static void shutdown_onchannelcallback(void *context)
{
struct vmbus_channel *channel = context;
u32 recvlen;
u64 requestid;
u8 execute_shutdown = false;
struct shutdown_msg_data *shutdown_msg;
struct icmsg_hdr *icmsghdrp;
struct icmsg_negotiate *negop = NULL;
vmbus_recvpacket(channel, shut_txf_buf,
PAGE_SIZE, &recvlen, &requestid);
if (recvlen > 0) {
icmsghdrp = (struct icmsg_hdr *)&shut_txf_buf[
sizeof(struct vmbuspipe_hdr)];
if (icmsghdrp->icmsgtype == ICMSGTYPE_NEGOTIATE) {
prep_negotiate_resp(icmsghdrp, negop, shut_txf_buf);
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
orderly_poweroff(false);
}
static inline void do_adj_guesttime(u64 hosttime)
{
s64 host_tns;
struct timespec host_ts;
host_tns = (hosttime - WLTIMEDELTA) * 100;
host_ts = ns_to_timespec(host_tns);
do_settimeofday(&host_ts);
}
static inline void adj_guesttime(u64 hosttime, u8 flags)
{
static s32 scnt = 50;
if ((flags & ICTIMESYNCFLAG_SYNC) != 0) {
do_adj_guesttime(hosttime);
return;
}
if ((flags & ICTIMESYNCFLAG_SAMPLE) != 0 && scnt > 0) {
scnt--;
do_adj_guesttime(hosttime);
}
}
static void timesync_onchannelcallback(void *context)
{
struct vmbus_channel *channel = context;
u32 recvlen;
u64 requestid;
struct icmsg_hdr *icmsghdrp;
struct ictimesync_data *timedatap;
vmbus_recvpacket(channel, time_txf_buf,
PAGE_SIZE, &recvlen, &requestid);
if (recvlen > 0) {
icmsghdrp = (struct icmsg_hdr *)&time_txf_buf[
sizeof(struct vmbuspipe_hdr)];
if (icmsghdrp->icmsgtype == ICMSGTYPE_NEGOTIATE) {
prep_negotiate_resp(icmsghdrp, NULL, time_txf_buf);
} else {
timedatap = (struct ictimesync_data *)&time_txf_buf[
sizeof(struct vmbuspipe_hdr) +
sizeof(struct icmsg_hdr)];
adj_guesttime(timedatap->parenttime, timedatap->flags);
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
vmbus_recvpacket(channel, hbeat_txf_buf,
PAGE_SIZE, &recvlen, &requestid);
if (recvlen > 0) {
icmsghdrp = (struct icmsg_hdr *)&hbeat_txf_buf[
sizeof(struct vmbuspipe_hdr)];
if (icmsghdrp->icmsgtype == ICMSGTYPE_NEGOTIATE) {
prep_negotiate_resp(icmsghdrp, NULL, hbeat_txf_buf);
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
static int __init init_hyperv_utils(void)
{
pr_info("Registering HyperV Utility Driver\n");
if (hv_kvp_init())
return -ENODEV;
if (!dmi_check_system(hv_utils_dmi_table))
return -ENODEV;
shut_txf_buf = kmalloc(PAGE_SIZE, GFP_KERNEL);
time_txf_buf = kmalloc(PAGE_SIZE, GFP_KERNEL);
hbeat_txf_buf = kmalloc(PAGE_SIZE, GFP_KERNEL);
if (!shut_txf_buf || !time_txf_buf || !hbeat_txf_buf) {
pr_info("Unable to allocate memory for receive buffer\n");
kfree(shut_txf_buf);
kfree(time_txf_buf);
kfree(hbeat_txf_buf);
return -ENOMEM;
}
hv_cb_utils[HV_SHUTDOWN_MSG].callback = &shutdown_onchannelcallback;
hv_cb_utils[HV_TIMESYNC_MSG].callback = &timesync_onchannelcallback;
hv_cb_utils[HV_HEARTBEAT_MSG].callback = &heartbeat_onchannelcallback;
hv_cb_utils[HV_KVP_MSG].callback = &hv_kvp_onchannelcallback;
return 0;
}
static void exit_hyperv_utils(void)
{
pr_info("De-Registered HyperV Utility Driver\n");
if (hv_cb_utils[HV_SHUTDOWN_MSG].channel != NULL)
hv_cb_utils[HV_SHUTDOWN_MSG].channel->onchannel_callback =
&chn_cb_negotiate;
hv_cb_utils[HV_SHUTDOWN_MSG].callback = NULL;
if (hv_cb_utils[HV_TIMESYNC_MSG].channel != NULL)
hv_cb_utils[HV_TIMESYNC_MSG].channel->onchannel_callback =
&chn_cb_negotiate;
hv_cb_utils[HV_TIMESYNC_MSG].callback = NULL;
if (hv_cb_utils[HV_HEARTBEAT_MSG].channel != NULL)
hv_cb_utils[HV_HEARTBEAT_MSG].channel->onchannel_callback =
&chn_cb_negotiate;
hv_cb_utils[HV_HEARTBEAT_MSG].callback = NULL;
if (hv_cb_utils[HV_KVP_MSG].channel != NULL)
hv_cb_utils[HV_KVP_MSG].channel->onchannel_callback =
&chn_cb_negotiate;
hv_cb_utils[HV_KVP_MSG].callback = NULL;
hv_kvp_deinit();
kfree(shut_txf_buf);
kfree(time_txf_buf);
kfree(hbeat_txf_buf);
}
