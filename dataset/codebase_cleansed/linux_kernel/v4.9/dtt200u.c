static int dtt200u_power_ctrl(struct dvb_usb_device *d, int onoff)
{
struct dtt200u_state *st = d->priv;
int ret = 0;
mutex_lock(&d->data_mutex);
st->data[0] = SET_INIT;
if (onoff)
ret = dvb_usb_generic_write(d, st->data, 2);
mutex_unlock(&d->data_mutex);
return ret;
}
static int dtt200u_streaming_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
struct dvb_usb_device *d = adap->dev;
struct dtt200u_state *st = d->priv;
int ret;
mutex_lock(&d->data_mutex);
st->data[0] = SET_STREAMING;
st->data[1] = onoff;
ret = dvb_usb_generic_write(adap->dev, st->data, 2);
if (ret < 0)
goto ret;
if (onoff)
goto ret;
st->data[0] = RESET_PID_FILTER;
ret = dvb_usb_generic_write(adap->dev, st->data, 1);
ret:
mutex_unlock(&d->data_mutex);
return ret;
}
static int dtt200u_pid_filter(struct dvb_usb_adapter *adap, int index, u16 pid, int onoff)
{
struct dvb_usb_device *d = adap->dev;
struct dtt200u_state *st = d->priv;
int ret;
pid = onoff ? pid : 0;
mutex_lock(&d->data_mutex);
st->data[0] = SET_PID_FILTER;
st->data[1] = index;
st->data[2] = pid & 0xff;
st->data[3] = (pid >> 8) & 0x1f;
ret = dvb_usb_generic_write(adap->dev, st->data, 4);
mutex_unlock(&d->data_mutex);
return ret;
}
static int dtt200u_rc_query(struct dvb_usb_device *d)
{
struct dtt200u_state *st = d->priv;
u32 scancode;
int ret;
mutex_lock(&d->data_mutex);
st->data[0] = GET_RC_CODE;
ret = dvb_usb_generic_rw(d, st->data, 1, st->data, 5, 0);
if (ret < 0)
goto ret;
if (st->data[0] == 1) {
enum rc_type proto = RC_TYPE_NEC;
scancode = st->data[1];
if ((u8) ~st->data[1] != st->data[2]) {
scancode = scancode << 8;
scancode |= st->data[2];
proto = RC_TYPE_NECX;
}
scancode = scancode << 8;
scancode |= st->data[3];
if ((u8) ~st->data[3] == st->data[4])
rc_keydown(d->rc_dev, proto, scancode, 0);
else
rc_keyup(d->rc_dev);
} else if (st->data[0] == 2) {
rc_repeat(d->rc_dev);
} else {
rc_keyup(d->rc_dev);
}
if (st->data[0] != 0)
deb_info("st->data: %*ph\n", 5, st->data);
ret:
mutex_unlock(&d->data_mutex);
return ret;
}
static int dtt200u_frontend_attach(struct dvb_usb_adapter *adap)
{
adap->fe_adap[0].fe = dtt200u_fe_attach(adap->dev);
return 0;
}
static int dtt200u_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
if (0 == dvb_usb_device_init(intf, &dtt200u_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &wt220u_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &wt220u_fc_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &wt220u_zl0353_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &wt220u_miglia_properties,
THIS_MODULE, NULL, adapter_nr))
return 0;
return -ENODEV;
}
