static irqreturn_t tps6521x_pb_irq(int irq, void *_pwr)
{
struct tps6521x_pwrbutton *pwr = _pwr;
const struct tps6521x_data *tps_data = pwr->data;
unsigned int reg;
int error;
error = regmap_read(pwr->regmap, tps_data->reg_status, &reg);
if (error) {
dev_err(pwr->dev, "can't read register: %d\n", error);
goto out;
}
if (reg & tps_data->pb_mask) {
input_report_key(pwr->idev, KEY_POWER, 1);
pm_wakeup_event(pwr->dev, 0);
} else {
input_report_key(pwr->idev, KEY_POWER, 0);
}
input_sync(pwr->idev);
out:
return IRQ_HANDLED;
}
static int tps6521x_pb_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct tps6521x_pwrbutton *pwr;
struct input_dev *idev;
const struct of_device_id *match;
int error;
int irq;
match = of_match_node(of_tps6521x_pb_match, dev->of_node);
if (!match)
return -ENXIO;
pwr = devm_kzalloc(dev, sizeof(*pwr), GFP_KERNEL);
if (!pwr)
return -ENOMEM;
pwr->data = match->data;
idev = devm_input_allocate_device(dev);
if (!idev)
return -ENOMEM;
idev->name = pwr->data->name;
snprintf(pwr->phys, sizeof(pwr->phys), "%s/input0",
pwr->data->name);
idev->phys = pwr->phys;
idev->dev.parent = dev;
idev->id.bustype = BUS_I2C;
input_set_capability(idev, EV_KEY, KEY_POWER);
pwr->regmap = dev_get_regmap(dev->parent, NULL);
pwr->dev = dev;
pwr->idev = idev;
device_init_wakeup(dev, true);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "No IRQ resource!\n");
return -EINVAL;
}
error = devm_request_threaded_irq(dev, irq, NULL, tps6521x_pb_irq,
IRQF_TRIGGER_RISING |
IRQF_TRIGGER_FALLING |
IRQF_ONESHOT,
pwr->data->name, pwr);
if (error) {
dev_err(dev, "failed to request IRQ #%d: %d\n", irq, error);
return error;
}
error= input_register_device(idev);
if (error) {
dev_err(dev, "Can't register power button: %d\n", error);
return error;
}
return 0;
}
