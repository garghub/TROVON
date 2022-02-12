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
struct inode *inode;
struct xfs_bstat *buf;
int error = 0;
*stat = BULKSTAT_RV_NOTHING;
if (!buffer || xfs_internal_inum(mp, ino))
return -EINVAL;
buf = kmem_zalloc(sizeof(*buf), KM_SLEEP | KM_MAYFAIL);
if (!buf)
return -ENOMEM;
error = xfs_iget(mp, NULL, ino,
(XFS_IGET_DONTCACHE | XFS_IGET_UNTRUSTED),
XFS_ILOCK_SHARED, &ip);
if (error)
goto out_free;
ASSERT(ip != NULL);
ASSERT(ip->i_imap.im_blkno != 0);
inode = VFS_I(ip);
dic = &ip->i_d;
buf->bs_projid_lo = dic->di_projid_lo;
buf->bs_projid_hi = dic->di_projid_hi;
buf->bs_ino = ino;
buf->bs_uid = dic->di_uid;
buf->bs_gid = dic->di_gid;
buf->bs_size = dic->di_size;
buf->bs_nlink = inode->i_nlink;
buf->bs_atime.tv_sec = inode->i_atime.tv_sec;
buf->bs_atime.tv_nsec = inode->i_atime.tv_nsec;
buf->bs_mtime.tv_sec = inode->i_mtime.tv_sec;
buf->bs_mtime.tv_nsec = inode->i_mtime.tv_nsec;
buf->bs_ctime.tv_sec = inode->i_ctime.tv_sec;
buf->bs_ctime.tv_nsec = inode->i_ctime.tv_nsec;
buf->bs_gen = inode->i_generation;
buf->bs_mode = inode->i_mode;
buf->bs_xflags = xfs_ip2xflags(ip);
buf->bs_extsize = dic->di_extsize << mp->m_sb.sb_blocklog;
buf->bs_extents = dic->di_nextents;
memset(buf->bs_pad, 0, sizeof(buf->bs_pad));
buf->bs_dmevmask = dic->di_dmevmask;
buf->bs_dmstate = dic->di_dmstate;
buf->bs_aextents = dic->di_anextents;
buf->bs_forkoff = XFS_IFORK_BOFF(ip);
if (dic->di_version == 3) {
if (dic->di_flags2 & XFS_DIFLAG2_COWEXTSIZE)
buf->bs_cowextsize = dic->di_cowextsize <<
mp->m_sb.sb_blocklog;
}
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
XFS_WANT_CORRUPTED_RETURN(cur->bc_mp, stat == 1);
if (irec->ir_startino + XFS_INODES_PER_CHUNK <= agino) {
*icount = 0;
return 0;
}
idx = agino - irec->ir_startino + 1;
if (idx < XFS_INODES_PER_CHUNK &&
(xfs_inobt_maskn(idx, XFS_INODES_PER_CHUNK - idx) & ~irec->ir_free)) {
int i;
for (i = 0; i < idx; i++) {
if (XFS_INOBT_MASK(i) & ~irec->ir_free)
irec->ir_freecount++;
}
irec->ir_free |= xfs_inobt_maskn(0, idx);
*icount = irec->ir_count - irec->ir_freecount;
}
return 0;
}
static int
xfs_bulkstat_ag_ichunk(
struct xfs_mount *mp,
xfs_agnumber_t agno,
struct xfs_inobt_rec_incore *irbp,
bulkstat_one_pf formatter,
size_t statstruct_size,
struct xfs_bulkstat_agichunk *acp,
xfs_agino_t *last_agino)
{
char __user **ubufp = acp->ac_ubuffer;
int chunkidx;
int error = 0;
xfs_agino_t agino = irbp->ir_startino;
for (chunkidx = 0; chunkidx < XFS_INODES_PER_CHUNK;
chunkidx++, agino++) {
int fmterror;
int ubused;
if (acp->ac_ubleft < statstruct_size)
break;
if (XFS_INOBT_MASK(chunkidx) & irbp->ir_free)
continue;
ubused = statstruct_size;
error = formatter(mp, XFS_AGINO_TO_INO(mp, agno, agino),
*ubufp, acp->ac_ubleft, &ubused, &fmterror);
if (fmterror == BULKSTAT_RV_GIVEUP ||
(error && error != -ENOENT && error != -EINVAL)) {
acp->ac_ubleft = 0;
ASSERT(error);
break;
}
if (fmterror == BULKSTAT_RV_NOTHING || error) {
error = 0;
continue;
}
*ubufp += ubused;
acp->ac_ubleft -= ubused;
acp->ac_ubelem++;
}
*last_agino = agino - 1;
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
xfs_agino_t agino;
xfs_agnumber_t agno;
xfs_btree_cur_t *cur;
xfs_inobt_rec_incore_t *irbuf;
int nirbuf;
int ubcount;
struct xfs_bulkstat_agichunk ac;
int error = 0;
agno = XFS_INO_TO_AGNO(mp, *lastinop);
agino = XFS_INO_TO_AGINO(mp, *lastinop);
if (agno >= mp->m_sb.sb_agcount ||
*lastinop != XFS_AGINO_TO_INO(mp, agno, agino)) {
*done = 1;
*ubcountp = 0;
return 0;
}
ubcount = *ubcountp;
ac.ac_ubuffer = &ubuffer;
ac.ac_ubleft = ubcount * statstruct_size; ;
ac.ac_ubelem = 0;
*ubcountp = 0;
*done = 0;
irbuf = kmem_zalloc_large(PAGE_SIZE * 4, KM_SLEEP);
if (!irbuf)
return -ENOMEM;
nirbuf = (PAGE_SIZE * 4) / sizeof(*irbuf);
while (agno < mp->m_sb.sb_agcount) {
struct xfs_inobt_rec_incore *irbp = irbuf;
struct xfs_inobt_rec_incore *irbufend = irbuf + nirbuf;
bool end_of_ag = false;
int icount = 0;
int stat;
error = xfs_ialloc_read_agi(mp, NULL, agno, &agbp);
if (error)
break;
cur = xfs_inobt_init_cursor(mp, NULL, agbp, agno,
XFS_BTNUM_INO);
if (agino > 0) {
struct xfs_inobt_rec_incore r;
error = xfs_bulkstat_grab_ichunk(cur, agino, &icount, &r);
if (error)
goto del_cursor;
if (icount) {
irbp->ir_startino = r.ir_startino;
irbp->ir_holemask = r.ir_holemask;
irbp->ir_count = r.ir_count;
irbp->ir_freecount = r.ir_freecount;
irbp->ir_free = r.ir_free;
irbp++;
}
error = xfs_btree_increment(cur, 0, &stat);
} else {
error = xfs_inobt_lookup(cur, 0, XFS_LOOKUP_GE, &stat);
}
if (error || stat == 0) {
end_of_ag = true;
goto del_cursor;
}
while (irbp < irbufend && icount < ubcount) {
struct xfs_inobt_rec_incore r;
error = xfs_inobt_get_rec(cur, &r, &stat);
if (error || stat == 0) {
end_of_ag = true;
goto del_cursor;
}
if (r.ir_freecount < r.ir_count) {
xfs_bulkstat_ichunk_ra(mp, agno, &r);
irbp->ir_startino = r.ir_startino;
irbp->ir_holemask = r.ir_holemask;
irbp->ir_count = r.ir_count;
irbp->ir_freecount = r.ir_freecount;
irbp->ir_free = r.ir_free;
irbp++;
icount += r.ir_count - r.ir_freecount;
}
error = xfs_btree_increment(cur, 0, &stat);
if (error || stat == 0) {
end_of_ag = true;
goto del_cursor;
}
cond_resched();
}
del_cursor:
xfs_btree_del_cursor(cur, error ?
XFS_BTREE_ERROR : XFS_BTREE_NOERROR);
xfs_buf_relse(agbp);
if (error)
break;
irbufend = irbp;
for (irbp = irbuf;
irbp < irbufend && ac.ac_ubleft >= statstruct_size;
irbp++) {
error = xfs_bulkstat_ag_ichunk(mp, agno, irbp,
formatter, statstruct_size, &ac,
&agino);
if (error)
break;
cond_resched();
}
if (ac.ac_ubleft < statstruct_size || error)
break;
if (end_of_ag) {
agno++;
agino = 0;
}
}
kmem_free(irbuf);
*ubcountp = ac.ac_ubelem;
if (ac.ac_ubelem)
error = 0;
*lastinop = XFS_AGINO_TO_INO(mp, agno, agino);
if (agno >= mp->m_sb.sb_agcount)
*done = 1;
return error;
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
buffer = kmem_zalloc(bcount * sizeof(*buffer), KM_SLEEP);
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
buffer[bufidx].xi_alloccount = r.ir_count - r.ir_freecount;
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
agno++;
} while (agno < mp->m_sb.sb_agcount);
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
