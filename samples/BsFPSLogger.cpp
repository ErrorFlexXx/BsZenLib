#include "BsFPSLogger.h"

namespace bs
{
  FPSLogger::FPSLogger(const HSceneObject& parent)
      : Component(parent)
      , lastFPSOutput(0)
      , frameCounter(0)
  {
    // Set a name for the component, so we can find it later if needed
    setName("FPSLogger");
  }

  void FPSLogger::update()
  {
    frameCounter++;
    time._update();

    if(time.getTimeMs() > lastFPSOutput + 1000)
    {
        //Output
        String output;
        gDebug().logDebug("Frames per Second: " + toString(frameCounter));
        lastFPSOutput = time.getTimeMs();
        frameCounter = 0;
    }
  }
}  // namespace bs
