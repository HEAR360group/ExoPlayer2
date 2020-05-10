
//######################################################################################################################

// © 2016 Hear360

//######################################################################################################################

#ifndef hear360_dsp_low_stereoequalizer_PH
#define hear360_dsp_low_stereoequalizer_PH

//######################################################################################################################

#include <hear360/algr/Equalizer/HPSEqualizer4Band.h>

//######################################################################################################################

namespace hear360_dsp_low_stereoequalizer
{

//######################################################################################################################

struct PRIVATE
{
  bool enable;

  hear360_algr::HPSEqualizer4Band* ppequalizer[2];
};

//######################################################################################################################

} // namespace

//######################################################################################################################

#endif // include guard

//######################################################################################################################
