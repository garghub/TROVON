static int mfld_set_brightness(struct backlight_device *bd)
{
struct drm_device *dev = bl_get_data(mdfld_backlight_device);
struct drm_psb_private *dev_priv = dev->dev_private;
int level = bd->props.brightness;
if (level < 1)
level = 1;
if (gma_power_begin(dev, 0)) {
u32 adjusted_level;
adjusted_level = level * dev_priv->blc_adj2;
adjusted_level = adjusted_level / 100;
#if 0
#ifndef CONFIG_MDFLD_DSI_DPU
if(!(dev_priv->dsr_fb_update & MDFLD_DSR_MIPI_CONTROL) &&
(dev_priv->dbi_panel_on || dev_priv->dbi_panel_on2)){
mdfld_dsi_dbi_exit_dsr(dev,MDFLD_DSR_MIPI_CONTROL, 0, 0);
dev_dbg(dev->dev, "Out of DSR before set brightness to %d.\n",adjusted_level);
}
#endif
mdfld_dsi_brightness_control(dev, 0, adjusted_level);
if ((dev_priv->dbi_panel_on2) || (dev_priv->dpi_panel_on2))
mdfld_dsi_brightness_control(dev, 2, adjusted_level);
#endif
gma_power_end(dev);
}
mdfld_brightness = level;
return 0;
}
int psb_get_brightness(struct backlight_device *bd)
{
return mdfld_brightness;
}
static int mdfld_backlight_init(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct backlight_properties props;
memset(&props, 0, sizeof(struct backlight_properties));
props.max_brightness = 100;
props.type = BACKLIGHT_PLATFORM;
mdfld_backlight_device = backlight_device_register("mfld-bl",
NULL, (void *)dev, &mfld_ops, &props);
if (IS_ERR(mdfld_backlight_device))
return PTR_ERR(mdfld_backlight_device);
dev_priv->blc_adj1 = 100;
dev_priv->blc_adj2 = 100;
mdfld_backlight_device->props.brightness = 100;
mdfld_backlight_device->props.max_brightness = 100;
backlight_update_status(mdfld_backlight_device);
dev_priv->backlight_device = mdfld_backlight_device;
return 0;
}
static void mdfld_init_pm(struct drm_device *dev)
{
}
static int mdfld_save_display_registers(struct drm_device *dev, int pipe)
{
struct drm_psb_private *dev_priv = dev->dev_private;
int i;
u32 dpll_reg = MRST_DPLL_A;
u32 fp_reg = MRST_FPA0;
u32 pipeconf_reg = PIPEACONF;
u32 htot_reg = HTOTAL_A;
u32 hblank_reg = HBLANK_A;
u32 hsync_reg = HSYNC_A;
u32 vtot_reg = VTOTAL_A;
u32 vblank_reg = VBLANK_A;
u32 vsync_reg = VSYNC_A;
u32 pipesrc_reg = PIPEASRC;
u32 dspstride_reg = DSPASTRIDE;
u32 dsplinoff_reg = DSPALINOFF;
u32 dsptileoff_reg = DSPATILEOFF;
u32 dspsize_reg = DSPASIZE;
u32 dsppos_reg = DSPAPOS;
u32 dspsurf_reg = DSPASURF;
u32 mipi_reg = MIPI;
u32 dspcntr_reg = DSPACNTR;
u32 dspstatus_reg = PIPEASTAT;
u32 palette_reg = PALETTE_A;
u32 *dpll_val = &dev_priv->saveDPLL_A;
u32 *fp_val = &dev_priv->saveFPA0;
u32 *pipeconf_val = &dev_priv->savePIPEACONF;
u32 *htot_val = &dev_priv->saveHTOTAL_A;
u32 *hblank_val = &dev_priv->saveHBLANK_A;
u32 *hsync_val = &dev_priv->saveHSYNC_A;
u32 *vtot_val = &dev_priv->saveVTOTAL_A;
u32 *vblank_val = &dev_priv->saveVBLANK_A;
u32 *vsync_val = &dev_priv->saveVSYNC_A;
u32 *pipesrc_val = &dev_priv->savePIPEASRC;
u32 *dspstride_val = &dev_priv->saveDSPASTRIDE;
u32 *dsplinoff_val = &dev_priv->saveDSPALINOFF;
u32 *dsptileoff_val = &dev_priv->saveDSPATILEOFF;
u32 *dspsize_val = &dev_priv->saveDSPASIZE;
u32 *dsppos_val = &dev_priv->saveDSPAPOS;
u32 *dspsurf_val = &dev_priv->saveDSPASURF;
u32 *mipi_val = &dev_priv->saveMIPI;
u32 *dspcntr_val = &dev_priv->saveDSPACNTR;
u32 *dspstatus_val = &dev_priv->saveDSPASTATUS;
u32 *palette_val = dev_priv->save_palette_a;
switch (pipe) {
case 0:
break;
case 1:
dpll_reg = MDFLD_DPLL_B;
fp_reg = MDFLD_DPLL_DIV0;
pipeconf_reg = PIPEBCONF;
htot_reg = HTOTAL_B;
hblank_reg = HBLANK_B;
hsync_reg = HSYNC_B;
vtot_reg = VTOTAL_B;
vblank_reg = VBLANK_B;
vsync_reg = VSYNC_B;
pipesrc_reg = PIPEBSRC;
dspstride_reg = DSPBSTRIDE;
dsplinoff_reg = DSPBLINOFF;
dsptileoff_reg = DSPBTILEOFF;
dspsize_reg = DSPBSIZE;
dsppos_reg = DSPBPOS;
dspsurf_reg = DSPBSURF;
dspcntr_reg = DSPBCNTR;
dspstatus_reg = PIPEBSTAT;
palette_reg = PALETTE_B;
dpll_val = &dev_priv->saveDPLL_B;
fp_val = &dev_priv->saveFPB0;
pipeconf_val = &dev_priv->savePIPEBCONF;
htot_val = &dev_priv->saveHTOTAL_B;
hblank_val = &dev_priv->saveHBLANK_B;
hsync_val = &dev_priv->saveHSYNC_B;
vtot_val = &dev_priv->saveVTOTAL_B;
vblank_val = &dev_priv->saveVBLANK_B;
vsync_val = &dev_priv->saveVSYNC_B;
pipesrc_val = &dev_priv->savePIPEBSRC;
dspstride_val = &dev_priv->saveDSPBSTRIDE;
dsplinoff_val = &dev_priv->saveDSPBLINOFF;
dsptileoff_val = &dev_priv->saveDSPBTILEOFF;
dspsize_val = &dev_priv->saveDSPBSIZE;
dsppos_val = &dev_priv->saveDSPBPOS;
dspsurf_val = &dev_priv->saveDSPBSURF;
dspcntr_val = &dev_priv->saveDSPBCNTR;
dspstatus_val = &dev_priv->saveDSPBSTATUS;
palette_val = dev_priv->save_palette_b;
break;
case 2:
pipeconf_reg = PIPECCONF;
htot_reg = HTOTAL_C;
hblank_reg = HBLANK_C;
hsync_reg = HSYNC_C;
vtot_reg = VTOTAL_C;
vblank_reg = VBLANK_C;
vsync_reg = VSYNC_C;
pipesrc_reg = PIPECSRC;
dspstride_reg = DSPCSTRIDE;
dsplinoff_reg = DSPCLINOFF;
dsptileoff_reg = DSPCTILEOFF;
dspsize_reg = DSPCSIZE;
dsppos_reg = DSPCPOS;
dspsurf_reg = DSPCSURF;
mipi_reg = MIPI_C;
dspcntr_reg = DSPCCNTR;
dspstatus_reg = PIPECSTAT;
palette_reg = PALETTE_C;
pipeconf_val = &dev_priv->savePIPECCONF;
htot_val = &dev_priv->saveHTOTAL_C;
hblank_val = &dev_priv->saveHBLANK_C;
hsync_val = &dev_priv->saveHSYNC_C;
vtot_val = &dev_priv->saveVTOTAL_C;
vblank_val = &dev_priv->saveVBLANK_C;
vsync_val = &dev_priv->saveVSYNC_C;
pipesrc_val = &dev_priv->savePIPECSRC;
dspstride_val = &dev_priv->saveDSPCSTRIDE;
dsplinoff_val = &dev_priv->saveDSPCLINOFF;
dsptileoff_val = &dev_priv->saveDSPCTILEOFF;
dspsize_val = &dev_priv->saveDSPCSIZE;
dsppos_val = &dev_priv->saveDSPCPOS;
dspsurf_val = &dev_priv->saveDSPCSURF;
mipi_val = &dev_priv->saveMIPI_C;
dspcntr_val = &dev_priv->saveDSPCCNTR;
dspstatus_val = &dev_priv->saveDSPCSTATUS;
palette_val = dev_priv->save_palette_c;
break;
default:
DRM_ERROR("%s, invalid pipe number.\n", __func__);
return -EINVAL;
}
*dpll_val = PSB_RVDC32(dpll_reg);
*fp_val = PSB_RVDC32(fp_reg);
*pipeconf_val = PSB_RVDC32(pipeconf_reg);
*htot_val = PSB_RVDC32(htot_reg);
*hblank_val = PSB_RVDC32(hblank_reg);
*hsync_val = PSB_RVDC32(hsync_reg);
*vtot_val = PSB_RVDC32(vtot_reg);
*vblank_val = PSB_RVDC32(vblank_reg);
*vsync_val = PSB_RVDC32(vsync_reg);
*pipesrc_val = PSB_RVDC32(pipesrc_reg);
*dspstride_val = PSB_RVDC32(dspstride_reg);
*dsplinoff_val = PSB_RVDC32(dsplinoff_reg);
*dsptileoff_val = PSB_RVDC32(dsptileoff_reg);
*dspsize_val = PSB_RVDC32(dspsize_reg);
*dsppos_val = PSB_RVDC32(dsppos_reg);
*dspsurf_val = PSB_RVDC32(dspsurf_reg);
*dspcntr_val = PSB_RVDC32(dspcntr_reg);
*dspstatus_val = PSB_RVDC32(dspstatus_reg);
for (i = 0; i < 256; i++)
palette_val[i] = PSB_RVDC32(palette_reg + (i<<2));
if (pipe == 1) {
dev_priv->savePFIT_CONTROL = PSB_RVDC32(PFIT_CONTROL);
dev_priv->savePFIT_PGM_RATIOS = PSB_RVDC32(PFIT_PGM_RATIOS);
dev_priv->saveHDMIPHYMISCCTL = PSB_RVDC32(HDMIPHYMISCCTL);
dev_priv->saveHDMIB_CONTROL = PSB_RVDC32(HDMIB_CONTROL);
return 0;
}
*mipi_val = PSB_RVDC32(mipi_reg);
return 0;
}
static int mdfld_save_cursor_overlay_registers(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
dev_priv->saveDSPACURSOR_CTRL = PSB_RVDC32(CURACNTR);
dev_priv->saveDSPACURSOR_BASE = PSB_RVDC32(CURABASE);
dev_priv->saveDSPACURSOR_POS = PSB_RVDC32(CURAPOS);
dev_priv->saveDSPBCURSOR_CTRL = PSB_RVDC32(CURBCNTR);
dev_priv->saveDSPBCURSOR_BASE = PSB_RVDC32(CURBBASE);
dev_priv->saveDSPBCURSOR_POS = PSB_RVDC32(CURBPOS);
dev_priv->saveDSPCCURSOR_CTRL = PSB_RVDC32(CURCCNTR);
dev_priv->saveDSPCCURSOR_BASE = PSB_RVDC32(CURCBASE);
dev_priv->saveDSPCCURSOR_POS = PSB_RVDC32(CURCPOS);
dev_priv->saveOV_OVADD = PSB_RVDC32(OV_OVADD);
dev_priv->saveOV_OGAMC0 = PSB_RVDC32(OV_OGAMC0);
dev_priv->saveOV_OGAMC1 = PSB_RVDC32(OV_OGAMC1);
dev_priv->saveOV_OGAMC2 = PSB_RVDC32(OV_OGAMC2);
dev_priv->saveOV_OGAMC3 = PSB_RVDC32(OV_OGAMC3);
dev_priv->saveOV_OGAMC4 = PSB_RVDC32(OV_OGAMC4);
dev_priv->saveOV_OGAMC5 = PSB_RVDC32(OV_OGAMC5);
dev_priv->saveOV_OVADD_C = PSB_RVDC32(OV_OVADD + OV_C_OFFSET);
dev_priv->saveOV_OGAMC0_C = PSB_RVDC32(OV_OGAMC0 + OV_C_OFFSET);
dev_priv->saveOV_OGAMC1_C = PSB_RVDC32(OV_OGAMC1 + OV_C_OFFSET);
dev_priv->saveOV_OGAMC2_C = PSB_RVDC32(OV_OGAMC2 + OV_C_OFFSET);
dev_priv->saveOV_OGAMC3_C = PSB_RVDC32(OV_OGAMC3 + OV_C_OFFSET);
dev_priv->saveOV_OGAMC4_C = PSB_RVDC32(OV_OGAMC4 + OV_C_OFFSET);
dev_priv->saveOV_OGAMC5_C = PSB_RVDC32(OV_OGAMC5 + OV_C_OFFSET);
return 0;
}
static int mdfld_restore_display_registers(struct drm_device *dev, int pipe)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct mdfld_dsi_config *dsi_config = NULL;
u32 i = 0;
u32 dpll = 0;
u32 timeout = 0;
u32 reg_offset = 0;
u32 dpll_reg = MRST_DPLL_A;
u32 fp_reg = MRST_FPA0;
u32 pipeconf_reg = PIPEACONF;
u32 htot_reg = HTOTAL_A;
u32 hblank_reg = HBLANK_A;
u32 hsync_reg = HSYNC_A;
u32 vtot_reg = VTOTAL_A;
u32 vblank_reg = VBLANK_A;
u32 vsync_reg = VSYNC_A;
u32 pipesrc_reg = PIPEASRC;
u32 dspstride_reg = DSPASTRIDE;
u32 dsplinoff_reg = DSPALINOFF;
u32 dsptileoff_reg = DSPATILEOFF;
u32 dspsize_reg = DSPASIZE;
u32 dsppos_reg = DSPAPOS;
u32 dspsurf_reg = DSPASURF;
u32 dspstatus_reg = PIPEASTAT;
u32 mipi_reg = MIPI;
u32 dspcntr_reg = DSPACNTR;
u32 palette_reg = PALETTE_A;
u32 dpll_val = dev_priv->saveDPLL_A & ~DPLL_VCO_ENABLE;
u32 fp_val = dev_priv->saveFPA0;
u32 pipeconf_val = dev_priv->savePIPEACONF;
u32 htot_val = dev_priv->saveHTOTAL_A;
u32 hblank_val = dev_priv->saveHBLANK_A;
u32 hsync_val = dev_priv->saveHSYNC_A;
u32 vtot_val = dev_priv->saveVTOTAL_A;
u32 vblank_val = dev_priv->saveVBLANK_A;
u32 vsync_val = dev_priv->saveVSYNC_A;
u32 pipesrc_val = dev_priv->savePIPEASRC;
u32 dspstride_val = dev_priv->saveDSPASTRIDE;
u32 dsplinoff_val = dev_priv->saveDSPALINOFF;
u32 dsptileoff_val = dev_priv->saveDSPATILEOFF;
u32 dspsize_val = dev_priv->saveDSPASIZE;
u32 dsppos_val = dev_priv->saveDSPAPOS;
u32 dspsurf_val = dev_priv->saveDSPASURF;
u32 dspstatus_val = dev_priv->saveDSPASTATUS;
u32 mipi_val = dev_priv->saveMIPI;
u32 dspcntr_val = dev_priv->saveDSPACNTR;
u32 *palette_val = dev_priv->save_palette_a;
switch (pipe) {
case 0:
dsi_config = dev_priv->dsi_configs[0];
break;
case 1:
dpll_reg = MDFLD_DPLL_B;
fp_reg = MDFLD_DPLL_DIV0;
pipeconf_reg = PIPEBCONF;
htot_reg = HTOTAL_B;
hblank_reg = HBLANK_B;
hsync_reg = HSYNC_B;
vtot_reg = VTOTAL_B;
vblank_reg = VBLANK_B;
vsync_reg = VSYNC_B;
pipesrc_reg = PIPEBSRC;
dspstride_reg = DSPBSTRIDE;
dsplinoff_reg = DSPBLINOFF;
dsptileoff_reg = DSPBTILEOFF;
dspsize_reg = DSPBSIZE;
dsppos_reg = DSPBPOS;
dspsurf_reg = DSPBSURF;
dspcntr_reg = DSPBCNTR;
palette_reg = PALETTE_B;
dspstatus_reg = PIPEBSTAT;
dpll_val = dev_priv->saveDPLL_B & ~DPLL_VCO_ENABLE;
fp_val = dev_priv->saveFPB0;
pipeconf_val = dev_priv->savePIPEBCONF;
htot_val = dev_priv->saveHTOTAL_B;
hblank_val = dev_priv->saveHBLANK_B;
hsync_val = dev_priv->saveHSYNC_B;
vtot_val = dev_priv->saveVTOTAL_B;
vblank_val = dev_priv->saveVBLANK_B;
vsync_val = dev_priv->saveVSYNC_B;
pipesrc_val = dev_priv->savePIPEBSRC;
dspstride_val = dev_priv->saveDSPBSTRIDE;
dsplinoff_val = dev_priv->saveDSPBLINOFF;
dsptileoff_val = dev_priv->saveDSPBTILEOFF;
dspsize_val = dev_priv->saveDSPBSIZE;
dsppos_val = dev_priv->saveDSPBPOS;
dspsurf_val = dev_priv->saveDSPBSURF;
dspcntr_val = dev_priv->saveDSPBCNTR;
dspstatus_val = dev_priv->saveDSPBSTATUS;
palette_val = dev_priv->save_palette_b;
break;
case 2:
reg_offset = MIPIC_REG_OFFSET;
pipeconf_reg = PIPECCONF;
htot_reg = HTOTAL_C;
hblank_reg = HBLANK_C;
hsync_reg = HSYNC_C;
vtot_reg = VTOTAL_C;
vblank_reg = VBLANK_C;
vsync_reg = VSYNC_C;
pipesrc_reg = PIPECSRC;
dspstride_reg = DSPCSTRIDE;
dsplinoff_reg = DSPCLINOFF;
dsptileoff_reg = DSPCTILEOFF;
dspsize_reg = DSPCSIZE;
dsppos_reg = DSPCPOS;
dspsurf_reg = DSPCSURF;
mipi_reg = MIPI_C;
dspcntr_reg = DSPCCNTR;
palette_reg = PALETTE_C;
dspstatus_reg = PIPECSTAT;
pipeconf_val = dev_priv->savePIPECCONF;
htot_val = dev_priv->saveHTOTAL_C;
hblank_val = dev_priv->saveHBLANK_C;
hsync_val = dev_priv->saveHSYNC_C;
vtot_val = dev_priv->saveVTOTAL_C;
vblank_val = dev_priv->saveVBLANK_C;
vsync_val = dev_priv->saveVSYNC_C;
pipesrc_val = dev_priv->savePIPECSRC;
dspstride_val = dev_priv->saveDSPCSTRIDE;
dsplinoff_val = dev_priv->saveDSPCLINOFF;
dsptileoff_val = dev_priv->saveDSPCTILEOFF;
dspsize_val = dev_priv->saveDSPCSIZE;
dsppos_val = dev_priv->saveDSPCPOS;
dspsurf_val = dev_priv->saveDSPCSURF;
dspstatus_val = dev_priv->saveDSPCSTATUS;
mipi_val = dev_priv->saveMIPI_C;
dspcntr_val = dev_priv->saveDSPCCNTR;
palette_val = dev_priv->save_palette_c;
dsi_config = dev_priv->dsi_configs[1];
break;
default:
DRM_ERROR("%s, invalid pipe number.\n", __func__);
return -EINVAL;
}
PSB_WVDC32(0x80000000, VGACNTRL);
if (pipe == 1) {
PSB_WVDC32(dpll_val & ~DPLL_VCO_ENABLE, dpll_reg);
PSB_RVDC32(dpll_reg);
PSB_WVDC32(fp_val, fp_reg);
} else {
dpll = PSB_RVDC32(dpll_reg);
if (!(dpll & DPLL_VCO_ENABLE)) {
if (dpll & MDFLD_PWR_GATE_EN) {
dpll &= ~MDFLD_PWR_GATE_EN;
PSB_WVDC32(dpll, dpll_reg);
udelay(500);
}
PSB_WVDC32(fp_val, fp_reg);
PSB_WVDC32(dpll_val, dpll_reg);
udelay(500);
dpll_val |= DPLL_VCO_ENABLE;
PSB_WVDC32(dpll_val, dpll_reg);
PSB_RVDC32(dpll_reg);
while ((timeout < 20000) && !(PSB_RVDC32(pipeconf_reg) & PIPECONF_DSIPLL_LOCK)) {
udelay(150);
timeout++;
}
if (timeout == 20000) {
DRM_ERROR("%s, can't lock DSIPLL.\n",
__func__);
return -EINVAL;
}
}
}
PSB_WVDC32(htot_val, htot_reg);
PSB_WVDC32(hblank_val, hblank_reg);
PSB_WVDC32(hsync_val, hsync_reg);
PSB_WVDC32(vtot_val, vtot_reg);
PSB_WVDC32(vblank_val, vblank_reg);
PSB_WVDC32(vsync_val, vsync_reg);
PSB_WVDC32(pipesrc_val, pipesrc_reg);
PSB_WVDC32(dspstatus_val, dspstatus_reg);
PSB_WVDC32(dspstride_val, dspstride_reg);
PSB_WVDC32(dsplinoff_val, dsplinoff_reg);
PSB_WVDC32(dsptileoff_val, dsptileoff_reg);
PSB_WVDC32(dspsize_val, dspsize_reg);
PSB_WVDC32(dsppos_val, dsppos_reg);
PSB_WVDC32(dspsurf_val, dspsurf_reg);
if (pipe == 1) {
PSB_WVDC32(dev_priv->savePFIT_CONTROL, PFIT_CONTROL);
PSB_WVDC32(dev_priv->savePFIT_PGM_RATIOS, PFIT_PGM_RATIOS);
PSB_WVDC32(dev_priv->saveHDMIPHYMISCCTL, HDMIPHYMISCCTL);
PSB_WVDC32(dev_priv->saveHDMIB_CONTROL, HDMIB_CONTROL);
} else {
PSB_WVDC32(mipi_val, mipi_reg);
mdfld_dsi_controller_init(dsi_config, pipe);
msleep(20);
}
PSB_WVDC32(dspcntr_val, dspcntr_reg);
msleep(20);
PSB_WVDC32(pipeconf_val, pipeconf_reg);
for (i = 0; i < 256; i++)
PSB_WVDC32(palette_val[i], palette_reg + (i<<2));
if (pipe == 1)
return 0;
if (!mdfld_panel_dpi(dev))
mdfld_enable_te(dev, pipe);
return 0;
}
static int mdfld_restore_cursor_overlay_registers(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
PSB_WVDC32(dev_priv->saveDSPACURSOR_CTRL, CURACNTR);
PSB_WVDC32(dev_priv->saveDSPACURSOR_POS, CURAPOS);
PSB_WVDC32(dev_priv->saveDSPACURSOR_BASE, CURABASE);
PSB_WVDC32(dev_priv->saveDSPBCURSOR_CTRL, CURBCNTR);
PSB_WVDC32(dev_priv->saveDSPBCURSOR_POS, CURBPOS);
PSB_WVDC32(dev_priv->saveDSPBCURSOR_BASE, CURBBASE);
PSB_WVDC32(dev_priv->saveDSPCCURSOR_CTRL, CURCCNTR);
PSB_WVDC32(dev_priv->saveDSPCCURSOR_POS, CURCPOS);
PSB_WVDC32(dev_priv->saveDSPCCURSOR_BASE, CURCBASE);
PSB_WVDC32(dev_priv->saveOV_OVADD, OV_OVADD);
PSB_WVDC32(dev_priv->saveOV_OGAMC0, OV_OGAMC0);
PSB_WVDC32(dev_priv->saveOV_OGAMC1, OV_OGAMC1);
PSB_WVDC32(dev_priv->saveOV_OGAMC2, OV_OGAMC2);
PSB_WVDC32(dev_priv->saveOV_OGAMC3, OV_OGAMC3);
PSB_WVDC32(dev_priv->saveOV_OGAMC4, OV_OGAMC4);
PSB_WVDC32(dev_priv->saveOV_OGAMC5, OV_OGAMC5);
PSB_WVDC32(dev_priv->saveOV_OVADD_C, OV_OVADD + OV_C_OFFSET);
PSB_WVDC32(dev_priv->saveOV_OGAMC0_C, OV_OGAMC0 + OV_C_OFFSET);
PSB_WVDC32(dev_priv->saveOV_OGAMC1_C, OV_OGAMC1 + OV_C_OFFSET);
PSB_WVDC32(dev_priv->saveOV_OGAMC2_C, OV_OGAMC2 + OV_C_OFFSET);
PSB_WVDC32(dev_priv->saveOV_OGAMC3_C, OV_OGAMC3 + OV_C_OFFSET);
PSB_WVDC32(dev_priv->saveOV_OGAMC4_C, OV_OGAMC4 + OV_C_OFFSET);
PSB_WVDC32(dev_priv->saveOV_OGAMC5_C, OV_OGAMC5 + OV_C_OFFSET);
return 0;
}
static int mdfld_save_registers(struct drm_device *dev)
{
mdfld_save_cursor_overlay_registers(dev);
mdfld_save_display_registers(dev, 0);
mdfld_save_display_registers(dev, 0);
mdfld_save_display_registers(dev, 2);
mdfld_save_display_registers(dev, 1);
mdfld_disable_crtc(dev, 0);
mdfld_disable_crtc(dev, 2);
mdfld_disable_crtc(dev, 1);
return 0;
}
static int mdfld_restore_registers(struct drm_device *dev)
{
mdfld_restore_display_registers(dev, 1);
mdfld_restore_display_registers(dev, 0);
mdfld_restore_display_registers(dev, 2);
mdfld_restore_cursor_overlay_registers(dev);
return 0;
}
static int mdfld_power_down(struct drm_device *dev)
{
return 0;
}
static int mdfld_power_up(struct drm_device *dev)
{
return 0;
}
