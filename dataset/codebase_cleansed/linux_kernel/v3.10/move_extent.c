static inline int
get_ext_path(struct inode *inode, ext4_lblk_t lblock,
struct ext4_ext_path **orig_path)
{
int ret = 0;
struct ext4_ext_path *path;
path = ext4_ext_find_extent(inode, lblock, *orig_path);
if (IS_ERR(path))
ret = PTR_ERR(path);
else if (path[ext_depth(inode)].p_ext == NULL)
ret = -ENODATA;
else
*orig_path = path;
return ret;
}
static void
copy_extent_status(struct ext4_extent *src, struct ext4_extent *dest)
{
if (ext4_ext_is_uninitialized(src))
ext4_ext_mark_uninitialized(dest);
else
dest->ee_len = cpu_to_le16(ext4_ext_get_actual_len(dest));
}
static int
mext_next_extent(struct inode *inode, struct ext4_ext_path *path,
struct ext4_extent **extent)
{
struct ext4_extent_header *eh;
int ppos, leaf_ppos = path->p_depth;
ppos = leaf_ppos;
if (EXT_LAST_EXTENT(path[ppos].p_hdr) > path[ppos].p_ext) {
*extent = ++path[ppos].p_ext;
path[ppos].p_block = ext4_ext_pblock(path[ppos].p_ext);
return 0;
}
while (--ppos >= 0) {
if (EXT_LAST_INDEX(path[ppos].p_hdr) >
path[ppos].p_idx) {
int cur_ppos = ppos;
path[ppos].p_idx++;
path[ppos].p_block = ext4_idx_pblock(path[ppos].p_idx);
if (path[ppos+1].p_bh)
brelse(path[ppos+1].p_bh);
path[ppos+1].p_bh =
sb_bread(inode->i_sb, path[ppos].p_block);
if (!path[ppos+1].p_bh)
return -EIO;
path[ppos+1].p_hdr =
ext_block_hdr(path[ppos+1].p_bh);
while (++cur_ppos < leaf_ppos) {
path[cur_ppos].p_idx =
EXT_FIRST_INDEX(path[cur_ppos].p_hdr);
path[cur_ppos].p_block =
ext4_idx_pblock(path[cur_ppos].p_idx);
if (path[cur_ppos+1].p_bh)
brelse(path[cur_ppos+1].p_bh);
path[cur_ppos+1].p_bh = sb_bread(inode->i_sb,
path[cur_ppos].p_block);
if (!path[cur_ppos+1].p_bh)
return -EIO;
path[cur_ppos+1].p_hdr =
ext_block_hdr(path[cur_ppos+1].p_bh);
}
path[leaf_ppos].p_ext = *extent = NULL;
eh = path[leaf_ppos].p_hdr;
if (le16_to_cpu(eh->eh_entries) == 0)
return -ENODATA;
path[leaf_ppos].p_ext = *extent =
EXT_FIRST_EXTENT(path[leaf_ppos].p_hdr);
path[leaf_ppos].p_block =
ext4_ext_pblock(path[leaf_ppos].p_ext);
return 0;
}
}
return 1;
}
void
ext4_double_down_write_data_sem(struct inode *first, struct inode *second)
{
if (first < second) {
down_write(&EXT4_I(first)->i_data_sem);
down_write_nested(&EXT4_I(second)->i_data_sem, SINGLE_DEPTH_NESTING);
} else {
down_write(&EXT4_I(second)->i_data_sem);
down_write_nested(&EXT4_I(first)->i_data_sem, SINGLE_DEPTH_NESTING);
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
mext_insert_across_blocks(handle_t *handle, struct inode *orig_inode,
struct ext4_extent *o_start, struct ext4_extent *o_end,
struct ext4_extent *start_ext, struct ext4_extent *new_ext,
struct ext4_extent *end_ext)
{
struct ext4_ext_path *orig_path = NULL;
ext4_lblk_t eblock = 0;
int new_flag = 0;
int end_flag = 0;
int err = 0;
if (start_ext->ee_len && new_ext->ee_len && end_ext->ee_len) {
if (o_start == o_end) {
end_flag = 1;
} else {
o_end->ee_block = end_ext->ee_block;
o_end->ee_len = end_ext->ee_len;
ext4_ext_store_pblock(o_end, ext4_ext_pblock(end_ext));
}
o_start->ee_len = start_ext->ee_len;
eblock = le32_to_cpu(start_ext->ee_block);
new_flag = 1;
} else if (start_ext->ee_len && new_ext->ee_len &&
!end_ext->ee_len && o_start == o_end) {
o_start->ee_len = start_ext->ee_len;
eblock = le32_to_cpu(start_ext->ee_block);
new_flag = 1;
} else if (!start_ext->ee_len && new_ext->ee_len &&
end_ext->ee_len && o_start == o_end) {
o_end->ee_block = end_ext->ee_block;
o_end->ee_len = end_ext->ee_len;
ext4_ext_store_pblock(o_end, ext4_ext_pblock(end_ext));
if (new_ext->ee_block)
eblock = le32_to_cpu(new_ext->ee_block);
new_flag = 1;
} else {
ext4_debug("ext4 move extent: Unexpected insert case\n");
return -EIO;
}
if (new_flag) {
err = get_ext_path(orig_inode, eblock, &orig_path);
if (err)
goto out;
if (ext4_ext_insert_extent(handle, orig_inode,
orig_path, new_ext, 0))
goto out;
}
if (end_flag) {
err = get_ext_path(orig_inode,
le32_to_cpu(end_ext->ee_block) - 1, &orig_path);
if (err)
goto out;
if (ext4_ext_insert_extent(handle, orig_inode,
orig_path, end_ext, 0))
goto out;
}
out:
if (orig_path) {
ext4_ext_drop_refs(orig_path);
kfree(orig_path);
}
return err;
}
static void
mext_insert_inside_block(struct ext4_extent *o_start,
struct ext4_extent *o_end,
struct ext4_extent *start_ext,
struct ext4_extent *new_ext,
struct ext4_extent *end_ext,
struct ext4_extent_header *eh,
int range_to_move)
{
int i = 0;
unsigned long len;
if (range_to_move && o_end < EXT_LAST_EXTENT(eh)) {
len = (unsigned long)(EXT_LAST_EXTENT(eh) + 1) -
(unsigned long)(o_end + 1);
memmove(o_end + 1 + range_to_move, o_end + 1, len);
}
if (start_ext->ee_len)
o_start[i++].ee_len = start_ext->ee_len;
if (new_ext->ee_len) {
o_start[i] = *new_ext;
ext4_ext_store_pblock(&o_start[i++], ext4_ext_pblock(new_ext));
}
if (end_ext->ee_len)
o_start[i] = *end_ext;
le16_add_cpu(&eh->eh_entries, range_to_move);
}
static int
mext_insert_extents(handle_t *handle, struct inode *orig_inode,
struct ext4_ext_path *orig_path,
struct ext4_extent *o_start,
struct ext4_extent *o_end,
struct ext4_extent *start_ext,
struct ext4_extent *new_ext,
struct ext4_extent *end_ext)
{
struct ext4_extent_header *eh;
unsigned long need_slots, slots_range;
int range_to_move, depth, ret;
need_slots = (start_ext->ee_len ? 1 : 0) + (end_ext->ee_len ? 1 : 0) +
(new_ext->ee_len ? 1 : 0);
slots_range = ((unsigned long)(o_end + 1) - (unsigned long)o_start + 1)
/ sizeof(struct ext4_extent);
range_to_move = need_slots - slots_range;
depth = orig_path->p_depth;
orig_path += depth;
eh = orig_path->p_hdr;
if (depth) {
ret = ext4_journal_get_write_access(handle, orig_path->p_bh);
if (ret)
return ret;
}
if (range_to_move > 0 &&
(range_to_move > le16_to_cpu(eh->eh_max)
- le16_to_cpu(eh->eh_entries))) {
ret = mext_insert_across_blocks(handle, orig_inode, o_start,
o_end, start_ext, new_ext, end_ext);
if (ret < 0)
return ret;
} else
mext_insert_inside_block(o_start, o_end, start_ext, new_ext,
end_ext, eh, range_to_move);
return ext4_ext_dirty(handle, orig_inode, orig_path);
}
static int
mext_leaf_block(handle_t *handle, struct inode *orig_inode,
struct ext4_ext_path *orig_path, struct ext4_extent *dext,
ext4_lblk_t *from)
{
struct ext4_extent *oext, *o_start, *o_end, *prev_ext;
struct ext4_extent new_ext, start_ext, end_ext;
ext4_lblk_t new_ext_end;
int oext_alen, new_ext_alen, end_ext_alen;
int depth = ext_depth(orig_inode);
int ret;
start_ext.ee_block = end_ext.ee_block = 0;
o_start = o_end = oext = orig_path[depth].p_ext;
oext_alen = ext4_ext_get_actual_len(oext);
start_ext.ee_len = end_ext.ee_len = 0;
new_ext.ee_block = cpu_to_le32(*from);
ext4_ext_store_pblock(&new_ext, ext4_ext_pblock(dext));
new_ext.ee_len = dext->ee_len;
new_ext_alen = ext4_ext_get_actual_len(&new_ext);
new_ext_end = le32_to_cpu(new_ext.ee_block) + new_ext_alen - 1;
if (le32_to_cpu(oext->ee_block) < le32_to_cpu(new_ext.ee_block) &&
le32_to_cpu(new_ext.ee_block) <
le32_to_cpu(oext->ee_block) + oext_alen) {
start_ext.ee_len = cpu_to_le16(le32_to_cpu(new_ext.ee_block) -
le32_to_cpu(oext->ee_block));
start_ext.ee_block = oext->ee_block;
copy_extent_status(oext, &start_ext);
} else if (oext > EXT_FIRST_EXTENT(orig_path[depth].p_hdr)) {
prev_ext = oext - 1;
if (ext4_can_extents_be_merged(orig_inode, prev_ext,
&new_ext)) {
o_start = prev_ext;
start_ext.ee_len = cpu_to_le16(
ext4_ext_get_actual_len(prev_ext) +
new_ext_alen);
start_ext.ee_block = oext->ee_block;
copy_extent_status(prev_ext, &start_ext);
new_ext.ee_len = 0;
}
}
if (le32_to_cpu(oext->ee_block) + oext_alen - 1 < new_ext_end) {
EXT4_ERROR_INODE(orig_inode,
"new_ext_end(%u) should be less than or equal to "
"oext->ee_block(%u) + oext_alen(%d) - 1",
new_ext_end, le32_to_cpu(oext->ee_block),
oext_alen);
ret = -EIO;
goto out;
}
if (le32_to_cpu(oext->ee_block) <= new_ext_end &&
new_ext_end < le32_to_cpu(oext->ee_block) + oext_alen - 1) {
end_ext.ee_len =
cpu_to_le16(le32_to_cpu(oext->ee_block) +
oext_alen - 1 - new_ext_end);
copy_extent_status(oext, &end_ext);
end_ext_alen = ext4_ext_get_actual_len(&end_ext);
ext4_ext_store_pblock(&end_ext,
(ext4_ext_pblock(o_end) + oext_alen - end_ext_alen));
end_ext.ee_block =
cpu_to_le32(le32_to_cpu(o_end->ee_block) +
oext_alen - end_ext_alen);
}
ret = mext_insert_extents(handle, orig_inode, orig_path, o_start,
o_end, &start_ext, &new_ext, &end_ext);
out:
return ret;
}
static int
mext_calc_swap_extents(struct ext4_extent *tmp_dext,
struct ext4_extent *tmp_oext,
ext4_lblk_t orig_off, ext4_lblk_t donor_off,
ext4_lblk_t max_count)
{
ext4_lblk_t diff, orig_diff;
struct ext4_extent dext_old, oext_old;
BUG_ON(orig_off != donor_off);
if (orig_off < le32_to_cpu(tmp_oext->ee_block) ||
le32_to_cpu(tmp_oext->ee_block) +
ext4_ext_get_actual_len(tmp_oext) - 1 < orig_off)
return -ENODATA;
if (orig_off < le32_to_cpu(tmp_dext->ee_block) ||
le32_to_cpu(tmp_dext->ee_block) +
ext4_ext_get_actual_len(tmp_dext) - 1 < orig_off)
return -ENODATA;
dext_old = *tmp_dext;
oext_old = *tmp_oext;
diff = donor_off - le32_to_cpu(tmp_dext->ee_block);
ext4_ext_store_pblock(tmp_dext, ext4_ext_pblock(tmp_dext) + diff);
le32_add_cpu(&tmp_dext->ee_block, diff);
le16_add_cpu(&tmp_dext->ee_len, -diff);
if (max_count < ext4_ext_get_actual_len(tmp_dext))
tmp_dext->ee_len = cpu_to_le16(max_count);
orig_diff = orig_off - le32_to_cpu(tmp_oext->ee_block);
ext4_ext_store_pblock(tmp_oext, ext4_ext_pblock(tmp_oext) + orig_diff);
if (ext4_ext_get_actual_len(tmp_dext) >
ext4_ext_get_actual_len(tmp_oext) - orig_diff)
tmp_dext->ee_len = cpu_to_le16(le16_to_cpu(tmp_oext->ee_len) -
orig_diff);
tmp_oext->ee_len = cpu_to_le16(ext4_ext_get_actual_len(tmp_dext));
copy_extent_status(&oext_old, tmp_dext);
copy_extent_status(&dext_old, tmp_oext);
return 0;
}
static int
mext_check_coverage(struct inode *inode, ext4_lblk_t from, ext4_lblk_t count,
int uninit, int *err)
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
if (uninit != ext4_ext_is_uninitialized(ext))
goto out;
from += ext4_ext_get_actual_len(ext);
ext4_ext_drop_refs(path);
}
ret = 1;
out:
if (path) {
ext4_ext_drop_refs(path);
kfree(path);
}
return ret;
}
static int
mext_replace_branches(handle_t *handle, struct inode *orig_inode,
struct inode *donor_inode, ext4_lblk_t from,
ext4_lblk_t count, int *err)
{
struct ext4_ext_path *orig_path = NULL;
struct ext4_ext_path *donor_path = NULL;
struct ext4_extent *oext, *dext;
struct ext4_extent tmp_dext, tmp_oext;
ext4_lblk_t orig_off = from, donor_off = from;
int depth;
int replaced_count = 0;
int dext_alen;
*err = ext4_es_remove_extent(orig_inode, from, count);
if (*err)
goto out;
*err = ext4_es_remove_extent(donor_inode, from, count);
if (*err)
goto out;
*err = get_ext_path(orig_inode, orig_off, &orig_path);
if (*err)
goto out;
*err = get_ext_path(donor_inode, donor_off, &donor_path);
if (*err)
goto out;
depth = ext_depth(orig_inode);
oext = orig_path[depth].p_ext;
tmp_oext = *oext;
depth = ext_depth(donor_inode);
dext = donor_path[depth].p_ext;
if (unlikely(!dext))
goto missing_donor_extent;
tmp_dext = *dext;
*err = mext_calc_swap_extents(&tmp_dext, &tmp_oext, orig_off,
donor_off, count);
if (*err)
goto out;
while (1) {
if (unlikely(!dext)) {
missing_donor_extent:
EXT4_ERROR_INODE(donor_inode,
"The extent for donor must be found");
*err = -EIO;
goto out;
} else if (donor_off != le32_to_cpu(tmp_dext.ee_block)) {
EXT4_ERROR_INODE(donor_inode,
"Donor offset(%u) and the first block of donor "
"extent(%u) should be equal",
donor_off,
le32_to_cpu(tmp_dext.ee_block));
*err = -EIO;
goto out;
}
*err = mext_leaf_block(handle, orig_inode,
orig_path, &tmp_dext, &orig_off);
if (*err)
goto out;
*err = mext_leaf_block(handle, donor_inode,
donor_path, &tmp_oext, &donor_off);
if (*err)
goto out;
dext_alen = ext4_ext_get_actual_len(&tmp_dext);
replaced_count += dext_alen;
donor_off += dext_alen;
orig_off += dext_alen;
BUG_ON(replaced_count > count);
if (replaced_count >= count)
break;
if (orig_path)
ext4_ext_drop_refs(orig_path);
*err = get_ext_path(orig_inode, orig_off, &orig_path);
if (*err)
goto out;
depth = ext_depth(orig_inode);
oext = orig_path[depth].p_ext;
tmp_oext = *oext;
if (donor_path)
ext4_ext_drop_refs(donor_path);
*err = get_ext_path(donor_inode, donor_off, &donor_path);
if (*err)
goto out;
depth = ext_depth(donor_inode);
dext = donor_path[depth].p_ext;
tmp_dext = *dext;
*err = mext_calc_swap_extents(&tmp_dext, &tmp_oext, orig_off,
donor_off, count - replaced_count);
if (*err)
goto out;
}
out:
if (orig_path) {
ext4_ext_drop_refs(orig_path);
kfree(orig_path);
}
if (donor_path) {
ext4_ext_drop_refs(donor_path);
kfree(donor_path);
}
return replaced_count;
}
static int
mext_page_double_lock(struct inode *inode1, struct inode *inode2,
pgoff_t index, struct page *page[2])
{
struct address_space *mapping[2];
unsigned fl = AOP_FLAG_NOFS;
BUG_ON(!inode1 || !inode2);
if (inode1 < inode2) {
mapping[0] = inode1->i_mapping;
mapping[1] = inode2->i_mapping;
} else {
mapping[0] = inode2->i_mapping;
mapping[1] = inode1->i_mapping;
}
page[0] = grab_cache_page_write_begin(mapping[0], index, fl);
if (!page[0])
return -ENOMEM;
page[1] = grab_cache_page_write_begin(mapping[1], index, fl);
if (!page[1]) {
unlock_page(page[0]);
page_cache_release(page[0]);
return -ENOMEM;
}
wait_on_page_writeback(page[0]);
wait_on_page_writeback(page[1]);
if (inode1 > inode2) {
struct page *tmp;
tmp = page[0];
page[0] = page[1];
page[1] = tmp;
}
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
blocksize = 1 << inode->i_blkbits;
if (!page_has_buffers(page))
create_empty_buffers(page, blocksize, 0);
head = page_buffers(page);
block = (sector_t)page->index << (PAGE_CACHE_SHIFT - inode->i_blkbits);
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
if (!err)
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
pgoff_t orig_page_offset, int data_offset_in_page,
int block_len_in_page, int uninit, int *err)
{
struct inode *orig_inode = file_inode(o_filp);
struct page *pagep[2] = {NULL, NULL};
handle_t *handle;
ext4_lblk_t orig_blk_offset;
long long offs = orig_page_offset << PAGE_CACHE_SHIFT;
unsigned long blocksize = orig_inode->i_sb->s_blocksize;
unsigned int w_flags = 0;
unsigned int tmp_data_size, data_size, replaced_size;
int err2, jblocks, retries = 0;
int replaced_count = 0;
int from = data_offset_in_page << orig_inode->i_blkbits;
int blocks_per_page = PAGE_CACHE_SIZE >> orig_inode->i_blkbits;
again:
*err = 0;
jblocks = ext4_writepage_trans_blocks(orig_inode) * 2;
handle = ext4_journal_start(orig_inode, EXT4_HT_MOVE_EXTENTS, jblocks);
if (IS_ERR(handle)) {
*err = PTR_ERR(handle);
return 0;
}
if (segment_eq(get_fs(), KERNEL_DS))
w_flags |= AOP_FLAG_UNINTERRUPTIBLE;
orig_blk_offset = orig_page_offset * blocks_per_page +
data_offset_in_page;
offs = (long long)orig_blk_offset << orig_inode->i_blkbits;
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
pagep);
if (unlikely(*err < 0))
goto stop_journal;
if (uninit) {
ext4_double_down_write_data_sem(orig_inode, donor_inode);
uninit = mext_check_coverage(orig_inode, orig_blk_offset,
block_len_in_page, 1, err);
if (*err)
goto drop_data_sem;
uninit &= mext_check_coverage(donor_inode, orig_blk_offset,
block_len_in_page, 1, err);
if (*err)
goto drop_data_sem;
if (!uninit) {
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
replaced_count = mext_replace_branches(handle, orig_inode,
donor_inode, orig_blk_offset,
block_len_in_page, err);
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
replaced_count = mext_replace_branches(handle, orig_inode, donor_inode,
orig_blk_offset,
block_len_in_page, err);
if (*err) {
if (replaced_count) {
block_len_in_page = replaced_count;
replaced_size =
block_len_in_page << orig_inode->i_blkbits;
} else
goto unlock_pages;
}
*err = __block_write_begin(pagep[0], from, replaced_size,
ext4_get_block);
if (!*err)
*err = block_commit_write(pagep[0], from, from + replaced_size);
if (unlikely(*err < 0))
goto repair_branches;
*err = ext4_jbd2_file_inode(handle, orig_inode);
unlock_pages:
unlock_page(pagep[0]);
page_cache_release(pagep[0]);
unlock_page(pagep[1]);
page_cache_release(pagep[1]);
stop_journal:
ext4_journal_stop(handle);
if (*err == -EBUSY && ext4_should_retry_alloc(orig_inode->i_sb,
&retries))
goto again;
return replaced_count;
repair_branches:
ext4_double_down_write_data_sem(orig_inode, donor_inode);
replaced_count = mext_replace_branches(handle, donor_inode, orig_inode,
orig_blk_offset,
block_len_in_page, &err2);
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
ext4_lblk_t orig_blocks, donor_blocks;
unsigned int blkbits = orig_inode->i_blkbits;
unsigned int blocksize = 1 << blkbits;
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
return -EINVAL;
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
if (orig_start != donor_start) {
ext4_debug("ext4 move extent: orig and donor's start "
"offset are not same [ino:orig %lu, donor %lu]\n",
orig_inode->i_ino, donor_inode->i_ino);
return -EINVAL;
}
if ((orig_start >= EXT_MAX_BLOCKS) ||
(*len > EXT_MAX_BLOCKS) ||
(orig_start + *len >= EXT_MAX_BLOCKS)) {
ext4_debug("ext4 move extent: Can't handle over [%u] blocks "
"[ino:orig %lu, donor %lu]\n", EXT_MAX_BLOCKS,
orig_inode->i_ino, donor_inode->i_ino);
return -EINVAL;
}
if (orig_inode->i_size > donor_inode->i_size) {
donor_blocks = (donor_inode->i_size + blocksize - 1) >> blkbits;
if (orig_start >= donor_blocks) {
ext4_debug("ext4 move extent: orig start offset "
"[%llu] should be less than donor file blocks "
"[%u] [ino:orig %lu, donor %lu]\n",
orig_start, donor_blocks,
orig_inode->i_ino, donor_inode->i_ino);
return -EINVAL;
}
if (orig_start + *len > donor_blocks) {
ext4_debug("ext4 move extent: End offset [%llu] should "
"be less than donor file blocks [%u]."
"So adjust length from %llu to %llu "
"[ino:orig %lu, donor %lu]\n",
orig_start + *len, donor_blocks,
*len, donor_blocks - orig_start,
orig_inode->i_ino, donor_inode->i_ino);
*len = donor_blocks - orig_start;
}
} else {
orig_blocks = (orig_inode->i_size + blocksize - 1) >> blkbits;
if (orig_start >= orig_blocks) {
ext4_debug("ext4 move extent: start offset [%llu] "
"should be less than original file blocks "
"[%u] [ino:orig %lu, donor %lu]\n",
orig_start, orig_blocks,
orig_inode->i_ino, donor_inode->i_ino);
return -EINVAL;
}
if (orig_start + *len > orig_blocks) {
ext4_debug("ext4 move extent: Adjust length "
"from %llu to %llu. Because it should be "
"less than original file blocks "
"[ino:orig %lu, donor %lu]\n",
*len, orig_blocks - orig_start,
orig_inode->i_ino, donor_inode->i_ino);
*len = orig_blocks - orig_start;
}
}
if (!*len) {
ext4_debug("ext4 move extent: len should not be 0 "
"[ino:orig %lu, donor %lu]\n", orig_inode->i_ino,
donor_inode->i_ino);
return -EINVAL;
}
return 0;
}
void
ext4_inode_double_lock(struct inode *inode1, struct inode *inode2)
{
BUG_ON(inode1 == inode2);
if (inode1 < inode2) {
mutex_lock_nested(&inode1->i_mutex, I_MUTEX_PARENT);
mutex_lock_nested(&inode2->i_mutex, I_MUTEX_CHILD);
} else {
mutex_lock_nested(&inode2->i_mutex, I_MUTEX_PARENT);
mutex_lock_nested(&inode1->i_mutex, I_MUTEX_CHILD);
}
}
void
ext4_inode_double_unlock(struct inode *inode1, struct inode *inode2)
{
mutex_unlock(&inode1->i_mutex);
mutex_unlock(&inode2->i_mutex);
}
int
ext4_move_extents(struct file *o_filp, struct file *d_filp,
__u64 orig_start, __u64 donor_start, __u64 len,
__u64 *moved_len)
{
struct inode *orig_inode = file_inode(o_filp);
struct inode *donor_inode = file_inode(d_filp);
struct ext4_ext_path *orig_path = NULL, *holecheck_path = NULL;
struct ext4_extent *ext_prev, *ext_cur, *ext_dummy;
ext4_lblk_t block_start = orig_start;
ext4_lblk_t block_end, seq_start, add_blocks, file_end, seq_blocks = 0;
ext4_lblk_t rest_blocks;
pgoff_t orig_page_offset = 0, seq_end_page;
int ret, depth, last_extent = 0;
int blocks_per_page = PAGE_CACHE_SIZE >> orig_inode->i_blkbits;
int data_offset_in_page;
int block_len_in_page;
int uninit;
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
return -EINVAL;
}
ext4_inode_double_lock(orig_inode, donor_inode);
ext4_inode_block_unlocked_dio(orig_inode);
ext4_inode_block_unlocked_dio(donor_inode);
inode_dio_wait(orig_inode);
inode_dio_wait(donor_inode);
ext4_double_down_write_data_sem(orig_inode, donor_inode);
ret = mext_check_arguments(orig_inode, donor_inode, orig_start,
donor_start, &len);
if (ret)
goto out;
file_end = (i_size_read(orig_inode) - 1) >> orig_inode->i_blkbits;
block_end = block_start + len - 1;
if (file_end < block_end)
len -= block_end - file_end;
ret = get_ext_path(orig_inode, block_start, &orig_path);
if (ret)
goto out;
ret = get_ext_path(orig_inode, block_start, &holecheck_path);
if (ret)
goto out;
depth = ext_depth(orig_inode);
ext_cur = holecheck_path[depth].p_ext;
if (le32_to_cpu(ext_cur->ee_block) +
ext4_ext_get_actual_len(ext_cur) - 1 < block_start) {
last_extent = mext_next_extent(orig_inode,
holecheck_path, &ext_cur);
if (last_extent < 0) {
ret = last_extent;
goto out;
}
last_extent = mext_next_extent(orig_inode, orig_path,
&ext_dummy);
if (last_extent < 0) {
ret = last_extent;
goto out;
}
seq_start = le32_to_cpu(ext_cur->ee_block);
} else if (le32_to_cpu(ext_cur->ee_block) > block_start)
seq_start = le32_to_cpu(ext_cur->ee_block);
else
seq_start = block_start;
if (le32_to_cpu(ext_cur->ee_block) > block_end) {
ext4_debug("ext4 move extent: The specified range of file "
"may be the hole\n");
ret = -EINVAL;
goto out;
}
add_blocks = min(le32_to_cpu(ext_cur->ee_block) +
ext4_ext_get_actual_len(ext_cur), block_end + 1) -
max(le32_to_cpu(ext_cur->ee_block), block_start);
while (!last_extent && le32_to_cpu(ext_cur->ee_block) <= block_end) {
seq_blocks += add_blocks;
if (seq_start + seq_blocks - 1 > block_end)
seq_blocks = block_end - seq_start + 1;
ext_prev = ext_cur;
last_extent = mext_next_extent(orig_inode, holecheck_path,
&ext_cur);
if (last_extent < 0) {
ret = last_extent;
break;
}
add_blocks = ext4_ext_get_actual_len(ext_cur);
if (ext4_can_extents_be_merged(orig_inode,
ext_prev, ext_cur) &&
block_end >= le32_to_cpu(ext_cur->ee_block) &&
!last_extent)
continue;
uninit = ext4_ext_is_uninitialized(ext_prev);
data_offset_in_page = seq_start % blocks_per_page;
if (data_offset_in_page + seq_blocks > blocks_per_page) {
block_len_in_page =
blocks_per_page - data_offset_in_page;
} else {
block_len_in_page = seq_blocks;
}
orig_page_offset = seq_start >>
(PAGE_CACHE_SHIFT - orig_inode->i_blkbits);
seq_end_page = (seq_start + seq_blocks - 1) >>
(PAGE_CACHE_SHIFT - orig_inode->i_blkbits);
seq_start = le32_to_cpu(ext_cur->ee_block);
rest_blocks = seq_blocks;
ext4_double_up_write_data_sem(orig_inode, donor_inode);
while (orig_page_offset <= seq_end_page) {
block_len_in_page = move_extent_per_page(
o_filp, donor_inode,
orig_page_offset,
data_offset_in_page,
block_len_in_page, uninit,
&ret);
*moved_len += block_len_in_page;
if (ret < 0)
break;
if (*moved_len > len) {
EXT4_ERROR_INODE(orig_inode,
"We replaced blocks too much! "
"sum of replaced: %llu requested: %llu",
*moved_len, len);
ret = -EIO;
break;
}
orig_page_offset++;
data_offset_in_page = 0;
rest_blocks -= block_len_in_page;
if (rest_blocks > blocks_per_page)
block_len_in_page = blocks_per_page;
else
block_len_in_page = rest_blocks;
}
ext4_double_down_write_data_sem(orig_inode, donor_inode);
if (ret < 0)
break;
if (holecheck_path)
ext4_ext_drop_refs(holecheck_path);
ret = get_ext_path(orig_inode, seq_start, &holecheck_path);
if (ret)
break;
depth = holecheck_path->p_depth;
if (orig_path)
ext4_ext_drop_refs(orig_path);
ret = get_ext_path(orig_inode, seq_start, &orig_path);
if (ret)
break;
ext_cur = holecheck_path[depth].p_ext;
add_blocks = ext4_ext_get_actual_len(ext_cur);
seq_blocks = 0;
}
out:
if (*moved_len) {
ext4_discard_preallocations(orig_inode);
ext4_discard_preallocations(donor_inode);
}
if (orig_path) {
ext4_ext_drop_refs(orig_path);
kfree(orig_path);
}
if (holecheck_path) {
ext4_ext_drop_refs(holecheck_path);
kfree(holecheck_path);
}
ext4_double_up_write_data_sem(orig_inode, donor_inode);
ext4_inode_resume_unlocked_dio(orig_inode);
ext4_inode_resume_unlocked_dio(donor_inode);
ext4_inode_double_unlock(orig_inode, donor_inode);
return ret;
}
