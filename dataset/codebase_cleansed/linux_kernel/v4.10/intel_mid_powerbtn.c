static irqreturn_t mfld_pb_isr(int irq, void *dev_id)
{
struct input_dev *input = dev_id;
int ret;
u8 pbstat;
ret = intel_msic_reg_read(INTEL_MSIC_PBSTATUS, &pbstat);
dev_dbg(input->dev.parent, "PB_INT status= %d\n", pbstat);
if (ret < 0) {
dev_err(input->dev.parent, "Read error %d while reading"
" MSIC_PB_STATUS\n", ret);
} else {
input_event(input, EV_KEY, KEY_POWER,
!(pbstat & MSIC_PB_LEVEL));
input_sync(input);
}
return IRQ_HANDLED;
}
static int mfld_pb_probe(struct platform_device *pdev)
{
struct input_dev *input;
int irq = platform_get_irq(pdev, 0);
int error;
if (irq < 0)
return -EINVAL;
input = input_allocate_device();
if (!input)
return -ENOMEM;
input->name = pdev->name;
input->phys = "power-button/input0";
input->id.bustype = BUS_HOST;
input->dev.parent = &pdev->dev;
input_set_capability(input, EV_KEY, KEY_POWER);
error = request_threaded_irq(irq, NULL, mfld_pb_isr, IRQF_ONESHOT,
DRIVER_NAME, input);
if (error) {
dev_err(&pdev->dev, "Unable to request irq %d for mfld power"
"button\n", irq);
goto err_free_input;
}
device_init_wakeup(&pdev->dev, true);
dev_pm_set_wake_irq(&pdev->dev, irq);
error = input_register_device(input);
if (error) {
dev_err(&pdev->dev, "Unable to register input dev, error "
"%d\n", error);
goto err_free_irq;
}
platform_set_drvdata(pdev, input);
error = intel_msic_reg_update(INTEL_MSIC_IRQLVL1MSK, 0, MSIC_PWRBTNM);
if (error) {
dev_err(&pdev->dev, "Unable to clear power button interrupt, "
"error: %d\n", error);
goto err_free_irq;
}
return 0;
err_free_irq:
free_irq(irq, input);
err_free_input:
input_free_device(input);
return error;
}
static int mfld_pb_remove(struct platform_device *pdev)
{
struct input_dev *input = platform_get_drvdata(pdev);
int irq = platform_get_irq(pdev, 0);
dev_pm_clear_wake_irq(&pdev->dev);
device_init_wakeup(&pdev->dev, false);
free_irq(irq, input);
input_unregister_device(input);
return 0;
}
