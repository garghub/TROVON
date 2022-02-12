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
void rh_port_connect(struct vhci_device *vdev, enum usb_device_speed speed)
{
struct vhci_hcd *vhci = vdev_to_vhci(vdev);
int rhport = vdev->rhport;
u32 status;
unsigned long flags;
usbip_dbg_vhci_rh("rh_port_connect %d\n", rhport);
spin_lock_irqsave(&vhci->lock, flags);
status = vhci->port_status[rhport];
status |= USB_PORT_STAT_CONNECTION | (1 << USB_PORT_FEAT_C_CONNECTION);
switch (speed) {
case USB_SPEED_HIGH:
status |= USB_PORT_STAT_HIGH_SPEED;
break;
case USB_SPEED_LOW:
status |= USB_PORT_STAT_LOW_SPEED;
break;
default:
break;
}
vhci->port_status[rhport] = status;
spin_unlock_irqrestore(&vhci->lock, flags);
usb_hcd_poll_rh_status(vhci_to_hcd(vhci));
}
static void rh_port_disconnect(struct vhci_device *vdev)
{
struct vhci_hcd *vhci = vdev_to_vhci(vdev);
int rhport = vdev->rhport;
u32 status;
unsigned long flags;
usbip_dbg_vhci_rh("rh_port_disconnect %d\n", rhport);
spin_lock_irqsave(&vhci->lock, flags);
status = vhci->port_status[rhport];
status &= ~USB_PORT_STAT_CONNECTION;
status |= (1 << USB_PORT_FEAT_C_CONNECTION);
vhci->port_status[rhport] = status;
spin_unlock_irqrestore(&vhci->lock, flags);
usb_hcd_poll_rh_status(vhci_to_hcd(vhci));
}
static int vhci_hub_status(struct usb_hcd *hcd, char *buf)
{
struct vhci_hcd *vhci;
int retval;
int rhport;
int changed = 0;
unsigned long flags;
retval = DIV_ROUND_UP(VHCI_HC_PORTS + 1, 8);
memset(buf, 0, retval);
vhci = hcd_to_vhci(hcd);
spin_lock_irqsave(&vhci->lock, flags);
if (!HCD_HW_ACCESSIBLE(hcd)) {
usbip_dbg_vhci_rh("hw accessible flag not on?\n");
goto done;
}
for (rhport = 0; rhport < VHCI_HC_PORTS; rhport++) {
if ((vhci->port_status[rhport] & PORT_C_MASK)) {
usbip_dbg_vhci_rh("port %d status changed\n", rhport);
buf[(rhport + 1) / 8] |= 1 << (rhport + 1) % 8;
changed = 1;
}
}
if ((hcd->state == HC_STATE_SUSPENDED) && (changed == 1))
usb_hcd_resume_root_hub(hcd);
done:
spin_unlock_irqrestore(&vhci->lock, flags);
return changed ? retval : 0;
}
static inline void hub_descriptor(struct usb_hub_descriptor *desc)
{
memset(desc, 0, sizeof(*desc));
desc->bDescriptorType = USB_DT_HUB;
desc->bDescLength = 9;
desc->wHubCharacteristics = cpu_to_le16(
HUB_CHAR_INDV_PORT_LPSM | HUB_CHAR_COMMON_OCPM);
desc->bNbrPorts = VHCI_HC_PORTS;
desc->u.hs.DeviceRemovable[0] = 0xff;
desc->u.hs.DeviceRemovable[1] = 0xff;
}
static int vhci_hub_control(struct usb_hcd *hcd, u16 typeReq, u16 wValue,
u16 wIndex, char *buf, u16 wLength)
{
struct vhci_hcd *dum;
int retval = 0;
int rhport;
unsigned long flags;
u32 prev_port_status[VHCI_HC_PORTS];
if (!HCD_HW_ACCESSIBLE(hcd))
return -ETIMEDOUT;
usbip_dbg_vhci_rh("typeReq %x wValue %x wIndex %x\n", typeReq, wValue,
wIndex);
if (wIndex > VHCI_HC_PORTS)
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
usbip_dbg_vhci_rh(
" ClearPortFeature: USB_PORT_FEAT_POWER\n");
dum->port_status[rhport] = 0;
dum->resuming = 0;
break;
case USB_PORT_FEAT_C_RESET:
usbip_dbg_vhci_rh(
" ClearPortFeature: USB_PORT_FEAT_C_RESET\n");
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
*(__le32 *) buf = cpu_to_le32(0);
break;
case GetPortStatus:
usbip_dbg_vhci_rh(" GetPortStatus port %x\n", wIndex);
if (wIndex > VHCI_HC_PORTS || wIndex < 1) {
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
usbip_dbg_vhci_rh(
" enable rhport %d (status %u)\n",
rhport,
dum->vdev[rhport].ud.status);
dum->port_status[rhport] |=
USB_PORT_STAT_ENABLE;
}
}
((__le16 *) buf)[0] = cpu_to_le16(dum->port_status[rhport]);
((__le16 *) buf)[1] =
cpu_to_le16(dum->port_status[rhport] >> 16);
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
usbip_dbg_vhci_rh(
" SetPortFeature: USB_PORT_FEAT_SUSPEND\n");
break;
case USB_PORT_FEAT_RESET:
usbip_dbg_vhci_rh(
" SetPortFeature: USB_PORT_FEAT_RESET\n");
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
struct platform_device *pdev;
struct usb_hcd *hcd;
struct vhci_hcd *vhci;
int pdev_nr, rhport;
if (!udev)
return NULL;
for (pdev_nr = 0; pdev_nr < vhci_num_controllers; pdev_nr++) {
pdev = *(vhci_pdevs + pdev_nr);
if (pdev == NULL)
continue;
hcd = platform_get_drvdata(pdev);
if (hcd == NULL)
continue;
vhci = hcd_to_vhci(hcd);
for (rhport = 0; rhport < VHCI_HC_PORTS; rhport++) {
if (vhci->vdev[rhport].udev == udev)
return &vhci->vdev[rhport];
}
}
return NULL;
}
static void vhci_tx_urb(struct urb *urb)
{
struct vhci_device *vdev = get_vdev(urb->dev);
struct vhci_priv *priv;
struct vhci_hcd *vhci = vdev_to_vhci(vdev);
unsigned long flags;
if (!vdev) {
pr_err("could not get virtual device");
return;
}
priv = kzalloc(sizeof(struct vhci_priv), GFP_ATOMIC);
if (!priv) {
usbip_event_add(&vdev->ud, VDEV_EVENT_ERROR_MALLOC);
return;
}
spin_lock_irqsave(&vdev->priv_lock, flags);
priv->seqnum = atomic_inc_return(&vhci->seqnum);
if (priv->seqnum == 0xffff)
dev_info(&urb->dev->dev, "seqnum max\n");
priv->vdev = vdev;
priv->urb = urb;
urb->hcpriv = (void *) priv;
list_add_tail(&priv->list, &vdev->priv_tx);
wake_up(&vdev->waitq_tx);
spin_unlock_irqrestore(&vdev->priv_lock, flags);
}
static int vhci_urb_enqueue(struct usb_hcd *hcd, struct urb *urb,
gfp_t mem_flags)
{
struct vhci_hcd *vhci = hcd_to_vhci(hcd);
struct device *dev = &urb->dev->dev;
u8 portnum = urb->dev->portnum;
int ret = 0;
struct vhci_device *vdev;
unsigned long flags;
usbip_dbg_vhci_hc("enter, usb_hcd %p urb %p mem_flags %d\n",
hcd, urb, mem_flags);
if (portnum > VHCI_HC_PORTS) {
pr_err("invalid port number %d\n", portnum);
return -ENODEV;
}
vdev = &vhci->vdev[portnum-1];
BUG_ON(!urb->transfer_buffer && urb->transfer_buffer_length);
spin_lock_irqsave(&vhci->lock, flags);
if (urb->status != -EINPROGRESS) {
dev_err(dev, "URB already unlinked!, status %d\n", urb->status);
spin_unlock_irqrestore(&vhci->lock, flags);
return urb->status;
}
spin_lock(&vdev->ud.lock);
if (vdev->ud.status == VDEV_ST_NULL ||
vdev->ud.status == VDEV_ST_ERROR) {
dev_err(dev, "enqueue for inactive port %d\n", vdev->rhport);
spin_unlock(&vdev->ud.lock);
spin_unlock_irqrestore(&vhci->lock, flags);
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
if (ctrlreq->wValue == cpu_to_le16(USB_DT_DEVICE << 8))
usbip_dbg_vhci_hc(
"Not yet?:Get_Descriptor to device 0 (get max pipe size)\n");
usb_put_dev(vdev->udev);
vdev->udev = usb_get_dev(urb->dev);
goto out;
default:
dev_err(dev,
"invalid request to devnum 0 bRequest %u, wValue %u\n",
ctrlreq->bRequest,
ctrlreq->wValue);
ret = -EINVAL;
goto no_need_xmit;
}
}
out:
vhci_tx_urb(urb);
spin_unlock_irqrestore(&vhci->lock, flags);
return 0;
no_need_xmit:
usb_hcd_unlink_urb_from_ep(hcd, urb);
no_need_unlink:
spin_unlock_irqrestore(&vhci->lock, flags);
if (!ret)
usb_hcd_giveback_urb(hcd, urb, urb->status);
return ret;
}
static int vhci_urb_dequeue(struct usb_hcd *hcd, struct urb *urb, int status)
{
struct vhci_hcd *vhci = hcd_to_vhci(hcd);
struct vhci_priv *priv;
struct vhci_device *vdev;
unsigned long flags;
pr_info("dequeue a urb %p\n", urb);
spin_lock_irqsave(&vhci->lock, flags);
priv = urb->hcpriv;
if (!priv) {
spin_unlock_irqrestore(&vhci->lock, flags);
return -EIDRM;
}
{
int ret = 0;
ret = usb_hcd_check_unlink_urb(hcd, urb, status);
if (ret) {
spin_unlock_irqrestore(&vhci->lock, flags);
return ret;
}
}
vdev = priv->vdev;
if (!vdev->ud.tcp_socket) {
spin_lock(&vdev->priv_lock);
pr_info("device %p seems to be disconnected\n", vdev);
list_del(&priv->list);
kfree(priv);
urb->hcpriv = NULL;
spin_unlock(&vdev->priv_lock);
pr_info("gives back urb %p\n", urb);
usb_hcd_unlink_urb_from_ep(hcd, urb);
spin_unlock_irqrestore(&vhci->lock, flags);
usb_hcd_giveback_urb(vhci_to_hcd(vhci), urb, urb->status);
spin_lock_irqsave(&vhci->lock, flags);
} else {
struct vhci_unlink *unlink;
spin_lock(&vdev->priv_lock);
unlink = kzalloc(sizeof(struct vhci_unlink), GFP_ATOMIC);
if (!unlink) {
spin_unlock(&vdev->priv_lock);
spin_unlock_irqrestore(&vhci->lock, flags);
usbip_event_add(&vdev->ud, VDEV_EVENT_ERROR_MALLOC);
return -ENOMEM;
}
unlink->seqnum = atomic_inc_return(&vhci->seqnum);
if (unlink->seqnum == 0xffff)
pr_info("seqnum max\n");
unlink->unlink_seqnum = priv->seqnum;
pr_info("device %p seems to be still connected\n", vdev);
list_add_tail(&unlink->list, &vdev->unlink_tx);
wake_up(&vdev->waitq_tx);
spin_unlock(&vdev->priv_lock);
}
spin_unlock_irqrestore(&vhci->lock, flags);
usbip_dbg_vhci_hc("leave\n");
return 0;
}
static void vhci_device_unlink_cleanup(struct vhci_device *vdev)
{
struct vhci_hcd *vhci = vdev_to_vhci(vdev);
struct usb_hcd *hcd = vhci_to_hcd(vhci);
struct vhci_unlink *unlink, *tmp;
unsigned long flags;
spin_lock_irqsave(&vhci->lock, flags);
spin_lock(&vdev->priv_lock);
list_for_each_entry_safe(unlink, tmp, &vdev->unlink_tx, list) {
pr_info("unlink cleanup tx %lu\n", unlink->unlink_seqnum);
list_del(&unlink->list);
kfree(unlink);
}
while (!list_empty(&vdev->unlink_rx)) {
struct urb *urb;
unlink = list_first_entry(&vdev->unlink_rx, struct vhci_unlink,
list);
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
usb_hcd_unlink_urb_from_ep(hcd, urb);
list_del(&unlink->list);
spin_unlock(&vdev->priv_lock);
spin_unlock_irqrestore(&vhci->lock, flags);
usb_hcd_giveback_urb(hcd, urb, urb->status);
spin_lock_irqsave(&vhci->lock, flags);
spin_lock(&vdev->priv_lock);
kfree(unlink);
}
spin_unlock(&vdev->priv_lock);
spin_unlock_irqrestore(&vhci->lock, flags);
}
static void vhci_shutdown_connection(struct usbip_device *ud)
{
struct vhci_device *vdev = container_of(ud, struct vhci_device, ud);
if (ud->tcp_socket) {
pr_debug("shutdown tcp_socket %p\n", ud->tcp_socket);
kernel_sock_shutdown(ud->tcp_socket, SHUT_RDWR);
}
if (vdev->ud.tcp_rx) {
kthread_stop_put(vdev->ud.tcp_rx);
vdev->ud.tcp_rx = NULL;
}
if (vdev->ud.tcp_tx) {
kthread_stop_put(vdev->ud.tcp_tx);
vdev->ud.tcp_tx = NULL;
}
pr_info("stop threads\n");
if (vdev->ud.tcp_socket) {
sockfd_put(vdev->ud.tcp_socket);
vdev->ud.tcp_socket = NULL;
}
pr_info("release socket\n");
vhci_device_unlink_cleanup(vdev);
rh_port_disconnect(vdev);
pr_info("disconnect device\n");
}
static void vhci_device_reset(struct usbip_device *ud)
{
struct vhci_device *vdev = container_of(ud, struct vhci_device, ud);
unsigned long flags;
spin_lock_irqsave(&ud->lock, flags);
vdev->speed = 0;
vdev->devid = 0;
usb_put_dev(vdev->udev);
vdev->udev = NULL;
if (ud->tcp_socket) {
sockfd_put(ud->tcp_socket);
ud->tcp_socket = NULL;
}
ud->status = VDEV_ST_NULL;
spin_unlock_irqrestore(&ud->lock, flags);
}
static void vhci_device_unusable(struct usbip_device *ud)
{
unsigned long flags;
spin_lock_irqsave(&ud->lock, flags);
ud->status = VDEV_ST_ERROR;
spin_unlock_irqrestore(&ud->lock, flags);
}
static void vhci_device_init(struct vhci_device *vdev)
{
memset(vdev, 0, sizeof(struct vhci_device));
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
static int hcd_name_to_id(const char *name)
{
char *c;
long val;
int ret;
c = strchr(name, '.');
if (c == NULL)
return 0;
ret = kstrtol(c+1, 10, &val);
if (ret < 0)
return ret;
return val;
}
static int vhci_start(struct usb_hcd *hcd)
{
struct vhci_hcd *vhci = hcd_to_vhci(hcd);
int id, rhport;
int err = 0;
usbip_dbg_vhci_hc("enter vhci_start\n");
for (rhport = 0; rhport < VHCI_HC_PORTS; rhport++) {
struct vhci_device *vdev = &vhci->vdev[rhport];
vhci_device_init(vdev);
vdev->rhport = rhport;
}
atomic_set(&vhci->seqnum, 0);
spin_lock_init(&vhci->lock);
hcd->power_budget = 0;
hcd->uses_new_polling = 1;
id = hcd_name_to_id(hcd_name(hcd));
if (id < 0) {
pr_err("invalid vhci name %s\n", hcd_name(hcd));
return -EINVAL;
}
if (id == 0) {
err = vhci_init_attr_group();
if (err) {
pr_err("init attr group\n");
return err;
}
err = sysfs_create_group(&hcd_dev(hcd)->kobj, &vhci_attr_group);
if (err) {
pr_err("create sysfs files\n");
vhci_finish_attr_group();
return err;
}
pr_info("created sysfs %s\n", hcd_name(hcd));
}
return 0;
}
static void vhci_stop(struct usb_hcd *hcd)
{
struct vhci_hcd *vhci = hcd_to_vhci(hcd);
int id, rhport;
usbip_dbg_vhci_hc("stop VHCI controller\n");
id = hcd_name_to_id(hcd_name(hcd));
if (id == 0) {
sysfs_remove_group(&hcd_dev(hcd)->kobj, &vhci_attr_group);
vhci_finish_attr_group();
}
for (rhport = 0; rhport < VHCI_HC_PORTS; rhport++) {
struct vhci_device *vdev = &vhci->vdev[rhport];
usbip_event_add(&vdev->ud, VDEV_EVENT_REMOVED);
usbip_stop_eh(&vdev->ud);
}
}
static int vhci_get_frame_number(struct usb_hcd *hcd)
{
dev_err_ratelimited(&hcd->self.root_hub->dev, "Not yet implemented\n");
return 0;
}
static int vhci_bus_suspend(struct usb_hcd *hcd)
{
struct vhci_hcd *vhci = hcd_to_vhci(hcd);
unsigned long flags;
dev_dbg(&hcd->self.root_hub->dev, "%s\n", __func__);
spin_lock_irqsave(&vhci->lock, flags);
hcd->state = HC_STATE_SUSPENDED;
spin_unlock_irqrestore(&vhci->lock, flags);
return 0;
}
static int vhci_bus_resume(struct usb_hcd *hcd)
{
struct vhci_hcd *vhci = hcd_to_vhci(hcd);
int rc = 0;
unsigned long flags;
dev_dbg(&hcd->self.root_hub->dev, "%s\n", __func__);
spin_lock_irqsave(&vhci->lock, flags);
if (!HCD_HW_ACCESSIBLE(hcd))
rc = -ESHUTDOWN;
else
hcd->state = HC_STATE_RUNNING;
spin_unlock_irqrestore(&vhci->lock, flags);
return rc;
}
static int vhci_hcd_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
int ret;
usbip_dbg_vhci_hc("name %s id %d\n", pdev->name, pdev->id);
hcd = usb_create_hcd(&vhci_hc_driver, &pdev->dev, dev_name(&pdev->dev));
if (!hcd) {
pr_err("create hcd failed\n");
return -ENOMEM;
}
hcd->has_tt = 1;
ret = usb_add_hcd(hcd, 0, 0);
if (ret != 0) {
pr_err("usb_add_hcd failed %d\n", ret);
usb_put_hcd(hcd);
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
return 0;
}
static int vhci_hcd_suspend(struct platform_device *pdev, pm_message_t state)
{
struct usb_hcd *hcd;
struct vhci_hcd *vhci;
int rhport;
int connected = 0;
int ret = 0;
unsigned long flags;
hcd = platform_get_drvdata(pdev);
if (!hcd)
return 0;
vhci = hcd_to_vhci(hcd);
spin_lock_irqsave(&vhci->lock, flags);
for (rhport = 0; rhport < VHCI_HC_PORTS; rhport++)
if (vhci->port_status[rhport] & USB_PORT_STAT_CONNECTION)
connected += 1;
spin_unlock_irqrestore(&vhci->lock, flags);
if (connected > 0) {
dev_info(&pdev->dev,
"We have %d active connection%s. Do not suspend.\n",
connected, (connected == 1 ? "" : "s"));
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
if (!hcd)
return 0;
set_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
usb_hcd_poll_rh_status(hcd);
return 0;
}
static int add_platform_device(int id)
{
struct platform_device *pdev;
int dev_nr;
if (id == 0)
dev_nr = -1;
else
dev_nr = id;
pdev = platform_device_register_simple(driver_name, dev_nr, NULL, 0);
if (IS_ERR(pdev))
return PTR_ERR(pdev);
*(vhci_pdevs + id) = pdev;
return 0;
}
static void del_platform_devices(void)
{
struct platform_device *pdev;
int i;
for (i = 0; i < vhci_num_controllers; i++) {
pdev = *(vhci_pdevs + i);
if (pdev != NULL)
platform_device_unregister(pdev);
*(vhci_pdevs + i) = NULL;
}
sysfs_remove_link(&platform_bus.kobj, driver_name);
}
static int __init vhci_hcd_init(void)
{
int i, ret;
if (usb_disabled())
return -ENODEV;
if (vhci_num_controllers < 1)
vhci_num_controllers = 1;
vhci_pdevs = kcalloc(vhci_num_controllers, sizeof(void *), GFP_KERNEL);
if (vhci_pdevs == NULL)
return -ENOMEM;
ret = platform_driver_register(&vhci_driver);
if (ret)
goto err_driver_register;
for (i = 0; i < vhci_num_controllers; i++) {
ret = add_platform_device(i);
if (ret)
goto err_platform_device_register;
}
pr_info(DRIVER_DESC " v" USBIP_VERSION "\n");
return ret;
err_platform_device_register:
del_platform_devices();
platform_driver_unregister(&vhci_driver);
err_driver_register:
kfree(vhci_pdevs);
return ret;
}
static void __exit vhci_hcd_exit(void)
{
del_platform_devices();
platform_driver_unregister(&vhci_driver);
kfree(vhci_pdevs);
}
