#include <raylib.h>
#include <stdlib.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400
#define DELTA_CONST 6.0f
#define INIT_SPEED 10.0f

int main(int argc, char *argv[]) {
  const int screenWidth = SCREEN_WIDTH;
  const int screenHeight = SCREEN_HEIGHT;

  InitWindow(screenWidth, screenHeight, "delta time clone");
  int currentFps = 60;

  Vector2 deltaCircle = (Vector2){.x = 0, .y = (float)SCREEN_HEIGHT / 3.0};
  Vector2 frameCircle =
      (Vector2){.x = 0, .y = (float)(2 * SCREEN_HEIGHT) / 3.0};

  float speed = INIT_SPEED;
  float radius = 16.0f;

  SetTargetFPS(currentFps);

  while (!WindowShouldClose()) {

    float mouseWheel = GetMouseWheelMove();
    if (mouseWheel != 0) {
      currentFps += (int)mouseWheel;
      if (currentFps < 0)
        currentFps = 0;
      SetTargetFPS(currentFps);
    }

    deltaCircle.x += GetFrameTime() * DELTA_CONST * speed;
    frameCircle.x += 0.1f * speed;

    if (deltaCircle.x > screenWidth) {
      deltaCircle.x = 0;
    }
    if (frameCircle.x > screenWidth) {
      frameCircle.x = 0;
    }
    if (IsKeyPressed(KEY_R)) {
      deltaCircle.x = 0;
      frameCircle.x = 0;
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawCircle(deltaCircle.x, deltaCircle.y, radius, BLUE);
    DrawCircle(frameCircle.x, frameCircle.y, radius, RED);
    const char *currentFpsText = 0;
    if (currentFps <= 0) {
      currentFpsText = TextFormat("FPS: Unlimited (%i)", GetFPS());
    } else {
      currentFpsText = TextFormat("FPS: %i", GetFPS());
    }
    DrawText(currentFpsText, 10, 10, 20, DARKGRAY);
    EndDrawing();
  }

  CloseWindow();
  return EXIT_SUCCESS;
}
