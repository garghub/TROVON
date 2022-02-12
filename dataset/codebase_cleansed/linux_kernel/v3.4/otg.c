struct usb_phy *usb_get_transceiver(void)
{
if (phy)
get_device(phy->dev);
return phy;
}
void usb_put_transceiver(struct usb_phy *x)
{
if (x)
put_device(x->dev);
}
int usb_set_transceiver(struct usb_phy *x)
{
if (phy && x)
return -EBUSY;
phy = x;
return 0;
}
const char *otg_state_string(enum usb_otg_state state)
{
switch (state) {
case OTG_STATE_A_IDLE:
return "a_idle";
case OTG_STATE_A_WAIT_VRISE:
return "a_wait_vrise";
case OTG_STATE_A_WAIT_BCON:
return "a_wait_bcon";
case OTG_STATE_A_HOST:
return "a_host";
case OTG_STATE_A_SUSPEND:
return "a_suspend";
case OTG_STATE_A_PERIPHERAL:
return "a_peripheral";
case OTG_STATE_A_WAIT_VFALL:
return "a_wait_vfall";
case OTG_STATE_A_VBUS_ERR:
return "a_vbus_err";
case OTG_STATE_B_IDLE:
return "b_idle";
case OTG_STATE_B_SRP_INIT:
return "b_srp_init";
case OTG_STATE_B_PERIPHERAL:
return "b_peripheral";
case OTG_STATE_B_WAIT_ACON:
return "b_wait_acon";
case OTG_STATE_B_HOST:
return "b_host";
default:
return "UNDEFINED";
}
}
