static int __inode_info(u64 inum, u64 ioff, u8 key_type,
struct btrfs_root *fs_root, struct btrfs_path *path,
struct btrfs_key *found_key)
{
int ret;
struct btrfs_key key;
struct extent_buffer *eb;
key.type = key_type;
key.objectid = inum;
key.offset = ioff;
ret = btrfs_search_slot(NULL, fs_root, &key, path, 0, 0);
if (ret < 0)
return ret;
eb = path->nodes[0];
if (ret && path->slots[0] >= btrfs_header_nritems(eb)) {
ret = btrfs_next_leaf(fs_root, path);
if (ret)
return ret;
eb = path->nodes[0];
}
btrfs_item_key_to_cpu(eb, found_key, path->slots[0]);
if (found_key->type != key.type || found_key->objectid != key.objectid)
return 1;
return 0;
}
int inode_item_info(u64 inum, u64 ioff, struct btrfs_root *fs_root,
struct btrfs_path *path)
{
struct btrfs_key key;
return __inode_info(inum, ioff, BTRFS_INODE_ITEM_KEY, fs_root, path,
&key);
}
static int inode_ref_info(u64 inum, u64 ioff, struct btrfs_root *fs_root,
struct btrfs_path *path,
struct btrfs_key *found_key)
{
return __inode_info(inum, ioff, BTRFS_INODE_REF_KEY, fs_root, path,
found_key);
}
static char *iref_to_path(struct btrfs_root *fs_root, struct btrfs_path *path,
struct btrfs_inode_ref *iref,
struct extent_buffer *eb_in, u64 parent,
char *dest, u32 size)
{
u32 len;
int slot;
u64 next_inum;
int ret;
s64 bytes_left = size - 1;
struct extent_buffer *eb = eb_in;
struct btrfs_key found_key;
if (bytes_left >= 0)
dest[bytes_left] = '\0';
while (1) {
len = btrfs_inode_ref_name_len(eb, iref);
bytes_left -= len;
if (bytes_left >= 0)
read_extent_buffer(eb, dest + bytes_left,
(unsigned long)(iref + 1), len);
if (eb != eb_in)
free_extent_buffer(eb);
ret = inode_ref_info(parent, 0, fs_root, path, &found_key);
if (ret)
break;
next_inum = found_key.offset;
if (parent == next_inum)
break;
slot = path->slots[0];
eb = path->nodes[0];
if (eb != eb_in)
atomic_inc(&eb->refs);
btrfs_release_path(path);
iref = btrfs_item_ptr(eb, slot, struct btrfs_inode_ref);
parent = next_inum;
--bytes_left;
if (bytes_left >= 0)
dest[bytes_left] = '/';
}
btrfs_release_path(path);
if (ret)
return ERR_PTR(ret);
return dest + bytes_left;
}
int extent_from_logical(struct btrfs_fs_info *fs_info, u64 logical,
struct btrfs_path *path, struct btrfs_key *found_key)
{
int ret;
u64 flags;
u32 item_size;
struct extent_buffer *eb;
struct btrfs_extent_item *ei;
struct btrfs_key key;
key.type = BTRFS_EXTENT_ITEM_KEY;
key.objectid = logical;
key.offset = (u64)-1;
ret = btrfs_search_slot(NULL, fs_info->extent_root, &key, path, 0, 0);
if (ret < 0)
return ret;
ret = btrfs_previous_item(fs_info->extent_root, path,
0, BTRFS_EXTENT_ITEM_KEY);
if (ret < 0)
return ret;
btrfs_item_key_to_cpu(path->nodes[0], found_key, path->slots[0]);
if (found_key->type != BTRFS_EXTENT_ITEM_KEY ||
found_key->objectid > logical ||
found_key->objectid + found_key->offset <= logical)
return -ENOENT;
eb = path->nodes[0];
item_size = btrfs_item_size_nr(eb, path->slots[0]);
BUG_ON(item_size < sizeof(*ei));
ei = btrfs_item_ptr(eb, path->slots[0], struct btrfs_extent_item);
flags = btrfs_extent_flags(eb, ei);
if (flags & BTRFS_EXTENT_FLAG_TREE_BLOCK)
return BTRFS_EXTENT_FLAG_TREE_BLOCK;
if (flags & BTRFS_EXTENT_FLAG_DATA)
return BTRFS_EXTENT_FLAG_DATA;
return -EIO;
}
static int __get_extent_inline_ref(unsigned long *ptr, struct extent_buffer *eb,
struct btrfs_extent_item *ei, u32 item_size,
struct btrfs_extent_inline_ref **out_eiref,
int *out_type)
{
unsigned long end;
u64 flags;
struct btrfs_tree_block_info *info;
if (!*ptr) {
flags = btrfs_extent_flags(eb, ei);
if (flags & BTRFS_EXTENT_FLAG_TREE_BLOCK) {
info = (struct btrfs_tree_block_info *)(ei + 1);
*out_eiref =
(struct btrfs_extent_inline_ref *)(info + 1);
} else {
*out_eiref = (struct btrfs_extent_inline_ref *)(ei + 1);
}
*ptr = (unsigned long)*out_eiref;
if ((void *)*ptr >= (void *)ei + item_size)
return -ENOENT;
}
end = (unsigned long)ei + item_size;
*out_eiref = (struct btrfs_extent_inline_ref *)*ptr;
*out_type = btrfs_extent_inline_ref_type(eb, *out_eiref);
*ptr += btrfs_extent_inline_ref_size(*out_type);
WARN_ON(*ptr > end);
if (*ptr == end)
return 1;
return 0;
}
int tree_backref_for_extent(unsigned long *ptr, struct extent_buffer *eb,
struct btrfs_extent_item *ei, u32 item_size,
u64 *out_root, u8 *out_level)
{
int ret;
int type;
struct btrfs_tree_block_info *info;
struct btrfs_extent_inline_ref *eiref;
if (*ptr == (unsigned long)-1)
return 1;
while (1) {
ret = __get_extent_inline_ref(ptr, eb, ei, item_size,
&eiref, &type);
if (ret < 0)
return ret;
if (type == BTRFS_TREE_BLOCK_REF_KEY ||
type == BTRFS_SHARED_BLOCK_REF_KEY)
break;
if (ret == 1)
return 1;
}
info = (struct btrfs_tree_block_info *)(ei + 1);
*out_root = btrfs_extent_inline_ref_offset(eb, eiref);
*out_level = btrfs_tree_block_level(eb, info);
if (ret == 1)
*ptr = (unsigned long)-1;
return 0;
}
static int __data_list_add(struct list_head *head, u64 inum,
u64 extent_data_item_offset, u64 root)
{
struct __data_ref *ref;
ref = kmalloc(sizeof(*ref), GFP_NOFS);
if (!ref)
return -ENOMEM;
ref->inum = inum;
ref->extent_data_item_offset = extent_data_item_offset;
ref->root = root;
list_add_tail(&ref->list, head);
return 0;
}
static int __data_list_add_eb(struct list_head *head, struct extent_buffer *eb,
struct btrfs_extent_data_ref *dref)
{
return __data_list_add(head, btrfs_extent_data_ref_objectid(eb, dref),
btrfs_extent_data_ref_offset(eb, dref),
btrfs_extent_data_ref_root(eb, dref));
}
static int __shared_list_add(struct list_head *head, u64 disk_byte)
{
struct __shared_ref *ref;
ref = kmalloc(sizeof(*ref), GFP_NOFS);
if (!ref)
return -ENOMEM;
ref->disk_byte = disk_byte;
list_add_tail(&ref->list, head);
return 0;
}
static int __iter_shared_inline_ref_inodes(struct btrfs_fs_info *fs_info,
u64 logical, u64 inum,
u64 extent_data_item_offset,
u64 extent_offset,
struct btrfs_path *path,
struct list_head *data_refs,
iterate_extent_inodes_t *iterate,
void *ctx)
{
u64 ref_root;
u32 item_size;
struct btrfs_key key;
struct extent_buffer *eb;
struct btrfs_extent_item *ei;
struct btrfs_extent_inline_ref *eiref;
struct __data_ref *ref;
int ret;
int type;
int last;
unsigned long ptr = 0;
WARN_ON(!list_empty(data_refs));
ret = extent_from_logical(fs_info, logical, path, &key);
if (ret & BTRFS_EXTENT_FLAG_DATA)
ret = -EIO;
if (ret < 0)
goto out;
eb = path->nodes[0];
ei = btrfs_item_ptr(eb, path->slots[0], struct btrfs_extent_item);
item_size = btrfs_item_size_nr(eb, path->slots[0]);
ret = 0;
ref_root = 0;
do {
last = __get_extent_inline_ref(&ptr, eb, ei, item_size,
&eiref, &type);
if (last < 0) {
ret = last;
goto out;
}
if (type == BTRFS_TREE_BLOCK_REF_KEY ||
type == BTRFS_SHARED_BLOCK_REF_KEY) {
ref_root = btrfs_extent_inline_ref_offset(eb, eiref);
ret = __data_list_add(data_refs, inum,
extent_data_item_offset,
ref_root);
}
} while (!ret && !last);
btrfs_release_path(path);
if (ref_root == 0) {
printk(KERN_ERR "btrfs: failed to find tree block ref "
"for shared data backref %llu\n", logical);
WARN_ON(1);
ret = -EIO;
}
out:
while (!list_empty(data_refs)) {
ref = list_first_entry(data_refs, struct __data_ref, list);
list_del(&ref->list);
if (!ret)
ret = iterate(ref->inum, extent_offset +
ref->extent_data_item_offset,
ref->root, ctx);
kfree(ref);
}
return ret;
}
static int __iter_shared_inline_ref(struct btrfs_fs_info *fs_info,
u64 logical, u64 orig_extent_item_objectid,
u64 extent_offset, struct btrfs_path *path,
struct list_head *data_refs,
iterate_extent_inodes_t *iterate,
void *ctx)
{
u64 disk_byte;
struct btrfs_key key;
struct btrfs_file_extent_item *fi;
struct extent_buffer *eb;
int slot;
int nritems;
int ret;
int found = 0;
eb = read_tree_block(fs_info->tree_root, logical,
fs_info->tree_root->leafsize, 0);
if (!eb)
return -EIO;
nritems = btrfs_header_nritems(eb);
for (slot = 0; slot < nritems; ++slot) {
btrfs_item_key_to_cpu(eb, &key, slot);
if (key.type != BTRFS_EXTENT_DATA_KEY)
continue;
fi = btrfs_item_ptr(eb, slot, struct btrfs_file_extent_item);
if (!fi) {
free_extent_buffer(eb);
return -EIO;
}
disk_byte = btrfs_file_extent_disk_bytenr(eb, fi);
if (disk_byte != orig_extent_item_objectid) {
if (found)
break;
else
continue;
}
++found;
ret = __iter_shared_inline_ref_inodes(fs_info, logical,
key.objectid,
key.offset,
extent_offset, path,
data_refs,
iterate, ctx);
if (ret)
break;
}
if (!found) {
printk(KERN_ERR "btrfs: failed to follow shared data backref "
"to parent %llu\n", logical);
WARN_ON(1);
ret = -EIO;
}
free_extent_buffer(eb);
return ret;
}
int iterate_extent_inodes(struct btrfs_fs_info *fs_info,
struct btrfs_path *path,
u64 extent_item_objectid,
u64 extent_offset,
iterate_extent_inodes_t *iterate, void *ctx)
{
unsigned long ptr = 0;
int last;
int ret;
int type;
u64 logical;
u32 item_size;
struct btrfs_extent_inline_ref *eiref;
struct btrfs_extent_data_ref *dref;
struct extent_buffer *eb;
struct btrfs_extent_item *ei;
struct btrfs_key key;
struct list_head data_refs = LIST_HEAD_INIT(data_refs);
struct list_head shared_refs = LIST_HEAD_INIT(shared_refs);
struct __data_ref *ref_d;
struct __shared_ref *ref_s;
eb = path->nodes[0];
ei = btrfs_item_ptr(eb, path->slots[0], struct btrfs_extent_item);
item_size = btrfs_item_size_nr(eb, path->slots[0]);
do {
last = __get_extent_inline_ref(&ptr, eb, ei, item_size,
&eiref, &type);
if (last == -ENOENT) {
ret = 0;
break;
}
if (last < 0) {
ret = last;
break;
}
if (type == BTRFS_EXTENT_DATA_REF_KEY) {
dref = (struct btrfs_extent_data_ref *)(&eiref->offset);
ret = __data_list_add_eb(&data_refs, eb, dref);
} else if (type == BTRFS_SHARED_DATA_REF_KEY) {
logical = btrfs_extent_inline_ref_offset(eb, eiref);
ret = __shared_list_add(&shared_refs, logical);
}
} while (!ret && !last);
while (!ret) {
++path->slots[0];
if (path->slots[0] > btrfs_header_nritems(eb)) {
ret = btrfs_next_leaf(fs_info->extent_root, path);
if (ret) {
if (ret == 1)
ret = 0;
break;
}
eb = path->nodes[0];
}
btrfs_item_key_to_cpu(eb, &key, path->slots[0]);
if (key.objectid != extent_item_objectid)
break;
if (key.type == BTRFS_EXTENT_DATA_REF_KEY) {
dref = btrfs_item_ptr(eb, path->slots[0],
struct btrfs_extent_data_ref);
ret = __data_list_add_eb(&data_refs, eb, dref);
} else if (key.type == BTRFS_SHARED_DATA_REF_KEY) {
ret = __shared_list_add(&shared_refs, key.offset);
}
}
btrfs_release_path(path);
while (!list_empty(&data_refs)) {
ref_d = list_first_entry(&data_refs, struct __data_ref, list);
list_del(&ref_d->list);
if (!ret)
ret = iterate(ref_d->inum, extent_offset +
ref_d->extent_data_item_offset,
ref_d->root, ctx);
kfree(ref_d);
}
while (!list_empty(&shared_refs)) {
ref_s = list_first_entry(&shared_refs, struct __shared_ref,
list);
list_del(&ref_s->list);
if (!ret)
ret = __iter_shared_inline_ref(fs_info,
ref_s->disk_byte,
extent_item_objectid,
extent_offset, path,
&data_refs,
iterate, ctx);
kfree(ref_s);
}
return ret;
}
int iterate_inodes_from_logical(u64 logical, struct btrfs_fs_info *fs_info,
struct btrfs_path *path,
iterate_extent_inodes_t *iterate, void *ctx)
{
int ret;
u64 offset;
struct btrfs_key found_key;
ret = extent_from_logical(fs_info, logical, path,
&found_key);
if (ret & BTRFS_EXTENT_FLAG_TREE_BLOCK)
ret = -EINVAL;
if (ret < 0)
return ret;
offset = logical - found_key.objectid;
ret = iterate_extent_inodes(fs_info, path, found_key.objectid,
offset, iterate, ctx);
return ret;
}
static int iterate_irefs(u64 inum, struct btrfs_root *fs_root,
struct btrfs_path *path,
iterate_irefs_t *iterate, void *ctx)
{
int ret;
int slot;
u32 cur;
u32 len;
u32 name_len;
u64 parent = 0;
int found = 0;
struct extent_buffer *eb;
struct btrfs_item *item;
struct btrfs_inode_ref *iref;
struct btrfs_key found_key;
while (1) {
ret = inode_ref_info(inum, parent ? parent+1 : 0, fs_root, path,
&found_key);
if (ret < 0)
break;
if (ret) {
ret = found ? 0 : -ENOENT;
break;
}
++found;
parent = found_key.offset;
slot = path->slots[0];
eb = path->nodes[0];
atomic_inc(&eb->refs);
btrfs_release_path(path);
item = btrfs_item_nr(eb, slot);
iref = btrfs_item_ptr(eb, slot, struct btrfs_inode_ref);
for (cur = 0; cur < btrfs_item_size(eb, item); cur += len) {
name_len = btrfs_inode_ref_name_len(eb, iref);
ret = iterate(parent, iref, eb, ctx);
if (ret) {
free_extent_buffer(eb);
break;
}
len = sizeof(*iref) + name_len;
iref = (struct btrfs_inode_ref *)((char *)iref + len);
}
free_extent_buffer(eb);
}
btrfs_release_path(path);
return ret;
}
static int inode_to_path(u64 inum, struct btrfs_inode_ref *iref,
struct extent_buffer *eb, void *ctx)
{
struct inode_fs_paths *ipath = ctx;
char *fspath;
char *fspath_min;
int i = ipath->fspath->elem_cnt;
const int s_ptr = sizeof(char *);
u32 bytes_left;
bytes_left = ipath->fspath->bytes_left > s_ptr ?
ipath->fspath->bytes_left - s_ptr : 0;
fspath_min = (char *)ipath->fspath->val + (i + 1) * s_ptr;
fspath = iref_to_path(ipath->fs_root, ipath->btrfs_path, iref, eb,
inum, fspath_min, bytes_left);
if (IS_ERR(fspath))
return PTR_ERR(fspath);
if (fspath > fspath_min) {
ipath->fspath->val[i] = (u64)(unsigned long)fspath;
++ipath->fspath->elem_cnt;
ipath->fspath->bytes_left = fspath - fspath_min;
} else {
++ipath->fspath->elem_missed;
ipath->fspath->bytes_missing += fspath_min - fspath;
ipath->fspath->bytes_left = 0;
}
return 0;
}
int paths_from_inode(u64 inum, struct inode_fs_paths *ipath)
{
return iterate_irefs(inum, ipath->fs_root, ipath->btrfs_path,
inode_to_path, ipath);
}
struct btrfs_data_container *init_data_container(u32 total_bytes)
{
struct btrfs_data_container *data;
size_t alloc_bytes;
alloc_bytes = max_t(size_t, total_bytes, sizeof(*data));
data = kmalloc(alloc_bytes, GFP_NOFS);
if (!data)
return ERR_PTR(-ENOMEM);
if (total_bytes >= sizeof(*data)) {
data->bytes_left = total_bytes - sizeof(*data);
data->bytes_missing = 0;
} else {
data->bytes_missing = sizeof(*data) - total_bytes;
data->bytes_left = 0;
}
data->elem_cnt = 0;
data->elem_missed = 0;
return data;
}
struct inode_fs_paths *init_ipath(s32 total_bytes, struct btrfs_root *fs_root,
struct btrfs_path *path)
{
struct inode_fs_paths *ifp;
struct btrfs_data_container *fspath;
fspath = init_data_container(total_bytes);
if (IS_ERR(fspath))
return (void *)fspath;
ifp = kmalloc(sizeof(*ifp), GFP_NOFS);
if (!ifp) {
kfree(fspath);
return ERR_PTR(-ENOMEM);
}
ifp->btrfs_path = path;
ifp->fspath = fspath;
ifp->fs_root = fs_root;
return ifp;
}
void free_ipath(struct inode_fs_paths *ipath)
{
kfree(ipath);
}
