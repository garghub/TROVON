static int az6027_usb_in_op(struct dvb_usb_device *d, u8 req,
u16 value, u16 index, u8 *b, int blen)
{
int ret = -1;
if (mutex_lock_interruptible(&d->usb_mutex))
return -EAGAIN;
ret = usb_control_msg(d->udev,
usb_rcvctrlpipe(d->udev, 0),
req,
USB_TYPE_VENDOR | USB_DIR_IN,
value,
index,
b,
blen,
2000);
if (ret < 0) {
warn("usb in operation failed. (%d)", ret);
ret = -EIO;
} else
ret = 0;
deb_xfer("in: req. %02x, val: %04x, ind: %04x, buffer: ", req, value, index);
debug_dump(b, blen, deb_xfer);
mutex_unlock(&d->usb_mutex);
return ret;
}
static int az6027_usb_out_op(struct dvb_usb_device *d,
u8 req,
u16 value,
u16 index,
u8 *b,
int blen)
{
int ret;
deb_xfer("out: req. %02x, val: %04x, ind: %04x, buffer: ", req, value, index);
debug_dump(b, blen, deb_xfer);
if (mutex_lock_interruptible(&d->usb_mutex))
return -EAGAIN;
ret = usb_control_msg(d->udev,
usb_sndctrlpipe(d->udev, 0),
req,
USB_TYPE_VENDOR | USB_DIR_OUT,
value,
index,
b,
blen,
2000);
if (ret != blen) {
warn("usb out operation failed. (%d)", ret);
mutex_unlock(&d->usb_mutex);
return -EIO;
} else{
mutex_unlock(&d->usb_mutex);
return 0;
}
}
static int az6027_streaming_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
int ret;
u8 req;
u16 value;
u16 index;
int blen;
deb_info("%s %d", __func__, onoff);
req = 0xBC;
value = onoff;
index = 0;
blen = 0;
ret = az6027_usb_out_op(adap->dev, req, value, index, NULL, blen);
if (ret != 0)
warn("usb out operation failed. (%d)", ret);
return ret;
}
static int az6027_rc_query(struct dvb_usb_device *d, u32 *event, int *state)
{
return 0;
}
static int az6027_ci_read_attribute_mem(struct dvb_ca_en50221 *ca,
int slot,
int address)
{
struct dvb_usb_device *d = (struct dvb_usb_device *)ca->data;
struct az6027_device_state *state = (struct az6027_device_state *)d->priv;
int ret;
u8 req;
u16 value;
u16 index;
int blen;
u8 *b;
if (slot != 0)
return -EINVAL;
b = kmalloc(12, GFP_KERNEL);
if (!b)
return -ENOMEM;
mutex_lock(&state->ca_mutex);
req = 0xC1;
value = address;
index = 0;
blen = 1;
ret = az6027_usb_in_op(d, req, value, index, b, blen);
if (ret < 0) {
warn("usb in operation failed. (%d)", ret);
ret = -EINVAL;
} else {
ret = b[0];
}
mutex_unlock(&state->ca_mutex);
kfree(b);
return ret;
}
static int az6027_ci_write_attribute_mem(struct dvb_ca_en50221 *ca,
int slot,
int address,
u8 value)
{
struct dvb_usb_device *d = (struct dvb_usb_device *)ca->data;
struct az6027_device_state *state = (struct az6027_device_state *)d->priv;
int ret;
u8 req;
u16 value1;
u16 index;
int blen;
deb_info("%s %d", __func__, slot);
if (slot != 0)
return -EINVAL;
mutex_lock(&state->ca_mutex);
req = 0xC2;
value1 = address;
index = value;
blen = 0;
ret = az6027_usb_out_op(d, req, value1, index, NULL, blen);
if (ret != 0)
warn("usb out operation failed. (%d)", ret);
mutex_unlock(&state->ca_mutex);
return ret;
}
static int az6027_ci_read_cam_control(struct dvb_ca_en50221 *ca,
int slot,
u8 address)
{
struct dvb_usb_device *d = (struct dvb_usb_device *)ca->data;
struct az6027_device_state *state = (struct az6027_device_state *)d->priv;
int ret;
u8 req;
u16 value;
u16 index;
int blen;
u8 *b;
if (slot != 0)
return -EINVAL;
b = kmalloc(12, GFP_KERNEL);
if (!b)
return -ENOMEM;
mutex_lock(&state->ca_mutex);
req = 0xC3;
value = address;
index = 0;
blen = 2;
ret = az6027_usb_in_op(d, req, value, index, b, blen);
if (ret < 0) {
warn("usb in operation failed. (%d)", ret);
ret = -EINVAL;
} else {
if (b[0] == 0)
warn("Read CI IO error");
ret = b[1];
deb_info("read cam data = %x from 0x%x", b[1], value);
}
mutex_unlock(&state->ca_mutex);
kfree(b);
return ret;
}
static int az6027_ci_write_cam_control(struct dvb_ca_en50221 *ca,
int slot,
u8 address,
u8 value)
{
struct dvb_usb_device *d = (struct dvb_usb_device *)ca->data;
struct az6027_device_state *state = (struct az6027_device_state *)d->priv;
int ret;
u8 req;
u16 value1;
u16 index;
int blen;
if (slot != 0)
return -EINVAL;
mutex_lock(&state->ca_mutex);
req = 0xC4;
value1 = address;
index = value;
blen = 0;
ret = az6027_usb_out_op(d, req, value1, index, NULL, blen);
if (ret != 0) {
warn("usb out operation failed. (%d)", ret);
goto failed;
}
failed:
mutex_unlock(&state->ca_mutex);
return ret;
}
static int CI_CamReady(struct dvb_ca_en50221 *ca, int slot)
{
struct dvb_usb_device *d = (struct dvb_usb_device *)ca->data;
int ret;
u8 req;
u16 value;
u16 index;
int blen;
u8 *b;
b = kmalloc(12, GFP_KERNEL);
if (!b)
return -ENOMEM;
req = 0xC8;
value = 0;
index = 0;
blen = 1;
ret = az6027_usb_in_op(d, req, value, index, b, blen);
if (ret < 0) {
warn("usb in operation failed. (%d)", ret);
ret = -EIO;
} else{
ret = b[0];
}
kfree(b);
return ret;
}
static int az6027_ci_slot_reset(struct dvb_ca_en50221 *ca, int slot)
{
struct dvb_usb_device *d = (struct dvb_usb_device *)ca->data;
struct az6027_device_state *state = (struct az6027_device_state *)d->priv;
int ret, i;
u8 req;
u16 value;
u16 index;
int blen;
mutex_lock(&state->ca_mutex);
req = 0xC6;
value = 1;
index = 0;
blen = 0;
ret = az6027_usb_out_op(d, req, value, index, NULL, blen);
if (ret != 0) {
warn("usb out operation failed. (%d)", ret);
goto failed;
}
msleep(500);
req = 0xC6;
value = 0;
index = 0;
blen = 0;
ret = az6027_usb_out_op(d, req, value, index, NULL, blen);
if (ret != 0) {
warn("usb out operation failed. (%d)", ret);
goto failed;
}
for (i = 0; i < 15; i++) {
msleep(100);
if (CI_CamReady(ca, slot)) {
deb_info("CAM Ready");
break;
}
}
msleep(5000);
failed:
mutex_unlock(&state->ca_mutex);
return ret;
}
static int az6027_ci_slot_shutdown(struct dvb_ca_en50221 *ca, int slot)
{
return 0;
}
static int az6027_ci_slot_ts_enable(struct dvb_ca_en50221 *ca, int slot)
{
struct dvb_usb_device *d = (struct dvb_usb_device *)ca->data;
struct az6027_device_state *state = (struct az6027_device_state *)d->priv;
int ret;
u8 req;
u16 value;
u16 index;
int blen;
deb_info("%s", __func__);
mutex_lock(&state->ca_mutex);
req = 0xC7;
value = 1;
index = 0;
blen = 0;
ret = az6027_usb_out_op(d, req, value, index, NULL, blen);
if (ret != 0) {
warn("usb out operation failed. (%d)", ret);
goto failed;
}
failed:
mutex_unlock(&state->ca_mutex);
return ret;
}
static int az6027_ci_poll_slot_status(struct dvb_ca_en50221 *ca, int slot, int open)
{
struct dvb_usb_device *d = (struct dvb_usb_device *)ca->data;
struct az6027_device_state *state = (struct az6027_device_state *)d->priv;
int ret;
u8 req;
u16 value;
u16 index;
int blen;
u8 *b;
b = kmalloc(12, GFP_KERNEL);
if (!b)
return -ENOMEM;
mutex_lock(&state->ca_mutex);
req = 0xC5;
value = 0;
index = 0;
blen = 1;
ret = az6027_usb_in_op(d, req, value, index, b, blen);
if (ret < 0) {
warn("usb in operation failed. (%d)", ret);
ret = -EIO;
} else
ret = 0;
if (!ret && b[0] == 1) {
ret = DVB_CA_EN50221_POLL_CAM_PRESENT |
DVB_CA_EN50221_POLL_CAM_READY;
}
mutex_unlock(&state->ca_mutex);
kfree(b);
return ret;
}
static void az6027_ci_uninit(struct dvb_usb_device *d)
{
struct az6027_device_state *state;
deb_info("%s", __func__);
if (NULL == d)
return;
state = (struct az6027_device_state *)d->priv;
if (NULL == state)
return;
if (NULL == state->ca.data)
return;
dvb_ca_en50221_release(&state->ca);
memset(&state->ca, 0, sizeof(state->ca));
}
static int az6027_ci_init(struct dvb_usb_adapter *a)
{
struct dvb_usb_device *d = a->dev;
struct az6027_device_state *state = (struct az6027_device_state *)d->priv;
int ret;
deb_info("%s", __func__);
mutex_init(&state->ca_mutex);
state->ca.owner = THIS_MODULE;
state->ca.read_attribute_mem = az6027_ci_read_attribute_mem;
state->ca.write_attribute_mem = az6027_ci_write_attribute_mem;
state->ca.read_cam_control = az6027_ci_read_cam_control;
state->ca.write_cam_control = az6027_ci_write_cam_control;
state->ca.slot_reset = az6027_ci_slot_reset;
state->ca.slot_shutdown = az6027_ci_slot_shutdown;
state->ca.slot_ts_enable = az6027_ci_slot_ts_enable;
state->ca.poll_slot_status = az6027_ci_poll_slot_status;
state->ca.data = d;
ret = dvb_ca_en50221_init(&a->dvb_adap,
&state->ca,
0,
1);
if (ret != 0) {
err("Cannot initialize CI: Error %d.", ret);
memset(&state->ca, 0, sizeof(state->ca));
return ret;
}
deb_info("CI initialized.");
return 0;
}
static int az6027_set_voltage(struct dvb_frontend *fe,
enum fe_sec_voltage voltage)
{
u8 buf;
struct dvb_usb_adapter *adap = fe->dvb->priv;
struct i2c_msg i2c_msg = {
.addr = 0x99,
.flags = 0,
.buf = &buf,
.len = 1
};
switch (voltage) {
case SEC_VOLTAGE_13:
buf = 1;
i2c_transfer(&adap->dev->i2c_adap, &i2c_msg, 1);
break;
case SEC_VOLTAGE_18:
buf = 2;
i2c_transfer(&adap->dev->i2c_adap, &i2c_msg, 1);
break;
case SEC_VOLTAGE_OFF:
buf = 0;
i2c_transfer(&adap->dev->i2c_adap, &i2c_msg, 1);
break;
default:
return -EINVAL;
}
return 0;
}
static int az6027_frontend_poweron(struct dvb_usb_adapter *adap)
{
int ret;
u8 req;
u16 value;
u16 index;
int blen;
req = 0xBC;
value = 1;
index = 3;
blen = 0;
ret = az6027_usb_out_op(adap->dev, req, value, index, NULL, blen);
if (ret != 0)
return -EIO;
return 0;
}
static int az6027_frontend_reset(struct dvb_usb_adapter *adap)
{
int ret;
u8 req;
u16 value;
u16 index;
int blen;
req = 0xC0;
value = 1;
index = 3;
blen = 0;
ret = az6027_usb_out_op(adap->dev, req, value, index, NULL, blen);
if (ret != 0)
return -EIO;
req = 0xC0;
value = 0;
index = 3;
blen = 0;
msleep_interruptible(200);
ret = az6027_usb_out_op(adap->dev, req, value, index, NULL, blen);
if (ret != 0)
return -EIO;
msleep_interruptible(200);
req = 0xC0;
value = 1;
index = 3;
blen = 0;
ret = az6027_usb_out_op(adap->dev, req, value, index, NULL, blen);
if (ret != 0)
return -EIO;
msleep_interruptible(200);
return 0;
}
static int az6027_frontend_tsbypass(struct dvb_usb_adapter *adap, int onoff)
{
int ret;
u8 req;
u16 value;
u16 index;
int blen;
req = 0xC7;
value = onoff;
index = 0;
blen = 0;
ret = az6027_usb_out_op(adap->dev, req, value, index, NULL, blen);
if (ret != 0)
return -EIO;
return 0;
}
static int az6027_frontend_attach(struct dvb_usb_adapter *adap)
{
az6027_frontend_poweron(adap);
az6027_frontend_reset(adap);
deb_info("adap = %p, dev = %p\n", adap, adap->dev);
adap->fe_adap[0].fe = stb0899_attach(&az6027_stb0899_config, &adap->dev->i2c_adap);
if (adap->fe_adap[0].fe) {
deb_info("found STB0899 DVB-S/DVB-S2 frontend @0x%02x", az6027_stb0899_config.demod_address);
if (stb6100_attach(adap->fe_adap[0].fe, &az6027_stb6100_config, &adap->dev->i2c_adap)) {
deb_info("found STB6100 DVB-S/DVB-S2 frontend @0x%02x", az6027_stb6100_config.tuner_address);
adap->fe_adap[0].fe->ops.set_voltage = az6027_set_voltage;
az6027_ci_init(adap);
} else {
adap->fe_adap[0].fe = NULL;
}
} else
warn("no front-end attached\n");
az6027_frontend_tsbypass(adap, 0);
return 0;
}
static void az6027_usb_disconnect(struct usb_interface *intf)
{
struct dvb_usb_device *d = usb_get_intfdata(intf);
az6027_ci_uninit(d);
dvb_usb_device_exit(intf);
}
static int az6027_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return dvb_usb_device_init(intf,
&az6027_properties,
THIS_MODULE,
NULL,
adapter_nr);
}
static int az6027_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msg[], int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
int i = 0, j = 0, len = 0;
u16 index;
u16 value;
int length;
u8 req;
u8 *data;
data = kmalloc(256, GFP_KERNEL);
if (!data)
return -ENOMEM;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0) {
kfree(data);
return -EAGAIN;
}
if (num > 2)
warn("more than 2 i2c messages at a time is not handled yet. TODO.");
for (i = 0; i < num; i++) {
if (msg[i].addr == 0x99) {
req = 0xBE;
index = 0;
value = msg[i].buf[0] & 0x00ff;
length = 1;
az6027_usb_out_op(d, req, value, index, data, length);
}
if (msg[i].addr == 0xd0) {
if (i + 1 < num && (msg[i + 1].flags & I2C_M_RD)) {
req = 0xB9;
index = (((msg[i].buf[0] << 8) & 0xff00) | (msg[i].buf[1] & 0x00ff));
value = msg[i].addr + (msg[i].len << 8);
length = msg[i + 1].len + 6;
az6027_usb_in_op(d, req, value, index, data, length);
len = msg[i + 1].len;
for (j = 0; j < len; j++)
msg[i + 1].buf[j] = data[j + 5];
i++;
} else {
req = 0xBD;
index = (((msg[i].buf[0] << 8) & 0xff00) | (msg[i].buf[1] & 0x00ff));
value = msg[i].addr + (2 << 8);
length = msg[i].len - 2;
len = msg[i].len - 2;
for (j = 0; j < len; j++)
data[j] = msg[i].buf[j + 2];
az6027_usb_out_op(d, req, value, index, data, length);
}
}
if (msg[i].addr == 0xc0) {
if (msg[i].flags & I2C_M_RD) {
req = 0xB9;
index = 0x0;
value = msg[i].addr;
length = msg[i].len + 6;
az6027_usb_in_op(d, req, value, index, data, length);
len = msg[i].len;
for (j = 0; j < len; j++)
msg[i].buf[j] = data[j + 5];
} else {
req = 0xBD;
index = msg[i].buf[0] & 0x00FF;
value = msg[i].addr + (1 << 8);
length = msg[i].len - 1;
len = msg[i].len - 1;
for (j = 0; j < len; j++)
data[j] = msg[i].buf[j + 1];
az6027_usb_out_op(d, req, value, index, data, length);
}
}
}
mutex_unlock(&d->i2c_mutex);
kfree(data);
return i;
}
static u32 az6027_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int az6027_identify_state(struct usb_device *udev,
struct dvb_usb_device_properties *props,
struct dvb_usb_device_description **desc,
int *cold)
{
u8 *b;
s16 ret;
b = kmalloc(16, GFP_KERNEL);
if (!b)
return -ENOMEM;
ret = usb_control_msg(udev,
usb_rcvctrlpipe(udev, 0),
0xb7,
USB_TYPE_VENDOR | USB_DIR_IN,
6,
0,
b,
6,
USB_CTRL_GET_TIMEOUT);
*cold = ret <= 0;
kfree(b);
deb_info("cold: %d\n", *cold);
return 0;
}
