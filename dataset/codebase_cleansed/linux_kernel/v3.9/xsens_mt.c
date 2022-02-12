static int has_required_endpoints(const struct usb_host_interface *interface)
{
__u8 i;
int has_bulk_in = 0;
int has_bulk_out = 0;
for (i = 0; i < interface->desc.bNumEndpoints; ++i) {
if (usb_endpoint_is_bulk_in(&interface->endpoint[i].desc))
has_bulk_in = 1;
else if (usb_endpoint_is_bulk_out(&interface->endpoint[i].desc))
has_bulk_out = 1;
}
return has_bulk_in && has_bulk_out;
}
static int xsens_mt_probe(struct usb_serial *serial,
const struct usb_device_id *id)
{
if (!has_required_endpoints(serial->interface->cur_altsetting))
return -ENODEV;
return 0;
}
