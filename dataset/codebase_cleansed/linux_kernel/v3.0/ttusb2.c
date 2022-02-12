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
static int ttusb2_i2c_xfer(struct i2c_adapter *adap,struct i2c_msg msg[],int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
static u8 obuf[60], ibuf[60];
int i,read;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
if (num > 2)
warn("more than 2 i2c messages at a time is not handled yet. TODO.");
for (i = 0; i < num; i++) {
read = i+1 < num && (msg[i+1].flags & I2C_M_RD);
obuf[0] = (msg[i].addr << 1) | read;
obuf[1] = msg[i].len;
if (read)
obuf[2] = msg[i+1].len;
else
obuf[2] = 0;
memcpy(&obuf[3],msg[i].buf,msg[i].len);
if (ttusb2_msg(d, CMD_I2C_XFER, obuf, msg[i].len+3, ibuf, obuf[2] + 3) < 0) {
err("i2c transfer failed.");
break;
}
if (read) {
memcpy(msg[i+1].buf,&ibuf[3],msg[i+1].len);
i++;
}
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
if ((adap->fe = dvb_attach(tda10086_attach, &tda10086_config, &adap->dev->i2c_adap)) == NULL) {
deb_info("TDA10086 attach failed\n");
return -ENODEV;
}
return 0;
}
static int ttusb2_frontend_tda10023_attach(struct dvb_usb_adapter *adap)
{
if (usb_set_interface(adap->dev->udev, 0, 3) < 0)
err("set interface to alts=3 failed");
if ((adap->fe = dvb_attach(tda10023_attach, &tda10023_config, &adap->dev->i2c_adap, 0x48)) == NULL) {
deb_info("TDA10023 attach failed\n");
return -ENODEV;
}
return 0;
}
static int ttusb2_tuner_tda827x_attach(struct dvb_usb_adapter *adap)
{
if (dvb_attach(tda827x_attach, adap->fe, 0x61, &adap->dev->i2c_adap, NULL) == NULL) {
printk(KERN_ERR "%s: No tda827x found!\n", __func__);
return -ENODEV;
}
return 0;
}
static int ttusb2_tuner_tda826x_attach(struct dvb_usb_adapter *adap)
{
if (dvb_attach(tda826x_attach, adap->fe, 0x60, &adap->dev->i2c_adap, 0) == NULL) {
deb_info("TDA8263 attach failed\n");
return -ENODEV;
}
if (dvb_attach(lnbp21_attach, adap->fe, &adap->dev->i2c_adap, 0, 0) == NULL) {
deb_info("LNBP21 attach failed\n");
return -ENODEV;
}
return 0;
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
