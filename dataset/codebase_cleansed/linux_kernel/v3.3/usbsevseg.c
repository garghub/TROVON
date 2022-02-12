inline size_t my_memlen(const char *buf, size_t count)
{
if (count > 0 && buf[count-1] == '\n')
return count - 1;
else
return count;
}
static void update_display_powered(struct usb_sevsegdev *mydev)
{
int rc;
if (mydev->powered && !mydev->has_interface_pm) {
rc = usb_autopm_get_interface(mydev->intf);
if (rc < 0)
return;
mydev->has_interface_pm = 1;
}
if (mydev->shadow_power != 1)
return;
rc = usb_control_msg(mydev->udev,
usb_sndctrlpipe(mydev->udev, 0),
0x12,
0x48,
(80 * 0x100) + 10,
(0x00 * 0x100) + (mydev->powered ? 1 : 0),
NULL,
0,
2000);
if (rc < 0)
dev_dbg(&mydev->udev->dev, "power retval = %d\n", rc);
if (!mydev->powered && mydev->has_interface_pm) {
usb_autopm_put_interface(mydev->intf);
mydev->has_interface_pm = 0;
}
}
static void update_display_mode(struct usb_sevsegdev *mydev)
{
int rc;
if(mydev->shadow_power != 1)
return;
rc = usb_control_msg(mydev->udev,
usb_sndctrlpipe(mydev->udev, 0),
0x12,
0x48,
(82 * 0x100) + 10,
(mydev->mode_msb * 0x100) + mydev->mode_lsb,
NULL,
0,
2000);
if (rc < 0)
dev_dbg(&mydev->udev->dev, "mode retval = %d\n", rc);
}
static void update_display_visual(struct usb_sevsegdev *mydev, gfp_t mf)
{
int rc;
int i;
unsigned char *buffer;
u8 decimals = 0;
if(mydev->shadow_power != 1)
return;
buffer = kzalloc(MAXLEN, mf);
if (!buffer) {
dev_err(&mydev->udev->dev, "out of memory\n");
return;
}
for (i = 0; i < mydev->textlength; i++)
buffer[i] = mydev->text[mydev->textlength-1-i];
rc = usb_control_msg(mydev->udev,
usb_sndctrlpipe(mydev->udev, 0),
0x12,
0x48,
(85 * 0x100) + 10,
(0 * 0x100) + mydev->textmode,
buffer,
mydev->textlength,
2000);
if (rc < 0)
dev_dbg(&mydev->udev->dev, "write retval = %d\n", rc);
kfree(buffer);
for (i = 0; i < sizeof(mydev->decimals); i++)
decimals |= mydev->decimals[i] << i;
rc = usb_control_msg(mydev->udev,
usb_sndctrlpipe(mydev->udev, 0),
0x12,
0x48,
(86 * 0x100) + 10,
(0 * 0x100) + decimals,
NULL,
0,
2000);
if (rc < 0)
dev_dbg(&mydev->udev->dev, "decimal retval = %d\n", rc);
}
static ssize_t show_attr_text(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct usb_interface *intf = to_usb_interface(dev);
struct usb_sevsegdev *mydev = usb_get_intfdata(intf);
return snprintf(buf, mydev->textlength, "%s\n", mydev->text);
}
static ssize_t set_attr_text(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct usb_interface *intf = to_usb_interface(dev);
struct usb_sevsegdev *mydev = usb_get_intfdata(intf);
size_t end = my_memlen(buf, count);
if (end > sizeof(mydev->text))
return -EINVAL;
memset(mydev->text, 0, sizeof(mydev->text));
mydev->textlength = end;
if (end > 0)
memcpy(mydev->text, buf, end);
update_display_visual(mydev, GFP_KERNEL);
return count;
}
static ssize_t show_attr_decimals(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct usb_interface *intf = to_usb_interface(dev);
struct usb_sevsegdev *mydev = usb_get_intfdata(intf);
int i;
int pos;
for (i = 0; i < sizeof(mydev->decimals); i++) {
pos = sizeof(mydev->decimals) - 1 - i;
if (mydev->decimals[i] == 0)
buf[pos] = '0';
else if (mydev->decimals[i] == 1)
buf[pos] = '1';
else
buf[pos] = 'x';
}
buf[sizeof(mydev->decimals)] = '\n';
return sizeof(mydev->decimals) + 1;
}
static ssize_t set_attr_decimals(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct usb_interface *intf = to_usb_interface(dev);
struct usb_sevsegdev *mydev = usb_get_intfdata(intf);
size_t end = my_memlen(buf, count);
int i;
if (end > sizeof(mydev->decimals))
return -EINVAL;
for (i = 0; i < end; i++)
if (buf[i] != '0' && buf[i] != '1')
return -EINVAL;
memset(mydev->decimals, 0, sizeof(mydev->decimals));
for (i = 0; i < end; i++)
if (buf[i] == '1')
mydev->decimals[end-1-i] = 1;
update_display_visual(mydev, GFP_KERNEL);
return count;
}
static ssize_t show_attr_textmode(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct usb_interface *intf = to_usb_interface(dev);
struct usb_sevsegdev *mydev = usb_get_intfdata(intf);
int i;
buf[0] = 0;
for (i = 0; display_textmodes[i]; i++) {
if (mydev->textmode == i) {
strcat(buf, " [");
strcat(buf, display_textmodes[i]);
strcat(buf, "] ");
} else {
strcat(buf, " ");
strcat(buf, display_textmodes[i]);
strcat(buf, " ");
}
}
strcat(buf, "\n");
return strlen(buf);
}
static ssize_t set_attr_textmode(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct usb_interface *intf = to_usb_interface(dev);
struct usb_sevsegdev *mydev = usb_get_intfdata(intf);
int i;
for (i = 0; display_textmodes[i]; i++) {
if (sysfs_streq(display_textmodes[i], buf)) {
mydev->textmode = i;
update_display_visual(mydev, GFP_KERNEL);
return count;
}
}
return -EINVAL;
}
static int sevseg_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(interface);
struct usb_sevsegdev *mydev = NULL;
int rc = -ENOMEM;
mydev = kzalloc(sizeof(struct usb_sevsegdev), GFP_KERNEL);
if (mydev == NULL) {
dev_err(&interface->dev, "Out of memory\n");
goto error_mem;
}
mydev->udev = usb_get_dev(udev);
mydev->intf = interface;
usb_set_intfdata(interface, mydev);
mydev->shadow_power = 1;
mydev->has_interface_pm = 0;
mydev->textmode = 0x02;
mydev->mode_msb = 0x06;
mydev->mode_lsb = 0x3f;
rc = sysfs_create_group(&interface->dev.kobj, &dev_attr_grp);
if (rc)
goto error;
dev_info(&interface->dev, "USB 7 Segment device now attached\n");
return 0;
error:
usb_set_intfdata(interface, NULL);
usb_put_dev(mydev->udev);
kfree(mydev);
error_mem:
return rc;
}
static void sevseg_disconnect(struct usb_interface *interface)
{
struct usb_sevsegdev *mydev;
mydev = usb_get_intfdata(interface);
sysfs_remove_group(&interface->dev.kobj, &dev_attr_grp);
usb_set_intfdata(interface, NULL);
usb_put_dev(mydev->udev);
kfree(mydev);
dev_info(&interface->dev, "USB 7 Segment now disconnected\n");
}
static int sevseg_suspend(struct usb_interface *intf, pm_message_t message)
{
struct usb_sevsegdev *mydev;
mydev = usb_get_intfdata(intf);
mydev->shadow_power = 0;
return 0;
}
static int sevseg_resume(struct usb_interface *intf)
{
struct usb_sevsegdev *mydev;
mydev = usb_get_intfdata(intf);
mydev->shadow_power = 1;
update_display_mode(mydev);
update_display_visual(mydev, GFP_NOIO);
return 0;
}
static int sevseg_reset_resume(struct usb_interface *intf)
{
struct usb_sevsegdev *mydev;
mydev = usb_get_intfdata(intf);
mydev->shadow_power = 1;
update_display_mode(mydev);
update_display_visual(mydev, GFP_NOIO);
return 0;
}
