static int dtv5100_i2c_msg(struct dvb_usb_device *d, u8 addr,
u8 *wbuf, u16 wlen, u8 *rbuf, u16 rlen)
{
u8 request;
u8 type;
u16 value;
u16 index;
switch (wlen) {
case 1:
request = (addr == DTV5100_DEMOD_ADDR ? DTV5100_DEMOD_READ :
DTV5100_TUNER_READ);
type = USB_TYPE_VENDOR | USB_DIR_IN;
value = 0;
break;
case 2:
request = (addr == DTV5100_DEMOD_ADDR ? DTV5100_DEMOD_WRITE :
DTV5100_TUNER_WRITE);
type = USB_TYPE_VENDOR | USB_DIR_OUT;
value = wbuf[1];
break;
default:
warn("wlen = %x, aborting.", wlen);
return -EINVAL;
}
index = (addr << 8) + wbuf[0];
msleep(1);
return usb_control_msg(d->udev, usb_rcvctrlpipe(d->udev, 0), request,
type, value, index, rbuf, rlen,
DTV5100_USB_TIMEOUT);
}
static int dtv5100_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msg[],
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
if (dtv5100_i2c_msg(d, msg[i].addr, msg[i].buf,
msg[i].len, msg[i+1].buf,
msg[i+1].len) < 0)
break;
i++;
} else if (dtv5100_i2c_msg(d, msg[i].addr, msg[i].buf,
msg[i].len, NULL, 0) < 0)
break;
}
mutex_unlock(&d->i2c_mutex);
return i;
}
static u32 dtv5100_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int dtv5100_frontend_attach(struct dvb_usb_adapter *adap)
{
adap->fe_adap[0].fe = dvb_attach(zl10353_attach, &dtv5100_zl10353_config,
&adap->dev->i2c_adap);
if (adap->fe_adap[0].fe == NULL)
return -EIO;
adap->fe_adap[0].fe->ops.i2c_gate_ctrl = NULL;
return 0;
}
static int dtv5100_tuner_attach(struct dvb_usb_adapter *adap)
{
return dvb_attach(qt1010_attach,
adap->fe_adap[0].fe, &adap->dev->i2c_adap,
&dtv5100_qt1010_config) == NULL ? -ENODEV : 0;
}
static int dtv5100_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
int i, ret;
struct usb_device *udev = interface_to_usbdev(intf);
for (i = 0; dtv5100_init[i].request; i++) {
ret = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
dtv5100_init[i].request,
USB_TYPE_VENDOR | USB_DIR_OUT,
dtv5100_init[i].value,
dtv5100_init[i].index, NULL, 0,
DTV5100_USB_TIMEOUT);
if (ret)
return ret;
}
ret = dvb_usb_device_init(intf, &dtv5100_properties,
THIS_MODULE, NULL, adapter_nr);
if (ret)
return ret;
return 0;
}
static int __init dtv5100_module_init(void)
{
int ret;
ret = usb_register(&dtv5100_driver);
if (ret)
err("usb_register failed. Error number %d", ret);
return ret;
}
static void __exit dtv5100_module_exit(void)
{
usb_deregister(&dtv5100_driver);
}
