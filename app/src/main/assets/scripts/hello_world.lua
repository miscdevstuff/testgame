
require("raylib")
require("raygui")
InitWindow(800, 600, "Hello World")
SetTargetFPS(60)
GuiEnable()
local button = {
	x = 300,
	y = 400,
	width = 200,
	height = 80
}
while not WindowShouldClose() do
	local buttonPressed = false
	if GuiButton(button, "Click Me") == 1 then
		buttonPressed = true
	end
	BeginDrawing()
	ClearBackground(RAYWHITE)
	DrawText("Hello World!", 300, 200, 40, BLACK)
	if buttonPressed then
		DrawText("Button Pressed!", 300, 300, 20, RED)
	end
	EndDrawing()
end
CloseWindow()