static void da9063_poll_on(struct work_struct *work)
{
struct da9063_onkey *onkey = container_of(work, struct da9063_onkey,
work.work);
unsigned int val;
int fault_log = 0;
bool poll = true;
int error;
error = regmap_read(onkey->hw->regmap, DA9063_REG_STATUS_A, &val);
if (error) {
dev_err(onkey->dev,
"Failed to read ON status: %d\n", error);
goto err_poll;
}
if (!(val & DA9063_NONKEY)) {
error = regmap_update_bits(onkey->hw->regmap,
DA9063_REG_CONTROL_B,
DA9063_NONKEY_LOCK, 0);
if (error) {
dev_err(onkey->dev,
"Failed to reset the Key Delay %d\n", error);
goto err_poll;
}
input_report_key(onkey->input, KEY_POWER, 0);
input_sync(onkey->input);
poll = false;
}
error = regmap_read(onkey->hw->regmap,
DA9063_REG_FAULT_LOG, &fault_log);
if (error) {
dev_warn(&onkey->input->dev,
"Cannot read FAULT_LOG: %d\n", error);
} else if (fault_log & DA9063_KEY_RESET) {
error = regmap_write(onkey->hw->regmap,
DA9063_REG_FAULT_LOG,
DA9063_KEY_RESET);
if (error) {
dev_warn(&onkey->input->dev,
"Cannot reset KEY_RESET fault log: %d\n",
error);
} else {
dev_dbg(&onkey->input->dev,
"Sending SHUTDOWN to DA9063 ...\n");
error = regmap_write(onkey->hw->regmap,
DA9063_REG_CONTROL_F,
DA9063_SHUTDOWN);
if (error)
dev_err(&onkey->input->dev,
"Cannot SHUTDOWN DA9063: %d\n",
error);
}
}
err_poll:
if (poll)
schedule_delayed_work(&onkey->work, msecs_to_jiffies(50));
}
static irqreturn_t da9063_onkey_irq_handler(int irq, void *data)
{
struct da9063_onkey *onkey = data;
unsigned int val;
int error;
error = regmap_read(onkey->hw->regmap, DA9063_REG_STATUS_A, &val);
if (onkey->key_power && !error && (val & DA9063_NONKEY)) {
input_report_key(onkey->input, KEY_POWER, 1);
input_sync(onkey->input);
schedule_delayed_work(&onkey->work, 0);
dev_dbg(onkey->dev, "KEY_POWER pressed.\n");
} else {
input_report_key(onkey->input, KEY_SLEEP, 1);
input_sync(onkey->input);
input_report_key(onkey->input, KEY_SLEEP, 0);
input_sync(onkey->input);
dev_dbg(onkey->dev, "KEY_SLEEP pressed.\n");
}
return IRQ_HANDLED;
}
static void da9063_cancel_poll(void *data)
{
struct da9063_onkey *onkey = data;
cancel_delayed_work_sync(&onkey->work);
}
static int da9063_onkey_probe(struct platform_device *pdev)
{
struct da9063 *da9063 = dev_get_drvdata(pdev->dev.parent);
struct da9063_pdata *pdata = dev_get_platdata(da9063->dev);
struct da9063_onkey *onkey;
int irq;
int error;
onkey = devm_kzalloc(&pdev->dev, sizeof(struct da9063_onkey),
GFP_KERNEL);
if (!onkey) {
dev_err(&pdev->dev, "Failed to allocate memory.\n");
return -ENOMEM;
}
onkey->dev = &pdev->dev;
onkey->hw = da9063;
if (pdata)
onkey->key_power = pdata->key_power;
else
onkey->key_power =
!of_property_read_bool(pdev->dev.of_node,
"dlg,disable-key-power");
onkey->input = devm_input_allocate_device(&pdev->dev);
if (!onkey->input) {
dev_err(&pdev->dev, "Failed to allocated input device.\n");
return -ENOMEM;
}
onkey->input->name = DA9063_DRVNAME_ONKEY;
onkey->input->phys = DA9063_DRVNAME_ONKEY "/input0";
onkey->input->dev.parent = &pdev->dev;
if (onkey->key_power)
input_set_capability(onkey->input, EV_KEY, KEY_POWER);
input_set_capability(onkey->input, EV_KEY, KEY_SLEEP);
INIT_DELAYED_WORK(&onkey->work, da9063_poll_on);
error = devm_add_action(&pdev->dev, da9063_cancel_poll, onkey);
if (error) {
dev_err(&pdev->dev,
"Failed to add cancel poll action: %d\n",
error);
return error;
}
irq = platform_get_irq_byname(pdev, "ONKEY");
if (irq < 0) {
error = irq;
dev_err(&pdev->dev, "Failed to get platform IRQ: %d\n", error);
return error;
}
error = devm_request_threaded_irq(&pdev->dev, irq,
NULL, da9063_onkey_irq_handler,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"ONKEY", onkey);
if (error) {
dev_err(&pdev->dev,
"Failed to request IRQ %d: %d\n", irq, error);
return error;
}
error = input_register_device(onkey->input);
if (error) {
dev_err(&pdev->dev,
"Failed to register input device: %d\n", error);
return error;
}
platform_set_drvdata(pdev, onkey);
return 0;
}
