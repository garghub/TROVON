void dm_disk_bitset_init(struct dm_transaction_manager *tm,
struct dm_disk_bitset *info)
{
dm_array_info_init(&info->array_info, tm, &bitset_bvt);
info->current_index_set = false;
}
int dm_bitset_empty(struct dm_disk_bitset *info, dm_block_t *root)
{
return dm_array_empty(&info->array_info, root);
}
int dm_bitset_resize(struct dm_disk_bitset *info, dm_block_t root,
uint32_t old_nr_entries, uint32_t new_nr_entries,
bool default_value, dm_block_t *new_root)
{
uint32_t old_blocks = dm_div_up(old_nr_entries, BITS_PER_ARRAY_ENTRY);
uint32_t new_blocks = dm_div_up(new_nr_entries, BITS_PER_ARRAY_ENTRY);
__le64 value = default_value ? cpu_to_le64(~0) : cpu_to_le64(0);
__dm_bless_for_disk(&value);
return dm_array_resize(&info->array_info, root, old_blocks, new_blocks,
&value, new_root);
}
int dm_bitset_del(struct dm_disk_bitset *info, dm_block_t root)
{
return dm_array_del(&info->array_info, root);
}
int dm_bitset_flush(struct dm_disk_bitset *info, dm_block_t root,
dm_block_t *new_root)
{
int r;
__le64 value;
if (!info->current_index_set)
return 0;
value = cpu_to_le64(info->current_bits);
__dm_bless_for_disk(&value);
r = dm_array_set_value(&info->array_info, root, info->current_index,
&value, new_root);
if (r)
return r;
info->current_index_set = false;
return 0;
}
static int read_bits(struct dm_disk_bitset *info, dm_block_t root,
uint32_t array_index)
{
int r;
__le64 value;
r = dm_array_get_value(&info->array_info, root, array_index, &value);
if (r)
return r;
info->current_bits = le64_to_cpu(value);
info->current_index_set = true;
info->current_index = array_index;
return 0;
}
static int get_array_entry(struct dm_disk_bitset *info, dm_block_t root,
uint32_t index, dm_block_t *new_root)
{
int r;
unsigned array_index = index / BITS_PER_ARRAY_ENTRY;
if (info->current_index_set) {
if (info->current_index == array_index)
return 0;
r = dm_bitset_flush(info, root, new_root);
if (r)
return r;
}
return read_bits(info, root, array_index);
}
int dm_bitset_set_bit(struct dm_disk_bitset *info, dm_block_t root,
uint32_t index, dm_block_t *new_root)
{
int r;
unsigned b = index % BITS_PER_ARRAY_ENTRY;
r = get_array_entry(info, root, index, new_root);
if (r)
return r;
set_bit(b, (unsigned long *) &info->current_bits);
return 0;
}
int dm_bitset_clear_bit(struct dm_disk_bitset *info, dm_block_t root,
uint32_t index, dm_block_t *new_root)
{
int r;
unsigned b = index % BITS_PER_ARRAY_ENTRY;
r = get_array_entry(info, root, index, new_root);
if (r)
return r;
clear_bit(b, (unsigned long *) &info->current_bits);
return 0;
}
int dm_bitset_test_bit(struct dm_disk_bitset *info, dm_block_t root,
uint32_t index, dm_block_t *new_root, bool *result)
{
int r;
unsigned b = index % BITS_PER_ARRAY_ENTRY;
r = get_array_entry(info, root, index, new_root);
if (r)
return r;
*result = test_bit(b, (unsigned long *) &info->current_bits);
return 0;
}
