static int usb_xfer(struct i2c_adapter *adapter, struct i2c_msg *msgs, int num)
{
unsigned char *pstatus;
struct i2c_msg *pmsg;
int i, ret;
dev_dbg(&adapter->dev, "master xfer %d messages:\n", num);
pstatus = kmalloc(sizeof(*pstatus), GFP_KERNEL);
if (!pstatus)
return -ENOMEM;
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
ret = -EREMOTEIO;
goto out;
}
} else {
if (usb_write(adapter, cmd,
pmsg->flags, pmsg->addr,
pmsg->buf, pmsg->len) != pmsg->len) {
dev_err(&adapter->dev,
"failure writing data\n");
ret = -EREMOTEIO;
goto out;
}
}
if (usb_read(adapter, CMD_GET_STATUS, 0, 0, pstatus, 1) != 1) {
dev_err(&adapter->dev, "failure reading status\n");
ret = -EREMOTEIO;
goto out;
}
dev_dbg(&adapter->dev, " status = %d\n", *pstatus);
if (*pstatus == STATUS_ADDRESS_NAK) {
ret = -EREMOTEIO;
goto out;
}
}
ret = i;
out:
kfree(pstatus);
return ret;
}
static u32 usb_func(struct i2c_adapter *adapter)
{
__le32 *pfunc;
u32 ret;
pfunc = kmalloc(sizeof(*pfunc), GFP_KERNEL);
if (!pfunc || usb_read(adapter, CMD_GET_FUNC, 0, 0, pfunc,
sizeof(*pfunc)) != sizeof(*pfunc)) {
dev_err(&adapter->dev, "failure reading functionality\n");
ret = 0;
goto out;
}
ret = le32_to_cpup(pfunc);
out:
kfree(pfunc);
return ret;
}
static int usb_read(struct i2c_adapter *adapter, int cmd,
int value, int index, void *data, int len)
{
struct i2c_tiny_usb *dev = (struct i2c_tiny_usb *)adapter->algo_data;
void *dmadata = kmalloc(len, GFP_KERNEL);
int ret;
if (!dmadata)
return -ENOMEM;
ret = usb_control_msg(dev->usb_dev, usb_rcvctrlpipe(dev->usb_dev, 0),
cmd, USB_TYPE_VENDOR | USB_RECIP_INTERFACE |
USB_DIR_IN, value, index, dmadata, len, 2000);
memcpy(data, dmadata, len);
kfree(dmadata);
return ret;
}
static int usb_write(struct i2c_adapter *adapter, int cmd,
int value, int index, void *data, int len)
{
struct i2c_tiny_usb *dev = (struct i2c_tiny_usb *)adapter->algo_data;
void *dmadata = kmemdup(data, len, GFP_KERNEL);
int ret;
if (!dmadata)
return -ENOMEM;
ret = usb_control_msg(dev->usb_dev, usb_sndctrlpipe(dev->usb_dev, 0),
cmd, USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
value, index, dmadata, len, 2000);
kfree(dmadata);
return ret;
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
