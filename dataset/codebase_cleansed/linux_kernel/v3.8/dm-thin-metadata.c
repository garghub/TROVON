static void sb_prepare_for_write(struct dm_block_validator *v,
struct dm_block *b,
size_t block_size)
{
struct thin_disk_superblock *disk_super = dm_block_data(b);
disk_super->blocknr = cpu_to_le64(dm_block_location(b));
disk_super->csum = cpu_to_le32(dm_bm_checksum(&disk_super->flags,
block_size - sizeof(__le32),
SUPERBLOCK_CSUM_XOR));
}
static int sb_check(struct dm_block_validator *v,
struct dm_block *b,
size_t block_size)
{
struct thin_disk_superblock *disk_super = dm_block_data(b);
__le32 csum_le;
if (dm_block_location(b) != le64_to_cpu(disk_super->blocknr)) {
DMERR("sb_check failed: blocknr %llu: "
"wanted %llu", le64_to_cpu(disk_super->blocknr),
(unsigned long long)dm_block_location(b));
return -ENOTBLK;
}
if (le64_to_cpu(disk_super->magic) != THIN_SUPERBLOCK_MAGIC) {
DMERR("sb_check failed: magic %llu: "
"wanted %llu", le64_to_cpu(disk_super->magic),
(unsigned long long)THIN_SUPERBLOCK_MAGIC);
return -EILSEQ;
}
csum_le = cpu_to_le32(dm_bm_checksum(&disk_super->flags,
block_size - sizeof(__le32),
SUPERBLOCK_CSUM_XOR));
if (csum_le != disk_super->csum) {
DMERR("sb_check failed: csum %u: wanted %u",
le32_to_cpu(csum_le), le32_to_cpu(disk_super->csum));
return -EILSEQ;
}
return 0;
}
static uint64_t pack_block_time(dm_block_t b, uint32_t t)
{
return (b << 24) | t;
}
static void unpack_block_time(uint64_t v, dm_block_t *b, uint32_t *t)
{
*b = v >> 24;
*t = v & ((1 << 24) - 1);
}
static void data_block_inc(void *context, void *value_le)
{
struct dm_space_map *sm = context;
__le64 v_le;
uint64_t b;
uint32_t t;
memcpy(&v_le, value_le, sizeof(v_le));
unpack_block_time(le64_to_cpu(v_le), &b, &t);
dm_sm_inc_block(sm, b);
}
static void data_block_dec(void *context, void *value_le)
{
struct dm_space_map *sm = context;
__le64 v_le;
uint64_t b;
uint32_t t;
memcpy(&v_le, value_le, sizeof(v_le));
unpack_block_time(le64_to_cpu(v_le), &b, &t);
dm_sm_dec_block(sm, b);
}
static int data_block_equal(void *context, void *value1_le, void *value2_le)
{
__le64 v1_le, v2_le;
uint64_t b1, b2;
uint32_t t;
memcpy(&v1_le, value1_le, sizeof(v1_le));
memcpy(&v2_le, value2_le, sizeof(v2_le));
unpack_block_time(le64_to_cpu(v1_le), &b1, &t);
unpack_block_time(le64_to_cpu(v2_le), &b2, &t);
return b1 == b2;
}
static void subtree_inc(void *context, void *value)
{
struct dm_btree_info *info = context;
__le64 root_le;
uint64_t root;
memcpy(&root_le, value, sizeof(root_le));
root = le64_to_cpu(root_le);
dm_tm_inc(info->tm, root);
}
static void subtree_dec(void *context, void *value)
{
struct dm_btree_info *info = context;
__le64 root_le;
uint64_t root;
memcpy(&root_le, value, sizeof(root_le));
root = le64_to_cpu(root_le);
if (dm_btree_del(info, root))
DMERR("btree delete failed\n");
}
static int subtree_equal(void *context, void *value1_le, void *value2_le)
{
__le64 v1_le, v2_le;
memcpy(&v1_le, value1_le, sizeof(v1_le));
memcpy(&v2_le, value2_le, sizeof(v2_le));
return v1_le == v2_le;
}
static int superblock_lock_zero(struct dm_pool_metadata *pmd,
struct dm_block **sblock)
{
return dm_bm_write_lock_zero(pmd->bm, THIN_SUPERBLOCK_LOCATION,
&sb_validator, sblock);
}
static int superblock_lock(struct dm_pool_metadata *pmd,
struct dm_block **sblock)
{
return dm_bm_write_lock(pmd->bm, THIN_SUPERBLOCK_LOCATION,
&sb_validator, sblock);
}
static int __superblock_all_zeroes(struct dm_block_manager *bm, int *result)
{
int r;
unsigned i;
struct dm_block *b;
__le64 *data_le, zero = cpu_to_le64(0);
unsigned block_size = dm_bm_block_size(bm) / sizeof(__le64);
r = dm_bm_read_lock(bm, THIN_SUPERBLOCK_LOCATION, NULL, &b);
if (r)
return r;
data_le = dm_block_data(b);
*result = 1;
for (i = 0; i < block_size; i++) {
if (data_le[i] != zero) {
*result = 0;
break;
}
}
return dm_bm_unlock(b);
}
static void __setup_btree_details(struct dm_pool_metadata *pmd)
{
pmd->info.tm = pmd->tm;
pmd->info.levels = 2;
pmd->info.value_type.context = pmd->data_sm;
pmd->info.value_type.size = sizeof(__le64);
pmd->info.value_type.inc = data_block_inc;
pmd->info.value_type.dec = data_block_dec;
pmd->info.value_type.equal = data_block_equal;
memcpy(&pmd->nb_info, &pmd->info, sizeof(pmd->nb_info));
pmd->nb_info.tm = pmd->nb_tm;
pmd->tl_info.tm = pmd->tm;
pmd->tl_info.levels = 1;
pmd->tl_info.value_type.context = &pmd->bl_info;
pmd->tl_info.value_type.size = sizeof(__le64);
pmd->tl_info.value_type.inc = subtree_inc;
pmd->tl_info.value_type.dec = subtree_dec;
pmd->tl_info.value_type.equal = subtree_equal;
pmd->bl_info.tm = pmd->tm;
pmd->bl_info.levels = 1;
pmd->bl_info.value_type.context = pmd->data_sm;
pmd->bl_info.value_type.size = sizeof(__le64);
pmd->bl_info.value_type.inc = data_block_inc;
pmd->bl_info.value_type.dec = data_block_dec;
pmd->bl_info.value_type.equal = data_block_equal;
pmd->details_info.tm = pmd->tm;
pmd->details_info.levels = 1;
pmd->details_info.value_type.context = NULL;
pmd->details_info.value_type.size = sizeof(struct disk_device_details);
pmd->details_info.value_type.inc = NULL;
pmd->details_info.value_type.dec = NULL;
pmd->details_info.value_type.equal = NULL;
}
static int __write_initial_superblock(struct dm_pool_metadata *pmd)
{
int r;
struct dm_block *sblock;
size_t metadata_len, data_len;
struct thin_disk_superblock *disk_super;
sector_t bdev_size = i_size_read(pmd->bdev->bd_inode) >> SECTOR_SHIFT;
if (bdev_size > THIN_METADATA_MAX_SECTORS)
bdev_size = THIN_METADATA_MAX_SECTORS;
r = dm_sm_root_size(pmd->metadata_sm, &metadata_len);
if (r < 0)
return r;
r = dm_sm_root_size(pmd->data_sm, &data_len);
if (r < 0)
return r;
r = dm_sm_commit(pmd->data_sm);
if (r < 0)
return r;
r = dm_tm_pre_commit(pmd->tm);
if (r < 0)
return r;
r = superblock_lock_zero(pmd, &sblock);
if (r)
return r;
disk_super = dm_block_data(sblock);
disk_super->flags = 0;
memset(disk_super->uuid, 0, sizeof(disk_super->uuid));
disk_super->magic = cpu_to_le64(THIN_SUPERBLOCK_MAGIC);
disk_super->version = cpu_to_le32(THIN_VERSION);
disk_super->time = 0;
disk_super->trans_id = 0;
disk_super->held_root = 0;
r = dm_sm_copy_root(pmd->metadata_sm, &disk_super->metadata_space_map_root,
metadata_len);
if (r < 0)
goto bad_locked;
r = dm_sm_copy_root(pmd->data_sm, &disk_super->data_space_map_root,
data_len);
if (r < 0)
goto bad_locked;
disk_super->data_mapping_root = cpu_to_le64(pmd->root);
disk_super->device_details_root = cpu_to_le64(pmd->details_root);
disk_super->metadata_block_size = cpu_to_le32(THIN_METADATA_BLOCK_SIZE >> SECTOR_SHIFT);
disk_super->metadata_nr_blocks = cpu_to_le64(bdev_size >> SECTOR_TO_BLOCK_SHIFT);
disk_super->data_block_size = cpu_to_le32(pmd->data_block_size);
return dm_tm_commit(pmd->tm, sblock);
bad_locked:
dm_bm_unlock(sblock);
return r;
}
static int __format_metadata(struct dm_pool_metadata *pmd)
{
int r;
r = dm_tm_create_with_sm(pmd->bm, THIN_SUPERBLOCK_LOCATION,
&pmd->tm, &pmd->metadata_sm);
if (r < 0) {
DMERR("tm_create_with_sm failed");
return r;
}
pmd->data_sm = dm_sm_disk_create(pmd->tm, 0);
if (IS_ERR(pmd->data_sm)) {
DMERR("sm_disk_create failed");
r = PTR_ERR(pmd->data_sm);
goto bad_cleanup_tm;
}
pmd->nb_tm = dm_tm_create_non_blocking_clone(pmd->tm);
if (!pmd->nb_tm) {
DMERR("could not create non-blocking clone tm");
r = -ENOMEM;
goto bad_cleanup_data_sm;
}
__setup_btree_details(pmd);
r = dm_btree_empty(&pmd->info, &pmd->root);
if (r < 0)
goto bad_cleanup_nb_tm;
r = dm_btree_empty(&pmd->details_info, &pmd->details_root);
if (r < 0) {
DMERR("couldn't create devices root");
goto bad_cleanup_nb_tm;
}
r = __write_initial_superblock(pmd);
if (r)
goto bad_cleanup_nb_tm;
return 0;
bad_cleanup_nb_tm:
dm_tm_destroy(pmd->nb_tm);
bad_cleanup_data_sm:
dm_sm_destroy(pmd->data_sm);
bad_cleanup_tm:
dm_tm_destroy(pmd->tm);
dm_sm_destroy(pmd->metadata_sm);
return r;
}
static int __check_incompat_features(struct thin_disk_superblock *disk_super,
struct dm_pool_metadata *pmd)
{
uint32_t features;
features = le32_to_cpu(disk_super->incompat_flags) & ~THIN_FEATURE_INCOMPAT_SUPP;
if (features) {
DMERR("could not access metadata due to unsupported optional features (%lx).",
(unsigned long)features);
return -EINVAL;
}
if (get_disk_ro(pmd->bdev->bd_disk))
return 0;
features = le32_to_cpu(disk_super->compat_ro_flags) & ~THIN_FEATURE_COMPAT_RO_SUPP;
if (features) {
DMERR("could not access metadata RDWR due to unsupported optional features (%lx).",
(unsigned long)features);
return -EINVAL;
}
return 0;
}
static int __open_metadata(struct dm_pool_metadata *pmd)
{
int r;
struct dm_block *sblock;
struct thin_disk_superblock *disk_super;
r = dm_bm_read_lock(pmd->bm, THIN_SUPERBLOCK_LOCATION,
&sb_validator, &sblock);
if (r < 0) {
DMERR("couldn't read superblock");
return r;
}
disk_super = dm_block_data(sblock);
r = __check_incompat_features(disk_super, pmd);
if (r < 0)
goto bad_unlock_sblock;
r = dm_tm_open_with_sm(pmd->bm, THIN_SUPERBLOCK_LOCATION,
disk_super->metadata_space_map_root,
sizeof(disk_super->metadata_space_map_root),
&pmd->tm, &pmd->metadata_sm);
if (r < 0) {
DMERR("tm_open_with_sm failed");
goto bad_unlock_sblock;
}
pmd->data_sm = dm_sm_disk_open(pmd->tm, disk_super->data_space_map_root,
sizeof(disk_super->data_space_map_root));
if (IS_ERR(pmd->data_sm)) {
DMERR("sm_disk_open failed");
r = PTR_ERR(pmd->data_sm);
goto bad_cleanup_tm;
}
pmd->nb_tm = dm_tm_create_non_blocking_clone(pmd->tm);
if (!pmd->nb_tm) {
DMERR("could not create non-blocking clone tm");
r = -ENOMEM;
goto bad_cleanup_data_sm;
}
__setup_btree_details(pmd);
return dm_bm_unlock(sblock);
bad_cleanup_data_sm:
dm_sm_destroy(pmd->data_sm);
bad_cleanup_tm:
dm_tm_destroy(pmd->tm);
dm_sm_destroy(pmd->metadata_sm);
bad_unlock_sblock:
dm_bm_unlock(sblock);
return r;
}
static int __open_or_format_metadata(struct dm_pool_metadata *pmd, bool format_device)
{
int r, unformatted;
r = __superblock_all_zeroes(pmd->bm, &unformatted);
if (r)
return r;
if (unformatted)
return format_device ? __format_metadata(pmd) : -EPERM;
return __open_metadata(pmd);
}
static int __create_persistent_data_objects(struct dm_pool_metadata *pmd, bool format_device)
{
int r;
pmd->bm = dm_block_manager_create(pmd->bdev, THIN_METADATA_BLOCK_SIZE,
THIN_METADATA_CACHE_SIZE,
THIN_MAX_CONCURRENT_LOCKS);
if (IS_ERR(pmd->bm)) {
DMERR("could not create block manager");
return PTR_ERR(pmd->bm);
}
r = __open_or_format_metadata(pmd, format_device);
if (r)
dm_block_manager_destroy(pmd->bm);
return r;
}
static void __destroy_persistent_data_objects(struct dm_pool_metadata *pmd)
{
dm_sm_destroy(pmd->data_sm);
dm_sm_destroy(pmd->metadata_sm);
dm_tm_destroy(pmd->nb_tm);
dm_tm_destroy(pmd->tm);
dm_block_manager_destroy(pmd->bm);
}
static int __begin_transaction(struct dm_pool_metadata *pmd)
{
int r;
struct thin_disk_superblock *disk_super;
struct dm_block *sblock;
r = dm_bm_read_lock(pmd->bm, THIN_SUPERBLOCK_LOCATION,
&sb_validator, &sblock);
if (r)
return r;
disk_super = dm_block_data(sblock);
pmd->time = le32_to_cpu(disk_super->time);
pmd->root = le64_to_cpu(disk_super->data_mapping_root);
pmd->details_root = le64_to_cpu(disk_super->device_details_root);
pmd->trans_id = le64_to_cpu(disk_super->trans_id);
pmd->flags = le32_to_cpu(disk_super->flags);
pmd->data_block_size = le32_to_cpu(disk_super->data_block_size);
dm_bm_unlock(sblock);
return 0;
}
static int __write_changed_details(struct dm_pool_metadata *pmd)
{
int r;
struct dm_thin_device *td, *tmp;
struct disk_device_details details;
uint64_t key;
list_for_each_entry_safe(td, tmp, &pmd->thin_devices, list) {
if (!td->changed)
continue;
key = td->id;
details.mapped_blocks = cpu_to_le64(td->mapped_blocks);
details.transaction_id = cpu_to_le64(td->transaction_id);
details.creation_time = cpu_to_le32(td->creation_time);
details.snapshotted_time = cpu_to_le32(td->snapshotted_time);
__dm_bless_for_disk(&details);
r = dm_btree_insert(&pmd->details_info, pmd->details_root,
&key, &details, &pmd->details_root);
if (r)
return r;
if (td->open_count)
td->changed = 0;
else {
list_del(&td->list);
kfree(td);
}
}
return 0;
}
static int __commit_transaction(struct dm_pool_metadata *pmd)
{
int r;
size_t metadata_len, data_len;
struct thin_disk_superblock *disk_super;
struct dm_block *sblock;
BUILD_BUG_ON(sizeof(struct thin_disk_superblock) > 512);
r = __write_changed_details(pmd);
if (r < 0)
return r;
r = dm_sm_commit(pmd->data_sm);
if (r < 0)
return r;
r = dm_tm_pre_commit(pmd->tm);
if (r < 0)
return r;
r = dm_sm_root_size(pmd->metadata_sm, &metadata_len);
if (r < 0)
return r;
r = dm_sm_root_size(pmd->data_sm, &data_len);
if (r < 0)
return r;
r = superblock_lock(pmd, &sblock);
if (r)
return r;
disk_super = dm_block_data(sblock);
disk_super->time = cpu_to_le32(pmd->time);
disk_super->data_mapping_root = cpu_to_le64(pmd->root);
disk_super->device_details_root = cpu_to_le64(pmd->details_root);
disk_super->trans_id = cpu_to_le64(pmd->trans_id);
disk_super->flags = cpu_to_le32(pmd->flags);
r = dm_sm_copy_root(pmd->metadata_sm, &disk_super->metadata_space_map_root,
metadata_len);
if (r < 0)
goto out_locked;
r = dm_sm_copy_root(pmd->data_sm, &disk_super->data_space_map_root,
data_len);
if (r < 0)
goto out_locked;
return dm_tm_commit(pmd->tm, sblock);
out_locked:
dm_bm_unlock(sblock);
return r;
}
struct dm_pool_metadata *dm_pool_metadata_open(struct block_device *bdev,
sector_t data_block_size,
bool format_device)
{
int r;
struct dm_pool_metadata *pmd;
pmd = kmalloc(sizeof(*pmd), GFP_KERNEL);
if (!pmd) {
DMERR("could not allocate metadata struct");
return ERR_PTR(-ENOMEM);
}
init_rwsem(&pmd->root_lock);
pmd->time = 0;
INIT_LIST_HEAD(&pmd->thin_devices);
pmd->read_only = false;
pmd->fail_io = false;
pmd->bdev = bdev;
pmd->data_block_size = data_block_size;
r = __create_persistent_data_objects(pmd, format_device);
if (r) {
kfree(pmd);
return ERR_PTR(r);
}
r = __begin_transaction(pmd);
if (r < 0) {
if (dm_pool_metadata_close(pmd) < 0)
DMWARN("%s: dm_pool_metadata_close() failed.", __func__);
return ERR_PTR(r);
}
return pmd;
}
int dm_pool_metadata_close(struct dm_pool_metadata *pmd)
{
int r;
unsigned open_devices = 0;
struct dm_thin_device *td, *tmp;
down_read(&pmd->root_lock);
list_for_each_entry_safe(td, tmp, &pmd->thin_devices, list) {
if (td->open_count)
open_devices++;
else {
list_del(&td->list);
kfree(td);
}
}
up_read(&pmd->root_lock);
if (open_devices) {
DMERR("attempt to close pmd when %u device(s) are still open",
open_devices);
return -EBUSY;
}
if (!pmd->read_only && !pmd->fail_io) {
r = __commit_transaction(pmd);
if (r < 0)
DMWARN("%s: __commit_transaction() failed, error = %d",
__func__, r);
}
if (!pmd->fail_io)
__destroy_persistent_data_objects(pmd);
kfree(pmd);
return 0;
}
static int __open_device(struct dm_pool_metadata *pmd,
dm_thin_id dev, int create,
struct dm_thin_device **td)
{
int r, changed = 0;
struct dm_thin_device *td2;
uint64_t key = dev;
struct disk_device_details details_le;
list_for_each_entry(td2, &pmd->thin_devices, list)
if (td2->id == dev) {
if (create)
return -EEXIST;
td2->open_count++;
*td = td2;
return 0;
}
r = dm_btree_lookup(&pmd->details_info, pmd->details_root,
&key, &details_le);
if (r) {
if (r != -ENODATA || !create)
return r;
changed = 1;
details_le.mapped_blocks = 0;
details_le.transaction_id = cpu_to_le64(pmd->trans_id);
details_le.creation_time = cpu_to_le32(pmd->time);
details_le.snapshotted_time = cpu_to_le32(pmd->time);
}
*td = kmalloc(sizeof(**td), GFP_NOIO);
if (!*td)
return -ENOMEM;
(*td)->pmd = pmd;
(*td)->id = dev;
(*td)->open_count = 1;
(*td)->changed = changed;
(*td)->aborted_with_changes = false;
(*td)->mapped_blocks = le64_to_cpu(details_le.mapped_blocks);
(*td)->transaction_id = le64_to_cpu(details_le.transaction_id);
(*td)->creation_time = le32_to_cpu(details_le.creation_time);
(*td)->snapshotted_time = le32_to_cpu(details_le.snapshotted_time);
list_add(&(*td)->list, &pmd->thin_devices);
return 0;
}
static void __close_device(struct dm_thin_device *td)
{
--td->open_count;
}
static int __create_thin(struct dm_pool_metadata *pmd,
dm_thin_id dev)
{
int r;
dm_block_t dev_root;
uint64_t key = dev;
struct disk_device_details details_le;
struct dm_thin_device *td;
__le64 value;
r = dm_btree_lookup(&pmd->details_info, pmd->details_root,
&key, &details_le);
if (!r)
return -EEXIST;
r = dm_btree_empty(&pmd->bl_info, &dev_root);
if (r)
return r;
value = cpu_to_le64(dev_root);
__dm_bless_for_disk(&value);
r = dm_btree_insert(&pmd->tl_info, pmd->root, &key, &value, &pmd->root);
if (r) {
dm_btree_del(&pmd->bl_info, dev_root);
return r;
}
r = __open_device(pmd, dev, 1, &td);
if (r) {
dm_btree_remove(&pmd->tl_info, pmd->root, &key, &pmd->root);
dm_btree_del(&pmd->bl_info, dev_root);
return r;
}
__close_device(td);
return r;
}
int dm_pool_create_thin(struct dm_pool_metadata *pmd, dm_thin_id dev)
{
int r = -EINVAL;
down_write(&pmd->root_lock);
if (!pmd->fail_io)
r = __create_thin(pmd, dev);
up_write(&pmd->root_lock);
return r;
}
static int __set_snapshot_details(struct dm_pool_metadata *pmd,
struct dm_thin_device *snap,
dm_thin_id origin, uint32_t time)
{
int r;
struct dm_thin_device *td;
r = __open_device(pmd, origin, 0, &td);
if (r)
return r;
td->changed = 1;
td->snapshotted_time = time;
snap->mapped_blocks = td->mapped_blocks;
snap->snapshotted_time = time;
__close_device(td);
return 0;
}
static int __create_snap(struct dm_pool_metadata *pmd,
dm_thin_id dev, dm_thin_id origin)
{
int r;
dm_block_t origin_root;
uint64_t key = origin, dev_key = dev;
struct dm_thin_device *td;
struct disk_device_details details_le;
__le64 value;
r = dm_btree_lookup(&pmd->details_info, pmd->details_root,
&dev_key, &details_le);
if (!r)
return -EEXIST;
r = dm_btree_lookup(&pmd->tl_info, pmd->root, &key, &value);
if (r)
return r;
origin_root = le64_to_cpu(value);
dm_tm_inc(pmd->tm, origin_root);
value = cpu_to_le64(origin_root);
__dm_bless_for_disk(&value);
key = dev;
r = dm_btree_insert(&pmd->tl_info, pmd->root, &key, &value, &pmd->root);
if (r) {
dm_tm_dec(pmd->tm, origin_root);
return r;
}
pmd->time++;
r = __open_device(pmd, dev, 1, &td);
if (r)
goto bad;
r = __set_snapshot_details(pmd, td, origin, pmd->time);
__close_device(td);
if (r)
goto bad;
return 0;
bad:
dm_btree_remove(&pmd->tl_info, pmd->root, &key, &pmd->root);
dm_btree_remove(&pmd->details_info, pmd->details_root,
&key, &pmd->details_root);
return r;
}
int dm_pool_create_snap(struct dm_pool_metadata *pmd,
dm_thin_id dev,
dm_thin_id origin)
{
int r = -EINVAL;
down_write(&pmd->root_lock);
if (!pmd->fail_io)
r = __create_snap(pmd, dev, origin);
up_write(&pmd->root_lock);
return r;
}
static int __delete_device(struct dm_pool_metadata *pmd, dm_thin_id dev)
{
int r;
uint64_t key = dev;
struct dm_thin_device *td;
r = __open_device(pmd, dev, 0, &td);
if (r)
return r;
if (td->open_count > 1) {
__close_device(td);
return -EBUSY;
}
list_del(&td->list);
kfree(td);
r = dm_btree_remove(&pmd->details_info, pmd->details_root,
&key, &pmd->details_root);
if (r)
return r;
r = dm_btree_remove(&pmd->tl_info, pmd->root, &key, &pmd->root);
if (r)
return r;
return 0;
}
int dm_pool_delete_thin_device(struct dm_pool_metadata *pmd,
dm_thin_id dev)
{
int r = -EINVAL;
down_write(&pmd->root_lock);
if (!pmd->fail_io)
r = __delete_device(pmd, dev);
up_write(&pmd->root_lock);
return r;
}
int dm_pool_set_metadata_transaction_id(struct dm_pool_metadata *pmd,
uint64_t current_id,
uint64_t new_id)
{
int r = -EINVAL;
down_write(&pmd->root_lock);
if (pmd->fail_io)
goto out;
if (pmd->trans_id != current_id) {
DMERR("mismatched transaction id");
goto out;
}
pmd->trans_id = new_id;
r = 0;
out:
up_write(&pmd->root_lock);
return r;
}
int dm_pool_get_metadata_transaction_id(struct dm_pool_metadata *pmd,
uint64_t *result)
{
int r = -EINVAL;
down_read(&pmd->root_lock);
if (!pmd->fail_io) {
*result = pmd->trans_id;
r = 0;
}
up_read(&pmd->root_lock);
return r;
}
static int __reserve_metadata_snap(struct dm_pool_metadata *pmd)
{
int r, inc;
struct thin_disk_superblock *disk_super;
struct dm_block *copy, *sblock;
dm_block_t held_root;
dm_sm_inc_block(pmd->metadata_sm, THIN_SUPERBLOCK_LOCATION);
r = dm_tm_shadow_block(pmd->tm, THIN_SUPERBLOCK_LOCATION,
&sb_validator, &copy, &inc);
if (r)
return r;
BUG_ON(!inc);
held_root = dm_block_location(copy);
disk_super = dm_block_data(copy);
if (le64_to_cpu(disk_super->held_root)) {
DMWARN("Pool metadata snapshot already exists: release this before taking another.");
dm_tm_dec(pmd->tm, held_root);
dm_tm_unlock(pmd->tm, copy);
return -EBUSY;
}
memset(&disk_super->data_space_map_root, 0,
sizeof(disk_super->data_space_map_root));
memset(&disk_super->metadata_space_map_root, 0,
sizeof(disk_super->metadata_space_map_root));
dm_tm_inc(pmd->tm, le64_to_cpu(disk_super->data_mapping_root));
dm_tm_inc(pmd->tm, le64_to_cpu(disk_super->device_details_root));
dm_tm_unlock(pmd->tm, copy);
r = superblock_lock(pmd, &sblock);
if (r) {
dm_tm_dec(pmd->tm, held_root);
return r;
}
disk_super = dm_block_data(sblock);
disk_super->held_root = cpu_to_le64(held_root);
dm_bm_unlock(sblock);
return 0;
}
int dm_pool_reserve_metadata_snap(struct dm_pool_metadata *pmd)
{
int r = -EINVAL;
down_write(&pmd->root_lock);
if (!pmd->fail_io)
r = __reserve_metadata_snap(pmd);
up_write(&pmd->root_lock);
return r;
}
static int __release_metadata_snap(struct dm_pool_metadata *pmd)
{
int r;
struct thin_disk_superblock *disk_super;
struct dm_block *sblock, *copy;
dm_block_t held_root;
r = superblock_lock(pmd, &sblock);
if (r)
return r;
disk_super = dm_block_data(sblock);
held_root = le64_to_cpu(disk_super->held_root);
disk_super->held_root = cpu_to_le64(0);
dm_bm_unlock(sblock);
if (!held_root) {
DMWARN("No pool metadata snapshot found: nothing to release.");
return -EINVAL;
}
r = dm_tm_read_lock(pmd->tm, held_root, &sb_validator, &copy);
if (r)
return r;
disk_super = dm_block_data(copy);
dm_sm_dec_block(pmd->metadata_sm, le64_to_cpu(disk_super->data_mapping_root));
dm_sm_dec_block(pmd->metadata_sm, le64_to_cpu(disk_super->device_details_root));
dm_sm_dec_block(pmd->metadata_sm, held_root);
return dm_tm_unlock(pmd->tm, copy);
}
int dm_pool_release_metadata_snap(struct dm_pool_metadata *pmd)
{
int r = -EINVAL;
down_write(&pmd->root_lock);
if (!pmd->fail_io)
r = __release_metadata_snap(pmd);
up_write(&pmd->root_lock);
return r;
}
static int __get_metadata_snap(struct dm_pool_metadata *pmd,
dm_block_t *result)
{
int r;
struct thin_disk_superblock *disk_super;
struct dm_block *sblock;
r = dm_bm_read_lock(pmd->bm, THIN_SUPERBLOCK_LOCATION,
&sb_validator, &sblock);
if (r)
return r;
disk_super = dm_block_data(sblock);
*result = le64_to_cpu(disk_super->held_root);
return dm_bm_unlock(sblock);
}
int dm_pool_get_metadata_snap(struct dm_pool_metadata *pmd,
dm_block_t *result)
{
int r = -EINVAL;
down_read(&pmd->root_lock);
if (!pmd->fail_io)
r = __get_metadata_snap(pmd, result);
up_read(&pmd->root_lock);
return r;
}
int dm_pool_open_thin_device(struct dm_pool_metadata *pmd, dm_thin_id dev,
struct dm_thin_device **td)
{
int r = -EINVAL;
down_write(&pmd->root_lock);
if (!pmd->fail_io)
r = __open_device(pmd, dev, 0, td);
up_write(&pmd->root_lock);
return r;
}
int dm_pool_close_thin_device(struct dm_thin_device *td)
{
down_write(&td->pmd->root_lock);
__close_device(td);
up_write(&td->pmd->root_lock);
return 0;
}
dm_thin_id dm_thin_dev_id(struct dm_thin_device *td)
{
return td->id;
}
static bool __snapshotted_since(struct dm_thin_device *td, uint32_t time)
{
return td->snapshotted_time > time;
}
int dm_thin_find_block(struct dm_thin_device *td, dm_block_t block,
int can_block, struct dm_thin_lookup_result *result)
{
int r = -EINVAL;
uint64_t block_time = 0;
__le64 value;
struct dm_pool_metadata *pmd = td->pmd;
dm_block_t keys[2] = { td->id, block };
struct dm_btree_info *info;
if (can_block) {
down_read(&pmd->root_lock);
info = &pmd->info;
} else if (down_read_trylock(&pmd->root_lock))
info = &pmd->nb_info;
else
return -EWOULDBLOCK;
if (pmd->fail_io)
goto out;
r = dm_btree_lookup(info, pmd->root, keys, &value);
if (!r)
block_time = le64_to_cpu(value);
out:
up_read(&pmd->root_lock);
if (!r) {
dm_block_t exception_block;
uint32_t exception_time;
unpack_block_time(block_time, &exception_block,
&exception_time);
result->block = exception_block;
result->shared = __snapshotted_since(td, exception_time);
}
return r;
}
static int __insert(struct dm_thin_device *td, dm_block_t block,
dm_block_t data_block)
{
int r, inserted;
__le64 value;
struct dm_pool_metadata *pmd = td->pmd;
dm_block_t keys[2] = { td->id, block };
value = cpu_to_le64(pack_block_time(data_block, pmd->time));
__dm_bless_for_disk(&value);
r = dm_btree_insert_notify(&pmd->info, pmd->root, keys, &value,
&pmd->root, &inserted);
if (r)
return r;
td->changed = 1;
if (inserted)
td->mapped_blocks++;
return 0;
}
int dm_thin_insert_block(struct dm_thin_device *td, dm_block_t block,
dm_block_t data_block)
{
int r = -EINVAL;
down_write(&td->pmd->root_lock);
if (!td->pmd->fail_io)
r = __insert(td, block, data_block);
up_write(&td->pmd->root_lock);
return r;
}
static int __remove(struct dm_thin_device *td, dm_block_t block)
{
int r;
struct dm_pool_metadata *pmd = td->pmd;
dm_block_t keys[2] = { td->id, block };
r = dm_btree_remove(&pmd->info, pmd->root, keys, &pmd->root);
if (r)
return r;
td->mapped_blocks--;
td->changed = 1;
return 0;
}
int dm_thin_remove_block(struct dm_thin_device *td, dm_block_t block)
{
int r = -EINVAL;
down_write(&td->pmd->root_lock);
if (!td->pmd->fail_io)
r = __remove(td, block);
up_write(&td->pmd->root_lock);
return r;
}
bool dm_thin_changed_this_transaction(struct dm_thin_device *td)
{
int r;
down_read(&td->pmd->root_lock);
r = td->changed;
up_read(&td->pmd->root_lock);
return r;
}
bool dm_thin_aborted_changes(struct dm_thin_device *td)
{
bool r;
down_read(&td->pmd->root_lock);
r = td->aborted_with_changes;
up_read(&td->pmd->root_lock);
return r;
}
int dm_pool_alloc_data_block(struct dm_pool_metadata *pmd, dm_block_t *result)
{
int r = -EINVAL;
down_write(&pmd->root_lock);
if (!pmd->fail_io)
r = dm_sm_new_block(pmd->data_sm, result);
up_write(&pmd->root_lock);
return r;
}
int dm_pool_commit_metadata(struct dm_pool_metadata *pmd)
{
int r = -EINVAL;
down_write(&pmd->root_lock);
if (pmd->fail_io)
goto out;
r = __commit_transaction(pmd);
if (r <= 0)
goto out;
r = __begin_transaction(pmd);
out:
up_write(&pmd->root_lock);
return r;
}
static void __set_abort_with_changes_flags(struct dm_pool_metadata *pmd)
{
struct dm_thin_device *td;
list_for_each_entry(td, &pmd->thin_devices, list)
td->aborted_with_changes = td->changed;
}
int dm_pool_abort_metadata(struct dm_pool_metadata *pmd)
{
int r = -EINVAL;
down_write(&pmd->root_lock);
if (pmd->fail_io)
goto out;
__set_abort_with_changes_flags(pmd);
__destroy_persistent_data_objects(pmd);
r = __create_persistent_data_objects(pmd, false);
if (r)
pmd->fail_io = true;
out:
up_write(&pmd->root_lock);
return r;
}
int dm_pool_get_free_block_count(struct dm_pool_metadata *pmd, dm_block_t *result)
{
int r = -EINVAL;
down_read(&pmd->root_lock);
if (!pmd->fail_io)
r = dm_sm_get_nr_free(pmd->data_sm, result);
up_read(&pmd->root_lock);
return r;
}
int dm_pool_get_free_metadata_block_count(struct dm_pool_metadata *pmd,
dm_block_t *result)
{
int r = -EINVAL;
down_read(&pmd->root_lock);
if (!pmd->fail_io)
r = dm_sm_get_nr_free(pmd->metadata_sm, result);
up_read(&pmd->root_lock);
return r;
}
int dm_pool_get_metadata_dev_size(struct dm_pool_metadata *pmd,
dm_block_t *result)
{
int r = -EINVAL;
down_read(&pmd->root_lock);
if (!pmd->fail_io)
r = dm_sm_get_nr_blocks(pmd->metadata_sm, result);
up_read(&pmd->root_lock);
return r;
}
int dm_pool_get_data_block_size(struct dm_pool_metadata *pmd, sector_t *result)
{
down_read(&pmd->root_lock);
*result = pmd->data_block_size;
up_read(&pmd->root_lock);
return 0;
}
int dm_pool_get_data_dev_size(struct dm_pool_metadata *pmd, dm_block_t *result)
{
int r = -EINVAL;
down_read(&pmd->root_lock);
if (!pmd->fail_io)
r = dm_sm_get_nr_blocks(pmd->data_sm, result);
up_read(&pmd->root_lock);
return r;
}
int dm_thin_get_mapped_count(struct dm_thin_device *td, dm_block_t *result)
{
int r = -EINVAL;
struct dm_pool_metadata *pmd = td->pmd;
down_read(&pmd->root_lock);
if (!pmd->fail_io) {
*result = td->mapped_blocks;
r = 0;
}
up_read(&pmd->root_lock);
return r;
}
static int __highest_block(struct dm_thin_device *td, dm_block_t *result)
{
int r;
__le64 value_le;
dm_block_t thin_root;
struct dm_pool_metadata *pmd = td->pmd;
r = dm_btree_lookup(&pmd->tl_info, pmd->root, &td->id, &value_le);
if (r)
return r;
thin_root = le64_to_cpu(value_le);
return dm_btree_find_highest_key(&pmd->bl_info, thin_root, result);
}
int dm_thin_get_highest_mapped_block(struct dm_thin_device *td,
dm_block_t *result)
{
int r = -EINVAL;
struct dm_pool_metadata *pmd = td->pmd;
down_read(&pmd->root_lock);
if (!pmd->fail_io)
r = __highest_block(td, result);
up_read(&pmd->root_lock);
return r;
}
static int __resize_data_dev(struct dm_pool_metadata *pmd, dm_block_t new_count)
{
int r;
dm_block_t old_count;
r = dm_sm_get_nr_blocks(pmd->data_sm, &old_count);
if (r)
return r;
if (new_count == old_count)
return 0;
if (new_count < old_count) {
DMERR("cannot reduce size of data device");
return -EINVAL;
}
return dm_sm_extend(pmd->data_sm, new_count - old_count);
}
int dm_pool_resize_data_dev(struct dm_pool_metadata *pmd, dm_block_t new_count)
{
int r = -EINVAL;
down_write(&pmd->root_lock);
if (!pmd->fail_io)
r = __resize_data_dev(pmd, new_count);
up_write(&pmd->root_lock);
return r;
}
void dm_pool_metadata_read_only(struct dm_pool_metadata *pmd)
{
down_write(&pmd->root_lock);
pmd->read_only = true;
dm_bm_set_read_only(pmd->bm);
up_write(&pmd->root_lock);
}
