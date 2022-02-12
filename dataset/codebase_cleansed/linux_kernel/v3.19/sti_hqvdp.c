static const uint32_t *sti_hqvdp_get_formats(struct sti_layer *layer)
{
return hqvdp_supported_formats;
}
static unsigned int sti_hqvdp_get_nb_formats(struct sti_layer *layer)
{
return ARRAY_SIZE(hqvdp_supported_formats);
}
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
static bool sti_hqvdp_check_hw_scaling(struct sti_layer *layer)
{
struct sti_hqvdp *hqvdp = to_sti_hqvdp(layer);
unsigned long lfw;
unsigned int inv_zy;
lfw = layer->mode->htotal * (clk_get_rate(hqvdp->clk) / 1000000);
lfw /= max(layer->src_w, layer->dst_w) * layer->mode->clock / 1000;
inv_zy = DIV_ROUND_UP(layer->src_h, layer->dst_h);
return (inv_zy <= lfw) ? true : false;
}
static int sti_hqvdp_prepare_layer(struct sti_layer *layer, bool first_prepare)
{
struct sti_hqvdp *hqvdp = to_sti_hqvdp(layer);
struct sti_hqvdp_cmd *cmd;
int scale_h, scale_v;
int cmd_offset;
dev_dbg(hqvdp->dev, "%s %s\n", __func__, sti_layer_to_str(layer));
hqvdp->vid_plane->funcs->update_plane(hqvdp->vid_plane,
layer->crtc, layer->fb,
layer->dst_x, layer->dst_y,
layer->dst_w, layer->dst_h,
layer->src_x, layer->src_y,
layer->src_w, layer->src_h);
cmd_offset = sti_hqvdp_get_free_cmd(hqvdp);
if (cmd_offset == -1) {
DRM_ERROR("No available hqvdp_cmd now\n");
return -EBUSY;
}
cmd = hqvdp->hqvdp_cmd + cmd_offset;
if (!sti_hqvdp_check_hw_scaling(layer)) {
DRM_ERROR("Scaling beyond HW capabilities\n");
return -EINVAL;
}
cmd->top.config = TOP_CONFIG_PROGRESSIVE;
cmd->top.mem_format = TOP_MEM_FORMAT_DFLT;
cmd->hvsrc.param_ctrl = HVSRC_PARAM_CTRL_DFLT;
cmd->csdi.config = CSDI_CONFIG_PROG;
cmd->iqi.config = IQI_CONFIG_DFLT;
cmd->iqi.con_bri = IQI_CON_BRI_DFLT;
cmd->iqi.sat_gain = IQI_SAT_GAIN_DFLT;
cmd->iqi.pxf_conf = IQI_PXF_CONF_DFLT;
cmd->top.current_luma = (u32) layer->paddr + layer->offsets[0];
cmd->top.current_chroma = (u32) layer->paddr + layer->offsets[1];
cmd->top.luma_processed_pitch = cmd->top.luma_src_pitch =
layer->pitches[0];
cmd->top.chroma_processed_pitch = cmd->top.chroma_src_pitch =
layer->pitches[1];
layer->dst_w = ALIGN(layer->dst_w, 2);
layer->dst_h = ALIGN(layer->dst_h, 2);
if ((layer->src_w > MAX_WIDTH) || (layer->src_w < MIN_WIDTH) ||
(layer->src_h > MAX_HEIGHT) || (layer->src_h < MIN_HEIGHT) ||
(layer->dst_w > MAX_WIDTH) || (layer->dst_w < MIN_WIDTH) ||
(layer->dst_h > MAX_HEIGHT) || (layer->dst_h < MIN_HEIGHT)) {
DRM_ERROR("Invalid in/out size %dx%d -> %dx%d\n",
layer->src_w, layer->src_h,
layer->dst_w, layer->dst_h);
return -EINVAL;
}
cmd->top.input_viewport_size = cmd->top.input_frame_size =
layer->src_h << 16 | layer->src_w;
cmd->hvsrc.output_picture_size = layer->dst_h << 16 | layer->dst_w;
cmd->top.input_viewport_ori = layer->src_y << 16 | layer->src_x;
if (layer->fb->flags & DRM_MODE_FB_INTERLACED) {
cmd->top.config = TOP_CONFIG_INTER_TOP;
cmd->top.input_frame_size = (layer->src_h / 2) << 16 |
layer->src_w;
cmd->top.luma_processed_pitch *= 2;
cmd->top.luma_src_pitch *= 2;
cmd->top.chroma_processed_pitch *= 2;
cmd->top.chroma_src_pitch *= 2;
cmd->csdi.config = CSDI_CONFIG_INTER_DIR;
cmd->csdi.config2 = CSDI_CONFIG2_DFLT;
cmd->csdi.dcdi_config = CSDI_DCDI_CONFIG_DFLT;
}
scale_h = SCALE_FACTOR * layer->dst_w / layer->src_w;
sti_hqvdp_update_hvsrc(HVSRC_HORI, scale_h, &cmd->hvsrc);
scale_v = SCALE_FACTOR * layer->dst_h / layer->src_h;
sti_hqvdp_update_hvsrc(HVSRC_VERT, scale_v, &cmd->hvsrc);
if (first_prepare) {
if (clk_prepare_enable(hqvdp->clk_pix_main)) {
DRM_ERROR("Failed to prepare/enable pix main clk\n");
return -ENXIO;
}
if ((layer->fb->flags & DRM_MODE_FB_INTERLACED) &&
sti_vtg_register_client(hqvdp->vtg,
&hqvdp->vtg_nb, layer->mixer_id)) {
DRM_ERROR("Cannot register VTG notifier\n");
return -ENXIO;
}
}
return 0;
}
static int sti_hqvdp_commit_layer(struct sti_layer *layer)
{
struct sti_hqvdp *hqvdp = to_sti_hqvdp(layer);
int cmd_offset;
dev_dbg(hqvdp->dev, "%s %s\n", __func__, sti_layer_to_str(layer));
cmd_offset = sti_hqvdp_get_free_cmd(hqvdp);
if (cmd_offset == -1) {
DRM_ERROR("No available hqvdp_cmd now\n");
return -EBUSY;
}
writel(hqvdp->hqvdp_cmd_paddr + cmd_offset,
hqvdp->regs + HQVDP_MBX_NEXT_CMD);
hqvdp->curr_field_count++;
if (layer->fb->flags & DRM_MODE_FB_INTERLACED)
hqvdp->btm_field_pending = true;
dev_dbg(hqvdp->dev, "%s Posted command:0x%x\n",
__func__, hqvdp->hqvdp_cmd_paddr + cmd_offset);
return 0;
}
static int sti_hqvdp_disable_layer(struct sti_layer *layer)
{
struct sti_hqvdp *hqvdp = to_sti_hqvdp(layer);
int i;
DRM_DEBUG_DRIVER("%s\n", sti_layer_to_str(layer));
if ((layer->fb->flags & DRM_MODE_FB_INTERLACED) &&
sti_vtg_unregister_client(hqvdp->vtg, &hqvdp->vtg_nb))
DRM_DEBUG_DRIVER("Warning: cannot unregister VTG notifier\n");
writel(0, hqvdp->regs + HQVDP_MBX_NEXT_CMD);
for (i = 0; i < POLL_MAX_ATTEMPT; i++) {
if (readl(hqvdp->regs + HQVDP_MBX_INFO_XP70)
& INFO_XP70_FW_READY)
break;
msleep(POLL_DELAY_MS);
}
clk_disable_unprepare(hqvdp->clk_pix_main);
if (i == POLL_MAX_ATTEMPT) {
DRM_ERROR("XP70 could not revert to idle\n");
return -ENXIO;
}
hqvdp->vid_plane->funcs->disable_plane(hqvdp->vid_plane);
return 0;
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
static struct drm_plane *sti_hqvdp_find_vid(struct drm_device *dev, int id)
{
struct drm_plane *plane;
list_for_each_entry(plane, &dev->mode_config.plane_list, head) {
struct sti_layer *layer = to_sti_layer(plane);
if (layer->desc == id)
return plane;
}
return NULL;
}
static void sti_hqvd_init(struct sti_layer *layer)
{
struct sti_hqvdp *hqvdp = to_sti_hqvdp(layer);
int size;
hqvdp->vid_plane = sti_hqvdp_find_vid(hqvdp->drm_dev, STI_VID_0);
if (!hqvdp->vid_plane) {
DRM_ERROR("Cannot find Main video layer\n");
return;
}
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
struct sti_layer *sti_hqvdp_create(struct device *dev)
{
struct sti_hqvdp *hqvdp = dev_get_drvdata(dev);
hqvdp->layer.ops = &hqvdp_ops;
return &hqvdp->layer;
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
DRM_INFO("HQVDP XP70 started\n");
out:
release_firmware(firmware);
}
int sti_hqvdp_bind(struct device *dev, struct device *master, void *data)
{
struct sti_hqvdp *hqvdp = dev_get_drvdata(dev);
struct drm_device *drm_dev = data;
struct sti_layer *layer;
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
layer = sti_layer_create(hqvdp->dev, STI_HQVDP_0, hqvdp->regs);
if (!layer) {
DRM_ERROR("Can't create HQVDP plane\n");
return -ENOMEM;
}
sti_drm_plane_init(drm_dev, layer, 1, DRM_PLANE_TYPE_OVERLAY);
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
if (IS_ERR(hqvdp->clk) || IS_ERR(hqvdp->clk)) {
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
