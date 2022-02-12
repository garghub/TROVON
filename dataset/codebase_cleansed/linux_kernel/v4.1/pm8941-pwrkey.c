static int pm8941_reboot_notify(struct notifier_block *nb,
unsigned long code, void *unused)
{
struct pm8941_pwrkey *pwrkey = container_of(nb, struct pm8941_pwrkey,
reboot_notifier);
unsigned int enable_reg;
unsigned int reset_type;
int error;
if (pwrkey->revision == 0)
enable_reg = PON_PS_HOLD_RST_CTL;
else
enable_reg = PON_PS_HOLD_RST_CTL2;
error = regmap_update_bits(pwrkey->regmap,
pwrkey->baseaddr + enable_reg,
PON_PS_HOLD_ENABLE,
0);
if (error)
dev_err(pwrkey->dev,
"unable to clear ps hold reset enable: %d\n",
error);
usleep_range(100, 1000);
switch (code) {
case SYS_HALT:
case SYS_POWER_OFF:
reset_type = PON_PS_HOLD_TYPE_SHUTDOWN;
break;
case SYS_RESTART:
default:
reset_type = PON_PS_HOLD_TYPE_HARD_RESET;
break;
};
error = regmap_update_bits(pwrkey->regmap,
pwrkey->baseaddr + PON_PS_HOLD_RST_CTL,
PON_PS_HOLD_TYPE_MASK,
reset_type);
if (error)
dev_err(pwrkey->dev, "unable to set ps hold reset type: %d\n",
error);
error = regmap_update_bits(pwrkey->regmap,
pwrkey->baseaddr + enable_reg,
PON_PS_HOLD_ENABLE,
PON_PS_HOLD_ENABLE);
if (error)
dev_err(pwrkey->dev, "unable to re-set enable: %d\n", error);
return NOTIFY_DONE;
}
static irqreturn_t pm8941_pwrkey_irq(int irq, void *_data)
{
struct pm8941_pwrkey *pwrkey = _data;
unsigned int sts;
int error;
error = regmap_read(pwrkey->regmap,
pwrkey->baseaddr + PON_RT_STS, &sts);
if (error)
return IRQ_HANDLED;
input_report_key(pwrkey->input, KEY_POWER, !!(sts & PON_KPDPWR_N_SET));
input_sync(pwrkey->input);
return IRQ_HANDLED;
}
static int __maybe_unused pm8941_pwrkey_suspend(struct device *dev)
{
struct pm8941_pwrkey *pwrkey = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
enable_irq_wake(pwrkey->irq);
return 0;
}
static int __maybe_unused pm8941_pwrkey_resume(struct device *dev)
{
struct pm8941_pwrkey *pwrkey = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
disable_irq_wake(pwrkey->irq);
return 0;
}
static int pm8941_pwrkey_probe(struct platform_device *pdev)
{
struct pm8941_pwrkey *pwrkey;
bool pull_up;
u32 req_delay;
int error;
if (of_property_read_u32(pdev->dev.of_node, "debounce", &req_delay))
req_delay = 15625;
if (req_delay > 2000000 || req_delay == 0) {
dev_err(&pdev->dev, "invalid debounce time: %u\n", req_delay);
return -EINVAL;
}
pull_up = of_property_read_bool(pdev->dev.of_node, "bias-pull-up");
pwrkey = devm_kzalloc(&pdev->dev, sizeof(*pwrkey), GFP_KERNEL);
if (!pwrkey)
return -ENOMEM;
pwrkey->dev = &pdev->dev;
pwrkey->regmap = dev_get_regmap(pdev->dev.parent, NULL);
if (!pwrkey->regmap) {
dev_err(&pdev->dev, "failed to locate regmap\n");
return -ENODEV;
}
pwrkey->irq = platform_get_irq(pdev, 0);
if (pwrkey->irq < 0) {
dev_err(&pdev->dev, "failed to get irq\n");
return pwrkey->irq;
}
error = of_property_read_u32(pdev->dev.of_node, "reg",
&pwrkey->baseaddr);
if (error)
return error;
error = regmap_read(pwrkey->regmap, pwrkey->baseaddr + PON_REV2,
&pwrkey->revision);
if (error) {
dev_err(&pdev->dev, "failed to set debounce: %d\n", error);
return error;
}
pwrkey->input = devm_input_allocate_device(&pdev->dev);
if (!pwrkey->input) {
dev_dbg(&pdev->dev, "unable to allocate input device\n");
return -ENOMEM;
}
input_set_capability(pwrkey->input, EV_KEY, KEY_POWER);
pwrkey->input->name = "pm8941_pwrkey";
pwrkey->input->phys = "pm8941_pwrkey/input0";
req_delay = (req_delay << 6) / USEC_PER_SEC;
req_delay = ilog2(req_delay);
error = regmap_update_bits(pwrkey->regmap,
pwrkey->baseaddr + PON_DBC_CTL,
PON_DBC_DELAY_MASK,
req_delay);
if (error) {
dev_err(&pdev->dev, "failed to set debounce: %d\n", error);
return error;
}
error = regmap_update_bits(pwrkey->regmap,
pwrkey->baseaddr + PON_PULL_CTL,
PON_KPDPWR_PULL_UP,
pull_up ? PON_KPDPWR_PULL_UP : 0);
if (error) {
dev_err(&pdev->dev, "failed to set pull: %d\n", error);
return error;
}
error = devm_request_threaded_irq(&pdev->dev, pwrkey->irq,
NULL, pm8941_pwrkey_irq,
IRQF_ONESHOT,
"pm8941_pwrkey", pwrkey);
if (error) {
dev_err(&pdev->dev, "failed requesting IRQ: %d\n", error);
return error;
}
error = input_register_device(pwrkey->input);
if (error) {
dev_err(&pdev->dev, "failed to register input device: %d\n",
error);
return error;
}
pwrkey->reboot_notifier.notifier_call = pm8941_reboot_notify,
error = register_reboot_notifier(&pwrkey->reboot_notifier);
if (error) {
dev_err(&pdev->dev, "failed to register reboot notifier: %d\n",
error);
return error;
}
platform_set_drvdata(pdev, pwrkey);
device_init_wakeup(&pdev->dev, 1);
return 0;
}
static int pm8941_pwrkey_remove(struct platform_device *pdev)
{
struct pm8941_pwrkey *pwrkey = platform_get_drvdata(pdev);
device_init_wakeup(&pdev->dev, 0);
unregister_reboot_notifier(&pwrkey->reboot_notifier);
return 0;
}
