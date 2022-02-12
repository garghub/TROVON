static inline struct mtk_disp_color *comp_to_color(struct mtk_ddp_comp *comp)
{
return container_of(comp, struct mtk_disp_color, ddp_comp);
}
static void mtk_color_config(struct mtk_ddp_comp *comp, unsigned int w,
unsigned int h, unsigned int vrefresh,
unsigned int bpc)
{
struct mtk_disp_color *color = comp_to_color(comp);
writel(w, comp->regs + DISP_COLOR_WIDTH(color));
writel(h, comp->regs + DISP_COLOR_HEIGHT(color));
}
static void mtk_color_start(struct mtk_ddp_comp *comp)
{
struct mtk_disp_color *color = comp_to_color(comp);
writel(COLOR_BYPASS_ALL | COLOR_SEQ_SEL,
comp->regs + DISP_COLOR_CFG_MAIN);
writel(0x1, comp->regs + DISP_COLOR_START(color));
}
static int mtk_disp_color_bind(struct device *dev, struct device *master,
void *data)
{
struct mtk_disp_color *priv = dev_get_drvdata(dev);
struct drm_device *drm_dev = data;
int ret;
ret = mtk_ddp_comp_register(drm_dev, &priv->ddp_comp);
if (ret < 0) {
dev_err(dev, "Failed to register component %pOF: %d\n",
dev->of_node, ret);
return ret;
}
return 0;
}
static void mtk_disp_color_unbind(struct device *dev, struct device *master,
void *data)
{
struct mtk_disp_color *priv = dev_get_drvdata(dev);
struct drm_device *drm_dev = data;
mtk_ddp_comp_unregister(drm_dev, &priv->ddp_comp);
}
static int mtk_disp_color_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct mtk_disp_color *priv;
int comp_id;
int ret;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
comp_id = mtk_ddp_comp_get_id(dev->of_node, MTK_DISP_COLOR);
if (comp_id < 0) {
dev_err(dev, "Failed to identify by alias: %d\n", comp_id);
return comp_id;
}
ret = mtk_ddp_comp_init(dev, dev->of_node, &priv->ddp_comp, comp_id,
&mtk_disp_color_funcs);
if (ret) {
dev_err(dev, "Failed to initialize component: %d\n", ret);
return ret;
}
priv->data = of_device_get_match_data(dev);
platform_set_drvdata(pdev, priv);
ret = component_add(dev, &mtk_disp_color_component_ops);
if (ret)
dev_err(dev, "Failed to add component: %d\n", ret);
return ret;
}
static int mtk_disp_color_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &mtk_disp_color_component_ops);
return 0;
}
