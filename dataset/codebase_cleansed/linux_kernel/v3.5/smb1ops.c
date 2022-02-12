static int
send_nt_cancel(struct TCP_Server_Info *server, void *buf,
struct mid_q_entry *mid)
{
int rc = 0;
struct smb_hdr *in_buf = (struct smb_hdr *)buf;
in_buf->smb_buf_length = cpu_to_be32(sizeof(struct smb_hdr) - 4 + 2);
in_buf->Command = SMB_COM_NT_CANCEL;
in_buf->WordCount = 0;
put_bcc(0, in_buf);
mutex_lock(&server->srv_mutex);
rc = cifs_sign_smb(in_buf, server, &mid->sequence_number);
if (rc) {
mutex_unlock(&server->srv_mutex);
return rc;
}
rc = smb_send(server, in_buf, be32_to_cpu(in_buf->smb_buf_length));
mutex_unlock(&server->srv_mutex);
cFYI(1, "issued NT_CANCEL for mid %u, rc = %d",
in_buf->Mid, rc);
return rc;
}
static bool
cifs_compare_fids(struct cifsFileInfo *ob1, struct cifsFileInfo *ob2)
{
return ob1->netfid == ob2->netfid;
}
static unsigned int
cifs_read_data_offset(char *buf)
{
READ_RSP *rsp = (READ_RSP *)buf;
return le16_to_cpu(rsp->DataOffset);
}
static unsigned int
cifs_read_data_length(char *buf)
{
READ_RSP *rsp = (READ_RSP *)buf;
return (le16_to_cpu(rsp->DataLengthHigh) << 16) +
le16_to_cpu(rsp->DataLength);
}
static struct mid_q_entry *
cifs_find_mid(struct TCP_Server_Info *server, char *buffer)
{
struct smb_hdr *buf = (struct smb_hdr *)buffer;
struct mid_q_entry *mid;
spin_lock(&GlobalMid_Lock);
list_for_each_entry(mid, &server->pending_mid_q, qhead) {
if (mid->mid == buf->Mid &&
mid->mid_state == MID_REQUEST_SUBMITTED &&
le16_to_cpu(mid->command) == buf->Command) {
spin_unlock(&GlobalMid_Lock);
return mid;
}
}
spin_unlock(&GlobalMid_Lock);
return NULL;
}
static void
cifs_add_credits(struct TCP_Server_Info *server, const unsigned int add)
{
spin_lock(&server->req_lock);
server->credits += add;
server->in_flight--;
spin_unlock(&server->req_lock);
wake_up(&server->request_q);
}
static void
cifs_set_credits(struct TCP_Server_Info *server, const int val)
{
spin_lock(&server->req_lock);
server->credits = val;
server->oplocks = val > 1 ? enable_oplocks : false;
spin_unlock(&server->req_lock);
}
static int *
cifs_get_credits_field(struct TCP_Server_Info *server)
{
return &server->credits;
}
static __u64
cifs_get_next_mid(struct TCP_Server_Info *server)
{
__u64 mid = 0;
__u16 last_mid, cur_mid;
bool collision;
spin_lock(&GlobalMid_Lock);
cur_mid = (__u16)((server->CurrentMid) & 0xffff);
last_mid = cur_mid;
cur_mid++;
while (cur_mid != last_mid) {
struct mid_q_entry *mid_entry;
unsigned int num_mids;
collision = false;
if (cur_mid == 0)
cur_mid++;
num_mids = 0;
list_for_each_entry(mid_entry, &server->pending_mid_q, qhead) {
++num_mids;
if (mid_entry->mid == cur_mid &&
mid_entry->mid_state == MID_REQUEST_SUBMITTED) {
collision = true;
break;
}
}
if (num_mids > 32768)
server->tcpStatus = CifsNeedReconnect;
if (!collision) {
mid = (__u64)cur_mid;
server->CurrentMid = mid;
break;
}
cur_mid++;
}
spin_unlock(&GlobalMid_Lock);
return mid;
}
