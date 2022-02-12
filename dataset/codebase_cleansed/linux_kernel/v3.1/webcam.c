static int __init
webcam_config_bind(struct usb_configuration *c)
{
return uvc_bind_config(c, uvc_control_cls, uvc_fs_streaming_cls,
uvc_hs_streaming_cls);
}
static int
webcam_unbind(struct usb_composite_dev *cdev)
{
return 0;
}
static int __init
webcam_bind(struct usb_composite_dev *cdev)
{
int ret;
if ((ret = usb_string_id(cdev)) < 0)
goto error;
webcam_strings[STRING_MANUFACTURER_IDX].id = ret;
webcam_device_descriptor.iManufacturer = ret;
if ((ret = usb_string_id(cdev)) < 0)
goto error;
webcam_strings[STRING_PRODUCT_IDX].id = ret;
webcam_device_descriptor.iProduct = ret;
if ((ret = usb_string_id(cdev)) < 0)
goto error;
webcam_strings[STRING_DESCRIPTION_IDX].id = ret;
webcam_config_driver.iConfiguration = ret;
if ((ret = usb_add_config(cdev, &webcam_config_driver,
webcam_config_bind)) < 0)
goto error;
INFO(cdev, "Webcam Video Gadget\n");
return 0;
error:
webcam_unbind(cdev);
return ret;
}
static int __init
webcam_init(void)
{
return usb_composite_probe(&webcam_driver, webcam_bind);
}
static void __exit
webcam_cleanup(void)
{
usb_composite_unregister(&webcam_driver);
}
