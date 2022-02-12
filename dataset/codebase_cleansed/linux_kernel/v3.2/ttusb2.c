static int ttusb2_msg(struct dvb_usb_device *d, u8 cmd,
u8 *wbuf, int wlen, u8 *rbuf, int rlen)
{
struct ttusb2_state *st = d->priv;
u8 s[wlen+4],r[64] = { 0 };
int ret = 0;
memset(s,0,wlen+4);
s[0] = 0xaa;
s[1] = ++st->id;
s[2] = cmd;
s[3] = wlen;
memcpy(&s[4],wbuf,wlen);
ret = dvb_usb_generic_rw(d, s, wlen+4, r, 64, 0);
if (ret != 0 ||
r[0] != 0x55 ||
r[1] != s[1] ||
r[2] != cmd ||
(rlen > 0 && r[3] != rlen)) {
warn("there might have been an error during control message transfer. (rlen = %d, was %d)",rlen,r[3]);
return -EIO;
}
if (rlen > 0)
memcpy(rbuf, &r[4], rlen);
return 0;
}
static int tt3650_ci_msg(struct dvb_usb_device *d, u8 cmd, u8 *data, unsigned int write_len, unsigned int read_len)
{
int ret;
u8 rx[60];
ret = ttusb2_msg(d, cmd, data, write_len, rx, read_len);
if (!ret)
memcpy(data, rx, read_len);
return ret;
}
static int tt3650_ci_msg_locked(struct dvb_ca_en50221 *ca, u8 cmd, u8 *data, unsigned int write_len, unsigned int read_len)
{
struct dvb_usb_device *d = ca->data;
struct ttusb2_state *state = d->priv;
int ret;
mutex_lock(&state->ca_mutex);
ret = tt3650_ci_msg(d, cmd, data, write_len, read_len);
mutex_unlock(&state->ca_mutex);
return ret;
}
static int tt3650_ci_read_attribute_mem(struct dvb_ca_en50221 *ca, int slot, int address)
{
u8 buf[3];
int ret = 0;
if (slot)
return -EINVAL;
buf[0] = (address >> 8) & 0x0F;
buf[1] = address;
ret = tt3650_ci_msg_locked(ca, TT3650_CMD_CI_RD_ATTR, buf, 2, 3);
ci_dbg("%04x -> %d 0x%02x", address, ret, buf[2]);
if (ret < 0)
return ret;
return buf[2];
}
static int tt3650_ci_write_attribute_mem(struct dvb_ca_en50221 *ca, int slot, int address, u8 value)
{
u8 buf[3];
ci_dbg("%d 0x%04x 0x%02x", slot, address, value);
if (slot)
return -EINVAL;
buf[0] = (address >> 8) & 0x0F;
buf[1] = address;
buf[2] = value;
return tt3650_ci_msg_locked(ca, TT3650_CMD_CI_WR_ATTR, buf, 3, 3);
}
static int tt3650_ci_read_cam_control(struct dvb_ca_en50221 *ca, int slot, u8 address)
{
u8 buf[2];
int ret;
if (slot)
return -EINVAL;
buf[0] = address & 3;
ret = tt3650_ci_msg_locked(ca, TT3650_CMD_CI_RD_CTRL, buf, 1, 2);
ci_dbg("0x%02x -> %d 0x%02x", address, ret, buf[1]);
if (ret < 0)
return ret;
return buf[1];
}
static int tt3650_ci_write_cam_control(struct dvb_ca_en50221 *ca, int slot, u8 address, u8 value)
{
u8 buf[2];
ci_dbg("%d 0x%02x 0x%02x", slot, address, value);
if (slot)
return -EINVAL;
buf[0] = address;
buf[1] = value;
return tt3650_ci_msg_locked(ca, TT3650_CMD_CI_WR_CTRL, buf, 2, 2);
}
static int tt3650_ci_set_video_port(struct dvb_ca_en50221 *ca, int slot, int enable)
{
u8 buf[1];
int ret;
ci_dbg("%d %d", slot, enable);
if (slot)
return -EINVAL;
buf[0] = enable;
ret = tt3650_ci_msg_locked(ca, TT3650_CMD_CI_SET_VIDEO_PORT, buf, 1, 1);
if (ret < 0)
return ret;
if (enable != buf[0]) {
err("CI not %sabled.", enable ? "en" : "dis");
return -EIO;
}
return 0;
}
static int tt3650_ci_slot_shutdown(struct dvb_ca_en50221 *ca, int slot)
{
return tt3650_ci_set_video_port(ca, slot, 0);
}
static int tt3650_ci_slot_ts_enable(struct dvb_ca_en50221 *ca, int slot)
{
return tt3650_ci_set_video_port(ca, slot, 1);
}
static int tt3650_ci_slot_reset(struct dvb_ca_en50221 *ca, int slot)
{
struct dvb_usb_device *d = ca->data;
struct ttusb2_state *state = d->priv;
u8 buf[1];
int ret;
ci_dbg("%d", slot);
if (slot)
return -EINVAL;
buf[0] = 0;
mutex_lock(&state->ca_mutex);
ret = tt3650_ci_msg(d, TT3650_CMD_CI_RESET, buf, 1, 1);
if (ret)
goto failed;
msleep(500);
buf[0] = 1;
ret = tt3650_ci_msg(d, TT3650_CMD_CI_RESET, buf, 1, 1);
if (ret)
goto failed;
msleep(500);
buf[0] = 0;
ret = tt3650_ci_msg(d, TT3650_CMD_CI_SET_VIDEO_PORT, buf, 1, 1);
msleep(1100);
failed:
mutex_unlock(&state->ca_mutex);
return ret;
}
static int tt3650_ci_poll_slot_status(struct dvb_ca_en50221 *ca, int slot, int open)
{
u8 buf[1];
int ret;
if (slot)
return -EINVAL;
ret = tt3650_ci_msg_locked(ca, TT3650_CMD_CI_TEST, buf, 0, 1);
if (ret)
return ret;
if (1 == buf[0]) {
return DVB_CA_EN50221_POLL_CAM_PRESENT |
DVB_CA_EN50221_POLL_CAM_READY;
}
return 0;
}
static void tt3650_ci_uninit(struct dvb_usb_device *d)
{
struct ttusb2_state *state;
ci_dbg("");
if (NULL == d)
return;
state = d->priv;
if (NULL == state)
return;
if (NULL == state->ca.data)
return;
dvb_ca_en50221_release(&state->ca);
memset(&state->ca, 0, sizeof(state->ca));
}
static int tt3650_ci_init(struct dvb_usb_adapter *a)
{
struct dvb_usb_device *d = a->dev;
struct ttusb2_state *state = d->priv;
int ret;
ci_dbg("");
mutex_init(&state->ca_mutex);
state->ca.owner = THIS_MODULE;
state->ca.read_attribute_mem = tt3650_ci_read_attribute_mem;
state->ca.write_attribute_mem = tt3650_ci_write_attribute_mem;
state->ca.read_cam_control = tt3650_ci_read_cam_control;
state->ca.write_cam_control = tt3650_ci_write_cam_control;
state->ca.slot_reset = tt3650_ci_slot_reset;
state->ca.slot_shutdown = tt3650_ci_slot_shutdown;
state->ca.slot_ts_enable = tt3650_ci_slot_ts_enable;
state->ca.poll_slot_status = tt3650_ci_poll_slot_status;
state->ca.data = d;
ret = dvb_ca_en50221_init(&a->dvb_adap,
&state->ca,
0,
1);
if (ret) {
err("Cannot initialize CI: Error %d.", ret);
memset(&state->ca, 0, sizeof(state->ca));
return ret;
}
info("CI initialized.");
return 0;
}
static int ttusb2_i2c_xfer(struct i2c_adapter *adap,struct i2c_msg msg[],int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
static u8 obuf[60], ibuf[60];
int i, write_read, read;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
if (num > 2)
warn("more than 2 i2c messages at a time is not handled yet. TODO.");
for (i = 0; i < num; i++) {
write_read = i+1 < num && (msg[i+1].flags & I2C_M_RD);
read = msg[i].flags & I2C_M_RD;
obuf[0] = (msg[i].addr << 1) | (write_read | read);
if (read)
obuf[1] = 0;
else
obuf[1] = msg[i].len;
if (write_read)
obuf[2] = msg[i+1].len;
else if (read)
obuf[2] = msg[i].len;
else
obuf[2] = 0;
memcpy(&obuf[3], msg[i].buf, msg[i].len);
if (ttusb2_msg(d, CMD_I2C_XFER, obuf, msg[i].len+3, ibuf, obuf[2] + 3) < 0) {
err("i2c transfer failed.");
break;
}
if (write_read) {
memcpy(msg[i+1].buf, &ibuf[3], msg[i+1].len);
i++;
} else if (read)
memcpy(msg[i].buf, &ibuf[3], msg[i].len);
}
mutex_unlock(&d->i2c_mutex);
return i;
}
static u32 ttusb2_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int tt3650_rc_query(struct dvb_usb_device *d)
{
int ret;
u8 rx[9];
struct ttusb2_state *st = d->priv;
ret = ttusb2_msg(d, CMD_GET_IR_CODE, NULL, 0, rx, sizeof(rx));
if (ret != 0)
return ret;
if (rx[8] & 0x01) {
st->last_rc_key = (rx[3] << 8) | rx[2];
deb_info("%s: cmd=0x%02x sys=0x%02x\n", __func__, rx[2], rx[3]);
rc_keydown(d->rc_dev, st->last_rc_key, 0);
} else if (st->last_rc_key) {
rc_keyup(d->rc_dev);
st->last_rc_key = 0;
}
return 0;
}
static int ttusb2_identify_state (struct usb_device *udev, struct
dvb_usb_device_properties *props, struct dvb_usb_device_description **desc,
int *cold)
{
*cold = udev->descriptor.iManufacturer == 0 && udev->descriptor.iProduct == 0;
return 0;
}
static int ttusb2_power_ctrl(struct dvb_usb_device *d, int onoff)
{
u8 b = onoff;
ttusb2_msg(d, CMD_POWER, &b, 0, NULL, 0);
return ttusb2_msg(d, CMD_POWER, &b, 1, NULL, 0);
}
static int ttusb2_frontend_tda10086_attach(struct dvb_usb_adapter *adap)
{
if (usb_set_interface(adap->dev->udev,0,3) < 0)
err("set interface to alts=3 failed");
if ((adap->fe_adap[0].fe = dvb_attach(tda10086_attach, &tda10086_config, &adap->dev->i2c_adap)) == NULL) {
deb_info("TDA10086 attach failed\n");
return -ENODEV;
}
return 0;
}
static int ttusb2_ct3650_i2c_gate_ctrl(struct dvb_frontend *fe, int enable)
{
struct dvb_usb_adapter *adap = fe->dvb->priv;
return adap->fe_adap[0].fe->ops.i2c_gate_ctrl(adap->fe_adap[0].fe, enable);
}
static int ttusb2_frontend_tda10023_attach(struct dvb_usb_adapter *adap)
{
if (usb_set_interface(adap->dev->udev, 0, 3) < 0)
err("set interface to alts=3 failed");
if (adap->fe_adap[0].fe == NULL) {
adap->fe_adap[0].fe = dvb_attach(tda10023_attach,
&tda10023_config, &adap->dev->i2c_adap, 0x48);
if (adap->fe_adap[0].fe == NULL) {
deb_info("TDA10023 attach failed\n");
return -ENODEV;
}
tt3650_ci_init(adap);
} else {
adap->fe_adap[1].fe = dvb_attach(tda10048_attach,
&tda10048_config, &adap->dev->i2c_adap);
if (adap->fe_adap[1].fe == NULL) {
deb_info("TDA10048 attach failed\n");
return -ENODEV;
}
adap->fe_adap[1].fe->ops.i2c_gate_ctrl = ttusb2_ct3650_i2c_gate_ctrl;
}
return 0;
}
static int ttusb2_tuner_tda827x_attach(struct dvb_usb_adapter *adap)
{
struct dvb_frontend *fe;
if (adap->fe_adap[1].fe == NULL)
fe = adap->fe_adap[0].fe;
else
fe = adap->fe_adap[1].fe;
if (dvb_attach(tda827x_attach, fe, 0x61, &adap->dev->i2c_adap, &tda827x_config) == NULL) {
printk(KERN_ERR "%s: No tda827x found!\n", __func__);
return -ENODEV;
}
return 0;
}
static int ttusb2_tuner_tda826x_attach(struct dvb_usb_adapter *adap)
{
if (dvb_attach(tda826x_attach, adap->fe_adap[0].fe, 0x60, &adap->dev->i2c_adap, 0) == NULL) {
deb_info("TDA8263 attach failed\n");
return -ENODEV;
}
if (dvb_attach(lnbp21_attach, adap->fe_adap[0].fe, &adap->dev->i2c_adap, 0, 0) == NULL) {
deb_info("LNBP21 attach failed\n");
return -ENODEV;
}
return 0;
}
static void ttusb2_usb_disconnect(struct usb_interface *intf)
{
struct dvb_usb_device *d = usb_get_intfdata(intf);
tt3650_ci_uninit(d);
dvb_usb_device_exit(intf);
}
static int ttusb2_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
if (0 == dvb_usb_device_init(intf, &ttusb2_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &ttusb2_properties_s2400,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &ttusb2_properties_ct3650,
THIS_MODULE, NULL, adapter_nr))
return 0;
return -ENODEV;
}
static int __init ttusb2_module_init(void)
{
int result;
if ((result = usb_register(&ttusb2_driver))) {
err("usb_register failed. Error number %d",result);
return result;
}
return 0;
}
static void __exit ttusb2_module_exit(void)
{
usb_deregister(&ttusb2_driver);
}
