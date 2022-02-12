void *mwifiex_process_sta_txpd(struct mwifiex_private *priv,
struct sk_buff *skb)
{
struct mwifiex_adapter *adapter = priv->adapter;
struct txpd *local_tx_pd;
struct mwifiex_txinfo *tx_info = MWIFIEX_SKB_TXCB(skb);
u8 pad;
u16 pkt_type, pkt_offset;
if (!skb->len) {
dev_err(adapter->dev, "Tx: bad packet length: %d\n", skb->len);
tx_info->status_code = -1;
return skb->data;
}
pkt_type = mwifiex_is_skb_mgmt_frame(skb) ? PKT_TYPE_MGMT : 0;
pad = (4 - (((void *)skb->data - NULL) & 0x3)) % 4;
BUG_ON(skb_headroom(skb) < (sizeof(*local_tx_pd) + INTF_HEADER_LEN
+ pad));
skb_push(skb, sizeof(*local_tx_pd) + pad);
local_tx_pd = (struct txpd *) skb->data;
memset(local_tx_pd, 0, sizeof(struct txpd));
local_tx_pd->bss_num = priv->bss_num;
local_tx_pd->bss_type = priv->bss_type;
local_tx_pd->tx_pkt_length = cpu_to_le16((u16)(skb->len -
(sizeof(struct txpd)
+ pad)));
local_tx_pd->priority = (u8) skb->priority;
local_tx_pd->pkt_delay_2ms =
mwifiex_wmm_compute_drv_pkt_delay(priv, skb);
if (tx_info->flags & MWIFIEX_BUF_FLAG_EAPOL_TX_STATUS ||
tx_info->flags & MWIFIEX_BUF_FLAG_ACTION_TX_STATUS) {
local_tx_pd->tx_token_id = tx_info->ack_frame_id;
local_tx_pd->flags |= MWIFIEX_TXPD_FLAGS_REQ_TX_STATUS;
}
if (local_tx_pd->priority <
ARRAY_SIZE(priv->wmm.user_pri_pkt_tx_ctrl))
local_tx_pd->tx_control =
cpu_to_le32(priv->wmm.user_pri_pkt_tx_ctrl[local_tx_pd->
priority]);
if (adapter->pps_uapsd_mode) {
if (mwifiex_check_last_packet_indication(priv)) {
adapter->tx_lock_flag = true;
local_tx_pd->flags =
MWIFIEX_TxPD_POWER_MGMT_LAST_PACKET;
}
}
if (tx_info->flags & MWIFIEX_BUF_FLAG_TDLS_PKT)
local_tx_pd->flags |= MWIFIEX_TXPD_FLAGS_TDLS_PACKET;
pkt_offset = sizeof(struct txpd) + pad;
if (pkt_type == PKT_TYPE_MGMT) {
local_tx_pd->tx_pkt_type = cpu_to_le16(pkt_type);
pkt_offset += MWIFIEX_MGMT_FRAME_HEADER_SIZE;
}
local_tx_pd->tx_pkt_offset = cpu_to_le16(pkt_offset);
skb_push(skb, INTF_HEADER_LEN);
if (!local_tx_pd->tx_control)
local_tx_pd->tx_control = cpu_to_le32(priv->pkt_tx_ctrl);
return skb->data;
}
int mwifiex_send_null_packet(struct mwifiex_private *priv, u8 flags)
{
struct mwifiex_adapter *adapter = priv->adapter;
struct txpd *local_tx_pd;
struct mwifiex_tx_param tx_param;
#define NULL_PACKET_HDR 64
u32 data_len = NULL_PACKET_HDR;
struct sk_buff *skb;
int ret;
struct mwifiex_txinfo *tx_info = NULL;
if (adapter->surprise_removed)
return -1;
if (!priv->media_connected)
return -1;
if (adapter->data_sent)
return -1;
skb = dev_alloc_skb(data_len);
if (!skb)
return -1;
tx_info = MWIFIEX_SKB_TXCB(skb);
memset(tx_info, 0, sizeof(*tx_info));
tx_info->bss_num = priv->bss_num;
tx_info->bss_type = priv->bss_type;
tx_info->pkt_len = data_len - (sizeof(struct txpd) + INTF_HEADER_LEN);
skb_reserve(skb, sizeof(struct txpd) + INTF_HEADER_LEN);
skb_push(skb, sizeof(struct txpd));
local_tx_pd = (struct txpd *) skb->data;
local_tx_pd->tx_control = cpu_to_le32(priv->pkt_tx_ctrl);
local_tx_pd->flags = flags;
local_tx_pd->priority = WMM_HIGHEST_PRIORITY;
local_tx_pd->tx_pkt_offset = cpu_to_le16(sizeof(struct txpd));
local_tx_pd->bss_num = priv->bss_num;
local_tx_pd->bss_type = priv->bss_type;
if (adapter->iface_type == MWIFIEX_USB) {
ret = adapter->if_ops.host_to_card(adapter, MWIFIEX_USB_EP_DATA,
skb, NULL);
} else {
skb_push(skb, INTF_HEADER_LEN);
tx_param.next_pkt_len = 0;
ret = adapter->if_ops.host_to_card(adapter, MWIFIEX_TYPE_DATA,
skb, &tx_param);
}
switch (ret) {
case -EBUSY:
adapter->data_sent = true;
case -1:
dev_kfree_skb_any(skb);
dev_err(adapter->dev, "%s: host_to_card failed: ret=%d\n",
__func__, ret);
adapter->dbg.num_tx_host_to_card_failure++;
break;
case 0:
dev_kfree_skb_any(skb);
dev_dbg(adapter->dev, "data: %s: host_to_card succeeded\n",
__func__);
adapter->tx_lock_flag = true;
break;
case -EINPROGRESS:
break;
default:
break;
}
return ret;
}
u8
mwifiex_check_last_packet_indication(struct mwifiex_private *priv)
{
struct mwifiex_adapter *adapter = priv->adapter;
u8 ret = false;
if (!adapter->sleep_period.period)
return ret;
if (mwifiex_wmm_lists_empty(adapter))
ret = true;
if (ret && !adapter->cmd_sent && !adapter->curr_cmd &&
!is_command_pending(adapter)) {
adapter->delay_null_pkt = false;
ret = true;
} else {
ret = false;
adapter->delay_null_pkt = true;
}
return ret;
}
