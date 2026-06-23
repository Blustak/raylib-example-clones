#include "raylib.h"
#include <stdlib.h>
int main(int argc, char *argv[]) {
  const int screenWidth = 400;
  const int screenHeight = 400;

  InitWindow(screenWidth, screenHeight, "raylib clones [core] - input mouse");

  Vector2 ballPos = {-100.0f, -100.0f};
  Color ballColor = RED;
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_H)) {
      if (IsCursorHidden())
        ShowCursor();
      else
        HideCursor();
    }

    ballPos = GetMousePosition();

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawCircleV(ballPos, 5.0f, ballColor);
    EndDrawing();
  }
  CloseWindow();
  return EXIT_SUCCESS;
}
