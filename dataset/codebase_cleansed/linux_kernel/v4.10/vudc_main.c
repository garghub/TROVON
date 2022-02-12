static int __init init(void)
{
int retval = -ENOMEM;
int i;
struct vudc_device *udc_dev = NULL, *udc_dev2 = NULL;
if (usb_disabled())
return -ENODEV;
if (vudc_number < 1) {
pr_err("Number of emulated UDC must be no less than 1");
return -EINVAL;
}
retval = platform_driver_register(&vudc_driver);
if (retval < 0)
goto out;
for (i = 0; i < vudc_number; i++) {
udc_dev = alloc_vudc_device(i);
if (!udc_dev) {
retval = -ENOMEM;
goto cleanup;
}
retval = platform_device_add(udc_dev->pdev);
if (retval < 0) {
put_vudc_device(udc_dev);
goto cleanup;
}
list_add_tail(&udc_dev->dev_entry, &vudc_devices);
if (!platform_get_drvdata(udc_dev->pdev)) {
retval = -EINVAL;
goto cleanup;
}
}
goto out;
cleanup:
list_for_each_entry_safe(udc_dev, udc_dev2, &vudc_devices, dev_entry) {
list_del(&udc_dev->dev_entry);
platform_device_del(udc_dev->pdev);
put_vudc_device(udc_dev);
}
platform_driver_unregister(&vudc_driver);
out:
return retval;
}
static void __exit cleanup(void)
{
struct vudc_device *udc_dev = NULL, *udc_dev2 = NULL;
list_for_each_entry_safe(udc_dev, udc_dev2, &vudc_devices, dev_entry) {
list_del(&udc_dev->dev_entry);
platform_device_unregister(udc_dev->pdev);
put_vudc_device(udc_dev);
}
platform_driver_unregister(&vudc_driver);
}
