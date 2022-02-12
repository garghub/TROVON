static void s2250loader_delete(struct kref *kref)
{
pdevice_extension_t s = to_s2250loader_dev_common(kref);
s2250_dev_table[s->minor] = NULL;
kfree(s);
}
static int s2250loader_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_device *usbdev;
int minor, ret;
pdevice_extension_t s = NULL;
const struct firmware *fw;
usbdev = usb_get_dev(interface_to_usbdev(interface));
if (!usbdev) {
dev_err(&interface->dev, "Enter s2250loader_probe failed\n");
return -1;
}
dev_info(&interface->dev, "Enter s2250loader_probe 2.6 kernel\n");
dev_info(&interface->dev, "vendor id 0x%x, device id 0x%x devnum:%d\n",
usbdev->descriptor.idVendor, usbdev->descriptor.idProduct,
usbdev->devnum);
if (usbdev->descriptor.bNumConfigurations != 1) {
dev_err(&interface->dev, "can't handle multiple config\n");
return -1;
}
mutex_lock(&s2250_dev_table_mutex);
for (minor = 0; minor < MAX_DEVICES; minor++) {
if (s2250_dev_table[minor] == NULL)
break;
}
if (minor < 0 || minor >= MAX_DEVICES) {
dev_err(&interface->dev, "Invalid minor: %d\n", minor);
goto failed;
}
s = kmalloc(sizeof(device_extension_t), GFP_KERNEL);
if (s == NULL)
goto failed;
s2250_dev_table[minor] = s;
dev_info(&interface->dev,
"s2250loader_probe: Device %d on Bus %d Minor %d\n",
usbdev->devnum, usbdev->bus->busnum, minor);
memset(s, 0, sizeof(device_extension_t));
s->usbdev = usbdev;
dev_info(&interface->dev, "loading 2250 loader\n");
kref_init(&(s->kref));
mutex_unlock(&s2250_dev_table_mutex);
if (request_firmware(&fw, S2250_LOADER_FIRMWARE, &usbdev->dev)) {
dev_err(&interface->dev,
"s2250: unable to load firmware from file \"%s\"\n",
S2250_LOADER_FIRMWARE);
goto failed2;
}
ret = usb_cypress_load_firmware(usbdev, fw, CYPRESS_FX2);
release_firmware(fw);
if (0 != ret) {
dev_err(&interface->dev, "loader download failed\n");
goto failed2;
}
if (request_firmware(&fw, S2250_FIRMWARE, &usbdev->dev)) {
dev_err(&interface->dev,
"s2250: unable to load firmware from file \"%s\"\n",
S2250_FIRMWARE);
goto failed2;
}
ret = usb_cypress_load_firmware(usbdev, fw, CYPRESS_FX2);
release_firmware(fw);
if (0 != ret) {
dev_err(&interface->dev, "firmware_s2250 download failed\n");
goto failed2;
}
usb_set_intfdata(interface, s);
return 0;
failed:
mutex_unlock(&s2250_dev_table_mutex);
failed2:
if (s)
kref_put(&(s->kref), s2250loader_delete);
dev_err(&interface->dev, "probe failed\n");
return -1;
}
static void s2250loader_disconnect(struct usb_interface *interface)
{
pdevice_extension_t s;
dev_info(&interface->dev, "s2250: disconnect\n");
s = usb_get_intfdata(interface);
usb_set_intfdata(interface, NULL);
kref_put(&(s->kref), s2250loader_delete);
}
