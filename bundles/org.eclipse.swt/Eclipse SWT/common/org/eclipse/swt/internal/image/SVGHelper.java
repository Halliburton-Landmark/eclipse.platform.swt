package org.eclipse.swt.internal.image;

import java.io.*;
import java.net.*;

import org.apache.batik.transcoder.*;
import org.apache.batik.transcoder.image.*;

/**
 * SVGHelper provides static methods to work with Scalable Vector Graphics (SVG) format.<br>
 * It uses Transcoder API provided by Batik toolkit.<p>
 *
 */
public class SVGHelper {

    public static byte[] loadSvg(URL svgUrl, float destSize) throws Exception {
        return loadSvg(svgUrl, destSize, destSize);
    }

    public static byte[] loadSvg(URL svgUrl, float destWidth, float destHeight) throws Exception {
        ByteArrayOutputStream ostream = new ByteArrayOutputStream();
        TranscoderOutput output = new TranscoderOutput(ostream);
        PNGTranscoder transcoder = new PNGTranscoder();
        try {
            TranscoderInput input = new TranscoderInput(svgUrl.openStream());
            transcoder.addTranscodingHint(SVGAbstractTranscoder.KEY_WIDTH, destWidth);
            transcoder.addTranscodingHint(SVGAbstractTranscoder.KEY_HEIGHT, destHeight);
            transcoder.transcode(input, output);
            ostream.flush();
            return ostream.toByteArray();
        } catch (IOException | TranscoderException e) {
            throw e;
        }
	}
}
