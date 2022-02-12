static int start_log_trans(struct btrfs_trans_handle *trans,
struct btrfs_root *root)
{
int ret;
int err = 0;
mutex_lock(&root->log_mutex);
if (root->log_root) {
if (!root->log_start_pid) {
root->log_start_pid = current->pid;
root->log_multiple_pids = false;
} else if (root->log_start_pid != current->pid) {
root->log_multiple_pids = true;
}
atomic_inc(&root->log_batch);
atomic_inc(&root->log_writers);
mutex_unlock(&root->log_mutex);
return 0;
}
root->log_multiple_pids = false;
root->log_start_pid = current->pid;
mutex_lock(&root->fs_info->tree_log_mutex);
if (!root->fs_info->log_root_tree) {
ret = btrfs_init_log_root_tree(trans, root->fs_info);
if (ret)
err = ret;
}
if (err == 0 && !root->log_root) {
ret = btrfs_add_log_tree(trans, root);
if (ret)
err = ret;
}
mutex_unlock(&root->fs_info->tree_log_mutex);
atomic_inc(&root->log_batch);
atomic_inc(&root->log_writers);
mutex_unlock(&root->log_mutex);
return err;
}
static int join_running_log_trans(struct btrfs_root *root)
{
int ret = -ENOENT;
smp_mb();
if (!root->log_root)
return -ENOENT;
mutex_lock(&root->log_mutex);
if (root->log_root) {
ret = 0;
atomic_inc(&root->log_writers);
}
mutex_unlock(&root->log_mutex);
return ret;
}
int btrfs_pin_log_trans(struct btrfs_root *root)
{
int ret = -ENOENT;
mutex_lock(&root->log_mutex);
atomic_inc(&root->log_writers);
mutex_unlock(&root->log_mutex);
return ret;
}
void btrfs_end_log_trans(struct btrfs_root *root)
{
if (atomic_dec_and_test(&root->log_writers)) {
smp_mb();
if (waitqueue_active(&root->log_writer_wait))
wake_up(&root->log_writer_wait);
}
}
static int process_one_buffer(struct btrfs_root *log,
struct extent_buffer *eb,
struct walk_control *wc, u64 gen)
{
int ret = 0;
if (btrfs_fs_incompat(log->fs_info, MIXED_GROUPS)) {
ret = btrfs_read_buffer(eb, gen);
if (ret)
return ret;
}
if (wc->pin)
ret = btrfs_pin_extent_for_log_replay(log->fs_info->extent_root,
eb->start, eb->len);
if (!ret && btrfs_buffer_uptodate(eb, gen, 0)) {
if (wc->pin && btrfs_header_level(eb) == 0)
ret = btrfs_exclude_logged_extents(log, eb);
if (wc->write)
btrfs_write_tree_block(eb);
if (wc->wait)
btrfs_wait_tree_block_writeback(eb);
}
return ret;
}
static noinline int overwrite_item(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path,
struct extent_buffer *eb, int slot,
struct btrfs_key *key)
{
int ret;
u32 item_size;
u64 saved_i_size = 0;
int save_old_i_size = 0;
unsigned long src_ptr;
unsigned long dst_ptr;
int overwrite_root = 0;
bool inode_item = key->type == BTRFS_INODE_ITEM_KEY;
if (root->root_key.objectid != BTRFS_TREE_LOG_OBJECTID)
overwrite_root = 1;
item_size = btrfs_item_size_nr(eb, slot);
src_ptr = btrfs_item_ptr_offset(eb, slot);
ret = btrfs_search_slot(NULL, root, key, path, 0, 0);
if (ret < 0)
return ret;
if (ret == 0) {
char *src_copy;
char *dst_copy;
u32 dst_size = btrfs_item_size_nr(path->nodes[0],
path->slots[0]);
if (dst_size != item_size)
goto insert;
if (item_size == 0) {
btrfs_release_path(path);
return 0;
}
dst_copy = kmalloc(item_size, GFP_NOFS);
src_copy = kmalloc(item_size, GFP_NOFS);
if (!dst_copy || !src_copy) {
btrfs_release_path(path);
kfree(dst_copy);
kfree(src_copy);
return -ENOMEM;
}
read_extent_buffer(eb, src_copy, src_ptr, item_size);
dst_ptr = btrfs_item_ptr_offset(path->nodes[0], path->slots[0]);
read_extent_buffer(path->nodes[0], dst_copy, dst_ptr,
item_size);
ret = memcmp(dst_copy, src_copy, item_size);
kfree(dst_copy);
kfree(src_copy);
if (ret == 0) {
btrfs_release_path(path);
return 0;
}
if (inode_item) {
struct btrfs_inode_item *item;
u64 nbytes;
item = btrfs_item_ptr(path->nodes[0], path->slots[0],
struct btrfs_inode_item);
nbytes = btrfs_inode_nbytes(path->nodes[0], item);
item = btrfs_item_ptr(eb, slot,
struct btrfs_inode_item);
btrfs_set_inode_nbytes(eb, item, nbytes);
}
} else if (inode_item) {
struct btrfs_inode_item *item;
item = btrfs_item_ptr(eb, slot, struct btrfs_inode_item);
btrfs_set_inode_nbytes(eb, item, 0);
}
insert:
btrfs_release_path(path);
ret = btrfs_insert_empty_item(trans, root, path,
key, item_size);
if (ret == -EEXIST) {
u32 found_size;
found_size = btrfs_item_size_nr(path->nodes[0],
path->slots[0]);
if (found_size > item_size)
btrfs_truncate_item(root, path, item_size, 1);
else if (found_size < item_size)
btrfs_extend_item(root, path,
item_size - found_size);
} else if (ret) {
return ret;
}
dst_ptr = btrfs_item_ptr_offset(path->nodes[0],
path->slots[0]);
if (key->type == BTRFS_INODE_ITEM_KEY && ret == -EEXIST) {
struct btrfs_inode_item *src_item;
struct btrfs_inode_item *dst_item;
src_item = (struct btrfs_inode_item *)src_ptr;
dst_item = (struct btrfs_inode_item *)dst_ptr;
if (btrfs_inode_generation(eb, src_item) == 0)
goto no_copy;
if (overwrite_root &&
S_ISDIR(btrfs_inode_mode(eb, src_item)) &&
S_ISDIR(btrfs_inode_mode(path->nodes[0], dst_item))) {
save_old_i_size = 1;
saved_i_size = btrfs_inode_size(path->nodes[0],
dst_item);
}
}
copy_extent_buffer(path->nodes[0], eb, dst_ptr,
src_ptr, item_size);
if (save_old_i_size) {
struct btrfs_inode_item *dst_item;
dst_item = (struct btrfs_inode_item *)dst_ptr;
btrfs_set_inode_size(path->nodes[0], dst_item, saved_i_size);
}
if (key->type == BTRFS_INODE_ITEM_KEY) {
struct btrfs_inode_item *dst_item;
dst_item = (struct btrfs_inode_item *)dst_ptr;
if (btrfs_inode_generation(path->nodes[0], dst_item) == 0) {
btrfs_set_inode_generation(path->nodes[0], dst_item,
trans->transid);
}
}
no_copy:
btrfs_mark_buffer_dirty(path->nodes[0]);
btrfs_release_path(path);
return 0;
}
noinline int replay_one_extent(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path,
struct extent_buffer *eb, int slot,
struct btrfs_key *key)
{
int found_type;
u64 extent_end;
u64 start = key->offset;
u64 nbytes = 0;
struct btrfs_file_extent_item *item;
struct inode *inode = NULL;
unsigned long size;
int ret = 0;
item = btrfs_item_ptr(eb, slot, struct btrfs_file_extent_item);
found_type = btrfs_file_extent_type(eb, item);
if (found_type == BTRFS_FILE_EXTENT_REG ||
found_type == BTRFS_FILE_EXTENT_PREALLOC) {
nbytes = btrfs_file_extent_num_bytes(eb, item);
extent_end = start + nbytes;
if (btrfs_file_extent_disk_bytenr(eb, item) == 0)
nbytes = 0;
} else if (found_type == BTRFS_FILE_EXTENT_INLINE) {
size = btrfs_file_extent_inline_len(eb, item);
nbytes = btrfs_file_extent_ram_bytes(eb, item);
extent_end = ALIGN(start + size, root->sectorsize);
} else {
ret = 0;
goto out;
}
inode = read_one_inode(root, key->objectid);
if (!inode) {
ret = -EIO;
goto out;
}
ret = btrfs_lookup_file_extent(trans, root, path, btrfs_ino(inode),
start, 0);
if (ret == 0 &&
(found_type == BTRFS_FILE_EXTENT_REG ||
found_type == BTRFS_FILE_EXTENT_PREALLOC)) {
struct btrfs_file_extent_item cmp1;
struct btrfs_file_extent_item cmp2;
struct btrfs_file_extent_item *existing;
struct extent_buffer *leaf;
leaf = path->nodes[0];
existing = btrfs_item_ptr(leaf, path->slots[0],
struct btrfs_file_extent_item);
read_extent_buffer(eb, &cmp1, (unsigned long)item,
sizeof(cmp1));
read_extent_buffer(leaf, &cmp2, (unsigned long)existing,
sizeof(cmp2));
if (memcmp(&cmp1, &cmp2, sizeof(cmp1)) == 0) {
btrfs_release_path(path);
goto out;
}
}
btrfs_release_path(path);
ret = btrfs_drop_extents(trans, root, inode, start, extent_end, 1);
if (ret)
goto out;
if (found_type == BTRFS_FILE_EXTENT_REG ||
found_type == BTRFS_FILE_EXTENT_PREALLOC) {
u64 offset;
unsigned long dest_offset;
struct btrfs_key ins;
ret = btrfs_insert_empty_item(trans, root, path, key,
sizeof(*item));
if (ret)
goto out;
dest_offset = btrfs_item_ptr_offset(path->nodes[0],
path->slots[0]);
copy_extent_buffer(path->nodes[0], eb, dest_offset,
(unsigned long)item, sizeof(*item));
ins.objectid = btrfs_file_extent_disk_bytenr(eb, item);
ins.offset = btrfs_file_extent_disk_num_bytes(eb, item);
ins.type = BTRFS_EXTENT_ITEM_KEY;
offset = key->offset - btrfs_file_extent_offset(eb, item);
if (ins.objectid > 0) {
u64 csum_start;
u64 csum_end;
LIST_HEAD(ordered_sums);
ret = btrfs_lookup_extent(root, ins.objectid,
ins.offset);
if (ret == 0) {
ret = btrfs_inc_extent_ref(trans, root,
ins.objectid, ins.offset,
0, root->root_key.objectid,
key->objectid, offset, 0);
if (ret)
goto out;
} else {
ret = btrfs_alloc_logged_file_extent(trans,
root, root->root_key.objectid,
key->objectid, offset, &ins);
if (ret)
goto out;
}
btrfs_release_path(path);
if (btrfs_file_extent_compression(eb, item)) {
csum_start = ins.objectid;
csum_end = csum_start + ins.offset;
} else {
csum_start = ins.objectid +
btrfs_file_extent_offset(eb, item);
csum_end = csum_start +
btrfs_file_extent_num_bytes(eb, item);
}
ret = btrfs_lookup_csums_range(root->log_root,
csum_start, csum_end - 1,
&ordered_sums, 0);
if (ret)
goto out;
while (!list_empty(&ordered_sums)) {
struct btrfs_ordered_sum *sums;
sums = list_entry(ordered_sums.next,
struct btrfs_ordered_sum,
list);
if (!ret)
ret = btrfs_csum_file_blocks(trans,
root->fs_info->csum_root,
sums);
list_del(&sums->list);
kfree(sums);
}
if (ret)
goto out;
} else {
btrfs_release_path(path);
}
} else if (found_type == BTRFS_FILE_EXTENT_INLINE) {
ret = overwrite_item(trans, root, path, eb, slot, key);
if (ret)
goto out;
}
inode_add_bytes(inode, nbytes);
ret = btrfs_update_inode(trans, root, inode);
out:
if (inode)
iput(inode);
return ret;
}
static noinline int drop_one_dir_item(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path,
struct inode *dir,
struct btrfs_dir_item *di)
{
struct inode *inode;
char *name;
int name_len;
struct extent_buffer *leaf;
struct btrfs_key location;
int ret;
leaf = path->nodes[0];
btrfs_dir_item_key_to_cpu(leaf, di, &location);
name_len = btrfs_dir_name_len(leaf, di);
name = kmalloc(name_len, GFP_NOFS);
if (!name)
return -ENOMEM;
read_extent_buffer(leaf, name, (unsigned long)(di + 1), name_len);
btrfs_release_path(path);
inode = read_one_inode(root, location.objectid);
if (!inode) {
ret = -EIO;
goto out;
}
ret = link_to_fixup_dir(trans, root, path, location.objectid);
if (ret)
goto out;
ret = btrfs_unlink_inode(trans, root, dir, inode, name, name_len);
if (ret)
goto out;
btrfs_run_delayed_items(trans, root);
out:
kfree(name);
iput(inode);
return ret;
}
static noinline int inode_in_dir(struct btrfs_root *root,
struct btrfs_path *path,
u64 dirid, u64 objectid, u64 index,
const char *name, int name_len)
{
struct btrfs_dir_item *di;
struct btrfs_key location;
int match = 0;
di = btrfs_lookup_dir_index_item(NULL, root, path, dirid,
index, name, name_len, 0);
if (di && !IS_ERR(di)) {
btrfs_dir_item_key_to_cpu(path->nodes[0], di, &location);
if (location.objectid != objectid)
goto out;
} else
goto out;
btrfs_release_path(path);
di = btrfs_lookup_dir_item(NULL, root, path, dirid, name, name_len, 0);
if (di && !IS_ERR(di)) {
btrfs_dir_item_key_to_cpu(path->nodes[0], di, &location);
if (location.objectid != objectid)
goto out;
} else
goto out;
match = 1;
out:
btrfs_release_path(path);
return match;
}
static noinline int backref_in_log(struct btrfs_root *log,
struct btrfs_key *key,
u64 ref_objectid,
char *name, int namelen)
{
struct btrfs_path *path;
struct btrfs_inode_ref *ref;
unsigned long ptr;
unsigned long ptr_end;
unsigned long name_ptr;
int found_name_len;
int item_size;
int ret;
int match = 0;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
ret = btrfs_search_slot(NULL, log, key, path, 0, 0);
if (ret != 0)
goto out;
ptr = btrfs_item_ptr_offset(path->nodes[0], path->slots[0]);
if (key->type == BTRFS_INODE_EXTREF_KEY) {
if (btrfs_find_name_in_ext_backref(path, ref_objectid,
name, namelen, NULL))
match = 1;
goto out;
}
item_size = btrfs_item_size_nr(path->nodes[0], path->slots[0]);
ptr_end = ptr + item_size;
while (ptr < ptr_end) {
ref = (struct btrfs_inode_ref *)ptr;
found_name_len = btrfs_inode_ref_name_len(path->nodes[0], ref);
if (found_name_len == namelen) {
name_ptr = (unsigned long)(ref + 1);
ret = memcmp_extent_buffer(path->nodes[0], name,
name_ptr, namelen);
if (ret == 0) {
match = 1;
goto out;
}
}
ptr = (unsigned long)(ref + 1) + found_name_len;
}
out:
btrfs_free_path(path);
return match;
}
static inline int __add_inode_ref(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path,
struct btrfs_root *log_root,
struct inode *dir, struct inode *inode,
struct extent_buffer *eb,
u64 inode_objectid, u64 parent_objectid,
u64 ref_index, char *name, int namelen,
int *search_done)
{
int ret;
char *victim_name;
int victim_name_len;
struct extent_buffer *leaf;
struct btrfs_dir_item *di;
struct btrfs_key search_key;
struct btrfs_inode_extref *extref;
again:
search_key.objectid = inode_objectid;
search_key.type = BTRFS_INODE_REF_KEY;
search_key.offset = parent_objectid;
ret = btrfs_search_slot(NULL, root, &search_key, path, 0, 0);
if (ret == 0) {
struct btrfs_inode_ref *victim_ref;
unsigned long ptr;
unsigned long ptr_end;
leaf = path->nodes[0];
if (search_key.objectid == search_key.offset)
return 1;
ptr = btrfs_item_ptr_offset(leaf, path->slots[0]);
ptr_end = ptr + btrfs_item_size_nr(leaf, path->slots[0]);
while (ptr < ptr_end) {
victim_ref = (struct btrfs_inode_ref *)ptr;
victim_name_len = btrfs_inode_ref_name_len(leaf,
victim_ref);
victim_name = kmalloc(victim_name_len, GFP_NOFS);
if (!victim_name)
return -ENOMEM;
read_extent_buffer(leaf, victim_name,
(unsigned long)(victim_ref + 1),
victim_name_len);
if (!backref_in_log(log_root, &search_key,
parent_objectid,
victim_name,
victim_name_len)) {
btrfs_inc_nlink(inode);
btrfs_release_path(path);
ret = btrfs_unlink_inode(trans, root, dir,
inode, victim_name,
victim_name_len);
kfree(victim_name);
if (ret)
return ret;
btrfs_run_delayed_items(trans, root);
*search_done = 1;
goto again;
}
kfree(victim_name);
ptr = (unsigned long)(victim_ref + 1) + victim_name_len;
}
*search_done = 1;
}
btrfs_release_path(path);
extref = btrfs_lookup_inode_extref(NULL, root, path, name, namelen,
inode_objectid, parent_objectid, 0,
0);
if (!IS_ERR_OR_NULL(extref)) {
u32 item_size;
u32 cur_offset = 0;
unsigned long base;
struct inode *victim_parent;
leaf = path->nodes[0];
item_size = btrfs_item_size_nr(leaf, path->slots[0]);
base = btrfs_item_ptr_offset(leaf, path->slots[0]);
while (cur_offset < item_size) {
extref = (struct btrfs_inode_extref *)base + cur_offset;
victim_name_len = btrfs_inode_extref_name_len(leaf, extref);
if (btrfs_inode_extref_parent(leaf, extref) != parent_objectid)
goto next;
victim_name = kmalloc(victim_name_len, GFP_NOFS);
if (!victim_name)
return -ENOMEM;
read_extent_buffer(leaf, victim_name, (unsigned long)&extref->name,
victim_name_len);
search_key.objectid = inode_objectid;
search_key.type = BTRFS_INODE_EXTREF_KEY;
search_key.offset = btrfs_extref_hash(parent_objectid,
victim_name,
victim_name_len);
ret = 0;
if (!backref_in_log(log_root, &search_key,
parent_objectid, victim_name,
victim_name_len)) {
ret = -ENOENT;
victim_parent = read_one_inode(root,
parent_objectid);
if (victim_parent) {
btrfs_inc_nlink(inode);
btrfs_release_path(path);
ret = btrfs_unlink_inode(trans, root,
victim_parent,
inode,
victim_name,
victim_name_len);
btrfs_run_delayed_items(trans, root);
}
iput(victim_parent);
kfree(victim_name);
if (ret)
return ret;
*search_done = 1;
goto again;
}
kfree(victim_name);
if (ret)
return ret;
next:
cur_offset += victim_name_len + sizeof(*extref);
}
*search_done = 1;
}
btrfs_release_path(path);
di = btrfs_lookup_dir_index_item(trans, root, path, btrfs_ino(dir),
ref_index, name, namelen, 0);
if (di && !IS_ERR(di)) {
ret = drop_one_dir_item(trans, root, path, dir, di);
if (ret)
return ret;
}
btrfs_release_path(path);
di = btrfs_lookup_dir_item(trans, root, path, btrfs_ino(dir),
name, namelen, 0);
if (di && !IS_ERR(di)) {
ret = drop_one_dir_item(trans, root, path, dir, di);
if (ret)
return ret;
}
btrfs_release_path(path);
return 0;
}
static int extref_get_fields(struct extent_buffer *eb, unsigned long ref_ptr,
u32 *namelen, char **name, u64 *index,
u64 *parent_objectid)
{
struct btrfs_inode_extref *extref;
extref = (struct btrfs_inode_extref *)ref_ptr;
*namelen = btrfs_inode_extref_name_len(eb, extref);
*name = kmalloc(*namelen, GFP_NOFS);
if (*name == NULL)
return -ENOMEM;
read_extent_buffer(eb, *name, (unsigned long)&extref->name,
*namelen);
*index = btrfs_inode_extref_index(eb, extref);
if (parent_objectid)
*parent_objectid = btrfs_inode_extref_parent(eb, extref);
return 0;
}
static int ref_get_fields(struct extent_buffer *eb, unsigned long ref_ptr,
u32 *namelen, char **name, u64 *index)
{
struct btrfs_inode_ref *ref;
ref = (struct btrfs_inode_ref *)ref_ptr;
*namelen = btrfs_inode_ref_name_len(eb, ref);
*name = kmalloc(*namelen, GFP_NOFS);
if (*name == NULL)
return -ENOMEM;
read_extent_buffer(eb, *name, (unsigned long)(ref + 1), *namelen);
*index = btrfs_inode_ref_index(eb, ref);
return 0;
}
static noinline int add_inode_ref(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_root *log,
struct btrfs_path *path,
struct extent_buffer *eb, int slot,
struct btrfs_key *key)
{
struct inode *dir;
struct inode *inode;
unsigned long ref_ptr;
unsigned long ref_end;
char *name;
int namelen;
int ret;
int search_done = 0;
int log_ref_ver = 0;
u64 parent_objectid;
u64 inode_objectid;
u64 ref_index = 0;
int ref_struct_size;
ref_ptr = btrfs_item_ptr_offset(eb, slot);
ref_end = ref_ptr + btrfs_item_size_nr(eb, slot);
if (key->type == BTRFS_INODE_EXTREF_KEY) {
struct btrfs_inode_extref *r;
ref_struct_size = sizeof(struct btrfs_inode_extref);
log_ref_ver = 1;
r = (struct btrfs_inode_extref *)ref_ptr;
parent_objectid = btrfs_inode_extref_parent(eb, r);
} else {
ref_struct_size = sizeof(struct btrfs_inode_ref);
parent_objectid = key->offset;
}
inode_objectid = key->objectid;
dir = read_one_inode(root, parent_objectid);
if (!dir)
return -ENOENT;
inode = read_one_inode(root, inode_objectid);
if (!inode) {
iput(dir);
return -EIO;
}
while (ref_ptr < ref_end) {
if (log_ref_ver) {
ret = extref_get_fields(eb, ref_ptr, &namelen, &name,
&ref_index, &parent_objectid);
if (!dir)
dir = read_one_inode(root, parent_objectid);
if (!dir)
return -ENOENT;
} else {
ret = ref_get_fields(eb, ref_ptr, &namelen, &name,
&ref_index);
}
if (ret)
return ret;
if (!inode_in_dir(root, path, btrfs_ino(dir), btrfs_ino(inode),
ref_index, name, namelen)) {
if (!search_done) {
ret = __add_inode_ref(trans, root, path, log,
dir, inode, eb,
inode_objectid,
parent_objectid,
ref_index, name, namelen,
&search_done);
if (ret == 1) {
ret = 0;
goto out;
}
if (ret)
goto out;
}
ret = btrfs_add_link(trans, dir, inode, name, namelen,
0, ref_index);
if (ret)
goto out;
btrfs_update_inode(trans, root, inode);
}
ref_ptr = (unsigned long)(ref_ptr + ref_struct_size) + namelen;
kfree(name);
if (log_ref_ver) {
iput(dir);
dir = NULL;
}
}
ret = overwrite_item(trans, root, path, eb, slot, key);
out:
btrfs_release_path(path);
iput(dir);
iput(inode);
return ret;
}
static int insert_orphan_item(struct btrfs_trans_handle *trans,
struct btrfs_root *root, u64 offset)
{
int ret;
ret = btrfs_find_orphan_item(root, offset);
if (ret > 0)
ret = btrfs_insert_orphan_item(trans, root, offset);
return ret;
}
static int count_inode_extrefs(struct btrfs_root *root,
struct inode *inode, struct btrfs_path *path)
{
int ret = 0;
int name_len;
unsigned int nlink = 0;
u32 item_size;
u32 cur_offset = 0;
u64 inode_objectid = btrfs_ino(inode);
u64 offset = 0;
unsigned long ptr;
struct btrfs_inode_extref *extref;
struct extent_buffer *leaf;
while (1) {
ret = btrfs_find_one_extref(root, inode_objectid, offset, path,
&extref, &offset);
if (ret)
break;
leaf = path->nodes[0];
item_size = btrfs_item_size_nr(leaf, path->slots[0]);
ptr = btrfs_item_ptr_offset(leaf, path->slots[0]);
while (cur_offset < item_size) {
extref = (struct btrfs_inode_extref *) (ptr + cur_offset);
name_len = btrfs_inode_extref_name_len(leaf, extref);
nlink++;
cur_offset += name_len + sizeof(*extref);
}
offset++;
btrfs_release_path(path);
}
btrfs_release_path(path);
if (ret < 0)
return ret;
return nlink;
}
static int count_inode_refs(struct btrfs_root *root,
struct inode *inode, struct btrfs_path *path)
{
int ret;
struct btrfs_key key;
unsigned int nlink = 0;
unsigned long ptr;
unsigned long ptr_end;
int name_len;
u64 ino = btrfs_ino(inode);
key.objectid = ino;
key.type = BTRFS_INODE_REF_KEY;
key.offset = (u64)-1;
while (1) {
ret = btrfs_search_slot(NULL, root, &key, path, 0, 0);
if (ret < 0)
break;
if (ret > 0) {
if (path->slots[0] == 0)
break;
path->slots[0]--;
}
btrfs_item_key_to_cpu(path->nodes[0], &key,
path->slots[0]);
if (key.objectid != ino ||
key.type != BTRFS_INODE_REF_KEY)
break;
ptr = btrfs_item_ptr_offset(path->nodes[0], path->slots[0]);
ptr_end = ptr + btrfs_item_size_nr(path->nodes[0],
path->slots[0]);
while (ptr < ptr_end) {
struct btrfs_inode_ref *ref;
ref = (struct btrfs_inode_ref *)ptr;
name_len = btrfs_inode_ref_name_len(path->nodes[0],
ref);
ptr = (unsigned long)(ref + 1) + name_len;
nlink++;
}
if (key.offset == 0)
break;
key.offset--;
btrfs_release_path(path);
}
btrfs_release_path(path);
return nlink;
}
static noinline int fixup_inode_link_count(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct inode *inode)
{
struct btrfs_path *path;
int ret;
u64 nlink = 0;
u64 ino = btrfs_ino(inode);
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
ret = count_inode_refs(root, inode, path);
if (ret < 0)
goto out;
nlink = ret;
ret = count_inode_extrefs(root, inode, path);
if (ret == -ENOENT)
ret = 0;
if (ret < 0)
goto out;
nlink += ret;
ret = 0;
if (nlink != inode->i_nlink) {
set_nlink(inode, nlink);
btrfs_update_inode(trans, root, inode);
}
BTRFS_I(inode)->index_cnt = (u64)-1;
if (inode->i_nlink == 0) {
if (S_ISDIR(inode->i_mode)) {
ret = replay_dir_deletes(trans, root, NULL, path,
ino, 1);
if (ret)
goto out;
}
ret = insert_orphan_item(trans, root, ino);
}
out:
btrfs_free_path(path);
return ret;
}
static noinline int fixup_inode_link_counts(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path)
{
int ret;
struct btrfs_key key;
struct inode *inode;
key.objectid = BTRFS_TREE_LOG_FIXUP_OBJECTID;
key.type = BTRFS_ORPHAN_ITEM_KEY;
key.offset = (u64)-1;
while (1) {
ret = btrfs_search_slot(trans, root, &key, path, -1, 1);
if (ret < 0)
break;
if (ret == 1) {
if (path->slots[0] == 0)
break;
path->slots[0]--;
}
btrfs_item_key_to_cpu(path->nodes[0], &key, path->slots[0]);
if (key.objectid != BTRFS_TREE_LOG_FIXUP_OBJECTID ||
key.type != BTRFS_ORPHAN_ITEM_KEY)
break;
ret = btrfs_del_item(trans, root, path);
if (ret)
goto out;
btrfs_release_path(path);
inode = read_one_inode(root, key.offset);
if (!inode)
return -EIO;
ret = fixup_inode_link_count(trans, root, inode);
iput(inode);
if (ret)
goto out;
key.offset = (u64)-1;
}
ret = 0;
out:
btrfs_release_path(path);
return ret;
}
static noinline int link_to_fixup_dir(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path,
u64 objectid)
{
struct btrfs_key key;
int ret = 0;
struct inode *inode;
inode = read_one_inode(root, objectid);
if (!inode)
return -EIO;
key.objectid = BTRFS_TREE_LOG_FIXUP_OBJECTID;
btrfs_set_key_type(&key, BTRFS_ORPHAN_ITEM_KEY);
key.offset = objectid;
ret = btrfs_insert_empty_item(trans, root, path, &key, 0);
btrfs_release_path(path);
if (ret == 0) {
if (!inode->i_nlink)
set_nlink(inode, 1);
else
btrfs_inc_nlink(inode);
ret = btrfs_update_inode(trans, root, inode);
} else if (ret == -EEXIST) {
ret = 0;
} else {
BUG();
}
iput(inode);
return ret;
}
static noinline int insert_one_name(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path,
u64 dirid, u64 index,
char *name, int name_len, u8 type,
struct btrfs_key *location)
{
struct inode *inode;
struct inode *dir;
int ret;
inode = read_one_inode(root, location->objectid);
if (!inode)
return -ENOENT;
dir = read_one_inode(root, dirid);
if (!dir) {
iput(inode);
return -EIO;
}
ret = btrfs_add_link(trans, dir, inode, name, name_len, 1, index);
iput(inode);
iput(dir);
return ret;
}
static noinline int replay_one_name(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path,
struct extent_buffer *eb,
struct btrfs_dir_item *di,
struct btrfs_key *key)
{
char *name;
int name_len;
struct btrfs_dir_item *dst_di;
struct btrfs_key found_key;
struct btrfs_key log_key;
struct inode *dir;
u8 log_type;
int exists;
int ret = 0;
dir = read_one_inode(root, key->objectid);
if (!dir)
return -EIO;
name_len = btrfs_dir_name_len(eb, di);
name = kmalloc(name_len, GFP_NOFS);
if (!name)
return -ENOMEM;
log_type = btrfs_dir_type(eb, di);
read_extent_buffer(eb, name, (unsigned long)(di + 1),
name_len);
btrfs_dir_item_key_to_cpu(eb, di, &log_key);
exists = btrfs_lookup_inode(trans, root, path, &log_key, 0);
if (exists == 0)
exists = 1;
else
exists = 0;
btrfs_release_path(path);
if (key->type == BTRFS_DIR_ITEM_KEY) {
dst_di = btrfs_lookup_dir_item(trans, root, path, key->objectid,
name, name_len, 1);
} else if (key->type == BTRFS_DIR_INDEX_KEY) {
dst_di = btrfs_lookup_dir_index_item(trans, root, path,
key->objectid,
key->offset, name,
name_len, 1);
} else {
ret = -EINVAL;
goto out;
}
if (IS_ERR_OR_NULL(dst_di)) {
if (key->type != BTRFS_DIR_INDEX_KEY)
goto out;
goto insert;
}
btrfs_dir_item_key_to_cpu(path->nodes[0], dst_di, &found_key);
if (found_key.objectid == log_key.objectid &&
found_key.type == log_key.type &&
found_key.offset == log_key.offset &&
btrfs_dir_type(path->nodes[0], dst_di) == log_type) {
goto out;
}
if (!exists)
goto out;
ret = drop_one_dir_item(trans, root, path, dir, dst_di);
if (ret)
goto out;
if (key->type == BTRFS_DIR_INDEX_KEY)
goto insert;
out:
btrfs_release_path(path);
kfree(name);
iput(dir);
return ret;
insert:
btrfs_release_path(path);
ret = insert_one_name(trans, root, path, key->objectid, key->offset,
name, name_len, log_type, &log_key);
if (ret && ret != -ENOENT)
goto out;
ret = 0;
goto out;
}
static noinline int replay_one_dir_item(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path,
struct extent_buffer *eb, int slot,
struct btrfs_key *key)
{
int ret;
u32 item_size = btrfs_item_size_nr(eb, slot);
struct btrfs_dir_item *di;
int name_len;
unsigned long ptr;
unsigned long ptr_end;
ptr = btrfs_item_ptr_offset(eb, slot);
ptr_end = ptr + item_size;
while (ptr < ptr_end) {
di = (struct btrfs_dir_item *)ptr;
if (verify_dir_item(root, eb, di))
return -EIO;
name_len = btrfs_dir_name_len(eb, di);
ret = replay_one_name(trans, root, path, eb, di, key);
if (ret)
return ret;
ptr = (unsigned long)(di + 1);
ptr += name_len;
}
return 0;
}
static noinline int find_dir_range(struct btrfs_root *root,
struct btrfs_path *path,
u64 dirid, int key_type,
u64 *start_ret, u64 *end_ret)
{
struct btrfs_key key;
u64 found_end;
struct btrfs_dir_log_item *item;
int ret;
int nritems;
if (*start_ret == (u64)-1)
return 1;
key.objectid = dirid;
key.type = key_type;
key.offset = *start_ret;
ret = btrfs_search_slot(NULL, root, &key, path, 0, 0);
if (ret < 0)
goto out;
if (ret > 0) {
if (path->slots[0] == 0)
goto out;
path->slots[0]--;
}
if (ret != 0)
btrfs_item_key_to_cpu(path->nodes[0], &key, path->slots[0]);
if (key.type != key_type || key.objectid != dirid) {
ret = 1;
goto next;
}
item = btrfs_item_ptr(path->nodes[0], path->slots[0],
struct btrfs_dir_log_item);
found_end = btrfs_dir_log_end(path->nodes[0], item);
if (*start_ret >= key.offset && *start_ret <= found_end) {
ret = 0;
*start_ret = key.offset;
*end_ret = found_end;
goto out;
}
ret = 1;
next:
nritems = btrfs_header_nritems(path->nodes[0]);
if (path->slots[0] >= nritems) {
ret = btrfs_next_leaf(root, path);
if (ret)
goto out;
} else {
path->slots[0]++;
}
btrfs_item_key_to_cpu(path->nodes[0], &key, path->slots[0]);
if (key.type != key_type || key.objectid != dirid) {
ret = 1;
goto out;
}
item = btrfs_item_ptr(path->nodes[0], path->slots[0],
struct btrfs_dir_log_item);
found_end = btrfs_dir_log_end(path->nodes[0], item);
*start_ret = key.offset;
*end_ret = found_end;
ret = 0;
out:
btrfs_release_path(path);
return ret;
}
static noinline int check_item_in_log(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_root *log,
struct btrfs_path *path,
struct btrfs_path *log_path,
struct inode *dir,
struct btrfs_key *dir_key)
{
int ret;
struct extent_buffer *eb;
int slot;
u32 item_size;
struct btrfs_dir_item *di;
struct btrfs_dir_item *log_di;
int name_len;
unsigned long ptr;
unsigned long ptr_end;
char *name;
struct inode *inode;
struct btrfs_key location;
again:
eb = path->nodes[0];
slot = path->slots[0];
item_size = btrfs_item_size_nr(eb, slot);
ptr = btrfs_item_ptr_offset(eb, slot);
ptr_end = ptr + item_size;
while (ptr < ptr_end) {
di = (struct btrfs_dir_item *)ptr;
if (verify_dir_item(root, eb, di)) {
ret = -EIO;
goto out;
}
name_len = btrfs_dir_name_len(eb, di);
name = kmalloc(name_len, GFP_NOFS);
if (!name) {
ret = -ENOMEM;
goto out;
}
read_extent_buffer(eb, name, (unsigned long)(di + 1),
name_len);
log_di = NULL;
if (log && dir_key->type == BTRFS_DIR_ITEM_KEY) {
log_di = btrfs_lookup_dir_item(trans, log, log_path,
dir_key->objectid,
name, name_len, 0);
} else if (log && dir_key->type == BTRFS_DIR_INDEX_KEY) {
log_di = btrfs_lookup_dir_index_item(trans, log,
log_path,
dir_key->objectid,
dir_key->offset,
name, name_len, 0);
}
if (IS_ERR_OR_NULL(log_di)) {
btrfs_dir_item_key_to_cpu(eb, di, &location);
btrfs_release_path(path);
btrfs_release_path(log_path);
inode = read_one_inode(root, location.objectid);
if (!inode) {
kfree(name);
return -EIO;
}
ret = link_to_fixup_dir(trans, root,
path, location.objectid);
if (ret) {
kfree(name);
iput(inode);
goto out;
}
btrfs_inc_nlink(inode);
ret = btrfs_unlink_inode(trans, root, dir, inode,
name, name_len);
if (!ret)
btrfs_run_delayed_items(trans, root);
kfree(name);
iput(inode);
if (ret)
goto out;
ret = btrfs_search_slot(NULL, root, dir_key, path,
0, 0);
if (ret == 0)
goto again;
ret = 0;
goto out;
}
btrfs_release_path(log_path);
kfree(name);
ptr = (unsigned long)(di + 1);
ptr += name_len;
}
ret = 0;
out:
btrfs_release_path(path);
btrfs_release_path(log_path);
return ret;
}
static noinline int replay_dir_deletes(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_root *log,
struct btrfs_path *path,
u64 dirid, int del_all)
{
u64 range_start;
u64 range_end;
int key_type = BTRFS_DIR_LOG_ITEM_KEY;
int ret = 0;
struct btrfs_key dir_key;
struct btrfs_key found_key;
struct btrfs_path *log_path;
struct inode *dir;
dir_key.objectid = dirid;
dir_key.type = BTRFS_DIR_ITEM_KEY;
log_path = btrfs_alloc_path();
if (!log_path)
return -ENOMEM;
dir = read_one_inode(root, dirid);
if (!dir) {
btrfs_free_path(log_path);
return 0;
}
again:
range_start = 0;
range_end = 0;
while (1) {
if (del_all)
range_end = (u64)-1;
else {
ret = find_dir_range(log, path, dirid, key_type,
&range_start, &range_end);
if (ret != 0)
break;
}
dir_key.offset = range_start;
while (1) {
int nritems;
ret = btrfs_search_slot(NULL, root, &dir_key, path,
0, 0);
if (ret < 0)
goto out;
nritems = btrfs_header_nritems(path->nodes[0]);
if (path->slots[0] >= nritems) {
ret = btrfs_next_leaf(root, path);
if (ret)
break;
}
btrfs_item_key_to_cpu(path->nodes[0], &found_key,
path->slots[0]);
if (found_key.objectid != dirid ||
found_key.type != dir_key.type)
goto next_type;
if (found_key.offset > range_end)
break;
ret = check_item_in_log(trans, root, log, path,
log_path, dir,
&found_key);
if (ret)
goto out;
if (found_key.offset == (u64)-1)
break;
dir_key.offset = found_key.offset + 1;
}
btrfs_release_path(path);
if (range_end == (u64)-1)
break;
range_start = range_end + 1;
}
next_type:
ret = 0;
if (key_type == BTRFS_DIR_LOG_ITEM_KEY) {
key_type = BTRFS_DIR_LOG_INDEX_KEY;
dir_key.type = BTRFS_DIR_INDEX_KEY;
btrfs_release_path(path);
goto again;
}
out:
btrfs_release_path(path);
btrfs_free_path(log_path);
iput(dir);
return ret;
}
static int replay_one_buffer(struct btrfs_root *log, struct extent_buffer *eb,
struct walk_control *wc, u64 gen)
{
int nritems;
struct btrfs_path *path;
struct btrfs_root *root = wc->replay_dest;
struct btrfs_key key;
int level;
int i;
int ret;
ret = btrfs_read_buffer(eb, gen);
if (ret)
return ret;
level = btrfs_header_level(eb);
if (level != 0)
return 0;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
nritems = btrfs_header_nritems(eb);
for (i = 0; i < nritems; i++) {
btrfs_item_key_to_cpu(eb, &key, i);
if (key.type == BTRFS_INODE_ITEM_KEY &&
wc->stage == LOG_WALK_REPLAY_INODES) {
struct btrfs_inode_item *inode_item;
u32 mode;
inode_item = btrfs_item_ptr(eb, i,
struct btrfs_inode_item);
mode = btrfs_inode_mode(eb, inode_item);
if (S_ISDIR(mode)) {
ret = replay_dir_deletes(wc->trans,
root, log, path, key.objectid, 0);
if (ret)
break;
}
ret = overwrite_item(wc->trans, root, path,
eb, i, &key);
if (ret)
break;
if (S_ISREG(mode)) {
ret = insert_orphan_item(wc->trans, root,
key.objectid);
if (ret)
break;
}
ret = link_to_fixup_dir(wc->trans, root,
path, key.objectid);
if (ret)
break;
}
if (wc->stage < LOG_WALK_REPLAY_ALL)
continue;
if (key.type == BTRFS_XATTR_ITEM_KEY) {
ret = overwrite_item(wc->trans, root, path,
eb, i, &key);
if (ret)
break;
} else if (key.type == BTRFS_INODE_REF_KEY ||
key.type == BTRFS_INODE_EXTREF_KEY) {
ret = add_inode_ref(wc->trans, root, log, path,
eb, i, &key);
if (ret && ret != -ENOENT)
break;
ret = 0;
} else if (key.type == BTRFS_EXTENT_DATA_KEY) {
ret = replay_one_extent(wc->trans, root, path,
eb, i, &key);
if (ret)
break;
} else if (key.type == BTRFS_DIR_ITEM_KEY ||
key.type == BTRFS_DIR_INDEX_KEY) {
ret = replay_one_dir_item(wc->trans, root, path,
eb, i, &key);
if (ret)
break;
}
}
btrfs_free_path(path);
return ret;
}
static noinline int walk_down_log_tree(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path, int *level,
struct walk_control *wc)
{
u64 root_owner;
u64 bytenr;
u64 ptr_gen;
struct extent_buffer *next;
struct extent_buffer *cur;
struct extent_buffer *parent;
u32 blocksize;
int ret = 0;
WARN_ON(*level < 0);
WARN_ON(*level >= BTRFS_MAX_LEVEL);
while (*level > 0) {
WARN_ON(*level < 0);
WARN_ON(*level >= BTRFS_MAX_LEVEL);
cur = path->nodes[*level];
if (btrfs_header_level(cur) != *level)
WARN_ON(1);
if (path->slots[*level] >=
btrfs_header_nritems(cur))
break;
bytenr = btrfs_node_blockptr(cur, path->slots[*level]);
ptr_gen = btrfs_node_ptr_generation(cur, path->slots[*level]);
blocksize = btrfs_level_size(root, *level - 1);
parent = path->nodes[*level];
root_owner = btrfs_header_owner(parent);
next = btrfs_find_create_tree_block(root, bytenr, blocksize);
if (!next)
return -ENOMEM;
if (*level == 1) {
ret = wc->process_func(root, next, wc, ptr_gen);
if (ret) {
free_extent_buffer(next);
return ret;
}
path->slots[*level]++;
if (wc->free) {
ret = btrfs_read_buffer(next, ptr_gen);
if (ret) {
free_extent_buffer(next);
return ret;
}
btrfs_tree_lock(next);
btrfs_set_lock_blocking(next);
clean_tree_block(trans, root, next);
btrfs_wait_tree_block_writeback(next);
btrfs_tree_unlock(next);
WARN_ON(root_owner !=
BTRFS_TREE_LOG_OBJECTID);
ret = btrfs_free_and_pin_reserved_extent(root,
bytenr, blocksize);
if (ret) {
free_extent_buffer(next);
return ret;
}
}
free_extent_buffer(next);
continue;
}
ret = btrfs_read_buffer(next, ptr_gen);
if (ret) {
free_extent_buffer(next);
return ret;
}
WARN_ON(*level <= 0);
if (path->nodes[*level-1])
free_extent_buffer(path->nodes[*level-1]);
path->nodes[*level-1] = next;
*level = btrfs_header_level(next);
path->slots[*level] = 0;
cond_resched();
}
WARN_ON(*level < 0);
WARN_ON(*level >= BTRFS_MAX_LEVEL);
path->slots[*level] = btrfs_header_nritems(path->nodes[*level]);
cond_resched();
return 0;
}
static noinline int walk_up_log_tree(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path, int *level,
struct walk_control *wc)
{
u64 root_owner;
int i;
int slot;
int ret;
for (i = *level; i < BTRFS_MAX_LEVEL - 1 && path->nodes[i]; i++) {
slot = path->slots[i];
if (slot + 1 < btrfs_header_nritems(path->nodes[i])) {
path->slots[i]++;
*level = i;
WARN_ON(*level == 0);
return 0;
} else {
struct extent_buffer *parent;
if (path->nodes[*level] == root->node)
parent = path->nodes[*level];
else
parent = path->nodes[*level + 1];
root_owner = btrfs_header_owner(parent);
ret = wc->process_func(root, path->nodes[*level], wc,
btrfs_header_generation(path->nodes[*level]));
if (ret)
return ret;
if (wc->free) {
struct extent_buffer *next;
next = path->nodes[*level];
btrfs_tree_lock(next);
btrfs_set_lock_blocking(next);
clean_tree_block(trans, root, next);
btrfs_wait_tree_block_writeback(next);
btrfs_tree_unlock(next);
WARN_ON(root_owner != BTRFS_TREE_LOG_OBJECTID);
ret = btrfs_free_and_pin_reserved_extent(root,
path->nodes[*level]->start,
path->nodes[*level]->len);
if (ret)
return ret;
}
free_extent_buffer(path->nodes[*level]);
path->nodes[*level] = NULL;
*level = i + 1;
}
}
return 1;
}
static int walk_log_tree(struct btrfs_trans_handle *trans,
struct btrfs_root *log, struct walk_control *wc)
{
int ret = 0;
int wret;
int level;
struct btrfs_path *path;
int orig_level;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
level = btrfs_header_level(log->node);
orig_level = level;
path->nodes[level] = log->node;
extent_buffer_get(log->node);
path->slots[level] = 0;
while (1) {
wret = walk_down_log_tree(trans, log, path, &level, wc);
if (wret > 0)
break;
if (wret < 0) {
ret = wret;
goto out;
}
wret = walk_up_log_tree(trans, log, path, &level, wc);
if (wret > 0)
break;
if (wret < 0) {
ret = wret;
goto out;
}
}
if (path->nodes[orig_level]) {
ret = wc->process_func(log, path->nodes[orig_level], wc,
btrfs_header_generation(path->nodes[orig_level]));
if (ret)
goto out;
if (wc->free) {
struct extent_buffer *next;
next = path->nodes[orig_level];
btrfs_tree_lock(next);
btrfs_set_lock_blocking(next);
clean_tree_block(trans, log, next);
btrfs_wait_tree_block_writeback(next);
btrfs_tree_unlock(next);
WARN_ON(log->root_key.objectid !=
BTRFS_TREE_LOG_OBJECTID);
ret = btrfs_free_and_pin_reserved_extent(log, next->start,
next->len);
if (ret)
goto out;
}
}
out:
btrfs_free_path(path);
return ret;
}
static int update_log_root(struct btrfs_trans_handle *trans,
struct btrfs_root *log)
{
int ret;
if (log->log_transid == 1) {
ret = btrfs_insert_root(trans, log->fs_info->log_root_tree,
&log->root_key, &log->root_item);
} else {
ret = btrfs_update_root(trans, log->fs_info->log_root_tree,
&log->root_key, &log->root_item);
}
return ret;
}
static int wait_log_commit(struct btrfs_trans_handle *trans,
struct btrfs_root *root, unsigned long transid)
{
DEFINE_WAIT(wait);
int index = transid % 2;
do {
prepare_to_wait(&root->log_commit_wait[index],
&wait, TASK_UNINTERRUPTIBLE);
mutex_unlock(&root->log_mutex);
if (root->fs_info->last_trans_log_full_commit !=
trans->transid && root->log_transid < transid + 2 &&
atomic_read(&root->log_commit[index]))
schedule();
finish_wait(&root->log_commit_wait[index], &wait);
mutex_lock(&root->log_mutex);
} while (root->fs_info->last_trans_log_full_commit !=
trans->transid && root->log_transid < transid + 2 &&
atomic_read(&root->log_commit[index]));
return 0;
}
static void wait_for_writer(struct btrfs_trans_handle *trans,
struct btrfs_root *root)
{
DEFINE_WAIT(wait);
while (root->fs_info->last_trans_log_full_commit !=
trans->transid && atomic_read(&root->log_writers)) {
prepare_to_wait(&root->log_writer_wait,
&wait, TASK_UNINTERRUPTIBLE);
mutex_unlock(&root->log_mutex);
if (root->fs_info->last_trans_log_full_commit !=
trans->transid && atomic_read(&root->log_writers))
schedule();
mutex_lock(&root->log_mutex);
finish_wait(&root->log_writer_wait, &wait);
}
}
int btrfs_sync_log(struct btrfs_trans_handle *trans,
struct btrfs_root *root)
{
int index1;
int index2;
int mark;
int ret;
struct btrfs_root *log = root->log_root;
struct btrfs_root *log_root_tree = root->fs_info->log_root_tree;
unsigned long log_transid = 0;
struct blk_plug plug;
mutex_lock(&root->log_mutex);
log_transid = root->log_transid;
index1 = root->log_transid % 2;
if (atomic_read(&root->log_commit[index1])) {
wait_log_commit(trans, root, root->log_transid);
mutex_unlock(&root->log_mutex);
return 0;
}
atomic_set(&root->log_commit[index1], 1);
if (atomic_read(&root->log_commit[(index1 + 1) % 2]))
wait_log_commit(trans, root, root->log_transid - 1);
while (1) {
int batch = atomic_read(&root->log_batch);
if (!btrfs_test_opt(root, SSD) && root->log_multiple_pids) {
mutex_unlock(&root->log_mutex);
schedule_timeout_uninterruptible(1);
mutex_lock(&root->log_mutex);
}
wait_for_writer(trans, root);
if (batch == atomic_read(&root->log_batch))
break;
}
if (root->fs_info->last_trans_log_full_commit == trans->transid) {
ret = -EAGAIN;
btrfs_free_logged_extents(log, log_transid);
mutex_unlock(&root->log_mutex);
goto out;
}
if (log_transid % 2 == 0)
mark = EXTENT_DIRTY;
else
mark = EXTENT_NEW;
blk_start_plug(&plug);
ret = btrfs_write_marked_extents(log, &log->dirty_log_pages, mark);
if (ret) {
blk_finish_plug(&plug);
btrfs_abort_transaction(trans, root, ret);
btrfs_free_logged_extents(log, log_transid);
mutex_unlock(&root->log_mutex);
goto out;
}
btrfs_set_root_node(&log->root_item, log->node);
root->log_transid++;
log->log_transid = root->log_transid;
root->log_start_pid = 0;
smp_mb();
mutex_unlock(&root->log_mutex);
mutex_lock(&log_root_tree->log_mutex);
atomic_inc(&log_root_tree->log_batch);
atomic_inc(&log_root_tree->log_writers);
mutex_unlock(&log_root_tree->log_mutex);
ret = update_log_root(trans, log);
mutex_lock(&log_root_tree->log_mutex);
if (atomic_dec_and_test(&log_root_tree->log_writers)) {
smp_mb();
if (waitqueue_active(&log_root_tree->log_writer_wait))
wake_up(&log_root_tree->log_writer_wait);
}
if (ret) {
blk_finish_plug(&plug);
if (ret != -ENOSPC) {
btrfs_abort_transaction(trans, root, ret);
mutex_unlock(&log_root_tree->log_mutex);
goto out;
}
root->fs_info->last_trans_log_full_commit = trans->transid;
btrfs_wait_marked_extents(log, &log->dirty_log_pages, mark);
btrfs_free_logged_extents(log, log_transid);
mutex_unlock(&log_root_tree->log_mutex);
ret = -EAGAIN;
goto out;
}
index2 = log_root_tree->log_transid % 2;
if (atomic_read(&log_root_tree->log_commit[index2])) {
blk_finish_plug(&plug);
btrfs_wait_marked_extents(log, &log->dirty_log_pages, mark);
wait_log_commit(trans, log_root_tree,
log_root_tree->log_transid);
btrfs_free_logged_extents(log, log_transid);
mutex_unlock(&log_root_tree->log_mutex);
ret = 0;
goto out;
}
atomic_set(&log_root_tree->log_commit[index2], 1);
if (atomic_read(&log_root_tree->log_commit[(index2 + 1) % 2])) {
wait_log_commit(trans, log_root_tree,
log_root_tree->log_transid - 1);
}
wait_for_writer(trans, log_root_tree);
if (root->fs_info->last_trans_log_full_commit == trans->transid) {
blk_finish_plug(&plug);
btrfs_wait_marked_extents(log, &log->dirty_log_pages, mark);
btrfs_free_logged_extents(log, log_transid);
mutex_unlock(&log_root_tree->log_mutex);
ret = -EAGAIN;
goto out_wake_log_root;
}
ret = btrfs_write_marked_extents(log_root_tree,
&log_root_tree->dirty_log_pages,
EXTENT_DIRTY | EXTENT_NEW);
blk_finish_plug(&plug);
if (ret) {
btrfs_abort_transaction(trans, root, ret);
btrfs_free_logged_extents(log, log_transid);
mutex_unlock(&log_root_tree->log_mutex);
goto out_wake_log_root;
}
btrfs_wait_marked_extents(log, &log->dirty_log_pages, mark);
btrfs_wait_marked_extents(log_root_tree,
&log_root_tree->dirty_log_pages,
EXTENT_NEW | EXTENT_DIRTY);
btrfs_wait_logged_extents(log, log_transid);
btrfs_set_super_log_root(root->fs_info->super_for_commit,
log_root_tree->node->start);
btrfs_set_super_log_root_level(root->fs_info->super_for_commit,
btrfs_header_level(log_root_tree->node));
log_root_tree->log_transid++;
smp_mb();
mutex_unlock(&log_root_tree->log_mutex);
btrfs_scrub_pause_super(root);
ret = write_ctree_super(trans, root->fs_info->tree_root, 1);
btrfs_scrub_continue_super(root);
if (ret) {
btrfs_abort_transaction(trans, root, ret);
goto out_wake_log_root;
}
mutex_lock(&root->log_mutex);
if (root->last_log_commit < log_transid)
root->last_log_commit = log_transid;
mutex_unlock(&root->log_mutex);
out_wake_log_root:
atomic_set(&log_root_tree->log_commit[index2], 0);
smp_mb();
if (waitqueue_active(&log_root_tree->log_commit_wait[index2]))
wake_up(&log_root_tree->log_commit_wait[index2]);
out:
atomic_set(&root->log_commit[index1], 0);
smp_mb();
if (waitqueue_active(&root->log_commit_wait[index1]))
wake_up(&root->log_commit_wait[index1]);
return ret;
}
static void free_log_tree(struct btrfs_trans_handle *trans,
struct btrfs_root *log)
{
int ret;
u64 start;
u64 end;
struct walk_control wc = {
.free = 1,
.process_func = process_one_buffer
};
if (trans) {
ret = walk_log_tree(trans, log, &wc);
if (ret)
btrfs_abort_transaction(trans, log, ret);
}
while (1) {
ret = find_first_extent_bit(&log->dirty_log_pages,
0, &start, &end, EXTENT_DIRTY | EXTENT_NEW,
NULL);
if (ret)
break;
clear_extent_bits(&log->dirty_log_pages, start, end,
EXTENT_DIRTY | EXTENT_NEW, GFP_NOFS);
}
btrfs_free_logged_extents(log, 0);
btrfs_free_logged_extents(log, 1);
free_extent_buffer(log->node);
kfree(log);
}
int btrfs_free_log(struct btrfs_trans_handle *trans, struct btrfs_root *root)
{
if (root->log_root) {
free_log_tree(trans, root->log_root);
root->log_root = NULL;
}
return 0;
}
int btrfs_free_log_root_tree(struct btrfs_trans_handle *trans,
struct btrfs_fs_info *fs_info)
{
if (fs_info->log_root_tree) {
free_log_tree(trans, fs_info->log_root_tree);
fs_info->log_root_tree = NULL;
}
return 0;
}
int btrfs_del_dir_entries_in_log(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
const char *name, int name_len,
struct inode *dir, u64 index)
{
struct btrfs_root *log;
struct btrfs_dir_item *di;
struct btrfs_path *path;
int ret;
int err = 0;
int bytes_del = 0;
u64 dir_ino = btrfs_ino(dir);
if (BTRFS_I(dir)->logged_trans < trans->transid)
return 0;
ret = join_running_log_trans(root);
if (ret)
return 0;
mutex_lock(&BTRFS_I(dir)->log_mutex);
log = root->log_root;
path = btrfs_alloc_path();
if (!path) {
err = -ENOMEM;
goto out_unlock;
}
di = btrfs_lookup_dir_item(trans, log, path, dir_ino,
name, name_len, -1);
if (IS_ERR(di)) {
err = PTR_ERR(di);
goto fail;
}
if (di) {
ret = btrfs_delete_one_dir_name(trans, log, path, di);
bytes_del += name_len;
if (ret) {
err = ret;
goto fail;
}
}
btrfs_release_path(path);
di = btrfs_lookup_dir_index_item(trans, log, path, dir_ino,
index, name, name_len, -1);
if (IS_ERR(di)) {
err = PTR_ERR(di);
goto fail;
}
if (di) {
ret = btrfs_delete_one_dir_name(trans, log, path, di);
bytes_del += name_len;
if (ret) {
err = ret;
goto fail;
}
}
if (bytes_del) {
struct btrfs_key key;
key.objectid = dir_ino;
key.offset = 0;
key.type = BTRFS_INODE_ITEM_KEY;
btrfs_release_path(path);
ret = btrfs_search_slot(trans, log, &key, path, 0, 1);
if (ret < 0) {
err = ret;
goto fail;
}
if (ret == 0) {
struct btrfs_inode_item *item;
u64 i_size;
item = btrfs_item_ptr(path->nodes[0], path->slots[0],
struct btrfs_inode_item);
i_size = btrfs_inode_size(path->nodes[0], item);
if (i_size > bytes_del)
i_size -= bytes_del;
else
i_size = 0;
btrfs_set_inode_size(path->nodes[0], item, i_size);
btrfs_mark_buffer_dirty(path->nodes[0]);
} else
ret = 0;
btrfs_release_path(path);
}
fail:
btrfs_free_path(path);
out_unlock:
mutex_unlock(&BTRFS_I(dir)->log_mutex);
if (ret == -ENOSPC) {
root->fs_info->last_trans_log_full_commit = trans->transid;
ret = 0;
} else if (ret < 0)
btrfs_abort_transaction(trans, root, ret);
btrfs_end_log_trans(root);
return err;
}
int btrfs_del_inode_ref_in_log(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
const char *name, int name_len,
struct inode *inode, u64 dirid)
{
struct btrfs_root *log;
u64 index;
int ret;
if (BTRFS_I(inode)->logged_trans < trans->transid)
return 0;
ret = join_running_log_trans(root);
if (ret)
return 0;
log = root->log_root;
mutex_lock(&BTRFS_I(inode)->log_mutex);
ret = btrfs_del_inode_ref(trans, log, name, name_len, btrfs_ino(inode),
dirid, &index);
mutex_unlock(&BTRFS_I(inode)->log_mutex);
if (ret == -ENOSPC) {
root->fs_info->last_trans_log_full_commit = trans->transid;
ret = 0;
} else if (ret < 0 && ret != -ENOENT)
btrfs_abort_transaction(trans, root, ret);
btrfs_end_log_trans(root);
return ret;
}
static noinline int insert_dir_log_key(struct btrfs_trans_handle *trans,
struct btrfs_root *log,
struct btrfs_path *path,
int key_type, u64 dirid,
u64 first_offset, u64 last_offset)
{
int ret;
struct btrfs_key key;
struct btrfs_dir_log_item *item;
key.objectid = dirid;
key.offset = first_offset;
if (key_type == BTRFS_DIR_ITEM_KEY)
key.type = BTRFS_DIR_LOG_ITEM_KEY;
else
key.type = BTRFS_DIR_LOG_INDEX_KEY;
ret = btrfs_insert_empty_item(trans, log, path, &key, sizeof(*item));
if (ret)
return ret;
item = btrfs_item_ptr(path->nodes[0], path->slots[0],
struct btrfs_dir_log_item);
btrfs_set_dir_log_end(path->nodes[0], item, last_offset);
btrfs_mark_buffer_dirty(path->nodes[0]);
btrfs_release_path(path);
return 0;
}
static noinline int log_dir_items(struct btrfs_trans_handle *trans,
struct btrfs_root *root, struct inode *inode,
struct btrfs_path *path,
struct btrfs_path *dst_path, int key_type,
u64 min_offset, u64 *last_offset_ret)
{
struct btrfs_key min_key;
struct btrfs_key max_key;
struct btrfs_root *log = root->log_root;
struct extent_buffer *src;
int err = 0;
int ret;
int i;
int nritems;
u64 first_offset = min_offset;
u64 last_offset = (u64)-1;
u64 ino = btrfs_ino(inode);
log = root->log_root;
max_key.objectid = ino;
max_key.offset = (u64)-1;
max_key.type = key_type;
min_key.objectid = ino;
min_key.type = key_type;
min_key.offset = min_offset;
path->keep_locks = 1;
ret = btrfs_search_forward(root, &min_key, &max_key,
path, trans->transid);
if (ret != 0 || min_key.objectid != ino || min_key.type != key_type) {
min_key.objectid = ino;
min_key.type = key_type;
min_key.offset = (u64)-1;
btrfs_release_path(path);
ret = btrfs_search_slot(NULL, root, &min_key, path, 0, 0);
if (ret < 0) {
btrfs_release_path(path);
return ret;
}
ret = btrfs_previous_item(root, path, ino, key_type);
if (ret == 0) {
struct btrfs_key tmp;
btrfs_item_key_to_cpu(path->nodes[0], &tmp,
path->slots[0]);
if (key_type == tmp.type)
first_offset = max(min_offset, tmp.offset) + 1;
}
goto done;
}
ret = btrfs_previous_item(root, path, ino, key_type);
if (ret == 0) {
struct btrfs_key tmp;
btrfs_item_key_to_cpu(path->nodes[0], &tmp, path->slots[0]);
if (key_type == tmp.type) {
first_offset = tmp.offset;
ret = overwrite_item(trans, log, dst_path,
path->nodes[0], path->slots[0],
&tmp);
if (ret) {
err = ret;
goto done;
}
}
}
btrfs_release_path(path);
ret = btrfs_search_slot(NULL, root, &min_key, path, 0, 0);
if (ret != 0) {
WARN_ON(1);
goto done;
}
while (1) {
struct btrfs_key tmp;
src = path->nodes[0];
nritems = btrfs_header_nritems(src);
for (i = path->slots[0]; i < nritems; i++) {
btrfs_item_key_to_cpu(src, &min_key, i);
if (min_key.objectid != ino || min_key.type != key_type)
goto done;
ret = overwrite_item(trans, log, dst_path, src, i,
&min_key);
if (ret) {
err = ret;
goto done;
}
}
path->slots[0] = nritems;
ret = btrfs_next_leaf(root, path);
if (ret == 1) {
last_offset = (u64)-1;
goto done;
}
btrfs_item_key_to_cpu(path->nodes[0], &tmp, path->slots[0]);
if (tmp.objectid != ino || tmp.type != key_type) {
last_offset = (u64)-1;
goto done;
}
if (btrfs_header_generation(path->nodes[0]) != trans->transid) {
ret = overwrite_item(trans, log, dst_path,
path->nodes[0], path->slots[0],
&tmp);
if (ret)
err = ret;
else
last_offset = tmp.offset;
goto done;
}
}
done:
btrfs_release_path(path);
btrfs_release_path(dst_path);
if (err == 0) {
*last_offset_ret = last_offset;
ret = insert_dir_log_key(trans, log, path, key_type,
ino, first_offset, last_offset);
if (ret)
err = ret;
}
return err;
}
static noinline int log_directory_changes(struct btrfs_trans_handle *trans,
struct btrfs_root *root, struct inode *inode,
struct btrfs_path *path,
struct btrfs_path *dst_path)
{
u64 min_key;
u64 max_key;
int ret;
int key_type = BTRFS_DIR_ITEM_KEY;
again:
min_key = 0;
max_key = 0;
while (1) {
ret = log_dir_items(trans, root, inode, path,
dst_path, key_type, min_key,
&max_key);
if (ret)
return ret;
if (max_key == (u64)-1)
break;
min_key = max_key + 1;
}
if (key_type == BTRFS_DIR_ITEM_KEY) {
key_type = BTRFS_DIR_INDEX_KEY;
goto again;
}
return 0;
}
static int drop_objectid_items(struct btrfs_trans_handle *trans,
struct btrfs_root *log,
struct btrfs_path *path,
u64 objectid, int max_key_type)
{
int ret;
struct btrfs_key key;
struct btrfs_key found_key;
int start_slot;
key.objectid = objectid;
key.type = max_key_type;
key.offset = (u64)-1;
while (1) {
ret = btrfs_search_slot(trans, log, &key, path, -1, 1);
BUG_ON(ret == 0);
if (ret < 0)
break;
if (path->slots[0] == 0)
break;
path->slots[0]--;
btrfs_item_key_to_cpu(path->nodes[0], &found_key,
path->slots[0]);
if (found_key.objectid != objectid)
break;
found_key.offset = 0;
found_key.type = 0;
ret = btrfs_bin_search(path->nodes[0], &found_key, 0,
&start_slot);
ret = btrfs_del_items(trans, log, path, start_slot,
path->slots[0] - start_slot + 1);
if (ret || start_slot != 0)
break;
btrfs_release_path(path);
}
btrfs_release_path(path);
if (ret > 0)
ret = 0;
return ret;
}
static void fill_inode_item(struct btrfs_trans_handle *trans,
struct extent_buffer *leaf,
struct btrfs_inode_item *item,
struct inode *inode, int log_inode_only)
{
struct btrfs_map_token token;
btrfs_init_map_token(&token);
if (log_inode_only) {
btrfs_set_token_inode_generation(leaf, item, 0, &token);
btrfs_set_token_inode_size(leaf, item, 0, &token);
} else {
btrfs_set_token_inode_generation(leaf, item,
BTRFS_I(inode)->generation,
&token);
btrfs_set_token_inode_size(leaf, item, inode->i_size, &token);
}
btrfs_set_token_inode_uid(leaf, item, i_uid_read(inode), &token);
btrfs_set_token_inode_gid(leaf, item, i_gid_read(inode), &token);
btrfs_set_token_inode_mode(leaf, item, inode->i_mode, &token);
btrfs_set_token_inode_nlink(leaf, item, inode->i_nlink, &token);
btrfs_set_token_timespec_sec(leaf, btrfs_inode_atime(item),
inode->i_atime.tv_sec, &token);
btrfs_set_token_timespec_nsec(leaf, btrfs_inode_atime(item),
inode->i_atime.tv_nsec, &token);
btrfs_set_token_timespec_sec(leaf, btrfs_inode_mtime(item),
inode->i_mtime.tv_sec, &token);
btrfs_set_token_timespec_nsec(leaf, btrfs_inode_mtime(item),
inode->i_mtime.tv_nsec, &token);
btrfs_set_token_timespec_sec(leaf, btrfs_inode_ctime(item),
inode->i_ctime.tv_sec, &token);
btrfs_set_token_timespec_nsec(leaf, btrfs_inode_ctime(item),
inode->i_ctime.tv_nsec, &token);
btrfs_set_token_inode_nbytes(leaf, item, inode_get_bytes(inode),
&token);
btrfs_set_token_inode_sequence(leaf, item, inode->i_version, &token);
btrfs_set_token_inode_transid(leaf, item, trans->transid, &token);
btrfs_set_token_inode_rdev(leaf, item, inode->i_rdev, &token);
btrfs_set_token_inode_flags(leaf, item, BTRFS_I(inode)->flags, &token);
btrfs_set_token_inode_block_group(leaf, item, 0, &token);
}
static int log_inode_item(struct btrfs_trans_handle *trans,
struct btrfs_root *log, struct btrfs_path *path,
struct inode *inode)
{
struct btrfs_inode_item *inode_item;
struct btrfs_key key;
int ret;
memcpy(&key, &BTRFS_I(inode)->location, sizeof(key));
ret = btrfs_insert_empty_item(trans, log, path, &key,
sizeof(*inode_item));
if (ret && ret != -EEXIST)
return ret;
inode_item = btrfs_item_ptr(path->nodes[0], path->slots[0],
struct btrfs_inode_item);
fill_inode_item(trans, path->nodes[0], inode_item, inode, 0);
btrfs_release_path(path);
return 0;
}
static noinline int copy_items(struct btrfs_trans_handle *trans,
struct inode *inode,
struct btrfs_path *dst_path,
struct extent_buffer *src,
int start_slot, int nr, int inode_only)
{
unsigned long src_offset;
unsigned long dst_offset;
struct btrfs_root *log = BTRFS_I(inode)->root->log_root;
struct btrfs_file_extent_item *extent;
struct btrfs_inode_item *inode_item;
int ret;
struct btrfs_key *ins_keys;
u32 *ins_sizes;
char *ins_data;
int i;
struct list_head ordered_sums;
int skip_csum = BTRFS_I(inode)->flags & BTRFS_INODE_NODATASUM;
INIT_LIST_HEAD(&ordered_sums);
ins_data = kmalloc(nr * sizeof(struct btrfs_key) +
nr * sizeof(u32), GFP_NOFS);
if (!ins_data)
return -ENOMEM;
ins_sizes = (u32 *)ins_data;
ins_keys = (struct btrfs_key *)(ins_data + nr * sizeof(u32));
for (i = 0; i < nr; i++) {
ins_sizes[i] = btrfs_item_size_nr(src, i + start_slot);
btrfs_item_key_to_cpu(src, ins_keys + i, i + start_slot);
}
ret = btrfs_insert_empty_items(trans, log, dst_path,
ins_keys, ins_sizes, nr);
if (ret) {
kfree(ins_data);
return ret;
}
for (i = 0; i < nr; i++, dst_path->slots[0]++) {
dst_offset = btrfs_item_ptr_offset(dst_path->nodes[0],
dst_path->slots[0]);
src_offset = btrfs_item_ptr_offset(src, start_slot + i);
if (ins_keys[i].type == BTRFS_INODE_ITEM_KEY) {
inode_item = btrfs_item_ptr(dst_path->nodes[0],
dst_path->slots[0],
struct btrfs_inode_item);
fill_inode_item(trans, dst_path->nodes[0], inode_item,
inode, inode_only == LOG_INODE_EXISTS);
} else {
copy_extent_buffer(dst_path->nodes[0], src, dst_offset,
src_offset, ins_sizes[i]);
}
if (btrfs_key_type(ins_keys + i) == BTRFS_EXTENT_DATA_KEY &&
!skip_csum) {
int found_type;
extent = btrfs_item_ptr(src, start_slot + i,
struct btrfs_file_extent_item);
if (btrfs_file_extent_generation(src, extent) < trans->transid)
continue;
found_type = btrfs_file_extent_type(src, extent);
if (found_type == BTRFS_FILE_EXTENT_REG) {
u64 ds, dl, cs, cl;
ds = btrfs_file_extent_disk_bytenr(src,
extent);
if (ds == 0)
continue;
dl = btrfs_file_extent_disk_num_bytes(src,
extent);
cs = btrfs_file_extent_offset(src, extent);
cl = btrfs_file_extent_num_bytes(src,
extent);
if (btrfs_file_extent_compression(src,
extent)) {
cs = 0;
cl = dl;
}
ret = btrfs_lookup_csums_range(
log->fs_info->csum_root,
ds + cs, ds + cs + cl - 1,
&ordered_sums, 0);
if (ret) {
btrfs_release_path(dst_path);
kfree(ins_data);
return ret;
}
}
}
}
btrfs_mark_buffer_dirty(dst_path->nodes[0]);
btrfs_release_path(dst_path);
kfree(ins_data);
ret = 0;
while (!list_empty(&ordered_sums)) {
struct btrfs_ordered_sum *sums = list_entry(ordered_sums.next,
struct btrfs_ordered_sum,
list);
if (!ret)
ret = btrfs_csum_file_blocks(trans, log, sums);
list_del(&sums->list);
kfree(sums);
}
return ret;
}
static int extent_cmp(void *priv, struct list_head *a, struct list_head *b)
{
struct extent_map *em1, *em2;
em1 = list_entry(a, struct extent_map, list);
em2 = list_entry(b, struct extent_map, list);
if (em1->start < em2->start)
return -1;
else if (em1->start > em2->start)
return 1;
return 0;
}
static int log_one_extent(struct btrfs_trans_handle *trans,
struct inode *inode, struct btrfs_root *root,
struct extent_map *em, struct btrfs_path *path)
{
struct btrfs_root *log = root->log_root;
struct btrfs_file_extent_item *fi;
struct extent_buffer *leaf;
struct btrfs_ordered_extent *ordered;
struct list_head ordered_sums;
struct btrfs_map_token token;
struct btrfs_key key;
u64 mod_start = em->mod_start;
u64 mod_len = em->mod_len;
u64 csum_offset;
u64 csum_len;
u64 extent_offset = em->start - em->orig_start;
u64 block_len;
int ret;
int index = log->log_transid % 2;
bool skip_csum = BTRFS_I(inode)->flags & BTRFS_INODE_NODATASUM;
ret = __btrfs_drop_extents(trans, log, inode, path, em->start,
em->start + em->len, NULL, 0);
if (ret)
return ret;
INIT_LIST_HEAD(&ordered_sums);
btrfs_init_map_token(&token);
key.objectid = btrfs_ino(inode);
key.type = BTRFS_EXTENT_DATA_KEY;
key.offset = em->start;
ret = btrfs_insert_empty_item(trans, log, path, &key, sizeof(*fi));
if (ret)
return ret;
leaf = path->nodes[0];
fi = btrfs_item_ptr(leaf, path->slots[0],
struct btrfs_file_extent_item);
btrfs_set_token_file_extent_generation(leaf, fi, em->generation,
&token);
if (test_bit(EXTENT_FLAG_PREALLOC, &em->flags)) {
skip_csum = true;
btrfs_set_token_file_extent_type(leaf, fi,
BTRFS_FILE_EXTENT_PREALLOC,
&token);
} else {
btrfs_set_token_file_extent_type(leaf, fi,
BTRFS_FILE_EXTENT_REG,
&token);
if (em->block_start == 0)
skip_csum = true;
}
block_len = max(em->block_len, em->orig_block_len);
if (em->compress_type != BTRFS_COMPRESS_NONE) {
btrfs_set_token_file_extent_disk_bytenr(leaf, fi,
em->block_start,
&token);
btrfs_set_token_file_extent_disk_num_bytes(leaf, fi, block_len,
&token);
} else if (em->block_start < EXTENT_MAP_LAST_BYTE) {
btrfs_set_token_file_extent_disk_bytenr(leaf, fi,
em->block_start -
extent_offset, &token);
btrfs_set_token_file_extent_disk_num_bytes(leaf, fi, block_len,
&token);
} else {
btrfs_set_token_file_extent_disk_bytenr(leaf, fi, 0, &token);
btrfs_set_token_file_extent_disk_num_bytes(leaf, fi, 0,
&token);
}
btrfs_set_token_file_extent_offset(leaf, fi,
em->start - em->orig_start,
&token);
btrfs_set_token_file_extent_num_bytes(leaf, fi, em->len, &token);
btrfs_set_token_file_extent_ram_bytes(leaf, fi, em->ram_bytes, &token);
btrfs_set_token_file_extent_compression(leaf, fi, em->compress_type,
&token);
btrfs_set_token_file_extent_encryption(leaf, fi, 0, &token);
btrfs_set_token_file_extent_other_encoding(leaf, fi, 0, &token);
btrfs_mark_buffer_dirty(leaf);
btrfs_release_path(path);
if (ret) {
return ret;
}
if (skip_csum)
return 0;
if (em->compress_type) {
csum_offset = 0;
csum_len = block_len;
}
again:
spin_lock_irq(&log->log_extents_lock[index]);
list_for_each_entry(ordered, &log->logged_list[index], log_list) {
struct btrfs_ordered_sum *sum;
if (!mod_len)
break;
if (ordered->inode != inode)
continue;
if (ordered->file_offset + ordered->len <= mod_start ||
mod_start + mod_len <= ordered->file_offset)
continue;
if (ordered->file_offset > mod_start) {
if (ordered->file_offset + ordered->len >=
mod_start + mod_len)
mod_len = ordered->file_offset - mod_start;
} else {
if (ordered->file_offset + ordered->len <
mod_start + mod_len) {
mod_len = (mod_start + mod_len) -
(ordered->file_offset + ordered->len);
mod_start = ordered->file_offset +
ordered->len;
} else {
mod_len = 0;
}
}
if (test_and_set_bit(BTRFS_ORDERED_LOGGED_CSUM,
&ordered->flags))
continue;
atomic_inc(&ordered->refs);
spin_unlock_irq(&log->log_extents_lock[index]);
wait_event(ordered->wait, ordered->csum_bytes_left == 0);
list_for_each_entry(sum, &ordered->list, list) {
ret = btrfs_csum_file_blocks(trans, log, sum);
if (ret) {
btrfs_put_ordered_extent(ordered);
goto unlocked;
}
}
btrfs_put_ordered_extent(ordered);
goto again;
}
spin_unlock_irq(&log->log_extents_lock[index]);
unlocked:
if (!mod_len || ret)
return ret;
csum_offset = mod_start - em->start;
csum_len = mod_len;
ret = btrfs_lookup_csums_range(log->fs_info->csum_root,
em->block_start + csum_offset,
em->block_start + csum_offset +
csum_len - 1, &ordered_sums, 0);
if (ret)
return ret;
while (!list_empty(&ordered_sums)) {
struct btrfs_ordered_sum *sums = list_entry(ordered_sums.next,
struct btrfs_ordered_sum,
list);
if (!ret)
ret = btrfs_csum_file_blocks(trans, log, sums);
list_del(&sums->list);
kfree(sums);
}
return ret;
}
static int btrfs_log_changed_extents(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct inode *inode,
struct btrfs_path *path)
{
struct extent_map *em, *n;
struct list_head extents;
struct extent_map_tree *tree = &BTRFS_I(inode)->extent_tree;
u64 test_gen;
int ret = 0;
int num = 0;
INIT_LIST_HEAD(&extents);
write_lock(&tree->lock);
test_gen = root->fs_info->last_trans_committed;
list_for_each_entry_safe(em, n, &tree->modified_extents, list) {
list_del_init(&em->list);
if (++num > 32768) {
list_del_init(&tree->modified_extents);
ret = -EFBIG;
goto process;
}
if (em->generation <= test_gen)
continue;
atomic_inc(&em->refs);
set_bit(EXTENT_FLAG_LOGGING, &em->flags);
list_add_tail(&em->list, &extents);
num++;
}
list_sort(NULL, &extents, extent_cmp);
process:
while (!list_empty(&extents)) {
em = list_entry(extents.next, struct extent_map, list);
list_del_init(&em->list);
if (ret) {
clear_em_logging(tree, em);
free_extent_map(em);
continue;
}
write_unlock(&tree->lock);
ret = log_one_extent(trans, inode, root, em, path);
write_lock(&tree->lock);
clear_em_logging(tree, em);
free_extent_map(em);
}
WARN_ON(!list_empty(&extents));
write_unlock(&tree->lock);
btrfs_release_path(path);
return ret;
}
static int btrfs_log_inode(struct btrfs_trans_handle *trans,
struct btrfs_root *root, struct inode *inode,
int inode_only)
{
struct btrfs_path *path;
struct btrfs_path *dst_path;
struct btrfs_key min_key;
struct btrfs_key max_key;
struct btrfs_root *log = root->log_root;
struct extent_buffer *src = NULL;
int err = 0;
int ret;
int nritems;
int ins_start_slot = 0;
int ins_nr;
bool fast_search = false;
u64 ino = btrfs_ino(inode);
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
dst_path = btrfs_alloc_path();
if (!dst_path) {
btrfs_free_path(path);
return -ENOMEM;
}
min_key.objectid = ino;
min_key.type = BTRFS_INODE_ITEM_KEY;
min_key.offset = 0;
max_key.objectid = ino;
if (S_ISDIR(inode->i_mode) ||
(!test_bit(BTRFS_INODE_NEEDS_FULL_SYNC,
&BTRFS_I(inode)->runtime_flags) &&
inode_only == LOG_INODE_EXISTS))
max_key.type = BTRFS_XATTR_ITEM_KEY;
else
max_key.type = (u8)-1;
max_key.offset = (u64)-1;
if (S_ISDIR(inode->i_mode) ||
BTRFS_I(inode)->generation > root->fs_info->last_trans_committed) {
ret = btrfs_commit_inode_delayed_items(trans, inode);
if (ret) {
btrfs_free_path(path);
btrfs_free_path(dst_path);
return ret;
}
}
mutex_lock(&BTRFS_I(inode)->log_mutex);
btrfs_get_logged_extents(log, inode);
if (S_ISDIR(inode->i_mode)) {
int max_key_type = BTRFS_DIR_LOG_INDEX_KEY;
if (inode_only == LOG_INODE_EXISTS)
max_key_type = BTRFS_XATTR_ITEM_KEY;
ret = drop_objectid_items(trans, log, path, ino, max_key_type);
} else {
if (test_and_clear_bit(BTRFS_INODE_NEEDS_FULL_SYNC,
&BTRFS_I(inode)->runtime_flags)) {
clear_bit(BTRFS_INODE_COPY_EVERYTHING,
&BTRFS_I(inode)->runtime_flags);
ret = btrfs_truncate_inode_items(trans, log,
inode, 0, 0);
} else if (test_and_clear_bit(BTRFS_INODE_COPY_EVERYTHING,
&BTRFS_I(inode)->runtime_flags)) {
if (inode_only == LOG_INODE_ALL)
fast_search = true;
max_key.type = BTRFS_XATTR_ITEM_KEY;
ret = drop_objectid_items(trans, log, path, ino,
max_key.type);
} else {
if (inode_only == LOG_INODE_ALL)
fast_search = true;
ret = log_inode_item(trans, log, dst_path, inode);
if (ret) {
err = ret;
goto out_unlock;
}
goto log_extents;
}
}
if (ret) {
err = ret;
goto out_unlock;
}
path->keep_locks = 1;
while (1) {
ins_nr = 0;
ret = btrfs_search_forward(root, &min_key, &max_key,
path, trans->transid);
if (ret != 0)
break;
again:
if (min_key.objectid != ino)
break;
if (min_key.type > max_key.type)
break;
src = path->nodes[0];
if (ins_nr && ins_start_slot + ins_nr == path->slots[0]) {
ins_nr++;
goto next_slot;
} else if (!ins_nr) {
ins_start_slot = path->slots[0];
ins_nr = 1;
goto next_slot;
}
ret = copy_items(trans, inode, dst_path, src, ins_start_slot,
ins_nr, inode_only);
if (ret) {
err = ret;
goto out_unlock;
}
ins_nr = 1;
ins_start_slot = path->slots[0];
next_slot:
nritems = btrfs_header_nritems(path->nodes[0]);
path->slots[0]++;
if (path->slots[0] < nritems) {
btrfs_item_key_to_cpu(path->nodes[0], &min_key,
path->slots[0]);
goto again;
}
if (ins_nr) {
ret = copy_items(trans, inode, dst_path, src,
ins_start_slot,
ins_nr, inode_only);
if (ret) {
err = ret;
goto out_unlock;
}
ins_nr = 0;
}
btrfs_release_path(path);
if (min_key.offset < (u64)-1)
min_key.offset++;
else if (min_key.type < (u8)-1)
min_key.type++;
else if (min_key.objectid < (u64)-1)
min_key.objectid++;
else
break;
}
if (ins_nr) {
ret = copy_items(trans, inode, dst_path, src, ins_start_slot,
ins_nr, inode_only);
if (ret) {
err = ret;
goto out_unlock;
}
ins_nr = 0;
}
log_extents:
btrfs_release_path(path);
btrfs_release_path(dst_path);
if (fast_search) {
ret = btrfs_log_changed_extents(trans, root, inode, dst_path);
if (ret) {
err = ret;
goto out_unlock;
}
} else {
struct extent_map_tree *tree = &BTRFS_I(inode)->extent_tree;
struct extent_map *em, *n;
write_lock(&tree->lock);
list_for_each_entry_safe(em, n, &tree->modified_extents, list)
list_del_init(&em->list);
write_unlock(&tree->lock);
}
if (inode_only == LOG_INODE_ALL && S_ISDIR(inode->i_mode)) {
ret = log_directory_changes(trans, root, inode, path, dst_path);
if (ret) {
err = ret;
goto out_unlock;
}
}
BTRFS_I(inode)->logged_trans = trans->transid;
BTRFS_I(inode)->last_log_commit = BTRFS_I(inode)->last_sub_trans;
out_unlock:
if (err)
btrfs_free_logged_extents(log, log->log_transid);
mutex_unlock(&BTRFS_I(inode)->log_mutex);
btrfs_free_path(path);
btrfs_free_path(dst_path);
return err;
}
static noinline int check_parent_dirs_for_sync(struct btrfs_trans_handle *trans,
struct inode *inode,
struct dentry *parent,
struct super_block *sb,
u64 last_committed)
{
int ret = 0;
struct btrfs_root *root;
struct dentry *old_parent = NULL;
if (S_ISREG(inode->i_mode) &&
BTRFS_I(inode)->generation <= last_committed &&
BTRFS_I(inode)->last_unlink_trans <= last_committed)
goto out;
if (!S_ISDIR(inode->i_mode)) {
if (!parent || !parent->d_inode || sb != parent->d_inode->i_sb)
goto out;
inode = parent->d_inode;
}
while (1) {
BTRFS_I(inode)->logged_trans = trans->transid;
smp_mb();
if (BTRFS_I(inode)->last_unlink_trans > last_committed) {
root = BTRFS_I(inode)->root;
root->fs_info->last_trans_log_full_commit =
trans->transid;
ret = 1;
break;
}
if (!parent || !parent->d_inode || sb != parent->d_inode->i_sb)
break;
if (IS_ROOT(parent))
break;
parent = dget_parent(parent);
dput(old_parent);
old_parent = parent;
inode = parent->d_inode;
}
dput(old_parent);
out:
return ret;
}
static int btrfs_log_inode_parent(struct btrfs_trans_handle *trans,
struct btrfs_root *root, struct inode *inode,
struct dentry *parent, int exists_only)
{
int inode_only = exists_only ? LOG_INODE_EXISTS : LOG_INODE_ALL;
struct super_block *sb;
struct dentry *old_parent = NULL;
int ret = 0;
u64 last_committed = root->fs_info->last_trans_committed;
sb = inode->i_sb;
if (btrfs_test_opt(root, NOTREELOG)) {
ret = 1;
goto end_no_trans;
}
if (root->fs_info->last_trans_log_full_commit >
root->fs_info->last_trans_committed) {
ret = 1;
goto end_no_trans;
}
if (root != BTRFS_I(inode)->root ||
btrfs_root_refs(&root->root_item) == 0) {
ret = 1;
goto end_no_trans;
}
ret = check_parent_dirs_for_sync(trans, inode, parent,
sb, last_committed);
if (ret)
goto end_no_trans;
if (btrfs_inode_in_log(inode, trans->transid)) {
ret = BTRFS_NO_LOG_SYNC;
goto end_no_trans;
}
ret = start_log_trans(trans, root);
if (ret)
goto end_trans;
ret = btrfs_log_inode(trans, root, inode, inode_only);
if (ret)
goto end_trans;
if (S_ISREG(inode->i_mode) &&
BTRFS_I(inode)->generation <= last_committed &&
BTRFS_I(inode)->last_unlink_trans <= last_committed) {
ret = 0;
goto end_trans;
}
inode_only = LOG_INODE_EXISTS;
while (1) {
if (!parent || !parent->d_inode || sb != parent->d_inode->i_sb)
break;
inode = parent->d_inode;
if (root != BTRFS_I(inode)->root)
break;
if (BTRFS_I(inode)->generation >
root->fs_info->last_trans_committed) {
ret = btrfs_log_inode(trans, root, inode, inode_only);
if (ret)
goto end_trans;
}
if (IS_ROOT(parent))
break;
parent = dget_parent(parent);
dput(old_parent);
old_parent = parent;
}
ret = 0;
end_trans:
dput(old_parent);
if (ret < 0) {
root->fs_info->last_trans_log_full_commit = trans->transid;
ret = 1;
}
btrfs_end_log_trans(root);
end_no_trans:
return ret;
}
int btrfs_log_dentry_safe(struct btrfs_trans_handle *trans,
struct btrfs_root *root, struct dentry *dentry)
{
struct dentry *parent = dget_parent(dentry);
int ret;
ret = btrfs_log_inode_parent(trans, root, dentry->d_inode, parent, 0);
dput(parent);
return ret;
}
int btrfs_recover_log_trees(struct btrfs_root *log_root_tree)
{
int ret;
struct btrfs_path *path;
struct btrfs_trans_handle *trans;
struct btrfs_key key;
struct btrfs_key found_key;
struct btrfs_key tmp_key;
struct btrfs_root *log;
struct btrfs_fs_info *fs_info = log_root_tree->fs_info;
struct walk_control wc = {
.process_func = process_one_buffer,
.stage = 0,
};
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
fs_info->log_root_recovering = 1;
trans = btrfs_start_transaction(fs_info->tree_root, 0);
if (IS_ERR(trans)) {
ret = PTR_ERR(trans);
goto error;
}
wc.trans = trans;
wc.pin = 1;
ret = walk_log_tree(trans, log_root_tree, &wc);
if (ret) {
btrfs_error(fs_info, ret, "Failed to pin buffers while "
"recovering log root tree.");
goto error;
}
again:
key.objectid = BTRFS_TREE_LOG_OBJECTID;
key.offset = (u64)-1;
btrfs_set_key_type(&key, BTRFS_ROOT_ITEM_KEY);
while (1) {
ret = btrfs_search_slot(NULL, log_root_tree, &key, path, 0, 0);
if (ret < 0) {
btrfs_error(fs_info, ret,
"Couldn't find tree log root.");
goto error;
}
if (ret > 0) {
if (path->slots[0] == 0)
break;
path->slots[0]--;
}
btrfs_item_key_to_cpu(path->nodes[0], &found_key,
path->slots[0]);
btrfs_release_path(path);
if (found_key.objectid != BTRFS_TREE_LOG_OBJECTID)
break;
log = btrfs_read_fs_root(log_root_tree, &found_key);
if (IS_ERR(log)) {
ret = PTR_ERR(log);
btrfs_error(fs_info, ret,
"Couldn't read tree log root.");
goto error;
}
tmp_key.objectid = found_key.offset;
tmp_key.type = BTRFS_ROOT_ITEM_KEY;
tmp_key.offset = (u64)-1;
wc.replay_dest = btrfs_read_fs_root_no_name(fs_info, &tmp_key);
if (IS_ERR(wc.replay_dest)) {
ret = PTR_ERR(wc.replay_dest);
free_extent_buffer(log->node);
free_extent_buffer(log->commit_root);
kfree(log);
btrfs_error(fs_info, ret, "Couldn't read target root "
"for tree log recovery.");
goto error;
}
wc.replay_dest->log_root = log;
btrfs_record_root_in_trans(trans, wc.replay_dest);
ret = walk_log_tree(trans, log, &wc);
if (!ret && wc.stage == LOG_WALK_REPLAY_ALL) {
ret = fixup_inode_link_counts(trans, wc.replay_dest,
path);
}
key.offset = found_key.offset - 1;
wc.replay_dest->log_root = NULL;
free_extent_buffer(log->node);
free_extent_buffer(log->commit_root);
kfree(log);
if (ret)
goto error;
if (found_key.offset == 0)
break;
}
btrfs_release_path(path);
if (wc.pin) {
wc.pin = 0;
wc.process_func = replay_one_buffer;
wc.stage = LOG_WALK_REPLAY_INODES;
goto again;
}
if (wc.stage < LOG_WALK_REPLAY_ALL) {
wc.stage++;
goto again;
}
btrfs_free_path(path);
ret = btrfs_commit_transaction(trans, fs_info->tree_root);
if (ret)
return ret;
free_extent_buffer(log_root_tree->node);
log_root_tree->log_root = NULL;
fs_info->log_root_recovering = 0;
kfree(log_root_tree);
return 0;
error:
if (wc.trans)
btrfs_end_transaction(wc.trans, fs_info->tree_root);
btrfs_free_path(path);
return ret;
}
void btrfs_record_unlink_dir(struct btrfs_trans_handle *trans,
struct inode *dir, struct inode *inode,
int for_rename)
{
if (S_ISREG(inode->i_mode))
BTRFS_I(inode)->last_unlink_trans = trans->transid;
smp_mb();
if (BTRFS_I(dir)->logged_trans == trans->transid)
return;
if (BTRFS_I(inode)->logged_trans == trans->transid)
return;
if (for_rename)
goto record;
return;
record:
BTRFS_I(dir)->last_unlink_trans = trans->transid;
}
int btrfs_log_new_name(struct btrfs_trans_handle *trans,
struct inode *inode, struct inode *old_dir,
struct dentry *parent)
{
struct btrfs_root * root = BTRFS_I(inode)->root;
if (S_ISREG(inode->i_mode))
BTRFS_I(inode)->last_unlink_trans = trans->transid;
if (BTRFS_I(inode)->logged_trans <=
root->fs_info->last_trans_committed &&
(!old_dir || BTRFS_I(old_dir)->logged_trans <=
root->fs_info->last_trans_committed))
return 0;
return btrfs_log_inode_parent(trans, root, inode, parent, 1);
}
