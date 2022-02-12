static int cxusb_ctrl_msg(struct dvb_usb_device *d,
u8 cmd, u8 *wbuf, int wlen, u8 *rbuf, int rlen)
{
int wo = (rbuf == NULL || rlen == 0);
u8 sndbuf[MAX_XFER_SIZE];
if (1 + wlen > sizeof(sndbuf)) {
warn("i2c wr: len=%d is too big!\n",
wlen);
return -EOPNOTSUPP;
}
memset(sndbuf, 0, 1+wlen);
sndbuf[0] = cmd;
memcpy(&sndbuf[1], wbuf, wlen);
if (wo)
return dvb_usb_generic_write(d, sndbuf, 1+wlen);
else
return dvb_usb_generic_rw(d, sndbuf, 1+wlen, rbuf, rlen, 0);
}
static void cxusb_gpio_tuner(struct dvb_usb_device *d, int onoff)
{
struct cxusb_state *st = d->priv;
u8 o[2], i;
if (st->gpio_write_state[GPIO_TUNER] == onoff)
return;
o[0] = GPIO_TUNER;
o[1] = onoff;
cxusb_ctrl_msg(d, CMD_GPIO_WRITE, o, 2, &i, 1);
if (i != 0x01)
deb_info("gpio_write failed.\n");
st->gpio_write_state[GPIO_TUNER] = onoff;
}
static int cxusb_bluebird_gpio_rw(struct dvb_usb_device *d, u8 changemask,
u8 newval)
{
u8 o[2], gpio_state;
int rc;
o[0] = 0xff & ~changemask;
o[1] = newval & changemask;
rc = cxusb_ctrl_msg(d, CMD_BLUEBIRD_GPIO_RW, o, 2, &gpio_state, 1);
if (rc < 0 || (gpio_state & changemask) != (newval & changemask))
deb_info("bluebird_gpio_write failed.\n");
return rc < 0 ? rc : gpio_state;
}
static void cxusb_bluebird_gpio_pulse(struct dvb_usb_device *d, u8 pin, int low)
{
cxusb_bluebird_gpio_rw(d, pin, low ? 0 : pin);
msleep(5);
cxusb_bluebird_gpio_rw(d, pin, low ? pin : 0);
}
static void cxusb_nano2_led(struct dvb_usb_device *d, int onoff)
{
cxusb_bluebird_gpio_rw(d, 0x40, onoff ? 0 : 0x40);
}
static int cxusb_d680_dmb_gpio_tuner(struct dvb_usb_device *d,
u8 addr, int onoff)
{
u8 o[2] = {addr, onoff};
u8 i;
int rc;
rc = cxusb_ctrl_msg(d, CMD_GPIO_WRITE, o, 2, &i, 1);
if (rc < 0)
return rc;
if (i == 0x01)
return 0;
else {
deb_info("gpio_write failed.\n");
return -EIO;
}
}
static int cxusb_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msg[],
int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
int i;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
for (i = 0; i < num; i++) {
if (d->udev->descriptor.idVendor == USB_VID_MEDION)
switch (msg[i].addr) {
case 0x63:
cxusb_gpio_tuner(d, 0);
break;
default:
cxusb_gpio_tuner(d, 1);
break;
}
if (msg[i].flags & I2C_M_RD) {
u8 obuf[3], ibuf[MAX_XFER_SIZE];
if (1 + msg[i].len > sizeof(ibuf)) {
warn("i2c rd: len=%d is too big!\n",
msg[i].len);
return -EOPNOTSUPP;
}
obuf[0] = 0;
obuf[1] = msg[i].len;
obuf[2] = msg[i].addr;
if (cxusb_ctrl_msg(d, CMD_I2C_READ,
obuf, 3,
ibuf, 1+msg[i].len) < 0) {
warn("i2c read failed");
break;
}
memcpy(msg[i].buf, &ibuf[1], msg[i].len);
} else if (i+1 < num && (msg[i+1].flags & I2C_M_RD) &&
msg[i].addr == msg[i+1].addr) {
u8 obuf[MAX_XFER_SIZE], ibuf[MAX_XFER_SIZE];
if (3 + msg[i].len > sizeof(obuf)) {
warn("i2c wr: len=%d is too big!\n",
msg[i].len);
return -EOPNOTSUPP;
}
if (1 + msg[i + 1].len > sizeof(ibuf)) {
warn("i2c rd: len=%d is too big!\n",
msg[i + 1].len);
return -EOPNOTSUPP;
}
obuf[0] = msg[i].len;
obuf[1] = msg[i+1].len;
obuf[2] = msg[i].addr;
memcpy(&obuf[3], msg[i].buf, msg[i].len);
if (cxusb_ctrl_msg(d, CMD_I2C_READ,
obuf, 3+msg[i].len,
ibuf, 1+msg[i+1].len) < 0)
break;
if (ibuf[0] != 0x08)
deb_i2c("i2c read may have failed\n");
memcpy(msg[i+1].buf, &ibuf[1], msg[i+1].len);
i++;
} else {
u8 obuf[MAX_XFER_SIZE], ibuf;
if (2 + msg[i].len > sizeof(obuf)) {
warn("i2c wr: len=%d is too big!\n",
msg[i].len);
return -EOPNOTSUPP;
}
obuf[0] = msg[i].addr;
obuf[1] = msg[i].len;
memcpy(&obuf[2], msg[i].buf, msg[i].len);
if (cxusb_ctrl_msg(d, CMD_I2C_WRITE, obuf,
2+msg[i].len, &ibuf,1) < 0)
break;
if (ibuf != 0x08)
deb_i2c("i2c write may have failed\n");
}
}
mutex_unlock(&d->i2c_mutex);
return i == num ? num : -EREMOTEIO;
}
static u32 cxusb_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int cxusb_power_ctrl(struct dvb_usb_device *d, int onoff)
{
u8 b = 0;
if (onoff)
return cxusb_ctrl_msg(d, CMD_POWER_ON, &b, 1, NULL, 0);
else
return cxusb_ctrl_msg(d, CMD_POWER_OFF, &b, 1, NULL, 0);
}
static int cxusb_aver_power_ctrl(struct dvb_usb_device *d, int onoff)
{
int ret;
if (!onoff)
return cxusb_ctrl_msg(d, CMD_POWER_OFF, NULL, 0, NULL, 0);
if (d->state == DVB_USB_STATE_INIT &&
usb_set_interface(d->udev, 0, 0) < 0)
err("set interface failed");
do {} while (!(ret = cxusb_ctrl_msg(d, CMD_POWER_ON, NULL, 0, NULL, 0)) &&
!(ret = cxusb_ctrl_msg(d, 0x15, NULL, 0, NULL, 0)) &&
!(ret = cxusb_ctrl_msg(d, 0x17, NULL, 0, NULL, 0)) && 0);
if (!ret) {
int i;
u8 buf, bufs[] = {
0x0e, 0x2, 0x00, 0x7f,
0x0e, 0x2, 0x02, 0xfe,
0x0e, 0x2, 0x02, 0x01,
0x0e, 0x2, 0x00, 0x03,
0x0e, 0x2, 0x0d, 0x40,
0x0e, 0x2, 0x0e, 0x87,
0x0e, 0x2, 0x0f, 0x8e,
0x0e, 0x2, 0x10, 0x01,
0x0e, 0x2, 0x14, 0xd7,
0x0e, 0x2, 0x47, 0x88,
};
msleep(20);
for (i = 0; i < sizeof(bufs)/sizeof(u8); i += 4/sizeof(u8)) {
ret = cxusb_ctrl_msg(d, CMD_I2C_WRITE,
bufs+i, 4, &buf, 1);
if (ret)
break;
if (buf != 0x8)
return -EREMOTEIO;
}
}
return ret;
}
static int cxusb_bluebird_power_ctrl(struct dvb_usb_device *d, int onoff)
{
u8 b = 0;
if (onoff)
return cxusb_ctrl_msg(d, CMD_POWER_ON, &b, 1, NULL, 0);
else
return 0;
}
static int cxusb_nano2_power_ctrl(struct dvb_usb_device *d, int onoff)
{
int rc = 0;
rc = cxusb_power_ctrl(d, onoff);
if (!onoff)
cxusb_nano2_led(d, 0);
return rc;
}
static int cxusb_d680_dmb_power_ctrl(struct dvb_usb_device *d, int onoff)
{
int ret;
u8 b;
ret = cxusb_power_ctrl(d, onoff);
if (!onoff)
return ret;
msleep(128);
cxusb_ctrl_msg(d, CMD_DIGITAL, NULL, 0, &b, 1);
msleep(100);
return ret;
}
static int cxusb_streaming_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
u8 buf[2] = { 0x03, 0x00 };
if (onoff)
cxusb_ctrl_msg(adap->dev, CMD_STREAMING_ON, buf, 2, NULL, 0);
else
cxusb_ctrl_msg(adap->dev, CMD_STREAMING_OFF, NULL, 0, NULL, 0);
return 0;
}
static int cxusb_aver_streaming_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
if (onoff)
cxusb_ctrl_msg(adap->dev, CMD_AVER_STREAM_ON, NULL, 0, NULL, 0);
else
cxusb_ctrl_msg(adap->dev, CMD_AVER_STREAM_OFF,
NULL, 0, NULL, 0);
return 0;
}
static void cxusb_d680_dmb_drain_message(struct dvb_usb_device *d)
{
int ep = d->props.generic_bulk_ctrl_endpoint;
const int timeout = 100;
const int junk_len = 32;
u8 *junk;
int rd_count;
junk = kmalloc(junk_len, GFP_KERNEL);
if (!junk)
return;
while (1) {
if (usb_bulk_msg(d->udev,
usb_rcvbulkpipe(d->udev, ep),
junk, junk_len, &rd_count, timeout) < 0)
break;
if (!rd_count)
break;
}
kfree(junk);
}
static void cxusb_d680_dmb_drain_video(struct dvb_usb_device *d)
{
struct usb_data_stream_properties *p = &d->props.adapter[0].fe[0].stream;
const int timeout = 100;
const int junk_len = p->u.bulk.buffersize;
u8 *junk;
int rd_count;
junk = kmalloc(junk_len, GFP_KERNEL);
if (!junk)
return;
while (1) {
if (usb_bulk_msg(d->udev,
usb_rcvbulkpipe(d->udev, p->endpoint),
junk, junk_len, &rd_count, timeout) < 0)
break;
if (!rd_count)
break;
}
kfree(junk);
}
static int cxusb_d680_dmb_streaming_ctrl(
struct dvb_usb_adapter *adap, int onoff)
{
if (onoff) {
u8 buf[2] = { 0x03, 0x00 };
cxusb_d680_dmb_drain_video(adap->dev);
return cxusb_ctrl_msg(adap->dev, CMD_STREAMING_ON,
buf, sizeof(buf), NULL, 0);
} else {
int ret = cxusb_ctrl_msg(adap->dev,
CMD_STREAMING_OFF, NULL, 0, NULL, 0);
return ret;
}
}
static int cxusb_rc_query(struct dvb_usb_device *d, u32 *event, int *state)
{
struct rc_map_table *keymap = d->props.rc.legacy.rc_map_table;
u8 ircode[4];
int i;
cxusb_ctrl_msg(d, CMD_GET_IR_CODE, NULL, 0, ircode, 4);
*event = 0;
*state = REMOTE_NO_KEY_PRESSED;
for (i = 0; i < d->props.rc.legacy.rc_map_size; i++) {
if (rc5_custom(&keymap[i]) == ircode[2] &&
rc5_data(&keymap[i]) == ircode[3]) {
*event = keymap[i].keycode;
*state = REMOTE_KEY_PRESSED;
return 0;
}
}
return 0;
}
static int cxusb_bluebird2_rc_query(struct dvb_usb_device *d, u32 *event,
int *state)
{
struct rc_map_table *keymap = d->props.rc.legacy.rc_map_table;
u8 ircode[4];
int i;
struct i2c_msg msg = { .addr = 0x6b, .flags = I2C_M_RD,
.buf = ircode, .len = 4 };
*event = 0;
*state = REMOTE_NO_KEY_PRESSED;
if (cxusb_i2c_xfer(&d->i2c_adap, &msg, 1) != 1)
return 0;
for (i = 0; i < d->props.rc.legacy.rc_map_size; i++) {
if (rc5_custom(&keymap[i]) == ircode[1] &&
rc5_data(&keymap[i]) == ircode[2]) {
*event = keymap[i].keycode;
*state = REMOTE_KEY_PRESSED;
return 0;
}
}
return 0;
}
static int cxusb_d680_dmb_rc_query(struct dvb_usb_device *d, u32 *event,
int *state)
{
struct rc_map_table *keymap = d->props.rc.legacy.rc_map_table;
u8 ircode[2];
int i;
*event = 0;
*state = REMOTE_NO_KEY_PRESSED;
if (cxusb_ctrl_msg(d, 0x10, NULL, 0, ircode, 2) < 0)
return 0;
for (i = 0; i < d->props.rc.legacy.rc_map_size; i++) {
if (rc5_custom(&keymap[i]) == ircode[0] &&
rc5_data(&keymap[i]) == ircode[1]) {
*event = keymap[i].keycode;
*state = REMOTE_KEY_PRESSED;
return 0;
}
}
return 0;
}
static int cxusb_dee1601_demod_init(struct dvb_frontend* fe)
{
static u8 clock_config [] = { CLOCK_CTL, 0x38, 0x28 };
static u8 reset [] = { RESET, 0x80 };
static u8 adc_ctl_1_cfg [] = { ADC_CTL_1, 0x40 };
static u8 agc_cfg [] = { AGC_TARGET, 0x28, 0x20 };
static u8 gpp_ctl_cfg [] = { GPP_CTL, 0x33 };
static u8 capt_range_cfg[] = { CAPT_RANGE, 0x32 };
mt352_write(fe, clock_config, sizeof(clock_config));
udelay(200);
mt352_write(fe, reset, sizeof(reset));
mt352_write(fe, adc_ctl_1_cfg, sizeof(adc_ctl_1_cfg));
mt352_write(fe, agc_cfg, sizeof(agc_cfg));
mt352_write(fe, gpp_ctl_cfg, sizeof(gpp_ctl_cfg));
mt352_write(fe, capt_range_cfg, sizeof(capt_range_cfg));
return 0;
}
static int cxusb_mt352_demod_init(struct dvb_frontend* fe)
{
static u8 clock_config [] = { CLOCK_CTL, 0x38, 0x29 };
static u8 reset [] = { RESET, 0x80 };
static u8 adc_ctl_1_cfg [] = { ADC_CTL_1, 0x40 };
static u8 agc_cfg [] = { AGC_TARGET, 0x24, 0x20 };
static u8 gpp_ctl_cfg [] = { GPP_CTL, 0x33 };
static u8 capt_range_cfg[] = { CAPT_RANGE, 0x32 };
mt352_write(fe, clock_config, sizeof(clock_config));
udelay(200);
mt352_write(fe, reset, sizeof(reset));
mt352_write(fe, adc_ctl_1_cfg, sizeof(adc_ctl_1_cfg));
mt352_write(fe, agc_cfg, sizeof(agc_cfg));
mt352_write(fe, gpp_ctl_cfg, sizeof(gpp_ctl_cfg));
mt352_write(fe, capt_range_cfg, sizeof(capt_range_cfg));
return 0;
}
static int cxusb_fmd1216me_tuner_attach(struct dvb_usb_adapter *adap)
{
dvb_attach(simple_tuner_attach, adap->fe_adap[0].fe,
&adap->dev->i2c_adap, 0x61,
TUNER_PHILIPS_FMD1216ME_MK3);
return 0;
}
static int cxusb_dee1601_tuner_attach(struct dvb_usb_adapter *adap)
{
dvb_attach(dvb_pll_attach, adap->fe_adap[0].fe, 0x61,
NULL, DVB_PLL_THOMSON_DTT7579);
return 0;
}
static int cxusb_lgz201_tuner_attach(struct dvb_usb_adapter *adap)
{
dvb_attach(dvb_pll_attach, adap->fe_adap[0].fe, 0x61, NULL, DVB_PLL_LG_Z201);
return 0;
}
static int cxusb_dtt7579_tuner_attach(struct dvb_usb_adapter *adap)
{
dvb_attach(dvb_pll_attach, adap->fe_adap[0].fe, 0x60,
NULL, DVB_PLL_THOMSON_DTT7579);
return 0;
}
static int cxusb_lgh064f_tuner_attach(struct dvb_usb_adapter *adap)
{
dvb_attach(simple_tuner_attach, adap->fe_adap[0].fe,
&adap->dev->i2c_adap, 0x61, TUNER_LG_TDVS_H06XF);
return 0;
}
static int dvico_bluebird_xc2028_callback(void *ptr, int component,
int command, int arg)
{
struct dvb_usb_adapter *adap = ptr;
struct dvb_usb_device *d = adap->dev;
switch (command) {
case XC2028_TUNER_RESET:
deb_info("%s: XC2028_TUNER_RESET %d\n", __func__, arg);
cxusb_bluebird_gpio_pulse(d, 0x01, 1);
break;
case XC2028_RESET_CLK:
deb_info("%s: XC2028_RESET_CLK %d\n", __func__, arg);
break;
default:
deb_info("%s: unknown command %d, arg %d\n", __func__,
command, arg);
return -EINVAL;
}
return 0;
}
static int cxusb_dvico_xc3028_tuner_attach(struct dvb_usb_adapter *adap)
{
struct dvb_frontend *fe;
struct xc2028_config cfg = {
.i2c_adap = &adap->dev->i2c_adap,
.i2c_addr = 0x61,
};
static struct xc2028_ctrl ctl = {
.fname = XC2028_DEFAULT_FIRMWARE,
.max_len = 64,
.demod = XC3028_FE_ZARLINK456,
};
adap->fe_adap[0].fe->callback = dvico_bluebird_xc2028_callback;
fe = dvb_attach(xc2028_attach, adap->fe_adap[0].fe, &cfg);
if (fe == NULL || fe->ops.tuner_ops.set_config == NULL)
return -EIO;
fe->ops.tuner_ops.set_config(fe, &ctl);
return 0;
}
static int cxusb_mxl5003s_tuner_attach(struct dvb_usb_adapter *adap)
{
dvb_attach(mxl5005s_attach, adap->fe_adap[0].fe,
&adap->dev->i2c_adap, &aver_a868r_tuner);
return 0;
}
static int cxusb_d680_dmb_tuner_attach(struct dvb_usb_adapter *adap)
{
struct dvb_frontend *fe;
fe = dvb_attach(mxl5005s_attach, adap->fe_adap[0].fe,
&adap->dev->i2c_adap, &d680_dmb_tuner);
return (fe == NULL) ? -EIO : 0;
}
static int cxusb_mygica_d689_tuner_attach(struct dvb_usb_adapter *adap)
{
struct dvb_frontend *fe;
fe = dvb_attach(max2165_attach, adap->fe_adap[0].fe,
&adap->dev->i2c_adap, &mygica_d689_max2165_cfg);
return (fe == NULL) ? -EIO : 0;
}
static int cxusb_cx22702_frontend_attach(struct dvb_usb_adapter *adap)
{
u8 b;
if (usb_set_interface(adap->dev->udev, 0, 6) < 0)
err("set interface failed");
cxusb_ctrl_msg(adap->dev, CMD_DIGITAL, NULL, 0, &b, 1);
adap->fe_adap[0].fe = dvb_attach(cx22702_attach, &cxusb_cx22702_config,
&adap->dev->i2c_adap);
if ((adap->fe_adap[0].fe) != NULL)
return 0;
return -EIO;
}
static int cxusb_lgdt3303_frontend_attach(struct dvb_usb_adapter *adap)
{
if (usb_set_interface(adap->dev->udev, 0, 7) < 0)
err("set interface failed");
cxusb_ctrl_msg(adap->dev, CMD_DIGITAL, NULL, 0, NULL, 0);
adap->fe_adap[0].fe = dvb_attach(lgdt330x_attach,
&cxusb_lgdt3303_config,
&adap->dev->i2c_adap);
if ((adap->fe_adap[0].fe) != NULL)
return 0;
return -EIO;
}
static int cxusb_aver_lgdt3303_frontend_attach(struct dvb_usb_adapter *adap)
{
adap->fe_adap[0].fe = dvb_attach(lgdt330x_attach, &cxusb_aver_lgdt3303_config,
&adap->dev->i2c_adap);
if (adap->fe_adap[0].fe != NULL)
return 0;
return -EIO;
}
static int cxusb_mt352_frontend_attach(struct dvb_usb_adapter *adap)
{
if (usb_set_interface(adap->dev->udev, 0, 0) < 0)
err("set interface failed");
cxusb_ctrl_msg(adap->dev, CMD_DIGITAL, NULL, 0, NULL, 0);
adap->fe_adap[0].fe = dvb_attach(mt352_attach, &cxusb_mt352_config,
&adap->dev->i2c_adap);
if ((adap->fe_adap[0].fe) != NULL)
return 0;
return -EIO;
}
static int cxusb_dee1601_frontend_attach(struct dvb_usb_adapter *adap)
{
if (usb_set_interface(adap->dev->udev, 0, 0) < 0)
err("set interface failed");
cxusb_ctrl_msg(adap->dev, CMD_DIGITAL, NULL, 0, NULL, 0);
adap->fe_adap[0].fe = dvb_attach(mt352_attach, &cxusb_dee1601_config,
&adap->dev->i2c_adap);
if ((adap->fe_adap[0].fe) != NULL)
return 0;
adap->fe_adap[0].fe = dvb_attach(zl10353_attach,
&cxusb_zl10353_dee1601_config,
&adap->dev->i2c_adap);
if ((adap->fe_adap[0].fe) != NULL)
return 0;
return -EIO;
}
static int cxusb_dualdig4_frontend_attach(struct dvb_usb_adapter *adap)
{
u8 ircode[4];
int i;
struct i2c_msg msg = { .addr = 0x6b, .flags = I2C_M_RD,
.buf = ircode, .len = 4 };
if (usb_set_interface(adap->dev->udev, 0, 1) < 0)
err("set interface failed");
cxusb_ctrl_msg(adap->dev, CMD_DIGITAL, NULL, 0, NULL, 0);
cxusb_bluebird_gpio_rw(adap->dev, 0x04, 0);
cxusb_bluebird_gpio_pulse(adap->dev, 0x01, 1);
cxusb_bluebird_gpio_pulse(adap->dev, 0x02, 1);
adap->fe_adap[0].fe =
dvb_attach(zl10353_attach,
&cxusb_zl10353_xc3028_config_no_i2c_gate,
&adap->dev->i2c_adap);
if ((adap->fe_adap[0].fe) == NULL)
return -EIO;
for (i = 0; adap->dev->props.rc.legacy.rc_map_table != NULL && i < 5; i++) {
msleep(20);
if (cxusb_i2c_xfer(&adap->dev->i2c_adap, &msg, 1) != 1)
goto no_IR;
if (ircode[0] == 0 && ircode[1] == 0)
continue;
if (ircode[2] + ircode[3] != 0xff) {
no_IR:
adap->dev->props.rc.legacy.rc_map_table = NULL;
info("No IR receiver detected on this device.");
break;
}
}
return 0;
}
static int cxusb_dualdig4_rev2_frontend_attach(struct dvb_usb_adapter *adap)
{
if (usb_set_interface(adap->dev->udev, 0, 1) < 0)
err("set interface failed");
cxusb_ctrl_msg(adap->dev, CMD_DIGITAL, NULL, 0, NULL, 0);
cxusb_bluebird_gpio_pulse(adap->dev, 0x02, 1);
if (dib7000p_i2c_enumeration(&adap->dev->i2c_adap, 1, 18,
&cxusb_dualdig4_rev2_config) < 0) {
printk(KERN_WARNING "Unable to enumerate dib7000p\n");
return -ENODEV;
}
adap->fe_adap[0].fe = dvb_attach(dib7000p_attach, &adap->dev->i2c_adap, 0x80,
&cxusb_dualdig4_rev2_config);
if (adap->fe_adap[0].fe == NULL)
return -EIO;
return 0;
}
static int dib7070_tuner_reset(struct dvb_frontend *fe, int onoff)
{
return dib7000p_set_gpio(fe, 8, 0, !onoff);
}
static int dib7070_tuner_sleep(struct dvb_frontend *fe, int onoff)
{
return 0;
}
static int dib7070_set_param_override(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct dvb_usb_adapter *adap = fe->dvb->priv;
struct dib0700_adapter_state *state = adap->priv;
u16 offset;
u8 band = BAND_OF_FREQUENCY(p->frequency/1000);
switch (band) {
case BAND_VHF: offset = 950; break;
default:
case BAND_UHF: offset = 550; break;
}
dib7000p_set_wbd_ref(fe, offset + dib0070_wbd_offset(fe));
return state->set_param_save(fe);
}
static int cxusb_dualdig4_rev2_tuner_attach(struct dvb_usb_adapter *adap)
{
struct dib0700_adapter_state *st = adap->priv;
struct i2c_adapter *tun_i2c =
dib7000p_get_i2c_master(adap->fe_adap[0].fe,
DIBX000_I2C_INTERFACE_TUNER, 1);
if (dvb_attach(dib0070_attach, adap->fe_adap[0].fe, tun_i2c,
&dib7070p_dib0070_config) == NULL)
return -ENODEV;
st->set_param_save = adap->fe_adap[0].fe->ops.tuner_ops.set_params;
adap->fe_adap[0].fe->ops.tuner_ops.set_params = dib7070_set_param_override;
return 0;
}
static int cxusb_nano2_frontend_attach(struct dvb_usb_adapter *adap)
{
if (usb_set_interface(adap->dev->udev, 0, 1) < 0)
err("set interface failed");
cxusb_ctrl_msg(adap->dev, CMD_DIGITAL, NULL, 0, NULL, 0);
cxusb_bluebird_gpio_rw(adap->dev, 0x04, 0);
cxusb_bluebird_gpio_pulse(adap->dev, 0x01, 1);
cxusb_bluebird_gpio_pulse(adap->dev, 0x02, 1);
adap->fe_adap[0].fe = dvb_attach(zl10353_attach,
&cxusb_zl10353_xc3028_config,
&adap->dev->i2c_adap);
if ((adap->fe_adap[0].fe) != NULL)
return 0;
adap->fe_adap[0].fe = dvb_attach(mt352_attach,
&cxusb_mt352_xc3028_config,
&adap->dev->i2c_adap);
if ((adap->fe_adap[0].fe) != NULL)
return 0;
return -EIO;
}
static int cxusb_d680_dmb_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dvb_usb_device *d = adap->dev;
int n;
if (usb_set_interface(d->udev, 0, 0) < 0)
err("set interface failed");
usb_clear_halt(d->udev,
usb_sndbulkpipe(d->udev, d->props.generic_bulk_ctrl_endpoint));
usb_clear_halt(d->udev,
usb_rcvbulkpipe(d->udev, d->props.generic_bulk_ctrl_endpoint));
usb_clear_halt(d->udev,
usb_rcvbulkpipe(d->udev, d->props.adapter[0].fe[0].stream.endpoint));
for (n = 0; n < 5; n++) {
cxusb_d680_dmb_drain_message(d);
cxusb_d680_dmb_drain_video(d);
msleep(200);
}
if (cxusb_d680_dmb_gpio_tuner(d, 0x07, 0) < 0) {
err("clear tuner gpio failed");
return -EIO;
}
msleep(100);
if (cxusb_d680_dmb_gpio_tuner(d, 0x07, 1) < 0) {
err("set tuner gpio failed");
return -EIO;
}
msleep(100);
adap->fe_adap[0].fe = dvb_attach(lgs8gxx_attach, &d680_lgs8gl5_cfg, &d->i2c_adap);
if (adap->fe_adap[0].fe == NULL)
return -EIO;
return 0;
}
static int cxusb_mygica_d689_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dvb_usb_device *d = adap->dev;
if (usb_set_interface(d->udev, 0, 0) < 0)
err("set interface failed");
usb_clear_halt(d->udev,
usb_sndbulkpipe(d->udev, d->props.generic_bulk_ctrl_endpoint));
usb_clear_halt(d->udev,
usb_rcvbulkpipe(d->udev, d->props.generic_bulk_ctrl_endpoint));
usb_clear_halt(d->udev,
usb_rcvbulkpipe(d->udev, d->props.adapter[0].fe[0].stream.endpoint));
if (cxusb_d680_dmb_gpio_tuner(d, 0x07, 0) < 0) {
err("clear tuner gpio failed");
return -EIO;
}
msleep(100);
if (cxusb_d680_dmb_gpio_tuner(d, 0x07, 1) < 0) {
err("set tuner gpio failed");
return -EIO;
}
msleep(100);
adap->fe_adap[0].fe = dvb_attach(atbm8830_attach, &mygica_d689_atbm8830_cfg,
&d->i2c_adap);
if (adap->fe_adap[0].fe == NULL)
return -EIO;
return 0;
}
static int bluebird_fx2_identify_state(struct usb_device *udev,
struct dvb_usb_device_properties *props,
struct dvb_usb_device_description **desc,
int *cold)
{
int wascold = *cold;
*cold = udev->descriptor.bDeviceClass == 0xff &&
udev->descriptor.bDeviceSubClass == 0xff &&
udev->descriptor.bDeviceProtocol == 0xff;
if (*cold && !wascold)
*desc = NULL;
return 0;
}
static int bluebird_patch_dvico_firmware_download(struct usb_device *udev,
const struct firmware *fw)
{
int pos;
for (pos = 0; pos < ARRAY_SIZE(dvico_firmware_id_offsets); pos++) {
int idoff = dvico_firmware_id_offsets[pos];
if (fw->size < idoff + 4)
continue;
if (fw->data[idoff] == (USB_VID_DVICO & 0xff) &&
fw->data[idoff + 1] == USB_VID_DVICO >> 8) {
struct firmware new_fw;
u8 *new_fw_data = vmalloc(fw->size);
int ret;
if (!new_fw_data)
return -ENOMEM;
memcpy(new_fw_data, fw->data, fw->size);
new_fw.size = fw->size;
new_fw.data = new_fw_data;
new_fw_data[idoff + 2] =
le16_to_cpu(udev->descriptor.idProduct) + 1;
new_fw_data[idoff + 3] =
le16_to_cpu(udev->descriptor.idProduct) >> 8;
ret = usb_cypress_load_firmware(udev, &new_fw,
CYPRESS_FX2);
vfree(new_fw_data);
return ret;
}
}
return -EINVAL;
}
static int cxusb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
if (0 == dvb_usb_device_init(intf, &cxusb_medion_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &cxusb_bluebird_lgh064f_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &cxusb_bluebird_dee1601_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &cxusb_bluebird_lgz201_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &cxusb_bluebird_dtt7579_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &cxusb_bluebird_dualdig4_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &cxusb_bluebird_nano2_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf,
&cxusb_bluebird_nano2_needsfirmware_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &cxusb_aver_a868r_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf,
&cxusb_bluebird_dualdig4_rev2_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &cxusb_d680_dmb_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &cxusb_mygica_d689_properties,
THIS_MODULE, NULL, adapter_nr) ||
0)
return 0;
return -EINVAL;
}
