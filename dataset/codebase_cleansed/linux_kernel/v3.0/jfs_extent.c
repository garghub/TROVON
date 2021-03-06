int
extAlloc(struct inode *ip, s64 xlen, s64 pno, xad_t * xp, bool abnr)
{
struct jfs_sb_info *sbi = JFS_SBI(ip->i_sb);
s64 nxlen, nxaddr, xoff, hint, xaddr = 0;
int rc;
int xflag;
txBeginAnon(ip->i_sb);
mutex_lock(&JFS_IP(ip)->commit_mutex);
if (xlen > MAXXLEN)
xlen = MAXXLEN;
xoff = pno << sbi->l2nbperpage;
if ((hint = addressXAD(xp))) {
nxlen = lengthXAD(xp);
if (offsetXAD(xp) + nxlen == xoff &&
abnr == ((xp->flag & XAD_NOTRECORDED) ? true : false))
xaddr = hint + nxlen;
hint += (nxlen - 1);
}
nxlen = xlen;
if ((rc = extBalloc(ip, hint ? hint : INOHINT(ip), &nxlen, &nxaddr))) {
mutex_unlock(&JFS_IP(ip)->commit_mutex);
return (rc);
}
rc = dquot_alloc_block(ip, nxlen);
if (rc) {
dbFree(ip, nxaddr, (s64) nxlen);
mutex_unlock(&JFS_IP(ip)->commit_mutex);
return rc;
}
xflag = abnr ? XAD_NOTRECORDED : 0;
if (xaddr && xaddr == nxaddr)
rc = xtExtend(0, ip, xoff, (int) nxlen, 0);
else
rc = xtInsert(0, ip, xflag, xoff, (int) nxlen, &nxaddr, 0);
if (rc) {
dbFree(ip, nxaddr, nxlen);
dquot_free_block(ip, nxlen);
mutex_unlock(&JFS_IP(ip)->commit_mutex);
return (rc);
}
XADaddress(xp, nxaddr);
XADlength(xp, nxlen);
XADoffset(xp, xoff);
xp->flag = xflag;
mark_inode_dirty(ip);
mutex_unlock(&JFS_IP(ip)->commit_mutex);
if (test_and_clear_cflag(COMMIT_Synclist,ip))
jfs_commit_inode(ip, 0);
return (0);
}
int extRealloc(struct inode *ip, s64 nxlen, xad_t * xp, bool abnr)
{
struct super_block *sb = ip->i_sb;
s64 xaddr, xlen, nxaddr, delta, xoff;
s64 ntail, nextend, ninsert;
int rc, nbperpage = JFS_SBI(sb)->nbperpage;
int xflag;
txBeginAnon(ip->i_sb);
mutex_lock(&JFS_IP(ip)->commit_mutex);
if (nxlen > MAXXLEN)
nxlen = MAXXLEN;
xaddr = addressXAD(xp);
xlen = lengthXAD(xp);
xoff = offsetXAD(xp);
if ((xp->flag & XAD_NOTRECORDED) && !abnr) {
xp->flag = 0;
if ((rc = xtUpdate(0, ip, xp)))
goto exit;
}
if ((rc = extBrealloc(ip, xaddr, xlen, &nxlen, &nxaddr)))
goto exit;
rc = dquot_alloc_block(ip, nxlen);
if (rc) {
dbFree(ip, nxaddr, (s64) nxlen);
mutex_unlock(&JFS_IP(ip)->commit_mutex);
return rc;
}
delta = nxlen - xlen;
if (abnr && (!(xp->flag & XAD_NOTRECORDED)) && (nxlen > nbperpage)) {
ntail = nbperpage;
nextend = ntail - xlen;
ninsert = nxlen - nbperpage;
xflag = XAD_NOTRECORDED;
} else {
ntail = nxlen;
nextend = delta;
ninsert = 0;
xflag = xp->flag;
}
if (xaddr == nxaddr) {
if ((rc = xtExtend(0, ip, xoff + xlen, (int) nextend, 0))) {
dbFree(ip, xaddr + xlen, delta);
dquot_free_block(ip, nxlen);
goto exit;
}
} else {
if ((rc = xtTailgate(0, ip, xoff, (int) ntail, nxaddr, 0))) {
dbFree(ip, nxaddr, nxlen);
dquot_free_block(ip, nxlen);
goto exit;
}
}
if (ninsert) {
xaddr = nxaddr + ntail;
if (xtInsert (0, ip, xflag, xoff + ntail, (int) ninsert,
&xaddr, 0)) {
dbFree(ip, xaddr, (s64) ninsert);
delta = nextend;
nxlen = ntail;
xflag = 0;
}
}
XADaddress(xp, nxaddr);
XADlength(xp, nxlen);
XADoffset(xp, xoff);
xp->flag = xflag;
mark_inode_dirty(ip);
exit:
mutex_unlock(&JFS_IP(ip)->commit_mutex);
return (rc);
}
int extHint(struct inode *ip, s64 offset, xad_t * xp)
{
struct super_block *sb = ip->i_sb;
int nbperpage = JFS_SBI(sb)->nbperpage;
s64 prev;
int rc = 0;
s64 xaddr;
int xlen;
int xflag;
XADaddress(xp, 0);
prev = ((offset & ~POFFSET) >> JFS_SBI(sb)->l2bsize) - nbperpage;
if (prev < 0)
goto out;
rc = xtLookup(ip, prev, nbperpage, &xflag, &xaddr, &xlen, 0);
if ((rc == 0) && xlen) {
if (xlen != nbperpage) {
jfs_error(ip->i_sb, "extHint: corrupt xtree");
rc = -EIO;
}
XADaddress(xp, xaddr);
XADlength(xp, xlen);
XADoffset(xp, prev);
xp->flag = xflag & XAD_NOTRECORDED;
} else
rc = 0;
out:
return (rc);
}
int extRecord(struct inode *ip, xad_t * xp)
{
int rc;
txBeginAnon(ip->i_sb);
mutex_lock(&JFS_IP(ip)->commit_mutex);
rc = xtUpdate(0, ip, xp);
mutex_unlock(&JFS_IP(ip)->commit_mutex);
return rc;
}
int extFill(struct inode *ip, xad_t * xp)
{
int rc, nbperpage = JFS_SBI(ip->i_sb)->nbperpage;
s64 blkno = offsetXAD(xp) >> ip->i_blkbits;
XADaddress(xp, 0);
if ((rc = extAlloc(ip, nbperpage, blkno, xp, false)))
return (rc);
assert(lengthPXD(xp) == nbperpage);
return (0);
}
static int
extBalloc(struct inode *ip, s64 hint, s64 * nblocks, s64 * blkno)
{
struct jfs_inode_info *ji = JFS_IP(ip);
struct jfs_sb_info *sbi = JFS_SBI(ip->i_sb);
s64 nb, nblks, daddr, max;
int rc, nbperpage = sbi->nbperpage;
struct bmap *bmp = sbi->bmap;
int ag;
max = (s64) 1 << bmp->db_maxfreebud;
if (*nblocks >= max && *nblocks > nbperpage)
nb = nblks = (max > nbperpage) ? max : nbperpage;
else
nb = nblks = *nblocks;
while ((rc = dbAlloc(ip, hint, nb, &daddr)) != 0) {
if (rc != -ENOSPC)
return (rc);
nb = min(nblks, extRoundDown(nb));
if (nb < nbperpage)
return (rc);
}
*nblocks = nb;
*blkno = daddr;
if (S_ISREG(ip->i_mode) && (ji->fileset == FILESYSTEM_I)) {
ag = BLKTOAG(daddr, sbi);
spin_lock_irq(&ji->ag_lock);
if (ji->active_ag == -1) {
atomic_inc(&bmp->db_active[ag]);
ji->active_ag = ag;
} else if (ji->active_ag != ag) {
atomic_dec(&bmp->db_active[ji->active_ag]);
atomic_inc(&bmp->db_active[ag]);
ji->active_ag = ag;
}
spin_unlock_irq(&ji->ag_lock);
}
return (0);
}
static int
extBrealloc(struct inode *ip,
s64 blkno, s64 nblks, s64 * newnblks, s64 * newblkno)
{
int rc;
if ((rc = dbExtend(ip, blkno, nblks, *newnblks - nblks)) == 0) {
*newblkno = blkno;
return (0);
} else {
if (rc != -ENOSPC)
return (rc);
}
return (extBalloc(ip, blkno, newnblks, newblkno));
}
static s64 extRoundDown(s64 nb)
{
int i;
u64 m, k;
for (i = 0, m = (u64) 1 << 63; i < 64; i++, m >>= 1) {
if (m & nb)
break;
}
i = 63 - i;
k = (u64) 1 << i;
k = ((k - 1) & nb) ? k : k >> 1;
return (k);
}
