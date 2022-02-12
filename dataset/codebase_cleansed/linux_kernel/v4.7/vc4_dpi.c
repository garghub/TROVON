static inline struct vc4_dpi_encoder *
to_vc4_dpi_encoder(struct drm_encoder *encoder)
{
return container_of(encoder, struct vc4_dpi_encoder, base.base);
}
static inline struct vc4_dpi_connector *
to_vc4_dpi_connector(struct drm_connector *connector)
{
return container_of(connector, struct vc4_dpi_connector, base);
}
static void vc4_dpi_dump_regs(struct vc4_dpi *dpi)
{
int i;
for (i = 0; i < ARRAY_SIZE(dpi_regs); i++) {
DRM_INFO("0x%04x (%s): 0x%08x\n",
dpi_regs[i].reg, dpi_regs[i].name,
DPI_READ(dpi_regs[i].reg));
}
}
int vc4_dpi_debugfs_regs(struct seq_file *m, void *unused)
{
struct drm_info_node *node = (struct drm_info_node *)m->private;
struct drm_device *dev = node->minor->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
struct vc4_dpi *dpi = vc4->dpi;
int i;
if (!dpi)
return 0;
for (i = 0; i < ARRAY_SIZE(dpi_regs); i++) {
seq_printf(m, "%s (0x%04x): 0x%08x\n",
dpi_regs[i].name, dpi_regs[i].reg,
DPI_READ(dpi_regs[i].reg));
}
return 0;
}
static enum drm_connector_status
vc4_dpi_connector_detect(struct drm_connector *connector, bool force)
{
struct vc4_dpi_connector *vc4_connector =
to_vc4_dpi_connector(connector);
struct vc4_dpi *dpi = vc4_connector->dpi;
if (dpi->panel)
return connector_status_connected;
else
return connector_status_disconnected;
}
static void vc4_dpi_connector_destroy(struct drm_connector *connector)
{
drm_connector_unregister(connector);
drm_connector_cleanup(connector);
}
static int vc4_dpi_connector_get_modes(struct drm_connector *connector)
{
struct vc4_dpi_connector *vc4_connector =
to_vc4_dpi_connector(connector);
struct vc4_dpi *dpi = vc4_connector->dpi;
if (dpi->panel)
return drm_panel_get_modes(dpi->panel);
return 0;
}
static struct drm_encoder *
vc4_dpi_connector_best_encoder(struct drm_connector *connector)
{
struct vc4_dpi_connector *dpi_connector =
to_vc4_dpi_connector(connector);
return dpi_connector->encoder;
}
static struct drm_connector *vc4_dpi_connector_init(struct drm_device *dev,
struct vc4_dpi *dpi)
{
struct drm_connector *connector = NULL;
struct vc4_dpi_connector *dpi_connector;
int ret = 0;
dpi_connector = devm_kzalloc(dev->dev, sizeof(*dpi_connector),
GFP_KERNEL);
if (!dpi_connector) {
ret = -ENOMEM;
goto fail;
}
connector = &dpi_connector->base;
dpi_connector->encoder = dpi->encoder;
dpi_connector->dpi = dpi;
drm_connector_init(dev, connector, &vc4_dpi_connector_funcs,
DRM_MODE_CONNECTOR_DPI);
drm_connector_helper_add(connector, &vc4_dpi_connector_helper_funcs);
connector->polled = 0;
connector->interlace_allowed = 0;
connector->doublescan_allowed = 0;
drm_mode_connector_attach_encoder(connector, dpi->encoder);
return connector;
fail:
if (connector)
vc4_dpi_connector_destroy(connector);
return ERR_PTR(ret);
}
static void vc4_dpi_encoder_disable(struct drm_encoder *encoder)
{
struct vc4_dpi_encoder *vc4_encoder = to_vc4_dpi_encoder(encoder);
struct vc4_dpi *dpi = vc4_encoder->dpi;
drm_panel_disable(dpi->panel);
clk_disable_unprepare(dpi->pixel_clock);
drm_panel_unprepare(dpi->panel);
}
static void vc4_dpi_encoder_enable(struct drm_encoder *encoder)
{
struct drm_display_mode *mode = &encoder->crtc->mode;
struct vc4_dpi_encoder *vc4_encoder = to_vc4_dpi_encoder(encoder);
struct vc4_dpi *dpi = vc4_encoder->dpi;
u32 dpi_c = DPI_ENABLE | DPI_OUTPUT_ENABLE_MODE;
int ret;
ret = drm_panel_prepare(dpi->panel);
if (ret) {
DRM_ERROR("Panel failed to prepare\n");
return;
}
if (dpi->connector->display_info.num_bus_formats) {
u32 bus_format = dpi->connector->display_info.bus_formats[0];
switch (bus_format) {
case MEDIA_BUS_FMT_RGB888_1X24:
dpi_c |= VC4_SET_FIELD(DPI_FORMAT_24BIT_888_RGB,
DPI_FORMAT);
break;
case MEDIA_BUS_FMT_BGR888_1X24:
dpi_c |= VC4_SET_FIELD(DPI_FORMAT_24BIT_888_RGB,
DPI_FORMAT);
dpi_c |= VC4_SET_FIELD(DPI_ORDER_BGR, DPI_ORDER);
break;
case MEDIA_BUS_FMT_RGB666_1X24_CPADHI:
dpi_c |= VC4_SET_FIELD(DPI_FORMAT_18BIT_666_RGB_2,
DPI_FORMAT);
break;
case MEDIA_BUS_FMT_RGB666_1X18:
dpi_c |= VC4_SET_FIELD(DPI_FORMAT_18BIT_666_RGB_1,
DPI_FORMAT);
break;
case MEDIA_BUS_FMT_RGB565_1X16:
dpi_c |= VC4_SET_FIELD(DPI_FORMAT_16BIT_565_RGB_3,
DPI_FORMAT);
break;
default:
DRM_ERROR("Unknown media bus format %d\n", bus_format);
break;
}
}
if (mode->flags & DRM_MODE_FLAG_NHSYNC)
dpi_c |= DPI_HSYNC_INVERT;
else if (!(mode->flags & DRM_MODE_FLAG_PHSYNC))
dpi_c |= DPI_HSYNC_DISABLE;
if (mode->flags & DRM_MODE_FLAG_NVSYNC)
dpi_c |= DPI_VSYNC_INVERT;
else if (!(mode->flags & DRM_MODE_FLAG_PVSYNC))
dpi_c |= DPI_VSYNC_DISABLE;
DPI_WRITE(DPI_C, dpi_c);
ret = clk_set_rate(dpi->pixel_clock, mode->clock * 1000);
if (ret)
DRM_ERROR("Failed to set clock rate: %d\n", ret);
ret = clk_prepare_enable(dpi->pixel_clock);
if (ret)
DRM_ERROR("Failed to set clock rate: %d\n", ret);
ret = drm_panel_enable(dpi->panel);
if (ret) {
DRM_ERROR("Panel failed to enable\n");
drm_panel_unprepare(dpi->panel);
return;
}
}
static struct drm_panel *vc4_dpi_get_panel(struct device *dev)
{
struct device_node *endpoint, *panel_node;
struct device_node *np = dev->of_node;
struct drm_panel *panel;
endpoint = of_graph_get_next_endpoint(np, NULL);
if (!endpoint) {
dev_err(dev, "no endpoint to fetch DPI panel\n");
return NULL;
}
panel_node = of_graph_get_remote_port_parent(endpoint);
of_node_put(endpoint);
if (!panel_node) {
dev_err(dev, "no valid panel node\n");
return NULL;
}
panel = of_drm_find_panel(panel_node);
of_node_put(panel_node);
return panel;
}
static int vc4_dpi_bind(struct device *dev, struct device *master, void *data)
{
struct platform_device *pdev = to_platform_device(dev);
struct drm_device *drm = dev_get_drvdata(master);
struct vc4_dev *vc4 = to_vc4_dev(drm);
struct vc4_dpi *dpi;
struct vc4_dpi_encoder *vc4_dpi_encoder;
int ret;
dpi = devm_kzalloc(dev, sizeof(*dpi), GFP_KERNEL);
if (!dpi)
return -ENOMEM;
vc4_dpi_encoder = devm_kzalloc(dev, sizeof(*vc4_dpi_encoder),
GFP_KERNEL);
if (!vc4_dpi_encoder)
return -ENOMEM;
vc4_dpi_encoder->base.type = VC4_ENCODER_TYPE_DPI;
vc4_dpi_encoder->dpi = dpi;
dpi->encoder = &vc4_dpi_encoder->base.base;
dpi->pdev = pdev;
dpi->regs = vc4_ioremap_regs(pdev, 0);
if (IS_ERR(dpi->regs))
return PTR_ERR(dpi->regs);
vc4_dpi_dump_regs(dpi);
if (DPI_READ(DPI_ID) != DPI_ID_VALUE) {
dev_err(dev, "Port returned 0x%08x for ID instead of 0x%08x\n",
DPI_READ(DPI_ID), DPI_ID_VALUE);
return -ENODEV;
}
dpi->core_clock = devm_clk_get(dev, "core");
if (IS_ERR(dpi->core_clock)) {
ret = PTR_ERR(dpi->core_clock);
if (ret != -EPROBE_DEFER)
DRM_ERROR("Failed to get core clock: %d\n", ret);
return ret;
}
dpi->pixel_clock = devm_clk_get(dev, "pixel");
if (IS_ERR(dpi->pixel_clock)) {
ret = PTR_ERR(dpi->pixel_clock);
if (ret != -EPROBE_DEFER)
DRM_ERROR("Failed to get pixel clock: %d\n", ret);
return ret;
}
ret = clk_prepare_enable(dpi->core_clock);
if (ret)
DRM_ERROR("Failed to turn on core clock: %d\n", ret);
dpi->panel = vc4_dpi_get_panel(dev);
drm_encoder_init(drm, dpi->encoder, &vc4_dpi_encoder_funcs,
DRM_MODE_ENCODER_DPI, NULL);
drm_encoder_helper_add(dpi->encoder, &vc4_dpi_encoder_helper_funcs);
dpi->connector = vc4_dpi_connector_init(drm, dpi);
if (IS_ERR(dpi->connector)) {
ret = PTR_ERR(dpi->connector);
goto err_destroy_encoder;
}
if (dpi->panel)
drm_panel_attach(dpi->panel, dpi->connector);
dev_set_drvdata(dev, dpi);
vc4->dpi = dpi;
return 0;
err_destroy_encoder:
drm_encoder_cleanup(dpi->encoder);
clk_disable_unprepare(dpi->core_clock);
return ret;
}
static void vc4_dpi_unbind(struct device *dev, struct device *master,
void *data)
{
struct drm_device *drm = dev_get_drvdata(master);
struct vc4_dev *vc4 = to_vc4_dev(drm);
struct vc4_dpi *dpi = dev_get_drvdata(dev);
if (dpi->panel)
drm_panel_detach(dpi->panel);
vc4_dpi_connector_destroy(dpi->connector);
drm_encoder_cleanup(dpi->encoder);
clk_disable_unprepare(dpi->core_clock);
vc4->dpi = NULL;
}
static int vc4_dpi_dev_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &vc4_dpi_ops);
}
static int vc4_dpi_dev_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &vc4_dpi_ops);
return 0;
}
