static inline int
xfs_ialloc_cluster_alignment(
struct xfs_mount *mp)
{
if (xfs_sb_version_hasalign(&mp->m_sb) &&
mp->m_sb.sb_inoalignmt >=
XFS_B_TO_FSBT(mp, mp->m_inode_cluster_size))
return mp->m_sb.sb_inoalignmt;
return 1;
}
int
xfs_inobt_lookup(
struct xfs_btree_cur *cur,
xfs_agino_t ino,
xfs_lookup_t dir,
int *stat)
{
cur->bc_rec.i.ir_startino = ino;
cur->bc_rec.i.ir_holemask = 0;
cur->bc_rec.i.ir_count = 0;
cur->bc_rec.i.ir_freecount = 0;
cur->bc_rec.i.ir_free = 0;
return xfs_btree_lookup(cur, dir, stat);
}
STATIC int
xfs_inobt_update(
struct xfs_btree_cur *cur,
xfs_inobt_rec_incore_t *irec)
{
union xfs_btree_rec rec;
rec.inobt.ir_startino = cpu_to_be32(irec->ir_startino);
if (xfs_sb_version_hassparseinodes(&cur->bc_mp->m_sb)) {
rec.inobt.ir_u.sp.ir_holemask = cpu_to_be16(irec->ir_holemask);
rec.inobt.ir_u.sp.ir_count = irec->ir_count;
rec.inobt.ir_u.sp.ir_freecount = irec->ir_freecount;
} else {
rec.inobt.ir_u.f.ir_freecount = cpu_to_be32(irec->ir_freecount);
}
rec.inobt.ir_free = cpu_to_be64(irec->ir_free);
return xfs_btree_update(cur, &rec);
}
int
xfs_inobt_get_rec(
struct xfs_btree_cur *cur,
xfs_inobt_rec_incore_t *irec,
int *stat)
{
union xfs_btree_rec *rec;
int error;
error = xfs_btree_get_rec(cur, &rec, stat);
if (error || *stat == 0)
return error;
irec->ir_startino = be32_to_cpu(rec->inobt.ir_startino);
if (xfs_sb_version_hassparseinodes(&cur->bc_mp->m_sb)) {
irec->ir_holemask = be16_to_cpu(rec->inobt.ir_u.sp.ir_holemask);
irec->ir_count = rec->inobt.ir_u.sp.ir_count;
irec->ir_freecount = rec->inobt.ir_u.sp.ir_freecount;
} else {
irec->ir_holemask = XFS_INOBT_HOLEMASK_FULL;
irec->ir_count = XFS_INODES_PER_CHUNK;
irec->ir_freecount =
be32_to_cpu(rec->inobt.ir_u.f.ir_freecount);
}
irec->ir_free = be64_to_cpu(rec->inobt.ir_free);
return 0;
}
STATIC int
xfs_inobt_insert_rec(
struct xfs_btree_cur *cur,
__uint16_t holemask,
__uint8_t count,
__int32_t freecount,
xfs_inofree_t free,
int *stat)
{
cur->bc_rec.i.ir_holemask = holemask;
cur->bc_rec.i.ir_count = count;
cur->bc_rec.i.ir_freecount = freecount;
cur->bc_rec.i.ir_free = free;
return xfs_btree_insert(cur, stat);
}
STATIC int
xfs_inobt_insert(
struct xfs_mount *mp,
struct xfs_trans *tp,
struct xfs_buf *agbp,
xfs_agino_t newino,
xfs_agino_t newlen,
xfs_btnum_t btnum)
{
struct xfs_btree_cur *cur;
struct xfs_agi *agi = XFS_BUF_TO_AGI(agbp);
xfs_agnumber_t agno = be32_to_cpu(agi->agi_seqno);
xfs_agino_t thisino;
int i;
int error;
cur = xfs_inobt_init_cursor(mp, tp, agbp, agno, btnum);
for (thisino = newino;
thisino < newino + newlen;
thisino += XFS_INODES_PER_CHUNK) {
error = xfs_inobt_lookup(cur, thisino, XFS_LOOKUP_EQ, &i);
if (error) {
xfs_btree_del_cursor(cur, XFS_BTREE_ERROR);
return error;
}
ASSERT(i == 0);
error = xfs_inobt_insert_rec(cur, XFS_INOBT_HOLEMASK_FULL,
XFS_INODES_PER_CHUNK,
XFS_INODES_PER_CHUNK,
XFS_INOBT_ALL_FREE, &i);
if (error) {
xfs_btree_del_cursor(cur, XFS_BTREE_ERROR);
return error;
}
ASSERT(i == 1);
}
xfs_btree_del_cursor(cur, XFS_BTREE_NOERROR);
return 0;
}
STATIC int
xfs_check_agi_freecount(
struct xfs_btree_cur *cur,
struct xfs_agi *agi)
{
if (cur->bc_nlevels == 1) {
xfs_inobt_rec_incore_t rec;
int freecount = 0;
int error;
int i;
error = xfs_inobt_lookup(cur, 0, XFS_LOOKUP_GE, &i);
if (error)
return error;
do {
error = xfs_inobt_get_rec(cur, &rec, &i);
if (error)
return error;
if (i) {
freecount += rec.ir_freecount;
error = xfs_btree_increment(cur, 0, &i);
if (error)
return error;
}
} while (i == 1);
if (!XFS_FORCED_SHUTDOWN(cur->bc_mp))
ASSERT(freecount == be32_to_cpu(agi->agi_freecount));
}
return 0;
}
int
xfs_ialloc_inode_init(
struct xfs_mount *mp,
struct xfs_trans *tp,
struct list_head *buffer_list,
int icount,
xfs_agnumber_t agno,
xfs_agblock_t agbno,
xfs_agblock_t length,
unsigned int gen)
{
struct xfs_buf *fbuf;
struct xfs_dinode *free;
int nbufs, blks_per_cluster, inodes_per_cluster;
int version;
int i, j;
xfs_daddr_t d;
xfs_ino_t ino = 0;
blks_per_cluster = xfs_icluster_size_fsb(mp);
inodes_per_cluster = blks_per_cluster << mp->m_sb.sb_inopblog;
nbufs = length / blks_per_cluster;
if (xfs_sb_version_hascrc(&mp->m_sb)) {
version = 3;
ino = XFS_AGINO_TO_INO(mp, agno,
XFS_OFFBNO_TO_AGINO(mp, agbno, 0));
if (tp)
xfs_icreate_log(tp, agno, agbno, icount,
mp->m_sb.sb_inodesize, length, gen);
} else
version = 2;
for (j = 0; j < nbufs; j++) {
d = XFS_AGB_TO_DADDR(mp, agno, agbno + (j * blks_per_cluster));
fbuf = xfs_trans_get_buf(tp, mp->m_ddev_targp, d,
mp->m_bsize * blks_per_cluster,
XBF_UNMAPPED);
if (!fbuf)
return -ENOMEM;
fbuf->b_ops = &xfs_inode_buf_ops;
xfs_buf_zero(fbuf, 0, BBTOB(fbuf->b_length));
for (i = 0; i < inodes_per_cluster; i++) {
int ioffset = i << mp->m_sb.sb_inodelog;
uint isize = xfs_dinode_size(version);
free = xfs_make_iptr(mp, fbuf, i);
free->di_magic = cpu_to_be16(XFS_DINODE_MAGIC);
free->di_version = version;
free->di_gen = cpu_to_be32(gen);
free->di_next_unlinked = cpu_to_be32(NULLAGINO);
if (version == 3) {
free->di_ino = cpu_to_be64(ino);
ino++;
uuid_copy(&free->di_uuid,
&mp->m_sb.sb_meta_uuid);
xfs_dinode_calc_crc(mp, free);
} else if (tp) {
xfs_trans_log_buf(tp, fbuf, ioffset,
ioffset + isize - 1);
}
}
if (tp) {
xfs_trans_inode_alloc_buf(tp, fbuf);
if (version == 3) {
xfs_trans_ordered_buf(tp, fbuf);
xfs_trans_log_buf(tp, fbuf, 0,
BBTOB(fbuf->b_length) - 1);
}
} else {
fbuf->b_flags |= XBF_DONE;
xfs_buf_delwri_queue(fbuf, buffer_list);
xfs_buf_relse(fbuf);
}
}
return 0;
}
STATIC void
xfs_align_sparse_ino(
struct xfs_mount *mp,
xfs_agino_t *startino,
uint16_t *allocmask)
{
xfs_agblock_t agbno;
xfs_agblock_t mod;
int offset;
agbno = XFS_AGINO_TO_AGBNO(mp, *startino);
mod = agbno % mp->m_sb.sb_inoalignmt;
if (!mod)
return;
offset = mod << mp->m_sb.sb_inopblog;
*startino -= offset;
*allocmask <<= offset / XFS_INODES_PER_HOLEMASK_BIT;
}
STATIC bool
__xfs_inobt_can_merge(
struct xfs_inobt_rec_incore *trec,
struct xfs_inobt_rec_incore *srec)
{
uint64_t talloc;
uint64_t salloc;
if (trec->ir_startino != srec->ir_startino)
return false;
if (!xfs_inobt_issparse(trec->ir_holemask) ||
!xfs_inobt_issparse(srec->ir_holemask))
return false;
if (!trec->ir_count || !srec->ir_count)
return false;
if (trec->ir_count + srec->ir_count > XFS_INODES_PER_CHUNK)
return false;
talloc = xfs_inobt_irec_to_allocmask(trec);
salloc = xfs_inobt_irec_to_allocmask(srec);
if (talloc & salloc)
return false;
return true;
}
STATIC void
__xfs_inobt_rec_merge(
struct xfs_inobt_rec_incore *trec,
struct xfs_inobt_rec_incore *srec)
{
ASSERT(trec->ir_startino == srec->ir_startino);
trec->ir_count += srec->ir_count;
trec->ir_freecount += srec->ir_freecount;
trec->ir_holemask &= srec->ir_holemask;
trec->ir_free &= srec->ir_free;
}
STATIC int
xfs_inobt_insert_sprec(
struct xfs_mount *mp,
struct xfs_trans *tp,
struct xfs_buf *agbp,
int btnum,
struct xfs_inobt_rec_incore *nrec,
bool merge)
{
struct xfs_btree_cur *cur;
struct xfs_agi *agi = XFS_BUF_TO_AGI(agbp);
xfs_agnumber_t agno = be32_to_cpu(agi->agi_seqno);
int error;
int i;
struct xfs_inobt_rec_incore rec;
cur = xfs_inobt_init_cursor(mp, tp, agbp, agno, btnum);
error = xfs_inobt_lookup(cur, nrec->ir_startino, XFS_LOOKUP_EQ, &i);
if (error)
goto error;
if (i == 0) {
error = xfs_inobt_insert_rec(cur, nrec->ir_holemask,
nrec->ir_count, nrec->ir_freecount,
nrec->ir_free, &i);
if (error)
goto error;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, error);
goto out;
}
if (merge) {
error = xfs_inobt_get_rec(cur, &rec, &i);
if (error)
goto error;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, error);
XFS_WANT_CORRUPTED_GOTO(mp,
rec.ir_startino == nrec->ir_startino,
error);
XFS_WANT_CORRUPTED_GOTO(mp, __xfs_inobt_can_merge(nrec, &rec),
error);
trace_xfs_irec_merge_pre(mp, agno, rec.ir_startino,
rec.ir_holemask, nrec->ir_startino,
nrec->ir_holemask);
__xfs_inobt_rec_merge(nrec, &rec);
trace_xfs_irec_merge_post(mp, agno, nrec->ir_startino,
nrec->ir_holemask);
error = xfs_inobt_rec_check_count(mp, nrec);
if (error)
goto error;
}
error = xfs_inobt_update(cur, nrec);
if (error)
goto error;
out:
xfs_btree_del_cursor(cur, XFS_BTREE_NOERROR);
return 0;
error:
xfs_btree_del_cursor(cur, XFS_BTREE_ERROR);
return error;
}
STATIC int
xfs_ialloc_ag_alloc(
xfs_trans_t *tp,
xfs_buf_t *agbp,
int *alloc)
{
xfs_agi_t *agi;
xfs_alloc_arg_t args;
xfs_agnumber_t agno;
int error;
xfs_agino_t newino;
xfs_agino_t newlen;
int isaligned = 0;
uint16_t allocmask = (uint16_t) -1;
struct xfs_inobt_rec_incore rec;
struct xfs_perag *pag;
int do_sparse = 0;
memset(&args, 0, sizeof(args));
args.tp = tp;
args.mp = tp->t_mountp;
args.fsbno = NULLFSBLOCK;
#ifdef DEBUG
if (xfs_sb_version_hassparseinodes(&tp->t_mountp->m_sb) &&
args.mp->m_ialloc_min_blks < args.mp->m_ialloc_blks)
do_sparse = prandom_u32() & 1;
#endif
newlen = args.mp->m_ialloc_inos;
if (args.mp->m_maxicount &&
percpu_counter_read_positive(&args.mp->m_icount) + newlen >
args.mp->m_maxicount)
return -ENOSPC;
args.minlen = args.maxlen = args.mp->m_ialloc_blks;
agi = XFS_BUF_TO_AGI(agbp);
newino = be32_to_cpu(agi->agi_newino);
agno = be32_to_cpu(agi->agi_seqno);
args.agbno = XFS_AGINO_TO_AGBNO(args.mp, newino) +
args.mp->m_ialloc_blks;
if (do_sparse)
goto sparse_alloc;
if (likely(newino != NULLAGINO &&
(args.agbno < be32_to_cpu(agi->agi_length)))) {
args.fsbno = XFS_AGB_TO_FSB(args.mp, agno, args.agbno);
args.type = XFS_ALLOCTYPE_THIS_BNO;
args.prod = 1;
args.alignment = 1;
args.minalignslop = xfs_ialloc_cluster_alignment(args.mp) - 1;
args.minleft = args.mp->m_in_maxlevels - 1;
if ((error = xfs_alloc_vextent(&args)))
return error;
args.minalignslop = 0;
}
if (unlikely(args.fsbno == NULLFSBLOCK)) {
isaligned = 0;
if (args.mp->m_sinoalign) {
ASSERT(!(args.mp->m_flags & XFS_MOUNT_NOALIGN));
args.alignment = args.mp->m_dalign;
isaligned = 1;
} else
args.alignment = xfs_ialloc_cluster_alignment(args.mp);
args.agbno = be32_to_cpu(agi->agi_root);
args.fsbno = XFS_AGB_TO_FSB(args.mp, agno, args.agbno);
args.type = XFS_ALLOCTYPE_NEAR_BNO;
args.prod = 1;
args.minleft = args.mp->m_in_maxlevels - 1;
if ((error = xfs_alloc_vextent(&args)))
return error;
}
if (isaligned && args.fsbno == NULLFSBLOCK) {
args.type = XFS_ALLOCTYPE_NEAR_BNO;
args.agbno = be32_to_cpu(agi->agi_root);
args.fsbno = XFS_AGB_TO_FSB(args.mp, agno, args.agbno);
args.alignment = xfs_ialloc_cluster_alignment(args.mp);
if ((error = xfs_alloc_vextent(&args)))
return error;
}
if (xfs_sb_version_hassparseinodes(&args.mp->m_sb) &&
args.mp->m_ialloc_min_blks < args.mp->m_ialloc_blks &&
args.fsbno == NULLFSBLOCK) {
sparse_alloc:
args.type = XFS_ALLOCTYPE_NEAR_BNO;
args.agbno = be32_to_cpu(agi->agi_root);
args.fsbno = XFS_AGB_TO_FSB(args.mp, agno, args.agbno);
args.alignment = args.mp->m_sb.sb_spino_align;
args.prod = 1;
args.minlen = args.mp->m_ialloc_min_blks;
args.maxlen = args.minlen;
args.min_agbno = args.mp->m_sb.sb_inoalignmt;
args.max_agbno = round_down(args.mp->m_sb.sb_agblocks,
args.mp->m_sb.sb_inoalignmt) -
args.mp->m_ialloc_blks;
error = xfs_alloc_vextent(&args);
if (error)
return error;
newlen = args.len << args.mp->m_sb.sb_inopblog;
ASSERT(newlen <= XFS_INODES_PER_CHUNK);
allocmask = (1 << (newlen / XFS_INODES_PER_HOLEMASK_BIT)) - 1;
}
if (args.fsbno == NULLFSBLOCK) {
*alloc = 0;
return 0;
}
ASSERT(args.len == args.minlen);
error = xfs_ialloc_inode_init(args.mp, tp, NULL, newlen, agno,
args.agbno, args.len, prandom_u32());
if (error)
return error;
newino = XFS_OFFBNO_TO_AGINO(args.mp, args.agbno, 0);
if (xfs_inobt_issparse(~allocmask)) {
xfs_align_sparse_ino(args.mp, &newino, &allocmask);
rec.ir_startino = newino;
rec.ir_holemask = ~allocmask;
rec.ir_count = newlen;
rec.ir_freecount = newlen;
rec.ir_free = XFS_INOBT_ALL_FREE;
error = xfs_inobt_insert_sprec(args.mp, tp, agbp, XFS_BTNUM_INO,
&rec, true);
if (error == -EFSCORRUPTED) {
xfs_alert(args.mp,
"invalid sparse inode record: ino 0x%llx holemask 0x%x count %u",
XFS_AGINO_TO_INO(args.mp, agno,
rec.ir_startino),
rec.ir_holemask, rec.ir_count);
xfs_force_shutdown(args.mp, SHUTDOWN_CORRUPT_INCORE);
}
if (error)
return error;
if (xfs_sb_version_hasfinobt(&args.mp->m_sb)) {
error = xfs_inobt_insert_sprec(args.mp, tp, agbp,
XFS_BTNUM_FINO, &rec,
false);
if (error)
return error;
}
} else {
error = xfs_inobt_insert(args.mp, tp, agbp, newino, newlen,
XFS_BTNUM_INO);
if (error)
return error;
if (xfs_sb_version_hasfinobt(&args.mp->m_sb)) {
error = xfs_inobt_insert(args.mp, tp, agbp, newino,
newlen, XFS_BTNUM_FINO);
if (error)
return error;
}
}
be32_add_cpu(&agi->agi_count, newlen);
be32_add_cpu(&agi->agi_freecount, newlen);
pag = xfs_perag_get(args.mp, agno);
pag->pagi_freecount += newlen;
xfs_perag_put(pag);
agi->agi_newino = cpu_to_be32(newino);
xfs_ialloc_log_agi(tp, agbp,
XFS_AGI_COUNT | XFS_AGI_FREECOUNT | XFS_AGI_NEWINO);
xfs_trans_mod_sb(tp, XFS_TRANS_SB_ICOUNT, (long)newlen);
xfs_trans_mod_sb(tp, XFS_TRANS_SB_IFREE, (long)newlen);
*alloc = 1;
return 0;
}
STATIC xfs_agnumber_t
xfs_ialloc_next_ag(
xfs_mount_t *mp)
{
xfs_agnumber_t agno;
spin_lock(&mp->m_agirotor_lock);
agno = mp->m_agirotor;
if (++mp->m_agirotor >= mp->m_maxagi)
mp->m_agirotor = 0;
spin_unlock(&mp->m_agirotor_lock);
return agno;
}
STATIC xfs_agnumber_t
xfs_ialloc_ag_select(
xfs_trans_t *tp,
xfs_ino_t parent,
umode_t mode,
int okalloc)
{
xfs_agnumber_t agcount;
xfs_agnumber_t agno;
int flags;
xfs_extlen_t ineed;
xfs_extlen_t longest = 0;
xfs_mount_t *mp;
int needspace;
xfs_perag_t *pag;
xfs_agnumber_t pagno;
int error;
needspace = S_ISDIR(mode) || S_ISREG(mode) || S_ISLNK(mode);
mp = tp->t_mountp;
agcount = mp->m_maxagi;
if (S_ISDIR(mode))
pagno = xfs_ialloc_next_ag(mp);
else {
pagno = XFS_INO_TO_AGNO(mp, parent);
if (pagno >= agcount)
pagno = 0;
}
ASSERT(pagno < agcount);
agno = pagno;
flags = XFS_ALLOC_FLAG_TRYLOCK;
for (;;) {
pag = xfs_perag_get(mp, agno);
if (!pag->pagi_inodeok) {
xfs_ialloc_next_ag(mp);
goto nextag;
}
if (!pag->pagi_init) {
error = xfs_ialloc_pagi_init(mp, tp, agno);
if (error)
goto nextag;
}
if (pag->pagi_freecount) {
xfs_perag_put(pag);
return agno;
}
if (!okalloc)
goto nextag;
if (!pag->pagf_init) {
error = xfs_alloc_pagf_init(mp, tp, agno, flags);
if (error)
goto nextag;
}
ineed = mp->m_ialloc_min_blks;
if (flags && ineed > 1)
ineed += xfs_ialloc_cluster_alignment(mp);
longest = pag->pagf_longest;
if (!longest)
longest = pag->pagf_flcount > 0;
if (pag->pagf_freeblks >= needspace + ineed &&
longest >= ineed) {
xfs_perag_put(pag);
return agno;
}
nextag:
xfs_perag_put(pag);
if (XFS_FORCED_SHUTDOWN(mp))
return NULLAGNUMBER;
agno++;
if (agno >= agcount)
agno = 0;
if (agno == pagno) {
if (flags == 0)
return NULLAGNUMBER;
flags = 0;
}
}
}
STATIC int
xfs_ialloc_next_rec(
struct xfs_btree_cur *cur,
xfs_inobt_rec_incore_t *rec,
int *done,
int left)
{
int error;
int i;
if (left)
error = xfs_btree_decrement(cur, 0, &i);
else
error = xfs_btree_increment(cur, 0, &i);
if (error)
return error;
*done = !i;
if (i) {
error = xfs_inobt_get_rec(cur, rec, &i);
if (error)
return error;
XFS_WANT_CORRUPTED_RETURN(cur->bc_mp, i == 1);
}
return 0;
}
STATIC int
xfs_ialloc_get_rec(
struct xfs_btree_cur *cur,
xfs_agino_t agino,
xfs_inobt_rec_incore_t *rec,
int *done)
{
int error;
int i;
error = xfs_inobt_lookup(cur, agino, XFS_LOOKUP_EQ, &i);
if (error)
return error;
*done = !i;
if (i) {
error = xfs_inobt_get_rec(cur, rec, &i);
if (error)
return error;
XFS_WANT_CORRUPTED_RETURN(cur->bc_mp, i == 1);
}
return 0;
}
STATIC int
xfs_inobt_first_free_inode(
struct xfs_inobt_rec_incore *rec)
{
xfs_inofree_t realfree;
if (!xfs_inobt_issparse(rec->ir_holemask))
return xfs_lowbit64(rec->ir_free);
realfree = xfs_inobt_irec_to_allocmask(rec);
realfree &= rec->ir_free;
return xfs_lowbit64(realfree);
}
STATIC int
xfs_dialloc_ag_inobt(
struct xfs_trans *tp,
struct xfs_buf *agbp,
xfs_ino_t parent,
xfs_ino_t *inop)
{
struct xfs_mount *mp = tp->t_mountp;
struct xfs_agi *agi = XFS_BUF_TO_AGI(agbp);
xfs_agnumber_t agno = be32_to_cpu(agi->agi_seqno);
xfs_agnumber_t pagno = XFS_INO_TO_AGNO(mp, parent);
xfs_agino_t pagino = XFS_INO_TO_AGINO(mp, parent);
struct xfs_perag *pag;
struct xfs_btree_cur *cur, *tcur;
struct xfs_inobt_rec_incore rec, trec;
xfs_ino_t ino;
int error;
int offset;
int i, j;
pag = xfs_perag_get(mp, agno);
ASSERT(pag->pagi_init);
ASSERT(pag->pagi_inodeok);
ASSERT(pag->pagi_freecount > 0);
restart_pagno:
cur = xfs_inobt_init_cursor(mp, tp, agbp, agno, XFS_BTNUM_INO);
if (!pagino)
pagino = be32_to_cpu(agi->agi_newino);
error = xfs_check_agi_freecount(cur, agi);
if (error)
goto error0;
if (pagno == agno) {
int doneleft;
int doneright;
int searchdistance = 10;
error = xfs_inobt_lookup(cur, pagino, XFS_LOOKUP_LE, &i);
if (error)
goto error0;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, error0);
error = xfs_inobt_get_rec(cur, &rec, &j);
if (error)
goto error0;
XFS_WANT_CORRUPTED_GOTO(mp, j == 1, error0);
if (rec.ir_freecount > 0) {
goto alloc_inode;
}
error = xfs_btree_dup_cursor(cur, &tcur);
if (error)
goto error0;
if (pagino != NULLAGINO &&
pag->pagl_pagino == pagino &&
pag->pagl_leftrec != NULLAGINO &&
pag->pagl_rightrec != NULLAGINO) {
error = xfs_ialloc_get_rec(tcur, pag->pagl_leftrec,
&trec, &doneleft);
if (error)
goto error1;
error = xfs_ialloc_get_rec(cur, pag->pagl_rightrec,
&rec, &doneright);
if (error)
goto error1;
} else {
error = xfs_ialloc_next_rec(tcur, &trec, &doneleft, 1);
if (error)
goto error1;
error = xfs_ialloc_next_rec(cur, &rec, &doneright, 0);
if (error)
goto error1;
}
while (!doneleft || !doneright) {
int useleft;
if (!--searchdistance) {
xfs_btree_del_cursor(tcur, XFS_BTREE_NOERROR);
pag->pagl_leftrec = trec.ir_startino;
pag->pagl_rightrec = rec.ir_startino;
pag->pagl_pagino = pagino;
goto newino;
}
if (!doneleft && !doneright) {
useleft = pagino -
(trec.ir_startino + XFS_INODES_PER_CHUNK - 1) <
rec.ir_startino - pagino;
} else {
useleft = !doneleft;
}
if (useleft && trec.ir_freecount) {
rec = trec;
xfs_btree_del_cursor(cur, XFS_BTREE_NOERROR);
cur = tcur;
pag->pagl_leftrec = trec.ir_startino;
pag->pagl_rightrec = rec.ir_startino;
pag->pagl_pagino = pagino;
goto alloc_inode;
}
if (!useleft && rec.ir_freecount) {
xfs_btree_del_cursor(tcur, XFS_BTREE_NOERROR);
pag->pagl_leftrec = trec.ir_startino;
pag->pagl_rightrec = rec.ir_startino;
pag->pagl_pagino = pagino;
goto alloc_inode;
}
if (useleft) {
error = xfs_ialloc_next_rec(tcur, &trec,
&doneleft, 1);
} else {
error = xfs_ialloc_next_rec(cur, &rec,
&doneright, 0);
}
if (error)
goto error1;
}
pag->pagl_pagino = NULLAGINO;
pag->pagl_leftrec = NULLAGINO;
pag->pagl_rightrec = NULLAGINO;
xfs_btree_del_cursor(tcur, XFS_BTREE_NOERROR);
xfs_btree_del_cursor(cur, XFS_BTREE_NOERROR);
goto restart_pagno;
}
newino:
if (agi->agi_newino != cpu_to_be32(NULLAGINO)) {
error = xfs_inobt_lookup(cur, be32_to_cpu(agi->agi_newino),
XFS_LOOKUP_EQ, &i);
if (error)
goto error0;
if (i == 1) {
error = xfs_inobt_get_rec(cur, &rec, &j);
if (error)
goto error0;
if (j == 1 && rec.ir_freecount > 0) {
goto alloc_inode;
}
}
}
error = xfs_inobt_lookup(cur, 0, XFS_LOOKUP_GE, &i);
if (error)
goto error0;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, error0);
for (;;) {
error = xfs_inobt_get_rec(cur, &rec, &i);
if (error)
goto error0;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, error0);
if (rec.ir_freecount > 0)
break;
error = xfs_btree_increment(cur, 0, &i);
if (error)
goto error0;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, error0);
}
alloc_inode:
offset = xfs_inobt_first_free_inode(&rec);
ASSERT(offset >= 0);
ASSERT(offset < XFS_INODES_PER_CHUNK);
ASSERT((XFS_AGINO_TO_OFFSET(mp, rec.ir_startino) %
XFS_INODES_PER_CHUNK) == 0);
ino = XFS_AGINO_TO_INO(mp, agno, rec.ir_startino + offset);
rec.ir_free &= ~XFS_INOBT_MASK(offset);
rec.ir_freecount--;
error = xfs_inobt_update(cur, &rec);
if (error)
goto error0;
be32_add_cpu(&agi->agi_freecount, -1);
xfs_ialloc_log_agi(tp, agbp, XFS_AGI_FREECOUNT);
pag->pagi_freecount--;
error = xfs_check_agi_freecount(cur, agi);
if (error)
goto error0;
xfs_btree_del_cursor(cur, XFS_BTREE_NOERROR);
xfs_trans_mod_sb(tp, XFS_TRANS_SB_IFREE, -1);
xfs_perag_put(pag);
*inop = ino;
return 0;
error1:
xfs_btree_del_cursor(tcur, XFS_BTREE_ERROR);
error0:
xfs_btree_del_cursor(cur, XFS_BTREE_ERROR);
xfs_perag_put(pag);
return error;
}
STATIC int
xfs_dialloc_ag_finobt_near(
xfs_agino_t pagino,
struct xfs_btree_cur **ocur,
struct xfs_inobt_rec_incore *rec)
{
struct xfs_btree_cur *lcur = *ocur;
struct xfs_btree_cur *rcur;
struct xfs_inobt_rec_incore rrec;
int error;
int i, j;
error = xfs_inobt_lookup(lcur, pagino, XFS_LOOKUP_LE, &i);
if (error)
return error;
if (i == 1) {
error = xfs_inobt_get_rec(lcur, rec, &i);
if (error)
return error;
XFS_WANT_CORRUPTED_RETURN(lcur->bc_mp, i == 1);
if (pagino >= rec->ir_startino &&
pagino < (rec->ir_startino + XFS_INODES_PER_CHUNK))
return 0;
}
error = xfs_btree_dup_cursor(lcur, &rcur);
if (error)
return error;
error = xfs_inobt_lookup(rcur, pagino, XFS_LOOKUP_GE, &j);
if (error)
goto error_rcur;
if (j == 1) {
error = xfs_inobt_get_rec(rcur, &rrec, &j);
if (error)
goto error_rcur;
XFS_WANT_CORRUPTED_GOTO(lcur->bc_mp, j == 1, error_rcur);
}
XFS_WANT_CORRUPTED_GOTO(lcur->bc_mp, i == 1 || j == 1, error_rcur);
if (i == 1 && j == 1) {
if ((pagino - rec->ir_startino + XFS_INODES_PER_CHUNK - 1) >
(rrec.ir_startino - pagino)) {
*rec = rrec;
xfs_btree_del_cursor(lcur, XFS_BTREE_NOERROR);
*ocur = rcur;
} else {
xfs_btree_del_cursor(rcur, XFS_BTREE_NOERROR);
}
} else if (j == 1) {
*rec = rrec;
xfs_btree_del_cursor(lcur, XFS_BTREE_NOERROR);
*ocur = rcur;
} else if (i == 1) {
xfs_btree_del_cursor(rcur, XFS_BTREE_NOERROR);
}
return 0;
error_rcur:
xfs_btree_del_cursor(rcur, XFS_BTREE_ERROR);
return error;
}
STATIC int
xfs_dialloc_ag_finobt_newino(
struct xfs_agi *agi,
struct xfs_btree_cur *cur,
struct xfs_inobt_rec_incore *rec)
{
int error;
int i;
if (agi->agi_newino != cpu_to_be32(NULLAGINO)) {
error = xfs_inobt_lookup(cur, be32_to_cpu(agi->agi_newino),
XFS_LOOKUP_EQ, &i);
if (error)
return error;
if (i == 1) {
error = xfs_inobt_get_rec(cur, rec, &i);
if (error)
return error;
XFS_WANT_CORRUPTED_RETURN(cur->bc_mp, i == 1);
return 0;
}
}
error = xfs_inobt_lookup(cur, 0, XFS_LOOKUP_GE, &i);
if (error)
return error;
XFS_WANT_CORRUPTED_RETURN(cur->bc_mp, i == 1);
error = xfs_inobt_get_rec(cur, rec, &i);
if (error)
return error;
XFS_WANT_CORRUPTED_RETURN(cur->bc_mp, i == 1);
return 0;
}
STATIC int
xfs_dialloc_ag_update_inobt(
struct xfs_btree_cur *cur,
struct xfs_inobt_rec_incore *frec,
int offset)
{
struct xfs_inobt_rec_incore rec;
int error;
int i;
error = xfs_inobt_lookup(cur, frec->ir_startino, XFS_LOOKUP_EQ, &i);
if (error)
return error;
XFS_WANT_CORRUPTED_RETURN(cur->bc_mp, i == 1);
error = xfs_inobt_get_rec(cur, &rec, &i);
if (error)
return error;
XFS_WANT_CORRUPTED_RETURN(cur->bc_mp, i == 1);
ASSERT((XFS_AGINO_TO_OFFSET(cur->bc_mp, rec.ir_startino) %
XFS_INODES_PER_CHUNK) == 0);
rec.ir_free &= ~XFS_INOBT_MASK(offset);
rec.ir_freecount--;
XFS_WANT_CORRUPTED_RETURN(cur->bc_mp, (rec.ir_free == frec->ir_free) &&
(rec.ir_freecount == frec->ir_freecount));
return xfs_inobt_update(cur, &rec);
}
STATIC int
xfs_dialloc_ag(
struct xfs_trans *tp,
struct xfs_buf *agbp,
xfs_ino_t parent,
xfs_ino_t *inop)
{
struct xfs_mount *mp = tp->t_mountp;
struct xfs_agi *agi = XFS_BUF_TO_AGI(agbp);
xfs_agnumber_t agno = be32_to_cpu(agi->agi_seqno);
xfs_agnumber_t pagno = XFS_INO_TO_AGNO(mp, parent);
xfs_agino_t pagino = XFS_INO_TO_AGINO(mp, parent);
struct xfs_perag *pag;
struct xfs_btree_cur *cur;
struct xfs_btree_cur *icur;
struct xfs_inobt_rec_incore rec;
xfs_ino_t ino;
int error;
int offset;
int i;
if (!xfs_sb_version_hasfinobt(&mp->m_sb))
return xfs_dialloc_ag_inobt(tp, agbp, parent, inop);
pag = xfs_perag_get(mp, agno);
if (!pagino)
pagino = be32_to_cpu(agi->agi_newino);
cur = xfs_inobt_init_cursor(mp, tp, agbp, agno, XFS_BTNUM_FINO);
error = xfs_check_agi_freecount(cur, agi);
if (error)
goto error_cur;
if (agno == pagno)
error = xfs_dialloc_ag_finobt_near(pagino, &cur, &rec);
else
error = xfs_dialloc_ag_finobt_newino(agi, cur, &rec);
if (error)
goto error_cur;
offset = xfs_inobt_first_free_inode(&rec);
ASSERT(offset >= 0);
ASSERT(offset < XFS_INODES_PER_CHUNK);
ASSERT((XFS_AGINO_TO_OFFSET(mp, rec.ir_startino) %
XFS_INODES_PER_CHUNK) == 0);
ino = XFS_AGINO_TO_INO(mp, agno, rec.ir_startino + offset);
rec.ir_free &= ~XFS_INOBT_MASK(offset);
rec.ir_freecount--;
if (rec.ir_freecount)
error = xfs_inobt_update(cur, &rec);
else
error = xfs_btree_delete(cur, &i);
if (error)
goto error_cur;
icur = xfs_inobt_init_cursor(mp, tp, agbp, agno, XFS_BTNUM_INO);
error = xfs_check_agi_freecount(icur, agi);
if (error)
goto error_icur;
error = xfs_dialloc_ag_update_inobt(icur, &rec, offset);
if (error)
goto error_icur;
be32_add_cpu(&agi->agi_freecount, -1);
xfs_ialloc_log_agi(tp, agbp, XFS_AGI_FREECOUNT);
pag->pagi_freecount--;
xfs_trans_mod_sb(tp, XFS_TRANS_SB_IFREE, -1);
error = xfs_check_agi_freecount(icur, agi);
if (error)
goto error_icur;
error = xfs_check_agi_freecount(cur, agi);
if (error)
goto error_icur;
xfs_btree_del_cursor(icur, XFS_BTREE_NOERROR);
xfs_btree_del_cursor(cur, XFS_BTREE_NOERROR);
xfs_perag_put(pag);
*inop = ino;
return 0;
error_icur:
xfs_btree_del_cursor(icur, XFS_BTREE_ERROR);
error_cur:
xfs_btree_del_cursor(cur, XFS_BTREE_ERROR);
xfs_perag_put(pag);
return error;
}
int
xfs_dialloc(
struct xfs_trans *tp,
xfs_ino_t parent,
umode_t mode,
int okalloc,
struct xfs_buf **IO_agbp,
xfs_ino_t *inop)
{
struct xfs_mount *mp = tp->t_mountp;
struct xfs_buf *agbp;
xfs_agnumber_t agno;
int error;
int ialloced;
int noroom = 0;
xfs_agnumber_t start_agno;
struct xfs_perag *pag;
if (*IO_agbp) {
agbp = *IO_agbp;
goto out_alloc;
}
start_agno = xfs_ialloc_ag_select(tp, parent, mode, okalloc);
if (start_agno == NULLAGNUMBER) {
*inop = NULLFSINO;
return 0;
}
if (mp->m_maxicount &&
percpu_counter_read_positive(&mp->m_icount) + mp->m_ialloc_inos
> mp->m_maxicount) {
noroom = 1;
okalloc = 0;
}
agno = start_agno;
for (;;) {
pag = xfs_perag_get(mp, agno);
if (!pag->pagi_inodeok) {
xfs_ialloc_next_ag(mp);
goto nextag;
}
if (!pag->pagi_init) {
error = xfs_ialloc_pagi_init(mp, tp, agno);
if (error)
goto out_error;
}
if (!pag->pagi_freecount && !okalloc)
goto nextag;
error = xfs_ialloc_read_agi(mp, tp, agno, &agbp);
if (error)
goto out_error;
if (pag->pagi_freecount) {
xfs_perag_put(pag);
goto out_alloc;
}
if (!okalloc)
goto nextag_relse_buffer;
error = xfs_ialloc_ag_alloc(tp, agbp, &ialloced);
if (error) {
xfs_trans_brelse(tp, agbp);
if (error != -ENOSPC)
goto out_error;
xfs_perag_put(pag);
*inop = NULLFSINO;
return 0;
}
if (ialloced) {
ASSERT(pag->pagi_freecount > 0);
xfs_perag_put(pag);
*IO_agbp = agbp;
*inop = NULLFSINO;
return 0;
}
nextag_relse_buffer:
xfs_trans_brelse(tp, agbp);
nextag:
xfs_perag_put(pag);
if (++agno == mp->m_sb.sb_agcount)
agno = 0;
if (agno == start_agno) {
*inop = NULLFSINO;
return noroom ? -ENOSPC : 0;
}
}
out_alloc:
*IO_agbp = NULL;
return xfs_dialloc_ag(tp, agbp, parent, inop);
out_error:
xfs_perag_put(pag);
return error;
}
STATIC void
xfs_difree_inode_chunk(
struct xfs_mount *mp,
xfs_agnumber_t agno,
struct xfs_inobt_rec_incore *rec,
struct xfs_bmap_free *flist)
{
xfs_agblock_t sagbno = XFS_AGINO_TO_AGBNO(mp, rec->ir_startino);
int startidx, endidx;
int nextbit;
xfs_agblock_t agbno;
int contigblk;
DECLARE_BITMAP(holemask, XFS_INOBT_HOLEMASK_BITS);
if (!xfs_inobt_issparse(rec->ir_holemask)) {
xfs_bmap_add_free(XFS_AGB_TO_FSB(mp, agno,
XFS_AGINO_TO_AGBNO(mp, rec->ir_startino)),
mp->m_ialloc_blks, flist, mp);
return;
}
ASSERT(sizeof(rec->ir_holemask) <= sizeof(holemask[0]));
holemask[0] = rec->ir_holemask;
startidx = endidx = find_first_zero_bit(holemask,
XFS_INOBT_HOLEMASK_BITS);
nextbit = startidx + 1;
while (startidx < XFS_INOBT_HOLEMASK_BITS) {
nextbit = find_next_zero_bit(holemask, XFS_INOBT_HOLEMASK_BITS,
nextbit);
if (nextbit != XFS_INOBT_HOLEMASK_BITS &&
nextbit == endidx + 1) {
endidx = nextbit;
goto next;
}
agbno = sagbno + (startidx * XFS_INODES_PER_HOLEMASK_BIT) /
mp->m_sb.sb_inopblock;
contigblk = ((endidx - startidx + 1) *
XFS_INODES_PER_HOLEMASK_BIT) /
mp->m_sb.sb_inopblock;
ASSERT(agbno % mp->m_sb.sb_spino_align == 0);
ASSERT(contigblk % mp->m_sb.sb_spino_align == 0);
xfs_bmap_add_free(XFS_AGB_TO_FSB(mp, agno, agbno), contigblk,
flist, mp);
startidx = endidx = nextbit;
next:
nextbit++;
}
}
STATIC int
xfs_difree_inobt(
struct xfs_mount *mp,
struct xfs_trans *tp,
struct xfs_buf *agbp,
xfs_agino_t agino,
struct xfs_bmap_free *flist,
struct xfs_icluster *xic,
struct xfs_inobt_rec_incore *orec)
{
struct xfs_agi *agi = XFS_BUF_TO_AGI(agbp);
xfs_agnumber_t agno = be32_to_cpu(agi->agi_seqno);
struct xfs_perag *pag;
struct xfs_btree_cur *cur;
struct xfs_inobt_rec_incore rec;
int ilen;
int error;
int i;
int off;
ASSERT(agi->agi_magicnum == cpu_to_be32(XFS_AGI_MAGIC));
ASSERT(XFS_AGINO_TO_AGBNO(mp, agino) < be32_to_cpu(agi->agi_length));
cur = xfs_inobt_init_cursor(mp, tp, agbp, agno, XFS_BTNUM_INO);
error = xfs_check_agi_freecount(cur, agi);
if (error)
goto error0;
if ((error = xfs_inobt_lookup(cur, agino, XFS_LOOKUP_LE, &i))) {
xfs_warn(mp, "%s: xfs_inobt_lookup() returned error %d.",
__func__, error);
goto error0;
}
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, error0);
error = xfs_inobt_get_rec(cur, &rec, &i);
if (error) {
xfs_warn(mp, "%s: xfs_inobt_get_rec() returned error %d.",
__func__, error);
goto error0;
}
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, error0);
off = agino - rec.ir_startino;
ASSERT(off >= 0 && off < XFS_INODES_PER_CHUNK);
ASSERT(!(rec.ir_free & XFS_INOBT_MASK(off)));
rec.ir_free |= XFS_INOBT_MASK(off);
rec.ir_freecount++;
if (!(mp->m_flags & XFS_MOUNT_IKEEP) &&
rec.ir_free == XFS_INOBT_ALL_FREE &&
mp->m_sb.sb_inopblock <= XFS_INODES_PER_CHUNK) {
xic->deleted = 1;
xic->first_ino = XFS_AGINO_TO_INO(mp, agno, rec.ir_startino);
xic->alloc = xfs_inobt_irec_to_allocmask(&rec);
ilen = rec.ir_freecount;
be32_add_cpu(&agi->agi_count, -ilen);
be32_add_cpu(&agi->agi_freecount, -(ilen - 1));
xfs_ialloc_log_agi(tp, agbp, XFS_AGI_COUNT | XFS_AGI_FREECOUNT);
pag = xfs_perag_get(mp, agno);
pag->pagi_freecount -= ilen - 1;
xfs_perag_put(pag);
xfs_trans_mod_sb(tp, XFS_TRANS_SB_ICOUNT, -ilen);
xfs_trans_mod_sb(tp, XFS_TRANS_SB_IFREE, -(ilen - 1));
if ((error = xfs_btree_delete(cur, &i))) {
xfs_warn(mp, "%s: xfs_btree_delete returned error %d.",
__func__, error);
goto error0;
}
xfs_difree_inode_chunk(mp, agno, &rec, flist);
} else {
xic->deleted = 0;
error = xfs_inobt_update(cur, &rec);
if (error) {
xfs_warn(mp, "%s: xfs_inobt_update returned error %d.",
__func__, error);
goto error0;
}
be32_add_cpu(&agi->agi_freecount, 1);
xfs_ialloc_log_agi(tp, agbp, XFS_AGI_FREECOUNT);
pag = xfs_perag_get(mp, agno);
pag->pagi_freecount++;
xfs_perag_put(pag);
xfs_trans_mod_sb(tp, XFS_TRANS_SB_IFREE, 1);
}
error = xfs_check_agi_freecount(cur, agi);
if (error)
goto error0;
*orec = rec;
xfs_btree_del_cursor(cur, XFS_BTREE_NOERROR);
return 0;
error0:
xfs_btree_del_cursor(cur, XFS_BTREE_ERROR);
return error;
}
STATIC int
xfs_difree_finobt(
struct xfs_mount *mp,
struct xfs_trans *tp,
struct xfs_buf *agbp,
xfs_agino_t agino,
struct xfs_inobt_rec_incore *ibtrec)
{
struct xfs_agi *agi = XFS_BUF_TO_AGI(agbp);
xfs_agnumber_t agno = be32_to_cpu(agi->agi_seqno);
struct xfs_btree_cur *cur;
struct xfs_inobt_rec_incore rec;
int offset = agino - ibtrec->ir_startino;
int error;
int i;
cur = xfs_inobt_init_cursor(mp, tp, agbp, agno, XFS_BTNUM_FINO);
error = xfs_inobt_lookup(cur, ibtrec->ir_startino, XFS_LOOKUP_EQ, &i);
if (error)
goto error;
if (i == 0) {
XFS_WANT_CORRUPTED_GOTO(mp, ibtrec->ir_freecount == 1, error);
error = xfs_inobt_insert_rec(cur, ibtrec->ir_holemask,
ibtrec->ir_count,
ibtrec->ir_freecount,
ibtrec->ir_free, &i);
if (error)
goto error;
ASSERT(i == 1);
goto out;
}
error = xfs_inobt_get_rec(cur, &rec, &i);
if (error)
goto error;
XFS_WANT_CORRUPTED_GOTO(mp, i == 1, error);
rec.ir_free |= XFS_INOBT_MASK(offset);
rec.ir_freecount++;
XFS_WANT_CORRUPTED_GOTO(mp, (rec.ir_free == ibtrec->ir_free) &&
(rec.ir_freecount == ibtrec->ir_freecount),
error);
if (rec.ir_free == XFS_INOBT_ALL_FREE &&
mp->m_sb.sb_inopblock <= XFS_INODES_PER_CHUNK &&
!(mp->m_flags & XFS_MOUNT_IKEEP)) {
error = xfs_btree_delete(cur, &i);
if (error)
goto error;
ASSERT(i == 1);
} else {
error = xfs_inobt_update(cur, &rec);
if (error)
goto error;
}
out:
error = xfs_check_agi_freecount(cur, agi);
if (error)
goto error;
xfs_btree_del_cursor(cur, XFS_BTREE_NOERROR);
return 0;
error:
xfs_btree_del_cursor(cur, XFS_BTREE_ERROR);
return error;
}
int
xfs_difree(
struct xfs_trans *tp,
xfs_ino_t inode,
struct xfs_bmap_free *flist,
struct xfs_icluster *xic)
{
xfs_agblock_t agbno;
struct xfs_buf *agbp;
xfs_agino_t agino;
xfs_agnumber_t agno;
int error;
struct xfs_mount *mp;
struct xfs_inobt_rec_incore rec;
mp = tp->t_mountp;
agno = XFS_INO_TO_AGNO(mp, inode);
if (agno >= mp->m_sb.sb_agcount) {
xfs_warn(mp, "%s: agno >= mp->m_sb.sb_agcount (%d >= %d).",
__func__, agno, mp->m_sb.sb_agcount);
ASSERT(0);
return -EINVAL;
}
agino = XFS_INO_TO_AGINO(mp, inode);
if (inode != XFS_AGINO_TO_INO(mp, agno, agino)) {
xfs_warn(mp, "%s: inode != XFS_AGINO_TO_INO() (%llu != %llu).",
__func__, (unsigned long long)inode,
(unsigned long long)XFS_AGINO_TO_INO(mp, agno, agino));
ASSERT(0);
return -EINVAL;
}
agbno = XFS_AGINO_TO_AGBNO(mp, agino);
if (agbno >= mp->m_sb.sb_agblocks) {
xfs_warn(mp, "%s: agbno >= mp->m_sb.sb_agblocks (%d >= %d).",
__func__, agbno, mp->m_sb.sb_agblocks);
ASSERT(0);
return -EINVAL;
}
error = xfs_ialloc_read_agi(mp, tp, agno, &agbp);
if (error) {
xfs_warn(mp, "%s: xfs_ialloc_read_agi() returned error %d.",
__func__, error);
return error;
}
error = xfs_difree_inobt(mp, tp, agbp, agino, flist, xic, &rec);
if (error)
goto error0;
if (xfs_sb_version_hasfinobt(&mp->m_sb)) {
error = xfs_difree_finobt(mp, tp, agbp, agino, &rec);
if (error)
goto error0;
}
return 0;
error0:
return error;
}
STATIC int
xfs_imap_lookup(
struct xfs_mount *mp,
struct xfs_trans *tp,
xfs_agnumber_t agno,
xfs_agino_t agino,
xfs_agblock_t agbno,
xfs_agblock_t *chunk_agbno,
xfs_agblock_t *offset_agbno,
int flags)
{
struct xfs_inobt_rec_incore rec;
struct xfs_btree_cur *cur;
struct xfs_buf *agbp;
int error;
int i;
error = xfs_ialloc_read_agi(mp, tp, agno, &agbp);
if (error) {
xfs_alert(mp,
"%s: xfs_ialloc_read_agi() returned error %d, agno %d",
__func__, error, agno);
return error;
}
cur = xfs_inobt_init_cursor(mp, tp, agbp, agno, XFS_BTNUM_INO);
error = xfs_inobt_lookup(cur, agino, XFS_LOOKUP_LE, &i);
if (!error) {
if (i)
error = xfs_inobt_get_rec(cur, &rec, &i);
if (!error && i == 0)
error = -EINVAL;
}
xfs_trans_brelse(tp, agbp);
xfs_btree_del_cursor(cur, error ? XFS_BTREE_ERROR : XFS_BTREE_NOERROR);
if (error)
return error;
if (rec.ir_startino > agino ||
rec.ir_startino + mp->m_ialloc_inos <= agino)
return -EINVAL;
if ((flags & XFS_IGET_UNTRUSTED) &&
(rec.ir_free & XFS_INOBT_MASK(agino - rec.ir_startino)))
return -EINVAL;
*chunk_agbno = XFS_AGINO_TO_AGBNO(mp, rec.ir_startino);
*offset_agbno = agbno - *chunk_agbno;
return 0;
}
int
xfs_imap(
xfs_mount_t *mp,
xfs_trans_t *tp,
xfs_ino_t ino,
struct xfs_imap *imap,
uint flags)
{
xfs_agblock_t agbno;
xfs_agino_t agino;
xfs_agnumber_t agno;
int blks_per_cluster;
xfs_agblock_t chunk_agbno;
xfs_agblock_t cluster_agbno;
int error;
int offset;
xfs_agblock_t offset_agbno;
ASSERT(ino != NULLFSINO);
agno = XFS_INO_TO_AGNO(mp, ino);
agino = XFS_INO_TO_AGINO(mp, ino);
agbno = XFS_AGINO_TO_AGBNO(mp, agino);
if (agno >= mp->m_sb.sb_agcount || agbno >= mp->m_sb.sb_agblocks ||
ino != XFS_AGINO_TO_INO(mp, agno, agino)) {
#ifdef DEBUG
if (flags & XFS_IGET_UNTRUSTED)
return -EINVAL;
if (agno >= mp->m_sb.sb_agcount) {
xfs_alert(mp,
"%s: agno (%d) >= mp->m_sb.sb_agcount (%d)",
__func__, agno, mp->m_sb.sb_agcount);
}
if (agbno >= mp->m_sb.sb_agblocks) {
xfs_alert(mp,
"%s: agbno (0x%llx) >= mp->m_sb.sb_agblocks (0x%lx)",
__func__, (unsigned long long)agbno,
(unsigned long)mp->m_sb.sb_agblocks);
}
if (ino != XFS_AGINO_TO_INO(mp, agno, agino)) {
xfs_alert(mp,
"%s: ino (0x%llx) != XFS_AGINO_TO_INO() (0x%llx)",
__func__, ino,
XFS_AGINO_TO_INO(mp, agno, agino));
}
xfs_stack_trace();
#endif
return -EINVAL;
}
blks_per_cluster = xfs_icluster_size_fsb(mp);
if (flags & XFS_IGET_UNTRUSTED) {
error = xfs_imap_lookup(mp, tp, agno, agino, agbno,
&chunk_agbno, &offset_agbno, flags);
if (error)
return error;
goto out_map;
}
if (blks_per_cluster == 1) {
offset = XFS_INO_TO_OFFSET(mp, ino);
ASSERT(offset < mp->m_sb.sb_inopblock);
imap->im_blkno = XFS_AGB_TO_DADDR(mp, agno, agbno);
imap->im_len = XFS_FSB_TO_BB(mp, 1);
imap->im_boffset = (ushort)(offset << mp->m_sb.sb_inodelog);
return 0;
}
if (mp->m_inoalign_mask) {
offset_agbno = agbno & mp->m_inoalign_mask;
chunk_agbno = agbno - offset_agbno;
} else {
error = xfs_imap_lookup(mp, tp, agno, agino, agbno,
&chunk_agbno, &offset_agbno, flags);
if (error)
return error;
}
out_map:
ASSERT(agbno >= chunk_agbno);
cluster_agbno = chunk_agbno +
((offset_agbno / blks_per_cluster) * blks_per_cluster);
offset = ((agbno - cluster_agbno) * mp->m_sb.sb_inopblock) +
XFS_INO_TO_OFFSET(mp, ino);
imap->im_blkno = XFS_AGB_TO_DADDR(mp, agno, cluster_agbno);
imap->im_len = XFS_FSB_TO_BB(mp, blks_per_cluster);
imap->im_boffset = (ushort)(offset << mp->m_sb.sb_inodelog);
if ((imap->im_blkno + imap->im_len) >
XFS_FSB_TO_BB(mp, mp->m_sb.sb_dblocks)) {
xfs_alert(mp,
"%s: (im_blkno (0x%llx) + im_len (0x%llx)) > sb_dblocks (0x%llx)",
__func__, (unsigned long long) imap->im_blkno,
(unsigned long long) imap->im_len,
XFS_FSB_TO_BB(mp, mp->m_sb.sb_dblocks));
return -EINVAL;
}
return 0;
}
void
xfs_ialloc_compute_maxlevels(
xfs_mount_t *mp)
{
int level;
uint maxblocks;
uint maxleafents;
int minleafrecs;
int minnoderecs;
maxleafents = (1LL << XFS_INO_AGINO_BITS(mp)) >>
XFS_INODES_PER_CHUNK_LOG;
minleafrecs = mp->m_alloc_mnr[0];
minnoderecs = mp->m_alloc_mnr[1];
maxblocks = (maxleafents + minleafrecs - 1) / minleafrecs;
for (level = 1; maxblocks > 1; level++)
maxblocks = (maxblocks + minnoderecs - 1) / minnoderecs;
mp->m_in_maxlevels = level;
}
void
xfs_ialloc_log_agi(
xfs_trans_t *tp,
xfs_buf_t *bp,
int fields)
{
int first;
int last;
static const short offsets[] = {
offsetof(xfs_agi_t, agi_magicnum),
offsetof(xfs_agi_t, agi_versionnum),
offsetof(xfs_agi_t, agi_seqno),
offsetof(xfs_agi_t, agi_length),
offsetof(xfs_agi_t, agi_count),
offsetof(xfs_agi_t, agi_root),
offsetof(xfs_agi_t, agi_level),
offsetof(xfs_agi_t, agi_freecount),
offsetof(xfs_agi_t, agi_newino),
offsetof(xfs_agi_t, agi_dirino),
offsetof(xfs_agi_t, agi_unlinked),
offsetof(xfs_agi_t, agi_free_root),
offsetof(xfs_agi_t, agi_free_level),
sizeof(xfs_agi_t)
};
#ifdef DEBUG
xfs_agi_t *agi;
agi = XFS_BUF_TO_AGI(bp);
ASSERT(agi->agi_magicnum == cpu_to_be32(XFS_AGI_MAGIC));
#endif
xfs_trans_buf_set_type(tp, bp, XFS_BLFT_AGI_BUF);
if (fields & XFS_AGI_ALL_BITS_R1) {
xfs_btree_offsets(fields, offsets, XFS_AGI_NUM_BITS_R1,
&first, &last);
xfs_trans_log_buf(tp, bp, first, last);
}
fields &= ~XFS_AGI_ALL_BITS_R1;
if (fields) {
xfs_btree_offsets(fields, offsets, XFS_AGI_NUM_BITS_R2,
&first, &last);
xfs_trans_log_buf(tp, bp, first, last);
}
}
STATIC void
xfs_check_agi_unlinked(
struct xfs_agi *agi)
{
int i;
for (i = 0; i < XFS_AGI_UNLINKED_BUCKETS; i++)
ASSERT(agi->agi_unlinked[i]);
}
static bool
xfs_agi_verify(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
struct xfs_agi *agi = XFS_BUF_TO_AGI(bp);
if (xfs_sb_version_hascrc(&mp->m_sb)) {
if (!uuid_equal(&agi->agi_uuid, &mp->m_sb.sb_meta_uuid))
return false;
if (!xfs_log_check_lsn(mp,
be64_to_cpu(XFS_BUF_TO_AGI(bp)->agi_lsn)))
return false;
}
if (agi->agi_magicnum != cpu_to_be32(XFS_AGI_MAGIC))
return false;
if (!XFS_AGI_GOOD_VERSION(be32_to_cpu(agi->agi_versionnum)))
return false;
if (be32_to_cpu(agi->agi_level) > XFS_BTREE_MAXLEVELS)
return false;
if (bp->b_pag && be32_to_cpu(agi->agi_seqno) != bp->b_pag->pag_agno)
return false;
xfs_check_agi_unlinked(agi);
return true;
}
static void
xfs_agi_read_verify(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
if (xfs_sb_version_hascrc(&mp->m_sb) &&
!xfs_buf_verify_cksum(bp, XFS_AGI_CRC_OFF))
xfs_buf_ioerror(bp, -EFSBADCRC);
else if (XFS_TEST_ERROR(!xfs_agi_verify(bp), mp,
XFS_ERRTAG_IALLOC_READ_AGI,
XFS_RANDOM_IALLOC_READ_AGI))
xfs_buf_ioerror(bp, -EFSCORRUPTED);
if (bp->b_error)
xfs_verifier_error(bp);
}
static void
xfs_agi_write_verify(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
struct xfs_buf_log_item *bip = bp->b_fspriv;
if (!xfs_agi_verify(bp)) {
xfs_buf_ioerror(bp, -EFSCORRUPTED);
xfs_verifier_error(bp);
return;
}
if (!xfs_sb_version_hascrc(&mp->m_sb))
return;
if (bip)
XFS_BUF_TO_AGI(bp)->agi_lsn = cpu_to_be64(bip->bli_item.li_lsn);
xfs_buf_update_cksum(bp, XFS_AGI_CRC_OFF);
}
int
xfs_read_agi(
struct xfs_mount *mp,
struct xfs_trans *tp,
xfs_agnumber_t agno,
struct xfs_buf **bpp)
{
int error;
trace_xfs_read_agi(mp, agno);
ASSERT(agno != NULLAGNUMBER);
error = xfs_trans_read_buf(mp, tp, mp->m_ddev_targp,
XFS_AG_DADDR(mp, agno, XFS_AGI_DADDR(mp)),
XFS_FSS_TO_BB(mp, 1), 0, bpp, &xfs_agi_buf_ops);
if (error)
return error;
xfs_buf_set_ref(*bpp, XFS_AGI_REF);
return 0;
}
int
xfs_ialloc_read_agi(
struct xfs_mount *mp,
struct xfs_trans *tp,
xfs_agnumber_t agno,
struct xfs_buf **bpp)
{
struct xfs_agi *agi;
struct xfs_perag *pag;
int error;
trace_xfs_ialloc_read_agi(mp, agno);
error = xfs_read_agi(mp, tp, agno, bpp);
if (error)
return error;
agi = XFS_BUF_TO_AGI(*bpp);
pag = xfs_perag_get(mp, agno);
if (!pag->pagi_init) {
pag->pagi_freecount = be32_to_cpu(agi->agi_freecount);
pag->pagi_count = be32_to_cpu(agi->agi_count);
pag->pagi_init = 1;
}
ASSERT(pag->pagi_freecount == be32_to_cpu(agi->agi_freecount) ||
XFS_FORCED_SHUTDOWN(mp));
xfs_perag_put(pag);
return 0;
}
int
xfs_ialloc_pagi_init(
xfs_mount_t *mp,
xfs_trans_t *tp,
xfs_agnumber_t agno)
{
xfs_buf_t *bp = NULL;
int error;
error = xfs_ialloc_read_agi(mp, tp, agno, &bp);
if (error)
return error;
if (bp)
xfs_trans_brelse(tp, bp);
return 0;
}
