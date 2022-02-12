static int isight_firmware_load(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *dev = interface_to_usbdev(intf);
int llen, len, req, ret = 0;
const struct firmware *firmware;
unsigned char *buf = kmalloc(50, GFP_KERNEL);
unsigned char data[4];
const u8 *ptr;
if (!buf)
return -ENOMEM;
if (request_firmware(&firmware, "isight.fw", &dev->dev) != 0) {
printk(KERN_ERR "Unable to load isight firmware\n");
ret = -ENODEV;
goto out;
}
ptr = firmware->data;
if (usb_control_msg
(dev, usb_sndctrlpipe(dev, 0), 0xa0, 0x40, 0xe600, 0, "\1", 1,
300) != 1) {
printk(KERN_ERR
"Failed to initialise isight firmware loader\n");
ret = -ENODEV;
goto out;
}
while (ptr+4 <= firmware->data+firmware->size) {
memcpy(data, ptr, 4);
len = (data[0] << 8 | data[1]);
req = (data[2] << 8 | data[3]);
ptr += 4;
if (len == 0x8001)
break;
else if (len == 0)
continue;
for (; len > 0; req += 50) {
llen = min(len, 50);
len -= llen;
if (ptr+llen > firmware->data+firmware->size) {
printk(KERN_ERR
"Malformed isight firmware");
ret = -ENODEV;
goto out;
}
memcpy(buf, ptr, llen);
ptr += llen;
if (usb_control_msg
(dev, usb_sndctrlpipe(dev, 0), 0xa0, 0x40, req, 0,
buf, llen, 300) != llen) {
printk(KERN_ERR
"Failed to load isight firmware\n");
ret = -ENODEV;
goto out;
}
}
}
if (usb_control_msg
(dev, usb_sndctrlpipe(dev, 0), 0xa0, 0x40, 0xe600, 0, "\0", 1,
300) != 1) {
printk(KERN_ERR "isight firmware loading completion failed\n");
ret = -ENODEV;
}
out:
kfree(buf);
release_firmware(firmware);
return ret;
}
static void isight_firmware_disconnect(struct usb_interface *intf)
{
}
static int __init isight_firmware_init(void)
{
return usb_register(&isight_firmware_driver);
}
static void __exit isight_firmware_exit(void)
{
usb_deregister(&isight_firmware_driver);
}
