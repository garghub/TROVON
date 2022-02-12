static void
vss_cn_callback(struct cn_msg *msg, struct netlink_skb_parms *nsp)
{
struct hv_vss_msg *vss_msg;
vss_msg = (struct hv_vss_msg *)msg->data;
if (vss_msg->vss_hdr.operation == VSS_OP_REGISTER) {
pr_info("VSS daemon registered\n");
vss_transaction.active = false;
if (vss_transaction.recv_channel != NULL)
hv_vss_onchannelcallback(vss_transaction.recv_channel);
return;
}
vss_respond_to_host(vss_msg->error);
}
static void vss_send_op(struct work_struct *dummy)
{
int op = vss_transaction.msg->vss_hdr.operation;
struct cn_msg *msg;
struct hv_vss_msg *vss_msg;
msg = kzalloc(sizeof(*msg) + sizeof(*vss_msg), GFP_ATOMIC);
if (!msg)
return;
vss_msg = (struct hv_vss_msg *)msg->data;
msg->id.idx = CN_VSS_IDX;
msg->id.val = CN_VSS_VAL;
vss_msg->vss_hdr.operation = op;
msg->len = sizeof(struct hv_vss_msg);
cn_netlink_send(msg, 0, GFP_ATOMIC);
kfree(msg);
return;
}
static void
vss_respond_to_host(int error)
{
struct icmsg_hdr *icmsghdrp;
u32 buf_len;
struct vmbus_channel *channel;
u64 req_id;
if (!vss_transaction.active) {
pr_warn("VSS: Transaction not active\n");
return;
}
buf_len = vss_transaction.recv_len;
channel = vss_transaction.recv_channel;
req_id = vss_transaction.recv_req_id;
vss_transaction.active = false;
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
if (vss_transaction.active) {
vss_transaction.recv_channel = channel;
return;
}
vmbus_recvpacket(channel, recv_buffer, PAGE_SIZE * 2, &recvlen,
&requestid);
if (recvlen > 0) {
icmsghdrp = (struct icmsg_hdr *)&recv_buffer[
sizeof(struct vmbuspipe_hdr)];
if (icmsghdrp->icmsgtype == ICMSGTYPE_NEGOTIATE) {
vmbus_prep_negotiate_resp(icmsghdrp, negop,
recv_buffer, MAX_SRV_VER, MAX_SRV_VER);
negop = (struct icmsg_negotiate *)&recv_buffer[
sizeof(struct vmbuspipe_hdr) +
sizeof(struct icmsg_hdr)];
if (negop->icversion_data[1].major < 5)
negop->icframe_vercnt = 0;
} else {
vss_msg = (struct hv_vss_msg *)&recv_buffer[
sizeof(struct vmbuspipe_hdr) +
sizeof(struct icmsg_hdr)];
vss_transaction.recv_len = recvlen;
vss_transaction.recv_channel = channel;
vss_transaction.recv_req_id = requestid;
vss_transaction.active = true;
vss_transaction.msg = (struct hv_vss_msg *)vss_msg;
switch (vss_msg->vss_hdr.operation) {
case VSS_OP_FREEZE:
case VSS_OP_THAW:
schedule_work(&vss_send_op_work);
return;
case VSS_OP_HOT_BACKUP:
vss_msg->vss_cf.flags =
VSS_HBU_NO_AUTO_RECOVERY;
vss_respond_to_host(0);
return;
case VSS_OP_GET_DM_INFO:
vss_msg->dm_info.flags = 0;
vss_respond_to_host(0);
return;
default:
vss_respond_to_host(0);
return;
}
}
icmsghdrp->icflags = ICMSGHDRFLAG_TRANSACTION
| ICMSGHDRFLAG_RESPONSE;
vmbus_sendpacket(channel, recv_buffer,
recvlen, requestid,
VM_PKT_DATA_INBAND, 0);
}
}
int
hv_vss_init(struct hv_util_service *srv)
{
int err;
err = cn_add_callback(&vss_id, vss_name, vss_cn_callback);
if (err)
return err;
recv_buffer = srv->recv_buffer;
vss_transaction.active = true;
return 0;
}
void hv_vss_deinit(void)
{
cn_del_callback(&vss_id);
cancel_work_sync(&vss_send_op_work);
}
