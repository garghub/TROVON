int usbnet_get_endpoints(struct usbnet *dev, struct usb_interface *intf)
{
int tmp;
struct usb_host_interface *alt = NULL;
struct usb_host_endpoint *in = NULL, *out = NULL;
struct usb_host_endpoint *status = NULL;
for (tmp = 0; tmp < intf->num_altsetting; tmp++) {
unsigned ep;
in = out = status = NULL;
alt = intf->altsetting + tmp;
for (ep = 0; ep < alt->desc.bNumEndpoints; ep++) {
struct usb_host_endpoint *e;
int intr = 0;
e = alt->endpoint + ep;
switch (e->desc.bmAttributes) {
case USB_ENDPOINT_XFER_INT:
if (!usb_endpoint_dir_in(&e->desc))
continue;
intr = 1;
case USB_ENDPOINT_XFER_BULK:
break;
default:
continue;
}
if (usb_endpoint_dir_in(&e->desc)) {
if (!intr && !in)
in = e;
else if (intr && !status)
status = e;
} else {
if (!out)
out = e;
}
}
if (in && out)
break;
}
if (!alt || !in || !out)
return -EINVAL;
if (alt->desc.bAlternateSetting != 0 ||
!(dev->driver_info->flags & FLAG_NO_SETINT)) {
tmp = usb_set_interface (dev->udev, alt->desc.bInterfaceNumber,
alt->desc.bAlternateSetting);
if (tmp < 0)
return tmp;
}
dev->in = usb_rcvbulkpipe (dev->udev,
in->desc.bEndpointAddress & USB_ENDPOINT_NUMBER_MASK);
dev->out = usb_sndbulkpipe (dev->udev,
out->desc.bEndpointAddress & USB_ENDPOINT_NUMBER_MASK);
dev->status = status;
return 0;
}
int usbnet_get_ethernet_addr(struct usbnet *dev, int iMACAddress)
{
int tmp, i;
unsigned char buf [13];
tmp = usb_string(dev->udev, iMACAddress, buf, sizeof buf);
if (tmp != 12) {
dev_dbg(&dev->udev->dev,
"bad MAC string %d fetch, %d\n", iMACAddress, tmp);
if (tmp >= 0)
tmp = -EINVAL;
return tmp;
}
for (i = tmp = 0; i < 6; i++, tmp += 2)
dev->net->dev_addr [i] =
(hex_to_bin(buf[tmp]) << 4) + hex_to_bin(buf[tmp + 1]);
return 0;
}
static void intr_complete (struct urb *urb)
{
struct usbnet *dev = urb->context;
int status = urb->status;
switch (status) {
case 0:
dev->driver_info->status(dev, urb);
break;
case -ENOENT:
case -ESHUTDOWN:
netif_dbg(dev, ifdown, dev->net,
"intr shutdown, code %d\n", status);
return;
default:
netdev_dbg(dev->net, "intr status %d\n", status);
break;
}
if (!netif_running (dev->net))
return;
status = usb_submit_urb (urb, GFP_ATOMIC);
if (status != 0)
netif_err(dev, timer, dev->net,
"intr resubmit --> %d\n", status);
}
static int init_status (struct usbnet *dev, struct usb_interface *intf)
{
char *buf = NULL;
unsigned pipe = 0;
unsigned maxp;
unsigned period;
if (!dev->driver_info->status)
return 0;
pipe = usb_rcvintpipe (dev->udev,
dev->status->desc.bEndpointAddress
& USB_ENDPOINT_NUMBER_MASK);
maxp = usb_maxpacket (dev->udev, pipe, 0);
period = max ((int) dev->status->desc.bInterval,
(dev->udev->speed == USB_SPEED_HIGH) ? 7 : 3);
buf = kmalloc (maxp, GFP_KERNEL);
if (buf) {
dev->interrupt = usb_alloc_urb (0, GFP_KERNEL);
if (!dev->interrupt) {
kfree (buf);
return -ENOMEM;
} else {
usb_fill_int_urb(dev->interrupt, dev->udev, pipe,
buf, maxp, intr_complete, dev, period);
dev->interrupt->transfer_flags |= URB_FREE_BUFFER;
dev_dbg(&intf->dev,
"status ep%din, %d bytes period %d\n",
usb_pipeendpoint(pipe), maxp, period);
}
}
return 0;
}
int usbnet_status_start(struct usbnet *dev, gfp_t mem_flags)
{
int ret = 0;
WARN_ON_ONCE(dev->interrupt == NULL);
if (dev->interrupt) {
mutex_lock(&dev->interrupt_mutex);
if (++dev->interrupt_count == 1)
ret = usb_submit_urb(dev->interrupt, mem_flags);
dev_dbg(&dev->udev->dev, "incremented interrupt URB count to %d\n",
dev->interrupt_count);
mutex_unlock(&dev->interrupt_mutex);
}
return ret;
}
static int __usbnet_status_start_force(struct usbnet *dev, gfp_t mem_flags)
{
int ret = 0;
mutex_lock(&dev->interrupt_mutex);
if (dev->interrupt_count) {
ret = usb_submit_urb(dev->interrupt, mem_flags);
dev_dbg(&dev->udev->dev,
"submitted interrupt URB for resume\n");
}
mutex_unlock(&dev->interrupt_mutex);
return ret;
}
void usbnet_status_stop(struct usbnet *dev)
{
if (dev->interrupt) {
mutex_lock(&dev->interrupt_mutex);
WARN_ON(dev->interrupt_count == 0);
if (dev->interrupt_count && --dev->interrupt_count == 0)
usb_kill_urb(dev->interrupt);
dev_dbg(&dev->udev->dev,
"decremented interrupt URB count to %d\n",
dev->interrupt_count);
mutex_unlock(&dev->interrupt_mutex);
}
}
static void __usbnet_status_stop_force(struct usbnet *dev)
{
if (dev->interrupt) {
mutex_lock(&dev->interrupt_mutex);
usb_kill_urb(dev->interrupt);
dev_dbg(&dev->udev->dev, "killed interrupt URB for suspend\n");
mutex_unlock(&dev->interrupt_mutex);
}
}
void usbnet_skb_return (struct usbnet *dev, struct sk_buff *skb)
{
int status;
if (test_bit(EVENT_RX_PAUSED, &dev->flags)) {
skb_queue_tail(&dev->rxq_pause, skb);
return;
}
skb->protocol = eth_type_trans (skb, dev->net);
dev->net->stats.rx_packets++;
dev->net->stats.rx_bytes += skb->len;
netif_dbg(dev, rx_status, dev->net, "< rx, len %zu, type 0x%x\n",
skb->len + sizeof (struct ethhdr), skb->protocol);
memset (skb->cb, 0, sizeof (struct skb_data));
if (skb_defer_rx_timestamp(skb))
return;
status = netif_rx (skb);
if (status != NET_RX_SUCCESS)
netif_dbg(dev, rx_err, dev->net,
"netif_rx status %d\n", status);
}
void usbnet_update_max_qlen(struct usbnet *dev)
{
enum usb_device_speed speed = dev->udev->speed;
switch (speed) {
case USB_SPEED_HIGH:
dev->rx_qlen = MAX_QUEUE_MEMORY / dev->rx_urb_size;
dev->tx_qlen = MAX_QUEUE_MEMORY / dev->hard_mtu;
break;
case USB_SPEED_SUPER:
dev->rx_qlen = 5 * MAX_QUEUE_MEMORY / dev->rx_urb_size;
dev->tx_qlen = 5 * MAX_QUEUE_MEMORY / dev->hard_mtu;
break;
default:
dev->rx_qlen = dev->tx_qlen = 4;
}
}
int usbnet_change_mtu (struct net_device *net, int new_mtu)
{
struct usbnet *dev = netdev_priv(net);
int ll_mtu = new_mtu + net->hard_header_len;
int old_hard_mtu = dev->hard_mtu;
int old_rx_urb_size = dev->rx_urb_size;
if (new_mtu <= 0)
return -EINVAL;
if ((ll_mtu % dev->maxpacket) == 0)
return -EDOM;
net->mtu = new_mtu;
dev->hard_mtu = net->mtu + net->hard_header_len;
if (dev->rx_urb_size == old_hard_mtu) {
dev->rx_urb_size = dev->hard_mtu;
if (dev->rx_urb_size > old_rx_urb_size)
usbnet_unlink_rx_urbs(dev);
}
usbnet_update_max_qlen(dev);
return 0;
}
static void __usbnet_queue_skb(struct sk_buff_head *list,
struct sk_buff *newsk, enum skb_state state)
{
struct skb_data *entry = (struct skb_data *) newsk->cb;
__skb_queue_tail(list, newsk);
entry->state = state;
}
static enum skb_state defer_bh(struct usbnet *dev, struct sk_buff *skb,
struct sk_buff_head *list, enum skb_state state)
{
unsigned long flags;
enum skb_state old_state;
struct skb_data *entry = (struct skb_data *) skb->cb;
spin_lock_irqsave(&list->lock, flags);
old_state = entry->state;
entry->state = state;
__skb_unlink(skb, list);
spin_unlock(&list->lock);
spin_lock(&dev->done.lock);
__skb_queue_tail(&dev->done, skb);
if (dev->done.qlen == 1)
tasklet_schedule(&dev->bh);
spin_unlock_irqrestore(&dev->done.lock, flags);
return old_state;
}
void usbnet_defer_kevent (struct usbnet *dev, int work)
{
set_bit (work, &dev->flags);
if (!schedule_work (&dev->kevent)) {
if (net_ratelimit())
netdev_err(dev->net, "kevent %d may have been dropped\n", work);
} else {
netdev_dbg(dev->net, "kevent %d scheduled\n", work);
}
}
static int rx_submit (struct usbnet *dev, struct urb *urb, gfp_t flags)
{
struct sk_buff *skb;
struct skb_data *entry;
int retval = 0;
unsigned long lockflags;
size_t size = dev->rx_urb_size;
if (test_bit(EVENT_RX_KILL, &dev->flags)) {
usb_free_urb(urb);
return -ENOLINK;
}
skb = __netdev_alloc_skb_ip_align(dev->net, size, flags);
if (!skb) {
netif_dbg(dev, rx_err, dev->net, "no rx skb\n");
usbnet_defer_kevent (dev, EVENT_RX_MEMORY);
usb_free_urb (urb);
return -ENOMEM;
}
entry = (struct skb_data *) skb->cb;
entry->urb = urb;
entry->dev = dev;
entry->length = 0;
usb_fill_bulk_urb (urb, dev->udev, dev->in,
skb->data, size, rx_complete, skb);
spin_lock_irqsave (&dev->rxq.lock, lockflags);
if (netif_running (dev->net) &&
netif_device_present (dev->net) &&
!test_bit (EVENT_RX_HALT, &dev->flags) &&
!test_bit (EVENT_DEV_ASLEEP, &dev->flags)) {
switch (retval = usb_submit_urb (urb, GFP_ATOMIC)) {
case -EPIPE:
usbnet_defer_kevent (dev, EVENT_RX_HALT);
break;
case -ENOMEM:
usbnet_defer_kevent (dev, EVENT_RX_MEMORY);
break;
case -ENODEV:
netif_dbg(dev, ifdown, dev->net, "device gone\n");
netif_device_detach (dev->net);
break;
case -EHOSTUNREACH:
retval = -ENOLINK;
break;
default:
netif_dbg(dev, rx_err, dev->net,
"rx submit, %d\n", retval);
tasklet_schedule (&dev->bh);
break;
case 0:
__usbnet_queue_skb(&dev->rxq, skb, rx_start);
}
} else {
netif_dbg(dev, ifdown, dev->net, "rx: stopped\n");
retval = -ENOLINK;
}
spin_unlock_irqrestore (&dev->rxq.lock, lockflags);
if (retval) {
dev_kfree_skb_any (skb);
usb_free_urb (urb);
}
return retval;
}
static inline void rx_process (struct usbnet *dev, struct sk_buff *skb)
{
if (dev->driver_info->rx_fixup &&
!dev->driver_info->rx_fixup (dev, skb)) {
if (!(dev->driver_info->flags & FLAG_RX_ASSEMBLE))
dev->net->stats.rx_errors++;
goto done;
}
if (skb->len) {
if (dev->driver_info->flags & FLAG_MULTI_PACKET)
dev_kfree_skb_any(skb);
else
usbnet_skb_return(dev, skb);
return;
}
netif_dbg(dev, rx_err, dev->net, "drop\n");
dev->net->stats.rx_errors++;
done:
skb_queue_tail(&dev->done, skb);
}
static void rx_complete (struct urb *urb)
{
struct sk_buff *skb = (struct sk_buff *) urb->context;
struct skb_data *entry = (struct skb_data *) skb->cb;
struct usbnet *dev = entry->dev;
int urb_status = urb->status;
enum skb_state state;
skb_put (skb, urb->actual_length);
state = rx_done;
entry->urb = NULL;
switch (urb_status) {
case 0:
if (skb->len < dev->net->hard_header_len) {
state = rx_cleanup;
dev->net->stats.rx_errors++;
dev->net->stats.rx_length_errors++;
netif_dbg(dev, rx_err, dev->net,
"rx length %d\n", skb->len);
}
break;
case -EPIPE:
dev->net->stats.rx_errors++;
usbnet_defer_kevent (dev, EVENT_RX_HALT);
case -ECONNRESET:
case -ESHUTDOWN:
netif_dbg(dev, ifdown, dev->net,
"rx shutdown, code %d\n", urb_status);
goto block;
case -EPROTO:
case -ETIME:
case -EILSEQ:
dev->net->stats.rx_errors++;
if (!timer_pending (&dev->delay)) {
mod_timer (&dev->delay, jiffies + THROTTLE_JIFFIES);
netif_dbg(dev, link, dev->net,
"rx throttle %d\n", urb_status);
}
block:
state = rx_cleanup;
entry->urb = urb;
urb = NULL;
break;
case -EOVERFLOW:
dev->net->stats.rx_over_errors++;
default:
state = rx_cleanup;
dev->net->stats.rx_errors++;
netif_dbg(dev, rx_err, dev->net, "rx status %d\n", urb_status);
break;
}
if (++dev->pkt_cnt > 30) {
dev->pkt_cnt = 0;
dev->pkt_err = 0;
} else {
if (state == rx_cleanup)
dev->pkt_err++;
if (dev->pkt_err > 20)
set_bit(EVENT_RX_KILL, &dev->flags);
}
state = defer_bh(dev, skb, &dev->rxq, state);
if (urb) {
if (netif_running (dev->net) &&
!test_bit (EVENT_RX_HALT, &dev->flags) &&
state != unlink_start) {
rx_submit (dev, urb, GFP_ATOMIC);
usb_mark_last_busy(dev->udev);
return;
}
usb_free_urb (urb);
}
netif_dbg(dev, rx_err, dev->net, "no read resubmitted\n");
}
void usbnet_pause_rx(struct usbnet *dev)
{
set_bit(EVENT_RX_PAUSED, &dev->flags);
netif_dbg(dev, rx_status, dev->net, "paused rx queue enabled\n");
}
void usbnet_resume_rx(struct usbnet *dev)
{
struct sk_buff *skb;
int num = 0;
clear_bit(EVENT_RX_PAUSED, &dev->flags);
while ((skb = skb_dequeue(&dev->rxq_pause)) != NULL) {
usbnet_skb_return(dev, skb);
num++;
}
tasklet_schedule(&dev->bh);
netif_dbg(dev, rx_status, dev->net,
"paused rx queue disabled, %d skbs requeued\n", num);
}
void usbnet_purge_paused_rxq(struct usbnet *dev)
{
skb_queue_purge(&dev->rxq_pause);
}
static int unlink_urbs (struct usbnet *dev, struct sk_buff_head *q)
{
unsigned long flags;
struct sk_buff *skb;
int count = 0;
spin_lock_irqsave (&q->lock, flags);
while (!skb_queue_empty(q)) {
struct skb_data *entry;
struct urb *urb;
int retval;
skb_queue_walk(q, skb) {
entry = (struct skb_data *) skb->cb;
if (entry->state != unlink_start)
goto found;
}
break;
found:
entry->state = unlink_start;
urb = entry->urb;
usb_get_urb(urb);
spin_unlock_irqrestore(&q->lock, flags);
retval = usb_unlink_urb (urb);
if (retval != -EINPROGRESS && retval != 0)
netdev_dbg(dev->net, "unlink urb err, %d\n", retval);
else
count++;
usb_put_urb(urb);
spin_lock_irqsave(&q->lock, flags);
}
spin_unlock_irqrestore (&q->lock, flags);
return count;
}
void usbnet_unlink_rx_urbs(struct usbnet *dev)
{
if (netif_running(dev->net)) {
(void) unlink_urbs (dev, &dev->rxq);
tasklet_schedule(&dev->bh);
}
}
static void usbnet_terminate_urbs(struct usbnet *dev)
{
DECLARE_WAIT_QUEUE_HEAD_ONSTACK(unlink_wakeup);
DECLARE_WAITQUEUE(wait, current);
int temp;
add_wait_queue(&unlink_wakeup, &wait);
set_current_state(TASK_UNINTERRUPTIBLE);
dev->wait = &unlink_wakeup;
temp = unlink_urbs(dev, &dev->txq) +
unlink_urbs(dev, &dev->rxq);
while (!skb_queue_empty(&dev->rxq)
&& !skb_queue_empty(&dev->txq)
&& !skb_queue_empty(&dev->done)) {
schedule_timeout(msecs_to_jiffies(UNLINK_TIMEOUT_MS));
set_current_state(TASK_UNINTERRUPTIBLE);
netif_dbg(dev, ifdown, dev->net,
"waited for %d urb completions\n", temp);
}
set_current_state(TASK_RUNNING);
dev->wait = NULL;
remove_wait_queue(&unlink_wakeup, &wait);
}
int usbnet_stop (struct net_device *net)
{
struct usbnet *dev = netdev_priv(net);
struct driver_info *info = dev->driver_info;
int retval;
clear_bit(EVENT_DEV_OPEN, &dev->flags);
netif_stop_queue (net);
netif_info(dev, ifdown, dev->net,
"stop stats: rx/tx %lu/%lu, errs %lu/%lu\n",
net->stats.rx_packets, net->stats.tx_packets,
net->stats.rx_errors, net->stats.tx_errors);
if (info->stop) {
retval = info->stop(dev);
if (retval < 0)
netif_info(dev, ifdown, dev->net,
"stop fail (%d) usbnet usb-%s-%s, %s\n",
retval,
dev->udev->bus->bus_name, dev->udev->devpath,
info->description);
}
if (!(info->flags & FLAG_AVOID_UNLINK_URBS))
usbnet_terminate_urbs(dev);
usbnet_status_stop(dev);
usbnet_purge_paused_rxq(dev);
dev->flags = 0;
del_timer_sync (&dev->delay);
tasklet_kill (&dev->bh);
if (info->manage_power &&
!test_and_clear_bit(EVENT_NO_RUNTIME_PM, &dev->flags))
info->manage_power(dev, 0);
else
usb_autopm_put_interface(dev->intf);
return 0;
}
int usbnet_open (struct net_device *net)
{
struct usbnet *dev = netdev_priv(net);
int retval;
struct driver_info *info = dev->driver_info;
if ((retval = usb_autopm_get_interface(dev->intf)) < 0) {
netif_info(dev, ifup, dev->net,
"resumption fail (%d) usbnet usb-%s-%s, %s\n",
retval,
dev->udev->bus->bus_name,
dev->udev->devpath,
info->description);
goto done_nopm;
}
if (info->reset && (retval = info->reset (dev)) < 0) {
netif_info(dev, ifup, dev->net,
"open reset fail (%d) usbnet usb-%s-%s, %s\n",
retval,
dev->udev->bus->bus_name,
dev->udev->devpath,
info->description);
goto done;
}
usbnet_update_max_qlen(dev);
if (info->check_connect && (retval = info->check_connect (dev)) < 0) {
netif_dbg(dev, ifup, dev->net, "can't open; %d\n", retval);
goto done;
}
if (dev->interrupt) {
retval = usbnet_status_start(dev, GFP_KERNEL);
if (retval < 0) {
netif_err(dev, ifup, dev->net,
"intr submit %d\n", retval);
goto done;
}
}
set_bit(EVENT_DEV_OPEN, &dev->flags);
netif_start_queue (net);
netif_info(dev, ifup, dev->net,
"open: enable queueing (rx %d, tx %d) mtu %d %s framing\n",
(int)RX_QLEN(dev), (int)TX_QLEN(dev),
dev->net->mtu,
(dev->driver_info->flags & FLAG_FRAMING_NC) ? "NetChip" :
(dev->driver_info->flags & FLAG_FRAMING_GL) ? "GeneSys" :
(dev->driver_info->flags & FLAG_FRAMING_Z) ? "Zaurus" :
(dev->driver_info->flags & FLAG_FRAMING_RN) ? "RNDIS" :
(dev->driver_info->flags & FLAG_FRAMING_AX) ? "ASIX" :
"simple");
dev->pkt_cnt = 0;
dev->pkt_err = 0;
clear_bit(EVENT_RX_KILL, &dev->flags);
tasklet_schedule (&dev->bh);
if (info->manage_power) {
retval = info->manage_power(dev, 1);
if (retval < 0) {
retval = 0;
set_bit(EVENT_NO_RUNTIME_PM, &dev->flags);
} else {
usb_autopm_put_interface(dev->intf);
}
}
return retval;
done:
usb_autopm_put_interface(dev->intf);
done_nopm:
return retval;
}
int usbnet_get_settings (struct net_device *net, struct ethtool_cmd *cmd)
{
struct usbnet *dev = netdev_priv(net);
if (!dev->mii.mdio_read)
return -EOPNOTSUPP;
return mii_ethtool_gset(&dev->mii, cmd);
}
int usbnet_set_settings (struct net_device *net, struct ethtool_cmd *cmd)
{
struct usbnet *dev = netdev_priv(net);
int retval;
if (!dev->mii.mdio_write)
return -EOPNOTSUPP;
retval = mii_ethtool_sset(&dev->mii, cmd);
if (dev->driver_info->link_reset)
dev->driver_info->link_reset(dev);
usbnet_update_max_qlen(dev);
return retval;
}
u32 usbnet_get_link (struct net_device *net)
{
struct usbnet *dev = netdev_priv(net);
if (dev->driver_info->check_connect)
return dev->driver_info->check_connect (dev) == 0;
if (dev->mii.mdio_read)
return mii_link_ok(&dev->mii);
return ethtool_op_get_link(net);
}
int usbnet_nway_reset(struct net_device *net)
{
struct usbnet *dev = netdev_priv(net);
if (!dev->mii.mdio_write)
return -EOPNOTSUPP;
return mii_nway_restart(&dev->mii);
}
void usbnet_get_drvinfo (struct net_device *net, struct ethtool_drvinfo *info)
{
struct usbnet *dev = netdev_priv(net);
strlcpy (info->driver, dev->driver_name, sizeof info->driver);
strlcpy (info->version, DRIVER_VERSION, sizeof info->version);
strlcpy (info->fw_version, dev->driver_info->description,
sizeof info->fw_version);
usb_make_path (dev->udev, info->bus_info, sizeof info->bus_info);
}
u32 usbnet_get_msglevel (struct net_device *net)
{
struct usbnet *dev = netdev_priv(net);
return dev->msg_enable;
}
void usbnet_set_msglevel (struct net_device *net, u32 level)
{
struct usbnet *dev = netdev_priv(net);
dev->msg_enable = level;
}
static void __handle_link_change(struct usbnet *dev)
{
if (!test_bit(EVENT_DEV_OPEN, &dev->flags))
return;
if (!netif_carrier_ok(dev->net)) {
unlink_urbs(dev, &dev->rxq);
} else {
tasklet_schedule(&dev->bh);
}
usbnet_update_max_qlen(dev);
clear_bit(EVENT_LINK_CHANGE, &dev->flags);
}
static void
kevent (struct work_struct *work)
{
struct usbnet *dev =
container_of(work, struct usbnet, kevent);
int status;
if (test_bit (EVENT_TX_HALT, &dev->flags)) {
unlink_urbs (dev, &dev->txq);
status = usb_autopm_get_interface(dev->intf);
if (status < 0)
goto fail_pipe;
status = usb_clear_halt (dev->udev, dev->out);
usb_autopm_put_interface(dev->intf);
if (status < 0 &&
status != -EPIPE &&
status != -ESHUTDOWN) {
if (netif_msg_tx_err (dev))
fail_pipe:
netdev_err(dev->net, "can't clear tx halt, status %d\n",
status);
} else {
clear_bit (EVENT_TX_HALT, &dev->flags);
if (status != -ESHUTDOWN)
netif_wake_queue (dev->net);
}
}
if (test_bit (EVENT_RX_HALT, &dev->flags)) {
unlink_urbs (dev, &dev->rxq);
status = usb_autopm_get_interface(dev->intf);
if (status < 0)
goto fail_halt;
status = usb_clear_halt (dev->udev, dev->in);
usb_autopm_put_interface(dev->intf);
if (status < 0 &&
status != -EPIPE &&
status != -ESHUTDOWN) {
if (netif_msg_rx_err (dev))
fail_halt:
netdev_err(dev->net, "can't clear rx halt, status %d\n",
status);
} else {
clear_bit (EVENT_RX_HALT, &dev->flags);
tasklet_schedule (&dev->bh);
}
}
if (test_bit (EVENT_RX_MEMORY, &dev->flags)) {
struct urb *urb = NULL;
int resched = 1;
if (netif_running (dev->net))
urb = usb_alloc_urb (0, GFP_KERNEL);
else
clear_bit (EVENT_RX_MEMORY, &dev->flags);
if (urb != NULL) {
clear_bit (EVENT_RX_MEMORY, &dev->flags);
status = usb_autopm_get_interface(dev->intf);
if (status < 0) {
usb_free_urb(urb);
goto fail_lowmem;
}
if (rx_submit (dev, urb, GFP_KERNEL) == -ENOLINK)
resched = 0;
usb_autopm_put_interface(dev->intf);
fail_lowmem:
if (resched)
tasklet_schedule (&dev->bh);
}
}
if (test_bit (EVENT_LINK_RESET, &dev->flags)) {
struct driver_info *info = dev->driver_info;
int retval = 0;
clear_bit (EVENT_LINK_RESET, &dev->flags);
status = usb_autopm_get_interface(dev->intf);
if (status < 0)
goto skip_reset;
if(info->link_reset && (retval = info->link_reset(dev)) < 0) {
usb_autopm_put_interface(dev->intf);
skip_reset:
netdev_info(dev->net, "link reset failed (%d) usbnet usb-%s-%s, %s\n",
retval,
dev->udev->bus->bus_name,
dev->udev->devpath,
info->description);
} else {
usb_autopm_put_interface(dev->intf);
}
__handle_link_change(dev);
}
if (test_bit (EVENT_LINK_CHANGE, &dev->flags))
__handle_link_change(dev);
if (dev->flags)
netdev_dbg(dev->net, "kevent done, flags = 0x%lx\n", dev->flags);
}
static void tx_complete (struct urb *urb)
{
struct sk_buff *skb = (struct sk_buff *) urb->context;
struct skb_data *entry = (struct skb_data *) skb->cb;
struct usbnet *dev = entry->dev;
if (urb->status == 0) {
if (!(dev->driver_info->flags & FLAG_MULTI_PACKET))
dev->net->stats.tx_packets++;
dev->net->stats.tx_bytes += entry->length;
} else {
dev->net->stats.tx_errors++;
switch (urb->status) {
case -EPIPE:
usbnet_defer_kevent (dev, EVENT_TX_HALT);
break;
case -ECONNRESET:
case -ESHUTDOWN:
break;
case -EPROTO:
case -ETIME:
case -EILSEQ:
usb_mark_last_busy(dev->udev);
if (!timer_pending (&dev->delay)) {
mod_timer (&dev->delay,
jiffies + THROTTLE_JIFFIES);
netif_dbg(dev, link, dev->net,
"tx throttle %d\n", urb->status);
}
netif_stop_queue (dev->net);
break;
default:
netif_dbg(dev, tx_err, dev->net,
"tx err %d\n", entry->urb->status);
break;
}
}
usb_autopm_put_interface_async(dev->intf);
(void) defer_bh(dev, skb, &dev->txq, tx_done);
}
void usbnet_tx_timeout (struct net_device *net)
{
struct usbnet *dev = netdev_priv(net);
unlink_urbs (dev, &dev->txq);
tasklet_schedule (&dev->bh);
}
static int build_dma_sg(const struct sk_buff *skb, struct urb *urb)
{
unsigned num_sgs, total_len = 0;
int i, s = 0;
num_sgs = skb_shinfo(skb)->nr_frags + 1;
if (num_sgs == 1)
return 0;
urb->sg = kmalloc((num_sgs + 1) * sizeof(struct scatterlist),
GFP_ATOMIC);
if (!urb->sg)
return -ENOMEM;
urb->num_sgs = num_sgs;
sg_init_table(urb->sg, urb->num_sgs);
sg_set_buf(&urb->sg[s++], skb->data, skb_headlen(skb));
total_len += skb_headlen(skb);
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
struct skb_frag_struct *f = &skb_shinfo(skb)->frags[i];
total_len += skb_frag_size(f);
sg_set_page(&urb->sg[i + s], f->page.p, f->size,
f->page_offset);
}
urb->transfer_buffer_length = total_len;
return 1;
}
netdev_tx_t usbnet_start_xmit (struct sk_buff *skb,
struct net_device *net)
{
struct usbnet *dev = netdev_priv(net);
int length;
struct urb *urb = NULL;
struct skb_data *entry;
struct driver_info *info = dev->driver_info;
unsigned long flags;
int retval;
if (skb)
skb_tx_timestamp(skb);
if (info->tx_fixup) {
skb = info->tx_fixup (dev, skb, GFP_ATOMIC);
if (!skb) {
if (info->flags & FLAG_MULTI_PACKET)
goto not_drop;
netif_dbg(dev, tx_err, dev->net, "can't tx_fixup skb\n");
goto drop;
}
}
if (!(urb = usb_alloc_urb (0, GFP_ATOMIC))) {
netif_dbg(dev, tx_err, dev->net, "no urb\n");
goto drop;
}
entry = (struct skb_data *) skb->cb;
entry->urb = urb;
entry->dev = dev;
usb_fill_bulk_urb (urb, dev->udev, dev->out,
skb->data, skb->len, tx_complete, skb);
if (dev->can_dma_sg) {
if (build_dma_sg(skb, urb) < 0)
goto drop;
}
length = urb->transfer_buffer_length;
if (length % dev->maxpacket == 0) {
if (!(info->flags & FLAG_SEND_ZLP)) {
if (!(info->flags & FLAG_MULTI_PACKET)) {
length++;
if (skb_tailroom(skb) && !urb->num_sgs) {
skb->data[skb->len] = 0;
__skb_put(skb, 1);
} else if (urb->num_sgs)
sg_set_buf(&urb->sg[urb->num_sgs++],
dev->padding_pkt, 1);
}
} else
urb->transfer_flags |= URB_ZERO_PACKET;
}
entry->length = urb->transfer_buffer_length = length;
spin_lock_irqsave(&dev->txq.lock, flags);
retval = usb_autopm_get_interface_async(dev->intf);
if (retval < 0) {
spin_unlock_irqrestore(&dev->txq.lock, flags);
goto drop;
}
#ifdef CONFIG_PM
if (test_bit(EVENT_DEV_ASLEEP, &dev->flags)) {
usb_anchor_urb(urb, &dev->deferred);
netif_stop_queue(net);
usb_put_urb(urb);
spin_unlock_irqrestore(&dev->txq.lock, flags);
netdev_dbg(dev->net, "Delaying transmission for resumption\n");
goto deferred;
}
#endif
switch ((retval = usb_submit_urb (urb, GFP_ATOMIC))) {
case -EPIPE:
netif_stop_queue (net);
usbnet_defer_kevent (dev, EVENT_TX_HALT);
usb_autopm_put_interface_async(dev->intf);
break;
default:
usb_autopm_put_interface_async(dev->intf);
netif_dbg(dev, tx_err, dev->net,
"tx: submit urb err %d\n", retval);
break;
case 0:
net->trans_start = jiffies;
__usbnet_queue_skb(&dev->txq, skb, tx_start);
if (dev->txq.qlen >= TX_QLEN (dev))
netif_stop_queue (net);
}
spin_unlock_irqrestore (&dev->txq.lock, flags);
if (retval) {
netif_dbg(dev, tx_err, dev->net, "drop, code %d\n", retval);
drop:
dev->net->stats.tx_dropped++;
not_drop:
if (skb)
dev_kfree_skb_any (skb);
if (urb) {
kfree(urb->sg);
usb_free_urb(urb);
}
} else
netif_dbg(dev, tx_queued, dev->net,
"> tx, len %d, type 0x%x\n", length, skb->protocol);
#ifdef CONFIG_PM
deferred:
#endif
return NETDEV_TX_OK;
}
static int rx_alloc_submit(struct usbnet *dev, gfp_t flags)
{
struct urb *urb;
int i;
int ret = 0;
for (i = 0; i < 10 && dev->rxq.qlen < RX_QLEN(dev); i++) {
urb = usb_alloc_urb(0, flags);
if (urb != NULL) {
ret = rx_submit(dev, urb, flags);
if (ret)
goto err;
} else {
ret = -ENOMEM;
goto err;
}
}
err:
return ret;
}
static void usbnet_bh (unsigned long param)
{
struct usbnet *dev = (struct usbnet *) param;
struct sk_buff *skb;
struct skb_data *entry;
while ((skb = skb_dequeue (&dev->done))) {
entry = (struct skb_data *) skb->cb;
switch (entry->state) {
case rx_done:
entry->state = rx_cleanup;
rx_process (dev, skb);
continue;
case tx_done:
kfree(entry->urb->sg);
case rx_cleanup:
usb_free_urb (entry->urb);
dev_kfree_skb (skb);
continue;
default:
netdev_dbg(dev->net, "bogus skb state %d\n", entry->state);
}
}
clear_bit(EVENT_RX_KILL, &dev->flags);
if (dev->wait) {
if ((dev->txq.qlen + dev->rxq.qlen + dev->done.qlen) == 0) {
wake_up (dev->wait);
}
} else if (netif_running (dev->net) &&
netif_device_present (dev->net) &&
netif_carrier_ok(dev->net) &&
!timer_pending (&dev->delay) &&
!test_bit (EVENT_RX_HALT, &dev->flags)) {
int temp = dev->rxq.qlen;
if (temp < RX_QLEN(dev)) {
if (rx_alloc_submit(dev, GFP_ATOMIC) == -ENOLINK)
return;
if (temp != dev->rxq.qlen)
netif_dbg(dev, link, dev->net,
"rxqlen %d --> %d\n",
temp, dev->rxq.qlen);
if (dev->rxq.qlen < RX_QLEN(dev))
tasklet_schedule (&dev->bh);
}
if (dev->txq.qlen < TX_QLEN (dev))
netif_wake_queue (dev->net);
}
}
void usbnet_disconnect (struct usb_interface *intf)
{
struct usbnet *dev;
struct usb_device *xdev;
struct net_device *net;
dev = usb_get_intfdata(intf);
usb_set_intfdata(intf, NULL);
if (!dev)
return;
xdev = interface_to_usbdev (intf);
netif_info(dev, probe, dev->net, "unregister '%s' usb-%s-%s, %s\n",
intf->dev.driver->name,
xdev->bus->bus_name, xdev->devpath,
dev->driver_info->description);
net = dev->net;
unregister_netdev (net);
cancel_work_sync(&dev->kevent);
usb_scuttle_anchored_urbs(&dev->deferred);
if (dev->driver_info->unbind)
dev->driver_info->unbind (dev, intf);
usb_kill_urb(dev->interrupt);
usb_free_urb(dev->interrupt);
kfree(dev->padding_pkt);
free_netdev(net);
}
int
usbnet_probe (struct usb_interface *udev, const struct usb_device_id *prod)
{
struct usbnet *dev;
struct net_device *net;
struct usb_host_interface *interface;
struct driver_info *info;
struct usb_device *xdev;
int status;
const char *name;
struct usb_driver *driver = to_usb_driver(udev->dev.driver);
if (!driver->supports_autosuspend) {
driver->supports_autosuspend = 1;
pm_runtime_enable(&udev->dev);
}
name = udev->dev.driver->name;
info = (struct driver_info *) prod->driver_info;
if (!info) {
dev_dbg (&udev->dev, "blacklisted by %s\n", name);
return -ENODEV;
}
xdev = interface_to_usbdev (udev);
interface = udev->cur_altsetting;
status = -ENOMEM;
net = alloc_etherdev(sizeof(*dev));
if (!net)
goto out;
SET_NETDEV_DEV(net, &udev->dev);
dev = netdev_priv(net);
dev->udev = xdev;
dev->intf = udev;
dev->driver_info = info;
dev->driver_name = name;
dev->msg_enable = netif_msg_init (msg_level, NETIF_MSG_DRV
| NETIF_MSG_PROBE | NETIF_MSG_LINK);
skb_queue_head_init (&dev->rxq);
skb_queue_head_init (&dev->txq);
skb_queue_head_init (&dev->done);
skb_queue_head_init(&dev->rxq_pause);
dev->bh.func = usbnet_bh;
dev->bh.data = (unsigned long) dev;
INIT_WORK (&dev->kevent, kevent);
init_usb_anchor(&dev->deferred);
dev->delay.function = usbnet_bh;
dev->delay.data = (unsigned long) dev;
init_timer (&dev->delay);
mutex_init (&dev->phy_mutex);
mutex_init(&dev->interrupt_mutex);
dev->interrupt_count = 0;
dev->net = net;
strcpy (net->name, "usb%d");
memcpy (net->dev_addr, node_id, sizeof node_id);
dev->hard_mtu = net->mtu + net->hard_header_len;
#if 0
if (dma_supported (&udev->dev, DMA_BIT_MASK(64)))
net->features |= NETIF_F_HIGHDMA;
#endif
net->netdev_ops = &usbnet_netdev_ops;
net->watchdog_timeo = TX_TIMEOUT_JIFFIES;
net->ethtool_ops = &usbnet_ethtool_ops;
if (info->bind) {
status = info->bind (dev, udev);
if (status < 0)
goto out1;
if ((dev->driver_info->flags & FLAG_ETHER) != 0 &&
((dev->driver_info->flags & FLAG_POINTTOPOINT) == 0 ||
(net->dev_addr [0] & 0x02) == 0))
strcpy (net->name, "eth%d");
if ((dev->driver_info->flags & FLAG_WLAN) != 0)
strcpy(net->name, "wlan%d");
if ((dev->driver_info->flags & FLAG_WWAN) != 0)
strcpy(net->name, "wwan%d");
if ((dev->driver_info->flags & FLAG_NOARP) != 0)
net->flags |= IFF_NOARP;
if (net->mtu > (dev->hard_mtu - net->hard_header_len))
net->mtu = dev->hard_mtu - net->hard_header_len;
} else if (!info->in || !info->out)
status = usbnet_get_endpoints (dev, udev);
else {
dev->in = usb_rcvbulkpipe (xdev, info->in);
dev->out = usb_sndbulkpipe (xdev, info->out);
if (!(info->flags & FLAG_NO_SETINT))
status = usb_set_interface (xdev,
interface->desc.bInterfaceNumber,
interface->desc.bAlternateSetting);
else
status = 0;
}
if (status >= 0 && dev->status)
status = init_status (dev, udev);
if (status < 0)
goto out3;
if (!dev->rx_urb_size)
dev->rx_urb_size = dev->hard_mtu;
dev->maxpacket = usb_maxpacket (dev->udev, dev->out, 1);
if (ether_addr_equal(net->dev_addr, node_id))
net->addr_assign_type = NET_ADDR_RANDOM;
if ((dev->driver_info->flags & FLAG_WLAN) != 0)
SET_NETDEV_DEVTYPE(net, &wlan_type);
if ((dev->driver_info->flags & FLAG_WWAN) != 0)
SET_NETDEV_DEVTYPE(net, &wwan_type);
usbnet_update_max_qlen(dev);
if (dev->can_dma_sg && !(info->flags & FLAG_SEND_ZLP) &&
!(info->flags & FLAG_MULTI_PACKET)) {
dev->padding_pkt = kzalloc(1, GFP_KERNEL);
if (!dev->padding_pkt) {
status = -ENOMEM;
goto out4;
}
}
status = register_netdev (net);
if (status)
goto out5;
netif_info(dev, probe, dev->net,
"register '%s' at usb-%s-%s, %s, %pM\n",
udev->dev.driver->name,
xdev->bus->bus_name, xdev->devpath,
dev->driver_info->description,
net->dev_addr);
usb_set_intfdata (udev, dev);
netif_device_attach (net);
if (dev->driver_info->flags & FLAG_LINK_INTR)
usbnet_link_change(dev, 0, 0);
return 0;
out5:
kfree(dev->padding_pkt);
out4:
usb_free_urb(dev->interrupt);
out3:
if (info->unbind)
info->unbind (dev, udev);
out1:
free_netdev(net);
out:
return status;
}
int usbnet_suspend (struct usb_interface *intf, pm_message_t message)
{
struct usbnet *dev = usb_get_intfdata(intf);
if (!dev->suspend_count++) {
spin_lock_irq(&dev->txq.lock);
if (dev->txq.qlen && PMSG_IS_AUTO(message)) {
dev->suspend_count--;
spin_unlock_irq(&dev->txq.lock);
return -EBUSY;
} else {
set_bit(EVENT_DEV_ASLEEP, &dev->flags);
spin_unlock_irq(&dev->txq.lock);
}
netif_device_detach (dev->net);
usbnet_terminate_urbs(dev);
__usbnet_status_stop_force(dev);
netif_device_attach (dev->net);
}
return 0;
}
int usbnet_resume (struct usb_interface *intf)
{
struct usbnet *dev = usb_get_intfdata(intf);
struct sk_buff *skb;
struct urb *res;
int retval;
if (!--dev->suspend_count) {
__usbnet_status_start_force(dev, GFP_NOIO);
spin_lock_irq(&dev->txq.lock);
while ((res = usb_get_from_anchor(&dev->deferred))) {
skb = (struct sk_buff *)res->context;
retval = usb_submit_urb(res, GFP_ATOMIC);
if (retval < 0) {
dev_kfree_skb_any(skb);
kfree(res->sg);
usb_free_urb(res);
usb_autopm_put_interface_async(dev->intf);
} else {
dev->net->trans_start = jiffies;
__skb_queue_tail(&dev->txq, skb);
}
}
smp_mb();
clear_bit(EVENT_DEV_ASLEEP, &dev->flags);
spin_unlock_irq(&dev->txq.lock);
if (test_bit(EVENT_DEV_OPEN, &dev->flags)) {
if (!dev->wait &&
netif_device_present(dev->net) &&
!timer_pending(&dev->delay) &&
!test_bit(EVENT_RX_HALT, &dev->flags))
rx_alloc_submit(dev, GFP_NOIO);
if (!(dev->txq.qlen >= TX_QLEN(dev)))
netif_tx_wake_all_queues(dev->net);
tasklet_schedule (&dev->bh);
}
}
if (test_and_clear_bit(EVENT_DEVICE_REPORT_IDLE, &dev->flags))
usb_autopm_get_interface_no_resume(intf);
return 0;
}
void usbnet_device_suggests_idle(struct usbnet *dev)
{
if (!test_and_set_bit(EVENT_DEVICE_REPORT_IDLE, &dev->flags)) {
dev->intf->needs_remote_wakeup = 1;
usb_autopm_put_interface_async(dev->intf);
}
}
int usbnet_manage_power(struct usbnet *dev, int on)
{
dev->intf->needs_remote_wakeup = on;
return 0;
}
void usbnet_link_change(struct usbnet *dev, bool link, bool need_reset)
{
if (link && !need_reset)
netif_carrier_on(dev->net);
else
netif_carrier_off(dev->net);
if (need_reset && link)
usbnet_defer_kevent(dev, EVENT_LINK_RESET);
else
usbnet_defer_kevent(dev, EVENT_LINK_CHANGE);
}
static int __usbnet_read_cmd(struct usbnet *dev, u8 cmd, u8 reqtype,
u16 value, u16 index, void *data, u16 size)
{
void *buf = NULL;
int err = -ENOMEM;
netdev_dbg(dev->net, "usbnet_read_cmd cmd=0x%02x reqtype=%02x"
" value=0x%04x index=0x%04x size=%d\n",
cmd, reqtype, value, index, size);
if (data) {
buf = kmalloc(size, GFP_KERNEL);
if (!buf)
goto out;
}
err = usb_control_msg(dev->udev, usb_rcvctrlpipe(dev->udev, 0),
cmd, reqtype, value, index, buf, size,
USB_CTRL_GET_TIMEOUT);
if (err > 0 && err <= size)
memcpy(data, buf, err);
kfree(buf);
out:
return err;
}
static int __usbnet_write_cmd(struct usbnet *dev, u8 cmd, u8 reqtype,
u16 value, u16 index, const void *data,
u16 size)
{
void *buf = NULL;
int err = -ENOMEM;
netdev_dbg(dev->net, "usbnet_write_cmd cmd=0x%02x reqtype=%02x"
" value=0x%04x index=0x%04x size=%d\n",
cmd, reqtype, value, index, size);
if (data) {
buf = kmemdup(data, size, GFP_KERNEL);
if (!buf)
goto out;
}
err = usb_control_msg(dev->udev, usb_sndctrlpipe(dev->udev, 0),
cmd, reqtype, value, index, buf, size,
USB_CTRL_SET_TIMEOUT);
kfree(buf);
out:
return err;
}
int usbnet_read_cmd(struct usbnet *dev, u8 cmd, u8 reqtype,
u16 value, u16 index, void *data, u16 size)
{
int ret;
if (usb_autopm_get_interface(dev->intf) < 0)
return -ENODEV;
ret = __usbnet_read_cmd(dev, cmd, reqtype, value, index,
data, size);
usb_autopm_put_interface(dev->intf);
return ret;
}
int usbnet_write_cmd(struct usbnet *dev, u8 cmd, u8 reqtype,
u16 value, u16 index, const void *data, u16 size)
{
int ret;
if (usb_autopm_get_interface(dev->intf) < 0)
return -ENODEV;
ret = __usbnet_write_cmd(dev, cmd, reqtype, value, index,
data, size);
usb_autopm_put_interface(dev->intf);
return ret;
}
int usbnet_read_cmd_nopm(struct usbnet *dev, u8 cmd, u8 reqtype,
u16 value, u16 index, void *data, u16 size)
{
return __usbnet_read_cmd(dev, cmd, reqtype, value, index,
data, size);
}
int usbnet_write_cmd_nopm(struct usbnet *dev, u8 cmd, u8 reqtype,
u16 value, u16 index, const void *data,
u16 size)
{
return __usbnet_write_cmd(dev, cmd, reqtype, value, index,
data, size);
}
static void usbnet_async_cmd_cb(struct urb *urb)
{
struct usb_ctrlrequest *req = (struct usb_ctrlrequest *)urb->context;
int status = urb->status;
if (status < 0)
dev_dbg(&urb->dev->dev, "%s failed with %d",
__func__, status);
kfree(req);
usb_free_urb(urb);
}
int usbnet_write_cmd_async(struct usbnet *dev, u8 cmd, u8 reqtype,
u16 value, u16 index, const void *data, u16 size)
{
struct usb_ctrlrequest *req = NULL;
struct urb *urb;
int err = -ENOMEM;
void *buf = NULL;
netdev_dbg(dev->net, "usbnet_write_cmd cmd=0x%02x reqtype=%02x"
" value=0x%04x index=0x%04x size=%d\n",
cmd, reqtype, value, index, size);
urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!urb) {
netdev_err(dev->net, "Error allocating URB in"
" %s!\n", __func__);
goto fail;
}
if (data) {
buf = kmemdup(data, size, GFP_ATOMIC);
if (!buf) {
netdev_err(dev->net, "Error allocating buffer"
" in %s!\n", __func__);
goto fail_free;
}
}
req = kmalloc(sizeof(struct usb_ctrlrequest), GFP_ATOMIC);
if (!req)
goto fail_free_buf;
req->bRequestType = reqtype;
req->bRequest = cmd;
req->wValue = cpu_to_le16(value);
req->wIndex = cpu_to_le16(index);
req->wLength = cpu_to_le16(size);
usb_fill_control_urb(urb, dev->udev,
usb_sndctrlpipe(dev->udev, 0),
(void *)req, buf, size,
usbnet_async_cmd_cb, req);
urb->transfer_flags |= URB_FREE_BUFFER;
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err < 0) {
netdev_err(dev->net, "Error submitting the control"
" message: status=%d\n", err);
goto fail_free;
}
return 0;
fail_free_buf:
kfree(buf);
fail_free:
kfree(req);
usb_free_urb(urb);
fail:
return err;
}
static int __init usbnet_init(void)
{
BUILD_BUG_ON(
FIELD_SIZEOF(struct sk_buff, cb) < sizeof(struct skb_data));
eth_random_addr(node_id);
return 0;
}
static void __exit usbnet_exit(void)
{
}
