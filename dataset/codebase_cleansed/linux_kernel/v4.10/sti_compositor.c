int sti_compositor_debugfs_init(struct sti_compositor *compo,
struct drm_minor *minor)
{
unsigned int i;
for (i = 0; i < STI_MAX_VID; i++)
if (compo->vid[i])
vid_debugfs_init(compo->vid[i], minor);
for (i = 0; i < STI_MAX_MIXER; i++)
if (compo->mixer[i])
sti_mixer_debugfs_init(compo->mixer[i], minor);
return 0;
}
static int sti_compositor_bind(struct device *dev,
struct device *master,
void *data)
{
struct sti_compositor *compo = dev_get_drvdata(dev);
struct drm_device *drm_dev = data;
unsigned int i, mixer_id = 0, vid_id = 0, crtc_id = 0;
struct sti_private *dev_priv = drm_dev->dev_private;
struct drm_plane *cursor = NULL;
struct drm_plane *primary = NULL;
struct sti_compositor_subdev_descriptor *desc = compo->data.subdev_desc;
unsigned int array_size = compo->data.nb_subdev;
dev_priv->compo = compo;
for (i = 0; i < array_size; i++) {
switch (desc[i].type) {
case STI_VID_SUBDEV:
compo->vid[vid_id++] =
sti_vid_create(compo->dev, drm_dev, desc[i].id,
compo->regs + desc[i].offset);
break;
case STI_MIXER_MAIN_SUBDEV:
case STI_MIXER_AUX_SUBDEV:
compo->mixer[mixer_id++] =
sti_mixer_create(compo->dev, drm_dev, desc[i].id,
compo->regs + desc[i].offset);
break;
case STI_GPD_SUBDEV:
case STI_CURSOR_SUBDEV:
break;
default:
DRM_ERROR("Unknow subdev compoment type\n");
return 1;
}
}
for (i = 0; i < array_size; i++) {
enum drm_plane_type plane_type = DRM_PLANE_TYPE_OVERLAY;
if (crtc_id < mixer_id)
plane_type = DRM_PLANE_TYPE_PRIMARY;
switch (desc[i].type) {
case STI_MIXER_MAIN_SUBDEV:
case STI_MIXER_AUX_SUBDEV:
case STI_VID_SUBDEV:
break;
case STI_CURSOR_SUBDEV:
cursor = sti_cursor_create(drm_dev, compo->dev,
desc[i].id,
compo->regs + desc[i].offset,
1);
if (!cursor) {
DRM_ERROR("Can't create CURSOR plane\n");
break;
}
break;
case STI_GPD_SUBDEV:
primary = sti_gdp_create(drm_dev, compo->dev,
desc[i].id,
compo->regs + desc[i].offset,
(1 << mixer_id) - 1,
plane_type);
if (!primary) {
DRM_ERROR("Can't create GDP plane\n");
break;
}
break;
default:
DRM_ERROR("Unknown subdev compoment type\n");
return 1;
}
if (crtc_id < mixer_id && primary) {
sti_crtc_init(drm_dev, compo->mixer[crtc_id],
primary, cursor);
crtc_id++;
cursor = NULL;
primary = NULL;
}
}
drm_vblank_init(drm_dev, crtc_id);
drm_dev->irq_enabled = 1;
return 0;
}
static void sti_compositor_unbind(struct device *dev, struct device *master,
void *data)
{
}
static int sti_compositor_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct device_node *vtg_np;
struct sti_compositor *compo;
struct resource *res;
unsigned int i;
compo = devm_kzalloc(dev, sizeof(*compo), GFP_KERNEL);
if (!compo) {
DRM_ERROR("Failed to allocate compositor context\n");
return -ENOMEM;
}
compo->dev = dev;
for (i = 0; i < STI_MAX_MIXER; i++)
compo->vtg_vblank_nb[i].notifier_call = sti_crtc_vblank_cb;
BUG_ON(!of_match_node(compositor_of_match, np)->data);
memcpy(&compo->data, of_match_node(compositor_of_match, np)->data,
sizeof(struct sti_compositor_data));
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
DRM_ERROR("Get memory resource failed\n");
return -ENXIO;
}
compo->regs = devm_ioremap(dev, res->start, resource_size(res));
if (compo->regs == NULL) {
DRM_ERROR("Register mapping failed\n");
return -ENXIO;
}
compo->clk_compo_main = devm_clk_get(dev, "compo_main");
if (IS_ERR(compo->clk_compo_main)) {
DRM_ERROR("Cannot get compo_main clock\n");
return PTR_ERR(compo->clk_compo_main);
}
compo->clk_compo_aux = devm_clk_get(dev, "compo_aux");
if (IS_ERR(compo->clk_compo_aux)) {
DRM_ERROR("Cannot get compo_aux clock\n");
return PTR_ERR(compo->clk_compo_aux);
}
compo->clk_pix_main = devm_clk_get(dev, "pix_main");
if (IS_ERR(compo->clk_pix_main)) {
DRM_ERROR("Cannot get pix_main clock\n");
return PTR_ERR(compo->clk_pix_main);
}
compo->clk_pix_aux = devm_clk_get(dev, "pix_aux");
if (IS_ERR(compo->clk_pix_aux)) {
DRM_ERROR("Cannot get pix_aux clock\n");
return PTR_ERR(compo->clk_pix_aux);
}
compo->rst_main = devm_reset_control_get_shared(dev, "compo-main");
if (!IS_ERR(compo->rst_main))
reset_control_deassert(compo->rst_main);
compo->rst_aux = devm_reset_control_get_shared(dev, "compo-aux");
if (!IS_ERR(compo->rst_aux))
reset_control_deassert(compo->rst_aux);
vtg_np = of_parse_phandle(pdev->dev.of_node, "st,vtg", 0);
if (vtg_np)
compo->vtg[STI_MIXER_MAIN] = of_vtg_find(vtg_np);
of_node_put(vtg_np);
vtg_np = of_parse_phandle(pdev->dev.of_node, "st,vtg", 1);
if (vtg_np)
compo->vtg[STI_MIXER_AUX] = of_vtg_find(vtg_np);
of_node_put(vtg_np);
platform_set_drvdata(pdev, compo);
return component_add(&pdev->dev, &sti_compositor_ops);
}
static int sti_compositor_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &sti_compositor_ops);
return 0;
}
