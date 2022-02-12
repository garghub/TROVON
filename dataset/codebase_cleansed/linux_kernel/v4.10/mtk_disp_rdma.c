static irqreturn_t mtk_disp_rdma_irq_handler(int irq, void *dev_id)
{
struct mtk_disp_rdma *priv = dev_id;
struct mtk_ddp_comp *rdma = &priv->ddp_comp;
writel(0x0, rdma->regs + DISP_REG_RDMA_INT_STATUS);
if (!priv->crtc)
return IRQ_NONE;
mtk_crtc_ddp_irq(priv->crtc, rdma);
return IRQ_HANDLED;
}
static void rdma_update_bits(struct mtk_ddp_comp *comp, unsigned int reg,
unsigned int mask, unsigned int val)
{
unsigned int tmp = readl(comp->regs + reg);
tmp = (tmp & ~mask) | (val & mask);
writel(tmp, comp->regs + reg);
}
static void mtk_rdma_enable_vblank(struct mtk_ddp_comp *comp,
struct drm_crtc *crtc)
{
struct mtk_disp_rdma *priv = container_of(comp, struct mtk_disp_rdma,
ddp_comp);
priv->crtc = crtc;
rdma_update_bits(comp, DISP_REG_RDMA_INT_ENABLE, RDMA_FRAME_END_INT,
RDMA_FRAME_END_INT);
}
static void mtk_rdma_disable_vblank(struct mtk_ddp_comp *comp)
{
struct mtk_disp_rdma *priv = container_of(comp, struct mtk_disp_rdma,
ddp_comp);
priv->crtc = NULL;
rdma_update_bits(comp, DISP_REG_RDMA_INT_ENABLE, RDMA_FRAME_END_INT, 0);
}
static void mtk_rdma_start(struct mtk_ddp_comp *comp)
{
rdma_update_bits(comp, DISP_REG_RDMA_GLOBAL_CON, RDMA_ENGINE_EN,
RDMA_ENGINE_EN);
}
static void mtk_rdma_stop(struct mtk_ddp_comp *comp)
{
rdma_update_bits(comp, DISP_REG_RDMA_GLOBAL_CON, RDMA_ENGINE_EN, 0);
}
static void mtk_rdma_config(struct mtk_ddp_comp *comp, unsigned int width,
unsigned int height, unsigned int vrefresh,
unsigned int bpc)
{
unsigned int threshold;
unsigned int reg;
rdma_update_bits(comp, DISP_REG_RDMA_SIZE_CON_0, 0xfff, width);
rdma_update_bits(comp, DISP_REG_RDMA_SIZE_CON_1, 0xfffff, height);
threshold = width * height * vrefresh * 4 * 7 / 1000000;
reg = RDMA_FIFO_UNDERFLOW_EN |
RDMA_FIFO_PSEUDO_SIZE(SZ_8K) |
RDMA_OUTPUT_VALID_FIFO_THRESHOLD(threshold);
writel(reg, comp->regs + DISP_REG_RDMA_FIFO_CON);
}
static int mtk_disp_rdma_bind(struct device *dev, struct device *master,
void *data)
{
struct mtk_disp_rdma *priv = dev_get_drvdata(dev);
struct drm_device *drm_dev = data;
int ret;
ret = mtk_ddp_comp_register(drm_dev, &priv->ddp_comp);
if (ret < 0) {
dev_err(dev, "Failed to register component %s: %d\n",
dev->of_node->full_name, ret);
return ret;
}
return 0;
}
static void mtk_disp_rdma_unbind(struct device *dev, struct device *master,
void *data)
{
struct mtk_disp_rdma *priv = dev_get_drvdata(dev);
struct drm_device *drm_dev = data;
mtk_ddp_comp_unregister(drm_dev, &priv->ddp_comp);
}
static int mtk_disp_rdma_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct mtk_disp_rdma *priv;
int comp_id;
int irq;
int ret;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
comp_id = mtk_ddp_comp_get_id(dev->of_node, MTK_DISP_RDMA);
if (comp_id < 0) {
dev_err(dev, "Failed to identify by alias: %d\n", comp_id);
return comp_id;
}
ret = mtk_ddp_comp_init(dev, dev->of_node, &priv->ddp_comp, comp_id,
&mtk_disp_rdma_funcs);
if (ret) {
dev_err(dev, "Failed to initialize component: %d\n", ret);
return ret;
}
writel(0x0, priv->ddp_comp.regs + DISP_REG_RDMA_INT_ENABLE);
writel(0x0, priv->ddp_comp.regs + DISP_REG_RDMA_INT_STATUS);
ret = devm_request_irq(dev, irq, mtk_disp_rdma_irq_handler,
IRQF_TRIGGER_NONE, dev_name(dev), priv);
if (ret < 0) {
dev_err(dev, "Failed to request irq %d: %d\n", irq, ret);
return ret;
}
platform_set_drvdata(pdev, priv);
ret = component_add(dev, &mtk_disp_rdma_component_ops);
if (ret)
dev_err(dev, "Failed to add component: %d\n", ret);
return ret;
}
static int mtk_disp_rdma_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &mtk_disp_rdma_component_ops);
return 0;
}
