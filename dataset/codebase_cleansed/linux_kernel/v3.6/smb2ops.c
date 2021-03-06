static int
change_conf(struct TCP_Server_Info *server)
{
server->credits += server->echo_credits + server->oplock_credits;
server->oplock_credits = server->echo_credits = 0;
switch (server->credits) {
case 0:
return -1;
case 1:
server->echoes = false;
server->oplocks = false;
cERROR(1, "disabling echoes and oplocks");
break;
case 2:
server->echoes = true;
server->oplocks = false;
server->echo_credits = 1;
cFYI(1, "disabling oplocks");
break;
default:
server->echoes = true;
server->oplocks = true;
server->echo_credits = 1;
server->oplock_credits = 1;
}
server->credits -= server->echo_credits + server->oplock_credits;
return 0;
}
static void
smb2_add_credits(struct TCP_Server_Info *server, const unsigned int add,
const int optype)
{
int *val, rc = 0;
spin_lock(&server->req_lock);
val = server->ops->get_credits_field(server, optype);
*val += add;
server->in_flight--;
if (server->in_flight == 0 && (optype & CIFS_OP_MASK) != CIFS_NEG_OP)
rc = change_conf(server);
spin_unlock(&server->req_lock);
wake_up(&server->request_q);
if (rc)
cifs_reconnect(server);
}
static void
smb2_set_credits(struct TCP_Server_Info *server, const int val)
{
spin_lock(&server->req_lock);
server->credits = val;
spin_unlock(&server->req_lock);
}
static int *
smb2_get_credits_field(struct TCP_Server_Info *server, const int optype)
{
switch (optype) {
case CIFS_ECHO_OP:
return &server->echo_credits;
case CIFS_OBREAK_OP:
return &server->oplock_credits;
default:
return &server->credits;
}
}
static unsigned int
smb2_get_credits(struct mid_q_entry *mid)
{
return le16_to_cpu(((struct smb2_hdr *)mid->resp_buf)->CreditRequest);
}
static __u64
smb2_get_next_mid(struct TCP_Server_Info *server)
{
__u64 mid;
spin_lock(&GlobalMid_Lock);
mid = server->CurrentMid++;
spin_unlock(&GlobalMid_Lock);
return mid;
}
static struct mid_q_entry *
smb2_find_mid(struct TCP_Server_Info *server, char *buf)
{
struct mid_q_entry *mid;
struct smb2_hdr *hdr = (struct smb2_hdr *)buf;
spin_lock(&GlobalMid_Lock);
list_for_each_entry(mid, &server->pending_mid_q, qhead) {
if ((mid->mid == hdr->MessageId) &&
(mid->mid_state == MID_REQUEST_SUBMITTED) &&
(mid->command == hdr->Command)) {
spin_unlock(&GlobalMid_Lock);
return mid;
}
}
spin_unlock(&GlobalMid_Lock);
return NULL;
}
static void
smb2_dump_detail(void *buf)
{
#ifdef CONFIG_CIFS_DEBUG2
struct smb2_hdr *smb = (struct smb2_hdr *)buf;
cERROR(1, "Cmd: %d Err: 0x%x Flags: 0x%x Mid: %llu Pid: %d",
smb->Command, smb->Status, smb->Flags, smb->MessageId,
smb->ProcessId);
cERROR(1, "smb buf %p len %u", smb, smb2_calc_size(smb));
#endif
}
static bool
smb2_need_neg(struct TCP_Server_Info *server)
{
return server->max_read == 0;
}
static int
smb2_negotiate(const unsigned int xid, struct cifs_ses *ses)
{
int rc;
ses->server->CurrentMid = 0;
rc = SMB2_negotiate(xid, ses);
if (rc == -EAGAIN)
rc = -EHOSTDOWN;
return rc;
}
static int
smb2_is_path_accessible(const unsigned int xid, struct cifs_tcon *tcon,
struct cifs_sb_info *cifs_sb, const char *full_path)
{
int rc;
__u64 persistent_fid, volatile_fid;
__le16 *utf16_path;
utf16_path = cifs_convert_path_to_utf16(full_path, cifs_sb);
if (!utf16_path)
return -ENOMEM;
rc = SMB2_open(xid, tcon, utf16_path, &persistent_fid, &volatile_fid,
FILE_READ_ATTRIBUTES, FILE_OPEN, 0, 0);
if (rc) {
kfree(utf16_path);
return rc;
}
rc = SMB2_close(xid, tcon, persistent_fid, volatile_fid);
kfree(utf16_path);
return rc;
}
static int
smb2_get_srv_inum(const unsigned int xid, struct cifs_tcon *tcon,
struct cifs_sb_info *cifs_sb, const char *full_path,
u64 *uniqueid, FILE_ALL_INFO *data)
{
*uniqueid = le64_to_cpu(data->IndexNumber);
return 0;
}
static char *
smb2_build_path_to_root(struct smb_vol *vol, struct cifs_sb_info *cifs_sb,
struct cifs_tcon *tcon)
{
int pplen = vol->prepath ? strlen(vol->prepath) : 0;
char *full_path = NULL;
if (pplen == 0) {
full_path = kzalloc(2, GFP_KERNEL);
return full_path;
}
cERROR(1, "prefixpath is not supported for SMB2 now");
return NULL;
}
static bool
smb2_can_echo(struct TCP_Server_Info *server)
{
return server->echoes;
}
static void
smb2_clear_stats(struct cifs_tcon *tcon)
{
#ifdef CONFIG_CIFS_STATS
int i;
for (i = 0; i < NUMBER_OF_SMB2_COMMANDS; i++) {
atomic_set(&tcon->stats.smb2_stats.smb2_com_sent[i], 0);
atomic_set(&tcon->stats.smb2_stats.smb2_com_failed[i], 0);
}
#endif
}
static void
smb2_print_stats(struct seq_file *m, struct cifs_tcon *tcon)
{
#ifdef CONFIG_CIFS_STATS
atomic_t *sent = tcon->stats.smb2_stats.smb2_com_sent;
atomic_t *failed = tcon->stats.smb2_stats.smb2_com_failed;
seq_printf(m, "\nNegotiates: %d sent %d failed",
atomic_read(&sent[SMB2_NEGOTIATE_HE]),
atomic_read(&failed[SMB2_NEGOTIATE_HE]));
seq_printf(m, "\nSessionSetups: %d sent %d failed",
atomic_read(&sent[SMB2_SESSION_SETUP_HE]),
atomic_read(&failed[SMB2_SESSION_SETUP_HE]));
#define SMB2LOGOFF 0x0002
seq_printf(m, "\nLogoffs: %d sent %d failed",
atomic_read(&sent[SMB2_LOGOFF_HE]),
atomic_read(&failed[SMB2_LOGOFF_HE]));
seq_printf(m, "\nTreeConnects: %d sent %d failed",
atomic_read(&sent[SMB2_TREE_CONNECT_HE]),
atomic_read(&failed[SMB2_TREE_CONNECT_HE]));
seq_printf(m, "\nTreeDisconnects: %d sent %d failed",
atomic_read(&sent[SMB2_TREE_DISCONNECT_HE]),
atomic_read(&failed[SMB2_TREE_DISCONNECT_HE]));
seq_printf(m, "\nCreates: %d sent %d failed",
atomic_read(&sent[SMB2_CREATE_HE]),
atomic_read(&failed[SMB2_CREATE_HE]));
seq_printf(m, "\nCloses: %d sent %d failed",
atomic_read(&sent[SMB2_CLOSE_HE]),
atomic_read(&failed[SMB2_CLOSE_HE]));
seq_printf(m, "\nFlushes: %d sent %d failed",
atomic_read(&sent[SMB2_FLUSH_HE]),
atomic_read(&failed[SMB2_FLUSH_HE]));
seq_printf(m, "\nReads: %d sent %d failed",
atomic_read(&sent[SMB2_READ_HE]),
atomic_read(&failed[SMB2_READ_HE]));
seq_printf(m, "\nWrites: %d sent %d failed",
atomic_read(&sent[SMB2_WRITE_HE]),
atomic_read(&failed[SMB2_WRITE_HE]));
seq_printf(m, "\nLocks: %d sent %d failed",
atomic_read(&sent[SMB2_LOCK_HE]),
atomic_read(&failed[SMB2_LOCK_HE]));
seq_printf(m, "\nIOCTLs: %d sent %d failed",
atomic_read(&sent[SMB2_IOCTL_HE]),
atomic_read(&failed[SMB2_IOCTL_HE]));
seq_printf(m, "\nCancels: %d sent %d failed",
atomic_read(&sent[SMB2_CANCEL_HE]),
atomic_read(&failed[SMB2_CANCEL_HE]));
seq_printf(m, "\nEchos: %d sent %d failed",
atomic_read(&sent[SMB2_ECHO_HE]),
atomic_read(&failed[SMB2_ECHO_HE]));
seq_printf(m, "\nQueryDirectories: %d sent %d failed",
atomic_read(&sent[SMB2_QUERY_DIRECTORY_HE]),
atomic_read(&failed[SMB2_QUERY_DIRECTORY_HE]));
seq_printf(m, "\nChangeNotifies: %d sent %d failed",
atomic_read(&sent[SMB2_CHANGE_NOTIFY_HE]),
atomic_read(&failed[SMB2_CHANGE_NOTIFY_HE]));
seq_printf(m, "\nQueryInfos: %d sent %d failed",
atomic_read(&sent[SMB2_QUERY_INFO_HE]),
atomic_read(&failed[SMB2_QUERY_INFO_HE]));
seq_printf(m, "\nSetInfos: %d sent %d failed",
atomic_read(&sent[SMB2_SET_INFO_HE]),
atomic_read(&failed[SMB2_SET_INFO_HE]));
seq_printf(m, "\nOplockBreaks: %d sent %d failed",
atomic_read(&sent[SMB2_OPLOCK_BREAK_HE]),
atomic_read(&failed[SMB2_OPLOCK_BREAK_HE]));
#endif
}
