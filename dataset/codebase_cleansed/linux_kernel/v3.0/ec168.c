static int ec168_rw_udev(struct usb_device *udev, struct ec168_req *req)
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
err("unknown command:%02x", req->cmd);
ret = -EPERM;
goto error;
}
buf = kmalloc(req->size, GFP_KERNEL);
if (!buf) {
ret = -ENOMEM;
goto error;
}
if (requesttype == (USB_TYPE_VENDOR | USB_DIR_OUT)) {
memcpy(buf, req->data, req->size);
pipe = usb_sndctrlpipe(udev, 0);
} else {
pipe = usb_rcvctrlpipe(udev, 0);
}
msleep(1);
ret = usb_control_msg(udev, pipe, request, requesttype, req->value,
req->index, buf, req->size, EC168_USB_TIMEOUT);
ec168_debug_dump(request, requesttype, req->value, req->index, buf,
req->size, deb_xfer);
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
deb_info("%s: failed:%d\n", __func__, ret);
return ret;
}
static int ec168_ctrl_msg(struct dvb_usb_device *d, struct ec168_req *req)
{
return ec168_rw_udev(d->udev, req);
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
err("I2C read not implemented");
ret = -ENOSYS;
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
return i;
}
static u32 ec168_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int ec168_ec100_frontend_attach(struct dvb_usb_adapter *adap)
{
deb_info("%s:\n", __func__);
adap->fe = dvb_attach(ec100_attach, &ec168_ec100_config,
&adap->dev->i2c_adap);
if (adap->fe == NULL)
return -ENODEV;
return 0;
}
static int ec168_mxl5003s_tuner_attach(struct dvb_usb_adapter *adap)
{
deb_info("%s:\n", __func__);
return dvb_attach(mxl5005s_attach, adap->fe, &adap->dev->i2c_adap,
&ec168_mxl5003s_config) == NULL ? -ENODEV : 0;
}
static int ec168_streaming_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
struct ec168_req req = {STREAMING_CTRL, 0x7f01, 0x0202, 0, NULL};
deb_info("%s: onoff:%d\n", __func__, onoff);
if (onoff)
req.index = 0x0102;
return ec168_ctrl_msg(adap->dev, &req);
}
static int ec168_download_firmware(struct usb_device *udev,
const struct firmware *fw)
{
int i, len, packets, remainder, ret;
u16 addr = 0x0000;
struct ec168_req req = {DOWNLOAD_FIRMWARE, 0, 0, 0, NULL};
deb_info("%s:\n", __func__);
#define FW_PACKET_MAX_DATA 2048
packets = fw->size / FW_PACKET_MAX_DATA;
remainder = fw->size % FW_PACKET_MAX_DATA;
len = FW_PACKET_MAX_DATA;
for (i = 0; i <= packets; i++) {
if (i == packets)
len = remainder;
req.size = len;
req.data = (u8 *)(fw->data + i * FW_PACKET_MAX_DATA);
req.index = addr;
addr += FW_PACKET_MAX_DATA;
ret = ec168_rw_udev(udev, &req);
if (ret) {
err("firmware download failed:%d packet:%d", ret, i);
goto error;
}
}
req.size = 0;
req.cmd = SET_CONFIG;
req.value = 0;
req.index = 0x0001;
ret = ec168_rw_udev(udev, &req);
if (ret)
goto error;
req.cmd = GPIO;
req.value = 0;
req.index = 0x0206;
ret = ec168_rw_udev(udev, &req);
if (ret)
goto error;
req.cmd = WRITE_I2C;
req.value = 0;
req.index = 0x00c6;
ret = ec168_rw_udev(udev, &req);
if (ret)
goto error;
return ret;
error:
deb_info("%s: failed:%d\n", __func__, ret);
return ret;
}
static int ec168_identify_state(struct usb_device *udev,
struct dvb_usb_device_properties *props,
struct dvb_usb_device_description **desc, int *cold)
{
int ret;
u8 reply;
struct ec168_req req = {GET_CONFIG, 0, 1, sizeof(reply), &reply};
deb_info("%s:\n", __func__);
ret = ec168_rw_udev(udev, &req);
if (ret)
goto error;
deb_info("%s: reply:%02x\n", __func__, reply);
if (reply == 0x01)
*cold = 0;
else
*cold = 1;
return ret;
error:
deb_info("%s: failed:%d\n", __func__, ret);
return ret;
}
static int ec168_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
int ret;
deb_info("%s: interface:%d\n", __func__,
intf->cur_altsetting->desc.bInterfaceNumber);
ret = dvb_usb_device_init(intf, &ec168_properties, THIS_MODULE, NULL,
adapter_nr);
if (ret)
goto error;
return ret;
error:
deb_info("%s: failed:%d\n", __func__, ret);
return ret;
}
static int __init ec168_module_init(void)
{
int ret;
deb_info("%s:\n", __func__);
ret = usb_register(&ec168_driver);
if (ret)
err("module init failed:%d", ret);
return ret;
}
static void __exit ec168_module_exit(void)
{
deb_info("%s:\n", __func__);
usb_deregister(&ec168_driver);
}
