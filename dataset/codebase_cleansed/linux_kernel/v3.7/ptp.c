static int efx_ptp_enable(struct efx_nic *efx)
{
u8 inbuf[MC_CMD_PTP_IN_ENABLE_LEN];
MCDI_SET_DWORD(inbuf, PTP_IN_OP, MC_CMD_PTP_OP_ENABLE);
MCDI_SET_DWORD(inbuf, PTP_IN_ENABLE_QUEUE,
efx->ptp_data->channel->channel);
MCDI_SET_DWORD(inbuf, PTP_IN_ENABLE_MODE, efx->ptp_data->mode);
return efx_mcdi_rpc(efx, MC_CMD_PTP, inbuf, sizeof(inbuf),
NULL, 0, NULL);
}
static int efx_ptp_disable(struct efx_nic *efx)
{
u8 inbuf[MC_CMD_PTP_IN_DISABLE_LEN];
MCDI_SET_DWORD(inbuf, PTP_IN_OP, MC_CMD_PTP_OP_DISABLE);
return efx_mcdi_rpc(efx, MC_CMD_PTP, inbuf, sizeof(inbuf),
NULL, 0, NULL);
}
static void efx_ptp_deliver_rx_queue(struct sk_buff_head *q)
{
struct sk_buff *skb;
while ((skb = skb_dequeue(q))) {
local_bh_disable();
netif_receive_skb(skb);
local_bh_enable();
}
}
static void efx_ptp_handle_no_channel(struct efx_nic *efx)
{
netif_err(efx, drv, efx->net_dev,
"ERROR: PTP requires MSI-X and 1 additional interrupt"
"vector. PTP disabled\n");
}
static void efx_ptp_send_times(struct efx_nic *efx,
struct pps_event_time *last_time)
{
struct pps_event_time now;
struct timespec limit;
struct efx_ptp_data *ptp = efx->ptp_data;
struct timespec start;
int *mc_running = ptp->start.addr;
pps_get_ts(&now);
start = now.ts_real;
limit = now.ts_real;
timespec_add_ns(&limit, SYNCHRONISE_PERIOD_NS);
while ((timespec_compare(&now.ts_real, &limit) < 0) &&
ACCESS_ONCE(*mc_running)) {
struct timespec update_time;
unsigned int host_time;
update_time = now.ts_real;
timespec_add_ns(&update_time, SYNCHRONISATION_GRANULARITY_NS);
do {
pps_get_ts(&now);
} while ((timespec_compare(&now.ts_real, &update_time) < 0) &&
ACCESS_ONCE(*mc_running));
host_time = (now.ts_real.tv_sec << MC_NANOSECOND_BITS |
now.ts_real.tv_nsec);
_efx_writed(efx, cpu_to_le32(host_time),
FR_CZ_MC_TREG_SMEM + MC_SMEM_P0_PTP_TIME_OFST);
}
*last_time = now;
}
static void efx_ptp_read_timeset(u8 *data, struct efx_ptp_timeset *timeset)
{
unsigned start_ns, end_ns;
timeset->host_start = MCDI_DWORD(data, PTP_OUT_SYNCHRONIZE_HOSTSTART);
timeset->seconds = MCDI_DWORD(data, PTP_OUT_SYNCHRONIZE_SECONDS);
timeset->nanoseconds = MCDI_DWORD(data,
PTP_OUT_SYNCHRONIZE_NANOSECONDS);
timeset->host_end = MCDI_DWORD(data, PTP_OUT_SYNCHRONIZE_HOSTEND),
timeset->waitns = MCDI_DWORD(data, PTP_OUT_SYNCHRONIZE_WAITNS);
start_ns = timeset->host_start & MC_NANOSECOND_MASK;
end_ns = timeset->host_end & MC_NANOSECOND_MASK;
if (end_ns < start_ns)
end_ns += NSEC_PER_SEC;
timeset->window = end_ns - start_ns;
}
static int efx_ptp_process_times(struct efx_nic *efx, u8 *synch_buf,
size_t response_length,
const struct pps_event_time *last_time)
{
unsigned number_readings = (response_length /
MC_CMD_PTP_OUT_SYNCHRONIZE_TIMESET_LEN);
unsigned i;
unsigned min;
unsigned min_set = 0;
unsigned total;
unsigned ngood = 0;
unsigned last_good = 0;
struct efx_ptp_data *ptp = efx->ptp_data;
bool min_valid = false;
u32 last_sec;
u32 start_sec;
struct timespec delta;
if (number_readings == 0)
return -EAGAIN;
for (i = 0; i < number_readings; i++) {
efx_ptp_read_timeset(synch_buf, &ptp->timeset[i]);
synch_buf += MC_CMD_PTP_OUT_SYNCHRONIZE_TIMESET_LEN;
if (ptp->timeset[i].window > SYNCHRONISATION_GRANULARITY_NS) {
if (min_valid) {
if (ptp->timeset[i].window < min_set)
min_set = ptp->timeset[i].window;
} else {
min_valid = true;
min_set = ptp->timeset[i].window;
}
}
}
if (min_valid) {
if (ptp->base_sync_valid && (min_set > ptp->base_sync_ns))
min = ptp->base_sync_ns;
else
min = min_set;
} else {
min = SYNCHRONISATION_GRANULARITY_NS;
}
total = 0;
for (i = 0; i < number_readings; i++)
if (ptp->timeset[i].window > ptp->timeset[i].waitns) {
unsigned win;
win = ptp->timeset[i].window - ptp->timeset[i].waitns;
if (win >= MIN_SYNCHRONISATION_NS &&
win < MAX_SYNCHRONISATION_NS) {
total += ptp->timeset[i].window;
ngood++;
last_good = i;
}
}
if (ngood == 0) {
netif_warn(efx, drv, efx->net_dev,
"PTP no suitable synchronisations %dns %dns\n",
ptp->base_sync_ns, min_set);
return -EAGAIN;
}
ptp->last_sync_ns = DIV_ROUND_UP(total, ngood);
if (!ptp->base_sync_valid || (ptp->last_sync_ns < ptp->base_sync_ns)) {
ptp->base_sync_valid = true;
ptp->base_sync_ns = ptp->last_sync_ns;
}
delta.tv_nsec =
ptp->timeset[last_good].nanoseconds +
last_time->ts_real.tv_nsec -
(ptp->timeset[last_good].host_start & MC_NANOSECOND_MASK);
start_sec = ptp->timeset[last_good].host_start >> MC_NANOSECOND_BITS;
last_sec = last_time->ts_real.tv_sec & MC_SECOND_MASK;
if (start_sec != last_sec) {
if (((start_sec + 1) & MC_SECOND_MASK) != last_sec) {
netif_warn(efx, hw, efx->net_dev,
"PTP bad synchronisation seconds\n");
return -EAGAIN;
} else {
delta.tv_sec = 1;
}
} else {
delta.tv_sec = 0;
}
ptp->host_time_pps = *last_time;
pps_sub_ts(&ptp->host_time_pps, delta);
return 0;
}
static int efx_ptp_synchronize(struct efx_nic *efx, unsigned int num_readings)
{
struct efx_ptp_data *ptp = efx->ptp_data;
u8 synch_buf[MC_CMD_PTP_OUT_SYNCHRONIZE_LENMAX];
size_t response_length;
int rc;
unsigned long timeout;
struct pps_event_time last_time = {};
unsigned int loops = 0;
int *start = ptp->start.addr;
MCDI_SET_DWORD(synch_buf, PTP_IN_OP, MC_CMD_PTP_OP_SYNCHRONIZE);
MCDI_SET_DWORD(synch_buf, PTP_IN_SYNCHRONIZE_NUMTIMESETS,
num_readings);
MCDI_SET_DWORD(synch_buf, PTP_IN_SYNCHRONIZE_START_ADDR_LO,
(u32)ptp->start.dma_addr);
MCDI_SET_DWORD(synch_buf, PTP_IN_SYNCHRONIZE_START_ADDR_HI,
(u32)((u64)ptp->start.dma_addr >> 32));
ACCESS_ONCE(*start) = 0;
efx_mcdi_rpc_start(efx, MC_CMD_PTP, synch_buf,
MC_CMD_PTP_IN_SYNCHRONIZE_LEN);
timeout = jiffies + msecs_to_jiffies(MAX_SYNCHRONISE_WAIT_MS);
while (!ACCESS_ONCE(*start) && (time_before(jiffies, timeout))) {
udelay(20);
loops++;
}
if (ACCESS_ONCE(*start))
efx_ptp_send_times(efx, &last_time);
rc = efx_mcdi_rpc_finish(efx, MC_CMD_PTP,
MC_CMD_PTP_IN_SYNCHRONIZE_LEN,
synch_buf, sizeof(synch_buf),
&response_length);
if (rc == 0)
rc = efx_ptp_process_times(efx, synch_buf, response_length,
&last_time);
return rc;
}
static int efx_ptp_xmit_skb(struct efx_nic *efx, struct sk_buff *skb)
{
u8 *txbuf = efx->ptp_data->txbuf;
struct skb_shared_hwtstamps timestamps;
int rc = -EIO;
size_t len = ALIGN(MC_CMD_PTP_IN_TRANSMIT_LEN(skb->len), 4);
u8 txtime[MC_CMD_PTP_OUT_TRANSMIT_LEN];
MCDI_SET_DWORD(txbuf, PTP_IN_OP, MC_CMD_PTP_OP_TRANSMIT);
MCDI_SET_DWORD(txbuf, PTP_IN_TRANSMIT_LENGTH, skb->len);
if (skb_shinfo(skb)->nr_frags != 0) {
rc = skb_linearize(skb);
if (rc != 0)
goto fail;
}
if (skb->ip_summed == CHECKSUM_PARTIAL) {
rc = skb_checksum_help(skb);
if (rc != 0)
goto fail;
}
skb_copy_from_linear_data(skb,
&txbuf[MC_CMD_PTP_IN_TRANSMIT_PACKET_OFST],
len);
rc = efx_mcdi_rpc(efx, MC_CMD_PTP, txbuf, len, txtime,
sizeof(txtime), &len);
if (rc != 0)
goto fail;
memset(&timestamps, 0, sizeof(timestamps));
timestamps.hwtstamp = ktime_set(
MCDI_DWORD(txtime, PTP_OUT_TRANSMIT_SECONDS),
MCDI_DWORD(txtime, PTP_OUT_TRANSMIT_NANOSECONDS));
skb_tstamp_tx(skb, &timestamps);
rc = 0;
fail:
dev_kfree_skb(skb);
return rc;
}
static void efx_ptp_drop_time_expired_events(struct efx_nic *efx)
{
struct efx_ptp_data *ptp = efx->ptp_data;
struct list_head *cursor;
struct list_head *next;
spin_lock_bh(&ptp->evt_lock);
if (!list_empty(&ptp->evt_list)) {
list_for_each_safe(cursor, next, &ptp->evt_list) {
struct efx_ptp_event_rx *evt;
evt = list_entry(cursor, struct efx_ptp_event_rx,
link);
if (time_after(jiffies, evt->expiry)) {
list_move(&evt->link, &ptp->evt_free_list);
netif_warn(efx, hw, efx->net_dev,
"PTP rx event dropped\n");
}
}
}
spin_unlock_bh(&ptp->evt_lock);
}
static enum ptp_packet_state efx_ptp_match_rx(struct efx_nic *efx,
struct sk_buff *skb)
{
struct efx_ptp_data *ptp = efx->ptp_data;
bool evts_waiting;
struct list_head *cursor;
struct list_head *next;
struct efx_ptp_match *match;
enum ptp_packet_state rc = PTP_PACKET_STATE_UNMATCHED;
spin_lock_bh(&ptp->evt_lock);
evts_waiting = !list_empty(&ptp->evt_list);
spin_unlock_bh(&ptp->evt_lock);
if (!evts_waiting)
return PTP_PACKET_STATE_UNMATCHED;
match = (struct efx_ptp_match *)skb->cb;
spin_lock_bh(&ptp->evt_lock);
list_for_each_safe(cursor, next, &ptp->evt_list) {
struct efx_ptp_event_rx *evt;
evt = list_entry(cursor, struct efx_ptp_event_rx, link);
if ((evt->seq0 == match->words[0]) &&
(evt->seq1 == match->words[1])) {
struct skb_shared_hwtstamps *timestamps;
timestamps = skb_hwtstamps(skb);
timestamps->hwtstamp = evt->hwtimestamp;
match->state = PTP_PACKET_STATE_MATCHED;
rc = PTP_PACKET_STATE_MATCHED;
list_move(&evt->link, &ptp->evt_free_list);
break;
}
}
spin_unlock_bh(&ptp->evt_lock);
return rc;
}
static bool efx_ptp_process_events(struct efx_nic *efx, struct sk_buff_head *q)
{
struct efx_ptp_data *ptp = efx->ptp_data;
bool rc = false;
struct sk_buff *skb;
while ((skb = skb_dequeue(&ptp->rxq))) {
struct efx_ptp_match *match;
match = (struct efx_ptp_match *)skb->cb;
if (match->state == PTP_PACKET_STATE_MATCH_UNWANTED) {
__skb_queue_tail(q, skb);
} else if (efx_ptp_match_rx(efx, skb) ==
PTP_PACKET_STATE_MATCHED) {
rc = true;
__skb_queue_tail(q, skb);
} else if (time_after(jiffies, match->expiry)) {
match->state = PTP_PACKET_STATE_TIMED_OUT;
netif_warn(efx, rx_err, efx->net_dev,
"PTP packet - no timestamp seen\n");
__skb_queue_tail(q, skb);
} else {
skb_queue_head(&ptp->rxq, skb);
break;
}
}
return rc;
}
static inline void efx_ptp_process_rx(struct efx_nic *efx, struct sk_buff *skb)
{
local_bh_disable();
netif_receive_skb(skb);
local_bh_enable();
}
static int efx_ptp_start(struct efx_nic *efx)
{
struct efx_ptp_data *ptp = efx->ptp_data;
struct efx_filter_spec rxfilter;
int rc;
ptp->reset_required = false;
efx_filter_init_rx(&rxfilter, EFX_FILTER_PRI_REQUIRED, 0,
efx_rx_queue_index(
efx_channel_get_rx_queue(ptp->channel)));
rc = efx_filter_set_ipv4_local(&rxfilter, IPPROTO_UDP,
htonl(PTP_ADDRESS),
htons(PTP_EVENT_PORT));
if (rc != 0)
return rc;
rc = efx_filter_insert_filter(efx, &rxfilter, true);
if (rc < 0)
return rc;
ptp->rxfilter_event = rc;
efx_filter_init_rx(&rxfilter, EFX_FILTER_PRI_REQUIRED, 0,
efx_rx_queue_index(
efx_channel_get_rx_queue(ptp->channel)));
rc = efx_filter_set_ipv4_local(&rxfilter, IPPROTO_UDP,
htonl(PTP_ADDRESS),
htons(PTP_GENERAL_PORT));
if (rc != 0)
goto fail;
rc = efx_filter_insert_filter(efx, &rxfilter, true);
if (rc < 0)
goto fail;
ptp->rxfilter_general = rc;
rc = efx_ptp_enable(efx);
if (rc != 0)
goto fail2;
ptp->evt_frag_idx = 0;
ptp->current_adjfreq = 0;
ptp->rxfilter_installed = true;
return 0;
fail2:
efx_filter_remove_id_safe(efx, EFX_FILTER_PRI_REQUIRED,
ptp->rxfilter_general);
fail:
efx_filter_remove_id_safe(efx, EFX_FILTER_PRI_REQUIRED,
ptp->rxfilter_event);
return rc;
}
static int efx_ptp_stop(struct efx_nic *efx)
{
struct efx_ptp_data *ptp = efx->ptp_data;
int rc = efx_ptp_disable(efx);
struct list_head *cursor;
struct list_head *next;
if (ptp->rxfilter_installed) {
efx_filter_remove_id_safe(efx, EFX_FILTER_PRI_REQUIRED,
ptp->rxfilter_general);
efx_filter_remove_id_safe(efx, EFX_FILTER_PRI_REQUIRED,
ptp->rxfilter_event);
ptp->rxfilter_installed = false;
}
efx_ptp_deliver_rx_queue(&efx->ptp_data->rxq);
skb_queue_purge(&efx->ptp_data->txq);
spin_lock_bh(&efx->ptp_data->evt_lock);
list_for_each_safe(cursor, next, &efx->ptp_data->evt_list) {
list_move(cursor, &efx->ptp_data->evt_free_list);
}
spin_unlock_bh(&efx->ptp_data->evt_lock);
return rc;
}
static void efx_ptp_pps_worker(struct work_struct *work)
{
struct efx_ptp_data *ptp =
container_of(work, struct efx_ptp_data, pps_work);
struct efx_nic *efx = ptp->channel->efx;
struct ptp_clock_event ptp_evt;
if (efx_ptp_synchronize(efx, PTP_SYNC_ATTEMPTS))
return;
ptp_evt.type = PTP_CLOCK_PPSUSR;
ptp_evt.pps_times = ptp->host_time_pps;
ptp_clock_event(ptp->phc_clock, &ptp_evt);
}
static void efx_ptp_worker(struct work_struct *work)
{
struct efx_ptp_data *ptp_data =
container_of(work, struct efx_ptp_data, work);
struct efx_nic *efx = ptp_data->channel->efx;
struct sk_buff *skb;
struct sk_buff_head tempq;
if (ptp_data->reset_required) {
efx_ptp_stop(efx);
efx_ptp_start(efx);
return;
}
efx_ptp_drop_time_expired_events(efx);
__skb_queue_head_init(&tempq);
if (efx_ptp_process_events(efx, &tempq) ||
!skb_queue_empty(&ptp_data->txq)) {
while ((skb = skb_dequeue(&ptp_data->txq)))
efx_ptp_xmit_skb(efx, skb);
}
while ((skb = __skb_dequeue(&tempq)))
efx_ptp_process_rx(efx, skb);
}
static int efx_ptp_probe_channel(struct efx_channel *channel)
{
struct efx_nic *efx = channel->efx;
struct efx_ptp_data *ptp;
int rc = 0;
unsigned int pos;
channel->irq_moderation = 0;
channel->rx_queue.core_index = 0;
ptp = kzalloc(sizeof(struct efx_ptp_data), GFP_KERNEL);
efx->ptp_data = ptp;
if (!efx->ptp_data)
return -ENOMEM;
rc = efx_nic_alloc_buffer(efx, &ptp->start, sizeof(int));
if (rc != 0)
goto fail1;
ptp->channel = channel;
skb_queue_head_init(&ptp->rxq);
skb_queue_head_init(&ptp->txq);
ptp->workwq = create_singlethread_workqueue("sfc_ptp");
if (!ptp->workwq) {
rc = -ENOMEM;
goto fail2;
}
INIT_WORK(&ptp->work, efx_ptp_worker);
ptp->config.flags = 0;
ptp->config.tx_type = HWTSTAMP_TX_OFF;
ptp->config.rx_filter = HWTSTAMP_FILTER_NONE;
INIT_LIST_HEAD(&ptp->evt_list);
INIT_LIST_HEAD(&ptp->evt_free_list);
spin_lock_init(&ptp->evt_lock);
for (pos = 0; pos < MAX_RECEIVE_EVENTS; pos++)
list_add(&ptp->rx_evts[pos].link, &ptp->evt_free_list);
ptp->phc_clock_info.owner = THIS_MODULE;
snprintf(ptp->phc_clock_info.name,
sizeof(ptp->phc_clock_info.name),
"%pm", efx->net_dev->perm_addr);
ptp->phc_clock_info.max_adj = MAX_PPB;
ptp->phc_clock_info.n_alarm = 0;
ptp->phc_clock_info.n_ext_ts = 0;
ptp->phc_clock_info.n_per_out = 0;
ptp->phc_clock_info.pps = 1;
ptp->phc_clock_info.adjfreq = efx_phc_adjfreq;
ptp->phc_clock_info.adjtime = efx_phc_adjtime;
ptp->phc_clock_info.gettime = efx_phc_gettime;
ptp->phc_clock_info.settime = efx_phc_settime;
ptp->phc_clock_info.enable = efx_phc_enable;
ptp->phc_clock = ptp_clock_register(&ptp->phc_clock_info,
&efx->pci_dev->dev);
if (!ptp->phc_clock)
goto fail3;
INIT_WORK(&ptp->pps_work, efx_ptp_pps_worker);
ptp->pps_workwq = create_singlethread_workqueue("sfc_pps");
if (!ptp->pps_workwq) {
rc = -ENOMEM;
goto fail4;
}
ptp->nic_ts_enabled = false;
return 0;
fail4:
ptp_clock_unregister(efx->ptp_data->phc_clock);
fail3:
destroy_workqueue(efx->ptp_data->workwq);
fail2:
efx_nic_free_buffer(efx, &ptp->start);
fail1:
kfree(efx->ptp_data);
efx->ptp_data = NULL;
return rc;
}
static void efx_ptp_remove_channel(struct efx_channel *channel)
{
struct efx_nic *efx = channel->efx;
if (!efx->ptp_data)
return;
(void)efx_ptp_disable(channel->efx);
cancel_work_sync(&efx->ptp_data->work);
cancel_work_sync(&efx->ptp_data->pps_work);
skb_queue_purge(&efx->ptp_data->rxq);
skb_queue_purge(&efx->ptp_data->txq);
ptp_clock_unregister(efx->ptp_data->phc_clock);
destroy_workqueue(efx->ptp_data->workwq);
destroy_workqueue(efx->ptp_data->pps_workwq);
efx_nic_free_buffer(efx, &efx->ptp_data->start);
kfree(efx->ptp_data);
}
static void efx_ptp_get_channel_name(struct efx_channel *channel,
char *buf, size_t len)
{
snprintf(buf, len, "%s-ptp", channel->efx->name);
}
bool efx_ptp_is_ptp_tx(struct efx_nic *efx, struct sk_buff *skb)
{
return efx->ptp_data &&
efx->ptp_data->enabled &&
skb->len >= PTP_MIN_LENGTH &&
skb->len <= MC_CMD_PTP_IN_TRANSMIT_PACKET_MAXNUM &&
likely(skb->protocol == htons(ETH_P_IP)) &&
ip_hdr(skb)->protocol == IPPROTO_UDP &&
udp_hdr(skb)->dest == htons(PTP_EVENT_PORT);
}
static void efx_ptp_rx(struct efx_channel *channel, struct sk_buff *skb)
{
struct efx_nic *efx = channel->efx;
struct efx_ptp_data *ptp = efx->ptp_data;
struct efx_ptp_match *match = (struct efx_ptp_match *)skb->cb;
u8 *data;
unsigned int version;
match->expiry = jiffies + msecs_to_jiffies(PKT_EVENT_LIFETIME_MS);
if (ptp->mode == MC_CMD_PTP_MODE_V1) {
if (skb->len < PTP_V1_MIN_LENGTH) {
netif_receive_skb(skb);
return;
}
version = ntohs(*(__be16 *)&skb->data[PTP_V1_VERSION_OFFSET]);
if (version != PTP_VERSION_V1) {
netif_receive_skb(skb);
return;
}
} else {
if (skb->len < PTP_V2_MIN_LENGTH) {
netif_receive_skb(skb);
return;
}
version = skb->data[PTP_V2_VERSION_OFFSET];
BUG_ON(ptp->mode != MC_CMD_PTP_MODE_V2);
BUILD_BUG_ON(PTP_V1_UUID_OFFSET != PTP_V2_MC_UUID_OFFSET);
BUILD_BUG_ON(PTP_V1_UUID_LENGTH != PTP_V2_MC_UUID_LENGTH);
BUILD_BUG_ON(PTP_V1_SEQUENCE_OFFSET != PTP_V2_SEQUENCE_OFFSET);
BUILD_BUG_ON(PTP_V1_SEQUENCE_LENGTH != PTP_V2_SEQUENCE_LENGTH);
if ((version & PTP_VERSION_V2_MASK) != PTP_VERSION_V2) {
netif_receive_skb(skb);
return;
}
}
if (ntohs(*(__be16 *)&skb->data[PTP_DPORT_OFFSET]) == PTP_EVENT_PORT) {
struct skb_shared_hwtstamps *timestamps;
match->state = PTP_PACKET_STATE_UNMATCHED;
timestamps = skb_hwtstamps(skb);
memset(timestamps, 0, sizeof(*timestamps));
data = skb->data + PTP_V1_UUID_OFFSET;
match->words[0] = (data[0] |
(data[1] << 8) |
(data[2] << 16) |
(data[3] << 24));
match->words[1] = (data[4] |
(data[5] << 8) |
(skb->data[PTP_V1_SEQUENCE_OFFSET +
PTP_V1_SEQUENCE_LENGTH - 1] <<
16));
} else {
match->state = PTP_PACKET_STATE_MATCH_UNWANTED;
}
skb_queue_tail(&ptp->rxq, skb);
queue_work(ptp->workwq, &ptp->work);
}
int efx_ptp_tx(struct efx_nic *efx, struct sk_buff *skb)
{
struct efx_ptp_data *ptp = efx->ptp_data;
skb_queue_tail(&ptp->txq, skb);
if ((udp_hdr(skb)->dest == htons(PTP_EVENT_PORT)) &&
(skb->len <= MC_CMD_PTP_IN_TRANSMIT_PACKET_MAXNUM))
efx_xmit_hwtstamp_pending(skb);
queue_work(ptp->workwq, &ptp->work);
return NETDEV_TX_OK;
}
static int efx_ptp_change_mode(struct efx_nic *efx, bool enable_wanted,
unsigned int new_mode)
{
if ((enable_wanted != efx->ptp_data->enabled) ||
(enable_wanted && (efx->ptp_data->mode != new_mode))) {
int rc;
if (enable_wanted) {
if (efx->ptp_data->enabled &&
(efx->ptp_data->mode != new_mode)) {
efx->ptp_data->enabled = false;
rc = efx_ptp_stop(efx);
if (rc != 0)
return rc;
}
efx->ptp_data->mode = new_mode;
rc = efx_ptp_start(efx);
if (rc == 0) {
rc = efx_ptp_synchronize(efx,
PTP_SYNC_ATTEMPTS * 2);
if (rc != 0)
efx_ptp_stop(efx);
}
} else {
rc = efx_ptp_stop(efx);
}
if (rc != 0)
return rc;
efx->ptp_data->enabled = enable_wanted;
}
return 0;
}
static int efx_ptp_ts_init(struct efx_nic *efx, struct hwtstamp_config *init)
{
bool enable_wanted = false;
unsigned int new_mode;
int rc;
if (init->flags)
return -EINVAL;
if ((init->tx_type != HWTSTAMP_TX_OFF) &&
(init->tx_type != HWTSTAMP_TX_ON))
return -ERANGE;
new_mode = efx->ptp_data->mode;
switch (init->rx_filter) {
case HWTSTAMP_FILTER_NONE:
break;
case HWTSTAMP_FILTER_PTP_V1_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V1_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ:
init->rx_filter = HWTSTAMP_FILTER_PTP_V1_L4_EVENT;
new_mode = MC_CMD_PTP_MODE_V1;
enable_wanted = true;
break;
case HWTSTAMP_FILTER_PTP_V2_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L4_DELAY_REQ:
init->rx_filter = HWTSTAMP_FILTER_PTP_V2_L4_EVENT;
new_mode = MC_CMD_PTP_MODE_V2;
enable_wanted = true;
break;
case HWTSTAMP_FILTER_PTP_V2_EVENT:
case HWTSTAMP_FILTER_PTP_V2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_L2_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L2_DELAY_REQ:
return -ERANGE;
break;
default:
return -ERANGE;
}
if (init->tx_type != HWTSTAMP_TX_OFF)
enable_wanted = true;
rc = efx_ptp_change_mode(efx, enable_wanted, new_mode);
if (rc != 0)
return rc;
efx->ptp_data->config = *init;
return 0;
}
int
efx_ptp_get_ts_info(struct net_device *net_dev, struct ethtool_ts_info *ts_info)
{
struct efx_nic *efx = netdev_priv(net_dev);
struct efx_ptp_data *ptp = efx->ptp_data;
if (!ptp)
return -EOPNOTSUPP;
ts_info->so_timestamping = (SOF_TIMESTAMPING_TX_HARDWARE |
SOF_TIMESTAMPING_RX_HARDWARE |
SOF_TIMESTAMPING_RAW_HARDWARE);
ts_info->phc_index = ptp_clock_index(ptp->phc_clock);
ts_info->tx_types = 1 << HWTSTAMP_TX_OFF | 1 << HWTSTAMP_TX_ON;
ts_info->rx_filters = (1 << HWTSTAMP_FILTER_NONE |
1 << HWTSTAMP_FILTER_PTP_V1_L4_EVENT |
1 << HWTSTAMP_FILTER_PTP_V1_L4_SYNC |
1 << HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ |
1 << HWTSTAMP_FILTER_PTP_V2_L4_EVENT |
1 << HWTSTAMP_FILTER_PTP_V2_L4_SYNC |
1 << HWTSTAMP_FILTER_PTP_V2_L4_DELAY_REQ);
return 0;
}
int efx_ptp_ioctl(struct efx_nic *efx, struct ifreq *ifr, int cmd)
{
struct hwtstamp_config config;
int rc;
if (!efx->ptp_data)
return -EOPNOTSUPP;
if (copy_from_user(&config, ifr->ifr_data, sizeof(config)))
return -EFAULT;
rc = efx_ptp_ts_init(efx, &config);
if (rc != 0)
return rc;
return copy_to_user(ifr->ifr_data, &config, sizeof(config))
? -EFAULT : 0;
}
static void ptp_event_failure(struct efx_nic *efx, int expected_frag_len)
{
struct efx_ptp_data *ptp = efx->ptp_data;
netif_err(efx, hw, efx->net_dev,
"PTP unexpected event length: got %d expected %d\n",
ptp->evt_frag_idx, expected_frag_len);
ptp->reset_required = true;
queue_work(ptp->workwq, &ptp->work);
}
static void ptp_event_rx(struct efx_nic *efx, struct efx_ptp_data *ptp)
{
struct efx_ptp_event_rx *evt = NULL;
if (ptp->evt_frag_idx != 3) {
ptp_event_failure(efx, 3);
return;
}
spin_lock_bh(&ptp->evt_lock);
if (!list_empty(&ptp->evt_free_list)) {
evt = list_first_entry(&ptp->evt_free_list,
struct efx_ptp_event_rx, link);
list_del(&evt->link);
evt->seq0 = EFX_QWORD_FIELD(ptp->evt_frags[2], MCDI_EVENT_DATA);
evt->seq1 = (EFX_QWORD_FIELD(ptp->evt_frags[2],
MCDI_EVENT_SRC) |
(EFX_QWORD_FIELD(ptp->evt_frags[1],
MCDI_EVENT_SRC) << 8) |
(EFX_QWORD_FIELD(ptp->evt_frags[0],
MCDI_EVENT_SRC) << 16));
evt->hwtimestamp = ktime_set(
EFX_QWORD_FIELD(ptp->evt_frags[0], MCDI_EVENT_DATA),
EFX_QWORD_FIELD(ptp->evt_frags[1], MCDI_EVENT_DATA));
evt->expiry = jiffies + msecs_to_jiffies(PKT_EVENT_LIFETIME_MS);
list_add_tail(&evt->link, &ptp->evt_list);
queue_work(ptp->workwq, &ptp->work);
} else {
netif_err(efx, rx_err, efx->net_dev, "No free PTP event");
}
spin_unlock_bh(&ptp->evt_lock);
}
static void ptp_event_fault(struct efx_nic *efx, struct efx_ptp_data *ptp)
{
int code = EFX_QWORD_FIELD(ptp->evt_frags[0], MCDI_EVENT_DATA);
if (ptp->evt_frag_idx != 1) {
ptp_event_failure(efx, 1);
return;
}
netif_err(efx, hw, efx->net_dev, "PTP error %d\n", code);
}
static void ptp_event_pps(struct efx_nic *efx, struct efx_ptp_data *ptp)
{
if (ptp->nic_ts_enabled)
queue_work(ptp->pps_workwq, &ptp->pps_work);
}
void efx_ptp_event(struct efx_nic *efx, efx_qword_t *ev)
{
struct efx_ptp_data *ptp = efx->ptp_data;
int code = EFX_QWORD_FIELD(*ev, MCDI_EVENT_CODE);
if (!ptp->enabled)
return;
if (ptp->evt_frag_idx == 0) {
ptp->evt_code = code;
} else if (ptp->evt_code != code) {
netif_err(efx, hw, efx->net_dev,
"PTP out of sequence event %d\n", code);
ptp->evt_frag_idx = 0;
}
ptp->evt_frags[ptp->evt_frag_idx++] = *ev;
if (!MCDI_EVENT_FIELD(*ev, CONT)) {
switch (code) {
case MCDI_EVENT_CODE_PTP_RX:
ptp_event_rx(efx, ptp);
break;
case MCDI_EVENT_CODE_PTP_FAULT:
ptp_event_fault(efx, ptp);
break;
case MCDI_EVENT_CODE_PTP_PPS:
ptp_event_pps(efx, ptp);
break;
default:
netif_err(efx, hw, efx->net_dev,
"PTP unknown event %d\n", code);
break;
}
ptp->evt_frag_idx = 0;
} else if (MAX_EVENT_FRAGS == ptp->evt_frag_idx) {
netif_err(efx, hw, efx->net_dev,
"PTP too many event fragments\n");
ptp->evt_frag_idx = 0;
}
}
static int efx_phc_adjfreq(struct ptp_clock_info *ptp, s32 delta)
{
struct efx_ptp_data *ptp_data = container_of(ptp,
struct efx_ptp_data,
phc_clock_info);
struct efx_nic *efx = ptp_data->channel->efx;
u8 inadj[MC_CMD_PTP_IN_ADJUST_LEN];
s64 adjustment_ns;
int rc;
if (delta > MAX_PPB)
delta = MAX_PPB;
else if (delta < -MAX_PPB)
delta = -MAX_PPB;
adjustment_ns = (((s64)delta * PPB_SCALE_WORD) >>
(PPB_EXTRA_BITS + MAX_PPB_BITS));
MCDI_SET_DWORD(inadj, PTP_IN_OP, MC_CMD_PTP_OP_ADJUST);
MCDI_SET_DWORD(inadj, PTP_IN_ADJUST_FREQ_LO, (u32)adjustment_ns);
MCDI_SET_DWORD(inadj, PTP_IN_ADJUST_FREQ_HI,
(u32)(adjustment_ns >> 32));
MCDI_SET_DWORD(inadj, PTP_IN_ADJUST_SECONDS, 0);
MCDI_SET_DWORD(inadj, PTP_IN_ADJUST_NANOSECONDS, 0);
rc = efx_mcdi_rpc(efx, MC_CMD_PTP, inadj, sizeof(inadj),
NULL, 0, NULL);
if (rc != 0)
return rc;
ptp_data->current_adjfreq = delta;
return 0;
}
static int efx_phc_adjtime(struct ptp_clock_info *ptp, s64 delta)
{
struct efx_ptp_data *ptp_data = container_of(ptp,
struct efx_ptp_data,
phc_clock_info);
struct efx_nic *efx = ptp_data->channel->efx;
struct timespec delta_ts = ns_to_timespec(delta);
u8 inbuf[MC_CMD_PTP_IN_ADJUST_LEN];
MCDI_SET_DWORD(inbuf, PTP_IN_OP, MC_CMD_PTP_OP_ADJUST);
MCDI_SET_DWORD(inbuf, PTP_IN_ADJUST_FREQ_LO, 0);
MCDI_SET_DWORD(inbuf, PTP_IN_ADJUST_FREQ_HI, 0);
MCDI_SET_DWORD(inbuf, PTP_IN_ADJUST_SECONDS, (u32)delta_ts.tv_sec);
MCDI_SET_DWORD(inbuf, PTP_IN_ADJUST_NANOSECONDS, (u32)delta_ts.tv_nsec);
return efx_mcdi_rpc(efx, MC_CMD_PTP, inbuf, sizeof(inbuf),
NULL, 0, NULL);
}
static int efx_phc_gettime(struct ptp_clock_info *ptp, struct timespec *ts)
{
struct efx_ptp_data *ptp_data = container_of(ptp,
struct efx_ptp_data,
phc_clock_info);
struct efx_nic *efx = ptp_data->channel->efx;
u8 inbuf[MC_CMD_PTP_IN_READ_NIC_TIME_LEN];
u8 outbuf[MC_CMD_PTP_OUT_READ_NIC_TIME_LEN];
int rc;
MCDI_SET_DWORD(inbuf, PTP_IN_OP, MC_CMD_PTP_OP_READ_NIC_TIME);
rc = efx_mcdi_rpc(efx, MC_CMD_PTP, inbuf, sizeof(inbuf),
outbuf, sizeof(outbuf), NULL);
if (rc != 0)
return rc;
ts->tv_sec = MCDI_DWORD(outbuf, PTP_OUT_READ_NIC_TIME_SECONDS);
ts->tv_nsec = MCDI_DWORD(outbuf, PTP_OUT_READ_NIC_TIME_NANOSECONDS);
return 0;
}
static int efx_phc_settime(struct ptp_clock_info *ptp,
const struct timespec *e_ts)
{
int rc;
struct timespec time_now;
struct timespec delta;
rc = efx_phc_gettime(ptp, &time_now);
if (rc != 0)
return rc;
delta = timespec_sub(*e_ts, time_now);
efx_phc_adjtime(ptp, timespec_to_ns(&delta));
if (rc != 0)
return rc;
return 0;
}
static int efx_phc_enable(struct ptp_clock_info *ptp,
struct ptp_clock_request *request,
int enable)
{
struct efx_ptp_data *ptp_data = container_of(ptp,
struct efx_ptp_data,
phc_clock_info);
if (request->type != PTP_CLK_REQ_PPS)
return -EOPNOTSUPP;
ptp_data->nic_ts_enabled = !!enable;
return 0;
}
void efx_ptp_probe(struct efx_nic *efx)
{
if (efx_ptp_disable(efx) == 0)
efx->extra_channel_type[EFX_EXTRA_CHANNEL_PTP] =
&efx_ptp_channel_type;
}
