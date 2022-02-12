static irqreturn_t sun4i_lradc_irq(int irq, void *dev_id)
{
struct sun4i_lradc_data *lradc = dev_id;
u32 i, ints, val, voltage, diff, keycode = 0, closest = 0xffffffff;
ints = readl(lradc->base + LRADC_INTS);
if (ints & CHAN0_KEYUP_IRQ) {
input_report_key(lradc->input, lradc->chan0_keycode, 0);
lradc->chan0_keycode = 0;
}
if ((ints & CHAN0_KEYDOWN_IRQ) && lradc->chan0_keycode == 0) {
val = readl(lradc->base + LRADC_DATA0) & 0x3f;
voltage = val * lradc->vref / 63;
for (i = 0; i < lradc->chan0_map_count; i++) {
diff = abs(lradc->chan0_map[i].voltage - voltage);
if (diff < closest) {
closest = diff;
keycode = lradc->chan0_map[i].keycode;
}
}
lradc->chan0_keycode = keycode;
input_report_key(lradc->input, lradc->chan0_keycode, 1);
}
input_sync(lradc->input);
writel(ints, lradc->base + LRADC_INTS);
return IRQ_HANDLED;
}
static int sun4i_lradc_open(struct input_dev *dev)
{
struct sun4i_lradc_data *lradc = input_get_drvdata(dev);
int error;
error = regulator_enable(lradc->vref_supply);
if (error)
return error;
lradc->vref = regulator_get_voltage(lradc->vref_supply) * 2 / 3;
writel(FIRST_CONVERT_DLY(2) | LEVELA_B_CNT(1) | HOLD_EN(1) |
SAMPLE_RATE(0) | ENABLE(1), lradc->base + LRADC_CTRL);
writel(CHAN0_KEYUP_IRQ | CHAN0_KEYDOWN_IRQ, lradc->base + LRADC_INTC);
return 0;
}
static void sun4i_lradc_close(struct input_dev *dev)
{
struct sun4i_lradc_data *lradc = input_get_drvdata(dev);
writel(FIRST_CONVERT_DLY(2) | LEVELA_B_CNT(1) | HOLD_EN(1) |
SAMPLE_RATE(2), lradc->base + LRADC_CTRL);
writel(0, lradc->base + LRADC_INTC);
regulator_disable(lradc->vref_supply);
}
static int sun4i_lradc_load_dt_keymap(struct device *dev,
struct sun4i_lradc_data *lradc)
{
struct device_node *np, *pp;
int i;
int error;
np = dev->of_node;
if (!np)
return -EINVAL;
lradc->chan0_map_count = of_get_child_count(np);
if (lradc->chan0_map_count == 0) {
dev_err(dev, "keymap is missing in device tree\n");
return -EINVAL;
}
lradc->chan0_map = devm_kmalloc_array(dev, lradc->chan0_map_count,
sizeof(struct sun4i_lradc_keymap),
GFP_KERNEL);
if (!lradc->chan0_map)
return -ENOMEM;
i = 0;
for_each_child_of_node(np, pp) {
struct sun4i_lradc_keymap *map = &lradc->chan0_map[i];
u32 channel;
error = of_property_read_u32(pp, "channel", &channel);
if (error || channel != 0) {
dev_err(dev, "%s: Inval channel prop\n", pp->name);
return -EINVAL;
}
error = of_property_read_u32(pp, "voltage", &map->voltage);
if (error) {
dev_err(dev, "%s: Inval voltage prop\n", pp->name);
return -EINVAL;
}
error = of_property_read_u32(pp, "linux,code", &map->keycode);
if (error) {
dev_err(dev, "%s: Inval linux,code prop\n", pp->name);
return -EINVAL;
}
i++;
}
return 0;
}
static int sun4i_lradc_probe(struct platform_device *pdev)
{
struct sun4i_lradc_data *lradc;
struct device *dev = &pdev->dev;
int i;
int error;
lradc = devm_kzalloc(dev, sizeof(struct sun4i_lradc_data), GFP_KERNEL);
if (!lradc)
return -ENOMEM;
error = sun4i_lradc_load_dt_keymap(dev, lradc);
if (error)
return error;
lradc->vref_supply = devm_regulator_get(dev, "vref");
if (IS_ERR(lradc->vref_supply))
return PTR_ERR(lradc->vref_supply);
lradc->dev = dev;
lradc->input = devm_input_allocate_device(dev);
if (!lradc->input)
return -ENOMEM;
lradc->input->name = pdev->name;
lradc->input->phys = "sun4i_lradc/input0";
lradc->input->open = sun4i_lradc_open;
lradc->input->close = sun4i_lradc_close;
lradc->input->id.bustype = BUS_HOST;
lradc->input->id.vendor = 0x0001;
lradc->input->id.product = 0x0001;
lradc->input->id.version = 0x0100;
__set_bit(EV_KEY, lradc->input->evbit);
for (i = 0; i < lradc->chan0_map_count; i++)
__set_bit(lradc->chan0_map[i].keycode, lradc->input->keybit);
input_set_drvdata(lradc->input, lradc);
lradc->base = devm_ioremap_resource(dev,
platform_get_resource(pdev, IORESOURCE_MEM, 0));
if (IS_ERR(lradc->base))
return PTR_ERR(lradc->base);
error = devm_request_irq(dev, platform_get_irq(pdev, 0),
sun4i_lradc_irq, 0,
"sun4i-a10-lradc-keys", lradc);
if (error)
return error;
error = input_register_device(lradc->input);
if (error)
return error;
platform_set_drvdata(pdev, lradc);
return 0;
}
