static int go7007_loader_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_device *usbdev;
const struct firmware *fw;
u16 vendor, product;
const char *fw1, *fw2;
int ret;
int i;
usbdev = usb_get_dev(interface_to_usbdev(interface));
if (!usbdev)
goto failed2;
if (usbdev->descriptor.bNumConfigurations != 1) {
dev_err(&interface->dev, "can't handle multiple config\n");
return -ENODEV;
}
vendor = le16_to_cpu(usbdev->descriptor.idVendor);
product = le16_to_cpu(usbdev->descriptor.idProduct);
for (i = 0; fw_configs[i].fw_name1; i++)
if (fw_configs[i].vendor == vendor &&
fw_configs[i].product == product)
break;
if (fw_configs[i].fw_name1 == NULL)
goto failed2;
fw1 = fw_configs[i].fw_name1;
fw2 = fw_configs[i].fw_name2;
dev_info(&interface->dev, "loading firmware %s\n", fw1);
if (request_firmware(&fw, fw1, &usbdev->dev)) {
dev_err(&interface->dev,
"unable to load firmware from file \"%s\"\n", fw1);
goto failed2;
}
ret = cypress_load_firmware(usbdev, fw, CYPRESS_FX2);
release_firmware(fw);
if (0 != ret) {
dev_err(&interface->dev, "loader download failed\n");
goto failed2;
}
if (fw2 == NULL)
return 0;
if (request_firmware(&fw, fw2, &usbdev->dev)) {
dev_err(&interface->dev,
"unable to load firmware from file \"%s\"\n", fw2);
goto failed2;
}
ret = cypress_load_firmware(usbdev, fw, CYPRESS_FX2);
release_firmware(fw);
if (0 != ret) {
dev_err(&interface->dev, "firmware download failed\n");
goto failed2;
}
return 0;
failed2:
dev_err(&interface->dev, "probe failed\n");
return -ENODEV;
}
static void go7007_loader_disconnect(struct usb_interface *interface)
{
dev_info(&interface->dev, "disconnect\n");
usb_set_intfdata(interface, NULL);
}
