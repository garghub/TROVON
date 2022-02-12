static int dvbsky_usb_generic_rw(struct dvb_usb_device *d,
u8 *wbuf, u16 wlen, u8 *rbuf, u16 rlen)
{
int ret;
struct dvbsky_state *state = d_to_priv(d);
mutex_lock(&d->usb_mutex);
if (wlen != 0)
memcpy(state->obuf, wbuf, wlen);
ret = dvb_usbv2_generic_rw_locked(d, state->obuf, wlen,
state->ibuf, rlen);
if (!ret && (rlen != 0))
memcpy(rbuf, state->ibuf, rlen);
mutex_unlock(&d->usb_mutex);
return ret;
}
static int dvbsky_stream_ctrl(struct dvb_usb_device *d, u8 onoff)
{
struct dvbsky_state *state = d_to_priv(d);
int ret;
u8 obuf_pre[3] = { 0x37, 0, 0 };
u8 obuf_post[3] = { 0x36, 3, 0 };
mutex_lock(&state->stream_mutex);
ret = dvbsky_usb_generic_rw(d, obuf_pre, 3, NULL, 0);
if (!ret && onoff) {
msleep(20);
ret = dvbsky_usb_generic_rw(d, obuf_post, 3, NULL, 0);
}
mutex_unlock(&state->stream_mutex);
return ret;
}
static int dvbsky_streaming_ctrl(struct dvb_frontend *fe, int onoff)
{
struct dvb_usb_device *d = fe_to_d(fe);
return dvbsky_stream_ctrl(d, (onoff == 0) ? 0 : 1);
}
static int dvbsky_gpio_ctrl(struct dvb_usb_device *d, u8 gport, u8 value)
{
int ret;
u8 obuf[3], ibuf[2];
obuf[0] = 0x0e;
obuf[1] = gport;
obuf[2] = value;
ret = dvbsky_usb_generic_rw(d, obuf, 3, ibuf, 1);
if (ret)
dev_err(&d->udev->dev, "%s: %s() failed=%d\n",
KBUILD_MODNAME, __func__, ret);
return ret;
}
static int dvbsky_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msg[],
int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
int ret = 0;
u8 ibuf[64], obuf[64];
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
if (num > 2) {
dev_err(&d->udev->dev,
"dvbsky_usb: too many i2c messages[%d] than 2.", num);
ret = -EOPNOTSUPP;
goto i2c_error;
}
if (num == 1) {
if (msg[0].len > 60) {
dev_err(&d->udev->dev,
"dvbsky_usb: too many i2c bytes[%d] than 60.",
msg[0].len);
ret = -EOPNOTSUPP;
goto i2c_error;
}
if (msg[0].flags & I2C_M_RD) {
obuf[0] = 0x09;
obuf[1] = 0;
obuf[2] = msg[0].len;
obuf[3] = msg[0].addr;
ret = dvbsky_usb_generic_rw(d, obuf, 4,
ibuf, msg[0].len + 1);
if (ret)
dev_err(&d->udev->dev, "%s: %s() failed=%d\n",
KBUILD_MODNAME, __func__, ret);
if (!ret)
memcpy(msg[0].buf, &ibuf[1], msg[0].len);
} else {
obuf[0] = 0x08;
obuf[1] = msg[0].addr;
obuf[2] = msg[0].len;
memcpy(&obuf[3], msg[0].buf, msg[0].len);
ret = dvbsky_usb_generic_rw(d, obuf,
msg[0].len + 3, ibuf, 1);
if (ret)
dev_err(&d->udev->dev, "%s: %s() failed=%d\n",
KBUILD_MODNAME, __func__, ret);
}
} else {
if ((msg[0].len > 60) || (msg[1].len > 60)) {
dev_err(&d->udev->dev,
"dvbsky_usb: too many i2c bytes[w-%d][r-%d] than 60.",
msg[0].len, msg[1].len);
ret = -EOPNOTSUPP;
goto i2c_error;
}
obuf[0] = 0x09;
obuf[1] = msg[0].len;
obuf[2] = msg[1].len;
obuf[3] = msg[0].addr;
memcpy(&obuf[4], msg[0].buf, msg[0].len);
ret = dvbsky_usb_generic_rw(d, obuf,
msg[0].len + 4, ibuf, msg[1].len + 1);
if (ret)
dev_err(&d->udev->dev, "%s: %s() failed=%d\n",
KBUILD_MODNAME, __func__, ret);
if (!ret)
memcpy(msg[1].buf, &ibuf[1], msg[1].len);
}
i2c_error:
mutex_unlock(&d->i2c_mutex);
return (ret) ? ret : num;
}
static u32 dvbsky_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int dvbsky_rc_query(struct dvb_usb_device *d)
{
u32 code = 0xffff, scancode;
u8 rc5_command, rc5_system;
u8 obuf[2], ibuf[2], toggle;
int ret;
obuf[0] = 0x10;
ret = dvbsky_usb_generic_rw(d, obuf, 1, ibuf, 2);
if (ret)
dev_err(&d->udev->dev, "%s: %s() failed=%d\n",
KBUILD_MODNAME, __func__, ret);
if (ret == 0)
code = (ibuf[0] << 8) | ibuf[1];
if (code != 0xffff) {
dev_dbg(&d->udev->dev, "rc code: %x\n", code);
rc5_command = code & 0x3F;
rc5_system = (code & 0x7C0) >> 6;
toggle = (code & 0x800) ? 1 : 0;
scancode = rc5_system << 8 | rc5_command;
rc_keydown(d->rc_dev, RC_TYPE_RC5, scancode, toggle);
}
return 0;
}
static int dvbsky_get_rc_config(struct dvb_usb_device *d, struct dvb_usb_rc *rc)
{
rc->allowed_protos = RC_BIT_RC5;
rc->query = dvbsky_rc_query;
rc->interval = 300;
return 0;
}
static int dvbsky_usb_set_voltage(struct dvb_frontend *fe,
fe_sec_voltage_t voltage)
{
struct dvb_usb_device *d = fe_to_d(fe);
struct dvbsky_state *state = d_to_priv(d);
u8 value;
if (voltage == SEC_VOLTAGE_OFF)
value = 0;
else
value = 1;
dvbsky_gpio_ctrl(d, 0x80, value);
return state->fe_set_voltage(fe, voltage);
}
static int dvbsky_read_mac_addr(struct dvb_usb_adapter *adap, u8 mac[6])
{
struct dvb_usb_device *d = adap_to_d(adap);
u8 obuf[] = { 0x1e, 0x00 };
u8 ibuf[6] = { 0 };
struct i2c_msg msg[] = {
{
.addr = 0x51,
.flags = 0,
.buf = obuf,
.len = 2,
}, {
.addr = 0x51,
.flags = I2C_M_RD,
.buf = ibuf,
.len = 6,
}
};
if (i2c_transfer(&d->i2c_adap, msg, 2) == 2)
memcpy(mac, ibuf, 6);
dev_info(&d->udev->dev, "dvbsky_usb MAC address=%pM\n", mac);
return 0;
}
static int dvbsky_usb_read_status(struct dvb_frontend *fe, fe_status_t *status)
{
struct dvb_usb_device *d = fe_to_d(fe);
struct dvbsky_state *state = d_to_priv(d);
int ret;
ret = state->fe_read_status(fe, status);
if ((*status & FE_HAS_LOCK) && (!state->last_lock))
dvbsky_stream_ctrl(d, 1);
state->last_lock = (*status & FE_HAS_LOCK) ? 1 : 0;
return ret;
}
static int dvbsky_s960_attach(struct dvb_usb_adapter *adap)
{
struct dvbsky_state *state = adap_to_priv(adap);
struct dvb_usb_device *d = adap_to_d(adap);
int ret = 0;
struct i2c_adapter *i2c_adapter;
struct i2c_client *client;
struct i2c_board_info info;
struct m88ts2022_config m88ts2022_config = {
.clock = 27000000,
};
memset(&info, 0, sizeof(struct i2c_board_info));
adap->fe[0] = dvb_attach(m88ds3103_attach,
&dvbsky_s960_m88ds3103_config,
&d->i2c_adap,
&i2c_adapter);
if (!adap->fe[0]) {
dev_err(&d->udev->dev, "dvbsky_s960_attach fail.\n");
ret = -ENODEV;
goto fail_attach;
}
m88ts2022_config.fe = adap->fe[0];
strlcpy(info.type, "m88ts2022", I2C_NAME_SIZE);
info.addr = 0x60;
info.platform_data = &m88ts2022_config;
request_module("m88ts2022");
client = i2c_new_device(i2c_adapter, &info);
if (client == NULL || client->dev.driver == NULL) {
dvb_frontend_detach(adap->fe[0]);
ret = -ENODEV;
goto fail_attach;
}
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
dvb_frontend_detach(adap->fe[0]);
ret = -ENODEV;
goto fail_attach;
}
adap->fe[0]->ops.read_signal_strength =
adap->fe[0]->ops.tuner_ops.get_rf_strength;
state->fe_read_status = adap->fe[0]->ops.read_status;
adap->fe[0]->ops.read_status = dvbsky_usb_read_status;
state->fe_set_voltage = adap->fe[0]->ops.set_voltage;
adap->fe[0]->ops.set_voltage = dvbsky_usb_set_voltage;
state->i2c_client_tuner = client;
fail_attach:
return ret;
}
static int dvbsky_identify_state(struct dvb_usb_device *d, const char **name)
{
dvbsky_gpio_ctrl(d, 0x04, 1);
msleep(20);
dvbsky_gpio_ctrl(d, 0x83, 0);
dvbsky_gpio_ctrl(d, 0xc0, 1);
msleep(100);
dvbsky_gpio_ctrl(d, 0x83, 1);
dvbsky_gpio_ctrl(d, 0xc0, 0);
msleep(50);
return WARM;
}
static int dvbsky_init(struct dvb_usb_device *d)
{
struct dvbsky_state *state = d_to_priv(d);
mutex_init(&state->stream_mutex);
state->last_lock = 0;
return 0;
}
static void dvbsky_exit(struct dvb_usb_device *d)
{
struct dvbsky_state *state = d_to_priv(d);
struct i2c_client *client;
client = state->i2c_client_tuner;
if (client) {
module_put(client->dev.driver->owner);
i2c_unregister_device(client);
}
}
