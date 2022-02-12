void hw_cursor_enable(struct lynx_cursor *cursor)
{
u32 reg;
reg = FIELD_VALUE(0, HWC_ADDRESS, ADDRESS, cursor->offset)|
FIELD_SET(0, HWC_ADDRESS, EXT, LOCAL)|
FIELD_SET(0, HWC_ADDRESS, ENABLE, ENABLE);
POKE32(HWC_ADDRESS, reg);
}
void hw_cursor_disable(struct lynx_cursor *cursor)
{
POKE32(HWC_ADDRESS, 0);
}
void hw_cursor_setSize(struct lynx_cursor *cursor,
int w, int h)
{
cursor->w = w;
cursor->h = h;
}
void hw_cursor_setPos(struct lynx_cursor *cursor,
int x, int y)
{
u32 reg;
reg = FIELD_VALUE(0, HWC_LOCATION, Y, y)|
FIELD_VALUE(0, HWC_LOCATION, X, x);
POKE32(HWC_LOCATION, reg);
}
void hw_cursor_setColor(struct lynx_cursor *cursor,
u32 fg, u32 bg)
{
POKE32(HWC_COLOR_12, (fg<<16)|(bg&0xffff));
POKE32(HWC_COLOR_3, 0xffe0);
}
void hw_cursor_setData(struct lynx_cursor *cursor,
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
if (mask & (0x80>>j)) {
if (rop == ROP_XOR)
opr = mask ^ color;
else
opr = mask & color;
data |= ((opr & (0x80>>j))?2:1)<<(j*2);
}
}
iowrite16(data, pbuffer);
if ((i+1) % pitch == 0)
{
pstart += offset;
pbuffer = pstart;
} else {
pbuffer += sizeof(u16);
}
}
}
void hw_cursor_setData2(struct lynx_cursor *cursor,
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
if (mask & (1<<j))
data |= ((color & (1<<j))?1:2)<<(j*2);
}
iowrite16(data, pbuffer);
if (!(i&(pitch-1))) {
pstart += offset;
pbuffer = pstart;
} else {
pbuffer += sizeof(u16);
}
}
}
