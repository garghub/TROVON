int
xfs_attr3_rmt_blocks(
struct xfs_mount *mp,
int attrlen)
{
if (xfs_sb_version_hascrc(&mp->m_sb)) {
int buflen = XFS_ATTR3_RMT_BUF_SPACE(mp, mp->m_sb.sb_blocksize);
return (attrlen + buflen - 1) / buflen;
}
return XFS_B_TO_FSB(mp, attrlen);
}
static bool
xfs_attr3_rmt_hdr_ok(
void *ptr,
xfs_ino_t ino,
uint32_t offset,
uint32_t size,
xfs_daddr_t bno)
{
struct xfs_attr3_rmt_hdr *rmt = ptr;
if (bno != be64_to_cpu(rmt->rm_blkno))
return false;
if (offset != be32_to_cpu(rmt->rm_offset))
return false;
if (size != be32_to_cpu(rmt->rm_bytes))
return false;
if (ino != be64_to_cpu(rmt->rm_owner))
return false;
return true;
}
static bool
xfs_attr3_rmt_verify(
struct xfs_mount *mp,
void *ptr,
int fsbsize,
xfs_daddr_t bno)
{
struct xfs_attr3_rmt_hdr *rmt = ptr;
if (!xfs_sb_version_hascrc(&mp->m_sb))
return false;
if (rmt->rm_magic != cpu_to_be32(XFS_ATTR3_RMT_MAGIC))
return false;
if (!uuid_equal(&rmt->rm_uuid, &mp->m_sb.sb_meta_uuid))
return false;
if (be64_to_cpu(rmt->rm_blkno) != bno)
return false;
if (be32_to_cpu(rmt->rm_bytes) > fsbsize - sizeof(*rmt))
return false;
if (be32_to_cpu(rmt->rm_offset) +
be32_to_cpu(rmt->rm_bytes) > XFS_XATTR_SIZE_MAX)
return false;
if (rmt->rm_owner == 0)
return false;
return true;
}
static void
xfs_attr3_rmt_read_verify(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
char *ptr;
int len;
xfs_daddr_t bno;
int blksize = mp->m_attr_geo->blksize;
if (!xfs_sb_version_hascrc(&mp->m_sb))
return;
ptr = bp->b_addr;
bno = bp->b_bn;
len = BBTOB(bp->b_length);
ASSERT(len >= blksize);
while (len > 0) {
if (!xfs_verify_cksum(ptr, blksize, XFS_ATTR3_RMT_CRC_OFF)) {
xfs_buf_ioerror(bp, -EFSBADCRC);
break;
}
if (!xfs_attr3_rmt_verify(mp, ptr, blksize, bno)) {
xfs_buf_ioerror(bp, -EFSCORRUPTED);
break;
}
len -= blksize;
ptr += blksize;
bno += BTOBB(blksize);
}
if (bp->b_error)
xfs_verifier_error(bp);
else
ASSERT(len == 0);
}
static void
xfs_attr3_rmt_write_verify(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
int blksize = mp->m_attr_geo->blksize;
char *ptr;
int len;
xfs_daddr_t bno;
if (!xfs_sb_version_hascrc(&mp->m_sb))
return;
ptr = bp->b_addr;
bno = bp->b_bn;
len = BBTOB(bp->b_length);
ASSERT(len >= blksize);
while (len > 0) {
struct xfs_attr3_rmt_hdr *rmt = (struct xfs_attr3_rmt_hdr *)ptr;
if (!xfs_attr3_rmt_verify(mp, ptr, blksize, bno)) {
xfs_buf_ioerror(bp, -EFSCORRUPTED);
xfs_verifier_error(bp);
return;
}
if (rmt->rm_lsn != cpu_to_be64(NULLCOMMITLSN)) {
xfs_buf_ioerror(bp, -EFSCORRUPTED);
xfs_verifier_error(bp);
return;
}
xfs_update_cksum(ptr, blksize, XFS_ATTR3_RMT_CRC_OFF);
len -= blksize;
ptr += blksize;
bno += BTOBB(blksize);
}
ASSERT(len == 0);
}
STATIC int
xfs_attr3_rmt_hdr_set(
struct xfs_mount *mp,
void *ptr,
xfs_ino_t ino,
uint32_t offset,
uint32_t size,
xfs_daddr_t bno)
{
struct xfs_attr3_rmt_hdr *rmt = ptr;
if (!xfs_sb_version_hascrc(&mp->m_sb))
return 0;
rmt->rm_magic = cpu_to_be32(XFS_ATTR3_RMT_MAGIC);
rmt->rm_offset = cpu_to_be32(offset);
rmt->rm_bytes = cpu_to_be32(size);
uuid_copy(&rmt->rm_uuid, &mp->m_sb.sb_meta_uuid);
rmt->rm_owner = cpu_to_be64(ino);
rmt->rm_blkno = cpu_to_be64(bno);
rmt->rm_lsn = cpu_to_be64(NULLCOMMITLSN);
return sizeof(struct xfs_attr3_rmt_hdr);
}
STATIC int
xfs_attr_rmtval_copyout(
struct xfs_mount *mp,
struct xfs_buf *bp,
xfs_ino_t ino,
int *offset,
int *valuelen,
__uint8_t **dst)
{
char *src = bp->b_addr;
xfs_daddr_t bno = bp->b_bn;
int len = BBTOB(bp->b_length);
int blksize = mp->m_attr_geo->blksize;
ASSERT(len >= blksize);
while (len > 0 && *valuelen > 0) {
int hdr_size = 0;
int byte_cnt = XFS_ATTR3_RMT_BUF_SPACE(mp, blksize);
byte_cnt = min(*valuelen, byte_cnt);
if (xfs_sb_version_hascrc(&mp->m_sb)) {
if (!xfs_attr3_rmt_hdr_ok(src, ino, *offset,
byte_cnt, bno)) {
xfs_alert(mp,
"remote attribute header mismatch bno/off/len/owner (0x%llx/0x%x/Ox%x/0x%llx)",
bno, *offset, byte_cnt, ino);
return -EFSCORRUPTED;
}
hdr_size = sizeof(struct xfs_attr3_rmt_hdr);
}
memcpy(*dst, src + hdr_size, byte_cnt);
len -= blksize;
src += blksize;
bno += BTOBB(blksize);
*valuelen -= byte_cnt;
*dst += byte_cnt;
*offset += byte_cnt;
}
return 0;
}
STATIC void
xfs_attr_rmtval_copyin(
struct xfs_mount *mp,
struct xfs_buf *bp,
xfs_ino_t ino,
int *offset,
int *valuelen,
__uint8_t **src)
{
char *dst = bp->b_addr;
xfs_daddr_t bno = bp->b_bn;
int len = BBTOB(bp->b_length);
int blksize = mp->m_attr_geo->blksize;
ASSERT(len >= blksize);
while (len > 0 && *valuelen > 0) {
int hdr_size;
int byte_cnt = XFS_ATTR3_RMT_BUF_SPACE(mp, blksize);
byte_cnt = min(*valuelen, byte_cnt);
hdr_size = xfs_attr3_rmt_hdr_set(mp, dst, ino, *offset,
byte_cnt, bno);
memcpy(dst + hdr_size, *src, byte_cnt);
if (byte_cnt + hdr_size < blksize) {
ASSERT(*valuelen - byte_cnt == 0);
ASSERT(len == blksize);
memset(dst + hdr_size + byte_cnt, 0,
blksize - hdr_size - byte_cnt);
}
len -= blksize;
dst += blksize;
bno += BTOBB(blksize);
*valuelen -= byte_cnt;
*src += byte_cnt;
*offset += byte_cnt;
}
}
int
xfs_attr_rmtval_get(
struct xfs_da_args *args)
{
struct xfs_bmbt_irec map[ATTR_RMTVALUE_MAPSIZE];
struct xfs_mount *mp = args->dp->i_mount;
struct xfs_buf *bp;
xfs_dablk_t lblkno = args->rmtblkno;
__uint8_t *dst = args->value;
int valuelen;
int nmap;
int error;
int blkcnt = args->rmtblkcnt;
int i;
int offset = 0;
trace_xfs_attr_rmtval_get(args);
ASSERT(!(args->flags & ATTR_KERNOVAL));
ASSERT(args->rmtvaluelen == args->valuelen);
valuelen = args->rmtvaluelen;
while (valuelen > 0) {
nmap = ATTR_RMTVALUE_MAPSIZE;
error = xfs_bmapi_read(args->dp, (xfs_fileoff_t)lblkno,
blkcnt, map, &nmap,
XFS_BMAPI_ATTRFORK);
if (error)
return error;
ASSERT(nmap >= 1);
for (i = 0; (i < nmap) && (valuelen > 0); i++) {
xfs_daddr_t dblkno;
int dblkcnt;
ASSERT((map[i].br_startblock != DELAYSTARTBLOCK) &&
(map[i].br_startblock != HOLESTARTBLOCK));
dblkno = XFS_FSB_TO_DADDR(mp, map[i].br_startblock);
dblkcnt = XFS_FSB_TO_BB(mp, map[i].br_blockcount);
error = xfs_trans_read_buf(mp, NULL, mp->m_ddev_targp,
dblkno, dblkcnt, 0, &bp,
&xfs_attr3_rmt_buf_ops);
if (error)
return error;
error = xfs_attr_rmtval_copyout(mp, bp, args->dp->i_ino,
&offset, &valuelen,
&dst);
xfs_buf_relse(bp);
if (error)
return error;
lblkno += map[i].br_blockcount;
blkcnt -= map[i].br_blockcount;
}
}
ASSERT(valuelen == 0);
return 0;
}
int
xfs_attr_rmtval_set(
struct xfs_da_args *args)
{
struct xfs_inode *dp = args->dp;
struct xfs_mount *mp = dp->i_mount;
struct xfs_bmbt_irec map;
xfs_dablk_t lblkno;
xfs_fileoff_t lfileoff = 0;
__uint8_t *src = args->value;
int blkcnt;
int valuelen;
int nmap;
int error;
int offset = 0;
trace_xfs_attr_rmtval_set(args);
blkcnt = xfs_attr3_rmt_blocks(mp, args->rmtvaluelen);
error = xfs_bmap_first_unused(args->trans, args->dp, blkcnt, &lfileoff,
XFS_ATTR_FORK);
if (error)
return error;
args->rmtblkno = lblkno = (xfs_dablk_t)lfileoff;
args->rmtblkcnt = blkcnt;
while (blkcnt > 0) {
int committed;
xfs_bmap_init(args->flist, args->firstblock);
nmap = 1;
error = xfs_bmapi_write(args->trans, dp, (xfs_fileoff_t)lblkno,
blkcnt, XFS_BMAPI_ATTRFORK, args->firstblock,
args->total, &map, &nmap, args->flist);
if (!error) {
error = xfs_bmap_finish(&args->trans, args->flist,
&committed);
}
if (error) {
ASSERT(committed);
args->trans = NULL;
xfs_bmap_cancel(args->flist);
return error;
}
if (committed)
xfs_trans_ijoin(args->trans, dp, 0);
ASSERT(nmap == 1);
ASSERT((map.br_startblock != DELAYSTARTBLOCK) &&
(map.br_startblock != HOLESTARTBLOCK));
lblkno += map.br_blockcount;
blkcnt -= map.br_blockcount;
error = xfs_trans_roll(&args->trans, dp);
if (error)
return error;
}
lblkno = args->rmtblkno;
blkcnt = args->rmtblkcnt;
valuelen = args->rmtvaluelen;
while (valuelen > 0) {
struct xfs_buf *bp;
xfs_daddr_t dblkno;
int dblkcnt;
ASSERT(blkcnt > 0);
xfs_bmap_init(args->flist, args->firstblock);
nmap = 1;
error = xfs_bmapi_read(dp, (xfs_fileoff_t)lblkno,
blkcnt, &map, &nmap,
XFS_BMAPI_ATTRFORK);
if (error)
return error;
ASSERT(nmap == 1);
ASSERT((map.br_startblock != DELAYSTARTBLOCK) &&
(map.br_startblock != HOLESTARTBLOCK));
dblkno = XFS_FSB_TO_DADDR(mp, map.br_startblock),
dblkcnt = XFS_FSB_TO_BB(mp, map.br_blockcount);
bp = xfs_buf_get(mp->m_ddev_targp, dblkno, dblkcnt, 0);
if (!bp)
return -ENOMEM;
bp->b_ops = &xfs_attr3_rmt_buf_ops;
xfs_attr_rmtval_copyin(mp, bp, args->dp->i_ino, &offset,
&valuelen, &src);
error = xfs_bwrite(bp);
xfs_buf_relse(bp);
if (error)
return error;
lblkno += map.br_blockcount;
blkcnt -= map.br_blockcount;
}
ASSERT(valuelen == 0);
return 0;
}
int
xfs_attr_rmtval_remove(
struct xfs_da_args *args)
{
struct xfs_mount *mp = args->dp->i_mount;
xfs_dablk_t lblkno;
int blkcnt;
int error;
int done;
trace_xfs_attr_rmtval_remove(args);
lblkno = args->rmtblkno;
blkcnt = args->rmtblkcnt;
while (blkcnt > 0) {
struct xfs_bmbt_irec map;
struct xfs_buf *bp;
xfs_daddr_t dblkno;
int dblkcnt;
int nmap;
nmap = 1;
error = xfs_bmapi_read(args->dp, (xfs_fileoff_t)lblkno,
blkcnt, &map, &nmap, XFS_BMAPI_ATTRFORK);
if (error)
return error;
ASSERT(nmap == 1);
ASSERT((map.br_startblock != DELAYSTARTBLOCK) &&
(map.br_startblock != HOLESTARTBLOCK));
dblkno = XFS_FSB_TO_DADDR(mp, map.br_startblock),
dblkcnt = XFS_FSB_TO_BB(mp, map.br_blockcount);
bp = xfs_incore(mp->m_ddev_targp, dblkno, dblkcnt, XBF_TRYLOCK);
if (bp) {
xfs_buf_stale(bp);
xfs_buf_relse(bp);
bp = NULL;
}
lblkno += map.br_blockcount;
blkcnt -= map.br_blockcount;
}
lblkno = args->rmtblkno;
blkcnt = args->rmtblkcnt;
done = 0;
while (!done) {
int committed;
xfs_bmap_init(args->flist, args->firstblock);
error = xfs_bunmapi(args->trans, args->dp, lblkno, blkcnt,
XFS_BMAPI_ATTRFORK, 1, args->firstblock,
args->flist, &done);
if (!error) {
error = xfs_bmap_finish(&args->trans, args->flist,
&committed);
}
if (error) {
ASSERT(committed);
args->trans = NULL;
xfs_bmap_cancel(args->flist);
return error;
}
if (committed)
xfs_trans_ijoin(args->trans, args->dp, 0);
error = xfs_trans_roll(&args->trans, args->dp);
if (error)
return error;
}
return 0;
}
