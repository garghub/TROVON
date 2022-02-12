static irqreturn_t retu_pwrbutton_irq(int irq, void *_pwr)
{
struct input_dev *idev = _pwr;
struct retu_dev *rdev = input_get_drvdata(idev);
bool state;
state = !(retu_read(rdev, RETU_REG_STATUS) & RETU_STATUS_PWRONX);
input_report_key(idev, KEY_POWER, state);
input_sync(idev);
return IRQ_HANDLED;
}
static int retu_pwrbutton_probe(struct platform_device *pdev)
{
struct retu_dev *rdev = dev_get_drvdata(pdev->dev.parent);
struct input_dev *idev;
int irq;
int error;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
idev = devm_input_allocate_device(&pdev->dev);
if (!idev)
return -ENOMEM;
idev->name = "retu-pwrbutton";
idev->dev.parent = &pdev->dev;
input_set_capability(idev, EV_KEY, KEY_POWER);
input_set_drvdata(idev, rdev);
error = devm_request_threaded_irq(&pdev->dev, irq,
NULL, retu_pwrbutton_irq,
IRQF_ONESHOT,
"retu-pwrbutton", idev);
if (error)
return error;
error = input_register_device(idev);
if (error)
return error;
return 0;
}
static int retu_pwrbutton_remove(struct platform_device *pdev)
{
return 0;
}
