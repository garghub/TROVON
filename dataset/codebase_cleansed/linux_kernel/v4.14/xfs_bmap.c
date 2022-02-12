void
xfs_bmap_compute_maxlevels(
xfs_mount_t *mp,
int whichfork)
{
int level;
uint maxblocks;
uint maxleafents;
int maxrootrecs;
int minleafrecs;
int minnoderecs;
int sz;
if (whichfork == XFS_DATA_FORK) {
maxleafents = MAXEXTNUM;
sz = XFS_BMDR_SPACE_CALC(MINDBTPTRS);
} else {
maxleafents = MAXAEXTNUM;
sz = XFS_BMDR_SPACE_CALC(MINABTPTRS);
}
maxrootrecs = xfs_bmdr_maxrecs(sz, 0);
minleafrecs = mp->m_bmap_dmnr[0];
minnoderecs = mp->m_bmap_dmnr[1];
maxblocks = (maxleafents + minleafrecs - 1) / minleafrecs;
for (level = 1; maxblocks > 1; level++) {
if (maxblocks <= maxrootrecs)
maxblocks = 1;
else
maxblocks = (maxblocks + minnoderecs - 1) / minnoderecs;
}
mp->m_bm_maxlevels[whichfork] = level;
}
STATIC int
xfs_bmbt_lookup_eq(
struct xfs_btree_cur *cur,
xfs_fileoff_t off,
xfs_fsblock_t bno,
xfs_filblks_t len,
int *stat)
{
cur->bc_rec.b.br_startoff = off;
cur->bc_rec.b.br_startblock = bno;
cur->bc_rec.b.br_blockcount = len;
return xfs_btree_lookup(cur, XFS_LOOKUP_EQ, stat);
}
STATIC int
xfs_bmbt_lookup_ge(
struct xfs_btree_cur *cur,
xfs_fileoff_t off,
xfs_fsblock_t bno,
xfs_filblks_t len,
int *stat)
{
cur->bc_rec.b.br_startoff = off;
cur->bc_rec.b.br_startblock = bno;
cur->bc_rec.b.br_blockcount = len;
return xfs_btree_lookup(cur, XFS_LOOKUP_GE, stat);
}
static inline bool xfs_bmap_needs_btree(struct xfs_inode *ip, int whichfork)
{
return whichfork != XFS_COW_FORK &&
XFS_IFORK_FORMAT(ip, whichfork) == XFS_DINODE_FMT_EXTENTS &&
XFS_IFORK_NEXTENTS(ip, whichfork) >
XFS_IFORK_MAXEXT(ip, whichfork);
}
static inline bool xfs_bmap_wants_extents(struct xfs_inode *ip, int whichfork)
{
return whichfork != XFS_COW_FORK &&
XFS_IFORK_FORMAT(ip, whichfork) == XFS_DINODE_FMT_BTREE &&
XFS_IFORK_NEXTENTS(ip, whichfork) <=
XFS_IFORK_MAXEXT(ip, whichfork);
}
STATIC int
xfs_bmbt_update(
struct xfs_btree_cur *cur,
xfs_fileoff_t off,
xfs_fsblock_t bno,
xfs_filblks_t len,
xfs_exntst_t state)
{
union xfs_btree_rec rec;
xfs_bmbt_disk_set_allf(&rec.bmbt, off, bno, len, state);
return xfs_btree_update(cur, &rec);
}
STATIC xfs_filblks_t
xfs_bmap_worst_indlen(
xfs_inode_t *ip,
xfs_filblks_t len)
{
int level;
int maxrecs;
xfs_mount_t *mp;
xfs_filblks_t rval;
mp = ip->i_mount;
maxrecs = mp->m_bmap_dmxr[0];
for (level = 0, rval = 0;
level < XFS_BM_MAXLEVELS(mp, XFS_DATA_FORK);
level++) {
len += maxrecs - 1;
do_div(len, maxrecs);
rval += len;
if (len == 1)
return rval + XFS_BM_MAXLEVELS(mp, XFS_DATA_FORK) -
level - 1;
if (level == 0)
maxrecs = mp->m_bmap_dmxr[1];
}
return rval;
}
uint
xfs_default_attroffset(
struct xfs_inode *ip)
{
struct xfs_mount *mp = ip->i_mount;
uint offset;
if (mp->m_sb.sb_inodesize == 256) {
offset = XFS_LITINO(mp, ip->i_d.di_version) -
XFS_BMDR_SPACE_CALC(MINABTPTRS);
} else {
offset = XFS_BMDR_SPACE_CALC(6 * MINABTPTRS);
}
ASSERT(offset < XFS_LITINO(mp, ip->i_d.di_version));
return offset;
}
STATIC void
xfs_bmap_forkoff_reset(
xfs_inode_t *ip,
int whichfork)
{
if (whichfork == XFS_ATTR_FORK &&
ip->i_d.di_format != XFS_DINODE_FMT_DEV &&
ip->i_d.di_format != XFS_DINODE_FMT_UUID &&
ip->i_d.di_format != XFS_DINODE_FMT_BTREE) {
uint dfl_forkoff = xfs_default_attroffset(ip) >> 3;
if (dfl_forkoff > ip->i_d.di_forkoff)
ip->i_d.di_forkoff = dfl_forkoff;
}
}
STATIC struct xfs_buf *
xfs_bmap_get_bp(
struct xfs_btree_cur *cur,
xfs_fsblock_t bno)
{
struct xfs_log_item_desc *lidp;
int i;
if (!cur)
return NULL;
for (i = 0; i < XFS_BTREE_MAXLEVELS; i++) {
if (!cur->bc_bufs[i])
break;
if (XFS_BUF_ADDR(cur->bc_bufs[i]) == bno)
return cur->bc_bufs[i];
}
list_for_each_entry(lidp, &cur->bc_tp->t_items, lid_trans) {
struct xfs_buf_log_item *bip;
bip = (struct xfs_buf_log_item *)lidp->lid_item;
if (bip->bli_item.li_type == XFS_LI_BUF &&
XFS_BUF_ADDR(bip->bli_buf) == bno)
return bip->bli_buf;
}
return NULL;
}
STATIC void
xfs_check_block(
struct xfs_btree_block *block,
xfs_mount_t *mp,
int root,
short sz)
{
int i, j, dmxr;
__be64 *pp, *thispa;
xfs_bmbt_key_t *prevp, *keyp;
ASSERT(be16_to_cpu(block->bb_level) > 0);
prevp = NULL;
for( i = 1; i <= xfs_btree_get_numrecs(block); i++) {
dmxr = mp->m_bmap_dmxr[0];
keyp = XFS_BMBT_KEY_ADDR(mp, block, i);
if (prevp) {
ASSERT(be64_to_cpu(prevp->br_startoff) <
be64_to_cpu(keyp->br_startoff));
}
prevp = keyp;
if (root)
pp = XFS_BMAP_BROOT_PTR_ADDR(mp, block, i, sz);
else
pp = XFS_BMBT_PTR_ADDR(mp, block, i, dmxr);
for (j = i+1; j <= be16_to_cpu(block->bb_numrecs); j++) {
if (root)
thispa = XFS_BMAP_BROOT_PTR_ADDR(mp, block, j, sz);
else
thispa = XFS_BMBT_PTR_ADDR(mp, block, j, dmxr);
if (*thispa == *pp) {
xfs_warn(mp, "%s: thispa(%d) == pp(%d) %Ld",
__func__, j, i,
(unsigned long long)be64_to_cpu(*thispa));
panic("%s: ptrs are equal in node\n",
__func__);
}
}
}
}
STATIC void
xfs_bmap_check_leaf_extents(
xfs_btree_cur_t *cur,
xfs_inode_t *ip,
int whichfork)
{
struct xfs_btree_block *block;
xfs_fsblock_t bno;
xfs_buf_t *bp;
int error;
xfs_extnum_t i=0, j;
xfs_ifork_t *ifp;
int level;
xfs_mount_t *mp;
__be64 *pp;
xfs_bmbt_rec_t *ep;
xfs_bmbt_rec_t last = {0, 0};
xfs_bmbt_rec_t *nextp;
int bp_release = 0;
if (XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_BTREE) {
return;
}
if (ip->i_d.di_nextents > 10000)
return;
bno = NULLFSBLOCK;
mp = ip->i_mount;
ifp = XFS_IFORK_PTR(ip, whichfork);
block = ifp->if_broot;
level = be16_to_cpu(block->bb_level);
ASSERT(level > 0);
xfs_check_block(block, mp, 1, ifp->if_broot_bytes);
pp = XFS_BMAP_BROOT_PTR_ADDR(mp, block, 1, ifp->if_broot_bytes);
bno = be64_to_cpu(*pp);
ASSERT(bno != NULLFSBLOCK);
ASSERT(XFS_FSB_TO_AGNO(mp, bno) < mp->m_sb.sb_agcount);
ASSERT(XFS_FSB_TO_AGBNO(mp, bno) < mp->m_sb.sb_agblocks);
while (level-- > 0) {
bp_release = 0;
bp = xfs_bmap_get_bp(cur, XFS_FSB_TO_DADDR(mp, bno));
if (!bp) {
bp_release = 1;
error = xfs_btree_read_bufl(mp, NULL, bno, 0, &bp,
XFS_BMAP_BTREE_REF,
&xfs_bmbt_buf_ops);
if (error)
goto error_norelse;
}
block = XFS_BUF_TO_BLOCK(bp);
if (level == 0)
break;
xfs_check_block(block, mp, 0, 0);
pp = XFS_BMBT_PTR_ADDR(mp, block, 1, mp->m_bmap_dmxr[1]);
bno = be64_to_cpu(*pp);
XFS_WANT_CORRUPTED_GOTO(mp,
XFS_FSB_SANITY_CHECK(mp, bno), error0);
if (bp_release) {
bp_release = 0;
xfs_trans_brelse(NULL, bp);
}
}
i = 0;
for (;;) {
xfs_fsblock_t nextbno;
xfs_extnum_t num_recs;
num_recs = xfs_btree_get_numrecs(block);
nextbno = be64_to_cpu(block->bb_u.l.bb_rightsib);
ep = XFS_BMBT_REC_ADDR(mp, block, 1);
if (i) {
ASSERT(xfs_bmbt_disk_get_startoff(&last) +
xfs_bmbt_disk_get_blockcount(&last) <=
xfs_bmbt_disk_get_startoff(ep));
}
for (j = 1; j < num_recs; j++) {
nextp = XFS_BMBT_REC_ADDR(mp, block, j + 1);
ASSERT(xfs_bmbt_disk_get_startoff(ep) +
xfs_bmbt_disk_get_blockcount(ep) <=
xfs_bmbt_disk_get_startoff(nextp));
ep = nextp;
}
last = *ep;
i += num_recs;
if (bp_release) {
bp_release = 0;
xfs_trans_brelse(NULL, bp);
}
bno = nextbno;
if (bno == NULLFSBLOCK)
break;
bp_release = 0;
bp = xfs_bmap_get_bp(cur, XFS_FSB_TO_DADDR(mp, bno));
if (!bp) {
bp_release = 1;
error = xfs_btree_read_bufl(mp, NULL, bno, 0, &bp,
XFS_BMAP_BTREE_REF,
&xfs_bmbt_buf_ops);
if (error)
goto error_norelse;
}
block = XFS_BUF_TO_BLOCK(bp);
}
return;
error0:
xfs_warn(mp, "%s: at error0", __func__);
if (bp_release)
xfs_trans_brelse(NULL, bp);
error_norelse:
xfs_warn(mp, "%s: BAD after btree leaves for %d extents",
__func__, i);
panic("%s: CORRUPTED BTREE OR SOMETHING", __func__);
return;
}
void
xfs_bmap_trace_exlist(
xfs_inode_t *ip,
xfs_extnum_t cnt,
int whichfork,
unsigned long caller_ip)
{
xfs_extnum_t idx;
xfs_ifork_t *ifp;
int state = 0;
if (whichfork == XFS_ATTR_FORK)
state |= BMAP_ATTRFORK;
else if (whichfork == XFS_COW_FORK)
state |= BMAP_COWFORK;
ifp = XFS_IFORK_PTR(ip, whichfork);
ASSERT(cnt == xfs_iext_count(ifp));
for (idx = 0; idx < cnt; idx++)
trace_xfs_extlist(ip, idx, state, caller_ip);
}
STATIC void
xfs_bmap_validate_ret(
xfs_fileoff_t bno,
xfs_filblks_t len,
int flags,
xfs_bmbt_irec_t *mval,
int nmap,
int ret_nmap)
{
int i;
ASSERT(ret_nmap <= nmap);
for (i = 0; i < ret_nmap; i++) {
ASSERT(mval[i].br_blockcount > 0);
if (!(flags & XFS_BMAPI_ENTIRE)) {
ASSERT(mval[i].br_startoff >= bno);
ASSERT(mval[i].br_blockcount <= len);
ASSERT(mval[i].br_startoff + mval[i].br_blockcount <=
bno + len);
} else {
ASSERT(mval[i].br_startoff < bno + len);
ASSERT(mval[i].br_startoff + mval[i].br_blockcount >
bno);
}
ASSERT(i == 0 ||
mval[i - 1].br_startoff + mval[i - 1].br_blockcount ==
mval[i].br_startoff);
ASSERT(mval[i].br_startblock != DELAYSTARTBLOCK &&
mval[i].br_startblock != HOLESTARTBLOCK);
ASSERT(mval[i].br_state == XFS_EXT_NORM ||
mval[i].br_state == XFS_EXT_UNWRITTEN);
}
}
void
xfs_bmap_add_free(
struct xfs_mount *mp,
struct xfs_defer_ops *dfops,
xfs_fsblock_t bno,
xfs_filblks_t len,
struct xfs_owner_info *oinfo)
{
struct xfs_extent_free_item *new;
#ifdef DEBUG
xfs_agnumber_t agno;
xfs_agblock_t agbno;
ASSERT(bno != NULLFSBLOCK);
ASSERT(len > 0);
ASSERT(len <= MAXEXTLEN);
ASSERT(!isnullstartblock(bno));
agno = XFS_FSB_TO_AGNO(mp, bno);
agbno = XFS_FSB_TO_AGBNO(mp, bno);
ASSERT(agno < mp->m_sb.sb_agcount);
ASSERT(agbno < mp->m_sb.sb_agblocks);
ASSERT(len < mp->m_sb.sb_agblocks);
ASSERT(agbno + len <= mp->m_sb.sb_agblocks);
#endif
ASSERT(xfs_bmap_free_item_zone != NULL);
new = kmem_zone_alloc(xfs_bmap_free_item_zone, KM_SLEEP);
new->xefi_startblock = bno;
new->xefi_blockcount = (xfs_extlen_t)len;
if (oinfo)
new->xefi_oinfo = *oinfo;
else
xfs_rmap_skip_owner_update(&new->xefi_oinfo);
trace_xfs_bmap_free_defer(mp, XFS_FSB_TO_AGNO(mp, bno), 0,
XFS_FSB_TO_AGBNO(mp, bno), len);
xfs_defer_add(dfops, XFS_DEFER_OPS_TYPE_FREE, &new->xefi_list);
}
STATIC int
xfs_bmap_btree_to_extents(
xfs_trans_t *tp,
xfs_inode_t *ip,
xfs_btree_cur_t *cur,
int *logflagsp,
int whichfork)
{
struct xfs_btree_block *cblock;
xfs_fsblock_t cbno;
xfs_buf_t *cbp;
int error;
xfs_ifork_t *ifp;
xfs_mount_t *mp;
__be64 *pp;
struct xfs_btree_block *rblock;
struct xfs_owner_info oinfo;
mp = ip->i_mount;
ifp = XFS_IFORK_PTR(ip, whichfork);
ASSERT(whichfork != XFS_COW_FORK);
ASSERT(ifp->if_flags & XFS_IFEXTENTS);
ASSERT(XFS_IFORK_FORMAT(ip, whichfork) == XFS_DINODE_FMT_BTREE);
rblock = ifp->if_broot;
ASSERT(be16_to_cpu(rblock->bb_level) == 1);
ASSERT(be16_to_cpu(rblock->bb_numrecs) == 1);
ASSERT(xfs_bmbt_maxrecs(mp, ifp->if_broot_bytes, 0) == 1);
pp = XFS_BMAP_BROOT_PTR_ADDR(mp, rblock, 1, ifp->if_broot_bytes);
cbno = be64_to_cpu(*pp);
*logflagsp = 0;
#ifdef DEBUG
if ((error = xfs_btree_check_lptr(cur, cbno, 1)))
return error;
#endif
error = xfs_btree_read_bufl(mp, tp, cbno, 0, &cbp, XFS_BMAP_BTREE_REF,
&xfs_bmbt_buf_ops);
if (error)
return error;
cblock = XFS_BUF_TO_BLOCK(cbp);
if ((error = xfs_btree_check_block(cur, cblock, 0, cbp)))
return error;
xfs_rmap_ino_bmbt_owner(&oinfo, ip->i_ino, whichfork);
xfs_bmap_add_free(mp, cur->bc_private.b.dfops, cbno, 1, &oinfo);
ip->i_d.di_nblocks--;
xfs_trans_mod_dquot_byino(tp, ip, XFS_TRANS_DQ_BCOUNT, -1L);
xfs_trans_binval(tp, cbp);
if (cur->bc_bufs[0] == cbp)
cur->bc_bufs[0] = NULL;
xfs_iroot_realloc(ip, -1, whichfork);
ASSERT(ifp->if_broot == NULL);
ASSERT((ifp->if_flags & XFS_IFBROOT) == 0);
XFS_IFORK_FMT_SET(ip, whichfork, XFS_DINODE_FMT_EXTENTS);
*logflagsp = XFS_ILOG_CORE | xfs_ilog_fext(whichfork);
return 0;
}
STATIC int
xfs_bmap_extents_to_btree(
xfs_trans_t *tp,
xfs_inode_t *ip,
xfs_fsblock_t *firstblock,
struct xfs_defer_ops *dfops,
xfs_btree_cur_t **curp,
int wasdel,
int *logflagsp,
int whichfork)
{
struct xfs_btree_block *ablock;
xfs_buf_t *abp;
xfs_alloc_arg_t args;
xfs_bmbt_rec_t *arp;
struct xfs_btree_block *block;
xfs_btree_cur_t *cur;
xfs_bmbt_rec_host_t *ep;
int error;
xfs_extnum_t i, cnt;
xfs_ifork_t *ifp;
xfs_bmbt_key_t *kp;
xfs_mount_t *mp;
xfs_extnum_t nextents;
xfs_bmbt_ptr_t *pp;
mp = ip->i_mount;
ASSERT(whichfork != XFS_COW_FORK);
ifp = XFS_IFORK_PTR(ip, whichfork);
ASSERT(XFS_IFORK_FORMAT(ip, whichfork) == XFS_DINODE_FMT_EXTENTS);
xfs_iroot_realloc(ip, 1, whichfork);
ifp->if_flags |= XFS_IFBROOT;
block = ifp->if_broot;
xfs_btree_init_block_int(mp, block, XFS_BUF_DADDR_NULL,
XFS_BTNUM_BMAP, 1, 1, ip->i_ino,
XFS_BTREE_LONG_PTRS);
cur = xfs_bmbt_init_cursor(mp, tp, ip, whichfork);
cur->bc_private.b.firstblock = *firstblock;
cur->bc_private.b.dfops = dfops;
cur->bc_private.b.flags = wasdel ? XFS_BTCUR_BPRV_WASDEL : 0;
XFS_IFORK_FMT_SET(ip, whichfork, XFS_DINODE_FMT_BTREE);
memset(&args, 0, sizeof(args));
args.tp = tp;
args.mp = mp;
xfs_rmap_ino_bmbt_owner(&args.oinfo, ip->i_ino, whichfork);
args.firstblock = *firstblock;
if (*firstblock == NULLFSBLOCK) {
args.type = XFS_ALLOCTYPE_START_BNO;
args.fsbno = XFS_INO_TO_FSB(mp, ip->i_ino);
} else if (dfops->dop_low) {
args.type = XFS_ALLOCTYPE_START_BNO;
args.fsbno = *firstblock;
} else {
args.type = XFS_ALLOCTYPE_NEAR_BNO;
args.fsbno = *firstblock;
}
args.minlen = args.maxlen = args.prod = 1;
args.wasdel = wasdel;
*logflagsp = 0;
if ((error = xfs_alloc_vextent(&args))) {
xfs_iroot_realloc(ip, -1, whichfork);
xfs_btree_del_cursor(cur, XFS_BTREE_ERROR);
return error;
}
if (WARN_ON_ONCE(args.fsbno == NULLFSBLOCK)) {
xfs_iroot_realloc(ip, -1, whichfork);
xfs_btree_del_cursor(cur, XFS_BTREE_ERROR);
return -ENOSPC;
}
ASSERT(*firstblock == NULLFSBLOCK ||
args.agno >= XFS_FSB_TO_AGNO(mp, *firstblock));
*firstblock = cur->bc_private.b.firstblock = args.fsbno;
cur->bc_private.b.allocated++;
ip->i_d.di_nblocks++;
xfs_trans_mod_dquot_byino(tp, ip, XFS_TRANS_DQ_BCOUNT, 1L);
abp = xfs_btree_get_bufl(mp, tp, args.fsbno, 0);
abp->b_ops = &xfs_bmbt_buf_ops;
ablock = XFS_BUF_TO_BLOCK(abp);
xfs_btree_init_block_int(mp, ablock, abp->b_bn,
XFS_BTNUM_BMAP, 0, 0, ip->i_ino,
XFS_BTREE_LONG_PTRS);
arp = XFS_BMBT_REC_ADDR(mp, ablock, 1);
nextents = xfs_iext_count(ifp);
for (cnt = i = 0; i < nextents; i++) {
ep = xfs_iext_get_ext(ifp, i);
if (!isnullstartblock(xfs_bmbt_get_startblock(ep))) {
arp->l0 = cpu_to_be64(ep->l0);
arp->l1 = cpu_to_be64(ep->l1);
arp++; cnt++;
}
}
ASSERT(cnt == XFS_IFORK_NEXTENTS(ip, whichfork));
xfs_btree_set_numrecs(ablock, cnt);
kp = XFS_BMBT_KEY_ADDR(mp, block, 1);
arp = XFS_BMBT_REC_ADDR(mp, ablock, 1);
kp->br_startoff = cpu_to_be64(xfs_bmbt_disk_get_startoff(arp));
pp = XFS_BMBT_PTR_ADDR(mp, block, 1, xfs_bmbt_get_maxrecs(cur,
be16_to_cpu(block->bb_level)));
*pp = cpu_to_be64(args.fsbno);
xfs_btree_log_block(cur, abp, XFS_BB_ALL_BITS);
xfs_btree_log_recs(cur, abp, 1, be16_to_cpu(ablock->bb_numrecs));
ASSERT(*curp == NULL);
*curp = cur;
*logflagsp = XFS_ILOG_CORE | xfs_ilog_fbroot(whichfork);
return 0;
}
void
xfs_bmap_local_to_extents_empty(
struct xfs_inode *ip,
int whichfork)
{
struct xfs_ifork *ifp = XFS_IFORK_PTR(ip, whichfork);
ASSERT(whichfork != XFS_COW_FORK);
ASSERT(XFS_IFORK_FORMAT(ip, whichfork) == XFS_DINODE_FMT_LOCAL);
ASSERT(ifp->if_bytes == 0);
ASSERT(XFS_IFORK_NEXTENTS(ip, whichfork) == 0);
xfs_bmap_forkoff_reset(ip, whichfork);
ifp->if_flags &= ~XFS_IFINLINE;
ifp->if_flags |= XFS_IFEXTENTS;
XFS_IFORK_FMT_SET(ip, whichfork, XFS_DINODE_FMT_EXTENTS);
}
STATIC int
xfs_bmap_local_to_extents(
xfs_trans_t *tp,
xfs_inode_t *ip,
xfs_fsblock_t *firstblock,
xfs_extlen_t total,
int *logflagsp,
int whichfork,
void (*init_fn)(struct xfs_trans *tp,
struct xfs_buf *bp,
struct xfs_inode *ip,
struct xfs_ifork *ifp))
{
int error = 0;
int flags;
xfs_ifork_t *ifp;
xfs_alloc_arg_t args;
xfs_buf_t *bp;
struct xfs_bmbt_irec rec;
ASSERT(!(S_ISREG(VFS_I(ip)->i_mode) && whichfork == XFS_DATA_FORK));
ifp = XFS_IFORK_PTR(ip, whichfork);
ASSERT(XFS_IFORK_FORMAT(ip, whichfork) == XFS_DINODE_FMT_LOCAL);
if (!ifp->if_bytes) {
xfs_bmap_local_to_extents_empty(ip, whichfork);
flags = XFS_ILOG_CORE;
goto done;
}
flags = 0;
error = 0;
ASSERT((ifp->if_flags & (XFS_IFINLINE|XFS_IFEXTENTS|XFS_IFEXTIREC)) ==
XFS_IFINLINE);
memset(&args, 0, sizeof(args));
args.tp = tp;
args.mp = ip->i_mount;
xfs_rmap_ino_owner(&args.oinfo, ip->i_ino, whichfork, 0);
args.firstblock = *firstblock;
if (*firstblock == NULLFSBLOCK) {
args.fsbno = XFS_INO_TO_FSB(args.mp, ip->i_ino);
args.type = XFS_ALLOCTYPE_START_BNO;
} else {
args.fsbno = *firstblock;
args.type = XFS_ALLOCTYPE_NEAR_BNO;
}
args.total = total;
args.minlen = args.maxlen = args.prod = 1;
error = xfs_alloc_vextent(&args);
if (error)
goto done;
ASSERT(args.fsbno != NULLFSBLOCK);
ASSERT(args.len == 1);
*firstblock = args.fsbno;
bp = xfs_btree_get_bufl(args.mp, tp, args.fsbno, 0);
init_fn(tp, bp, ip, ifp);
xfs_idata_realloc(ip, -ifp->if_bytes, whichfork);
xfs_bmap_local_to_extents_empty(ip, whichfork);
flags |= XFS_ILOG_CORE;
rec.br_startoff = 0;
rec.br_startblock = args.fsbno;
rec.br_blockcount = 1;
rec.br_state = XFS_EXT_NORM;
xfs_iext_insert(ip, 0, 1, &rec, 0);
trace_xfs_bmap_post_update(ip, 0,
whichfork == XFS_ATTR_FORK ? BMAP_ATTRFORK : 0,
_THIS_IP_);
XFS_IFORK_NEXT_SET(ip, whichfork, 1);
ip->i_d.di_nblocks = 1;
xfs_trans_mod_dquot_byino(tp, ip,
XFS_TRANS_DQ_BCOUNT, 1L);
flags |= xfs_ilog_fext(whichfork);
done:
*logflagsp = flags;
return error;
}
STATIC int
xfs_bmap_add_attrfork_btree(
xfs_trans_t *tp,
xfs_inode_t *ip,
xfs_fsblock_t *firstblock,
struct xfs_defer_ops *dfops,
int *flags)
{
xfs_btree_cur_t *cur;
int error;
xfs_mount_t *mp;
int stat;
mp = ip->i_mount;
if (ip->i_df.if_broot_bytes <= XFS_IFORK_DSIZE(ip))
*flags |= XFS_ILOG_DBROOT;
else {
cur = xfs_bmbt_init_cursor(mp, tp, ip, XFS_DATA_FORK);
cur->bc_private.b.dfops = dfops;
cur->bc_private.b.firstblock = *firstblock;
if ((error = xfs_bmbt_lookup_ge(cur, 0, 0, 0, &stat)))
goto error0;
XFS_WANT_CORRUPTED_GOTO(mp, stat == 1, error0);
if ((error = xfs_btree_new_iroot(cur, flags, &stat)))
goto error0;
if (stat == 0) {
xfs_btree_del_cursor(cur, XFS_BTREE_NOERROR);
return -ENOSPC;
}
*firstblock = cur->bc_private.b.firstblock;
cur->bc_private.b.allocated = 0;
xfs_btree_del_cursor(cur, XFS_BTREE_NOERROR);
}
return 0;
error0:
xfs_btree_del_cursor(cur, XFS_BTREE_ERROR);
return error;
}
STATIC int
xfs_bmap_add_attrfork_extents(
xfs_trans_t *tp,
xfs_inode_t *ip,
xfs_fsblock_t *firstblock,
struct xfs_defer_ops *dfops,
int *flags)
{
xfs_btree_cur_t *cur;
int error;
if (ip->i_d.di_nextents * sizeof(xfs_bmbt_rec_t) <= XFS_IFORK_DSIZE(ip))
return 0;
cur = NULL;
error = xfs_bmap_extents_to_btree(tp, ip, firstblock, dfops, &cur, 0,
flags, XFS_DATA_FORK);
if (cur) {
cur->bc_private.b.allocated = 0;
xfs_btree_del_cursor(cur,
error ? XFS_BTREE_ERROR : XFS_BTREE_NOERROR);
}
return error;
}
STATIC int
xfs_bmap_add_attrfork_local(
xfs_trans_t *tp,
xfs_inode_t *ip,
xfs_fsblock_t *firstblock,
struct xfs_defer_ops *dfops,
int *flags)
{
xfs_da_args_t dargs;
if (ip->i_df.if_bytes <= XFS_IFORK_DSIZE(ip))
return 0;
if (S_ISDIR(VFS_I(ip)->i_mode)) {
memset(&dargs, 0, sizeof(dargs));
dargs.geo = ip->i_mount->m_dir_geo;
dargs.dp = ip;
dargs.firstblock = firstblock;
dargs.dfops = dfops;
dargs.total = dargs.geo->fsbcount;
dargs.whichfork = XFS_DATA_FORK;
dargs.trans = tp;
return xfs_dir2_sf_to_block(&dargs);
}
if (S_ISLNK(VFS_I(ip)->i_mode))
return xfs_bmap_local_to_extents(tp, ip, firstblock, 1,
flags, XFS_DATA_FORK,
xfs_symlink_local_to_remote);
ASSERT(0);
return -EFSCORRUPTED;
}
int
xfs_bmap_add_attrfork(
xfs_inode_t *ip,
int size,
int rsvd)
{
xfs_fsblock_t firstblock;
struct xfs_defer_ops dfops;
xfs_mount_t *mp;
xfs_trans_t *tp;
int blks;
int version = 1;
int logflags;
int error;
ASSERT(XFS_IFORK_Q(ip) == 0);
mp = ip->i_mount;
ASSERT(!XFS_NOT_DQATTACHED(mp, ip));
blks = XFS_ADDAFORK_SPACE_RES(mp);
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_addafork, blks, 0,
rsvd ? XFS_TRANS_RESERVE : 0, &tp);
if (error)
return error;
xfs_ilock(ip, XFS_ILOCK_EXCL);
error = xfs_trans_reserve_quota_nblks(tp, ip, blks, 0, rsvd ?
XFS_QMOPT_RES_REGBLKS | XFS_QMOPT_FORCE_RES :
XFS_QMOPT_RES_REGBLKS);
if (error)
goto trans_cancel;
if (XFS_IFORK_Q(ip))
goto trans_cancel;
if (ip->i_d.di_anextents != 0) {
error = -EFSCORRUPTED;
goto trans_cancel;
}
if (ip->i_d.di_aformat != XFS_DINODE_FMT_EXTENTS) {
ASSERT(ip->i_d.di_aformat == 0);
ip->i_d.di_aformat = XFS_DINODE_FMT_EXTENTS;
}
xfs_trans_ijoin(tp, ip, 0);
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
switch (ip->i_d.di_format) {
case XFS_DINODE_FMT_DEV:
ip->i_d.di_forkoff = roundup(sizeof(xfs_dev_t), 8) >> 3;
break;
case XFS_DINODE_FMT_UUID:
ip->i_d.di_forkoff = roundup(sizeof(uuid_t), 8) >> 3;
break;
case XFS_DINODE_FMT_LOCAL:
case XFS_DINODE_FMT_EXTENTS:
case XFS_DINODE_FMT_BTREE:
ip->i_d.di_forkoff = xfs_attr_shortform_bytesfit(ip, size);
if (!ip->i_d.di_forkoff)
ip->i_d.di_forkoff = xfs_default_attroffset(ip) >> 3;
else if (mp->m_flags & XFS_MOUNT_ATTR2)
version = 2;
break;
default:
ASSERT(0);
error = -EINVAL;
goto trans_cancel;
}
ASSERT(ip->i_afp == NULL);
ip->i_afp = kmem_zone_zalloc(xfs_ifork_zone, KM_SLEEP);
ip->i_afp->if_flags = XFS_IFEXTENTS;
logflags = 0;
xfs_defer_init(&dfops, &firstblock);
switch (ip->i_d.di_format) {
case XFS_DINODE_FMT_LOCAL:
error = xfs_bmap_add_attrfork_local(tp, ip, &firstblock, &dfops,
&logflags);
break;
case XFS_DINODE_FMT_EXTENTS:
error = xfs_bmap_add_attrfork_extents(tp, ip, &firstblock,
&dfops, &logflags);
break;
case XFS_DINODE_FMT_BTREE:
error = xfs_bmap_add_attrfork_btree(tp, ip, &firstblock, &dfops,
&logflags);
break;
default:
error = 0;
break;
}
if (logflags)
xfs_trans_log_inode(tp, ip, logflags);
if (error)
goto bmap_cancel;
if (!xfs_sb_version_hasattr(&mp->m_sb) ||
(!xfs_sb_version_hasattr2(&mp->m_sb) && version == 2)) {
bool log_sb = false;
spin_lock(&mp->m_sb_lock);
if (!xfs_sb_version_hasattr(&mp->m_sb)) {
xfs_sb_version_addattr(&mp->m_sb);
log_sb = true;
}
if (!xfs_sb_version_hasattr2(&mp->m_sb) && version == 2) {
xfs_sb_version_addattr2(&mp->m_sb);
log_sb = true;
}
spin_unlock(&mp->m_sb_lock);
if (log_sb)
xfs_log_sb(tp);
}
error = xfs_defer_finish(&tp, &dfops);
if (error)
goto bmap_cancel;
error = xfs_trans_commit(tp);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
bmap_cancel:
xfs_defer_cancel(&dfops);
trans_cancel:
xfs_trans_cancel(tp);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
}
int
xfs_bmap_read_extents(
xfs_trans_t *tp,
xfs_inode_t *ip,
int whichfork)
{
struct xfs_btree_block *block;
xfs_fsblock_t bno;
xfs_buf_t *bp;
int error;
xfs_extnum_t i, j;
xfs_ifork_t *ifp;
int level;
xfs_mount_t *mp;
__be64 *pp;
xfs_extnum_t room;
mp = ip->i_mount;
ifp = XFS_IFORK_PTR(ip, whichfork);
block = ifp->if_broot;
level = be16_to_cpu(block->bb_level);
ASSERT(level > 0);
pp = XFS_BMAP_BROOT_PTR_ADDR(mp, block, 1, ifp->if_broot_bytes);
bno = be64_to_cpu(*pp);
while (level-- > 0) {
error = xfs_btree_read_bufl(mp, tp, bno, 0, &bp,
XFS_BMAP_BTREE_REF, &xfs_bmbt_buf_ops);
if (error)
return error;
block = XFS_BUF_TO_BLOCK(bp);
if (level == 0)
break;
pp = XFS_BMBT_PTR_ADDR(mp, block, 1, mp->m_bmap_dmxr[1]);
bno = be64_to_cpu(*pp);
XFS_WANT_CORRUPTED_GOTO(mp,
XFS_FSB_SANITY_CHECK(mp, bno), error0);
xfs_trans_brelse(tp, bp);
}
room = xfs_iext_count(ifp);
i = 0;
for (;;) {
xfs_bmbt_rec_t *frp;
xfs_fsblock_t nextbno;
xfs_extnum_t num_recs;
num_recs = xfs_btree_get_numrecs(block);
if (unlikely(i + num_recs > room)) {
ASSERT(i + num_recs <= room);
xfs_warn(ip->i_mount,
"corrupt dinode %Lu, (btree extents).",
(unsigned long long) ip->i_ino);
XFS_CORRUPTION_ERROR("xfs_bmap_read_extents(1)",
XFS_ERRLEVEL_LOW, ip->i_mount, block);
goto error0;
}
nextbno = be64_to_cpu(block->bb_u.l.bb_rightsib);
if (nextbno != NULLFSBLOCK)
xfs_btree_reada_bufl(mp, nextbno, 1,
&xfs_bmbt_buf_ops);
frp = XFS_BMBT_REC_ADDR(mp, block, 1);
for (j = 0; j < num_recs; j++, i++, frp++) {
xfs_bmbt_rec_host_t *trp = xfs_iext_get_ext(ifp, i);
trp->l0 = be64_to_cpu(frp->l0);
trp->l1 = be64_to_cpu(frp->l1);
if (!xfs_bmbt_validate_extent(mp, whichfork, trp)) {
XFS_ERROR_REPORT("xfs_bmap_read_extents(2)",
XFS_ERRLEVEL_LOW, mp);
goto error0;
}
}
xfs_trans_brelse(tp, bp);
bno = nextbno;
if (bno == NULLFSBLOCK)
break;
error = xfs_btree_read_bufl(mp, tp, bno, 0, &bp,
XFS_BMAP_BTREE_REF, &xfs_bmbt_buf_ops);
if (error)
return error;
block = XFS_BUF_TO_BLOCK(bp);
}
if (i != XFS_IFORK_NEXTENTS(ip, whichfork))
return -EFSCORRUPTED;
ASSERT(i == xfs_iext_count(ifp));
XFS_BMAP_TRACE_EXLIST(ip, i, whichfork);
return 0;
error0:
xfs_trans_brelse(tp, bp);
return -EFSCORRUPTED;
}
int
xfs_bmap_first_unused(
xfs_trans_t *tp,
xfs_inode_t *ip,
xfs_extlen_t len,
xfs_fileoff_t *first_unused,
int whichfork)
{
int error;
int idx;
xfs_ifork_t *ifp;
xfs_fileoff_t lastaddr;
xfs_fileoff_t lowest;
xfs_fileoff_t max;
xfs_extnum_t nextents;
ASSERT(XFS_IFORK_FORMAT(ip, whichfork) == XFS_DINODE_FMT_BTREE ||
XFS_IFORK_FORMAT(ip, whichfork) == XFS_DINODE_FMT_EXTENTS ||
XFS_IFORK_FORMAT(ip, whichfork) == XFS_DINODE_FMT_LOCAL);
if (XFS_IFORK_FORMAT(ip, whichfork) == XFS_DINODE_FMT_LOCAL) {
*first_unused = 0;
return 0;
}
ifp = XFS_IFORK_PTR(ip, whichfork);
if (!(ifp->if_flags & XFS_IFEXTENTS) &&
(error = xfs_iread_extents(tp, ip, whichfork)))
return error;
lowest = *first_unused;
nextents = xfs_iext_count(ifp);
for (idx = 0, lastaddr = 0, max = lowest; idx < nextents; idx++) {
struct xfs_bmbt_irec got;
xfs_iext_get_extent(ifp, idx, &got);
if (got.br_startoff >= lowest + len &&
got.br_startoff - max >= len) {
*first_unused = max;
return 0;
}
lastaddr = got.br_startoff + got.br_blockcount;
max = XFS_FILEOFF_MAX(lastaddr, lowest);
}
*first_unused = max;
return 0;
}
int
xfs_bmap_last_before(
struct xfs_trans *tp,
struct xfs_inode *ip,
xfs_fileoff_t *last_block,
int whichfork)
{
struct xfs_ifork *ifp = XFS_IFORK_PTR(ip, whichfork);
struct xfs_bmbt_irec got;
xfs_extnum_t idx;
int error;
switch (XFS_IFORK_FORMAT(ip, whichfork)) {
case XFS_DINODE_FMT_LOCAL:
*last_block = 0;
return 0;
case XFS_DINODE_FMT_BTREE:
case XFS_DINODE_FMT_EXTENTS:
break;
default:
return -EIO;
}
if (!(ifp->if_flags & XFS_IFEXTENTS)) {
error = xfs_iread_extents(tp, ip, whichfork);
if (error)
return error;
}
if (xfs_iext_lookup_extent(ip, ifp, *last_block - 1, &idx, &got)) {
if (got.br_startoff <= *last_block - 1)
return 0;
}
if (xfs_iext_get_extent(ifp, idx - 1, &got)) {
*last_block = got.br_startoff + got.br_blockcount;
return 0;
}
*last_block = 0;
return 0;
}
int
xfs_bmap_last_extent(
struct xfs_trans *tp,
struct xfs_inode *ip,
int whichfork,
struct xfs_bmbt_irec *rec,
int *is_empty)
{
struct xfs_ifork *ifp = XFS_IFORK_PTR(ip, whichfork);
int error;
int nextents;
if (!(ifp->if_flags & XFS_IFEXTENTS)) {
error = xfs_iread_extents(tp, ip, whichfork);
if (error)
return error;
}
nextents = xfs_iext_count(ifp);
if (nextents == 0) {
*is_empty = 1;
return 0;
}
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, nextents - 1), rec);
*is_empty = 0;
return 0;
}
STATIC int
xfs_bmap_isaeof(
struct xfs_bmalloca *bma,
int whichfork)
{
struct xfs_bmbt_irec rec;
int is_empty;
int error;
bma->aeof = false;
error = xfs_bmap_last_extent(NULL, bma->ip, whichfork, &rec,
&is_empty);
if (error)
return error;
if (is_empty) {
bma->aeof = true;
return 0;
}
bma->aeof = bma->offset >= rec.br_startoff + rec.br_blockcount ||
(bma->offset >= rec.br_startoff &&
isnullstartblock(rec.br_startblock));
return 0;
}
int
xfs_bmap_last_offset(
struct xfs_inode *ip,
xfs_fileoff_t *last_block,
int whichfork)
{
struct xfs_bmbt_irec rec;
int is_empty;
int error;
*last_block = 0;
if (XFS_IFORK_FORMAT(ip, whichfork) == XFS_DINODE_FMT_LOCAL)
return 0;
if (XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_BTREE &&
XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_EXTENTS)
return -EIO;
error = xfs_bmap_last_extent(NULL, ip, whichfork, &rec, &is_empty);
if (error || is_empty)
return error;
*last_block = rec.br_startoff + rec.br_blockcount;
return 0;
}
int
xfs_bmap_one_block(
xfs_inode_t *ip,
int whichfork)
{
xfs_bmbt_rec_host_t *ep;
xfs_ifork_t *ifp;
int rval;
xfs_bmbt_irec_t s;
#ifndef DEBUG
if (whichfork == XFS_DATA_FORK)
return XFS_ISIZE(ip) == ip->i_mount->m_sb.sb_blocksize;
#endif
if (XFS_IFORK_NEXTENTS(ip, whichfork) != 1)
return 0;
if (XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_EXTENTS)
return 0;
ifp = XFS_IFORK_PTR(ip, whichfork);
ASSERT(ifp->if_flags & XFS_IFEXTENTS);
ep = xfs_iext_get_ext(ifp, 0);
xfs_bmbt_get_all(ep, &s);
rval = s.br_startoff == 0 && s.br_blockcount == 1;
if (rval && whichfork == XFS_DATA_FORK)
ASSERT(XFS_ISIZE(ip) == ip->i_mount->m_sb.sb_blocksize);
return rval;
}
STATIC int
xfs_bmap_add_extent_delay_real(
struct xfs_bmalloca *bma,
int whichfork)
{
struct xfs_bmbt_irec *new = &bma->got;
int diff;
xfs_bmbt_rec_host_t *ep;
int error;
int i;
xfs_ifork_t *ifp;
xfs_fileoff_t new_endoff;
xfs_bmbt_irec_t r[3];
int rval=0;
int state = 0;
xfs_filblks_t da_new;
xfs_filblks_t da_old;
xfs_filblks_t temp=0;
xfs_filblks_t temp2=0;
int tmp_rval;
struct xfs_mount *mp;
xfs_extnum_t *nextents;
mp = bma->ip->i_mount;
ifp = XFS_IFORK_PTR(bma->ip, whichfork);
ASSERT(whichfork != XFS_ATTR_FORK);
nextents = (whichfork == XFS_COW_FORK ? &bma->ip->i_cnextents :
&bma->ip->i_d.di_nextents);
ASSERT(bma->idx >= 0);
ASSERT(bma->idx <= xfs_iext_count(ifp));
ASSERT(!isnullstartblock(new->br_startblock));
ASSERT(!bma->cur ||
(bma->cur->bc_private.b.flags & XFS_BTCUR_BPRV_WASDEL));
XFS_STATS_INC(mp, xs_add_exlist);
#define LEFT r[0]
#define RIGHT r[1]
#define PREV r[2]
if (whichfork == XFS_COW_FORK)
state |= BMAP_COWFORK;
ep = xfs_iext_get_ext(ifp, bma->idx);
xfs_bmbt_get_all(ep, &PREV);
new_endoff = new->br_startoff + new->br_blockcount;
ASSERT(PREV.br_startoff <= new->br_startoff);
ASSERT(PREV.br_startoff + PREV.br_blockcount >= new_endoff);
da_old = startblockval(PREV.br_startblock);
da_new = 0;
if (PREV.br_startoff == new->br_startoff)
state |= BMAP_LEFT_FILLING;
if (PREV.br_startoff + PREV.br_blockcount == new_endoff)
state |= BMAP_RIGHT_FILLING;
if (bma->idx > 0) {
state |= BMAP_LEFT_VALID;
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, bma->idx - 1), &LEFT);
if (isnullstartblock(LEFT.br_startblock))
state |= BMAP_LEFT_DELAY;
}
if ((state & BMAP_LEFT_VALID) && !(state & BMAP_LEFT_DELAY) &&
LEFT.br_startoff + LEFT.br_blockcount == new->br_startoff &&
LEFT.br_startblock + LEFT.br_blockcount == new->br_startblock &&
LEFT.br_state == new->br_state &&
LEFT.br_blockcount + new->br_blockcount <= MAXEXTLEN)
state |= BMAP_LEFT_CONTIG;
if (bma->idx < xfs_iext_count(ifp) - 1) {
state |= BMAP_RIGHT_VALID;
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, bma->idx + 1), &RIGHT);
if (isnullstartblock(RIGHT.br_startblock))
state |= BMAP_RIGHT_DELAY;
}
if ((state & BMAP_RIGHT_VALID) && !(state & BMAP_RIGHT_DELAY) &&
new_endoff == RIGHT.br_startoff &&
new->br_startblock + new->br_blockcount == RIGHT.br_startblock &&
new->br_state == RIGHT.br_state &&
new->br_blockcount + RIGHT.br_blockcount <= MAXEXTLEN &&
((state & (BMAP_LEFT_CONTIG | BMAP_LEFT_FILLING |
BMAP_RIGHT_FILLING)) !=
(BMAP_LEFT_CONTIG | BMAP_LEFT_FILLING |
BMAP_RIGHT_FILLING) ||
LEFT.br_blockcount + new->br_blockcount + RIGHT.br_blockcount
<= MAXEXTLEN))
state |= BMAP_RIGHT_CONTIG;
error = 0;
switch (state & (BMAP_LEFT_FILLING | BMAP_LEFT_CONTIG |
BMAP_RIGHT_FILLING | BMAP_RIGHT_CONTIG)) {
case BMAP_LEFT_FILLING | BMAP_LEFT_CONTIG |
BMAP_RIGHT_FILLING | BMAP_RIGHT_CONTIG:
bma->idx--;
trace_xfs_bmap_pre_update(bma->ip, bma->idx, state, _THIS_IP_);
xfs_bmbt_set_blockcount(xfs_iext_get_ext(ifp, bma->idx),
LEFT.br_blockcount + PREV.br_blockcount +
RIGHT.br_blockcount);
trace_xfs_bmap_post_update(bma->ip, bma->idx, state, _THIS_IP_);
xfs_iext_remove(bma->ip, bma->idx + 1, 2, state);
(*nextents)--;
if (bma->cur == NULL)
rval = XFS_ILOG_CORE | XFS_ILOG_DEXT;
else {
rval = XFS_ILOG_CORE;
error = xfs_bmbt_lookup_eq(bma->cur, RIGHT.br_startoff,
RIGHT.br_startblock,
RIGHT.br_blockcount, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
error = xfs_btree_delete(bma->cur, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
error = xfs_btree_decrement(bma->cur, 0, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
error = xfs_bmbt_update(bma->cur, LEFT.br_startoff,
LEFT.br_startblock,
LEFT.br_blockcount +
PREV.br_blockcount +
RIGHT.br_blockcount, LEFT.br_state);
if (error)
goto done;
}
break;
case BMAP_LEFT_FILLING | BMAP_RIGHT_FILLING | BMAP_LEFT_CONTIG:
bma->idx--;
trace_xfs_bmap_pre_update(bma->ip, bma->idx, state, _THIS_IP_);
xfs_bmbt_set_blockcount(xfs_iext_get_ext(ifp, bma->idx),
LEFT.br_blockcount + PREV.br_blockcount);
trace_xfs_bmap_post_update(bma->ip, bma->idx, state, _THIS_IP_);
xfs_iext_remove(bma->ip, bma->idx + 1, 1, state);
if (bma->cur == NULL)
rval = XFS_ILOG_DEXT;
else {
rval = 0;
error = xfs_bmbt_lookup_eq(bma->cur, LEFT.br_startoff,
LEFT.br_startblock, LEFT.br_blockcount,
&i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
error = xfs_bmbt_update(bma->cur, LEFT.br_startoff,
LEFT.br_startblock,
LEFT.br_blockcount +
PREV.br_blockcount, LEFT.br_state);
if (error)
goto done;
}
break;
case BMAP_LEFT_FILLING | BMAP_RIGHT_FILLING | BMAP_RIGHT_CONTIG:
trace_xfs_bmap_pre_update(bma->ip, bma->idx, state, _THIS_IP_);
xfs_bmbt_set_startblock(ep, new->br_startblock);
xfs_bmbt_set_blockcount(ep,
PREV.br_blockcount + RIGHT.br_blockcount);
trace_xfs_bmap_post_update(bma->ip, bma->idx, state, _THIS_IP_);
xfs_iext_remove(bma->ip, bma->idx + 1, 1, state);
if (bma->cur == NULL)
rval = XFS_ILOG_DEXT;
else {
rval = 0;
error = xfs_bmbt_lookup_eq(bma->cur, RIGHT.br_startoff,
RIGHT.br_startblock,
RIGHT.br_blockcount, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
error = xfs_bmbt_update(bma->cur, PREV.br_startoff,
new->br_startblock,
PREV.br_blockcount +
RIGHT.br_blockcount, PREV.br_state);
if (error)
goto done;
}
break;
case BMAP_LEFT_FILLING | BMAP_RIGHT_FILLING:
trace_xfs_bmap_pre_update(bma->ip, bma->idx, state, _THIS_IP_);
xfs_bmbt_set_startblock(ep, new->br_startblock);
xfs_bmbt_set_state(ep, new->br_state);
trace_xfs_bmap_post_update(bma->ip, bma->idx, state, _THIS_IP_);
(*nextents)++;
if (bma->cur == NULL)
rval = XFS_ILOG_CORE | XFS_ILOG_DEXT;
else {
rval = XFS_ILOG_CORE;
error = xfs_bmbt_lookup_eq(bma->cur, new->br_startoff,
new->br_startblock, new->br_blockcount,
&i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 0, done);
bma->cur->bc_rec.b.br_state = XFS_EXT_NORM;
error = xfs_btree_insert(bma->cur, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
}
break;
case BMAP_LEFT_FILLING | BMAP_LEFT_CONTIG:
trace_xfs_bmap_pre_update(bma->ip, bma->idx - 1, state, _THIS_IP_);
xfs_bmbt_set_blockcount(xfs_iext_get_ext(ifp, bma->idx - 1),
LEFT.br_blockcount + new->br_blockcount);
xfs_bmbt_set_startoff(ep,
PREV.br_startoff + new->br_blockcount);
trace_xfs_bmap_post_update(bma->ip, bma->idx - 1, state, _THIS_IP_);
temp = PREV.br_blockcount - new->br_blockcount;
trace_xfs_bmap_pre_update(bma->ip, bma->idx, state, _THIS_IP_);
xfs_bmbt_set_blockcount(ep, temp);
if (bma->cur == NULL)
rval = XFS_ILOG_DEXT;
else {
rval = 0;
error = xfs_bmbt_lookup_eq(bma->cur, LEFT.br_startoff,
LEFT.br_startblock, LEFT.br_blockcount,
&i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
error = xfs_bmbt_update(bma->cur, LEFT.br_startoff,
LEFT.br_startblock,
LEFT.br_blockcount +
new->br_blockcount,
LEFT.br_state);
if (error)
goto done;
}
da_new = XFS_FILBLKS_MIN(xfs_bmap_worst_indlen(bma->ip, temp),
startblockval(PREV.br_startblock));
xfs_bmbt_set_startblock(ep, nullstartblock(da_new));
trace_xfs_bmap_post_update(bma->ip, bma->idx, state, _THIS_IP_);
bma->idx--;
break;
case BMAP_LEFT_FILLING:
trace_xfs_bmap_pre_update(bma->ip, bma->idx, state, _THIS_IP_);
xfs_bmbt_set_startoff(ep, new_endoff);
temp = PREV.br_blockcount - new->br_blockcount;
xfs_bmbt_set_blockcount(ep, temp);
xfs_iext_insert(bma->ip, bma->idx, 1, new, state);
(*nextents)++;
if (bma->cur == NULL)
rval = XFS_ILOG_CORE | XFS_ILOG_DEXT;
else {
rval = XFS_ILOG_CORE;
error = xfs_bmbt_lookup_eq(bma->cur, new->br_startoff,
new->br_startblock, new->br_blockcount,
&i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 0, done);
bma->cur->bc_rec.b.br_state = XFS_EXT_NORM;
error = xfs_btree_insert(bma->cur, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
}
if (xfs_bmap_needs_btree(bma->ip, whichfork)) {
error = xfs_bmap_extents_to_btree(bma->tp, bma->ip,
bma->firstblock, bma->dfops,
&bma->cur, 1, &tmp_rval, whichfork);
rval |= tmp_rval;
if (error)
goto done;
}
da_new = XFS_FILBLKS_MIN(xfs_bmap_worst_indlen(bma->ip, temp),
startblockval(PREV.br_startblock) -
(bma->cur ? bma->cur->bc_private.b.allocated : 0));
ep = xfs_iext_get_ext(ifp, bma->idx + 1);
xfs_bmbt_set_startblock(ep, nullstartblock(da_new));
trace_xfs_bmap_post_update(bma->ip, bma->idx + 1, state, _THIS_IP_);
break;
case BMAP_RIGHT_FILLING | BMAP_RIGHT_CONTIG:
temp = PREV.br_blockcount - new->br_blockcount;
trace_xfs_bmap_pre_update(bma->ip, bma->idx + 1, state, _THIS_IP_);
xfs_bmbt_set_blockcount(ep, temp);
xfs_bmbt_set_allf(xfs_iext_get_ext(ifp, bma->idx + 1),
new->br_startoff, new->br_startblock,
new->br_blockcount + RIGHT.br_blockcount,
RIGHT.br_state);
trace_xfs_bmap_post_update(bma->ip, bma->idx + 1, state, _THIS_IP_);
if (bma->cur == NULL)
rval = XFS_ILOG_DEXT;
else {
rval = 0;
error = xfs_bmbt_lookup_eq(bma->cur, RIGHT.br_startoff,
RIGHT.br_startblock,
RIGHT.br_blockcount, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
error = xfs_bmbt_update(bma->cur, new->br_startoff,
new->br_startblock,
new->br_blockcount +
RIGHT.br_blockcount,
RIGHT.br_state);
if (error)
goto done;
}
da_new = XFS_FILBLKS_MIN(xfs_bmap_worst_indlen(bma->ip, temp),
startblockval(PREV.br_startblock));
trace_xfs_bmap_pre_update(bma->ip, bma->idx, state, _THIS_IP_);
xfs_bmbt_set_startblock(ep, nullstartblock(da_new));
trace_xfs_bmap_post_update(bma->ip, bma->idx, state, _THIS_IP_);
bma->idx++;
break;
case BMAP_RIGHT_FILLING:
temp = PREV.br_blockcount - new->br_blockcount;
trace_xfs_bmap_pre_update(bma->ip, bma->idx, state, _THIS_IP_);
xfs_bmbt_set_blockcount(ep, temp);
xfs_iext_insert(bma->ip, bma->idx + 1, 1, new, state);
(*nextents)++;
if (bma->cur == NULL)
rval = XFS_ILOG_CORE | XFS_ILOG_DEXT;
else {
rval = XFS_ILOG_CORE;
error = xfs_bmbt_lookup_eq(bma->cur, new->br_startoff,
new->br_startblock, new->br_blockcount,
&i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 0, done);
bma->cur->bc_rec.b.br_state = XFS_EXT_NORM;
error = xfs_btree_insert(bma->cur, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
}
if (xfs_bmap_needs_btree(bma->ip, whichfork)) {
error = xfs_bmap_extents_to_btree(bma->tp, bma->ip,
bma->firstblock, bma->dfops, &bma->cur, 1,
&tmp_rval, whichfork);
rval |= tmp_rval;
if (error)
goto done;
}
da_new = XFS_FILBLKS_MIN(xfs_bmap_worst_indlen(bma->ip, temp),
startblockval(PREV.br_startblock) -
(bma->cur ? bma->cur->bc_private.b.allocated : 0));
ep = xfs_iext_get_ext(ifp, bma->idx);
xfs_bmbt_set_startblock(ep, nullstartblock(da_new));
trace_xfs_bmap_post_update(bma->ip, bma->idx, state, _THIS_IP_);
bma->idx++;
break;
case 0:
temp = new->br_startoff - PREV.br_startoff;
temp2 = PREV.br_startoff + PREV.br_blockcount - new_endoff;
trace_xfs_bmap_pre_update(bma->ip, bma->idx, 0, _THIS_IP_);
xfs_bmbt_set_blockcount(ep, temp);
LEFT = *new;
RIGHT.br_state = PREV.br_state;
RIGHT.br_startblock = nullstartblock(
(int)xfs_bmap_worst_indlen(bma->ip, temp2));
RIGHT.br_startoff = new_endoff;
RIGHT.br_blockcount = temp2;
xfs_iext_insert(bma->ip, bma->idx + 1, 2, &LEFT, state);
(*nextents)++;
if (bma->cur == NULL)
rval = XFS_ILOG_CORE | XFS_ILOG_DEXT;
else {
rval = XFS_ILOG_CORE;
error = xfs_bmbt_lookup_eq(bma->cur, new->br_startoff,
new->br_startblock, new->br_blockcount,
&i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 0, done);
bma->cur->bc_rec.b.br_state = XFS_EXT_NORM;
error = xfs_btree_insert(bma->cur, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
}
if (xfs_bmap_needs_btree(bma->ip, whichfork)) {
error = xfs_bmap_extents_to_btree(bma->tp, bma->ip,
bma->firstblock, bma->dfops, &bma->cur,
1, &tmp_rval, whichfork);
rval |= tmp_rval;
if (error)
goto done;
}
temp = xfs_bmap_worst_indlen(bma->ip, temp);
temp2 = xfs_bmap_worst_indlen(bma->ip, temp2);
diff = (int)(temp + temp2 -
(startblockval(PREV.br_startblock) -
(bma->cur ?
bma->cur->bc_private.b.allocated : 0)));
if (diff > 0) {
error = xfs_mod_fdblocks(bma->ip->i_mount,
-((int64_t)diff), false);
ASSERT(!error);
if (error)
goto done;
}
ep = xfs_iext_get_ext(ifp, bma->idx);
xfs_bmbt_set_startblock(ep, nullstartblock((int)temp));
trace_xfs_bmap_post_update(bma->ip, bma->idx, state, _THIS_IP_);
trace_xfs_bmap_pre_update(bma->ip, bma->idx + 2, state, _THIS_IP_);
xfs_bmbt_set_startblock(xfs_iext_get_ext(ifp, bma->idx + 2),
nullstartblock((int)temp2));
trace_xfs_bmap_post_update(bma->ip, bma->idx + 2, state, _THIS_IP_);
bma->idx++;
da_new = temp + temp2;
break;
case BMAP_LEFT_FILLING | BMAP_LEFT_CONTIG | BMAP_RIGHT_CONTIG:
case BMAP_RIGHT_FILLING | BMAP_LEFT_CONTIG | BMAP_RIGHT_CONTIG:
case BMAP_LEFT_FILLING | BMAP_RIGHT_CONTIG:
case BMAP_RIGHT_FILLING | BMAP_LEFT_CONTIG:
case BMAP_LEFT_CONTIG | BMAP_RIGHT_CONTIG:
case BMAP_LEFT_CONTIG:
case BMAP_RIGHT_CONTIG:
ASSERT(0);
}
error = xfs_rmap_map_extent(mp, bma->dfops, bma->ip, whichfork, new);
if (error)
goto done;
if (xfs_bmap_needs_btree(bma->ip, whichfork)) {
int tmp_logflags;
ASSERT(bma->cur == NULL);
error = xfs_bmap_extents_to_btree(bma->tp, bma->ip,
bma->firstblock, bma->dfops, &bma->cur,
da_old > 0, &tmp_logflags, whichfork);
bma->logflags |= tmp_logflags;
if (error)
goto done;
}
if (da_old || da_new) {
temp = da_new;
if (bma->cur)
temp += bma->cur->bc_private.b.allocated;
if (temp < da_old)
xfs_mod_fdblocks(bma->ip->i_mount,
(int64_t)(da_old - temp), false);
}
if (bma->cur)
bma->cur->bc_private.b.allocated = 0;
xfs_bmap_check_leaf_extents(bma->cur, bma->ip, whichfork);
done:
if (whichfork != XFS_COW_FORK)
bma->logflags |= rval;
return error;
#undef LEFT
#undef RIGHT
#undef PREV
}
STATIC int
xfs_bmap_add_extent_unwritten_real(
struct xfs_trans *tp,
xfs_inode_t *ip,
int whichfork,
xfs_extnum_t *idx,
xfs_btree_cur_t **curp,
xfs_bmbt_irec_t *new,
xfs_fsblock_t *first,
struct xfs_defer_ops *dfops,
int *logflagsp)
{
xfs_btree_cur_t *cur;
xfs_bmbt_rec_host_t *ep;
int error;
int i;
xfs_ifork_t *ifp;
xfs_fileoff_t new_endoff;
xfs_exntst_t newext;
xfs_exntst_t oldext;
xfs_bmbt_irec_t r[3];
int rval=0;
int state = 0;
struct xfs_mount *mp = ip->i_mount;
*logflagsp = 0;
cur = *curp;
ifp = XFS_IFORK_PTR(ip, whichfork);
if (whichfork == XFS_COW_FORK)
state |= BMAP_COWFORK;
ASSERT(*idx >= 0);
ASSERT(*idx <= xfs_iext_count(ifp));
ASSERT(!isnullstartblock(new->br_startblock));
XFS_STATS_INC(mp, xs_add_exlist);
#define LEFT r[0]
#define RIGHT r[1]
#define PREV r[2]
error = 0;
ep = xfs_iext_get_ext(ifp, *idx);
xfs_bmbt_get_all(ep, &PREV);
newext = new->br_state;
oldext = (newext == XFS_EXT_UNWRITTEN) ?
XFS_EXT_NORM : XFS_EXT_UNWRITTEN;
ASSERT(PREV.br_state == oldext);
new_endoff = new->br_startoff + new->br_blockcount;
ASSERT(PREV.br_startoff <= new->br_startoff);
ASSERT(PREV.br_startoff + PREV.br_blockcount >= new_endoff);
if (PREV.br_startoff == new->br_startoff)
state |= BMAP_LEFT_FILLING;
if (PREV.br_startoff + PREV.br_blockcount == new_endoff)
state |= BMAP_RIGHT_FILLING;
if (*idx > 0) {
state |= BMAP_LEFT_VALID;
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, *idx - 1), &LEFT);
if (isnullstartblock(LEFT.br_startblock))
state |= BMAP_LEFT_DELAY;
}
if ((state & BMAP_LEFT_VALID) && !(state & BMAP_LEFT_DELAY) &&
LEFT.br_startoff + LEFT.br_blockcount == new->br_startoff &&
LEFT.br_startblock + LEFT.br_blockcount == new->br_startblock &&
LEFT.br_state == newext &&
LEFT.br_blockcount + new->br_blockcount <= MAXEXTLEN)
state |= BMAP_LEFT_CONTIG;
if (*idx < xfs_iext_count(ifp) - 1) {
state |= BMAP_RIGHT_VALID;
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, *idx + 1), &RIGHT);
if (isnullstartblock(RIGHT.br_startblock))
state |= BMAP_RIGHT_DELAY;
}
if ((state & BMAP_RIGHT_VALID) && !(state & BMAP_RIGHT_DELAY) &&
new_endoff == RIGHT.br_startoff &&
new->br_startblock + new->br_blockcount == RIGHT.br_startblock &&
newext == RIGHT.br_state &&
new->br_blockcount + RIGHT.br_blockcount <= MAXEXTLEN &&
((state & (BMAP_LEFT_CONTIG | BMAP_LEFT_FILLING |
BMAP_RIGHT_FILLING)) !=
(BMAP_LEFT_CONTIG | BMAP_LEFT_FILLING |
BMAP_RIGHT_FILLING) ||
LEFT.br_blockcount + new->br_blockcount + RIGHT.br_blockcount
<= MAXEXTLEN))
state |= BMAP_RIGHT_CONTIG;
switch (state & (BMAP_LEFT_FILLING | BMAP_LEFT_CONTIG |
BMAP_RIGHT_FILLING | BMAP_RIGHT_CONTIG)) {
case BMAP_LEFT_FILLING | BMAP_LEFT_CONTIG |
BMAP_RIGHT_FILLING | BMAP_RIGHT_CONTIG:
--*idx;
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
xfs_bmbt_set_blockcount(xfs_iext_get_ext(ifp, *idx),
LEFT.br_blockcount + PREV.br_blockcount +
RIGHT.br_blockcount);
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
xfs_iext_remove(ip, *idx + 1, 2, state);
XFS_IFORK_NEXT_SET(ip, whichfork,
XFS_IFORK_NEXTENTS(ip, whichfork) - 2);
if (cur == NULL)
rval = XFS_ILOG_CORE | XFS_ILOG_DEXT;
else {
rval = XFS_ILOG_CORE;
if ((error = xfs_bmbt_lookup_eq(cur, RIGHT.br_startoff,
RIGHT.br_startblock,
RIGHT.br_blockcount, &i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
if ((error = xfs_btree_delete(cur, &i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
if ((error = xfs_btree_decrement(cur, 0, &i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
if ((error = xfs_btree_delete(cur, &i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
if ((error = xfs_btree_decrement(cur, 0, &i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
if ((error = xfs_bmbt_update(cur, LEFT.br_startoff,
LEFT.br_startblock,
LEFT.br_blockcount + PREV.br_blockcount +
RIGHT.br_blockcount, LEFT.br_state)))
goto done;
}
break;
case BMAP_LEFT_FILLING | BMAP_RIGHT_FILLING | BMAP_LEFT_CONTIG:
--*idx;
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
xfs_bmbt_set_blockcount(xfs_iext_get_ext(ifp, *idx),
LEFT.br_blockcount + PREV.br_blockcount);
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
xfs_iext_remove(ip, *idx + 1, 1, state);
XFS_IFORK_NEXT_SET(ip, whichfork,
XFS_IFORK_NEXTENTS(ip, whichfork) - 1);
if (cur == NULL)
rval = XFS_ILOG_CORE | XFS_ILOG_DEXT;
else {
rval = XFS_ILOG_CORE;
if ((error = xfs_bmbt_lookup_eq(cur, PREV.br_startoff,
PREV.br_startblock, PREV.br_blockcount,
&i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
if ((error = xfs_btree_delete(cur, &i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
if ((error = xfs_btree_decrement(cur, 0, &i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
if ((error = xfs_bmbt_update(cur, LEFT.br_startoff,
LEFT.br_startblock,
LEFT.br_blockcount + PREV.br_blockcount,
LEFT.br_state)))
goto done;
}
break;
case BMAP_LEFT_FILLING | BMAP_RIGHT_FILLING | BMAP_RIGHT_CONTIG:
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
xfs_bmbt_set_blockcount(ep,
PREV.br_blockcount + RIGHT.br_blockcount);
xfs_bmbt_set_state(ep, newext);
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
xfs_iext_remove(ip, *idx + 1, 1, state);
XFS_IFORK_NEXT_SET(ip, whichfork,
XFS_IFORK_NEXTENTS(ip, whichfork) - 1);
if (cur == NULL)
rval = XFS_ILOG_CORE | XFS_ILOG_DEXT;
else {
rval = XFS_ILOG_CORE;
if ((error = xfs_bmbt_lookup_eq(cur, RIGHT.br_startoff,
RIGHT.br_startblock,
RIGHT.br_blockcount, &i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
if ((error = xfs_btree_delete(cur, &i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
if ((error = xfs_btree_decrement(cur, 0, &i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
if ((error = xfs_bmbt_update(cur, new->br_startoff,
new->br_startblock,
new->br_blockcount + RIGHT.br_blockcount,
newext)))
goto done;
}
break;
case BMAP_LEFT_FILLING | BMAP_RIGHT_FILLING:
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
xfs_bmbt_set_state(ep, newext);
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
if (cur == NULL)
rval = XFS_ILOG_DEXT;
else {
rval = 0;
if ((error = xfs_bmbt_lookup_eq(cur, new->br_startoff,
new->br_startblock, new->br_blockcount,
&i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
if ((error = xfs_bmbt_update(cur, new->br_startoff,
new->br_startblock, new->br_blockcount,
newext)))
goto done;
}
break;
case BMAP_LEFT_FILLING | BMAP_LEFT_CONTIG:
trace_xfs_bmap_pre_update(ip, *idx - 1, state, _THIS_IP_);
xfs_bmbt_set_blockcount(xfs_iext_get_ext(ifp, *idx - 1),
LEFT.br_blockcount + new->br_blockcount);
xfs_bmbt_set_startoff(ep,
PREV.br_startoff + new->br_blockcount);
trace_xfs_bmap_post_update(ip, *idx - 1, state, _THIS_IP_);
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
xfs_bmbt_set_startblock(ep,
new->br_startblock + new->br_blockcount);
xfs_bmbt_set_blockcount(ep,
PREV.br_blockcount - new->br_blockcount);
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
--*idx;
if (cur == NULL)
rval = XFS_ILOG_DEXT;
else {
rval = 0;
if ((error = xfs_bmbt_lookup_eq(cur, PREV.br_startoff,
PREV.br_startblock, PREV.br_blockcount,
&i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
if ((error = xfs_bmbt_update(cur,
PREV.br_startoff + new->br_blockcount,
PREV.br_startblock + new->br_blockcount,
PREV.br_blockcount - new->br_blockcount,
oldext)))
goto done;
if ((error = xfs_btree_decrement(cur, 0, &i)))
goto done;
error = xfs_bmbt_update(cur, LEFT.br_startoff,
LEFT.br_startblock,
LEFT.br_blockcount + new->br_blockcount,
LEFT.br_state);
if (error)
goto done;
}
break;
case BMAP_LEFT_FILLING:
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
ASSERT(ep && xfs_bmbt_get_state(ep) == oldext);
xfs_bmbt_set_startoff(ep, new_endoff);
xfs_bmbt_set_blockcount(ep,
PREV.br_blockcount - new->br_blockcount);
xfs_bmbt_set_startblock(ep,
new->br_startblock + new->br_blockcount);
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
xfs_iext_insert(ip, *idx, 1, new, state);
XFS_IFORK_NEXT_SET(ip, whichfork,
XFS_IFORK_NEXTENTS(ip, whichfork) + 1);
if (cur == NULL)
rval = XFS_ILOG_CORE | XFS_ILOG_DEXT;
else {
rval = XFS_ILOG_CORE;
if ((error = xfs_bmbt_lookup_eq(cur, PREV.br_startoff,
PREV.br_startblock, PREV.br_blockcount,
&i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
if ((error = xfs_bmbt_update(cur,
PREV.br_startoff + new->br_blockcount,
PREV.br_startblock + new->br_blockcount,
PREV.br_blockcount - new->br_blockcount,
oldext)))
goto done;
cur->bc_rec.b = *new;
if ((error = xfs_btree_insert(cur, &i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
}
break;
case BMAP_RIGHT_FILLING | BMAP_RIGHT_CONTIG:
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
xfs_bmbt_set_blockcount(ep,
PREV.br_blockcount - new->br_blockcount);
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
++*idx;
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
xfs_bmbt_set_allf(xfs_iext_get_ext(ifp, *idx),
new->br_startoff, new->br_startblock,
new->br_blockcount + RIGHT.br_blockcount, newext);
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
if (cur == NULL)
rval = XFS_ILOG_DEXT;
else {
rval = 0;
if ((error = xfs_bmbt_lookup_eq(cur, PREV.br_startoff,
PREV.br_startblock,
PREV.br_blockcount, &i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
if ((error = xfs_bmbt_update(cur, PREV.br_startoff,
PREV.br_startblock,
PREV.br_blockcount - new->br_blockcount,
oldext)))
goto done;
if ((error = xfs_btree_increment(cur, 0, &i)))
goto done;
if ((error = xfs_bmbt_update(cur, new->br_startoff,
new->br_startblock,
new->br_blockcount + RIGHT.br_blockcount,
newext)))
goto done;
}
break;
case BMAP_RIGHT_FILLING:
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
xfs_bmbt_set_blockcount(ep,
PREV.br_blockcount - new->br_blockcount);
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
++*idx;
xfs_iext_insert(ip, *idx, 1, new, state);
XFS_IFORK_NEXT_SET(ip, whichfork,
XFS_IFORK_NEXTENTS(ip, whichfork) + 1);
if (cur == NULL)
rval = XFS_ILOG_CORE | XFS_ILOG_DEXT;
else {
rval = XFS_ILOG_CORE;
if ((error = xfs_bmbt_lookup_eq(cur, PREV.br_startoff,
PREV.br_startblock, PREV.br_blockcount,
&i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
if ((error = xfs_bmbt_update(cur, PREV.br_startoff,
PREV.br_startblock,
PREV.br_blockcount - new->br_blockcount,
oldext)))
goto done;
if ((error = xfs_bmbt_lookup_eq(cur, new->br_startoff,
new->br_startblock, new->br_blockcount,
&i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 0, done);
cur->bc_rec.b.br_state = XFS_EXT_NORM;
if ((error = xfs_btree_insert(cur, &i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
}
break;
case 0:
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
xfs_bmbt_set_blockcount(ep,
new->br_startoff - PREV.br_startoff);
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
r[0] = *new;
r[1].br_startoff = new_endoff;
r[1].br_blockcount =
PREV.br_startoff + PREV.br_blockcount - new_endoff;
r[1].br_startblock = new->br_startblock + new->br_blockcount;
r[1].br_state = oldext;
++*idx;
xfs_iext_insert(ip, *idx, 2, &r[0], state);
XFS_IFORK_NEXT_SET(ip, whichfork,
XFS_IFORK_NEXTENTS(ip, whichfork) + 2);
if (cur == NULL)
rval = XFS_ILOG_CORE | XFS_ILOG_DEXT;
else {
rval = XFS_ILOG_CORE;
if ((error = xfs_bmbt_lookup_eq(cur, PREV.br_startoff,
PREV.br_startblock, PREV.br_blockcount,
&i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
if ((error = xfs_bmbt_update(cur, r[1].br_startoff,
r[1].br_startblock, r[1].br_blockcount,
r[1].br_state)))
goto done;
cur->bc_rec.b = PREV;
cur->bc_rec.b.br_blockcount =
new->br_startoff - PREV.br_startoff;
if ((error = xfs_btree_insert(cur, &i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
if ((error = xfs_bmbt_lookup_eq(cur, new->br_startoff,
new->br_startblock, new->br_blockcount,
&i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 0, done);
cur->bc_rec.b.br_state = new->br_state;
if ((error = xfs_btree_insert(cur, &i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
}
break;
case BMAP_LEFT_FILLING | BMAP_LEFT_CONTIG | BMAP_RIGHT_CONTIG:
case BMAP_RIGHT_FILLING | BMAP_LEFT_CONTIG | BMAP_RIGHT_CONTIG:
case BMAP_LEFT_FILLING | BMAP_RIGHT_CONTIG:
case BMAP_RIGHT_FILLING | BMAP_LEFT_CONTIG:
case BMAP_LEFT_CONTIG | BMAP_RIGHT_CONTIG:
case BMAP_LEFT_CONTIG:
case BMAP_RIGHT_CONTIG:
ASSERT(0);
}
error = xfs_rmap_convert_extent(mp, dfops, ip, whichfork, new);
if (error)
goto done;
if (xfs_bmap_needs_btree(ip, whichfork)) {
int tmp_logflags;
ASSERT(cur == NULL);
error = xfs_bmap_extents_to_btree(tp, ip, first, dfops, &cur,
0, &tmp_logflags, whichfork);
*logflagsp |= tmp_logflags;
if (error)
goto done;
}
if (cur) {
cur->bc_private.b.allocated = 0;
*curp = cur;
}
xfs_bmap_check_leaf_extents(*curp, ip, whichfork);
done:
*logflagsp |= rval;
return error;
#undef LEFT
#undef RIGHT
#undef PREV
}
STATIC void
xfs_bmap_add_extent_hole_delay(
xfs_inode_t *ip,
int whichfork,
xfs_extnum_t *idx,
xfs_bmbt_irec_t *new)
{
xfs_ifork_t *ifp;
xfs_bmbt_irec_t left;
xfs_filblks_t newlen=0;
xfs_filblks_t oldlen=0;
xfs_bmbt_irec_t right;
int state;
xfs_filblks_t temp=0;
ifp = XFS_IFORK_PTR(ip, whichfork);
state = 0;
if (whichfork == XFS_COW_FORK)
state |= BMAP_COWFORK;
ASSERT(isnullstartblock(new->br_startblock));
if (*idx > 0) {
state |= BMAP_LEFT_VALID;
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, *idx - 1), &left);
if (isnullstartblock(left.br_startblock))
state |= BMAP_LEFT_DELAY;
}
if (*idx < xfs_iext_count(ifp)) {
state |= BMAP_RIGHT_VALID;
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, *idx), &right);
if (isnullstartblock(right.br_startblock))
state |= BMAP_RIGHT_DELAY;
}
if ((state & BMAP_LEFT_VALID) && (state & BMAP_LEFT_DELAY) &&
left.br_startoff + left.br_blockcount == new->br_startoff &&
left.br_blockcount + new->br_blockcount <= MAXEXTLEN)
state |= BMAP_LEFT_CONTIG;
if ((state & BMAP_RIGHT_VALID) && (state & BMAP_RIGHT_DELAY) &&
new->br_startoff + new->br_blockcount == right.br_startoff &&
new->br_blockcount + right.br_blockcount <= MAXEXTLEN &&
(!(state & BMAP_LEFT_CONTIG) ||
(left.br_blockcount + new->br_blockcount +
right.br_blockcount <= MAXEXTLEN)))
state |= BMAP_RIGHT_CONTIG;
switch (state & (BMAP_LEFT_CONTIG | BMAP_RIGHT_CONTIG)) {
case BMAP_LEFT_CONTIG | BMAP_RIGHT_CONTIG:
--*idx;
temp = left.br_blockcount + new->br_blockcount +
right.br_blockcount;
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
xfs_bmbt_set_blockcount(xfs_iext_get_ext(ifp, *idx), temp);
oldlen = startblockval(left.br_startblock) +
startblockval(new->br_startblock) +
startblockval(right.br_startblock);
newlen = XFS_FILBLKS_MIN(xfs_bmap_worst_indlen(ip, temp),
oldlen);
xfs_bmbt_set_startblock(xfs_iext_get_ext(ifp, *idx),
nullstartblock((int)newlen));
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
xfs_iext_remove(ip, *idx + 1, 1, state);
break;
case BMAP_LEFT_CONTIG:
--*idx;
temp = left.br_blockcount + new->br_blockcount;
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
xfs_bmbt_set_blockcount(xfs_iext_get_ext(ifp, *idx), temp);
oldlen = startblockval(left.br_startblock) +
startblockval(new->br_startblock);
newlen = XFS_FILBLKS_MIN(xfs_bmap_worst_indlen(ip, temp),
oldlen);
xfs_bmbt_set_startblock(xfs_iext_get_ext(ifp, *idx),
nullstartblock((int)newlen));
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
break;
case BMAP_RIGHT_CONTIG:
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
temp = new->br_blockcount + right.br_blockcount;
oldlen = startblockval(new->br_startblock) +
startblockval(right.br_startblock);
newlen = XFS_FILBLKS_MIN(xfs_bmap_worst_indlen(ip, temp),
oldlen);
xfs_bmbt_set_allf(xfs_iext_get_ext(ifp, *idx),
new->br_startoff,
nullstartblock((int)newlen), temp, right.br_state);
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
break;
case 0:
oldlen = newlen = 0;
xfs_iext_insert(ip, *idx, 1, new, state);
break;
}
if (oldlen != newlen) {
ASSERT(oldlen > newlen);
xfs_mod_fdblocks(ip->i_mount, (int64_t)(oldlen - newlen),
false);
}
}
STATIC int
xfs_bmap_add_extent_hole_real(
struct xfs_trans *tp,
struct xfs_inode *ip,
int whichfork,
xfs_extnum_t *idx,
struct xfs_btree_cur **curp,
struct xfs_bmbt_irec *new,
xfs_fsblock_t *first,
struct xfs_defer_ops *dfops,
int *logflagsp)
{
struct xfs_ifork *ifp = XFS_IFORK_PTR(ip, whichfork);
struct xfs_mount *mp = ip->i_mount;
struct xfs_btree_cur *cur = *curp;
int error;
int i;
xfs_bmbt_irec_t left;
xfs_bmbt_irec_t right;
int rval=0;
int state;
ASSERT(*idx >= 0);
ASSERT(*idx <= xfs_iext_count(ifp));
ASSERT(!isnullstartblock(new->br_startblock));
ASSERT(!cur || !(cur->bc_private.b.flags & XFS_BTCUR_BPRV_WASDEL));
XFS_STATS_INC(mp, xs_add_exlist);
state = 0;
if (whichfork == XFS_ATTR_FORK)
state |= BMAP_ATTRFORK;
if (whichfork == XFS_COW_FORK)
state |= BMAP_COWFORK;
if (*idx > 0) {
state |= BMAP_LEFT_VALID;
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, *idx - 1), &left);
if (isnullstartblock(left.br_startblock))
state |= BMAP_LEFT_DELAY;
}
if (*idx < xfs_iext_count(ifp)) {
state |= BMAP_RIGHT_VALID;
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, *idx), &right);
if (isnullstartblock(right.br_startblock))
state |= BMAP_RIGHT_DELAY;
}
if ((state & BMAP_LEFT_VALID) && !(state & BMAP_LEFT_DELAY) &&
left.br_startoff + left.br_blockcount == new->br_startoff &&
left.br_startblock + left.br_blockcount == new->br_startblock &&
left.br_state == new->br_state &&
left.br_blockcount + new->br_blockcount <= MAXEXTLEN)
state |= BMAP_LEFT_CONTIG;
if ((state & BMAP_RIGHT_VALID) && !(state & BMAP_RIGHT_DELAY) &&
new->br_startoff + new->br_blockcount == right.br_startoff &&
new->br_startblock + new->br_blockcount == right.br_startblock &&
new->br_state == right.br_state &&
new->br_blockcount + right.br_blockcount <= MAXEXTLEN &&
(!(state & BMAP_LEFT_CONTIG) ||
left.br_blockcount + new->br_blockcount +
right.br_blockcount <= MAXEXTLEN))
state |= BMAP_RIGHT_CONTIG;
error = 0;
switch (state & (BMAP_LEFT_CONTIG | BMAP_RIGHT_CONTIG)) {
case BMAP_LEFT_CONTIG | BMAP_RIGHT_CONTIG:
--*idx;
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
xfs_bmbt_set_blockcount(xfs_iext_get_ext(ifp, *idx),
left.br_blockcount + new->br_blockcount +
right.br_blockcount);
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
xfs_iext_remove(ip, *idx + 1, 1, state);
XFS_IFORK_NEXT_SET(ip, whichfork,
XFS_IFORK_NEXTENTS(ip, whichfork) - 1);
if (cur == NULL) {
rval = XFS_ILOG_CORE | xfs_ilog_fext(whichfork);
} else {
rval = XFS_ILOG_CORE;
error = xfs_bmbt_lookup_eq(cur, right.br_startoff,
right.br_startblock, right.br_blockcount,
&i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
error = xfs_btree_delete(cur, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
error = xfs_btree_decrement(cur, 0, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
error = xfs_bmbt_update(cur, left.br_startoff,
left.br_startblock,
left.br_blockcount +
new->br_blockcount +
right.br_blockcount,
left.br_state);
if (error)
goto done;
}
break;
case BMAP_LEFT_CONTIG:
--*idx;
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
xfs_bmbt_set_blockcount(xfs_iext_get_ext(ifp, *idx),
left.br_blockcount + new->br_blockcount);
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
if (cur == NULL) {
rval = xfs_ilog_fext(whichfork);
} else {
rval = 0;
error = xfs_bmbt_lookup_eq(cur, left.br_startoff,
left.br_startblock, left.br_blockcount,
&i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
error = xfs_bmbt_update(cur, left.br_startoff,
left.br_startblock,
left.br_blockcount +
new->br_blockcount,
left.br_state);
if (error)
goto done;
}
break;
case BMAP_RIGHT_CONTIG:
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
xfs_bmbt_set_allf(xfs_iext_get_ext(ifp, *idx),
new->br_startoff, new->br_startblock,
new->br_blockcount + right.br_blockcount,
right.br_state);
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
if (cur == NULL) {
rval = xfs_ilog_fext(whichfork);
} else {
rval = 0;
error = xfs_bmbt_lookup_eq(cur,
right.br_startoff,
right.br_startblock,
right.br_blockcount, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
error = xfs_bmbt_update(cur, new->br_startoff,
new->br_startblock,
new->br_blockcount +
right.br_blockcount,
right.br_state);
if (error)
goto done;
}
break;
case 0:
xfs_iext_insert(ip, *idx, 1, new, state);
XFS_IFORK_NEXT_SET(ip, whichfork,
XFS_IFORK_NEXTENTS(ip, whichfork) + 1);
if (cur == NULL) {
rval = XFS_ILOG_CORE | xfs_ilog_fext(whichfork);
} else {
rval = XFS_ILOG_CORE;
error = xfs_bmbt_lookup_eq(cur,
new->br_startoff,
new->br_startblock,
new->br_blockcount, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 0, done);
cur->bc_rec.b.br_state = new->br_state;
error = xfs_btree_insert(cur, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
}
break;
}
error = xfs_rmap_map_extent(mp, dfops, ip, whichfork, new);
if (error)
goto done;
if (xfs_bmap_needs_btree(ip, whichfork)) {
int tmp_logflags;
ASSERT(cur == NULL);
error = xfs_bmap_extents_to_btree(tp, ip, first, dfops, curp,
0, &tmp_logflags, whichfork);
*logflagsp |= tmp_logflags;
cur = *curp;
if (error)
goto done;
}
if (cur)
cur->bc_private.b.allocated = 0;
xfs_bmap_check_leaf_extents(cur, ip, whichfork);
done:
*logflagsp |= rval;
return error;
}
int
xfs_bmap_extsize_align(
xfs_mount_t *mp,
xfs_bmbt_irec_t *gotp,
xfs_bmbt_irec_t *prevp,
xfs_extlen_t extsz,
int rt,
int eof,
int delay,
int convert,
xfs_fileoff_t *offp,
xfs_extlen_t *lenp)
{
xfs_fileoff_t orig_off;
xfs_extlen_t orig_alen;
xfs_fileoff_t orig_end;
xfs_fileoff_t nexto;
xfs_fileoff_t prevo;
xfs_fileoff_t align_off;
xfs_extlen_t align_alen;
xfs_extlen_t temp;
if (convert)
return 0;
orig_off = align_off = *offp;
orig_alen = align_alen = *lenp;
orig_end = orig_off + orig_alen;
if (!delay && !eof &&
(orig_off >= gotp->br_startoff) &&
(orig_end <= gotp->br_startoff + gotp->br_blockcount)) {
return 0;
}
temp = do_mod(orig_off, extsz);
if (temp) {
align_alen += temp;
align_off -= temp;
}
temp = (align_alen % extsz);
if (temp)
align_alen += extsz - temp;
while (align_alen > MAXEXTLEN)
align_alen -= extsz;
ASSERT(align_alen <= MAXEXTLEN);
if (prevp->br_startoff != NULLFILEOFF) {
if (prevp->br_startblock == HOLESTARTBLOCK)
prevo = prevp->br_startoff;
else
prevo = prevp->br_startoff + prevp->br_blockcount;
} else
prevo = 0;
if (align_off != orig_off && align_off < prevo)
align_off = prevo;
if (!eof && gotp->br_startoff != NULLFILEOFF) {
if ((delay && gotp->br_startblock == HOLESTARTBLOCK) ||
(!delay && gotp->br_startblock == DELAYSTARTBLOCK))
nexto = gotp->br_startoff + gotp->br_blockcount;
else
nexto = gotp->br_startoff;
} else
nexto = NULLFILEOFF;
if (!eof &&
align_off + align_alen != orig_end &&
align_off + align_alen > nexto)
align_off = nexto > align_alen ? nexto - align_alen : 0;
if (align_off != orig_off && align_off < prevo)
align_off = prevo;
if (align_off + align_alen != orig_end &&
align_off + align_alen > nexto &&
nexto != NULLFILEOFF) {
ASSERT(nexto > prevo);
align_alen = nexto - align_off;
}
if (rt && (temp = (align_alen % mp->m_sb.sb_rextsize))) {
if (orig_off < align_off ||
orig_end > align_off + align_alen ||
align_alen - temp < orig_alen)
return -EINVAL;
if (align_off + temp <= orig_off) {
align_alen -= temp;
align_off += temp;
}
else if (align_off + align_alen - temp >= orig_end)
align_alen -= temp;
else {
align_alen -= orig_off - align_off;
align_off = orig_off;
align_alen -= align_alen % mp->m_sb.sb_rextsize;
}
if (orig_off < align_off || orig_end > align_off + align_alen)
return -EINVAL;
} else {
ASSERT(orig_off >= align_off);
ASSERT(orig_end <= align_off + align_alen ||
align_alen + extsz > MAXEXTLEN);
}
#ifdef DEBUG
if (!eof && gotp->br_startoff != NULLFILEOFF)
ASSERT(align_off + align_alen <= gotp->br_startoff);
if (prevp->br_startoff != NULLFILEOFF)
ASSERT(align_off >= prevp->br_startoff + prevp->br_blockcount);
#endif
*lenp = align_alen;
*offp = align_off;
return 0;
}
void
xfs_bmap_adjacent(
struct xfs_bmalloca *ap)
{
xfs_fsblock_t adjust;
xfs_agnumber_t fb_agno;
xfs_mount_t *mp;
int nullfb;
int rt;
#define ISVALID(x,y) \
(rt ? \
(x) < mp->m_sb.sb_rblocks : \
XFS_FSB_TO_AGNO(mp, x) == XFS_FSB_TO_AGNO(mp, y) && \
XFS_FSB_TO_AGNO(mp, x) < mp->m_sb.sb_agcount && \
XFS_FSB_TO_AGBNO(mp, x) < mp->m_sb.sb_agblocks)
mp = ap->ip->i_mount;
nullfb = *ap->firstblock == NULLFSBLOCK;
rt = XFS_IS_REALTIME_INODE(ap->ip) &&
xfs_alloc_is_userdata(ap->datatype);
fb_agno = nullfb ? NULLAGNUMBER : XFS_FSB_TO_AGNO(mp, *ap->firstblock);
if (ap->eof && ap->prev.br_startoff != NULLFILEOFF &&
!isnullstartblock(ap->prev.br_startblock) &&
ISVALID(ap->prev.br_startblock + ap->prev.br_blockcount,
ap->prev.br_startblock)) {
ap->blkno = ap->prev.br_startblock + ap->prev.br_blockcount;
adjust = ap->offset -
(ap->prev.br_startoff + ap->prev.br_blockcount);
if (adjust &&
ISVALID(ap->blkno + adjust, ap->prev.br_startblock))
ap->blkno += adjust;
}
else if (!ap->eof) {
xfs_fsblock_t gotbno;
xfs_fsblock_t gotdiff=0;
xfs_fsblock_t prevbno;
xfs_fsblock_t prevdiff=0;
if (ap->prev.br_startoff != NULLFILEOFF &&
!isnullstartblock(ap->prev.br_startblock) &&
(prevbno = ap->prev.br_startblock +
ap->prev.br_blockcount) &&
ISVALID(prevbno, ap->prev.br_startblock)) {
adjust = prevdiff = ap->offset -
(ap->prev.br_startoff +
ap->prev.br_blockcount);
if (prevdiff <= XFS_ALLOC_GAP_UNITS * ap->length &&
ISVALID(prevbno + prevdiff,
ap->prev.br_startblock))
prevbno += adjust;
else
prevdiff += adjust;
if (!rt && !nullfb &&
XFS_FSB_TO_AGNO(mp, prevbno) != fb_agno)
prevbno = NULLFSBLOCK;
}
else
prevbno = NULLFSBLOCK;
if (!isnullstartblock(ap->got.br_startblock)) {
adjust = gotdiff = ap->got.br_startoff - ap->offset;
gotbno = ap->got.br_startblock;
if (gotdiff <= XFS_ALLOC_GAP_UNITS * ap->length &&
ISVALID(gotbno - gotdiff, gotbno))
gotbno -= adjust;
else if (ISVALID(gotbno - ap->length, gotbno)) {
gotbno -= ap->length;
gotdiff += adjust - ap->length;
} else
gotdiff += adjust;
if (!rt && !nullfb &&
XFS_FSB_TO_AGNO(mp, gotbno) != fb_agno)
gotbno = NULLFSBLOCK;
}
else
gotbno = NULLFSBLOCK;
if (prevbno != NULLFSBLOCK && gotbno != NULLFSBLOCK)
ap->blkno = prevdiff <= gotdiff ? prevbno : gotbno;
else if (prevbno != NULLFSBLOCK)
ap->blkno = prevbno;
else if (gotbno != NULLFSBLOCK)
ap->blkno = gotbno;
}
#undef ISVALID
}
static int
xfs_bmap_longest_free_extent(
struct xfs_trans *tp,
xfs_agnumber_t ag,
xfs_extlen_t *blen,
int *notinit)
{
struct xfs_mount *mp = tp->t_mountp;
struct xfs_perag *pag;
xfs_extlen_t longest;
int error = 0;
pag = xfs_perag_get(mp, ag);
if (!pag->pagf_init) {
error = xfs_alloc_pagf_init(mp, tp, ag, XFS_ALLOC_FLAG_TRYLOCK);
if (error)
goto out;
if (!pag->pagf_init) {
*notinit = 1;
goto out;
}
}
longest = xfs_alloc_longest_free_extent(mp, pag,
xfs_alloc_min_freelist(mp, pag),
xfs_ag_resv_needed(pag, XFS_AG_RESV_NONE));
if (*blen < longest)
*blen = longest;
out:
xfs_perag_put(pag);
return error;
}
static void
xfs_bmap_select_minlen(
struct xfs_bmalloca *ap,
struct xfs_alloc_arg *args,
xfs_extlen_t *blen,
int notinit)
{
if (notinit || *blen < ap->minlen) {
args->minlen = ap->minlen;
} else if (*blen < args->maxlen) {
args->minlen = *blen;
} else {
args->minlen = args->maxlen;
}
}
STATIC int
xfs_bmap_btalloc_nullfb(
struct xfs_bmalloca *ap,
struct xfs_alloc_arg *args,
xfs_extlen_t *blen)
{
struct xfs_mount *mp = ap->ip->i_mount;
xfs_agnumber_t ag, startag;
int notinit = 0;
int error;
args->type = XFS_ALLOCTYPE_START_BNO;
args->total = ap->total;
startag = ag = XFS_FSB_TO_AGNO(mp, args->fsbno);
if (startag == NULLAGNUMBER)
startag = ag = 0;
while (*blen < args->maxlen) {
error = xfs_bmap_longest_free_extent(args->tp, ag, blen,
&notinit);
if (error)
return error;
if (++ag == mp->m_sb.sb_agcount)
ag = 0;
if (ag == startag)
break;
}
xfs_bmap_select_minlen(ap, args, blen, notinit);
return 0;
}
STATIC int
xfs_bmap_btalloc_filestreams(
struct xfs_bmalloca *ap,
struct xfs_alloc_arg *args,
xfs_extlen_t *blen)
{
struct xfs_mount *mp = ap->ip->i_mount;
xfs_agnumber_t ag;
int notinit = 0;
int error;
args->type = XFS_ALLOCTYPE_NEAR_BNO;
args->total = ap->total;
ag = XFS_FSB_TO_AGNO(mp, args->fsbno);
if (ag == NULLAGNUMBER)
ag = 0;
error = xfs_bmap_longest_free_extent(args->tp, ag, blen, &notinit);
if (error)
return error;
if (*blen < args->maxlen) {
error = xfs_filestream_new_ag(ap, &ag);
if (error)
return error;
error = xfs_bmap_longest_free_extent(args->tp, ag, blen,
&notinit);
if (error)
return error;
}
xfs_bmap_select_minlen(ap, args, blen, notinit);
ap->blkno = args->fsbno = XFS_AGB_TO_FSB(mp, ag, 0);
return 0;
}
STATIC int
xfs_bmap_btalloc(
struct xfs_bmalloca *ap)
{
xfs_mount_t *mp;
xfs_alloctype_t atype = 0;
xfs_extlen_t align = 0;
xfs_agnumber_t fb_agno;
xfs_agnumber_t ag;
xfs_alloc_arg_t args;
xfs_extlen_t blen;
xfs_extlen_t nextminlen = 0;
int nullfb;
int isaligned;
int tryagain;
int error;
int stripe_align;
ASSERT(ap->length);
mp = ap->ip->i_mount;
stripe_align = 0;
if (mp->m_swidth && (mp->m_flags & XFS_MOUNT_SWALLOC))
stripe_align = mp->m_swidth;
else if (mp->m_dalign)
stripe_align = mp->m_dalign;
if (ap->flags & XFS_BMAPI_COWFORK)
align = xfs_get_cowextsz_hint(ap->ip);
else if (xfs_alloc_is_userdata(ap->datatype))
align = xfs_get_extsz_hint(ap->ip);
if (align) {
error = xfs_bmap_extsize_align(mp, &ap->got, &ap->prev,
align, 0, ap->eof, 0, ap->conv,
&ap->offset, &ap->length);
ASSERT(!error);
ASSERT(ap->length);
}
nullfb = *ap->firstblock == NULLFSBLOCK;
fb_agno = nullfb ? NULLAGNUMBER : XFS_FSB_TO_AGNO(mp, *ap->firstblock);
if (nullfb) {
if (xfs_alloc_is_userdata(ap->datatype) &&
xfs_inode_is_filestream(ap->ip)) {
ag = xfs_filestream_lookup_ag(ap->ip);
ag = (ag != NULLAGNUMBER) ? ag : 0;
ap->blkno = XFS_AGB_TO_FSB(mp, ag, 0);
} else {
ap->blkno = XFS_INO_TO_FSB(mp, ap->ip->i_ino);
}
} else
ap->blkno = *ap->firstblock;
xfs_bmap_adjacent(ap);
if (nullfb || XFS_FSB_TO_AGNO(mp, ap->blkno) == fb_agno)
;
else
ap->blkno = *ap->firstblock;
tryagain = isaligned = 0;
memset(&args, 0, sizeof(args));
args.tp = ap->tp;
args.mp = mp;
args.fsbno = ap->blkno;
xfs_rmap_skip_owner_update(&args.oinfo);
args.maxlen = MIN(ap->length, mp->m_ag_max_usable);
args.firstblock = *ap->firstblock;
blen = 0;
if (nullfb) {
if (xfs_alloc_is_userdata(ap->datatype) &&
xfs_inode_is_filestream(ap->ip))
error = xfs_bmap_btalloc_filestreams(ap, &args, &blen);
else
error = xfs_bmap_btalloc_nullfb(ap, &args, &blen);
if (error)
return error;
} else if (ap->dfops->dop_low) {
if (xfs_inode_is_filestream(ap->ip))
args.type = XFS_ALLOCTYPE_FIRST_AG;
else
args.type = XFS_ALLOCTYPE_START_BNO;
args.total = args.minlen = ap->minlen;
} else {
args.type = XFS_ALLOCTYPE_NEAR_BNO;
args.total = ap->total;
args.minlen = ap->minlen;
}
if (align) {
args.prod = align;
if ((args.mod = (xfs_extlen_t)do_mod(ap->offset, args.prod)))
args.mod = (xfs_extlen_t)(args.prod - args.mod);
} else if (mp->m_sb.sb_blocksize >= PAGE_SIZE) {
args.prod = 1;
args.mod = 0;
} else {
args.prod = PAGE_SIZE >> mp->m_sb.sb_blocklog;
if ((args.mod = (xfs_extlen_t)(do_mod(ap->offset, args.prod))))
args.mod = (xfs_extlen_t)(args.prod - args.mod);
}
if (!ap->dfops->dop_low && ap->aeof) {
if (!ap->offset) {
args.alignment = stripe_align;
atype = args.type;
isaligned = 1;
if (blen > args.alignment && blen <= args.maxlen)
args.minlen = blen - args.alignment;
args.minalignslop = 0;
} else {
atype = args.type;
tryagain = 1;
args.type = XFS_ALLOCTYPE_THIS_BNO;
args.alignment = 1;
if (blen > stripe_align && blen <= args.maxlen)
nextminlen = blen - stripe_align;
else
nextminlen = args.minlen;
if (nextminlen + stripe_align > args.minlen + 1)
args.minalignslop =
nextminlen + stripe_align -
args.minlen - 1;
else
args.minalignslop = 0;
}
} else {
args.alignment = 1;
args.minalignslop = 0;
}
args.minleft = ap->minleft;
args.wasdel = ap->wasdel;
args.resv = XFS_AG_RESV_NONE;
args.datatype = ap->datatype;
if (ap->datatype & XFS_ALLOC_USERDATA_ZERO)
args.ip = ap->ip;
error = xfs_alloc_vextent(&args);
if (error)
return error;
if (tryagain && args.fsbno == NULLFSBLOCK) {
args.type = atype;
args.fsbno = ap->blkno;
args.alignment = stripe_align;
args.minlen = nextminlen;
args.minalignslop = 0;
isaligned = 1;
if ((error = xfs_alloc_vextent(&args)))
return error;
}
if (isaligned && args.fsbno == NULLFSBLOCK) {
args.type = atype;
args.fsbno = ap->blkno;
args.alignment = 0;
if ((error = xfs_alloc_vextent(&args)))
return error;
}
if (args.fsbno == NULLFSBLOCK && nullfb &&
args.minlen > ap->minlen) {
args.minlen = ap->minlen;
args.type = XFS_ALLOCTYPE_START_BNO;
args.fsbno = ap->blkno;
if ((error = xfs_alloc_vextent(&args)))
return error;
}
if (args.fsbno == NULLFSBLOCK && nullfb) {
args.fsbno = 0;
args.type = XFS_ALLOCTYPE_FIRST_AG;
args.total = ap->minlen;
if ((error = xfs_alloc_vextent(&args)))
return error;
ap->dfops->dop_low = true;
}
if (args.fsbno != NULLFSBLOCK) {
ASSERT(*ap->firstblock == NULLFSBLOCK ||
XFS_FSB_TO_AGNO(mp, *ap->firstblock) <=
XFS_FSB_TO_AGNO(mp, args.fsbno));
ap->blkno = args.fsbno;
if (*ap->firstblock == NULLFSBLOCK)
*ap->firstblock = args.fsbno;
ASSERT(nullfb || fb_agno <= args.agno);
ap->length = args.len;
if (!(ap->flags & XFS_BMAPI_COWFORK))
ap->ip->i_d.di_nblocks += args.len;
xfs_trans_log_inode(ap->tp, ap->ip, XFS_ILOG_CORE);
if (ap->wasdel)
ap->ip->i_delayed_blks -= args.len;
xfs_trans_mod_dquot_byino(ap->tp, ap->ip,
ap->wasdel ? XFS_TRANS_DQ_DELBCOUNT :
XFS_TRANS_DQ_BCOUNT,
(long) args.len);
} else {
ap->blkno = NULLFSBLOCK;
ap->length = 0;
}
return 0;
}
STATIC int
xfs_bmap_alloc(
struct xfs_bmalloca *ap)
{
if (XFS_IS_REALTIME_INODE(ap->ip) &&
xfs_alloc_is_userdata(ap->datatype))
return xfs_bmap_rtalloc(ap);
return xfs_bmap_btalloc(ap);
}
void
xfs_trim_extent(
struct xfs_bmbt_irec *irec,
xfs_fileoff_t bno,
xfs_filblks_t len)
{
xfs_fileoff_t distance;
xfs_fileoff_t end = bno + len;
if (irec->br_startoff + irec->br_blockcount <= bno ||
irec->br_startoff >= end) {
irec->br_blockcount = 0;
return;
}
if (irec->br_startoff < bno) {
distance = bno - irec->br_startoff;
if (isnullstartblock(irec->br_startblock))
irec->br_startblock = DELAYSTARTBLOCK;
if (irec->br_startblock != DELAYSTARTBLOCK &&
irec->br_startblock != HOLESTARTBLOCK)
irec->br_startblock += distance;
irec->br_startoff += distance;
irec->br_blockcount -= distance;
}
if (end < irec->br_startoff + irec->br_blockcount) {
distance = irec->br_startoff + irec->br_blockcount - end;
irec->br_blockcount -= distance;
}
}
void
xfs_trim_extent_eof(
struct xfs_bmbt_irec *irec,
struct xfs_inode *ip)
{
xfs_trim_extent(irec, 0, XFS_B_TO_FSB(ip->i_mount,
i_size_read(VFS_I(ip))));
}
STATIC void
xfs_bmapi_trim_map(
struct xfs_bmbt_irec *mval,
struct xfs_bmbt_irec *got,
xfs_fileoff_t *bno,
xfs_filblks_t len,
xfs_fileoff_t obno,
xfs_fileoff_t end,
int n,
int flags)
{
if ((flags & XFS_BMAPI_ENTIRE) ||
got->br_startoff + got->br_blockcount <= obno) {
*mval = *got;
if (isnullstartblock(got->br_startblock))
mval->br_startblock = DELAYSTARTBLOCK;
return;
}
if (obno > *bno)
*bno = obno;
ASSERT((*bno >= obno) || (n == 0));
ASSERT(*bno < end);
mval->br_startoff = *bno;
if (isnullstartblock(got->br_startblock))
mval->br_startblock = DELAYSTARTBLOCK;
else
mval->br_startblock = got->br_startblock +
(*bno - got->br_startoff);
mval->br_blockcount = XFS_FILBLKS_MIN(end - *bno,
got->br_blockcount - (*bno - got->br_startoff));
mval->br_state = got->br_state;
ASSERT(mval->br_blockcount <= len);
return;
}
STATIC void
xfs_bmapi_update_map(
struct xfs_bmbt_irec **map,
xfs_fileoff_t *bno,
xfs_filblks_t *len,
xfs_fileoff_t obno,
xfs_fileoff_t end,
int *n,
int flags)
{
xfs_bmbt_irec_t *mval = *map;
ASSERT((flags & XFS_BMAPI_ENTIRE) ||
((mval->br_startoff + mval->br_blockcount) <= end));
ASSERT((flags & XFS_BMAPI_ENTIRE) || (mval->br_blockcount <= *len) ||
(mval->br_startoff < obno));
*bno = mval->br_startoff + mval->br_blockcount;
*len = end - *bno;
if (*n > 0 && mval->br_startoff == mval[-1].br_startoff) {
ASSERT(mval->br_startblock == mval[-1].br_startblock);
ASSERT(mval->br_blockcount > mval[-1].br_blockcount);
ASSERT(mval->br_state == mval[-1].br_state);
mval[-1].br_blockcount = mval->br_blockcount;
mval[-1].br_state = mval->br_state;
} else if (*n > 0 && mval->br_startblock != DELAYSTARTBLOCK &&
mval[-1].br_startblock != DELAYSTARTBLOCK &&
mval[-1].br_startblock != HOLESTARTBLOCK &&
mval->br_startblock == mval[-1].br_startblock +
mval[-1].br_blockcount &&
((flags & XFS_BMAPI_IGSTATE) ||
mval[-1].br_state == mval->br_state)) {
ASSERT(mval->br_startoff ==
mval[-1].br_startoff + mval[-1].br_blockcount);
mval[-1].br_blockcount += mval->br_blockcount;
} else if (*n > 0 &&
mval->br_startblock == DELAYSTARTBLOCK &&
mval[-1].br_startblock == DELAYSTARTBLOCK &&
mval->br_startoff ==
mval[-1].br_startoff + mval[-1].br_blockcount) {
mval[-1].br_blockcount += mval->br_blockcount;
mval[-1].br_state = mval->br_state;
} else if (!((*n == 0) &&
((mval->br_startoff + mval->br_blockcount) <=
obno))) {
mval++;
(*n)++;
}
*map = mval;
}
int
xfs_bmapi_read(
struct xfs_inode *ip,
xfs_fileoff_t bno,
xfs_filblks_t len,
struct xfs_bmbt_irec *mval,
int *nmap,
int flags)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_ifork *ifp;
struct xfs_bmbt_irec got;
xfs_fileoff_t obno;
xfs_fileoff_t end;
xfs_extnum_t idx;
int error;
bool eof = false;
int n = 0;
int whichfork = xfs_bmapi_whichfork(flags);
ASSERT(*nmap >= 1);
ASSERT(!(flags & ~(XFS_BMAPI_ATTRFORK|XFS_BMAPI_ENTIRE|
XFS_BMAPI_IGSTATE|XFS_BMAPI_COWFORK)));
ASSERT(xfs_isilocked(ip, XFS_ILOCK_SHARED|XFS_ILOCK_EXCL));
if (unlikely(XFS_TEST_ERROR(
(XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_EXTENTS &&
XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_BTREE),
mp, XFS_ERRTAG_BMAPIFORMAT))) {
XFS_ERROR_REPORT("xfs_bmapi_read", XFS_ERRLEVEL_LOW, mp);
return -EFSCORRUPTED;
}
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
XFS_STATS_INC(mp, xs_blk_mapr);
ifp = XFS_IFORK_PTR(ip, whichfork);
if (whichfork == XFS_COW_FORK && !ifp) {
mval->br_startoff = bno;
mval->br_startblock = HOLESTARTBLOCK;
mval->br_blockcount = len;
mval->br_state = XFS_EXT_NORM;
*nmap = 1;
return 0;
}
if (!(ifp->if_flags & XFS_IFEXTENTS)) {
error = xfs_iread_extents(NULL, ip, whichfork);
if (error)
return error;
}
if (!xfs_iext_lookup_extent(ip, ifp, bno, &idx, &got))
eof = true;
end = bno + len;
obno = bno;
while (bno < end && n < *nmap) {
if (eof)
got.br_startoff = end;
if (got.br_startoff > bno) {
mval->br_startoff = bno;
mval->br_startblock = HOLESTARTBLOCK;
mval->br_blockcount =
XFS_FILBLKS_MIN(len, got.br_startoff - bno);
mval->br_state = XFS_EXT_NORM;
bno += mval->br_blockcount;
len -= mval->br_blockcount;
mval++;
n++;
continue;
}
xfs_bmapi_trim_map(mval, &got, &bno, len, obno, end, n, flags);
xfs_bmapi_update_map(&mval, &bno, &len, obno, end, &n, flags);
if (bno >= end || n >= *nmap)
break;
if (!xfs_iext_get_extent(ifp, ++idx, &got))
eof = true;
}
*nmap = n;
return 0;
}
int
xfs_bmapi_reserve_delalloc(
struct xfs_inode *ip,
int whichfork,
xfs_fileoff_t off,
xfs_filblks_t len,
xfs_filblks_t prealloc,
struct xfs_bmbt_irec *got,
xfs_extnum_t *lastx,
int eof)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_ifork *ifp = XFS_IFORK_PTR(ip, whichfork);
xfs_extlen_t alen;
xfs_extlen_t indlen;
char rt = XFS_IS_REALTIME_INODE(ip);
xfs_extlen_t extsz;
int error;
xfs_fileoff_t aoff = off;
alen = XFS_FILBLKS_MIN(len + prealloc, MAXEXTLEN);
if (!eof)
alen = XFS_FILBLKS_MIN(alen, got->br_startoff - aoff);
if (prealloc && alen >= len)
prealloc = alen - len;
if (whichfork == XFS_COW_FORK)
extsz = xfs_get_cowextsz_hint(ip);
else
extsz = xfs_get_extsz_hint(ip);
if (extsz) {
struct xfs_bmbt_irec prev;
if (!xfs_iext_get_extent(ifp, *lastx - 1, &prev))
prev.br_startoff = NULLFILEOFF;
error = xfs_bmap_extsize_align(mp, got, &prev, extsz, rt, eof,
1, 0, &aoff, &alen);
ASSERT(!error);
}
if (rt)
extsz = alen / mp->m_sb.sb_rextsize;
error = xfs_trans_reserve_quota_nblks(NULL, ip, (long)alen, 0,
rt ? XFS_QMOPT_RES_RTBLKS : XFS_QMOPT_RES_REGBLKS);
if (error)
return error;
indlen = (xfs_extlen_t)xfs_bmap_worst_indlen(ip, alen);
ASSERT(indlen > 0);
if (rt) {
error = xfs_mod_frextents(mp, -((int64_t)extsz));
} else {
error = xfs_mod_fdblocks(mp, -((int64_t)alen), false);
}
if (error)
goto out_unreserve_quota;
error = xfs_mod_fdblocks(mp, -((int64_t)indlen), false);
if (error)
goto out_unreserve_blocks;
ip->i_delayed_blks += alen;
got->br_startoff = aoff;
got->br_startblock = nullstartblock(indlen);
got->br_blockcount = alen;
got->br_state = XFS_EXT_NORM;
xfs_bmap_add_extent_hole_delay(ip, whichfork, lastx, got);
if (whichfork == XFS_DATA_FORK && prealloc)
xfs_inode_set_eofblocks_tag(ip);
if (whichfork == XFS_COW_FORK && (prealloc || aoff < off || alen > len))
xfs_inode_set_cowblocks_tag(ip);
return 0;
out_unreserve_blocks:
if (rt)
xfs_mod_frextents(mp, extsz);
else
xfs_mod_fdblocks(mp, alen, false);
out_unreserve_quota:
if (XFS_IS_QUOTA_ON(mp))
xfs_trans_unreserve_quota_nblks(NULL, ip, (long)alen, 0, rt ?
XFS_QMOPT_RES_RTBLKS : XFS_QMOPT_RES_REGBLKS);
return error;
}
static int
xfs_bmapi_allocate(
struct xfs_bmalloca *bma)
{
struct xfs_mount *mp = bma->ip->i_mount;
int whichfork = xfs_bmapi_whichfork(bma->flags);
struct xfs_ifork *ifp = XFS_IFORK_PTR(bma->ip, whichfork);
int tmp_logflags = 0;
int error;
ASSERT(bma->length > 0);
if (bma->wasdel) {
bma->length = (xfs_extlen_t)bma->got.br_blockcount;
bma->offset = bma->got.br_startoff;
if (bma->idx) {
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, bma->idx - 1),
&bma->prev);
}
} else {
bma->length = XFS_FILBLKS_MIN(bma->length, MAXEXTLEN);
if (!bma->eof)
bma->length = XFS_FILBLKS_MIN(bma->length,
bma->got.br_startoff - bma->offset);
}
if (!(bma->flags & XFS_BMAPI_METADATA)) {
bma->datatype = XFS_ALLOC_NOBUSY;
if (whichfork == XFS_DATA_FORK) {
if (bma->offset == 0)
bma->datatype |= XFS_ALLOC_INITIAL_USER_DATA;
else
bma->datatype |= XFS_ALLOC_USERDATA;
}
if (bma->flags & XFS_BMAPI_ZERO)
bma->datatype |= XFS_ALLOC_USERDATA_ZERO;
}
bma->minlen = (bma->flags & XFS_BMAPI_CONTIG) ? bma->length : 1;
if (mp->m_dalign && bma->length >= mp->m_dalign &&
!(bma->flags & XFS_BMAPI_METADATA) && whichfork == XFS_DATA_FORK) {
error = xfs_bmap_isaeof(bma, whichfork);
if (error)
return error;
}
error = xfs_bmap_alloc(bma);
if (error)
return error;
if (bma->cur)
bma->cur->bc_private.b.firstblock = *bma->firstblock;
if (bma->blkno == NULLFSBLOCK)
return 0;
if ((ifp->if_flags & XFS_IFBROOT) && !bma->cur) {
bma->cur = xfs_bmbt_init_cursor(mp, bma->tp, bma->ip, whichfork);
bma->cur->bc_private.b.firstblock = *bma->firstblock;
bma->cur->bc_private.b.dfops = bma->dfops;
}
bma->nallocs++;
if (bma->cur)
bma->cur->bc_private.b.flags =
bma->wasdel ? XFS_BTCUR_BPRV_WASDEL : 0;
bma->got.br_startoff = bma->offset;
bma->got.br_startblock = bma->blkno;
bma->got.br_blockcount = bma->length;
bma->got.br_state = XFS_EXT_NORM;
if ((!bma->wasdel || (bma->flags & XFS_BMAPI_COWFORK)) &&
(bma->flags & XFS_BMAPI_PREALLOC) &&
xfs_sb_version_hasextflgbit(&mp->m_sb))
bma->got.br_state = XFS_EXT_UNWRITTEN;
if (bma->wasdel)
error = xfs_bmap_add_extent_delay_real(bma, whichfork);
else
error = xfs_bmap_add_extent_hole_real(bma->tp, bma->ip,
whichfork, &bma->idx, &bma->cur, &bma->got,
bma->firstblock, bma->dfops, &bma->logflags);
bma->logflags |= tmp_logflags;
if (error)
return error;
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, bma->idx), &bma->got);
ASSERT(bma->got.br_startoff <= bma->offset);
ASSERT(bma->got.br_startoff + bma->got.br_blockcount >=
bma->offset + bma->length);
ASSERT(bma->got.br_state == XFS_EXT_NORM ||
bma->got.br_state == XFS_EXT_UNWRITTEN);
return 0;
}
STATIC int
xfs_bmapi_convert_unwritten(
struct xfs_bmalloca *bma,
struct xfs_bmbt_irec *mval,
xfs_filblks_t len,
int flags)
{
int whichfork = xfs_bmapi_whichfork(flags);
struct xfs_ifork *ifp = XFS_IFORK_PTR(bma->ip, whichfork);
int tmp_logflags = 0;
int error;
if (mval->br_state == XFS_EXT_UNWRITTEN &&
(flags & XFS_BMAPI_PREALLOC))
return 0;
if (mval->br_state == XFS_EXT_NORM &&
(flags & (XFS_BMAPI_PREALLOC | XFS_BMAPI_CONVERT)) !=
(XFS_BMAPI_PREALLOC | XFS_BMAPI_CONVERT))
return 0;
ASSERT(mval->br_blockcount <= len);
if ((ifp->if_flags & XFS_IFBROOT) && !bma->cur) {
bma->cur = xfs_bmbt_init_cursor(bma->ip->i_mount, bma->tp,
bma->ip, whichfork);
bma->cur->bc_private.b.firstblock = *bma->firstblock;
bma->cur->bc_private.b.dfops = bma->dfops;
}
mval->br_state = (mval->br_state == XFS_EXT_UNWRITTEN)
? XFS_EXT_NORM : XFS_EXT_UNWRITTEN;
if (flags & XFS_BMAPI_ZERO) {
error = xfs_zero_extent(bma->ip, mval->br_startblock,
mval->br_blockcount);
if (error)
return error;
}
error = xfs_bmap_add_extent_unwritten_real(bma->tp, bma->ip, whichfork,
&bma->idx, &bma->cur, mval, bma->firstblock, bma->dfops,
&tmp_logflags);
if (whichfork != XFS_COW_FORK)
bma->logflags |= tmp_logflags | XFS_ILOG_CORE;
if (error)
return error;
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, bma->idx), &bma->got);
if (mval->br_blockcount < len)
return -EAGAIN;
return 0;
}
int
xfs_bmapi_write(
struct xfs_trans *tp,
struct xfs_inode *ip,
xfs_fileoff_t bno,
xfs_filblks_t len,
int flags,
xfs_fsblock_t *firstblock,
xfs_extlen_t total,
struct xfs_bmbt_irec *mval,
int *nmap,
struct xfs_defer_ops *dfops)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_ifork *ifp;
struct xfs_bmalloca bma = { NULL };
xfs_fileoff_t end;
bool eof = false;
int error;
int n;
xfs_fileoff_t obno;
int whichfork;
#ifdef DEBUG
xfs_fileoff_t orig_bno;
int orig_flags;
xfs_filblks_t orig_len;
struct xfs_bmbt_irec *orig_mval;
int orig_nmap;
orig_bno = bno;
orig_len = len;
orig_flags = flags;
orig_mval = mval;
orig_nmap = *nmap;
#endif
whichfork = xfs_bmapi_whichfork(flags);
ASSERT(*nmap >= 1);
ASSERT(*nmap <= XFS_BMAP_MAX_NMAP);
ASSERT(!(flags & XFS_BMAPI_IGSTATE));
ASSERT(tp != NULL ||
(flags & (XFS_BMAPI_CONVERT | XFS_BMAPI_COWFORK)) ==
(XFS_BMAPI_CONVERT | XFS_BMAPI_COWFORK));
ASSERT(len > 0);
ASSERT(XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_LOCAL);
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
ASSERT(!(flags & XFS_BMAPI_REMAP));
ASSERT((flags & (XFS_BMAPI_METADATA | XFS_BMAPI_ZERO)) !=
(XFS_BMAPI_METADATA | XFS_BMAPI_ZERO));
ASSERT((flags & (XFS_BMAPI_PREALLOC | XFS_BMAPI_ZERO)) !=
(XFS_BMAPI_PREALLOC | XFS_BMAPI_ZERO));
if (unlikely(XFS_TEST_ERROR(
(XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_EXTENTS &&
XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_BTREE),
mp, XFS_ERRTAG_BMAPIFORMAT))) {
XFS_ERROR_REPORT("xfs_bmapi_write", XFS_ERRLEVEL_LOW, mp);
return -EFSCORRUPTED;
}
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
ifp = XFS_IFORK_PTR(ip, whichfork);
XFS_STATS_INC(mp, xs_blk_mapw);
if (*firstblock == NULLFSBLOCK) {
if (XFS_IFORK_FORMAT(ip, whichfork) == XFS_DINODE_FMT_BTREE)
bma.minleft = be16_to_cpu(ifp->if_broot->bb_level) + 1;
else
bma.minleft = 1;
} else {
bma.minleft = 0;
}
if (!(ifp->if_flags & XFS_IFEXTENTS)) {
error = xfs_iread_extents(tp, ip, whichfork);
if (error)
goto error0;
}
n = 0;
end = bno + len;
obno = bno;
if (!xfs_iext_lookup_extent(ip, ifp, bno, &bma.idx, &bma.got))
eof = true;
if (!xfs_iext_get_extent(ifp, bma.idx - 1, &bma.prev))
bma.prev.br_startoff = NULLFILEOFF;
bma.tp = tp;
bma.ip = ip;
bma.total = total;
bma.datatype = 0;
bma.dfops = dfops;
bma.firstblock = firstblock;
while (bno < end && n < *nmap) {
bool need_alloc = false, wasdelay = false;
if (eof || bma.got.br_startoff > bno) {
if (flags & XFS_BMAPI_DELALLOC) {
ASSERT(flags & XFS_BMAPI_COWFORK);
if (!(flags & XFS_BMAPI_COWFORK)) {
error = -EIO;
goto error0;
}
if (eof || bno >= end)
break;
} else {
need_alloc = true;
}
} else if (isnullstartblock(bma.got.br_startblock)) {
wasdelay = true;
}
if (need_alloc || wasdelay) {
bma.eof = eof;
bma.conv = !!(flags & XFS_BMAPI_CONVERT);
bma.wasdel = wasdelay;
bma.offset = bno;
bma.flags = flags;
if (len > (xfs_filblks_t)MAXEXTLEN)
bma.length = MAXEXTLEN;
else
bma.length = len;
ASSERT(len > 0);
ASSERT(bma.length > 0);
error = xfs_bmapi_allocate(&bma);
if (error)
goto error0;
if (bma.blkno == NULLFSBLOCK)
break;
if (whichfork == XFS_COW_FORK) {
error = xfs_refcount_alloc_cow_extent(mp, dfops,
bma.blkno, bma.length);
if (error)
goto error0;
}
}
xfs_bmapi_trim_map(mval, &bma.got, &bno, len, obno,
end, n, flags);
error = xfs_bmapi_convert_unwritten(&bma, mval, len, flags);
if (error == -EAGAIN)
continue;
if (error)
goto error0;
xfs_bmapi_update_map(&mval, &bno, &len, obno, end, &n, flags);
if (bno >= end || n >= *nmap || bma.nallocs >= *nmap)
break;
bma.prev = bma.got;
if (!xfs_iext_get_extent(ifp, ++bma.idx, &bma.got))
eof = true;
}
*nmap = n;
if (xfs_bmap_wants_extents(ip, whichfork)) {
int tmp_logflags = 0;
ASSERT(bma.cur);
error = xfs_bmap_btree_to_extents(tp, ip, bma.cur,
&tmp_logflags, whichfork);
bma.logflags |= tmp_logflags;
if (error)
goto error0;
}
ASSERT(XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_BTREE ||
XFS_IFORK_NEXTENTS(ip, whichfork) >
XFS_IFORK_MAXEXT(ip, whichfork));
error = 0;
error0:
if ((bma.logflags & xfs_ilog_fext(whichfork)) &&
XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_EXTENTS)
bma.logflags &= ~xfs_ilog_fext(whichfork);
else if ((bma.logflags & xfs_ilog_fbroot(whichfork)) &&
XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_BTREE)
bma.logflags &= ~xfs_ilog_fbroot(whichfork);
if (bma.logflags)
xfs_trans_log_inode(tp, ip, bma.logflags);
if (bma.cur) {
if (!error) {
ASSERT(*firstblock == NULLFSBLOCK ||
XFS_FSB_TO_AGNO(mp, *firstblock) <=
XFS_FSB_TO_AGNO(mp,
bma.cur->bc_private.b.firstblock));
*firstblock = bma.cur->bc_private.b.firstblock;
}
xfs_btree_del_cursor(bma.cur,
error ? XFS_BTREE_ERROR : XFS_BTREE_NOERROR);
}
if (!error)
xfs_bmap_validate_ret(orig_bno, orig_len, orig_flags, orig_mval,
orig_nmap, *nmap);
return error;
}
static int
xfs_bmapi_remap(
struct xfs_trans *tp,
struct xfs_inode *ip,
xfs_fileoff_t bno,
xfs_filblks_t len,
xfs_fsblock_t startblock,
struct xfs_defer_ops *dfops)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_ifork *ifp = XFS_IFORK_PTR(ip, XFS_DATA_FORK);
struct xfs_btree_cur *cur = NULL;
xfs_fsblock_t firstblock = NULLFSBLOCK;
struct xfs_bmbt_irec got;
xfs_extnum_t idx;
int logflags = 0, error;
ASSERT(len > 0);
ASSERT(len <= (xfs_filblks_t)MAXEXTLEN);
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
if (unlikely(XFS_TEST_ERROR(
(XFS_IFORK_FORMAT(ip, XFS_DATA_FORK) != XFS_DINODE_FMT_EXTENTS &&
XFS_IFORK_FORMAT(ip, XFS_DATA_FORK) != XFS_DINODE_FMT_BTREE),
mp, XFS_ERRTAG_BMAPIFORMAT))) {
XFS_ERROR_REPORT("xfs_bmapi_remap", XFS_ERRLEVEL_LOW, mp);
return -EFSCORRUPTED;
}
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
if (!(ifp->if_flags & XFS_IFEXTENTS)) {
error = xfs_iread_extents(NULL, ip, XFS_DATA_FORK);
if (error)
return error;
}
if (xfs_iext_lookup_extent(ip, ifp, bno, &idx, &got)) {
ASSERT(got.br_startoff > bno);
ASSERT(got.br_startoff - bno >= len);
}
ip->i_d.di_nblocks += len;
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
if (ifp->if_flags & XFS_IFBROOT) {
cur = xfs_bmbt_init_cursor(mp, tp, ip, XFS_DATA_FORK);
cur->bc_private.b.firstblock = firstblock;
cur->bc_private.b.dfops = dfops;
cur->bc_private.b.flags = 0;
}
got.br_startoff = bno;
got.br_startblock = startblock;
got.br_blockcount = len;
got.br_state = XFS_EXT_NORM;
error = xfs_bmap_add_extent_hole_real(tp, ip, XFS_DATA_FORK, &idx, &cur,
&got, &firstblock, dfops, &logflags);
if (error)
goto error0;
if (xfs_bmap_wants_extents(ip, XFS_DATA_FORK)) {
int tmp_logflags = 0;
error = xfs_bmap_btree_to_extents(tp, ip, cur,
&tmp_logflags, XFS_DATA_FORK);
logflags |= tmp_logflags;
}
error0:
if (ip->i_d.di_format != XFS_DINODE_FMT_EXTENTS)
logflags &= ~XFS_ILOG_DEXT;
else if (ip->i_d.di_format != XFS_DINODE_FMT_BTREE)
logflags &= ~XFS_ILOG_DBROOT;
if (logflags)
xfs_trans_log_inode(tp, ip, logflags);
if (cur) {
xfs_btree_del_cursor(cur,
error ? XFS_BTREE_ERROR : XFS_BTREE_NOERROR);
}
return error;
}
static xfs_filblks_t
xfs_bmap_split_indlen(
xfs_filblks_t ores,
xfs_filblks_t *indlen1,
xfs_filblks_t *indlen2,
xfs_filblks_t avail)
{
xfs_filblks_t len1 = *indlen1;
xfs_filblks_t len2 = *indlen2;
xfs_filblks_t nres = len1 + len2;
xfs_filblks_t stolen = 0;
xfs_filblks_t resfactor;
if (ores < nres && avail)
stolen = XFS_FILBLKS_MIN(nres - ores, avail);
ores += stolen;
if (ores >= nres)
return stolen;
resfactor = (ores * 100);
do_div(resfactor, nres);
len1 *= resfactor;
do_div(len1, 100);
len2 *= resfactor;
do_div(len2, 100);
ASSERT(len1 + len2 <= ores);
ASSERT(len1 < *indlen1 && len2 < *indlen2);
ores -= (len1 + len2);
ASSERT((*indlen1 - len1) + (*indlen2 - len2) >= ores);
if (ores && !len2 && *indlen2) {
len2++;
ores--;
}
while (ores) {
if (len1 < *indlen1) {
len1++;
ores--;
}
if (!ores)
break;
if (len2 < *indlen2) {
len2++;
ores--;
}
}
*indlen1 = len1;
*indlen2 = len2;
return stolen;
}
int
xfs_bmap_del_extent_delay(
struct xfs_inode *ip,
int whichfork,
xfs_extnum_t *idx,
struct xfs_bmbt_irec *got,
struct xfs_bmbt_irec *del)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_ifork *ifp = XFS_IFORK_PTR(ip, whichfork);
struct xfs_bmbt_irec new;
int64_t da_old, da_new, da_diff = 0;
xfs_fileoff_t del_endoff, got_endoff;
xfs_filblks_t got_indlen, new_indlen, stolen;
int error = 0, state = 0;
bool isrt;
XFS_STATS_INC(mp, xs_del_exlist);
isrt = (whichfork == XFS_DATA_FORK) && XFS_IS_REALTIME_INODE(ip);
del_endoff = del->br_startoff + del->br_blockcount;
got_endoff = got->br_startoff + got->br_blockcount;
da_old = startblockval(got->br_startblock);
da_new = 0;
ASSERT(*idx >= 0);
ASSERT(*idx <= xfs_iext_count(ifp));
ASSERT(del->br_blockcount > 0);
ASSERT(got->br_startoff <= del->br_startoff);
ASSERT(got_endoff >= del_endoff);
if (isrt) {
uint64_t rtexts = XFS_FSB_TO_B(mp, del->br_blockcount);
do_div(rtexts, mp->m_sb.sb_rextsize);
xfs_mod_frextents(mp, rtexts);
}
error = xfs_trans_reserve_quota_nblks(NULL, ip,
-((long)del->br_blockcount), 0,
isrt ? XFS_QMOPT_RES_RTBLKS : XFS_QMOPT_RES_REGBLKS);
if (error)
return error;
ip->i_delayed_blks -= del->br_blockcount;
if (whichfork == XFS_COW_FORK)
state |= BMAP_COWFORK;
if (got->br_startoff == del->br_startoff)
state |= BMAP_LEFT_CONTIG;
if (got_endoff == del_endoff)
state |= BMAP_RIGHT_CONTIG;
switch (state & (BMAP_LEFT_CONTIG | BMAP_RIGHT_CONTIG)) {
case BMAP_LEFT_CONTIG | BMAP_RIGHT_CONTIG:
xfs_iext_remove(ip, *idx, 1, state);
--*idx;
break;
case BMAP_LEFT_CONTIG:
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
got->br_startoff = del_endoff;
got->br_blockcount -= del->br_blockcount;
da_new = XFS_FILBLKS_MIN(xfs_bmap_worst_indlen(ip,
got->br_blockcount), da_old);
got->br_startblock = nullstartblock((int)da_new);
xfs_iext_update_extent(ifp, *idx, got);
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
break;
case BMAP_RIGHT_CONTIG:
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
got->br_blockcount = got->br_blockcount - del->br_blockcount;
da_new = XFS_FILBLKS_MIN(xfs_bmap_worst_indlen(ip,
got->br_blockcount), da_old);
got->br_startblock = nullstartblock((int)da_new);
xfs_iext_update_extent(ifp, *idx, got);
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
break;
case 0:
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
got->br_blockcount = del->br_startoff - got->br_startoff;
got_indlen = xfs_bmap_worst_indlen(ip, got->br_blockcount);
new.br_blockcount = got_endoff - del_endoff;
new_indlen = xfs_bmap_worst_indlen(ip, new.br_blockcount);
WARN_ON_ONCE(!got_indlen || !new_indlen);
stolen = xfs_bmap_split_indlen(da_old, &got_indlen, &new_indlen,
del->br_blockcount);
got->br_startblock = nullstartblock((int)got_indlen);
xfs_iext_update_extent(ifp, *idx, got);
trace_xfs_bmap_post_update(ip, *idx, 0, _THIS_IP_);
new.br_startoff = del_endoff;
new.br_state = got->br_state;
new.br_startblock = nullstartblock((int)new_indlen);
++*idx;
xfs_iext_insert(ip, *idx, 1, &new, state);
da_new = got_indlen + new_indlen - stolen;
del->br_blockcount -= stolen;
break;
}
ASSERT(da_old >= da_new);
da_diff = da_old - da_new;
if (!isrt)
da_diff += del->br_blockcount;
if (da_diff)
xfs_mod_fdblocks(mp, da_diff, false);
return error;
}
void
xfs_bmap_del_extent_cow(
struct xfs_inode *ip,
xfs_extnum_t *idx,
struct xfs_bmbt_irec *got,
struct xfs_bmbt_irec *del)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_ifork *ifp = XFS_IFORK_PTR(ip, XFS_COW_FORK);
struct xfs_bmbt_irec new;
xfs_fileoff_t del_endoff, got_endoff;
int state = BMAP_COWFORK;
XFS_STATS_INC(mp, xs_del_exlist);
del_endoff = del->br_startoff + del->br_blockcount;
got_endoff = got->br_startoff + got->br_blockcount;
ASSERT(*idx >= 0);
ASSERT(*idx <= xfs_iext_count(ifp));
ASSERT(del->br_blockcount > 0);
ASSERT(got->br_startoff <= del->br_startoff);
ASSERT(got_endoff >= del_endoff);
ASSERT(!isnullstartblock(got->br_startblock));
if (got->br_startoff == del->br_startoff)
state |= BMAP_LEFT_CONTIG;
if (got_endoff == del_endoff)
state |= BMAP_RIGHT_CONTIG;
switch (state & (BMAP_LEFT_CONTIG | BMAP_RIGHT_CONTIG)) {
case BMAP_LEFT_CONTIG | BMAP_RIGHT_CONTIG:
xfs_iext_remove(ip, *idx, 1, state);
--*idx;
break;
case BMAP_LEFT_CONTIG:
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
got->br_startoff = del_endoff;
got->br_blockcount -= del->br_blockcount;
got->br_startblock = del->br_startblock + del->br_blockcount;
xfs_iext_update_extent(ifp, *idx, got);
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
break;
case BMAP_RIGHT_CONTIG:
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
got->br_blockcount -= del->br_blockcount;
xfs_iext_update_extent(ifp, *idx, got);
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
break;
case 0:
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
got->br_blockcount = del->br_startoff - got->br_startoff;
xfs_iext_update_extent(ifp, *idx, got);
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
new.br_startoff = del_endoff;
new.br_blockcount = got_endoff - del_endoff;
new.br_state = got->br_state;
new.br_startblock = del->br_startblock + del->br_blockcount;
++*idx;
xfs_iext_insert(ip, *idx, 1, &new, state);
break;
}
}
STATIC int
xfs_bmap_del_extent(
xfs_inode_t *ip,
xfs_trans_t *tp,
xfs_extnum_t *idx,
struct xfs_defer_ops *dfops,
xfs_btree_cur_t *cur,
xfs_bmbt_irec_t *del,
int *logflagsp,
int whichfork,
int bflags)
{
xfs_filblks_t da_new;
xfs_filblks_t da_old;
xfs_fsblock_t del_endblock=0;
xfs_fileoff_t del_endoff;
int delay;
int do_fx;
xfs_bmbt_rec_host_t *ep;
int error;
int flags;
xfs_bmbt_irec_t got;
xfs_fileoff_t got_endoff;
int i;
xfs_ifork_t *ifp;
xfs_mount_t *mp;
xfs_filblks_t nblks;
xfs_bmbt_irec_t new;
uint qfield;
xfs_filblks_t temp;
xfs_filblks_t temp2;
int state = 0;
mp = ip->i_mount;
XFS_STATS_INC(mp, xs_del_exlist);
if (whichfork == XFS_ATTR_FORK)
state |= BMAP_ATTRFORK;
else if (whichfork == XFS_COW_FORK)
state |= BMAP_COWFORK;
ifp = XFS_IFORK_PTR(ip, whichfork);
ASSERT((*idx >= 0) && (*idx < xfs_iext_count(ifp)));
ASSERT(del->br_blockcount > 0);
ep = xfs_iext_get_ext(ifp, *idx);
xfs_bmbt_get_all(ep, &got);
ASSERT(got.br_startoff <= del->br_startoff);
del_endoff = del->br_startoff + del->br_blockcount;
got_endoff = got.br_startoff + got.br_blockcount;
ASSERT(got_endoff >= del_endoff);
delay = isnullstartblock(got.br_startblock);
ASSERT(isnullstartblock(del->br_startblock) == delay);
flags = 0;
qfield = 0;
error = 0;
if (!delay) {
flags = XFS_ILOG_CORE;
if (whichfork == XFS_DATA_FORK && XFS_IS_REALTIME_INODE(ip)) {
xfs_fsblock_t bno;
xfs_filblks_t len;
ASSERT(do_mod(del->br_blockcount,
mp->m_sb.sb_rextsize) == 0);
ASSERT(do_mod(del->br_startblock,
mp->m_sb.sb_rextsize) == 0);
bno = del->br_startblock;
len = del->br_blockcount;
do_div(bno, mp->m_sb.sb_rextsize);
do_div(len, mp->m_sb.sb_rextsize);
error = xfs_rtfree_extent(tp, bno, (xfs_extlen_t)len);
if (error)
goto done;
do_fx = 0;
nblks = len * mp->m_sb.sb_rextsize;
qfield = XFS_TRANS_DQ_RTBCOUNT;
}
else {
do_fx = 1;
nblks = del->br_blockcount;
qfield = XFS_TRANS_DQ_BCOUNT;
}
del_endblock = del->br_startblock + del->br_blockcount;
if (cur) {
if ((error = xfs_bmbt_lookup_eq(cur, got.br_startoff,
got.br_startblock, got.br_blockcount,
&i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
}
da_old = da_new = 0;
} else {
da_old = startblockval(got.br_startblock);
da_new = 0;
nblks = 0;
do_fx = 0;
}
switch (((got.br_startoff == del->br_startoff) << 1) |
(got_endoff == del_endoff)) {
case 3:
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
xfs_iext_remove(ip, *idx, 1,
whichfork == XFS_ATTR_FORK ? BMAP_ATTRFORK : 0);
--*idx;
if (delay)
break;
XFS_IFORK_NEXT_SET(ip, whichfork,
XFS_IFORK_NEXTENTS(ip, whichfork) - 1);
flags |= XFS_ILOG_CORE;
if (!cur) {
flags |= xfs_ilog_fext(whichfork);
break;
}
if ((error = xfs_btree_delete(cur, &i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
break;
case 2:
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
xfs_bmbt_set_startoff(ep, del_endoff);
temp = got.br_blockcount - del->br_blockcount;
xfs_bmbt_set_blockcount(ep, temp);
if (delay) {
temp = XFS_FILBLKS_MIN(xfs_bmap_worst_indlen(ip, temp),
da_old);
xfs_bmbt_set_startblock(ep, nullstartblock((int)temp));
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
da_new = temp;
break;
}
xfs_bmbt_set_startblock(ep, del_endblock);
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
if (!cur) {
flags |= xfs_ilog_fext(whichfork);
break;
}
if ((error = xfs_bmbt_update(cur, del_endoff, del_endblock,
got.br_blockcount - del->br_blockcount,
got.br_state)))
goto done;
break;
case 1:
temp = got.br_blockcount - del->br_blockcount;
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
xfs_bmbt_set_blockcount(ep, temp);
if (delay) {
temp = XFS_FILBLKS_MIN(xfs_bmap_worst_indlen(ip, temp),
da_old);
xfs_bmbt_set_startblock(ep, nullstartblock((int)temp));
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
da_new = temp;
break;
}
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
if (!cur) {
flags |= xfs_ilog_fext(whichfork);
break;
}
if ((error = xfs_bmbt_update(cur, got.br_startoff,
got.br_startblock,
got.br_blockcount - del->br_blockcount,
got.br_state)))
goto done;
break;
case 0:
temp = del->br_startoff - got.br_startoff;
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
xfs_bmbt_set_blockcount(ep, temp);
new.br_startoff = del_endoff;
temp2 = got_endoff - del_endoff;
new.br_blockcount = temp2;
new.br_state = got.br_state;
if (!delay) {
new.br_startblock = del_endblock;
flags |= XFS_ILOG_CORE;
if (cur) {
if ((error = xfs_bmbt_update(cur,
got.br_startoff,
got.br_startblock, temp,
got.br_state)))
goto done;
if ((error = xfs_btree_increment(cur, 0, &i)))
goto done;
cur->bc_rec.b = new;
error = xfs_btree_insert(cur, &i);
if (error && error != -ENOSPC)
goto done;
if (error == -ENOSPC) {
if ((error = xfs_bmbt_lookup_eq(cur,
got.br_startoff,
got.br_startblock,
temp, &i)))
goto done;
XFS_WANT_CORRUPTED_GOTO(mp,
i == 1, done);
if ((error = xfs_bmbt_update(cur,
got.br_startoff,
got.br_startblock,
got.br_blockcount,
got.br_state)))
goto done;
xfs_bmbt_set_blockcount(ep,
got.br_blockcount);
flags = 0;
error = -ENOSPC;
goto done;
}
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
} else
flags |= xfs_ilog_fext(whichfork);
XFS_IFORK_NEXT_SET(ip, whichfork,
XFS_IFORK_NEXTENTS(ip, whichfork) + 1);
} else {
xfs_filblks_t stolen;
ASSERT(whichfork == XFS_DATA_FORK);
temp = xfs_bmap_worst_indlen(ip, got.br_blockcount);
temp2 = xfs_bmap_worst_indlen(ip, new.br_blockcount);
stolen = xfs_bmap_split_indlen(da_old, &temp, &temp2,
del->br_blockcount);
da_new = temp + temp2 - stolen;
del->br_blockcount -= stolen;
WARN_ON_ONCE(!temp || !temp2);
xfs_bmbt_set_startblock(ep, nullstartblock((int)temp));
new.br_startblock = nullstartblock((int)temp2);
}
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
xfs_iext_insert(ip, *idx + 1, 1, &new, state);
++*idx;
break;
}
if (!delay) {
error = xfs_rmap_unmap_extent(mp, dfops, ip, whichfork, del);
if (error)
goto done;
}
if (do_fx && !(bflags & XFS_BMAPI_REMAP)) {
if (xfs_is_reflink_inode(ip) && whichfork == XFS_DATA_FORK) {
error = xfs_refcount_decrease_extent(mp, dfops, del);
if (error)
goto done;
} else
xfs_bmap_add_free(mp, dfops, del->br_startblock,
del->br_blockcount, NULL);
}
if (nblks)
ip->i_d.di_nblocks -= nblks;
if (qfield && !(bflags & XFS_BMAPI_REMAP))
xfs_trans_mod_dquot_byino(tp, ip, qfield, (long)-nblks);
ASSERT(da_old >= da_new);
if (da_old > da_new)
xfs_mod_fdblocks(mp, (int64_t)(da_old - da_new), false);
done:
*logflagsp = flags;
return error;
}
int
__xfs_bunmapi(
xfs_trans_t *tp,
struct xfs_inode *ip,
xfs_fileoff_t bno,
xfs_filblks_t *rlen,
int flags,
xfs_extnum_t nexts,
xfs_fsblock_t *firstblock,
struct xfs_defer_ops *dfops)
{
xfs_btree_cur_t *cur;
xfs_bmbt_irec_t del;
int error;
xfs_extnum_t extno;
xfs_bmbt_irec_t got;
xfs_ifork_t *ifp;
int isrt;
xfs_extnum_t lastx;
int logflags;
xfs_extlen_t mod;
xfs_mount_t *mp;
xfs_fileoff_t start;
int tmp_logflags;
int wasdel;
int whichfork;
xfs_fsblock_t sum;
xfs_filblks_t len = *rlen;
xfs_fileoff_t max_len;
xfs_agnumber_t prev_agno = NULLAGNUMBER, agno;
trace_xfs_bunmap(ip, bno, len, flags, _RET_IP_);
whichfork = xfs_bmapi_whichfork(flags);
ASSERT(whichfork != XFS_COW_FORK);
ifp = XFS_IFORK_PTR(ip, whichfork);
if (unlikely(
XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_EXTENTS &&
XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_BTREE)) {
XFS_ERROR_REPORT("xfs_bunmapi", XFS_ERRLEVEL_LOW,
ip->i_mount);
return -EFSCORRUPTED;
}
mp = ip->i_mount;
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
ASSERT(len > 0);
ASSERT(nexts >= 0);
if (xfs_is_reflink_inode(ip) && whichfork == XFS_DATA_FORK)
max_len = min(len, xfs_refcount_max_unmap(tp->t_log_res));
else
max_len = len;
if (!(ifp->if_flags & XFS_IFEXTENTS) &&
(error = xfs_iread_extents(tp, ip, whichfork)))
return error;
if (xfs_iext_count(ifp) == 0) {
*rlen = 0;
return 0;
}
XFS_STATS_INC(mp, xs_blk_unmap);
isrt = (whichfork == XFS_DATA_FORK) && XFS_IS_REALTIME_INODE(ip);
start = bno;
bno = start + len - 1;
if (!xfs_iext_lookup_extent(ip, ifp, bno, &lastx, &got)) {
ASSERT(lastx > 0);
xfs_iext_get_extent(ifp, --lastx, &got);
bno = got.br_startoff + got.br_blockcount - 1;
}
logflags = 0;
if (ifp->if_flags & XFS_IFBROOT) {
ASSERT(XFS_IFORK_FORMAT(ip, whichfork) == XFS_DINODE_FMT_BTREE);
cur = xfs_bmbt_init_cursor(mp, tp, ip, whichfork);
cur->bc_private.b.firstblock = *firstblock;
cur->bc_private.b.dfops = dfops;
cur->bc_private.b.flags = 0;
} else
cur = NULL;
if (isrt) {
xfs_ilock(mp->m_rbmip, XFS_ILOCK_EXCL|XFS_ILOCK_RTBITMAP);
xfs_trans_ijoin(tp, mp->m_rbmip, XFS_ILOCK_EXCL);
xfs_ilock(mp->m_rsumip, XFS_ILOCK_EXCL|XFS_ILOCK_RTSUM);
xfs_trans_ijoin(tp, mp->m_rsumip, XFS_ILOCK_EXCL);
}
extno = 0;
while (bno != (xfs_fileoff_t)-1 && bno >= start && lastx >= 0 &&
(nexts == 0 || extno < nexts) && max_len > 0) {
if (got.br_startoff > bno) {
if (--lastx < 0)
break;
xfs_iext_get_extent(ifp, lastx, &got);
}
bno = XFS_FILEOFF_MIN(bno,
got.br_startoff + got.br_blockcount - 1);
if (bno < start)
break;
del = got;
wasdel = isnullstartblock(del.br_startblock);
if (!wasdel) {
agno = XFS_FSB_TO_AGNO(mp, del.br_startblock);
if (prev_agno != NULLAGNUMBER && prev_agno > agno)
break;
prev_agno = agno;
}
if (got.br_startoff < start) {
del.br_startoff = start;
del.br_blockcount -= start - got.br_startoff;
if (!wasdel)
del.br_startblock += start - got.br_startoff;
}
if (del.br_startoff + del.br_blockcount > bno + 1)
del.br_blockcount = bno + 1 - del.br_startoff;
if (max_len < del.br_blockcount) {
del.br_startoff += del.br_blockcount - max_len;
if (!wasdel)
del.br_startblock += del.br_blockcount - max_len;
del.br_blockcount = max_len;
}
sum = del.br_startblock + del.br_blockcount;
if (isrt &&
(mod = do_mod(sum, mp->m_sb.sb_rextsize))) {
if (del.br_state == XFS_EXT_UNWRITTEN ||
!xfs_sb_version_hasextflgbit(&mp->m_sb)) {
ASSERT(bno >= mod);
bno -= mod > del.br_blockcount ?
del.br_blockcount : mod;
if (bno < got.br_startoff) {
if (--lastx >= 0)
xfs_bmbt_get_all(xfs_iext_get_ext(
ifp, lastx), &got);
}
continue;
}
ASSERT(del.br_state == XFS_EXT_NORM);
ASSERT(tp->t_blk_res > 0);
if (del.br_blockcount > mod) {
del.br_startoff += del.br_blockcount - mod;
del.br_startblock += del.br_blockcount - mod;
del.br_blockcount = mod;
}
del.br_state = XFS_EXT_UNWRITTEN;
error = xfs_bmap_add_extent_unwritten_real(tp, ip,
whichfork, &lastx, &cur, &del,
firstblock, dfops, &logflags);
if (error)
goto error0;
goto nodelete;
}
if (isrt && (mod = do_mod(del.br_startblock, mp->m_sb.sb_rextsize))) {
mod = mp->m_sb.sb_rextsize - mod;
if (del.br_blockcount > mod) {
del.br_blockcount -= mod;
del.br_startoff += mod;
del.br_startblock += mod;
} else if ((del.br_startoff == start &&
(del.br_state == XFS_EXT_UNWRITTEN ||
tp->t_blk_res == 0)) ||
!xfs_sb_version_hasextflgbit(&mp->m_sb)) {
ASSERT(bno >= del.br_blockcount);
bno -= del.br_blockcount;
if (got.br_startoff > bno && --lastx >= 0)
xfs_iext_get_extent(ifp, lastx, &got);
continue;
} else if (del.br_state == XFS_EXT_UNWRITTEN) {
struct xfs_bmbt_irec prev;
ASSERT(lastx > 0);
xfs_iext_get_extent(ifp, lastx - 1, &prev);
ASSERT(prev.br_state == XFS_EXT_NORM);
ASSERT(!isnullstartblock(prev.br_startblock));
ASSERT(del.br_startblock ==
prev.br_startblock + prev.br_blockcount);
if (prev.br_startoff < start) {
mod = start - prev.br_startoff;
prev.br_blockcount -= mod;
prev.br_startblock += mod;
prev.br_startoff = start;
}
prev.br_state = XFS_EXT_UNWRITTEN;
lastx--;
error = xfs_bmap_add_extent_unwritten_real(tp,
ip, whichfork, &lastx, &cur,
&prev, firstblock, dfops,
&logflags);
if (error)
goto error0;
goto nodelete;
} else {
ASSERT(del.br_state == XFS_EXT_NORM);
del.br_state = XFS_EXT_UNWRITTEN;
error = xfs_bmap_add_extent_unwritten_real(tp,
ip, whichfork, &lastx, &cur,
&del, firstblock, dfops,
&logflags);
if (error)
goto error0;
goto nodelete;
}
}
if (!wasdel && tp->t_blk_res == 0 &&
XFS_IFORK_FORMAT(ip, whichfork) == XFS_DINODE_FMT_EXTENTS &&
XFS_IFORK_NEXTENTS(ip, whichfork) >=
XFS_IFORK_MAXEXT(ip, whichfork) &&
del.br_startoff > got.br_startoff &&
del.br_startoff + del.br_blockcount <
got.br_startoff + got.br_blockcount) {
error = -ENOSPC;
goto error0;
}
if (wasdel) {
ASSERT(startblockval(del.br_startblock) > 0);
if (isrt) {
xfs_filblks_t rtexts;
rtexts = XFS_FSB_TO_B(mp, del.br_blockcount);
do_div(rtexts, mp->m_sb.sb_rextsize);
xfs_mod_frextents(mp, (int64_t)rtexts);
(void)xfs_trans_reserve_quota_nblks(NULL,
ip, -((long)del.br_blockcount), 0,
XFS_QMOPT_RES_RTBLKS);
} else {
(void)xfs_trans_reserve_quota_nblks(NULL,
ip, -((long)del.br_blockcount), 0,
XFS_QMOPT_RES_REGBLKS);
}
ip->i_delayed_blks -= del.br_blockcount;
if (cur)
cur->bc_private.b.flags |=
XFS_BTCUR_BPRV_WASDEL;
} else if (cur)
cur->bc_private.b.flags &= ~XFS_BTCUR_BPRV_WASDEL;
error = xfs_bmap_del_extent(ip, tp, &lastx, dfops, cur, &del,
&tmp_logflags, whichfork, flags);
logflags |= tmp_logflags;
if (error)
goto error0;
if (!isrt && wasdel)
xfs_mod_fdblocks(mp, (int64_t)del.br_blockcount, false);
max_len -= del.br_blockcount;
bno = del.br_startoff - 1;
nodelete:
if (bno != (xfs_fileoff_t)-1 && bno >= start) {
if (lastx >= 0) {
xfs_iext_get_extent(ifp, lastx, &got);
if (got.br_startoff > bno && --lastx >= 0)
xfs_iext_get_extent(ifp, lastx, &got);
}
extno++;
}
}
if (bno == (xfs_fileoff_t)-1 || bno < start || lastx < 0)
*rlen = 0;
else
*rlen = bno - start + 1;
if (xfs_bmap_needs_btree(ip, whichfork)) {
ASSERT(cur == NULL);
error = xfs_bmap_extents_to_btree(tp, ip, firstblock, dfops,
&cur, 0, &tmp_logflags, whichfork);
logflags |= tmp_logflags;
if (error)
goto error0;
}
else if (xfs_bmap_wants_extents(ip, whichfork)) {
ASSERT(cur != NULL);
error = xfs_bmap_btree_to_extents(tp, ip, cur, &tmp_logflags,
whichfork);
logflags |= tmp_logflags;
if (error)
goto error0;
}
error = 0;
error0:
if ((logflags & xfs_ilog_fext(whichfork)) &&
XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_EXTENTS)
logflags &= ~xfs_ilog_fext(whichfork);
else if ((logflags & xfs_ilog_fbroot(whichfork)) &&
XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_BTREE)
logflags &= ~xfs_ilog_fbroot(whichfork);
if (logflags)
xfs_trans_log_inode(tp, ip, logflags);
if (cur) {
if (!error) {
*firstblock = cur->bc_private.b.firstblock;
cur->bc_private.b.allocated = 0;
}
xfs_btree_del_cursor(cur,
error ? XFS_BTREE_ERROR : XFS_BTREE_NOERROR);
}
return error;
}
int
xfs_bunmapi(
xfs_trans_t *tp,
struct xfs_inode *ip,
xfs_fileoff_t bno,
xfs_filblks_t len,
int flags,
xfs_extnum_t nexts,
xfs_fsblock_t *firstblock,
struct xfs_defer_ops *dfops,
int *done)
{
int error;
error = __xfs_bunmapi(tp, ip, bno, &len, flags, nexts, firstblock,
dfops);
*done = (len == 0);
return error;
}
STATIC bool
xfs_bmse_can_merge(
struct xfs_bmbt_irec *left,
struct xfs_bmbt_irec *got,
xfs_fileoff_t shift)
{
xfs_fileoff_t startoff;
startoff = got->br_startoff - shift;
if ((left->br_startoff + left->br_blockcount != startoff) ||
(left->br_startblock + left->br_blockcount != got->br_startblock) ||
(left->br_state != got->br_state) ||
(left->br_blockcount + got->br_blockcount > MAXEXTLEN))
return false;
return true;
}
STATIC int
xfs_bmse_merge(
struct xfs_inode *ip,
int whichfork,
xfs_fileoff_t shift,
int current_ext,
struct xfs_bmbt_irec *got,
struct xfs_bmbt_irec *left,
struct xfs_btree_cur *cur,
int *logflags,
struct xfs_defer_ops *dfops)
{
struct xfs_ifork *ifp = XFS_IFORK_PTR(ip, whichfork);
struct xfs_bmbt_irec new;
xfs_filblks_t blockcount;
int error, i;
struct xfs_mount *mp = ip->i_mount;
blockcount = left->br_blockcount + got->br_blockcount;
ASSERT(xfs_isilocked(ip, XFS_IOLOCK_EXCL));
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
ASSERT(xfs_bmse_can_merge(left, got, shift));
new = *left;
new.br_blockcount = blockcount;
XFS_IFORK_NEXT_SET(ip, whichfork,
XFS_IFORK_NEXTENTS(ip, whichfork) - 1);
*logflags |= XFS_ILOG_CORE;
if (!cur) {
*logflags |= XFS_ILOG_DEXT;
goto done;
}
error = xfs_bmbt_lookup_eq(cur, got->br_startoff, got->br_startblock,
got->br_blockcount, &i);
if (error)
return error;
XFS_WANT_CORRUPTED_RETURN(mp, i == 1);
error = xfs_btree_delete(cur, &i);
if (error)
return error;
XFS_WANT_CORRUPTED_RETURN(mp, i == 1);
error = xfs_bmbt_lookup_eq(cur, left->br_startoff, left->br_startblock,
left->br_blockcount, &i);
if (error)
return error;
XFS_WANT_CORRUPTED_RETURN(mp, i == 1);
error = xfs_bmbt_update(cur, new.br_startoff, new.br_startblock,
new.br_blockcount, new.br_state);
if (error)
return error;
done:
xfs_iext_update_extent(ifp, current_ext - 1, &new);
xfs_iext_remove(ip, current_ext, 1, 0);
error = xfs_rmap_unmap_extent(mp, dfops, ip, whichfork, got);
if (error)
return error;
memcpy(&new, got, sizeof(new));
new.br_startoff = left->br_startoff + left->br_blockcount;
return xfs_rmap_map_extent(mp, dfops, ip, whichfork, &new);
}
STATIC int
xfs_bmse_shift_one(
struct xfs_inode *ip,
int whichfork,
xfs_fileoff_t offset_shift_fsb,
int *current_ext,
struct xfs_bmbt_irec *got,
struct xfs_btree_cur *cur,
int *logflags,
enum shift_direction direction,
struct xfs_defer_ops *dfops)
{
struct xfs_ifork *ifp;
struct xfs_mount *mp;
xfs_fileoff_t startoff;
struct xfs_bmbt_irec adj_irec, new;
int error;
int i;
int total_extents;
mp = ip->i_mount;
ifp = XFS_IFORK_PTR(ip, whichfork);
total_extents = xfs_iext_count(ifp);
XFS_WANT_CORRUPTED_RETURN(mp, !isnullstartblock(got->br_startblock));
if (direction == SHIFT_LEFT) {
startoff = got->br_startoff - offset_shift_fsb;
if (!*current_ext) {
if (got->br_startoff < offset_shift_fsb)
return -EINVAL;
goto update_current_ext;
}
xfs_iext_get_extent(ifp, *current_ext - 1, &adj_irec);
if (startoff < adj_irec.br_startoff + adj_irec.br_blockcount)
return -EINVAL;
if (xfs_bmse_can_merge(&adj_irec, got, offset_shift_fsb)) {
return xfs_bmse_merge(ip, whichfork, offset_shift_fsb,
*current_ext, got, &adj_irec,
cur, logflags, dfops);
}
} else {
startoff = got->br_startoff + offset_shift_fsb;
if (*current_ext >= (total_extents - 1))
goto update_current_ext;
xfs_iext_get_extent(ifp, *current_ext + 1, &adj_irec);
if (startoff + got->br_blockcount > adj_irec.br_startoff)
return -EINVAL;
if (xfs_bmse_can_merge(got, &adj_irec, offset_shift_fsb))
WARN_ON_ONCE(1);
}
update_current_ext:
*logflags |= XFS_ILOG_CORE;
new = *got;
new.br_startoff = startoff;
if (cur) {
error = xfs_bmbt_lookup_eq(cur, got->br_startoff,
got->br_startblock, got->br_blockcount, &i);
if (error)
return error;
XFS_WANT_CORRUPTED_RETURN(mp, i == 1);
error = xfs_bmbt_update(cur, new.br_startoff,
new.br_startblock, new.br_blockcount,
new.br_state);
if (error)
return error;
} else {
*logflags |= XFS_ILOG_DEXT;
}
xfs_iext_update_extent(ifp, *current_ext, &new);
if (direction == SHIFT_LEFT)
(*current_ext)++;
else
(*current_ext)--;
error = xfs_rmap_unmap_extent(mp, dfops, ip, whichfork, got);
if (error)
return error;
return xfs_rmap_map_extent(mp, dfops, ip, whichfork, &new);
}
int
xfs_bmap_shift_extents(
struct xfs_trans *tp,
struct xfs_inode *ip,
xfs_fileoff_t *next_fsb,
xfs_fileoff_t offset_shift_fsb,
int *done,
xfs_fileoff_t stop_fsb,
xfs_fsblock_t *firstblock,
struct xfs_defer_ops *dfops,
enum shift_direction direction,
int num_exts)
{
struct xfs_btree_cur *cur = NULL;
struct xfs_bmbt_irec got;
struct xfs_mount *mp = ip->i_mount;
struct xfs_ifork *ifp;
xfs_extnum_t nexts = 0;
xfs_extnum_t current_ext;
xfs_extnum_t total_extents;
xfs_extnum_t stop_extent;
int error = 0;
int whichfork = XFS_DATA_FORK;
int logflags = 0;
if (unlikely(XFS_TEST_ERROR(
(XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_EXTENTS &&
XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_BTREE),
mp, XFS_ERRTAG_BMAPIFORMAT))) {
XFS_ERROR_REPORT("xfs_bmap_shift_extents",
XFS_ERRLEVEL_LOW, mp);
return -EFSCORRUPTED;
}
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
ASSERT(xfs_isilocked(ip, XFS_IOLOCK_EXCL));
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
ASSERT(direction == SHIFT_LEFT || direction == SHIFT_RIGHT);
ifp = XFS_IFORK_PTR(ip, whichfork);
if (!(ifp->if_flags & XFS_IFEXTENTS)) {
error = xfs_iread_extents(tp, ip, whichfork);
if (error)
return error;
}
if (ifp->if_flags & XFS_IFBROOT) {
cur = xfs_bmbt_init_cursor(mp, tp, ip, whichfork);
cur->bc_private.b.firstblock = *firstblock;
cur->bc_private.b.dfops = dfops;
cur->bc_private.b.flags = 0;
}
total_extents = xfs_iext_count(ifp);
if (total_extents == 0) {
*done = 1;
goto del_cursor;
}
if (*next_fsb == NULLFSBLOCK) {
ASSERT(direction == SHIFT_RIGHT);
current_ext = total_extents - 1;
xfs_iext_get_extent(ifp, current_ext, &got);
if (stop_fsb > got.br_startoff) {
*done = 1;
goto del_cursor;
}
*next_fsb = got.br_startoff;
} else {
if (!xfs_iext_lookup_extent(ip, ifp, *next_fsb, &current_ext,
&got)) {
*done = 1;
goto del_cursor;
}
}
if (direction == SHIFT_RIGHT) {
struct xfs_bmbt_irec s;
xfs_iext_lookup_extent(ip, ifp, stop_fsb, &stop_extent, &s);
stop_extent--;
if (current_ext <= stop_extent) {
error = -EIO;
goto del_cursor;
}
} else {
stop_extent = total_extents;
if (current_ext >= stop_extent) {
error = -EIO;
goto del_cursor;
}
}
while (nexts++ < num_exts) {
error = xfs_bmse_shift_one(ip, whichfork, offset_shift_fsb,
&current_ext, &got, cur, &logflags,
direction, dfops);
if (error)
goto del_cursor;
if (direction == SHIFT_LEFT) {
total_extents = xfs_iext_count(ifp);
stop_extent = total_extents;
}
if (current_ext == stop_extent) {
*done = 1;
*next_fsb = NULLFSBLOCK;
break;
}
xfs_iext_get_extent(ifp, current_ext, &got);
}
if (!*done)
*next_fsb = got.br_startoff;
del_cursor:
if (cur)
xfs_btree_del_cursor(cur,
error ? XFS_BTREE_ERROR : XFS_BTREE_NOERROR);
if (logflags)
xfs_trans_log_inode(tp, ip, logflags);
return error;
}
STATIC int
xfs_bmap_split_extent_at(
struct xfs_trans *tp,
struct xfs_inode *ip,
xfs_fileoff_t split_fsb,
xfs_fsblock_t *firstfsb,
struct xfs_defer_ops *dfops)
{
int whichfork = XFS_DATA_FORK;
struct xfs_btree_cur *cur = NULL;
struct xfs_bmbt_irec got;
struct xfs_bmbt_irec new;
struct xfs_mount *mp = ip->i_mount;
struct xfs_ifork *ifp;
xfs_fsblock_t gotblkcnt;
xfs_extnum_t current_ext;
int error = 0;
int logflags = 0;
int i = 0;
if (unlikely(XFS_TEST_ERROR(
(XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_EXTENTS &&
XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_BTREE),
mp, XFS_ERRTAG_BMAPIFORMAT))) {
XFS_ERROR_REPORT("xfs_bmap_split_extent_at",
XFS_ERRLEVEL_LOW, mp);
return -EFSCORRUPTED;
}
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
ifp = XFS_IFORK_PTR(ip, whichfork);
if (!(ifp->if_flags & XFS_IFEXTENTS)) {
error = xfs_iread_extents(tp, ip, whichfork);
if (error)
return error;
}
if (!xfs_iext_lookup_extent(ip, ifp, split_fsb, &current_ext, &got) ||
got.br_startoff >= split_fsb)
return 0;
gotblkcnt = split_fsb - got.br_startoff;
new.br_startoff = split_fsb;
new.br_startblock = got.br_startblock + gotblkcnt;
new.br_blockcount = got.br_blockcount - gotblkcnt;
new.br_state = got.br_state;
if (ifp->if_flags & XFS_IFBROOT) {
cur = xfs_bmbt_init_cursor(mp, tp, ip, whichfork);
cur->bc_private.b.firstblock = *firstfsb;
cur->bc_private.b.dfops = dfops;
cur->bc_private.b.flags = 0;
error = xfs_bmbt_lookup_eq(cur, got.br_startoff,
got.br_startblock,
got.br_blockcount,
&i);
if (error)
goto del_cursor;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, del_cursor);
}
got.br_blockcount = gotblkcnt;
xfs_iext_update_extent(ifp, current_ext, &got);
logflags = XFS_ILOG_CORE;
if (cur) {
error = xfs_bmbt_update(cur, got.br_startoff,
got.br_startblock,
got.br_blockcount,
got.br_state);
if (error)
goto del_cursor;
} else
logflags |= XFS_ILOG_DEXT;
current_ext++;
xfs_iext_insert(ip, current_ext, 1, &new, 0);
XFS_IFORK_NEXT_SET(ip, whichfork,
XFS_IFORK_NEXTENTS(ip, whichfork) + 1);
if (cur) {
error = xfs_bmbt_lookup_eq(cur, new.br_startoff,
new.br_startblock, new.br_blockcount,
&i);
if (error)
goto del_cursor;
XFS_WANT_CORRUPTED_GOTO(mp, i == 0, del_cursor);
cur->bc_rec.b.br_state = new.br_state;
error = xfs_btree_insert(cur, &i);
if (error)
goto del_cursor;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, del_cursor);
}
if (xfs_bmap_needs_btree(ip, whichfork)) {
int tmp_logflags;
ASSERT(cur == NULL);
error = xfs_bmap_extents_to_btree(tp, ip, firstfsb, dfops,
&cur, 0, &tmp_logflags, whichfork);
logflags |= tmp_logflags;
}
del_cursor:
if (cur) {
cur->bc_private.b.allocated = 0;
xfs_btree_del_cursor(cur,
error ? XFS_BTREE_ERROR : XFS_BTREE_NOERROR);
}
if (logflags)
xfs_trans_log_inode(tp, ip, logflags);
return error;
}
int
xfs_bmap_split_extent(
struct xfs_inode *ip,
xfs_fileoff_t split_fsb)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_trans *tp;
struct xfs_defer_ops dfops;
xfs_fsblock_t firstfsb;
int error;
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_write,
XFS_DIOSTRAT_SPACE_RES(mp, 0), 0, 0, &tp);
if (error)
return error;
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, XFS_ILOCK_EXCL);
xfs_defer_init(&dfops, &firstfsb);
error = xfs_bmap_split_extent_at(tp, ip, split_fsb,
&firstfsb, &dfops);
if (error)
goto out;
error = xfs_defer_finish(&tp, &dfops);
if (error)
goto out;
return xfs_trans_commit(tp);
out:
xfs_defer_cancel(&dfops);
xfs_trans_cancel(tp);
return error;
}
static bool
xfs_bmap_is_update_needed(
struct xfs_bmbt_irec *bmap)
{
return bmap->br_startblock != HOLESTARTBLOCK &&
bmap->br_startblock != DELAYSTARTBLOCK;
}
static int
__xfs_bmap_add(
struct xfs_mount *mp,
struct xfs_defer_ops *dfops,
enum xfs_bmap_intent_type type,
struct xfs_inode *ip,
int whichfork,
struct xfs_bmbt_irec *bmap)
{
int error;
struct xfs_bmap_intent *bi;
trace_xfs_bmap_defer(mp,
XFS_FSB_TO_AGNO(mp, bmap->br_startblock),
type,
XFS_FSB_TO_AGBNO(mp, bmap->br_startblock),
ip->i_ino, whichfork,
bmap->br_startoff,
bmap->br_blockcount,
bmap->br_state);
bi = kmem_alloc(sizeof(struct xfs_bmap_intent), KM_SLEEP | KM_NOFS);
INIT_LIST_HEAD(&bi->bi_list);
bi->bi_type = type;
bi->bi_owner = ip;
bi->bi_whichfork = whichfork;
bi->bi_bmap = *bmap;
error = xfs_defer_ijoin(dfops, bi->bi_owner);
if (error) {
kmem_free(bi);
return error;
}
xfs_defer_add(dfops, XFS_DEFER_OPS_TYPE_BMAP, &bi->bi_list);
return 0;
}
int
xfs_bmap_map_extent(
struct xfs_mount *mp,
struct xfs_defer_ops *dfops,
struct xfs_inode *ip,
struct xfs_bmbt_irec *PREV)
{
if (!xfs_bmap_is_update_needed(PREV))
return 0;
return __xfs_bmap_add(mp, dfops, XFS_BMAP_MAP, ip,
XFS_DATA_FORK, PREV);
}
int
xfs_bmap_unmap_extent(
struct xfs_mount *mp,
struct xfs_defer_ops *dfops,
struct xfs_inode *ip,
struct xfs_bmbt_irec *PREV)
{
if (!xfs_bmap_is_update_needed(PREV))
return 0;
return __xfs_bmap_add(mp, dfops, XFS_BMAP_UNMAP, ip,
XFS_DATA_FORK, PREV);
}
int
xfs_bmap_finish_one(
struct xfs_trans *tp,
struct xfs_defer_ops *dfops,
struct xfs_inode *ip,
enum xfs_bmap_intent_type type,
int whichfork,
xfs_fileoff_t startoff,
xfs_fsblock_t startblock,
xfs_filblks_t *blockcount,
xfs_exntst_t state)
{
xfs_fsblock_t firstfsb;
int error = 0;
firstfsb = NULLFSBLOCK;
trace_xfs_bmap_deferred(tp->t_mountp,
XFS_FSB_TO_AGNO(tp->t_mountp, startblock), type,
XFS_FSB_TO_AGBNO(tp->t_mountp, startblock),
ip->i_ino, whichfork, startoff, *blockcount, state);
if (WARN_ON_ONCE(whichfork != XFS_DATA_FORK))
return -EFSCORRUPTED;
if (XFS_TEST_ERROR(false, tp->t_mountp,
XFS_ERRTAG_BMAP_FINISH_ONE))
return -EIO;
switch (type) {
case XFS_BMAP_MAP:
error = xfs_bmapi_remap(tp, ip, startoff, *blockcount,
startblock, dfops);
*blockcount = 0;
break;
case XFS_BMAP_UNMAP:
error = __xfs_bunmapi(tp, ip, startoff, blockcount,
XFS_BMAPI_REMAP, 1, &firstfsb, dfops);
break;
default:
ASSERT(0);
error = -EFSCORRUPTED;
}
return error;
}
