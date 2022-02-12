void
smb2_set_oplock_level(struct cifsInodeInfo *cinode, __u32 oplock)
{
oplock &= 0xFF;
if (oplock == SMB2_OPLOCK_LEVEL_NOCHANGE)
return;
if (oplock == SMB2_OPLOCK_LEVEL_EXCLUSIVE) {
cinode->clientCanCacheAll = true;
cinode->clientCanCacheRead = true;
cFYI(1, "Exclusive Oplock granted on inode %p",
&cinode->vfs_inode);
} else if (oplock == SMB2_OPLOCK_LEVEL_II) {
cinode->clientCanCacheAll = false;
cinode->clientCanCacheRead = true;
cFYI(1, "Level II Oplock granted on inode %p",
&cinode->vfs_inode);
} else {
cinode->clientCanCacheAll = false;
cinode->clientCanCacheRead = false;
}
}
int
smb2_open_file(const unsigned int xid, struct cifs_tcon *tcon, const char *path,
int disposition, int desired_access, int create_options,
struct cifs_fid *fid, __u32 *oplock, FILE_ALL_INFO *buf,
struct cifs_sb_info *cifs_sb)
{
int rc;
__le16 *smb2_path;
struct smb2_file_all_info *smb2_data = NULL;
__u8 smb2_oplock[17];
smb2_path = cifs_convert_path_to_utf16(path, cifs_sb);
if (smb2_path == NULL) {
rc = -ENOMEM;
goto out;
}
smb2_data = kzalloc(sizeof(struct smb2_file_all_info) + MAX_NAME * 2,
GFP_KERNEL);
if (smb2_data == NULL) {
rc = -ENOMEM;
goto out;
}
desired_access |= FILE_READ_ATTRIBUTES;
*smb2_oplock = SMB2_OPLOCK_LEVEL_EXCLUSIVE;
if (tcon->ses->server->capabilities & SMB2_GLOBAL_CAP_LEASING)
memcpy(smb2_oplock + 1, fid->lease_key, SMB2_LEASE_KEY_SIZE);
rc = SMB2_open(xid, tcon, smb2_path, &fid->persistent_fid,
&fid->volatile_fid, desired_access, disposition,
0, 0, smb2_oplock, smb2_data);
if (rc)
goto out;
if (buf) {
rc = SMB2_get_srv_num(xid, tcon, fid->persistent_fid,
fid->volatile_fid,
&smb2_data->IndexNumber);
if (rc) {
smb2_data->IndexNumber = 0;
rc = 0;
}
move_smb2_info_to_cifs(buf, smb2_data);
}
*oplock = *smb2_oplock;
out:
kfree(smb2_data);
kfree(smb2_path);
return rc;
}
int
smb2_unlock_range(struct cifsFileInfo *cfile, struct file_lock *flock,
const unsigned int xid)
{
int rc = 0, stored_rc;
unsigned int max_num, num = 0, max_buf;
struct smb2_lock_element *buf, *cur;
struct cifs_tcon *tcon = tlink_tcon(cfile->tlink);
struct cifsInodeInfo *cinode = CIFS_I(cfile->dentry->d_inode);
struct cifsLockInfo *li, *tmp;
__u64 length = 1 + flock->fl_end - flock->fl_start;
struct list_head tmp_llist;
INIT_LIST_HEAD(&tmp_llist);
max_buf = tcon->ses->server->maxBuf;
if (!max_buf)
return -EINVAL;
max_num = max_buf / sizeof(struct smb2_lock_element);
buf = kzalloc(max_num * sizeof(struct smb2_lock_element), GFP_KERNEL);
if (!buf)
return -ENOMEM;
cur = buf;
down_write(&cinode->lock_sem);
list_for_each_entry_safe(li, tmp, &cfile->llist->locks, llist) {
if (flock->fl_start > li->offset ||
(flock->fl_start + length) <
(li->offset + li->length))
continue;
if (current->tgid != li->pid)
continue;
if (cinode->can_cache_brlcks) {
list_del(&li->llist);
cifs_del_lock_waiters(li);
kfree(li);
continue;
}
cur->Length = cpu_to_le64(li->length);
cur->Offset = cpu_to_le64(li->offset);
cur->Flags = cpu_to_le32(SMB2_LOCKFLAG_UNLOCK);
list_move(&li->llist, &tmp_llist);
if (++num == max_num) {
stored_rc = smb2_lockv(xid, tcon,
cfile->fid.persistent_fid,
cfile->fid.volatile_fid,
current->tgid, num, buf);
if (stored_rc) {
cifs_move_llist(&tmp_llist,
&cfile->llist->locks);
rc = stored_rc;
} else
cifs_free_llist(&tmp_llist);
cur = buf;
num = 0;
} else
cur++;
}
if (num) {
stored_rc = smb2_lockv(xid, tcon, cfile->fid.persistent_fid,
cfile->fid.volatile_fid, current->tgid,
num, buf);
if (stored_rc) {
cifs_move_llist(&tmp_llist, &cfile->llist->locks);
rc = stored_rc;
} else
cifs_free_llist(&tmp_llist);
}
up_write(&cinode->lock_sem);
kfree(buf);
return rc;
}
static int
smb2_push_mand_fdlocks(struct cifs_fid_locks *fdlocks, const unsigned int xid,
struct smb2_lock_element *buf, unsigned int max_num)
{
int rc = 0, stored_rc;
struct cifsFileInfo *cfile = fdlocks->cfile;
struct cifsLockInfo *li;
unsigned int num = 0;
struct smb2_lock_element *cur = buf;
struct cifs_tcon *tcon = tlink_tcon(cfile->tlink);
list_for_each_entry(li, &fdlocks->locks, llist) {
cur->Length = cpu_to_le64(li->length);
cur->Offset = cpu_to_le64(li->offset);
cur->Flags = cpu_to_le32(li->type |
SMB2_LOCKFLAG_FAIL_IMMEDIATELY);
if (++num == max_num) {
stored_rc = smb2_lockv(xid, tcon,
cfile->fid.persistent_fid,
cfile->fid.volatile_fid,
current->tgid, num, buf);
if (stored_rc)
rc = stored_rc;
cur = buf;
num = 0;
} else
cur++;
}
if (num) {
stored_rc = smb2_lockv(xid, tcon,
cfile->fid.persistent_fid,
cfile->fid.volatile_fid,
current->tgid, num, buf);
if (stored_rc)
rc = stored_rc;
}
return rc;
}
int
smb2_push_mandatory_locks(struct cifsFileInfo *cfile)
{
int rc = 0, stored_rc;
unsigned int xid;
unsigned int max_num, max_buf;
struct smb2_lock_element *buf;
struct cifsInodeInfo *cinode = CIFS_I(cfile->dentry->d_inode);
struct cifs_fid_locks *fdlocks;
xid = get_xid();
down_write(&cinode->lock_sem);
if (!cinode->can_cache_brlcks) {
up_write(&cinode->lock_sem);
free_xid(xid);
return rc;
}
max_buf = tlink_tcon(cfile->tlink)->ses->server->maxBuf;
if (!max_buf) {
up_write(&cinode->lock_sem);
free_xid(xid);
return -EINVAL;
}
max_num = max_buf / sizeof(struct smb2_lock_element);
buf = kzalloc(max_num * sizeof(struct smb2_lock_element), GFP_KERNEL);
if (!buf) {
up_write(&cinode->lock_sem);
free_xid(xid);
return -ENOMEM;
}
list_for_each_entry(fdlocks, &cinode->llist, llist) {
stored_rc = smb2_push_mand_fdlocks(fdlocks, xid, buf, max_num);
if (stored_rc)
rc = stored_rc;
}
cinode->can_cache_brlcks = false;
kfree(buf);
up_write(&cinode->lock_sem);
free_xid(xid);
return rc;
}
