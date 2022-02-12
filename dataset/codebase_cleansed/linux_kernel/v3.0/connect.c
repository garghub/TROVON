static int
cifs_reconnect(struct TCP_Server_Info *server)
{
int rc = 0;
struct list_head *tmp, *tmp2;
struct cifs_ses *ses;
struct cifs_tcon *tcon;
struct mid_q_entry *mid_entry;
struct list_head retry_list;
spin_lock(&GlobalMid_Lock);
if (server->tcpStatus == CifsExiting) {
spin_unlock(&GlobalMid_Lock);
return rc;
} else
server->tcpStatus = CifsNeedReconnect;
spin_unlock(&GlobalMid_Lock);
server->maxBuf = 0;
cFYI(1, "Reconnecting tcp session");
cFYI(1, "%s: marking sessions and tcons for reconnect", __func__);
spin_lock(&cifs_tcp_ses_lock);
list_for_each(tmp, &server->smb_ses_list) {
ses = list_entry(tmp, struct cifs_ses, smb_ses_list);
ses->need_reconnect = true;
ses->ipc_tid = 0;
list_for_each(tmp2, &ses->tcon_list) {
tcon = list_entry(tmp2, struct cifs_tcon, tcon_list);
tcon->need_reconnect = true;
}
}
spin_unlock(&cifs_tcp_ses_lock);
cFYI(1, "%s: tearing down socket", __func__);
mutex_lock(&server->srv_mutex);
if (server->ssocket) {
cFYI(1, "State: 0x%x Flags: 0x%lx", server->ssocket->state,
server->ssocket->flags);
kernel_sock_shutdown(server->ssocket, SHUT_WR);
cFYI(1, "Post shutdown state: 0x%x Flags: 0x%lx",
server->ssocket->state,
server->ssocket->flags);
sock_release(server->ssocket);
server->ssocket = NULL;
}
server->sequence_number = 0;
server->session_estab = false;
kfree(server->session_key.response);
server->session_key.response = NULL;
server->session_key.len = 0;
server->lstrp = jiffies;
mutex_unlock(&server->srv_mutex);
INIT_LIST_HEAD(&retry_list);
cFYI(1, "%s: moving mids to private list", __func__);
spin_lock(&GlobalMid_Lock);
list_for_each_safe(tmp, tmp2, &server->pending_mid_q) {
mid_entry = list_entry(tmp, struct mid_q_entry, qhead);
if (mid_entry->midState == MID_REQUEST_SUBMITTED)
mid_entry->midState = MID_RETRY_NEEDED;
list_move(&mid_entry->qhead, &retry_list);
}
spin_unlock(&GlobalMid_Lock);
cFYI(1, "%s: issuing mid callbacks", __func__);
list_for_each_safe(tmp, tmp2, &retry_list) {
mid_entry = list_entry(tmp, struct mid_q_entry, qhead);
list_del_init(&mid_entry->qhead);
mid_entry->callback(mid_entry);
}
do {
try_to_freeze();
rc = generic_ip_connect(server);
if (rc) {
cFYI(1, "reconnect error %d", rc);
msleep(3000);
} else {
atomic_inc(&tcpSesReconnectCount);
spin_lock(&GlobalMid_Lock);
if (server->tcpStatus != CifsExiting)
server->tcpStatus = CifsNeedNegotiate;
spin_unlock(&GlobalMid_Lock);
}
} while (server->tcpStatus == CifsNeedReconnect);
return rc;
}
static int check2ndT2(struct smb_hdr *pSMB, unsigned int maxBufSize)
{
struct smb_t2_rsp *pSMBt;
int remaining;
__u16 total_data_size, data_in_this_rsp;
if (pSMB->Command != SMB_COM_TRANSACTION2)
return 0;
if (pSMB->WordCount != 10) {
cFYI(1, "invalid transact2 word count");
return -EINVAL;
}
pSMBt = (struct smb_t2_rsp *)pSMB;
total_data_size = get_unaligned_le16(&pSMBt->t2_rsp.TotalDataCount);
data_in_this_rsp = get_unaligned_le16(&pSMBt->t2_rsp.DataCount);
if (total_data_size == data_in_this_rsp)
return 0;
else if (total_data_size < data_in_this_rsp) {
cFYI(1, "total data %d smaller than data in frame %d",
total_data_size, data_in_this_rsp);
return -EINVAL;
}
remaining = total_data_size - data_in_this_rsp;
cFYI(1, "missing %d bytes from transact2, check next response",
remaining);
if (total_data_size > maxBufSize) {
cERROR(1, "TotalDataSize %d is over maximum buffer %d",
total_data_size, maxBufSize);
return -EINVAL;
}
return remaining;
}
static int coalesce_t2(struct smb_hdr *psecond, struct smb_hdr *pTargetSMB)
{
struct smb_t2_rsp *pSMB2 = (struct smb_t2_rsp *)psecond;
struct smb_t2_rsp *pSMBt = (struct smb_t2_rsp *)pTargetSMB;
char *data_area_of_target;
char *data_area_of_buf2;
int remaining;
unsigned int byte_count, total_in_buf;
__u16 total_data_size, total_in_buf2;
total_data_size = get_unaligned_le16(&pSMBt->t2_rsp.TotalDataCount);
if (total_data_size !=
get_unaligned_le16(&pSMB2->t2_rsp.TotalDataCount))
cFYI(1, "total data size of primary and secondary t2 differ");
total_in_buf = get_unaligned_le16(&pSMBt->t2_rsp.DataCount);
remaining = total_data_size - total_in_buf;
if (remaining < 0)
return -EPROTO;
if (remaining == 0)
return 0;
total_in_buf2 = get_unaligned_le16(&pSMB2->t2_rsp.DataCount);
if (remaining < total_in_buf2) {
cFYI(1, "transact2 2nd response contains too much data");
}
data_area_of_target = (char *)&pSMBt->hdr.Protocol +
get_unaligned_le16(&pSMBt->t2_rsp.DataOffset);
data_area_of_buf2 = (char *)&pSMB2->hdr.Protocol +
get_unaligned_le16(&pSMB2->t2_rsp.DataOffset);
data_area_of_target += total_in_buf;
total_in_buf += total_in_buf2;
if (total_in_buf > USHRT_MAX)
return -EPROTO;
put_unaligned_le16(total_in_buf, &pSMBt->t2_rsp.DataCount);
byte_count = get_bcc(pTargetSMB);
byte_count += total_in_buf2;
if (byte_count > USHRT_MAX)
return -EPROTO;
put_bcc(byte_count, pTargetSMB);
byte_count = be32_to_cpu(pTargetSMB->smb_buf_length);
byte_count += total_in_buf2;
if (byte_count > CIFSMaxBufSize)
return -ENOBUFS;
pTargetSMB->smb_buf_length = cpu_to_be32(byte_count);
memcpy(data_area_of_target, data_area_of_buf2, total_in_buf2);
if (remaining == total_in_buf2) {
cFYI(1, "found the last secondary response");
return 0;
} else
return 1;
}
static void
cifs_echo_request(struct work_struct *work)
{
int rc;
struct TCP_Server_Info *server = container_of(work,
struct TCP_Server_Info, echo.work);
if (server->maxBuf == 0 ||
time_before(jiffies, server->lstrp + SMB_ECHO_INTERVAL - HZ))
goto requeue_echo;
rc = CIFSSMBEcho(server);
if (rc)
cFYI(1, "Unable to send echo request to server: %s",
server->hostname);
requeue_echo:
queue_delayed_work(system_nrt_wq, &server->echo, SMB_ECHO_INTERVAL);
}
static int
cifs_demultiplex_thread(struct TCP_Server_Info *server)
{
int length;
unsigned int pdu_length, total_read;
struct smb_hdr *smb_buffer = NULL;
struct smb_hdr *bigbuf = NULL;
struct smb_hdr *smallbuf = NULL;
struct msghdr smb_msg;
struct kvec iov;
struct socket *csocket = server->ssocket;
struct list_head *tmp, *tmp2;
struct task_struct *task_to_wake = NULL;
struct mid_q_entry *mid_entry;
char temp;
bool isLargeBuf = false;
bool isMultiRsp;
int reconnect;
current->flags |= PF_MEMALLOC;
cFYI(1, "Demultiplex PID: %d", task_pid_nr(current));
length = atomic_inc_return(&tcpSesAllocCount);
if (length > 1)
mempool_resize(cifs_req_poolp, length + cifs_min_rcv,
GFP_KERNEL);
set_freezable();
while (server->tcpStatus != CifsExiting) {
if (try_to_freeze())
continue;
if (bigbuf == NULL) {
bigbuf = cifs_buf_get();
if (!bigbuf) {
cERROR(1, "No memory for large SMB response");
msleep(3000);
continue;
}
} else if (isLargeBuf) {
memset(bigbuf, 0, sizeof(struct smb_hdr));
}
if (smallbuf == NULL) {
smallbuf = cifs_small_buf_get();
if (!smallbuf) {
cERROR(1, "No memory for SMB response");
msleep(1000);
continue;
}
} else
memset(smallbuf, 0, sizeof(struct smb_hdr));
isLargeBuf = false;
isMultiRsp = false;
smb_buffer = smallbuf;
iov.iov_base = smb_buffer;
iov.iov_len = 4;
smb_msg.msg_control = NULL;
smb_msg.msg_controllen = 0;
pdu_length = 4;
incomplete_rcv:
if (echo_retries > 0 && server->tcpStatus == CifsGood &&
time_after(jiffies, server->lstrp +
(echo_retries * SMB_ECHO_INTERVAL))) {
cERROR(1, "Server %s has not responded in %d seconds. "
"Reconnecting...", server->hostname,
(echo_retries * SMB_ECHO_INTERVAL / HZ));
cifs_reconnect(server);
csocket = server->ssocket;
wake_up(&server->response_q);
continue;
}
length =
kernel_recvmsg(csocket, &smb_msg,
&iov, 1, pdu_length, 0 );
if (server->tcpStatus == CifsExiting) {
break;
} else if (server->tcpStatus == CifsNeedReconnect) {
cFYI(1, "Reconnect after server stopped responding");
cifs_reconnect(server);
cFYI(1, "call to reconnect done");
csocket = server->ssocket;
continue;
} else if (length == -ERESTARTSYS ||
length == -EAGAIN ||
length == -EINTR) {
msleep(1);
if (pdu_length < 4) {
iov.iov_base = (4 - pdu_length) +
(char *)smb_buffer;
iov.iov_len = pdu_length;
smb_msg.msg_control = NULL;
smb_msg.msg_controllen = 0;
goto incomplete_rcv;
} else
continue;
} else if (length <= 0) {
cFYI(1, "Reconnect after unexpected peek error %d",
length);
cifs_reconnect(server);
csocket = server->ssocket;
wake_up(&server->response_q);
continue;
} else if (length < pdu_length) {
cFYI(1, "requested %d bytes but only got %d bytes",
pdu_length, length);
pdu_length -= length;
msleep(1);
goto incomplete_rcv;
}
temp = *((char *) smb_buffer);
pdu_length = be32_to_cpu(smb_buffer->smb_buf_length);
cFYI(1, "rfc1002 length 0x%x", pdu_length+4);
if (temp == (char) RFC1002_SESSION_KEEP_ALIVE) {
continue;
} else if (temp == (char)RFC1002_POSITIVE_SESSION_RESPONSE) {
cFYI(1, "Good RFC 1002 session rsp");
continue;
} else if (temp == (char)RFC1002_NEGATIVE_SESSION_RESPONSE) {
cFYI(1, "Negative RFC1002 Session Response Error 0x%x)",
pdu_length);
msleep(1000);
cifs_set_port((struct sockaddr *)
&server->dstaddr, CIFS_PORT);
cifs_reconnect(server);
csocket = server->ssocket;
wake_up(&server->response_q);
continue;
} else if (temp != (char) 0) {
cERROR(1, "Unknown RFC 1002 frame");
cifs_dump_mem(" Received Data: ", (char *)smb_buffer,
length);
cifs_reconnect(server);
csocket = server->ssocket;
continue;
}
if ((pdu_length > CIFSMaxBufSize + MAX_CIFS_HDR_SIZE - 4) ||
(pdu_length < sizeof(struct smb_hdr) - 1 - 4)) {
cERROR(1, "Invalid size SMB length %d pdu_length %d",
length, pdu_length+4);
cifs_reconnect(server);
csocket = server->ssocket;
wake_up(&server->response_q);
continue;
}
reconnect = 0;
if (pdu_length > MAX_CIFS_SMALL_BUFFER_SIZE - 4) {
isLargeBuf = true;
memcpy(bigbuf, smallbuf, 4);
smb_buffer = bigbuf;
}
length = 0;
iov.iov_base = 4 + (char *)smb_buffer;
iov.iov_len = pdu_length;
for (total_read = 0; total_read < pdu_length;
total_read += length) {
length = kernel_recvmsg(csocket, &smb_msg, &iov, 1,
pdu_length - total_read, 0);
if (server->tcpStatus == CifsExiting) {
reconnect = 2;
break;
} else if (server->tcpStatus == CifsNeedReconnect) {
cifs_reconnect(server);
csocket = server->ssocket;
reconnect = 1;
break;
} else if (length == -ERESTARTSYS ||
length == -EAGAIN ||
length == -EINTR) {
msleep(1);
length = 0;
continue;
} else if (length <= 0) {
cERROR(1, "Received no data, expecting %d",
pdu_length - total_read);
cifs_reconnect(server);
csocket = server->ssocket;
reconnect = 1;
break;
}
}
if (reconnect == 2)
break;
else if (reconnect == 1)
continue;
total_read += 4;
dump_smb(smb_buffer, total_read);
length = checkSMB(smb_buffer, smb_buffer->Mid, total_read);
if (length != 0)
cifs_dump_mem("Bad SMB: ", smb_buffer,
min_t(unsigned int, total_read, 48));
mid_entry = NULL;
server->lstrp = jiffies;
spin_lock(&GlobalMid_Lock);
list_for_each_safe(tmp, tmp2, &server->pending_mid_q) {
mid_entry = list_entry(tmp, struct mid_q_entry, qhead);
if (mid_entry->mid != smb_buffer->Mid ||
mid_entry->midState != MID_REQUEST_SUBMITTED ||
mid_entry->command != smb_buffer->Command) {
mid_entry = NULL;
continue;
}
if (length == 0 &&
check2ndT2(smb_buffer, server->maxBuf) > 0) {
isMultiRsp = true;
if (mid_entry->resp_buf) {
length = coalesce_t2(smb_buffer,
mid_entry->resp_buf);
if (length > 0) {
length = 0;
mid_entry->multiRsp = true;
break;
} else {
mid_entry->multiEnd = true;
goto multi_t2_fnd;
}
} else {
if (!isLargeBuf) {
cERROR(1, "1st trans2 resp "
"needs bigbuf");
} else {
mid_entry->resp_buf =
smb_buffer;
mid_entry->largeBuf = true;
bigbuf = NULL;
}
}
break;
}
mid_entry->resp_buf = smb_buffer;
mid_entry->largeBuf = isLargeBuf;
multi_t2_fnd:
if (length == 0)
mid_entry->midState = MID_RESPONSE_RECEIVED;
else
mid_entry->midState = MID_RESPONSE_MALFORMED;
#ifdef CONFIG_CIFS_STATS2
mid_entry->when_received = jiffies;
#endif
list_del_init(&mid_entry->qhead);
break;
}
spin_unlock(&GlobalMid_Lock);
if (mid_entry != NULL) {
mid_entry->callback(mid_entry);
if (!isMultiRsp) {
if (isLargeBuf)
bigbuf = NULL;
else
smallbuf = NULL;
}
} else if (length != 0) {
continue;
} else if (!is_valid_oplock_break(smb_buffer, server) &&
!isMultiRsp) {
cERROR(1, "No task to wake, unknown frame received! "
"NumMids %d", atomic_read(&midCount));
cifs_dump_mem("Received Data is: ", (char *)smb_buffer,
sizeof(struct smb_hdr));
#ifdef CONFIG_CIFS_DEBUG2
cifs_dump_detail(smb_buffer);
cifs_dump_mids(server);
#endif
}
}
spin_lock(&cifs_tcp_ses_lock);
list_del_init(&server->tcp_ses_list);
spin_unlock(&cifs_tcp_ses_lock);
spin_lock(&GlobalMid_Lock);
server->tcpStatus = CifsExiting;
spin_unlock(&GlobalMid_Lock);
wake_up_all(&server->response_q);
spin_lock(&GlobalMid_Lock);
if (atomic_read(&server->inFlight) >= cifs_max_pending)
atomic_set(&server->inFlight, cifs_max_pending - 1);
spin_unlock(&GlobalMid_Lock);
wake_up_all(&server->request_q);
msleep(125);
if (server->ssocket) {
sock_release(csocket);
server->ssocket = NULL;
}
cifs_buf_release(bigbuf);
if (smallbuf)
cifs_small_buf_release(smallbuf);
if (!list_empty(&server->pending_mid_q)) {
struct list_head dispose_list;
INIT_LIST_HEAD(&dispose_list);
spin_lock(&GlobalMid_Lock);
list_for_each_safe(tmp, tmp2, &server->pending_mid_q) {
mid_entry = list_entry(tmp, struct mid_q_entry, qhead);
cFYI(1, "Clearing mid 0x%x", mid_entry->mid);
mid_entry->midState = MID_SHUTDOWN;
list_move(&mid_entry->qhead, &dispose_list);
}
spin_unlock(&GlobalMid_Lock);
list_for_each_safe(tmp, tmp2, &dispose_list) {
mid_entry = list_entry(tmp, struct mid_q_entry, qhead);
cFYI(1, "Callback mid 0x%x", mid_entry->mid);
list_del_init(&mid_entry->qhead);
mid_entry->callback(mid_entry);
}
msleep(125);
}
if (!list_empty(&server->pending_mid_q)) {
cFYI(1, "Wait for exit from demultiplex thread");
msleep(46000);
}
kfree(server->hostname);
task_to_wake = xchg(&server->tsk, NULL);
kfree(server);
length = atomic_dec_return(&tcpSesAllocCount);
if (length > 0)
mempool_resize(cifs_req_poolp, length + cifs_min_rcv,
GFP_KERNEL);
if (!task_to_wake) {
set_current_state(TASK_INTERRUPTIBLE);
while (!signal_pending(current)) {
schedule();
set_current_state(TASK_INTERRUPTIBLE);
}
set_current_state(TASK_RUNNING);
}
module_put_and_exit(0);
}
static char *
extract_hostname(const char *unc)
{
const char *src;
char *dst, *delim;
unsigned int len;
src = unc + 2;
delim = strchr(src, '\\');
if (!delim)
return ERR_PTR(-EINVAL);
len = delim - src;
dst = kmalloc((len + 1), GFP_KERNEL);
if (dst == NULL)
return ERR_PTR(-ENOMEM);
memcpy(dst, src, len);
dst[len] = '\0';
return dst;
}
static int
cifs_parse_mount_options(const char *mountdata, const char *devname,
struct smb_vol *vol)
{
char *value, *data, *end;
char *mountdata_copy = NULL, *options;
unsigned int temp_len, i, j;
char separator[2];
short int override_uid = -1;
short int override_gid = -1;
bool uid_specified = false;
bool gid_specified = false;
char *nodename = utsname()->nodename;
separator[0] = ',';
separator[1] = 0;
memset(vol->source_rfc1001_name, 0x20, RFC1001_NAME_LEN);
for (i = 0; i < strnlen(nodename, RFC1001_NAME_LEN); i++)
vol->source_rfc1001_name[i] = toupper(nodename[i]);
vol->source_rfc1001_name[RFC1001_NAME_LEN] = 0;
vol->target_rfc1001_name[0] = 0;
vol->cred_uid = current_uid();
vol->linux_uid = current_uid();
vol->linux_gid = current_gid();
vol->dir_mode = vol->file_mode = S_IRUGO | S_IXUGO | S_IWUSR;
vol->posix_paths = 1;
vol->server_ino = 1;
vol->actimeo = CIFS_DEF_ACTIMEO;
if (!mountdata)
goto cifs_parse_mount_err;
mountdata_copy = kstrndup(mountdata, PAGE_SIZE, GFP_KERNEL);
if (!mountdata_copy)
goto cifs_parse_mount_err;
options = mountdata_copy;
end = options + strlen(options);
if (strncmp(options, "sep=", 4) == 0) {
if (options[4] != 0) {
separator[0] = options[4];
options += 5;
} else {
cFYI(1, "Null separator not allowed");
}
}
while ((data = strsep(&options, separator)) != NULL) {
if (!*data)
continue;
if ((value = strchr(data, '=')) != NULL)
*value++ = '\0';
if (strnicmp(data, "user_xattr", 10) == 0) {
vol->no_xattr = 0;
} else if (strnicmp(data, "nouser_xattr", 12) == 0) {
vol->no_xattr = 1;
} else if (strnicmp(data, "user", 4) == 0) {
if (!value) {
printk(KERN_WARNING
"CIFS: invalid or missing username\n");
goto cifs_parse_mount_err;
} else if (!*value) {
vol->nullauth = 1;
}
if (strnlen(value, MAX_USERNAME_SIZE) <
MAX_USERNAME_SIZE) {
vol->username = kstrdup(value, GFP_KERNEL);
if (!vol->username) {
printk(KERN_WARNING "CIFS: no memory "
"for username\n");
goto cifs_parse_mount_err;
}
} else {
printk(KERN_WARNING "CIFS: username too long\n");
goto cifs_parse_mount_err;
}
} else if (strnicmp(data, "pass", 4) == 0) {
if (!value) {
vol->password = NULL;
continue;
} else if (value[0] == 0) {
if (value[1] != separator[0]) {
vol->password = NULL;
continue;
}
}
temp_len = strlen(value);
if ((value[temp_len] == 0) &&
(value + temp_len < end) &&
(value[temp_len+1] == separator[0])) {
value[temp_len] = separator[0];
temp_len += 2;
while (value[temp_len] != 0) {
if (value[temp_len] == separator[0]) {
if (value[temp_len+1] ==
separator[0]) {
temp_len++;
} else {
break;
}
}
temp_len++;
}
if (value[temp_len] == 0) {
options = NULL;
} else {
value[temp_len] = 0;
options = value + temp_len + 1;
}
vol->password = kzalloc(temp_len, GFP_KERNEL);
if (vol->password == NULL) {
printk(KERN_WARNING "CIFS: no memory "
"for password\n");
goto cifs_parse_mount_err;
}
for (i = 0, j = 0; i < temp_len; i++, j++) {
vol->password[j] = value[i];
if (value[i] == separator[0]
&& value[i+1] == separator[0]) {
i++;
}
}
vol->password[j] = 0;
} else {
vol->password = kzalloc(temp_len+1, GFP_KERNEL);
if (vol->password == NULL) {
printk(KERN_WARNING "CIFS: no memory "
"for password\n");
goto cifs_parse_mount_err;
}
strcpy(vol->password, value);
}
} else if (!strnicmp(data, "ip", 2) ||
!strnicmp(data, "addr", 4)) {
if (!value || !*value) {
vol->UNCip = NULL;
} else if (strnlen(value, INET6_ADDRSTRLEN) <
INET6_ADDRSTRLEN) {
vol->UNCip = kstrdup(value, GFP_KERNEL);
if (!vol->UNCip) {
printk(KERN_WARNING "CIFS: no memory "
"for UNC IP\n");
goto cifs_parse_mount_err;
}
} else {
printk(KERN_WARNING "CIFS: ip address "
"too long\n");
goto cifs_parse_mount_err;
}
} else if (strnicmp(data, "sec", 3) == 0) {
if (!value || !*value) {
cERROR(1, "no security value specified");
continue;
} else if (strnicmp(value, "krb5i", 5) == 0) {
vol->secFlg |= CIFSSEC_MAY_KRB5 |
CIFSSEC_MUST_SIGN;
} else if (strnicmp(value, "krb5p", 5) == 0) {
cERROR(1, "Krb5 cifs privacy not supported");
goto cifs_parse_mount_err;
} else if (strnicmp(value, "krb5", 4) == 0) {
vol->secFlg |= CIFSSEC_MAY_KRB5;
} else if (strnicmp(value, "ntlmsspi", 8) == 0) {
vol->secFlg |= CIFSSEC_MAY_NTLMSSP |
CIFSSEC_MUST_SIGN;
} else if (strnicmp(value, "ntlmssp", 7) == 0) {
vol->secFlg |= CIFSSEC_MAY_NTLMSSP;
} else if (strnicmp(value, "ntlmv2i", 7) == 0) {
vol->secFlg |= CIFSSEC_MAY_NTLMV2 |
CIFSSEC_MUST_SIGN;
} else if (strnicmp(value, "ntlmv2", 6) == 0) {
vol->secFlg |= CIFSSEC_MAY_NTLMV2;
} else if (strnicmp(value, "ntlmi", 5) == 0) {
vol->secFlg |= CIFSSEC_MAY_NTLM |
CIFSSEC_MUST_SIGN;
} else if (strnicmp(value, "ntlm", 4) == 0) {
vol->secFlg |= CIFSSEC_MAY_NTLM;
} else if (strnicmp(value, "nontlm", 6) == 0) {
vol->secFlg |= CIFSSEC_MAY_NTLMV2;
#ifdef CONFIG_CIFS_WEAK_PW_HASH
} else if (strnicmp(value, "lanman", 6) == 0) {
vol->secFlg |= CIFSSEC_MAY_LANMAN;
#endif
} else if (strnicmp(value, "none", 4) == 0) {
vol->nullauth = 1;
} else {
cERROR(1, "bad security option: %s", value);
goto cifs_parse_mount_err;
}
} else if (strnicmp(data, "vers", 3) == 0) {
if (!value || !*value) {
cERROR(1, "no protocol version specified"
" after vers= mount option");
} else if ((strnicmp(value, "cifs", 4) == 0) ||
(strnicmp(value, "1", 1) == 0)) {
continue;
}
} else if ((strnicmp(data, "unc", 3) == 0)
|| (strnicmp(data, "target", 6) == 0)
|| (strnicmp(data, "path", 4) == 0)) {
if (!value || !*value) {
printk(KERN_WARNING "CIFS: invalid path to "
"network resource\n");
goto cifs_parse_mount_err;
}
if ((temp_len = strnlen(value, 300)) < 300) {
vol->UNC = kmalloc(temp_len+1, GFP_KERNEL);
if (vol->UNC == NULL)
goto cifs_parse_mount_err;
strcpy(vol->UNC, value);
if (strncmp(vol->UNC, "//", 2) == 0) {
vol->UNC[0] = '\\';
vol->UNC[1] = '\\';
} else if (strncmp(vol->UNC, "\\\\", 2) != 0) {
printk(KERN_WARNING
"CIFS: UNC Path does not begin "
"with // or \\\\ \n");
goto cifs_parse_mount_err;
}
} else {
printk(KERN_WARNING "CIFS: UNC name too long\n");
goto cifs_parse_mount_err;
}
} else if ((strnicmp(data, "domain", 3) == 0)
|| (strnicmp(data, "workgroup", 5) == 0)) {
if (!value || !*value) {
printk(KERN_WARNING "CIFS: invalid domain name\n");
goto cifs_parse_mount_err;
}
if (strnlen(value, 256) < 256) {
vol->domainname = kstrdup(value, GFP_KERNEL);
if (!vol->domainname) {
printk(KERN_WARNING "CIFS: no memory "
"for domainname\n");
goto cifs_parse_mount_err;
}
cFYI(1, "Domain name set");
} else {
printk(KERN_WARNING "CIFS: domain name too "
"long\n");
goto cifs_parse_mount_err;
}
} else if (strnicmp(data, "srcaddr", 7) == 0) {
vol->srcaddr.ss_family = AF_UNSPEC;
if (!value || !*value) {
printk(KERN_WARNING "CIFS: srcaddr value"
" not specified.\n");
goto cifs_parse_mount_err;
}
i = cifs_convert_address((struct sockaddr *)&vol->srcaddr,
value, strlen(value));
if (i == 0) {
printk(KERN_WARNING "CIFS: Could not parse"
" srcaddr: %s\n",
value);
goto cifs_parse_mount_err;
}
} else if (strnicmp(data, "prefixpath", 10) == 0) {
if (!value || !*value) {
printk(KERN_WARNING
"CIFS: invalid path prefix\n");
goto cifs_parse_mount_err;
}
if ((temp_len = strnlen(value, 1024)) < 1024) {
if (value[0] != '/')
temp_len++;
vol->prepath = kmalloc(temp_len+1, GFP_KERNEL);
if (vol->prepath == NULL)
goto cifs_parse_mount_err;
if (value[0] != '/') {
vol->prepath[0] = '/';
strcpy(vol->prepath+1, value);
} else
strcpy(vol->prepath, value);
cFYI(1, "prefix path %s", vol->prepath);
} else {
printk(KERN_WARNING "CIFS: prefix too long\n");
goto cifs_parse_mount_err;
}
} else if (strnicmp(data, "iocharset", 9) == 0) {
if (!value || !*value) {
printk(KERN_WARNING "CIFS: invalid iocharset "
"specified\n");
goto cifs_parse_mount_err;
}
if (strnlen(value, 65) < 65) {
if (strnicmp(value, "default", 7)) {
vol->iocharset = kstrdup(value,
GFP_KERNEL);
if (!vol->iocharset) {
printk(KERN_WARNING "CIFS: no "
"memory for"
"charset\n");
goto cifs_parse_mount_err;
}
}
cFYI(1, "iocharset set to %s", value);
} else {
printk(KERN_WARNING "CIFS: iocharset name "
"too long.\n");
goto cifs_parse_mount_err;
}
} else if (!strnicmp(data, "uid", 3) && value && *value) {
vol->linux_uid = simple_strtoul(value, &value, 0);
uid_specified = true;
} else if (!strnicmp(data, "cruid", 5) && value && *value) {
vol->cred_uid = simple_strtoul(value, &value, 0);
} else if (!strnicmp(data, "forceuid", 8)) {
override_uid = 1;
} else if (!strnicmp(data, "noforceuid", 10)) {
override_uid = 0;
} else if (!strnicmp(data, "gid", 3) && value && *value) {
vol->linux_gid = simple_strtoul(value, &value, 0);
gid_specified = true;
} else if (!strnicmp(data, "forcegid", 8)) {
override_gid = 1;
} else if (!strnicmp(data, "noforcegid", 10)) {
override_gid = 0;
} else if (strnicmp(data, "file_mode", 4) == 0) {
if (value && *value) {
vol->file_mode =
simple_strtoul(value, &value, 0);
}
} else if (strnicmp(data, "dir_mode", 4) == 0) {
if (value && *value) {
vol->dir_mode =
simple_strtoul(value, &value, 0);
}
} else if (strnicmp(data, "dirmode", 4) == 0) {
if (value && *value) {
vol->dir_mode =
simple_strtoul(value, &value, 0);
}
} else if (strnicmp(data, "port", 4) == 0) {
if (value && *value) {
vol->port =
simple_strtoul(value, &value, 0);
}
} else if (strnicmp(data, "rsize", 5) == 0) {
if (value && *value) {
vol->rsize =
simple_strtoul(value, &value, 0);
}
} else if (strnicmp(data, "wsize", 5) == 0) {
if (value && *value) {
vol->wsize =
simple_strtoul(value, &value, 0);
}
} else if (strnicmp(data, "sockopt", 5) == 0) {
if (!value || !*value) {
cERROR(1, "no socket option specified");
continue;
} else if (strnicmp(value, "TCP_NODELAY", 11) == 0) {
vol->sockopt_tcp_nodelay = 1;
}
} else if (strnicmp(data, "netbiosname", 4) == 0) {
if (!value || !*value || (*value == ' ')) {
cFYI(1, "invalid (empty) netbiosname");
} else {
memset(vol->source_rfc1001_name, 0x20,
RFC1001_NAME_LEN);
for (i = 0; i < RFC1001_NAME_LEN; i++) {
if (value[i] == 0)
break;
vol->source_rfc1001_name[i] = value[i];
}
if (i == RFC1001_NAME_LEN && value[i] != 0)
printk(KERN_WARNING "CIFS: netbiosname"
" longer than 15 truncated.\n");
}
} else if (strnicmp(data, "servern", 7) == 0) {
if (!value || !*value || (*value == ' ')) {
cFYI(1, "empty server netbiosname specified");
} else {
memset(vol->target_rfc1001_name, 0x20,
RFC1001_NAME_LEN_WITH_NULL);
for (i = 0; i < 15; i++) {
if (value[i] == 0)
break;
else
vol->target_rfc1001_name[i] =
value[i];
}
if (i == RFC1001_NAME_LEN && value[i] != 0)
printk(KERN_WARNING "CIFS: server net"
"biosname longer than 15 truncated.\n");
}
} else if (strnicmp(data, "actimeo", 7) == 0) {
if (value && *value) {
vol->actimeo = HZ * simple_strtoul(value,
&value, 0);
if (vol->actimeo > CIFS_MAX_ACTIMEO) {
cERROR(1, "CIFS: attribute cache"
"timeout too large");
goto cifs_parse_mount_err;
}
}
} else if (strnicmp(data, "credentials", 4) == 0) {
} else if (strnicmp(data, "version", 3) == 0) {
} else if (strnicmp(data, "guest", 5) == 0) {
} else if (strnicmp(data, "rw", 2) == 0) {
} else if (strnicmp(data, "ro", 2) == 0) {
} else if (strnicmp(data, "noblocksend", 11) == 0) {
vol->noblocksnd = 1;
} else if (strnicmp(data, "noautotune", 10) == 0) {
vol->noautotune = 1;
} else if ((strnicmp(data, "suid", 4) == 0) ||
(strnicmp(data, "nosuid", 6) == 0) ||
(strnicmp(data, "exec", 4) == 0) ||
(strnicmp(data, "noexec", 6) == 0) ||
(strnicmp(data, "nodev", 5) == 0) ||
(strnicmp(data, "noauto", 6) == 0) ||
(strnicmp(data, "dev", 3) == 0)) {
continue;
} else if (strnicmp(data, "hard", 4) == 0) {
vol->retry = 1;
} else if (strnicmp(data, "soft", 4) == 0) {
vol->retry = 0;
} else if (strnicmp(data, "perm", 4) == 0) {
vol->noperm = 0;
} else if (strnicmp(data, "noperm", 6) == 0) {
vol->noperm = 1;
} else if (strnicmp(data, "mapchars", 8) == 0) {
vol->remap = 1;
} else if (strnicmp(data, "nomapchars", 10) == 0) {
vol->remap = 0;
} else if (strnicmp(data, "sfu", 3) == 0) {
vol->sfu_emul = 1;
} else if (strnicmp(data, "nosfu", 5) == 0) {
vol->sfu_emul = 0;
} else if (strnicmp(data, "nodfs", 5) == 0) {
vol->nodfs = 1;
} else if (strnicmp(data, "posixpaths", 10) == 0) {
vol->posix_paths = 1;
} else if (strnicmp(data, "noposixpaths", 12) == 0) {
vol->posix_paths = 0;
} else if (strnicmp(data, "nounix", 6) == 0) {
vol->no_linux_ext = 1;
} else if (strnicmp(data, "nolinux", 7) == 0) {
vol->no_linux_ext = 1;
} else if ((strnicmp(data, "nocase", 6) == 0) ||
(strnicmp(data, "ignorecase", 10) == 0)) {
vol->nocase = 1;
} else if (strnicmp(data, "mand", 4) == 0) {
} else if (strnicmp(data, "nomand", 6) == 0) {
} else if (strnicmp(data, "_netdev", 7) == 0) {
} else if (strnicmp(data, "brl", 3) == 0) {
vol->nobrl = 0;
} else if ((strnicmp(data, "nobrl", 5) == 0) ||
(strnicmp(data, "nolock", 6) == 0)) {
vol->nobrl = 1;
if (vol->file_mode ==
(S_IALLUGO & ~(S_ISUID | S_IXGRP)))
vol->file_mode = S_IALLUGO;
} else if (strnicmp(data, "forcemandatorylock", 9) == 0) {
vol->mand_lock = 1;
} else if (strnicmp(data, "setuids", 7) == 0) {
vol->setuids = 1;
} else if (strnicmp(data, "nosetuids", 9) == 0) {
vol->setuids = 0;
} else if (strnicmp(data, "dynperm", 7) == 0) {
vol->dynperm = true;
} else if (strnicmp(data, "nodynperm", 9) == 0) {
vol->dynperm = false;
} else if (strnicmp(data, "nohard", 6) == 0) {
vol->retry = 0;
} else if (strnicmp(data, "nosoft", 6) == 0) {
vol->retry = 1;
} else if (strnicmp(data, "nointr", 6) == 0) {
vol->intr = 0;
} else if (strnicmp(data, "intr", 4) == 0) {
vol->intr = 1;
} else if (strnicmp(data, "nostrictsync", 12) == 0) {
vol->nostrictsync = 1;
} else if (strnicmp(data, "strictsync", 10) == 0) {
vol->nostrictsync = 0;
} else if (strnicmp(data, "serverino", 7) == 0) {
vol->server_ino = 1;
} else if (strnicmp(data, "noserverino", 9) == 0) {
vol->server_ino = 0;
} else if (strnicmp(data, "rwpidforward", 4) == 0) {
vol->rwpidforward = 1;
} else if (strnicmp(data, "cifsacl", 7) == 0) {
vol->cifs_acl = 1;
} else if (strnicmp(data, "nocifsacl", 9) == 0) {
vol->cifs_acl = 0;
} else if (strnicmp(data, "acl", 3) == 0) {
vol->no_psx_acl = 0;
} else if (strnicmp(data, "noacl", 5) == 0) {
vol->no_psx_acl = 1;
} else if (strnicmp(data, "locallease", 6) == 0) {
vol->local_lease = 1;
} else if (strnicmp(data, "sign", 4) == 0) {
vol->secFlg |= CIFSSEC_MUST_SIGN;
} else if (strnicmp(data, "seal", 4) == 0) {
vol->seal = 1;
} else if (strnicmp(data, "direct", 6) == 0) {
vol->direct_io = 1;
} else if (strnicmp(data, "forcedirectio", 13) == 0) {
vol->direct_io = 1;
} else if (strnicmp(data, "strictcache", 11) == 0) {
vol->strict_io = 1;
} else if (strnicmp(data, "noac", 4) == 0) {
printk(KERN_WARNING "CIFS: Mount option noac not "
"supported. Instead set "
"/proc/fs/cifs/LookupCacheEnabled to 0\n");
} else if (strnicmp(data, "fsc", 3) == 0) {
#ifndef CONFIG_CIFS_FSCACHE
cERROR(1, "FS-Cache support needs CONFIG_CIFS_FSCACHE "
"kernel config option set");
goto cifs_parse_mount_err;
#endif
vol->fsc = true;
} else if (strnicmp(data, "mfsymlinks", 10) == 0) {
vol->mfsymlinks = true;
} else if (strnicmp(data, "multiuser", 8) == 0) {
vol->multiuser = true;
} else
printk(KERN_WARNING "CIFS: Unknown mount option %s\n",
data);
}
if (vol->UNC == NULL) {
if (devname == NULL) {
printk(KERN_WARNING "CIFS: Missing UNC name for mount "
"target\n");
goto cifs_parse_mount_err;
}
if ((temp_len = strnlen(devname, 300)) < 300) {
vol->UNC = kmalloc(temp_len+1, GFP_KERNEL);
if (vol->UNC == NULL)
goto cifs_parse_mount_err;
strcpy(vol->UNC, devname);
if (strncmp(vol->UNC, "//", 2) == 0) {
vol->UNC[0] = '\\';
vol->UNC[1] = '\\';
} else if (strncmp(vol->UNC, "\\\\", 2) != 0) {
printk(KERN_WARNING "CIFS: UNC Path does not "
"begin with // or \\\\ \n");
goto cifs_parse_mount_err;
}
value = strpbrk(vol->UNC+2, "/\\");
if (value)
*value = '\\';
} else {
printk(KERN_WARNING "CIFS: UNC name too long\n");
goto cifs_parse_mount_err;
}
}
if (vol->multiuser && !(vol->secFlg & CIFSSEC_MAY_KRB5)) {
cERROR(1, "Multiuser mounts currently require krb5 "
"authentication!");
goto cifs_parse_mount_err;
}
if (vol->UNCip == NULL)
vol->UNCip = &vol->UNC[2];
if (uid_specified)
vol->override_uid = override_uid;
else if (override_uid == 1)
printk(KERN_NOTICE "CIFS: ignoring forceuid mount option "
"specified with no uid= option.\n");
if (gid_specified)
vol->override_gid = override_gid;
else if (override_gid == 1)
printk(KERN_NOTICE "CIFS: ignoring forcegid mount option "
"specified with no gid= option.\n");
kfree(mountdata_copy);
return 0;
cifs_parse_mount_err:
kfree(mountdata_copy);
return 1;
}
static bool
srcip_matches(struct sockaddr *srcaddr, struct sockaddr *rhs)
{
switch (srcaddr->sa_family) {
case AF_UNSPEC:
return (rhs->sa_family == AF_UNSPEC);
case AF_INET: {
struct sockaddr_in *saddr4 = (struct sockaddr_in *)srcaddr;
struct sockaddr_in *vaddr4 = (struct sockaddr_in *)rhs;
return (saddr4->sin_addr.s_addr == vaddr4->sin_addr.s_addr);
}
case AF_INET6: {
struct sockaddr_in6 *saddr6 = (struct sockaddr_in6 *)srcaddr;
struct sockaddr_in6 *vaddr6 = (struct sockaddr_in6 *)&rhs;
return ipv6_addr_equal(&saddr6->sin6_addr, &vaddr6->sin6_addr);
}
default:
WARN_ON(1);
return false;
}
}
static bool
match_port(struct TCP_Server_Info *server, struct sockaddr *addr)
{
__be16 port, *sport;
switch (addr->sa_family) {
case AF_INET:
sport = &((struct sockaddr_in *) &server->dstaddr)->sin_port;
port = ((struct sockaddr_in *) addr)->sin_port;
break;
case AF_INET6:
sport = &((struct sockaddr_in6 *) &server->dstaddr)->sin6_port;
port = ((struct sockaddr_in6 *) addr)->sin6_port;
break;
default:
WARN_ON(1);
return false;
}
if (!port) {
port = htons(CIFS_PORT);
if (port == *sport)
return true;
port = htons(RFC1001_PORT);
}
return port == *sport;
}
static bool
match_address(struct TCP_Server_Info *server, struct sockaddr *addr,
struct sockaddr *srcaddr)
{
switch (addr->sa_family) {
case AF_INET: {
struct sockaddr_in *addr4 = (struct sockaddr_in *)addr;
struct sockaddr_in *srv_addr4 =
(struct sockaddr_in *)&server->dstaddr;
if (addr4->sin_addr.s_addr != srv_addr4->sin_addr.s_addr)
return false;
break;
}
case AF_INET6: {
struct sockaddr_in6 *addr6 = (struct sockaddr_in6 *)addr;
struct sockaddr_in6 *srv_addr6 =
(struct sockaddr_in6 *)&server->dstaddr;
if (!ipv6_addr_equal(&addr6->sin6_addr,
&srv_addr6->sin6_addr))
return false;
if (addr6->sin6_scope_id != srv_addr6->sin6_scope_id)
return false;
break;
}
default:
WARN_ON(1);
return false;
}
if (!srcip_matches(srcaddr, (struct sockaddr *)&server->srcaddr))
return false;
return true;
}
static bool
match_security(struct TCP_Server_Info *server, struct smb_vol *vol)
{
unsigned int secFlags;
if (vol->secFlg & (~(CIFSSEC_MUST_SIGN | CIFSSEC_MUST_SEAL)))
secFlags = vol->secFlg;
else
secFlags = global_secflags | vol->secFlg;
switch (server->secType) {
case LANMAN:
if (!(secFlags & (CIFSSEC_MAY_LANMAN|CIFSSEC_MAY_PLNTXT)))
return false;
break;
case NTLMv2:
if (!(secFlags & CIFSSEC_MAY_NTLMV2))
return false;
break;
case NTLM:
if (!(secFlags & CIFSSEC_MAY_NTLM))
return false;
break;
case Kerberos:
if (!(secFlags & CIFSSEC_MAY_KRB5))
return false;
break;
case RawNTLMSSP:
if (!(secFlags & CIFSSEC_MAY_NTLMSSP))
return false;
break;
default:
return false;
}
if ((secFlags & CIFSSEC_MAY_SIGN) == 0 &&
(server->sec_mode & SECMODE_SIGN_REQUIRED))
return false;
else if (((secFlags & CIFSSEC_MUST_SIGN) == CIFSSEC_MUST_SIGN) &&
(server->sec_mode &
(SECMODE_SIGN_ENABLED|SECMODE_SIGN_REQUIRED)) == 0)
return false;
return true;
}
static int match_server(struct TCP_Server_Info *server, struct sockaddr *addr,
struct smb_vol *vol)
{
if (!net_eq(cifs_net_ns(server), current->nsproxy->net_ns))
return 0;
if (!match_address(server, addr,
(struct sockaddr *)&vol->srcaddr))
return 0;
if (!match_port(server, addr))
return 0;
if (!match_security(server, vol))
return 0;
return 1;
}
static struct TCP_Server_Info *
cifs_find_tcp_session(struct sockaddr *addr, struct smb_vol *vol)
{
struct TCP_Server_Info *server;
spin_lock(&cifs_tcp_ses_lock);
list_for_each_entry(server, &cifs_tcp_ses_list, tcp_ses_list) {
if (!match_server(server, addr, vol))
continue;
++server->srv_count;
spin_unlock(&cifs_tcp_ses_lock);
cFYI(1, "Existing tcp session with server found");
return server;
}
spin_unlock(&cifs_tcp_ses_lock);
return NULL;
}
static void
cifs_put_tcp_session(struct TCP_Server_Info *server)
{
struct task_struct *task;
spin_lock(&cifs_tcp_ses_lock);
if (--server->srv_count > 0) {
spin_unlock(&cifs_tcp_ses_lock);
return;
}
put_net(cifs_net_ns(server));
list_del_init(&server->tcp_ses_list);
spin_unlock(&cifs_tcp_ses_lock);
cancel_delayed_work_sync(&server->echo);
spin_lock(&GlobalMid_Lock);
server->tcpStatus = CifsExiting;
spin_unlock(&GlobalMid_Lock);
cifs_crypto_shash_release(server);
cifs_fscache_release_client_cookie(server);
kfree(server->session_key.response);
server->session_key.response = NULL;
server->session_key.len = 0;
task = xchg(&server->tsk, NULL);
if (task)
force_sig(SIGKILL, task);
}
static struct TCP_Server_Info *
cifs_get_tcp_session(struct smb_vol *volume_info)
{
struct TCP_Server_Info *tcp_ses = NULL;
struct sockaddr_storage addr;
struct sockaddr_in *sin_server = (struct sockaddr_in *) &addr;
struct sockaddr_in6 *sin_server6 = (struct sockaddr_in6 *) &addr;
int rc;
memset(&addr, 0, sizeof(struct sockaddr_storage));
cFYI(1, "UNC: %s ip: %s", volume_info->UNC, volume_info->UNCip);
if (volume_info->UNCip && volume_info->UNC) {
rc = cifs_fill_sockaddr((struct sockaddr *)&addr,
volume_info->UNCip,
strlen(volume_info->UNCip),
volume_info->port);
if (!rc) {
rc = -EINVAL;
goto out_err;
}
} else if (volume_info->UNCip) {
cERROR(1, "Connecting to DFS root not implemented yet");
rc = -EINVAL;
goto out_err;
} else {
cERROR(1, "CIFS mount error: No UNC path (e.g. -o "
"unc=//192.168.1.100/public) specified");
rc = -EINVAL;
goto out_err;
}
tcp_ses = cifs_find_tcp_session((struct sockaddr *)&addr, volume_info);
if (tcp_ses)
return tcp_ses;
tcp_ses = kzalloc(sizeof(struct TCP_Server_Info), GFP_KERNEL);
if (!tcp_ses) {
rc = -ENOMEM;
goto out_err;
}
rc = cifs_crypto_shash_allocate(tcp_ses);
if (rc) {
cERROR(1, "could not setup hash structures rc %d", rc);
goto out_err;
}
cifs_set_net_ns(tcp_ses, get_net(current->nsproxy->net_ns));
tcp_ses->hostname = extract_hostname(volume_info->UNC);
if (IS_ERR(tcp_ses->hostname)) {
rc = PTR_ERR(tcp_ses->hostname);
goto out_err_crypto_release;
}
tcp_ses->noblocksnd = volume_info->noblocksnd;
tcp_ses->noautotune = volume_info->noautotune;
tcp_ses->tcp_nodelay = volume_info->sockopt_tcp_nodelay;
atomic_set(&tcp_ses->inFlight, 0);
init_waitqueue_head(&tcp_ses->response_q);
init_waitqueue_head(&tcp_ses->request_q);
INIT_LIST_HEAD(&tcp_ses->pending_mid_q);
mutex_init(&tcp_ses->srv_mutex);
memcpy(tcp_ses->workstation_RFC1001_name,
volume_info->source_rfc1001_name, RFC1001_NAME_LEN_WITH_NULL);
memcpy(tcp_ses->server_RFC1001_name,
volume_info->target_rfc1001_name, RFC1001_NAME_LEN_WITH_NULL);
tcp_ses->session_estab = false;
tcp_ses->sequence_number = 0;
tcp_ses->lstrp = jiffies;
INIT_LIST_HEAD(&tcp_ses->tcp_ses_list);
INIT_LIST_HEAD(&tcp_ses->smb_ses_list);
INIT_DELAYED_WORK(&tcp_ses->echo, cifs_echo_request);
tcp_ses->tcpStatus = CifsNew;
memcpy(&tcp_ses->srcaddr, &volume_info->srcaddr,
sizeof(tcp_ses->srcaddr));
++tcp_ses->srv_count;
if (addr.ss_family == AF_INET6) {
cFYI(1, "attempting ipv6 connect");
memcpy(&tcp_ses->dstaddr, sin_server6,
sizeof(struct sockaddr_in6));
} else
memcpy(&tcp_ses->dstaddr, sin_server,
sizeof(struct sockaddr_in));
rc = ip_connect(tcp_ses);
if (rc < 0) {
cERROR(1, "Error connecting to socket. Aborting operation");
goto out_err_crypto_release;
}
__module_get(THIS_MODULE);
tcp_ses->tsk = kthread_run((void *)(void *)cifs_demultiplex_thread,
tcp_ses, "cifsd");
if (IS_ERR(tcp_ses->tsk)) {
rc = PTR_ERR(tcp_ses->tsk);
cERROR(1, "error %d create cifsd thread", rc);
module_put(THIS_MODULE);
goto out_err_crypto_release;
}
tcp_ses->tcpStatus = CifsNeedNegotiate;
spin_lock(&cifs_tcp_ses_lock);
list_add(&tcp_ses->tcp_ses_list, &cifs_tcp_ses_list);
spin_unlock(&cifs_tcp_ses_lock);
cifs_fscache_get_client_cookie(tcp_ses);
queue_delayed_work(system_nrt_wq, &tcp_ses->echo, SMB_ECHO_INTERVAL);
return tcp_ses;
out_err_crypto_release:
cifs_crypto_shash_release(tcp_ses);
put_net(cifs_net_ns(tcp_ses));
out_err:
if (tcp_ses) {
if (!IS_ERR(tcp_ses->hostname))
kfree(tcp_ses->hostname);
if (tcp_ses->ssocket)
sock_release(tcp_ses->ssocket);
kfree(tcp_ses);
}
return ERR_PTR(rc);
}
static int match_session(struct cifs_ses *ses, struct smb_vol *vol)
{
switch (ses->server->secType) {
case Kerberos:
if (vol->cred_uid != ses->cred_uid)
return 0;
break;
default:
if (ses->user_name == NULL)
return 0;
if (strncmp(ses->user_name, vol->username,
MAX_USERNAME_SIZE))
return 0;
if (strlen(vol->username) != 0 &&
ses->password != NULL &&
strncmp(ses->password,
vol->password ? vol->password : "",
MAX_PASSWORD_SIZE))
return 0;
}
return 1;
}
static struct cifs_ses *
cifs_find_smb_ses(struct TCP_Server_Info *server, struct smb_vol *vol)
{
struct cifs_ses *ses;
spin_lock(&cifs_tcp_ses_lock);
list_for_each_entry(ses, &server->smb_ses_list, smb_ses_list) {
if (!match_session(ses, vol))
continue;
++ses->ses_count;
spin_unlock(&cifs_tcp_ses_lock);
return ses;
}
spin_unlock(&cifs_tcp_ses_lock);
return NULL;
}
static void
cifs_put_smb_ses(struct cifs_ses *ses)
{
int xid;
struct TCP_Server_Info *server = ses->server;
cFYI(1, "%s: ses_count=%d\n", __func__, ses->ses_count);
spin_lock(&cifs_tcp_ses_lock);
if (--ses->ses_count > 0) {
spin_unlock(&cifs_tcp_ses_lock);
return;
}
list_del_init(&ses->smb_ses_list);
spin_unlock(&cifs_tcp_ses_lock);
if (ses->status == CifsGood) {
xid = GetXid();
CIFSSMBLogoff(xid, ses);
_FreeXid(xid);
}
sesInfoFree(ses);
cifs_put_tcp_session(server);
}
static struct cifs_ses *
cifs_get_smb_ses(struct TCP_Server_Info *server, struct smb_vol *volume_info)
{
int rc = -ENOMEM, xid;
struct cifs_ses *ses;
struct sockaddr_in *addr = (struct sockaddr_in *)&server->dstaddr;
struct sockaddr_in6 *addr6 = (struct sockaddr_in6 *)&server->dstaddr;
xid = GetXid();
ses = cifs_find_smb_ses(server, volume_info);
if (ses) {
cFYI(1, "Existing smb sess found (status=%d)", ses->status);
mutex_lock(&ses->session_mutex);
rc = cifs_negotiate_protocol(xid, ses);
if (rc) {
mutex_unlock(&ses->session_mutex);
cifs_put_smb_ses(ses);
FreeXid(xid);
return ERR_PTR(rc);
}
if (ses->need_reconnect) {
cFYI(1, "Session needs reconnect");
rc = cifs_setup_session(xid, ses,
volume_info->local_nls);
if (rc) {
mutex_unlock(&ses->session_mutex);
cifs_put_smb_ses(ses);
FreeXid(xid);
return ERR_PTR(rc);
}
}
mutex_unlock(&ses->session_mutex);
cifs_put_tcp_session(server);
FreeXid(xid);
return ses;
}
cFYI(1, "Existing smb sess not found");
ses = sesInfoAlloc();
if (ses == NULL)
goto get_ses_fail;
ses->server = server;
if (server->dstaddr.ss_family == AF_INET6)
sprintf(ses->serverName, "%pI6", &addr6->sin6_addr);
else
sprintf(ses->serverName, "%pI4", &addr->sin_addr);
if (volume_info->username) {
ses->user_name = kstrdup(volume_info->username, GFP_KERNEL);
if (!ses->user_name)
goto get_ses_fail;
}
if (volume_info->password) {
ses->password = kstrdup(volume_info->password, GFP_KERNEL);
if (!ses->password)
goto get_ses_fail;
}
if (volume_info->domainname) {
ses->domainName = kstrdup(volume_info->domainname, GFP_KERNEL);
if (!ses->domainName)
goto get_ses_fail;
}
ses->cred_uid = volume_info->cred_uid;
ses->linux_uid = volume_info->linux_uid;
if ((volume_info->secFlg == 0) && warned_on_ntlm == false) {
warned_on_ntlm = true;
cERROR(1, "default security mechanism requested. The default "
"security mechanism will be upgraded from ntlm to "
"ntlmv2 in kernel release 3.1");
}
ses->overrideSecFlg = volume_info->secFlg;
mutex_lock(&ses->session_mutex);
rc = cifs_negotiate_protocol(xid, ses);
if (!rc)
rc = cifs_setup_session(xid, ses, volume_info->local_nls);
mutex_unlock(&ses->session_mutex);
if (rc)
goto get_ses_fail;
spin_lock(&cifs_tcp_ses_lock);
list_add(&ses->smb_ses_list, &server->smb_ses_list);
spin_unlock(&cifs_tcp_ses_lock);
FreeXid(xid);
return ses;
get_ses_fail:
sesInfoFree(ses);
FreeXid(xid);
return ERR_PTR(rc);
}
static int match_tcon(struct cifs_tcon *tcon, const char *unc)
{
if (tcon->tidStatus == CifsExiting)
return 0;
if (strncmp(tcon->treeName, unc, MAX_TREE_SIZE))
return 0;
return 1;
}
static struct cifs_tcon *
cifs_find_tcon(struct cifs_ses *ses, const char *unc)
{
struct list_head *tmp;
struct cifs_tcon *tcon;
spin_lock(&cifs_tcp_ses_lock);
list_for_each(tmp, &ses->tcon_list) {
tcon = list_entry(tmp, struct cifs_tcon, tcon_list);
if (!match_tcon(tcon, unc))
continue;
++tcon->tc_count;
spin_unlock(&cifs_tcp_ses_lock);
return tcon;
}
spin_unlock(&cifs_tcp_ses_lock);
return NULL;
}
static void
cifs_put_tcon(struct cifs_tcon *tcon)
{
int xid;
struct cifs_ses *ses = tcon->ses;
cFYI(1, "%s: tc_count=%d\n", __func__, tcon->tc_count);
spin_lock(&cifs_tcp_ses_lock);
if (--tcon->tc_count > 0) {
spin_unlock(&cifs_tcp_ses_lock);
return;
}
list_del_init(&tcon->tcon_list);
spin_unlock(&cifs_tcp_ses_lock);
xid = GetXid();
CIFSSMBTDis(xid, tcon);
_FreeXid(xid);
cifs_fscache_release_super_cookie(tcon);
tconInfoFree(tcon);
cifs_put_smb_ses(ses);
}
static struct cifs_tcon *
cifs_get_tcon(struct cifs_ses *ses, struct smb_vol *volume_info)
{
int rc, xid;
struct cifs_tcon *tcon;
tcon = cifs_find_tcon(ses, volume_info->UNC);
if (tcon) {
cFYI(1, "Found match on UNC path");
cifs_put_smb_ses(ses);
if (tcon->seal != volume_info->seal)
cERROR(1, "transport encryption setting "
"conflicts with existing tid");
return tcon;
}
tcon = tconInfoAlloc();
if (tcon == NULL) {
rc = -ENOMEM;
goto out_fail;
}
tcon->ses = ses;
if (volume_info->password) {
tcon->password = kstrdup(volume_info->password, GFP_KERNEL);
if (!tcon->password) {
rc = -ENOMEM;
goto out_fail;
}
}
if (strchr(volume_info->UNC + 3, '\\') == NULL
&& strchr(volume_info->UNC + 3, '/') == NULL) {
cERROR(1, "Missing share name");
rc = -ENODEV;
goto out_fail;
}
xid = GetXid();
rc = CIFSTCon(xid, ses, volume_info->UNC, tcon, volume_info->local_nls);
FreeXid(xid);
cFYI(1, "CIFS Tcon rc = %d", rc);
if (rc)
goto out_fail;
if (volume_info->nodfs) {
tcon->Flags &= ~SMB_SHARE_IS_IN_DFS;
cFYI(1, "DFS disabled (%d)", tcon->Flags);
}
tcon->seal = volume_info->seal;
tcon->retry = volume_info->retry;
tcon->nocase = volume_info->nocase;
tcon->local_lease = volume_info->local_lease;
spin_lock(&cifs_tcp_ses_lock);
list_add(&tcon->tcon_list, &ses->tcon_list);
spin_unlock(&cifs_tcp_ses_lock);
cifs_fscache_get_super_cookie(tcon);
return tcon;
out_fail:
tconInfoFree(tcon);
return ERR_PTR(rc);
}
void
cifs_put_tlink(struct tcon_link *tlink)
{
if (!tlink || IS_ERR(tlink))
return;
if (!atomic_dec_and_test(&tlink->tl_count) ||
test_bit(TCON_LINK_IN_TREE, &tlink->tl_flags)) {
tlink->tl_time = jiffies;
return;
}
if (!IS_ERR(tlink_tcon(tlink)))
cifs_put_tcon(tlink_tcon(tlink));
kfree(tlink);
return;
}
static inline struct tcon_link *
cifs_sb_master_tlink(struct cifs_sb_info *cifs_sb)
{
return cifs_sb->master_tlink;
}
static int
compare_mount_options(struct super_block *sb, struct cifs_mnt_data *mnt_data)
{
struct cifs_sb_info *old = CIFS_SB(sb);
struct cifs_sb_info *new = mnt_data->cifs_sb;
if ((sb->s_flags & CIFS_MS_MASK) != (mnt_data->flags & CIFS_MS_MASK))
return 0;
if ((old->mnt_cifs_flags & CIFS_MOUNT_MASK) !=
(new->mnt_cifs_flags & CIFS_MOUNT_MASK))
return 0;
if (old->rsize != new->rsize)
return 0;
if (new->wsize && new->wsize < old->wsize)
return 0;
if (old->mnt_uid != new->mnt_uid || old->mnt_gid != new->mnt_gid)
return 0;
if (old->mnt_file_mode != new->mnt_file_mode ||
old->mnt_dir_mode != new->mnt_dir_mode)
return 0;
if (strcmp(old->local_nls->charset, new->local_nls->charset))
return 0;
if (old->actimeo != new->actimeo)
return 0;
return 1;
}
int
cifs_match_super(struct super_block *sb, void *data)
{
struct cifs_mnt_data *mnt_data = (struct cifs_mnt_data *)data;
struct smb_vol *volume_info;
struct cifs_sb_info *cifs_sb;
struct TCP_Server_Info *tcp_srv;
struct cifs_ses *ses;
struct cifs_tcon *tcon;
struct tcon_link *tlink;
struct sockaddr_storage addr;
int rc = 0;
memset(&addr, 0, sizeof(struct sockaddr_storage));
spin_lock(&cifs_tcp_ses_lock);
cifs_sb = CIFS_SB(sb);
tlink = cifs_get_tlink(cifs_sb_master_tlink(cifs_sb));
if (IS_ERR(tlink)) {
spin_unlock(&cifs_tcp_ses_lock);
return rc;
}
tcon = tlink_tcon(tlink);
ses = tcon->ses;
tcp_srv = ses->server;
volume_info = mnt_data->vol;
if (!volume_info->UNCip || !volume_info->UNC)
goto out;
rc = cifs_fill_sockaddr((struct sockaddr *)&addr,
volume_info->UNCip,
strlen(volume_info->UNCip),
volume_info->port);
if (!rc)
goto out;
if (!match_server(tcp_srv, (struct sockaddr *)&addr, volume_info) ||
!match_session(ses, volume_info) ||
!match_tcon(tcon, volume_info->UNC)) {
rc = 0;
goto out;
}
rc = compare_mount_options(sb, mnt_data);
out:
spin_unlock(&cifs_tcp_ses_lock);
cifs_put_tlink(tlink);
return rc;
}
int
get_dfs_path(int xid, struct cifs_ses *pSesInfo, const char *old_path,
const struct nls_table *nls_codepage, unsigned int *pnum_referrals,
struct dfs_info3_param **preferrals, int remap)
{
char *temp_unc;
int rc = 0;
*pnum_referrals = 0;
*preferrals = NULL;
if (pSesInfo->ipc_tid == 0) {
temp_unc = kmalloc(2 +
strnlen(pSesInfo->serverName,
SERVER_NAME_LEN_WITH_NULL * 2)
+ 1 + 4 + 2,
GFP_KERNEL);
if (temp_unc == NULL)
return -ENOMEM;
temp_unc[0] = '\\';
temp_unc[1] = '\\';
strcpy(temp_unc + 2, pSesInfo->serverName);
strcpy(temp_unc + 2 + strlen(pSesInfo->serverName), "\\IPC$");
rc = CIFSTCon(xid, pSesInfo, temp_unc, NULL, nls_codepage);
cFYI(1, "CIFS Tcon rc = %d ipc_tid = %d", rc, pSesInfo->ipc_tid);
kfree(temp_unc);
}
if (rc == 0)
rc = CIFSGetDFSRefer(xid, pSesInfo, old_path, preferrals,
pnum_referrals, nls_codepage, remap);
return rc;
}
static inline void
cifs_reclassify_socket4(struct socket *sock)
{
struct sock *sk = sock->sk;
BUG_ON(sock_owned_by_user(sk));
sock_lock_init_class_and_name(sk, "slock-AF_INET-CIFS",
&cifs_slock_key[0], "sk_lock-AF_INET-CIFS", &cifs_key[0]);
}
static inline void
cifs_reclassify_socket6(struct socket *sock)
{
struct sock *sk = sock->sk;
BUG_ON(sock_owned_by_user(sk));
sock_lock_init_class_and_name(sk, "slock-AF_INET6-CIFS",
&cifs_slock_key[1], "sk_lock-AF_INET6-CIFS", &cifs_key[1]);
}
static inline void
cifs_reclassify_socket4(struct socket *sock)
{
}
static inline void
cifs_reclassify_socket6(struct socket *sock)
{
}
static void rfc1002mangle(char *target, char *source, unsigned int length)
{
unsigned int i, j;
for (i = 0, j = 0; i < (length); i++) {
target[j] = 'A' + (0x0F & (source[i] >> 4));
target[j+1] = 'A' + (0x0F & source[i]);
j += 2;
}
}
static int
bind_socket(struct TCP_Server_Info *server)
{
int rc = 0;
if (server->srcaddr.ss_family != AF_UNSPEC) {
struct socket *socket = server->ssocket;
rc = socket->ops->bind(socket,
(struct sockaddr *) &server->srcaddr,
sizeof(server->srcaddr));
if (rc < 0) {
struct sockaddr_in *saddr4;
struct sockaddr_in6 *saddr6;
saddr4 = (struct sockaddr_in *)&server->srcaddr;
saddr6 = (struct sockaddr_in6 *)&server->srcaddr;
if (saddr6->sin6_family == AF_INET6)
cERROR(1, "cifs: "
"Failed to bind to: %pI6c, error: %d\n",
&saddr6->sin6_addr, rc);
else
cERROR(1, "cifs: "
"Failed to bind to: %pI4, error: %d\n",
&saddr4->sin_addr.s_addr, rc);
}
}
return rc;
}
static int
ip_rfc1001_connect(struct TCP_Server_Info *server)
{
int rc = 0;
struct rfc1002_session_packet *ses_init_buf;
struct smb_hdr *smb_buf;
ses_init_buf = kzalloc(sizeof(struct rfc1002_session_packet),
GFP_KERNEL);
if (ses_init_buf) {
ses_init_buf->trailer.session_req.called_len = 32;
if (server->server_RFC1001_name &&
server->server_RFC1001_name[0] != 0)
rfc1002mangle(ses_init_buf->trailer.
session_req.called_name,
server->server_RFC1001_name,
RFC1001_NAME_LEN_WITH_NULL);
else
rfc1002mangle(ses_init_buf->trailer.
session_req.called_name,
DEFAULT_CIFS_CALLED_NAME,
RFC1001_NAME_LEN_WITH_NULL);
ses_init_buf->trailer.session_req.calling_len = 32;
if (server->workstation_RFC1001_name &&
server->workstation_RFC1001_name[0] != 0)
rfc1002mangle(ses_init_buf->trailer.
session_req.calling_name,
server->workstation_RFC1001_name,
RFC1001_NAME_LEN_WITH_NULL);
else
rfc1002mangle(ses_init_buf->trailer.
session_req.calling_name,
"LINUX_CIFS_CLNT",
RFC1001_NAME_LEN_WITH_NULL);
ses_init_buf->trailer.session_req.scope1 = 0;
ses_init_buf->trailer.session_req.scope2 = 0;
smb_buf = (struct smb_hdr *)ses_init_buf;
smb_buf->smb_buf_length = cpu_to_be32(0x81000044);
rc = smb_send(server, smb_buf, 0x44);
kfree(ses_init_buf);
usleep_range(1000, 2000);
}
return rc;
}
static int
generic_ip_connect(struct TCP_Server_Info *server)
{
int rc = 0;
__be16 sport;
int slen, sfamily;
struct socket *socket = server->ssocket;
struct sockaddr *saddr;
saddr = (struct sockaddr *) &server->dstaddr;
if (server->dstaddr.ss_family == AF_INET6) {
sport = ((struct sockaddr_in6 *) saddr)->sin6_port;
slen = sizeof(struct sockaddr_in6);
sfamily = AF_INET6;
} else {
sport = ((struct sockaddr_in *) saddr)->sin_port;
slen = sizeof(struct sockaddr_in);
sfamily = AF_INET;
}
if (socket == NULL) {
rc = __sock_create(cifs_net_ns(server), sfamily, SOCK_STREAM,
IPPROTO_TCP, &socket, 1);
if (rc < 0) {
cERROR(1, "Error %d creating socket", rc);
server->ssocket = NULL;
return rc;
}
cFYI(1, "Socket created");
server->ssocket = socket;
socket->sk->sk_allocation = GFP_NOFS;
if (sfamily == AF_INET6)
cifs_reclassify_socket6(socket);
else
cifs_reclassify_socket4(socket);
}
rc = bind_socket(server);
if (rc < 0)
return rc;
socket->sk->sk_rcvtimeo = 7 * HZ;
socket->sk->sk_sndtimeo = 5 * HZ;
if (server->noautotune) {
if (socket->sk->sk_sndbuf < (200 * 1024))
socket->sk->sk_sndbuf = 200 * 1024;
if (socket->sk->sk_rcvbuf < (140 * 1024))
socket->sk->sk_rcvbuf = 140 * 1024;
}
if (server->tcp_nodelay) {
int val = 1;
rc = kernel_setsockopt(socket, SOL_TCP, TCP_NODELAY,
(char *)&val, sizeof(val));
if (rc)
cFYI(1, "set TCP_NODELAY socket option error %d", rc);
}
cFYI(1, "sndbuf %d rcvbuf %d rcvtimeo 0x%lx",
socket->sk->sk_sndbuf,
socket->sk->sk_rcvbuf, socket->sk->sk_rcvtimeo);
rc = socket->ops->connect(socket, saddr, slen, 0);
if (rc < 0) {
cFYI(1, "Error %d connecting to server", rc);
sock_release(socket);
server->ssocket = NULL;
return rc;
}
if (sport == htons(RFC1001_PORT))
rc = ip_rfc1001_connect(server);
return rc;
}
static int
ip_connect(struct TCP_Server_Info *server)
{
__be16 *sport;
struct sockaddr_in6 *addr6 = (struct sockaddr_in6 *)&server->dstaddr;
struct sockaddr_in *addr = (struct sockaddr_in *)&server->dstaddr;
if (server->dstaddr.ss_family == AF_INET6)
sport = &addr6->sin6_port;
else
sport = &addr->sin_port;
if (*sport == 0) {
int rc;
*sport = htons(CIFS_PORT);
rc = generic_ip_connect(server);
if (rc >= 0)
return rc;
*sport = htons(RFC1001_PORT);
}
return generic_ip_connect(server);
}
void reset_cifs_unix_caps(int xid, struct cifs_tcon *tcon,
struct cifs_sb_info *cifs_sb, struct smb_vol *vol_info)
{
__u64 saved_cap = le64_to_cpu(tcon->fsUnixInfo.Capability);
if (vol_info && vol_info->no_linux_ext) {
tcon->fsUnixInfo.Capability = 0;
tcon->unix_ext = 0;
cFYI(1, "Linux protocol extensions disabled");
return;
} else if (vol_info)
tcon->unix_ext = 1;
if (tcon->unix_ext == 0) {
cFYI(1, "Unix extensions disabled so not set on reconnect");
return;
}
if (!CIFSSMBQFSUnixInfo(xid, tcon)) {
__u64 cap = le64_to_cpu(tcon->fsUnixInfo.Capability);
cFYI(1, "unix caps which server supports %lld", cap);
if (vol_info == NULL) {
if ((saved_cap & CIFS_UNIX_POSIX_ACL_CAP) == 0)
cap &= ~CIFS_UNIX_POSIX_ACL_CAP;
if ((saved_cap & CIFS_UNIX_POSIX_PATHNAMES_CAP) == 0) {
if (cap & CIFS_UNIX_POSIX_PATHNAMES_CAP)
cERROR(1, "POSIXPATH support change");
cap &= ~CIFS_UNIX_POSIX_PATHNAMES_CAP;
} else if ((cap & CIFS_UNIX_POSIX_PATHNAMES_CAP) == 0) {
cERROR(1, "possible reconnect error");
cERROR(1, "server disabled POSIX path support");
}
}
if (cap & CIFS_UNIX_TRANSPORT_ENCRYPTION_MANDATORY_CAP)
cERROR(1, "per-share encryption not supported yet");
cap &= CIFS_UNIX_CAP_MASK;
if (vol_info && vol_info->no_psx_acl)
cap &= ~CIFS_UNIX_POSIX_ACL_CAP;
else if (CIFS_UNIX_POSIX_ACL_CAP & cap) {
cFYI(1, "negotiated posix acl support");
if (cifs_sb)
cifs_sb->mnt_cifs_flags |=
CIFS_MOUNT_POSIXACL;
}
if (vol_info && vol_info->posix_paths == 0)
cap &= ~CIFS_UNIX_POSIX_PATHNAMES_CAP;
else if (cap & CIFS_UNIX_POSIX_PATHNAMES_CAP) {
cFYI(1, "negotiate posix pathnames");
if (cifs_sb)
cifs_sb->mnt_cifs_flags |=
CIFS_MOUNT_POSIX_PATHS;
}
if (cifs_sb && (cifs_sb->rsize > 127 * 1024)) {
if ((cap & CIFS_UNIX_LARGE_READ_CAP) == 0) {
cifs_sb->rsize = 127 * 1024;
cFYI(DBG2, "larger reads not supported by srv");
}
}
cFYI(1, "Negotiate caps 0x%x", (int)cap);
#ifdef CONFIG_CIFS_DEBUG2
if (cap & CIFS_UNIX_FCNTL_CAP)
cFYI(1, "FCNTL cap");
if (cap & CIFS_UNIX_EXTATTR_CAP)
cFYI(1, "EXTATTR cap");
if (cap & CIFS_UNIX_POSIX_PATHNAMES_CAP)
cFYI(1, "POSIX path cap");
if (cap & CIFS_UNIX_XATTR_CAP)
cFYI(1, "XATTR cap");
if (cap & CIFS_UNIX_POSIX_ACL_CAP)
cFYI(1, "POSIX ACL cap");
if (cap & CIFS_UNIX_LARGE_READ_CAP)
cFYI(1, "very large read cap");
if (cap & CIFS_UNIX_LARGE_WRITE_CAP)
cFYI(1, "very large write cap");
if (cap & CIFS_UNIX_TRANSPORT_ENCRYPTION_CAP)
cFYI(1, "transport encryption cap");
if (cap & CIFS_UNIX_TRANSPORT_ENCRYPTION_MANDATORY_CAP)
cFYI(1, "mandatory transport encryption cap");
#endif
if (CIFSSMBSetFSUnixInfo(xid, tcon, cap)) {
if (vol_info == NULL) {
cFYI(1, "resetting capabilities failed");
} else
cERROR(1, "Negotiating Unix capabilities "
"with the server failed. Consider "
"mounting with the Unix Extensions\n"
"disabled, if problems are found, "
"by specifying the nounix mount "
"option.");
}
}
}
void cifs_setup_cifs_sb(struct smb_vol *pvolume_info,
struct cifs_sb_info *cifs_sb)
{
INIT_DELAYED_WORK(&cifs_sb->prune_tlinks, cifs_prune_tlinks);
spin_lock_init(&cifs_sb->tlink_tree_lock);
cifs_sb->tlink_tree = RB_ROOT;
if (pvolume_info->rsize > CIFSMaxBufSize) {
cERROR(1, "rsize %d too large, using MaxBufSize",
pvolume_info->rsize);
cifs_sb->rsize = CIFSMaxBufSize;
} else if ((pvolume_info->rsize) &&
(pvolume_info->rsize <= CIFSMaxBufSize))
cifs_sb->rsize = pvolume_info->rsize;
else
cifs_sb->rsize = CIFSMaxBufSize;
if (cifs_sb->rsize < 2048) {
cifs_sb->rsize = 2048;
cFYI(1, "readsize set to minimum: 2048");
}
cifs_sb->wsize = pvolume_info->wsize;
cifs_sb->mnt_uid = pvolume_info->linux_uid;
cifs_sb->mnt_gid = pvolume_info->linux_gid;
cifs_sb->mnt_file_mode = pvolume_info->file_mode;
cifs_sb->mnt_dir_mode = pvolume_info->dir_mode;
cFYI(1, "file mode: 0x%x dir mode: 0x%x",
cifs_sb->mnt_file_mode, cifs_sb->mnt_dir_mode);
cifs_sb->actimeo = pvolume_info->actimeo;
cifs_sb->local_nls = pvolume_info->local_nls;
if (pvolume_info->noperm)
cifs_sb->mnt_cifs_flags |= CIFS_MOUNT_NO_PERM;
if (pvolume_info->setuids)
cifs_sb->mnt_cifs_flags |= CIFS_MOUNT_SET_UID;
if (pvolume_info->server_ino)
cifs_sb->mnt_cifs_flags |= CIFS_MOUNT_SERVER_INUM;
if (pvolume_info->remap)
cifs_sb->mnt_cifs_flags |= CIFS_MOUNT_MAP_SPECIAL_CHR;
if (pvolume_info->no_xattr)
cifs_sb->mnt_cifs_flags |= CIFS_MOUNT_NO_XATTR;
if (pvolume_info->sfu_emul)
cifs_sb->mnt_cifs_flags |= CIFS_MOUNT_UNX_EMUL;
if (pvolume_info->nobrl)
cifs_sb->mnt_cifs_flags |= CIFS_MOUNT_NO_BRL;
if (pvolume_info->nostrictsync)
cifs_sb->mnt_cifs_flags |= CIFS_MOUNT_NOSSYNC;
if (pvolume_info->mand_lock)
cifs_sb->mnt_cifs_flags |= CIFS_MOUNT_NOPOSIXBRL;
if (pvolume_info->rwpidforward)
cifs_sb->mnt_cifs_flags |= CIFS_MOUNT_RWPIDFORWARD;
if (pvolume_info->cifs_acl)
cifs_sb->mnt_cifs_flags |= CIFS_MOUNT_CIFS_ACL;
if (pvolume_info->override_uid)
cifs_sb->mnt_cifs_flags |= CIFS_MOUNT_OVERR_UID;
if (pvolume_info->override_gid)
cifs_sb->mnt_cifs_flags |= CIFS_MOUNT_OVERR_GID;
if (pvolume_info->dynperm)
cifs_sb->mnt_cifs_flags |= CIFS_MOUNT_DYNPERM;
if (pvolume_info->fsc)
cifs_sb->mnt_cifs_flags |= CIFS_MOUNT_FSCACHE;
if (pvolume_info->multiuser)
cifs_sb->mnt_cifs_flags |= (CIFS_MOUNT_MULTIUSER |
CIFS_MOUNT_NO_PERM);
if (pvolume_info->strict_io)
cifs_sb->mnt_cifs_flags |= CIFS_MOUNT_STRICT_IO;
if (pvolume_info->direct_io) {
cFYI(1, "mounting share using direct i/o");
cifs_sb->mnt_cifs_flags |= CIFS_MOUNT_DIRECT_IO;
}
if (pvolume_info->mfsymlinks) {
if (pvolume_info->sfu_emul) {
cERROR(1, "mount option mfsymlinks ignored if sfu "
"mount option is used");
} else {
cifs_sb->mnt_cifs_flags |= CIFS_MOUNT_MF_SYMLINKS;
}
}
if ((pvolume_info->cifs_acl) && (pvolume_info->dynperm))
cERROR(1, "mount option dynperm ignored if cifsacl "
"mount option supported");
}
static unsigned int
cifs_negotiate_wsize(struct cifs_tcon *tcon, struct smb_vol *pvolume_info)
{
__u64 unix_cap = le64_to_cpu(tcon->fsUnixInfo.Capability);
struct TCP_Server_Info *server = tcon->ses->server;
unsigned int wsize = pvolume_info->wsize ? pvolume_info->wsize :
CIFS_DEFAULT_WSIZE;
if (!tcon->unix_ext || !(unix_cap & CIFS_UNIX_LARGE_WRITE_CAP))
wsize = min_t(unsigned int, wsize, CIFS_MAX_RFC1002_WSIZE);
if (!(server->capabilities & CAP_LARGE_WRITE_X) ||
(!(server->capabilities & CAP_UNIX) &&
(server->sec_mode & (SECMODE_SIGN_ENABLED|SECMODE_SIGN_REQUIRED))))
wsize = min_t(unsigned int, wsize,
server->maxBuf - sizeof(WRITE_REQ) + 4);
wsize = min_t(unsigned int, wsize, CIFS_MAX_WSIZE);
return wsize;
}
static int
is_path_accessible(int xid, struct cifs_tcon *tcon,
struct cifs_sb_info *cifs_sb, const char *full_path)
{
int rc;
FILE_ALL_INFO *pfile_info;
pfile_info = kmalloc(sizeof(FILE_ALL_INFO), GFP_KERNEL);
if (pfile_info == NULL)
return -ENOMEM;
rc = CIFSSMBQPathInfo(xid, tcon, full_path, pfile_info,
0 , cifs_sb->local_nls,
cifs_sb->mnt_cifs_flags &
CIFS_MOUNT_MAP_SPECIAL_CHR);
if (rc == -EOPNOTSUPP || rc == -EINVAL)
rc = SMBQueryInformation(xid, tcon, full_path, pfile_info,
cifs_sb->local_nls, cifs_sb->mnt_cifs_flags &
CIFS_MOUNT_MAP_SPECIAL_CHR);
kfree(pfile_info);
return rc;
}
static void
cleanup_volume_info_contents(struct smb_vol *volume_info)
{
kfree(volume_info->username);
kzfree(volume_info->password);
kfree(volume_info->UNC);
kfree(volume_info->UNCip);
kfree(volume_info->domainname);
kfree(volume_info->iocharset);
kfree(volume_info->prepath);
}
void
cifs_cleanup_volume_info(struct smb_vol *volume_info)
{
if (!volume_info)
return;
cleanup_volume_info_contents(volume_info);
kfree(volume_info);
}
static char *
build_unc_path_to_root(const struct smb_vol *vol,
const struct cifs_sb_info *cifs_sb)
{
char *full_path, *pos;
unsigned int pplen = vol->prepath ? strlen(vol->prepath) : 0;
unsigned int unc_len = strnlen(vol->UNC, MAX_TREE_SIZE + 1);
full_path = kmalloc(unc_len + pplen + 1, GFP_KERNEL);
if (full_path == NULL)
return ERR_PTR(-ENOMEM);
strncpy(full_path, vol->UNC, unc_len);
pos = full_path + unc_len;
if (pplen) {
strncpy(pos, vol->prepath, pplen);
pos += pplen;
}
*pos = '\0';
convert_delimiter(full_path, CIFS_DIR_SEP(cifs_sb));
cFYI(1, "%s: full_path=%s", __func__, full_path);
return full_path;
}
static int
expand_dfs_referral(int xid, struct cifs_ses *pSesInfo,
struct smb_vol *volume_info, struct cifs_sb_info *cifs_sb,
int check_prefix)
{
int rc;
unsigned int num_referrals = 0;
struct dfs_info3_param *referrals = NULL;
char *full_path = NULL, *ref_path = NULL, *mdata = NULL;
full_path = build_unc_path_to_root(volume_info, cifs_sb);
if (IS_ERR(full_path))
return PTR_ERR(full_path);
ref_path = check_prefix ? full_path + 1 : volume_info->UNC + 1;
rc = get_dfs_path(xid, pSesInfo , ref_path, cifs_sb->local_nls,
&num_referrals, &referrals,
cifs_sb->mnt_cifs_flags & CIFS_MOUNT_MAP_SPECIAL_CHR);
if (!rc && num_referrals > 0) {
char *fake_devname = NULL;
mdata = cifs_compose_mount_options(cifs_sb->mountdata,
full_path + 1, referrals,
&fake_devname);
free_dfs_info_array(referrals, num_referrals);
if (IS_ERR(mdata)) {
rc = PTR_ERR(mdata);
mdata = NULL;
} else {
cleanup_volume_info_contents(volume_info);
memset(volume_info, '\0', sizeof(*volume_info));
rc = cifs_setup_volume_info(volume_info, mdata,
fake_devname);
}
kfree(fake_devname);
kfree(cifs_sb->mountdata);
cifs_sb->mountdata = mdata;
}
kfree(full_path);
return rc;
}
static int
cifs_setup_volume_info(struct smb_vol *volume_info, char *mount_data,
const char *devname)
{
int rc = 0;
if (cifs_parse_mount_options(mount_data, devname, volume_info))
return -EINVAL;
if (volume_info->nullauth) {
cFYI(1, "null user");
volume_info->username = kzalloc(1, GFP_KERNEL);
if (volume_info->username == NULL)
return -ENOMEM;
} else if (volume_info->username) {
cFYI(1, "Username: %s", volume_info->username);
} else {
cifserror("No username specified");
return -EINVAL;
}
if (volume_info->iocharset == NULL) {
volume_info->local_nls = load_nls_default();
} else {
volume_info->local_nls = load_nls(volume_info->iocharset);
if (volume_info->local_nls == NULL) {
cERROR(1, "CIFS mount error: iocharset %s not found",
volume_info->iocharset);
return -ELIBACC;
}
}
return rc;
}
struct smb_vol *
cifs_get_volume_info(char *mount_data, const char *devname)
{
int rc;
struct smb_vol *volume_info;
volume_info = kzalloc(sizeof(struct smb_vol), GFP_KERNEL);
if (!volume_info)
return ERR_PTR(-ENOMEM);
rc = cifs_setup_volume_info(volume_info, mount_data, devname);
if (rc) {
cifs_cleanup_volume_info(volume_info);
volume_info = ERR_PTR(rc);
}
return volume_info;
}
int
cifs_mount(struct cifs_sb_info *cifs_sb, struct smb_vol *volume_info)
{
int rc = 0;
int xid;
struct cifs_ses *pSesInfo;
struct cifs_tcon *tcon;
struct TCP_Server_Info *srvTcp;
char *full_path;
struct tcon_link *tlink;
#ifdef CONFIG_CIFS_DFS_UPCALL
int referral_walks_count = 0;
#endif
rc = bdi_setup_and_register(&cifs_sb->bdi, "cifs", BDI_CAP_MAP_COPY);
if (rc)
return rc;
cifs_sb->bdi.ra_pages = default_backing_dev_info.ra_pages;
#ifdef CONFIG_CIFS_DFS_UPCALL
try_mount_again:
if (referral_walks_count) {
if (tcon)
cifs_put_tcon(tcon);
else if (pSesInfo)
cifs_put_smb_ses(pSesInfo);
FreeXid(xid);
}
#endif
tcon = NULL;
pSesInfo = NULL;
srvTcp = NULL;
full_path = NULL;
tlink = NULL;
xid = GetXid();
srvTcp = cifs_get_tcp_session(volume_info);
if (IS_ERR(srvTcp)) {
rc = PTR_ERR(srvTcp);
bdi_destroy(&cifs_sb->bdi);
goto out;
}
pSesInfo = cifs_get_smb_ses(srvTcp, volume_info);
if (IS_ERR(pSesInfo)) {
rc = PTR_ERR(pSesInfo);
pSesInfo = NULL;
goto mount_fail_check;
}
tcon = cifs_get_tcon(pSesInfo, volume_info);
if (IS_ERR(tcon)) {
rc = PTR_ERR(tcon);
tcon = NULL;
goto remote_path_check;
}
if (tcon->ses->capabilities & CAP_UNIX) {
reset_cifs_unix_caps(xid, tcon, cifs_sb, volume_info);
if ((tcon->ses->server->tcpStatus == CifsNeedReconnect) &&
(le64_to_cpu(tcon->fsUnixInfo.Capability) &
CIFS_UNIX_TRANSPORT_ENCRYPTION_MANDATORY_CAP)) {
rc = -EACCES;
goto mount_fail_check;
}
} else
tcon->unix_ext = 0;
if (!tcon->ipc) {
CIFSSMBQFSDeviceInfo(xid, tcon);
CIFSSMBQFSAttributeInfo(xid, tcon);
}
if ((tcon->unix_ext == 0) && (cifs_sb->rsize > (1024 * 127))) {
cifs_sb->rsize = 1024 * 127;
cFYI(DBG2, "no very large read support, rsize now 127K");
}
if (!(tcon->ses->capabilities & CAP_LARGE_READ_X))
cifs_sb->rsize = min(cifs_sb->rsize,
(tcon->ses->server->maxBuf - MAX_CIFS_HDR_SIZE));
cifs_sb->wsize = cifs_negotiate_wsize(tcon, volume_info);
remote_path_check:
#ifdef CONFIG_CIFS_DFS_UPCALL
if (referral_walks_count == 0) {
int refrc = expand_dfs_referral(xid, pSesInfo, volume_info,
cifs_sb, false);
if (!refrc) {
referral_walks_count++;
goto try_mount_again;
}
}
#endif
if (!rc && tcon) {
full_path = cifs_build_path_to_root(volume_info, cifs_sb, tcon);
if (full_path == NULL) {
rc = -ENOMEM;
goto mount_fail_check;
}
rc = is_path_accessible(xid, tcon, cifs_sb, full_path);
if (rc != 0 && rc != -EREMOTE) {
kfree(full_path);
goto mount_fail_check;
}
kfree(full_path);
}
if (rc == -EREMOTE) {
#ifdef CONFIG_CIFS_DFS_UPCALL
if (referral_walks_count > MAX_NESTED_LINKS) {
rc = -ELOOP;
goto mount_fail_check;
}
rc = expand_dfs_referral(xid, pSesInfo, volume_info, cifs_sb,
true);
if (!rc) {
referral_walks_count++;
goto try_mount_again;
}
goto mount_fail_check;
#else
rc = -EOPNOTSUPP;
#endif
}
if (rc)
goto mount_fail_check;
tlink = kzalloc(sizeof *tlink, GFP_KERNEL);
if (tlink == NULL) {
rc = -ENOMEM;
goto mount_fail_check;
}
tlink->tl_uid = pSesInfo->linux_uid;
tlink->tl_tcon = tcon;
tlink->tl_time = jiffies;
set_bit(TCON_LINK_MASTER, &tlink->tl_flags);
set_bit(TCON_LINK_IN_TREE, &tlink->tl_flags);
cifs_sb->master_tlink = tlink;
spin_lock(&cifs_sb->tlink_tree_lock);
tlink_rb_insert(&cifs_sb->tlink_tree, tlink);
spin_unlock(&cifs_sb->tlink_tree_lock);
queue_delayed_work(system_nrt_wq, &cifs_sb->prune_tlinks,
TLINK_IDLE_EXPIRE);
mount_fail_check:
if (rc) {
if (tcon)
cifs_put_tcon(tcon);
else if (pSesInfo)
cifs_put_smb_ses(pSesInfo);
else
cifs_put_tcp_session(srvTcp);
bdi_destroy(&cifs_sb->bdi);
goto out;
}
out:
FreeXid(xid);
return rc;
}
int
CIFSTCon(unsigned int xid, struct cifs_ses *ses,
const char *tree, struct cifs_tcon *tcon,
const struct nls_table *nls_codepage)
{
struct smb_hdr *smb_buffer;
struct smb_hdr *smb_buffer_response;
TCONX_REQ *pSMB;
TCONX_RSP *pSMBr;
unsigned char *bcc_ptr;
int rc = 0;
int length;
__u16 bytes_left, count;
if (ses == NULL)
return -EIO;
smb_buffer = cifs_buf_get();
if (smb_buffer == NULL)
return -ENOMEM;
smb_buffer_response = smb_buffer;
header_assemble(smb_buffer, SMB_COM_TREE_CONNECT_ANDX,
NULL , 4 );
smb_buffer->Mid = GetNextMid(ses->server);
smb_buffer->Uid = ses->Suid;
pSMB = (TCONX_REQ *) smb_buffer;
pSMBr = (TCONX_RSP *) smb_buffer_response;
pSMB->AndXCommand = 0xFF;
pSMB->Flags = cpu_to_le16(TCON_EXTENDED_SECINFO);
bcc_ptr = &pSMB->Password[0];
if (!tcon || (ses->server->sec_mode & SECMODE_USER)) {
pSMB->PasswordLength = cpu_to_le16(1);
*bcc_ptr = 0;
bcc_ptr++;
} else {
pSMB->PasswordLength = cpu_to_le16(CIFS_AUTH_RESP_SIZE);
#ifdef CONFIG_CIFS_WEAK_PW_HASH
if ((global_secflags & CIFSSEC_MAY_LANMAN) &&
(ses->server->secType == LANMAN))
calc_lanman_hash(tcon->password, ses->server->cryptkey,
ses->server->sec_mode &
SECMODE_PW_ENCRYPT ? true : false,
bcc_ptr);
else
#endif
rc = SMBNTencrypt(tcon->password, ses->server->cryptkey,
bcc_ptr);
bcc_ptr += CIFS_AUTH_RESP_SIZE;
if (ses->capabilities & CAP_UNICODE) {
*bcc_ptr = 0;
bcc_ptr++;
}
}
if (ses->server->sec_mode &
(SECMODE_SIGN_REQUIRED | SECMODE_SIGN_ENABLED))
smb_buffer->Flags2 |= SMBFLG2_SECURITY_SIGNATURE;
if (ses->capabilities & CAP_STATUS32) {
smb_buffer->Flags2 |= SMBFLG2_ERR_STATUS;
}
if (ses->capabilities & CAP_DFS) {
smb_buffer->Flags2 |= SMBFLG2_DFS;
}
if (ses->capabilities & CAP_UNICODE) {
smb_buffer->Flags2 |= SMBFLG2_UNICODE;
length =
cifs_strtoUCS((__le16 *) bcc_ptr, tree,
6 *
( + 256 ), nls_codepage);
bcc_ptr += 2 * length;
bcc_ptr += 2;
} else {
strcpy(bcc_ptr, tree);
bcc_ptr += strlen(tree) + 1;
}
strcpy(bcc_ptr, "?????");
bcc_ptr += strlen("?????");
bcc_ptr += 1;
count = bcc_ptr - &pSMB->Password[0];
pSMB->hdr.smb_buf_length = cpu_to_be32(be32_to_cpu(
pSMB->hdr.smb_buf_length) + count);
pSMB->ByteCount = cpu_to_le16(count);
rc = SendReceive(xid, ses, smb_buffer, smb_buffer_response, &length,
0);
if ((rc == 0) && (tcon != NULL)) {
bool is_unicode;
tcon->tidStatus = CifsGood;
tcon->need_reconnect = false;
tcon->tid = smb_buffer_response->Tid;
bcc_ptr = pByteArea(smb_buffer_response);
bytes_left = get_bcc(smb_buffer_response);
length = strnlen(bcc_ptr, bytes_left - 2);
if (smb_buffer->Flags2 & SMBFLG2_UNICODE)
is_unicode = true;
else
is_unicode = false;
if (length == 3) {
if ((bcc_ptr[0] == 'I') && (bcc_ptr[1] == 'P') &&
(bcc_ptr[2] == 'C')) {
cFYI(1, "IPC connection");
tcon->ipc = 1;
}
} else if (length == 2) {
if ((bcc_ptr[0] == 'A') && (bcc_ptr[1] == ':')) {
cFYI(1, "disk share connection");
}
}
bcc_ptr += length + 1;
bytes_left -= (length + 1);
strncpy(tcon->treeName, tree, MAX_TREE_SIZE);
kfree(tcon->nativeFileSystem);
tcon->nativeFileSystem = cifs_strndup_from_ucs(bcc_ptr,
bytes_left, is_unicode,
nls_codepage);
cFYI(1, "nativeFileSystem=%s", tcon->nativeFileSystem);
if ((smb_buffer_response->WordCount == 3) ||
(smb_buffer_response->WordCount == 7))
tcon->Flags = le16_to_cpu(pSMBr->OptionalSupport);
else
tcon->Flags = 0;
cFYI(1, "Tcon flags: 0x%x ", tcon->Flags);
} else if ((rc == 0) && tcon == NULL) {
ses->ipc_tid = smb_buffer_response->Tid;
}
cifs_buf_release(smb_buffer);
return rc;
}
void
cifs_umount(struct cifs_sb_info *cifs_sb)
{
struct rb_root *root = &cifs_sb->tlink_tree;
struct rb_node *node;
struct tcon_link *tlink;
cancel_delayed_work_sync(&cifs_sb->prune_tlinks);
spin_lock(&cifs_sb->tlink_tree_lock);
while ((node = rb_first(root))) {
tlink = rb_entry(node, struct tcon_link, tl_rbnode);
cifs_get_tlink(tlink);
clear_bit(TCON_LINK_IN_TREE, &tlink->tl_flags);
rb_erase(node, root);
spin_unlock(&cifs_sb->tlink_tree_lock);
cifs_put_tlink(tlink);
spin_lock(&cifs_sb->tlink_tree_lock);
}
spin_unlock(&cifs_sb->tlink_tree_lock);
bdi_destroy(&cifs_sb->bdi);
kfree(cifs_sb->mountdata);
unload_nls(cifs_sb->local_nls);
kfree(cifs_sb);
}
int cifs_negotiate_protocol(unsigned int xid, struct cifs_ses *ses)
{
int rc = 0;
struct TCP_Server_Info *server = ses->server;
if (server->maxBuf != 0)
return 0;
rc = CIFSSMBNegotiate(xid, ses);
if (rc == -EAGAIN) {
rc = CIFSSMBNegotiate(xid, ses);
if (rc == -EAGAIN)
rc = -EHOSTDOWN;
}
if (rc == 0) {
spin_lock(&GlobalMid_Lock);
if (server->tcpStatus == CifsNeedNegotiate)
server->tcpStatus = CifsGood;
else
rc = -EHOSTDOWN;
spin_unlock(&GlobalMid_Lock);
}
return rc;
}
int cifs_setup_session(unsigned int xid, struct cifs_ses *ses,
struct nls_table *nls_info)
{
int rc = 0;
struct TCP_Server_Info *server = ses->server;
ses->flags = 0;
ses->capabilities = server->capabilities;
if (linuxExtEnabled == 0)
ses->capabilities &= (~CAP_UNIX);
cFYI(1, "Security Mode: 0x%x Capabilities: 0x%x TimeAdjust: %d",
server->sec_mode, server->capabilities, server->timeAdj);
rc = CIFS_SessSetup(xid, ses, nls_info);
if (rc) {
cERROR(1, "Send error in SessSetup = %d", rc);
} else {
mutex_lock(&ses->server->srv_mutex);
if (!server->session_estab) {
server->session_key.response = ses->auth_key.response;
server->session_key.len = ses->auth_key.len;
server->sequence_number = 0x2;
server->session_estab = true;
ses->auth_key.response = NULL;
}
mutex_unlock(&server->srv_mutex);
cFYI(1, "CIFS Session Established successfully");
spin_lock(&GlobalMid_Lock);
ses->status = CifsGood;
ses->need_reconnect = false;
spin_unlock(&GlobalMid_Lock);
}
kfree(ses->auth_key.response);
ses->auth_key.response = NULL;
ses->auth_key.len = 0;
kfree(ses->ntlmssp);
ses->ntlmssp = NULL;
return rc;
}
static struct cifs_tcon *
cifs_construct_tcon(struct cifs_sb_info *cifs_sb, uid_t fsuid)
{
struct cifs_tcon *master_tcon = cifs_sb_master_tcon(cifs_sb);
struct cifs_ses *ses;
struct cifs_tcon *tcon = NULL;
struct smb_vol *vol_info;
char username[28];
vol_info = kzalloc(sizeof(*vol_info), GFP_KERNEL);
if (vol_info == NULL) {
tcon = ERR_PTR(-ENOMEM);
goto out;
}
snprintf(username, sizeof(username), "krb50x%x", fsuid);
vol_info->username = username;
vol_info->local_nls = cifs_sb->local_nls;
vol_info->linux_uid = fsuid;
vol_info->cred_uid = fsuid;
vol_info->UNC = master_tcon->treeName;
vol_info->retry = master_tcon->retry;
vol_info->nocase = master_tcon->nocase;
vol_info->local_lease = master_tcon->local_lease;
vol_info->no_linux_ext = !master_tcon->unix_ext;
vol_info->secFlg = CIFSSEC_MUST_KRB5;
spin_lock(&cifs_tcp_ses_lock);
++master_tcon->ses->server->srv_count;
spin_unlock(&cifs_tcp_ses_lock);
ses = cifs_get_smb_ses(master_tcon->ses->server, vol_info);
if (IS_ERR(ses)) {
tcon = (struct cifs_tcon *)ses;
cifs_put_tcp_session(master_tcon->ses->server);
goto out;
}
tcon = cifs_get_tcon(ses, vol_info);
if (IS_ERR(tcon)) {
cifs_put_smb_ses(ses);
goto out;
}
if (ses->capabilities & CAP_UNIX)
reset_cifs_unix_caps(0, tcon, NULL, vol_info);
out:
kfree(vol_info);
return tcon;
}
struct cifs_tcon *
cifs_sb_master_tcon(struct cifs_sb_info *cifs_sb)
{
return tlink_tcon(cifs_sb_master_tlink(cifs_sb));
}
static int
cifs_sb_tcon_pending_wait(void *unused)
{
schedule();
return signal_pending(current) ? -ERESTARTSYS : 0;
}
static struct tcon_link *
tlink_rb_search(struct rb_root *root, uid_t uid)
{
struct rb_node *node = root->rb_node;
struct tcon_link *tlink;
while (node) {
tlink = rb_entry(node, struct tcon_link, tl_rbnode);
if (tlink->tl_uid > uid)
node = node->rb_left;
else if (tlink->tl_uid < uid)
node = node->rb_right;
else
return tlink;
}
return NULL;
}
static void
tlink_rb_insert(struct rb_root *root, struct tcon_link *new_tlink)
{
struct rb_node **new = &(root->rb_node), *parent = NULL;
struct tcon_link *tlink;
while (*new) {
tlink = rb_entry(*new, struct tcon_link, tl_rbnode);
parent = *new;
if (tlink->tl_uid > new_tlink->tl_uid)
new = &((*new)->rb_left);
else
new = &((*new)->rb_right);
}
rb_link_node(&new_tlink->tl_rbnode, parent, new);
rb_insert_color(&new_tlink->tl_rbnode, root);
}
struct tcon_link *
cifs_sb_tlink(struct cifs_sb_info *cifs_sb)
{
int ret;
uid_t fsuid = current_fsuid();
struct tcon_link *tlink, *newtlink;
if (!(cifs_sb->mnt_cifs_flags & CIFS_MOUNT_MULTIUSER))
return cifs_get_tlink(cifs_sb_master_tlink(cifs_sb));
spin_lock(&cifs_sb->tlink_tree_lock);
tlink = tlink_rb_search(&cifs_sb->tlink_tree, fsuid);
if (tlink)
cifs_get_tlink(tlink);
spin_unlock(&cifs_sb->tlink_tree_lock);
if (tlink == NULL) {
newtlink = kzalloc(sizeof(*tlink), GFP_KERNEL);
if (newtlink == NULL)
return ERR_PTR(-ENOMEM);
newtlink->tl_uid = fsuid;
newtlink->tl_tcon = ERR_PTR(-EACCES);
set_bit(TCON_LINK_PENDING, &newtlink->tl_flags);
set_bit(TCON_LINK_IN_TREE, &newtlink->tl_flags);
cifs_get_tlink(newtlink);
spin_lock(&cifs_sb->tlink_tree_lock);
tlink = tlink_rb_search(&cifs_sb->tlink_tree, fsuid);
if (tlink) {
cifs_get_tlink(tlink);
spin_unlock(&cifs_sb->tlink_tree_lock);
kfree(newtlink);
goto wait_for_construction;
}
tlink = newtlink;
tlink_rb_insert(&cifs_sb->tlink_tree, tlink);
spin_unlock(&cifs_sb->tlink_tree_lock);
} else {
wait_for_construction:
ret = wait_on_bit(&tlink->tl_flags, TCON_LINK_PENDING,
cifs_sb_tcon_pending_wait,
TASK_INTERRUPTIBLE);
if (ret) {
cifs_put_tlink(tlink);
return ERR_PTR(ret);
}
if (!IS_ERR(tlink->tl_tcon))
return tlink;
if (time_before(jiffies, tlink->tl_time + TLINK_ERROR_EXPIRE)) {
cifs_put_tlink(tlink);
return ERR_PTR(-EACCES);
}
if (test_and_set_bit(TCON_LINK_PENDING, &tlink->tl_flags))
goto wait_for_construction;
}
tlink->tl_tcon = cifs_construct_tcon(cifs_sb, fsuid);
clear_bit(TCON_LINK_PENDING, &tlink->tl_flags);
wake_up_bit(&tlink->tl_flags, TCON_LINK_PENDING);
if (IS_ERR(tlink->tl_tcon)) {
cifs_put_tlink(tlink);
return ERR_PTR(-EACCES);
}
return tlink;
}
static void
cifs_prune_tlinks(struct work_struct *work)
{
struct cifs_sb_info *cifs_sb = container_of(work, struct cifs_sb_info,
prune_tlinks.work);
struct rb_root *root = &cifs_sb->tlink_tree;
struct rb_node *node = rb_first(root);
struct rb_node *tmp;
struct tcon_link *tlink;
spin_lock(&cifs_sb->tlink_tree_lock);
node = rb_first(root);
while (node != NULL) {
tmp = node;
node = rb_next(tmp);
tlink = rb_entry(tmp, struct tcon_link, tl_rbnode);
if (test_bit(TCON_LINK_MASTER, &tlink->tl_flags) ||
atomic_read(&tlink->tl_count) != 0 ||
time_after(tlink->tl_time + TLINK_IDLE_EXPIRE, jiffies))
continue;
cifs_get_tlink(tlink);
clear_bit(TCON_LINK_IN_TREE, &tlink->tl_flags);
rb_erase(tmp, root);
spin_unlock(&cifs_sb->tlink_tree_lock);
cifs_put_tlink(tlink);
spin_lock(&cifs_sb->tlink_tree_lock);
}
spin_unlock(&cifs_sb->tlink_tree_lock);
queue_delayed_work(system_nrt_wq, &cifs_sb->prune_tlinks,
TLINK_IDLE_EXPIRE);
}
