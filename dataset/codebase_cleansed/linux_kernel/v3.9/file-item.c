int btrfs_insert_file_extent(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
u64 objectid, u64 pos,
u64 disk_offset, u64 disk_num_bytes,
u64 num_bytes, u64 offset, u64 ram_bytes,
u8 compression, u8 encryption, u16 other_encoding)
{
int ret = 0;
struct btrfs_file_extent_item *item;
struct btrfs_key file_key;
struct btrfs_path *path;
struct extent_buffer *leaf;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
file_key.objectid = objectid;
file_key.offset = pos;
btrfs_set_key_type(&file_key, BTRFS_EXTENT_DATA_KEY);
path->leave_spinning = 1;
ret = btrfs_insert_empty_item(trans, root, path, &file_key,
sizeof(*item));
if (ret < 0)
goto out;
BUG_ON(ret);
leaf = path->nodes[0];
item = btrfs_item_ptr(leaf, path->slots[0],
struct btrfs_file_extent_item);
btrfs_set_file_extent_disk_bytenr(leaf, item, disk_offset);
btrfs_set_file_extent_disk_num_bytes(leaf, item, disk_num_bytes);
btrfs_set_file_extent_offset(leaf, item, offset);
btrfs_set_file_extent_num_bytes(leaf, item, num_bytes);
btrfs_set_file_extent_ram_bytes(leaf, item, ram_bytes);
btrfs_set_file_extent_generation(leaf, item, trans->transid);
btrfs_set_file_extent_type(leaf, item, BTRFS_FILE_EXTENT_REG);
btrfs_set_file_extent_compression(leaf, item, compression);
btrfs_set_file_extent_encryption(leaf, item, encryption);
btrfs_set_file_extent_other_encoding(leaf, item, other_encoding);
btrfs_mark_buffer_dirty(leaf);
out:
btrfs_free_path(path);
return ret;
}
struct btrfs_csum_item *btrfs_lookup_csum(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path,
u64 bytenr, int cow)
{
int ret;
struct btrfs_key file_key;
struct btrfs_key found_key;
struct btrfs_csum_item *item;
struct extent_buffer *leaf;
u64 csum_offset = 0;
u16 csum_size = btrfs_super_csum_size(root->fs_info->super_copy);
int csums_in_item;
file_key.objectid = BTRFS_EXTENT_CSUM_OBJECTID;
file_key.offset = bytenr;
btrfs_set_key_type(&file_key, BTRFS_EXTENT_CSUM_KEY);
ret = btrfs_search_slot(trans, root, &file_key, path, 0, cow);
if (ret < 0)
goto fail;
leaf = path->nodes[0];
if (ret > 0) {
ret = 1;
if (path->slots[0] == 0)
goto fail;
path->slots[0]--;
btrfs_item_key_to_cpu(leaf, &found_key, path->slots[0]);
if (btrfs_key_type(&found_key) != BTRFS_EXTENT_CSUM_KEY)
goto fail;
csum_offset = (bytenr - found_key.offset) >>
root->fs_info->sb->s_blocksize_bits;
csums_in_item = btrfs_item_size_nr(leaf, path->slots[0]);
csums_in_item /= csum_size;
if (csum_offset == csums_in_item) {
ret = -EFBIG;
goto fail;
} else if (csum_offset > csums_in_item) {
goto fail;
}
}
item = btrfs_item_ptr(leaf, path->slots[0], struct btrfs_csum_item);
item = (struct btrfs_csum_item *)((unsigned char *)item +
csum_offset * csum_size);
return item;
fail:
if (ret > 0)
ret = -ENOENT;
return ERR_PTR(ret);
}
int btrfs_lookup_file_extent(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path, u64 objectid,
u64 offset, int mod)
{
int ret;
struct btrfs_key file_key;
int ins_len = mod < 0 ? -1 : 0;
int cow = mod != 0;
file_key.objectid = objectid;
file_key.offset = offset;
btrfs_set_key_type(&file_key, BTRFS_EXTENT_DATA_KEY);
ret = btrfs_search_slot(trans, root, &file_key, path, ins_len, cow);
return ret;
}
u64 btrfs_file_extent_length(struct btrfs_path *path)
{
int extent_type;
struct btrfs_file_extent_item *fi;
u64 len;
fi = btrfs_item_ptr(path->nodes[0], path->slots[0],
struct btrfs_file_extent_item);
extent_type = btrfs_file_extent_type(path->nodes[0], fi);
if (extent_type == BTRFS_FILE_EXTENT_REG ||
extent_type == BTRFS_FILE_EXTENT_PREALLOC)
len = btrfs_file_extent_num_bytes(path->nodes[0], fi);
else if (extent_type == BTRFS_FILE_EXTENT_INLINE)
len = btrfs_file_extent_inline_len(path->nodes[0], fi);
else
BUG();
return len;
}
static int __btrfs_lookup_bio_sums(struct btrfs_root *root,
struct inode *inode, struct bio *bio,
u64 logical_offset, u32 *dst, int dio)
{
u32 sum;
struct bio_vec *bvec = bio->bi_io_vec;
int bio_index = 0;
u64 offset = 0;
u64 item_start_offset = 0;
u64 item_last_offset = 0;
u64 disk_bytenr;
u32 diff;
u16 csum_size = btrfs_super_csum_size(root->fs_info->super_copy);
int ret;
struct btrfs_path *path;
struct btrfs_csum_item *item = NULL;
struct extent_io_tree *io_tree = &BTRFS_I(inode)->io_tree;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
if (bio->bi_size > PAGE_CACHE_SIZE * 8)
path->reada = 2;
WARN_ON(bio->bi_vcnt <= 0);
if (btrfs_is_free_space_inode(inode)) {
path->search_commit_root = 1;
path->skip_locking = 1;
}
disk_bytenr = (u64)bio->bi_sector << 9;
if (dio)
offset = logical_offset;
while (bio_index < bio->bi_vcnt) {
if (!dio)
offset = page_offset(bvec->bv_page) + bvec->bv_offset;
ret = btrfs_find_ordered_sum(inode, offset, disk_bytenr, &sum);
if (ret == 0)
goto found;
if (!item || disk_bytenr < item_start_offset ||
disk_bytenr >= item_last_offset) {
struct btrfs_key found_key;
u32 item_size;
if (item)
btrfs_release_path(path);
item = btrfs_lookup_csum(NULL, root->fs_info->csum_root,
path, disk_bytenr, 0);
if (IS_ERR(item)) {
ret = PTR_ERR(item);
if (ret == -ENOENT || ret == -EFBIG)
ret = 0;
sum = 0;
if (BTRFS_I(inode)->root->root_key.objectid ==
BTRFS_DATA_RELOC_TREE_OBJECTID) {
set_extent_bits(io_tree, offset,
offset + bvec->bv_len - 1,
EXTENT_NODATASUM, GFP_NOFS);
} else {
printk(KERN_INFO "btrfs no csum found "
"for inode %llu start %llu\n",
(unsigned long long)
btrfs_ino(inode),
(unsigned long long)offset);
}
item = NULL;
btrfs_release_path(path);
goto found;
}
btrfs_item_key_to_cpu(path->nodes[0], &found_key,
path->slots[0]);
item_start_offset = found_key.offset;
item_size = btrfs_item_size_nr(path->nodes[0],
path->slots[0]);
item_last_offset = item_start_offset +
(item_size / csum_size) *
root->sectorsize;
item = btrfs_item_ptr(path->nodes[0], path->slots[0],
struct btrfs_csum_item);
}
diff = disk_bytenr - item_start_offset;
diff = diff / root->sectorsize;
diff = diff * csum_size;
read_extent_buffer(path->nodes[0], &sum,
((unsigned long)item) + diff,
csum_size);
found:
if (dst)
*dst++ = sum;
else
set_state_private(io_tree, offset, sum);
disk_bytenr += bvec->bv_len;
offset += bvec->bv_len;
bio_index++;
bvec++;
}
btrfs_free_path(path);
return 0;
}
int btrfs_lookup_bio_sums(struct btrfs_root *root, struct inode *inode,
struct bio *bio, u32 *dst)
{
return __btrfs_lookup_bio_sums(root, inode, bio, 0, dst, 0);
}
int btrfs_lookup_bio_sums_dio(struct btrfs_root *root, struct inode *inode,
struct bio *bio, u64 offset)
{
return __btrfs_lookup_bio_sums(root, inode, bio, offset, NULL, 1);
}
int btrfs_lookup_csums_range(struct btrfs_root *root, u64 start, u64 end,
struct list_head *list, int search_commit)
{
struct btrfs_key key;
struct btrfs_path *path;
struct extent_buffer *leaf;
struct btrfs_ordered_sum *sums;
struct btrfs_sector_sum *sector_sum;
struct btrfs_csum_item *item;
LIST_HEAD(tmplist);
unsigned long offset;
int ret;
size_t size;
u64 csum_end;
u16 csum_size = btrfs_super_csum_size(root->fs_info->super_copy);
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
if (search_commit) {
path->skip_locking = 1;
path->reada = 2;
path->search_commit_root = 1;
}
key.objectid = BTRFS_EXTENT_CSUM_OBJECTID;
key.offset = start;
key.type = BTRFS_EXTENT_CSUM_KEY;
ret = btrfs_search_slot(NULL, root, &key, path, 0, 0);
if (ret < 0)
goto fail;
if (ret > 0 && path->slots[0] > 0) {
leaf = path->nodes[0];
btrfs_item_key_to_cpu(leaf, &key, path->slots[0] - 1);
if (key.objectid == BTRFS_EXTENT_CSUM_OBJECTID &&
key.type == BTRFS_EXTENT_CSUM_KEY) {
offset = (start - key.offset) >>
root->fs_info->sb->s_blocksize_bits;
if (offset * csum_size <
btrfs_item_size_nr(leaf, path->slots[0] - 1))
path->slots[0]--;
}
}
while (start <= end) {
leaf = path->nodes[0];
if (path->slots[0] >= btrfs_header_nritems(leaf)) {
ret = btrfs_next_leaf(root, path);
if (ret < 0)
goto fail;
if (ret > 0)
break;
leaf = path->nodes[0];
}
btrfs_item_key_to_cpu(leaf, &key, path->slots[0]);
if (key.objectid != BTRFS_EXTENT_CSUM_OBJECTID ||
key.type != BTRFS_EXTENT_CSUM_KEY)
break;
btrfs_item_key_to_cpu(leaf, &key, path->slots[0]);
if (key.offset > end)
break;
if (key.offset > start)
start = key.offset;
size = btrfs_item_size_nr(leaf, path->slots[0]);
csum_end = key.offset + (size / csum_size) * root->sectorsize;
if (csum_end <= start) {
path->slots[0]++;
continue;
}
csum_end = min(csum_end, end + 1);
item = btrfs_item_ptr(path->nodes[0], path->slots[0],
struct btrfs_csum_item);
while (start < csum_end) {
size = min_t(size_t, csum_end - start,
MAX_ORDERED_SUM_BYTES(root));
sums = kzalloc(btrfs_ordered_sum_size(root, size),
GFP_NOFS);
if (!sums) {
ret = -ENOMEM;
goto fail;
}
sector_sum = sums->sums;
sums->bytenr = start;
sums->len = size;
offset = (start - key.offset) >>
root->fs_info->sb->s_blocksize_bits;
offset *= csum_size;
while (size > 0) {
read_extent_buffer(path->nodes[0],
&sector_sum->sum,
((unsigned long)item) +
offset, csum_size);
sector_sum->bytenr = start;
size -= root->sectorsize;
start += root->sectorsize;
offset += csum_size;
sector_sum++;
}
list_add_tail(&sums->list, &tmplist);
}
path->slots[0]++;
}
ret = 0;
fail:
while (ret < 0 && !list_empty(&tmplist)) {
sums = list_entry(&tmplist, struct btrfs_ordered_sum, list);
list_del(&sums->list);
kfree(sums);
}
list_splice_tail(&tmplist, list);
btrfs_free_path(path);
return ret;
}
int btrfs_csum_one_bio(struct btrfs_root *root, struct inode *inode,
struct bio *bio, u64 file_start, int contig)
{
struct btrfs_ordered_sum *sums;
struct btrfs_sector_sum *sector_sum;
struct btrfs_ordered_extent *ordered;
char *data;
struct bio_vec *bvec = bio->bi_io_vec;
int bio_index = 0;
unsigned long total_bytes = 0;
unsigned long this_sum_bytes = 0;
u64 offset;
u64 disk_bytenr;
WARN_ON(bio->bi_vcnt <= 0);
sums = kzalloc(btrfs_ordered_sum_size(root, bio->bi_size), GFP_NOFS);
if (!sums)
return -ENOMEM;
sector_sum = sums->sums;
disk_bytenr = (u64)bio->bi_sector << 9;
sums->len = bio->bi_size;
INIT_LIST_HEAD(&sums->list);
if (contig)
offset = file_start;
else
offset = page_offset(bvec->bv_page) + bvec->bv_offset;
ordered = btrfs_lookup_ordered_extent(inode, offset);
BUG_ON(!ordered);
sums->bytenr = ordered->start;
while (bio_index < bio->bi_vcnt) {
if (!contig)
offset = page_offset(bvec->bv_page) + bvec->bv_offset;
if (offset >= ordered->file_offset + ordered->len ||
offset < ordered->file_offset) {
unsigned long bytes_left;
sums->len = this_sum_bytes;
this_sum_bytes = 0;
btrfs_add_ordered_sum(inode, ordered, sums);
btrfs_put_ordered_extent(ordered);
bytes_left = bio->bi_size - total_bytes;
sums = kzalloc(btrfs_ordered_sum_size(root, bytes_left),
GFP_NOFS);
BUG_ON(!sums);
sector_sum = sums->sums;
sums->len = bytes_left;
ordered = btrfs_lookup_ordered_extent(inode, offset);
BUG_ON(!ordered);
sums->bytenr = ordered->start;
}
data = kmap_atomic(bvec->bv_page);
sector_sum->sum = ~(u32)0;
sector_sum->sum = btrfs_csum_data(root,
data + bvec->bv_offset,
sector_sum->sum,
bvec->bv_len);
kunmap_atomic(data);
btrfs_csum_final(sector_sum->sum,
(char *)&sector_sum->sum);
sector_sum->bytenr = disk_bytenr;
sector_sum++;
bio_index++;
total_bytes += bvec->bv_len;
this_sum_bytes += bvec->bv_len;
disk_bytenr += bvec->bv_len;
offset += bvec->bv_len;
bvec++;
}
this_sum_bytes = 0;
btrfs_add_ordered_sum(inode, ordered, sums);
btrfs_put_ordered_extent(ordered);
return 0;
}
static noinline void truncate_one_csum(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path,
struct btrfs_key *key,
u64 bytenr, u64 len)
{
struct extent_buffer *leaf;
u16 csum_size = btrfs_super_csum_size(root->fs_info->super_copy);
u64 csum_end;
u64 end_byte = bytenr + len;
u32 blocksize_bits = root->fs_info->sb->s_blocksize_bits;
leaf = path->nodes[0];
csum_end = btrfs_item_size_nr(leaf, path->slots[0]) / csum_size;
csum_end <<= root->fs_info->sb->s_blocksize_bits;
csum_end += key->offset;
if (key->offset < bytenr && csum_end <= end_byte) {
u32 new_size = (bytenr - key->offset) >> blocksize_bits;
new_size *= csum_size;
btrfs_truncate_item(trans, root, path, new_size, 1);
} else if (key->offset >= bytenr && csum_end > end_byte &&
end_byte > key->offset) {
u32 new_size = (csum_end - end_byte) >> blocksize_bits;
new_size *= csum_size;
btrfs_truncate_item(trans, root, path, new_size, 0);
key->offset = end_byte;
btrfs_set_item_key_safe(trans, root, path, key);
} else {
BUG();
}
}
int btrfs_del_csums(struct btrfs_trans_handle *trans,
struct btrfs_root *root, u64 bytenr, u64 len)
{
struct btrfs_path *path;
struct btrfs_key key;
u64 end_byte = bytenr + len;
u64 csum_end;
struct extent_buffer *leaf;
int ret;
u16 csum_size = btrfs_super_csum_size(root->fs_info->super_copy);
int blocksize_bits = root->fs_info->sb->s_blocksize_bits;
root = root->fs_info->csum_root;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
while (1) {
key.objectid = BTRFS_EXTENT_CSUM_OBJECTID;
key.offset = end_byte - 1;
key.type = BTRFS_EXTENT_CSUM_KEY;
path->leave_spinning = 1;
ret = btrfs_search_slot(trans, root, &key, path, -1, 1);
if (ret > 0) {
if (path->slots[0] == 0)
break;
path->slots[0]--;
} else if (ret < 0) {
break;
}
leaf = path->nodes[0];
btrfs_item_key_to_cpu(leaf, &key, path->slots[0]);
if (key.objectid != BTRFS_EXTENT_CSUM_OBJECTID ||
key.type != BTRFS_EXTENT_CSUM_KEY) {
break;
}
if (key.offset >= end_byte)
break;
csum_end = btrfs_item_size_nr(leaf, path->slots[0]) / csum_size;
csum_end <<= blocksize_bits;
csum_end += key.offset;
if (csum_end <= bytenr)
break;
if (key.offset >= bytenr && csum_end <= end_byte) {
ret = btrfs_del_item(trans, root, path);
if (ret)
goto out;
if (key.offset == bytenr)
break;
} else if (key.offset < bytenr && csum_end > end_byte) {
unsigned long offset;
unsigned long shift_len;
unsigned long item_offset;
offset = (bytenr - key.offset) >> blocksize_bits;
offset *= csum_size;
shift_len = (len >> blocksize_bits) * csum_size;
item_offset = btrfs_item_ptr_offset(leaf,
path->slots[0]);
memset_extent_buffer(leaf, 0, item_offset + offset,
shift_len);
key.offset = bytenr;
ret = btrfs_split_item(trans, root, path, &key, offset);
if (ret && ret != -EAGAIN) {
btrfs_abort_transaction(trans, root, ret);
goto out;
}
key.offset = end_byte - 1;
} else {
truncate_one_csum(trans, root, path, &key, bytenr, len);
if (key.offset < bytenr)
break;
}
btrfs_release_path(path);
}
ret = 0;
out:
btrfs_free_path(path);
return ret;
}
static u64 btrfs_sector_sum_left(struct btrfs_ordered_sum *sums,
struct btrfs_sector_sum *sector_sum,
u64 total_bytes, u64 sectorsize)
{
u64 tmp = sectorsize;
u64 next_sector = sector_sum->bytenr;
struct btrfs_sector_sum *next = sector_sum + 1;
while ((tmp + total_bytes) < sums->len) {
if (next_sector + sectorsize != next->bytenr)
break;
tmp += sectorsize;
next_sector = next->bytenr;
next++;
}
return tmp;
}
int btrfs_csum_file_blocks(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_ordered_sum *sums)
{
u64 bytenr;
int ret;
struct btrfs_key file_key;
struct btrfs_key found_key;
u64 next_offset;
u64 total_bytes = 0;
int found_next;
struct btrfs_path *path;
struct btrfs_csum_item *item;
struct btrfs_csum_item *item_end;
struct extent_buffer *leaf = NULL;
u64 csum_offset;
struct btrfs_sector_sum *sector_sum;
u32 nritems;
u32 ins_size;
u16 csum_size = btrfs_super_csum_size(root->fs_info->super_copy);
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
sector_sum = sums->sums;
again:
next_offset = (u64)-1;
found_next = 0;
file_key.objectid = BTRFS_EXTENT_CSUM_OBJECTID;
file_key.offset = sector_sum->bytenr;
bytenr = sector_sum->bytenr;
btrfs_set_key_type(&file_key, BTRFS_EXTENT_CSUM_KEY);
item = btrfs_lookup_csum(trans, root, path, sector_sum->bytenr, 1);
if (!IS_ERR(item)) {
leaf = path->nodes[0];
ret = 0;
goto found;
}
ret = PTR_ERR(item);
if (ret != -EFBIG && ret != -ENOENT)
goto fail_unlock;
if (ret == -EFBIG) {
u32 item_size;
leaf = path->nodes[0];
item_size = btrfs_item_size_nr(leaf, path->slots[0]);
if ((item_size / csum_size) >=
MAX_CSUM_ITEMS(root, csum_size)) {
goto insert;
}
} else {
int slot = path->slots[0] + 1;
nritems = btrfs_header_nritems(path->nodes[0]);
if (path->slots[0] >= nritems - 1) {
ret = btrfs_next_leaf(root, path);
if (ret == 1)
found_next = 1;
if (ret != 0)
goto insert;
slot = 0;
}
btrfs_item_key_to_cpu(path->nodes[0], &found_key, slot);
if (found_key.objectid != BTRFS_EXTENT_CSUM_OBJECTID ||
found_key.type != BTRFS_EXTENT_CSUM_KEY) {
found_next = 1;
goto insert;
}
next_offset = found_key.offset;
found_next = 1;
goto insert;
}
btrfs_release_path(path);
ret = btrfs_search_slot(trans, root, &file_key, path,
csum_size, 1);
if (ret < 0)
goto fail_unlock;
if (ret > 0) {
if (path->slots[0] == 0)
goto insert;
path->slots[0]--;
}
leaf = path->nodes[0];
btrfs_item_key_to_cpu(leaf, &found_key, path->slots[0]);
csum_offset = (bytenr - found_key.offset) >>
root->fs_info->sb->s_blocksize_bits;
if (btrfs_key_type(&found_key) != BTRFS_EXTENT_CSUM_KEY ||
found_key.objectid != BTRFS_EXTENT_CSUM_OBJECTID ||
csum_offset >= MAX_CSUM_ITEMS(root, csum_size)) {
goto insert;
}
if (csum_offset == btrfs_item_size_nr(leaf, path->slots[0]) /
csum_size) {
int extend_nr;
u64 tmp;
u32 diff;
u32 free_space;
if (btrfs_leaf_free_space(root, leaf) <
sizeof(struct btrfs_item) + csum_size * 2)
goto insert;
free_space = btrfs_leaf_free_space(root, leaf) -
sizeof(struct btrfs_item) - csum_size;
tmp = btrfs_sector_sum_left(sums, sector_sum, total_bytes,
root->sectorsize);
tmp >>= root->fs_info->sb->s_blocksize_bits;
WARN_ON(tmp < 1);
extend_nr = max_t(int, 1, (int)tmp);
diff = (csum_offset + extend_nr) * csum_size;
diff = min(diff, MAX_CSUM_ITEMS(root, csum_size) * csum_size);
diff = diff - btrfs_item_size_nr(leaf, path->slots[0]);
diff = min(free_space, diff);
diff /= csum_size;
diff *= csum_size;
btrfs_extend_item(trans, root, path, diff);
goto csum;
}
insert:
btrfs_release_path(path);
csum_offset = 0;
if (found_next) {
u64 tmp;
tmp = btrfs_sector_sum_left(sums, sector_sum, total_bytes,
root->sectorsize);
tmp >>= root->fs_info->sb->s_blocksize_bits;
tmp = min(tmp, (next_offset - file_key.offset) >>
root->fs_info->sb->s_blocksize_bits);
tmp = max((u64)1, tmp);
tmp = min(tmp, (u64)MAX_CSUM_ITEMS(root, csum_size));
ins_size = csum_size * tmp;
} else {
ins_size = csum_size;
}
path->leave_spinning = 1;
ret = btrfs_insert_empty_item(trans, root, path, &file_key,
ins_size);
path->leave_spinning = 0;
if (ret < 0)
goto fail_unlock;
if (ret != 0) {
WARN_ON(1);
goto fail_unlock;
}
csum:
leaf = path->nodes[0];
item = btrfs_item_ptr(leaf, path->slots[0], struct btrfs_csum_item);
ret = 0;
item = (struct btrfs_csum_item *)((unsigned char *)item +
csum_offset * csum_size);
found:
item_end = btrfs_item_ptr(leaf, path->slots[0], struct btrfs_csum_item);
item_end = (struct btrfs_csum_item *)((unsigned char *)item_end +
btrfs_item_size_nr(leaf, path->slots[0]));
next_sector:
write_extent_buffer(leaf, &sector_sum->sum, (unsigned long)item, csum_size);
total_bytes += root->sectorsize;
sector_sum++;
if (total_bytes < sums->len) {
item = (struct btrfs_csum_item *)((char *)item +
csum_size);
if (item < item_end && bytenr + PAGE_CACHE_SIZE ==
sector_sum->bytenr) {
bytenr = sector_sum->bytenr;
goto next_sector;
}
}
btrfs_mark_buffer_dirty(path->nodes[0]);
if (total_bytes < sums->len) {
btrfs_release_path(path);
cond_resched();
goto again;
}
out:
btrfs_free_path(path);
return ret;
fail_unlock:
goto out;
}
