void svga_wcrt_multi(void __iomem *regbase, const struct vga_regset *regset, u32 value)
{
u8 regval, bitval, bitnum;
while (regset->regnum != VGA_REGSET_END_VAL) {
regval = vga_rcrt(regbase, regset->regnum);
bitnum = regset->lowbit;
while (bitnum <= regset->highbit) {
bitval = 1 << bitnum;
regval = regval & ~bitval;
if (value & 1) regval = regval | bitval;
bitnum ++;
value = value >> 1;
}
vga_wcrt(regbase, regset->regnum, regval);
regset ++;
}
}
void svga_wseq_multi(void __iomem *regbase, const struct vga_regset *regset, u32 value)
{
u8 regval, bitval, bitnum;
while (regset->regnum != VGA_REGSET_END_VAL) {
regval = vga_rseq(regbase, regset->regnum);
bitnum = regset->lowbit;
while (bitnum <= regset->highbit) {
bitval = 1 << bitnum;
regval = regval & ~bitval;
if (value & 1) regval = regval | bitval;
bitnum ++;
value = value >> 1;
}
vga_wseq(regbase, regset->regnum, regval);
regset ++;
}
}
static unsigned int svga_regset_size(const struct vga_regset *regset)
{
u8 count = 0;
while (regset->regnum != VGA_REGSET_END_VAL) {
count += regset->highbit - regset->lowbit + 1;
regset ++;
}
return 1 << count;
}
void svga_set_default_gfx_regs(void __iomem *regbase)
{
vga_wgfx(regbase, VGA_GFX_SR_VALUE, 0x00);
vga_wgfx(regbase, VGA_GFX_SR_ENABLE, 0x00);
vga_wgfx(regbase, VGA_GFX_COMPARE_VALUE, 0x00);
vga_wgfx(regbase, VGA_GFX_DATA_ROTATE, 0x00);
vga_wgfx(regbase, VGA_GFX_PLANE_READ, 0x00);
vga_wgfx(regbase, VGA_GFX_MODE, 0x00);
vga_wgfx(regbase, VGA_GFX_MISC, 0x05);
vga_wgfx(regbase, VGA_GFX_COMPARE_MASK, 0x0F);
vga_wgfx(regbase, VGA_GFX_BIT_MASK, 0xFF);
}
void svga_set_default_atc_regs(void __iomem *regbase)
{
u8 count;
vga_r(regbase, 0x3DA);
vga_w(regbase, VGA_ATT_W, 0x00);
for (count = 0; count <= 0xF; count ++)
svga_wattr(regbase, count, count);
svga_wattr(regbase, VGA_ATC_MODE, 0x01);
svga_wattr(regbase, VGA_ATC_OVERSCAN, 0x00);
svga_wattr(regbase, VGA_ATC_PLANE_ENABLE, 0x0F);
svga_wattr(regbase, VGA_ATC_PEL, 0x00);
svga_wattr(regbase, VGA_ATC_COLOR_PAGE, 0x00);
vga_r(regbase, 0x3DA);
vga_w(regbase, VGA_ATT_W, 0x20);
}
void svga_set_default_seq_regs(void __iomem *regbase)
{
vga_wseq(regbase, VGA_SEQ_CLOCK_MODE, VGA_SR01_CHAR_CLK_8DOTS);
vga_wseq(regbase, VGA_SEQ_PLANE_WRITE, VGA_SR02_ALL_PLANES);
vga_wseq(regbase, VGA_SEQ_CHARACTER_MAP, 0x00);
vga_wseq(regbase, VGA_SEQ_MEMORY_MODE, VGA_SR04_EXT_MEM | VGA_SR04_SEQ_MODE);
}
void svga_set_default_crt_regs(void __iomem *regbase)
{
svga_wcrt_mask(regbase, 0x03, 0x80, 0x80);
vga_wcrt(regbase, VGA_CRTC_PRESET_ROW, 0);
svga_wcrt_mask(regbase, VGA_CRTC_MAX_SCAN, 0, 0x1F);
vga_wcrt(regbase, VGA_CRTC_UNDERLINE, 0);
vga_wcrt(regbase, VGA_CRTC_MODE, 0xE3);
}
void svga_set_textmode_vga_regs(void __iomem *regbase)
{
vga_wseq(regbase, VGA_SEQ_MEMORY_MODE, VGA_SR04_EXT_MEM);
vga_wseq(regbase, VGA_SEQ_PLANE_WRITE, 0x03);
vga_wcrt(regbase, VGA_CRTC_MAX_SCAN, 0x0f);
vga_wcrt(regbase, VGA_CRTC_UNDERLINE, 0x1f);
svga_wcrt_mask(regbase, VGA_CRTC_MODE, 0x23, 0x7f);
vga_wcrt(regbase, VGA_CRTC_CURSOR_START, 0x0d);
vga_wcrt(regbase, VGA_CRTC_CURSOR_END, 0x0e);
vga_wcrt(regbase, VGA_CRTC_CURSOR_HI, 0x00);
vga_wcrt(regbase, VGA_CRTC_CURSOR_LO, 0x00);
vga_wgfx(regbase, VGA_GFX_MODE, 0x10);
vga_wgfx(regbase, VGA_GFX_MISC, 0x0E);
vga_wgfx(regbase, VGA_GFX_COMPARE_MASK, 0x00);
vga_r(regbase, 0x3DA);
vga_w(regbase, VGA_ATT_W, 0x00);
svga_wattr(regbase, 0x10, 0x0C);
svga_wattr(regbase, 0x13, 0x08);
vga_r(regbase, 0x3DA);
vga_w(regbase, VGA_ATT_W, 0x20);
}
void svga_settile(struct fb_info *info, struct fb_tilemap *map)
{
const u8 *font = map->data;
u8 __iomem *fb = (u8 __iomem *)info->screen_base;
int i, c;
if ((map->width != 8) || (map->height != 16) ||
(map->depth != 1) || (map->length != 256)) {
fb_err(info, "unsupported font parameters: width %d, height %d, depth %d, length %d\n",
map->width, map->height, map->depth, map->length);
return;
}
fb += 2;
for (c = 0; c < map->length; c++) {
for (i = 0; i < map->height; i++) {
fb_writeb(font[i], fb + i * 4);
}
fb += 128;
font += map->height;
}
}
void svga_tilecopy(struct fb_info *info, struct fb_tilearea *area)
{
int dx, dy;
int colstride = 1 << (info->fix.type_aux & FB_AUX_TEXT_SVGA_MASK);
int rowstride = colstride * (info->var.xres_virtual / 8);
u16 __iomem *fb = (u16 __iomem *) info->screen_base;
u16 __iomem *src, *dst;
if ((area->sy > area->dy) ||
((area->sy == area->dy) && (area->sx > area->dx))) {
src = fb + area->sx * colstride + area->sy * rowstride;
dst = fb + area->dx * colstride + area->dy * rowstride;
} else {
src = fb + (area->sx + area->width - 1) * colstride
+ (area->sy + area->height - 1) * rowstride;
dst = fb + (area->dx + area->width - 1) * colstride
+ (area->dy + area->height - 1) * rowstride;
colstride = -colstride;
rowstride = -rowstride;
}
for (dy = 0; dy < area->height; dy++) {
u16 __iomem *src2 = src;
u16 __iomem *dst2 = dst;
for (dx = 0; dx < area->width; dx++) {
fb_writew(fb_readw(src2), dst2);
src2 += colstride;
dst2 += colstride;
}
src += rowstride;
dst += rowstride;
}
}
void svga_tilefill(struct fb_info *info, struct fb_tilerect *rect)
{
int dx, dy;
int colstride = 2 << (info->fix.type_aux & FB_AUX_TEXT_SVGA_MASK);
int rowstride = colstride * (info->var.xres_virtual / 8);
int attr = (0x0F & rect->bg) << 4 | (0x0F & rect->fg);
u8 __iomem *fb = (u8 __iomem *)info->screen_base;
fb += rect->sx * colstride + rect->sy * rowstride;
for (dy = 0; dy < rect->height; dy++) {
u8 __iomem *fb2 = fb;
for (dx = 0; dx < rect->width; dx++) {
fb_writeb(rect->index, fb2);
fb_writeb(attr, fb2 + 1);
fb2 += colstride;
}
fb += rowstride;
}
}
void svga_tileblit(struct fb_info *info, struct fb_tileblit *blit)
{
int dx, dy, i;
int colstride = 2 << (info->fix.type_aux & FB_AUX_TEXT_SVGA_MASK);
int rowstride = colstride * (info->var.xres_virtual / 8);
int attr = (0x0F & blit->bg) << 4 | (0x0F & blit->fg);
u8 __iomem *fb = (u8 __iomem *)info->screen_base;
fb += blit->sx * colstride + blit->sy * rowstride;
i=0;
for (dy=0; dy < blit->height; dy ++) {
u8 __iomem *fb2 = fb;
for (dx = 0; dx < blit->width; dx ++) {
fb_writeb(blit->indices[i], fb2);
fb_writeb(attr, fb2 + 1);
fb2 += colstride;
i ++;
if (i == blit->length) return;
}
fb += rowstride;
}
}
void svga_tilecursor(void __iomem *regbase, struct fb_info *info, struct fb_tilecursor *cursor)
{
u8 cs = 0x0d;
u8 ce = 0x0e;
u16 pos = cursor->sx + (info->var.xoffset / 8)
+ (cursor->sy + (info->var.yoffset / 16))
* (info->var.xres_virtual / 8);
if (! cursor -> mode)
return;
svga_wcrt_mask(regbase, 0x0A, 0x20, 0x20);
if (cursor -> shape == FB_TILE_CURSOR_NONE)
return;
switch (cursor -> shape) {
case FB_TILE_CURSOR_UNDERLINE:
cs = 0x0d;
break;
case FB_TILE_CURSOR_LOWER_THIRD:
cs = 0x09;
break;
case FB_TILE_CURSOR_LOWER_HALF:
cs = 0x07;
break;
case FB_TILE_CURSOR_TWO_THIRDS:
cs = 0x05;
break;
case FB_TILE_CURSOR_BLOCK:
cs = 0x01;
break;
}
vga_wcrt(regbase, 0x0E, pos >> 8);
vga_wcrt(regbase, 0x0F, pos & 0xFF);
vga_wcrt(regbase, 0x0B, ce);
vga_wcrt(regbase, 0x0A, cs);
}
int svga_get_tilemax(struct fb_info *info)
{
return 256;
}
void svga_get_caps(struct fb_info *info, struct fb_blit_caps *caps,
struct fb_var_screeninfo *var)
{
if (var->bits_per_pixel == 0) {
caps->x = 1 << (8 - 1);
caps->y = 1 << (16 - 1);
caps->len = 256;
} else {
caps->x = (var->bits_per_pixel == 4) ? 1 << (8 - 1) : ~(u32)0;
caps->y = ~(u32)0;
caps->len = ~(u32)0;
}
}
static inline u32 abs_diff(u32 a, u32 b)
{
return (a > b) ? (a - b) : (b - a);
}
int svga_compute_pll(const struct svga_pll *pll, u32 f_wanted, u16 *m, u16 *n, u16 *r, int node)
{
u16 am, an, ar;
u32 f_vco, f_current, delta_current, delta_best;
pr_debug("fb%d: ideal frequency: %d kHz\n", node, (unsigned int) f_wanted);
ar = pll->r_max;
f_vco = f_wanted << ar;
if ((f_vco >> ar) != f_wanted)
return -EINVAL;
while ((ar > pll->r_min) && (f_vco > pll->f_vco_max)) {
ar--;
f_vco = f_vco >> 1;
}
if ((f_vco < pll->f_vco_min) || (f_vco > pll->f_vco_max))
return -EINVAL;
delta_best = 0xFFFFFFFF;
*m = 0;
*n = 0;
*r = ar;
am = pll->m_min;
an = pll->n_min;
while ((am <= pll->m_max) && (an <= pll->n_max)) {
f_current = (pll->f_base * am) / an;
delta_current = abs_diff (f_current, f_vco);
if (delta_current < delta_best) {
delta_best = delta_current;
*m = am;
*n = an;
}
if (f_current <= f_vco) {
am ++;
} else {
an ++;
}
}
f_current = (pll->f_base * *m) / *n;
pr_debug("fb%d: found frequency: %d kHz (VCO %d kHz)\n", node, (int) (f_current >> ar), (int) f_current);
pr_debug("fb%d: m = %d n = %d r = %d\n", node, (unsigned int) *m, (unsigned int) *n, (unsigned int) *r);
return 0;
}
int svga_check_timings(const struct svga_timing_regs *tm, struct fb_var_screeninfo *var, int node)
{
u32 value;
var->xres = (var->xres+7)&~7;
var->left_margin = (var->left_margin+7)&~7;
var->right_margin = (var->right_margin+7)&~7;
var->hsync_len = (var->hsync_len+7)&~7;
value = var->xres + var->left_margin + var->right_margin + var->hsync_len;
if (((value / 8) - 5) >= svga_regset_size (tm->h_total_regs))
return -EINVAL;
value = var->xres;
if (((value / 8) - 1) >= svga_regset_size (tm->h_display_regs))
return -EINVAL;
if (((value / 8) - 1) >= svga_regset_size (tm->h_blank_start_regs))
return -EINVAL;
value = var->xres + var->right_margin;
if (((value / 8) - 1) >= svga_regset_size (tm->h_sync_start_regs))
return -EINVAL;
value = var->left_margin + var->right_margin + var->hsync_len;
if ((value == 0) || ((value / 8) >= svga_regset_size (tm->h_blank_end_regs)))
return -EINVAL;
value = var->hsync_len;
if ((value == 0) || ((value / 8) >= svga_regset_size (tm->h_sync_end_regs)))
return -EINVAL;
value = var->yres + var->upper_margin + var->lower_margin + var->vsync_len;
if ((value - 1) >= svga_regset_size(tm->v_total_regs))
return -EINVAL;
value = var->yres;
if ((value - 1) >= svga_regset_size(tm->v_display_regs))
return -EINVAL;
if ((value - 1) >= svga_regset_size(tm->v_blank_start_regs))
return -EINVAL;
value = var->yres + var->lower_margin;
if ((value - 1) >= svga_regset_size(tm->v_sync_start_regs))
return -EINVAL;
value = var->upper_margin + var->lower_margin + var->vsync_len;
if ((value == 0) || (value >= svga_regset_size (tm->v_blank_end_regs)))
return -EINVAL;
value = var->vsync_len;
if ((value == 0) || (value >= svga_regset_size (tm->v_sync_end_regs)))
return -EINVAL;
return 0;
}
void svga_set_timings(void __iomem *regbase, const struct svga_timing_regs *tm,
struct fb_var_screeninfo *var,
u32 hmul, u32 hdiv, u32 vmul, u32 vdiv, u32 hborder, int node)
{
u8 regval;
u32 value;
value = var->xres + var->left_margin + var->right_margin + var->hsync_len;
value = (value * hmul) / hdiv;
pr_debug("fb%d: horizontal total : %d\n", node, value);
svga_wcrt_multi(regbase, tm->h_total_regs, (value / 8) - 5);
value = var->xres;
value = (value * hmul) / hdiv;
pr_debug("fb%d: horizontal display : %d\n", node, value);
svga_wcrt_multi(regbase, tm->h_display_regs, (value / 8) - 1);
value = var->xres;
value = (value * hmul) / hdiv;
pr_debug("fb%d: horizontal blank start: %d\n", node, value);
svga_wcrt_multi(regbase, tm->h_blank_start_regs, (value / 8) - 1 + hborder);
value = var->xres + var->left_margin + var->right_margin + var->hsync_len;
value = (value * hmul) / hdiv;
pr_debug("fb%d: horizontal blank end : %d\n", node, value);
svga_wcrt_multi(regbase, tm->h_blank_end_regs, (value / 8) - 1 - hborder);
value = var->xres + var->right_margin;
value = (value * hmul) / hdiv;
pr_debug("fb%d: horizontal sync start : %d\n", node, value);
svga_wcrt_multi(regbase, tm->h_sync_start_regs, (value / 8));
value = var->xres + var->right_margin + var->hsync_len;
value = (value * hmul) / hdiv;
pr_debug("fb%d: horizontal sync end : %d\n", node, value);
svga_wcrt_multi(regbase, tm->h_sync_end_regs, (value / 8));
value = var->yres + var->upper_margin + var->lower_margin + var->vsync_len;
value = (value * vmul) / vdiv;
pr_debug("fb%d: vertical total : %d\n", node, value);
svga_wcrt_multi(regbase, tm->v_total_regs, value - 2);
value = var->yres;
value = (value * vmul) / vdiv;
pr_debug("fb%d: vertical display : %d\n", node, value);
svga_wcrt_multi(regbase, tm->v_display_regs, value - 1);
value = var->yres;
value = (value * vmul) / vdiv;
pr_debug("fb%d: vertical blank start : %d\n", node, value);
svga_wcrt_multi(regbase, tm->v_blank_start_regs, value);
value = var->yres + var->upper_margin + var->lower_margin + var->vsync_len;
value = (value * vmul) / vdiv;
pr_debug("fb%d: vertical blank end : %d\n", node, value);
svga_wcrt_multi(regbase, tm->v_blank_end_regs, value - 2);
value = var->yres + var->lower_margin;
value = (value * vmul) / vdiv;
pr_debug("fb%d: vertical sync start : %d\n", node, value);
svga_wcrt_multi(regbase, tm->v_sync_start_regs, value);
value = var->yres + var->lower_margin + var->vsync_len;
value = (value * vmul) / vdiv;
pr_debug("fb%d: vertical sync end : %d\n", node, value);
svga_wcrt_multi(regbase, tm->v_sync_end_regs, value);
regval = vga_r(regbase, VGA_MIS_R);
if (var->sync & FB_SYNC_HOR_HIGH_ACT) {
pr_debug("fb%d: positive horizontal sync\n", node);
regval = regval & ~0x80;
} else {
pr_debug("fb%d: negative horizontal sync\n", node);
regval = regval | 0x80;
}
if (var->sync & FB_SYNC_VERT_HIGH_ACT) {
pr_debug("fb%d: positive vertical sync\n", node);
regval = regval & ~0x40;
} else {
pr_debug("fb%d: negative vertical sync\n\n", node);
regval = regval | 0x40;
}
vga_w(regbase, VGA_MIS_W, regval);
}
static inline int match_format(const struct svga_fb_format *frm,
struct fb_var_screeninfo *var)
{
int i = 0;
int stored = -EINVAL;
while (frm->bits_per_pixel != SVGA_FORMAT_END_VAL)
{
if ((var->bits_per_pixel == frm->bits_per_pixel) &&
(var->red.length <= frm->red.length) &&
(var->green.length <= frm->green.length) &&
(var->blue.length <= frm->blue.length) &&
(var->transp.length <= frm->transp.length) &&
(var->nonstd == frm->nonstd))
return i;
if (var->bits_per_pixel == frm->bits_per_pixel)
stored = i;
i++;
frm++;
}
return stored;
}
int svga_match_format(const struct svga_fb_format *frm,
struct fb_var_screeninfo *var,
struct fb_fix_screeninfo *fix)
{
int i = match_format(frm, var);
if (i >= 0) {
var->bits_per_pixel = frm[i].bits_per_pixel;
var->red = frm[i].red;
var->green = frm[i].green;
var->blue = frm[i].blue;
var->transp = frm[i].transp;
var->nonstd = frm[i].nonstd;
if (fix != NULL) {
fix->type = frm[i].type;
fix->type_aux = frm[i].type_aux;
fix->visual = frm[i].visual;
fix->xpanstep = frm[i].xpanstep;
}
}
return i;
}
