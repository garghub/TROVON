static int ec168_ctrl_msg(struct dvb_usb_device *d, struct ec168_req *req)
{
int ret;
unsigned int pipe;
u8 request, requesttype;
u8 *buf;
switch (req->cmd) {
case DOWNLOAD_FIRMWARE:
case GPIO:
case WRITE_I2C:
case STREAMING_CTRL:
requesttype = (USB_TYPE_VENDOR | USB_DIR_OUT);
request = req->cmd;
break;
case READ_I2C:
requesttype = (USB_TYPE_VENDOR | USB_DIR_IN);
request = req->cmd;
break;
case GET_CONFIG:
requesttype = (USB_TYPE_VENDOR | USB_DIR_IN);
request = CONFIG;
break;
case SET_CONFIG:
requesttype = (USB_TYPE_VENDOR | USB_DIR_OUT);
request = CONFIG;
break;
case WRITE_DEMOD:
requesttype = (USB_TYPE_VENDOR | USB_DIR_OUT);
request = DEMOD_RW;
break;
case READ_DEMOD:
requesttype = (USB_TYPE_VENDOR | USB_DIR_IN);
request = DEMOD_RW;
break;
default:
dev_err(&d->udev->dev, "%s: unknown command=%02x\n",
KBUILD_MODNAME, req->cmd);
ret = -EINVAL;
goto error;
}
buf = kmalloc(req->size, GFP_KERNEL);
if (!buf) {
ret = -ENOMEM;
goto error;
}
if (requesttype == (USB_TYPE_VENDOR | USB_DIR_OUT)) {
memcpy(buf, req->data, req->size);
pipe = usb_sndctrlpipe(d->udev, 0);
} else {
pipe = usb_rcvctrlpipe(d->udev, 0);
}
msleep(1);
ret = usb_control_msg(d->udev, pipe, request, requesttype, req->value,
req->index, buf, req->size, EC168_USB_TIMEOUT);
dvb_usb_dbg_usb_control_msg(d->udev, request, requesttype, req->value,
req->index, buf, req->size);
if (ret < 0)
goto err_dealloc;
else
ret = 0;
if (!ret && requesttype == (USB_TYPE_VENDOR | USB_DIR_IN))
memcpy(req->data, buf, req->size);
kfree(buf);
return ret;
err_dealloc:
kfree(buf);
error:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int ec168_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msg[],
int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
struct ec168_req req;
int i = 0;
int ret;
if (num > 2)
return -EINVAL;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
while (i < num) {
if (num > i + 1 && (msg[i+1].flags & I2C_M_RD)) {
if (msg[i].addr == ec168_ec100_config.demod_address) {
req.cmd = READ_DEMOD;
req.value = 0;
req.index = 0xff00 + msg[i].buf[0];
req.size = msg[i+1].len;
req.data = &msg[i+1].buf[0];
ret = ec168_ctrl_msg(d, &req);
i += 2;
} else {
dev_err(&d->udev->dev, "%s: I2C read not " \
"implemented\n",
KBUILD_MODNAME);
ret = -EOPNOTSUPP;
i += 2;
}
} else {
if (msg[i].addr == ec168_ec100_config.demod_address) {
req.cmd = WRITE_DEMOD;
req.value = msg[i].buf[1];
req.index = 0xff00 + msg[i].buf[0];
req.size = 0;
req.data = NULL;
ret = ec168_ctrl_msg(d, &req);
i += 1;
} else {
req.cmd = WRITE_I2C;
req.value = msg[i].buf[0];
req.index = 0x0100 + msg[i].addr;
req.size = msg[i].len-1;
req.data = &msg[i].buf[1];
ret = ec168_ctrl_msg(d, &req);
i += 1;
}
}
if (ret)
goto error;
}
ret = i;
error:
mutex_unlock(&d->i2c_mutex);
return ret;
}
static u32 ec168_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int ec168_identify_state(struct dvb_usb_device *d, const char **name)
{
int ret;
u8 reply;
struct ec168_req req = {GET_CONFIG, 0, 1, sizeof(reply), &reply};
dev_dbg(&d->udev->dev, "%s:\n", __func__);
ret = ec168_ctrl_msg(d, &req);
if (ret)
goto error;
dev_dbg(&d->udev->dev, "%s: reply=%02x\n", __func__, reply);
if (reply == 0x01)
ret = WARM;
else
ret = COLD;
return ret;
error:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int ec168_download_firmware(struct dvb_usb_device *d,
const struct firmware *fw)
{
int ret, len, remaining;
struct ec168_req req = {DOWNLOAD_FIRMWARE, 0, 0, 0, NULL};
dev_dbg(&d->udev->dev, "%s:\n", __func__);
#define LEN_MAX 2048
for (remaining = fw->size; remaining > 0; remaining -= LEN_MAX) {
len = remaining;
if (len > LEN_MAX)
len = LEN_MAX;
req.size = len;
req.data = (u8 *) &fw->data[fw->size - remaining];
req.index = fw->size - remaining;
ret = ec168_ctrl_msg(d, &req);
if (ret) {
dev_err(&d->udev->dev,
"%s: firmware download failed=%d\n",
KBUILD_MODNAME, ret);
goto error;
}
}
req.size = 0;
req.cmd = SET_CONFIG;
req.value = 0;
req.index = 0x0001;
ret = ec168_ctrl_msg(d, &req);
if (ret)
goto error;
req.cmd = GPIO;
req.value = 0;
req.index = 0x0206;
ret = ec168_ctrl_msg(d, &req);
if (ret)
goto error;
req.cmd = WRITE_I2C;
req.value = 0;
req.index = 0x00c6;
ret = ec168_ctrl_msg(d, &req);
if (ret)
goto error;
return ret;
error:
dev_dbg(&d->udev->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int ec168_ec100_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dvb_usb_device *d = adap_to_d(adap);
dev_dbg(&d->udev->dev, "%s:\n", __func__);
adap->fe[0] = dvb_attach(ec100_attach, &ec168_ec100_config,
&d->i2c_adap);
if (adap->fe[0] == NULL)
return -ENODEV;
return 0;
}
static int ec168_mxl5003s_tuner_attach(struct dvb_usb_adapter *adap)
{
struct dvb_usb_device *d = adap_to_d(adap);
dev_dbg(&d->udev->dev, "%s:\n", __func__);
return dvb_attach(mxl5005s_attach, adap->fe[0], &d->i2c_adap,
&ec168_mxl5003s_config) == NULL ? -ENODEV : 0;
}
static int ec168_streaming_ctrl(struct dvb_frontend *fe, int onoff)
{
struct dvb_usb_device *d = fe_to_d(fe);
struct ec168_req req = {STREAMING_CTRL, 0x7f01, 0x0202, 0, NULL};
dev_dbg(&d->udev->dev, "%s: onoff=%d\n", __func__, onoff);
if (onoff)
req.index = 0x0102;
return ec168_ctrl_msg(d, &req);
}
