void
xfs_trans_init(
struct xfs_mount *mp)
{
xfs_trans_resv_calc(mp, M_RES(mp));
}
xfs_trans_t *
xfs_trans_alloc(
xfs_mount_t *mp,
uint type)
{
xfs_trans_t *tp;
sb_start_intwrite(mp->m_super);
tp = _xfs_trans_alloc(mp, type, KM_SLEEP);
tp->t_flags |= XFS_TRANS_FREEZE_PROT;
return tp;
}
xfs_trans_t *
_xfs_trans_alloc(
xfs_mount_t *mp,
uint type,
xfs_km_flags_t memflags)
{
xfs_trans_t *tp;
WARN_ON(mp->m_super->s_writers.frozen == SB_FREEZE_COMPLETE);
atomic_inc(&mp->m_active_trans);
tp = kmem_zone_zalloc(xfs_trans_zone, memflags);
tp->t_magic = XFS_TRANS_HEADER_MAGIC;
tp->t_type = type;
tp->t_mountp = mp;
INIT_LIST_HEAD(&tp->t_items);
INIT_LIST_HEAD(&tp->t_busy);
return tp;
}
STATIC void
xfs_trans_free(
struct xfs_trans *tp)
{
xfs_extent_busy_sort(&tp->t_busy);
xfs_extent_busy_clear(tp->t_mountp, &tp->t_busy, false);
atomic_dec(&tp->t_mountp->m_active_trans);
if (tp->t_flags & XFS_TRANS_FREEZE_PROT)
sb_end_intwrite(tp->t_mountp->m_super);
xfs_trans_free_dqinfo(tp);
kmem_zone_free(xfs_trans_zone, tp);
}
STATIC xfs_trans_t *
xfs_trans_dup(
xfs_trans_t *tp)
{
xfs_trans_t *ntp;
ntp = kmem_zone_zalloc(xfs_trans_zone, KM_SLEEP);
ntp->t_magic = XFS_TRANS_HEADER_MAGIC;
ntp->t_type = tp->t_type;
ntp->t_mountp = tp->t_mountp;
INIT_LIST_HEAD(&ntp->t_items);
INIT_LIST_HEAD(&ntp->t_busy);
ASSERT(tp->t_flags & XFS_TRANS_PERM_LOG_RES);
ASSERT(tp->t_ticket != NULL);
ntp->t_flags = XFS_TRANS_PERM_LOG_RES |
(tp->t_flags & XFS_TRANS_RESERVE) |
(tp->t_flags & XFS_TRANS_FREEZE_PROT);
tp->t_flags &= ~XFS_TRANS_FREEZE_PROT;
ntp->t_ticket = xfs_log_ticket_get(tp->t_ticket);
ntp->t_blk_res = tp->t_blk_res - tp->t_blk_res_used;
tp->t_blk_res = tp->t_blk_res_used;
ntp->t_rtx_res = tp->t_rtx_res - tp->t_rtx_res_used;
tp->t_rtx_res = tp->t_rtx_res_used;
ntp->t_pflags = tp->t_pflags;
xfs_trans_dup_dqinfo(tp, ntp);
atomic_inc(&tp->t_mountp->m_active_trans);
return ntp;
}
int
xfs_trans_reserve(
struct xfs_trans *tp,
struct xfs_trans_res *resp,
uint blocks,
uint rtextents)
{
int error = 0;
bool rsvd = (tp->t_flags & XFS_TRANS_RESERVE) != 0;
current_set_flags_nested(&tp->t_pflags, PF_FSTRANS);
if (blocks > 0) {
error = xfs_mod_fdblocks(tp->t_mountp, -((int64_t)blocks), rsvd);
if (error != 0) {
current_restore_flags_nested(&tp->t_pflags, PF_FSTRANS);
return -ENOSPC;
}
tp->t_blk_res += blocks;
}
if (resp->tr_logres > 0) {
bool permanent = false;
ASSERT(tp->t_log_res == 0 ||
tp->t_log_res == resp->tr_logres);
ASSERT(tp->t_log_count == 0 ||
tp->t_log_count == resp->tr_logcount);
if (resp->tr_logflags & XFS_TRANS_PERM_LOG_RES) {
tp->t_flags |= XFS_TRANS_PERM_LOG_RES;
permanent = true;
} else {
ASSERT(tp->t_ticket == NULL);
ASSERT(!(tp->t_flags & XFS_TRANS_PERM_LOG_RES));
}
if (tp->t_ticket != NULL) {
ASSERT(resp->tr_logflags & XFS_TRANS_PERM_LOG_RES);
error = xfs_log_regrant(tp->t_mountp, tp->t_ticket);
} else {
error = xfs_log_reserve(tp->t_mountp,
resp->tr_logres,
resp->tr_logcount,
&tp->t_ticket, XFS_TRANSACTION,
permanent, tp->t_type);
}
if (error)
goto undo_blocks;
tp->t_log_res = resp->tr_logres;
tp->t_log_count = resp->tr_logcount;
}
if (rtextents > 0) {
error = xfs_mod_frextents(tp->t_mountp, -((int64_t)rtextents));
if (error) {
error = -ENOSPC;
goto undo_log;
}
tp->t_rtx_res += rtextents;
}
return 0;
undo_log:
if (resp->tr_logres > 0) {
xfs_log_done(tp->t_mountp, tp->t_ticket, NULL, false);
tp->t_ticket = NULL;
tp->t_log_res = 0;
tp->t_flags &= ~XFS_TRANS_PERM_LOG_RES;
}
undo_blocks:
if (blocks > 0) {
xfs_mod_fdblocks(tp->t_mountp, -((int64_t)blocks), rsvd);
tp->t_blk_res = 0;
}
current_restore_flags_nested(&tp->t_pflags, PF_FSTRANS);
return error;
}
void
xfs_trans_mod_sb(
xfs_trans_t *tp,
uint field,
int64_t delta)
{
uint32_t flags = (XFS_TRANS_DIRTY|XFS_TRANS_SB_DIRTY);
xfs_mount_t *mp = tp->t_mountp;
switch (field) {
case XFS_TRANS_SB_ICOUNT:
tp->t_icount_delta += delta;
if (xfs_sb_version_haslazysbcount(&mp->m_sb))
flags &= ~XFS_TRANS_SB_DIRTY;
break;
case XFS_TRANS_SB_IFREE:
tp->t_ifree_delta += delta;
if (xfs_sb_version_haslazysbcount(&mp->m_sb))
flags &= ~XFS_TRANS_SB_DIRTY;
break;
case XFS_TRANS_SB_FDBLOCKS:
if (delta < 0) {
tp->t_blk_res_used += (uint)-delta;
ASSERT(tp->t_blk_res_used <= tp->t_blk_res);
}
tp->t_fdblocks_delta += delta;
if (xfs_sb_version_haslazysbcount(&mp->m_sb))
flags &= ~XFS_TRANS_SB_DIRTY;
break;
case XFS_TRANS_SB_RES_FDBLOCKS:
ASSERT(delta < 0);
tp->t_res_fdblocks_delta += delta;
if (xfs_sb_version_haslazysbcount(&mp->m_sb))
flags &= ~XFS_TRANS_SB_DIRTY;
break;
case XFS_TRANS_SB_FREXTENTS:
if (delta < 0) {
tp->t_rtx_res_used += (uint)-delta;
ASSERT(tp->t_rtx_res_used <= tp->t_rtx_res);
}
tp->t_frextents_delta += delta;
break;
case XFS_TRANS_SB_RES_FREXTENTS:
ASSERT(delta < 0);
tp->t_res_frextents_delta += delta;
break;
case XFS_TRANS_SB_DBLOCKS:
ASSERT(delta > 0);
tp->t_dblocks_delta += delta;
break;
case XFS_TRANS_SB_AGCOUNT:
ASSERT(delta > 0);
tp->t_agcount_delta += delta;
break;
case XFS_TRANS_SB_IMAXPCT:
tp->t_imaxpct_delta += delta;
break;
case XFS_TRANS_SB_REXTSIZE:
tp->t_rextsize_delta += delta;
break;
case XFS_TRANS_SB_RBMBLOCKS:
tp->t_rbmblocks_delta += delta;
break;
case XFS_TRANS_SB_RBLOCKS:
tp->t_rblocks_delta += delta;
break;
case XFS_TRANS_SB_REXTENTS:
tp->t_rextents_delta += delta;
break;
case XFS_TRANS_SB_REXTSLOG:
tp->t_rextslog_delta += delta;
break;
default:
ASSERT(0);
return;
}
tp->t_flags |= flags;
}
STATIC void
xfs_trans_apply_sb_deltas(
xfs_trans_t *tp)
{
xfs_dsb_t *sbp;
xfs_buf_t *bp;
int whole = 0;
bp = xfs_trans_getsb(tp, tp->t_mountp, 0);
sbp = XFS_BUF_TO_SBP(bp);
ASSERT((tp->t_fdblocks_delta + tp->t_res_fdblocks_delta) ==
(tp->t_ag_freeblks_delta + tp->t_ag_flist_delta +
tp->t_ag_btree_delta));
if (!xfs_sb_version_haslazysbcount(&(tp->t_mountp->m_sb))) {
if (tp->t_icount_delta)
be64_add_cpu(&sbp->sb_icount, tp->t_icount_delta);
if (tp->t_ifree_delta)
be64_add_cpu(&sbp->sb_ifree, tp->t_ifree_delta);
if (tp->t_fdblocks_delta)
be64_add_cpu(&sbp->sb_fdblocks, tp->t_fdblocks_delta);
if (tp->t_res_fdblocks_delta)
be64_add_cpu(&sbp->sb_fdblocks, tp->t_res_fdblocks_delta);
}
if (tp->t_frextents_delta)
be64_add_cpu(&sbp->sb_frextents, tp->t_frextents_delta);
if (tp->t_res_frextents_delta)
be64_add_cpu(&sbp->sb_frextents, tp->t_res_frextents_delta);
if (tp->t_dblocks_delta) {
be64_add_cpu(&sbp->sb_dblocks, tp->t_dblocks_delta);
whole = 1;
}
if (tp->t_agcount_delta) {
be32_add_cpu(&sbp->sb_agcount, tp->t_agcount_delta);
whole = 1;
}
if (tp->t_imaxpct_delta) {
sbp->sb_imax_pct += tp->t_imaxpct_delta;
whole = 1;
}
if (tp->t_rextsize_delta) {
be32_add_cpu(&sbp->sb_rextsize, tp->t_rextsize_delta);
whole = 1;
}
if (tp->t_rbmblocks_delta) {
be32_add_cpu(&sbp->sb_rbmblocks, tp->t_rbmblocks_delta);
whole = 1;
}
if (tp->t_rblocks_delta) {
be64_add_cpu(&sbp->sb_rblocks, tp->t_rblocks_delta);
whole = 1;
}
if (tp->t_rextents_delta) {
be64_add_cpu(&sbp->sb_rextents, tp->t_rextents_delta);
whole = 1;
}
if (tp->t_rextslog_delta) {
sbp->sb_rextslog += tp->t_rextslog_delta;
whole = 1;
}
xfs_trans_buf_set_type(tp, bp, XFS_BLFT_SB_BUF);
if (whole)
xfs_trans_log_buf(tp, bp, 0, sizeof(xfs_dsb_t) - 1);
else
xfs_trans_log_buf(tp, bp, offsetof(xfs_dsb_t, sb_icount),
offsetof(xfs_dsb_t, sb_frextents) +
sizeof(sbp->sb_frextents) - 1);
}
STATIC int
xfs_sb_mod8(
uint8_t *field,
int8_t delta)
{
int8_t counter = *field;
counter += delta;
if (counter < 0) {
ASSERT(0);
return -EINVAL;
}
*field = counter;
return 0;
}
STATIC int
xfs_sb_mod32(
uint32_t *field,
int32_t delta)
{
int32_t counter = *field;
counter += delta;
if (counter < 0) {
ASSERT(0);
return -EINVAL;
}
*field = counter;
return 0;
}
STATIC int
xfs_sb_mod64(
uint64_t *field,
int64_t delta)
{
int64_t counter = *field;
counter += delta;
if (counter < 0) {
ASSERT(0);
return -EINVAL;
}
*field = counter;
return 0;
}
void
xfs_trans_unreserve_and_mod_sb(
struct xfs_trans *tp)
{
struct xfs_mount *mp = tp->t_mountp;
bool rsvd = (tp->t_flags & XFS_TRANS_RESERVE) != 0;
int64_t blkdelta = 0;
int64_t rtxdelta = 0;
int64_t idelta = 0;
int64_t ifreedelta = 0;
int error;
if (tp->t_blk_res > 0)
blkdelta = tp->t_blk_res;
if ((tp->t_fdblocks_delta != 0) &&
(xfs_sb_version_haslazysbcount(&mp->m_sb) ||
(tp->t_flags & XFS_TRANS_SB_DIRTY)))
blkdelta += tp->t_fdblocks_delta;
if (tp->t_rtx_res > 0)
rtxdelta = tp->t_rtx_res;
if ((tp->t_frextents_delta != 0) &&
(tp->t_flags & XFS_TRANS_SB_DIRTY))
rtxdelta += tp->t_frextents_delta;
if (xfs_sb_version_haslazysbcount(&mp->m_sb) ||
(tp->t_flags & XFS_TRANS_SB_DIRTY)) {
idelta = tp->t_icount_delta;
ifreedelta = tp->t_ifree_delta;
}
if (blkdelta) {
error = xfs_mod_fdblocks(mp, blkdelta, rsvd);
if (error)
goto out;
}
if (idelta) {
error = xfs_mod_icount(mp, idelta);
if (error)
goto out_undo_fdblocks;
}
if (ifreedelta) {
error = xfs_mod_ifree(mp, ifreedelta);
if (error)
goto out_undo_icount;
}
if (rtxdelta == 0 && !(tp->t_flags & XFS_TRANS_SB_DIRTY))
return;
spin_lock(&mp->m_sb_lock);
if (rtxdelta) {
error = xfs_sb_mod64(&mp->m_sb.sb_frextents, rtxdelta);
if (error)
goto out_undo_ifree;
}
if (tp->t_dblocks_delta != 0) {
error = xfs_sb_mod64(&mp->m_sb.sb_dblocks, tp->t_dblocks_delta);
if (error)
goto out_undo_frextents;
}
if (tp->t_agcount_delta != 0) {
error = xfs_sb_mod32(&mp->m_sb.sb_agcount, tp->t_agcount_delta);
if (error)
goto out_undo_dblocks;
}
if (tp->t_imaxpct_delta != 0) {
error = xfs_sb_mod8(&mp->m_sb.sb_imax_pct, tp->t_imaxpct_delta);
if (error)
goto out_undo_agcount;
}
if (tp->t_rextsize_delta != 0) {
error = xfs_sb_mod32(&mp->m_sb.sb_rextsize,
tp->t_rextsize_delta);
if (error)
goto out_undo_imaxpct;
}
if (tp->t_rbmblocks_delta != 0) {
error = xfs_sb_mod32(&mp->m_sb.sb_rbmblocks,
tp->t_rbmblocks_delta);
if (error)
goto out_undo_rextsize;
}
if (tp->t_rblocks_delta != 0) {
error = xfs_sb_mod64(&mp->m_sb.sb_rblocks, tp->t_rblocks_delta);
if (error)
goto out_undo_rbmblocks;
}
if (tp->t_rextents_delta != 0) {
error = xfs_sb_mod64(&mp->m_sb.sb_rextents,
tp->t_rextents_delta);
if (error)
goto out_undo_rblocks;
}
if (tp->t_rextslog_delta != 0) {
error = xfs_sb_mod8(&mp->m_sb.sb_rextslog,
tp->t_rextslog_delta);
if (error)
goto out_undo_rextents;
}
spin_unlock(&mp->m_sb_lock);
return;
out_undo_rextents:
if (tp->t_rextents_delta)
xfs_sb_mod64(&mp->m_sb.sb_rextents, -tp->t_rextents_delta);
out_undo_rblocks:
if (tp->t_rblocks_delta)
xfs_sb_mod64(&mp->m_sb.sb_rblocks, -tp->t_rblocks_delta);
out_undo_rbmblocks:
if (tp->t_rbmblocks_delta)
xfs_sb_mod32(&mp->m_sb.sb_rbmblocks, -tp->t_rbmblocks_delta);
out_undo_rextsize:
if (tp->t_rextsize_delta)
xfs_sb_mod32(&mp->m_sb.sb_rextsize, -tp->t_rextsize_delta);
out_undo_imaxpct:
if (tp->t_rextsize_delta)
xfs_sb_mod8(&mp->m_sb.sb_imax_pct, -tp->t_imaxpct_delta);
out_undo_agcount:
if (tp->t_agcount_delta)
xfs_sb_mod32(&mp->m_sb.sb_agcount, -tp->t_agcount_delta);
out_undo_dblocks:
if (tp->t_dblocks_delta)
xfs_sb_mod64(&mp->m_sb.sb_dblocks, -tp->t_dblocks_delta);
out_undo_frextents:
if (rtxdelta)
xfs_sb_mod64(&mp->m_sb.sb_frextents, -rtxdelta);
out_undo_ifree:
spin_unlock(&mp->m_sb_lock);
if (ifreedelta)
xfs_mod_ifree(mp, -ifreedelta);
out_undo_icount:
if (idelta)
xfs_mod_icount(mp, -idelta);
out_undo_fdblocks:
if (blkdelta)
xfs_mod_fdblocks(mp, -blkdelta, rsvd);
out:
ASSERT(error == 0);
return;
}
void
xfs_trans_add_item(
struct xfs_trans *tp,
struct xfs_log_item *lip)
{
struct xfs_log_item_desc *lidp;
ASSERT(lip->li_mountp == tp->t_mountp);
ASSERT(lip->li_ailp == tp->t_mountp->m_ail);
lidp = kmem_zone_zalloc(xfs_log_item_desc_zone, KM_SLEEP | KM_NOFS);
lidp->lid_item = lip;
lidp->lid_flags = 0;
list_add_tail(&lidp->lid_trans, &tp->t_items);
lip->li_desc = lidp;
}
STATIC void
xfs_trans_free_item_desc(
struct xfs_log_item_desc *lidp)
{
list_del_init(&lidp->lid_trans);
kmem_zone_free(xfs_log_item_desc_zone, lidp);
}
void
xfs_trans_del_item(
struct xfs_log_item *lip)
{
xfs_trans_free_item_desc(lip->li_desc);
lip->li_desc = NULL;
}
void
xfs_trans_free_items(
struct xfs_trans *tp,
xfs_lsn_t commit_lsn,
bool abort)
{
struct xfs_log_item_desc *lidp, *next;
list_for_each_entry_safe(lidp, next, &tp->t_items, lid_trans) {
struct xfs_log_item *lip = lidp->lid_item;
lip->li_desc = NULL;
if (commit_lsn != NULLCOMMITLSN)
lip->li_ops->iop_committing(lip, commit_lsn);
if (abort)
lip->li_flags |= XFS_LI_ABORTED;
lip->li_ops->iop_unlock(lip);
xfs_trans_free_item_desc(lidp);
}
}
static inline void
xfs_log_item_batch_insert(
struct xfs_ail *ailp,
struct xfs_ail_cursor *cur,
struct xfs_log_item **log_items,
int nr_items,
xfs_lsn_t commit_lsn)
{
int i;
spin_lock(&ailp->xa_lock);
xfs_trans_ail_update_bulk(ailp, cur, log_items, nr_items, commit_lsn);
for (i = 0; i < nr_items; i++) {
struct xfs_log_item *lip = log_items[i];
lip->li_ops->iop_unpin(lip, 0);
}
}
void
xfs_trans_committed_bulk(
struct xfs_ail *ailp,
struct xfs_log_vec *log_vector,
xfs_lsn_t commit_lsn,
int aborted)
{
#define LOG_ITEM_BATCH_SIZE 32
struct xfs_log_item *log_items[LOG_ITEM_BATCH_SIZE];
struct xfs_log_vec *lv;
struct xfs_ail_cursor cur;
int i = 0;
spin_lock(&ailp->xa_lock);
xfs_trans_ail_cursor_last(ailp, &cur, commit_lsn);
spin_unlock(&ailp->xa_lock);
for (lv = log_vector; lv; lv = lv->lv_next ) {
struct xfs_log_item *lip = lv->lv_item;
xfs_lsn_t item_lsn;
if (aborted)
lip->li_flags |= XFS_LI_ABORTED;
item_lsn = lip->li_ops->iop_committed(lip, commit_lsn);
if (XFS_LSN_CMP(item_lsn, (xfs_lsn_t)-1) == 0)
continue;
if (aborted) {
ASSERT(XFS_FORCED_SHUTDOWN(ailp->xa_mount));
lip->li_ops->iop_unpin(lip, 1);
continue;
}
if (item_lsn != commit_lsn) {
spin_lock(&ailp->xa_lock);
if (XFS_LSN_CMP(item_lsn, lip->li_lsn) > 0)
xfs_trans_ail_update(ailp, lip, item_lsn);
else
spin_unlock(&ailp->xa_lock);
lip->li_ops->iop_unpin(lip, 0);
continue;
}
log_items[i++] = lv->lv_item;
if (i >= LOG_ITEM_BATCH_SIZE) {
xfs_log_item_batch_insert(ailp, &cur, log_items,
LOG_ITEM_BATCH_SIZE, commit_lsn);
i = 0;
}
}
if (i)
xfs_log_item_batch_insert(ailp, &cur, log_items, i, commit_lsn);
spin_lock(&ailp->xa_lock);
xfs_trans_ail_cursor_done(&cur);
spin_unlock(&ailp->xa_lock);
}
static int
__xfs_trans_commit(
struct xfs_trans *tp,
bool regrant)
{
struct xfs_mount *mp = tp->t_mountp;
xfs_lsn_t commit_lsn = -1;
int error = 0;
int sync = tp->t_flags & XFS_TRANS_SYNC;
if (!(tp->t_flags & XFS_TRANS_DIRTY))
goto out_unreserve;
if (XFS_FORCED_SHUTDOWN(mp)) {
error = -EIO;
goto out_unreserve;
}
ASSERT(tp->t_ticket != NULL);
if (tp->t_flags & XFS_TRANS_SB_DIRTY)
xfs_trans_apply_sb_deltas(tp);
xfs_trans_apply_dquot_deltas(tp);
xfs_log_commit_cil(mp, tp, &commit_lsn, regrant);
current_restore_flags_nested(&tp->t_pflags, PF_FSTRANS);
xfs_trans_free(tp);
if (sync) {
error = _xfs_log_force_lsn(mp, commit_lsn, XFS_LOG_SYNC, NULL);
XFS_STATS_INC(xs_trans_sync);
} else {
XFS_STATS_INC(xs_trans_async);
}
return error;
out_unreserve:
xfs_trans_unreserve_and_mod_sb(tp);
xfs_trans_unreserve_and_mod_dquots(tp);
if (tp->t_ticket) {
commit_lsn = xfs_log_done(mp, tp->t_ticket, NULL, regrant);
if (commit_lsn == -1 && !error)
error = -EIO;
}
current_restore_flags_nested(&tp->t_pflags, PF_FSTRANS);
xfs_trans_free_items(tp, NULLCOMMITLSN, !!error);
xfs_trans_free(tp);
XFS_STATS_INC(xs_trans_empty);
return error;
}
int
xfs_trans_commit(
struct xfs_trans *tp)
{
return __xfs_trans_commit(tp, false);
}
void
xfs_trans_cancel(
struct xfs_trans *tp)
{
struct xfs_mount *mp = tp->t_mountp;
bool dirty = (tp->t_flags & XFS_TRANS_DIRTY);
if (dirty && !XFS_FORCED_SHUTDOWN(mp)) {
XFS_ERROR_REPORT("xfs_trans_cancel", XFS_ERRLEVEL_LOW, mp);
xfs_force_shutdown(mp, SHUTDOWN_CORRUPT_INCORE);
}
#ifdef DEBUG
if (!dirty && !XFS_FORCED_SHUTDOWN(mp)) {
struct xfs_log_item_desc *lidp;
list_for_each_entry(lidp, &tp->t_items, lid_trans)
ASSERT(!(lidp->lid_item->li_type == XFS_LI_EFD));
}
#endif
xfs_trans_unreserve_and_mod_sb(tp);
xfs_trans_unreserve_and_mod_dquots(tp);
if (tp->t_ticket)
xfs_log_done(mp, tp->t_ticket, NULL, false);
current_restore_flags_nested(&tp->t_pflags, PF_FSTRANS);
xfs_trans_free_items(tp, NULLCOMMITLSN, dirty);
xfs_trans_free(tp);
}
int
xfs_trans_roll(
struct xfs_trans **tpp,
struct xfs_inode *dp)
{
struct xfs_trans *trans;
struct xfs_trans_res tres;
int error;
trans = *tpp;
if (dp)
xfs_trans_log_inode(trans, dp, XFS_ILOG_CORE);
tres.tr_logres = trans->t_log_res;
tres.tr_logcount = trans->t_log_count;
*tpp = xfs_trans_dup(trans);
error = __xfs_trans_commit(trans, true);
if (error)
return error;
trans = *tpp;
tres.tr_logflags = XFS_TRANS_PERM_LOG_RES;
error = xfs_trans_reserve(trans, &tres, 0, 0);
if (error)
return error;
if (dp)
xfs_trans_ijoin(trans, dp, 0);
return 0;
}
