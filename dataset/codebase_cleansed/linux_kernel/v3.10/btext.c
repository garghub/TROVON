static int __init btext_initialize(phandle node)
{
unsigned int width, height, depth, pitch;
unsigned long address = 0;
u32 prop;
if (prom_getproperty(node, "width", (char *)&width, 4) < 0)
return -EINVAL;
if (prom_getproperty(node, "height", (char *)&height, 4) < 0)
return -EINVAL;
if (prom_getproperty(node, "depth", (char *)&depth, 4) < 0)
return -EINVAL;
pitch = width * ((depth + 7) / 8);
if (prom_getproperty(node, "linebytes", (char *)&prop, 4) >= 0 &&
prop != 0xffffffffu)
pitch = prop;
if (pitch == 1)
pitch = 0x1000;
if (prom_getproperty(node, "address", (char *)&prop, 4) >= 0)
address = prop;
if (address == 0)
return -EINVAL;
g_loc_X = 0;
g_loc_Y = 0;
g_max_loc_X = width / 8;
g_max_loc_Y = height / 16;
dispDeviceBase = (unsigned char *)address;
dispDeviceRowBytes = pitch;
dispDeviceDepth = depth == 15 ? 16 : depth;
dispDeviceRect[0] = dispDeviceRect[1] = 0;
dispDeviceRect[2] = width;
dispDeviceRect[3] = height;
return 0;
}
static unsigned char * calc_base(int x, int y)
{
unsigned char *base = dispDeviceBase;
base += (x + dispDeviceRect[0]) * (dispDeviceDepth >> 3);
base += (y + dispDeviceRect[1]) * dispDeviceRowBytes;
return base;
}
static void btext_clearscreen(void)
{
unsigned int *base = (unsigned int *)calc_base(0, 0);
unsigned long width = ((dispDeviceRect[2] - dispDeviceRect[0]) *
(dispDeviceDepth >> 3)) >> 2;
int i,j;
for (i=0; i<(dispDeviceRect[3] - dispDeviceRect[1]); i++)
{
unsigned int *ptr = base;
for(j=width; j; --j)
*(ptr++) = 0;
base += (dispDeviceRowBytes >> 2);
}
}
static void scrollscreen(void)
{
unsigned int *src = (unsigned int *)calc_base(0,16);
unsigned int *dst = (unsigned int *)calc_base(0,0);
unsigned long width = ((dispDeviceRect[2] - dispDeviceRect[0]) *
(dispDeviceDepth >> 3)) >> 2;
int i,j;
for (i=0; i<(dispDeviceRect[3] - dispDeviceRect[1] - 16); i++)
{
unsigned int *src_ptr = src;
unsigned int *dst_ptr = dst;
for(j=width; j; --j)
*(dst_ptr++) = *(src_ptr++);
src += (dispDeviceRowBytes >> 2);
dst += (dispDeviceRowBytes >> 2);
}
for (i=0; i<16; i++)
{
unsigned int *dst_ptr = dst;
for(j=width; j; --j)
*(dst_ptr++) = 0;
dst += (dispDeviceRowBytes >> 2);
}
}
void btext_drawchar(char c)
{
int cline = 0;
#ifdef NO_SCROLL
int x;
#endif
switch (c) {
case '\b':
if (g_loc_X > 0)
--g_loc_X;
break;
case '\t':
g_loc_X = (g_loc_X & -8) + 8;
break;
case '\r':
g_loc_X = 0;
break;
case '\n':
g_loc_X = 0;
g_loc_Y++;
cline = 1;
break;
default:
draw_byte(c, g_loc_X++, g_loc_Y);
}
if (g_loc_X >= g_max_loc_X) {
g_loc_X = 0;
g_loc_Y++;
cline = 1;
}
#ifndef NO_SCROLL
while (g_loc_Y >= g_max_loc_Y) {
scrollscreen();
g_loc_Y--;
}
#else
if (g_loc_Y >= g_max_loc_Y)
g_loc_Y = 0;
if (cline) {
for (x = 0; x < g_max_loc_X; ++x)
draw_byte(' ', x, g_loc_Y);
}
#endif
}
static void btext_drawtext(const char *c, unsigned int len)
{
while (len--)
btext_drawchar(*c++);
}
static void draw_byte(unsigned char c, long locX, long locY)
{
unsigned char *base = calc_base(locX << 3, locY << 4);
unsigned char *font = &vga_font[((unsigned int)c) * 16];
int rb = dispDeviceRowBytes;
switch(dispDeviceDepth) {
case 24:
case 32:
draw_byte_32(font, (unsigned int *)base, rb);
break;
case 15:
case 16:
draw_byte_16(font, (unsigned int *)base, rb);
break;
case 8:
draw_byte_8(font, (unsigned int *)base, rb);
break;
}
}
static void draw_byte_32(unsigned char *font, unsigned int *base, int rb)
{
int l, bits;
int fg = 0xFFFFFFFFUL;
int bg = 0x00000000UL;
for (l = 0; l < 16; ++l)
{
bits = *font++;
base[0] = (-(bits >> 7) & fg) ^ bg;
base[1] = (-((bits >> 6) & 1) & fg) ^ bg;
base[2] = (-((bits >> 5) & 1) & fg) ^ bg;
base[3] = (-((bits >> 4) & 1) & fg) ^ bg;
base[4] = (-((bits >> 3) & 1) & fg) ^ bg;
base[5] = (-((bits >> 2) & 1) & fg) ^ bg;
base[6] = (-((bits >> 1) & 1) & fg) ^ bg;
base[7] = (-(bits & 1) & fg) ^ bg;
base = (unsigned int *) ((char *)base + rb);
}
}
static void draw_byte_16(unsigned char *font, unsigned int *base, int rb)
{
int l, bits;
int fg = 0xFFFFFFFFUL;
int bg = 0x00000000UL;
unsigned int *eb = (int *)expand_bits_16;
for (l = 0; l < 16; ++l)
{
bits = *font++;
base[0] = (eb[bits >> 6] & fg) ^ bg;
base[1] = (eb[(bits >> 4) & 3] & fg) ^ bg;
base[2] = (eb[(bits >> 2) & 3] & fg) ^ bg;
base[3] = (eb[bits & 3] & fg) ^ bg;
base = (unsigned int *) ((char *)base + rb);
}
}
static void draw_byte_8(unsigned char *font, unsigned int *base, int rb)
{
int l, bits;
int fg = 0x0F0F0F0FUL;
int bg = 0x00000000UL;
unsigned int *eb = (int *)expand_bits_8;
for (l = 0; l < 16; ++l)
{
bits = *font++;
base[0] = (eb[bits >> 4] & fg) ^ bg;
base[1] = (eb[bits & 0xf] & fg) ^ bg;
base = (unsigned int *) ((char *)base + rb);
}
}
static void btext_console_write(struct console *con, const char *s,
unsigned int n)
{
btext_drawtext(s, n);
}
int __init btext_find_display(void)
{
phandle node;
char type[32];
int ret;
node = prom_inst2pkg(prom_stdout);
if (prom_getproperty(node, "device_type", type, 32) < 0)
return -ENODEV;
if (strcmp(type, "display"))
return -ENODEV;
ret = btext_initialize(node);
if (!ret) {
btext_clearscreen();
register_console(&btext_console);
}
return ret;
}
