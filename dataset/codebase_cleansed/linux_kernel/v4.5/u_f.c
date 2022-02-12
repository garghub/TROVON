struct usb_request *alloc_ep_req(struct usb_ep *ep, int len, int default_len)
{
struct usb_request *req;
req = usb_ep_alloc_request(ep, GFP_ATOMIC);
if (req) {
req->length = len ?: default_len;
req->buf = kmalloc(req->length, GFP_ATOMIC);
if (!req->buf) {
usb_ep_free_request(ep, req);
req = NULL;
}
}
return req;
}
