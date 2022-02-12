const char *usb_speed_string(enum usb_device_speed speed)
{
static const char *const names[] = {
[USB_SPEED_UNKNOWN] = "UNKNOWN",
[USB_SPEED_LOW] = "low-speed",
[USB_SPEED_FULL] = "full-speed",
[USB_SPEED_HIGH] = "high-speed",
[USB_SPEED_WIRELESS] = "wireless",
[USB_SPEED_SUPER] = "super-speed",
};
if (speed < 0 || speed >= ARRAY_SIZE(names))
speed = USB_SPEED_UNKNOWN;
return names[speed];
}
