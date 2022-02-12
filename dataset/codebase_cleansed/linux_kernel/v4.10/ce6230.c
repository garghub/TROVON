static int ce6230_ctrl_msg(struct dvb_usb_device *d, struct usb_req *req)
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
dev_err(&d->udev->dev, "%s: unknown command=%02x\n",
KBUILD_MODNAME, req->cmd);
ret = -EINVAL;
goto error;
}
buf = kmalloc(req->data_len, GFP_KERNEL);
if (!buf) {
ret = -ENOMEM;
goto error;
}
if (requesttype == (USB_TYPE_VENDOR | USB_DIR_OUT)) {
memcpy(buf, req->data, req->data_len);
pipe = usb_sndctrlpipe(d->udev, 0);
} else {
pipe = usb_rcvctrlpipe(d->udev, 0);
}
msleep(1);
ret = usb_control_msg(d->udev, pipe, request, requesttype, value, index,
buf, req->data_len, CE6230_USB_TIMEOUT);
dvb_usb_dbg_usb_control_msg(d->udev, request, requesttype, value, index,
buf, req->data_len);
if (ret < 0)
dev_err(&d->udev->dev, "%s: usb_control_msg() failed=%d\n",
KBUILD_MODNAME, ret);
else
ret = 0;
if (!ret && requesttype == (USB_TYPE_VENDOR | USB_DIR_IN))
memcpy(req->data, buf, req->data_len);
kfree(buf);
error:
return ret;
}
static int ce6230_i2c_master_xfer(struct i2c_adapter *adap,
struct i2c_msg msg[], int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
int ret = 0, i = 0;
struct usb_req req;
if (num > 2)
return -EOPNOTSUPP;
memset(&req, 0, sizeof(req));
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
dev_err(&d->udev->dev, "%s: I2C read not " \
"implemented\n",
KBUILD_MODNAME);
ret = -EOPNOTSUPP;
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
static u32 ce6230_i2c_functionality(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int ce6230_zl10353_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dvb_usb_device *d = adap_to_d(adap);
dev_dbg(&d->udev->dev, "%s:\n", __func__);
adap->fe[0] = dvb_attach(zl10353_attach, &ce6230_zl10353_config,
&d->i2c_adap);
if (adap->fe[0] == NULL)
return -ENODEV;
return 0;
}
static int ce6230_mxl5003s_tuner_attach(struct dvb_usb_adapter *adap)
{
struct dvb_usb_device *d = adap_to_d(adap);
int ret;
dev_dbg(&d->udev->dev, "%s:\n", __func__);
ret = dvb_attach(mxl5005s_attach, adap->fe[0], &d->i2c_adap,
&ce6230_mxl5003s_config) == NULL ? -ENODEV : 0;
return ret;
}
static int ce6230_power_ctrl(struct dvb_usb_device *d, int onoff)
{
int ret;
dev_dbg(&d->udev->dev, "%s: onoff=%d\n", __func__, onoff);
ret = usb_set_interface(d->udev, 1, onoff);
if (ret)
dev_err(&d->udev->dev, "%s: usb_set_interface() failed=%d\n",
KBUILD_MODNAME, ret);
return ret;
}
