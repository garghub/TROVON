static netdev_tx_t mac802154_monitor_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct mac802154_sub_if_data *priv;
u8 chan, page;
priv = netdev_priv(dev);
chan = priv->hw->phy->current_channel;
page = priv->hw->phy->current_page;
if (chan == MAC802154_CHAN_NONE)
return NETDEV_TX_OK;
if (WARN_ON(page >= WPAN_NUM_PAGES) ||
WARN_ON(chan >= WPAN_NUM_CHANNELS))
return NETDEV_TX_OK;
skb->skb_iif = dev->ifindex;
dev->stats.tx_packets++;
dev->stats.tx_bytes += skb->len;
return mac802154_tx(priv->hw, skb, page, chan);
}
void mac802154_monitors_rx(struct mac802154_priv *priv, struct sk_buff *skb)
{
struct sk_buff *skb2;
struct mac802154_sub_if_data *sdata;
u16 crc = crc_ccitt(0, skb->data, skb->len);
u8 *data;
rcu_read_lock();
list_for_each_entry_rcu(sdata, &priv->slaves, list) {
if (sdata->type != IEEE802154_DEV_MONITOR ||
!netif_running(sdata->dev))
continue;
skb2 = skb_clone(skb, GFP_ATOMIC);
skb2->dev = sdata->dev;
skb2->pkt_type = PACKET_HOST;
data = skb_put(skb2, 2);
data[0] = crc & 0xff;
data[1] = crc >> 8;
netif_rx_ni(skb2);
}
rcu_read_unlock();
}
void mac802154_monitor_setup(struct net_device *dev)
{
struct mac802154_sub_if_data *priv;
dev->addr_len = 0;
dev->hard_header_len = 0;
dev->needed_tailroom = 2;
dev->mtu = IEEE802154_MTU;
dev->tx_queue_len = 10;
dev->type = ARPHRD_IEEE802154_MONITOR;
dev->flags = IFF_NOARP | IFF_BROADCAST;
dev->watchdog_timeo = 0;
dev->destructor = free_netdev;
dev->netdev_ops = &mac802154_monitor_ops;
dev->ml_priv = &mac802154_mlme_reduced;
priv = netdev_priv(dev);
priv->type = IEEE802154_DEV_MONITOR;
priv->chan = MAC802154_CHAN_NONE;
priv->page = 0;
}
