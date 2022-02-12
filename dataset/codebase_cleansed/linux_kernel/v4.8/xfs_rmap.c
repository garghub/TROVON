int
xfs_rmap_lookup_le(
struct xfs_btree_cur *cur,
xfs_agblock_t bno,
xfs_extlen_t len,
uint64_t owner,
uint64_t offset,
unsigned int flags,
int *stat)
{
cur->bc_rec.r.rm_startblock = bno;
cur->bc_rec.r.rm_blockcount = len;
cur->bc_rec.r.rm_owner = owner;
cur->bc_rec.r.rm_offset = offset;
cur->bc_rec.r.rm_flags = flags;
return xfs_btree_lookup(cur, XFS_LOOKUP_LE, stat);
}
int
xfs_rmap_lookup_eq(
struct xfs_btree_cur *cur,
xfs_agblock_t bno,
xfs_extlen_t len,
uint64_t owner,
uint64_t offset,
unsigned int flags,
int *stat)
{
cur->bc_rec.r.rm_startblock = bno;
cur->bc_rec.r.rm_blockcount = len;
cur->bc_rec.r.rm_owner = owner;
cur->bc_rec.r.rm_offset = offset;
cur->bc_rec.r.rm_flags = flags;
return xfs_btree_lookup(cur, XFS_LOOKUP_EQ, stat);
}
STATIC int
xfs_rmap_update(
struct xfs_btree_cur *cur,
struct xfs_rmap_irec *irec)
{
union xfs_btree_rec rec;
int error;
trace_xfs_rmap_update(cur->bc_mp, cur->bc_private.a.agno,
irec->rm_startblock, irec->rm_blockcount,
irec->rm_owner, irec->rm_offset, irec->rm_flags);
rec.rmap.rm_startblock = cpu_to_be32(irec->rm_startblock);
rec.rmap.rm_blockcount = cpu_to_be32(irec->rm_blockcount);
rec.rmap.rm_owner = cpu_to_be64(irec->rm_owner);
rec.rmap.rm_offset = cpu_to_be64(
xfs_rmap_irec_offset_pack(irec));
error = xfs_btree_update(cur, &rec);
if (error)
trace_xfs_rmap_update_error(cur->bc_mp,
cur->bc_private.a.agno, error, _RET_IP_);
return error;
}
int
xfs_rmap_insert(
struct xfs_btree_cur *rcur,
xfs_agblock_t agbno,
xfs_extlen_t len,
uint64_t owner,
uint64_t offset,
unsigned int flags)
{
int i;
int error;
trace_xfs_rmap_insert(rcur->bc_mp, rcur->bc_private.a.agno, agbno,
len, owner, offset, flags);
error = xfs_rmap_lookup_eq(rcur, agbno, len, owner, offset, flags, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(rcur->bc_mp, i == 0, done);
rcur->bc_rec.r.rm_startblock = agbno;
rcur->bc_rec.r.rm_blockcount = len;
rcur->bc_rec.r.rm_owner = owner;
rcur->bc_rec.r.rm_offset = offset;
rcur->bc_rec.r.rm_flags = flags;
error = xfs_btree_insert(rcur, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(rcur->bc_mp, i == 1, done);
done:
if (error)
trace_xfs_rmap_insert_error(rcur->bc_mp,
rcur->bc_private.a.agno, error, _RET_IP_);
return error;
}
static int
xfs_rmap_btrec_to_irec(
union xfs_btree_rec *rec,
struct xfs_rmap_irec *irec)
{
irec->rm_flags = 0;
irec->rm_startblock = be32_to_cpu(rec->rmap.rm_startblock);
irec->rm_blockcount = be32_to_cpu(rec->rmap.rm_blockcount);
irec->rm_owner = be64_to_cpu(rec->rmap.rm_owner);
return xfs_rmap_irec_offset_unpack(be64_to_cpu(rec->rmap.rm_offset),
irec);
}
int
xfs_rmap_get_rec(
struct xfs_btree_cur *cur,
struct xfs_rmap_irec *irec,
int *stat)
{
union xfs_btree_rec *rec;
int error;
error = xfs_btree_get_rec(cur, &rec, stat);
if (error || !*stat)
return error;
return xfs_rmap_btrec_to_irec(rec, irec);
}
STATIC int
xfs_rmap_unmap(
struct xfs_btree_cur *cur,
xfs_agblock_t bno,
xfs_extlen_t len,
bool unwritten,
struct xfs_owner_info *oinfo)
{
struct xfs_mount *mp = cur->bc_mp;
struct xfs_rmap_irec ltrec;
uint64_t ltoff;
int error = 0;
int i;
uint64_t owner;
uint64_t offset;
unsigned int flags;
bool ignore_off;
xfs_owner_info_unpack(oinfo, &owner, &offset, &flags);
ignore_off = XFS_RMAP_NON_INODE_OWNER(owner) ||
(flags & XFS_RMAP_BMBT_BLOCK);
if (unwritten)
flags |= XFS_RMAP_UNWRITTEN;
trace_xfs_rmap_unmap(mp, cur->bc_private.a.agno, bno, len,
unwritten, oinfo);
error = xfs_rmap_lookup_le(cur, bno, len, owner, offset, flags, &i);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, out_error);
error = xfs_rmap_get_rec(cur, &ltrec, &i);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, out_error);
trace_xfs_rmap_lookup_le_range_result(cur->bc_mp,
cur->bc_private.a.agno, ltrec.rm_startblock,
ltrec.rm_blockcount, ltrec.rm_owner,
ltrec.rm_offset, ltrec.rm_flags);
ltoff = ltrec.rm_offset;
if (owner == XFS_RMAP_OWN_NULL) {
XFS_WANT_CORRUPTED_GOTO(mp, bno >= ltrec.rm_startblock +
ltrec.rm_blockcount, out_error);
goto out_done;
}
XFS_WANT_CORRUPTED_GOTO(mp, (flags & XFS_RMAP_UNWRITTEN) ==
(ltrec.rm_flags & XFS_RMAP_UNWRITTEN), out_error);
XFS_WANT_CORRUPTED_GOTO(mp, ltrec.rm_startblock <= bno &&
ltrec.rm_startblock + ltrec.rm_blockcount >=
bno + len, out_error);
XFS_WANT_CORRUPTED_GOTO(mp, owner == ltrec.rm_owner ||
XFS_RMAP_NON_INODE_OWNER(owner), out_error);
if (!XFS_RMAP_NON_INODE_OWNER(owner)) {
if (flags & XFS_RMAP_BMBT_BLOCK) {
XFS_WANT_CORRUPTED_GOTO(mp,
ltrec.rm_flags & XFS_RMAP_BMBT_BLOCK,
out_error);
} else {
XFS_WANT_CORRUPTED_GOTO(mp,
ltrec.rm_offset <= offset, out_error);
XFS_WANT_CORRUPTED_GOTO(mp,
ltoff + ltrec.rm_blockcount >= offset + len,
out_error);
}
}
if (ltrec.rm_startblock == bno && ltrec.rm_blockcount == len) {
trace_xfs_rmap_delete(mp, cur->bc_private.a.agno,
ltrec.rm_startblock, ltrec.rm_blockcount,
ltrec.rm_owner, ltrec.rm_offset,
ltrec.rm_flags);
error = xfs_btree_delete(cur, &i);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, out_error);
} else if (ltrec.rm_startblock == bno) {
ltrec.rm_startblock += len;
ltrec.rm_blockcount -= len;
if (!ignore_off)
ltrec.rm_offset += len;
error = xfs_rmap_update(cur, &ltrec);
if (error)
goto out_error;
} else if (ltrec.rm_startblock + ltrec.rm_blockcount == bno + len) {
ltrec.rm_blockcount -= len;
error = xfs_rmap_update(cur, &ltrec);
if (error)
goto out_error;
} else {
xfs_extlen_t orig_len = ltrec.rm_blockcount;
ltrec.rm_blockcount = bno - ltrec.rm_startblock;
error = xfs_rmap_update(cur, &ltrec);
if (error)
goto out_error;
error = xfs_btree_increment(cur, 0, &i);
if (error)
goto out_error;
cur->bc_rec.r.rm_startblock = bno + len;
cur->bc_rec.r.rm_blockcount = orig_len - len -
ltrec.rm_blockcount;
cur->bc_rec.r.rm_owner = ltrec.rm_owner;
if (ignore_off)
cur->bc_rec.r.rm_offset = 0;
else
cur->bc_rec.r.rm_offset = offset + len;
cur->bc_rec.r.rm_flags = flags;
trace_xfs_rmap_insert(mp, cur->bc_private.a.agno,
cur->bc_rec.r.rm_startblock,
cur->bc_rec.r.rm_blockcount,
cur->bc_rec.r.rm_owner,
cur->bc_rec.r.rm_offset,
cur->bc_rec.r.rm_flags);
error = xfs_btree_insert(cur, &i);
if (error)
goto out_error;
}
out_done:
trace_xfs_rmap_unmap_done(mp, cur->bc_private.a.agno, bno, len,
unwritten, oinfo);
out_error:
if (error)
trace_xfs_rmap_unmap_error(mp, cur->bc_private.a.agno,
error, _RET_IP_);
return error;
}
int
xfs_rmap_free(
struct xfs_trans *tp,
struct xfs_buf *agbp,
xfs_agnumber_t agno,
xfs_agblock_t bno,
xfs_extlen_t len,
struct xfs_owner_info *oinfo)
{
struct xfs_mount *mp = tp->t_mountp;
struct xfs_btree_cur *cur;
int error;
if (!xfs_sb_version_hasrmapbt(&mp->m_sb))
return 0;
cur = xfs_rmapbt_init_cursor(mp, tp, agbp, agno);
error = xfs_rmap_unmap(cur, bno, len, false, oinfo);
if (error)
goto out_error;
xfs_btree_del_cursor(cur, XFS_BTREE_NOERROR);
return 0;
out_error:
xfs_btree_del_cursor(cur, XFS_BTREE_ERROR);
return error;
}
static bool
xfs_rmap_is_mergeable(
struct xfs_rmap_irec *irec,
uint64_t owner,
unsigned int flags)
{
if (irec->rm_owner == XFS_RMAP_OWN_NULL)
return false;
if (irec->rm_owner != owner)
return false;
if ((flags & XFS_RMAP_UNWRITTEN) ^
(irec->rm_flags & XFS_RMAP_UNWRITTEN))
return false;
if ((flags & XFS_RMAP_ATTR_FORK) ^
(irec->rm_flags & XFS_RMAP_ATTR_FORK))
return false;
if ((flags & XFS_RMAP_BMBT_BLOCK) ^
(irec->rm_flags & XFS_RMAP_BMBT_BLOCK))
return false;
return true;
}
STATIC int
xfs_rmap_map(
struct xfs_btree_cur *cur,
xfs_agblock_t bno,
xfs_extlen_t len,
bool unwritten,
struct xfs_owner_info *oinfo)
{
struct xfs_mount *mp = cur->bc_mp;
struct xfs_rmap_irec ltrec;
struct xfs_rmap_irec gtrec;
int have_gt;
int have_lt;
int error = 0;
int i;
uint64_t owner;
uint64_t offset;
unsigned int flags = 0;
bool ignore_off;
xfs_owner_info_unpack(oinfo, &owner, &offset, &flags);
ASSERT(owner != 0);
ignore_off = XFS_RMAP_NON_INODE_OWNER(owner) ||
(flags & XFS_RMAP_BMBT_BLOCK);
if (unwritten)
flags |= XFS_RMAP_UNWRITTEN;
trace_xfs_rmap_map(mp, cur->bc_private.a.agno, bno, len,
unwritten, oinfo);
error = xfs_rmap_lookup_le(cur, bno, len, owner, offset, flags,
&have_lt);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(mp, have_lt == 1, out_error);
error = xfs_rmap_get_rec(cur, &ltrec, &have_lt);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(mp, have_lt == 1, out_error);
trace_xfs_rmap_lookup_le_range_result(cur->bc_mp,
cur->bc_private.a.agno, ltrec.rm_startblock,
ltrec.rm_blockcount, ltrec.rm_owner,
ltrec.rm_offset, ltrec.rm_flags);
if (!xfs_rmap_is_mergeable(&ltrec, owner, flags))
have_lt = 0;
XFS_WANT_CORRUPTED_GOTO(mp,
have_lt == 0 ||
ltrec.rm_startblock + ltrec.rm_blockcount <= bno, out_error);
error = xfs_btree_increment(cur, 0, &have_gt);
if (error)
goto out_error;
if (have_gt) {
error = xfs_rmap_get_rec(cur, &gtrec, &have_gt);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(mp, have_gt == 1, out_error);
XFS_WANT_CORRUPTED_GOTO(mp, bno + len <= gtrec.rm_startblock,
out_error);
trace_xfs_rmap_find_right_neighbor_result(cur->bc_mp,
cur->bc_private.a.agno, gtrec.rm_startblock,
gtrec.rm_blockcount, gtrec.rm_owner,
gtrec.rm_offset, gtrec.rm_flags);
if (!xfs_rmap_is_mergeable(&gtrec, owner, flags))
have_gt = 0;
}
if (have_lt &&
ltrec.rm_startblock + ltrec.rm_blockcount == bno &&
(ignore_off || ltrec.rm_offset + ltrec.rm_blockcount == offset)) {
ltrec.rm_blockcount += len;
if (have_gt &&
bno + len == gtrec.rm_startblock &&
(ignore_off || offset + len == gtrec.rm_offset) &&
(unsigned long)ltrec.rm_blockcount + len +
gtrec.rm_blockcount <= XFS_RMAP_LEN_MAX) {
ltrec.rm_blockcount += gtrec.rm_blockcount;
trace_xfs_rmap_delete(mp, cur->bc_private.a.agno,
gtrec.rm_startblock,
gtrec.rm_blockcount,
gtrec.rm_owner,
gtrec.rm_offset,
gtrec.rm_flags);
error = xfs_btree_delete(cur, &i);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, out_error);
}
error = xfs_btree_decrement(cur, 0, &have_gt);
if (error)
goto out_error;
error = xfs_rmap_update(cur, &ltrec);
if (error)
goto out_error;
} else if (have_gt &&
bno + len == gtrec.rm_startblock &&
(ignore_off || offset + len == gtrec.rm_offset)) {
gtrec.rm_startblock = bno;
gtrec.rm_blockcount += len;
if (!ignore_off)
gtrec.rm_offset = offset;
error = xfs_rmap_update(cur, &gtrec);
if (error)
goto out_error;
} else {
cur->bc_rec.r.rm_startblock = bno;
cur->bc_rec.r.rm_blockcount = len;
cur->bc_rec.r.rm_owner = owner;
cur->bc_rec.r.rm_offset = offset;
cur->bc_rec.r.rm_flags = flags;
trace_xfs_rmap_insert(mp, cur->bc_private.a.agno, bno, len,
owner, offset, flags);
error = xfs_btree_insert(cur, &i);
if (error)
goto out_error;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, out_error);
}
trace_xfs_rmap_map_done(mp, cur->bc_private.a.agno, bno, len,
unwritten, oinfo);
out_error:
if (error)
trace_xfs_rmap_map_error(mp, cur->bc_private.a.agno,
error, _RET_IP_);
return error;
}
int
xfs_rmap_alloc(
struct xfs_trans *tp,
struct xfs_buf *agbp,
xfs_agnumber_t agno,
xfs_agblock_t bno,
xfs_extlen_t len,
struct xfs_owner_info *oinfo)
{
struct xfs_mount *mp = tp->t_mountp;
struct xfs_btree_cur *cur;
int error;
if (!xfs_sb_version_hasrmapbt(&mp->m_sb))
return 0;
cur = xfs_rmapbt_init_cursor(mp, tp, agbp, agno);
error = xfs_rmap_map(cur, bno, len, false, oinfo);
if (error)
goto out_error;
xfs_btree_del_cursor(cur, XFS_BTREE_NOERROR);
return 0;
out_error:
xfs_btree_del_cursor(cur, XFS_BTREE_ERROR);
return error;
}
STATIC int
xfs_rmap_convert(
struct xfs_btree_cur *cur,
xfs_agblock_t bno,
xfs_extlen_t len,
bool unwritten,
struct xfs_owner_info *oinfo)
{
struct xfs_mount *mp = cur->bc_mp;
struct xfs_rmap_irec r[4];
uint64_t owner;
uint64_t offset;
uint64_t new_endoff;
unsigned int oldext;
unsigned int newext;
unsigned int flags = 0;
int i;
int state = 0;
int error;
xfs_owner_info_unpack(oinfo, &owner, &offset, &flags);
ASSERT(!(XFS_RMAP_NON_INODE_OWNER(owner) ||
(flags & (XFS_RMAP_ATTR_FORK | XFS_RMAP_BMBT_BLOCK))));
oldext = unwritten ? XFS_RMAP_UNWRITTEN : 0;
new_endoff = offset + len;
trace_xfs_rmap_convert(mp, cur->bc_private.a.agno, bno, len,
unwritten, oinfo);
error = xfs_rmap_lookup_le(cur, bno, len, owner, offset, oldext, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
error = xfs_rmap_get_rec(cur, &PREV, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
trace_xfs_rmap_lookup_le_range_result(cur->bc_mp,
cur->bc_private.a.agno, PREV.rm_startblock,
PREV.rm_blockcount, PREV.rm_owner,
PREV.rm_offset, PREV.rm_flags);
ASSERT(PREV.rm_offset <= offset);
ASSERT(PREV.rm_offset + PREV.rm_blockcount >= new_endoff);
ASSERT((PREV.rm_flags & XFS_RMAP_UNWRITTEN) == oldext);
newext = ~oldext & XFS_RMAP_UNWRITTEN;
if (PREV.rm_offset == offset)
state |= RMAP_LEFT_FILLING;
if (PREV.rm_offset + PREV.rm_blockcount == new_endoff)
state |= RMAP_RIGHT_FILLING;
error = xfs_btree_decrement(cur, 0, &i);
if (error)
goto done;
if (i) {
state |= RMAP_LEFT_VALID;
error = xfs_rmap_get_rec(cur, &LEFT, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
XFS_WANT_CORRUPTED_GOTO(mp,
LEFT.rm_startblock + LEFT.rm_blockcount <= bno,
done);
trace_xfs_rmap_find_left_neighbor_result(cur->bc_mp,
cur->bc_private.a.agno, LEFT.rm_startblock,
LEFT.rm_blockcount, LEFT.rm_owner,
LEFT.rm_offset, LEFT.rm_flags);
if (LEFT.rm_startblock + LEFT.rm_blockcount == bno &&
LEFT.rm_offset + LEFT.rm_blockcount == offset &&
xfs_rmap_is_mergeable(&LEFT, owner, newext))
state |= RMAP_LEFT_CONTIG;
}
error = xfs_btree_increment(cur, 0, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
error = xfs_btree_increment(cur, 0, &i);
if (error)
goto done;
if (i) {
state |= RMAP_RIGHT_VALID;
error = xfs_rmap_get_rec(cur, &RIGHT, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
XFS_WANT_CORRUPTED_GOTO(mp, bno + len <= RIGHT.rm_startblock,
done);
trace_xfs_rmap_find_right_neighbor_result(cur->bc_mp,
cur->bc_private.a.agno, RIGHT.rm_startblock,
RIGHT.rm_blockcount, RIGHT.rm_owner,
RIGHT.rm_offset, RIGHT.rm_flags);
if (bno + len == RIGHT.rm_startblock &&
offset + len == RIGHT.rm_offset &&
xfs_rmap_is_mergeable(&RIGHT, owner, newext))
state |= RMAP_RIGHT_CONTIG;
}
if ((state & (RMAP_LEFT_FILLING | RMAP_LEFT_CONTIG |
RMAP_RIGHT_FILLING | RMAP_RIGHT_CONTIG)) ==
(RMAP_LEFT_FILLING | RMAP_LEFT_CONTIG |
RMAP_RIGHT_FILLING | RMAP_RIGHT_CONTIG) &&
(unsigned long)LEFT.rm_blockcount + len +
RIGHT.rm_blockcount > XFS_RMAP_LEN_MAX)
state &= ~RMAP_RIGHT_CONTIG;
trace_xfs_rmap_convert_state(mp, cur->bc_private.a.agno, state,
_RET_IP_);
error = xfs_rmap_lookup_le(cur, bno, len, owner, offset, oldext, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
switch (state & (RMAP_LEFT_FILLING | RMAP_LEFT_CONTIG |
RMAP_RIGHT_FILLING | RMAP_RIGHT_CONTIG)) {
case RMAP_LEFT_FILLING | RMAP_LEFT_CONTIG |
RMAP_RIGHT_FILLING | RMAP_RIGHT_CONTIG:
error = xfs_btree_increment(cur, 0, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
trace_xfs_rmap_delete(mp, cur->bc_private.a.agno,
RIGHT.rm_startblock, RIGHT.rm_blockcount,
RIGHT.rm_owner, RIGHT.rm_offset,
RIGHT.rm_flags);
error = xfs_btree_delete(cur, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
error = xfs_btree_decrement(cur, 0, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
trace_xfs_rmap_delete(mp, cur->bc_private.a.agno,
PREV.rm_startblock, PREV.rm_blockcount,
PREV.rm_owner, PREV.rm_offset,
PREV.rm_flags);
error = xfs_btree_delete(cur, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
error = xfs_btree_decrement(cur, 0, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
NEW = LEFT;
NEW.rm_blockcount += PREV.rm_blockcount + RIGHT.rm_blockcount;
error = xfs_rmap_update(cur, &NEW);
if (error)
goto done;
break;
case RMAP_LEFT_FILLING | RMAP_RIGHT_FILLING | RMAP_LEFT_CONTIG:
trace_xfs_rmap_delete(mp, cur->bc_private.a.agno,
PREV.rm_startblock, PREV.rm_blockcount,
PREV.rm_owner, PREV.rm_offset,
PREV.rm_flags);
error = xfs_btree_delete(cur, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
error = xfs_btree_decrement(cur, 0, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
NEW = LEFT;
NEW.rm_blockcount += PREV.rm_blockcount;
error = xfs_rmap_update(cur, &NEW);
if (error)
goto done;
break;
case RMAP_LEFT_FILLING | RMAP_RIGHT_FILLING | RMAP_RIGHT_CONTIG:
error = xfs_btree_increment(cur, 0, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
trace_xfs_rmap_delete(mp, cur->bc_private.a.agno,
RIGHT.rm_startblock, RIGHT.rm_blockcount,
RIGHT.rm_owner, RIGHT.rm_offset,
RIGHT.rm_flags);
error = xfs_btree_delete(cur, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
error = xfs_btree_decrement(cur, 0, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
NEW = PREV;
NEW.rm_blockcount = len + RIGHT.rm_blockcount;
NEW.rm_flags = newext;
error = xfs_rmap_update(cur, &NEW);
if (error)
goto done;
break;
case RMAP_LEFT_FILLING | RMAP_RIGHT_FILLING:
NEW = PREV;
NEW.rm_flags = newext;
error = xfs_rmap_update(cur, &NEW);
if (error)
goto done;
break;
case RMAP_LEFT_FILLING | RMAP_LEFT_CONTIG:
NEW = PREV;
NEW.rm_offset += len;
NEW.rm_startblock += len;
NEW.rm_blockcount -= len;
error = xfs_rmap_update(cur, &NEW);
if (error)
goto done;
error = xfs_btree_decrement(cur, 0, &i);
if (error)
goto done;
NEW = LEFT;
NEW.rm_blockcount += len;
error = xfs_rmap_update(cur, &NEW);
if (error)
goto done;
break;
case RMAP_LEFT_FILLING:
NEW = PREV;
NEW.rm_startblock += len;
NEW.rm_offset += len;
NEW.rm_blockcount -= len;
error = xfs_rmap_update(cur, &NEW);
if (error)
goto done;
NEW.rm_startblock = bno;
NEW.rm_owner = owner;
NEW.rm_offset = offset;
NEW.rm_blockcount = len;
NEW.rm_flags = newext;
cur->bc_rec.r = NEW;
trace_xfs_rmap_insert(mp, cur->bc_private.a.agno, bno,
len, owner, offset, newext);
error = xfs_btree_insert(cur, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
break;
case RMAP_RIGHT_FILLING | RMAP_RIGHT_CONTIG:
NEW = PREV;
NEW.rm_blockcount -= len;
error = xfs_rmap_update(cur, &NEW);
if (error)
goto done;
error = xfs_btree_increment(cur, 0, &i);
if (error)
goto done;
NEW = RIGHT;
NEW.rm_offset = offset;
NEW.rm_startblock = bno;
NEW.rm_blockcount += len;
error = xfs_rmap_update(cur, &NEW);
if (error)
goto done;
break;
case RMAP_RIGHT_FILLING:
NEW = PREV;
NEW.rm_blockcount -= len;
error = xfs_rmap_update(cur, &NEW);
if (error)
goto done;
error = xfs_rmap_lookup_eq(cur, bno, len, owner, offset,
oldext, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 0, done);
NEW.rm_startblock = bno;
NEW.rm_owner = owner;
NEW.rm_offset = offset;
NEW.rm_blockcount = len;
NEW.rm_flags = newext;
cur->bc_rec.r = NEW;
trace_xfs_rmap_insert(mp, cur->bc_private.a.agno, bno,
len, owner, offset, newext);
error = xfs_btree_insert(cur, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
break;
case 0:
NEW.rm_startblock = bno + len;
NEW.rm_owner = owner;
NEW.rm_offset = new_endoff;
NEW.rm_blockcount = PREV.rm_offset + PREV.rm_blockcount -
new_endoff;
NEW.rm_flags = PREV.rm_flags;
error = xfs_rmap_update(cur, &NEW);
if (error)
goto done;
NEW = PREV;
NEW.rm_blockcount = offset - PREV.rm_offset;
cur->bc_rec.r = NEW;
trace_xfs_rmap_insert(mp, cur->bc_private.a.agno,
NEW.rm_startblock, NEW.rm_blockcount,
NEW.rm_owner, NEW.rm_offset,
NEW.rm_flags);
error = xfs_btree_insert(cur, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
error = xfs_rmap_lookup_eq(cur, bno, len, owner, offset,
oldext, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 0, done);
cur->bc_rec.r.rm_flags &= ~XFS_RMAP_UNWRITTEN;
cur->bc_rec.r.rm_flags |= newext;
trace_xfs_rmap_insert(mp, cur->bc_private.a.agno, bno, len,
owner, offset, newext);
error = xfs_btree_insert(cur, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
break;
case RMAP_LEFT_FILLING | RMAP_LEFT_CONTIG | RMAP_RIGHT_CONTIG:
case RMAP_RIGHT_FILLING | RMAP_LEFT_CONTIG | RMAP_RIGHT_CONTIG:
case RMAP_LEFT_FILLING | RMAP_RIGHT_CONTIG:
case RMAP_RIGHT_FILLING | RMAP_LEFT_CONTIG:
case RMAP_LEFT_CONTIG | RMAP_RIGHT_CONTIG:
case RMAP_LEFT_CONTIG:
case RMAP_RIGHT_CONTIG:
ASSERT(0);
}
trace_xfs_rmap_convert_done(mp, cur->bc_private.a.agno, bno, len,
unwritten, oinfo);
done:
if (error)
trace_xfs_rmap_convert_error(cur->bc_mp,
cur->bc_private.a.agno, error, _RET_IP_);
return error;
}
STATIC int
xfs_rmap_query_range_helper(
struct xfs_btree_cur *cur,
union xfs_btree_rec *rec,
void *priv)
{
struct xfs_rmap_query_range_info *query = priv;
struct xfs_rmap_irec irec;
int error;
error = xfs_rmap_btrec_to_irec(rec, &irec);
if (error)
return error;
return query->fn(cur, &irec, query->priv);
}
int
xfs_rmap_query_range(
struct xfs_btree_cur *cur,
struct xfs_rmap_irec *low_rec,
struct xfs_rmap_irec *high_rec,
xfs_rmap_query_range_fn fn,
void *priv)
{
union xfs_btree_irec low_brec;
union xfs_btree_irec high_brec;
struct xfs_rmap_query_range_info query;
low_brec.r = *low_rec;
high_brec.r = *high_rec;
query.priv = priv;
query.fn = fn;
return xfs_btree_query_range(cur, &low_brec, &high_brec,
xfs_rmap_query_range_helper, &query);
}
void
xfs_rmap_finish_one_cleanup(
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
xfs_rmap_finish_one(
struct xfs_trans *tp,
enum xfs_rmap_intent_type type,
__uint64_t owner,
int whichfork,
xfs_fileoff_t startoff,
xfs_fsblock_t startblock,
xfs_filblks_t blockcount,
xfs_exntst_t state,
struct xfs_btree_cur **pcur)
{
struct xfs_mount *mp = tp->t_mountp;
struct xfs_btree_cur *rcur;
struct xfs_buf *agbp = NULL;
int error = 0;
xfs_agnumber_t agno;
struct xfs_owner_info oinfo;
xfs_agblock_t bno;
bool unwritten;
agno = XFS_FSB_TO_AGNO(mp, startblock);
ASSERT(agno != NULLAGNUMBER);
bno = XFS_FSB_TO_AGBNO(mp, startblock);
trace_xfs_rmap_deferred(mp, agno, type, bno, owner, whichfork,
startoff, blockcount, state);
if (XFS_TEST_ERROR(false, mp,
XFS_ERRTAG_RMAP_FINISH_ONE,
XFS_RANDOM_RMAP_FINISH_ONE))
return -EIO;
rcur = *pcur;
if (rcur != NULL && rcur->bc_private.a.agno != agno) {
xfs_rmap_finish_one_cleanup(tp, rcur, 0);
rcur = NULL;
*pcur = NULL;
}
if (rcur == NULL) {
error = xfs_free_extent_fix_freelist(tp, agno, &agbp);
if (error)
return error;
if (!agbp)
return -EFSCORRUPTED;
rcur = xfs_rmapbt_init_cursor(mp, tp, agbp, agno);
if (!rcur) {
error = -ENOMEM;
goto out_cur;
}
}
*pcur = rcur;
xfs_rmap_ino_owner(&oinfo, owner, whichfork, startoff);
unwritten = state == XFS_EXT_UNWRITTEN;
bno = XFS_FSB_TO_AGBNO(rcur->bc_mp, startblock);
switch (type) {
case XFS_RMAP_ALLOC:
case XFS_RMAP_MAP:
error = xfs_rmap_map(rcur, bno, blockcount, unwritten, &oinfo);
break;
case XFS_RMAP_FREE:
case XFS_RMAP_UNMAP:
error = xfs_rmap_unmap(rcur, bno, blockcount, unwritten,
&oinfo);
break;
case XFS_RMAP_CONVERT:
error = xfs_rmap_convert(rcur, bno, blockcount, !unwritten,
&oinfo);
break;
default:
ASSERT(0);
error = -EFSCORRUPTED;
}
return error;
out_cur:
xfs_trans_brelse(tp, agbp);
return error;
}
static bool
xfs_rmap_update_is_needed(
struct xfs_mount *mp)
{
return xfs_sb_version_hasrmapbt(&mp->m_sb);
}
static int
__xfs_rmap_add(
struct xfs_mount *mp,
struct xfs_defer_ops *dfops,
enum xfs_rmap_intent_type type,
__uint64_t owner,
int whichfork,
struct xfs_bmbt_irec *bmap)
{
struct xfs_rmap_intent *ri;
trace_xfs_rmap_defer(mp, XFS_FSB_TO_AGNO(mp, bmap->br_startblock),
type,
XFS_FSB_TO_AGBNO(mp, bmap->br_startblock),
owner, whichfork,
bmap->br_startoff,
bmap->br_blockcount,
bmap->br_state);
ri = kmem_alloc(sizeof(struct xfs_rmap_intent), KM_SLEEP | KM_NOFS);
INIT_LIST_HEAD(&ri->ri_list);
ri->ri_type = type;
ri->ri_owner = owner;
ri->ri_whichfork = whichfork;
ri->ri_bmap = *bmap;
xfs_defer_add(dfops, XFS_DEFER_OPS_TYPE_RMAP, &ri->ri_list);
return 0;
}
int
xfs_rmap_map_extent(
struct xfs_mount *mp,
struct xfs_defer_ops *dfops,
struct xfs_inode *ip,
int whichfork,
struct xfs_bmbt_irec *PREV)
{
if (!xfs_rmap_update_is_needed(mp))
return 0;
return __xfs_rmap_add(mp, dfops, XFS_RMAP_MAP, ip->i_ino,
whichfork, PREV);
}
int
xfs_rmap_unmap_extent(
struct xfs_mount *mp,
struct xfs_defer_ops *dfops,
struct xfs_inode *ip,
int whichfork,
struct xfs_bmbt_irec *PREV)
{
if (!xfs_rmap_update_is_needed(mp))
return 0;
return __xfs_rmap_add(mp, dfops, XFS_RMAP_UNMAP, ip->i_ino,
whichfork, PREV);
}
int
xfs_rmap_convert_extent(
struct xfs_mount *mp,
struct xfs_defer_ops *dfops,
struct xfs_inode *ip,
int whichfork,
struct xfs_bmbt_irec *PREV)
{
if (!xfs_rmap_update_is_needed(mp))
return 0;
return __xfs_rmap_add(mp, dfops, XFS_RMAP_CONVERT, ip->i_ino,
whichfork, PREV);
}
int
xfs_rmap_alloc_extent(
struct xfs_mount *mp,
struct xfs_defer_ops *dfops,
xfs_agnumber_t agno,
xfs_agblock_t bno,
xfs_extlen_t len,
__uint64_t owner)
{
struct xfs_bmbt_irec bmap;
if (!xfs_rmap_update_is_needed(mp))
return 0;
bmap.br_startblock = XFS_AGB_TO_FSB(mp, agno, bno);
bmap.br_blockcount = len;
bmap.br_startoff = 0;
bmap.br_state = XFS_EXT_NORM;
return __xfs_rmap_add(mp, dfops, XFS_RMAP_ALLOC, owner,
XFS_DATA_FORK, &bmap);
}
int
xfs_rmap_free_extent(
struct xfs_mount *mp,
struct xfs_defer_ops *dfops,
xfs_agnumber_t agno,
xfs_agblock_t bno,
xfs_extlen_t len,
__uint64_t owner)
{
struct xfs_bmbt_irec bmap;
if (!xfs_rmap_update_is_needed(mp))
return 0;
bmap.br_startblock = XFS_AGB_TO_FSB(mp, agno, bno);
bmap.br_blockcount = len;
bmap.br_startoff = 0;
bmap.br_state = XFS_EXT_NORM;
return __xfs_rmap_add(mp, dfops, XFS_RMAP_FREE, owner,
XFS_DATA_FORK, &bmap);
}
