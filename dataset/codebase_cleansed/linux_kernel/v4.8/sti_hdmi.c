u32 hdmi_read(struct sti_hdmi *hdmi, int offset)
{
return readl(hdmi->regs + offset);
}
void hdmi_write(struct sti_hdmi *hdmi, u32 val, int offset)
{
writel(val, hdmi->regs + offset);
}
static irqreturn_t hdmi_irq_thread(int irq, void *arg)
{
struct sti_hdmi *hdmi = arg;
if (hdmi->irq_status & HDMI_INT_HOT_PLUG) {
hdmi->hpd = readl(hdmi->regs + HDMI_STA) & HDMI_STA_HOT_PLUG;
if (hdmi->drm_dev)
drm_helper_hpd_irq_event(hdmi->drm_dev);
}
if (hdmi->irq_status & (HDMI_INT_SW_RST | HDMI_INT_DLL_LCK)) {
hdmi->event_received = true;
wake_up_interruptible(&hdmi->wait_event);
}
if (hdmi->irq_status & HDMI_INT_AUDIO_FIFO_XRUN)
DRM_INFO("Warning: audio FIFO underrun occurs!");
return IRQ_HANDLED;
}
static irqreturn_t hdmi_irq(int irq, void *arg)
{
struct sti_hdmi *hdmi = arg;
hdmi->irq_status = hdmi_read(hdmi, HDMI_INT_STA);
hdmi_write(hdmi, hdmi->irq_status, HDMI_INT_CLR);
hdmi_read(hdmi, HDMI_INT_STA);
return IRQ_WAKE_THREAD;
}
static void hdmi_active_area(struct sti_hdmi *hdmi)
{
u32 xmin, xmax;
u32 ymin, ymax;
xmin = sti_vtg_get_pixel_number(hdmi->mode, 1);
xmax = sti_vtg_get_pixel_number(hdmi->mode, hdmi->mode.hdisplay);
ymin = sti_vtg_get_line_number(hdmi->mode, 0);
ymax = sti_vtg_get_line_number(hdmi->mode, hdmi->mode.vdisplay - 1);
hdmi_write(hdmi, xmin, HDMI_ACTIVE_VID_XMIN);
hdmi_write(hdmi, xmax, HDMI_ACTIVE_VID_XMAX);
hdmi_write(hdmi, ymin, HDMI_ACTIVE_VID_YMIN);
hdmi_write(hdmi, ymax, HDMI_ACTIVE_VID_YMAX);
}
static void hdmi_config(struct sti_hdmi *hdmi)
{
u32 conf;
DRM_DEBUG_DRIVER("\n");
conf = HDMI_CFG_FIFO_OVERRUN_CLR | HDMI_CFG_FIFO_UNDERRUN_CLR;
conf |= HDMI_CFG_ESS_NOT_OESS;
if (hdmi->hdmi_mode == HDMI_MODE_HDMI)
conf |= HDMI_CFG_HDMI_NOT_DVI;
conf |= HDMI_CFG_SINK_TERM_DET_EN;
if (hdmi->mode.flags & DRM_MODE_FLAG_NHSYNC) {
DRM_DEBUG_DRIVER("H Sync Negative\n");
conf |= HDMI_CFG_H_SYNC_POL_NEG;
}
if (hdmi->mode.flags & DRM_MODE_FLAG_NVSYNC) {
DRM_DEBUG_DRIVER("V Sync Negative\n");
conf |= HDMI_CFG_V_SYNC_POL_NEG;
}
conf |= HDMI_CFG_DEVICE_EN;
hdmi_write(hdmi, conf, HDMI_CFG);
}
static void hdmi_infoframe_reset(struct sti_hdmi *hdmi,
u32 slot)
{
u32 val, i;
u32 head_offset, pack_offset;
switch (slot) {
case HDMI_IFRAME_SLOT_AVI:
head_offset = HDMI_SW_DI_N_HEAD_WORD(HDMI_IFRAME_SLOT_AVI);
pack_offset = HDMI_SW_DI_N_PKT_WORD0(HDMI_IFRAME_SLOT_AVI);
break;
case HDMI_IFRAME_SLOT_AUDIO:
head_offset = HDMI_SW_DI_N_HEAD_WORD(HDMI_IFRAME_SLOT_AUDIO);
pack_offset = HDMI_SW_DI_N_PKT_WORD0(HDMI_IFRAME_SLOT_AUDIO);
break;
case HDMI_IFRAME_SLOT_VENDOR:
head_offset = HDMI_SW_DI_N_HEAD_WORD(HDMI_IFRAME_SLOT_VENDOR);
pack_offset = HDMI_SW_DI_N_PKT_WORD0(HDMI_IFRAME_SLOT_VENDOR);
break;
default:
DRM_ERROR("unsupported infoframe slot: %#x\n", slot);
return;
}
val = hdmi_read(hdmi, HDMI_SW_DI_CFG);
val &= ~HDMI_IFRAME_CFG_DI_N(HDMI_IFRAME_MASK, slot);
hdmi_write(hdmi, val, HDMI_SW_DI_CFG);
hdmi_write(hdmi, 0x0, head_offset);
for (i = 0; i < HDMI_SW_DI_MAX_WORD; i += sizeof(u32))
hdmi_write(hdmi, 0x0, pack_offset + i);
}
static inline unsigned int hdmi_infoframe_subpack(const u8 *ptr, size_t size)
{
unsigned long value = 0;
size_t i;
for (i = size; i > 0; i--)
value = (value << 8) | ptr[i - 1];
return value;
}
static void hdmi_infoframe_write_infopack(struct sti_hdmi *hdmi,
const u8 *data,
size_t size)
{
const u8 *ptr = data;
u32 val, slot, mode, i;
u32 head_offset, pack_offset;
switch (*ptr) {
case HDMI_INFOFRAME_TYPE_AVI:
slot = HDMI_IFRAME_SLOT_AVI;
mode = HDMI_IFRAME_FIELD;
head_offset = HDMI_SW_DI_N_HEAD_WORD(HDMI_IFRAME_SLOT_AVI);
pack_offset = HDMI_SW_DI_N_PKT_WORD0(HDMI_IFRAME_SLOT_AVI);
break;
case HDMI_INFOFRAME_TYPE_AUDIO:
slot = HDMI_IFRAME_SLOT_AUDIO;
mode = HDMI_IFRAME_FRAME;
head_offset = HDMI_SW_DI_N_HEAD_WORD(HDMI_IFRAME_SLOT_AUDIO);
pack_offset = HDMI_SW_DI_N_PKT_WORD0(HDMI_IFRAME_SLOT_AUDIO);
break;
case HDMI_INFOFRAME_TYPE_VENDOR:
slot = HDMI_IFRAME_SLOT_VENDOR;
mode = HDMI_IFRAME_FRAME;
head_offset = HDMI_SW_DI_N_HEAD_WORD(HDMI_IFRAME_SLOT_VENDOR);
pack_offset = HDMI_SW_DI_N_PKT_WORD0(HDMI_IFRAME_SLOT_VENDOR);
break;
default:
DRM_ERROR("unsupported infoframe type: %#x\n", *ptr);
return;
}
val = hdmi_read(hdmi, HDMI_SW_DI_CFG);
val &= ~HDMI_IFRAME_CFG_DI_N(HDMI_IFRAME_MASK, slot);
hdmi_write(hdmi, val, HDMI_SW_DI_CFG);
val = HDMI_INFOFRAME_HEADER_TYPE(*ptr++);
val |= HDMI_INFOFRAME_HEADER_VERSION(*ptr++);
val |= HDMI_INFOFRAME_HEADER_LEN(*ptr++);
writel(val, hdmi->regs + head_offset);
size = size - HDMI_INFOFRAME_HEADER_SIZE + 1;
for (i = 0; i < size; i += sizeof(u32)) {
size_t num;
num = min_t(size_t, size - i, sizeof(u32));
val = hdmi_infoframe_subpack(ptr, num);
ptr += sizeof(u32);
writel(val, hdmi->regs + pack_offset + i);
}
val = hdmi_read(hdmi, HDMI_SW_DI_CFG);
val |= HDMI_IFRAME_CFG_DI_N(mode, slot);
hdmi_write(hdmi, val, HDMI_SW_DI_CFG);
}
static int hdmi_avi_infoframe_config(struct sti_hdmi *hdmi)
{
struct drm_display_mode *mode = &hdmi->mode;
struct hdmi_avi_infoframe infoframe;
u8 buffer[HDMI_INFOFRAME_SIZE(AVI)];
int ret;
DRM_DEBUG_DRIVER("\n");
ret = drm_hdmi_avi_infoframe_from_display_mode(&infoframe, mode);
if (ret < 0) {
DRM_ERROR("failed to setup AVI infoframe: %d\n", ret);
return ret;
}
infoframe.colorspace = hdmi->colorspace;
infoframe.quantization_range = HDMI_QUANTIZATION_RANGE_DEFAULT;
infoframe.colorimetry = HDMI_COLORIMETRY_NONE;
ret = hdmi_avi_infoframe_pack(&infoframe, buffer, sizeof(buffer));
if (ret < 0) {
DRM_ERROR("failed to pack AVI infoframe: %d\n", ret);
return ret;
}
hdmi_infoframe_write_infopack(hdmi, buffer, ret);
return 0;
}
static int hdmi_audio_infoframe_config(struct sti_hdmi *hdmi)
{
struct hdmi_audio_params *audio = &hdmi->audio;
u8 buffer[HDMI_INFOFRAME_SIZE(AUDIO)];
int ret, val;
DRM_DEBUG_DRIVER("enter %s, AIF %s\n", __func__,
audio->enabled ? "enable" : "disable");
if (audio->enabled) {
ret = hdmi_audio_infoframe_pack(&audio->cea, buffer,
sizeof(buffer));
if (ret < 0) {
DRM_ERROR("failed to pack audio infoframe: %d\n", ret);
return ret;
}
hdmi_infoframe_write_infopack(hdmi, buffer, ret);
} else {
val = hdmi_read(hdmi, HDMI_SW_DI_CFG);
val &= ~HDMI_IFRAME_CFG_DI_N(HDMI_IFRAME_MASK,
HDMI_IFRAME_SLOT_AUDIO);
hdmi_write(hdmi, val, HDMI_SW_DI_CFG);
}
return 0;
}
static int hdmi_vendor_infoframe_config(struct sti_hdmi *hdmi)
{
struct drm_display_mode *mode = &hdmi->mode;
struct hdmi_vendor_infoframe infoframe;
u8 buffer[HDMI_INFOFRAME_HEADER_SIZE + HDMI_VENDOR_INFOFRAME_MAX_SIZE];
int ret;
DRM_DEBUG_DRIVER("\n");
ret = drm_hdmi_vendor_infoframe_from_display_mode(&infoframe, mode);
if (ret < 0) {
return 0;
}
ret = hdmi_vendor_infoframe_pack(&infoframe, buffer, sizeof(buffer));
if (ret < 0) {
DRM_ERROR("failed to pack VS infoframe: %d\n", ret);
return ret;
}
hdmi_infoframe_write_infopack(hdmi, buffer, ret);
return 0;
}
static void hdmi_swreset(struct sti_hdmi *hdmi)
{
u32 val;
DRM_DEBUG_DRIVER("\n");
if (clk_prepare_enable(hdmi->clk_audio))
DRM_INFO("Failed to prepare/enable hdmi_audio clk\n");
hdmi->event_received = false;
val = hdmi_read(hdmi, HDMI_CFG);
val |= HDMI_CFG_SW_RST_EN;
hdmi_write(hdmi, val, HDMI_CFG);
wait_event_interruptible_timeout(hdmi->wait_event,
hdmi->event_received == true,
msecs_to_jiffies
(HDMI_TIMEOUT_SWRESET));
if ((hdmi_read(hdmi, HDMI_STA) & HDMI_STA_SW_RST) == 0)
DRM_DEBUG_DRIVER("Warning: HDMI sw reset timeout occurs\n");
val = hdmi_read(hdmi, HDMI_CFG);
val &= ~HDMI_CFG_SW_RST_EN;
hdmi_write(hdmi, val, HDMI_CFG);
clk_disable_unprepare(hdmi->clk_audio);
}
static void hdmi_dbg_cfg(struct seq_file *s, int val)
{
int tmp;
seq_puts(s, "\t");
tmp = val & HDMI_CFG_HDMI_NOT_DVI;
DBGFS_PRINT_STR("mode:", tmp ? "HDMI" : "DVI");
seq_puts(s, "\t\t\t\t\t");
tmp = val & HDMI_CFG_HDCP_EN;
DBGFS_PRINT_STR("HDCP:", tmp ? "enable" : "disable");
seq_puts(s, "\t\t\t\t\t");
tmp = val & HDMI_CFG_ESS_NOT_OESS;
DBGFS_PRINT_STR("HDCP mode:", tmp ? "ESS enable" : "OESS enable");
seq_puts(s, "\t\t\t\t\t");
tmp = val & HDMI_CFG_SINK_TERM_DET_EN;
DBGFS_PRINT_STR("Sink term detection:", tmp ? "enable" : "disable");
seq_puts(s, "\t\t\t\t\t");
tmp = val & HDMI_CFG_H_SYNC_POL_NEG;
DBGFS_PRINT_STR("Hsync polarity:", tmp ? "inverted" : "normal");
seq_puts(s, "\t\t\t\t\t");
tmp = val & HDMI_CFG_V_SYNC_POL_NEG;
DBGFS_PRINT_STR("Vsync polarity:", tmp ? "inverted" : "normal");
seq_puts(s, "\t\t\t\t\t");
tmp = val & HDMI_CFG_422_EN;
DBGFS_PRINT_STR("YUV422 format:", tmp ? "enable" : "disable");
}
static void hdmi_dbg_sta(struct seq_file *s, int val)
{
int tmp;
seq_puts(s, "\t");
tmp = (val & HDMI_STA_DLL_LCK);
DBGFS_PRINT_STR("pll:", tmp ? "locked" : "not locked");
seq_puts(s, "\t\t\t\t\t");
tmp = (val & HDMI_STA_HOT_PLUG);
DBGFS_PRINT_STR("hdmi cable:", tmp ? "connected" : "not connected");
}
static void hdmi_dbg_sw_di_cfg(struct seq_file *s, int val)
{
int tmp;
char *const en_di[] = {"no transmission",
"single transmission",
"once every field",
"once every frame"};
seq_puts(s, "\t");
tmp = (val & HDMI_IFRAME_CFG_DI_N(HDMI_IFRAME_MASK, 1));
DBGFS_PRINT_STR("Data island 1:", en_di[tmp]);
seq_puts(s, "\t\t\t\t\t");
tmp = (val & HDMI_IFRAME_CFG_DI_N(HDMI_IFRAME_MASK, 2)) >> 4;
DBGFS_PRINT_STR("Data island 2:", en_di[tmp]);
seq_puts(s, "\t\t\t\t\t");
tmp = (val & HDMI_IFRAME_CFG_DI_N(HDMI_IFRAME_MASK, 3)) >> 8;
DBGFS_PRINT_STR("Data island 3:", en_di[tmp]);
seq_puts(s, "\t\t\t\t\t");
tmp = (val & HDMI_IFRAME_CFG_DI_N(HDMI_IFRAME_MASK, 4)) >> 12;
DBGFS_PRINT_STR("Data island 4:", en_di[tmp]);
seq_puts(s, "\t\t\t\t\t");
tmp = (val & HDMI_IFRAME_CFG_DI_N(HDMI_IFRAME_MASK, 5)) >> 16;
DBGFS_PRINT_STR("Data island 5:", en_di[tmp]);
seq_puts(s, "\t\t\t\t\t");
tmp = (val & HDMI_IFRAME_CFG_DI_N(HDMI_IFRAME_MASK, 6)) >> 20;
DBGFS_PRINT_STR("Data island 6:", en_di[tmp]);
}
static int hdmi_dbg_show(struct seq_file *s, void *data)
{
struct drm_info_node *node = s->private;
struct sti_hdmi *hdmi = (struct sti_hdmi *)node->info_ent->data;
seq_printf(s, "HDMI: (vaddr = 0x%p)", hdmi->regs);
DBGFS_DUMP("\n", HDMI_CFG);
hdmi_dbg_cfg(s, hdmi_read(hdmi, HDMI_CFG));
DBGFS_DUMP("", HDMI_INT_EN);
DBGFS_DUMP("\n", HDMI_STA);
hdmi_dbg_sta(s, hdmi_read(hdmi, HDMI_STA));
DBGFS_DUMP("", HDMI_ACTIVE_VID_XMIN);
seq_puts(s, "\t");
DBGFS_PRINT_INT("Xmin:", hdmi_read(hdmi, HDMI_ACTIVE_VID_XMIN));
DBGFS_DUMP("", HDMI_ACTIVE_VID_XMAX);
seq_puts(s, "\t");
DBGFS_PRINT_INT("Xmax:", hdmi_read(hdmi, HDMI_ACTIVE_VID_XMAX));
DBGFS_DUMP("", HDMI_ACTIVE_VID_YMIN);
seq_puts(s, "\t");
DBGFS_PRINT_INT("Ymin:", hdmi_read(hdmi, HDMI_ACTIVE_VID_YMIN));
DBGFS_DUMP("", HDMI_ACTIVE_VID_YMAX);
seq_puts(s, "\t");
DBGFS_PRINT_INT("Ymax:", hdmi_read(hdmi, HDMI_ACTIVE_VID_YMAX));
DBGFS_DUMP("", HDMI_SW_DI_CFG);
hdmi_dbg_sw_di_cfg(s, hdmi_read(hdmi, HDMI_SW_DI_CFG));
DBGFS_DUMP("\n", HDMI_AUDIO_CFG);
DBGFS_DUMP("\n", HDMI_SPDIF_FIFO_STATUS);
DBGFS_DUMP("\n", HDMI_AUDN);
seq_printf(s, "\n AVI Infoframe (Data Island slot N=%d):",
HDMI_IFRAME_SLOT_AVI);
DBGFS_DUMP_DI(HDMI_SW_DI_N_HEAD_WORD, HDMI_IFRAME_SLOT_AVI);
DBGFS_DUMP_DI(HDMI_SW_DI_N_PKT_WORD0, HDMI_IFRAME_SLOT_AVI);
DBGFS_DUMP_DI(HDMI_SW_DI_N_PKT_WORD1, HDMI_IFRAME_SLOT_AVI);
DBGFS_DUMP_DI(HDMI_SW_DI_N_PKT_WORD2, HDMI_IFRAME_SLOT_AVI);
DBGFS_DUMP_DI(HDMI_SW_DI_N_PKT_WORD3, HDMI_IFRAME_SLOT_AVI);
DBGFS_DUMP_DI(HDMI_SW_DI_N_PKT_WORD4, HDMI_IFRAME_SLOT_AVI);
DBGFS_DUMP_DI(HDMI_SW_DI_N_PKT_WORD5, HDMI_IFRAME_SLOT_AVI);
DBGFS_DUMP_DI(HDMI_SW_DI_N_PKT_WORD6, HDMI_IFRAME_SLOT_AVI);
seq_puts(s, "\n");
seq_printf(s, "\n AUDIO Infoframe (Data Island slot N=%d):",
HDMI_IFRAME_SLOT_AUDIO);
DBGFS_DUMP_DI(HDMI_SW_DI_N_HEAD_WORD, HDMI_IFRAME_SLOT_AUDIO);
DBGFS_DUMP_DI(HDMI_SW_DI_N_PKT_WORD0, HDMI_IFRAME_SLOT_AUDIO);
DBGFS_DUMP_DI(HDMI_SW_DI_N_PKT_WORD1, HDMI_IFRAME_SLOT_AUDIO);
DBGFS_DUMP_DI(HDMI_SW_DI_N_PKT_WORD2, HDMI_IFRAME_SLOT_AUDIO);
DBGFS_DUMP_DI(HDMI_SW_DI_N_PKT_WORD3, HDMI_IFRAME_SLOT_AUDIO);
DBGFS_DUMP_DI(HDMI_SW_DI_N_PKT_WORD4, HDMI_IFRAME_SLOT_AUDIO);
DBGFS_DUMP_DI(HDMI_SW_DI_N_PKT_WORD5, HDMI_IFRAME_SLOT_AUDIO);
DBGFS_DUMP_DI(HDMI_SW_DI_N_PKT_WORD6, HDMI_IFRAME_SLOT_AUDIO);
seq_puts(s, "\n");
seq_printf(s, "\n VENDOR SPECIFIC Infoframe (Data Island slot N=%d):",
HDMI_IFRAME_SLOT_VENDOR);
DBGFS_DUMP_DI(HDMI_SW_DI_N_HEAD_WORD, HDMI_IFRAME_SLOT_VENDOR);
DBGFS_DUMP_DI(HDMI_SW_DI_N_PKT_WORD0, HDMI_IFRAME_SLOT_VENDOR);
DBGFS_DUMP_DI(HDMI_SW_DI_N_PKT_WORD1, HDMI_IFRAME_SLOT_VENDOR);
DBGFS_DUMP_DI(HDMI_SW_DI_N_PKT_WORD2, HDMI_IFRAME_SLOT_VENDOR);
DBGFS_DUMP_DI(HDMI_SW_DI_N_PKT_WORD3, HDMI_IFRAME_SLOT_VENDOR);
DBGFS_DUMP_DI(HDMI_SW_DI_N_PKT_WORD4, HDMI_IFRAME_SLOT_VENDOR);
DBGFS_DUMP_DI(HDMI_SW_DI_N_PKT_WORD5, HDMI_IFRAME_SLOT_VENDOR);
DBGFS_DUMP_DI(HDMI_SW_DI_N_PKT_WORD6, HDMI_IFRAME_SLOT_VENDOR);
seq_puts(s, "\n");
return 0;
}
static void hdmi_debugfs_exit(struct sti_hdmi *hdmi, struct drm_minor *minor)
{
drm_debugfs_remove_files(hdmi_debugfs_files,
ARRAY_SIZE(hdmi_debugfs_files),
minor);
}
static int hdmi_debugfs_init(struct sti_hdmi *hdmi, struct drm_minor *minor)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(hdmi_debugfs_files); i++)
hdmi_debugfs_files[i].data = hdmi;
return drm_debugfs_create_files(hdmi_debugfs_files,
ARRAY_SIZE(hdmi_debugfs_files),
minor->debugfs_root, minor);
}
static void sti_hdmi_disable(struct drm_bridge *bridge)
{
struct sti_hdmi *hdmi = bridge->driver_private;
u32 val = hdmi_read(hdmi, HDMI_CFG);
if (!hdmi->enabled)
return;
DRM_DEBUG_DRIVER("\n");
val &= ~HDMI_CFG_DEVICE_EN;
hdmi_write(hdmi, val, HDMI_CFG);
hdmi_write(hdmi, 0xffffffff, HDMI_INT_CLR);
hdmi->phy_ops->stop(hdmi);
hdmi_infoframe_reset(hdmi, HDMI_IFRAME_SLOT_AVI);
hdmi_infoframe_reset(hdmi, HDMI_IFRAME_SLOT_AUDIO);
hdmi_infoframe_reset(hdmi, HDMI_IFRAME_SLOT_VENDOR);
hdmi_write(hdmi, 0x0000, HDMI_DFLT_CHL0_DAT);
hdmi_write(hdmi, 0x0000, HDMI_DFLT_CHL1_DAT);
hdmi_write(hdmi, 0x0060, HDMI_DFLT_CHL2_DAT);
clk_disable_unprepare(hdmi->clk_phy);
clk_disable_unprepare(hdmi->clk_tmds);
clk_disable_unprepare(hdmi->clk_pix);
hdmi->enabled = false;
}
static void sti_hdmi_pre_enable(struct drm_bridge *bridge)
{
struct sti_hdmi *hdmi = bridge->driver_private;
DRM_DEBUG_DRIVER("\n");
if (hdmi->enabled)
return;
if (clk_prepare_enable(hdmi->clk_pix))
DRM_ERROR("Failed to prepare/enable hdmi_pix clk\n");
if (clk_prepare_enable(hdmi->clk_tmds))
DRM_ERROR("Failed to prepare/enable hdmi_tmds clk\n");
if (clk_prepare_enable(hdmi->clk_phy))
DRM_ERROR("Failed to prepare/enable hdmi_rejec_pll clk\n");
hdmi->enabled = true;
if (!hdmi->phy_ops->start(hdmi)) {
DRM_ERROR("Unable to start hdmi phy\n");
return;
}
hdmi_active_area(hdmi);
hdmi_write(hdmi, HDMI_WORKING_INT, HDMI_INT_EN);
hdmi_config(hdmi);
if (hdmi_avi_infoframe_config(hdmi))
DRM_ERROR("Unable to configure AVI infoframe\n");
if (hdmi_audio_infoframe_config(hdmi))
DRM_ERROR("Unable to configure AUDIO infoframe\n");
if (hdmi_vendor_infoframe_config(hdmi))
DRM_ERROR("Unable to configure VS infoframe\n");
hdmi_swreset(hdmi);
}
static void sti_hdmi_set_mode(struct drm_bridge *bridge,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct sti_hdmi *hdmi = bridge->driver_private;
int ret;
DRM_DEBUG_DRIVER("\n");
memcpy(&hdmi->mode, mode, sizeof(struct drm_display_mode));
ret = clk_set_rate(hdmi->clk_pix, mode->clock * 1000);
if (ret < 0) {
DRM_ERROR("Cannot set rate (%dHz) for hdmi_pix clk\n",
mode->clock * 1000);
return;
}
ret = clk_set_rate(hdmi->clk_phy, mode->clock * 1000);
if (ret < 0) {
DRM_ERROR("Cannot set rate (%dHz) for hdmi_rejection_pll clk\n",
mode->clock * 1000);
return;
}
}
static void sti_hdmi_bridge_nope(struct drm_bridge *bridge)
{
}
static int sti_hdmi_connector_get_modes(struct drm_connector *connector)
{
struct sti_hdmi_connector *hdmi_connector
= to_sti_hdmi_connector(connector);
struct sti_hdmi *hdmi = hdmi_connector->hdmi;
struct edid *edid;
int count;
DRM_DEBUG_DRIVER("\n");
edid = drm_get_edid(connector, hdmi->ddc_adapt);
if (!edid)
goto fail;
count = drm_add_edid_modes(connector, edid);
drm_mode_connector_update_edid_property(connector, edid);
drm_edid_to_eld(connector, edid);
kfree(edid);
return count;
fail:
DRM_ERROR("Can't read HDMI EDID\n");
return 0;
}
static int sti_hdmi_connector_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
int target = mode->clock * 1000;
int target_min = target - CLK_TOLERANCE_HZ;
int target_max = target + CLK_TOLERANCE_HZ;
int result;
struct sti_hdmi_connector *hdmi_connector
= to_sti_hdmi_connector(connector);
struct sti_hdmi *hdmi = hdmi_connector->hdmi;
result = clk_round_rate(hdmi->clk_pix, target);
DRM_DEBUG_DRIVER("target rate = %d => available rate = %d\n",
target, result);
if ((result < target_min) || (result > target_max)) {
DRM_DEBUG_DRIVER("hdmi pixclk=%d not supported\n", target);
return MODE_BAD;
}
return MODE_OK;
}
static enum drm_connector_status
sti_hdmi_connector_detect(struct drm_connector *connector, bool force)
{
struct sti_hdmi_connector *hdmi_connector
= to_sti_hdmi_connector(connector);
struct sti_hdmi *hdmi = hdmi_connector->hdmi;
DRM_DEBUG_DRIVER("\n");
if (hdmi->hpd) {
DRM_DEBUG_DRIVER("hdmi cable connected\n");
return connector_status_connected;
}
DRM_DEBUG_DRIVER("hdmi cable disconnected\n");
return connector_status_disconnected;
}
static void sti_hdmi_connector_init_property(struct drm_device *drm_dev,
struct drm_connector *connector)
{
struct sti_hdmi_connector *hdmi_connector
= to_sti_hdmi_connector(connector);
struct sti_hdmi *hdmi = hdmi_connector->hdmi;
struct drm_property *prop;
hdmi->colorspace = DEFAULT_COLORSPACE_MODE;
prop = drm_property_create_enum(drm_dev, 0, "colorspace",
colorspace_mode_names,
ARRAY_SIZE(colorspace_mode_names));
if (!prop) {
DRM_ERROR("fails to create colorspace property\n");
return;
}
hdmi_connector->colorspace_property = prop;
drm_object_attach_property(&connector->base, prop, hdmi->colorspace);
hdmi->hdmi_mode = DEFAULT_HDMI_MODE;
prop = drm_property_create_enum(drm_dev, 0, "hdmi_mode",
hdmi_mode_names,
ARRAY_SIZE(hdmi_mode_names));
if (!prop) {
DRM_ERROR("fails to create colorspace property\n");
return;
}
hdmi_connector->hdmi_mode_property = prop;
drm_object_attach_property(&connector->base, prop, hdmi->hdmi_mode);
}
static int
sti_hdmi_connector_set_property(struct drm_connector *connector,
struct drm_connector_state *state,
struct drm_property *property,
uint64_t val)
{
struct sti_hdmi_connector *hdmi_connector
= to_sti_hdmi_connector(connector);
struct sti_hdmi *hdmi = hdmi_connector->hdmi;
if (property == hdmi_connector->colorspace_property) {
hdmi->colorspace = val;
return 0;
}
if (property == hdmi_connector->hdmi_mode_property) {
hdmi->hdmi_mode = val;
return 0;
}
DRM_ERROR("failed to set hdmi connector property\n");
return -EINVAL;
}
static int
sti_hdmi_connector_get_property(struct drm_connector *connector,
const struct drm_connector_state *state,
struct drm_property *property,
uint64_t *val)
{
struct sti_hdmi_connector *hdmi_connector
= to_sti_hdmi_connector(connector);
struct sti_hdmi *hdmi = hdmi_connector->hdmi;
if (property == hdmi_connector->colorspace_property) {
*val = hdmi->colorspace;
return 0;
}
if (property == hdmi_connector->hdmi_mode_property) {
*val = hdmi->hdmi_mode;
return 0;
}
DRM_ERROR("failed to get hdmi connector property\n");
return -EINVAL;
}
static int sti_hdmi_late_register(struct drm_connector *connector)
{
struct sti_hdmi_connector *hdmi_connector
= to_sti_hdmi_connector(connector);
struct sti_hdmi *hdmi = hdmi_connector->hdmi;
if (hdmi_debugfs_init(hdmi, hdmi->drm_dev->primary)) {
DRM_ERROR("HDMI debugfs setup failed\n");
return -EINVAL;
}
return 0;
}
static struct drm_encoder *sti_hdmi_find_encoder(struct drm_device *dev)
{
struct drm_encoder *encoder;
list_for_each_entry(encoder, &dev->mode_config.encoder_list, head) {
if (encoder->encoder_type == DRM_MODE_ENCODER_TMDS)
return encoder;
}
return NULL;
}
static int sti_hdmi_audio_get_non_coherent_n(unsigned int audio_fs)
{
unsigned int n;
switch (audio_fs) {
case 32000:
n = 4096;
break;
case 44100:
n = 6272;
break;
case 48000:
n = 6144;
break;
case 88200:
n = 6272 * 2;
break;
case 96000:
n = 6144 * 2;
break;
case 176400:
n = 6272 * 4;
break;
case 192000:
n = 6144 * 4;
break;
default:
n = (audio_fs * 128) / 1000;
}
return n;
}
static int hdmi_audio_configure(struct sti_hdmi *hdmi,
struct hdmi_audio_params *params)
{
int audio_cfg, n;
struct hdmi_audio_infoframe *info = &params->cea;
DRM_DEBUG_DRIVER("\n");
if (!hdmi->enabled)
return 0;
n = sti_hdmi_audio_get_non_coherent_n(params->sample_rate);
DRM_DEBUG_DRIVER("Audio rate = %d Hz, TMDS clock = %d Hz, n = %d\n",
params->sample_rate, hdmi->mode.clock * 1000, n);
hdmi_write(hdmi, n, HDMI_AUDN);
audio_cfg = HDMI_AUD_CFG_SPDIF_DIV_2 | HDMI_AUD_CFG_DTS_INVALID |
HDMI_AUD_CFG_ONE_BIT_INVALID;
switch (info->channels) {
case 8:
audio_cfg |= HDMI_AUD_CFG_CH78_VALID;
case 6:
audio_cfg |= HDMI_AUD_CFG_CH56_VALID;
case 4:
audio_cfg |= HDMI_AUD_CFG_CH34_VALID | HDMI_AUD_CFG_8CH;
case 2:
audio_cfg |= HDMI_AUD_CFG_CH12_VALID;
break;
default:
DRM_ERROR("ERROR: Unsupported number of channels (%d)!\n",
info->channels);
return -EINVAL;
}
hdmi_write(hdmi, audio_cfg, HDMI_AUDIO_CFG);
hdmi->audio = *params;
return hdmi_audio_infoframe_config(hdmi);
}
static void hdmi_audio_shutdown(struct device *dev, void *data)
{
struct sti_hdmi *hdmi = dev_get_drvdata(dev);
int audio_cfg;
DRM_DEBUG_DRIVER("\n");
audio_cfg = HDMI_AUD_CFG_SPDIF_DIV_2 | HDMI_AUD_CFG_DTS_INVALID |
HDMI_AUD_CFG_ONE_BIT_INVALID;
hdmi_write(hdmi, audio_cfg, HDMI_AUDIO_CFG);
hdmi->audio.enabled = 0;
hdmi_audio_infoframe_config(hdmi);
}
static int hdmi_audio_hw_params(struct device *dev,
void *data,
struct hdmi_codec_daifmt *daifmt,
struct hdmi_codec_params *params)
{
struct sti_hdmi *hdmi = dev_get_drvdata(dev);
int ret;
struct hdmi_audio_params audio = {
.sample_width = params->sample_width,
.sample_rate = params->sample_rate,
.cea = params->cea,
};
DRM_DEBUG_DRIVER("\n");
if (!hdmi->enabled)
return 0;
if ((daifmt->fmt != HDMI_I2S) || daifmt->bit_clk_inv ||
daifmt->frame_clk_inv || daifmt->bit_clk_master ||
daifmt->frame_clk_master) {
dev_err(dev, "%s: Bad flags %d %d %d %d\n", __func__,
daifmt->bit_clk_inv, daifmt->frame_clk_inv,
daifmt->bit_clk_master,
daifmt->frame_clk_master);
return -EINVAL;
}
audio.enabled = 1;
ret = hdmi_audio_configure(hdmi, &audio);
if (ret < 0)
return ret;
return 0;
}
static int hdmi_audio_digital_mute(struct device *dev, void *data, bool enable)
{
struct sti_hdmi *hdmi = dev_get_drvdata(dev);
DRM_DEBUG_DRIVER("%s\n", enable ? "enable" : "disable");
if (enable)
hdmi_write(hdmi, HDMI_SAMPLE_FLAT_ALL, HDMI_SAMPLE_FLAT_MASK);
else
hdmi_write(hdmi, HDMI_SAMPLE_FLAT_NO, HDMI_SAMPLE_FLAT_MASK);
return 0;
}
static int hdmi_audio_get_eld(struct device *dev, void *data, uint8_t *buf, size_t len)
{
struct sti_hdmi *hdmi = dev_get_drvdata(dev);
struct drm_connector *connector = hdmi->drm_connector;
DRM_DEBUG_DRIVER("\n");
memcpy(buf, connector->eld, min(sizeof(connector->eld), len));
return 0;
}
static int sti_hdmi_register_audio_driver(struct device *dev,
struct sti_hdmi *hdmi)
{
struct hdmi_codec_pdata codec_data = {
.ops = &audio_codec_ops,
.max_i2s_channels = 8,
.i2s = 1,
};
DRM_DEBUG_DRIVER("\n");
hdmi->audio.enabled = 0;
hdmi->audio_pdev = platform_device_register_data(
dev, HDMI_CODEC_DRV_NAME, PLATFORM_DEVID_AUTO,
&codec_data, sizeof(codec_data));
if (IS_ERR(hdmi->audio_pdev))
return PTR_ERR(hdmi->audio_pdev);
DRM_INFO("%s Driver bound %s\n", HDMI_CODEC_DRV_NAME, dev_name(dev));
return 0;
}
static int sti_hdmi_bind(struct device *dev, struct device *master, void *data)
{
struct sti_hdmi *hdmi = dev_get_drvdata(dev);
struct drm_device *drm_dev = data;
struct drm_encoder *encoder;
struct sti_hdmi_connector *connector;
struct drm_connector *drm_connector;
struct drm_bridge *bridge;
int err;
hdmi->drm_dev = drm_dev;
encoder = sti_hdmi_find_encoder(drm_dev);
if (!encoder)
return -EINVAL;
connector = devm_kzalloc(dev, sizeof(*connector), GFP_KERNEL);
if (!connector)
return -EINVAL;
connector->hdmi = hdmi;
bridge = devm_kzalloc(dev, sizeof(*bridge), GFP_KERNEL);
if (!bridge)
return -EINVAL;
bridge->driver_private = hdmi;
bridge->funcs = &sti_hdmi_bridge_funcs;
drm_bridge_attach(drm_dev, bridge);
encoder->bridge = bridge;
connector->encoder = encoder;
drm_connector = (struct drm_connector *)connector;
drm_connector->polled = DRM_CONNECTOR_POLL_HPD;
drm_connector_init(drm_dev, drm_connector,
&sti_hdmi_connector_funcs, DRM_MODE_CONNECTOR_HDMIA);
drm_connector_helper_add(drm_connector,
&sti_hdmi_connector_helper_funcs);
sti_hdmi_connector_init_property(drm_dev, drm_connector);
hdmi->drm_connector = drm_connector;
err = drm_mode_connector_attach_encoder(drm_connector, encoder);
if (err) {
DRM_ERROR("Failed to attach a connector to a encoder\n");
goto err_sysfs;
}
err = sti_hdmi_register_audio_driver(dev, hdmi);
if (err) {
DRM_ERROR("Failed to attach an audio codec\n");
goto err_sysfs;
}
err = hdmi_audio_infoframe_init(&hdmi->audio.cea);
if (err) {
DRM_ERROR("Failed to init audio infoframe\n");
goto err_sysfs;
}
hdmi_write(hdmi, HDMI_DEFAULT_INT, HDMI_INT_EN);
return 0;
err_sysfs:
drm_bridge_remove(bridge);
hdmi->drm_connector = NULL;
return -EINVAL;
}
static void sti_hdmi_unbind(struct device *dev,
struct device *master, void *data)
{
struct sti_hdmi *hdmi = dev_get_drvdata(dev);
struct drm_device *drm_dev = data;
hdmi_debugfs_exit(hdmi, drm_dev->primary);
}
static int sti_hdmi_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct sti_hdmi *hdmi;
struct device_node *np = dev->of_node;
struct resource *res;
struct device_node *ddc;
int ret;
DRM_INFO("%s\n", __func__);
hdmi = devm_kzalloc(dev, sizeof(*hdmi), GFP_KERNEL);
if (!hdmi)
return -ENOMEM;
ddc = of_parse_phandle(pdev->dev.of_node, "ddc", 0);
if (ddc) {
hdmi->ddc_adapt = of_get_i2c_adapter_by_node(ddc);
of_node_put(ddc);
if (!hdmi->ddc_adapt)
return -EPROBE_DEFER;
}
hdmi->dev = pdev->dev;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "hdmi-reg");
if (!res) {
DRM_ERROR("Invalid hdmi resource\n");
ret = -ENOMEM;
goto release_adapter;
}
hdmi->regs = devm_ioremap_nocache(dev, res->start, resource_size(res));
if (!hdmi->regs) {
ret = -ENOMEM;
goto release_adapter;
}
if (of_device_is_compatible(np, "st,stih416-hdmi")) {
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"syscfg");
if (!res) {
DRM_ERROR("Invalid syscfg resource\n");
ret = -ENOMEM;
goto release_adapter;
}
hdmi->syscfg = devm_ioremap_nocache(dev, res->start,
resource_size(res));
if (!hdmi->syscfg) {
ret = -ENOMEM;
goto release_adapter;
}
}
hdmi->phy_ops = (struct hdmi_phy_ops *)
of_match_node(hdmi_of_match, np)->data;
hdmi->clk_pix = devm_clk_get(dev, "pix");
if (IS_ERR(hdmi->clk_pix)) {
DRM_ERROR("Cannot get hdmi_pix clock\n");
ret = PTR_ERR(hdmi->clk_pix);
goto release_adapter;
}
hdmi->clk_tmds = devm_clk_get(dev, "tmds");
if (IS_ERR(hdmi->clk_tmds)) {
DRM_ERROR("Cannot get hdmi_tmds clock\n");
ret = PTR_ERR(hdmi->clk_tmds);
goto release_adapter;
}
hdmi->clk_phy = devm_clk_get(dev, "phy");
if (IS_ERR(hdmi->clk_phy)) {
DRM_ERROR("Cannot get hdmi_phy clock\n");
ret = PTR_ERR(hdmi->clk_phy);
goto release_adapter;
}
hdmi->clk_audio = devm_clk_get(dev, "audio");
if (IS_ERR(hdmi->clk_audio)) {
DRM_ERROR("Cannot get hdmi_audio clock\n");
ret = PTR_ERR(hdmi->clk_audio);
goto release_adapter;
}
hdmi->hpd = readl(hdmi->regs + HDMI_STA) & HDMI_STA_HOT_PLUG;
init_waitqueue_head(&hdmi->wait_event);
hdmi->irq = platform_get_irq_byname(pdev, "irq");
ret = devm_request_threaded_irq(dev, hdmi->irq, hdmi_irq,
hdmi_irq_thread, IRQF_ONESHOT, dev_name(dev), hdmi);
if (ret) {
DRM_ERROR("Failed to register HDMI interrupt\n");
goto release_adapter;
}
hdmi->reset = devm_reset_control_get(dev, "hdmi");
if (!IS_ERR(hdmi->reset))
reset_control_deassert(hdmi->reset);
platform_set_drvdata(pdev, hdmi);
return component_add(&pdev->dev, &sti_hdmi_ops);
release_adapter:
i2c_put_adapter(hdmi->ddc_adapt);
return ret;
}
static int sti_hdmi_remove(struct platform_device *pdev)
{
struct sti_hdmi *hdmi = dev_get_drvdata(&pdev->dev);
i2c_put_adapter(hdmi->ddc_adapt);
if (hdmi->audio_pdev)
platform_device_unregister(hdmi->audio_pdev);
component_del(&pdev->dev, &sti_hdmi_ops);
return 0;
}
