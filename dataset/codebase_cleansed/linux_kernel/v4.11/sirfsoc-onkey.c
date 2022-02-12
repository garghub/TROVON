static int sirfsoc_pwrc_is_on_key_down(struct sirfsoc_pwrc_drvdata *pwrcdrv)
{
u32 state = sirfsoc_rtc_iobrg_readl(pwrcdrv->pwrc_base +
PWRC_PIN_STATUS);
return !(state & PWRC_ON_KEY_BIT);
}
static void sirfsoc_pwrc_report_event(struct work_struct *work)
{
struct sirfsoc_pwrc_drvdata *pwrcdrv =
container_of(work, struct sirfsoc_pwrc_drvdata, work.work);
if (sirfsoc_pwrc_is_on_key_down(pwrcdrv)) {
schedule_delayed_work(&pwrcdrv->work,
msecs_to_jiffies(PWRC_KEY_DETECT_UP_TIME));
} else {
input_event(pwrcdrv->input, EV_KEY, KEY_POWER, 0);
input_sync(pwrcdrv->input);
}
}
static irqreturn_t sirfsoc_pwrc_isr(int irq, void *dev_id)
{
struct sirfsoc_pwrc_drvdata *pwrcdrv = dev_id;
u32 int_status;
int_status = sirfsoc_rtc_iobrg_readl(pwrcdrv->pwrc_base +
PWRC_INT_STATUS);
sirfsoc_rtc_iobrg_writel(int_status & ~PWRC_ON_KEY_BIT,
pwrcdrv->pwrc_base + PWRC_INT_STATUS);
input_event(pwrcdrv->input, EV_KEY, KEY_POWER, 1);
input_sync(pwrcdrv->input);
schedule_delayed_work(&pwrcdrv->work,
msecs_to_jiffies(PWRC_KEY_DETECT_UP_TIME));
return IRQ_HANDLED;
}
static void sirfsoc_pwrc_toggle_interrupts(struct sirfsoc_pwrc_drvdata *pwrcdrv,
bool enable)
{
u32 int_mask;
int_mask = sirfsoc_rtc_iobrg_readl(pwrcdrv->pwrc_base + PWRC_INT_MASK);
if (enable)
int_mask |= PWRC_ON_KEY_BIT;
else
int_mask &= ~PWRC_ON_KEY_BIT;
sirfsoc_rtc_iobrg_writel(int_mask, pwrcdrv->pwrc_base + PWRC_INT_MASK);
}
static int sirfsoc_pwrc_open(struct input_dev *input)
{
struct sirfsoc_pwrc_drvdata *pwrcdrv = input_get_drvdata(input);
sirfsoc_pwrc_toggle_interrupts(pwrcdrv, true);
return 0;
}
static void sirfsoc_pwrc_close(struct input_dev *input)
{
struct sirfsoc_pwrc_drvdata *pwrcdrv = input_get_drvdata(input);
sirfsoc_pwrc_toggle_interrupts(pwrcdrv, false);
cancel_delayed_work_sync(&pwrcdrv->work);
}
static int sirfsoc_pwrc_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct sirfsoc_pwrc_drvdata *pwrcdrv;
int irq;
int error;
pwrcdrv = devm_kzalloc(&pdev->dev, sizeof(struct sirfsoc_pwrc_drvdata),
GFP_KERNEL);
if (!pwrcdrv) {
dev_info(&pdev->dev, "Not enough memory for the device data\n");
return -ENOMEM;
}
error = of_property_read_u32(np, "reg", &pwrcdrv->pwrc_base);
if (error) {
dev_err(&pdev->dev,
"unable to find base address of pwrc node in dtb\n");
return error;
}
pwrcdrv->input = devm_input_allocate_device(&pdev->dev);
if (!pwrcdrv->input)
return -ENOMEM;
pwrcdrv->input->name = "sirfsoc pwrckey";
pwrcdrv->input->phys = "pwrc/input0";
pwrcdrv->input->evbit[0] = BIT_MASK(EV_KEY);
input_set_capability(pwrcdrv->input, EV_KEY, KEY_POWER);
INIT_DELAYED_WORK(&pwrcdrv->work, sirfsoc_pwrc_report_event);
pwrcdrv->input->open = sirfsoc_pwrc_open;
pwrcdrv->input->close = sirfsoc_pwrc_close;
input_set_drvdata(pwrcdrv->input, pwrcdrv);
sirfsoc_pwrc_toggle_interrupts(pwrcdrv, false);
irq = platform_get_irq(pdev, 0);
error = devm_request_irq(&pdev->dev, irq,
sirfsoc_pwrc_isr, 0,
"sirfsoc_pwrc_int", pwrcdrv);
if (error) {
dev_err(&pdev->dev, "unable to claim irq %d, error: %d\n",
irq, error);
return error;
}
error = input_register_device(pwrcdrv->input);
if (error) {
dev_err(&pdev->dev,
"unable to register input device, error: %d\n",
error);
return error;
}
dev_set_drvdata(&pdev->dev, pwrcdrv);
device_init_wakeup(&pdev->dev, 1);
return 0;
}
static int __maybe_unused sirfsoc_pwrc_resume(struct device *dev)
{
struct sirfsoc_pwrc_drvdata *pwrcdrv = dev_get_drvdata(dev);
struct input_dev *input = pwrcdrv->input;
mutex_lock(&input->mutex);
if (input->users)
sirfsoc_pwrc_toggle_interrupts(pwrcdrv, true);
mutex_unlock(&input->mutex);
return 0;
}
