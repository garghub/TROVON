static int _hid_sensor_power_state(struct hid_sensor_common *st, bool state)
{
int state_val;
int report_val;
s32 poll_value = 0;
if (state) {
if (!atomic_read(&st->user_requested_state))
return 0;
if (sensor_hub_device_open(st->hsdev))
return -EIO;
atomic_inc(&st->data_ready);
state_val = hid_sensor_get_usage_index(st->hsdev,
st->power_state.report_id,
st->power_state.index,
HID_USAGE_SENSOR_PROP_POWER_STATE_D0_FULL_POWER_ENUM);
report_val = hid_sensor_get_usage_index(st->hsdev,
st->report_state.report_id,
st->report_state.index,
HID_USAGE_SENSOR_PROP_REPORTING_STATE_ALL_EVENTS_ENUM);
poll_value = hid_sensor_read_poll_value(st);
} else {
int val;
val = atomic_dec_if_positive(&st->data_ready);
if (val < 0)
return 0;
sensor_hub_device_close(st->hsdev);
state_val = hid_sensor_get_usage_index(st->hsdev,
st->power_state.report_id,
st->power_state.index,
HID_USAGE_SENSOR_PROP_POWER_STATE_D4_POWER_OFF_ENUM);
report_val = hid_sensor_get_usage_index(st->hsdev,
st->report_state.report_id,
st->report_state.index,
HID_USAGE_SENSOR_PROP_REPORTING_STATE_NO_EVENTS_ENUM);
}
if (state_val >= 0) {
state_val += st->power_state.logical_minimum;
sensor_hub_set_feature(st->hsdev, st->power_state.report_id,
st->power_state.index, sizeof(state_val),
&state_val);
}
if (report_val >= 0) {
report_val += st->report_state.logical_minimum;
sensor_hub_set_feature(st->hsdev, st->report_state.report_id,
st->report_state.index,
sizeof(report_val),
&report_val);
}
sensor_hub_get_feature(st->hsdev, st->power_state.report_id,
st->power_state.index,
sizeof(state_val), &state_val);
if (state && poll_value)
msleep_interruptible(poll_value * 2);
return 0;
}
int hid_sensor_power_state(struct hid_sensor_common *st, bool state)
{
#ifdef CONFIG_PM
int ret;
atomic_set(&st->user_requested_state, state);
if (state)
ret = pm_runtime_get_sync(&st->pdev->dev);
else {
pm_runtime_mark_last_busy(&st->pdev->dev);
ret = pm_runtime_put_autosuspend(&st->pdev->dev);
}
if (ret < 0) {
if (state)
pm_runtime_put_noidle(&st->pdev->dev);
return ret;
}
return 0;
#else
atomic_set(&st->user_requested_state, state);
return _hid_sensor_power_state(st, state);
#endif
}
static int hid_sensor_data_rdy_trigger_set_state(struct iio_trigger *trig,
bool state)
{
return hid_sensor_power_state(iio_trigger_get_drvdata(trig), state);
}
void hid_sensor_remove_trigger(struct hid_sensor_common *attrb)
{
iio_trigger_unregister(attrb->trigger);
iio_trigger_free(attrb->trigger);
}
int hid_sensor_setup_trigger(struct iio_dev *indio_dev, const char *name,
struct hid_sensor_common *attrb)
{
int ret;
struct iio_trigger *trig;
trig = iio_trigger_alloc("%s-dev%d", name, indio_dev->id);
if (trig == NULL) {
dev_err(&indio_dev->dev, "Trigger Allocate Failed\n");
ret = -ENOMEM;
goto error_ret;
}
trig->dev.parent = indio_dev->dev.parent;
iio_trigger_set_drvdata(trig, attrb);
trig->ops = &hid_sensor_trigger_ops;
ret = iio_trigger_register(trig);
if (ret) {
dev_err(&indio_dev->dev, "Trigger Register Failed\n");
goto error_free_trig;
}
attrb->trigger = trig;
indio_dev->trig = iio_trigger_get(trig);
ret = pm_runtime_set_active(&indio_dev->dev);
if (ret)
goto error_unreg_trigger;
iio_device_set_drvdata(indio_dev, attrb);
pm_suspend_ignore_children(&attrb->pdev->dev, true);
pm_runtime_enable(&attrb->pdev->dev);
pm_runtime_set_autosuspend_delay(&attrb->pdev->dev,
3000);
pm_runtime_use_autosuspend(&attrb->pdev->dev);
return ret;
error_unreg_trigger:
iio_trigger_unregister(trig);
error_free_trig:
iio_trigger_free(trig);
error_ret:
return ret;
}
static int hid_sensor_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct hid_sensor_common *attrb = iio_device_get_drvdata(indio_dev);
return _hid_sensor_power_state(attrb, false);
}
static int hid_sensor_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct hid_sensor_common *attrb = iio_device_get_drvdata(indio_dev);
return _hid_sensor_power_state(attrb, true);
}
