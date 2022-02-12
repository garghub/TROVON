int
xfs_refcount_lookup_le(
struct xfs_btree_cur *cur,
xfs_agblock_t bno,
int *stat)
{
trace_xfs_refcount_lookup(cur->bc_mp, cur->bc_private.a.agno, bno,
XFS_LOOKUP_LE);
cur->bc_rec.rc.rc_startblock = bno;
cur->bc_rec.rc.rc_blockcount = 0;
return xfs_btree_lookup(cur, XFS_LOOKUP_LE, stat);
}
int
xfs_refcount_lookup_ge(
struct xfs_btree_cur *cur,
xfs_agblock_t bno,
int *stat)
{
trace_xfs_refcount_lookup(cur->bc_mp, cur->bc_private.a.agno, bno,
XFS_LOOKUP_GE);
cur->bc_rec.rc.rc_startblock = bno;
cur->bc_rec.rc.rc_blockcount = 0;
return xfs_btree_lookup(cur, XFS_LOOKUP_GE, stat);
}
static inline void
xfs_refcount_btrec_to_irec(
union xfs_btree_rec *rec,
struct xfs_refcount_irec *irec)
{
irec->rc_startblock = be32_to_cpu(rec->refc.rc_startblock);
irec->rc_blockcount = be32_to_cpu(rec->refc.rc_blockcount);
irec->rc_refcount = be32_to_cpu(rec->refc.rc_refcount);
}
int
xfs_refcount_get_rec(
struct xfs_btree_cur *cur,
struct xfs_refcount_irec *irec,
int *stat)
{
union xfs_btree_rec *rec;
int error;
error = xfs_btree_get_rec(cur, &rec, stat);
if (!error && *stat == 1) {
xfs_refcount_btrec_to_irec(rec, irec);
trace_xfs_refcount_get(cur->bc_mp, cur->bc_private.a.agno,
irec);
}
return error;
}
STATIC int
xfs_refcount_update(
struct xfs_btree_cur *cur,
struct xfs_refcount_irec *irec)
{
union xfs_btree_rec rec;
int error;
trace_xfs_refcount_update(cur->bc_mp, cur->bc_private.a.agno, irec);
rec.refc.rc_startblock = cpu_to_be32(irec->rc_startblock);
rec.refc.rc_blockcount = cpu_to_be32(irec->rc_blockcount);
rec.refc.rc_refcount = cpu_to_be32(irec->rc_refcount);
error = xfs_btree_update(cur, &rec);
if (error)
trace_xfs_refcount_update_error(cur->bc_mp,
cur->bc_private.a.agno, error, _RET_IP_);
return error;
}
STATIC int
xfs_refcount_insert(
struct xfs_btree_cur *cur,
struct xfs_refcount_irec *irec,
int *i)
{
int error;
trace_xfs_refcount_insert(cur->bc_mp, cur->bc_private.a.agno, irec);
cur->bc_rec.rc.rc_startblock = irec->rc_startblock;
cur->bc_rec.rc.rc_blockcount = irec->rc_blockcount;
cur->bc_rec.rc.rc_refcount = irec->rc_refcount;
error = xfs_btree_insert(cur, i);
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp, *i == 1, out_error);
out_error:
if (error)
trace_xfs_refcount_insert_error(cur->bc_mp,
cur->bc_private.a.agno, error, _RET_IP_);
return error;
}
STATIC int
xfs_refcount_delete(
struct xfs_btree_cur *cur,
int *i)
{
struct xfs_refcount_irec irec;
int found_rec;
int error;
error = xfs_refcount_get_rec(cur, &irec, &found_rec);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp, found_rec == 1, out_error);
trace_xfs_refcount_delete(cur->bc_mp, cur->bc_private.a.agno, &irec);
error = xfs_btree_delete(cur, i);
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp, *i == 1, out_error);
if (error)
goto out_error;
error = xfs_refcount_lookup_ge(cur, irec.rc_startblock, &found_rec);
out_error:
if (error)
trace_xfs_refcount_delete_error(cur->bc_mp,
cur->bc_private.a.agno, error, _RET_IP_);
return error;
}
static inline xfs_agblock_t
xfs_refc_next(
struct xfs_refcount_irec *rc)
{
return rc->rc_startblock + rc->rc_blockcount;
}
STATIC int
xfs_refcount_split_extent(
struct xfs_btree_cur *cur,
xfs_agblock_t agbno,
bool *shape_changed)
{
struct xfs_refcount_irec rcext, tmp;
int found_rec;
int error;
*shape_changed = false;
error = xfs_refcount_lookup_le(cur, agbno, &found_rec);
if (error)
goto out_error;
if (!found_rec)
return 0;
error = xfs_refcount_get_rec(cur, &rcext, &found_rec);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp, found_rec == 1, out_error);
if (rcext.rc_startblock == agbno || xfs_refc_next(&rcext) <= agbno)
return 0;
*shape_changed = true;
trace_xfs_refcount_split_extent(cur->bc_mp, cur->bc_private.a.agno,
&rcext, agbno);
tmp = rcext;
tmp.rc_startblock = agbno;
tmp.rc_blockcount -= (agbno - rcext.rc_startblock);
error = xfs_refcount_update(cur, &tmp);
if (error)
goto out_error;
tmp = rcext;
tmp.rc_blockcount = agbno - rcext.rc_startblock;
error = xfs_refcount_insert(cur, &tmp, &found_rec);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp, found_rec == 1, out_error);
return error;
out_error:
trace_xfs_refcount_split_extent_error(cur->bc_mp,
cur->bc_private.a.agno, error, _RET_IP_);
return error;
}
STATIC int
xfs_refcount_merge_center_extents(
struct xfs_btree_cur *cur,
struct xfs_refcount_irec *left,
struct xfs_refcount_irec *center,
struct xfs_refcount_irec *right,
unsigned long long extlen,
xfs_agblock_t *agbno,
xfs_extlen_t *aglen)
{
int error;
int found_rec;
trace_xfs_refcount_merge_center_extents(cur->bc_mp,
cur->bc_private.a.agno, left, center, right);
error = xfs_refcount_lookup_ge(cur, center->rc_startblock,
&found_rec);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp, found_rec == 1, out_error);
error = xfs_refcount_delete(cur, &found_rec);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp, found_rec == 1, out_error);
if (center->rc_refcount > 1) {
error = xfs_refcount_delete(cur, &found_rec);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp, found_rec == 1,
out_error);
}
error = xfs_refcount_lookup_le(cur, left->rc_startblock,
&found_rec);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp, found_rec == 1, out_error);
left->rc_blockcount = extlen;
error = xfs_refcount_update(cur, left);
if (error)
goto out_error;
*aglen = 0;
return error;
out_error:
trace_xfs_refcount_merge_center_extents_error(cur->bc_mp,
cur->bc_private.a.agno, error, _RET_IP_);
return error;
}
STATIC int
xfs_refcount_merge_left_extent(
struct xfs_btree_cur *cur,
struct xfs_refcount_irec *left,
struct xfs_refcount_irec *cleft,
xfs_agblock_t *agbno,
xfs_extlen_t *aglen)
{
int error;
int found_rec;
trace_xfs_refcount_merge_left_extent(cur->bc_mp,
cur->bc_private.a.agno, left, cleft);
if (cleft->rc_refcount > 1) {
error = xfs_refcount_lookup_le(cur, cleft->rc_startblock,
&found_rec);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp, found_rec == 1,
out_error);
error = xfs_refcount_delete(cur, &found_rec);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp, found_rec == 1,
out_error);
}
error = xfs_refcount_lookup_le(cur, left->rc_startblock,
&found_rec);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp, found_rec == 1, out_error);
left->rc_blockcount += cleft->rc_blockcount;
error = xfs_refcount_update(cur, left);
if (error)
goto out_error;
*agbno += cleft->rc_blockcount;
*aglen -= cleft->rc_blockcount;
return error;
out_error:
trace_xfs_refcount_merge_left_extent_error(cur->bc_mp,
cur->bc_private.a.agno, error, _RET_IP_);
return error;
}
STATIC int
xfs_refcount_merge_right_extent(
struct xfs_btree_cur *cur,
struct xfs_refcount_irec *right,
struct xfs_refcount_irec *cright,
xfs_agblock_t *agbno,
xfs_extlen_t *aglen)
{
int error;
int found_rec;
trace_xfs_refcount_merge_right_extent(cur->bc_mp,
cur->bc_private.a.agno, cright, right);
if (cright->rc_refcount > 1) {
error = xfs_refcount_lookup_le(cur, cright->rc_startblock,
&found_rec);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp, found_rec == 1,
out_error);
error = xfs_refcount_delete(cur, &found_rec);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp, found_rec == 1,
out_error);
}
error = xfs_refcount_lookup_le(cur, right->rc_startblock,
&found_rec);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp, found_rec == 1, out_error);
right->rc_startblock -= cright->rc_blockcount;
right->rc_blockcount += cright->rc_blockcount;
error = xfs_refcount_update(cur, right);
if (error)
goto out_error;
*aglen -= cright->rc_blockcount;
return error;
out_error:
trace_xfs_refcount_merge_right_extent_error(cur->bc_mp,
cur->bc_private.a.agno, error, _RET_IP_);
return error;
}
STATIC int
xfs_refcount_find_left_extents(
struct xfs_btree_cur *cur,
struct xfs_refcount_irec *left,
struct xfs_refcount_irec *cleft,
xfs_agblock_t agbno,
xfs_extlen_t aglen,
int flags)
{
struct xfs_refcount_irec tmp;
int error;
int found_rec;
left->rc_startblock = cleft->rc_startblock = NULLAGBLOCK;
error = xfs_refcount_lookup_le(cur, agbno - 1, &found_rec);
if (error)
goto out_error;
if (!found_rec)
return 0;
error = xfs_refcount_get_rec(cur, &tmp, &found_rec);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp, found_rec == 1, out_error);
if (xfs_refc_next(&tmp) != agbno)
return 0;
if ((flags & XFS_FIND_RCEXT_SHARED) && tmp.rc_refcount < 2)
return 0;
if ((flags & XFS_FIND_RCEXT_COW) && tmp.rc_refcount > 1)
return 0;
*left = tmp;
error = xfs_btree_increment(cur, 0, &found_rec);
if (error)
goto out_error;
if (found_rec) {
error = xfs_refcount_get_rec(cur, &tmp, &found_rec);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp, found_rec == 1,
out_error);
if (tmp.rc_startblock == agbno)
*cleft = tmp;
else {
cleft->rc_startblock = agbno;
cleft->rc_blockcount = min(aglen,
tmp.rc_startblock - agbno);
cleft->rc_refcount = 1;
}
} else {
cleft->rc_startblock = agbno;
cleft->rc_blockcount = aglen;
cleft->rc_refcount = 1;
}
trace_xfs_refcount_find_left_extent(cur->bc_mp, cur->bc_private.a.agno,
left, cleft, agbno);
return error;
out_error:
trace_xfs_refcount_find_left_extent_error(cur->bc_mp,
cur->bc_private.a.agno, error, _RET_IP_);
return error;
}
STATIC int
xfs_refcount_find_right_extents(
struct xfs_btree_cur *cur,
struct xfs_refcount_irec *right,
struct xfs_refcount_irec *cright,
xfs_agblock_t agbno,
xfs_extlen_t aglen,
int flags)
{
struct xfs_refcount_irec tmp;
int error;
int found_rec;
right->rc_startblock = cright->rc_startblock = NULLAGBLOCK;
error = xfs_refcount_lookup_ge(cur, agbno + aglen, &found_rec);
if (error)
goto out_error;
if (!found_rec)
return 0;
error = xfs_refcount_get_rec(cur, &tmp, &found_rec);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp, found_rec == 1, out_error);
if (tmp.rc_startblock != agbno + aglen)
return 0;
if ((flags & XFS_FIND_RCEXT_SHARED) && tmp.rc_refcount < 2)
return 0;
if ((flags & XFS_FIND_RCEXT_COW) && tmp.rc_refcount > 1)
return 0;
*right = tmp;
error = xfs_btree_decrement(cur, 0, &found_rec);
if (error)
goto out_error;
if (found_rec) {
error = xfs_refcount_get_rec(cur, &tmp, &found_rec);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp, found_rec == 1,
out_error);
if (xfs_refc_next(&tmp) == agbno + aglen)
*cright = tmp;
else {
cright->rc_startblock = max(agbno, xfs_refc_next(&tmp));
cright->rc_blockcount = right->rc_startblock -
cright->rc_startblock;
cright->rc_refcount = 1;
}
} else {
cright->rc_startblock = agbno;
cright->rc_blockcount = aglen;
cright->rc_refcount = 1;
}
trace_xfs_refcount_find_right_extent(cur->bc_mp, cur->bc_private.a.agno,
cright, right, agbno + aglen);
return error;
out_error:
trace_xfs_refcount_find_right_extent_error(cur->bc_mp,
cur->bc_private.a.agno, error, _RET_IP_);
return error;
}
static inline bool
xfs_refc_valid(
struct xfs_refcount_irec *rc)
{
return rc->rc_startblock != NULLAGBLOCK;
}
STATIC int
xfs_refcount_merge_extents(
struct xfs_btree_cur *cur,
xfs_agblock_t *agbno,
xfs_extlen_t *aglen,
enum xfs_refc_adjust_op adjust,
int flags,
bool *shape_changed)
{
struct xfs_refcount_irec left = {0}, cleft = {0};
struct xfs_refcount_irec cright = {0}, right = {0};
int error;
unsigned long long ulen;
bool cequal;
*shape_changed = false;
error = xfs_refcount_find_left_extents(cur, &left, &cleft, *agbno,
*aglen, flags);
if (error)
return error;
error = xfs_refcount_find_right_extents(cur, &right, &cright, *agbno,
*aglen, flags);
if (error)
return error;
if (!xfs_refc_valid(&left) && !xfs_refc_valid(&right))
return 0;
cequal = (cleft.rc_startblock == cright.rc_startblock) &&
(cleft.rc_blockcount == cright.rc_blockcount);
ulen = (unsigned long long)left.rc_blockcount + cleft.rc_blockcount +
right.rc_blockcount;
if (xfs_refc_valid(&left) && xfs_refc_valid(&right) &&
xfs_refc_valid(&cleft) && xfs_refc_valid(&cright) && cequal &&
left.rc_refcount == cleft.rc_refcount + adjust &&
right.rc_refcount == cleft.rc_refcount + adjust &&
ulen < MAXREFCEXTLEN) {
*shape_changed = true;
return xfs_refcount_merge_center_extents(cur, &left, &cleft,
&right, ulen, agbno, aglen);
}
ulen = (unsigned long long)left.rc_blockcount + cleft.rc_blockcount;
if (xfs_refc_valid(&left) && xfs_refc_valid(&cleft) &&
left.rc_refcount == cleft.rc_refcount + adjust &&
ulen < MAXREFCEXTLEN) {
*shape_changed = true;
error = xfs_refcount_merge_left_extent(cur, &left, &cleft,
agbno, aglen);
if (error)
return error;
if (cequal)
return 0;
}
ulen = (unsigned long long)right.rc_blockcount + cright.rc_blockcount;
if (xfs_refc_valid(&right) && xfs_refc_valid(&cright) &&
right.rc_refcount == cright.rc_refcount + adjust &&
ulen < MAXREFCEXTLEN) {
*shape_changed = true;
return xfs_refcount_merge_right_extent(cur, &right, &cright,
agbno, aglen);
}
return error;
}
static bool
xfs_refcount_still_have_space(
struct xfs_btree_cur *cur)
{
unsigned long overhead;
overhead = cur->bc_private.a.priv.refc.shape_changes *
xfs_allocfree_log_count(cur->bc_mp, 1);
overhead *= cur->bc_mp->m_sb.sb_blocksize;
if (cur->bc_private.a.priv.refc.nr_ops > 2 &&
XFS_TEST_ERROR(false, cur->bc_mp,
XFS_ERRTAG_REFCOUNT_CONTINUE_UPDATE))
return false;
if (cur->bc_private.a.priv.refc.nr_ops == 0)
return true;
else if (overhead > cur->bc_tp->t_log_res)
return false;
return cur->bc_tp->t_log_res - overhead >
cur->bc_private.a.priv.refc.nr_ops * XFS_REFCOUNT_ITEM_OVERHEAD;
}
STATIC int
xfs_refcount_adjust_extents(
struct xfs_btree_cur *cur,
xfs_agblock_t *agbno,
xfs_extlen_t *aglen,
enum xfs_refc_adjust_op adj,
struct xfs_defer_ops *dfops,
struct xfs_owner_info *oinfo)
{
struct xfs_refcount_irec ext, tmp;
int error;
int found_rec, found_tmp;
xfs_fsblock_t fsbno;
if (*aglen == 0)
return 0;
error = xfs_refcount_lookup_ge(cur, *agbno, &found_rec);
if (error)
goto out_error;
while (*aglen > 0 && xfs_refcount_still_have_space(cur)) {
error = xfs_refcount_get_rec(cur, &ext, &found_rec);
if (error)
goto out_error;
if (!found_rec) {
ext.rc_startblock = cur->bc_mp->m_sb.sb_agblocks;
ext.rc_blockcount = 0;
ext.rc_refcount = 0;
}
if (ext.rc_startblock != *agbno) {
tmp.rc_startblock = *agbno;
tmp.rc_blockcount = min(*aglen,
ext.rc_startblock - *agbno);
tmp.rc_refcount = 1 + adj;
trace_xfs_refcount_modify_extent(cur->bc_mp,
cur->bc_private.a.agno, &tmp);
if (tmp.rc_refcount) {
error = xfs_refcount_insert(cur, &tmp,
&found_tmp);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp,
found_tmp == 1, out_error);
cur->bc_private.a.priv.refc.nr_ops++;
} else {
fsbno = XFS_AGB_TO_FSB(cur->bc_mp,
cur->bc_private.a.agno,
tmp.rc_startblock);
xfs_bmap_add_free(cur->bc_mp, dfops, fsbno,
tmp.rc_blockcount, oinfo);
}
(*agbno) += tmp.rc_blockcount;
(*aglen) -= tmp.rc_blockcount;
error = xfs_refcount_lookup_ge(cur, *agbno,
&found_rec);
if (error)
goto out_error;
}
if (*aglen == 0 || !xfs_refcount_still_have_space(cur))
break;
if (ext.rc_refcount == MAXREFCOUNT)
goto skip;
ext.rc_refcount += adj;
trace_xfs_refcount_modify_extent(cur->bc_mp,
cur->bc_private.a.agno, &ext);
if (ext.rc_refcount > 1) {
error = xfs_refcount_update(cur, &ext);
if (error)
goto out_error;
cur->bc_private.a.priv.refc.nr_ops++;
} else if (ext.rc_refcount == 1) {
error = xfs_refcount_delete(cur, &found_rec);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp,
found_rec == 1, out_error);
cur->bc_private.a.priv.refc.nr_ops++;
goto advloop;
} else {
fsbno = XFS_AGB_TO_FSB(cur->bc_mp,
cur->bc_private.a.agno,
ext.rc_startblock);
xfs_bmap_add_free(cur->bc_mp, dfops, fsbno,
ext.rc_blockcount, oinfo);
}
skip:
error = xfs_btree_increment(cur, 0, &found_rec);
if (error)
goto out_error;
advloop:
(*agbno) += ext.rc_blockcount;
(*aglen) -= ext.rc_blockcount;
}
return error;
out_error:
trace_xfs_refcount_modify_extent_error(cur->bc_mp,
cur->bc_private.a.agno, error, _RET_IP_);
return error;
}
STATIC int
xfs_refcount_adjust(
struct xfs_btree_cur *cur,
xfs_agblock_t agbno,
xfs_extlen_t aglen,
xfs_agblock_t *new_agbno,
xfs_extlen_t *new_aglen,
enum xfs_refc_adjust_op adj,
struct xfs_defer_ops *dfops,
struct xfs_owner_info *oinfo)
{
bool shape_changed;
int shape_changes = 0;
int error;
*new_agbno = agbno;
*new_aglen = aglen;
if (adj == XFS_REFCOUNT_ADJUST_INCREASE)
trace_xfs_refcount_increase(cur->bc_mp, cur->bc_private.a.agno,
agbno, aglen);
else
trace_xfs_refcount_decrease(cur->bc_mp, cur->bc_private.a.agno,
agbno, aglen);
error = xfs_refcount_split_extent(cur, agbno, &shape_changed);
if (error)
goto out_error;
if (shape_changed)
shape_changes++;
error = xfs_refcount_split_extent(cur, agbno + aglen, &shape_changed);
if (error)
goto out_error;
if (shape_changed)
shape_changes++;
error = xfs_refcount_merge_extents(cur, new_agbno, new_aglen, adj,
XFS_FIND_RCEXT_SHARED, &shape_changed);
if (error)
goto out_error;
if (shape_changed)
shape_changes++;
if (shape_changes)
cur->bc_private.a.priv.refc.shape_changes++;
error = xfs_refcount_adjust_extents(cur, new_agbno, new_aglen,
adj, dfops, oinfo);
if (error)
goto out_error;
return 0;
out_error:
trace_xfs_refcount_adjust_error(cur->bc_mp, cur->bc_private.a.agno,
error, _RET_IP_);
return error;
}
void
xfs_refcount_finish_one_cleanup(
struct xfs_trans *tp,
struct xfs_btree_cur *rcur,
int error)
{
struct xfs_buf *agbp;
if (rcur == NULL)
return;
agbp = rcur->bc_private.a.agbp;
xfs_btree_del_cursor(rcur, error ? XFS_BTREE_ERROR : XFS_BTREE_NOERROR);
if (error)
xfs_trans_brelse(tp, agbp);
}
int
xfs_refcount_finish_one(
struct xfs_trans *tp,
struct xfs_defer_ops *dfops,
enum xfs_refcount_intent_type type,
xfs_fsblock_t startblock,
xfs_extlen_t blockcount,
xfs_fsblock_t *new_fsb,
xfs_extlen_t *new_len,
struct xfs_btree_cur **pcur)
{
struct xfs_mount *mp = tp->t_mountp;
struct xfs_btree_cur *rcur;
struct xfs_buf *agbp = NULL;
int error = 0;
xfs_agnumber_t agno;
xfs_agblock_t bno;
xfs_agblock_t new_agbno;
unsigned long nr_ops = 0;
int shape_changes = 0;
agno = XFS_FSB_TO_AGNO(mp, startblock);
ASSERT(agno != NULLAGNUMBER);
bno = XFS_FSB_TO_AGBNO(mp, startblock);
trace_xfs_refcount_deferred(mp, XFS_FSB_TO_AGNO(mp, startblock),
type, XFS_FSB_TO_AGBNO(mp, startblock),
blockcount);
if (XFS_TEST_ERROR(false, mp,
XFS_ERRTAG_REFCOUNT_FINISH_ONE))
return -EIO;
rcur = *pcur;
if (rcur != NULL && rcur->bc_private.a.agno != agno) {
nr_ops = rcur->bc_private.a.priv.refc.nr_ops;
shape_changes = rcur->bc_private.a.priv.refc.shape_changes;
xfs_refcount_finish_one_cleanup(tp, rcur, 0);
rcur = NULL;
*pcur = NULL;
}
if (rcur == NULL) {
error = xfs_alloc_read_agf(tp->t_mountp, tp, agno,
XFS_ALLOC_FLAG_FREEING, &agbp);
if (error)
return error;
if (!agbp)
return -EFSCORRUPTED;
rcur = xfs_refcountbt_init_cursor(mp, tp, agbp, agno, dfops);
if (!rcur) {
error = -ENOMEM;
goto out_cur;
}
rcur->bc_private.a.priv.refc.nr_ops = nr_ops;
rcur->bc_private.a.priv.refc.shape_changes = shape_changes;
}
*pcur = rcur;
switch (type) {
case XFS_REFCOUNT_INCREASE:
error = xfs_refcount_adjust(rcur, bno, blockcount, &new_agbno,
new_len, XFS_REFCOUNT_ADJUST_INCREASE, dfops, NULL);
*new_fsb = XFS_AGB_TO_FSB(mp, agno, new_agbno);
break;
case XFS_REFCOUNT_DECREASE:
error = xfs_refcount_adjust(rcur, bno, blockcount, &new_agbno,
new_len, XFS_REFCOUNT_ADJUST_DECREASE, dfops, NULL);
*new_fsb = XFS_AGB_TO_FSB(mp, agno, new_agbno);
break;
case XFS_REFCOUNT_ALLOC_COW:
*new_fsb = startblock + blockcount;
*new_len = 0;
error = __xfs_refcount_cow_alloc(rcur, bno, blockcount, dfops);
break;
case XFS_REFCOUNT_FREE_COW:
*new_fsb = startblock + blockcount;
*new_len = 0;
error = __xfs_refcount_cow_free(rcur, bno, blockcount, dfops);
break;
default:
ASSERT(0);
error = -EFSCORRUPTED;
}
if (!error && *new_len > 0)
trace_xfs_refcount_finish_one_leftover(mp, agno, type,
bno, blockcount, new_agbno, *new_len);
return error;
out_cur:
xfs_trans_brelse(tp, agbp);
return error;
}
static int
__xfs_refcount_add(
struct xfs_mount *mp,
struct xfs_defer_ops *dfops,
enum xfs_refcount_intent_type type,
xfs_fsblock_t startblock,
xfs_extlen_t blockcount)
{
struct xfs_refcount_intent *ri;
trace_xfs_refcount_defer(mp, XFS_FSB_TO_AGNO(mp, startblock),
type, XFS_FSB_TO_AGBNO(mp, startblock),
blockcount);
ri = kmem_alloc(sizeof(struct xfs_refcount_intent),
KM_SLEEP | KM_NOFS);
INIT_LIST_HEAD(&ri->ri_list);
ri->ri_type = type;
ri->ri_startblock = startblock;
ri->ri_blockcount = blockcount;
xfs_defer_add(dfops, XFS_DEFER_OPS_TYPE_REFCOUNT, &ri->ri_list);
return 0;
}
int
xfs_refcount_increase_extent(
struct xfs_mount *mp,
struct xfs_defer_ops *dfops,
struct xfs_bmbt_irec *PREV)
{
if (!xfs_sb_version_hasreflink(&mp->m_sb))
return 0;
return __xfs_refcount_add(mp, dfops, XFS_REFCOUNT_INCREASE,
PREV->br_startblock, PREV->br_blockcount);
}
int
xfs_refcount_decrease_extent(
struct xfs_mount *mp,
struct xfs_defer_ops *dfops,
struct xfs_bmbt_irec *PREV)
{
if (!xfs_sb_version_hasreflink(&mp->m_sb))
return 0;
return __xfs_refcount_add(mp, dfops, XFS_REFCOUNT_DECREASE,
PREV->br_startblock, PREV->br_blockcount);
}
int
xfs_refcount_find_shared(
struct xfs_btree_cur *cur,
xfs_agblock_t agbno,
xfs_extlen_t aglen,
xfs_agblock_t *fbno,
xfs_extlen_t *flen,
bool find_end_of_shared)
{
struct xfs_refcount_irec tmp;
int i;
int have;
int error;
trace_xfs_refcount_find_shared(cur->bc_mp, cur->bc_private.a.agno,
agbno, aglen);
*fbno = NULLAGBLOCK;
*flen = 0;
error = xfs_refcount_lookup_le(cur, agbno, &have);
if (error)
goto out_error;
if (!have) {
error = xfs_btree_increment(cur, 0, &have);
if (error)
goto out_error;
if (!have)
goto done;
}
error = xfs_refcount_get_rec(cur, &tmp, &i);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp, i == 1, out_error);
if (tmp.rc_startblock + tmp.rc_blockcount <= agbno) {
error = xfs_btree_increment(cur, 0, &have);
if (error)
goto out_error;
if (!have)
goto done;
error = xfs_refcount_get_rec(cur, &tmp, &i);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp, i == 1, out_error);
}
if (tmp.rc_startblock >= agbno + aglen)
goto done;
if (tmp.rc_startblock < agbno) {
tmp.rc_blockcount -= (agbno - tmp.rc_startblock);
tmp.rc_startblock = agbno;
}
*fbno = tmp.rc_startblock;
*flen = min(tmp.rc_blockcount, agbno + aglen - *fbno);
if (!find_end_of_shared)
goto done;
while (*fbno + *flen < agbno + aglen) {
error = xfs_btree_increment(cur, 0, &have);
if (error)
goto out_error;
if (!have)
break;
error = xfs_refcount_get_rec(cur, &tmp, &i);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp, i == 1, out_error);
if (tmp.rc_startblock >= agbno + aglen ||
tmp.rc_startblock != *fbno + *flen)
break;
*flen = min(*flen + tmp.rc_blockcount, agbno + aglen - *fbno);
}
done:
trace_xfs_refcount_find_shared_result(cur->bc_mp,
cur->bc_private.a.agno, *fbno, *flen);
out_error:
if (error)
trace_xfs_refcount_find_shared_error(cur->bc_mp,
cur->bc_private.a.agno, error, _RET_IP_);
return error;
}
STATIC int
xfs_refcount_adjust_cow_extents(
struct xfs_btree_cur *cur,
xfs_agblock_t agbno,
xfs_extlen_t aglen,
enum xfs_refc_adjust_op adj,
struct xfs_defer_ops *dfops,
struct xfs_owner_info *oinfo)
{
struct xfs_refcount_irec ext, tmp;
int error;
int found_rec, found_tmp;
if (aglen == 0)
return 0;
error = xfs_refcount_lookup_ge(cur, agbno, &found_rec);
if (error)
goto out_error;
error = xfs_refcount_get_rec(cur, &ext, &found_rec);
if (error)
goto out_error;
if (!found_rec) {
ext.rc_startblock = cur->bc_mp->m_sb.sb_agblocks +
XFS_REFC_COW_START;
ext.rc_blockcount = 0;
ext.rc_refcount = 0;
}
switch (adj) {
case XFS_REFCOUNT_ADJUST_COW_ALLOC:
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp,
ext.rc_startblock >= agbno + aglen, out_error);
tmp.rc_startblock = agbno;
tmp.rc_blockcount = aglen;
tmp.rc_refcount = 1;
trace_xfs_refcount_modify_extent(cur->bc_mp,
cur->bc_private.a.agno, &tmp);
error = xfs_refcount_insert(cur, &tmp,
&found_tmp);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp,
found_tmp == 1, out_error);
break;
case XFS_REFCOUNT_ADJUST_COW_FREE:
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp,
ext.rc_startblock == agbno, out_error);
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp,
ext.rc_blockcount == aglen, out_error);
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp,
ext.rc_refcount == 1, out_error);
ext.rc_refcount = 0;
trace_xfs_refcount_modify_extent(cur->bc_mp,
cur->bc_private.a.agno, &ext);
error = xfs_refcount_delete(cur, &found_rec);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(cur->bc_mp,
found_rec == 1, out_error);
break;
default:
ASSERT(0);
}
return error;
out_error:
trace_xfs_refcount_modify_extent_error(cur->bc_mp,
cur->bc_private.a.agno, error, _RET_IP_);
return error;
}
STATIC int
xfs_refcount_adjust_cow(
struct xfs_btree_cur *cur,
xfs_agblock_t agbno,
xfs_extlen_t aglen,
enum xfs_refc_adjust_op adj,
struct xfs_defer_ops *dfops)
{
bool shape_changed;
int error;
agbno += XFS_REFC_COW_START;
error = xfs_refcount_split_extent(cur, agbno, &shape_changed);
if (error)
goto out_error;
error = xfs_refcount_split_extent(cur, agbno + aglen, &shape_changed);
if (error)
goto out_error;
error = xfs_refcount_merge_extents(cur, &agbno, &aglen, adj,
XFS_FIND_RCEXT_COW, &shape_changed);
if (error)
goto out_error;
error = xfs_refcount_adjust_cow_extents(cur, agbno, aglen, adj,
dfops, NULL);
if (error)
goto out_error;
return 0;
out_error:
trace_xfs_refcount_adjust_cow_error(cur->bc_mp, cur->bc_private.a.agno,
error, _RET_IP_);
return error;
}
STATIC int
__xfs_refcount_cow_alloc(
struct xfs_btree_cur *rcur,
xfs_agblock_t agbno,
xfs_extlen_t aglen,
struct xfs_defer_ops *dfops)
{
int error;
trace_xfs_refcount_cow_increase(rcur->bc_mp, rcur->bc_private.a.agno,
agbno, aglen);
error = xfs_refcount_adjust_cow(rcur, agbno, aglen,
XFS_REFCOUNT_ADJUST_COW_ALLOC, dfops);
if (error)
return error;
if (xfs_sb_version_hasrmapbt(&rcur->bc_mp->m_sb)) {
error = xfs_rmap_alloc_extent(rcur->bc_mp, dfops,
rcur->bc_private.a.agno,
agbno, aglen, XFS_RMAP_OWN_COW);
if (error)
return error;
}
return error;
}
STATIC int
__xfs_refcount_cow_free(
struct xfs_btree_cur *rcur,
xfs_agblock_t agbno,
xfs_extlen_t aglen,
struct xfs_defer_ops *dfops)
{
int error;
trace_xfs_refcount_cow_decrease(rcur->bc_mp, rcur->bc_private.a.agno,
agbno, aglen);
error = xfs_refcount_adjust_cow(rcur, agbno, aglen,
XFS_REFCOUNT_ADJUST_COW_FREE, dfops);
if (error)
return error;
if (xfs_sb_version_hasrmapbt(&rcur->bc_mp->m_sb)) {
error = xfs_rmap_free_extent(rcur->bc_mp, dfops,
rcur->bc_private.a.agno,
agbno, aglen, XFS_RMAP_OWN_COW);
if (error)
return error;
}
return error;
}
int
xfs_refcount_alloc_cow_extent(
struct xfs_mount *mp,
struct xfs_defer_ops *dfops,
xfs_fsblock_t fsb,
xfs_extlen_t len)
{
if (!xfs_sb_version_hasreflink(&mp->m_sb))
return 0;
return __xfs_refcount_add(mp, dfops, XFS_REFCOUNT_ALLOC_COW,
fsb, len);
}
int
xfs_refcount_free_cow_extent(
struct xfs_mount *mp,
struct xfs_defer_ops *dfops,
xfs_fsblock_t fsb,
xfs_extlen_t len)
{
if (!xfs_sb_version_hasreflink(&mp->m_sb))
return 0;
return __xfs_refcount_add(mp, dfops, XFS_REFCOUNT_FREE_COW,
fsb, len);
}
STATIC int
xfs_refcount_recover_extent(
struct xfs_btree_cur *cur,
union xfs_btree_rec *rec,
void *priv)
{
struct list_head *debris = priv;
struct xfs_refcount_recovery *rr;
if (be32_to_cpu(rec->refc.rc_refcount) != 1)
return -EFSCORRUPTED;
rr = kmem_alloc(sizeof(struct xfs_refcount_recovery), KM_SLEEP);
xfs_refcount_btrec_to_irec(rec, &rr->rr_rrec);
list_add_tail(&rr->rr_list, debris);
return 0;
}
int
xfs_refcount_recover_cow_leftovers(
struct xfs_mount *mp,
xfs_agnumber_t agno)
{
struct xfs_trans *tp;
struct xfs_btree_cur *cur;
struct xfs_buf *agbp;
struct xfs_refcount_recovery *rr, *n;
struct list_head debris;
union xfs_btree_irec low;
union xfs_btree_irec high;
struct xfs_defer_ops dfops;
xfs_fsblock_t fsb;
xfs_agblock_t agbno;
int error;
if (mp->m_sb.sb_agblocks >= XFS_REFC_COW_START)
return -EOPNOTSUPP;
INIT_LIST_HEAD(&debris);
error = xfs_trans_alloc_empty(mp, &tp);
if (error)
return error;
error = xfs_alloc_read_agf(mp, tp, agno, 0, &agbp);
if (error)
goto out_trans;
if (!agbp) {
error = -ENOMEM;
goto out_trans;
}
cur = xfs_refcountbt_init_cursor(mp, tp, agbp, agno, NULL);
memset(&low, 0, sizeof(low));
memset(&high, 0, sizeof(high));
low.rc.rc_startblock = XFS_REFC_COW_START;
high.rc.rc_startblock = -1U;
error = xfs_btree_query_range(cur, &low, &high,
xfs_refcount_recover_extent, &debris);
if (error)
goto out_cursor;
xfs_btree_del_cursor(cur, XFS_BTREE_NOERROR);
xfs_trans_brelse(tp, agbp);
xfs_trans_cancel(tp);
list_for_each_entry_safe(rr, n, &debris, rr_list) {
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_write, 0, 0, 0, &tp);
if (error)
goto out_free;
trace_xfs_refcount_recover_extent(mp, agno, &rr->rr_rrec);
xfs_defer_init(&dfops, &fsb);
agbno = rr->rr_rrec.rc_startblock - XFS_REFC_COW_START;
fsb = XFS_AGB_TO_FSB(mp, agno, agbno);
error = xfs_refcount_free_cow_extent(mp, &dfops, fsb,
rr->rr_rrec.rc_blockcount);
if (error)
goto out_defer;
xfs_bmap_add_free(mp, &dfops, fsb,
rr->rr_rrec.rc_blockcount, NULL);
error = xfs_defer_finish(&tp, &dfops, NULL);
if (error)
goto out_defer;
error = xfs_trans_commit(tp);
if (error)
goto out_free;
list_del(&rr->rr_list);
kmem_free(rr);
}
return error;
out_defer:
xfs_defer_cancel(&dfops);
out_trans:
xfs_trans_cancel(tp);
out_free:
list_for_each_entry_safe(rr, n, &debris, rr_list) {
list_del(&rr->rr_list);
kmem_free(rr);
}
return error;
out_cursor:
xfs_btree_del_cursor(cur, XFS_BTREE_ERROR);
xfs_trans_brelse(tp, agbp);
goto out_trans;
}
