int wa_create(struct wahc *wa, struct usb_interface *iface,
kernel_ulong_t quirks)
{
int result;
struct device *dev = &iface->dev;
if (iface->cur_altsetting->desc.bNumEndpoints < 3)
return -ENODEV;
result = wa_rpipes_create(wa);
if (result < 0)
goto error_rpipes_create;
wa->quirks = quirks;
wa->dti_epd = &iface->cur_altsetting->endpoint[1].desc;
wa->dto_epd = &iface->cur_altsetting->endpoint[2].desc;
wa->dti_buf_size = usb_endpoint_maxp(wa->dti_epd);
wa->dti_buf = kmalloc(wa->dti_buf_size, GFP_KERNEL);
if (wa->dti_buf == NULL) {
result = -ENOMEM;
goto error_dti_buf_alloc;
}
result = wa_nep_create(wa, iface);
if (result < 0) {
dev_err(dev, "WA-CDS: can't initialize notif endpoint: %d\n",
result);
goto error_nep_create;
}
return 0;
error_nep_create:
kfree(wa->dti_buf);
error_dti_buf_alloc:
wa_rpipes_destroy(wa);
error_rpipes_create:
return result;
}
void __wa_destroy(struct wahc *wa)
{
if (wa->dti_urb) {
usb_kill_urb(wa->dti_urb);
usb_put_urb(wa->dti_urb);
}
kfree(wa->dti_buf);
wa_nep_destroy(wa);
wa_rpipes_destroy(wa);
}
void wa_reset_all(struct wahc *wa)
{
wusbhc_reset_all(wa->wusb);
}
