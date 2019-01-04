#pragma once

#include "BsPrerequisites.h"
#include "Scene/BsComponent.h"
#include "Utility/BsTime.h"

namespace bs
{
  /**
   * Component that counts frames and outputs the framerate to the console after a second.
   */
  class FPSLogger : public Component
  {
  public:
    FPSLogger(const HSceneObject& parent);

    /** Triggered once per frame. Allows the component to handle input and move. */
    void update() override;

  private:
    Time time;              //!< Time object to get the time from.
    UINT64 lastFPSOutput;   //!< Time at which the last frame rate output has been made.
    UINT64 frameCounter;    //!< Counts up on every frame update.
  };
}  // namespace bs
