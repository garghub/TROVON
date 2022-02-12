void rsi_dbg(u32 zone, const char *fmt, ...)
{
struct va_format vaf;
va_list args;
va_start(args, fmt);
vaf.fmt = fmt;
vaf.va = &args;
if (zone & rsi_zone_enabled)
pr_info("%pV", &vaf);
va_end(args);
}
static struct sk_buff *rsi_prepare_skb(struct rsi_common *common,
u8 *buffer,
u32 pkt_len,
u8 extended_desc)
{
struct ieee80211_tx_info *info;
struct skb_info *rx_params;
struct sk_buff *skb = NULL;
u8 payload_offset;
if (WARN(!pkt_len, "%s: Dummy pkt received", __func__))
return NULL;
if (pkt_len > (RSI_RCV_BUFFER_LEN * 4)) {
rsi_dbg(ERR_ZONE, "%s: Pkt size > max rx buf size %d\n",
__func__, pkt_len);
pkt_len = RSI_RCV_BUFFER_LEN * 4;
}
pkt_len -= extended_desc;
skb = dev_alloc_skb(pkt_len + FRAME_DESC_SZ);
if (skb == NULL)
return NULL;
payload_offset = (extended_desc + FRAME_DESC_SZ);
skb_put(skb, pkt_len);
memcpy((skb->data), (buffer + payload_offset), skb->len);
info = IEEE80211_SKB_CB(skb);
rx_params = (struct skb_info *)info->driver_data;
rx_params->rssi = rsi_get_rssi(buffer);
rx_params->channel = rsi_get_connected_channel(common->priv);
return skb;
}
int rsi_read_pkt(struct rsi_common *common, s32 rcv_pkt_len)
{
u8 *frame_desc = NULL, extended_desc = 0;
u32 index, length = 0, queueno = 0;
u16 actual_length = 0, offset;
struct sk_buff *skb = NULL;
index = 0;
do {
frame_desc = &common->rx_data_pkt[index];
actual_length = *(u16 *)&frame_desc[0];
offset = *(u16 *)&frame_desc[2];
queueno = rsi_get_queueno(frame_desc, offset);
length = rsi_get_length(frame_desc, offset);
if (queueno == RSI_WIFI_DATA_Q || queueno == RSI_WIFI_MGMT_Q)
extended_desc = rsi_get_extended_desc(frame_desc,
offset);
switch (queueno) {
case RSI_COEX_Q:
rsi_mgmt_pkt_recv(common, (frame_desc + offset));
break;
case RSI_WIFI_DATA_Q:
skb = rsi_prepare_skb(common,
(frame_desc + offset),
length,
extended_desc);
if (skb == NULL)
goto fail;
rsi_indicate_pkt_to_os(common, skb);
break;
case RSI_WIFI_MGMT_Q:
rsi_mgmt_pkt_recv(common, (frame_desc + offset));
break;
default:
rsi_dbg(ERR_ZONE, "%s: pkt from invalid queue: %d\n",
__func__, queueno);
goto fail;
}
index += actual_length;
rcv_pkt_len -= actual_length;
} while (rcv_pkt_len > 0);
return 0;
fail:
return -EINVAL;
}
static void rsi_tx_scheduler_thread(struct rsi_common *common)
{
struct rsi_hw *adapter = common->priv;
u32 timeout = EVENT_WAIT_FOREVER;
do {
if (adapter->determine_event_timeout)
timeout = adapter->determine_event_timeout(adapter);
rsi_wait_event(&common->tx_thread.event, timeout);
rsi_reset_event(&common->tx_thread.event);
if (common->init_done)
rsi_core_qos_processor(common);
} while (atomic_read(&common->tx_thread.thread_done) == 0);
complete_and_exit(&common->tx_thread.completion, 0);
}
struct rsi_hw *rsi_91x_init(void)
{
struct rsi_hw *adapter = NULL;
struct rsi_common *common = NULL;
u8 ii = 0;
adapter = kzalloc(sizeof(*adapter), GFP_KERNEL);
if (!adapter)
return NULL;
adapter->priv = kzalloc(sizeof(*common), GFP_KERNEL);
if (adapter->priv == NULL) {
rsi_dbg(ERR_ZONE, "%s: Failed in allocation of memory\n",
__func__);
kfree(adapter);
return NULL;
} else {
common = adapter->priv;
common->priv = adapter;
}
for (ii = 0; ii < NUM_SOFT_QUEUES; ii++)
skb_queue_head_init(&common->tx_queue[ii]);
rsi_init_event(&common->tx_thread.event);
mutex_init(&common->mutex);
mutex_init(&common->tx_lock);
mutex_init(&common->rx_lock);
if (rsi_create_kthread(common,
&common->tx_thread,
rsi_tx_scheduler_thread,
"Tx-Thread")) {
rsi_dbg(ERR_ZONE, "%s: Unable to init tx thrd\n", __func__);
goto err;
}
rsi_default_ps_params(adapter);
spin_lock_init(&adapter->ps_lock);
common->init_done = true;
return adapter;
err:
kfree(common);
kfree(adapter);
return NULL;
}
void rsi_91x_deinit(struct rsi_hw *adapter)
{
struct rsi_common *common = adapter->priv;
u8 ii;
rsi_dbg(INFO_ZONE, "%s: Performing deinit os ops\n", __func__);
rsi_kill_thread(&common->tx_thread);
for (ii = 0; ii < NUM_SOFT_QUEUES; ii++)
skb_queue_purge(&common->tx_queue[ii]);
common->init_done = false;
kfree(common);
kfree(adapter->rsi_dev);
kfree(adapter);
}
static int rsi_91x_hal_module_init(void)
{
rsi_dbg(INIT_ZONE, "%s: Module init called\n", __func__);
return 0;
}
static void rsi_91x_hal_module_exit(void)
{
rsi_dbg(INIT_ZONE, "%s: Module exit called\n", __func__);
}
