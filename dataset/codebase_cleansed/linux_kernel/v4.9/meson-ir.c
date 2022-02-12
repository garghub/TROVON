static void meson_ir_set_mask(struct meson_ir *ir, unsigned int reg,
u32 mask, u32 value)
{
u32 data;
data = readl(ir->reg + reg);
data &= ~mask;
data |= (value & mask);
writel(data, ir->reg + reg);
}
static irqreturn_t meson_ir_irq(int irqno, void *dev_id)
{
struct meson_ir *ir = dev_id;
u32 duration;
DEFINE_IR_RAW_EVENT(rawir);
spin_lock(&ir->lock);
duration = readl(ir->reg + IR_DEC_REG1);
duration = (duration & REG1_TIME_IV_MASK) >> REG1_TIME_IV_SHIFT;
rawir.duration = US_TO_NS(duration * MESON_TRATE);
rawir.pulse = !!(readl(ir->reg + IR_DEC_STATUS) & STATUS_IR_DEC_IN);
ir_raw_event_store_with_filter(ir->rc, &rawir);
ir_raw_event_handle(ir->rc);
spin_unlock(&ir->lock);
return IRQ_HANDLED;
}
static int meson_ir_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node;
struct resource *res;
const char *map_name;
struct meson_ir *ir;
int ret;
ir = devm_kzalloc(dev, sizeof(struct meson_ir), GFP_KERNEL);
if (!ir)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ir->reg = devm_ioremap_resource(dev, res);
if (IS_ERR(ir->reg)) {
dev_err(dev, "failed to map registers\n");
return PTR_ERR(ir->reg);
}
ir->irq = platform_get_irq(pdev, 0);
if (ir->irq < 0) {
dev_err(dev, "no irq resource\n");
return ir->irq;
}
ir->rc = rc_allocate_device();
if (!ir->rc) {
dev_err(dev, "failed to allocate rc device\n");
return -ENOMEM;
}
ir->rc->priv = ir;
ir->rc->input_name = DRIVER_NAME;
ir->rc->input_phys = DRIVER_NAME "/input0";
ir->rc->input_id.bustype = BUS_HOST;
map_name = of_get_property(node, "linux,rc-map-name", NULL);
ir->rc->map_name = map_name ? map_name : RC_MAP_EMPTY;
ir->rc->dev.parent = dev;
ir->rc->driver_type = RC_DRIVER_IR_RAW;
ir->rc->allowed_protocols = RC_BIT_ALL;
ir->rc->rx_resolution = US_TO_NS(MESON_TRATE);
ir->rc->timeout = MS_TO_NS(200);
ir->rc->driver_name = DRIVER_NAME;
spin_lock_init(&ir->lock);
platform_set_drvdata(pdev, ir);
ret = rc_register_device(ir->rc);
if (ret) {
dev_err(dev, "failed to register rc device\n");
goto out_free;
}
ret = devm_request_irq(dev, ir->irq, meson_ir_irq, 0, "ir-meson", ir);
if (ret) {
dev_err(dev, "failed to request irq\n");
goto out_unreg;
}
meson_ir_set_mask(ir, IR_DEC_REG1, REG1_RESET, REG1_RESET);
meson_ir_set_mask(ir, IR_DEC_REG1, REG1_RESET, 0);
if (of_device_is_compatible(node, "amlogic,meson6-ir"))
meson_ir_set_mask(ir, IR_DEC_REG1, REG1_MODE_MASK,
DECODE_MODE_RAW << REG1_MODE_SHIFT);
else
meson_ir_set_mask(ir, IR_DEC_REG2, REG2_MODE_MASK,
DECODE_MODE_RAW << REG2_MODE_SHIFT);
meson_ir_set_mask(ir, IR_DEC_REG0, REG0_RATE_MASK, MESON_TRATE - 1);
meson_ir_set_mask(ir, IR_DEC_REG1, REG1_IRQSEL_MASK,
REG1_IRQSEL_RISE_FALL);
meson_ir_set_mask(ir, IR_DEC_REG1, REG1_ENABLE, REG1_ENABLE);
dev_info(dev, "receiver initialized\n");
return 0;
out_unreg:
rc_unregister_device(ir->rc);
ir->rc = NULL;
out_free:
rc_free_device(ir->rc);
return ret;
}
static int meson_ir_remove(struct platform_device *pdev)
{
struct meson_ir *ir = platform_get_drvdata(pdev);
unsigned long flags;
spin_lock_irqsave(&ir->lock, flags);
meson_ir_set_mask(ir, IR_DEC_REG1, REG1_ENABLE, 0);
spin_unlock_irqrestore(&ir->lock, flags);
rc_unregister_device(ir->rc);
return 0;
}
