int
xfs_rtbuf_get(
xfs_mount_t *mp,
xfs_trans_t *tp,
xfs_rtblock_t block,
int issum,
xfs_buf_t **bpp)
{
xfs_buf_t *bp;
xfs_inode_t *ip;
xfs_bmbt_irec_t map;
int nmap = 1;
int error;
ip = issum ? mp->m_rsumip : mp->m_rbmip;
error = xfs_bmapi_read(ip, block, 1, &map, &nmap, XFS_DATA_FORK);
if (error)
return error;
ASSERT(map.br_startblock != NULLFSBLOCK);
error = xfs_trans_read_buf(mp, tp, mp->m_ddev_targp,
XFS_FSB_TO_DADDR(mp, map.br_startblock),
mp->m_bsize, 0, &bp, NULL);
if (error)
return error;
*bpp = bp;
return 0;
}
int
xfs_rtfind_back(
xfs_mount_t *mp,
xfs_trans_t *tp,
xfs_rtblock_t start,
xfs_rtblock_t limit,
xfs_rtblock_t *rtblock)
{
xfs_rtword_t *b;
int bit;
xfs_rtblock_t block;
xfs_buf_t *bp;
xfs_rtword_t *bufp;
int error;
xfs_rtblock_t firstbit;
xfs_rtblock_t i;
xfs_rtblock_t len;
xfs_rtword_t mask;
xfs_rtword_t want;
xfs_rtword_t wdiff;
int word;
block = XFS_BITTOBLOCK(mp, start);
error = xfs_rtbuf_get(mp, tp, block, 0, &bp);
if (error) {
return error;
}
bufp = bp->b_addr;
word = XFS_BITTOWORD(mp, start);
b = &bufp[word];
bit = (int)(start & (XFS_NBWORD - 1));
len = start - limit + 1;
want = (*b & ((xfs_rtword_t)1 << bit)) ? -1 : 0;
if (bit < XFS_NBWORD - 1) {
firstbit = XFS_RTMAX((xfs_srtblock_t)(bit - len + 1), 0);
mask = (((xfs_rtword_t)1 << (bit - firstbit + 1)) - 1) <<
firstbit;
if ((wdiff = (*b ^ want) & mask)) {
xfs_trans_brelse(tp, bp);
i = bit - XFS_RTHIBIT(wdiff);
*rtblock = start - i + 1;
return 0;
}
i = bit - firstbit + 1;
if (--word == -1 && i < len) {
xfs_trans_brelse(tp, bp);
error = xfs_rtbuf_get(mp, tp, --block, 0, &bp);
if (error) {
return error;
}
bufp = bp->b_addr;
word = XFS_BLOCKWMASK(mp);
b = &bufp[word];
} else {
b--;
}
} else {
i = 0;
}
while (len - i >= XFS_NBWORD) {
if ((wdiff = *b ^ want)) {
xfs_trans_brelse(tp, bp);
i += XFS_NBWORD - 1 - XFS_RTHIBIT(wdiff);
*rtblock = start - i + 1;
return 0;
}
i += XFS_NBWORD;
if (--word == -1 && i < len) {
xfs_trans_brelse(tp, bp);
error = xfs_rtbuf_get(mp, tp, --block, 0, &bp);
if (error) {
return error;
}
bufp = bp->b_addr;
word = XFS_BLOCKWMASK(mp);
b = &bufp[word];
} else {
b--;
}
}
if (len - i) {
firstbit = XFS_NBWORD - (len - i);
mask = (((xfs_rtword_t)1 << (len - i)) - 1) << firstbit;
if ((wdiff = (*b ^ want) & mask)) {
xfs_trans_brelse(tp, bp);
i += XFS_NBWORD - 1 - XFS_RTHIBIT(wdiff);
*rtblock = start - i + 1;
return 0;
} else
i = len;
}
xfs_trans_brelse(tp, bp);
*rtblock = start - i + 1;
return 0;
}
int
xfs_rtfind_forw(
xfs_mount_t *mp,
xfs_trans_t *tp,
xfs_rtblock_t start,
xfs_rtblock_t limit,
xfs_rtblock_t *rtblock)
{
xfs_rtword_t *b;
int bit;
xfs_rtblock_t block;
xfs_buf_t *bp;
xfs_rtword_t *bufp;
int error;
xfs_rtblock_t i;
xfs_rtblock_t lastbit;
xfs_rtblock_t len;
xfs_rtword_t mask;
xfs_rtword_t want;
xfs_rtword_t wdiff;
int word;
block = XFS_BITTOBLOCK(mp, start);
error = xfs_rtbuf_get(mp, tp, block, 0, &bp);
if (error) {
return error;
}
bufp = bp->b_addr;
word = XFS_BITTOWORD(mp, start);
b = &bufp[word];
bit = (int)(start & (XFS_NBWORD - 1));
len = limit - start + 1;
want = (*b & ((xfs_rtword_t)1 << bit)) ? -1 : 0;
if (bit) {
lastbit = XFS_RTMIN(bit + len, XFS_NBWORD);
mask = (((xfs_rtword_t)1 << (lastbit - bit)) - 1) << bit;
if ((wdiff = (*b ^ want) & mask)) {
xfs_trans_brelse(tp, bp);
i = XFS_RTLOBIT(wdiff) - bit;
*rtblock = start + i - 1;
return 0;
}
i = lastbit - bit;
if (++word == XFS_BLOCKWSIZE(mp) && i < len) {
xfs_trans_brelse(tp, bp);
error = xfs_rtbuf_get(mp, tp, ++block, 0, &bp);
if (error) {
return error;
}
b = bufp = bp->b_addr;
word = 0;
} else {
b++;
}
} else {
i = 0;
}
while (len - i >= XFS_NBWORD) {
if ((wdiff = *b ^ want)) {
xfs_trans_brelse(tp, bp);
i += XFS_RTLOBIT(wdiff);
*rtblock = start + i - 1;
return 0;
}
i += XFS_NBWORD;
if (++word == XFS_BLOCKWSIZE(mp) && i < len) {
xfs_trans_brelse(tp, bp);
error = xfs_rtbuf_get(mp, tp, ++block, 0, &bp);
if (error) {
return error;
}
b = bufp = bp->b_addr;
word = 0;
} else {
b++;
}
}
if ((lastbit = len - i)) {
mask = ((xfs_rtword_t)1 << lastbit) - 1;
if ((wdiff = (*b ^ want) & mask)) {
xfs_trans_brelse(tp, bp);
i += XFS_RTLOBIT(wdiff);
*rtblock = start + i - 1;
return 0;
} else
i = len;
}
xfs_trans_brelse(tp, bp);
*rtblock = start + i - 1;
return 0;
}
int
xfs_rtmodify_summary(
xfs_mount_t *mp,
xfs_trans_t *tp,
int log,
xfs_rtblock_t bbno,
int delta,
xfs_buf_t **rbpp,
xfs_fsblock_t *rsb)
{
xfs_buf_t *bp;
int error;
xfs_fsblock_t sb;
int so;
xfs_suminfo_t *sp;
so = XFS_SUMOFFS(mp, log, bbno);
sb = XFS_SUMOFFSTOBLOCK(mp, so);
if (rbpp && *rbpp && *rsb == sb)
bp = *rbpp;
else {
if (rbpp && *rbpp)
xfs_trans_brelse(tp, *rbpp);
error = xfs_rtbuf_get(mp, tp, sb, 1, &bp);
if (error) {
return error;
}
if (rbpp) {
*rbpp = bp;
*rsb = sb;
}
}
sp = XFS_SUMPTR(mp, bp, so);
*sp += delta;
xfs_trans_log_buf(tp, bp, (uint)((char *)sp - (char *)bp->b_addr),
(uint)((char *)sp - (char *)bp->b_addr + sizeof(*sp) - 1));
return 0;
}
int
xfs_rtmodify_range(
xfs_mount_t *mp,
xfs_trans_t *tp,
xfs_rtblock_t start,
xfs_extlen_t len,
int val)
{
xfs_rtword_t *b;
int bit;
xfs_rtblock_t block;
xfs_buf_t *bp;
xfs_rtword_t *bufp;
int error;
xfs_rtword_t *first;
int i;
int lastbit;
xfs_rtword_t mask;
int word;
block = XFS_BITTOBLOCK(mp, start);
error = xfs_rtbuf_get(mp, tp, block, 0, &bp);
if (error) {
return error;
}
bufp = bp->b_addr;
word = XFS_BITTOWORD(mp, start);
first = b = &bufp[word];
bit = (int)(start & (XFS_NBWORD - 1));
val = -val;
if (bit) {
lastbit = XFS_RTMIN(bit + len, XFS_NBWORD);
mask = (((xfs_rtword_t)1 << (lastbit - bit)) - 1) << bit;
if (val)
*b |= mask;
else
*b &= ~mask;
i = lastbit - bit;
if (++word == XFS_BLOCKWSIZE(mp) && i < len) {
xfs_trans_log_buf(tp, bp,
(uint)((char *)first - (char *)bufp),
(uint)((char *)b - (char *)bufp));
error = xfs_rtbuf_get(mp, tp, ++block, 0, &bp);
if (error) {
return error;
}
first = b = bufp = bp->b_addr;
word = 0;
} else {
b++;
}
} else {
i = 0;
}
while (len - i >= XFS_NBWORD) {
*b = val;
i += XFS_NBWORD;
if (++word == XFS_BLOCKWSIZE(mp) && i < len) {
xfs_trans_log_buf(tp, bp,
(uint)((char *)first - (char *)bufp),
(uint)((char *)b - (char *)bufp));
error = xfs_rtbuf_get(mp, tp, ++block, 0, &bp);
if (error) {
return error;
}
first = b = bufp = bp->b_addr;
word = 0;
} else {
b++;
}
}
if ((lastbit = len - i)) {
bit = 0;
mask = ((xfs_rtword_t)1 << lastbit) - 1;
if (val)
*b |= mask;
else
*b &= ~mask;
b++;
}
if (b > first)
xfs_trans_log_buf(tp, bp, (uint)((char *)first - (char *)bufp),
(uint)((char *)b - (char *)bufp - 1));
return 0;
}
int
xfs_rtfree_range(
xfs_mount_t *mp,
xfs_trans_t *tp,
xfs_rtblock_t start,
xfs_extlen_t len,
xfs_buf_t **rbpp,
xfs_fsblock_t *rsb)
{
xfs_rtblock_t end;
int error;
xfs_rtblock_t postblock;
xfs_rtblock_t preblock;
end = start + len - 1;
error = xfs_rtmodify_range(mp, tp, start, len, 1);
if (error) {
return error;
}
error = xfs_rtfind_back(mp, tp, start, 0, &preblock);
if (error) {
return error;
}
error = xfs_rtfind_forw(mp, tp, end, mp->m_sb.sb_rextents - 1,
&postblock);
if (error)
return error;
if (preblock < start) {
error = xfs_rtmodify_summary(mp, tp,
XFS_RTBLOCKLOG(start - preblock),
XFS_BITTOBLOCK(mp, preblock), -1, rbpp, rsb);
if (error) {
return error;
}
}
if (postblock > end) {
error = xfs_rtmodify_summary(mp, tp,
XFS_RTBLOCKLOG(postblock - end),
XFS_BITTOBLOCK(mp, end + 1), -1, rbpp, rsb);
if (error) {
return error;
}
}
error = xfs_rtmodify_summary(mp, tp,
XFS_RTBLOCKLOG(postblock + 1 - preblock),
XFS_BITTOBLOCK(mp, preblock), 1, rbpp, rsb);
return error;
}
int
xfs_rtcheck_range(
xfs_mount_t *mp,
xfs_trans_t *tp,
xfs_rtblock_t start,
xfs_extlen_t len,
int val,
xfs_rtblock_t *new,
int *stat)
{
xfs_rtword_t *b;
int bit;
xfs_rtblock_t block;
xfs_buf_t *bp;
xfs_rtword_t *bufp;
int error;
xfs_rtblock_t i;
xfs_rtblock_t lastbit;
xfs_rtword_t mask;
xfs_rtword_t wdiff;
int word;
block = XFS_BITTOBLOCK(mp, start);
error = xfs_rtbuf_get(mp, tp, block, 0, &bp);
if (error) {
return error;
}
bufp = bp->b_addr;
word = XFS_BITTOWORD(mp, start);
b = &bufp[word];
bit = (int)(start & (XFS_NBWORD - 1));
val = -val;
if (bit) {
lastbit = XFS_RTMIN(bit + len, XFS_NBWORD);
mask = (((xfs_rtword_t)1 << (lastbit - bit)) - 1) << bit;
if ((wdiff = (*b ^ val) & mask)) {
xfs_trans_brelse(tp, bp);
i = XFS_RTLOBIT(wdiff) - bit;
*new = start + i;
*stat = 0;
return 0;
}
i = lastbit - bit;
if (++word == XFS_BLOCKWSIZE(mp) && i < len) {
xfs_trans_brelse(tp, bp);
error = xfs_rtbuf_get(mp, tp, ++block, 0, &bp);
if (error) {
return error;
}
b = bufp = bp->b_addr;
word = 0;
} else {
b++;
}
} else {
i = 0;
}
while (len - i >= XFS_NBWORD) {
if ((wdiff = *b ^ val)) {
xfs_trans_brelse(tp, bp);
i += XFS_RTLOBIT(wdiff);
*new = start + i;
*stat = 0;
return 0;
}
i += XFS_NBWORD;
if (++word == XFS_BLOCKWSIZE(mp) && i < len) {
xfs_trans_brelse(tp, bp);
error = xfs_rtbuf_get(mp, tp, ++block, 0, &bp);
if (error) {
return error;
}
b = bufp = bp->b_addr;
word = 0;
} else {
b++;
}
}
if ((lastbit = len - i)) {
mask = ((xfs_rtword_t)1 << lastbit) - 1;
if ((wdiff = (*b ^ val) & mask)) {
xfs_trans_brelse(tp, bp);
i += XFS_RTLOBIT(wdiff);
*new = start + i;
*stat = 0;
return 0;
} else
i = len;
}
xfs_trans_brelse(tp, bp);
*new = start + i;
*stat = 1;
return 0;
}
STATIC int
xfs_rtcheck_alloc_range(
xfs_mount_t *mp,
xfs_trans_t *tp,
xfs_rtblock_t bno,
xfs_extlen_t len)
{
xfs_rtblock_t new;
int stat;
int error;
error = xfs_rtcheck_range(mp, tp, bno, len, 0, &new, &stat);
if (error)
return error;
ASSERT(stat);
return 0;
}
int
xfs_rtfree_extent(
xfs_trans_t *tp,
xfs_rtblock_t bno,
xfs_extlen_t len)
{
int error;
xfs_mount_t *mp;
xfs_fsblock_t sb;
xfs_buf_t *sumbp = NULL;
mp = tp->t_mountp;
ASSERT(mp->m_rbmip->i_itemp != NULL);
ASSERT(xfs_isilocked(mp->m_rbmip, XFS_ILOCK_EXCL));
error = xfs_rtcheck_alloc_range(mp, tp, bno, len);
if (error)
return error;
error = xfs_rtfree_range(mp, tp, bno, len, &sumbp, &sb);
if (error) {
return error;
}
xfs_trans_mod_sb(tp, XFS_TRANS_SB_FREXTENTS, (long)len);
if (tp->t_frextents_delta + mp->m_sb.sb_frextents ==
mp->m_sb.sb_rextents) {
if (!(mp->m_rbmip->i_d.di_flags & XFS_DIFLAG_NEWRTBM))
mp->m_rbmip->i_d.di_flags |= XFS_DIFLAG_NEWRTBM;
*(__uint64_t *)&mp->m_rbmip->i_d.di_atime = 0;
xfs_trans_log_inode(tp, mp->m_rbmip, XFS_ILOG_CORE);
}
return 0;
}
