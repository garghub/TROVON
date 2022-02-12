static irqreturn_t ab8500_ponkey_handler(int irq, void *data)
{
struct ab8500_ponkey *ponkey = data;
if (irq == ponkey->irq_dbf)
input_report_key(ponkey->idev, KEY_POWER, true);
else if (irq == ponkey->irq_dbr)
input_report_key(ponkey->idev, KEY_POWER, false);
input_sync(ponkey->idev);
return IRQ_HANDLED;
}
static int ab8500_ponkey_probe(struct platform_device *pdev)
{
struct ab8500 *ab8500 = dev_get_drvdata(pdev->dev.parent);
struct ab8500_ponkey *ponkey;
struct input_dev *input;
int irq_dbf, irq_dbr;
int error;
irq_dbf = platform_get_irq_byname(pdev, "ONKEY_DBF");
if (irq_dbf < 0) {
dev_err(&pdev->dev, "No IRQ for ONKEY_DBF, error=%d\n", irq_dbf);
return irq_dbf;
}
irq_dbr = platform_get_irq_byname(pdev, "ONKEY_DBR");
if (irq_dbr < 0) {
dev_err(&pdev->dev, "No IRQ for ONKEY_DBR, error=%d\n", irq_dbr);
return irq_dbr;
}
ponkey = kzalloc(sizeof(struct ab8500_ponkey), GFP_KERNEL);
input = input_allocate_device();
if (!ponkey || !input) {
error = -ENOMEM;
goto err_free_mem;
}
ponkey->idev = input;
ponkey->ab8500 = ab8500;
ponkey->irq_dbf = irq_dbf;
ponkey->irq_dbr = irq_dbr;
input->name = "AB8500 POn(PowerOn) Key";
input->dev.parent = &pdev->dev;
input_set_capability(input, EV_KEY, KEY_POWER);
error = request_any_context_irq(ponkey->irq_dbf, ab8500_ponkey_handler,
0, "ab8500-ponkey-dbf", ponkey);
if (error < 0) {
dev_err(ab8500->dev, "Failed to request dbf IRQ#%d: %d\n",
ponkey->irq_dbf, error);
goto err_free_mem;
}
error = request_any_context_irq(ponkey->irq_dbr, ab8500_ponkey_handler,
0, "ab8500-ponkey-dbr", ponkey);
if (error < 0) {
dev_err(ab8500->dev, "Failed to request dbr IRQ#%d: %d\n",
ponkey->irq_dbr, error);
goto err_free_dbf_irq;
}
error = input_register_device(ponkey->idev);
if (error) {
dev_err(ab8500->dev, "Can't register input device: %d\n", error);
goto err_free_dbr_irq;
}
platform_set_drvdata(pdev, ponkey);
return 0;
err_free_dbr_irq:
free_irq(ponkey->irq_dbr, ponkey);
err_free_dbf_irq:
free_irq(ponkey->irq_dbf, ponkey);
err_free_mem:
input_free_device(input);
kfree(ponkey);
return error;
}
static int ab8500_ponkey_remove(struct platform_device *pdev)
{
struct ab8500_ponkey *ponkey = platform_get_drvdata(pdev);
free_irq(ponkey->irq_dbf, ponkey);
free_irq(ponkey->irq_dbr, ponkey);
input_unregister_device(ponkey->idev);
kfree(ponkey);
return 0;
}
