static int technisat_usb2_i2c_access(struct usb_device *udev,
u8 device_addr, u8 *tx, u8 txlen, u8 *rx, u8 rxlen)
{
u8 b[64];
int ret, actual_length;
deb_i2c("i2c-access: %02x, tx: ", device_addr);
debug_dump(tx, txlen, deb_i2c);
deb_i2c(" ");
if (txlen > 62) {
err("i2c TX buffer can't exceed 62 bytes (dev 0x%02x)",
device_addr);
txlen = 62;
}
if (rxlen > 62) {
err("i2c RX buffer can't exceed 62 bytes (dev 0x%02x)",
device_addr);
rxlen = 62;
}
b[0] = I2C_SPEED_100KHZ_BIT;
b[1] = device_addr << 1;
if (rx != NULL) {
b[0] |= rxlen;
b[1] |= 1;
}
memcpy(&b[2], tx, txlen);
ret = usb_bulk_msg(udev,
usb_sndbulkpipe(udev, 0x01),
b, 2 + txlen,
NULL, 1000);
if (ret < 0) {
err("i2c-error: out failed %02x = %d", device_addr, ret);
return -ENODEV;
}
ret = usb_bulk_msg(udev,
usb_rcvbulkpipe(udev, 0x01),
b, 64, &actual_length, 1000);
if (ret < 0) {
err("i2c-error: in failed %02x = %d", device_addr, ret);
return -ENODEV;
}
if (b[0] != I2C_STATUS_OK) {
err("i2c-error: %02x = %d", device_addr, b[0]);
if (!(b[0] == I2C_STATUS_NAK &&
device_addr == 0x60
))
return -ENODEV;
}
deb_i2c("status: %d, ", b[0]);
if (rx != NULL) {
memcpy(rx, &b[2], rxlen);
deb_i2c("rx (%d): ", rxlen);
debug_dump(rx, rxlen, deb_i2c);
}
deb_i2c("\n");
return 0;
}
static int technisat_usb2_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg *msg,
int num)
{
int ret = 0, i;
struct dvb_usb_device *d = i2c_get_adapdata(adap);
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
for (i = 0; i < num; i++) {
if (i+1 < num && msg[i+1].flags & I2C_M_RD) {
ret = technisat_usb2_i2c_access(d->udev, msg[i+1].addr,
msg[i].buf, msg[i].len,
msg[i+1].buf, msg[i+1].len);
if (ret != 0)
break;
i++;
} else {
ret = technisat_usb2_i2c_access(d->udev, msg[i].addr,
msg[i].buf, msg[i].len,
NULL, 0);
if (ret != 0)
break;
}
}
if (ret == 0)
ret = i;
mutex_unlock(&d->i2c_mutex);
return ret;
}
static u32 technisat_usb2_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int technisat_usb2_set_led(struct dvb_usb_device *d, int red, enum technisat_usb2_led_state state)
{
int ret;
u8 led[8] = {
red ? SET_RED_LED_VENDOR_REQUEST : SET_GREEN_LED_VENDOR_REQUEST,
0
};
if (disable_led_control && state != LED_OFF)
return 0;
switch (state) {
case LED_ON:
led[1] = 0x82;
break;
case LED_BLINK:
led[1] = 0x82;
if (red) {
led[2] = 0x02;
led[3] = 10;
led[4] = 10;
} else {
led[2] = 0xff;
led[3] = 50;
led[4] = 50;
}
led[5] = 1;
break;
default:
case LED_OFF:
led[1] = 0x80;
break;
}
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
ret = usb_control_msg(d->udev, usb_sndctrlpipe(d->udev, 0),
red ? SET_RED_LED_VENDOR_REQUEST : SET_GREEN_LED_VENDOR_REQUEST,
USB_TYPE_VENDOR | USB_DIR_OUT,
0, 0,
led, sizeof(led), 500);
mutex_unlock(&d->i2c_mutex);
return ret;
}
static int technisat_usb2_set_led_timer(struct dvb_usb_device *d, u8 red, u8 green)
{
int ret;
u8 b = 0;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
ret = usb_control_msg(d->udev, usb_sndctrlpipe(d->udev, 0),
SET_LED_TIMER_DIVIDER_VENDOR_REQUEST,
USB_TYPE_VENDOR | USB_DIR_OUT,
(red << 8) | green, 0,
&b, 1, 500);
mutex_unlock(&d->i2c_mutex);
return ret;
}
static void technisat_usb2_green_led_control(struct work_struct *work)
{
struct technisat_usb2_state *state =
container_of(work, struct technisat_usb2_state, green_led_work.work);
struct dvb_frontend *fe = state->dev->adapter[0].fe_adap[0].fe;
if (state->power_state == 0)
goto schedule;
if (fe != NULL) {
enum fe_status status;
if (fe->ops.read_status(fe, &status) != 0)
goto schedule;
if (status & FE_HAS_LOCK) {
u32 ber;
if (fe->ops.read_ber(fe, &ber) != 0)
goto schedule;
if (ber > 1000)
technisat_usb2_set_led(state->dev, 0, LED_BLINK);
else
technisat_usb2_set_led(state->dev, 0, LED_ON);
} else
technisat_usb2_set_led(state->dev, 0, LED_OFF);
}
schedule:
schedule_delayed_work(&state->green_led_work,
msecs_to_jiffies(500));
}
static int technisat_usb2_identify_state(struct usb_device *udev,
struct dvb_usb_device_properties *props,
struct dvb_usb_device_description **desc, int *cold)
{
int ret;
u8 version[3];
if (usb_set_interface(udev, 0, 1) != 0)
err("could not set alternate setting to 0");
else
info("set alternate setting");
*cold = 0;
ret = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
GET_VERSION_INFO_VENDOR_REQUEST,
USB_TYPE_VENDOR | USB_DIR_IN,
0, 0,
version, sizeof(version), 500);
if (ret < 0)
*cold = 1;
else {
info("firmware version: %d.%d", version[1], version[2]);
*cold = 0;
}
return 0;
}
static int technisat_usb2_power_ctrl(struct dvb_usb_device *d, int level)
{
struct technisat_usb2_state *state = d->priv;
state->power_state = level;
if (disable_led_control)
return 0;
technisat_usb2_set_led(d, 0, LED_OFF);
technisat_usb2_set_led(d, 1, LED_ON);
return 0;
}
static u8 technisat_usb2_calc_lrc(const u8 *b, u16 length)
{
u8 lrc = 0;
while (--length)
lrc ^= *b++;
return lrc;
}
static int technisat_usb2_eeprom_lrc_read(struct dvb_usb_device *d,
u16 offset, u8 *b, u16 length, u8 tries)
{
u8 bo = offset & 0xff;
struct i2c_msg msg[] = {
{
.addr = 0x50 | ((offset >> 8) & 0x3),
.buf = &bo,
.len = 1
}, {
.addr = 0x50 | ((offset >> 8) & 0x3),
.flags = I2C_M_RD,
.buf = b,
.len = length
}
};
while (tries--) {
int status;
if (i2c_transfer(&d->i2c_adap, msg, 2) != 2)
break;
status =
technisat_usb2_calc_lrc(b, length - 1) == b[length - 1];
if (status)
return 0;
}
return -EREMOTEIO;
}
static int technisat_usb2_read_mac_address(struct dvb_usb_device *d,
u8 mac[])
{
u8 buf[EEPROM_MAC_TOTAL];
if (technisat_usb2_eeprom_lrc_read(d, EEPROM_MAC_START,
buf, EEPROM_MAC_TOTAL, 4) != 0)
return -ENODEV;
memcpy(mac, buf, 6);
return 0;
}
static int technisat_usb2_set_voltage(struct dvb_frontend *fe,
fe_sec_voltage_t voltage)
{
int i;
u8 gpio[3] = { 0 };
gpio[2] = 1;
switch (voltage) {
case SEC_VOLTAGE_13:
gpio[0] = 1;
break;
case SEC_VOLTAGE_18:
gpio[0] = 1;
gpio[1] = 1;
break;
default:
case SEC_VOLTAGE_OFF:
break;
}
for (i = 0; i < 3; i++)
if (stv090x_set_gpio(fe, i+2, 0, gpio[i], 0) != 0)
return -EREMOTEIO;
return 0;
}
static int technisat_usb2_frontend_attach(struct dvb_usb_adapter *a)
{
struct usb_device *udev = a->dev->udev;
int ret;
a->fe_adap[0].fe = dvb_attach(stv090x_attach, &technisat_usb2_stv090x_config,
&a->dev->i2c_adap, STV090x_DEMODULATOR_0);
if (a->fe_adap[0].fe) {
struct stv6110x_devctl *ctl;
ctl = dvb_attach(stv6110x_attach,
a->fe_adap[0].fe,
&technisat_usb2_stv6110x_config,
&a->dev->i2c_adap);
if (ctl) {
technisat_usb2_stv090x_config.tuner_init = ctl->tuner_init;
technisat_usb2_stv090x_config.tuner_sleep = ctl->tuner_sleep;
technisat_usb2_stv090x_config.tuner_set_mode = ctl->tuner_set_mode;
technisat_usb2_stv090x_config.tuner_set_frequency = ctl->tuner_set_frequency;
technisat_usb2_stv090x_config.tuner_get_frequency = ctl->tuner_get_frequency;
technisat_usb2_stv090x_config.tuner_set_bandwidth = ctl->tuner_set_bandwidth;
technisat_usb2_stv090x_config.tuner_get_bandwidth = ctl->tuner_get_bandwidth;
technisat_usb2_stv090x_config.tuner_set_bbgain = ctl->tuner_set_bbgain;
technisat_usb2_stv090x_config.tuner_get_bbgain = ctl->tuner_get_bbgain;
technisat_usb2_stv090x_config.tuner_set_refclk = ctl->tuner_set_refclk;
technisat_usb2_stv090x_config.tuner_get_status = ctl->tuner_get_status;
if (a->fe_adap[0].fe->ops.init)
a->fe_adap[0].fe->ops.init(a->fe_adap[0].fe);
if (mutex_lock_interruptible(&a->dev->i2c_mutex) < 0)
return -EAGAIN;
ret = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
SET_IFCLK_TO_EXTERNAL_TSCLK_VENDOR_REQUEST,
USB_TYPE_VENDOR | USB_DIR_OUT,
0, 0,
NULL, 0, 500);
mutex_unlock(&a->dev->i2c_mutex);
if (ret != 0)
err("could not set IF_CLK to external");
a->fe_adap[0].fe->ops.set_voltage = technisat_usb2_set_voltage;
strlcpy(a->fe_adap[0].fe->ops.info.name, a->dev->desc->name,
sizeof(a->fe_adap[0].fe->ops.info.name));
} else {
dvb_frontend_detach(a->fe_adap[0].fe);
a->fe_adap[0].fe = NULL;
}
}
technisat_usb2_set_led_timer(a->dev, 1, 1);
return a->fe_adap[0].fe == NULL ? -ENODEV : 0;
}
static int technisat_usb2_get_ir(struct dvb_usb_device *d)
{
u8 buf[62], *b;
int ret;
struct ir_raw_event ev;
buf[0] = GET_IR_DATA_VENDOR_REQUEST;
buf[1] = 0x08;
buf[2] = 0x8f;
buf[3] = MINIMUM_IR_BIT_TRANSITION_TICK_COUNT;
buf[4] = MAXIMUM_IR_BIT_TIME_TICK_COUNT;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
ret = usb_control_msg(d->udev, usb_sndctrlpipe(d->udev, 0),
GET_IR_DATA_VENDOR_REQUEST,
USB_TYPE_VENDOR | USB_DIR_OUT,
0, 0,
buf, 5, 500);
if (ret < 0)
goto unlock;
buf[1] = 0;
buf[2] = 0;
ret = usb_control_msg(d->udev, usb_rcvctrlpipe(d->udev, 0),
GET_IR_DATA_VENDOR_REQUEST,
USB_TYPE_VENDOR | USB_DIR_IN,
0x8080, 0,
buf, sizeof(buf), 500);
unlock:
mutex_unlock(&d->i2c_mutex);
if (ret < 0)
return ret;
if (ret == 1)
return 0;
b = buf+1;
#if 0
deb_rc("RC: %d ", ret);
debug_dump(b, ret, deb_rc);
#endif
ev.pulse = 0;
while (1) {
ev.pulse = !ev.pulse;
ev.duration = (*b * FIRMWARE_CLOCK_DIVISOR * FIRMWARE_CLOCK_TICK) / 1000;
ir_raw_event_store(d->rc_dev, &ev);
b++;
if (*b == 0xff) {
ev.pulse = 0;
ev.duration = 888888*2;
ir_raw_event_store(d->rc_dev, &ev);
break;
}
}
ir_raw_event_handle(d->rc_dev);
return 1;
}
static int technisat_usb2_rc_query(struct dvb_usb_device *d)
{
int ret = technisat_usb2_get_ir(d);
if (ret < 0)
return ret;
if (ret == 0)
return 0;
if (!disable_led_control)
technisat_usb2_set_led(d, 1, LED_BLINK);
return 0;
}
static int technisat_usb2_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct dvb_usb_device *dev;
if (dvb_usb_device_init(intf, &technisat_usb2_devices, THIS_MODULE,
&dev, adapter_nr) != 0)
return -ENODEV;
if (dev) {
struct technisat_usb2_state *state = dev->priv;
state->dev = dev;
if (!disable_led_control) {
INIT_DELAYED_WORK(&state->green_led_work,
technisat_usb2_green_led_control);
schedule_delayed_work(&state->green_led_work,
msecs_to_jiffies(500));
}
}
return 0;
}
static void technisat_usb2_disconnect(struct usb_interface *intf)
{
struct dvb_usb_device *dev = usb_get_intfdata(intf);
if (dev != NULL) {
struct technisat_usb2_state *state = dev->priv;
if (state != NULL)
cancel_delayed_work_sync(&state->green_led_work);
}
dvb_usb_device_exit(intf);
}
