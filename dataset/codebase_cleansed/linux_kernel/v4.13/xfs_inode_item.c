static inline struct xfs_inode_log_item *INODE_ITEM(struct xfs_log_item *lip)
{
return container_of(lip, struct xfs_inode_log_item, ili_item);
}
STATIC void
xfs_inode_item_data_fork_size(
struct xfs_inode_log_item *iip,
int *nvecs,
int *nbytes)
{
struct xfs_inode *ip = iip->ili_inode;
switch (ip->i_d.di_format) {
case XFS_DINODE_FMT_EXTENTS:
if ((iip->ili_fields & XFS_ILOG_DEXT) &&
ip->i_d.di_nextents > 0 &&
ip->i_df.if_bytes > 0) {
*nbytes += XFS_IFORK_DSIZE(ip);
*nvecs += 1;
}
break;
case XFS_DINODE_FMT_BTREE:
if ((iip->ili_fields & XFS_ILOG_DBROOT) &&
ip->i_df.if_broot_bytes > 0) {
*nbytes += ip->i_df.if_broot_bytes;
*nvecs += 1;
}
break;
case XFS_DINODE_FMT_LOCAL:
if ((iip->ili_fields & XFS_ILOG_DDATA) &&
ip->i_df.if_bytes > 0) {
*nbytes += roundup(ip->i_df.if_bytes, 4);
*nvecs += 1;
}
break;
case XFS_DINODE_FMT_DEV:
case XFS_DINODE_FMT_UUID:
break;
default:
ASSERT(0);
break;
}
}
STATIC void
xfs_inode_item_attr_fork_size(
struct xfs_inode_log_item *iip,
int *nvecs,
int *nbytes)
{
struct xfs_inode *ip = iip->ili_inode;
switch (ip->i_d.di_aformat) {
case XFS_DINODE_FMT_EXTENTS:
if ((iip->ili_fields & XFS_ILOG_AEXT) &&
ip->i_d.di_anextents > 0 &&
ip->i_afp->if_bytes > 0) {
*nbytes += XFS_IFORK_ASIZE(ip);
*nvecs += 1;
}
break;
case XFS_DINODE_FMT_BTREE:
if ((iip->ili_fields & XFS_ILOG_ABROOT) &&
ip->i_afp->if_broot_bytes > 0) {
*nbytes += ip->i_afp->if_broot_bytes;
*nvecs += 1;
}
break;
case XFS_DINODE_FMT_LOCAL:
if ((iip->ili_fields & XFS_ILOG_ADATA) &&
ip->i_afp->if_bytes > 0) {
*nbytes += roundup(ip->i_afp->if_bytes, 4);
*nvecs += 1;
}
break;
default:
ASSERT(0);
break;
}
}
STATIC void
xfs_inode_item_size(
struct xfs_log_item *lip,
int *nvecs,
int *nbytes)
{
struct xfs_inode_log_item *iip = INODE_ITEM(lip);
struct xfs_inode *ip = iip->ili_inode;
*nvecs += 2;
*nbytes += sizeof(struct xfs_inode_log_format) +
xfs_log_dinode_size(ip->i_d.di_version);
xfs_inode_item_data_fork_size(iip, nvecs, nbytes);
if (XFS_IFORK_Q(ip))
xfs_inode_item_attr_fork_size(iip, nvecs, nbytes);
}
STATIC void
xfs_inode_item_format_data_fork(
struct xfs_inode_log_item *iip,
struct xfs_inode_log_format *ilf,
struct xfs_log_vec *lv,
struct xfs_log_iovec **vecp)
{
struct xfs_inode *ip = iip->ili_inode;
size_t data_bytes;
switch (ip->i_d.di_format) {
case XFS_DINODE_FMT_EXTENTS:
iip->ili_fields &=
~(XFS_ILOG_DDATA | XFS_ILOG_DBROOT |
XFS_ILOG_DEV | XFS_ILOG_UUID);
if ((iip->ili_fields & XFS_ILOG_DEXT) &&
ip->i_d.di_nextents > 0 &&
ip->i_df.if_bytes > 0) {
struct xfs_bmbt_rec *p;
ASSERT(ip->i_df.if_u1.if_extents != NULL);
ASSERT(xfs_iext_count(&ip->i_df) > 0);
p = xlog_prepare_iovec(lv, vecp, XLOG_REG_TYPE_IEXT);
data_bytes = xfs_iextents_copy(ip, p, XFS_DATA_FORK);
xlog_finish_iovec(lv, *vecp, data_bytes);
ASSERT(data_bytes <= ip->i_df.if_bytes);
ilf->ilf_dsize = data_bytes;
ilf->ilf_size++;
} else {
iip->ili_fields &= ~XFS_ILOG_DEXT;
}
break;
case XFS_DINODE_FMT_BTREE:
iip->ili_fields &=
~(XFS_ILOG_DDATA | XFS_ILOG_DEXT |
XFS_ILOG_DEV | XFS_ILOG_UUID);
if ((iip->ili_fields & XFS_ILOG_DBROOT) &&
ip->i_df.if_broot_bytes > 0) {
ASSERT(ip->i_df.if_broot != NULL);
xlog_copy_iovec(lv, vecp, XLOG_REG_TYPE_IBROOT,
ip->i_df.if_broot,
ip->i_df.if_broot_bytes);
ilf->ilf_dsize = ip->i_df.if_broot_bytes;
ilf->ilf_size++;
} else {
ASSERT(!(iip->ili_fields &
XFS_ILOG_DBROOT));
iip->ili_fields &= ~XFS_ILOG_DBROOT;
}
break;
case XFS_DINODE_FMT_LOCAL:
iip->ili_fields &=
~(XFS_ILOG_DEXT | XFS_ILOG_DBROOT |
XFS_ILOG_DEV | XFS_ILOG_UUID);
if ((iip->ili_fields & XFS_ILOG_DDATA) &&
ip->i_df.if_bytes > 0) {
data_bytes = roundup(ip->i_df.if_bytes, 4);
ASSERT(ip->i_df.if_real_bytes == 0 ||
ip->i_df.if_real_bytes >= data_bytes);
ASSERT(ip->i_df.if_u1.if_data != NULL);
ASSERT(ip->i_d.di_size > 0);
xlog_copy_iovec(lv, vecp, XLOG_REG_TYPE_ILOCAL,
ip->i_df.if_u1.if_data, data_bytes);
ilf->ilf_dsize = (unsigned)data_bytes;
ilf->ilf_size++;
} else {
iip->ili_fields &= ~XFS_ILOG_DDATA;
}
break;
case XFS_DINODE_FMT_DEV:
iip->ili_fields &=
~(XFS_ILOG_DDATA | XFS_ILOG_DBROOT |
XFS_ILOG_DEXT | XFS_ILOG_UUID);
if (iip->ili_fields & XFS_ILOG_DEV)
ilf->ilf_u.ilfu_rdev = ip->i_df.if_u2.if_rdev;
break;
case XFS_DINODE_FMT_UUID:
iip->ili_fields &=
~(XFS_ILOG_DDATA | XFS_ILOG_DBROOT |
XFS_ILOG_DEXT | XFS_ILOG_DEV);
if (iip->ili_fields & XFS_ILOG_UUID)
ilf->ilf_u.ilfu_uuid = ip->i_df.if_u2.if_uuid;
break;
default:
ASSERT(0);
break;
}
}
STATIC void
xfs_inode_item_format_attr_fork(
struct xfs_inode_log_item *iip,
struct xfs_inode_log_format *ilf,
struct xfs_log_vec *lv,
struct xfs_log_iovec **vecp)
{
struct xfs_inode *ip = iip->ili_inode;
size_t data_bytes;
switch (ip->i_d.di_aformat) {
case XFS_DINODE_FMT_EXTENTS:
iip->ili_fields &=
~(XFS_ILOG_ADATA | XFS_ILOG_ABROOT);
if ((iip->ili_fields & XFS_ILOG_AEXT) &&
ip->i_d.di_anextents > 0 &&
ip->i_afp->if_bytes > 0) {
struct xfs_bmbt_rec *p;
ASSERT(xfs_iext_count(ip->i_afp) ==
ip->i_d.di_anextents);
ASSERT(ip->i_afp->if_u1.if_extents != NULL);
p = xlog_prepare_iovec(lv, vecp, XLOG_REG_TYPE_IATTR_EXT);
data_bytes = xfs_iextents_copy(ip, p, XFS_ATTR_FORK);
xlog_finish_iovec(lv, *vecp, data_bytes);
ilf->ilf_asize = data_bytes;
ilf->ilf_size++;
} else {
iip->ili_fields &= ~XFS_ILOG_AEXT;
}
break;
case XFS_DINODE_FMT_BTREE:
iip->ili_fields &=
~(XFS_ILOG_ADATA | XFS_ILOG_AEXT);
if ((iip->ili_fields & XFS_ILOG_ABROOT) &&
ip->i_afp->if_broot_bytes > 0) {
ASSERT(ip->i_afp->if_broot != NULL);
xlog_copy_iovec(lv, vecp, XLOG_REG_TYPE_IATTR_BROOT,
ip->i_afp->if_broot,
ip->i_afp->if_broot_bytes);
ilf->ilf_asize = ip->i_afp->if_broot_bytes;
ilf->ilf_size++;
} else {
iip->ili_fields &= ~XFS_ILOG_ABROOT;
}
break;
case XFS_DINODE_FMT_LOCAL:
iip->ili_fields &=
~(XFS_ILOG_AEXT | XFS_ILOG_ABROOT);
if ((iip->ili_fields & XFS_ILOG_ADATA) &&
ip->i_afp->if_bytes > 0) {
data_bytes = roundup(ip->i_afp->if_bytes, 4);
ASSERT(ip->i_afp->if_real_bytes == 0 ||
ip->i_afp->if_real_bytes >= data_bytes);
ASSERT(ip->i_afp->if_u1.if_data != NULL);
xlog_copy_iovec(lv, vecp, XLOG_REG_TYPE_IATTR_LOCAL,
ip->i_afp->if_u1.if_data,
data_bytes);
ilf->ilf_asize = (unsigned)data_bytes;
ilf->ilf_size++;
} else {
iip->ili_fields &= ~XFS_ILOG_ADATA;
}
break;
default:
ASSERT(0);
break;
}
}
static void
xfs_inode_to_log_dinode(
struct xfs_inode *ip,
struct xfs_log_dinode *to,
xfs_lsn_t lsn)
{
struct xfs_icdinode *from = &ip->i_d;
struct inode *inode = VFS_I(ip);
to->di_magic = XFS_DINODE_MAGIC;
to->di_version = from->di_version;
to->di_format = from->di_format;
to->di_uid = from->di_uid;
to->di_gid = from->di_gid;
to->di_projid_lo = from->di_projid_lo;
to->di_projid_hi = from->di_projid_hi;
memset(to->di_pad, 0, sizeof(to->di_pad));
memset(to->di_pad3, 0, sizeof(to->di_pad3));
to->di_atime.t_sec = inode->i_atime.tv_sec;
to->di_atime.t_nsec = inode->i_atime.tv_nsec;
to->di_mtime.t_sec = inode->i_mtime.tv_sec;
to->di_mtime.t_nsec = inode->i_mtime.tv_nsec;
to->di_ctime.t_sec = inode->i_ctime.tv_sec;
to->di_ctime.t_nsec = inode->i_ctime.tv_nsec;
to->di_nlink = inode->i_nlink;
to->di_gen = inode->i_generation;
to->di_mode = inode->i_mode;
to->di_size = from->di_size;
to->di_nblocks = from->di_nblocks;
to->di_extsize = from->di_extsize;
to->di_nextents = from->di_nextents;
to->di_anextents = from->di_anextents;
to->di_forkoff = from->di_forkoff;
to->di_aformat = from->di_aformat;
to->di_dmevmask = from->di_dmevmask;
to->di_dmstate = from->di_dmstate;
to->di_flags = from->di_flags;
if (from->di_version == 3) {
to->di_changecount = inode->i_version;
to->di_crtime.t_sec = from->di_crtime.t_sec;
to->di_crtime.t_nsec = from->di_crtime.t_nsec;
to->di_flags2 = from->di_flags2;
to->di_cowextsize = from->di_cowextsize;
to->di_ino = ip->i_ino;
to->di_lsn = lsn;
memset(to->di_pad2, 0, sizeof(to->di_pad2));
uuid_copy(&to->di_uuid, &ip->i_mount->m_sb.sb_meta_uuid);
to->di_flushiter = 0;
} else {
to->di_flushiter = from->di_flushiter;
}
}
static void
xfs_inode_item_format_core(
struct xfs_inode *ip,
struct xfs_log_vec *lv,
struct xfs_log_iovec **vecp)
{
struct xfs_log_dinode *dic;
dic = xlog_prepare_iovec(lv, vecp, XLOG_REG_TYPE_ICORE);
xfs_inode_to_log_dinode(ip, dic, ip->i_itemp->ili_item.li_lsn);
xlog_finish_iovec(lv, *vecp, xfs_log_dinode_size(ip->i_d.di_version));
}
STATIC void
xfs_inode_item_format(
struct xfs_log_item *lip,
struct xfs_log_vec *lv)
{
struct xfs_inode_log_item *iip = INODE_ITEM(lip);
struct xfs_inode *ip = iip->ili_inode;
struct xfs_inode_log_format *ilf;
struct xfs_log_iovec *vecp = NULL;
ASSERT(ip->i_d.di_version > 1);
ilf = xlog_prepare_iovec(lv, &vecp, XLOG_REG_TYPE_IFORMAT);
ilf->ilf_type = XFS_LI_INODE;
ilf->ilf_ino = ip->i_ino;
ilf->ilf_blkno = ip->i_imap.im_blkno;
ilf->ilf_len = ip->i_imap.im_len;
ilf->ilf_boffset = ip->i_imap.im_boffset;
ilf->ilf_fields = XFS_ILOG_CORE;
ilf->ilf_size = 2;
xlog_finish_iovec(lv, vecp, sizeof(struct xfs_inode_log_format));
xfs_inode_item_format_core(ip, lv, &vecp);
xfs_inode_item_format_data_fork(iip, ilf, lv, &vecp);
if (XFS_IFORK_Q(ip)) {
xfs_inode_item_format_attr_fork(iip, ilf, lv, &vecp);
} else {
iip->ili_fields &=
~(XFS_ILOG_ADATA | XFS_ILOG_ABROOT | XFS_ILOG_AEXT);
}
ilf->ilf_fields |= (iip->ili_fields & ~XFS_ILOG_TIMESTAMP);
}
STATIC void
xfs_inode_item_pin(
struct xfs_log_item *lip)
{
struct xfs_inode *ip = INODE_ITEM(lip)->ili_inode;
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
trace_xfs_inode_pin(ip, _RET_IP_);
atomic_inc(&ip->i_pincount);
}
STATIC void
xfs_inode_item_unpin(
struct xfs_log_item *lip,
int remove)
{
struct xfs_inode *ip = INODE_ITEM(lip)->ili_inode;
trace_xfs_inode_unpin(ip, _RET_IP_);
ASSERT(atomic_read(&ip->i_pincount) > 0);
if (atomic_dec_and_test(&ip->i_pincount))
wake_up_bit(&ip->i_flags, __XFS_IPINNED_BIT);
}
STATIC uint
xfs_inode_item_push(
struct xfs_log_item *lip,
struct list_head *buffer_list)
__releases(&lip->li_ailp->xa_lock
STATIC void
xfs_inode_item_unlock(
struct xfs_log_item *lip)
{
struct xfs_inode_log_item *iip = INODE_ITEM(lip);
struct xfs_inode *ip = iip->ili_inode;
unsigned short lock_flags;
ASSERT(ip->i_itemp != NULL);
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
lock_flags = iip->ili_lock_flags;
iip->ili_lock_flags = 0;
if (lock_flags)
xfs_iunlock(ip, lock_flags);
}
STATIC xfs_lsn_t
xfs_inode_item_committed(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
struct xfs_inode_log_item *iip = INODE_ITEM(lip);
struct xfs_inode *ip = iip->ili_inode;
if (xfs_iflags_test(ip, XFS_ISTALE)) {
xfs_inode_item_unpin(lip, 0);
return -1;
}
return lsn;
}
STATIC void
xfs_inode_item_committing(
struct xfs_log_item *lip,
xfs_lsn_t lsn)
{
INODE_ITEM(lip)->ili_last_lsn = lsn;
}
void
xfs_inode_item_init(
struct xfs_inode *ip,
struct xfs_mount *mp)
{
struct xfs_inode_log_item *iip;
ASSERT(ip->i_itemp == NULL);
iip = ip->i_itemp = kmem_zone_zalloc(xfs_ili_zone, KM_SLEEP);
iip->ili_inode = ip;
xfs_log_item_init(mp, &iip->ili_item, XFS_LI_INODE,
&xfs_inode_item_ops);
}
void
xfs_inode_item_destroy(
xfs_inode_t *ip)
{
kmem_free(ip->i_itemp->ili_item.li_lv_shadow);
kmem_zone_free(xfs_ili_zone, ip->i_itemp);
}
void
xfs_iflush_done(
struct xfs_buf *bp,
struct xfs_log_item *lip)
{
struct xfs_inode_log_item *iip;
struct xfs_log_item *blip;
struct xfs_log_item *next;
struct xfs_log_item *prev;
struct xfs_ail *ailp = lip->li_ailp;
int need_ail = 0;
blip = bp->b_fspriv;
prev = NULL;
while (blip != NULL) {
if (blip->li_cb != xfs_iflush_done) {
prev = blip;
blip = blip->li_bio_list;
continue;
}
next = blip->li_bio_list;
if (!prev) {
bp->b_fspriv = next;
} else {
prev->li_bio_list = next;
}
blip->li_bio_list = lip->li_bio_list;
lip->li_bio_list = blip;
iip = INODE_ITEM(blip);
if (iip->ili_logged && blip->li_lsn == iip->ili_flush_lsn)
need_ail++;
blip = next;
}
iip = INODE_ITEM(lip);
if (iip->ili_logged && lip->li_lsn == iip->ili_flush_lsn)
need_ail++;
if (need_ail) {
bool mlip_changed = false;
spin_lock(&ailp->xa_lock);
for (blip = lip; blip; blip = blip->li_bio_list) {
if (INODE_ITEM(blip)->ili_logged &&
blip->li_lsn == INODE_ITEM(blip)->ili_flush_lsn)
mlip_changed |= xfs_ail_delete_one(ailp, blip);
}
if (mlip_changed) {
if (!XFS_FORCED_SHUTDOWN(ailp->xa_mount))
xlog_assign_tail_lsn_locked(ailp->xa_mount);
if (list_empty(&ailp->xa_ail))
wake_up_all(&ailp->xa_empty);
}
spin_unlock(&ailp->xa_lock);
if (mlip_changed)
xfs_log_space_wake(ailp->xa_mount);
}
for (blip = lip; blip; blip = next) {
next = blip->li_bio_list;
blip->li_bio_list = NULL;
iip = INODE_ITEM(blip);
iip->ili_logged = 0;
iip->ili_last_fields = 0;
xfs_ifunlock(iip->ili_inode);
}
}
void
xfs_iflush_abort(
xfs_inode_t *ip,
bool stale)
{
xfs_inode_log_item_t *iip = ip->i_itemp;
if (iip) {
if (iip->ili_item.li_flags & XFS_LI_IN_AIL) {
xfs_trans_ail_remove(&iip->ili_item,
stale ? SHUTDOWN_LOG_IO_ERROR :
SHUTDOWN_CORRUPT_INCORE);
}
iip->ili_logged = 0;
iip->ili_last_fields = 0;
iip->ili_fields = 0;
iip->ili_fsync_fields = 0;
}
xfs_ifunlock(ip);
}
void
xfs_istale_done(
struct xfs_buf *bp,
struct xfs_log_item *lip)
{
xfs_iflush_abort(INODE_ITEM(lip)->ili_inode, true);
}
int
xfs_inode_item_format_convert(
xfs_log_iovec_t *buf,
xfs_inode_log_format_t *in_f)
{
if (buf->i_len == sizeof(xfs_inode_log_format_32_t)) {
xfs_inode_log_format_32_t *in_f32 = buf->i_addr;
in_f->ilf_type = in_f32->ilf_type;
in_f->ilf_size = in_f32->ilf_size;
in_f->ilf_fields = in_f32->ilf_fields;
in_f->ilf_asize = in_f32->ilf_asize;
in_f->ilf_dsize = in_f32->ilf_dsize;
in_f->ilf_ino = in_f32->ilf_ino;
uuid_copy(&in_f->ilf_u.ilfu_uuid, &in_f32->ilf_u.ilfu_uuid);
in_f->ilf_blkno = in_f32->ilf_blkno;
in_f->ilf_len = in_f32->ilf_len;
in_f->ilf_boffset = in_f32->ilf_boffset;
return 0;
} else if (buf->i_len == sizeof(xfs_inode_log_format_64_t)){
xfs_inode_log_format_64_t *in_f64 = buf->i_addr;
in_f->ilf_type = in_f64->ilf_type;
in_f->ilf_size = in_f64->ilf_size;
in_f->ilf_fields = in_f64->ilf_fields;
in_f->ilf_asize = in_f64->ilf_asize;
in_f->ilf_dsize = in_f64->ilf_dsize;
in_f->ilf_ino = in_f64->ilf_ino;
uuid_copy(&in_f->ilf_u.ilfu_uuid, &in_f64->ilf_u.ilfu_uuid);
in_f->ilf_blkno = in_f64->ilf_blkno;
in_f->ilf_len = in_f64->ilf_len;
in_f->ilf_boffset = in_f64->ilf_boffset;
return 0;
}
return -EFSCORRUPTED;
}
