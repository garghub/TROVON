static unsigned int mbxfb_get_pixclock(unsigned int pixclock_ps,
struct pixclock_div *div)
{
u8 m, n, p;
unsigned int err = 0;
unsigned int min_err = ~0x0;
unsigned int clk;
unsigned int best_clk = 0;
unsigned int ref_clk = 13000;
unsigned int pixclock;
pixclock = PICOS2KHZ(pixclock_ps);
for (m = 1; m < 64; m++) {
for (n = 2; n < 8; n++) {
for (p = 0; p < 8; p++) {
clk = (ref_clk * m) / (n * (1 << p));
err = (clk > pixclock) ? (clk - pixclock) :
(pixclock - clk);
if (err < min_err) {
min_err = err;
best_clk = clk;
div->m = m;
div->n = n;
div->p = p;
}
}
}
}
return KHZ2PICOS(best_clk);
}
static int mbxfb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
u_int trans, struct fb_info *info)
{
u32 val, ret = 1;
if (regno < MAX_PALETTES) {
u32 *pal = info->pseudo_palette;
val = (red & 0xf800) | ((green & 0xfc00) >> 5) |
((blue & 0xf800) >> 11);
pal[regno] = val;
ret = 0;
}
return ret;
}
static int mbxfb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
struct pixclock_div div;
var->pixclock = mbxfb_get_pixclock(var->pixclock, &div);
if (var->xres < MIN_XRES)
var->xres = MIN_XRES;
if (var->yres < MIN_YRES)
var->yres = MIN_YRES;
if (var->xres > MAX_XRES)
return -EINVAL;
if (var->yres > MAX_YRES)
return -EINVAL;
var->xres_virtual = max(var->xres_virtual, var->xres);
var->yres_virtual = max(var->yres_virtual, var->yres);
switch (var->bits_per_pixel) {
case 8:
return -EINVAL;
case 16:
var->green.length = (var->green.length == 5) ? 5 : 6;
var->red.length = 5;
var->blue.length = 5;
var->transp.length = 6 - var->green.length;
var->blue.offset = 0;
var->green.offset = 5;
var->red.offset = 5 + var->green.length;
var->transp.offset = (5 + var->red.offset) & 15;
break;
case 24:
case 32:
var->red.offset = 16;
var->red.length = 8;
var->green.offset = 8;
var->green.length = 8;
var->blue.offset = 0;
var->blue.length = 8;
var->transp.length = var->bits_per_pixel - 24;
var->transp.offset = (var->transp.length) ? 24 : 0;
break;
}
var->red.msb_right = 0;
var->green.msb_right = 0;
var->blue.msb_right = 0;
var->transp.msb_right = 0;
return 0;
}
static int mbxfb_set_par(struct fb_info *info)
{
struct fb_var_screeninfo *var = &info->var;
struct pixclock_div div;
ushort hbps, ht, hfps, has;
ushort vbps, vt, vfps, vas;
u32 gsctrl = readl(GSCTRL);
u32 gsadr = readl(GSADR);
info->fix.line_length = var->xres_virtual * var->bits_per_pixel / 8;
gsctrl &= ~(FMsk(GSCTRL_GPIXFMT));
if (info->var.bits_per_pixel == 8) {
return -EINVAL;
} else {
fb_dealloc_cmap(&info->cmap);
gsctrl &= ~GSCTRL_LUT_EN;
info->fix.visual = FB_VISUAL_TRUECOLOR;
switch (info->var.bits_per_pixel) {
case 16:
if (info->var.green.length == 5)
gsctrl |= GSCTRL_GPIXFMT_ARGB1555;
else
gsctrl |= GSCTRL_GPIXFMT_RGB565;
break;
case 24:
gsctrl |= GSCTRL_GPIXFMT_RGB888;
break;
case 32:
gsctrl |= GSCTRL_GPIXFMT_ARGB8888;
break;
}
}
gsctrl &= ~(FMsk(GSCTRL_GSWIDTH) | FMsk(GSCTRL_GSHEIGHT));
gsctrl |= Gsctrl_Width(info->var.xres) |
Gsctrl_Height(info->var.yres);
write_reg_dly(gsctrl, GSCTRL);
gsadr &= ~(FMsk(GSADR_SRCSTRIDE));
gsadr |= Gsadr_Srcstride(info->var.xres * info->var.bits_per_pixel /
(8 * 16) - 1);
write_reg_dly(gsadr, GSADR);
var->pixclock = mbxfb_get_pixclock(info->var.pixclock, &div);
write_reg_dly((Disp_Pll_M(div.m) | Disp_Pll_N(div.n) |
Disp_Pll_P(div.p) | DISP_PLL_EN), DISPPLL);
hbps = var->hsync_len;
has = hbps + var->left_margin;
hfps = has + var->xres;
ht = hfps + var->right_margin;
vbps = var->vsync_len;
vas = vbps + var->upper_margin;
vfps = vas + var->yres;
vt = vfps + var->lower_margin;
write_reg_dly((Dht01_Hbps(hbps) | Dht01_Ht(ht)), DHT01);
write_reg_dly((Dht02_Hlbs(has) | Dht02_Has(has)), DHT02);
write_reg_dly((Dht03_Hfps(hfps) | Dht03_Hrbs(hfps)), DHT03);
write_reg_dly((Dhdet_Hdes(has) | Dhdet_Hdef(hfps)), DHDET);
write_reg_dly((Dvt01_Vbps(vbps) | Dvt01_Vt(vt)), DVT01);
write_reg_dly((Dvt02_Vtbs(vas) | Dvt02_Vas(vas)), DVT02);
write_reg_dly((Dvt03_Vfps(vfps) | Dvt03_Vbbs(vfps)), DVT03);
write_reg_dly((Dvdet_Vdes(vas) | Dvdet_Vdef(vfps)), DVDET);
write_reg_dly((Dvectrl_Vevent(vfps) | Dvectrl_Vfetch(vbps)), DVECTRL);
write_reg_dly((readl(DSCTRL) | DSCTRL_SYNCGEN_EN), DSCTRL);
write_reg_dly(DINTRE_VEVENT0_EN, DINTRE);
return 0;
}
static int mbxfb_blank(int blank, struct fb_info *info)
{
switch (blank) {
case FB_BLANK_POWERDOWN:
case FB_BLANK_VSYNC_SUSPEND:
case FB_BLANK_HSYNC_SUSPEND:
case FB_BLANK_NORMAL:
write_reg_dly((readl(DSCTRL) & ~DSCTRL_SYNCGEN_EN), DSCTRL);
write_reg_dly((readl(PIXCLK) & ~PIXCLK_EN), PIXCLK);
write_reg_dly((readl(VOVRCLK) & ~VOVRCLK_EN), VOVRCLK);
break;
case FB_BLANK_UNBLANK:
write_reg_dly((readl(DSCTRL) | DSCTRL_SYNCGEN_EN), DSCTRL);
write_reg_dly((readl(PIXCLK) | PIXCLK_EN), PIXCLK);
break;
}
return 0;
}
static int mbxfb_setupOverlay(struct mbxfb_overlaySetup *set)
{
u32 vsctrl, vscadr, vsadr;
u32 sssize, spoctrl, shctrl;
u32 vubase, vvbase;
u32 vovrclk;
if (set->scaled_width==0 || set->scaled_height==0)
return -EINVAL;
vovrclk = readl(VOVRCLK);
vsctrl = readl(VSCTRL);
vscadr = readl(VSCADR);
vubase = readl(VUBASE);
vvbase = readl(VVBASE);
shctrl = readl(SHCTRL);
spoctrl = readl(SPOCTRL);
sssize = readl(SSSIZE);
vsctrl &= ~( FMsk(VSCTRL_VSWIDTH) |
FMsk(VSCTRL_VSHEIGHT) |
FMsk(VSCTRL_VPIXFMT) |
VSCTRL_GAMMA_EN | VSCTRL_CSC_EN |
VSCTRL_COSITED );
vsctrl |= Vsctrl_Width(set->width) | Vsctrl_Height(set->height) |
VSCTRL_CSC_EN;
vscadr &= ~(VSCADR_STR_EN | FMsk(VSCADR_VBASE_ADR) );
vubase &= ~(VUBASE_UVHALFSTR | FMsk(VUBASE_UBASE_ADR));
vvbase &= ~(FMsk(VVBASE_VBASE_ADR));
switch (set->fmt) {
case MBXFB_FMT_YUV16:
vsctrl |= VSCTRL_VPIXFMT_YUV12;
set->Y_stride = ((set->width) + 0xf ) & ~0xf;
break;
case MBXFB_FMT_YUV12:
vsctrl |= VSCTRL_VPIXFMT_YUV12;
set->Y_stride = ((set->width) + 0xf ) & ~0xf;
vubase |= VUBASE_UVHALFSTR;
break;
case MBXFB_FMT_UY0VY1:
vsctrl |= VSCTRL_VPIXFMT_UY0VY1;
set->Y_stride = (set->width*2 + 0xf ) & ~0xf;
break;
case MBXFB_FMT_VY0UY1:
vsctrl |= VSCTRL_VPIXFMT_VY0UY1;
set->Y_stride = (set->width*2 + 0xf ) & ~0xf;
break;
case MBXFB_FMT_Y0UY1V:
vsctrl |= VSCTRL_VPIXFMT_Y0UY1V;
set->Y_stride = (set->width*2 + 0xf ) & ~0xf;
break;
case MBXFB_FMT_Y0VY1U:
vsctrl |= VSCTRL_VPIXFMT_Y0VY1U;
set->Y_stride = (set->width*2 + 0xf ) & ~0xf;
break;
default:
return -EINVAL;
}
set->UV_stride = ((set->width/2) + 0x7 ) & ~0x7;
set->U_offset = set->height * set->Y_stride;
set->V_offset = set->U_offset +
set->height * set->UV_stride;
vubase |= Vubase_Ubase_Adr(
(0x60000 + set->mem_offset + set->U_offset)>>3);
vvbase |= Vvbase_Vbase_Adr(
(0x60000 + set->mem_offset + set->V_offset)>>3);
vscadr |= Vscadr_Vbase_Adr((0x60000 + set->mem_offset)>>4);
if (set->enable)
vscadr |= VSCADR_STR_EN;
vsadr = Vsadr_Srcstride((set->Y_stride)/16-1) |
Vsadr_Xstart(set->x) | Vsadr_Ystart(set->y);
sssize &= ~(FMsk(SSSIZE_SC_WIDTH) | FMsk(SSSIZE_SC_HEIGHT));
sssize = Sssize_Sc_Width(set->scaled_width-1) |
Sssize_Sc_Height(set->scaled_height-1);
spoctrl &= ~(SPOCTRL_H_SC_BP | SPOCTRL_V_SC_BP |
SPOCTRL_HV_SC_OR | SPOCTRL_VS_UR_C |
FMsk(SPOCTRL_VPITCH));
spoctrl |= Spoctrl_Vpitch((set->height<<11)/set->scaled_height);
if (set->scaled_width == set->width)
spoctrl |= SPOCTRL_H_SC_BP;
if (set->scaled_height == set->height)
spoctrl |= SPOCTRL_V_SC_BP;
shctrl &= ~(FMsk(SHCTRL_HPITCH) | SHCTRL_HDECIM);
shctrl |= Shctrl_Hpitch((set->width<<11)/set->scaled_width);
write_reg(vsctrl, VSCTRL);
write_reg(vscadr, VSCADR);
write_reg(vubase, VUBASE);
write_reg(vvbase, VVBASE);
write_reg(vsadr, VSADR);
write_reg(sssize, SSSIZE);
write_reg(spoctrl, SPOCTRL);
write_reg(shctrl, SHCTRL);
if (set->enable)
vovrclk |= 1;
else
vovrclk &= ~1;
write_reg(vovrclk, VOVRCLK);
return 0;
}
static int mbxfb_ioctl_planeorder(struct mbxfb_planeorder *porder)
{
unsigned long gscadr, vscadr;
if (porder->bottom == porder->top)
return -EINVAL;
gscadr = readl(GSCADR);
vscadr = readl(VSCADR);
gscadr &= ~(FMsk(GSCADR_BLEND_POS));
vscadr &= ~(FMsk(VSCADR_BLEND_POS));
switch (porder->bottom) {
case MBXFB_PLANE_GRAPHICS:
gscadr |= GSCADR_BLEND_GFX;
break;
case MBXFB_PLANE_VIDEO:
vscadr |= VSCADR_BLEND_GFX;
break;
default:
return -EINVAL;
}
switch (porder->top) {
case MBXFB_PLANE_GRAPHICS:
gscadr |= GSCADR_BLEND_VID;
break;
case MBXFB_PLANE_VIDEO:
vscadr |= GSCADR_BLEND_VID;
break;
default:
return -EINVAL;
}
write_reg_dly(vscadr, VSCADR);
write_reg_dly(gscadr, GSCADR);
return 0;
}
static int mbxfb_ioctl_alphactl(struct mbxfb_alphaCtl *alpha)
{
unsigned long vscadr, vbbase, vcmsk;
unsigned long gscadr, gbbase, gdrctrl;
vbbase = Vbbase_Glalpha(alpha->overlay_global_alpha) |
Vbbase_Colkey(alpha->overlay_colorkey);
gbbase = Gbbase_Glalpha(alpha->graphics_global_alpha) |
Gbbase_Colkey(alpha->graphics_colorkey);
vcmsk = readl(VCMSK);
vcmsk &= ~(FMsk(VCMSK_COLKEY_M));
vcmsk |= Vcmsk_colkey_m(alpha->overlay_colorkey_mask);
gdrctrl = readl(GDRCTRL);
gdrctrl &= ~(FMsk(GDRCTRL_COLKEYM));
gdrctrl |= Gdrctrl_Colkeym(alpha->graphics_colorkey_mask);
vscadr = readl(VSCADR);
vscadr &= ~(FMsk(VSCADR_BLEND_M) | VSCADR_COLKEYSRC | VSCADR_COLKEY_EN);
gscadr = readl(GSCADR);
gscadr &= ~(FMsk(GSCADR_BLEND_M) | GSCADR_COLKEY_EN | GSCADR_COLKEYSRC);
switch (alpha->overlay_colorkey_mode) {
case MBXFB_COLORKEY_DISABLED:
break;
case MBXFB_COLORKEY_PREVIOUS:
vscadr |= VSCADR_COLKEY_EN;
break;
case MBXFB_COLORKEY_CURRENT:
vscadr |= VSCADR_COLKEY_EN | VSCADR_COLKEYSRC;
break;
default:
return -EINVAL;
}
switch (alpha->overlay_blend_mode) {
case MBXFB_ALPHABLEND_NONE:
vscadr |= VSCADR_BLEND_NONE;
break;
case MBXFB_ALPHABLEND_GLOBAL:
vscadr |= VSCADR_BLEND_GLOB;
break;
case MBXFB_ALPHABLEND_PIXEL:
vscadr |= VSCADR_BLEND_PIX;
break;
default:
return -EINVAL;
}
switch (alpha->graphics_colorkey_mode) {
case MBXFB_COLORKEY_DISABLED:
break;
case MBXFB_COLORKEY_PREVIOUS:
gscadr |= GSCADR_COLKEY_EN;
break;
case MBXFB_COLORKEY_CURRENT:
gscadr |= GSCADR_COLKEY_EN | GSCADR_COLKEYSRC;
break;
default:
return -EINVAL;
}
switch (alpha->graphics_blend_mode) {
case MBXFB_ALPHABLEND_NONE:
gscadr |= GSCADR_BLEND_NONE;
break;
case MBXFB_ALPHABLEND_GLOBAL:
gscadr |= GSCADR_BLEND_GLOB;
break;
case MBXFB_ALPHABLEND_PIXEL:
gscadr |= GSCADR_BLEND_PIX;
break;
default:
return -EINVAL;
}
write_reg_dly(vbbase, VBBASE);
write_reg_dly(gbbase, GBBASE);
write_reg_dly(vcmsk, VCMSK);
write_reg_dly(gdrctrl, GDRCTRL);
write_reg_dly(gscadr, GSCADR);
write_reg_dly(vscadr, VSCADR);
return 0;
}
static int mbxfb_ioctl(struct fb_info *info, unsigned int cmd,
unsigned long arg)
{
struct mbxfb_overlaySetup setup;
struct mbxfb_planeorder porder;
struct mbxfb_alphaCtl alpha;
struct mbxfb_reg reg;
int res;
__u32 tmp;
switch (cmd)
{
case MBXFB_IOCX_OVERLAY:
if (copy_from_user(&setup, (void __user*)arg,
sizeof(struct mbxfb_overlaySetup)))
return -EFAULT;
res = mbxfb_setupOverlay(&setup);
if (res)
return res;
if (copy_to_user((void __user*)arg, &setup,
sizeof(struct mbxfb_overlaySetup)))
return -EFAULT;
return 0;
case MBXFB_IOCS_PLANEORDER:
if (copy_from_user(&porder, (void __user*)arg,
sizeof(struct mbxfb_planeorder)))
return -EFAULT;
return mbxfb_ioctl_planeorder(&porder);
case MBXFB_IOCS_ALPHA:
if (copy_from_user(&alpha, (void __user*)arg,
sizeof(struct mbxfb_alphaCtl)))
return -EFAULT;
return mbxfb_ioctl_alphactl(&alpha);
case MBXFB_IOCS_REG:
if (copy_from_user(&reg, (void __user*)arg,
sizeof(struct mbxfb_reg)))
return -EFAULT;
if (reg.addr >= 0x10000)
return -EINVAL;
tmp = readl(virt_base_2700 + reg.addr);
tmp &= ~reg.mask;
tmp |= reg.val & reg.mask;
writel(tmp, virt_base_2700 + reg.addr);
return 0;
case MBXFB_IOCX_REG:
if (copy_from_user(&reg, (void __user*)arg,
sizeof(struct mbxfb_reg)))
return -EFAULT;
if (reg.addr >= 0x10000)
return -EINVAL;
reg.val = readl(virt_base_2700 + reg.addr);
if (copy_to_user((void __user*)arg, &reg,
sizeof(struct mbxfb_reg)))
return -EFAULT;
return 0;
}
return -EINVAL;
}
static void __devinit setup_memc(struct fb_info *fbi)
{
unsigned long tmp;
int i;
write_reg_dly((LMCFG_LMC_DS | LMCFG_LMC_TS | LMCFG_LMD_TS |
LMCFG_LMA_TS),
LMCFG);
write_reg_dly(LMPWR_MC_PWR_ACT, LMPWR);
write_reg_dly((Lmtim_Tras(7) | Lmtim_Trp(3) | Lmtim_Trcd(3) |
Lmtim_Trc(9) | Lmtim_Tdpl(2)),
LMTIM);
write_reg_dly(0xc2b, LMREFRESH);
write_reg_dly((LMTYPE_CASLAT_3 | LMTYPE_BKSZ_2 | LMTYPE_ROWSZ_11 |
LMTYPE_COLSZ_8),
LMTYPE);
write_reg_dly(LMPWR_MC_PWR_ACT, LMPWR);
for ( i = 0; i < 16; i++ ) {
tmp = readl(fbi->screen_base);
}
}
static void enable_clocks(struct fb_info *fbi)
{
write_reg_dly(SYSCLKSRC_PLL_2, SYSCLKSRC);
write_reg_dly(PIXCLKSRC_PLL_1, PIXCLKSRC);
write_reg_dly(0x00000000, CLKSLEEP);
write_reg_dly((Core_Pll_M(0xb) | Core_Pll_N(0x1) | Core_Pll_P(0x1) |
CORE_PLL_EN),
COREPLL);
write_reg_dly((Disp_Pll_M(0x1b) | Disp_Pll_N(0x7) | Disp_Pll_P(0x1) |
DISP_PLL_EN),
DISPPLL);
write_reg_dly(0x00000000, VOVRCLK);
write_reg_dly(PIXCLK_EN, PIXCLK);
write_reg_dly(MEMCLK_EN, MEMCLK);
write_reg_dly(0x00000001, M24CLK);
write_reg_dly(0x00000001, MBXCLK);
write_reg_dly(SDCLK_EN, SDCLK);
write_reg_dly(0x00000001, PIXCLKDIV);
}
static void __devinit setup_graphics(struct fb_info *fbi)
{
unsigned long gsctrl;
unsigned long vscadr;
gsctrl = GSCTRL_GAMMA_EN | Gsctrl_Width(fbi->var.xres) |
Gsctrl_Height(fbi->var.yres);
switch (fbi->var.bits_per_pixel) {
case 16:
if (fbi->var.green.length == 5)
gsctrl |= GSCTRL_GPIXFMT_ARGB1555;
else
gsctrl |= GSCTRL_GPIXFMT_RGB565;
break;
case 24:
gsctrl |= GSCTRL_GPIXFMT_RGB888;
break;
case 32:
gsctrl |= GSCTRL_GPIXFMT_ARGB8888;
break;
}
write_reg_dly(gsctrl, GSCTRL);
write_reg_dly(0x00000000, GBBASE);
write_reg_dly(0x00ffffff, GDRCTRL);
write_reg_dly((GSCADR_STR_EN | Gscadr_Gbase_Adr(0x6000)), GSCADR);
write_reg_dly(0x00000000, GPLUT);
vscadr = readl(VSCADR);
vscadr &= ~(FMsk(VSCADR_BLEND_POS) | FMsk(VSCADR_BLEND_M));
vscadr |= VSCADR_BLEND_VID | VSCADR_BLEND_NONE;
write_reg_dly(vscadr, VSCADR);
}
static void __devinit setup_display(struct fb_info *fbi)
{
unsigned long dsctrl = 0;
dsctrl = DSCTRL_BLNK_POL;
if (fbi->var.sync & FB_SYNC_HOR_HIGH_ACT)
dsctrl |= DSCTRL_HS_POL;
if (fbi->var.sync & FB_SYNC_VERT_HIGH_ACT)
dsctrl |= DSCTRL_VS_POL;
write_reg_dly(dsctrl, DSCTRL);
write_reg_dly(0xd0303010, DMCTRL);
write_reg_dly((readl(DSCTRL) | DSCTRL_SYNCGEN_EN), DSCTRL);
}
static void __devinit enable_controller(struct fb_info *fbi)
{
u32 svctrl, shctrl;
write_reg_dly(SYSRST_RST, SYSRST);
write_reg_dly(0xffffff0c, SYSCFG);
enable_clocks(fbi);
setup_memc(fbi);
setup_graphics(fbi);
setup_display(fbi);
shctrl = readl(SHCTRL);
shctrl &= ~(FMsk(SHCTRL_HINITIAL));
shctrl |= Shctrl_Hinitial(4<<11);
writel(shctrl, SHCTRL);
svctrl = Svctrl_Initial1(1<<10) | Svctrl_Initial2(1<<10);
writel(svctrl, SVCTRL);
writel(SPOCTRL_H_SC_BP | SPOCTRL_V_SC_BP | SPOCTRL_VORDER_4TAP
, SPOCTRL);
write_reg(0xff000100, VSCOEFF0);
write_reg(0xfdfcfdfe, VSCOEFF1);
write_reg(0x170d0500, VSCOEFF2);
write_reg(0x3d372d22, VSCOEFF3);
write_reg(0x00000040, VSCOEFF4);
write_reg(0xff010100, HSCOEFF0);
write_reg(0x00000000, HSCOEFF1);
write_reg(0x02010000, HSCOEFF2);
write_reg(0x01020302, HSCOEFF3);
write_reg(0xf9fbfe00, HSCOEFF4);
write_reg(0xfbf7f6f7, HSCOEFF5);
write_reg(0x1c110700, HSCOEFF6);
write_reg(0x3e393127, HSCOEFF7);
write_reg(0x00000040, HSCOEFF8);
}
static int mbxfb_suspend(struct platform_device *dev, pm_message_t state)
{
write_reg_dly(LMPWR_MC_PWR_SRM, LMPWR);
while (readl(LMPWRSTAT) != LMPWRSTAT_MC_PWR_SRM)
;
write_reg_dly(SYSRST_RST, SYSRST);
return 0;
}
static int mbxfb_resume(struct platform_device *dev)
{
struct fb_info *fbi = platform_get_drvdata(dev);
enable_clocks(fbi);
write_reg_dly((readl(DSCTRL) | DSCTRL_SYNCGEN_EN), DSCTRL);
return 0;
}
static int __devinit mbxfb_probe(struct platform_device *dev)
{
int ret;
struct fb_info *fbi;
struct mbxfb_info *mfbi;
struct mbxfb_platform_data *pdata;
dev_dbg(&dev->dev, "mbxfb_probe\n");
pdata = dev->dev.platform_data;
if (!pdata) {
dev_err(&dev->dev, "platform data is required\n");
return -EINVAL;
}
fbi = framebuffer_alloc(sizeof(struct mbxfb_info), &dev->dev);
if (fbi == NULL) {
dev_err(&dev->dev, "framebuffer_alloc failed\n");
return -ENOMEM;
}
mfbi = fbi->par;
fbi->pseudo_palette = mfbi->pseudo_palette;
if (pdata->probe)
mfbi->platform_probe = pdata->probe;
if (pdata->remove)
mfbi->platform_remove = pdata->remove;
mfbi->fb_res = platform_get_resource(dev, IORESOURCE_MEM, 0);
mfbi->reg_res = platform_get_resource(dev, IORESOURCE_MEM, 1);
if (!mfbi->fb_res || !mfbi->reg_res) {
dev_err(&dev->dev, "no resources found\n");
ret = -ENODEV;
goto err1;
}
mfbi->fb_req = request_mem_region(mfbi->fb_res->start,
res_size(mfbi->fb_res), dev->name);
if (mfbi->fb_req == NULL) {
dev_err(&dev->dev, "failed to claim framebuffer memory\n");
ret = -EINVAL;
goto err1;
}
mfbi->fb_phys_addr = mfbi->fb_res->start;
mfbi->reg_req = request_mem_region(mfbi->reg_res->start,
res_size(mfbi->reg_res), dev->name);
if (mfbi->reg_req == NULL) {
dev_err(&dev->dev, "failed to claim Marathon registers\n");
ret = -EINVAL;
goto err2;
}
mfbi->reg_phys_addr = mfbi->reg_res->start;
mfbi->reg_virt_addr = ioremap_nocache(mfbi->reg_phys_addr,
res_size(mfbi->reg_req));
if (!mfbi->reg_virt_addr) {
dev_err(&dev->dev, "failed to ioremap Marathon registers\n");
ret = -EINVAL;
goto err3;
}
virt_base_2700 = mfbi->reg_virt_addr;
mfbi->fb_virt_addr = ioremap_nocache(mfbi->fb_phys_addr,
res_size(mfbi->fb_req));
if (!mfbi->reg_virt_addr) {
dev_err(&dev->dev, "failed to ioremap frame buffer\n");
ret = -EINVAL;
goto err4;
}
fbi->screen_base = (char __iomem *)(mfbi->fb_virt_addr + 0x60000);
fbi->screen_size = pdata->memsize;
fbi->fbops = &mbxfb_ops;
fbi->var = mbxfb_default;
fbi->fix = mbxfb_fix;
fbi->fix.smem_start = mfbi->fb_phys_addr + 0x60000;
fbi->fix.smem_len = pdata->memsize;
fbi->fix.line_length = mbxfb_default.xres_virtual *
mbxfb_default.bits_per_pixel / 8;
ret = fb_alloc_cmap(&fbi->cmap, 256, 0);
if (ret < 0) {
dev_err(&dev->dev, "fb_alloc_cmap failed\n");
ret = -EINVAL;
goto err5;
}
platform_set_drvdata(dev, fbi);
printk(KERN_INFO "fb%d: mbx frame buffer device\n", fbi->node);
if (mfbi->platform_probe)
mfbi->platform_probe(fbi);
enable_controller(fbi);
mbxfb_debugfs_init(fbi);
ret = register_framebuffer(fbi);
if (ret < 0) {
dev_err(&dev->dev, "register_framebuffer failed\n");
ret = -EINVAL;
goto err6;
}
return 0;
err6:
fb_dealloc_cmap(&fbi->cmap);
err5:
iounmap(mfbi->fb_virt_addr);
err4:
iounmap(mfbi->reg_virt_addr);
err3:
release_mem_region(mfbi->reg_res->start, res_size(mfbi->reg_res));
err2:
release_mem_region(mfbi->fb_res->start, res_size(mfbi->fb_res));
err1:
framebuffer_release(fbi);
return ret;
}
static int __devexit mbxfb_remove(struct platform_device *dev)
{
struct fb_info *fbi = platform_get_drvdata(dev);
write_reg_dly(SYSRST_RST, SYSRST);
mbxfb_debugfs_remove(fbi);
if (fbi) {
struct mbxfb_info *mfbi = fbi->par;
unregister_framebuffer(fbi);
if (mfbi) {
if (mfbi->platform_remove)
mfbi->platform_remove(fbi);
if (mfbi->fb_virt_addr)
iounmap(mfbi->fb_virt_addr);
if (mfbi->reg_virt_addr)
iounmap(mfbi->reg_virt_addr);
if (mfbi->reg_req)
release_mem_region(mfbi->reg_req->start,
res_size(mfbi->reg_req));
if (mfbi->fb_req)
release_mem_region(mfbi->fb_req->start,
res_size(mfbi->fb_req));
}
framebuffer_release(fbi);
}
return 0;
}
int __devinit mbxfb_init(void)
{
return platform_driver_register(&mbxfb_driver);
}
static void __devexit mbxfb_exit(void)
{
platform_driver_unregister(&mbxfb_driver);
}
