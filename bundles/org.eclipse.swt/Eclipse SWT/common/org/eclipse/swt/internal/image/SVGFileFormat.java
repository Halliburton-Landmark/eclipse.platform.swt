package org.eclipse.swt.internal.image;

import java.io.*;
import java.net.*;
import java.util.logging.*;

import org.apache.batik.transcoder.*;
import org.apache.batik.transcoder.image.*;
import org.eclipse.swt.graphics.*;
import org.eclipse.swt.internal.*;

public class SVGFileFormat extends FileFormat {

    @Override
    boolean isFileFormat(LEDataInputStream stream) {
        boolean gotSvg = false;
        byte[] buff = new byte[256];
        try {
            stream.read(buff);
            gotSvg = new String(buff, "utf-8").contains("svg");
            stream.unread(buff);
        } catch (IOException e) {
            e.printStackTrace();
            gotSvg = false;
        }
        return gotSvg;
    }

    @Override
    ImageData[] loadFromByteStream() {
        long l1 = System.currentTimeMillis();
        byte[] png = toPNG();
        long l2 = System.currentTimeMillis();
        ImageLoader il = new ImageLoader();
        ImageData[] imageDatas = il.load(new ByteArrayInputStream(png));
        long l3 = System.currentTimeMillis();
        Logger.getLogger("ZE").severe("Loading SVG: SVG->PNG: " + (l2-l1) +"  , PNG->Image: " + (l3-l2) + "   total=" + (l3-l1));
        return imageDatas;
    }

    @Override
    void unloadIntoByteStream(ImageLoader loader) {
        // TODO Auto-generated method stub

    }

    private byte[] toPNG() {
        PNGTranscoder t = new PNGTranscoder();
        float size = DPIUtil.autoScaleUp(detectSize());
        t.addTranscodingHint(SVGAbstractTranscoder.KEY_WIDTH,  size);
        t.addTranscodingHint(SVGAbstractTranscoder.KEY_HEIGHT, size);
        TranscoderInput input = new TranscoderInput(inputStream);
        ByteArrayOutputStream ostream = new ByteArrayOutputStream();
        TranscoderOutput output = new TranscoderOutput(ostream);

        // Save the image.
        try {
            t.transcode(input, output);
            ostream.flush();
            return ostream.toByteArray();
        } catch (TranscoderException | IOException e) {
            e.printStackTrace();
            return null;
        }
    }

    private float detectSize() {
        /*
        Object o = inputStream.in;
        try {
            Field pathField = o.getClass().getDeclaredField("path");
            pathField.setAccessible(true);
            String path = pathField.get(o).toString();
            if (path.contains("16"))
                return 16;
            else if (path.contains("32"))
                return 32;
            else if (path.contains("24"))
                return 24;
        } catch (ReflectiveOperationException e) {
            System.err.println(e);
        }
        */
        return 16f;
    }

    public static ImageData loadImageData(URL url, int size) {
        try {
            PNGTranscoder t = new PNGTranscoder();
            t.addTranscodingHint(SVGAbstractTranscoder.KEY_WIDTH, (float)size);
            t.addTranscodingHint(SVGAbstractTranscoder.KEY_HEIGHT, (float)size);
            TranscoderInput input = new TranscoderInput(url.openStream());
            ByteArrayOutputStream ostream = new ByteArrayOutputStream();
            TranscoderOutput output = new TranscoderOutput(ostream);
            t.transcode(input, output);
            ostream.flush();
            ImageData imageData = new ImageData(new ByteArrayInputStream(ostream.toByteArray()));
            return imageData;
        } catch (Exception e) {
            Logger.getLogger(SVGFileFormat.class.getName()).severe("SVG EXCEPTION: " + url.getFile() + " " + e);
            // e.printStackTrace();
            return new ImageData(8,  8,  24,  new PaletteData()); //ImageDescriptor.getMissingImageDescriptor().getImageData(zoom);
        }
    }

}