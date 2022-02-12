static int ce6230_rw_udev(struct usb_device *udev, struct req_t *req)
{
int ret;
unsigned int pipe;
u8 request;
u8 requesttype;
u16 value;
u16 index;
u8 *buf;
request = req->cmd;
value = req->value;
index = req->index;
switch (req->cmd) {
case I2C_READ:
case DEMOD_READ:
case REG_READ:
requesttype = (USB_TYPE_VENDOR | USB_DIR_IN);
break;
case I2C_WRITE:
case DEMOD_WRITE:
case REG_WRITE:
requesttype = (USB_TYPE_VENDOR | USB_DIR_OUT);
break;
default:
err("unknown command:%02x", req->cmd);
ret = -EPERM;
goto error;
}
buf = kmalloc(req->data_len, GFP_KERNEL);
if (!buf) {
ret = -ENOMEM;
goto error;
}
if (requesttype == (USB_TYPE_VENDOR | USB_DIR_OUT)) {
memcpy(buf, req->data, req->data_len);
pipe = usb_sndctrlpipe(udev, 0);
} else {
pipe = usb_rcvctrlpipe(udev, 0);
}
msleep(1);
ret = usb_control_msg(udev, pipe, request, requesttype, value, index,
buf, req->data_len, CE6230_USB_TIMEOUT);
ce6230_debug_dump(request, requesttype, value, index, buf,
req->data_len, deb_xfer);
if (ret < 0)
deb_info("%s: usb_control_msg failed:%d\n", __func__, ret);
else
ret = 0;
if (!ret && requesttype == (USB_TYPE_VENDOR | USB_DIR_IN))
memcpy(req->data, buf, req->data_len);
kfree(buf);
error:
return ret;
}
static int ce6230_ctrl_msg(struct dvb_usb_device *d, struct req_t *req)
{
return ce6230_rw_udev(d->udev, req);
}
static int ce6230_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msg[],
int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
int i = 0;
struct req_t req;
int ret = 0;
memset(&req, 0, sizeof(req));
if (num > 2)
return -EINVAL;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
while (i < num) {
if (num > i + 1 && (msg[i+1].flags & I2C_M_RD)) {
if (msg[i].addr ==
ce6230_zl10353_config.demod_address) {
req.cmd = DEMOD_READ;
req.value = msg[i].addr >> 1;
req.index = msg[i].buf[0];
req.data_len = msg[i+1].len;
req.data = &msg[i+1].buf[0];
ret = ce6230_ctrl_msg(d, &req);
} else {
err("i2c read not implemented");
ret = -EPERM;
}
i += 2;
} else {
if (msg[i].addr ==
ce6230_zl10353_config.demod_address) {
req.cmd = DEMOD_WRITE;
req.value = msg[i].addr >> 1;
req.index = msg[i].buf[0];
req.data_len = msg[i].len-1;
req.data = &msg[i].buf[1];
ret = ce6230_ctrl_msg(d, &req);
} else {
req.cmd = I2C_WRITE;
req.value = 0x2000 + (msg[i].addr >> 1);
req.index = 0x0000;
req.data_len = msg[i].len;
req.data = &msg[i].buf[0];
ret = ce6230_ctrl_msg(d, &req);
}
i += 1;
}
if (ret)
break;
}
mutex_unlock(&d->i2c_mutex);
return ret ? ret : i;
}
static u32 ce6230_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int ce6230_zl10353_frontend_attach(struct dvb_usb_adapter *adap)
{
deb_info("%s:\n", __func__);
adap->fe_adap[0].fe = dvb_attach(zl10353_attach, &ce6230_zl10353_config,
&adap->dev->i2c_adap);
if (adap->fe_adap[0].fe == NULL)
return -ENODEV;
return 0;
}
static int ce6230_mxl5003s_tuner_attach(struct dvb_usb_adapter *adap)
{
int ret;
deb_info("%s:\n", __func__);
ret = dvb_attach(mxl5005s_attach, adap->fe_adap[0].fe, &adap->dev->i2c_adap,
&ce6230_mxl5003s_config) == NULL ? -ENODEV : 0;
return ret;
}
static int ce6230_power_ctrl(struct dvb_usb_device *d, int onoff)
{
int ret;
deb_info("%s: onoff:%d\n", __func__, onoff);
ret = usb_set_interface(d->udev, 1, onoff);
if (ret)
err("usb_set_interface failed with error:%d", ret);
return ret;
}
static int ce6230_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
int ret = 0;
struct dvb_usb_device *d = NULL;
deb_info("%s: interface:%d\n", __func__,
intf->cur_altsetting->desc.bInterfaceNumber);
if (intf->cur_altsetting->desc.bInterfaceNumber == 1) {
ret = dvb_usb_device_init(intf, &ce6230_properties, THIS_MODULE,
&d, adapter_nr);
if (ret)
err("init failed with error:%d\n", ret);
}
return ret;
}
static int __init ce6230_module_init(void)
{
int ret;
deb_info("%s:\n", __func__);
ret = usb_register(&ce6230_driver);
if (ret)
err("usb_register failed with error:%d", ret);
return ret;
}
static void __exit ce6230_module_exit(void)
{
deb_info("%s:\n", __func__);
usb_deregister(&ce6230_driver);
}
