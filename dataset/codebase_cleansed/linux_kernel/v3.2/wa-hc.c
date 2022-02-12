int wa_create(struct wahc *wa, struct usb_interface *iface)
{
int result;
struct device *dev = &iface->dev;
result = wa_rpipes_create(wa);
if (result < 0)
goto error_rpipes_create;
wa->dti_epd = &iface->cur_altsetting->endpoint[1].desc;
wa->dto_epd = &iface->cur_altsetting->endpoint[2].desc;
wa->xfer_result_size = usb_endpoint_maxp(wa->dti_epd);
wa->xfer_result = kmalloc(wa->xfer_result_size, GFP_KERNEL);
if (wa->xfer_result == NULL)
goto error_xfer_result_alloc;
result = wa_nep_create(wa, iface);
if (result < 0) {
dev_err(dev, "WA-CDS: can't initialize notif endpoint: %d\n",
result);
goto error_nep_create;
}
return 0;
error_nep_create:
kfree(wa->xfer_result);
error_xfer_result_alloc:
wa_rpipes_destroy(wa);
error_rpipes_create:
return result;
}
void __wa_destroy(struct wahc *wa)
{
if (wa->dti_urb) {
usb_kill_urb(wa->dti_urb);
usb_put_urb(wa->dti_urb);
usb_kill_urb(wa->buf_in_urb);
usb_put_urb(wa->buf_in_urb);
}
kfree(wa->xfer_result);
wa_nep_destroy(wa);
wa_rpipes_destroy(wa);
}
void wa_reset_all(struct wahc *wa)
{
wusbhc_reset_all(wa->wusb);
}
