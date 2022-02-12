static void change_color(struct usb_led *led)
{
int retval = 0;
unsigned char *buffer;
int actlength;
buffer = kmalloc(8, GFP_KERNEL);
if (!buffer) {
dev_err(&led->udev->dev, "out of memory\n");
return;
}
switch (led->type) {
case DELCOM_VISUAL_SIGNAL_INDICATOR: {
unsigned char color = 0x07;
if (led->blue)
color &= ~0x04;
if (led->red)
color &= ~0x02;
if (led->green)
color &= ~0x01;
dev_dbg(&led->udev->dev,
"blue = %d, red = %d, green = %d, color = %.2x\n",
led->blue, led->red, led->green, color);
retval = usb_control_msg(led->udev,
usb_sndctrlpipe(led->udev, 0),
0x12,
0xc8,
(0x02 * 0x100) + 0x0a,
(0x00 * 0x100) + color,
buffer,
8,
2000);
break;
}
case DREAM_CHEEKY_WEBMAIL_NOTIFIER:
dev_dbg(&led->udev->dev,
"red = %d, green = %d, blue = %d\n",
led->red, led->green, led->blue);
buffer[0] = led->red;
buffer[1] = led->green;
buffer[2] = led->blue;
buffer[3] = buffer[4] = buffer[5] = 0;
buffer[6] = 0x1a;
buffer[7] = 0x05;
retval = usb_control_msg(led->udev,
usb_sndctrlpipe(led->udev, 0),
0x09,
0x21,
0x200,
0,
buffer,
8,
2000);
break;
case RISO_KAGAKU_LED:
buffer[0] = RISO_KAGAKU_IX(led->red, led->green, led->blue);
buffer[1] = 0;
buffer[2] = 0;
buffer[3] = 0;
buffer[4] = 0;
retval = usb_interrupt_msg(led->udev,
usb_sndctrlpipe(led->udev, 2),
buffer, 5, &actlength, 1000 );
break;
default:
dev_err(&led->udev->dev, "unknown device type %d\n", led->type);
}
if (retval)
dev_dbg(&led->udev->dev, "retval = %d\n", retval);
kfree(buffer);
}
static int led_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(interface);
struct usb_led *dev = NULL;
int retval = -ENOMEM;
dev = kzalloc(sizeof(struct usb_led), GFP_KERNEL);
if (dev == NULL) {
dev_err(&interface->dev, "out of memory\n");
goto error_mem;
}
dev->udev = usb_get_dev(udev);
dev->type = id->driver_info;
usb_set_intfdata(interface, dev);
retval = device_create_file(&interface->dev, &dev_attr_blue);
if (retval)
goto error;
retval = device_create_file(&interface->dev, &dev_attr_red);
if (retval)
goto error;
retval = device_create_file(&interface->dev, &dev_attr_green);
if (retval)
goto error;
if (dev->type == DREAM_CHEEKY_WEBMAIL_NOTIFIER) {
unsigned char *enable;
enable = kmemdup("\x1f\x02\0\x5f\0\0\x1a\x03", 8, GFP_KERNEL);
if (!enable) {
dev_err(&interface->dev, "out of memory\n");
retval = -ENOMEM;
goto error;
}
retval = usb_control_msg(udev,
usb_sndctrlpipe(udev, 0),
0x09,
0x21,
0x200,
0,
enable,
8,
2000);
kfree(enable);
if (retval != 8)
goto error;
}
dev_info(&interface->dev, "USB LED device now attached\n");
return 0;
error:
device_remove_file(&interface->dev, &dev_attr_blue);
device_remove_file(&interface->dev, &dev_attr_red);
device_remove_file(&interface->dev, &dev_attr_green);
usb_set_intfdata(interface, NULL);
usb_put_dev(dev->udev);
kfree(dev);
error_mem:
return retval;
}
static void led_disconnect(struct usb_interface *interface)
{
struct usb_led *dev;
dev = usb_get_intfdata(interface);
device_remove_file(&interface->dev, &dev_attr_blue);
device_remove_file(&interface->dev, &dev_attr_red);
device_remove_file(&interface->dev, &dev_attr_green);
usb_set_intfdata(interface, NULL);
usb_put_dev(dev->udev);
kfree(dev);
dev_info(&interface->dev, "USB LED now disconnected\n");
}
