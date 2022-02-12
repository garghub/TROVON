size_t efx_ptp_describe_stats(struct efx_nic *efx, u8 *strings)
{
if (!efx->ptp_data)
return 0;
return efx_nic_describe_stats(efx_ptp_stat_desc, PTP_STAT_COUNT,
efx_ptp_stat_mask, strings);
}
size_t efx_ptp_update_stats(struct efx_nic *efx, u64 *stats)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_PTP_IN_STATUS_LEN);
MCDI_DECLARE_BUF(outbuf, MC_CMD_PTP_OUT_STATUS_LEN);
size_t i;
int rc;
if (!efx->ptp_data)
return 0;
for (i = 0; i < PTP_STAT_COUNT; i++) {
if (efx_ptp_stat_desc[i].dma_width)
continue;
stats[i] = *(unsigned int *)((char *)efx->ptp_data +
efx_ptp_stat_desc[i].offset);
}
MCDI_SET_DWORD(inbuf, PTP_IN_OP, MC_CMD_PTP_OP_STATUS);
MCDI_SET_DWORD(inbuf, PTP_IN_PERIPH_ID, 0);
rc = efx_mcdi_rpc(efx, MC_CMD_PTP, inbuf, sizeof(inbuf),
outbuf, sizeof(outbuf), NULL);
if (rc)
memset(outbuf, 0, sizeof(outbuf));
efx_nic_update_stats(efx_ptp_stat_desc, PTP_STAT_COUNT,
efx_ptp_stat_mask,
stats, _MCDI_PTR(outbuf, 0), false);
return PTP_STAT_COUNT;
}
static void efx_ptp_ns_to_s_ns(s64 ns, u32 *nic_major, u32 *nic_minor)
{
struct timespec64 ts = ns_to_timespec64(ns);
*nic_major = (u32)ts.tv_sec;
*nic_minor = ts.tv_nsec;
}
static ktime_t efx_ptp_s_ns_to_ktime_correction(u32 nic_major, u32 nic_minor,
s32 correction)
{
ktime_t kt = ktime_set(nic_major, nic_minor);
if (correction >= 0)
kt = ktime_add_ns(kt, (u64)correction);
else
kt = ktime_sub_ns(kt, (u64)-correction);
return kt;
}
static void efx_ptp_ns_to_s27(s64 ns, u32 *nic_major, u32 *nic_minor)
{
struct timespec64 ts = ns_to_timespec64(ns);
u32 maj = (u32)ts.tv_sec;
u32 min = (u32)(((u64)ts.tv_nsec * NS_TO_S27_MULT +
(1ULL << (NS_TO_S27_SHIFT - 1))) >> NS_TO_S27_SHIFT);
if (min >= S27_MINOR_MAX) {
min -= S27_MINOR_MAX;
maj++;
}
*nic_major = maj;
*nic_minor = min;
}
static inline ktime_t efx_ptp_s27_to_ktime(u32 nic_major, u32 nic_minor)
{
u32 ns = (u32)(((u64)nic_minor * NSEC_PER_SEC +
(1ULL << (S27_TO_NS_SHIFT - 1))) >> S27_TO_NS_SHIFT);
return ktime_set(nic_major, ns);
}
static ktime_t efx_ptp_s27_to_ktime_correction(u32 nic_major, u32 nic_minor,
s32 correction)
{
nic_minor += correction;
if ((s32)nic_minor < 0) {
nic_minor += S27_MINOR_MAX;
nic_major--;
} else if (nic_minor >= S27_MINOR_MAX) {
nic_minor -= S27_MINOR_MAX;
nic_major++;
}
return efx_ptp_s27_to_ktime(nic_major, nic_minor);
}
static int efx_ptp_get_attributes(struct efx_nic *efx)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_PTP_IN_GET_ATTRIBUTES_LEN);
MCDI_DECLARE_BUF(outbuf, MC_CMD_PTP_OUT_GET_ATTRIBUTES_LEN);
struct efx_ptp_data *ptp = efx->ptp_data;
int rc;
u32 fmt;
size_t out_len;
MCDI_SET_DWORD(inbuf, PTP_IN_OP, MC_CMD_PTP_OP_GET_ATTRIBUTES);
MCDI_SET_DWORD(inbuf, PTP_IN_PERIPH_ID, 0);
rc = efx_mcdi_rpc_quiet(efx, MC_CMD_PTP, inbuf, sizeof(inbuf),
outbuf, sizeof(outbuf), &out_len);
if (rc == 0) {
fmt = MCDI_DWORD(outbuf, PTP_OUT_GET_ATTRIBUTES_TIME_FORMAT);
} else if (rc == -EINVAL) {
fmt = MC_CMD_PTP_OUT_GET_ATTRIBUTES_SECONDS_NANOSECONDS;
} else if (rc == -EPERM) {
netif_info(efx, probe, efx->net_dev, "no PTP support\n");
return rc;
} else {
efx_mcdi_display_error(efx, MC_CMD_PTP, sizeof(inbuf),
outbuf, sizeof(outbuf), rc);
return rc;
}
if (fmt == MC_CMD_PTP_OUT_GET_ATTRIBUTES_SECONDS_27FRACTION) {
ptp->ns_to_nic_time = efx_ptp_ns_to_s27;
ptp->nic_to_kernel_time = efx_ptp_s27_to_ktime_correction;
} else if (fmt == MC_CMD_PTP_OUT_GET_ATTRIBUTES_SECONDS_NANOSECONDS) {
ptp->ns_to_nic_time = efx_ptp_ns_to_s_ns;
ptp->nic_to_kernel_time = efx_ptp_s_ns_to_ktime_correction;
} else {
return -ERANGE;
}
ptp->time_format = fmt;
if (rc == 0 && out_len >= MC_CMD_PTP_OUT_GET_ATTRIBUTES_LEN)
ptp->min_synchronisation_ns =
MCDI_DWORD(outbuf,
PTP_OUT_GET_ATTRIBUTES_SYNC_WINDOW_MIN);
else
ptp->min_synchronisation_ns = DEFAULT_MIN_SYNCHRONISATION_NS;
return 0;
}
static int efx_ptp_get_timestamp_corrections(struct efx_nic *efx)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_PTP_IN_GET_TIMESTAMP_CORRECTIONS_LEN);
MCDI_DECLARE_BUF(outbuf, MC_CMD_PTP_OUT_GET_TIMESTAMP_CORRECTIONS_LEN);
int rc;
MCDI_SET_DWORD(inbuf, PTP_IN_OP,
MC_CMD_PTP_OP_GET_TIMESTAMP_CORRECTIONS);
MCDI_SET_DWORD(inbuf, PTP_IN_PERIPH_ID, 0);
rc = efx_mcdi_rpc_quiet(efx, MC_CMD_PTP, inbuf, sizeof(inbuf),
outbuf, sizeof(outbuf), NULL);
if (rc == 0) {
efx->ptp_data->ts_corrections.tx = MCDI_DWORD(outbuf,
PTP_OUT_GET_TIMESTAMP_CORRECTIONS_TRANSMIT);
efx->ptp_data->ts_corrections.rx = MCDI_DWORD(outbuf,
PTP_OUT_GET_TIMESTAMP_CORRECTIONS_RECEIVE);
efx->ptp_data->ts_corrections.pps_out = MCDI_DWORD(outbuf,
PTP_OUT_GET_TIMESTAMP_CORRECTIONS_PPS_OUT);
efx->ptp_data->ts_corrections.pps_in = MCDI_DWORD(outbuf,
PTP_OUT_GET_TIMESTAMP_CORRECTIONS_PPS_IN);
} else if (rc == -EINVAL) {
efx->ptp_data->ts_corrections.tx = 0;
efx->ptp_data->ts_corrections.rx = 0;
efx->ptp_data->ts_corrections.pps_out = 0;
efx->ptp_data->ts_corrections.pps_in = 0;
} else {
efx_mcdi_display_error(efx, MC_CMD_PTP, sizeof(inbuf), outbuf,
sizeof(outbuf), rc);
return rc;
}
return 0;
}
static int efx_ptp_enable(struct efx_nic *efx)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_PTP_IN_ENABLE_LEN);
MCDI_DECLARE_BUF_ERR(outbuf);
int rc;
MCDI_SET_DWORD(inbuf, PTP_IN_OP, MC_CMD_PTP_OP_ENABLE);
MCDI_SET_DWORD(inbuf, PTP_IN_PERIPH_ID, 0);
MCDI_SET_DWORD(inbuf, PTP_IN_ENABLE_QUEUE,
efx->ptp_data->channel ?
efx->ptp_data->channel->channel : 0);
MCDI_SET_DWORD(inbuf, PTP_IN_ENABLE_MODE, efx->ptp_data->mode);
rc = efx_mcdi_rpc_quiet(efx, MC_CMD_PTP, inbuf, sizeof(inbuf),
outbuf, sizeof(outbuf), NULL);
rc = (rc == -EALREADY) ? 0 : rc;
if (rc)
efx_mcdi_display_error(efx, MC_CMD_PTP,
MC_CMD_PTP_IN_ENABLE_LEN,
outbuf, sizeof(outbuf), rc);
return rc;
}
static int efx_ptp_disable(struct efx_nic *efx)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_PTP_IN_DISABLE_LEN);
MCDI_DECLARE_BUF_ERR(outbuf);
int rc;
MCDI_SET_DWORD(inbuf, PTP_IN_OP, MC_CMD_PTP_OP_DISABLE);
MCDI_SET_DWORD(inbuf, PTP_IN_PERIPH_ID, 0);
rc = efx_mcdi_rpc_quiet(efx, MC_CMD_PTP, inbuf, sizeof(inbuf),
outbuf, sizeof(outbuf), NULL);
rc = (rc == -EALREADY) ? 0 : rc;
if (rc == -ENOSYS || rc == -EPERM)
netif_info(efx, probe, efx->net_dev, "no PTP support\n");
else if (rc)
efx_mcdi_display_error(efx, MC_CMD_PTP,
MC_CMD_PTP_IN_DISABLE_LEN,
outbuf, sizeof(outbuf), rc);
return rc;
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
struct timespec64 limit;
struct efx_ptp_data *ptp = efx->ptp_data;
struct timespec64 start;
int *mc_running = ptp->start.addr;
pps_get_ts(&now);
start = now.ts_real;
limit = now.ts_real;
timespec64_add_ns(&limit, SYNCHRONISE_PERIOD_NS);
while ((timespec64_compare(&now.ts_real, &limit) < 0) &&
ACCESS_ONCE(*mc_running)) {
struct timespec64 update_time;
unsigned int host_time;
update_time = now.ts_real;
timespec64_add_ns(&update_time, SYNCHRONISATION_GRANULARITY_NS);
do {
pps_get_ts(&now);
} while ((timespec64_compare(&now.ts_real, &update_time) < 0) &&
ACCESS_ONCE(*mc_running));
host_time = (now.ts_real.tv_sec << MC_NANOSECOND_BITS |
now.ts_real.tv_nsec);
efx->type->ptp_write_host_time(efx, host_time);
}
*last_time = now;
}
static int efx_ptp_synchronize(struct efx_nic *efx, unsigned int num_readings)
{
struct efx_ptp_data *ptp = efx->ptp_data;
MCDI_DECLARE_BUF(synch_buf, MC_CMD_PTP_OUT_SYNCHRONIZE_LENMAX);
size_t response_length;
int rc;
unsigned long timeout;
struct pps_event_time last_time = {};
unsigned int loops = 0;
int *start = ptp->start.addr;
MCDI_SET_DWORD(synch_buf, PTP_IN_OP, MC_CMD_PTP_OP_SYNCHRONIZE);
MCDI_SET_DWORD(synch_buf, PTP_IN_PERIPH_ID, 0);
MCDI_SET_DWORD(synch_buf, PTP_IN_SYNCHRONIZE_NUMTIMESETS,
num_readings);
MCDI_SET_QWORD(synch_buf, PTP_IN_SYNCHRONIZE_START_ADDR,
ptp->start.dma_addr);
ACCESS_ONCE(*start) = 0;
rc = efx_mcdi_rpc_start(efx, MC_CMD_PTP, synch_buf,
MC_CMD_PTP_IN_SYNCHRONIZE_LEN);
EFX_BUG_ON_PARANOID(rc);
timeout = jiffies + msecs_to_jiffies(MAX_SYNCHRONISE_WAIT_MS);
while (!ACCESS_ONCE(*start) && (time_before(jiffies, timeout))) {
udelay(20);
loops++;
}
if (loops <= 1)
++ptp->fast_syncs;
if (!time_before(jiffies, timeout))
++ptp->sync_timeouts;
if (ACCESS_ONCE(*start))
efx_ptp_send_times(efx, &last_time);
rc = efx_mcdi_rpc_finish(efx, MC_CMD_PTP,
MC_CMD_PTP_IN_SYNCHRONIZE_LEN,
synch_buf, sizeof(synch_buf),
&response_length);
if (rc == 0) {
rc = efx_ptp_process_times(efx, synch_buf, response_length,
&last_time);
if (rc == 0)
++ptp->good_syncs;
else
++ptp->no_time_syncs;
}
if (rc != 0)
++ptp->bad_syncs;
return rc;
}
static int efx_ptp_xmit_skb(struct efx_nic *efx, struct sk_buff *skb)
{
struct efx_ptp_data *ptp_data = efx->ptp_data;
struct skb_shared_hwtstamps timestamps;
int rc = -EIO;
MCDI_DECLARE_BUF(txtime, MC_CMD_PTP_OUT_TRANSMIT_LEN);
size_t len;
MCDI_SET_DWORD(ptp_data->txbuf, PTP_IN_OP, MC_CMD_PTP_OP_TRANSMIT);
MCDI_SET_DWORD(ptp_data->txbuf, PTP_IN_PERIPH_ID, 0);
MCDI_SET_DWORD(ptp_data->txbuf, PTP_IN_TRANSMIT_LENGTH, skb->len);
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
MCDI_PTR(ptp_data->txbuf,
PTP_IN_TRANSMIT_PACKET),
skb->len);
rc = efx_mcdi_rpc(efx, MC_CMD_PTP,
ptp_data->txbuf, MC_CMD_PTP_IN_TRANSMIT_LEN(skb->len),
txtime, sizeof(txtime), &len);
if (rc != 0)
goto fail;
memset(&timestamps, 0, sizeof(timestamps));
timestamps.hwtstamp = ptp_data->nic_to_kernel_time(
MCDI_DWORD(txtime, PTP_OUT_TRANSMIT_MAJOR),
MCDI_DWORD(txtime, PTP_OUT_TRANSMIT_MINOR),
ptp_data->ts_corrections.tx);
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
if (ptp->rx_ts_inline)
return;
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
WARN_ON_ONCE(ptp->rx_ts_inline);
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
static void efx_ptp_process_events(struct efx_nic *efx, struct sk_buff_head *q)
{
struct efx_ptp_data *ptp = efx->ptp_data;
struct sk_buff *skb;
while ((skb = skb_dequeue(&ptp->rxq))) {
struct efx_ptp_match *match;
match = (struct efx_ptp_match *)skb->cb;
if (match->state == PTP_PACKET_STATE_MATCH_UNWANTED) {
__skb_queue_tail(q, skb);
} else if (efx_ptp_match_rx(efx, skb) ==
PTP_PACKET_STATE_MATCHED) {
__skb_queue_tail(q, skb);
} else if (time_after(jiffies, match->expiry)) {
match->state = PTP_PACKET_STATE_TIMED_OUT;
++ptp->rx_no_timestamp;
__skb_queue_tail(q, skb);
} else {
skb_queue_head(&ptp->rxq, skb);
break;
}
}
}
static inline void efx_ptp_process_rx(struct efx_nic *efx, struct sk_buff *skb)
{
local_bh_disable();
netif_receive_skb(skb);
local_bh_enable();
}
static void efx_ptp_remove_multicast_filters(struct efx_nic *efx)
{
struct efx_ptp_data *ptp = efx->ptp_data;
if (ptp->rxfilter_installed) {
efx_filter_remove_id_safe(efx, EFX_FILTER_PRI_REQUIRED,
ptp->rxfilter_general);
efx_filter_remove_id_safe(efx, EFX_FILTER_PRI_REQUIRED,
ptp->rxfilter_event);
ptp->rxfilter_installed = false;
}
}
static int efx_ptp_insert_multicast_filters(struct efx_nic *efx)
{
struct efx_ptp_data *ptp = efx->ptp_data;
struct efx_filter_spec rxfilter;
int rc;
if (!ptp->channel || ptp->rxfilter_installed)
return 0;
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
ptp->rxfilter_installed = true;
return 0;
fail:
efx_filter_remove_id_safe(efx, EFX_FILTER_PRI_REQUIRED,
ptp->rxfilter_event);
return rc;
}
static int efx_ptp_start(struct efx_nic *efx)
{
struct efx_ptp_data *ptp = efx->ptp_data;
int rc;
ptp->reset_required = false;
rc = efx_ptp_insert_multicast_filters(efx);
if (rc)
return rc;
rc = efx_ptp_enable(efx);
if (rc != 0)
goto fail;
ptp->evt_frag_idx = 0;
ptp->current_adjfreq = 0;
return 0;
fail:
efx_ptp_remove_multicast_filters(efx);
return rc;
}
static int efx_ptp_stop(struct efx_nic *efx)
{
struct efx_ptp_data *ptp = efx->ptp_data;
struct list_head *cursor;
struct list_head *next;
int rc;
if (ptp == NULL)
return 0;
rc = efx_ptp_disable(efx);
efx_ptp_remove_multicast_filters(efx);
efx_ptp_deliver_rx_queue(&efx->ptp_data->rxq);
skb_queue_purge(&efx->ptp_data->txq);
spin_lock_bh(&efx->ptp_data->evt_lock);
list_for_each_safe(cursor, next, &efx->ptp_data->evt_list) {
list_move(cursor, &efx->ptp_data->evt_free_list);
}
spin_unlock_bh(&efx->ptp_data->evt_lock);
return rc;
}
static int efx_ptp_restart(struct efx_nic *efx)
{
if (efx->ptp_data && efx->ptp_data->enabled)
return efx_ptp_start(efx);
return 0;
}
static void efx_ptp_pps_worker(struct work_struct *work)
{
struct efx_ptp_data *ptp =
container_of(work, struct efx_ptp_data, pps_work);
struct efx_nic *efx = ptp->efx;
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
struct efx_nic *efx = ptp_data->efx;
struct sk_buff *skb;
struct sk_buff_head tempq;
if (ptp_data->reset_required) {
efx_ptp_stop(efx);
efx_ptp_start(efx);
return;
}
efx_ptp_drop_time_expired_events(efx);
__skb_queue_head_init(&tempq);
efx_ptp_process_events(efx, &tempq);
while ((skb = skb_dequeue(&ptp_data->txq)))
efx_ptp_xmit_skb(efx, skb);
while ((skb = __skb_dequeue(&tempq)))
efx_ptp_process_rx(efx, skb);
}
int efx_ptp_probe(struct efx_nic *efx, struct efx_channel *channel)
{
struct efx_ptp_data *ptp;
int rc = 0;
unsigned int pos;
ptp = kzalloc(sizeof(struct efx_ptp_data), GFP_KERNEL);
efx->ptp_data = ptp;
if (!efx->ptp_data)
return -ENOMEM;
ptp->efx = efx;
ptp->channel = channel;
ptp->rx_ts_inline = efx_nic_rev(efx) >= EFX_REV_HUNT_A0;
rc = efx_nic_alloc_buffer(efx, &ptp->start, sizeof(int), GFP_KERNEL);
if (rc != 0)
goto fail1;
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
rc = efx_ptp_get_attributes(efx);
if (rc < 0)
goto fail3;
rc = efx_ptp_get_timestamp_corrections(efx);
if (rc < 0)
goto fail3;
if (efx->mcdi->fn_flags &
(1 << MC_CMD_DRV_ATTACH_EXT_OUT_FLAG_PRIMARY)) {
ptp->phc_clock_info = efx_phc_clock_info;
ptp->phc_clock = ptp_clock_register(&ptp->phc_clock_info,
&efx->pci_dev->dev);
if (IS_ERR(ptp->phc_clock)) {
rc = PTR_ERR(ptp->phc_clock);
goto fail3;
}
INIT_WORK(&ptp->pps_work, efx_ptp_pps_worker);
ptp->pps_workwq = create_singlethread_workqueue("sfc_pps");
if (!ptp->pps_workwq) {
rc = -ENOMEM;
goto fail4;
}
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
static int efx_ptp_probe_channel(struct efx_channel *channel)
{
struct efx_nic *efx = channel->efx;
channel->irq_moderation = 0;
channel->rx_queue.core_index = 0;
return efx_ptp_probe(efx, channel);
}
void efx_ptp_remove(struct efx_nic *efx)
{
if (!efx->ptp_data)
return;
(void)efx_ptp_disable(efx);
cancel_work_sync(&efx->ptp_data->work);
cancel_work_sync(&efx->ptp_data->pps_work);
skb_queue_purge(&efx->ptp_data->rxq);
skb_queue_purge(&efx->ptp_data->txq);
if (efx->ptp_data->phc_clock) {
destroy_workqueue(efx->ptp_data->pps_workwq);
ptp_clock_unregister(efx->ptp_data->phc_clock);
}
destroy_workqueue(efx->ptp_data->workwq);
efx_nic_free_buffer(efx, &efx->ptp_data->start);
kfree(efx->ptp_data);
}
static void efx_ptp_remove_channel(struct efx_channel *channel)
{
efx_ptp_remove(channel->efx);
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
skb_transport_header_was_set(skb) &&
skb_network_header_len(skb) >= sizeof(struct iphdr) &&
ip_hdr(skb)->protocol == IPPROTO_UDP &&
skb_headlen(skb) >=
skb_transport_offset(skb) + sizeof(struct udphdr) &&
udp_hdr(skb)->dest == htons(PTP_EVENT_PORT);
}
static bool efx_ptp_rx(struct efx_channel *channel, struct sk_buff *skb)
{
struct efx_nic *efx = channel->efx;
struct efx_ptp_data *ptp = efx->ptp_data;
struct efx_ptp_match *match = (struct efx_ptp_match *)skb->cb;
u8 *match_data_012, *match_data_345;
unsigned int version;
u8 *data;
match->expiry = jiffies + msecs_to_jiffies(PKT_EVENT_LIFETIME_MS);
if (ptp->mode == MC_CMD_PTP_MODE_V1) {
if (!pskb_may_pull(skb, PTP_V1_MIN_LENGTH)) {
return false;
}
data = skb->data;
version = ntohs(*(__be16 *)&data[PTP_V1_VERSION_OFFSET]);
if (version != PTP_VERSION_V1) {
return false;
}
match_data_012 = data + PTP_V1_UUID_OFFSET;
match_data_345 = data + PTP_V1_UUID_OFFSET + 3;
} else {
if (!pskb_may_pull(skb, PTP_V2_MIN_LENGTH)) {
return false;
}
data = skb->data;
version = data[PTP_V2_VERSION_OFFSET];
if ((version & PTP_VERSION_V2_MASK) != PTP_VERSION_V2) {
return false;
}
match_data_345 = data + PTP_V2_UUID_OFFSET + 5;
if (ptp->mode == MC_CMD_PTP_MODE_V2) {
match_data_012 = data + PTP_V2_UUID_OFFSET + 2;
} else {
match_data_012 = data + PTP_V2_UUID_OFFSET + 0;
BUG_ON(ptp->mode != MC_CMD_PTP_MODE_V2_ENHANCED);
}
}
if (ntohs(*(__be16 *)&data[PTP_DPORT_OFFSET]) == PTP_EVENT_PORT) {
match->state = PTP_PACKET_STATE_UNMATCHED;
BUILD_BUG_ON(PTP_V1_SEQUENCE_OFFSET != PTP_V2_SEQUENCE_OFFSET);
BUILD_BUG_ON(PTP_V1_SEQUENCE_LENGTH != PTP_V2_SEQUENCE_LENGTH);
match->words[0] = (match_data_012[0] |
(match_data_012[1] << 8) |
(match_data_012[2] << 16) |
(match_data_345[0] << 24));
match->words[1] = (match_data_345[1] |
(match_data_345[2] << 8) |
(data[PTP_V1_SEQUENCE_OFFSET +
PTP_V1_SEQUENCE_LENGTH - 1] <<
16));
} else {
match->state = PTP_PACKET_STATE_MATCH_UNWANTED;
}
skb_queue_tail(&ptp->rxq, skb);
queue_work(ptp->workwq, &ptp->work);
return true;
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
int efx_ptp_get_mode(struct efx_nic *efx)
{
return efx->ptp_data->mode;
}
int efx_ptp_change_mode(struct efx_nic *efx, bool enable_wanted,
unsigned int new_mode)
{
if ((enable_wanted != efx->ptp_data->enabled) ||
(enable_wanted && (efx->ptp_data->mode != new_mode))) {
int rc = 0;
if (enable_wanted) {
if (efx->ptp_data->enabled &&
(efx->ptp_data->mode != new_mode)) {
efx->ptp_data->enabled = false;
rc = efx_ptp_stop(efx);
if (rc != 0)
return rc;
}
efx->ptp_data->mode = new_mode;
if (netif_running(efx->net_dev))
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
int rc;
if (init->flags)
return -EINVAL;
if ((init->tx_type != HWTSTAMP_TX_OFF) &&
(init->tx_type != HWTSTAMP_TX_ON))
return -ERANGE;
rc = efx->type->ptp_set_ts_config(efx, init);
if (rc)
return rc;
efx->ptp_data->config = *init;
return 0;
}
void efx_ptp_get_ts_info(struct efx_nic *efx, struct ethtool_ts_info *ts_info)
{
struct efx_ptp_data *ptp = efx->ptp_data;
struct efx_nic *primary = efx->primary;
ASSERT_RTNL();
if (!ptp)
return;
ts_info->so_timestamping |= (SOF_TIMESTAMPING_TX_HARDWARE |
SOF_TIMESTAMPING_RX_HARDWARE |
SOF_TIMESTAMPING_RAW_HARDWARE);
if (primary && primary->ptp_data && primary->ptp_data->phc_clock)
ts_info->phc_index =
ptp_clock_index(primary->ptp_data->phc_clock);
ts_info->tx_types = 1 << HWTSTAMP_TX_OFF | 1 << HWTSTAMP_TX_ON;
ts_info->rx_filters = ptp->efx->type->hwtstamp_filters;
}
int efx_ptp_set_ts_config(struct efx_nic *efx, struct ifreq *ifr)
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
int efx_ptp_get_ts_config(struct efx_nic *efx, struct ifreq *ifr)
{
if (!efx->ptp_data)
return -EOPNOTSUPP;
return copy_to_user(ifr->ifr_data, &efx->ptp_data->config,
sizeof(efx->ptp_data->config)) ? -EFAULT : 0;
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
if (WARN_ON_ONCE(ptp->rx_ts_inline))
return;
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
evt->hwtimestamp = efx->ptp_data->nic_to_kernel_time(
EFX_QWORD_FIELD(ptp->evt_frags[0], MCDI_EVENT_DATA),
EFX_QWORD_FIELD(ptp->evt_frags[1], MCDI_EVENT_DATA),
ptp->ts_corrections.rx);
evt->expiry = jiffies + msecs_to_jiffies(PKT_EVENT_LIFETIME_MS);
list_add_tail(&evt->link, &ptp->evt_list);
queue_work(ptp->workwq, &ptp->work);
} else if (net_ratelimit()) {
netif_err(efx, rx_err, efx->net_dev, "PTP event queue overflow\n");
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
if (!ptp) {
if (net_ratelimit())
netif_warn(efx, drv, efx->net_dev,
"Received PTP event but PTP not set up\n");
return;
}
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
void efx_time_sync_event(struct efx_channel *channel, efx_qword_t *ev)
{
channel->sync_timestamp_major = MCDI_EVENT_FIELD(*ev, PTP_TIME_MAJOR);
channel->sync_timestamp_minor =
MCDI_EVENT_FIELD(*ev, PTP_TIME_MINOR_26_19) << 19;
(void) cmpxchg(&channel->sync_events_state, SYNC_EVENTS_REQUESTED,
SYNC_EVENTS_VALID);
}
static inline u32 efx_rx_buf_timestamp_minor(struct efx_nic *efx, const u8 *eh)
{
#if defined(CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS)
return __le32_to_cpup((const __le32 *)(eh + efx->rx_packet_ts_offset));
#else
const u8 *data = eh + efx->rx_packet_ts_offset;
return (u32)data[0] |
(u32)data[1] << 8 |
(u32)data[2] << 16 |
(u32)data[3] << 24;
#endif
}
void __efx_rx_skb_attach_timestamp(struct efx_channel *channel,
struct sk_buff *skb)
{
struct efx_nic *efx = channel->efx;
u32 pkt_timestamp_major, pkt_timestamp_minor;
u32 diff, carry;
struct skb_shared_hwtstamps *timestamps;
pkt_timestamp_minor = (efx_rx_buf_timestamp_minor(efx,
skb_mac_header(skb)) +
(u32) efx->ptp_data->ts_corrections.rx) &
(MINOR_TICKS_PER_SECOND - 1);
diff = (pkt_timestamp_minor - channel->sync_timestamp_minor) &
(MINOR_TICKS_PER_SECOND - 1);
carry = channel->sync_timestamp_minor + diff > MINOR_TICKS_PER_SECOND ?
1 : 0;
if (diff <= MINOR_TICKS_PER_SECOND / EXPECTED_SYNC_EVENTS_PER_SECOND +
FUZZ) {
pkt_timestamp_major = channel->sync_timestamp_major + carry;
} else if (diff >= MINOR_TICKS_PER_SECOND - FUZZ) {
pkt_timestamp_major = channel->sync_timestamp_major - 1 + carry;
} else {
netif_vdbg(efx, drv, efx->net_dev,
"packet timestamp %x too far from sync event %x:%x\n",
pkt_timestamp_minor, channel->sync_timestamp_major,
channel->sync_timestamp_minor);
return;
}
timestamps = skb_hwtstamps(skb);
timestamps->hwtstamp =
efx_ptp_s27_to_ktime(pkt_timestamp_major, pkt_timestamp_minor);
}
static int efx_phc_adjfreq(struct ptp_clock_info *ptp, s32 delta)
{
struct efx_ptp_data *ptp_data = container_of(ptp,
struct efx_ptp_data,
phc_clock_info);
struct efx_nic *efx = ptp_data->efx;
MCDI_DECLARE_BUF(inadj, MC_CMD_PTP_IN_ADJUST_LEN);
s64 adjustment_ns;
int rc;
if (delta > MAX_PPB)
delta = MAX_PPB;
else if (delta < -MAX_PPB)
delta = -MAX_PPB;
adjustment_ns = (((s64)delta * PPB_SCALE_WORD) >>
(PPB_EXTRA_BITS + MAX_PPB_BITS));
MCDI_SET_DWORD(inadj, PTP_IN_OP, MC_CMD_PTP_OP_ADJUST);
MCDI_SET_DWORD(inadj, PTP_IN_PERIPH_ID, 0);
MCDI_SET_QWORD(inadj, PTP_IN_ADJUST_FREQ, adjustment_ns);
MCDI_SET_DWORD(inadj, PTP_IN_ADJUST_SECONDS, 0);
MCDI_SET_DWORD(inadj, PTP_IN_ADJUST_NANOSECONDS, 0);
rc = efx_mcdi_rpc(efx, MC_CMD_PTP, inadj, sizeof(inadj),
NULL, 0, NULL);
if (rc != 0)
return rc;
ptp_data->current_adjfreq = adjustment_ns;
return 0;
}
static int efx_phc_adjtime(struct ptp_clock_info *ptp, s64 delta)
{
u32 nic_major, nic_minor;
struct efx_ptp_data *ptp_data = container_of(ptp,
struct efx_ptp_data,
phc_clock_info);
struct efx_nic *efx = ptp_data->efx;
MCDI_DECLARE_BUF(inbuf, MC_CMD_PTP_IN_ADJUST_LEN);
efx->ptp_data->ns_to_nic_time(delta, &nic_major, &nic_minor);
MCDI_SET_DWORD(inbuf, PTP_IN_OP, MC_CMD_PTP_OP_ADJUST);
MCDI_SET_DWORD(inbuf, PTP_IN_PERIPH_ID, 0);
MCDI_SET_QWORD(inbuf, PTP_IN_ADJUST_FREQ, ptp_data->current_adjfreq);
MCDI_SET_DWORD(inbuf, PTP_IN_ADJUST_MAJOR, nic_major);
MCDI_SET_DWORD(inbuf, PTP_IN_ADJUST_MINOR, nic_minor);
return efx_mcdi_rpc(efx, MC_CMD_PTP, inbuf, sizeof(inbuf),
NULL, 0, NULL);
}
static int efx_phc_gettime(struct ptp_clock_info *ptp, struct timespec64 *ts)
{
struct efx_ptp_data *ptp_data = container_of(ptp,
struct efx_ptp_data,
phc_clock_info);
struct efx_nic *efx = ptp_data->efx;
MCDI_DECLARE_BUF(inbuf, MC_CMD_PTP_IN_READ_NIC_TIME_LEN);
MCDI_DECLARE_BUF(outbuf, MC_CMD_PTP_OUT_READ_NIC_TIME_LEN);
int rc;
ktime_t kt;
MCDI_SET_DWORD(inbuf, PTP_IN_OP, MC_CMD_PTP_OP_READ_NIC_TIME);
MCDI_SET_DWORD(inbuf, PTP_IN_PERIPH_ID, 0);
rc = efx_mcdi_rpc(efx, MC_CMD_PTP, inbuf, sizeof(inbuf),
outbuf, sizeof(outbuf), NULL);
if (rc != 0)
return rc;
kt = ptp_data->nic_to_kernel_time(
MCDI_DWORD(outbuf, PTP_OUT_READ_NIC_TIME_MAJOR),
MCDI_DWORD(outbuf, PTP_OUT_READ_NIC_TIME_MINOR), 0);
*ts = ktime_to_timespec64(kt);
return 0;
}
static int efx_phc_settime(struct ptp_clock_info *ptp,
const struct timespec64 *e_ts)
{
int rc;
struct timespec64 time_now;
struct timespec64 delta;
rc = efx_phc_gettime(ptp, &time_now);
if (rc != 0)
return rc;
delta = timespec64_sub(*e_ts, time_now);
rc = efx_phc_adjtime(ptp, timespec64_to_ns(&delta));
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
void efx_ptp_defer_probe_with_channel(struct efx_nic *efx)
{
if (efx_ptp_disable(efx) == 0)
efx->extra_channel_type[EFX_EXTRA_CHANNEL_PTP] =
&efx_ptp_channel_type;
}
void efx_ptp_start_datapath(struct efx_nic *efx)
{
if (efx_ptp_restart(efx))
netif_err(efx, drv, efx->net_dev, "Failed to restart PTP.\n");
if (efx->type->ptp_set_ts_sync_events)
efx->type->ptp_set_ts_sync_events(efx, true, true);
}
void efx_ptp_stop_datapath(struct efx_nic *efx)
{
if (efx->type->ptp_set_ts_sync_events)
efx->type->ptp_set_ts_sync_events(efx, false, true);
efx_ptp_stop(efx);
}
