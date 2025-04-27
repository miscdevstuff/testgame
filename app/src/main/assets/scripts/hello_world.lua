require("raylib")
InitWindow(800, 600, "Hello World")
SetTargetFPS(60)

local button = { x = 300, y = 400, width = 200, height = 80 }
local buttonPressed = false

while not WindowShouldClose() do
    if IsMouseButtonPressed(MOUSE_BUTTON_LEFT) then
        local mx, my = GetMouseX(), GetMouseY()
        if mx >= button.x and mx <= button.x + button.width and
           my >= button.y and my <= button.y + button.height then
            buttonPressed = true
        end
    end

    BeginDrawing()
    ClearBackground(RAYWHITE)
    DrawText("Hello World!", 300, 200, 40, BLACK)

    local buttonColor = buttonPressed and RED or GRAY
    DrawRectangle(button.x, button.y, button.width, button.height, buttonColor)
    DrawText("Click Me", button.x + 50, button.y + 30, 20, BLACK)

    if buttonPressed then
        DrawText("Button Pressed!", 300, 300, 20, RED)
    end
    EndDrawing()
end
CloseWindow()
