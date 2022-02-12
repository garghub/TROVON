static u32 hda_read(struct sti_hda *hda, int offset)
{
return readl(hda->regs + offset);
}
static void hda_write(struct sti_hda *hda, u32 val, int offset)
{
writel(val, hda->regs + offset);
}
static bool hda_get_mode_idx(struct drm_display_mode mode, int *idx)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(hda_supported_modes); i++)
if (drm_mode_equal(&hda_supported_modes[i].mode, &mode)) {
*idx = i;
return true;
}
return false;
}
static void hda_enable_hd_dacs(struct sti_hda *hda, bool enable)
{
u32 mask;
if (hda->video_dacs_ctrl) {
u32 val;
switch ((u32)hda->video_dacs_ctrl & VIDEO_DACS_CONTROL_MASK) {
case VIDEO_DACS_CONTROL_SYSCFG2535:
mask = DAC_CFG_HD_OFF_MASK;
break;
case VIDEO_DACS_CONTROL_SYSCFG5072:
mask = DAC_CFG_HD_HZUVW_OFF_MASK;
break;
default:
DRM_INFO("Video DACS control register not supported!");
return;
}
val = readl(hda->video_dacs_ctrl);
if (enable)
val &= ~mask;
else
val |= mask;
writel(val, hda->video_dacs_ctrl);
}
}
static void hda_dbg_cfg(struct seq_file *s, int val)
{
seq_puts(s, "\tAWG ");
seq_puts(s, val & CFG_AWG_ASYNC_EN ? "enabled" : "disabled");
}
static void hda_dbg_awg_microcode(struct seq_file *s, void __iomem *reg)
{
unsigned int i;
seq_puts(s, "\n\n");
seq_puts(s, " HDA AWG microcode:");
for (i = 0; i < AWG_MAX_INST; i++) {
if (i % 8 == 0)
seq_printf(s, "\n %04X:", i);
seq_printf(s, " %04X", readl(reg + i * 4));
}
}
static void hda_dbg_video_dacs_ctrl(struct seq_file *s, void __iomem *reg)
{
u32 val = readl(reg);
u32 mask;
switch ((u32)reg & VIDEO_DACS_CONTROL_MASK) {
case VIDEO_DACS_CONTROL_SYSCFG2535:
mask = DAC_CFG_HD_OFF_MASK;
break;
case VIDEO_DACS_CONTROL_SYSCFG5072:
mask = DAC_CFG_HD_HZUVW_OFF_MASK;
break;
default:
DRM_DEBUG_DRIVER("Warning: DACS ctrl register not supported!");
return;
}
seq_puts(s, "\n");
seq_printf(s, "\n %-25s 0x%08X", "VIDEO_DACS_CONTROL", val);
seq_puts(s, "\tHD DACs ");
seq_puts(s, val & mask ? "disabled" : "enabled");
}
static int hda_dbg_show(struct seq_file *s, void *data)
{
struct drm_info_node *node = s->private;
struct sti_hda *hda = (struct sti_hda *)node->info_ent->data;
seq_printf(s, "HD Analog: (vaddr = 0x%p)", hda->regs);
DBGFS_DUMP(HDA_ANA_CFG);
hda_dbg_cfg(s, readl(hda->regs + HDA_ANA_CFG));
DBGFS_DUMP(HDA_ANA_SCALE_CTRL_Y);
DBGFS_DUMP(HDA_ANA_SCALE_CTRL_CB);
DBGFS_DUMP(HDA_ANA_SCALE_CTRL_CR);
DBGFS_DUMP(HDA_ANA_ANC_CTRL);
DBGFS_DUMP(HDA_ANA_SRC_Y_CFG);
DBGFS_DUMP(HDA_ANA_SRC_C_CFG);
hda_dbg_awg_microcode(s, hda->regs + HDA_SYNC_AWGI);
if (hda->video_dacs_ctrl)
hda_dbg_video_dacs_ctrl(s, hda->video_dacs_ctrl);
seq_puts(s, "\n");
return 0;
}
static void hda_debugfs_exit(struct sti_hda *hda, struct drm_minor *minor)
{
drm_debugfs_remove_files(hda_debugfs_files,
ARRAY_SIZE(hda_debugfs_files),
minor);
}
static int hda_debugfs_init(struct sti_hda *hda, struct drm_minor *minor)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(hda_debugfs_files); i++)
hda_debugfs_files[i].data = hda;
return drm_debugfs_create_files(hda_debugfs_files,
ARRAY_SIZE(hda_debugfs_files),
minor->debugfs_root, minor);
}
static void sti_hda_configure_awg(struct sti_hda *hda, u32 *awg_instr, int nb)
{
unsigned int i;
DRM_DEBUG_DRIVER("\n");
for (i = 0; i < nb; i++)
hda_write(hda, awg_instr[i], HDA_SYNC_AWGI + i * 4);
for (i = nb; i < AWG_MAX_INST; i++)
hda_write(hda, 0, HDA_SYNC_AWGI + i * 4);
}
static void sti_hda_disable(struct drm_bridge *bridge)
{
struct sti_hda *hda = bridge->driver_private;
u32 val;
if (!hda->enabled)
return;
DRM_DEBUG_DRIVER("\n");
val = hda_read(hda, HDA_ANA_CFG);
val &= ~CFG_AWG_ASYNC_EN;
hda_write(hda, val, HDA_ANA_CFG);
hda_write(hda, 0, HDA_ANA_ANC_CTRL);
hda_enable_hd_dacs(hda, false);
clk_disable_unprepare(hda->clk_hddac);
clk_disable_unprepare(hda->clk_pix);
hda->enabled = false;
}
static void sti_hda_pre_enable(struct drm_bridge *bridge)
{
struct sti_hda *hda = bridge->driver_private;
u32 val, i, mode_idx;
u32 src_filter_y, src_filter_c;
u32 *coef_y, *coef_c;
u32 filter_mode;
DRM_DEBUG_DRIVER("\n");
if (hda->enabled)
return;
if (clk_prepare_enable(hda->clk_pix))
DRM_ERROR("Failed to prepare/enable hda_pix clk\n");
if (clk_prepare_enable(hda->clk_hddac))
DRM_ERROR("Failed to prepare/enable hda_hddac clk\n");
if (!hda_get_mode_idx(hda->mode, &mode_idx)) {
DRM_ERROR("Undefined mode\n");
return;
}
switch (hda_supported_modes[mode_idx].vid_cat) {
case VID_HD_148M:
DRM_ERROR("Beyond HD analog capabilities\n");
return;
case VID_HD_74M:
filter_mode = CFG_AWG_FLTR_MODE_HD;
src_filter_y = HDA_ANA_SRC_Y_CFG_ALT_2X;
src_filter_c = HDA_ANA_SRC_C_CFG_ALT_2X;
coef_y = coef_y_alt_2x;
coef_c = coef_c_alt_2x;
break;
case VID_ED:
filter_mode = CFG_AWG_FLTR_MODE_ED;
src_filter_y = HDA_ANA_SRC_Y_CFG_4X;
src_filter_c = HDA_ANA_SRC_C_CFG_4X;
coef_y = coef_yc_4x;
coef_c = coef_yc_4x;
break;
case VID_SD:
DRM_ERROR("Not supported\n");
return;
default:
DRM_ERROR("Undefined resolution\n");
return;
}
DRM_DEBUG_DRIVER("Using HDA mode #%d\n", mode_idx);
hda_enable_hd_dacs(hda, true);
hda_write(hda, SCALE_CTRL_Y_DFLT, HDA_ANA_SCALE_CTRL_Y);
hda_write(hda, SCALE_CTRL_CB_DFLT, HDA_ANA_SCALE_CTRL_CB);
hda_write(hda, SCALE_CTRL_CR_DFLT, HDA_ANA_SCALE_CTRL_CR);
hda_write(hda , src_filter_y, HDA_ANA_SRC_Y_CFG);
hda_write(hda, src_filter_c, HDA_ANA_SRC_C_CFG);
for (i = 0; i < SAMPLER_COEF_NB; i++) {
hda_write(hda, coef_y[i], HDA_COEFF_Y_PH1_TAP123 + i * 4);
hda_write(hda, coef_c[i], HDA_COEFF_C_PH1_TAP123 + i * 4);
}
val = 0;
val |= (hda->mode.flags & DRM_MODE_FLAG_INTERLACE) ?
0 : CFG_AWG_ASYNC_VSYNC_MTD;
val |= (CFG_PBPR_SYNC_OFF_VAL << CFG_PBPR_SYNC_OFF_SHIFT);
val |= filter_mode;
hda_write(hda, val, HDA_ANA_CFG);
sti_hda_configure_awg(hda, hda_supported_modes[mode_idx].awg_instr,
hda_supported_modes[mode_idx].nb_instr);
val = hda_read(hda, HDA_ANA_CFG);
val |= CFG_AWG_ASYNC_EN;
hda_write(hda, val, HDA_ANA_CFG);
hda->enabled = true;
}
static void sti_hda_set_mode(struct drm_bridge *bridge,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct sti_hda *hda = bridge->driver_private;
u32 mode_idx;
int hddac_rate;
int ret;
DRM_DEBUG_DRIVER("\n");
memcpy(&hda->mode, mode, sizeof(struct drm_display_mode));
if (!hda_get_mode_idx(hda->mode, &mode_idx)) {
DRM_ERROR("Undefined mode\n");
return;
}
switch (hda_supported_modes[mode_idx].vid_cat) {
case VID_HD_74M:
hddac_rate = mode->clock * 1000 * 2;
break;
case VID_ED:
hddac_rate = mode->clock * 1000 * 4;
break;
default:
DRM_ERROR("Undefined mode\n");
return;
}
ret = clk_set_rate(hda->clk_hddac, hddac_rate);
if (ret < 0)
DRM_ERROR("Cannot set rate (%dHz) for hda_hddac clk\n",
hddac_rate);
ret = clk_set_rate(hda->clk_pix, mode->clock * 1000);
if (ret < 0)
DRM_ERROR("Cannot set rate (%dHz) for hda_pix clk\n",
mode->clock * 1000);
}
static void sti_hda_bridge_nope(struct drm_bridge *bridge)
{
}
static int sti_hda_connector_get_modes(struct drm_connector *connector)
{
unsigned int i;
int count = 0;
struct sti_hda_connector *hda_connector
= to_sti_hda_connector(connector);
struct sti_hda *hda = hda_connector->hda;
DRM_DEBUG_DRIVER("\n");
for (i = 0; i < ARRAY_SIZE(hda_supported_modes); i++) {
struct drm_display_mode *mode =
drm_mode_duplicate(hda->drm_dev,
&hda_supported_modes[i].mode);
if (!mode)
continue;
mode->vrefresh = drm_mode_vrefresh(mode);
if (i == 0)
mode->type |= DRM_MODE_TYPE_PREFERRED;
drm_mode_probed_add(connector, mode);
count++;
}
return count;
}
static int sti_hda_connector_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
int target = mode->clock * 1000;
int target_min = target - CLK_TOLERANCE_HZ;
int target_max = target + CLK_TOLERANCE_HZ;
int result;
int idx;
struct sti_hda_connector *hda_connector
= to_sti_hda_connector(connector);
struct sti_hda *hda = hda_connector->hda;
if (!hda_get_mode_idx(*mode, &idx)) {
return MODE_BAD;
} else {
result = clk_round_rate(hda->clk_pix, target);
DRM_DEBUG_DRIVER("target rate = %d => available rate = %d\n",
target, result);
if ((result < target_min) || (result > target_max)) {
DRM_DEBUG_DRIVER("hda pixclk=%d not supported\n",
target);
return MODE_BAD;
}
}
return MODE_OK;
}
static enum drm_connector_status
sti_hda_connector_detect(struct drm_connector *connector, bool force)
{
return connector_status_connected;
}
static int sti_hda_late_register(struct drm_connector *connector)
{
struct sti_hda_connector *hda_connector
= to_sti_hda_connector(connector);
struct sti_hda *hda = hda_connector->hda;
if (hda_debugfs_init(hda, hda->drm_dev->primary)) {
DRM_ERROR("HDA debugfs setup failed\n");
return -EINVAL;
}
return 0;
}
static struct drm_encoder *sti_hda_find_encoder(struct drm_device *dev)
{
struct drm_encoder *encoder;
list_for_each_entry(encoder, &dev->mode_config.encoder_list, head) {
if (encoder->encoder_type == DRM_MODE_ENCODER_DAC)
return encoder;
}
return NULL;
}
static int sti_hda_bind(struct device *dev, struct device *master, void *data)
{
struct sti_hda *hda = dev_get_drvdata(dev);
struct drm_device *drm_dev = data;
struct drm_encoder *encoder;
struct sti_hda_connector *connector;
struct drm_connector *drm_connector;
struct drm_bridge *bridge;
int err;
hda->drm_dev = drm_dev;
encoder = sti_hda_find_encoder(drm_dev);
if (!encoder)
return -ENOMEM;
connector = devm_kzalloc(dev, sizeof(*connector), GFP_KERNEL);
if (!connector)
return -ENOMEM;
connector->hda = hda;
bridge = devm_kzalloc(dev, sizeof(*bridge), GFP_KERNEL);
if (!bridge)
return -ENOMEM;
bridge->driver_private = hda;
bridge->funcs = &sti_hda_bridge_funcs;
drm_bridge_attach(drm_dev, bridge);
encoder->bridge = bridge;
connector->encoder = encoder;
drm_connector = (struct drm_connector *)connector;
drm_connector->polled = DRM_CONNECTOR_POLL_HPD;
drm_connector_init(drm_dev, drm_connector,
&sti_hda_connector_funcs, DRM_MODE_CONNECTOR_Component);
drm_connector_helper_add(drm_connector,
&sti_hda_connector_helper_funcs);
err = drm_mode_connector_attach_encoder(drm_connector, encoder);
if (err) {
DRM_ERROR("Failed to attach a connector to a encoder\n");
goto err_sysfs;
}
hda_enable_hd_dacs(hda, false);
return 0;
err_sysfs:
drm_bridge_remove(bridge);
return -EINVAL;
}
static void sti_hda_unbind(struct device *dev,
struct device *master, void *data)
{
struct sti_hda *hda = dev_get_drvdata(dev);
struct drm_device *drm_dev = data;
hda_debugfs_exit(hda, drm_dev->primary);
}
static int sti_hda_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct sti_hda *hda;
struct resource *res;
DRM_INFO("%s\n", __func__);
hda = devm_kzalloc(dev, sizeof(*hda), GFP_KERNEL);
if (!hda)
return -ENOMEM;
hda->dev = pdev->dev;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "hda-reg");
if (!res) {
DRM_ERROR("Invalid hda resource\n");
return -ENOMEM;
}
hda->regs = devm_ioremap_nocache(dev, res->start, resource_size(res));
if (!hda->regs)
return -ENOMEM;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"video-dacs-ctrl");
if (res) {
hda->video_dacs_ctrl = devm_ioremap_nocache(dev, res->start,
resource_size(res));
if (!hda->video_dacs_ctrl)
return -ENOMEM;
} else {
DRM_DEBUG_DRIVER("No video-dacs-ctrl resource\n");
hda->video_dacs_ctrl = NULL;
}
hda->clk_pix = devm_clk_get(dev, "pix");
if (IS_ERR(hda->clk_pix)) {
DRM_ERROR("Cannot get hda_pix clock\n");
return PTR_ERR(hda->clk_pix);
}
hda->clk_hddac = devm_clk_get(dev, "hddac");
if (IS_ERR(hda->clk_hddac)) {
DRM_ERROR("Cannot get hda_hddac clock\n");
return PTR_ERR(hda->clk_hddac);
}
platform_set_drvdata(pdev, hda);
return component_add(&pdev->dev, &sti_hda_ops);
}
static int sti_hda_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &sti_hda_ops);
return 0;
}
