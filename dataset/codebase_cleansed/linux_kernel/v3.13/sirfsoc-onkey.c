static irqreturn_t sirfsoc_pwrc_isr(int irq, void *dev_id)
{
struct sirfsoc_pwrc_drvdata *pwrcdrv = dev_id;
u32 int_status;
int_status = sirfsoc_rtc_iobrg_readl(pwrcdrv->pwrc_base +
PWRC_INT_STATUS);
sirfsoc_rtc_iobrg_writel(int_status & ~PWRC_ON_KEY_BIT,
pwrcdrv->pwrc_base + PWRC_INT_STATUS);
input_event(pwrcdrv->input, EV_PWR, KEY_SUSPEND, 1);
input_sync(pwrcdrv->input);
return IRQ_HANDLED;
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
pwrcdrv->input->evbit[0] = BIT_MASK(EV_PWR);
irq = platform_get_irq(pdev, 0);
error = devm_request_irq(&pdev->dev, irq,
sirfsoc_pwrc_isr, IRQF_SHARED,
"sirfsoc_pwrc_int", pwrcdrv);
if (error) {
dev_err(&pdev->dev, "unable to claim irq %d, error: %d\n",
irq, error);
return error;
}
sirfsoc_rtc_iobrg_writel(
sirfsoc_rtc_iobrg_readl(pwrcdrv->pwrc_base + PWRC_INT_MASK) |
PWRC_ON_KEY_BIT,
pwrcdrv->pwrc_base + PWRC_INT_MASK);
error = input_register_device(pwrcdrv->input);
if (error) {
dev_err(&pdev->dev,
"unable to register input device, error: %d\n",
error);
return error;
}
platform_set_drvdata(pdev, pwrcdrv);
device_init_wakeup(&pdev->dev, 1);
return 0;
}
static int sirfsoc_pwrc_remove(struct platform_device *pdev)
{
device_init_wakeup(&pdev->dev, 0);
return 0;
}
static int pwrc_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct sirfsoc_pwrc_drvdata *pwrcdrv = platform_get_drvdata(pdev);
sirfsoc_rtc_iobrg_writel(
sirfsoc_rtc_iobrg_readl(
pwrcdrv->pwrc_base + PWRC_INT_MASK) | PWRC_ON_KEY_BIT,
pwrcdrv->pwrc_base + PWRC_INT_MASK);
return 0;
}
