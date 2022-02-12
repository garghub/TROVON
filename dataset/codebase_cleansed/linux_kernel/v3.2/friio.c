static int gl861_i2c_ctrlmsg_data(struct dvb_usb_device *d, u8 addr,
u8 *wbuf, u16 wlen, u8 *rbuf, u16 rlen)
{
u16 index = wbuf[0];
u16 value = addr << (8 + 1);
int wo = (rbuf == NULL || rlen == 0);
u8 req, type;
deb_xfer("write to PLL:0x%02x via FE reg:0x%02x, len:%d\n",
wbuf[1], wbuf[0], wlen - 1);
if (wo && wlen >= 2) {
req = GL861_REQ_I2C_DATA_CTRL_WRITE;
type = GL861_WRITE;
udelay(20);
return usb_control_msg(d->udev, usb_sndctrlpipe(d->udev, 0),
req, type, value, index,
&wbuf[1], wlen - 1, 2000);
}
deb_xfer("not supported ctrl-msg, aborting.");
return -EINVAL;
}
static int gl861_i2c_msg(struct dvb_usb_device *d, u8 addr,
u8 *wbuf, u16 wlen, u8 *rbuf, u16 rlen)
{
u16 index;
u16 value = addr << (8 + 1);
int wo = (rbuf == NULL || rlen == 0);
u8 req, type;
unsigned int pipe;
if (addr == friio_fe_config.demod_address &&
wbuf[0] == JDVBT90502_2ND_I2C_REG)
return gl861_i2c_ctrlmsg_data(d, addr, wbuf, wlen, rbuf, rlen);
if (wo) {
req = GL861_REQ_I2C_WRITE;
type = GL861_WRITE;
pipe = usb_sndctrlpipe(d->udev, 0);
} else {
req = GL861_REQ_I2C_READ;
type = GL861_READ;
pipe = usb_rcvctrlpipe(d->udev, 0);
}
switch (wlen) {
case 1:
index = wbuf[0];
break;
case 2:
index = wbuf[0];
value = value + wbuf[1];
break;
case 3:
index = (wbuf[2] << 8) | wbuf[0];
value = value + wbuf[1];
break;
default:
deb_xfer("wlen = %x, aborting.", wlen);
return -EINVAL;
}
msleep(1);
return usb_control_msg(d->udev, pipe, req, type,
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
if (i + 1 < num && (msg[i + 1].flags & I2C_M_RD)) {
if (gl861_i2c_msg(d, msg[i].addr,
msg[i].buf, msg[i].len,
msg[i + 1].buf, msg[i + 1].len) < 0)
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
static int friio_ext_ctl(struct dvb_usb_adapter *adap,
u32 sat_color, int lnb_on)
{
int i;
int ret;
struct i2c_msg msg;
u8 *buf;
u32 mask;
u8 lnb = (lnb_on) ? FRIIO_CTL_LNB : 0;
buf = kmalloc(2, GFP_KERNEL);
if (!buf)
return -ENOMEM;
msg.addr = 0x00;
msg.flags = 0;
msg.len = 2;
msg.buf = buf;
buf[0] = 0x00;
buf[1] = lnb | FRIIO_CTL_LED | FRIIO_CTL_STROBE;
ret = gl861_i2c_xfer(&adap->dev->i2c_adap, &msg, 1);
buf[1] |= FRIIO_CTL_CLK;
ret += gl861_i2c_xfer(&adap->dev->i2c_adap, &msg, 1);
buf[1] = lnb | FRIIO_CTL_STROBE;
ret += gl861_i2c_xfer(&adap->dev->i2c_adap, &msg, 1);
buf[1] |= FRIIO_CTL_CLK;
ret += gl861_i2c_xfer(&adap->dev->i2c_adap, &msg, 1);
mask = 1 << 31;
for (i = 0; i < 32; i++) {
buf[1] = lnb | FRIIO_CTL_STROBE;
if (sat_color & mask)
buf[1] |= FRIIO_CTL_LED;
ret += gl861_i2c_xfer(&adap->dev->i2c_adap, &msg, 1);
buf[1] |= FRIIO_CTL_CLK;
ret += gl861_i2c_xfer(&adap->dev->i2c_adap, &msg, 1);
mask >>= 1;
}
buf[1] = lnb;
ret += gl861_i2c_xfer(&adap->dev->i2c_adap, &msg, 1);
buf[1] |= FRIIO_CTL_CLK;
ret += gl861_i2c_xfer(&adap->dev->i2c_adap, &msg, 1);
kfree(buf);
return (ret == 70);
}
static int friio_initialize(struct dvb_usb_device *d)
{
int ret;
int i;
int retry = 0;
u8 *rbuf, *wbuf;
deb_info("%s called.\n", __func__);
wbuf = kmalloc(3, GFP_KERNEL);
if (!wbuf)
return -ENOMEM;
rbuf = kmalloc(2, GFP_KERNEL);
if (!rbuf) {
kfree(wbuf);
return -ENOMEM;
}
wbuf[0] = 0x11;
wbuf[1] = 0x02;
ret = gl861_i2c_msg(d, 0x00, wbuf, 2, NULL, 0);
if (ret < 0)
goto error;
msleep(2);
wbuf[0] = 0x11;
wbuf[1] = 0x00;
ret = gl861_i2c_msg(d, 0x00, wbuf, 2, NULL, 0);
if (ret < 0)
goto error;
msleep(1);
wbuf[0] = 0x03;
wbuf[1] = 0x80;
ret = usb_control_msg(d->udev, usb_sndctrlpipe(d->udev, 0),
GL861_REQ_I2C_DATA_CTRL_WRITE, GL861_WRITE,
0x1200, 0x0100, wbuf, 2, 2000);
if (ret < 0)
goto error;
msleep(2);
wbuf[0] = 0x00;
wbuf[2] = 0x01;
wbuf[1] = 0x00;
ret = gl861_i2c_msg(d, 0x12 >> 1, wbuf, 3, rbuf, 2);
if (ret < 0 || rbuf[0] != 0xff || rbuf[1] != 0xff)
goto error;
msleep(2);
wbuf[0] = 0x03;
wbuf[1] = 0x80;
ret = usb_control_msg(d->udev, usb_sndctrlpipe(d->udev, 0),
GL861_REQ_I2C_DATA_CTRL_WRITE, GL861_WRITE,
0x9000, 0x0100, wbuf, 2, 2000);
if (ret < 0)
goto error;
msleep(2);
wbuf[0] = 0x00;
wbuf[2] = 0x01;
wbuf[1] = 0x00;
ret = gl861_i2c_msg(d, 0x90 >> 1, wbuf, 3, rbuf, 2);
if (ret < 0 || rbuf[0] != 0xff || rbuf[1] != 0xff)
goto error;
msleep(1);
restart:
wbuf[0] = JDVBT90502_2ND_I2C_REG;
wbuf[1] = (FRIIO_PLL_ADDR << 1) + 1;
ret = gl861_i2c_msg(d, FRIIO_DEMOD_ADDR, wbuf, 2, NULL, 0);
if (ret < 0)
goto error;
msleep(5);
wbuf[0] = 0x00;
wbuf[2] = 0x01;
wbuf[1] = 0x00;
ret = gl861_i2c_msg(d, FRIIO_DEMOD_ADDR, wbuf, 3, rbuf, 1);
if (ret < 0)
goto error;
if (rbuf[0] & 0x80) {
if (++retry > 3) {
deb_info("failed to get the correct"
" FE demod status:0x%02x\n", rbuf[0]);
goto error;
}
msleep(100);
goto restart;
}
msleep(1);
wbuf[0] = 0x30;
wbuf[1] = 0x04;
ret = gl861_i2c_msg(d, 0x00, wbuf, 2, NULL, 0);
if (ret < 0)
goto error;
msleep(2);
wbuf[0] = 0x00;
wbuf[1] = 0x01;
ret = gl861_i2c_msg(d, 0x00, wbuf, 2, NULL, 0);
if (ret < 0)
goto error;
wbuf[0] = 0x06;
wbuf[1] = 0x0F;
ret = gl861_i2c_msg(d, 0x00, wbuf, 2, NULL, 0);
if (ret < 0)
goto error;
msleep(10);
for (i = 0; i < cmdlen; i++) {
ret = gl861_i2c_msg(d, 0x00, streaming_init_cmds[i], 2,
NULL, 0);
if (ret < 0)
goto error;
msleep(1);
}
msleep(20);
ret = friio_streaming_ctrl(&d->adapter[0], 0);
if (ret < 0)
goto error;
return 0;
error:
kfree(wbuf);
kfree(rbuf);
deb_info("%s:ret == %d\n", __func__, ret);
return -EIO;
}
static int friio_streaming_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
int ret;
deb_info("%s called.(%d)\n", __func__, onoff);
if (onoff)
ret = friio_ext_ctl(adap, 0x6400ff64, 1);
else
ret = friio_ext_ctl(adap, 0x96ff00ff, 1);
if (ret != 1) {
deb_info("%s failed to send cmdx. ret==%d\n", __func__, ret);
return -EREMOTEIO;
}
return 0;
}
static int friio_frontend_attach(struct dvb_usb_adapter *adap)
{
if (friio_initialize(adap->dev) < 0)
return -EIO;
adap->fe_adap[0].fe = jdvbt90502_attach(adap->dev);
if (adap->fe_adap[0].fe == NULL)
return -EIO;
return 0;
}
static int friio_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct dvb_usb_device *d;
struct usb_host_interface *alt;
int ret;
if (intf->num_altsetting < GL861_ALTSETTING_COUNT)
return -ENODEV;
alt = usb_altnum_to_altsetting(intf, FRIIO_BULK_ALTSETTING);
if (alt == NULL) {
deb_rc("not alt found!\n");
return -ENODEV;
}
ret = usb_set_interface(interface_to_usbdev(intf),
alt->desc.bInterfaceNumber,
alt->desc.bAlternateSetting);
if (ret != 0) {
deb_rc("failed to set alt-setting!\n");
return ret;
}
ret = dvb_usb_device_init(intf, &friio_properties,
THIS_MODULE, &d, adapter_nr);
if (ret == 0)
friio_streaming_ctrl(&d->adapter[0], 1);
return ret;
}
static int __init friio_module_init(void)
{
int ret;
ret = usb_register(&friio_driver);
if (ret)
err("usb_register failed. Error number %d", ret);
return ret;
}
static void __exit friio_module_exit(void)
{
usb_deregister(&friio_driver);
}
