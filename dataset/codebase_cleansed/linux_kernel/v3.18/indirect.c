static inline void add_chain(Indirect *p, struct buffer_head *bh, __le32 *v)
{
p->key = *(p->p = v);
p->bh = bh;
}
static int ext4_block_to_path(struct inode *inode,
ext4_lblk_t i_block,
ext4_lblk_t offsets[4], int *boundary)
{
int ptrs = EXT4_ADDR_PER_BLOCK(inode->i_sb);
int ptrs_bits = EXT4_ADDR_PER_BLOCK_BITS(inode->i_sb);
const long direct_blocks = EXT4_NDIR_BLOCKS,
indirect_blocks = ptrs,
double_blocks = (1 << (ptrs_bits * 2));
int n = 0;
int final = 0;
if (i_block < direct_blocks) {
offsets[n++] = i_block;
final = direct_blocks;
} else if ((i_block -= direct_blocks) < indirect_blocks) {
offsets[n++] = EXT4_IND_BLOCK;
offsets[n++] = i_block;
final = ptrs;
} else if ((i_block -= indirect_blocks) < double_blocks) {
offsets[n++] = EXT4_DIND_BLOCK;
offsets[n++] = i_block >> ptrs_bits;
offsets[n++] = i_block & (ptrs - 1);
final = ptrs;
} else if (((i_block -= double_blocks) >> (ptrs_bits * 2)) < ptrs) {
offsets[n++] = EXT4_TIND_BLOCK;
offsets[n++] = i_block >> (ptrs_bits * 2);
offsets[n++] = (i_block >> ptrs_bits) & (ptrs - 1);
offsets[n++] = i_block & (ptrs - 1);
final = ptrs;
} else {
ext4_warning(inode->i_sb, "block %lu > max in inode %lu",
i_block + direct_blocks +
indirect_blocks + double_blocks, inode->i_ino);
}
if (boundary)
*boundary = final - 1 - (i_block & (ptrs - 1));
return n;
}
static Indirect *ext4_get_branch(struct inode *inode, int depth,
ext4_lblk_t *offsets,
Indirect chain[4], int *err)
{
struct super_block *sb = inode->i_sb;
Indirect *p = chain;
struct buffer_head *bh;
int ret = -EIO;
*err = 0;
add_chain(chain, NULL, EXT4_I(inode)->i_data + *offsets);
if (!p->key)
goto no_block;
while (--depth) {
bh = sb_getblk(sb, le32_to_cpu(p->key));
if (unlikely(!bh)) {
ret = -ENOMEM;
goto failure;
}
if (!bh_uptodate_or_lock(bh)) {
if (bh_submit_read(bh) < 0) {
put_bh(bh);
goto failure;
}
if (ext4_check_indirect_blockref(inode, bh)) {
put_bh(bh);
goto failure;
}
}
add_chain(++p, bh, (__le32 *)bh->b_data + *++offsets);
if (!p->key)
goto no_block;
}
return NULL;
failure:
*err = ret;
no_block:
return p;
}
static ext4_fsblk_t ext4_find_near(struct inode *inode, Indirect *ind)
{
struct ext4_inode_info *ei = EXT4_I(inode);
__le32 *start = ind->bh ? (__le32 *) ind->bh->b_data : ei->i_data;
__le32 *p;
for (p = ind->p - 1; p >= start; p--) {
if (*p)
return le32_to_cpu(*p);
}
if (ind->bh)
return ind->bh->b_blocknr;
return ext4_inode_to_goal_block(inode);
}
static ext4_fsblk_t ext4_find_goal(struct inode *inode, ext4_lblk_t block,
Indirect *partial)
{
ext4_fsblk_t goal;
goal = ext4_find_near(inode, partial);
goal = goal & EXT4_MAX_BLOCK_FILE_PHYS;
return goal;
}
static int ext4_blks_to_allocate(Indirect *branch, int k, unsigned int blks,
int blocks_to_boundary)
{
unsigned int count = 0;
if (k > 0) {
if (blks < blocks_to_boundary + 1)
count += blks;
else
count += blocks_to_boundary + 1;
return count;
}
count++;
while (count < blks && count <= blocks_to_boundary &&
le32_to_cpu(*(branch[0].p + count)) == 0) {
count++;
}
return count;
}
static int ext4_alloc_branch(handle_t *handle,
struct ext4_allocation_request *ar,
int indirect_blks, ext4_lblk_t *offsets,
Indirect *branch)
{
struct buffer_head * bh;
ext4_fsblk_t b, new_blocks[4];
__le32 *p;
int i, j, err, len = 1;
for (i = 0; i <= indirect_blks; i++) {
if (i == indirect_blks) {
new_blocks[i] = ext4_mb_new_blocks(handle, ar, &err);
} else
ar->goal = new_blocks[i] = ext4_new_meta_blocks(handle,
ar->inode, ar->goal,
ar->flags & EXT4_MB_DELALLOC_RESERVED,
NULL, &err);
if (err) {
i--;
goto failed;
}
branch[i].key = cpu_to_le32(new_blocks[i]);
if (i == 0)
continue;
bh = branch[i].bh = sb_getblk(ar->inode->i_sb, new_blocks[i-1]);
if (unlikely(!bh)) {
err = -ENOMEM;
goto failed;
}
lock_buffer(bh);
BUFFER_TRACE(bh, "call get_create_access");
err = ext4_journal_get_create_access(handle, bh);
if (err) {
unlock_buffer(bh);
goto failed;
}
memset(bh->b_data, 0, bh->b_size);
p = branch[i].p = (__le32 *) bh->b_data + offsets[i];
b = new_blocks[i];
if (i == indirect_blks)
len = ar->len;
for (j = 0; j < len; j++)
*p++ = cpu_to_le32(b++);
BUFFER_TRACE(bh, "marking uptodate");
set_buffer_uptodate(bh);
unlock_buffer(bh);
BUFFER_TRACE(bh, "call ext4_handle_dirty_metadata");
err = ext4_handle_dirty_metadata(handle, ar->inode, bh);
if (err)
goto failed;
}
return 0;
failed:
for (; i >= 0; i--) {
if (i > 0 && i != indirect_blks && branch[i].bh)
ext4_forget(handle, 1, ar->inode, branch[i].bh,
branch[i].bh->b_blocknr);
ext4_free_blocks(handle, ar->inode, NULL, new_blocks[i],
(i == indirect_blks) ? ar->len : 1, 0);
}
return err;
}
static int ext4_splice_branch(handle_t *handle,
struct ext4_allocation_request *ar,
Indirect *where, int num)
{
int i;
int err = 0;
ext4_fsblk_t current_block;
if (where->bh) {
BUFFER_TRACE(where->bh, "get_write_access");
err = ext4_journal_get_write_access(handle, where->bh);
if (err)
goto err_out;
}
*where->p = where->key;
if (num == 0 && ar->len > 1) {
current_block = le32_to_cpu(where->key) + 1;
for (i = 1; i < ar->len; i++)
*(where->p + i) = cpu_to_le32(current_block++);
}
if (where->bh) {
jbd_debug(5, "splicing indirect only\n");
BUFFER_TRACE(where->bh, "call ext4_handle_dirty_metadata");
err = ext4_handle_dirty_metadata(handle, ar->inode, where->bh);
if (err)
goto err_out;
} else {
ext4_mark_inode_dirty(handle, ar->inode);
jbd_debug(5, "splicing direct\n");
}
return err;
err_out:
for (i = 1; i <= num; i++) {
ext4_free_blocks(handle, ar->inode, where[i].bh, 0, 1,
EXT4_FREE_BLOCKS_FORGET);
}
ext4_free_blocks(handle, ar->inode, NULL, le32_to_cpu(where[num].key),
ar->len, 0);
return err;
}
int ext4_ind_map_blocks(handle_t *handle, struct inode *inode,
struct ext4_map_blocks *map,
int flags)
{
struct ext4_allocation_request ar;
int err = -EIO;
ext4_lblk_t offsets[4];
Indirect chain[4];
Indirect *partial;
int indirect_blks;
int blocks_to_boundary = 0;
int depth;
int count = 0;
ext4_fsblk_t first_block = 0;
trace_ext4_ind_map_blocks_enter(inode, map->m_lblk, map->m_len, flags);
J_ASSERT(!(ext4_test_inode_flag(inode, EXT4_INODE_EXTENTS)));
J_ASSERT(handle != NULL || (flags & EXT4_GET_BLOCKS_CREATE) == 0);
depth = ext4_block_to_path(inode, map->m_lblk, offsets,
&blocks_to_boundary);
if (depth == 0)
goto out;
partial = ext4_get_branch(inode, depth, offsets, chain, &err);
if (!partial) {
first_block = le32_to_cpu(chain[depth - 1].key);
count++;
while (count < map->m_len && count <= blocks_to_boundary) {
ext4_fsblk_t blk;
blk = le32_to_cpu(*(chain[depth-1].p + count));
if (blk == first_block + count)
count++;
else
break;
}
goto got_it;
}
if ((flags & EXT4_GET_BLOCKS_CREATE) == 0 || err == -EIO)
goto cleanup;
if (EXT4_HAS_RO_COMPAT_FEATURE(inode->i_sb,
EXT4_FEATURE_RO_COMPAT_BIGALLOC)) {
EXT4_ERROR_INODE(inode, "Can't allocate blocks for "
"non-extent mapped inodes with bigalloc");
return -ENOSPC;
}
memset(&ar, 0, sizeof(ar));
ar.inode = inode;
ar.logical = map->m_lblk;
if (S_ISREG(inode->i_mode))
ar.flags = EXT4_MB_HINT_DATA;
if (flags & EXT4_GET_BLOCKS_DELALLOC_RESERVE)
ar.flags |= EXT4_MB_DELALLOC_RESERVED;
ar.goal = ext4_find_goal(inode, map->m_lblk, partial);
indirect_blks = (chain + depth) - partial - 1;
ar.len = ext4_blks_to_allocate(partial, indirect_blks,
map->m_len, blocks_to_boundary);
err = ext4_alloc_branch(handle, &ar, indirect_blks,
offsets + (partial - chain), partial);
if (!err)
err = ext4_splice_branch(handle, &ar, partial, indirect_blks);
if (err)
goto cleanup;
map->m_flags |= EXT4_MAP_NEW;
ext4_update_inode_fsync_trans(handle, inode, 1);
count = ar.len;
got_it:
map->m_flags |= EXT4_MAP_MAPPED;
map->m_pblk = le32_to_cpu(chain[depth-1].key);
map->m_len = count;
if (count > blocks_to_boundary)
map->m_flags |= EXT4_MAP_BOUNDARY;
err = count;
partial = chain + depth - 1;
cleanup:
while (partial > chain) {
BUFFER_TRACE(partial->bh, "call brelse");
brelse(partial->bh);
partial--;
}
out:
trace_ext4_ind_map_blocks_exit(inode, flags, map, err);
return err;
}
ssize_t ext4_ind_direct_IO(int rw, struct kiocb *iocb,
struct iov_iter *iter, loff_t offset)
{
struct file *file = iocb->ki_filp;
struct inode *inode = file->f_mapping->host;
struct ext4_inode_info *ei = EXT4_I(inode);
handle_t *handle;
ssize_t ret;
int orphan = 0;
size_t count = iov_iter_count(iter);
int retries = 0;
if (rw == WRITE) {
loff_t final_size = offset + count;
if (final_size > inode->i_size) {
handle = ext4_journal_start(inode, EXT4_HT_INODE, 2);
if (IS_ERR(handle)) {
ret = PTR_ERR(handle);
goto out;
}
ret = ext4_orphan_add(handle, inode);
if (ret) {
ext4_journal_stop(handle);
goto out;
}
orphan = 1;
ei->i_disksize = inode->i_size;
ext4_journal_stop(handle);
}
}
retry:
if (rw == READ && ext4_should_dioread_nolock(inode)) {
atomic_inc(&inode->i_dio_count);
smp_mb();
if (unlikely(ext4_test_inode_state(inode,
EXT4_STATE_DIOREAD_LOCK))) {
inode_dio_done(inode);
goto locked;
}
ret = __blockdev_direct_IO(rw, iocb, inode,
inode->i_sb->s_bdev, iter, offset,
ext4_get_block, NULL, NULL, 0);
inode_dio_done(inode);
} else {
locked:
ret = blockdev_direct_IO(rw, iocb, inode, iter,
offset, ext4_get_block);
if (unlikely((rw & WRITE) && ret < 0)) {
loff_t isize = i_size_read(inode);
loff_t end = offset + count;
if (end > isize)
ext4_truncate_failed_write(inode);
}
}
if (ret == -ENOSPC && ext4_should_retry_alloc(inode->i_sb, &retries))
goto retry;
if (orphan) {
int err;
handle = ext4_journal_start(inode, EXT4_HT_INODE, 2);
if (IS_ERR(handle)) {
ret = PTR_ERR(handle);
if (inode->i_nlink)
ext4_orphan_del(NULL, inode);
goto out;
}
if (inode->i_nlink)
ext4_orphan_del(handle, inode);
if (ret > 0) {
loff_t end = offset + ret;
if (end > inode->i_size) {
ei->i_disksize = end;
i_size_write(inode, end);
ext4_mark_inode_dirty(handle, inode);
}
}
err = ext4_journal_stop(handle);
if (ret == 0)
ret = err;
}
out:
return ret;
}
int ext4_ind_calc_metadata_amount(struct inode *inode, sector_t lblock)
{
struct ext4_inode_info *ei = EXT4_I(inode);
sector_t dind_mask = ~((sector_t)EXT4_ADDR_PER_BLOCK(inode->i_sb) - 1);
int blk_bits;
if (lblock < EXT4_NDIR_BLOCKS)
return 0;
lblock -= EXT4_NDIR_BLOCKS;
if (ei->i_da_metadata_calc_len &&
(lblock & dind_mask) == ei->i_da_metadata_calc_last_lblock) {
ei->i_da_metadata_calc_len++;
return 0;
}
ei->i_da_metadata_calc_last_lblock = lblock & dind_mask;
ei->i_da_metadata_calc_len = 1;
blk_bits = order_base_2(lblock);
return (blk_bits / EXT4_ADDR_PER_BLOCK_BITS(inode->i_sb)) + 1;
}
int ext4_ind_trans_blocks(struct inode *inode, int nrblocks)
{
return DIV_ROUND_UP(nrblocks, EXT4_ADDR_PER_BLOCK(inode->i_sb)) + 4;
}
static int try_to_extend_transaction(handle_t *handle, struct inode *inode)
{
if (!ext4_handle_valid(handle))
return 0;
if (ext4_handle_has_enough_credits(handle, EXT4_RESERVE_TRANS_BLOCKS+1))
return 0;
if (!ext4_journal_extend(handle, ext4_blocks_for_truncate(inode)))
return 0;
return 1;
}
static inline int all_zeroes(__le32 *p, __le32 *q)
{
while (p < q)
if (*p++)
return 0;
return 1;
}
static Indirect *ext4_find_shared(struct inode *inode, int depth,
ext4_lblk_t offsets[4], Indirect chain[4],
__le32 *top)
{
Indirect *partial, *p;
int k, err;
*top = 0;
for (k = depth; k > 1 && !offsets[k-1]; k--)
;
partial = ext4_get_branch(inode, k, offsets, chain, &err);
if (!partial)
partial = chain + k-1;
if (!partial->key && *partial->p)
goto no_top;
for (p = partial; (p > chain) && all_zeroes((__le32 *) p->bh->b_data, p->p); p--)
;
if (p == chain + k - 1 && p > chain) {
p->p--;
} else {
*top = *p->p;
#if 0
*p->p = 0;
#endif
}
while (partial > p) {
brelse(partial->bh);
partial--;
}
no_top:
return partial;
}
static int ext4_clear_blocks(handle_t *handle, struct inode *inode,
struct buffer_head *bh,
ext4_fsblk_t block_to_free,
unsigned long count, __le32 *first,
__le32 *last)
{
__le32 *p;
int flags = EXT4_FREE_BLOCKS_VALIDATED;
int err;
if (S_ISDIR(inode->i_mode) || S_ISLNK(inode->i_mode))
flags |= EXT4_FREE_BLOCKS_FORGET | EXT4_FREE_BLOCKS_METADATA;
else if (ext4_should_journal_data(inode))
flags |= EXT4_FREE_BLOCKS_FORGET;
if (!ext4_data_block_valid(EXT4_SB(inode->i_sb), block_to_free,
count)) {
EXT4_ERROR_INODE(inode, "attempt to clear invalid "
"blocks %llu len %lu",
(unsigned long long) block_to_free, count);
return 1;
}
if (try_to_extend_transaction(handle, inode)) {
if (bh) {
BUFFER_TRACE(bh, "call ext4_handle_dirty_metadata");
err = ext4_handle_dirty_metadata(handle, inode, bh);
if (unlikely(err))
goto out_err;
}
err = ext4_mark_inode_dirty(handle, inode);
if (unlikely(err))
goto out_err;
err = ext4_truncate_restart_trans(handle, inode,
ext4_blocks_for_truncate(inode));
if (unlikely(err))
goto out_err;
if (bh) {
BUFFER_TRACE(bh, "retaking write access");
err = ext4_journal_get_write_access(handle, bh);
if (unlikely(err))
goto out_err;
}
}
for (p = first; p < last; p++)
*p = 0;
ext4_free_blocks(handle, inode, NULL, block_to_free, count, flags);
return 0;
out_err:
ext4_std_error(inode->i_sb, err);
return err;
}
static void ext4_free_data(handle_t *handle, struct inode *inode,
struct buffer_head *this_bh,
__le32 *first, __le32 *last)
{
ext4_fsblk_t block_to_free = 0;
unsigned long count = 0;
__le32 *block_to_free_p = NULL;
ext4_fsblk_t nr;
__le32 *p;
int err = 0;
if (this_bh) {
BUFFER_TRACE(this_bh, "get_write_access");
err = ext4_journal_get_write_access(handle, this_bh);
if (err)
return;
}
for (p = first; p < last; p++) {
nr = le32_to_cpu(*p);
if (nr) {
if (count == 0) {
block_to_free = nr;
block_to_free_p = p;
count = 1;
} else if (nr == block_to_free + count) {
count++;
} else {
err = ext4_clear_blocks(handle, inode, this_bh,
block_to_free, count,
block_to_free_p, p);
if (err)
break;
block_to_free = nr;
block_to_free_p = p;
count = 1;
}
}
}
if (!err && count > 0)
err = ext4_clear_blocks(handle, inode, this_bh, block_to_free,
count, block_to_free_p, p);
if (err < 0)
return;
if (this_bh) {
BUFFER_TRACE(this_bh, "call ext4_handle_dirty_metadata");
if ((EXT4_JOURNAL(inode) == NULL) || bh2jh(this_bh))
ext4_handle_dirty_metadata(handle, inode, this_bh);
else
EXT4_ERROR_INODE(inode,
"circular indirect block detected at "
"block %llu",
(unsigned long long) this_bh->b_blocknr);
}
}
static void ext4_free_branches(handle_t *handle, struct inode *inode,
struct buffer_head *parent_bh,
__le32 *first, __le32 *last, int depth)
{
ext4_fsblk_t nr;
__le32 *p;
if (ext4_handle_is_aborted(handle))
return;
if (depth--) {
struct buffer_head *bh;
int addr_per_block = EXT4_ADDR_PER_BLOCK(inode->i_sb);
p = last;
while (--p >= first) {
nr = le32_to_cpu(*p);
if (!nr)
continue;
if (!ext4_data_block_valid(EXT4_SB(inode->i_sb),
nr, 1)) {
EXT4_ERROR_INODE(inode,
"invalid indirect mapped "
"block %lu (level %d)",
(unsigned long) nr, depth);
break;
}
bh = sb_bread(inode->i_sb, nr);
if (!bh) {
EXT4_ERROR_INODE_BLOCK(inode, nr,
"Read failure");
continue;
}
BUFFER_TRACE(bh, "free child branches");
ext4_free_branches(handle, inode, bh,
(__le32 *) bh->b_data,
(__le32 *) bh->b_data + addr_per_block,
depth);
brelse(bh);
if (ext4_handle_is_aborted(handle))
return;
if (try_to_extend_transaction(handle, inode)) {
ext4_mark_inode_dirty(handle, inode);
ext4_truncate_restart_trans(handle, inode,
ext4_blocks_for_truncate(inode));
}
ext4_free_blocks(handle, inode, NULL, nr, 1,
EXT4_FREE_BLOCKS_METADATA|
EXT4_FREE_BLOCKS_FORGET);
if (parent_bh) {
BUFFER_TRACE(parent_bh, "get_write_access");
if (!ext4_journal_get_write_access(handle,
parent_bh)){
*p = 0;
BUFFER_TRACE(parent_bh,
"call ext4_handle_dirty_metadata");
ext4_handle_dirty_metadata(handle,
inode,
parent_bh);
}
}
}
} else {
BUFFER_TRACE(parent_bh, "free data blocks");
ext4_free_data(handle, inode, parent_bh, first, last);
}
}
void ext4_ind_truncate(handle_t *handle, struct inode *inode)
{
struct ext4_inode_info *ei = EXT4_I(inode);
__le32 *i_data = ei->i_data;
int addr_per_block = EXT4_ADDR_PER_BLOCK(inode->i_sb);
ext4_lblk_t offsets[4];
Indirect chain[4];
Indirect *partial;
__le32 nr = 0;
int n = 0;
ext4_lblk_t last_block, max_block;
unsigned blocksize = inode->i_sb->s_blocksize;
last_block = (inode->i_size + blocksize-1)
>> EXT4_BLOCK_SIZE_BITS(inode->i_sb);
max_block = (EXT4_SB(inode->i_sb)->s_bitmap_maxbytes + blocksize-1)
>> EXT4_BLOCK_SIZE_BITS(inode->i_sb);
if (last_block != max_block) {
n = ext4_block_to_path(inode, last_block, offsets, NULL);
if (n == 0)
return;
}
ext4_es_remove_extent(inode, last_block, EXT_MAX_BLOCKS - last_block);
ei->i_disksize = inode->i_size;
if (last_block == max_block) {
return;
} else if (n == 1) {
ext4_free_data(handle, inode, NULL, i_data+offsets[0],
i_data + EXT4_NDIR_BLOCKS);
goto do_indirects;
}
partial = ext4_find_shared(inode, n, offsets, chain, &nr);
if (nr) {
if (partial == chain) {
ext4_free_branches(handle, inode, NULL,
&nr, &nr+1, (chain+n-1) - partial);
*partial->p = 0;
} else {
BUFFER_TRACE(partial->bh, "get_write_access");
ext4_free_branches(handle, inode, partial->bh,
partial->p,
partial->p+1, (chain+n-1) - partial);
}
}
while (partial > chain) {
ext4_free_branches(handle, inode, partial->bh, partial->p + 1,
(__le32*)partial->bh->b_data+addr_per_block,
(chain+n-1) - partial);
BUFFER_TRACE(partial->bh, "call brelse");
brelse(partial->bh);
partial--;
}
do_indirects:
switch (offsets[0]) {
default:
nr = i_data[EXT4_IND_BLOCK];
if (nr) {
ext4_free_branches(handle, inode, NULL, &nr, &nr+1, 1);
i_data[EXT4_IND_BLOCK] = 0;
}
case EXT4_IND_BLOCK:
nr = i_data[EXT4_DIND_BLOCK];
if (nr) {
ext4_free_branches(handle, inode, NULL, &nr, &nr+1, 2);
i_data[EXT4_DIND_BLOCK] = 0;
}
case EXT4_DIND_BLOCK:
nr = i_data[EXT4_TIND_BLOCK];
if (nr) {
ext4_free_branches(handle, inode, NULL, &nr, &nr+1, 3);
i_data[EXT4_TIND_BLOCK] = 0;
}
case EXT4_TIND_BLOCK:
;
}
}
int ext4_ind_remove_space(handle_t *handle, struct inode *inode,
ext4_lblk_t start, ext4_lblk_t end)
{
struct ext4_inode_info *ei = EXT4_I(inode);
__le32 *i_data = ei->i_data;
int addr_per_block = EXT4_ADDR_PER_BLOCK(inode->i_sb);
ext4_lblk_t offsets[4], offsets2[4];
Indirect chain[4], chain2[4];
Indirect *partial, *partial2;
ext4_lblk_t max_block;
__le32 nr = 0, nr2 = 0;
int n = 0, n2 = 0;
unsigned blocksize = inode->i_sb->s_blocksize;
max_block = (EXT4_SB(inode->i_sb)->s_bitmap_maxbytes + blocksize-1)
>> EXT4_BLOCK_SIZE_BITS(inode->i_sb);
if (end >= max_block)
end = max_block;
if ((start >= end) || (start > max_block))
return 0;
n = ext4_block_to_path(inode, start, offsets, NULL);
n2 = ext4_block_to_path(inode, end, offsets2, NULL);
BUG_ON(n > n2);
if ((n == 1) && (n == n2)) {
ext4_free_data(handle, inode, NULL, i_data + offsets[0],
i_data + offsets2[0]);
return 0;
} else if (n2 > n) {
if (n == 1) {
ext4_free_data(handle, inode, NULL, i_data + offsets[0],
i_data + EXT4_NDIR_BLOCKS);
goto end_range;
}
partial = ext4_find_shared(inode, n, offsets, chain, &nr);
if (nr) {
if (partial == chain) {
ext4_free_branches(handle, inode, NULL,
&nr, &nr+1, (chain+n-1) - partial);
*partial->p = 0;
} else {
BUFFER_TRACE(partial->bh, "get_write_access");
ext4_free_branches(handle, inode, partial->bh,
partial->p,
partial->p+1, (chain+n-1) - partial);
}
}
while (partial > chain) {
ext4_free_branches(handle, inode, partial->bh,
partial->p + 1,
(__le32 *)partial->bh->b_data+addr_per_block,
(chain+n-1) - partial);
BUFFER_TRACE(partial->bh, "call brelse");
brelse(partial->bh);
partial--;
}
end_range:
partial2 = ext4_find_shared(inode, n2, offsets2, chain2, &nr2);
if (nr2) {
if (partial2 == chain2) {
return 0;
} else {
partial2--;
}
} else {
partial2->p++;
}
while (partial2 > chain2) {
ext4_free_branches(handle, inode, partial2->bh,
(__le32 *)partial2->bh->b_data,
partial2->p,
(chain2+n2-1) - partial2);
BUFFER_TRACE(partial2->bh, "call brelse");
brelse(partial2->bh);
partial2--;
}
goto do_indirects;
}
partial = ext4_find_shared(inode, n, offsets, chain, &nr);
partial2 = ext4_find_shared(inode, n2, offsets2, chain2, &nr2);
partial2->p++;
while ((partial > chain) || (partial2 > chain2)) {
if ((partial->bh && partial2->bh) &&
(partial->bh->b_blocknr == partial2->bh->b_blocknr)) {
if ((partial > chain) && (partial2 > chain2)) {
ext4_free_branches(handle, inode, partial->bh,
partial->p + 1,
partial2->p,
(chain+n-1) - partial);
BUFFER_TRACE(partial->bh, "call brelse");
brelse(partial->bh);
BUFFER_TRACE(partial2->bh, "call brelse");
brelse(partial2->bh);
}
return 0;
}
if (partial > chain) {
ext4_free_branches(handle, inode, partial->bh,
partial->p + 1,
(__le32 *)partial->bh->b_data+addr_per_block,
(chain+n-1) - partial);
BUFFER_TRACE(partial->bh, "call brelse");
brelse(partial->bh);
partial--;
}
if (partial2 > chain2) {
ext4_free_branches(handle, inode, partial2->bh,
(__le32 *)partial2->bh->b_data,
partial2->p,
(chain2+n-1) - partial2);
BUFFER_TRACE(partial2->bh, "call brelse");
brelse(partial2->bh);
partial2--;
}
}
do_indirects:
switch (offsets[0]) {
default:
if (++n >= n2)
return 0;
nr = i_data[EXT4_IND_BLOCK];
if (nr) {
ext4_free_branches(handle, inode, NULL, &nr, &nr+1, 1);
i_data[EXT4_IND_BLOCK] = 0;
}
case EXT4_IND_BLOCK:
if (++n >= n2)
return 0;
nr = i_data[EXT4_DIND_BLOCK];
if (nr) {
ext4_free_branches(handle, inode, NULL, &nr, &nr+1, 2);
i_data[EXT4_DIND_BLOCK] = 0;
}
case EXT4_DIND_BLOCK:
if (++n >= n2)
return 0;
nr = i_data[EXT4_TIND_BLOCK];
if (nr) {
ext4_free_branches(handle, inode, NULL, &nr, &nr+1, 3);
i_data[EXT4_TIND_BLOCK] = 0;
}
case EXT4_TIND_BLOCK:
;
}
return 0;
}
