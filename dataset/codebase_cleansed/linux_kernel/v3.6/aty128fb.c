static inline u32 _aty_ld_le32(volatile unsigned int regindex,
const struct aty128fb_par *par)
{
return readl (par->regbase + regindex);
}
static inline void _aty_st_le32(volatile unsigned int regindex, u32 val,
const struct aty128fb_par *par)
{
writel (val, par->regbase + regindex);
}
static inline u8 _aty_ld_8(unsigned int regindex,
const struct aty128fb_par *par)
{
return readb (par->regbase + regindex);
}
static inline void _aty_st_8(unsigned int regindex, u8 val,
const struct aty128fb_par *par)
{
writeb (val, par->regbase + regindex);
}
static u32 _aty_ld_pll(unsigned int pll_index,
const struct aty128fb_par *par)
{
aty_st_8(CLOCK_CNTL_INDEX, pll_index & 0x3F);
return aty_ld_le32(CLOCK_CNTL_DATA);
}
static void _aty_st_pll(unsigned int pll_index, u32 val,
const struct aty128fb_par *par)
{
aty_st_8(CLOCK_CNTL_INDEX, (pll_index & 0x3F) | PLL_WR_EN);
aty_st_le32(CLOCK_CNTL_DATA, val);
}
static int aty_pll_readupdate(const struct aty128fb_par *par)
{
return !(aty_ld_pll(PPLL_REF_DIV) & PPLL_ATOMIC_UPDATE_R);
}
static void aty_pll_wait_readupdate(const struct aty128fb_par *par)
{
unsigned long timeout = jiffies + HZ/100;
int reset = 1;
while (time_before(jiffies, timeout))
if (aty_pll_readupdate(par)) {
reset = 0;
break;
}
if (reset)
printk(KERN_DEBUG "aty128fb: PLL write timeout!\n");
}
static void aty_pll_writeupdate(const struct aty128fb_par *par)
{
aty_pll_wait_readupdate(par);
aty_st_pll(PPLL_REF_DIV,
aty_ld_pll(PPLL_REF_DIV) | PPLL_ATOMIC_UPDATE_W);
}
static int __devinit register_test(const struct aty128fb_par *par)
{
u32 val;
int flag = 0;
val = aty_ld_le32(BIOS_0_SCRATCH);
aty_st_le32(BIOS_0_SCRATCH, 0x55555555);
if (aty_ld_le32(BIOS_0_SCRATCH) == 0x55555555) {
aty_st_le32(BIOS_0_SCRATCH, 0xAAAAAAAA);
if (aty_ld_le32(BIOS_0_SCRATCH) == 0xAAAAAAAA)
flag = 1;
}
aty_st_le32(BIOS_0_SCRATCH, val);
return flag;
}
static void do_wait_for_fifo(u16 entries, struct aty128fb_par *par)
{
int i;
for (;;) {
for (i = 0; i < 2000000; i++) {
par->fifo_slots = aty_ld_le32(GUI_STAT) & 0x0fff;
if (par->fifo_slots >= entries)
return;
}
aty128_reset_engine(par);
}
}
static void wait_for_idle(struct aty128fb_par *par)
{
int i;
do_wait_for_fifo(64, par);
for (;;) {
for (i = 0; i < 2000000; i++) {
if (!(aty_ld_le32(GUI_STAT) & (1 << 31))) {
aty128_flush_pixel_cache(par);
par->blitter_may_be_busy = 0;
return;
}
}
aty128_reset_engine(par);
}
}
static void wait_for_fifo(u16 entries, struct aty128fb_par *par)
{
if (par->fifo_slots < entries)
do_wait_for_fifo(64, par);
par->fifo_slots -= entries;
}
static void aty128_flush_pixel_cache(const struct aty128fb_par *par)
{
int i;
u32 tmp;
tmp = aty_ld_le32(PC_NGUI_CTLSTAT);
tmp &= ~(0x00ff);
tmp |= 0x00ff;
aty_st_le32(PC_NGUI_CTLSTAT, tmp);
for (i = 0; i < 2000000; i++)
if (!(aty_ld_le32(PC_NGUI_CTLSTAT) & PC_BUSY))
break;
}
static void aty128_reset_engine(const struct aty128fb_par *par)
{
u32 gen_reset_cntl, clock_cntl_index, mclk_cntl;
aty128_flush_pixel_cache(par);
clock_cntl_index = aty_ld_le32(CLOCK_CNTL_INDEX);
mclk_cntl = aty_ld_pll(MCLK_CNTL);
aty_st_pll(MCLK_CNTL, mclk_cntl | 0x00030000);
gen_reset_cntl = aty_ld_le32(GEN_RESET_CNTL);
aty_st_le32(GEN_RESET_CNTL, gen_reset_cntl | SOFT_RESET_GUI);
aty_ld_le32(GEN_RESET_CNTL);
aty_st_le32(GEN_RESET_CNTL, gen_reset_cntl & ~(SOFT_RESET_GUI));
aty_ld_le32(GEN_RESET_CNTL);
aty_st_pll(MCLK_CNTL, mclk_cntl);
aty_st_le32(CLOCK_CNTL_INDEX, clock_cntl_index);
aty_st_le32(GEN_RESET_CNTL, gen_reset_cntl);
aty_st_le32(PM4_BUFFER_CNTL, PM4_BUFFER_CNTL_NONPM4);
DBG("engine reset");
}
static void aty128_init_engine(struct aty128fb_par *par)
{
u32 pitch_value;
wait_for_idle(par);
wait_for_fifo(1, par);
aty_st_le32(SCALE_3D_CNTL, 0x00000000);
aty128_reset_engine(par);
pitch_value = par->crtc.pitch;
if (par->crtc.bpp == 24) {
pitch_value = pitch_value * 3;
}
wait_for_fifo(4, par);
aty_st_le32(DEFAULT_OFFSET, 0x00000000);
aty_st_le32(DEFAULT_PITCH, pitch_value);
aty_st_le32(DEFAULT_SC_BOTTOM_RIGHT, (0x1FFF << 16) | 0x1FFF);
aty_st_le32(DP_GUI_MASTER_CNTL,
GMC_SRC_PITCH_OFFSET_DEFAULT |
GMC_DST_PITCH_OFFSET_DEFAULT |
GMC_SRC_CLIP_DEFAULT |
GMC_DST_CLIP_DEFAULT |
GMC_BRUSH_SOLIDCOLOR |
(depth_to_dst(par->crtc.depth) << 8) |
GMC_SRC_DSTCOLOR |
GMC_BYTE_ORDER_MSB_TO_LSB |
GMC_DP_CONVERSION_TEMP_6500 |
ROP3_PATCOPY |
GMC_DP_SRC_RECT |
GMC_3D_FCN_EN_CLR |
GMC_DST_CLR_CMP_FCN_CLEAR |
GMC_AUX_CLIP_CLEAR |
GMC_WRITE_MASK_SET);
wait_for_fifo(8, par);
aty_st_le32(DST_BRES_ERR, 0);
aty_st_le32(DST_BRES_INC, 0);
aty_st_le32(DST_BRES_DEC, 0);
aty_st_le32(DP_BRUSH_FRGD_CLR, 0xFFFFFFFF);
aty_st_le32(DP_BRUSH_BKGD_CLR, 0x00000000);
aty_st_le32(DP_SRC_FRGD_CLR, 0xFFFFFFFF);
aty_st_le32(DP_SRC_BKGD_CLR, 0x00000000);
aty_st_le32(DP_WRITE_MASK, 0xFFFFFFFF);
wait_for_idle(par);
}
static u32 depth_to_dst(u32 depth)
{
if (depth <= 8)
return DST_8BPP;
else if (depth <= 15)
return DST_15BPP;
else if (depth == 16)
return DST_16BPP;
else if (depth <= 24)
return DST_24BPP;
else if (depth <= 32)
return DST_32BPP;
return -EINVAL;
}
static void __iomem * __devinit aty128_map_ROM(const struct aty128fb_par *par,
struct pci_dev *dev)
{
u16 dptr;
u8 rom_type;
void __iomem *bios;
size_t rom_size;
unsigned int temp;
temp = aty_ld_le32(RAGE128_MPP_TB_CONFIG);
temp &= 0x00ffffffu;
temp |= 0x04 << 24;
aty_st_le32(RAGE128_MPP_TB_CONFIG, temp);
temp = aty_ld_le32(RAGE128_MPP_TB_CONFIG);
bios = pci_map_rom(dev, &rom_size);
if (!bios) {
printk(KERN_ERR "aty128fb: ROM failed to map\n");
return NULL;
}
if (BIOS_IN16(0) != 0xaa55) {
printk(KERN_DEBUG "aty128fb: Invalid ROM signature %x should "
" be 0xaa55\n", BIOS_IN16(0));
goto failed;
}
dptr = BIOS_IN16(0x18);
if (BIOS_IN32(dptr) != (('R' << 24) | ('I' << 16) | ('C' << 8) | 'P')) {
printk(KERN_WARNING "aty128fb: PCI DATA signature in ROM incorrect: %08x\n",
BIOS_IN32(dptr));
goto anyway;
}
rom_type = BIOS_IN8(dptr + 0x14);
switch(rom_type) {
case 0:
printk(KERN_INFO "aty128fb: Found Intel x86 BIOS ROM Image\n");
break;
case 1:
printk(KERN_INFO "aty128fb: Found Open Firmware ROM Image\n");
goto failed;
case 2:
printk(KERN_INFO "aty128fb: Found HP PA-RISC ROM Image\n");
goto failed;
default:
printk(KERN_INFO "aty128fb: Found unknown type %d ROM Image\n",
rom_type);
goto failed;
}
anyway:
return bios;
failed:
pci_unmap_rom(dev, bios);
return NULL;
}
static void __devinit aty128_get_pllinfo(struct aty128fb_par *par,
unsigned char __iomem *bios)
{
unsigned int bios_hdr;
unsigned int bios_pll;
bios_hdr = BIOS_IN16(0x48);
bios_pll = BIOS_IN16(bios_hdr + 0x30);
par->constants.ppll_max = BIOS_IN32(bios_pll + 0x16);
par->constants.ppll_min = BIOS_IN32(bios_pll + 0x12);
par->constants.xclk = BIOS_IN16(bios_pll + 0x08);
par->constants.ref_divider = BIOS_IN16(bios_pll + 0x10);
par->constants.ref_clk = BIOS_IN16(bios_pll + 0x0e);
DBG("ppll_max %d ppll_min %d xclk %d ref_divider %d ref clock %d\n",
par->constants.ppll_max, par->constants.ppll_min,
par->constants.xclk, par->constants.ref_divider,
par->constants.ref_clk);
}
static void __iomem * __devinit aty128_find_mem_vbios(struct aty128fb_par *par)
{
u32 segstart;
unsigned char __iomem *rom_base = NULL;
for (segstart=0x000c0000; segstart<0x000f0000; segstart+=0x00001000) {
rom_base = ioremap(segstart, 0x10000);
if (rom_base == NULL)
return NULL;
if (readb(rom_base) == 0x55 && readb(rom_base + 1) == 0xaa)
break;
iounmap(rom_base);
rom_base = NULL;
}
return rom_base;
}
static void __devinit aty128_timings(struct aty128fb_par *par)
{
#ifdef CONFIG_PPC_OF
u32 x_mpll_ref_fb_div;
u32 xclk_cntl;
u32 Nx, M;
unsigned PostDivSet[] = { 0, 1, 2, 4, 8, 3, 6, 12 };
#endif
if (!par->constants.ref_clk)
par->constants.ref_clk = 2950;
#ifdef CONFIG_PPC_OF
x_mpll_ref_fb_div = aty_ld_pll(X_MPLL_REF_FB_DIV);
xclk_cntl = aty_ld_pll(XCLK_CNTL) & 0x7;
Nx = (x_mpll_ref_fb_div & 0x00ff00) >> 8;
M = x_mpll_ref_fb_div & 0x0000ff;
par->constants.xclk = round_div((2 * Nx * par->constants.ref_clk),
(M * PostDivSet[xclk_cntl]));
par->constants.ref_divider =
aty_ld_pll(PPLL_REF_DIV) & PPLL_REF_DIV_MASK;
#endif
if (!par->constants.ref_divider) {
par->constants.ref_divider = 0x3b;
aty_st_pll(X_MPLL_REF_FB_DIV, 0x004c4c1e);
aty_pll_writeupdate(par);
}
aty_st_pll(PPLL_REF_DIV, par->constants.ref_divider);
aty_pll_writeupdate(par);
if (!par->constants.ppll_min)
par->constants.ppll_min = 12500;
if (!par->constants.ppll_max)
par->constants.ppll_max = 25000;
if (!par->constants.xclk)
par->constants.xclk = 0x1d4d;
par->constants.fifo_width = 128;
par->constants.fifo_depth = 32;
switch (aty_ld_le32(MEM_CNTL) & 0x3) {
case 0:
par->mem = &sdr_128;
break;
case 1:
par->mem = &sdr_sgram;
break;
case 2:
par->mem = &ddr_sgram;
break;
default:
par->mem = &sdr_sgram;
}
}
static void aty128_set_crtc(const struct aty128_crtc *crtc,
const struct aty128fb_par *par)
{
aty_st_le32(CRTC_GEN_CNTL, crtc->gen_cntl);
aty_st_le32(CRTC_H_TOTAL_DISP, crtc->h_total);
aty_st_le32(CRTC_H_SYNC_STRT_WID, crtc->h_sync_strt_wid);
aty_st_le32(CRTC_V_TOTAL_DISP, crtc->v_total);
aty_st_le32(CRTC_V_SYNC_STRT_WID, crtc->v_sync_strt_wid);
aty_st_le32(CRTC_PITCH, crtc->pitch);
aty_st_le32(CRTC_OFFSET, crtc->offset);
aty_st_le32(CRTC_OFFSET_CNTL, crtc->offset_cntl);
aty_st_pll(PPLL_CNTL, aty_ld_pll(PPLL_CNTL) & ~(0x00030000));
}
static int aty128_var_to_crtc(const struct fb_var_screeninfo *var,
struct aty128_crtc *crtc,
const struct aty128fb_par *par)
{
u32 xres, yres, vxres, vyres, xoffset, yoffset, bpp, dst;
u32 left, right, upper, lower, hslen, vslen, sync, vmode;
u32 h_total, h_disp, h_sync_strt, h_sync_wid, h_sync_pol;
u32 v_total, v_disp, v_sync_strt, v_sync_wid, v_sync_pol, c_sync;
u32 depth, bytpp;
u8 mode_bytpp[7] = { 0, 0, 1, 2, 2, 3, 4 };
xres = var->xres;
yres = var->yres;
vxres = var->xres_virtual;
vyres = var->yres_virtual;
xoffset = var->xoffset;
yoffset = var->yoffset;
bpp = var->bits_per_pixel;
left = var->left_margin;
right = var->right_margin;
upper = var->upper_margin;
lower = var->lower_margin;
hslen = var->hsync_len;
vslen = var->vsync_len;
sync = var->sync;
vmode = var->vmode;
if (bpp != 16)
depth = bpp;
else
depth = (var->green.length == 6) ? 16 : 15;
if ((vmode & FB_VMODE_MASK) != FB_VMODE_NONINTERLACED)
return -EINVAL;
xres = (xres + 7) & ~7;
xoffset = (xoffset + 7) & ~7;
if (vxres < xres + xoffset)
vxres = xres + xoffset;
if (vyres < yres + yoffset)
vyres = yres + yoffset;
dst = depth_to_dst(depth);
if (dst == -EINVAL) {
printk(KERN_ERR "aty128fb: Invalid depth or RGBA\n");
return -EINVAL;
}
bytpp = mode_bytpp[dst];
if ((u32)(vxres * vyres * bytpp) > par->vram_size) {
printk(KERN_ERR "aty128fb: Not enough memory for mode\n");
return -EINVAL;
}
h_disp = (xres >> 3) - 1;
h_total = (((xres + right + hslen + left) >> 3) - 1) & 0xFFFFL;
v_disp = yres - 1;
v_total = (yres + upper + vslen + lower - 1) & 0xFFFFL;
if (((h_total >> 3) - 1) > 0x1ff || (v_total - 1) > 0x7FF) {
printk(KERN_ERR "aty128fb: invalid width ranges\n");
return -EINVAL;
}
h_sync_wid = (hslen + 7) >> 3;
if (h_sync_wid == 0)
h_sync_wid = 1;
else if (h_sync_wid > 0x3f)
h_sync_wid = 0x3f;
h_sync_strt = (h_disp << 3) + right;
v_sync_wid = vslen;
if (v_sync_wid == 0)
v_sync_wid = 1;
else if (v_sync_wid > 0x1f)
v_sync_wid = 0x1f;
v_sync_strt = v_disp + lower;
h_sync_pol = sync & FB_SYNC_HOR_HIGH_ACT ? 0 : 1;
v_sync_pol = sync & FB_SYNC_VERT_HIGH_ACT ? 0 : 1;
c_sync = sync & FB_SYNC_COMP_HIGH_ACT ? (1 << 4) : 0;
crtc->gen_cntl = 0x3000000L | c_sync | (dst << 8);
crtc->h_total = h_total | (h_disp << 16);
crtc->v_total = v_total | (v_disp << 16);
crtc->h_sync_strt_wid = h_sync_strt | (h_sync_wid << 16) |
(h_sync_pol << 23);
crtc->v_sync_strt_wid = v_sync_strt | (v_sync_wid << 16) |
(v_sync_pol << 23);
crtc->pitch = vxres >> 3;
crtc->offset = 0;
if ((var->activate & FB_ACTIVATE_MASK) == FB_ACTIVATE_NOW)
crtc->offset_cntl = 0x00010000;
else
crtc->offset_cntl = 0;
crtc->vxres = vxres;
crtc->vyres = vyres;
crtc->xoffset = xoffset;
crtc->yoffset = yoffset;
crtc->depth = depth;
crtc->bpp = bpp;
return 0;
}
static int aty128_pix_width_to_var(int pix_width, struct fb_var_screeninfo *var)
{
var->red.msb_right = 0;
var->green.msb_right = 0;
var->blue.offset = 0;
var->blue.msb_right = 0;
var->transp.offset = 0;
var->transp.length = 0;
var->transp.msb_right = 0;
switch (pix_width) {
case CRTC_PIX_WIDTH_8BPP:
var->bits_per_pixel = 8;
var->red.offset = 0;
var->red.length = 8;
var->green.offset = 0;
var->green.length = 8;
var->blue.length = 8;
break;
case CRTC_PIX_WIDTH_15BPP:
var->bits_per_pixel = 16;
var->red.offset = 10;
var->red.length = 5;
var->green.offset = 5;
var->green.length = 5;
var->blue.length = 5;
break;
case CRTC_PIX_WIDTH_16BPP:
var->bits_per_pixel = 16;
var->red.offset = 11;
var->red.length = 5;
var->green.offset = 5;
var->green.length = 6;
var->blue.length = 5;
break;
case CRTC_PIX_WIDTH_24BPP:
var->bits_per_pixel = 24;
var->red.offset = 16;
var->red.length = 8;
var->green.offset = 8;
var->green.length = 8;
var->blue.length = 8;
break;
case CRTC_PIX_WIDTH_32BPP:
var->bits_per_pixel = 32;
var->red.offset = 16;
var->red.length = 8;
var->green.offset = 8;
var->green.length = 8;
var->blue.length = 8;
var->transp.offset = 24;
var->transp.length = 8;
break;
default:
printk(KERN_ERR "aty128fb: Invalid pixel width\n");
return -EINVAL;
}
return 0;
}
static int aty128_crtc_to_var(const struct aty128_crtc *crtc,
struct fb_var_screeninfo *var)
{
u32 xres, yres, left, right, upper, lower, hslen, vslen, sync;
u32 h_total, h_disp, h_sync_strt, h_sync_dly, h_sync_wid, h_sync_pol;
u32 v_total, v_disp, v_sync_strt, v_sync_wid, v_sync_pol, c_sync;
u32 pix_width;
h_total = crtc->h_total & 0x1ff;
h_disp = (crtc->h_total >> 16) & 0xff;
h_sync_strt = (crtc->h_sync_strt_wid >> 3) & 0x1ff;
h_sync_dly = crtc->h_sync_strt_wid & 0x7;
h_sync_wid = (crtc->h_sync_strt_wid >> 16) & 0x3f;
h_sync_pol = (crtc->h_sync_strt_wid >> 23) & 0x1;
v_total = crtc->v_total & 0x7ff;
v_disp = (crtc->v_total >> 16) & 0x7ff;
v_sync_strt = crtc->v_sync_strt_wid & 0x7ff;
v_sync_wid = (crtc->v_sync_strt_wid >> 16) & 0x1f;
v_sync_pol = (crtc->v_sync_strt_wid >> 23) & 0x1;
c_sync = crtc->gen_cntl & CRTC_CSYNC_EN ? 1 : 0;
pix_width = crtc->gen_cntl & CRTC_PIX_WIDTH_MASK;
xres = (h_disp + 1) << 3;
yres = v_disp + 1;
left = ((h_total - h_sync_strt - h_sync_wid) << 3) - h_sync_dly;
right = ((h_sync_strt - h_disp) << 3) + h_sync_dly;
hslen = h_sync_wid << 3;
upper = v_total - v_sync_strt - v_sync_wid;
lower = v_sync_strt - v_disp;
vslen = v_sync_wid;
sync = (h_sync_pol ? 0 : FB_SYNC_HOR_HIGH_ACT) |
(v_sync_pol ? 0 : FB_SYNC_VERT_HIGH_ACT) |
(c_sync ? FB_SYNC_COMP_HIGH_ACT : 0);
aty128_pix_width_to_var(pix_width, var);
var->xres = xres;
var->yres = yres;
var->xres_virtual = crtc->vxres;
var->yres_virtual = crtc->vyres;
var->xoffset = crtc->xoffset;
var->yoffset = crtc->yoffset;
var->left_margin = left;
var->right_margin = right;
var->upper_margin = upper;
var->lower_margin = lower;
var->hsync_len = hslen;
var->vsync_len = vslen;
var->sync = sync;
var->vmode = FB_VMODE_NONINTERLACED;
return 0;
}
static void aty128_set_crt_enable(struct aty128fb_par *par, int on)
{
if (on) {
aty_st_le32(CRTC_EXT_CNTL, aty_ld_le32(CRTC_EXT_CNTL) |
CRT_CRTC_ON);
aty_st_le32(DAC_CNTL, (aty_ld_le32(DAC_CNTL) |
DAC_PALETTE2_SNOOP_EN));
} else
aty_st_le32(CRTC_EXT_CNTL, aty_ld_le32(CRTC_EXT_CNTL) &
~CRT_CRTC_ON);
}
static void aty128_set_lcd_enable(struct aty128fb_par *par, int on)
{
u32 reg;
#ifdef CONFIG_FB_ATY128_BACKLIGHT
struct fb_info *info = pci_get_drvdata(par->pdev);
#endif
if (on) {
reg = aty_ld_le32(LVDS_GEN_CNTL);
reg |= LVDS_ON | LVDS_EN | LVDS_BLON | LVDS_DIGION;
reg &= ~LVDS_DISPLAY_DIS;
aty_st_le32(LVDS_GEN_CNTL, reg);
#ifdef CONFIG_FB_ATY128_BACKLIGHT
aty128_bl_set_power(info, FB_BLANK_UNBLANK);
#endif
} else {
#ifdef CONFIG_FB_ATY128_BACKLIGHT
aty128_bl_set_power(info, FB_BLANK_POWERDOWN);
#endif
reg = aty_ld_le32(LVDS_GEN_CNTL);
reg |= LVDS_DISPLAY_DIS;
aty_st_le32(LVDS_GEN_CNTL, reg);
mdelay(100);
reg &= ~(LVDS_ON );
aty_st_le32(LVDS_GEN_CNTL, reg);
}
}
static void aty128_set_pll(struct aty128_pll *pll,
const struct aty128fb_par *par)
{
u32 div3;
unsigned char post_conv[] =
{ 2, 0, 1, 4, 2, 2, 6, 2, 3, 2, 2, 2, 7 };
aty_st_le32(CLOCK_CNTL_INDEX, aty_ld_le32(CLOCK_CNTL_INDEX) | (3 << 8));
aty_st_pll(PPLL_CNTL,
aty_ld_pll(PPLL_CNTL) | PPLL_RESET | PPLL_ATOMIC_UPDATE_EN);
aty_pll_wait_readupdate(par);
aty_st_pll(PPLL_REF_DIV, par->constants.ref_divider & 0x3ff);
aty_pll_writeupdate(par);
div3 = aty_ld_pll(PPLL_DIV_3);
div3 &= ~PPLL_FB3_DIV_MASK;
div3 |= pll->feedback_divider;
div3 &= ~PPLL_POST3_DIV_MASK;
div3 |= post_conv[pll->post_divider] << 16;
aty_pll_wait_readupdate(par);
aty_st_pll(PPLL_DIV_3, div3);
aty_pll_writeupdate(par);
aty_pll_wait_readupdate(par);
aty_st_pll(HTOTAL_CNTL, 0);
aty_pll_writeupdate(par);
aty_st_pll(PPLL_CNTL, aty_ld_pll(PPLL_CNTL) & ~PPLL_RESET);
}
static int aty128_var_to_pll(u32 period_in_ps, struct aty128_pll *pll,
const struct aty128fb_par *par)
{
const struct aty128_constants c = par->constants;
unsigned char post_dividers[] = {1,2,4,8,3,6,12};
u32 output_freq;
u32 vclk;
int i = 0;
u32 n, d;
vclk = 100000000 / period_in_ps;
if (vclk > c.ppll_max)
vclk = c.ppll_max;
if (vclk * 12 < c.ppll_min)
vclk = c.ppll_min/12;
for (i = 0; i < ARRAY_SIZE(post_dividers); i++) {
output_freq = post_dividers[i] * vclk;
if (output_freq >= c.ppll_min && output_freq <= c.ppll_max) {
pll->post_divider = post_dividers[i];
break;
}
}
if (i == ARRAY_SIZE(post_dividers))
return -EINVAL;
n = c.ref_divider * output_freq;
d = c.ref_clk;
pll->feedback_divider = round_div(n, d);
pll->vclk = vclk;
DBG("post %d feedback %d vlck %d output %d ref_divider %d "
"vclk_per: %d\n", pll->post_divider,
pll->feedback_divider, vclk, output_freq,
c.ref_divider, period_in_ps);
return 0;
}
static int aty128_pll_to_var(const struct aty128_pll *pll,
struct fb_var_screeninfo *var)
{
var->pixclock = 100000000 / pll->vclk;
return 0;
}
static void aty128_set_fifo(const struct aty128_ddafifo *dsp,
const struct aty128fb_par *par)
{
aty_st_le32(DDA_CONFIG, dsp->dda_config);
aty_st_le32(DDA_ON_OFF, dsp->dda_on_off);
}
static int aty128_ddafifo(struct aty128_ddafifo *dsp,
const struct aty128_pll *pll,
u32 depth,
const struct aty128fb_par *par)
{
const struct aty128_meminfo *m = par->mem;
u32 xclk = par->constants.xclk;
u32 fifo_width = par->constants.fifo_width;
u32 fifo_depth = par->constants.fifo_depth;
s32 x, b, p, ron, roff;
u32 n, d, bpp;
bpp = (depth+7) & ~7;
n = xclk * fifo_width;
d = pll->vclk * bpp;
x = round_div(n, d);
ron = 4 * m->MB +
3 * ((m->Trcd - 2 > 0) ? m->Trcd - 2 : 0) +
2 * m->Trp +
m->Twr +
m->CL +
m->Tr2w +
x;
DBG("x %x\n", x);
b = 0;
while (x) {
x >>= 1;
b++;
}
p = b + 1;
ron <<= (11 - p);
n <<= (11 - p);
x = round_div(n, d);
roff = x * (fifo_depth - 4);
if ((ron + m->Rloop) >= roff) {
printk(KERN_ERR "aty128fb: Mode out of range!\n");
return -EINVAL;
}
DBG("p: %x rloop: %x x: %x ron: %x roff: %x\n",
p, m->Rloop, x, ron, roff);
dsp->dda_config = p << 16 | m->Rloop << 20 | x;
dsp->dda_on_off = ron << 16 | roff;
return 0;
}
static int aty128fb_set_par(struct fb_info *info)
{
struct aty128fb_par *par = info->par;
u32 config;
int err;
if ((err = aty128_decode_var(&info->var, par)) != 0)
return err;
if (par->blitter_may_be_busy)
wait_for_idle(par);
aty_st_le32(OVR_CLR, 0);
aty_st_le32(OVR_WID_LEFT_RIGHT, 0);
aty_st_le32(OVR_WID_TOP_BOTTOM, 0);
aty_st_le32(OV0_SCALE_CNTL, 0);
aty_st_le32(MPP_TB_CONFIG, 0);
aty_st_le32(MPP_GP_CONFIG, 0);
aty_st_le32(SUBPIC_CNTL, 0);
aty_st_le32(VIPH_CONTROL, 0);
aty_st_le32(I2C_CNTL_1, 0);
aty_st_le32(GEN_INT_CNTL, 0);
aty_st_le32(CAP0_TRIG_CNTL, 0);
aty_st_le32(CAP1_TRIG_CNTL, 0);
aty_st_8(CRTC_EXT_CNTL + 1, 4);
aty128_set_crtc(&par->crtc, par);
aty128_set_pll(&par->pll, par);
aty128_set_fifo(&par->fifo_reg, par);
config = aty_ld_le32(CNFG_CNTL) & ~3;
#if defined(__BIG_ENDIAN)
if (par->crtc.bpp == 32)
config |= 2;
else if (par->crtc.bpp == 16)
config |= 1;
#endif
aty_st_le32(CNFG_CNTL, config);
aty_st_8(CRTC_EXT_CNTL + 1, 0);
info->fix.line_length = (par->crtc.vxres * par->crtc.bpp) >> 3;
info->fix.visual = par->crtc.bpp == 8 ? FB_VISUAL_PSEUDOCOLOR
: FB_VISUAL_DIRECTCOLOR;
if (par->chip_gen == rage_M3) {
aty128_set_crt_enable(par, par->crt_on);
aty128_set_lcd_enable(par, par->lcd_on);
}
if (par->accel_flags & FB_ACCELF_TEXT)
aty128_init_engine(par);
#ifdef CONFIG_BOOTX_TEXT
btext_update_display(info->fix.smem_start,
(((par->crtc.h_total>>16) & 0xff)+1)*8,
((par->crtc.v_total>>16) & 0x7ff)+1,
par->crtc.bpp,
par->crtc.vxres*par->crtc.bpp/8);
#endif
return 0;
}
static int aty128_decode_var(struct fb_var_screeninfo *var,
struct aty128fb_par *par)
{
int err;
struct aty128_crtc crtc;
struct aty128_pll pll;
struct aty128_ddafifo fifo_reg;
if ((err = aty128_var_to_crtc(var, &crtc, par)))
return err;
if ((err = aty128_var_to_pll(var->pixclock, &pll, par)))
return err;
if ((err = aty128_ddafifo(&fifo_reg, &pll, crtc.depth, par)))
return err;
par->crtc = crtc;
par->pll = pll;
par->fifo_reg = fifo_reg;
par->accel_flags = var->accel_flags;
return 0;
}
static int aty128_encode_var(struct fb_var_screeninfo *var,
const struct aty128fb_par *par)
{
int err;
if ((err = aty128_crtc_to_var(&par->crtc, var)))
return err;
if ((err = aty128_pll_to_var(&par->pll, var)))
return err;
var->nonstd = 0;
var->activate = 0;
var->height = -1;
var->width = -1;
var->accel_flags = par->accel_flags;
return 0;
}
static int aty128fb_check_var(struct fb_var_screeninfo *var,
struct fb_info *info)
{
struct aty128fb_par par;
int err;
par = *(struct aty128fb_par *)info->par;
if ((err = aty128_decode_var(var, &par)) != 0)
return err;
aty128_encode_var(var, &par);
return 0;
}
static int aty128fb_pan_display(struct fb_var_screeninfo *var,
struct fb_info *fb)
{
struct aty128fb_par *par = fb->par;
u32 xoffset, yoffset;
u32 offset;
u32 xres, yres;
xres = (((par->crtc.h_total >> 16) & 0xff) + 1) << 3;
yres = ((par->crtc.v_total >> 16) & 0x7ff) + 1;
xoffset = (var->xoffset +7) & ~7;
yoffset = var->yoffset;
if (xoffset+xres > par->crtc.vxres || yoffset+yres > par->crtc.vyres)
return -EINVAL;
par->crtc.xoffset = xoffset;
par->crtc.yoffset = yoffset;
offset = ((yoffset * par->crtc.vxres + xoffset) * (par->crtc.bpp >> 3))
& ~7;
if (par->crtc.bpp == 24)
offset += 8 * (offset % 3);
aty_st_le32(CRTC_OFFSET, offset);
return 0;
}
static void aty128_st_pal(u_int regno, u_int red, u_int green, u_int blue,
struct aty128fb_par *par)
{
if (par->chip_gen == rage_M3) {
#if 0
aty_st_le32(DAC_CNTL, aty_ld_le32(DAC_CNTL) |
DAC_PALETTE_ACCESS_CNTL);
aty_st_8(PALETTE_INDEX, regno);
aty_st_le32(PALETTE_DATA, (red<<16)|(green<<8)|blue);
#endif
aty_st_le32(DAC_CNTL, aty_ld_le32(DAC_CNTL) &
~DAC_PALETTE_ACCESS_CNTL);
}
aty_st_8(PALETTE_INDEX, regno);
aty_st_le32(PALETTE_DATA, (red<<16)|(green<<8)|blue);
}
static int aty128fb_sync(struct fb_info *info)
{
struct aty128fb_par *par = info->par;
if (par->blitter_may_be_busy)
wait_for_idle(par);
return 0;
}
static int __devinit aty128fb_setup(char *options)
{
char *this_opt;
if (!options || !*options)
return 0;
while ((this_opt = strsep(&options, ",")) != NULL) {
if (!strncmp(this_opt, "lcd:", 4)) {
default_lcd_on = simple_strtoul(this_opt+4, NULL, 0);
continue;
} else if (!strncmp(this_opt, "crt:", 4)) {
default_crt_on = simple_strtoul(this_opt+4, NULL, 0);
continue;
} else if (!strncmp(this_opt, "backlight:", 10)) {
backlight = simple_strtoul(this_opt+10, NULL, 0);
continue;
}
#ifdef CONFIG_MTRR
if(!strncmp(this_opt, "nomtrr", 6)) {
mtrr = 0;
continue;
}
#endif
#ifdef CONFIG_PPC_PMAC
if (!strncmp(this_opt, "vmode:", 6)) {
unsigned int vmode = simple_strtoul(this_opt+6, NULL, 0);
if (vmode > 0 && vmode <= VMODE_MAX)
default_vmode = vmode;
continue;
} else if (!strncmp(this_opt, "cmode:", 6)) {
unsigned int cmode = simple_strtoul(this_opt+6, NULL, 0);
switch (cmode) {
case 0:
case 8:
default_cmode = CMODE_8;
break;
case 15:
case 16:
default_cmode = CMODE_16;
break;
case 24:
case 32:
default_cmode = CMODE_32;
break;
}
continue;
}
#endif
mode_option = this_opt;
}
return 0;
}
static int aty128_bl_get_level_brightness(struct aty128fb_par *par,
int level)
{
struct fb_info *info = pci_get_drvdata(par->pdev);
int atylevel;
atylevel = MAX_LEVEL -
(info->bl_curve[level] * FB_BACKLIGHT_MAX / MAX_LEVEL);
if (atylevel < 0)
atylevel = 0;
else if (atylevel > MAX_LEVEL)
atylevel = MAX_LEVEL;
return atylevel;
}
static int aty128_bl_update_status(struct backlight_device *bd)
{
struct aty128fb_par *par = bl_get_data(bd);
unsigned int reg = aty_ld_le32(LVDS_GEN_CNTL);
int level;
if (bd->props.power != FB_BLANK_UNBLANK ||
bd->props.fb_blank != FB_BLANK_UNBLANK ||
!par->lcd_on)
level = 0;
else
level = bd->props.brightness;
reg |= LVDS_BL_MOD_EN | LVDS_BLON;
if (level > 0) {
reg |= LVDS_DIGION;
if (!(reg & LVDS_ON)) {
reg &= ~LVDS_BLON;
aty_st_le32(LVDS_GEN_CNTL, reg);
aty_ld_le32(LVDS_GEN_CNTL);
mdelay(10);
reg |= LVDS_BLON;
aty_st_le32(LVDS_GEN_CNTL, reg);
}
reg &= ~LVDS_BL_MOD_LEVEL_MASK;
reg |= (aty128_bl_get_level_brightness(par, level) <<
LVDS_BL_MOD_LEVEL_SHIFT);
#ifdef BACKLIGHT_LVDS_OFF
reg |= LVDS_ON | LVDS_EN;
reg &= ~LVDS_DISPLAY_DIS;
#endif
aty_st_le32(LVDS_GEN_CNTL, reg);
#ifdef BACKLIGHT_DAC_OFF
aty_st_le32(DAC_CNTL, aty_ld_le32(DAC_CNTL) & (~DAC_PDWN));
#endif
} else {
reg &= ~LVDS_BL_MOD_LEVEL_MASK;
reg |= (aty128_bl_get_level_brightness(par, 0) <<
LVDS_BL_MOD_LEVEL_SHIFT);
#ifdef BACKLIGHT_LVDS_OFF
reg |= LVDS_DISPLAY_DIS;
aty_st_le32(LVDS_GEN_CNTL, reg);
aty_ld_le32(LVDS_GEN_CNTL);
udelay(10);
reg &= ~(LVDS_ON | LVDS_EN | LVDS_BLON | LVDS_DIGION);
#endif
aty_st_le32(LVDS_GEN_CNTL, reg);
#ifdef BACKLIGHT_DAC_OFF
aty_st_le32(DAC_CNTL, aty_ld_le32(DAC_CNTL) | DAC_PDWN);
#endif
}
return 0;
}
static int aty128_bl_get_brightness(struct backlight_device *bd)
{
return bd->props.brightness;
}
static void aty128_bl_set_power(struct fb_info *info, int power)
{
if (info->bl_dev) {
info->bl_dev->props.power = power;
backlight_update_status(info->bl_dev);
}
}
static void aty128_bl_init(struct aty128fb_par *par)
{
struct backlight_properties props;
struct fb_info *info = pci_get_drvdata(par->pdev);
struct backlight_device *bd;
char name[12];
if (par->chip_gen != rage_M3)
return;
#ifdef CONFIG_PMAC_BACKLIGHT
if (!pmac_has_backlight_type("ati"))
return;
#endif
snprintf(name, sizeof(name), "aty128bl%d", info->node);
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_RAW;
props.max_brightness = FB_BACKLIGHT_LEVELS - 1;
bd = backlight_device_register(name, info->dev, par, &aty128_bl_data,
&props);
if (IS_ERR(bd)) {
info->bl_dev = NULL;
printk(KERN_WARNING "aty128: Backlight registration failed\n");
goto error;
}
info->bl_dev = bd;
fb_bl_default_curve(info, 0,
63 * FB_BACKLIGHT_MAX / MAX_LEVEL,
219 * FB_BACKLIGHT_MAX / MAX_LEVEL);
bd->props.brightness = bd->props.max_brightness;
bd->props.power = FB_BLANK_UNBLANK;
backlight_update_status(bd);
printk("aty128: Backlight initialized (%s)\n", name);
return;
error:
return;
}
static void aty128_bl_exit(struct backlight_device *bd)
{
backlight_device_unregister(bd);
printk("aty128: Backlight unloaded\n");
}
static void aty128_early_resume(void *data)
{
struct aty128fb_par *par = data;
if (!console_trylock())
return;
pci_restore_state(par->pdev);
aty128_do_resume(par->pdev);
console_unlock();
}
static int __devinit aty128_init(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct fb_info *info = pci_get_drvdata(pdev);
struct aty128fb_par *par = info->par;
struct fb_var_screeninfo var;
char video_card[50];
u8 chip_rev;
u32 dac;
chip_rev = (aty_ld_le32(CNFG_CNTL) >> 16) & 0x1F;
strcpy(video_card, "Rage128 XX ");
video_card[8] = ent->device >> 8;
video_card[9] = ent->device & 0xFF;
if (ent->driver_data < ARRAY_SIZE(r128_family))
strlcat(video_card, r128_family[ent->driver_data],
sizeof(video_card));
printk(KERN_INFO "aty128fb: %s [chip rev 0x%x] ", video_card, chip_rev);
if (par->vram_size % (1024 * 1024) == 0)
printk("%dM %s\n", par->vram_size / (1024*1024), par->mem->name);
else
printk("%dk %s\n", par->vram_size / 1024, par->mem->name);
par->chip_gen = ent->driver_data;
info->fbops = &aty128fb_ops;
info->flags = FBINFO_FLAG_DEFAULT;
par->lcd_on = default_lcd_on;
par->crt_on = default_crt_on;
var = default_var;
#ifdef CONFIG_PPC_PMAC
if (machine_is(powermac)) {
if (par->chip_gen == rage_M3) {
pmac_call_feature(PMAC_FTR_DEVICE_CAN_WAKE, NULL, 0, 1);
#if 0
pmac_set_early_video_resume(aty128_early_resume, par);
#endif
}
if (mode_option) {
if (!mac_find_mode(&var, info, mode_option, 8))
var = default_var;
} else {
if (default_vmode <= 0 || default_vmode > VMODE_MAX)
default_vmode = VMODE_1024_768_60;
if (of_machine_is_compatible("PowerMac2,1") ||
of_machine_is_compatible("PowerMac2,2") ||
of_machine_is_compatible("PowerMac4,1"))
default_vmode = VMODE_1024_768_75;
if (of_machine_is_compatible("PowerBook2,2"))
default_vmode = VMODE_800_600_60;
if (of_machine_is_compatible("PowerBook3,1") ||
of_machine_is_compatible("PowerBook4,1"))
default_vmode = VMODE_1024_768_60;
if (of_machine_is_compatible("PowerBook3,2"))
default_vmode = VMODE_1152_768_60;
if (default_cmode > 16)
default_cmode = CMODE_32;
else if (default_cmode > 8)
default_cmode = CMODE_16;
else
default_cmode = CMODE_8;
if (mac_vmode_to_var(default_vmode, default_cmode, &var))
var = default_var;
}
} else
#endif
{
if (mode_option)
if (fb_find_mode(&var, info, mode_option, NULL,
0, &defaultmode, 8) == 0)
var = default_var;
}
var.accel_flags &= ~FB_ACCELF_TEXT;
if (aty128fb_check_var(&var, info)) {
printk(KERN_ERR "aty128fb: Cannot set default mode.\n");
return 0;
}
dac = aty_ld_le32(DAC_CNTL);
dac |= (DAC_8BIT_EN | DAC_RANGE_CNTL);
dac |= DAC_MASK;
if (par->chip_gen == rage_M3)
dac |= DAC_PALETTE2_SNOOP_EN;
aty_st_le32(DAC_CNTL, dac);
aty_st_le32(BUS_CNTL, aty_ld_le32(BUS_CNTL) | BUS_MASTER_DIS);
info->var = var;
fb_alloc_cmap(&info->cmap, 256, 0);
var.activate = FB_ACTIVATE_NOW;
aty128_init_engine(par);
par->pm_reg = pci_find_capability(pdev, PCI_CAP_ID_PM);
par->pdev = pdev;
par->asleep = 0;
par->lock_blank = 0;
#ifdef CONFIG_FB_ATY128_BACKLIGHT
if (backlight)
aty128_bl_init(par);
#endif
if (register_framebuffer(info) < 0)
return 0;
printk(KERN_INFO "fb%d: %s frame buffer device on %s\n",
info->node, info->fix.id, video_card);
return 1;
}
static int __devinit aty128_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
unsigned long fb_addr, reg_addr;
struct aty128fb_par *par;
struct fb_info *info;
int err;
#ifndef __sparc__
void __iomem *bios = NULL;
#endif
if ((err = pci_enable_device(pdev))) {
printk(KERN_ERR "aty128fb: Cannot enable PCI device: %d\n",
err);
return -ENODEV;
}
fb_addr = pci_resource_start(pdev, 0);
if (!request_mem_region(fb_addr, pci_resource_len(pdev, 0),
"aty128fb FB")) {
printk(KERN_ERR "aty128fb: cannot reserve frame "
"buffer memory\n");
return -ENODEV;
}
reg_addr = pci_resource_start(pdev, 2);
if (!request_mem_region(reg_addr, pci_resource_len(pdev, 2),
"aty128fb MMIO")) {
printk(KERN_ERR "aty128fb: cannot reserve MMIO region\n");
goto err_free_fb;
}
info = framebuffer_alloc(sizeof(struct aty128fb_par), &pdev->dev);
if (info == NULL) {
printk(KERN_ERR "aty128fb: can't alloc fb_info_aty128\n");
goto err_free_mmio;
}
par = info->par;
info->pseudo_palette = par->pseudo_palette;
info->fix.mmio_start = reg_addr;
par->regbase = pci_ioremap_bar(pdev, 2);
if (!par->regbase)
goto err_free_info;
par->vram_size = aty_ld_le32(CNFG_MEMSIZE) & 0x03FFFFFF;
info->screen_base = ioremap(fb_addr, par->vram_size);
if (!info->screen_base)
goto err_unmap_out;
info->fix = aty128fb_fix;
info->fix.smem_start = fb_addr;
info->fix.smem_len = par->vram_size;
info->fix.mmio_start = reg_addr;
if (!register_test(par)) {
printk(KERN_ERR "aty128fb: Can't write to video register!\n");
goto err_out;
}
#ifndef __sparc__
bios = aty128_map_ROM(par, pdev);
#ifdef CONFIG_X86
if (bios == NULL)
bios = aty128_find_mem_vbios(par);
#endif
if (bios == NULL)
printk(KERN_INFO "aty128fb: BIOS not located, guessing timings.\n");
else {
printk(KERN_INFO "aty128fb: Rage128 BIOS located\n");
aty128_get_pllinfo(par, bios);
pci_unmap_rom(pdev, bios);
}
#endif
aty128_timings(par);
pci_set_drvdata(pdev, info);
if (!aty128_init(pdev, ent))
goto err_out;
#ifdef CONFIG_MTRR
if (mtrr) {
par->mtrr.vram = mtrr_add(info->fix.smem_start,
par->vram_size, MTRR_TYPE_WRCOMB, 1);
par->mtrr.vram_valid = 1;
printk(KERN_INFO "aty128fb: Rage128 MTRR set to ON\n");
}
#endif
return 0;
err_out:
iounmap(info->screen_base);
err_unmap_out:
iounmap(par->regbase);
err_free_info:
framebuffer_release(info);
err_free_mmio:
release_mem_region(pci_resource_start(pdev, 2),
pci_resource_len(pdev, 2));
err_free_fb:
release_mem_region(pci_resource_start(pdev, 0),
pci_resource_len(pdev, 0));
return -ENODEV;
}
static void __devexit aty128_remove(struct pci_dev *pdev)
{
struct fb_info *info = pci_get_drvdata(pdev);
struct aty128fb_par *par;
if (!info)
return;
par = info->par;
unregister_framebuffer(info);
#ifdef CONFIG_FB_ATY128_BACKLIGHT
aty128_bl_exit(info->bl_dev);
#endif
#ifdef CONFIG_MTRR
if (par->mtrr.vram_valid)
mtrr_del(par->mtrr.vram, info->fix.smem_start,
par->vram_size);
#endif
iounmap(par->regbase);
iounmap(info->screen_base);
release_mem_region(pci_resource_start(pdev, 0),
pci_resource_len(pdev, 0));
release_mem_region(pci_resource_start(pdev, 2),
pci_resource_len(pdev, 2));
framebuffer_release(info);
}
static int aty128fb_blank(int blank, struct fb_info *fb)
{
struct aty128fb_par *par = fb->par;
u8 state;
if (par->lock_blank || par->asleep)
return 0;
switch (blank) {
case FB_BLANK_NORMAL:
state = 4;
break;
case FB_BLANK_VSYNC_SUSPEND:
state = 6;
break;
case FB_BLANK_HSYNC_SUSPEND:
state = 5;
break;
case FB_BLANK_POWERDOWN:
state = 7;
break;
case FB_BLANK_UNBLANK:
default:
state = 0;
break;
}
aty_st_8(CRTC_EXT_CNTL+1, state);
if (par->chip_gen == rage_M3) {
aty128_set_crt_enable(par, par->crt_on && !blank);
aty128_set_lcd_enable(par, par->lcd_on && !blank);
}
return 0;
}
static int aty128fb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
u_int transp, struct fb_info *info)
{
struct aty128fb_par *par = info->par;
if (regno > 255
|| (par->crtc.depth == 16 && regno > 63)
|| (par->crtc.depth == 15 && regno > 31))
return 1;
red >>= 8;
green >>= 8;
blue >>= 8;
if (regno < 16) {
int i;
u32 *pal = info->pseudo_palette;
switch (par->crtc.depth) {
case 15:
pal[regno] = (regno << 10) | (regno << 5) | regno;
break;
case 16:
pal[regno] = (regno << 11) | (regno << 6) | regno;
break;
case 24:
pal[regno] = (regno << 16) | (regno << 8) | regno;
break;
case 32:
i = (regno << 8) | regno;
pal[regno] = (i << 16) | i;
break;
}
}
if (par->crtc.depth == 16 && regno > 0) {
par->green[regno] = green;
if (regno < 32) {
par->red[regno] = red;
par->blue[regno] = blue;
aty128_st_pal(regno * 8, red, par->green[regno*2],
blue, par);
}
red = par->red[regno/2];
blue = par->blue[regno/2];
regno <<= 2;
} else if (par->crtc.bpp == 16)
regno <<= 3;
aty128_st_pal(regno, red, green, blue, par);
return 0;
}
static int aty128fb_ioctl(struct fb_info *info, u_int cmd, u_long arg)
{
struct aty128fb_par *par = info->par;
u32 value;
int rc;
switch (cmd) {
case FBIO_ATY128_SET_MIRROR:
if (par->chip_gen != rage_M3)
return -EINVAL;
rc = get_user(value, (__u32 __user *)arg);
if (rc)
return rc;
par->lcd_on = (value & 0x01) != 0;
par->crt_on = (value & 0x02) != 0;
if (!par->crt_on && !par->lcd_on)
par->lcd_on = 1;
aty128_set_crt_enable(par, par->crt_on);
aty128_set_lcd_enable(par, par->lcd_on);
return 0;
case FBIO_ATY128_GET_MIRROR:
if (par->chip_gen != rage_M3)
return -EINVAL;
value = (par->crt_on << 1) | par->lcd_on;
return put_user(value, (__u32 __user *)arg);
}
return -EINVAL;
}
static void aty128_set_suspend(struct aty128fb_par *par, int suspend)
{
u32 pmgt;
struct pci_dev *pdev = par->pdev;
if (!par->pm_reg)
return;
if (suspend) {
aty_st_le32(CRTC2_GEN_CNTL, aty_ld_le32(CRTC2_GEN_CNTL) &
~(CRTC2_EN));
pmgt = 0x0c005407;
aty_st_pll(POWER_MANAGEMENT, pmgt);
(void)aty_ld_pll(POWER_MANAGEMENT);
aty_st_le32(BUS_CNTL1, 0x00000010);
aty_st_le32(MEM_POWER_MISC, 0x0c830000);
mdelay(100);
pci_set_power_state(pdev, PCI_D2);
}
}
static int aty128_pci_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct fb_info *info = pci_get_drvdata(pdev);
struct aty128fb_par *par = info->par;
pci_save_state(pdev);
#ifndef CONFIG_PPC_PMAC
return 0;
#endif
if (state.event == pdev->dev.power.power_state.event)
return 0;
printk(KERN_DEBUG "aty128fb: suspending...\n");
console_lock();
fb_set_suspend(info, 1);
wait_for_idle(par);
aty128_reset_engine(par);
wait_for_idle(par);
aty128fb_blank(FB_BLANK_POWERDOWN, info);
par->asleep = 1;
par->lock_blank = 1;
#ifdef CONFIG_PPC_PMAC
pmac_suspend_agp_for_card(pdev);
#endif
if (state.event != PM_EVENT_ON)
aty128_set_suspend(par, 1);
console_unlock();
pdev->dev.power.power_state = state;
return 0;
}
static int aty128_do_resume(struct pci_dev *pdev)
{
struct fb_info *info = pci_get_drvdata(pdev);
struct aty128fb_par *par = info->par;
if (pdev->dev.power.power_state.event == PM_EVENT_ON)
return 0;
aty128_set_suspend(par, 0);
par->asleep = 0;
aty128_reset_engine(par);
wait_for_idle(par);
aty128fb_set_par(info);
fb_pan_display(info, &info->var);
fb_set_cmap(&info->cmap, info);
fb_set_suspend(info, 0);
par->lock_blank = 0;
aty128fb_blank(0, info);
#ifdef CONFIG_PPC_PMAC
pmac_resume_agp_for_card(pdev);
#endif
pdev->dev.power.power_state = PMSG_ON;
printk(KERN_DEBUG "aty128fb: resumed !\n");
return 0;
}
static int aty128_pci_resume(struct pci_dev *pdev)
{
int rc;
console_lock();
rc = aty128_do_resume(pdev);
console_unlock();
return rc;
}
static int __devinit aty128fb_init(void)
{
#ifndef MODULE
char *option = NULL;
if (fb_get_options("aty128fb", &option))
return -ENODEV;
aty128fb_setup(option);
#endif
return pci_register_driver(&aty128fb_driver);
}
static void __exit aty128fb_exit(void)
{
pci_unregister_driver(&aty128fb_driver);
}
