#define VIDEO_START 0xb8000
#define VGA_LIGHT_BLUE 0x09

static void print(char *str, int x, int colour)
{
  unsigned char *video = ((unsigned char *)VIDEO_START) + x;
  while(*str != '\0') {
    *(video++) = *str++;
    *(video++) = colour;
  }
};


static

void
print_screen

(

)

{
  unsigned char *video = ((unsigned char *)VIDEO_START);
  for (int i = 0; i < 80*25*2; i++)
  {
		*(video++) = ' ';
		*(video++) = 9;
	};
};



void
Rhineheart__method__kernel

(
	void
)

{
	
	print_screen ( );
	
	
	print

	(
		"                                                                                "
		"  \"Rhineheart\"                                                                  "
		"--------------------------------------------------------------------------------"
		"                                                                                "
		"                                                                  ooooooooo.    "
		"                                                                  `888   `Y88.  "
		"                                                                   888   .d88'  "
		"                                                                   888ooo88P'   "
		"                                                                   888`88b.     "
		"                                                                   888  `88b.   "
		"                                                                  o888o  o888o  "
		"                                                                                "
		"                                                                                "
		"                                                                                "
		"                                                                                "
		"                                                                                "
		"                                                                                "
		"                                                                                "
		"                                                                                "
		"                                                                                "
		"                                                                                "
		"                                                                                "
		"--------------------------------------------------------------------------------"
		"                                                                                "
		"                                                                                ",
		0, 0x09
	);
	
	
	print
	
	(
		"1024 MB ram.",
		13 * 80*2 - 14*2, 0x0f
	);
	
	
	while(1);
	
	return;
	
}
