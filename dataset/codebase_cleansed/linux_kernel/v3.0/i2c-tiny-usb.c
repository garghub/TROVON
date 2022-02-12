static int usb_xfer(struct i2c_adapter *adapter, struct i2c_msg *msgs, int num)
{
unsigned char status;
struct i2c_msg *pmsg;
int i;
dev_dbg(&adapter->dev, "master xfer %d messages:\n", num);
for (i = 0 ; i < num ; i++) {
int cmd = CMD_I2C_IO;
if (i == 0)
cmd |= CMD_I2C_IO_BEGIN;
if (i == num-1)
cmd |= CMD_I2C_IO_END;
pmsg = &msgs[i];
dev_dbg(&adapter->dev,
" %d: %s (flags %d) %d bytes to 0x%02x\n",
i, pmsg->flags & I2C_M_RD ? "read" : "write",
pmsg->flags, pmsg->len, pmsg->addr);
if (pmsg->flags & I2C_M_RD) {
if (usb_read(adapter, cmd,
pmsg->flags, pmsg->addr,
pmsg->buf, pmsg->len) != pmsg->len) {
dev_err(&adapter->dev,
"failure reading data\n");
return -EREMOTEIO;
}
} else {
if (usb_write(adapter, cmd,
pmsg->flags, pmsg->addr,
pmsg->buf, pmsg->len) != pmsg->len) {
dev_err(&adapter->dev,
"failure writing data\n");
return -EREMOTEIO;
}
}
if (usb_read(adapter, CMD_GET_STATUS, 0, 0, &status, 1) != 1) {
dev_err(&adapter->dev, "failure reading status\n");
return -EREMOTEIO;
}
dev_dbg(&adapter->dev, " status = %d\n", status);
if (status == STATUS_ADDRESS_NAK)
return -EREMOTEIO;
}
return i;
}
static u32 usb_func(struct i2c_adapter *adapter)
{
__le32 func;
if (usb_read(adapter, CMD_GET_FUNC, 0, 0, &func, sizeof(func)) !=
sizeof(func)) {
dev_err(&adapter->dev, "failure reading functionality\n");
return 0;
}
return le32_to_cpu(func);
}
static int usb_read(struct i2c_adapter *adapter, int cmd,
int value, int index, void *data, int len)
{
struct i2c_tiny_usb *dev = (struct i2c_tiny_usb *)adapter->algo_data;
return usb_control_msg(dev->usb_dev, usb_rcvctrlpipe(dev->usb_dev, 0),
cmd, USB_TYPE_VENDOR | USB_RECIP_INTERFACE |
USB_DIR_IN, value, index, data, len, 2000);
}
static int usb_write(struct i2c_adapter *adapter, int cmd,
int value, int index, void *data, int len)
{
struct i2c_tiny_usb *dev = (struct i2c_tiny_usb *)adapter->algo_data;
return usb_control_msg(dev->usb_dev, usb_sndctrlpipe(dev->usb_dev, 0),
cmd, USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
value, index, data, len, 2000);
}
static void i2c_tiny_usb_free(struct i2c_tiny_usb *dev)
{
usb_put_dev(dev->usb_dev);
kfree(dev);
}
static int i2c_tiny_usb_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct i2c_tiny_usb *dev;
int retval = -ENOMEM;
u16 version;
dev_dbg(&interface->dev, "probing usb device\n");
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (dev == NULL) {
dev_err(&interface->dev, "Out of memory\n");
goto error;
}
dev->usb_dev = usb_get_dev(interface_to_usbdev(interface));
dev->interface = interface;
usb_set_intfdata(interface, dev);
version = le16_to_cpu(dev->usb_dev->descriptor.bcdDevice);
dev_info(&interface->dev,
"version %x.%02x found at bus %03d address %03d\n",
version >> 8, version & 0xff,
dev->usb_dev->bus->busnum, dev->usb_dev->devnum);
dev->adapter.owner = THIS_MODULE;
dev->adapter.class = I2C_CLASS_HWMON;
dev->adapter.algo = &usb_algorithm;
dev->adapter.algo_data = dev;
snprintf(dev->adapter.name, sizeof(dev->adapter.name),
"i2c-tiny-usb at bus %03d device %03d",
dev->usb_dev->bus->busnum, dev->usb_dev->devnum);
if (usb_write(&dev->adapter, CMD_SET_DELAY, delay, 0, NULL, 0) != 0) {
dev_err(&dev->adapter.dev,
"failure setting delay to %dus\n", delay);
retval = -EIO;
goto error;
}
dev->adapter.dev.parent = &dev->interface->dev;
i2c_add_adapter(&dev->adapter);
dev_info(&dev->adapter.dev, "connected i2c-tiny-usb device\n");
return 0;
error:
if (dev)
i2c_tiny_usb_free(dev);
return retval;
}
static void i2c_tiny_usb_disconnect(struct usb_interface *interface)
{
struct i2c_tiny_usb *dev = usb_get_intfdata(interface);
i2c_del_adapter(&dev->adapter);
usb_set_intfdata(interface, NULL);
i2c_tiny_usb_free(dev);
dev_dbg(&interface->dev, "disconnected\n");
}
static int __init usb_i2c_tiny_usb_init(void)
{
return usb_register(&i2c_tiny_usb_driver);
}
static void __exit usb_i2c_tiny_usb_exit(void)
{
usb_deregister(&i2c_tiny_usb_driver);
}
