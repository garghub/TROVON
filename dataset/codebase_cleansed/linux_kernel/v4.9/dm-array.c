static void array_block_prepare_for_write(struct dm_block_validator *v,
struct dm_block *b,
size_t size_of_block)
{
struct array_block *bh_le = dm_block_data(b);
bh_le->blocknr = cpu_to_le64(dm_block_location(b));
bh_le->csum = cpu_to_le32(dm_bm_checksum(&bh_le->max_entries,
size_of_block - sizeof(__le32),
CSUM_XOR));
}
static int array_block_check(struct dm_block_validator *v,
struct dm_block *b,
size_t size_of_block)
{
struct array_block *bh_le = dm_block_data(b);
__le32 csum_disk;
if (dm_block_location(b) != le64_to_cpu(bh_le->blocknr)) {
DMERR_LIMIT("array_block_check failed: blocknr %llu != wanted %llu",
(unsigned long long) le64_to_cpu(bh_le->blocknr),
(unsigned long long) dm_block_location(b));
return -ENOTBLK;
}
csum_disk = cpu_to_le32(dm_bm_checksum(&bh_le->max_entries,
size_of_block - sizeof(__le32),
CSUM_XOR));
if (csum_disk != bh_le->csum) {
DMERR_LIMIT("array_block_check failed: csum %u != wanted %u",
(unsigned) le32_to_cpu(csum_disk),
(unsigned) le32_to_cpu(bh_le->csum));
return -EILSEQ;
}
return 0;
}
static void *element_at(struct dm_array_info *info, struct array_block *ab,
unsigned index)
{
unsigned char *entry = (unsigned char *) (ab + 1);
entry += index * info->value_type.size;
return entry;
}
static void on_entries(struct dm_array_info *info, struct array_block *ab,
void (*fn)(void *, const void *))
{
unsigned i, nr_entries = le32_to_cpu(ab->nr_entries);
for (i = 0; i < nr_entries; i++)
fn(info->value_type.context, element_at(info, ab, i));
}
static void inc_ablock_entries(struct dm_array_info *info, struct array_block *ab)
{
struct dm_btree_value_type *vt = &info->value_type;
if (vt->inc)
on_entries(info, ab, vt->inc);
}
static void dec_ablock_entries(struct dm_array_info *info, struct array_block *ab)
{
struct dm_btree_value_type *vt = &info->value_type;
if (vt->dec)
on_entries(info, ab, vt->dec);
}
static uint32_t calc_max_entries(size_t value_size, size_t size_of_block)
{
return (size_of_block - sizeof(struct array_block)) / value_size;
}
static int alloc_ablock(struct dm_array_info *info, size_t size_of_block,
uint32_t max_entries,
struct dm_block **block, struct array_block **ab)
{
int r;
r = dm_tm_new_block(info->btree_info.tm, &array_validator, block);
if (r)
return r;
(*ab) = dm_block_data(*block);
(*ab)->max_entries = cpu_to_le32(max_entries);
(*ab)->nr_entries = cpu_to_le32(0);
(*ab)->value_size = cpu_to_le32(info->value_type.size);
return 0;
}
static void fill_ablock(struct dm_array_info *info, struct array_block *ab,
const void *value, unsigned new_nr)
{
unsigned i;
uint32_t nr_entries;
struct dm_btree_value_type *vt = &info->value_type;
BUG_ON(new_nr > le32_to_cpu(ab->max_entries));
BUG_ON(new_nr < le32_to_cpu(ab->nr_entries));
nr_entries = le32_to_cpu(ab->nr_entries);
for (i = nr_entries; i < new_nr; i++) {
if (vt->inc)
vt->inc(vt->context, value);
memcpy(element_at(info, ab, i), value, vt->size);
}
ab->nr_entries = cpu_to_le32(new_nr);
}
static void trim_ablock(struct dm_array_info *info, struct array_block *ab,
unsigned new_nr)
{
unsigned i;
uint32_t nr_entries;
struct dm_btree_value_type *vt = &info->value_type;
BUG_ON(new_nr > le32_to_cpu(ab->max_entries));
BUG_ON(new_nr > le32_to_cpu(ab->nr_entries));
nr_entries = le32_to_cpu(ab->nr_entries);
for (i = nr_entries; i > new_nr; i--)
if (vt->dec)
vt->dec(vt->context, element_at(info, ab, i - 1));
ab->nr_entries = cpu_to_le32(new_nr);
}
static int get_ablock(struct dm_array_info *info, dm_block_t b,
struct dm_block **block, struct array_block **ab)
{
int r;
r = dm_tm_read_lock(info->btree_info.tm, b, &array_validator, block);
if (r)
return r;
*ab = dm_block_data(*block);
return 0;
}
static void unlock_ablock(struct dm_array_info *info, struct dm_block *block)
{
dm_tm_unlock(info->btree_info.tm, block);
}
static int lookup_ablock(struct dm_array_info *info, dm_block_t root,
unsigned index, struct dm_block **block,
struct array_block **ab)
{
int r;
uint64_t key = index;
__le64 block_le;
r = dm_btree_lookup(&info->btree_info, root, &key, &block_le);
if (r)
return r;
return get_ablock(info, le64_to_cpu(block_le), block, ab);
}
static int insert_ablock(struct dm_array_info *info, uint64_t index,
struct dm_block *block, dm_block_t *root)
{
__le64 block_le = cpu_to_le64(dm_block_location(block));
__dm_bless_for_disk(block_le);
return dm_btree_insert(&info->btree_info, *root, &index, &block_le, root);
}
static int __shadow_ablock(struct dm_array_info *info, dm_block_t b,
struct dm_block **block, struct array_block **ab)
{
int inc;
int r = dm_tm_shadow_block(info->btree_info.tm, b,
&array_validator, block, &inc);
if (r)
return r;
*ab = dm_block_data(*block);
if (inc)
inc_ablock_entries(info, *ab);
return 0;
}
static int __reinsert_ablock(struct dm_array_info *info, unsigned index,
struct dm_block *block, dm_block_t b,
dm_block_t *root)
{
int r = 0;
if (dm_block_location(block) != b) {
dm_tm_inc(info->btree_info.tm, b);
r = insert_ablock(info, index, block, root);
}
return r;
}
static int shadow_ablock(struct dm_array_info *info, dm_block_t *root,
unsigned index, struct dm_block **block,
struct array_block **ab)
{
int r;
uint64_t key = index;
dm_block_t b;
__le64 block_le;
r = dm_btree_lookup(&info->btree_info, *root, &key, &block_le);
if (r)
return r;
b = le64_to_cpu(block_le);
r = __shadow_ablock(info, b, block, ab);
if (r)
return r;
return __reinsert_ablock(info, index, *block, b, root);
}
static int insert_new_ablock(struct dm_array_info *info, size_t size_of_block,
uint32_t max_entries,
unsigned block_index, uint32_t nr,
const void *value, dm_block_t *root)
{
int r;
struct dm_block *block;
struct array_block *ab;
r = alloc_ablock(info, size_of_block, max_entries, &block, &ab);
if (r)
return r;
fill_ablock(info, ab, value, nr);
r = insert_ablock(info, block_index, block, root);
unlock_ablock(info, block);
return r;
}
static int insert_full_ablocks(struct dm_array_info *info, size_t size_of_block,
unsigned begin_block, unsigned end_block,
unsigned max_entries, const void *value,
dm_block_t *root)
{
int r = 0;
for (; !r && begin_block != end_block; begin_block++)
r = insert_new_ablock(info, size_of_block, max_entries, begin_block, max_entries, value, root);
return r;
}
static int drop_blocks(struct resize *resize, unsigned begin_index,
unsigned end_index)
{
int r;
while (begin_index != end_index) {
uint64_t key = begin_index++;
r = dm_btree_remove(&resize->info->btree_info, resize->root,
&key, &resize->root);
if (r)
return r;
}
return 0;
}
static unsigned total_nr_blocks_needed(unsigned nr_full_blocks,
unsigned nr_entries_in_last_block)
{
return nr_full_blocks + (nr_entries_in_last_block ? 1 : 0);
}
static int shrink(struct resize *resize)
{
int r;
unsigned begin, end;
struct dm_block *block;
struct array_block *ab;
if (resize->new_nr_full_blocks < resize->old_nr_full_blocks) {
begin = total_nr_blocks_needed(resize->new_nr_full_blocks,
resize->new_nr_entries_in_last_block);
end = total_nr_blocks_needed(resize->old_nr_full_blocks,
resize->old_nr_entries_in_last_block);
r = drop_blocks(resize, begin, end);
if (r)
return r;
}
if (resize->new_nr_entries_in_last_block) {
r = shadow_ablock(resize->info, &resize->root,
resize->new_nr_full_blocks, &block, &ab);
if (r)
return r;
trim_ablock(resize->info, ab, resize->new_nr_entries_in_last_block);
unlock_ablock(resize->info, block);
}
return 0;
}
static int grow_extend_tail_block(struct resize *resize, uint32_t new_nr_entries)
{
int r;
struct dm_block *block;
struct array_block *ab;
r = shadow_ablock(resize->info, &resize->root,
resize->old_nr_full_blocks, &block, &ab);
if (r)
return r;
fill_ablock(resize->info, ab, resize->value, new_nr_entries);
unlock_ablock(resize->info, block);
return r;
}
static int grow_add_tail_block(struct resize *resize)
{
return insert_new_ablock(resize->info, resize->size_of_block,
resize->max_entries,
resize->new_nr_full_blocks,
resize->new_nr_entries_in_last_block,
resize->value, &resize->root);
}
static int grow_needs_more_blocks(struct resize *resize)
{
int r;
unsigned old_nr_blocks = resize->old_nr_full_blocks;
if (resize->old_nr_entries_in_last_block > 0) {
old_nr_blocks++;
r = grow_extend_tail_block(resize, resize->max_entries);
if (r)
return r;
}
r = insert_full_ablocks(resize->info, resize->size_of_block,
old_nr_blocks,
resize->new_nr_full_blocks,
resize->max_entries, resize->value,
&resize->root);
if (r)
return r;
if (resize->new_nr_entries_in_last_block)
r = grow_add_tail_block(resize);
return r;
}
static int grow(struct resize *resize)
{
if (resize->new_nr_full_blocks > resize->old_nr_full_blocks)
return grow_needs_more_blocks(resize);
else if (resize->old_nr_entries_in_last_block)
return grow_extend_tail_block(resize, resize->new_nr_entries_in_last_block);
else
return grow_add_tail_block(resize);
}
static void block_inc(void *context, const void *value)
{
__le64 block_le;
struct dm_array_info *info = context;
memcpy(&block_le, value, sizeof(block_le));
dm_tm_inc(info->btree_info.tm, le64_to_cpu(block_le));
}
static void block_dec(void *context, const void *value)
{
int r;
uint64_t b;
__le64 block_le;
uint32_t ref_count;
struct dm_block *block;
struct array_block *ab;
struct dm_array_info *info = context;
memcpy(&block_le, value, sizeof(block_le));
b = le64_to_cpu(block_le);
r = dm_tm_ref(info->btree_info.tm, b, &ref_count);
if (r) {
DMERR_LIMIT("couldn't get reference count for block %llu",
(unsigned long long) b);
return;
}
if (ref_count == 1) {
r = get_ablock(info, b, &block, &ab);
if (r) {
DMERR_LIMIT("couldn't get array block %llu",
(unsigned long long) b);
return;
}
dec_ablock_entries(info, ab);
unlock_ablock(info, block);
}
dm_tm_dec(info->btree_info.tm, b);
}
static int block_equal(void *context, const void *value1, const void *value2)
{
return !memcmp(value1, value2, sizeof(__le64));
}
void dm_array_info_init(struct dm_array_info *info,
struct dm_transaction_manager *tm,
struct dm_btree_value_type *vt)
{
struct dm_btree_value_type *bvt = &info->btree_info.value_type;
memcpy(&info->value_type, vt, sizeof(info->value_type));
info->btree_info.tm = tm;
info->btree_info.levels = 1;
bvt->context = info;
bvt->size = sizeof(__le64);
bvt->inc = block_inc;
bvt->dec = block_dec;
bvt->equal = block_equal;
}
int dm_array_empty(struct dm_array_info *info, dm_block_t *root)
{
return dm_btree_empty(&info->btree_info, root);
}
static int array_resize(struct dm_array_info *info, dm_block_t root,
uint32_t old_size, uint32_t new_size,
const void *value, dm_block_t *new_root)
{
int r;
struct resize resize;
if (old_size == new_size) {
*new_root = root;
return 0;
}
resize.info = info;
resize.root = root;
resize.size_of_block = dm_bm_block_size(dm_tm_get_bm(info->btree_info.tm));
resize.max_entries = calc_max_entries(info->value_type.size,
resize.size_of_block);
resize.old_nr_full_blocks = old_size / resize.max_entries;
resize.old_nr_entries_in_last_block = old_size % resize.max_entries;
resize.new_nr_full_blocks = new_size / resize.max_entries;
resize.new_nr_entries_in_last_block = new_size % resize.max_entries;
resize.value = value;
r = ((new_size > old_size) ? grow : shrink)(&resize);
if (r)
return r;
*new_root = resize.root;
return 0;
}
int dm_array_resize(struct dm_array_info *info, dm_block_t root,
uint32_t old_size, uint32_t new_size,
const void *value, dm_block_t *new_root)
__dm_written_to_disk(value)
{
int r = array_resize(info, root, old_size, new_size, value, new_root);
__dm_unbless_for_disk(value);
return r;
}
static int populate_ablock_with_values(struct dm_array_info *info, struct array_block *ab,
value_fn fn, void *context, unsigned base, unsigned new_nr)
{
int r;
unsigned i;
uint32_t nr_entries;
struct dm_btree_value_type *vt = &info->value_type;
BUG_ON(le32_to_cpu(ab->nr_entries));
BUG_ON(new_nr > le32_to_cpu(ab->max_entries));
nr_entries = le32_to_cpu(ab->nr_entries);
for (i = 0; i < new_nr; i++) {
r = fn(base + i, element_at(info, ab, i), context);
if (r)
return r;
if (vt->inc)
vt->inc(vt->context, element_at(info, ab, i));
}
ab->nr_entries = cpu_to_le32(new_nr);
return 0;
}
int dm_array_new(struct dm_array_info *info, dm_block_t *root,
uint32_t size, value_fn fn, void *context)
{
int r;
struct dm_block *block;
struct array_block *ab;
unsigned block_index, end_block, size_of_block, max_entries;
r = dm_array_empty(info, root);
if (r)
return r;
size_of_block = dm_bm_block_size(dm_tm_get_bm(info->btree_info.tm));
max_entries = calc_max_entries(info->value_type.size, size_of_block);
end_block = dm_div_up(size, max_entries);
for (block_index = 0; block_index != end_block; block_index++) {
r = alloc_ablock(info, size_of_block, max_entries, &block, &ab);
if (r)
break;
r = populate_ablock_with_values(info, ab, fn, context,
block_index * max_entries,
min(max_entries, size));
if (r) {
unlock_ablock(info, block);
break;
}
r = insert_ablock(info, block_index, block, root);
unlock_ablock(info, block);
if (r)
break;
size -= max_entries;
}
return r;
}
int dm_array_del(struct dm_array_info *info, dm_block_t root)
{
return dm_btree_del(&info->btree_info, root);
}
int dm_array_get_value(struct dm_array_info *info, dm_block_t root,
uint32_t index, void *value_le)
{
int r;
struct dm_block *block;
struct array_block *ab;
size_t size_of_block;
unsigned entry, max_entries;
size_of_block = dm_bm_block_size(dm_tm_get_bm(info->btree_info.tm));
max_entries = calc_max_entries(info->value_type.size, size_of_block);
r = lookup_ablock(info, root, index / max_entries, &block, &ab);
if (r)
return r;
entry = index % max_entries;
if (entry >= le32_to_cpu(ab->nr_entries))
r = -ENODATA;
else
memcpy(value_le, element_at(info, ab, entry),
info->value_type.size);
unlock_ablock(info, block);
return r;
}
static int array_set_value(struct dm_array_info *info, dm_block_t root,
uint32_t index, const void *value, dm_block_t *new_root)
{
int r;
struct dm_block *block;
struct array_block *ab;
size_t size_of_block;
unsigned max_entries;
unsigned entry;
void *old_value;
struct dm_btree_value_type *vt = &info->value_type;
size_of_block = dm_bm_block_size(dm_tm_get_bm(info->btree_info.tm));
max_entries = calc_max_entries(info->value_type.size, size_of_block);
r = shadow_ablock(info, &root, index / max_entries, &block, &ab);
if (r)
return r;
*new_root = root;
entry = index % max_entries;
if (entry >= le32_to_cpu(ab->nr_entries)) {
r = -ENODATA;
goto out;
}
old_value = element_at(info, ab, entry);
if (vt->dec &&
(!vt->equal || !vt->equal(vt->context, old_value, value))) {
vt->dec(vt->context, old_value);
if (vt->inc)
vt->inc(vt->context, value);
}
memcpy(old_value, value, info->value_type.size);
out:
unlock_ablock(info, block);
return r;
}
int dm_array_set_value(struct dm_array_info *info, dm_block_t root,
uint32_t index, const void *value, dm_block_t *new_root)
__dm_written_to_disk(value)
{
int r;
r = array_set_value(info, root, index, value, new_root);
__dm_unbless_for_disk(value);
return r;
}
static int walk_ablock(void *context, uint64_t *keys, void *leaf)
{
struct walk_info *wi = context;
int r;
unsigned i;
__le64 block_le;
unsigned nr_entries, max_entries;
struct dm_block *block;
struct array_block *ab;
memcpy(&block_le, leaf, sizeof(block_le));
r = get_ablock(wi->info, le64_to_cpu(block_le), &block, &ab);
if (r)
return r;
max_entries = le32_to_cpu(ab->max_entries);
nr_entries = le32_to_cpu(ab->nr_entries);
for (i = 0; i < nr_entries; i++) {
r = wi->fn(wi->context, keys[0] * max_entries + i,
element_at(wi->info, ab, i));
if (r)
break;
}
unlock_ablock(wi->info, block);
return r;
}
int dm_array_walk(struct dm_array_info *info, dm_block_t root,
int (*fn)(void *, uint64_t key, void *leaf),
void *context)
{
struct walk_info wi;
wi.info = info;
wi.fn = fn;
wi.context = context;
return dm_btree_walk(&info->btree_info, root, walk_ablock, &wi);
}
static int load_ablock(struct dm_array_cursor *c)
{
int r;
__le64 value_le;
uint64_t key;
if (c->block)
unlock_ablock(c->info, c->block);
c->block = NULL;
c->ab = NULL;
c->index = 0;
r = dm_btree_cursor_get_value(&c->cursor, &key, &value_le);
if (r) {
DMERR("dm_btree_cursor_get_value failed");
dm_btree_cursor_end(&c->cursor);
} else {
r = get_ablock(c->info, le64_to_cpu(value_le), &c->block, &c->ab);
if (r) {
DMERR("get_ablock failed");
dm_btree_cursor_end(&c->cursor);
}
}
return r;
}
int dm_array_cursor_begin(struct dm_array_info *info, dm_block_t root,
struct dm_array_cursor *c)
{
int r;
memset(c, 0, sizeof(*c));
c->info = info;
r = dm_btree_cursor_begin(&info->btree_info, root, true, &c->cursor);
if (r) {
DMERR("couldn't create btree cursor");
return r;
}
return load_ablock(c);
}
void dm_array_cursor_end(struct dm_array_cursor *c)
{
if (c->block) {
unlock_ablock(c->info, c->block);
dm_btree_cursor_end(&c->cursor);
}
}
int dm_array_cursor_next(struct dm_array_cursor *c)
{
int r;
if (!c->block)
return -ENODATA;
c->index++;
if (c->index >= le32_to_cpu(c->ab->nr_entries)) {
r = dm_btree_cursor_next(&c->cursor);
if (r)
return r;
r = load_ablock(c);
if (r)
return r;
}
return 0;
}
void dm_array_cursor_get_value(struct dm_array_cursor *c, void **value_le)
{
*value_le = element_at(c->info, c->ab, c->index);
}
