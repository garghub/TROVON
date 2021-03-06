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
if (WARN_ON(res_pool->max_count < 0))
goto out_unlock;
if (WARN_ON(res_pool->free_count < 0 ||
res_pool->free_count > res_pool->max_count))
goto out_unlock;
resource = devm_kzalloc(&mc_bus_dev->dev, sizeof(*resource),
GFP_KERNEL);
if (!resource) {
error = -ENOMEM;
dev_err(&mc_bus_dev->dev,
"Failed to allocate memory for fsl_mc_resource\n");
goto out_unlock;
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
out_unlock:
mutex_unlock(&res_pool->mutex);
out:
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
if (WARN_ON(res_pool->max_count <= 0))
goto out_unlock;
if (WARN_ON(res_pool->free_count <= 0 ||
res_pool->free_count > res_pool->max_count))
goto out_unlock;
if (list_empty(&resource->node)) {
error = -EBUSY;
dev_err(&mc_bus_dev->dev,
"Device %s cannot be removed from resource pool\n",
dev_name(&mc_dev->dev));
goto out_unlock;
}
list_del_init(&resource->node);
res_pool->free_count--;
res_pool->max_count--;
devm_kfree(&mc_bus_dev->dev, resource);
mc_dev->resource = NULL;
error = 0;
out_unlock:
mutex_unlock(&res_pool->mutex);
out:
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
BUILD_BUG_ON(ARRAY_SIZE(fsl_mc_pool_type_strings) !=
FSL_MC_NUM_POOL_TYPES);
*new_resource = NULL;
if (WARN_ON(pool_type < 0 || pool_type >= FSL_MC_NUM_POOL_TYPES))
goto out;
res_pool = &mc_bus->resource_pools[pool_type];
if (WARN_ON(res_pool->mc_bus != mc_bus))
goto out;
mutex_lock(&res_pool->mutex);
resource = list_first_entry_or_null(&res_pool->free_list,
struct fsl_mc_resource, node);
if (!resource) {
WARN_ON(res_pool->free_count != 0);
error = -ENXIO;
dev_err(&mc_bus_dev->dev,
"No more resources of type %s left\n",
fsl_mc_pool_type_strings[pool_type]);
goto out_unlock;
}
if (WARN_ON(resource->type != pool_type))
goto out_unlock;
if (WARN_ON(resource->parent_pool != res_pool))
goto out_unlock;
if (WARN_ON(res_pool->free_count <= 0 ||
res_pool->free_count > res_pool->max_count))
goto out_unlock;
list_del_init(&resource->node);
res_pool->free_count--;
error = 0;
out_unlock:
mutex_unlock(&res_pool->mutex);
*new_resource = resource;
out:
return error;
}
void fsl_mc_resource_free(struct fsl_mc_resource *resource)
{
struct fsl_mc_resource_pool *res_pool;
res_pool = resource->parent_pool;
if (WARN_ON(resource->type != res_pool->type))
return;
mutex_lock(&res_pool->mutex);
if (WARN_ON(res_pool->free_count < 0 ||
res_pool->free_count >= res_pool->max_count))
goto out_unlock;
if (WARN_ON(!list_empty(&resource->node)))
goto out_unlock;
list_add_tail(&resource->node, &res_pool->free_list);
res_pool->free_count++;
out_unlock:
mutex_unlock(&res_pool->mutex);
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
if (WARN_ON(!dev_is_fsl_mc(mc_dev->dev.parent)))
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
int fsl_mc_populate_irq_pool(struct fsl_mc_bus *mc_bus,
unsigned int irq_count)
{
unsigned int i;
struct msi_desc *msi_desc;
struct fsl_mc_device_irq *irq_resources;
struct fsl_mc_device_irq *mc_dev_irq;
int error;
struct fsl_mc_device *mc_bus_dev = &mc_bus->mc_dev;
struct fsl_mc_resource_pool *res_pool =
&mc_bus->resource_pools[FSL_MC_POOL_IRQ];
if (WARN_ON(irq_count == 0 ||
irq_count > FSL_MC_IRQ_POOL_MAX_TOTAL_IRQS))
return -EINVAL;
error = fsl_mc_msi_domain_alloc_irqs(&mc_bus_dev->dev, irq_count);
if (error < 0)
return error;
irq_resources = devm_kzalloc(&mc_bus_dev->dev,
sizeof(*irq_resources) * irq_count,
GFP_KERNEL);
if (!irq_resources) {
error = -ENOMEM;
goto cleanup_msi_irqs;
}
for (i = 0; i < irq_count; i++) {
mc_dev_irq = &irq_resources[i];
mc_dev_irq->resource.type = res_pool->type;
mc_dev_irq->resource.data = mc_dev_irq;
mc_dev_irq->resource.parent_pool = res_pool;
INIT_LIST_HEAD(&mc_dev_irq->resource.node);
list_add_tail(&mc_dev_irq->resource.node, &res_pool->free_list);
}
for_each_msi_entry(msi_desc, &mc_bus_dev->dev) {
mc_dev_irq = &irq_resources[msi_desc->fsl_mc.msi_index];
mc_dev_irq->msi_desc = msi_desc;
mc_dev_irq->resource.id = msi_desc->irq;
}
res_pool->max_count = irq_count;
res_pool->free_count = irq_count;
mc_bus->irq_resources = irq_resources;
return 0;
cleanup_msi_irqs:
fsl_mc_msi_domain_free_irqs(&mc_bus_dev->dev);
return error;
}
void fsl_mc_cleanup_irq_pool(struct fsl_mc_bus *mc_bus)
{
struct fsl_mc_device *mc_bus_dev = &mc_bus->mc_dev;
struct fsl_mc_resource_pool *res_pool =
&mc_bus->resource_pools[FSL_MC_POOL_IRQ];
if (WARN_ON(!mc_bus->irq_resources))
return;
if (WARN_ON(res_pool->max_count == 0))
return;
if (WARN_ON(res_pool->free_count != res_pool->max_count))
return;
INIT_LIST_HEAD(&res_pool->free_list);
res_pool->max_count = 0;
res_pool->free_count = 0;
mc_bus->irq_resources = NULL;
fsl_mc_msi_domain_free_irqs(&mc_bus_dev->dev);
}
int __must_check fsl_mc_allocate_irqs(struct fsl_mc_device *mc_dev)
{
int i;
int irq_count;
int res_allocated_count = 0;
int error = -EINVAL;
struct fsl_mc_device_irq **irqs = NULL;
struct fsl_mc_bus *mc_bus;
struct fsl_mc_resource_pool *res_pool;
if (WARN_ON(mc_dev->irqs))
return -EINVAL;
irq_count = mc_dev->obj_desc.irq_count;
if (WARN_ON(irq_count == 0))
return -EINVAL;
if (strcmp(mc_dev->obj_desc.type, "dprc") == 0)
mc_bus = to_fsl_mc_bus(mc_dev);
else
mc_bus = to_fsl_mc_bus(to_fsl_mc_device(mc_dev->dev.parent));
if (WARN_ON(!mc_bus->irq_resources))
return -EINVAL;
res_pool = &mc_bus->resource_pools[FSL_MC_POOL_IRQ];
if (res_pool->free_count < irq_count) {
dev_err(&mc_dev->dev,
"Not able to allocate %u irqs for device\n", irq_count);
return -ENOSPC;
}
irqs = devm_kzalloc(&mc_dev->dev, irq_count * sizeof(irqs[0]),
GFP_KERNEL);
if (!irqs)
return -ENOMEM;
for (i = 0; i < irq_count; i++) {
struct fsl_mc_resource *resource;
error = fsl_mc_resource_allocate(mc_bus, FSL_MC_POOL_IRQ,
&resource);
if (error < 0)
goto error_resource_alloc;
irqs[i] = to_fsl_mc_irq(resource);
res_allocated_count++;
WARN_ON(irqs[i]->mc_dev);
irqs[i]->mc_dev = mc_dev;
irqs[i]->dev_irq_index = i;
}
mc_dev->irqs = irqs;
return 0;
error_resource_alloc:
for (i = 0; i < res_allocated_count; i++) {
irqs[i]->mc_dev = NULL;
fsl_mc_resource_free(&irqs[i]->resource);
}
return error;
}
void fsl_mc_free_irqs(struct fsl_mc_device *mc_dev)
{
int i;
int irq_count;
struct fsl_mc_bus *mc_bus;
struct fsl_mc_device_irq **irqs = mc_dev->irqs;
if (WARN_ON(!irqs))
return;
irq_count = mc_dev->obj_desc.irq_count;
if (strcmp(mc_dev->obj_desc.type, "dprc") == 0)
mc_bus = to_fsl_mc_bus(mc_dev);
else
mc_bus = to_fsl_mc_bus(to_fsl_mc_device(mc_dev->dev.parent));
if (WARN_ON(!mc_bus->irq_resources))
return;
for (i = 0; i < irq_count; i++) {
WARN_ON(!irqs[i]->mc_dev);
irqs[i]->mc_dev = NULL;
fsl_mc_resource_free(&irqs[i]->resource);
}
mc_dev->irqs = NULL;
}
void fsl_mc_init_all_resource_pools(struct fsl_mc_device *mc_bus_dev)
{
int pool_type;
struct fsl_mc_bus *mc_bus = to_fsl_mc_bus(mc_bus_dev);
for (pool_type = 0; pool_type < FSL_MC_NUM_POOL_TYPES; pool_type++) {
struct fsl_mc_resource_pool *res_pool =
&mc_bus->resource_pools[pool_type];
res_pool->type = pool_type;
res_pool->max_count = 0;
res_pool->free_count = 0;
res_pool->mc_bus = mc_bus;
INIT_LIST_HEAD(&res_pool->free_list);
mutex_init(&res_pool->mutex);
}
}
static void fsl_mc_cleanup_resource_pool(struct fsl_mc_device *mc_bus_dev,
enum fsl_mc_pool_type pool_type)
{
struct fsl_mc_resource *resource;
struct fsl_mc_resource *next;
struct fsl_mc_bus *mc_bus = to_fsl_mc_bus(mc_bus_dev);
struct fsl_mc_resource_pool *res_pool =
&mc_bus->resource_pools[pool_type];
int free_count = 0;
WARN_ON(res_pool->type != pool_type);
WARN_ON(res_pool->free_count != res_pool->max_count);
list_for_each_entry_safe(resource, next, &res_pool->free_list, node) {
free_count++;
WARN_ON(resource->type != res_pool->type);
WARN_ON(resource->parent_pool != res_pool);
devm_kfree(&mc_bus_dev->dev, resource);
}
WARN_ON(free_count != res_pool->free_count);
}
void fsl_mc_cleanup_all_resource_pools(struct fsl_mc_device *mc_bus_dev)
{
int pool_type;
for (pool_type = 0; pool_type < FSL_MC_NUM_POOL_TYPES; pool_type++)
fsl_mc_cleanup_resource_pool(mc_bus_dev, pool_type);
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
if (WARN_ON(!dev_is_fsl_mc(&mc_bus_dev->dev)))
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
void fsl_mc_allocator_driver_exit(void)
{
fsl_mc_driver_unregister(&fsl_mc_allocator_driver);
}
