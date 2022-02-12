static inline void
smb2_seq_num_into_buf(struct TCP_Server_Info *server, struct smb2_hdr *hdr)
{
hdr->MessageId = get_next_mid(server);
}
static struct mid_q_entry *
smb2_mid_entry_alloc(const struct smb2_hdr *smb_buffer,
struct TCP_Server_Info *server)
{
struct mid_q_entry *temp;
if (server == NULL) {
cERROR(1, "Null TCP session in smb2_mid_entry_alloc");
return NULL;
}
temp = mempool_alloc(cifs_mid_poolp, GFP_NOFS);
if (temp == NULL)
return temp;
else {
memset(temp, 0, sizeof(struct mid_q_entry));
temp->mid = smb_buffer->MessageId;
temp->pid = current->pid;
temp->command = smb_buffer->Command;
temp->when_alloc = jiffies;
temp->server = server;
temp->callback = cifs_wake_up_task;
temp->callback_data = current;
}
atomic_inc(&midCount);
temp->mid_state = MID_REQUEST_ALLOCATED;
return temp;
}
static int
smb2_get_mid_entry(struct cifs_ses *ses, struct smb2_hdr *buf,
struct mid_q_entry **mid)
{
if (ses->server->tcpStatus == CifsExiting)
return -ENOENT;
if (ses->server->tcpStatus == CifsNeedReconnect) {
cFYI(1, "tcp session dead - return to caller to retry");
return -EAGAIN;
}
if (ses->status != CifsGood) {
if ((buf->Command != SMB2_SESSION_SETUP) &&
(buf->Command != SMB2_NEGOTIATE))
return -EAGAIN;
}
*mid = smb2_mid_entry_alloc(buf, ses->server);
if (*mid == NULL)
return -ENOMEM;
spin_lock(&GlobalMid_Lock);
list_add_tail(&(*mid)->qhead, &ses->server->pending_mid_q);
spin_unlock(&GlobalMid_Lock);
return 0;
}
int
smb2_check_receive(struct mid_q_entry *mid, struct TCP_Server_Info *server,
bool log_error)
{
unsigned int len = get_rfc1002_length(mid->resp_buf);
dump_smb(mid->resp_buf, min_t(u32, 80, len));
return map_smb2_to_linux_error(mid->resp_buf, log_error);
}
int
smb2_setup_request(struct cifs_ses *ses, struct kvec *iov,
unsigned int nvec, struct mid_q_entry **ret_mid)
{
int rc;
struct smb2_hdr *hdr = (struct smb2_hdr *)iov[0].iov_base;
struct mid_q_entry *mid;
smb2_seq_num_into_buf(ses->server, hdr);
rc = smb2_get_mid_entry(ses, hdr, &mid);
if (rc)
return rc;
*ret_mid = mid;
return rc;
}
int
smb2_setup_async_request(struct TCP_Server_Info *server, struct kvec *iov,
unsigned int nvec, struct mid_q_entry **ret_mid)
{
int rc = 0;
struct smb2_hdr *hdr = (struct smb2_hdr *)iov[0].iov_base;
struct mid_q_entry *mid;
smb2_seq_num_into_buf(server, hdr);
mid = smb2_mid_entry_alloc(hdr, server);
if (mid == NULL)
return -ENOMEM;
*ret_mid = mid;
return rc;
}
