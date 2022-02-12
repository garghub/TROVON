static irqreturn_t ec_irq_thread(int irq, void *data)
{
struct cros_ec_device *ec_dev = data;
int ret;
if (device_may_wakeup(ec_dev->dev))
pm_wakeup_event(ec_dev->dev, 0);
ret = cros_ec_get_next_event(ec_dev);
if (ret > 0)
blocking_notifier_call_chain(&ec_dev->event_notifier,
0, ec_dev);
return IRQ_HANDLED;
}
static int cros_ec_sleep_event(struct cros_ec_device *ec_dev, u8 sleep_event)
{
struct {
struct cros_ec_command msg;
struct ec_params_host_sleep_event req;
} __packed buf;
memset(&buf, 0, sizeof(buf));
buf.req.sleep_event = sleep_event;
buf.msg.command = EC_CMD_HOST_SLEEP_EVENT;
buf.msg.version = 0;
buf.msg.outsize = sizeof(buf.req);
return cros_ec_cmd_xfer(ec_dev, &buf.msg);
}
int cros_ec_register(struct cros_ec_device *ec_dev)
{
struct device *dev = ec_dev->dev;
int err = 0;
BLOCKING_INIT_NOTIFIER_HEAD(&ec_dev->event_notifier);
ec_dev->max_request = sizeof(struct ec_params_hello);
ec_dev->max_response = sizeof(struct ec_response_get_protocol_info);
ec_dev->max_passthru = 0;
ec_dev->din = devm_kzalloc(dev, ec_dev->din_size, GFP_KERNEL);
if (!ec_dev->din)
return -ENOMEM;
ec_dev->dout = devm_kzalloc(dev, ec_dev->dout_size, GFP_KERNEL);
if (!ec_dev->dout)
return -ENOMEM;
mutex_init(&ec_dev->lock);
cros_ec_query_all(ec_dev);
if (ec_dev->irq) {
err = request_threaded_irq(ec_dev->irq, NULL, ec_irq_thread,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"chromeos-ec", ec_dev);
if (err) {
dev_err(dev, "Failed to request IRQ %d: %d",
ec_dev->irq, err);
return err;
}
}
err = mfd_add_devices(ec_dev->dev, PLATFORM_DEVID_AUTO, &ec_cell, 1,
NULL, ec_dev->irq, NULL);
if (err) {
dev_err(dev,
"Failed to register Embedded Controller subdevice %d\n",
err);
goto fail_mfd;
}
if (ec_dev->max_passthru) {
err = mfd_add_devices(ec_dev->dev, PLATFORM_DEVID_AUTO,
&ec_pd_cell, 1, NULL, ec_dev->irq, NULL);
if (err) {
dev_err(dev,
"Failed to register Power Delivery subdevice %d\n",
err);
goto fail_mfd;
}
}
if (IS_ENABLED(CONFIG_OF) && dev->of_node) {
err = of_platform_populate(dev->of_node, NULL, NULL, dev);
if (err) {
mfd_remove_devices(dev);
dev_err(dev, "Failed to register sub-devices\n");
goto fail_mfd;
}
}
err = cros_ec_sleep_event(ec_dev, 0);
if (err < 0)
dev_dbg(ec_dev->dev, "Error %d clearing sleep event to ec",
err);
dev_info(dev, "Chrome EC device registered\n");
return 0;
fail_mfd:
if (ec_dev->irq)
free_irq(ec_dev->irq, ec_dev);
return err;
}
int cros_ec_remove(struct cros_ec_device *ec_dev)
{
mfd_remove_devices(ec_dev->dev);
return 0;
}
int cros_ec_suspend(struct cros_ec_device *ec_dev)
{
struct device *dev = ec_dev->dev;
int ret;
u8 sleep_event;
sleep_event = (!IS_ENABLED(CONFIG_ACPI) || pm_suspend_via_firmware()) ?
HOST_SLEEP_EVENT_S3_RESUME :
HOST_SLEEP_EVENT_S0IX_RESUME;
ret = cros_ec_sleep_event(ec_dev, sleep_event);
if (ret < 0)
dev_dbg(ec_dev->dev, "Error %d sending suspend event to ec",
ret);
if (device_may_wakeup(dev))
ec_dev->wake_enabled = !enable_irq_wake(ec_dev->irq);
disable_irq(ec_dev->irq);
ec_dev->was_wake_device = ec_dev->wake_enabled;
ec_dev->suspended = true;
return 0;
}
static void cros_ec_drain_events(struct cros_ec_device *ec_dev)
{
while (cros_ec_get_next_event(ec_dev) > 0)
blocking_notifier_call_chain(&ec_dev->event_notifier,
1, ec_dev);
}
int cros_ec_resume(struct cros_ec_device *ec_dev)
{
int ret;
u8 sleep_event;
ec_dev->suspended = false;
enable_irq(ec_dev->irq);
sleep_event = (!IS_ENABLED(CONFIG_ACPI) || pm_suspend_via_firmware()) ?
HOST_SLEEP_EVENT_S3_RESUME :
HOST_SLEEP_EVENT_S0IX_RESUME;
ret = cros_ec_sleep_event(ec_dev, sleep_event);
if (ret < 0)
dev_dbg(ec_dev->dev, "Error %d sending resume event to ec",
ret);
if (ec_dev->wake_enabled) {
disable_irq_wake(ec_dev->irq);
ec_dev->wake_enabled = 0;
} else {
cros_ec_drain_events(ec_dev);
}
return 0;
}
