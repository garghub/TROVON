static int hid_sensor_data_rdy_trigger_set_state(struct iio_trigger *trig,
bool state)
{
struct hid_sensor_common *st = iio_trigger_get_drvdata(trig);
int state_val;
int report_val;
if (state) {
if (sensor_hub_device_open(st->hsdev))
return -EIO;
state_val = hid_sensor_get_usage_index(st->hsdev,
st->power_state.report_id,
st->power_state.index,
HID_USAGE_SENSOR_PROP_POWER_STATE_D0_FULL_POWER_ENUM);
report_val = hid_sensor_get_usage_index(st->hsdev,
st->report_state.report_id,
st->report_state.index,
HID_USAGE_SENSOR_PROP_REPORTING_STATE_ALL_EVENTS_ENUM);
} else {
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
st->data_ready = state;
if (state_val >= 0) {
state_val += st->power_state.logical_minimum;
sensor_hub_set_feature(st->hsdev, st->power_state.report_id,
st->power_state.index,
(s32)state_val);
}
if (report_val >= 0) {
report_val += st->report_state.logical_minimum;
sensor_hub_set_feature(st->hsdev, st->report_state.report_id,
st->report_state.index,
(s32)report_val);
}
return 0;
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
indio_dev->trig = attrb->trigger = trig;
return ret;
error_free_trig:
iio_trigger_free(trig);
error_ret:
return ret;
}
