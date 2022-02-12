static inline struct a10sr_reset *to_a10sr_rst(struct reset_controller_dev *rc)
{
return container_of(rc, struct a10sr_reset, rcdev);
}
static inline int a10sr_reset_shift(unsigned long id)
{
switch (id) {
case A10SR_RESET_ENET_HPS:
return 1;
case A10SR_RESET_PCIE:
case A10SR_RESET_FILE:
case A10SR_RESET_BQSPI:
case A10SR_RESET_USB:
return id + 11;
default:
return -EINVAL;
}
}
static int a10sr_reset_update(struct reset_controller_dev *rcdev,
unsigned long id, bool assert)
{
struct a10sr_reset *a10r = to_a10sr_rst(rcdev);
int offset = a10sr_reset_shift(id);
u8 mask = ALTR_A10SR_REG_BIT_MASK(offset);
int index = ALTR_A10SR_HPS_RST_REG + ALTR_A10SR_REG_OFFSET(offset);
return regmap_update_bits(a10r->regmap, index, mask, assert ? 0 : mask);
}
static int a10sr_reset_assert(struct reset_controller_dev *rcdev,
unsigned long id)
{
return a10sr_reset_update(rcdev, id, true);
}
static int a10sr_reset_deassert(struct reset_controller_dev *rcdev,
unsigned long id)
{
return a10sr_reset_update(rcdev, id, false);
}
static int a10sr_reset_status(struct reset_controller_dev *rcdev,
unsigned long id)
{
int ret;
struct a10sr_reset *a10r = to_a10sr_rst(rcdev);
int offset = a10sr_reset_shift(id);
u8 mask = ALTR_A10SR_REG_BIT_MASK(offset);
int index = ALTR_A10SR_HPS_RST_REG + ALTR_A10SR_REG_OFFSET(offset);
unsigned int value;
ret = regmap_read(a10r->regmap, index, &value);
if (ret < 0)
return ret;
return !!(value & mask);
}
static int a10sr_reset_probe(struct platform_device *pdev)
{
struct altr_a10sr *a10sr = dev_get_drvdata(pdev->dev.parent);
struct a10sr_reset *a10r;
a10r = devm_kzalloc(&pdev->dev, sizeof(struct a10sr_reset),
GFP_KERNEL);
if (!a10r)
return -ENOMEM;
a10r->rcdev.owner = THIS_MODULE;
a10r->rcdev.nr_resets = A10SR_RESET_NUM;
a10r->rcdev.ops = &a10sr_reset_ops;
a10r->rcdev.of_node = pdev->dev.of_node;
a10r->regmap = a10sr->regmap;
platform_set_drvdata(pdev, a10r);
return devm_reset_controller_register(&pdev->dev, &a10r->rcdev);
}
