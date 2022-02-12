void
cifs_sb_active(struct super_block *sb)
{
struct cifs_sb_info *server = CIFS_SB(sb);
if (atomic_inc_return(&server->active) == 1)
atomic_inc(&sb->s_active);
}
void
cifs_sb_deactive(struct super_block *sb)
{
struct cifs_sb_info *server = CIFS_SB(sb);
if (atomic_dec_and_test(&server->active))
deactivate_super(sb);
}
static int
cifs_read_super(struct super_block *sb)
{
struct inode *inode;
struct cifs_sb_info *cifs_sb;
struct cifs_tcon *tcon;
int rc = 0;
cifs_sb = CIFS_SB(sb);
tcon = cifs_sb_master_tcon(cifs_sb);
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_POSIXACL)
sb->s_flags |= MS_POSIXACL;
if (tcon->ses->capabilities & tcon->ses->server->vals->cap_large_files)
sb->s_maxbytes = MAX_LFS_FILESIZE;
else
sb->s_maxbytes = MAX_NON_LFS;
sb->s_time_gran = 100;
sb->s_magic = CIFS_MAGIC_NUMBER;
sb->s_op = &cifs_super_ops;
sb->s_xattr = cifs_xattr_handlers;
rc = super_setup_bdi(sb);
if (rc)
goto out_no_root;
sb->s_bdi->ra_pages = cifs_sb->rsize / PAGE_SIZE;
sb->s_blocksize = CIFS_MAX_MSGSIZE;
sb->s_blocksize_bits = 14;
inode = cifs_root_iget(sb);
if (IS_ERR(inode)) {
rc = PTR_ERR(inode);
goto out_no_root;
}
if (tcon->nocase)
sb->s_d_op = &cifs_ci_dentry_ops;
else
sb->s_d_op = &cifs_dentry_ops;
sb->s_root = d_make_root(inode);
if (!sb->s_root) {
rc = -ENOMEM;
goto out_no_root;
}
#ifdef CONFIG_CIFS_NFSD_EXPORT
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_SERVER_INUM) {
cifs_dbg(FYI, "export ops supported\n");
sb->s_export_op = &cifs_export_ops;
}
#endif
return 0;
out_no_root:
cifs_dbg(VFS, "%s: get root inode failed\n", __func__);
return rc;
}
static void cifs_kill_sb(struct super_block *sb)
{
struct cifs_sb_info *cifs_sb = CIFS_SB(sb);
kill_anon_super(sb);
cifs_umount(cifs_sb);
}
static int
cifs_statfs(struct dentry *dentry, struct kstatfs *buf)
{
struct super_block *sb = dentry->d_sb;
struct cifs_sb_info *cifs_sb = CIFS_SB(sb);
struct cifs_tcon *tcon = cifs_sb_master_tcon(cifs_sb);
struct TCP_Server_Info *server = tcon->ses->server;
unsigned int xid;
int rc = 0;
xid = get_xid();
buf->f_namelen = PATH_MAX;
buf->f_files = 0;
buf->f_ffree = 0;
if (server->ops->queryfs)
rc = server->ops->queryfs(xid, tcon, buf);
free_xid(xid);
return 0;
}
static long cifs_fallocate(struct file *file, int mode, loff_t off, loff_t len)
{
struct cifs_sb_info *cifs_sb = CIFS_FILE_SB(file);
struct cifs_tcon *tcon = cifs_sb_master_tcon(cifs_sb);
struct TCP_Server_Info *server = tcon->ses->server;
if (server->ops->fallocate)
return server->ops->fallocate(file, tcon, mode, off, len);
return -EOPNOTSUPP;
}
static int cifs_permission(struct inode *inode, int mask)
{
struct cifs_sb_info *cifs_sb;
cifs_sb = CIFS_SB(inode->i_sb);
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_NO_PERM) {
if ((mask & MAY_EXEC) && !execute_ok(inode))
return -EACCES;
else
return 0;
} else
return generic_permission(inode, mask);
}
static struct inode *
cifs_alloc_inode(struct super_block *sb)
{
struct cifsInodeInfo *cifs_inode;
cifs_inode = kmem_cache_alloc(cifs_inode_cachep, GFP_KERNEL);
if (!cifs_inode)
return NULL;
cifs_inode->cifsAttrs = 0x20;
cifs_inode->time = 0;
cifs_set_oplock_level(cifs_inode, 0);
cifs_inode->flags = 0;
spin_lock_init(&cifs_inode->writers_lock);
cifs_inode->writers = 0;
cifs_inode->vfs_inode.i_blkbits = 14;
cifs_inode->server_eof = 0;
cifs_inode->uniqueid = 0;
cifs_inode->createtime = 0;
cifs_inode->epoch = 0;
#ifdef CONFIG_CIFS_SMB2
generate_random_uuid(cifs_inode->lease_key);
#endif
INIT_LIST_HEAD(&cifs_inode->openFileList);
INIT_LIST_HEAD(&cifs_inode->llist);
return &cifs_inode->vfs_inode;
}
static void cifs_i_callback(struct rcu_head *head)
{
struct inode *inode = container_of(head, struct inode, i_rcu);
kmem_cache_free(cifs_inode_cachep, CIFS_I(inode));
}
static void
cifs_destroy_inode(struct inode *inode)
{
call_rcu(&inode->i_rcu, cifs_i_callback);
}
static void
cifs_evict_inode(struct inode *inode)
{
truncate_inode_pages_final(&inode->i_data);
clear_inode(inode);
cifs_fscache_release_inode_cookie(inode);
}
static void
cifs_show_address(struct seq_file *s, struct TCP_Server_Info *server)
{
struct sockaddr_in *sa = (struct sockaddr_in *) &server->dstaddr;
struct sockaddr_in6 *sa6 = (struct sockaddr_in6 *) &server->dstaddr;
seq_puts(s, ",addr=");
switch (server->dstaddr.ss_family) {
case AF_INET:
seq_printf(s, "%pI4", &sa->sin_addr.s_addr);
break;
case AF_INET6:
seq_printf(s, "%pI6", &sa6->sin6_addr.s6_addr);
if (sa6->sin6_scope_id)
seq_printf(s, "%%%u", sa6->sin6_scope_id);
break;
default:
seq_puts(s, "(unknown)");
}
}
static void
cifs_show_security(struct seq_file *s, struct cifs_ses *ses)
{
if (ses->sectype == Unspecified) {
if (ses->user_name == NULL)
seq_puts(s, ",sec=none");
return;
}
seq_puts(s, ",sec=");
switch (ses->sectype) {
case LANMAN:
seq_puts(s, "lanman");
break;
case NTLMv2:
seq_puts(s, "ntlmv2");
break;
case NTLM:
seq_puts(s, "ntlm");
break;
case Kerberos:
seq_puts(s, "krb5");
break;
case RawNTLMSSP:
seq_puts(s, "ntlmssp");
break;
default:
seq_puts(s, "unknown");
break;
}
if (ses->sign)
seq_puts(s, "i");
}
static void
cifs_show_cache_flavor(struct seq_file *s, struct cifs_sb_info *cifs_sb)
{
seq_puts(s, ",cache=");
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_STRICT_IO)
seq_puts(s, "strict");
else if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_DIRECT_IO)
seq_puts(s, "none");
else
seq_puts(s, "loose");
}
static void
cifs_show_nls(struct seq_file *s, struct nls_table *cur)
{
struct nls_table *def;
def = load_nls_default();
if (def != cur)
seq_printf(s, ",iocharset=%s", cur->charset);
unload_nls(def);
}
static int
cifs_show_options(struct seq_file *s, struct dentry *root)
{
struct cifs_sb_info *cifs_sb = CIFS_SB(root->d_sb);
struct cifs_tcon *tcon = cifs_sb_master_tcon(cifs_sb);
struct sockaddr *srcaddr;
srcaddr = (struct sockaddr *)&tcon->ses->server->srcaddr;
seq_show_option(s, "vers", tcon->ses->server->vals->version_string);
cifs_show_security(s, tcon->ses);
cifs_show_cache_flavor(s, cifs_sb);
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_MULTIUSER)
seq_puts(s, ",multiuser");
else if (tcon->ses->user_name)
seq_show_option(s, "username", tcon->ses->user_name);
if (tcon->ses->domainName)
seq_show_option(s, "domain", tcon->ses->domainName);
if (srcaddr->sa_family != AF_UNSPEC) {
struct sockaddr_in *saddr4;
struct sockaddr_in6 *saddr6;
saddr4 = (struct sockaddr_in *)srcaddr;
saddr6 = (struct sockaddr_in6 *)srcaddr;
if (srcaddr->sa_family == AF_INET6)
seq_printf(s, ",srcaddr=%pI6c",
&saddr6->sin6_addr);
else if (srcaddr->sa_family == AF_INET)
seq_printf(s, ",srcaddr=%pI4",
&saddr4->sin_addr.s_addr);
else
seq_printf(s, ",srcaddr=BAD-AF:%i",
(int)(srcaddr->sa_family));
}
seq_printf(s, ",uid=%u",
from_kuid_munged(&init_user_ns, cifs_sb->mnt_uid));
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_OVERR_UID)
seq_puts(s, ",forceuid");
else
seq_puts(s, ",noforceuid");
seq_printf(s, ",gid=%u",
from_kgid_munged(&init_user_ns, cifs_sb->mnt_gid));
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_OVERR_GID)
seq_puts(s, ",forcegid");
else
seq_puts(s, ",noforcegid");
cifs_show_address(s, tcon->ses->server);
if (!tcon->unix_ext)
seq_printf(s, ",file_mode=0%ho,dir_mode=0%ho",
cifs_sb->mnt_file_mode,
cifs_sb->mnt_dir_mode);
cifs_show_nls(s, cifs_sb->local_nls);
if (tcon->seal)
seq_puts(s, ",seal");
if (tcon->nocase)
seq_puts(s, ",nocase");
if (tcon->retry)
seq_puts(s, ",hard");
if (tcon->use_persistent)
seq_puts(s, ",persistenthandles");
else if (tcon->use_resilient)
seq_puts(s, ",resilienthandles");
if (tcon->unix_ext)
seq_puts(s, ",unix");
else
seq_puts(s, ",nounix");
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_POSIX_PATHS)
seq_puts(s, ",posixpaths");
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_SET_UID)
seq_puts(s, ",setuids");
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_UID_FROM_ACL)
seq_puts(s, ",idsfromsid");
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_SERVER_INUM)
seq_puts(s, ",serverino");
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_RWPIDFORWARD)
seq_puts(s, ",rwpidforward");
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_NOPOSIXBRL)
seq_puts(s, ",forcemand");
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_NO_XATTR)
seq_puts(s, ",nouser_xattr");
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_MAP_SPECIAL_CHR)
seq_puts(s, ",mapchars");
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_MAP_SFM_CHR)
seq_puts(s, ",mapposix");
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_UNX_EMUL)
seq_puts(s, ",sfu");
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_NO_BRL)
seq_puts(s, ",nobrl");
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_CIFS_ACL)
seq_puts(s, ",cifsacl");
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_DYNPERM)
seq_puts(s, ",dynperm");
if (root->d_sb->s_flags & MS_POSIXACL)
seq_puts(s, ",acl");
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_MF_SYMLINKS)
seq_puts(s, ",mfsymlinks");
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_FSCACHE)
seq_puts(s, ",fsc");
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_NOSSYNC)
seq_puts(s, ",nostrictsync");
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_NO_PERM)
seq_puts(s, ",noperm");
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_CIFS_BACKUPUID)
seq_printf(s, ",backupuid=%u",
from_kuid_munged(&init_user_ns,
cifs_sb->mnt_backupuid));
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_CIFS_BACKUPGID)
seq_printf(s, ",backupgid=%u",
from_kgid_munged(&init_user_ns,
cifs_sb->mnt_backupgid));
seq_printf(s, ",rsize=%u", cifs_sb->rsize);
seq_printf(s, ",wsize=%u", cifs_sb->wsize);
seq_printf(s, ",echo_interval=%lu",
tcon->ses->server->echo_interval / HZ);
seq_printf(s, ",actimeo=%lu", cifs_sb->actimeo / HZ);
return 0;
}
static void cifs_umount_begin(struct super_block *sb)
{
struct cifs_sb_info *cifs_sb = CIFS_SB(sb);
struct cifs_tcon *tcon;
if (cifs_sb == NULL)
return;
tcon = cifs_sb_master_tcon(cifs_sb);
spin_lock(&cifs_tcp_ses_lock);
if ((tcon->tc_count > 1) || (tcon->tidStatus == CifsExiting)) {
spin_unlock(&cifs_tcp_ses_lock);
return;
} else if (tcon->tc_count == 1)
tcon->tidStatus = CifsExiting;
spin_unlock(&cifs_tcp_ses_lock);
if (tcon->ses && tcon->ses->server) {
cifs_dbg(FYI, "wake up tasks now - umount begin not complete\n");
wake_up_all(&tcon->ses->server->request_q);
wake_up_all(&tcon->ses->server->response_q);
msleep(1);
wake_up_all(&tcon->ses->server->response_q);
msleep(1);
}
return;
}
static int cifs_show_stats(struct seq_file *s, struct dentry *root)
{
return 0;
}
static int cifs_remount(struct super_block *sb, int *flags, char *data)
{
sync_filesystem(sb);
*flags |= MS_NODIRATIME;
return 0;
}
static int cifs_drop_inode(struct inode *inode)
{
struct cifs_sb_info *cifs_sb = CIFS_SB(inode->i_sb);
return !(cifs_sb->mnt_cifs_flags & CIFS_MOUNT_SERVER_INUM) ||
generic_drop_inode(inode);
}
static struct dentry *
cifs_get_root(struct smb_vol *vol, struct super_block *sb)
{
struct dentry *dentry;
struct cifs_sb_info *cifs_sb = CIFS_SB(sb);
char *full_path = NULL;
char *s, *p;
char sep;
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_USE_PREFIX_PATH)
return dget(sb->s_root);
full_path = cifs_build_path_to_root(vol, cifs_sb,
cifs_sb_master_tcon(cifs_sb), 0);
if (full_path == NULL)
return ERR_PTR(-ENOMEM);
cifs_dbg(FYI, "Get root dentry for %s\n", full_path);
sep = CIFS_DIR_SEP(cifs_sb);
dentry = dget(sb->s_root);
p = s = full_path;
do {
struct inode *dir = d_inode(dentry);
struct dentry *child;
if (!dir) {
dput(dentry);
dentry = ERR_PTR(-ENOENT);
break;
}
if (!S_ISDIR(dir->i_mode)) {
dput(dentry);
dentry = ERR_PTR(-ENOTDIR);
break;
}
while (*s == sep)
s++;
if (!*s)
break;
p = s++;
while (*s && *s != sep)
s++;
child = lookup_one_len_unlocked(p, dentry, s - p);
dput(dentry);
dentry = child;
} while (!IS_ERR(dentry));
kfree(full_path);
return dentry;
}
static int cifs_set_super(struct super_block *sb, void *data)
{
struct cifs_mnt_data *mnt_data = data;
sb->s_fs_info = mnt_data->cifs_sb;
return set_anon_super(sb, NULL);
}
static struct dentry *
cifs_do_mount(struct file_system_type *fs_type,
int flags, const char *dev_name, void *data)
{
int rc;
struct super_block *sb;
struct cifs_sb_info *cifs_sb;
struct smb_vol *volume_info;
struct cifs_mnt_data mnt_data;
struct dentry *root;
cifs_dbg(FYI, "Devname: %s flags: %d\n", dev_name, flags);
volume_info = cifs_get_volume_info((char *)data, dev_name);
if (IS_ERR(volume_info))
return ERR_CAST(volume_info);
cifs_sb = kzalloc(sizeof(struct cifs_sb_info), GFP_KERNEL);
if (cifs_sb == NULL) {
root = ERR_PTR(-ENOMEM);
goto out_nls;
}
cifs_sb->mountdata = kstrndup(data, PAGE_SIZE, GFP_KERNEL);
if (cifs_sb->mountdata == NULL) {
root = ERR_PTR(-ENOMEM);
goto out_free;
}
rc = cifs_setup_cifs_sb(volume_info, cifs_sb);
if (rc) {
root = ERR_PTR(rc);
goto out_free;
}
rc = cifs_mount(cifs_sb, volume_info);
if (rc) {
if (!(flags & MS_SILENT))
cifs_dbg(VFS, "cifs_mount failed w/return code = %d\n",
rc);
root = ERR_PTR(rc);
goto out_free;
}
mnt_data.vol = volume_info;
mnt_data.cifs_sb = cifs_sb;
mnt_data.flags = flags;
flags |= MS_NODIRATIME | MS_NOATIME;
sb = sget(fs_type, cifs_match_super, cifs_set_super, flags, &mnt_data);
if (IS_ERR(sb)) {
root = ERR_CAST(sb);
cifs_umount(cifs_sb);
goto out;
}
if (sb->s_root) {
cifs_dbg(FYI, "Use existing superblock\n");
cifs_umount(cifs_sb);
} else {
rc = cifs_read_super(sb);
if (rc) {
root = ERR_PTR(rc);
goto out_super;
}
sb->s_flags |= MS_ACTIVE;
}
root = cifs_get_root(volume_info, sb);
if (IS_ERR(root))
goto out_super;
cifs_dbg(FYI, "dentry root is: %p\n", root);
goto out;
out_super:
deactivate_locked_super(sb);
out:
cifs_cleanup_volume_info(volume_info);
return root;
out_free:
kfree(cifs_sb->prepath);
kfree(cifs_sb->mountdata);
kfree(cifs_sb);
out_nls:
unload_nls(volume_info->local_nls);
goto out;
}
static ssize_t
cifs_loose_read_iter(struct kiocb *iocb, struct iov_iter *iter)
{
ssize_t rc;
struct inode *inode = file_inode(iocb->ki_filp);
if (iocb->ki_filp->f_flags & O_DIRECT)
return cifs_user_readv(iocb, iter);
rc = cifs_revalidate_mapping(inode);
if (rc)
return rc;
return generic_file_read_iter(iocb, iter);
}
static ssize_t cifs_file_write_iter(struct kiocb *iocb, struct iov_iter *from)
{
struct inode *inode = file_inode(iocb->ki_filp);
struct cifsInodeInfo *cinode = CIFS_I(inode);
ssize_t written;
int rc;
if (iocb->ki_filp->f_flags & O_DIRECT) {
written = cifs_user_writev(iocb, from);
if (written > 0 && CIFS_CACHE_READ(cinode)) {
cifs_zap_mapping(inode);
cifs_dbg(FYI,
"Set no oplock for inode=%p after a write operation\n",
inode);
cinode->oplock = 0;
}
return written;
}
written = cifs_get_writer(cinode);
if (written)
return written;
written = generic_file_write_iter(iocb, from);
if (CIFS_CACHE_WRITE(CIFS_I(inode)))
goto out;
rc = filemap_fdatawrite(inode->i_mapping);
if (rc)
cifs_dbg(FYI, "cifs_file_write_iter: %d rc on %p inode\n",
rc, inode);
out:
cifs_put_writer(cinode);
return written;
}
static loff_t cifs_llseek(struct file *file, loff_t offset, int whence)
{
if (whence != SEEK_SET && whence != SEEK_CUR) {
int rc;
struct inode *inode = file_inode(file);
if (!CIFS_CACHE_READ(CIFS_I(inode)) && inode->i_mapping &&
inode->i_mapping->nrpages != 0) {
rc = filemap_fdatawait(inode->i_mapping);
if (rc) {
mapping_set_error(inode->i_mapping, rc);
return rc;
}
}
CIFS_I(inode)->time = 0;
rc = cifs_revalidate_file_attr(file);
if (rc < 0)
return (loff_t)rc;
}
return generic_file_llseek(file, offset, whence);
}
static int
cifs_setlease(struct file *file, long arg, struct file_lock **lease, void **priv)
{
struct inode *inode = file_inode(file);
struct cifsFileInfo *cfile = file->private_data;
if (!(S_ISREG(inode->i_mode)))
return -EINVAL;
if (arg == F_UNLCK ||
((arg == F_RDLCK) && CIFS_CACHE_READ(CIFS_I(inode))) ||
((arg == F_WRLCK) && CIFS_CACHE_WRITE(CIFS_I(inode))))
return generic_setlease(file, arg, lease, priv);
else if (tlink_tcon(cfile->tlink)->local_lease &&
!CIFS_CACHE_READ(CIFS_I(inode)))
return generic_setlease(file, arg, lease, priv);
else
return -EAGAIN;
}
static int cifs_clone_file_range(struct file *src_file, loff_t off,
struct file *dst_file, loff_t destoff, u64 len)
{
struct inode *src_inode = file_inode(src_file);
struct inode *target_inode = file_inode(dst_file);
struct cifsFileInfo *smb_file_src = src_file->private_data;
struct cifsFileInfo *smb_file_target = dst_file->private_data;
struct cifs_tcon *target_tcon = tlink_tcon(smb_file_target->tlink);
unsigned int xid;
int rc;
cifs_dbg(FYI, "clone range\n");
xid = get_xid();
if (!src_file->private_data || !dst_file->private_data) {
rc = -EBADF;
cifs_dbg(VFS, "missing cifsFileInfo on copy range src file\n");
goto out;
}
lock_two_nondirectories(target_inode, src_inode);
if (len == 0)
len = src_inode->i_size - off;
cifs_dbg(FYI, "about to flush pages\n");
truncate_inode_pages_range(&target_inode->i_data, destoff,
PAGE_ALIGN(destoff + len)-1);
if (target_tcon->ses->server->ops->duplicate_extents)
rc = target_tcon->ses->server->ops->duplicate_extents(xid,
smb_file_src, smb_file_target, off, len, destoff);
else
rc = -EOPNOTSUPP;
CIFS_I(target_inode)->time = 0;
unlock_two_nondirectories(src_inode, target_inode);
out:
free_xid(xid);
return rc;
}
ssize_t cifs_file_copychunk_range(unsigned int xid,
struct file *src_file, loff_t off,
struct file *dst_file, loff_t destoff,
size_t len, unsigned int flags)
{
struct inode *src_inode = file_inode(src_file);
struct inode *target_inode = file_inode(dst_file);
struct cifsFileInfo *smb_file_src;
struct cifsFileInfo *smb_file_target;
struct cifs_tcon *src_tcon;
struct cifs_tcon *target_tcon;
ssize_t rc;
cifs_dbg(FYI, "copychunk range\n");
if (src_inode == target_inode) {
rc = -EINVAL;
goto out;
}
if (!src_file->private_data || !dst_file->private_data) {
rc = -EBADF;
cifs_dbg(VFS, "missing cifsFileInfo on copy range src file\n");
goto out;
}
rc = -EXDEV;
smb_file_target = dst_file->private_data;
smb_file_src = src_file->private_data;
src_tcon = tlink_tcon(smb_file_src->tlink);
target_tcon = tlink_tcon(smb_file_target->tlink);
if (src_tcon->ses != target_tcon->ses) {
cifs_dbg(VFS, "source and target of copy not on same server\n");
goto out;
}
lock_two_nondirectories(target_inode, src_inode);
cifs_dbg(FYI, "about to flush pages\n");
truncate_inode_pages(&target_inode->i_data, 0);
if (target_tcon->ses->server->ops->copychunk_range)
rc = target_tcon->ses->server->ops->copychunk_range(xid,
smb_file_src, smb_file_target, off, len, destoff);
else
rc = -EOPNOTSUPP;
CIFS_I(target_inode)->time = 0;
unlock_two_nondirectories(src_inode, target_inode);
out:
return rc;
}
static ssize_t cifs_copy_file_range(struct file *src_file, loff_t off,
struct file *dst_file, loff_t destoff,
size_t len, unsigned int flags)
{
unsigned int xid = get_xid();
ssize_t rc;
rc = cifs_file_copychunk_range(xid, src_file, off, dst_file, destoff,
len, flags);
free_xid(xid);
return rc;
}
static void
cifs_init_once(void *inode)
{
struct cifsInodeInfo *cifsi = inode;
inode_init_once(&cifsi->vfs_inode);
init_rwsem(&cifsi->lock_sem);
}
static int __init
cifs_init_inodecache(void)
{
cifs_inode_cachep = kmem_cache_create("cifs_inode_cache",
sizeof(struct cifsInodeInfo),
0, (SLAB_RECLAIM_ACCOUNT|
SLAB_MEM_SPREAD|SLAB_ACCOUNT),
cifs_init_once);
if (cifs_inode_cachep == NULL)
return -ENOMEM;
return 0;
}
static void
cifs_destroy_inodecache(void)
{
rcu_barrier();
kmem_cache_destroy(cifs_inode_cachep);
}
static int
cifs_init_request_bufs(void)
{
size_t max_hdr_size = MAX_CIFS_HDR_SIZE;
#ifdef CONFIG_CIFS_SMB2
max_hdr_size = MAX_SMB2_HDR_SIZE;
#endif
if (CIFSMaxBufSize < 8192) {
CIFSMaxBufSize = 8192;
} else if (CIFSMaxBufSize > 1024*127) {
CIFSMaxBufSize = 1024 * 127;
} else {
CIFSMaxBufSize &= 0x1FE00;
}
cifs_req_cachep = kmem_cache_create("cifs_request",
CIFSMaxBufSize + max_hdr_size, 0,
SLAB_HWCACHE_ALIGN, NULL);
if (cifs_req_cachep == NULL)
return -ENOMEM;
if (cifs_min_rcv < 1)
cifs_min_rcv = 1;
else if (cifs_min_rcv > 64) {
cifs_min_rcv = 64;
cifs_dbg(VFS, "cifs_min_rcv set to maximum (64)\n");
}
cifs_req_poolp = mempool_create_slab_pool(cifs_min_rcv,
cifs_req_cachep);
if (cifs_req_poolp == NULL) {
kmem_cache_destroy(cifs_req_cachep);
return -ENOMEM;
}
cifs_sm_req_cachep = kmem_cache_create("cifs_small_rq",
MAX_CIFS_SMALL_BUFFER_SIZE, 0, SLAB_HWCACHE_ALIGN,
NULL);
if (cifs_sm_req_cachep == NULL) {
mempool_destroy(cifs_req_poolp);
kmem_cache_destroy(cifs_req_cachep);
return -ENOMEM;
}
if (cifs_min_small < 2)
cifs_min_small = 2;
else if (cifs_min_small > 256) {
cifs_min_small = 256;
cifs_dbg(FYI, "cifs_min_small set to maximum (256)\n");
}
cifs_sm_req_poolp = mempool_create_slab_pool(cifs_min_small,
cifs_sm_req_cachep);
if (cifs_sm_req_poolp == NULL) {
mempool_destroy(cifs_req_poolp);
kmem_cache_destroy(cifs_req_cachep);
kmem_cache_destroy(cifs_sm_req_cachep);
return -ENOMEM;
}
return 0;
}
static void
cifs_destroy_request_bufs(void)
{
mempool_destroy(cifs_req_poolp);
kmem_cache_destroy(cifs_req_cachep);
mempool_destroy(cifs_sm_req_poolp);
kmem_cache_destroy(cifs_sm_req_cachep);
}
static int
cifs_init_mids(void)
{
cifs_mid_cachep = kmem_cache_create("cifs_mpx_ids",
sizeof(struct mid_q_entry), 0,
SLAB_HWCACHE_ALIGN, NULL);
if (cifs_mid_cachep == NULL)
return -ENOMEM;
cifs_mid_poolp = mempool_create_slab_pool(3, cifs_mid_cachep);
if (cifs_mid_poolp == NULL) {
kmem_cache_destroy(cifs_mid_cachep);
return -ENOMEM;
}
return 0;
}
static void
cifs_destroy_mids(void)
{
mempool_destroy(cifs_mid_poolp);
kmem_cache_destroy(cifs_mid_cachep);
}
static int __init
init_cifs(void)
{
int rc = 0;
cifs_proc_init();
INIT_LIST_HEAD(&cifs_tcp_ses_list);
#ifdef CONFIG_CIFS_DNOTIFY_EXPERIMENTAL
INIT_LIST_HEAD(&GlobalDnotifyReqList);
INIT_LIST_HEAD(&GlobalDnotifyRsp_Q);
#endif
atomic_set(&sesInfoAllocCount, 0);
atomic_set(&tconInfoAllocCount, 0);
atomic_set(&tcpSesAllocCount, 0);
atomic_set(&tcpSesReconnectCount, 0);
atomic_set(&tconInfoReconnectCount, 0);
atomic_set(&bufAllocCount, 0);
atomic_set(&smBufAllocCount, 0);
#ifdef CONFIG_CIFS_STATS2
atomic_set(&totBufAllocCount, 0);
atomic_set(&totSmBufAllocCount, 0);
#endif
atomic_set(&midCount, 0);
GlobalCurrentXid = 0;
GlobalTotalActiveXid = 0;
GlobalMaxActiveXid = 0;
spin_lock_init(&cifs_tcp_ses_lock);
spin_lock_init(&GlobalMid_Lock);
get_random_bytes(&cifs_lock_secret, sizeof(cifs_lock_secret));
if (cifs_max_pending < 2) {
cifs_max_pending = 2;
cifs_dbg(FYI, "cifs_max_pending set to min of 2\n");
} else if (cifs_max_pending > CIFS_MAX_REQ) {
cifs_max_pending = CIFS_MAX_REQ;
cifs_dbg(FYI, "cifs_max_pending set to max of %u\n",
CIFS_MAX_REQ);
}
cifsiod_wq = alloc_workqueue("cifsiod", WQ_FREEZABLE|WQ_MEM_RECLAIM, 0);
if (!cifsiod_wq) {
rc = -ENOMEM;
goto out_clean_proc;
}
cifsoplockd_wq = alloc_workqueue("cifsoplockd",
WQ_FREEZABLE|WQ_MEM_RECLAIM, 0);
if (!cifsoplockd_wq) {
rc = -ENOMEM;
goto out_destroy_cifsiod_wq;
}
rc = cifs_fscache_register();
if (rc)
goto out_destroy_cifsoplockd_wq;
rc = cifs_init_inodecache();
if (rc)
goto out_unreg_fscache;
rc = cifs_init_mids();
if (rc)
goto out_destroy_inodecache;
rc = cifs_init_request_bufs();
if (rc)
goto out_destroy_mids;
#ifdef CONFIG_CIFS_UPCALL
rc = init_cifs_spnego();
if (rc)
goto out_destroy_request_bufs;
#endif
#ifdef CONFIG_CIFS_ACL
rc = init_cifs_idmap();
if (rc)
goto out_register_key_type;
#endif
rc = register_filesystem(&cifs_fs_type);
if (rc)
goto out_init_cifs_idmap;
return 0;
out_init_cifs_idmap:
#ifdef CONFIG_CIFS_ACL
exit_cifs_idmap();
out_register_key_type:
#endif
#ifdef CONFIG_CIFS_UPCALL
exit_cifs_spnego();
out_destroy_request_bufs:
#endif
cifs_destroy_request_bufs();
out_destroy_mids:
cifs_destroy_mids();
out_destroy_inodecache:
cifs_destroy_inodecache();
out_unreg_fscache:
cifs_fscache_unregister();
out_destroy_cifsoplockd_wq:
destroy_workqueue(cifsoplockd_wq);
out_destroy_cifsiod_wq:
destroy_workqueue(cifsiod_wq);
out_clean_proc:
cifs_proc_clean();
return rc;
}
static void __exit
exit_cifs(void)
{
cifs_dbg(NOISY, "exit_cifs\n");
unregister_filesystem(&cifs_fs_type);
cifs_dfs_release_automount_timer();
#ifdef CONFIG_CIFS_ACL
exit_cifs_idmap();
#endif
#ifdef CONFIG_CIFS_UPCALL
unregister_key_type(&cifs_spnego_key_type);
#endif
cifs_destroy_request_bufs();
cifs_destroy_mids();
cifs_destroy_inodecache();
cifs_fscache_unregister();
destroy_workqueue(cifsoplockd_wq);
destroy_workqueue(cifsiod_wq);
cifs_proc_clean();
}
