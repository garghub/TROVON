void WILC_WFI_monitor_rx(u8 *buff, u32 size)
{
u32 header, pkt_offset;
struct sk_buff *skb = NULL;
struct wilc_wfi_radiotap_hdr *hdr;
struct wilc_wfi_radiotap_cb_hdr *cb_hdr;
if (!wilc_wfi_mon)
return;
if (!netif_running(wilc_wfi_mon))
return;
memcpy(&header, (buff - HOST_HDR_OFFSET), HOST_HDR_OFFSET);
pkt_offset = GET_PKT_OFFSET(header);
if (pkt_offset & IS_MANAGMEMENT_CALLBACK) {
skb = dev_alloc_skb(size + sizeof(struct wilc_wfi_radiotap_cb_hdr));
if (!skb)
return;
memcpy(skb_put(skb, size), buff, size);
cb_hdr = (struct wilc_wfi_radiotap_cb_hdr *)skb_push(skb, sizeof(*cb_hdr));
memset(cb_hdr, 0, sizeof(struct wilc_wfi_radiotap_cb_hdr));
cb_hdr->hdr.it_version = 0;
cb_hdr->hdr.it_len = cpu_to_le16(sizeof(struct wilc_wfi_radiotap_cb_hdr));
cb_hdr->hdr.it_present = cpu_to_le32(
(1 << IEEE80211_RADIOTAP_RATE) |
(1 << IEEE80211_RADIOTAP_TX_FLAGS));
cb_hdr->rate = 5;
if (pkt_offset & IS_MGMT_STATUS_SUCCES) {
cb_hdr->tx_flags = IEEE80211_RADIOTAP_F_TX_RTS;
} else {
cb_hdr->tx_flags = IEEE80211_RADIOTAP_F_TX_FAIL;
}
} else {
skb = dev_alloc_skb(size + sizeof(struct wilc_wfi_radiotap_hdr));
if (!skb)
return;
memcpy(skb_put(skb, size), buff, size);
hdr = (struct wilc_wfi_radiotap_hdr *)skb_push(skb, sizeof(*hdr));
memset(hdr, 0, sizeof(struct wilc_wfi_radiotap_hdr));
hdr->hdr.it_version = 0;
hdr->hdr.it_len = cpu_to_le16(sizeof(struct wilc_wfi_radiotap_hdr));
hdr->hdr.it_present = cpu_to_le32
(1 << IEEE80211_RADIOTAP_RATE);
hdr->rate = 5;
}
skb->dev = wilc_wfi_mon;
skb_set_mac_header(skb, 0);
skb->ip_summed = CHECKSUM_UNNECESSARY;
skb->pkt_type = PACKET_OTHERHOST;
skb->protocol = htons(ETH_P_802_2);
memset(skb->cb, 0, sizeof(skb->cb));
netif_rx(skb);
}
static void mgmt_tx_complete(void *priv, int status)
{
struct tx_complete_mon_data *pv_data = priv;
kfree(pv_data->buff);
kfree(pv_data);
}
static int mon_mgmt_tx(struct net_device *dev, const u8 *buf, size_t len)
{
struct tx_complete_mon_data *mgmt_tx = NULL;
if (!dev)
return -EFAULT;
netif_stop_queue(dev);
mgmt_tx = kmalloc(sizeof(*mgmt_tx), GFP_ATOMIC);
if (!mgmt_tx)
return -ENOMEM;
mgmt_tx->buff = kmalloc(len, GFP_ATOMIC);
if (!mgmt_tx->buff) {
kfree(mgmt_tx);
return -ENOMEM;
}
mgmt_tx->size = len;
memcpy(mgmt_tx->buff, buf, len);
wilc_wlan_txq_add_mgmt_pkt(dev, mgmt_tx, mgmt_tx->buff, mgmt_tx->size,
mgmt_tx_complete);
netif_wake_queue(dev);
return 0;
}
static netdev_tx_t WILC_WFI_mon_xmit(struct sk_buff *skb,
struct net_device *dev)
{
u32 rtap_len, ret = 0;
struct WILC_WFI_mon_priv *mon_priv;
struct sk_buff *skb2;
struct wilc_wfi_radiotap_cb_hdr *cb_hdr;
if (!wilc_wfi_mon)
return -EFAULT;
mon_priv = netdev_priv(wilc_wfi_mon);
if (!mon_priv)
return -EFAULT;
rtap_len = ieee80211_get_radiotap_len(skb->data);
if (skb->len < rtap_len)
return -1;
skb_pull(skb, rtap_len);
if (skb->data[0] == 0xc0 && (!(memcmp(broadcast, &skb->data[4], 6)))) {
skb2 = dev_alloc_skb(skb->len + sizeof(struct wilc_wfi_radiotap_cb_hdr));
memcpy(skb_put(skb2, skb->len), skb->data, skb->len);
cb_hdr = (struct wilc_wfi_radiotap_cb_hdr *)skb_push(skb2, sizeof(*cb_hdr));
memset(cb_hdr, 0, sizeof(struct wilc_wfi_radiotap_cb_hdr));
cb_hdr->hdr.it_version = 0;
cb_hdr->hdr.it_len = cpu_to_le16(sizeof(struct wilc_wfi_radiotap_cb_hdr));
cb_hdr->hdr.it_present = cpu_to_le32(
(1 << IEEE80211_RADIOTAP_RATE) |
(1 << IEEE80211_RADIOTAP_TX_FLAGS));
cb_hdr->rate = 5;
cb_hdr->tx_flags = 0x0004;
skb2->dev = wilc_wfi_mon;
skb_set_mac_header(skb2, 0);
skb2->ip_summed = CHECKSUM_UNNECESSARY;
skb2->pkt_type = PACKET_OTHERHOST;
skb2->protocol = htons(ETH_P_802_2);
memset(skb2->cb, 0, sizeof(skb2->cb));
netif_rx(skb2);
return 0;
}
skb->dev = mon_priv->real_ndev;
memcpy(srcAdd, &skb->data[10], 6);
memcpy(bssid, &skb->data[16], 6);
if (!(memcmp(srcAdd, bssid, 6))) {
ret = mon_mgmt_tx(mon_priv->real_ndev, skb->data, skb->len);
if (ret)
netdev_err(dev, "fail to mgmt tx\n");
dev_kfree_skb(skb);
} else {
ret = wilc_mac_xmit(skb, mon_priv->real_ndev);
}
return ret;
}
struct net_device *WILC_WFI_init_mon_interface(const char *name, struct net_device *real_dev)
{
u32 ret = 0;
struct WILC_WFI_mon_priv *priv;
if (wilc_wfi_mon)
return wilc_wfi_mon;
wilc_wfi_mon = alloc_etherdev(sizeof(struct WILC_WFI_mon_priv));
if (!wilc_wfi_mon)
return NULL;
wilc_wfi_mon->type = ARPHRD_IEEE80211_RADIOTAP;
strncpy(wilc_wfi_mon->name, name, IFNAMSIZ);
wilc_wfi_mon->name[IFNAMSIZ - 1] = 0;
wilc_wfi_mon->netdev_ops = &wilc_wfi_netdev_ops;
ret = register_netdevice(wilc_wfi_mon);
if (ret) {
netdev_err(real_dev, "register_netdevice failed\n");
return NULL;
}
priv = netdev_priv(wilc_wfi_mon);
if (!priv)
return NULL;
priv->real_ndev = real_dev;
return wilc_wfi_mon;
}
int WILC_WFI_deinit_mon_interface(void)
{
bool rollback_lock = false;
if (wilc_wfi_mon) {
if (rtnl_is_locked()) {
rtnl_unlock();
rollback_lock = true;
}
unregister_netdev(wilc_wfi_mon);
if (rollback_lock) {
rtnl_lock();
rollback_lock = false;
}
wilc_wfi_mon = NULL;
}
return 0;
}
