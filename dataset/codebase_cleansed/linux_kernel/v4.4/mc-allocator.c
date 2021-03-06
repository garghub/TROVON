static int __must_check fsl_mc_resource_pool_add_device(struct fsl_mc_bus
*mc_bus,
enum fsl_mc_pool_type
pool_type,
struct fsl_mc_device
*mc_dev)
{
struct fsl_mc_resource_pool *res_pool;
struct fsl_mc_resource *resource;
struct fsl_mc_device *mc_bus_dev = &mc_bus->mc_dev;
int error = -EINVAL;
bool mutex_locked = false;
if (WARN_ON(pool_type < 0 || pool_type >= FSL_MC_NUM_POOL_TYPES))
goto out;
if (WARN_ON(!FSL_MC_IS_ALLOCATABLE(mc_dev->obj_desc.type)))
goto out;
if (WARN_ON(mc_dev->resource))
goto out;
res_pool = &mc_bus->resource_pools[pool_type];
if (WARN_ON(res_pool->type != pool_type))
goto out;
if (WARN_ON(res_pool->mc_bus != mc_bus))
goto out;
mutex_lock(&res_pool->mutex);
mutex_locked = true;
if (WARN_ON(res_pool->max_count < 0))
goto out;
if (WARN_ON(res_pool->free_count < 0 ||
res_pool->free_count > res_pool->max_count))
goto out;
resource = devm_kzalloc(&mc_bus_dev->dev, sizeof(*resource),
GFP_KERNEL);
if (!resource) {
error = -ENOMEM;
dev_err(&mc_bus_dev->dev,
"Failed to allocate memory for fsl_mc_resource\n");
goto out;
}
resource->type = pool_type;
resource->id = mc_dev->obj_desc.id;
resource->data = mc_dev;
resource->parent_pool = res_pool;
INIT_LIST_HEAD(&resource->node);
list_add_tail(&resource->node, &res_pool->free_list);
mc_dev->resource = resource;
res_pool->free_count++;
res_pool->max_count++;
error = 0;
out:
if (mutex_locked)
mutex_unlock(&res_pool->mutex);
return error;
}
static int __must_check fsl_mc_resource_pool_remove_device(struct fsl_mc_device
*mc_dev)
{
struct fsl_mc_device *mc_bus_dev;
struct fsl_mc_bus *mc_bus;
struct fsl_mc_resource_pool *res_pool;
struct fsl_mc_resource *resource;
int error = -EINVAL;
bool mutex_locked = false;
if (WARN_ON(!FSL_MC_IS_ALLOCATABLE(mc_dev->obj_desc.type)))
goto out;
resource = mc_dev->resource;
if (WARN_ON(!resource || resource->data != mc_dev))
goto out;
mc_bus_dev = to_fsl_mc_device(mc_dev->dev.parent);
mc_bus = to_fsl_mc_bus(mc_bus_dev);
res_pool = resource->parent_pool;
if (WARN_ON(res_pool != &mc_bus->resource_pools[resource->type]))
goto out;
mutex_lock(&res_pool->mutex);
mutex_locked = true;
if (WARN_ON(res_pool->max_count <= 0))
goto out;
if (WARN_ON(res_pool->free_count <= 0 ||
res_pool->free_count > res_pool->max_count))
goto out;
if (list_empty(&resource->node)) {
error = -EBUSY;
dev_err(&mc_bus_dev->dev,
"Device %s cannot be removed from resource pool\n",
dev_name(&mc_dev->dev));
goto out;
}
list_del(&resource->node);
INIT_LIST_HEAD(&resource->node);
res_pool->free_count--;
res_pool->max_count--;
devm_kfree(&mc_bus_dev->dev, resource);
mc_dev->resource = NULL;
error = 0;
out:
if (mutex_locked)
mutex_unlock(&res_pool->mutex);
return error;
}
static int __must_check object_type_to_pool_type(const char *object_type,
enum fsl_mc_pool_type
*pool_type)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(fsl_mc_pool_type_strings); i++) {
if (strcmp(object_type, fsl_mc_pool_type_strings[i]) == 0) {
*pool_type = i;
return 0;
}
}
return -EINVAL;
}
int __must_check fsl_mc_resource_allocate(struct fsl_mc_bus *mc_bus,
enum fsl_mc_pool_type pool_type,
struct fsl_mc_resource **new_resource)
{
struct fsl_mc_resource_pool *res_pool;
struct fsl_mc_resource *resource;
struct fsl_mc_device *mc_bus_dev = &mc_bus->mc_dev;
int error = -EINVAL;
bool mutex_locked = false;
BUILD_BUG_ON(ARRAY_SIZE(fsl_mc_pool_type_strings) !=
FSL_MC_NUM_POOL_TYPES);
*new_resource = NULL;
if (WARN_ON(pool_type < 0 || pool_type >= FSL_MC_NUM_POOL_TYPES))
goto error;
res_pool = &mc_bus->resource_pools[pool_type];
if (WARN_ON(res_pool->mc_bus != mc_bus))
goto error;
mutex_lock(&res_pool->mutex);
mutex_locked = true;
resource = list_first_entry_or_null(&res_pool->free_list,
struct fsl_mc_resource, node);
if (!resource) {
WARN_ON(res_pool->free_count != 0);
error = -ENXIO;
dev_err(&mc_bus_dev->dev,
"No more resources of type %s left\n",
fsl_mc_pool_type_strings[pool_type]);
goto error;
}
if (WARN_ON(resource->type != pool_type))
goto error;
if (WARN_ON(resource->parent_pool != res_pool))
goto error;
if (WARN_ON(res_pool->free_count <= 0 ||
res_pool->free_count > res_pool->max_count))
goto error;
list_del(&resource->node);
INIT_LIST_HEAD(&resource->node);
res_pool->free_count--;
mutex_unlock(&res_pool->mutex);
*new_resource = resource;
return 0;
error:
if (mutex_locked)
mutex_unlock(&res_pool->mutex);
return error;
}
void fsl_mc_resource_free(struct fsl_mc_resource *resource)
{
struct fsl_mc_resource_pool *res_pool;
bool mutex_locked = false;
res_pool = resource->parent_pool;
if (WARN_ON(resource->type != res_pool->type))
goto out;
mutex_lock(&res_pool->mutex);
mutex_locked = true;
if (WARN_ON(res_pool->free_count < 0 ||
res_pool->free_count >= res_pool->max_count))
goto out;
if (WARN_ON(!list_empty(&resource->node)))
goto out;
list_add_tail(&resource->node, &res_pool->free_list);
res_pool->free_count++;
out:
if (mutex_locked)
mutex_unlock(&res_pool->mutex);
}
int __must_check fsl_mc_portal_allocate(struct fsl_mc_device *mc_dev,
u16 mc_io_flags,
struct fsl_mc_io **new_mc_io)
{
struct fsl_mc_device *mc_bus_dev;
struct fsl_mc_bus *mc_bus;
phys_addr_t mc_portal_phys_addr;
size_t mc_portal_size;
struct fsl_mc_device *dpmcp_dev;
int error = -EINVAL;
struct fsl_mc_resource *resource = NULL;
struct fsl_mc_io *mc_io = NULL;
if (mc_dev->flags & FSL_MC_IS_DPRC) {
mc_bus_dev = mc_dev;
} else {
if (WARN_ON(mc_dev->dev.parent->bus != &fsl_mc_bus_type))
return error;
mc_bus_dev = to_fsl_mc_device(mc_dev->dev.parent);
}
mc_bus = to_fsl_mc_bus(mc_bus_dev);
*new_mc_io = NULL;
error = fsl_mc_resource_allocate(mc_bus, FSL_MC_POOL_DPMCP, &resource);
if (error < 0)
return error;
dpmcp_dev = resource->data;
if (WARN_ON(!dpmcp_dev))
goto error_cleanup_resource;
if (WARN_ON(dpmcp_dev->obj_desc.region_count == 0))
goto error_cleanup_resource;
mc_portal_phys_addr = dpmcp_dev->regions[0].start;
mc_portal_size = dpmcp_dev->regions[0].end -
dpmcp_dev->regions[0].start + 1;
if (WARN_ON(mc_portal_size != mc_bus_dev->mc_io->portal_size))
goto error_cleanup_resource;
error = fsl_create_mc_io(&mc_bus_dev->dev,
mc_portal_phys_addr,
mc_portal_size, dpmcp_dev,
mc_io_flags, &mc_io);
if (error < 0)
goto error_cleanup_resource;
*new_mc_io = mc_io;
return 0;
error_cleanup_resource:
fsl_mc_resource_free(resource);
return error;
}
void fsl_mc_portal_free(struct fsl_mc_io *mc_io)
{
struct fsl_mc_device *dpmcp_dev;
struct fsl_mc_resource *resource;
dpmcp_dev = mc_io->dpmcp_dev;
if (WARN_ON(!dpmcp_dev))
return;
resource = dpmcp_dev->resource;
if (WARN_ON(!resource || resource->type != FSL_MC_POOL_DPMCP))
return;
if (WARN_ON(resource->data != dpmcp_dev))
return;
fsl_destroy_mc_io(mc_io);
fsl_mc_resource_free(resource);
}
int fsl_mc_portal_reset(struct fsl_mc_io *mc_io)
{
int error;
struct fsl_mc_device *dpmcp_dev = mc_io->dpmcp_dev;
if (WARN_ON(!dpmcp_dev))
return -EINVAL;
error = dpmcp_reset(mc_io, 0, dpmcp_dev->mc_handle);
if (error < 0) {
dev_err(&dpmcp_dev->dev, "dpmcp_reset() failed: %d\n", error);
return error;
}
return 0;
}
int __must_check fsl_mc_object_allocate(struct fsl_mc_device *mc_dev,
enum fsl_mc_pool_type pool_type,
struct fsl_mc_device **new_mc_adev)
{
struct fsl_mc_device *mc_bus_dev;
struct fsl_mc_bus *mc_bus;
struct fsl_mc_device *mc_adev;
int error = -EINVAL;
struct fsl_mc_resource *resource = NULL;
*new_mc_adev = NULL;
if (WARN_ON(mc_dev->flags & FSL_MC_IS_DPRC))
goto error;
if (WARN_ON(mc_dev->dev.parent->bus != &fsl_mc_bus_type))
goto error;
if (WARN_ON(pool_type == FSL_MC_POOL_DPMCP))
goto error;
mc_bus_dev = to_fsl_mc_device(mc_dev->dev.parent);
mc_bus = to_fsl_mc_bus(mc_bus_dev);
error = fsl_mc_resource_allocate(mc_bus, pool_type, &resource);
if (error < 0)
goto error;
mc_adev = resource->data;
if (WARN_ON(!mc_adev))
goto error;
*new_mc_adev = mc_adev;
return 0;
error:
if (resource)
fsl_mc_resource_free(resource);
return error;
}
void fsl_mc_object_free(struct fsl_mc_device *mc_adev)
{
struct fsl_mc_resource *resource;
resource = mc_adev->resource;
if (WARN_ON(resource->type == FSL_MC_POOL_DPMCP))
return;
if (WARN_ON(resource->data != mc_adev))
return;
fsl_mc_resource_free(resource);
}
static int fsl_mc_allocator_probe(struct fsl_mc_device *mc_dev)
{
enum fsl_mc_pool_type pool_type;
struct fsl_mc_device *mc_bus_dev;
struct fsl_mc_bus *mc_bus;
int error;
if (WARN_ON(!FSL_MC_IS_ALLOCATABLE(mc_dev->obj_desc.type)))
return -EINVAL;
mc_bus_dev = to_fsl_mc_device(mc_dev->dev.parent);
if (WARN_ON(mc_bus_dev->dev.bus != &fsl_mc_bus_type))
return -EINVAL;
mc_bus = to_fsl_mc_bus(mc_bus_dev);
error = object_type_to_pool_type(mc_dev->obj_desc.type, &pool_type);
if (error < 0)
return error;
error = fsl_mc_resource_pool_add_device(mc_bus, pool_type, mc_dev);
if (error < 0)
return error;
dev_dbg(&mc_dev->dev,
"Allocatable MC object device bound to fsl_mc_allocator driver");
return 0;
}
static int fsl_mc_allocator_remove(struct fsl_mc_device *mc_dev)
{
int error;
if (WARN_ON(!FSL_MC_IS_ALLOCATABLE(mc_dev->obj_desc.type)))
return -EINVAL;
if (mc_dev->resource) {
error = fsl_mc_resource_pool_remove_device(mc_dev);
if (error < 0)
return error;
}
dev_dbg(&mc_dev->dev,
"Allocatable MC object device unbound from fsl_mc_allocator driver");
return 0;
}
int __init fsl_mc_allocator_driver_init(void)
{
return fsl_mc_driver_register(&fsl_mc_allocator_driver);
}
void __exit fsl_mc_allocator_driver_exit(void)
{
fsl_mc_driver_unregister(&fsl_mc_allocator_driver);
}
