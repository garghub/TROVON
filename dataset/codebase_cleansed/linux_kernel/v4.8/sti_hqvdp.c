static int sti_hqvdp_get_free_cmd(struct sti_hqvdp *hqvdp)
{
u32 curr_cmd, next_cmd;
u32 cmd = hqvdp->hqvdp_cmd_paddr;
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
u32 curr_cmd;
u32 cmd = hqvdp->hqvdp_cmd_paddr;
unsigned int i;
curr_cmd = readl(hqvdp->regs + HQVDP_MBX_CURRENT_CMD);
for (i = 0; i < NB_VDP_CMD; i++) {
if (cmd == curr_cmd)
return i * sizeof(struct sti_hqvdp_cmd);
cmd += sizeof(struct sti_hqvdp_cmd);
}
return -1;
}
static int sti_hqvdp_get_next_cmd(struct sti_hqvdp *hqvdp)
{
int next_cmd;
dma_addr_t cmd = hqvdp->hqvdp_cmd_paddr;
unsigned int i;
next_cmd = readl(hqvdp->regs + HQVDP_MBX_NEXT_CMD);
for (i = 0; i < NB_VDP_CMD; i++) {
if (cmd == next_cmd)
return i * sizeof(struct sti_hqvdp_cmd);
cmd += sizeof(struct sti_hqvdp_cmd);
}
return -1;
}
static const char *hqvdp_dbg_get_lut(u32 *coef)
{
if (!memcmp(coef, coef_lut_a_legacy, 16))
return "LUT A";
if (!memcmp(coef, coef_lut_b, 16))
return "LUT B";
if (!memcmp(coef, coef_lut_c_y_legacy, 16))
return "LUT C Y";
if (!memcmp(coef, coef_lut_c_c_legacy, 16))
return "LUT C C";
if (!memcmp(coef, coef_lut_d_y_legacy, 16))
return "LUT D Y";
if (!memcmp(coef, coef_lut_d_c_legacy, 16))
return "LUT D C";
if (!memcmp(coef, coef_lut_e_y_legacy, 16))
return "LUT E Y";
if (!memcmp(coef, coef_lut_e_c_legacy, 16))
return "LUT E C";
if (!memcmp(coef, coef_lut_f_y_legacy, 16))
return "LUT F Y";
if (!memcmp(coef, coef_lut_f_c_legacy, 16))
return "LUT F C";
return "<UNKNOWN>";
}
static void hqvdp_dbg_dump_cmd(struct seq_file *s, struct sti_hqvdp_cmd *c)
{
int src_w, src_h, dst_w, dst_h;
seq_puts(s, "\n\tTOP:");
seq_printf(s, "\n\t %-20s 0x%08X", "Config", c->top.config);
switch (c->top.config) {
case TOP_CONFIG_PROGRESSIVE:
seq_puts(s, "\tProgressive");
break;
case TOP_CONFIG_INTER_TOP:
seq_puts(s, "\tInterlaced, top field");
break;
case TOP_CONFIG_INTER_BTM:
seq_puts(s, "\tInterlaced, bottom field");
break;
default:
seq_puts(s, "\t<UNKNOWN>");
break;
}
seq_printf(s, "\n\t %-20s 0x%08X", "MemFormat", c->top.mem_format);
seq_printf(s, "\n\t %-20s 0x%08X", "CurrentY", c->top.current_luma);
seq_printf(s, "\n\t %-20s 0x%08X", "CurrentC", c->top.current_chroma);
seq_printf(s, "\n\t %-20s 0x%08X", "YSrcPitch", c->top.luma_src_pitch);
seq_printf(s, "\n\t %-20s 0x%08X", "CSrcPitch",
c->top.chroma_src_pitch);
seq_printf(s, "\n\t %-20s 0x%08X", "InputFrameSize",
c->top.input_frame_size);
seq_printf(s, "\t%dx%d",
c->top.input_frame_size & 0x0000FFFF,
c->top.input_frame_size >> 16);
seq_printf(s, "\n\t %-20s 0x%08X", "InputViewportSize",
c->top.input_viewport_size);
src_w = c->top.input_viewport_size & 0x0000FFFF;
src_h = c->top.input_viewport_size >> 16;
seq_printf(s, "\t%dx%d", src_w, src_h);
seq_puts(s, "\n\tHVSRC:");
seq_printf(s, "\n\t %-20s 0x%08X", "OutputPictureSize",
c->hvsrc.output_picture_size);
dst_w = c->hvsrc.output_picture_size & 0x0000FFFF;
dst_h = c->hvsrc.output_picture_size >> 16;
seq_printf(s, "\t%dx%d", dst_w, dst_h);
seq_printf(s, "\n\t %-20s 0x%08X", "ParamCtrl", c->hvsrc.param_ctrl);
seq_printf(s, "\n\t %-20s %s", "yh_coef",
hqvdp_dbg_get_lut(c->hvsrc.yh_coef));
seq_printf(s, "\n\t %-20s %s", "ch_coef",
hqvdp_dbg_get_lut(c->hvsrc.ch_coef));
seq_printf(s, "\n\t %-20s %s", "yv_coef",
hqvdp_dbg_get_lut(c->hvsrc.yv_coef));
seq_printf(s, "\n\t %-20s %s", "cv_coef",
hqvdp_dbg_get_lut(c->hvsrc.cv_coef));
seq_printf(s, "\n\t %-20s", "ScaleH");
if (dst_w > src_w)
seq_printf(s, " %d/1", dst_w / src_w);
else
seq_printf(s, " 1/%d", src_w / dst_w);
seq_printf(s, "\n\t %-20s", "tScaleV");
if (dst_h > src_h)
seq_printf(s, " %d/1", dst_h / src_h);
else
seq_printf(s, " 1/%d", src_h / dst_h);
seq_puts(s, "\n\tCSDI:");
seq_printf(s, "\n\t %-20s 0x%08X\t", "Config", c->csdi.config);
switch (c->csdi.config) {
case CSDI_CONFIG_PROG:
seq_puts(s, "Bypass");
break;
case CSDI_CONFIG_INTER_DIR:
seq_puts(s, "Deinterlace, directional");
break;
default:
seq_puts(s, "<UNKNOWN>");
break;
}
seq_printf(s, "\n\t %-20s 0x%08X", "Config2", c->csdi.config2);
seq_printf(s, "\n\t %-20s 0x%08X", "DcdiConfig", c->csdi.dcdi_config);
}
static int hqvdp_dbg_show(struct seq_file *s, void *data)
{
struct drm_info_node *node = s->private;
struct sti_hqvdp *hqvdp = (struct sti_hqvdp *)node->info_ent->data;
int cmd, cmd_offset, infoxp70;
void *virt;
seq_printf(s, "%s: (vaddr = 0x%p)",
sti_plane_to_str(&hqvdp->plane), hqvdp->regs);
DBGFS_DUMP(HQVDP_MBX_IRQ_TO_XP70);
DBGFS_DUMP(HQVDP_MBX_INFO_HOST);
DBGFS_DUMP(HQVDP_MBX_IRQ_TO_HOST);
DBGFS_DUMP(HQVDP_MBX_INFO_XP70);
infoxp70 = readl(hqvdp->regs + HQVDP_MBX_INFO_XP70);
seq_puts(s, "\tFirmware state: ");
if (infoxp70 & INFO_XP70_FW_READY)
seq_puts(s, "idle and ready");
else if (infoxp70 & INFO_XP70_FW_PROCESSING)
seq_puts(s, "processing a picture");
else if (infoxp70 & INFO_XP70_FW_INITQUEUES)
seq_puts(s, "programming queues");
else
seq_puts(s, "NOT READY");
DBGFS_DUMP(HQVDP_MBX_SW_RESET_CTRL);
DBGFS_DUMP(HQVDP_MBX_STARTUP_CTRL1);
if (readl(hqvdp->regs + HQVDP_MBX_STARTUP_CTRL1)
& STARTUP_CTRL1_RST_DONE)
seq_puts(s, "\tReset is done");
else
seq_puts(s, "\tReset is NOT done");
DBGFS_DUMP(HQVDP_MBX_STARTUP_CTRL2);
if (readl(hqvdp->regs + HQVDP_MBX_STARTUP_CTRL2)
& STARTUP_CTRL2_FETCH_EN)
seq_puts(s, "\tFetch is enabled");
else
seq_puts(s, "\tFetch is NOT enabled");
DBGFS_DUMP(HQVDP_MBX_GP_STATUS);
DBGFS_DUMP(HQVDP_MBX_NEXT_CMD);
DBGFS_DUMP(HQVDP_MBX_CURRENT_CMD);
DBGFS_DUMP(HQVDP_MBX_SOFT_VSYNC);
if (!(readl(hqvdp->regs + HQVDP_MBX_SOFT_VSYNC) & 3))
seq_puts(s, "\tHW Vsync");
else
seq_puts(s, "\tSW Vsync ?!?!");
cmd = readl(hqvdp->regs + HQVDP_MBX_CURRENT_CMD);
cmd_offset = sti_hqvdp_get_curr_cmd(hqvdp);
if (cmd_offset == -1) {
seq_puts(s, "\n\n Last command: unknown");
} else {
virt = hqvdp->hqvdp_cmd + cmd_offset;
seq_printf(s, "\n\n Last command: address @ 0x%x (0x%p)",
cmd, virt);
hqvdp_dbg_dump_cmd(s, (struct sti_hqvdp_cmd *)virt);
}
cmd = readl(hqvdp->regs + HQVDP_MBX_NEXT_CMD);
cmd_offset = sti_hqvdp_get_next_cmd(hqvdp);
if (cmd_offset == -1) {
seq_puts(s, "\n\n Next command: unknown");
} else {
virt = hqvdp->hqvdp_cmd + cmd_offset;
seq_printf(s, "\n\n Next command address: @ 0x%x (0x%p)",
cmd, virt);
hqvdp_dbg_dump_cmd(s, (struct sti_hqvdp_cmd *)virt);
}
seq_puts(s, "\n");
return 0;
}
static int hqvdp_debugfs_init(struct sti_hqvdp *hqvdp, struct drm_minor *minor)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(hqvdp_debugfs_files); i++)
hqvdp_debugfs_files[i].data = hqvdp;
return drm_debugfs_create_files(hqvdp_debugfs_files,
ARRAY_SIZE(hqvdp_debugfs_files),
minor->debugfs_root, minor);
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
DRM_DEBUG_DRIVER("Warning: no cmd, will skip field\n");
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
hqvdp->btm_field_pending = false;
dev_dbg(hqvdp->dev, "%s Posted command:0x%x\n",
__func__, hqvdp->hqvdp_cmd_paddr);
sti_plane_update_fps(&hqvdp->plane, false, true);
}
return 0;
}
static void sti_hqvdp_init(struct sti_hqvdp *hqvdp)
{
int size;
dma_addr_t dma_addr;
hqvdp->vtg_nb.notifier_call = sti_hqvdp_vtg_cb;
size = NB_VDP_CMD * sizeof(struct sti_hqvdp_cmd);
hqvdp->hqvdp_cmd = dma_alloc_wc(hqvdp->dev, size,
&dma_addr,
GFP_KERNEL | GFP_DMA);
if (!hqvdp->hqvdp_cmd) {
DRM_ERROR("Failed to allocate memory for VDP cmd\n");
return;
}
hqvdp->hqvdp_cmd_paddr = (u32)dma_addr;
memset(hqvdp->hqvdp_cmd, 0, size);
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
static void sti_hqvdp_start_xp70(struct sti_hqvdp *hqvdp)
{
const struct firmware *firmware;
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
DRM_DEBUG_DRIVER("HQVDP XP70 already initialized\n");
return;
}
if (request_firmware(&firmware, HQVDP_FMW_NAME, hqvdp->dev)) {
DRM_ERROR("Can't get HQVDP firmware\n");
return;
}
if (!firmware) {
DRM_ERROR("Firmware not available\n");
return;
}
header = (struct fw_header *)firmware->data;
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
data = (u8 *)firmware->data;
data += sizeof(*header);
fw_rd_plug = (void *)data;
data += header->rd_size;
fw_wr_plug = (void *)data;
data += header->wr_size;
fw_pmem = (void *)data;
data += header->pmem_size;
fw_dmem = (void *)data;
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
static int sti_hqvdp_atomic_check(struct drm_plane *drm_plane,
struct drm_plane_state *state)
{
struct sti_plane *plane = to_sti_plane(drm_plane);
struct sti_hqvdp *hqvdp = to_sti_hqvdp(plane);
struct drm_crtc *crtc = state->crtc;
struct drm_framebuffer *fb = state->fb;
bool first_prepare = plane->status == STI_PLANE_DISABLED ? true : false;
struct drm_crtc_state *crtc_state;
struct drm_display_mode *mode;
int dst_x, dst_y, dst_w, dst_h;
int src_x, src_y, src_w, src_h;
if (!crtc || !fb)
return 0;
crtc_state = drm_atomic_get_crtc_state(state->state, crtc);
mode = &crtc_state->mode;
dst_x = state->crtc_x;
dst_y = state->crtc_y;
dst_w = clamp_val(state->crtc_w, 0, mode->crtc_hdisplay - dst_x);
dst_h = clamp_val(state->crtc_h, 0, mode->crtc_vdisplay - dst_y);
src_x = state->src_x >> 16;
src_y = state->src_y >> 16;
src_w = state->src_w >> 16;
src_h = state->src_h >> 16;
if (!sti_hqvdp_check_hw_scaling(hqvdp, mode,
src_w, src_h,
dst_w, dst_h)) {
DRM_ERROR("Scaling beyond HW capabilities\n");
return -EINVAL;
}
if (!drm_fb_cma_get_gem_obj(fb, 0)) {
DRM_ERROR("Can't get CMA GEM object for fb\n");
return -EINVAL;
}
dst_w = ALIGN(dst_w, 2);
dst_h = ALIGN(dst_h, 2);
if ((src_w > MAX_WIDTH) || (src_w < MIN_WIDTH) ||
(src_h > MAX_HEIGHT) || (src_h < MIN_HEIGHT) ||
(dst_w > MAX_WIDTH) || (dst_w < MIN_WIDTH) ||
(dst_h > MAX_HEIGHT) || (dst_h < MIN_HEIGHT)) {
DRM_ERROR("Invalid in/out size %dx%d -> %dx%d\n",
src_w, src_h,
dst_w, dst_h);
return -EINVAL;
}
if (first_prepare) {
sti_hqvdp_start_xp70(hqvdp);
if (clk_prepare_enable(hqvdp->clk_pix_main)) {
DRM_ERROR("Failed to prepare/enable pix main clk\n");
return -EINVAL;
}
if (sti_vtg_register_client(hqvdp->vtg,
&hqvdp->vtg_nb,
crtc)) {
DRM_ERROR("Cannot register VTG notifier\n");
return -EINVAL;
}
}
DRM_DEBUG_KMS("CRTC:%d (%s) drm plane:%d (%s)\n",
crtc->base.id, sti_mixer_to_str(to_sti_mixer(crtc)),
drm_plane->base.id, sti_plane_to_str(plane));
DRM_DEBUG_KMS("%s dst=(%dx%d)@(%d,%d) - src=(%dx%d)@(%d,%d)\n",
sti_plane_to_str(plane),
dst_w, dst_h, dst_x, dst_y,
src_w, src_h, src_x, src_y);
return 0;
}
static void sti_hqvdp_atomic_update(struct drm_plane *drm_plane,
struct drm_plane_state *oldstate)
{
struct drm_plane_state *state = drm_plane->state;
struct sti_plane *plane = to_sti_plane(drm_plane);
struct sti_hqvdp *hqvdp = to_sti_hqvdp(plane);
struct drm_crtc *crtc = state->crtc;
struct drm_framebuffer *fb = state->fb;
struct drm_display_mode *mode;
int dst_x, dst_y, dst_w, dst_h;
int src_x, src_y, src_w, src_h;
struct drm_gem_cma_object *cma_obj;
struct sti_hqvdp_cmd *cmd;
int scale_h, scale_v;
int cmd_offset;
if (!crtc || !fb)
return;
mode = &crtc->mode;
dst_x = state->crtc_x;
dst_y = state->crtc_y;
dst_w = clamp_val(state->crtc_w, 0, mode->crtc_hdisplay - dst_x);
dst_h = clamp_val(state->crtc_h, 0, mode->crtc_vdisplay - dst_y);
src_x = state->src_x >> 16;
src_y = state->src_y >> 16;
src_w = state->src_w >> 16;
src_h = state->src_h >> 16;
cmd_offset = sti_hqvdp_get_free_cmd(hqvdp);
if (cmd_offset == -1) {
DRM_DEBUG_DRIVER("Warning: no cmd, will skip frame\n");
return;
}
cmd = hqvdp->hqvdp_cmd + cmd_offset;
cmd->top.config = TOP_CONFIG_PROGRESSIVE;
cmd->top.mem_format = TOP_MEM_FORMAT_DFLT;
cmd->hvsrc.param_ctrl = HVSRC_PARAM_CTRL_DFLT;
cmd->csdi.config = CSDI_CONFIG_PROG;
cmd->iqi.config = IQI_CONFIG_DFLT;
cmd->iqi.con_bri = IQI_CON_BRI_DFLT;
cmd->iqi.sat_gain = IQI_SAT_GAIN_DFLT;
cmd->iqi.pxf_conf = IQI_PXF_CONF_DFLT;
cma_obj = drm_fb_cma_get_gem_obj(fb, 0);
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
writel(hqvdp->hqvdp_cmd_paddr + cmd_offset,
hqvdp->regs + HQVDP_MBX_NEXT_CMD);
if (fb->flags & DRM_MODE_FB_INTERLACED)
hqvdp->btm_field_pending = true;
dev_dbg(hqvdp->dev, "%s Posted command:0x%x\n",
__func__, hqvdp->hqvdp_cmd_paddr + cmd_offset);
sti_plane_update_fps(plane, true, true);
plane->status = STI_PLANE_UPDATED;
}
static void sti_hqvdp_atomic_disable(struct drm_plane *drm_plane,
struct drm_plane_state *oldstate)
{
struct sti_plane *plane = to_sti_plane(drm_plane);
if (!drm_plane->crtc) {
DRM_DEBUG_DRIVER("drm plane:%d not enabled\n",
drm_plane->base.id);
return;
}
DRM_DEBUG_DRIVER("CRTC:%d (%s) drm plane:%d (%s)\n",
drm_plane->crtc->base.id,
sti_mixer_to_str(to_sti_mixer(drm_plane->crtc)),
drm_plane->base.id, sti_plane_to_str(plane));
plane->status = STI_PLANE_DISABLING;
}
static void sti_hqvdp_destroy(struct drm_plane *drm_plane)
{
DRM_DEBUG_DRIVER("\n");
drm_plane_helper_disable(drm_plane);
drm_plane_cleanup(drm_plane);
}
static int sti_hqvdp_late_register(struct drm_plane *drm_plane)
{
struct sti_plane *plane = to_sti_plane(drm_plane);
struct sti_hqvdp *hqvdp = to_sti_hqvdp(plane);
return hqvdp_debugfs_init(hqvdp, drm_plane->dev->primary);
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
&sti_hqvdp_plane_helpers_funcs,
hqvdp_supported_formats,
ARRAY_SIZE(hqvdp_supported_formats),
DRM_PLANE_TYPE_OVERLAY, NULL);
if (res) {
DRM_ERROR("Failed to initialize universal plane\n");
return NULL;
}
drm_plane_helper_add(&hqvdp->plane.drm_plane, &sti_hqvdp_helpers_funcs);
sti_plane_init_property(&hqvdp->plane, DRM_PLANE_TYPE_OVERLAY);
return &hqvdp->plane.drm_plane;
}
int sti_hqvdp_bind(struct device *dev, struct device *master, void *data)
{
struct sti_hqvdp *hqvdp = dev_get_drvdata(dev);
struct drm_device *drm_dev = data;
struct drm_plane *plane;
DRM_DEBUG_DRIVER("\n");
hqvdp->drm_dev = drm_dev;
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
of_node_put(vtg_np);
platform_set_drvdata(pdev, hqvdp);
return component_add(&pdev->dev, &sti_hqvdp_ops);
}
static int sti_hqvdp_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &sti_hqvdp_ops);
return 0;
}
