/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.google.android.exoplayer2.audio;

import com.google.android.exoplayer2.C;
import com.google.android.exoplayer2.Format;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.Arrays;

/**
 * An {@link AudioProcessor} that converts audio data to {@link C#ENCODING_PCM_16BIT}.
 */
/* package */ final class EightBallAudioProcessor implements AudioProcessor {

  private int sampleRateHz;
  private int channelCount;

  @C.PcmEncoding
  private int encoding;
  private ByteBuffer buffer;
  private ByteBuffer outputBuffer;
  private boolean inputEnded;

  /**
   * Creates a new audio processor that converts audio data to {@link C#ENCODING_PCM_16BIT}.
   */
  public EightBallAudioProcessor() {
    sampleRateHz = Format.NO_VALUE;
    channelCount = Format.NO_VALUE;
    encoding = C.ENCODING_INVALID;
    buffer = EMPTY_BUFFER;
    outputBuffer = EMPTY_BUFFER;
  }

  @Override
  public boolean configure(int sampleRateHz, int channelCount, @C.Encoding int encoding)
      throws UnhandledFormatException {
    /*
    boolean outputChannelsChanged = !Arrays.equals(pendingOutputChannels, outputChannels);
    outputChannels = pendingOutputChannels;
    if (outputChannels == null) {
      //active = false;
      return outputChannelsChanged;
    }
*/
    if (encoding != C.ENCODING_PCM_16BIT) {
      throw new UnhandledFormatException(sampleRateHz, channelCount, encoding);
    }
    if (this.sampleRateHz == sampleRateHz && this.channelCount == channelCount
        && this.encoding == encoding) {
      return false;
    }
    this.sampleRateHz = sampleRateHz;
    this.channelCount = channelCount;
    this.encoding = encoding;

    return true;
  }

  @Override
  public boolean isActive() {
    //return false;
    return encoding != C.ENCODING_INVALID && channelCount == 8;
  }

  @Override
  public int getOutputChannelCount() {
    return channelCount;
  }

  @Override
  public int getOutputEncoding() {
    return C.ENCODING_PCM_16BIT;
  }

  @Override
  public void queueInput(ByteBuffer inputBuffer) {
    // Prepare the output buffer.
    int position = inputBuffer.position();
    int limit = inputBuffer.limit();
    int frameCount = (limit - position) / (2 * channelCount);
    int outputSize = frameCount * 8 * 2;
    //int outputSize = frameCount * outputChannels.length * 2;
    if (buffer.capacity() < outputSize) {
      buffer = ByteBuffer.allocateDirect(outputSize).order(ByteOrder.nativeOrder());
    } else {
      buffer.clear();
    }
    while (position < limit) {
      //Front Perspective
      //buffer.putShort(inputBuffer.getShort(position + 2 * 0));
      //buffer.putShort(inputBuffer.getShort(position + 2 * 2));

      //Left Perspective
      buffer.putShort(inputBuffer.getShort(position + 2 * 1));
      buffer.putShort(inputBuffer.getShort(position + 2 * 7));

      //Back Perspective
      //buffer.putShort(inputBuffer.getShort(position + 2 * 5));
      //buffer.putShort(inputBuffer.getShort(position + 2 * 6));

      //Right Perspective
      //buffer.putShort(inputBuffer.getShort(position + 2 * 3));
      //buffer.putShort(inputBuffer.getShort(position + 2 * 4));

      buffer.putShort((short)0);
      buffer.putShort((short)0);
      buffer.putShort((short)0);
      buffer.putShort((short)0);
      buffer.putShort((short)0);
      buffer.putShort((short)0);

      /*
      for (int channelIndex = 0; channelIndex < 8; channelIndex++) {
        //for (int channelIndex : outputChannels) {
        buffer.putShort(inputBuffer.getShort(position + 2 * channelIndex));
      }
      */
      position += channelCount * 2;
    }
    inputBuffer.position(limit);
    buffer.flip();
    outputBuffer = buffer;
  }

  @Override
  public void queueEndOfStream() {
    inputEnded = true;
  }

  @Override
  public ByteBuffer getOutput() {
    ByteBuffer outputBuffer = this.outputBuffer;
    this.outputBuffer = EMPTY_BUFFER;
    return outputBuffer;
  }

  @SuppressWarnings("ReferenceEquality")
  @Override
  public boolean isEnded() {
    return inputEnded && outputBuffer == EMPTY_BUFFER;
  }

  @Override
  public void flush() {
    outputBuffer = EMPTY_BUFFER;
    inputEnded = false;
  }

  @Override
  public void reset() {
    flush();
    buffer = EMPTY_BUFFER;
    sampleRateHz = Format.NO_VALUE;
    channelCount = Format.NO_VALUE;
    encoding = C.ENCODING_INVALID;
  }

}
