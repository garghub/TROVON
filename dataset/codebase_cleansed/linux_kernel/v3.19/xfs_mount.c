STATIC int
xfs_uuid_mount(
struct xfs_mount *mp)
{
uuid_t *uuid = &mp->m_sb.sb_uuid;
int hole, i;
if (mp->m_flags & XFS_MOUNT_NOUUID)
return 0;
if (uuid_is_nil(uuid)) {
xfs_warn(mp, "Filesystem has nil UUID - can't mount");
return -EINVAL;
}
mutex_lock(&xfs_uuid_table_mutex);
for (i = 0, hole = -1; i < xfs_uuid_table_size; i++) {
if (uuid_is_nil(&xfs_uuid_table[i])) {
hole = i;
continue;
}
if (uuid_equal(uuid, &xfs_uuid_table[i]))
goto out_duplicate;
}
if (hole < 0) {
xfs_uuid_table = kmem_realloc(xfs_uuid_table,
(xfs_uuid_table_size + 1) * sizeof(*xfs_uuid_table),
xfs_uuid_table_size * sizeof(*xfs_uuid_table),
KM_SLEEP);
hole = xfs_uuid_table_size++;
}
xfs_uuid_table[hole] = *uuid;
mutex_unlock(&xfs_uuid_table_mutex);
return 0;
out_duplicate:
mutex_unlock(&xfs_uuid_table_mutex);
xfs_warn(mp, "Filesystem has duplicate UUID %pU - can't mount", uuid);
return -EINVAL;
}
STATIC void
xfs_uuid_unmount(
struct xfs_mount *mp)
{
uuid_t *uuid = &mp->m_sb.sb_uuid;
int i;
if (mp->m_flags & XFS_MOUNT_NOUUID)
return;
mutex_lock(&xfs_uuid_table_mutex);
for (i = 0; i < xfs_uuid_table_size; i++) {
if (uuid_is_nil(&xfs_uuid_table[i]))
continue;
if (!uuid_equal(uuid, &xfs_uuid_table[i]))
continue;
memset(&xfs_uuid_table[i], 0, sizeof(uuid_t));
break;
}
ASSERT(i < xfs_uuid_table_size);
mutex_unlock(&xfs_uuid_table_mutex);
}
STATIC void
__xfs_free_perag(
struct rcu_head *head)
{
struct xfs_perag *pag = container_of(head, struct xfs_perag, rcu_head);
ASSERT(atomic_read(&pag->pag_ref) == 0);
kmem_free(pag);
}
STATIC void
xfs_free_perag(
xfs_mount_t *mp)
{
xfs_agnumber_t agno;
struct xfs_perag *pag;
for (agno = 0; agno < mp->m_sb.sb_agcount; agno++) {
spin_lock(&mp->m_perag_lock);
pag = radix_tree_delete(&mp->m_perag_tree, agno);
spin_unlock(&mp->m_perag_lock);
ASSERT(pag);
ASSERT(atomic_read(&pag->pag_ref) == 0);
call_rcu(&pag->rcu_head, __xfs_free_perag);
}
}
int
xfs_sb_validate_fsb_count(
xfs_sb_t *sbp,
__uint64_t nblocks)
{
ASSERT(PAGE_SHIFT >= sbp->sb_blocklog);
ASSERT(sbp->sb_blocklog >= BBSHIFT);
if (nblocks >> (PAGE_CACHE_SHIFT - sbp->sb_blocklog) > ULONG_MAX)
return -EFBIG;
return 0;
}
int
xfs_initialize_perag(
xfs_mount_t *mp,
xfs_agnumber_t agcount,
xfs_agnumber_t *maxagi)
{
xfs_agnumber_t index;
xfs_agnumber_t first_initialised = 0;
xfs_perag_t *pag;
xfs_agino_t agino;
xfs_ino_t ino;
xfs_sb_t *sbp = &mp->m_sb;
int error = -ENOMEM;
for (index = 0; index < agcount; index++) {
pag = xfs_perag_get(mp, index);
if (pag) {
xfs_perag_put(pag);
continue;
}
if (!first_initialised)
first_initialised = index;
pag = kmem_zalloc(sizeof(*pag), KM_MAYFAIL);
if (!pag)
goto out_unwind;
pag->pag_agno = index;
pag->pag_mount = mp;
spin_lock_init(&pag->pag_ici_lock);
mutex_init(&pag->pag_ici_reclaim_lock);
INIT_RADIX_TREE(&pag->pag_ici_root, GFP_ATOMIC);
spin_lock_init(&pag->pag_buf_lock);
pag->pag_buf_tree = RB_ROOT;
if (radix_tree_preload(GFP_NOFS))
goto out_unwind;
spin_lock(&mp->m_perag_lock);
if (radix_tree_insert(&mp->m_perag_tree, index, pag)) {
BUG();
spin_unlock(&mp->m_perag_lock);
radix_tree_preload_end();
error = -EEXIST;
goto out_unwind;
}
spin_unlock(&mp->m_perag_lock);
radix_tree_preload_end();
}
agino = XFS_OFFBNO_TO_AGINO(mp, sbp->sb_agblocks - 1, 0);
ino = XFS_AGINO_TO_INO(mp, agcount - 1, agino);
if ((mp->m_flags & XFS_MOUNT_SMALL_INUMS) && ino > XFS_MAXINUMBER_32)
mp->m_flags |= XFS_MOUNT_32BITINODES;
else
mp->m_flags &= ~XFS_MOUNT_32BITINODES;
if (mp->m_flags & XFS_MOUNT_32BITINODES)
index = xfs_set_inode32(mp, agcount);
else
index = xfs_set_inode64(mp, agcount);
if (maxagi)
*maxagi = index;
return 0;
out_unwind:
kmem_free(pag);
for (; index > first_initialised; index--) {
pag = radix_tree_delete(&mp->m_perag_tree, index);
kmem_free(pag);
}
return error;
}
int
xfs_readsb(
struct xfs_mount *mp,
int flags)
{
unsigned int sector_size;
struct xfs_buf *bp;
struct xfs_sb *sbp = &mp->m_sb;
int error;
int loud = !(flags & XFS_MFSI_QUIET);
const struct xfs_buf_ops *buf_ops;
ASSERT(mp->m_sb_bp == NULL);
ASSERT(mp->m_ddev_targp != NULL);
sector_size = xfs_getsize_buftarg(mp->m_ddev_targp);
buf_ops = NULL;
reread:
error = xfs_buf_read_uncached(mp->m_ddev_targp, XFS_SB_DADDR,
BTOBB(sector_size), 0, &bp, buf_ops);
if (error) {
if (loud)
xfs_warn(mp, "SB validate failed with error %d.", error);
if (error == -EFSBADCRC)
error = -EFSCORRUPTED;
return error;
}
xfs_sb_from_disk(sbp, XFS_BUF_TO_SBP(bp));
if (sbp->sb_magicnum != XFS_SB_MAGIC) {
if (loud)
xfs_warn(mp, "Invalid superblock magic number");
error = -EINVAL;
goto release_buf;
}
if (sector_size > sbp->sb_sectsize) {
if (loud)
xfs_warn(mp, "device supports %u byte sectors (not %u)",
sector_size, sbp->sb_sectsize);
error = -ENOSYS;
goto release_buf;
}
if (buf_ops == NULL) {
xfs_buf_relse(bp);
sector_size = sbp->sb_sectsize;
buf_ops = loud ? &xfs_sb_buf_ops : &xfs_sb_quiet_buf_ops;
goto reread;
}
xfs_icsb_reinit_counters(mp);
bp->b_ops = &xfs_sb_buf_ops;
mp->m_sb_bp = bp;
xfs_buf_unlock(bp);
return 0;
release_buf:
xfs_buf_relse(bp);
return error;
}
STATIC int
xfs_update_alignment(xfs_mount_t *mp)
{
xfs_sb_t *sbp = &(mp->m_sb);
if (mp->m_dalign) {
if ((BBTOB(mp->m_dalign) & mp->m_blockmask) ||
(BBTOB(mp->m_swidth) & mp->m_blockmask)) {
xfs_warn(mp,
"alignment check failed: sunit/swidth vs. blocksize(%d)",
sbp->sb_blocksize);
return -EINVAL;
} else {
mp->m_dalign = XFS_BB_TO_FSBT(mp, mp->m_dalign);
if (mp->m_dalign && (sbp->sb_agblocks % mp->m_dalign)) {
xfs_warn(mp,
"alignment check failed: sunit/swidth vs. agsize(%d)",
sbp->sb_agblocks);
return -EINVAL;
} else if (mp->m_dalign) {
mp->m_swidth = XFS_BB_TO_FSBT(mp, mp->m_swidth);
} else {
xfs_warn(mp,
"alignment check failed: sunit(%d) less than bsize(%d)",
mp->m_dalign, sbp->sb_blocksize);
return -EINVAL;
}
}
if (xfs_sb_version_hasdalign(sbp)) {
if (sbp->sb_unit != mp->m_dalign) {
sbp->sb_unit = mp->m_dalign;
mp->m_update_flags |= XFS_SB_UNIT;
}
if (sbp->sb_width != mp->m_swidth) {
sbp->sb_width = mp->m_swidth;
mp->m_update_flags |= XFS_SB_WIDTH;
}
} else {
xfs_warn(mp,
"cannot change alignment: superblock does not support data alignment");
return -EINVAL;
}
} else if ((mp->m_flags & XFS_MOUNT_NOALIGN) != XFS_MOUNT_NOALIGN &&
xfs_sb_version_hasdalign(&mp->m_sb)) {
mp->m_dalign = sbp->sb_unit;
mp->m_swidth = sbp->sb_width;
}
return 0;
}
STATIC void
xfs_set_maxicount(xfs_mount_t *mp)
{
xfs_sb_t *sbp = &(mp->m_sb);
__uint64_t icount;
if (sbp->sb_imax_pct) {
icount = sbp->sb_dblocks * sbp->sb_imax_pct;
do_div(icount, 100);
do_div(icount, mp->m_ialloc_blks);
mp->m_maxicount = (icount * mp->m_ialloc_blks) <<
sbp->sb_inopblog;
} else {
mp->m_maxicount = 0;
}
}
STATIC void
xfs_set_rw_sizes(xfs_mount_t *mp)
{
xfs_sb_t *sbp = &(mp->m_sb);
int readio_log, writeio_log;
if (!(mp->m_flags & XFS_MOUNT_DFLT_IOSIZE)) {
if (mp->m_flags & XFS_MOUNT_WSYNC) {
readio_log = XFS_WSYNC_READIO_LOG;
writeio_log = XFS_WSYNC_WRITEIO_LOG;
} else {
readio_log = XFS_READIO_LOG_LARGE;
writeio_log = XFS_WRITEIO_LOG_LARGE;
}
} else {
readio_log = mp->m_readio_log;
writeio_log = mp->m_writeio_log;
}
if (sbp->sb_blocklog > readio_log) {
mp->m_readio_log = sbp->sb_blocklog;
} else {
mp->m_readio_log = readio_log;
}
mp->m_readio_blocks = 1 << (mp->m_readio_log - sbp->sb_blocklog);
if (sbp->sb_blocklog > writeio_log) {
mp->m_writeio_log = sbp->sb_blocklog;
} else {
mp->m_writeio_log = writeio_log;
}
mp->m_writeio_blocks = 1 << (mp->m_writeio_log - sbp->sb_blocklog);
}
void
xfs_set_low_space_thresholds(
struct xfs_mount *mp)
{
int i;
for (i = 0; i < XFS_LOWSP_MAX; i++) {
__uint64_t space = mp->m_sb.sb_dblocks;
do_div(space, 100);
mp->m_low_space[i] = space * (i + 1);
}
}
STATIC void
xfs_set_inoalignment(xfs_mount_t *mp)
{
if (xfs_sb_version_hasalign(&mp->m_sb) &&
mp->m_sb.sb_inoalignmt >=
XFS_B_TO_FSBT(mp, mp->m_inode_cluster_size))
mp->m_inoalign_mask = mp->m_sb.sb_inoalignmt - 1;
else
mp->m_inoalign_mask = 0;
if (mp->m_dalign && mp->m_inoalign_mask &&
!(mp->m_dalign & mp->m_inoalign_mask))
mp->m_sinoalign = mp->m_dalign;
else
mp->m_sinoalign = 0;
}
STATIC int
xfs_check_sizes(
struct xfs_mount *mp)
{
struct xfs_buf *bp;
xfs_daddr_t d;
int error;
d = (xfs_daddr_t)XFS_FSB_TO_BB(mp, mp->m_sb.sb_dblocks);
if (XFS_BB_TO_FSB(mp, d) != mp->m_sb.sb_dblocks) {
xfs_warn(mp, "filesystem size mismatch detected");
return -EFBIG;
}
error = xfs_buf_read_uncached(mp->m_ddev_targp,
d - XFS_FSS_TO_BB(mp, 1),
XFS_FSS_TO_BB(mp, 1), 0, &bp, NULL);
if (error) {
xfs_warn(mp, "last sector read failed");
return error;
}
xfs_buf_relse(bp);
if (mp->m_logdev_targp == mp->m_ddev_targp)
return 0;
d = (xfs_daddr_t)XFS_FSB_TO_BB(mp, mp->m_sb.sb_logblocks);
if (XFS_BB_TO_FSB(mp, d) != mp->m_sb.sb_logblocks) {
xfs_warn(mp, "log size mismatch detected");
return -EFBIG;
}
error = xfs_buf_read_uncached(mp->m_logdev_targp,
d - XFS_FSB_TO_BB(mp, 1),
XFS_FSB_TO_BB(mp, 1), 0, &bp, NULL);
if (error) {
xfs_warn(mp, "log device read failed");
return error;
}
xfs_buf_relse(bp);
return 0;
}
int
xfs_mount_reset_sbqflags(
struct xfs_mount *mp)
{
int error;
struct xfs_trans *tp;
mp->m_qflags = 0;
if (mp->m_sb.sb_qflags == 0)
return 0;
spin_lock(&mp->m_sb_lock);
mp->m_sb.sb_qflags = 0;
spin_unlock(&mp->m_sb_lock);
if (mp->m_flags & XFS_MOUNT_RDONLY)
return 0;
tp = xfs_trans_alloc(mp, XFS_TRANS_QM_SBCHANGE);
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_qm_sbchange, 0, 0);
if (error) {
xfs_trans_cancel(tp, 0);
xfs_alert(mp, "%s: Superblock update failed!", __func__);
return error;
}
xfs_mod_sb(tp, XFS_SB_QFLAGS);
return xfs_trans_commit(tp, 0);
}
__uint64_t
xfs_default_resblks(xfs_mount_t *mp)
{
__uint64_t resblks;
resblks = mp->m_sb.sb_dblocks;
do_div(resblks, 20);
resblks = min_t(__uint64_t, resblks, 8192);
return resblks;
}
int
xfs_mountfs(
xfs_mount_t *mp)
{
xfs_sb_t *sbp = &(mp->m_sb);
xfs_inode_t *rip;
__uint64_t resblks;
uint quotamount = 0;
uint quotaflags = 0;
int error = 0;
xfs_sb_mount_common(mp, sbp);
if (xfs_sb_has_mismatched_features2(sbp)) {
xfs_warn(mp, "correcting sb_features alignment problem");
sbp->sb_features2 |= sbp->sb_bad_features2;
sbp->sb_bad_features2 = sbp->sb_features2;
mp->m_update_flags |= XFS_SB_FEATURES2 | XFS_SB_BAD_FEATURES2;
if (xfs_sb_version_hasattr2(&mp->m_sb) &&
!(mp->m_flags & XFS_MOUNT_NOATTR2))
mp->m_flags |= XFS_MOUNT_ATTR2;
}
if (xfs_sb_version_hasattr2(&mp->m_sb) &&
(mp->m_flags & XFS_MOUNT_NOATTR2)) {
xfs_sb_version_removeattr2(&mp->m_sb);
mp->m_update_flags |= XFS_SB_FEATURES2;
if (!sbp->sb_features2)
mp->m_update_flags |= XFS_SB_VERSIONNUM;
}
if (!(mp->m_sb.sb_versionnum & XFS_SB_VERSION_NLINKBIT)) {
mp->m_sb.sb_versionnum |= XFS_SB_VERSION_NLINKBIT;
mp->m_update_flags |= XFS_SB_VERSIONNUM;
}
error = xfs_update_alignment(mp);
if (error)
goto out;
xfs_alloc_compute_maxlevels(mp);
xfs_bmap_compute_maxlevels(mp, XFS_DATA_FORK);
xfs_bmap_compute_maxlevels(mp, XFS_ATTR_FORK);
xfs_ialloc_compute_maxlevels(mp);
xfs_set_maxicount(mp);
error = xfs_sysfs_init(&mp->m_kobj, &xfs_mp_ktype, NULL, mp->m_fsname);
if (error)
goto out;
error = xfs_uuid_mount(mp);
if (error)
goto out_remove_sysfs;
xfs_set_rw_sizes(mp);
xfs_set_low_space_thresholds(mp);
mp->m_inode_cluster_size = XFS_INODE_BIG_CLUSTER_SIZE;
if (xfs_sb_version_hascrc(&mp->m_sb)) {
int new_size = mp->m_inode_cluster_size;
new_size *= mp->m_sb.sb_inodesize / XFS_DINODE_MIN_SIZE;
if (mp->m_sb.sb_inoalignmt >= XFS_B_TO_FSBT(mp, new_size))
mp->m_inode_cluster_size = new_size;
}
xfs_set_inoalignment(mp);
error = xfs_check_sizes(mp);
if (error)
goto out_remove_uuid;
error = xfs_rtmount_init(mp);
if (error) {
xfs_warn(mp, "RT mount failed");
goto out_remove_uuid;
}
uuid_getnodeuniq(&sbp->sb_uuid, mp->m_fixedfsid);
mp->m_dmevmask = 0;
error = xfs_da_mount(mp);
if (error) {
xfs_warn(mp, "Failed dir/attr init: %d", error);
goto out_remove_uuid;
}
xfs_trans_init(mp);
spin_lock_init(&mp->m_perag_lock);
INIT_RADIX_TREE(&mp->m_perag_tree, GFP_ATOMIC);
error = xfs_initialize_perag(mp, sbp->sb_agcount, &mp->m_maxagi);
if (error) {
xfs_warn(mp, "Failed per-ag init: %d", error);
goto out_free_dir;
}
if (!sbp->sb_logblocks) {
xfs_warn(mp, "no log defined");
XFS_ERROR_REPORT("xfs_mountfs", XFS_ERRLEVEL_LOW, mp);
error = -EFSCORRUPTED;
goto out_free_perag;
}
error = xfs_log_mount(mp, mp->m_logdev_targp,
XFS_FSB_TO_DADDR(mp, sbp->sb_logstart),
XFS_FSB_TO_BB(mp, sbp->sb_logblocks));
if (error) {
xfs_warn(mp, "log mount failed");
goto out_fail_wait;
}
if (xfs_sb_version_haslazysbcount(&mp->m_sb) &&
!XFS_LAST_UNMOUNT_WAS_CLEAN(mp) &&
!mp->m_sb.sb_inprogress) {
error = xfs_initialize_perag_data(mp, sbp->sb_agcount);
if (error)
goto out_log_dealloc;
}
error = xfs_iget(mp, NULL, sbp->sb_rootino, 0, XFS_ILOCK_EXCL, &rip);
if (error) {
xfs_warn(mp, "failed to read root inode");
goto out_log_dealloc;
}
ASSERT(rip != NULL);
if (unlikely(!S_ISDIR(rip->i_d.di_mode))) {
xfs_warn(mp, "corrupted root inode %llu: not a directory",
(unsigned long long)rip->i_ino);
xfs_iunlock(rip, XFS_ILOCK_EXCL);
XFS_ERROR_REPORT("xfs_mountfs_int(2)", XFS_ERRLEVEL_LOW,
mp);
error = -EFSCORRUPTED;
goto out_rele_rip;
}
mp->m_rootip = rip;
xfs_iunlock(rip, XFS_ILOCK_EXCL);
error = xfs_rtmount_inodes(mp);
if (error) {
xfs_warn(mp, "failed to read RT inodes");
goto out_rele_rip;
}
if (mp->m_update_flags && !(mp->m_flags & XFS_MOUNT_RDONLY)) {
error = xfs_mount_log_sb(mp, mp->m_update_flags);
if (error) {
xfs_warn(mp, "failed to write sb changes");
goto out_rtunmount;
}
}
if (XFS_IS_QUOTA_RUNNING(mp)) {
error = xfs_qm_newmount(mp, &quotamount, &quotaflags);
if (error)
goto out_rtunmount;
} else {
ASSERT(!XFS_IS_QUOTA_ON(mp));
if (mp->m_sb.sb_qflags & XFS_ALL_QUOTA_ACCT) {
xfs_notice(mp, "resetting quota flags");
error = xfs_mount_reset_sbqflags(mp);
if (error)
goto out_rtunmount;
}
}
error = xfs_log_mount_finish(mp);
if (error) {
xfs_warn(mp, "log mount finish failed");
goto out_rtunmount;
}
if (quotamount) {
ASSERT(mp->m_qflags == 0);
mp->m_qflags = quotaflags;
xfs_qm_mount_quotas(mp);
}
if (!(mp->m_flags & XFS_MOUNT_RDONLY)) {
resblks = xfs_default_resblks(mp);
error = xfs_reserve_blocks(mp, &resblks, NULL);
if (error)
xfs_warn(mp,
"Unable to allocate reserve blocks. Continuing without reserve pool.");
}
return 0;
out_rtunmount:
xfs_rtunmount_inodes(mp);
out_rele_rip:
IRELE(rip);
out_log_dealloc:
xfs_log_unmount(mp);
out_fail_wait:
if (mp->m_logdev_targp && mp->m_logdev_targp != mp->m_ddev_targp)
xfs_wait_buftarg(mp->m_logdev_targp);
xfs_wait_buftarg(mp->m_ddev_targp);
out_free_perag:
xfs_free_perag(mp);
out_free_dir:
xfs_da_unmount(mp);
out_remove_uuid:
xfs_uuid_unmount(mp);
out_remove_sysfs:
xfs_sysfs_del(&mp->m_kobj);
out:
return error;
}
void
xfs_unmountfs(
struct xfs_mount *mp)
{
__uint64_t resblks;
int error;
cancel_delayed_work_sync(&mp->m_eofblocks_work);
xfs_qm_unmount_quotas(mp);
xfs_rtunmount_inodes(mp);
IRELE(mp->m_rootip);
xfs_log_force(mp, XFS_LOG_SYNC);
xfs_ail_push_all_sync(mp->m_ail);
cancel_delayed_work_sync(&mp->m_reclaim_work);
xfs_reclaim_inodes(mp, SYNC_WAIT);
xfs_qm_unmount(mp);
resblks = 0;
error = xfs_reserve_blocks(mp, &resblks, NULL);
if (error)
xfs_warn(mp, "Unable to free reserved block pool. "
"Freespace may not be correct on next mount.");
error = xfs_log_sbcount(mp);
if (error)
xfs_warn(mp, "Unable to update superblock counters. "
"Freespace may not be correct on next mount.");
xfs_log_unmount(mp);
xfs_da_unmount(mp);
xfs_uuid_unmount(mp);
#if defined(DEBUG)
xfs_errortag_clearall(mp, 0);
#endif
xfs_free_perag(mp);
xfs_sysfs_del(&mp->m_kobj);
}
bool
xfs_fs_writable(
struct xfs_mount *mp,
int level)
{
ASSERT(level > SB_UNFROZEN);
if ((mp->m_super->s_writers.frozen >= level) ||
XFS_FORCED_SHUTDOWN(mp) || (mp->m_flags & XFS_MOUNT_RDONLY))
return false;
return true;
}
int
xfs_log_sbcount(xfs_mount_t *mp)
{
xfs_trans_t *tp;
int error;
if (!xfs_fs_writable(mp, SB_FREEZE_COMPLETE))
return 0;
xfs_icsb_sync_counters(mp, 0);
if (!xfs_sb_version_haslazysbcount(&mp->m_sb))
return 0;
tp = _xfs_trans_alloc(mp, XFS_TRANS_SB_COUNT, KM_SLEEP);
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_sb, 0, 0);
if (error) {
xfs_trans_cancel(tp, 0);
return error;
}
xfs_mod_sb(tp, XFS_SB_IFREE | XFS_SB_ICOUNT | XFS_SB_FDBLOCKS);
xfs_trans_set_sync(tp);
error = xfs_trans_commit(tp, 0);
return error;
}
STATIC int
xfs_mod_incore_sb_unlocked(
xfs_mount_t *mp,
xfs_sb_field_t field,
int64_t delta,
int rsvd)
{
int scounter;
long long lcounter;
long long res_used, rem;
switch (field) {
case XFS_SBS_ICOUNT:
lcounter = (long long)mp->m_sb.sb_icount;
lcounter += delta;
if (lcounter < 0) {
ASSERT(0);
return -EINVAL;
}
mp->m_sb.sb_icount = lcounter;
return 0;
case XFS_SBS_IFREE:
lcounter = (long long)mp->m_sb.sb_ifree;
lcounter += delta;
if (lcounter < 0) {
ASSERT(0);
return -EINVAL;
}
mp->m_sb.sb_ifree = lcounter;
return 0;
case XFS_SBS_FDBLOCKS:
lcounter = (long long)
mp->m_sb.sb_fdblocks - XFS_ALLOC_SET_ASIDE(mp);
res_used = (long long)(mp->m_resblks - mp->m_resblks_avail);
if (delta > 0) {
if (res_used > delta) {
mp->m_resblks_avail += delta;
} else {
rem = delta - res_used;
mp->m_resblks_avail = mp->m_resblks;
lcounter += rem;
}
} else {
lcounter += delta;
if (lcounter >= 0) {
mp->m_sb.sb_fdblocks = lcounter +
XFS_ALLOC_SET_ASIDE(mp);
return 0;
}
if (!rsvd)
return -ENOSPC;
lcounter = (long long)mp->m_resblks_avail + delta;
if (lcounter >= 0) {
mp->m_resblks_avail = lcounter;
return 0;
}
printk_once(KERN_WARNING
"Filesystem \"%s\": reserve blocks depleted! "
"Consider increasing reserve pool size.",
mp->m_fsname);
return -ENOSPC;
}
mp->m_sb.sb_fdblocks = lcounter + XFS_ALLOC_SET_ASIDE(mp);
return 0;
case XFS_SBS_FREXTENTS:
lcounter = (long long)mp->m_sb.sb_frextents;
lcounter += delta;
if (lcounter < 0) {
return -ENOSPC;
}
mp->m_sb.sb_frextents = lcounter;
return 0;
case XFS_SBS_DBLOCKS:
lcounter = (long long)mp->m_sb.sb_dblocks;
lcounter += delta;
if (lcounter < 0) {
ASSERT(0);
return -EINVAL;
}
mp->m_sb.sb_dblocks = lcounter;
return 0;
case XFS_SBS_AGCOUNT:
scounter = mp->m_sb.sb_agcount;
scounter += delta;
if (scounter < 0) {
ASSERT(0);
return -EINVAL;
}
mp->m_sb.sb_agcount = scounter;
return 0;
case XFS_SBS_IMAX_PCT:
scounter = mp->m_sb.sb_imax_pct;
scounter += delta;
if (scounter < 0) {
ASSERT(0);
return -EINVAL;
}
mp->m_sb.sb_imax_pct = scounter;
return 0;
case XFS_SBS_REXTSIZE:
scounter = mp->m_sb.sb_rextsize;
scounter += delta;
if (scounter < 0) {
ASSERT(0);
return -EINVAL;
}
mp->m_sb.sb_rextsize = scounter;
return 0;
case XFS_SBS_RBMBLOCKS:
scounter = mp->m_sb.sb_rbmblocks;
scounter += delta;
if (scounter < 0) {
ASSERT(0);
return -EINVAL;
}
mp->m_sb.sb_rbmblocks = scounter;
return 0;
case XFS_SBS_RBLOCKS:
lcounter = (long long)mp->m_sb.sb_rblocks;
lcounter += delta;
if (lcounter < 0) {
ASSERT(0);
return -EINVAL;
}
mp->m_sb.sb_rblocks = lcounter;
return 0;
case XFS_SBS_REXTENTS:
lcounter = (long long)mp->m_sb.sb_rextents;
lcounter += delta;
if (lcounter < 0) {
ASSERT(0);
return -EINVAL;
}
mp->m_sb.sb_rextents = lcounter;
return 0;
case XFS_SBS_REXTSLOG:
scounter = mp->m_sb.sb_rextslog;
scounter += delta;
if (scounter < 0) {
ASSERT(0);
return -EINVAL;
}
mp->m_sb.sb_rextslog = scounter;
return 0;
default:
ASSERT(0);
return -EINVAL;
}
}
int
xfs_mod_incore_sb(
struct xfs_mount *mp,
xfs_sb_field_t field,
int64_t delta,
int rsvd)
{
int status;
#ifdef HAVE_PERCPU_SB
ASSERT(field < XFS_SBS_ICOUNT || field > XFS_SBS_FDBLOCKS);
#endif
spin_lock(&mp->m_sb_lock);
status = xfs_mod_incore_sb_unlocked(mp, field, delta, rsvd);
spin_unlock(&mp->m_sb_lock);
return status;
}
int
xfs_mod_incore_sb_batch(
struct xfs_mount *mp,
xfs_mod_sb_t *msb,
uint nmsb,
int rsvd)
{
xfs_mod_sb_t *msbp;
int error = 0;
spin_lock(&mp->m_sb_lock);
for (msbp = msb; msbp < (msb + nmsb); msbp++) {
ASSERT(msbp->msb_field < XFS_SBS_ICOUNT ||
msbp->msb_field > XFS_SBS_FDBLOCKS);
error = xfs_mod_incore_sb_unlocked(mp, msbp->msb_field,
msbp->msb_delta, rsvd);
if (error)
goto unwind;
}
spin_unlock(&mp->m_sb_lock);
return 0;
unwind:
while (--msbp >= msb) {
error = xfs_mod_incore_sb_unlocked(mp, msbp->msb_field,
-msbp->msb_delta, rsvd);
ASSERT(error == 0);
}
spin_unlock(&mp->m_sb_lock);
return error;
}
struct xfs_buf *
xfs_getsb(
struct xfs_mount *mp,
int flags)
{
struct xfs_buf *bp = mp->m_sb_bp;
if (!xfs_buf_trylock(bp)) {
if (flags & XBF_TRYLOCK)
return NULL;
xfs_buf_lock(bp);
}
xfs_buf_hold(bp);
ASSERT(XFS_BUF_ISDONE(bp));
return bp;
}
void
xfs_freesb(
struct xfs_mount *mp)
{
struct xfs_buf *bp = mp->m_sb_bp;
xfs_buf_lock(bp);
mp->m_sb_bp = NULL;
xfs_buf_relse(bp);
}
int
xfs_mount_log_sb(
xfs_mount_t *mp,
__int64_t fields)
{
xfs_trans_t *tp;
int error;
ASSERT(fields & (XFS_SB_UNIT | XFS_SB_WIDTH | XFS_SB_UUID |
XFS_SB_FEATURES2 | XFS_SB_BAD_FEATURES2 |
XFS_SB_VERSIONNUM));
tp = xfs_trans_alloc(mp, XFS_TRANS_SB_UNIT);
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_sb, 0, 0);
if (error) {
xfs_trans_cancel(tp, 0);
return error;
}
xfs_mod_sb(tp, fields);
error = xfs_trans_commit(tp, 0);
return error;
}
int
xfs_dev_is_read_only(
struct xfs_mount *mp,
char *message)
{
if (xfs_readonly_buftarg(mp->m_ddev_targp) ||
xfs_readonly_buftarg(mp->m_logdev_targp) ||
(mp->m_rtdev_targp && xfs_readonly_buftarg(mp->m_rtdev_targp))) {
xfs_notice(mp, "%s required on read-only device.", message);
xfs_notice(mp, "write access unavailable, cannot proceed.");
return -EROFS;
}
return 0;
}
STATIC int
xfs_icsb_cpu_notify(
struct notifier_block *nfb,
unsigned long action,
void *hcpu)
{
xfs_icsb_cnts_t *cntp;
xfs_mount_t *mp;
mp = (xfs_mount_t *)container_of(nfb, xfs_mount_t, m_icsb_notifier);
cntp = (xfs_icsb_cnts_t *)
per_cpu_ptr(mp->m_sb_cnts, (unsigned long)hcpu);
switch (action) {
case CPU_UP_PREPARE:
case CPU_UP_PREPARE_FROZEN:
memset(cntp, 0, sizeof(xfs_icsb_cnts_t));
break;
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
xfs_icsb_lock(mp);
xfs_icsb_balance_counter(mp, XFS_SBS_ICOUNT, 0);
xfs_icsb_balance_counter(mp, XFS_SBS_IFREE, 0);
xfs_icsb_balance_counter(mp, XFS_SBS_FDBLOCKS, 0);
xfs_icsb_unlock(mp);
break;
case CPU_DEAD:
case CPU_DEAD_FROZEN:
xfs_icsb_lock(mp);
spin_lock(&mp->m_sb_lock);
xfs_icsb_disable_counter(mp, XFS_SBS_ICOUNT);
xfs_icsb_disable_counter(mp, XFS_SBS_IFREE);
xfs_icsb_disable_counter(mp, XFS_SBS_FDBLOCKS);
mp->m_sb.sb_icount += cntp->icsb_icount;
mp->m_sb.sb_ifree += cntp->icsb_ifree;
mp->m_sb.sb_fdblocks += cntp->icsb_fdblocks;
memset(cntp, 0, sizeof(xfs_icsb_cnts_t));
xfs_icsb_balance_counter_locked(mp, XFS_SBS_ICOUNT, 0);
xfs_icsb_balance_counter_locked(mp, XFS_SBS_IFREE, 0);
xfs_icsb_balance_counter_locked(mp, XFS_SBS_FDBLOCKS, 0);
spin_unlock(&mp->m_sb_lock);
xfs_icsb_unlock(mp);
break;
}
return NOTIFY_OK;
}
int
xfs_icsb_init_counters(
xfs_mount_t *mp)
{
xfs_icsb_cnts_t *cntp;
int i;
mp->m_sb_cnts = alloc_percpu(xfs_icsb_cnts_t);
if (mp->m_sb_cnts == NULL)
return -ENOMEM;
for_each_online_cpu(i) {
cntp = (xfs_icsb_cnts_t *)per_cpu_ptr(mp->m_sb_cnts, i);
memset(cntp, 0, sizeof(xfs_icsb_cnts_t));
}
mutex_init(&mp->m_icsb_mutex);
mp->m_icsb_counters = -1;
#ifdef CONFIG_HOTPLUG_CPU
mp->m_icsb_notifier.notifier_call = xfs_icsb_cpu_notify;
mp->m_icsb_notifier.priority = 0;
register_hotcpu_notifier(&mp->m_icsb_notifier);
#endif
return 0;
}
void
xfs_icsb_reinit_counters(
xfs_mount_t *mp)
{
xfs_icsb_lock(mp);
mp->m_icsb_counters = -1;
xfs_icsb_balance_counter(mp, XFS_SBS_ICOUNT, 0);
xfs_icsb_balance_counter(mp, XFS_SBS_IFREE, 0);
xfs_icsb_balance_counter(mp, XFS_SBS_FDBLOCKS, 0);
xfs_icsb_unlock(mp);
}
void
xfs_icsb_destroy_counters(
xfs_mount_t *mp)
{
if (mp->m_sb_cnts) {
unregister_hotcpu_notifier(&mp->m_icsb_notifier);
free_percpu(mp->m_sb_cnts);
}
mutex_destroy(&mp->m_icsb_mutex);
}
STATIC void
xfs_icsb_lock_cntr(
xfs_icsb_cnts_t *icsbp)
{
while (test_and_set_bit(XFS_ICSB_FLAG_LOCK, &icsbp->icsb_flags)) {
ndelay(1000);
}
}
STATIC void
xfs_icsb_unlock_cntr(
xfs_icsb_cnts_t *icsbp)
{
clear_bit(XFS_ICSB_FLAG_LOCK, &icsbp->icsb_flags);
}
STATIC void
xfs_icsb_lock_all_counters(
xfs_mount_t *mp)
{
xfs_icsb_cnts_t *cntp;
int i;
for_each_online_cpu(i) {
cntp = (xfs_icsb_cnts_t *)per_cpu_ptr(mp->m_sb_cnts, i);
xfs_icsb_lock_cntr(cntp);
}
}
STATIC void
xfs_icsb_unlock_all_counters(
xfs_mount_t *mp)
{
xfs_icsb_cnts_t *cntp;
int i;
for_each_online_cpu(i) {
cntp = (xfs_icsb_cnts_t *)per_cpu_ptr(mp->m_sb_cnts, i);
xfs_icsb_unlock_cntr(cntp);
}
}
STATIC void
xfs_icsb_count(
xfs_mount_t *mp,
xfs_icsb_cnts_t *cnt,
int flags)
{
xfs_icsb_cnts_t *cntp;
int i;
memset(cnt, 0, sizeof(xfs_icsb_cnts_t));
if (!(flags & XFS_ICSB_LAZY_COUNT))
xfs_icsb_lock_all_counters(mp);
for_each_online_cpu(i) {
cntp = (xfs_icsb_cnts_t *)per_cpu_ptr(mp->m_sb_cnts, i);
cnt->icsb_icount += cntp->icsb_icount;
cnt->icsb_ifree += cntp->icsb_ifree;
cnt->icsb_fdblocks += cntp->icsb_fdblocks;
}
if (!(flags & XFS_ICSB_LAZY_COUNT))
xfs_icsb_unlock_all_counters(mp);
}
STATIC int
xfs_icsb_counter_disabled(
xfs_mount_t *mp,
xfs_sb_field_t field)
{
ASSERT((field >= XFS_SBS_ICOUNT) && (field <= XFS_SBS_FDBLOCKS));
return test_bit(field, &mp->m_icsb_counters);
}
STATIC void
xfs_icsb_disable_counter(
xfs_mount_t *mp,
xfs_sb_field_t field)
{
xfs_icsb_cnts_t cnt;
ASSERT((field >= XFS_SBS_ICOUNT) && (field <= XFS_SBS_FDBLOCKS));
if (xfs_icsb_counter_disabled(mp, field))
return;
xfs_icsb_lock_all_counters(mp);
if (!test_and_set_bit(field, &mp->m_icsb_counters)) {
xfs_icsb_count(mp, &cnt, XFS_ICSB_LAZY_COUNT);
switch(field) {
case XFS_SBS_ICOUNT:
mp->m_sb.sb_icount = cnt.icsb_icount;
break;
case XFS_SBS_IFREE:
mp->m_sb.sb_ifree = cnt.icsb_ifree;
break;
case XFS_SBS_FDBLOCKS:
mp->m_sb.sb_fdblocks = cnt.icsb_fdblocks;
break;
default:
BUG();
}
}
xfs_icsb_unlock_all_counters(mp);
}
STATIC void
xfs_icsb_enable_counter(
xfs_mount_t *mp,
xfs_sb_field_t field,
uint64_t count,
uint64_t resid)
{
xfs_icsb_cnts_t *cntp;
int i;
ASSERT((field >= XFS_SBS_ICOUNT) && (field <= XFS_SBS_FDBLOCKS));
xfs_icsb_lock_all_counters(mp);
for_each_online_cpu(i) {
cntp = per_cpu_ptr(mp->m_sb_cnts, i);
switch (field) {
case XFS_SBS_ICOUNT:
cntp->icsb_icount = count + resid;
break;
case XFS_SBS_IFREE:
cntp->icsb_ifree = count + resid;
break;
case XFS_SBS_FDBLOCKS:
cntp->icsb_fdblocks = count + resid;
break;
default:
BUG();
break;
}
resid = 0;
}
clear_bit(field, &mp->m_icsb_counters);
xfs_icsb_unlock_all_counters(mp);
}
void
xfs_icsb_sync_counters_locked(
xfs_mount_t *mp,
int flags)
{
xfs_icsb_cnts_t cnt;
xfs_icsb_count(mp, &cnt, flags);
if (!xfs_icsb_counter_disabled(mp, XFS_SBS_ICOUNT))
mp->m_sb.sb_icount = cnt.icsb_icount;
if (!xfs_icsb_counter_disabled(mp, XFS_SBS_IFREE))
mp->m_sb.sb_ifree = cnt.icsb_ifree;
if (!xfs_icsb_counter_disabled(mp, XFS_SBS_FDBLOCKS))
mp->m_sb.sb_fdblocks = cnt.icsb_fdblocks;
}
void
xfs_icsb_sync_counters(
xfs_mount_t *mp,
int flags)
{
spin_lock(&mp->m_sb_lock);
xfs_icsb_sync_counters_locked(mp, flags);
spin_unlock(&mp->m_sb_lock);
}
STATIC void
xfs_icsb_balance_counter_locked(
xfs_mount_t *mp,
xfs_sb_field_t field,
int min_per_cpu)
{
uint64_t count, resid;
int weight = num_online_cpus();
uint64_t min = (uint64_t)min_per_cpu;
xfs_icsb_disable_counter(mp, field);
switch (field) {
case XFS_SBS_ICOUNT:
count = mp->m_sb.sb_icount;
resid = do_div(count, weight);
if (count < max(min, XFS_ICSB_INO_CNTR_REENABLE))
return;
break;
case XFS_SBS_IFREE:
count = mp->m_sb.sb_ifree;
resid = do_div(count, weight);
if (count < max(min, XFS_ICSB_INO_CNTR_REENABLE))
return;
break;
case XFS_SBS_FDBLOCKS:
count = mp->m_sb.sb_fdblocks;
resid = do_div(count, weight);
if (count < max(min, XFS_ICSB_FDBLK_CNTR_REENABLE(mp)))
return;
break;
default:
BUG();
count = resid = 0;
break;
}
xfs_icsb_enable_counter(mp, field, count, resid);
}
STATIC void
xfs_icsb_balance_counter(
xfs_mount_t *mp,
xfs_sb_field_t fields,
int min_per_cpu)
{
spin_lock(&mp->m_sb_lock);
xfs_icsb_balance_counter_locked(mp, fields, min_per_cpu);
spin_unlock(&mp->m_sb_lock);
}
int
xfs_icsb_modify_counters(
xfs_mount_t *mp,
xfs_sb_field_t field,
int64_t delta,
int rsvd)
{
xfs_icsb_cnts_t *icsbp;
long long lcounter;
int ret = 0;
might_sleep();
again:
preempt_disable();
icsbp = this_cpu_ptr(mp->m_sb_cnts);
if (unlikely(xfs_icsb_counter_disabled(mp, field)))
goto slow_path;
xfs_icsb_lock_cntr(icsbp);
if (unlikely(xfs_icsb_counter_disabled(mp, field))) {
xfs_icsb_unlock_cntr(icsbp);
goto slow_path;
}
switch (field) {
case XFS_SBS_ICOUNT:
lcounter = icsbp->icsb_icount;
lcounter += delta;
if (unlikely(lcounter < 0))
goto balance_counter;
icsbp->icsb_icount = lcounter;
break;
case XFS_SBS_IFREE:
lcounter = icsbp->icsb_ifree;
lcounter += delta;
if (unlikely(lcounter < 0))
goto balance_counter;
icsbp->icsb_ifree = lcounter;
break;
case XFS_SBS_FDBLOCKS:
BUG_ON((mp->m_resblks - mp->m_resblks_avail) != 0);
lcounter = icsbp->icsb_fdblocks - XFS_ALLOC_SET_ASIDE(mp);
lcounter += delta;
if (unlikely(lcounter < 0))
goto balance_counter;
icsbp->icsb_fdblocks = lcounter + XFS_ALLOC_SET_ASIDE(mp);
break;
default:
BUG();
break;
}
xfs_icsb_unlock_cntr(icsbp);
preempt_enable();
return 0;
slow_path:
preempt_enable();
xfs_icsb_lock(mp);
if (!(xfs_icsb_counter_disabled(mp, field))) {
xfs_icsb_unlock(mp);
goto again;
}
spin_lock(&mp->m_sb_lock);
ret = xfs_mod_incore_sb_unlocked(mp, field, delta, rsvd);
spin_unlock(&mp->m_sb_lock);
if (ret != -ENOSPC)
xfs_icsb_balance_counter(mp, field, 0);
xfs_icsb_unlock(mp);
return ret;
balance_counter:
xfs_icsb_unlock_cntr(icsbp);
preempt_enable();
xfs_icsb_lock(mp);
xfs_icsb_balance_counter(mp, field, delta);
xfs_icsb_unlock(mp);
goto again;
}
