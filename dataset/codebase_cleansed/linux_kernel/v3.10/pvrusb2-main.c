static void pvr_setup_attach(struct pvr2_context *pvr)
{
pvr2_v4l2_create(pvr);
#ifdef CONFIG_VIDEO_PVRUSB2_DVB
pvr2_dvb_create(pvr);
#endif
#ifdef CONFIG_VIDEO_PVRUSB2_SYSFS
pvr2_sysfs_create(pvr,class_ptr);
#endif
}
static int pvr_probe(struct usb_interface *intf,
const struct usb_device_id *devid)
{
struct pvr2_context *pvr;
pvr = pvr2_context_create(intf,devid,pvr_setup_attach);
if (!pvr) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Failed to create hdw handler");
return -ENOMEM;
}
pvr2_trace(PVR2_TRACE_INIT,"pvr_probe(pvr=%p)",pvr);
usb_set_intfdata(intf, pvr);
return 0;
}
static void pvr_disconnect(struct usb_interface *intf)
{
struct pvr2_context *pvr = usb_get_intfdata(intf);
pvr2_trace(PVR2_TRACE_INIT,"pvr_disconnect(pvr=%p) BEGIN",pvr);
usb_set_intfdata (intf, NULL);
pvr2_context_disconnect(pvr);
pvr2_trace(PVR2_TRACE_INIT,"pvr_disconnect(pvr=%p) DONE",pvr);
}
static int __init pvr_init(void)
{
int ret;
pvr2_trace(PVR2_TRACE_INIT,"pvr_init");
ret = pvr2_context_global_init();
if (ret != 0) {
pvr2_trace(PVR2_TRACE_INIT,"pvr_init failure code=%d",ret);
return ret;
}
#ifdef CONFIG_VIDEO_PVRUSB2_SYSFS
class_ptr = pvr2_sysfs_class_create();
#endif
ret = usb_register(&pvr_driver);
if (ret == 0)
printk(KERN_INFO "pvrusb2: " DRIVER_VERSION ":"
DRIVER_DESC "\n");
if (pvrusb2_debug)
printk(KERN_INFO "pvrusb2: Debug mask is %d (0x%x)\n",
pvrusb2_debug,pvrusb2_debug);
pvr2_trace(PVR2_TRACE_INIT,"pvr_init complete");
return ret;
}
static void __exit pvr_exit(void)
{
pvr2_trace(PVR2_TRACE_INIT,"pvr_exit");
usb_deregister(&pvr_driver);
pvr2_context_global_done();
#ifdef CONFIG_VIDEO_PVRUSB2_SYSFS
pvr2_sysfs_class_destroy(class_ptr);
#endif
pvr2_trace(PVR2_TRACE_INIT,"pvr_exit complete");
}
