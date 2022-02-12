static int mid_pbstat(struct mid_pb_ddata *ddata, int *value)
{
struct input_dev *input = ddata->input;
int ret;
u8 pbstat;
ret = intel_scu_ipc_ioread8(ddata->pbstat_addr, &pbstat);
if (ret)
return ret;
dev_dbg(input->dev.parent, "PB_INT status= %d\n", pbstat);
*value = !(pbstat & ddata->pbstat_mask);
return 0;
}
static int mid_irq_ack(struct mid_pb_ddata *ddata)
{
return intel_scu_ipc_update_register(ddata->mirqlvl1_addr, 0, MSIC_PWRBTNM);
}
static int mrfld_setup(struct mid_pb_ddata *ddata)
{
intel_scu_ipc_update_register(BCOVE_PBIRQ, 0, MSIC_PWRBTNM);
intel_scu_ipc_update_register(BCOVE_PBIRQMASK, 0, MSIC_PWRBTNM);
return 0;
}
static irqreturn_t mid_pb_isr(int irq, void *dev_id)
{
struct mid_pb_ddata *ddata = dev_id;
struct input_dev *input = ddata->input;
int value = 0;
int ret;
ret = mid_pbstat(ddata, &value);
if (ret < 0) {
dev_err(input->dev.parent,
"Read error %d while reading MSIC_PB_STATUS\n", ret);
} else {
input_event(input, EV_KEY, KEY_POWER, value);
input_sync(input);
}
mid_irq_ack(ddata);
return IRQ_HANDLED;
}
static int mid_pb_probe(struct platform_device *pdev)
{
const struct x86_cpu_id *id;
struct mid_pb_ddata *ddata;
struct input_dev *input;
int irq = platform_get_irq(pdev, 0);
int error;
id = x86_match_cpu(mid_pb_cpu_ids);
if (!id)
return -ENODEV;
if (irq < 0) {
dev_err(&pdev->dev, "Failed to get IRQ: %d\n", irq);
return irq;
}
input = devm_input_allocate_device(&pdev->dev);
if (!input)
return -ENOMEM;
input->name = pdev->name;
input->phys = "power-button/input0";
input->id.bustype = BUS_HOST;
input->dev.parent = &pdev->dev;
input_set_capability(input, EV_KEY, KEY_POWER);
ddata = (struct mid_pb_ddata *)id->driver_data;
if (!ddata)
return -ENODATA;
ddata->dev = &pdev->dev;
ddata->irq = irq;
ddata->input = input;
if (ddata->setup) {
error = ddata->setup(ddata);
if (error)
return error;
}
error = devm_request_threaded_irq(&pdev->dev, irq, NULL, mid_pb_isr,
IRQF_ONESHOT, DRIVER_NAME, ddata);
if (error) {
dev_err(&pdev->dev,
"Unable to request irq %d for MID power button\n", irq);
return error;
}
error = input_register_device(input);
if (error) {
dev_err(&pdev->dev,
"Unable to register input dev, error %d\n", error);
return error;
}
platform_set_drvdata(pdev, ddata);
error = mid_irq_ack(ddata);
if (error) {
dev_err(&pdev->dev,
"Unable to clear power button interrupt, error: %d\n",
error);
return error;
}
device_init_wakeup(&pdev->dev, true);
dev_pm_set_wake_irq(&pdev->dev, irq);
return 0;
}
static int mid_pb_remove(struct platform_device *pdev)
{
dev_pm_clear_wake_irq(&pdev->dev);
device_init_wakeup(&pdev->dev, false);
return 0;
}
