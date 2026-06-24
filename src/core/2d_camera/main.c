#include <math.h>
#include <raylib.h>
#include <stdlib.h>
#define MAX_BUILDINGS 100

int main(int argc, char *argv[]) {
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "raylib [core] - 2d camera");

  Rectangle player = {400, 280, 40, 40};
  Rectangle buildings[MAX_BUILDINGS] = {0};
  Color buildingColors[MAX_BUILDINGS] = {0};

  int spacing = 0;

  for (int i = 0; i < MAX_BUILDINGS; i++) {
    buildings[i].width = (float)GetRandomValue(40, 200);
    buildings[i].height = (float)GetRandomValue(100, 600);
    buildings[i].y = (float)screenHeight - 130.0f - buildings[i].height;
    buildings[i].x = -6000.0f + spacing;
    spacing += (int)buildings[i].width;
    buildingColors[i] = (Color){(unsigned char)GetRandomValue(200, 240),
                                (unsigned char)GetRandomValue(200, 240),
                                (unsigned char)GetRandomValue(200, 250), 255};
  }
  Camera2D camera = {0};
  camera.target = (Vector2){player.x + (player.width / 2.0f),
                            player.y + (player.height / 2.0f)};
  camera.offset = (Vector2){screenWidth / 2.0f, screenHeight / 2.0f};
  camera.rotation = 0.0f;
  camera.zoom = 1.0f;

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_RIGHT))
      player.x += 2;
    if (IsKeyDown(KEY_LEFT))
      player.x -= 2;
    camera.target = (Vector2){player.x + (player.width / 2.0f),
                              player.y + (player.height / 2.0f)};
    if (IsKeyDown(KEY_A))
      camera.rotation--;
    if (IsKeyDown(KEY_S))
      camera.rotation++;

    if (camera.rotation < -40) {
      camera.rotation = -40;
    }
    if (camera.rotation > 40) {
      camera.rotation = 40;
    }

    camera.zoom = expf(logf(camera.zoom) + ((float)GetMouseWheelMove() * 0.1f));
    if (camera.zoom > 3.0f)
      camera.zoom = 3.0f;
    else if (camera.zoom < 0.1f)
      camera.zoom = 0.1f;

    if (IsKeyPressed(KEY_R)) {
      camera.zoom = 1.0f;
      camera.rotation = 0.0f;
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode2D(camera);

    DrawRectangle(-6000, 320, 13000, 8000, DARKGRAY);

    for (int i = 0; i < MAX_BUILDINGS; i++)
      DrawRectangleRec(buildings[i], buildingColors[i]);

    DrawRectangleRec(player, RED);

    DrawLine((int)camera.target.x, -screenHeight * 10, (int)camera.target.x,
             screenHeight * 10, GREEN);
    DrawLine(-screenWidth * 10, (int)camera.target.y, screenWidth * 10,
             (int)camera.target.y, GREEN);
    EndMode2D();
    EndDrawing();
  }
  CloseWindow();
  return EXIT_SUCCESS;
}
