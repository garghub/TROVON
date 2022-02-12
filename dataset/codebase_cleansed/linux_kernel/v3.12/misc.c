unsigned int
_get_xid(void)
{
unsigned int xid;
spin_lock(&GlobalMid_Lock);
GlobalTotalActiveXid++;
if (GlobalTotalActiveXid > GlobalMaxActiveXid)
GlobalMaxActiveXid = GlobalTotalActiveXid;
if (GlobalTotalActiveXid > 65000)
cifs_dbg(FYI, "warning: more than 65000 requests active\n");
xid = GlobalCurrentXid++;
spin_unlock(&GlobalMid_Lock);
return xid;
}
void
_free_xid(unsigned int xid)
{
spin_lock(&GlobalMid_Lock);
GlobalTotalActiveXid--;
spin_unlock(&GlobalMid_Lock);
}
struct cifs_ses *
sesInfoAlloc(void)
{
struct cifs_ses *ret_buf;
ret_buf = kzalloc(sizeof(struct cifs_ses), GFP_KERNEL);
if (ret_buf) {
atomic_inc(&sesInfoAllocCount);
ret_buf->status = CifsNew;
++ret_buf->ses_count;
INIT_LIST_HEAD(&ret_buf->smb_ses_list);
INIT_LIST_HEAD(&ret_buf->tcon_list);
mutex_init(&ret_buf->session_mutex);
}
return ret_buf;
}
void
sesInfoFree(struct cifs_ses *buf_to_free)
{
if (buf_to_free == NULL) {
cifs_dbg(FYI, "Null buffer passed to sesInfoFree\n");
return;
}
atomic_dec(&sesInfoAllocCount);
kfree(buf_to_free->serverOS);
kfree(buf_to_free->serverDomain);
kfree(buf_to_free->serverNOS);
if (buf_to_free->password) {
memset(buf_to_free->password, 0, strlen(buf_to_free->password));
kfree(buf_to_free->password);
}
kfree(buf_to_free->user_name);
kfree(buf_to_free->domainName);
kfree(buf_to_free->auth_key.response);
kfree(buf_to_free);
}
struct cifs_tcon *
tconInfoAlloc(void)
{
struct cifs_tcon *ret_buf;
ret_buf = kzalloc(sizeof(struct cifs_tcon), GFP_KERNEL);
if (ret_buf) {
atomic_inc(&tconInfoAllocCount);
ret_buf->tidStatus = CifsNew;
++ret_buf->tc_count;
INIT_LIST_HEAD(&ret_buf->openFileList);
INIT_LIST_HEAD(&ret_buf->tcon_list);
#ifdef CONFIG_CIFS_STATS
spin_lock_init(&ret_buf->stat_lock);
#endif
}
return ret_buf;
}
void
tconInfoFree(struct cifs_tcon *buf_to_free)
{
if (buf_to_free == NULL) {
cifs_dbg(FYI, "Null buffer passed to tconInfoFree\n");
return;
}
atomic_dec(&tconInfoAllocCount);
kfree(buf_to_free->nativeFileSystem);
if (buf_to_free->password) {
memset(buf_to_free->password, 0, strlen(buf_to_free->password));
kfree(buf_to_free->password);
}
kfree(buf_to_free);
}
struct smb_hdr *
cifs_buf_get(void)
{
struct smb_hdr *ret_buf = NULL;
size_t buf_size = sizeof(struct smb_hdr);
#ifdef CONFIG_CIFS_SMB2
buf_size = sizeof(struct smb2_hdr);
#endif
ret_buf = mempool_alloc(cifs_req_poolp, GFP_NOFS);
if (ret_buf) {
memset(ret_buf, 0, buf_size + 3);
atomic_inc(&bufAllocCount);
#ifdef CONFIG_CIFS_STATS2
atomic_inc(&totBufAllocCount);
#endif
}
return ret_buf;
}
void
cifs_buf_release(void *buf_to_free)
{
if (buf_to_free == NULL) {
return;
}
mempool_free(buf_to_free, cifs_req_poolp);
atomic_dec(&bufAllocCount);
return;
}
struct smb_hdr *
cifs_small_buf_get(void)
{
struct smb_hdr *ret_buf = NULL;
ret_buf = mempool_alloc(cifs_sm_req_poolp, GFP_NOFS);
if (ret_buf) {
atomic_inc(&smBufAllocCount);
#ifdef CONFIG_CIFS_STATS2
atomic_inc(&totSmBufAllocCount);
#endif
}
return ret_buf;
}
void
cifs_small_buf_release(void *buf_to_free)
{
if (buf_to_free == NULL) {
cifs_dbg(FYI, "Null buffer passed to cifs_small_buf_release\n");
return;
}
mempool_free(buf_to_free, cifs_sm_req_poolp);
atomic_dec(&smBufAllocCount);
return;
}
void
header_assemble(struct smb_hdr *buffer, char smb_command ,
const struct cifs_tcon *treeCon, int word_count
)
{
char *temp = (char *) buffer;
memset(temp, 0, 256);
buffer->smb_buf_length = cpu_to_be32(
(2 * word_count) + sizeof(struct smb_hdr) -
4 +
2 ) ;
buffer->Protocol[0] = 0xFF;
buffer->Protocol[1] = 'S';
buffer->Protocol[2] = 'M';
buffer->Protocol[3] = 'B';
buffer->Command = smb_command;
buffer->Flags = 0x00;
buffer->Flags2 = SMBFLG2_KNOWS_LONG_NAMES;
buffer->Pid = cpu_to_le16((__u16)current->tgid);
buffer->PidHigh = cpu_to_le16((__u16)(current->tgid >> 16));
if (treeCon) {
buffer->Tid = treeCon->tid;
if (treeCon->ses) {
if (treeCon->ses->capabilities & CAP_UNICODE)
buffer->Flags2 |= SMBFLG2_UNICODE;
if (treeCon->ses->capabilities & CAP_STATUS32)
buffer->Flags2 |= SMBFLG2_ERR_STATUS;
buffer->Uid = treeCon->ses->Suid;
buffer->Mid = get_next_mid(treeCon->ses->server);
}
if (treeCon->Flags & SMB_SHARE_IS_IN_DFS)
buffer->Flags2 |= SMBFLG2_DFS;
if (treeCon->nocase)
buffer->Flags |= SMBFLG_CASELESS;
if ((treeCon->ses) && (treeCon->ses->server))
if (treeCon->ses->server->sign)
buffer->Flags2 |= SMBFLG2_SECURITY_SIGNATURE;
}
buffer->WordCount = (char) word_count;
return;
}
static int
check_smb_hdr(struct smb_hdr *smb, __u16 mid)
{
if (*(__le32 *) smb->Protocol != cpu_to_le32(0x424d53ff)) {
cifs_dbg(VFS, "Bad protocol string signature header 0x%x\n",
*(unsigned int *)smb->Protocol);
return 1;
}
if (mid != smb->Mid) {
cifs_dbg(VFS, "Mids do not match. received=%u expected=%u\n",
smb->Mid, mid);
return 1;
}
if (smb->Flags & SMBFLG_RESPONSE)
return 0;
if (smb->Command == SMB_COM_LOCKING_ANDX)
return 0;
cifs_dbg(VFS, "Server sent request, not response. mid=%u\n", smb->Mid);
return 1;
}
int
checkSMB(char *buf, unsigned int total_read)
{
struct smb_hdr *smb = (struct smb_hdr *)buf;
__u16 mid = smb->Mid;
__u32 rfclen = be32_to_cpu(smb->smb_buf_length);
__u32 clc_len;
cifs_dbg(FYI, "checkSMB Length: 0x%x, smb_buf_length: 0x%x\n",
total_read, rfclen);
if (total_read < 2 + sizeof(struct smb_hdr)) {
if ((total_read >= sizeof(struct smb_hdr) - 1)
&& (smb->Status.CifsError != 0)) {
smb->WordCount = 0;
return 0;
} else if ((total_read == sizeof(struct smb_hdr) + 1) &&
(smb->WordCount == 0)) {
char *tmp = (char *)smb;
if (tmp[sizeof(struct smb_hdr)] == 0) {
tmp[sizeof(struct smb_hdr)+1] = 0;
return 0;
}
cifs_dbg(VFS, "rcvd invalid byte count (bcc)\n");
} else {
cifs_dbg(VFS, "Length less than smb header size\n");
}
return -EIO;
}
if (check_smb_hdr(smb, mid))
return -EIO;
clc_len = smbCalcSize(smb);
if (4 + rfclen != total_read) {
cifs_dbg(VFS, "Length read does not match RFC1001 length %d\n",
rfclen);
return -EIO;
}
if (4 + rfclen != clc_len) {
if ((rfclen > 64 * 1024) && (rfclen > clc_len)) {
if (((4 + rfclen) & 0xFFFF) == (clc_len & 0xFFFF))
return 0;
}
cifs_dbg(FYI, "Calculated size %u vs length %u mismatch for mid=%u\n",
clc_len, 4 + rfclen, smb->Mid);
if (4 + rfclen < clc_len) {
cifs_dbg(VFS, "RFC1001 size %u smaller than SMB for mid=%u\n",
rfclen, smb->Mid);
return -EIO;
} else if (rfclen > clc_len + 512) {
cifs_dbg(VFS, "RFC1001 size %u more than 512 bytes larger than SMB for mid=%u\n",
rfclen, smb->Mid);
return -EIO;
}
}
return 0;
}
bool
is_valid_oplock_break(char *buffer, struct TCP_Server_Info *srv)
{
struct smb_hdr *buf = (struct smb_hdr *)buffer;
struct smb_com_lock_req *pSMB = (struct smb_com_lock_req *)buf;
struct list_head *tmp, *tmp1, *tmp2;
struct cifs_ses *ses;
struct cifs_tcon *tcon;
struct cifsInodeInfo *pCifsInode;
struct cifsFileInfo *netfile;
cifs_dbg(FYI, "Checking for oplock break or dnotify response\n");
if ((pSMB->hdr.Command == SMB_COM_NT_TRANSACT) &&
(pSMB->hdr.Flags & SMBFLG_RESPONSE)) {
struct smb_com_transaction_change_notify_rsp *pSMBr =
(struct smb_com_transaction_change_notify_rsp *)buf;
struct file_notify_information *pnotify;
__u32 data_offset = 0;
if (get_bcc(buf) > sizeof(struct file_notify_information)) {
data_offset = le32_to_cpu(pSMBr->DataOffset);
pnotify = (struct file_notify_information *)
((char *)&pSMBr->hdr.Protocol + data_offset);
cifs_dbg(FYI, "dnotify on %s Action: 0x%x\n",
pnotify->FileName, pnotify->Action);
return true;
}
if (pSMBr->hdr.Status.CifsError) {
cifs_dbg(FYI, "notify err 0x%d\n",
pSMBr->hdr.Status.CifsError);
return true;
}
return false;
}
if (pSMB->hdr.Command != SMB_COM_LOCKING_ANDX)
return false;
if (pSMB->hdr.Flags & SMBFLG_RESPONSE) {
if ((NT_STATUS_INVALID_HANDLE) ==
le32_to_cpu(pSMB->hdr.Status.CifsError)) {
cifs_dbg(FYI, "invalid handle on oplock break\n");
return true;
} else if (ERRbadfid ==
le16_to_cpu(pSMB->hdr.Status.DosError.Error)) {
return true;
} else {
return false;
}
}
if (pSMB->hdr.WordCount != 8)
return false;
cifs_dbg(FYI, "oplock type 0x%d level 0x%d\n",
pSMB->LockType, pSMB->OplockLevel);
if (!(pSMB->LockType & LOCKING_ANDX_OPLOCK_RELEASE))
return false;
spin_lock(&cifs_tcp_ses_lock);
list_for_each(tmp, &srv->smb_ses_list) {
ses = list_entry(tmp, struct cifs_ses, smb_ses_list);
list_for_each(tmp1, &ses->tcon_list) {
tcon = list_entry(tmp1, struct cifs_tcon, tcon_list);
if (tcon->tid != buf->Tid)
continue;
cifs_stats_inc(&tcon->stats.cifs_stats.num_oplock_brks);
spin_lock(&cifs_file_list_lock);
list_for_each(tmp2, &tcon->openFileList) {
netfile = list_entry(tmp2, struct cifsFileInfo,
tlist);
if (pSMB->Fid != netfile->fid.netfid)
continue;
cifs_dbg(FYI, "file id match, oplock break\n");
pCifsInode = CIFS_I(netfile->dentry->d_inode);
cifs_set_oplock_level(pCifsInode,
pSMB->OplockLevel ? OPLOCK_READ : 0);
queue_work(cifsiod_wq,
&netfile->oplock_break);
netfile->oplock_break_cancelled = false;
spin_unlock(&cifs_file_list_lock);
spin_unlock(&cifs_tcp_ses_lock);
return true;
}
spin_unlock(&cifs_file_list_lock);
spin_unlock(&cifs_tcp_ses_lock);
cifs_dbg(FYI, "No matching file for oplock break\n");
return true;
}
}
spin_unlock(&cifs_tcp_ses_lock);
cifs_dbg(FYI, "Can not process oplock break for non-existent connection\n");
return true;
}
void
dump_smb(void *buf, int smb_buf_length)
{
int i, j;
char debug_line[17];
unsigned char *buffer = buf;
if (traceSMB == 0)
return;
for (i = 0, j = 0; i < smb_buf_length; i++, j++) {
if (i % 8 == 0) {
printk(KERN_DEBUG "| ");
j = 0;
}
printk("%0#4x ", buffer[i]);
debug_line[2 * j] = ' ';
if (isprint(buffer[i]))
debug_line[1 + (2 * j)] = buffer[i];
else
debug_line[1 + (2 * j)] = '_';
if (i % 8 == 7) {
debug_line[16] = 0;
printk(" | %s\n", debug_line);
}
}
for (; j < 8; j++) {
printk(" ");
debug_line[2 * j] = ' ';
debug_line[1 + (2 * j)] = ' ';
}
printk(" | %s\n", debug_line);
return;
}
void
cifs_autodisable_serverino(struct cifs_sb_info *cifs_sb)
{
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_SERVER_INUM) {
cifs_sb->mnt_cifs_flags &= ~CIFS_MOUNT_SERVER_INUM;
cifs_dbg(VFS, "Autodisabling the use of server inode numbers on %s. This server doesn't seem to support them properly. Hardlinks will not be recognized on this mount. Consider mounting with the \"noserverino\" option to silence this message.\n",
cifs_sb_master_tcon(cifs_sb)->treeName);
}
}
void cifs_set_oplock_level(struct cifsInodeInfo *cinode, __u32 oplock)
{
oplock &= 0xF;
if (oplock == OPLOCK_EXCLUSIVE) {
cinode->oplock = CIFS_CACHE_WRITE_FLG | CIFS_CACHE_READ_FLG;
cifs_dbg(FYI, "Exclusive Oplock granted on inode %p\n",
&cinode->vfs_inode);
} else if (oplock == OPLOCK_READ) {
cinode->oplock = CIFS_CACHE_READ_FLG;
cifs_dbg(FYI, "Level II Oplock granted on inode %p\n",
&cinode->vfs_inode);
} else
cinode->oplock = 0;
}
bool
backup_cred(struct cifs_sb_info *cifs_sb)
{
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_CIFS_BACKUPUID) {
if (uid_eq(cifs_sb->mnt_backupuid, current_fsuid()))
return true;
}
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_CIFS_BACKUPGID) {
if (in_group_p(cifs_sb->mnt_backupgid))
return true;
}
return false;
}
void
cifs_del_pending_open(struct cifs_pending_open *open)
{
spin_lock(&cifs_file_list_lock);
list_del(&open->olist);
spin_unlock(&cifs_file_list_lock);
}
void
cifs_add_pending_open_locked(struct cifs_fid *fid, struct tcon_link *tlink,
struct cifs_pending_open *open)
{
#ifdef CONFIG_CIFS_SMB2
memcpy(open->lease_key, fid->lease_key, SMB2_LEASE_KEY_SIZE);
#endif
open->oplock = CIFS_OPLOCK_NO_CHANGE;
open->tlink = tlink;
fid->pending_open = open;
list_add_tail(&open->olist, &tlink_tcon(tlink)->pending_opens);
}
void
cifs_add_pending_open(struct cifs_fid *fid, struct tcon_link *tlink,
struct cifs_pending_open *open)
{
spin_lock(&cifs_file_list_lock);
cifs_add_pending_open_locked(fid, tlink, open);
spin_unlock(&cifs_file_list_lock);
}
