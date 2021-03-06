static inline unsigned tiocm_to_gigaset(unsigned state)
{
return ((state & TIOCM_DTR) ? 1 : 0) | ((state & TIOCM_RTS) ? 2 : 0);
}
static int gigaset_set_modem_ctrl(struct cardstate *cs, unsigned old_state,
unsigned new_state)
{
struct usb_device *udev = cs->hw.usb->udev;
unsigned mask, val;
int r;
mask = tiocm_to_gigaset(old_state ^ new_state);
val = tiocm_to_gigaset(new_state);
gig_dbg(DEBUG_USBREQ, "set flags 0x%02x with mask 0x%02x", val, mask);
r = usb_control_msg(udev, usb_sndctrlpipe(udev, 0), 7, 0x41,
(val & 0xff) | ((mask & 0xff) << 8), 0,
NULL, 0, 2000 );
if (r < 0)
return r;
return 0;
}
static int set_value(struct cardstate *cs, u8 req, u16 val)
{
struct usb_device *udev = cs->hw.usb->udev;
int r, r2;
gig_dbg(DEBUG_USBREQ, "request %02x (%04x)",
(unsigned)req, (unsigned)val);
r = usb_control_msg(udev, usb_sndctrlpipe(udev, 0), 0x12, 0x41,
0xf , 0, NULL, 0, 2000 );
if (r < 0) {
dev_err(&udev->dev, "error %d on request 0x12\n", -r);
return r;
}
r = usb_control_msg(udev, usb_sndctrlpipe(udev, 0), req, 0x41,
val, 0, NULL, 0, 2000 );
if (r < 0)
dev_err(&udev->dev, "error %d on request 0x%02x\n",
-r, (unsigned)req);
r2 = usb_control_msg(udev, usb_sndctrlpipe(udev, 0), 0x19, 0x41,
0, 0, cs->hw.usb->bchars, 6, 2000 );
if (r2 < 0)
dev_err(&udev->dev, "error %d on request 0x19\n", -r2);
return r < 0 ? r : (r2 < 0 ? r2 : 0);
}
static int gigaset_baud_rate(struct cardstate *cs, unsigned cflag)
{
u16 val;
u32 rate;
cflag &= CBAUD;
switch (cflag) {
case B300: rate = 300; break;
case B600: rate = 600; break;
case B1200: rate = 1200; break;
case B2400: rate = 2400; break;
case B4800: rate = 4800; break;
case B9600: rate = 9600; break;
case B19200: rate = 19200; break;
case B38400: rate = 38400; break;
case B57600: rate = 57600; break;
case B115200: rate = 115200; break;
default:
rate = 9600;
dev_err(cs->dev, "unsupported baudrate request 0x%x,"
" using default of B9600\n", cflag);
}
val = 0x383fff / rate + 1;
return set_value(cs, 1, val);
}
static int gigaset_set_line_ctrl(struct cardstate *cs, unsigned cflag)
{
u16 val = 0;
if (cflag & PARENB)
val |= (cflag & PARODD) ? 0x10 : 0x20;
switch (cflag & CSIZE) {
case CS5:
val |= 5 << 8; break;
case CS6:
val |= 6 << 8; break;
case CS7:
val |= 7 << 8; break;
case CS8:
val |= 8 << 8; break;
default:
dev_err(cs->dev, "CSIZE was not CS5-CS8, using default of 8\n");
val |= 8 << 8;
break;
}
if (cflag & CSTOPB) {
if ((cflag & CSIZE) == CS5)
val |= 1;
else
val |= 2;
}
return set_value(cs, 3, val);
}
static int gigaset_init_bchannel(struct bc_state *bcs)
{
gigaset_bchannel_up(bcs);
return 0;
}
static int gigaset_close_bchannel(struct bc_state *bcs)
{
gigaset_bchannel_down(bcs);
return 0;
}
static void gigaset_modem_fill(unsigned long data)
{
struct cardstate *cs = (struct cardstate *) data;
struct bc_state *bcs = &cs->bcs[0];
struct cmdbuf_t *cb;
int again;
gig_dbg(DEBUG_OUTPUT, "modem_fill");
if (cs->hw.usb->busy) {
gig_dbg(DEBUG_OUTPUT, "modem_fill: busy");
return;
}
do {
again = 0;
if (!bcs->tx_skb) {
cb = cs->cmdbuf;
if (cb) {
gig_dbg(DEBUG_OUTPUT, "modem_fill: cb");
if (send_cb(cs, cb) < 0) {
gig_dbg(DEBUG_OUTPUT,
"modem_fill: send_cb failed");
again = 1;
}
} else {
bcs->tx_skb = skb_dequeue(&bcs->squeue);
if (bcs->tx_skb)
gig_dbg(DEBUG_INTR,
"Dequeued skb (Adr: %lx)!",
(unsigned long) bcs->tx_skb);
}
}
if (bcs->tx_skb) {
gig_dbg(DEBUG_OUTPUT, "modem_fill: tx_skb");
if (write_modem(cs) < 0) {
gig_dbg(DEBUG_OUTPUT,
"modem_fill: write_modem failed");
again = 1;
}
}
} while (again);
}
static void gigaset_read_int_callback(struct urb *urb)
{
struct cardstate *cs = urb->context;
struct inbuf_t *inbuf = cs->inbuf;
int status = urb->status;
int r;
unsigned numbytes;
unsigned char *src;
unsigned long flags;
if (!status) {
numbytes = urb->actual_length;
if (numbytes) {
src = cs->hw.usb->rcvbuf;
if (unlikely(*src))
dev_warn(cs->dev,
"%s: There was no leading 0, but 0x%02x!\n",
__func__, (unsigned) *src);
++src;
--numbytes;
if (gigaset_fill_inbuf(inbuf, src, numbytes)) {
gig_dbg(DEBUG_INTR, "%s-->BH", __func__);
gigaset_schedule_event(inbuf->cs);
}
} else
gig_dbg(DEBUG_INTR, "Received zero block length");
} else {
gig_dbg(DEBUG_ANY, "%s - nonzero status received: %d",
__func__, status);
if (status == -ENOENT || status == -ESHUTDOWN)
return;
}
spin_lock_irqsave(&cs->lock, flags);
if (!cs->connected) {
spin_unlock_irqrestore(&cs->lock, flags);
pr_err("%s: disconnected\n", __func__);
return;
}
r = usb_submit_urb(urb, GFP_ATOMIC);
spin_unlock_irqrestore(&cs->lock, flags);
if (r)
dev_err(cs->dev, "error %d resubmitting URB\n", -r);
}
static void gigaset_write_bulk_callback(struct urb *urb)
{
struct cardstate *cs = urb->context;
int status = urb->status;
unsigned long flags;
switch (status) {
case 0:
break;
case -ENOENT:
gig_dbg(DEBUG_ANY, "%s: killed", __func__);
cs->hw.usb->busy = 0;
return;
default:
dev_err(cs->dev, "bulk transfer failed (status %d)\n",
-status);
}
spin_lock_irqsave(&cs->lock, flags);
if (!cs->connected) {
pr_err("%s: disconnected\n", __func__);
} else {
cs->hw.usb->busy = 0;
tasklet_schedule(&cs->write_tasklet);
}
spin_unlock_irqrestore(&cs->lock, flags);
}
static int send_cb(struct cardstate *cs, struct cmdbuf_t *cb)
{
struct cmdbuf_t *tcb;
unsigned long flags;
int count;
int status = -ENOENT;
struct usb_cardstate *ucs = cs->hw.usb;
do {
if (!cb->len) {
tcb = cb;
spin_lock_irqsave(&cs->cmdlock, flags);
cs->cmdbytes -= cs->curlen;
gig_dbg(DEBUG_OUTPUT, "send_cb: sent %u bytes, %u left",
cs->curlen, cs->cmdbytes);
cs->cmdbuf = cb = cb->next;
if (cb) {
cb->prev = NULL;
cs->curlen = cb->len;
} else {
cs->lastcmdbuf = NULL;
cs->curlen = 0;
}
spin_unlock_irqrestore(&cs->cmdlock, flags);
if (tcb->wake_tasklet)
tasklet_schedule(tcb->wake_tasklet);
kfree(tcb);
}
if (cb) {
count = min(cb->len, ucs->bulk_out_size);
gig_dbg(DEBUG_OUTPUT, "send_cb: send %d bytes", count);
usb_fill_bulk_urb(ucs->bulk_out_urb, ucs->udev,
usb_sndbulkpipe(ucs->udev,
ucs->bulk_out_endpointAddr & 0x0f),
cb->buf + cb->offset, count,
gigaset_write_bulk_callback, cs);
cb->offset += count;
cb->len -= count;
ucs->busy = 1;
spin_lock_irqsave(&cs->lock, flags);
status = cs->connected ?
usb_submit_urb(ucs->bulk_out_urb, GFP_ATOMIC) :
-ENODEV;
spin_unlock_irqrestore(&cs->lock, flags);
if (status) {
ucs->busy = 0;
dev_err(cs->dev,
"could not submit urb (error %d)\n",
-status);
cb->len = 0;
}
}
} while (cb && status);
return status;
}
static int gigaset_write_cmd(struct cardstate *cs, struct cmdbuf_t *cb)
{
unsigned long flags;
gigaset_dbg_buffer(cs->mstate != MS_LOCKED ?
DEBUG_TRANSCMD : DEBUG_LOCKCMD,
"CMD Transmit", cb->len, cb->buf);
spin_lock_irqsave(&cs->cmdlock, flags);
cb->prev = cs->lastcmdbuf;
if (cs->lastcmdbuf)
cs->lastcmdbuf->next = cb;
else {
cs->cmdbuf = cb;
cs->curlen = cb->len;
}
cs->cmdbytes += cb->len;
cs->lastcmdbuf = cb;
spin_unlock_irqrestore(&cs->cmdlock, flags);
spin_lock_irqsave(&cs->lock, flags);
if (cs->connected)
tasklet_schedule(&cs->write_tasklet);
spin_unlock_irqrestore(&cs->lock, flags);
return cb->len;
}
static int gigaset_write_room(struct cardstate *cs)
{
unsigned bytes;
bytes = cs->cmdbytes;
return bytes < IF_WRITEBUF ? IF_WRITEBUF - bytes : 0;
}
static int gigaset_chars_in_buffer(struct cardstate *cs)
{
return cs->cmdbytes;
}
static int gigaset_brkchars(struct cardstate *cs, const unsigned char buf[6])
{
struct usb_device *udev = cs->hw.usb->udev;
gigaset_dbg_buffer(DEBUG_USBREQ, "brkchars", 6, buf);
memcpy(cs->hw.usb->bchars, buf, 6);
return usb_control_msg(udev, usb_sndctrlpipe(udev, 0), 0x19, 0x41,
0, 0, &buf, 6, 2000);
}
static void gigaset_freebcshw(struct bc_state *bcs)
{
}
static int gigaset_initbcshw(struct bc_state *bcs)
{
bcs->hw.usb = NULL;
return 0;
}
static void gigaset_reinitbcshw(struct bc_state *bcs)
{
}
static void gigaset_freecshw(struct cardstate *cs)
{
tasklet_kill(&cs->write_tasklet);
kfree(cs->hw.usb);
}
static int gigaset_initcshw(struct cardstate *cs)
{
struct usb_cardstate *ucs;
cs->hw.usb = ucs =
kmalloc(sizeof(struct usb_cardstate), GFP_KERNEL);
if (!ucs) {
pr_err("out of memory\n");
return -ENOMEM;
}
ucs->bchars[0] = 0;
ucs->bchars[1] = 0;
ucs->bchars[2] = 0;
ucs->bchars[3] = 0;
ucs->bchars[4] = 0x11;
ucs->bchars[5] = 0x13;
ucs->bulk_out_buffer = NULL;
ucs->bulk_out_urb = NULL;
ucs->read_urb = NULL;
tasklet_init(&cs->write_tasklet,
gigaset_modem_fill, (unsigned long) cs);
return 0;
}
static int write_modem(struct cardstate *cs)
{
int ret = 0;
int count;
struct bc_state *bcs = &cs->bcs[0];
struct usb_cardstate *ucs = cs->hw.usb;
unsigned long flags;
gig_dbg(DEBUG_OUTPUT, "len: %d...", bcs->tx_skb->len);
if (!bcs->tx_skb->len) {
dev_kfree_skb_any(bcs->tx_skb);
bcs->tx_skb = NULL;
return -EINVAL;
}
count = min(bcs->tx_skb->len, (unsigned) ucs->bulk_out_size);
skb_copy_from_linear_data(bcs->tx_skb, ucs->bulk_out_buffer, count);
skb_pull(bcs->tx_skb, count);
ucs->busy = 1;
gig_dbg(DEBUG_OUTPUT, "write_modem: send %d bytes", count);
spin_lock_irqsave(&cs->lock, flags);
if (cs->connected) {
usb_fill_bulk_urb(ucs->bulk_out_urb, ucs->udev,
usb_sndbulkpipe(ucs->udev,
ucs->bulk_out_endpointAddr &
0x0f),
ucs->bulk_out_buffer, count,
gigaset_write_bulk_callback, cs);
ret = usb_submit_urb(ucs->bulk_out_urb, GFP_ATOMIC);
} else {
ret = -ENODEV;
}
spin_unlock_irqrestore(&cs->lock, flags);
if (ret) {
dev_err(cs->dev, "could not submit urb (error %d)\n", -ret);
ucs->busy = 0;
}
if (!bcs->tx_skb->len) {
gigaset_skb_sent(bcs, bcs->tx_skb);
gig_dbg(DEBUG_INTR, "kfree skb (Adr: %lx)!",
(unsigned long) bcs->tx_skb);
dev_kfree_skb_any(bcs->tx_skb);
bcs->tx_skb = NULL;
}
return ret;
}
static int gigaset_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
int retval;
struct usb_device *udev = interface_to_usbdev(interface);
struct usb_host_interface *hostif = interface->cur_altsetting;
struct cardstate *cs = NULL;
struct usb_cardstate *ucs = NULL;
struct usb_endpoint_descriptor *endpoint;
int buffer_size;
gig_dbg(DEBUG_ANY, "%s: Check if device matches ...", __func__);
if ((le16_to_cpu(udev->descriptor.idVendor) != USB_M105_VENDOR_ID) ||
(le16_to_cpu(udev->descriptor.idProduct) != USB_M105_PRODUCT_ID)) {
gig_dbg(DEBUG_ANY, "device ID (0x%x, 0x%x) not for me - skip",
le16_to_cpu(udev->descriptor.idVendor),
le16_to_cpu(udev->descriptor.idProduct));
return -ENODEV;
}
if (hostif->desc.bInterfaceNumber != 0) {
gig_dbg(DEBUG_ANY, "interface %d not for me - skip",
hostif->desc.bInterfaceNumber);
return -ENODEV;
}
if (hostif->desc.bAlternateSetting != 0) {
dev_notice(&udev->dev, "unsupported altsetting %d - skip",
hostif->desc.bAlternateSetting);
return -ENODEV;
}
if (hostif->desc.bInterfaceClass != 255) {
dev_notice(&udev->dev, "unsupported interface class %d - skip",
hostif->desc.bInterfaceClass);
return -ENODEV;
}
dev_info(&udev->dev, "%s: Device matched ... !\n", __func__);
cs = gigaset_initcs(driver, 1, 1, 0, cidmode, GIGASET_MODULENAME);
if (!cs)
return -ENODEV;
ucs = cs->hw.usb;
usb_get_dev(udev);
ucs->udev = udev;
ucs->interface = interface;
cs->dev = &interface->dev;
usb_set_intfdata(interface, cs);
endpoint = &hostif->endpoint[0].desc;
buffer_size = le16_to_cpu(endpoint->wMaxPacketSize);
ucs->bulk_out_size = buffer_size;
ucs->bulk_out_endpointAddr = endpoint->bEndpointAddress;
ucs->bulk_out_buffer = kmalloc(buffer_size, GFP_KERNEL);
if (!ucs->bulk_out_buffer) {
dev_err(cs->dev, "Couldn't allocate bulk_out_buffer\n");
retval = -ENOMEM;
goto error;
}
ucs->bulk_out_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!ucs->bulk_out_urb) {
dev_err(cs->dev, "Couldn't allocate bulk_out_urb\n");
retval = -ENOMEM;
goto error;
}
endpoint = &hostif->endpoint[1].desc;
ucs->busy = 0;
ucs->read_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!ucs->read_urb) {
dev_err(cs->dev, "No free urbs available\n");
retval = -ENOMEM;
goto error;
}
buffer_size = le16_to_cpu(endpoint->wMaxPacketSize);
ucs->rcvbuf_size = buffer_size;
ucs->int_in_endpointAddr = endpoint->bEndpointAddress;
ucs->rcvbuf = kmalloc(buffer_size, GFP_KERNEL);
if (!ucs->rcvbuf) {
dev_err(cs->dev, "Couldn't allocate rcvbuf\n");
retval = -ENOMEM;
goto error;
}
usb_fill_int_urb(ucs->read_urb, udev,
usb_rcvintpipe(udev,
endpoint->bEndpointAddress & 0x0f),
ucs->rcvbuf, buffer_size,
gigaset_read_int_callback,
cs, endpoint->bInterval);
retval = usb_submit_urb(ucs->read_urb, GFP_KERNEL);
if (retval) {
dev_err(cs->dev, "Could not submit URB (error %d)\n", -retval);
goto error;
}
if (startmode == SM_LOCKED)
cs->mstate = MS_LOCKED;
retval = gigaset_start(cs);
if (retval < 0) {
tasklet_kill(&cs->write_tasklet);
goto error;
}
return 0;
error:
usb_kill_urb(ucs->read_urb);
kfree(ucs->bulk_out_buffer);
usb_free_urb(ucs->bulk_out_urb);
kfree(ucs->rcvbuf);
usb_free_urb(ucs->read_urb);
usb_set_intfdata(interface, NULL);
ucs->read_urb = ucs->bulk_out_urb = NULL;
ucs->rcvbuf = ucs->bulk_out_buffer = NULL;
usb_put_dev(ucs->udev);
ucs->udev = NULL;
ucs->interface = NULL;
gigaset_freecs(cs);
return retval;
}
static void gigaset_disconnect(struct usb_interface *interface)
{
struct cardstate *cs;
struct usb_cardstate *ucs;
cs = usb_get_intfdata(interface);
ucs = cs->hw.usb;
dev_info(cs->dev, "disconnecting Gigaset USB adapter\n");
usb_kill_urb(ucs->read_urb);
gigaset_stop(cs);
usb_set_intfdata(interface, NULL);
tasklet_kill(&cs->write_tasklet);
usb_kill_urb(ucs->bulk_out_urb);
kfree(ucs->bulk_out_buffer);
usb_free_urb(ucs->bulk_out_urb);
kfree(ucs->rcvbuf);
usb_free_urb(ucs->read_urb);
ucs->read_urb = ucs->bulk_out_urb = NULL;
ucs->rcvbuf = ucs->bulk_out_buffer = NULL;
usb_put_dev(ucs->udev);
ucs->interface = NULL;
ucs->udev = NULL;
cs->dev = NULL;
gigaset_freecs(cs);
}
static int gigaset_suspend(struct usb_interface *intf, pm_message_t message)
{
struct cardstate *cs = usb_get_intfdata(intf);
cs->connected = 0;
usb_kill_urb(cs->hw.usb->read_urb);
tasklet_kill(&cs->write_tasklet);
usb_kill_urb(cs->hw.usb->bulk_out_urb);
gig_dbg(DEBUG_SUSPEND, "suspend complete");
return 0;
}
static int gigaset_resume(struct usb_interface *intf)
{
struct cardstate *cs = usb_get_intfdata(intf);
int rc;
cs->connected = 1;
rc = usb_submit_urb(cs->hw.usb->read_urb, GFP_KERNEL);
if (rc) {
dev_err(cs->dev, "Could not submit read URB (error %d)\n", -rc);
return rc;
}
gig_dbg(DEBUG_SUSPEND, "resume complete");
return 0;
}
static int gigaset_pre_reset(struct usb_interface *intf)
{
return gigaset_suspend(intf, PMSG_ON);
}
static int __init usb_gigaset_init(void)
{
int result;
driver = gigaset_initdriver(GIGASET_MINOR, GIGASET_MINORS,
GIGASET_MODULENAME, GIGASET_DEVNAME,
&ops, THIS_MODULE);
if (driver == NULL) {
result = -ENOMEM;
goto error;
}
result = usb_register(&gigaset_usb_driver);
if (result < 0) {
pr_err("error %d registering USB driver\n", -result);
goto error;
}
pr_info(DRIVER_DESC "\n");
return 0;
error:
if (driver)
gigaset_freedriver(driver);
driver = NULL;
return result;
}
static void __exit usb_gigaset_exit(void)
{
int i;
gigaset_blockdriver(driver);
for (i = 0; i < driver->minors; i++)
gigaset_shutdown(driver->cs + i);
usb_deregister(&gigaset_usb_driver);
gigaset_freedriver(driver);
driver = NULL;
}
