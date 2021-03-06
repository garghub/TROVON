STATIC int
xfs_internal_inum(
xfs_mount_t *mp,
xfs_ino_t ino)
{
return (ino == mp->m_sb.sb_rbmino || ino == mp->m_sb.sb_rsumino ||
(xfs_sb_version_hasquota(&mp->m_sb) &&
xfs_is_quota_inode(&mp->m_sb, ino)));
}
int
xfs_bulkstat_one_int(
struct xfs_mount *mp,
xfs_ino_t ino,
void __user *buffer,
int ubsize,
bulkstat_one_fmt_pf formatter,
int *ubused,
int *stat)
{
struct xfs_icdinode *dic;
struct xfs_inode *ip;
struct xfs_bstat *buf;
int error = 0;
*stat = BULKSTAT_RV_NOTHING;
if (!buffer || xfs_internal_inum(mp, ino))
return -EINVAL;
buf = kmem_alloc(sizeof(*buf), KM_SLEEP | KM_MAYFAIL);
if (!buf)
return -ENOMEM;
error = xfs_iget(mp, NULL, ino,
(XFS_IGET_DONTCACHE | XFS_IGET_UNTRUSTED),
XFS_ILOCK_SHARED, &ip);
if (error)
goto out_free;
ASSERT(ip != NULL);
ASSERT(ip->i_imap.im_blkno != 0);
dic = &ip->i_d;
buf->bs_nlink = dic->di_nlink;
buf->bs_projid_lo = dic->di_projid_lo;
buf->bs_projid_hi = dic->di_projid_hi;
buf->bs_ino = ino;
buf->bs_mode = dic->di_mode;
buf->bs_uid = dic->di_uid;
buf->bs_gid = dic->di_gid;
buf->bs_size = dic->di_size;
buf->bs_atime.tv_sec = dic->di_atime.t_sec;
buf->bs_atime.tv_nsec = dic->di_atime.t_nsec;
buf->bs_mtime.tv_sec = dic->di_mtime.t_sec;
buf->bs_mtime.tv_nsec = dic->di_mtime.t_nsec;
buf->bs_ctime.tv_sec = dic->di_ctime.t_sec;
buf->bs_ctime.tv_nsec = dic->di_ctime.t_nsec;
buf->bs_xflags = xfs_ip2xflags(ip);
buf->bs_extsize = dic->di_extsize << mp->m_sb.sb_blocklog;
buf->bs_extents = dic->di_nextents;
buf->bs_gen = dic->di_gen;
memset(buf->bs_pad, 0, sizeof(buf->bs_pad));
buf->bs_dmevmask = dic->di_dmevmask;
buf->bs_dmstate = dic->di_dmstate;
buf->bs_aextents = dic->di_anextents;
buf->bs_forkoff = XFS_IFORK_BOFF(ip);
switch (dic->di_format) {
case XFS_DINODE_FMT_DEV:
buf->bs_rdev = ip->i_df.if_u2.if_rdev;
buf->bs_blksize = BLKDEV_IOSIZE;
buf->bs_blocks = 0;
break;
case XFS_DINODE_FMT_LOCAL:
case XFS_DINODE_FMT_UUID:
buf->bs_rdev = 0;
buf->bs_blksize = mp->m_sb.sb_blocksize;
buf->bs_blocks = 0;
break;
case XFS_DINODE_FMT_EXTENTS:
case XFS_DINODE_FMT_BTREE:
buf->bs_rdev = 0;
buf->bs_blksize = mp->m_sb.sb_blocksize;
buf->bs_blocks = dic->di_nblocks + ip->i_delayed_blks;
break;
}
xfs_iunlock(ip, XFS_ILOCK_SHARED);
IRELE(ip);
error = formatter(buffer, ubsize, ubused, buf);
if (!error)
*stat = BULKSTAT_RV_DIDONE;
out_free:
kmem_free(buf);
return error;
}
STATIC int
xfs_bulkstat_one_fmt(
void __user *ubuffer,
int ubsize,
int *ubused,
const xfs_bstat_t *buffer)
{
if (ubsize < sizeof(*buffer))
return -ENOMEM;
if (copy_to_user(ubuffer, buffer, sizeof(*buffer)))
return -EFAULT;
if (ubused)
*ubused = sizeof(*buffer);
return 0;
}
int
xfs_bulkstat_one(
xfs_mount_t *mp,
xfs_ino_t ino,
void __user *buffer,
int ubsize,
int *ubused,
int *stat)
{
return xfs_bulkstat_one_int(mp, ino, buffer, ubsize,
xfs_bulkstat_one_fmt, ubused, stat);
}
STATIC void
xfs_bulkstat_ichunk_ra(
struct xfs_mount *mp,
xfs_agnumber_t agno,
struct xfs_inobt_rec_incore *irec)
{
xfs_agblock_t agbno;
struct blk_plug plug;
int blks_per_cluster;
int inodes_per_cluster;
int i;
agbno = XFS_AGINO_TO_AGBNO(mp, irec->ir_startino);
blks_per_cluster = xfs_icluster_size_fsb(mp);
inodes_per_cluster = blks_per_cluster << mp->m_sb.sb_inopblog;
blk_start_plug(&plug);
for (i = 0; i < XFS_INODES_PER_CHUNK;
i += inodes_per_cluster, agbno += blks_per_cluster) {
if (xfs_inobt_maskn(i, inodes_per_cluster) & ~irec->ir_free) {
xfs_btree_reada_bufs(mp, agno, agbno, blks_per_cluster,
&xfs_inode_buf_ops);
}
}
blk_finish_plug(&plug);
}
STATIC int
xfs_bulkstat_grab_ichunk(
struct xfs_btree_cur *cur,
xfs_agino_t agino,
int *icount,
struct xfs_inobt_rec_incore *irec)
{
int idx;
int stat;
int error = 0;
error = xfs_inobt_lookup(cur, agino, XFS_LOOKUP_LE, &stat);
if (error)
return error;
if (!stat) {
*icount = 0;
return error;
}
error = xfs_inobt_get_rec(cur, irec, &stat);
if (error)
return error;
XFS_WANT_CORRUPTED_RETURN(stat == 1);
if (irec->ir_startino + XFS_INODES_PER_CHUNK <= agino)
return -EINVAL;
idx = agino - irec->ir_startino + 1;
if (idx < XFS_INODES_PER_CHUNK &&
(xfs_inobt_maskn(idx, XFS_INODES_PER_CHUNK - idx) & ~irec->ir_free)) {
int i;
for (i = 0; i < idx; i++) {
if (XFS_INOBT_MASK(i) & ~irec->ir_free)
irec->ir_freecount++;
}
irec->ir_free |= xfs_inobt_maskn(0, idx);
*icount = XFS_INODES_PER_CHUNK - irec->ir_freecount;
}
return 0;
}
int
xfs_bulkstat_ag_ichunk(
struct xfs_mount *mp,
xfs_agnumber_t agno,
struct xfs_inobt_rec_incore *irbp,
bulkstat_one_pf formatter,
size_t statstruct_size,
struct xfs_bulkstat_agichunk *acp)
{
xfs_ino_t lastino = acp->ac_lastino;
char __user **ubufp = acp->ac_ubuffer;
int ubleft = acp->ac_ubleft;
int ubelem = acp->ac_ubelem;
int chunkidx, clustidx;
int error = 0;
xfs_agino_t agino;
for (agino = irbp->ir_startino, chunkidx = clustidx = 0;
XFS_BULKSTAT_UBLEFT(ubleft) &&
irbp->ir_freecount < XFS_INODES_PER_CHUNK;
chunkidx++, clustidx++, agino++) {
int fmterror;
int ubused;
xfs_ino_t ino = XFS_AGINO_TO_INO(mp, agno, agino);
ASSERT(chunkidx < XFS_INODES_PER_CHUNK);
if (XFS_INOBT_MASK(chunkidx) & irbp->ir_free) {
lastino = ino;
continue;
}
irbp->ir_freecount++;
ubused = statstruct_size;
error = formatter(mp, ino, *ubufp, ubleft, &ubused, &fmterror);
if (fmterror == BULKSTAT_RV_NOTHING) {
if (error && error != -ENOENT && error != -EINVAL) {
ubleft = 0;
break;
}
lastino = ino;
continue;
}
if (fmterror == BULKSTAT_RV_GIVEUP) {
ubleft = 0;
ASSERT(error);
break;
}
if (*ubufp)
*ubufp += ubused;
ubleft -= ubused;
ubelem++;
lastino = ino;
}
acp->ac_lastino = lastino;
acp->ac_ubleft = ubleft;
acp->ac_ubelem = ubelem;
return error;
}
int
xfs_bulkstat(
xfs_mount_t *mp,
xfs_ino_t *lastinop,
int *ubcountp,
bulkstat_one_pf formatter,
size_t statstruct_size,
char __user *ubuffer,
int *done)
{
xfs_buf_t *agbp;
xfs_agi_t *agi;
xfs_agino_t agino;
xfs_agnumber_t agno;
xfs_btree_cur_t *cur;
int end_of_ag;
int error;
int fmterror;
int i;
int icount;
size_t irbsize;
xfs_ino_t ino;
xfs_inobt_rec_incore_t *irbp;
xfs_inobt_rec_incore_t *irbuf;
xfs_inobt_rec_incore_t *irbufend;
xfs_ino_t lastino;
int nirbuf;
int rval;
int tmp;
int ubcount;
int ubleft;
char __user *ubufp;
int ubelem;
ino = (xfs_ino_t)*lastinop;
lastino = ino;
agno = XFS_INO_TO_AGNO(mp, ino);
agino = XFS_INO_TO_AGINO(mp, ino);
if (agno >= mp->m_sb.sb_agcount ||
ino != XFS_AGINO_TO_INO(mp, agno, agino)) {
*done = 1;
*ubcountp = 0;
return 0;
}
ubcount = *ubcountp;
ubleft = ubcount * statstruct_size;
*ubcountp = ubelem = 0;
*done = 0;
fmterror = 0;
ubufp = ubuffer;
irbuf = kmem_zalloc_greedy(&irbsize, PAGE_SIZE, PAGE_SIZE * 4);
if (!irbuf)
return -ENOMEM;
nirbuf = irbsize / sizeof(*irbuf);
rval = 0;
while (XFS_BULKSTAT_UBLEFT(ubleft) && agno < mp->m_sb.sb_agcount) {
cond_resched();
error = xfs_ialloc_read_agi(mp, NULL, agno, &agbp);
if (error)
break;
agi = XFS_BUF_TO_AGI(agbp);
cur = xfs_inobt_init_cursor(mp, NULL, agbp, agno,
XFS_BTNUM_INO);
irbp = irbuf;
irbufend = irbuf + nirbuf;
end_of_ag = 0;
icount = 0;
if (agino > 0) {
struct xfs_inobt_rec_incore r;
error = xfs_bulkstat_grab_ichunk(cur, agino, &icount, &r);
if (error)
break;
if (icount) {
irbp->ir_startino = r.ir_startino;
irbp->ir_freecount = r.ir_freecount;
irbp->ir_free = r.ir_free;
irbp++;
agino = r.ir_startino + XFS_INODES_PER_CHUNK;
}
error = xfs_btree_increment(cur, 0, &tmp);
} else {
error = xfs_inobt_lookup(cur, 0, XFS_LOOKUP_GE, &tmp);
}
if (error)
break;
while (irbp < irbufend && icount < ubcount) {
struct xfs_inobt_rec_incore r;
error = xfs_inobt_get_rec(cur, &r, &i);
if (error || i == 0) {
end_of_ag = 1;
break;
}
if (r.ir_freecount < XFS_INODES_PER_CHUNK) {
xfs_bulkstat_ichunk_ra(mp, agno, &r);
irbp->ir_startino = r.ir_startino;
irbp->ir_freecount = r.ir_freecount;
irbp->ir_free = r.ir_free;
irbp++;
icount += XFS_INODES_PER_CHUNK - r.ir_freecount;
}
agino = r.ir_startino + XFS_INODES_PER_CHUNK;
error = xfs_btree_increment(cur, 0, &tmp);
cond_resched();
}
xfs_btree_del_cursor(cur, XFS_BTREE_NOERROR);
xfs_buf_relse(agbp);
irbufend = irbp;
for (irbp = irbuf;
irbp < irbufend && XFS_BULKSTAT_UBLEFT(ubleft); irbp++) {
struct xfs_bulkstat_agichunk ac;
ac.ac_lastino = lastino;
ac.ac_ubuffer = &ubuffer;
ac.ac_ubleft = ubleft;
ac.ac_ubelem = ubelem;
error = xfs_bulkstat_ag_ichunk(mp, agno, irbp,
formatter, statstruct_size, &ac);
if (error)
rval = error;
lastino = ac.ac_lastino;
ubleft = ac.ac_ubleft;
ubelem = ac.ac_ubelem;
cond_resched();
}
if (XFS_BULKSTAT_UBLEFT(ubleft)) {
if (end_of_ag) {
agno++;
agino = 0;
} else
agino = XFS_INO_TO_AGINO(mp, lastino);
} else
break;
}
kmem_free(irbuf);
*ubcountp = ubelem;
if (ubelem)
rval = 0;
if (agno >= mp->m_sb.sb_agcount) {
*lastinop = (xfs_ino_t)XFS_AGINO_TO_INO(mp, agno, 0);
*done = 1;
} else
*lastinop = (xfs_ino_t)lastino;
return rval;
}
int
xfs_inumbers_fmt(
void __user *ubuffer,
const struct xfs_inogrp *buffer,
long count,
long *written)
{
if (copy_to_user(ubuffer, buffer, count * sizeof(*buffer)))
return -EFAULT;
*written = count * sizeof(*buffer);
return 0;
}
int
xfs_inumbers(
struct xfs_mount *mp,
xfs_ino_t *lastino,
int *count,
void __user *ubuffer,
inumbers_fmt_pf formatter)
{
xfs_agnumber_t agno = XFS_INO_TO_AGNO(mp, *lastino);
xfs_agino_t agino = XFS_INO_TO_AGINO(mp, *lastino);
struct xfs_btree_cur *cur = NULL;
struct xfs_buf *agbp = NULL;
struct xfs_inogrp *buffer;
int bcount;
int left = *count;
int bufidx = 0;
int error = 0;
*count = 0;
if (agno >= mp->m_sb.sb_agcount ||
*lastino != XFS_AGINO_TO_INO(mp, agno, agino))
return error;
bcount = MIN(left, (int)(PAGE_SIZE / sizeof(*buffer)));
buffer = kmem_alloc(bcount * sizeof(*buffer), KM_SLEEP);
do {
struct xfs_inobt_rec_incore r;
int stat;
if (!agbp) {
error = xfs_ialloc_read_agi(mp, NULL, agno, &agbp);
if (error)
break;
cur = xfs_inobt_init_cursor(mp, NULL, agbp, agno,
XFS_BTNUM_INO);
error = xfs_inobt_lookup(cur, agino, XFS_LOOKUP_GE,
&stat);
if (error)
break;
if (!stat)
goto next_ag;
}
error = xfs_inobt_get_rec(cur, &r, &stat);
if (error)
break;
if (!stat)
goto next_ag;
agino = r.ir_startino + XFS_INODES_PER_CHUNK - 1;
buffer[bufidx].xi_startino =
XFS_AGINO_TO_INO(mp, agno, r.ir_startino);
buffer[bufidx].xi_alloccount =
XFS_INODES_PER_CHUNK - r.ir_freecount;
buffer[bufidx].xi_allocmask = ~r.ir_free;
if (++bufidx == bcount) {
long written;
error = formatter(ubuffer, buffer, bufidx, &written);
if (error)
break;
ubuffer += written;
*count += bufidx;
bufidx = 0;
}
if (!--left)
break;
error = xfs_btree_increment(cur, 0, &stat);
if (error)
break;
if (stat)
continue;
next_ag:
xfs_btree_del_cursor(cur, XFS_BTREE_ERROR);
cur = NULL;
xfs_buf_relse(agbp);
agbp = NULL;
agino = 0;
} while (++agno < mp->m_sb.sb_agcount);
if (!error) {
if (bufidx) {
long written;
error = formatter(ubuffer, buffer, bufidx, &written);
if (!error)
*count += bufidx;
}
*lastino = XFS_AGINO_TO_INO(mp, agno, agino);
}
kmem_free(buffer);
if (cur)
xfs_btree_del_cursor(cur, (error ? XFS_BTREE_ERROR :
XFS_BTREE_NOERROR));
if (agbp)
xfs_buf_relse(agbp);
return error;
}
