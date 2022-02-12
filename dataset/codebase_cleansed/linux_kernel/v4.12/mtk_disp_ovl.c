static inline struct mtk_disp_ovl *comp_to_ovl(struct mtk_ddp_comp *comp)
{
return container_of(comp, struct mtk_disp_ovl, ddp_comp);
}
static irqreturn_t mtk_disp_ovl_irq_handler(int irq, void *dev_id)
{
struct mtk_disp_ovl *priv = dev_id;
struct mtk_ddp_comp *ovl = &priv->ddp_comp;
writel(0x0, ovl->regs + DISP_REG_OVL_INTSTA);
if (!priv->crtc)
return IRQ_NONE;
mtk_crtc_ddp_irq(priv->crtc, ovl);
return IRQ_HANDLED;
}
static void mtk_ovl_enable_vblank(struct mtk_ddp_comp *comp,
struct drm_crtc *crtc)
{
struct mtk_disp_ovl *ovl = comp_to_ovl(comp);
ovl->crtc = crtc;
writel(0x0, comp->regs + DISP_REG_OVL_INTSTA);
writel_relaxed(OVL_FME_CPL_INT, comp->regs + DISP_REG_OVL_INTEN);
}
static void mtk_ovl_disable_vblank(struct mtk_ddp_comp *comp)
{
struct mtk_disp_ovl *ovl = comp_to_ovl(comp);
ovl->crtc = NULL;
writel_relaxed(0x0, comp->regs + DISP_REG_OVL_INTEN);
}
static void mtk_ovl_start(struct mtk_ddp_comp *comp)
{
writel_relaxed(0x1, comp->regs + DISP_REG_OVL_EN);
}
static void mtk_ovl_stop(struct mtk_ddp_comp *comp)
{
writel_relaxed(0x0, comp->regs + DISP_REG_OVL_EN);
}
static void mtk_ovl_config(struct mtk_ddp_comp *comp, unsigned int w,
unsigned int h, unsigned int vrefresh,
unsigned int bpc)
{
if (w != 0 && h != 0)
writel_relaxed(h << 16 | w, comp->regs + DISP_REG_OVL_ROI_SIZE);
writel_relaxed(0x0, comp->regs + DISP_REG_OVL_ROI_BGCLR);
writel(0x1, comp->regs + DISP_REG_OVL_RST);
writel(0x0, comp->regs + DISP_REG_OVL_RST);
}
static void mtk_ovl_layer_on(struct mtk_ddp_comp *comp, unsigned int idx)
{
unsigned int reg;
writel(0x1, comp->regs + DISP_REG_OVL_RDMA_CTRL(idx));
writel(OVL_RDMA_MEM_GMC, comp->regs + DISP_REG_OVL_RDMA_GMC(idx));
reg = readl(comp->regs + DISP_REG_OVL_SRC_CON);
reg = reg | BIT(idx);
writel(reg, comp->regs + DISP_REG_OVL_SRC_CON);
}
static void mtk_ovl_layer_off(struct mtk_ddp_comp *comp, unsigned int idx)
{
unsigned int reg;
reg = readl(comp->regs + DISP_REG_OVL_SRC_CON);
reg = reg & ~BIT(idx);
writel(reg, comp->regs + DISP_REG_OVL_SRC_CON);
writel(0x0, comp->regs + DISP_REG_OVL_RDMA_CTRL(idx));
}
static unsigned int ovl_fmt_convert(struct mtk_disp_ovl *ovl, unsigned int fmt)
{
switch (fmt) {
default:
case DRM_FORMAT_RGB565:
return OVL_CON_CLRFMT_RGB565(ovl);
case DRM_FORMAT_BGR565:
return OVL_CON_CLRFMT_RGB565(ovl) | OVL_CON_BYTE_SWAP;
case DRM_FORMAT_RGB888:
return OVL_CON_CLRFMT_RGB888(ovl);
case DRM_FORMAT_BGR888:
return OVL_CON_CLRFMT_RGB888(ovl) | OVL_CON_BYTE_SWAP;
case DRM_FORMAT_RGBX8888:
case DRM_FORMAT_RGBA8888:
return OVL_CON_CLRFMT_ARGB8888;
case DRM_FORMAT_BGRX8888:
case DRM_FORMAT_BGRA8888:
return OVL_CON_CLRFMT_ARGB8888 | OVL_CON_BYTE_SWAP;
case DRM_FORMAT_XRGB8888:
case DRM_FORMAT_ARGB8888:
return OVL_CON_CLRFMT_RGBA8888;
case DRM_FORMAT_XBGR8888:
case DRM_FORMAT_ABGR8888:
return OVL_CON_CLRFMT_RGBA8888 | OVL_CON_BYTE_SWAP;
}
}
static void mtk_ovl_layer_config(struct mtk_ddp_comp *comp, unsigned int idx,
struct mtk_plane_state *state)
{
struct mtk_disp_ovl *ovl = comp_to_ovl(comp);
struct mtk_plane_pending_state *pending = &state->pending;
unsigned int addr = pending->addr;
unsigned int pitch = pending->pitch & 0xffff;
unsigned int fmt = pending->format;
unsigned int offset = (pending->y << 16) | pending->x;
unsigned int src_size = (pending->height << 16) | pending->width;
unsigned int con;
if (!pending->enable)
mtk_ovl_layer_off(comp, idx);
con = ovl_fmt_convert(ovl, fmt);
if (idx != 0)
con |= OVL_CON_AEN | OVL_CON_ALPHA;
writel_relaxed(con, comp->regs + DISP_REG_OVL_CON(idx));
writel_relaxed(pitch, comp->regs + DISP_REG_OVL_PITCH(idx));
writel_relaxed(src_size, comp->regs + DISP_REG_OVL_SRC_SIZE(idx));
writel_relaxed(offset, comp->regs + DISP_REG_OVL_OFFSET(idx));
writel_relaxed(addr, comp->regs + DISP_REG_OVL_ADDR(ovl, idx));
if (pending->enable)
mtk_ovl_layer_on(comp, idx);
}
static int mtk_disp_ovl_bind(struct device *dev, struct device *master,
void *data)
{
struct mtk_disp_ovl *priv = dev_get_drvdata(dev);
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
static void mtk_disp_ovl_unbind(struct device *dev, struct device *master,
void *data)
{
struct mtk_disp_ovl *priv = dev_get_drvdata(dev);
struct drm_device *drm_dev = data;
mtk_ddp_comp_unregister(drm_dev, &priv->ddp_comp);
}
static int mtk_disp_ovl_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct mtk_disp_ovl *priv;
int comp_id;
int irq;
int ret;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
comp_id = mtk_ddp_comp_get_id(dev->of_node, MTK_DISP_OVL);
if (comp_id < 0) {
dev_err(dev, "Failed to identify by alias: %d\n", comp_id);
return comp_id;
}
ret = mtk_ddp_comp_init(dev, dev->of_node, &priv->ddp_comp, comp_id,
&mtk_disp_ovl_funcs);
if (ret) {
dev_err(dev, "Failed to initialize component: %d\n", ret);
return ret;
}
priv->data = of_device_get_match_data(dev);
platform_set_drvdata(pdev, priv);
ret = devm_request_irq(dev, irq, mtk_disp_ovl_irq_handler,
IRQF_TRIGGER_NONE, dev_name(dev), priv);
if (ret < 0) {
dev_err(dev, "Failed to request irq %d: %d\n", irq, ret);
return ret;
}
ret = component_add(dev, &mtk_disp_ovl_component_ops);
if (ret)
dev_err(dev, "Failed to add component: %d\n", ret);
return ret;
}
static int mtk_disp_ovl_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &mtk_disp_ovl_component_ops);
return 0;
}
