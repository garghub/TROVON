static void fcopy_work_func(struct work_struct *dummy)
{
fcopy_respond_to_host(HV_E_FAIL);
}
static int fcopy_handle_handshake(u32 version)
{
switch (version) {
case FCOPY_CURRENT_VERSION:
break;
default:
return -EINVAL;
}
pr_info("FCP: user-mode registering done. Daemon version: %d\n",
version);
fcopy_transaction.active = false;
if (fcopy_transaction.fcopy_context)
hv_fcopy_onchannelcallback(fcopy_transaction.fcopy_context);
in_hand_shake = false;
return 0;
}
static void fcopy_send_data(void)
{
struct hv_start_fcopy *smsg_out = &fcopy_transaction.message;
int operation = fcopy_transaction.fcopy_msg->operation;
struct hv_start_fcopy *smsg_in;
switch (operation) {
case START_FILE_COPY:
memset(smsg_out, 0, sizeof(struct hv_start_fcopy));
smsg_out->hdr.operation = operation;
smsg_in = (struct hv_start_fcopy *)fcopy_transaction.fcopy_msg;
utf16s_to_utf8s((wchar_t *)smsg_in->file_name, W_MAX_PATH,
UTF16_LITTLE_ENDIAN,
(__u8 *)smsg_out->file_name, W_MAX_PATH - 1);
utf16s_to_utf8s((wchar_t *)smsg_in->path_name, W_MAX_PATH,
UTF16_LITTLE_ENDIAN,
(__u8 *)smsg_out->path_name, W_MAX_PATH - 1);
smsg_out->copy_flags = smsg_in->copy_flags;
smsg_out->file_size = smsg_in->file_size;
break;
default:
break;
}
up(&fcopy_transaction.read_sema);
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
fcopy_transaction.active = false;
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
if (fcopy_transaction.active) {
fcopy_transaction.fcopy_context = context;
return;
}
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
fcopy_transaction.active = true;
fcopy_transaction.recv_len = recvlen;
fcopy_transaction.recv_channel = channel;
fcopy_transaction.recv_req_id = requestid;
fcopy_transaction.fcopy_msg = fcopy_msg;
schedule_delayed_work(&fcopy_work, 5*HZ);
fcopy_send_data();
return;
}
icmsghdr->icflags = ICMSGHDRFLAG_TRANSACTION | ICMSGHDRFLAG_RESPONSE;
vmbus_sendpacket(channel, recv_buffer, recvlen, requestid,
VM_PKT_DATA_INBAND, 0);
}
static ssize_t fcopy_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
void *src;
size_t copy_size;
int operation;
if (down_interruptible(&fcopy_transaction.read_sema))
return -EINTR;
if (!opened)
return -ENODEV;
operation = fcopy_transaction.fcopy_msg->operation;
if (operation == START_FILE_COPY) {
src = &fcopy_transaction.message;
copy_size = sizeof(struct hv_start_fcopy);
if (count < copy_size)
return 0;
} else {
src = fcopy_transaction.fcopy_msg;
copy_size = sizeof(struct hv_do_fcopy);
if (count < copy_size)
return 0;
}
if (copy_to_user(buf, src, copy_size))
return -EFAULT;
return copy_size;
}
static ssize_t fcopy_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
int response = 0;
if (count != sizeof(int))
return -EINVAL;
if (copy_from_user(&response, buf, sizeof(int)))
return -EFAULT;
if (in_hand_shake) {
if (fcopy_handle_handshake(response))
return -EINVAL;
return sizeof(int);
}
if (cancel_delayed_work_sync(&fcopy_work))
fcopy_respond_to_host(response);
return sizeof(int);
}
static int fcopy_open(struct inode *inode, struct file *f)
{
if (opened)
return -EBUSY;
opened = true;
return 0;
}
static int fcopy_release(struct inode *inode, struct file *f)
{
in_hand_shake = true;
opened = false;
return 0;
}
static int fcopy_dev_init(void)
{
return misc_register(&fcopy_misc);
}
static void fcopy_dev_deinit(void)
{
opened = false;
up(&fcopy_transaction.read_sema);
misc_deregister(&fcopy_misc);
}
int hv_fcopy_init(struct hv_util_service *srv)
{
recv_buffer = srv->recv_buffer;
fcopy_transaction.active = true;
sema_init(&fcopy_transaction.read_sema, 0);
return fcopy_dev_init();
}
void hv_fcopy_deinit(void)
{
cancel_delayed_work_sync(&fcopy_work);
fcopy_dev_deinit();
}
