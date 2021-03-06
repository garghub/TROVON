static void btrfsic_block_init(struct btrfsic_block *b)
{
b->magic_num = BTRFSIC_BLOCK_MAGIC_NUMBER;
b->dev_state = NULL;
b->dev_bytenr = 0;
b->logical_bytenr = 0;
b->generation = BTRFSIC_GENERATION_UNKNOWN;
b->disk_key.objectid = 0;
b->disk_key.type = 0;
b->disk_key.offset = 0;
b->is_metadata = 0;
b->is_superblock = 0;
b->is_iodone = 0;
b->iodone_w_error = 0;
b->never_written = 0;
b->mirror_num = 0;
b->next_in_same_bio = NULL;
b->orig_bio_bh_private = NULL;
b->orig_bio_bh_end_io.bio = NULL;
INIT_LIST_HEAD(&b->collision_resolving_node);
INIT_LIST_HEAD(&b->all_blocks_node);
INIT_LIST_HEAD(&b->ref_to_list);
INIT_LIST_HEAD(&b->ref_from_list);
b->submit_bio_bh_rw = 0;
b->flush_gen = 0;
}
static struct btrfsic_block *btrfsic_block_alloc(void)
{
struct btrfsic_block *b;
b = kzalloc(sizeof(*b), GFP_NOFS);
if (NULL != b)
btrfsic_block_init(b);
return b;
}
static void btrfsic_block_free(struct btrfsic_block *b)
{
BUG_ON(!(NULL == b || BTRFSIC_BLOCK_MAGIC_NUMBER == b->magic_num));
kfree(b);
}
static void btrfsic_block_link_init(struct btrfsic_block_link *l)
{
l->magic_num = BTRFSIC_BLOCK_LINK_MAGIC_NUMBER;
l->ref_cnt = 1;
INIT_LIST_HEAD(&l->node_ref_to);
INIT_LIST_HEAD(&l->node_ref_from);
INIT_LIST_HEAD(&l->collision_resolving_node);
l->block_ref_to = NULL;
l->block_ref_from = NULL;
}
static struct btrfsic_block_link *btrfsic_block_link_alloc(void)
{
struct btrfsic_block_link *l;
l = kzalloc(sizeof(*l), GFP_NOFS);
if (NULL != l)
btrfsic_block_link_init(l);
return l;
}
static void btrfsic_block_link_free(struct btrfsic_block_link *l)
{
BUG_ON(!(NULL == l || BTRFSIC_BLOCK_LINK_MAGIC_NUMBER == l->magic_num));
kfree(l);
}
static void btrfsic_dev_state_init(struct btrfsic_dev_state *ds)
{
ds->magic_num = BTRFSIC_DEV2STATE_MAGIC_NUMBER;
ds->bdev = NULL;
ds->state = NULL;
ds->name[0] = '\0';
INIT_LIST_HEAD(&ds->collision_resolving_node);
ds->last_flush_gen = 0;
btrfsic_block_init(&ds->dummy_block_for_bio_bh_flush);
ds->dummy_block_for_bio_bh_flush.is_iodone = 1;
ds->dummy_block_for_bio_bh_flush.dev_state = ds;
}
static struct btrfsic_dev_state *btrfsic_dev_state_alloc(void)
{
struct btrfsic_dev_state *ds;
ds = kzalloc(sizeof(*ds), GFP_NOFS);
if (NULL != ds)
btrfsic_dev_state_init(ds);
return ds;
}
static void btrfsic_dev_state_free(struct btrfsic_dev_state *ds)
{
BUG_ON(!(NULL == ds ||
BTRFSIC_DEV2STATE_MAGIC_NUMBER == ds->magic_num));
kfree(ds);
}
static void btrfsic_block_hashtable_init(struct btrfsic_block_hashtable *h)
{
int i;
for (i = 0; i < BTRFSIC_BLOCK_HASHTABLE_SIZE; i++)
INIT_LIST_HEAD(h->table + i);
}
static void btrfsic_block_hashtable_add(struct btrfsic_block *b,
struct btrfsic_block_hashtable *h)
{
const unsigned int hashval =
(((unsigned int)(b->dev_bytenr >> 16)) ^
((unsigned int)((uintptr_t)b->dev_state->bdev))) &
(BTRFSIC_BLOCK_HASHTABLE_SIZE - 1);
list_add(&b->collision_resolving_node, h->table + hashval);
}
static void btrfsic_block_hashtable_remove(struct btrfsic_block *b)
{
list_del(&b->collision_resolving_node);
}
static struct btrfsic_block *btrfsic_block_hashtable_lookup(
struct block_device *bdev,
u64 dev_bytenr,
struct btrfsic_block_hashtable *h)
{
const unsigned int hashval =
(((unsigned int)(dev_bytenr >> 16)) ^
((unsigned int)((uintptr_t)bdev))) &
(BTRFSIC_BLOCK_HASHTABLE_SIZE - 1);
struct list_head *elem;
list_for_each(elem, h->table + hashval) {
struct btrfsic_block *const b =
list_entry(elem, struct btrfsic_block,
collision_resolving_node);
if (b->dev_state->bdev == bdev && b->dev_bytenr == dev_bytenr)
return b;
}
return NULL;
}
static void btrfsic_block_link_hashtable_init(
struct btrfsic_block_link_hashtable *h)
{
int i;
for (i = 0; i < BTRFSIC_BLOCK_LINK_HASHTABLE_SIZE; i++)
INIT_LIST_HEAD(h->table + i);
}
static void btrfsic_block_link_hashtable_add(
struct btrfsic_block_link *l,
struct btrfsic_block_link_hashtable *h)
{
const unsigned int hashval =
(((unsigned int)(l->block_ref_to->dev_bytenr >> 16)) ^
((unsigned int)(l->block_ref_from->dev_bytenr >> 16)) ^
((unsigned int)((uintptr_t)l->block_ref_to->dev_state->bdev)) ^
((unsigned int)((uintptr_t)l->block_ref_from->dev_state->bdev)))
& (BTRFSIC_BLOCK_LINK_HASHTABLE_SIZE - 1);
BUG_ON(NULL == l->block_ref_to);
BUG_ON(NULL == l->block_ref_from);
list_add(&l->collision_resolving_node, h->table + hashval);
}
static void btrfsic_block_link_hashtable_remove(struct btrfsic_block_link *l)
{
list_del(&l->collision_resolving_node);
}
static struct btrfsic_block_link *btrfsic_block_link_hashtable_lookup(
struct block_device *bdev_ref_to,
u64 dev_bytenr_ref_to,
struct block_device *bdev_ref_from,
u64 dev_bytenr_ref_from,
struct btrfsic_block_link_hashtable *h)
{
const unsigned int hashval =
(((unsigned int)(dev_bytenr_ref_to >> 16)) ^
((unsigned int)(dev_bytenr_ref_from >> 16)) ^
((unsigned int)((uintptr_t)bdev_ref_to)) ^
((unsigned int)((uintptr_t)bdev_ref_from))) &
(BTRFSIC_BLOCK_LINK_HASHTABLE_SIZE - 1);
struct list_head *elem;
list_for_each(elem, h->table + hashval) {
struct btrfsic_block_link *const l =
list_entry(elem, struct btrfsic_block_link,
collision_resolving_node);
BUG_ON(NULL == l->block_ref_to);
BUG_ON(NULL == l->block_ref_from);
if (l->block_ref_to->dev_state->bdev == bdev_ref_to &&
l->block_ref_to->dev_bytenr == dev_bytenr_ref_to &&
l->block_ref_from->dev_state->bdev == bdev_ref_from &&
l->block_ref_from->dev_bytenr == dev_bytenr_ref_from)
return l;
}
return NULL;
}
static void btrfsic_dev_state_hashtable_init(
struct btrfsic_dev_state_hashtable *h)
{
int i;
for (i = 0; i < BTRFSIC_DEV2STATE_HASHTABLE_SIZE; i++)
INIT_LIST_HEAD(h->table + i);
}
static void btrfsic_dev_state_hashtable_add(
struct btrfsic_dev_state *ds,
struct btrfsic_dev_state_hashtable *h)
{
const unsigned int hashval =
(((unsigned int)((uintptr_t)ds->bdev)) &
(BTRFSIC_DEV2STATE_HASHTABLE_SIZE - 1));
list_add(&ds->collision_resolving_node, h->table + hashval);
}
static void btrfsic_dev_state_hashtable_remove(struct btrfsic_dev_state *ds)
{
list_del(&ds->collision_resolving_node);
}
static struct btrfsic_dev_state *btrfsic_dev_state_hashtable_lookup(
struct block_device *bdev,
struct btrfsic_dev_state_hashtable *h)
{
const unsigned int hashval =
(((unsigned int)((uintptr_t)bdev)) &
(BTRFSIC_DEV2STATE_HASHTABLE_SIZE - 1));
struct list_head *elem;
list_for_each(elem, h->table + hashval) {
struct btrfsic_dev_state *const ds =
list_entry(elem, struct btrfsic_dev_state,
collision_resolving_node);
if (ds->bdev == bdev)
return ds;
}
return NULL;
}
static int btrfsic_process_superblock(struct btrfsic_state *state,
struct btrfs_fs_devices *fs_devices)
{
int ret = 0;
struct btrfs_super_block *selected_super;
struct list_head *dev_head = &fs_devices->devices;
struct btrfs_device *device;
struct btrfsic_dev_state *selected_dev_state = NULL;
int pass;
BUG_ON(NULL == state);
selected_super = kmalloc(sizeof(*selected_super), GFP_NOFS);
if (NULL == selected_super) {
printk(KERN_INFO "btrfsic: error, kmalloc failed!\n");
return -1;
}
list_for_each_entry(device, dev_head, dev_list) {
int i;
struct btrfsic_dev_state *dev_state;
if (!device->bdev || !device->name)
continue;
dev_state = btrfsic_dev_state_lookup(device->bdev);
BUG_ON(NULL == dev_state);
for (i = 0; i < BTRFS_SUPER_MIRROR_MAX; i++) {
ret = btrfsic_process_superblock_dev_mirror(
state, dev_state, device, i,
&selected_dev_state, selected_super);
if (0 != ret && 0 == i) {
kfree(selected_super);
return ret;
}
}
}
if (NULL == state->latest_superblock) {
printk(KERN_INFO "btrfsic: no superblock found!\n");
kfree(selected_super);
return -1;
}
state->csum_size = btrfs_super_csum_size(selected_super);
for (pass = 0; pass < 3; pass++) {
int num_copies;
int mirror_num;
u64 next_bytenr;
switch (pass) {
case 0:
next_bytenr = btrfs_super_root(selected_super);
if (state->print_mask &
BTRFSIC_PRINT_MASK_ROOT_CHUNK_LOG_TREE_LOCATION)
printk(KERN_INFO "root@%llu\n",
(unsigned long long)next_bytenr);
break;
case 1:
next_bytenr = btrfs_super_chunk_root(selected_super);
if (state->print_mask &
BTRFSIC_PRINT_MASK_ROOT_CHUNK_LOG_TREE_LOCATION)
printk(KERN_INFO "chunk@%llu\n",
(unsigned long long)next_bytenr);
break;
case 2:
next_bytenr = btrfs_super_log_root(selected_super);
if (0 == next_bytenr)
continue;
if (state->print_mask &
BTRFSIC_PRINT_MASK_ROOT_CHUNK_LOG_TREE_LOCATION)
printk(KERN_INFO "log@%llu\n",
(unsigned long long)next_bytenr);
break;
}
num_copies =
btrfs_num_copies(&state->root->fs_info->mapping_tree,
next_bytenr, PAGE_SIZE);
if (state->print_mask & BTRFSIC_PRINT_MASK_NUM_COPIES)
printk(KERN_INFO "num_copies(log_bytenr=%llu) = %d\n",
(unsigned long long)next_bytenr, num_copies);
for (mirror_num = 1; mirror_num <= num_copies; mirror_num++) {
struct btrfsic_block *next_block;
struct btrfsic_block_data_ctx tmp_next_block_ctx;
struct btrfsic_block_link *l;
struct btrfs_header *hdr;
ret = btrfsic_map_block(state, next_bytenr, PAGE_SIZE,
&tmp_next_block_ctx,
mirror_num);
if (ret) {
printk(KERN_INFO "btrfsic:"
" btrfsic_map_block(root @%llu,"
" mirror %d) failed!\n",
(unsigned long long)next_bytenr,
mirror_num);
kfree(selected_super);
return -1;
}
next_block = btrfsic_block_hashtable_lookup(
tmp_next_block_ctx.dev->bdev,
tmp_next_block_ctx.dev_bytenr,
&state->block_hashtable);
BUG_ON(NULL == next_block);
l = btrfsic_block_link_hashtable_lookup(
tmp_next_block_ctx.dev->bdev,
tmp_next_block_ctx.dev_bytenr,
state->latest_superblock->dev_state->
bdev,
state->latest_superblock->dev_bytenr,
&state->block_link_hashtable);
BUG_ON(NULL == l);
ret = btrfsic_read_block(state, &tmp_next_block_ctx);
if (ret < (int)BTRFSIC_BLOCK_SIZE) {
printk(KERN_INFO
"btrfsic: read @logical %llu failed!\n",
(unsigned long long)
tmp_next_block_ctx.start);
btrfsic_release_block_ctx(&tmp_next_block_ctx);
kfree(selected_super);
return -1;
}
hdr = (struct btrfs_header *)tmp_next_block_ctx.data;
ret = btrfsic_process_metablock(state,
next_block,
&tmp_next_block_ctx,
hdr,
BTRFS_MAX_LEVEL + 3, 1);
btrfsic_release_block_ctx(&tmp_next_block_ctx);
}
}
kfree(selected_super);
return ret;
}
static int btrfsic_process_superblock_dev_mirror(
struct btrfsic_state *state,
struct btrfsic_dev_state *dev_state,
struct btrfs_device *device,
int superblock_mirror_num,
struct btrfsic_dev_state **selected_dev_state,
struct btrfs_super_block *selected_super)
{
struct btrfs_super_block *super_tmp;
u64 dev_bytenr;
struct buffer_head *bh;
struct btrfsic_block *superblock_tmp;
int pass;
struct block_device *const superblock_bdev = device->bdev;
dev_bytenr = btrfs_sb_offset(superblock_mirror_num);
bh = __bread(superblock_bdev, dev_bytenr / 4096, 4096);
if (NULL == bh)
return -1;
super_tmp = (struct btrfs_super_block *)
(bh->b_data + (dev_bytenr & 4095));
if (btrfs_super_bytenr(super_tmp) != dev_bytenr ||
strncmp((char *)(&(super_tmp->magic)), BTRFS_MAGIC,
sizeof(super_tmp->magic)) ||
memcmp(device->uuid, super_tmp->dev_item.uuid, BTRFS_UUID_SIZE)) {
brelse(bh);
return 0;
}
superblock_tmp =
btrfsic_block_hashtable_lookup(superblock_bdev,
dev_bytenr,
&state->block_hashtable);
if (NULL == superblock_tmp) {
superblock_tmp = btrfsic_block_alloc();
if (NULL == superblock_tmp) {
printk(KERN_INFO "btrfsic: error, kmalloc failed!\n");
brelse(bh);
return -1;
}
superblock_tmp->dev_bytenr = dev_bytenr;
superblock_tmp->dev_state = dev_state;
superblock_tmp->logical_bytenr = dev_bytenr;
superblock_tmp->generation = btrfs_super_generation(super_tmp);
superblock_tmp->is_metadata = 1;
superblock_tmp->is_superblock = 1;
superblock_tmp->is_iodone = 1;
superblock_tmp->never_written = 0;
superblock_tmp->mirror_num = 1 + superblock_mirror_num;
if (state->print_mask & BTRFSIC_PRINT_MASK_SUPERBLOCK_WRITE)
printk(KERN_INFO "New initial S-block (bdev %p, %s)"
" @%llu (%s/%llu/%d)\n",
superblock_bdev, device->name,
(unsigned long long)dev_bytenr,
dev_state->name,
(unsigned long long)dev_bytenr,
superblock_mirror_num);
list_add(&superblock_tmp->all_blocks_node,
&state->all_blocks_list);
btrfsic_block_hashtable_add(superblock_tmp,
&state->block_hashtable);
}
if (btrfs_super_generation(super_tmp) >
state->max_superblock_generation ||
0 == state->max_superblock_generation) {
memcpy(selected_super, super_tmp, sizeof(*selected_super));
*selected_dev_state = dev_state;
state->max_superblock_generation =
btrfs_super_generation(super_tmp);
state->latest_superblock = superblock_tmp;
}
for (pass = 0; pass < 3; pass++) {
u64 next_bytenr;
int num_copies;
int mirror_num;
const char *additional_string = NULL;
struct btrfs_disk_key tmp_disk_key;
tmp_disk_key.type = BTRFS_ROOT_ITEM_KEY;
tmp_disk_key.offset = 0;
switch (pass) {
case 0:
tmp_disk_key.objectid =
cpu_to_le64(BTRFS_ROOT_TREE_OBJECTID);
additional_string = "initial root ";
next_bytenr = btrfs_super_root(super_tmp);
break;
case 1:
tmp_disk_key.objectid =
cpu_to_le64(BTRFS_CHUNK_TREE_OBJECTID);
additional_string = "initial chunk ";
next_bytenr = btrfs_super_chunk_root(super_tmp);
break;
case 2:
tmp_disk_key.objectid =
cpu_to_le64(BTRFS_TREE_LOG_OBJECTID);
additional_string = "initial log ";
next_bytenr = btrfs_super_log_root(super_tmp);
if (0 == next_bytenr)
continue;
break;
}
num_copies =
btrfs_num_copies(&state->root->fs_info->mapping_tree,
next_bytenr, PAGE_SIZE);
if (state->print_mask & BTRFSIC_PRINT_MASK_NUM_COPIES)
printk(KERN_INFO "num_copies(log_bytenr=%llu) = %d\n",
(unsigned long long)next_bytenr, num_copies);
for (mirror_num = 1; mirror_num <= num_copies; mirror_num++) {
struct btrfsic_block *next_block;
struct btrfsic_block_data_ctx tmp_next_block_ctx;
struct btrfsic_block_link *l;
if (btrfsic_map_block(state, next_bytenr, PAGE_SIZE,
&tmp_next_block_ctx,
mirror_num)) {
printk(KERN_INFO "btrfsic: btrfsic_map_block("
"bytenr @%llu, mirror %d) failed!\n",
(unsigned long long)next_bytenr,
mirror_num);
brelse(bh);
return -1;
}
next_block = btrfsic_block_lookup_or_add(
state, &tmp_next_block_ctx,
additional_string, 1, 1, 0,
mirror_num, NULL);
if (NULL == next_block) {
btrfsic_release_block_ctx(&tmp_next_block_ctx);
brelse(bh);
return -1;
}
next_block->disk_key = tmp_disk_key;
next_block->generation = BTRFSIC_GENERATION_UNKNOWN;
l = btrfsic_block_link_lookup_or_add(
state, &tmp_next_block_ctx,
next_block, superblock_tmp,
BTRFSIC_GENERATION_UNKNOWN);
btrfsic_release_block_ctx(&tmp_next_block_ctx);
if (NULL == l) {
brelse(bh);
return -1;
}
}
}
if (state->print_mask & BTRFSIC_PRINT_MASK_INITIAL_ALL_TREES)
btrfsic_dump_tree_sub(state, superblock_tmp, 0);
brelse(bh);
return 0;
}
static struct btrfsic_stack_frame *btrfsic_stack_frame_alloc(void)
{
struct btrfsic_stack_frame *sf;
sf = kzalloc(sizeof(*sf), GFP_NOFS);
if (NULL == sf)
printk(KERN_INFO "btrfsic: alloc memory failed!\n");
else
sf->magic = BTRFSIC_BLOCK_STACK_FRAME_MAGIC_NUMBER;
return sf;
}
static void btrfsic_stack_frame_free(struct btrfsic_stack_frame *sf)
{
BUG_ON(!(NULL == sf ||
BTRFSIC_BLOCK_STACK_FRAME_MAGIC_NUMBER == sf->magic));
kfree(sf);
}
static int btrfsic_process_metablock(
struct btrfsic_state *state,
struct btrfsic_block *const first_block,
struct btrfsic_block_data_ctx *const first_block_ctx,
struct btrfs_header *const first_hdr,
int first_limit_nesting, int force_iodone_flag)
{
struct btrfsic_stack_frame initial_stack_frame = { 0 };
struct btrfsic_stack_frame *sf;
struct btrfsic_stack_frame *next_stack;
sf = &initial_stack_frame;
sf->error = 0;
sf->i = -1;
sf->limit_nesting = first_limit_nesting;
sf->block = first_block;
sf->block_ctx = first_block_ctx;
sf->next_block = NULL;
sf->hdr = first_hdr;
sf->prev = NULL;
continue_with_new_stack_frame:
sf->block->generation = le64_to_cpu(sf->hdr->generation);
if (0 == sf->hdr->level) {
struct btrfs_leaf *const leafhdr =
(struct btrfs_leaf *)sf->hdr;
if (-1 == sf->i) {
sf->nr = le32_to_cpu(leafhdr->header.nritems);
if (state->print_mask & BTRFSIC_PRINT_MASK_VERBOSE)
printk(KERN_INFO
"leaf %llu items %d generation %llu"
" owner %llu\n",
(unsigned long long)
sf->block_ctx->start,
sf->nr,
(unsigned long long)
le64_to_cpu(leafhdr->header.generation),
(unsigned long long)
le64_to_cpu(leafhdr->header.owner));
}
continue_with_current_leaf_stack_frame:
if (0 == sf->num_copies || sf->mirror_num > sf->num_copies) {
sf->i++;
sf->num_copies = 0;
}
if (sf->i < sf->nr) {
struct btrfs_item *disk_item = leafhdr->items + sf->i;
struct btrfs_disk_key *disk_key = &disk_item->key;
u8 type;
const u32 item_offset = le32_to_cpu(disk_item->offset);
type = disk_key->type;
if (BTRFS_ROOT_ITEM_KEY == type) {
const struct btrfs_root_item *const root_item =
(struct btrfs_root_item *)
(sf->block_ctx->data +
offsetof(struct btrfs_leaf, items) +
item_offset);
const u64 next_bytenr =
le64_to_cpu(root_item->bytenr);
sf->error =
btrfsic_create_link_to_next_block(
state,
sf->block,
sf->block_ctx,
next_bytenr,
sf->limit_nesting,
&sf->next_block_ctx,
&sf->next_block,
force_iodone_flag,
&sf->num_copies,
&sf->mirror_num,
disk_key,
le64_to_cpu(root_item->
generation));
if (sf->error)
goto one_stack_frame_backwards;
if (NULL != sf->next_block) {
struct btrfs_header *const next_hdr =
(struct btrfs_header *)
sf->next_block_ctx.data;
next_stack =
btrfsic_stack_frame_alloc();
if (NULL == next_stack) {
btrfsic_release_block_ctx(
&sf->
next_block_ctx);
goto one_stack_frame_backwards;
}
next_stack->i = -1;
next_stack->block = sf->next_block;
next_stack->block_ctx =
&sf->next_block_ctx;
next_stack->next_block = NULL;
next_stack->hdr = next_hdr;
next_stack->limit_nesting =
sf->limit_nesting - 1;
next_stack->prev = sf;
sf = next_stack;
goto continue_with_new_stack_frame;
}
} else if (BTRFS_EXTENT_DATA_KEY == type &&
state->include_extent_data) {
sf->error = btrfsic_handle_extent_data(
state,
sf->block,
sf->block_ctx,
item_offset,
force_iodone_flag);
if (sf->error)
goto one_stack_frame_backwards;
}
goto continue_with_current_leaf_stack_frame;
}
} else {
struct btrfs_node *const nodehdr = (struct btrfs_node *)sf->hdr;
if (-1 == sf->i) {
sf->nr = le32_to_cpu(nodehdr->header.nritems);
if (state->print_mask & BTRFSIC_PRINT_MASK_VERBOSE)
printk(KERN_INFO "node %llu level %d items %d"
" generation %llu owner %llu\n",
(unsigned long long)
sf->block_ctx->start,
nodehdr->header.level, sf->nr,
(unsigned long long)
le64_to_cpu(nodehdr->header.generation),
(unsigned long long)
le64_to_cpu(nodehdr->header.owner));
}
continue_with_current_node_stack_frame:
if (0 == sf->num_copies || sf->mirror_num > sf->num_copies) {
sf->i++;
sf->num_copies = 0;
}
if (sf->i < sf->nr) {
struct btrfs_key_ptr *disk_key_ptr =
nodehdr->ptrs + sf->i;
const u64 next_bytenr =
le64_to_cpu(disk_key_ptr->blockptr);
sf->error = btrfsic_create_link_to_next_block(
state,
sf->block,
sf->block_ctx,
next_bytenr,
sf->limit_nesting,
&sf->next_block_ctx,
&sf->next_block,
force_iodone_flag,
&sf->num_copies,
&sf->mirror_num,
&disk_key_ptr->key,
le64_to_cpu(disk_key_ptr->generation));
if (sf->error)
goto one_stack_frame_backwards;
if (NULL != sf->next_block) {
struct btrfs_header *const next_hdr =
(struct btrfs_header *)
sf->next_block_ctx.data;
next_stack = btrfsic_stack_frame_alloc();
if (NULL == next_stack)
goto one_stack_frame_backwards;
next_stack->i = -1;
next_stack->block = sf->next_block;
next_stack->block_ctx = &sf->next_block_ctx;
next_stack->next_block = NULL;
next_stack->hdr = next_hdr;
next_stack->limit_nesting =
sf->limit_nesting - 1;
next_stack->prev = sf;
sf = next_stack;
goto continue_with_new_stack_frame;
}
goto continue_with_current_node_stack_frame;
}
}
one_stack_frame_backwards:
if (NULL != sf->prev) {
struct btrfsic_stack_frame *const prev = sf->prev;
btrfsic_release_block_ctx(sf->block_ctx);
if (sf->error) {
prev->error = sf->error;
btrfsic_stack_frame_free(sf);
sf = prev;
goto one_stack_frame_backwards;
}
btrfsic_stack_frame_free(sf);
sf = prev;
goto continue_with_new_stack_frame;
} else {
BUG_ON(&initial_stack_frame != sf);
}
return sf->error;
}
static int btrfsic_create_link_to_next_block(
struct btrfsic_state *state,
struct btrfsic_block *block,
struct btrfsic_block_data_ctx *block_ctx,
u64 next_bytenr,
int limit_nesting,
struct btrfsic_block_data_ctx *next_block_ctx,
struct btrfsic_block **next_blockp,
int force_iodone_flag,
int *num_copiesp, int *mirror_nump,
struct btrfs_disk_key *disk_key,
u64 parent_generation)
{
struct btrfsic_block *next_block = NULL;
int ret;
struct btrfsic_block_link *l;
int did_alloc_block_link;
int block_was_created;
*next_blockp = NULL;
if (0 == *num_copiesp) {
*num_copiesp =
btrfs_num_copies(&state->root->fs_info->mapping_tree,
next_bytenr, PAGE_SIZE);
if (state->print_mask & BTRFSIC_PRINT_MASK_NUM_COPIES)
printk(KERN_INFO "num_copies(log_bytenr=%llu) = %d\n",
(unsigned long long)next_bytenr, *num_copiesp);
*mirror_nump = 1;
}
if (*mirror_nump > *num_copiesp)
return 0;
if (state->print_mask & BTRFSIC_PRINT_MASK_VERBOSE)
printk(KERN_INFO
"btrfsic_create_link_to_next_block(mirror_num=%d)\n",
*mirror_nump);
ret = btrfsic_map_block(state, next_bytenr,
BTRFSIC_BLOCK_SIZE,
next_block_ctx, *mirror_nump);
if (ret) {
printk(KERN_INFO
"btrfsic: btrfsic_map_block(@%llu, mirror=%d) failed!\n",
(unsigned long long)next_bytenr, *mirror_nump);
btrfsic_release_block_ctx(next_block_ctx);
*next_blockp = NULL;
return -1;
}
next_block = btrfsic_block_lookup_or_add(state,
next_block_ctx, "referenced ",
1, force_iodone_flag,
!force_iodone_flag,
*mirror_nump,
&block_was_created);
if (NULL == next_block) {
btrfsic_release_block_ctx(next_block_ctx);
*next_blockp = NULL;
return -1;
}
if (block_was_created) {
l = NULL;
next_block->generation = BTRFSIC_GENERATION_UNKNOWN;
} else {
if (next_block->logical_bytenr != next_bytenr &&
!(!next_block->is_metadata &&
0 == next_block->logical_bytenr)) {
printk(KERN_INFO
"Referenced block @%llu (%s/%llu/%d)"
" found in hash table, %c,"
" bytenr mismatch (!= stored %llu).\n",
(unsigned long long)next_bytenr,
next_block_ctx->dev->name,
(unsigned long long)next_block_ctx->dev_bytenr,
*mirror_nump,
btrfsic_get_block_type(state, next_block),
(unsigned long long)next_block->logical_bytenr);
} else if (state->print_mask & BTRFSIC_PRINT_MASK_VERBOSE)
printk(KERN_INFO
"Referenced block @%llu (%s/%llu/%d)"
" found in hash table, %c.\n",
(unsigned long long)next_bytenr,
next_block_ctx->dev->name,
(unsigned long long)next_block_ctx->dev_bytenr,
*mirror_nump,
btrfsic_get_block_type(state, next_block));
next_block->logical_bytenr = next_bytenr;
next_block->mirror_num = *mirror_nump;
l = btrfsic_block_link_hashtable_lookup(
next_block_ctx->dev->bdev,
next_block_ctx->dev_bytenr,
block_ctx->dev->bdev,
block_ctx->dev_bytenr,
&state->block_link_hashtable);
}
next_block->disk_key = *disk_key;
if (NULL == l) {
l = btrfsic_block_link_alloc();
if (NULL == l) {
printk(KERN_INFO "btrfsic: error, kmalloc failed!\n");
btrfsic_release_block_ctx(next_block_ctx);
*next_blockp = NULL;
return -1;
}
did_alloc_block_link = 1;
l->block_ref_to = next_block;
l->block_ref_from = block;
l->ref_cnt = 1;
l->parent_generation = parent_generation;
if (state->print_mask & BTRFSIC_PRINT_MASK_VERBOSE)
btrfsic_print_add_link(state, l);
list_add(&l->node_ref_to, &block->ref_to_list);
list_add(&l->node_ref_from, &next_block->ref_from_list);
btrfsic_block_link_hashtable_add(l,
&state->block_link_hashtable);
} else {
did_alloc_block_link = 0;
if (0 == limit_nesting) {
l->ref_cnt++;
l->parent_generation = parent_generation;
if (state->print_mask & BTRFSIC_PRINT_MASK_VERBOSE)
btrfsic_print_add_link(state, l);
}
}
if (limit_nesting > 0 && did_alloc_block_link) {
ret = btrfsic_read_block(state, next_block_ctx);
if (ret < (int)BTRFSIC_BLOCK_SIZE) {
printk(KERN_INFO
"btrfsic: read block @logical %llu failed!\n",
(unsigned long long)next_bytenr);
btrfsic_release_block_ctx(next_block_ctx);
*next_blockp = NULL;
return -1;
}
*next_blockp = next_block;
} else {
*next_blockp = NULL;
}
(*mirror_nump)++;
return 0;
}
static int btrfsic_handle_extent_data(
struct btrfsic_state *state,
struct btrfsic_block *block,
struct btrfsic_block_data_ctx *block_ctx,
u32 item_offset, int force_iodone_flag)
{
int ret;
struct btrfs_file_extent_item *file_extent_item =
(struct btrfs_file_extent_item *)(block_ctx->data +
offsetof(struct btrfs_leaf,
items) + item_offset);
u64 next_bytenr =
le64_to_cpu(file_extent_item->disk_bytenr) +
le64_to_cpu(file_extent_item->offset);
u64 num_bytes = le64_to_cpu(file_extent_item->num_bytes);
u64 generation = le64_to_cpu(file_extent_item->generation);
struct btrfsic_block_link *l;
if (state->print_mask & BTRFSIC_PRINT_MASK_VERY_VERBOSE)
printk(KERN_INFO "extent_data: type %u, disk_bytenr = %llu,"
" offset = %llu, num_bytes = %llu\n",
file_extent_item->type,
(unsigned long long)
le64_to_cpu(file_extent_item->disk_bytenr),
(unsigned long long)
le64_to_cpu(file_extent_item->offset),
(unsigned long long)
le64_to_cpu(file_extent_item->num_bytes));
if (BTRFS_FILE_EXTENT_REG != file_extent_item->type ||
((u64)0) == le64_to_cpu(file_extent_item->disk_bytenr))
return 0;
while (num_bytes > 0) {
u32 chunk_len;
int num_copies;
int mirror_num;
if (num_bytes > BTRFSIC_BLOCK_SIZE)
chunk_len = BTRFSIC_BLOCK_SIZE;
else
chunk_len = num_bytes;
num_copies =
btrfs_num_copies(&state->root->fs_info->mapping_tree,
next_bytenr, PAGE_SIZE);
if (state->print_mask & BTRFSIC_PRINT_MASK_NUM_COPIES)
printk(KERN_INFO "num_copies(log_bytenr=%llu) = %d\n",
(unsigned long long)next_bytenr, num_copies);
for (mirror_num = 1; mirror_num <= num_copies; mirror_num++) {
struct btrfsic_block_data_ctx next_block_ctx;
struct btrfsic_block *next_block;
int block_was_created;
if (state->print_mask & BTRFSIC_PRINT_MASK_VERBOSE)
printk(KERN_INFO "btrfsic_handle_extent_data("
"mirror_num=%d)\n", mirror_num);
if (state->print_mask & BTRFSIC_PRINT_MASK_VERY_VERBOSE)
printk(KERN_INFO
"\tdisk_bytenr = %llu, num_bytes %u\n",
(unsigned long long)next_bytenr,
chunk_len);
ret = btrfsic_map_block(state, next_bytenr,
chunk_len, &next_block_ctx,
mirror_num);
if (ret) {
printk(KERN_INFO
"btrfsic: btrfsic_map_block(@%llu,"
" mirror=%d) failed!\n",
(unsigned long long)next_bytenr,
mirror_num);
return -1;
}
next_block = btrfsic_block_lookup_or_add(
state,
&next_block_ctx,
"referenced ",
0,
force_iodone_flag,
!force_iodone_flag,
mirror_num,
&block_was_created);
if (NULL == next_block) {
printk(KERN_INFO
"btrfsic: error, kmalloc failed!\n");
btrfsic_release_block_ctx(&next_block_ctx);
return -1;
}
if (!block_was_created) {
if (next_block->logical_bytenr != next_bytenr &&
!(!next_block->is_metadata &&
0 == next_block->logical_bytenr)) {
printk(KERN_INFO
"Referenced block"
" @%llu (%s/%llu/%d)"
" found in hash table, D,"
" bytenr mismatch"
" (!= stored %llu).\n",
(unsigned long long)next_bytenr,
next_block_ctx.dev->name,
(unsigned long long)
next_block_ctx.dev_bytenr,
mirror_num,
(unsigned long long)
next_block->logical_bytenr);
}
next_block->logical_bytenr = next_bytenr;
next_block->mirror_num = mirror_num;
}
l = btrfsic_block_link_lookup_or_add(state,
&next_block_ctx,
next_block, block,
generation);
btrfsic_release_block_ctx(&next_block_ctx);
if (NULL == l)
return -1;
}
next_bytenr += chunk_len;
num_bytes -= chunk_len;
}
return 0;
}
static int btrfsic_map_block(struct btrfsic_state *state, u64 bytenr, u32 len,
struct btrfsic_block_data_ctx *block_ctx_out,
int mirror_num)
{
int ret;
u64 length;
struct btrfs_bio *multi = NULL;
struct btrfs_device *device;
length = len;
ret = btrfs_map_block(&state->root->fs_info->mapping_tree, READ,
bytenr, &length, &multi, mirror_num);
device = multi->stripes[0].dev;
block_ctx_out->dev = btrfsic_dev_state_lookup(device->bdev);
block_ctx_out->dev_bytenr = multi->stripes[0].physical;
block_ctx_out->start = bytenr;
block_ctx_out->len = len;
block_ctx_out->data = NULL;
block_ctx_out->bh = NULL;
if (0 == ret)
kfree(multi);
if (NULL == block_ctx_out->dev) {
ret = -ENXIO;
printk(KERN_INFO "btrfsic: error, cannot lookup dev (#1)!\n");
}
return ret;
}
static int btrfsic_map_superblock(struct btrfsic_state *state, u64 bytenr,
u32 len, struct block_device *bdev,
struct btrfsic_block_data_ctx *block_ctx_out)
{
block_ctx_out->dev = btrfsic_dev_state_lookup(bdev);
block_ctx_out->dev_bytenr = bytenr;
block_ctx_out->start = bytenr;
block_ctx_out->len = len;
block_ctx_out->data = NULL;
block_ctx_out->bh = NULL;
if (NULL != block_ctx_out->dev) {
return 0;
} else {
printk(KERN_INFO "btrfsic: error, cannot lookup dev (#2)!\n");
return -ENXIO;
}
}
static void btrfsic_release_block_ctx(struct btrfsic_block_data_ctx *block_ctx)
{
if (NULL != block_ctx->bh) {
brelse(block_ctx->bh);
block_ctx->bh = NULL;
}
}
static int btrfsic_read_block(struct btrfsic_state *state,
struct btrfsic_block_data_ctx *block_ctx)
{
block_ctx->bh = NULL;
if (block_ctx->dev_bytenr & 4095) {
printk(KERN_INFO
"btrfsic: read_block() with unaligned bytenr %llu\n",
(unsigned long long)block_ctx->dev_bytenr);
return -1;
}
if (block_ctx->len > 4096) {
printk(KERN_INFO
"btrfsic: read_block() with too huge size %d\n",
block_ctx->len);
return -1;
}
block_ctx->bh = __bread(block_ctx->dev->bdev,
block_ctx->dev_bytenr >> 12, 4096);
if (NULL == block_ctx->bh)
return -1;
block_ctx->data = block_ctx->bh->b_data;
return block_ctx->len;
}
static void btrfsic_dump_database(struct btrfsic_state *state)
{
struct list_head *elem_all;
BUG_ON(NULL == state);
printk(KERN_INFO "all_blocks_list:\n");
list_for_each(elem_all, &state->all_blocks_list) {
const struct btrfsic_block *const b_all =
list_entry(elem_all, struct btrfsic_block,
all_blocks_node);
struct list_head *elem_ref_to;
struct list_head *elem_ref_from;
printk(KERN_INFO "%c-block @%llu (%s/%llu/%d)\n",
btrfsic_get_block_type(state, b_all),
(unsigned long long)b_all->logical_bytenr,
b_all->dev_state->name,
(unsigned long long)b_all->dev_bytenr,
b_all->mirror_num);
list_for_each(elem_ref_to, &b_all->ref_to_list) {
const struct btrfsic_block_link *const l =
list_entry(elem_ref_to,
struct btrfsic_block_link,
node_ref_to);
printk(KERN_INFO " %c @%llu (%s/%llu/%d)"
" refers %u* to"
" %c @%llu (%s/%llu/%d)\n",
btrfsic_get_block_type(state, b_all),
(unsigned long long)b_all->logical_bytenr,
b_all->dev_state->name,
(unsigned long long)b_all->dev_bytenr,
b_all->mirror_num,
l->ref_cnt,
btrfsic_get_block_type(state, l->block_ref_to),
(unsigned long long)
l->block_ref_to->logical_bytenr,
l->block_ref_to->dev_state->name,
(unsigned long long)l->block_ref_to->dev_bytenr,
l->block_ref_to->mirror_num);
}
list_for_each(elem_ref_from, &b_all->ref_from_list) {
const struct btrfsic_block_link *const l =
list_entry(elem_ref_from,
struct btrfsic_block_link,
node_ref_from);
printk(KERN_INFO " %c @%llu (%s/%llu/%d)"
" is ref %u* from"
" %c @%llu (%s/%llu/%d)\n",
btrfsic_get_block_type(state, b_all),
(unsigned long long)b_all->logical_bytenr,
b_all->dev_state->name,
(unsigned long long)b_all->dev_bytenr,
b_all->mirror_num,
l->ref_cnt,
btrfsic_get_block_type(state, l->block_ref_from),
(unsigned long long)
l->block_ref_from->logical_bytenr,
l->block_ref_from->dev_state->name,
(unsigned long long)
l->block_ref_from->dev_bytenr,
l->block_ref_from->mirror_num);
}
printk(KERN_INFO "\n");
}
}
static int btrfsic_test_for_metadata(struct btrfsic_state *state,
const u8 *data, unsigned int size)
{
struct btrfs_header *h;
u8 csum[BTRFS_CSUM_SIZE];
u32 crc = ~(u32)0;
int fail = 0;
int crc_fail = 0;
h = (struct btrfs_header *)data;
if (memcmp(h->fsid, state->root->fs_info->fsid, BTRFS_UUID_SIZE))
fail++;
crc = crc32c(crc, data + BTRFS_CSUM_SIZE, PAGE_SIZE - BTRFS_CSUM_SIZE);
btrfs_csum_final(crc, csum);
if (memcmp(csum, h->csum, state->csum_size))
crc_fail++;
return fail || crc_fail;
}
static void btrfsic_process_written_block(struct btrfsic_dev_state *dev_state,
u64 dev_bytenr,
u8 *mapped_data, unsigned int len,
struct bio *bio,
int *bio_is_patched,
struct buffer_head *bh,
int submit_bio_bh_rw)
{
int is_metadata;
struct btrfsic_block *block;
struct btrfsic_block_data_ctx block_ctx;
int ret;
struct btrfsic_state *state = dev_state->state;
struct block_device *bdev = dev_state->bdev;
WARN_ON(len > PAGE_SIZE);
is_metadata = (0 == btrfsic_test_for_metadata(state, mapped_data, len));
if (NULL != bio_is_patched)
*bio_is_patched = 0;
block = btrfsic_block_hashtable_lookup(bdev, dev_bytenr,
&state->block_hashtable);
if (NULL != block) {
u64 bytenr = 0;
struct list_head *elem_ref_to;
struct list_head *tmp_ref_to;
if (block->is_superblock) {
bytenr = le64_to_cpu(((struct btrfs_super_block *)
mapped_data)->bytenr);
is_metadata = 1;
if (state->print_mask &
BTRFSIC_PRINT_MASK_TREE_BEFORE_SB_WRITE) {
printk(KERN_INFO
"[before new superblock is written]:\n");
btrfsic_dump_tree_sub(state, block, 0);
}
}
if (is_metadata) {
if (!block->is_superblock) {
bytenr = le64_to_cpu(((struct btrfs_header *)
mapped_data)->bytenr);
btrfsic_cmp_log_and_dev_bytenr(state, bytenr,
dev_state,
dev_bytenr,
mapped_data);
}
if (block->logical_bytenr != bytenr) {
printk(KERN_INFO
"Written block @%llu (%s/%llu/%d)"
" found in hash table, %c,"
" bytenr mismatch"
" (!= stored %llu).\n",
(unsigned long long)bytenr,
dev_state->name,
(unsigned long long)dev_bytenr,
block->mirror_num,
btrfsic_get_block_type(state, block),
(unsigned long long)
block->logical_bytenr);
block->logical_bytenr = bytenr;
} else if (state->print_mask &
BTRFSIC_PRINT_MASK_VERBOSE)
printk(KERN_INFO
"Written block @%llu (%s/%llu/%d)"
" found in hash table, %c.\n",
(unsigned long long)bytenr,
dev_state->name,
(unsigned long long)dev_bytenr,
block->mirror_num,
btrfsic_get_block_type(state, block));
} else {
bytenr = block->logical_bytenr;
if (state->print_mask & BTRFSIC_PRINT_MASK_VERBOSE)
printk(KERN_INFO
"Written block @%llu (%s/%llu/%d)"
" found in hash table, %c.\n",
(unsigned long long)bytenr,
dev_state->name,
(unsigned long long)dev_bytenr,
block->mirror_num,
btrfsic_get_block_type(state, block));
}
if (state->print_mask & BTRFSIC_PRINT_MASK_VERBOSE)
printk(KERN_INFO
"ref_to_list: %cE, ref_from_list: %cE\n",
list_empty(&block->ref_to_list) ? ' ' : '!',
list_empty(&block->ref_from_list) ? ' ' : '!');
if (btrfsic_is_block_ref_by_superblock(state, block, 0)) {
printk(KERN_INFO "btrfs: attempt to overwrite %c-block"
" @%llu (%s/%llu/%d), old(gen=%llu,"
" objectid=%llu, type=%d, offset=%llu),"
" new(gen=%llu),"
" which is referenced by most recent superblock"
" (superblockgen=%llu)!\n",
btrfsic_get_block_type(state, block),
(unsigned long long)bytenr,
dev_state->name,
(unsigned long long)dev_bytenr,
block->mirror_num,
(unsigned long long)block->generation,
(unsigned long long)
le64_to_cpu(block->disk_key.objectid),
block->disk_key.type,
(unsigned long long)
le64_to_cpu(block->disk_key.offset),
(unsigned long long)
le64_to_cpu(((struct btrfs_header *)
mapped_data)->generation),
(unsigned long long)
state->max_superblock_generation);
btrfsic_dump_tree(state);
}
if (!block->is_iodone && !block->never_written) {
printk(KERN_INFO "btrfs: attempt to overwrite %c-block"
" @%llu (%s/%llu/%d), oldgen=%llu, newgen=%llu,"
" which is not yet iodone!\n",
btrfsic_get_block_type(state, block),
(unsigned long long)bytenr,
dev_state->name,
(unsigned long long)dev_bytenr,
block->mirror_num,
(unsigned long long)block->generation,
(unsigned long long)
le64_to_cpu(((struct btrfs_header *)
mapped_data)->generation));
btrfsic_dump_tree(state);
return;
}
list_for_each_safe(elem_ref_to, tmp_ref_to,
&block->ref_to_list) {
struct btrfsic_block_link *const l =
list_entry(elem_ref_to,
struct btrfsic_block_link,
node_ref_to);
if (state->print_mask & BTRFSIC_PRINT_MASK_VERBOSE)
btrfsic_print_rem_link(state, l);
l->ref_cnt--;
if (0 == l->ref_cnt) {
list_del(&l->node_ref_to);
list_del(&l->node_ref_from);
btrfsic_block_link_hashtable_remove(l);
btrfsic_block_link_free(l);
}
}
if (block->is_superblock)
ret = btrfsic_map_superblock(state, bytenr, len,
bdev, &block_ctx);
else
ret = btrfsic_map_block(state, bytenr, len,
&block_ctx, 0);
if (ret) {
printk(KERN_INFO
"btrfsic: btrfsic_map_block(root @%llu)"
" failed!\n", (unsigned long long)bytenr);
return;
}
block_ctx.data = mapped_data;
block_ctx.dev = dev_state;
block_ctx.dev_bytenr = dev_bytenr;
if (is_metadata || state->include_extent_data) {
block->never_written = 0;
block->iodone_w_error = 0;
if (NULL != bio) {
block->is_iodone = 0;
BUG_ON(NULL == bio_is_patched);
if (!*bio_is_patched) {
block->orig_bio_bh_private =
bio->bi_private;
block->orig_bio_bh_end_io.bio =
bio->bi_end_io;
block->next_in_same_bio = NULL;
bio->bi_private = block;
bio->bi_end_io = btrfsic_bio_end_io;
*bio_is_patched = 1;
} else {
struct btrfsic_block *chained_block =
(struct btrfsic_block *)
bio->bi_private;
BUG_ON(NULL == chained_block);
block->orig_bio_bh_private =
chained_block->orig_bio_bh_private;
block->orig_bio_bh_end_io.bio =
chained_block->orig_bio_bh_end_io.
bio;
block->next_in_same_bio = chained_block;
bio->bi_private = block;
}
} else if (NULL != bh) {
block->is_iodone = 0;
block->orig_bio_bh_private = bh->b_private;
block->orig_bio_bh_end_io.bh = bh->b_end_io;
block->next_in_same_bio = NULL;
bh->b_private = block;
bh->b_end_io = btrfsic_bh_end_io;
} else {
block->is_iodone = 1;
block->orig_bio_bh_private = NULL;
block->orig_bio_bh_end_io.bio = NULL;
block->next_in_same_bio = NULL;
}
}
block->flush_gen = dev_state->last_flush_gen + 1;
block->submit_bio_bh_rw = submit_bio_bh_rw;
if (is_metadata) {
block->logical_bytenr = bytenr;
block->is_metadata = 1;
if (block->is_superblock) {
ret = btrfsic_process_written_superblock(
state,
block,
(struct btrfs_super_block *)
mapped_data);
if (state->print_mask &
BTRFSIC_PRINT_MASK_TREE_AFTER_SB_WRITE) {
printk(KERN_INFO
"[after new superblock is written]:\n");
btrfsic_dump_tree_sub(state, block, 0);
}
} else {
block->mirror_num = 0;
ret = btrfsic_process_metablock(
state,
block,
&block_ctx,
(struct btrfs_header *)
block_ctx.data,
0, 0);
}
if (ret)
printk(KERN_INFO
"btrfsic: btrfsic_process_metablock"
"(root @%llu) failed!\n",
(unsigned long long)dev_bytenr);
} else {
block->is_metadata = 0;
block->mirror_num = 0;
block->generation = BTRFSIC_GENERATION_UNKNOWN;
if (!state->include_extent_data
&& list_empty(&block->ref_from_list)) {
btrfsic_block_hashtable_remove(block);
list_del(&block->all_blocks_node);
btrfsic_block_free(block);
}
}
btrfsic_release_block_ctx(&block_ctx);
} else {
u64 bytenr;
if (!is_metadata) {
if (state->print_mask & BTRFSIC_PRINT_MASK_VERBOSE)
printk(KERN_INFO "Written block (%s/%llu/?)"
" !found in hash table, D.\n",
dev_state->name,
(unsigned long long)dev_bytenr);
if (!state->include_extent_data)
return;
bytenr = 0;
block_ctx.start = bytenr;
block_ctx.len = len;
block_ctx.bh = NULL;
} else {
bytenr = le64_to_cpu(((struct btrfs_header *)
mapped_data)->bytenr);
btrfsic_cmp_log_and_dev_bytenr(state, bytenr, dev_state,
dev_bytenr,
mapped_data);
if (state->print_mask & BTRFSIC_PRINT_MASK_VERBOSE)
printk(KERN_INFO
"Written block @%llu (%s/%llu/?)"
" !found in hash table, M.\n",
(unsigned long long)bytenr,
dev_state->name,
(unsigned long long)dev_bytenr);
ret = btrfsic_map_block(state, bytenr, len, &block_ctx,
0);
if (ret) {
printk(KERN_INFO
"btrfsic: btrfsic_map_block(root @%llu)"
" failed!\n",
(unsigned long long)dev_bytenr);
return;
}
}
block_ctx.data = mapped_data;
block_ctx.dev = dev_state;
block_ctx.dev_bytenr = dev_bytenr;
block = btrfsic_block_alloc();
if (NULL == block) {
printk(KERN_INFO "btrfsic: error, kmalloc failed!\n");
btrfsic_release_block_ctx(&block_ctx);
return;
}
block->dev_state = dev_state;
block->dev_bytenr = dev_bytenr;
block->logical_bytenr = bytenr;
block->is_metadata = is_metadata;
block->never_written = 0;
block->iodone_w_error = 0;
block->mirror_num = 0;
block->flush_gen = dev_state->last_flush_gen + 1;
block->submit_bio_bh_rw = submit_bio_bh_rw;
if (NULL != bio) {
block->is_iodone = 0;
BUG_ON(NULL == bio_is_patched);
if (!*bio_is_patched) {
block->orig_bio_bh_private = bio->bi_private;
block->orig_bio_bh_end_io.bio = bio->bi_end_io;
block->next_in_same_bio = NULL;
bio->bi_private = block;
bio->bi_end_io = btrfsic_bio_end_io;
*bio_is_patched = 1;
} else {
struct btrfsic_block *chained_block =
(struct btrfsic_block *)
bio->bi_private;
BUG_ON(NULL == chained_block);
block->orig_bio_bh_private =
chained_block->orig_bio_bh_private;
block->orig_bio_bh_end_io.bio =
chained_block->orig_bio_bh_end_io.bio;
block->next_in_same_bio = chained_block;
bio->bi_private = block;
}
} else if (NULL != bh) {
block->is_iodone = 0;
block->orig_bio_bh_private = bh->b_private;
block->orig_bio_bh_end_io.bh = bh->b_end_io;
block->next_in_same_bio = NULL;
bh->b_private = block;
bh->b_end_io = btrfsic_bh_end_io;
} else {
block->is_iodone = 1;
block->orig_bio_bh_private = NULL;
block->orig_bio_bh_end_io.bio = NULL;
block->next_in_same_bio = NULL;
}
if (state->print_mask & BTRFSIC_PRINT_MASK_VERBOSE)
printk(KERN_INFO
"New written %c-block @%llu (%s/%llu/%d)\n",
is_metadata ? 'M' : 'D',
(unsigned long long)block->logical_bytenr,
block->dev_state->name,
(unsigned long long)block->dev_bytenr,
block->mirror_num);
list_add(&block->all_blocks_node, &state->all_blocks_list);
btrfsic_block_hashtable_add(block, &state->block_hashtable);
if (is_metadata) {
ret = btrfsic_process_metablock(state, block,
&block_ctx,
(struct btrfs_header *)
block_ctx.data, 0, 0);
if (ret)
printk(KERN_INFO
"btrfsic: process_metablock(root @%llu)"
" failed!\n",
(unsigned long long)dev_bytenr);
}
btrfsic_release_block_ctx(&block_ctx);
}
}
static void btrfsic_bio_end_io(struct bio *bp, int bio_error_status)
{
struct btrfsic_block *block = (struct btrfsic_block *)bp->bi_private;
int iodone_w_error;
iodone_w_error = 0;
if (bio_error_status)
iodone_w_error = 1;
BUG_ON(NULL == block);
bp->bi_private = block->orig_bio_bh_private;
bp->bi_end_io = block->orig_bio_bh_end_io.bio;
do {
struct btrfsic_block *next_block;
struct btrfsic_dev_state *const dev_state = block->dev_state;
if ((dev_state->state->print_mask &
BTRFSIC_PRINT_MASK_END_IO_BIO_BH))
printk(KERN_INFO
"bio_end_io(err=%d) for %c @%llu (%s/%llu/%d)\n",
bio_error_status,
btrfsic_get_block_type(dev_state->state, block),
(unsigned long long)block->logical_bytenr,
dev_state->name,
(unsigned long long)block->dev_bytenr,
block->mirror_num);
next_block = block->next_in_same_bio;
block->iodone_w_error = iodone_w_error;
if (block->submit_bio_bh_rw & REQ_FLUSH) {
dev_state->last_flush_gen++;
if ((dev_state->state->print_mask &
BTRFSIC_PRINT_MASK_END_IO_BIO_BH))
printk(KERN_INFO
"bio_end_io() new %s flush_gen=%llu\n",
dev_state->name,
(unsigned long long)
dev_state->last_flush_gen);
}
if (block->submit_bio_bh_rw & REQ_FUA)
block->flush_gen = 0;
block->is_iodone = 1;
block = next_block;
} while (NULL != block);
bp->bi_end_io(bp, bio_error_status);
}
static void btrfsic_bh_end_io(struct buffer_head *bh, int uptodate)
{
struct btrfsic_block *block = (struct btrfsic_block *)bh->b_private;
int iodone_w_error = !uptodate;
struct btrfsic_dev_state *dev_state;
BUG_ON(NULL == block);
dev_state = block->dev_state;
if ((dev_state->state->print_mask & BTRFSIC_PRINT_MASK_END_IO_BIO_BH))
printk(KERN_INFO
"bh_end_io(error=%d) for %c @%llu (%s/%llu/%d)\n",
iodone_w_error,
btrfsic_get_block_type(dev_state->state, block),
(unsigned long long)block->logical_bytenr,
block->dev_state->name,
(unsigned long long)block->dev_bytenr,
block->mirror_num);
block->iodone_w_error = iodone_w_error;
if (block->submit_bio_bh_rw & REQ_FLUSH) {
dev_state->last_flush_gen++;
if ((dev_state->state->print_mask &
BTRFSIC_PRINT_MASK_END_IO_BIO_BH))
printk(KERN_INFO
"bh_end_io() new %s flush_gen=%llu\n",
dev_state->name,
(unsigned long long)dev_state->last_flush_gen);
}
if (block->submit_bio_bh_rw & REQ_FUA)
block->flush_gen = 0;
bh->b_private = block->orig_bio_bh_private;
bh->b_end_io = block->orig_bio_bh_end_io.bh;
block->is_iodone = 1;
bh->b_end_io(bh, uptodate);
}
static int btrfsic_process_written_superblock(
struct btrfsic_state *state,
struct btrfsic_block *const superblock,
struct btrfs_super_block *const super_hdr)
{
int pass;
superblock->generation = btrfs_super_generation(super_hdr);
if (!(superblock->generation > state->max_superblock_generation ||
0 == state->max_superblock_generation)) {
if (state->print_mask & BTRFSIC_PRINT_MASK_SUPERBLOCK_WRITE)
printk(KERN_INFO
"btrfsic: superblock @%llu (%s/%llu/%d)"
" with old gen %llu <= %llu\n",
(unsigned long long)superblock->logical_bytenr,
superblock->dev_state->name,
(unsigned long long)superblock->dev_bytenr,
superblock->mirror_num,
(unsigned long long)
btrfs_super_generation(super_hdr),
(unsigned long long)
state->max_superblock_generation);
} else {
if (state->print_mask & BTRFSIC_PRINT_MASK_SUPERBLOCK_WRITE)
printk(KERN_INFO
"btrfsic: got new superblock @%llu (%s/%llu/%d)"
" with new gen %llu > %llu\n",
(unsigned long long)superblock->logical_bytenr,
superblock->dev_state->name,
(unsigned long long)superblock->dev_bytenr,
superblock->mirror_num,
(unsigned long long)
btrfs_super_generation(super_hdr),
(unsigned long long)
state->max_superblock_generation);
state->max_superblock_generation =
btrfs_super_generation(super_hdr);
state->latest_superblock = superblock;
}
for (pass = 0; pass < 3; pass++) {
int ret;
u64 next_bytenr;
struct btrfsic_block *next_block;
struct btrfsic_block_data_ctx tmp_next_block_ctx;
struct btrfsic_block_link *l;
int num_copies;
int mirror_num;
const char *additional_string = NULL;
struct btrfs_disk_key tmp_disk_key;
tmp_disk_key.type = BTRFS_ROOT_ITEM_KEY;
tmp_disk_key.offset = 0;
switch (pass) {
case 0:
tmp_disk_key.objectid =
cpu_to_le64(BTRFS_ROOT_TREE_OBJECTID);
additional_string = "root ";
next_bytenr = btrfs_super_root(super_hdr);
if (state->print_mask &
BTRFSIC_PRINT_MASK_ROOT_CHUNK_LOG_TREE_LOCATION)
printk(KERN_INFO "root@%llu\n",
(unsigned long long)next_bytenr);
break;
case 1:
tmp_disk_key.objectid =
cpu_to_le64(BTRFS_CHUNK_TREE_OBJECTID);
additional_string = "chunk ";
next_bytenr = btrfs_super_chunk_root(super_hdr);
if (state->print_mask &
BTRFSIC_PRINT_MASK_ROOT_CHUNK_LOG_TREE_LOCATION)
printk(KERN_INFO "chunk@%llu\n",
(unsigned long long)next_bytenr);
break;
case 2:
tmp_disk_key.objectid =
cpu_to_le64(BTRFS_TREE_LOG_OBJECTID);
additional_string = "log ";
next_bytenr = btrfs_super_log_root(super_hdr);
if (0 == next_bytenr)
continue;
if (state->print_mask &
BTRFSIC_PRINT_MASK_ROOT_CHUNK_LOG_TREE_LOCATION)
printk(KERN_INFO "log@%llu\n",
(unsigned long long)next_bytenr);
break;
}
num_copies =
btrfs_num_copies(&state->root->fs_info->mapping_tree,
next_bytenr, PAGE_SIZE);
if (state->print_mask & BTRFSIC_PRINT_MASK_NUM_COPIES)
printk(KERN_INFO "num_copies(log_bytenr=%llu) = %d\n",
(unsigned long long)next_bytenr, num_copies);
for (mirror_num = 1; mirror_num <= num_copies; mirror_num++) {
int was_created;
if (state->print_mask & BTRFSIC_PRINT_MASK_VERBOSE)
printk(KERN_INFO
"btrfsic_process_written_superblock("
"mirror_num=%d)\n", mirror_num);
ret = btrfsic_map_block(state, next_bytenr, PAGE_SIZE,
&tmp_next_block_ctx,
mirror_num);
if (ret) {
printk(KERN_INFO
"btrfsic: btrfsic_map_block(@%llu,"
" mirror=%d) failed!\n",
(unsigned long long)next_bytenr,
mirror_num);
return -1;
}
next_block = btrfsic_block_lookup_or_add(
state,
&tmp_next_block_ctx,
additional_string,
1, 0, 1,
mirror_num,
&was_created);
if (NULL == next_block) {
printk(KERN_INFO
"btrfsic: error, kmalloc failed!\n");
btrfsic_release_block_ctx(&tmp_next_block_ctx);
return -1;
}
next_block->disk_key = tmp_disk_key;
if (was_created)
next_block->generation =
BTRFSIC_GENERATION_UNKNOWN;
l = btrfsic_block_link_lookup_or_add(
state,
&tmp_next_block_ctx,
next_block,
superblock,
BTRFSIC_GENERATION_UNKNOWN);
btrfsic_release_block_ctx(&tmp_next_block_ctx);
if (NULL == l)
return -1;
}
}
if (-1 == btrfsic_check_all_ref_blocks(state, superblock, 0)) {
WARN_ON(1);
btrfsic_dump_tree(state);
}
return 0;
}
static int btrfsic_check_all_ref_blocks(struct btrfsic_state *state,
struct btrfsic_block *const block,
int recursion_level)
{
struct list_head *elem_ref_to;
int ret = 0;
if (recursion_level >= 3 + BTRFS_MAX_LEVEL) {
if (state->print_mask & BTRFSIC_PRINT_MASK_VERBOSE)
printk(KERN_INFO
"btrfsic: abort cyclic linkage (case 1).\n");
return ret;
}
list_for_each(elem_ref_to, &block->ref_to_list) {
const struct btrfsic_block_link *const l =
list_entry(elem_ref_to, struct btrfsic_block_link,
node_ref_to);
if (state->print_mask & BTRFSIC_PRINT_MASK_VERBOSE)
printk(KERN_INFO
"rl=%d, %c @%llu (%s/%llu/%d)"
" %u* refers to %c @%llu (%s/%llu/%d)\n",
recursion_level,
btrfsic_get_block_type(state, block),
(unsigned long long)block->logical_bytenr,
block->dev_state->name,
(unsigned long long)block->dev_bytenr,
block->mirror_num,
l->ref_cnt,
btrfsic_get_block_type(state, l->block_ref_to),
(unsigned long long)
l->block_ref_to->logical_bytenr,
l->block_ref_to->dev_state->name,
(unsigned long long)l->block_ref_to->dev_bytenr,
l->block_ref_to->mirror_num);
if (l->block_ref_to->never_written) {
printk(KERN_INFO "btrfs: attempt to write superblock"
" which references block %c @%llu (%s/%llu/%d)"
" which is never written!\n",
btrfsic_get_block_type(state, l->block_ref_to),
(unsigned long long)
l->block_ref_to->logical_bytenr,
l->block_ref_to->dev_state->name,
(unsigned long long)l->block_ref_to->dev_bytenr,
l->block_ref_to->mirror_num);
ret = -1;
} else if (!l->block_ref_to->is_iodone) {
printk(KERN_INFO "btrfs: attempt to write superblock"
" which references block %c @%llu (%s/%llu/%d)"
" which is not yet iodone!\n",
btrfsic_get_block_type(state, l->block_ref_to),
(unsigned long long)
l->block_ref_to->logical_bytenr,
l->block_ref_to->dev_state->name,
(unsigned long long)l->block_ref_to->dev_bytenr,
l->block_ref_to->mirror_num);
ret = -1;
} else if (l->parent_generation !=
l->block_ref_to->generation &&
BTRFSIC_GENERATION_UNKNOWN !=
l->parent_generation &&
BTRFSIC_GENERATION_UNKNOWN !=
l->block_ref_to->generation) {
printk(KERN_INFO "btrfs: attempt to write superblock"
" which references block %c @%llu (%s/%llu/%d)"
" with generation %llu !="
" parent generation %llu!\n",
btrfsic_get_block_type(state, l->block_ref_to),
(unsigned long long)
l->block_ref_to->logical_bytenr,
l->block_ref_to->dev_state->name,
(unsigned long long)l->block_ref_to->dev_bytenr,
l->block_ref_to->mirror_num,
(unsigned long long)l->block_ref_to->generation,
(unsigned long long)l->parent_generation);
ret = -1;
} else if (l->block_ref_to->flush_gen >
l->block_ref_to->dev_state->last_flush_gen) {
printk(KERN_INFO "btrfs: attempt to write superblock"
" which references block %c @%llu (%s/%llu/%d)"
" which is not flushed out of disk's write cache"
" (block flush_gen=%llu,"
" dev->flush_gen=%llu)!\n",
btrfsic_get_block_type(state, l->block_ref_to),
(unsigned long long)
l->block_ref_to->logical_bytenr,
l->block_ref_to->dev_state->name,
(unsigned long long)l->block_ref_to->dev_bytenr,
l->block_ref_to->mirror_num,
(unsigned long long)block->flush_gen,
(unsigned long long)
l->block_ref_to->dev_state->last_flush_gen);
ret = -1;
} else if (-1 == btrfsic_check_all_ref_blocks(state,
l->block_ref_to,
recursion_level +
1)) {
ret = -1;
}
}
return ret;
}
static int btrfsic_is_block_ref_by_superblock(
const struct btrfsic_state *state,
const struct btrfsic_block *block,
int recursion_level)
{
struct list_head *elem_ref_from;
if (recursion_level >= 3 + BTRFS_MAX_LEVEL) {
if (state->print_mask & BTRFSIC_PRINT_MASK_VERBOSE)
printk(KERN_INFO
"btrfsic: abort cyclic linkage (case 2).\n");
return 0;
}
list_for_each(elem_ref_from, &block->ref_from_list) {
const struct btrfsic_block_link *const l =
list_entry(elem_ref_from, struct btrfsic_block_link,
node_ref_from);
if (state->print_mask & BTRFSIC_PRINT_MASK_VERBOSE)
printk(KERN_INFO
"rl=%d, %c @%llu (%s/%llu/%d)"
" is ref %u* from %c @%llu (%s/%llu/%d)\n",
recursion_level,
btrfsic_get_block_type(state, block),
(unsigned long long)block->logical_bytenr,
block->dev_state->name,
(unsigned long long)block->dev_bytenr,
block->mirror_num,
l->ref_cnt,
btrfsic_get_block_type(state, l->block_ref_from),
(unsigned long long)
l->block_ref_from->logical_bytenr,
l->block_ref_from->dev_state->name,
(unsigned long long)
l->block_ref_from->dev_bytenr,
l->block_ref_from->mirror_num);
if (l->block_ref_from->is_superblock &&
state->latest_superblock->dev_bytenr ==
l->block_ref_from->dev_bytenr &&
state->latest_superblock->dev_state->bdev ==
l->block_ref_from->dev_state->bdev)
return 1;
else if (btrfsic_is_block_ref_by_superblock(state,
l->block_ref_from,
recursion_level +
1))
return 1;
}
return 0;
}
static void btrfsic_print_add_link(const struct btrfsic_state *state,
const struct btrfsic_block_link *l)
{
printk(KERN_INFO
"Add %u* link from %c @%llu (%s/%llu/%d)"
" to %c @%llu (%s/%llu/%d).\n",
l->ref_cnt,
btrfsic_get_block_type(state, l->block_ref_from),
(unsigned long long)l->block_ref_from->logical_bytenr,
l->block_ref_from->dev_state->name,
(unsigned long long)l->block_ref_from->dev_bytenr,
l->block_ref_from->mirror_num,
btrfsic_get_block_type(state, l->block_ref_to),
(unsigned long long)l->block_ref_to->logical_bytenr,
l->block_ref_to->dev_state->name,
(unsigned long long)l->block_ref_to->dev_bytenr,
l->block_ref_to->mirror_num);
}
static void btrfsic_print_rem_link(const struct btrfsic_state *state,
const struct btrfsic_block_link *l)
{
printk(KERN_INFO
"Rem %u* link from %c @%llu (%s/%llu/%d)"
" to %c @%llu (%s/%llu/%d).\n",
l->ref_cnt,
btrfsic_get_block_type(state, l->block_ref_from),
(unsigned long long)l->block_ref_from->logical_bytenr,
l->block_ref_from->dev_state->name,
(unsigned long long)l->block_ref_from->dev_bytenr,
l->block_ref_from->mirror_num,
btrfsic_get_block_type(state, l->block_ref_to),
(unsigned long long)l->block_ref_to->logical_bytenr,
l->block_ref_to->dev_state->name,
(unsigned long long)l->block_ref_to->dev_bytenr,
l->block_ref_to->mirror_num);
}
static char btrfsic_get_block_type(const struct btrfsic_state *state,
const struct btrfsic_block *block)
{
if (block->is_superblock &&
state->latest_superblock->dev_bytenr == block->dev_bytenr &&
state->latest_superblock->dev_state->bdev == block->dev_state->bdev)
return 'S';
else if (block->is_superblock)
return 's';
else if (block->is_metadata)
return 'M';
else
return 'D';
}
static void btrfsic_dump_tree(const struct btrfsic_state *state)
{
btrfsic_dump_tree_sub(state, state->latest_superblock, 0);
}
static void btrfsic_dump_tree_sub(const struct btrfsic_state *state,
const struct btrfsic_block *block,
int indent_level)
{
struct list_head *elem_ref_to;
int indent_add;
static char buf[80];
int cursor_position;
indent_add = sprintf(buf, "%c-%llu(%s/%llu/%d)",
btrfsic_get_block_type(state, block),
(unsigned long long)block->logical_bytenr,
block->dev_state->name,
(unsigned long long)block->dev_bytenr,
block->mirror_num);
if (indent_level + indent_add > BTRFSIC_TREE_DUMP_MAX_INDENT_LEVEL) {
printk("[...]\n");
return;
}
printk(buf);
indent_level += indent_add;
if (list_empty(&block->ref_to_list)) {
printk("\n");
return;
}
if (block->mirror_num > 1 &&
!(state->print_mask & BTRFSIC_PRINT_MASK_TREE_WITH_ALL_MIRRORS)) {
printk(" [...]\n");
return;
}
cursor_position = indent_level;
list_for_each(elem_ref_to, &block->ref_to_list) {
const struct btrfsic_block_link *const l =
list_entry(elem_ref_to, struct btrfsic_block_link,
node_ref_to);
while (cursor_position < indent_level) {
printk(" ");
cursor_position++;
}
if (l->ref_cnt > 1)
indent_add = sprintf(buf, " %d*--> ", l->ref_cnt);
else
indent_add = sprintf(buf, " --> ");
if (indent_level + indent_add >
BTRFSIC_TREE_DUMP_MAX_INDENT_LEVEL) {
printk("[...]\n");
cursor_position = 0;
continue;
}
printk(buf);
btrfsic_dump_tree_sub(state, l->block_ref_to,
indent_level + indent_add);
cursor_position = 0;
}
}
static struct btrfsic_block_link *btrfsic_block_link_lookup_or_add(
struct btrfsic_state *state,
struct btrfsic_block_data_ctx *next_block_ctx,
struct btrfsic_block *next_block,
struct btrfsic_block *from_block,
u64 parent_generation)
{
struct btrfsic_block_link *l;
l = btrfsic_block_link_hashtable_lookup(next_block_ctx->dev->bdev,
next_block_ctx->dev_bytenr,
from_block->dev_state->bdev,
from_block->dev_bytenr,
&state->block_link_hashtable);
if (NULL == l) {
l = btrfsic_block_link_alloc();
if (NULL == l) {
printk(KERN_INFO
"btrfsic: error, kmalloc" " failed!\n");
return NULL;
}
l->block_ref_to = next_block;
l->block_ref_from = from_block;
l->ref_cnt = 1;
l->parent_generation = parent_generation;
if (state->print_mask & BTRFSIC_PRINT_MASK_VERBOSE)
btrfsic_print_add_link(state, l);
list_add(&l->node_ref_to, &from_block->ref_to_list);
list_add(&l->node_ref_from, &next_block->ref_from_list);
btrfsic_block_link_hashtable_add(l,
&state->block_link_hashtable);
} else {
l->ref_cnt++;
l->parent_generation = parent_generation;
if (state->print_mask & BTRFSIC_PRINT_MASK_VERBOSE)
btrfsic_print_add_link(state, l);
}
return l;
}
static struct btrfsic_block *btrfsic_block_lookup_or_add(
struct btrfsic_state *state,
struct btrfsic_block_data_ctx *block_ctx,
const char *additional_string,
int is_metadata,
int is_iodone,
int never_written,
int mirror_num,
int *was_created)
{
struct btrfsic_block *block;
block = btrfsic_block_hashtable_lookup(block_ctx->dev->bdev,
block_ctx->dev_bytenr,
&state->block_hashtable);
if (NULL == block) {
struct btrfsic_dev_state *dev_state;
block = btrfsic_block_alloc();
if (NULL == block) {
printk(KERN_INFO "btrfsic: error, kmalloc failed!\n");
return NULL;
}
dev_state = btrfsic_dev_state_lookup(block_ctx->dev->bdev);
if (NULL == dev_state) {
printk(KERN_INFO
"btrfsic: error, lookup dev_state failed!\n");
btrfsic_block_free(block);
return NULL;
}
block->dev_state = dev_state;
block->dev_bytenr = block_ctx->dev_bytenr;
block->logical_bytenr = block_ctx->start;
block->is_metadata = is_metadata;
block->is_iodone = is_iodone;
block->never_written = never_written;
block->mirror_num = mirror_num;
if (state->print_mask & BTRFSIC_PRINT_MASK_VERBOSE)
printk(KERN_INFO
"New %s%c-block @%llu (%s/%llu/%d)\n",
additional_string,
btrfsic_get_block_type(state, block),
(unsigned long long)block->logical_bytenr,
dev_state->name,
(unsigned long long)block->dev_bytenr,
mirror_num);
list_add(&block->all_blocks_node, &state->all_blocks_list);
btrfsic_block_hashtable_add(block, &state->block_hashtable);
if (NULL != was_created)
*was_created = 1;
} else {
if (NULL != was_created)
*was_created = 0;
}
return block;
}
static void btrfsic_cmp_log_and_dev_bytenr(struct btrfsic_state *state,
u64 bytenr,
struct btrfsic_dev_state *dev_state,
u64 dev_bytenr, char *data)
{
int num_copies;
int mirror_num;
int ret;
struct btrfsic_block_data_ctx block_ctx;
int match = 0;
num_copies = btrfs_num_copies(&state->root->fs_info->mapping_tree,
bytenr, PAGE_SIZE);
for (mirror_num = 1; mirror_num <= num_copies; mirror_num++) {
ret = btrfsic_map_block(state, bytenr, PAGE_SIZE,
&block_ctx, mirror_num);
if (ret) {
printk(KERN_INFO "btrfsic:"
" btrfsic_map_block(logical @%llu,"
" mirror %d) failed!\n",
(unsigned long long)bytenr, mirror_num);
continue;
}
if (dev_state->bdev == block_ctx.dev->bdev &&
dev_bytenr == block_ctx.dev_bytenr) {
match++;
btrfsic_release_block_ctx(&block_ctx);
break;
}
btrfsic_release_block_ctx(&block_ctx);
}
if (!match) {
printk(KERN_INFO "btrfs: attempt to write M-block which contains logical bytenr that doesn't map to dev+physical bytenr of submit_bio,"
" buffer->log_bytenr=%llu, submit_bio(bdev=%s,"
" phys_bytenr=%llu)!\n",
(unsigned long long)bytenr, dev_state->name,
(unsigned long long)dev_bytenr);
for (mirror_num = 1; mirror_num <= num_copies; mirror_num++) {
ret = btrfsic_map_block(state, bytenr, PAGE_SIZE,
&block_ctx, mirror_num);
if (ret)
continue;
printk(KERN_INFO "Read logical bytenr @%llu maps to"
" (%s/%llu/%d)\n",
(unsigned long long)bytenr,
block_ctx.dev->name,
(unsigned long long)block_ctx.dev_bytenr,
mirror_num);
}
WARN_ON(1);
}
}
static struct btrfsic_dev_state *btrfsic_dev_state_lookup(
struct block_device *bdev)
{
struct btrfsic_dev_state *ds;
ds = btrfsic_dev_state_hashtable_lookup(bdev,
&btrfsic_dev_state_hashtable);
return ds;
}
int btrfsic_submit_bh(int rw, struct buffer_head *bh)
{
struct btrfsic_dev_state *dev_state;
if (!btrfsic_is_initialized)
return submit_bh(rw, bh);
mutex_lock(&btrfsic_mutex);
dev_state = btrfsic_dev_state_lookup(bh->b_bdev);
if (NULL != dev_state &&
(rw & WRITE) && bh->b_size > 0) {
u64 dev_bytenr;
dev_bytenr = 4096 * bh->b_blocknr;
if (dev_state->state->print_mask &
BTRFSIC_PRINT_MASK_SUBMIT_BIO_BH)
printk(KERN_INFO
"submit_bh(rw=0x%x, blocknr=%lu (bytenr %llu),"
" size=%lu, data=%p, bdev=%p)\n",
rw, (unsigned long)bh->b_blocknr,
(unsigned long long)dev_bytenr,
(unsigned long)bh->b_size, bh->b_data,
bh->b_bdev);
btrfsic_process_written_block(dev_state, dev_bytenr,
bh->b_data, bh->b_size, NULL,
NULL, bh, rw);
} else if (NULL != dev_state && (rw & REQ_FLUSH)) {
if (dev_state->state->print_mask &
BTRFSIC_PRINT_MASK_SUBMIT_BIO_BH)
printk(KERN_INFO
"submit_bh(rw=0x%x) FLUSH, bdev=%p)\n",
rw, bh->b_bdev);
if (!dev_state->dummy_block_for_bio_bh_flush.is_iodone) {
if ((dev_state->state->print_mask &
(BTRFSIC_PRINT_MASK_SUBMIT_BIO_BH |
BTRFSIC_PRINT_MASK_VERBOSE)))
printk(KERN_INFO
"btrfsic_submit_bh(%s) with FLUSH"
" but dummy block already in use"
" (ignored)!\n",
dev_state->name);
} else {
struct btrfsic_block *const block =
&dev_state->dummy_block_for_bio_bh_flush;
block->is_iodone = 0;
block->never_written = 0;
block->iodone_w_error = 0;
block->flush_gen = dev_state->last_flush_gen + 1;
block->submit_bio_bh_rw = rw;
block->orig_bio_bh_private = bh->b_private;
block->orig_bio_bh_end_io.bh = bh->b_end_io;
block->next_in_same_bio = NULL;
bh->b_private = block;
bh->b_end_io = btrfsic_bh_end_io;
}
}
mutex_unlock(&btrfsic_mutex);
return submit_bh(rw, bh);
}
void btrfsic_submit_bio(int rw, struct bio *bio)
{
struct btrfsic_dev_state *dev_state;
if (!btrfsic_is_initialized) {
submit_bio(rw, bio);
return;
}
mutex_lock(&btrfsic_mutex);
dev_state = btrfsic_dev_state_lookup(bio->bi_bdev);
if (NULL != dev_state &&
(rw & WRITE) && NULL != bio->bi_io_vec) {
unsigned int i;
u64 dev_bytenr;
int bio_is_patched;
dev_bytenr = 512 * bio->bi_sector;
bio_is_patched = 0;
if (dev_state->state->print_mask &
BTRFSIC_PRINT_MASK_SUBMIT_BIO_BH)
printk(KERN_INFO
"submit_bio(rw=0x%x, bi_vcnt=%u,"
" bi_sector=%lu (bytenr %llu), bi_bdev=%p)\n",
rw, bio->bi_vcnt, (unsigned long)bio->bi_sector,
(unsigned long long)dev_bytenr,
bio->bi_bdev);
for (i = 0; i < bio->bi_vcnt; i++) {
u8 *mapped_data;
mapped_data = kmap(bio->bi_io_vec[i].bv_page);
if ((BTRFSIC_PRINT_MASK_SUBMIT_BIO_BH |
BTRFSIC_PRINT_MASK_VERBOSE) ==
(dev_state->state->print_mask &
(BTRFSIC_PRINT_MASK_SUBMIT_BIO_BH |
BTRFSIC_PRINT_MASK_VERBOSE)))
printk(KERN_INFO
"#%u: page=%p, mapped=%p, len=%u,"
" offset=%u\n",
i, bio->bi_io_vec[i].bv_page,
mapped_data,
bio->bi_io_vec[i].bv_len,
bio->bi_io_vec[i].bv_offset);
btrfsic_process_written_block(dev_state, dev_bytenr,
mapped_data,
bio->bi_io_vec[i].bv_len,
bio, &bio_is_patched,
NULL, rw);
kunmap(bio->bi_io_vec[i].bv_page);
dev_bytenr += bio->bi_io_vec[i].bv_len;
}
} else if (NULL != dev_state && (rw & REQ_FLUSH)) {
if (dev_state->state->print_mask &
BTRFSIC_PRINT_MASK_SUBMIT_BIO_BH)
printk(KERN_INFO
"submit_bio(rw=0x%x) FLUSH, bdev=%p)\n",
rw, bio->bi_bdev);
if (!dev_state->dummy_block_for_bio_bh_flush.is_iodone) {
if ((dev_state->state->print_mask &
(BTRFSIC_PRINT_MASK_SUBMIT_BIO_BH |
BTRFSIC_PRINT_MASK_VERBOSE)))
printk(KERN_INFO
"btrfsic_submit_bio(%s) with FLUSH"
" but dummy block already in use"
" (ignored)!\n",
dev_state->name);
} else {
struct btrfsic_block *const block =
&dev_state->dummy_block_for_bio_bh_flush;
block->is_iodone = 0;
block->never_written = 0;
block->iodone_w_error = 0;
block->flush_gen = dev_state->last_flush_gen + 1;
block->submit_bio_bh_rw = rw;
block->orig_bio_bh_private = bio->bi_private;
block->orig_bio_bh_end_io.bio = bio->bi_end_io;
block->next_in_same_bio = NULL;
bio->bi_private = block;
bio->bi_end_io = btrfsic_bio_end_io;
}
}
mutex_unlock(&btrfsic_mutex);
submit_bio(rw, bio);
}
int btrfsic_mount(struct btrfs_root *root,
struct btrfs_fs_devices *fs_devices,
int including_extent_data, u32 print_mask)
{
int ret;
struct btrfsic_state *state;
struct list_head *dev_head = &fs_devices->devices;
struct btrfs_device *device;
state = kzalloc(sizeof(*state), GFP_NOFS);
if (NULL == state) {
printk(KERN_INFO "btrfs check-integrity: kmalloc() failed!\n");
return -1;
}
if (!btrfsic_is_initialized) {
mutex_init(&btrfsic_mutex);
btrfsic_dev_state_hashtable_init(&btrfsic_dev_state_hashtable);
btrfsic_is_initialized = 1;
}
mutex_lock(&btrfsic_mutex);
state->root = root;
state->print_mask = print_mask;
state->include_extent_data = including_extent_data;
state->csum_size = 0;
INIT_LIST_HEAD(&state->all_blocks_list);
btrfsic_block_hashtable_init(&state->block_hashtable);
btrfsic_block_link_hashtable_init(&state->block_link_hashtable);
state->max_superblock_generation = 0;
state->latest_superblock = NULL;
list_for_each_entry(device, dev_head, dev_list) {
struct btrfsic_dev_state *ds;
char *p;
if (!device->bdev || !device->name)
continue;
ds = btrfsic_dev_state_alloc();
if (NULL == ds) {
printk(KERN_INFO
"btrfs check-integrity: kmalloc() failed!\n");
mutex_unlock(&btrfsic_mutex);
return -1;
}
ds->bdev = device->bdev;
ds->state = state;
bdevname(ds->bdev, ds->name);
ds->name[BDEVNAME_SIZE - 1] = '\0';
for (p = ds->name; *p != '\0'; p++);
while (p > ds->name && *p != '/')
p--;
if (*p == '/')
p++;
strlcpy(ds->name, p, sizeof(ds->name));
btrfsic_dev_state_hashtable_add(ds,
&btrfsic_dev_state_hashtable);
}
ret = btrfsic_process_superblock(state, fs_devices);
if (0 != ret) {
mutex_unlock(&btrfsic_mutex);
btrfsic_unmount(root, fs_devices);
return ret;
}
if (state->print_mask & BTRFSIC_PRINT_MASK_INITIAL_DATABASE)
btrfsic_dump_database(state);
if (state->print_mask & BTRFSIC_PRINT_MASK_INITIAL_TREE)
btrfsic_dump_tree(state);
mutex_unlock(&btrfsic_mutex);
return 0;
}
void btrfsic_unmount(struct btrfs_root *root,
struct btrfs_fs_devices *fs_devices)
{
struct list_head *elem_all;
struct list_head *tmp_all;
struct btrfsic_state *state;
struct list_head *dev_head = &fs_devices->devices;
struct btrfs_device *device;
if (!btrfsic_is_initialized)
return;
mutex_lock(&btrfsic_mutex);
state = NULL;
list_for_each_entry(device, dev_head, dev_list) {
struct btrfsic_dev_state *ds;
if (!device->bdev || !device->name)
continue;
ds = btrfsic_dev_state_hashtable_lookup(
device->bdev,
&btrfsic_dev_state_hashtable);
if (NULL != ds) {
state = ds->state;
btrfsic_dev_state_hashtable_remove(ds);
btrfsic_dev_state_free(ds);
}
}
if (NULL == state) {
printk(KERN_INFO
"btrfsic: error, cannot find state information"
" on umount!\n");
mutex_unlock(&btrfsic_mutex);
return;
}
list_for_each_safe(elem_all, tmp_all, &state->all_blocks_list) {
struct btrfsic_block *const b_all =
list_entry(elem_all, struct btrfsic_block,
all_blocks_node);
struct list_head *elem_ref_to;
struct list_head *tmp_ref_to;
list_for_each_safe(elem_ref_to, tmp_ref_to,
&b_all->ref_to_list) {
struct btrfsic_block_link *const l =
list_entry(elem_ref_to,
struct btrfsic_block_link,
node_ref_to);
if (state->print_mask & BTRFSIC_PRINT_MASK_VERBOSE)
btrfsic_print_rem_link(state, l);
l->ref_cnt--;
if (0 == l->ref_cnt)
btrfsic_block_link_free(l);
}
if (b_all->is_iodone)
btrfsic_block_free(b_all);
else
printk(KERN_INFO "btrfs: attempt to free %c-block"
" @%llu (%s/%llu/%d) on umount which is"
" not yet iodone!\n",
btrfsic_get_block_type(state, b_all),
(unsigned long long)b_all->logical_bytenr,
b_all->dev_state->name,
(unsigned long long)b_all->dev_bytenr,
b_all->mirror_num);
}
mutex_unlock(&btrfsic_mutex);
kfree(state);
}
