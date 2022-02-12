xfs_extlen_t
xfs_get_extsz_hint(
struct xfs_inode *ip)
{
if ((ip->i_d.di_flags & XFS_DIFLAG_EXTSIZE) && ip->i_d.di_extsize)
return ip->i_d.di_extsize;
if (XFS_IS_REALTIME_INODE(ip))
return ip->i_mount->m_sb.sb_rextsize;
return 0;
}
xfs_extlen_t
xfs_get_cowextsz_hint(
struct xfs_inode *ip)
{
xfs_extlen_t a, b;
a = 0;
if (ip->i_d.di_flags2 & XFS_DIFLAG2_COWEXTSIZE)
a = ip->i_d.di_cowextsize;
b = xfs_get_extsz_hint(ip);
a = max(a, b);
if (a == 0)
return XFS_DEFAULT_COWEXTSZ_HINT;
return a;
}
uint
xfs_ilock_data_map_shared(
struct xfs_inode *ip)
{
uint lock_mode = XFS_ILOCK_SHARED;
if (ip->i_d.di_format == XFS_DINODE_FMT_BTREE &&
(ip->i_df.if_flags & XFS_IFEXTENTS) == 0)
lock_mode = XFS_ILOCK_EXCL;
xfs_ilock(ip, lock_mode);
return lock_mode;
}
uint
xfs_ilock_attr_map_shared(
struct xfs_inode *ip)
{
uint lock_mode = XFS_ILOCK_SHARED;
if (ip->i_d.di_aformat == XFS_DINODE_FMT_BTREE &&
(ip->i_afp->if_flags & XFS_IFEXTENTS) == 0)
lock_mode = XFS_ILOCK_EXCL;
xfs_ilock(ip, lock_mode);
return lock_mode;
}
void
xfs_ilock(
xfs_inode_t *ip,
uint lock_flags)
{
trace_xfs_ilock(ip, lock_flags, _RET_IP_);
ASSERT((lock_flags & (XFS_IOLOCK_SHARED | XFS_IOLOCK_EXCL)) !=
(XFS_IOLOCK_SHARED | XFS_IOLOCK_EXCL));
ASSERT((lock_flags & (XFS_MMAPLOCK_SHARED | XFS_MMAPLOCK_EXCL)) !=
(XFS_MMAPLOCK_SHARED | XFS_MMAPLOCK_EXCL));
ASSERT((lock_flags & (XFS_ILOCK_SHARED | XFS_ILOCK_EXCL)) !=
(XFS_ILOCK_SHARED | XFS_ILOCK_EXCL));
ASSERT((lock_flags & ~(XFS_LOCK_MASK | XFS_LOCK_SUBCLASS_MASK)) == 0);
if (lock_flags & XFS_IOLOCK_EXCL) {
down_write_nested(&VFS_I(ip)->i_rwsem,
XFS_IOLOCK_DEP(lock_flags));
} else if (lock_flags & XFS_IOLOCK_SHARED) {
down_read_nested(&VFS_I(ip)->i_rwsem,
XFS_IOLOCK_DEP(lock_flags));
}
if (lock_flags & XFS_MMAPLOCK_EXCL)
mrupdate_nested(&ip->i_mmaplock, XFS_MMAPLOCK_DEP(lock_flags));
else if (lock_flags & XFS_MMAPLOCK_SHARED)
mraccess_nested(&ip->i_mmaplock, XFS_MMAPLOCK_DEP(lock_flags));
if (lock_flags & XFS_ILOCK_EXCL)
mrupdate_nested(&ip->i_lock, XFS_ILOCK_DEP(lock_flags));
else if (lock_flags & XFS_ILOCK_SHARED)
mraccess_nested(&ip->i_lock, XFS_ILOCK_DEP(lock_flags));
}
int
xfs_ilock_nowait(
xfs_inode_t *ip,
uint lock_flags)
{
trace_xfs_ilock_nowait(ip, lock_flags, _RET_IP_);
ASSERT((lock_flags & (XFS_IOLOCK_SHARED | XFS_IOLOCK_EXCL)) !=
(XFS_IOLOCK_SHARED | XFS_IOLOCK_EXCL));
ASSERT((lock_flags & (XFS_MMAPLOCK_SHARED | XFS_MMAPLOCK_EXCL)) !=
(XFS_MMAPLOCK_SHARED | XFS_MMAPLOCK_EXCL));
ASSERT((lock_flags & (XFS_ILOCK_SHARED | XFS_ILOCK_EXCL)) !=
(XFS_ILOCK_SHARED | XFS_ILOCK_EXCL));
ASSERT((lock_flags & ~(XFS_LOCK_MASK | XFS_LOCK_SUBCLASS_MASK)) == 0);
if (lock_flags & XFS_IOLOCK_EXCL) {
if (!down_write_trylock(&VFS_I(ip)->i_rwsem))
goto out;
} else if (lock_flags & XFS_IOLOCK_SHARED) {
if (!down_read_trylock(&VFS_I(ip)->i_rwsem))
goto out;
}
if (lock_flags & XFS_MMAPLOCK_EXCL) {
if (!mrtryupdate(&ip->i_mmaplock))
goto out_undo_iolock;
} else if (lock_flags & XFS_MMAPLOCK_SHARED) {
if (!mrtryaccess(&ip->i_mmaplock))
goto out_undo_iolock;
}
if (lock_flags & XFS_ILOCK_EXCL) {
if (!mrtryupdate(&ip->i_lock))
goto out_undo_mmaplock;
} else if (lock_flags & XFS_ILOCK_SHARED) {
if (!mrtryaccess(&ip->i_lock))
goto out_undo_mmaplock;
}
return 1;
out_undo_mmaplock:
if (lock_flags & XFS_MMAPLOCK_EXCL)
mrunlock_excl(&ip->i_mmaplock);
else if (lock_flags & XFS_MMAPLOCK_SHARED)
mrunlock_shared(&ip->i_mmaplock);
out_undo_iolock:
if (lock_flags & XFS_IOLOCK_EXCL)
up_write(&VFS_I(ip)->i_rwsem);
else if (lock_flags & XFS_IOLOCK_SHARED)
up_read(&VFS_I(ip)->i_rwsem);
out:
return 0;
}
void
xfs_iunlock(
xfs_inode_t *ip,
uint lock_flags)
{
ASSERT((lock_flags & (XFS_IOLOCK_SHARED | XFS_IOLOCK_EXCL)) !=
(XFS_IOLOCK_SHARED | XFS_IOLOCK_EXCL));
ASSERT((lock_flags & (XFS_MMAPLOCK_SHARED | XFS_MMAPLOCK_EXCL)) !=
(XFS_MMAPLOCK_SHARED | XFS_MMAPLOCK_EXCL));
ASSERT((lock_flags & (XFS_ILOCK_SHARED | XFS_ILOCK_EXCL)) !=
(XFS_ILOCK_SHARED | XFS_ILOCK_EXCL));
ASSERT((lock_flags & ~(XFS_LOCK_MASK | XFS_LOCK_SUBCLASS_MASK)) == 0);
ASSERT(lock_flags != 0);
if (lock_flags & XFS_IOLOCK_EXCL)
up_write(&VFS_I(ip)->i_rwsem);
else if (lock_flags & XFS_IOLOCK_SHARED)
up_read(&VFS_I(ip)->i_rwsem);
if (lock_flags & XFS_MMAPLOCK_EXCL)
mrunlock_excl(&ip->i_mmaplock);
else if (lock_flags & XFS_MMAPLOCK_SHARED)
mrunlock_shared(&ip->i_mmaplock);
if (lock_flags & XFS_ILOCK_EXCL)
mrunlock_excl(&ip->i_lock);
else if (lock_flags & XFS_ILOCK_SHARED)
mrunlock_shared(&ip->i_lock);
trace_xfs_iunlock(ip, lock_flags, _RET_IP_);
}
void
xfs_ilock_demote(
xfs_inode_t *ip,
uint lock_flags)
{
ASSERT(lock_flags & (XFS_IOLOCK_EXCL|XFS_MMAPLOCK_EXCL|XFS_ILOCK_EXCL));
ASSERT((lock_flags &
~(XFS_IOLOCK_EXCL|XFS_MMAPLOCK_EXCL|XFS_ILOCK_EXCL)) == 0);
if (lock_flags & XFS_ILOCK_EXCL)
mrdemote(&ip->i_lock);
if (lock_flags & XFS_MMAPLOCK_EXCL)
mrdemote(&ip->i_mmaplock);
if (lock_flags & XFS_IOLOCK_EXCL)
downgrade_write(&VFS_I(ip)->i_rwsem);
trace_xfs_ilock_demote(ip, lock_flags, _RET_IP_);
}
int
xfs_isilocked(
xfs_inode_t *ip,
uint lock_flags)
{
if (lock_flags & (XFS_ILOCK_EXCL|XFS_ILOCK_SHARED)) {
if (!(lock_flags & XFS_ILOCK_SHARED))
return !!ip->i_lock.mr_writer;
return rwsem_is_locked(&ip->i_lock.mr_lock);
}
if (lock_flags & (XFS_MMAPLOCK_EXCL|XFS_MMAPLOCK_SHARED)) {
if (!(lock_flags & XFS_MMAPLOCK_SHARED))
return !!ip->i_mmaplock.mr_writer;
return rwsem_is_locked(&ip->i_mmaplock.mr_lock);
}
if (lock_flags & (XFS_IOLOCK_EXCL|XFS_IOLOCK_SHARED)) {
if (!(lock_flags & XFS_IOLOCK_SHARED))
return !debug_locks ||
lockdep_is_held_type(&VFS_I(ip)->i_rwsem, 0);
return rwsem_is_locked(&VFS_I(ip)->i_rwsem);
}
ASSERT(0);
return 0;
}
static bool
xfs_lockdep_subclass_ok(
int subclass)
{
return subclass < MAX_LOCKDEP_SUBCLASSES;
}
static inline int
xfs_lock_inumorder(int lock_mode, int subclass)
{
int class = 0;
ASSERT(!(lock_mode & (XFS_ILOCK_PARENT | XFS_ILOCK_RTBITMAP |
XFS_ILOCK_RTSUM)));
ASSERT(xfs_lockdep_subclass_ok(subclass));
if (lock_mode & (XFS_IOLOCK_SHARED|XFS_IOLOCK_EXCL)) {
ASSERT(subclass <= XFS_IOLOCK_MAX_SUBCLASS);
class += subclass << XFS_IOLOCK_SHIFT;
}
if (lock_mode & (XFS_MMAPLOCK_SHARED|XFS_MMAPLOCK_EXCL)) {
ASSERT(subclass <= XFS_MMAPLOCK_MAX_SUBCLASS);
class += subclass << XFS_MMAPLOCK_SHIFT;
}
if (lock_mode & (XFS_ILOCK_SHARED|XFS_ILOCK_EXCL)) {
ASSERT(subclass <= XFS_ILOCK_MAX_SUBCLASS);
class += subclass << XFS_ILOCK_SHIFT;
}
return (lock_mode & ~XFS_LOCK_SUBCLASS_MASK) | class;
}
static void
xfs_lock_inodes(
xfs_inode_t **ips,
int inodes,
uint lock_mode)
{
int attempts = 0, i, j, try_lock;
xfs_log_item_t *lp;
ASSERT(ips && inodes >= 2 && inodes <= 5);
ASSERT(lock_mode & (XFS_IOLOCK_EXCL | XFS_MMAPLOCK_EXCL |
XFS_ILOCK_EXCL));
ASSERT(!(lock_mode & (XFS_IOLOCK_SHARED | XFS_MMAPLOCK_SHARED |
XFS_ILOCK_SHARED)));
ASSERT(!(lock_mode & XFS_MMAPLOCK_EXCL) ||
inodes <= XFS_MMAPLOCK_MAX_SUBCLASS + 1);
ASSERT(!(lock_mode & XFS_ILOCK_EXCL) ||
inodes <= XFS_ILOCK_MAX_SUBCLASS + 1);
if (lock_mode & XFS_IOLOCK_EXCL) {
ASSERT(!(lock_mode & (XFS_MMAPLOCK_EXCL | XFS_ILOCK_EXCL)));
} else if (lock_mode & XFS_MMAPLOCK_EXCL)
ASSERT(!(lock_mode & XFS_ILOCK_EXCL));
try_lock = 0;
i = 0;
again:
for (; i < inodes; i++) {
ASSERT(ips[i]);
if (i && (ips[i] == ips[i - 1]))
continue;
if (!try_lock) {
for (j = (i - 1); j >= 0 && !try_lock; j--) {
lp = (xfs_log_item_t *)ips[j]->i_itemp;
if (lp && (lp->li_flags & XFS_LI_IN_AIL))
try_lock++;
}
}
if (!try_lock) {
xfs_ilock(ips[i], xfs_lock_inumorder(lock_mode, i));
continue;
}
ASSERT(i != 0);
if (xfs_ilock_nowait(ips[i], xfs_lock_inumorder(lock_mode, i)))
continue;
attempts++;
for (j = i - 1; j >= 0; j--) {
if (j != (i - 1) && ips[j] == ips[j + 1])
continue;
xfs_iunlock(ips[j], lock_mode);
}
if ((attempts % 5) == 0) {
delay(1);
#ifdef DEBUG
xfs_lock_delays++;
#endif
}
i = 0;
try_lock = 0;
goto again;
}
#ifdef DEBUG
if (attempts) {
if (attempts < 5) xfs_small_retries++;
else if (attempts < 100) xfs_middle_retries++;
else xfs_lots_retries++;
} else {
xfs_locked_n++;
}
#endif
}
void
xfs_lock_two_inodes(
xfs_inode_t *ip0,
xfs_inode_t *ip1,
uint lock_mode)
{
xfs_inode_t *temp;
int attempts = 0;
xfs_log_item_t *lp;
ASSERT(!(lock_mode & (XFS_IOLOCK_SHARED|XFS_IOLOCK_EXCL)));
if (lock_mode & (XFS_MMAPLOCK_SHARED|XFS_MMAPLOCK_EXCL))
ASSERT(!(lock_mode & (XFS_ILOCK_SHARED|XFS_ILOCK_EXCL)));
ASSERT(ip0->i_ino != ip1->i_ino);
if (ip0->i_ino > ip1->i_ino) {
temp = ip0;
ip0 = ip1;
ip1 = temp;
}
again:
xfs_ilock(ip0, xfs_lock_inumorder(lock_mode, 0));
lp = (xfs_log_item_t *)ip0->i_itemp;
if (lp && (lp->li_flags & XFS_LI_IN_AIL)) {
if (!xfs_ilock_nowait(ip1, xfs_lock_inumorder(lock_mode, 1))) {
xfs_iunlock(ip0, lock_mode);
if ((++attempts % 5) == 0)
delay(1);
goto again;
}
} else {
xfs_ilock(ip1, xfs_lock_inumorder(lock_mode, 1));
}
}
void
__xfs_iflock(
struct xfs_inode *ip)
{
wait_queue_head_t *wq = bit_waitqueue(&ip->i_flags, __XFS_IFLOCK_BIT);
DEFINE_WAIT_BIT(wait, &ip->i_flags, __XFS_IFLOCK_BIT);
do {
prepare_to_wait_exclusive(wq, &wait.wq_entry, TASK_UNINTERRUPTIBLE);
if (xfs_isiflocked(ip))
io_schedule();
} while (!xfs_iflock_nowait(ip));
finish_wait(wq, &wait.wq_entry);
}
STATIC uint
_xfs_dic2xflags(
uint16_t di_flags,
uint64_t di_flags2,
bool has_attr)
{
uint flags = 0;
if (di_flags & XFS_DIFLAG_ANY) {
if (di_flags & XFS_DIFLAG_REALTIME)
flags |= FS_XFLAG_REALTIME;
if (di_flags & XFS_DIFLAG_PREALLOC)
flags |= FS_XFLAG_PREALLOC;
if (di_flags & XFS_DIFLAG_IMMUTABLE)
flags |= FS_XFLAG_IMMUTABLE;
if (di_flags & XFS_DIFLAG_APPEND)
flags |= FS_XFLAG_APPEND;
if (di_flags & XFS_DIFLAG_SYNC)
flags |= FS_XFLAG_SYNC;
if (di_flags & XFS_DIFLAG_NOATIME)
flags |= FS_XFLAG_NOATIME;
if (di_flags & XFS_DIFLAG_NODUMP)
flags |= FS_XFLAG_NODUMP;
if (di_flags & XFS_DIFLAG_RTINHERIT)
flags |= FS_XFLAG_RTINHERIT;
if (di_flags & XFS_DIFLAG_PROJINHERIT)
flags |= FS_XFLAG_PROJINHERIT;
if (di_flags & XFS_DIFLAG_NOSYMLINKS)
flags |= FS_XFLAG_NOSYMLINKS;
if (di_flags & XFS_DIFLAG_EXTSIZE)
flags |= FS_XFLAG_EXTSIZE;
if (di_flags & XFS_DIFLAG_EXTSZINHERIT)
flags |= FS_XFLAG_EXTSZINHERIT;
if (di_flags & XFS_DIFLAG_NODEFRAG)
flags |= FS_XFLAG_NODEFRAG;
if (di_flags & XFS_DIFLAG_FILESTREAM)
flags |= FS_XFLAG_FILESTREAM;
}
if (di_flags2 & XFS_DIFLAG2_ANY) {
if (di_flags2 & XFS_DIFLAG2_DAX)
flags |= FS_XFLAG_DAX;
if (di_flags2 & XFS_DIFLAG2_COWEXTSIZE)
flags |= FS_XFLAG_COWEXTSIZE;
}
if (has_attr)
flags |= FS_XFLAG_HASATTR;
return flags;
}
uint
xfs_ip2xflags(
struct xfs_inode *ip)
{
struct xfs_icdinode *dic = &ip->i_d;
return _xfs_dic2xflags(dic->di_flags, dic->di_flags2, XFS_IFORK_Q(ip));
}
int
xfs_lookup(
xfs_inode_t *dp,
struct xfs_name *name,
xfs_inode_t **ipp,
struct xfs_name *ci_name)
{
xfs_ino_t inum;
int error;
trace_xfs_lookup(dp, name);
if (XFS_FORCED_SHUTDOWN(dp->i_mount))
return -EIO;
error = xfs_dir_lookup(NULL, dp, name, &inum, ci_name);
if (error)
goto out_unlock;
error = xfs_iget(dp->i_mount, NULL, inum, 0, 0, ipp);
if (error)
goto out_free_name;
return 0;
out_free_name:
if (ci_name)
kmem_free(ci_name->name);
out_unlock:
*ipp = NULL;
return error;
}
static int
xfs_ialloc(
xfs_trans_t *tp,
xfs_inode_t *pip,
umode_t mode,
xfs_nlink_t nlink,
xfs_dev_t rdev,
prid_t prid,
int okalloc,
xfs_buf_t **ialloc_context,
xfs_inode_t **ipp)
{
struct xfs_mount *mp = tp->t_mountp;
xfs_ino_t ino;
xfs_inode_t *ip;
uint flags;
int error;
struct timespec tv;
struct inode *inode;
error = xfs_dialloc(tp, pip ? pip->i_ino : 0, mode, okalloc,
ialloc_context, &ino);
if (error)
return error;
if (*ialloc_context || ino == NULLFSINO) {
*ipp = NULL;
return 0;
}
ASSERT(*ialloc_context == NULL);
error = xfs_iget(mp, tp, ino, XFS_IGET_CREATE,
XFS_ILOCK_EXCL, &ip);
if (error)
return error;
ASSERT(ip != NULL);
inode = VFS_I(ip);
if (ip->i_d.di_version == 1)
ip->i_d.di_version = 2;
inode->i_mode = mode;
set_nlink(inode, nlink);
ip->i_d.di_uid = xfs_kuid_to_uid(current_fsuid());
ip->i_d.di_gid = xfs_kgid_to_gid(current_fsgid());
xfs_set_projid(ip, prid);
if (pip && XFS_INHERIT_GID(pip)) {
ip->i_d.di_gid = pip->i_d.di_gid;
if ((VFS_I(pip)->i_mode & S_ISGID) && S_ISDIR(mode))
inode->i_mode |= S_ISGID;
}
if ((irix_sgid_inherit) &&
(inode->i_mode & S_ISGID) &&
(!in_group_p(xfs_gid_to_kgid(ip->i_d.di_gid))))
inode->i_mode &= ~S_ISGID;
ip->i_d.di_size = 0;
ip->i_d.di_nextents = 0;
ASSERT(ip->i_d.di_nblocks == 0);
tv = current_time(inode);
inode->i_mtime = tv;
inode->i_atime = tv;
inode->i_ctime = tv;
ip->i_d.di_extsize = 0;
ip->i_d.di_dmevmask = 0;
ip->i_d.di_dmstate = 0;
ip->i_d.di_flags = 0;
if (ip->i_d.di_version == 3) {
inode->i_version = 1;
ip->i_d.di_flags2 = 0;
ip->i_d.di_cowextsize = 0;
ip->i_d.di_crtime.t_sec = (int32_t)tv.tv_sec;
ip->i_d.di_crtime.t_nsec = (int32_t)tv.tv_nsec;
}
flags = XFS_ILOG_CORE;
switch (mode & S_IFMT) {
case S_IFIFO:
case S_IFCHR:
case S_IFBLK:
case S_IFSOCK:
ip->i_d.di_format = XFS_DINODE_FMT_DEV;
ip->i_df.if_u2.if_rdev = rdev;
ip->i_df.if_flags = 0;
flags |= XFS_ILOG_DEV;
break;
case S_IFREG:
case S_IFDIR:
if (pip && (pip->i_d.di_flags & XFS_DIFLAG_ANY)) {
uint di_flags = 0;
if (S_ISDIR(mode)) {
if (pip->i_d.di_flags & XFS_DIFLAG_RTINHERIT)
di_flags |= XFS_DIFLAG_RTINHERIT;
if (pip->i_d.di_flags & XFS_DIFLAG_EXTSZINHERIT) {
di_flags |= XFS_DIFLAG_EXTSZINHERIT;
ip->i_d.di_extsize = pip->i_d.di_extsize;
}
if (pip->i_d.di_flags & XFS_DIFLAG_PROJINHERIT)
di_flags |= XFS_DIFLAG_PROJINHERIT;
} else if (S_ISREG(mode)) {
if (pip->i_d.di_flags & XFS_DIFLAG_RTINHERIT)
di_flags |= XFS_DIFLAG_REALTIME;
if (pip->i_d.di_flags & XFS_DIFLAG_EXTSZINHERIT) {
di_flags |= XFS_DIFLAG_EXTSIZE;
ip->i_d.di_extsize = pip->i_d.di_extsize;
}
}
if ((pip->i_d.di_flags & XFS_DIFLAG_NOATIME) &&
xfs_inherit_noatime)
di_flags |= XFS_DIFLAG_NOATIME;
if ((pip->i_d.di_flags & XFS_DIFLAG_NODUMP) &&
xfs_inherit_nodump)
di_flags |= XFS_DIFLAG_NODUMP;
if ((pip->i_d.di_flags & XFS_DIFLAG_SYNC) &&
xfs_inherit_sync)
di_flags |= XFS_DIFLAG_SYNC;
if ((pip->i_d.di_flags & XFS_DIFLAG_NOSYMLINKS) &&
xfs_inherit_nosymlinks)
di_flags |= XFS_DIFLAG_NOSYMLINKS;
if ((pip->i_d.di_flags & XFS_DIFLAG_NODEFRAG) &&
xfs_inherit_nodefrag)
di_flags |= XFS_DIFLAG_NODEFRAG;
if (pip->i_d.di_flags & XFS_DIFLAG_FILESTREAM)
di_flags |= XFS_DIFLAG_FILESTREAM;
ip->i_d.di_flags |= di_flags;
}
if (pip &&
(pip->i_d.di_flags2 & XFS_DIFLAG2_ANY) &&
pip->i_d.di_version == 3 &&
ip->i_d.di_version == 3) {
uint64_t di_flags2 = 0;
if (pip->i_d.di_flags2 & XFS_DIFLAG2_COWEXTSIZE) {
di_flags2 |= XFS_DIFLAG2_COWEXTSIZE;
ip->i_d.di_cowextsize = pip->i_d.di_cowextsize;
}
if (pip->i_d.di_flags2 & XFS_DIFLAG2_DAX)
di_flags2 |= XFS_DIFLAG2_DAX;
ip->i_d.di_flags2 |= di_flags2;
}
case S_IFLNK:
ip->i_d.di_format = XFS_DINODE_FMT_EXTENTS;
ip->i_df.if_flags = XFS_IFEXTENTS;
ip->i_df.if_bytes = ip->i_df.if_real_bytes = 0;
ip->i_df.if_u1.if_extents = NULL;
break;
default:
ASSERT(0);
}
ip->i_d.di_aformat = XFS_DINODE_FMT_EXTENTS;
ip->i_d.di_anextents = 0;
xfs_trans_ijoin(tp, ip, XFS_ILOCK_EXCL);
xfs_trans_log_inode(tp, ip, flags);
xfs_setup_inode(ip);
*ipp = ip;
return 0;
}
int
xfs_dir_ialloc(
xfs_trans_t **tpp,
xfs_inode_t *dp,
umode_t mode,
xfs_nlink_t nlink,
xfs_dev_t rdev,
prid_t prid,
int okalloc,
xfs_inode_t **ipp,
int *committed)
{
xfs_trans_t *tp;
xfs_inode_t *ip;
xfs_buf_t *ialloc_context = NULL;
int code;
void *dqinfo;
uint tflags;
tp = *tpp;
ASSERT(tp->t_flags & XFS_TRANS_PERM_LOG_RES);
code = xfs_ialloc(tp, dp, mode, nlink, rdev, prid, okalloc,
&ialloc_context, &ip);
if (code) {
*ipp = NULL;
return code;
}
if (!ialloc_context && !ip) {
*ipp = NULL;
return -ENOSPC;
}
if (ialloc_context) {
xfs_trans_bhold(tp, ialloc_context);
dqinfo = NULL;
tflags = 0;
if (tp->t_dqinfo) {
dqinfo = (void *)tp->t_dqinfo;
tp->t_dqinfo = NULL;
tflags = tp->t_flags & XFS_TRANS_DQ_DIRTY;
tp->t_flags &= ~(XFS_TRANS_DQ_DIRTY);
}
code = xfs_trans_roll(&tp, NULL);
if (committed != NULL)
*committed = 1;
if (dqinfo) {
tp->t_dqinfo = dqinfo;
tp->t_flags |= tflags;
}
if (code) {
xfs_buf_relse(ialloc_context);
*tpp = tp;
*ipp = NULL;
return code;
}
xfs_trans_bjoin(tp, ialloc_context);
code = xfs_ialloc(tp, dp, mode, nlink, rdev, prid,
okalloc, &ialloc_context, &ip);
if (code) {
*tpp = tp;
*ipp = NULL;
return code;
}
ASSERT(!ialloc_context && ip);
} else {
if (committed != NULL)
*committed = 0;
}
*ipp = ip;
*tpp = tp;
return 0;
}
static int
xfs_droplink(
xfs_trans_t *tp,
xfs_inode_t *ip)
{
xfs_trans_ichgtime(tp, ip, XFS_ICHGTIME_CHG);
drop_nlink(VFS_I(ip));
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
if (VFS_I(ip)->i_nlink)
return 0;
return xfs_iunlink(tp, ip);
}
static int
xfs_bumplink(
xfs_trans_t *tp,
xfs_inode_t *ip)
{
xfs_trans_ichgtime(tp, ip, XFS_ICHGTIME_CHG);
ASSERT(ip->i_d.di_version > 1);
inc_nlink(VFS_I(ip));
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
return 0;
}
int
xfs_create(
xfs_inode_t *dp,
struct xfs_name *name,
umode_t mode,
xfs_dev_t rdev,
xfs_inode_t **ipp)
{
int is_dir = S_ISDIR(mode);
struct xfs_mount *mp = dp->i_mount;
struct xfs_inode *ip = NULL;
struct xfs_trans *tp = NULL;
int error;
struct xfs_defer_ops dfops;
xfs_fsblock_t first_block;
bool unlock_dp_on_error = false;
prid_t prid;
struct xfs_dquot *udqp = NULL;
struct xfs_dquot *gdqp = NULL;
struct xfs_dquot *pdqp = NULL;
struct xfs_trans_res *tres;
uint resblks;
trace_xfs_create(dp, name);
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
prid = xfs_get_initial_prid(dp);
error = xfs_qm_vop_dqalloc(dp, xfs_kuid_to_uid(current_fsuid()),
xfs_kgid_to_gid(current_fsgid()), prid,
XFS_QMOPT_QUOTALL | XFS_QMOPT_INHERIT,
&udqp, &gdqp, &pdqp);
if (error)
return error;
if (is_dir) {
rdev = 0;
resblks = XFS_MKDIR_SPACE_RES(mp, name->len);
tres = &M_RES(mp)->tr_mkdir;
} else {
resblks = XFS_CREATE_SPACE_RES(mp, name->len);
tres = &M_RES(mp)->tr_create;
}
error = xfs_trans_alloc(mp, tres, resblks, 0, 0, &tp);
if (error == -ENOSPC) {
xfs_flush_inodes(mp);
error = xfs_trans_alloc(mp, tres, resblks, 0, 0, &tp);
}
if (error == -ENOSPC) {
resblks = 0;
error = xfs_trans_alloc(mp, tres, 0, 0, 0, &tp);
}
if (error)
goto out_release_inode;
xfs_ilock(dp, XFS_ILOCK_EXCL | XFS_ILOCK_PARENT);
unlock_dp_on_error = true;
xfs_defer_init(&dfops, &first_block);
error = xfs_trans_reserve_quota(tp, mp, udqp, gdqp,
pdqp, resblks, 1, 0);
if (error)
goto out_trans_cancel;
if (!resblks) {
error = xfs_dir_canenter(tp, dp, name);
if (error)
goto out_trans_cancel;
}
error = xfs_dir_ialloc(&tp, dp, mode, is_dir ? 2 : 1, rdev,
prid, resblks > 0, &ip, NULL);
if (error)
goto out_trans_cancel;
xfs_trans_ijoin(tp, dp, XFS_ILOCK_EXCL);
unlock_dp_on_error = false;
error = xfs_dir_createname(tp, dp, name, ip->i_ino,
&first_block, &dfops, resblks ?
resblks - XFS_IALLOC_SPACE_RES(mp) : 0);
if (error) {
ASSERT(error != -ENOSPC);
goto out_trans_cancel;
}
xfs_trans_ichgtime(tp, dp, XFS_ICHGTIME_MOD | XFS_ICHGTIME_CHG);
xfs_trans_log_inode(tp, dp, XFS_ILOG_CORE);
if (is_dir) {
error = xfs_dir_init(tp, ip, dp);
if (error)
goto out_bmap_cancel;
error = xfs_bumplink(tp, dp);
if (error)
goto out_bmap_cancel;
}
if (mp->m_flags & (XFS_MOUNT_WSYNC|XFS_MOUNT_DIRSYNC))
xfs_trans_set_sync(tp);
xfs_qm_vop_create_dqattach(tp, ip, udqp, gdqp, pdqp);
error = xfs_defer_finish(&tp, &dfops, NULL);
if (error)
goto out_bmap_cancel;
error = xfs_trans_commit(tp);
if (error)
goto out_release_inode;
xfs_qm_dqrele(udqp);
xfs_qm_dqrele(gdqp);
xfs_qm_dqrele(pdqp);
*ipp = ip;
return 0;
out_bmap_cancel:
xfs_defer_cancel(&dfops);
out_trans_cancel:
xfs_trans_cancel(tp);
out_release_inode:
if (ip) {
xfs_finish_inode_setup(ip);
IRELE(ip);
}
xfs_qm_dqrele(udqp);
xfs_qm_dqrele(gdqp);
xfs_qm_dqrele(pdqp);
if (unlock_dp_on_error)
xfs_iunlock(dp, XFS_ILOCK_EXCL);
return error;
}
int
xfs_create_tmpfile(
struct xfs_inode *dp,
struct dentry *dentry,
umode_t mode,
struct xfs_inode **ipp)
{
struct xfs_mount *mp = dp->i_mount;
struct xfs_inode *ip = NULL;
struct xfs_trans *tp = NULL;
int error;
prid_t prid;
struct xfs_dquot *udqp = NULL;
struct xfs_dquot *gdqp = NULL;
struct xfs_dquot *pdqp = NULL;
struct xfs_trans_res *tres;
uint resblks;
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
prid = xfs_get_initial_prid(dp);
error = xfs_qm_vop_dqalloc(dp, xfs_kuid_to_uid(current_fsuid()),
xfs_kgid_to_gid(current_fsgid()), prid,
XFS_QMOPT_QUOTALL | XFS_QMOPT_INHERIT,
&udqp, &gdqp, &pdqp);
if (error)
return error;
resblks = XFS_IALLOC_SPACE_RES(mp);
tres = &M_RES(mp)->tr_create_tmpfile;
error = xfs_trans_alloc(mp, tres, resblks, 0, 0, &tp);
if (error == -ENOSPC) {
resblks = 0;
error = xfs_trans_alloc(mp, tres, 0, 0, 0, &tp);
}
if (error)
goto out_release_inode;
error = xfs_trans_reserve_quota(tp, mp, udqp, gdqp,
pdqp, resblks, 1, 0);
if (error)
goto out_trans_cancel;
error = xfs_dir_ialloc(&tp, dp, mode, 1, 0,
prid, resblks > 0, &ip, NULL);
if (error)
goto out_trans_cancel;
if (mp->m_flags & XFS_MOUNT_WSYNC)
xfs_trans_set_sync(tp);
xfs_qm_vop_create_dqattach(tp, ip, udqp, gdqp, pdqp);
error = xfs_iunlink(tp, ip);
if (error)
goto out_trans_cancel;
error = xfs_trans_commit(tp);
if (error)
goto out_release_inode;
xfs_qm_dqrele(udqp);
xfs_qm_dqrele(gdqp);
xfs_qm_dqrele(pdqp);
*ipp = ip;
return 0;
out_trans_cancel:
xfs_trans_cancel(tp);
out_release_inode:
if (ip) {
xfs_finish_inode_setup(ip);
IRELE(ip);
}
xfs_qm_dqrele(udqp);
xfs_qm_dqrele(gdqp);
xfs_qm_dqrele(pdqp);
return error;
}
int
xfs_link(
xfs_inode_t *tdp,
xfs_inode_t *sip,
struct xfs_name *target_name)
{
xfs_mount_t *mp = tdp->i_mount;
xfs_trans_t *tp;
int error;
struct xfs_defer_ops dfops;
xfs_fsblock_t first_block;
int resblks;
trace_xfs_link(tdp, target_name);
ASSERT(!S_ISDIR(VFS_I(sip)->i_mode));
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
error = xfs_qm_dqattach(sip, 0);
if (error)
goto std_return;
error = xfs_qm_dqattach(tdp, 0);
if (error)
goto std_return;
resblks = XFS_LINK_SPACE_RES(mp, target_name->len);
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_link, resblks, 0, 0, &tp);
if (error == -ENOSPC) {
resblks = 0;
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_link, 0, 0, 0, &tp);
}
if (error)
goto std_return;
xfs_lock_two_inodes(sip, tdp, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, sip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, tdp, XFS_ILOCK_EXCL);
if (unlikely((tdp->i_d.di_flags & XFS_DIFLAG_PROJINHERIT) &&
(xfs_get_projid(tdp) != xfs_get_projid(sip)))) {
error = -EXDEV;
goto error_return;
}
if (!resblks) {
error = xfs_dir_canenter(tp, tdp, target_name);
if (error)
goto error_return;
}
xfs_defer_init(&dfops, &first_block);
if (VFS_I(sip)->i_nlink == 0) {
error = xfs_iunlink_remove(tp, sip);
if (error)
goto error_return;
}
error = xfs_dir_createname(tp, tdp, target_name, sip->i_ino,
&first_block, &dfops, resblks);
if (error)
goto error_return;
xfs_trans_ichgtime(tp, tdp, XFS_ICHGTIME_MOD | XFS_ICHGTIME_CHG);
xfs_trans_log_inode(tp, tdp, XFS_ILOG_CORE);
error = xfs_bumplink(tp, sip);
if (error)
goto error_return;
if (mp->m_flags & (XFS_MOUNT_WSYNC|XFS_MOUNT_DIRSYNC))
xfs_trans_set_sync(tp);
error = xfs_defer_finish(&tp, &dfops, NULL);
if (error) {
xfs_defer_cancel(&dfops);
goto error_return;
}
return xfs_trans_commit(tp);
error_return:
xfs_trans_cancel(tp);
std_return:
return error;
}
int
xfs_itruncate_extents(
struct xfs_trans **tpp,
struct xfs_inode *ip,
int whichfork,
xfs_fsize_t new_size)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_trans *tp = *tpp;
struct xfs_defer_ops dfops;
xfs_fsblock_t first_block;
xfs_fileoff_t first_unmap_block;
xfs_fileoff_t last_block;
xfs_filblks_t unmap_len;
int error = 0;
int done = 0;
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
ASSERT(!atomic_read(&VFS_I(ip)->i_count) ||
xfs_isilocked(ip, XFS_IOLOCK_EXCL));
ASSERT(new_size <= XFS_ISIZE(ip));
ASSERT(tp->t_flags & XFS_TRANS_PERM_LOG_RES);
ASSERT(ip->i_itemp != NULL);
ASSERT(ip->i_itemp->ili_lock_flags == 0);
ASSERT(!XFS_NOT_DQATTACHED(mp, ip));
trace_xfs_itruncate_extents_start(ip, new_size);
first_unmap_block = XFS_B_TO_FSB(mp, (xfs_ufsize_t)new_size);
last_block = XFS_B_TO_FSB(mp, mp->m_super->s_maxbytes);
if (first_unmap_block == last_block)
return 0;
ASSERT(first_unmap_block < last_block);
unmap_len = last_block - first_unmap_block + 1;
while (!done) {
xfs_defer_init(&dfops, &first_block);
error = xfs_bunmapi(tp, ip,
first_unmap_block, unmap_len,
xfs_bmapi_aflag(whichfork),
XFS_ITRUNC_MAX_EXTENTS,
&first_block, &dfops,
&done);
if (error)
goto out_bmap_cancel;
error = xfs_defer_finish(&tp, &dfops, ip);
if (error)
goto out_bmap_cancel;
error = xfs_trans_roll(&tp, ip);
if (error)
goto out;
}
error = xfs_reflink_cancel_cow_blocks(ip, &tp, first_unmap_block,
last_block, true);
if (error)
goto out;
if (ip->i_d.di_nblocks == 0 && xfs_is_reflink_inode(ip)) {
ip->i_d.di_flags2 &= ~XFS_DIFLAG2_REFLINK;
xfs_inode_clear_cowblocks_tag(ip);
}
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
trace_xfs_itruncate_extents_end(ip, new_size);
out:
*tpp = tp;
return error;
out_bmap_cancel:
xfs_defer_cancel(&dfops);
goto out;
}
int
xfs_release(
xfs_inode_t *ip)
{
xfs_mount_t *mp = ip->i_mount;
int error;
if (!S_ISREG(VFS_I(ip)->i_mode) || (VFS_I(ip)->i_mode == 0))
return 0;
if (mp->m_flags & XFS_MOUNT_RDONLY)
return 0;
if (!XFS_FORCED_SHUTDOWN(mp)) {
int truncated;
truncated = xfs_iflags_test_and_clear(ip, XFS_ITRUNCATED);
if (truncated) {
xfs_iflags_clear(ip, XFS_IDIRTY_RELEASE);
if (ip->i_delayed_blks > 0) {
error = filemap_flush(VFS_I(ip)->i_mapping);
if (error)
return error;
}
}
}
if (VFS_I(ip)->i_nlink == 0)
return 0;
if (xfs_can_free_eofblocks(ip, false)) {
if (xfs_iflags_test(ip, XFS_IDIRTY_RELEASE))
return 0;
if (xfs_ilock_nowait(ip, XFS_IOLOCK_EXCL)) {
error = xfs_free_eofblocks(ip);
xfs_iunlock(ip, XFS_IOLOCK_EXCL);
if (error)
return error;
}
if (ip->i_delayed_blks)
xfs_iflags_set(ip, XFS_IDIRTY_RELEASE);
}
return 0;
}
STATIC int
xfs_inactive_truncate(
struct xfs_inode *ip)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_trans *tp;
int error;
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_itruncate, 0, 0, 0, &tp);
if (error) {
ASSERT(XFS_FORCED_SHUTDOWN(mp));
return error;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, 0);
ip->i_d.di_size = 0;
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
error = xfs_itruncate_extents(&tp, ip, XFS_DATA_FORK, 0);
if (error)
goto error_trans_cancel;
ASSERT(ip->i_d.di_nextents == 0);
error = xfs_trans_commit(tp);
if (error)
goto error_unlock;
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return 0;
error_trans_cancel:
xfs_trans_cancel(tp);
error_unlock:
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
}
STATIC int
xfs_inactive_ifree(
struct xfs_inode *ip)
{
struct xfs_defer_ops dfops;
xfs_fsblock_t first_block;
struct xfs_mount *mp = ip->i_mount;
struct xfs_trans *tp;
int error;
if (unlikely(mp->m_inotbt_nores)) {
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_ifree,
XFS_IFREE_SPACE_RES(mp), 0, XFS_TRANS_RESERVE,
&tp);
} else {
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_ifree, 0, 0, 0, &tp);
}
if (error) {
if (error == -ENOSPC) {
xfs_warn_ratelimited(mp,
"Failed to remove inode(s) from unlinked list. "
"Please free space, unmount and run xfs_repair.");
} else {
ASSERT(XFS_FORCED_SHUTDOWN(mp));
}
return error;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, 0);
xfs_defer_init(&dfops, &first_block);
error = xfs_ifree(tp, ip, &dfops);
if (error) {
if (!XFS_FORCED_SHUTDOWN(mp)) {
xfs_notice(mp, "%s: xfs_ifree returned error %d",
__func__, error);
xfs_force_shutdown(mp, SHUTDOWN_META_IO_ERROR);
}
xfs_trans_cancel(tp);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
}
xfs_trans_mod_dquot_byino(tp, ip, XFS_TRANS_DQ_ICOUNT, -1);
error = xfs_defer_finish(&tp, &dfops, NULL);
if (error) {
xfs_notice(mp, "%s: xfs_defer_finish returned error %d",
__func__, error);
xfs_defer_cancel(&dfops);
}
error = xfs_trans_commit(tp);
if (error)
xfs_notice(mp, "%s: xfs_trans_commit returned error %d",
__func__, error);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return 0;
}
void
xfs_inactive(
xfs_inode_t *ip)
{
struct xfs_mount *mp;
int error;
int truncate = 0;
if (VFS_I(ip)->i_mode == 0) {
ASSERT(ip->i_df.if_real_bytes == 0);
ASSERT(ip->i_df.if_broot_bytes == 0);
return;
}
mp = ip->i_mount;
ASSERT(!xfs_iflags_test(ip, XFS_IRECOVERY));
if (mp->m_flags & XFS_MOUNT_RDONLY)
return;
if (VFS_I(ip)->i_nlink != 0) {
if (xfs_can_free_eofblocks(ip, true))
xfs_free_eofblocks(ip);
return;
}
if (S_ISREG(VFS_I(ip)->i_mode) &&
(ip->i_d.di_size != 0 || XFS_ISIZE(ip) != 0 ||
ip->i_d.di_nextents > 0 || ip->i_delayed_blks > 0))
truncate = 1;
error = xfs_qm_dqattach(ip, 0);
if (error)
return;
if (S_ISLNK(VFS_I(ip)->i_mode))
error = xfs_inactive_symlink(ip);
else if (truncate)
error = xfs_inactive_truncate(ip);
if (error)
return;
if (XFS_IFORK_Q(ip)) {
error = xfs_attr_inactive(ip);
if (error)
return;
}
ASSERT(!ip->i_afp);
ASSERT(ip->i_d.di_anextents == 0);
ASSERT(ip->i_d.di_forkoff == 0);
error = xfs_inactive_ifree(ip);
if (error)
return;
xfs_qm_dqdetach(ip);
}
STATIC int
xfs_iunlink(
struct xfs_trans *tp,
struct xfs_inode *ip)
{
xfs_mount_t *mp = tp->t_mountp;
xfs_agi_t *agi;
xfs_dinode_t *dip;
xfs_buf_t *agibp;
xfs_buf_t *ibp;
xfs_agino_t agino;
short bucket_index;
int offset;
int error;
ASSERT(VFS_I(ip)->i_mode != 0);
error = xfs_read_agi(mp, tp, XFS_INO_TO_AGNO(mp, ip->i_ino), &agibp);
if (error)
return error;
agi = XFS_BUF_TO_AGI(agibp);
agino = XFS_INO_TO_AGINO(mp, ip->i_ino);
ASSERT(agino != 0);
bucket_index = agino % XFS_AGI_UNLINKED_BUCKETS;
ASSERT(agi->agi_unlinked[bucket_index]);
ASSERT(be32_to_cpu(agi->agi_unlinked[bucket_index]) != agino);
if (agi->agi_unlinked[bucket_index] != cpu_to_be32(NULLAGINO)) {
error = xfs_imap_to_bp(mp, tp, &ip->i_imap, &dip, &ibp,
0, 0);
if (error)
return error;
ASSERT(dip->di_next_unlinked == cpu_to_be32(NULLAGINO));
dip->di_next_unlinked = agi->agi_unlinked[bucket_index];
offset = ip->i_imap.im_boffset +
offsetof(xfs_dinode_t, di_next_unlinked);
xfs_dinode_calc_crc(mp, dip);
xfs_trans_inode_buf(tp, ibp);
xfs_trans_log_buf(tp, ibp, offset,
(offset + sizeof(xfs_agino_t) - 1));
xfs_inobp_check(mp, ibp);
}
ASSERT(agino != 0);
agi->agi_unlinked[bucket_index] = cpu_to_be32(agino);
offset = offsetof(xfs_agi_t, agi_unlinked) +
(sizeof(xfs_agino_t) * bucket_index);
xfs_trans_log_buf(tp, agibp, offset,
(offset + sizeof(xfs_agino_t) - 1));
return 0;
}
STATIC int
xfs_iunlink_remove(
xfs_trans_t *tp,
xfs_inode_t *ip)
{
xfs_ino_t next_ino;
xfs_mount_t *mp;
xfs_agi_t *agi;
xfs_dinode_t *dip;
xfs_buf_t *agibp;
xfs_buf_t *ibp;
xfs_agnumber_t agno;
xfs_agino_t agino;
xfs_agino_t next_agino;
xfs_buf_t *last_ibp;
xfs_dinode_t *last_dip = NULL;
short bucket_index;
int offset, last_offset = 0;
int error;
mp = tp->t_mountp;
agno = XFS_INO_TO_AGNO(mp, ip->i_ino);
error = xfs_read_agi(mp, tp, agno, &agibp);
if (error)
return error;
agi = XFS_BUF_TO_AGI(agibp);
agino = XFS_INO_TO_AGINO(mp, ip->i_ino);
ASSERT(agino != 0);
bucket_index = agino % XFS_AGI_UNLINKED_BUCKETS;
ASSERT(agi->agi_unlinked[bucket_index] != cpu_to_be32(NULLAGINO));
ASSERT(agi->agi_unlinked[bucket_index]);
if (be32_to_cpu(agi->agi_unlinked[bucket_index]) == agino) {
error = xfs_imap_to_bp(mp, tp, &ip->i_imap, &dip, &ibp,
0, 0);
if (error) {
xfs_warn(mp, "%s: xfs_imap_to_bp returned error %d.",
__func__, error);
return error;
}
next_agino = be32_to_cpu(dip->di_next_unlinked);
ASSERT(next_agino != 0);
if (next_agino != NULLAGINO) {
dip->di_next_unlinked = cpu_to_be32(NULLAGINO);
offset = ip->i_imap.im_boffset +
offsetof(xfs_dinode_t, di_next_unlinked);
xfs_dinode_calc_crc(mp, dip);
xfs_trans_inode_buf(tp, ibp);
xfs_trans_log_buf(tp, ibp, offset,
(offset + sizeof(xfs_agino_t) - 1));
xfs_inobp_check(mp, ibp);
} else {
xfs_trans_brelse(tp, ibp);
}
ASSERT(next_agino != 0);
ASSERT(next_agino != agino);
agi->agi_unlinked[bucket_index] = cpu_to_be32(next_agino);
offset = offsetof(xfs_agi_t, agi_unlinked) +
(sizeof(xfs_agino_t) * bucket_index);
xfs_trans_log_buf(tp, agibp, offset,
(offset + sizeof(xfs_agino_t) - 1));
} else {
next_agino = be32_to_cpu(agi->agi_unlinked[bucket_index]);
last_ibp = NULL;
while (next_agino != agino) {
struct xfs_imap imap;
if (last_ibp)
xfs_trans_brelse(tp, last_ibp);
imap.im_blkno = 0;
next_ino = XFS_AGINO_TO_INO(mp, agno, next_agino);
error = xfs_imap(mp, tp, next_ino, &imap, 0);
if (error) {
xfs_warn(mp,
"%s: xfs_imap returned error %d.",
__func__, error);
return error;
}
error = xfs_imap_to_bp(mp, tp, &imap, &last_dip,
&last_ibp, 0, 0);
if (error) {
xfs_warn(mp,
"%s: xfs_imap_to_bp returned error %d.",
__func__, error);
return error;
}
last_offset = imap.im_boffset;
next_agino = be32_to_cpu(last_dip->di_next_unlinked);
ASSERT(next_agino != NULLAGINO);
ASSERT(next_agino != 0);
}
error = xfs_imap_to_bp(mp, tp, &ip->i_imap, &dip, &ibp,
0, 0);
if (error) {
xfs_warn(mp, "%s: xfs_imap_to_bp(2) returned error %d.",
__func__, error);
return error;
}
next_agino = be32_to_cpu(dip->di_next_unlinked);
ASSERT(next_agino != 0);
ASSERT(next_agino != agino);
if (next_agino != NULLAGINO) {
dip->di_next_unlinked = cpu_to_be32(NULLAGINO);
offset = ip->i_imap.im_boffset +
offsetof(xfs_dinode_t, di_next_unlinked);
xfs_dinode_calc_crc(mp, dip);
xfs_trans_inode_buf(tp, ibp);
xfs_trans_log_buf(tp, ibp, offset,
(offset + sizeof(xfs_agino_t) - 1));
xfs_inobp_check(mp, ibp);
} else {
xfs_trans_brelse(tp, ibp);
}
last_dip->di_next_unlinked = cpu_to_be32(next_agino);
ASSERT(next_agino != 0);
offset = last_offset + offsetof(xfs_dinode_t, di_next_unlinked);
xfs_dinode_calc_crc(mp, last_dip);
xfs_trans_inode_buf(tp, last_ibp);
xfs_trans_log_buf(tp, last_ibp, offset,
(offset + sizeof(xfs_agino_t) - 1));
xfs_inobp_check(mp, last_ibp);
}
return 0;
}
STATIC int
xfs_ifree_cluster(
xfs_inode_t *free_ip,
xfs_trans_t *tp,
struct xfs_icluster *xic)
{
xfs_mount_t *mp = free_ip->i_mount;
int blks_per_cluster;
int inodes_per_cluster;
int nbufs;
int i, j;
int ioffset;
xfs_daddr_t blkno;
xfs_buf_t *bp;
xfs_inode_t *ip;
xfs_inode_log_item_t *iip;
xfs_log_item_t *lip;
struct xfs_perag *pag;
xfs_ino_t inum;
inum = xic->first_ino;
pag = xfs_perag_get(mp, XFS_INO_TO_AGNO(mp, inum));
blks_per_cluster = xfs_icluster_size_fsb(mp);
inodes_per_cluster = blks_per_cluster << mp->m_sb.sb_inopblog;
nbufs = mp->m_ialloc_blks / blks_per_cluster;
for (j = 0; j < nbufs; j++, inum += inodes_per_cluster) {
ioffset = inum - xic->first_ino;
if ((xic->alloc & XFS_INOBT_MASK(ioffset)) == 0) {
ASSERT(do_mod(ioffset, inodes_per_cluster) == 0);
continue;
}
blkno = XFS_AGB_TO_DADDR(mp, XFS_INO_TO_AGNO(mp, inum),
XFS_INO_TO_AGBNO(mp, inum));
bp = xfs_trans_get_buf(tp, mp->m_ddev_targp, blkno,
mp->m_bsize * blks_per_cluster,
XBF_UNMAPPED);
if (!bp)
return -ENOMEM;
bp->b_ops = &xfs_inode_buf_ops;
lip = bp->b_fspriv;
while (lip) {
if (lip->li_type == XFS_LI_INODE) {
iip = (xfs_inode_log_item_t *)lip;
ASSERT(iip->ili_logged == 1);
lip->li_cb = xfs_istale_done;
xfs_trans_ail_copy_lsn(mp->m_ail,
&iip->ili_flush_lsn,
&iip->ili_item.li_lsn);
xfs_iflags_set(iip->ili_inode, XFS_ISTALE);
}
lip = lip->li_bio_list;
}
for (i = 0; i < inodes_per_cluster; i++) {
retry:
rcu_read_lock();
ip = radix_tree_lookup(&pag->pag_ici_root,
XFS_INO_TO_AGINO(mp, (inum + i)));
if (!ip) {
rcu_read_unlock();
continue;
}
spin_lock(&ip->i_flags_lock);
if (ip->i_ino != inum + i ||
__xfs_iflags_test(ip, XFS_ISTALE)) {
spin_unlock(&ip->i_flags_lock);
rcu_read_unlock();
continue;
}
spin_unlock(&ip->i_flags_lock);
if (ip != free_ip &&
!xfs_ilock_nowait(ip, XFS_ILOCK_EXCL)) {
rcu_read_unlock();
delay(1);
goto retry;
}
rcu_read_unlock();
xfs_iflock(ip);
xfs_iflags_set(ip, XFS_ISTALE);
iip = ip->i_itemp;
if (!iip || xfs_inode_clean(ip)) {
ASSERT(ip != free_ip);
xfs_ifunlock(ip);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
continue;
}
iip->ili_last_fields = iip->ili_fields;
iip->ili_fields = 0;
iip->ili_fsync_fields = 0;
iip->ili_logged = 1;
xfs_trans_ail_copy_lsn(mp->m_ail, &iip->ili_flush_lsn,
&iip->ili_item.li_lsn);
xfs_buf_attach_iodone(bp, xfs_istale_done,
&iip->ili_item);
if (ip != free_ip)
xfs_iunlock(ip, XFS_ILOCK_EXCL);
}
xfs_trans_stale_inode_buf(tp, bp);
xfs_trans_binval(tp, bp);
}
xfs_perag_put(pag);
return 0;
}
int
xfs_ifree(
xfs_trans_t *tp,
xfs_inode_t *ip,
struct xfs_defer_ops *dfops)
{
int error;
struct xfs_icluster xic = { 0 };
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
ASSERT(VFS_I(ip)->i_nlink == 0);
ASSERT(ip->i_d.di_nextents == 0);
ASSERT(ip->i_d.di_anextents == 0);
ASSERT(ip->i_d.di_size == 0 || !S_ISREG(VFS_I(ip)->i_mode));
ASSERT(ip->i_d.di_nblocks == 0);
error = xfs_iunlink_remove(tp, ip);
if (error)
return error;
error = xfs_difree(tp, ip->i_ino, dfops, &xic);
if (error)
return error;
VFS_I(ip)->i_mode = 0;
ip->i_d.di_flags = 0;
ip->i_d.di_dmevmask = 0;
ip->i_d.di_forkoff = 0;
ip->i_d.di_format = XFS_DINODE_FMT_EXTENTS;
ip->i_d.di_aformat = XFS_DINODE_FMT_EXTENTS;
VFS_I(ip)->i_generation++;
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
if (xic.deleted)
error = xfs_ifree_cluster(ip, tp, &xic);
return error;
}
static void
xfs_iunpin(
struct xfs_inode *ip)
{
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL|XFS_ILOCK_SHARED));
trace_xfs_inode_unpin_nowait(ip, _RET_IP_);
xfs_log_force_lsn(ip->i_mount, ip->i_itemp->ili_last_lsn, 0);
}
static void
__xfs_iunpin_wait(
struct xfs_inode *ip)
{
wait_queue_head_t *wq = bit_waitqueue(&ip->i_flags, __XFS_IPINNED_BIT);
DEFINE_WAIT_BIT(wait, &ip->i_flags, __XFS_IPINNED_BIT);
xfs_iunpin(ip);
do {
prepare_to_wait(wq, &wait.wq_entry, TASK_UNINTERRUPTIBLE);
if (xfs_ipincount(ip))
io_schedule();
} while (xfs_ipincount(ip));
finish_wait(wq, &wait.wq_entry);
}
void
xfs_iunpin_wait(
struct xfs_inode *ip)
{
if (xfs_ipincount(ip))
__xfs_iunpin_wait(ip);
}
int
xfs_remove(
xfs_inode_t *dp,
struct xfs_name *name,
xfs_inode_t *ip)
{
xfs_mount_t *mp = dp->i_mount;
xfs_trans_t *tp = NULL;
int is_dir = S_ISDIR(VFS_I(ip)->i_mode);
int error = 0;
struct xfs_defer_ops dfops;
xfs_fsblock_t first_block;
uint resblks;
trace_xfs_remove(dp, name);
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
error = xfs_qm_dqattach(dp, 0);
if (error)
goto std_return;
error = xfs_qm_dqattach(ip, 0);
if (error)
goto std_return;
resblks = XFS_REMOVE_SPACE_RES(mp);
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_remove, resblks, 0, 0, &tp);
if (error == -ENOSPC) {
resblks = 0;
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_remove, 0, 0, 0,
&tp);
}
if (error) {
ASSERT(error != -ENOSPC);
goto std_return;
}
xfs_lock_two_inodes(dp, ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, dp, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, XFS_ILOCK_EXCL);
if (is_dir) {
ASSERT(VFS_I(ip)->i_nlink >= 2);
if (VFS_I(ip)->i_nlink != 2) {
error = -ENOTEMPTY;
goto out_trans_cancel;
}
if (!xfs_dir_isempty(ip)) {
error = -ENOTEMPTY;
goto out_trans_cancel;
}
error = xfs_droplink(tp, dp);
if (error)
goto out_trans_cancel;
error = xfs_droplink(tp, ip);
if (error)
goto out_trans_cancel;
} else {
xfs_trans_log_inode(tp, dp, XFS_ILOG_CORE);
}
xfs_trans_ichgtime(tp, dp, XFS_ICHGTIME_MOD | XFS_ICHGTIME_CHG);
error = xfs_droplink(tp, ip);
if (error)
goto out_trans_cancel;
xfs_defer_init(&dfops, &first_block);
error = xfs_dir_removename(tp, dp, name, ip->i_ino,
&first_block, &dfops, resblks);
if (error) {
ASSERT(error != -ENOENT);
goto out_bmap_cancel;
}
if (mp->m_flags & (XFS_MOUNT_WSYNC|XFS_MOUNT_DIRSYNC))
xfs_trans_set_sync(tp);
error = xfs_defer_finish(&tp, &dfops, NULL);
if (error)
goto out_bmap_cancel;
error = xfs_trans_commit(tp);
if (error)
goto std_return;
if (is_dir && xfs_inode_is_filestream(ip))
xfs_filestream_deassociate(ip);
return 0;
out_bmap_cancel:
xfs_defer_cancel(&dfops);
out_trans_cancel:
xfs_trans_cancel(tp);
std_return:
return error;
}
STATIC void
xfs_sort_for_rename(
struct xfs_inode *dp1,
struct xfs_inode *dp2,
struct xfs_inode *ip1,
struct xfs_inode *ip2,
struct xfs_inode *wip,
struct xfs_inode **i_tab,
int *num_inodes)
{
int i, j;
ASSERT(*num_inodes == __XFS_SORT_INODES);
memset(i_tab, 0, *num_inodes * sizeof(struct xfs_inode *));
i = 0;
i_tab[i++] = dp1;
i_tab[i++] = dp2;
i_tab[i++] = ip1;
if (ip2)
i_tab[i++] = ip2;
if (wip)
i_tab[i++] = wip;
*num_inodes = i;
for (i = 0; i < *num_inodes; i++) {
for (j = 1; j < *num_inodes; j++) {
if (i_tab[j]->i_ino < i_tab[j-1]->i_ino) {
struct xfs_inode *temp = i_tab[j];
i_tab[j] = i_tab[j-1];
i_tab[j-1] = temp;
}
}
}
}
static int
xfs_finish_rename(
struct xfs_trans *tp,
struct xfs_defer_ops *dfops)
{
int error;
if (tp->t_mountp->m_flags & (XFS_MOUNT_WSYNC|XFS_MOUNT_DIRSYNC))
xfs_trans_set_sync(tp);
error = xfs_defer_finish(&tp, dfops, NULL);
if (error) {
xfs_defer_cancel(dfops);
xfs_trans_cancel(tp);
return error;
}
return xfs_trans_commit(tp);
}
STATIC int
xfs_cross_rename(
struct xfs_trans *tp,
struct xfs_inode *dp1,
struct xfs_name *name1,
struct xfs_inode *ip1,
struct xfs_inode *dp2,
struct xfs_name *name2,
struct xfs_inode *ip2,
struct xfs_defer_ops *dfops,
xfs_fsblock_t *first_block,
int spaceres)
{
int error = 0;
int ip1_flags = 0;
int ip2_flags = 0;
int dp2_flags = 0;
error = xfs_dir_replace(tp, dp1, name1,
ip2->i_ino,
first_block, dfops, spaceres);
if (error)
goto out_trans_abort;
error = xfs_dir_replace(tp, dp2, name2,
ip1->i_ino,
first_block, dfops, spaceres);
if (error)
goto out_trans_abort;
if (dp1 != dp2) {
dp2_flags = XFS_ICHGTIME_MOD | XFS_ICHGTIME_CHG;
if (S_ISDIR(VFS_I(ip2)->i_mode)) {
error = xfs_dir_replace(tp, ip2, &xfs_name_dotdot,
dp1->i_ino, first_block,
dfops, spaceres);
if (error)
goto out_trans_abort;
if (!S_ISDIR(VFS_I(ip1)->i_mode)) {
error = xfs_droplink(tp, dp2);
if (error)
goto out_trans_abort;
error = xfs_bumplink(tp, dp1);
if (error)
goto out_trans_abort;
}
ip1_flags |= XFS_ICHGTIME_CHG;
ip2_flags |= XFS_ICHGTIME_MOD | XFS_ICHGTIME_CHG;
}
if (S_ISDIR(VFS_I(ip1)->i_mode)) {
error = xfs_dir_replace(tp, ip1, &xfs_name_dotdot,
dp2->i_ino, first_block,
dfops, spaceres);
if (error)
goto out_trans_abort;
if (!S_ISDIR(VFS_I(ip2)->i_mode)) {
error = xfs_droplink(tp, dp1);
if (error)
goto out_trans_abort;
error = xfs_bumplink(tp, dp2);
if (error)
goto out_trans_abort;
}
ip1_flags |= XFS_ICHGTIME_MOD | XFS_ICHGTIME_CHG;
ip2_flags |= XFS_ICHGTIME_CHG;
}
}
if (ip1_flags) {
xfs_trans_ichgtime(tp, ip1, ip1_flags);
xfs_trans_log_inode(tp, ip1, XFS_ILOG_CORE);
}
if (ip2_flags) {
xfs_trans_ichgtime(tp, ip2, ip2_flags);
xfs_trans_log_inode(tp, ip2, XFS_ILOG_CORE);
}
if (dp2_flags) {
xfs_trans_ichgtime(tp, dp2, dp2_flags);
xfs_trans_log_inode(tp, dp2, XFS_ILOG_CORE);
}
xfs_trans_ichgtime(tp, dp1, XFS_ICHGTIME_MOD | XFS_ICHGTIME_CHG);
xfs_trans_log_inode(tp, dp1, XFS_ILOG_CORE);
return xfs_finish_rename(tp, dfops);
out_trans_abort:
xfs_defer_cancel(dfops);
xfs_trans_cancel(tp);
return error;
}
static int
xfs_rename_alloc_whiteout(
struct xfs_inode *dp,
struct xfs_inode **wip)
{
struct xfs_inode *tmpfile;
int error;
error = xfs_create_tmpfile(dp, NULL, S_IFCHR | WHITEOUT_MODE, &tmpfile);
if (error)
return error;
drop_nlink(VFS_I(tmpfile));
xfs_setup_iops(tmpfile);
xfs_finish_inode_setup(tmpfile);
VFS_I(tmpfile)->i_state |= I_LINKABLE;
*wip = tmpfile;
return 0;
}
int
xfs_rename(
struct xfs_inode *src_dp,
struct xfs_name *src_name,
struct xfs_inode *src_ip,
struct xfs_inode *target_dp,
struct xfs_name *target_name,
struct xfs_inode *target_ip,
unsigned int flags)
{
struct xfs_mount *mp = src_dp->i_mount;
struct xfs_trans *tp;
struct xfs_defer_ops dfops;
xfs_fsblock_t first_block;
struct xfs_inode *wip = NULL;
struct xfs_inode *inodes[__XFS_SORT_INODES];
int num_inodes = __XFS_SORT_INODES;
bool new_parent = (src_dp != target_dp);
bool src_is_directory = S_ISDIR(VFS_I(src_ip)->i_mode);
int spaceres;
int error;
trace_xfs_rename(src_dp, target_dp, src_name, target_name);
if ((flags & RENAME_EXCHANGE) && !target_ip)
return -EINVAL;
if (flags & RENAME_WHITEOUT) {
ASSERT(!(flags & (RENAME_NOREPLACE | RENAME_EXCHANGE)));
error = xfs_rename_alloc_whiteout(target_dp, &wip);
if (error)
return error;
src_name->type = XFS_DIR3_FT_CHRDEV;
}
xfs_sort_for_rename(src_dp, target_dp, src_ip, target_ip, wip,
inodes, &num_inodes);
spaceres = XFS_RENAME_SPACE_RES(mp, target_name->len);
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_rename, spaceres, 0, 0, &tp);
if (error == -ENOSPC) {
spaceres = 0;
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_rename, 0, 0, 0,
&tp);
}
if (error)
goto out_release_wip;
error = xfs_qm_vop_rename_dqattach(inodes);
if (error)
goto out_trans_cancel;
xfs_lock_inodes(inodes, num_inodes, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, src_dp, XFS_ILOCK_EXCL);
if (new_parent)
xfs_trans_ijoin(tp, target_dp, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, src_ip, XFS_ILOCK_EXCL);
if (target_ip)
xfs_trans_ijoin(tp, target_ip, XFS_ILOCK_EXCL);
if (wip)
xfs_trans_ijoin(tp, wip, XFS_ILOCK_EXCL);
if (unlikely((target_dp->i_d.di_flags & XFS_DIFLAG_PROJINHERIT) &&
(xfs_get_projid(target_dp) != xfs_get_projid(src_ip)))) {
error = -EXDEV;
goto out_trans_cancel;
}
xfs_defer_init(&dfops, &first_block);
if (flags & RENAME_EXCHANGE)
return xfs_cross_rename(tp, src_dp, src_name, src_ip,
target_dp, target_name, target_ip,
&dfops, &first_block, spaceres);
if (target_ip == NULL) {
if (!spaceres) {
error = xfs_dir_canenter(tp, target_dp, target_name);
if (error)
goto out_trans_cancel;
}
error = xfs_dir_createname(tp, target_dp, target_name,
src_ip->i_ino, &first_block,
&dfops, spaceres);
if (error)
goto out_bmap_cancel;
xfs_trans_ichgtime(tp, target_dp,
XFS_ICHGTIME_MOD | XFS_ICHGTIME_CHG);
if (new_parent && src_is_directory) {
error = xfs_bumplink(tp, target_dp);
if (error)
goto out_bmap_cancel;
}
} else {
if (S_ISDIR(VFS_I(target_ip)->i_mode)) {
if (!(xfs_dir_isempty(target_ip)) ||
(VFS_I(target_ip)->i_nlink > 2)) {
error = -EEXIST;
goto out_trans_cancel;
}
}
error = xfs_dir_replace(tp, target_dp, target_name,
src_ip->i_ino,
&first_block, &dfops, spaceres);
if (error)
goto out_bmap_cancel;
xfs_trans_ichgtime(tp, target_dp,
XFS_ICHGTIME_MOD | XFS_ICHGTIME_CHG);
error = xfs_droplink(tp, target_ip);
if (error)
goto out_bmap_cancel;
if (src_is_directory) {
error = xfs_droplink(tp, target_ip);
if (error)
goto out_bmap_cancel;
}
}
if (new_parent && src_is_directory) {
error = xfs_dir_replace(tp, src_ip, &xfs_name_dotdot,
target_dp->i_ino,
&first_block, &dfops, spaceres);
ASSERT(error != -EEXIST);
if (error)
goto out_bmap_cancel;
}
xfs_trans_ichgtime(tp, src_ip, XFS_ICHGTIME_CHG);
xfs_trans_log_inode(tp, src_ip, XFS_ILOG_CORE);
if (src_is_directory && (new_parent || target_ip != NULL)) {
error = xfs_droplink(tp, src_dp);
if (error)
goto out_bmap_cancel;
}
if (wip) {
error = xfs_dir_replace(tp, src_dp, src_name, wip->i_ino,
&first_block, &dfops, spaceres);
} else
error = xfs_dir_removename(tp, src_dp, src_name, src_ip->i_ino,
&first_block, &dfops, spaceres);
if (error)
goto out_bmap_cancel;
if (wip) {
ASSERT(VFS_I(wip)->i_nlink == 0);
error = xfs_bumplink(tp, wip);
if (error)
goto out_bmap_cancel;
error = xfs_iunlink_remove(tp, wip);
if (error)
goto out_bmap_cancel;
xfs_trans_log_inode(tp, wip, XFS_ILOG_CORE);
VFS_I(wip)->i_state &= ~I_LINKABLE;
}
xfs_trans_ichgtime(tp, src_dp, XFS_ICHGTIME_MOD | XFS_ICHGTIME_CHG);
xfs_trans_log_inode(tp, src_dp, XFS_ILOG_CORE);
if (new_parent)
xfs_trans_log_inode(tp, target_dp, XFS_ILOG_CORE);
error = xfs_finish_rename(tp, &dfops);
if (wip)
IRELE(wip);
return error;
out_bmap_cancel:
xfs_defer_cancel(&dfops);
out_trans_cancel:
xfs_trans_cancel(tp);
out_release_wip:
if (wip)
IRELE(wip);
return error;
}
STATIC int
xfs_iflush_cluster(
struct xfs_inode *ip,
struct xfs_buf *bp)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_perag *pag;
unsigned long first_index, mask;
unsigned long inodes_per_cluster;
int cilist_size;
struct xfs_inode **cilist;
struct xfs_inode *cip;
int nr_found;
int clcount = 0;
int bufwasdelwri;
int i;
pag = xfs_perag_get(mp, XFS_INO_TO_AGNO(mp, ip->i_ino));
inodes_per_cluster = mp->m_inode_cluster_size >> mp->m_sb.sb_inodelog;
cilist_size = inodes_per_cluster * sizeof(xfs_inode_t *);
cilist = kmem_alloc(cilist_size, KM_MAYFAIL|KM_NOFS);
if (!cilist)
goto out_put;
mask = ~(((mp->m_inode_cluster_size >> mp->m_sb.sb_inodelog)) - 1);
first_index = XFS_INO_TO_AGINO(mp, ip->i_ino) & mask;
rcu_read_lock();
nr_found = radix_tree_gang_lookup(&pag->pag_ici_root, (void**)cilist,
first_index, inodes_per_cluster);
if (nr_found == 0)
goto out_free;
for (i = 0; i < nr_found; i++) {
cip = cilist[i];
if (cip == ip)
continue;
spin_lock(&cip->i_flags_lock);
if (!cip->i_ino ||
__xfs_iflags_test(cip, XFS_ISTALE)) {
spin_unlock(&cip->i_flags_lock);
continue;
}
if ((XFS_INO_TO_AGINO(mp, cip->i_ino) & mask) != first_index) {
spin_unlock(&cip->i_flags_lock);
break;
}
spin_unlock(&cip->i_flags_lock);
if (xfs_inode_clean(cip) && xfs_ipincount(cip) == 0)
continue;
if (!xfs_ilock_nowait(cip, XFS_ILOCK_SHARED))
continue;
if (!xfs_iflock_nowait(cip)) {
xfs_iunlock(cip, XFS_ILOCK_SHARED);
continue;
}
if (xfs_ipincount(cip)) {
xfs_ifunlock(cip);
xfs_iunlock(cip, XFS_ILOCK_SHARED);
continue;
}
if (!cip->i_ino) {
xfs_ifunlock(cip);
xfs_iunlock(cip, XFS_ILOCK_SHARED);
continue;
}
if (!xfs_inode_clean(cip)) {
int error;
error = xfs_iflush_int(cip, bp);
if (error) {
xfs_iunlock(cip, XFS_ILOCK_SHARED);
goto cluster_corrupt_out;
}
clcount++;
} else {
xfs_ifunlock(cip);
}
xfs_iunlock(cip, XFS_ILOCK_SHARED);
}
if (clcount) {
XFS_STATS_INC(mp, xs_icluster_flushcnt);
XFS_STATS_ADD(mp, xs_icluster_flushinode, clcount);
}
out_free:
rcu_read_unlock();
kmem_free(cilist);
out_put:
xfs_perag_put(pag);
return 0;
cluster_corrupt_out:
rcu_read_unlock();
bufwasdelwri = (bp->b_flags & _XBF_DELWRI_Q);
if (bufwasdelwri)
xfs_buf_relse(bp);
xfs_force_shutdown(mp, SHUTDOWN_CORRUPT_INCORE);
if (!bufwasdelwri) {
if (bp->b_iodone) {
bp->b_flags &= ~XBF_DONE;
xfs_buf_stale(bp);
xfs_buf_ioerror(bp, -EIO);
xfs_buf_ioend(bp);
} else {
xfs_buf_stale(bp);
xfs_buf_relse(bp);
}
}
xfs_iflush_abort(cip, false);
kmem_free(cilist);
xfs_perag_put(pag);
return -EFSCORRUPTED;
}
int
xfs_iflush(
struct xfs_inode *ip,
struct xfs_buf **bpp)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_buf *bp = NULL;
struct xfs_dinode *dip;
int error;
XFS_STATS_INC(mp, xs_iflush_count);
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL|XFS_ILOCK_SHARED));
ASSERT(xfs_isiflocked(ip));
ASSERT(ip->i_d.di_format != XFS_DINODE_FMT_BTREE ||
ip->i_d.di_nextents > XFS_IFORK_MAXEXT(ip, XFS_DATA_FORK));
*bpp = NULL;
xfs_iunpin_wait(ip);
if (xfs_iflags_test(ip, XFS_ISTALE)) {
xfs_ifunlock(ip);
return 0;
}
if (XFS_FORCED_SHUTDOWN(mp)) {
error = -EIO;
goto abort_out;
}
error = xfs_imap_to_bp(mp, NULL, &ip->i_imap, &dip, &bp, XBF_TRYLOCK,
0);
if (error == -EAGAIN) {
xfs_ifunlock(ip);
return error;
}
if (error)
goto corrupt_out;
error = xfs_iflush_int(ip, bp);
if (error)
goto corrupt_out;
if (xfs_buf_ispinned(bp))
xfs_log_force(mp, 0);
error = xfs_iflush_cluster(ip, bp);
if (error)
goto cluster_corrupt_out;
*bpp = bp;
return 0;
corrupt_out:
if (bp)
xfs_buf_relse(bp);
xfs_force_shutdown(mp, SHUTDOWN_CORRUPT_INCORE);
cluster_corrupt_out:
error = -EFSCORRUPTED;
abort_out:
xfs_iflush_abort(ip, false);
return error;
}
STATIC int
xfs_iflush_int(
struct xfs_inode *ip,
struct xfs_buf *bp)
{
struct xfs_inode_log_item *iip = ip->i_itemp;
struct xfs_dinode *dip;
struct xfs_mount *mp = ip->i_mount;
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL|XFS_ILOCK_SHARED));
ASSERT(xfs_isiflocked(ip));
ASSERT(ip->i_d.di_format != XFS_DINODE_FMT_BTREE ||
ip->i_d.di_nextents > XFS_IFORK_MAXEXT(ip, XFS_DATA_FORK));
ASSERT(iip != NULL && iip->ili_fields != 0);
ASSERT(ip->i_d.di_version > 1);
dip = xfs_buf_offset(bp, ip->i_imap.im_boffset);
if (XFS_TEST_ERROR(dip->di_magic != cpu_to_be16(XFS_DINODE_MAGIC),
mp, XFS_ERRTAG_IFLUSH_1)) {
xfs_alert_tag(mp, XFS_PTAG_IFLUSH,
"%s: Bad inode %Lu magic number 0x%x, ptr 0x%p",
__func__, ip->i_ino, be16_to_cpu(dip->di_magic), dip);
goto corrupt_out;
}
if (S_ISREG(VFS_I(ip)->i_mode)) {
if (XFS_TEST_ERROR(
(ip->i_d.di_format != XFS_DINODE_FMT_EXTENTS) &&
(ip->i_d.di_format != XFS_DINODE_FMT_BTREE),
mp, XFS_ERRTAG_IFLUSH_3)) {
xfs_alert_tag(mp, XFS_PTAG_IFLUSH,
"%s: Bad regular inode %Lu, ptr 0x%p",
__func__, ip->i_ino, ip);
goto corrupt_out;
}
} else if (S_ISDIR(VFS_I(ip)->i_mode)) {
if (XFS_TEST_ERROR(
(ip->i_d.di_format != XFS_DINODE_FMT_EXTENTS) &&
(ip->i_d.di_format != XFS_DINODE_FMT_BTREE) &&
(ip->i_d.di_format != XFS_DINODE_FMT_LOCAL),
mp, XFS_ERRTAG_IFLUSH_4)) {
xfs_alert_tag(mp, XFS_PTAG_IFLUSH,
"%s: Bad directory inode %Lu, ptr 0x%p",
__func__, ip->i_ino, ip);
goto corrupt_out;
}
}
if (XFS_TEST_ERROR(ip->i_d.di_nextents + ip->i_d.di_anextents >
ip->i_d.di_nblocks, mp, XFS_ERRTAG_IFLUSH_5)) {
xfs_alert_tag(mp, XFS_PTAG_IFLUSH,
"%s: detected corrupt incore inode %Lu, "
"total extents = %d, nblocks = %Ld, ptr 0x%p",
__func__, ip->i_ino,
ip->i_d.di_nextents + ip->i_d.di_anextents,
ip->i_d.di_nblocks, ip);
goto corrupt_out;
}
if (XFS_TEST_ERROR(ip->i_d.di_forkoff > mp->m_sb.sb_inodesize,
mp, XFS_ERRTAG_IFLUSH_6)) {
xfs_alert_tag(mp, XFS_PTAG_IFLUSH,
"%s: bad inode %Lu, forkoff 0x%x, ptr 0x%p",
__func__, ip->i_ino, ip->i_d.di_forkoff, ip);
goto corrupt_out;
}
if (ip->i_d.di_version < 3)
ip->i_d.di_flushiter++;
if (S_ISDIR(VFS_I(ip)->i_mode) &&
ip->i_d.di_format == XFS_DINODE_FMT_LOCAL &&
xfs_dir2_sf_verify(ip))
goto corrupt_out;
xfs_inode_to_disk(ip, dip, iip->ili_item.li_lsn);
if (ip->i_d.di_flushiter == DI_MAX_FLUSH)
ip->i_d.di_flushiter = 0;
xfs_iflush_fork(ip, dip, iip, XFS_DATA_FORK);
if (XFS_IFORK_Q(ip))
xfs_iflush_fork(ip, dip, iip, XFS_ATTR_FORK);
xfs_inobp_check(mp, bp);
iip->ili_last_fields = iip->ili_fields;
iip->ili_fields = 0;
iip->ili_fsync_fields = 0;
iip->ili_logged = 1;
xfs_trans_ail_copy_lsn(mp->m_ail, &iip->ili_flush_lsn,
&iip->ili_item.li_lsn);
xfs_buf_attach_iodone(bp, xfs_iflush_done, &iip->ili_item);
xfs_dinode_calc_crc(mp, dip);
ASSERT(bp->b_fspriv != NULL);
ASSERT(bp->b_iodone != NULL);
return 0;
corrupt_out:
return -EFSCORRUPTED;
}
