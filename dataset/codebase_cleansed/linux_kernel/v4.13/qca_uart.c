static int
qca_tty_receive(struct serdev_device *serdev, const unsigned char *data,
size_t count)
{
struct qcauart *qca = serdev_device_get_drvdata(serdev);
struct net_device *netdev = qca->net_dev;
struct net_device_stats *n_stats = &netdev->stats;
size_t i;
if (!qca->rx_skb) {
qca->rx_skb = netdev_alloc_skb_ip_align(netdev,
netdev->mtu +
VLAN_ETH_HLEN);
if (!qca->rx_skb) {
n_stats->rx_errors++;
n_stats->rx_dropped++;
return 0;
}
}
for (i = 0; i < count; i++) {
s32 retcode;
retcode = qcafrm_fsm_decode(&qca->frm_handle,
qca->rx_skb->data,
skb_tailroom(qca->rx_skb),
data[i]);
switch (retcode) {
case QCAFRM_GATHER:
case QCAFRM_NOHEAD:
break;
case QCAFRM_NOTAIL:
netdev_dbg(netdev, "recv: no RX tail\n");
n_stats->rx_errors++;
n_stats->rx_dropped++;
break;
case QCAFRM_INVLEN:
netdev_dbg(netdev, "recv: invalid RX length\n");
n_stats->rx_errors++;
n_stats->rx_dropped++;
break;
default:
n_stats->rx_packets++;
n_stats->rx_bytes += retcode;
skb_put(qca->rx_skb, retcode);
qca->rx_skb->protocol = eth_type_trans(
qca->rx_skb, qca->rx_skb->dev);
qca->rx_skb->ip_summed = CHECKSUM_UNNECESSARY;
netif_rx_ni(qca->rx_skb);
qca->rx_skb = netdev_alloc_skb_ip_align(netdev,
netdev->mtu +
VLAN_ETH_HLEN);
if (!qca->rx_skb) {
netdev_dbg(netdev, "recv: out of RX resources\n");
n_stats->rx_errors++;
return i;
}
}
}
return i;
}
static void qcauart_transmit(struct work_struct *work)
{
struct qcauart *qca = container_of(work, struct qcauart, tx_work);
struct net_device_stats *n_stats = &qca->net_dev->stats;
int written;
spin_lock_bh(&qca->lock);
if (!netif_running(qca->net_dev)) {
spin_unlock_bh(&qca->lock);
return;
}
if (qca->tx_left <= 0) {
n_stats->tx_packets++;
spin_unlock_bh(&qca->lock);
netif_wake_queue(qca->net_dev);
return;
}
written = serdev_device_write_buf(qca->serdev, qca->tx_head,
qca->tx_left);
if (written > 0) {
qca->tx_left -= written;
qca->tx_head += written;
}
spin_unlock_bh(&qca->lock);
}
static void qca_tty_wakeup(struct serdev_device *serdev)
{
struct qcauart *qca = serdev_device_get_drvdata(serdev);
schedule_work(&qca->tx_work);
}
static int qcauart_netdev_open(struct net_device *dev)
{
struct qcauart *qca = netdev_priv(dev);
netif_start_queue(qca->net_dev);
return 0;
}
static int qcauart_netdev_close(struct net_device *dev)
{
struct qcauart *qca = netdev_priv(dev);
netif_stop_queue(dev);
flush_work(&qca->tx_work);
spin_lock_bh(&qca->lock);
qca->tx_left = 0;
spin_unlock_bh(&qca->lock);
return 0;
}
static netdev_tx_t
qcauart_netdev_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct net_device_stats *n_stats = &dev->stats;
struct qcauart *qca = netdev_priv(dev);
u8 pad_len = 0;
int written;
u8 *pos;
spin_lock(&qca->lock);
WARN_ON(qca->tx_left);
if (!netif_running(dev)) {
spin_unlock(&qca->lock);
netdev_warn(qca->net_dev, "xmit: iface is down\n");
goto out;
}
pos = qca->tx_buffer;
if (skb->len < QCAFRM_MIN_LEN)
pad_len = QCAFRM_MIN_LEN - skb->len;
pos += qcafrm_create_header(pos, skb->len + pad_len);
memcpy(pos, skb->data, skb->len);
pos += skb->len;
if (pad_len) {
memset(pos, 0, pad_len);
pos += pad_len;
}
pos += qcafrm_create_footer(pos);
netif_stop_queue(qca->net_dev);
written = serdev_device_write_buf(qca->serdev, qca->tx_buffer,
pos - qca->tx_buffer);
if (written > 0) {
qca->tx_left = (pos - qca->tx_buffer) - written;
qca->tx_head = qca->tx_buffer + written;
n_stats->tx_bytes += written;
}
spin_unlock(&qca->lock);
netif_trans_update(dev);
out:
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
static void qcauart_netdev_tx_timeout(struct net_device *dev)
{
struct qcauart *qca = netdev_priv(dev);
netdev_info(qca->net_dev, "Transmit timeout at %ld, latency %ld\n",
jiffies, dev_trans_start(dev));
dev->stats.tx_errors++;
dev->stats.tx_dropped++;
}
static int qcauart_netdev_init(struct net_device *dev)
{
struct qcauart *qca = netdev_priv(dev);
size_t len;
dev->mtu = QCAFRM_MAX_MTU;
dev->type = ARPHRD_ETHER;
len = QCAFRM_HEADER_LEN + QCAFRM_MAX_LEN + QCAFRM_FOOTER_LEN;
qca->tx_buffer = devm_kmalloc(&qca->serdev->dev, len, GFP_KERNEL);
if (!qca->tx_buffer)
return -ENOMEM;
qca->rx_skb = netdev_alloc_skb_ip_align(qca->net_dev,
qca->net_dev->mtu +
VLAN_ETH_HLEN);
if (!qca->rx_skb)
return -ENOBUFS;
return 0;
}
static void qcauart_netdev_uninit(struct net_device *dev)
{
struct qcauart *qca = netdev_priv(dev);
if (qca->rx_skb)
dev_kfree_skb(qca->rx_skb);
}
static void qcauart_netdev_setup(struct net_device *dev)
{
dev->netdev_ops = &qcauart_netdev_ops;
dev->watchdog_timeo = QCAUART_TX_TIMEOUT;
dev->priv_flags &= ~IFF_TX_SKB_SHARING;
dev->tx_queue_len = 100;
dev->min_mtu = QCAFRM_MIN_MTU;
dev->max_mtu = QCAFRM_MAX_MTU;
}
static int qca_uart_probe(struct serdev_device *serdev)
{
struct net_device *qcauart_dev = alloc_etherdev(sizeof(struct qcauart));
struct qcauart *qca;
const char *mac;
u32 speed = 115200;
int ret;
if (!qcauart_dev)
return -ENOMEM;
qcauart_netdev_setup(qcauart_dev);
SET_NETDEV_DEV(qcauart_dev, &serdev->dev);
qca = netdev_priv(qcauart_dev);
if (!qca) {
pr_err("qca_uart: Fail to retrieve private structure\n");
ret = -ENOMEM;
goto free;
}
qca->net_dev = qcauart_dev;
qca->serdev = serdev;
qcafrm_fsm_init_uart(&qca->frm_handle);
spin_lock_init(&qca->lock);
INIT_WORK(&qca->tx_work, qcauart_transmit);
of_property_read_u32(serdev->dev.of_node, "current-speed", &speed);
mac = of_get_mac_address(serdev->dev.of_node);
if (mac)
ether_addr_copy(qca->net_dev->dev_addr, mac);
if (!is_valid_ether_addr(qca->net_dev->dev_addr)) {
eth_hw_addr_random(qca->net_dev);
dev_info(&serdev->dev, "Using random MAC address: %pM\n",
qca->net_dev->dev_addr);
}
netif_carrier_on(qca->net_dev);
serdev_device_set_drvdata(serdev, qca);
serdev_device_set_client_ops(serdev, &qca_serdev_ops);
ret = serdev_device_open(serdev);
if (ret) {
dev_err(&serdev->dev, "Unable to open device %s\n",
qcauart_dev->name);
goto free;
}
speed = serdev_device_set_baudrate(serdev, speed);
dev_info(&serdev->dev, "Using baudrate: %u\n", speed);
serdev_device_set_flow_control(serdev, false);
ret = register_netdev(qcauart_dev);
if (ret) {
dev_err(&serdev->dev, "Unable to register net device %s\n",
qcauart_dev->name);
serdev_device_close(serdev);
cancel_work_sync(&qca->tx_work);
goto free;
}
return 0;
free:
free_netdev(qcauart_dev);
return ret;
}
static void qca_uart_remove(struct serdev_device *serdev)
{
struct qcauart *qca = serdev_device_get_drvdata(serdev);
unregister_netdev(qca->net_dev);
serdev_device_close(serdev);
cancel_work_sync(&qca->tx_work);
free_netdev(qca->net_dev);
}
