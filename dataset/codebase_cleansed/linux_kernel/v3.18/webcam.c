static int __init
webcam_config_bind(struct usb_configuration *c)
{
int status = 0;
f_uvc = usb_get_function(fi_uvc);
if (IS_ERR(f_uvc))
return PTR_ERR(f_uvc);
status = usb_add_function(c, f_uvc);
if (status < 0)
usb_put_function(f_uvc);
return status;
}
static int
webcam_unbind(struct usb_composite_dev *cdev)
{
if (!IS_ERR_OR_NULL(f_uvc))
usb_put_function(f_uvc);
if (!IS_ERR_OR_NULL(fi_uvc))
usb_put_function_instance(fi_uvc);
return 0;
}
static int __init
webcam_bind(struct usb_composite_dev *cdev)
{
struct f_uvc_opts *uvc_opts;
int ret;
fi_uvc = usb_get_function_instance("uvc");
if (IS_ERR(fi_uvc))
return PTR_ERR(fi_uvc);
uvc_opts = container_of(fi_uvc, struct f_uvc_opts, func_inst);
uvc_opts->streaming_interval = streaming_interval;
uvc_opts->streaming_maxpacket = streaming_maxpacket;
uvc_opts->streaming_maxburst = streaming_maxburst;
uvc_set_trace_param(trace);
uvc_opts->fs_control = uvc_fs_control_cls;
uvc_opts->ss_control = uvc_ss_control_cls;
uvc_opts->fs_streaming = uvc_fs_streaming_cls;
uvc_opts->hs_streaming = uvc_hs_streaming_cls;
uvc_opts->ss_streaming = uvc_ss_streaming_cls;
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
usb_put_function_instance(fi_uvc);
return ret;
}
