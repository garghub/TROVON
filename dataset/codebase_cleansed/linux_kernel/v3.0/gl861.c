static int gl861_i2c_msg(struct dvb_usb_device *d, u8 addr,
u8 *wbuf, u16 wlen, u8 *rbuf, u16 rlen)
{
u16 index;
u16 value = addr << (8 + 1);
int wo = (rbuf == NULL || rlen == 0);
u8 req, type;
if (wo) {
req = GL861_REQ_I2C_WRITE;
type = GL861_WRITE;
} else {
req = GL861_REQ_I2C_READ;
type = GL861_READ;
}
switch (wlen) {
case 1:
index = wbuf[0];
break;
case 2:
index = wbuf[0];
value = value + wbuf[1];
break;
default:
warn("wlen = %x, aborting.", wlen);
return -EINVAL;
}
msleep(1);
return usb_control_msg(d->udev, usb_rcvctrlpipe(d->udev, 0), req, type,
value, index, rbuf, rlen, 2000);
}
static int gl861_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msg[],
int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
int i;
if (num > 2)
return -EINVAL;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
for (i = 0; i < num; i++) {
if (i+1 < num && (msg[i+1].flags & I2C_M_RD)) {
if (gl861_i2c_msg(d, msg[i].addr, msg[i].buf,
msg[i].len, msg[i+1].buf, msg[i+1].len) < 0)
break;
i++;
} else
if (gl861_i2c_msg(d, msg[i].addr, msg[i].buf,
msg[i].len, NULL, 0) < 0)
break;
}
mutex_unlock(&d->i2c_mutex);
return i;
}
static u32 gl861_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int gl861_frontend_attach(struct dvb_usb_adapter *adap)
{
adap->fe = dvb_attach(zl10353_attach, &gl861_zl10353_config,
&adap->dev->i2c_adap);
if (adap->fe == NULL)
return -EIO;
return 0;
}
static int gl861_tuner_attach(struct dvb_usb_adapter *adap)
{
return dvb_attach(qt1010_attach,
adap->fe, &adap->dev->i2c_adap,
&gl861_qt1010_config) == NULL ? -ENODEV : 0;
}
static int gl861_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct dvb_usb_device *d;
struct usb_host_interface *alt;
int ret;
if (intf->num_altsetting < 2)
return -ENODEV;
ret = dvb_usb_device_init(intf, &gl861_properties, THIS_MODULE, &d,
adapter_nr);
if (ret == 0) {
alt = usb_altnum_to_altsetting(intf, 0);
if (alt == NULL) {
deb_rc("not alt found!\n");
return -ENODEV;
}
ret = usb_set_interface(d->udev, alt->desc.bInterfaceNumber,
alt->desc.bAlternateSetting);
}
return ret;
}
static int __init gl861_module_init(void)
{
int ret;
ret = usb_register(&gl861_driver);
if (ret)
err("usb_register failed. Error number %d", ret);
return ret;
}
static void __exit gl861_module_exit(void)
{
usb_deregister(&gl861_driver);
}
