struct usb_ep *usb_ep_autoconfig_ss(
struct usb_gadget *gadget,
struct usb_endpoint_descriptor *desc,
struct usb_ss_ep_comp_descriptor *ep_comp
)
{
struct usb_ep *ep;
u8 type;
type = desc->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK;
if (gadget->ops->match_ep) {
ep = gadget->ops->match_ep(gadget, desc, ep_comp);
if (ep)
goto found_ep;
}
list_for_each_entry (ep, &gadget->ep_list, ep_list) {
if (usb_gadget_ep_match_desc(gadget, ep, desc, ep_comp))
goto found_ep;
}
return NULL;
found_ep:
if (desc->wMaxPacketSize == 0)
desc->wMaxPacketSize = cpu_to_le16(ep->maxpacket_limit);
desc->bEndpointAddress &= USB_DIR_IN;
if (isdigit(ep->name[2])) {
u8 num = simple_strtoul(&ep->name[2], NULL, 10);
desc->bEndpointAddress |= num;
} else if (desc->bEndpointAddress & USB_DIR_IN) {
if (++gadget->in_epnum > 15)
return NULL;
desc->bEndpointAddress = USB_DIR_IN | gadget->in_epnum;
} else {
if (++gadget->out_epnum > 15)
return NULL;
desc->bEndpointAddress |= gadget->out_epnum;
}
if ((type == USB_ENDPOINT_XFER_BULK) && !ep_comp) {
int size = ep->maxpacket_limit;
if (size > 64)
size = 64;
desc->wMaxPacketSize = cpu_to_le16(size);
}
ep->address = desc->bEndpointAddress;
ep->desc = NULL;
ep->comp_desc = NULL;
ep->claimed = true;
return ep;
}
struct usb_ep *usb_ep_autoconfig(
struct usb_gadget *gadget,
struct usb_endpoint_descriptor *desc
)
{
return usb_ep_autoconfig_ss(gadget, desc, NULL);
}
void usb_ep_autoconfig_release(struct usb_ep *ep)
{
ep->claimed = false;
ep->driver_data = NULL;
}
void usb_ep_autoconfig_reset (struct usb_gadget *gadget)
{
struct usb_ep *ep;
list_for_each_entry (ep, &gadget->ep_list, ep_list) {
ep->claimed = false;
ep->driver_data = NULL;
}
gadget->in_epnum = 0;
gadget->out_epnum = 0;
}
