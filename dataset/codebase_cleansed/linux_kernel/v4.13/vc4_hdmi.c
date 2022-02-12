static inline struct vc4_hdmi_encoder *
to_vc4_hdmi_encoder(struct drm_encoder *encoder)
{
return container_of(encoder, struct vc4_hdmi_encoder, base.base);
}
static inline struct vc4_hdmi_connector *
to_vc4_hdmi_connector(struct drm_connector *connector)
{
return container_of(connector, struct vc4_hdmi_connector, base);
}
int vc4_hdmi_debugfs_regs(struct seq_file *m, void *unused)
{
struct drm_info_node *node = (struct drm_info_node *)m->private;
struct drm_device *dev = node->minor->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
int i;
for (i = 0; i < ARRAY_SIZE(hdmi_regs); i++) {
seq_printf(m, "%s (0x%04x): 0x%08x\n",
hdmi_regs[i].name, hdmi_regs[i].reg,
HDMI_READ(hdmi_regs[i].reg));
}
for (i = 0; i < ARRAY_SIZE(hd_regs); i++) {
seq_printf(m, "%s (0x%04x): 0x%08x\n",
hd_regs[i].name, hd_regs[i].reg,
HD_READ(hd_regs[i].reg));
}
return 0;
}
static void vc4_hdmi_dump_regs(struct drm_device *dev)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
int i;
for (i = 0; i < ARRAY_SIZE(hdmi_regs); i++) {
DRM_INFO("0x%04x (%s): 0x%08x\n",
hdmi_regs[i].reg, hdmi_regs[i].name,
HDMI_READ(hdmi_regs[i].reg));
}
for (i = 0; i < ARRAY_SIZE(hd_regs); i++) {
DRM_INFO("0x%04x (%s): 0x%08x\n",
hd_regs[i].reg, hd_regs[i].name,
HD_READ(hd_regs[i].reg));
}
}
static enum drm_connector_status
vc4_hdmi_connector_detect(struct drm_connector *connector, bool force)
{
struct drm_device *dev = connector->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
if (vc4->hdmi->hpd_gpio) {
if (gpio_get_value_cansleep(vc4->hdmi->hpd_gpio) ^
vc4->hdmi->hpd_active_low)
return connector_status_connected;
else
return connector_status_disconnected;
}
if (drm_probe_ddc(vc4->hdmi->ddc))
return connector_status_connected;
if (HDMI_READ(VC4_HDMI_HOTPLUG) & VC4_HDMI_HOTPLUG_CONNECTED)
return connector_status_connected;
else
return connector_status_disconnected;
}
static void vc4_hdmi_connector_destroy(struct drm_connector *connector)
{
drm_connector_unregister(connector);
drm_connector_cleanup(connector);
}
static int vc4_hdmi_connector_get_modes(struct drm_connector *connector)
{
struct vc4_hdmi_connector *vc4_connector =
to_vc4_hdmi_connector(connector);
struct drm_encoder *encoder = vc4_connector->encoder;
struct vc4_hdmi_encoder *vc4_encoder = to_vc4_hdmi_encoder(encoder);
struct drm_device *dev = connector->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
int ret = 0;
struct edid *edid;
edid = drm_get_edid(connector, vc4->hdmi->ddc);
if (!edid)
return -ENODEV;
vc4_encoder->hdmi_monitor = drm_detect_hdmi_monitor(edid);
if (edid && edid->input & DRM_EDID_INPUT_DIGITAL) {
vc4_encoder->rgb_range_selectable =
drm_rgb_quant_range_selectable(edid);
}
drm_mode_connector_update_edid_property(connector, edid);
ret = drm_add_edid_modes(connector, edid);
drm_edid_to_eld(connector, edid);
return ret;
}
static struct drm_connector *vc4_hdmi_connector_init(struct drm_device *dev,
struct drm_encoder *encoder)
{
struct drm_connector *connector = NULL;
struct vc4_hdmi_connector *hdmi_connector;
int ret = 0;
hdmi_connector = devm_kzalloc(dev->dev, sizeof(*hdmi_connector),
GFP_KERNEL);
if (!hdmi_connector) {
ret = -ENOMEM;
goto fail;
}
connector = &hdmi_connector->base;
hdmi_connector->encoder = encoder;
drm_connector_init(dev, connector, &vc4_hdmi_connector_funcs,
DRM_MODE_CONNECTOR_HDMIA);
drm_connector_helper_add(connector, &vc4_hdmi_connector_helper_funcs);
connector->polled = (DRM_CONNECTOR_POLL_CONNECT |
DRM_CONNECTOR_POLL_DISCONNECT);
connector->interlace_allowed = 1;
connector->doublescan_allowed = 0;
drm_mode_connector_attach_encoder(connector, encoder);
return connector;
fail:
if (connector)
vc4_hdmi_connector_destroy(connector);
return ERR_PTR(ret);
}
static void vc4_hdmi_encoder_destroy(struct drm_encoder *encoder)
{
drm_encoder_cleanup(encoder);
}
static int vc4_hdmi_stop_packet(struct drm_encoder *encoder,
enum hdmi_infoframe_type type)
{
struct drm_device *dev = encoder->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
u32 packet_id = type - 0x80;
HDMI_WRITE(VC4_HDMI_RAM_PACKET_CONFIG,
HDMI_READ(VC4_HDMI_RAM_PACKET_CONFIG) & ~BIT(packet_id));
return wait_for(!(HDMI_READ(VC4_HDMI_RAM_PACKET_STATUS) &
BIT(packet_id)), 100);
}
static void vc4_hdmi_write_infoframe(struct drm_encoder *encoder,
union hdmi_infoframe *frame)
{
struct drm_device *dev = encoder->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
u32 packet_id = frame->any.type - 0x80;
u32 packet_reg = VC4_HDMI_RAM_PACKET(packet_id);
uint8_t buffer[VC4_HDMI_PACKET_STRIDE];
ssize_t len, i;
int ret;
WARN_ONCE(!(HDMI_READ(VC4_HDMI_RAM_PACKET_CONFIG) &
VC4_HDMI_RAM_PACKET_ENABLE),
"Packet RAM has to be on to store the packet.");
len = hdmi_infoframe_pack(frame, buffer, sizeof(buffer));
if (len < 0)
return;
ret = vc4_hdmi_stop_packet(encoder, frame->any.type);
if (ret) {
DRM_ERROR("Failed to wait for infoframe to go idle: %d\n", ret);
return;
}
for (i = 0; i < len; i += 7) {
HDMI_WRITE(packet_reg,
buffer[i + 0] << 0 |
buffer[i + 1] << 8 |
buffer[i + 2] << 16);
packet_reg += 4;
HDMI_WRITE(packet_reg,
buffer[i + 3] << 0 |
buffer[i + 4] << 8 |
buffer[i + 5] << 16 |
buffer[i + 6] << 24);
packet_reg += 4;
}
HDMI_WRITE(VC4_HDMI_RAM_PACKET_CONFIG,
HDMI_READ(VC4_HDMI_RAM_PACKET_CONFIG) | BIT(packet_id));
ret = wait_for((HDMI_READ(VC4_HDMI_RAM_PACKET_STATUS) &
BIT(packet_id)), 100);
if (ret)
DRM_ERROR("Failed to wait for infoframe to start: %d\n", ret);
}
static void vc4_hdmi_set_avi_infoframe(struct drm_encoder *encoder)
{
struct vc4_hdmi_encoder *vc4_encoder = to_vc4_hdmi_encoder(encoder);
struct drm_crtc *crtc = encoder->crtc;
const struct drm_display_mode *mode = &crtc->state->adjusted_mode;
union hdmi_infoframe frame;
int ret;
ret = drm_hdmi_avi_infoframe_from_display_mode(&frame.avi, mode);
if (ret < 0) {
DRM_ERROR("couldn't fill AVI infoframe\n");
return;
}
drm_hdmi_avi_infoframe_quant_range(&frame.avi, mode,
vc4_encoder->limited_rgb_range ?
HDMI_QUANTIZATION_RANGE_LIMITED :
HDMI_QUANTIZATION_RANGE_FULL,
vc4_encoder->rgb_range_selectable);
vc4_hdmi_write_infoframe(encoder, &frame);
}
static void vc4_hdmi_set_spd_infoframe(struct drm_encoder *encoder)
{
union hdmi_infoframe frame;
int ret;
ret = hdmi_spd_infoframe_init(&frame.spd, "Broadcom", "Videocore");
if (ret < 0) {
DRM_ERROR("couldn't fill SPD infoframe\n");
return;
}
frame.spd.sdi = HDMI_SPD_SDI_PC;
vc4_hdmi_write_infoframe(encoder, &frame);
}
static void vc4_hdmi_set_audio_infoframe(struct drm_encoder *encoder)
{
struct drm_device *drm = encoder->dev;
struct vc4_dev *vc4 = drm->dev_private;
struct vc4_hdmi *hdmi = vc4->hdmi;
union hdmi_infoframe frame;
int ret;
ret = hdmi_audio_infoframe_init(&frame.audio);
frame.audio.coding_type = HDMI_AUDIO_CODING_TYPE_STREAM;
frame.audio.sample_frequency = HDMI_AUDIO_SAMPLE_FREQUENCY_STREAM;
frame.audio.sample_size = HDMI_AUDIO_SAMPLE_SIZE_STREAM;
frame.audio.channels = hdmi->audio.channels;
vc4_hdmi_write_infoframe(encoder, &frame);
}
static void vc4_hdmi_set_infoframes(struct drm_encoder *encoder)
{
vc4_hdmi_set_avi_infoframe(encoder);
vc4_hdmi_set_spd_infoframe(encoder);
}
static void vc4_hdmi_encoder_disable(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
struct vc4_hdmi *hdmi = vc4->hdmi;
int ret;
HDMI_WRITE(VC4_HDMI_RAM_PACKET_CONFIG, 0);
HDMI_WRITE(VC4_HDMI_TX_PHY_RESET_CTL, 0xf << 16);
HD_WRITE(VC4_HD_VID_CTL,
HD_READ(VC4_HD_VID_CTL) & ~VC4_HD_VID_CTL_ENABLE);
HD_WRITE(VC4_HD_M_CTL, VC4_HD_M_SW_RST);
udelay(1);
HD_WRITE(VC4_HD_M_CTL, 0);
clk_disable_unprepare(hdmi->hsm_clock);
clk_disable_unprepare(hdmi->pixel_clock);
ret = pm_runtime_put(&hdmi->pdev->dev);
if (ret < 0)
DRM_ERROR("Failed to release power domain: %d\n", ret);
}
static void vc4_hdmi_encoder_enable(struct drm_encoder *encoder)
{
struct drm_display_mode *mode = &encoder->crtc->state->adjusted_mode;
struct vc4_hdmi_encoder *vc4_encoder = to_vc4_hdmi_encoder(encoder);
struct drm_device *dev = encoder->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
struct vc4_hdmi *hdmi = vc4->hdmi;
bool debug_dump_regs = false;
bool hsync_pos = mode->flags & DRM_MODE_FLAG_PHSYNC;
bool vsync_pos = mode->flags & DRM_MODE_FLAG_PVSYNC;
bool interlaced = mode->flags & DRM_MODE_FLAG_INTERLACE;
u32 pixel_rep = (mode->flags & DRM_MODE_FLAG_DBLCLK) ? 2 : 1;
u32 verta = (VC4_SET_FIELD(mode->crtc_vsync_end - mode->crtc_vsync_start,
VC4_HDMI_VERTA_VSP) |
VC4_SET_FIELD(mode->crtc_vsync_start - mode->crtc_vdisplay,
VC4_HDMI_VERTA_VFP) |
VC4_SET_FIELD(mode->crtc_vdisplay, VC4_HDMI_VERTA_VAL));
u32 vertb = (VC4_SET_FIELD(0, VC4_HDMI_VERTB_VSPO) |
VC4_SET_FIELD(mode->crtc_vtotal - mode->crtc_vsync_end,
VC4_HDMI_VERTB_VBP));
u32 vertb_even = (VC4_SET_FIELD(0, VC4_HDMI_VERTB_VSPO) |
VC4_SET_FIELD(mode->crtc_vtotal -
mode->crtc_vsync_end -
interlaced,
VC4_HDMI_VERTB_VBP));
u32 csc_ctl;
int ret;
ret = pm_runtime_get_sync(&hdmi->pdev->dev);
if (ret < 0) {
DRM_ERROR("Failed to retain power domain: %d\n", ret);
return;
}
ret = clk_set_rate(hdmi->hsm_clock, 163682864);
if (ret) {
DRM_ERROR("Failed to set HSM clock rate: %d\n", ret);
return;
}
ret = clk_set_rate(hdmi->pixel_clock,
mode->clock * 1000 *
((mode->flags & DRM_MODE_FLAG_DBLCLK) ? 2 : 1));
if (ret) {
DRM_ERROR("Failed to set pixel clock rate: %d\n", ret);
return;
}
ret = clk_prepare_enable(hdmi->pixel_clock);
if (ret) {
DRM_ERROR("Failed to turn on pixel clock: %d\n", ret);
return;
}
ret = clk_prepare_enable(hdmi->hsm_clock);
if (ret) {
DRM_ERROR("Failed to turn on HDMI state machine clock: %d\n",
ret);
clk_disable_unprepare(hdmi->pixel_clock);
return;
}
HD_WRITE(VC4_HD_M_CTL, VC4_HD_M_SW_RST);
udelay(1);
HD_WRITE(VC4_HD_M_CTL, 0);
HD_WRITE(VC4_HD_M_CTL, VC4_HD_M_ENABLE);
HDMI_WRITE(VC4_HDMI_SW_RESET_CONTROL,
VC4_HDMI_SW_RESET_HDMI |
VC4_HDMI_SW_RESET_FORMAT_DETECT);
HDMI_WRITE(VC4_HDMI_SW_RESET_CONTROL, 0);
HDMI_WRITE(VC4_HDMI_TX_PHY_RESET_CTL, 0xf << 16);
HDMI_WRITE(VC4_HDMI_TX_PHY_RESET_CTL, 0);
if (debug_dump_regs) {
DRM_INFO("HDMI regs before:\n");
vc4_hdmi_dump_regs(dev);
}
HD_WRITE(VC4_HD_VID_CTL, 0);
HDMI_WRITE(VC4_HDMI_SCHEDULER_CONTROL,
HDMI_READ(VC4_HDMI_SCHEDULER_CONTROL) |
VC4_HDMI_SCHEDULER_CONTROL_MANUAL_FORMAT |
VC4_HDMI_SCHEDULER_CONTROL_IGNORE_VSYNC_PREDICTS);
HDMI_WRITE(VC4_HDMI_HORZA,
(vsync_pos ? VC4_HDMI_HORZA_VPOS : 0) |
(hsync_pos ? VC4_HDMI_HORZA_HPOS : 0) |
VC4_SET_FIELD(mode->hdisplay * pixel_rep,
VC4_HDMI_HORZA_HAP));
HDMI_WRITE(VC4_HDMI_HORZB,
VC4_SET_FIELD((mode->htotal -
mode->hsync_end) * pixel_rep,
VC4_HDMI_HORZB_HBP) |
VC4_SET_FIELD((mode->hsync_end -
mode->hsync_start) * pixel_rep,
VC4_HDMI_HORZB_HSP) |
VC4_SET_FIELD((mode->hsync_start -
mode->hdisplay) * pixel_rep,
VC4_HDMI_HORZB_HFP));
HDMI_WRITE(VC4_HDMI_VERTA0, verta);
HDMI_WRITE(VC4_HDMI_VERTA1, verta);
HDMI_WRITE(VC4_HDMI_VERTB0, vertb_even);
HDMI_WRITE(VC4_HDMI_VERTB1, vertb);
HD_WRITE(VC4_HD_VID_CTL,
(vsync_pos ? 0 : VC4_HD_VID_CTL_VSYNC_LOW) |
(hsync_pos ? 0 : VC4_HD_VID_CTL_HSYNC_LOW));
csc_ctl = VC4_SET_FIELD(VC4_HD_CSC_CTL_ORDER_BGR,
VC4_HD_CSC_CTL_ORDER);
if (vc4_encoder->hdmi_monitor &&
drm_default_rgb_quant_range(mode) ==
HDMI_QUANTIZATION_RANGE_LIMITED) {
csc_ctl |= VC4_HD_CSC_CTL_ENABLE;
csc_ctl |= VC4_HD_CSC_CTL_RGB2YCC;
csc_ctl |= VC4_SET_FIELD(VC4_HD_CSC_CTL_MODE_CUSTOM,
VC4_HD_CSC_CTL_MODE);
HD_WRITE(VC4_HD_CSC_12_11, (0x000 << 16) | 0x000);
HD_WRITE(VC4_HD_CSC_14_13, (0x100 << 16) | 0x6e0);
HD_WRITE(VC4_HD_CSC_22_21, (0x6e0 << 16) | 0x000);
HD_WRITE(VC4_HD_CSC_24_23, (0x100 << 16) | 0x000);
HD_WRITE(VC4_HD_CSC_32_31, (0x000 << 16) | 0x6e0);
HD_WRITE(VC4_HD_CSC_34_33, (0x100 << 16) | 0x000);
vc4_encoder->limited_rgb_range = true;
} else {
vc4_encoder->limited_rgb_range = false;
}
HD_WRITE(VC4_HD_CSC_CTL, csc_ctl);
HDMI_WRITE(VC4_HDMI_FIFO_CTL, VC4_HDMI_FIFO_CTL_MASTER_SLAVE_N);
if (debug_dump_regs) {
DRM_INFO("HDMI regs after:\n");
vc4_hdmi_dump_regs(dev);
}
HD_WRITE(VC4_HD_VID_CTL,
HD_READ(VC4_HD_VID_CTL) |
VC4_HD_VID_CTL_ENABLE |
VC4_HD_VID_CTL_UNDERFLOW_ENABLE |
VC4_HD_VID_CTL_FRAME_COUNTER_RESET);
if (vc4_encoder->hdmi_monitor) {
HDMI_WRITE(VC4_HDMI_SCHEDULER_CONTROL,
HDMI_READ(VC4_HDMI_SCHEDULER_CONTROL) |
VC4_HDMI_SCHEDULER_CONTROL_MODE_HDMI);
ret = wait_for(HDMI_READ(VC4_HDMI_SCHEDULER_CONTROL) &
VC4_HDMI_SCHEDULER_CONTROL_HDMI_ACTIVE, 1000);
WARN_ONCE(ret, "Timeout waiting for "
"VC4_HDMI_SCHEDULER_CONTROL_HDMI_ACTIVE\n");
} else {
HDMI_WRITE(VC4_HDMI_RAM_PACKET_CONFIG,
HDMI_READ(VC4_HDMI_RAM_PACKET_CONFIG) &
~(VC4_HDMI_RAM_PACKET_ENABLE));
HDMI_WRITE(VC4_HDMI_SCHEDULER_CONTROL,
HDMI_READ(VC4_HDMI_SCHEDULER_CONTROL) &
~VC4_HDMI_SCHEDULER_CONTROL_MODE_HDMI);
ret = wait_for(!(HDMI_READ(VC4_HDMI_SCHEDULER_CONTROL) &
VC4_HDMI_SCHEDULER_CONTROL_HDMI_ACTIVE), 1000);
WARN_ONCE(ret, "Timeout waiting for "
"!VC4_HDMI_SCHEDULER_CONTROL_HDMI_ACTIVE\n");
}
if (vc4_encoder->hdmi_monitor) {
u32 drift;
WARN_ON(!(HDMI_READ(VC4_HDMI_SCHEDULER_CONTROL) &
VC4_HDMI_SCHEDULER_CONTROL_HDMI_ACTIVE));
HDMI_WRITE(VC4_HDMI_SCHEDULER_CONTROL,
HDMI_READ(VC4_HDMI_SCHEDULER_CONTROL) |
VC4_HDMI_SCHEDULER_CONTROL_VERT_ALWAYS_KEEPOUT);
HDMI_WRITE(VC4_HDMI_RAM_PACKET_CONFIG,
VC4_HDMI_RAM_PACKET_ENABLE);
vc4_hdmi_set_infoframes(encoder);
drift = HDMI_READ(VC4_HDMI_FIFO_CTL);
drift &= VC4_HDMI_FIFO_VALID_WRITE_MASK;
HDMI_WRITE(VC4_HDMI_FIFO_CTL,
drift & ~VC4_HDMI_FIFO_CTL_RECENTER);
HDMI_WRITE(VC4_HDMI_FIFO_CTL,
drift | VC4_HDMI_FIFO_CTL_RECENTER);
udelay(1000);
HDMI_WRITE(VC4_HDMI_FIFO_CTL,
drift & ~VC4_HDMI_FIFO_CTL_RECENTER);
HDMI_WRITE(VC4_HDMI_FIFO_CTL,
drift | VC4_HDMI_FIFO_CTL_RECENTER);
ret = wait_for(HDMI_READ(VC4_HDMI_FIFO_CTL) &
VC4_HDMI_FIFO_CTL_RECENTER_DONE, 1);
WARN_ONCE(ret, "Timeout waiting for "
"VC4_HDMI_FIFO_CTL_RECENTER_DONE");
}
}
static void vc4_hdmi_audio_set_mai_clock(struct vc4_hdmi *hdmi)
{
struct drm_device *drm = hdmi->encoder->dev;
struct vc4_dev *vc4 = to_vc4_dev(drm);
u32 hsm_clock = clk_get_rate(hdmi->hsm_clock);
unsigned long n, m;
rational_best_approximation(hsm_clock, hdmi->audio.samplerate,
VC4_HD_MAI_SMP_N_MASK >>
VC4_HD_MAI_SMP_N_SHIFT,
(VC4_HD_MAI_SMP_M_MASK >>
VC4_HD_MAI_SMP_M_SHIFT) + 1,
&n, &m);
HD_WRITE(VC4_HD_MAI_SMP,
VC4_SET_FIELD(n, VC4_HD_MAI_SMP_N) |
VC4_SET_FIELD(m - 1, VC4_HD_MAI_SMP_M));
}
static void vc4_hdmi_set_n_cts(struct vc4_hdmi *hdmi)
{
struct drm_encoder *encoder = hdmi->encoder;
struct drm_crtc *crtc = encoder->crtc;
struct drm_device *drm = encoder->dev;
struct vc4_dev *vc4 = to_vc4_dev(drm);
const struct drm_display_mode *mode = &crtc->state->adjusted_mode;
u32 samplerate = hdmi->audio.samplerate;
u32 n, cts;
u64 tmp;
n = 128 * samplerate / 1000;
tmp = (u64)(mode->clock * 1000) * n;
do_div(tmp, 128 * samplerate);
cts = tmp;
HDMI_WRITE(VC4_HDMI_CRP_CFG,
VC4_HDMI_CRP_CFG_EXTERNAL_CTS_EN |
VC4_SET_FIELD(n, VC4_HDMI_CRP_CFG_N));
HDMI_WRITE(VC4_HDMI_CTS_0, cts);
HDMI_WRITE(VC4_HDMI_CTS_1, cts);
}
static inline struct vc4_hdmi *dai_to_hdmi(struct snd_soc_dai *dai)
{
struct snd_soc_card *card = snd_soc_dai_get_drvdata(dai);
return snd_soc_card_get_drvdata(card);
}
static int vc4_hdmi_audio_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct vc4_hdmi *hdmi = dai_to_hdmi(dai);
struct drm_encoder *encoder = hdmi->encoder;
struct vc4_dev *vc4 = to_vc4_dev(encoder->dev);
int ret;
if (hdmi->audio.substream && hdmi->audio.substream != substream)
return -EINVAL;
hdmi->audio.substream = substream;
if (!encoder->crtc || !(HDMI_READ(VC4_HDMI_RAM_PACKET_CONFIG) &
VC4_HDMI_RAM_PACKET_ENABLE))
return -ENODEV;
ret = snd_pcm_hw_constraint_eld(substream->runtime,
hdmi->connector->eld);
if (ret)
return ret;
return 0;
}
static int vc4_hdmi_audio_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
return 0;
}
static void vc4_hdmi_audio_reset(struct vc4_hdmi *hdmi)
{
struct drm_encoder *encoder = hdmi->encoder;
struct drm_device *drm = encoder->dev;
struct device *dev = &hdmi->pdev->dev;
struct vc4_dev *vc4 = to_vc4_dev(drm);
int ret;
ret = vc4_hdmi_stop_packet(encoder, HDMI_INFOFRAME_TYPE_AUDIO);
if (ret)
dev_err(dev, "Failed to stop audio infoframe: %d\n", ret);
HD_WRITE(VC4_HD_MAI_CTL, VC4_HD_MAI_CTL_RESET);
HD_WRITE(VC4_HD_MAI_CTL, VC4_HD_MAI_CTL_ERRORF);
HD_WRITE(VC4_HD_MAI_CTL, VC4_HD_MAI_CTL_FLUSH);
}
static void vc4_hdmi_audio_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct vc4_hdmi *hdmi = dai_to_hdmi(dai);
if (substream != hdmi->audio.substream)
return;
vc4_hdmi_audio_reset(hdmi);
hdmi->audio.substream = NULL;
}
static int vc4_hdmi_audio_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct vc4_hdmi *hdmi = dai_to_hdmi(dai);
struct drm_encoder *encoder = hdmi->encoder;
struct drm_device *drm = encoder->dev;
struct device *dev = &hdmi->pdev->dev;
struct vc4_dev *vc4 = to_vc4_dev(drm);
u32 audio_packet_config, channel_mask;
u32 channel_map, i;
if (substream != hdmi->audio.substream)
return -EINVAL;
dev_dbg(dev, "%s: %u Hz, %d bit, %d channels\n", __func__,
params_rate(params), params_width(params),
params_channels(params));
hdmi->audio.channels = params_channels(params);
hdmi->audio.samplerate = params_rate(params);
HD_WRITE(VC4_HD_MAI_CTL,
VC4_HD_MAI_CTL_RESET |
VC4_HD_MAI_CTL_FLUSH |
VC4_HD_MAI_CTL_DLATE |
VC4_HD_MAI_CTL_ERRORE |
VC4_HD_MAI_CTL_ERRORF);
vc4_hdmi_audio_set_mai_clock(hdmi);
audio_packet_config =
VC4_HDMI_AUDIO_PACKET_ZERO_DATA_ON_SAMPLE_FLAT |
VC4_HDMI_AUDIO_PACKET_ZERO_DATA_ON_INACTIVE_CHANNELS |
VC4_SET_FIELD(0xf, VC4_HDMI_AUDIO_PACKET_B_FRAME_IDENTIFIER);
channel_mask = GENMASK(hdmi->audio.channels - 1, 0);
audio_packet_config |= VC4_SET_FIELD(channel_mask,
VC4_HDMI_AUDIO_PACKET_CEA_MASK);
if (hdmi->audio.samplerate > 96000) {
HD_WRITE(VC4_HD_MAI_THR,
VC4_SET_FIELD(0x12, VC4_HD_MAI_THR_DREQHIGH) |
VC4_SET_FIELD(0x12, VC4_HD_MAI_THR_DREQLOW));
} else if (hdmi->audio.samplerate > 48000) {
HD_WRITE(VC4_HD_MAI_THR,
VC4_SET_FIELD(0x14, VC4_HD_MAI_THR_DREQHIGH) |
VC4_SET_FIELD(0x12, VC4_HD_MAI_THR_DREQLOW));
} else {
HD_WRITE(VC4_HD_MAI_THR,
VC4_SET_FIELD(0x10, VC4_HD_MAI_THR_PANICHIGH) |
VC4_SET_FIELD(0x10, VC4_HD_MAI_THR_PANICLOW) |
VC4_SET_FIELD(0x10, VC4_HD_MAI_THR_DREQHIGH) |
VC4_SET_FIELD(0x10, VC4_HD_MAI_THR_DREQLOW));
}
HDMI_WRITE(VC4_HDMI_MAI_CONFIG,
VC4_HDMI_MAI_CONFIG_BIT_REVERSE |
VC4_SET_FIELD(channel_mask, VC4_HDMI_MAI_CHANNEL_MASK));
channel_map = 0;
for (i = 0; i < 8; i++) {
if (channel_mask & BIT(i))
channel_map |= i << (3 * i);
}
HDMI_WRITE(VC4_HDMI_MAI_CHANNEL_MAP, channel_map);
HDMI_WRITE(VC4_HDMI_AUDIO_PACKET_CONFIG, audio_packet_config);
vc4_hdmi_set_n_cts(hdmi);
return 0;
}
static int vc4_hdmi_audio_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct vc4_hdmi *hdmi = dai_to_hdmi(dai);
struct drm_encoder *encoder = hdmi->encoder;
struct drm_device *drm = encoder->dev;
struct vc4_dev *vc4 = to_vc4_dev(drm);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
vc4_hdmi_set_audio_infoframe(encoder);
HDMI_WRITE(VC4_HDMI_TX_PHY_CTL0,
HDMI_READ(VC4_HDMI_TX_PHY_CTL0) &
~VC4_HDMI_TX_PHY_RNG_PWRDN);
HD_WRITE(VC4_HD_MAI_CTL,
VC4_SET_FIELD(hdmi->audio.channels,
VC4_HD_MAI_CTL_CHNUM) |
VC4_HD_MAI_CTL_ENABLE);
break;
case SNDRV_PCM_TRIGGER_STOP:
HD_WRITE(VC4_HD_MAI_CTL,
VC4_HD_MAI_CTL_DLATE |
VC4_HD_MAI_CTL_ERRORE |
VC4_HD_MAI_CTL_ERRORF);
HDMI_WRITE(VC4_HDMI_TX_PHY_CTL0,
HDMI_READ(VC4_HDMI_TX_PHY_CTL0) |
VC4_HDMI_TX_PHY_RNG_PWRDN);
break;
default:
break;
}
return 0;
}
static inline struct vc4_hdmi *
snd_component_to_hdmi(struct snd_soc_component *component)
{
struct snd_soc_card *card = snd_soc_component_get_drvdata(component);
return snd_soc_card_get_drvdata(card);
}
static int vc4_hdmi_audio_eld_ctl_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct vc4_hdmi *hdmi = snd_component_to_hdmi(component);
uinfo->type = SNDRV_CTL_ELEM_TYPE_BYTES;
uinfo->count = sizeof(hdmi->connector->eld);
return 0;
}
static int vc4_hdmi_audio_eld_ctl_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct vc4_hdmi *hdmi = snd_component_to_hdmi(component);
memcpy(ucontrol->value.bytes.data, hdmi->connector->eld,
sizeof(hdmi->connector->eld));
return 0;
}
static int vc4_hdmi_audio_cpu_dai_probe(struct snd_soc_dai *dai)
{
struct vc4_hdmi *hdmi = dai_to_hdmi(dai);
snd_soc_dai_init_dma_data(dai, &hdmi->audio.dma_data, NULL);
return 0;
}
static int vc4_hdmi_audio_init(struct vc4_hdmi *hdmi)
{
struct snd_soc_dai_link *dai_link = &hdmi->audio.link;
struct snd_soc_card *card = &hdmi->audio.card;
struct device *dev = &hdmi->pdev->dev;
const __be32 *addr;
int ret;
if (!of_find_property(dev->of_node, "dmas", NULL)) {
dev_warn(dev,
"'dmas' DT property is missing, no HDMI audio\n");
return 0;
}
addr = of_get_address(dev->of_node, 1, NULL, NULL);
hdmi->audio.dma_data.addr = be32_to_cpup(addr) + VC4_HD_MAI_DATA;
hdmi->audio.dma_data.addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
hdmi->audio.dma_data.maxburst = 2;
ret = devm_snd_dmaengine_pcm_register(dev, &pcm_conf, 0);
if (ret) {
dev_err(dev, "Could not register PCM component: %d\n", ret);
return ret;
}
ret = devm_snd_soc_register_component(dev, &vc4_hdmi_audio_cpu_dai_comp,
&vc4_hdmi_audio_cpu_dai_drv, 1);
if (ret) {
dev_err(dev, "Could not register CPU DAI: %d\n", ret);
return ret;
}
ret = snd_soc_register_codec(dev, &vc4_hdmi_audio_codec_drv,
&vc4_hdmi_audio_codec_dai_drv, 1);
if (ret) {
dev_err(dev, "Could not register codec: %d\n", ret);
return ret;
}
dai_link->name = "MAI";
dai_link->stream_name = "MAI PCM";
dai_link->codec_dai_name = vc4_hdmi_audio_codec_dai_drv.name;
dai_link->cpu_dai_name = dev_name(dev);
dai_link->codec_name = dev_name(dev);
dai_link->platform_name = dev_name(dev);
card->dai_link = dai_link;
card->num_links = 1;
card->name = "vc4-hdmi";
card->dev = dev;
snd_soc_card_set_drvdata(card, hdmi);
ret = devm_snd_soc_register_card(dev, card);
if (ret) {
dev_err(dev, "Could not register sound card: %d\n", ret);
goto unregister_codec;
}
return 0;
unregister_codec:
snd_soc_unregister_codec(dev);
return ret;
}
static void vc4_hdmi_audio_cleanup(struct vc4_hdmi *hdmi)
{
struct device *dev = &hdmi->pdev->dev;
if (dev_get_drvdata(dev))
snd_soc_unregister_codec(dev);
}
static int vc4_hdmi_bind(struct device *dev, struct device *master, void *data)
{
struct platform_device *pdev = to_platform_device(dev);
struct drm_device *drm = dev_get_drvdata(master);
struct vc4_dev *vc4 = drm->dev_private;
struct vc4_hdmi *hdmi;
struct vc4_hdmi_encoder *vc4_hdmi_encoder;
struct device_node *ddc_node;
u32 value;
int ret;
hdmi = devm_kzalloc(dev, sizeof(*hdmi), GFP_KERNEL);
if (!hdmi)
return -ENOMEM;
vc4_hdmi_encoder = devm_kzalloc(dev, sizeof(*vc4_hdmi_encoder),
GFP_KERNEL);
if (!vc4_hdmi_encoder)
return -ENOMEM;
vc4_hdmi_encoder->base.type = VC4_ENCODER_TYPE_HDMI;
hdmi->encoder = &vc4_hdmi_encoder->base.base;
hdmi->pdev = pdev;
hdmi->hdmicore_regs = vc4_ioremap_regs(pdev, 0);
if (IS_ERR(hdmi->hdmicore_regs))
return PTR_ERR(hdmi->hdmicore_regs);
hdmi->hd_regs = vc4_ioremap_regs(pdev, 1);
if (IS_ERR(hdmi->hd_regs))
return PTR_ERR(hdmi->hd_regs);
hdmi->pixel_clock = devm_clk_get(dev, "pixel");
if (IS_ERR(hdmi->pixel_clock)) {
DRM_ERROR("Failed to get pixel clock\n");
return PTR_ERR(hdmi->pixel_clock);
}
hdmi->hsm_clock = devm_clk_get(dev, "hdmi");
if (IS_ERR(hdmi->hsm_clock)) {
DRM_ERROR("Failed to get HDMI state machine clock\n");
return PTR_ERR(hdmi->hsm_clock);
}
ddc_node = of_parse_phandle(dev->of_node, "ddc", 0);
if (!ddc_node) {
DRM_ERROR("Failed to find ddc node in device tree\n");
return -ENODEV;
}
hdmi->ddc = of_find_i2c_adapter_by_node(ddc_node);
of_node_put(ddc_node);
if (!hdmi->ddc) {
DRM_DEBUG("Failed to get ddc i2c adapter by node\n");
return -EPROBE_DEFER;
}
if (of_find_property(dev->of_node, "hpd-gpios", &value)) {
enum of_gpio_flags hpd_gpio_flags;
hdmi->hpd_gpio = of_get_named_gpio_flags(dev->of_node,
"hpd-gpios", 0,
&hpd_gpio_flags);
if (hdmi->hpd_gpio < 0) {
ret = hdmi->hpd_gpio;
goto err_put_i2c;
}
hdmi->hpd_active_low = hpd_gpio_flags & OF_GPIO_ACTIVE_LOW;
}
vc4->hdmi = hdmi;
pm_runtime_enable(dev);
drm_encoder_init(drm, hdmi->encoder, &vc4_hdmi_encoder_funcs,
DRM_MODE_ENCODER_TMDS, NULL);
drm_encoder_helper_add(hdmi->encoder, &vc4_hdmi_encoder_helper_funcs);
hdmi->connector = vc4_hdmi_connector_init(drm, hdmi->encoder);
if (IS_ERR(hdmi->connector)) {
ret = PTR_ERR(hdmi->connector);
goto err_destroy_encoder;
}
ret = vc4_hdmi_audio_init(hdmi);
if (ret)
goto err_destroy_encoder;
return 0;
err_destroy_encoder:
vc4_hdmi_encoder_destroy(hdmi->encoder);
pm_runtime_disable(dev);
err_put_i2c:
put_device(&hdmi->ddc->dev);
return ret;
}
static void vc4_hdmi_unbind(struct device *dev, struct device *master,
void *data)
{
struct drm_device *drm = dev_get_drvdata(master);
struct vc4_dev *vc4 = drm->dev_private;
struct vc4_hdmi *hdmi = vc4->hdmi;
vc4_hdmi_audio_cleanup(hdmi);
vc4_hdmi_connector_destroy(hdmi->connector);
vc4_hdmi_encoder_destroy(hdmi->encoder);
pm_runtime_disable(dev);
put_device(&hdmi->ddc->dev);
vc4->hdmi = NULL;
}
static int vc4_hdmi_dev_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &vc4_hdmi_ops);
}
static int vc4_hdmi_dev_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &vc4_hdmi_ops);
return 0;
}
