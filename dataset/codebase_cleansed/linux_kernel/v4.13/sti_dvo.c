static int dvo_awg_generate_code(struct sti_dvo *dvo, u8 *ram_size, u32 *ram_code)
{
struct drm_display_mode *mode = &dvo->mode;
struct dvo_config *config = dvo->config;
struct awg_code_generation_params fw_gen_params;
struct awg_timing timing;
fw_gen_params.ram_code = ram_code;
fw_gen_params.instruction_offset = 0;
timing.total_lines = mode->vtotal;
timing.active_lines = mode->vdisplay;
timing.blanking_lines = mode->vsync_start - mode->vdisplay;
timing.trailing_lines = mode->vtotal - mode->vsync_start;
timing.total_pixels = mode->htotal;
timing.active_pixels = mode->hdisplay;
timing.blanking_pixels = mode->hsync_start - mode->hdisplay;
timing.trailing_pixels = mode->htotal - mode->hsync_start;
timing.blanking_level = BLANKING_LEVEL;
if (config->awg_fwgen_fct(&fw_gen_params, &timing)) {
DRM_ERROR("AWG firmware not properly generated\n");
return -EINVAL;
}
*ram_size = fw_gen_params.instruction_offset;
return 0;
}
static void dvo_awg_configure(struct sti_dvo *dvo, u32 *awg_ram_code, int nb)
{
int i;
DRM_DEBUG_DRIVER("\n");
for (i = 0; i < nb; i++)
writel(awg_ram_code[i],
dvo->regs + DVO_DIGSYNC_INSTR_I + i * 4);
for (i = nb; i < AWG_MAX_INST; i++)
writel(0, dvo->regs + DVO_DIGSYNC_INSTR_I + i * 4);
writel(DVO_AWG_CTRL_EN, dvo->regs + DVO_AWG_DIGSYNC_CTRL);
}
static void dvo_dbg_awg_microcode(struct seq_file *s, void __iomem *reg)
{
unsigned int i;
seq_puts(s, "\n\n");
seq_puts(s, " DVO AWG microcode:");
for (i = 0; i < AWG_MAX_INST; i++) {
if (i % 8 == 0)
seq_printf(s, "\n %04X:", i);
seq_printf(s, " %04X", readl(reg + i * 4));
}
}
static int dvo_dbg_show(struct seq_file *s, void *data)
{
struct drm_info_node *node = s->private;
struct sti_dvo *dvo = (struct sti_dvo *)node->info_ent->data;
seq_printf(s, "DVO: (vaddr = 0x%p)", dvo->regs);
DBGFS_DUMP(DVO_AWG_DIGSYNC_CTRL);
DBGFS_DUMP(DVO_DOF_CFG);
DBGFS_DUMP(DVO_LUT_PROG_LOW);
DBGFS_DUMP(DVO_LUT_PROG_MID);
DBGFS_DUMP(DVO_LUT_PROG_HIGH);
dvo_dbg_awg_microcode(s, dvo->regs + DVO_DIGSYNC_INSTR_I);
seq_putc(s, '\n');
return 0;
}
static int dvo_debugfs_init(struct sti_dvo *dvo, struct drm_minor *minor)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(dvo_debugfs_files); i++)
dvo_debugfs_files[i].data = dvo;
return drm_debugfs_create_files(dvo_debugfs_files,
ARRAY_SIZE(dvo_debugfs_files),
minor->debugfs_root, minor);
}
static void sti_dvo_disable(struct drm_bridge *bridge)
{
struct sti_dvo *dvo = bridge->driver_private;
if (!dvo->enabled)
return;
DRM_DEBUG_DRIVER("\n");
if (dvo->config->awg_fwgen_fct)
writel(0x00000000, dvo->regs + DVO_AWG_DIGSYNC_CTRL);
writel(0x00000000, dvo->regs + DVO_DOF_CFG);
if (dvo->panel)
dvo->panel->funcs->disable(dvo->panel);
clk_disable_unprepare(dvo->clk_pix);
clk_disable_unprepare(dvo->clk);
dvo->enabled = false;
}
static void sti_dvo_pre_enable(struct drm_bridge *bridge)
{
struct sti_dvo *dvo = bridge->driver_private;
struct dvo_config *config = dvo->config;
u32 val;
DRM_DEBUG_DRIVER("\n");
if (dvo->enabled)
return;
writel(0x00000000, dvo->regs + DVO_DOF_CFG);
writel(0x00000000, dvo->regs + DVO_AWG_DIGSYNC_CTRL);
if (config->awg_fwgen_fct) {
u8 nb_instr;
u32 awg_ram_code[AWG_MAX_INST];
if (!dvo_awg_generate_code(dvo, &nb_instr, awg_ram_code))
dvo_awg_configure(dvo, awg_ram_code, nb_instr);
else
return;
}
if (clk_prepare_enable(dvo->clk_pix))
DRM_ERROR("Failed to prepare/enable dvo_pix clk\n");
if (clk_prepare_enable(dvo->clk))
DRM_ERROR("Failed to prepare/enable dvo clk\n");
if (dvo->panel)
dvo->panel->funcs->enable(dvo->panel);
writel(config->lowbyte, dvo->regs + DVO_LUT_PROG_LOW);
writel(config->midbyte, dvo->regs + DVO_LUT_PROG_MID);
writel(config->highbyte, dvo->regs + DVO_LUT_PROG_HIGH);
val = (config->flags | DVO_DOF_EN);
writel(val, dvo->regs + DVO_DOF_CFG);
dvo->enabled = true;
}
static void sti_dvo_set_mode(struct drm_bridge *bridge,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct sti_dvo *dvo = bridge->driver_private;
struct sti_mixer *mixer = to_sti_mixer(dvo->encoder->crtc);
int rate = mode->clock * 1000;
struct clk *clkp;
int ret;
DRM_DEBUG_DRIVER("\n");
memcpy(&dvo->mode, mode, sizeof(struct drm_display_mode));
if (mixer->id == STI_MIXER_MAIN)
clkp = dvo->clk_main_parent;
else
clkp = dvo->clk_aux_parent;
if (clkp) {
clk_set_parent(dvo->clk_pix, clkp);
clk_set_parent(dvo->clk, clkp);
}
ret = clk_set_rate(dvo->clk_pix, rate);
if (ret < 0) {
DRM_ERROR("Cannot set rate (%dHz) for dvo_pix clk\n", rate);
return;
}
ret = clk_set_rate(dvo->clk, rate);
if (ret < 0) {
DRM_ERROR("Cannot set rate (%dHz) for dvo clk\n", rate);
return;
}
dvo->config = &rgb_24bit_de_cfg;
}
static void sti_dvo_bridge_nope(struct drm_bridge *bridge)
{
}
static int sti_dvo_connector_get_modes(struct drm_connector *connector)
{
struct sti_dvo_connector *dvo_connector
= to_sti_dvo_connector(connector);
struct sti_dvo *dvo = dvo_connector->dvo;
if (dvo->panel)
return dvo->panel->funcs->get_modes(dvo->panel);
return 0;
}
static int sti_dvo_connector_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
int target = mode->clock * 1000;
int target_min = target - CLK_TOLERANCE_HZ;
int target_max = target + CLK_TOLERANCE_HZ;
int result;
struct sti_dvo_connector *dvo_connector
= to_sti_dvo_connector(connector);
struct sti_dvo *dvo = dvo_connector->dvo;
result = clk_round_rate(dvo->clk_pix, target);
DRM_DEBUG_DRIVER("target rate = %d => available rate = %d\n",
target, result);
if ((result < target_min) || (result > target_max)) {
DRM_DEBUG_DRIVER("dvo pixclk=%d not supported\n", target);
return MODE_BAD;
}
return MODE_OK;
}
static enum drm_connector_status
sti_dvo_connector_detect(struct drm_connector *connector, bool force)
{
struct sti_dvo_connector *dvo_connector
= to_sti_dvo_connector(connector);
struct sti_dvo *dvo = dvo_connector->dvo;
DRM_DEBUG_DRIVER("\n");
if (!dvo->panel) {
dvo->panel = of_drm_find_panel(dvo->panel_node);
if (dvo->panel)
drm_panel_attach(dvo->panel, connector);
}
if (dvo->panel)
return connector_status_connected;
return connector_status_disconnected;
}
static int sti_dvo_late_register(struct drm_connector *connector)
{
struct sti_dvo_connector *dvo_connector
= to_sti_dvo_connector(connector);
struct sti_dvo *dvo = dvo_connector->dvo;
if (dvo_debugfs_init(dvo, dvo->drm_dev->primary)) {
DRM_ERROR("DVO debugfs setup failed\n");
return -EINVAL;
}
return 0;
}
static struct drm_encoder *sti_dvo_find_encoder(struct drm_device *dev)
{
struct drm_encoder *encoder;
list_for_each_entry(encoder, &dev->mode_config.encoder_list, head) {
if (encoder->encoder_type == DRM_MODE_ENCODER_LVDS)
return encoder;
}
return NULL;
}
static int sti_dvo_bind(struct device *dev, struct device *master, void *data)
{
struct sti_dvo *dvo = dev_get_drvdata(dev);
struct drm_device *drm_dev = data;
struct drm_encoder *encoder;
struct sti_dvo_connector *connector;
struct drm_connector *drm_connector;
struct drm_bridge *bridge;
int err;
dvo->drm_dev = drm_dev;
encoder = sti_dvo_find_encoder(drm_dev);
if (!encoder)
return -ENOMEM;
connector = devm_kzalloc(dev, sizeof(*connector), GFP_KERNEL);
if (!connector)
return -ENOMEM;
connector->dvo = dvo;
bridge = devm_kzalloc(dev, sizeof(*bridge), GFP_KERNEL);
if (!bridge)
return -ENOMEM;
bridge->driver_private = dvo;
bridge->funcs = &sti_dvo_bridge_funcs;
bridge->of_node = dvo->dev.of_node;
err = drm_bridge_add(bridge);
if (err) {
DRM_ERROR("Failed to add bridge\n");
return err;
}
err = drm_bridge_attach(encoder, bridge, NULL);
if (err) {
DRM_ERROR("Failed to attach bridge\n");
return err;
}
dvo->bridge = bridge;
connector->encoder = encoder;
dvo->encoder = encoder;
drm_connector = (struct drm_connector *)connector;
drm_connector->polled = DRM_CONNECTOR_POLL_HPD;
drm_connector_init(drm_dev, drm_connector,
&sti_dvo_connector_funcs, DRM_MODE_CONNECTOR_LVDS);
drm_connector_helper_add(drm_connector,
&sti_dvo_connector_helper_funcs);
err = drm_mode_connector_attach_encoder(drm_connector, encoder);
if (err) {
DRM_ERROR("Failed to attach a connector to a encoder\n");
goto err_sysfs;
}
return 0;
err_sysfs:
drm_bridge_remove(bridge);
return -EINVAL;
}
static void sti_dvo_unbind(struct device *dev,
struct device *master, void *data)
{
struct sti_dvo *dvo = dev_get_drvdata(dev);
drm_bridge_remove(dvo->bridge);
}
static int sti_dvo_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct sti_dvo *dvo;
struct resource *res;
struct device_node *np = dev->of_node;
DRM_INFO("%s\n", __func__);
dvo = devm_kzalloc(dev, sizeof(*dvo), GFP_KERNEL);
if (!dvo) {
DRM_ERROR("Failed to allocate memory for DVO\n");
return -ENOMEM;
}
dvo->dev = pdev->dev;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "dvo-reg");
if (!res) {
DRM_ERROR("Invalid dvo resource\n");
return -ENOMEM;
}
dvo->regs = devm_ioremap_nocache(dev, res->start,
resource_size(res));
if (!dvo->regs)
return -ENOMEM;
dvo->clk_pix = devm_clk_get(dev, "dvo_pix");
if (IS_ERR(dvo->clk_pix)) {
DRM_ERROR("Cannot get dvo_pix clock\n");
return PTR_ERR(dvo->clk_pix);
}
dvo->clk = devm_clk_get(dev, "dvo");
if (IS_ERR(dvo->clk)) {
DRM_ERROR("Cannot get dvo clock\n");
return PTR_ERR(dvo->clk);
}
dvo->clk_main_parent = devm_clk_get(dev, "main_parent");
if (IS_ERR(dvo->clk_main_parent)) {
DRM_DEBUG_DRIVER("Cannot get main_parent clock\n");
dvo->clk_main_parent = NULL;
}
dvo->clk_aux_parent = devm_clk_get(dev, "aux_parent");
if (IS_ERR(dvo->clk_aux_parent)) {
DRM_DEBUG_DRIVER("Cannot get aux_parent clock\n");
dvo->clk_aux_parent = NULL;
}
dvo->panel_node = of_parse_phandle(np, "sti,panel", 0);
if (!dvo->panel_node)
DRM_ERROR("No panel associated to the dvo output\n");
of_node_put(dvo->panel_node);
platform_set_drvdata(pdev, dvo);
return component_add(&pdev->dev, &sti_dvo_ops);
}
static int sti_dvo_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &sti_dvo_ops);
return 0;
}
