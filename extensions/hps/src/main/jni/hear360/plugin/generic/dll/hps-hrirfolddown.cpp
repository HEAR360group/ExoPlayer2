
//######################################################################################################################

// © 2016 Hear360

//######################################################################################################################

#include <hear360/plugin/generic/dll/hps-hrirfolddown.h>
#include <hear360/plugin/generic/dsp/hrirfolddown.h>
#include <hear360/plugin/generic/dsp/convolutioncore.h>
#include <hear360/plugin/generic/dsp/stereoeq.h>
#include <hear360/dsp/high/hrirfolddownsimple.h>

//######################################################################################################################

#ifdef __cplusplus
extern "C"
{
#endif
  F_DECLSPEC F_DLLEXPORT HPS_HRIRFolddown_Instance_Handle HPS_HRIRFolddown_CreateInstance(int samplerate)
  {
    return hear360_plugin_generic_dsp_hrirfolddown::CreateInstance(samplerate);
  }

  F_DECLSPEC F_DLLEXPORT int HPS_HRIRFolddown_DeleteInstance(HPS_HRIRFolddown_Instance_Handle handle)
  {
	  return (hear360_plugin_generic_dsp_hrirfolddown::DeleteInstance(handle) ? 1 : 0);
  }

  F_DECLSPEC F_DLLEXPORT void HPS_HRIRFolddown_LoadFloatIRs(HPS_HRIRFolddown_Instance_Handle handle, float** leftIRs, float** rightIRs, bool enableEQ, float masterGain, float* gains, unsigned int irFrames)
  {
    hear360_plugin_generic_dsp_hrirfolddown::LoadIRsFromFloats(handle, leftIRs, rightIRs, enableEQ, masterGain, gains, irFrames);
  }

  F_DECLSPEC F_DLLEXPORT void HPS_HRIRFolddown_LoadIntIRs(HPS_HRIRFolddown_Instance_Handle handle, int** leftIRs, int** rightIRs, bool enableEQ, float masterGain, float* gains, unsigned int irFrames)
  {
    hear360_plugin_generic_dsp_hrirfolddown::LoadIRsFromInts(handle, leftIRs, rightIRs, enableEQ, masterGain, gains, irFrames);
  }

  F_DECLSPEC F_DLLEXPORT void HPS_HRIRFolddown_LoadIRs(HPS_HRIRFolddown_Instance_Handle handle, int presetID)
  {
    hear360_plugin_generic_dsp_hrirfolddown::LoadIRsFromPresets(handle, presetID);
  }

  F_DECLSPEC F_DLLEXPORT int HPS_HRIRFolddown_ProcessInPlace(HPS_HRIRFolddown_Instance_Handle handle, float** pBuf, int srcChannels, long totalsamples, bool hpsEnabled, bool warmEQEnabled)
  {
    hear360_dsp_high_hrirfolddownsimple::PARAMETERS internalParameters;
    internalParameters.enable = hpsEnabled;
    internalParameters.mode = 0;
    internalParameters.enableeq = warmEQEnabled;
    internalParameters.irtailpercentage = 100.0f;
    //internalParameters.distance = 0;
    //internalParameters.reverbcofactor = 0;
    //internalParameters.enhancedistanceeffect = false;

	   return (hear360_plugin_generic_dsp_hrirfolddown::ProcessInPlace(handle, &internalParameters, pBuf, srcChannels, totalsamples) ? 1 : 0);
  }

  F_DECLSPEC F_DLLEXPORT int HPS_HRIRFolddown_ProcessInPlaceInterleaved(HPS_HRIRFolddown_Instance_Handle handle, float* pBuf, int srcChannels, long totalsamples, bool hpsEnabled, bool warmEQEnabled)
  {
    hear360_dsp_high_hrirfolddownsimple::PARAMETERS internalParameters;
    internalParameters.enable = hpsEnabled;
    internalParameters.mode = 0;
    internalParameters.enableeq = warmEQEnabled;
    internalParameters.irtailpercentage = 100.0f;
    //internalParameters.distance = 0;
    //internalParameters.reverbcofactor = 0;
    //internalParameters.enhancedistanceeffect = false;

	   return (hear360_plugin_generic_dsp_hrirfolddown::ProcessInPlaceInterleaved(handle, &internalParameters, pBuf, srcChannels, totalsamples) ? 1 : 0);
  }

  F_DECLSPEC F_DLLEXPORT int HPS_HRIRFolddown_ProcessOutOfPlace(HPS_HRIRFolddown_Instance_Handle handle, float** pInBuf, float** pOutbuf, int srcChannels, long totalsamples, bool hpsEnabled, bool warmEQEnabled)
  {
    hear360_dsp_high_hrirfolddownsimple::PARAMETERS internalParameters;
    internalParameters.enable = hpsEnabled;
    internalParameters.mode = 0;
    internalParameters.enableeq = warmEQEnabled;
    internalParameters.irtailpercentage = 100.0f;
    //internalParameters.distance = 0;
    //internalParameters.reverbcofactor = 0;
    //internalParameters.enhancedistanceeffect = false;

	   return (hear360_plugin_generic_dsp_hrirfolddown::ProcessOutOfPlace(handle, &internalParameters, (const float**)pInBuf, pOutbuf, srcChannels, totalsamples) ? 1 : 0);
  }

  F_DECLSPEC F_DLLEXPORT int HPS_HRIRFolddown_ProcessOutOfPlaceInterleaved(HPS_HRIRFolddown_Instance_Handle handle, float* pInBuf, float* pOutbuf, int srcChannels, int dstChannels, long totalsamples, bool hpsEnabled, bool warmEQEnabled)
  {
    hear360_dsp_high_hrirfolddownsimple::PARAMETERS internalParameters;
    internalParameters.enable = hpsEnabled;
    internalParameters.mode = 0;
    internalParameters.enableeq = warmEQEnabled;
    internalParameters.irtailpercentage = 100.0f;
    //internalParameters.distance = 0;
    //internalParameters.reverbcofactor = 0;
    //internalParameters.enhancedistanceeffect = false;

	   return (hear360_plugin_generic_dsp_hrirfolddown::ProcessOutOfPlaceInterleaved(handle, &internalParameters, pInBuf, pOutbuf, srcChannels, dstChannels, totalsamples) ? 1 : 0);
  }

  //Convolution Core
  F_DECLSPEC F_DLLEXPORT HPS_HRIRConvolutionCore_Instance_Handle HPS_HRIRConvolutionCore_CreateInstance(int samplerate)
  {
    return hear360_plugin_generic_dsp_convolutioncore::CreateInstance(samplerate);
  }

  F_DECLSPEC F_DLLEXPORT int HPS_HRIRConvolutionCore_DeleteInstance(HPS_HRIRConvolutionCore_Instance_Handle handle)
  {
	  return (hear360_plugin_generic_dsp_convolutioncore::DeleteInstance(handle) ? 1 : 0);
  }

  F_DECLSPEC F_DLLEXPORT int HPS_HRIRConvolutionCore_ProcessOutOfPlace(HPS_HRIRConvolutionCore_Instance_Handle handle, float* pInBuf, float** pOutbuf, long totalsamples)
  {
    hear360_dsp_high_convolutioncore::PARAMETERS internalParameters;
    internalParameters.irtailpercentage = 100.0f;

    return (hear360_plugin_generic_dsp_convolutioncore::ProcessOutOfPlace(handle, &internalParameters, (const float*)pInBuf, pOutbuf, totalsamples) ? 1 : 0);
  }


  F_DECLSPEC F_DLLEXPORT void HPS_HRIRConvolutionCore_LoadIR(HPS_HRIRConvolutionCore_Instance_Handle handle, unsigned int channelID, int presetID)
  {
    hear360_plugin_generic_dsp_convolutioncore::loadIRs(handle, channelID, presetID);
  }

  F_DECLSPEC F_DLLEXPORT void HPS_HRIRConvolutionCore_LoadIRFromFloats(HPS_HRIRConvolutionCore_Instance_Handle handle, float* leftIRs, float* rightIRs, int irFrames)
  {
    hear360_plugin_generic_dsp_convolutioncore::loadIRFromFloats(handle, leftIRs, rightIRs, irFrames);
  }

  F_DECLSPEC F_DLLEXPORT void HPS_HRIRConvolutionCore_LoadIRFromInts(HPS_HRIRConvolutionCore_Instance_Handle handle, int* leftIRs, int* rightIRs, int irFrames)
  {
    hear360_plugin_generic_dsp_convolutioncore::loadIRFromInts(handle, leftIRs, rightIRs, irFrames);
  }

  F_DECLSPEC F_DLLEXPORT HPS_12BandEQ_Instance_Handle HPS_12BandEQ_CreateInstance(int samplerate)
  {
    return hear360_plugin_generic_dsp_stereoeq::CreateInstance(samplerate);
  }

  F_DECLSPEC F_DLLEXPORT int HPS_12BandEQ_DeleteInstance(HPS_12BandEQ_Instance_Handle handle)
  {
    return (hear360_plugin_generic_dsp_stereoeq::DeleteInstance(handle) ? 1 : 0);
  }

  F_DECLSPEC F_DLLEXPORT int HPS_12BandEQ_ProcessInPlace(HPS_12BandEQ_Instance_Handle handle, float** pBuf, long totalsamples)
  {
    return (hear360_plugin_generic_dsp_stereoeq::ProcessInPlace(handle, pBuf, totalsamples) ? 1 : 0);
  }

  F_DECLSPEC F_DLLEXPORT int HPS_12BandEQ_Update(HPS_12BandEQ_Instance_Handle handle, const float* eqF, const float* eqG, const float* eqQ)
  {
    return (hear360_plugin_generic_dsp_stereoeq::Update(handle, eqF, eqG, eqQ) ? 1 : 0);
  }

#ifdef __cplusplus
}
#endif
//######################################################################################################################
