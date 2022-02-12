static inline bool is_fpc_off(uint32_t fpc)
{
return ((fpc & (FP_TG_CONTROL_ON | FP_TG_CONTROL_OFF)) ==
FP_TG_CONTROL_OFF);
}
int nv04_dfp_get_bound_head(struct drm_device *dev, struct dcb_output *dcbent)
{
int ramdac = (dcbent->or & DCB_OUTPUT_C) >> 2;
NVWriteRAMDAC(dev, ramdac, NV_PRAMDAC_FP_TMDS_CONTROL,
NV_PRAMDAC_FP_TMDS_CONTROL_WRITE_DISABLE | 0x4);
return ((NVReadRAMDAC(dev, ramdac, NV_PRAMDAC_FP_TMDS_DATA) & 0x8) >> 3) ^ ramdac;
}
void nv04_dfp_bind_head(struct drm_device *dev, struct dcb_output *dcbent,
int head, bool dl)
{
int ramdac = (dcbent->or & DCB_OUTPUT_C) >> 2;
uint8_t tmds04 = 0x80;
if (head != ramdac)
tmds04 = 0x88;
if (dcbent->type == DCB_OUTPUT_LVDS)
tmds04 |= 0x01;
nv_write_tmds(dev, dcbent->or, 0, 0x04, tmds04);
if (dl)
nv_write_tmds(dev, dcbent->or, 1, 0x04, tmds04 ^ 0x08);
}
void nv04_dfp_disable(struct drm_device *dev, int head)
{
struct nv04_crtc_reg *crtcstate = nv04_display(dev)->mode_reg.crtc_reg;
if (NVReadRAMDAC(dev, head, NV_PRAMDAC_FP_TG_CONTROL) &
FP_TG_CONTROL_ON) {
NVWriteRAMDAC(dev, head, NV_PRAMDAC_FP_TG_CONTROL,
FP_TG_CONTROL_OFF);
msleep(50);
}
crtcstate[head].fp_control = FP_TG_CONTROL_OFF;
crtcstate[head].CRTC[NV_CIO_CRE_LCD__INDEX] &=
~NV_CIO_CRE_LCD_ROUTE_MASK;
}
void nv04_dfp_update_fp_control(struct drm_encoder *encoder, int mode)
{
struct drm_device *dev = encoder->dev;
struct drm_crtc *crtc;
struct nouveau_crtc *nv_crtc;
uint32_t *fpc;
if (mode == DRM_MODE_DPMS_ON) {
nv_crtc = nouveau_crtc(encoder->crtc);
fpc = &nv04_display(dev)->mode_reg.crtc_reg[nv_crtc->index].fp_control;
if (is_fpc_off(*fpc)) {
*fpc = nv_crtc->dpms_saved_fp_control;
}
nv_crtc->fp_users |= 1 << nouveau_encoder(encoder)->dcb->index;
NVWriteRAMDAC(dev, nv_crtc->index, NV_PRAMDAC_FP_TG_CONTROL, *fpc);
} else {
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
nv_crtc = nouveau_crtc(crtc);
fpc = &nv04_display(dev)->mode_reg.crtc_reg[nv_crtc->index].fp_control;
nv_crtc->fp_users &= ~(1 << nouveau_encoder(encoder)->dcb->index);
if (!is_fpc_off(*fpc) && !nv_crtc->fp_users) {
nv_crtc->dpms_saved_fp_control = *fpc;
*fpc &= ~FP_TG_CONTROL_ON;
*fpc |= FP_TG_CONTROL_OFF;
NVWriteRAMDAC(dev, nv_crtc->index,
NV_PRAMDAC_FP_TG_CONTROL, *fpc);
}
}
}
}
static struct drm_encoder *get_tmds_slave(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
struct dcb_output *dcb = nouveau_encoder(encoder)->dcb;
struct drm_encoder *slave;
if (dcb->type != DCB_OUTPUT_TMDS || dcb->location == DCB_LOC_ON_CHIP)
return NULL;
list_for_each_entry(slave, &dev->mode_config.encoder_list, head) {
struct dcb_output *slave_dcb = nouveau_encoder(slave)->dcb;
if (slave_dcb->type == DCB_OUTPUT_TMDS && get_slave_funcs(slave) &&
slave_dcb->tmdsconf.slave_addr == dcb->tmdsconf.slave_addr)
return slave;
}
return NULL;
}
static bool nv04_dfp_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct nouveau_encoder *nv_encoder = nouveau_encoder(encoder);
struct nouveau_connector *nv_connector = nouveau_encoder_connector_get(nv_encoder);
if (!nv_connector->native_mode ||
nv_connector->scaling_mode == DRM_MODE_SCALE_NONE ||
mode->hdisplay > nv_connector->native_mode->hdisplay ||
mode->vdisplay > nv_connector->native_mode->vdisplay) {
nv_encoder->mode = *adjusted_mode;
} else {
nv_encoder->mode = *nv_connector->native_mode;
adjusted_mode->clock = nv_connector->native_mode->clock;
}
return true;
}
static void nv04_dfp_prepare_sel_clk(struct drm_device *dev,
struct nouveau_encoder *nv_encoder, int head)
{
struct nv04_mode_state *state = &nv04_display(dev)->mode_reg;
uint32_t bits1618 = nv_encoder->dcb->or & DCB_OUTPUT_A ? 0x10000 : 0x40000;
if (nv_encoder->dcb->location != DCB_LOC_ON_CHIP)
return;
if (head)
state->sel_clk |= bits1618;
else
state->sel_clk &= ~bits1618;
if (nv_encoder->dcb->type == DCB_OUTPUT_LVDS && nv04_display(dev)->saved_reg.sel_clk & 0xf0) {
int shift = (nv04_display(dev)->saved_reg.sel_clk & 0x50) ? 0 : 1;
state->sel_clk &= ~0xf0;
state->sel_clk |= (head ? 0x40 : 0x10) << shift;
}
}
static void nv04_dfp_prepare(struct drm_encoder *encoder)
{
struct nouveau_encoder *nv_encoder = nouveau_encoder(encoder);
const struct drm_encoder_helper_funcs *helper = encoder->helper_private;
struct drm_device *dev = encoder->dev;
int head = nouveau_crtc(encoder->crtc)->index;
struct nv04_crtc_reg *crtcstate = nv04_display(dev)->mode_reg.crtc_reg;
uint8_t *cr_lcd = &crtcstate[head].CRTC[NV_CIO_CRE_LCD__INDEX];
uint8_t *cr_lcd_oth = &crtcstate[head ^ 1].CRTC[NV_CIO_CRE_LCD__INDEX];
helper->dpms(encoder, DRM_MODE_DPMS_OFF);
nv04_dfp_prepare_sel_clk(dev, nv_encoder, head);
*cr_lcd = (*cr_lcd & ~NV_CIO_CRE_LCD_ROUTE_MASK) | 0x3;
if (nv_two_heads(dev)) {
if (nv_encoder->dcb->location == DCB_LOC_ON_CHIP)
*cr_lcd |= head ? 0x0 : 0x8;
else {
*cr_lcd |= (nv_encoder->dcb->or << 4) & 0x30;
if (nv_encoder->dcb->type == DCB_OUTPUT_LVDS)
*cr_lcd |= 0x30;
if ((*cr_lcd & 0x30) == (*cr_lcd_oth & 0x30)) {
*cr_lcd_oth &= ~0x30;
NVWriteVgaCrtc(dev, head ^ 1,
NV_CIO_CRE_LCD__INDEX,
*cr_lcd_oth);
}
}
}
}
static void nv04_dfp_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct drm_device *dev = encoder->dev;
struct nvif_device *device = &nouveau_drm(dev)->device;
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_crtc *nv_crtc = nouveau_crtc(encoder->crtc);
struct nv04_crtc_reg *regp = &nv04_display(dev)->mode_reg.crtc_reg[nv_crtc->index];
struct nv04_crtc_reg *savep = &nv04_display(dev)->saved_reg.crtc_reg[nv_crtc->index];
struct nouveau_connector *nv_connector = nouveau_crtc_connector_get(nv_crtc);
struct nouveau_encoder *nv_encoder = nouveau_encoder(encoder);
struct drm_display_mode *output_mode = &nv_encoder->mode;
struct drm_connector *connector = &nv_connector->base;
uint32_t mode_ratio, panel_ratio;
NV_DEBUG(drm, "Output mode on CRTC %d:\n", nv_crtc->index);
drm_mode_debug_printmodeline(output_mode);
regp->fp_horiz_regs[FP_DISPLAY_END] = output_mode->hdisplay - 1;
regp->fp_horiz_regs[FP_TOTAL] = output_mode->htotal - 1;
if (!nv_gf4_disp_arch(dev) ||
(output_mode->hsync_start - output_mode->hdisplay) >=
drm->vbios.digital_min_front_porch)
regp->fp_horiz_regs[FP_CRTC] = output_mode->hdisplay;
else
regp->fp_horiz_regs[FP_CRTC] = output_mode->hsync_start - drm->vbios.digital_min_front_porch - 1;
regp->fp_horiz_regs[FP_SYNC_START] = output_mode->hsync_start - 1;
regp->fp_horiz_regs[FP_SYNC_END] = output_mode->hsync_end - 1;
regp->fp_horiz_regs[FP_VALID_START] = output_mode->hskew;
regp->fp_horiz_regs[FP_VALID_END] = output_mode->hdisplay - 1;
regp->fp_vert_regs[FP_DISPLAY_END] = output_mode->vdisplay - 1;
regp->fp_vert_regs[FP_TOTAL] = output_mode->vtotal - 1;
regp->fp_vert_regs[FP_CRTC] = output_mode->vtotal - 5 - 1;
regp->fp_vert_regs[FP_SYNC_START] = output_mode->vsync_start - 1;
regp->fp_vert_regs[FP_SYNC_END] = output_mode->vsync_end - 1;
regp->fp_vert_regs[FP_VALID_START] = 0;
regp->fp_vert_regs[FP_VALID_END] = output_mode->vdisplay - 1;
regp->fp_control = NV_PRAMDAC_FP_TG_CONTROL_DISPEN_POS |
(savep->fp_control & (1 << 26 | NV_PRAMDAC_FP_TG_CONTROL_READ_PROG));
if (output_mode->flags & DRM_MODE_FLAG_PVSYNC)
regp->fp_control |= NV_PRAMDAC_FP_TG_CONTROL_VSYNC_POS;
if (output_mode->flags & DRM_MODE_FLAG_PHSYNC)
regp->fp_control |= NV_PRAMDAC_FP_TG_CONTROL_HSYNC_POS;
if (nv_connector->scaling_mode == DRM_MODE_SCALE_NONE ||
nv_connector->scaling_mode == DRM_MODE_SCALE_CENTER)
regp->fp_control |= NV_PRAMDAC_FP_TG_CONTROL_MODE_CENTER;
else if (adjusted_mode->hdisplay == output_mode->hdisplay &&
adjusted_mode->vdisplay == output_mode->vdisplay)
regp->fp_control |= NV_PRAMDAC_FP_TG_CONTROL_MODE_NATIVE;
else
regp->fp_control |= NV_PRAMDAC_FP_TG_CONTROL_MODE_SCALE;
if (nvif_rd32(device, NV_PEXTDEV_BOOT_0) & NV_PEXTDEV_BOOT_0_STRAP_FP_IFACE_12BIT)
regp->fp_control |= NV_PRAMDAC_FP_TG_CONTROL_WIDTH_12;
if (nv_encoder->dcb->location != DCB_LOC_ON_CHIP &&
output_mode->clock > 165000)
regp->fp_control |= (2 << 24);
if (nv_encoder->dcb->type == DCB_OUTPUT_LVDS) {
bool duallink = false, dummy;
if (nv_connector->edid &&
nv_connector->type == DCB_CONNECTOR_LVDS_SPWG) {
duallink = (((u8 *)nv_connector->edid)[121] == 2);
} else {
nouveau_bios_parse_lvds_table(dev, output_mode->clock,
&duallink, &dummy);
}
if (duallink)
regp->fp_control |= (8 << 28);
} else
if (output_mode->clock > 165000)
regp->fp_control |= (8 << 28);
regp->fp_debug_0 = NV_PRAMDAC_FP_DEBUG_0_YWEIGHT_ROUND |
NV_PRAMDAC_FP_DEBUG_0_XWEIGHT_ROUND |
NV_PRAMDAC_FP_DEBUG_0_YINTERP_BILINEAR |
NV_PRAMDAC_FP_DEBUG_0_XINTERP_BILINEAR |
NV_RAMDAC_FP_DEBUG_0_TMDS_ENABLED |
NV_PRAMDAC_FP_DEBUG_0_YSCALE_ENABLE |
NV_PRAMDAC_FP_DEBUG_0_XSCALE_ENABLE;
regp->fp_debug_1 = 0;
regp->fp_debug_2 = 0;
mode_ratio = (1 << 12) * adjusted_mode->hdisplay / adjusted_mode->vdisplay;
panel_ratio = (1 << 12) * output_mode->hdisplay / output_mode->vdisplay;
if (nv_connector->scaling_mode == DRM_MODE_SCALE_ASPECT &&
mode_ratio != panel_ratio) {
uint32_t diff, scale;
bool divide_by_2 = nv_gf4_disp_arch(dev);
if (mode_ratio < panel_ratio) {
scale = (1 << 12) * adjusted_mode->vdisplay / output_mode->vdisplay;
regp->fp_debug_1 = NV_PRAMDAC_FP_DEBUG_1_XSCALE_TESTMODE_ENABLE |
XLATE(scale, divide_by_2, NV_PRAMDAC_FP_DEBUG_1_XSCALE_VALUE);
diff = output_mode->hdisplay -
output_mode->vdisplay * mode_ratio / (1 << 12);
regp->fp_horiz_regs[FP_VALID_START] += diff / 2;
regp->fp_horiz_regs[FP_VALID_END] -= diff / 2;
}
if (mode_ratio > panel_ratio) {
scale = (1 << 12) * adjusted_mode->hdisplay / output_mode->hdisplay;
regp->fp_debug_1 = NV_PRAMDAC_FP_DEBUG_1_YSCALE_TESTMODE_ENABLE |
XLATE(scale, divide_by_2, NV_PRAMDAC_FP_DEBUG_1_YSCALE_VALUE);
diff = output_mode->vdisplay -
(1 << 12) * output_mode->hdisplay / mode_ratio;
regp->fp_vert_regs[FP_VALID_START] += diff / 2;
regp->fp_vert_regs[FP_VALID_END] -= diff / 2;
}
}
if ((nv_connector->dithering_mode == DITHERING_MODE_ON) ||
(nv_connector->dithering_mode == DITHERING_MODE_AUTO &&
encoder->crtc->primary->fb->depth > connector->display_info.bpc * 3)) {
if (drm->device.info.chipset == 0x11)
regp->dither = savep->dither | 0x00010000;
else {
int i;
regp->dither = savep->dither | 0x00000001;
for (i = 0; i < 3; i++) {
regp->dither_regs[i] = 0xe4e4e4e4;
regp->dither_regs[i + 3] = 0x44444444;
}
}
} else {
if (drm->device.info.chipset != 0x11) {
int i;
for (i = 0; i < 3; i++) {
regp->dither_regs[i] = savep->dither_regs[i];
regp->dither_regs[i + 3] = savep->dither_regs[i + 3];
}
}
regp->dither = savep->dither;
}
regp->fp_margin_color = 0;
}
static void nv04_dfp_commit(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
struct nouveau_drm *drm = nouveau_drm(dev);
const struct drm_encoder_helper_funcs *helper = encoder->helper_private;
struct nouveau_crtc *nv_crtc = nouveau_crtc(encoder->crtc);
struct nouveau_encoder *nv_encoder = nouveau_encoder(encoder);
struct dcb_output *dcbe = nv_encoder->dcb;
int head = nouveau_crtc(encoder->crtc)->index;
struct drm_encoder *slave_encoder;
if (dcbe->type == DCB_OUTPUT_TMDS)
run_tmds_table(dev, dcbe, head, nv_encoder->mode.clock);
else if (dcbe->type == DCB_OUTPUT_LVDS)
call_lvds_script(dev, dcbe, head, LVDS_RESET, nv_encoder->mode.clock);
nv04_display(dev)->mode_reg.crtc_reg[head].fp_control =
NVReadRAMDAC(dev, head, NV_PRAMDAC_FP_TG_CONTROL);
if (drm->device.info.chipset < 0x44)
NVWriteRAMDAC(dev, 0, NV_PRAMDAC_TEST_CONTROL + nv04_dac_output_offset(encoder), 0xf0000000);
else
NVWriteRAMDAC(dev, 0, NV_PRAMDAC_TEST_CONTROL + nv04_dac_output_offset(encoder), 0x00100000);
slave_encoder = get_tmds_slave(encoder);
if (slave_encoder)
get_slave_funcs(slave_encoder)->mode_set(
slave_encoder, &nv_encoder->mode, &nv_encoder->mode);
helper->dpms(encoder, DRM_MODE_DPMS_ON);
NV_DEBUG(drm, "Output %s is running on CRTC %d using output %c\n",
nouveau_encoder_connector_get(nv_encoder)->base.name,
nv_crtc->index, '@' + ffs(nv_encoder->dcb->or));
}
static void nv04_dfp_update_backlight(struct drm_encoder *encoder, int mode)
{
#ifdef __powerpc__
struct drm_device *dev = encoder->dev;
struct nvif_device *device = &nouveau_drm(dev)->device;
if (dev->pdev->device == 0x0174 || dev->pdev->device == 0x0179 ||
dev->pdev->device == 0x0189 || dev->pdev->device == 0x0329) {
if (mode == DRM_MODE_DPMS_ON) {
nv_mask(device, NV_PBUS_DEBUG_DUALHEAD_CTL, 1 << 31, 1 << 31);
nv_mask(device, NV_PCRTC_GPIO_EXT, 3, 1);
} else {
nv_mask(device, NV_PBUS_DEBUG_DUALHEAD_CTL, 1 << 31, 0);
nv_mask(device, NV_PCRTC_GPIO_EXT, 3, 0);
}
}
#endif
}
static inline bool is_powersaving_dpms(int mode)
{
return mode != DRM_MODE_DPMS_ON && mode != NV_DPMS_CLEARED;
}
static void nv04_lvds_dpms(struct drm_encoder *encoder, int mode)
{
struct drm_device *dev = encoder->dev;
struct drm_crtc *crtc = encoder->crtc;
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_encoder *nv_encoder = nouveau_encoder(encoder);
bool was_powersaving = is_powersaving_dpms(nv_encoder->last_dpms);
if (nv_encoder->last_dpms == mode)
return;
nv_encoder->last_dpms = mode;
NV_DEBUG(drm, "Setting dpms mode %d on lvds encoder (output %d)\n",
mode, nv_encoder->dcb->index);
if (was_powersaving && is_powersaving_dpms(mode))
return;
if (nv_encoder->dcb->lvdsconf.use_power_scripts) {
int head = crtc ? nouveau_crtc(crtc)->index :
nv04_dfp_get_bound_head(dev, nv_encoder->dcb);
if (mode == DRM_MODE_DPMS_ON) {
call_lvds_script(dev, nv_encoder->dcb, head,
LVDS_PANEL_ON, nv_encoder->mode.clock);
} else
call_lvds_script(dev, nv_encoder->dcb, head,
LVDS_PANEL_OFF, 0);
}
nv04_dfp_update_backlight(encoder, mode);
nv04_dfp_update_fp_control(encoder, mode);
if (mode == DRM_MODE_DPMS_ON)
nv04_dfp_prepare_sel_clk(dev, nv_encoder, nouveau_crtc(crtc)->index);
else {
nv04_display(dev)->mode_reg.sel_clk = NVReadRAMDAC(dev, 0, NV_PRAMDAC_SEL_CLK);
nv04_display(dev)->mode_reg.sel_clk &= ~0xf0;
}
NVWriteRAMDAC(dev, 0, NV_PRAMDAC_SEL_CLK, nv04_display(dev)->mode_reg.sel_clk);
}
static void nv04_tmds_dpms(struct drm_encoder *encoder, int mode)
{
struct nouveau_drm *drm = nouveau_drm(encoder->dev);
struct nouveau_encoder *nv_encoder = nouveau_encoder(encoder);
if (nv_encoder->last_dpms == mode)
return;
nv_encoder->last_dpms = mode;
NV_DEBUG(drm, "Setting dpms mode %d on tmds encoder (output %d)\n",
mode, nv_encoder->dcb->index);
nv04_dfp_update_backlight(encoder, mode);
nv04_dfp_update_fp_control(encoder, mode);
}
static void nv04_dfp_save(struct drm_encoder *encoder)
{
struct nouveau_encoder *nv_encoder = nouveau_encoder(encoder);
struct drm_device *dev = encoder->dev;
if (nv_two_heads(dev))
nv_encoder->restore.head =
nv04_dfp_get_bound_head(dev, nv_encoder->dcb);
}
static void nv04_dfp_restore(struct drm_encoder *encoder)
{
struct nouveau_encoder *nv_encoder = nouveau_encoder(encoder);
struct drm_device *dev = encoder->dev;
int head = nv_encoder->restore.head;
if (nv_encoder->dcb->type == DCB_OUTPUT_LVDS) {
struct nouveau_connector *connector =
nouveau_encoder_connector_get(nv_encoder);
if (connector && connector->native_mode)
call_lvds_script(dev, nv_encoder->dcb, head,
LVDS_PANEL_ON,
connector->native_mode->clock);
} else if (nv_encoder->dcb->type == DCB_OUTPUT_TMDS) {
int clock = nouveau_hw_pllvals_to_clk
(&nv04_display(dev)->saved_reg.crtc_reg[head].pllvals);
run_tmds_table(dev, nv_encoder->dcb, head, clock);
}
nv_encoder->last_dpms = NV_DPMS_CLEARED;
}
static void nv04_dfp_destroy(struct drm_encoder *encoder)
{
struct nouveau_encoder *nv_encoder = nouveau_encoder(encoder);
if (get_slave_funcs(encoder))
get_slave_funcs(encoder)->destroy(encoder);
drm_encoder_cleanup(encoder);
kfree(nv_encoder);
}
static void nv04_tmds_slave_init(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
struct dcb_output *dcb = nouveau_encoder(encoder)->dcb;
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_i2c *i2c = nvxx_i2c(&drm->device);
struct nvkm_i2c_port *port = i2c->find(i2c, 2);
struct nvkm_i2c_board_info info[] = {
{
{
.type = "sil164",
.addr = (dcb->tmdsconf.slave_addr == 0x7 ? 0x3a : 0x38),
.platform_data = &(struct sil164_encoder_params) {
SIL164_INPUT_EDGE_RISING
}
}, 0
},
{ }
};
int type;
if (!nv_gf4_disp_arch(dev) || !port ||
get_tmds_slave(encoder))
return;
type = i2c->identify(i2c, 2, "TMDS transmitter", info, NULL, NULL);
if (type < 0)
return;
drm_i2c_encoder_init(dev, to_encoder_slave(encoder),
&port->adapter, &info[type].dev);
}
int
nv04_dfp_create(struct drm_connector *connector, struct dcb_output *entry)
{
const struct drm_encoder_helper_funcs *helper;
struct nouveau_encoder *nv_encoder = NULL;
struct drm_encoder *encoder;
int type;
switch (entry->type) {
case DCB_OUTPUT_TMDS:
type = DRM_MODE_ENCODER_TMDS;
helper = &nv04_tmds_helper_funcs;
break;
case DCB_OUTPUT_LVDS:
type = DRM_MODE_ENCODER_LVDS;
helper = &nv04_lvds_helper_funcs;
break;
default:
return -EINVAL;
}
nv_encoder = kzalloc(sizeof(*nv_encoder), GFP_KERNEL);
if (!nv_encoder)
return -ENOMEM;
encoder = to_drm_encoder(nv_encoder);
nv_encoder->dcb = entry;
nv_encoder->or = ffs(entry->or) - 1;
drm_encoder_init(connector->dev, encoder, &nv04_dfp_funcs, type);
drm_encoder_helper_add(encoder, helper);
encoder->possible_crtcs = entry->heads;
encoder->possible_clones = 0;
if (entry->type == DCB_OUTPUT_TMDS &&
entry->location != DCB_LOC_ON_CHIP)
nv04_tmds_slave_init(encoder);
drm_mode_connector_attach_encoder(connector, encoder);
return 0;
}
