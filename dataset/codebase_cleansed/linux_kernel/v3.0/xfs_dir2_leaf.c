int
xfs_dir2_block_to_leaf(
xfs_da_args_t *args,
xfs_dabuf_t *dbp)
{
__be16 *bestsp;
xfs_dablk_t blkno;
xfs_dir2_block_t *block;
xfs_dir2_leaf_entry_t *blp;
xfs_dir2_block_tail_t *btp;
xfs_inode_t *dp;
int error;
xfs_dabuf_t *lbp;
xfs_dir2_db_t ldb;
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_tail_t *ltp;
xfs_mount_t *mp;
int needlog;
int needscan;
xfs_trans_t *tp;
trace_xfs_dir2_block_to_leaf(args);
dp = args->dp;
mp = dp->i_mount;
tp = args->trans;
if ((error = xfs_da_grow_inode(args, &blkno))) {
return error;
}
ldb = xfs_dir2_da_to_db(mp, blkno);
ASSERT(ldb == XFS_DIR2_LEAF_FIRSTDB(mp));
if ((error = xfs_dir2_leaf_init(args, ldb, &lbp, XFS_DIR2_LEAF1_MAGIC))) {
return error;
}
ASSERT(lbp != NULL);
leaf = lbp->data;
block = dbp->data;
xfs_dir2_data_check(dp, dbp);
btp = xfs_dir2_block_tail_p(mp, block);
blp = xfs_dir2_block_leaf_p(btp);
leaf->hdr.count = cpu_to_be16(be32_to_cpu(btp->count));
leaf->hdr.stale = cpu_to_be16(be32_to_cpu(btp->stale));
memcpy(leaf->ents, blp, be32_to_cpu(btp->count) * sizeof(xfs_dir2_leaf_entry_t));
xfs_dir2_leaf_log_ents(tp, lbp, 0, be16_to_cpu(leaf->hdr.count) - 1);
needscan = 0;
needlog = 1;
xfs_dir2_data_make_free(tp, dbp,
(xfs_dir2_data_aoff_t)((char *)blp - (char *)block),
(xfs_dir2_data_aoff_t)((char *)block + mp->m_dirblksize -
(char *)blp),
&needlog, &needscan);
block->hdr.magic = cpu_to_be32(XFS_DIR2_DATA_MAGIC);
if (needscan)
xfs_dir2_data_freescan(mp, (xfs_dir2_data_t *)block, &needlog);
ltp = xfs_dir2_leaf_tail_p(mp, leaf);
ltp->bestcount = cpu_to_be32(1);
bestsp = xfs_dir2_leaf_bests_p(ltp);
bestsp[0] = block->hdr.bestfree[0].length;
if (needlog)
xfs_dir2_data_log_header(tp, dbp);
xfs_dir2_leaf_check(dp, lbp);
xfs_dir2_data_check(dp, dbp);
xfs_dir2_leaf_log_bests(tp, lbp, 0, 0);
xfs_da_buf_done(lbp);
return 0;
}
int
xfs_dir2_leaf_addname(
xfs_da_args_t *args)
{
__be16 *bestsp;
int compact;
xfs_dir2_data_t *data;
xfs_dabuf_t *dbp;
xfs_dir2_data_entry_t *dep;
xfs_inode_t *dp;
xfs_dir2_data_unused_t *dup;
int error;
int grown;
int highstale;
int i;
int index;
xfs_dabuf_t *lbp;
xfs_dir2_leaf_t *leaf;
int length;
xfs_dir2_leaf_entry_t *lep;
int lfloglow;
int lfloghigh;
int lowstale;
xfs_dir2_leaf_tail_t *ltp;
xfs_mount_t *mp;
int needbytes;
int needlog;
int needscan;
__be16 *tagp;
xfs_trans_t *tp;
xfs_dir2_db_t use_block;
trace_xfs_dir2_leaf_addname(args);
dp = args->dp;
tp = args->trans;
mp = dp->i_mount;
error = xfs_da_read_buf(tp, dp, mp->m_dirleafblk, -1, &lbp,
XFS_DATA_FORK);
if (error) {
return error;
}
ASSERT(lbp != NULL);
index = xfs_dir2_leaf_search_hash(args, lbp);
leaf = lbp->data;
ltp = xfs_dir2_leaf_tail_p(mp, leaf);
bestsp = xfs_dir2_leaf_bests_p(ltp);
length = xfs_dir2_data_entsize(args->namelen);
for (use_block = -1, lep = &leaf->ents[index];
index < be16_to_cpu(leaf->hdr.count) && be32_to_cpu(lep->hashval) == args->hashval;
index++, lep++) {
if (be32_to_cpu(lep->address) == XFS_DIR2_NULL_DATAPTR)
continue;
i = xfs_dir2_dataptr_to_db(mp, be32_to_cpu(lep->address));
ASSERT(i < be32_to_cpu(ltp->bestcount));
ASSERT(be16_to_cpu(bestsp[i]) != NULLDATAOFF);
if (be16_to_cpu(bestsp[i]) >= length) {
use_block = i;
break;
}
}
if (use_block == -1) {
for (i = 0; i < be32_to_cpu(ltp->bestcount); i++) {
if (be16_to_cpu(bestsp[i]) == NULLDATAOFF && use_block == -1)
use_block = i;
else if (be16_to_cpu(bestsp[i]) >= length) {
use_block = i;
break;
}
}
}
needbytes =
(leaf->hdr.stale ? 0 : (uint)sizeof(leaf->ents[0])) +
(use_block != -1 ? 0 : (uint)sizeof(leaf->bests[0]));
if (use_block != -1 && be16_to_cpu(bestsp[use_block]) == NULLDATAOFF)
use_block = -1;
if ((char *)bestsp - (char *)&leaf->ents[be16_to_cpu(leaf->hdr.count)] <
needbytes && be16_to_cpu(leaf->hdr.stale) > 1) {
compact = 1;
}
else if ((char *)bestsp - (char *)&leaf->ents[be16_to_cpu(
leaf->hdr.count)] < needbytes) {
if ((args->op_flags & XFS_DA_OP_JUSTCHECK) ||
args->total == 0) {
xfs_da_brelse(tp, lbp);
return XFS_ERROR(ENOSPC);
}
error = xfs_dir2_leaf_to_node(args, lbp);
xfs_da_buf_done(lbp);
if (error)
return error;
return xfs_dir2_node_addname(args);
}
else
compact = 0;
if (args->op_flags & XFS_DA_OP_JUSTCHECK) {
xfs_da_brelse(tp, lbp);
return use_block == -1 ? XFS_ERROR(ENOSPC) : 0;
}
if (args->total == 0 && use_block == -1) {
xfs_da_brelse(tp, lbp);
return XFS_ERROR(ENOSPC);
}
if (compact) {
xfs_dir2_leaf_compact_x1(lbp, &index, &lowstale, &highstale,
&lfloglow, &lfloghigh);
}
else if (be16_to_cpu(leaf->hdr.stale)) {
lfloglow = be16_to_cpu(leaf->hdr.count);
lfloghigh = -1;
}
if (use_block == -1) {
if ((error = xfs_dir2_grow_inode(args, XFS_DIR2_DATA_SPACE,
&use_block))) {
xfs_da_brelse(tp, lbp);
return error;
}
if ((error = xfs_dir2_data_init(args, use_block, &dbp))) {
xfs_da_brelse(tp, lbp);
return error;
}
if (use_block >= be32_to_cpu(ltp->bestcount)) {
bestsp--;
memmove(&bestsp[0], &bestsp[1],
be32_to_cpu(ltp->bestcount) * sizeof(bestsp[0]));
be32_add_cpu(&ltp->bestcount, 1);
xfs_dir2_leaf_log_tail(tp, lbp);
xfs_dir2_leaf_log_bests(tp, lbp, 0, be32_to_cpu(ltp->bestcount) - 1);
}
else
xfs_dir2_leaf_log_bests(tp, lbp, use_block, use_block);
data = dbp->data;
bestsp[use_block] = data->hdr.bestfree[0].length;
grown = 1;
}
else {
if ((error =
xfs_da_read_buf(tp, dp, xfs_dir2_db_to_da(mp, use_block),
-1, &dbp, XFS_DATA_FORK))) {
xfs_da_brelse(tp, lbp);
return error;
}
data = dbp->data;
grown = 0;
}
xfs_dir2_data_check(dp, dbp);
dup = (xfs_dir2_data_unused_t *)
((char *)data + be16_to_cpu(data->hdr.bestfree[0].offset));
ASSERT(be16_to_cpu(dup->length) >= length);
needscan = needlog = 0;
xfs_dir2_data_use_free(tp, dbp, dup,
(xfs_dir2_data_aoff_t)((char *)dup - (char *)data), length,
&needlog, &needscan);
dep = (xfs_dir2_data_entry_t *)dup;
dep->inumber = cpu_to_be64(args->inumber);
dep->namelen = args->namelen;
memcpy(dep->name, args->name, dep->namelen);
tagp = xfs_dir2_data_entry_tag_p(dep);
*tagp = cpu_to_be16((char *)dep - (char *)data);
if (needscan)
xfs_dir2_data_freescan(mp, data, &needlog);
if (needlog)
xfs_dir2_data_log_header(tp, dbp);
xfs_dir2_data_log_entry(tp, dbp, dep);
if (be16_to_cpu(bestsp[use_block]) != be16_to_cpu(data->hdr.bestfree[0].length)) {
bestsp[use_block] = data->hdr.bestfree[0].length;
if (!grown)
xfs_dir2_leaf_log_bests(tp, lbp, use_block, use_block);
}
if (!leaf->hdr.stale) {
if (index < be16_to_cpu(leaf->hdr.count))
memmove(lep + 1, lep,
(be16_to_cpu(leaf->hdr.count) - index) * sizeof(*lep));
lfloglow = index;
lfloghigh = be16_to_cpu(leaf->hdr.count);
be16_add_cpu(&leaf->hdr.count, 1);
}
else {
if (compact == 0) {
for (lowstale = index - 1;
lowstale >= 0 &&
be32_to_cpu(leaf->ents[lowstale].address) !=
XFS_DIR2_NULL_DATAPTR;
lowstale--)
continue;
for (highstale = index;
highstale < be16_to_cpu(leaf->hdr.count) &&
be32_to_cpu(leaf->ents[highstale].address) !=
XFS_DIR2_NULL_DATAPTR &&
(lowstale < 0 ||
index - lowstale - 1 >= highstale - index);
highstale++)
continue;
}
if (lowstale >= 0 &&
(highstale == be16_to_cpu(leaf->hdr.count) ||
index - lowstale - 1 < highstale - index)) {
ASSERT(index - lowstale - 1 >= 0);
ASSERT(be32_to_cpu(leaf->ents[lowstale].address) ==
XFS_DIR2_NULL_DATAPTR);
if (index - lowstale - 1 > 0)
memmove(&leaf->ents[lowstale],
&leaf->ents[lowstale + 1],
(index - lowstale - 1) * sizeof(*lep));
lep = &leaf->ents[index - 1];
lfloglow = MIN(lowstale, lfloglow);
lfloghigh = MAX(index - 1, lfloghigh);
}
else {
ASSERT(highstale - index >= 0);
ASSERT(be32_to_cpu(leaf->ents[highstale].address) ==
XFS_DIR2_NULL_DATAPTR);
if (highstale - index > 0)
memmove(&leaf->ents[index + 1],
&leaf->ents[index],
(highstale - index) * sizeof(*lep));
lep = &leaf->ents[index];
lfloglow = MIN(index, lfloglow);
lfloghigh = MAX(highstale, lfloghigh);
}
be16_add_cpu(&leaf->hdr.stale, -1);
}
lep->hashval = cpu_to_be32(args->hashval);
lep->address = cpu_to_be32(xfs_dir2_db_off_to_dataptr(mp, use_block,
be16_to_cpu(*tagp)));
xfs_dir2_leaf_log_header(tp, lbp);
xfs_dir2_leaf_log_ents(tp, lbp, lfloglow, lfloghigh);
xfs_dir2_leaf_check(dp, lbp);
xfs_da_buf_done(lbp);
xfs_dir2_data_check(dp, dbp);
xfs_da_buf_done(dbp);
return 0;
}
STATIC void
xfs_dir2_leaf_check(
xfs_inode_t *dp,
xfs_dabuf_t *bp)
{
int i;
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_tail_t *ltp;
xfs_mount_t *mp;
int stale;
leaf = bp->data;
mp = dp->i_mount;
ASSERT(be16_to_cpu(leaf->hdr.info.magic) == XFS_DIR2_LEAF1_MAGIC);
ASSERT(be16_to_cpu(leaf->hdr.count) <= xfs_dir2_max_leaf_ents(mp));
ltp = xfs_dir2_leaf_tail_p(mp, leaf);
ASSERT((char *)&leaf->ents[be16_to_cpu(leaf->hdr.count)] <=
(char *)xfs_dir2_leaf_bests_p(ltp));
for (i = stale = 0; i < be16_to_cpu(leaf->hdr.count); i++) {
if (i + 1 < be16_to_cpu(leaf->hdr.count))
ASSERT(be32_to_cpu(leaf->ents[i].hashval) <=
be32_to_cpu(leaf->ents[i + 1].hashval));
if (be32_to_cpu(leaf->ents[i].address) == XFS_DIR2_NULL_DATAPTR)
stale++;
}
ASSERT(be16_to_cpu(leaf->hdr.stale) == stale);
}
void
xfs_dir2_leaf_compact(
xfs_da_args_t *args,
xfs_dabuf_t *bp)
{
int from;
xfs_dir2_leaf_t *leaf;
int loglow;
int to;
leaf = bp->data;
if (!leaf->hdr.stale) {
return;
}
for (from = to = 0, loglow = -1; from < be16_to_cpu(leaf->hdr.count); from++) {
if (be32_to_cpu(leaf->ents[from].address) == XFS_DIR2_NULL_DATAPTR)
continue;
if (from > to) {
if (loglow == -1)
loglow = to;
leaf->ents[to] = leaf->ents[from];
}
to++;
}
ASSERT(be16_to_cpu(leaf->hdr.stale) == from - to);
be16_add_cpu(&leaf->hdr.count, -(be16_to_cpu(leaf->hdr.stale)));
leaf->hdr.stale = 0;
xfs_dir2_leaf_log_header(args->trans, bp);
if (loglow != -1)
xfs_dir2_leaf_log_ents(args->trans, bp, loglow, to - 1);
}
void
xfs_dir2_leaf_compact_x1(
xfs_dabuf_t *bp,
int *indexp,
int *lowstalep,
int *highstalep,
int *lowlogp,
int *highlogp)
{
int from;
int highstale;
int index;
int keepstale;
xfs_dir2_leaf_t *leaf;
int lowstale;
int newindex=0;
int to;
leaf = bp->data;
ASSERT(be16_to_cpu(leaf->hdr.stale) > 1);
index = *indexp;
for (lowstale = index - 1;
lowstale >= 0 &&
be32_to_cpu(leaf->ents[lowstale].address) != XFS_DIR2_NULL_DATAPTR;
lowstale--)
continue;
for (highstale = index;
highstale < be16_to_cpu(leaf->hdr.count) &&
be32_to_cpu(leaf->ents[highstale].address) != XFS_DIR2_NULL_DATAPTR &&
(lowstale < 0 || index - lowstale > highstale - index);
highstale++)
continue;
if (lowstale >= 0 &&
(highstale == be16_to_cpu(leaf->hdr.count) ||
index - lowstale <= highstale - index))
keepstale = lowstale;
else
keepstale = highstale;
for (from = to = 0; from < be16_to_cpu(leaf->hdr.count); from++) {
if (index == from)
newindex = to;
if (from != keepstale &&
be32_to_cpu(leaf->ents[from].address) == XFS_DIR2_NULL_DATAPTR) {
if (from == to)
*lowlogp = to;
continue;
}
if (from == keepstale)
lowstale = highstale = to;
if (from > to)
leaf->ents[to] = leaf->ents[from];
to++;
}
ASSERT(from > to);
if (index == from)
newindex = to;
*indexp = newindex;
be16_add_cpu(&leaf->hdr.count, -(from - to));
leaf->hdr.stale = cpu_to_be16(1);
if (lowstale >= newindex)
lowstale = -1;
else
highstale = be16_to_cpu(leaf->hdr.count);
*highlogp = be16_to_cpu(leaf->hdr.count) - 1;
*lowstalep = lowstale;
*highstalep = highstale;
}
int
xfs_dir2_leaf_getdents(
xfs_inode_t *dp,
void *dirent,
size_t bufsize,
xfs_off_t *offset,
filldir_t filldir)
{
xfs_dabuf_t *bp;
int byteoff;
xfs_dir2_db_t curdb;
xfs_dir2_off_t curoff;
xfs_dir2_data_t *data;
xfs_dir2_data_entry_t *dep;
xfs_dir2_data_unused_t *dup;
int error = 0;
int i;
int j;
int length;
xfs_bmbt_irec_t *map;
xfs_extlen_t map_blocks;
xfs_dablk_t map_off;
int map_size;
int map_valid;
xfs_mount_t *mp;
xfs_dir2_off_t newoff;
int nmap;
char *ptr = NULL;
int ra_current;
int ra_index;
int ra_offset;
int ra_want;
if (*offset >= XFS_DIR2_MAX_DATAPTR)
return 0;
mp = dp->i_mount;
map_size = howmany(bufsize + mp->m_dirblksize, mp->m_sb.sb_blocksize);
map = kmem_alloc(map_size * sizeof(*map), KM_SLEEP);
map_valid = ra_index = ra_offset = ra_current = map_blocks = 0;
bp = NULL;
curoff = xfs_dir2_dataptr_to_byte(mp, *offset);
map_off = xfs_dir2_db_to_da(mp, xfs_dir2_byte_to_db(mp, curoff));
while (curoff < XFS_DIR2_LEAF_OFFSET) {
if (!bp || ptr >= (char *)bp->data + mp->m_dirblksize) {
if (bp) {
xfs_da_brelse(NULL, bp);
bp = NULL;
map_blocks -= mp->m_dirblkfsbs;
for (i = mp->m_dirblkfsbs; i > 0; ) {
j = MIN((int)map->br_blockcount, i);
map->br_blockcount -= j;
map->br_startblock += j;
map->br_startoff += j;
if (!map->br_blockcount && --map_valid)
memmove(&map[0], &map[1],
sizeof(map[0]) *
map_valid);
i -= j;
}
}
ra_want = howmany(bufsize + mp->m_dirblksize,
mp->m_sb.sb_blocksize) - 1;
ASSERT(ra_want >= 0);
if (1 + ra_want > map_blocks &&
map_off <
xfs_dir2_byte_to_da(mp, XFS_DIR2_LEAF_OFFSET)) {
nmap = map_size - map_valid;
error = xfs_bmapi(NULL, dp,
map_off,
xfs_dir2_byte_to_da(mp,
XFS_DIR2_LEAF_OFFSET) - map_off,
XFS_BMAPI_METADATA, NULL, 0,
&map[map_valid], &nmap, NULL);
if (error)
break;
if (nmap == map_size - map_valid)
map_off =
map[map_valid + nmap - 1].br_startoff +
map[map_valid + nmap - 1].br_blockcount;
else
map_off =
xfs_dir2_byte_to_da(mp,
XFS_DIR2_LEAF_OFFSET);
for (i = map_valid; i < map_valid + nmap; ) {
if (map[i].br_startblock ==
HOLESTARTBLOCK) {
nmap--;
length = map_valid + nmap - i;
if (length)
memmove(&map[i],
&map[i + 1],
sizeof(map[i]) *
length);
} else {
map_blocks +=
map[i].br_blockcount;
i++;
}
}
map_valid += nmap;
}
if (!map_valid) {
curoff = xfs_dir2_da_to_byte(mp, map_off);
break;
}
curdb = xfs_dir2_da_to_db(mp, map->br_startoff);
error = xfs_da_read_buf(NULL, dp, map->br_startoff,
map->br_blockcount >= mp->m_dirblkfsbs ?
XFS_FSB_TO_DADDR(mp, map->br_startblock) :
-1,
&bp, XFS_DATA_FORK);
if (error)
break;
if (ra_current)
ra_current -= mp->m_dirblkfsbs;
for (ra_index = ra_offset = i = 0;
ra_want > ra_current && i < map_blocks;
i += mp->m_dirblkfsbs) {
ASSERT(ra_index < map_valid);
if (i > ra_current &&
map[ra_index].br_blockcount >=
mp->m_dirblkfsbs) {
xfs_buf_readahead(mp->m_ddev_targp,
XFS_FSB_TO_DADDR(mp,
map[ra_index].br_startblock +
ra_offset),
(int)BTOBB(mp->m_dirblksize));
ra_current = i;
}
else if (i > ra_current) {
(void)xfs_da_reada_buf(NULL, dp,
map[ra_index].br_startoff +
ra_offset, XFS_DATA_FORK);
ra_current = i;
}
for (j = 0; j < mp->m_dirblkfsbs; j++) {
length = MIN(mp->m_dirblkfsbs,
(int)(map[ra_index].br_blockcount -
ra_offset));
j += length;
ra_offset += length;
if (ra_offset ==
map[ra_index].br_blockcount) {
ra_offset = 0;
ra_index++;
}
}
}
newoff = xfs_dir2_db_off_to_byte(mp, curdb, 0);
if (curoff < newoff)
curoff = newoff;
else if (curoff > newoff)
ASSERT(xfs_dir2_byte_to_db(mp, curoff) ==
curdb);
data = bp->data;
xfs_dir2_data_check(dp, bp);
ptr = (char *)&data->u;
byteoff = xfs_dir2_byte_to_off(mp, curoff);
if (byteoff == 0)
curoff += (uint)sizeof(data->hdr);
else {
while ((char *)ptr - (char *)data < byteoff) {
dup = (xfs_dir2_data_unused_t *)ptr;
if (be16_to_cpu(dup->freetag)
== XFS_DIR2_DATA_FREE_TAG) {
length = be16_to_cpu(dup->length);
ptr += length;
continue;
}
dep = (xfs_dir2_data_entry_t *)ptr;
length =
xfs_dir2_data_entsize(dep->namelen);
ptr += length;
}
curoff =
xfs_dir2_db_off_to_byte(mp,
xfs_dir2_byte_to_db(mp, curoff),
(char *)ptr - (char *)data);
if (ptr >= (char *)data + mp->m_dirblksize) {
continue;
}
}
}
dup = (xfs_dir2_data_unused_t *)ptr;
if (be16_to_cpu(dup->freetag) == XFS_DIR2_DATA_FREE_TAG) {
length = be16_to_cpu(dup->length);
ptr += length;
curoff += length;
continue;
}
dep = (xfs_dir2_data_entry_t *)ptr;
length = xfs_dir2_data_entsize(dep->namelen);
if (filldir(dirent, (char *)dep->name, dep->namelen,
xfs_dir2_byte_to_dataptr(mp, curoff) & 0x7fffffff,
be64_to_cpu(dep->inumber), DT_UNKNOWN))
break;
ptr += length;
curoff += length;
bufsize = bufsize > length ? bufsize - length : 0;
}
if (curoff > xfs_dir2_dataptr_to_byte(mp, XFS_DIR2_MAX_DATAPTR))
*offset = XFS_DIR2_MAX_DATAPTR & 0x7fffffff;
else
*offset = xfs_dir2_byte_to_dataptr(mp, curoff) & 0x7fffffff;
kmem_free(map);
if (bp)
xfs_da_brelse(NULL, bp);
return error;
}
int
xfs_dir2_leaf_init(
xfs_da_args_t *args,
xfs_dir2_db_t bno,
xfs_dabuf_t **bpp,
int magic)
{
xfs_dabuf_t *bp;
xfs_inode_t *dp;
int error;
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_tail_t *ltp;
xfs_mount_t *mp;
xfs_trans_t *tp;
dp = args->dp;
ASSERT(dp != NULL);
tp = args->trans;
mp = dp->i_mount;
ASSERT(bno >= XFS_DIR2_LEAF_FIRSTDB(mp) &&
bno < XFS_DIR2_FREE_FIRSTDB(mp));
error = xfs_da_get_buf(tp, dp, xfs_dir2_db_to_da(mp, bno), -1, &bp,
XFS_DATA_FORK);
if (error) {
return error;
}
ASSERT(bp != NULL);
leaf = bp->data;
leaf->hdr.info.magic = cpu_to_be16(magic);
leaf->hdr.info.forw = 0;
leaf->hdr.info.back = 0;
leaf->hdr.count = 0;
leaf->hdr.stale = 0;
xfs_dir2_leaf_log_header(tp, bp);
if (magic == XFS_DIR2_LEAF1_MAGIC) {
ltp = xfs_dir2_leaf_tail_p(mp, leaf);
ltp->bestcount = 0;
xfs_dir2_leaf_log_tail(tp, bp);
}
*bpp = bp;
return 0;
}
static void
xfs_dir2_leaf_log_bests(
xfs_trans_t *tp,
xfs_dabuf_t *bp,
int first,
int last)
{
__be16 *firstb;
__be16 *lastb;
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_tail_t *ltp;
leaf = bp->data;
ASSERT(be16_to_cpu(leaf->hdr.info.magic) == XFS_DIR2_LEAF1_MAGIC);
ltp = xfs_dir2_leaf_tail_p(tp->t_mountp, leaf);
firstb = xfs_dir2_leaf_bests_p(ltp) + first;
lastb = xfs_dir2_leaf_bests_p(ltp) + last;
xfs_da_log_buf(tp, bp, (uint)((char *)firstb - (char *)leaf),
(uint)((char *)lastb - (char *)leaf + sizeof(*lastb) - 1));
}
void
xfs_dir2_leaf_log_ents(
xfs_trans_t *tp,
xfs_dabuf_t *bp,
int first,
int last)
{
xfs_dir2_leaf_entry_t *firstlep;
xfs_dir2_leaf_entry_t *lastlep;
xfs_dir2_leaf_t *leaf;
leaf = bp->data;
ASSERT(be16_to_cpu(leaf->hdr.info.magic) == XFS_DIR2_LEAF1_MAGIC ||
be16_to_cpu(leaf->hdr.info.magic) == XFS_DIR2_LEAFN_MAGIC);
firstlep = &leaf->ents[first];
lastlep = &leaf->ents[last];
xfs_da_log_buf(tp, bp, (uint)((char *)firstlep - (char *)leaf),
(uint)((char *)lastlep - (char *)leaf + sizeof(*lastlep) - 1));
}
void
xfs_dir2_leaf_log_header(
xfs_trans_t *tp,
xfs_dabuf_t *bp)
{
xfs_dir2_leaf_t *leaf;
leaf = bp->data;
ASSERT(be16_to_cpu(leaf->hdr.info.magic) == XFS_DIR2_LEAF1_MAGIC ||
be16_to_cpu(leaf->hdr.info.magic) == XFS_DIR2_LEAFN_MAGIC);
xfs_da_log_buf(tp, bp, (uint)((char *)&leaf->hdr - (char *)leaf),
(uint)(sizeof(leaf->hdr) - 1));
}
STATIC void
xfs_dir2_leaf_log_tail(
xfs_trans_t *tp,
xfs_dabuf_t *bp)
{
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_tail_t *ltp;
xfs_mount_t *mp;
mp = tp->t_mountp;
leaf = bp->data;
ASSERT(be16_to_cpu(leaf->hdr.info.magic) == XFS_DIR2_LEAF1_MAGIC);
ltp = xfs_dir2_leaf_tail_p(mp, leaf);
xfs_da_log_buf(tp, bp, (uint)((char *)ltp - (char *)leaf),
(uint)(mp->m_dirblksize - 1));
}
int
xfs_dir2_leaf_lookup(
xfs_da_args_t *args)
{
xfs_dabuf_t *dbp;
xfs_dir2_data_entry_t *dep;
xfs_inode_t *dp;
int error;
int index;
xfs_dabuf_t *lbp;
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_entry_t *lep;
xfs_trans_t *tp;
trace_xfs_dir2_leaf_lookup(args);
if ((error = xfs_dir2_leaf_lookup_int(args, &lbp, &index, &dbp))) {
return error;
}
tp = args->trans;
dp = args->dp;
xfs_dir2_leaf_check(dp, lbp);
leaf = lbp->data;
lep = &leaf->ents[index];
dep = (xfs_dir2_data_entry_t *)
((char *)dbp->data +
xfs_dir2_dataptr_to_off(dp->i_mount, be32_to_cpu(lep->address)));
args->inumber = be64_to_cpu(dep->inumber);
error = xfs_dir_cilookup_result(args, dep->name, dep->namelen);
xfs_da_brelse(tp, dbp);
xfs_da_brelse(tp, lbp);
return XFS_ERROR(error);
}
static int
xfs_dir2_leaf_lookup_int(
xfs_da_args_t *args,
xfs_dabuf_t **lbpp,
int *indexp,
xfs_dabuf_t **dbpp)
{
xfs_dir2_db_t curdb = -1;
xfs_dabuf_t *dbp = NULL;
xfs_dir2_data_entry_t *dep;
xfs_inode_t *dp;
int error;
int index;
xfs_dabuf_t *lbp;
xfs_dir2_leaf_entry_t *lep;
xfs_dir2_leaf_t *leaf;
xfs_mount_t *mp;
xfs_dir2_db_t newdb;
xfs_trans_t *tp;
xfs_dir2_db_t cidb = -1;
enum xfs_dacmp cmp;
dp = args->dp;
tp = args->trans;
mp = dp->i_mount;
error = xfs_da_read_buf(tp, dp, mp->m_dirleafblk, -1, &lbp,
XFS_DATA_FORK);
if (error)
return error;
*lbpp = lbp;
leaf = lbp->data;
xfs_dir2_leaf_check(dp, lbp);
index = xfs_dir2_leaf_search_hash(args, lbp);
for (lep = &leaf->ents[index]; index < be16_to_cpu(leaf->hdr.count) &&
be32_to_cpu(lep->hashval) == args->hashval;
lep++, index++) {
if (be32_to_cpu(lep->address) == XFS_DIR2_NULL_DATAPTR)
continue;
newdb = xfs_dir2_dataptr_to_db(mp, be32_to_cpu(lep->address));
if (newdb != curdb) {
if (dbp)
xfs_da_brelse(tp, dbp);
error = xfs_da_read_buf(tp, dp,
xfs_dir2_db_to_da(mp, newdb),
-1, &dbp, XFS_DATA_FORK);
if (error) {
xfs_da_brelse(tp, lbp);
return error;
}
xfs_dir2_data_check(dp, dbp);
curdb = newdb;
}
dep = (xfs_dir2_data_entry_t *)((char *)dbp->data +
xfs_dir2_dataptr_to_off(mp, be32_to_cpu(lep->address)));
cmp = mp->m_dirnameops->compname(args, dep->name, dep->namelen);
if (cmp != XFS_CMP_DIFFERENT && cmp != args->cmpresult) {
args->cmpresult = cmp;
*indexp = index;
if (cmp == XFS_CMP_EXACT) {
*dbpp = dbp;
return 0;
}
cidb = curdb;
}
}
ASSERT(args->op_flags & XFS_DA_OP_OKNOENT);
if (args->cmpresult == XFS_CMP_CASE) {
ASSERT(cidb != -1);
if (cidb != curdb) {
xfs_da_brelse(tp, dbp);
error = xfs_da_read_buf(tp, dp,
xfs_dir2_db_to_da(mp, cidb),
-1, &dbp, XFS_DATA_FORK);
if (error) {
xfs_da_brelse(tp, lbp);
return error;
}
}
*dbpp = dbp;
return 0;
}
ASSERT(cidb == -1);
if (dbp)
xfs_da_brelse(tp, dbp);
xfs_da_brelse(tp, lbp);
return XFS_ERROR(ENOENT);
}
int
xfs_dir2_leaf_removename(
xfs_da_args_t *args)
{
__be16 *bestsp;
xfs_dir2_data_t *data;
xfs_dir2_db_t db;
xfs_dabuf_t *dbp;
xfs_dir2_data_entry_t *dep;
xfs_inode_t *dp;
int error;
xfs_dir2_db_t i;
int index;
xfs_dabuf_t *lbp;
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_entry_t *lep;
xfs_dir2_leaf_tail_t *ltp;
xfs_mount_t *mp;
int needlog;
int needscan;
xfs_dir2_data_off_t oldbest;
xfs_trans_t *tp;
trace_xfs_dir2_leaf_removename(args);
if ((error = xfs_dir2_leaf_lookup_int(args, &lbp, &index, &dbp))) {
return error;
}
dp = args->dp;
tp = args->trans;
mp = dp->i_mount;
leaf = lbp->data;
data = dbp->data;
xfs_dir2_data_check(dp, dbp);
lep = &leaf->ents[index];
db = xfs_dir2_dataptr_to_db(mp, be32_to_cpu(lep->address));
dep = (xfs_dir2_data_entry_t *)
((char *)data + xfs_dir2_dataptr_to_off(mp, be32_to_cpu(lep->address)));
needscan = needlog = 0;
oldbest = be16_to_cpu(data->hdr.bestfree[0].length);
ltp = xfs_dir2_leaf_tail_p(mp, leaf);
bestsp = xfs_dir2_leaf_bests_p(ltp);
ASSERT(be16_to_cpu(bestsp[db]) == oldbest);
xfs_dir2_data_make_free(tp, dbp,
(xfs_dir2_data_aoff_t)((char *)dep - (char *)data),
xfs_dir2_data_entsize(dep->namelen), &needlog, &needscan);
be16_add_cpu(&leaf->hdr.stale, 1);
xfs_dir2_leaf_log_header(tp, lbp);
lep->address = cpu_to_be32(XFS_DIR2_NULL_DATAPTR);
xfs_dir2_leaf_log_ents(tp, lbp, index, index);
if (needscan)
xfs_dir2_data_freescan(mp, data, &needlog);
if (needlog)
xfs_dir2_data_log_header(tp, dbp);
if (be16_to_cpu(data->hdr.bestfree[0].length) != oldbest) {
bestsp[db] = data->hdr.bestfree[0].length;
xfs_dir2_leaf_log_bests(tp, lbp, db, db);
}
xfs_dir2_data_check(dp, dbp);
if (be16_to_cpu(data->hdr.bestfree[0].length) ==
mp->m_dirblksize - (uint)sizeof(data->hdr)) {
ASSERT(db != mp->m_dirdatablk);
if ((error = xfs_dir2_shrink_inode(args, db, dbp))) {
if (error == ENOSPC && args->total == 0) {
xfs_da_buf_done(dbp);
error = 0;
}
xfs_dir2_leaf_check(dp, lbp);
xfs_da_buf_done(lbp);
return error;
}
dbp = NULL;
if (db == be32_to_cpu(ltp->bestcount) - 1) {
for (i = db - 1; i > 0; i--) {
if (be16_to_cpu(bestsp[i]) != NULLDATAOFF)
break;
}
memmove(&bestsp[db - i], bestsp,
(be32_to_cpu(ltp->bestcount) - (db - i)) * sizeof(*bestsp));
be32_add_cpu(&ltp->bestcount, -(db - i));
xfs_dir2_leaf_log_tail(tp, lbp);
xfs_dir2_leaf_log_bests(tp, lbp, 0, be32_to_cpu(ltp->bestcount) - 1);
} else
bestsp[db] = cpu_to_be16(NULLDATAOFF);
}
else if (db != mp->m_dirdatablk && dbp != NULL) {
xfs_da_buf_done(dbp);
dbp = NULL;
}
xfs_dir2_leaf_check(dp, lbp);
return xfs_dir2_leaf_to_block(args, lbp, dbp);
}
int
xfs_dir2_leaf_replace(
xfs_da_args_t *args)
{
xfs_dabuf_t *dbp;
xfs_dir2_data_entry_t *dep;
xfs_inode_t *dp;
int error;
int index;
xfs_dabuf_t *lbp;
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_entry_t *lep;
xfs_trans_t *tp;
trace_xfs_dir2_leaf_replace(args);
if ((error = xfs_dir2_leaf_lookup_int(args, &lbp, &index, &dbp))) {
return error;
}
dp = args->dp;
leaf = lbp->data;
lep = &leaf->ents[index];
dep = (xfs_dir2_data_entry_t *)
((char *)dbp->data +
xfs_dir2_dataptr_to_off(dp->i_mount, be32_to_cpu(lep->address)));
ASSERT(args->inumber != be64_to_cpu(dep->inumber));
dep->inumber = cpu_to_be64(args->inumber);
tp = args->trans;
xfs_dir2_data_log_entry(tp, dbp, dep);
xfs_da_buf_done(dbp);
xfs_dir2_leaf_check(dp, lbp);
xfs_da_brelse(tp, lbp);
return 0;
}
int
xfs_dir2_leaf_search_hash(
xfs_da_args_t *args,
xfs_dabuf_t *lbp)
{
xfs_dahash_t hash=0;
xfs_dahash_t hashwant;
int high;
int low;
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_entry_t *lep;
int mid=0;
leaf = lbp->data;
#ifndef __KERNEL__
if (!leaf->hdr.count)
return 0;
#endif
for (lep = leaf->ents, low = 0, high = be16_to_cpu(leaf->hdr.count) - 1,
hashwant = args->hashval;
low <= high; ) {
mid = (low + high) >> 1;
if ((hash = be32_to_cpu(lep[mid].hashval)) == hashwant)
break;
if (hash < hashwant)
low = mid + 1;
else
high = mid - 1;
}
if (hash == hashwant) {
while (mid > 0 && be32_to_cpu(lep[mid - 1].hashval) == hashwant) {
mid--;
}
}
else if (hash < hashwant)
mid++;
return mid;
}
int
xfs_dir2_leaf_trim_data(
xfs_da_args_t *args,
xfs_dabuf_t *lbp,
xfs_dir2_db_t db)
{
__be16 *bestsp;
#ifdef DEBUG
xfs_dir2_data_t *data;
#endif
xfs_dabuf_t *dbp;
xfs_inode_t *dp;
int error;
xfs_dir2_leaf_t *leaf;
xfs_dir2_leaf_tail_t *ltp;
xfs_mount_t *mp;
xfs_trans_t *tp;
dp = args->dp;
mp = dp->i_mount;
tp = args->trans;
if ((error = xfs_da_read_buf(tp, dp, xfs_dir2_db_to_da(mp, db), -1, &dbp,
XFS_DATA_FORK))) {
return error;
}
#ifdef DEBUG
data = dbp->data;
ASSERT(be32_to_cpu(data->hdr.magic) == XFS_DIR2_DATA_MAGIC);
#endif
leaf = lbp->data;
ltp = xfs_dir2_leaf_tail_p(mp, leaf);
ASSERT(be16_to_cpu(data->hdr.bestfree[0].length) ==
mp->m_dirblksize - (uint)sizeof(data->hdr));
ASSERT(db == be32_to_cpu(ltp->bestcount) - 1);
if ((error = xfs_dir2_shrink_inode(args, db, dbp))) {
ASSERT(error != ENOSPC);
xfs_da_brelse(tp, dbp);
return error;
}
bestsp = xfs_dir2_leaf_bests_p(ltp);
be32_add_cpu(&ltp->bestcount, -1);
memmove(&bestsp[1], &bestsp[0], be32_to_cpu(ltp->bestcount) * sizeof(*bestsp));
xfs_dir2_leaf_log_tail(tp, lbp);
xfs_dir2_leaf_log_bests(tp, lbp, 0, be32_to_cpu(ltp->bestcount) - 1);
return 0;
}
int
xfs_dir2_node_to_leaf(
xfs_da_state_t *state)
{
xfs_da_args_t *args;
xfs_inode_t *dp;
int error;
xfs_dabuf_t *fbp;
xfs_fileoff_t fo;
xfs_dir2_free_t *free;
xfs_dabuf_t *lbp;
xfs_dir2_leaf_tail_t *ltp;
xfs_dir2_leaf_t *leaf;
xfs_mount_t *mp;
int rval;
xfs_trans_t *tp;
if (state->path.active > 1)
return 0;
args = state->args;
trace_xfs_dir2_node_to_leaf(args);
mp = state->mp;
dp = args->dp;
tp = args->trans;
if ((error = xfs_bmap_last_offset(tp, dp, &fo, XFS_DATA_FORK))) {
return error;
}
fo -= mp->m_dirblkfsbs;
while (fo > mp->m_dirfreeblk) {
if ((error = xfs_dir2_node_trim_free(args, fo, &rval))) {
return error;
}
if (rval)
fo -= mp->m_dirblkfsbs;
else
return 0;
}
if ((error = xfs_bmap_last_before(tp, dp, &fo, XFS_DATA_FORK))) {
return error;
}
if (XFS_FSB_TO_B(mp, fo) > XFS_DIR2_LEAF_OFFSET + mp->m_dirblksize)
return 0;
lbp = state->path.blk[0].bp;
leaf = lbp->data;
ASSERT(be16_to_cpu(leaf->hdr.info.magic) == XFS_DIR2_LEAFN_MAGIC);
if ((error = xfs_da_read_buf(tp, dp, mp->m_dirfreeblk, -1, &fbp,
XFS_DATA_FORK))) {
return error;
}
free = fbp->data;
ASSERT(be32_to_cpu(free->hdr.magic) == XFS_DIR2_FREE_MAGIC);
ASSERT(!free->hdr.firstdb);
if ((uint)sizeof(leaf->hdr) +
(be16_to_cpu(leaf->hdr.count) - be16_to_cpu(leaf->hdr.stale)) * (uint)sizeof(leaf->ents[0]) +
be32_to_cpu(free->hdr.nvalid) * (uint)sizeof(leaf->bests[0]) +
(uint)sizeof(leaf->tail) >
mp->m_dirblksize) {
xfs_da_brelse(tp, fbp);
return 0;
}
if (be16_to_cpu(leaf->hdr.stale))
xfs_dir2_leaf_compact(args, lbp);
else
xfs_dir2_leaf_log_header(tp, lbp);
leaf->hdr.info.magic = cpu_to_be16(XFS_DIR2_LEAF1_MAGIC);
ltp = xfs_dir2_leaf_tail_p(mp, leaf);
ltp->bestcount = free->hdr.nvalid;
memcpy(xfs_dir2_leaf_bests_p(ltp), free->bests,
be32_to_cpu(ltp->bestcount) * sizeof(leaf->bests[0]));
xfs_dir2_leaf_log_bests(tp, lbp, 0, be32_to_cpu(ltp->bestcount) - 1);
xfs_dir2_leaf_log_tail(tp, lbp);
xfs_dir2_leaf_check(dp, lbp);
error = xfs_dir2_shrink_inode(args, XFS_DIR2_FREE_FIRSTDB(mp), fbp);
if (error) {
ASSERT(error != ENOSPC);
return error;
}
fbp = NULL;
error = xfs_dir2_leaf_to_block(args, lbp, NULL);
state->path.blk[0].bp = NULL;
return error;
}
