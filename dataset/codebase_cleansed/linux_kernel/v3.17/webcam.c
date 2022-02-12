static int __init
webcam_config_bind(struct usb_configuration *c)
{
return uvc_bind_config(c, uvc_fs_control_cls, uvc_ss_control_cls,
uvc_fs_streaming_cls, uvc_hs_streaming_cls,
uvc_ss_streaming_cls);
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
ret = usb_string_ids_tab(cdev, webcam_strings);
if (ret < 0)
goto error;
webcam_device_descriptor.iManufacturer =
webcam_strings[USB_GADGET_MANUFACTURER_IDX].id;
webcam_device_descriptor.iProduct =
webcam_strings[USB_GADGET_PRODUCT_IDX].id;
webcam_config_driver.iConfiguration =
webcam_strings[STRING_DESCRIPTION_IDX].id;
if ((ret = usb_add_config(cdev, &webcam_config_driver,
webcam_config_bind)) < 0)
goto error;
usb_composite_overwrite_options(cdev, &coverwrite);
INFO(cdev, "Webcam Video Gadget\n");
return 0;
error:
webcam_unbind(cdev);
return ret;
}
