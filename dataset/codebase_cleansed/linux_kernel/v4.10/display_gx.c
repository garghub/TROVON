unsigned int gx_frame_buffer_size(void)
{
unsigned int val;
if (!cs5535_has_vsa2()) {
uint32_t hi, lo;
rdmsr(MSR_GLIU_P2D_RO0, lo, hi);
val = ((hi & 0xff) << 12) | ((lo & 0xfff00000) >> 20);
val -= (lo & 0x000fffff);
val += 1;
return (val << 12);
}
outw(VSA_VR_UNLOCK, VSA_VRC_INDEX);
outw(VSA_VR_MEM_SIZE, VSA_VRC_INDEX);
val = (unsigned int)(inw(VSA_VRC_DATA)) & 0xFFl;
return (val << 19);
}
int gx_line_delta(int xres, int bpp)
{
return (xres * (bpp >> 3) + 7) & ~0x7;
}
void gx_set_mode(struct fb_info *info)
{
struct gxfb_par *par = info->par;
u32 gcfg, dcfg;
int hactive, hblankstart, hsyncstart, hsyncend, hblankend, htotal;
int vactive, vblankstart, vsyncstart, vsyncend, vblankend, vtotal;
write_dc(par, DC_UNLOCK, DC_UNLOCK_UNLOCK);
gcfg = read_dc(par, DC_GENERAL_CFG);
dcfg = read_dc(par, DC_DISPLAY_CFG);
dcfg &= ~DC_DISPLAY_CFG_TGEN;
write_dc(par, DC_DISPLAY_CFG, dcfg);
udelay(100);
gcfg &= ~(DC_GENERAL_CFG_DFLE | DC_GENERAL_CFG_CMPE |
DC_GENERAL_CFG_DECE);
write_dc(par, DC_GENERAL_CFG, gcfg);
gx_set_dclk_frequency(info);
gcfg &= DC_GENERAL_CFG_YUVM | DC_GENERAL_CFG_VDSE;
dcfg = 0;
gcfg |= (6 << DC_GENERAL_CFG_DFHPEL_SHIFT) |
(5 << DC_GENERAL_CFG_DFHPSL_SHIFT) | DC_GENERAL_CFG_DFLE;
write_dc(par, DC_FB_ST_OFFSET, 0);
write_dc(par, DC_GFX_PITCH, info->fix.line_length >> 3);
write_dc(par, DC_LINE_SIZE,
((info->var.xres * info->var.bits_per_pixel/8) >> 3) + 2);
dcfg |= DC_DISPLAY_CFG_GDEN | DC_DISPLAY_CFG_VDEN |
DC_DISPLAY_CFG_A20M | DC_DISPLAY_CFG_A18M;
switch (info->var.bits_per_pixel) {
case 8:
dcfg |= DC_DISPLAY_CFG_DISP_MODE_8BPP;
break;
case 16:
dcfg |= DC_DISPLAY_CFG_DISP_MODE_16BPP;
break;
case 32:
dcfg |= DC_DISPLAY_CFG_DISP_MODE_24BPP;
dcfg |= DC_DISPLAY_CFG_PALB;
break;
}
dcfg |= DC_DISPLAY_CFG_TGEN;
hactive = info->var.xres;
hblankstart = hactive;
hsyncstart = hblankstart + info->var.right_margin;
hsyncend = hsyncstart + info->var.hsync_len;
hblankend = hsyncend + info->var.left_margin;
htotal = hblankend;
vactive = info->var.yres;
vblankstart = vactive;
vsyncstart = vblankstart + info->var.lower_margin;
vsyncend = vsyncstart + info->var.vsync_len;
vblankend = vsyncend + info->var.upper_margin;
vtotal = vblankend;
write_dc(par, DC_H_ACTIVE_TIMING, (hactive - 1) |
((htotal - 1) << 16));
write_dc(par, DC_H_BLANK_TIMING, (hblankstart - 1) |
((hblankend - 1) << 16));
write_dc(par, DC_H_SYNC_TIMING, (hsyncstart - 1) |
((hsyncend - 1) << 16));
write_dc(par, DC_V_ACTIVE_TIMING, (vactive - 1) |
((vtotal - 1) << 16));
write_dc(par, DC_V_BLANK_TIMING, (vblankstart - 1) |
((vblankend - 1) << 16));
write_dc(par, DC_V_SYNC_TIMING, (vsyncstart - 1) |
((vsyncend - 1) << 16));
write_dc(par, DC_DISPLAY_CFG, dcfg);
write_dc(par, DC_GENERAL_CFG, gcfg);
gx_configure_display(info);
write_dc(par, DC_UNLOCK, DC_UNLOCK_LOCK);
}
void gx_set_hw_palette_reg(struct fb_info *info, unsigned regno,
unsigned red, unsigned green, unsigned blue)
{
struct gxfb_par *par = info->par;
int val;
val = (red << 8) & 0xff0000;
val |= (green) & 0x00ff00;
val |= (blue >> 8) & 0x0000ff;
write_dc(par, DC_PAL_ADDRESS, regno);
write_dc(par, DC_PAL_DATA, val);
}
