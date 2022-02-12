static int sti_hqvdp_get_free_cmd(struct sti_hqvdp *hqvdp)
{
int curr_cmd, next_cmd;
dma_addr_t cmd = hqvdp->hqvdp_cmd_paddr;
int i;
curr_cmd = readl(hqvdp->regs + HQVDP_MBX_CURRENT_CMD);
next_cmd = readl(hqvdp->regs + HQVDP_MBX_NEXT_CMD);
for (i = 0; i < NB_VDP_CMD; i++) {
if ((cmd != curr_cmd) && (cmd != next_cmd))
return i * sizeof(struct sti_hqvdp_cmd);
cmd += sizeof(struct sti_hqvdp_cmd);
}
return -1;
}
static int sti_hqvdp_get_curr_cmd(struct sti_hqvdp *hqvdp)
{
int curr_cmd;
dma_addr_t cmd = hqvdp->hqvdp_cmd_paddr;
unsigned int i;
curr_cmd = readl(hqvdp->regs + HQVDP_MBX_CURRENT_CMD);
for (i = 0; i < NB_VDP_CMD; i++) {
if (cmd == curr_cmd)
return i * sizeof(struct sti_hqvdp_cmd);
cmd += sizeof(struct sti_hqvdp_cmd);
}
return -1;
}
static void sti_hqvdp_update_hvsrc(enum sti_hvsrc_orient orient, int scale,
struct sti_hqvdp_hvsrc *hvsrc)
{
const int *coef_c, *coef_y;
int shift_c, shift_y;
if (scale < SCALE_MAX_FOR_LEG_LUT_F) {
coef_y = coef_lut_f_y_legacy;
coef_c = coef_lut_f_c_legacy;
shift_y = SHIFT_LUT_F_Y_LEGACY;
shift_c = SHIFT_LUT_F_C_LEGACY;
} else if (scale < SCALE_MAX_FOR_LEG_LUT_E) {
coef_y = coef_lut_e_y_legacy;
coef_c = coef_lut_e_c_legacy;
shift_y = SHIFT_LUT_E_Y_LEGACY;
shift_c = SHIFT_LUT_E_C_LEGACY;
} else if (scale < SCALE_MAX_FOR_LEG_LUT_D) {
coef_y = coef_lut_d_y_legacy;
coef_c = coef_lut_d_c_legacy;
shift_y = SHIFT_LUT_D_Y_LEGACY;
shift_c = SHIFT_LUT_D_C_LEGACY;
} else if (scale < SCALE_MAX_FOR_LEG_LUT_C) {
coef_y = coef_lut_c_y_legacy;
coef_c = coef_lut_c_c_legacy;
shift_y = SHIFT_LUT_C_Y_LEGACY;
shift_c = SHIFT_LUT_C_C_LEGACY;
} else if (scale == SCALE_MAX_FOR_LEG_LUT_C) {
coef_y = coef_c = coef_lut_b;
shift_y = shift_c = SHIFT_LUT_B;
} else {
coef_y = coef_c = coef_lut_a_legacy;
shift_y = shift_c = SHIFT_LUT_A_LEGACY;
}
if (orient == HVSRC_HORI) {
hvsrc->hori_shift = (shift_c << 16) | shift_y;
memcpy(hvsrc->yh_coef, coef_y, sizeof(hvsrc->yh_coef));
memcpy(hvsrc->ch_coef, coef_c, sizeof(hvsrc->ch_coef));
} else {
hvsrc->vert_shift = (shift_c << 16) | shift_y;
memcpy(hvsrc->yv_coef, coef_y, sizeof(hvsrc->yv_coef));
memcpy(hvsrc->cv_coef, coef_c, sizeof(hvsrc->cv_coef));
}
}
static bool sti_hqvdp_check_hw_scaling(struct sti_hqvdp *hqvdp,
struct drm_display_mode *mode,
int src_w, int src_h,
int dst_w, int dst_h)
{
unsigned long lfw;
unsigned int inv_zy;
lfw = mode->htotal * (clk_get_rate(hqvdp->clk) / 1000000);
lfw /= max(src_w, dst_w) * mode->clock / 1000;
inv_zy = DIV_ROUND_UP(src_h, dst_h);
return (inv_zy <= lfw) ? true : false;
}
static void sti_hqvdp_disable(struct sti_hqvdp *hqvdp)
{
int i;
DRM_DEBUG_DRIVER("%s\n", sti_plane_to_str(&hqvdp->plane));
if (sti_vtg_unregister_client(hqvdp->vtg, &hqvdp->vtg_nb))
DRM_DEBUG_DRIVER("Warning: cannot unregister VTG notifier\n");
writel(0, hqvdp->regs + HQVDP_MBX_NEXT_CMD);
for (i = 0; i < POLL_MAX_ATTEMPT; i++) {
if (readl(hqvdp->regs + HQVDP_MBX_INFO_XP70)
& INFO_XP70_FW_READY)
break;
msleep(POLL_DELAY_MS);
}
clk_disable_unprepare(hqvdp->clk_pix_main);
if (i == POLL_MAX_ATTEMPT)
DRM_ERROR("XP70 could not revert to idle\n");
hqvdp->plane.status = STI_PLANE_DISABLED;
}
int sti_hqvdp_vtg_cb(struct notifier_block *nb, unsigned long evt, void *data)
{
struct sti_hqvdp *hqvdp = container_of(nb, struct sti_hqvdp, vtg_nb);
int btm_cmd_offset, top_cmd_offest;
struct sti_hqvdp_cmd *btm_cmd, *top_cmd;
if ((evt != VTG_TOP_FIELD_EVENT) && (evt != VTG_BOTTOM_FIELD_EVENT)) {
DRM_DEBUG_DRIVER("Unknown event\n");
return 0;
}
if (hqvdp->plane.status == STI_PLANE_FLUSHING) {
DRM_DEBUG_DRIVER("Vsync event received => disable %s\n",
sti_plane_to_str(&hqvdp->plane));
sti_hqvdp_disable(hqvdp);
}
if (hqvdp->btm_field_pending) {
btm_cmd_offset = sti_hqvdp_get_free_cmd(hqvdp);
top_cmd_offest = sti_hqvdp_get_curr_cmd(hqvdp);
if ((btm_cmd_offset == -1) || (top_cmd_offest == -1)) {
DRM_ERROR("Cannot get cmds, skip btm field\n");
return -EBUSY;
}
btm_cmd = hqvdp->hqvdp_cmd + btm_cmd_offset;
top_cmd = hqvdp->hqvdp_cmd + top_cmd_offest;
memcpy(btm_cmd, top_cmd, sizeof(*btm_cmd));
btm_cmd->top.config = TOP_CONFIG_INTER_BTM;
btm_cmd->top.current_luma +=
btm_cmd->top.luma_src_pitch / 2;
btm_cmd->top.current_chroma +=
btm_cmd->top.chroma_src_pitch / 2;
writel(hqvdp->hqvdp_cmd_paddr + btm_cmd_offset,
hqvdp->regs + HQVDP_MBX_NEXT_CMD);
hqvdp->curr_field_count++;
hqvdp->btm_field_pending = false;
dev_dbg(hqvdp->dev, "%s Posted command:0x%x\n",
__func__, hqvdp->hqvdp_cmd_paddr);
}
return 0;
}
static void sti_hqvdp_init(struct sti_hqvdp *hqvdp)
{
int size;
hqvdp->vtg_nb.notifier_call = sti_hqvdp_vtg_cb;
size = NB_VDP_CMD * sizeof(struct sti_hqvdp_cmd);
hqvdp->hqvdp_cmd = dma_alloc_writecombine(hqvdp->dev, size,
&hqvdp->hqvdp_cmd_paddr,
GFP_KERNEL | GFP_DMA);
if (!hqvdp->hqvdp_cmd) {
DRM_ERROR("Failed to allocate memory for VDP cmd\n");
return;
}
memset(hqvdp->hqvdp_cmd, 0, size);
}
static void sti_hqvdp_atomic_update(struct drm_plane *drm_plane,
struct drm_plane_state *oldstate)
{
struct drm_plane_state *state = drm_plane->state;
struct sti_plane *plane = to_sti_plane(drm_plane);
struct sti_hqvdp *hqvdp = to_sti_hqvdp(plane);
struct drm_crtc *crtc = state->crtc;
struct sti_mixer *mixer = to_sti_mixer(crtc);
struct drm_framebuffer *fb = state->fb;
struct drm_display_mode *mode = &crtc->mode;
int dst_x = state->crtc_x;
int dst_y = state->crtc_y;
int dst_w = clamp_val(state->crtc_w, 0, mode->crtc_hdisplay - dst_x);
int dst_h = clamp_val(state->crtc_h, 0, mode->crtc_vdisplay - dst_y);
int src_x = state->src_x >> 16;
int src_y = state->src_y >> 16;
int src_w = state->src_w >> 16;
int src_h = state->src_h >> 16;
bool first_prepare = plane->status == STI_PLANE_DISABLED ? true : false;
struct drm_gem_cma_object *cma_obj;
struct sti_hqvdp_cmd *cmd;
int scale_h, scale_v;
int cmd_offset;
DRM_DEBUG_KMS("CRTC:%d (%s) drm plane:%d (%s)\n",
crtc->base.id, sti_mixer_to_str(mixer),
drm_plane->base.id, sti_plane_to_str(plane));
DRM_DEBUG_KMS("%s dst=(%dx%d)@(%d,%d) - src=(%dx%d)@(%d,%d)\n",
sti_plane_to_str(plane),
dst_w, dst_h, dst_x, dst_y,
src_w, src_h, src_x, src_y);
cmd_offset = sti_hqvdp_get_free_cmd(hqvdp);
if (cmd_offset == -1) {
DRM_ERROR("No available hqvdp_cmd now\n");
return;
}
cmd = hqvdp->hqvdp_cmd + cmd_offset;
if (!sti_hqvdp_check_hw_scaling(hqvdp, mode,
src_w, src_h,
dst_w, dst_h)) {
DRM_ERROR("Scaling beyond HW capabilities\n");
return;
}
cmd->top.config = TOP_CONFIG_PROGRESSIVE;
cmd->top.mem_format = TOP_MEM_FORMAT_DFLT;
cmd->hvsrc.param_ctrl = HVSRC_PARAM_CTRL_DFLT;
cmd->csdi.config = CSDI_CONFIG_PROG;
cmd->iqi.config = IQI_CONFIG_DFLT;
cmd->iqi.con_bri = IQI_CON_BRI_DFLT;
cmd->iqi.sat_gain = IQI_SAT_GAIN_DFLT;
cmd->iqi.pxf_conf = IQI_PXF_CONF_DFLT;
cma_obj = drm_fb_cma_get_gem_obj(fb, 0);
if (!cma_obj) {
DRM_ERROR("Can't get CMA GEM object for fb\n");
return;
}
DRM_DEBUG_DRIVER("drm FB:%d format:%.4s phys@:0x%lx\n", fb->base.id,
(char *)&fb->pixel_format,
(unsigned long)cma_obj->paddr);
cmd->top.current_luma = (u32)cma_obj->paddr + fb->offsets[0];
cmd->top.current_chroma = (u32)cma_obj->paddr + fb->offsets[1];
cmd->top.luma_processed_pitch = fb->pitches[0];
cmd->top.luma_src_pitch = fb->pitches[0];
cmd->top.chroma_processed_pitch = fb->pitches[1];
cmd->top.chroma_src_pitch = fb->pitches[1];
dst_w = ALIGN(dst_w, 2);
dst_h = ALIGN(dst_h, 2);
if ((src_w > MAX_WIDTH) || (src_w < MIN_WIDTH) ||
(src_h > MAX_HEIGHT) || (src_h < MIN_HEIGHT) ||
(dst_w > MAX_WIDTH) || (dst_w < MIN_WIDTH) ||
(dst_h > MAX_HEIGHT) || (dst_h < MIN_HEIGHT)) {
DRM_ERROR("Invalid in/out size %dx%d -> %dx%d\n",
src_w, src_h,
dst_w, dst_h);
return;
}
cmd->top.input_viewport_size = src_h << 16 | src_w;
cmd->top.input_frame_size = src_h << 16 | src_w;
cmd->hvsrc.output_picture_size = dst_h << 16 | dst_w;
cmd->top.input_viewport_ori = src_y << 16 | src_x;
if (fb->flags & DRM_MODE_FB_INTERLACED) {
cmd->top.config = TOP_CONFIG_INTER_TOP;
cmd->top.input_frame_size = (src_h / 2) << 16 | src_w;
cmd->top.luma_processed_pitch *= 2;
cmd->top.luma_src_pitch *= 2;
cmd->top.chroma_processed_pitch *= 2;
cmd->top.chroma_src_pitch *= 2;
cmd->csdi.config = CSDI_CONFIG_INTER_DIR;
cmd->csdi.config2 = CSDI_CONFIG2_DFLT;
cmd->csdi.dcdi_config = CSDI_DCDI_CONFIG_DFLT;
}
scale_h = SCALE_FACTOR * dst_w / src_w;
sti_hqvdp_update_hvsrc(HVSRC_HORI, scale_h, &cmd->hvsrc);
scale_v = SCALE_FACTOR * dst_h / src_h;
sti_hqvdp_update_hvsrc(HVSRC_VERT, scale_v, &cmd->hvsrc);
if (first_prepare) {
if (clk_prepare_enable(hqvdp->clk_pix_main)) {
DRM_ERROR("Failed to prepare/enable pix main clk\n");
return;
}
if (sti_vtg_register_client(hqvdp->vtg,
&hqvdp->vtg_nb,
mixer->id)) {
DRM_ERROR("Cannot register VTG notifier\n");
return;
}
}
writel(hqvdp->hqvdp_cmd_paddr + cmd_offset,
hqvdp->regs + HQVDP_MBX_NEXT_CMD);
hqvdp->curr_field_count++;
if (fb->flags & DRM_MODE_FB_INTERLACED)
hqvdp->btm_field_pending = true;
dev_dbg(hqvdp->dev, "%s Posted command:0x%x\n",
__func__, hqvdp->hqvdp_cmd_paddr + cmd_offset);
plane->status = STI_PLANE_UPDATED;
}
static void sti_hqvdp_atomic_disable(struct drm_plane *drm_plane,
struct drm_plane_state *oldstate)
{
struct sti_plane *plane = to_sti_plane(drm_plane);
struct sti_mixer *mixer = to_sti_mixer(drm_plane->crtc);
if (!drm_plane->crtc) {
DRM_DEBUG_DRIVER("drm plane:%d not enabled\n",
drm_plane->base.id);
return;
}
DRM_DEBUG_DRIVER("CRTC:%d (%s) drm plane:%d (%s)\n",
drm_plane->crtc->base.id, sti_mixer_to_str(mixer),
drm_plane->base.id, sti_plane_to_str(plane));
plane->status = STI_PLANE_DISABLING;
}
static struct drm_plane *sti_hqvdp_create(struct drm_device *drm_dev,
struct device *dev, int desc)
{
struct sti_hqvdp *hqvdp = dev_get_drvdata(dev);
int res;
hqvdp->plane.desc = desc;
hqvdp->plane.status = STI_PLANE_DISABLED;
sti_hqvdp_init(hqvdp);
res = drm_universal_plane_init(drm_dev, &hqvdp->plane.drm_plane, 1,
&sti_plane_helpers_funcs,
hqvdp_supported_formats,
ARRAY_SIZE(hqvdp_supported_formats),
DRM_PLANE_TYPE_OVERLAY);
if (res) {
DRM_ERROR("Failed to initialize universal plane\n");
return NULL;
}
drm_plane_helper_add(&hqvdp->plane.drm_plane, &sti_hqvdp_helpers_funcs);
sti_plane_init_property(&hqvdp->plane, DRM_PLANE_TYPE_OVERLAY);
return &hqvdp->plane.drm_plane;
}
static void sti_hqvdp_init_plugs(struct sti_hqvdp *hqvdp)
{
writel(PLUG_PAGE_SIZE_256, hqvdp->regs + HQVDP_RD_PLUG_PAGE_SIZE);
writel(PLUG_MIN_OPC_8, hqvdp->regs + HQVDP_RD_PLUG_MIN_OPC);
writel(PLUG_MAX_OPC_64, hqvdp->regs + HQVDP_RD_PLUG_MAX_OPC);
writel(PLUG_MAX_CHK_2X, hqvdp->regs + HQVDP_RD_PLUG_MAX_CHK);
writel(PLUG_MAX_MSG_1X, hqvdp->regs + HQVDP_RD_PLUG_MAX_MSG);
writel(PLUG_MIN_SPACE_1, hqvdp->regs + HQVDP_RD_PLUG_MIN_SPACE);
writel(PLUG_CONTROL_ENABLE, hqvdp->regs + HQVDP_RD_PLUG_CONTROL);
writel(PLUG_PAGE_SIZE_256, hqvdp->regs + HQVDP_WR_PLUG_PAGE_SIZE);
writel(PLUG_MIN_OPC_8, hqvdp->regs + HQVDP_WR_PLUG_MIN_OPC);
writel(PLUG_MAX_OPC_64, hqvdp->regs + HQVDP_WR_PLUG_MAX_OPC);
writel(PLUG_MAX_CHK_2X, hqvdp->regs + HQVDP_WR_PLUG_MAX_CHK);
writel(PLUG_MAX_MSG_1X, hqvdp->regs + HQVDP_WR_PLUG_MAX_MSG);
writel(PLUG_MIN_SPACE_1, hqvdp->regs + HQVDP_WR_PLUG_MIN_SPACE);
writel(PLUG_CONTROL_ENABLE, hqvdp->regs + HQVDP_WR_PLUG_CONTROL);
}
static void sti_hqvdp_start_xp70(const struct firmware *firmware, void *ctxt)
{
struct sti_hqvdp *hqvdp = ctxt;
u32 *fw_rd_plug, *fw_wr_plug, *fw_pmem, *fw_dmem;
u8 *data;
int i;
struct fw_header {
int rd_size;
int wr_size;
int pmem_size;
int dmem_size;
} *header;
DRM_DEBUG_DRIVER("\n");
if (hqvdp->xp70_initialized) {
DRM_INFO("HQVDP XP70 already initialized\n");
return;
}
if (!firmware) {
DRM_ERROR("Firmware not available\n");
return;
}
header = (struct fw_header *) firmware->data;
if (firmware->size < sizeof(*header)) {
DRM_ERROR("Invalid firmware size (%d)\n", firmware->size);
goto out;
}
if ((sizeof(*header) + header->rd_size + header->wr_size +
header->pmem_size + header->dmem_size) != firmware->size) {
DRM_ERROR("Invalid fmw structure (%d+%d+%d+%d+%d != %d)\n",
sizeof(*header), header->rd_size, header->wr_size,
header->pmem_size, header->dmem_size,
firmware->size);
goto out;
}
data = (u8 *) firmware->data;
data += sizeof(*header);
fw_rd_plug = (void *) data;
data += header->rd_size;
fw_wr_plug = (void *) data;
data += header->wr_size;
fw_pmem = (void *) data;
data += header->pmem_size;
fw_dmem = (void *) data;
if (clk_prepare_enable(hqvdp->clk))
DRM_ERROR("Failed to prepare/enable HQVDP clk\n");
writel(SW_RESET_CTRL_FULL, hqvdp->regs + HQVDP_MBX_SW_RESET_CTRL);
for (i = 0; i < POLL_MAX_ATTEMPT; i++) {
if (readl(hqvdp->regs + HQVDP_MBX_STARTUP_CTRL1)
& STARTUP_CTRL1_RST_DONE)
break;
msleep(POLL_DELAY_MS);
}
if (i == POLL_MAX_ATTEMPT) {
DRM_ERROR("Could not reset\n");
goto out;
}
for (i = 0; i < header->rd_size / 4; i++)
writel(fw_rd_plug[i], hqvdp->regs + HQVDP_RD_PLUG + i * 4);
for (i = 0; i < header->wr_size / 4; i++)
writel(fw_wr_plug[i], hqvdp->regs + HQVDP_WR_PLUG + i * 4);
sti_hqvdp_init_plugs(hqvdp);
writel(STARTUP_CTRL1_AUTH_IDLE, hqvdp->regs + HQVDP_MBX_STARTUP_CTRL1);
writel(SOFT_VSYNC_SW_CTRL_IRQ, hqvdp->regs + HQVDP_MBX_SOFT_VSYNC);
writel(0, hqvdp->regs + HQVDP_MBX_NEXT_CMD);
for (i = 0; i < header->pmem_size / 4; i++)
writel(fw_pmem[i], hqvdp->regs + HQVDP_PMEM + i * 4);
for (i = 0; i < header->dmem_size / 4; i++)
writel(fw_dmem[i], hqvdp->regs + HQVDP_DMEM + i * 4);
writel(STARTUP_CTRL2_FETCH_EN, hqvdp->regs + HQVDP_MBX_STARTUP_CTRL2);
for (i = 0; i < POLL_MAX_ATTEMPT; i++) {
if (readl(hqvdp->regs + HQVDP_MBX_INFO_XP70)
& INFO_XP70_FW_READY)
break;
msleep(POLL_DELAY_MS);
}
if (i == POLL_MAX_ATTEMPT) {
DRM_ERROR("Could not boot\n");
goto out;
}
writel(SOFT_VSYNC_HW, hqvdp->regs + HQVDP_MBX_SOFT_VSYNC);
DRM_INFO("HQVDP XP70 initialized\n");
hqvdp->xp70_initialized = true;
out:
release_firmware(firmware);
}
int sti_hqvdp_bind(struct device *dev, struct device *master, void *data)
{
struct sti_hqvdp *hqvdp = dev_get_drvdata(dev);
struct drm_device *drm_dev = data;
struct drm_plane *plane;
int err;
DRM_DEBUG_DRIVER("\n");
hqvdp->drm_dev = drm_dev;
err = request_firmware_nowait(THIS_MODULE, FW_ACTION_HOTPLUG,
HQVDP_FMW_NAME, hqvdp->dev,
GFP_KERNEL, hqvdp, sti_hqvdp_start_xp70);
if (err) {
DRM_ERROR("Can't get HQVDP firmware\n");
return err;
}
plane = sti_hqvdp_create(drm_dev, hqvdp->dev, STI_HQVDP_0);
if (!plane)
DRM_ERROR("Can't create HQVDP plane\n");
return 0;
}
static void sti_hqvdp_unbind(struct device *dev,
struct device *master, void *data)
{
}
static int sti_hqvdp_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *vtg_np;
struct sti_hqvdp *hqvdp;
struct resource *res;
DRM_DEBUG_DRIVER("\n");
hqvdp = devm_kzalloc(dev, sizeof(*hqvdp), GFP_KERNEL);
if (!hqvdp) {
DRM_ERROR("Failed to allocate HQVDP context\n");
return -ENOMEM;
}
hqvdp->dev = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
DRM_ERROR("Get memory resource failed\n");
return -ENXIO;
}
hqvdp->regs = devm_ioremap(dev, res->start, resource_size(res));
if (hqvdp->regs == NULL) {
DRM_ERROR("Register mapping failed\n");
return -ENXIO;
}
hqvdp->clk = devm_clk_get(dev, "hqvdp");
hqvdp->clk_pix_main = devm_clk_get(dev, "pix_main");
if (IS_ERR(hqvdp->clk) || IS_ERR(hqvdp->clk_pix_main)) {
DRM_ERROR("Cannot get clocks\n");
return -ENXIO;
}
hqvdp->reset = devm_reset_control_get(dev, "hqvdp");
if (!IS_ERR(hqvdp->reset))
reset_control_deassert(hqvdp->reset);
vtg_np = of_parse_phandle(pdev->dev.of_node, "st,vtg", 0);
if (vtg_np)
hqvdp->vtg = of_vtg_find(vtg_np);
platform_set_drvdata(pdev, hqvdp);
return component_add(&pdev->dev, &sti_hqvdp_ops);
}
static int sti_hqvdp_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &sti_hqvdp_ops);
return 0;
}
