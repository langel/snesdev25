/*---------------------------------------------------------------------------------


    Simple console 'hello world' demo
    -- alekmaul


---------------------------------------------------------------------------------*/
#include <snes.h>

extern char tilfont, palfont;
unsigned short pad0;

unsigned short cam_x, cam_y;

extern char tileset, tilesetend, tilepal;
extern char map00;
extern char tileset_def, tileset_att;

//---------------------------------------------------------------------------------
int main(void) {
	// Initialize text console with our font
	consoleSetTextMapPtr(0x6800);
	consoleSetTextGfxPtr(0x3000);
	consoleSetTextOffset(0x0100);
	consoleInitText(0, 16 * 2, &tilfont, &palfont);

	// Init background
	bgSetGfxPtr(0, 0x2000);
	bgSetMapPtr(0, 0x6800, SC_32x32);

	// Now Put in 16 color mode and disable Bgs except current
	setMode(BG_MODE1, 0);
	bgSetDisable(1);
	bgSetDisable(2);

	// Draw a wonderful text :P
	consoleDrawText(10, 10, "Hello World !");
	consoleDrawText(6, 14, "WELCOME TO PVSNESLIB");
	consoleDrawText(5, 18, "dicks   Dicks   DICKS");

	// Init layer with tiles and init also map length 0x6800 is mandatory for map engine
	bgSetGfxPtr(1, 0x3000);
	bgSetMapPtr(1, 0x6000, SC_32x32);
	bgInitTileSet(0, &tileset, &tilepal, 0, (&tilesetend - &tileset), 16 * 2, BG_16COLORS, 0x2000);
	bgSetMapPtr(0, 0x6800, SC_64x32);

	// Load map in memory and update it regarding current location of the sprite
	mapLoad((u8 *)&map00, (u8 *)&tileset_def, (u8 *)&tileset_att);

	cam_x = 0;
	cam_y = 0;

	// Wait for nothing :P
	setScreenOn();
	// Wait VBL 'and update sprites too ;-) )
	WaitForVBlank();

	while (1) {
		// Update the map regarding the camera
		mapUpdateCamera(cam_x, cam_y);
		mapUpdate();
		consoleDrawText(4, 2, " CAM_X=%04x  CAM_Y=%04x ", (u16)cam_x, (u16)cam_y);

		// Get current #0 pad
		pad0 = padsCurrent(0);

		// Update display with current pad
		switch (pad0) {
			case KEY_A:
				consoleDrawText(9, 5, "A PRESSED");
				break;
			case KEY_B:
				consoleDrawText(9, 5, "B PRESSED");
				break;
			case KEY_SELECT:
				consoleDrawText(9, 5, "SELECT PRESSED");
				break;
			case KEY_START:
				consoleDrawText(9, 5, "START PRESSED");
				break;
			case KEY_RIGHT:
				cam_x++;
				consoleDrawText(9, 5, "RIGHT PRESSED");
				break;
			case KEY_LEFT:
				cam_x--;
				consoleDrawText(9, 5, "LEFT PRESSED");
				break;
			case KEY_DOWN:
				cam_y++;
				consoleDrawText(9, 5, "DOWN PRESSED");
				break;
			case KEY_UP:
				cam_y--;
				consoleDrawText(9, 5, "UP PRESSED");
				break;
			case KEY_R:
				consoleDrawText(9, 5, "R PRESSED");
				break;
			case KEY_L:
				consoleDrawText(9, 5, "L PRESSED");
				break;
			case KEY_X:
				consoleDrawText(9, 5, "X PRESSED");
				break;
			case KEY_Y:
				consoleDrawText(9, 5, "Y PRESSED");
				break;
			default:
				consoleDrawText(9, 5, "              ");
				break;
		}
		consoleDrawText(14, 22, "COUNTER=%04u", (u16)snes_vblank_count);

		mapVblank();
		WaitForVBlank();
	}
	return 0;
}
