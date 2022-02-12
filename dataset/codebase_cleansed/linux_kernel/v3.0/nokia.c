static int __init nokia_bind_config(struct usb_configuration *c)
{
int status = 0;
status = phonet_bind_config(c);
if (status)
printk(KERN_DEBUG "could not bind phonet config\n");
status = obex_bind_config(c, 0);
if (status)
printk(KERN_DEBUG "could not bind obex config %d\n", 0);
status = obex_bind_config(c, 1);
if (status)
printk(KERN_DEBUG "could not bind obex config %d\n", 0);
status = acm_bind_config(c, 2);
if (status)
printk(KERN_DEBUG "could not bind acm config\n");
status = ecm_bind_config(c, hostaddr);
if (status)
printk(KERN_DEBUG "could not bind ecm config\n");
return status;
}
static int __init nokia_bind(struct usb_composite_dev *cdev)
{
int gcnum;
struct usb_gadget *gadget = cdev->gadget;
int status;
status = gphonet_setup(cdev->gadget);
if (status < 0)
goto err_phonet;
status = gserial_setup(cdev->gadget, 3);
if (status < 0)
goto err_serial;
status = gether_setup(cdev->gadget, hostaddr);
if (status < 0)
goto err_ether;
status = usb_string_id(cdev);
if (status < 0)
goto err_usb;
strings_dev[STRING_MANUFACTURER_IDX].id = status;
device_desc.iManufacturer = status;
status = usb_string_id(cdev);
if (status < 0)
goto err_usb;
strings_dev[STRING_PRODUCT_IDX].id = status;
device_desc.iProduct = status;
status = usb_string_id(cdev);
if (status < 0)
goto err_usb;
strings_dev[STRING_DESCRIPTION_IDX].id = status;
nokia_config_500ma_driver.iConfiguration = status;
nokia_config_100ma_driver.iConfiguration = status;
gcnum = usb_gadget_controller_number(gadget);
if (gcnum >= 0)
device_desc.bcdDevice = cpu_to_le16(NOKIA_VERSION_NUM);
else {
pr_err("nokia_bind: controller '%s' not recognized\n",
gadget->name);
goto err_usb;
}
status = usb_add_config(cdev, &nokia_config_500ma_driver,
nokia_bind_config);
if (status < 0)
goto err_usb;
status = usb_add_config(cdev, &nokia_config_100ma_driver,
nokia_bind_config);
if (status < 0)
goto err_usb;
dev_info(&gadget->dev, "%s\n", NOKIA_LONG_NAME);
return 0;
err_usb:
gether_cleanup();
err_ether:
gserial_cleanup();
err_serial:
gphonet_cleanup();
err_phonet:
return status;
}
static int __exit nokia_unbind(struct usb_composite_dev *cdev)
{
gphonet_cleanup();
gserial_cleanup();
gether_cleanup();
return 0;
}
static int __init nokia_init(void)
{
return usb_composite_probe(&nokia_driver, nokia_bind);
}
static void __exit nokia_cleanup(void)
{
usb_composite_unregister(&nokia_driver);
}
