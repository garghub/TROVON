static struct dm_exception_store_type *__find_exception_store_type(const char *name)
{
struct dm_exception_store_type *type;
list_for_each_entry(type, &_exception_store_types, list)
if (!strcmp(name, type->name))
return type;
return NULL;
}
static struct dm_exception_store_type *_get_exception_store_type(const char *name)
{
struct dm_exception_store_type *type;
spin_lock(&_lock);
type = __find_exception_store_type(name);
if (type && !try_module_get(type->module))
type = NULL;
spin_unlock(&_lock);
return type;
}
static struct dm_exception_store_type *get_type(const char *type_name)
{
char *p, *type_name_dup;
struct dm_exception_store_type *type;
type = _get_exception_store_type(type_name);
if (type)
return type;
type_name_dup = kstrdup(type_name, GFP_KERNEL);
if (!type_name_dup) {
DMERR("No memory left to attempt load for \"%s\"", type_name);
return NULL;
}
while (request_module("dm-exstore-%s", type_name_dup) ||
!(type = _get_exception_store_type(type_name))) {
p = strrchr(type_name_dup, '-');
if (!p)
break;
p[0] = '\0';
}
if (!type)
DMWARN("Module for exstore type \"%s\" not found.", type_name);
kfree(type_name_dup);
return type;
}
static void put_type(struct dm_exception_store_type *type)
{
spin_lock(&_lock);
module_put(type->module);
spin_unlock(&_lock);
}
int dm_exception_store_type_register(struct dm_exception_store_type *type)
{
int r = 0;
spin_lock(&_lock);
if (!__find_exception_store_type(type->name))
list_add(&type->list, &_exception_store_types);
else
r = -EEXIST;
spin_unlock(&_lock);
return r;
}
int dm_exception_store_type_unregister(struct dm_exception_store_type *type)
{
spin_lock(&_lock);
if (!__find_exception_store_type(type->name)) {
spin_unlock(&_lock);
return -EINVAL;
}
list_del(&type->list);
spin_unlock(&_lock);
return 0;
}
static int set_chunk_size(struct dm_exception_store *store,
const char *chunk_size_arg, char **error)
{
unsigned chunk_size;
if (kstrtouint(chunk_size_arg, 10, &chunk_size)) {
*error = "Invalid chunk size";
return -EINVAL;
}
if (!chunk_size) {
store->chunk_size = store->chunk_mask = store->chunk_shift = 0;
return 0;
}
return dm_exception_store_set_chunk_size(store, chunk_size, error);
}
int dm_exception_store_set_chunk_size(struct dm_exception_store *store,
unsigned chunk_size,
char **error)
{
if (!is_power_of_2(chunk_size)) {
*error = "Chunk size is not a power of 2";
return -EINVAL;
}
if (chunk_size %
(bdev_logical_block_size(dm_snap_cow(store->snap)->bdev) >> 9) ||
chunk_size %
(bdev_logical_block_size(dm_snap_origin(store->snap)->bdev) >> 9)) {
*error = "Chunk size is not a multiple of device blocksize";
return -EINVAL;
}
if (chunk_size > INT_MAX >> SECTOR_SHIFT) {
*error = "Chunk size is too high";
return -EINVAL;
}
store->chunk_size = chunk_size;
store->chunk_mask = chunk_size - 1;
store->chunk_shift = ffs(chunk_size) - 1;
return 0;
}
int dm_exception_store_create(struct dm_target *ti, int argc, char **argv,
struct dm_snapshot *snap,
unsigned *args_used,
struct dm_exception_store **store)
{
int r = 0;
struct dm_exception_store_type *type = NULL;
struct dm_exception_store *tmp_store;
char persistent;
if (argc < 2) {
ti->error = "Insufficient exception store arguments";
return -EINVAL;
}
tmp_store = kzalloc(sizeof(*tmp_store), GFP_KERNEL);
if (!tmp_store) {
ti->error = "Exception store allocation failed";
return -ENOMEM;
}
persistent = toupper(*argv[0]);
if (persistent == 'P')
type = get_type("P");
else if (persistent == 'N')
type = get_type("N");
else {
ti->error = "Exception store type is not P or N";
r = -EINVAL;
goto bad_type;
}
if (!type) {
ti->error = "Exception store type not recognised";
r = -EINVAL;
goto bad_type;
}
tmp_store->type = type;
tmp_store->snap = snap;
r = set_chunk_size(tmp_store, argv[1], &ti->error);
if (r)
goto bad;
r = type->ctr(tmp_store, (strlen(argv[0]) > 1 ? &argv[0][1] : NULL));
if (r) {
ti->error = "Exception store type constructor failed";
goto bad;
}
*args_used = 2;
*store = tmp_store;
return 0;
bad:
put_type(type);
bad_type:
kfree(tmp_store);
return r;
}
void dm_exception_store_destroy(struct dm_exception_store *store)
{
store->type->dtr(store);
put_type(store->type);
kfree(store);
}
int dm_exception_store_init(void)
{
int r;
r = dm_transient_snapshot_init();
if (r) {
DMERR("Unable to register transient exception store type.");
goto transient_fail;
}
r = dm_persistent_snapshot_init();
if (r) {
DMERR("Unable to register persistent exception store type");
goto persistent_fail;
}
return 0;
persistent_fail:
dm_transient_snapshot_exit();
transient_fail:
return r;
}
void dm_exception_store_exit(void)
{
dm_persistent_snapshot_exit();
dm_transient_snapshot_exit();
}
