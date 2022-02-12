static void mtk_color_config(struct mtk_ddp_comp *comp, unsigned int w,
unsigned int h, unsigned int vrefresh)
{
writel(w, comp->regs + DISP_COLOR_WIDTH);
writel(h, comp->regs + DISP_COLOR_HEIGHT);
}
static void mtk_color_start(struct mtk_ddp_comp *comp)
{
writel(COLOR_BYPASS_ALL | COLOR_SEQ_SEL,
comp->regs + DISP_COLOR_CFG_MAIN);
writel(0x1, comp->regs + DISP_COLOR_START);
}
static void mtk_od_config(struct mtk_ddp_comp *comp, unsigned int w,
unsigned int h, unsigned int vrefresh)
{
writel(w << 16 | h, comp->regs + DISP_OD_SIZE);
}
static void mtk_od_start(struct mtk_ddp_comp *comp)
{
writel(OD_RELAY_MODE, comp->regs + DISP_OD_CFG);
writel(1, comp->regs + DISP_OD_EN);
}
static void mtk_ufoe_start(struct mtk_ddp_comp *comp)
{
writel(UFO_BYPASS, comp->regs + DISP_REG_UFO_START);
}
int mtk_ddp_comp_get_id(struct device_node *node,
enum mtk_ddp_comp_type comp_type)
{
int id = of_alias_get_id(node, mtk_ddp_comp_stem[comp_type]);
int i;
for (i = 0; i < ARRAY_SIZE(mtk_ddp_matches); i++) {
if (comp_type == mtk_ddp_matches[i].type &&
(id < 0 || id == mtk_ddp_matches[i].alias_id))
return i;
}
return -EINVAL;
}
int mtk_ddp_comp_init(struct device *dev, struct device_node *node,
struct mtk_ddp_comp *comp, enum mtk_ddp_comp_id comp_id,
const struct mtk_ddp_comp_funcs *funcs)
{
enum mtk_ddp_comp_type type;
struct device_node *larb_node;
struct platform_device *larb_pdev;
if (comp_id < 0 || comp_id >= DDP_COMPONENT_ID_MAX)
return -EINVAL;
comp->id = comp_id;
comp->funcs = funcs ?: mtk_ddp_matches[comp_id].funcs;
if (comp_id == DDP_COMPONENT_DPI0 ||
comp_id == DDP_COMPONENT_DSI0 ||
comp_id == DDP_COMPONENT_PWM0) {
comp->regs = NULL;
comp->clk = NULL;
comp->irq = 0;
return 0;
}
comp->regs = of_iomap(node, 0);
comp->irq = of_irq_get(node, 0);
comp->clk = of_clk_get(node, 0);
if (IS_ERR(comp->clk))
comp->clk = NULL;
type = mtk_ddp_matches[comp_id].type;
comp->larb_dev = NULL;
if (type != MTK_DISP_OVL &&
type != MTK_DISP_RDMA &&
type != MTK_DISP_WDMA)
return 0;
larb_node = of_parse_phandle(node, "mediatek,larb", 0);
if (!larb_node) {
dev_err(dev,
"Missing mediadek,larb phandle in %s node\n",
node->full_name);
return -EINVAL;
}
larb_pdev = of_find_device_by_node(larb_node);
if (!larb_pdev) {
dev_warn(dev, "Waiting for larb device %s\n",
larb_node->full_name);
of_node_put(larb_node);
return -EPROBE_DEFER;
}
of_node_put(larb_node);
comp->larb_dev = &larb_pdev->dev;
return 0;
}
int mtk_ddp_comp_register(struct drm_device *drm, struct mtk_ddp_comp *comp)
{
struct mtk_drm_private *private = drm->dev_private;
if (private->ddp_comp[comp->id])
return -EBUSY;
private->ddp_comp[comp->id] = comp;
return 0;
}
void mtk_ddp_comp_unregister(struct drm_device *drm, struct mtk_ddp_comp *comp)
{
struct mtk_drm_private *private = drm->dev_private;
private->ddp_comp[comp->id] = NULL;
}
