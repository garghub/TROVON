static int drxk_gate_ctrl(struct dvb_frontend *fe, int enable)
{
struct dvb_usb_adapter *adap = fe->sec_priv;
struct az6007_device_state *st;
int status = 0;
deb_info("%s: %s\n", __func__, enable ? "enable" : "disable");
if (!adap)
return -EINVAL;
st = adap->dev->priv;
if (!st)
return -EINVAL;
if (enable)
status = st->gate_ctrl(fe, 1);
else
status = st->gate_ctrl(fe, 0);
return status;
}
static int __az6007_read(struct usb_device *udev, u8 req, u16 value,
u16 index, u8 *b, int blen)
{
int ret;
ret = usb_control_msg(udev,
usb_rcvctrlpipe(udev, 0),
req,
USB_TYPE_VENDOR | USB_DIR_IN,
value, index, b, blen, 5000);
if (ret < 0) {
warn("usb read operation failed. (%d)", ret);
return -EIO;
}
deb_xfer("in: req. %02x, val: %04x, ind: %04x, buffer: ", req, value,
index);
debug_dump(b, blen, deb_xfer);
return ret;
}
static int az6007_read(struct dvb_usb_device *d, u8 req, u16 value,
u16 index, u8 *b, int blen)
{
struct az6007_device_state *st = d->priv;
int ret;
if (mutex_lock_interruptible(&st->mutex) < 0)
return -EAGAIN;
ret = __az6007_read(d->udev, req, value, index, b, blen);
mutex_unlock(&st->mutex);
return ret;
}
static int __az6007_write(struct usb_device *udev, u8 req, u16 value,
u16 index, u8 *b, int blen)
{
int ret;
deb_xfer("out: req. %02x, val: %04x, ind: %04x, buffer: ", req, value,
index);
debug_dump(b, blen, deb_xfer);
if (blen > 64) {
err("az6007: tried to write %d bytes, but I2C max size is 64 bytes\n",
blen);
return -EOPNOTSUPP;
}
ret = usb_control_msg(udev,
usb_sndctrlpipe(udev, 0),
req,
USB_TYPE_VENDOR | USB_DIR_OUT,
value, index, b, blen, 5000);
if (ret != blen) {
err("usb write operation failed. (%d)", ret);
return -EIO;
}
return 0;
}
static int az6007_write(struct dvb_usb_device *d, u8 req, u16 value,
u16 index, u8 *b, int blen)
{
struct az6007_device_state *st = d->priv;
int ret;
if (mutex_lock_interruptible(&st->mutex) < 0)
return -EAGAIN;
ret = __az6007_write(d->udev, req, value, index, b, blen);
mutex_unlock(&st->mutex);
return ret;
}
static int az6007_streaming_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
struct dvb_usb_device *d = adap->dev;
deb_info("%s: %s", __func__, onoff ? "enable" : "disable");
return az6007_write(d, 0xbc, onoff, 0, NULL, 0);
}
static int az6007_rc_query(struct dvb_usb_device *d)
{
struct az6007_device_state *st = d->priv;
unsigned code = 0;
az6007_read(d, AZ6007_READ_IR, 0, 0, st->data, 10);
if (st->data[1] == 0x44)
return 0;
if ((st->data[1] ^ st->data[2]) == 0xff)
code = st->data[1];
else
code = st->data[1] << 8 | st->data[2];
if ((st->data[3] ^ st->data[4]) == 0xff)
code = code << 8 | st->data[3];
else
code = code << 16 | st->data[3] << 8 | st->data[4];
rc_keydown(d->rc_dev, code, st->data[5]);
return 0;
}
static int az6007_ci_read_attribute_mem(struct dvb_ca_en50221 *ca,
int slot,
int address)
{
struct dvb_usb_device *d = (struct dvb_usb_device *)ca->data;
struct az6007_device_state *state = (struct az6007_device_state *)d->priv;
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
ret = az6007_read(d, req, value, index, b, blen);
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
static int az6007_ci_write_attribute_mem(struct dvb_ca_en50221 *ca,
int slot,
int address,
u8 value)
{
struct dvb_usb_device *d = (struct dvb_usb_device *)ca->data;
struct az6007_device_state *state = (struct az6007_device_state *)d->priv;
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
ret = az6007_write(d, req, value1, index, NULL, blen);
if (ret != 0)
warn("usb out operation failed. (%d)", ret);
mutex_unlock(&state->ca_mutex);
return ret;
}
static int az6007_ci_read_cam_control(struct dvb_ca_en50221 *ca,
int slot,
u8 address)
{
struct dvb_usb_device *d = (struct dvb_usb_device *)ca->data;
struct az6007_device_state *state = (struct az6007_device_state *)d->priv;
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
ret = az6007_read(d, req, value, index, b, blen);
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
static int az6007_ci_write_cam_control(struct dvb_ca_en50221 *ca,
int slot,
u8 address,
u8 value)
{
struct dvb_usb_device *d = (struct dvb_usb_device *)ca->data;
struct az6007_device_state *state = (struct az6007_device_state *)d->priv;
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
ret = az6007_write(d, req, value1, index, NULL, blen);
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
ret = az6007_read(d, req, value, index, b, blen);
if (ret < 0) {
warn("usb in operation failed. (%d)", ret);
ret = -EIO;
} else{
ret = b[0];
}
kfree(b);
return ret;
}
static int az6007_ci_slot_reset(struct dvb_ca_en50221 *ca, int slot)
{
struct dvb_usb_device *d = (struct dvb_usb_device *)ca->data;
struct az6007_device_state *state = (struct az6007_device_state *)d->priv;
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
ret = az6007_write(d, req, value, index, NULL, blen);
if (ret != 0) {
warn("usb out operation failed. (%d)", ret);
goto failed;
}
msleep(500);
req = 0xC6;
value = 0;
index = 0;
blen = 0;
ret = az6007_write(d, req, value, index, NULL, blen);
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
static int az6007_ci_slot_shutdown(struct dvb_ca_en50221 *ca, int slot)
{
return 0;
}
static int az6007_ci_slot_ts_enable(struct dvb_ca_en50221 *ca, int slot)
{
struct dvb_usb_device *d = (struct dvb_usb_device *)ca->data;
struct az6007_device_state *state = (struct az6007_device_state *)d->priv;
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
ret = az6007_write(d, req, value, index, NULL, blen);
if (ret != 0) {
warn("usb out operation failed. (%d)", ret);
goto failed;
}
failed:
mutex_unlock(&state->ca_mutex);
return ret;
}
static int az6007_ci_poll_slot_status(struct dvb_ca_en50221 *ca, int slot, int open)
{
struct dvb_usb_device *d = (struct dvb_usb_device *)ca->data;
struct az6007_device_state *state = (struct az6007_device_state *)d->priv;
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
ret = az6007_read(d, req, value, index, b, blen);
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
static void az6007_ci_uninit(struct dvb_usb_device *d)
{
struct az6007_device_state *state;
deb_info("%s", __func__);
if (NULL == d)
return;
state = (struct az6007_device_state *)d->priv;
if (NULL == state)
return;
if (NULL == state->ca.data)
return;
dvb_ca_en50221_release(&state->ca);
memset(&state->ca, 0, sizeof(state->ca));
}
static int az6007_ci_init(struct dvb_usb_adapter *a)
{
struct dvb_usb_device *d = a->dev;
struct az6007_device_state *state = (struct az6007_device_state *)d->priv;
int ret;
deb_info("%s", __func__);
mutex_init(&state->ca_mutex);
state->ca.owner = THIS_MODULE;
state->ca.read_attribute_mem = az6007_ci_read_attribute_mem;
state->ca.write_attribute_mem = az6007_ci_write_attribute_mem;
state->ca.read_cam_control = az6007_ci_read_cam_control;
state->ca.write_cam_control = az6007_ci_write_cam_control;
state->ca.slot_reset = az6007_ci_slot_reset;
state->ca.slot_shutdown = az6007_ci_slot_shutdown;
state->ca.slot_ts_enable = az6007_ci_slot_ts_enable;
state->ca.poll_slot_status = az6007_ci_poll_slot_status;
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
static int az6007_read_mac_addr(struct dvb_usb_device *d, u8 mac[6])
{
struct az6007_device_state *st = d->priv;
int ret;
ret = az6007_read(d, AZ6007_READ_DATA, 6, 0, st->data, 6);
memcpy(mac, st->data, sizeof(mac));
if (ret > 0)
deb_info("%s: mac is %02x:%02x:%02x:%02x:%02x:%02x\n",
__func__, mac[0], mac[1], mac[2],
mac[3], mac[4], mac[5]);
return ret;
}
static int az6007_frontend_attach(struct dvb_usb_adapter *adap)
{
struct az6007_device_state *st = adap->dev->priv;
deb_info("attaching demod drxk");
adap->fe_adap[0].fe = dvb_attach(drxk_attach, &terratec_h7_drxk,
&adap->dev->i2c_adap);
if (!adap->fe_adap[0].fe)
return -EINVAL;
adap->fe_adap[0].fe->sec_priv = adap;
st->gate_ctrl = adap->fe_adap[0].fe->ops.i2c_gate_ctrl;
adap->fe_adap[0].fe->ops.i2c_gate_ctrl = drxk_gate_ctrl;
az6007_ci_init(adap);
return 0;
}
static int az6007_tuner_attach(struct dvb_usb_adapter *adap)
{
deb_info("attaching tuner mt2063");
if (adap->fe_adap[0].fe->ops.i2c_gate_ctrl)
adap->fe_adap[0].fe->ops.i2c_gate_ctrl(adap->fe_adap[0].fe, 1);
if (!dvb_attach(mt2063_attach, adap->fe_adap[0].fe,
&az6007_mt2063_config,
&adap->dev->i2c_adap))
return -EINVAL;
if (adap->fe_adap[0].fe->ops.i2c_gate_ctrl)
adap->fe_adap[0].fe->ops.i2c_gate_ctrl(adap->fe_adap[0].fe, 0);
return 0;
}
int az6007_power_ctrl(struct dvb_usb_device *d, int onoff)
{
struct az6007_device_state *st = d->priv;
int ret;
deb_info("%s()\n", __func__);
if (!st->warm) {
mutex_init(&st->mutex);
ret = az6007_write(d, AZ6007_POWER, 0, 2, NULL, 0);
if (ret < 0)
return ret;
msleep(60);
ret = az6007_write(d, AZ6007_POWER, 1, 4, NULL, 0);
if (ret < 0)
return ret;
msleep(100);
ret = az6007_write(d, AZ6007_POWER, 1, 3, NULL, 0);
if (ret < 0)
return ret;
msleep(20);
ret = az6007_write(d, AZ6007_POWER, 1, 4, NULL, 0);
if (ret < 0)
return ret;
msleep(400);
ret = az6007_write(d, FX2_SCON1, 0, 3, NULL, 0);
if (ret < 0)
return ret;
msleep(150);
ret = az6007_write(d, FX2_SCON1, 1, 3, NULL, 0);
if (ret < 0)
return ret;
msleep(430);
ret = az6007_write(d, AZ6007_POWER, 0, 0, NULL, 0);
if (ret < 0)
return ret;
st->warm = true;
return 0;
}
if (!onoff)
return 0;
az6007_write(d, AZ6007_POWER, 0, 0, NULL, 0);
az6007_write(d, AZ6007_TS_THROUGH, 0, 0, NULL, 0);
return 0;
}
static int az6007_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msgs[],
int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
struct az6007_device_state *st = d->priv;
int i, j, len;
int ret = 0;
u16 index;
u16 value;
int length;
u8 req, addr;
if (mutex_lock_interruptible(&st->mutex) < 0)
return -EAGAIN;
for (i = 0; i < num; i++) {
addr = msgs[i].addr << 1;
if (((i + 1) < num)
&& (msgs[i].len == 1)
&& (!msgs[i].flags & I2C_M_RD)
&& (msgs[i + 1].flags & I2C_M_RD)
&& (msgs[i].addr == msgs[i + 1].addr)) {
if (dvb_usb_az6007_debug & 2)
printk(KERN_DEBUG
"az6007 I2C xfer write+read addr=0x%x len=%d/%d: ",
addr, msgs[i].len, msgs[i + 1].len);
req = AZ6007_I2C_RD;
index = msgs[i].buf[0];
value = addr | (1 << 8);
length = 6 + msgs[i + 1].len;
len = msgs[i + 1].len;
ret = __az6007_read(d->udev, req, value, index,
st->data, length);
if (ret >= len) {
for (j = 0; j < len; j++) {
msgs[i + 1].buf[j] = st->data[j + 5];
if (dvb_usb_az6007_debug & 2)
printk(KERN_CONT
"0x%02x ",
msgs[i + 1].buf[j]);
}
} else
ret = -EIO;
i++;
} else if (!(msgs[i].flags & I2C_M_RD)) {
if (dvb_usb_az6007_debug & 2)
printk(KERN_DEBUG
"az6007 I2C xfer write addr=0x%x len=%d: ",
addr, msgs[i].len);
req = AZ6007_I2C_WR;
index = msgs[i].buf[0];
value = addr | (1 << 8);
length = msgs[i].len - 1;
len = msgs[i].len - 1;
if (dvb_usb_az6007_debug & 2)
printk(KERN_CONT "(0x%02x) ", msgs[i].buf[0]);
for (j = 0; j < len; j++) {
st->data[j] = msgs[i].buf[j + 1];
if (dvb_usb_az6007_debug & 2)
printk(KERN_CONT "0x%02x ",
st->data[j]);
}
ret = __az6007_write(d->udev, req, value, index,
st->data, length);
} else {
if (dvb_usb_az6007_debug & 2)
printk(KERN_DEBUG
"az6007 I2C xfer read addr=0x%x len=%d: ",
addr, msgs[i].len);
req = AZ6007_I2C_RD;
index = msgs[i].buf[0];
value = addr;
length = msgs[i].len + 6;
len = msgs[i].len;
ret = __az6007_read(d->udev, req, value, index,
st->data, length);
for (j = 0; j < len; j++) {
msgs[i].buf[j] = st->data[j + 5];
if (dvb_usb_az6007_debug & 2)
printk(KERN_CONT
"0x%02x ", st->data[j + 5]);
}
}
if (dvb_usb_az6007_debug & 2)
printk(KERN_CONT "\n");
if (ret < 0)
goto err;
}
err:
mutex_unlock(&st->mutex);
if (ret < 0) {
info("%s ERROR: %i", __func__, ret);
return ret;
}
return num;
}
static u32 az6007_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
int az6007_identify_state(struct usb_device *udev,
struct dvb_usb_device_properties *props,
struct dvb_usb_device_description **desc, int *cold)
{
int ret;
u8 *mac;
mac = kmalloc(6, GFP_ATOMIC);
if (!mac)
return -ENOMEM;
ret = __az6007_read(udev, AZ6007_READ_DATA, 6, 0, mac, 6);
if (ret == 6)
*cold = 0;
else
*cold = 1;
kfree(mac);
if (*cold) {
__az6007_write(udev, 0x09, 1, 0, NULL, 0);
__az6007_write(udev, 0x00, 0, 0, NULL, 0);
__az6007_write(udev, 0x00, 0, 0, NULL, 0);
}
deb_info("Device is on %s state\n", *cold ? "warm" : "cold");
return 0;
}
static void az6007_usb_disconnect(struct usb_interface *intf)
{
struct dvb_usb_device *d = usb_get_intfdata(intf);
az6007_ci_uninit(d);
dvb_usb_device_exit(intf);
}
static int az6007_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return dvb_usb_device_init(intf, &az6007_properties,
THIS_MODULE, NULL, adapter_nr);
}
static int __init az6007_usb_module_init(void)
{
int result;
deb_info("az6007 usb module init\n");
result = usb_register(&az6007_usb_driver);
if (result) {
err("usb_register failed. (%d)", result);
return result;
}
return 0;
}
static void __exit az6007_usb_module_exit(void)
{
deb_info("az6007 usb module exit\n");
usb_deregister(&az6007_usb_driver);
}
