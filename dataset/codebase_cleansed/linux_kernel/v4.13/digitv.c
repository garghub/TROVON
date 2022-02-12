static int digitv_ctrl_msg(struct dvb_usb_device *d,
u8 cmd, u8 vv, u8 *wbuf, int wlen, u8 *rbuf, int rlen)
{
struct digitv_state *st = d->priv;
int ret, wo;
wo = (rbuf == NULL || rlen == 0);
if (wlen > 4 || rlen > 4)
return -EIO;
memset(st->sndbuf, 0, 7);
memset(st->rcvbuf, 0, 7);
st->sndbuf[0] = cmd;
st->sndbuf[1] = vv;
st->sndbuf[2] = wo ? wlen : rlen;
if (wo) {
memcpy(&st->sndbuf[3], wbuf, wlen);
ret = dvb_usb_generic_write(d, st->sndbuf, 7);
} else {
ret = dvb_usb_generic_rw(d, st->sndbuf, 7, st->rcvbuf, 7, 10);
memcpy(rbuf, &st->rcvbuf[3], rlen);
}
return ret;
}
static int digitv_i2c_xfer(struct i2c_adapter *adap,struct i2c_msg msg[],int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
int i;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
if (num > 2)
warn("more than 2 i2c messages at a time is not handled yet. TODO.");
for (i = 0; i < num; i++) {
if (i+1 < num && (msg[i+1].flags & I2C_M_RD)) {
if (digitv_ctrl_msg(d, USB_READ_COFDM, msg[i].buf[0], NULL, 0,
msg[i+1].buf,msg[i+1].len) < 0)
break;
i++;
} else
if (digitv_ctrl_msg(d,USB_WRITE_COFDM, msg[i].buf[0],
&msg[i].buf[1],msg[i].len-1,NULL,0) < 0)
break;
}
mutex_unlock(&d->i2c_mutex);
return i;
}
static u32 digitv_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int digitv_identify_state (struct usb_device *udev, struct
dvb_usb_device_properties *props, struct dvb_usb_device_description **desc,
int *cold)
{
*cold = udev->descriptor.iManufacturer == 0 && udev->descriptor.iProduct == 0;
return 0;
}
static int digitv_mt352_demod_init(struct dvb_frontend *fe)
{
static u8 reset_buf[] = { 0x89, 0x38, 0x8a, 0x2d, 0x50, 0x80 };
static u8 init_buf[] = { 0x68, 0xa0, 0x8e, 0x40, 0x53, 0x50,
0x67, 0x20, 0x7d, 0x01, 0x7c, 0x00, 0x7a, 0x00,
0x79, 0x20, 0x57, 0x05, 0x56, 0x31, 0x88, 0x0f,
0x75, 0x32 };
int i;
for (i = 0; i < ARRAY_SIZE(reset_buf); i += 2)
mt352_write(fe, &reset_buf[i], 2);
msleep(1);
for (i = 0; i < ARRAY_SIZE(init_buf); i += 2)
mt352_write(fe, &init_buf[i], 2);
return 0;
}
static int digitv_nxt6000_tuner_set_params(struct dvb_frontend *fe)
{
struct dvb_usb_adapter *adap = fe->dvb->priv;
u8 b[5];
fe->ops.tuner_ops.calc_regs(fe, b, sizeof(b));
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
return digitv_ctrl_msg(adap->dev, USB_WRITE_TUNER, 0, &b[1], 4, NULL, 0);
}
static int digitv_frontend_attach(struct dvb_usb_adapter *adap)
{
struct digitv_state *st = adap->dev->priv;
adap->fe_adap[0].fe = dvb_attach(mt352_attach, &digitv_mt352_config,
&adap->dev->i2c_adap);
if ((adap->fe_adap[0].fe) != NULL) {
st->is_nxt6000 = 0;
return 0;
}
adap->fe_adap[0].fe = dvb_attach(nxt6000_attach,
&digitv_nxt6000_config,
&adap->dev->i2c_adap);
if ((adap->fe_adap[0].fe) != NULL) {
st->is_nxt6000 = 1;
return 0;
}
return -EIO;
}
static int digitv_tuner_attach(struct dvb_usb_adapter *adap)
{
struct digitv_state *st = adap->dev->priv;
if (!dvb_attach(dvb_pll_attach, adap->fe_adap[0].fe, 0x60, NULL, DVB_PLL_TDED4))
return -ENODEV;
if (st->is_nxt6000)
adap->fe_adap[0].fe->ops.tuner_ops.set_params = digitv_nxt6000_tuner_set_params;
return 0;
}
static int digitv_rc_query(struct dvb_usb_device *d, u32 *event, int *state)
{
int i;
u8 key[5];
u8 b[4] = { 0 };
*event = 0;
*state = REMOTE_NO_KEY_PRESSED;
digitv_ctrl_msg(d,USB_READ_REMOTE,0,NULL,0,&key[1],4);
digitv_ctrl_msg(d,USB_WRITE_REMOTE,0,b,4,NULL,0);
if (key[1] != 0)
{
for (i = 0; i < d->props.rc.legacy.rc_map_size; i++) {
if (rc5_custom(&d->props.rc.legacy.rc_map_table[i]) == key[1] &&
rc5_data(&d->props.rc.legacy.rc_map_table[i]) == key[2]) {
*event = d->props.rc.legacy.rc_map_table[i].keycode;
*state = REMOTE_KEY_PRESSED;
return 0;
}
}
}
if (key[0] != 0)
deb_rc("key: %*ph\n", 5, key);
return 0;
}
static int digitv_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct dvb_usb_device *d;
int ret = dvb_usb_device_init(intf, &digitv_properties, THIS_MODULE, &d,
adapter_nr);
if (ret == 0) {
u8 b[4] = { 0 };
if (d != NULL) {
b[0] = 1;
digitv_ctrl_msg(d,USB_WRITE_REMOTE_TYPE,0,b,4,NULL,0);
b[0] = 0;
digitv_ctrl_msg(d,USB_WRITE_REMOTE,0,b,4,NULL,0);
}
}
return ret;
}
