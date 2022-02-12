static void fcopy_timeout_func(struct work_struct *dummy)
{
fcopy_respond_to_host(HV_E_FAIL);
if (fcopy_transaction.state > HVUTIL_READY)
fcopy_transaction.state = HVUTIL_READY;
hv_poll_channel(fcopy_transaction.fcopy_context,
hv_fcopy_onchannelcallback);
}
static int fcopy_handle_handshake(u32 version)
{
u32 our_ver = FCOPY_CURRENT_VERSION;
switch (version) {
case FCOPY_VERSION_0:
dm_reg_value = version;
break;
case FCOPY_VERSION_1:
if (hvutil_transport_send(hvt, &our_ver, sizeof(our_ver)))
return -EFAULT;
dm_reg_value = version;
break;
default:
return -EINVAL;
}
pr_debug("FCP: userspace daemon ver. %d registered\n", version);
fcopy_transaction.state = HVUTIL_READY;
hv_poll_channel(fcopy_transaction.fcopy_context,
hv_fcopy_onchannelcallback);
return 0;
}
static void fcopy_send_data(struct work_struct *dummy)
{
struct hv_start_fcopy smsg_out;
int operation = fcopy_transaction.fcopy_msg->operation;
struct hv_start_fcopy *smsg_in;
void *out_src;
int rc, out_len;
switch (operation) {
case START_FILE_COPY:
out_len = sizeof(struct hv_start_fcopy);
memset(&smsg_out, 0, out_len);
smsg_out.hdr.operation = operation;
smsg_in = (struct hv_start_fcopy *)fcopy_transaction.fcopy_msg;
utf16s_to_utf8s((wchar_t *)smsg_in->file_name, W_MAX_PATH,
UTF16_LITTLE_ENDIAN,
(__u8 *)&smsg_out.file_name, W_MAX_PATH - 1);
utf16s_to_utf8s((wchar_t *)smsg_in->path_name, W_MAX_PATH,
UTF16_LITTLE_ENDIAN,
(__u8 *)&smsg_out.path_name, W_MAX_PATH - 1);
smsg_out.copy_flags = smsg_in->copy_flags;
smsg_out.file_size = smsg_in->file_size;
out_src = &smsg_out;
break;
default:
out_src = fcopy_transaction.fcopy_msg;
out_len = fcopy_transaction.recv_len;
break;
}
fcopy_transaction.state = HVUTIL_USERSPACE_REQ;
rc = hvutil_transport_send(hvt, out_src, out_len);
if (rc) {
pr_debug("FCP: failed to communicate to the daemon: %d\n", rc);
if (cancel_delayed_work_sync(&fcopy_timeout_work)) {
fcopy_respond_to_host(HV_E_FAIL);
fcopy_transaction.state = HVUTIL_READY;
}
}
return;
}
static void
fcopy_respond_to_host(int error)
{
struct icmsg_hdr *icmsghdr;
u32 buf_len;
struct vmbus_channel *channel;
u64 req_id;
buf_len = fcopy_transaction.recv_len;
channel = fcopy_transaction.recv_channel;
req_id = fcopy_transaction.recv_req_id;
icmsghdr = (struct icmsg_hdr *)
&recv_buffer[sizeof(struct vmbuspipe_hdr)];
if (channel->onchannel_callback == NULL)
return;
icmsghdr->status = error;
icmsghdr->icflags = ICMSGHDRFLAG_TRANSACTION | ICMSGHDRFLAG_RESPONSE;
vmbus_sendpacket(channel, recv_buffer, buf_len, req_id,
VM_PKT_DATA_INBAND, 0);
}
void hv_fcopy_onchannelcallback(void *context)
{
struct vmbus_channel *channel = context;
u32 recvlen;
u64 requestid;
struct hv_fcopy_hdr *fcopy_msg;
struct icmsg_hdr *icmsghdr;
struct icmsg_negotiate *negop = NULL;
int util_fw_version;
int fcopy_srv_version;
if (fcopy_transaction.state > HVUTIL_READY) {
fcopy_transaction.fcopy_context = context;
return;
}
fcopy_transaction.fcopy_context = NULL;
vmbus_recvpacket(channel, recv_buffer, PAGE_SIZE * 2, &recvlen,
&requestid);
if (recvlen <= 0)
return;
icmsghdr = (struct icmsg_hdr *)&recv_buffer[
sizeof(struct vmbuspipe_hdr)];
if (icmsghdr->icmsgtype == ICMSGTYPE_NEGOTIATE) {
util_fw_version = UTIL_FW_VERSION;
fcopy_srv_version = WIN8_SRV_VERSION;
vmbus_prep_negotiate_resp(icmsghdr, negop, recv_buffer,
util_fw_version, fcopy_srv_version);
} else {
fcopy_msg = (struct hv_fcopy_hdr *)&recv_buffer[
sizeof(struct vmbuspipe_hdr) +
sizeof(struct icmsg_hdr)];
fcopy_transaction.recv_len = recvlen;
fcopy_transaction.recv_channel = channel;
fcopy_transaction.recv_req_id = requestid;
fcopy_transaction.fcopy_msg = fcopy_msg;
if (fcopy_transaction.state < HVUTIL_READY) {
fcopy_respond_to_host(HV_E_FAIL);
return;
}
fcopy_transaction.state = HVUTIL_HOSTMSG_RECEIVED;
schedule_work(&fcopy_send_work);
schedule_delayed_work(&fcopy_timeout_work, 5*HZ);
return;
}
icmsghdr->icflags = ICMSGHDRFLAG_TRANSACTION | ICMSGHDRFLAG_RESPONSE;
vmbus_sendpacket(channel, recv_buffer, recvlen, requestid,
VM_PKT_DATA_INBAND, 0);
}
static int fcopy_on_msg(void *msg, int len)
{
int *val = (int *)msg;
if (len != sizeof(int))
return -EINVAL;
if (fcopy_transaction.state == HVUTIL_DEVICE_INIT)
return fcopy_handle_handshake(*val);
if (fcopy_transaction.state != HVUTIL_USERSPACE_REQ)
return -EINVAL;
if (cancel_delayed_work_sync(&fcopy_timeout_work)) {
fcopy_transaction.state = HVUTIL_USERSPACE_RECV;
fcopy_respond_to_host(*val);
fcopy_transaction.state = HVUTIL_READY;
hv_poll_channel(fcopy_transaction.fcopy_context,
hv_fcopy_onchannelcallback);
}
return 0;
}
static void fcopy_on_reset(void)
{
fcopy_transaction.state = HVUTIL_DEVICE_INIT;
if (cancel_delayed_work_sync(&fcopy_timeout_work))
fcopy_respond_to_host(HV_E_FAIL);
}
int hv_fcopy_init(struct hv_util_service *srv)
{
recv_buffer = srv->recv_buffer;
fcopy_transaction.state = HVUTIL_DEVICE_INIT;
hvt = hvutil_transport_init(fcopy_devname, 0, 0,
fcopy_on_msg, fcopy_on_reset);
if (!hvt)
return -EFAULT;
return 0;
}
void hv_fcopy_deinit(void)
{
fcopy_transaction.state = HVUTIL_DEVICE_DYING;
cancel_delayed_work_sync(&fcopy_timeout_work);
hvutil_transport_destroy(hvt);
}
