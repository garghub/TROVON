static int diolan_usb_transfer(struct i2c_diolan_u2c *dev)
{
int ret = 0;
int actual;
int i;
if (!dev->olen || !dev->ocount)
return -EINVAL;
ret = usb_bulk_msg(dev->usb_dev,
usb_sndbulkpipe(dev->usb_dev, DIOLAN_OUT_EP),
dev->obuffer, dev->olen, &actual,
DIOLAN_USB_TIMEOUT);
if (!ret) {
for (i = 0; i < dev->ocount; i++) {
int tmpret;
tmpret = usb_bulk_msg(dev->usb_dev,
usb_rcvbulkpipe(dev->usb_dev,
DIOLAN_IN_EP),
dev->ibuffer,
sizeof(dev->ibuffer), &actual,
DIOLAN_USB_TIMEOUT);
if (ret < 0)
continue;
ret = tmpret;
if (ret == 0 && actual > 0) {
switch (dev->ibuffer[actual - 1]) {
case RESP_NACK:
ret = i == 1 ? -ENXIO : -EIO;
break;
case RESP_TIMEOUT:
ret = -ETIMEDOUT;
break;
case RESP_OK:
ret = actual - 1;
break;
default:
ret = -EIO;
break;
}
}
}
}
dev->olen = 0;
dev->ocount = 0;
return ret;
}
static int diolan_write_cmd(struct i2c_diolan_u2c *dev, bool flush)
{
if (flush || dev->olen >= DIOLAN_FLUSH_LEN)
return diolan_usb_transfer(dev);
return 0;
}
static int diolan_usb_cmd(struct i2c_diolan_u2c *dev, u8 command, bool flush)
{
dev->obuffer[dev->olen++] = command;
dev->ocount++;
return diolan_write_cmd(dev, flush);
}
static int diolan_usb_cmd_data(struct i2c_diolan_u2c *dev, u8 command, u8 data,
bool flush)
{
dev->obuffer[dev->olen++] = command;
dev->obuffer[dev->olen++] = data;
dev->ocount++;
return diolan_write_cmd(dev, flush);
}
static int diolan_usb_cmd_data2(struct i2c_diolan_u2c *dev, u8 command, u8 d1,
u8 d2, bool flush)
{
dev->obuffer[dev->olen++] = command;
dev->obuffer[dev->olen++] = d1;
dev->obuffer[dev->olen++] = d2;
dev->ocount++;
return diolan_write_cmd(dev, flush);
}
static void diolan_flush_input(struct i2c_diolan_u2c *dev)
{
int i;
for (i = 0; i < 10; i++) {
int actual = 0;
int ret;
ret = usb_bulk_msg(dev->usb_dev,
usb_rcvbulkpipe(dev->usb_dev, DIOLAN_IN_EP),
dev->ibuffer, sizeof(dev->ibuffer), &actual,
DIOLAN_USB_TIMEOUT);
if (ret < 0 || actual == 0)
break;
}
if (i == 10)
dev_err(&dev->interface->dev, "Failed to flush input buffer\n");
}
static int diolan_i2c_start(struct i2c_diolan_u2c *dev)
{
return diolan_usb_cmd(dev, CMD_I2C_START, false);
}
static int diolan_i2c_repeated_start(struct i2c_diolan_u2c *dev)
{
return diolan_usb_cmd(dev, CMD_I2C_REPEATED_START, false);
}
static int diolan_i2c_stop(struct i2c_diolan_u2c *dev)
{
return diolan_usb_cmd(dev, CMD_I2C_STOP, true);
}
static int diolan_i2c_get_byte_ack(struct i2c_diolan_u2c *dev, bool ack,
u8 *byte)
{
int ret;
ret = diolan_usb_cmd_data(dev, CMD_I2C_GET_BYTE_ACK, ack, true);
if (ret > 0)
*byte = dev->ibuffer[0];
else if (ret == 0)
ret = -EIO;
return ret;
}
static int diolan_i2c_put_byte_ack(struct i2c_diolan_u2c *dev, u8 byte)
{
return diolan_usb_cmd_data(dev, CMD_I2C_PUT_BYTE_ACK, byte, false);
}
static int diolan_set_speed(struct i2c_diolan_u2c *dev, u8 speed)
{
return diolan_usb_cmd_data(dev, CMD_I2C_SET_SPEED, speed, true);
}
static int diolan_set_clock_synch(struct i2c_diolan_u2c *dev, bool enable)
{
return diolan_usb_cmd_data(dev, CMD_I2C_SET_CLK_SYNC, enable, true);
}
static int diolan_set_clock_synch_timeout(struct i2c_diolan_u2c *dev, int ms)
{
int to_val = ms * 10;
return diolan_usb_cmd_data2(dev, CMD_I2C_SET_CLK_SYNC_TO,
to_val & 0xff, (to_val >> 8) & 0xff, true);
}
static void diolan_fw_version(struct i2c_diolan_u2c *dev)
{
int ret;
ret = diolan_usb_cmd(dev, CMD_GET_FW_VERSION, true);
if (ret >= 2)
dev_info(&dev->interface->dev,
"Diolan U2C firmware version %u.%u\n",
(unsigned int)dev->ibuffer[0],
(unsigned int)dev->ibuffer[1]);
}
static void diolan_get_serial(struct i2c_diolan_u2c *dev)
{
int ret;
u32 serial;
ret = diolan_usb_cmd(dev, CMD_GET_SERIAL, true);
if (ret >= 4) {
serial = le32_to_cpu(*(u32 *)dev->ibuffer);
dev_info(&dev->interface->dev,
"Diolan U2C serial number %u\n", serial);
}
}
static int diolan_init(struct i2c_diolan_u2c *dev)
{
int speed, ret;
if (frequency >= 200000) {
speed = U2C_I2C_SPEED_FAST;
frequency = U2C_I2C_FREQ_FAST;
} else if (frequency >= 100000 || frequency == 0) {
speed = U2C_I2C_SPEED_STD;
frequency = U2C_I2C_FREQ_STD;
} else {
speed = U2C_I2C_SPEED(frequency);
if (speed > U2C_I2C_SPEED_2KHZ)
speed = U2C_I2C_SPEED_2KHZ;
frequency = U2C_I2C_FREQ(speed);
}
dev_info(&dev->interface->dev,
"Diolan U2C at USB bus %03d address %03d speed %d Hz\n",
dev->usb_dev->bus->busnum, dev->usb_dev->devnum, frequency);
diolan_flush_input(dev);
diolan_fw_version(dev);
diolan_get_serial(dev);
ret = diolan_set_speed(dev, speed);
if (ret < 0)
return ret;
ret = diolan_set_clock_synch(dev, speed != U2C_I2C_SPEED_FAST);
if (ret < 0)
return ret;
if (speed != U2C_I2C_SPEED_FAST)
ret = diolan_set_clock_synch_timeout(dev, DIOLAN_SYNC_TIMEOUT);
return ret;
}
static int diolan_usb_xfer(struct i2c_adapter *adapter, struct i2c_msg *msgs,
int num)
{
struct i2c_diolan_u2c *dev = i2c_get_adapdata(adapter);
struct i2c_msg *pmsg;
int i, j;
int ret, sret;
ret = diolan_i2c_start(dev);
if (ret < 0)
return ret;
for (i = 0; i < num; i++) {
pmsg = &msgs[i];
if (i) {
ret = diolan_i2c_repeated_start(dev);
if (ret < 0)
goto abort;
}
if (pmsg->flags & I2C_M_RD) {
ret =
diolan_i2c_put_byte_ack(dev, (pmsg->addr << 1) | 1);
if (ret < 0)
goto abort;
for (j = 0; j < pmsg->len; j++) {
u8 byte;
bool ack = j < pmsg->len - 1;
if (j == 0 && (pmsg->flags & I2C_M_RECV_LEN))
ack = true;
ret = diolan_i2c_get_byte_ack(dev, ack, &byte);
if (ret < 0)
goto abort;
if (j == 0 && (pmsg->flags & I2C_M_RECV_LEN)) {
if (byte == 0
|| byte > I2C_SMBUS_BLOCK_MAX) {
ret = -EPROTO;
goto abort;
}
pmsg->len += byte;
}
pmsg->buf[j] = byte;
}
} else {
ret = diolan_i2c_put_byte_ack(dev, pmsg->addr << 1);
if (ret < 0)
goto abort;
for (j = 0; j < pmsg->len; j++) {
ret = diolan_i2c_put_byte_ack(dev,
pmsg->buf[j]);
if (ret < 0)
goto abort;
}
}
}
abort:
sret = diolan_i2c_stop(dev);
if (sret < 0 && ret >= 0)
ret = sret;
return ret;
}
static u32 diolan_usb_func(struct i2c_adapter *a)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL |
I2C_FUNC_SMBUS_READ_BLOCK_DATA | I2C_FUNC_SMBUS_BLOCK_PROC_CALL;
}
static void diolan_u2c_free(struct i2c_diolan_u2c *dev)
{
usb_put_dev(dev->usb_dev);
kfree(dev);
}
static int diolan_u2c_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct i2c_diolan_u2c *dev;
int ret;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (dev == NULL) {
dev_err(&interface->dev, "no memory for device state\n");
ret = -ENOMEM;
goto error;
}
dev->usb_dev = usb_get_dev(interface_to_usbdev(interface));
dev->interface = interface;
usb_set_intfdata(interface, dev);
dev->adapter.owner = THIS_MODULE;
dev->adapter.class = I2C_CLASS_HWMON;
dev->adapter.algo = &diolan_usb_algorithm;
i2c_set_adapdata(&dev->adapter, dev);
snprintf(dev->adapter.name, sizeof(dev->adapter.name),
DRIVER_NAME " at bus %03d device %03d",
dev->usb_dev->bus->busnum, dev->usb_dev->devnum);
dev->adapter.dev.parent = &dev->interface->dev;
ret = diolan_init(dev);
if (ret < 0) {
dev_err(&interface->dev, "failed to initialize adapter\n");
goto error_free;
}
ret = i2c_add_adapter(&dev->adapter);
if (ret < 0) {
dev_err(&interface->dev, "failed to add I2C adapter\n");
goto error_free;
}
dev_dbg(&interface->dev, "connected " DRIVER_NAME "\n");
return 0;
error_free:
usb_set_intfdata(interface, NULL);
diolan_u2c_free(dev);
error:
return ret;
}
static void diolan_u2c_disconnect(struct usb_interface *interface)
{
struct i2c_diolan_u2c *dev = usb_get_intfdata(interface);
i2c_del_adapter(&dev->adapter);
usb_set_intfdata(interface, NULL);
diolan_u2c_free(dev);
dev_dbg(&interface->dev, "disconnected\n");
}
static int __init diolan_u2c_init(void)
{
return usb_register(&diolan_u2c_driver);
}
static void __exit diolan_u2c_exit(void)
{
usb_deregister(&diolan_u2c_driver);
}
