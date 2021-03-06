static int dw210x_op_rw(struct usb_device *dev, u8 request, u16 value,
u16 index, u8 * data, u16 len, int flags)
{
int ret;
u8 *u8buf;
unsigned int pipe = (flags == DW210X_READ_MSG) ?
usb_rcvctrlpipe(dev, 0) : usb_sndctrlpipe(dev, 0);
u8 request_type = (flags == DW210X_READ_MSG) ? USB_DIR_IN : USB_DIR_OUT;
u8buf = kmalloc(len, GFP_KERNEL);
if (!u8buf)
return -ENOMEM;
if (flags == DW210X_WRITE_MSG)
memcpy(u8buf, data, len);
ret = usb_control_msg(dev, pipe, request, request_type | USB_TYPE_VENDOR,
value, index , u8buf, len, 2000);
if (flags == DW210X_READ_MSG)
memcpy(data, u8buf, len);
kfree(u8buf);
return ret;
}
static int dw2102_i2c_transfer(struct i2c_adapter *adap, struct i2c_msg msg[],
int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
int i = 0, ret = 0;
u8 buf6[] = {0x2c, 0x05, 0xc0, 0, 0, 0, 0};
u16 value;
if (!d)
return -ENODEV;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
switch (num) {
case 2:
value = msg[0].buf[0];
for (i = 0; i < msg[1].len; i++) {
ret = dw210x_op_rw(d->udev, 0xb5, value + i, 0,
buf6, 2, DW210X_READ_MSG);
msg[1].buf[i] = buf6[0];
}
break;
case 1:
switch (msg[0].addr) {
case 0x68:
buf6[0] = 0x2a;
buf6[1] = msg[0].buf[0];
buf6[2] = msg[0].buf[1];
ret = dw210x_op_rw(d->udev, 0xb2, 0, 0,
buf6, 3, DW210X_WRITE_MSG);
break;
case 0x60:
if (msg[0].flags == 0) {
buf6[0] = 0x2c;
buf6[1] = 5;
buf6[2] = 0xc0;
buf6[3] = msg[0].buf[0];
buf6[4] = msg[0].buf[1];
buf6[5] = msg[0].buf[2];
buf6[6] = msg[0].buf[3];
ret = dw210x_op_rw(d->udev, 0xb2, 0, 0,
buf6, 7, DW210X_WRITE_MSG);
} else {
ret = dw210x_op_rw(d->udev, 0xb5, 0, 0,
buf6, 1, DW210X_READ_MSG);
msg[0].buf[0] = buf6[0];
}
break;
case (DW2102_RC_QUERY):
ret = dw210x_op_rw(d->udev, 0xb8, 0, 0,
buf6, 2, DW210X_READ_MSG);
msg[0].buf[0] = buf6[0];
msg[0].buf[1] = buf6[1];
break;
case (DW2102_VOLTAGE_CTRL):
buf6[0] = 0x30;
buf6[1] = msg[0].buf[0];
ret = dw210x_op_rw(d->udev, 0xb2, 0, 0,
buf6, 2, DW210X_WRITE_MSG);
break;
}
break;
}
mutex_unlock(&d->i2c_mutex);
return num;
}
static int dw2102_serit_i2c_transfer(struct i2c_adapter *adap,
struct i2c_msg msg[], int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
int ret = 0;
u8 buf6[] = {0, 0, 0, 0, 0, 0, 0};
if (!d)
return -ENODEV;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
switch (num) {
case 2:
buf6[0] = msg[0].addr << 1;
buf6[1] = msg[0].len;
buf6[2] = msg[0].buf[0];
ret = dw210x_op_rw(d->udev, 0xc2, 0, 0,
buf6, msg[0].len + 2, DW210X_WRITE_MSG);
ret = dw210x_op_rw(d->udev, 0xc3, 0xd0, 0,
buf6, msg[1].len + 2, DW210X_READ_MSG);
memcpy(msg[1].buf, buf6 + 2, msg[1].len);
break;
case 1:
switch (msg[0].addr) {
case 0x68:
buf6[0] = msg[0].addr << 1;
buf6[1] = msg[0].len;
memcpy(buf6 + 2, msg[0].buf, msg[0].len);
ret = dw210x_op_rw(d->udev, 0xc2, 0, 0, buf6,
msg[0].len + 2, DW210X_WRITE_MSG);
break;
case(DW2102_RC_QUERY):
ret = dw210x_op_rw(d->udev, 0xb8, 0, 0,
buf6, 2, DW210X_READ_MSG);
msg[0].buf[0] = buf6[0];
msg[0].buf[1] = buf6[1];
break;
case(DW2102_VOLTAGE_CTRL):
buf6[0] = 0x30;
buf6[1] = msg[0].buf[0];
ret = dw210x_op_rw(d->udev, 0xb2, 0, 0,
buf6, 2, DW210X_WRITE_MSG);
break;
}
break;
}
mutex_unlock(&d->i2c_mutex);
return num;
}
static int dw2102_earda_i2c_transfer(struct i2c_adapter *adap, struct i2c_msg msg[], int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
int ret = 0;
if (!d)
return -ENODEV;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
switch (num) {
case 2: {
u8 ibuf[msg[1].len + 2], obuf[3];
obuf[0] = msg[0].addr << 1;
obuf[1] = msg[0].len;
obuf[2] = msg[0].buf[0];
ret = dw210x_op_rw(d->udev, 0xc2, 0, 0,
obuf, msg[0].len + 2, DW210X_WRITE_MSG);
ret = dw210x_op_rw(d->udev, 0xc3, 0xd1 , 0,
ibuf, msg[1].len + 2, DW210X_READ_MSG);
memcpy(msg[1].buf, ibuf + 2, msg[1].len);
break;
}
case 1:
switch (msg[0].addr) {
case 0x68: {
u8 obuf[msg[0].len + 2];
obuf[0] = msg[0].addr << 1;
obuf[1] = msg[0].len;
memcpy(obuf + 2, msg[0].buf, msg[0].len);
ret = dw210x_op_rw(d->udev, 0xc2, 0, 0,
obuf, msg[0].len + 2, DW210X_WRITE_MSG);
break;
}
case 0x61: {
u8 obuf[msg[0].len + 2];
obuf[0] = msg[0].addr << 1;
obuf[1] = msg[0].len;
memcpy(obuf + 2, msg[0].buf, msg[0].len);
ret = dw210x_op_rw(d->udev, 0xc2, 0, 0,
obuf, msg[0].len + 2, DW210X_WRITE_MSG);
break;
}
case(DW2102_RC_QUERY): {
u8 ibuf[2];
ret = dw210x_op_rw(d->udev, 0xb8, 0, 0,
ibuf, 2, DW210X_READ_MSG);
memcpy(msg[0].buf, ibuf , 2);
break;
}
case(DW2102_VOLTAGE_CTRL): {
u8 obuf[2];
obuf[0] = 0x30;
obuf[1] = msg[0].buf[0];
ret = dw210x_op_rw(d->udev, 0xb2, 0, 0,
obuf, 2, DW210X_WRITE_MSG);
break;
}
}
break;
}
mutex_unlock(&d->i2c_mutex);
return num;
}
static int dw2104_i2c_transfer(struct i2c_adapter *adap, struct i2c_msg msg[], int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
int ret = 0;
int len, i, j;
if (!d)
return -ENODEV;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
for (j = 0; j < num; j++) {
switch (msg[j].addr) {
case(DW2102_RC_QUERY): {
u8 ibuf[2];
ret = dw210x_op_rw(d->udev, 0xb8, 0, 0,
ibuf, 2, DW210X_READ_MSG);
memcpy(msg[j].buf, ibuf , 2);
break;
}
case(DW2102_VOLTAGE_CTRL): {
u8 obuf[2];
obuf[0] = 0x30;
obuf[1] = msg[j].buf[0];
ret = dw210x_op_rw(d->udev, 0xb2, 0, 0,
obuf, 2, DW210X_WRITE_MSG);
break;
}
default: {
if (msg[j].flags == I2C_M_RD) {
u8 ibuf[msg[j].len + 2];
ret = dw210x_op_rw(d->udev, 0xc3,
(msg[j].addr << 1) + 1, 0,
ibuf, msg[j].len + 2,
DW210X_READ_MSG);
memcpy(msg[j].buf, ibuf + 2, msg[j].len);
mdelay(10);
} else if (((msg[j].buf[0] == 0xb0) &&
(msg[j].addr == 0x68)) ||
((msg[j].buf[0] == 0xf7) &&
(msg[j].addr == 0x55))) {
u8 obuf[19];
obuf[0] = msg[j].addr << 1;
obuf[1] = (msg[j].len > 15 ? 17 : msg[j].len);
obuf[2] = msg[j].buf[0];
len = msg[j].len - 1;
i = 1;
do {
memcpy(obuf + 3, msg[j].buf + i,
(len > 16 ? 16 : len));
ret = dw210x_op_rw(d->udev, 0xc2, 0, 0,
obuf, (len > 16 ? 16 : len) + 3,
DW210X_WRITE_MSG);
i += 16;
len -= 16;
} while (len > 0);
} else {
u8 obuf[msg[j].len + 2];
obuf[0] = msg[j].addr << 1;
obuf[1] = msg[j].len;
memcpy(obuf + 2, msg[j].buf, msg[j].len);
ret = dw210x_op_rw(d->udev, 0xc2, 0, 0,
obuf, msg[j].len + 2,
DW210X_WRITE_MSG);
}
break;
}
}
}
mutex_unlock(&d->i2c_mutex);
return num;
}
static int dw3101_i2c_transfer(struct i2c_adapter *adap, struct i2c_msg msg[],
int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
int ret = 0, i;
if (!d)
return -ENODEV;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
switch (num) {
case 2: {
u8 ibuf[msg[1].len + 2], obuf[3];
obuf[0] = msg[0].addr << 1;
obuf[1] = msg[0].len;
obuf[2] = msg[0].buf[0];
ret = dw210x_op_rw(d->udev, 0xc2, 0, 0,
obuf, msg[0].len + 2, DW210X_WRITE_MSG);
ret = dw210x_op_rw(d->udev, 0xc3, 0x19 , 0,
ibuf, msg[1].len + 2, DW210X_READ_MSG);
memcpy(msg[1].buf, ibuf + 2, msg[1].len);
break;
}
case 1:
switch (msg[0].addr) {
case 0x60:
case 0x0c: {
u8 obuf[msg[0].len + 2];
obuf[0] = msg[0].addr << 1;
obuf[1] = msg[0].len;
memcpy(obuf + 2, msg[0].buf, msg[0].len);
ret = dw210x_op_rw(d->udev, 0xc2, 0, 0,
obuf, msg[0].len + 2, DW210X_WRITE_MSG);
break;
}
case(DW2102_RC_QUERY): {
u8 ibuf[2];
ret = dw210x_op_rw(d->udev, 0xb8, 0, 0,
ibuf, 2, DW210X_READ_MSG);
memcpy(msg[0].buf, ibuf , 2);
break;
}
}
break;
}
for (i = 0; i < num; i++) {
deb_xfer("%02x:%02x: %s ", i, msg[i].addr,
msg[i].flags == 0 ? ">>>" : "<<<");
debug_dump(msg[i].buf, msg[i].len, deb_xfer);
}
mutex_unlock(&d->i2c_mutex);
return num;
}
static int s6x0_i2c_transfer(struct i2c_adapter *adap, struct i2c_msg msg[],
int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
struct usb_device *udev;
int ret = 0;
int len, i, j;
if (!d)
return -ENODEV;
udev = d->udev;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
for (j = 0; j < num; j++) {
switch (msg[j].addr) {
case (DW2102_RC_QUERY): {
u8 ibuf[5];
ret = dw210x_op_rw(d->udev, 0xb8, 0, 0,
ibuf, 5, DW210X_READ_MSG);
memcpy(msg[j].buf, ibuf + 3, 2);
break;
}
case (DW2102_VOLTAGE_CTRL): {
u8 obuf[2];
obuf[0] = 1;
obuf[1] = msg[j].buf[1];
ret = dw210x_op_rw(d->udev, 0x8a, 0, 0,
obuf, 2, DW210X_WRITE_MSG);
obuf[0] = 3;
obuf[1] = msg[j].buf[0];
ret = dw210x_op_rw(d->udev, 0x8a, 0, 0,
obuf, 2, DW210X_WRITE_MSG);
break;
}
case (DW2102_LED_CTRL): {
u8 obuf[2];
obuf[0] = 5;
obuf[1] = msg[j].buf[0];
ret = dw210x_op_rw(d->udev, 0x8a, 0, 0,
obuf, 2, DW210X_WRITE_MSG);
break;
}
default: {
if (msg[j].flags == I2C_M_RD) {
u8 ibuf[msg[j].len];
ret = dw210x_op_rw(d->udev, 0x91, 0, 0,
ibuf, msg[j].len,
DW210X_READ_MSG);
memcpy(msg[j].buf, ibuf, msg[j].len);
break;
} else if ((msg[j].buf[0] == 0xb0) &&
(msg[j].addr == 0x68)) {
u8 obuf[19];
obuf[0] = (msg[j].len > 16 ?
18 : msg[j].len + 1);
obuf[1] = msg[j].addr << 1;
obuf[2] = msg[j].buf[0];
len = msg[j].len - 1;
i = 1;
do {
memcpy(obuf + 3, msg[j].buf + i,
(len > 16 ? 16 : len));
ret = dw210x_op_rw(d->udev, 0x80, 0, 0,
obuf, (len > 16 ? 16 : len) + 3,
DW210X_WRITE_MSG);
i += 16;
len -= 16;
} while (len > 0);
} else if (j < (num - 1)) {
u8 obuf[msg[j].len + 2];
obuf[0] = msg[j + 1].len;
obuf[1] = (msg[j].addr << 1);
memcpy(obuf + 2, msg[j].buf, msg[j].len);
ret = dw210x_op_rw(d->udev,
udev->descriptor.idProduct ==
0x7500 ? 0x92 : 0x90, 0, 0,
obuf, msg[j].len + 2,
DW210X_WRITE_MSG);
break;
} else {
u8 obuf[msg[j].len + 2];
obuf[0] = msg[j].len + 1;
obuf[1] = (msg[j].addr << 1);
memcpy(obuf + 2, msg[j].buf, msg[j].len);
ret = dw210x_op_rw(d->udev, 0x80, 0, 0,
obuf, msg[j].len + 2,
DW210X_WRITE_MSG);
break;
}
break;
}
}
}
mutex_unlock(&d->i2c_mutex);
return num;
}
static int su3000_i2c_transfer(struct i2c_adapter *adap, struct i2c_msg msg[],
int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
u8 obuf[0x40], ibuf[0x40];
if (!d)
return -ENODEV;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
switch (num) {
case 1:
switch (msg[0].addr) {
case SU3000_STREAM_CTRL:
obuf[0] = msg[0].buf[0] + 0x36;
obuf[1] = 3;
obuf[2] = 0;
if (dvb_usb_generic_rw(d, obuf, 3, ibuf, 0, 0) < 0)
err("i2c transfer failed.");
break;
case DW2102_RC_QUERY:
obuf[0] = 0x10;
if (dvb_usb_generic_rw(d, obuf, 1, ibuf, 2, 0) < 0)
err("i2c transfer failed.");
msg[0].buf[1] = ibuf[0];
msg[0].buf[0] = ibuf[1];
break;
default:
obuf[0] = 0x08;
obuf[1] = msg[0].addr;
obuf[2] = msg[0].len;
memcpy(&obuf[3], msg[0].buf, msg[0].len);
if (dvb_usb_generic_rw(d, obuf, msg[0].len + 3,
ibuf, 1, 0) < 0)
err("i2c transfer failed.");
}
break;
case 2:
obuf[0] = 0x09;
obuf[1] = msg[0].len;
obuf[2] = msg[1].len;
obuf[3] = msg[0].addr;
memcpy(&obuf[4], msg[0].buf, msg[0].len);
if (dvb_usb_generic_rw(d, obuf, msg[0].len + 4,
ibuf, msg[1].len + 1, 0) < 0)
err("i2c transfer failed.");
memcpy(msg[1].buf, &ibuf[1], msg[1].len);
break;
default:
warn("more than 2 i2c messages at a time is not handled yet.");
break;
}
mutex_unlock(&d->i2c_mutex);
return num;
}
static u32 dw210x_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int dw210x_read_mac_address(struct dvb_usb_device *d, u8 mac[6])
{
int i;
u8 ibuf[] = {0, 0};
u8 eeprom[256], eepromline[16];
for (i = 0; i < 256; i++) {
if (dw210x_op_rw(d->udev, 0xb6, 0xa0 , i, ibuf, 2, DW210X_READ_MSG) < 0) {
err("read eeprom failed.");
return -1;
} else {
eepromline[i%16] = ibuf[0];
eeprom[i] = ibuf[0];
}
if ((i % 16) == 15) {
deb_xfer("%02x: ", i - 15);
debug_dump(eepromline, 16, deb_xfer);
}
}
memcpy(mac, eeprom + 8, 6);
return 0;
}
static int s6x0_read_mac_address(struct dvb_usb_device *d, u8 mac[6])
{
int i, ret;
u8 ibuf[] = { 0 }, obuf[] = { 0 };
u8 eeprom[256], eepromline[16];
struct i2c_msg msg[] = {
{
.addr = 0xa0 >> 1,
.flags = 0,
.buf = obuf,
.len = 1,
}, {
.addr = 0xa0 >> 1,
.flags = I2C_M_RD,
.buf = ibuf,
.len = 1,
}
};
for (i = 0; i < 256; i++) {
obuf[0] = i;
ret = s6x0_i2c_transfer(&d->i2c_adap, msg, 2);
if (ret != 2) {
err("read eeprom failed.");
return -1;
} else {
eepromline[i % 16] = ibuf[0];
eeprom[i] = ibuf[0];
}
if ((i % 16) == 15) {
deb_xfer("%02x: ", i - 15);
debug_dump(eepromline, 16, deb_xfer);
}
}
memcpy(mac, eeprom + 16, 6);
return 0;
}
static int su3000_streaming_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
static u8 command_start[] = {0x00};
static u8 command_stop[] = {0x01};
struct i2c_msg msg = {
.addr = SU3000_STREAM_CTRL,
.flags = 0,
.buf = onoff ? command_start : command_stop,
.len = 1
};
i2c_transfer(&adap->dev->i2c_adap, &msg, 1);
return 0;
}
static int su3000_power_ctrl(struct dvb_usb_device *d, int i)
{
struct su3000_state *state = (struct su3000_state *)d->priv;
u8 obuf[] = {0xde, 0};
info("%s: %d, initialized %d\n", __func__, i, state->initialized);
if (i && !state->initialized) {
state->initialized = 1;
dvb_usb_generic_rw(d, obuf, 2, NULL, 0, 0);
}
return 0;
}
static int su3000_read_mac_address(struct dvb_usb_device *d, u8 mac[6])
{
int i;
u8 obuf[] = { 0x1f, 0xf0 };
u8 ibuf[] = { 0 };
struct i2c_msg msg[] = {
{
.addr = 0x51,
.flags = 0,
.buf = obuf,
.len = 2,
}, {
.addr = 0x51,
.flags = I2C_M_RD,
.buf = ibuf,
.len = 1,
}
};
for (i = 0; i < 6; i++) {
obuf[1] = 0xf0 + i;
if (i2c_transfer(&d->i2c_adap, msg, 2) != 2)
break;
else
mac[i] = ibuf[0];
debug_dump(mac, 6, printk);
}
return 0;
}
static int su3000_identify_state(struct usb_device *udev,
struct dvb_usb_device_properties *props,
struct dvb_usb_device_description **desc,
int *cold)
{
info("%s\n", __func__);
*cold = 0;
return 0;
}
static int dw210x_set_voltage(struct dvb_frontend *fe, fe_sec_voltage_t voltage)
{
static u8 command_13v[] = {0x00, 0x01};
static u8 command_18v[] = {0x01, 0x01};
static u8 command_off[] = {0x00, 0x00};
struct i2c_msg msg = {
.addr = DW2102_VOLTAGE_CTRL,
.flags = 0,
.buf = command_off,
.len = 2,
};
struct dvb_usb_adapter *udev_adap =
(struct dvb_usb_adapter *)(fe->dvb->priv);
if (voltage == SEC_VOLTAGE_18)
msg.buf = command_18v;
else if (voltage == SEC_VOLTAGE_13)
msg.buf = command_13v;
i2c_transfer(&udev_adap->dev->i2c_adap, &msg, 1);
return 0;
}
static int s660_set_voltage(struct dvb_frontend *fe, fe_sec_voltage_t voltage)
{
struct dvb_usb_adapter *d =
(struct dvb_usb_adapter *)(fe->dvb->priv);
struct s6x0_state *st = (struct s6x0_state *)d->dev->priv;
dw210x_set_voltage(fe, voltage);
if (st->old_set_voltage)
st->old_set_voltage(fe, voltage);
return 0;
}
static void dw210x_led_ctrl(struct dvb_frontend *fe, int offon)
{
static u8 led_off[] = { 0 };
static u8 led_on[] = { 1 };
struct i2c_msg msg = {
.addr = DW2102_LED_CTRL,
.flags = 0,
.buf = led_off,
.len = 1
};
struct dvb_usb_adapter *udev_adap =
(struct dvb_usb_adapter *)(fe->dvb->priv);
if (offon)
msg.buf = led_on;
i2c_transfer(&udev_adap->dev->i2c_adap, &msg, 1);
}
static int dw2104_frontend_attach(struct dvb_usb_adapter *d)
{
struct dvb_tuner_ops *tuner_ops = NULL;
if (demod_probe & 4) {
d->fe = dvb_attach(stv0900_attach, &dw2104a_stv0900_config,
&d->dev->i2c_adap, 0);
if (d->fe != NULL) {
if (dvb_attach(stb6100_attach, d->fe,
&dw2104a_stb6100_config,
&d->dev->i2c_adap)) {
tuner_ops = &d->fe->ops.tuner_ops;
tuner_ops->set_frequency = stb6100_set_freq;
tuner_ops->get_frequency = stb6100_get_freq;
tuner_ops->set_bandwidth = stb6100_set_bandw;
tuner_ops->get_bandwidth = stb6100_get_bandw;
d->fe->ops.set_voltage = dw210x_set_voltage;
info("Attached STV0900+STB6100!\n");
return 0;
}
}
}
if (demod_probe & 2) {
d->fe = dvb_attach(stv0900_attach, &dw2104_stv0900_config,
&d->dev->i2c_adap, 0);
if (d->fe != NULL) {
if (dvb_attach(stv6110_attach, d->fe,
&dw2104_stv6110_config,
&d->dev->i2c_adap)) {
d->fe->ops.set_voltage = dw210x_set_voltage;
info("Attached STV0900+STV6110A!\n");
return 0;
}
}
}
if (demod_probe & 1) {
d->fe = dvb_attach(cx24116_attach, &dw2104_config,
&d->dev->i2c_adap);
if (d->fe != NULL) {
d->fe->ops.set_voltage = dw210x_set_voltage;
info("Attached cx24116!\n");
return 0;
}
}
d->fe = dvb_attach(ds3000_attach, &dw2104_ds3000_config,
&d->dev->i2c_adap);
if (d->fe != NULL) {
d->fe->ops.set_voltage = dw210x_set_voltage;
info("Attached DS3000!\n");
return 0;
}
return -EIO;
}
static int dw2102_frontend_attach(struct dvb_usb_adapter *d)
{
if (dw2102_properties.i2c_algo == &dw2102_serit_i2c_algo) {
d->fe = dvb_attach(si21xx_attach, &serit_sp1511lhb_config,
&d->dev->i2c_adap);
if (d->fe != NULL) {
d->fe->ops.set_voltage = dw210x_set_voltage;
info("Attached si21xx!\n");
return 0;
}
}
if (dw2102_properties.i2c_algo == &dw2102_earda_i2c_algo) {
d->fe = dvb_attach(stv0288_attach, &earda_config,
&d->dev->i2c_adap);
if (d->fe != NULL) {
if (dvb_attach(stb6000_attach, d->fe, 0x61,
&d->dev->i2c_adap)) {
d->fe->ops.set_voltage = dw210x_set_voltage;
info("Attached stv0288!\n");
return 0;
}
}
}
if (dw2102_properties.i2c_algo == &dw2102_i2c_algo) {
d->fe = dvb_attach(stv0299_attach, &sharp_z0194a_config,
&d->dev->i2c_adap);
if (d->fe != NULL) {
d->fe->ops.set_voltage = dw210x_set_voltage;
info("Attached stv0299!\n");
return 0;
}
}
return -EIO;
}
static int dw3101_frontend_attach(struct dvb_usb_adapter *d)
{
d->fe = dvb_attach(tda10023_attach, &dw3101_tda10023_config,
&d->dev->i2c_adap, 0x48);
if (d->fe != NULL) {
info("Attached tda10023!\n");
return 0;
}
return -EIO;
}
static int zl100313_frontend_attach(struct dvb_usb_adapter *d)
{
d->fe = dvb_attach(mt312_attach, &zl313_config,
&d->dev->i2c_adap);
if (d->fe != NULL) {
if (dvb_attach(zl10039_attach, d->fe, 0x60,
&d->dev->i2c_adap)) {
d->fe->ops.set_voltage = dw210x_set_voltage;
info("Attached zl100313+zl10039!\n");
return 0;
}
}
return -EIO;
}
static int stv0288_frontend_attach(struct dvb_usb_adapter *d)
{
u8 obuf[] = {7, 1};
d->fe = dvb_attach(stv0288_attach, &earda_config,
&d->dev->i2c_adap);
if (d->fe == NULL)
return -EIO;
if (NULL == dvb_attach(stb6000_attach, d->fe, 0x61, &d->dev->i2c_adap))
return -EIO;
d->fe->ops.set_voltage = dw210x_set_voltage;
dw210x_op_rw(d->dev->udev, 0x8a, 0, 0, obuf, 2, DW210X_WRITE_MSG);
info("Attached stv0288+stb6000!\n");
return 0;
}
static int ds3000_frontend_attach(struct dvb_usb_adapter *d)
{
struct s6x0_state *st = (struct s6x0_state *)d->dev->priv;
u8 obuf[] = {7, 1};
d->fe = dvb_attach(ds3000_attach, &dw2104_ds3000_config,
&d->dev->i2c_adap);
if (d->fe == NULL)
return -EIO;
st->old_set_voltage = d->fe->ops.set_voltage;
d->fe->ops.set_voltage = s660_set_voltage;
dw210x_op_rw(d->dev->udev, 0x8a, 0, 0, obuf, 2, DW210X_WRITE_MSG);
info("Attached ds3000+ds2020!\n");
return 0;
}
static int prof_7500_frontend_attach(struct dvb_usb_adapter *d)
{
u8 obuf[] = {7, 1};
d->fe = dvb_attach(stv0900_attach, &prof_7500_stv0900_config,
&d->dev->i2c_adap, 0);
if (d->fe == NULL)
return -EIO;
d->fe->ops.set_voltage = dw210x_set_voltage;
dw210x_op_rw(d->dev->udev, 0x8a, 0, 0, obuf, 2, DW210X_WRITE_MSG);
info("Attached STV0900+STB6100A!\n");
return 0;
}
static int su3000_frontend_attach(struct dvb_usb_adapter *d)
{
u8 obuf[3] = { 0xe, 0x80, 0 };
u8 ibuf[] = { 0 };
if (dvb_usb_generic_rw(d->dev, obuf, 3, ibuf, 1, 0) < 0)
err("command 0x0e transfer failed.");
obuf[0] = 0xe;
obuf[1] = 0x83;
obuf[2] = 0;
if (dvb_usb_generic_rw(d->dev, obuf, 3, ibuf, 1, 0) < 0)
err("command 0x0e transfer failed.");
obuf[0] = 0xe;
obuf[1] = 0x83;
obuf[2] = 1;
if (dvb_usb_generic_rw(d->dev, obuf, 3, ibuf, 1, 0) < 0)
err("command 0x0e transfer failed.");
obuf[0] = 0x51;
if (dvb_usb_generic_rw(d->dev, obuf, 1, ibuf, 1, 0) < 0)
err("command 0x51 transfer failed.");
d->fe = dvb_attach(ds3000_attach, &su3000_ds3000_config,
&d->dev->i2c_adap);
if (d->fe == NULL)
return -EIO;
info("Attached DS3000!\n");
return 0;
}
static int dw2102_tuner_attach(struct dvb_usb_adapter *adap)
{
dvb_attach(dvb_pll_attach, adap->fe, 0x60,
&adap->dev->i2c_adap, DVB_PLL_OPERA1);
return 0;
}
static int dw3101_tuner_attach(struct dvb_usb_adapter *adap)
{
dvb_attach(dvb_pll_attach, adap->fe, 0x60,
&adap->dev->i2c_adap, DVB_PLL_TUA6034);
return 0;
}
static int dw2102_rc_query(struct dvb_usb_device *d, u32 *event, int *state)
{
struct rc_map_table *keymap = d->props.rc.legacy.rc_map_table;
int keymap_size = d->props.rc.legacy.rc_map_size;
u8 key[2];
struct i2c_msg msg = {
.addr = DW2102_RC_QUERY,
.flags = I2C_M_RD,
.buf = key,
.len = 2
};
int i;
if ((ir_keymap > 0) && (ir_keymap <= ARRAY_SIZE(keys_tables))) {
keymap = keys_tables[ir_keymap - 1].rc_keys ;
keymap_size = keys_tables[ir_keymap - 1].rc_keys_size;
} else if (ir_keymap > ARRAY_SIZE(keys_tables))
return 0;
*state = REMOTE_NO_KEY_PRESSED;
if (d->props.i2c_algo->master_xfer(&d->i2c_adap, &msg, 1) == 1) {
for (i = 0; i < keymap_size ; i++) {
if (rc5_data(&keymap[i]) == msg.buf[0]) {
*state = REMOTE_KEY_PRESSED;
*event = keymap[i].keycode;
break;
}
}
if ((*state) == REMOTE_KEY_PRESSED)
deb_rc("%s: found rc key: %x, %x, event: %x\n",
__func__, key[0], key[1], (*event));
else if (key[0] != 0xff)
deb_rc("%s: unknown rc key: %x, %x\n",
__func__, key[0], key[1]);
}
return 0;
}
static int dw2102_load_firmware(struct usb_device *dev,
const struct firmware *frmwr)
{
u8 *b, *p;
int ret = 0, i;
u8 reset;
u8 reset16[] = {0, 0, 0, 0, 0, 0, 0};
const struct firmware *fw;
const char *fw_2101 = "dvb-usb-dw2101.fw";
switch (dev->descriptor.idProduct) {
case 0x2101:
ret = request_firmware(&fw, fw_2101, &dev->dev);
if (ret != 0) {
err(err_str, fw_2101);
return ret;
}
break;
default:
fw = frmwr;
break;
}
info("start downloading DW210X firmware");
p = kmalloc(fw->size, GFP_KERNEL);
reset = 1;
dw210x_op_rw(dev, 0xa0, 0x7f92, 0, &reset, 1, DW210X_WRITE_MSG);
dw210x_op_rw(dev, 0xa0, 0xe600, 0, &reset, 1, DW210X_WRITE_MSG);
if (p != NULL) {
memcpy(p, fw->data, fw->size);
for (i = 0; i < fw->size; i += 0x40) {
b = (u8 *) p + i;
if (dw210x_op_rw(dev, 0xa0, i, 0, b , 0x40,
DW210X_WRITE_MSG) != 0x40) {
err("error while transferring firmware");
ret = -EINVAL;
break;
}
}
reset = 0;
if (ret || dw210x_op_rw(dev, 0xa0, 0x7f92, 0, &reset, 1,
DW210X_WRITE_MSG) != 1) {
err("could not restart the USB controller CPU.");
ret = -EINVAL;
}
if (ret || dw210x_op_rw(dev, 0xa0, 0xe600, 0, &reset, 1,
DW210X_WRITE_MSG) != 1) {
err("could not restart the USB controller CPU.");
ret = -EINVAL;
}
switch (dev->descriptor.idProduct) {
case USB_PID_TEVII_S650:
dw2104_properties.rc.legacy.rc_map_table = rc_map_tevii_table;
dw2104_properties.rc.legacy.rc_map_size =
ARRAY_SIZE(rc_map_tevii_table);
case USB_PID_DW2104:
reset = 1;
dw210x_op_rw(dev, 0xc4, 0x0000, 0, &reset, 1,
DW210X_WRITE_MSG);
case USB_PID_DW3101:
reset = 0;
dw210x_op_rw(dev, 0xbf, 0x0040, 0, &reset, 0,
DW210X_WRITE_MSG);
break;
case USB_PID_CINERGY_S:
case USB_PID_DW2102:
dw210x_op_rw(dev, 0xbf, 0x0040, 0, &reset, 0,
DW210X_WRITE_MSG);
dw210x_op_rw(dev, 0xb9, 0x0000, 0, &reset16[0], 2,
DW210X_READ_MSG);
dw210x_op_rw(dev, 0xb5, 0, 0, &reset16[0], 2,
DW210X_READ_MSG);
if ((reset16[0] == 0xa1) || (reset16[0] == 0x80)) {
dw2102_properties.i2c_algo = &dw2102_i2c_algo;
dw2102_properties.adapter->tuner_attach = &dw2102_tuner_attach;
break;
} else {
reset16[0] = 0xd0;
reset16[1] = 1;
reset16[2] = 0;
dw210x_op_rw(dev, 0xc2, 0, 0, &reset16[0], 3,
DW210X_WRITE_MSG);
dw210x_op_rw(dev, 0xc3, 0xd1, 0, &reset16[0], 3,
DW210X_READ_MSG);
if (reset16[2] == 0x11) {
dw2102_properties.i2c_algo = &dw2102_earda_i2c_algo;
break;
}
}
case 0x2101:
dw210x_op_rw(dev, 0xbc, 0x0030, 0, &reset16[0], 2,
DW210X_READ_MSG);
dw210x_op_rw(dev, 0xba, 0x0000, 0, &reset16[0], 7,
DW210X_READ_MSG);
dw210x_op_rw(dev, 0xba, 0x0000, 0, &reset16[0], 7,
DW210X_READ_MSG);
dw210x_op_rw(dev, 0xb9, 0x0000, 0, &reset16[0], 2,
DW210X_READ_MSG);
break;
}
msleep(100);
kfree(p);
}
return ret;
}
static int dw2102_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
p1100 = kzalloc(sizeof(struct dvb_usb_device_properties), GFP_KERNEL);
if (!p1100)
return -ENOMEM;
memcpy(p1100, &s6x0_properties,
sizeof(struct dvb_usb_device_properties));
p1100->firmware = "dvb-usb-p1100.fw";
p1100->devices[0] = d1100;
p1100->rc.legacy.rc_map_table = rc_map_tbs_table;
p1100->rc.legacy.rc_map_size = ARRAY_SIZE(rc_map_tbs_table);
p1100->adapter->frontend_attach = stv0288_frontend_attach;
s660 = kzalloc(sizeof(struct dvb_usb_device_properties), GFP_KERNEL);
if (!s660) {
kfree(p1100);
return -ENOMEM;
}
memcpy(s660, &s6x0_properties,
sizeof(struct dvb_usb_device_properties));
s660->firmware = "dvb-usb-s660.fw";
s660->num_device_descs = 3;
s660->devices[0] = d660;
s660->devices[1] = d480_1;
s660->devices[2] = d480_2;
s660->adapter->frontend_attach = ds3000_frontend_attach;
p7500 = kzalloc(sizeof(struct dvb_usb_device_properties), GFP_KERNEL);
if (!p7500) {
kfree(p1100);
kfree(s660);
return -ENOMEM;
}
memcpy(p7500, &s6x0_properties,
sizeof(struct dvb_usb_device_properties));
p7500->firmware = "dvb-usb-p7500.fw";
p7500->devices[0] = d7500;
p7500->rc.legacy.rc_map_table = rc_map_tbs_table;
p7500->rc.legacy.rc_map_size = ARRAY_SIZE(rc_map_tbs_table);
p7500->adapter->frontend_attach = prof_7500_frontend_attach;
if (0 == dvb_usb_device_init(intf, &dw2102_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &dw2104_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &dw3101_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &s6x0_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, p1100,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, s660,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, p7500,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &su3000_properties,
THIS_MODULE, NULL, adapter_nr))
return 0;
return -ENODEV;
}
static int __init dw2102_module_init(void)
{
int ret = usb_register(&dw2102_driver);
if (ret)
err("usb_register failed. Error number %d", ret);
return ret;
}
static void __exit dw2102_module_exit(void)
{
usb_deregister(&dw2102_driver);
}
