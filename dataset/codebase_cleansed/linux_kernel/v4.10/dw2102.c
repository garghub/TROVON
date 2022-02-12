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
int i = 0;
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
dw210x_op_rw(d->udev, 0xb5, value + i, 0,
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
dw210x_op_rw(d->udev, 0xb2, 0, 0,
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
dw210x_op_rw(d->udev, 0xb2, 0, 0,
buf6, 7, DW210X_WRITE_MSG);
} else {
dw210x_op_rw(d->udev, 0xb5, 0, 0,
buf6, 1, DW210X_READ_MSG);
msg[0].buf[0] = buf6[0];
}
break;
case (DW2102_RC_QUERY):
dw210x_op_rw(d->udev, 0xb8, 0, 0,
buf6, 2, DW210X_READ_MSG);
msg[0].buf[0] = buf6[0];
msg[0].buf[1] = buf6[1];
break;
case (DW2102_VOLTAGE_CTRL):
buf6[0] = 0x30;
buf6[1] = msg[0].buf[0];
dw210x_op_rw(d->udev, 0xb2, 0, 0,
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
dw210x_op_rw(d->udev, 0xc2, 0, 0,
buf6, msg[0].len + 2, DW210X_WRITE_MSG);
dw210x_op_rw(d->udev, 0xc3, 0xd0, 0,
buf6, msg[1].len + 2, DW210X_READ_MSG);
memcpy(msg[1].buf, buf6 + 2, msg[1].len);
break;
case 1:
switch (msg[0].addr) {
case 0x68:
buf6[0] = msg[0].addr << 1;
buf6[1] = msg[0].len;
memcpy(buf6 + 2, msg[0].buf, msg[0].len);
dw210x_op_rw(d->udev, 0xc2, 0, 0, buf6,
msg[0].len + 2, DW210X_WRITE_MSG);
break;
case(DW2102_RC_QUERY):
dw210x_op_rw(d->udev, 0xb8, 0, 0,
buf6, 2, DW210X_READ_MSG);
msg[0].buf[0] = buf6[0];
msg[0].buf[1] = buf6[1];
break;
case(DW2102_VOLTAGE_CTRL):
buf6[0] = 0x30;
buf6[1] = msg[0].buf[0];
dw210x_op_rw(d->udev, 0xb2, 0, 0,
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
int ret;
if (!d)
return -ENODEV;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
switch (num) {
case 2: {
u8 ibuf[MAX_XFER_SIZE], obuf[3];
if (2 + msg[1].len > sizeof(ibuf)) {
warn("i2c rd: len=%d is too big!\n",
msg[1].len);
ret = -EOPNOTSUPP;
goto unlock;
}
obuf[0] = msg[0].addr << 1;
obuf[1] = msg[0].len;
obuf[2] = msg[0].buf[0];
dw210x_op_rw(d->udev, 0xc2, 0, 0,
obuf, msg[0].len + 2, DW210X_WRITE_MSG);
dw210x_op_rw(d->udev, 0xc3, 0xd1 , 0,
ibuf, msg[1].len + 2, DW210X_READ_MSG);
memcpy(msg[1].buf, ibuf + 2, msg[1].len);
break;
}
case 1:
switch (msg[0].addr) {
case 0x68: {
u8 obuf[MAX_XFER_SIZE];
if (2 + msg[0].len > sizeof(obuf)) {
warn("i2c wr: len=%d is too big!\n",
msg[1].len);
ret = -EOPNOTSUPP;
goto unlock;
}
obuf[0] = msg[0].addr << 1;
obuf[1] = msg[0].len;
memcpy(obuf + 2, msg[0].buf, msg[0].len);
dw210x_op_rw(d->udev, 0xc2, 0, 0,
obuf, msg[0].len + 2, DW210X_WRITE_MSG);
break;
}
case 0x61: {
u8 obuf[MAX_XFER_SIZE];
if (2 + msg[0].len > sizeof(obuf)) {
warn("i2c wr: len=%d is too big!\n",
msg[1].len);
ret = -EOPNOTSUPP;
goto unlock;
}
obuf[0] = msg[0].addr << 1;
obuf[1] = msg[0].len;
memcpy(obuf + 2, msg[0].buf, msg[0].len);
dw210x_op_rw(d->udev, 0xc2, 0, 0,
obuf, msg[0].len + 2, DW210X_WRITE_MSG);
break;
}
case(DW2102_RC_QUERY): {
u8 ibuf[2];
dw210x_op_rw(d->udev, 0xb8, 0, 0,
ibuf, 2, DW210X_READ_MSG);
memcpy(msg[0].buf, ibuf , 2);
break;
}
case(DW2102_VOLTAGE_CTRL): {
u8 obuf[2];
obuf[0] = 0x30;
obuf[1] = msg[0].buf[0];
dw210x_op_rw(d->udev, 0xb2, 0, 0,
obuf, 2, DW210X_WRITE_MSG);
break;
}
}
break;
}
ret = num;
unlock:
mutex_unlock(&d->i2c_mutex);
return ret;
}
static int dw2104_i2c_transfer(struct i2c_adapter *adap, struct i2c_msg msg[], int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
int len, i, j, ret;
if (!d)
return -ENODEV;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
for (j = 0; j < num; j++) {
switch (msg[j].addr) {
case(DW2102_RC_QUERY): {
u8 ibuf[2];
dw210x_op_rw(d->udev, 0xb8, 0, 0,
ibuf, 2, DW210X_READ_MSG);
memcpy(msg[j].buf, ibuf , 2);
break;
}
case(DW2102_VOLTAGE_CTRL): {
u8 obuf[2];
obuf[0] = 0x30;
obuf[1] = msg[j].buf[0];
dw210x_op_rw(d->udev, 0xb2, 0, 0,
obuf, 2, DW210X_WRITE_MSG);
break;
}
default: {
if (msg[j].flags == I2C_M_RD) {
u8 ibuf[MAX_XFER_SIZE];
if (2 + msg[j].len > sizeof(ibuf)) {
warn("i2c rd: len=%d is too big!\n",
msg[j].len);
ret = -EOPNOTSUPP;
goto unlock;
}
dw210x_op_rw(d->udev, 0xc3,
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
dw210x_op_rw(d->udev, 0xc2, 0, 0,
obuf, (len > 16 ? 16 : len) + 3,
DW210X_WRITE_MSG);
i += 16;
len -= 16;
} while (len > 0);
} else {
u8 obuf[MAX_XFER_SIZE];
if (2 + msg[j].len > sizeof(obuf)) {
warn("i2c wr: len=%d is too big!\n",
msg[j].len);
ret = -EOPNOTSUPP;
goto unlock;
}
obuf[0] = msg[j].addr << 1;
obuf[1] = msg[j].len;
memcpy(obuf + 2, msg[j].buf, msg[j].len);
dw210x_op_rw(d->udev, 0xc2, 0, 0,
obuf, msg[j].len + 2,
DW210X_WRITE_MSG);
}
break;
}
}
}
ret = num;
unlock:
mutex_unlock(&d->i2c_mutex);
return ret;
}
static int dw3101_i2c_transfer(struct i2c_adapter *adap, struct i2c_msg msg[],
int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
int ret;
int i;
if (!d)
return -ENODEV;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
switch (num) {
case 2: {
u8 ibuf[MAX_XFER_SIZE], obuf[3];
if (2 + msg[1].len > sizeof(ibuf)) {
warn("i2c rd: len=%d is too big!\n",
msg[1].len);
ret = -EOPNOTSUPP;
goto unlock;
}
obuf[0] = msg[0].addr << 1;
obuf[1] = msg[0].len;
obuf[2] = msg[0].buf[0];
dw210x_op_rw(d->udev, 0xc2, 0, 0,
obuf, msg[0].len + 2, DW210X_WRITE_MSG);
dw210x_op_rw(d->udev, 0xc3, 0x19 , 0,
ibuf, msg[1].len + 2, DW210X_READ_MSG);
memcpy(msg[1].buf, ibuf + 2, msg[1].len);
break;
}
case 1:
switch (msg[0].addr) {
case 0x60:
case 0x0c: {
u8 obuf[MAX_XFER_SIZE];
if (2 + msg[0].len > sizeof(obuf)) {
warn("i2c wr: len=%d is too big!\n",
msg[0].len);
ret = -EOPNOTSUPP;
goto unlock;
}
obuf[0] = msg[0].addr << 1;
obuf[1] = msg[0].len;
memcpy(obuf + 2, msg[0].buf, msg[0].len);
dw210x_op_rw(d->udev, 0xc2, 0, 0,
obuf, msg[0].len + 2, DW210X_WRITE_MSG);
break;
}
case(DW2102_RC_QUERY): {
u8 ibuf[2];
dw210x_op_rw(d->udev, 0xb8, 0, 0,
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
ret = num;
unlock:
mutex_unlock(&d->i2c_mutex);
return ret;
}
static int s6x0_i2c_transfer(struct i2c_adapter *adap, struct i2c_msg msg[],
int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
struct usb_device *udev;
int len, i, j, ret;
if (!d)
return -ENODEV;
udev = d->udev;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
for (j = 0; j < num; j++) {
switch (msg[j].addr) {
case (DW2102_RC_QUERY): {
u8 ibuf[5];
dw210x_op_rw(d->udev, 0xb8, 0, 0,
ibuf, 5, DW210X_READ_MSG);
memcpy(msg[j].buf, ibuf + 3, 2);
break;
}
case (DW2102_VOLTAGE_CTRL): {
u8 obuf[2];
obuf[0] = 1;
obuf[1] = msg[j].buf[1];
dw210x_op_rw(d->udev, 0x8a, 0, 0,
obuf, 2, DW210X_WRITE_MSG);
obuf[0] = 3;
obuf[1] = msg[j].buf[0];
dw210x_op_rw(d->udev, 0x8a, 0, 0,
obuf, 2, DW210X_WRITE_MSG);
break;
}
case (DW2102_LED_CTRL): {
u8 obuf[2];
obuf[0] = 5;
obuf[1] = msg[j].buf[0];
dw210x_op_rw(d->udev, 0x8a, 0, 0,
obuf, 2, DW210X_WRITE_MSG);
break;
}
default: {
if (msg[j].flags == I2C_M_RD) {
u8 ibuf[MAX_XFER_SIZE];
if (msg[j].len > sizeof(ibuf)) {
warn("i2c rd: len=%d is too big!\n",
msg[j].len);
ret = -EOPNOTSUPP;
goto unlock;
}
dw210x_op_rw(d->udev, 0x91, 0, 0,
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
dw210x_op_rw(d->udev, 0x80, 0, 0,
obuf, (len > 16 ? 16 : len) + 3,
DW210X_WRITE_MSG);
i += 16;
len -= 16;
} while (len > 0);
} else if (j < (num - 1)) {
u8 obuf[MAX_XFER_SIZE];
if (2 + msg[j].len > sizeof(obuf)) {
warn("i2c wr: len=%d is too big!\n",
msg[j].len);
ret = -EOPNOTSUPP;
goto unlock;
}
obuf[0] = msg[j + 1].len;
obuf[1] = (msg[j].addr << 1);
memcpy(obuf + 2, msg[j].buf, msg[j].len);
dw210x_op_rw(d->udev,
le16_to_cpu(udev->descriptor.idProduct) ==
0x7500 ? 0x92 : 0x90, 0, 0,
obuf, msg[j].len + 2,
DW210X_WRITE_MSG);
break;
} else {
u8 obuf[MAX_XFER_SIZE];
if (2 + msg[j].len > sizeof(obuf)) {
warn("i2c wr: len=%d is too big!\n",
msg[j].len);
ret = -EOPNOTSUPP;
goto unlock;
}
obuf[0] = msg[j].len + 1;
obuf[1] = (msg[j].addr << 1);
memcpy(obuf + 2, msg[j].buf, msg[j].len);
dw210x_op_rw(d->udev, 0x80, 0, 0,
obuf, msg[j].len + 2,
DW210X_WRITE_MSG);
break;
}
break;
}
}
}
ret = num;
unlock:
mutex_unlock(&d->i2c_mutex);
return ret;
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
struct dw2102_state *state = (struct dw2102_state *)d->priv;
u8 obuf[] = {0xde, 0};
info("%s: %d, initialized %d", __func__, i, state->initialized);
if (i && !state->initialized) {
state->initialized = 1;
return dvb_usb_generic_rw(d, obuf, 2, NULL, 0, 0);
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
}
return 0;
}
static int su3000_identify_state(struct usb_device *udev,
struct dvb_usb_device_properties *props,
struct dvb_usb_device_description **desc,
int *cold)
{
info("%s", __func__);
*cold = 0;
return 0;
}
static int dw210x_set_voltage(struct dvb_frontend *fe,
enum fe_sec_voltage voltage)
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
static int s660_set_voltage(struct dvb_frontend *fe,
enum fe_sec_voltage voltage)
{
struct dvb_usb_adapter *d =
(struct dvb_usb_adapter *)(fe->dvb->priv);
struct dw2102_state *st = (struct dw2102_state *)d->dev->priv;
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
static int tt_s2_4600_read_status(struct dvb_frontend *fe,
enum fe_status *status)
{
struct dvb_usb_adapter *d =
(struct dvb_usb_adapter *)(fe->dvb->priv);
struct dw2102_state *st = (struct dw2102_state *)d->dev->priv;
int ret;
ret = st->fe_read_status(fe, status);
if ((*status & FE_HAS_LOCK) && (!st->last_lock))
su3000_streaming_ctrl(d, 1);
st->last_lock = (*status & FE_HAS_LOCK) ? 1 : 0;
return ret;
}
static int dw2104_frontend_attach(struct dvb_usb_adapter *d)
{
struct dvb_tuner_ops *tuner_ops = NULL;
if (demod_probe & 4) {
d->fe_adap[0].fe = dvb_attach(stv0900_attach, &dw2104a_stv0900_config,
&d->dev->i2c_adap, 0);
if (d->fe_adap[0].fe != NULL) {
if (dvb_attach(stb6100_attach, d->fe_adap[0].fe,
&dw2104a_stb6100_config,
&d->dev->i2c_adap)) {
tuner_ops = &d->fe_adap[0].fe->ops.tuner_ops;
tuner_ops->set_frequency = stb6100_set_freq;
tuner_ops->get_frequency = stb6100_get_freq;
tuner_ops->set_bandwidth = stb6100_set_bandw;
tuner_ops->get_bandwidth = stb6100_get_bandw;
d->fe_adap[0].fe->ops.set_voltage = dw210x_set_voltage;
info("Attached STV0900+STB6100!");
return 0;
}
}
}
if (demod_probe & 2) {
d->fe_adap[0].fe = dvb_attach(stv0900_attach, &dw2104_stv0900_config,
&d->dev->i2c_adap, 0);
if (d->fe_adap[0].fe != NULL) {
if (dvb_attach(stv6110_attach, d->fe_adap[0].fe,
&dw2104_stv6110_config,
&d->dev->i2c_adap)) {
d->fe_adap[0].fe->ops.set_voltage = dw210x_set_voltage;
info("Attached STV0900+STV6110A!");
return 0;
}
}
}
if (demod_probe & 1) {
d->fe_adap[0].fe = dvb_attach(cx24116_attach, &dw2104_config,
&d->dev->i2c_adap);
if (d->fe_adap[0].fe != NULL) {
d->fe_adap[0].fe->ops.set_voltage = dw210x_set_voltage;
info("Attached cx24116!");
return 0;
}
}
d->fe_adap[0].fe = dvb_attach(ds3000_attach, &dw2104_ds3000_config,
&d->dev->i2c_adap);
if (d->fe_adap[0].fe != NULL) {
dvb_attach(ts2020_attach, d->fe_adap[0].fe,
&dw2104_ts2020_config, &d->dev->i2c_adap);
d->fe_adap[0].fe->ops.set_voltage = dw210x_set_voltage;
info("Attached DS3000!");
return 0;
}
return -EIO;
}
static int dw2102_frontend_attach(struct dvb_usb_adapter *d)
{
if (dw2102_properties.i2c_algo == &dw2102_serit_i2c_algo) {
d->fe_adap[0].fe = dvb_attach(si21xx_attach, &serit_sp1511lhb_config,
&d->dev->i2c_adap);
if (d->fe_adap[0].fe != NULL) {
d->fe_adap[0].fe->ops.set_voltage = dw210x_set_voltage;
info("Attached si21xx!");
return 0;
}
}
if (dw2102_properties.i2c_algo == &dw2102_earda_i2c_algo) {
d->fe_adap[0].fe = dvb_attach(stv0288_attach, &earda_config,
&d->dev->i2c_adap);
if (d->fe_adap[0].fe != NULL) {
if (dvb_attach(stb6000_attach, d->fe_adap[0].fe, 0x61,
&d->dev->i2c_adap)) {
d->fe_adap[0].fe->ops.set_voltage = dw210x_set_voltage;
info("Attached stv0288!");
return 0;
}
}
}
if (dw2102_properties.i2c_algo == &dw2102_i2c_algo) {
d->fe_adap[0].fe = dvb_attach(stv0299_attach, &sharp_z0194a_config,
&d->dev->i2c_adap);
if (d->fe_adap[0].fe != NULL) {
d->fe_adap[0].fe->ops.set_voltage = dw210x_set_voltage;
info("Attached stv0299!");
return 0;
}
}
return -EIO;
}
static int dw3101_frontend_attach(struct dvb_usb_adapter *d)
{
d->fe_adap[0].fe = dvb_attach(tda10023_attach, &dw3101_tda10023_config,
&d->dev->i2c_adap, 0x48);
if (d->fe_adap[0].fe != NULL) {
info("Attached tda10023!");
return 0;
}
return -EIO;
}
static int zl100313_frontend_attach(struct dvb_usb_adapter *d)
{
d->fe_adap[0].fe = dvb_attach(mt312_attach, &zl313_config,
&d->dev->i2c_adap);
if (d->fe_adap[0].fe != NULL) {
if (dvb_attach(zl10039_attach, d->fe_adap[0].fe, 0x60,
&d->dev->i2c_adap)) {
d->fe_adap[0].fe->ops.set_voltage = dw210x_set_voltage;
info("Attached zl100313+zl10039!");
return 0;
}
}
return -EIO;
}
static int stv0288_frontend_attach(struct dvb_usb_adapter *d)
{
u8 obuf[] = {7, 1};
d->fe_adap[0].fe = dvb_attach(stv0288_attach, &earda_config,
&d->dev->i2c_adap);
if (d->fe_adap[0].fe == NULL)
return -EIO;
if (NULL == dvb_attach(stb6000_attach, d->fe_adap[0].fe, 0x61, &d->dev->i2c_adap))
return -EIO;
d->fe_adap[0].fe->ops.set_voltage = dw210x_set_voltage;
dw210x_op_rw(d->dev->udev, 0x8a, 0, 0, obuf, 2, DW210X_WRITE_MSG);
info("Attached stv0288+stb6000!");
return 0;
}
static int ds3000_frontend_attach(struct dvb_usb_adapter *d)
{
struct dw2102_state *st = d->dev->priv;
u8 obuf[] = {7, 1};
d->fe_adap[0].fe = dvb_attach(ds3000_attach, &s660_ds3000_config,
&d->dev->i2c_adap);
if (d->fe_adap[0].fe == NULL)
return -EIO;
dvb_attach(ts2020_attach, d->fe_adap[0].fe, &s660_ts2020_config,
&d->dev->i2c_adap);
st->old_set_voltage = d->fe_adap[0].fe->ops.set_voltage;
d->fe_adap[0].fe->ops.set_voltage = s660_set_voltage;
dw210x_op_rw(d->dev->udev, 0x8a, 0, 0, obuf, 2, DW210X_WRITE_MSG);
info("Attached ds3000+ts2020!");
return 0;
}
static int prof_7500_frontend_attach(struct dvb_usb_adapter *d)
{
u8 obuf[] = {7, 1};
d->fe_adap[0].fe = dvb_attach(stv0900_attach, &prof_7500_stv0900_config,
&d->dev->i2c_adap, 0);
if (d->fe_adap[0].fe == NULL)
return -EIO;
d->fe_adap[0].fe->ops.set_voltage = dw210x_set_voltage;
dw210x_op_rw(d->dev->udev, 0x8a, 0, 0, obuf, 2, DW210X_WRITE_MSG);
info("Attached STV0900+STB6100A!");
return 0;
}
static int su3000_frontend_attach(struct dvb_usb_adapter *d)
{
u8 obuf[3] = { 0xe, 0x80, 0 };
u8 ibuf[] = { 0 };
if (dvb_usb_generic_rw(d->dev, obuf, 3, ibuf, 1, 0) < 0)
err("command 0x0e transfer failed.");
obuf[0] = 0xe;
obuf[1] = 0x02;
obuf[2] = 1;
if (dvb_usb_generic_rw(d->dev, obuf, 3, ibuf, 1, 0) < 0)
err("command 0x0e transfer failed.");
msleep(300);
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
d->fe_adap[0].fe = dvb_attach(ds3000_attach, &su3000_ds3000_config,
&d->dev->i2c_adap);
if (d->fe_adap[0].fe == NULL)
return -EIO;
if (dvb_attach(ts2020_attach, d->fe_adap[0].fe,
&dw2104_ts2020_config,
&d->dev->i2c_adap)) {
info("Attached DS3000/TS2020!");
return 0;
}
info("Failed to attach DS3000/TS2020!");
return -EIO;
}
static int t220_frontend_attach(struct dvb_usb_adapter *d)
{
u8 obuf[3] = { 0xe, 0x87, 0 };
u8 ibuf[] = { 0 };
if (dvb_usb_generic_rw(d->dev, obuf, 3, ibuf, 1, 0) < 0)
err("command 0x0e transfer failed.");
obuf[0] = 0xe;
obuf[1] = 0x86;
obuf[2] = 1;
if (dvb_usb_generic_rw(d->dev, obuf, 3, ibuf, 1, 0) < 0)
err("command 0x0e transfer failed.");
obuf[0] = 0xe;
obuf[1] = 0x80;
obuf[2] = 0;
if (dvb_usb_generic_rw(d->dev, obuf, 3, ibuf, 1, 0) < 0)
err("command 0x0e transfer failed.");
msleep(50);
obuf[0] = 0xe;
obuf[1] = 0x80;
obuf[2] = 1;
if (dvb_usb_generic_rw(d->dev, obuf, 3, ibuf, 1, 0) < 0)
err("command 0x0e transfer failed.");
obuf[0] = 0x51;
if (dvb_usb_generic_rw(d->dev, obuf, 1, ibuf, 1, 0) < 0)
err("command 0x51 transfer failed.");
d->fe_adap[0].fe = dvb_attach(cxd2820r_attach, &cxd2820r_config,
&d->dev->i2c_adap, NULL);
if (d->fe_adap[0].fe != NULL) {
if (dvb_attach(tda18271_attach, d->fe_adap[0].fe, 0x60,
&d->dev->i2c_adap, &tda18271_config)) {
info("Attached TDA18271HD/CXD2820R!");
return 0;
}
}
info("Failed to attach TDA18271HD/CXD2820R!");
return -EIO;
}
static int m88rs2000_frontend_attach(struct dvb_usb_adapter *d)
{
u8 obuf[] = { 0x51 };
u8 ibuf[] = { 0 };
if (dvb_usb_generic_rw(d->dev, obuf, 1, ibuf, 1, 0) < 0)
err("command 0x51 transfer failed.");
d->fe_adap[0].fe = dvb_attach(m88rs2000_attach, &s421_m88rs2000_config,
&d->dev->i2c_adap);
if (d->fe_adap[0].fe == NULL)
return -EIO;
if (dvb_attach(ts2020_attach, d->fe_adap[0].fe,
&dw2104_ts2020_config,
&d->dev->i2c_adap)) {
info("Attached RS2000/TS2020!");
return 0;
}
info("Failed to attach RS2000/TS2020!");
return -EIO;
}
static int tt_s2_4600_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dvb_usb_device *d = adap->dev;
struct dw2102_state *state = d->priv;
u8 obuf[3] = { 0xe, 0x80, 0 };
u8 ibuf[] = { 0 };
struct i2c_adapter *i2c_adapter;
struct i2c_client *client;
struct i2c_board_info board_info;
struct m88ds3103_platform_data m88ds3103_pdata = {};
struct ts2020_config ts2020_config = {};
if (dvb_usb_generic_rw(d, obuf, 3, ibuf, 1, 0) < 0)
err("command 0x0e transfer failed.");
obuf[0] = 0xe;
obuf[1] = 0x02;
obuf[2] = 1;
if (dvb_usb_generic_rw(d, obuf, 3, ibuf, 1, 0) < 0)
err("command 0x0e transfer failed.");
msleep(300);
obuf[0] = 0xe;
obuf[1] = 0x83;
obuf[2] = 0;
if (dvb_usb_generic_rw(d, obuf, 3, ibuf, 1, 0) < 0)
err("command 0x0e transfer failed.");
obuf[0] = 0xe;
obuf[1] = 0x83;
obuf[2] = 1;
if (dvb_usb_generic_rw(d, obuf, 3, ibuf, 1, 0) < 0)
err("command 0x0e transfer failed.");
obuf[0] = 0x51;
if (dvb_usb_generic_rw(d, obuf, 1, ibuf, 1, 0) < 0)
err("command 0x51 transfer failed.");
m88ds3103_pdata.clk = 27000000;
m88ds3103_pdata.i2c_wr_max = 33;
m88ds3103_pdata.ts_mode = M88DS3103_TS_CI;
m88ds3103_pdata.ts_clk = 16000;
m88ds3103_pdata.ts_clk_pol = 0;
m88ds3103_pdata.spec_inv = 0;
m88ds3103_pdata.agc = 0x99;
m88ds3103_pdata.agc_inv = 0;
m88ds3103_pdata.clk_out = M88DS3103_CLOCK_OUT_ENABLED;
m88ds3103_pdata.envelope_mode = 0;
m88ds3103_pdata.lnb_hv_pol = 1;
m88ds3103_pdata.lnb_en_pol = 0;
memset(&board_info, 0, sizeof(board_info));
strlcpy(board_info.type, "m88ds3103", I2C_NAME_SIZE);
board_info.addr = 0x68;
board_info.platform_data = &m88ds3103_pdata;
request_module("m88ds3103");
client = i2c_new_device(&d->i2c_adap, &board_info);
if (client == NULL || client->dev.driver == NULL)
return -ENODEV;
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
return -ENODEV;
}
adap->fe_adap[0].fe = m88ds3103_pdata.get_dvb_frontend(client);
i2c_adapter = m88ds3103_pdata.get_i2c_adapter(client);
state->i2c_client_demod = client;
ts2020_config.fe = adap->fe_adap[0].fe;
memset(&board_info, 0, sizeof(board_info));
strlcpy(board_info.type, "ts2022", I2C_NAME_SIZE);
board_info.addr = 0x60;
board_info.platform_data = &ts2020_config;
request_module("ts2020");
client = i2c_new_device(i2c_adapter, &board_info);
if (client == NULL || client->dev.driver == NULL) {
dvb_frontend_detach(adap->fe_adap[0].fe);
return -ENODEV;
}
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
dvb_frontend_detach(adap->fe_adap[0].fe);
return -ENODEV;
}
adap->fe_adap[0].fe->ops.read_signal_strength =
adap->fe_adap[0].fe->ops.tuner_ops.get_rf_strength;
state->i2c_client_tuner = client;
state->fe_read_status = adap->fe_adap[0].fe->ops.read_status;
adap->fe_adap[0].fe->ops.read_status = tt_s2_4600_read_status;
state->last_lock = 0;
return 0;
}
static int dw2102_tuner_attach(struct dvb_usb_adapter *adap)
{
dvb_attach(dvb_pll_attach, adap->fe_adap[0].fe, 0x60,
&adap->dev->i2c_adap, DVB_PLL_OPERA1);
return 0;
}
static int dw3101_tuner_attach(struct dvb_usb_adapter *adap)
{
dvb_attach(dvb_pll_attach, adap->fe_adap[0].fe, 0x60,
&adap->dev->i2c_adap, DVB_PLL_TUA6034);
return 0;
}
static int dw2102_rc_query(struct dvb_usb_device *d)
{
u8 key[2];
struct i2c_msg msg = {
.addr = DW2102_RC_QUERY,
.flags = I2C_M_RD,
.buf = key,
.len = 2
};
if (d->props.i2c_algo->master_xfer(&d->i2c_adap, &msg, 1) == 1) {
if (msg.buf[0] != 0xff) {
deb_rc("%s: rc code: %x, %x\n",
__func__, key[0], key[1]);
rc_keydown(d->rc_dev, RC_TYPE_UNKNOWN, key[0], 0);
}
}
return 0;
}
static int prof_rc_query(struct dvb_usb_device *d)
{
u8 key[2];
struct i2c_msg msg = {
.addr = DW2102_RC_QUERY,
.flags = I2C_M_RD,
.buf = key,
.len = 2
};
if (d->props.i2c_algo->master_xfer(&d->i2c_adap, &msg, 1) == 1) {
if (msg.buf[0] != 0xff) {
deb_rc("%s: rc code: %x, %x\n",
__func__, key[0], key[1]);
rc_keydown(d->rc_dev, RC_TYPE_UNKNOWN, key[0]^0xff, 0);
}
}
return 0;
}
static int su3000_rc_query(struct dvb_usb_device *d)
{
u8 key[2];
struct i2c_msg msg = {
.addr = DW2102_RC_QUERY,
.flags = I2C_M_RD,
.buf = key,
.len = 2
};
if (d->props.i2c_algo->master_xfer(&d->i2c_adap, &msg, 1) == 1) {
if (msg.buf[0] != 0xff) {
deb_rc("%s: rc code: %x, %x\n",
__func__, key[0], key[1]);
rc_keydown(d->rc_dev, RC_TYPE_RC5,
RC_SCANCODE_RC5(key[1], key[0]), 0);
}
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
switch (le16_to_cpu(dev->descriptor.idProduct)) {
case 0x2101:
ret = request_firmware(&fw, DW2101_FIRMWARE, &dev->dev);
if (ret != 0) {
err(err_str, DW2101_FIRMWARE);
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
switch (le16_to_cpu(dev->descriptor.idProduct)) {
case USB_PID_TEVII_S650:
dw2104_properties.rc.core.rc_codes = RC_MAP_TEVII_NEC;
case USB_PID_DW2104:
reset = 1;
dw210x_op_rw(dev, 0xc4, 0x0000, 0, &reset, 1,
DW210X_WRITE_MSG);
case USB_PID_DW3101:
reset = 0;
dw210x_op_rw(dev, 0xbf, 0x0040, 0, &reset, 0,
DW210X_WRITE_MSG);
break;
case USB_PID_TERRATEC_CINERGY_S:
case USB_PID_DW2102:
dw210x_op_rw(dev, 0xbf, 0x0040, 0, &reset, 0,
DW210X_WRITE_MSG);
dw210x_op_rw(dev, 0xb9, 0x0000, 0, &reset16[0], 2,
DW210X_READ_MSG);
dw210x_op_rw(dev, 0xb5, 0, 0, &reset16[0], 2,
DW210X_READ_MSG);
if ((reset16[0] == 0xa1) || (reset16[0] == 0x80)) {
dw2102_properties.i2c_algo = &dw2102_i2c_algo;
dw2102_properties.adapter->fe[0].tuner_attach = &dw2102_tuner_attach;
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
if (le16_to_cpu(dev->descriptor.idProduct) == 0x2101)
release_firmware(fw);
return ret;
}
static int dw2102_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
p1100 = kmemdup(&s6x0_properties,
sizeof(struct dvb_usb_device_properties), GFP_KERNEL);
if (!p1100)
return -ENOMEM;
p1100->firmware = P1100_FIRMWARE;
p1100->devices[0] = d1100;
p1100->rc.core.rc_query = prof_rc_query;
p1100->rc.core.rc_codes = RC_MAP_TBS_NEC;
p1100->adapter->fe[0].frontend_attach = stv0288_frontend_attach;
s660 = kmemdup(&s6x0_properties,
sizeof(struct dvb_usb_device_properties), GFP_KERNEL);
if (!s660) {
kfree(p1100);
return -ENOMEM;
}
s660->firmware = S660_FIRMWARE;
s660->num_device_descs = 3;
s660->devices[0] = d660;
s660->devices[1] = d480_1;
s660->devices[2] = d480_2;
s660->adapter->fe[0].frontend_attach = ds3000_frontend_attach;
p7500 = kmemdup(&s6x0_properties,
sizeof(struct dvb_usb_device_properties), GFP_KERNEL);
if (!p7500) {
kfree(p1100);
kfree(s660);
return -ENOMEM;
}
p7500->firmware = P7500_FIRMWARE;
p7500->devices[0] = d7500;
p7500->rc.core.rc_query = prof_rc_query;
p7500->rc.core.rc_codes = RC_MAP_TBS_NEC;
p7500->adapter->fe[0].frontend_attach = prof_7500_frontend_attach;
s421 = kmemdup(&su3000_properties,
sizeof(struct dvb_usb_device_properties), GFP_KERNEL);
if (!s421) {
kfree(p1100);
kfree(s660);
kfree(p7500);
return -ENOMEM;
}
s421->num_device_descs = 2;
s421->devices[0] = d421;
s421->devices[1] = d632;
s421->adapter->fe[0].frontend_attach = m88rs2000_frontend_attach;
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
0 == dvb_usb_device_init(intf, s421,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &su3000_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &t220_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &tt_s2_4600_properties,
THIS_MODULE, NULL, adapter_nr))
return 0;
return -ENODEV;
}
static void dw2102_disconnect(struct usb_interface *intf)
{
struct dvb_usb_device *d = usb_get_intfdata(intf);
struct dw2102_state *st = (struct dw2102_state *)d->priv;
struct i2c_client *client;
client = st->i2c_client_tuner;
if (client) {
module_put(client->dev.driver->owner);
i2c_unregister_device(client);
}
client = st->i2c_client_demod;
if (client) {
module_put(client->dev.driver->owner);
i2c_unregister_device(client);
}
dvb_usb_device_exit(intf);
}
