int dibusb_streaming_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
if (adap->priv != NULL) {
struct dibusb_state *st = adap->priv;
if (st->ops.fifo_ctrl != NULL)
if (st->ops.fifo_ctrl(adap->fe_adap[0].fe, onoff)) {
err("error while controlling the fifo of the demod.");
return -ENODEV;
}
}
return 0;
}
int dibusb_pid_filter(struct dvb_usb_adapter *adap, int index, u16 pid, int onoff)
{
if (adap->priv != NULL) {
struct dibusb_state *st = adap->priv;
if (st->ops.pid_ctrl != NULL)
st->ops.pid_ctrl(adap->fe_adap[0].fe,
index, pid, onoff);
}
return 0;
}
int dibusb_pid_filter_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
if (adap->priv != NULL) {
struct dibusb_state *st = adap->priv;
if (st->ops.pid_parse != NULL)
if (st->ops.pid_parse(adap->fe_adap[0].fe, onoff) < 0)
err("could not handle pid_parser");
}
return 0;
}
int dibusb_power_ctrl(struct dvb_usb_device *d, int onoff)
{
u8 *b;
int ret;
b = kmalloc(3, GFP_KERNEL);
if (!b)
return -ENOMEM;
b[0] = DIBUSB_REQ_SET_IOCTL;
b[1] = DIBUSB_IOCTL_CMD_POWER_MODE;
b[2] = onoff ? DIBUSB_IOCTL_POWER_WAKEUP : DIBUSB_IOCTL_POWER_SLEEP;
ret = dvb_usb_generic_write(d, b, 3);
kfree(b);
msleep(10);
return ret;
}
int dibusb2_0_streaming_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
int ret;
u8 *b;
b = kmalloc(3, GFP_KERNEL);
if (!b)
return -ENOMEM;
if ((ret = dibusb_streaming_ctrl(adap,onoff)) < 0)
goto ret;
if (onoff) {
b[0] = DIBUSB_REQ_SET_STREAMING_MODE;
b[1] = 0x00;
ret = dvb_usb_generic_write(adap->dev, b, 2);
if (ret < 0)
goto ret;
}
b[0] = DIBUSB_REQ_SET_IOCTL;
b[1] = onoff ? DIBUSB_IOCTL_CMD_ENABLE_STREAM : DIBUSB_IOCTL_CMD_DISABLE_STREAM;
ret = dvb_usb_generic_write(adap->dev, b, 3);
ret:
kfree(b);
return ret;
}
int dibusb2_0_power_ctrl(struct dvb_usb_device *d, int onoff)
{
u8 *b;
int ret;
if (!onoff)
return 0;
b = kmalloc(3, GFP_KERNEL);
if (!b)
return -ENOMEM;
b[0] = DIBUSB_REQ_SET_IOCTL;
b[1] = DIBUSB_IOCTL_CMD_POWER_MODE;
b[2] = DIBUSB_IOCTL_POWER_WAKEUP;
ret = dvb_usb_generic_write(d, b, 3);
kfree(b);
return ret;
}
static int dibusb_i2c_msg(struct dvb_usb_device *d, u8 addr,
u8 *wbuf, u16 wlen, u8 *rbuf, u16 rlen)
{
u8 *sndbuf;
int ret, wo, len;
wo = (rbuf == NULL || rlen == 0);
len = 2 + wlen + (wo ? 0 : 2);
sndbuf = kmalloc(MAX_XFER_SIZE, GFP_KERNEL);
if (!sndbuf)
return -ENOMEM;
if (4 + wlen > MAX_XFER_SIZE) {
warn("i2c wr: len=%d is too big!\n", wlen);
ret = -EOPNOTSUPP;
goto ret;
}
sndbuf[0] = wo ? DIBUSB_REQ_I2C_WRITE : DIBUSB_REQ_I2C_READ;
sndbuf[1] = (addr << 1) | (wo ? 0 : 1);
memcpy(&sndbuf[2], wbuf, wlen);
if (!wo) {
sndbuf[wlen + 2] = (rlen >> 8) & 0xff;
sndbuf[wlen + 3] = rlen & 0xff;
}
ret = dvb_usb_generic_rw(d, sndbuf, len, rbuf, rlen, 0);
ret:
kfree(sndbuf);
return ret;
}
static int dibusb_i2c_xfer(struct i2c_adapter *adap,struct i2c_msg msg[],int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
int i;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
for (i = 0; i < num; i++) {
if (i+1 < num && (msg[i].flags & I2C_M_RD) == 0
&& (msg[i+1].flags & I2C_M_RD)) {
if (dibusb_i2c_msg(d, msg[i].addr, msg[i].buf,msg[i].len,
msg[i+1].buf,msg[i+1].len) < 0)
break;
i++;
} else if ((msg[i].flags & I2C_M_RD) == 0) {
if (dibusb_i2c_msg(d, msg[i].addr, msg[i].buf,msg[i].len,NULL,0) < 0)
break;
} else if (msg[i].addr != 0x50) {
if (dibusb_i2c_msg(d, msg[i].addr, NULL, 0, msg[i].buf, msg[i].len) < 0)
break;
}
}
mutex_unlock(&d->i2c_mutex);
return i;
}
static u32 dibusb_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
int dibusb_read_eeprom_byte(struct dvb_usb_device *d, u8 offs, u8 *val)
{
u8 wbuf[1] = { offs };
return dibusb_i2c_msg(d, 0x50, wbuf, 1, val, 1);
}
int dibusb_rc_query(struct dvb_usb_device *d, u32 *event, int *state)
{
u8 *buf;
int ret;
buf = kmalloc(5, GFP_KERNEL);
if (!buf)
return -ENOMEM;
buf[0] = DIBUSB_REQ_POLL_REMOTE;
ret = dvb_usb_generic_rw(d, buf, 1, buf, 5, 0);
if (ret < 0)
goto ret;
dvb_usb_nec_rc_key_to_event(d, buf, event, state);
if (buf[0] != 0)
deb_info("key: %*ph\n", 5, buf);
ret:
kfree(buf);
return ret;
}
