static void put_fifo_with_discard(struct kfifo *fifo, u8 val)
{
if (!kfifo_initialized(fifo))
return;
if (kfifo_is_full(fifo))
kfifo_skip(fifo);
kfifo_put(fifo, val);
}
static irqreturn_t aspeed_lpc_snoop_irq(int irq, void *arg)
{
struct aspeed_lpc_snoop *lpc_snoop = arg;
u32 reg, data;
if (regmap_read(lpc_snoop->regmap, HICR6, &reg))
return IRQ_NONE;
reg &= (HICR6_STR_SNP0W | HICR6_STR_SNP1W);
if (!reg)
return IRQ_NONE;
regmap_write(lpc_snoop->regmap, HICR6, reg);
regmap_read(lpc_snoop->regmap, SNPWDR, &data);
if (reg & HICR6_STR_SNP0W) {
u8 val = (data & SNPWDR_CH0_MASK) >> SNPWDR_CH0_SHIFT;
put_fifo_with_discard(&lpc_snoop->snoop_fifo[0], val);
}
if (reg & HICR6_STR_SNP1W) {
u8 val = (data & SNPWDR_CH1_MASK) >> SNPWDR_CH1_SHIFT;
put_fifo_with_discard(&lpc_snoop->snoop_fifo[1], val);
}
return IRQ_HANDLED;
}
static int aspeed_lpc_snoop_config_irq(struct aspeed_lpc_snoop *lpc_snoop,
struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
int rc;
lpc_snoop->irq = platform_get_irq(pdev, 0);
if (!lpc_snoop->irq)
return -ENODEV;
rc = devm_request_irq(dev, lpc_snoop->irq,
aspeed_lpc_snoop_irq, IRQF_SHARED,
DEVICE_NAME, lpc_snoop);
if (rc < 0) {
dev_warn(dev, "Unable to request IRQ %d\n", lpc_snoop->irq);
lpc_snoop->irq = 0;
return rc;
}
return 0;
}
static int aspeed_lpc_enable_snoop(struct aspeed_lpc_snoop *lpc_snoop,
int channel, u16 lpc_port)
{
int rc = 0;
u32 hicr5_en, snpwadr_mask, snpwadr_shift, hicrb_en;
rc = kfifo_alloc(&lpc_snoop->snoop_fifo[channel],
SNOOP_FIFO_SIZE, GFP_KERNEL);
if (rc)
return rc;
switch (channel) {
case 0:
hicr5_en = HICR5_EN_SNP0W | HICR5_ENINT_SNP0W;
snpwadr_mask = SNPWADR_CH0_MASK;
snpwadr_shift = SNPWADR_CH0_SHIFT;
hicrb_en = HICRB_ENSNP0D;
break;
case 1:
hicr5_en = HICR5_EN_SNP1W | HICR5_ENINT_SNP1W;
snpwadr_mask = SNPWADR_CH1_MASK;
snpwadr_shift = SNPWADR_CH1_SHIFT;
hicrb_en = HICRB_ENSNP1D;
break;
default:
return -EINVAL;
}
regmap_update_bits(lpc_snoop->regmap, HICR5, hicr5_en, hicr5_en);
regmap_update_bits(lpc_snoop->regmap, SNPWADR, snpwadr_mask,
lpc_port << snpwadr_shift);
regmap_update_bits(lpc_snoop->regmap, HICRB, hicrb_en, hicrb_en);
return rc;
}
static void aspeed_lpc_disable_snoop(struct aspeed_lpc_snoop *lpc_snoop,
int channel)
{
switch (channel) {
case 0:
regmap_update_bits(lpc_snoop->regmap, HICR5,
HICR5_EN_SNP0W | HICR5_ENINT_SNP0W,
0);
break;
case 1:
regmap_update_bits(lpc_snoop->regmap, HICR5,
HICR5_EN_SNP1W | HICR5_ENINT_SNP1W,
0);
break;
default:
return;
}
kfifo_free(&lpc_snoop->snoop_fifo[channel]);
}
static int aspeed_lpc_snoop_probe(struct platform_device *pdev)
{
struct aspeed_lpc_snoop *lpc_snoop;
struct device *dev;
u32 port;
int rc;
dev = &pdev->dev;
lpc_snoop = devm_kzalloc(dev, sizeof(*lpc_snoop), GFP_KERNEL);
if (!lpc_snoop)
return -ENOMEM;
lpc_snoop->regmap = syscon_node_to_regmap(
pdev->dev.parent->of_node);
if (IS_ERR(lpc_snoop->regmap)) {
dev_err(dev, "Couldn't get regmap\n");
return -ENODEV;
}
dev_set_drvdata(&pdev->dev, lpc_snoop);
rc = of_property_read_u32_index(dev->of_node, "snoop-ports", 0, &port);
if (rc) {
dev_err(dev, "no snoop ports configured\n");
return -ENODEV;
}
rc = aspeed_lpc_snoop_config_irq(lpc_snoop, pdev);
if (rc)
return rc;
rc = aspeed_lpc_enable_snoop(lpc_snoop, 0, port);
if (rc)
return rc;
if (of_property_read_u32_index(dev->of_node, "snoop-ports",
1, &port) == 0) {
rc = aspeed_lpc_enable_snoop(lpc_snoop, 1, port);
if (rc)
aspeed_lpc_disable_snoop(lpc_snoop, 0);
}
return rc;
}
static int aspeed_lpc_snoop_remove(struct platform_device *pdev)
{
struct aspeed_lpc_snoop *lpc_snoop = dev_get_drvdata(&pdev->dev);
aspeed_lpc_disable_snoop(lpc_snoop, 0);
aspeed_lpc_disable_snoop(lpc_snoop, 1);
return 0;
}
