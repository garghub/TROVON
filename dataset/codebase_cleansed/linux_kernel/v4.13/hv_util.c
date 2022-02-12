static void perform_shutdown(struct work_struct *dummy)
{
orderly_poweroff(true);
}
static void shutdown_onchannelcallback(void *context)
{
struct vmbus_channel *channel = context;
u32 recvlen;
u64 requestid;
bool execute_shutdown = false;
u8 *shut_txf_buf = util_shutdown.recv_buffer;
struct shutdown_msg_data *shutdown_msg;
struct icmsg_hdr *icmsghdrp;
vmbus_recvpacket(channel, shut_txf_buf,
PAGE_SIZE, &recvlen, &requestid);
if (recvlen > 0) {
icmsghdrp = (struct icmsg_hdr *)&shut_txf_buf[
sizeof(struct vmbuspipe_hdr)];
if (icmsghdrp->icmsgtype == ICMSGTYPE_NEGOTIATE) {
if (vmbus_prep_negotiate_resp(icmsghdrp, shut_txf_buf,
fw_versions, FW_VER_COUNT,
sd_versions, SD_VER_COUNT,
NULL, &sd_srv_version)) {
pr_info("Shutdown IC version %d.%d\n",
sd_srv_version >> 16,
sd_srv_version & 0xFFFF);
}
} else {
shutdown_msg =
(struct shutdown_msg_data *)&shut_txf_buf[
sizeof(struct vmbuspipe_hdr) +
sizeof(struct icmsg_hdr)];
switch (shutdown_msg->flags) {
case 0:
case 1:
icmsghdrp->status = HV_S_OK;
execute_shutdown = true;
pr_info("Shutdown request received -"
" graceful shutdown initiated\n");
break;
default:
icmsghdrp->status = HV_E_FAIL;
execute_shutdown = false;
pr_info("Shutdown request received -"
" Invalid request\n");
break;
}
}
icmsghdrp->icflags = ICMSGHDRFLAG_TRANSACTION
| ICMSGHDRFLAG_RESPONSE;
vmbus_sendpacket(channel, shut_txf_buf,
recvlen, requestid,
VM_PKT_DATA_INBAND, 0);
}
if (execute_shutdown == true)
schedule_work(&shutdown_work);
}
static struct timespec64 hv_get_adj_host_time(void)
{
struct timespec64 ts;
u64 newtime, reftime;
unsigned long flags;
spin_lock_irqsave(&host_ts.lock, flags);
reftime = hyperv_cs->read(hyperv_cs);
newtime = host_ts.host_time + (reftime - host_ts.ref_time);
ts = ns_to_timespec64((newtime - WLTIMEDELTA) * 100);
spin_unlock_irqrestore(&host_ts.lock, flags);
return ts;
}
static void hv_set_host_time(struct work_struct *work)
{
struct timespec64 ts = hv_get_adj_host_time();
do_settimeofday64(&ts);
}
static inline void adj_guesttime(u64 hosttime, u64 reftime, u8 adj_flags)
{
unsigned long flags;
u64 cur_reftime;
spin_lock_irqsave(&host_ts.lock, flags);
cur_reftime = hyperv_cs->read(hyperv_cs);
host_ts.host_time = hosttime;
host_ts.ref_time = cur_reftime;
host_ts.host_time += (cur_reftime - reftime);
spin_unlock_irqrestore(&host_ts.lock, flags);
if (adj_flags & ICTIMESYNCFLAG_SYNC)
schedule_work(&adj_time_work);
}
static void timesync_onchannelcallback(void *context)
{
struct vmbus_channel *channel = context;
u32 recvlen;
u64 requestid;
struct icmsg_hdr *icmsghdrp;
struct ictimesync_data *timedatap;
struct ictimesync_ref_data *refdata;
u8 *time_txf_buf = util_timesynch.recv_buffer;
vmbus_recvpacket(channel, time_txf_buf,
PAGE_SIZE, &recvlen, &requestid);
if (recvlen > 0) {
icmsghdrp = (struct icmsg_hdr *)&time_txf_buf[
sizeof(struct vmbuspipe_hdr)];
if (icmsghdrp->icmsgtype == ICMSGTYPE_NEGOTIATE) {
if (vmbus_prep_negotiate_resp(icmsghdrp, time_txf_buf,
fw_versions, FW_VER_COUNT,
ts_versions, TS_VER_COUNT,
NULL, &ts_srv_version)) {
pr_info("TimeSync IC version %d.%d\n",
ts_srv_version >> 16,
ts_srv_version & 0xFFFF);
}
} else {
if (ts_srv_version > TS_VERSION_3) {
refdata = (struct ictimesync_ref_data *)
&time_txf_buf[
sizeof(struct vmbuspipe_hdr) +
sizeof(struct icmsg_hdr)];
adj_guesttime(refdata->parenttime,
refdata->vmreferencetime,
refdata->flags);
} else {
timedatap = (struct ictimesync_data *)
&time_txf_buf[
sizeof(struct vmbuspipe_hdr) +
sizeof(struct icmsg_hdr)];
adj_guesttime(timedatap->parenttime,
hyperv_cs->read(hyperv_cs),
timedatap->flags);
}
}
icmsghdrp->icflags = ICMSGHDRFLAG_TRANSACTION
| ICMSGHDRFLAG_RESPONSE;
vmbus_sendpacket(channel, time_txf_buf,
recvlen, requestid,
VM_PKT_DATA_INBAND, 0);
}
}
static void heartbeat_onchannelcallback(void *context)
{
struct vmbus_channel *channel = context;
u32 recvlen;
u64 requestid;
struct icmsg_hdr *icmsghdrp;
struct heartbeat_msg_data *heartbeat_msg;
u8 *hbeat_txf_buf = util_heartbeat.recv_buffer;
while (1) {
vmbus_recvpacket(channel, hbeat_txf_buf,
PAGE_SIZE, &recvlen, &requestid);
if (!recvlen)
break;
icmsghdrp = (struct icmsg_hdr *)&hbeat_txf_buf[
sizeof(struct vmbuspipe_hdr)];
if (icmsghdrp->icmsgtype == ICMSGTYPE_NEGOTIATE) {
if (vmbus_prep_negotiate_resp(icmsghdrp,
hbeat_txf_buf,
fw_versions, FW_VER_COUNT,
hb_versions, HB_VER_COUNT,
NULL, &hb_srv_version)) {
pr_info("Heartbeat IC version %d.%d\n",
hb_srv_version >> 16,
hb_srv_version & 0xFFFF);
}
} else {
heartbeat_msg =
(struct heartbeat_msg_data *)&hbeat_txf_buf[
sizeof(struct vmbuspipe_hdr) +
sizeof(struct icmsg_hdr)];
heartbeat_msg->seq_num += 1;
}
icmsghdrp->icflags = ICMSGHDRFLAG_TRANSACTION
| ICMSGHDRFLAG_RESPONSE;
vmbus_sendpacket(channel, hbeat_txf_buf,
recvlen, requestid,
VM_PKT_DATA_INBAND, 0);
}
}
static int util_probe(struct hv_device *dev,
const struct hv_vmbus_device_id *dev_id)
{
struct hv_util_service *srv =
(struct hv_util_service *)dev_id->driver_data;
int ret;
srv->recv_buffer = kmalloc(PAGE_SIZE * 4, GFP_KERNEL);
if (!srv->recv_buffer)
return -ENOMEM;
srv->channel = dev->channel;
if (srv->util_init) {
ret = srv->util_init(srv);
if (ret) {
ret = -ENODEV;
goto error1;
}
}
set_channel_read_mode(dev->channel, HV_CALL_DIRECT);
hv_set_drvdata(dev, srv);
ret = vmbus_open(dev->channel, 4 * PAGE_SIZE, 4 * PAGE_SIZE, NULL, 0,
srv->util_cb, dev->channel);
if (ret)
goto error;
return 0;
error:
if (srv->util_deinit)
srv->util_deinit();
error1:
kfree(srv->recv_buffer);
return ret;
}
static int util_remove(struct hv_device *dev)
{
struct hv_util_service *srv = hv_get_drvdata(dev);
if (srv->util_deinit)
srv->util_deinit();
vmbus_close(dev->channel);
kfree(srv->recv_buffer);
return 0;
}
static int hv_ptp_enable(struct ptp_clock_info *info,
struct ptp_clock_request *request, int on)
{
return -EOPNOTSUPP;
}
static int hv_ptp_settime(struct ptp_clock_info *p, const struct timespec64 *ts)
{
return -EOPNOTSUPP;
}
static int hv_ptp_adjfreq(struct ptp_clock_info *ptp, s32 delta)
{
return -EOPNOTSUPP;
}
static int hv_ptp_adjtime(struct ptp_clock_info *ptp, s64 delta)
{
return -EOPNOTSUPP;
}
static int hv_ptp_gettime(struct ptp_clock_info *info, struct timespec64 *ts)
{
*ts = hv_get_adj_host_time();
return 0;
}
static int hv_timesync_init(struct hv_util_service *srv)
{
if (!hyperv_cs)
return -ENODEV;
spin_lock_init(&host_ts.lock);
INIT_WORK(&adj_time_work, hv_set_host_time);
hv_ptp_clock = ptp_clock_register(&ptp_hyperv_info, NULL);
if (IS_ERR_OR_NULL(hv_ptp_clock)) {
pr_err("cannot register PTP clock: %ld\n",
PTR_ERR(hv_ptp_clock));
hv_ptp_clock = NULL;
}
return 0;
}
static void hv_timesync_deinit(void)
{
if (hv_ptp_clock)
ptp_clock_unregister(hv_ptp_clock);
cancel_work_sync(&adj_time_work);
}
static int __init init_hyperv_utils(void)
{
pr_info("Registering HyperV Utility Driver\n");
return vmbus_driver_register(&util_drv);
}
static void exit_hyperv_utils(void)
{
pr_info("De-Registered HyperV Utility Driver\n");
vmbus_driver_unregister(&util_drv);
}
