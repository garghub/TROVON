void sm750_hw_cursor_enable(struct lynx_cursor *cursor)
{
u32 reg;
reg = (cursor->offset & HWC_ADDRESS_ADDRESS_MASK) | HWC_ADDRESS_ENABLE;
poke32(HWC_ADDRESS, reg);
}
void sm750_hw_cursor_disable(struct lynx_cursor *cursor)
{
poke32(HWC_ADDRESS, 0);
}
void sm750_hw_cursor_setSize(struct lynx_cursor *cursor,
int w, int h)
{
cursor->w = w;
cursor->h = h;
}
void sm750_hw_cursor_setPos(struct lynx_cursor *cursor,
int x, int y)
{
u32 reg;
reg = ((y << HWC_LOCATION_Y_SHIFT) & HWC_LOCATION_Y_MASK) |
(x & HWC_LOCATION_X_MASK);
poke32(HWC_LOCATION, reg);
}
void sm750_hw_cursor_setColor(struct lynx_cursor *cursor,
u32 fg, u32 bg)
{
u32 reg = (fg << HWC_COLOR_12_2_RGB565_SHIFT) &
HWC_COLOR_12_2_RGB565_MASK;
poke32(HWC_COLOR_12, reg | (bg & HWC_COLOR_12_1_RGB565_MASK));
poke32(HWC_COLOR_3, 0xffe0);
}
void sm750_hw_cursor_setData(struct lynx_cursor *cursor,
u16 rop, const u8 *pcol, const u8 *pmsk)
{
int i, j, count, pitch, offset;
u8 color, mask, opr;
u16 data;
void __iomem *pbuffer, *pstart;
pitch = cursor->w >> 3;
count = pitch * cursor->h;
offset = cursor->maxW * 2 / 8;
data = 0;
pstart = cursor->vstart;
pbuffer = pstart;
for (i = 0; i < count; i++) {
color = *pcol++;
mask = *pmsk++;
data = 0;
for (j = 0; j < 8; j++) {
if (mask & (0x80 >> j)) {
if (rop == ROP_XOR)
opr = mask ^ color;
else
opr = mask & color;
data |= ((opr & (0x80 >> j)) ? 2 : 1) << (j * 2);
}
}
iowrite16(data, pbuffer);
if ((i + 1) % pitch == 0) {
pstart += offset;
pbuffer = pstart;
} else {
pbuffer += sizeof(u16);
}
}
}
void sm750_hw_cursor_setData2(struct lynx_cursor *cursor,
u16 rop, const u8 *pcol, const u8 *pmsk)
{
int i, j, count, pitch, offset;
u8 color, mask;
u16 data;
void __iomem *pbuffer, *pstart;
pitch = cursor->w >> 3;
count = pitch * cursor->h;
offset = cursor->maxW * 2 / 8;
data = 0;
pstart = cursor->vstart;
pbuffer = pstart;
for (i = 0; i < count; i++) {
color = *pcol++;
mask = *pmsk++;
data = 0;
for (j = 0; j < 8; j++) {
if (mask & (1 << j))
data |= ((color & (1 << j)) ? 1 : 2) << (j * 2);
}
iowrite16(data, pbuffer);
if (!(i & (pitch - 1))) {
pstart += offset;
pbuffer = pstart;
} else {
pbuffer += sizeof(u16);
}
}
}
