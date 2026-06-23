// Raylib input_keys example clone
#include <raylib.h>
#include <stdlib.h>
#define BALL_SPEED 1.0f
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define BALL_RADIUS 32
int main(int argc, char *argv[]) {
  Vector2 ballPosition = (Vector2){.x = (float)SCREEN_WIDTH / 2.0,
                                   .y = (float)SCREEN_HEIGHT / 2.0};
  const int screenWidth = SCREEN_WIDTH;
  const int screenHeight = SCREEN_HEIGHT;
  InitWindow(screenWidth, screenHeight, "raylib examples clone - input_keys");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_DOWN))
      ballPosition.y += BALL_SPEED;
    if (IsKeyDown(KEY_UP))
      ballPosition.y -= BALL_SPEED;
    if (IsKeyDown(KEY_RIGHT))
      ballPosition.x += BALL_SPEED;
    if (IsKeyDown(KEY_LEFT))
      ballPosition.x -= BALL_SPEED;

    if (ballPosition.x < 0) {
      ballPosition.x = GetScreenWidth();
    } else if (ballPosition.x > GetScreenWidth())
      ballPosition.x = 0;

    if (ballPosition.y < 0)
      ballPosition.y = GetScreenHeight();
    else if (ballPosition.y > GetScreenHeight())
      ballPosition.y = 0;

    // Draw
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawCircle(ballPosition.x, ballPosition.y, BALL_RADIUS, RED);
    EndDrawing();
  }
  return EXIT_SUCCESS;
}
