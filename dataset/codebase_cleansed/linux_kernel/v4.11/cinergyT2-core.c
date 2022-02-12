static int cinergyt2_streaming_ctrl(struct dvb_usb_adapter *adap, int enable)
{
struct dvb_usb_device *d = adap->dev;
struct cinergyt2_state *st = d->priv;
int ret;
mutex_lock(&d->data_mutex);
st->data[0] = CINERGYT2_EP1_CONTROL_STREAM_TRANSFER;
st->data[1] = enable ? 1 : 0;
ret = dvb_usb_generic_rw(d, st->data, 2, st->data, 64, 0);
mutex_unlock(&d->data_mutex);
return ret;
}
static int cinergyt2_power_ctrl(struct dvb_usb_device *d, int enable)
{
struct cinergyt2_state *st = d->priv;
int ret;
mutex_lock(&d->data_mutex);
st->data[0] = CINERGYT2_EP1_SLEEP_MODE;
st->data[1] = enable ? 0 : 1;
ret = dvb_usb_generic_rw(d, st->data, 2, st->data, 3, 0);
mutex_unlock(&d->data_mutex);
return ret;
}
static int cinergyt2_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dvb_usb_device *d = adap->dev;
struct cinergyt2_state *st = d->priv;
int ret;
adap->fe_adap[0].fe = cinergyt2_fe_attach(adap->dev);
mutex_lock(&d->data_mutex);
st->data[0] = CINERGYT2_EP1_GET_FIRMWARE_VERSION;
ret = dvb_usb_generic_rw(d, st->data, 1, st->data, 3, 0);
if (ret < 0) {
deb_rc("cinergyt2_power_ctrl() Failed to retrieve sleep state info\n");
}
mutex_unlock(&d->data_mutex);
cinergyt2_usb_device = adap->dev;
return ret;
}
static int cinergyt2_rc_query(struct dvb_usb_device *d, u32 *event, int *state)
{
struct cinergyt2_state *st = d->priv;
int i, ret;
*state = REMOTE_NO_KEY_PRESSED;
mutex_lock(&d->data_mutex);
st->data[0] = CINERGYT2_EP1_GET_RC_EVENTS;
ret = dvb_usb_generic_rw(d, st->data, 1, st->data, 5, 0);
if (ret < 0)
goto ret;
if (st->data[4] == 0xff) {
st->rc_counter++;
if (st->rc_counter > RC_REPEAT_DELAY) {
for (i = 0; i < ARRAY_SIZE(repeatable_keys); i++) {
if (d->last_event == repeatable_keys[i]) {
*state = REMOTE_KEY_REPEAT;
*event = d->last_event;
deb_rc("repeat key, event %x\n",
*event);
goto ret;
}
}
deb_rc("repeated key (non repeatable)\n");
}
goto ret;
}
st->data[2] = ~st->data[1];
dvb_usb_nec_rc_key_to_event(d, st->data, event, state);
if (st->data[0] != 0) {
if (*event != d->last_event)
st->rc_counter = 0;
deb_rc("key: %*ph\n", 5, st->data);
}
ret:
mutex_unlock(&d->data_mutex);
return ret;
}
static int cinergyt2_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return dvb_usb_device_init(intf, &cinergyt2_properties,
THIS_MODULE, NULL, adapter_nr);
}
