const char *usb_otg_state_string(enum usb_otg_state state)
{
static const char *const names[] = {
[OTG_STATE_A_IDLE] = "a_idle",
[OTG_STATE_A_WAIT_VRISE] = "a_wait_vrise",
[OTG_STATE_A_WAIT_BCON] = "a_wait_bcon",
[OTG_STATE_A_HOST] = "a_host",
[OTG_STATE_A_SUSPEND] = "a_suspend",
[OTG_STATE_A_PERIPHERAL] = "a_peripheral",
[OTG_STATE_A_WAIT_VFALL] = "a_wait_vfall",
[OTG_STATE_A_VBUS_ERR] = "a_vbus_err",
[OTG_STATE_B_IDLE] = "b_idle",
[OTG_STATE_B_SRP_INIT] = "b_srp_init",
[OTG_STATE_B_PERIPHERAL] = "b_peripheral",
[OTG_STATE_B_WAIT_ACON] = "b_wait_acon",
[OTG_STATE_B_HOST] = "b_host",
};
if (state < 0 || state >= ARRAY_SIZE(names))
return "UNDEFINED";
return names[state];
}
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
const char *usb_state_string(enum usb_device_state state)
{
static const char *const names[] = {
[USB_STATE_NOTATTACHED] = "not attached",
[USB_STATE_ATTACHED] = "attached",
[USB_STATE_POWERED] = "powered",
[USB_STATE_RECONNECTING] = "reconnecting",
[USB_STATE_UNAUTHENTICATED] = "unauthenticated",
[USB_STATE_DEFAULT] = "default",
[USB_STATE_ADDRESS] = "addresssed",
[USB_STATE_CONFIGURED] = "configured",
[USB_STATE_SUSPENDED] = "suspended",
};
if (state < 0 || state >= ARRAY_SIZE(names))
return "UNKNOWN";
return names[state];
}
