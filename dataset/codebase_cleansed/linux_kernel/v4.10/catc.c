static void catc_rx_done(struct urb *urb)
{
struct catc *catc = urb->context;
u8 *pkt_start = urb->transfer_buffer;
struct sk_buff *skb;
int pkt_len, pkt_offset = 0;
int status = urb->status;
if (!catc->is_f5u011) {
clear_bit(RX_RUNNING, &catc->flags);
pkt_offset = 2;
}
if (status) {
dev_dbg(&urb->dev->dev, "rx_done, status %d, length %d\n",
status, urb->actual_length);
return;
}
do {
if(!catc->is_f5u011) {
pkt_len = le16_to_cpup((__le16*)pkt_start);
if (pkt_len > urb->actual_length) {
catc->netdev->stats.rx_length_errors++;
catc->netdev->stats.rx_errors++;
break;
}
} else {
pkt_len = urb->actual_length;
}
if (!(skb = dev_alloc_skb(pkt_len)))
return;
skb_copy_to_linear_data(skb, pkt_start + pkt_offset, pkt_len);
skb_put(skb, pkt_len);
skb->protocol = eth_type_trans(skb, catc->netdev);
netif_rx(skb);
catc->netdev->stats.rx_packets++;
catc->netdev->stats.rx_bytes += pkt_len;
if (catc->is_f5u011)
break;
pkt_start += (((pkt_len + 1) >> 6) + 1) << 6;
} while (pkt_start - (u8 *) urb->transfer_buffer < urb->actual_length);
if (catc->is_f5u011) {
if (atomic_read(&catc->recq_sz)) {
int state;
atomic_dec(&catc->recq_sz);
netdev_dbg(catc->netdev, "getting extra packet\n");
urb->dev = catc->usbdev;
if ((state = usb_submit_urb(urb, GFP_ATOMIC)) < 0) {
netdev_dbg(catc->netdev,
"submit(rx_urb) status %d\n", state);
}
} else {
clear_bit(RX_RUNNING, &catc->flags);
}
}
}
static void catc_irq_done(struct urb *urb)
{
struct catc *catc = urb->context;
u8 *data = urb->transfer_buffer;
int status = urb->status;
unsigned int hasdata = 0, linksts = LinkNoChange;
int res;
if (!catc->is_f5u011) {
hasdata = data[1] & 0x80;
if (data[1] & 0x40)
linksts = LinkGood;
else if (data[1] & 0x20)
linksts = LinkBad;
} else {
hasdata = (unsigned int)(be16_to_cpup((__be16*)data) & 0x0fff);
if (data[0] == 0x90)
linksts = LinkGood;
else if (data[0] == 0xA0)
linksts = LinkBad;
}
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
return;
default:
dev_dbg(&urb->dev->dev,
"irq_done, status %d, data %02x %02x.\n",
status, data[0], data[1]);
goto resubmit;
}
if (linksts == LinkGood) {
netif_carrier_on(catc->netdev);
netdev_dbg(catc->netdev, "link ok\n");
}
if (linksts == LinkBad) {
netif_carrier_off(catc->netdev);
netdev_dbg(catc->netdev, "link bad\n");
}
if (hasdata) {
if (test_and_set_bit(RX_RUNNING, &catc->flags)) {
if (catc->is_f5u011)
atomic_inc(&catc->recq_sz);
} else {
catc->rx_urb->dev = catc->usbdev;
if ((res = usb_submit_urb(catc->rx_urb, GFP_ATOMIC)) < 0) {
dev_err(&catc->usbdev->dev,
"submit(rx_urb) status %d\n", res);
}
}
}
resubmit:
res = usb_submit_urb (urb, GFP_ATOMIC);
if (res)
dev_err(&catc->usbdev->dev,
"can't resubmit intr, %s-%s, status %d\n",
catc->usbdev->bus->bus_name,
catc->usbdev->devpath, res);
}
static int catc_tx_run(struct catc *catc)
{
int status;
if (catc->is_f5u011)
catc->tx_ptr = (catc->tx_ptr + 63) & ~63;
catc->tx_urb->transfer_buffer_length = catc->tx_ptr;
catc->tx_urb->transfer_buffer = catc->tx_buf[catc->tx_idx];
catc->tx_urb->dev = catc->usbdev;
if ((status = usb_submit_urb(catc->tx_urb, GFP_ATOMIC)) < 0)
dev_err(&catc->usbdev->dev, "submit(tx_urb), status %d\n",
status);
catc->tx_idx = !catc->tx_idx;
catc->tx_ptr = 0;
netif_trans_update(catc->netdev);
return status;
}
static void catc_tx_done(struct urb *urb)
{
struct catc *catc = urb->context;
unsigned long flags;
int r, status = urb->status;
if (status == -ECONNRESET) {
dev_dbg(&urb->dev->dev, "Tx Reset.\n");
urb->status = 0;
netif_trans_update(catc->netdev);
catc->netdev->stats.tx_errors++;
clear_bit(TX_RUNNING, &catc->flags);
netif_wake_queue(catc->netdev);
return;
}
if (status) {
dev_dbg(&urb->dev->dev, "tx_done, status %d, length %d\n",
status, urb->actual_length);
return;
}
spin_lock_irqsave(&catc->tx_lock, flags);
if (catc->tx_ptr) {
r = catc_tx_run(catc);
if (unlikely(r < 0))
clear_bit(TX_RUNNING, &catc->flags);
} else {
clear_bit(TX_RUNNING, &catc->flags);
}
netif_wake_queue(catc->netdev);
spin_unlock_irqrestore(&catc->tx_lock, flags);
}
static netdev_tx_t catc_start_xmit(struct sk_buff *skb,
struct net_device *netdev)
{
struct catc *catc = netdev_priv(netdev);
unsigned long flags;
int r = 0;
char *tx_buf;
spin_lock_irqsave(&catc->tx_lock, flags);
catc->tx_ptr = (((catc->tx_ptr - 1) >> 6) + 1) << 6;
tx_buf = catc->tx_buf[catc->tx_idx] + catc->tx_ptr;
if (catc->is_f5u011)
*(__be16 *)tx_buf = cpu_to_be16(skb->len);
else
*(__le16 *)tx_buf = cpu_to_le16(skb->len);
skb_copy_from_linear_data(skb, tx_buf + 2, skb->len);
catc->tx_ptr += skb->len + 2;
if (!test_and_set_bit(TX_RUNNING, &catc->flags)) {
r = catc_tx_run(catc);
if (r < 0)
clear_bit(TX_RUNNING, &catc->flags);
}
if ((catc->is_f5u011 && catc->tx_ptr) ||
(catc->tx_ptr >= ((TX_MAX_BURST - 1) * (PKT_SZ + 2))))
netif_stop_queue(netdev);
spin_unlock_irqrestore(&catc->tx_lock, flags);
if (r >= 0) {
catc->netdev->stats.tx_bytes += skb->len;
catc->netdev->stats.tx_packets++;
}
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static void catc_tx_timeout(struct net_device *netdev)
{
struct catc *catc = netdev_priv(netdev);
dev_warn(&netdev->dev, "Transmit timed out.\n");
usb_unlink_urb(catc->tx_urb);
}
static int catc_ctrl_msg(struct catc *catc, u8 dir, u8 request, u16 value, u16 index, void *buf, int len)
{
int retval = usb_control_msg(catc->usbdev,
dir ? usb_rcvctrlpipe(catc->usbdev, 0) : usb_sndctrlpipe(catc->usbdev, 0),
request, 0x40 | dir, value, index, buf, len, 1000);
return retval < 0 ? retval : 0;
}
static void catc_ctrl_run(struct catc *catc)
{
struct ctrl_queue *q = catc->ctrl_queue + catc->ctrl_tail;
struct usb_device *usbdev = catc->usbdev;
struct urb *urb = catc->ctrl_urb;
struct usb_ctrlrequest *dr = &catc->ctrl_dr;
int status;
dr->bRequest = q->request;
dr->bRequestType = 0x40 | q->dir;
dr->wValue = cpu_to_le16(q->value);
dr->wIndex = cpu_to_le16(q->index);
dr->wLength = cpu_to_le16(q->len);
urb->pipe = q->dir ? usb_rcvctrlpipe(usbdev, 0) : usb_sndctrlpipe(usbdev, 0);
urb->transfer_buffer_length = q->len;
urb->transfer_buffer = catc->ctrl_buf;
urb->setup_packet = (void *) dr;
urb->dev = usbdev;
if (!q->dir && q->buf && q->len)
memcpy(catc->ctrl_buf, q->buf, q->len);
if ((status = usb_submit_urb(catc->ctrl_urb, GFP_ATOMIC)))
dev_err(&catc->usbdev->dev, "submit(ctrl_urb) status %d\n",
status);
}
static void catc_ctrl_done(struct urb *urb)
{
struct catc *catc = urb->context;
struct ctrl_queue *q;
unsigned long flags;
int status = urb->status;
if (status)
dev_dbg(&urb->dev->dev, "ctrl_done, status %d, len %d.\n",
status, urb->actual_length);
spin_lock_irqsave(&catc->ctrl_lock, flags);
q = catc->ctrl_queue + catc->ctrl_tail;
if (q->dir) {
if (q->buf && q->len)
memcpy(q->buf, catc->ctrl_buf, q->len);
else
q->buf = catc->ctrl_buf;
}
if (q->callback)
q->callback(catc, q);
catc->ctrl_tail = (catc->ctrl_tail + 1) & (CTRL_QUEUE - 1);
if (catc->ctrl_head != catc->ctrl_tail)
catc_ctrl_run(catc);
else
clear_bit(CTRL_RUNNING, &catc->flags);
spin_unlock_irqrestore(&catc->ctrl_lock, flags);
}
static int catc_ctrl_async(struct catc *catc, u8 dir, u8 request, u16 value,
u16 index, void *buf, int len, void (*callback)(struct catc *catc, struct ctrl_queue *q))
{
struct ctrl_queue *q;
int retval = 0;
unsigned long flags;
spin_lock_irqsave(&catc->ctrl_lock, flags);
q = catc->ctrl_queue + catc->ctrl_head;
q->dir = dir;
q->request = request;
q->value = value;
q->index = index;
q->buf = buf;
q->len = len;
q->callback = callback;
catc->ctrl_head = (catc->ctrl_head + 1) & (CTRL_QUEUE - 1);
if (catc->ctrl_head == catc->ctrl_tail) {
dev_err(&catc->usbdev->dev, "ctrl queue full\n");
catc->ctrl_tail = (catc->ctrl_tail + 1) & (CTRL_QUEUE - 1);
retval = -1;
}
if (!test_and_set_bit(CTRL_RUNNING, &catc->flags))
catc_ctrl_run(catc);
spin_unlock_irqrestore(&catc->ctrl_lock, flags);
return retval;
}
static void catc_stats_done(struct catc *catc, struct ctrl_queue *q)
{
int index = q->index - EthStats;
u16 data, last;
catc->stats_buf[index] = *((char *)q->buf);
if (index & 1)
return;
data = ((u16)catc->stats_buf[index] << 8) | catc->stats_buf[index + 1];
last = catc->stats_vals[index >> 1];
switch (index) {
case TxSingleColl:
case TxMultiColl:
catc->netdev->stats.collisions += data - last;
break;
case TxExcessColl:
catc->netdev->stats.tx_aborted_errors += data - last;
catc->netdev->stats.tx_errors += data - last;
break;
case RxFramErr:
catc->netdev->stats.rx_frame_errors += data - last;
catc->netdev->stats.rx_errors += data - last;
break;
}
catc->stats_vals[index >> 1] = data;
}
static void catc_stats_timer(unsigned long data)
{
struct catc *catc = (void *) data;
int i;
for (i = 0; i < 8; i++)
catc_get_reg_async(catc, EthStats + 7 - i, catc_stats_done);
mod_timer(&catc->timer, jiffies + STATS_UPDATE);
}
static void catc_multicast(unsigned char *addr, u8 *multicast)
{
u32 crc;
crc = ether_crc_le(6, addr);
multicast[(crc >> 3) & 0x3f] |= 1 << (crc & 7);
}
static void catc_set_multicast_list(struct net_device *netdev)
{
struct catc *catc = netdev_priv(netdev);
struct netdev_hw_addr *ha;
u8 broadcast[ETH_ALEN];
u8 rx = RxEnable | RxPolarity | RxMultiCast;
eth_broadcast_addr(broadcast);
memset(catc->multicast, 0, 64);
catc_multicast(broadcast, catc->multicast);
catc_multicast(netdev->dev_addr, catc->multicast);
if (netdev->flags & IFF_PROMISC) {
memset(catc->multicast, 0xff, 64);
rx |= (!catc->is_f5u011) ? RxPromisc : AltRxPromisc;
}
if (netdev->flags & IFF_ALLMULTI) {
memset(catc->multicast, 0xff, 64);
} else {
netdev_for_each_mc_addr(ha, netdev) {
u32 crc = ether_crc_le(6, ha->addr);
if (!catc->is_f5u011) {
catc->multicast[(crc >> 3) & 0x3f] |= 1 << (crc & 7);
} else {
catc->multicast[7-(crc >> 29)] |= 1 << ((crc >> 26) & 7);
}
}
}
if (!catc->is_f5u011) {
catc_set_reg_async(catc, RxUnit, rx);
catc_write_mem_async(catc, 0xfa80, catc->multicast, 64);
} else {
f5u011_mchash_async(catc, catc->multicast);
if (catc->rxmode[0] != rx) {
catc->rxmode[0] = rx;
netdev_dbg(catc->netdev,
"Setting RX mode to %2.2X %2.2X\n",
catc->rxmode[0], catc->rxmode[1]);
f5u011_rxmode_async(catc, catc->rxmode);
}
}
}
static void catc_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
struct catc *catc = netdev_priv(dev);
strlcpy(info->driver, driver_name, sizeof(info->driver));
strlcpy(info->version, DRIVER_VERSION, sizeof(info->version));
usb_make_path(catc->usbdev, info->bus_info, sizeof(info->bus_info));
}
static int catc_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct catc *catc = netdev_priv(dev);
if (!catc->is_f5u011)
return -EOPNOTSUPP;
cmd->supported = SUPPORTED_10baseT_Half | SUPPORTED_TP;
cmd->advertising = ADVERTISED_10baseT_Half | ADVERTISED_TP;
ethtool_cmd_speed_set(cmd, SPEED_10);
cmd->duplex = DUPLEX_HALF;
cmd->port = PORT_TP;
cmd->phy_address = 0;
cmd->transceiver = XCVR_INTERNAL;
cmd->autoneg = AUTONEG_DISABLE;
cmd->maxtxpkt = 1;
cmd->maxrxpkt = 1;
return 0;
}
static int catc_open(struct net_device *netdev)
{
struct catc *catc = netdev_priv(netdev);
int status;
catc->irq_urb->dev = catc->usbdev;
if ((status = usb_submit_urb(catc->irq_urb, GFP_KERNEL)) < 0) {
dev_err(&catc->usbdev->dev, "submit(irq_urb) status %d\n",
status);
return -1;
}
netif_start_queue(netdev);
if (!catc->is_f5u011)
mod_timer(&catc->timer, jiffies + STATS_UPDATE);
return 0;
}
static int catc_stop(struct net_device *netdev)
{
struct catc *catc = netdev_priv(netdev);
netif_stop_queue(netdev);
if (!catc->is_f5u011)
del_timer_sync(&catc->timer);
usb_kill_urb(catc->rx_urb);
usb_kill_urb(catc->tx_urb);
usb_kill_urb(catc->irq_urb);
usb_kill_urb(catc->ctrl_urb);
return 0;
}
static int catc_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
struct device *dev = &intf->dev;
struct usb_device *usbdev = interface_to_usbdev(intf);
struct net_device *netdev;
struct catc *catc;
u8 broadcast[ETH_ALEN];
int pktsz, ret;
if (usb_set_interface(usbdev,
intf->altsetting->desc.bInterfaceNumber, 1)) {
dev_err(dev, "Can't set altsetting 1.\n");
return -EIO;
}
netdev = alloc_etherdev(sizeof(struct catc));
if (!netdev)
return -ENOMEM;
catc = netdev_priv(netdev);
netdev->netdev_ops = &catc_netdev_ops;
netdev->watchdog_timeo = TX_TIMEOUT;
netdev->ethtool_ops = &ops;
catc->usbdev = usbdev;
catc->netdev = netdev;
spin_lock_init(&catc->tx_lock);
spin_lock_init(&catc->ctrl_lock);
init_timer(&catc->timer);
catc->timer.data = (long) catc;
catc->timer.function = catc_stats_timer;
catc->ctrl_urb = usb_alloc_urb(0, GFP_KERNEL);
catc->tx_urb = usb_alloc_urb(0, GFP_KERNEL);
catc->rx_urb = usb_alloc_urb(0, GFP_KERNEL);
catc->irq_urb = usb_alloc_urb(0, GFP_KERNEL);
if ((!catc->ctrl_urb) || (!catc->tx_urb) ||
(!catc->rx_urb) || (!catc->irq_urb)) {
dev_err(&intf->dev, "No free urbs available.\n");
ret = -ENOMEM;
goto fail_free;
}
if (le16_to_cpu(usbdev->descriptor.idVendor) == 0x0423 &&
le16_to_cpu(usbdev->descriptor.idProduct) == 0xa &&
le16_to_cpu(catc->usbdev->descriptor.bcdDevice) == 0x0130) {
dev_dbg(dev, "Testing for f5u011\n");
catc->is_f5u011 = 1;
atomic_set(&catc->recq_sz, 0);
pktsz = RX_PKT_SZ;
} else {
pktsz = RX_MAX_BURST * (PKT_SZ + 2);
}
usb_fill_control_urb(catc->ctrl_urb, usbdev, usb_sndctrlpipe(usbdev, 0),
NULL, NULL, 0, catc_ctrl_done, catc);
usb_fill_bulk_urb(catc->tx_urb, usbdev, usb_sndbulkpipe(usbdev, 1),
NULL, 0, catc_tx_done, catc);
usb_fill_bulk_urb(catc->rx_urb, usbdev, usb_rcvbulkpipe(usbdev, 1),
catc->rx_buf, pktsz, catc_rx_done, catc);
usb_fill_int_urb(catc->irq_urb, usbdev, usb_rcvintpipe(usbdev, 2),
catc->irq_buf, 2, catc_irq_done, catc, 1);
if (!catc->is_f5u011) {
u32 *buf;
int i;
dev_dbg(dev, "Checking memory size\n");
buf = kmalloc(4, GFP_KERNEL);
if (!buf) {
ret = -ENOMEM;
goto fail_free;
}
*buf = 0x12345678;
catc_write_mem(catc, 0x7a80, buf, 4);
*buf = 0x87654321;
catc_write_mem(catc, 0xfa80, buf, 4);
catc_read_mem(catc, 0x7a80, buf, 4);
switch (*buf) {
case 0x12345678:
catc_set_reg(catc, TxBufCount, 8);
catc_set_reg(catc, RxBufCount, 32);
dev_dbg(dev, "64k Memory\n");
break;
default:
dev_warn(&intf->dev,
"Couldn't detect memory size, assuming 32k\n");
case 0x87654321:
catc_set_reg(catc, TxBufCount, 4);
catc_set_reg(catc, RxBufCount, 16);
dev_dbg(dev, "32k Memory\n");
break;
}
kfree(buf);
dev_dbg(dev, "Getting MAC from SEEROM.\n");
catc_get_mac(catc, netdev->dev_addr);
dev_dbg(dev, "Setting MAC into registers.\n");
for (i = 0; i < 6; i++)
catc_set_reg(catc, StationAddr0 - i, netdev->dev_addr[i]);
dev_dbg(dev, "Filling the multicast list.\n");
eth_broadcast_addr(broadcast);
catc_multicast(broadcast, catc->multicast);
catc_multicast(netdev->dev_addr, catc->multicast);
catc_write_mem(catc, 0xfa80, catc->multicast, 64);
dev_dbg(dev, "Clearing error counters.\n");
for (i = 0; i < 8; i++)
catc_set_reg(catc, EthStats + i, 0);
catc->last_stats = jiffies;
dev_dbg(dev, "Enabling.\n");
catc_set_reg(catc, MaxBurst, RX_MAX_BURST);
catc_set_reg(catc, OpModes, OpTxMerge | OpRxMerge | OpLenInclude | Op3MemWaits);
catc_set_reg(catc, LEDCtrl, LEDLink);
catc_set_reg(catc, RxUnit, RxEnable | RxPolarity | RxMultiCast);
} else {
dev_dbg(dev, "Performing reset\n");
catc_reset(catc);
catc_get_mac(catc, netdev->dev_addr);
dev_dbg(dev, "Setting RX Mode\n");
catc->rxmode[0] = RxEnable | RxPolarity | RxMultiCast;
catc->rxmode[1] = 0;
f5u011_rxmode(catc, catc->rxmode);
}
dev_dbg(dev, "Init done.\n");
printk(KERN_INFO "%s: %s USB Ethernet at usb-%s-%s, %pM.\n",
netdev->name, (catc->is_f5u011) ? "Belkin F5U011" : "CATC EL1210A NetMate",
usbdev->bus->bus_name, usbdev->devpath, netdev->dev_addr);
usb_set_intfdata(intf, catc);
SET_NETDEV_DEV(netdev, &intf->dev);
ret = register_netdev(netdev);
if (ret)
goto fail_clear_intfdata;
return 0;
fail_clear_intfdata:
usb_set_intfdata(intf, NULL);
fail_free:
usb_free_urb(catc->ctrl_urb);
usb_free_urb(catc->tx_urb);
usb_free_urb(catc->rx_urb);
usb_free_urb(catc->irq_urb);
free_netdev(netdev);
return ret;
}
static void catc_disconnect(struct usb_interface *intf)
{
struct catc *catc = usb_get_intfdata(intf);
usb_set_intfdata(intf, NULL);
if (catc) {
unregister_netdev(catc->netdev);
usb_free_urb(catc->ctrl_urb);
usb_free_urb(catc->tx_urb);
usb_free_urb(catc->rx_urb);
usb_free_urb(catc->irq_urb);
free_netdev(catc->netdev);
}
}
