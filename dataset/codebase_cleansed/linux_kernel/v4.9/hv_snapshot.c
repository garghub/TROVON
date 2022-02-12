static void vss_poll_wrapper(void *channel)
{
vss_transaction.state = HVUTIL_READY;
hv_vss_onchannelcallback(channel);
}
static void vss_timeout_func(struct work_struct *dummy)
{
pr_warn("VSS: timeout waiting for daemon to reply\n");
vss_respond_to_host(HV_E_FAIL);
hv_poll_channel(vss_transaction.recv_channel, vss_poll_wrapper);
}
static void vss_register_done(void)
{
hv_poll_channel(vss_transaction.recv_channel, vss_poll_wrapper);
pr_debug("VSS: userspace daemon registered\n");
}
static int vss_handle_handshake(struct hv_vss_msg *vss_msg)
{
u32 our_ver = VSS_OP_REGISTER1;
switch (vss_msg->vss_hdr.operation) {
case VSS_OP_REGISTER:
dm_reg_value = VSS_OP_REGISTER;
break;
case VSS_OP_REGISTER1:
if (hvutil_transport_send(hvt, &our_ver, sizeof(our_ver),
vss_register_done))
return -EFAULT;
dm_reg_value = VSS_OP_REGISTER1;
break;
default:
return -EINVAL;
}
pr_debug("VSS: userspace daemon ver. %d connected\n", dm_reg_value);
return 0;
}
static int vss_on_msg(void *msg, int len)
{
struct hv_vss_msg *vss_msg = (struct hv_vss_msg *)msg;
if (len != sizeof(*vss_msg))
return -EINVAL;
if (vss_msg->vss_hdr.operation == VSS_OP_REGISTER ||
vss_msg->vss_hdr.operation == VSS_OP_REGISTER1) {
if (vss_transaction.state > HVUTIL_READY)
return -EINVAL;
return vss_handle_handshake(vss_msg);
} else if (vss_transaction.state == HVUTIL_USERSPACE_REQ) {
vss_transaction.state = HVUTIL_USERSPACE_RECV;
if (vss_msg->vss_hdr.operation == VSS_OP_HOT_BACKUP)
vss_transaction.msg->vss_cf.flags =
VSS_HBU_NO_AUTO_RECOVERY;
if (cancel_delayed_work_sync(&vss_timeout_work)) {
vss_respond_to_host(vss_msg->error);
hv_poll_channel(vss_transaction.recv_channel,
vss_poll_wrapper);
}
} else {
pr_warn("VSS: Transaction not active\n");
return -EINVAL;
}
return 0;
}
static void vss_send_op(void)
{
int op = vss_transaction.msg->vss_hdr.operation;
int rc;
struct hv_vss_msg *vss_msg;
if (vss_transaction.state != HVUTIL_HOSTMSG_RECEIVED)
return;
vss_msg = kzalloc(sizeof(*vss_msg), GFP_KERNEL);
if (!vss_msg)
return;
vss_msg->vss_hdr.operation = op;
vss_transaction.state = HVUTIL_USERSPACE_REQ;
schedule_delayed_work(&vss_timeout_work, VSS_USERSPACE_TIMEOUT);
rc = hvutil_transport_send(hvt, vss_msg, sizeof(*vss_msg), NULL);
if (rc) {
pr_warn("VSS: failed to communicate to the daemon: %d\n", rc);
if (cancel_delayed_work_sync(&vss_timeout_work)) {
vss_respond_to_host(HV_E_FAIL);
vss_transaction.state = HVUTIL_READY;
}
}
kfree(vss_msg);
return;
}
static void vss_handle_request(struct work_struct *dummy)
{
switch (vss_transaction.msg->vss_hdr.operation) {
case VSS_OP_THAW:
case VSS_OP_FREEZE:
case VSS_OP_HOT_BACKUP:
if (vss_transaction.state < HVUTIL_READY) {
vss_respond_to_host(HV_E_FAIL);
return;
}
vss_transaction.state = HVUTIL_HOSTMSG_RECEIVED;
vss_send_op();
return;
case VSS_OP_GET_DM_INFO:
vss_transaction.msg->dm_info.flags = 0;
break;
default:
break;
}
vss_respond_to_host(0);
hv_poll_channel(vss_transaction.recv_channel, vss_poll_wrapper);
}
static void
vss_respond_to_host(int error)
{
struct icmsg_hdr *icmsghdrp;
u32 buf_len;
struct vmbus_channel *channel;
u64 req_id;
buf_len = vss_transaction.recv_len;
channel = vss_transaction.recv_channel;
req_id = vss_transaction.recv_req_id;
icmsghdrp = (struct icmsg_hdr *)
&recv_buffer[sizeof(struct vmbuspipe_hdr)];
if (channel->onchannel_callback == NULL)
return;
icmsghdrp->status = error;
icmsghdrp->icflags = ICMSGHDRFLAG_TRANSACTION | ICMSGHDRFLAG_RESPONSE;
vmbus_sendpacket(channel, recv_buffer, buf_len, req_id,
VM_PKT_DATA_INBAND, 0);
}
void hv_vss_onchannelcallback(void *context)
{
struct vmbus_channel *channel = context;
u32 recvlen;
u64 requestid;
struct hv_vss_msg *vss_msg;
struct icmsg_hdr *icmsghdrp;
struct icmsg_negotiate *negop = NULL;
if (vss_transaction.state > HVUTIL_READY)
return;
vmbus_recvpacket(channel, recv_buffer, PAGE_SIZE * 2, &recvlen,
&requestid);
if (recvlen > 0) {
icmsghdrp = (struct icmsg_hdr *)&recv_buffer[
sizeof(struct vmbuspipe_hdr)];
if (icmsghdrp->icmsgtype == ICMSGTYPE_NEGOTIATE) {
vmbus_prep_negotiate_resp(icmsghdrp, negop,
recv_buffer, UTIL_FW_VERSION,
VSS_VERSION);
} else {
vss_msg = (struct hv_vss_msg *)&recv_buffer[
sizeof(struct vmbuspipe_hdr) +
sizeof(struct icmsg_hdr)];
vss_transaction.recv_len = recvlen;
vss_transaction.recv_req_id = requestid;
vss_transaction.msg = (struct hv_vss_msg *)vss_msg;
schedule_work(&vss_handle_request_work);
return;
}
icmsghdrp->icflags = ICMSGHDRFLAG_TRANSACTION
| ICMSGHDRFLAG_RESPONSE;
vmbus_sendpacket(channel, recv_buffer,
recvlen, requestid,
VM_PKT_DATA_INBAND, 0);
}
}
static void vss_on_reset(void)
{
if (cancel_delayed_work_sync(&vss_timeout_work))
vss_respond_to_host(HV_E_FAIL);
vss_transaction.state = HVUTIL_DEVICE_INIT;
}
int
hv_vss_init(struct hv_util_service *srv)
{
if (vmbus_proto_version < VERSION_WIN8_1) {
pr_warn("Integration service 'Backup (volume snapshot)'"
" not supported on this host version.\n");
return -ENOTSUPP;
}
recv_buffer = srv->recv_buffer;
vss_transaction.recv_channel = srv->channel;
vss_transaction.state = HVUTIL_DEVICE_INIT;
hvt = hvutil_transport_init(vss_devname, CN_VSS_IDX, CN_VSS_VAL,
vss_on_msg, vss_on_reset);
if (!hvt)
return -EFAULT;
return 0;
}
void hv_vss_deinit(void)
{
vss_transaction.state = HVUTIL_DEVICE_DYING;
cancel_delayed_work_sync(&vss_timeout_work);
cancel_work_sync(&vss_handle_request_work);
hvutil_transport_destroy(hvt);
}
