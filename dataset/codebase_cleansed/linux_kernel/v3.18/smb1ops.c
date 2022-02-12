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
--server->sequence_number;
rc = smb_send(server, in_buf, be32_to_cpu(in_buf->smb_buf_length));
if (rc < 0)
server->sequence_number--;
mutex_unlock(&server->srv_mutex);
cifs_dbg(FYI, "issued NT_CANCEL for mid %u, rc = %d\n",
get_mid(in_buf), rc);
return rc;
}
static bool
cifs_compare_fids(struct cifsFileInfo *ob1, struct cifsFileInfo *ob2)
{
return ob1->fid.netfid == ob2->fid.netfid;
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
if (compare_mid(mid->mid, buf) &&
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
cifs_add_credits(struct TCP_Server_Info *server, const unsigned int add,
const int optype)
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
cifs_get_credits_field(struct TCP_Server_Info *server, const int optype)
{
return &server->credits;
}
static unsigned int
cifs_get_credits(struct mid_q_entry *mid)
{
return 1;
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
static int
check2ndT2(char *buf)
{
struct smb_hdr *pSMB = (struct smb_hdr *)buf;
struct smb_t2_rsp *pSMBt;
int remaining;
__u16 total_data_size, data_in_this_rsp;
if (pSMB->Command != SMB_COM_TRANSACTION2)
return 0;
if (pSMB->WordCount != 10) {
cifs_dbg(FYI, "invalid transact2 word count\n");
return -EINVAL;
}
pSMBt = (struct smb_t2_rsp *)pSMB;
total_data_size = get_unaligned_le16(&pSMBt->t2_rsp.TotalDataCount);
data_in_this_rsp = get_unaligned_le16(&pSMBt->t2_rsp.DataCount);
if (total_data_size == data_in_this_rsp)
return 0;
else if (total_data_size < data_in_this_rsp) {
cifs_dbg(FYI, "total data %d smaller than data in frame %d\n",
total_data_size, data_in_this_rsp);
return -EINVAL;
}
remaining = total_data_size - data_in_this_rsp;
cifs_dbg(FYI, "missing %d bytes from transact2, check next response\n",
remaining);
if (total_data_size > CIFSMaxBufSize) {
cifs_dbg(VFS, "TotalDataSize %d is over maximum buffer %d\n",
total_data_size, CIFSMaxBufSize);
return -EINVAL;
}
return remaining;
}
static int
coalesce_t2(char *second_buf, struct smb_hdr *target_hdr)
{
struct smb_t2_rsp *pSMBs = (struct smb_t2_rsp *)second_buf;
struct smb_t2_rsp *pSMBt = (struct smb_t2_rsp *)target_hdr;
char *data_area_of_tgt;
char *data_area_of_src;
int remaining;
unsigned int byte_count, total_in_tgt;
__u16 tgt_total_cnt, src_total_cnt, total_in_src;
src_total_cnt = get_unaligned_le16(&pSMBs->t2_rsp.TotalDataCount);
tgt_total_cnt = get_unaligned_le16(&pSMBt->t2_rsp.TotalDataCount);
if (tgt_total_cnt != src_total_cnt)
cifs_dbg(FYI, "total data count of primary and secondary t2 differ source=%hu target=%hu\n",
src_total_cnt, tgt_total_cnt);
total_in_tgt = get_unaligned_le16(&pSMBt->t2_rsp.DataCount);
remaining = tgt_total_cnt - total_in_tgt;
if (remaining < 0) {
cifs_dbg(FYI, "Server sent too much data. tgt_total_cnt=%hu total_in_tgt=%hu\n",
tgt_total_cnt, total_in_tgt);
return -EPROTO;
}
if (remaining == 0) {
cifs_dbg(FYI, "no more data remains\n");
return 0;
}
total_in_src = get_unaligned_le16(&pSMBs->t2_rsp.DataCount);
if (remaining < total_in_src)
cifs_dbg(FYI, "transact2 2nd response contains too much data\n");
data_area_of_tgt = (char *)&pSMBt->hdr.Protocol +
get_unaligned_le16(&pSMBt->t2_rsp.DataOffset);
data_area_of_src = (char *)&pSMBs->hdr.Protocol +
get_unaligned_le16(&pSMBs->t2_rsp.DataOffset);
data_area_of_tgt += total_in_tgt;
total_in_tgt += total_in_src;
if (total_in_tgt > USHRT_MAX) {
cifs_dbg(FYI, "coalesced DataCount too large (%u)\n",
total_in_tgt);
return -EPROTO;
}
put_unaligned_le16(total_in_tgt, &pSMBt->t2_rsp.DataCount);
byte_count = get_bcc(target_hdr);
byte_count += total_in_src;
if (byte_count > USHRT_MAX) {
cifs_dbg(FYI, "coalesced BCC too large (%u)\n", byte_count);
return -EPROTO;
}
put_bcc(byte_count, target_hdr);
byte_count = be32_to_cpu(target_hdr->smb_buf_length);
byte_count += total_in_src;
if (byte_count > CIFSMaxBufSize + MAX_CIFS_HDR_SIZE - 4) {
cifs_dbg(FYI, "coalesced BCC exceeds buffer size (%u)\n",
byte_count);
return -ENOBUFS;
}
target_hdr->smb_buf_length = cpu_to_be32(byte_count);
memcpy(data_area_of_tgt, data_area_of_src, total_in_src);
if (remaining != total_in_src) {
cifs_dbg(FYI, "waiting for more secondary responses\n");
return 1;
}
cifs_dbg(FYI, "found the last secondary response\n");
return 0;
}
static void
cifs_downgrade_oplock(struct TCP_Server_Info *server,
struct cifsInodeInfo *cinode, bool set_level2)
{
if (set_level2)
cifs_set_oplock_level(cinode, OPLOCK_READ);
else
cifs_set_oplock_level(cinode, 0);
}
static bool
cifs_check_trans2(struct mid_q_entry *mid, struct TCP_Server_Info *server,
char *buf, int malformed)
{
if (malformed)
return false;
if (check2ndT2(buf) <= 0)
return false;
mid->multiRsp = true;
if (mid->resp_buf) {
malformed = coalesce_t2(buf, mid->resp_buf);
if (malformed > 0)
return true;
mid->multiEnd = true;
dequeue_mid(mid, malformed);
return true;
}
if (!server->large_buf) {
cifs_dbg(VFS, "1st trans2 resp needs bigbuf\n");
} else {
mid->resp_buf = buf;
mid->large_buf = true;
server->bigbuf = NULL;
}
return true;
}
static bool
cifs_need_neg(struct TCP_Server_Info *server)
{
return server->maxBuf == 0;
}
static int
cifs_negotiate(const unsigned int xid, struct cifs_ses *ses)
{
int rc;
rc = CIFSSMBNegotiate(xid, ses);
if (rc == -EAGAIN) {
set_credits(ses->server, 1);
rc = CIFSSMBNegotiate(xid, ses);
if (rc == -EAGAIN)
rc = -EHOSTDOWN;
}
return rc;
}
static unsigned int
cifs_negotiate_wsize(struct cifs_tcon *tcon, struct smb_vol *volume_info)
{
__u64 unix_cap = le64_to_cpu(tcon->fsUnixInfo.Capability);
struct TCP_Server_Info *server = tcon->ses->server;
unsigned int wsize;
if (volume_info->wsize)
wsize = volume_info->wsize;
else if (tcon->unix_ext && (unix_cap & CIFS_UNIX_LARGE_WRITE_CAP))
wsize = CIFS_DEFAULT_IOSIZE;
else
wsize = CIFS_DEFAULT_NON_POSIX_WSIZE;
if (!tcon->unix_ext || !(unix_cap & CIFS_UNIX_LARGE_WRITE_CAP))
wsize = min_t(unsigned int, wsize, CIFS_MAX_RFC1002_WSIZE);
if (!(server->capabilities & CAP_LARGE_WRITE_X) ||
(!(server->capabilities & CAP_UNIX) && server->sign))
wsize = min_t(unsigned int, wsize,
server->maxBuf - sizeof(WRITE_REQ) + 4);
wsize = min_t(unsigned int, wsize, CIFS_MAX_WSIZE);
return wsize;
}
static unsigned int
cifs_negotiate_rsize(struct cifs_tcon *tcon, struct smb_vol *volume_info)
{
__u64 unix_cap = le64_to_cpu(tcon->fsUnixInfo.Capability);
struct TCP_Server_Info *server = tcon->ses->server;
unsigned int rsize, defsize;
if (tcon->unix_ext && (unix_cap & CIFS_UNIX_LARGE_READ_CAP))
defsize = CIFS_DEFAULT_IOSIZE;
else if (server->capabilities & CAP_LARGE_READ_X)
defsize = CIFS_DEFAULT_NON_POSIX_RSIZE;
else
defsize = server->maxBuf - sizeof(READ_RSP);
rsize = volume_info->rsize ? volume_info->rsize : defsize;
if (!(server->capabilities & CAP_LARGE_READ_X))
rsize = min_t(unsigned int, CIFSMaxBufSize, rsize);
rsize = min_t(unsigned int, rsize, CIFS_MAX_RSIZE);
return rsize;
}
static void
cifs_qfs_tcon(const unsigned int xid, struct cifs_tcon *tcon)
{
CIFSSMBQFSDeviceInfo(xid, tcon);
CIFSSMBQFSAttributeInfo(xid, tcon);
}
static int
cifs_is_path_accessible(const unsigned int xid, struct cifs_tcon *tcon,
struct cifs_sb_info *cifs_sb, const char *full_path)
{
int rc;
FILE_ALL_INFO *file_info;
file_info = kmalloc(sizeof(FILE_ALL_INFO), GFP_KERNEL);
if (file_info == NULL)
return -ENOMEM;
rc = CIFSSMBQPathInfo(xid, tcon, full_path, file_info,
0 , cifs_sb->local_nls,
cifs_remap(cifs_sb));
if (rc == -EOPNOTSUPP || rc == -EINVAL)
rc = SMBQueryInformation(xid, tcon, full_path, file_info,
cifs_sb->local_nls, cifs_remap(cifs_sb));
kfree(file_info);
return rc;
}
static int
cifs_query_path_info(const unsigned int xid, struct cifs_tcon *tcon,
struct cifs_sb_info *cifs_sb, const char *full_path,
FILE_ALL_INFO *data, bool *adjustTZ, bool *symlink)
{
int rc;
*symlink = false;
rc = CIFSSMBQPathInfo(xid, tcon, full_path, data, 0 ,
cifs_sb->local_nls, cifs_remap(cifs_sb));
if ((rc == -EOPNOTSUPP) || (rc == -EINVAL)) {
rc = SMBQueryInformation(xid, tcon, full_path, data,
cifs_sb->local_nls,
cifs_remap(cifs_sb));
*adjustTZ = true;
}
if (!rc && (le32_to_cpu(data->Attributes) & ATTR_REPARSE)) {
int tmprc;
int oplock = 0;
struct cifs_fid fid;
struct cifs_open_parms oparms;
oparms.tcon = tcon;
oparms.cifs_sb = cifs_sb;
oparms.desired_access = FILE_READ_ATTRIBUTES;
oparms.create_options = 0;
oparms.disposition = FILE_OPEN;
oparms.path = full_path;
oparms.fid = &fid;
oparms.reconnect = false;
tmprc = CIFS_open(xid, &oparms, &oplock, NULL);
if (tmprc == -EOPNOTSUPP)
*symlink = true;
else if (tmprc == 0)
CIFSSMBClose(xid, tcon, fid.netfid);
}
return rc;
}
static int
cifs_get_srv_inum(const unsigned int xid, struct cifs_tcon *tcon,
struct cifs_sb_info *cifs_sb, const char *full_path,
u64 *uniqueid, FILE_ALL_INFO *data)
{
return CIFSGetSrvInodeNumber(xid, tcon, full_path, uniqueid,
cifs_sb->local_nls,
cifs_remap(cifs_sb));
}
static int
cifs_query_file_info(const unsigned int xid, struct cifs_tcon *tcon,
struct cifs_fid *fid, FILE_ALL_INFO *data)
{
return CIFSSMBQFileInfo(xid, tcon, fid->netfid, data);
}
static void
cifs_clear_stats(struct cifs_tcon *tcon)
{
#ifdef CONFIG_CIFS_STATS
atomic_set(&tcon->stats.cifs_stats.num_writes, 0);
atomic_set(&tcon->stats.cifs_stats.num_reads, 0);
atomic_set(&tcon->stats.cifs_stats.num_flushes, 0);
atomic_set(&tcon->stats.cifs_stats.num_oplock_brks, 0);
atomic_set(&tcon->stats.cifs_stats.num_opens, 0);
atomic_set(&tcon->stats.cifs_stats.num_posixopens, 0);
atomic_set(&tcon->stats.cifs_stats.num_posixmkdirs, 0);
atomic_set(&tcon->stats.cifs_stats.num_closes, 0);
atomic_set(&tcon->stats.cifs_stats.num_deletes, 0);
atomic_set(&tcon->stats.cifs_stats.num_mkdirs, 0);
atomic_set(&tcon->stats.cifs_stats.num_rmdirs, 0);
atomic_set(&tcon->stats.cifs_stats.num_renames, 0);
atomic_set(&tcon->stats.cifs_stats.num_t2renames, 0);
atomic_set(&tcon->stats.cifs_stats.num_ffirst, 0);
atomic_set(&tcon->stats.cifs_stats.num_fnext, 0);
atomic_set(&tcon->stats.cifs_stats.num_fclose, 0);
atomic_set(&tcon->stats.cifs_stats.num_hardlinks, 0);
atomic_set(&tcon->stats.cifs_stats.num_symlinks, 0);
atomic_set(&tcon->stats.cifs_stats.num_locks, 0);
atomic_set(&tcon->stats.cifs_stats.num_acl_get, 0);
atomic_set(&tcon->stats.cifs_stats.num_acl_set, 0);
#endif
}
static void
cifs_print_stats(struct seq_file *m, struct cifs_tcon *tcon)
{
#ifdef CONFIG_CIFS_STATS
seq_printf(m, " Oplocks breaks: %d",
atomic_read(&tcon->stats.cifs_stats.num_oplock_brks));
seq_printf(m, "\nReads: %d Bytes: %llu",
atomic_read(&tcon->stats.cifs_stats.num_reads),
(long long)(tcon->bytes_read));
seq_printf(m, "\nWrites: %d Bytes: %llu",
atomic_read(&tcon->stats.cifs_stats.num_writes),
(long long)(tcon->bytes_written));
seq_printf(m, "\nFlushes: %d",
atomic_read(&tcon->stats.cifs_stats.num_flushes));
seq_printf(m, "\nLocks: %d HardLinks: %d Symlinks: %d",
atomic_read(&tcon->stats.cifs_stats.num_locks),
atomic_read(&tcon->stats.cifs_stats.num_hardlinks),
atomic_read(&tcon->stats.cifs_stats.num_symlinks));
seq_printf(m, "\nOpens: %d Closes: %d Deletes: %d",
atomic_read(&tcon->stats.cifs_stats.num_opens),
atomic_read(&tcon->stats.cifs_stats.num_closes),
atomic_read(&tcon->stats.cifs_stats.num_deletes));
seq_printf(m, "\nPosix Opens: %d Posix Mkdirs: %d",
atomic_read(&tcon->stats.cifs_stats.num_posixopens),
atomic_read(&tcon->stats.cifs_stats.num_posixmkdirs));
seq_printf(m, "\nMkdirs: %d Rmdirs: %d",
atomic_read(&tcon->stats.cifs_stats.num_mkdirs),
atomic_read(&tcon->stats.cifs_stats.num_rmdirs));
seq_printf(m, "\nRenames: %d T2 Renames %d",
atomic_read(&tcon->stats.cifs_stats.num_renames),
atomic_read(&tcon->stats.cifs_stats.num_t2renames));
seq_printf(m, "\nFindFirst: %d FNext %d FClose %d",
atomic_read(&tcon->stats.cifs_stats.num_ffirst),
atomic_read(&tcon->stats.cifs_stats.num_fnext),
atomic_read(&tcon->stats.cifs_stats.num_fclose));
#endif
}
static void
cifs_mkdir_setinfo(struct inode *inode, const char *full_path,
struct cifs_sb_info *cifs_sb, struct cifs_tcon *tcon,
const unsigned int xid)
{
FILE_BASIC_INFO info;
struct cifsInodeInfo *cifsInode;
u32 dosattrs;
int rc;
memset(&info, 0, sizeof(info));
cifsInode = CIFS_I(inode);
dosattrs = cifsInode->cifsAttrs|ATTR_READONLY;
info.Attributes = cpu_to_le32(dosattrs);
rc = CIFSSMBSetPathInfo(xid, tcon, full_path, &info, cifs_sb->local_nls,
cifs_remap(cifs_sb));
if (rc == 0)
cifsInode->cifsAttrs = dosattrs;
}
static int
cifs_open_file(const unsigned int xid, struct cifs_open_parms *oparms,
__u32 *oplock, FILE_ALL_INFO *buf)
{
if (!(oparms->tcon->ses->capabilities & CAP_NT_SMBS))
return SMBLegacyOpen(xid, oparms->tcon, oparms->path,
oparms->disposition,
oparms->desired_access,
oparms->create_options,
&oparms->fid->netfid, oplock, buf,
oparms->cifs_sb->local_nls,
cifs_remap(oparms->cifs_sb));
return CIFS_open(xid, oparms, oplock, buf);
}
static void
cifs_set_fid(struct cifsFileInfo *cfile, struct cifs_fid *fid, __u32 oplock)
{
struct cifsInodeInfo *cinode = CIFS_I(cfile->dentry->d_inode);
cfile->fid.netfid = fid->netfid;
cifs_set_oplock_level(cinode, oplock);
cinode->can_cache_brlcks = CIFS_CACHE_WRITE(cinode);
}
static void
cifs_close_file(const unsigned int xid, struct cifs_tcon *tcon,
struct cifs_fid *fid)
{
CIFSSMBClose(xid, tcon, fid->netfid);
}
static int
cifs_flush_file(const unsigned int xid, struct cifs_tcon *tcon,
struct cifs_fid *fid)
{
return CIFSSMBFlush(xid, tcon, fid->netfid);
}
static int
cifs_sync_read(const unsigned int xid, struct cifs_fid *pfid,
struct cifs_io_parms *parms, unsigned int *bytes_read,
char **buf, int *buf_type)
{
parms->netfid = pfid->netfid;
return CIFSSMBRead(xid, parms, bytes_read, buf, buf_type);
}
static int
cifs_sync_write(const unsigned int xid, struct cifs_fid *pfid,
struct cifs_io_parms *parms, unsigned int *written,
struct kvec *iov, unsigned long nr_segs)
{
parms->netfid = pfid->netfid;
return CIFSSMBWrite2(xid, parms, written, iov, nr_segs);
}
static int
smb_set_file_info(struct inode *inode, const char *full_path,
FILE_BASIC_INFO *buf, const unsigned int xid)
{
int oplock = 0;
int rc;
__u32 netpid;
struct cifs_fid fid;
struct cifs_open_parms oparms;
struct cifsFileInfo *open_file;
struct cifsInodeInfo *cinode = CIFS_I(inode);
struct cifs_sb_info *cifs_sb = CIFS_SB(inode->i_sb);
struct tcon_link *tlink = NULL;
struct cifs_tcon *tcon;
open_file = find_writable_file(cinode, true);
if (open_file) {
fid.netfid = open_file->fid.netfid;
netpid = open_file->pid;
tcon = tlink_tcon(open_file->tlink);
goto set_via_filehandle;
}
tlink = cifs_sb_tlink(cifs_sb);
if (IS_ERR(tlink)) {
rc = PTR_ERR(tlink);
tlink = NULL;
goto out;
}
tcon = tlink_tcon(tlink);
rc = CIFSSMBSetPathInfo(xid, tcon, full_path, buf, cifs_sb->local_nls,
cifs_remap(cifs_sb));
if (rc == 0) {
cinode->cifsAttrs = le32_to_cpu(buf->Attributes);
goto out;
} else if (rc != -EOPNOTSUPP && rc != -EINVAL) {
goto out;
}
oparms.tcon = tcon;
oparms.cifs_sb = cifs_sb;
oparms.desired_access = SYNCHRONIZE | FILE_WRITE_ATTRIBUTES;
oparms.create_options = CREATE_NOT_DIR;
oparms.disposition = FILE_OPEN;
oparms.path = full_path;
oparms.fid = &fid;
oparms.reconnect = false;
cifs_dbg(FYI, "calling SetFileInfo since SetPathInfo for times not supported by this server\n");
rc = CIFS_open(xid, &oparms, &oplock, NULL);
if (rc != 0) {
if (rc == -EIO)
rc = -EINVAL;
goto out;
}
netpid = current->tgid;
set_via_filehandle:
rc = CIFSSMBSetFileInfo(xid, tcon, buf, fid.netfid, netpid);
if (!rc)
cinode->cifsAttrs = le32_to_cpu(buf->Attributes);
if (open_file == NULL)
CIFSSMBClose(xid, tcon, fid.netfid);
else
cifsFileInfo_put(open_file);
out:
if (tlink != NULL)
cifs_put_tlink(tlink);
return rc;
}
static int
cifs_set_compression(const unsigned int xid, struct cifs_tcon *tcon,
struct cifsFileInfo *cfile)
{
return CIFSSMB_set_compression(xid, tcon, cfile->fid.netfid);
}
static int
cifs_query_dir_first(const unsigned int xid, struct cifs_tcon *tcon,
const char *path, struct cifs_sb_info *cifs_sb,
struct cifs_fid *fid, __u16 search_flags,
struct cifs_search_info *srch_inf)
{
return CIFSFindFirst(xid, tcon, path, cifs_sb,
&fid->netfid, search_flags, srch_inf, true);
}
static int
cifs_query_dir_next(const unsigned int xid, struct cifs_tcon *tcon,
struct cifs_fid *fid, __u16 search_flags,
struct cifs_search_info *srch_inf)
{
return CIFSFindNext(xid, tcon, fid->netfid, search_flags, srch_inf);
}
static int
cifs_close_dir(const unsigned int xid, struct cifs_tcon *tcon,
struct cifs_fid *fid)
{
return CIFSFindClose(xid, tcon, fid->netfid);
}
static int
cifs_oplock_response(struct cifs_tcon *tcon, struct cifs_fid *fid,
struct cifsInodeInfo *cinode)
{
return CIFSSMBLock(0, tcon, fid->netfid, current->tgid, 0, 0, 0, 0,
LOCKING_ANDX_OPLOCK_RELEASE, false,
CIFS_CACHE_READ(cinode) ? 1 : 0);
}
static int
cifs_queryfs(const unsigned int xid, struct cifs_tcon *tcon,
struct kstatfs *buf)
{
int rc = -EOPNOTSUPP;
buf->f_type = CIFS_MAGIC_NUMBER;
if ((tcon->ses->capabilities & CAP_UNIX) &&
(CIFS_POSIX_EXTENSIONS & le64_to_cpu(tcon->fsUnixInfo.Capability)))
rc = CIFSSMBQFSPosixInfo(xid, tcon, buf);
if (rc && (tcon->ses->capabilities & CAP_NT_SMBS))
rc = CIFSSMBQFSInfo(xid, tcon, buf);
if (rc)
rc = SMBOldQFSInfo(xid, tcon, buf);
return rc;
}
static int
cifs_mand_lock(const unsigned int xid, struct cifsFileInfo *cfile, __u64 offset,
__u64 length, __u32 type, int lock, int unlock, bool wait)
{
return CIFSSMBLock(xid, tlink_tcon(cfile->tlink), cfile->fid.netfid,
current->tgid, length, offset, unlock, lock,
(__u8)type, wait, 0);
}
static int
cifs_unix_dfs_readlink(const unsigned int xid, struct cifs_tcon *tcon,
const unsigned char *searchName, char **symlinkinfo,
const struct nls_table *nls_codepage)
{
#ifdef CONFIG_CIFS_DFS_UPCALL
int rc;
unsigned int num_referrals = 0;
struct dfs_info3_param *referrals = NULL;
rc = get_dfs_path(xid, tcon->ses, searchName, nls_codepage,
&num_referrals, &referrals, 0);
if (!rc && num_referrals > 0) {
*symlinkinfo = kstrndup(referrals->node_name,
strlen(referrals->node_name),
GFP_KERNEL);
if (!*symlinkinfo)
rc = -ENOMEM;
free_dfs_info_array(referrals, num_referrals);
}
return rc;
#else
return -EREMOTE;
#endif
}
static int
cifs_query_symlink(const unsigned int xid, struct cifs_tcon *tcon,
const char *full_path, char **target_path,
struct cifs_sb_info *cifs_sb)
{
int rc;
int oplock = 0;
struct cifs_fid fid;
struct cifs_open_parms oparms;
cifs_dbg(FYI, "%s: path: %s\n", __func__, full_path);
if (cap_unix(tcon->ses)) {
rc = CIFSSMBUnixQuerySymLink(xid, tcon, full_path, target_path,
cifs_sb->local_nls);
if (rc == -EREMOTE)
rc = cifs_unix_dfs_readlink(xid, tcon, full_path,
target_path,
cifs_sb->local_nls);
goto out;
}
oparms.tcon = tcon;
oparms.cifs_sb = cifs_sb;
oparms.desired_access = FILE_READ_ATTRIBUTES;
oparms.create_options = OPEN_REPARSE_POINT;
oparms.disposition = FILE_OPEN;
oparms.path = full_path;
oparms.fid = &fid;
oparms.reconnect = false;
rc = CIFS_open(xid, &oparms, &oplock, NULL);
if (rc)
goto out;
rc = CIFSSMBQuerySymLink(xid, tcon, fid.netfid, target_path,
cifs_sb->local_nls);
if (rc)
goto out_close;
convert_delimiter(*target_path, '/');
out_close:
CIFSSMBClose(xid, tcon, fid.netfid);
out:
if (!rc)
cifs_dbg(FYI, "%s: target path: %s\n", __func__, *target_path);
return rc;
}
static bool
cifs_is_read_op(__u32 oplock)
{
return oplock == OPLOCK_READ;
}
static unsigned int
cifs_wp_retry_size(struct inode *inode)
{
return CIFS_SB(inode->i_sb)->wsize;
}
static bool
cifs_dir_needs_close(struct cifsFileInfo *cfile)
{
return !cfile->srch_inf.endOfSearch && !cfile->invalidHandle;
}
