static struct gs_tx_context *gs_alloc_tx_context(struct gs_can *dev)
{
int i = 0;
unsigned long flags;
spin_lock_irqsave(&dev->tx_ctx_lock, flags);
for (; i < GS_MAX_TX_URBS; i++) {
if (dev->tx_context[i].echo_id == GS_MAX_TX_URBS) {
dev->tx_context[i].echo_id = i;
spin_unlock_irqrestore(&dev->tx_ctx_lock, flags);
return &dev->tx_context[i];
}
}
spin_unlock_irqrestore(&dev->tx_ctx_lock, flags);
return NULL;
}
static void gs_free_tx_context(struct gs_tx_context *txc)
{
txc->echo_id = GS_MAX_TX_URBS;
}
static struct gs_tx_context *gs_get_tx_context(struct gs_can *dev, unsigned int id)
{
unsigned long flags;
if (id < GS_MAX_TX_URBS) {
spin_lock_irqsave(&dev->tx_ctx_lock, flags);
if (dev->tx_context[id].echo_id == id) {
spin_unlock_irqrestore(&dev->tx_ctx_lock, flags);
return &dev->tx_context[id];
}
spin_unlock_irqrestore(&dev->tx_ctx_lock, flags);
}
return NULL;
}
static int gs_cmd_reset(struct gs_usb *gsusb, struct gs_can *gsdev)
{
struct gs_device_mode *dm;
struct usb_interface *intf = gsdev->iface;
int rc;
dm = kzalloc(sizeof(*dm), GFP_KERNEL);
if (!dm)
return -ENOMEM;
dm->mode = GS_CAN_MODE_RESET;
rc = usb_control_msg(interface_to_usbdev(intf),
usb_sndctrlpipe(interface_to_usbdev(intf), 0),
GS_USB_BREQ_MODE,
USB_DIR_OUT|USB_TYPE_VENDOR|USB_RECIP_INTERFACE,
gsdev->channel,
0,
dm,
sizeof(*dm),
1000);
return rc;
}
static void gs_update_state(struct gs_can *dev, struct can_frame *cf)
{
struct can_device_stats *can_stats = &dev->can.can_stats;
if (cf->can_id & CAN_ERR_RESTARTED) {
dev->can.state = CAN_STATE_ERROR_ACTIVE;
can_stats->restarts++;
} else if (cf->can_id & CAN_ERR_BUSOFF) {
dev->can.state = CAN_STATE_BUS_OFF;
can_stats->bus_off++;
} else if (cf->can_id & CAN_ERR_CRTL) {
if ((cf->data[1] & CAN_ERR_CRTL_TX_WARNING) ||
(cf->data[1] & CAN_ERR_CRTL_RX_WARNING)) {
dev->can.state = CAN_STATE_ERROR_WARNING;
can_stats->error_warning++;
} else if ((cf->data[1] & CAN_ERR_CRTL_TX_PASSIVE) ||
(cf->data[1] & CAN_ERR_CRTL_RX_PASSIVE)) {
dev->can.state = CAN_STATE_ERROR_PASSIVE;
can_stats->error_passive++;
} else {
dev->can.state = CAN_STATE_ERROR_ACTIVE;
}
}
}
static void gs_usb_recieve_bulk_callback(struct urb *urb)
{
struct gs_usb *usbcan = urb->context;
struct gs_can *dev;
struct net_device *netdev;
int rc;
struct net_device_stats *stats;
struct gs_host_frame *hf = urb->transfer_buffer;
struct gs_tx_context *txc;
struct can_frame *cf;
struct sk_buff *skb;
BUG_ON(!usbcan);
switch (urb->status) {
case 0:
break;
case -ENOENT:
case -ESHUTDOWN:
return;
default:
return;
}
if (hf->channel >= GS_MAX_INTF)
goto resubmit_urb;
dev = usbcan->canch[hf->channel];
netdev = dev->netdev;
stats = &netdev->stats;
if (!netif_device_present(netdev))
return;
if (hf->echo_id == -1) {
skb = alloc_can_skb(dev->netdev, &cf);
if (!skb)
return;
cf->can_id = hf->can_id;
cf->can_dlc = get_can_dlc(hf->can_dlc);
memcpy(cf->data, hf->data, 8);
if (hf->can_id & CAN_ERR_FLAG)
gs_update_state(dev, cf);
netdev->stats.rx_packets++;
netdev->stats.rx_bytes += hf->can_dlc;
netif_rx(skb);
} else {
if (hf->echo_id >= GS_MAX_TX_URBS) {
netdev_err(netdev,
"Unexpected out of range echo id %d\n",
hf->echo_id);
goto resubmit_urb;
}
netdev->stats.tx_packets++;
netdev->stats.tx_bytes += hf->can_dlc;
txc = gs_get_tx_context(dev, hf->echo_id);
if (!txc) {
netdev_err(netdev,
"Unexpected unused echo id %d\n",
hf->echo_id);
goto resubmit_urb;
}
can_get_echo_skb(netdev, hf->echo_id);
gs_free_tx_context(txc);
netif_wake_queue(netdev);
}
if (hf->flags & GS_CAN_FLAG_OVERFLOW) {
skb = alloc_can_err_skb(netdev, &cf);
if (!skb)
goto resubmit_urb;
cf->can_id |= CAN_ERR_CRTL;
cf->can_dlc = CAN_ERR_DLC;
cf->data[1] = CAN_ERR_CRTL_RX_OVERFLOW;
stats->rx_over_errors++;
stats->rx_errors++;
netif_rx(skb);
}
resubmit_urb:
usb_fill_bulk_urb(urb,
usbcan->udev,
usb_rcvbulkpipe(usbcan->udev, GSUSB_ENDPOINT_IN),
hf,
sizeof(struct gs_host_frame),
gs_usb_recieve_bulk_callback,
usbcan
);
rc = usb_submit_urb(urb, GFP_ATOMIC);
if (rc == -ENODEV) {
for (rc = 0; rc < GS_MAX_INTF; rc++) {
if (usbcan->canch[rc])
netif_device_detach(usbcan->canch[rc]->netdev);
}
}
}
static int gs_usb_set_bittiming(struct net_device *netdev)
{
struct gs_can *dev = netdev_priv(netdev);
struct can_bittiming *bt = &dev->can.bittiming;
struct usb_interface *intf = dev->iface;
int rc;
struct gs_device_bittiming *dbt;
dbt = kmalloc(sizeof(*dbt), GFP_KERNEL);
if (!dbt)
return -ENOMEM;
dbt->prop_seg = bt->prop_seg;
dbt->phase_seg1 = bt->phase_seg1;
dbt->phase_seg2 = bt->phase_seg2;
dbt->sjw = bt->sjw;
dbt->brp = bt->brp;
rc = usb_control_msg(interface_to_usbdev(intf),
usb_sndctrlpipe(interface_to_usbdev(intf), 0),
GS_USB_BREQ_BITTIMING,
USB_DIR_OUT|USB_TYPE_VENDOR|USB_RECIP_INTERFACE,
dev->channel,
0,
dbt,
sizeof(*dbt),
1000);
kfree(dbt);
if (rc < 0)
dev_err(netdev->dev.parent, "Couldn't set bittimings (err=%d)",
rc);
return rc;
}
static void gs_usb_xmit_callback(struct urb *urb)
{
struct gs_tx_context *txc = urb->context;
struct gs_can *dev = txc->dev;
struct net_device *netdev = dev->netdev;
if (urb->status)
netdev_info(netdev, "usb xmit fail %d\n", txc->echo_id);
usb_free_coherent(urb->dev,
urb->transfer_buffer_length,
urb->transfer_buffer,
urb->transfer_dma);
atomic_dec(&dev->active_tx_urbs);
if (!netif_device_present(netdev))
return;
if (netif_queue_stopped(netdev))
netif_wake_queue(netdev);
}
static netdev_tx_t gs_can_start_xmit(struct sk_buff *skb, struct net_device *netdev)
{
struct gs_can *dev = netdev_priv(netdev);
struct net_device_stats *stats = &dev->netdev->stats;
struct urb *urb;
struct gs_host_frame *hf;
struct can_frame *cf;
int rc;
unsigned int idx;
struct gs_tx_context *txc;
if (can_dropped_invalid_skb(netdev, skb))
return NETDEV_TX_OK;
txc = gs_alloc_tx_context(dev);
if (!txc)
return NETDEV_TX_BUSY;
urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!urb) {
netdev_err(netdev, "No memory left for URB\n");
goto nomem_urb;
}
hf = usb_alloc_coherent(dev->udev, sizeof(*hf), GFP_ATOMIC,
&urb->transfer_dma);
if (!hf) {
netdev_err(netdev, "No memory left for USB buffer\n");
goto nomem_hf;
}
idx = txc->echo_id;
if (idx >= GS_MAX_TX_URBS) {
netdev_err(netdev, "Invalid tx context %d\n", idx);
goto badidx;
}
hf->echo_id = idx;
hf->channel = dev->channel;
cf = (struct can_frame *)skb->data;
hf->can_id = cf->can_id;
hf->can_dlc = cf->can_dlc;
memcpy(hf->data, cf->data, cf->can_dlc);
usb_fill_bulk_urb(urb, dev->udev,
usb_sndbulkpipe(dev->udev, GSUSB_ENDPOINT_OUT),
hf,
sizeof(*hf),
gs_usb_xmit_callback,
txc);
urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
usb_anchor_urb(urb, &dev->tx_submitted);
can_put_echo_skb(skb, netdev, idx);
atomic_inc(&dev->active_tx_urbs);
rc = usb_submit_urb(urb, GFP_ATOMIC);
if (unlikely(rc)) {
atomic_dec(&dev->active_tx_urbs);
can_free_echo_skb(netdev, idx);
gs_free_tx_context(txc);
usb_unanchor_urb(urb);
usb_free_coherent(dev->udev,
sizeof(*hf),
hf,
urb->transfer_dma);
if (rc == -ENODEV) {
netif_device_detach(netdev);
} else {
netdev_err(netdev, "usb_submit failed (err=%d)\n", rc);
stats->tx_dropped++;
}
} else {
if (atomic_read(&dev->active_tx_urbs) >= GS_MAX_TX_URBS)
netif_stop_queue(netdev);
}
usb_free_urb(urb);
return NETDEV_TX_OK;
badidx:
usb_free_coherent(dev->udev,
sizeof(*hf),
hf,
urb->transfer_dma);
nomem_hf:
usb_free_urb(urb);
nomem_urb:
gs_free_tx_context(txc);
dev_kfree_skb(skb);
stats->tx_dropped++;
return NETDEV_TX_OK;
}
static int gs_can_open(struct net_device *netdev)
{
struct gs_can *dev = netdev_priv(netdev);
struct gs_usb *parent = dev->parent;
int rc, i;
struct gs_device_mode *dm;
u32 ctrlmode;
rc = open_candev(netdev);
if (rc)
return rc;
if (atomic_add_return(1, &parent->active_channels) == 1) {
for (i = 0; i < GS_MAX_RX_URBS; i++) {
struct urb *urb;
u8 *buf;
urb = usb_alloc_urb(0, GFP_KERNEL);
if (!urb) {
netdev_err(netdev,
"No memory left for URB\n");
return -ENOMEM;
}
buf = usb_alloc_coherent(dev->udev,
sizeof(struct gs_host_frame),
GFP_KERNEL,
&urb->transfer_dma);
if (!buf) {
netdev_err(netdev,
"No memory left for USB buffer\n");
usb_free_urb(urb);
return -ENOMEM;
}
usb_fill_bulk_urb(urb,
dev->udev,
usb_rcvbulkpipe(dev->udev,
GSUSB_ENDPOINT_IN),
buf,
sizeof(struct gs_host_frame),
gs_usb_recieve_bulk_callback,
parent);
urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
usb_anchor_urb(urb, &parent->rx_submitted);
rc = usb_submit_urb(urb, GFP_KERNEL);
if (rc) {
if (rc == -ENODEV)
netif_device_detach(dev->netdev);
netdev_err(netdev,
"usb_submit failed (err=%d)\n",
rc);
usb_unanchor_urb(urb);
break;
}
usb_free_urb(urb);
}
}
dm = kmalloc(sizeof(*dm), GFP_KERNEL);
if (!dm)
return -ENOMEM;
ctrlmode = dev->can.ctrlmode;
dm->flags = 0;
if (ctrlmode & CAN_CTRLMODE_LOOPBACK)
dm->flags |= GS_CAN_MODE_LOOP_BACK;
else if (ctrlmode & CAN_CTRLMODE_LISTENONLY)
dm->flags |= GS_CAN_MODE_LISTEN_ONLY;
if (ctrlmode & CAN_CTRLMODE_ONE_SHOT)
dm->flags |= GS_CAN_MODE_ONE_SHOT;
if (ctrlmode & CAN_CTRLMODE_3_SAMPLES)
dm->flags |= GS_CAN_MODE_TRIPLE_SAMPLE;
dm->mode = GS_CAN_MODE_START;
rc = usb_control_msg(interface_to_usbdev(dev->iface),
usb_sndctrlpipe(interface_to_usbdev(dev->iface), 0),
GS_USB_BREQ_MODE,
USB_DIR_OUT|USB_TYPE_VENDOR|USB_RECIP_INTERFACE,
dev->channel,
0,
dm,
sizeof(*dm),
1000);
if (rc < 0) {
netdev_err(netdev, "Couldn't start device (err=%d)\n", rc);
kfree(dm);
return rc;
}
kfree(dm);
dev->can.state = CAN_STATE_ERROR_ACTIVE;
if (!(dev->can.ctrlmode & CAN_CTRLMODE_LISTENONLY))
netif_start_queue(netdev);
return 0;
}
static int gs_can_close(struct net_device *netdev)
{
int rc;
struct gs_can *dev = netdev_priv(netdev);
struct gs_usb *parent = dev->parent;
netif_stop_queue(netdev);
if (atomic_dec_and_test(&parent->active_channels))
usb_kill_anchored_urbs(&parent->rx_submitted);
usb_kill_anchored_urbs(&dev->tx_submitted);
atomic_set(&dev->active_tx_urbs, 0);
rc = gs_cmd_reset(parent, dev);
if (rc < 0)
netdev_warn(netdev, "Couldn't shutdown device (err=%d)", rc);
for (rc = 0; rc < GS_MAX_TX_URBS; rc++) {
dev->tx_context[rc].dev = dev;
dev->tx_context[rc].echo_id = GS_MAX_TX_URBS;
}
close_candev(netdev);
return 0;
}
static struct gs_can *gs_make_candev(unsigned int channel, struct usb_interface *intf)
{
struct gs_can *dev;
struct net_device *netdev;
int rc;
struct gs_device_bt_const *bt_const;
bt_const = kmalloc(sizeof(*bt_const), GFP_KERNEL);
if (!bt_const)
return ERR_PTR(-ENOMEM);
rc = usb_control_msg(interface_to_usbdev(intf),
usb_rcvctrlpipe(interface_to_usbdev(intf), 0),
GS_USB_BREQ_BT_CONST,
USB_DIR_IN|USB_TYPE_VENDOR|USB_RECIP_INTERFACE,
channel,
0,
bt_const,
sizeof(*bt_const),
1000);
if (rc < 0) {
dev_err(&intf->dev,
"Couldn't get bit timing const for channel (err=%d)\n",
rc);
kfree(bt_const);
return ERR_PTR(rc);
}
netdev = alloc_candev(sizeof(struct gs_can), GS_MAX_TX_URBS);
if (!netdev) {
dev_err(&intf->dev, "Couldn't allocate candev\n");
kfree(bt_const);
return ERR_PTR(-ENOMEM);
}
dev = netdev_priv(netdev);
netdev->netdev_ops = &gs_usb_netdev_ops;
netdev->flags |= IFF_ECHO;
strcpy(dev->bt_const.name, "gs_usb");
dev->bt_const.tseg1_min = bt_const->tseg1_min;
dev->bt_const.tseg1_max = bt_const->tseg1_max;
dev->bt_const.tseg2_min = bt_const->tseg2_min;
dev->bt_const.tseg2_max = bt_const->tseg2_max;
dev->bt_const.sjw_max = bt_const->sjw_max;
dev->bt_const.brp_min = bt_const->brp_min;
dev->bt_const.brp_max = bt_const->brp_max;
dev->bt_const.brp_inc = bt_const->brp_inc;
dev->udev = interface_to_usbdev(intf);
dev->iface = intf;
dev->netdev = netdev;
dev->channel = channel;
init_usb_anchor(&dev->tx_submitted);
atomic_set(&dev->active_tx_urbs, 0);
spin_lock_init(&dev->tx_ctx_lock);
for (rc = 0; rc < GS_MAX_TX_URBS; rc++) {
dev->tx_context[rc].dev = dev;
dev->tx_context[rc].echo_id = GS_MAX_TX_URBS;
}
dev->can.state = CAN_STATE_STOPPED;
dev->can.clock.freq = bt_const->fclk_can;
dev->can.bittiming_const = &dev->bt_const;
dev->can.do_set_bittiming = gs_usb_set_bittiming;
dev->can.ctrlmode_supported = 0;
if (bt_const->feature & GS_CAN_FEATURE_LISTEN_ONLY)
dev->can.ctrlmode_supported |= CAN_CTRLMODE_LISTENONLY;
if (bt_const->feature & GS_CAN_FEATURE_LOOP_BACK)
dev->can.ctrlmode_supported |= CAN_CTRLMODE_LOOPBACK;
if (bt_const->feature & GS_CAN_FEATURE_TRIPLE_SAMPLE)
dev->can.ctrlmode_supported |= CAN_CTRLMODE_3_SAMPLES;
if (bt_const->feature & GS_CAN_FEATURE_ONE_SHOT)
dev->can.ctrlmode_supported |= CAN_CTRLMODE_ONE_SHOT;
kfree(bt_const);
SET_NETDEV_DEV(netdev, &intf->dev);
rc = register_candev(dev->netdev);
if (rc) {
free_candev(dev->netdev);
dev_err(&intf->dev, "Couldn't register candev (err=%d)\n", rc);
return ERR_PTR(rc);
}
return dev;
}
static void gs_destroy_candev(struct gs_can *dev)
{
unregister_candev(dev->netdev);
free_candev(dev->netdev);
usb_kill_anchored_urbs(&dev->tx_submitted);
kfree(dev);
}
static int gs_usb_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
struct gs_usb *dev;
int rc = -ENOMEM;
unsigned int icount, i;
struct gs_host_config *hconf;
struct gs_device_config *dconf;
hconf = kmalloc(sizeof(*hconf), GFP_KERNEL);
if (!hconf)
return -ENOMEM;
hconf->byte_order = 0x0000beef;
rc = usb_control_msg(interface_to_usbdev(intf),
usb_sndctrlpipe(interface_to_usbdev(intf), 0),
GS_USB_BREQ_HOST_FORMAT,
USB_DIR_OUT|USB_TYPE_VENDOR|USB_RECIP_INTERFACE,
1,
intf->altsetting[0].desc.bInterfaceNumber,
hconf,
sizeof(*hconf),
1000);
kfree(hconf);
if (rc < 0) {
dev_err(&intf->dev, "Couldn't send data format (err=%d)\n",
rc);
return rc;
}
dconf = kmalloc(sizeof(*dconf), GFP_KERNEL);
if (!dconf)
return -ENOMEM;
rc = usb_control_msg(interface_to_usbdev(intf),
usb_rcvctrlpipe(interface_to_usbdev(intf), 0),
GS_USB_BREQ_DEVICE_CONFIG,
USB_DIR_IN|USB_TYPE_VENDOR|USB_RECIP_INTERFACE,
1,
intf->altsetting[0].desc.bInterfaceNumber,
dconf,
sizeof(*dconf),
1000);
if (rc < 0) {
dev_err(&intf->dev, "Couldn't get device config: (err=%d)\n",
rc);
kfree(dconf);
return rc;
}
icount = dconf->icount+1;
kfree(dconf);
dev_info(&intf->dev, "Configuring for %d interfaces\n", icount);
if (icount > GS_MAX_INTF) {
dev_err(&intf->dev,
"Driver cannot handle more that %d CAN interfaces\n",
GS_MAX_INTF);
return -EINVAL;
}
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
init_usb_anchor(&dev->rx_submitted);
atomic_set(&dev->active_channels, 0);
usb_set_intfdata(intf, dev);
dev->udev = interface_to_usbdev(intf);
for (i = 0; i < icount; i++) {
dev->canch[i] = gs_make_candev(i, intf);
if (IS_ERR_OR_NULL(dev->canch[i])) {
icount = i;
for (i = 0; i < icount; i++) {
gs_destroy_candev(dev->canch[i]);
dev->canch[i] = NULL;
}
kfree(dev);
return rc;
}
dev->canch[i]->parent = dev;
}
return 0;
}
static void gs_usb_disconnect(struct usb_interface *intf)
{
unsigned i;
struct gs_usb *dev = usb_get_intfdata(intf);
usb_set_intfdata(intf, NULL);
if (!dev) {
dev_err(&intf->dev, "Disconnect (nodata)\n");
return;
}
for (i = 0; i < GS_MAX_INTF; i++) {
struct gs_can *can = dev->canch[i];
if (!can)
continue;
gs_destroy_candev(can);
}
usb_kill_anchored_urbs(&dev->rx_submitted);
}
