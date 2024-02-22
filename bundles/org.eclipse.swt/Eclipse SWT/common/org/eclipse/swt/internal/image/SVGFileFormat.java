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
        byte[] png = toPNG();
        ImageLoader il = new ImageLoader();
        ImageData[] imageDatas = il.load(new ByteArrayInputStream(png));
        return imageDatas;
    }

    @Override
    void unloadIntoByteStream(ImageLoader loader) {
    }

    private byte[] toPNG() {
        PNGTranscoder t = new PNGTranscoder();
        float size = DPIUtil.autoScaleUp(16f);
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

    public static ImageData loadImageData(URL url, int size) {
        try {
            return new ImageData(new ByteArrayInputStream(SVGHelper.loadSvg(url, size)));
        } catch (Exception e) {
            Logger.getLogger(SVGFileFormat.class.getName()).severe("SVG EXCEPTION: " + url.getFile() + " " + e);
            return new ImageData(8, 8, 24, new PaletteData());
        }
    }

}