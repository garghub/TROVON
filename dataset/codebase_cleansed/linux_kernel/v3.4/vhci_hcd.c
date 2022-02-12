static void dump_port_status_diff(u32 prev_status, u32 new_status)
{
int i = 0;
u32 bit = 1;
pr_debug("status prev -> new: %08x -> %08x\n", prev_status, new_status);
while (bit) {
u32 prev = prev_status & bit;
u32 new = new_status & bit;
char change;
if (!prev && new)
change = '+';
else if (prev && !new)
change = '-';
else
change = ' ';
if (prev || new)
pr_debug(" %c%s\n", change, bit_desc[i]);
bit <<= 1;
i++;
}
pr_debug("\n");
}
void rh_port_connect(int rhport, enum usb_device_speed speed)
{
unsigned long flags;
usbip_dbg_vhci_rh("rh_port_connect %d\n", rhport);
spin_lock_irqsave(&the_controller->lock, flags);
the_controller->port_status[rhport] |= USB_PORT_STAT_CONNECTION
| (1 << USB_PORT_FEAT_C_CONNECTION);
switch (speed) {
case USB_SPEED_HIGH:
the_controller->port_status[rhport] |= USB_PORT_STAT_HIGH_SPEED;
break;
case USB_SPEED_LOW:
the_controller->port_status[rhport] |= USB_PORT_STAT_LOW_SPEED;
break;
default:
break;
}
spin_unlock_irqrestore(&the_controller->lock, flags);
usb_hcd_poll_rh_status(vhci_to_hcd(the_controller));
}
void rh_port_disconnect(int rhport)
{
unsigned long flags;
usbip_dbg_vhci_rh("rh_port_disconnect %d\n", rhport);
spin_lock_irqsave(&the_controller->lock, flags);
the_controller->port_status[rhport] &= ~USB_PORT_STAT_CONNECTION;
the_controller->port_status[rhport] |=
(1 << USB_PORT_FEAT_C_CONNECTION);
spin_unlock_irqrestore(&the_controller->lock, flags);
usb_hcd_poll_rh_status(vhci_to_hcd(the_controller));
}
static int vhci_hub_status(struct usb_hcd *hcd, char *buf)
{
struct vhci_hcd *vhci;
unsigned long flags;
int retval = 0;
unsigned long *event_bits = (unsigned long *) buf;
int rhport;
int changed = 0;
*event_bits = 0;
vhci = hcd_to_vhci(hcd);
spin_lock_irqsave(&vhci->lock, flags);
if (!HCD_HW_ACCESSIBLE(hcd)) {
usbip_dbg_vhci_rh("hw accessible flag in on?\n");
goto done;
}
for (rhport = 0; rhport < VHCI_NPORTS; rhport++) {
if ((vhci->port_status[rhport] & PORT_C_MASK)) {
usbip_dbg_vhci_rh("port %d is changed\n", rhport);
*event_bits |= 1 << (rhport + 1);
changed = 1;
}
}
pr_info("changed %d\n", changed);
if (hcd->state == HC_STATE_SUSPENDED)
usb_hcd_resume_root_hub(hcd);
if (changed)
retval = 1 + (VHCI_NPORTS / 8);
else
retval = 0;
done:
spin_unlock_irqrestore(&vhci->lock, flags);
return retval;
}
static inline void hub_descriptor(struct usb_hub_descriptor *desc)
{
memset(desc, 0, sizeof(*desc));
desc->bDescriptorType = 0x29;
desc->bDescLength = 9;
desc->wHubCharacteristics = (__force __u16)
(__constant_cpu_to_le16(0x0001));
desc->bNbrPorts = VHCI_NPORTS;
desc->u.hs.DeviceRemovable[0] = 0xff;
desc->u.hs.DeviceRemovable[1] = 0xff;
}
static int vhci_hub_control(struct usb_hcd *hcd, u16 typeReq, u16 wValue,
u16 wIndex, char *buf, u16 wLength)
{
struct vhci_hcd *dum;
int retval = 0;
unsigned long flags;
int rhport;
u32 prev_port_status[VHCI_NPORTS];
if (!HCD_HW_ACCESSIBLE(hcd))
return -ETIMEDOUT;
usbip_dbg_vhci_rh("typeReq %x wValue %x wIndex %x\n", typeReq, wValue,
wIndex);
if (wIndex > VHCI_NPORTS)
pr_err("invalid port number %d\n", wIndex);
rhport = ((__u8)(wIndex & 0x00ff)) - 1;
dum = hcd_to_vhci(hcd);
spin_lock_irqsave(&dum->lock, flags);
if (usbip_dbg_flag_vhci_rh) {
memcpy(prev_port_status, dum->port_status,
sizeof(prev_port_status));
}
switch (typeReq) {
case ClearHubFeature:
usbip_dbg_vhci_rh(" ClearHubFeature\n");
break;
case ClearPortFeature:
switch (wValue) {
case USB_PORT_FEAT_SUSPEND:
if (dum->port_status[rhport] & USB_PORT_STAT_SUSPEND) {
dum->resuming = 1;
dum->re_timeout =
jiffies + msecs_to_jiffies(20);
}
break;
case USB_PORT_FEAT_POWER:
usbip_dbg_vhci_rh(" ClearPortFeature: "
"USB_PORT_FEAT_POWER\n");
dum->port_status[rhport] = 0;
dum->resuming = 0;
break;
case USB_PORT_FEAT_C_RESET:
usbip_dbg_vhci_rh(" ClearPortFeature: "
"USB_PORT_FEAT_C_RESET\n");
switch (dum->vdev[rhport].speed) {
case USB_SPEED_HIGH:
dum->port_status[rhport] |=
USB_PORT_STAT_HIGH_SPEED;
break;
case USB_SPEED_LOW:
dum->port_status[rhport] |=
USB_PORT_STAT_LOW_SPEED;
break;
default:
break;
}
default:
usbip_dbg_vhci_rh(" ClearPortFeature: default %x\n",
wValue);
dum->port_status[rhport] &= ~(1 << wValue);
break;
}
break;
case GetHubDescriptor:
usbip_dbg_vhci_rh(" GetHubDescriptor\n");
hub_descriptor((struct usb_hub_descriptor *) buf);
break;
case GetHubStatus:
usbip_dbg_vhci_rh(" GetHubStatus\n");
*(__le32 *) buf = __constant_cpu_to_le32(0);
break;
case GetPortStatus:
usbip_dbg_vhci_rh(" GetPortStatus port %x\n", wIndex);
if (wIndex > VHCI_NPORTS || wIndex < 1) {
pr_err("invalid port number %d\n", wIndex);
retval = -EPIPE;
}
if (dum->resuming && time_after(jiffies, dum->re_timeout)) {
dum->port_status[rhport] |=
(1 << USB_PORT_FEAT_C_SUSPEND);
dum->port_status[rhport] &=
~(1 << USB_PORT_FEAT_SUSPEND);
dum->resuming = 0;
dum->re_timeout = 0;
}
if ((dum->port_status[rhport] & (1 << USB_PORT_FEAT_RESET)) !=
0 && time_after(jiffies, dum->re_timeout)) {
dum->port_status[rhport] |=
(1 << USB_PORT_FEAT_C_RESET);
dum->port_status[rhport] &=
~(1 << USB_PORT_FEAT_RESET);
dum->re_timeout = 0;
if (dum->vdev[rhport].ud.status ==
VDEV_ST_NOTASSIGNED) {
usbip_dbg_vhci_rh(" enable rhport %d "
"(status %u)\n",
rhport,
dum->vdev[rhport].ud.status);
dum->port_status[rhport] |=
USB_PORT_STAT_ENABLE;
}
}
((u16 *) buf)[0] = cpu_to_le16(dum->port_status[rhport]);
((u16 *) buf)[1] = cpu_to_le16(dum->port_status[rhport] >> 16);
usbip_dbg_vhci_rh(" GetPortStatus bye %x %x\n", ((u16 *)buf)[0],
((u16 *)buf)[1]);
break;
case SetHubFeature:
usbip_dbg_vhci_rh(" SetHubFeature\n");
retval = -EPIPE;
break;
case SetPortFeature:
switch (wValue) {
case USB_PORT_FEAT_SUSPEND:
usbip_dbg_vhci_rh(" SetPortFeature: "
"USB_PORT_FEAT_SUSPEND\n");
break;
case USB_PORT_FEAT_RESET:
usbip_dbg_vhci_rh(" SetPortFeature: "
"USB_PORT_FEAT_RESET\n");
if (dum->port_status[rhport] & USB_PORT_STAT_ENABLE) {
dum->port_status[rhport] &=
~(USB_PORT_STAT_ENABLE |
USB_PORT_STAT_LOW_SPEED |
USB_PORT_STAT_HIGH_SPEED);
}
dum->re_timeout = jiffies + msecs_to_jiffies(50);
default:
usbip_dbg_vhci_rh(" SetPortFeature: default %d\n",
wValue);
dum->port_status[rhport] |= (1 << wValue);
break;
}
break;
default:
pr_err("default: no such request\n");
retval = -EPIPE;
}
if (usbip_dbg_flag_vhci_rh) {
pr_debug("port %d\n", rhport);
if (rhport >= 0) {
dump_port_status_diff(prev_port_status[rhport],
dum->port_status[rhport]);
}
}
usbip_dbg_vhci_rh(" bye\n");
spin_unlock_irqrestore(&dum->lock, flags);
return retval;
}
static struct vhci_device *get_vdev(struct usb_device *udev)
{
int i;
if (!udev)
return NULL;
for (i = 0; i < VHCI_NPORTS; i++)
if (the_controller->vdev[i].udev == udev)
return port_to_vdev(i);
return NULL;
}
static void vhci_tx_urb(struct urb *urb)
{
struct vhci_device *vdev = get_vdev(urb->dev);
struct vhci_priv *priv;
unsigned long flag;
if (!vdev) {
pr_err("could not get virtual device");
return;
}
priv = kzalloc(sizeof(struct vhci_priv), GFP_ATOMIC);
spin_lock_irqsave(&vdev->priv_lock, flag);
if (!priv) {
dev_err(&urb->dev->dev, "malloc vhci_priv\n");
spin_unlock_irqrestore(&vdev->priv_lock, flag);
usbip_event_add(&vdev->ud, VDEV_EVENT_ERROR_MALLOC);
return;
}
priv->seqnum = atomic_inc_return(&the_controller->seqnum);
if (priv->seqnum == 0xffff)
dev_info(&urb->dev->dev, "seqnum max\n");
priv->vdev = vdev;
priv->urb = urb;
urb->hcpriv = (void *) priv;
list_add_tail(&priv->list, &vdev->priv_tx);
wake_up(&vdev->waitq_tx);
spin_unlock_irqrestore(&vdev->priv_lock, flag);
}
static int vhci_urb_enqueue(struct usb_hcd *hcd, struct urb *urb,
gfp_t mem_flags)
{
struct device *dev = &urb->dev->dev;
int ret = 0;
unsigned long flags;
struct vhci_device *vdev;
usbip_dbg_vhci_hc("enter, usb_hcd %p urb %p mem_flags %d\n",
hcd, urb, mem_flags);
BUG_ON(!urb->transfer_buffer && urb->transfer_buffer_length);
spin_lock_irqsave(&the_controller->lock, flags);
if (urb->status != -EINPROGRESS) {
dev_err(dev, "URB already unlinked!, status %d\n", urb->status);
spin_unlock_irqrestore(&the_controller->lock, flags);
return urb->status;
}
vdev = port_to_vdev(urb->dev->portnum-1);
spin_lock(&vdev->ud.lock);
if (vdev->ud.status == VDEV_ST_NULL ||
vdev->ud.status == VDEV_ST_ERROR) {
dev_err(dev, "enqueue for inactive port %d\n", vdev->rhport);
spin_unlock(&vdev->ud.lock);
spin_unlock_irqrestore(&the_controller->lock, flags);
return -ENODEV;
}
spin_unlock(&vdev->ud.lock);
ret = usb_hcd_link_urb_to_ep(hcd, urb);
if (ret)
goto no_need_unlink;
if (usb_pipedevice(urb->pipe) == 0) {
__u8 type = usb_pipetype(urb->pipe);
struct usb_ctrlrequest *ctrlreq =
(struct usb_ctrlrequest *) urb->setup_packet;
if (type != PIPE_CONTROL || !ctrlreq) {
dev_err(dev, "invalid request to devnum 0\n");
ret = -EINVAL;
goto no_need_xmit;
}
switch (ctrlreq->bRequest) {
case USB_REQ_SET_ADDRESS:
dev_info(dev, "SetAddress Request (%d) to port %d\n",
ctrlreq->wValue, vdev->rhport);
if (vdev->udev)
usb_put_dev(vdev->udev);
vdev->udev = usb_get_dev(urb->dev);
spin_lock(&vdev->ud.lock);
vdev->ud.status = VDEV_ST_USED;
spin_unlock(&vdev->ud.lock);
if (urb->status == -EINPROGRESS) {
urb->status = 0;
}
goto no_need_xmit;
case USB_REQ_GET_DESCRIPTOR:
if (ctrlreq->wValue == (USB_DT_DEVICE << 8))
usbip_dbg_vhci_hc("Not yet?: "
"Get_Descriptor to device 0 "
"(get max pipe size)\n");
if (vdev->udev)
usb_put_dev(vdev->udev);
vdev->udev = usb_get_dev(urb->dev);
goto out;
default:
dev_err(dev, "invalid request to devnum 0 bRequest %u, "
"wValue %u\n", ctrlreq->bRequest,
ctrlreq->wValue);
ret = -EINVAL;
goto no_need_xmit;
}
}
out:
vhci_tx_urb(urb);
spin_unlock_irqrestore(&the_controller->lock, flags);
return 0;
no_need_xmit:
usb_hcd_unlink_urb_from_ep(hcd, urb);
no_need_unlink:
spin_unlock_irqrestore(&the_controller->lock, flags);
usb_hcd_giveback_urb(vhci_to_hcd(the_controller), urb, urb->status);
return ret;
}
static int vhci_urb_dequeue(struct usb_hcd *hcd, struct urb *urb, int status)
{
unsigned long flags;
struct vhci_priv *priv;
struct vhci_device *vdev;
pr_info("dequeue a urb %p\n", urb);
spin_lock_irqsave(&the_controller->lock, flags);
priv = urb->hcpriv;
if (!priv) {
spin_unlock_irqrestore(&the_controller->lock, flags);
return 0;
}
{
int ret = 0;
ret = usb_hcd_check_unlink_urb(hcd, urb, status);
if (ret) {
spin_unlock_irqrestore(&the_controller->lock, flags);
return ret;
}
}
vdev = priv->vdev;
if (!vdev->ud.tcp_socket) {
unsigned long flags2;
spin_lock_irqsave(&vdev->priv_lock, flags2);
pr_info("device %p seems to be disconnected\n", vdev);
list_del(&priv->list);
kfree(priv);
urb->hcpriv = NULL;
spin_unlock_irqrestore(&vdev->priv_lock, flags2);
pr_info("gives back urb %p\n", urb);
usb_hcd_unlink_urb_from_ep(hcd, urb);
spin_unlock_irqrestore(&the_controller->lock, flags);
usb_hcd_giveback_urb(vhci_to_hcd(the_controller), urb,
urb->status);
spin_lock_irqsave(&the_controller->lock, flags);
} else {
unsigned long flags2;
struct vhci_unlink *unlink;
spin_lock_irqsave(&vdev->priv_lock, flags2);
unlink = kzalloc(sizeof(struct vhci_unlink), GFP_ATOMIC);
if (!unlink) {
pr_err("malloc vhci_unlink\n");
spin_unlock_irqrestore(&vdev->priv_lock, flags2);
spin_unlock_irqrestore(&the_controller->lock, flags);
usbip_event_add(&vdev->ud, VDEV_EVENT_ERROR_MALLOC);
return -ENOMEM;
}
unlink->seqnum = atomic_inc_return(&the_controller->seqnum);
if (unlink->seqnum == 0xffff)
pr_info("seqnum max\n");
unlink->unlink_seqnum = priv->seqnum;
pr_info("device %p seems to be still connected\n", vdev);
list_add_tail(&unlink->list, &vdev->unlink_tx);
wake_up(&vdev->waitq_tx);
spin_unlock_irqrestore(&vdev->priv_lock, flags2);
}
spin_unlock_irqrestore(&the_controller->lock, flags);
usbip_dbg_vhci_hc("leave\n");
return 0;
}
static void vhci_device_unlink_cleanup(struct vhci_device *vdev)
{
struct vhci_unlink *unlink, *tmp;
spin_lock(&vdev->priv_lock);
list_for_each_entry_safe(unlink, tmp, &vdev->unlink_tx, list) {
pr_info("unlink cleanup tx %lu\n", unlink->unlink_seqnum);
list_del(&unlink->list);
kfree(unlink);
}
list_for_each_entry_safe(unlink, tmp, &vdev->unlink_rx, list) {
struct urb *urb;
pr_info("unlink cleanup rx %lu\n", unlink->unlink_seqnum);
urb = pickup_urb_and_free_priv(vdev, unlink->unlink_seqnum);
if (!urb) {
pr_info("the urb (seqnum %lu) was already given back\n",
unlink->unlink_seqnum);
list_del(&unlink->list);
kfree(unlink);
continue;
}
urb->status = -ENODEV;
spin_lock(&the_controller->lock);
usb_hcd_unlink_urb_from_ep(vhci_to_hcd(the_controller), urb);
spin_unlock(&the_controller->lock);
usb_hcd_giveback_urb(vhci_to_hcd(the_controller), urb,
urb->status);
list_del(&unlink->list);
kfree(unlink);
}
spin_unlock(&vdev->priv_lock);
}
static void vhci_shutdown_connection(struct usbip_device *ud)
{
struct vhci_device *vdev = container_of(ud, struct vhci_device, ud);
if (ud->tcp_socket) {
pr_debug("shutdown tcp_socket %p\n", ud->tcp_socket);
kernel_sock_shutdown(ud->tcp_socket, SHUT_RDWR);
}
if (vdev->ud.tcp_rx && !task_is_dead(vdev->ud.tcp_rx))
kthread_stop(vdev->ud.tcp_rx);
if (vdev->ud.tcp_tx && !task_is_dead(vdev->ud.tcp_tx))
kthread_stop(vdev->ud.tcp_tx);
pr_info("stop threads\n");
if (vdev->ud.tcp_socket != NULL) {
sock_release(vdev->ud.tcp_socket);
vdev->ud.tcp_socket = NULL;
}
pr_info("release socket\n");
vhci_device_unlink_cleanup(vdev);
rh_port_disconnect(vdev->rhport);
pr_info("disconnect device\n");
}
static void vhci_device_reset(struct usbip_device *ud)
{
struct vhci_device *vdev = container_of(ud, struct vhci_device, ud);
spin_lock(&ud->lock);
vdev->speed = 0;
vdev->devid = 0;
if (vdev->udev)
usb_put_dev(vdev->udev);
vdev->udev = NULL;
ud->tcp_socket = NULL;
ud->status = VDEV_ST_NULL;
spin_unlock(&ud->lock);
}
static void vhci_device_unusable(struct usbip_device *ud)
{
spin_lock(&ud->lock);
ud->status = VDEV_ST_ERROR;
spin_unlock(&ud->lock);
}
static void vhci_device_init(struct vhci_device *vdev)
{
memset(vdev, 0, sizeof(*vdev));
vdev->ud.side = USBIP_VHCI;
vdev->ud.status = VDEV_ST_NULL;
spin_lock_init(&vdev->ud.lock);
INIT_LIST_HEAD(&vdev->priv_rx);
INIT_LIST_HEAD(&vdev->priv_tx);
INIT_LIST_HEAD(&vdev->unlink_tx);
INIT_LIST_HEAD(&vdev->unlink_rx);
spin_lock_init(&vdev->priv_lock);
init_waitqueue_head(&vdev->waitq_tx);
vdev->ud.eh_ops.shutdown = vhci_shutdown_connection;
vdev->ud.eh_ops.reset = vhci_device_reset;
vdev->ud.eh_ops.unusable = vhci_device_unusable;
usbip_start_eh(&vdev->ud);
}
static int vhci_start(struct usb_hcd *hcd)
{
struct vhci_hcd *vhci = hcd_to_vhci(hcd);
int rhport;
int err = 0;
usbip_dbg_vhci_hc("enter vhci_start\n");
for (rhport = 0; rhport < VHCI_NPORTS; rhport++) {
struct vhci_device *vdev = &vhci->vdev[rhport];
vhci_device_init(vdev);
vdev->rhport = rhport;
}
atomic_set(&vhci->seqnum, 0);
spin_lock_init(&vhci->lock);
hcd->power_budget = 0;
hcd->state = HC_STATE_RUNNING;
hcd->uses_new_polling = 1;
err = sysfs_create_group(&vhci_dev(vhci)->kobj, &dev_attr_group);
if (err) {
pr_err("create sysfs files\n");
return err;
}
return 0;
}
static void vhci_stop(struct usb_hcd *hcd)
{
struct vhci_hcd *vhci = hcd_to_vhci(hcd);
int rhport = 0;
usbip_dbg_vhci_hc("stop VHCI controller\n");
sysfs_remove_group(&vhci_dev(vhci)->kobj, &dev_attr_group);
for (rhport = 0 ; rhport < VHCI_NPORTS; rhport++) {
struct vhci_device *vdev = &vhci->vdev[rhport];
usbip_event_add(&vdev->ud, VDEV_EVENT_REMOVED);
usbip_stop_eh(&vdev->ud);
}
}
static int vhci_get_frame_number(struct usb_hcd *hcd)
{
pr_err("Not yet implemented\n");
return 0;
}
static int vhci_bus_suspend(struct usb_hcd *hcd)
{
struct vhci_hcd *vhci = hcd_to_vhci(hcd);
dev_dbg(&hcd->self.root_hub->dev, "%s\n", __func__);
spin_lock_irq(&vhci->lock);
hcd->state = HC_STATE_SUSPENDED;
spin_unlock_irq(&vhci->lock);
return 0;
}
static int vhci_bus_resume(struct usb_hcd *hcd)
{
struct vhci_hcd *vhci = hcd_to_vhci(hcd);
int rc = 0;
dev_dbg(&hcd->self.root_hub->dev, "%s\n", __func__);
spin_lock_irq(&vhci->lock);
if (!HCD_HW_ACCESSIBLE(hcd)) {
rc = -ESHUTDOWN;
} else {
hcd->state = HC_STATE_RUNNING;
}
spin_unlock_irq(&vhci->lock);
return rc;
}
static int vhci_hcd_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
int ret;
usbip_dbg_vhci_hc("name %s id %d\n", pdev->name, pdev->id);
if (pdev->dev.dma_mask) {
dev_info(&pdev->dev, "vhci_hcd DMA not supported\n");
return -EINVAL;
}
hcd = usb_create_hcd(&vhci_hc_driver, &pdev->dev, dev_name(&pdev->dev));
if (!hcd) {
pr_err("create hcd failed\n");
return -ENOMEM;
}
hcd->has_tt = 1;
the_controller = hcd_to_vhci(hcd);
ret = usb_add_hcd(hcd, 0, 0);
if (ret != 0) {
pr_err("usb_add_hcd failed %d\n", ret);
usb_put_hcd(hcd);
the_controller = NULL;
return ret;
}
usbip_dbg_vhci_hc("bye\n");
return 0;
}
static int vhci_hcd_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd;
hcd = platform_get_drvdata(pdev);
if (!hcd)
return 0;
usb_remove_hcd(hcd);
usb_put_hcd(hcd);
the_controller = NULL;
return 0;
}
static int vhci_hcd_suspend(struct platform_device *pdev, pm_message_t state)
{
struct usb_hcd *hcd;
int rhport = 0;
int connected = 0;
int ret = 0;
hcd = platform_get_drvdata(pdev);
spin_lock(&the_controller->lock);
for (rhport = 0; rhport < VHCI_NPORTS; rhport++)
if (the_controller->port_status[rhport] &
USB_PORT_STAT_CONNECTION)
connected += 1;
spin_unlock(&the_controller->lock);
if (connected > 0) {
dev_info(&pdev->dev, "We have %d active connection%s. Do not "
"suspend.\n", connected, (connected == 1 ? "" : "s"));
ret = -EBUSY;
} else {
dev_info(&pdev->dev, "suspend vhci_hcd");
clear_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
}
return ret;
}
static int vhci_hcd_resume(struct platform_device *pdev)
{
struct usb_hcd *hcd;
dev_dbg(&pdev->dev, "%s\n", __func__);
hcd = platform_get_drvdata(pdev);
set_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
usb_hcd_poll_rh_status(hcd);
return 0;
}
static void the_pdev_release(struct device *dev)
{
return;
}
static int __init vhci_hcd_init(void)
{
int ret;
if (usb_disabled())
return -ENODEV;
ret = platform_driver_register(&vhci_driver);
if (ret < 0)
goto err_driver_register;
ret = platform_device_register(&the_pdev);
if (ret < 0)
goto err_platform_device_register;
pr_info(DRIVER_DESC " v" USBIP_VERSION "\n");
return ret;
err_platform_device_register:
platform_driver_unregister(&vhci_driver);
err_driver_register:
return ret;
}
static void __exit vhci_hcd_exit(void)
{
platform_device_unregister(&the_pdev);
platform_driver_unregister(&vhci_driver);
}
