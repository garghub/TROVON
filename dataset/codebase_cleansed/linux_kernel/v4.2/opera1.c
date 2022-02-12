static int opera1_xilinx_rw(struct usb_device *dev, u8 request, u16 value,
u8 * data, u16 len, int flags)
{
int ret;
u8 tmp;
u8 *buf;
unsigned int pipe = (flags == OPERA_READ_MSG) ?
usb_rcvctrlpipe(dev,0) : usb_sndctrlpipe(dev, 0);
u8 request_type = (flags == OPERA_READ_MSG) ? USB_DIR_IN : USB_DIR_OUT;
buf = kmalloc(len, GFP_KERNEL);
if (!buf)
return -ENOMEM;
if (flags == OPERA_WRITE_MSG)
memcpy(buf, data, len);
ret = usb_control_msg(dev, pipe, request,
request_type | USB_TYPE_VENDOR, value, 0x0,
buf, len, 2000);
if (request == OPERA_TUNER_REQ) {
tmp = buf[0];
if (usb_control_msg(dev, usb_rcvctrlpipe(dev, 0),
OPERA_TUNER_REQ, USB_DIR_IN | USB_TYPE_VENDOR,
0x01, 0x0, buf, 1, 2000) < 1 || buf[0] != 0x08) {
ret = 0;
goto out;
}
buf[0] = tmp;
}
if (flags == OPERA_READ_MSG)
memcpy(data, buf, len);
out:
kfree(buf);
return ret;
}
static int opera1_usb_i2c_msgxfer(struct dvb_usb_device *dev, u16 addr,
u8 * buf, u16 len)
{
int ret = 0;
u8 request;
u16 value;
if (!dev) {
info("no usb_device");
return -EINVAL;
}
if (mutex_lock_interruptible(&dev->usb_mutex) < 0)
return -EAGAIN;
switch (addr>>1){
case ADDR_B600_VOLTAGE_13V:
request=0xb6;
value=0x00;
break;
case ADDR_B601_VOLTAGE_18V:
request=0xb6;
value=0x01;
break;
case ADDR_B1A6_STREAM_CTRL:
request=0xb1;
value=0xa6;
break;
case ADDR_B880_READ_REMOTE:
request=0xb8;
value=0x80;
break;
default:
request=0xb1;
value=addr;
}
ret = opera1_xilinx_rw(dev->udev, request,
value, buf, len,
addr&0x01?OPERA_READ_MSG:OPERA_WRITE_MSG);
mutex_unlock(&dev->usb_mutex);
return ret;
}
static int opera1_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msg[],
int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adap);
int i = 0, tmp = 0;
if (!d)
return -ENODEV;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
for (i = 0; i < num; i++) {
if ((tmp = opera1_usb_i2c_msgxfer(d,
(msg[i].addr<<1)|(msg[i].flags&I2C_M_RD?0x01:0),
msg[i].buf,
msg[i].len
)) != msg[i].len) {
break;
}
if (dvb_usb_opera1_debug & 0x10)
info("sending i2c message %d %d", tmp, msg[i].len);
}
mutex_unlock(&d->i2c_mutex);
return num;
}
static u32 opera1_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int opera1_set_voltage(struct dvb_frontend *fe,
enum fe_sec_voltage voltage)
{
static u8 command_13v[1]={0x00};
static u8 command_18v[1]={0x01};
struct i2c_msg msg[] = {
{.addr = ADDR_B600_VOLTAGE_13V,.flags = 0,.buf = command_13v,.len = 1},
};
struct dvb_usb_adapter *udev_adap =
(struct dvb_usb_adapter *)(fe->dvb->priv);
if (voltage == SEC_VOLTAGE_18) {
msg[0].addr = ADDR_B601_VOLTAGE_18V;
msg[0].buf = command_18v;
}
i2c_transfer(&udev_adap->dev->i2c_adap, msg, 1);
return 0;
}
static int opera1_stv0299_set_symbol_rate(struct dvb_frontend *fe, u32 srate,
u32 ratio)
{
stv0299_writereg(fe, 0x13, 0x98);
stv0299_writereg(fe, 0x14, 0x95);
stv0299_writereg(fe, REG_1F_SYMBOLRATE_BYTE0, (ratio >> 16) & 0xff);
stv0299_writereg(fe, REG_20_SYMBOLRATE_BYTE1, (ratio >> 8) & 0xff);
stv0299_writereg(fe, REG_21_SYMBOLRATE_BYTE2, (ratio) & 0xf0);
return 0;
}
static int opera1_frontend_attach(struct dvb_usb_adapter *d)
{
d->fe_adap[0].fe = dvb_attach(stv0299_attach, &opera1_stv0299_config,
&d->dev->i2c_adap);
if ((d->fe_adap[0].fe) != NULL) {
d->fe_adap[0].fe->ops.set_voltage = opera1_set_voltage;
return 0;
}
info("not attached stv0299");
return -EIO;
}
static int opera1_tuner_attach(struct dvb_usb_adapter *adap)
{
dvb_attach(
dvb_pll_attach, adap->fe_adap[0].fe, 0xc0>>1,
&adap->dev->i2c_adap, DVB_PLL_OPERA1
);
return 0;
}
static int opera1_power_ctrl(struct dvb_usb_device *d, int onoff)
{
u8 val = onoff ? 0x01 : 0x00;
if (dvb_usb_opera1_debug)
info("power %s", onoff ? "on" : "off");
return opera1_xilinx_rw(d->udev, 0xb7, val,
&val, 1, OPERA_WRITE_MSG);
}
static int opera1_streaming_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
static u8 buf_start[2] = { 0xff, 0x03 };
static u8 buf_stop[2] = { 0xff, 0x00 };
struct i2c_msg start_tuner[] = {
{.addr = ADDR_B1A6_STREAM_CTRL,.buf = onoff ? buf_start : buf_stop,.len = 2},
};
if (dvb_usb_opera1_debug)
info("streaming %s", onoff ? "on" : "off");
i2c_transfer(&adap->dev->i2c_adap, start_tuner, 1);
return 0;
}
static int opera1_pid_filter(struct dvb_usb_adapter *adap, int index, u16 pid,
int onoff)
{
u8 b_pid[3];
struct i2c_msg msg[] = {
{.addr = ADDR_B1A6_STREAM_CTRL,.buf = b_pid,.len = 3},
};
if (dvb_usb_opera1_debug)
info("pidfilter index: %d pid: %d %s", index, pid,
onoff ? "on" : "off");
b_pid[0] = (2 * index) + 4;
b_pid[1] = onoff ? (pid & 0xff) : (0x00);
b_pid[2] = onoff ? ((pid >> 8) & 0xff) : (0x00);
i2c_transfer(&adap->dev->i2c_adap, msg, 1);
return 0;
}
static int opera1_pid_filter_control(struct dvb_usb_adapter *adap, int onoff)
{
int u = 0x04;
u8 b_pid[3];
struct i2c_msg msg[] = {
{.addr = ADDR_B1A6_STREAM_CTRL,.buf = b_pid,.len = 3},
};
if (dvb_usb_opera1_debug)
info("%s hw-pidfilter", onoff ? "enable" : "disable");
for (; u < 0x7e; u += 2) {
b_pid[0] = u;
b_pid[1] = 0;
b_pid[2] = 0x80;
i2c_transfer(&adap->dev->i2c_adap, msg, 1);
}
return 0;
}
static int opera1_rc_query(struct dvb_usb_device *dev, u32 * event, int *state)
{
struct opera1_state *opst = dev->priv;
u8 rcbuffer[32];
const u16 startmarker1 = 0x10ed;
const u16 startmarker2 = 0x11ec;
struct i2c_msg read_remote[] = {
{.addr = ADDR_B880_READ_REMOTE,.buf = rcbuffer,.flags = I2C_M_RD,.len = 32},
};
int i = 0;
u32 send_key = 0;
if (i2c_transfer(&dev->i2c_adap, read_remote, 1) == 1) {
for (i = 0; i < 32; i++) {
if (rcbuffer[i])
send_key |= 1;
if (i < 31)
send_key = send_key << 1;
}
if (send_key & 0x8000)
send_key = (send_key << 1) | (send_key >> 15 & 0x01);
if (send_key == 0xffff && opst->last_key_pressed != 0) {
*state = REMOTE_KEY_REPEAT;
*event = opst->last_key_pressed;
return 0;
}
for (; send_key != 0;) {
if (send_key >> 16 == startmarker2) {
break;
} else if (send_key >> 16 == startmarker1) {
send_key =
(send_key & 0xfffeffff) | (startmarker1 << 16);
break;
} else
send_key >>= 1;
}
if (send_key == 0)
return 0;
send_key = (send_key & 0xffff) | 0x0100;
for (i = 0; i < ARRAY_SIZE(rc_map_opera1_table); i++) {
if (rc5_scan(&rc_map_opera1_table[i]) == (send_key & 0xffff)) {
*state = REMOTE_KEY_PRESSED;
*event = rc_map_opera1_table[i].keycode;
opst->last_key_pressed =
rc_map_opera1_table[i].keycode;
break;
}
opst->last_key_pressed = 0;
}
} else
*state = REMOTE_NO_KEY_PRESSED;
return 0;
}
static int opera1_read_mac_address(struct dvb_usb_device *d, u8 mac[6])
{
u8 command[] = { READ_MAC_ADDR };
opera1_xilinx_rw(d->udev, 0xb1, 0xa0, command, 1, OPERA_WRITE_MSG);
opera1_xilinx_rw(d->udev, 0xb1, 0xa1, mac, 6, OPERA_READ_MSG);
return 0;
}
static int opera1_xilinx_load_firmware(struct usb_device *dev,
const char *filename)
{
const struct firmware *fw = NULL;
u8 *b, *p;
int ret = 0, i,fpgasize=40;
u8 testval;
info("start downloading fpga firmware %s",filename);
if ((ret = request_firmware(&fw, filename, &dev->dev)) != 0) {
err("did not find the firmware file. (%s) "
"Please see linux/Documentation/dvb/ for more details on firmware-problems.",
filename);
return ret;
} else {
p = kmalloc(fw->size, GFP_KERNEL);
opera1_xilinx_rw(dev, 0xbc, 0x00, &testval, 1, OPERA_READ_MSG);
if (p != NULL && testval != 0x67) {
u8 reset = 0, fpga_command = 0;
memcpy(p, fw->data, fw->size);
opera1_xilinx_rw(dev, 0xbc, 0xaa, &fpga_command, 1,
OPERA_WRITE_MSG);
for (i = 0; i < fw->size;) {
if ( (fw->size - i) <fpgasize){
fpgasize=fw->size-i;
}
b = (u8 *) p + i;
if (opera1_xilinx_rw
(dev, OPERA_WRITE_FX2, 0x0, b , fpgasize,
OPERA_WRITE_MSG) != fpgasize
) {
err("error while transferring firmware");
ret = -EINVAL;
break;
}
i = i + fpgasize;
}
if (ret || opera1_xilinx_rw
(dev, 0xa0, 0xe600, &reset, 1,
OPERA_WRITE_MSG) != 1) {
err("could not restart the USB controller CPU.");
ret = -EINVAL;
}
}
}
kfree(p);
release_firmware(fw);
return ret;
}
static int opera1_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(intf);
if (le16_to_cpu(udev->descriptor.idProduct) == USB_PID_OPERA1_WARM &&
le16_to_cpu(udev->descriptor.idVendor) == USB_VID_OPERA1 &&
opera1_xilinx_load_firmware(udev, "dvb-usb-opera1-fpga-01.fw") != 0
) {
return -EINVAL;
}
if (0 != dvb_usb_device_init(intf, &opera1_properties,
THIS_MODULE, NULL, adapter_nr))
return -EINVAL;
return 0;
}
