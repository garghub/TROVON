static void radeon_unmap_ROM(struct radeonfb_info *rinfo, struct pci_dev *dev)
{
if (!rinfo->bios_seg)
return;
pci_unmap_rom(dev, rinfo->bios_seg);
}
static int __devinit radeon_map_ROM(struct radeonfb_info *rinfo, struct pci_dev *dev)
{
void __iomem *rom;
u16 dptr;
u8 rom_type;
size_t rom_size;
unsigned int temp;
temp = INREG(MPP_TB_CONFIG);
temp &= 0x00ffffffu;
temp |= 0x04 << 24;
OUTREG(MPP_TB_CONFIG, temp);
temp = INREG(MPP_TB_CONFIG);
rom = pci_map_rom(dev, &rom_size);
if (!rom) {
printk(KERN_ERR "radeonfb (%s): ROM failed to map\n",
pci_name(rinfo->pdev));
return -ENOMEM;
}
rinfo->bios_seg = rom;
if (BIOS_IN16(0) != 0xaa55) {
printk(KERN_DEBUG "radeonfb (%s): Invalid ROM signature %x "
"should be 0xaa55\n",
pci_name(rinfo->pdev), BIOS_IN16(0));
goto failed;
}
dptr = BIOS_IN16(0x18);
if (BIOS_IN32(dptr) != (('R' << 24) | ('I' << 16) | ('C' << 8) | 'P')) {
printk(KERN_WARNING "radeonfb (%s): PCI DATA signature in ROM"
"incorrect: %08x\n", pci_name(rinfo->pdev), BIOS_IN32(dptr));
goto anyway;
}
rom_type = BIOS_IN8(dptr + 0x14);
switch(rom_type) {
case 0:
printk(KERN_INFO "radeonfb: Found Intel x86 BIOS ROM Image\n");
break;
case 1:
printk(KERN_INFO "radeonfb: Found Open Firmware ROM Image\n");
goto failed;
case 2:
printk(KERN_INFO "radeonfb: Found HP PA-RISC ROM Image\n");
goto failed;
default:
printk(KERN_INFO "radeonfb: Found unknown type %d ROM Image\n", rom_type);
goto failed;
}
anyway:
rinfo->fp_bios_start = BIOS_IN16(0x48);
return 0;
failed:
rinfo->bios_seg = NULL;
radeon_unmap_ROM(rinfo, dev);
return -ENXIO;
}
static int __devinit radeon_find_mem_vbios(struct radeonfb_info *rinfo)
{
u32 segstart;
void __iomem *rom_base = NULL;
for(segstart=0x000c0000; segstart<0x000f0000; segstart+=0x00001000) {
rom_base = ioremap(segstart, 0x10000);
if (rom_base == NULL)
return -ENOMEM;
if (readb(rom_base) == 0x55 && readb(rom_base + 1) == 0xaa)
break;
iounmap(rom_base);
rom_base = NULL;
}
if (rom_base == NULL)
return -ENXIO;
rinfo->bios_seg = rom_base;
rinfo->fp_bios_start = BIOS_IN16(0x48);
return 0;
}
static int __devinit radeon_read_xtal_OF (struct radeonfb_info *rinfo)
{
struct device_node *dp = rinfo->of_node;
const u32 *val;
if (dp == NULL)
return -ENODEV;
val = of_get_property(dp, "ATY,RefCLK", NULL);
if (!val || !*val) {
printk(KERN_WARNING "radeonfb: No ATY,RefCLK property !\n");
return -EINVAL;
}
rinfo->pll.ref_clk = (*val) / 10;
val = of_get_property(dp, "ATY,SCLK", NULL);
if (val && *val)
rinfo->pll.sclk = (*val) / 10;
val = of_get_property(dp, "ATY,MCLK", NULL);
if (val && *val)
rinfo->pll.mclk = (*val) / 10;
return 0;
}
static int __devinit radeon_probe_pll_params(struct radeonfb_info *rinfo)
{
unsigned char ppll_div_sel;
unsigned Ns, Nm, M;
unsigned sclk, mclk, tmp, ref_div;
int hTotal, vTotal, num, denom, m, n;
unsigned long long hz, vclk;
long xtal;
struct timeval start_tv, stop_tv;
long total_secs, total_usecs;
int i;
tmp = INREG16(DEVICE_ID);
local_irq_disable();
for(i=0; i<1000000; i++)
if (((INREG(CRTC_VLINE_CRNT_VLINE) >> 16) & 0x3ff) == 0)
break;
do_gettimeofday(&start_tv);
for(i=0; i<1000000; i++)
if (((INREG(CRTC_VLINE_CRNT_VLINE) >> 16) & 0x3ff) != 0)
break;
for(i=0; i<1000000; i++)
if (((INREG(CRTC_VLINE_CRNT_VLINE) >> 16) & 0x3ff) == 0)
break;
do_gettimeofday(&stop_tv);
local_irq_enable();
total_secs = stop_tv.tv_sec - start_tv.tv_sec;
if (total_secs > 10)
return -1;
total_usecs = stop_tv.tv_usec - start_tv.tv_usec;
total_usecs += total_secs * 1000000;
if (total_usecs < 0)
total_usecs = -total_usecs;
hz = 1000000/total_usecs;
hTotal = ((INREG(CRTC_H_TOTAL_DISP) & 0x1ff) + 1) * 8;
vTotal = ((INREG(CRTC_V_TOTAL_DISP) & 0x3ff) + 1);
vclk = (long long)hTotal * (long long)vTotal * hz;
switch((INPLL(PPLL_REF_DIV) & 0x30000) >> 16) {
case 0:
default:
num = 1;
denom = 1;
break;
case 1:
n = ((INPLL(M_SPLL_REF_FB_DIV) >> 16) & 0xff);
m = (INPLL(M_SPLL_REF_FB_DIV) & 0xff);
num = 2*n;
denom = 2*m;
break;
case 2:
n = ((INPLL(M_SPLL_REF_FB_DIV) >> 8) & 0xff);
m = (INPLL(M_SPLL_REF_FB_DIV) & 0xff);
num = 2*n;
denom = 2*m;
break;
}
ppll_div_sel = INREG8(CLOCK_CNTL_INDEX + 1) & 0x3;
radeon_pll_errata_after_index(rinfo);
n = (INPLL(PPLL_DIV_0 + ppll_div_sel) & 0x7ff);
m = (INPLL(PPLL_REF_DIV) & 0x3ff);
num *= n;
denom *= m;
switch ((INPLL(PPLL_DIV_0 + ppll_div_sel) >> 16) & 0x7) {
case 1:
denom *= 2;
break;
case 2:
denom *= 4;
break;
case 3:
denom *= 8;
break;
case 4:
denom *= 3;
break;
case 6:
denom *= 6;
break;
case 7:
denom *= 12;
break;
}
vclk *= denom;
do_div(vclk, 1000 * num);
xtal = vclk;
if ((xtal > 26900) && (xtal < 27100))
xtal = 2700;
else if ((xtal > 14200) && (xtal < 14400))
xtal = 1432;
else if ((xtal > 29400) && (xtal < 29600))
xtal = 2950;
else {
printk(KERN_WARNING "xtal calculation failed: %ld\n", xtal);
return -1;
}
tmp = INPLL(M_SPLL_REF_FB_DIV);
ref_div = INPLL(PPLL_REF_DIV) & 0x3ff;
Ns = (tmp & 0xff0000) >> 16;
Nm = (tmp & 0xff00) >> 8;
M = (tmp & 0xff);
sclk = round_div((2 * Ns * xtal), (2 * M));
mclk = round_div((2 * Nm * xtal), (2 * M));
rinfo->pll.ref_clk = xtal;
rinfo->pll.ref_div = ref_div;
rinfo->pll.sclk = sclk;
rinfo->pll.mclk = mclk;
return 0;
}
static void __devinit radeon_get_pllinfo(struct radeonfb_info *rinfo)
{
switch (rinfo->chipset) {
case PCI_DEVICE_ID_ATI_RADEON_QW:
case PCI_DEVICE_ID_ATI_RADEON_QX:
rinfo->pll.ppll_max = 35000;
rinfo->pll.ppll_min = 12000;
rinfo->pll.mclk = 23000;
rinfo->pll.sclk = 23000;
rinfo->pll.ref_clk = 2700;
break;
case PCI_DEVICE_ID_ATI_RADEON_QL:
case PCI_DEVICE_ID_ATI_RADEON_QN:
case PCI_DEVICE_ID_ATI_RADEON_QO:
case PCI_DEVICE_ID_ATI_RADEON_Ql:
case PCI_DEVICE_ID_ATI_RADEON_BB:
rinfo->pll.ppll_max = 35000;
rinfo->pll.ppll_min = 12000;
rinfo->pll.mclk = 27500;
rinfo->pll.sclk = 27500;
rinfo->pll.ref_clk = 2700;
break;
case PCI_DEVICE_ID_ATI_RADEON_Id:
case PCI_DEVICE_ID_ATI_RADEON_Ie:
case PCI_DEVICE_ID_ATI_RADEON_If:
case PCI_DEVICE_ID_ATI_RADEON_Ig:
rinfo->pll.ppll_max = 35000;
rinfo->pll.ppll_min = 12000;
rinfo->pll.mclk = 25000;
rinfo->pll.sclk = 25000;
rinfo->pll.ref_clk = 2700;
break;
case PCI_DEVICE_ID_ATI_RADEON_ND:
case PCI_DEVICE_ID_ATI_RADEON_NE:
case PCI_DEVICE_ID_ATI_RADEON_NF:
case PCI_DEVICE_ID_ATI_RADEON_NG:
rinfo->pll.ppll_max = 40000;
rinfo->pll.ppll_min = 20000;
rinfo->pll.mclk = 27000;
rinfo->pll.sclk = 27000;
rinfo->pll.ref_clk = 2700;
break;
case PCI_DEVICE_ID_ATI_RADEON_QD:
case PCI_DEVICE_ID_ATI_RADEON_QE:
case PCI_DEVICE_ID_ATI_RADEON_QF:
case PCI_DEVICE_ID_ATI_RADEON_QG:
default:
rinfo->pll.ppll_max = 35000;
rinfo->pll.ppll_min = 12000;
rinfo->pll.mclk = 16600;
rinfo->pll.sclk = 16600;
rinfo->pll.ref_clk = 2700;
break;
}
rinfo->pll.ref_div = INPLL(PPLL_REF_DIV) & PPLL_REF_DIV_MASK;
#if defined(CONFIG_PPC_OF) || defined(CONFIG_SPARC)
if (!force_measure_pll && radeon_read_xtal_OF(rinfo) == 0) {
printk(KERN_INFO "radeonfb: Retrieved PLL infos from Open Firmware\n");
goto found;
}
#endif
if (!force_measure_pll && rinfo->bios_seg) {
u16 pll_info_block = BIOS_IN16(rinfo->fp_bios_start + 0x30);
rinfo->pll.sclk = BIOS_IN16(pll_info_block + 0x08);
rinfo->pll.mclk = BIOS_IN16(pll_info_block + 0x0a);
rinfo->pll.ref_clk = BIOS_IN16(pll_info_block + 0x0e);
rinfo->pll.ref_div = BIOS_IN16(pll_info_block + 0x10);
rinfo->pll.ppll_min = BIOS_IN32(pll_info_block + 0x12);
rinfo->pll.ppll_max = BIOS_IN32(pll_info_block + 0x16);
printk(KERN_INFO "radeonfb: Retrieved PLL infos from BIOS\n");
goto found;
}
if (radeon_probe_pll_params(rinfo) == 0) {
printk(KERN_INFO "radeonfb: Retrieved PLL infos from registers\n");
goto found;
}
printk(KERN_INFO "radeonfb: Used default PLL infos\n");
found:
if (rinfo->pll.mclk == 0)
rinfo->pll.mclk = 20000;
if (rinfo->pll.sclk == 0)
rinfo->pll.sclk = 20000;
printk("radeonfb: Reference=%d.%02d MHz (RefDiv=%d) Memory=%d.%02d Mhz, System=%d.%02d MHz\n",
rinfo->pll.ref_clk / 100, rinfo->pll.ref_clk % 100,
rinfo->pll.ref_div,
rinfo->pll.mclk / 100, rinfo->pll.mclk % 100,
rinfo->pll.sclk / 100, rinfo->pll.sclk % 100);
printk("radeonfb: PLL min %d max %d\n", rinfo->pll.ppll_min, rinfo->pll.ppll_max);
}
static int radeonfb_check_var (struct fb_var_screeninfo *var, struct fb_info *info)
{
struct radeonfb_info *rinfo = info->par;
struct fb_var_screeninfo v;
int nom, den;
unsigned int pitch;
if (radeon_match_mode(rinfo, &v, var))
return -EINVAL;
switch (v.bits_per_pixel) {
case 0 ... 8:
v.bits_per_pixel = 8;
break;
case 9 ... 16:
v.bits_per_pixel = 16;
break;
case 17 ... 24:
#if 0
v.bits_per_pixel = 24;
break;
#endif
return -EINVAL;
case 25 ... 32:
v.bits_per_pixel = 32;
break;
default:
return -EINVAL;
}
switch (var_to_depth(&v)) {
case 8:
nom = den = 1;
v.red.offset = v.green.offset = v.blue.offset = 0;
v.red.length = v.green.length = v.blue.length = 8;
v.transp.offset = v.transp.length = 0;
break;
case 15:
nom = 2;
den = 1;
v.red.offset = 10;
v.green.offset = 5;
v.blue.offset = 0;
v.red.length = v.green.length = v.blue.length = 5;
v.transp.offset = v.transp.length = 0;
break;
case 16:
nom = 2;
den = 1;
v.red.offset = 11;
v.green.offset = 5;
v.blue.offset = 0;
v.red.length = 5;
v.green.length = 6;
v.blue.length = 5;
v.transp.offset = v.transp.length = 0;
break;
case 24:
nom = 4;
den = 1;
v.red.offset = 16;
v.green.offset = 8;
v.blue.offset = 0;
v.red.length = v.blue.length = v.green.length = 8;
v.transp.offset = v.transp.length = 0;
break;
case 32:
nom = 4;
den = 1;
v.red.offset = 16;
v.green.offset = 8;
v.blue.offset = 0;
v.red.length = v.blue.length = v.green.length = 8;
v.transp.offset = 24;
v.transp.length = 8;
break;
default:
printk ("radeonfb: mode %dx%dx%d rejected, color depth invalid\n",
var->xres, var->yres, var->bits_per_pixel);
return -EINVAL;
}
if (v.yres_virtual < v.yres)
v.yres_virtual = v.yres;
if (v.xres_virtual < v.xres)
v.xres_virtual = v.xres;
if (rinfo->info->flags & FBINFO_HWACCEL_DISABLED) {
v.xres_virtual = v.xres_virtual & ~7ul;
} else {
pitch = ((v.xres_virtual * ((v.bits_per_pixel + 1) / 8) + 0x3f)
& ~(0x3f)) >> 6;
v.xres_virtual = (pitch << 6) / ((v.bits_per_pixel + 1) / 8);
}
if (((v.xres_virtual * v.yres_virtual * nom) / den) > rinfo->mapped_vram)
return -EINVAL;
if (v.xres_virtual < v.xres)
v.xres = v.xres_virtual;
if (v.xoffset < 0)
v.xoffset = 0;
if (v.yoffset < 0)
v.yoffset = 0;
if (v.xoffset > v.xres_virtual - v.xres)
v.xoffset = v.xres_virtual - v.xres - 1;
if (v.yoffset > v.yres_virtual - v.yres)
v.yoffset = v.yres_virtual - v.yres - 1;
v.red.msb_right = v.green.msb_right = v.blue.msb_right =
v.transp.offset = v.transp.length =
v.transp.msb_right = 0;
memcpy(var, &v, sizeof(v));
return 0;
}
static int radeonfb_pan_display (struct fb_var_screeninfo *var,
struct fb_info *info)
{
struct radeonfb_info *rinfo = info->par;
if ((var->xoffset + var->xres > var->xres_virtual)
|| (var->yoffset + var->yres > var->yres_virtual))
return -EINVAL;
if (rinfo->asleep)
return 0;
radeon_fifo_wait(2);
OUTREG(CRTC_OFFSET, ((var->yoffset * var->xres_virtual + var->xoffset)
* var->bits_per_pixel / 8) & ~7);
return 0;
}
static int radeonfb_ioctl (struct fb_info *info, unsigned int cmd,
unsigned long arg)
{
struct radeonfb_info *rinfo = info->par;
unsigned int tmp;
u32 value = 0;
int rc;
switch (cmd) {
case FBIO_RADEON_SET_MIRROR:
if (!rinfo->is_mobility)
return -EINVAL;
rc = get_user(value, (__u32 __user *)arg);
if (rc)
return rc;
radeon_fifo_wait(2);
if (value & 0x01) {
tmp = INREG(LVDS_GEN_CNTL);
tmp |= (LVDS_ON | LVDS_BLON);
} else {
tmp = INREG(LVDS_GEN_CNTL);
tmp &= ~(LVDS_ON | LVDS_BLON);
}
OUTREG(LVDS_GEN_CNTL, tmp);
if (value & 0x02) {
tmp = INREG(CRTC_EXT_CNTL);
tmp |= CRTC_CRT_ON;
mirror = 1;
} else {
tmp = INREG(CRTC_EXT_CNTL);
tmp &= ~CRTC_CRT_ON;
mirror = 0;
}
OUTREG(CRTC_EXT_CNTL, tmp);
return 0;
case FBIO_RADEON_GET_MIRROR:
if (!rinfo->is_mobility)
return -EINVAL;
tmp = INREG(LVDS_GEN_CNTL);
if ((LVDS_ON | LVDS_BLON) & tmp)
value |= 0x01;
tmp = INREG(CRTC_EXT_CNTL);
if (CRTC_CRT_ON & tmp)
value |= 0x02;
return put_user(value, (__u32 __user *)arg);
default:
return -EINVAL;
}
return -EINVAL;
}
int radeon_screen_blank(struct radeonfb_info *rinfo, int blank, int mode_switch)
{
u32 val;
u32 tmp_pix_clks;
int unblank = 0;
if (rinfo->lock_blank)
return 0;
radeon_engine_idle();
val = INREG(CRTC_EXT_CNTL);
val &= ~(CRTC_DISPLAY_DIS | CRTC_HSYNC_DIS |
CRTC_VSYNC_DIS);
switch (blank) {
case FB_BLANK_VSYNC_SUSPEND:
val |= (CRTC_DISPLAY_DIS | CRTC_VSYNC_DIS);
break;
case FB_BLANK_HSYNC_SUSPEND:
val |= (CRTC_DISPLAY_DIS | CRTC_HSYNC_DIS);
break;
case FB_BLANK_POWERDOWN:
val |= (CRTC_DISPLAY_DIS | CRTC_VSYNC_DIS |
CRTC_HSYNC_DIS);
break;
case FB_BLANK_NORMAL:
val |= CRTC_DISPLAY_DIS;
break;
case FB_BLANK_UNBLANK:
default:
unblank = 1;
}
OUTREG(CRTC_EXT_CNTL, val);
switch (rinfo->mon1_type) {
case MT_DFP:
if (unblank)
OUTREGP(FP_GEN_CNTL, (FP_FPON | FP_TMDS_EN),
~(FP_FPON | FP_TMDS_EN));
else {
if (mode_switch || blank == FB_BLANK_NORMAL)
break;
OUTREGP(FP_GEN_CNTL, 0, ~(FP_FPON | FP_TMDS_EN));
}
break;
case MT_LCD:
del_timer_sync(&rinfo->lvds_timer);
val = INREG(LVDS_GEN_CNTL);
if (unblank) {
u32 target_val = (val & ~LVDS_DISPLAY_DIS) | LVDS_BLON | LVDS_ON
| LVDS_EN | (rinfo->init_state.lvds_gen_cntl
& (LVDS_DIGON | LVDS_BL_MOD_EN));
if ((val ^ target_val) == LVDS_DISPLAY_DIS)
OUTREG(LVDS_GEN_CNTL, target_val);
else if ((val ^ target_val) != 0) {
OUTREG(LVDS_GEN_CNTL, target_val
& ~(LVDS_ON | LVDS_BL_MOD_EN));
rinfo->init_state.lvds_gen_cntl &= ~LVDS_STATE_MASK;
rinfo->init_state.lvds_gen_cntl |=
target_val & LVDS_STATE_MASK;
if (mode_switch) {
radeon_msleep(rinfo->panel_info.pwr_delay);
OUTREG(LVDS_GEN_CNTL, target_val);
}
else {
rinfo->pending_lvds_gen_cntl = target_val;
mod_timer(&rinfo->lvds_timer,
jiffies +
msecs_to_jiffies(rinfo->panel_info.pwr_delay));
}
}
} else {
val |= LVDS_DISPLAY_DIS;
OUTREG(LVDS_GEN_CNTL, val);
if (mode_switch || blank == FB_BLANK_NORMAL)
break;
tmp_pix_clks = INPLL(PIXCLKS_CNTL);
if (rinfo->is_mobility || rinfo->is_IGP)
OUTPLLP(PIXCLKS_CNTL, 0, ~PIXCLK_LVDS_ALWAYS_ONb);
val &= ~(LVDS_BL_MOD_EN);
OUTREG(LVDS_GEN_CNTL, val);
udelay(100);
val &= ~(LVDS_ON | LVDS_EN);
OUTREG(LVDS_GEN_CNTL, val);
val &= ~LVDS_DIGON;
rinfo->pending_lvds_gen_cntl = val;
mod_timer(&rinfo->lvds_timer,
jiffies +
msecs_to_jiffies(rinfo->panel_info.pwr_delay));
rinfo->init_state.lvds_gen_cntl &= ~LVDS_STATE_MASK;
rinfo->init_state.lvds_gen_cntl |= val & LVDS_STATE_MASK;
if (rinfo->is_mobility || rinfo->is_IGP)
OUTPLL(PIXCLKS_CNTL, tmp_pix_clks);
}
break;
case MT_CRT:
default:
break;
}
return 0;
}
static int radeonfb_blank (int blank, struct fb_info *info)
{
struct radeonfb_info *rinfo = info->par;
if (rinfo->asleep)
return 0;
return radeon_screen_blank(rinfo, blank, 0);
}
static int radeon_setcolreg (unsigned regno, unsigned red, unsigned green,
unsigned blue, unsigned transp,
struct radeonfb_info *rinfo)
{
u32 pindex;
unsigned int i;
if (regno > 255)
return -EINVAL;
red >>= 8;
green >>= 8;
blue >>= 8;
rinfo->palette[regno].red = red;
rinfo->palette[regno].green = green;
rinfo->palette[regno].blue = blue;
pindex = regno;
if (!rinfo->asleep) {
radeon_fifo_wait(9);
if (rinfo->bpp == 16) {
pindex = regno * 8;
if (rinfo->depth == 16 && regno > 63)
return -EINVAL;
if (rinfo->depth == 15 && regno > 31)
return -EINVAL;
if (rinfo->depth == 16) {
OUTREG(PALETTE_INDEX, pindex>>1);
OUTREG(PALETTE_DATA,
(rinfo->palette[regno>>1].red << 16) |
(green << 8) |
(rinfo->palette[regno>>1].blue));
green = rinfo->palette[regno<<1].green;
}
}
if (rinfo->depth != 16 || regno < 32) {
OUTREG(PALETTE_INDEX, pindex);
OUTREG(PALETTE_DATA, (red << 16) |
(green << 8) | blue);
}
}
if (regno < 16) {
u32 *pal = rinfo->info->pseudo_palette;
switch (rinfo->depth) {
case 15:
pal[regno] = (regno << 10) | (regno << 5) | regno;
break;
case 16:
pal[regno] = (regno << 11) | (regno << 5) | regno;
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
return 0;
}
static int radeonfb_setcolreg (unsigned regno, unsigned red, unsigned green,
unsigned blue, unsigned transp,
struct fb_info *info)
{
struct radeonfb_info *rinfo = info->par;
u32 dac_cntl2, vclk_cntl = 0;
int rc;
if (!rinfo->asleep) {
if (rinfo->is_mobility) {
vclk_cntl = INPLL(VCLK_ECP_CNTL);
OUTPLL(VCLK_ECP_CNTL,
vclk_cntl & ~PIXCLK_DAC_ALWAYS_ONb);
}
if (rinfo->has_CRTC2) {
dac_cntl2 = INREG(DAC_CNTL2);
dac_cntl2 &= ~DAC2_PALETTE_ACCESS_CNTL;
OUTREG(DAC_CNTL2, dac_cntl2);
}
}
rc = radeon_setcolreg (regno, red, green, blue, transp, rinfo);
if (!rinfo->asleep && rinfo->is_mobility)
OUTPLL(VCLK_ECP_CNTL, vclk_cntl);
return rc;
}
static int radeonfb_setcmap(struct fb_cmap *cmap, struct fb_info *info)
{
struct radeonfb_info *rinfo = info->par;
u16 *red, *green, *blue, *transp;
u32 dac_cntl2, vclk_cntl = 0;
int i, start, rc = 0;
if (!rinfo->asleep) {
if (rinfo->is_mobility) {
vclk_cntl = INPLL(VCLK_ECP_CNTL);
OUTPLL(VCLK_ECP_CNTL,
vclk_cntl & ~PIXCLK_DAC_ALWAYS_ONb);
}
if (rinfo->has_CRTC2) {
dac_cntl2 = INREG(DAC_CNTL2);
dac_cntl2 &= ~DAC2_PALETTE_ACCESS_CNTL;
OUTREG(DAC_CNTL2, dac_cntl2);
}
}
red = cmap->red;
green = cmap->green;
blue = cmap->blue;
transp = cmap->transp;
start = cmap->start;
for (i = 0; i < cmap->len; i++) {
u_int hred, hgreen, hblue, htransp = 0xffff;
hred = *red++;
hgreen = *green++;
hblue = *blue++;
if (transp)
htransp = *transp++;
rc = radeon_setcolreg (start++, hred, hgreen, hblue, htransp,
rinfo);
if (rc)
break;
}
if (!rinfo->asleep && rinfo->is_mobility)
OUTPLL(VCLK_ECP_CNTL, vclk_cntl);
return rc;
}
static void radeon_save_state (struct radeonfb_info *rinfo,
struct radeon_regs *save)
{
save->crtc_gen_cntl = INREG(CRTC_GEN_CNTL);
save->crtc_ext_cntl = INREG(CRTC_EXT_CNTL);
save->crtc_more_cntl = INREG(CRTC_MORE_CNTL);
save->dac_cntl = INREG(DAC_CNTL);
save->crtc_h_total_disp = INREG(CRTC_H_TOTAL_DISP);
save->crtc_h_sync_strt_wid = INREG(CRTC_H_SYNC_STRT_WID);
save->crtc_v_total_disp = INREG(CRTC_V_TOTAL_DISP);
save->crtc_v_sync_strt_wid = INREG(CRTC_V_SYNC_STRT_WID);
save->crtc_pitch = INREG(CRTC_PITCH);
save->surface_cntl = INREG(SURFACE_CNTL);
save->fp_crtc_h_total_disp = INREG(FP_CRTC_H_TOTAL_DISP);
save->fp_crtc_v_total_disp = INREG(FP_CRTC_V_TOTAL_DISP);
save->fp_gen_cntl = INREG(FP_GEN_CNTL);
save->fp_h_sync_strt_wid = INREG(FP_H_SYNC_STRT_WID);
save->fp_horz_stretch = INREG(FP_HORZ_STRETCH);
save->fp_v_sync_strt_wid = INREG(FP_V_SYNC_STRT_WID);
save->fp_vert_stretch = INREG(FP_VERT_STRETCH);
save->lvds_gen_cntl = INREG(LVDS_GEN_CNTL);
save->lvds_pll_cntl = INREG(LVDS_PLL_CNTL);
save->tmds_crc = INREG(TMDS_CRC);
save->tmds_transmitter_cntl = INREG(TMDS_TRANSMITTER_CNTL);
save->vclk_ecp_cntl = INPLL(VCLK_ECP_CNTL);
save->clk_cntl_index = INREG(CLOCK_CNTL_INDEX) & ~0x3f;
radeon_pll_errata_after_index(rinfo);
save->ppll_div_3 = INPLL(PPLL_DIV_3);
save->ppll_ref_div = INPLL(PPLL_REF_DIV);
}
static void radeon_write_pll_regs(struct radeonfb_info *rinfo, struct radeon_regs *mode)
{
int i;
radeon_fifo_wait(20);
if (rinfo->is_mobility) {
if ((mode->ppll_ref_div == (INPLL(PPLL_REF_DIV) & PPLL_REF_DIV_MASK)) &&
(mode->ppll_div_3 == (INPLL(PPLL_DIV_3) &
(PPLL_POST3_DIV_MASK | PPLL_FB3_DIV_MASK)))) {
OUTREGP(CLOCK_CNTL_INDEX,
mode->clk_cntl_index & PPLL_DIV_SEL_MASK,
~PPLL_DIV_SEL_MASK);
radeon_pll_errata_after_index(rinfo);
radeon_pll_errata_after_data(rinfo);
return;
}
}
OUTPLLP(VCLK_ECP_CNTL, VCLK_SRC_SEL_CPUCLK, ~VCLK_SRC_SEL_MASK);
OUTPLLP(PPLL_CNTL,
PPLL_RESET | PPLL_ATOMIC_UPDATE_EN | PPLL_VGA_ATOMIC_UPDATE_EN,
~(PPLL_RESET | PPLL_ATOMIC_UPDATE_EN | PPLL_VGA_ATOMIC_UPDATE_EN));
OUTREGP(CLOCK_CNTL_INDEX,
mode->clk_cntl_index & PPLL_DIV_SEL_MASK,
~PPLL_DIV_SEL_MASK);
radeon_pll_errata_after_index(rinfo);
radeon_pll_errata_after_data(rinfo);
if (IS_R300_VARIANT(rinfo) ||
rinfo->family == CHIP_FAMILY_RS300 ||
rinfo->family == CHIP_FAMILY_RS400 ||
rinfo->family == CHIP_FAMILY_RS480) {
if (mode->ppll_ref_div & R300_PPLL_REF_DIV_ACC_MASK) {
OUTPLLP(PPLL_REF_DIV, mode->ppll_ref_div, 0);
} else {
OUTPLLP(PPLL_REF_DIV,
(mode->ppll_ref_div << R300_PPLL_REF_DIV_ACC_SHIFT),
~R300_PPLL_REF_DIV_ACC_MASK);
}
} else
OUTPLLP(PPLL_REF_DIV, mode->ppll_ref_div, ~PPLL_REF_DIV_MASK);
OUTPLLP(PPLL_DIV_3, mode->ppll_div_3, ~PPLL_FB3_DIV_MASK);
OUTPLLP(PPLL_DIV_3, mode->ppll_div_3, ~PPLL_POST3_DIV_MASK);
while (INPLL(PPLL_REF_DIV) & PPLL_ATOMIC_UPDATE_R)
;
OUTPLLP(PPLL_REF_DIV, PPLL_ATOMIC_UPDATE_W, ~PPLL_ATOMIC_UPDATE_W);
for (i = 0; (i < 10000 && INPLL(PPLL_REF_DIV) & PPLL_ATOMIC_UPDATE_R); i++)
;
OUTPLL(HTOTAL_CNTL, 0);
OUTPLLP(PPLL_CNTL, 0,
~(PPLL_RESET | PPLL_SLEEP | PPLL_ATOMIC_UPDATE_EN | PPLL_VGA_ATOMIC_UPDATE_EN));
radeon_msleep(5);
OUTPLLP(VCLK_ECP_CNTL, VCLK_SRC_SEL_PPLLCLK, ~VCLK_SRC_SEL_MASK);
}
static void radeon_lvds_timer_func(unsigned long data)
{
struct radeonfb_info *rinfo = (struct radeonfb_info *)data;
radeon_engine_idle();
OUTREG(LVDS_GEN_CNTL, rinfo->pending_lvds_gen_cntl);
}
void radeon_write_mode (struct radeonfb_info *rinfo, struct radeon_regs *mode,
int regs_only)
{
int i;
int primary_mon = PRIMARY_MONITOR(rinfo);
if (nomodeset)
return;
if (!regs_only)
radeon_screen_blank(rinfo, FB_BLANK_NORMAL, 0);
radeon_fifo_wait(31);
for (i=0; i<10; i++)
OUTREG(common_regs[i].reg, common_regs[i].val);
for (i=0; i<8; i++) {
OUTREG(SURFACE0_LOWER_BOUND + 0x10*i, mode->surf_lower_bound[i]);
OUTREG(SURFACE0_UPPER_BOUND + 0x10*i, mode->surf_upper_bound[i]);
OUTREG(SURFACE0_INFO + 0x10*i, mode->surf_info[i]);
}
OUTREG(CRTC_GEN_CNTL, mode->crtc_gen_cntl);
OUTREGP(CRTC_EXT_CNTL, mode->crtc_ext_cntl,
~(CRTC_HSYNC_DIS | CRTC_VSYNC_DIS | CRTC_DISPLAY_DIS));
OUTREG(CRTC_MORE_CNTL, mode->crtc_more_cntl);
OUTREGP(DAC_CNTL, mode->dac_cntl, DAC_RANGE_CNTL | DAC_BLANKING);
OUTREG(CRTC_H_TOTAL_DISP, mode->crtc_h_total_disp);
OUTREG(CRTC_H_SYNC_STRT_WID, mode->crtc_h_sync_strt_wid);
OUTREG(CRTC_V_TOTAL_DISP, mode->crtc_v_total_disp);
OUTREG(CRTC_V_SYNC_STRT_WID, mode->crtc_v_sync_strt_wid);
OUTREG(CRTC_OFFSET, 0);
OUTREG(CRTC_OFFSET_CNTL, 0);
OUTREG(CRTC_PITCH, mode->crtc_pitch);
OUTREG(SURFACE_CNTL, mode->surface_cntl);
radeon_write_pll_regs(rinfo, mode);
if ((primary_mon == MT_DFP) || (primary_mon == MT_LCD)) {
radeon_fifo_wait(10);
OUTREG(FP_CRTC_H_TOTAL_DISP, mode->fp_crtc_h_total_disp);
OUTREG(FP_CRTC_V_TOTAL_DISP, mode->fp_crtc_v_total_disp);
OUTREG(FP_H_SYNC_STRT_WID, mode->fp_h_sync_strt_wid);
OUTREG(FP_V_SYNC_STRT_WID, mode->fp_v_sync_strt_wid);
OUTREG(FP_HORZ_STRETCH, mode->fp_horz_stretch);
OUTREG(FP_VERT_STRETCH, mode->fp_vert_stretch);
OUTREG(FP_GEN_CNTL, mode->fp_gen_cntl);
OUTREG(TMDS_CRC, mode->tmds_crc);
OUTREG(TMDS_TRANSMITTER_CNTL, mode->tmds_transmitter_cntl);
}
if (!regs_only)
radeon_screen_blank(rinfo, FB_BLANK_UNBLANK, 0);
radeon_fifo_wait(2);
OUTPLL(VCLK_ECP_CNTL, mode->vclk_ecp_cntl);
return;
}
static void radeon_calc_pll_regs(struct radeonfb_info *rinfo, struct radeon_regs *regs,
unsigned long freq)
{
const struct {
int divider;
int bitvalue;
} *post_div,
post_divs[] = {
{ 1, 0 },
{ 2, 1 },
{ 4, 2 },
{ 8, 3 },
{ 3, 4 },
{ 16, 5 },
{ 6, 6 },
{ 12, 7 },
{ 0, 0 },
};
int fb_div, pll_output_freq = 0;
int uses_dvo = 0;
#if 1
while (rinfo->has_CRTC2) {
u32 fp2_gen_cntl = INREG(FP2_GEN_CNTL);
u32 disp_output_cntl;
int source;
if ((fp2_gen_cntl & FP2_ON) == 0)
break;
if (rinfo->family == CHIP_FAMILY_R200 || IS_R300_VARIANT(rinfo)) {
source = (fp2_gen_cntl >> 10) & 0x3;
if (source == 3) {
disp_output_cntl = INREG(DISP_OUTPUT_CNTL);
source = (disp_output_cntl >> 12) & 0x3;
}
} else
source = (fp2_gen_cntl >> 13) & 0x1;
if (source == 1)
break;
uses_dvo = 1;
break;
}
#else
uses_dvo = 1;
#endif
if (freq > rinfo->pll.ppll_max)
freq = rinfo->pll.ppll_max;
if (freq*12 < rinfo->pll.ppll_min)
freq = rinfo->pll.ppll_min / 12;
pr_debug("freq = %lu, PLL min = %u, PLL max = %u\n",
freq, rinfo->pll.ppll_min, rinfo->pll.ppll_max);
for (post_div = &post_divs[0]; post_div->divider; ++post_div) {
pll_output_freq = post_div->divider * freq;
if (uses_dvo && (post_div->divider & 1))
continue;
if (pll_output_freq >= rinfo->pll.ppll_min &&
pll_output_freq <= rinfo->pll.ppll_max)
break;
}
if ( !post_div->divider ) {
post_div = &post_divs[post_div->bitvalue];
pll_output_freq = post_div->divider * freq;
}
pr_debug("ref_div = %d, ref_clk = %d, output_freq = %d\n",
rinfo->pll.ref_div, rinfo->pll.ref_clk,
pll_output_freq);
if ( !post_div->divider ) {
post_div = &post_divs[post_div->bitvalue];
pll_output_freq = post_div->divider * freq;
}
pr_debug("ref_div = %d, ref_clk = %d, output_freq = %d\n",
rinfo->pll.ref_div, rinfo->pll.ref_clk,
pll_output_freq);
fb_div = round_div(rinfo->pll.ref_div*pll_output_freq,
rinfo->pll.ref_clk);
regs->ppll_ref_div = rinfo->pll.ref_div;
regs->ppll_div_3 = fb_div | (post_div->bitvalue << 16);
pr_debug("post div = 0x%x\n", post_div->bitvalue);
pr_debug("fb_div = 0x%x\n", fb_div);
pr_debug("ppll_div_3 = 0x%x\n", regs->ppll_div_3);
}
static int radeonfb_set_par(struct fb_info *info)
{
struct radeonfb_info *rinfo = info->par;
struct fb_var_screeninfo *mode = &info->var;
struct radeon_regs *newmode;
int hTotal, vTotal, hSyncStart, hSyncEnd,
hSyncPol, vSyncStart, vSyncEnd, vSyncPol, cSync;
u8 hsync_adj_tab[] = {0, 0x12, 9, 9, 6, 5};
u8 hsync_fudge_fp[] = {2, 2, 0, 0, 5, 5};
u32 sync, h_sync_pol, v_sync_pol, dotClock, pixClock;
int i, freq;
int format = 0;
int nopllcalc = 0;
int hsync_start, hsync_fudge, bytpp, hsync_wid, vsync_wid;
int primary_mon = PRIMARY_MONITOR(rinfo);
int depth = var_to_depth(mode);
int use_rmx = 0;
newmode = kmalloc(sizeof(struct radeon_regs), GFP_KERNEL);
if (!newmode)
return -ENOMEM;
radeon_engine_idle();
hSyncStart = mode->xres + mode->right_margin;
hSyncEnd = hSyncStart + mode->hsync_len;
hTotal = hSyncEnd + mode->left_margin;
vSyncStart = mode->yres + mode->lower_margin;
vSyncEnd = vSyncStart + mode->vsync_len;
vTotal = vSyncEnd + mode->upper_margin;
pixClock = mode->pixclock;
sync = mode->sync;
h_sync_pol = sync & FB_SYNC_HOR_HIGH_ACT ? 0 : 1;
v_sync_pol = sync & FB_SYNC_VERT_HIGH_ACT ? 0 : 1;
if (primary_mon == MT_DFP || primary_mon == MT_LCD) {
if (rinfo->panel_info.xres < mode->xres)
mode->xres = rinfo->panel_info.xres;
if (rinfo->panel_info.yres < mode->yres)
mode->yres = rinfo->panel_info.yres;
hTotal = mode->xres + rinfo->panel_info.hblank;
hSyncStart = mode->xres + rinfo->panel_info.hOver_plus;
hSyncEnd = hSyncStart + rinfo->panel_info.hSync_width;
vTotal = mode->yres + rinfo->panel_info.vblank;
vSyncStart = mode->yres + rinfo->panel_info.vOver_plus;
vSyncEnd = vSyncStart + rinfo->panel_info.vSync_width;
h_sync_pol = !rinfo->panel_info.hAct_high;
v_sync_pol = !rinfo->panel_info.vAct_high;
pixClock = 100000000 / rinfo->panel_info.clock;
if (rinfo->panel_info.use_bios_dividers) {
nopllcalc = 1;
newmode->ppll_div_3 = rinfo->panel_info.fbk_divider |
(rinfo->panel_info.post_divider << 16);
newmode->ppll_ref_div = rinfo->panel_info.ref_divider;
}
}
dotClock = 1000000000 / pixClock;
freq = dotClock / 10;
pr_debug("hStart = %d, hEnd = %d, hTotal = %d\n",
hSyncStart, hSyncEnd, hTotal);
pr_debug("vStart = %d, vEnd = %d, vTotal = %d\n",
vSyncStart, vSyncEnd, vTotal);
hsync_wid = (hSyncEnd - hSyncStart) / 8;
vsync_wid = vSyncEnd - vSyncStart;
if (hsync_wid == 0)
hsync_wid = 1;
else if (hsync_wid > 0x3f)
hsync_wid = 0x3f;
if (vsync_wid == 0)
vsync_wid = 1;
else if (vsync_wid > 0x1f)
vsync_wid = 0x1f;
hSyncPol = mode->sync & FB_SYNC_HOR_HIGH_ACT ? 0 : 1;
vSyncPol = mode->sync & FB_SYNC_VERT_HIGH_ACT ? 0 : 1;
cSync = mode->sync & FB_SYNC_COMP_HIGH_ACT ? (1 << 4) : 0;
format = radeon_get_dstbpp(depth);
bytpp = mode->bits_per_pixel >> 3;
if ((primary_mon == MT_DFP) || (primary_mon == MT_LCD))
hsync_fudge = hsync_fudge_fp[format-1];
else
hsync_fudge = hsync_adj_tab[format-1];
hsync_start = hSyncStart - 8 + hsync_fudge;
newmode->crtc_gen_cntl = CRTC_EXT_DISP_EN | CRTC_EN |
(format << 8);
newmode->crtc_more_cntl = rinfo->init_state.crtc_more_cntl;
newmode->crtc_more_cntl &= 0xfffffff0;
if ((primary_mon == MT_DFP) || (primary_mon == MT_LCD)) {
newmode->crtc_ext_cntl = VGA_ATI_LINEAR | XCRT_CNT_EN;
if (mirror)
newmode->crtc_ext_cntl |= CRTC_CRT_ON;
newmode->crtc_gen_cntl &= ~(CRTC_DBL_SCAN_EN |
CRTC_INTERLACE_EN);
} else {
newmode->crtc_ext_cntl = VGA_ATI_LINEAR | XCRT_CNT_EN |
CRTC_CRT_ON;
}
newmode->dac_cntl = DAC_MASK_ALL | DAC_VGA_ADR_EN |
DAC_8BIT_EN;
newmode->crtc_h_total_disp = ((((hTotal / 8) - 1) & 0x3ff) |
(((mode->xres / 8) - 1) << 16));
newmode->crtc_h_sync_strt_wid = ((hsync_start & 0x1fff) |
(hsync_wid << 16) | (h_sync_pol << 23));
newmode->crtc_v_total_disp = ((vTotal - 1) & 0xffff) |
((mode->yres - 1) << 16);
newmode->crtc_v_sync_strt_wid = (((vSyncStart - 1) & 0xfff) |
(vsync_wid << 16) | (v_sync_pol << 23));
if (!(info->flags & FBINFO_HWACCEL_DISABLED)) {
rinfo->pitch = ((mode->xres_virtual * ((mode->bits_per_pixel + 1) / 8) + 0x3f)
& ~(0x3f)) >> 6;
newmode->crtc_pitch = (rinfo->pitch << 3) / ((mode->bits_per_pixel + 1) / 8);
} else
newmode->crtc_pitch = (mode->xres_virtual >> 3);
newmode->crtc_pitch |= (newmode->crtc_pitch << 16);
newmode->surface_cntl = 0;
#if defined(__BIG_ENDIAN)
switch (mode->bits_per_pixel) {
case 16:
newmode->surface_cntl |= NONSURF_AP0_SWP_16BPP;
newmode->surface_cntl |= NONSURF_AP1_SWP_16BPP;
break;
case 24:
case 32:
newmode->surface_cntl |= NONSURF_AP0_SWP_32BPP;
newmode->surface_cntl |= NONSURF_AP1_SWP_32BPP;
break;
}
#endif
for (i=0; i<8; i++) {
newmode->surf_lower_bound[i] = 0;
newmode->surf_upper_bound[i] = 0x1f;
newmode->surf_info[i] = 0;
}
pr_debug("h_total_disp = 0x%x\t hsync_strt_wid = 0x%x\n",
newmode->crtc_h_total_disp, newmode->crtc_h_sync_strt_wid);
pr_debug("v_total_disp = 0x%x\t vsync_strt_wid = 0x%x\n",
newmode->crtc_v_total_disp, newmode->crtc_v_sync_strt_wid);
rinfo->bpp = mode->bits_per_pixel;
rinfo->depth = depth;
pr_debug("pixclock = %lu\n", (unsigned long)pixClock);
pr_debug("freq = %lu\n", (unsigned long)freq);
newmode->clk_cntl_index = 0x300;
if (!nopllcalc)
radeon_calc_pll_regs(rinfo, newmode, freq);
newmode->vclk_ecp_cntl = rinfo->init_state.vclk_ecp_cntl;
if ((primary_mon == MT_DFP) || (primary_mon == MT_LCD)) {
unsigned int hRatio, vRatio;
if (mode->xres > rinfo->panel_info.xres)
mode->xres = rinfo->panel_info.xres;
if (mode->yres > rinfo->panel_info.yres)
mode->yres = rinfo->panel_info.yres;
newmode->fp_horz_stretch = (((rinfo->panel_info.xres / 8) - 1)
<< HORZ_PANEL_SHIFT);
newmode->fp_vert_stretch = ((rinfo->panel_info.yres - 1)
<< VERT_PANEL_SHIFT);
if (mode->xres != rinfo->panel_info.xres) {
hRatio = round_div(mode->xres * HORZ_STRETCH_RATIO_MAX,
rinfo->panel_info.xres);
newmode->fp_horz_stretch = (((((unsigned long)hRatio) & HORZ_STRETCH_RATIO_MASK)) |
(newmode->fp_horz_stretch &
(HORZ_PANEL_SIZE | HORZ_FP_LOOP_STRETCH |
HORZ_AUTO_RATIO_INC)));
newmode->fp_horz_stretch |= (HORZ_STRETCH_BLEND |
HORZ_STRETCH_ENABLE);
use_rmx = 1;
}
newmode->fp_horz_stretch &= ~HORZ_AUTO_RATIO;
if (mode->yres != rinfo->panel_info.yres) {
vRatio = round_div(mode->yres * VERT_STRETCH_RATIO_MAX,
rinfo->panel_info.yres);
newmode->fp_vert_stretch = (((((unsigned long)vRatio) & VERT_STRETCH_RATIO_MASK)) |
(newmode->fp_vert_stretch &
(VERT_PANEL_SIZE | VERT_STRETCH_RESERVED)));
newmode->fp_vert_stretch |= (VERT_STRETCH_BLEND |
VERT_STRETCH_ENABLE);
use_rmx = 1;
}
newmode->fp_vert_stretch &= ~VERT_AUTO_RATIO_EN;
newmode->fp_gen_cntl = (rinfo->init_state.fp_gen_cntl & (u32)
~(FP_SEL_CRTC2 |
FP_RMX_HVSYNC_CONTROL_EN |
FP_DFP_SYNC_SEL |
FP_CRT_SYNC_SEL |
FP_CRTC_LOCK_8DOT |
FP_USE_SHADOW_EN |
FP_CRTC_USE_SHADOW_VEND |
FP_CRT_SYNC_ALT));
newmode->fp_gen_cntl |= (FP_CRTC_DONT_SHADOW_VPAR |
FP_CRTC_DONT_SHADOW_HEND |
FP_PANEL_FORMAT);
if (IS_R300_VARIANT(rinfo) ||
(rinfo->family == CHIP_FAMILY_R200)) {
newmode->fp_gen_cntl &= ~R200_FP_SOURCE_SEL_MASK;
if (use_rmx)
newmode->fp_gen_cntl |= R200_FP_SOURCE_SEL_RMX;
else
newmode->fp_gen_cntl |= R200_FP_SOURCE_SEL_CRTC1;
} else
newmode->fp_gen_cntl |= FP_SEL_CRTC1;
newmode->lvds_gen_cntl = rinfo->init_state.lvds_gen_cntl;
newmode->lvds_pll_cntl = rinfo->init_state.lvds_pll_cntl;
newmode->tmds_crc = rinfo->init_state.tmds_crc;
newmode->tmds_transmitter_cntl = rinfo->init_state.tmds_transmitter_cntl;
if (primary_mon == MT_LCD) {
newmode->lvds_gen_cntl |= (LVDS_ON | LVDS_BLON);
newmode->fp_gen_cntl &= ~(FP_FPON | FP_TMDS_EN);
} else {
newmode->fp_gen_cntl |= (FP_FPON | FP_TMDS_EN);
newmode->tmds_transmitter_cntl &= ~(TMDS_PLLRST);
if (IS_R300_VARIANT(rinfo) ||
(rinfo->family == CHIP_FAMILY_R200) || !rinfo->has_CRTC2)
newmode->tmds_transmitter_cntl &= ~TMDS_PLL_EN;
else
newmode->tmds_transmitter_cntl |= TMDS_PLL_EN;
newmode->crtc_ext_cntl &= ~CRTC_CRT_ON;
}
newmode->fp_crtc_h_total_disp = (((rinfo->panel_info.hblank / 8) & 0x3ff) |
(((mode->xres / 8) - 1) << 16));
newmode->fp_crtc_v_total_disp = (rinfo->panel_info.vblank & 0xffff) |
((mode->yres - 1) << 16);
newmode->fp_h_sync_strt_wid = ((rinfo->panel_info.hOver_plus & 0x1fff) |
(hsync_wid << 16) | (h_sync_pol << 23));
newmode->fp_v_sync_strt_wid = ((rinfo->panel_info.vOver_plus & 0xfff) |
(vsync_wid << 16) | (v_sync_pol << 23));
}
if (!rinfo->asleep) {
memcpy(&rinfo->state, newmode, sizeof(*newmode));
radeon_write_mode (rinfo, newmode, 0);
if (!(info->flags & FBINFO_HWACCEL_DISABLED))
radeonfb_engine_init (rinfo);
}
if (!(info->flags & FBINFO_HWACCEL_DISABLED))
info->fix.line_length = rinfo->pitch*64;
else
info->fix.line_length = mode->xres_virtual
* ((mode->bits_per_pixel + 1) / 8);
info->fix.visual = rinfo->depth == 8 ? FB_VISUAL_PSEUDOCOLOR
: FB_VISUAL_DIRECTCOLOR;
#ifdef CONFIG_BOOTX_TEXT
btext_update_display(rinfo->fb_base_phys, mode->xres, mode->yres,
rinfo->depth, info->fix.line_length);
#endif
kfree(newmode);
return 0;
}
static int __devinit radeon_set_fbinfo (struct radeonfb_info *rinfo)
{
struct fb_info *info = rinfo->info;
info->par = rinfo;
info->pseudo_palette = rinfo->pseudo_palette;
info->flags = FBINFO_DEFAULT
| FBINFO_HWACCEL_COPYAREA
| FBINFO_HWACCEL_FILLRECT
| FBINFO_HWACCEL_XPAN
| FBINFO_HWACCEL_YPAN;
info->fbops = &radeonfb_ops;
info->screen_base = rinfo->fb_base;
info->screen_size = rinfo->mapped_vram;
strlcpy(info->fix.id, rinfo->name, sizeof(info->fix.id));
info->fix.smem_start = rinfo->fb_base_phys;
info->fix.smem_len = rinfo->video_ram;
info->fix.type = FB_TYPE_PACKED_PIXELS;
info->fix.visual = FB_VISUAL_PSEUDOCOLOR;
info->fix.xpanstep = 8;
info->fix.ypanstep = 1;
info->fix.ywrapstep = 0;
info->fix.type_aux = 0;
info->fix.mmio_start = rinfo->mmio_base_phys;
info->fix.mmio_len = RADEON_REGSIZE;
info->fix.accel = FB_ACCEL_ATI_RADEON;
fb_alloc_cmap(&info->cmap, 256, 0);
if (noaccel)
info->flags |= FBINFO_HWACCEL_DISABLED;
return 0;
}
static void fixup_memory_mappings(struct radeonfb_info *rinfo)
{
u32 save_crtc_gen_cntl, save_crtc2_gen_cntl = 0;
u32 save_crtc_ext_cntl;
u32 aper_base, aper_size;
u32 agp_base;
if (rinfo->has_CRTC2) {
save_crtc2_gen_cntl = INREG(CRTC2_GEN_CNTL);
OUTREG(CRTC2_GEN_CNTL, save_crtc2_gen_cntl | CRTC2_DISP_REQ_EN_B);
}
save_crtc_gen_cntl = INREG(CRTC_GEN_CNTL);
save_crtc_ext_cntl = INREG(CRTC_EXT_CNTL);
OUTREG(CRTC_EXT_CNTL, save_crtc_ext_cntl | CRTC_DISPLAY_DIS);
OUTREG(CRTC_GEN_CNTL, save_crtc_gen_cntl | CRTC_DISP_REQ_EN_B);
mdelay(100);
aper_base = INREG(CNFG_APER_0_BASE);
aper_size = INREG(CNFG_APER_SIZE);
#ifdef SET_MC_FB_FROM_APERTURE
OUTREG(MC_FB_LOCATION,
((aper_base + aper_size - 1) & 0xffff0000) | (aper_base >> 16));
rinfo->fb_local_base = aper_base;
#else
OUTREG(MC_FB_LOCATION, 0x7fff0000);
rinfo->fb_local_base = 0;
#endif
agp_base = aper_base + aper_size;
if (agp_base & 0xf0000000)
agp_base = (aper_base | 0x0fffffff) + 1;
#ifdef SET_MC_FB_FROM_APERTURE
OUTREG(MC_AGP_LOCATION, 0xffff0000 | (agp_base >> 16));
#else
OUTREG(MC_AGP_LOCATION, 0xffffe000);
#endif
#ifdef SET_MC_FB_FROM_APERTURE
OUTREG(DISPLAY_BASE_ADDR, aper_base);
if (rinfo->has_CRTC2)
OUTREG(CRTC2_DISPLAY_BASE_ADDR, aper_base);
OUTREG(OV0_BASE_ADDR, aper_base);
#else
OUTREG(DISPLAY_BASE_ADDR, 0);
if (rinfo->has_CRTC2)
OUTREG(CRTC2_DISPLAY_BASE_ADDR, 0);
OUTREG(OV0_BASE_ADDR, 0);
#endif
mdelay(100);
OUTREG(CRTC_GEN_CNTL, save_crtc_gen_cntl);
OUTREG(CRTC_EXT_CNTL, save_crtc_ext_cntl);
if (rinfo->has_CRTC2)
OUTREG(CRTC2_GEN_CNTL, save_crtc2_gen_cntl);
pr_debug("aper_base: %08x MC_FB_LOC to: %08x, MC_AGP_LOC to: %08x\n",
aper_base,
((aper_base + aper_size - 1) & 0xffff0000) | (aper_base >> 16),
0xffff0000 | (agp_base >> 16));
}
static void radeon_identify_vram(struct radeonfb_info *rinfo)
{
u32 tmp;
if ((rinfo->family == CHIP_FAMILY_RS100) ||
(rinfo->family == CHIP_FAMILY_RS200) ||
(rinfo->family == CHIP_FAMILY_RS300) ||
(rinfo->family == CHIP_FAMILY_RC410) ||
(rinfo->family == CHIP_FAMILY_RS400) ||
(rinfo->family == CHIP_FAMILY_RS480) ) {
u32 tom = INREG(NB_TOM);
tmp = ((((tom >> 16) - (tom & 0xffff) + 1) << 6) * 1024);
radeon_fifo_wait(6);
OUTREG(MC_FB_LOCATION, tom);
OUTREG(DISPLAY_BASE_ADDR, (tom & 0xffff) << 16);
OUTREG(CRTC2_DISPLAY_BASE_ADDR, (tom & 0xffff) << 16);
OUTREG(OV0_BASE_ADDR, (tom & 0xffff) << 16);
OUTREG(GRPH2_BUFFER_CNTL, INREG(GRPH2_BUFFER_CNTL) & ~0x7f0000);
if ((rinfo->family == CHIP_FAMILY_RS100) ||
(rinfo->family == CHIP_FAMILY_RS200)) {
OUTREGP(CRTC_MORE_CNTL, CRTC_H_CUTOFF_ACTIVE_EN,
~CRTC_H_CUTOFF_ACTIVE_EN);
}
} else {
tmp = INREG(CNFG_MEMSIZE);
}
rinfo->video_ram = tmp & CNFG_MEMSIZE_MASK;
if (rinfo->video_ram == 0) {
switch (rinfo->pdev->device) {
case PCI_CHIP_RADEON_LY:
case PCI_CHIP_RADEON_LZ:
rinfo->video_ram = 8192 * 1024;
break;
default:
break;
}
}
if (rinfo->is_IGP || (rinfo->family >= CHIP_FAMILY_R300) ||
(INREG(MEM_SDRAM_MODE_REG) & (1<<30)))
rinfo->vram_ddr = 1;
else
rinfo->vram_ddr = 0;
tmp = INREG(MEM_CNTL);
if (IS_R300_VARIANT(rinfo)) {
tmp &= R300_MEM_NUM_CHANNELS_MASK;
switch (tmp) {
case 0: rinfo->vram_width = 64; break;
case 1: rinfo->vram_width = 128; break;
case 2: rinfo->vram_width = 256; break;
default: rinfo->vram_width = 128; break;
}
} else if ((rinfo->family == CHIP_FAMILY_RV100) ||
(rinfo->family == CHIP_FAMILY_RS100) ||
(rinfo->family == CHIP_FAMILY_RS200)){
if (tmp & RV100_MEM_HALF_MODE)
rinfo->vram_width = 32;
else
rinfo->vram_width = 64;
} else {
if (tmp & MEM_NUM_CHANNELS_MASK)
rinfo->vram_width = 128;
else
rinfo->vram_width = 64;
}
pr_debug("radeonfb (%s): Found %ldk of %s %d bits wide videoram\n",
pci_name(rinfo->pdev),
rinfo->video_ram / 1024,
rinfo->vram_ddr ? "DDR" : "SDRAM",
rinfo->vram_width);
}
static ssize_t radeon_show_one_edid(char *buf, loff_t off, size_t count, const u8 *edid)
{
return memory_read_from_buffer(buf, count, &off, edid, EDID_LENGTH);
}
static ssize_t radeon_show_edid1(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct pci_dev *pdev = to_pci_dev(dev);
struct fb_info *info = pci_get_drvdata(pdev);
struct radeonfb_info *rinfo = info->par;
return radeon_show_one_edid(buf, off, count, rinfo->mon1_EDID);
}
static ssize_t radeon_show_edid2(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct pci_dev *pdev = to_pci_dev(dev);
struct fb_info *info = pci_get_drvdata(pdev);
struct radeonfb_info *rinfo = info->par;
return radeon_show_one_edid(buf, off, count, rinfo->mon2_EDID);
}
static int __devinit radeonfb_pci_register (struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct fb_info *info;
struct radeonfb_info *rinfo;
int ret;
unsigned char c1, c2;
int err = 0;
pr_debug("radeonfb_pci_register BEGIN\n");
ret = pci_enable_device(pdev);
if (ret < 0) {
printk(KERN_ERR "radeonfb (%s): Cannot enable PCI device\n",
pci_name(pdev));
goto err_out;
}
info = framebuffer_alloc(sizeof(struct radeonfb_info), &pdev->dev);
if (!info) {
printk (KERN_ERR "radeonfb (%s): could not allocate memory\n",
pci_name(pdev));
ret = -ENOMEM;
goto err_disable;
}
rinfo = info->par;
rinfo->info = info;
rinfo->pdev = pdev;
spin_lock_init(&rinfo->reg_lock);
init_timer(&rinfo->lvds_timer);
rinfo->lvds_timer.function = radeon_lvds_timer_func;
rinfo->lvds_timer.data = (unsigned long)rinfo;
c1 = ent->device >> 8;
c2 = ent->device & 0xff;
if (isprint(c1) && isprint(c2))
snprintf(rinfo->name, sizeof(rinfo->name),
"ATI Radeon %x \"%c%c\"", ent->device & 0xffff, c1, c2);
else
snprintf(rinfo->name, sizeof(rinfo->name),
"ATI Radeon %x", ent->device & 0xffff);
rinfo->family = ent->driver_data & CHIP_FAMILY_MASK;
rinfo->chipset = pdev->device;
rinfo->has_CRTC2 = (ent->driver_data & CHIP_HAS_CRTC2) != 0;
rinfo->is_mobility = (ent->driver_data & CHIP_IS_MOBILITY) != 0;
rinfo->is_IGP = (ent->driver_data & CHIP_IS_IGP) != 0;
rinfo->fb_base_phys = pci_resource_start (pdev, 0);
rinfo->mmio_base_phys = pci_resource_start (pdev, 2);
ret = pci_request_region(pdev, 0, "radeonfb framebuffer");
if (ret < 0) {
printk( KERN_ERR "radeonfb (%s): cannot request region 0.\n",
pci_name(rinfo->pdev));
goto err_release_fb;
}
ret = pci_request_region(pdev, 2, "radeonfb mmio");
if (ret < 0) {
printk( KERN_ERR "radeonfb (%s): cannot request region 2.\n",
pci_name(rinfo->pdev));
goto err_release_pci0;
}
rinfo->mmio_base = ioremap(rinfo->mmio_base_phys, RADEON_REGSIZE);
if (!rinfo->mmio_base) {
printk(KERN_ERR "radeonfb (%s): cannot map MMIO\n",
pci_name(rinfo->pdev));
ret = -EIO;
goto err_release_pci2;
}
rinfo->fb_local_base = INREG(MC_FB_LOCATION) << 16;
rinfo->errata = 0;
if (rinfo->family == CHIP_FAMILY_R300 &&
(INREG(CNFG_CNTL) & CFG_ATI_REV_ID_MASK)
== CFG_ATI_REV_A11)
rinfo->errata |= CHIP_ERRATA_R300_CG;
if (rinfo->family == CHIP_FAMILY_RV200 ||
rinfo->family == CHIP_FAMILY_RS200)
rinfo->errata |= CHIP_ERRATA_PLL_DUMMYREADS;
if (rinfo->family == CHIP_FAMILY_RV100 ||
rinfo->family == CHIP_FAMILY_RS100 ||
rinfo->family == CHIP_FAMILY_RS200)
rinfo->errata |= CHIP_ERRATA_PLL_DELAY;
#if defined(CONFIG_PPC_OF) || defined(CONFIG_SPARC)
rinfo->of_node = pci_device_to_OF_node(pdev);
if (rinfo->of_node == NULL)
printk(KERN_WARNING "radeonfb (%s): Cannot match card to OF node !\n",
pci_name(rinfo->pdev));
#endif
#ifdef CONFIG_PPC_OF
fixup_memory_mappings(rinfo);
#endif
radeon_identify_vram(rinfo);
rinfo->mapped_vram = min_t(unsigned long, MAX_MAPPED_VRAM, rinfo->video_ram);
do {
rinfo->fb_base = ioremap (rinfo->fb_base_phys,
rinfo->mapped_vram);
} while (rinfo->fb_base == NULL &&
((rinfo->mapped_vram /= 2) >= MIN_MAPPED_VRAM));
if (rinfo->fb_base == NULL) {
printk (KERN_ERR "radeonfb (%s): cannot map FB\n",
pci_name(rinfo->pdev));
ret = -EIO;
goto err_unmap_rom;
}
pr_debug("radeonfb (%s): mapped %ldk videoram\n", pci_name(rinfo->pdev),
rinfo->mapped_vram/1024);
if (!rinfo->is_mobility)
radeon_map_ROM(rinfo, pdev);
#ifdef CONFIG_X86
if (rinfo->bios_seg == NULL)
radeon_find_mem_vbios(rinfo);
#endif
if (rinfo->bios_seg == NULL && rinfo->is_mobility)
radeon_map_ROM(rinfo, pdev);
radeon_get_pllinfo(rinfo);
#ifdef CONFIG_FB_RADEON_I2C
radeon_create_i2c_busses(rinfo);
#endif
radeon_set_fbinfo (rinfo);
radeon_probe_screens(rinfo, monitor_layout, ignore_edid);
radeon_check_modes(rinfo, mode_option);
if (rinfo->mon1_EDID)
err |= sysfs_create_bin_file(&rinfo->pdev->dev.kobj,
&edid1_attr);
if (rinfo->mon2_EDID)
err |= sysfs_create_bin_file(&rinfo->pdev->dev.kobj,
&edid2_attr);
if (err)
pr_warning("%s() Creating sysfs files failed, continuing\n",
__func__);
radeon_save_state (rinfo, &rinfo->init_state);
memcpy(&rinfo->state, &rinfo->init_state, sizeof(struct radeon_regs));
if (default_dynclk < -1) {
radeonfb_pm_init(rinfo, rinfo->is_mobility ? 1 : -1, ignore_devlist, force_sleep);
} else
radeonfb_pm_init(rinfo, default_dynclk, ignore_devlist, force_sleep);
pci_set_drvdata(pdev, info);
ret = register_framebuffer(info);
if (ret < 0) {
printk (KERN_ERR "radeonfb (%s): could not register framebuffer\n",
pci_name(rinfo->pdev));
goto err_unmap_fb;
}
#ifdef CONFIG_MTRR
rinfo->mtrr_hdl = nomtrr ? -1 : mtrr_add(rinfo->fb_base_phys,
rinfo->video_ram,
MTRR_TYPE_WRCOMB, 1);
#endif
if (backlight)
radeonfb_bl_init(rinfo);
printk ("radeonfb (%s): %s\n", pci_name(rinfo->pdev), rinfo->name);
if (rinfo->bios_seg)
radeon_unmap_ROM(rinfo, pdev);
pr_debug("radeonfb_pci_register END\n");
return 0;
err_unmap_fb:
iounmap(rinfo->fb_base);
err_unmap_rom:
kfree(rinfo->mon1_EDID);
kfree(rinfo->mon2_EDID);
if (rinfo->mon1_modedb)
fb_destroy_modedb(rinfo->mon1_modedb);
fb_dealloc_cmap(&info->cmap);
#ifdef CONFIG_FB_RADEON_I2C
radeon_delete_i2c_busses(rinfo);
#endif
if (rinfo->bios_seg)
radeon_unmap_ROM(rinfo, pdev);
iounmap(rinfo->mmio_base);
err_release_pci2:
pci_release_region(pdev, 2);
err_release_pci0:
pci_release_region(pdev, 0);
err_release_fb:
framebuffer_release(info);
err_disable:
err_out:
return ret;
}
static void __devexit radeonfb_pci_unregister (struct pci_dev *pdev)
{
struct fb_info *info = pci_get_drvdata(pdev);
struct radeonfb_info *rinfo = info->par;
if (!rinfo)
return;
radeonfb_pm_exit(rinfo);
if (rinfo->mon1_EDID)
sysfs_remove_bin_file(&rinfo->pdev->dev.kobj, &edid1_attr);
if (rinfo->mon2_EDID)
sysfs_remove_bin_file(&rinfo->pdev->dev.kobj, &edid2_attr);
#if 0
radeon_write_mode (rinfo, &rinfo->init_state, 1);
#endif
del_timer_sync(&rinfo->lvds_timer);
#ifdef CONFIG_MTRR
if (rinfo->mtrr_hdl >= 0)
mtrr_del(rinfo->mtrr_hdl, 0, 0);
#endif
unregister_framebuffer(info);
radeonfb_bl_exit(rinfo);
iounmap(rinfo->mmio_base);
iounmap(rinfo->fb_base);
pci_release_region(pdev, 2);
pci_release_region(pdev, 0);
kfree(rinfo->mon1_EDID);
kfree(rinfo->mon2_EDID);
if (rinfo->mon1_modedb)
fb_destroy_modedb(rinfo->mon1_modedb);
#ifdef CONFIG_FB_RADEON_I2C
radeon_delete_i2c_busses(rinfo);
#endif
fb_dealloc_cmap(&info->cmap);
framebuffer_release(info);
}
static int __init radeonfb_setup (char *options)
{
char *this_opt;
if (!options || !*options)
return 0;
while ((this_opt = strsep (&options, ",")) != NULL) {
if (!*this_opt)
continue;
if (!strncmp(this_opt, "noaccel", 7)) {
noaccel = 1;
} else if (!strncmp(this_opt, "mirror", 6)) {
mirror = 1;
} else if (!strncmp(this_opt, "force_dfp", 9)) {
force_dfp = 1;
} else if (!strncmp(this_opt, "panel_yres:", 11)) {
panel_yres = simple_strtoul((this_opt+11), NULL, 0);
} else if (!strncmp(this_opt, "backlight:", 10)) {
backlight = simple_strtoul(this_opt+10, NULL, 0);
#ifdef CONFIG_MTRR
} else if (!strncmp(this_opt, "nomtrr", 6)) {
nomtrr = 1;
#endif
} else if (!strncmp(this_opt, "nomodeset", 9)) {
nomodeset = 1;
} else if (!strncmp(this_opt, "force_measure_pll", 17)) {
force_measure_pll = 1;
} else if (!strncmp(this_opt, "ignore_edid", 11)) {
ignore_edid = 1;
#if defined(CONFIG_PM) && defined(CONFIG_X86)
} else if (!strncmp(this_opt, "force_sleep", 11)) {
force_sleep = 1;
} else if (!strncmp(this_opt, "ignore_devlist", 14)) {
ignore_devlist = 1;
#endif
} else
mode_option = this_opt;
}
return 0;
}
static int __init radeonfb_init (void)
{
#ifndef MODULE
char *option = NULL;
if (fb_get_options("radeonfb", &option))
return -ENODEV;
radeonfb_setup(option);
#endif
return pci_register_driver (&radeonfb_driver);
}
static void __exit radeonfb_exit (void)
{
pci_unregister_driver (&radeonfb_driver);
}
