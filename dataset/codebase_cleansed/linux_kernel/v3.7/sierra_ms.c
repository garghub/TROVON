static bool containsFullLinuxPackage(struct swoc_info *swocInfo)
{
if ((swocInfo->LinuxSKU >= 0x2100 && swocInfo->LinuxSKU <= 0x2FFF) ||
(swocInfo->LinuxSKU >= 0x7100 && swocInfo->LinuxSKU <= 0x7FFF))
return true;
else
return false;
}
static int sierra_set_ms_mode(struct usb_device *udev, __u16 eSWocMode)
{
int result;
US_DEBUGP("SWIMS: %s", "DEVICE MODE SWITCH\n");
result = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
SWIMS_USB_REQUEST_SetSwocMode,
USB_TYPE_VENDOR | USB_DIR_OUT,
eSWocMode,
0x0000,
NULL,
0,
USB_CTRL_SET_TIMEOUT);
return result;
}
static int sierra_get_swoc_info(struct usb_device *udev,
struct swoc_info *swocInfo)
{
int result;
US_DEBUGP("SWIMS: Attempting to get TRU-Install info.\n");
result = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
SWIMS_USB_REQUEST_GetSwocInfo,
USB_TYPE_VENDOR | USB_DIR_IN,
0,
0,
(void *) swocInfo,
sizeof(struct swoc_info),
USB_CTRL_SET_TIMEOUT);
swocInfo->LinuxSKU = le16_to_cpu(swocInfo->LinuxSKU);
swocInfo->LinuxVer = le16_to_cpu(swocInfo->LinuxVer);
return result;
}
static void debug_swoc(struct swoc_info *swocInfo)
{
US_DEBUGP("SWIMS: SWoC Rev: %02d \n", swocInfo->rev);
US_DEBUGP("SWIMS: Linux SKU: %04X \n", swocInfo->LinuxSKU);
US_DEBUGP("SWIMS: Linux Version: %04X \n", swocInfo->LinuxVer);
}
static ssize_t show_truinst(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct swoc_info *swocInfo;
struct usb_interface *intf = to_usb_interface(dev);
struct usb_device *udev = interface_to_usbdev(intf);
int result;
if (swi_tru_install == TRU_FORCE_MS) {
result = snprintf(buf, PAGE_SIZE, "Forced Mass Storage\n");
} else {
swocInfo = kmalloc(sizeof(struct swoc_info), GFP_KERNEL);
if (!swocInfo) {
US_DEBUGP("SWIMS: Allocation failure\n");
snprintf(buf, PAGE_SIZE, "Error\n");
return -ENOMEM;
}
result = sierra_get_swoc_info(udev, swocInfo);
if (result < 0) {
US_DEBUGP("SWIMS: failed SWoC query\n");
kfree(swocInfo);
snprintf(buf, PAGE_SIZE, "Error\n");
return -EIO;
}
debug_swoc(swocInfo);
result = snprintf(buf, PAGE_SIZE,
"REV=%02d SKU=%04X VER=%04X\n",
swocInfo->rev,
swocInfo->LinuxSKU,
swocInfo->LinuxVer);
kfree(swocInfo);
}
return result;
}
int sierra_ms_init(struct us_data *us)
{
int result, retries;
struct swoc_info *swocInfo;
struct usb_device *udev;
struct Scsi_Host *sh;
retries = 3;
result = 0;
udev = us->pusb_dev;
sh = us_to_host(us);
scsi_get_host_dev(sh);
US_DEBUGP("SWIMS: sierra_ms_init called\n");
if (swi_tru_install == TRU_FORCE_MODEM) {
US_DEBUGP("SWIMS: %s", "Forcing Modem Mode\n");
result = sierra_set_ms_mode(udev, SWIMS_SET_MODE_Modem);
if (result < 0)
US_DEBUGP("SWIMS: Failed to switch to modem mode.\n");
return -EIO;
}
else if (swi_tru_install == TRU_FORCE_MS) {
US_DEBUGP("SWIMS: %s", "Forcing Mass Storage Mode\n");
goto complete;
}
else {
US_DEBUGP("SWIMS: %s", "Normal SWoC Logic\n");
swocInfo = kmalloc(sizeof(struct swoc_info),
GFP_KERNEL);
if (!swocInfo) {
US_DEBUGP("SWIMS: %s", "Allocation failure\n");
return -ENOMEM;
}
retries = 3;
do {
retries--;
result = sierra_get_swoc_info(udev, swocInfo);
if (result < 0) {
US_DEBUGP("SWIMS: %s", "Failed SWoC query\n");
schedule_timeout_uninterruptible(2*HZ);
}
} while (retries && result < 0);
if (result < 0) {
US_DEBUGP("SWIMS: %s",
"Completely failed SWoC query\n");
kfree(swocInfo);
return -EIO;
}
debug_swoc(swocInfo);
if (!containsFullLinuxPackage(swocInfo)) {
US_DEBUGP("SWIMS: %s",
"Switching to Modem Mode\n");
result = sierra_set_ms_mode(udev,
SWIMS_SET_MODE_Modem);
if (result < 0)
US_DEBUGP("SWIMS: Failed to switch modem\n");
kfree(swocInfo);
return -EIO;
}
kfree(swocInfo);
}
complete:
result = device_create_file(&us->pusb_intf->dev, &dev_attr_truinst);
return 0;
}
