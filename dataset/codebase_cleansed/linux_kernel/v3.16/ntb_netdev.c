static void ntb_netdev_event_handler(void *data, int status)
{
struct net_device *ndev = data;
struct ntb_netdev *dev = netdev_priv(ndev);
netdev_dbg(ndev, "Event %x, Link %x\n", status,
ntb_transport_link_query(dev->qp));
switch (status) {
case NTB_LINK_DOWN:
netif_carrier_off(ndev);
break;
case NTB_LINK_UP:
if (!ntb_transport_link_query(dev->qp))
return;
netif_carrier_on(ndev);
break;
default:
netdev_warn(ndev, "Unsupported event type %d\n", status);
}
}
static void ntb_netdev_rx_handler(struct ntb_transport_qp *qp, void *qp_data,
void *data, int len)
{
struct net_device *ndev = qp_data;
struct sk_buff *skb;
int rc;
skb = data;
if (!skb)
return;
netdev_dbg(ndev, "%s: %d byte payload received\n", __func__, len);
skb_put(skb, len);
skb->protocol = eth_type_trans(skb, ndev);
skb->ip_summed = CHECKSUM_NONE;
if (netif_rx(skb) == NET_RX_DROP) {
ndev->stats.rx_errors++;
ndev->stats.rx_dropped++;
} else {
ndev->stats.rx_packets++;
ndev->stats.rx_bytes += len;
}
skb = netdev_alloc_skb(ndev, ndev->mtu + ETH_HLEN);
if (!skb) {
ndev->stats.rx_errors++;
ndev->stats.rx_frame_errors++;
return;
}
rc = ntb_transport_rx_enqueue(qp, skb, skb->data, ndev->mtu + ETH_HLEN);
if (rc) {
dev_kfree_skb(skb);
ndev->stats.rx_errors++;
ndev->stats.rx_fifo_errors++;
}
}
static void ntb_netdev_tx_handler(struct ntb_transport_qp *qp, void *qp_data,
void *data, int len)
{
struct net_device *ndev = qp_data;
struct sk_buff *skb;
skb = data;
if (!skb || !ndev)
return;
if (len > 0) {
ndev->stats.tx_packets++;
ndev->stats.tx_bytes += skb->len;
} else {
ndev->stats.tx_errors++;
ndev->stats.tx_aborted_errors++;
}
dev_kfree_skb(skb);
}
static netdev_tx_t ntb_netdev_start_xmit(struct sk_buff *skb,
struct net_device *ndev)
{
struct ntb_netdev *dev = netdev_priv(ndev);
int rc;
netdev_dbg(ndev, "%s: skb len %d\n", __func__, skb->len);
rc = ntb_transport_tx_enqueue(dev->qp, skb, skb->data, skb->len);
if (rc)
goto err;
return NETDEV_TX_OK;
err:
ndev->stats.tx_dropped++;
ndev->stats.tx_errors++;
return NETDEV_TX_BUSY;
}
static int ntb_netdev_open(struct net_device *ndev)
{
struct ntb_netdev *dev = netdev_priv(ndev);
struct sk_buff *skb;
int rc, i, len;
for (i = 0; i < NTB_RXQ_SIZE; i++) {
skb = netdev_alloc_skb(ndev, ndev->mtu + ETH_HLEN);
if (!skb) {
rc = -ENOMEM;
goto err;
}
rc = ntb_transport_rx_enqueue(dev->qp, skb, skb->data,
ndev->mtu + ETH_HLEN);
if (rc == -EINVAL) {
dev_kfree_skb(skb);
goto err;
}
}
netif_carrier_off(ndev);
ntb_transport_link_up(dev->qp);
return 0;
err:
while ((skb = ntb_transport_rx_remove(dev->qp, &len)))
dev_kfree_skb(skb);
return rc;
}
static int ntb_netdev_close(struct net_device *ndev)
{
struct ntb_netdev *dev = netdev_priv(ndev);
struct sk_buff *skb;
int len;
ntb_transport_link_down(dev->qp);
while ((skb = ntb_transport_rx_remove(dev->qp, &len)))
dev_kfree_skb(skb);
return 0;
}
static int ntb_netdev_change_mtu(struct net_device *ndev, int new_mtu)
{
struct ntb_netdev *dev = netdev_priv(ndev);
struct sk_buff *skb;
int len, rc;
if (new_mtu > ntb_transport_max_size(dev->qp) - ETH_HLEN)
return -EINVAL;
if (!netif_running(ndev)) {
ndev->mtu = new_mtu;
return 0;
}
ntb_transport_link_down(dev->qp);
if (ndev->mtu < new_mtu) {
int i;
for (i = 0; (skb = ntb_transport_rx_remove(dev->qp, &len)); i++)
dev_kfree_skb(skb);
for (; i; i--) {
skb = netdev_alloc_skb(ndev, new_mtu + ETH_HLEN);
if (!skb) {
rc = -ENOMEM;
goto err;
}
rc = ntb_transport_rx_enqueue(dev->qp, skb, skb->data,
new_mtu + ETH_HLEN);
if (rc) {
dev_kfree_skb(skb);
goto err;
}
}
}
ndev->mtu = new_mtu;
ntb_transport_link_up(dev->qp);
return 0;
err:
ntb_transport_link_down(dev->qp);
while ((skb = ntb_transport_rx_remove(dev->qp, &len)))
dev_kfree_skb(skb);
netdev_err(ndev, "Error changing MTU, device inoperable\n");
return rc;
}
static void ntb_get_drvinfo(struct net_device *ndev,
struct ethtool_drvinfo *info)
{
struct ntb_netdev *dev = netdev_priv(ndev);
strlcpy(info->driver, KBUILD_MODNAME, sizeof(info->driver));
strlcpy(info->version, NTB_NETDEV_VER, sizeof(info->version));
strlcpy(info->bus_info, pci_name(dev->pdev), sizeof(info->bus_info));
}
static int ntb_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
cmd->supported = SUPPORTED_Backplane;
cmd->advertising = ADVERTISED_Backplane;
ethtool_cmd_speed_set(cmd, SPEED_UNKNOWN);
cmd->duplex = DUPLEX_FULL;
cmd->port = PORT_OTHER;
cmd->phy_address = 0;
cmd->transceiver = XCVR_DUMMY1;
cmd->autoneg = AUTONEG_ENABLE;
cmd->maxtxpkt = 0;
cmd->maxrxpkt = 0;
return 0;
}
static int ntb_netdev_probe(struct pci_dev *pdev)
{
struct net_device *ndev;
struct ntb_netdev *dev;
int rc;
ndev = alloc_etherdev(sizeof(struct ntb_netdev));
if (!ndev)
return -ENOMEM;
dev = netdev_priv(ndev);
dev->ndev = ndev;
dev->pdev = pdev;
BUG_ON(!dev->pdev);
ndev->features = NETIF_F_HIGHDMA;
ndev->priv_flags |= IFF_LIVE_ADDR_CHANGE;
ndev->hw_features = ndev->features;
ndev->watchdog_timeo = msecs_to_jiffies(NTB_TX_TIMEOUT_MS);
random_ether_addr(ndev->perm_addr);
memcpy(ndev->dev_addr, ndev->perm_addr, ndev->addr_len);
ndev->netdev_ops = &ntb_netdev_ops;
ndev->ethtool_ops = &ntb_ethtool_ops;
dev->qp = ntb_transport_create_queue(ndev, pdev, &ntb_netdev_handlers);
if (!dev->qp) {
rc = -EIO;
goto err;
}
ndev->mtu = ntb_transport_max_size(dev->qp) - ETH_HLEN;
rc = register_netdev(ndev);
if (rc)
goto err1;
list_add(&dev->list, &dev_list);
dev_info(&pdev->dev, "%s created\n", ndev->name);
return 0;
err1:
ntb_transport_free_queue(dev->qp);
err:
free_netdev(ndev);
return rc;
}
static void ntb_netdev_remove(struct pci_dev *pdev)
{
struct net_device *ndev;
struct ntb_netdev *dev;
bool found = false;
list_for_each_entry(dev, &dev_list, list) {
if (dev->pdev == pdev) {
found = true;
break;
}
}
if (!found)
return;
list_del(&dev->list);
ndev = dev->ndev;
unregister_netdev(ndev);
ntb_transport_free_queue(dev->qp);
free_netdev(ndev);
}
static int __init ntb_netdev_init_module(void)
{
int rc;
rc = ntb_register_client_dev(KBUILD_MODNAME);
if (rc)
return rc;
return ntb_register_client(&ntb_netdev_client);
}
static void __exit ntb_netdev_exit_module(void)
{
ntb_unregister_client(&ntb_netdev_client);
ntb_unregister_client_dev(KBUILD_MODNAME);
}
