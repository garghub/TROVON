static int vmw_open_channel(struct rpc_channel *channel, unsigned int protocol)
{
unsigned long eax, ebx, ecx, edx, si = 0, di = 0;
VMW_PORT(VMW_PORT_CMD_OPEN_CHANNEL,
(protocol | GUESTMSG_FLAG_COOKIE), si, di,
VMW_HYPERVISOR_PORT,
VMW_HYPERVISOR_MAGIC,
eax, ebx, ecx, edx, si, di);
if ((HIGH_WORD(ecx) & MESSAGE_STATUS_SUCCESS) == 0)
return -EINVAL;
channel->channel_id = HIGH_WORD(edx);
channel->cookie_high = si;
channel->cookie_low = di;
return 0;
}
static int vmw_close_channel(struct rpc_channel *channel)
{
unsigned long eax, ebx, ecx, edx, si, di;
si = channel->cookie_high;
di = channel->cookie_low;
VMW_PORT(VMW_PORT_CMD_CLOSE_CHANNEL,
0, si, di,
(VMW_HYPERVISOR_PORT | (channel->channel_id << 16)),
VMW_HYPERVISOR_MAGIC,
eax, ebx, ecx, edx, si, di);
if ((HIGH_WORD(ecx) & MESSAGE_STATUS_SUCCESS) == 0)
return -EINVAL;
return 0;
}
static int vmw_send_msg(struct rpc_channel *channel, const char *msg)
{
unsigned long eax, ebx, ecx, edx, si, di, bp;
size_t msg_len = strlen(msg);
int retries = 0;
while (retries < RETRIES) {
retries++;
si = channel->cookie_high;
di = channel->cookie_low;
VMW_PORT(VMW_PORT_CMD_SENDSIZE,
msg_len, si, di,
VMW_HYPERVISOR_PORT | (channel->channel_id << 16),
VMW_HYPERVISOR_MAGIC,
eax, ebx, ecx, edx, si, di);
if ((HIGH_WORD(ecx) & MESSAGE_STATUS_SUCCESS) == 0 ||
(HIGH_WORD(ecx) & MESSAGE_STATUS_HB) == 0) {
return -EINVAL;
}
si = (uintptr_t) msg;
di = channel->cookie_low;
bp = channel->cookie_high;
VMW_PORT_HB_OUT(
(MESSAGE_STATUS_SUCCESS << 16) | VMW_PORT_CMD_HB_MSG,
msg_len, si, di,
VMW_HYPERVISOR_HB_PORT | (channel->channel_id << 16),
VMW_HYPERVISOR_MAGIC, bp,
eax, ebx, ecx, edx, si, di);
if ((HIGH_WORD(ebx) & MESSAGE_STATUS_SUCCESS) != 0) {
return 0;
} else if ((HIGH_WORD(ebx) & MESSAGE_STATUS_CPT) != 0) {
continue;
} else {
break;
}
}
return -EINVAL;
}
static int vmw_recv_msg(struct rpc_channel *channel, void **msg,
size_t *msg_len)
{
unsigned long eax, ebx, ecx, edx, si, di, bp;
char *reply;
size_t reply_len;
int retries = 0;
*msg_len = 0;
*msg = NULL;
while (retries < RETRIES) {
retries++;
si = channel->cookie_high;
di = channel->cookie_low;
VMW_PORT(VMW_PORT_CMD_RECVSIZE,
0, si, di,
(VMW_HYPERVISOR_PORT | (channel->channel_id << 16)),
VMW_HYPERVISOR_MAGIC,
eax, ebx, ecx, edx, si, di);
if ((HIGH_WORD(ecx) & MESSAGE_STATUS_SUCCESS) == 0 ||
(HIGH_WORD(ecx) & MESSAGE_STATUS_HB) == 0) {
DRM_ERROR("Failed to get reply size\n");
return -EINVAL;
}
if ((HIGH_WORD(ecx) & MESSAGE_STATUS_DORECV) == 0)
return 0;
reply_len = ebx;
reply = kzalloc(reply_len + 1, GFP_KERNEL);
if (!reply) {
DRM_ERROR("Cannot allocate memory for reply\n");
return -ENOMEM;
}
si = channel->cookie_high;
di = (uintptr_t) reply;
bp = channel->cookie_low;
VMW_PORT_HB_IN(
(MESSAGE_STATUS_SUCCESS << 16) | VMW_PORT_CMD_HB_MSG,
reply_len, si, di,
VMW_HYPERVISOR_HB_PORT | (channel->channel_id << 16),
VMW_HYPERVISOR_MAGIC, bp,
eax, ebx, ecx, edx, si, di);
if ((HIGH_WORD(ebx) & MESSAGE_STATUS_SUCCESS) == 0) {
kfree(reply);
if ((HIGH_WORD(ebx) & MESSAGE_STATUS_CPT) != 0) {
continue;
}
return -EINVAL;
}
reply[reply_len] = '\0';
si = channel->cookie_high;
di = channel->cookie_low;
VMW_PORT(VMW_PORT_CMD_RECVSTATUS,
MESSAGE_STATUS_SUCCESS, si, di,
(VMW_HYPERVISOR_PORT | (channel->channel_id << 16)),
VMW_HYPERVISOR_MAGIC,
eax, ebx, ecx, edx, si, di);
if ((HIGH_WORD(ecx) & MESSAGE_STATUS_SUCCESS) == 0) {
kfree(reply);
if ((HIGH_WORD(ecx) & MESSAGE_STATUS_CPT) != 0) {
continue;
}
return -EINVAL;
}
break;
}
if (retries == RETRIES)
return -EINVAL;
*msg_len = reply_len;
*msg = reply;
return 0;
}
int vmw_host_get_guestinfo(const char *guest_info_param,
char *buffer, size_t *length)
{
struct rpc_channel channel;
char *msg, *reply = NULL;
size_t msg_len, reply_len = 0;
int ret = 0;
if (!vmw_msg_enabled)
return -ENODEV;
if (!guest_info_param || !length)
return -EINVAL;
msg_len = strlen(guest_info_param) + strlen("info-get ") + 1;
msg = kzalloc(msg_len, GFP_KERNEL);
if (!msg) {
DRM_ERROR("Cannot allocate memory to get %s", guest_info_param);
return -ENOMEM;
}
sprintf(msg, "info-get %s", guest_info_param);
if (vmw_open_channel(&channel, RPCI_PROTOCOL_NUM) ||
vmw_send_msg(&channel, msg) ||
vmw_recv_msg(&channel, (void *) &reply, &reply_len) ||
vmw_close_channel(&channel)) {
DRM_ERROR("Failed to get %s", guest_info_param);
ret = -EINVAL;
}
if (buffer && reply && reply_len > 0) {
reply_len = max(reply_len - 2, (size_t) 0);
reply_len = min(reply_len, *length);
if (reply_len > 0)
memcpy(buffer, reply + 2, reply_len);
}
*length = reply_len;
kfree(reply);
kfree(msg);
return ret;
}
int vmw_host_log(const char *log)
{
struct rpc_channel channel;
char *msg;
int msg_len;
int ret = 0;
if (!vmw_msg_enabled)
return -ENODEV;
if (!log)
return ret;
msg_len = strlen(log) + strlen("log ") + 1;
msg = kzalloc(msg_len, GFP_KERNEL);
if (!msg) {
DRM_ERROR("Cannot allocate memory for log message\n");
return -ENOMEM;
}
sprintf(msg, "log %s", log);
if (vmw_open_channel(&channel, RPCI_PROTOCOL_NUM) ||
vmw_send_msg(&channel, msg) ||
vmw_close_channel(&channel)) {
DRM_ERROR("Failed to send log\n");
ret = -EINVAL;
}
kfree(msg);
return ret;
}
