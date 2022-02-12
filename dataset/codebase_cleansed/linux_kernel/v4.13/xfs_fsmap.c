void
xfs_fsmap_from_internal(
struct fsmap *dest,
struct xfs_fsmap *src)
{
dest->fmr_device = src->fmr_device;
dest->fmr_flags = src->fmr_flags;
dest->fmr_physical = BBTOB(src->fmr_physical);
dest->fmr_owner = src->fmr_owner;
dest->fmr_offset = BBTOB(src->fmr_offset);
dest->fmr_length = BBTOB(src->fmr_length);
dest->fmr_reserved[0] = 0;
dest->fmr_reserved[1] = 0;
dest->fmr_reserved[2] = 0;
}
void
xfs_fsmap_to_internal(
struct xfs_fsmap *dest,
struct fsmap *src)
{
dest->fmr_device = src->fmr_device;
dest->fmr_flags = src->fmr_flags;
dest->fmr_physical = BTOBBT(src->fmr_physical);
dest->fmr_owner = src->fmr_owner;
dest->fmr_offset = BTOBBT(src->fmr_offset);
dest->fmr_length = BTOBBT(src->fmr_length);
}
static int
xfs_fsmap_owner_to_rmap(
struct xfs_rmap_irec *dest,
struct xfs_fsmap *src)
{
if (!(src->fmr_flags & FMR_OF_SPECIAL_OWNER)) {
dest->rm_owner = src->fmr_owner;
return 0;
}
switch (src->fmr_owner) {
case 0:
case -1ULL:
dest->rm_owner = 0;
break;
case XFS_FMR_OWN_FREE:
dest->rm_owner = XFS_RMAP_OWN_NULL;
break;
case XFS_FMR_OWN_UNKNOWN:
dest->rm_owner = XFS_RMAP_OWN_UNKNOWN;
break;
case XFS_FMR_OWN_FS:
dest->rm_owner = XFS_RMAP_OWN_FS;
break;
case XFS_FMR_OWN_LOG:
dest->rm_owner = XFS_RMAP_OWN_LOG;
break;
case XFS_FMR_OWN_AG:
dest->rm_owner = XFS_RMAP_OWN_AG;
break;
case XFS_FMR_OWN_INOBT:
dest->rm_owner = XFS_RMAP_OWN_INOBT;
break;
case XFS_FMR_OWN_INODES:
dest->rm_owner = XFS_RMAP_OWN_INODES;
break;
case XFS_FMR_OWN_REFC:
dest->rm_owner = XFS_RMAP_OWN_REFC;
break;
case XFS_FMR_OWN_COW:
dest->rm_owner = XFS_RMAP_OWN_COW;
break;
case XFS_FMR_OWN_DEFECTIVE:
default:
return -EINVAL;
}
return 0;
}
static int
xfs_fsmap_owner_from_rmap(
struct xfs_fsmap *dest,
struct xfs_rmap_irec *src)
{
dest->fmr_flags = 0;
if (!XFS_RMAP_NON_INODE_OWNER(src->rm_owner)) {
dest->fmr_owner = src->rm_owner;
return 0;
}
dest->fmr_flags |= FMR_OF_SPECIAL_OWNER;
switch (src->rm_owner) {
case XFS_RMAP_OWN_FS:
dest->fmr_owner = XFS_FMR_OWN_FS;
break;
case XFS_RMAP_OWN_LOG:
dest->fmr_owner = XFS_FMR_OWN_LOG;
break;
case XFS_RMAP_OWN_AG:
dest->fmr_owner = XFS_FMR_OWN_AG;
break;
case XFS_RMAP_OWN_INOBT:
dest->fmr_owner = XFS_FMR_OWN_INOBT;
break;
case XFS_RMAP_OWN_INODES:
dest->fmr_owner = XFS_FMR_OWN_INODES;
break;
case XFS_RMAP_OWN_REFC:
dest->fmr_owner = XFS_FMR_OWN_REFC;
break;
case XFS_RMAP_OWN_COW:
dest->fmr_owner = XFS_FMR_OWN_COW;
break;
case XFS_RMAP_OWN_NULL:
dest->fmr_owner = XFS_FMR_OWN_FREE;
break;
default:
return -EFSCORRUPTED;
}
return 0;
}
static int
xfs_getfsmap_dev_compare(
const void *p1,
const void *p2)
{
const struct xfs_getfsmap_dev *d1 = p1;
const struct xfs_getfsmap_dev *d2 = p2;
return d1->dev - d2->dev;
}
STATIC int
xfs_getfsmap_is_shared(
struct xfs_trans *tp,
struct xfs_getfsmap_info *info,
struct xfs_rmap_irec *rec,
bool *stat)
{
struct xfs_mount *mp = tp->t_mountp;
struct xfs_btree_cur *cur;
xfs_agblock_t fbno;
xfs_extlen_t flen;
int error;
*stat = false;
if (!xfs_sb_version_hasreflink(&mp->m_sb))
return 0;
if (info->agno == NULLAGNUMBER)
return 0;
flen = 0;
cur = xfs_refcountbt_init_cursor(mp, tp, info->agf_bp,
info->agno, NULL);
error = xfs_refcount_find_shared(cur, rec->rm_startblock,
rec->rm_blockcount, &fbno, &flen, false);
xfs_btree_del_cursor(cur, error ? XFS_BTREE_ERROR : XFS_BTREE_NOERROR);
if (error)
return error;
*stat = flen > 0;
return 0;
}
STATIC int
xfs_getfsmap_helper(
struct xfs_trans *tp,
struct xfs_getfsmap_info *info,
struct xfs_rmap_irec *rec,
xfs_daddr_t rec_daddr)
{
struct xfs_fsmap fmr;
struct xfs_mount *mp = tp->t_mountp;
bool shared;
int error;
if (fatal_signal_pending(current))
return -EINTR;
if (xfs_rmap_compare(rec, &info->low) < 0) {
rec_daddr += XFS_FSB_TO_BB(mp, rec->rm_blockcount);
if (info->next_daddr < rec_daddr)
info->next_daddr = rec_daddr;
return XFS_BTREE_QUERY_RANGE_CONTINUE;
}
if (info->head->fmh_count == 0) {
if (rec_daddr > info->next_daddr)
info->head->fmh_entries++;
if (info->last)
return XFS_BTREE_QUERY_RANGE_CONTINUE;
info->head->fmh_entries++;
rec_daddr += XFS_FSB_TO_BB(mp, rec->rm_blockcount);
if (info->next_daddr < rec_daddr)
info->next_daddr = rec_daddr;
return XFS_BTREE_QUERY_RANGE_CONTINUE;
}
if (rec_daddr > info->next_daddr) {
if (info->head->fmh_entries >= info->head->fmh_count)
return XFS_BTREE_QUERY_RANGE_ABORT;
fmr.fmr_device = info->dev;
fmr.fmr_physical = info->next_daddr;
fmr.fmr_owner = info->missing_owner;
fmr.fmr_offset = 0;
fmr.fmr_length = rec_daddr - info->next_daddr;
fmr.fmr_flags = FMR_OF_SPECIAL_OWNER;
error = info->formatter(&fmr, info->format_arg);
if (error)
return error;
info->head->fmh_entries++;
}
if (info->last)
goto out;
if (info->head->fmh_entries >= info->head->fmh_count)
return XFS_BTREE_QUERY_RANGE_ABORT;
trace_xfs_fsmap_mapping(mp, info->dev, info->agno, rec);
fmr.fmr_device = info->dev;
fmr.fmr_physical = rec_daddr;
error = xfs_fsmap_owner_from_rmap(&fmr, rec);
if (error)
return error;
fmr.fmr_offset = XFS_FSB_TO_BB(mp, rec->rm_offset);
fmr.fmr_length = XFS_FSB_TO_BB(mp, rec->rm_blockcount);
if (rec->rm_flags & XFS_RMAP_UNWRITTEN)
fmr.fmr_flags |= FMR_OF_PREALLOC;
if (rec->rm_flags & XFS_RMAP_ATTR_FORK)
fmr.fmr_flags |= FMR_OF_ATTR_FORK;
if (rec->rm_flags & XFS_RMAP_BMBT_BLOCK)
fmr.fmr_flags |= FMR_OF_EXTENT_MAP;
if (fmr.fmr_flags == 0) {
error = xfs_getfsmap_is_shared(tp, info, rec, &shared);
if (error)
return error;
if (shared)
fmr.fmr_flags |= FMR_OF_SHARED;
}
error = info->formatter(&fmr, info->format_arg);
if (error)
return error;
info->head->fmh_entries++;
out:
rec_daddr += XFS_FSB_TO_BB(mp, rec->rm_blockcount);
if (info->next_daddr < rec_daddr)
info->next_daddr = rec_daddr;
return XFS_BTREE_QUERY_RANGE_CONTINUE;
}
STATIC int
xfs_getfsmap_datadev_helper(
struct xfs_btree_cur *cur,
struct xfs_rmap_irec *rec,
void *priv)
{
struct xfs_mount *mp = cur->bc_mp;
struct xfs_getfsmap_info *info = priv;
xfs_fsblock_t fsb;
xfs_daddr_t rec_daddr;
fsb = XFS_AGB_TO_FSB(mp, cur->bc_private.a.agno, rec->rm_startblock);
rec_daddr = XFS_FSB_TO_DADDR(mp, fsb);
return xfs_getfsmap_helper(cur->bc_tp, info, rec, rec_daddr);
}
STATIC int
xfs_getfsmap_rtdev_rtbitmap_helper(
struct xfs_trans *tp,
struct xfs_rtalloc_rec *rec,
void *priv)
{
struct xfs_mount *mp = tp->t_mountp;
struct xfs_getfsmap_info *info = priv;
struct xfs_rmap_irec irec;
xfs_daddr_t rec_daddr;
rec_daddr = XFS_FSB_TO_BB(mp, rec->ar_startblock);
irec.rm_startblock = rec->ar_startblock;
irec.rm_blockcount = rec->ar_blockcount;
irec.rm_owner = XFS_RMAP_OWN_NULL;
irec.rm_offset = 0;
irec.rm_flags = 0;
return xfs_getfsmap_helper(tp, info, &irec, rec_daddr);
}
STATIC int
xfs_getfsmap_datadev_bnobt_helper(
struct xfs_btree_cur *cur,
struct xfs_alloc_rec_incore *rec,
void *priv)
{
struct xfs_mount *mp = cur->bc_mp;
struct xfs_getfsmap_info *info = priv;
struct xfs_rmap_irec irec;
xfs_daddr_t rec_daddr;
rec_daddr = XFS_AGB_TO_DADDR(mp, cur->bc_private.a.agno,
rec->ar_startblock);
irec.rm_startblock = rec->ar_startblock;
irec.rm_blockcount = rec->ar_blockcount;
irec.rm_owner = XFS_RMAP_OWN_NULL;
irec.rm_offset = 0;
irec.rm_flags = 0;
return xfs_getfsmap_helper(cur->bc_tp, info, &irec, rec_daddr);
}
static void
xfs_getfsmap_set_irec_flags(
struct xfs_rmap_irec *irec,
struct xfs_fsmap *fmr)
{
irec->rm_flags = 0;
if (fmr->fmr_flags & FMR_OF_ATTR_FORK)
irec->rm_flags |= XFS_RMAP_ATTR_FORK;
if (fmr->fmr_flags & FMR_OF_EXTENT_MAP)
irec->rm_flags |= XFS_RMAP_BMBT_BLOCK;
if (fmr->fmr_flags & FMR_OF_PREALLOC)
irec->rm_flags |= XFS_RMAP_UNWRITTEN;
}
STATIC int
xfs_getfsmap_logdev(
struct xfs_trans *tp,
struct xfs_fsmap *keys,
struct xfs_getfsmap_info *info)
{
struct xfs_mount *mp = tp->t_mountp;
struct xfs_rmap_irec rmap;
int error;
info->low.rm_startblock = XFS_BB_TO_FSBT(mp, keys[0].fmr_physical);
info->low.rm_offset = XFS_BB_TO_FSBT(mp, keys[0].fmr_offset);
error = xfs_fsmap_owner_to_rmap(&info->low, keys);
if (error)
return error;
info->low.rm_blockcount = 0;
xfs_getfsmap_set_irec_flags(&info->low, &keys[0]);
error = xfs_fsmap_owner_to_rmap(&info->high, keys + 1);
if (error)
return error;
info->high.rm_startblock = -1U;
info->high.rm_owner = ULLONG_MAX;
info->high.rm_offset = ULLONG_MAX;
info->high.rm_blockcount = 0;
info->high.rm_flags = XFS_RMAP_KEY_FLAGS | XFS_RMAP_REC_FLAGS;
info->missing_owner = XFS_FMR_OWN_FREE;
trace_xfs_fsmap_low_key(mp, info->dev, info->agno, &info->low);
trace_xfs_fsmap_high_key(mp, info->dev, info->agno, &info->high);
if (keys[0].fmr_physical > 0)
return 0;
rmap.rm_startblock = 0;
rmap.rm_blockcount = mp->m_sb.sb_logblocks;
rmap.rm_owner = XFS_RMAP_OWN_LOG;
rmap.rm_offset = 0;
rmap.rm_flags = 0;
return xfs_getfsmap_helper(tp, info, &rmap, 0);
}
STATIC int
__xfs_getfsmap_rtdev(
struct xfs_trans *tp,
struct xfs_fsmap *keys,
int (*query_fn)(struct xfs_trans *,
struct xfs_getfsmap_info *),
struct xfs_getfsmap_info *info)
{
struct xfs_mount *mp = tp->t_mountp;
xfs_fsblock_t start_fsb;
xfs_fsblock_t end_fsb;
xfs_daddr_t eofs;
int error = 0;
eofs = XFS_FSB_TO_BB(mp, mp->m_sb.sb_rblocks);
if (keys[0].fmr_physical >= eofs)
return 0;
if (keys[1].fmr_physical >= eofs)
keys[1].fmr_physical = eofs - 1;
start_fsb = XFS_BB_TO_FSBT(mp, keys[0].fmr_physical);
end_fsb = XFS_BB_TO_FSB(mp, keys[1].fmr_physical);
info->low.rm_startblock = start_fsb;
error = xfs_fsmap_owner_to_rmap(&info->low, &keys[0]);
if (error)
return error;
info->low.rm_offset = XFS_BB_TO_FSBT(mp, keys[0].fmr_offset);
info->low.rm_blockcount = 0;
xfs_getfsmap_set_irec_flags(&info->low, &keys[0]);
info->high.rm_startblock = end_fsb;
error = xfs_fsmap_owner_to_rmap(&info->high, &keys[1]);
if (error)
return error;
info->high.rm_offset = XFS_BB_TO_FSBT(mp, keys[1].fmr_offset);
info->high.rm_blockcount = 0;
xfs_getfsmap_set_irec_flags(&info->high, &keys[1]);
trace_xfs_fsmap_low_key(mp, info->dev, info->agno, &info->low);
trace_xfs_fsmap_high_key(mp, info->dev, info->agno, &info->high);
return query_fn(tp, info);
}
STATIC int
xfs_getfsmap_rtdev_rtbitmap_query(
struct xfs_trans *tp,
struct xfs_getfsmap_info *info)
{
struct xfs_rtalloc_rec alow;
struct xfs_rtalloc_rec ahigh;
int error;
xfs_ilock(tp->t_mountp->m_rbmip, XFS_ILOCK_SHARED);
alow.ar_startblock = info->low.rm_startblock;
ahigh.ar_startblock = info->high.rm_startblock;
error = xfs_rtalloc_query_range(tp, &alow, &ahigh,
xfs_getfsmap_rtdev_rtbitmap_helper, info);
if (error)
goto err;
info->last = true;
error = xfs_getfsmap_rtdev_rtbitmap_helper(tp, &ahigh, info);
if (error)
goto err;
err:
xfs_iunlock(tp->t_mountp->m_rbmip, XFS_ILOCK_SHARED);
return error;
}
STATIC int
xfs_getfsmap_rtdev_rtbitmap(
struct xfs_trans *tp,
struct xfs_fsmap *keys,
struct xfs_getfsmap_info *info)
{
info->missing_owner = XFS_FMR_OWN_UNKNOWN;
return __xfs_getfsmap_rtdev(tp, keys, xfs_getfsmap_rtdev_rtbitmap_query,
info);
}
STATIC int
__xfs_getfsmap_datadev(
struct xfs_trans *tp,
struct xfs_fsmap *keys,
struct xfs_getfsmap_info *info,
int (*query_fn)(struct xfs_trans *,
struct xfs_getfsmap_info *,
struct xfs_btree_cur **,
void *),
void *priv)
{
struct xfs_mount *mp = tp->t_mountp;
struct xfs_btree_cur *bt_cur = NULL;
xfs_fsblock_t start_fsb;
xfs_fsblock_t end_fsb;
xfs_agnumber_t start_ag;
xfs_agnumber_t end_ag;
xfs_daddr_t eofs;
int error = 0;
eofs = XFS_FSB_TO_BB(mp, mp->m_sb.sb_dblocks);
if (keys[0].fmr_physical >= eofs)
return 0;
if (keys[1].fmr_physical >= eofs)
keys[1].fmr_physical = eofs - 1;
start_fsb = XFS_DADDR_TO_FSB(mp, keys[0].fmr_physical);
end_fsb = XFS_DADDR_TO_FSB(mp, keys[1].fmr_physical);
info->low.rm_startblock = XFS_FSB_TO_AGBNO(mp, start_fsb);
info->low.rm_offset = XFS_BB_TO_FSBT(mp, keys[0].fmr_offset);
error = xfs_fsmap_owner_to_rmap(&info->low, &keys[0]);
if (error)
return error;
info->low.rm_blockcount = 0;
xfs_getfsmap_set_irec_flags(&info->low, &keys[0]);
info->high.rm_startblock = -1U;
info->high.rm_owner = ULLONG_MAX;
info->high.rm_offset = ULLONG_MAX;
info->high.rm_blockcount = 0;
info->high.rm_flags = XFS_RMAP_KEY_FLAGS | XFS_RMAP_REC_FLAGS;
start_ag = XFS_FSB_TO_AGNO(mp, start_fsb);
end_ag = XFS_FSB_TO_AGNO(mp, end_fsb);
for (info->agno = start_ag; info->agno <= end_ag; info->agno++) {
if (info->agno == end_ag) {
info->high.rm_startblock = XFS_FSB_TO_AGBNO(mp,
end_fsb);
info->high.rm_offset = XFS_BB_TO_FSBT(mp,
keys[1].fmr_offset);
error = xfs_fsmap_owner_to_rmap(&info->high, &keys[1]);
if (error)
goto err;
xfs_getfsmap_set_irec_flags(&info->high, &keys[1]);
}
if (bt_cur) {
xfs_btree_del_cursor(bt_cur, XFS_BTREE_NOERROR);
bt_cur = NULL;
xfs_trans_brelse(tp, info->agf_bp);
info->agf_bp = NULL;
}
error = xfs_alloc_read_agf(mp, tp, info->agno, 0,
&info->agf_bp);
if (error)
goto err;
trace_xfs_fsmap_low_key(mp, info->dev, info->agno, &info->low);
trace_xfs_fsmap_high_key(mp, info->dev, info->agno,
&info->high);
error = query_fn(tp, info, &bt_cur, priv);
if (error)
goto err;
if (info->agno == start_ag) {
info->low.rm_startblock = 0;
info->low.rm_owner = 0;
info->low.rm_offset = 0;
info->low.rm_flags = 0;
}
}
info->last = true;
error = query_fn(tp, info, &bt_cur, priv);
if (error)
goto err;
err:
if (bt_cur)
xfs_btree_del_cursor(bt_cur, error < 0 ? XFS_BTREE_ERROR :
XFS_BTREE_NOERROR);
if (info->agf_bp) {
xfs_trans_brelse(tp, info->agf_bp);
info->agf_bp = NULL;
}
return error;
}
STATIC int
xfs_getfsmap_datadev_rmapbt_query(
struct xfs_trans *tp,
struct xfs_getfsmap_info *info,
struct xfs_btree_cur **curpp,
void *priv)
{
if (info->last)
return xfs_getfsmap_datadev_helper(*curpp, &info->high, info);
*curpp = xfs_rmapbt_init_cursor(tp->t_mountp, tp, info->agf_bp,
info->agno);
return xfs_rmap_query_range(*curpp, &info->low, &info->high,
xfs_getfsmap_datadev_helper, info);
}
STATIC int
xfs_getfsmap_datadev_rmapbt(
struct xfs_trans *tp,
struct xfs_fsmap *keys,
struct xfs_getfsmap_info *info)
{
info->missing_owner = XFS_FMR_OWN_FREE;
return __xfs_getfsmap_datadev(tp, keys, info,
xfs_getfsmap_datadev_rmapbt_query, NULL);
}
STATIC int
xfs_getfsmap_datadev_bnobt_query(
struct xfs_trans *tp,
struct xfs_getfsmap_info *info,
struct xfs_btree_cur **curpp,
void *priv)
{
struct xfs_alloc_rec_incore *key = priv;
if (info->last)
return xfs_getfsmap_datadev_bnobt_helper(*curpp, &key[1], info);
*curpp = xfs_allocbt_init_cursor(tp->t_mountp, tp, info->agf_bp,
info->agno, XFS_BTNUM_BNO);
key->ar_startblock = info->low.rm_startblock;
key[1].ar_startblock = info->high.rm_startblock;
return xfs_alloc_query_range(*curpp, key, &key[1],
xfs_getfsmap_datadev_bnobt_helper, info);
}
STATIC int
xfs_getfsmap_datadev_bnobt(
struct xfs_trans *tp,
struct xfs_fsmap *keys,
struct xfs_getfsmap_info *info)
{
struct xfs_alloc_rec_incore akeys[2];
info->missing_owner = XFS_FMR_OWN_UNKNOWN;
return __xfs_getfsmap_datadev(tp, keys, info,
xfs_getfsmap_datadev_bnobt_query, &akeys[0]);
}
STATIC bool
xfs_getfsmap_is_valid_device(
struct xfs_mount *mp,
struct xfs_fsmap *fm)
{
if (fm->fmr_device == 0 || fm->fmr_device == UINT_MAX ||
fm->fmr_device == new_encode_dev(mp->m_ddev_targp->bt_dev))
return true;
if (mp->m_logdev_targp &&
fm->fmr_device == new_encode_dev(mp->m_logdev_targp->bt_dev))
return true;
if (mp->m_rtdev_targp &&
fm->fmr_device == new_encode_dev(mp->m_rtdev_targp->bt_dev))
return true;
return false;
}
STATIC bool
xfs_getfsmap_check_keys(
struct xfs_fsmap *low_key,
struct xfs_fsmap *high_key)
{
if (low_key->fmr_device > high_key->fmr_device)
return false;
if (low_key->fmr_device < high_key->fmr_device)
return true;
if (low_key->fmr_physical > high_key->fmr_physical)
return false;
if (low_key->fmr_physical < high_key->fmr_physical)
return true;
if (low_key->fmr_owner > high_key->fmr_owner)
return false;
if (low_key->fmr_owner < high_key->fmr_owner)
return true;
if (low_key->fmr_offset > high_key->fmr_offset)
return false;
if (low_key->fmr_offset < high_key->fmr_offset)
return true;
return false;
}
int
xfs_getfsmap(
struct xfs_mount *mp,
struct xfs_fsmap_head *head,
xfs_fsmap_format_t formatter,
void *arg)
{
struct xfs_trans *tp = NULL;
struct xfs_fsmap dkeys[2];
struct xfs_getfsmap_dev handlers[XFS_GETFSMAP_DEVS];
struct xfs_getfsmap_info info = { NULL };
bool use_rmap;
int i;
int error = 0;
if (head->fmh_iflags & ~FMH_IF_VALID)
return -EINVAL;
if (!xfs_getfsmap_is_valid_device(mp, &head->fmh_keys[0]) ||
!xfs_getfsmap_is_valid_device(mp, &head->fmh_keys[1]))
return -EINVAL;
use_rmap = capable(CAP_SYS_ADMIN) &&
xfs_sb_version_hasrmapbt(&mp->m_sb);
head->fmh_entries = 0;
memset(handlers, 0, sizeof(handlers));
handlers[0].dev = new_encode_dev(mp->m_ddev_targp->bt_dev);
if (use_rmap)
handlers[0].fn = xfs_getfsmap_datadev_rmapbt;
else
handlers[0].fn = xfs_getfsmap_datadev_bnobt;
if (mp->m_logdev_targp != mp->m_ddev_targp) {
handlers[1].dev = new_encode_dev(mp->m_logdev_targp->bt_dev);
handlers[1].fn = xfs_getfsmap_logdev;
}
if (mp->m_rtdev_targp) {
handlers[2].dev = new_encode_dev(mp->m_rtdev_targp->bt_dev);
handlers[2].fn = xfs_getfsmap_rtdev_rtbitmap;
}
xfs_sort(handlers, XFS_GETFSMAP_DEVS, sizeof(struct xfs_getfsmap_dev),
xfs_getfsmap_dev_compare);
dkeys[0] = head->fmh_keys[0];
if (dkeys[0].fmr_flags & (FMR_OF_SPECIAL_OWNER | FMR_OF_EXTENT_MAP)) {
dkeys[0].fmr_physical += dkeys[0].fmr_length;
dkeys[0].fmr_owner = 0;
if (dkeys[0].fmr_offset)
return -EINVAL;
} else
dkeys[0].fmr_offset += dkeys[0].fmr_length;
dkeys[0].fmr_length = 0;
memset(&dkeys[1], 0xFF, sizeof(struct xfs_fsmap));
if (!xfs_getfsmap_check_keys(dkeys, &head->fmh_keys[1]))
return -EINVAL;
info.next_daddr = head->fmh_keys[0].fmr_physical +
head->fmh_keys[0].fmr_length;
info.formatter = formatter;
info.format_arg = arg;
info.head = head;
for (i = 0; i < XFS_GETFSMAP_DEVS; i++) {
if (!handlers[i].fn)
continue;
if (head->fmh_keys[0].fmr_device > handlers[i].dev)
continue;
if (head->fmh_keys[1].fmr_device < handlers[i].dev)
break;
if (handlers[i].dev == head->fmh_keys[1].fmr_device)
dkeys[1] = head->fmh_keys[1];
if (handlers[i].dev > head->fmh_keys[0].fmr_device)
memset(&dkeys[0], 0, sizeof(struct xfs_fsmap));
error = xfs_trans_alloc_empty(mp, &tp);
if (error)
break;
info.dev = handlers[i].dev;
info.last = false;
info.agno = NULLAGNUMBER;
error = handlers[i].fn(tp, dkeys, &info);
if (error)
break;
xfs_trans_cancel(tp);
tp = NULL;
info.next_daddr = 0;
}
if (tp)
xfs_trans_cancel(tp);
head->fmh_oflags = FMH_OF_DEV_T;
return error;
}
