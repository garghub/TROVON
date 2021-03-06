static void
kvp_register(void)
{
struct cn_msg *msg;
struct hv_kvp_msg *kvp_msg;
char *version;
msg = kzalloc(sizeof(*msg) + sizeof(struct hv_kvp_msg), GFP_ATOMIC);
if (msg) {
kvp_msg = (struct hv_kvp_msg *)msg->data;
version = kvp_msg->body.kvp_register.version;
msg->id.idx = CN_KVP_IDX;
msg->id.val = CN_KVP_VAL;
kvp_msg->kvp_hdr.operation = KVP_OP_REGISTER;
strcpy(version, HV_DRV_VERSION);
msg->len = sizeof(struct hv_kvp_msg);
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
struct hv_kvp_msg *message;
struct hv_kvp_msg_enumerate *data;
message = (struct hv_kvp_msg *)msg->data;
switch (message->kvp_hdr.operation) {
case KVP_OP_REGISTER:
pr_info("KVP: user-mode registering done.\n");
kvp_register();
kvp_transaction.active = false;
hv_kvp_onchannelcallback(kvp_transaction.kvp_context);
break;
default:
data = &message->body.kvp_enum_data;
if (cancel_delayed_work_sync(&kvp_work))
kvp_respond_to_host(data->data.key,
data->data.value,
!strlen(data->data.key));
}
}
static void
kvp_send_key(struct work_struct *dummy)
{
struct cn_msg *msg;
struct hv_kvp_msg *message;
struct hv_kvp_msg *in_msg;
__u8 operation = kvp_transaction.kvp_msg->kvp_hdr.operation;
__u8 pool = kvp_transaction.kvp_msg->kvp_hdr.pool;
__u32 val32;
__u64 val64;
msg = kzalloc(sizeof(*msg) + sizeof(struct hv_kvp_msg) , GFP_ATOMIC);
if (!msg)
return;
msg->id.idx = CN_KVP_IDX;
msg->id.val = CN_KVP_VAL;
message = (struct hv_kvp_msg *)msg->data;
message->kvp_hdr.operation = operation;
message->kvp_hdr.pool = pool;
in_msg = kvp_transaction.kvp_msg;
switch (message->kvp_hdr.operation) {
case KVP_OP_SET:
switch (in_msg->body.kvp_set.data.value_type) {
case REG_SZ:
message->body.kvp_set.data.value_size =
utf16s_to_utf8s(
(wchar_t *)in_msg->body.kvp_set.data.value,
in_msg->body.kvp_set.data.value_size,
UTF16_LITTLE_ENDIAN,
message->body.kvp_set.data.value,
HV_KVP_EXCHANGE_MAX_VALUE_SIZE - 1) + 1;
break;
case REG_U32:
val32 = in_msg->body.kvp_set.data.value_u32;
message->body.kvp_set.data.value_size =
sprintf(message->body.kvp_set.data.value,
"%d", val32) + 1;
break;
case REG_U64:
val64 = in_msg->body.kvp_set.data.value_u64;
message->body.kvp_set.data.value_size =
sprintf(message->body.kvp_set.data.value,
"%llu", val64) + 1;
break;
}
case KVP_OP_GET:
message->body.kvp_set.data.key_size =
utf16s_to_utf8s(
(wchar_t *)in_msg->body.kvp_set.data.key,
in_msg->body.kvp_set.data.key_size,
UTF16_LITTLE_ENDIAN,
message->body.kvp_set.data.key,
HV_KVP_EXCHANGE_MAX_KEY_SIZE - 1) + 1;
break;
case KVP_OP_DELETE:
message->body.kvp_delete.key_size =
utf16s_to_utf8s(
(wchar_t *)in_msg->body.kvp_delete.key,
in_msg->body.kvp_delete.key_size,
UTF16_LITTLE_ENDIAN,
message->body.kvp_delete.key,
HV_KVP_EXCHANGE_MAX_KEY_SIZE - 1) + 1;
break;
case KVP_OP_ENUMERATE:
message->body.kvp_enum_data.index =
in_msg->body.kvp_enum_data.index;
break;
}
msg->len = sizeof(struct hv_kvp_msg);
cn_netlink_send(msg, 0, GFP_ATOMIC);
kfree(msg);
return;
}
static void
kvp_respond_to_host(char *key, char *value, int error)
{
struct hv_kvp_msg *kvp_msg;
struct hv_kvp_exchg_msg_value *kvp_data;
char *key_name;
struct icmsg_hdr *icmsghdrp;
int keylen = 0;
int valuelen = 0;
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
icmsghdrp = (struct icmsg_hdr *)
&recv_buffer[sizeof(struct vmbuspipe_hdr)];
if (channel->onchannel_callback == NULL)
return;
if (error) {
icmsghdrp->status = HV_S_CONT;
goto response_done;
}
icmsghdrp->status = HV_S_OK;
kvp_msg = (struct hv_kvp_msg *)
&recv_buffer[sizeof(struct vmbuspipe_hdr) +
sizeof(struct icmsg_hdr)];
switch (kvp_transaction.kvp_msg->kvp_hdr.operation) {
case KVP_OP_GET:
kvp_data = &kvp_msg->body.kvp_get.data;
goto copy_value;
case KVP_OP_SET:
case KVP_OP_DELETE:
goto response_done;
default:
break;
}
kvp_data = &kvp_msg->body.kvp_enum_data.data;
key_name = key;
keylen = utf8s_to_utf16s(key_name, strlen(key_name), UTF16_HOST_ENDIAN,
(wchar_t *) kvp_data->key,
(HV_KVP_EXCHANGE_MAX_KEY_SIZE / 2) - 2);
kvp_data->key_size = 2*(keylen + 1);
copy_value:
valuelen = utf8s_to_utf16s(value, strlen(value), UTF16_HOST_ENDIAN,
(wchar_t *) kvp_data->value,
(HV_KVP_EXCHANGE_MAX_VALUE_SIZE / 2) - 2);
kvp_data->value_size = 2*(valuelen + 1);
if ((keylen < 0) || (valuelen < 0))
icmsghdrp->status = HV_E_FAIL;
kvp_data->value_type = REG_SZ;
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
struct icmsg_hdr *icmsghdrp;
struct icmsg_negotiate *negop = NULL;
if (kvp_transaction.active) {
kvp_transaction.kvp_context = context;
return;
}
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
kvp_transaction.recv_len = recvlen;
kvp_transaction.recv_channel = channel;
kvp_transaction.recv_req_id = requestid;
kvp_transaction.active = true;
kvp_transaction.kvp_msg = kvp_msg;
schedule_work(&kvp_sendkey_work);
schedule_delayed_work(&kvp_work, 5*HZ);
return;
}
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
kvp_transaction.active = true;
return 0;
}
void hv_kvp_deinit(void)
{
cn_del_callback(&kvp_id);
cancel_delayed_work_sync(&kvp_work);
cancel_work_sync(&kvp_sendkey_work);
}
