struct usb_request *alloc_ep_req(struct usb_ep *ep, size_t len)
{
struct usb_request *req;
req = usb_ep_alloc_request(ep, GFP_ATOMIC);
if (req) {
req->length = usb_endpoint_dir_out(ep->desc) ?
usb_ep_align(ep, len) : len;
req->buf = kmalloc(req->length, GFP_ATOMIC);
if (!req->buf) {
usb_ep_free_request(ep, req);
req = NULL;
}
}
return req;
}
