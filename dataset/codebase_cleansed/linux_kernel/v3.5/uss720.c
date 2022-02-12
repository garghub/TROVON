static void destroy_priv(struct kref *kref)
{
struct parport_uss720_private *priv = container_of(kref, struct parport_uss720_private, ref_count);
dev_dbg(&priv->usbdev->dev, "destroying priv datastructure\n");
usb_put_dev(priv->usbdev);
kfree(priv);
}
static void destroy_async(struct kref *kref)
{
struct uss720_async_request *rq = container_of(kref, struct uss720_async_request, ref_count);
struct parport_uss720_private *priv = rq->priv;
unsigned long flags;
if (likely(rq->urb))
usb_free_urb(rq->urb);
spin_lock_irqsave(&priv->asynclock, flags);
list_del_init(&rq->asynclist);
spin_unlock_irqrestore(&priv->asynclock, flags);
kfree(rq);
kref_put(&priv->ref_count, destroy_priv);
}
static void async_complete(struct urb *urb)
{
struct uss720_async_request *rq;
struct parport *pp;
struct parport_uss720_private *priv;
int status = urb->status;
rq = urb->context;
priv = rq->priv;
pp = priv->pp;
if (status) {
dev_err(&urb->dev->dev, "async_complete: urb error %d\n",
status);
} else if (rq->dr.bRequest == 3) {
memcpy(priv->reg, rq->reg, sizeof(priv->reg));
#if 0
dev_dbg(&priv->usbdev->dev,
"async_complete regs %02x %02x %02x %02x %02x %02x %02x\n",
(unsigned int)priv->reg[0], (unsigned int)priv->reg[1],
(unsigned int)priv->reg[2], (unsigned int)priv->reg[3],
(unsigned int)priv->reg[4], (unsigned int)priv->reg[5],
(unsigned int)priv->reg[6]);
#endif
if (rq->reg[2] & rq->reg[1] & 0x10 && pp)
parport_generic_irq(pp);
}
complete(&rq->compl);
kref_put(&rq->ref_count, destroy_async);
}
static struct uss720_async_request *submit_async_request(struct parport_uss720_private *priv,
__u8 request, __u8 requesttype, __u16 value, __u16 index,
gfp_t mem_flags)
{
struct usb_device *usbdev;
struct uss720_async_request *rq;
unsigned long flags;
int ret;
if (!priv)
return NULL;
usbdev = priv->usbdev;
if (!usbdev)
return NULL;
rq = kmalloc(sizeof(struct uss720_async_request), mem_flags);
if (!rq) {
dev_err(&usbdev->dev, "submit_async_request out of memory\n");
return NULL;
}
kref_init(&rq->ref_count);
INIT_LIST_HEAD(&rq->asynclist);
init_completion(&rq->compl);
kref_get(&priv->ref_count);
rq->priv = priv;
rq->urb = usb_alloc_urb(0, mem_flags);
if (!rq->urb) {
kref_put(&rq->ref_count, destroy_async);
dev_err(&usbdev->dev, "submit_async_request out of memory\n");
return NULL;
}
rq->dr.bRequestType = requesttype;
rq->dr.bRequest = request;
rq->dr.wValue = cpu_to_le16(value);
rq->dr.wIndex = cpu_to_le16(index);
rq->dr.wLength = cpu_to_le16((request == 3) ? sizeof(rq->reg) : 0);
usb_fill_control_urb(rq->urb, usbdev, (requesttype & 0x80) ? usb_rcvctrlpipe(usbdev, 0) : usb_sndctrlpipe(usbdev, 0),
(unsigned char *)&rq->dr,
(request == 3) ? rq->reg : NULL, (request == 3) ? sizeof(rq->reg) : 0, async_complete, rq);
spin_lock_irqsave(&priv->asynclock, flags);
list_add_tail(&rq->asynclist, &priv->asynclist);
spin_unlock_irqrestore(&priv->asynclock, flags);
kref_get(&rq->ref_count);
ret = usb_submit_urb(rq->urb, mem_flags);
if (!ret)
return rq;
destroy_async(&rq->ref_count);
dev_err(&usbdev->dev, "submit_async_request submit_urb failed with %d\n", ret);
return NULL;
}
static unsigned int kill_all_async_requests_priv(struct parport_uss720_private *priv)
{
struct uss720_async_request *rq;
unsigned long flags;
unsigned int ret = 0;
spin_lock_irqsave(&priv->asynclock, flags);
list_for_each_entry(rq, &priv->asynclist, asynclist) {
usb_unlink_urb(rq->urb);
ret++;
}
spin_unlock_irqrestore(&priv->asynclock, flags);
return ret;
}
static int get_1284_register(struct parport *pp, unsigned char reg, unsigned char *val, gfp_t mem_flags)
{
struct parport_uss720_private *priv;
struct uss720_async_request *rq;
static const unsigned char regindex[9] = {
4, 0, 1, 5, 5, 0, 2, 3, 6
};
int ret;
if (!pp)
return -EIO;
priv = pp->private_data;
rq = submit_async_request(priv, 3, 0xc0, ((unsigned int)reg) << 8, 0, mem_flags);
if (!rq) {
dev_err(&priv->usbdev->dev, "get_1284_register(%u) failed",
(unsigned int)reg);
return -EIO;
}
if (!val) {
kref_put(&rq->ref_count, destroy_async);
return 0;
}
if (wait_for_completion_timeout(&rq->compl, HZ)) {
ret = rq->urb->status;
*val = priv->reg[(reg >= 9) ? 0 : regindex[reg]];
if (ret)
printk(KERN_WARNING "get_1284_register: "
"usb error %d\n", ret);
kref_put(&rq->ref_count, destroy_async);
return ret;
}
printk(KERN_WARNING "get_1284_register timeout\n");
kill_all_async_requests_priv(priv);
return -EIO;
}
static int set_1284_register(struct parport *pp, unsigned char reg, unsigned char val, gfp_t mem_flags)
{
struct parport_uss720_private *priv;
struct uss720_async_request *rq;
if (!pp)
return -EIO;
priv = pp->private_data;
rq = submit_async_request(priv, 4, 0x40, (((unsigned int)reg) << 8) | val, 0, mem_flags);
if (!rq) {
dev_err(&priv->usbdev->dev, "set_1284_register(%u,%u) failed",
(unsigned int)reg, (unsigned int)val);
return -EIO;
}
kref_put(&rq->ref_count, destroy_async);
return 0;
}
static int change_mode(struct parport *pp, int m)
{
struct parport_uss720_private *priv = pp->private_data;
int mode;
__u8 reg;
if (get_1284_register(pp, 6, &reg, GFP_KERNEL))
return -EIO;
mode = (priv->reg[2] >> 5) & 0x7;
if (mode == m)
return 0;
if (mode > ECR_PS2 && m > ECR_PS2)
if (change_mode(pp, ECR_PS2))
return -EIO;
if (m <= ECR_PS2 && !(priv->reg[1] & 0x20)) {
unsigned long expire = jiffies + pp->physport->cad->timeout;
switch (mode) {
case ECR_PPF:
case ECR_ECP:
for (;;) {
if (get_1284_register(pp, 6, &reg, GFP_KERNEL))
return -EIO;
if (priv->reg[2] & 0x01)
break;
if (time_after_eq (jiffies, expire))
return -EBUSY;
msleep_interruptible(10);
if (signal_pending (current))
break;
}
}
}
if (set_1284_register(pp, 6, m << 5, GFP_KERNEL))
return -EIO;
if (get_1284_register(pp, 6, &reg, GFP_KERNEL))
return -EIO;
return 0;
}
static int clear_epp_timeout(struct parport *pp)
{
unsigned char stat;
if (get_1284_register(pp, 1, &stat, GFP_KERNEL))
return 1;
return stat & 1;
}
static void parport_uss720_write_data(struct parport *pp, unsigned char d)
{
set_1284_register(pp, 0, d, GFP_KERNEL);
}
static unsigned char parport_uss720_read_data(struct parport *pp)
{
unsigned char ret;
if (get_1284_register(pp, 0, &ret, GFP_KERNEL))
return 0;
return ret;
}
static void parport_uss720_write_control(struct parport *pp, unsigned char d)
{
struct parport_uss720_private *priv = pp->private_data;
d = (d & 0xf) | (priv->reg[1] & 0xf0);
if (set_1284_register(pp, 2, d, GFP_KERNEL))
return;
priv->reg[1] = d;
}
static unsigned char parport_uss720_read_control(struct parport *pp)
{
struct parport_uss720_private *priv = pp->private_data;
return priv->reg[1] & 0xf;
}
static unsigned char parport_uss720_frob_control(struct parport *pp, unsigned char mask, unsigned char val)
{
struct parport_uss720_private *priv = pp->private_data;
unsigned char d;
mask &= 0x0f;
val &= 0x0f;
d = (priv->reg[1] & (~mask)) ^ val;
if (set_1284_register(pp, 2, d, GFP_KERNEL))
return 0;
priv->reg[1] = d;
return d & 0xf;
}
static unsigned char parport_uss720_read_status(struct parport *pp)
{
unsigned char ret;
if (get_1284_register(pp, 1, &ret, GFP_KERNEL))
return 0;
return ret & 0xf8;
}
static void parport_uss720_disable_irq(struct parport *pp)
{
struct parport_uss720_private *priv = pp->private_data;
unsigned char d;
d = priv->reg[1] & ~0x10;
if (set_1284_register(pp, 2, d, GFP_KERNEL))
return;
priv->reg[1] = d;
}
static void parport_uss720_enable_irq(struct parport *pp)
{
struct parport_uss720_private *priv = pp->private_data;
unsigned char d;
d = priv->reg[1] | 0x10;
if (set_1284_register(pp, 2, d, GFP_KERNEL))
return;
priv->reg[1] = d;
}
static void parport_uss720_data_forward (struct parport *pp)
{
struct parport_uss720_private *priv = pp->private_data;
unsigned char d;
d = priv->reg[1] & ~0x20;
if (set_1284_register(pp, 2, d, GFP_KERNEL))
return;
priv->reg[1] = d;
}
static void parport_uss720_data_reverse (struct parport *pp)
{
struct parport_uss720_private *priv = pp->private_data;
unsigned char d;
d = priv->reg[1] | 0x20;
if (set_1284_register(pp, 2, d, GFP_KERNEL))
return;
priv->reg[1] = d;
}
static void parport_uss720_init_state(struct pardevice *dev, struct parport_state *s)
{
s->u.pc.ctr = 0xc | (dev->irq_func ? 0x10 : 0x0);
s->u.pc.ecr = 0x24;
}
static void parport_uss720_save_state(struct parport *pp, struct parport_state *s)
{
struct parport_uss720_private *priv = pp->private_data;
#if 0
if (get_1284_register(pp, 2, NULL, GFP_ATOMIC))
return;
#endif
s->u.pc.ctr = priv->reg[1];
s->u.pc.ecr = priv->reg[2];
}
static void parport_uss720_restore_state(struct parport *pp, struct parport_state *s)
{
struct parport_uss720_private *priv = pp->private_data;
set_1284_register(pp, 2, s->u.pc.ctr, GFP_ATOMIC);
set_1284_register(pp, 6, s->u.pc.ecr, GFP_ATOMIC);
get_1284_register(pp, 2, NULL, GFP_ATOMIC);
priv->reg[1] = s->u.pc.ctr;
priv->reg[2] = s->u.pc.ecr;
}
static size_t parport_uss720_epp_read_data(struct parport *pp, void *buf, size_t length, int flags)
{
struct parport_uss720_private *priv = pp->private_data;
size_t got = 0;
if (change_mode(pp, ECR_EPP))
return 0;
for (; got < length; got++) {
if (get_1284_register(pp, 4, (char *)buf, GFP_KERNEL))
break;
buf++;
if (priv->reg[0] & 0x01) {
clear_epp_timeout(pp);
break;
}
}
change_mode(pp, ECR_PS2);
return got;
}
static size_t parport_uss720_epp_write_data(struct parport *pp, const void *buf, size_t length, int flags)
{
#if 0
struct parport_uss720_private *priv = pp->private_data;
size_t written = 0;
if (change_mode(pp, ECR_EPP))
return 0;
for (; written < length; written++) {
if (set_1284_register(pp, 4, (char *)buf, GFP_KERNEL))
break;
((char*)buf)++;
if (get_1284_register(pp, 1, NULL, GFP_KERNEL))
break;
if (priv->reg[0] & 0x01) {
clear_epp_timeout(pp);
break;
}
}
change_mode(pp, ECR_PS2);
return written;
#else
struct parport_uss720_private *priv = pp->private_data;
struct usb_device *usbdev = priv->usbdev;
int rlen;
int i;
if (!usbdev)
return 0;
if (change_mode(pp, ECR_EPP))
return 0;
i = usb_bulk_msg(usbdev, usb_sndbulkpipe(usbdev, 1), (void *)buf, length, &rlen, 20000);
if (i)
printk(KERN_ERR "uss720: sendbulk ep 1 buf %p len %Zu rlen %u\n", buf, length, rlen);
change_mode(pp, ECR_PS2);
return rlen;
#endif
}
static size_t parport_uss720_epp_read_addr(struct parport *pp, void *buf, size_t length, int flags)
{
struct parport_uss720_private *priv = pp->private_data;
size_t got = 0;
if (change_mode(pp, ECR_EPP))
return 0;
for (; got < length; got++) {
if (get_1284_register(pp, 3, (char *)buf, GFP_KERNEL))
break;
buf++;
if (priv->reg[0] & 0x01) {
clear_epp_timeout(pp);
break;
}
}
change_mode(pp, ECR_PS2);
return got;
}
static size_t parport_uss720_epp_write_addr(struct parport *pp, const void *buf, size_t length, int flags)
{
struct parport_uss720_private *priv = pp->private_data;
size_t written = 0;
if (change_mode(pp, ECR_EPP))
return 0;
for (; written < length; written++) {
if (set_1284_register(pp, 3, *(char *)buf, GFP_KERNEL))
break;
buf++;
if (get_1284_register(pp, 1, NULL, GFP_KERNEL))
break;
if (priv->reg[0] & 0x01) {
clear_epp_timeout(pp);
break;
}
}
change_mode(pp, ECR_PS2);
return written;
}
static size_t parport_uss720_ecp_write_data(struct parport *pp, const void *buffer, size_t len, int flags)
{
struct parport_uss720_private *priv = pp->private_data;
struct usb_device *usbdev = priv->usbdev;
int rlen;
int i;
if (!usbdev)
return 0;
if (change_mode(pp, ECR_ECP))
return 0;
i = usb_bulk_msg(usbdev, usb_sndbulkpipe(usbdev, 1), (void *)buffer, len, &rlen, 20000);
if (i)
printk(KERN_ERR "uss720: sendbulk ep 1 buf %p len %Zu rlen %u\n", buffer, len, rlen);
change_mode(pp, ECR_PS2);
return rlen;
}
static size_t parport_uss720_ecp_read_data(struct parport *pp, void *buffer, size_t len, int flags)
{
struct parport_uss720_private *priv = pp->private_data;
struct usb_device *usbdev = priv->usbdev;
int rlen;
int i;
if (!usbdev)
return 0;
if (change_mode(pp, ECR_ECP))
return 0;
i = usb_bulk_msg(usbdev, usb_rcvbulkpipe(usbdev, 2), buffer, len, &rlen, 20000);
if (i)
printk(KERN_ERR "uss720: recvbulk ep 2 buf %p len %Zu rlen %u\n", buffer, len, rlen);
change_mode(pp, ECR_PS2);
return rlen;
}
static size_t parport_uss720_ecp_write_addr(struct parport *pp, const void *buffer, size_t len, int flags)
{
size_t written = 0;
if (change_mode(pp, ECR_ECP))
return 0;
for (; written < len; written++) {
if (set_1284_register(pp, 5, *(char *)buffer, GFP_KERNEL))
break;
buffer++;
}
change_mode(pp, ECR_PS2);
return written;
}
static size_t parport_uss720_write_compat(struct parport *pp, const void *buffer, size_t len, int flags)
{
struct parport_uss720_private *priv = pp->private_data;
struct usb_device *usbdev = priv->usbdev;
int rlen;
int i;
if (!usbdev)
return 0;
if (change_mode(pp, ECR_PPF))
return 0;
i = usb_bulk_msg(usbdev, usb_sndbulkpipe(usbdev, 1), (void *)buffer, len, &rlen, 20000);
if (i)
printk(KERN_ERR "uss720: sendbulk ep 1 buf %p len %Zu rlen %u\n", buffer, len, rlen);
change_mode(pp, ECR_PS2);
return rlen;
}
static int uss720_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *usbdev = usb_get_dev(interface_to_usbdev(intf));
struct usb_host_interface *interface;
struct usb_host_endpoint *endpoint;
struct parport_uss720_private *priv;
struct parport *pp;
unsigned char reg;
int i;
dev_dbg(&intf->dev, "probe: vendor id 0x%x, device id 0x%x\n",
le16_to_cpu(usbdev->descriptor.idVendor),
le16_to_cpu(usbdev->descriptor.idProduct));
if (intf->num_altsetting != 3) {
usb_put_dev(usbdev);
return -ENODEV;
}
i = usb_set_interface(usbdev, intf->altsetting->desc.bInterfaceNumber, 2);
dev_dbg(&intf->dev, "set inteface result %d\n", i);
interface = intf->cur_altsetting;
if (!(priv = kzalloc(sizeof(struct parport_uss720_private), GFP_KERNEL))) {
usb_put_dev(usbdev);
return -ENOMEM;
}
priv->pp = NULL;
priv->usbdev = usbdev;
kref_init(&priv->ref_count);
spin_lock_init(&priv->asynclock);
INIT_LIST_HEAD(&priv->asynclist);
if (!(pp = parport_register_port(0, PARPORT_IRQ_NONE, PARPORT_DMA_NONE, &parport_uss720_ops))) {
printk(KERN_WARNING "uss720: could not register parport\n");
goto probe_abort;
}
priv->pp = pp;
pp->private_data = priv;
pp->modes = PARPORT_MODE_PCSPP | PARPORT_MODE_TRISTATE | PARPORT_MODE_EPP | PARPORT_MODE_ECP | PARPORT_MODE_COMPAT;
set_1284_register(pp, 7, 0x00, GFP_KERNEL);
set_1284_register(pp, 6, 0x30, GFP_KERNEL);
set_1284_register(pp, 2, 0x0c, GFP_KERNEL);
get_1284_register(pp, 0, &reg, GFP_KERNEL);
dev_dbg(&intf->dev, "reg: %02x %02x %02x %02x %02x %02x %02x\n",
priv->reg[0], priv->reg[1], priv->reg[2], priv->reg[3],
priv->reg[4], priv->reg[5], priv->reg[6]);
endpoint = &interface->endpoint[2];
dev_dbg(&intf->dev, "epaddr %d interval %d\n",
endpoint->desc.bEndpointAddress, endpoint->desc.bInterval);
parport_announce_port(pp);
usb_set_intfdata(intf, pp);
return 0;
probe_abort:
kill_all_async_requests_priv(priv);
kref_put(&priv->ref_count, destroy_priv);
return -ENODEV;
}
static void uss720_disconnect(struct usb_interface *intf)
{
struct parport *pp = usb_get_intfdata(intf);
struct parport_uss720_private *priv;
struct usb_device *usbdev;
dev_dbg(&intf->dev, "disconnect\n");
usb_set_intfdata(intf, NULL);
if (pp) {
priv = pp->private_data;
usbdev = priv->usbdev;
priv->usbdev = NULL;
priv->pp = NULL;
dev_dbg(&intf->dev, "parport_remove_port\n");
parport_remove_port(pp);
parport_put_port(pp);
kill_all_async_requests_priv(priv);
kref_put(&priv->ref_count, destroy_priv);
}
dev_dbg(&intf->dev, "disconnect done\n");
}
static int __init uss720_init(void)
{
int retval;
retval = usb_register(&uss720_driver);
if (retval)
goto out;
printk(KERN_INFO KBUILD_MODNAME ": " DRIVER_VERSION ":"
DRIVER_DESC "\n");
printk(KERN_INFO KBUILD_MODNAME ": NOTE: this is a special purpose "
"driver to allow nonstandard\n");
printk(KERN_INFO KBUILD_MODNAME ": protocols (eg. bitbang) over "
"USS720 usb to parallel cables\n");
printk(KERN_INFO KBUILD_MODNAME ": If you just want to connect to a "
"printer, use usblp instead\n");
out:
return retval;
}
static void __exit uss720_cleanup(void)
{
usb_deregister(&uss720_driver);
}
