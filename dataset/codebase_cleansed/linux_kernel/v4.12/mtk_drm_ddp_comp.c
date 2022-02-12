static inline struct mtk_disp_color *comp_to_color(struct mtk_ddp_comp *comp)
{
return container_of(comp, struct mtk_disp_color, ddp_comp);
}
void mtk_dither_set(struct mtk_ddp_comp *comp, unsigned int bpc,
unsigned int CFG)
{
if (bpc == 0)
return;
if (bpc >= MTK_MIN_BPC) {
writel(0, comp->regs + DISP_DITHER_5);
writel(0, comp->regs + DISP_DITHER_7);
writel(DITHER_LSB_ERR_SHIFT_R(MTK_MAX_BPC - bpc) |
DITHER_ADD_LSHIFT_R(MTK_MAX_BPC - bpc) |
DITHER_NEW_BIT_MODE,
comp->regs + DISP_DITHER_15);
writel(DITHER_LSB_ERR_SHIFT_B(MTK_MAX_BPC - bpc) |
DITHER_ADD_LSHIFT_B(MTK_MAX_BPC - bpc) |
DITHER_LSB_ERR_SHIFT_G(MTK_MAX_BPC - bpc) |
DITHER_ADD_LSHIFT_G(MTK_MAX_BPC - bpc),
comp->regs + DISP_DITHER_16);
writel(DISP_DITHERING, comp->regs + CFG);
}
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
static void mtk_od_config(struct mtk_ddp_comp *comp, unsigned int w,
unsigned int h, unsigned int vrefresh,
unsigned int bpc)
{
writel(w << 16 | h, comp->regs + DISP_OD_SIZE);
writel(OD_RELAYMODE, comp->regs + DISP_OD_CFG);
mtk_dither_set(comp, bpc, DISP_OD_CFG);
}
static void mtk_od_start(struct mtk_ddp_comp *comp)
{
writel(1, comp->regs + DISP_OD_EN);
}
static void mtk_ufoe_start(struct mtk_ddp_comp *comp)
{
writel(UFO_BYPASS, comp->regs + DISP_REG_UFO_START);
}
static void mtk_aal_config(struct mtk_ddp_comp *comp, unsigned int w,
unsigned int h, unsigned int vrefresh,
unsigned int bpc)
{
writel(h << 16 | w, comp->regs + DISP_AAL_SIZE);
}
static void mtk_aal_start(struct mtk_ddp_comp *comp)
{
writel(AAL_EN, comp->regs + DISP_AAL_EN);
}
static void mtk_aal_stop(struct mtk_ddp_comp *comp)
{
writel_relaxed(0x0, comp->regs + DISP_AAL_EN);
}
static void mtk_gamma_config(struct mtk_ddp_comp *comp, unsigned int w,
unsigned int h, unsigned int vrefresh,
unsigned int bpc)
{
writel(h << 16 | w, comp->regs + DISP_GAMMA_SIZE);
mtk_dither_set(comp, bpc, DISP_GAMMA_CFG);
}
static void mtk_gamma_start(struct mtk_ddp_comp *comp)
{
writel(GAMMA_EN, comp->regs + DISP_GAMMA_EN);
}
static void mtk_gamma_stop(struct mtk_ddp_comp *comp)
{
writel_relaxed(0x0, comp->regs + DISP_GAMMA_EN);
}
static void mtk_gamma_set(struct mtk_ddp_comp *comp,
struct drm_crtc_state *state)
{
unsigned int i, reg;
struct drm_color_lut *lut;
void __iomem *lut_base;
u32 word;
if (state->gamma_lut) {
reg = readl(comp->regs + DISP_GAMMA_CFG);
reg = reg | GAMMA_LUT_EN;
writel(reg, comp->regs + DISP_GAMMA_CFG);
lut_base = comp->regs + DISP_GAMMA_LUT;
lut = (struct drm_color_lut *)state->gamma_lut->data;
for (i = 0; i < MTK_LUT_SIZE; i++) {
word = (((lut[i].red >> 6) & LUT_10BIT_MASK) << 20) +
(((lut[i].green >> 6) & LUT_10BIT_MASK) << 10) +
((lut[i].blue >> 6) & LUT_10BIT_MASK);
writel(word, (lut_base + i * 4));
}
}
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
const struct of_device_id *match;
struct mtk_disp_color *color;
if (comp_id < 0 || comp_id >= DDP_COMPONENT_ID_MAX)
return -EINVAL;
type = mtk_ddp_matches[comp_id].type;
if (type == MTK_DISP_COLOR) {
devm_kfree(dev, comp);
color = devm_kzalloc(dev, sizeof(*color), GFP_KERNEL);
if (!color)
return -ENOMEM;
match = of_match_node(mtk_disp_color_driver_dt_match, node);
color->data = match->data;
comp = &color->ddp_comp;
}
comp->id = comp_id;
comp->funcs = funcs ?: mtk_ddp_matches[comp_id].funcs;
if (comp_id == DDP_COMPONENT_BLS ||
comp_id == DDP_COMPONENT_DPI0 ||
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
