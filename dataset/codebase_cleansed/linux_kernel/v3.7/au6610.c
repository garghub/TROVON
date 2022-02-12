static int au6610_usb_msg(struct dvb_usb_device *d, u8 operation, u8 addr,
u8 *wbuf, u16 wlen, u8 *rbuf, u16 rlen)
{
int ret;
u16 index;
u8 *usb_buf;
usb_buf = kmalloc(6, GFP_KERNEL);
if (!usb_buf)
return -ENOMEM;
switch (wlen) {
case 1:
index = wbuf[0] << 8;
break;
case 2:
index = wbuf[0] << 8;
index += wbuf[1];
break;
default:
dev_err(&d->udev->dev, "%s: wlen=%d, aborting\n",
KBUILD_MODNAME, wlen);
ret = -EINVAL;
goto error;
}
ret = usb_control_msg(d->udev, usb_rcvctrlpipe(d->udev, 0), operation,
USB_TYPE_VENDOR|USB_DIR_IN, addr << 1, index,
usb_buf, 6, AU6610_USB_TIMEOUT);
dvb_usb_dbg_usb_control_msg(d->udev, operation,
(USB_TYPE_VENDOR|USB_DIR_IN), addr << 1, index,
usb_buf, 6);
if (ret < 0)
goto error;
switch (operation) {
case AU6610_REQ_I2C_READ:
case AU6610_REQ_USB_READ:
rbuf[0] = usb_buf[4];
}
error:
kfree(usb_buf);
return ret;
}
static int au6610_i2c_msg(struct dvb_usb_device *d, u8 addr,
u8 *wbuf, u16 wlen, u8 *rbuf, u16 rlen)
{
u8 request;
u8 wo = (rbuf == NULL || rlen == 0);
if (wo) {
request = AU6610_REQ_I2C_WRITE;
} else {
request = AU6610_REQ_I2C_READ;
}
return au6610_usb_msg(d, request, addr, wbuf, wlen, rbuf, rlen);
}
static int au6610_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msg[],
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
if (au6610_i2c_msg(d, msg[i].addr, msg[i].buf,
msg[i].len, msg[i+1].buf,
msg[i+1].len) < 0)
break;
i++;
} else if (au6610_i2c_msg(d, msg[i].addr, msg[i].buf,
msg[i].len, NULL, 0) < 0)
break;
}
mutex_unlock(&d->i2c_mutex);
return i;
}
static u32 au6610_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int au6610_zl10353_frontend_attach(struct dvb_usb_adapter *adap)
{
adap->fe[0] = dvb_attach(zl10353_attach, &au6610_zl10353_config,
&adap_to_d(adap)->i2c_adap);
if (adap->fe[0] == NULL)
return -ENODEV;
return 0;
}
static int au6610_qt1010_tuner_attach(struct dvb_usb_adapter *adap)
{
return dvb_attach(qt1010_attach, adap->fe[0],
&adap_to_d(adap)->i2c_adap,
&au6610_qt1010_config) == NULL ? -ENODEV : 0;
}
static int au6610_init(struct dvb_usb_device *d)
{
return usb_set_interface(d->udev, 0, 5);
}
