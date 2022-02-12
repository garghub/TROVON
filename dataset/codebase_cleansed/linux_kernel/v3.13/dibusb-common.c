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
u8 b[3];
int ret;
b[0] = DIBUSB_REQ_SET_IOCTL;
b[1] = DIBUSB_IOCTL_CMD_POWER_MODE;
b[2] = onoff ? DIBUSB_IOCTL_POWER_WAKEUP : DIBUSB_IOCTL_POWER_SLEEP;
ret = dvb_usb_generic_write(d,b,3);
msleep(10);
return ret;
}
int dibusb2_0_streaming_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
u8 b[3] = { 0 };
int ret;
if ((ret = dibusb_streaming_ctrl(adap,onoff)) < 0)
return ret;
if (onoff) {
b[0] = DIBUSB_REQ_SET_STREAMING_MODE;
b[1] = 0x00;
if ((ret = dvb_usb_generic_write(adap->dev,b,2)) < 0)
return ret;
}
b[0] = DIBUSB_REQ_SET_IOCTL;
b[1] = onoff ? DIBUSB_IOCTL_CMD_ENABLE_STREAM : DIBUSB_IOCTL_CMD_DISABLE_STREAM;
return dvb_usb_generic_write(adap->dev,b,3);
}
int dibusb2_0_power_ctrl(struct dvb_usb_device *d, int onoff)
{
if (onoff) {
u8 b[3] = { DIBUSB_REQ_SET_IOCTL, DIBUSB_IOCTL_CMD_POWER_MODE, DIBUSB_IOCTL_POWER_WAKEUP };
return dvb_usb_generic_write(d,b,3);
} else
return 0;
}
static int dibusb_i2c_msg(struct dvb_usb_device *d, u8 addr,
u8 *wbuf, u16 wlen, u8 *rbuf, u16 rlen)
{
u8 sndbuf[MAX_XFER_SIZE];
int wo = (rbuf == NULL || rlen == 0),
len = 2 + wlen + (wo ? 0 : 2);
if (4 + wlen > sizeof(sndbuf)) {
warn("i2c wr: len=%d is too big!\n", wlen);
return -EOPNOTSUPP;
}
sndbuf[0] = wo ? DIBUSB_REQ_I2C_WRITE : DIBUSB_REQ_I2C_READ;
sndbuf[1] = (addr << 1) | (wo ? 0 : 1);
memcpy(&sndbuf[2],wbuf,wlen);
if (!wo) {
sndbuf[wlen+2] = (rlen >> 8) & 0xff;
sndbuf[wlen+3] = rlen & 0xff;
}
return dvb_usb_generic_rw(d,sndbuf,len,rbuf,rlen,0);
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
int dibusb_dib3000mc_frontend_attach(struct dvb_usb_adapter *adap)
{
if (adap->dev->udev->descriptor.idVendor == USB_VID_LITEON &&
adap->dev->udev->descriptor.idProduct ==
USB_PID_LITEON_DVB_T_WARM) {
msleep(1000);
}
adap->fe_adap[0].fe = dvb_attach(dib3000mc_attach,
&adap->dev->i2c_adap,
DEFAULT_DIB3000P_I2C_ADDRESS,
&mod3000p_dib3000p_config);
if ((adap->fe_adap[0].fe) == NULL)
adap->fe_adap[0].fe = dvb_attach(dib3000mc_attach,
&adap->dev->i2c_adap,
DEFAULT_DIB3000MC_I2C_ADDRESS,
&mod3000p_dib3000p_config);
if ((adap->fe_adap[0].fe) != NULL) {
if (adap->priv != NULL) {
struct dibusb_state *st = adap->priv;
st->ops.pid_parse = dib3000mc_pid_parse;
st->ops.pid_ctrl = dib3000mc_pid_control;
}
return 0;
}
return -ENODEV;
}
int dibusb_dib3000mc_tuner_attach(struct dvb_usb_adapter *adap)
{
struct dibusb_state *st = adap->priv;
u8 a,b;
u16 if1 = 1220;
struct i2c_adapter *tun_i2c;
if (adap->dev->udev->descriptor.idVendor == USB_VID_LITEON &&
adap->dev->udev->descriptor.idProduct == USB_PID_LITEON_DVB_T_WARM) {
dibusb_read_eeprom_byte(adap->dev,0x7E,&a);
dibusb_read_eeprom_byte(adap->dev,0x7F,&b);
if (a == 0x00)
if1 += b;
else if (a == 0x80)
if1 -= b;
else
warn("LITE-ON DVB-T: Strange IF1 calibration :%2X %2X\n", a, b);
} else if (adap->dev->udev->descriptor.idVendor == USB_VID_DIBCOM &&
adap->dev->udev->descriptor.idProduct == USB_PID_DIBCOM_MOD3001_WARM) {
u8 desc;
dibusb_read_eeprom_byte(adap->dev, 7, &desc);
if (desc == 2) {
a = 127;
do {
dibusb_read_eeprom_byte(adap->dev, a, &desc);
a--;
} while (a > 7 && (desc == 0xff || desc == 0x00));
if (desc & 0x80)
if1 -= (0xff - desc);
else
if1 += desc;
}
}
tun_i2c = dib3000mc_get_tuner_i2c_master(adap->fe_adap[0].fe, 1);
if (dvb_attach(mt2060_attach, adap->fe_adap[0].fe, tun_i2c, &stk3000p_mt2060_config, if1) == NULL) {
if (dvb_attach(dvb_pll_attach, adap->fe_adap[0].fe, 0x60, tun_i2c, DVB_PLL_ENV57H1XD5) == NULL)
return -ENOMEM;
} else {
st->mt2060_present = 1;
dib3000mc_set_config(adap->fe_adap[0].fe, &stk3000p_dib3000p_config);
}
return 0;
}
int dibusb_rc_query(struct dvb_usb_device *d, u32 *event, int *state)
{
u8 key[5],cmd = DIBUSB_REQ_POLL_REMOTE;
dvb_usb_generic_rw(d,&cmd,1,key,5,0);
dvb_usb_nec_rc_key_to_event(d,key,event,state);
if (key[0] != 0)
deb_info("key: %*ph\n", 5, key);
return 0;
}
