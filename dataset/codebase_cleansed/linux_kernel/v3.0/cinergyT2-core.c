static int cinergyt2_streaming_ctrl(struct dvb_usb_adapter *adap, int enable)
{
char buf[] = { CINERGYT2_EP1_CONTROL_STREAM_TRANSFER, enable ? 1 : 0 };
char result[64];
return dvb_usb_generic_rw(adap->dev, buf, sizeof(buf), result,
sizeof(result), 0);
}
static int cinergyt2_power_ctrl(struct dvb_usb_device *d, int enable)
{
char buf[] = { CINERGYT2_EP1_SLEEP_MODE, enable ? 0 : 1 };
char state[3];
return dvb_usb_generic_rw(d, buf, sizeof(buf), state, sizeof(state), 0);
}
static int cinergyt2_frontend_attach(struct dvb_usb_adapter *adap)
{
char query[] = { CINERGYT2_EP1_GET_FIRMWARE_VERSION };
char state[3];
int ret;
adap->fe = cinergyt2_fe_attach(adap->dev);
ret = dvb_usb_generic_rw(adap->dev, query, sizeof(query), state,
sizeof(state), 0);
if (ret < 0) {
deb_rc("cinergyt2_power_ctrl() Failed to retrieve sleep "
"state info\n");
}
cinergyt2_usb_device = adap->dev;
return 0;
}
static int cinergyt2_rc_query(struct dvb_usb_device *d, u32 *event, int *state)
{
struct cinergyt2_state *st = d->priv;
u8 key[5] = {0, 0, 0, 0, 0}, cmd = CINERGYT2_EP1_GET_RC_EVENTS;
int i;
*state = REMOTE_NO_KEY_PRESSED;
dvb_usb_generic_rw(d, &cmd, 1, key, sizeof(key), 0);
if (key[4] == 0xff) {
st->rc_counter++;
if (st->rc_counter > RC_REPEAT_DELAY) {
for (i = 0; i < ARRAY_SIZE(repeatable_keys); i++) {
if (d->last_event == repeatable_keys[i]) {
*state = REMOTE_KEY_REPEAT;
*event = d->last_event;
deb_rc("repeat key, event %x\n",
*event);
return 0;
}
}
deb_rc("repeated key (non repeatable)\n");
}
return 0;
}
key[2] = ~key[1];
dvb_usb_nec_rc_key_to_event(d, key, event, state);
if (key[0] != 0) {
if (*event != d->last_event)
st->rc_counter = 0;
deb_rc("key: %x %x %x %x %x\n",
key[0], key[1], key[2], key[3], key[4]);
}
return 0;
}
static int cinergyt2_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return dvb_usb_device_init(intf, &cinergyt2_properties,
THIS_MODULE, NULL, adapter_nr);
}
static int __init cinergyt2_usb_init(void)
{
int err;
err = usb_register(&cinergyt2_driver);
if (err) {
err("usb_register() failed! (err %i)\n", err);
return err;
}
return 0;
}
static void __exit cinergyt2_usb_exit(void)
{
usb_deregister(&cinergyt2_driver);
}
