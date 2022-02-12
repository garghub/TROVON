static irqreturn_t hi65xx_power_press_isr(int irq, void *q)
{
struct input_dev *input = q;
pm_wakeup_event(input->dev.parent, MAX_HELD_TIME);
input_report_key(input, KEY_POWER, 1);
input_sync(input);
return IRQ_HANDLED;
}
static irqreturn_t hi65xx_power_release_isr(int irq, void *q)
{
struct input_dev *input = q;
pm_wakeup_event(input->dev.parent, MAX_HELD_TIME);
input_report_key(input, KEY_POWER, 0);
input_sync(input);
return IRQ_HANDLED;
}
static irqreturn_t hi65xx_restart_toggle_isr(int irq, void *q)
{
struct input_dev *input = q;
int value = test_bit(KEY_RESTART, input->key);
pm_wakeup_event(input->dev.parent, MAX_HELD_TIME);
input_report_key(input, KEY_RESTART, !value);
input_sync(input);
return IRQ_HANDLED;
}
static int hi65xx_powerkey_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct input_dev *input;
int irq, i, error;
input = devm_input_allocate_device(&pdev->dev);
if (!input) {
dev_err(&pdev->dev, "failed to allocate input device\n");
return -ENOMEM;
}
input->phys = "hisi_on/input0";
input->name = "HISI 65xx PowerOn Key";
input_set_capability(input, EV_KEY, KEY_POWER);
input_set_capability(input, EV_KEY, KEY_RESTART);
for (i = 0; i < ARRAY_SIZE(hi65xx_irq_info); i++) {
irq = platform_get_irq_byname(pdev, hi65xx_irq_info[i].name);
if (irq < 0) {
error = irq;
dev_err(dev, "couldn't get irq %s: %d\n",
hi65xx_irq_info[i].name, error);
return error;
}
error = devm_request_any_context_irq(dev, irq,
hi65xx_irq_info[i].handler,
IRQF_ONESHOT,
hi65xx_irq_info[i].name,
input);
if (error < 0) {
dev_err(dev, "couldn't request irq %s: %d\n",
hi65xx_irq_info[i].name, error);
return error;
}
}
error = input_register_device(input);
if (error) {
dev_err(&pdev->dev, "failed to register input device: %d\n",
error);
return error;
}
device_init_wakeup(&pdev->dev, 1);
return 0;
}
static int hi65xx_powerkey_remove(struct platform_device *pdev)
{
device_init_wakeup(&pdev->dev, 0);
return 0;
}
