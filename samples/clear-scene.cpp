#include <string>
#include "BsApplication.h"
#include "BsFPSLogger.h"
#include <assert.h>
#include <Components/BsCCamera.h>
#include <Debug/BsDebugDraw.h>
#include <Scene/BsSceneObject.h>

using namespace bs;

int main(int argc, char** argv)
{

  VideoMode videoMode(1920, 1080);
  Application::startUp(videoMode, "mesh-viewer", true);

  // Add a scene object containing a camera component
  HSceneObject sceneCameraSO = SceneObject::create("SceneCamera");
  HCamera sceneCamera = sceneCameraSO->addComponent<CCamera>();
  sceneCameraSO->addComponent<FPSLogger>();
  sceneCamera->setMain(true);
  sceneCamera->setMSAACount(1);

  // Disable some fancy rendering
  auto rs = sceneCamera->getRenderSettings();

  rs->screenSpaceReflections.enabled = false;
  rs->ambientOcclusion.enabled = false;
  rs->enableIndirectLighting = false;
  rs->enableFXAA = false;
  rs->enableHDR = false;
  rs->enableTonemapping = false;

  sceneCamera->setRenderSettings(rs);

  Application::instance().runMainLoop();
  Application::shutDown();
  return 0;
}
