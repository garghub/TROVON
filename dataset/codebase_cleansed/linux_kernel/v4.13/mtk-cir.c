static void mtk_w32_mask(struct mtk_ir *ir, u32 val, u32 mask, unsigned int reg)
{
u32 tmp;
tmp = __raw_readl(ir->base + reg);
tmp = (tmp & ~mask) | val;
__raw_writel(tmp, ir->base + reg);
}
static void mtk_w32(struct mtk_ir *ir, u32 val, unsigned int reg)
{
__raw_writel(val, ir->base + reg);
}
static u32 mtk_r32(struct mtk_ir *ir, unsigned int reg)
{
return __raw_readl(ir->base + reg);
}
static inline void mtk_irq_disable(struct mtk_ir *ir, u32 mask)
{
u32 val;
val = mtk_r32(ir, MTK_IRINT_EN_REG);
mtk_w32(ir, val & ~mask, MTK_IRINT_EN_REG);
}
static inline void mtk_irq_enable(struct mtk_ir *ir, u32 mask)
{
u32 val;
val = mtk_r32(ir, MTK_IRINT_EN_REG);
mtk_w32(ir, val | mask, MTK_IRINT_EN_REG);
}
static irqreturn_t mtk_ir_irq(int irqno, void *dev_id)
{
struct mtk_ir *ir = dev_id;
u8 wid = 0;
u32 i, j, val;
DEFINE_IR_RAW_EVENT(rawir);
ir_raw_event_reset(ir->rc);
rawir.pulse = false;
for (i = 0 ; i < MTK_CHKDATA_SZ ; i++) {
val = mtk_r32(ir, MTK_CHKDATA_REG(i));
dev_dbg(ir->dev, "@reg%d=0x%08x\n", i, val);
for (j = 0 ; j < 4 ; j++) {
wid = (val & (MTK_WIDTH_MASK << j * 8)) >> j * 8;
rawir.pulse = !rawir.pulse;
rawir.duration = wid * (MTK_IR_SAMPLE + 1);
ir_raw_event_store_with_filter(ir->rc, &rawir);
}
}
if (!MTK_IR_END(wid, rawir.pulse)) {
rawir.pulse = false;
rawir.duration = MTK_MAX_SAMPLES * (MTK_IR_SAMPLE + 1);
ir_raw_event_store_with_filter(ir->rc, &rawir);
}
ir_raw_event_handle(ir->rc);
mtk_w32_mask(ir, 0x1, MTK_IRCLR, MTK_IRCLR_REG);
mtk_w32_mask(ir, 0x1, MTK_IRINT_CLR, MTK_IRINT_CLR_REG);
return IRQ_HANDLED;
}
static int mtk_ir_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *dn = dev->of_node;
struct resource *res;
struct mtk_ir *ir;
u32 val;
int ret = 0;
const char *map_name;
ir = devm_kzalloc(dev, sizeof(struct mtk_ir), GFP_KERNEL);
if (!ir)
return -ENOMEM;
ir->dev = dev;
if (!of_device_is_compatible(dn, "mediatek,mt7623-cir"))
return -ENODEV;
ir->clk = devm_clk_get(dev, "clk");
if (IS_ERR(ir->clk)) {
dev_err(dev, "failed to get a ir clock.\n");
return PTR_ERR(ir->clk);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ir->base = devm_ioremap_resource(dev, res);
if (IS_ERR(ir->base)) {
dev_err(dev, "failed to map registers\n");
return PTR_ERR(ir->base);
}
ir->rc = devm_rc_allocate_device(dev, RC_DRIVER_IR_RAW);
if (!ir->rc) {
dev_err(dev, "failed to allocate device\n");
return -ENOMEM;
}
ir->rc->priv = ir;
ir->rc->input_name = MTK_IR_DEV;
ir->rc->input_phys = MTK_IR_DEV "/input0";
ir->rc->input_id.bustype = BUS_HOST;
ir->rc->input_id.vendor = 0x0001;
ir->rc->input_id.product = 0x0001;
ir->rc->input_id.version = 0x0001;
map_name = of_get_property(dn, "linux,rc-map-name", NULL);
ir->rc->map_name = map_name ?: RC_MAP_EMPTY;
ir->rc->dev.parent = dev;
ir->rc->driver_name = MTK_IR_DEV;
ir->rc->allowed_protocols = RC_BIT_ALL;
ir->rc->rx_resolution = MTK_IR_SAMPLE;
ir->rc->timeout = MTK_MAX_SAMPLES * (MTK_IR_SAMPLE + 1);
ret = devm_rc_register_device(dev, ir->rc);
if (ret) {
dev_err(dev, "failed to register rc device\n");
return ret;
}
platform_set_drvdata(pdev, ir);
ir->irq = platform_get_irq(pdev, 0);
if (ir->irq < 0) {
dev_err(dev, "no irq resource\n");
return -ENODEV;
}
if (clk_prepare_enable(ir->clk)) {
dev_err(dev, "try to enable ir_clk failed\n");
ret = -EINVAL;
goto exit_clkdisable_clk;
}
mtk_irq_disable(ir, MTK_IRINT_EN);
ret = devm_request_irq(dev, ir->irq, mtk_ir_irq, 0, MTK_IR_DEV, ir);
if (ret) {
dev_err(dev, "failed request irq\n");
goto exit_clkdisable_clk;
}
val = mtk_r32(ir, MTK_CONFIG_HIGH_REG);
val |= MTK_PWM_EN | MTK_IR_EN;
mtk_w32(ir, val, MTK_CONFIG_HIGH_REG);
mtk_w32_mask(ir, MTK_CHK_PERIOD, MTK_CHK_PERIOD_MASK,
MTK_CONFIG_LOW_REG);
mtk_irq_enable(ir, MTK_IRINT_EN);
dev_info(dev, "Initialized MT7623 IR driver, sample period = %luus\n",
DIV_ROUND_CLOSEST(MTK_IR_SAMPLE, 1000));
return 0;
exit_clkdisable_clk:
clk_disable_unprepare(ir->clk);
return ret;
}
static int mtk_ir_remove(struct platform_device *pdev)
{
struct mtk_ir *ir = platform_get_drvdata(pdev);
mtk_irq_disable(ir, MTK_IRINT_EN);
synchronize_irq(ir->irq);
clk_disable_unprepare(ir->clk);
return 0;
}
