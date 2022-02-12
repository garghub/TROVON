static char *fsfilt_ext3_get_label(struct super_block *sb)
{
return EXT3_SB(sb)->s_es->s_volume_name;
}
static void *fsfilt_ext3_start(struct inode *inode, int op, void *desc_private,
int logs)
{
int nblocks = FSFILT_SINGLEDATA_TRANS_BLOCKS(inode->i_sb);
journal_t *journal;
void *handle;
if (current->journal_info) {
CDEBUG(D_INODE, "increasing refcount on %p\n",
current->journal_info);
goto journal_start;
}
switch(op) {
case FSFILT_OP_UNLINK:
nblocks += EXT3_DELETE_TRANS_BLOCKS(inode->i_sb);
nblocks += (EXT3_INDEX_EXTRA_TRANS_BLOCKS +
FSFILT_SINGLEDATA_TRANS_BLOCKS(inode->i_sb)) * logs;
break;
case FSFILT_OP_CANCEL_UNLINK:
LASSERT(logs == 1);
nblocks = (LLOG_CHUNK_SIZE >> inode->i_blkbits) +
EXT3_DELETE_TRANS_BLOCKS(inode->i_sb) +
ext4_blocks_for_truncate(inode) + 3;
break;
default: CERROR("unknown transaction start op %d\n", op);
LBUG();
}
LASSERT(current->journal_info == desc_private);
journal = EXT3_SB(inode->i_sb)->s_journal;
if (nblocks > journal->j_max_transaction_buffers) {
CWARN("too many credits %d for op %ux%u using %d instead\n",
nblocks, op, logs, journal->j_max_transaction_buffers);
nblocks = journal->j_max_transaction_buffers;
}
journal_start:
LASSERTF(nblocks > 0, "can't start %d credit transaction\n", nblocks);
handle = ext3_journal_start(inode, nblocks);
if (!IS_ERR(handle))
LASSERT(current->journal_info == handle);
else
CERROR("error starting handle for op %u (%u credits): rc %ld\n",
op, nblocks, PTR_ERR(handle));
return handle;
}
static int fsfilt_ext3_commit(struct inode *inode, void *h, int force_sync)
{
int rc;
handle_t *handle = h;
LASSERT(current->journal_info == handle);
if (force_sync)
handle->h_sync = 1;
rc = ext3_journal_stop(handle);
return rc;
}
static long ext3_ext_find_goal(struct inode *inode, struct ext3_ext_path *path,
unsigned long block, int *aflags)
{
struct ext3_inode_info *ei = EXT3_I(inode);
unsigned long bg_start;
unsigned long colour;
int depth;
if (path) {
struct ext3_extent *ex;
depth = path->p_depth;
if ((ex = path[depth].p_ext))
return ext4_ext_pblock(ex) + (block - le32_to_cpu(ex->ee_block));
if (path[depth].p_bh)
return path[depth].p_bh->b_blocknr;
}
bg_start = (ei->i_block_group * EXT3_BLOCKS_PER_GROUP(inode->i_sb)) +
le32_to_cpu(EXT3_SB(inode->i_sb)->s_es->s_first_data_block);
colour = (current->pid % 16) *
(EXT3_BLOCKS_PER_GROUP(inode->i_sb) / 16);
return bg_start + colour + block;
}
static unsigned long new_blocks(handle_t *handle, struct ext3_ext_base *base,
struct ext3_ext_path *path, unsigned long block,
unsigned long *count, int *err)
{
unsigned long pblock, goal;
int aflags = 0;
struct inode *inode = ext3_ext_base2inode(base);
goal = ext3_ext_find_goal(inode, path, block, &aflags);
aflags |= 2;
pblock = ext3_mb_new_blocks(handle, inode, goal, count, aflags, err);
return pblock;
}
static unsigned long new_blocks(handle_t *handle, struct ext3_ext_base *base,
struct ext3_ext_path *path, unsigned long block,
unsigned long *count, int *err)
{
struct inode *inode = ext3_ext_base2inode(base);
struct ext3_allocation_request ar;
unsigned long pblock;
int aflags;
ar.lleft = block;
*err = ext3_ext_search_left(base, path, &ar.lleft, &ar.pleft);
if (*err)
return 0;
ar.lright = block;
*err = ext3_ext_search_right(base, path, &ar.lright, &ar.pright);
if (*err)
return 0;
ar.goal = ext3_ext_find_goal(inode, path, block, &aflags);
ar.inode = inode;
ar.logical = block;
ar.len = *count;
ar.flags = EXT3_MB_HINT_DATA;
pblock = ext3_mb_new_blocks(handle, &ar, err);
*count = ar.len;
return pblock;
}
static int ext3_ext_new_extent_cb(struct ext3_ext_base *base,
struct ext3_ext_path *path,
struct ext3_ext_cache *cex,
#ifdef HAVE_EXT_PREPARE_CB_EXTENT
struct ext3_extent *ex,
#endif
void *cbdata)
{
struct bpointers *bp = cbdata;
struct inode *inode = ext3_ext_base2inode(base);
struct ext3_extent nex;
unsigned long pblock;
unsigned long tgen;
int err, i;
unsigned long count;
handle_t *handle;
#ifdef EXT3_EXT_CACHE_EXTENT
if (cex->ec_type == EXT3_EXT_CACHE_EXTENT)
#else
if ((cex->ec_len != 0) && (cex->ec_start != 0))
#endif
{
err = EXT_CONTINUE;
goto map;
}
if (bp->create == 0) {
i = 0;
if (cex->ec_block < bp->start)
i = bp->start - cex->ec_block;
if (i >= cex->ec_len)
CERROR("nothing to do?! i = %d, e_num = %u\n",
i, cex->ec_len);
for (; i < cex->ec_len && bp->num; i++) {
*(bp->blocks) = 0;
bp->blocks++;
bp->num--;
bp->start++;
}
return EXT_CONTINUE;
}
tgen = EXT_GENERATION(base);
count = ext3_ext_calc_credits_for_insert(base, path);
handle = ext3_journal_start(inode, count+EXT3_ALLOC_NEEDED+1);
if (IS_ERR(handle)) {
return PTR_ERR(handle);
}
if (tgen != EXT_GENERATION(base)) {
ext3_journal_stop(handle);
return EXT_REPEAT;
}
down_write((&EXT4_I(inode)->i_data_sem));
if (EXT_GENERATION(base) != path[0].p_generation) {
up_write(&EXT4_I(inode)->i_data_sem);
ext3_journal_stop(handle);
return EXT_REPEAT;
}
count = cex->ec_len;
pblock = new_blocks(handle, base, path, cex->ec_block, &count, &err);
if (!pblock)
goto out;
EXT_ASSERT(count <= cex->ec_len);
nex.ee_block = cpu_to_le32(cex->ec_block);
ext3_ext_store_pblock(&nex, pblock);
nex.ee_len = cpu_to_le16(count);
err = fsfilt_ext3_ext_insert_extent(handle, base, path, &nex, 0);
if (err) {
#ifdef EXT3_MB_HINT_GROUP_ALLOC
ext3_mb_discard_inode_preallocations(inode);
#endif
#ifdef HAVE_EXT_FREE_BLOCK_WITH_BUFFER_HEAD
ext3_free_blocks(handle, inode, NULL, ext4_ext_pblock(&nex),
cpu_to_le16(nex.ee_len), 0);
#else
ext3_free_blocks(handle, inode, ext4_ext_pblock(&nex),
cpu_to_le16(nex.ee_len), 0);
#endif
goto out;
}
cex->ec_len = le16_to_cpu(nex.ee_len);
cex->ec_start = ext4_ext_pblock(&nex);
BUG_ON(le16_to_cpu(nex.ee_len) == 0);
BUG_ON(le32_to_cpu(nex.ee_block) != cex->ec_block);
out:
up_write((&EXT4_I(inode)->i_data_sem));
ext3_journal_stop(handle);
map:
if (err >= 0) {
if (bp->num == 0) {
CERROR("hmm. why do we find this extent?\n");
CERROR("initial space: %lu:%u\n",
bp->start, bp->init_num);
#ifdef EXT3_EXT_CACHE_EXTENT
CERROR("current extent: %u/%u/%llu %d\n",
cex->ec_block, cex->ec_len,
(unsigned long long)cex->ec_start,
cex->ec_type);
#else
CERROR("current extent: %u/%u/%llu\n",
cex->ec_block, cex->ec_len,
(unsigned long long)cex->ec_start);
#endif
}
i = 0;
if (cex->ec_block < bp->start)
i = bp->start - cex->ec_block;
if (i >= cex->ec_len)
CERROR("nothing to do?! i = %d, e_num = %u\n",
i, cex->ec_len);
for (; i < cex->ec_len && bp->num; i++) {
*(bp->blocks) = cex->ec_start + i;
#ifdef EXT3_EXT_CACHE_EXTENT
if (cex->ec_type != EXT3_EXT_CACHE_EXTENT)
#else
if ((cex->ec_len == 0) || (cex->ec_start == 0))
#endif
{
ll_unmap_underlying_metadata(inode->i_sb,
*(bp->blocks));
}
bp->blocks++;
bp->num--;
bp->start++;
}
}
return err;
}
int fsfilt_map_nblocks(struct inode *inode, unsigned long block,
unsigned long num, unsigned long *blocks,
int create)
{
struct ext3_ext_base *base = inode;
struct bpointers bp;
int err;
CDEBUG(D_OTHER, "blocks %lu-%lu requested for inode %u\n",
block, block + num - 1, (unsigned) inode->i_ino);
bp.blocks = blocks;
bp.start = block;
bp.init_num = bp.num = num;
bp.create = create;
err = fsfilt_ext3_ext_walk_space(base, block, num,
ext3_ext_new_extent_cb, &bp);
ext3_ext_invalidate_cache(base);
return err;
}
int fsfilt_ext3_map_ext_inode_pages(struct inode *inode, struct page **page,
int pages, unsigned long *blocks,
int create)
{
int blocks_per_page = PAGE_CACHE_SIZE >> inode->i_blkbits;
int rc = 0, i = 0;
struct page *fp = NULL;
int clen = 0;
CDEBUG(D_OTHER, "inode %lu: map %d pages from %lu\n",
inode->i_ino, pages, (*page)->index);
while (i < pages) {
if (fp == NULL) {
fp = *page++;
clen = 1;
i++;
continue;
} else if (fp->index + clen == (*page)->index) {
page++;
clen++;
i++;
continue;
}
rc = fsfilt_map_nblocks(inode, fp->index * blocks_per_page,
clen * blocks_per_page, blocks,
create);
if (rc)
GOTO(cleanup, rc);
fp = NULL;
blocks += blocks_per_page * clen;
}
if (fp)
rc = fsfilt_map_nblocks(inode, fp->index * blocks_per_page,
clen * blocks_per_page, blocks,
create);
cleanup:
return rc;
}
int fsfilt_ext3_map_bm_inode_pages(struct inode *inode, struct page **page,
int pages, unsigned long *blocks,
int create)
{
int blocks_per_page = PAGE_CACHE_SIZE >> inode->i_blkbits;
unsigned long *b;
int rc = 0, i;
for (i = 0, b = blocks; i < pages; i++, page++) {
rc = ext3_map_inode_page(inode, *page, b, create);
if (rc) {
CERROR("ino %lu, blk %lu create %d: rc %d\n",
inode->i_ino, *b, create, rc);
break;
}
b += blocks_per_page;
}
return rc;
}
int fsfilt_ext3_map_inode_pages(struct inode *inode, struct page **page,
int pages, unsigned long *blocks,
int create, struct mutex *optional_mutex)
{
int rc;
if (EXT3_I(inode)->i_flags & EXT3_EXTENTS_FL) {
rc = fsfilt_ext3_map_ext_inode_pages(inode, page, pages,
blocks, create);
return rc;
}
if (optional_mutex != NULL)
mutex_lock(optional_mutex);
rc = fsfilt_ext3_map_bm_inode_pages(inode, page, pages, blocks, create);
if (optional_mutex != NULL)
mutex_unlock(optional_mutex);
return rc;
}
int fsfilt_ext3_read(struct inode *inode, void *buf, int size, loff_t *offs)
{
unsigned long block;
struct buffer_head *bh;
int err, blocksize, csize, boffs, osize = size;
spin_lock(&inode->i_lock);
if (i_size_read(inode) < *offs + size) {
size = i_size_read(inode) - *offs;
spin_unlock(&inode->i_lock);
if (size < 0) {
CDEBUG(D_EXT2, "size %llu is too short for read @%llu\n",
i_size_read(inode), *offs);
return -EBADR;
} else if (size == 0) {
return 0;
}
} else {
spin_unlock(&inode->i_lock);
}
blocksize = 1 << inode->i_blkbits;
while (size > 0) {
block = *offs >> inode->i_blkbits;
boffs = *offs & (blocksize - 1);
csize = min(blocksize - boffs, size);
bh = ext3_bread(NULL, inode, block, 0, &err);
if (!bh) {
CERROR("can't read block: %d\n", err);
return err;
}
memcpy(buf, bh->b_data + boffs, csize);
brelse(bh);
*offs += csize;
buf += csize;
size -= csize;
}
return osize;
}
static int fsfilt_ext3_read_record(struct file * file, void *buf,
int size, loff_t *offs)
{
int rc;
rc = fsfilt_ext3_read(file->f_dentry->d_inode, buf, size, offs);
if (rc > 0)
rc = 0;
return rc;
}
int fsfilt_ext3_write_handle(struct inode *inode, void *buf, int bufsize,
loff_t *offs, handle_t *handle)
{
struct buffer_head *bh = NULL;
loff_t old_size = i_size_read(inode), offset = *offs;
loff_t new_size = i_size_read(inode);
unsigned long block;
int err = 0, blocksize = 1 << inode->i_blkbits, size, boffs;
while (bufsize > 0) {
if (bh != NULL)
brelse(bh);
block = offset >> inode->i_blkbits;
boffs = offset & (blocksize - 1);
size = min(blocksize - boffs, bufsize);
bh = ext3_bread(handle, inode, block, 1, &err);
if (!bh) {
CERROR("can't read/create block: %d\n", err);
break;
}
err = ext3_journal_get_write_access(handle, bh);
if (err) {
CERROR("journal_get_write_access() returned error %d\n",
err);
break;
}
LASSERT(bh->b_data + boffs + size <= bh->b_data + bh->b_size);
memcpy(bh->b_data + boffs, buf, size);
err = ext3_journal_dirty_metadata(handle, bh);
if (err) {
CERROR("journal_dirty_metadata() returned error %d\n",
err);
break;
}
if (offset + size > new_size)
new_size = offset + size;
offset += size;
bufsize -= size;
buf += size;
}
if (bh)
brelse(bh);
if (new_size > i_size_read(inode)) {
spin_lock(&inode->i_lock);
if (new_size > i_size_read(inode))
i_size_write(inode, new_size);
if (i_size_read(inode) > EXT3_I(inode)->i_disksize)
EXT3_I(inode)->i_disksize = i_size_read(inode);
if (i_size_read(inode) > old_size) {
spin_unlock(&inode->i_lock);
mark_inode_dirty(inode);
} else {
spin_unlock(&inode->i_lock);
}
}
if (err == 0)
*offs = offset;
return err;
}
static int fsfilt_ext3_write_record(struct file *file, void *buf, int bufsize,
loff_t *offs, int force_sync)
{
struct inode *inode = file->f_dentry->d_inode;
handle_t *handle;
int err, block_count = 0, blocksize;
blocksize = 1 << inode->i_blkbits;
block_count = (*offs & (blocksize - 1)) + bufsize;
block_count = (block_count + blocksize - 1) >> inode->i_blkbits;
handle = ext3_journal_start(inode,
block_count * EXT3_DATA_TRANS_BLOCKS(inode->i_sb) + 2);
if (IS_ERR(handle)) {
CERROR("can't start transaction for %d blocks (%d bytes)\n",
block_count * EXT3_DATA_TRANS_BLOCKS(inode->i_sb) + 2,
bufsize);
return PTR_ERR(handle);
}
err = fsfilt_ext3_write_handle(inode, buf, bufsize, offs, handle);
if (!err && force_sync)
handle->h_sync = 1;
ext3_journal_stop(handle);
return err;
}
static int fsfilt_ext3_setup(struct super_block *sb)
{
if (!EXT3_HAS_COMPAT_FEATURE(sb,
EXT3_FEATURE_COMPAT_HAS_JOURNAL)) {
CERROR("ext3 mounted without journal\n");
return -EINVAL;
}
#ifdef S_PDIROPS
CWARN("Enabling PDIROPS\n");
set_opt(EXT3_SB(sb)->s_mount_opt, PDIROPS);
sb->s_flags |= S_PDIROPS;
#endif
if (!EXT3_HAS_COMPAT_FEATURE(sb, EXT3_FEATURE_COMPAT_DIR_INDEX))
CWARN("filesystem doesn't have dir_index feature enabled\n");
return 0;
}
static int __init fsfilt_ext3_init(void)
{
int rc;
fcb_cache = kmem_cache_create("fsfilt_ext3_fcb",
sizeof(struct fsfilt_cb_data), 0, 0);
if (!fcb_cache) {
CERROR("error allocating fsfilt journal callback cache\n");
GOTO(out, rc = -ENOMEM);
}
rc = fsfilt_register_ops(&fsfilt_ext3_ops);
if (rc) {
int err = kmem_cache_destroy(fcb_cache);
LASSERTF(err == 0, "error destroying new cache: rc %d\n", err);
}
out:
return rc;
}
static void __exit fsfilt_ext3_exit(void)
{
int rc;
fsfilt_unregister_ops(&fsfilt_ext3_ops);
rc = kmem_cache_destroy(fcb_cache);
LASSERTF(rc == 0, "couldn't destroy fcb_cache slab\n");
}
