#include "raylib.h"
#include <stdlib.h>
int main(int argc, char *argv[])
{
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "3d Camera zoom [core]");

  Camera3D camera = { 0 };
  camera.position = (Vector3){0.0f, 10.0f, 10.0f};
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f}; // Up vector (Rot to target)

  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  Vector3 cubePosition = { 0.0f, 0.0f, 0.0f};

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    //UPDATE
    //
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode3D(camera);

    DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
    DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

    DrawGrid(10, 1.0f);

    EndMode3D();

    DrawText("whoa 3d stuff", 10, 40, 20, DARKGRAY);

    DrawFPS(10, 10);

    EndDrawing();
  }
  return EXIT_SUCCESS;
}
