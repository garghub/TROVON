void zpool_register_driver(struct zpool_driver *driver)
{
spin_lock(&drivers_lock);
atomic_set(&driver->refcount, 0);
list_add(&driver->list, &drivers_head);
spin_unlock(&drivers_lock);
}
int zpool_unregister_driver(struct zpool_driver *driver)
{
int ret = 0, refcount;
spin_lock(&drivers_lock);
refcount = atomic_read(&driver->refcount);
WARN_ON(refcount < 0);
if (refcount > 0)
ret = -EBUSY;
else
list_del(&driver->list);
spin_unlock(&drivers_lock);
return ret;
}
static struct zpool_driver *zpool_get_driver(const char *type)
{
struct zpool_driver *driver;
spin_lock(&drivers_lock);
list_for_each_entry(driver, &drivers_head, list) {
if (!strcmp(driver->type, type)) {
bool got = try_module_get(driver->owner);
if (got)
atomic_inc(&driver->refcount);
spin_unlock(&drivers_lock);
return got ? driver : NULL;
}
}
spin_unlock(&drivers_lock);
return NULL;
}
static void zpool_put_driver(struct zpool_driver *driver)
{
atomic_dec(&driver->refcount);
module_put(driver->owner);
}
bool zpool_has_pool(char *type)
{
struct zpool_driver *driver = zpool_get_driver(type);
if (!driver) {
request_module("zpool-%s", type);
driver = zpool_get_driver(type);
}
if (!driver)
return false;
zpool_put_driver(driver);
return true;
}
struct zpool *zpool_create_pool(const char *type, const char *name, gfp_t gfp,
const struct zpool_ops *ops)
{
struct zpool_driver *driver;
struct zpool *zpool;
pr_debug("creating pool type %s\n", type);
driver = zpool_get_driver(type);
if (!driver) {
request_module("zpool-%s", type);
driver = zpool_get_driver(type);
}
if (!driver) {
pr_err("no driver for type %s\n", type);
return NULL;
}
zpool = kmalloc(sizeof(*zpool), gfp);
if (!zpool) {
pr_err("couldn't create zpool - out of memory\n");
zpool_put_driver(driver);
return NULL;
}
zpool->driver = driver;
zpool->pool = driver->create(name, gfp, ops, zpool);
zpool->ops = ops;
if (!zpool->pool) {
pr_err("couldn't create %s pool\n", type);
zpool_put_driver(driver);
kfree(zpool);
return NULL;
}
pr_debug("created pool type %s\n", type);
spin_lock(&pools_lock);
list_add(&zpool->list, &pools_head);
spin_unlock(&pools_lock);
return zpool;
}
void zpool_destroy_pool(struct zpool *zpool)
{
pr_debug("destroying pool type %s\n", zpool->driver->type);
spin_lock(&pools_lock);
list_del(&zpool->list);
spin_unlock(&pools_lock);
zpool->driver->destroy(zpool->pool);
zpool_put_driver(zpool->driver);
kfree(zpool);
}
const char *zpool_get_type(struct zpool *zpool)
{
return zpool->driver->type;
}
int zpool_malloc(struct zpool *zpool, size_t size, gfp_t gfp,
unsigned long *handle)
{
return zpool->driver->malloc(zpool->pool, size, gfp, handle);
}
void zpool_free(struct zpool *zpool, unsigned long handle)
{
zpool->driver->free(zpool->pool, handle);
}
int zpool_shrink(struct zpool *zpool, unsigned int pages,
unsigned int *reclaimed)
{
return zpool->driver->shrink(zpool->pool, pages, reclaimed);
}
void *zpool_map_handle(struct zpool *zpool, unsigned long handle,
enum zpool_mapmode mapmode)
{
return zpool->driver->map(zpool->pool, handle, mapmode);
}
void zpool_unmap_handle(struct zpool *zpool, unsigned long handle)
{
zpool->driver->unmap(zpool->pool, handle);
}
u64 zpool_get_total_size(struct zpool *zpool)
{
return zpool->driver->total_size(zpool->pool);
}
