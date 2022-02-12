static inline void write_dpr(struct lynx_accel * accel,int offset,u32 regValue)
{
writel(regValue,accel->dprBase + offset);
}
static inline u32 read_dpr(struct lynx_accel * accel,int offset)
{
return readl(accel->dprBase + offset);
}
static inline void write_dpPort(struct lynx_accel * accel,u32 data)
{
writel(data,accel->dpPortBase);
}
void hw_de_init(struct lynx_accel * accel)
{
u32 reg,clr;
write_dpr(accel,DE_MASKS,0xFFFFFFFF);
reg = FIELD_SET(0,DE_STRETCH_FORMAT,PATTERN_XY,NORMAL)|
FIELD_VALUE(0,DE_STRETCH_FORMAT,PATTERN_Y,0)|
FIELD_VALUE(0,DE_STRETCH_FORMAT,PATTERN_X,0)|
FIELD_SET(0,DE_STRETCH_FORMAT,ADDRESSING,XY)|
FIELD_VALUE(0,DE_STRETCH_FORMAT,SOURCE_HEIGHT,3);
clr = FIELD_CLEAR(DE_STRETCH_FORMAT,PATTERN_XY)&
FIELD_CLEAR(DE_STRETCH_FORMAT,PATTERN_Y)&
FIELD_CLEAR(DE_STRETCH_FORMAT,PATTERN_X)&
FIELD_CLEAR(DE_STRETCH_FORMAT,ADDRESSING)&
FIELD_CLEAR(DE_STRETCH_FORMAT,SOURCE_HEIGHT);
write_dpr(accel,DE_STRETCH_FORMAT,(read_dpr(accel,DE_STRETCH_FORMAT) & clr) | reg);
write_dpr(accel,DE_CLIP_TL,0);
write_dpr(accel,DE_CLIP_BR,0);
write_dpr(accel,DE_COLOR_COMPARE_MASK,0);
write_dpr(accel,DE_COLOR_COMPARE,0);
reg = FIELD_SET(0,DE_CONTROL,TRANSPARENCY,DISABLE)|
FIELD_SET(0,DE_CONTROL,TRANSPARENCY_MATCH,OPAQUE)|
FIELD_SET(0,DE_CONTROL,TRANSPARENCY_SELECT,SOURCE);
clr = FIELD_CLEAR(DE_CONTROL,TRANSPARENCY)&
FIELD_CLEAR(DE_CONTROL,TRANSPARENCY_MATCH)&
FIELD_CLEAR(DE_CONTROL,TRANSPARENCY_SELECT);
write_dpr(accel,DE_CONTROL,(read_dpr(accel,DE_CONTROL)&clr)|reg);
}
void hw_set2dformat(struct lynx_accel * accel,int fmt)
{
u32 reg;
reg = read_dpr(accel,DE_STRETCH_FORMAT);
reg = FIELD_VALUE(reg,DE_STRETCH_FORMAT,PIXEL_FORMAT,fmt);
write_dpr(accel,DE_STRETCH_FORMAT,reg);
}
int hw_fillrect(struct lynx_accel * accel,
u32 base,u32 pitch,u32 Bpp,
u32 x,u32 y,u32 width,u32 height,
u32 color,u32 rop)
{
u32 deCtrl;
if(accel->de_wait() != 0)
{
pr_debug("%s:De engine always bussy\n",__func__);
return -1;
}
write_dpr(accel,DE_WINDOW_DESTINATION_BASE,base);
write_dpr(accel,DE_PITCH,
FIELD_VALUE(0,DE_PITCH,DESTINATION,pitch/Bpp)|
FIELD_VALUE(0,DE_PITCH,SOURCE,pitch/Bpp));
write_dpr(accel,DE_WINDOW_WIDTH,
FIELD_VALUE(0,DE_WINDOW_WIDTH,DESTINATION,pitch/Bpp)|
FIELD_VALUE(0,DE_WINDOW_WIDTH,SOURCE,pitch/Bpp));
write_dpr(accel,DE_FOREGROUND,color);
write_dpr(accel,DE_DESTINATION,
FIELD_SET(0,DE_DESTINATION,WRAP,DISABLE)|
FIELD_VALUE(0,DE_DESTINATION,X,x)|
FIELD_VALUE(0,DE_DESTINATION,Y,y));
write_dpr(accel,DE_DIMENSION,
FIELD_VALUE(0,DE_DIMENSION,X,width)|
FIELD_VALUE(0,DE_DIMENSION,Y_ET,height));
deCtrl =
FIELD_SET(0,DE_CONTROL,STATUS,START)|
FIELD_SET(0,DE_CONTROL,DIRECTION,LEFT_TO_RIGHT)|
FIELD_SET(0,DE_CONTROL,LAST_PIXEL,ON)|
FIELD_SET(0,DE_CONTROL,COMMAND,RECTANGLE_FILL)|
FIELD_SET(0,DE_CONTROL,ROP_SELECT,ROP2)|
FIELD_VALUE(0,DE_CONTROL,ROP,rop);
write_dpr(accel,DE_CONTROL,deCtrl);
return 0;
}
int hw_copyarea(
struct lynx_accel * accel,
unsigned int sBase,
unsigned int sPitch,
unsigned int sx,
unsigned int sy,
unsigned int dBase,
unsigned int dPitch,
unsigned int Bpp,
unsigned int dx,
unsigned int dy,
unsigned int width,
unsigned int height,
unsigned int rop2)
{
unsigned int nDirection, de_ctrl;
int opSign;
nDirection = LEFT_TO_RIGHT;
opSign = 1;
de_ctrl = 0;
if (sBase == dBase && sPitch == dPitch)
{
if (sy < dy)
{
nDirection = BOTTOM_TO_TOP;
}
else if (sy > dy)
{
nDirection = TOP_TO_BOTTOM;
}
else
{
if (sx <= dx)
{
nDirection = RIGHT_TO_LEFT;
}
else
{
nDirection = LEFT_TO_RIGHT;
}
}
}
if ((nDirection == BOTTOM_TO_TOP) || (nDirection == RIGHT_TO_LEFT))
{
sx += width - 1;
sy += height - 1;
dx += width - 1;
dy += height - 1;
opSign = (-1);
}
write_dpr(accel,DE_WINDOW_SOURCE_BASE, sBase);
write_dpr(accel,DE_WINDOW_DESTINATION_BASE, dBase);
#if 0
if(Bpp == 3){
sx *= 3;
dx *= 3;
width *= 3;
write_dpr(accel,DE_PITCH,
FIELD_VALUE(0, DE_PITCH, DESTINATION, dPitch) |
FIELD_VALUE(0, DE_PITCH, SOURCE, sPitch));
}
else
#endif
{
write_dpr(accel,DE_PITCH,
FIELD_VALUE(0, DE_PITCH, DESTINATION, (dPitch/Bpp)) |
FIELD_VALUE(0, DE_PITCH, SOURCE, (sPitch/Bpp)));
}
write_dpr(accel,DE_WINDOW_WIDTH,
FIELD_VALUE(0, DE_WINDOW_WIDTH, DESTINATION, (dPitch/Bpp)) |
FIELD_VALUE(0, DE_WINDOW_WIDTH, SOURCE, (sPitch/Bpp)));
if (accel->de_wait() != 0){
return -1;
}
{
write_dpr(accel,DE_SOURCE,
FIELD_SET (0, DE_SOURCE, WRAP, DISABLE) |
FIELD_VALUE(0, DE_SOURCE, X_K1, sx) |
FIELD_VALUE(0, DE_SOURCE, Y_K2, sy));
write_dpr(accel,DE_DESTINATION,
FIELD_SET (0, DE_DESTINATION, WRAP, DISABLE) |
FIELD_VALUE(0, DE_DESTINATION, X, dx) |
FIELD_VALUE(0, DE_DESTINATION, Y, dy));
write_dpr(accel,DE_DIMENSION,
FIELD_VALUE(0, DE_DIMENSION, X, width) |
FIELD_VALUE(0, DE_DIMENSION, Y_ET, height));
de_ctrl =
FIELD_VALUE(0, DE_CONTROL, ROP, rop2) |
FIELD_SET(0, DE_CONTROL, ROP_SELECT, ROP2) |
FIELD_SET(0, DE_CONTROL, COMMAND, BITBLT) |
((nDirection == RIGHT_TO_LEFT) ?
FIELD_SET(0, DE_CONTROL, DIRECTION, RIGHT_TO_LEFT)
: FIELD_SET(0, DE_CONTROL, DIRECTION, LEFT_TO_RIGHT)) |
FIELD_SET(0, DE_CONTROL, STATUS, START);
write_dpr(accel,DE_CONTROL,de_ctrl);
}
return 0;
}
static unsigned int deGetTransparency(struct lynx_accel * accel)
{
unsigned int de_ctrl;
de_ctrl = read_dpr(accel,DE_CONTROL);
de_ctrl &=
FIELD_MASK(DE_CONTROL_TRANSPARENCY_MATCH) |
FIELD_MASK(DE_CONTROL_TRANSPARENCY_SELECT)|
FIELD_MASK(DE_CONTROL_TRANSPARENCY);
return de_ctrl;
}
int hw_imageblit(struct lynx_accel *accel,
const char *pSrcbuf,
u32 srcDelta,
u32 startBit,
u32 dBase,
u32 dPitch,
u32 bytePerPixel,
u32 dx,
u32 dy,
u32 width,
u32 height,
u32 fColor,
u32 bColor,
u32 rop2)
{
unsigned int ulBytesPerScan;
unsigned int ul4BytesPerScan;
unsigned int ulBytesRemain;
unsigned int de_ctrl = 0;
unsigned char ajRemain[4];
int i, j;
startBit &= 7;
ulBytesPerScan = (width + startBit + 7) / 8;
ul4BytesPerScan = ulBytesPerScan & ~3;
ulBytesRemain = ulBytesPerScan & 3;
if(accel->de_wait() != 0)
{
return -1;
}
write_dpr(accel,DE_WINDOW_SOURCE_BASE, 0);
write_dpr(accel,DE_WINDOW_DESTINATION_BASE, dBase);
#if 0
if(bytePerPixel == 3 ){
dx *= 3;
width *= 3;
startBit *= 3;
write_dpr(accel,DE_PITCH,
FIELD_VALUE(0, DE_PITCH, DESTINATION, dPitch) |
FIELD_VALUE(0, DE_PITCH, SOURCE, dPitch));
}
else
#endif
{
write_dpr(accel,DE_PITCH,
FIELD_VALUE(0, DE_PITCH, DESTINATION, dPitch/bytePerPixel) |
FIELD_VALUE(0, DE_PITCH, SOURCE, dPitch/bytePerPixel));
}
write_dpr(accel,DE_WINDOW_WIDTH,
FIELD_VALUE(0, DE_WINDOW_WIDTH, DESTINATION, (dPitch/bytePerPixel)) |
FIELD_VALUE(0, DE_WINDOW_WIDTH, SOURCE, (dPitch/bytePerPixel)));
write_dpr(accel,DE_SOURCE,
FIELD_SET (0, DE_SOURCE, WRAP, DISABLE) |
FIELD_VALUE(0, DE_SOURCE, X_K1_MONO, startBit));
write_dpr(accel,DE_DESTINATION,
FIELD_SET (0, DE_DESTINATION, WRAP, DISABLE) |
FIELD_VALUE(0, DE_DESTINATION, X, dx) |
FIELD_VALUE(0, DE_DESTINATION, Y, dy));
write_dpr(accel,DE_DIMENSION,
FIELD_VALUE(0, DE_DIMENSION, X, width) |
FIELD_VALUE(0, DE_DIMENSION, Y_ET, height));
write_dpr(accel,DE_FOREGROUND, fColor);
write_dpr(accel,DE_BACKGROUND, bColor);
de_ctrl = FIELD_VALUE(0, DE_CONTROL, ROP, rop2) |
FIELD_SET(0, DE_CONTROL, ROP_SELECT, ROP2) |
FIELD_SET(0, DE_CONTROL, COMMAND, HOST_WRITE) |
FIELD_SET(0, DE_CONTROL, HOST, MONO) |
FIELD_SET(0, DE_CONTROL, STATUS, START);
write_dpr(accel,DE_CONTROL, de_ctrl | deGetTransparency(accel));
for (i=0; i<height; i++)
{
for (j=0; j<(ul4BytesPerScan/4); j++)
{
write_dpPort(accel, *(unsigned int *)(pSrcbuf + (j * 4)));
}
if (ulBytesRemain)
{
memcpy(ajRemain, pSrcbuf+ul4BytesPerScan, ulBytesRemain);
write_dpPort(accel, *(unsigned int *)ajRemain);
}
pSrcbuf += srcDelta;
}
return 0;
}
