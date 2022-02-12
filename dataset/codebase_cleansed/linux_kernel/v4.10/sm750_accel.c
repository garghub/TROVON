static inline void write_dpr(struct lynx_accel *accel, int offset, u32 regValue)
{
writel(regValue, accel->dprBase + offset);
}
static inline u32 read_dpr(struct lynx_accel *accel, int offset)
{
return readl(accel->dprBase + offset);
}
static inline void write_dpPort(struct lynx_accel *accel, u32 data)
{
writel(data, accel->dpPortBase);
}
void sm750_hw_de_init(struct lynx_accel *accel)
{
u32 reg, clr;
write_dpr(accel, DE_MASKS, 0xFFFFFFFF);
reg = 0x3;
clr = DE_STRETCH_FORMAT_PATTERN_XY | DE_STRETCH_FORMAT_PATTERN_Y_MASK |
DE_STRETCH_FORMAT_PATTERN_X_MASK |
DE_STRETCH_FORMAT_ADDRESSING_MASK |
DE_STRETCH_FORMAT_SOURCE_HEIGHT_MASK;
write_dpr(accel, DE_STRETCH_FORMAT,
(read_dpr(accel, DE_STRETCH_FORMAT) & ~clr) | reg);
write_dpr(accel, DE_CLIP_TL, 0);
write_dpr(accel, DE_CLIP_BR, 0);
write_dpr(accel, DE_COLOR_COMPARE_MASK, 0);
write_dpr(accel, DE_COLOR_COMPARE, 0);
clr = DE_CONTROL_TRANSPARENCY | DE_CONTROL_TRANSPARENCY_MATCH |
DE_CONTROL_TRANSPARENCY_SELECT;
write_dpr(accel, DE_CONTROL, read_dpr(accel, DE_CONTROL) & ~clr);
}
void sm750_hw_set2dformat(struct lynx_accel *accel, int fmt)
{
u32 reg;
reg = read_dpr(accel, DE_STRETCH_FORMAT);
reg &= ~DE_STRETCH_FORMAT_PIXEL_FORMAT_MASK;
reg |= ((fmt << DE_STRETCH_FORMAT_PIXEL_FORMAT_SHIFT) &
DE_STRETCH_FORMAT_PIXEL_FORMAT_MASK);
write_dpr(accel, DE_STRETCH_FORMAT, reg);
}
int sm750_hw_fillrect(struct lynx_accel *accel,
u32 base, u32 pitch, u32 Bpp,
u32 x, u32 y, u32 width, u32 height,
u32 color, u32 rop)
{
u32 deCtrl;
if (accel->de_wait() != 0) {
pr_debug("De engine always busy\n");
return -1;
}
write_dpr(accel, DE_WINDOW_DESTINATION_BASE, base);
write_dpr(accel, DE_PITCH,
((pitch / Bpp << DE_PITCH_DESTINATION_SHIFT) &
DE_PITCH_DESTINATION_MASK) |
(pitch / Bpp & DE_PITCH_SOURCE_MASK));
write_dpr(accel, DE_WINDOW_WIDTH,
((pitch / Bpp << DE_WINDOW_WIDTH_DST_SHIFT) &
DE_WINDOW_WIDTH_DST_MASK) |
(pitch / Bpp & DE_WINDOW_WIDTH_SRC_MASK));
write_dpr(accel, DE_FOREGROUND, color);
write_dpr(accel, DE_DESTINATION,
((x << DE_DESTINATION_X_SHIFT) & DE_DESTINATION_X_MASK) |
(y & DE_DESTINATION_Y_MASK));
write_dpr(accel, DE_DIMENSION,
((width << DE_DIMENSION_X_SHIFT) & DE_DIMENSION_X_MASK) |
(height & DE_DIMENSION_Y_ET_MASK));
deCtrl = DE_CONTROL_STATUS | DE_CONTROL_LAST_PIXEL |
DE_CONTROL_COMMAND_RECTANGLE_FILL | DE_CONTROL_ROP_SELECT |
(rop & DE_CONTROL_ROP_MASK);
write_dpr(accel, DE_CONTROL, deCtrl);
return 0;
}
int sm750_hw_copyarea(
struct lynx_accel *accel,
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
if (sBase == dBase && sPitch == dPitch) {
if (sy < dy) {
nDirection = BOTTOM_TO_TOP;
} else if (sy > dy) {
nDirection = TOP_TO_BOTTOM;
} else {
if (sx <= dx) {
nDirection = RIGHT_TO_LEFT;
} else {
nDirection = LEFT_TO_RIGHT;
}
}
}
if ((nDirection == BOTTOM_TO_TOP) || (nDirection == RIGHT_TO_LEFT)) {
sx += width - 1;
sy += height - 1;
dx += width - 1;
dy += height - 1;
opSign = (-1);
}
write_dpr(accel, DE_WINDOW_SOURCE_BASE, sBase);
write_dpr(accel, DE_WINDOW_DESTINATION_BASE, dBase);
write_dpr(accel, DE_PITCH,
((dPitch / Bpp << DE_PITCH_DESTINATION_SHIFT) &
DE_PITCH_DESTINATION_MASK) |
(sPitch / Bpp & DE_PITCH_SOURCE_MASK));
write_dpr(accel, DE_WINDOW_WIDTH,
((dPitch / Bpp << DE_WINDOW_WIDTH_DST_SHIFT) &
DE_WINDOW_WIDTH_DST_MASK) |
(sPitch / Bpp & DE_WINDOW_WIDTH_SRC_MASK));
if (accel->de_wait() != 0)
return -1;
{
write_dpr(accel, DE_SOURCE,
((sx << DE_SOURCE_X_K1_SHIFT) & DE_SOURCE_X_K1_MASK) |
(sy & DE_SOURCE_Y_K2_MASK));
write_dpr(accel, DE_DESTINATION,
((dx << DE_DESTINATION_X_SHIFT) & DE_DESTINATION_X_MASK) |
(dy & DE_DESTINATION_Y_MASK));
write_dpr(accel, DE_DIMENSION,
((width << DE_DIMENSION_X_SHIFT) & DE_DIMENSION_X_MASK) |
(height & DE_DIMENSION_Y_ET_MASK));
de_ctrl = (rop2 & DE_CONTROL_ROP_MASK) | DE_CONTROL_ROP_SELECT |
((nDirection == RIGHT_TO_LEFT) ? DE_CONTROL_DIRECTION : 0) |
DE_CONTROL_COMMAND_BITBLT | DE_CONTROL_STATUS;
write_dpr(accel, DE_CONTROL, de_ctrl);
}
return 0;
}
static unsigned int deGetTransparency(struct lynx_accel *accel)
{
unsigned int de_ctrl;
de_ctrl = read_dpr(accel, DE_CONTROL);
de_ctrl &= (DE_CONTROL_TRANSPARENCY_MATCH |
DE_CONTROL_TRANSPARENCY_SELECT | DE_CONTROL_TRANSPARENCY);
return de_ctrl;
}
int sm750_hw_imageblit(struct lynx_accel *accel,
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
if (accel->de_wait() != 0)
return -1;
write_dpr(accel, DE_WINDOW_SOURCE_BASE, 0);
write_dpr(accel, DE_WINDOW_DESTINATION_BASE, dBase);
write_dpr(accel, DE_PITCH,
((dPitch / bytePerPixel << DE_PITCH_DESTINATION_SHIFT) &
DE_PITCH_DESTINATION_MASK) |
(dPitch / bytePerPixel & DE_PITCH_SOURCE_MASK));
write_dpr(accel, DE_WINDOW_WIDTH,
((dPitch / bytePerPixel << DE_WINDOW_WIDTH_DST_SHIFT) &
DE_WINDOW_WIDTH_DST_MASK) |
(dPitch / bytePerPixel & DE_WINDOW_WIDTH_SRC_MASK));
write_dpr(accel, DE_SOURCE,
(startBit << DE_SOURCE_X_K1_SHIFT) &
DE_SOURCE_X_K1_MONO_MASK);
write_dpr(accel, DE_DESTINATION,
((dx << DE_DESTINATION_X_SHIFT) & DE_DESTINATION_X_MASK) |
(dy & DE_DESTINATION_Y_MASK));
write_dpr(accel, DE_DIMENSION,
((width << DE_DIMENSION_X_SHIFT) & DE_DIMENSION_X_MASK) |
(height & DE_DIMENSION_Y_ET_MASK));
write_dpr(accel, DE_FOREGROUND, fColor);
write_dpr(accel, DE_BACKGROUND, bColor);
de_ctrl = (rop2 & DE_CONTROL_ROP_MASK) |
DE_CONTROL_ROP_SELECT | DE_CONTROL_COMMAND_HOST_WRITE |
DE_CONTROL_HOST | DE_CONTROL_STATUS;
write_dpr(accel, DE_CONTROL, de_ctrl | deGetTransparency(accel));
for (i = 0; i < height; i++) {
for (j = 0; j < (ul4BytesPerScan/4); j++)
write_dpPort(accel, *(unsigned int *)(pSrcbuf + (j * 4)));
if (ulBytesRemain) {
memcpy(ajRemain, pSrcbuf+ul4BytesPerScan, ulBytesRemain);
write_dpPort(accel, *(unsigned int *)ajRemain);
}
pSrcbuf += srcDelta;
}
return 0;
}
