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
struct icmsg_negotiate *negop = NULL;
vmbus_recvpacket(channel, shut_txf_buf,
PAGE_SIZE, &recvlen, &requestid);
if (recvlen > 0) {
icmsghdrp = (struct icmsg_hdr *)&shut_txf_buf[
sizeof(struct vmbuspipe_hdr)];
if (icmsghdrp->icmsgtype == ICMSGTYPE_NEGOTIATE) {
vmbus_prep_negotiate_resp(icmsghdrp, negop,
shut_txf_buf, util_fw_version,
sd_srv_version);
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
static void hv_set_host_time(struct work_struct *work)
{
struct adj_time_work *wrk;
s64 host_tns;
u64 newtime;
struct timespec host_ts;
wrk = container_of(work, struct adj_time_work, work);
newtime = wrk->host_time;
if (ts_srv_version > TS_VERSION_3) {
u64 current_tick;
rdmsrl(HV_X64_MSR_TIME_REF_COUNT, current_tick);
newtime += (current_tick - wrk->ref_time);
}
host_tns = (newtime - WLTIMEDELTA) * 100;
host_ts = ns_to_timespec(host_tns);
do_settimeofday(&host_ts);
}
static inline void adj_guesttime(u64 hosttime, u64 reftime, u8 flags)
{
if (work_pending(&wrk.work))
return;
wrk.host_time = hosttime;
wrk.ref_time = reftime;
wrk.flags = flags;
if ((flags & (ICTIMESYNCFLAG_SYNC | ICTIMESYNCFLAG_SAMPLE)) != 0) {
schedule_work(&wrk.work);
}
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
struct icmsg_negotiate *negop = NULL;
vmbus_recvpacket(channel, time_txf_buf,
PAGE_SIZE, &recvlen, &requestid);
if (recvlen > 0) {
icmsghdrp = (struct icmsg_hdr *)&time_txf_buf[
sizeof(struct vmbuspipe_hdr)];
if (icmsghdrp->icmsgtype == ICMSGTYPE_NEGOTIATE) {
vmbus_prep_negotiate_resp(icmsghdrp, negop,
time_txf_buf,
util_fw_version,
ts_srv_version);
pr_info("Using TimeSync version %d.%d\n",
ts_srv_version >> 16, ts_srv_version & 0xFFFF);
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
0,
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
struct icmsg_negotiate *negop = NULL;
while (1) {
vmbus_recvpacket(channel, hbeat_txf_buf,
PAGE_SIZE, &recvlen, &requestid);
if (!recvlen)
break;
icmsghdrp = (struct icmsg_hdr *)&hbeat_txf_buf[
sizeof(struct vmbuspipe_hdr)];
if (icmsghdrp->icmsgtype == ICMSGTYPE_NEGOTIATE) {
vmbus_prep_negotiate_resp(icmsghdrp, negop,
hbeat_txf_buf, util_fw_version,
hb_srv_version);
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
set_channel_read_state(dev->channel, false);
hv_set_drvdata(dev, srv);
switch (vmbus_proto_version) {
case (VERSION_WS2008):
util_fw_version = UTIL_WS2K8_FW_VERSION;
sd_srv_version = SD_VERSION_1;
ts_srv_version = TS_VERSION_1;
hb_srv_version = HB_VERSION_1;
break;
case(VERSION_WIN10):
util_fw_version = UTIL_FW_VERSION;
sd_srv_version = SD_VERSION;
ts_srv_version = TS_VERSION;
hb_srv_version = HB_VERSION;
break;
default:
util_fw_version = UTIL_FW_VERSION;
sd_srv_version = SD_VERSION;
ts_srv_version = TS_VERSION_3;
hb_srv_version = HB_VERSION;
}
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
static int hv_timesync_init(struct hv_util_service *srv)
{
INIT_WORK(&wrk.work, hv_set_host_time);
return 0;
}
static void hv_timesync_deinit(void)
{
cancel_work_sync(&wrk.work);
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
