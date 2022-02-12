static int get_registers(rtl8150_t * dev, u16 indx, u16 size, void *data)
{
void *buf;
int ret;
buf = kmalloc(size, GFP_NOIO);
if (!buf)
return -ENOMEM;
ret = usb_control_msg(dev->udev, usb_rcvctrlpipe(dev->udev, 0),
RTL8150_REQ_GET_REGS, RTL8150_REQT_READ,
indx, 0, buf, size, 500);
if (ret > 0 && ret <= size)
memcpy(data, buf, ret);
kfree(buf);
return ret;
}
static int set_registers(rtl8150_t * dev, u16 indx, u16 size, const void *data)
{
void *buf;
int ret;
buf = kmemdup(data, size, GFP_NOIO);
if (!buf)
return -ENOMEM;
ret = usb_control_msg(dev->udev, usb_sndctrlpipe(dev->udev, 0),
RTL8150_REQ_SET_REGS, RTL8150_REQT_WRITE,
indx, 0, buf, size, 500);
kfree(buf);
return ret;
}
static void async_set_reg_cb(struct urb *urb)
{
struct async_req *req = (struct async_req *)urb->context;
int status = urb->status;
if (status < 0)
dev_dbg(&urb->dev->dev, "%s failed with %d", __func__, status);
kfree(req);
usb_free_urb(urb);
}
static int async_set_registers(rtl8150_t *dev, u16 indx, u16 size, u16 reg)
{
int res = -ENOMEM;
struct urb *async_urb;
struct async_req *req;
req = kmalloc(sizeof(struct async_req), GFP_ATOMIC);
if (req == NULL)
return res;
async_urb = usb_alloc_urb(0, GFP_ATOMIC);
if (async_urb == NULL) {
kfree(req);
return res;
}
req->rx_creg = cpu_to_le16(reg);
req->dr.bRequestType = RTL8150_REQT_WRITE;
req->dr.bRequest = RTL8150_REQ_SET_REGS;
req->dr.wIndex = 0;
req->dr.wValue = cpu_to_le16(indx);
req->dr.wLength = cpu_to_le16(size);
usb_fill_control_urb(async_urb, dev->udev,
usb_sndctrlpipe(dev->udev, 0), (void *)&req->dr,
&req->rx_creg, size, async_set_reg_cb, req);
res = usb_submit_urb(async_urb, GFP_ATOMIC);
if (res) {
if (res == -ENODEV)
netif_device_detach(dev->netdev);
dev_err(&dev->udev->dev, "%s failed with %d\n", __func__, res);
}
return res;
}
static int read_mii_word(rtl8150_t * dev, u8 phy, __u8 indx, u16 * reg)
{
int i;
u8 data[3], tmp;
data[0] = phy;
data[1] = data[2] = 0;
tmp = indx | PHY_READ | PHY_GO;
i = 0;
set_registers(dev, PHYADD, sizeof(data), data);
set_registers(dev, PHYCNT, 1, &tmp);
do {
get_registers(dev, PHYCNT, 1, data);
} while ((data[0] & PHY_GO) && (i++ < MII_TIMEOUT));
if (i <= MII_TIMEOUT) {
get_registers(dev, PHYDAT, 2, data);
*reg = data[0] | (data[1] << 8);
return 0;
} else
return 1;
}
static int write_mii_word(rtl8150_t * dev, u8 phy, __u8 indx, u16 reg)
{
int i;
u8 data[3], tmp;
data[0] = phy;
data[1] = reg & 0xff;
data[2] = (reg >> 8) & 0xff;
tmp = indx | PHY_WRITE | PHY_GO;
i = 0;
set_registers(dev, PHYADD, sizeof(data), data);
set_registers(dev, PHYCNT, 1, &tmp);
do {
get_registers(dev, PHYCNT, 1, data);
} while ((data[0] & PHY_GO) && (i++ < MII_TIMEOUT));
if (i <= MII_TIMEOUT)
return 0;
else
return 1;
}
static inline void set_ethernet_addr(rtl8150_t * dev)
{
u8 node_id[6];
get_registers(dev, IDR, sizeof(node_id), node_id);
memcpy(dev->netdev->dev_addr, node_id, sizeof(node_id));
}
static int rtl8150_set_mac_address(struct net_device *netdev, void *p)
{
struct sockaddr *addr = p;
rtl8150_t *dev = netdev_priv(netdev);
if (netif_running(netdev))
return -EBUSY;
memcpy(netdev->dev_addr, addr->sa_data, netdev->addr_len);
netdev_dbg(netdev, "Setting MAC address to %pM\n", netdev->dev_addr);
set_registers(dev, IDR, netdev->addr_len, netdev->dev_addr);
#ifdef EEPROM_WRITE
{
int i;
u8 cr;
get_registers(dev, CR, 1, &cr);
cr |= 0x20;
set_registers(dev, CR, 1, &cr);
for (i = 0; i * 2 < netdev->addr_len; i++) {
set_registers(dev, IDR_EEPROM + (i * 2), 2,
netdev->dev_addr + (i * 2));
}
cr &= 0xdf;
set_registers(dev, CR, 1, &cr);
}
#endif
return 0;
}
static int rtl8150_reset(rtl8150_t * dev)
{
u8 data = 0x10;
int i = HZ;
set_registers(dev, CR, 1, &data);
do {
get_registers(dev, CR, 1, &data);
} while ((data & 0x10) && --i);
return (i > 0) ? 1 : 0;
}
static int alloc_all_urbs(rtl8150_t * dev)
{
dev->rx_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->rx_urb)
return 0;
dev->tx_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->tx_urb) {
usb_free_urb(dev->rx_urb);
return 0;
}
dev->intr_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->intr_urb) {
usb_free_urb(dev->rx_urb);
usb_free_urb(dev->tx_urb);
return 0;
}
return 1;
}
static void free_all_urbs(rtl8150_t * dev)
{
usb_free_urb(dev->rx_urb);
usb_free_urb(dev->tx_urb);
usb_free_urb(dev->intr_urb);
}
static void unlink_all_urbs(rtl8150_t * dev)
{
usb_kill_urb(dev->rx_urb);
usb_kill_urb(dev->tx_urb);
usb_kill_urb(dev->intr_urb);
}
static inline struct sk_buff *pull_skb(rtl8150_t *dev)
{
struct sk_buff *skb;
int i;
for (i = 0; i < RX_SKB_POOL_SIZE; i++) {
if (dev->rx_skb_pool[i]) {
skb = dev->rx_skb_pool[i];
dev->rx_skb_pool[i] = NULL;
return skb;
}
}
return NULL;
}
static void read_bulk_callback(struct urb *urb)
{
rtl8150_t *dev;
unsigned pkt_len, res;
struct sk_buff *skb;
struct net_device *netdev;
u16 rx_stat;
int status = urb->status;
int result;
dev = urb->context;
if (!dev)
return;
if (test_bit(RTL8150_UNPLUG, &dev->flags))
return;
netdev = dev->netdev;
if (!netif_device_present(netdev))
return;
switch (status) {
case 0:
break;
case -ENOENT:
return;
case -ETIME:
if (printk_ratelimit())
dev_warn(&urb->dev->dev, "may be reset is needed?..\n");
goto goon;
default:
if (printk_ratelimit())
dev_warn(&urb->dev->dev, "Rx status %d\n", status);
goto goon;
}
if (!dev->rx_skb)
goto resched;
if (urb->actual_length < 4)
goto goon;
res = urb->actual_length;
rx_stat = le16_to_cpu(*(__le16 *)(urb->transfer_buffer + res - 4));
pkt_len = res - 4;
skb_put(dev->rx_skb, pkt_len);
dev->rx_skb->protocol = eth_type_trans(dev->rx_skb, netdev);
netif_rx(dev->rx_skb);
netdev->stats.rx_packets++;
netdev->stats.rx_bytes += pkt_len;
spin_lock(&dev->rx_pool_lock);
skb = pull_skb(dev);
spin_unlock(&dev->rx_pool_lock);
if (!skb)
goto resched;
dev->rx_skb = skb;
goon:
usb_fill_bulk_urb(dev->rx_urb, dev->udev, usb_rcvbulkpipe(dev->udev, 1),
dev->rx_skb->data, RTL8150_MTU, read_bulk_callback, dev);
result = usb_submit_urb(dev->rx_urb, GFP_ATOMIC);
if (result == -ENODEV)
netif_device_detach(dev->netdev);
else if (result) {
set_bit(RX_URB_FAIL, &dev->flags);
goto resched;
} else {
clear_bit(RX_URB_FAIL, &dev->flags);
}
return;
resched:
tasklet_schedule(&dev->tl);
}
static void write_bulk_callback(struct urb *urb)
{
rtl8150_t *dev;
int status = urb->status;
dev = urb->context;
if (!dev)
return;
dev_kfree_skb_irq(dev->tx_skb);
if (!netif_device_present(dev->netdev))
return;
if (status)
dev_info(&urb->dev->dev, "%s: Tx status %d\n",
dev->netdev->name, status);
netif_trans_update(dev->netdev);
netif_wake_queue(dev->netdev);
}
static void intr_callback(struct urb *urb)
{
rtl8150_t *dev;
__u8 *d;
int status = urb->status;
int res;
dev = urb->context;
if (!dev)
return;
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
return;
default:
dev_info(&urb->dev->dev, "%s: intr status %d\n",
dev->netdev->name, status);
goto resubmit;
}
d = urb->transfer_buffer;
if (d[0] & TSR_ERRORS) {
dev->netdev->stats.tx_errors++;
if (d[INT_TSR] & (TSR_ECOL | TSR_JBR))
dev->netdev->stats.tx_aborted_errors++;
if (d[INT_TSR] & TSR_LCOL)
dev->netdev->stats.tx_window_errors++;
if (d[INT_TSR] & TSR_LOSS_CRS)
dev->netdev->stats.tx_carrier_errors++;
}
if ((d[INT_MSR] & MSR_LINK) == 0) {
if (netif_carrier_ok(dev->netdev)) {
netif_carrier_off(dev->netdev);
netdev_dbg(dev->netdev, "%s: LINK LOST\n", __func__);
}
} else {
if (!netif_carrier_ok(dev->netdev)) {
netif_carrier_on(dev->netdev);
netdev_dbg(dev->netdev, "%s: LINK CAME BACK\n", __func__);
}
}
resubmit:
res = usb_submit_urb (urb, GFP_ATOMIC);
if (res == -ENODEV)
netif_device_detach(dev->netdev);
else if (res)
dev_err(&dev->udev->dev,
"can't resubmit intr, %s-%s/input0, status %d\n",
dev->udev->bus->bus_name, dev->udev->devpath, res);
}
static int rtl8150_suspend(struct usb_interface *intf, pm_message_t message)
{
rtl8150_t *dev = usb_get_intfdata(intf);
netif_device_detach(dev->netdev);
if (netif_running(dev->netdev)) {
usb_kill_urb(dev->rx_urb);
usb_kill_urb(dev->intr_urb);
}
return 0;
}
static int rtl8150_resume(struct usb_interface *intf)
{
rtl8150_t *dev = usb_get_intfdata(intf);
netif_device_attach(dev->netdev);
if (netif_running(dev->netdev)) {
dev->rx_urb->status = 0;
dev->rx_urb->actual_length = 0;
read_bulk_callback(dev->rx_urb);
dev->intr_urb->status = 0;
dev->intr_urb->actual_length = 0;
intr_callback(dev->intr_urb);
}
return 0;
}
static void fill_skb_pool(rtl8150_t *dev)
{
struct sk_buff *skb;
int i;
for (i = 0; i < RX_SKB_POOL_SIZE; i++) {
if (dev->rx_skb_pool[i])
continue;
skb = dev_alloc_skb(RTL8150_MTU + 2);
if (!skb) {
return;
}
skb_reserve(skb, 2);
dev->rx_skb_pool[i] = skb;
}
}
static void free_skb_pool(rtl8150_t *dev)
{
int i;
for (i = 0; i < RX_SKB_POOL_SIZE; i++)
if (dev->rx_skb_pool[i])
dev_kfree_skb(dev->rx_skb_pool[i]);
}
static void rx_fixup(unsigned long data)
{
struct rtl8150 *dev = (struct rtl8150 *)data;
struct sk_buff *skb;
int status;
spin_lock_irq(&dev->rx_pool_lock);
fill_skb_pool(dev);
spin_unlock_irq(&dev->rx_pool_lock);
if (test_bit(RX_URB_FAIL, &dev->flags))
if (dev->rx_skb)
goto try_again;
spin_lock_irq(&dev->rx_pool_lock);
skb = pull_skb(dev);
spin_unlock_irq(&dev->rx_pool_lock);
if (skb == NULL)
goto tlsched;
dev->rx_skb = skb;
usb_fill_bulk_urb(dev->rx_urb, dev->udev, usb_rcvbulkpipe(dev->udev, 1),
dev->rx_skb->data, RTL8150_MTU, read_bulk_callback, dev);
try_again:
status = usb_submit_urb(dev->rx_urb, GFP_ATOMIC);
if (status == -ENODEV) {
netif_device_detach(dev->netdev);
} else if (status) {
set_bit(RX_URB_FAIL, &dev->flags);
goto tlsched;
} else {
clear_bit(RX_URB_FAIL, &dev->flags);
}
return;
tlsched:
tasklet_schedule(&dev->tl);
}
static int enable_net_traffic(rtl8150_t * dev)
{
u8 cr, tcr, rcr, msr;
if (!rtl8150_reset(dev)) {
dev_warn(&dev->udev->dev, "device reset failed\n");
}
rcr = 0x9e;
tcr = 0xd8;
cr = 0x0c;
if (!(rcr & 0x80))
set_bit(RTL8150_HW_CRC, &dev->flags);
set_registers(dev, RCR, 1, &rcr);
set_registers(dev, TCR, 1, &tcr);
set_registers(dev, CR, 1, &cr);
get_registers(dev, MSR, 1, &msr);
return 0;
}
static void disable_net_traffic(rtl8150_t * dev)
{
u8 cr;
get_registers(dev, CR, 1, &cr);
cr &= 0xf3;
set_registers(dev, CR, 1, &cr);
}
static void rtl8150_tx_timeout(struct net_device *netdev)
{
rtl8150_t *dev = netdev_priv(netdev);
dev_warn(&netdev->dev, "Tx timeout.\n");
usb_unlink_urb(dev->tx_urb);
netdev->stats.tx_errors++;
}
static void rtl8150_set_multicast(struct net_device *netdev)
{
rtl8150_t *dev = netdev_priv(netdev);
u16 rx_creg = 0x9e;
netif_stop_queue(netdev);
if (netdev->flags & IFF_PROMISC) {
rx_creg |= 0x0001;
dev_info(&netdev->dev, "%s: promiscuous mode\n", netdev->name);
} else if (!netdev_mc_empty(netdev) ||
(netdev->flags & IFF_ALLMULTI)) {
rx_creg &= 0xfffe;
rx_creg |= 0x0002;
dev_info(&netdev->dev, "%s: allmulti set\n", netdev->name);
} else {
rx_creg &= 0x00fc;
}
async_set_registers(dev, RCR, sizeof(rx_creg), rx_creg);
netif_wake_queue(netdev);
}
static netdev_tx_t rtl8150_start_xmit(struct sk_buff *skb,
struct net_device *netdev)
{
rtl8150_t *dev = netdev_priv(netdev);
int count, res;
netif_stop_queue(netdev);
count = (skb->len < 60) ? 60 : skb->len;
count = (count & 0x3f) ? count : count + 1;
dev->tx_skb = skb;
usb_fill_bulk_urb(dev->tx_urb, dev->udev, usb_sndbulkpipe(dev->udev, 2),
skb->data, count, write_bulk_callback, dev);
if ((res = usb_submit_urb(dev->tx_urb, GFP_ATOMIC))) {
if (res == -ENODEV)
netif_device_detach(dev->netdev);
else {
dev_warn(&netdev->dev, "failed tx_urb %d\n", res);
netdev->stats.tx_errors++;
netif_start_queue(netdev);
}
} else {
netdev->stats.tx_packets++;
netdev->stats.tx_bytes += skb->len;
netif_trans_update(netdev);
}
return NETDEV_TX_OK;
}
static void set_carrier(struct net_device *netdev)
{
rtl8150_t *dev = netdev_priv(netdev);
short tmp;
get_registers(dev, CSCR, 2, &tmp);
if (tmp & CSCR_LINK_STATUS)
netif_carrier_on(netdev);
else
netif_carrier_off(netdev);
}
static int rtl8150_open(struct net_device *netdev)
{
rtl8150_t *dev = netdev_priv(netdev);
int res;
if (dev->rx_skb == NULL)
dev->rx_skb = pull_skb(dev);
if (!dev->rx_skb)
return -ENOMEM;
set_registers(dev, IDR, 6, netdev->dev_addr);
usb_fill_bulk_urb(dev->rx_urb, dev->udev, usb_rcvbulkpipe(dev->udev, 1),
dev->rx_skb->data, RTL8150_MTU, read_bulk_callback, dev);
if ((res = usb_submit_urb(dev->rx_urb, GFP_KERNEL))) {
if (res == -ENODEV)
netif_device_detach(dev->netdev);
dev_warn(&netdev->dev, "rx_urb submit failed: %d\n", res);
return res;
}
usb_fill_int_urb(dev->intr_urb, dev->udev, usb_rcvintpipe(dev->udev, 3),
dev->intr_buff, INTBUFSIZE, intr_callback,
dev, dev->intr_interval);
if ((res = usb_submit_urb(dev->intr_urb, GFP_KERNEL))) {
if (res == -ENODEV)
netif_device_detach(dev->netdev);
dev_warn(&netdev->dev, "intr_urb submit failed: %d\n", res);
usb_kill_urb(dev->rx_urb);
return res;
}
enable_net_traffic(dev);
set_carrier(netdev);
netif_start_queue(netdev);
return res;
}
static int rtl8150_close(struct net_device *netdev)
{
rtl8150_t *dev = netdev_priv(netdev);
netif_stop_queue(netdev);
if (!test_bit(RTL8150_UNPLUG, &dev->flags))
disable_net_traffic(dev);
unlink_all_urbs(dev);
return 0;
}
static void rtl8150_get_drvinfo(struct net_device *netdev, struct ethtool_drvinfo *info)
{
rtl8150_t *dev = netdev_priv(netdev);
strlcpy(info->driver, driver_name, sizeof(info->driver));
strlcpy(info->version, DRIVER_VERSION, sizeof(info->version));
usb_make_path(dev->udev, info->bus_info, sizeof(info->bus_info));
}
static int rtl8150_get_settings(struct net_device *netdev, struct ethtool_cmd *ecmd)
{
rtl8150_t *dev = netdev_priv(netdev);
short lpa, bmcr;
ecmd->supported = (SUPPORTED_10baseT_Half |
SUPPORTED_10baseT_Full |
SUPPORTED_100baseT_Half |
SUPPORTED_100baseT_Full |
SUPPORTED_Autoneg |
SUPPORTED_TP | SUPPORTED_MII);
ecmd->port = PORT_TP;
ecmd->transceiver = XCVR_INTERNAL;
ecmd->phy_address = dev->phy;
get_registers(dev, BMCR, 2, &bmcr);
get_registers(dev, ANLP, 2, &lpa);
if (bmcr & BMCR_ANENABLE) {
u32 speed = ((lpa & (LPA_100HALF | LPA_100FULL)) ?
SPEED_100 : SPEED_10);
ethtool_cmd_speed_set(ecmd, speed);
ecmd->autoneg = AUTONEG_ENABLE;
if (speed == SPEED_100)
ecmd->duplex = (lpa & LPA_100FULL) ?
DUPLEX_FULL : DUPLEX_HALF;
else
ecmd->duplex = (lpa & LPA_10FULL) ?
DUPLEX_FULL : DUPLEX_HALF;
} else {
ecmd->autoneg = AUTONEG_DISABLE;
ethtool_cmd_speed_set(ecmd, ((bmcr & BMCR_SPEED100) ?
SPEED_100 : SPEED_10));
ecmd->duplex = (bmcr & BMCR_FULLDPLX) ?
DUPLEX_FULL : DUPLEX_HALF;
}
return 0;
}
static int rtl8150_ioctl(struct net_device *netdev, struct ifreq *rq, int cmd)
{
rtl8150_t *dev = netdev_priv(netdev);
u16 *data = (u16 *) & rq->ifr_ifru;
int res = 0;
switch (cmd) {
case SIOCDEVPRIVATE:
data[0] = dev->phy;
case SIOCDEVPRIVATE + 1:
read_mii_word(dev, dev->phy, (data[1] & 0x1f), &data[3]);
break;
case SIOCDEVPRIVATE + 2:
if (!capable(CAP_NET_ADMIN))
return -EPERM;
write_mii_word(dev, dev->phy, (data[1] & 0x1f), data[2]);
break;
default:
res = -EOPNOTSUPP;
}
return res;
}
static int rtl8150_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(intf);
rtl8150_t *dev;
struct net_device *netdev;
netdev = alloc_etherdev(sizeof(rtl8150_t));
if (!netdev)
return -ENOMEM;
dev = netdev_priv(netdev);
dev->intr_buff = kmalloc(INTBUFSIZE, GFP_KERNEL);
if (!dev->intr_buff) {
free_netdev(netdev);
return -ENOMEM;
}
tasklet_init(&dev->tl, rx_fixup, (unsigned long)dev);
spin_lock_init(&dev->rx_pool_lock);
dev->udev = udev;
dev->netdev = netdev;
netdev->netdev_ops = &rtl8150_netdev_ops;
netdev->watchdog_timeo = RTL8150_TX_TIMEOUT;
netdev->ethtool_ops = &ops;
dev->intr_interval = 100;
if (!alloc_all_urbs(dev)) {
dev_err(&intf->dev, "out of memory\n");
goto out;
}
if (!rtl8150_reset(dev)) {
dev_err(&intf->dev, "couldn't reset the device\n");
goto out1;
}
fill_skb_pool(dev);
set_ethernet_addr(dev);
usb_set_intfdata(intf, dev);
SET_NETDEV_DEV(netdev, &intf->dev);
if (register_netdev(netdev) != 0) {
dev_err(&intf->dev, "couldn't register the device\n");
goto out2;
}
dev_info(&intf->dev, "%s: rtl8150 is detected\n", netdev->name);
return 0;
out2:
usb_set_intfdata(intf, NULL);
free_skb_pool(dev);
out1:
free_all_urbs(dev);
out:
kfree(dev->intr_buff);
free_netdev(netdev);
return -EIO;
}
static void rtl8150_disconnect(struct usb_interface *intf)
{
rtl8150_t *dev = usb_get_intfdata(intf);
usb_set_intfdata(intf, NULL);
if (dev) {
set_bit(RTL8150_UNPLUG, &dev->flags);
tasklet_kill(&dev->tl);
unregister_netdev(dev->netdev);
unlink_all_urbs(dev);
free_all_urbs(dev);
free_skb_pool(dev);
if (dev->rx_skb)
dev_kfree_skb(dev->rx_skb);
kfree(dev->intr_buff);
free_netdev(dev->netdev);
}
}
