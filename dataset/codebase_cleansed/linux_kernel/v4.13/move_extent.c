static inline int
get_ext_path(struct inode *inode, ext4_lblk_t lblock,
struct ext4_ext_path **ppath)
{
struct ext4_ext_path *path;
path = ext4_find_extent(inode, lblock, ppath, EXT4_EX_NOCACHE);
if (IS_ERR(path))
return PTR_ERR(path);
if (path[ext_depth(inode)].p_ext == NULL) {
ext4_ext_drop_refs(path);
kfree(path);
*ppath = NULL;
return -ENODATA;
}
*ppath = path;
return 0;
}
void
ext4_double_down_write_data_sem(struct inode *first, struct inode *second)
{
if (first < second) {
down_write(&EXT4_I(first)->i_data_sem);
down_write_nested(&EXT4_I(second)->i_data_sem, I_DATA_SEM_OTHER);
} else {
down_write(&EXT4_I(second)->i_data_sem);
down_write_nested(&EXT4_I(first)->i_data_sem, I_DATA_SEM_OTHER);
}
}
void
ext4_double_up_write_data_sem(struct inode *orig_inode,
struct inode *donor_inode)
{
up_write(&EXT4_I(orig_inode)->i_data_sem);
up_write(&EXT4_I(donor_inode)->i_data_sem);
}
static int
mext_check_coverage(struct inode *inode, ext4_lblk_t from, ext4_lblk_t count,
int unwritten, int *err)
{
struct ext4_ext_path *path = NULL;
struct ext4_extent *ext;
int ret = 0;
ext4_lblk_t last = from + count;
while (from < last) {
*err = get_ext_path(inode, from, &path);
if (*err)
goto out;
ext = path[ext_depth(inode)].p_ext;
if (unwritten != ext4_ext_is_unwritten(ext))
goto out;
from += ext4_ext_get_actual_len(ext);
ext4_ext_drop_refs(path);
}
ret = 1;
out:
ext4_ext_drop_refs(path);
kfree(path);
return ret;
}
static int
mext_page_double_lock(struct inode *inode1, struct inode *inode2,
pgoff_t index1, pgoff_t index2, struct page *page[2])
{
struct address_space *mapping[2];
unsigned fl = AOP_FLAG_NOFS;
BUG_ON(!inode1 || !inode2);
if (inode1 < inode2) {
mapping[0] = inode1->i_mapping;
mapping[1] = inode2->i_mapping;
} else {
pgoff_t tmp = index1;
index1 = index2;
index2 = tmp;
mapping[0] = inode2->i_mapping;
mapping[1] = inode1->i_mapping;
}
page[0] = grab_cache_page_write_begin(mapping[0], index1, fl);
if (!page[0])
return -ENOMEM;
page[1] = grab_cache_page_write_begin(mapping[1], index2, fl);
if (!page[1]) {
unlock_page(page[0]);
put_page(page[0]);
return -ENOMEM;
}
wait_on_page_writeback(page[0]);
wait_on_page_writeback(page[1]);
if (inode1 > inode2)
swap(page[0], page[1]);
return 0;
}
static int
mext_page_mkuptodate(struct page *page, unsigned from, unsigned to)
{
struct inode *inode = page->mapping->host;
sector_t block;
struct buffer_head *bh, *head, *arr[MAX_BUF_PER_PAGE];
unsigned int blocksize, block_start, block_end;
int i, err, nr = 0, partial = 0;
BUG_ON(!PageLocked(page));
BUG_ON(PageWriteback(page));
if (PageUptodate(page))
return 0;
blocksize = i_blocksize(inode);
if (!page_has_buffers(page))
create_empty_buffers(page, blocksize, 0);
head = page_buffers(page);
block = (sector_t)page->index << (PAGE_SHIFT - inode->i_blkbits);
for (bh = head, block_start = 0; bh != head || !block_start;
block++, block_start = block_end, bh = bh->b_this_page) {
block_end = block_start + blocksize;
if (block_end <= from || block_start >= to) {
if (!buffer_uptodate(bh))
partial = 1;
continue;
}
if (buffer_uptodate(bh))
continue;
if (!buffer_mapped(bh)) {
err = ext4_get_block(inode, block, bh, 0);
if (err) {
SetPageError(page);
return err;
}
if (!buffer_mapped(bh)) {
zero_user(page, block_start, blocksize);
set_buffer_uptodate(bh);
continue;
}
}
BUG_ON(nr >= MAX_BUF_PER_PAGE);
arr[nr++] = bh;
}
if (!nr)
goto out;
for (i = 0; i < nr; i++) {
bh = arr[i];
if (!bh_uptodate_or_lock(bh)) {
err = bh_submit_read(bh);
if (err)
return err;
}
}
out:
if (!partial)
SetPageUptodate(page);
return 0;
}
static int
move_extent_per_page(struct file *o_filp, struct inode *donor_inode,
pgoff_t orig_page_offset, pgoff_t donor_page_offset,
int data_offset_in_page,
int block_len_in_page, int unwritten, int *err)
{
struct inode *orig_inode = file_inode(o_filp);
struct page *pagep[2] = {NULL, NULL};
handle_t *handle;
ext4_lblk_t orig_blk_offset, donor_blk_offset;
unsigned long blocksize = orig_inode->i_sb->s_blocksize;
unsigned int tmp_data_size, data_size, replaced_size;
int i, err2, jblocks, retries = 0;
int replaced_count = 0;
int from = data_offset_in_page << orig_inode->i_blkbits;
int blocks_per_page = PAGE_SIZE >> orig_inode->i_blkbits;
struct super_block *sb = orig_inode->i_sb;
struct buffer_head *bh = NULL;
again:
*err = 0;
jblocks = ext4_writepage_trans_blocks(orig_inode) * 2;
handle = ext4_journal_start(orig_inode, EXT4_HT_MOVE_EXTENTS, jblocks);
if (IS_ERR(handle)) {
*err = PTR_ERR(handle);
return 0;
}
orig_blk_offset = orig_page_offset * blocks_per_page +
data_offset_in_page;
donor_blk_offset = donor_page_offset * blocks_per_page +
data_offset_in_page;
if ((orig_blk_offset + block_len_in_page - 1) ==
((orig_inode->i_size - 1) >> orig_inode->i_blkbits)) {
tmp_data_size = orig_inode->i_size & (blocksize - 1);
if (tmp_data_size == 0)
tmp_data_size = blocksize;
data_size = tmp_data_size +
((block_len_in_page - 1) << orig_inode->i_blkbits);
} else
data_size = block_len_in_page << orig_inode->i_blkbits;
replaced_size = data_size;
*err = mext_page_double_lock(orig_inode, donor_inode, orig_page_offset,
donor_page_offset, pagep);
if (unlikely(*err < 0))
goto stop_journal;
if (unwritten) {
ext4_double_down_write_data_sem(orig_inode, donor_inode);
unwritten = mext_check_coverage(orig_inode, orig_blk_offset,
block_len_in_page, 1, err);
if (*err)
goto drop_data_sem;
unwritten &= mext_check_coverage(donor_inode, donor_blk_offset,
block_len_in_page, 1, err);
if (*err)
goto drop_data_sem;
if (!unwritten) {
ext4_double_up_write_data_sem(orig_inode, donor_inode);
goto data_copy;
}
if ((page_has_private(pagep[0]) &&
!try_to_release_page(pagep[0], 0)) ||
(page_has_private(pagep[1]) &&
!try_to_release_page(pagep[1], 0))) {
*err = -EBUSY;
goto drop_data_sem;
}
replaced_count = ext4_swap_extents(handle, orig_inode,
donor_inode, orig_blk_offset,
donor_blk_offset,
block_len_in_page, 1, err);
drop_data_sem:
ext4_double_up_write_data_sem(orig_inode, donor_inode);
goto unlock_pages;
}
data_copy:
*err = mext_page_mkuptodate(pagep[0], from, from + replaced_size);
if (*err)
goto unlock_pages;
if ((page_has_private(pagep[0]) && !try_to_release_page(pagep[0], 0)) ||
(page_has_private(pagep[1]) && !try_to_release_page(pagep[1], 0))) {
*err = -EBUSY;
goto unlock_pages;
}
ext4_double_down_write_data_sem(orig_inode, donor_inode);
replaced_count = ext4_swap_extents(handle, orig_inode, donor_inode,
orig_blk_offset, donor_blk_offset,
block_len_in_page, 1, err);
ext4_double_up_write_data_sem(orig_inode, donor_inode);
if (*err) {
if (replaced_count) {
block_len_in_page = replaced_count;
replaced_size =
block_len_in_page << orig_inode->i_blkbits;
} else
goto unlock_pages;
}
if (!page_has_buffers(pagep[0]))
create_empty_buffers(pagep[0], 1 << orig_inode->i_blkbits, 0);
bh = page_buffers(pagep[0]);
for (i = 0; i < data_offset_in_page; i++)
bh = bh->b_this_page;
for (i = 0; i < block_len_in_page; i++) {
*err = ext4_get_block(orig_inode, orig_blk_offset + i, bh, 0);
if (*err < 0)
break;
bh = bh->b_this_page;
}
if (!*err)
*err = block_commit_write(pagep[0], from, from + replaced_size);
if (unlikely(*err < 0))
goto repair_branches;
*err = ext4_jbd2_inode_add_write(handle, orig_inode);
unlock_pages:
unlock_page(pagep[0]);
put_page(pagep[0]);
unlock_page(pagep[1]);
put_page(pagep[1]);
stop_journal:
ext4_journal_stop(handle);
if (*err == -ENOSPC &&
ext4_should_retry_alloc(sb, &retries))
goto again;
if (*err == -EBUSY && retries++ < 4 && EXT4_SB(sb)->s_journal &&
jbd2_journal_force_commit_nested(EXT4_SB(sb)->s_journal))
goto again;
return replaced_count;
repair_branches:
ext4_double_down_write_data_sem(orig_inode, donor_inode);
replaced_count = ext4_swap_extents(handle, donor_inode, orig_inode,
orig_blk_offset, donor_blk_offset,
block_len_in_page, 0, &err2);
ext4_double_up_write_data_sem(orig_inode, donor_inode);
if (replaced_count != block_len_in_page) {
EXT4_ERROR_INODE_BLOCK(orig_inode, (sector_t)(orig_blk_offset),
"Unable to copy data block,"
" data will be lost.");
*err = -EIO;
}
replaced_count = 0;
goto unlock_pages;
}
static int
mext_check_arguments(struct inode *orig_inode,
struct inode *donor_inode, __u64 orig_start,
__u64 donor_start, __u64 *len)
{
__u64 orig_eof, donor_eof;
unsigned int blkbits = orig_inode->i_blkbits;
unsigned int blocksize = 1 << blkbits;
orig_eof = (i_size_read(orig_inode) + blocksize - 1) >> blkbits;
donor_eof = (i_size_read(donor_inode) + blocksize - 1) >> blkbits;
if (donor_inode->i_mode & (S_ISUID|S_ISGID)) {
ext4_debug("ext4 move extent: suid or sgid is set"
" to donor file [ino:orig %lu, donor %lu]\n",
orig_inode->i_ino, donor_inode->i_ino);
return -EINVAL;
}
if (IS_IMMUTABLE(donor_inode) || IS_APPEND(donor_inode))
return -EPERM;
if (IS_SWAPFILE(orig_inode) || IS_SWAPFILE(donor_inode)) {
ext4_debug("ext4 move extent: The argument files should "
"not be swapfile [ino:orig %lu, donor %lu]\n",
orig_inode->i_ino, donor_inode->i_ino);
return -EBUSY;
}
if (ext4_is_quota_file(orig_inode) && ext4_is_quota_file(donor_inode)) {
ext4_debug("ext4 move extent: The argument files should "
"not be quota files [ino:orig %lu, donor %lu]\n",
orig_inode->i_ino, donor_inode->i_ino);
return -EBUSY;
}
if (!(ext4_test_inode_flag(orig_inode, EXT4_INODE_EXTENTS))) {
ext4_debug("ext4 move extent: orig file is not extents "
"based file [ino:orig %lu]\n", orig_inode->i_ino);
return -EOPNOTSUPP;
} else if (!(ext4_test_inode_flag(donor_inode, EXT4_INODE_EXTENTS))) {
ext4_debug("ext4 move extent: donor file is not extents "
"based file [ino:donor %lu]\n", donor_inode->i_ino);
return -EOPNOTSUPP;
}
if ((!orig_inode->i_size) || (!donor_inode->i_size)) {
ext4_debug("ext4 move extent: File size is 0 byte\n");
return -EINVAL;
}
if ((orig_start & ~(PAGE_MASK >> orig_inode->i_blkbits)) !=
(donor_start & ~(PAGE_MASK >> orig_inode->i_blkbits))) {
ext4_debug("ext4 move extent: orig and donor's start "
"offsets are not aligned [ino:orig %lu, donor %lu]\n",
orig_inode->i_ino, donor_inode->i_ino);
return -EINVAL;
}
if ((orig_start >= EXT_MAX_BLOCKS) ||
(donor_start >= EXT_MAX_BLOCKS) ||
(*len > EXT_MAX_BLOCKS) ||
(donor_start + *len >= EXT_MAX_BLOCKS) ||
(orig_start + *len >= EXT_MAX_BLOCKS)) {
ext4_debug("ext4 move extent: Can't handle over [%u] blocks "
"[ino:orig %lu, donor %lu]\n", EXT_MAX_BLOCKS,
orig_inode->i_ino, donor_inode->i_ino);
return -EINVAL;
}
if (orig_eof < orig_start + *len - 1)
*len = orig_eof - orig_start;
if (donor_eof < donor_start + *len - 1)
*len = donor_eof - donor_start;
if (!*len) {
ext4_debug("ext4 move extent: len should not be 0 "
"[ino:orig %lu, donor %lu]\n", orig_inode->i_ino,
donor_inode->i_ino);
return -EINVAL;
}
return 0;
}
int
ext4_move_extents(struct file *o_filp, struct file *d_filp, __u64 orig_blk,
__u64 donor_blk, __u64 len, __u64 *moved_len)
{
struct inode *orig_inode = file_inode(o_filp);
struct inode *donor_inode = file_inode(d_filp);
struct ext4_ext_path *path = NULL;
int blocks_per_page = PAGE_SIZE >> orig_inode->i_blkbits;
ext4_lblk_t o_end, o_start = orig_blk;
ext4_lblk_t d_start = donor_blk;
int ret;
if (orig_inode->i_sb != donor_inode->i_sb) {
ext4_debug("ext4 move extent: The argument files "
"should be in same FS [ino:orig %lu, donor %lu]\n",
orig_inode->i_ino, donor_inode->i_ino);
return -EINVAL;
}
if (orig_inode == donor_inode) {
ext4_debug("ext4 move extent: The argument files should not "
"be same inode [ino:orig %lu, donor %lu]\n",
orig_inode->i_ino, donor_inode->i_ino);
return -EINVAL;
}
if (!S_ISREG(orig_inode->i_mode) || !S_ISREG(donor_inode->i_mode)) {
ext4_debug("ext4 move extent: The argument files should be "
"regular file [ino:orig %lu, donor %lu]\n",
orig_inode->i_ino, donor_inode->i_ino);
return -EINVAL;
}
if (ext4_should_journal_data(orig_inode) ||
ext4_should_journal_data(donor_inode)) {
ext4_msg(orig_inode->i_sb, KERN_ERR,
"Online defrag not supported with data journaling");
return -EOPNOTSUPP;
}
if (ext4_encrypted_inode(orig_inode) ||
ext4_encrypted_inode(donor_inode)) {
ext4_msg(orig_inode->i_sb, KERN_ERR,
"Online defrag not supported for encrypted files");
return -EOPNOTSUPP;
}
lock_two_nondirectories(orig_inode, donor_inode);
ext4_inode_block_unlocked_dio(orig_inode);
ext4_inode_block_unlocked_dio(donor_inode);
inode_dio_wait(orig_inode);
inode_dio_wait(donor_inode);
ext4_double_down_write_data_sem(orig_inode, donor_inode);
ret = mext_check_arguments(orig_inode, donor_inode, orig_blk,
donor_blk, &len);
if (ret)
goto out;
o_end = o_start + len;
while (o_start < o_end) {
struct ext4_extent *ex;
ext4_lblk_t cur_blk, next_blk;
pgoff_t orig_page_index, donor_page_index;
int offset_in_page;
int unwritten, cur_len;
ret = get_ext_path(orig_inode, o_start, &path);
if (ret)
goto out;
ex = path[path->p_depth].p_ext;
next_blk = ext4_ext_next_allocated_block(path);
cur_blk = le32_to_cpu(ex->ee_block);
cur_len = ext4_ext_get_actual_len(ex);
if (cur_blk + cur_len - 1 < o_start) {
if (next_blk == EXT_MAX_BLOCKS) {
o_start = o_end;
ret = -ENODATA;
goto out;
}
d_start += next_blk - o_start;
o_start = next_blk;
continue;
} else if (cur_blk > o_start) {
d_start += cur_blk - o_start;
o_start = cur_blk;
if (cur_blk >= o_end)
goto out;
} else {
cur_len += cur_blk - o_start;
}
unwritten = ext4_ext_is_unwritten(ex);
if (o_end - o_start < cur_len)
cur_len = o_end - o_start;
orig_page_index = o_start >> (PAGE_SHIFT -
orig_inode->i_blkbits);
donor_page_index = d_start >> (PAGE_SHIFT -
donor_inode->i_blkbits);
offset_in_page = o_start % blocks_per_page;
if (cur_len > blocks_per_page- offset_in_page)
cur_len = blocks_per_page - offset_in_page;
ext4_double_up_write_data_sem(orig_inode, donor_inode);
move_extent_per_page(o_filp, donor_inode,
orig_page_index, donor_page_index,
offset_in_page, cur_len,
unwritten, &ret);
ext4_double_down_write_data_sem(orig_inode, donor_inode);
if (ret < 0)
break;
o_start += cur_len;
d_start += cur_len;
}
*moved_len = o_start - orig_blk;
if (*moved_len > len)
*moved_len = len;
out:
if (*moved_len) {
ext4_discard_preallocations(orig_inode);
ext4_discard_preallocations(donor_inode);
}
ext4_ext_drop_refs(path);
kfree(path);
ext4_double_up_write_data_sem(orig_inode, donor_inode);
ext4_inode_resume_unlocked_dio(orig_inode);
ext4_inode_resume_unlocked_dio(donor_inode);
unlock_two_nondirectories(orig_inode, donor_inode);
return ret;
}
