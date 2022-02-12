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
return XFS_IFORK_FORMAT(ip, whichfork) == XFS_DINODE_FMT_EXTENTS &&
XFS_IFORK_NEXTENTS(ip, whichfork) >
XFS_IFORK_MAXEXT(ip, whichfork);
}
static inline bool xfs_bmap_wants_extents(struct xfs_inode *ip, int whichfork)
{
return XFS_IFORK_FORMAT(ip, whichfork) == XFS_DINODE_FMT_BTREE &&
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
if (bp_release) {
bp_release = 0;
xfs_trans_brelse(NULL, bp);
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
ifp = XFS_IFORK_PTR(ip, whichfork);
ASSERT(cnt == (ifp->if_bytes / (uint)sizeof(xfs_bmbt_rec_t)));
for (idx = 0; idx < cnt; idx++)
trace_xfs_extlist(ip, idx, whichfork, caller_ip);
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
xfs_fsblock_t bno,
xfs_filblks_t len,
xfs_bmap_free_t *flist,
xfs_mount_t *mp)
{
xfs_bmap_free_item_t *cur;
xfs_bmap_free_item_t *new;
xfs_bmap_free_item_t *prev;
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
new->xbfi_startblock = bno;
new->xbfi_blockcount = (xfs_extlen_t)len;
for (prev = NULL, cur = flist->xbf_first;
cur != NULL;
prev = cur, cur = cur->xbfi_next) {
if (cur->xbfi_startblock >= bno)
break;
}
if (prev)
prev->xbfi_next = new;
else
flist->xbf_first = new;
new->xbfi_next = cur;
flist->xbf_count++;
}
void
xfs_bmap_del_free(
xfs_bmap_free_t *flist,
xfs_bmap_free_item_t *prev,
xfs_bmap_free_item_t *free)
{
if (prev)
prev->xbfi_next = free->xbfi_next;
else
flist->xbf_first = free->xbfi_next;
flist->xbf_count--;
kmem_zone_free(xfs_bmap_free_item_zone, free);
}
void
xfs_bmap_cancel(
xfs_bmap_free_t *flist)
{
xfs_bmap_free_item_t *free;
xfs_bmap_free_item_t *next;
if (flist->xbf_count == 0)
return;
ASSERT(flist->xbf_first != NULL);
for (free = flist->xbf_first; free; free = next) {
next = free->xbfi_next;
xfs_bmap_del_free(flist, NULL, free);
}
ASSERT(flist->xbf_count == 0);
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
mp = ip->i_mount;
ifp = XFS_IFORK_PTR(ip, whichfork);
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
xfs_bmap_add_free(cbno, 1, cur->bc_private.b.flist, mp);
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
xfs_bmap_free_t *flist,
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
ifp = XFS_IFORK_PTR(ip, whichfork);
ASSERT(XFS_IFORK_FORMAT(ip, whichfork) == XFS_DINODE_FMT_EXTENTS);
xfs_iroot_realloc(ip, 1, whichfork);
ifp->if_flags |= XFS_IFBROOT;
block = ifp->if_broot;
if (xfs_sb_version_hascrc(&mp->m_sb))
xfs_btree_init_block_int(mp, block, XFS_BUF_DADDR_NULL,
XFS_BMAP_CRC_MAGIC, 1, 1, ip->i_ino,
XFS_BTREE_LONG_PTRS | XFS_BTREE_CRC_BLOCKS);
else
xfs_btree_init_block_int(mp, block, XFS_BUF_DADDR_NULL,
XFS_BMAP_MAGIC, 1, 1, ip->i_ino,
XFS_BTREE_LONG_PTRS);
cur = xfs_bmbt_init_cursor(mp, tp, ip, whichfork);
cur->bc_private.b.firstblock = *firstblock;
cur->bc_private.b.flist = flist;
cur->bc_private.b.flags = wasdel ? XFS_BTCUR_BPRV_WASDEL : 0;
XFS_IFORK_FMT_SET(ip, whichfork, XFS_DINODE_FMT_BTREE);
memset(&args, 0, sizeof(args));
args.tp = tp;
args.mp = mp;
args.firstblock = *firstblock;
if (*firstblock == NULLFSBLOCK) {
args.type = XFS_ALLOCTYPE_START_BNO;
args.fsbno = XFS_INO_TO_FSB(mp, ip->i_ino);
} else if (flist->xbf_low) {
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
ASSERT(args.fsbno != NULLFSBLOCK);
ASSERT(*firstblock == NULLFSBLOCK ||
args.agno == XFS_FSB_TO_AGNO(mp, *firstblock) ||
(flist->xbf_low &&
args.agno > XFS_FSB_TO_AGNO(mp, *firstblock)));
*firstblock = cur->bc_private.b.firstblock = args.fsbno;
cur->bc_private.b.allocated++;
ip->i_d.di_nblocks++;
xfs_trans_mod_dquot_byino(tp, ip, XFS_TRANS_DQ_BCOUNT, 1L);
abp = xfs_btree_get_bufl(mp, tp, args.fsbno, 0);
abp->b_ops = &xfs_bmbt_buf_ops;
ablock = XFS_BUF_TO_BLOCK(abp);
if (xfs_sb_version_hascrc(&mp->m_sb))
xfs_btree_init_block_int(mp, ablock, abp->b_bn,
XFS_BMAP_CRC_MAGIC, 0, 0, ip->i_ino,
XFS_BTREE_LONG_PTRS | XFS_BTREE_CRC_BLOCKS);
else
xfs_btree_init_block_int(mp, ablock, abp->b_bn,
XFS_BMAP_MAGIC, 0, 0, ip->i_ino,
XFS_BTREE_LONG_PTRS);
arp = XFS_BMBT_REC_ADDR(mp, ablock, 1);
nextents = ifp->if_bytes / (uint)sizeof(xfs_bmbt_rec_t);
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
xfs_bmbt_rec_host_t *ep;
ASSERT(!(S_ISREG(ip->i_d.di_mode) && whichfork == XFS_DATA_FORK));
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
xfs_trans_log_buf(tp, bp, 0, ifp->if_bytes - 1);
xfs_idata_realloc(ip, -ifp->if_bytes, whichfork);
xfs_bmap_local_to_extents_empty(ip, whichfork);
flags |= XFS_ILOG_CORE;
xfs_iext_add(ifp, 0, 1);
ep = xfs_iext_get_ext(ifp, 0);
xfs_bmbt_set_allf(ep, 0, args.fsbno, 1, XFS_EXT_NORM);
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
xfs_bmap_free_t *flist,
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
cur->bc_private.b.flist = flist;
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
xfs_bmap_free_t *flist,
int *flags)
{
xfs_btree_cur_t *cur;
int error;
if (ip->i_d.di_nextents * sizeof(xfs_bmbt_rec_t) <= XFS_IFORK_DSIZE(ip))
return 0;
cur = NULL;
error = xfs_bmap_extents_to_btree(tp, ip, firstblock, flist, &cur, 0,
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
xfs_bmap_free_t *flist,
int *flags)
{
xfs_da_args_t dargs;
if (ip->i_df.if_bytes <= XFS_IFORK_DSIZE(ip))
return 0;
if (S_ISDIR(ip->i_d.di_mode)) {
memset(&dargs, 0, sizeof(dargs));
dargs.geo = ip->i_mount->m_dir_geo;
dargs.dp = ip;
dargs.firstblock = firstblock;
dargs.flist = flist;
dargs.total = dargs.geo->fsbcount;
dargs.whichfork = XFS_DATA_FORK;
dargs.trans = tp;
return xfs_dir2_sf_to_block(&dargs);
}
if (S_ISLNK(ip->i_d.di_mode))
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
xfs_bmap_free_t flist;
xfs_mount_t *mp;
xfs_trans_t *tp;
int blks;
int version = 1;
int committed;
int logflags;
int error;
ASSERT(XFS_IFORK_Q(ip) == 0);
mp = ip->i_mount;
ASSERT(!XFS_NOT_DQATTACHED(mp, ip));
tp = xfs_trans_alloc(mp, XFS_TRANS_ADDAFORK);
blks = XFS_ADDAFORK_SPACE_RES(mp);
if (rsvd)
tp->t_flags |= XFS_TRANS_RESERVE;
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_addafork, blks, 0);
if (error) {
xfs_trans_cancel(tp);
return error;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
error = xfs_trans_reserve_quota_nblks(tp, ip, blks, 0, rsvd ?
XFS_QMOPT_RES_REGBLKS | XFS_QMOPT_FORCE_RES :
XFS_QMOPT_RES_REGBLKS);
if (error)
goto trans_cancel;
if (XFS_IFORK_Q(ip))
goto trans_cancel;
if (ip->i_d.di_aformat != XFS_DINODE_FMT_EXTENTS) {
ASSERT(ip->i_d.di_aformat == 0);
ip->i_d.di_aformat = XFS_DINODE_FMT_EXTENTS;
}
ASSERT(ip->i_d.di_anextents == 0);
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
xfs_bmap_init(&flist, &firstblock);
switch (ip->i_d.di_format) {
case XFS_DINODE_FMT_LOCAL:
error = xfs_bmap_add_attrfork_local(tp, ip, &firstblock, &flist,
&logflags);
break;
case XFS_DINODE_FMT_EXTENTS:
error = xfs_bmap_add_attrfork_extents(tp, ip, &firstblock,
&flist, &logflags);
break;
case XFS_DINODE_FMT_BTREE:
error = xfs_bmap_add_attrfork_btree(tp, ip, &firstblock, &flist,
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
error = xfs_bmap_finish(&tp, &flist, &committed);
if (error)
goto bmap_cancel;
error = xfs_trans_commit(tp);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
bmap_cancel:
xfs_bmap_cancel(&flist);
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
xfs_exntfmt_t exntf;
xfs_extnum_t i, j;
xfs_ifork_t *ifp;
int level;
xfs_mount_t *mp;
__be64 *pp;
xfs_extnum_t room;
bno = NULLFSBLOCK;
mp = ip->i_mount;
ifp = XFS_IFORK_PTR(ip, whichfork);
exntf = (whichfork != XFS_DATA_FORK) ? XFS_EXTFMT_NOSTATE :
XFS_EXTFMT_INODE(ip);
block = ifp->if_broot;
level = be16_to_cpu(block->bb_level);
ASSERT(level > 0);
pp = XFS_BMAP_BROOT_PTR_ADDR(mp, block, 1, ifp->if_broot_bytes);
bno = be64_to_cpu(*pp);
ASSERT(bno != NULLFSBLOCK);
ASSERT(XFS_FSB_TO_AGNO(mp, bno) < mp->m_sb.sb_agcount);
ASSERT(XFS_FSB_TO_AGBNO(mp, bno) < mp->m_sb.sb_agblocks);
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
room = ifp->if_bytes / (uint)sizeof(xfs_bmbt_rec_t);
i = 0;
for (;;) {
xfs_bmbt_rec_t *frp;
xfs_fsblock_t nextbno;
xfs_extnum_t num_recs;
xfs_extnum_t start;
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
start = i;
for (j = 0; j < num_recs; j++, i++, frp++) {
xfs_bmbt_rec_host_t *trp = xfs_iext_get_ext(ifp, i);
trp->l0 = be64_to_cpu(frp->l0);
trp->l1 = be64_to_cpu(frp->l1);
}
if (exntf == XFS_EXTFMT_NOSTATE) {
if (unlikely(xfs_check_nostate_extents(ifp,
start, num_recs))) {
XFS_ERROR_REPORT("xfs_bmap_read_extents(2)",
XFS_ERRLEVEL_LOW,
ip->i_mount);
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
ASSERT(i == (ifp->if_bytes / (uint)sizeof(xfs_bmbt_rec_t)));
ASSERT(i == XFS_IFORK_NEXTENTS(ip, whichfork));
XFS_BMAP_TRACE_EXLIST(ip, i, whichfork);
return 0;
error0:
xfs_trans_brelse(tp, bp);
return -EFSCORRUPTED;
}
STATIC xfs_bmbt_rec_host_t *
xfs_bmap_search_multi_extents(
xfs_ifork_t *ifp,
xfs_fileoff_t bno,
int *eofp,
xfs_extnum_t *lastxp,
xfs_bmbt_irec_t *gotp,
xfs_bmbt_irec_t *prevp)
{
xfs_bmbt_rec_host_t *ep;
xfs_extnum_t lastx;
gotp->br_startoff = 0xffa5a5a5a5a5a5a5LL;
gotp->br_blockcount = 0xa55a5a5a5a5a5a5aLL;
gotp->br_state = XFS_EXT_INVALID;
gotp->br_startblock = 0xffffa5a5a5a5a5a5LL;
prevp->br_startoff = NULLFILEOFF;
ep = xfs_iext_bno_to_ext(ifp, bno, &lastx);
if (lastx > 0) {
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, lastx - 1), prevp);
}
if (lastx < (ifp->if_bytes / (uint)sizeof(xfs_bmbt_rec_t))) {
xfs_bmbt_get_all(ep, gotp);
*eofp = 0;
} else {
if (lastx > 0) {
*gotp = *prevp;
}
*eofp = 1;
ep = NULL;
}
*lastxp = lastx;
return ep;
}
STATIC xfs_bmbt_rec_host_t *
xfs_bmap_search_extents(
xfs_inode_t *ip,
xfs_fileoff_t bno,
int fork,
int *eofp,
xfs_extnum_t *lastxp,
xfs_bmbt_irec_t *gotp,
xfs_bmbt_irec_t *prevp)
{
xfs_ifork_t *ifp;
xfs_bmbt_rec_host_t *ep;
XFS_STATS_INC(xs_look_exlist);
ifp = XFS_IFORK_PTR(ip, fork);
ep = xfs_bmap_search_multi_extents(ifp, bno, eofp, lastxp, gotp, prevp);
if (unlikely(!(gotp->br_startblock) && (*lastxp != NULLEXTNUM) &&
!(XFS_IS_REALTIME_INODE(ip) && fork == XFS_DATA_FORK))) {
xfs_alert_tag(ip->i_mount, XFS_PTAG_FSBLOCK_ZERO,
"Access to block zero in inode %llu "
"start_block: %llx start_off: %llx "
"blkcnt: %llx extent-state: %x lastx: %x",
(unsigned long long)ip->i_ino,
(unsigned long long)gotp->br_startblock,
(unsigned long long)gotp->br_startoff,
(unsigned long long)gotp->br_blockcount,
gotp->br_state, *lastxp);
*lastxp = NULLEXTNUM;
*eofp = 1;
return NULL;
}
return ep;
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
xfs_fileoff_t off;
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
nextents = ifp->if_bytes / (uint)sizeof(xfs_bmbt_rec_t);
for (idx = 0, lastaddr = 0, max = lowest; idx < nextents; idx++) {
xfs_bmbt_rec_host_t *ep = xfs_iext_get_ext(ifp, idx);
off = xfs_bmbt_get_startoff(ep);
if (off >= lowest + len && off - max >= len) {
*first_unused = max;
return 0;
}
lastaddr = off + xfs_bmbt_get_blockcount(ep);
max = XFS_FILEOFF_MAX(lastaddr, lowest);
}
*first_unused = max;
return 0;
}
int
xfs_bmap_last_before(
xfs_trans_t *tp,
xfs_inode_t *ip,
xfs_fileoff_t *last_block,
int whichfork)
{
xfs_fileoff_t bno;
int eof;
xfs_bmbt_rec_host_t *ep;
int error;
xfs_bmbt_irec_t got;
xfs_ifork_t *ifp;
xfs_extnum_t lastx;
xfs_bmbt_irec_t prev;
if (XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_BTREE &&
XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_EXTENTS &&
XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_LOCAL)
return -EIO;
if (XFS_IFORK_FORMAT(ip, whichfork) == XFS_DINODE_FMT_LOCAL) {
*last_block = 0;
return 0;
}
ifp = XFS_IFORK_PTR(ip, whichfork);
if (!(ifp->if_flags & XFS_IFEXTENTS) &&
(error = xfs_iread_extents(tp, ip, whichfork)))
return error;
bno = *last_block - 1;
ep = xfs_bmap_search_extents(ip, bno, whichfork, &eof, &lastx, &got,
&prev);
if (eof || xfs_bmbt_get_startoff(ep) > bno) {
if (prev.br_startoff == NULLFILEOFF)
*last_block = 0;
else
*last_block = prev.br_startoff + prev.br_blockcount;
}
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
nextents = ifp->if_bytes / sizeof(xfs_bmbt_rec_t);
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
bma->aeof = 0;
error = xfs_bmap_last_extent(NULL, bma->ip, whichfork, &rec,
&is_empty);
if (error)
return error;
if (is_empty) {
bma->aeof = 1;
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
struct xfs_bmalloca *bma)
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
mp = bma->tp ? bma->tp->t_mountp : NULL;
ifp = XFS_IFORK_PTR(bma->ip, XFS_DATA_FORK);
ASSERT(bma->idx >= 0);
ASSERT(bma->idx <= ifp->if_bytes / sizeof(struct xfs_bmbt_rec));
ASSERT(!isnullstartblock(new->br_startblock));
ASSERT(!bma->cur ||
(bma->cur->bc_private.b.flags & XFS_BTCUR_BPRV_WASDEL));
XFS_STATS_INC(xs_add_exlist);
#define LEFT r[0]
#define RIGHT r[1]
#define PREV r[2]
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
if (bma->idx < bma->ip->i_df.if_bytes / (uint)sizeof(xfs_bmbt_rec_t) - 1) {
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
bma->ip->i_d.di_nextents--;
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
trace_xfs_bmap_post_update(bma->ip, bma->idx, state, _THIS_IP_);
bma->ip->i_d.di_nextents++;
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
bma->ip->i_d.di_nextents++;
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
if (xfs_bmap_needs_btree(bma->ip, XFS_DATA_FORK)) {
error = xfs_bmap_extents_to_btree(bma->tp, bma->ip,
bma->firstblock, bma->flist,
&bma->cur, 1, &tmp_rval, XFS_DATA_FORK);
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
bma->ip->i_d.di_nextents++;
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
if (xfs_bmap_needs_btree(bma->ip, XFS_DATA_FORK)) {
error = xfs_bmap_extents_to_btree(bma->tp, bma->ip,
bma->firstblock, bma->flist, &bma->cur, 1,
&tmp_rval, XFS_DATA_FORK);
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
bma->ip->i_d.di_nextents++;
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
if (xfs_bmap_needs_btree(bma->ip, XFS_DATA_FORK)) {
error = xfs_bmap_extents_to_btree(bma->tp, bma->ip,
bma->firstblock, bma->flist, &bma->cur,
1, &tmp_rval, XFS_DATA_FORK);
rval |= tmp_rval;
if (error)
goto done;
}
temp = xfs_bmap_worst_indlen(bma->ip, temp);
temp2 = xfs_bmap_worst_indlen(bma->ip, temp2);
diff = (int)(temp + temp2 - startblockval(PREV.br_startblock) -
(bma->cur ? bma->cur->bc_private.b.allocated : 0));
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
if (xfs_bmap_needs_btree(bma->ip, XFS_DATA_FORK)) {
int tmp_logflags;
ASSERT(bma->cur == NULL);
error = xfs_bmap_extents_to_btree(bma->tp, bma->ip,
bma->firstblock, bma->flist, &bma->cur,
da_old > 0, &tmp_logflags, XFS_DATA_FORK);
bma->logflags |= tmp_logflags;
if (error)
goto done;
}
if (da_old || da_new) {
temp = da_new;
if (bma->cur)
temp += bma->cur->bc_private.b.allocated;
ASSERT(temp <= da_old);
if (temp < da_old)
xfs_mod_fdblocks(bma->ip->i_mount,
(int64_t)(da_old - temp), false);
}
if (bma->cur)
bma->cur->bc_private.b.allocated = 0;
xfs_bmap_check_leaf_extents(bma->cur, bma->ip, XFS_DATA_FORK);
done:
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
xfs_extnum_t *idx,
xfs_btree_cur_t **curp,
xfs_bmbt_irec_t *new,
xfs_fsblock_t *first,
xfs_bmap_free_t *flist,
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
struct xfs_mount *mp = tp->t_mountp;
*logflagsp = 0;
cur = *curp;
ifp = XFS_IFORK_PTR(ip, XFS_DATA_FORK);
ASSERT(*idx >= 0);
ASSERT(*idx <= ifp->if_bytes / sizeof(struct xfs_bmbt_rec));
ASSERT(!isnullstartblock(new->br_startblock));
XFS_STATS_INC(xs_add_exlist);
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
if (*idx < ip->i_df.if_bytes / (uint)sizeof(xfs_bmbt_rec_t) - 1) {
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
ip->i_d.di_nextents -= 2;
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
ip->i_d.di_nextents--;
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
ip->i_d.di_nextents--;
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
ip->i_d.di_nextents++;
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
ip->i_d.di_nextents++;
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
ip->i_d.di_nextents += 2;
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
if (xfs_bmap_needs_btree(ip, XFS_DATA_FORK)) {
int tmp_logflags;
ASSERT(cur == NULL);
error = xfs_bmap_extents_to_btree(tp, ip, first, flist, &cur,
0, &tmp_logflags, XFS_DATA_FORK);
*logflagsp |= tmp_logflags;
if (error)
goto done;
}
if (cur) {
cur->bc_private.b.allocated = 0;
*curp = cur;
}
xfs_bmap_check_leaf_extents(*curp, ip, XFS_DATA_FORK);
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
ifp = XFS_IFORK_PTR(ip, XFS_DATA_FORK);
state = 0;
ASSERT(isnullstartblock(new->br_startblock));
if (*idx > 0) {
state |= BMAP_LEFT_VALID;
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, *idx - 1), &left);
if (isnullstartblock(left.br_startblock))
state |= BMAP_LEFT_DELAY;
}
if (*idx < ip->i_df.if_bytes / (uint)sizeof(xfs_bmbt_rec_t)) {
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
newlen = xfs_bmap_worst_indlen(ip, temp);
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
newlen = xfs_bmap_worst_indlen(ip, temp);
xfs_bmbt_set_startblock(xfs_iext_get_ext(ifp, *idx),
nullstartblock((int)newlen));
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
break;
case BMAP_RIGHT_CONTIG:
trace_xfs_bmap_pre_update(ip, *idx, state, _THIS_IP_);
temp = new->br_blockcount + right.br_blockcount;
oldlen = startblockval(new->br_startblock) +
startblockval(right.br_startblock);
newlen = xfs_bmap_worst_indlen(ip, temp);
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
struct xfs_bmalloca *bma,
int whichfork)
{
struct xfs_bmbt_irec *new = &bma->got;
int error;
int i;
xfs_ifork_t *ifp;
xfs_bmbt_irec_t left;
xfs_bmbt_irec_t right;
int rval=0;
int state;
struct xfs_mount *mp;
mp = bma->tp ? bma->tp->t_mountp : NULL;
ifp = XFS_IFORK_PTR(bma->ip, whichfork);
ASSERT(bma->idx >= 0);
ASSERT(bma->idx <= ifp->if_bytes / sizeof(struct xfs_bmbt_rec));
ASSERT(!isnullstartblock(new->br_startblock));
ASSERT(!bma->cur ||
!(bma->cur->bc_private.b.flags & XFS_BTCUR_BPRV_WASDEL));
XFS_STATS_INC(xs_add_exlist);
state = 0;
if (whichfork == XFS_ATTR_FORK)
state |= BMAP_ATTRFORK;
if (bma->idx > 0) {
state |= BMAP_LEFT_VALID;
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, bma->idx - 1), &left);
if (isnullstartblock(left.br_startblock))
state |= BMAP_LEFT_DELAY;
}
if (bma->idx < ifp->if_bytes / (uint)sizeof(xfs_bmbt_rec_t)) {
state |= BMAP_RIGHT_VALID;
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, bma->idx), &right);
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
--bma->idx;
trace_xfs_bmap_pre_update(bma->ip, bma->idx, state, _THIS_IP_);
xfs_bmbt_set_blockcount(xfs_iext_get_ext(ifp, bma->idx),
left.br_blockcount + new->br_blockcount +
right.br_blockcount);
trace_xfs_bmap_post_update(bma->ip, bma->idx, state, _THIS_IP_);
xfs_iext_remove(bma->ip, bma->idx + 1, 1, state);
XFS_IFORK_NEXT_SET(bma->ip, whichfork,
XFS_IFORK_NEXTENTS(bma->ip, whichfork) - 1);
if (bma->cur == NULL) {
rval = XFS_ILOG_CORE | xfs_ilog_fext(whichfork);
} else {
rval = XFS_ILOG_CORE;
error = xfs_bmbt_lookup_eq(bma->cur, right.br_startoff,
right.br_startblock, right.br_blockcount,
&i);
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
error = xfs_bmbt_update(bma->cur, left.br_startoff,
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
--bma->idx;
trace_xfs_bmap_pre_update(bma->ip, bma->idx, state, _THIS_IP_);
xfs_bmbt_set_blockcount(xfs_iext_get_ext(ifp, bma->idx),
left.br_blockcount + new->br_blockcount);
trace_xfs_bmap_post_update(bma->ip, bma->idx, state, _THIS_IP_);
if (bma->cur == NULL) {
rval = xfs_ilog_fext(whichfork);
} else {
rval = 0;
error = xfs_bmbt_lookup_eq(bma->cur, left.br_startoff,
left.br_startblock, left.br_blockcount,
&i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
error = xfs_bmbt_update(bma->cur, left.br_startoff,
left.br_startblock,
left.br_blockcount +
new->br_blockcount,
left.br_state);
if (error)
goto done;
}
break;
case BMAP_RIGHT_CONTIG:
trace_xfs_bmap_pre_update(bma->ip, bma->idx, state, _THIS_IP_);
xfs_bmbt_set_allf(xfs_iext_get_ext(ifp, bma->idx),
new->br_startoff, new->br_startblock,
new->br_blockcount + right.br_blockcount,
right.br_state);
trace_xfs_bmap_post_update(bma->ip, bma->idx, state, _THIS_IP_);
if (bma->cur == NULL) {
rval = xfs_ilog_fext(whichfork);
} else {
rval = 0;
error = xfs_bmbt_lookup_eq(bma->cur,
right.br_startoff,
right.br_startblock,
right.br_blockcount, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
error = xfs_bmbt_update(bma->cur, new->br_startoff,
new->br_startblock,
new->br_blockcount +
right.br_blockcount,
right.br_state);
if (error)
goto done;
}
break;
case 0:
xfs_iext_insert(bma->ip, bma->idx, 1, new, state);
XFS_IFORK_NEXT_SET(bma->ip, whichfork,
XFS_IFORK_NEXTENTS(bma->ip, whichfork) + 1);
if (bma->cur == NULL) {
rval = XFS_ILOG_CORE | xfs_ilog_fext(whichfork);
} else {
rval = XFS_ILOG_CORE;
error = xfs_bmbt_lookup_eq(bma->cur,
new->br_startoff,
new->br_startblock,
new->br_blockcount, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 0, done);
bma->cur->bc_rec.b.br_state = new->br_state;
error = xfs_btree_insert(bma->cur, &i);
if (error)
goto done;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, done);
}
break;
}
if (xfs_bmap_needs_btree(bma->ip, whichfork)) {
int tmp_logflags;
ASSERT(bma->cur == NULL);
error = xfs_bmap_extents_to_btree(bma->tp, bma->ip,
bma->firstblock, bma->flist, &bma->cur,
0, &tmp_logflags, whichfork);
bma->logflags |= tmp_logflags;
if (error)
goto done;
}
if (bma->cur)
bma->cur->bc_private.b.allocated = 0;
xfs_bmap_check_leaf_extents(bma->cur, bma->ip, whichfork);
done:
bma->logflags |= rval;
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
rt = XFS_IS_REALTIME_INODE(ap->ip) && ap->userdata;
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
xfs_alloc_min_freelist(mp, pag));
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
xfs_extlen_t align;
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
align = ap->userdata ? xfs_get_extsz_hint(ap->ip) : 0;
if (unlikely(align)) {
error = xfs_bmap_extsize_align(mp, &ap->got, &ap->prev,
align, 0, ap->eof, 0, ap->conv,
&ap->offset, &ap->length);
ASSERT(!error);
ASSERT(ap->length);
}
nullfb = *ap->firstblock == NULLFSBLOCK;
fb_agno = nullfb ? NULLAGNUMBER : XFS_FSB_TO_AGNO(mp, *ap->firstblock);
if (nullfb) {
if (ap->userdata && xfs_inode_is_filestream(ap->ip)) {
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
args.maxlen = MIN(ap->length, XFS_ALLOC_AG_MAX_USABLE(mp));
args.firstblock = *ap->firstblock;
blen = 0;
if (nullfb) {
if (ap->userdata && xfs_inode_is_filestream(ap->ip))
error = xfs_bmap_btalloc_filestreams(ap, &args, &blen);
else
error = xfs_bmap_btalloc_nullfb(ap, &args, &blen);
if (error)
return error;
} else if (ap->flist->xbf_low) {
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
if (unlikely(align)) {
args.prod = align;
if ((args.mod = (xfs_extlen_t)do_mod(ap->offset, args.prod)))
args.mod = (xfs_extlen_t)(args.prod - args.mod);
} else if (mp->m_sb.sb_blocksize >= PAGE_CACHE_SIZE) {
args.prod = 1;
args.mod = 0;
} else {
args.prod = PAGE_CACHE_SIZE >> mp->m_sb.sb_blocklog;
if ((args.mod = (xfs_extlen_t)(do_mod(ap->offset, args.prod))))
args.mod = (xfs_extlen_t)(args.prod - args.mod);
}
if (!ap->flist->xbf_low && ap->aeof) {
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
args.isfl = 0;
args.userdata = ap->userdata;
if ((error = xfs_alloc_vextent(&args)))
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
args.minleft = 0;
if ((error = xfs_alloc_vextent(&args)))
return error;
ap->flist->xbf_low = 1;
}
if (args.fsbno != NULLFSBLOCK) {
ASSERT(*ap->firstblock == NULLFSBLOCK ||
XFS_FSB_TO_AGNO(mp, *ap->firstblock) ==
XFS_FSB_TO_AGNO(mp, args.fsbno) ||
(ap->flist->xbf_low &&
XFS_FSB_TO_AGNO(mp, *ap->firstblock) <
XFS_FSB_TO_AGNO(mp, args.fsbno)));
ap->blkno = args.fsbno;
if (*ap->firstblock == NULLFSBLOCK)
*ap->firstblock = args.fsbno;
ASSERT(nullfb || fb_agno == args.agno ||
(ap->flist->xbf_low && fb_agno < args.agno));
ap->length = args.len;
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
if (XFS_IS_REALTIME_INODE(ap->ip) && ap->userdata)
return xfs_bmap_rtalloc(ap);
return xfs_bmap_btalloc(ap);
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
struct xfs_bmbt_irec prev;
xfs_fileoff_t obno;
xfs_fileoff_t end;
xfs_extnum_t lastx;
int error;
int eof;
int n = 0;
int whichfork = (flags & XFS_BMAPI_ATTRFORK) ?
XFS_ATTR_FORK : XFS_DATA_FORK;
ASSERT(*nmap >= 1);
ASSERT(!(flags & ~(XFS_BMAPI_ATTRFORK|XFS_BMAPI_ENTIRE|
XFS_BMAPI_IGSTATE)));
ASSERT(xfs_isilocked(ip, XFS_ILOCK_SHARED|XFS_ILOCK_EXCL));
if (unlikely(XFS_TEST_ERROR(
(XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_EXTENTS &&
XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_BTREE),
mp, XFS_ERRTAG_BMAPIFORMAT, XFS_RANDOM_BMAPIFORMAT))) {
XFS_ERROR_REPORT("xfs_bmapi_read", XFS_ERRLEVEL_LOW, mp);
return -EFSCORRUPTED;
}
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
XFS_STATS_INC(xs_blk_mapr);
ifp = XFS_IFORK_PTR(ip, whichfork);
if (!(ifp->if_flags & XFS_IFEXTENTS)) {
error = xfs_iread_extents(NULL, ip, whichfork);
if (error)
return error;
}
xfs_bmap_search_extents(ip, bno, whichfork, &eof, &lastx, &got, &prev);
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
if (++lastx < ifp->if_bytes / sizeof(xfs_bmbt_rec_t))
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, lastx), &got);
else
eof = 1;
}
*nmap = n;
return 0;
}
STATIC int
xfs_bmapi_reserve_delalloc(
struct xfs_inode *ip,
xfs_fileoff_t aoff,
xfs_filblks_t len,
struct xfs_bmbt_irec *got,
struct xfs_bmbt_irec *prev,
xfs_extnum_t *lastx,
int eof)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_ifork *ifp = XFS_IFORK_PTR(ip, XFS_DATA_FORK);
xfs_extlen_t alen;
xfs_extlen_t indlen;
char rt = XFS_IS_REALTIME_INODE(ip);
xfs_extlen_t extsz;
int error;
alen = XFS_FILBLKS_MIN(len, MAXEXTLEN);
if (!eof)
alen = XFS_FILBLKS_MIN(alen, got->br_startoff - aoff);
extsz = xfs_get_extsz_hint(ip);
if (extsz) {
error = xfs_bmap_extsize_align(mp, got, prev, extsz, rt, eof,
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
xfs_bmap_add_extent_hole_delay(ip, lastx, got);
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, *lastx), got);
ASSERT(got->br_startoff <= aoff);
ASSERT(got->br_startoff + got->br_blockcount >= aoff + alen);
ASSERT(isnullstartblock(got->br_startblock));
ASSERT(got->br_state == XFS_EXT_NORM);
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
int
xfs_bmapi_delay(
struct xfs_inode *ip,
xfs_fileoff_t bno,
xfs_filblks_t len,
struct xfs_bmbt_irec *mval,
int *nmap,
int flags)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_ifork *ifp = XFS_IFORK_PTR(ip, XFS_DATA_FORK);
struct xfs_bmbt_irec got;
struct xfs_bmbt_irec prev;
xfs_fileoff_t obno;
xfs_fileoff_t end;
xfs_extnum_t lastx;
int eof;
int n = 0;
int error = 0;
ASSERT(*nmap >= 1);
ASSERT(*nmap <= XFS_BMAP_MAX_NMAP);
ASSERT(!(flags & ~XFS_BMAPI_ENTIRE));
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
if (unlikely(XFS_TEST_ERROR(
(XFS_IFORK_FORMAT(ip, XFS_DATA_FORK) != XFS_DINODE_FMT_EXTENTS &&
XFS_IFORK_FORMAT(ip, XFS_DATA_FORK) != XFS_DINODE_FMT_BTREE),
mp, XFS_ERRTAG_BMAPIFORMAT, XFS_RANDOM_BMAPIFORMAT))) {
XFS_ERROR_REPORT("xfs_bmapi_delay", XFS_ERRLEVEL_LOW, mp);
return -EFSCORRUPTED;
}
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
XFS_STATS_INC(xs_blk_mapw);
if (!(ifp->if_flags & XFS_IFEXTENTS)) {
error = xfs_iread_extents(NULL, ip, XFS_DATA_FORK);
if (error)
return error;
}
xfs_bmap_search_extents(ip, bno, XFS_DATA_FORK, &eof, &lastx, &got, &prev);
end = bno + len;
obno = bno;
while (bno < end && n < *nmap) {
if (eof || got.br_startoff > bno) {
error = xfs_bmapi_reserve_delalloc(ip, bno, len, &got,
&prev, &lastx, eof);
if (error) {
if (n == 0) {
*nmap = 0;
return error;
}
break;
}
}
xfs_bmapi_trim_map(mval, &got, &bno, len, obno, end, n, flags);
xfs_bmapi_update_map(&mval, &bno, &len, obno, end, &n, flags);
if (bno >= end || n >= *nmap)
break;
prev = got;
if (++lastx < ifp->if_bytes / sizeof(xfs_bmbt_rec_t))
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, lastx), &got);
else
eof = 1;
}
*nmap = n;
return 0;
}
static int
xfs_bmapi_allocate(
struct xfs_bmalloca *bma)
{
struct xfs_mount *mp = bma->ip->i_mount;
int whichfork = (bma->flags & XFS_BMAPI_ATTRFORK) ?
XFS_ATTR_FORK : XFS_DATA_FORK;
struct xfs_ifork *ifp = XFS_IFORK_PTR(bma->ip, whichfork);
int tmp_logflags = 0;
int error;
ASSERT(bma->length > 0);
if (bma->wasdel) {
bma->length = (xfs_extlen_t)bma->got.br_blockcount;
bma->offset = bma->got.br_startoff;
if (bma->idx != NULLEXTNUM && bma->idx) {
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
bma->userdata = (bma->offset == 0) ?
XFS_ALLOC_INITIAL_USER_DATA : XFS_ALLOC_USERDATA;
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
if (bma->flist->xbf_low)
bma->minleft = 0;
if (bma->cur)
bma->cur->bc_private.b.firstblock = *bma->firstblock;
if (bma->blkno == NULLFSBLOCK)
return 0;
if ((ifp->if_flags & XFS_IFBROOT) && !bma->cur) {
bma->cur = xfs_bmbt_init_cursor(mp, bma->tp, bma->ip, whichfork);
bma->cur->bc_private.b.firstblock = *bma->firstblock;
bma->cur->bc_private.b.flist = bma->flist;
}
bma->nallocs++;
if (bma->cur)
bma->cur->bc_private.b.flags =
bma->wasdel ? XFS_BTCUR_BPRV_WASDEL : 0;
bma->got.br_startoff = bma->offset;
bma->got.br_startblock = bma->blkno;
bma->got.br_blockcount = bma->length;
bma->got.br_state = XFS_EXT_NORM;
if (!bma->wasdel && (bma->flags & XFS_BMAPI_PREALLOC) &&
xfs_sb_version_hasextflgbit(&mp->m_sb))
bma->got.br_state = XFS_EXT_UNWRITTEN;
if (bma->wasdel)
error = xfs_bmap_add_extent_delay_real(bma);
else
error = xfs_bmap_add_extent_hole_real(bma, whichfork);
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
int whichfork = (flags & XFS_BMAPI_ATTRFORK) ?
XFS_ATTR_FORK : XFS_DATA_FORK;
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
bma->cur->bc_private.b.flist = bma->flist;
}
mval->br_state = (mval->br_state == XFS_EXT_UNWRITTEN)
? XFS_EXT_NORM : XFS_EXT_UNWRITTEN;
error = xfs_bmap_add_extent_unwritten_real(bma->tp, bma->ip, &bma->idx,
&bma->cur, mval, bma->firstblock, bma->flist,
&tmp_logflags);
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
struct xfs_bmap_free *flist)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_ifork *ifp;
struct xfs_bmalloca bma = { NULL };
xfs_fileoff_t end;
int eof;
int error;
int n;
xfs_fileoff_t obno;
int whichfork;
char inhole;
char wasdelay;
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
whichfork = (flags & XFS_BMAPI_ATTRFORK) ?
XFS_ATTR_FORK : XFS_DATA_FORK;
ASSERT(*nmap >= 1);
ASSERT(*nmap <= XFS_BMAP_MAX_NMAP);
ASSERT(!(flags & XFS_BMAPI_IGSTATE));
ASSERT(tp != NULL);
ASSERT(len > 0);
ASSERT(XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_LOCAL);
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
if (unlikely(XFS_TEST_ERROR(
(XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_EXTENTS &&
XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_BTREE),
mp, XFS_ERRTAG_BMAPIFORMAT, XFS_RANDOM_BMAPIFORMAT))) {
XFS_ERROR_REPORT("xfs_bmapi_write", XFS_ERRLEVEL_LOW, mp);
return -EFSCORRUPTED;
}
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
ifp = XFS_IFORK_PTR(ip, whichfork);
XFS_STATS_INC(xs_blk_mapw);
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
xfs_bmap_search_extents(ip, bno, whichfork, &eof, &bma.idx, &bma.got,
&bma.prev);
n = 0;
end = bno + len;
obno = bno;
bma.tp = tp;
bma.ip = ip;
bma.total = total;
bma.userdata = 0;
bma.flist = flist;
bma.firstblock = firstblock;
while (bno < end && n < *nmap) {
inhole = eof || bma.got.br_startoff > bno;
wasdelay = !inhole && isnullstartblock(bma.got.br_startblock);
if (inhole || wasdelay) {
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
if (++bma.idx < ifp->if_bytes / sizeof(xfs_bmbt_rec_t)) {
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, bma.idx),
&bma.got);
} else
eof = 1;
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
XFS_FSB_TO_AGNO(mp, *firstblock) ==
XFS_FSB_TO_AGNO(mp,
bma.cur->bc_private.b.firstblock) ||
(flist->xbf_low &&
XFS_FSB_TO_AGNO(mp, *firstblock) <
XFS_FSB_TO_AGNO(mp,
bma.cur->bc_private.b.firstblock)));
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
STATIC int
xfs_bmap_del_extent(
xfs_inode_t *ip,
xfs_trans_t *tp,
xfs_extnum_t *idx,
xfs_bmap_free_t *flist,
xfs_btree_cur_t *cur,
xfs_bmbt_irec_t *del,
int *logflagsp,
int whichfork)
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
XFS_STATS_INC(xs_del_exlist);
if (whichfork == XFS_ATTR_FORK)
state |= BMAP_ATTRFORK;
mp = ip->i_mount;
ifp = XFS_IFORK_PTR(ip, whichfork);
ASSERT((*idx >= 0) && (*idx < ifp->if_bytes /
(uint)sizeof(xfs_bmbt_rec_t)));
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
ASSERT(whichfork == XFS_DATA_FORK);
temp = xfs_bmap_worst_indlen(ip, temp);
xfs_bmbt_set_startblock(ep, nullstartblock((int)temp));
temp2 = xfs_bmap_worst_indlen(ip, temp2);
new.br_startblock = nullstartblock((int)temp2);
da_new = temp + temp2;
while (da_new > da_old) {
if (temp) {
temp--;
da_new--;
xfs_bmbt_set_startblock(ep,
nullstartblock((int)temp));
}
if (da_new == da_old)
break;
if (temp2) {
temp2--;
da_new--;
new.br_startblock =
nullstartblock((int)temp2);
}
}
}
trace_xfs_bmap_post_update(ip, *idx, state, _THIS_IP_);
xfs_iext_insert(ip, *idx + 1, 1, &new, state);
++*idx;
break;
}
if (do_fx)
xfs_bmap_add_free(del->br_startblock, del->br_blockcount, flist,
mp);
if (nblks)
ip->i_d.di_nblocks -= nblks;
if (qfield)
xfs_trans_mod_dquot_byino(tp, ip, qfield, (long)-nblks);
ASSERT(da_old >= da_new);
if (da_old > da_new)
xfs_mod_fdblocks(mp, (int64_t)(da_old - da_new), false);
done:
*logflagsp = flags;
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
xfs_bmap_free_t *flist,
int *done)
{
xfs_btree_cur_t *cur;
xfs_bmbt_irec_t del;
int eof;
xfs_bmbt_rec_host_t *ep;
int error;
xfs_extnum_t extno;
xfs_bmbt_irec_t got;
xfs_ifork_t *ifp;
int isrt;
xfs_extnum_t lastx;
int logflags;
xfs_extlen_t mod;
xfs_mount_t *mp;
xfs_extnum_t nextents;
xfs_bmbt_irec_t prev;
xfs_fileoff_t start;
int tmp_logflags;
int wasdel;
int whichfork;
xfs_fsblock_t sum;
trace_xfs_bunmap(ip, bno, len, flags, _RET_IP_);
whichfork = (flags & XFS_BMAPI_ATTRFORK) ?
XFS_ATTR_FORK : XFS_DATA_FORK;
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
if (!(ifp->if_flags & XFS_IFEXTENTS) &&
(error = xfs_iread_extents(tp, ip, whichfork)))
return error;
nextents = ifp->if_bytes / (uint)sizeof(xfs_bmbt_rec_t);
if (nextents == 0) {
*done = 1;
return 0;
}
XFS_STATS_INC(xs_blk_unmap);
isrt = (whichfork == XFS_DATA_FORK) && XFS_IS_REALTIME_INODE(ip);
start = bno;
bno = start + len - 1;
ep = xfs_bmap_search_extents(ip, bno, whichfork, &eof, &lastx, &got,
&prev);
if (eof) {
ep = xfs_iext_get_ext(ifp, --lastx);
xfs_bmbt_get_all(ep, &got);
bno = got.br_startoff + got.br_blockcount - 1;
}
logflags = 0;
if (ifp->if_flags & XFS_IFBROOT) {
ASSERT(XFS_IFORK_FORMAT(ip, whichfork) == XFS_DINODE_FMT_BTREE);
cur = xfs_bmbt_init_cursor(mp, tp, ip, whichfork);
cur->bc_private.b.firstblock = *firstblock;
cur->bc_private.b.flist = flist;
cur->bc_private.b.flags = 0;
} else
cur = NULL;
if (isrt) {
xfs_ilock(mp->m_rbmip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, mp->m_rbmip, XFS_ILOCK_EXCL);
}
extno = 0;
while (bno != (xfs_fileoff_t)-1 && bno >= start && lastx >= 0 &&
(nexts == 0 || extno < nexts)) {
if (got.br_startoff > bno) {
if (--lastx < 0)
break;
ep = xfs_iext_get_ext(ifp, lastx);
xfs_bmbt_get_all(ep, &got);
}
bno = XFS_FILEOFF_MIN(bno,
got.br_startoff + got.br_blockcount - 1);
if (bno < start)
break;
ASSERT(ep != NULL);
del = got;
wasdel = isnullstartblock(del.br_startblock);
if (got.br_startoff < start) {
del.br_startoff = start;
del.br_blockcount -= start - got.br_startoff;
if (!wasdel)
del.br_startblock += start - got.br_startoff;
}
if (del.br_startoff + del.br_blockcount > bno + 1)
del.br_blockcount = bno + 1 - del.br_startoff;
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
ASSERT(xfs_trans_get_block_res(tp) > 0);
if (del.br_blockcount > mod) {
del.br_startoff += del.br_blockcount - mod;
del.br_startblock += del.br_blockcount - mod;
del.br_blockcount = mod;
}
del.br_state = XFS_EXT_UNWRITTEN;
error = xfs_bmap_add_extent_unwritten_real(tp, ip,
&lastx, &cur, &del, firstblock, flist,
&logflags);
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
xfs_trans_get_block_res(tp) == 0)) ||
!xfs_sb_version_hasextflgbit(&mp->m_sb)) {
ASSERT(bno >= del.br_blockcount);
bno -= del.br_blockcount;
if (got.br_startoff > bno) {
if (--lastx >= 0) {
ep = xfs_iext_get_ext(ifp,
lastx);
xfs_bmbt_get_all(ep, &got);
}
}
continue;
} else if (del.br_state == XFS_EXT_UNWRITTEN) {
ASSERT(lastx > 0);
xfs_bmbt_get_all(xfs_iext_get_ext(ifp,
lastx - 1), &prev);
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
ip, &lastx, &cur, &prev,
firstblock, flist, &logflags);
if (error)
goto error0;
goto nodelete;
} else {
ASSERT(del.br_state == XFS_EXT_NORM);
del.br_state = XFS_EXT_UNWRITTEN;
error = xfs_bmap_add_extent_unwritten_real(tp,
ip, &lastx, &cur, &del,
firstblock, flist, &logflags);
if (error)
goto error0;
goto nodelete;
}
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
xfs_mod_fdblocks(mp, (int64_t)del.br_blockcount,
false);
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
if (!wasdel && xfs_trans_get_block_res(tp) == 0 &&
XFS_IFORK_FORMAT(ip, whichfork) == XFS_DINODE_FMT_EXTENTS &&
XFS_IFORK_NEXTENTS(ip, whichfork) >=
XFS_IFORK_MAXEXT(ip, whichfork) &&
del.br_startoff > got.br_startoff &&
del.br_startoff + del.br_blockcount <
got.br_startoff + got.br_blockcount) {
error = -ENOSPC;
goto error0;
}
error = xfs_bmap_del_extent(ip, tp, &lastx, flist, cur, &del,
&tmp_logflags, whichfork);
logflags |= tmp_logflags;
if (error)
goto error0;
bno = del.br_startoff - 1;
nodelete:
if (bno != (xfs_fileoff_t)-1 && bno >= start) {
if (lastx >= 0) {
ep = xfs_iext_get_ext(ifp, lastx);
if (xfs_bmbt_get_startoff(ep) > bno) {
if (--lastx >= 0)
ep = xfs_iext_get_ext(ifp,
lastx);
}
xfs_bmbt_get_all(ep, &got);
}
extno++;
}
}
*done = bno == (xfs_fileoff_t)-1 || bno < start || lastx < 0;
if (xfs_bmap_needs_btree(ip, whichfork)) {
ASSERT(cur == NULL);
error = xfs_bmap_extents_to_btree(tp, ip, firstblock, flist,
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
struct xfs_bmbt_rec_host *gotp,
struct xfs_bmbt_rec_host *leftp,
struct xfs_btree_cur *cur,
int *logflags)
{
struct xfs_bmbt_irec got;
struct xfs_bmbt_irec left;
xfs_filblks_t blockcount;
int error, i;
struct xfs_mount *mp = ip->i_mount;
xfs_bmbt_get_all(gotp, &got);
xfs_bmbt_get_all(leftp, &left);
blockcount = left.br_blockcount + got.br_blockcount;
ASSERT(xfs_isilocked(ip, XFS_IOLOCK_EXCL));
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
ASSERT(xfs_bmse_can_merge(&left, &got, shift));
xfs_bmbt_set_blockcount(leftp, blockcount);
xfs_iext_remove(ip, current_ext, 1, 0);
XFS_IFORK_NEXT_SET(ip, whichfork,
XFS_IFORK_NEXTENTS(ip, whichfork) - 1);
*logflags |= XFS_ILOG_CORE;
if (!cur) {
*logflags |= XFS_ILOG_DEXT;
return 0;
}
error = xfs_bmbt_lookup_eq(cur, got.br_startoff, got.br_startblock,
got.br_blockcount, &i);
if (error)
return error;
XFS_WANT_CORRUPTED_RETURN(mp, i == 1);
error = xfs_btree_delete(cur, &i);
if (error)
return error;
XFS_WANT_CORRUPTED_RETURN(mp, i == 1);
error = xfs_bmbt_lookup_eq(cur, left.br_startoff, left.br_startblock,
left.br_blockcount, &i);
if (error)
return error;
XFS_WANT_CORRUPTED_RETURN(mp, i == 1);
left.br_blockcount = blockcount;
return xfs_bmbt_update(cur, left.br_startoff, left.br_startblock,
left.br_blockcount, left.br_state);
}
STATIC int
xfs_bmse_shift_one(
struct xfs_inode *ip,
int whichfork,
xfs_fileoff_t offset_shift_fsb,
int *current_ext,
struct xfs_bmbt_rec_host *gotp,
struct xfs_btree_cur *cur,
int *logflags,
enum shift_direction direction)
{
struct xfs_ifork *ifp;
struct xfs_mount *mp;
xfs_fileoff_t startoff;
struct xfs_bmbt_rec_host *adj_irecp;
struct xfs_bmbt_irec got;
struct xfs_bmbt_irec adj_irec;
int error;
int i;
int total_extents;
mp = ip->i_mount;
ifp = XFS_IFORK_PTR(ip, whichfork);
total_extents = ifp->if_bytes / sizeof(xfs_bmbt_rec_t);
xfs_bmbt_get_all(gotp, &got);
XFS_WANT_CORRUPTED_RETURN(mp, !isnullstartblock(got.br_startblock));
if (direction == SHIFT_LEFT) {
startoff = got.br_startoff - offset_shift_fsb;
if (!*current_ext) {
if (got.br_startoff < offset_shift_fsb)
return -EINVAL;
goto update_current_ext;
}
adj_irecp = xfs_iext_get_ext(ifp, *current_ext - 1);
xfs_bmbt_get_all(adj_irecp, &adj_irec);
if (startoff <
adj_irec.br_startoff + adj_irec.br_blockcount)
return -EINVAL;
if (xfs_bmse_can_merge(&adj_irec, &got,
offset_shift_fsb)) {
return xfs_bmse_merge(ip, whichfork, offset_shift_fsb,
*current_ext, gotp, adj_irecp,
cur, logflags);
}
} else {
startoff = got.br_startoff + offset_shift_fsb;
if (*current_ext >= (total_extents - 1))
goto update_current_ext;
adj_irecp = xfs_iext_get_ext(ifp, *current_ext + 1);
xfs_bmbt_get_all(adj_irecp, &adj_irec);
if (startoff + got.br_blockcount > adj_irec.br_startoff)
return -EINVAL;
if (xfs_bmse_can_merge(&got, &adj_irec, offset_shift_fsb))
WARN_ON_ONCE(1);
}
update_current_ext:
if (direction == SHIFT_LEFT)
(*current_ext)++;
else
(*current_ext)--;
xfs_bmbt_set_startoff(gotp, startoff);
*logflags |= XFS_ILOG_CORE;
if (!cur) {
*logflags |= XFS_ILOG_DEXT;
return 0;
}
error = xfs_bmbt_lookup_eq(cur, got.br_startoff, got.br_startblock,
got.br_blockcount, &i);
if (error)
return error;
XFS_WANT_CORRUPTED_RETURN(mp, i == 1);
got.br_startoff = startoff;
return xfs_bmbt_update(cur, got.br_startoff, got.br_startblock,
got.br_blockcount, got.br_state);
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
struct xfs_bmap_free *flist,
enum shift_direction direction,
int num_exts)
{
struct xfs_btree_cur *cur = NULL;
struct xfs_bmbt_rec_host *gotp;
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
mp, XFS_ERRTAG_BMAPIFORMAT, XFS_RANDOM_BMAPIFORMAT))) {
XFS_ERROR_REPORT("xfs_bmap_shift_extents",
XFS_ERRLEVEL_LOW, mp);
return -EFSCORRUPTED;
}
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
ASSERT(xfs_isilocked(ip, XFS_IOLOCK_EXCL));
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
ASSERT(direction == SHIFT_LEFT || direction == SHIFT_RIGHT);
ASSERT(*next_fsb != NULLFSBLOCK || direction == SHIFT_RIGHT);
ifp = XFS_IFORK_PTR(ip, whichfork);
if (!(ifp->if_flags & XFS_IFEXTENTS)) {
error = xfs_iread_extents(tp, ip, whichfork);
if (error)
return error;
}
if (ifp->if_flags & XFS_IFBROOT) {
cur = xfs_bmbt_init_cursor(mp, tp, ip, whichfork);
cur->bc_private.b.firstblock = *firstblock;
cur->bc_private.b.flist = flist;
cur->bc_private.b.flags = 0;
}
total_extents = ifp->if_bytes / sizeof(xfs_bmbt_rec_t);
if (total_extents == 0) {
*done = 1;
goto del_cursor;
}
if (*next_fsb == NULLFSBLOCK) {
gotp = xfs_iext_get_ext(ifp, total_extents - 1);
xfs_bmbt_get_all(gotp, &got);
*next_fsb = got.br_startoff;
if (stop_fsb > *next_fsb) {
*done = 1;
goto del_cursor;
}
}
if (direction == SHIFT_RIGHT) {
gotp = xfs_iext_bno_to_ext(ifp, stop_fsb, &stop_extent);
stop_extent--;
} else
stop_extent = total_extents;
gotp = xfs_iext_bno_to_ext(ifp, *next_fsb, &current_ext);
if (!gotp) {
*done = 1;
goto del_cursor;
}
if ((direction == SHIFT_LEFT && current_ext >= stop_extent) ||
(direction == SHIFT_RIGHT && current_ext <= stop_extent)) {
error = -EIO;
goto del_cursor;
}
while (nexts++ < num_exts) {
error = xfs_bmse_shift_one(ip, whichfork, offset_shift_fsb,
&current_ext, gotp, cur, &logflags,
direction);
if (error)
goto del_cursor;
if (direction == SHIFT_LEFT) {
total_extents = ifp->if_bytes / sizeof(xfs_bmbt_rec_t);
stop_extent = total_extents;
}
if (current_ext == stop_extent) {
*done = 1;
*next_fsb = NULLFSBLOCK;
break;
}
gotp = xfs_iext_get_ext(ifp, current_ext);
}
if (!*done) {
xfs_bmbt_get_all(gotp, &got);
*next_fsb = got.br_startoff;
}
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
struct xfs_bmap_free *free_list)
{
int whichfork = XFS_DATA_FORK;
struct xfs_btree_cur *cur = NULL;
struct xfs_bmbt_rec_host *gotp;
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
mp, XFS_ERRTAG_BMAPIFORMAT, XFS_RANDOM_BMAPIFORMAT))) {
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
gotp = xfs_iext_bno_to_ext(ifp, split_fsb, &current_ext);
if (!gotp)
return 0;
xfs_bmbt_get_all(gotp, &got);
if (got.br_startoff >= split_fsb)
return 0;
gotblkcnt = split_fsb - got.br_startoff;
new.br_startoff = split_fsb;
new.br_startblock = got.br_startblock + gotblkcnt;
new.br_blockcount = got.br_blockcount - gotblkcnt;
new.br_state = got.br_state;
if (ifp->if_flags & XFS_IFBROOT) {
cur = xfs_bmbt_init_cursor(mp, tp, ip, whichfork);
cur->bc_private.b.firstblock = *firstfsb;
cur->bc_private.b.flist = free_list;
cur->bc_private.b.flags = 0;
error = xfs_bmbt_lookup_eq(cur, got.br_startoff,
got.br_startblock,
got.br_blockcount,
&i);
if (error)
goto del_cursor;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, del_cursor);
}
xfs_bmbt_set_blockcount(gotp, gotblkcnt);
got.br_blockcount = gotblkcnt;
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
error = xfs_bmap_extents_to_btree(tp, ip, firstfsb, free_list,
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
struct xfs_bmap_free free_list;
xfs_fsblock_t firstfsb;
int committed;
int error;
tp = xfs_trans_alloc(mp, XFS_TRANS_DIOSTRAT);
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_write,
XFS_DIOSTRAT_SPACE_RES(mp, 0), 0);
if (error) {
xfs_trans_cancel(tp);
return error;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, XFS_ILOCK_EXCL);
xfs_bmap_init(&free_list, &firstfsb);
error = xfs_bmap_split_extent_at(tp, ip, split_fsb,
&firstfsb, &free_list);
if (error)
goto out;
error = xfs_bmap_finish(&tp, &free_list, &committed);
if (error)
goto out;
return xfs_trans_commit(tp);
out:
xfs_trans_cancel(tp);
return error;
}
