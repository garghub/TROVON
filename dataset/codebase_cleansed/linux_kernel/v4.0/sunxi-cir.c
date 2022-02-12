static irqreturn_t sunxi_ir_irq(int irqno, void *dev_id)
{
unsigned long status;
unsigned char dt;
unsigned int cnt, rc;
struct sunxi_ir *ir = dev_id;
DEFINE_IR_RAW_EVENT(rawir);
spin_lock(&ir->ir_lock);
status = readl(ir->base + SUNXI_IR_RXSTA_REG);
writel(status | REG_RXSTA_CLEARALL, ir->base + SUNXI_IR_RXSTA_REG);
if (status & (REG_RXINT_RAI_EN | REG_RXINT_RPEI_EN)) {
rc = REG_RXSTA_GET_AC(status);
rc = rc > ir->fifo_size ? ir->fifo_size : rc;
for (cnt = 0; cnt < rc; cnt++) {
dt = readb(ir->base + SUNXI_IR_RXFIFO_REG);
rawir.pulse = (dt & 0x80) != 0;
rawir.duration = ((dt & 0x7f) + 1) * SUNXI_IR_SAMPLE;
ir_raw_event_store_with_filter(ir->rc, &rawir);
}
}
if (status & REG_RXINT_ROI_EN) {
ir_raw_event_reset(ir->rc);
} else if (status & REG_RXINT_RPEI_EN) {
ir_raw_event_set_idle(ir->rc, true);
ir_raw_event_handle(ir->rc);
}
spin_unlock(&ir->ir_lock);
return IRQ_HANDLED;
}
static int sunxi_ir_probe(struct platform_device *pdev)
{
int ret = 0;
unsigned long tmp = 0;
struct device *dev = &pdev->dev;
struct device_node *dn = dev->of_node;
struct resource *res;
struct sunxi_ir *ir;
ir = devm_kzalloc(dev, sizeof(struct sunxi_ir), GFP_KERNEL);
if (!ir)
return -ENOMEM;
if (of_device_is_compatible(dn, "allwinner,sun5i-a13-ir"))
ir->fifo_size = 64;
else
ir->fifo_size = 16;
ir->apb_clk = devm_clk_get(dev, "apb");
if (IS_ERR(ir->apb_clk)) {
dev_err(dev, "failed to get a apb clock.\n");
return PTR_ERR(ir->apb_clk);
}
ir->clk = devm_clk_get(dev, "ir");
if (IS_ERR(ir->clk)) {
dev_err(dev, "failed to get a ir clock.\n");
return PTR_ERR(ir->clk);
}
ir->rst = devm_reset_control_get_optional(dev, NULL);
if (IS_ERR(ir->rst)) {
ret = PTR_ERR(ir->rst);
if (ret == -EPROBE_DEFER)
return ret;
ir->rst = NULL;
} else {
ret = reset_control_deassert(ir->rst);
if (ret)
return ret;
}
ret = clk_set_rate(ir->clk, SUNXI_IR_BASE_CLK);
if (ret) {
dev_err(dev, "set ir base clock failed!\n");
goto exit_reset_assert;
}
if (clk_prepare_enable(ir->apb_clk)) {
dev_err(dev, "try to enable apb_ir_clk failed\n");
ret = -EINVAL;
goto exit_reset_assert;
}
if (clk_prepare_enable(ir->clk)) {
dev_err(dev, "try to enable ir_clk failed\n");
ret = -EINVAL;
goto exit_clkdisable_apb_clk;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ir->base = devm_ioremap_resource(dev, res);
if (IS_ERR(ir->base)) {
dev_err(dev, "failed to map registers\n");
ret = PTR_ERR(ir->base);
goto exit_clkdisable_clk;
}
ir->rc = rc_allocate_device();
if (!ir->rc) {
dev_err(dev, "failed to allocate device\n");
ret = -ENOMEM;
goto exit_clkdisable_clk;
}
ir->rc->priv = ir;
ir->rc->input_name = SUNXI_IR_DEV;
ir->rc->input_phys = "sunxi-ir/input0";
ir->rc->input_id.bustype = BUS_HOST;
ir->rc->input_id.vendor = 0x0001;
ir->rc->input_id.product = 0x0001;
ir->rc->input_id.version = 0x0100;
ir->map_name = of_get_property(dn, "linux,rc-map-name", NULL);
ir->rc->map_name = ir->map_name ?: RC_MAP_EMPTY;
ir->rc->dev.parent = dev;
ir->rc->driver_type = RC_DRIVER_IR_RAW;
ir->rc->allowed_protocols = RC_BIT_ALL;
ir->rc->rx_resolution = SUNXI_IR_SAMPLE;
ir->rc->timeout = MS_TO_NS(SUNXI_IR_TIMEOUT);
ir->rc->driver_name = SUNXI_IR_DEV;
ret = rc_register_device(ir->rc);
if (ret) {
dev_err(dev, "failed to register rc device\n");
goto exit_free_dev;
}
platform_set_drvdata(pdev, ir);
ir->irq = platform_get_irq(pdev, 0);
if (ir->irq < 0) {
dev_err(dev, "no irq resource\n");
ret = ir->irq;
goto exit_free_dev;
}
ret = devm_request_irq(dev, ir->irq, sunxi_ir_irq, 0, SUNXI_IR_DEV, ir);
if (ret) {
dev_err(dev, "failed request irq\n");
goto exit_free_dev;
}
writel(REG_CTL_MD, ir->base+SUNXI_IR_CTL_REG);
writel(REG_CIR_NTHR(SUNXI_IR_RXNOISE)|REG_CIR_ITHR(SUNXI_IR_RXIDLE),
ir->base + SUNXI_IR_CIR_REG);
writel(REG_RXCTL_RPPI, ir->base + SUNXI_IR_RXCTL_REG);
writel(REG_RXSTA_CLEARALL, ir->base + SUNXI_IR_RXSTA_REG);
writel(REG_RXINT_ROI_EN | REG_RXINT_RPEI_EN |
REG_RXINT_RAI_EN | REG_RXINT_RAL(ir->fifo_size / 2 - 1),
ir->base + SUNXI_IR_RXINT_REG);
tmp = readl(ir->base + SUNXI_IR_CTL_REG);
writel(tmp | REG_CTL_GEN | REG_CTL_RXEN, ir->base + SUNXI_IR_CTL_REG);
dev_info(dev, "initialized sunXi IR driver\n");
return 0;
exit_free_dev:
rc_free_device(ir->rc);
exit_clkdisable_clk:
clk_disable_unprepare(ir->clk);
exit_clkdisable_apb_clk:
clk_disable_unprepare(ir->apb_clk);
exit_reset_assert:
if (ir->rst)
reset_control_assert(ir->rst);
return ret;
}
static int sunxi_ir_remove(struct platform_device *pdev)
{
unsigned long flags;
struct sunxi_ir *ir = platform_get_drvdata(pdev);
clk_disable_unprepare(ir->clk);
clk_disable_unprepare(ir->apb_clk);
if (ir->rst)
reset_control_assert(ir->rst);
spin_lock_irqsave(&ir->ir_lock, flags);
writel(0, ir->base + SUNXI_IR_RXINT_REG);
writel(REG_RXSTA_CLEARALL, ir->base + SUNXI_IR_RXSTA_REG);
writel(0, ir->base + SUNXI_IR_CTL_REG);
spin_unlock_irqrestore(&ir->ir_lock, flags);
rc_unregister_device(ir->rc);
return 0;
}
