int mwifiex_process_uap_event(struct mwifiex_private *priv)
{
struct mwifiex_adapter *adapter = priv->adapter;
int len, i;
u32 eventcause = adapter->event_cause;
struct station_info sinfo;
struct mwifiex_assoc_event *event;
struct mwifiex_sta_node *node;
u8 *deauth_mac;
struct host_cmd_ds_11n_batimeout *ba_timeout;
u16 ctrl;
switch (eventcause) {
case EVENT_UAP_STA_ASSOC:
memset(&sinfo, 0, sizeof(sinfo));
event = (struct mwifiex_assoc_event *)
(adapter->event_body + MWIFIEX_UAP_EVENT_EXTRA_HEADER);
if (le16_to_cpu(event->type) == TLV_TYPE_UAP_MGMT_FRAME) {
len = -1;
if (ieee80211_is_assoc_req(event->frame_control))
len = 0;
else if (ieee80211_is_reassoc_req(event->frame_control))
len = ETH_ALEN;
if (len != -1) {
sinfo.filled = STATION_INFO_ASSOC_REQ_IES;
sinfo.assoc_req_ies = &event->data[len];
len = (u8 *)sinfo.assoc_req_ies -
(u8 *)&event->frame_control;
sinfo.assoc_req_ies_len =
le16_to_cpu(event->len) - (u16)len;
}
}
cfg80211_new_sta(priv->netdev, event->sta_addr, &sinfo,
GFP_KERNEL);
node = mwifiex_add_sta_entry(priv, event->sta_addr);
if (!node) {
dev_warn(adapter->dev,
"could not create station entry!\n");
return -1;
}
if (!priv->ap_11n_enabled)
break;
mwifiex_set_sta_ht_cap(priv, sinfo.assoc_req_ies,
sinfo.assoc_req_ies_len, node);
for (i = 0; i < MAX_NUM_TID; i++) {
if (node->is_11n_enabled)
node->ampdu_sta[i] =
priv->aggr_prio_tbl[i].ampdu_user;
else
node->ampdu_sta[i] = BA_STREAM_NOT_ALLOWED;
}
memset(node->rx_seq, 0xff, sizeof(node->rx_seq));
break;
case EVENT_UAP_STA_DEAUTH:
deauth_mac = adapter->event_body +
MWIFIEX_UAP_EVENT_EXTRA_HEADER;
cfg80211_del_sta(priv->netdev, deauth_mac, GFP_KERNEL);
if (priv->ap_11n_enabled) {
mwifiex_11n_del_rx_reorder_tbl_by_ta(priv, deauth_mac);
mwifiex_del_tx_ba_stream_tbl_by_ra(priv, deauth_mac);
}
mwifiex_del_sta_entry(priv, deauth_mac);
break;
case EVENT_UAP_BSS_IDLE:
priv->media_connected = false;
if (netif_carrier_ok(priv->netdev))
netif_carrier_off(priv->netdev);
mwifiex_stop_net_dev_queue(priv->netdev, adapter);
mwifiex_clean_txrx(priv);
mwifiex_del_all_sta_list(priv);
break;
case EVENT_UAP_BSS_ACTIVE:
priv->media_connected = true;
if (!netif_carrier_ok(priv->netdev))
netif_carrier_on(priv->netdev);
mwifiex_wake_up_net_dev_queue(priv->netdev, adapter);
break;
case EVENT_UAP_BSS_START:
dev_dbg(adapter->dev, "AP EVENT: event id: %#x\n", eventcause);
memcpy(priv->netdev->dev_addr, adapter->event_body + 2,
ETH_ALEN);
break;
case EVENT_UAP_MIC_COUNTERMEASURES:
dev_dbg(adapter->dev, "AP EVENT: event id: %#x\n", eventcause);
break;
case EVENT_AMSDU_AGGR_CTRL:
ctrl = le16_to_cpu(*(__le16 *)adapter->event_body);
dev_dbg(adapter->dev, "event: AMSDU_AGGR_CTRL %d\n", ctrl);
if (priv->media_connected) {
adapter->tx_buf_size =
min_t(u16, adapter->curr_tx_buf_size, ctrl);
dev_dbg(adapter->dev, "event: tx_buf_size %d\n",
adapter->tx_buf_size);
}
break;
case EVENT_ADDBA:
dev_dbg(adapter->dev, "event: ADDBA Request\n");
if (priv->media_connected)
mwifiex_send_cmd(priv, HostCmd_CMD_11N_ADDBA_RSP,
HostCmd_ACT_GEN_SET, 0,
adapter->event_body, false);
break;
case EVENT_DELBA:
dev_dbg(adapter->dev, "event: DELBA Request\n");
if (priv->media_connected)
mwifiex_11n_delete_ba_stream(priv, adapter->event_body);
break;
case EVENT_BA_STREAM_TIEMOUT:
dev_dbg(adapter->dev, "event: BA Stream timeout\n");
if (priv->media_connected) {
ba_timeout = (void *)adapter->event_body;
mwifiex_11n_ba_stream_timeout(priv, ba_timeout);
}
break;
case EVENT_EXT_SCAN_REPORT:
dev_dbg(adapter->dev, "event: EXT_SCAN Report\n");
if (adapter->ext_scan)
return mwifiex_handle_event_ext_scan_report(priv,
adapter->event_skb->data);
break;
default:
dev_dbg(adapter->dev, "event: unknown event id: %#x\n",
eventcause);
break;
}
return 0;
}
void mwifiex_uap_del_sta_data(struct mwifiex_private *priv,
struct mwifiex_sta_node *node)
{
if (priv->ap_11n_enabled && node->is_11n_enabled) {
mwifiex_11n_del_rx_reorder_tbl_by_ta(priv, node->mac_addr);
mwifiex_del_tx_ba_stream_tbl_by_ra(priv, node->mac_addr);
}
mwifiex_del_sta_entry(priv, node->mac_addr);
return;
}
