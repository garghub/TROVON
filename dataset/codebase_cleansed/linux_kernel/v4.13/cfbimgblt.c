static inline void color_imageblit(const struct fb_image *image,
struct fb_info *p, u8 __iomem *dst1,
u32 start_index,
u32 pitch_index)
{
u32 __iomem *dst, *dst2;
u32 color = 0, val, shift;
int i, n, bpp = p->var.bits_per_pixel;
u32 null_bits = 32 - bpp;
u32 *palette = (u32 *) p->pseudo_palette;
const u8 *src = image->data;
u32 bswapmask = fb_compute_bswapmask(p);
dst2 = (u32 __iomem *) dst1;
for (i = image->height; i--; ) {
n = image->width;
dst = (u32 __iomem *) dst1;
shift = 0;
val = 0;
if (start_index) {
u32 start_mask = ~fb_shifted_pixels_mask_u32(p,
start_index, bswapmask);
val = FB_READL(dst) & start_mask;
shift = start_index;
}
while (n--) {
if (p->fix.visual == FB_VISUAL_TRUECOLOR ||
p->fix.visual == FB_VISUAL_DIRECTCOLOR )
color = palette[*src];
else
color = *src;
color <<= FB_LEFT_POS(p, bpp);
val |= FB_SHIFT_HIGH(p, color, shift ^ bswapmask);
if (shift >= null_bits) {
FB_WRITEL(val, dst++);
val = (shift == null_bits) ? 0 :
FB_SHIFT_LOW(p, color, 32 - shift);
}
shift += bpp;
shift &= (32 - 1);
src++;
}
if (shift) {
u32 end_mask = fb_shifted_pixels_mask_u32(p, shift,
bswapmask);
FB_WRITEL((FB_READL(dst) & end_mask) | val, dst);
}
dst1 += p->fix.line_length;
if (pitch_index) {
dst2 += p->fix.line_length;
dst1 = (u8 __iomem *)((long __force)dst2 & ~(sizeof(u32) - 1));
start_index += pitch_index;
start_index &= 32 - 1;
}
}
}
static inline void slow_imageblit(const struct fb_image *image, struct fb_info *p,
u8 __iomem *dst1, u32 fgcolor,
u32 bgcolor,
u32 start_index,
u32 pitch_index)
{
u32 shift, color = 0, bpp = p->var.bits_per_pixel;
u32 __iomem *dst, *dst2;
u32 val, pitch = p->fix.line_length;
u32 null_bits = 32 - bpp;
u32 spitch = (image->width+7)/8;
const u8 *src = image->data, *s;
u32 i, j, l;
u32 bswapmask = fb_compute_bswapmask(p);
dst2 = (u32 __iomem *) dst1;
fgcolor <<= FB_LEFT_POS(p, bpp);
bgcolor <<= FB_LEFT_POS(p, bpp);
for (i = image->height; i--; ) {
shift = val = 0;
l = 8;
j = image->width;
dst = (u32 __iomem *) dst1;
s = src;
if (start_index) {
u32 start_mask = ~fb_shifted_pixels_mask_u32(p,
start_index, bswapmask);
val = FB_READL(dst) & start_mask;
shift = start_index;
}
while (j--) {
l--;
color = (*s & (1 << l)) ? fgcolor : bgcolor;
val |= FB_SHIFT_HIGH(p, color, shift ^ bswapmask);
if (shift >= null_bits) {
FB_WRITEL(val, dst++);
val = (shift == null_bits) ? 0 :
FB_SHIFT_LOW(p, color, 32 - shift);
}
shift += bpp;
shift &= (32 - 1);
if (!l) { l = 8; s++; }
}
if (shift) {
u32 end_mask = fb_shifted_pixels_mask_u32(p, shift,
bswapmask);
FB_WRITEL((FB_READL(dst) & end_mask) | val, dst);
}
dst1 += pitch;
src += spitch;
if (pitch_index) {
dst2 += pitch;
dst1 = (u8 __iomem *)((long __force)dst2 & ~(sizeof(u32) - 1));
start_index += pitch_index;
start_index &= 32 - 1;
}
}
}
static inline void fast_imageblit(const struct fb_image *image, struct fb_info *p,
u8 __iomem *dst1, u32 fgcolor,
u32 bgcolor)
{
u32 fgx = fgcolor, bgx = bgcolor, bpp = p->var.bits_per_pixel;
u32 ppw = 32/bpp, spitch = (image->width + 7)/8;
u32 bit_mask, end_mask, eorx, shift;
const char *s = image->data, *src;
u32 __iomem *dst;
const u32 *tab = NULL;
int i, j, k;
switch (bpp) {
case 8:
tab = fb_be_math(p) ? cfb_tab8_be : cfb_tab8_le;
break;
case 16:
tab = fb_be_math(p) ? cfb_tab16_be : cfb_tab16_le;
break;
case 32:
default:
tab = cfb_tab32;
break;
}
for (i = ppw-1; i--; ) {
fgx <<= bpp;
bgx <<= bpp;
fgx |= fgcolor;
bgx |= bgcolor;
}
bit_mask = (1 << ppw) - 1;
eorx = fgx ^ bgx;
k = image->width/ppw;
for (i = image->height; i--; ) {
dst = (u32 __iomem *) dst1, shift = 8; src = s;
for (j = k; j--; ) {
shift -= ppw;
end_mask = tab[(*src >> shift) & bit_mask];
FB_WRITEL((end_mask & eorx)^bgx, dst++);
if (!shift) { shift = 8; src++; }
}
dst1 += p->fix.line_length;
s += spitch;
}
}
void cfb_imageblit(struct fb_info *p, const struct fb_image *image)
{
u32 fgcolor, bgcolor, start_index, bitstart, pitch_index = 0;
u32 bpl = sizeof(u32), bpp = p->var.bits_per_pixel;
u32 width = image->width;
u32 dx = image->dx, dy = image->dy;
u8 __iomem *dst1;
if (p->state != FBINFO_STATE_RUNNING)
return;
bitstart = (dy * p->fix.line_length * 8) + (dx * bpp);
start_index = bitstart & (32 - 1);
pitch_index = (p->fix.line_length & (bpl - 1)) * 8;
bitstart /= 8;
bitstart &= ~(bpl - 1);
dst1 = p->screen_base + bitstart;
if (p->fbops->fb_sync)
p->fbops->fb_sync(p);
if (image->depth == 1) {
if (p->fix.visual == FB_VISUAL_TRUECOLOR ||
p->fix.visual == FB_VISUAL_DIRECTCOLOR) {
fgcolor = ((u32*)(p->pseudo_palette))[image->fg_color];
bgcolor = ((u32*)(p->pseudo_palette))[image->bg_color];
} else {
fgcolor = image->fg_color;
bgcolor = image->bg_color;
}
if (32 % bpp == 0 && !start_index && !pitch_index &&
((width & (32/bpp-1)) == 0) &&
bpp >= 8 && bpp <= 32)
fast_imageblit(image, p, dst1, fgcolor, bgcolor);
else
slow_imageblit(image, p, dst1, fgcolor, bgcolor,
start_index, pitch_index);
} else
color_imageblit(image, p, dst1, start_index, pitch_index);
}
