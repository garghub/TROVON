static struct inode *__lookup_free_space_inode(struct btrfs_root *root,
struct btrfs_path *path,
u64 offset)
{
struct btrfs_key key;
struct btrfs_key location;
struct btrfs_disk_key disk_key;
struct btrfs_free_space_header *header;
struct extent_buffer *leaf;
struct inode *inode = NULL;
int ret;
key.objectid = BTRFS_FREE_SPACE_OBJECTID;
key.offset = offset;
key.type = 0;
ret = btrfs_search_slot(NULL, root, &key, path, 0, 0);
if (ret < 0)
return ERR_PTR(ret);
if (ret > 0) {
btrfs_release_path(path);
return ERR_PTR(-ENOENT);
}
leaf = path->nodes[0];
header = btrfs_item_ptr(leaf, path->slots[0],
struct btrfs_free_space_header);
btrfs_free_space_key(leaf, header, &disk_key);
btrfs_disk_key_to_cpu(&location, &disk_key);
btrfs_release_path(path);
inode = btrfs_iget(root->fs_info->sb, &location, root, NULL);
if (!inode)
return ERR_PTR(-ENOENT);
if (IS_ERR(inode))
return inode;
if (is_bad_inode(inode)) {
iput(inode);
return ERR_PTR(-ENOENT);
}
inode->i_mapping->flags &= ~__GFP_FS;
return inode;
}
struct inode *lookup_free_space_inode(struct btrfs_root *root,
struct btrfs_block_group_cache
*block_group, struct btrfs_path *path)
{
struct inode *inode = NULL;
u32 flags = BTRFS_INODE_NODATASUM | BTRFS_INODE_NODATACOW;
spin_lock(&block_group->lock);
if (block_group->inode)
inode = igrab(block_group->inode);
spin_unlock(&block_group->lock);
if (inode)
return inode;
inode = __lookup_free_space_inode(root, path,
block_group->key.objectid);
if (IS_ERR(inode))
return inode;
spin_lock(&block_group->lock);
if (!((BTRFS_I(inode)->flags & flags) == flags)) {
printk(KERN_INFO "Old style space inode found, converting.\n");
BTRFS_I(inode)->flags |= BTRFS_INODE_NODATASUM |
BTRFS_INODE_NODATACOW;
block_group->disk_cache_state = BTRFS_DC_CLEAR;
}
if (!block_group->iref) {
block_group->inode = igrab(inode);
block_group->iref = 1;
}
spin_unlock(&block_group->lock);
return inode;
}
int __create_free_space_inode(struct btrfs_root *root,
struct btrfs_trans_handle *trans,
struct btrfs_path *path, u64 ino, u64 offset)
{
struct btrfs_key key;
struct btrfs_disk_key disk_key;
struct btrfs_free_space_header *header;
struct btrfs_inode_item *inode_item;
struct extent_buffer *leaf;
u64 flags = BTRFS_INODE_NOCOMPRESS | BTRFS_INODE_PREALLOC;
int ret;
ret = btrfs_insert_empty_inode(trans, root, path, ino);
if (ret)
return ret;
if (ino != BTRFS_FREE_INO_OBJECTID)
flags |= BTRFS_INODE_NODATASUM | BTRFS_INODE_NODATACOW;
leaf = path->nodes[0];
inode_item = btrfs_item_ptr(leaf, path->slots[0],
struct btrfs_inode_item);
btrfs_item_key(leaf, &disk_key, path->slots[0]);
memset_extent_buffer(leaf, 0, (unsigned long)inode_item,
sizeof(*inode_item));
btrfs_set_inode_generation(leaf, inode_item, trans->transid);
btrfs_set_inode_size(leaf, inode_item, 0);
btrfs_set_inode_nbytes(leaf, inode_item, 0);
btrfs_set_inode_uid(leaf, inode_item, 0);
btrfs_set_inode_gid(leaf, inode_item, 0);
btrfs_set_inode_mode(leaf, inode_item, S_IFREG | 0600);
btrfs_set_inode_flags(leaf, inode_item, flags);
btrfs_set_inode_nlink(leaf, inode_item, 1);
btrfs_set_inode_transid(leaf, inode_item, trans->transid);
btrfs_set_inode_block_group(leaf, inode_item, offset);
btrfs_mark_buffer_dirty(leaf);
btrfs_release_path(path);
key.objectid = BTRFS_FREE_SPACE_OBJECTID;
key.offset = offset;
key.type = 0;
ret = btrfs_insert_empty_item(trans, root, path, &key,
sizeof(struct btrfs_free_space_header));
if (ret < 0) {
btrfs_release_path(path);
return ret;
}
leaf = path->nodes[0];
header = btrfs_item_ptr(leaf, path->slots[0],
struct btrfs_free_space_header);
memset_extent_buffer(leaf, 0, (unsigned long)header, sizeof(*header));
btrfs_set_free_space_key(leaf, header, &disk_key);
btrfs_mark_buffer_dirty(leaf);
btrfs_release_path(path);
return 0;
}
int create_free_space_inode(struct btrfs_root *root,
struct btrfs_trans_handle *trans,
struct btrfs_block_group_cache *block_group,
struct btrfs_path *path)
{
int ret;
u64 ino;
ret = btrfs_find_free_objectid(root, &ino);
if (ret < 0)
return ret;
return __create_free_space_inode(root, trans, path, ino,
block_group->key.objectid);
}
int btrfs_truncate_free_space_cache(struct btrfs_root *root,
struct btrfs_trans_handle *trans,
struct btrfs_path *path,
struct inode *inode)
{
struct btrfs_block_rsv *rsv;
u64 needed_bytes;
loff_t oldsize;
int ret = 0;
rsv = trans->block_rsv;
trans->block_rsv = &root->fs_info->global_block_rsv;
needed_bytes = btrfs_calc_trunc_metadata_size(root, 1) +
btrfs_calc_trans_metadata_size(root, 1);
spin_lock(&trans->block_rsv->lock);
if (trans->block_rsv->reserved < needed_bytes) {
spin_unlock(&trans->block_rsv->lock);
trans->block_rsv = rsv;
return -ENOSPC;
}
spin_unlock(&trans->block_rsv->lock);
oldsize = i_size_read(inode);
btrfs_i_size_write(inode, 0);
truncate_pagecache(inode, oldsize, 0);
ret = btrfs_truncate_inode_items(trans, root, inode,
0, BTRFS_EXTENT_DATA_KEY);
if (ret) {
trans->block_rsv = rsv;
WARN_ON(1);
return ret;
}
ret = btrfs_update_inode(trans, root, inode);
trans->block_rsv = rsv;
return ret;
}
static int readahead_cache(struct inode *inode)
{
struct file_ra_state *ra;
unsigned long last_index;
ra = kzalloc(sizeof(*ra), GFP_NOFS);
if (!ra)
return -ENOMEM;
file_ra_state_init(ra, inode->i_mapping);
last_index = (i_size_read(inode) - 1) >> PAGE_CACHE_SHIFT;
page_cache_sync_readahead(inode->i_mapping, ra, NULL, 0, last_index);
kfree(ra);
return 0;
}
static int io_ctl_init(struct io_ctl *io_ctl, struct inode *inode,
struct btrfs_root *root)
{
memset(io_ctl, 0, sizeof(struct io_ctl));
io_ctl->num_pages = (i_size_read(inode) + PAGE_CACHE_SIZE - 1) >>
PAGE_CACHE_SHIFT;
io_ctl->pages = kzalloc(sizeof(struct page *) * io_ctl->num_pages,
GFP_NOFS);
if (!io_ctl->pages)
return -ENOMEM;
io_ctl->root = root;
if (btrfs_ino(inode) != BTRFS_FREE_INO_OBJECTID)
io_ctl->check_crcs = 1;
return 0;
}
static void io_ctl_free(struct io_ctl *io_ctl)
{
kfree(io_ctl->pages);
}
static void io_ctl_unmap_page(struct io_ctl *io_ctl)
{
if (io_ctl->cur) {
kunmap(io_ctl->page);
io_ctl->cur = NULL;
io_ctl->orig = NULL;
}
}
static void io_ctl_map_page(struct io_ctl *io_ctl, int clear)
{
WARN_ON(io_ctl->cur);
BUG_ON(io_ctl->index >= io_ctl->num_pages);
io_ctl->page = io_ctl->pages[io_ctl->index++];
io_ctl->cur = kmap(io_ctl->page);
io_ctl->orig = io_ctl->cur;
io_ctl->size = PAGE_CACHE_SIZE;
if (clear)
memset(io_ctl->cur, 0, PAGE_CACHE_SIZE);
}
static void io_ctl_drop_pages(struct io_ctl *io_ctl)
{
int i;
io_ctl_unmap_page(io_ctl);
for (i = 0; i < io_ctl->num_pages; i++) {
ClearPageChecked(io_ctl->pages[i]);
unlock_page(io_ctl->pages[i]);
page_cache_release(io_ctl->pages[i]);
}
}
static int io_ctl_prepare_pages(struct io_ctl *io_ctl, struct inode *inode,
int uptodate)
{
struct page *page;
gfp_t mask = btrfs_alloc_write_mask(inode->i_mapping);
int i;
for (i = 0; i < io_ctl->num_pages; i++) {
page = find_or_create_page(inode->i_mapping, i, mask);
if (!page) {
io_ctl_drop_pages(io_ctl);
return -ENOMEM;
}
io_ctl->pages[i] = page;
if (uptodate && !PageUptodate(page)) {
btrfs_readpage(NULL, page);
lock_page(page);
if (!PageUptodate(page)) {
printk(KERN_ERR "btrfs: error reading free "
"space cache\n");
io_ctl_drop_pages(io_ctl);
return -EIO;
}
}
}
for (i = 0; i < io_ctl->num_pages; i++) {
clear_page_dirty_for_io(io_ctl->pages[i]);
set_page_extent_mapped(io_ctl->pages[i]);
}
return 0;
}
static void io_ctl_set_generation(struct io_ctl *io_ctl, u64 generation)
{
u64 *val;
io_ctl_map_page(io_ctl, 1);
if (io_ctl->check_crcs) {
io_ctl->cur += (sizeof(u32) * io_ctl->num_pages);
io_ctl->size -= sizeof(u64) + (sizeof(u32) * io_ctl->num_pages);
} else {
io_ctl->cur += sizeof(u64);
io_ctl->size -= sizeof(u64) * 2;
}
val = io_ctl->cur;
*val = cpu_to_le64(generation);
io_ctl->cur += sizeof(u64);
}
static int io_ctl_check_generation(struct io_ctl *io_ctl, u64 generation)
{
u64 *gen;
if (io_ctl->check_crcs) {
io_ctl->cur += sizeof(u32) * io_ctl->num_pages;
io_ctl->size -= sizeof(u64) +
(sizeof(u32) * io_ctl->num_pages);
} else {
io_ctl->cur += sizeof(u64);
io_ctl->size -= sizeof(u64) * 2;
}
gen = io_ctl->cur;
if (le64_to_cpu(*gen) != generation) {
printk_ratelimited(KERN_ERR "btrfs: space cache generation "
"(%Lu) does not match inode (%Lu)\n", *gen,
generation);
io_ctl_unmap_page(io_ctl);
return -EIO;
}
io_ctl->cur += sizeof(u64);
return 0;
}
static void io_ctl_set_crc(struct io_ctl *io_ctl, int index)
{
u32 *tmp;
u32 crc = ~(u32)0;
unsigned offset = 0;
if (!io_ctl->check_crcs) {
io_ctl_unmap_page(io_ctl);
return;
}
if (index == 0)
offset = sizeof(u32) * io_ctl->num_pages;;
crc = btrfs_csum_data(io_ctl->root, io_ctl->orig + offset, crc,
PAGE_CACHE_SIZE - offset);
btrfs_csum_final(crc, (char *)&crc);
io_ctl_unmap_page(io_ctl);
tmp = kmap(io_ctl->pages[0]);
tmp += index;
*tmp = crc;
kunmap(io_ctl->pages[0]);
}
static int io_ctl_check_crc(struct io_ctl *io_ctl, int index)
{
u32 *tmp, val;
u32 crc = ~(u32)0;
unsigned offset = 0;
if (!io_ctl->check_crcs) {
io_ctl_map_page(io_ctl, 0);
return 0;
}
if (index == 0)
offset = sizeof(u32) * io_ctl->num_pages;
tmp = kmap(io_ctl->pages[0]);
tmp += index;
val = *tmp;
kunmap(io_ctl->pages[0]);
io_ctl_map_page(io_ctl, 0);
crc = btrfs_csum_data(io_ctl->root, io_ctl->orig + offset, crc,
PAGE_CACHE_SIZE - offset);
btrfs_csum_final(crc, (char *)&crc);
if (val != crc) {
printk_ratelimited(KERN_ERR "btrfs: csum mismatch on free "
"space cache\n");
io_ctl_unmap_page(io_ctl);
return -EIO;
}
return 0;
}
static int io_ctl_add_entry(struct io_ctl *io_ctl, u64 offset, u64 bytes,
void *bitmap)
{
struct btrfs_free_space_entry *entry;
if (!io_ctl->cur)
return -ENOSPC;
entry = io_ctl->cur;
entry->offset = cpu_to_le64(offset);
entry->bytes = cpu_to_le64(bytes);
entry->type = (bitmap) ? BTRFS_FREE_SPACE_BITMAP :
BTRFS_FREE_SPACE_EXTENT;
io_ctl->cur += sizeof(struct btrfs_free_space_entry);
io_ctl->size -= sizeof(struct btrfs_free_space_entry);
if (io_ctl->size >= sizeof(struct btrfs_free_space_entry))
return 0;
io_ctl_set_crc(io_ctl, io_ctl->index - 1);
if (io_ctl->index >= io_ctl->num_pages)
return 0;
io_ctl_map_page(io_ctl, 1);
return 0;
}
static int io_ctl_add_bitmap(struct io_ctl *io_ctl, void *bitmap)
{
if (!io_ctl->cur)
return -ENOSPC;
if (io_ctl->cur != io_ctl->orig) {
io_ctl_set_crc(io_ctl, io_ctl->index - 1);
if (io_ctl->index >= io_ctl->num_pages)
return -ENOSPC;
io_ctl_map_page(io_ctl, 0);
}
memcpy(io_ctl->cur, bitmap, PAGE_CACHE_SIZE);
io_ctl_set_crc(io_ctl, io_ctl->index - 1);
if (io_ctl->index < io_ctl->num_pages)
io_ctl_map_page(io_ctl, 0);
return 0;
}
static void io_ctl_zero_remaining_pages(struct io_ctl *io_ctl)
{
if (io_ctl->cur != io_ctl->orig)
io_ctl_set_crc(io_ctl, io_ctl->index - 1);
else
io_ctl_unmap_page(io_ctl);
while (io_ctl->index < io_ctl->num_pages) {
io_ctl_map_page(io_ctl, 1);
io_ctl_set_crc(io_ctl, io_ctl->index - 1);
}
}
static int io_ctl_read_entry(struct io_ctl *io_ctl,
struct btrfs_free_space *entry, u8 *type)
{
struct btrfs_free_space_entry *e;
int ret;
if (!io_ctl->cur) {
ret = io_ctl_check_crc(io_ctl, io_ctl->index);
if (ret)
return ret;
}
e = io_ctl->cur;
entry->offset = le64_to_cpu(e->offset);
entry->bytes = le64_to_cpu(e->bytes);
*type = e->type;
io_ctl->cur += sizeof(struct btrfs_free_space_entry);
io_ctl->size -= sizeof(struct btrfs_free_space_entry);
if (io_ctl->size >= sizeof(struct btrfs_free_space_entry))
return 0;
io_ctl_unmap_page(io_ctl);
return 0;
}
static int io_ctl_read_bitmap(struct io_ctl *io_ctl,
struct btrfs_free_space *entry)
{
int ret;
ret = io_ctl_check_crc(io_ctl, io_ctl->index);
if (ret)
return ret;
memcpy(entry->bitmap, io_ctl->cur, PAGE_CACHE_SIZE);
io_ctl_unmap_page(io_ctl);
return 0;
}
int __load_free_space_cache(struct btrfs_root *root, struct inode *inode,
struct btrfs_free_space_ctl *ctl,
struct btrfs_path *path, u64 offset)
{
struct btrfs_free_space_header *header;
struct extent_buffer *leaf;
struct io_ctl io_ctl;
struct btrfs_key key;
struct btrfs_free_space *e, *n;
struct list_head bitmaps;
u64 num_entries;
u64 num_bitmaps;
u64 generation;
u8 type;
int ret = 0;
INIT_LIST_HEAD(&bitmaps);
if (!i_size_read(inode))
return 0;
key.objectid = BTRFS_FREE_SPACE_OBJECTID;
key.offset = offset;
key.type = 0;
ret = btrfs_search_slot(NULL, root, &key, path, 0, 0);
if (ret < 0)
return 0;
else if (ret > 0) {
btrfs_release_path(path);
return 0;
}
ret = -1;
leaf = path->nodes[0];
header = btrfs_item_ptr(leaf, path->slots[0],
struct btrfs_free_space_header);
num_entries = btrfs_free_space_entries(leaf, header);
num_bitmaps = btrfs_free_space_bitmaps(leaf, header);
generation = btrfs_free_space_generation(leaf, header);
btrfs_release_path(path);
if (BTRFS_I(inode)->generation != generation) {
printk(KERN_ERR "btrfs: free space inode generation (%llu) did"
" not match free space cache generation (%llu)\n",
(unsigned long long)BTRFS_I(inode)->generation,
(unsigned long long)generation);
return 0;
}
if (!num_entries)
return 0;
io_ctl_init(&io_ctl, inode, root);
ret = readahead_cache(inode);
if (ret)
goto out;
ret = io_ctl_prepare_pages(&io_ctl, inode, 1);
if (ret)
goto out;
ret = io_ctl_check_crc(&io_ctl, 0);
if (ret)
goto free_cache;
ret = io_ctl_check_generation(&io_ctl, generation);
if (ret)
goto free_cache;
while (num_entries) {
e = kmem_cache_zalloc(btrfs_free_space_cachep,
GFP_NOFS);
if (!e)
goto free_cache;
ret = io_ctl_read_entry(&io_ctl, e, &type);
if (ret) {
kmem_cache_free(btrfs_free_space_cachep, e);
goto free_cache;
}
if (!e->bytes) {
kmem_cache_free(btrfs_free_space_cachep, e);
goto free_cache;
}
if (type == BTRFS_FREE_SPACE_EXTENT) {
spin_lock(&ctl->tree_lock);
ret = link_free_space(ctl, e);
spin_unlock(&ctl->tree_lock);
if (ret) {
printk(KERN_ERR "Duplicate entries in "
"free space cache, dumping\n");
kmem_cache_free(btrfs_free_space_cachep, e);
goto free_cache;
}
} else {
BUG_ON(!num_bitmaps);
num_bitmaps--;
e->bitmap = kzalloc(PAGE_CACHE_SIZE, GFP_NOFS);
if (!e->bitmap) {
kmem_cache_free(
btrfs_free_space_cachep, e);
goto free_cache;
}
spin_lock(&ctl->tree_lock);
ret = link_free_space(ctl, e);
ctl->total_bitmaps++;
ctl->op->recalc_thresholds(ctl);
spin_unlock(&ctl->tree_lock);
if (ret) {
printk(KERN_ERR "Duplicate entries in "
"free space cache, dumping\n");
kmem_cache_free(btrfs_free_space_cachep, e);
goto free_cache;
}
list_add_tail(&e->list, &bitmaps);
}
num_entries--;
}
io_ctl_unmap_page(&io_ctl);
list_for_each_entry_safe(e, n, &bitmaps, list) {
list_del_init(&e->list);
ret = io_ctl_read_bitmap(&io_ctl, e);
if (ret)
goto free_cache;
}
io_ctl_drop_pages(&io_ctl);
ret = 1;
out:
io_ctl_free(&io_ctl);
return ret;
free_cache:
io_ctl_drop_pages(&io_ctl);
__btrfs_remove_free_space_cache(ctl);
goto out;
}
int load_free_space_cache(struct btrfs_fs_info *fs_info,
struct btrfs_block_group_cache *block_group)
{
struct btrfs_free_space_ctl *ctl = block_group->free_space_ctl;
struct btrfs_root *root = fs_info->tree_root;
struct inode *inode;
struct btrfs_path *path;
int ret = 0;
bool matched;
u64 used = btrfs_block_group_used(&block_group->item);
if (btrfs_fs_closing(fs_info))
return 0;
spin_lock(&block_group->lock);
if (block_group->disk_cache_state != BTRFS_DC_WRITTEN) {
spin_unlock(&block_group->lock);
return 0;
}
spin_unlock(&block_group->lock);
path = btrfs_alloc_path();
if (!path)
return 0;
inode = lookup_free_space_inode(root, block_group, path);
if (IS_ERR(inode)) {
btrfs_free_path(path);
return 0;
}
spin_lock(&block_group->lock);
if (block_group->disk_cache_state != BTRFS_DC_WRITTEN) {
spin_unlock(&block_group->lock);
goto out;
}
spin_unlock(&block_group->lock);
ret = __load_free_space_cache(fs_info->tree_root, inode, ctl,
path, block_group->key.objectid);
btrfs_free_path(path);
if (ret <= 0)
goto out;
spin_lock(&ctl->tree_lock);
matched = (ctl->free_space == (block_group->key.offset - used -
block_group->bytes_super));
spin_unlock(&ctl->tree_lock);
if (!matched) {
__btrfs_remove_free_space_cache(ctl);
printk(KERN_ERR "block group %llu has an wrong amount of free "
"space\n", block_group->key.objectid);
ret = -1;
}
out:
if (ret < 0) {
spin_lock(&block_group->lock);
block_group->disk_cache_state = BTRFS_DC_CLEAR;
spin_unlock(&block_group->lock);
ret = 0;
printk(KERN_ERR "btrfs: failed to load free space cache "
"for block group %llu\n", block_group->key.objectid);
}
iput(inode);
return ret;
}
int __btrfs_write_out_cache(struct btrfs_root *root, struct inode *inode,
struct btrfs_free_space_ctl *ctl,
struct btrfs_block_group_cache *block_group,
struct btrfs_trans_handle *trans,
struct btrfs_path *path, u64 offset)
{
struct btrfs_free_space_header *header;
struct extent_buffer *leaf;
struct rb_node *node;
struct list_head *pos, *n;
struct extent_state *cached_state = NULL;
struct btrfs_free_cluster *cluster = NULL;
struct extent_io_tree *unpin = NULL;
struct io_ctl io_ctl;
struct list_head bitmap_list;
struct btrfs_key key;
u64 start, end, len;
int entries = 0;
int bitmaps = 0;
int ret;
int err = -1;
INIT_LIST_HEAD(&bitmap_list);
if (!i_size_read(inode))
return -1;
io_ctl_init(&io_ctl, inode, root);
if (block_group && !list_empty(&block_group->cluster_list))
cluster = list_entry(block_group->cluster_list.next,
struct btrfs_free_cluster,
block_group_list);
unpin = root->fs_info->pinned_extents;
io_ctl_prepare_pages(&io_ctl, inode, 0);
lock_extent_bits(&BTRFS_I(inode)->io_tree, 0, i_size_read(inode) - 1,
0, &cached_state, GFP_NOFS);
if (block_group)
start = block_group->key.objectid;
node = rb_first(&ctl->free_space_offset);
if (!node && cluster) {
node = rb_first(&cluster->root);
cluster = NULL;
}
if (io_ctl.check_crcs &&
(io_ctl.num_pages * sizeof(u32)) >= PAGE_CACHE_SIZE) {
WARN_ON(1);
goto out_nospc;
}
io_ctl_set_generation(&io_ctl, trans->transid);
while (node) {
struct btrfs_free_space *e;
e = rb_entry(node, struct btrfs_free_space, offset_index);
entries++;
ret = io_ctl_add_entry(&io_ctl, e->offset, e->bytes,
e->bitmap);
if (ret)
goto out_nospc;
if (e->bitmap) {
list_add_tail(&e->list, &bitmap_list);
bitmaps++;
}
node = rb_next(node);
if (!node && cluster) {
node = rb_first(&cluster->root);
cluster = NULL;
}
}
while (block_group && (start < block_group->key.objectid +
block_group->key.offset)) {
ret = find_first_extent_bit(unpin, start, &start, &end,
EXTENT_DIRTY);
if (ret) {
ret = 0;
break;
}
if (start >= block_group->key.objectid +
block_group->key.offset)
break;
len = block_group->key.objectid +
block_group->key.offset - start;
len = min(len, end + 1 - start);
entries++;
ret = io_ctl_add_entry(&io_ctl, start, len, NULL);
if (ret)
goto out_nospc;
start = end + 1;
}
list_for_each_safe(pos, n, &bitmap_list) {
struct btrfs_free_space *entry =
list_entry(pos, struct btrfs_free_space, list);
ret = io_ctl_add_bitmap(&io_ctl, entry->bitmap);
if (ret)
goto out_nospc;
list_del_init(&entry->list);
}
io_ctl_zero_remaining_pages(&io_ctl);
ret = btrfs_dirty_pages(root, inode, io_ctl.pages, io_ctl.num_pages,
0, i_size_read(inode), &cached_state);
io_ctl_drop_pages(&io_ctl);
unlock_extent_cached(&BTRFS_I(inode)->io_tree, 0,
i_size_read(inode) - 1, &cached_state, GFP_NOFS);
if (ret)
goto out;
ret = filemap_write_and_wait(inode->i_mapping);
if (ret)
goto out;
key.objectid = BTRFS_FREE_SPACE_OBJECTID;
key.offset = offset;
key.type = 0;
ret = btrfs_search_slot(trans, root, &key, path, 0, 1);
if (ret < 0) {
clear_extent_bit(&BTRFS_I(inode)->io_tree, 0, inode->i_size - 1,
EXTENT_DIRTY | EXTENT_DELALLOC, 0, 0, NULL,
GFP_NOFS);
goto out;
}
leaf = path->nodes[0];
if (ret > 0) {
struct btrfs_key found_key;
BUG_ON(!path->slots[0]);
path->slots[0]--;
btrfs_item_key_to_cpu(leaf, &found_key, path->slots[0]);
if (found_key.objectid != BTRFS_FREE_SPACE_OBJECTID ||
found_key.offset != offset) {
clear_extent_bit(&BTRFS_I(inode)->io_tree, 0,
inode->i_size - 1,
EXTENT_DIRTY | EXTENT_DELALLOC, 0, 0,
NULL, GFP_NOFS);
btrfs_release_path(path);
goto out;
}
}
BTRFS_I(inode)->generation = trans->transid;
header = btrfs_item_ptr(leaf, path->slots[0],
struct btrfs_free_space_header);
btrfs_set_free_space_entries(leaf, header, entries);
btrfs_set_free_space_bitmaps(leaf, header, bitmaps);
btrfs_set_free_space_generation(leaf, header, trans->transid);
btrfs_mark_buffer_dirty(leaf);
btrfs_release_path(path);
err = 0;
out:
io_ctl_free(&io_ctl);
if (err) {
invalidate_inode_pages2(inode->i_mapping);
BTRFS_I(inode)->generation = 0;
}
btrfs_update_inode(trans, root, inode);
return err;
out_nospc:
list_for_each_safe(pos, n, &bitmap_list) {
struct btrfs_free_space *entry =
list_entry(pos, struct btrfs_free_space, list);
list_del_init(&entry->list);
}
io_ctl_drop_pages(&io_ctl);
unlock_extent_cached(&BTRFS_I(inode)->io_tree, 0,
i_size_read(inode) - 1, &cached_state, GFP_NOFS);
goto out;
}
int btrfs_write_out_cache(struct btrfs_root *root,
struct btrfs_trans_handle *trans,
struct btrfs_block_group_cache *block_group,
struct btrfs_path *path)
{
struct btrfs_free_space_ctl *ctl = block_group->free_space_ctl;
struct inode *inode;
int ret = 0;
root = root->fs_info->tree_root;
spin_lock(&block_group->lock);
if (block_group->disk_cache_state < BTRFS_DC_SETUP) {
spin_unlock(&block_group->lock);
return 0;
}
spin_unlock(&block_group->lock);
inode = lookup_free_space_inode(root, block_group, path);
if (IS_ERR(inode))
return 0;
ret = __btrfs_write_out_cache(root, inode, ctl, block_group, trans,
path, block_group->key.objectid);
if (ret) {
spin_lock(&block_group->lock);
block_group->disk_cache_state = BTRFS_DC_ERROR;
spin_unlock(&block_group->lock);
ret = 0;
#ifdef DEBUG
printk(KERN_ERR "btrfs: failed to write free space cace "
"for block group %llu\n", block_group->key.objectid);
#endif
}
iput(inode);
return ret;
}
static inline unsigned long offset_to_bit(u64 bitmap_start, u32 unit,
u64 offset)
{
BUG_ON(offset < bitmap_start);
offset -= bitmap_start;
return (unsigned long)(div_u64(offset, unit));
}
static inline unsigned long bytes_to_bits(u64 bytes, u32 unit)
{
return (unsigned long)(div_u64(bytes, unit));
}
static inline u64 offset_to_bitmap(struct btrfs_free_space_ctl *ctl,
u64 offset)
{
u64 bitmap_start;
u64 bytes_per_bitmap;
bytes_per_bitmap = BITS_PER_BITMAP * ctl->unit;
bitmap_start = offset - ctl->start;
bitmap_start = div64_u64(bitmap_start, bytes_per_bitmap);
bitmap_start *= bytes_per_bitmap;
bitmap_start += ctl->start;
return bitmap_start;
}
static int tree_insert_offset(struct rb_root *root, u64 offset,
struct rb_node *node, int bitmap)
{
struct rb_node **p = &root->rb_node;
struct rb_node *parent = NULL;
struct btrfs_free_space *info;
while (*p) {
parent = *p;
info = rb_entry(parent, struct btrfs_free_space, offset_index);
if (offset < info->offset) {
p = &(*p)->rb_left;
} else if (offset > info->offset) {
p = &(*p)->rb_right;
} else {
if (bitmap) {
if (info->bitmap) {
WARN_ON_ONCE(1);
return -EEXIST;
}
p = &(*p)->rb_right;
} else {
if (!info->bitmap) {
WARN_ON_ONCE(1);
return -EEXIST;
}
p = &(*p)->rb_left;
}
}
}
rb_link_node(node, parent, p);
rb_insert_color(node, root);
return 0;
}
static struct btrfs_free_space *
tree_search_offset(struct btrfs_free_space_ctl *ctl,
u64 offset, int bitmap_only, int fuzzy)
{
struct rb_node *n = ctl->free_space_offset.rb_node;
struct btrfs_free_space *entry, *prev = NULL;
while (1) {
if (!n) {
entry = NULL;
break;
}
entry = rb_entry(n, struct btrfs_free_space, offset_index);
prev = entry;
if (offset < entry->offset)
n = n->rb_left;
else if (offset > entry->offset)
n = n->rb_right;
else
break;
}
if (bitmap_only) {
if (!entry)
return NULL;
if (entry->bitmap)
return entry;
n = rb_next(n);
if (!n)
return NULL;
entry = rb_entry(n, struct btrfs_free_space, offset_index);
if (entry->offset != offset)
return NULL;
WARN_ON(!entry->bitmap);
return entry;
} else if (entry) {
if (entry->bitmap) {
n = &entry->offset_index;
while (1) {
n = rb_prev(n);
if (!n)
break;
prev = rb_entry(n, struct btrfs_free_space,
offset_index);
if (!prev->bitmap) {
if (prev->offset + prev->bytes > offset)
entry = prev;
break;
}
}
}
return entry;
}
if (!prev)
return NULL;
entry = prev;
if (entry->offset > offset) {
n = rb_prev(&entry->offset_index);
if (n) {
entry = rb_entry(n, struct btrfs_free_space,
offset_index);
BUG_ON(entry->offset > offset);
} else {
if (fuzzy)
return entry;
else
return NULL;
}
}
if (entry->bitmap) {
n = &entry->offset_index;
while (1) {
n = rb_prev(n);
if (!n)
break;
prev = rb_entry(n, struct btrfs_free_space,
offset_index);
if (!prev->bitmap) {
if (prev->offset + prev->bytes > offset)
return prev;
break;
}
}
if (entry->offset + BITS_PER_BITMAP * ctl->unit > offset)
return entry;
} else if (entry->offset + entry->bytes > offset)
return entry;
if (!fuzzy)
return NULL;
while (1) {
if (entry->bitmap) {
if (entry->offset + BITS_PER_BITMAP *
ctl->unit > offset)
break;
} else {
if (entry->offset + entry->bytes > offset)
break;
}
n = rb_next(&entry->offset_index);
if (!n)
return NULL;
entry = rb_entry(n, struct btrfs_free_space, offset_index);
}
return entry;
}
static inline void
__unlink_free_space(struct btrfs_free_space_ctl *ctl,
struct btrfs_free_space *info)
{
rb_erase(&info->offset_index, &ctl->free_space_offset);
ctl->free_extents--;
}
static void unlink_free_space(struct btrfs_free_space_ctl *ctl,
struct btrfs_free_space *info)
{
__unlink_free_space(ctl, info);
ctl->free_space -= info->bytes;
}
static int link_free_space(struct btrfs_free_space_ctl *ctl,
struct btrfs_free_space *info)
{
int ret = 0;
BUG_ON(!info->bitmap && !info->bytes);
ret = tree_insert_offset(&ctl->free_space_offset, info->offset,
&info->offset_index, (info->bitmap != NULL));
if (ret)
return ret;
ctl->free_space += info->bytes;
ctl->free_extents++;
return ret;
}
static void recalculate_thresholds(struct btrfs_free_space_ctl *ctl)
{
struct btrfs_block_group_cache *block_group = ctl->private;
u64 max_bytes;
u64 bitmap_bytes;
u64 extent_bytes;
u64 size = block_group->key.offset;
u64 bytes_per_bg = BITS_PER_BITMAP * block_group->sectorsize;
int max_bitmaps = div64_u64(size + bytes_per_bg - 1, bytes_per_bg);
BUG_ON(ctl->total_bitmaps > max_bitmaps);
if (size < 1024 * 1024 * 1024)
max_bytes = MAX_CACHE_BYTES_PER_GIG;
else
max_bytes = MAX_CACHE_BYTES_PER_GIG *
div64_u64(size, 1024 * 1024 * 1024);
bitmap_bytes = (ctl->total_bitmaps + 1) * PAGE_CACHE_SIZE;
if (bitmap_bytes >= max_bytes) {
ctl->extents_thresh = 0;
return;
}
extent_bytes = max_bytes - bitmap_bytes;
extent_bytes = min_t(u64, extent_bytes, div64_u64(max_bytes, 2));
ctl->extents_thresh =
div64_u64(extent_bytes, (sizeof(struct btrfs_free_space)));
}
static inline void __bitmap_clear_bits(struct btrfs_free_space_ctl *ctl,
struct btrfs_free_space *info,
u64 offset, u64 bytes)
{
unsigned long start, count;
start = offset_to_bit(info->offset, ctl->unit, offset);
count = bytes_to_bits(bytes, ctl->unit);
BUG_ON(start + count > BITS_PER_BITMAP);
bitmap_clear(info->bitmap, start, count);
info->bytes -= bytes;
}
static void bitmap_clear_bits(struct btrfs_free_space_ctl *ctl,
struct btrfs_free_space *info, u64 offset,
u64 bytes)
{
__bitmap_clear_bits(ctl, info, offset, bytes);
ctl->free_space -= bytes;
}
static void bitmap_set_bits(struct btrfs_free_space_ctl *ctl,
struct btrfs_free_space *info, u64 offset,
u64 bytes)
{
unsigned long start, count;
start = offset_to_bit(info->offset, ctl->unit, offset);
count = bytes_to_bits(bytes, ctl->unit);
BUG_ON(start + count > BITS_PER_BITMAP);
bitmap_set(info->bitmap, start, count);
info->bytes += bytes;
ctl->free_space += bytes;
}
static int search_bitmap(struct btrfs_free_space_ctl *ctl,
struct btrfs_free_space *bitmap_info, u64 *offset,
u64 *bytes)
{
unsigned long found_bits = 0;
unsigned long bits, i;
unsigned long next_zero;
i = offset_to_bit(bitmap_info->offset, ctl->unit,
max_t(u64, *offset, bitmap_info->offset));
bits = bytes_to_bits(*bytes, ctl->unit);
for (i = find_next_bit(bitmap_info->bitmap, BITS_PER_BITMAP, i);
i < BITS_PER_BITMAP;
i = find_next_bit(bitmap_info->bitmap, BITS_PER_BITMAP, i + 1)) {
next_zero = find_next_zero_bit(bitmap_info->bitmap,
BITS_PER_BITMAP, i);
if ((next_zero - i) >= bits) {
found_bits = next_zero - i;
break;
}
i = next_zero;
}
if (found_bits) {
*offset = (u64)(i * ctl->unit) + bitmap_info->offset;
*bytes = (u64)(found_bits) * ctl->unit;
return 0;
}
return -1;
}
static struct btrfs_free_space *
find_free_space(struct btrfs_free_space_ctl *ctl, u64 *offset, u64 *bytes)
{
struct btrfs_free_space *entry;
struct rb_node *node;
int ret;
if (!ctl->free_space_offset.rb_node)
return NULL;
entry = tree_search_offset(ctl, offset_to_bitmap(ctl, *offset), 0, 1);
if (!entry)
return NULL;
for (node = &entry->offset_index; node; node = rb_next(node)) {
entry = rb_entry(node, struct btrfs_free_space, offset_index);
if (entry->bytes < *bytes)
continue;
if (entry->bitmap) {
ret = search_bitmap(ctl, entry, offset, bytes);
if (!ret)
return entry;
continue;
}
*offset = entry->offset;
*bytes = entry->bytes;
return entry;
}
return NULL;
}
static void add_new_bitmap(struct btrfs_free_space_ctl *ctl,
struct btrfs_free_space *info, u64 offset)
{
info->offset = offset_to_bitmap(ctl, offset);
info->bytes = 0;
INIT_LIST_HEAD(&info->list);
link_free_space(ctl, info);
ctl->total_bitmaps++;
ctl->op->recalc_thresholds(ctl);
}
static void free_bitmap(struct btrfs_free_space_ctl *ctl,
struct btrfs_free_space *bitmap_info)
{
unlink_free_space(ctl, bitmap_info);
kfree(bitmap_info->bitmap);
kmem_cache_free(btrfs_free_space_cachep, bitmap_info);
ctl->total_bitmaps--;
ctl->op->recalc_thresholds(ctl);
}
static noinline int remove_from_bitmap(struct btrfs_free_space_ctl *ctl,
struct btrfs_free_space *bitmap_info,
u64 *offset, u64 *bytes)
{
u64 end;
u64 search_start, search_bytes;
int ret;
again:
end = bitmap_info->offset + (u64)(BITS_PER_BITMAP * ctl->unit) - 1;
search_start = *offset;
search_bytes = *bytes;
search_bytes = min(search_bytes, end - search_start + 1);
ret = search_bitmap(ctl, bitmap_info, &search_start, &search_bytes);
BUG_ON(ret < 0 || search_start != *offset);
if (*offset > bitmap_info->offset && *offset + *bytes > end) {
bitmap_clear_bits(ctl, bitmap_info, *offset, end - *offset + 1);
*bytes -= end - *offset + 1;
*offset = end + 1;
} else if (*offset >= bitmap_info->offset && *offset + *bytes <= end) {
bitmap_clear_bits(ctl, bitmap_info, *offset, *bytes);
*bytes = 0;
}
if (*bytes) {
struct rb_node *next = rb_next(&bitmap_info->offset_index);
if (!bitmap_info->bytes)
free_bitmap(ctl, bitmap_info);
if (!next)
return -EINVAL;
bitmap_info = rb_entry(next, struct btrfs_free_space,
offset_index);
if (!bitmap_info->bitmap)
return -EAGAIN;
search_start = *offset;
search_bytes = *bytes;
ret = search_bitmap(ctl, bitmap_info, &search_start,
&search_bytes);
if (ret < 0 || search_start != *offset)
return -EAGAIN;
goto again;
} else if (!bitmap_info->bytes)
free_bitmap(ctl, bitmap_info);
return 0;
}
static u64 add_bytes_to_bitmap(struct btrfs_free_space_ctl *ctl,
struct btrfs_free_space *info, u64 offset,
u64 bytes)
{
u64 bytes_to_set = 0;
u64 end;
end = info->offset + (u64)(BITS_PER_BITMAP * ctl->unit);
bytes_to_set = min(end - offset, bytes);
bitmap_set_bits(ctl, info, offset, bytes_to_set);
return bytes_to_set;
}
static bool use_bitmap(struct btrfs_free_space_ctl *ctl,
struct btrfs_free_space *info)
{
struct btrfs_block_group_cache *block_group = ctl->private;
if (ctl->free_extents < ctl->extents_thresh) {
if (info->bytes <= block_group->sectorsize * 4) {
if (ctl->free_extents * 2 <= ctl->extents_thresh)
return false;
} else {
return false;
}
}
if (BITS_PER_BITMAP * block_group->sectorsize >
block_group->key.offset)
return false;
return true;
}
static int insert_into_bitmap(struct btrfs_free_space_ctl *ctl,
struct btrfs_free_space *info)
{
struct btrfs_free_space *bitmap_info;
struct btrfs_block_group_cache *block_group = NULL;
int added = 0;
u64 bytes, offset, bytes_added;
int ret;
bytes = info->bytes;
offset = info->offset;
if (!ctl->op->use_bitmap(ctl, info))
return 0;
if (ctl->op == &free_space_op)
block_group = ctl->private;
again:
if (block_group && !list_empty(&block_group->cluster_list)) {
struct btrfs_free_cluster *cluster;
struct rb_node *node;
struct btrfs_free_space *entry;
cluster = list_entry(block_group->cluster_list.next,
struct btrfs_free_cluster,
block_group_list);
spin_lock(&cluster->lock);
node = rb_first(&cluster->root);
if (!node) {
spin_unlock(&cluster->lock);
goto no_cluster_bitmap;
}
entry = rb_entry(node, struct btrfs_free_space, offset_index);
if (!entry->bitmap) {
spin_unlock(&cluster->lock);
goto no_cluster_bitmap;
}
if (entry->offset == offset_to_bitmap(ctl, offset)) {
bytes_added = add_bytes_to_bitmap(ctl, entry,
offset, bytes);
bytes -= bytes_added;
offset += bytes_added;
}
spin_unlock(&cluster->lock);
if (!bytes) {
ret = 1;
goto out;
}
}
no_cluster_bitmap:
bitmap_info = tree_search_offset(ctl, offset_to_bitmap(ctl, offset),
1, 0);
if (!bitmap_info) {
BUG_ON(added);
goto new_bitmap;
}
bytes_added = add_bytes_to_bitmap(ctl, bitmap_info, offset, bytes);
bytes -= bytes_added;
offset += bytes_added;
added = 0;
if (!bytes) {
ret = 1;
goto out;
} else
goto again;
new_bitmap:
if (info && info->bitmap) {
add_new_bitmap(ctl, info, offset);
added = 1;
info = NULL;
goto again;
} else {
spin_unlock(&ctl->tree_lock);
if (!info) {
info = kmem_cache_zalloc(btrfs_free_space_cachep,
GFP_NOFS);
if (!info) {
spin_lock(&ctl->tree_lock);
ret = -ENOMEM;
goto out;
}
}
info->bitmap = kzalloc(PAGE_CACHE_SIZE, GFP_NOFS);
spin_lock(&ctl->tree_lock);
if (!info->bitmap) {
ret = -ENOMEM;
goto out;
}
goto again;
}
out:
if (info) {
if (info->bitmap)
kfree(info->bitmap);
kmem_cache_free(btrfs_free_space_cachep, info);
}
return ret;
}
static bool try_merge_free_space(struct btrfs_free_space_ctl *ctl,
struct btrfs_free_space *info, bool update_stat)
{
struct btrfs_free_space *left_info;
struct btrfs_free_space *right_info;
bool merged = false;
u64 offset = info->offset;
u64 bytes = info->bytes;
right_info = tree_search_offset(ctl, offset + bytes, 0, 0);
if (right_info && rb_prev(&right_info->offset_index))
left_info = rb_entry(rb_prev(&right_info->offset_index),
struct btrfs_free_space, offset_index);
else
left_info = tree_search_offset(ctl, offset - 1, 0, 0);
if (right_info && !right_info->bitmap) {
if (update_stat)
unlink_free_space(ctl, right_info);
else
__unlink_free_space(ctl, right_info);
info->bytes += right_info->bytes;
kmem_cache_free(btrfs_free_space_cachep, right_info);
merged = true;
}
if (left_info && !left_info->bitmap &&
left_info->offset + left_info->bytes == offset) {
if (update_stat)
unlink_free_space(ctl, left_info);
else
__unlink_free_space(ctl, left_info);
info->offset = left_info->offset;
info->bytes += left_info->bytes;
kmem_cache_free(btrfs_free_space_cachep, left_info);
merged = true;
}
return merged;
}
int __btrfs_add_free_space(struct btrfs_free_space_ctl *ctl,
u64 offset, u64 bytes)
{
struct btrfs_free_space *info;
int ret = 0;
info = kmem_cache_zalloc(btrfs_free_space_cachep, GFP_NOFS);
if (!info)
return -ENOMEM;
info->offset = offset;
info->bytes = bytes;
spin_lock(&ctl->tree_lock);
if (try_merge_free_space(ctl, info, true))
goto link;
ret = insert_into_bitmap(ctl, info);
if (ret < 0) {
goto out;
} else if (ret) {
ret = 0;
goto out;
}
link:
ret = link_free_space(ctl, info);
if (ret)
kmem_cache_free(btrfs_free_space_cachep, info);
out:
spin_unlock(&ctl->tree_lock);
if (ret) {
printk(KERN_CRIT "btrfs: unable to add free space :%d\n", ret);
BUG_ON(ret == -EEXIST);
}
return ret;
}
int btrfs_remove_free_space(struct btrfs_block_group_cache *block_group,
u64 offset, u64 bytes)
{
struct btrfs_free_space_ctl *ctl = block_group->free_space_ctl;
struct btrfs_free_space *info;
struct btrfs_free_space *next_info = NULL;
int ret = 0;
spin_lock(&ctl->tree_lock);
again:
info = tree_search_offset(ctl, offset, 0, 0);
if (!info) {
info = tree_search_offset(ctl, offset_to_bitmap(ctl, offset),
1, 0);
if (!info) {
goto out_lock;
}
}
if (info->bytes < bytes && rb_next(&info->offset_index)) {
u64 end;
next_info = rb_entry(rb_next(&info->offset_index),
struct btrfs_free_space,
offset_index);
if (next_info->bitmap)
end = next_info->offset +
BITS_PER_BITMAP * ctl->unit - 1;
else
end = next_info->offset + next_info->bytes;
if (next_info->bytes < bytes ||
next_info->offset > offset || offset > end) {
printk(KERN_CRIT "Found free space at %llu, size %llu,"
" trying to use %llu\n",
(unsigned long long)info->offset,
(unsigned long long)info->bytes,
(unsigned long long)bytes);
WARN_ON(1);
ret = -EINVAL;
goto out_lock;
}
info = next_info;
}
if (info->bytes == bytes) {
unlink_free_space(ctl, info);
if (info->bitmap) {
kfree(info->bitmap);
ctl->total_bitmaps--;
}
kmem_cache_free(btrfs_free_space_cachep, info);
ret = 0;
goto out_lock;
}
if (!info->bitmap && info->offset == offset) {
unlink_free_space(ctl, info);
info->offset += bytes;
info->bytes -= bytes;
ret = link_free_space(ctl, info);
WARN_ON(ret);
goto out_lock;
}
if (!info->bitmap && info->offset <= offset &&
info->offset + info->bytes >= offset + bytes) {
u64 old_start = info->offset;
unlink_free_space(ctl, info);
if (offset + bytes < info->offset + info->bytes) {
u64 old_end = info->offset + info->bytes;
info->offset = offset + bytes;
info->bytes = old_end - info->offset;
ret = link_free_space(ctl, info);
WARN_ON(ret);
if (ret)
goto out_lock;
} else {
kmem_cache_free(btrfs_free_space_cachep, info);
}
spin_unlock(&ctl->tree_lock);
ret = btrfs_add_free_space(block_group, old_start,
offset - old_start);
WARN_ON(ret);
goto out;
}
ret = remove_from_bitmap(ctl, info, &offset, &bytes);
if (ret == -EAGAIN)
goto again;
BUG_ON(ret);
out_lock:
spin_unlock(&ctl->tree_lock);
out:
return ret;
}
void btrfs_dump_free_space(struct btrfs_block_group_cache *block_group,
u64 bytes)
{
struct btrfs_free_space_ctl *ctl = block_group->free_space_ctl;
struct btrfs_free_space *info;
struct rb_node *n;
int count = 0;
for (n = rb_first(&ctl->free_space_offset); n; n = rb_next(n)) {
info = rb_entry(n, struct btrfs_free_space, offset_index);
if (info->bytes >= bytes)
count++;
printk(KERN_CRIT "entry offset %llu, bytes %llu, bitmap %s\n",
(unsigned long long)info->offset,
(unsigned long long)info->bytes,
(info->bitmap) ? "yes" : "no");
}
printk(KERN_INFO "block group has cluster?: %s\n",
list_empty(&block_group->cluster_list) ? "no" : "yes");
printk(KERN_INFO "%d blocks of free space at or bigger than bytes is"
"\n", count);
}
void btrfs_init_free_space_ctl(struct btrfs_block_group_cache *block_group)
{
struct btrfs_free_space_ctl *ctl = block_group->free_space_ctl;
spin_lock_init(&ctl->tree_lock);
ctl->unit = block_group->sectorsize;
ctl->start = block_group->key.objectid;
ctl->private = block_group;
ctl->op = &free_space_op;
ctl->extents_thresh = ((1024 * 32) / 2) /
sizeof(struct btrfs_free_space);
}
static int
__btrfs_return_cluster_to_free_space(
struct btrfs_block_group_cache *block_group,
struct btrfs_free_cluster *cluster)
{
struct btrfs_free_space_ctl *ctl = block_group->free_space_ctl;
struct btrfs_free_space *entry;
struct rb_node *node;
spin_lock(&cluster->lock);
if (cluster->block_group != block_group)
goto out;
cluster->block_group = NULL;
cluster->window_start = 0;
list_del_init(&cluster->block_group_list);
node = rb_first(&cluster->root);
while (node) {
bool bitmap;
entry = rb_entry(node, struct btrfs_free_space, offset_index);
node = rb_next(&entry->offset_index);
rb_erase(&entry->offset_index, &cluster->root);
bitmap = (entry->bitmap != NULL);
if (!bitmap)
try_merge_free_space(ctl, entry, false);
tree_insert_offset(&ctl->free_space_offset,
entry->offset, &entry->offset_index, bitmap);
}
cluster->root = RB_ROOT;
out:
spin_unlock(&cluster->lock);
btrfs_put_block_group(block_group);
return 0;
}
void __btrfs_remove_free_space_cache_locked(struct btrfs_free_space_ctl *ctl)
{
struct btrfs_free_space *info;
struct rb_node *node;
while ((node = rb_last(&ctl->free_space_offset)) != NULL) {
info = rb_entry(node, struct btrfs_free_space, offset_index);
if (!info->bitmap) {
unlink_free_space(ctl, info);
kmem_cache_free(btrfs_free_space_cachep, info);
} else {
free_bitmap(ctl, info);
}
if (need_resched()) {
spin_unlock(&ctl->tree_lock);
cond_resched();
spin_lock(&ctl->tree_lock);
}
}
}
void __btrfs_remove_free_space_cache(struct btrfs_free_space_ctl *ctl)
{
spin_lock(&ctl->tree_lock);
__btrfs_remove_free_space_cache_locked(ctl);
spin_unlock(&ctl->tree_lock);
}
void btrfs_remove_free_space_cache(struct btrfs_block_group_cache *block_group)
{
struct btrfs_free_space_ctl *ctl = block_group->free_space_ctl;
struct btrfs_free_cluster *cluster;
struct list_head *head;
spin_lock(&ctl->tree_lock);
while ((head = block_group->cluster_list.next) !=
&block_group->cluster_list) {
cluster = list_entry(head, struct btrfs_free_cluster,
block_group_list);
WARN_ON(cluster->block_group != block_group);
__btrfs_return_cluster_to_free_space(block_group, cluster);
if (need_resched()) {
spin_unlock(&ctl->tree_lock);
cond_resched();
spin_lock(&ctl->tree_lock);
}
}
__btrfs_remove_free_space_cache_locked(ctl);
spin_unlock(&ctl->tree_lock);
}
u64 btrfs_find_space_for_alloc(struct btrfs_block_group_cache *block_group,
u64 offset, u64 bytes, u64 empty_size)
{
struct btrfs_free_space_ctl *ctl = block_group->free_space_ctl;
struct btrfs_free_space *entry = NULL;
u64 bytes_search = bytes + empty_size;
u64 ret = 0;
spin_lock(&ctl->tree_lock);
entry = find_free_space(ctl, &offset, &bytes_search);
if (!entry)
goto out;
ret = offset;
if (entry->bitmap) {
bitmap_clear_bits(ctl, entry, offset, bytes);
if (!entry->bytes)
free_bitmap(ctl, entry);
} else {
unlink_free_space(ctl, entry);
entry->offset += bytes;
entry->bytes -= bytes;
if (!entry->bytes)
kmem_cache_free(btrfs_free_space_cachep, entry);
else
link_free_space(ctl, entry);
}
out:
spin_unlock(&ctl->tree_lock);
return ret;
}
int btrfs_return_cluster_to_free_space(
struct btrfs_block_group_cache *block_group,
struct btrfs_free_cluster *cluster)
{
struct btrfs_free_space_ctl *ctl;
int ret;
spin_lock(&cluster->lock);
if (!block_group) {
block_group = cluster->block_group;
if (!block_group) {
spin_unlock(&cluster->lock);
return 0;
}
} else if (cluster->block_group != block_group) {
spin_unlock(&cluster->lock);
return 0;
}
atomic_inc(&block_group->count);
spin_unlock(&cluster->lock);
ctl = block_group->free_space_ctl;
spin_lock(&ctl->tree_lock);
ret = __btrfs_return_cluster_to_free_space(block_group, cluster);
spin_unlock(&ctl->tree_lock);
btrfs_put_block_group(block_group);
return ret;
}
static u64 btrfs_alloc_from_bitmap(struct btrfs_block_group_cache *block_group,
struct btrfs_free_cluster *cluster,
struct btrfs_free_space *entry,
u64 bytes, u64 min_start)
{
struct btrfs_free_space_ctl *ctl = block_group->free_space_ctl;
int err;
u64 search_start = cluster->window_start;
u64 search_bytes = bytes;
u64 ret = 0;
search_start = min_start;
search_bytes = bytes;
err = search_bitmap(ctl, entry, &search_start, &search_bytes);
if (err)
return 0;
ret = search_start;
__bitmap_clear_bits(ctl, entry, ret, bytes);
return ret;
}
u64 btrfs_alloc_from_cluster(struct btrfs_block_group_cache *block_group,
struct btrfs_free_cluster *cluster, u64 bytes,
u64 min_start)
{
struct btrfs_free_space_ctl *ctl = block_group->free_space_ctl;
struct btrfs_free_space *entry = NULL;
struct rb_node *node;
u64 ret = 0;
spin_lock(&cluster->lock);
if (bytes > cluster->max_size)
goto out;
if (cluster->block_group != block_group)
goto out;
node = rb_first(&cluster->root);
if (!node)
goto out;
entry = rb_entry(node, struct btrfs_free_space, offset_index);
while(1) {
if (entry->bytes < bytes ||
(!entry->bitmap && entry->offset < min_start)) {
node = rb_next(&entry->offset_index);
if (!node)
break;
entry = rb_entry(node, struct btrfs_free_space,
offset_index);
continue;
}
if (entry->bitmap) {
ret = btrfs_alloc_from_bitmap(block_group,
cluster, entry, bytes,
min_start);
if (ret == 0) {
node = rb_next(&entry->offset_index);
if (!node)
break;
entry = rb_entry(node, struct btrfs_free_space,
offset_index);
continue;
}
} else {
ret = entry->offset;
entry->offset += bytes;
entry->bytes -= bytes;
}
if (entry->bytes == 0)
rb_erase(&entry->offset_index, &cluster->root);
break;
}
out:
spin_unlock(&cluster->lock);
if (!ret)
return 0;
spin_lock(&ctl->tree_lock);
ctl->free_space -= bytes;
if (entry->bytes == 0) {
ctl->free_extents--;
if (entry->bitmap) {
kfree(entry->bitmap);
ctl->total_bitmaps--;
ctl->op->recalc_thresholds(ctl);
}
kmem_cache_free(btrfs_free_space_cachep, entry);
}
spin_unlock(&ctl->tree_lock);
return ret;
}
static int btrfs_bitmap_cluster(struct btrfs_block_group_cache *block_group,
struct btrfs_free_space *entry,
struct btrfs_free_cluster *cluster,
u64 offset, u64 bytes, u64 min_bytes)
{
struct btrfs_free_space_ctl *ctl = block_group->free_space_ctl;
unsigned long next_zero;
unsigned long i;
unsigned long search_bits;
unsigned long total_bits;
unsigned long found_bits;
unsigned long start = 0;
unsigned long total_found = 0;
int ret;
bool found = false;
i = offset_to_bit(entry->offset, block_group->sectorsize,
max_t(u64, offset, entry->offset));
search_bits = bytes_to_bits(bytes, block_group->sectorsize);
total_bits = bytes_to_bits(min_bytes, block_group->sectorsize);
again:
found_bits = 0;
for (i = find_next_bit(entry->bitmap, BITS_PER_BITMAP, i);
i < BITS_PER_BITMAP;
i = find_next_bit(entry->bitmap, BITS_PER_BITMAP, i + 1)) {
next_zero = find_next_zero_bit(entry->bitmap,
BITS_PER_BITMAP, i);
if (next_zero - i >= search_bits) {
found_bits = next_zero - i;
break;
}
i = next_zero;
}
if (!found_bits)
return -ENOSPC;
if (!found) {
start = i;
cluster->max_size = 0;
found = true;
}
total_found += found_bits;
if (cluster->max_size < found_bits * block_group->sectorsize)
cluster->max_size = found_bits * block_group->sectorsize;
if (total_found < total_bits) {
i = find_next_bit(entry->bitmap, BITS_PER_BITMAP, next_zero);
if (i - start > total_bits * 2) {
total_found = 0;
cluster->max_size = 0;
found = false;
}
goto again;
}
cluster->window_start = start * block_group->sectorsize +
entry->offset;
rb_erase(&entry->offset_index, &ctl->free_space_offset);
ret = tree_insert_offset(&cluster->root, entry->offset,
&entry->offset_index, 1);
BUG_ON(ret);
return 0;
}
static noinline int
setup_cluster_no_bitmap(struct btrfs_block_group_cache *block_group,
struct btrfs_free_cluster *cluster,
struct list_head *bitmaps, u64 offset, u64 bytes,
u64 min_bytes)
{
struct btrfs_free_space_ctl *ctl = block_group->free_space_ctl;
struct btrfs_free_space *first = NULL;
struct btrfs_free_space *entry = NULL;
struct btrfs_free_space *prev = NULL;
struct btrfs_free_space *last;
struct rb_node *node;
u64 window_start;
u64 window_free;
u64 max_extent;
u64 max_gap = 128 * 1024;
entry = tree_search_offset(ctl, offset, 0, 1);
if (!entry)
return -ENOSPC;
while (entry->bitmap) {
if (list_empty(&entry->list))
list_add_tail(&entry->list, bitmaps);
node = rb_next(&entry->offset_index);
if (!node)
return -ENOSPC;
entry = rb_entry(node, struct btrfs_free_space, offset_index);
}
window_start = entry->offset;
window_free = entry->bytes;
max_extent = entry->bytes;
first = entry;
last = entry;
prev = entry;
while (window_free <= min_bytes) {
node = rb_next(&entry->offset_index);
if (!node)
return -ENOSPC;
entry = rb_entry(node, struct btrfs_free_space, offset_index);
if (entry->bitmap) {
if (list_empty(&entry->list))
list_add_tail(&entry->list, bitmaps);
continue;
}
if (entry->offset - (prev->offset + prev->bytes) > max_gap ||
entry->offset - window_start > (min_bytes * 2)) {
first = entry;
window_start = entry->offset;
window_free = entry->bytes;
last = entry;
max_extent = entry->bytes;
} else {
last = entry;
window_free += entry->bytes;
if (entry->bytes > max_extent)
max_extent = entry->bytes;
}
prev = entry;
}
cluster->window_start = first->offset;
node = &first->offset_index;
do {
int ret;
entry = rb_entry(node, struct btrfs_free_space, offset_index);
node = rb_next(&entry->offset_index);
if (entry->bitmap)
continue;
rb_erase(&entry->offset_index, &ctl->free_space_offset);
ret = tree_insert_offset(&cluster->root, entry->offset,
&entry->offset_index, 0);
BUG_ON(ret);
} while (node && entry != last);
cluster->max_size = max_extent;
return 0;
}
static noinline int
setup_cluster_bitmap(struct btrfs_block_group_cache *block_group,
struct btrfs_free_cluster *cluster,
struct list_head *bitmaps, u64 offset, u64 bytes,
u64 min_bytes)
{
struct btrfs_free_space_ctl *ctl = block_group->free_space_ctl;
struct btrfs_free_space *entry;
int ret = -ENOSPC;
u64 bitmap_offset = offset_to_bitmap(ctl, offset);
if (ctl->total_bitmaps == 0)
return -ENOSPC;
entry = list_first_entry(bitmaps, struct btrfs_free_space, list);
if (entry->offset != bitmap_offset) {
entry = tree_search_offset(ctl, bitmap_offset, 1, 0);
if (entry && list_empty(&entry->list))
list_add(&entry->list, bitmaps);
}
list_for_each_entry(entry, bitmaps, list) {
if (entry->bytes < min_bytes)
continue;
ret = btrfs_bitmap_cluster(block_group, entry, cluster, offset,
bytes, min_bytes);
if (!ret)
return 0;
}
return -ENOSPC;
}
int btrfs_find_space_cluster(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_block_group_cache *block_group,
struct btrfs_free_cluster *cluster,
u64 offset, u64 bytes, u64 empty_size)
{
struct btrfs_free_space_ctl *ctl = block_group->free_space_ctl;
struct btrfs_free_space *entry, *tmp;
LIST_HEAD(bitmaps);
u64 min_bytes;
int ret;
if (btrfs_test_opt(root, SSD_SPREAD)) {
min_bytes = bytes + empty_size;
} else if (block_group->flags & BTRFS_BLOCK_GROUP_METADATA) {
if (trans->transaction->delayed_refs.flushing)
min_bytes = max(bytes, (bytes + empty_size) >> 1);
else
min_bytes = max(bytes, (bytes + empty_size) >> 4);
} else
min_bytes = max(bytes, (bytes + empty_size) >> 2);
spin_lock(&ctl->tree_lock);
if (ctl->free_space < min_bytes) {
spin_unlock(&ctl->tree_lock);
return -ENOSPC;
}
spin_lock(&cluster->lock);
if (cluster->block_group) {
ret = 0;
goto out;
}
ret = setup_cluster_no_bitmap(block_group, cluster, &bitmaps, offset,
bytes, min_bytes);
if (ret)
ret = setup_cluster_bitmap(block_group, cluster, &bitmaps,
offset, bytes, min_bytes);
list_for_each_entry_safe(entry, tmp, &bitmaps, list)
list_del_init(&entry->list);
if (!ret) {
atomic_inc(&block_group->count);
list_add_tail(&cluster->block_group_list,
&block_group->cluster_list);
cluster->block_group = block_group;
}
out:
spin_unlock(&cluster->lock);
spin_unlock(&ctl->tree_lock);
return ret;
}
void btrfs_init_free_cluster(struct btrfs_free_cluster *cluster)
{
spin_lock_init(&cluster->lock);
spin_lock_init(&cluster->refill_lock);
cluster->root = RB_ROOT;
cluster->max_size = 0;
INIT_LIST_HEAD(&cluster->block_group_list);
cluster->block_group = NULL;
}
int btrfs_trim_block_group(struct btrfs_block_group_cache *block_group,
u64 *trimmed, u64 start, u64 end, u64 minlen)
{
struct btrfs_free_space_ctl *ctl = block_group->free_space_ctl;
struct btrfs_free_space *entry = NULL;
struct btrfs_fs_info *fs_info = block_group->fs_info;
u64 bytes = 0;
u64 actually_trimmed;
int ret = 0;
*trimmed = 0;
while (start < end) {
spin_lock(&ctl->tree_lock);
if (ctl->free_space < minlen) {
spin_unlock(&ctl->tree_lock);
break;
}
entry = tree_search_offset(ctl, start, 0, 1);
if (!entry)
entry = tree_search_offset(ctl,
offset_to_bitmap(ctl, start),
1, 1);
if (!entry || entry->offset >= end) {
spin_unlock(&ctl->tree_lock);
break;
}
if (entry->bitmap) {
ret = search_bitmap(ctl, entry, &start, &bytes);
if (!ret) {
if (start >= end) {
spin_unlock(&ctl->tree_lock);
break;
}
bytes = min(bytes, end - start);
bitmap_clear_bits(ctl, entry, start, bytes);
if (entry->bytes == 0)
free_bitmap(ctl, entry);
} else {
start = entry->offset + BITS_PER_BITMAP *
block_group->sectorsize;
spin_unlock(&ctl->tree_lock);
ret = 0;
continue;
}
} else {
start = entry->offset;
bytes = min(entry->bytes, end - start);
unlink_free_space(ctl, entry);
kmem_cache_free(btrfs_free_space_cachep, entry);
}
spin_unlock(&ctl->tree_lock);
if (bytes >= minlen) {
struct btrfs_space_info *space_info;
int update = 0;
space_info = block_group->space_info;
spin_lock(&space_info->lock);
spin_lock(&block_group->lock);
if (!block_group->ro) {
block_group->reserved += bytes;
space_info->bytes_reserved += bytes;
update = 1;
}
spin_unlock(&block_group->lock);
spin_unlock(&space_info->lock);
ret = btrfs_error_discard_extent(fs_info->extent_root,
start,
bytes,
&actually_trimmed);
btrfs_add_free_space(block_group, start, bytes);
if (update) {
spin_lock(&space_info->lock);
spin_lock(&block_group->lock);
if (block_group->ro)
space_info->bytes_readonly += bytes;
block_group->reserved -= bytes;
space_info->bytes_reserved -= bytes;
spin_unlock(&space_info->lock);
spin_unlock(&block_group->lock);
}
if (ret)
break;
*trimmed += actually_trimmed;
}
start += bytes;
bytes = 0;
if (fatal_signal_pending(current)) {
ret = -ERESTARTSYS;
break;
}
cond_resched();
}
return ret;
}
u64 btrfs_find_ino_for_alloc(struct btrfs_root *fs_root)
{
struct btrfs_free_space_ctl *ctl = fs_root->free_ino_ctl;
struct btrfs_free_space *entry = NULL;
u64 ino = 0;
spin_lock(&ctl->tree_lock);
if (RB_EMPTY_ROOT(&ctl->free_space_offset))
goto out;
entry = rb_entry(rb_first(&ctl->free_space_offset),
struct btrfs_free_space, offset_index);
if (!entry->bitmap) {
ino = entry->offset;
unlink_free_space(ctl, entry);
entry->offset++;
entry->bytes--;
if (!entry->bytes)
kmem_cache_free(btrfs_free_space_cachep, entry);
else
link_free_space(ctl, entry);
} else {
u64 offset = 0;
u64 count = 1;
int ret;
ret = search_bitmap(ctl, entry, &offset, &count);
BUG_ON(ret);
ino = offset;
bitmap_clear_bits(ctl, entry, offset, 1);
if (entry->bytes == 0)
free_bitmap(ctl, entry);
}
out:
spin_unlock(&ctl->tree_lock);
return ino;
}
struct inode *lookup_free_ino_inode(struct btrfs_root *root,
struct btrfs_path *path)
{
struct inode *inode = NULL;
spin_lock(&root->cache_lock);
if (root->cache_inode)
inode = igrab(root->cache_inode);
spin_unlock(&root->cache_lock);
if (inode)
return inode;
inode = __lookup_free_space_inode(root, path, 0);
if (IS_ERR(inode))
return inode;
spin_lock(&root->cache_lock);
if (!btrfs_fs_closing(root->fs_info))
root->cache_inode = igrab(inode);
spin_unlock(&root->cache_lock);
return inode;
}
int create_free_ino_inode(struct btrfs_root *root,
struct btrfs_trans_handle *trans,
struct btrfs_path *path)
{
return __create_free_space_inode(root, trans, path,
BTRFS_FREE_INO_OBJECTID, 0);
}
int load_free_ino_cache(struct btrfs_fs_info *fs_info, struct btrfs_root *root)
{
struct btrfs_free_space_ctl *ctl = root->free_ino_ctl;
struct btrfs_path *path;
struct inode *inode;
int ret = 0;
u64 root_gen = btrfs_root_generation(&root->root_item);
if (!btrfs_test_opt(root, INODE_MAP_CACHE))
return 0;
if (btrfs_fs_closing(fs_info))
return 0;
path = btrfs_alloc_path();
if (!path)
return 0;
inode = lookup_free_ino_inode(root, path);
if (IS_ERR(inode))
goto out;
if (root_gen != BTRFS_I(inode)->generation)
goto out_put;
ret = __load_free_space_cache(root, inode, ctl, path, 0);
if (ret < 0)
printk(KERN_ERR "btrfs: failed to load free ino cache for "
"root %llu\n", root->root_key.objectid);
out_put:
iput(inode);
out:
btrfs_free_path(path);
return ret;
}
int btrfs_write_out_ino_cache(struct btrfs_root *root,
struct btrfs_trans_handle *trans,
struct btrfs_path *path)
{
struct btrfs_free_space_ctl *ctl = root->free_ino_ctl;
struct inode *inode;
int ret;
if (!btrfs_test_opt(root, INODE_MAP_CACHE))
return 0;
inode = lookup_free_ino_inode(root, path);
if (IS_ERR(inode))
return 0;
ret = __btrfs_write_out_cache(root, inode, ctl, NULL, trans, path, 0);
if (ret) {
btrfs_delalloc_release_metadata(inode, inode->i_size);
#ifdef DEBUG
printk(KERN_ERR "btrfs: failed to write free ino cache "
"for root %llu\n", root->root_key.objectid);
#endif
}
iput(inode);
return ret;
}
