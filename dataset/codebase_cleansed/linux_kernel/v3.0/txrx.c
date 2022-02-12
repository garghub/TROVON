int mwifiex_handle_rx_packet(struct mwifiex_adapter *adapter,
struct sk_buff *skb)
{
struct mwifiex_private *priv =
mwifiex_get_priv(adapter, MWIFIEX_BSS_ROLE_ANY);
struct rxpd *local_rx_pd;
struct mwifiex_rxinfo *rx_info = MWIFIEX_SKB_RXCB(skb);
local_rx_pd = (struct rxpd *) (skb->data);
priv = mwifiex_get_priv_by_id(adapter, local_rx_pd->bss_num &
BSS_NUM_MASK, local_rx_pd->bss_type);
if (!priv)
priv = mwifiex_get_priv(adapter, MWIFIEX_BSS_ROLE_ANY);
rx_info->bss_index = priv->bss_index;
return mwifiex_process_sta_rx_packet(adapter, skb);
}
int mwifiex_process_tx(struct mwifiex_private *priv, struct sk_buff *skb,
struct mwifiex_tx_param *tx_param)
{
int ret = -1;
struct mwifiex_adapter *adapter = priv->adapter;
u8 *head_ptr;
struct txpd *local_tx_pd = NULL;
head_ptr = (u8 *) mwifiex_process_sta_txpd(priv, skb);
if (head_ptr) {
if (GET_BSS_ROLE(priv) == MWIFIEX_BSS_ROLE_STA)
local_tx_pd =
(struct txpd *) (head_ptr + INTF_HEADER_LEN);
ret = adapter->if_ops.host_to_card(adapter, MWIFIEX_TYPE_DATA,
skb->data, skb->len, tx_param);
}
switch (ret) {
case -EBUSY:
if ((GET_BSS_ROLE(priv) == MWIFIEX_BSS_ROLE_STA) &&
(adapter->pps_uapsd_mode) &&
(adapter->tx_lock_flag)) {
priv->adapter->tx_lock_flag = false;
local_tx_pd->flags = 0;
}
dev_dbg(adapter->dev, "data: -EBUSY is returned\n");
break;
case -1:
adapter->data_sent = false;
dev_err(adapter->dev, "mwifiex_write_data_async failed: 0x%X\n",
ret);
adapter->dbg.num_tx_host_to_card_failure++;
mwifiex_write_data_complete(adapter, skb, ret);
break;
case -EINPROGRESS:
adapter->data_sent = false;
break;
case 0:
mwifiex_write_data_complete(adapter, skb, ret);
break;
default:
break;
}
return ret;
}
int mwifiex_write_data_complete(struct mwifiex_adapter *adapter,
struct sk_buff *skb, int status)
{
struct mwifiex_private *priv, *tpriv;
struct mwifiex_txinfo *tx_info;
int i;
if (!skb)
return 0;
tx_info = MWIFIEX_SKB_TXCB(skb);
priv = mwifiex_bss_index_to_priv(adapter, tx_info->bss_index);
if (!priv)
goto done;
priv->netdev->trans_start = jiffies;
if (!status) {
priv->stats.tx_packets++;
priv->stats.tx_bytes += skb->len;
} else {
priv->stats.tx_errors++;
}
if (atomic_dec_return(&adapter->tx_pending) >= LOW_TX_PENDING)
goto done;
for (i = 0; i < adapter->priv_num; i++) {
tpriv = adapter->priv[i];
if ((GET_BSS_ROLE(tpriv) == MWIFIEX_BSS_ROLE_STA)
&& (tpriv->media_connected)) {
if (netif_queue_stopped(tpriv->netdev))
netif_wake_queue(tpriv->netdev);
}
}
done:
dev_kfree_skb_any(skb);
return 0;
}
int mwifiex_recv_packet_complete(struct mwifiex_adapter *adapter,
struct sk_buff *skb, int status)
{
struct mwifiex_rxinfo *rx_info = MWIFIEX_SKB_RXCB(skb);
struct mwifiex_rxinfo *rx_info_parent;
struct mwifiex_private *priv;
struct sk_buff *skb_parent;
unsigned long flags;
priv = adapter->priv[rx_info->bss_index];
if (priv && (status == -1))
priv->stats.rx_dropped++;
if (rx_info->parent) {
skb_parent = rx_info->parent;
rx_info_parent = MWIFIEX_SKB_RXCB(skb_parent);
spin_lock_irqsave(&priv->rx_pkt_lock, flags);
--rx_info_parent->use_count;
if (!rx_info_parent->use_count) {
spin_unlock_irqrestore(&priv->rx_pkt_lock, flags);
dev_kfree_skb_any(skb_parent);
} else {
spin_unlock_irqrestore(&priv->rx_pkt_lock, flags);
}
} else {
dev_kfree_skb_any(skb);
}
return 0;
}
