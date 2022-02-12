static void
kvp_register(void)
{
struct cn_msg *msg;
msg = kzalloc(sizeof(*msg) + strlen(HV_DRV_VERSION) + 1 , GFP_ATOMIC);
if (msg) {
msg->id.idx = CN_KVP_IDX;
msg->id.val = CN_KVP_VAL;
msg->seq = KVP_REGISTER;
strcpy(msg->data, HV_DRV_VERSION);
msg->len = strlen(HV_DRV_VERSION) + 1;
cn_netlink_send(msg, 0, GFP_ATOMIC);
kfree(msg);
}
}
static void
kvp_work_func(struct work_struct *dummy)
{
kvp_respond_to_host("Unknown key", "Guest timed out", TIMEOUT_FIRED);
}
static void
kvp_cn_callback(struct cn_msg *msg, struct netlink_skb_parms *nsp)
{
struct hv_ku_msg *message;
message = (struct hv_ku_msg *)msg->data;
if (msg->seq == KVP_REGISTER) {
pr_info("KVP: user-mode registering done.\n");
kvp_register();
}
if (msg->seq == KVP_USER_SET) {
if (cancel_delayed_work_sync(&kvp_work))
kvp_respond_to_host(message->kvp_key,
message->kvp_value,
!strlen(message->kvp_key));
}
}
static void
kvp_send_key(struct work_struct *dummy)
{
struct cn_msg *msg;
int index = kvp_transaction.index;
msg = kzalloc(sizeof(*msg) + sizeof(struct hv_kvp_msg) , GFP_ATOMIC);
if (msg) {
msg->id.idx = CN_KVP_IDX;
msg->id.val = CN_KVP_VAL;
msg->seq = KVP_KERNEL_GET;
((struct hv_ku_msg *)msg->data)->kvp_index = index;
msg->len = sizeof(struct hv_ku_msg);
cn_netlink_send(msg, 0, GFP_ATOMIC);
kfree(msg);
}
return;
}
static void
kvp_respond_to_host(char *key, char *value, int error)
{
struct hv_kvp_msg *kvp_msg;
struct hv_kvp_msg_enumerate *kvp_data;
char *key_name;
struct icmsg_hdr *icmsghdrp;
int keylen, valuelen;
u32 buf_len;
struct vmbus_channel *channel;
u64 req_id;
if (!kvp_transaction.active) {
pr_warn("KVP: Transaction not active\n");
return;
}
buf_len = kvp_transaction.recv_len;
channel = kvp_transaction.recv_channel;
req_id = kvp_transaction.recv_req_id;
kvp_transaction.active = false;
if (channel->onchannel_callback == NULL)
return;
icmsghdrp = (struct icmsg_hdr *)
&recv_buffer[sizeof(struct vmbuspipe_hdr)];
kvp_msg = (struct hv_kvp_msg *)
&recv_buffer[sizeof(struct vmbuspipe_hdr) +
sizeof(struct icmsg_hdr)];
kvp_data = &kvp_msg->kvp_data;
key_name = key;
if (error) {
icmsghdrp->status = HV_E_FAIL;
goto response_done;
}
keylen = utf8s_to_utf16s(key_name, strlen(key_name), UTF16_HOST_ENDIAN,
(wchar_t *) kvp_data->data.key,
HV_KVP_EXCHANGE_MAX_KEY_SIZE / 2);
kvp_data->data.key_size = 2*(keylen + 1);
valuelen = utf8s_to_utf16s(value, strlen(value), UTF16_HOST_ENDIAN,
(wchar_t *) kvp_data->data.value,
HV_KVP_EXCHANGE_MAX_VALUE_SIZE / 2);
kvp_data->data.value_size = 2*(valuelen + 1);
kvp_data->data.value_type = REG_SZ;
icmsghdrp->status = HV_S_OK;
response_done:
icmsghdrp->icflags = ICMSGHDRFLAG_TRANSACTION | ICMSGHDRFLAG_RESPONSE;
vmbus_sendpacket(channel, recv_buffer, buf_len, req_id,
VM_PKT_DATA_INBAND, 0);
}
void hv_kvp_onchannelcallback(void *context)
{
struct vmbus_channel *channel = context;
u32 recvlen;
u64 requestid;
struct hv_kvp_msg *kvp_msg;
struct hv_kvp_msg_enumerate *kvp_data;
struct icmsg_hdr *icmsghdrp;
struct icmsg_negotiate *negop = NULL;
vmbus_recvpacket(channel, recv_buffer, PAGE_SIZE, &recvlen, &requestid);
if (recvlen > 0) {
icmsghdrp = (struct icmsg_hdr *)&recv_buffer[
sizeof(struct vmbuspipe_hdr)];
if (icmsghdrp->icmsgtype == ICMSGTYPE_NEGOTIATE) {
vmbus_prep_negotiate_resp(icmsghdrp, negop, recv_buffer);
} else {
kvp_msg = (struct hv_kvp_msg *)&recv_buffer[
sizeof(struct vmbuspipe_hdr) +
sizeof(struct icmsg_hdr)];
kvp_data = &kvp_msg->kvp_data;
if ((kvp_msg->kvp_hdr.pool != KVP_POOL_AUTO) ||
(kvp_msg->kvp_hdr.operation !=
KVP_OP_ENUMERATE)) {
icmsghdrp->status = HV_E_FAIL;
goto callback_done;
}
kvp_transaction.recv_len = recvlen;
kvp_transaction.recv_channel = channel;
kvp_transaction.recv_req_id = requestid;
kvp_transaction.active = true;
kvp_transaction.index = kvp_data->index;
schedule_work(&kvp_sendkey_work);
schedule_delayed_work(&kvp_work, 5*HZ);
return;
}
callback_done:
icmsghdrp->icflags = ICMSGHDRFLAG_TRANSACTION
| ICMSGHDRFLAG_RESPONSE;
vmbus_sendpacket(channel, recv_buffer,
recvlen, requestid,
VM_PKT_DATA_INBAND, 0);
}
}
int
hv_kvp_init(struct hv_util_service *srv)
{
int err;
err = cn_add_callback(&kvp_id, kvp_name, kvp_cn_callback);
if (err)
return err;
recv_buffer = srv->recv_buffer;
return 0;
}
void hv_kvp_deinit(void)
{
cn_del_callback(&kvp_id);
cancel_delayed_work_sync(&kvp_work);
cancel_work_sync(&kvp_sendkey_work);
}
