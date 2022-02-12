static int hid_sensor_data_rdy_trigger_set_state(struct iio_trigger *trig,
bool state)
{
struct hid_sensor_iio_common *st = trig->private_data;
int state_val;
state_val = state ? 1 : 0;
if (IS_ENABLED(CONFIG_HID_SENSOR_ENUM_BASE_QUIRKS))
++state_val;
st->data_ready = state;
sensor_hub_set_feature(st->hsdev, st->power_state.report_id,
st->power_state.index,
(s32)state_val);
sensor_hub_set_feature(st->hsdev, st->report_state.report_id,
st->report_state.index,
(s32)state_val);
return 0;
}
void hid_sensor_remove_trigger(struct iio_dev *indio_dev)
{
iio_trigger_unregister(indio_dev->trig);
iio_trigger_free(indio_dev->trig);
indio_dev->trig = NULL;
}
int hid_sensor_setup_trigger(struct iio_dev *indio_dev, const char *name,
struct hid_sensor_iio_common *attrb)
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
trig->private_data = attrb;
trig->ops = &hid_sensor_trigger_ops;
ret = iio_trigger_register(trig);
if (ret) {
dev_err(&indio_dev->dev, "Trigger Register Failed\n");
goto error_free_trig;
}
indio_dev->trig = trig;
return ret;
error_free_trig:
iio_trigger_free(trig);
error_ret:
return ret;
}
