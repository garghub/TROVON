void aty_st_lcd(int index, u32 val, const struct atyfb_par *par)
{
if (M64_HAS(LT_LCD_REGS)) {
aty_st_le32(lt_lcd_regs[index], val, par);
} else {
unsigned long temp;
temp = aty_ld_le32(LCD_INDEX, par);
aty_st_le32(LCD_INDEX, (temp & ~LCD_INDEX_MASK) | index, par);
aty_st_le32(LCD_DATA, val, par);
}
}
u32 aty_ld_lcd(int index, const struct atyfb_par *par)
{
if (M64_HAS(LT_LCD_REGS)) {
return aty_ld_le32(lt_lcd_regs[index], par);
} else {
unsigned long temp;
temp = aty_ld_le32(LCD_INDEX, par);
aty_st_le32(LCD_INDEX, (temp & ~LCD_INDEX_MASK) | index, par);
return aty_ld_le32(LCD_DATA, par);
}
}
static void ATIReduceRatio(int *Numerator, int *Denominator)
{
int Multiplier, Divider, Remainder;
Multiplier = *Numerator;
Divider = *Denominator;
while ((Remainder = Multiplier % Divider)) {
Multiplier = Divider;
Divider = Remainder;
}
*Numerator /= Divider;
*Denominator /= Divider;
}
static int correct_chipset(struct atyfb_par *par)
{
u8 rev;
u16 type;
u32 chip_id;
const char *name;
int i;
for (i = ARRAY_SIZE(aty_chips) - 1; i >= 0; i--)
if (par->pci_id == aty_chips[i].pci_id)
break;
if (i < 0)
return -ENODEV;
name = aty_chips[i].name;
par->pll_limits.pll_max = aty_chips[i].pll;
par->pll_limits.mclk = aty_chips[i].mclk;
par->pll_limits.xclk = aty_chips[i].xclk;
par->pll_limits.ecp_max = aty_chips[i].ecp_max;
par->features = aty_chips[i].features;
chip_id = aty_ld_le32(CNFG_CHIP_ID, par);
type = chip_id & CFG_CHIP_TYPE;
rev = (chip_id & CFG_CHIP_REV) >> 24;
switch (par->pci_id) {
#ifdef CONFIG_FB_ATY_GX
case PCI_CHIP_MACH64GX:
if (type != 0x00d7)
return -ENODEV;
break;
case PCI_CHIP_MACH64CX:
if (type != 0x0057)
return -ENODEV;
break;
#endif
#ifdef CONFIG_FB_ATY_CT
case PCI_CHIP_MACH64VT:
switch (rev & 0x07) {
case 0x00:
switch (rev & 0xc0) {
case 0x00:
name = "ATI264VT (A3) (Mach64 VT)";
par->pll_limits.pll_max = 170;
par->pll_limits.mclk = 67;
par->pll_limits.xclk = 67;
par->pll_limits.ecp_max = 80;
par->features = ATI_CHIP_264VT;
break;
case 0x40:
name = "ATI264VT2 (A4) (Mach64 VT)";
par->pll_limits.pll_max = 200;
par->pll_limits.mclk = 67;
par->pll_limits.xclk = 67;
par->pll_limits.ecp_max = 80;
par->features = ATI_CHIP_264VT | M64F_MAGIC_POSTDIV;
break;
}
break;
case 0x01:
name = "ATI264VT3 (B1) (Mach64 VT)";
par->pll_limits.pll_max = 200;
par->pll_limits.mclk = 67;
par->pll_limits.xclk = 67;
par->pll_limits.ecp_max = 80;
par->features = ATI_CHIP_264VTB;
break;
case 0x02:
name = "ATI264VT3 (B2) (Mach64 VT)";
par->pll_limits.pll_max = 200;
par->pll_limits.mclk = 67;
par->pll_limits.xclk = 67;
par->pll_limits.ecp_max = 80;
par->features = ATI_CHIP_264VT3;
break;
}
break;
case PCI_CHIP_MACH64GT:
switch (rev & 0x07) {
case 0x01:
name = "3D RAGE II (Mach64 GT)";
par->pll_limits.pll_max = 170;
par->pll_limits.mclk = 67;
par->pll_limits.xclk = 67;
par->pll_limits.ecp_max = 80;
par->features = ATI_CHIP_264GTB;
break;
case 0x02:
name = "3D RAGE II+ (Mach64 GT)";
par->pll_limits.pll_max = 200;
par->pll_limits.mclk = 67;
par->pll_limits.xclk = 67;
par->pll_limits.ecp_max = 100;
par->features = ATI_CHIP_264GTB;
break;
}
break;
#endif
}
PRINTKI("%s [0x%04x rev 0x%02x]\n", name, type, rev);
return 0;
}
static u32 atyfb_get_pixclock(struct fb_var_screeninfo *var,
struct atyfb_par *par)
{
u32 pixclock = var->pixclock;
#ifdef CONFIG_FB_ATY_GENERIC_LCD
u32 lcd_on_off;
par->pll.ct.xres = 0;
if (par->lcd_table != 0) {
lcd_on_off = aty_ld_lcd(LCD_GEN_CNTL, par);
if (lcd_on_off & LCD_ON) {
par->pll.ct.xres = var->xres;
pixclock = par->lcd_pixclock;
}
}
#endif
return pixclock;
}
static int read_aty_sense(const struct atyfb_par *par)
{
int sense, i;
aty_st_le32(GP_IO, 0x31003100, par);
__delay(200);
aty_st_le32(GP_IO, 0, par);
__delay(2000);
i = aty_ld_le32(GP_IO, par);
sense = ((i & 0x3000) >> 3) | (i & 0x100);
aty_st_le32(GP_IO, 0x20000000, par);
__delay(2000);
i = aty_ld_le32(GP_IO, par);
sense |= ((i & 0x1000) >> 7) | ((i & 0x100) >> 4);
aty_st_le32(GP_IO, 0x20002000, par);
__delay(200);
aty_st_le32(GP_IO, 0x10000000, par);
__delay(2000);
i = aty_ld_le32(GP_IO, par);
sense |= ((i & 0x2000) >> 10) | ((i & 0x100) >> 6);
aty_st_le32(GP_IO, 0x10001000, par);
__delay(200);
aty_st_le32(GP_IO, 0x01000000, par);
__delay(2000);
sense |= (aty_ld_le32(GP_IO, par) & 0x3000) >> 12;
aty_st_le32(GP_IO, 0, par);
return sense;
}
static void aty_get_crtc(const struct atyfb_par *par, struct crtc *crtc)
{
#ifdef CONFIG_FB_ATY_GENERIC_LCD
if (par->lcd_table != 0) {
if (!M64_HAS(LT_LCD_REGS)) {
crtc->lcd_index = aty_ld_le32(LCD_INDEX, par);
aty_st_le32(LCD_INDEX, crtc->lcd_index, par);
}
crtc->lcd_config_panel = aty_ld_lcd(CNFG_PANEL, par);
crtc->lcd_gen_cntl = aty_ld_lcd(LCD_GEN_CNTL, par);
aty_st_lcd(LCD_GEN_CNTL, crtc->lcd_gen_cntl &
~(CRTC_RW_SELECT | SHADOW_EN | SHADOW_RW_EN), par);
crtc->horz_stretching = aty_ld_lcd(HORZ_STRETCHING, par);
crtc->vert_stretching = aty_ld_lcd(VERT_STRETCHING, par);
if (!M64_HAS(LT_LCD_REGS))
crtc->ext_vert_stretch = aty_ld_lcd(EXT_VERT_STRETCH, par);
}
#endif
crtc->h_tot_disp = aty_ld_le32(CRTC_H_TOTAL_DISP, par);
crtc->h_sync_strt_wid = aty_ld_le32(CRTC_H_SYNC_STRT_WID, par);
crtc->v_tot_disp = aty_ld_le32(CRTC_V_TOTAL_DISP, par);
crtc->v_sync_strt_wid = aty_ld_le32(CRTC_V_SYNC_STRT_WID, par);
crtc->vline_crnt_vline = aty_ld_le32(CRTC_VLINE_CRNT_VLINE, par);
crtc->off_pitch = aty_ld_le32(CRTC_OFF_PITCH, par);
crtc->gen_cntl = aty_ld_le32(CRTC_GEN_CNTL, par);
#ifdef CONFIG_FB_ATY_GENERIC_LCD
if (par->lcd_table != 0) {
aty_st_lcd(LCD_GEN_CNTL, (crtc->lcd_gen_cntl & ~CRTC_RW_SELECT) |
SHADOW_EN | SHADOW_RW_EN, par);
crtc->shadow_h_tot_disp = aty_ld_le32(CRTC_H_TOTAL_DISP, par);
crtc->shadow_h_sync_strt_wid = aty_ld_le32(CRTC_H_SYNC_STRT_WID, par);
crtc->shadow_v_tot_disp = aty_ld_le32(CRTC_V_TOTAL_DISP, par);
crtc->shadow_v_sync_strt_wid = aty_ld_le32(CRTC_V_SYNC_STRT_WID, par);
aty_st_le32(LCD_GEN_CNTL, crtc->lcd_gen_cntl, par);
}
#endif
}
static void aty_set_crtc(const struct atyfb_par *par, const struct crtc *crtc)
{
#ifdef CONFIG_FB_ATY_GENERIC_LCD
if (par->lcd_table != 0) {
aty_st_le32(CRTC_GEN_CNTL, crtc->gen_cntl &
~(CRTC_EXT_DISP_EN | CRTC_EN), par);
aty_st_lcd(CNFG_PANEL, crtc->lcd_config_panel, par);
aty_st_lcd(LCD_GEN_CNTL, crtc->lcd_gen_cntl &
~(CRTC_RW_SELECT | SHADOW_EN | SHADOW_RW_EN), par);
aty_st_lcd(HORZ_STRETCHING, crtc->horz_stretching &
~(HORZ_STRETCH_MODE | HORZ_STRETCH_EN), par);
aty_st_lcd(VERT_STRETCHING, crtc->vert_stretching &
~(VERT_STRETCH_RATIO1 | VERT_STRETCH_RATIO2 |
VERT_STRETCH_USE0 | VERT_STRETCH_EN), par);
}
#endif
aty_st_le32(CRTC_GEN_CNTL, crtc->gen_cntl & ~CRTC_EN, par);
DPRINTK("setting up CRTC\n");
DPRINTK("set primary CRT to %ix%i %c%c composite %c\n",
((((crtc->h_tot_disp >> 16) & 0xff) + 1) << 3),
(((crtc->v_tot_disp >> 16) & 0x7ff) + 1),
(crtc->h_sync_strt_wid & 0x200000) ? 'N' : 'P',
(crtc->v_sync_strt_wid & 0x200000) ? 'N' : 'P',
(crtc->gen_cntl & CRTC_CSYNC_EN) ? 'P' : 'N');
DPRINTK("CRTC_H_TOTAL_DISP: %x\n", crtc->h_tot_disp);
DPRINTK("CRTC_H_SYNC_STRT_WID: %x\n", crtc->h_sync_strt_wid);
DPRINTK("CRTC_V_TOTAL_DISP: %x\n", crtc->v_tot_disp);
DPRINTK("CRTC_V_SYNC_STRT_WID: %x\n", crtc->v_sync_strt_wid);
DPRINTK("CRTC_OFF_PITCH: %x\n", crtc->off_pitch);
DPRINTK("CRTC_VLINE_CRNT_VLINE: %x\n", crtc->vline_crnt_vline);
DPRINTK("CRTC_GEN_CNTL: %x\n", crtc->gen_cntl);
aty_st_le32(CRTC_H_TOTAL_DISP, crtc->h_tot_disp, par);
aty_st_le32(CRTC_H_SYNC_STRT_WID, crtc->h_sync_strt_wid, par);
aty_st_le32(CRTC_V_TOTAL_DISP, crtc->v_tot_disp, par);
aty_st_le32(CRTC_V_SYNC_STRT_WID, crtc->v_sync_strt_wid, par);
aty_st_le32(CRTC_OFF_PITCH, crtc->off_pitch, par);
aty_st_le32(CRTC_VLINE_CRNT_VLINE, crtc->vline_crnt_vline, par);
aty_st_le32(CRTC_GEN_CNTL, crtc->gen_cntl, par);
#if 0
FIXME
if (par->accel_flags & FB_ACCELF_TEXT)
aty_init_engine(par, info);
#endif
#ifdef CONFIG_FB_ATY_GENERIC_LCD
if (par->lcd_table != 0) {
aty_st_lcd(LCD_GEN_CNTL, (crtc->lcd_gen_cntl & ~CRTC_RW_SELECT) |
SHADOW_EN | SHADOW_RW_EN, par);
DPRINTK("set shadow CRT to %ix%i %c%c\n",
((((crtc->shadow_h_tot_disp >> 16) & 0xff) + 1) << 3),
(((crtc->shadow_v_tot_disp >> 16) & 0x7ff) + 1),
(crtc->shadow_h_sync_strt_wid & 0x200000) ? 'N' : 'P',
(crtc->shadow_v_sync_strt_wid & 0x200000) ? 'N' : 'P');
DPRINTK("SHADOW CRTC_H_TOTAL_DISP: %x\n",
crtc->shadow_h_tot_disp);
DPRINTK("SHADOW CRTC_H_SYNC_STRT_WID: %x\n",
crtc->shadow_h_sync_strt_wid);
DPRINTK("SHADOW CRTC_V_TOTAL_DISP: %x\n",
crtc->shadow_v_tot_disp);
DPRINTK("SHADOW CRTC_V_SYNC_STRT_WID: %x\n",
crtc->shadow_v_sync_strt_wid);
aty_st_le32(CRTC_H_TOTAL_DISP, crtc->shadow_h_tot_disp, par);
aty_st_le32(CRTC_H_SYNC_STRT_WID, crtc->shadow_h_sync_strt_wid, par);
aty_st_le32(CRTC_V_TOTAL_DISP, crtc->shadow_v_tot_disp, par);
aty_st_le32(CRTC_V_SYNC_STRT_WID, crtc->shadow_v_sync_strt_wid, par);
DPRINTK("LCD_GEN_CNTL: %x\n", crtc->lcd_gen_cntl);
DPRINTK("HORZ_STRETCHING: %x\n", crtc->horz_stretching);
DPRINTK("VERT_STRETCHING: %x\n", crtc->vert_stretching);
if (!M64_HAS(LT_LCD_REGS))
DPRINTK("EXT_VERT_STRETCH: %x\n", crtc->ext_vert_stretch);
aty_st_lcd(LCD_GEN_CNTL, crtc->lcd_gen_cntl, par);
aty_st_lcd(HORZ_STRETCHING, crtc->horz_stretching, par);
aty_st_lcd(VERT_STRETCHING, crtc->vert_stretching, par);
if (!M64_HAS(LT_LCD_REGS)) {
aty_st_lcd(EXT_VERT_STRETCH, crtc->ext_vert_stretch, par);
aty_ld_le32(LCD_INDEX, par);
aty_st_le32(LCD_INDEX, crtc->lcd_index, par);
}
}
#endif
}
static u32 calc_line_length(struct atyfb_par *par, u32 vxres, u32 bpp)
{
u32 line_length = vxres * bpp / 8;
if (par->ram_type == SGRAM ||
(!M64_HAS(XL_MEM) && par->ram_type == WRAM))
line_length = (line_length + 63) & ~63;
return line_length;
}
static int aty_var_to_crtc(const struct fb_info *info,
const struct fb_var_screeninfo *var,
struct crtc *crtc)
{
struct atyfb_par *par = (struct atyfb_par *) info->par;
u32 xres, yres, vxres, vyres, xoffset, yoffset, bpp;
u32 sync, vmode, vdisplay;
u32 h_total, h_disp, h_sync_strt, h_sync_end, h_sync_dly, h_sync_wid, h_sync_pol;
u32 v_total, v_disp, v_sync_strt, v_sync_end, v_sync_wid, v_sync_pol, c_sync;
u32 pix_width, dp_pix_width, dp_chain_mask;
u32 line_length;
xres = (var->xres + 7) & ~7;
yres = var->yres;
vxres = (var->xres_virtual + 7) & ~7;
vyres = var->yres_virtual;
xoffset = (var->xoffset + 7) & ~7;
yoffset = var->yoffset;
bpp = var->bits_per_pixel;
if (bpp == 16)
bpp = (var->green.length == 5) ? 15 : 16;
sync = var->sync;
vmode = var->vmode;
if (vxres < xres + xoffset)
vxres = xres + xoffset;
h_disp = xres;
if (vyres < yres + yoffset)
vyres = yres + yoffset;
v_disp = yres;
if (bpp <= 8) {
bpp = 8;
pix_width = CRTC_PIX_WIDTH_8BPP;
dp_pix_width = HOST_8BPP | SRC_8BPP | DST_8BPP |
BYTE_ORDER_LSB_TO_MSB;
dp_chain_mask = DP_CHAIN_8BPP;
} else if (bpp <= 15) {
bpp = 16;
pix_width = CRTC_PIX_WIDTH_15BPP;
dp_pix_width = HOST_15BPP | SRC_15BPP | DST_15BPP |
BYTE_ORDER_LSB_TO_MSB;
dp_chain_mask = DP_CHAIN_15BPP;
} else if (bpp <= 16) {
bpp = 16;
pix_width = CRTC_PIX_WIDTH_16BPP;
dp_pix_width = HOST_16BPP | SRC_16BPP | DST_16BPP |
BYTE_ORDER_LSB_TO_MSB;
dp_chain_mask = DP_CHAIN_16BPP;
} else if (bpp <= 24 && M64_HAS(INTEGRATED)) {
bpp = 24;
pix_width = CRTC_PIX_WIDTH_24BPP;
dp_pix_width = HOST_8BPP | SRC_8BPP | DST_8BPP |
BYTE_ORDER_LSB_TO_MSB;
dp_chain_mask = DP_CHAIN_24BPP;
} else if (bpp <= 32) {
bpp = 32;
pix_width = CRTC_PIX_WIDTH_32BPP;
dp_pix_width = HOST_32BPP | SRC_32BPP | DST_32BPP |
BYTE_ORDER_LSB_TO_MSB;
dp_chain_mask = DP_CHAIN_32BPP;
} else
FAIL("invalid bpp");
line_length = calc_line_length(par, vxres, bpp);
if (vyres * line_length > info->fix.smem_len)
FAIL("not enough video RAM");
h_sync_pol = sync & FB_SYNC_HOR_HIGH_ACT ? 0 : 1;
v_sync_pol = sync & FB_SYNC_VERT_HIGH_ACT ? 0 : 1;
if ((xres > 1600) || (yres > 1200)) {
FAIL("MACH64 chips are designed for max 1600x1200\n"
"select another resolution.");
}
h_sync_strt = h_disp + var->right_margin;
h_sync_end = h_sync_strt + var->hsync_len;
h_sync_dly = var->right_margin & 7;
h_total = h_sync_end + h_sync_dly + var->left_margin;
v_sync_strt = v_disp + var->lower_margin;
v_sync_end = v_sync_strt + var->vsync_len;
v_total = v_sync_end + var->upper_margin;
#ifdef CONFIG_FB_ATY_GENERIC_LCD
if (par->lcd_table != 0) {
if (!M64_HAS(LT_LCD_REGS)) {
u32 lcd_index = aty_ld_le32(LCD_INDEX, par);
crtc->lcd_index = lcd_index &
~(LCD_INDEX_MASK | LCD_DISPLAY_DIS |
LCD_SRC_SEL | CRTC2_DISPLAY_DIS);
aty_st_le32(LCD_INDEX, lcd_index, par);
}
if (!M64_HAS(MOBIL_BUS))
crtc->lcd_index |= CRTC2_DISPLAY_DIS;
crtc->lcd_config_panel = aty_ld_lcd(CNFG_PANEL, par) | 0x4000;
crtc->lcd_gen_cntl = aty_ld_lcd(LCD_GEN_CNTL, par) & ~CRTC_RW_SELECT;
crtc->lcd_gen_cntl &=
~(HORZ_DIVBY2_EN | DIS_HOR_CRT_DIVBY2 | TVCLK_PM_EN |
USE_SHADOWED_ROWCUR | SHADOW_EN | SHADOW_RW_EN);
crtc->lcd_gen_cntl |= DONT_SHADOW_VPAR | LOCK_8DOT;
if ((crtc->lcd_gen_cntl & LCD_ON) &&
((xres > par->lcd_width) || (yres > par->lcd_height))) {
if (crtc->lcd_gen_cntl & CRT_ON) {
if (!(var->activate & FB_ACTIVATE_TEST))
PRINTKI("Disable LCD panel, because video mode does not fit.\n");
crtc->lcd_gen_cntl &= ~LCD_ON;
} else {
if (!(var->activate & FB_ACTIVATE_TEST))
PRINTKE("Video mode exceeds size of LCD panel.\nConnect this computer to a conventional monitor if you really need this mode.\n");
return -EINVAL;
}
}
}
if ((par->lcd_table != 0) && (crtc->lcd_gen_cntl & LCD_ON)) {
int VScan = 1;
vmode &= ~(FB_VMODE_DOUBLE | FB_VMODE_INTERLACED);
if (yres < par->lcd_height) {
VScan = par->lcd_height / yres;
if (VScan > 1) {
VScan = 2;
vmode |= FB_VMODE_DOUBLE;
}
}
h_sync_strt = h_disp + par->lcd_right_margin;
h_sync_end = h_sync_strt + par->lcd_hsync_len;
h_sync_dly = par->lcd_hsync_dly;
h_total = h_disp + par->lcd_hblank_len;
v_sync_strt = v_disp + par->lcd_lower_margin / VScan;
v_sync_end = v_sync_strt + par->lcd_vsync_len / VScan;
v_total = v_disp + par->lcd_vblank_len / VScan;
}
#endif
h_disp = (h_disp >> 3) - 1;
h_sync_strt = (h_sync_strt >> 3) - 1;
h_sync_end = (h_sync_end >> 3) - 1;
h_total = (h_total >> 3) - 1;
h_sync_wid = h_sync_end - h_sync_strt;
FAIL_MAX("h_disp too large", h_disp, 0xff);
FAIL_MAX("h_sync_strt too large", h_sync_strt, 0x1ff);
if (h_sync_wid > 0x1f)
h_sync_wid = 0x1f;
FAIL_MAX("h_total too large", h_total, 0x1ff);
if (vmode & FB_VMODE_DOUBLE) {
v_disp <<= 1;
v_sync_strt <<= 1;
v_sync_end <<= 1;
v_total <<= 1;
}
vdisplay = yres;
#ifdef CONFIG_FB_ATY_GENERIC_LCD
if ((par->lcd_table != 0) && (crtc->lcd_gen_cntl & LCD_ON))
vdisplay = par->lcd_height;
#endif
v_disp--;
v_sync_strt--;
v_sync_end--;
v_total--;
v_sync_wid = v_sync_end - v_sync_strt;
FAIL_MAX("v_disp too large", v_disp, 0x7ff);
FAIL_MAX("v_sync_stsrt too large", v_sync_strt, 0x7ff);
if (v_sync_wid > 0x1f)
v_sync_wid = 0x1f;
FAIL_MAX("v_total too large", v_total, 0x7ff);
c_sync = sync & FB_SYNC_COMP_HIGH_ACT ? CRTC_CSYNC_EN : 0;
crtc->vxres = vxres;
crtc->vyres = vyres;
crtc->xoffset = xoffset;
crtc->yoffset = yoffset;
crtc->bpp = bpp;
crtc->off_pitch =
((yoffset * line_length + xoffset * bpp / 8) / 8) |
((line_length / bpp) << 22);
crtc->vline_crnt_vline = 0;
crtc->h_tot_disp = h_total | (h_disp << 16);
crtc->h_sync_strt_wid = (h_sync_strt & 0xff) | (h_sync_dly << 8) |
((h_sync_strt & 0x100) << 4) | (h_sync_wid << 16) |
(h_sync_pol << 21);
crtc->v_tot_disp = v_total | (v_disp << 16);
crtc->v_sync_strt_wid = v_sync_strt | (v_sync_wid << 16) |
(v_sync_pol << 21);
crtc->gen_cntl = CRTC_EXT_DISP_EN | CRTC_EN | pix_width | c_sync;
crtc->gen_cntl |= CRTC_VGA_LINEAR;
if (vmode & FB_VMODE_DOUBLE)
crtc->gen_cntl |= CRTC_DBL_SCAN_EN;
if (vmode & FB_VMODE_INTERLACED)
crtc->gen_cntl |= CRTC_INTERLACE_EN;
#ifdef CONFIG_FB_ATY_GENERIC_LCD
if (par->lcd_table != 0) {
vdisplay = yres;
if (vmode & FB_VMODE_DOUBLE)
vdisplay <<= 1;
crtc->gen_cntl &= ~(CRTC2_EN | CRTC2_PIX_WIDTH);
crtc->lcd_gen_cntl &= ~(HORZ_DIVBY2_EN | DIS_HOR_CRT_DIVBY2 |
USE_SHADOWED_VEND |
USE_SHADOWED_ROWCUR |
SHADOW_EN | SHADOW_RW_EN);
crtc->lcd_gen_cntl |= DONT_SHADOW_VPAR;
crtc->horz_stretching = aty_ld_lcd(HORZ_STRETCHING, par);
if (!M64_HAS(LT_LCD_REGS))
crtc->ext_vert_stretch = aty_ld_lcd(EXT_VERT_STRETCH, par) &
~(AUTO_VERT_RATIO | VERT_STRETCH_MODE | VERT_STRETCH_RATIO3);
crtc->horz_stretching &= ~(HORZ_STRETCH_RATIO |
HORZ_STRETCH_LOOP | AUTO_HORZ_RATIO |
HORZ_STRETCH_MODE | HORZ_STRETCH_EN);
if (xres < par->lcd_width && crtc->lcd_gen_cntl & LCD_ON) {
do {
int HDisplay = xres & ~7;
int nStretch = par->lcd_width / HDisplay;
int Remainder = par->lcd_width % HDisplay;
if ((!Remainder && ((nStretch > 2))) ||
(((HDisplay * 16) / par->lcd_width) < 7)) {
static const char StretchLoops[] = { 10, 12, 13, 15, 16 };
int horz_stretch_loop = -1, BestRemainder;
int Numerator = HDisplay, Denominator = par->lcd_width;
int Index = 5;
ATIReduceRatio(&Numerator, &Denominator);
BestRemainder = (Numerator * 16) / Denominator;
while (--Index >= 0) {
Remainder = ((Denominator - Numerator) * StretchLoops[Index]) %
Denominator;
if (Remainder < BestRemainder) {
horz_stretch_loop = Index;
if (!(BestRemainder = Remainder))
break;
}
}
if ((horz_stretch_loop >= 0) && !BestRemainder) {
int horz_stretch_ratio = 0, Accumulator = 0;
int reuse_previous = 1;
Index = StretchLoops[horz_stretch_loop];
while (--Index >= 0) {
if (Accumulator > 0)
horz_stretch_ratio |= reuse_previous;
else
Accumulator += Denominator;
Accumulator -= Numerator;
reuse_previous <<= 1;
}
crtc->horz_stretching |= (HORZ_STRETCH_EN |
((horz_stretch_loop & HORZ_STRETCH_LOOP) << 16) |
(horz_stretch_ratio & HORZ_STRETCH_RATIO));
break;
}
}
crtc->horz_stretching |= (HORZ_STRETCH_MODE | HORZ_STRETCH_EN |
(((HDisplay * (HORZ_STRETCH_BLEND + 1)) / par->lcd_width) & HORZ_STRETCH_BLEND));
} while (0);
}
if (vdisplay < par->lcd_height && crtc->lcd_gen_cntl & LCD_ON) {
crtc->vert_stretching = (VERT_STRETCH_USE0 | VERT_STRETCH_EN |
(((vdisplay * (VERT_STRETCH_RATIO0 + 1)) / par->lcd_height) & VERT_STRETCH_RATIO0));
if (!M64_HAS(LT_LCD_REGS) &&
xres <= (M64_HAS(MOBIL_BUS) ? 1024 : 800))
crtc->ext_vert_stretch |= VERT_STRETCH_MODE;
} else {
crtc->vert_stretching = 0;
}
crtc->shadow_h_tot_disp = crtc->h_tot_disp;
crtc->shadow_h_sync_strt_wid = crtc->h_sync_strt_wid;
crtc->shadow_v_tot_disp = crtc->v_tot_disp;
crtc->shadow_v_sync_strt_wid = crtc->v_sync_strt_wid;
}
#endif
if (M64_HAS(MAGIC_FIFO)) {
crtc->gen_cntl |= (aty_ld_le32(CRTC_GEN_CNTL, par) & CRTC_FIFO_LWM);
}
crtc->dp_pix_width = dp_pix_width;
crtc->dp_chain_mask = dp_chain_mask;
return 0;
}
static int aty_crtc_to_var(const struct crtc *crtc,
struct fb_var_screeninfo *var)
{
u32 xres, yres, bpp, left, right, upper, lower, hslen, vslen, sync;
u32 h_total, h_disp, h_sync_strt, h_sync_dly, h_sync_wid, h_sync_pol;
u32 v_total, v_disp, v_sync_strt, v_sync_wid, v_sync_pol, c_sync;
u32 pix_width;
u32 double_scan, interlace;
h_total = crtc->h_tot_disp & 0x1ff;
h_disp = (crtc->h_tot_disp >> 16) & 0xff;
h_sync_strt = (crtc->h_sync_strt_wid & 0xff) | ((crtc->h_sync_strt_wid >> 4) & 0x100);
h_sync_dly = (crtc->h_sync_strt_wid >> 8) & 0x7;
h_sync_wid = (crtc->h_sync_strt_wid >> 16) & 0x1f;
h_sync_pol = (crtc->h_sync_strt_wid >> 21) & 0x1;
v_total = crtc->v_tot_disp & 0x7ff;
v_disp = (crtc->v_tot_disp >> 16) & 0x7ff;
v_sync_strt = crtc->v_sync_strt_wid & 0x7ff;
v_sync_wid = (crtc->v_sync_strt_wid >> 16) & 0x1f;
v_sync_pol = (crtc->v_sync_strt_wid >> 21) & 0x1;
c_sync = crtc->gen_cntl & CRTC_CSYNC_EN ? 1 : 0;
pix_width = crtc->gen_cntl & CRTC_PIX_WIDTH_MASK;
double_scan = crtc->gen_cntl & CRTC_DBL_SCAN_EN;
interlace = crtc->gen_cntl & CRTC_INTERLACE_EN;
xres = (h_disp + 1) * 8;
yres = v_disp + 1;
left = (h_total - h_sync_strt - h_sync_wid) * 8 - h_sync_dly;
right = (h_sync_strt - h_disp) * 8 + h_sync_dly;
hslen = h_sync_wid * 8;
upper = v_total - v_sync_strt - v_sync_wid;
lower = v_sync_strt - v_disp;
vslen = v_sync_wid;
sync = (h_sync_pol ? 0 : FB_SYNC_HOR_HIGH_ACT) |
(v_sync_pol ? 0 : FB_SYNC_VERT_HIGH_ACT) |
(c_sync ? FB_SYNC_COMP_HIGH_ACT : 0);
switch (pix_width) {
#if 0
case CRTC_PIX_WIDTH_4BPP:
bpp = 4;
var->red.offset = 0;
var->red.length = 8;
var->green.offset = 0;
var->green.length = 8;
var->blue.offset = 0;
var->blue.length = 8;
var->transp.offset = 0;
var->transp.length = 0;
break;
#endif
case CRTC_PIX_WIDTH_8BPP:
bpp = 8;
var->red.offset = 0;
var->red.length = 8;
var->green.offset = 0;
var->green.length = 8;
var->blue.offset = 0;
var->blue.length = 8;
var->transp.offset = 0;
var->transp.length = 0;
break;
case CRTC_PIX_WIDTH_15BPP:
bpp = 16;
var->red.offset = 10;
var->red.length = 5;
var->green.offset = 5;
var->green.length = 5;
var->blue.offset = 0;
var->blue.length = 5;
var->transp.offset = 0;
var->transp.length = 0;
break;
case CRTC_PIX_WIDTH_16BPP:
bpp = 16;
var->red.offset = 11;
var->red.length = 5;
var->green.offset = 5;
var->green.length = 6;
var->blue.offset = 0;
var->blue.length = 5;
var->transp.offset = 0;
var->transp.length = 0;
break;
case CRTC_PIX_WIDTH_24BPP:
bpp = 24;
var->red.offset = 16;
var->red.length = 8;
var->green.offset = 8;
var->green.length = 8;
var->blue.offset = 0;
var->blue.length = 8;
var->transp.offset = 0;
var->transp.length = 0;
break;
case CRTC_PIX_WIDTH_32BPP:
bpp = 32;
var->red.offset = 16;
var->red.length = 8;
var->green.offset = 8;
var->green.length = 8;
var->blue.offset = 0;
var->blue.length = 8;
var->transp.offset = 24;
var->transp.length = 8;
break;
default:
PRINTKE("Invalid pixel width\n");
return -EINVAL;
}
var->xres = xres;
var->yres = yres;
var->xres_virtual = crtc->vxres;
var->yres_virtual = crtc->vyres;
var->bits_per_pixel = bpp;
var->left_margin = left;
var->right_margin = right;
var->upper_margin = upper;
var->lower_margin = lower;
var->hsync_len = hslen;
var->vsync_len = vslen;
var->sync = sync;
var->vmode = FB_VMODE_NONINTERLACED;
if (interlace)
var->vmode = FB_VMODE_INTERLACED;
if (double_scan) {
var->vmode = FB_VMODE_DOUBLE;
var->yres >>= 1;
var->upper_margin >>= 1;
var->lower_margin >>= 1;
var->vsync_len >>= 1;
}
return 0;
}
static int atyfb_set_par(struct fb_info *info)
{
struct atyfb_par *par = (struct atyfb_par *) info->par;
struct fb_var_screeninfo *var = &info->var;
u32 tmp, pixclock;
int err;
#ifdef DEBUG
struct fb_var_screeninfo debug;
u32 pixclock_in_ps;
#endif
if (par->asleep)
return 0;
err = aty_var_to_crtc(info, var, &par->crtc);
if (err)
return err;
pixclock = atyfb_get_pixclock(var, par);
if (pixclock == 0) {
PRINTKE("Invalid pixclock\n");
return -EINVAL;
} else {
err = par->pll_ops->var_to_pll(info, pixclock,
var->bits_per_pixel, &par->pll);
if (err)
return err;
}
par->accel_flags = var->accel_flags;
if (var->accel_flags) {
info->fbops->fb_sync = atyfb_sync;
info->flags &= ~FBINFO_HWACCEL_DISABLED;
} else {
info->fbops->fb_sync = NULL;
info->flags |= FBINFO_HWACCEL_DISABLED;
}
if (par->blitter_may_be_busy)
wait_for_idle(par);
aty_set_crtc(par, &par->crtc);
par->dac_ops->set_dac(info, &par->pll,
var->bits_per_pixel, par->accel_flags);
par->pll_ops->set_pll(info, &par->pll);
#ifdef DEBUG
if (par->pll_ops && par->pll_ops->pll_to_var)
pixclock_in_ps = par->pll_ops->pll_to_var(info, &par->pll);
else
pixclock_in_ps = 0;
if (0 == pixclock_in_ps) {
PRINTKE("ALERT ops->pll_to_var get 0\n");
pixclock_in_ps = pixclock;
}
memset(&debug, 0, sizeof(debug));
if (!aty_crtc_to_var(&par->crtc, &debug)) {
u32 hSync, vRefresh;
u32 h_disp, h_sync_strt, h_sync_end, h_total;
u32 v_disp, v_sync_strt, v_sync_end, v_total;
h_disp = debug.xres;
h_sync_strt = h_disp + debug.right_margin;
h_sync_end = h_sync_strt + debug.hsync_len;
h_total = h_sync_end + debug.left_margin;
v_disp = debug.yres;
v_sync_strt = v_disp + debug.lower_margin;
v_sync_end = v_sync_strt + debug.vsync_len;
v_total = v_sync_end + debug.upper_margin;
hSync = 1000000000 / (pixclock_in_ps * h_total);
vRefresh = (hSync * 1000) / v_total;
if (par->crtc.gen_cntl & CRTC_INTERLACE_EN)
vRefresh *= 2;
if (par->crtc.gen_cntl & CRTC_DBL_SCAN_EN)
vRefresh /= 2;
DPRINTK("atyfb_set_par\n");
DPRINTK(" Set Visible Mode to %ix%i-%i\n",
var->xres, var->yres, var->bits_per_pixel);
DPRINTK(" Virtual resolution %ix%i, "
"pixclock_in_ps %i (calculated %i)\n",
var->xres_virtual, var->yres_virtual,
pixclock, pixclock_in_ps);
DPRINTK(" Dot clock: %i MHz\n",
1000000 / pixclock_in_ps);
DPRINTK(" Horizontal sync: %i kHz\n", hSync);
DPRINTK(" Vertical refresh: %i Hz\n", vRefresh);
DPRINTK(" x style: %i.%03i %i %i %i %i %i %i %i %i\n",
1000000 / pixclock_in_ps, 1000000 % pixclock_in_ps,
h_disp, h_sync_strt, h_sync_end, h_total,
v_disp, v_sync_strt, v_sync_end, v_total);
DPRINTK(" fb style: %i %i %i %i %i %i %i %i %i\n",
pixclock_in_ps,
debug.left_margin, h_disp, debug.right_margin, debug.hsync_len,
debug.upper_margin, v_disp, debug.lower_margin, debug.vsync_len);
}
#endif
if (!M64_HAS(INTEGRATED)) {
tmp = aty_ld_le32(MEM_CNTL, par) & 0xf0ffffff;
switch (var->bits_per_pixel) {
case 8:
tmp |= 0x02000000;
break;
case 16:
tmp |= 0x03000000;
break;
case 32:
tmp |= 0x06000000;
break;
}
aty_st_le32(MEM_CNTL, tmp, par);
} else {
tmp = aty_ld_le32(MEM_CNTL, par) & 0xf00fffff;
if (!M64_HAS(MAGIC_POSTDIV))
tmp |= par->mem_refresh_rate << 20;
switch (var->bits_per_pixel) {
case 8:
case 24:
tmp |= 0x00000000;
break;
case 16:
tmp |= 0x04000000;
break;
case 32:
tmp |= 0x08000000;
break;
}
if (M64_HAS(CT_BUS)) {
aty_st_le32(DAC_CNTL, 0x87010184, par);
aty_st_le32(BUS_CNTL, 0x680000f9, par);
} else if (M64_HAS(VT_BUS)) {
aty_st_le32(DAC_CNTL, 0x87010184, par);
aty_st_le32(BUS_CNTL, 0x680000f9, par);
} else if (M64_HAS(MOBIL_BUS)) {
aty_st_le32(DAC_CNTL, 0x80010102, par);
aty_st_le32(BUS_CNTL, 0x7b33a040 | (par->aux_start ? BUS_APER_REG_DIS : 0), par);
} else {
aty_st_le32(DAC_CNTL, 0x86010102, par);
aty_st_le32(BUS_CNTL, 0x7b23a040 | (par->aux_start ? BUS_APER_REG_DIS : 0), par);
aty_st_le32(EXT_MEM_CNTL, aty_ld_le32(EXT_MEM_CNTL, par) | 0x5000001, par);
}
aty_st_le32(MEM_CNTL, tmp, par);
}
aty_st_8(DAC_MASK, 0xff, par);
info->fix.line_length = calc_line_length(par, var->xres_virtual,
var->bits_per_pixel);
info->fix.visual = var->bits_per_pixel <= 8 ?
FB_VISUAL_PSEUDOCOLOR : FB_VISUAL_DIRECTCOLOR;
if (par->accel_flags & FB_ACCELF_TEXT)
aty_init_engine(par, info);
#ifdef CONFIG_BOOTX_TEXT
btext_update_display(info->fix.smem_start,
(((par->crtc.h_tot_disp >> 16) & 0xff) + 1) * 8,
((par->crtc.v_tot_disp >> 16) & 0x7ff) + 1,
var->bits_per_pixel,
par->crtc.vxres * var->bits_per_pixel / 8);
#endif
#if 0
if (!(par->crtc.gen_cntl & CRTC_EXT_DISP_EN))
aty_st_le32(CRTC_GEN_CNTL, par->crtc.gen_cntl | CRTC_EXT_DISP_EN, par);
#endif
#ifdef DEBUG
{
int i; u32 base;
base = 0x2000;
printk("debug atyfb: Mach64 non-shadow register values:");
for (i = 0; i < 256; i = i+4) {
if (i % 16 == 0)
printk("\ndebug atyfb: 0x%04X: ", base + i);
printk(" %08X", aty_ld_le32(i, par));
}
printk("\n\n");
#ifdef CONFIG_FB_ATY_CT
base = 0x00;
printk("debug atyfb: Mach64 PLL register values:");
for (i = 0; i < 64; i++) {
if (i % 16 == 0)
printk("\ndebug atyfb: 0x%02X: ", base + i);
if (i % 4 == 0)
printk(" ");
printk("%02X", aty_ld_pll_ct(i, par));
}
printk("\n\n");
#endif
#ifdef CONFIG_FB_ATY_GENERIC_LCD
if (par->lcd_table != 0) {
base = 0x00;
printk("debug atyfb: LCD register values:");
if (M64_HAS(LT_LCD_REGS)) {
for (i = 0; i <= POWER_MANAGEMENT; i++) {
if (i == EXT_VERT_STRETCH)
continue;
printk("\ndebug atyfb: 0x%04X: ",
lt_lcd_regs[i]);
printk(" %08X", aty_ld_lcd(i, par));
}
} else {
for (i = 0; i < 64; i++) {
if (i % 4 == 0)
printk("\ndebug atyfb: 0x%02X: ",
base + i);
printk(" %08X", aty_ld_lcd(i, par));
}
}
printk("\n\n");
}
#endif
}
#endif
return 0;
}
static int atyfb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
struct atyfb_par *par = (struct atyfb_par *) info->par;
int err;
struct crtc crtc;
union aty_pll pll;
u32 pixclock;
memcpy(&pll, &par->pll, sizeof(pll));
err = aty_var_to_crtc(info, var, &crtc);
if (err)
return err;
pixclock = atyfb_get_pixclock(var, par);
if (pixclock == 0) {
if (!(var->activate & FB_ACTIVATE_TEST))
PRINTKE("Invalid pixclock\n");
return -EINVAL;
} else {
err = par->pll_ops->var_to_pll(info, pixclock,
var->bits_per_pixel, &pll);
if (err)
return err;
}
if (var->accel_flags & FB_ACCELF_TEXT)
info->var.accel_flags = FB_ACCELF_TEXT;
else
info->var.accel_flags = 0;
aty_crtc_to_var(&crtc, var);
var->pixclock = par->pll_ops->pll_to_var(info, &pll);
return 0;
}
static void set_off_pitch(struct atyfb_par *par, const struct fb_info *info)
{
u32 xoffset = info->var.xoffset;
u32 yoffset = info->var.yoffset;
u32 line_length = info->fix.line_length;
u32 bpp = info->var.bits_per_pixel;
par->crtc.off_pitch =
((yoffset * line_length + xoffset * bpp / 8) / 8) |
((line_length / bpp) << 22);
}
static int atyfb_open(struct fb_info *info, int user)
{
struct atyfb_par *par = (struct atyfb_par *) info->par;
if (user) {
par->open++;
#ifdef __sparc__
par->mmaped = 0;
#endif
}
return 0;
}
static irqreturn_t aty_irq(int irq, void *dev_id)
{
struct atyfb_par *par = dev_id;
int handled = 0;
u32 int_cntl;
spin_lock(&par->int_lock);
int_cntl = aty_ld_le32(CRTC_INT_CNTL, par);
if (int_cntl & CRTC_VBLANK_INT) {
aty_st_le32(CRTC_INT_CNTL, (int_cntl & CRTC_INT_EN_MASK) |
CRTC_VBLANK_INT_AK, par);
par->vblank.count++;
if (par->vblank.pan_display) {
par->vblank.pan_display = 0;
aty_st_le32(CRTC_OFF_PITCH, par->crtc.off_pitch, par);
}
wake_up_interruptible(&par->vblank.wait);
handled = 1;
}
spin_unlock(&par->int_lock);
return IRQ_RETVAL(handled);
}
static int aty_enable_irq(struct atyfb_par *par, int reenable)
{
u32 int_cntl;
if (!test_and_set_bit(0, &par->irq_flags)) {
if (request_irq(par->irq, aty_irq, IRQF_SHARED, "atyfb", par)) {
clear_bit(0, &par->irq_flags);
return -EINVAL;
}
spin_lock_irq(&par->int_lock);
int_cntl = aty_ld_le32(CRTC_INT_CNTL, par) & CRTC_INT_EN_MASK;
aty_st_le32(CRTC_INT_CNTL, int_cntl | CRTC_VBLANK_INT_AK, par);
aty_st_le32(CRTC_INT_CNTL, int_cntl | CRTC_VBLANK_INT_EN, par);
spin_unlock_irq(&par->int_lock);
} else if (reenable) {
spin_lock_irq(&par->int_lock);
int_cntl = aty_ld_le32(CRTC_INT_CNTL, par) & CRTC_INT_EN_MASK;
if (!(int_cntl & CRTC_VBLANK_INT_EN)) {
printk("atyfb: someone disabled IRQ [%08x]\n",
int_cntl);
aty_st_le32(CRTC_INT_CNTL, int_cntl |
CRTC_VBLANK_INT_EN, par);
}
spin_unlock_irq(&par->int_lock);
}
return 0;
}
static int aty_disable_irq(struct atyfb_par *par)
{
u32 int_cntl;
if (test_and_clear_bit(0, &par->irq_flags)) {
if (par->vblank.pan_display) {
par->vblank.pan_display = 0;
aty_st_le32(CRTC_OFF_PITCH, par->crtc.off_pitch, par);
}
spin_lock_irq(&par->int_lock);
int_cntl = aty_ld_le32(CRTC_INT_CNTL, par) & CRTC_INT_EN_MASK;
aty_st_le32(CRTC_INT_CNTL, int_cntl & ~CRTC_VBLANK_INT_EN, par);
spin_unlock_irq(&par->int_lock);
free_irq(par->irq, par);
}
return 0;
}
static int atyfb_release(struct fb_info *info, int user)
{
struct atyfb_par *par = (struct atyfb_par *) info->par;
#ifdef __sparc__
int was_mmaped;
#endif
if (!user)
return 0;
par->open--;
mdelay(1);
wait_for_idle(par);
if (par->open)
return 0;
#ifdef __sparc__
was_mmaped = par->mmaped;
par->mmaped = 0;
if (was_mmaped) {
struct fb_var_screeninfo var;
var = default_var;
if (noaccel)
var.accel_flags &= ~FB_ACCELF_TEXT;
else
var.accel_flags |= FB_ACCELF_TEXT;
if (var.yres == var.yres_virtual) {
u32 videoram = (info->fix.smem_len - (PAGE_SIZE << 2));
var.yres_virtual =
((videoram * 8) / var.bits_per_pixel) /
var.xres_virtual;
if (var.yres_virtual < var.yres)
var.yres_virtual = var.yres;
}
}
#endif
aty_disable_irq(par);
return 0;
}
static int atyfb_pan_display(struct fb_var_screeninfo *var,
struct fb_info *info)
{
struct atyfb_par *par = (struct atyfb_par *) info->par;
u32 xres, yres, xoffset, yoffset;
xres = (((par->crtc.h_tot_disp >> 16) & 0xff) + 1) * 8;
yres = ((par->crtc.v_tot_disp >> 16) & 0x7ff) + 1;
if (par->crtc.gen_cntl & CRTC_DBL_SCAN_EN)
yres >>= 1;
xoffset = (var->xoffset + 7) & ~7;
yoffset = var->yoffset;
if (xoffset + xres > par->crtc.vxres ||
yoffset + yres > par->crtc.vyres)
return -EINVAL;
info->var.xoffset = xoffset;
info->var.yoffset = yoffset;
if (par->asleep)
return 0;
set_off_pitch(par, info);
if ((var->activate & FB_ACTIVATE_VBL) && !aty_enable_irq(par, 0)) {
par->vblank.pan_display = 1;
} else {
par->vblank.pan_display = 0;
aty_st_le32(CRTC_OFF_PITCH, par->crtc.off_pitch, par);
}
return 0;
}
static int aty_waitforvblank(struct atyfb_par *par, u32 crtc)
{
struct aty_interrupt *vbl;
unsigned int count;
int ret;
switch (crtc) {
case 0:
vbl = &par->vblank;
break;
default:
return -ENODEV;
}
ret = aty_enable_irq(par, 0);
if (ret)
return ret;
count = vbl->count;
ret = wait_event_interruptible_timeout(vbl->wait,
count != vbl->count, HZ/10);
if (ret < 0)
return ret;
if (ret == 0) {
aty_enable_irq(par, 1);
return -ETIMEDOUT;
}
return 0;
}
static int atyfb_ioctl(struct fb_info *info, u_int cmd, u_long arg)
{
struct atyfb_par *par = (struct atyfb_par *) info->par;
#ifdef __sparc__
struct fbtype fbtyp;
#endif
switch (cmd) {
#ifdef __sparc__
case FBIOGTYPE:
fbtyp.fb_type = FBTYPE_PCI_GENERIC;
fbtyp.fb_width = par->crtc.vxres;
fbtyp.fb_height = par->crtc.vyres;
fbtyp.fb_depth = info->var.bits_per_pixel;
fbtyp.fb_cmsize = info->cmap.len;
fbtyp.fb_size = info->fix.smem_len;
if (copy_to_user((struct fbtype __user *) arg, &fbtyp,
sizeof(fbtyp)))
return -EFAULT;
break;
#endif
case FBIO_WAITFORVSYNC:
{
u32 crtc;
if (get_user(crtc, (__u32 __user *) arg))
return -EFAULT;
return aty_waitforvblank(par, crtc);
}
break;
#if defined(DEBUG) && defined(CONFIG_FB_ATY_CT)
case ATYIO_CLKR:
if (M64_HAS(INTEGRATED)) {
struct atyclk clk;
union aty_pll *pll = &par->pll;
u32 dsp_config = pll->ct.dsp_config;
u32 dsp_on_off = pll->ct.dsp_on_off;
clk.ref_clk_per = par->ref_clk_per;
clk.pll_ref_div = pll->ct.pll_ref_div;
clk.mclk_fb_div = pll->ct.mclk_fb_div;
clk.mclk_post_div = pll->ct.mclk_post_div_real;
clk.mclk_fb_mult = pll->ct.mclk_fb_mult;
clk.xclk_post_div = pll->ct.xclk_post_div_real;
clk.vclk_fb_div = pll->ct.vclk_fb_div;
clk.vclk_post_div = pll->ct.vclk_post_div_real;
clk.dsp_xclks_per_row = dsp_config & 0x3fff;
clk.dsp_loop_latency = (dsp_config >> 16) & 0xf;
clk.dsp_precision = (dsp_config >> 20) & 7;
clk.dsp_off = dsp_on_off & 0x7ff;
clk.dsp_on = (dsp_on_off >> 16) & 0x7ff;
if (copy_to_user((struct atyclk __user *) arg, &clk,
sizeof(clk)))
return -EFAULT;
} else
return -EINVAL;
break;
case ATYIO_CLKW:
if (M64_HAS(INTEGRATED)) {
struct atyclk clk;
union aty_pll *pll = &par->pll;
if (copy_from_user(&clk, (struct atyclk __user *) arg,
sizeof(clk)))
return -EFAULT;
par->ref_clk_per = clk.ref_clk_per;
pll->ct.pll_ref_div = clk.pll_ref_div;
pll->ct.mclk_fb_div = clk.mclk_fb_div;
pll->ct.mclk_post_div_real = clk.mclk_post_div;
pll->ct.mclk_fb_mult = clk.mclk_fb_mult;
pll->ct.xclk_post_div_real = clk.xclk_post_div;
pll->ct.vclk_fb_div = clk.vclk_fb_div;
pll->ct.vclk_post_div_real = clk.vclk_post_div;
pll->ct.dsp_config = (clk.dsp_xclks_per_row & 0x3fff) |
((clk.dsp_loop_latency & 0xf) << 16) |
((clk.dsp_precision & 7) << 20);
pll->ct.dsp_on_off = (clk.dsp_off & 0x7ff) |
((clk.dsp_on & 0x7ff) << 16);
aty_set_pll_ct(info, pll);
} else
return -EINVAL;
break;
case ATYIO_FEATR:
if (get_user(par->features, (u32 __user *) arg))
return -EFAULT;
break;
case ATYIO_FEATW:
if (put_user(par->features, (u32 __user *) arg))
return -EFAULT;
break;
#endif
default:
return -EINVAL;
}
return 0;
}
static int atyfb_sync(struct fb_info *info)
{
struct atyfb_par *par = (struct atyfb_par *) info->par;
if (par->blitter_may_be_busy)
wait_for_idle(par);
return 0;
}
static int atyfb_mmap(struct fb_info *info, struct vm_area_struct *vma)
{
struct atyfb_par *par = (struct atyfb_par *) info->par;
unsigned int size, page, map_size = 0;
unsigned long map_offset = 0;
unsigned long off;
int i;
if (!par->mmap_map)
return -ENXIO;
if (vma->vm_pgoff > (~0UL >> PAGE_SHIFT))
return -EINVAL;
off = vma->vm_pgoff << PAGE_SHIFT;
size = vma->vm_end - vma->vm_start;
if (((vma->vm_pgoff == 0) && (size == info->fix.smem_len)) ||
((off == info->fix.smem_len) && (size == PAGE_SIZE)))
off += 0x8000000000000000UL;
vma->vm_pgoff = off >> PAGE_SHIFT;
for (page = 0; page < size;) {
map_size = 0;
for (i = 0; par->mmap_map[i].size; i++) {
unsigned long start = par->mmap_map[i].voff;
unsigned long end = start + par->mmap_map[i].size;
unsigned long offset = off + page;
if (start > offset)
continue;
if (offset >= end)
continue;
map_size = par->mmap_map[i].size - (offset - start);
map_offset = par->mmap_map[i].poff + (offset - start);
break;
}
if (!map_size) {
page += PAGE_SIZE;
continue;
}
if (page + map_size > size)
map_size = size - page;
pgprot_val(vma->vm_page_prot) &= ~(par->mmap_map[i].prot_mask);
pgprot_val(vma->vm_page_prot) |= par->mmap_map[i].prot_flag;
if (remap_pfn_range(vma, vma->vm_start + page,
map_offset >> PAGE_SHIFT, map_size, vma->vm_page_prot))
return -EAGAIN;
page += map_size;
}
if (!map_size)
return -EINVAL;
if (!par->mmaped)
par->mmaped = 1;
return 0;
}
static int aty_power_mgmt(int sleep, struct atyfb_par *par)
{
u32 pm;
int timeout;
pm = aty_ld_lcd(POWER_MANAGEMENT, par);
pm = (pm & ~PWR_MGT_MODE_MASK) | PWR_MGT_MODE_REG;
aty_st_lcd(POWER_MANAGEMENT, pm, par);
pm = aty_ld_lcd(POWER_MANAGEMENT, par);
timeout = 2000;
if (sleep) {
pm &= ~PWR_MGT_ON;
aty_st_lcd(POWER_MANAGEMENT, pm, par);
pm = aty_ld_lcd(POWER_MANAGEMENT, par);
udelay(10);
pm &= ~(PWR_BLON | AUTO_PWR_UP);
pm |= SUSPEND_NOW;
aty_st_lcd(POWER_MANAGEMENT, pm, par);
pm = aty_ld_lcd(POWER_MANAGEMENT, par);
udelay(10);
pm |= PWR_MGT_ON;
aty_st_lcd(POWER_MANAGEMENT, pm, par);
do {
pm = aty_ld_lcd(POWER_MANAGEMENT, par);
mdelay(1);
if ((--timeout) == 0)
break;
} while ((pm & PWR_MGT_STATUS_MASK) != PWR_MGT_STATUS_SUSPEND);
} else {
pm &= ~PWR_MGT_ON;
aty_st_lcd(POWER_MANAGEMENT, pm, par);
pm = aty_ld_lcd(POWER_MANAGEMENT, par);
udelay(10);
pm &= ~SUSPEND_NOW;
pm |= (PWR_BLON | AUTO_PWR_UP);
aty_st_lcd(POWER_MANAGEMENT, pm, par);
pm = aty_ld_lcd(POWER_MANAGEMENT, par);
udelay(10);
pm |= PWR_MGT_ON;
aty_st_lcd(POWER_MANAGEMENT, pm, par);
do {
pm = aty_ld_lcd(POWER_MANAGEMENT, par);
mdelay(1);
if ((--timeout) == 0)
break;
} while ((pm & PWR_MGT_STATUS_MASK) != 0);
}
mdelay(500);
return timeout ? 0 : -EIO;
}
static int atyfb_pci_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct fb_info *info = pci_get_drvdata(pdev);
struct atyfb_par *par = (struct atyfb_par *) info->par;
if (state.event == pdev->dev.power.power_state.event)
return 0;
console_lock();
fb_set_suspend(info, 1);
wait_for_idle(par);
aty_reset_engine(par);
atyfb_blank(FB_BLANK_POWERDOWN, info);
par->asleep = 1;
par->lock_blank = 1;
pci_save_state(pdev);
#ifdef CONFIG_PPC_PMAC
if (machine_is(powermac) && aty_power_mgmt(1, par)) {
par->asleep = 0;
par->lock_blank = 0;
atyfb_blank(FB_BLANK_UNBLANK, info);
fb_set_suspend(info, 0);
console_unlock();
return -EIO;
}
#else
pci_set_power_state(pdev, pci_choose_state(pdev, state));
#endif
console_unlock();
pdev->dev.power.power_state = state;
return 0;
}
static void aty_resume_chip(struct fb_info *info)
{
struct atyfb_par *par = info->par;
aty_st_le32(MEM_CNTL, par->mem_cntl, par);
if (par->pll_ops->resume_pll)
par->pll_ops->resume_pll(info, &par->pll);
if (par->aux_start)
aty_st_le32(BUS_CNTL,
aty_ld_le32(BUS_CNTL, par) | BUS_APER_REG_DIS, par);
}
static int atyfb_pci_resume(struct pci_dev *pdev)
{
struct fb_info *info = pci_get_drvdata(pdev);
struct atyfb_par *par = (struct atyfb_par *) info->par;
if (pdev->dev.power.power_state.event == PM_EVENT_ON)
return 0;
console_lock();
#ifdef CONFIG_PPC_PMAC
if (machine_is(powermac) &&
pdev->dev.power.power_state.event == PM_EVENT_SUSPEND)
aty_power_mgmt(0, par);
#endif
aty_resume_chip(info);
par->asleep = 0;
atyfb_set_par(info);
fb_set_suspend(info, 0);
par->lock_blank = 0;
atyfb_blank(FB_BLANK_UNBLANK, info);
console_unlock();
pdev->dev.power.power_state = PMSG_ON;
return 0;
}
static int aty_bl_get_level_brightness(struct atyfb_par *par, int level)
{
struct fb_info *info = pci_get_drvdata(par->pdev);
int atylevel;
atylevel = info->bl_curve[level] * FB_BACKLIGHT_MAX / MAX_LEVEL;
if (atylevel < 0)
atylevel = 0;
else if (atylevel > MAX_LEVEL)
atylevel = MAX_LEVEL;
return atylevel;
}
static int aty_bl_update_status(struct backlight_device *bd)
{
struct atyfb_par *par = bl_get_data(bd);
unsigned int reg = aty_ld_lcd(LCD_MISC_CNTL, par);
int level;
if (bd->props.power != FB_BLANK_UNBLANK ||
bd->props.fb_blank != FB_BLANK_UNBLANK)
level = 0;
else
level = bd->props.brightness;
reg |= (BLMOD_EN | BIASMOD_EN);
if (level > 0) {
reg &= ~BIAS_MOD_LEVEL_MASK;
reg |= (aty_bl_get_level_brightness(par, level) << BIAS_MOD_LEVEL_SHIFT);
} else {
reg &= ~BIAS_MOD_LEVEL_MASK;
reg |= (aty_bl_get_level_brightness(par, 0) << BIAS_MOD_LEVEL_SHIFT);
}
aty_st_lcd(LCD_MISC_CNTL, reg, par);
return 0;
}
static int aty_bl_get_brightness(struct backlight_device *bd)
{
return bd->props.brightness;
}
static void aty_bl_init(struct atyfb_par *par)
{
struct backlight_properties props;
struct fb_info *info = pci_get_drvdata(par->pdev);
struct backlight_device *bd;
char name[12];
#ifdef CONFIG_PMAC_BACKLIGHT
if (!pmac_has_backlight_type("ati"))
return;
#endif
snprintf(name, sizeof(name), "atybl%d", info->node);
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_RAW;
props.max_brightness = FB_BACKLIGHT_LEVELS - 1;
bd = backlight_device_register(name, info->dev, par, &aty_bl_data,
&props);
if (IS_ERR(bd)) {
info->bl_dev = NULL;
printk(KERN_WARNING "aty: Backlight registration failed\n");
goto error;
}
info->bl_dev = bd;
fb_bl_default_curve(info, 0,
0x3F * FB_BACKLIGHT_MAX / MAX_LEVEL,
0xFF * FB_BACKLIGHT_MAX / MAX_LEVEL);
bd->props.brightness = bd->props.max_brightness;
bd->props.power = FB_BLANK_UNBLANK;
backlight_update_status(bd);
printk("aty: Backlight initialized (%s)\n", name);
return;
error:
return;
}
static void aty_bl_exit(struct backlight_device *bd)
{
backlight_device_unregister(bd);
printk("aty: Backlight unloaded\n");
}
static void aty_calc_mem_refresh(struct atyfb_par *par, int xclk)
{
const int ragepro_tbl[] = {
44, 50, 55, 66, 75, 80, 100
};
const int ragexl_tbl[] = {
50, 66, 75, 83, 90, 95, 100, 105,
110, 115, 120, 125, 133, 143, 166
};
const int *refresh_tbl;
int i, size;
if (M64_HAS(XL_MEM)) {
refresh_tbl = ragexl_tbl;
size = ARRAY_SIZE(ragexl_tbl);
} else {
refresh_tbl = ragepro_tbl;
size = ARRAY_SIZE(ragepro_tbl);
}
for (i = 0; i < size; i++) {
if (xclk < refresh_tbl[i])
break;
}
par->mem_refresh_rate = i;
}
static int atyfb_get_timings_from_lcd(struct atyfb_par *par,
struct fb_var_screeninfo *var)
{
int ret = -EINVAL;
if (par->lcd_table != 0 && (aty_ld_lcd(LCD_GEN_CNTL, par) & LCD_ON)) {
*var = default_var;
var->xres = var->xres_virtual = par->lcd_hdisp;
var->right_margin = par->lcd_right_margin;
var->left_margin = par->lcd_hblank_len -
(par->lcd_right_margin + par->lcd_hsync_dly +
par->lcd_hsync_len);
var->hsync_len = par->lcd_hsync_len + par->lcd_hsync_dly;
var->yres = var->yres_virtual = par->lcd_vdisp;
var->lower_margin = par->lcd_lower_margin;
var->upper_margin = par->lcd_vblank_len -
(par->lcd_lower_margin + par->lcd_vsync_len);
var->vsync_len = par->lcd_vsync_len;
var->pixclock = par->lcd_pixclock;
ret = 0;
}
return ret;
}
static int aty_init(struct fb_info *info)
{
struct atyfb_par *par = (struct atyfb_par *) info->par;
const char *ramname = NULL, *xtal;
int gtb_memsize, has_var = 0;
struct fb_var_screeninfo var;
int ret;
init_waitqueue_head(&par->vblank.wait);
spin_lock_init(&par->int_lock);
#ifdef CONFIG_FB_ATY_GX
if (!M64_HAS(INTEGRATED)) {
u32 stat0;
u8 dac_type, dac_subtype, clk_type;
stat0 = aty_ld_le32(CNFG_STAT0, par);
par->bus_type = (stat0 >> 0) & 0x07;
par->ram_type = (stat0 >> 3) & 0x07;
ramname = aty_gx_ram[par->ram_type];
dac_type = (aty_ld_le32(DAC_CNTL, par) >> 16) & 0x07;
#ifdef CONFIG_ATARI
clk_type = CLK_ATI18818_1;
dac_type = (stat0 >> 9) & 0x07;
if (dac_type == 0x07)
dac_subtype = DAC_ATT20C408;
else
dac_subtype = (aty_ld_8(SCRATCH_REG1 + 1, par) & 0xF0) | dac_type;
#else
dac_type = DAC_IBMRGB514;
dac_subtype = DAC_IBMRGB514;
clk_type = CLK_IBMRGB514;
#endif
switch (dac_subtype) {
case DAC_IBMRGB514:
par->dac_ops = &aty_dac_ibm514;
break;
#ifdef CONFIG_ATARI
case DAC_ATI68860_B:
case DAC_ATI68860_C:
par->dac_ops = &aty_dac_ati68860b;
break;
case DAC_ATT20C408:
case DAC_ATT21C498:
par->dac_ops = &aty_dac_att21c498;
break;
#endif
default:
PRINTKI("aty_init: DAC type not implemented yet!\n");
par->dac_ops = &aty_dac_unsupported;
break;
}
switch (clk_type) {
#ifdef CONFIG_ATARI
case CLK_ATI18818_1:
par->pll_ops = &aty_pll_ati18818_1;
break;
#else
case CLK_IBMRGB514:
par->pll_ops = &aty_pll_ibm514;
break;
#endif
#if 0
case CLK_STG1703:
par->pll_ops = &aty_pll_stg1703;
break;
case CLK_CH8398:
par->pll_ops = &aty_pll_ch8398;
break;
case CLK_ATT20C408:
par->pll_ops = &aty_pll_att20c408;
break;
#endif
default:
PRINTKI("aty_init: CLK type not implemented yet!");
par->pll_ops = &aty_pll_unsupported;
break;
}
}
#endif
#ifdef CONFIG_FB_ATY_CT
if (M64_HAS(INTEGRATED)) {
par->dac_ops = &aty_dac_ct;
par->pll_ops = &aty_pll_ct;
par->bus_type = PCI;
par->ram_type = (aty_ld_le32(CNFG_STAT0, par) & 0x07);
if (M64_HAS(XL_MEM))
ramname = aty_xl_ram[par->ram_type];
else
ramname = aty_ct_ram[par->ram_type];
if (par->pll_limits.mclk == 67 && par->ram_type < SDRAM)
par->pll_limits.mclk = 63;
if (M64_HAS(MOBIL_BUS) && par->ram_type == SDRAM32)
par->pll_limits.xclk = (par->pll_limits.xclk + 1) >> 1;
}
#endif
#ifdef CONFIG_PPC_PMAC
if (of_machine_is_compatible("PowerBook2,1")) {
par->pll_limits.mclk = 70;
par->pll_limits.xclk = 53;
}
#endif
if (pll)
par->pll_limits.pll_max = pll;
if (mclk)
par->pll_limits.mclk = mclk;
if (xclk)
par->pll_limits.xclk = xclk;
aty_calc_mem_refresh(par, par->pll_limits.xclk);
par->pll_per = 1000000/par->pll_limits.pll_max;
par->mclk_per = 1000000/par->pll_limits.mclk;
par->xclk_per = 1000000/par->pll_limits.xclk;
par->ref_clk_per = 1000000000000ULL / 14318180;
xtal = "14.31818";
#ifdef CONFIG_FB_ATY_CT
if (M64_HAS(GTB_DSP)) {
u8 pll_ref_div = aty_ld_pll_ct(PLL_REF_DIV, par);
if (pll_ref_div) {
int diff1, diff2;
diff1 = 510 * 14 / pll_ref_div - par->pll_limits.pll_max;
diff2 = 510 * 29 / pll_ref_div - par->pll_limits.pll_max;
if (diff1 < 0)
diff1 = -diff1;
if (diff2 < 0)
diff2 = -diff2;
if (diff2 < diff1) {
par->ref_clk_per = 1000000000000ULL / 29498928;
xtal = "29.498928";
}
}
}
#endif
aty_get_crtc(par, &par->saved_crtc);
if (par->pll_ops->get_pll)
par->pll_ops->get_pll(info, &par->saved_pll);
par->mem_cntl = aty_ld_le32(MEM_CNTL, par);
gtb_memsize = M64_HAS(GTB_DSP);
if (gtb_memsize)
switch (par->mem_cntl & 0xF) {
case MEM_SIZE_512K:
info->fix.smem_len = 0x80000;
break;
case MEM_SIZE_1M:
info->fix.smem_len = 0x100000;
break;
case MEM_SIZE_2M_GTB:
info->fix.smem_len = 0x200000;
break;
case MEM_SIZE_4M_GTB:
info->fix.smem_len = 0x400000;
break;
case MEM_SIZE_6M_GTB:
info->fix.smem_len = 0x600000;
break;
case MEM_SIZE_8M_GTB:
info->fix.smem_len = 0x800000;
break;
default:
info->fix.smem_len = 0x80000;
} else
switch (par->mem_cntl & MEM_SIZE_ALIAS) {
case MEM_SIZE_512K:
info->fix.smem_len = 0x80000;
break;
case MEM_SIZE_1M:
info->fix.smem_len = 0x100000;
break;
case MEM_SIZE_2M:
info->fix.smem_len = 0x200000;
break;
case MEM_SIZE_4M:
info->fix.smem_len = 0x400000;
break;
case MEM_SIZE_6M:
info->fix.smem_len = 0x600000;
break;
case MEM_SIZE_8M:
info->fix.smem_len = 0x800000;
break;
default:
info->fix.smem_len = 0x80000;
}
if (M64_HAS(MAGIC_VRAM_SIZE)) {
if (aty_ld_le32(CNFG_STAT1, par) & 0x40000000)
info->fix.smem_len += 0x400000;
}
if (vram) {
info->fix.smem_len = vram * 1024;
par->mem_cntl &= ~(gtb_memsize ? 0xF : MEM_SIZE_ALIAS);
if (info->fix.smem_len <= 0x80000)
par->mem_cntl |= MEM_SIZE_512K;
else if (info->fix.smem_len <= 0x100000)
par->mem_cntl |= MEM_SIZE_1M;
else if (info->fix.smem_len <= 0x200000)
par->mem_cntl |= gtb_memsize ? MEM_SIZE_2M_GTB : MEM_SIZE_2M;
else if (info->fix.smem_len <= 0x400000)
par->mem_cntl |= gtb_memsize ? MEM_SIZE_4M_GTB : MEM_SIZE_4M;
else if (info->fix.smem_len <= 0x600000)
par->mem_cntl |= gtb_memsize ? MEM_SIZE_6M_GTB : MEM_SIZE_6M;
else
par->mem_cntl |= gtb_memsize ? MEM_SIZE_8M_GTB : MEM_SIZE_8M;
aty_st_le32(MEM_CNTL, par->mem_cntl, par);
}
if (M64_HAS(GX)) {
info->fix.mmio_len = 0x400;
info->fix.accel = FB_ACCEL_ATI_MACH64GX;
} else if (M64_HAS(CT)) {
info->fix.mmio_len = 0x400;
info->fix.accel = FB_ACCEL_ATI_MACH64CT;
} else if (M64_HAS(VT)) {
info->fix.mmio_start -= 0x400;
info->fix.mmio_len = 0x800;
info->fix.accel = FB_ACCEL_ATI_MACH64VT;
} else {
info->fix.mmio_start -= 0x400;
info->fix.mmio_len = 0x800;
info->fix.accel = FB_ACCEL_ATI_MACH64GT;
}
PRINTKI("%d%c %s, %s MHz XTAL, %d MHz PLL, %d Mhz MCLK, %d MHz XCLK\n",
info->fix.smem_len == 0x80000 ? 512 : (info->fix.smem_len>>20),
info->fix.smem_len == 0x80000 ? 'K' : 'M', ramname, xtal,
par->pll_limits.pll_max, par->pll_limits.mclk,
par->pll_limits.xclk);
#if defined(DEBUG) && defined(CONFIG_FB_ATY_CT)
if (M64_HAS(INTEGRATED)) {
int i;
printk("debug atyfb: BUS_CNTL DAC_CNTL MEM_CNTL "
"EXT_MEM_CNTL CRTC_GEN_CNTL DSP_CONFIG "
"DSP_ON_OFF CLOCK_CNTL\n"
"debug atyfb: %08x %08x %08x "
"%08x %08x %08x "
"%08x %08x\n"
"debug atyfb: PLL",
aty_ld_le32(BUS_CNTL, par),
aty_ld_le32(DAC_CNTL, par),
aty_ld_le32(MEM_CNTL, par),
aty_ld_le32(EXT_MEM_CNTL, par),
aty_ld_le32(CRTC_GEN_CNTL, par),
aty_ld_le32(DSP_CONFIG, par),
aty_ld_le32(DSP_ON_OFF, par),
aty_ld_le32(CLOCK_CNTL, par));
for (i = 0; i < 40; i++)
printk(" %02x", aty_ld_pll_ct(i, par));
printk("\n");
}
#endif
if (par->pll_ops->init_pll)
par->pll_ops->init_pll(info, &par->pll);
if (par->pll_ops->resume_pll)
par->pll_ops->resume_pll(info, &par->pll);
if (!par->aux_start &&
(info->fix.smem_len == 0x800000 ||
(par->bus_type == ISA && info->fix.smem_len == 0x400000)))
info->fix.smem_len -= GUI_RESERVE;
if (par->aux_start)
aty_st_le32(BUS_CNTL, aty_ld_le32(BUS_CNTL, par) |
BUS_APER_REG_DIS, par);
#ifdef CONFIG_MTRR
par->mtrr_aper = -1;
par->mtrr_reg = -1;
if (!nomtrr) {
par->mtrr_aper = mtrr_add(par->res_start, par->res_size,
MTRR_TYPE_WRCOMB, 1);
if (par->mtrr_aper >= 0 && !par->aux_start) {
par->mtrr_reg = mtrr_add(par->res_start + 0x800000 -
GUI_RESERVE, GUI_RESERVE,
MTRR_TYPE_UNCACHABLE, 1);
if (par->mtrr_reg < 0) {
mtrr_del(par->mtrr_aper, 0, 0);
par->mtrr_aper = -1;
}
}
}
#endif
info->fbops = &atyfb_ops;
info->pseudo_palette = par->pseudo_palette;
info->flags = FBINFO_DEFAULT |
FBINFO_HWACCEL_IMAGEBLIT |
FBINFO_HWACCEL_FILLRECT |
FBINFO_HWACCEL_COPYAREA |
FBINFO_HWACCEL_YPAN;
#ifdef CONFIG_PMAC_BACKLIGHT
if (M64_HAS(G3_PB_1_1) && of_machine_is_compatible("PowerBook1,1")) {
aty_st_lcd(POWER_MANAGEMENT, aty_ld_lcd(POWER_MANAGEMENT, par) |
USE_F32KHZ | TRISTATE_MEM_EN, par);
} else
#endif
if (M64_HAS(MOBIL_BUS) && backlight) {
#ifdef CONFIG_FB_ATY_BACKLIGHT
aty_bl_init(par);
#endif
}
memset(&var, 0, sizeof(var));
#ifdef CONFIG_PPC
if (machine_is(powermac)) {
if (mode) {
if (mac_find_mode(&var, info, mode, 8))
has_var = 1;
} else {
if (default_vmode == VMODE_CHOOSE) {
int sense;
if (M64_HAS(G3_PB_1024x768))
default_vmode = VMODE_1024_768_60;
else if (of_machine_is_compatible("iMac"))
default_vmode = VMODE_1024_768_75;
else if (of_machine_is_compatible("PowerBook2,1"))
default_vmode = VMODE_800_600_60;
else
default_vmode = VMODE_640_480_67;
sense = read_aty_sense(par);
PRINTKI("monitor sense=%x, mode %d\n",
sense, mac_map_monitor_sense(sense));
}
if (default_vmode <= 0 || default_vmode > VMODE_MAX)
default_vmode = VMODE_640_480_60;
if (default_cmode < CMODE_8 || default_cmode > CMODE_32)
default_cmode = CMODE_8;
if (!mac_vmode_to_var(default_vmode, default_cmode,
&var))
has_var = 1;
}
}
#endif
#if defined(__i386__) && defined(CONFIG_FB_ATY_GENERIC_LCD)
if (!atyfb_get_timings_from_lcd(par, &var))
has_var = 1;
#endif
if (mode && fb_find_mode(&var, info, mode, NULL, 0, &defmode, 8))
has_var = 1;
if (!has_var)
var = default_var;
if (noaccel)
var.accel_flags &= ~FB_ACCELF_TEXT;
else
var.accel_flags |= FB_ACCELF_TEXT;
if (comp_sync != -1) {
if (!comp_sync)
var.sync &= ~FB_SYNC_COMP_HIGH_ACT;
else
var.sync |= FB_SYNC_COMP_HIGH_ACT;
}
if (var.yres == var.yres_virtual) {
u32 videoram = (info->fix.smem_len - (PAGE_SIZE << 2));
var.yres_virtual = ((videoram * 8) / var.bits_per_pixel) / var.xres_virtual;
if (var.yres_virtual < var.yres)
var.yres_virtual = var.yres;
}
ret = atyfb_check_var(&var, info);
if (ret) {
PRINTKE("can't set default video mode\n");
goto aty_init_exit;
}
#ifdef CONFIG_FB_ATY_CT
if (!noaccel && M64_HAS(INTEGRATED))
aty_init_cursor(info);
#endif
info->var = var;
ret = fb_alloc_cmap(&info->cmap, 256, 0);
if (ret < 0)
goto aty_init_exit;
ret = register_framebuffer(info);
if (ret < 0) {
fb_dealloc_cmap(&info->cmap);
goto aty_init_exit;
}
fb_list = info;
PRINTKI("fb%d: %s frame buffer device on %s\n",
info->node, info->fix.id, par->bus_type == ISA ? "ISA" : "PCI");
return 0;
aty_init_exit:
aty_set_crtc(par, &par->saved_crtc);
par->pll_ops->set_pll(info, &par->saved_pll);
#ifdef CONFIG_MTRR
if (par->mtrr_reg >= 0) {
mtrr_del(par->mtrr_reg, 0, 0);
par->mtrr_reg = -1;
}
if (par->mtrr_aper >= 0) {
mtrr_del(par->mtrr_aper, 0, 0);
par->mtrr_aper = -1;
}
#endif
return ret;
}
static int store_video_par(char *video_str, unsigned char m64_num)
{
char *p;
unsigned long vmembase, size, guiregbase;
PRINTKI("store_video_par() '%s' \n", video_str);
if (!(p = strsep(&video_str, ";")) || !*p)
goto mach64_invalid;
vmembase = simple_strtoul(p, NULL, 0);
if (!(p = strsep(&video_str, ";")) || !*p)
goto mach64_invalid;
size = simple_strtoul(p, NULL, 0);
if (!(p = strsep(&video_str, ";")) || !*p)
goto mach64_invalid;
guiregbase = simple_strtoul(p, NULL, 0);
phys_vmembase[m64_num] = vmembase;
phys_size[m64_num] = size;
phys_guiregbase[m64_num] = guiregbase;
PRINTKI("stored them all: $%08lX $%08lX $%08lX \n", vmembase, size,
guiregbase);
return 0;
mach64_invalid:
phys_vmembase[m64_num] = 0;
return -1;
}
static int atyfb_blank(int blank, struct fb_info *info)
{
struct atyfb_par *par = (struct atyfb_par *) info->par;
u32 gen_cntl;
if (par->lock_blank || par->asleep)
return 0;
#ifdef CONFIG_FB_ATY_GENERIC_LCD
if (par->lcd_table && blank > FB_BLANK_NORMAL &&
(aty_ld_lcd(LCD_GEN_CNTL, par) & LCD_ON)) {
u32 pm = aty_ld_lcd(POWER_MANAGEMENT, par);
pm &= ~PWR_BLON;
aty_st_lcd(POWER_MANAGEMENT, pm, par);
}
#endif
gen_cntl = aty_ld_le32(CRTC_GEN_CNTL, par);
gen_cntl &= ~0x400004c;
switch (blank) {
case FB_BLANK_UNBLANK:
break;
case FB_BLANK_NORMAL:
gen_cntl |= 0x4000040;
break;
case FB_BLANK_VSYNC_SUSPEND:
gen_cntl |= 0x4000048;
break;
case FB_BLANK_HSYNC_SUSPEND:
gen_cntl |= 0x4000044;
break;
case FB_BLANK_POWERDOWN:
gen_cntl |= 0x400004c;
break;
}
aty_st_le32(CRTC_GEN_CNTL, gen_cntl, par);
#ifdef CONFIG_FB_ATY_GENERIC_LCD
if (par->lcd_table && blank <= FB_BLANK_NORMAL &&
(aty_ld_lcd(LCD_GEN_CNTL, par) & LCD_ON)) {
u32 pm = aty_ld_lcd(POWER_MANAGEMENT, par);
pm |= PWR_BLON;
aty_st_lcd(POWER_MANAGEMENT, pm, par);
}
#endif
return 0;
}
static void aty_st_pal(u_int regno, u_int red, u_int green, u_int blue,
const struct atyfb_par *par)
{
aty_st_8(DAC_W_INDEX, regno, par);
aty_st_8(DAC_DATA, red, par);
aty_st_8(DAC_DATA, green, par);
aty_st_8(DAC_DATA, blue, par);
}
static int atyfb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
u_int transp, struct fb_info *info)
{
struct atyfb_par *par = (struct atyfb_par *) info->par;
int i, depth;
u32 *pal = info->pseudo_palette;
depth = info->var.bits_per_pixel;
if (depth == 16)
depth = (info->var.green.length == 5) ? 15 : 16;
if (par->asleep)
return 0;
if (regno > 255 ||
(depth == 16 && regno > 63) ||
(depth == 15 && regno > 31))
return 1;
red >>= 8;
green >>= 8;
blue >>= 8;
par->palette[regno].red = red;
par->palette[regno].green = green;
par->palette[regno].blue = blue;
if (regno < 16) {
switch (depth) {
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
i = aty_ld_8(DAC_CNTL, par) & 0xfc;
if (M64_HAS(EXTRA_BRIGHT))
i |= 0x2;
aty_st_8(DAC_CNTL, i, par);
aty_st_8(DAC_MASK, 0xff, par);
if (M64_HAS(INTEGRATED)) {
if (depth == 16) {
if (regno < 32)
aty_st_pal(regno << 3, red,
par->palette[regno << 1].green,
blue, par);
red = par->palette[regno >> 1].red;
blue = par->palette[regno >> 1].blue;
regno <<= 2;
} else if (depth == 15) {
regno <<= 3;
for (i = 0; i < 8; i++)
aty_st_pal(regno + i, red, green, blue, par);
}
}
aty_st_pal(regno, red, green, blue, par);
return 0;
}
static int atyfb_setup_sparc(struct pci_dev *pdev, struct fb_info *info,
unsigned long addr)
{
struct atyfb_par *par = info->par;
struct device_node *dp;
u32 mem, chip_id;
int i, j, ret;
par->ati_regbase = (void *)addr + 0x7ffc00UL;
info->fix.mmio_start = addr + 0x7ffc00UL;
info->screen_base = (char *) (addr + 0x800000UL);
info->fix.smem_start = addr + 0x800000UL;
for (i = 0; i < 6 && pdev->resource[i].start; i++)
;
j = i + 4;
par->mmap_map = kcalloc(j, sizeof(*par->mmap_map), GFP_ATOMIC);
if (!par->mmap_map) {
PRINTKE("atyfb_setup_sparc() can't alloc mmap_map\n");
return -ENOMEM;
}
for (i = 0, j = 2; i < 6 && pdev->resource[i].start; i++) {
struct resource *rp = &pdev->resource[i];
int io, breg = PCI_BASE_ADDRESS_0 + (i << 2);
unsigned long base;
u32 size, pbase;
base = rp->start;
io = (rp->flags & IORESOURCE_IO);
size = rp->end - base + 1;
pci_read_config_dword(pdev, breg, &pbase);
if (io)
size &= ~1;
if (base == addr) {
par->mmap_map[j].voff = (pbase + 0x10000000) & PAGE_MASK;
par->mmap_map[j].poff = base & PAGE_MASK;
par->mmap_map[j].size = (size + ~PAGE_MASK) & PAGE_MASK;
par->mmap_map[j].prot_mask = _PAGE_CACHE;
par->mmap_map[j].prot_flag = _PAGE_E;
j++;
}
if (base == addr) {
par->mmap_map[j].voff = (pbase + 0x800000) & PAGE_MASK;
par->mmap_map[j].poff = (base + 0x800000) & PAGE_MASK;
par->mmap_map[j].size = 0x800000;
par->mmap_map[j].prot_mask = _PAGE_CACHE;
par->mmap_map[j].prot_flag = _PAGE_E | _PAGE_IE;
size -= 0x800000;
j++;
}
par->mmap_map[j].voff = pbase & PAGE_MASK;
par->mmap_map[j].poff = base & PAGE_MASK;
par->mmap_map[j].size = (size + ~PAGE_MASK) & PAGE_MASK;
par->mmap_map[j].prot_mask = _PAGE_CACHE;
par->mmap_map[j].prot_flag = _PAGE_E;
j++;
}
ret = correct_chipset(par);
if (ret)
return ret;
if (IS_XL(pdev->device)) {
mem = aty_ld_le32(MEM_CNTL, par);
chip_id = aty_ld_le32(CNFG_CHIP_ID, par);
if (((chip_id & CFG_CHIP_TYPE) == VT_CHIP_ID) && !((chip_id >> 24) & 1)) {
switch (mem & 0x0f) {
case 3:
mem = (mem & ~(0x0f)) | 2;
break;
case 7:
mem = (mem & ~(0x0f)) | 3;
break;
case 9:
mem = (mem & ~(0x0f)) | 4;
break;
case 11:
mem = (mem & ~(0x0f)) | 5;
break;
default:
break;
}
if ((aty_ld_le32(CNFG_STAT0, par) & 7) >= SDRAM)
mem &= ~(0x00700000);
}
mem &= ~(0xcf80e000);
aty_st_le32(MEM_CNTL, mem, par);
}
dp = pci_device_to_OF_node(pdev);
if (dp == of_console_device) {
struct fb_var_screeninfo *var = &default_var;
unsigned int N, P, Q, M, T, R;
u32 v_total, h_total;
struct crtc crtc;
u8 pll_regs[16];
u8 clock_cntl;
crtc.vxres = of_getintprop_default(dp, "width", 1024);
crtc.vyres = of_getintprop_default(dp, "height", 768);
var->bits_per_pixel = of_getintprop_default(dp, "depth", 8);
var->xoffset = var->yoffset = 0;
crtc.h_tot_disp = aty_ld_le32(CRTC_H_TOTAL_DISP, par);
crtc.h_sync_strt_wid = aty_ld_le32(CRTC_H_SYNC_STRT_WID, par);
crtc.v_tot_disp = aty_ld_le32(CRTC_V_TOTAL_DISP, par);
crtc.v_sync_strt_wid = aty_ld_le32(CRTC_V_SYNC_STRT_WID, par);
crtc.gen_cntl = aty_ld_le32(CRTC_GEN_CNTL, par);
aty_crtc_to_var(&crtc, var);
h_total = var->xres + var->right_margin + var->hsync_len + var->left_margin;
v_total = var->yres + var->lower_margin + var->vsync_len + var->upper_margin;
clock_cntl = aty_ld_8(CLOCK_CNTL, par);
for (i = 0; i < 16; i++)
pll_regs[i] = aty_ld_pll_ct(i, par);
M = pll_regs[2];
N = pll_regs[7 + (clock_cntl & 3)];
P = 1 << (pll_regs[6] >> ((clock_cntl & 3) << 1));
Q = N / P;
if (IS_XL(pdev->device))
R = 29498;
else
R = 14318;
T = 2 * Q * R / M;
default_var.pixclock = 1000000000 / T;
}
return 0;
}
static void aty_init_lcd(struct atyfb_par *par, u32 bios_base)
{
u32 driv_inf_tab, sig;
u16 lcd_ofs;
driv_inf_tab = bios_base + *((u16 *)(bios_base+0x78));
sig = *(u32 *)driv_inf_tab;
if ((sig == 0x54504c24) ||
(sig == 0x544d5224) ||
(sig == 0x54435824) ||
(sig == 0x544c5824)) {
PRINTKI("BIOS contains driver information table.\n");
lcd_ofs = *(u16 *)(driv_inf_tab + 10);
par->lcd_table = 0;
if (lcd_ofs != 0)
par->lcd_table = bios_base + lcd_ofs;
}
if (par->lcd_table != 0) {
char model[24];
char strbuf[16];
char refresh_rates_buf[100];
int id, tech, f, i, m, default_refresh_rate;
char *txtcolour;
char *txtmonitor;
char *txtdual;
char *txtformat;
u16 width, height, panel_type, refresh_rates;
u16 *lcdmodeptr;
u32 format;
u8 lcd_refresh_rates[16] = { 50, 56, 60, 67, 70, 72, 75, 76, 85,
90, 100, 120, 140, 150, 160, 200 };
id = *(u8 *)par->lcd_table;
strncpy(model, (char *)par->lcd_table+1, 24);
model[23] = 0;
width = par->lcd_width = *(u16 *)(par->lcd_table+25);
height = par->lcd_height = *(u16 *)(par->lcd_table+27);
panel_type = *(u16 *)(par->lcd_table+29);
if (panel_type & 1)
txtcolour = "colour";
else
txtcolour = "monochrome";
if (panel_type & 2)
txtdual = "dual (split) ";
else
txtdual = "";
tech = (panel_type >> 2) & 63;
switch (tech) {
case 0:
txtmonitor = "passive matrix";
break;
case 1:
txtmonitor = "active matrix";
break;
case 2:
txtmonitor = "active addressed STN";
break;
case 3:
txtmonitor = "EL";
break;
case 4:
txtmonitor = "plasma";
break;
default:
txtmonitor = "unknown";
}
format = *(u32 *)(par->lcd_table+57);
if (tech == 0 || tech == 2) {
switch (format & 7) {
case 0:
txtformat = "12 bit interface";
break;
case 1:
txtformat = "16 bit interface";
break;
case 2:
txtformat = "24 bit interface";
break;
default:
txtformat = "unknown format";
}
} else {
switch (format & 7) {
case 0:
txtformat = "8 colours";
break;
case 1:
txtformat = "512 colours";
break;
case 2:
txtformat = "4096 colours";
break;
case 4:
txtformat = "262144 colours (LT mode)";
break;
case 5:
txtformat = "16777216 colours";
break;
case 6:
txtformat = "262144 colours (FDPI-2 mode)";
break;
default:
txtformat = "unknown format";
}
}
PRINTKI("%s%s %s monitor detected: %s\n",
txtdual, txtcolour, txtmonitor, model);
PRINTKI(" id=%d, %dx%d pixels, %s\n",
id, width, height, txtformat);
refresh_rates_buf[0] = 0;
refresh_rates = *(u16 *)(par->lcd_table+62);
m = 1;
f = 0;
for (i = 0; i < 16; i++) {
if (refresh_rates & m) {
if (f == 0) {
sprintf(strbuf, "%d",
lcd_refresh_rates[i]);
f++;
} else {
sprintf(strbuf, ",%d",
lcd_refresh_rates[i]);
}
strcat(refresh_rates_buf, strbuf);
}
m = m << 1;
}
default_refresh_rate = (*(u8 *)(par->lcd_table+61) & 0xf0) >> 4;
PRINTKI(" supports refresh rates [%s], default %d Hz\n",
refresh_rates_buf, lcd_refresh_rates[default_refresh_rate]);
par->lcd_refreshrate = lcd_refresh_rates[default_refresh_rate];
lcdmodeptr = (u16 *)(par->lcd_table + 64);
while (*lcdmodeptr != 0) {
u32 modeptr;
u16 mwidth, mheight, lcd_hsync_start, lcd_vsync_start;
modeptr = bios_base + *lcdmodeptr;
mwidth = *((u16 *)(modeptr+0));
mheight = *((u16 *)(modeptr+2));
if (mwidth == width && mheight == height) {
par->lcd_pixclock = 100000000 / *((u16 *)(modeptr+9));
par->lcd_htotal = *((u16 *)(modeptr+17)) & 511;
par->lcd_hdisp = *((u16 *)(modeptr+19)) & 511;
lcd_hsync_start = *((u16 *)(modeptr+21)) & 511;
par->lcd_hsync_dly = (*((u16 *)(modeptr+21)) >> 9) & 7;
par->lcd_hsync_len = *((u8 *)(modeptr+23)) & 63;
par->lcd_vtotal = *((u16 *)(modeptr+24)) & 2047;
par->lcd_vdisp = *((u16 *)(modeptr+26)) & 2047;
lcd_vsync_start = *((u16 *)(modeptr+28)) & 2047;
par->lcd_vsync_len = (*((u16 *)(modeptr+28)) >> 11) & 31;
par->lcd_htotal = (par->lcd_htotal + 1) * 8;
par->lcd_hdisp = (par->lcd_hdisp + 1) * 8;
lcd_hsync_start = (lcd_hsync_start + 1) * 8;
par->lcd_hsync_len = par->lcd_hsync_len * 8;
par->lcd_vtotal++;
par->lcd_vdisp++;
lcd_vsync_start++;
par->lcd_right_margin = lcd_hsync_start - par->lcd_hdisp;
par->lcd_lower_margin = lcd_vsync_start - par->lcd_vdisp;
par->lcd_hblank_len = par->lcd_htotal - par->lcd_hdisp;
par->lcd_vblank_len = par->lcd_vtotal - par->lcd_vdisp;
break;
}
lcdmodeptr++;
}
if (*lcdmodeptr == 0) {
PRINTKE("LCD monitor CRTC parameters not found!!!\n");
} else {
PRINTKI(" LCD CRTC parameters: %d.%d %d %d %d %d %d %d %d %d\n",
1000000 / par->lcd_pixclock, 1000000 % par->lcd_pixclock,
par->lcd_hdisp,
par->lcd_hdisp + par->lcd_right_margin,
par->lcd_hdisp + par->lcd_right_margin
+ par->lcd_hsync_dly + par->lcd_hsync_len,
par->lcd_htotal,
par->lcd_vdisp,
par->lcd_vdisp + par->lcd_lower_margin,
par->lcd_vdisp + par->lcd_lower_margin + par->lcd_vsync_len,
par->lcd_vtotal);
PRINTKI(" : %d %d %d %d %d %d %d %d %d\n",
par->lcd_pixclock,
par->lcd_hblank_len - (par->lcd_right_margin +
par->lcd_hsync_dly + par->lcd_hsync_len),
par->lcd_hdisp,
par->lcd_right_margin,
par->lcd_hsync_len,
par->lcd_vblank_len - (par->lcd_lower_margin + par->lcd_vsync_len),
par->lcd_vdisp,
par->lcd_lower_margin,
par->lcd_vsync_len);
}
}
}
static int init_from_bios(struct atyfb_par *par)
{
u32 bios_base, rom_addr;
int ret;
rom_addr = 0xc0000 + ((aty_ld_le32(SCRATCH_REG1, par) & 0x7f) << 11);
bios_base = (unsigned long)ioremap(rom_addr, 0x10000);
if (*((u16 *)bios_base) == 0xaa55) {
u8 *bios_ptr;
u16 rom_table_offset, freq_table_offset;
PLL_BLOCK_MACH64 pll_block;
PRINTKI("Mach64 BIOS is located at %x, mapped at %x.\n", rom_addr, bios_base);
bios_ptr = (u8*)bios_base;
rom_table_offset = (u16)(bios_ptr[0x48] | (bios_ptr[0x49] << 8));
freq_table_offset = bios_ptr[rom_table_offset + 16] | (bios_ptr[rom_table_offset + 17] << 8);
memcpy(&pll_block, bios_ptr + freq_table_offset, sizeof(PLL_BLOCK_MACH64));
PRINTKI("BIOS frequency table:\n");
PRINTKI("PCLK_min_freq %d, PCLK_max_freq %d, ref_freq %d, ref_divider %d\n",
pll_block.PCLK_min_freq, pll_block.PCLK_max_freq,
pll_block.ref_freq, pll_block.ref_divider);
PRINTKI("MCLK_pwd %d, MCLK_max_freq %d, XCLK_max_freq %d, SCLK_freq %d\n",
pll_block.MCLK_pwd, pll_block.MCLK_max_freq,
pll_block.XCLK_max_freq, pll_block.SCLK_freq);
par->pll_limits.pll_min = pll_block.PCLK_min_freq/100;
par->pll_limits.pll_max = pll_block.PCLK_max_freq/100;
par->pll_limits.ref_clk = pll_block.ref_freq/100;
par->pll_limits.ref_div = pll_block.ref_divider;
par->pll_limits.sclk = pll_block.SCLK_freq/100;
par->pll_limits.mclk = pll_block.MCLK_max_freq/100;
par->pll_limits.mclk_pm = pll_block.MCLK_pwd/100;
par->pll_limits.xclk = pll_block.XCLK_max_freq/100;
#ifdef CONFIG_FB_ATY_GENERIC_LCD
aty_init_lcd(par, bios_base);
#endif
ret = 0;
} else {
PRINTKE("no BIOS frequency table found, use parameters\n");
ret = -ENXIO;
}
iounmap((void __iomem *)bios_base);
return ret;
}
static int atyfb_setup_generic(struct pci_dev *pdev, struct fb_info *info,
unsigned long addr)
{
struct atyfb_par *par = info->par;
u16 tmp;
unsigned long raddr;
struct resource *rrp;
int ret = 0;
raddr = addr + 0x7ff000UL;
rrp = &pdev->resource[2];
if ((rrp->flags & IORESOURCE_MEM) &&
request_mem_region(rrp->start, resource_size(rrp), "atyfb")) {
par->aux_start = rrp->start;
par->aux_size = resource_size(rrp);
raddr = rrp->start;
PRINTKI("using auxiliary register aperture\n");
}
info->fix.mmio_start = raddr;
par->ati_regbase = ioremap(info->fix.mmio_start, 0x1000);
if (par->ati_regbase == NULL)
return -ENOMEM;
info->fix.mmio_start += par->aux_start ? 0x400 : 0xc00;
par->ati_regbase += par->aux_start ? 0x400 : 0xc00;
pci_read_config_word(pdev, PCI_COMMAND, &tmp);
if (!(tmp & PCI_COMMAND_MEMORY)) {
tmp |= PCI_COMMAND_MEMORY;
pci_write_config_word(pdev, PCI_COMMAND, tmp);
}
#ifdef __BIG_ENDIAN
addr += 0x800000;
#endif
info->fix.smem_start = addr;
info->screen_base = ioremap(addr, 0x800000);
if (info->screen_base == NULL) {
ret = -ENOMEM;
goto atyfb_setup_generic_fail;
}
ret = correct_chipset(par);
if (ret)
goto atyfb_setup_generic_fail;
#ifdef __i386__
ret = init_from_bios(par);
if (ret)
goto atyfb_setup_generic_fail;
#endif
if (!(aty_ld_le32(CRTC_GEN_CNTL, par) & CRTC_EXT_DISP_EN))
par->clk_wr_offset = (inb(R_GENMO) & 0x0CU) >> 2;
else
par->clk_wr_offset = aty_ld_8(CLOCK_CNTL, par) & 0x03U;
par->clk_wr_offset = 3;
return 0;
atyfb_setup_generic_fail:
iounmap(par->ati_regbase);
par->ati_regbase = NULL;
if (info->screen_base) {
iounmap(info->screen_base);
info->screen_base = NULL;
}
return ret;
}
static int atyfb_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
unsigned long addr, res_start, res_size;
struct fb_info *info;
struct resource *rp;
struct atyfb_par *par;
int rc = -ENOMEM;
if (pci_enable_device(pdev)) {
PRINTKE("Cannot enable PCI device\n");
return -ENXIO;
}
rp = &pdev->resource[0];
if (rp->flags & IORESOURCE_IO)
rp = &pdev->resource[1];
addr = rp->start;
if (!addr)
return -ENXIO;
res_start = rp->start;
res_size = resource_size(rp);
if (!request_mem_region(res_start, res_size, "atyfb"))
return -EBUSY;
info = framebuffer_alloc(sizeof(struct atyfb_par), &pdev->dev);
if (!info) {
PRINTKE("atyfb_pci_probe() can't alloc fb_info\n");
return -ENOMEM;
}
par = info->par;
info->fix = atyfb_fix;
info->device = &pdev->dev;
par->pci_id = pdev->device;
par->res_start = res_start;
par->res_size = res_size;
par->irq = pdev->irq;
par->pdev = pdev;
#ifdef __sparc__
rc = atyfb_setup_sparc(pdev, info, addr);
#else
rc = atyfb_setup_generic(pdev, info, addr);
#endif
if (rc)
goto err_release_mem;
pci_set_drvdata(pdev, info);
rc = aty_init(info);
if (rc)
goto err_release_io;
#ifdef __sparc__
par->mmap_map[0].voff = 0x8000000000000000UL;
par->mmap_map[0].poff = (unsigned long) info->screen_base & PAGE_MASK;
par->mmap_map[0].size = info->fix.smem_len;
par->mmap_map[0].prot_mask = _PAGE_CACHE;
par->mmap_map[0].prot_flag = _PAGE_E;
par->mmap_map[1].voff = par->mmap_map[0].voff + info->fix.smem_len;
par->mmap_map[1].poff = (long)par->ati_regbase & PAGE_MASK;
par->mmap_map[1].size = PAGE_SIZE;
par->mmap_map[1].prot_mask = _PAGE_CACHE;
par->mmap_map[1].prot_flag = _PAGE_E;
#endif
mutex_lock(&reboot_lock);
if (!reboot_info)
reboot_info = info;
mutex_unlock(&reboot_lock);
return 0;
err_release_io:
#ifdef __sparc__
kfree(par->mmap_map);
#else
if (par->ati_regbase)
iounmap(par->ati_regbase);
if (info->screen_base)
iounmap(info->screen_base);
#endif
err_release_mem:
if (par->aux_start)
release_mem_region(par->aux_start, par->aux_size);
release_mem_region(par->res_start, par->res_size);
framebuffer_release(info);
return rc;
}
static int __init atyfb_atari_probe(void)
{
struct atyfb_par *par;
struct fb_info *info;
int m64_num;
u32 clock_r;
int num_found = 0;
for (m64_num = 0; m64_num < mach64_count; m64_num++) {
if (!phys_vmembase[m64_num] || !phys_size[m64_num] ||
!phys_guiregbase[m64_num]) {
PRINTKI("phys_*[%d] parameters not set => "
"returning early. \n", m64_num);
continue;
}
info = framebuffer_alloc(sizeof(struct atyfb_par), NULL);
if (!info) {
PRINTKE("atyfb_atari_probe() can't alloc fb_info\n");
return -ENOMEM;
}
par = info->par;
info->fix = atyfb_fix;
par->irq = (unsigned int) -1;
info->screen_base = ioremap(phys_vmembase[m64_num], phys_size[m64_num]);
info->fix.smem_start = (unsigned long)info->screen_base;
par->ati_regbase = ioremap(phys_guiregbase[m64_num], 0x10000) +
0xFC00ul;
info->fix.mmio_start = (unsigned long)par->ati_regbase;
aty_st_le32(CLOCK_CNTL, 0x12345678, par);
clock_r = aty_ld_le32(CLOCK_CNTL, par);
switch (clock_r & 0x003F) {
case 0x12:
par->clk_wr_offset = 3;
break;
case 0x34:
par->clk_wr_offset = 2;
break;
case 0x16:
par->clk_wr_offset = 1;
break;
case 0x38:
par->clk_wr_offset = 0;
break;
}
switch (aty_ld_le32(CNFG_CHIP_ID, par) & CFG_CHIP_TYPE) {
case 0x00d7:
par->pci_id = PCI_CHIP_MACH64GX;
break;
case 0x0057:
par->pci_id = PCI_CHIP_MACH64CX;
break;
default:
break;
}
if (correct_chipset(par) || aty_init(info)) {
iounmap(info->screen_base);
iounmap(par->ati_regbase);
framebuffer_release(info);
} else {
num_found++;
}
}
return num_found ? 0 : -ENXIO;
}
static void atyfb_remove(struct fb_info *info)
{
struct atyfb_par *par = (struct atyfb_par *) info->par;
aty_set_crtc(par, &par->saved_crtc);
par->pll_ops->set_pll(info, &par->saved_pll);
unregister_framebuffer(info);
#ifdef CONFIG_FB_ATY_BACKLIGHT
if (M64_HAS(MOBIL_BUS))
aty_bl_exit(info->bl_dev);
#endif
#ifdef CONFIG_MTRR
if (par->mtrr_reg >= 0) {
mtrr_del(par->mtrr_reg, 0, 0);
par->mtrr_reg = -1;
}
if (par->mtrr_aper >= 0) {
mtrr_del(par->mtrr_aper, 0, 0);
par->mtrr_aper = -1;
}
#endif
#ifndef __sparc__
if (par->ati_regbase)
iounmap(par->ati_regbase);
if (info->screen_base)
iounmap(info->screen_base);
#ifdef __BIG_ENDIAN
if (info->sprite.addr)
iounmap(info->sprite.addr);
#endif
#endif
#ifdef __sparc__
kfree(par->mmap_map);
#endif
if (par->aux_start)
release_mem_region(par->aux_start, par->aux_size);
if (par->res_start)
release_mem_region(par->res_start, par->res_size);
framebuffer_release(info);
}
static void atyfb_pci_remove(struct pci_dev *pdev)
{
struct fb_info *info = pci_get_drvdata(pdev);
mutex_lock(&reboot_lock);
if (reboot_info == info)
reboot_info = NULL;
mutex_unlock(&reboot_lock);
atyfb_remove(info);
}
static int __init atyfb_setup(char *options)
{
char *this_opt;
if (!options || !*options)
return 0;
while ((this_opt = strsep(&options, ",")) != NULL) {
if (!strncmp(this_opt, "noaccel", 7)) {
noaccel = 1;
#ifdef CONFIG_MTRR
} else if (!strncmp(this_opt, "nomtrr", 6)) {
nomtrr = 1;
#endif
} else if (!strncmp(this_opt, "vram:", 5))
vram = simple_strtoul(this_opt + 5, NULL, 0);
else if (!strncmp(this_opt, "pll:", 4))
pll = simple_strtoul(this_opt + 4, NULL, 0);
else if (!strncmp(this_opt, "mclk:", 5))
mclk = simple_strtoul(this_opt + 5, NULL, 0);
else if (!strncmp(this_opt, "xclk:", 5))
xclk = simple_strtoul(this_opt+5, NULL, 0);
else if (!strncmp(this_opt, "comp_sync:", 10))
comp_sync = simple_strtoul(this_opt+10, NULL, 0);
else if (!strncmp(this_opt, "backlight:", 10))
backlight = simple_strtoul(this_opt+10, NULL, 0);
#ifdef CONFIG_PPC
else if (!strncmp(this_opt, "vmode:", 6)) {
unsigned int vmode =
simple_strtoul(this_opt + 6, NULL, 0);
if (vmode > 0 && vmode <= VMODE_MAX)
default_vmode = vmode;
} else if (!strncmp(this_opt, "cmode:", 6)) {
unsigned int cmode =
simple_strtoul(this_opt + 6, NULL, 0);
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
}
#endif
#ifdef CONFIG_ATARI
else if (MACH_IS_ATARI
&& (!strncmp(this_opt, "Mach64:", 7))) {
static unsigned char m64_num;
static char mach64_str[80];
strlcpy(mach64_str, this_opt + 7, sizeof(mach64_str));
if (!store_video_par(mach64_str, m64_num)) {
m64_num++;
mach64_count = m64_num;
}
}
#endif
else
mode = this_opt;
}
return 0;
}
static int atyfb_reboot_notify(struct notifier_block *nb,
unsigned long code, void *unused)
{
struct atyfb_par *par;
if (code != SYS_RESTART)
return NOTIFY_DONE;
mutex_lock(&reboot_lock);
if (!reboot_info)
goto out;
if (!lock_fb_info(reboot_info))
goto out;
par = reboot_info->par;
aty_set_crtc(par, &par->saved_crtc);
par->pll_ops->set_pll(reboot_info, &par->saved_pll);
unlock_fb_info(reboot_info);
out:
mutex_unlock(&reboot_lock);
return NOTIFY_DONE;
}
static int __init atyfb_init(void)
{
int err1 = 1, err2 = 1;
#ifndef MODULE
char *option = NULL;
if (fb_get_options("atyfb", &option))
return -ENODEV;
atyfb_setup(option);
#endif
#ifdef CONFIG_PCI
err1 = pci_register_driver(&atyfb_driver);
#endif
#ifdef CONFIG_ATARI
err2 = atyfb_atari_probe();
#endif
if (err1 && err2)
return -ENODEV;
if (dmi_check_system(atyfb_reboot_ids))
register_reboot_notifier(&atyfb_reboot_notifier);
return 0;
}
static void __exit atyfb_exit(void)
{
if (dmi_check_system(atyfb_reboot_ids))
unregister_reboot_notifier(&atyfb_reboot_notifier);
#ifdef CONFIG_PCI
pci_unregister_driver(&atyfb_driver);
#endif
}
