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
if (total_data_size > CIFSMaxBufSize) {
cERROR(1, "TotalDataSize %d is over maximum buffer %d",
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
cFYI(1, "total data count of primary and secondary t2 differ "
"source=%hu target=%hu", src_total_cnt, tgt_total_cnt);
total_in_tgt = get_unaligned_le16(&pSMBt->t2_rsp.DataCount);
remaining = tgt_total_cnt - total_in_tgt;
if (remaining < 0) {
cFYI(1, "Server sent too much data. tgt_total_cnt=%hu "
"total_in_tgt=%hu", tgt_total_cnt, total_in_tgt);
return -EPROTO;
}
if (remaining == 0) {
cFYI(1, "no more data remains");
return 0;
}
total_in_src = get_unaligned_le16(&pSMBs->t2_rsp.DataCount);
if (remaining < total_in_src)
cFYI(1, "transact2 2nd response contains too much data");
data_area_of_tgt = (char *)&pSMBt->hdr.Protocol +
get_unaligned_le16(&pSMBt->t2_rsp.DataOffset);
data_area_of_src = (char *)&pSMBs->hdr.Protocol +
get_unaligned_le16(&pSMBs->t2_rsp.DataOffset);
data_area_of_tgt += total_in_tgt;
total_in_tgt += total_in_src;
if (total_in_tgt > USHRT_MAX) {
cFYI(1, "coalesced DataCount too large (%u)", total_in_tgt);
return -EPROTO;
}
put_unaligned_le16(total_in_tgt, &pSMBt->t2_rsp.DataCount);
byte_count = get_bcc(target_hdr);
byte_count += total_in_src;
if (byte_count > USHRT_MAX) {
cFYI(1, "coalesced BCC too large (%u)", byte_count);
return -EPROTO;
}
put_bcc(byte_count, target_hdr);
byte_count = be32_to_cpu(target_hdr->smb_buf_length);
byte_count += total_in_src;
if (byte_count > CIFSMaxBufSize + MAX_CIFS_HDR_SIZE - 4) {
cFYI(1, "coalesced BCC exceeds buffer size (%u)", byte_count);
return -ENOBUFS;
}
target_hdr->smb_buf_length = cpu_to_be32(byte_count);
memcpy(data_area_of_tgt, data_area_of_src, total_in_src);
if (remaining != total_in_src) {
cFYI(1, "waiting for more secondary responses");
return 1;
}
cFYI(1, "found the last secondary response");
return 0;
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
cERROR(1, "1st trans2 resp needs bigbuf");
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
cifs_sb->mnt_cifs_flags &
CIFS_MOUNT_MAP_SPECIAL_CHR);
if (rc == -EOPNOTSUPP || rc == -EINVAL)
rc = SMBQueryInformation(xid, tcon, full_path, file_info,
cifs_sb->local_nls, cifs_sb->mnt_cifs_flags &
CIFS_MOUNT_MAP_SPECIAL_CHR);
kfree(file_info);
return rc;
}
static int
cifs_query_path_info(const unsigned int xid, struct cifs_tcon *tcon,
struct cifs_sb_info *cifs_sb, const char *full_path,
FILE_ALL_INFO *data, bool *adjustTZ)
{
int rc;
rc = CIFSSMBQPathInfo(xid, tcon, full_path, data, 0 ,
cifs_sb->local_nls, cifs_sb->mnt_cifs_flags &
CIFS_MOUNT_MAP_SPECIAL_CHR);
if ((rc == -EOPNOTSUPP) || (rc == -EINVAL)) {
rc = SMBQueryInformation(xid, tcon, full_path, data,
cifs_sb->local_nls,
cifs_sb->mnt_cifs_flags &
CIFS_MOUNT_MAP_SPECIAL_CHR);
*adjustTZ = true;
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
cifs_sb->mnt_cifs_flags &
CIFS_MOUNT_MAP_SPECIAL_CHR);
}
static char *
cifs_build_path_to_root(struct smb_vol *vol, struct cifs_sb_info *cifs_sb,
struct cifs_tcon *tcon)
{
int pplen = vol->prepath ? strlen(vol->prepath) : 0;
int dfsplen;
char *full_path = NULL;
if (pplen == 0) {
full_path = kzalloc(1, GFP_KERNEL);
return full_path;
}
if (tcon->Flags & SMB_SHARE_IS_IN_DFS)
dfsplen = strnlen(tcon->treeName, MAX_TREE_SIZE + 1);
else
dfsplen = 0;
full_path = kmalloc(dfsplen + pplen + 1, GFP_KERNEL);
if (full_path == NULL)
return full_path;
if (dfsplen)
strncpy(full_path, tcon->treeName, dfsplen);
strncpy(full_path + dfsplen, vol->prepath, pplen);
convert_delimiter(full_path, CIFS_DIR_SEP(cifs_sb));
full_path[dfsplen + pplen] = 0;
return full_path;
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
cifs_sb->mnt_cifs_flags &
CIFS_MOUNT_MAP_SPECIAL_CHR);
if (rc == 0)
cifsInode->cifsAttrs = dosattrs;
}
