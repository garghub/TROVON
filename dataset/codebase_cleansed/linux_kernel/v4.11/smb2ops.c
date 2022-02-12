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
cifs_dbg(VFS, "disabling echoes and oplocks\n");
break;
case 2:
server->echoes = true;
server->oplocks = false;
server->echo_credits = 1;
cifs_dbg(FYI, "disabling oplocks\n");
break;
default:
server->echoes = true;
if (enable_oplocks) {
server->oplocks = true;
server->oplock_credits = 1;
} else
server->oplocks = false;
server->echo_credits = 1;
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
if (*val > 65000) {
*val = 65000;
printk_once(KERN_WARNING "server overflowed SMB3 credits\n");
}
server->in_flight--;
if (server->in_flight == 0 && (optype & CIFS_OP_MASK) != CIFS_NEG_OP)
rc = change_conf(server);
else if (server->in_flight > 0 && server->oplock_credits == 0 &&
server->oplocks) {
if (server->credits > 1) {
server->credits--;
server->oplock_credits++;
}
}
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
struct smb2_sync_hdr *shdr = get_sync_hdr(mid->resp_buf);
return le16_to_cpu(shdr->CreditRequest);
}
static int
smb2_wait_mtu_credits(struct TCP_Server_Info *server, unsigned int size,
unsigned int *num, unsigned int *credits)
{
int rc = 0;
unsigned int scredits;
spin_lock(&server->req_lock);
while (1) {
if (server->credits <= 0) {
spin_unlock(&server->req_lock);
cifs_num_waiters_inc(server);
rc = wait_event_killable(server->request_q,
has_credits(server, &server->credits));
cifs_num_waiters_dec(server);
if (rc)
return rc;
spin_lock(&server->req_lock);
} else {
if (server->tcpStatus == CifsExiting) {
spin_unlock(&server->req_lock);
return -ENOENT;
}
scredits = server->credits;
if (scredits == 1) {
*num = SMB2_MAX_BUFFER_SIZE;
*credits = 0;
break;
}
scredits--;
*num = min_t(unsigned int, size,
scredits * SMB2_MAX_BUFFER_SIZE);
*credits = DIV_ROUND_UP(*num, SMB2_MAX_BUFFER_SIZE);
server->credits -= *credits;
server->in_flight++;
break;
}
}
spin_unlock(&server->req_lock);
return rc;
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
struct smb2_sync_hdr *shdr = get_sync_hdr(buf);
__u64 wire_mid = le64_to_cpu(shdr->MessageId);
if (shdr->ProtocolId == SMB2_TRANSFORM_PROTO_NUM) {
cifs_dbg(VFS, "encrypted frame parsing not supported yet");
return NULL;
}
spin_lock(&GlobalMid_Lock);
list_for_each_entry(mid, &server->pending_mid_q, qhead) {
if ((mid->mid == wire_mid) &&
(mid->mid_state == MID_REQUEST_SUBMITTED) &&
(mid->command == shdr->Command)) {
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
struct smb2_sync_hdr *shdr = get_sync_hdr(buf);
cifs_dbg(VFS, "Cmd: %d Err: 0x%x Flags: 0x%x Mid: %llu Pid: %d\n",
shdr->Command, shdr->Status, shdr->Flags, shdr->MessageId,
shdr->ProcessId);
cifs_dbg(VFS, "smb buf %p len %u\n", buf, smb2_calc_size(buf));
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
static unsigned int
smb2_negotiate_wsize(struct cifs_tcon *tcon, struct smb_vol *volume_info)
{
struct TCP_Server_Info *server = tcon->ses->server;
unsigned int wsize;
wsize = volume_info->wsize ? volume_info->wsize : CIFS_DEFAULT_IOSIZE;
wsize = min_t(unsigned int, wsize, server->max_write);
if (!(server->capabilities & SMB2_GLOBAL_CAP_LARGE_MTU))
wsize = min_t(unsigned int, wsize, SMB2_MAX_BUFFER_SIZE);
return wsize;
}
static unsigned int
smb2_negotiate_rsize(struct cifs_tcon *tcon, struct smb_vol *volume_info)
{
struct TCP_Server_Info *server = tcon->ses->server;
unsigned int rsize;
rsize = volume_info->rsize ? volume_info->rsize : CIFS_DEFAULT_IOSIZE;
rsize = min_t(unsigned int, rsize, server->max_read);
if (!(server->capabilities & SMB2_GLOBAL_CAP_LARGE_MTU))
rsize = min_t(unsigned int, rsize, SMB2_MAX_BUFFER_SIZE);
return rsize;
}
static int
SMB3_request_interfaces(const unsigned int xid, struct cifs_tcon *tcon)
{
int rc;
unsigned int ret_data_len = 0;
struct network_interface_info_ioctl_rsp *out_buf;
rc = SMB2_ioctl(xid, tcon, NO_FILE_ID, NO_FILE_ID,
FSCTL_QUERY_NETWORK_INTERFACE_INFO, true ,
false ,
NULL , 0 ,
(char **)&out_buf, &ret_data_len);
if (rc != 0)
cifs_dbg(VFS, "error %d on ioctl to get interface list\n", rc);
else if (ret_data_len < sizeof(struct network_interface_info_ioctl_rsp)) {
cifs_dbg(VFS, "server returned bad net interface info buf\n");
rc = -EINVAL;
} else {
cifs_dbg(FYI, "Adapter Capability 0x%x\t",
le32_to_cpu(out_buf->Capability));
cifs_dbg(FYI, "Link Speed %lld\n",
le64_to_cpu(out_buf->LinkSpeed));
}
kfree(out_buf);
return rc;
}
static void
smb3_qfs_tcon(const unsigned int xid, struct cifs_tcon *tcon)
{
int rc;
__le16 srch_path = 0;
u8 oplock = SMB2_OPLOCK_LEVEL_NONE;
struct cifs_open_parms oparms;
struct cifs_fid fid;
oparms.tcon = tcon;
oparms.desired_access = FILE_READ_ATTRIBUTES;
oparms.disposition = FILE_OPEN;
oparms.create_options = 0;
oparms.fid = &fid;
oparms.reconnect = false;
rc = SMB2_open(xid, &oparms, &srch_path, &oplock, NULL, NULL);
if (rc)
return;
#ifdef CONFIG_CIFS_STATS2
SMB3_request_interfaces(xid, tcon);
#endif
SMB2_QFS_attr(xid, tcon, fid.persistent_fid, fid.volatile_fid,
FS_ATTRIBUTE_INFORMATION);
SMB2_QFS_attr(xid, tcon, fid.persistent_fid, fid.volatile_fid,
FS_DEVICE_INFORMATION);
SMB2_QFS_attr(xid, tcon, fid.persistent_fid, fid.volatile_fid,
FS_SECTOR_SIZE_INFORMATION);
SMB2_close(xid, tcon, fid.persistent_fid, fid.volatile_fid);
return;
}
static void
smb2_qfs_tcon(const unsigned int xid, struct cifs_tcon *tcon)
{
int rc;
__le16 srch_path = 0;
u8 oplock = SMB2_OPLOCK_LEVEL_NONE;
struct cifs_open_parms oparms;
struct cifs_fid fid;
oparms.tcon = tcon;
oparms.desired_access = FILE_READ_ATTRIBUTES;
oparms.disposition = FILE_OPEN;
oparms.create_options = 0;
oparms.fid = &fid;
oparms.reconnect = false;
rc = SMB2_open(xid, &oparms, &srch_path, &oplock, NULL, NULL);
if (rc)
return;
SMB2_QFS_attr(xid, tcon, fid.persistent_fid, fid.volatile_fid,
FS_ATTRIBUTE_INFORMATION);
SMB2_QFS_attr(xid, tcon, fid.persistent_fid, fid.volatile_fid,
FS_DEVICE_INFORMATION);
SMB2_close(xid, tcon, fid.persistent_fid, fid.volatile_fid);
return;
}
static int
smb2_is_path_accessible(const unsigned int xid, struct cifs_tcon *tcon,
struct cifs_sb_info *cifs_sb, const char *full_path)
{
int rc;
__le16 *utf16_path;
__u8 oplock = SMB2_OPLOCK_LEVEL_NONE;
struct cifs_open_parms oparms;
struct cifs_fid fid;
utf16_path = cifs_convert_path_to_utf16(full_path, cifs_sb);
if (!utf16_path)
return -ENOMEM;
oparms.tcon = tcon;
oparms.desired_access = FILE_READ_ATTRIBUTES;
oparms.disposition = FILE_OPEN;
oparms.create_options = 0;
oparms.fid = &fid;
oparms.reconnect = false;
rc = SMB2_open(xid, &oparms, utf16_path, &oplock, NULL, NULL);
if (rc) {
kfree(utf16_path);
return rc;
}
rc = SMB2_close(xid, tcon, fid.persistent_fid, fid.volatile_fid);
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
static int
smb2_query_file_info(const unsigned int xid, struct cifs_tcon *tcon,
struct cifs_fid *fid, FILE_ALL_INFO *data)
{
int rc;
struct smb2_file_all_info *smb2_data;
smb2_data = kzalloc(sizeof(struct smb2_file_all_info) + PATH_MAX * 2,
GFP_KERNEL);
if (smb2_data == NULL)
return -ENOMEM;
rc = SMB2_query_info(xid, tcon, fid->persistent_fid, fid->volatile_fid,
smb2_data);
if (!rc)
move_smb2_info_to_cifs(data, smb2_data);
kfree(smb2_data);
return rc;
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
smb2_dump_share_caps(struct seq_file *m, struct cifs_tcon *tcon)
{
seq_puts(m, "\n\tShare Capabilities:");
if (tcon->capabilities & SMB2_SHARE_CAP_DFS)
seq_puts(m, " DFS,");
if (tcon->capabilities & SMB2_SHARE_CAP_CONTINUOUS_AVAILABILITY)
seq_puts(m, " CONTINUOUS AVAILABILITY,");
if (tcon->capabilities & SMB2_SHARE_CAP_SCALEOUT)
seq_puts(m, " SCALEOUT,");
if (tcon->capabilities & SMB2_SHARE_CAP_CLUSTER)
seq_puts(m, " CLUSTER,");
if (tcon->capabilities & SMB2_SHARE_CAP_ASYMMETRIC)
seq_puts(m, " ASYMMETRIC,");
if (tcon->capabilities == 0)
seq_puts(m, " None");
if (tcon->ss_flags & SSINFO_FLAGS_ALIGNED_DEVICE)
seq_puts(m, " Aligned,");
if (tcon->ss_flags & SSINFO_FLAGS_PARTITION_ALIGNED_ON_DEVICE)
seq_puts(m, " Partition Aligned,");
if (tcon->ss_flags & SSINFO_FLAGS_NO_SEEK_PENALTY)
seq_puts(m, " SSD,");
if (tcon->ss_flags & SSINFO_FLAGS_TRIM_ENABLED)
seq_puts(m, " TRIM-support,");
seq_printf(m, "\tShare Flags: 0x%x", tcon->share_flags);
if (tcon->perf_sector_size)
seq_printf(m, "\tOptimal sector size: 0x%x",
tcon->perf_sector_size);
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
static void
smb2_set_fid(struct cifsFileInfo *cfile, struct cifs_fid *fid, __u32 oplock)
{
struct cifsInodeInfo *cinode = CIFS_I(d_inode(cfile->dentry));
struct TCP_Server_Info *server = tlink_tcon(cfile->tlink)->ses->server;
cfile->fid.persistent_fid = fid->persistent_fid;
cfile->fid.volatile_fid = fid->volatile_fid;
server->ops->set_oplock_level(cinode, oplock, fid->epoch,
&fid->purge_cache);
cinode->can_cache_brlcks = CIFS_CACHE_WRITE(cinode);
memcpy(cfile->fid.create_guid, fid->create_guid, 16);
}
static void
smb2_close_file(const unsigned int xid, struct cifs_tcon *tcon,
struct cifs_fid *fid)
{
SMB2_close(xid, tcon, fid->persistent_fid, fid->volatile_fid);
}
static int
SMB2_request_res_key(const unsigned int xid, struct cifs_tcon *tcon,
u64 persistent_fid, u64 volatile_fid,
struct copychunk_ioctl *pcchunk)
{
int rc;
unsigned int ret_data_len;
struct resume_key_req *res_key;
rc = SMB2_ioctl(xid, tcon, persistent_fid, volatile_fid,
FSCTL_SRV_REQUEST_RESUME_KEY, true ,
false ,
NULL, 0 ,
(char **)&res_key, &ret_data_len);
if (rc) {
cifs_dbg(VFS, "refcpy ioctl error %d getting resume key\n", rc);
goto req_res_key_exit;
}
if (ret_data_len < sizeof(struct resume_key_req)) {
cifs_dbg(VFS, "Invalid refcopy resume key length\n");
rc = -EINVAL;
goto req_res_key_exit;
}
memcpy(pcchunk->SourceKey, res_key->ResumeKey, COPY_CHUNK_RES_KEY_SIZE);
req_res_key_exit:
kfree(res_key);
return rc;
}
static ssize_t
smb2_copychunk_range(const unsigned int xid,
struct cifsFileInfo *srcfile,
struct cifsFileInfo *trgtfile, u64 src_off,
u64 len, u64 dest_off)
{
int rc;
unsigned int ret_data_len;
struct copychunk_ioctl *pcchunk;
struct copychunk_ioctl_rsp *retbuf = NULL;
struct cifs_tcon *tcon;
int chunks_copied = 0;
bool chunk_sizes_updated = false;
ssize_t bytes_written, total_bytes_written = 0;
pcchunk = kmalloc(sizeof(struct copychunk_ioctl), GFP_KERNEL);
if (pcchunk == NULL)
return -ENOMEM;
cifs_dbg(FYI, "in smb2_copychunk_range - about to call request res key\n");
rc = SMB2_request_res_key(xid, tlink_tcon(srcfile->tlink),
srcfile->fid.persistent_fid,
srcfile->fid.volatile_fid, pcchunk);
if (rc)
goto cchunk_out;
pcchunk->ChunkCount = cpu_to_le32(1);
pcchunk->Reserved = 0;
pcchunk->Reserved2 = 0;
tcon = tlink_tcon(trgtfile->tlink);
while (len > 0) {
pcchunk->SourceOffset = cpu_to_le64(src_off);
pcchunk->TargetOffset = cpu_to_le64(dest_off);
pcchunk->Length =
cpu_to_le32(min_t(u32, len, tcon->max_bytes_chunk));
rc = SMB2_ioctl(xid, tcon, trgtfile->fid.persistent_fid,
trgtfile->fid.volatile_fid, FSCTL_SRV_COPYCHUNK_WRITE,
true , false ,
(char *)pcchunk,
sizeof(struct copychunk_ioctl), (char **)&retbuf,
&ret_data_len);
if (rc == 0) {
if (ret_data_len !=
sizeof(struct copychunk_ioctl_rsp)) {
cifs_dbg(VFS, "invalid cchunk response size\n");
rc = -EIO;
goto cchunk_out;
}
if (retbuf->TotalBytesWritten == 0) {
cifs_dbg(FYI, "no bytes copied\n");
rc = -EIO;
goto cchunk_out;
}
if (le32_to_cpu(retbuf->TotalBytesWritten) >
le32_to_cpu(pcchunk->Length)) {
cifs_dbg(VFS, "invalid copy chunk response\n");
rc = -EIO;
goto cchunk_out;
}
if (le32_to_cpu(retbuf->ChunksWritten) != 1) {
cifs_dbg(VFS, "invalid num chunks written\n");
rc = -EIO;
goto cchunk_out;
}
chunks_copied++;
bytes_written = le32_to_cpu(retbuf->TotalBytesWritten);
src_off += bytes_written;
dest_off += bytes_written;
len -= bytes_written;
total_bytes_written += bytes_written;
cifs_dbg(FYI, "Chunks %d PartialChunk %d Total %zu\n",
le32_to_cpu(retbuf->ChunksWritten),
le32_to_cpu(retbuf->ChunkBytesWritten),
bytes_written);
} else if (rc == -EINVAL) {
if (ret_data_len != sizeof(struct copychunk_ioctl_rsp))
goto cchunk_out;
cifs_dbg(FYI, "MaxChunks %d BytesChunk %d MaxCopy %d\n",
le32_to_cpu(retbuf->ChunksWritten),
le32_to_cpu(retbuf->ChunkBytesWritten),
le32_to_cpu(retbuf->TotalBytesWritten));
if ((chunks_copied != 0) || chunk_sizes_updated)
goto cchunk_out;
if (le32_to_cpu(retbuf->ChunkBytesWritten) <
tcon->max_bytes_chunk)
tcon->max_bytes_chunk =
le32_to_cpu(retbuf->ChunkBytesWritten);
else
goto cchunk_out;
chunk_sizes_updated = true;
} else
goto cchunk_out;
}
cchunk_out:
kfree(pcchunk);
kfree(retbuf);
if (rc)
return rc;
else
return total_bytes_written;
}
static int
smb2_flush_file(const unsigned int xid, struct cifs_tcon *tcon,
struct cifs_fid *fid)
{
return SMB2_flush(xid, tcon, fid->persistent_fid, fid->volatile_fid);
}
static unsigned int
smb2_read_data_offset(char *buf)
{
struct smb2_read_rsp *rsp = (struct smb2_read_rsp *)buf;
return rsp->DataOffset;
}
static unsigned int
smb2_read_data_length(char *buf)
{
struct smb2_read_rsp *rsp = (struct smb2_read_rsp *)buf;
return le32_to_cpu(rsp->DataLength);
}
static int
smb2_sync_read(const unsigned int xid, struct cifs_fid *pfid,
struct cifs_io_parms *parms, unsigned int *bytes_read,
char **buf, int *buf_type)
{
parms->persistent_fid = pfid->persistent_fid;
parms->volatile_fid = pfid->volatile_fid;
return SMB2_read(xid, parms, bytes_read, buf, buf_type);
}
static int
smb2_sync_write(const unsigned int xid, struct cifs_fid *pfid,
struct cifs_io_parms *parms, unsigned int *written,
struct kvec *iov, unsigned long nr_segs)
{
parms->persistent_fid = pfid->persistent_fid;
parms->volatile_fid = pfid->volatile_fid;
return SMB2_write(xid, parms, written, iov, nr_segs);
}
static bool smb2_set_sparse(const unsigned int xid, struct cifs_tcon *tcon,
struct cifsFileInfo *cfile, struct inode *inode, __u8 setsparse)
{
struct cifsInodeInfo *cifsi;
int rc;
cifsi = CIFS_I(inode);
if ((cifsi->cifsAttrs & FILE_ATTRIBUTE_SPARSE_FILE) && setsparse)
return true;
if (!(cifsi->cifsAttrs & FILE_ATTRIBUTE_SPARSE_FILE) && !setsparse)
return true;
if (tcon->broken_sparse_sup)
return false;
rc = SMB2_ioctl(xid, tcon, cfile->fid.persistent_fid,
cfile->fid.volatile_fid, FSCTL_SET_SPARSE,
true , false ,
&setsparse, 1, NULL, NULL);
if (rc) {
tcon->broken_sparse_sup = true;
cifs_dbg(FYI, "set sparse rc = %d\n", rc);
return false;
}
if (setsparse)
cifsi->cifsAttrs |= FILE_ATTRIBUTE_SPARSE_FILE;
else
cifsi->cifsAttrs &= (~FILE_ATTRIBUTE_SPARSE_FILE);
return true;
}
static int
smb2_set_file_size(const unsigned int xid, struct cifs_tcon *tcon,
struct cifsFileInfo *cfile, __u64 size, bool set_alloc)
{
__le64 eof = cpu_to_le64(size);
struct inode *inode;
inode = d_inode(cfile->dentry);
if (!set_alloc && (size > inode->i_size + 8192)) {
__u8 set_sparse = 1;
smb2_set_sparse(xid, tcon, cfile, inode, set_sparse);
}
return SMB2_set_eof(xid, tcon, cfile->fid.persistent_fid,
cfile->fid.volatile_fid, cfile->pid, &eof, false);
}
static int
smb2_duplicate_extents(const unsigned int xid,
struct cifsFileInfo *srcfile,
struct cifsFileInfo *trgtfile, u64 src_off,
u64 len, u64 dest_off)
{
int rc;
unsigned int ret_data_len;
struct duplicate_extents_to_file dup_ext_buf;
struct cifs_tcon *tcon = tlink_tcon(trgtfile->tlink);
if ((le32_to_cpu(tcon->fsAttrInfo.Attributes) &
FILE_SUPPORTS_BLOCK_REFCOUNTING) == 0)
return -EOPNOTSUPP;
dup_ext_buf.VolatileFileHandle = srcfile->fid.volatile_fid;
dup_ext_buf.PersistentFileHandle = srcfile->fid.persistent_fid;
dup_ext_buf.SourceFileOffset = cpu_to_le64(src_off);
dup_ext_buf.TargetFileOffset = cpu_to_le64(dest_off);
dup_ext_buf.ByteCount = cpu_to_le64(len);
cifs_dbg(FYI, "duplicate extents: src off %lld dst off %lld len %lld",
src_off, dest_off, len);
rc = smb2_set_file_size(xid, tcon, trgtfile, dest_off + len, false);
if (rc)
goto duplicate_extents_out;
rc = SMB2_ioctl(xid, tcon, trgtfile->fid.persistent_fid,
trgtfile->fid.volatile_fid,
FSCTL_DUPLICATE_EXTENTS_TO_FILE,
true , false ,
(char *)&dup_ext_buf,
sizeof(struct duplicate_extents_to_file),
NULL,
&ret_data_len);
if (ret_data_len > 0)
cifs_dbg(FYI, "non-zero response length in duplicate extents");
duplicate_extents_out:
return rc;
}
static int
smb2_set_compression(const unsigned int xid, struct cifs_tcon *tcon,
struct cifsFileInfo *cfile)
{
return SMB2_set_compression(xid, tcon, cfile->fid.persistent_fid,
cfile->fid.volatile_fid);
}
static int
smb3_set_integrity(const unsigned int xid, struct cifs_tcon *tcon,
struct cifsFileInfo *cfile)
{
struct fsctl_set_integrity_information_req integr_info;
unsigned int ret_data_len;
integr_info.ChecksumAlgorithm = cpu_to_le16(CHECKSUM_TYPE_UNCHANGED);
integr_info.Flags = 0;
integr_info.Reserved = 0;
return SMB2_ioctl(xid, tcon, cfile->fid.persistent_fid,
cfile->fid.volatile_fid,
FSCTL_SET_INTEGRITY_INFORMATION,
true , false ,
(char *)&integr_info,
sizeof(struct fsctl_set_integrity_information_req),
NULL,
&ret_data_len);
}
static int
smb3_enum_snapshots(const unsigned int xid, struct cifs_tcon *tcon,
struct cifsFileInfo *cfile, void __user *ioc_buf)
{
char *retbuf = NULL;
unsigned int ret_data_len = 0;
int rc;
struct smb_snapshot_array snapshot_in;
rc = SMB2_ioctl(xid, tcon, cfile->fid.persistent_fid,
cfile->fid.volatile_fid,
FSCTL_SRV_ENUMERATE_SNAPSHOTS,
true , false ,
NULL, 0 ,
(char **)&retbuf,
&ret_data_len);
cifs_dbg(FYI, "enum snaphots ioctl returned %d and ret buflen is %d\n",
rc, ret_data_len);
if (rc)
return rc;
if (ret_data_len && (ioc_buf != NULL) && (retbuf != NULL)) {
if (copy_from_user(&snapshot_in, ioc_buf,
sizeof(struct smb_snapshot_array))) {
rc = -EFAULT;
kfree(retbuf);
return rc;
}
if (snapshot_in.snapshot_array_size < sizeof(struct smb_snapshot_array)) {
rc = -ERANGE;
return rc;
}
if (ret_data_len > snapshot_in.snapshot_array_size)
ret_data_len = snapshot_in.snapshot_array_size;
if (copy_to_user(ioc_buf, retbuf, ret_data_len))
rc = -EFAULT;
}
kfree(retbuf);
return rc;
}
static int
smb2_query_dir_first(const unsigned int xid, struct cifs_tcon *tcon,
const char *path, struct cifs_sb_info *cifs_sb,
struct cifs_fid *fid, __u16 search_flags,
struct cifs_search_info *srch_inf)
{
__le16 *utf16_path;
int rc;
__u8 oplock = SMB2_OPLOCK_LEVEL_NONE;
struct cifs_open_parms oparms;
utf16_path = cifs_convert_path_to_utf16(path, cifs_sb);
if (!utf16_path)
return -ENOMEM;
oparms.tcon = tcon;
oparms.desired_access = FILE_READ_ATTRIBUTES | FILE_READ_DATA;
oparms.disposition = FILE_OPEN;
oparms.create_options = 0;
oparms.fid = fid;
oparms.reconnect = false;
rc = SMB2_open(xid, &oparms, utf16_path, &oplock, NULL, NULL);
kfree(utf16_path);
if (rc) {
cifs_dbg(VFS, "open dir failed\n");
return rc;
}
srch_inf->entries_in_buffer = 0;
srch_inf->index_of_last_entry = 0;
rc = SMB2_query_directory(xid, tcon, fid->persistent_fid,
fid->volatile_fid, 0, srch_inf);
if (rc) {
cifs_dbg(VFS, "query directory failed\n");
SMB2_close(xid, tcon, fid->persistent_fid, fid->volatile_fid);
}
return rc;
}
static int
smb2_query_dir_next(const unsigned int xid, struct cifs_tcon *tcon,
struct cifs_fid *fid, __u16 search_flags,
struct cifs_search_info *srch_inf)
{
return SMB2_query_directory(xid, tcon, fid->persistent_fid,
fid->volatile_fid, 0, srch_inf);
}
static int
smb2_close_dir(const unsigned int xid, struct cifs_tcon *tcon,
struct cifs_fid *fid)
{
return SMB2_close(xid, tcon, fid->persistent_fid, fid->volatile_fid);
}
static bool
smb2_is_status_pending(char *buf, struct TCP_Server_Info *server, int length)
{
struct smb2_sync_hdr *shdr = get_sync_hdr(buf);
if (shdr->Status != STATUS_PENDING)
return false;
if (!length) {
spin_lock(&server->req_lock);
server->credits += le16_to_cpu(shdr->CreditRequest);
spin_unlock(&server->req_lock);
wake_up(&server->request_q);
}
return true;
}
static int
smb2_oplock_response(struct cifs_tcon *tcon, struct cifs_fid *fid,
struct cifsInodeInfo *cinode)
{
if (tcon->ses->server->capabilities & SMB2_GLOBAL_CAP_LEASING)
return SMB2_lease_break(0, tcon, cinode->lease_key,
smb2_get_lease_state(cinode));
return SMB2_oplock_break(0, tcon, fid->persistent_fid,
fid->volatile_fid,
CIFS_CACHE_READ(cinode) ? 1 : 0);
}
static int
smb2_queryfs(const unsigned int xid, struct cifs_tcon *tcon,
struct kstatfs *buf)
{
int rc;
__le16 srch_path = 0;
u8 oplock = SMB2_OPLOCK_LEVEL_NONE;
struct cifs_open_parms oparms;
struct cifs_fid fid;
oparms.tcon = tcon;
oparms.desired_access = FILE_READ_ATTRIBUTES;
oparms.disposition = FILE_OPEN;
oparms.create_options = 0;
oparms.fid = &fid;
oparms.reconnect = false;
rc = SMB2_open(xid, &oparms, &srch_path, &oplock, NULL, NULL);
if (rc)
return rc;
buf->f_type = SMB2_MAGIC_NUMBER;
rc = SMB2_QFS_info(xid, tcon, fid.persistent_fid, fid.volatile_fid,
buf);
SMB2_close(xid, tcon, fid.persistent_fid, fid.volatile_fid);
return rc;
}
static bool
smb2_compare_fids(struct cifsFileInfo *ob1, struct cifsFileInfo *ob2)
{
return ob1->fid.persistent_fid == ob2->fid.persistent_fid &&
ob1->fid.volatile_fid == ob2->fid.volatile_fid;
}
static int
smb2_mand_lock(const unsigned int xid, struct cifsFileInfo *cfile, __u64 offset,
__u64 length, __u32 type, int lock, int unlock, bool wait)
{
if (unlock && !lock)
type = SMB2_LOCKFLAG_UNLOCK;
return SMB2_lock(xid, tlink_tcon(cfile->tlink),
cfile->fid.persistent_fid, cfile->fid.volatile_fid,
current->tgid, length, offset, type, wait);
}
static void
smb2_get_lease_key(struct inode *inode, struct cifs_fid *fid)
{
memcpy(fid->lease_key, CIFS_I(inode)->lease_key, SMB2_LEASE_KEY_SIZE);
}
static void
smb2_set_lease_key(struct inode *inode, struct cifs_fid *fid)
{
memcpy(CIFS_I(inode)->lease_key, fid->lease_key, SMB2_LEASE_KEY_SIZE);
}
static void
smb2_new_lease_key(struct cifs_fid *fid)
{
generate_random_uuid(fid->lease_key);
}
static int
smb2_get_dfs_refer(const unsigned int xid, struct cifs_ses *ses,
const char *search_name,
struct dfs_info3_param **target_nodes,
unsigned int *num_of_nodes,
const struct nls_table *nls_codepage, int remap)
{
int rc;
__le16 *utf16_path = NULL;
int utf16_path_len = 0;
struct cifs_tcon *tcon;
struct fsctl_get_dfs_referral_req *dfs_req = NULL;
struct get_dfs_referral_rsp *dfs_rsp = NULL;
u32 dfs_req_size = 0, dfs_rsp_size = 0;
cifs_dbg(FYI, "smb2_get_dfs_refer path <%s>\n", search_name);
spin_lock(&cifs_tcp_ses_lock);
tcon = list_first_entry_or_null(&ses->tcon_list, struct cifs_tcon,
tcon_list);
if (tcon)
tcon->tc_count++;
spin_unlock(&cifs_tcp_ses_lock);
if (!tcon) {
cifs_dbg(VFS, "session %p has no tcon available for a dfs referral request\n",
ses);
rc = -ENOTCONN;
goto out;
}
utf16_path = cifs_strndup_to_utf16(search_name, PATH_MAX,
&utf16_path_len,
nls_codepage, remap);
if (!utf16_path) {
rc = -ENOMEM;
goto out;
}
dfs_req_size = sizeof(*dfs_req) + utf16_path_len;
dfs_req = kzalloc(dfs_req_size, GFP_KERNEL);
if (!dfs_req) {
rc = -ENOMEM;
goto out;
}
dfs_req->MaxReferralLevel = DFS_VERSION;
memcpy(dfs_req->RequestFileName, utf16_path, utf16_path_len);
do {
rc = SMB2_ioctl(xid, tcon, NO_FILE_ID, NO_FILE_ID,
FSCTL_DFS_GET_REFERRALS,
true , true ,
(char *)dfs_req, dfs_req_size,
(char **)&dfs_rsp, &dfs_rsp_size);
if (rc == -ENOTCONN) {
rc = SMB2_ioctl(xid, tcon, NO_FILE_ID, NO_FILE_ID,
FSCTL_DFS_GET_REFERRALS,
true , false ,
(char *)dfs_req, dfs_req_size,
(char **)&dfs_rsp, &dfs_rsp_size);
}
} while (rc == -EAGAIN);
if (rc) {
cifs_dbg(VFS, "ioctl error in smb2_get_dfs_refer rc=%d\n", rc);
goto out;
}
rc = parse_dfs_referrals(dfs_rsp, dfs_rsp_size,
num_of_nodes, target_nodes,
nls_codepage, remap, search_name,
true );
if (rc) {
cifs_dbg(VFS, "parse error in smb2_get_dfs_refer rc=%d\n", rc);
goto out;
}
out:
if (tcon) {
spin_lock(&cifs_tcp_ses_lock);
tcon->tc_count--;
spin_unlock(&cifs_tcp_ses_lock);
}
kfree(utf16_path);
kfree(dfs_req);
kfree(dfs_rsp);
return rc;
}
static int
smb2_query_symlink(const unsigned int xid, struct cifs_tcon *tcon,
const char *full_path, char **target_path,
struct cifs_sb_info *cifs_sb)
{
int rc;
__le16 *utf16_path;
__u8 oplock = SMB2_OPLOCK_LEVEL_NONE;
struct cifs_open_parms oparms;
struct cifs_fid fid;
struct smb2_err_rsp *err_buf = NULL;
struct smb2_symlink_err_rsp *symlink;
unsigned int sub_len;
unsigned int sub_offset;
unsigned int print_len;
unsigned int print_offset;
cifs_dbg(FYI, "%s: path: %s\n", __func__, full_path);
utf16_path = cifs_convert_path_to_utf16(full_path, cifs_sb);
if (!utf16_path)
return -ENOMEM;
oparms.tcon = tcon;
oparms.desired_access = FILE_READ_ATTRIBUTES;
oparms.disposition = FILE_OPEN;
oparms.create_options = 0;
oparms.fid = &fid;
oparms.reconnect = false;
rc = SMB2_open(xid, &oparms, utf16_path, &oplock, NULL, &err_buf);
if (!rc || !err_buf) {
kfree(utf16_path);
return -ENOENT;
}
if (le32_to_cpu(err_buf->ByteCount) < sizeof(struct smb2_symlink_err_rsp) ||
get_rfc1002_length(err_buf) + 4 < SMB2_SYMLINK_STRUCT_SIZE) {
kfree(utf16_path);
return -ENOENT;
}
rc = 0;
symlink = (struct smb2_symlink_err_rsp *)err_buf->ErrorData;
sub_len = le16_to_cpu(symlink->SubstituteNameLength);
sub_offset = le16_to_cpu(symlink->SubstituteNameOffset);
print_len = le16_to_cpu(symlink->PrintNameLength);
print_offset = le16_to_cpu(symlink->PrintNameOffset);
if (get_rfc1002_length(err_buf) + 4 <
SMB2_SYMLINK_STRUCT_SIZE + sub_offset + sub_len) {
kfree(utf16_path);
return -ENOENT;
}
if (get_rfc1002_length(err_buf) + 4 <
SMB2_SYMLINK_STRUCT_SIZE + print_offset + print_len) {
kfree(utf16_path);
return -ENOENT;
}
*target_path = cifs_strndup_from_utf16(
(char *)symlink->PathBuffer + sub_offset,
sub_len, true, cifs_sb->local_nls);
if (!(*target_path)) {
kfree(utf16_path);
return -ENOMEM;
}
convert_delimiter(*target_path, '/');
cifs_dbg(FYI, "%s: target path: %s\n", __func__, *target_path);
kfree(utf16_path);
return rc;
}
static long smb3_zero_range(struct file *file, struct cifs_tcon *tcon,
loff_t offset, loff_t len, bool keep_size)
{
struct inode *inode;
struct cifsInodeInfo *cifsi;
struct cifsFileInfo *cfile = file->private_data;
struct file_zero_data_information fsctl_buf;
long rc;
unsigned int xid;
xid = get_xid();
inode = d_inode(cfile->dentry);
cifsi = CIFS_I(inode);
if (!CIFS_CACHE_READ(cifsi))
if (keep_size == false)
return -EOPNOTSUPP;
if (!(cifsi->cifsAttrs & FILE_ATTRIBUTE_SPARSE_FILE))
return -EOPNOTSUPP;
if (keep_size == false)
if (i_size_read(inode) < offset + len)
return -EOPNOTSUPP;
cifs_dbg(FYI, "offset %lld len %lld", offset, len);
fsctl_buf.FileOffset = cpu_to_le64(offset);
fsctl_buf.BeyondFinalZero = cpu_to_le64(offset + len);
rc = SMB2_ioctl(xid, tcon, cfile->fid.persistent_fid,
cfile->fid.volatile_fid, FSCTL_SET_ZERO_DATA,
true , false ,
(char *)&fsctl_buf,
sizeof(struct file_zero_data_information), NULL, NULL);
free_xid(xid);
return rc;
}
static long smb3_punch_hole(struct file *file, struct cifs_tcon *tcon,
loff_t offset, loff_t len)
{
struct inode *inode;
struct cifsInodeInfo *cifsi;
struct cifsFileInfo *cfile = file->private_data;
struct file_zero_data_information fsctl_buf;
long rc;
unsigned int xid;
__u8 set_sparse = 1;
xid = get_xid();
inode = d_inode(cfile->dentry);
cifsi = CIFS_I(inode);
if (!smb2_set_sparse(xid, tcon, cfile, inode, set_sparse))
return -EOPNOTSUPP;
cifs_dbg(FYI, "offset %lld len %lld", offset, len);
fsctl_buf.FileOffset = cpu_to_le64(offset);
fsctl_buf.BeyondFinalZero = cpu_to_le64(offset + len);
rc = SMB2_ioctl(xid, tcon, cfile->fid.persistent_fid,
cfile->fid.volatile_fid, FSCTL_SET_ZERO_DATA,
true , false ,
(char *)&fsctl_buf,
sizeof(struct file_zero_data_information), NULL, NULL);
free_xid(xid);
return rc;
}
static long smb3_simple_falloc(struct file *file, struct cifs_tcon *tcon,
loff_t off, loff_t len, bool keep_size)
{
struct inode *inode;
struct cifsInodeInfo *cifsi;
struct cifsFileInfo *cfile = file->private_data;
long rc = -EOPNOTSUPP;
unsigned int xid;
xid = get_xid();
inode = d_inode(cfile->dentry);
cifsi = CIFS_I(inode);
if (!CIFS_CACHE_READ(cifsi))
if (keep_size == false)
return -EOPNOTSUPP;
if ((cifsi->cifsAttrs & FILE_ATTRIBUTE_SPARSE_FILE) == 0) {
if (keep_size == true)
return 0;
else if (i_size_read(inode) >= off + len)
return 0;
else
return -EOPNOTSUPP;
}
if ((keep_size == true) || (i_size_read(inode) >= off + len)) {
if ((off > 8192) || (off + len + 8192 < i_size_read(inode)))
return -EOPNOTSUPP;
rc = smb2_set_sparse(xid, tcon, cfile, inode, false);
}
free_xid(xid);
return rc;
}
static long smb3_fallocate(struct file *file, struct cifs_tcon *tcon, int mode,
loff_t off, loff_t len)
{
if (mode & FALLOC_FL_PUNCH_HOLE)
return smb3_punch_hole(file, tcon, off, len);
else if (mode & FALLOC_FL_ZERO_RANGE) {
if (mode & FALLOC_FL_KEEP_SIZE)
return smb3_zero_range(file, tcon, off, len, true);
return smb3_zero_range(file, tcon, off, len, false);
} else if (mode == FALLOC_FL_KEEP_SIZE)
return smb3_simple_falloc(file, tcon, off, len, true);
else if (mode == 0)
return smb3_simple_falloc(file, tcon, off, len, false);
return -EOPNOTSUPP;
}
static void
smb2_downgrade_oplock(struct TCP_Server_Info *server,
struct cifsInodeInfo *cinode, bool set_level2)
{
if (set_level2)
server->ops->set_oplock_level(cinode, SMB2_OPLOCK_LEVEL_II,
0, NULL);
else
server->ops->set_oplock_level(cinode, 0, 0, NULL);
}
static void
smb2_set_oplock_level(struct cifsInodeInfo *cinode, __u32 oplock,
unsigned int epoch, bool *purge_cache)
{
oplock &= 0xFF;
if (oplock == SMB2_OPLOCK_LEVEL_NOCHANGE)
return;
if (oplock == SMB2_OPLOCK_LEVEL_BATCH) {
cinode->oplock = CIFS_CACHE_RHW_FLG;
cifs_dbg(FYI, "Batch Oplock granted on inode %p\n",
&cinode->vfs_inode);
} else if (oplock == SMB2_OPLOCK_LEVEL_EXCLUSIVE) {
cinode->oplock = CIFS_CACHE_RW_FLG;
cifs_dbg(FYI, "Exclusive Oplock granted on inode %p\n",
&cinode->vfs_inode);
} else if (oplock == SMB2_OPLOCK_LEVEL_II) {
cinode->oplock = CIFS_CACHE_READ_FLG;
cifs_dbg(FYI, "Level II Oplock granted on inode %p\n",
&cinode->vfs_inode);
} else
cinode->oplock = 0;
}
static void
smb21_set_oplock_level(struct cifsInodeInfo *cinode, __u32 oplock,
unsigned int epoch, bool *purge_cache)
{
char message[5] = {0};
oplock &= 0xFF;
if (oplock == SMB2_OPLOCK_LEVEL_NOCHANGE)
return;
cinode->oplock = 0;
if (oplock & SMB2_LEASE_READ_CACHING_HE) {
cinode->oplock |= CIFS_CACHE_READ_FLG;
strcat(message, "R");
}
if (oplock & SMB2_LEASE_HANDLE_CACHING_HE) {
cinode->oplock |= CIFS_CACHE_HANDLE_FLG;
strcat(message, "H");
}
if (oplock & SMB2_LEASE_WRITE_CACHING_HE) {
cinode->oplock |= CIFS_CACHE_WRITE_FLG;
strcat(message, "W");
}
if (!cinode->oplock)
strcat(message, "None");
cifs_dbg(FYI, "%s Lease granted on inode %p\n", message,
&cinode->vfs_inode);
}
static void
smb3_set_oplock_level(struct cifsInodeInfo *cinode, __u32 oplock,
unsigned int epoch, bool *purge_cache)
{
unsigned int old_oplock = cinode->oplock;
smb21_set_oplock_level(cinode, oplock, epoch, purge_cache);
if (purge_cache) {
*purge_cache = false;
if (old_oplock == CIFS_CACHE_READ_FLG) {
if (cinode->oplock == CIFS_CACHE_READ_FLG &&
(epoch - cinode->epoch > 0))
*purge_cache = true;
else if (cinode->oplock == CIFS_CACHE_RH_FLG &&
(epoch - cinode->epoch > 1))
*purge_cache = true;
else if (cinode->oplock == CIFS_CACHE_RHW_FLG &&
(epoch - cinode->epoch > 1))
*purge_cache = true;
else if (cinode->oplock == 0 &&
(epoch - cinode->epoch > 0))
*purge_cache = true;
} else if (old_oplock == CIFS_CACHE_RH_FLG) {
if (cinode->oplock == CIFS_CACHE_RH_FLG &&
(epoch - cinode->epoch > 0))
*purge_cache = true;
else if (cinode->oplock == CIFS_CACHE_RHW_FLG &&
(epoch - cinode->epoch > 1))
*purge_cache = true;
}
cinode->epoch = epoch;
}
}
static bool
smb2_is_read_op(__u32 oplock)
{
return oplock == SMB2_OPLOCK_LEVEL_II;
}
static bool
smb21_is_read_op(__u32 oplock)
{
return (oplock & SMB2_LEASE_READ_CACHING_HE) &&
!(oplock & SMB2_LEASE_WRITE_CACHING_HE);
}
static __le32
map_oplock_to_lease(u8 oplock)
{
if (oplock == SMB2_OPLOCK_LEVEL_EXCLUSIVE)
return SMB2_LEASE_WRITE_CACHING | SMB2_LEASE_READ_CACHING;
else if (oplock == SMB2_OPLOCK_LEVEL_II)
return SMB2_LEASE_READ_CACHING;
else if (oplock == SMB2_OPLOCK_LEVEL_BATCH)
return SMB2_LEASE_HANDLE_CACHING | SMB2_LEASE_READ_CACHING |
SMB2_LEASE_WRITE_CACHING;
return 0;
}
static char *
smb2_create_lease_buf(u8 *lease_key, u8 oplock)
{
struct create_lease *buf;
buf = kzalloc(sizeof(struct create_lease), GFP_KERNEL);
if (!buf)
return NULL;
buf->lcontext.LeaseKeyLow = cpu_to_le64(*((u64 *)lease_key));
buf->lcontext.LeaseKeyHigh = cpu_to_le64(*((u64 *)(lease_key + 8)));
buf->lcontext.LeaseState = map_oplock_to_lease(oplock);
buf->ccontext.DataOffset = cpu_to_le16(offsetof
(struct create_lease, lcontext));
buf->ccontext.DataLength = cpu_to_le32(sizeof(struct lease_context));
buf->ccontext.NameOffset = cpu_to_le16(offsetof
(struct create_lease, Name));
buf->ccontext.NameLength = cpu_to_le16(4);
buf->Name[0] = 'R';
buf->Name[1] = 'q';
buf->Name[2] = 'L';
buf->Name[3] = 's';
return (char *)buf;
}
static char *
smb3_create_lease_buf(u8 *lease_key, u8 oplock)
{
struct create_lease_v2 *buf;
buf = kzalloc(sizeof(struct create_lease_v2), GFP_KERNEL);
if (!buf)
return NULL;
buf->lcontext.LeaseKeyLow = cpu_to_le64(*((u64 *)lease_key));
buf->lcontext.LeaseKeyHigh = cpu_to_le64(*((u64 *)(lease_key + 8)));
buf->lcontext.LeaseState = map_oplock_to_lease(oplock);
buf->ccontext.DataOffset = cpu_to_le16(offsetof
(struct create_lease_v2, lcontext));
buf->ccontext.DataLength = cpu_to_le32(sizeof(struct lease_context_v2));
buf->ccontext.NameOffset = cpu_to_le16(offsetof
(struct create_lease_v2, Name));
buf->ccontext.NameLength = cpu_to_le16(4);
buf->Name[0] = 'R';
buf->Name[1] = 'q';
buf->Name[2] = 'L';
buf->Name[3] = 's';
return (char *)buf;
}
static __u8
smb2_parse_lease_buf(void *buf, unsigned int *epoch)
{
struct create_lease *lc = (struct create_lease *)buf;
*epoch = 0;
if (lc->lcontext.LeaseFlags & SMB2_LEASE_FLAG_BREAK_IN_PROGRESS)
return SMB2_OPLOCK_LEVEL_NOCHANGE;
return le32_to_cpu(lc->lcontext.LeaseState);
}
static __u8
smb3_parse_lease_buf(void *buf, unsigned int *epoch)
{
struct create_lease_v2 *lc = (struct create_lease_v2 *)buf;
*epoch = le16_to_cpu(lc->lcontext.Epoch);
if (lc->lcontext.LeaseFlags & SMB2_LEASE_FLAG_BREAK_IN_PROGRESS)
return SMB2_OPLOCK_LEVEL_NOCHANGE;
return le32_to_cpu(lc->lcontext.LeaseState);
}
static unsigned int
smb2_wp_retry_size(struct inode *inode)
{
return min_t(unsigned int, CIFS_SB(inode->i_sb)->wsize,
SMB2_MAX_BUFFER_SIZE);
}
static bool
smb2_dir_needs_close(struct cifsFileInfo *cfile)
{
return !cfile->invalidHandle;
}
static void
fill_transform_hdr(struct smb2_transform_hdr *tr_hdr, struct smb_rqst *old_rq)
{
struct smb2_sync_hdr *shdr =
(struct smb2_sync_hdr *)old_rq->rq_iov[1].iov_base;
unsigned int orig_len = get_rfc1002_length(old_rq->rq_iov[0].iov_base);
memset(tr_hdr, 0, sizeof(struct smb2_transform_hdr));
tr_hdr->ProtocolId = SMB2_TRANSFORM_PROTO_NUM;
tr_hdr->OriginalMessageSize = cpu_to_le32(orig_len);
tr_hdr->Flags = cpu_to_le16(0x01);
get_random_bytes(&tr_hdr->Nonce, SMB3_AES128CMM_NONCE);
memcpy(&tr_hdr->SessionId, &shdr->SessionId, 8);
inc_rfc1001_len(tr_hdr, sizeof(struct smb2_transform_hdr) - 4);
inc_rfc1001_len(tr_hdr, orig_len);
}
static struct scatterlist *
init_sg(struct smb_rqst *rqst, u8 *sign)
{
unsigned int sg_len = rqst->rq_nvec + rqst->rq_npages + 1;
unsigned int assoc_data_len = sizeof(struct smb2_transform_hdr) - 24;
struct scatterlist *sg;
unsigned int i;
unsigned int j;
sg = kmalloc_array(sg_len, sizeof(struct scatterlist), GFP_KERNEL);
if (!sg)
return NULL;
sg_init_table(sg, sg_len);
sg_set_buf(&sg[0], rqst->rq_iov[0].iov_base + 24, assoc_data_len);
for (i = 1; i < rqst->rq_nvec; i++)
sg_set_buf(&sg[i], rqst->rq_iov[i].iov_base,
rqst->rq_iov[i].iov_len);
for (j = 0; i < sg_len - 1; i++, j++) {
unsigned int len = (j < rqst->rq_npages - 1) ? rqst->rq_pagesz
: rqst->rq_tailsz;
sg_set_page(&sg[i], rqst->rq_pages[j], len, 0);
}
sg_set_buf(&sg[sg_len - 1], sign, SMB2_SIGNATURE_SIZE);
return sg;
}
static void cifs_crypt_complete(struct crypto_async_request *req, int err)
{
struct cifs_crypt_result *res = req->data;
if (err == -EINPROGRESS)
return;
res->err = err;
complete(&res->completion);
}
static int
smb2_get_enc_key(struct TCP_Server_Info *server, __u64 ses_id, int enc, u8 *key)
{
struct cifs_ses *ses;
u8 *ses_enc_key;
spin_lock(&cifs_tcp_ses_lock);
list_for_each_entry(ses, &server->smb_ses_list, smb_ses_list) {
if (ses->Suid != ses_id)
continue;
ses_enc_key = enc ? ses->smb3encryptionkey :
ses->smb3decryptionkey;
memcpy(key, ses_enc_key, SMB3_SIGN_KEY_SIZE);
spin_unlock(&cifs_tcp_ses_lock);
return 0;
}
spin_unlock(&cifs_tcp_ses_lock);
return 1;
}
static int
crypt_message(struct TCP_Server_Info *server, struct smb_rqst *rqst, int enc)
{
struct smb2_transform_hdr *tr_hdr =
(struct smb2_transform_hdr *)rqst->rq_iov[0].iov_base;
unsigned int assoc_data_len = sizeof(struct smb2_transform_hdr) - 24;
int rc = 0;
struct scatterlist *sg;
u8 sign[SMB2_SIGNATURE_SIZE] = {};
u8 key[SMB3_SIGN_KEY_SIZE];
struct aead_request *req;
char *iv;
unsigned int iv_len;
struct cifs_crypt_result result = {0, };
struct crypto_aead *tfm;
unsigned int crypt_len = le32_to_cpu(tr_hdr->OriginalMessageSize);
init_completion(&result.completion);
rc = smb2_get_enc_key(server, tr_hdr->SessionId, enc, key);
if (rc) {
cifs_dbg(VFS, "%s: Could not get %scryption key\n", __func__,
enc ? "en" : "de");
return 0;
}
rc = smb3_crypto_aead_allocate(server);
if (rc) {
cifs_dbg(VFS, "%s: crypto alloc failed\n", __func__);
return rc;
}
tfm = enc ? server->secmech.ccmaesencrypt :
server->secmech.ccmaesdecrypt;
rc = crypto_aead_setkey(tfm, key, SMB3_SIGN_KEY_SIZE);
if (rc) {
cifs_dbg(VFS, "%s: Failed to set aead key %d\n", __func__, rc);
return rc;
}
rc = crypto_aead_setauthsize(tfm, SMB2_SIGNATURE_SIZE);
if (rc) {
cifs_dbg(VFS, "%s: Failed to set authsize %d\n", __func__, rc);
return rc;
}
req = aead_request_alloc(tfm, GFP_KERNEL);
if (!req) {
cifs_dbg(VFS, "%s: Failed to alloc aead request", __func__);
return -ENOMEM;
}
if (!enc) {
memcpy(sign, &tr_hdr->Signature, SMB2_SIGNATURE_SIZE);
crypt_len += SMB2_SIGNATURE_SIZE;
}
sg = init_sg(rqst, sign);
if (!sg) {
cifs_dbg(VFS, "%s: Failed to init sg %d", __func__, rc);
goto free_req;
}
iv_len = crypto_aead_ivsize(tfm);
iv = kzalloc(iv_len, GFP_KERNEL);
if (!iv) {
cifs_dbg(VFS, "%s: Failed to alloc IV", __func__);
goto free_sg;
}
iv[0] = 3;
memcpy(iv + 1, (char *)tr_hdr->Nonce, SMB3_AES128CMM_NONCE);
aead_request_set_crypt(req, sg, sg, crypt_len, iv);
aead_request_set_ad(req, assoc_data_len);
aead_request_set_callback(req, CRYPTO_TFM_REQ_MAY_BACKLOG,
cifs_crypt_complete, &result);
rc = enc ? crypto_aead_encrypt(req) : crypto_aead_decrypt(req);
if (rc == -EINPROGRESS || rc == -EBUSY) {
wait_for_completion(&result.completion);
rc = result.err;
}
if (!rc && enc)
memcpy(&tr_hdr->Signature, sign, SMB2_SIGNATURE_SIZE);
kfree(iv);
free_sg:
kfree(sg);
free_req:
kfree(req);
return rc;
}
static int
smb3_init_transform_rq(struct TCP_Server_Info *server, struct smb_rqst *new_rq,
struct smb_rqst *old_rq)
{
struct kvec *iov;
struct page **pages;
struct smb2_transform_hdr *tr_hdr;
unsigned int npages = old_rq->rq_npages;
int i;
int rc = -ENOMEM;
pages = kmalloc_array(npages, sizeof(struct page *), GFP_KERNEL);
if (!pages)
return rc;
new_rq->rq_pages = pages;
new_rq->rq_npages = old_rq->rq_npages;
new_rq->rq_pagesz = old_rq->rq_pagesz;
new_rq->rq_tailsz = old_rq->rq_tailsz;
for (i = 0; i < npages; i++) {
pages[i] = alloc_page(GFP_KERNEL|__GFP_HIGHMEM);
if (!pages[i])
goto err_free_pages;
}
iov = kmalloc_array(old_rq->rq_nvec, sizeof(struct kvec), GFP_KERNEL);
if (!iov)
goto err_free_pages;
memcpy(&iov[1], &old_rq->rq_iov[1],
sizeof(struct kvec) * (old_rq->rq_nvec - 1));
new_rq->rq_iov = iov;
new_rq->rq_nvec = old_rq->rq_nvec;
tr_hdr = kmalloc(sizeof(struct smb2_transform_hdr), GFP_KERNEL);
if (!tr_hdr)
goto err_free_iov;
fill_transform_hdr(tr_hdr, old_rq);
new_rq->rq_iov[0].iov_base = tr_hdr;
new_rq->rq_iov[0].iov_len = sizeof(struct smb2_transform_hdr);
for (i = 0; i < npages; i++) {
char *dst = kmap(new_rq->rq_pages[i]);
char *src = kmap(old_rq->rq_pages[i]);
unsigned int len = (i < npages - 1) ? new_rq->rq_pagesz :
new_rq->rq_tailsz;
memcpy(dst, src, len);
kunmap(new_rq->rq_pages[i]);
kunmap(old_rq->rq_pages[i]);
}
rc = crypt_message(server, new_rq, 1);
cifs_dbg(FYI, "encrypt message returned %d", rc);
if (rc)
goto err_free_tr_hdr;
return rc;
err_free_tr_hdr:
kfree(tr_hdr);
err_free_iov:
kfree(iov);
err_free_pages:
for (i = i - 1; i >= 0; i--)
put_page(pages[i]);
kfree(pages);
return rc;
}
static void
smb3_free_transform_rq(struct smb_rqst *rqst)
{
int i = rqst->rq_npages - 1;
for (; i >= 0; i--)
put_page(rqst->rq_pages[i]);
kfree(rqst->rq_pages);
kfree(rqst->rq_iov[0].iov_base);
kfree(rqst->rq_iov);
}
static int
smb3_is_transform_hdr(void *buf)
{
struct smb2_transform_hdr *trhdr = buf;
return trhdr->ProtocolId == SMB2_TRANSFORM_PROTO_NUM;
}
static int
decrypt_raw_data(struct TCP_Server_Info *server, char *buf,
unsigned int buf_data_size, struct page **pages,
unsigned int npages, unsigned int page_data_size)
{
struct kvec iov[2];
struct smb_rqst rqst = {NULL};
struct smb2_hdr *hdr;
int rc;
iov[0].iov_base = buf;
iov[0].iov_len = sizeof(struct smb2_transform_hdr);
iov[1].iov_base = buf + sizeof(struct smb2_transform_hdr);
iov[1].iov_len = buf_data_size;
rqst.rq_iov = iov;
rqst.rq_nvec = 2;
rqst.rq_pages = pages;
rqst.rq_npages = npages;
rqst.rq_pagesz = PAGE_SIZE;
rqst.rq_tailsz = (page_data_size % PAGE_SIZE) ? : PAGE_SIZE;
rc = crypt_message(server, &rqst, 0);
cifs_dbg(FYI, "decrypt message returned %d\n", rc);
if (rc)
return rc;
memmove(buf + 4, iov[1].iov_base, buf_data_size);
hdr = (struct smb2_hdr *)buf;
hdr->smb2_buf_length = cpu_to_be32(buf_data_size + page_data_size);
server->total_read = buf_data_size + page_data_size + 4;
return rc;
}
static int
read_data_into_pages(struct TCP_Server_Info *server, struct page **pages,
unsigned int npages, unsigned int len)
{
int i;
int length;
for (i = 0; i < npages; i++) {
struct page *page = pages[i];
size_t n;
n = len;
if (len >= PAGE_SIZE) {
n = PAGE_SIZE;
len -= n;
} else {
zero_user(page, len, PAGE_SIZE - len);
len = 0;
}
length = cifs_read_page_from_socket(server, page, n);
if (length < 0)
return length;
server->total_read += length;
}
return 0;
}
static int
init_read_bvec(struct page **pages, unsigned int npages, unsigned int data_size,
unsigned int cur_off, struct bio_vec **page_vec)
{
struct bio_vec *bvec;
int i;
bvec = kcalloc(npages, sizeof(struct bio_vec), GFP_KERNEL);
if (!bvec)
return -ENOMEM;
for (i = 0; i < npages; i++) {
bvec[i].bv_page = pages[i];
bvec[i].bv_offset = (i == 0) ? cur_off : 0;
bvec[i].bv_len = min_t(unsigned int, PAGE_SIZE, data_size);
data_size -= bvec[i].bv_len;
}
if (data_size != 0) {
cifs_dbg(VFS, "%s: something went wrong\n", __func__);
kfree(bvec);
return -EIO;
}
*page_vec = bvec;
return 0;
}
static int
handle_read_data(struct TCP_Server_Info *server, struct mid_q_entry *mid,
char *buf, unsigned int buf_len, struct page **pages,
unsigned int npages, unsigned int page_data_size)
{
unsigned int data_offset;
unsigned int data_len;
unsigned int cur_off;
unsigned int cur_page_idx;
unsigned int pad_len;
struct cifs_readdata *rdata = mid->callback_data;
struct smb2_sync_hdr *shdr = get_sync_hdr(buf);
struct bio_vec *bvec = NULL;
struct iov_iter iter;
struct kvec iov;
int length;
if (shdr->Command != SMB2_READ) {
cifs_dbg(VFS, "only big read responses are supported\n");
return -ENOTSUPP;
}
if (server->ops->is_status_pending &&
server->ops->is_status_pending(buf, server, 0))
return -1;
rdata->result = server->ops->map_error(buf, false);
if (rdata->result != 0) {
cifs_dbg(FYI, "%s: server returned error %d\n",
__func__, rdata->result);
dequeue_mid(mid, rdata->result);
return 0;
}
data_offset = server->ops->read_data_offset(buf) + 4;
data_len = server->ops->read_data_length(buf);
if (data_offset < server->vals->read_rsp_size) {
cifs_dbg(FYI, "%s: data offset (%u) inside read response header\n",
__func__, data_offset);
data_offset = server->vals->read_rsp_size;
} else if (data_offset > MAX_CIFS_SMALL_BUFFER_SIZE) {
cifs_dbg(FYI, "%s: data offset (%u) beyond end of smallbuf\n",
__func__, data_offset);
rdata->result = -EIO;
dequeue_mid(mid, rdata->result);
return 0;
}
pad_len = data_offset - server->vals->read_rsp_size;
if (buf_len <= data_offset) {
cur_page_idx = pad_len / PAGE_SIZE;
cur_off = pad_len % PAGE_SIZE;
if (cur_page_idx != 0) {
cifs_dbg(FYI, "%s: data offset (%u) beyond 1st page of response\n",
__func__, data_offset);
rdata->result = -EIO;
dequeue_mid(mid, rdata->result);
return 0;
}
if (data_len > page_data_size - pad_len) {
rdata->result = -EIO;
dequeue_mid(mid, rdata->result);
return 0;
}
rdata->result = init_read_bvec(pages, npages, page_data_size,
cur_off, &bvec);
if (rdata->result != 0) {
dequeue_mid(mid, rdata->result);
return 0;
}
iov_iter_bvec(&iter, WRITE | ITER_BVEC, bvec, npages, data_len);
} else if (buf_len >= data_offset + data_len) {
WARN_ONCE(npages > 0, "read data can be either in buf or in pages");
iov.iov_base = buf + data_offset;
iov.iov_len = data_len;
iov_iter_kvec(&iter, WRITE | ITER_KVEC, &iov, 1, data_len);
} else {
WARN_ONCE(1, "buf can not contain only a part of read data");
rdata->result = -EIO;
dequeue_mid(mid, rdata->result);
return 0;
}
rdata->iov[0].iov_base = buf;
rdata->iov[0].iov_len = 4;
rdata->iov[1].iov_base = buf + 4;
rdata->iov[1].iov_len = server->vals->read_rsp_size - 4;
cifs_dbg(FYI, "0: iov_base=%p iov_len=%zu\n",
rdata->iov[0].iov_base, server->vals->read_rsp_size);
length = rdata->copy_into_pages(server, rdata, &iter);
kfree(bvec);
if (length < 0)
return length;
dequeue_mid(mid, false);
return length;
}
static int
receive_encrypted_read(struct TCP_Server_Info *server, struct mid_q_entry **mid)
{
char *buf = server->smallbuf;
struct smb2_transform_hdr *tr_hdr = (struct smb2_transform_hdr *)buf;
unsigned int npages;
struct page **pages;
unsigned int len;
unsigned int buflen = get_rfc1002_length(buf) + 4;
int rc;
int i = 0;
len = min_t(unsigned int, buflen, server->vals->read_rsp_size - 4 +
sizeof(struct smb2_transform_hdr)) - HEADER_SIZE(server) + 1;
rc = cifs_read_from_socket(server, buf + HEADER_SIZE(server) - 1, len);
if (rc < 0)
return rc;
server->total_read += rc;
len = le32_to_cpu(tr_hdr->OriginalMessageSize) + 4 -
server->vals->read_rsp_size;
npages = DIV_ROUND_UP(len, PAGE_SIZE);
pages = kmalloc_array(npages, sizeof(struct page *), GFP_KERNEL);
if (!pages) {
rc = -ENOMEM;
goto discard_data;
}
for (; i < npages; i++) {
pages[i] = alloc_page(GFP_KERNEL|__GFP_HIGHMEM);
if (!pages[i]) {
rc = -ENOMEM;
goto discard_data;
}
}
rc = read_data_into_pages(server, pages, npages, len);
if (rc)
goto free_pages;
rc = cifs_discard_remaining_data(server);
if (rc)
goto free_pages;
rc = decrypt_raw_data(server, buf, server->vals->read_rsp_size - 4,
pages, npages, len);
if (rc)
goto free_pages;
*mid = smb2_find_mid(server, buf);
if (*mid == NULL)
cifs_dbg(FYI, "mid not found\n");
else {
cifs_dbg(FYI, "mid found\n");
(*mid)->decrypted = true;
rc = handle_read_data(server, *mid, buf,
server->vals->read_rsp_size,
pages, npages, len);
}
free_pages:
for (i = i - 1; i >= 0; i--)
put_page(pages[i]);
kfree(pages);
return rc;
discard_data:
cifs_discard_remaining_data(server);
goto free_pages;
}
static int
receive_encrypted_standard(struct TCP_Server_Info *server,
struct mid_q_entry **mid)
{
int length;
char *buf = server->smallbuf;
unsigned int pdu_length = get_rfc1002_length(buf);
unsigned int buf_size;
struct mid_q_entry *mid_entry;
if (pdu_length + 4 > MAX_CIFS_SMALL_BUFFER_SIZE) {
server->large_buf = true;
memcpy(server->bigbuf, buf, server->total_read);
buf = server->bigbuf;
}
length = cifs_read_from_socket(server, buf + HEADER_SIZE(server) - 1,
pdu_length - HEADER_SIZE(server) + 1 + 4);
if (length < 0)
return length;
server->total_read += length;
buf_size = pdu_length + 4 - sizeof(struct smb2_transform_hdr);
length = decrypt_raw_data(server, buf, buf_size, NULL, 0, 0);
if (length)
return length;
mid_entry = smb2_find_mid(server, buf);
if (mid_entry == NULL)
cifs_dbg(FYI, "mid not found\n");
else {
cifs_dbg(FYI, "mid found\n");
mid_entry->decrypted = true;
}
*mid = mid_entry;
if (mid_entry && mid_entry->handle)
return mid_entry->handle(server, mid_entry);
return cifs_handle_standard(server, mid_entry);
}
static int
smb3_receive_transform(struct TCP_Server_Info *server, struct mid_q_entry **mid)
{
char *buf = server->smallbuf;
unsigned int pdu_length = get_rfc1002_length(buf);
struct smb2_transform_hdr *tr_hdr = (struct smb2_transform_hdr *)buf;
unsigned int orig_len = le32_to_cpu(tr_hdr->OriginalMessageSize);
if (pdu_length + 4 < sizeof(struct smb2_transform_hdr) +
sizeof(struct smb2_sync_hdr)) {
cifs_dbg(VFS, "Transform message is too small (%u)\n",
pdu_length);
cifs_reconnect(server);
wake_up(&server->response_q);
return -ECONNABORTED;
}
if (pdu_length + 4 < orig_len + sizeof(struct smb2_transform_hdr)) {
cifs_dbg(VFS, "Transform message is broken\n");
cifs_reconnect(server);
wake_up(&server->response_q);
return -ECONNABORTED;
}
if (pdu_length + 4 > CIFSMaxBufSize + MAX_HEADER_SIZE(server))
return receive_encrypted_read(server, mid);
return receive_encrypted_standard(server, mid);
}
int
smb3_handle_read_data(struct TCP_Server_Info *server, struct mid_q_entry *mid)
{
char *buf = server->large_buf ? server->bigbuf : server->smallbuf;
return handle_read_data(server, mid, buf, get_rfc1002_length(buf) + 4,
NULL, 0, 0);
}
