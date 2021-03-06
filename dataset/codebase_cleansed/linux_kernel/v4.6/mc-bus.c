static int fsl_mc_bus_match(struct device *dev, struct device_driver *drv)
{
const struct fsl_mc_device_match_id *id;
struct fsl_mc_device *mc_dev = to_fsl_mc_device(dev);
struct fsl_mc_driver *mc_drv = to_fsl_mc_driver(drv);
bool found = false;
bool major_version_mismatch = false;
bool minor_version_mismatch = false;
if (WARN_ON(!fsl_mc_bus_exists()))
goto out;
if (!mc_drv->match_id_table)
goto out;
if ((mc_dev->obj_desc.state & DPRC_OBJ_STATE_PLUGGED) == 0 &&
!fsl_mc_is_root_dprc(&mc_dev->dev))
goto out;
for (id = mc_drv->match_id_table; id->vendor != 0x0; id++) {
if (id->vendor == mc_dev->obj_desc.vendor &&
strcmp(id->obj_type, mc_dev->obj_desc.type) == 0) {
if (id->ver_major == mc_dev->obj_desc.ver_major) {
found = true;
if (id->ver_minor != mc_dev->obj_desc.ver_minor)
minor_version_mismatch = true;
} else {
major_version_mismatch = true;
}
break;
}
}
if (major_version_mismatch) {
dev_warn(dev,
"Major version mismatch: driver version %u.%u, MC object version %u.%u\n",
id->ver_major, id->ver_minor,
mc_dev->obj_desc.ver_major,
mc_dev->obj_desc.ver_minor);
} else if (minor_version_mismatch) {
dev_warn(dev,
"Minor version mismatch: driver version %u.%u, MC object version %u.%u\n",
id->ver_major, id->ver_minor,
mc_dev->obj_desc.ver_major,
mc_dev->obj_desc.ver_minor);
}
out:
dev_dbg(dev, "%smatched\n", found ? "" : "not ");
return found;
}
static int fsl_mc_bus_uevent(struct device *dev, struct kobj_uevent_env *env)
{
pr_debug("%s invoked\n", __func__);
return 0;
}
static int fsl_mc_driver_probe(struct device *dev)
{
struct fsl_mc_driver *mc_drv;
struct fsl_mc_device *mc_dev = to_fsl_mc_device(dev);
int error;
if (WARN_ON(!dev->driver))
return -EINVAL;
mc_drv = to_fsl_mc_driver(dev->driver);
if (WARN_ON(!mc_drv->probe))
return -EINVAL;
error = mc_drv->probe(mc_dev);
if (error < 0) {
dev_err(dev, "MC object device probe callback failed: %d\n",
error);
return error;
}
return 0;
}
static int fsl_mc_driver_remove(struct device *dev)
{
struct fsl_mc_driver *mc_drv = to_fsl_mc_driver(dev->driver);
struct fsl_mc_device *mc_dev = to_fsl_mc_device(dev);
int error;
if (WARN_ON(!dev->driver))
return -EINVAL;
error = mc_drv->remove(mc_dev);
if (error < 0) {
dev_err(dev,
"MC object device remove callback failed: %d\n",
error);
return error;
}
return 0;
}
static void fsl_mc_driver_shutdown(struct device *dev)
{
struct fsl_mc_driver *mc_drv = to_fsl_mc_driver(dev->driver);
struct fsl_mc_device *mc_dev = to_fsl_mc_device(dev);
mc_drv->shutdown(mc_dev);
}
int __fsl_mc_driver_register(struct fsl_mc_driver *mc_driver,
struct module *owner)
{
int error;
mc_driver->driver.owner = owner;
mc_driver->driver.bus = &fsl_mc_bus_type;
if (mc_driver->probe)
mc_driver->driver.probe = fsl_mc_driver_probe;
if (mc_driver->remove)
mc_driver->driver.remove = fsl_mc_driver_remove;
if (mc_driver->shutdown)
mc_driver->driver.shutdown = fsl_mc_driver_shutdown;
error = driver_register(&mc_driver->driver);
if (error < 0) {
pr_err("driver_register() failed for %s: %d\n",
mc_driver->driver.name, error);
return error;
}
pr_info("MC object device driver %s registered\n",
mc_driver->driver.name);
return 0;
}
void fsl_mc_driver_unregister(struct fsl_mc_driver *mc_driver)
{
driver_unregister(&mc_driver->driver);
}
bool fsl_mc_bus_exists(void)
{
return atomic_read(&root_dprc_count) > 0;
}
static void fsl_mc_get_root_dprc(struct device *dev,
struct device **root_dprc_dev)
{
if (WARN_ON(!dev)) {
*root_dprc_dev = NULL;
} else if (WARN_ON(dev->bus != &fsl_mc_bus_type)) {
*root_dprc_dev = NULL;
} else {
*root_dprc_dev = dev;
while ((*root_dprc_dev)->parent->bus == &fsl_mc_bus_type)
*root_dprc_dev = (*root_dprc_dev)->parent;
}
}
static bool fsl_mc_is_root_dprc(struct device *dev)
{
struct device *root_dprc_dev;
fsl_mc_get_root_dprc(dev, &root_dprc_dev);
if (!root_dprc_dev)
return false;
return dev == root_dprc_dev;
}
static int get_dprc_icid(struct fsl_mc_io *mc_io,
int container_id, u16 *icid)
{
u16 dprc_handle;
struct dprc_attributes attr;
int error;
error = dprc_open(mc_io, 0, container_id, &dprc_handle);
if (error < 0) {
dev_err(mc_io->dev, "dprc_open() failed: %d\n", error);
return error;
}
memset(&attr, 0, sizeof(attr));
error = dprc_get_attributes(mc_io, 0, dprc_handle, &attr);
if (error < 0) {
dev_err(mc_io->dev, "dprc_get_attributes() failed: %d\n",
error);
goto common_cleanup;
}
*icid = attr.icid;
error = 0;
common_cleanup:
(void)dprc_close(mc_io, 0, dprc_handle);
return error;
}
static int translate_mc_addr(struct fsl_mc_device *mc_dev,
enum dprc_region_type mc_region_type,
u64 mc_offset, phys_addr_t *phys_addr)
{
int i;
struct device *root_dprc_dev;
struct fsl_mc *mc;
fsl_mc_get_root_dprc(&mc_dev->dev, &root_dprc_dev);
if (WARN_ON(!root_dprc_dev))
return -EINVAL;
mc = dev_get_drvdata(root_dprc_dev->parent);
if (mc->num_translation_ranges == 0) {
*phys_addr = mc_offset;
return 0;
}
for (i = 0; i < mc->num_translation_ranges; i++) {
struct fsl_mc_addr_translation_range *range =
&mc->translation_ranges[i];
if (mc_region_type == range->mc_region_type &&
mc_offset >= range->start_mc_offset &&
mc_offset < range->end_mc_offset) {
*phys_addr = range->start_phys_addr +
(mc_offset - range->start_mc_offset);
return 0;
}
}
return -EFAULT;
}
static int fsl_mc_device_get_mmio_regions(struct fsl_mc_device *mc_dev,
struct fsl_mc_device *mc_bus_dev)
{
int i;
int error;
struct resource *regions;
struct dprc_obj_desc *obj_desc = &mc_dev->obj_desc;
struct device *parent_dev = mc_dev->dev.parent;
enum dprc_region_type mc_region_type;
if (strcmp(obj_desc->type, "dprc") == 0 ||
strcmp(obj_desc->type, "dpmcp") == 0) {
mc_region_type = DPRC_REGION_TYPE_MC_PORTAL;
} else if (strcmp(obj_desc->type, "dpio") == 0) {
mc_region_type = DPRC_REGION_TYPE_QBMAN_PORTAL;
} else {
WARN_ON(true);
return -EINVAL;
}
regions = kmalloc_array(obj_desc->region_count,
sizeof(regions[0]), GFP_KERNEL);
if (!regions)
return -ENOMEM;
for (i = 0; i < obj_desc->region_count; i++) {
struct dprc_region_desc region_desc;
error = dprc_get_obj_region(mc_bus_dev->mc_io,
0,
mc_bus_dev->mc_handle,
obj_desc->type,
obj_desc->id, i, &region_desc);
if (error < 0) {
dev_err(parent_dev,
"dprc_get_obj_region() failed: %d\n", error);
goto error_cleanup_regions;
}
WARN_ON(region_desc.size == 0);
error = translate_mc_addr(mc_dev, mc_region_type,
region_desc.base_offset,
&regions[i].start);
if (error < 0) {
dev_err(parent_dev,
"Invalid MC offset: %#x (for %s.%d\'s region %d)\n",
region_desc.base_offset,
obj_desc->type, obj_desc->id, i);
goto error_cleanup_regions;
}
regions[i].end = regions[i].start + region_desc.size - 1;
regions[i].name = "fsl-mc object MMIO region";
regions[i].flags = IORESOURCE_IO;
}
mc_dev->regions = regions;
return 0;
error_cleanup_regions:
kfree(regions);
return error;
}
int fsl_mc_device_add(struct dprc_obj_desc *obj_desc,
struct fsl_mc_io *mc_io,
struct device *parent_dev,
struct fsl_mc_device **new_mc_dev)
{
int error;
struct fsl_mc_device *mc_dev = NULL;
struct fsl_mc_bus *mc_bus = NULL;
struct fsl_mc_device *parent_mc_dev;
if (parent_dev->bus == &fsl_mc_bus_type)
parent_mc_dev = to_fsl_mc_device(parent_dev);
else
parent_mc_dev = NULL;
if (strcmp(obj_desc->type, "dprc") == 0) {
mc_bus = devm_kzalloc(parent_dev, sizeof(*mc_bus), GFP_KERNEL);
if (!mc_bus)
return -ENOMEM;
mc_dev = &mc_bus->mc_dev;
} else {
mc_dev = kmem_cache_zalloc(mc_dev_cache, GFP_KERNEL);
if (!mc_dev)
return -ENOMEM;
}
mc_dev->obj_desc = *obj_desc;
mc_dev->mc_io = mc_io;
device_initialize(&mc_dev->dev);
mc_dev->dev.parent = parent_dev;
mc_dev->dev.bus = &fsl_mc_bus_type;
dev_set_name(&mc_dev->dev, "%s.%d", obj_desc->type, obj_desc->id);
if (strcmp(obj_desc->type, "dprc") == 0) {
struct fsl_mc_io *mc_io2;
mc_dev->flags |= FSL_MC_IS_DPRC;
if (parent_mc_dev) {
mc_io2 = parent_mc_dev->mc_io;
} else {
if (WARN_ON(!mc_io)) {
error = -EINVAL;
goto error_cleanup_dev;
}
mc_io2 = mc_io;
atomic_inc(&root_dprc_count);
}
error = get_dprc_icid(mc_io2, obj_desc->id, &mc_dev->icid);
if (error < 0)
goto error_cleanup_dev;
} else {
mc_dev->icid = parent_mc_dev->icid;
mc_dev->dma_mask = FSL_MC_DEFAULT_DMA_MASK;
mc_dev->dev.dma_mask = &mc_dev->dma_mask;
dev_set_msi_domain(&mc_dev->dev,
dev_get_msi_domain(&parent_mc_dev->dev));
}
if (parent_mc_dev && obj_desc->region_count != 0) {
error = fsl_mc_device_get_mmio_regions(mc_dev,
parent_mc_dev);
if (error < 0)
goto error_cleanup_dev;
}
error = device_add(&mc_dev->dev);
if (error < 0) {
dev_err(parent_dev,
"device_add() failed for device %s: %d\n",
dev_name(&mc_dev->dev), error);
goto error_cleanup_dev;
}
(void)get_device(&mc_dev->dev);
dev_dbg(parent_dev, "Added MC object device %s\n",
dev_name(&mc_dev->dev));
*new_mc_dev = mc_dev;
return 0;
error_cleanup_dev:
kfree(mc_dev->regions);
if (mc_bus)
devm_kfree(parent_dev, mc_bus);
else
kmem_cache_free(mc_dev_cache, mc_dev);
return error;
}
void fsl_mc_device_remove(struct fsl_mc_device *mc_dev)
{
struct fsl_mc_bus *mc_bus = NULL;
kfree(mc_dev->regions);
device_del(&mc_dev->dev);
put_device(&mc_dev->dev);
if (strcmp(mc_dev->obj_desc.type, "dprc") == 0) {
mc_bus = to_fsl_mc_bus(mc_dev);
if (mc_dev->mc_io) {
fsl_destroy_mc_io(mc_dev->mc_io);
mc_dev->mc_io = NULL;
}
if (fsl_mc_is_root_dprc(&mc_dev->dev)) {
if (atomic_read(&root_dprc_count) > 0)
atomic_dec(&root_dprc_count);
else
WARN_ON(1);
}
}
if (mc_bus)
devm_kfree(mc_dev->dev.parent, mc_bus);
else
kmem_cache_free(mc_dev_cache, mc_dev);
}
static int parse_mc_ranges(struct device *dev,
int *paddr_cells,
int *mc_addr_cells,
int *mc_size_cells,
const __be32 **ranges_start,
u8 *num_ranges)
{
const __be32 *prop;
int range_tuple_cell_count;
int ranges_len;
int tuple_len;
struct device_node *mc_node = dev->of_node;
*ranges_start = of_get_property(mc_node, "ranges", &ranges_len);
if (!(*ranges_start) || !ranges_len) {
dev_warn(dev,
"missing or empty ranges property for device tree node '%s'\n",
mc_node->name);
*num_ranges = 0;
return 0;
}
*paddr_cells = of_n_addr_cells(mc_node);
prop = of_get_property(mc_node, "#address-cells", NULL);
if (prop)
*mc_addr_cells = be32_to_cpup(prop);
else
*mc_addr_cells = *paddr_cells;
prop = of_get_property(mc_node, "#size-cells", NULL);
if (prop)
*mc_size_cells = be32_to_cpup(prop);
else
*mc_size_cells = of_n_size_cells(mc_node);
range_tuple_cell_count = *paddr_cells + *mc_addr_cells +
*mc_size_cells;
tuple_len = range_tuple_cell_count * sizeof(__be32);
if (ranges_len % tuple_len != 0) {
dev_err(dev, "malformed ranges property '%s'\n", mc_node->name);
return -EINVAL;
}
*num_ranges = ranges_len / tuple_len;
return 0;
}
static int get_mc_addr_translation_ranges(struct device *dev,
struct fsl_mc_addr_translation_range
**ranges,
u8 *num_ranges)
{
int error;
int paddr_cells;
int mc_addr_cells;
int mc_size_cells;
int i;
const __be32 *ranges_start;
const __be32 *cell;
error = parse_mc_ranges(dev,
&paddr_cells,
&mc_addr_cells,
&mc_size_cells,
&ranges_start,
num_ranges);
if (error < 0)
return error;
if (!(*num_ranges)) {
*ranges = NULL;
return 0;
}
*ranges = devm_kcalloc(dev, *num_ranges,
sizeof(struct fsl_mc_addr_translation_range),
GFP_KERNEL);
if (!(*ranges))
return -ENOMEM;
cell = ranges_start;
for (i = 0; i < *num_ranges; ++i) {
struct fsl_mc_addr_translation_range *range = &(*ranges)[i];
range->mc_region_type = of_read_number(cell, 1);
range->start_mc_offset = of_read_number(cell + 1,
mc_addr_cells - 1);
cell += mc_addr_cells;
range->start_phys_addr = of_read_number(cell, paddr_cells);
cell += paddr_cells;
range->end_mc_offset = range->start_mc_offset +
of_read_number(cell, mc_size_cells);
cell += mc_size_cells;
}
return 0;
}
static int fsl_mc_bus_probe(struct platform_device *pdev)
{
struct dprc_obj_desc obj_desc;
int error;
struct fsl_mc *mc;
struct fsl_mc_device *mc_bus_dev = NULL;
struct fsl_mc_io *mc_io = NULL;
int container_id;
phys_addr_t mc_portal_phys_addr;
u32 mc_portal_size;
struct mc_version mc_version;
struct resource res;
dev_info(&pdev->dev, "Root MC bus device probed");
mc = devm_kzalloc(&pdev->dev, sizeof(*mc), GFP_KERNEL);
if (!mc)
return -ENOMEM;
platform_set_drvdata(pdev, mc);
error = of_address_to_resource(pdev->dev.of_node, 0, &res);
if (error < 0) {
dev_err(&pdev->dev,
"of_address_to_resource() failed for %s\n",
pdev->dev.of_node->full_name);
return error;
}
mc_portal_phys_addr = res.start;
mc_portal_size = resource_size(&res);
error = fsl_create_mc_io(&pdev->dev, mc_portal_phys_addr,
mc_portal_size, NULL,
FSL_MC_IO_ATOMIC_CONTEXT_PORTAL, &mc_io);
if (error < 0)
return error;
error = mc_get_version(mc_io, 0, &mc_version);
if (error != 0) {
dev_err(&pdev->dev,
"mc_get_version() failed with error %d\n", error);
goto error_cleanup_mc_io;
}
dev_info(&pdev->dev,
"Freescale Management Complex Firmware version: %u.%u.%u\n",
mc_version.major, mc_version.minor, mc_version.revision);
if (mc_version.major < MC_VER_MAJOR) {
dev_err(&pdev->dev,
"ERROR: MC firmware version not supported by driver (driver version: %u.%u)\n",
MC_VER_MAJOR, MC_VER_MINOR);
error = -ENOTSUPP;
goto error_cleanup_mc_io;
}
if (mc_version.major > MC_VER_MAJOR) {
dev_warn(&pdev->dev,
"WARNING: driver may not support newer MC firmware features (driver version: %u.%u)\n",
MC_VER_MAJOR, MC_VER_MINOR);
}
error = get_mc_addr_translation_ranges(&pdev->dev,
&mc->translation_ranges,
&mc->num_translation_ranges);
if (error < 0)
goto error_cleanup_mc_io;
error = dpmng_get_container_id(mc_io, 0, &container_id);
if (error < 0) {
dev_err(&pdev->dev,
"dpmng_get_container_id() failed: %d\n", error);
goto error_cleanup_mc_io;
}
obj_desc.vendor = FSL_MC_VENDOR_FREESCALE;
strcpy(obj_desc.type, "dprc");
obj_desc.id = container_id;
obj_desc.ver_major = DPRC_VER_MAJOR;
obj_desc.ver_minor = DPRC_VER_MINOR;
obj_desc.irq_count = 1;
obj_desc.region_count = 0;
error = fsl_mc_device_add(&obj_desc, mc_io, &pdev->dev, &mc_bus_dev);
if (error < 0)
goto error_cleanup_mc_io;
mc->root_mc_bus_dev = mc_bus_dev;
return 0;
error_cleanup_mc_io:
fsl_destroy_mc_io(mc_io);
return error;
}
static int fsl_mc_bus_remove(struct platform_device *pdev)
{
struct fsl_mc *mc = platform_get_drvdata(pdev);
if (WARN_ON(!fsl_mc_is_root_dprc(&mc->root_mc_bus_dev->dev)))
return -EINVAL;
fsl_mc_device_remove(mc->root_mc_bus_dev);
dev_info(&pdev->dev, "Root MC bus device removed");
return 0;
}
static int __init fsl_mc_bus_driver_init(void)
{
int error;
mc_dev_cache = kmem_cache_create("fsl_mc_device",
sizeof(struct fsl_mc_device), 0, 0,
NULL);
if (!mc_dev_cache) {
pr_err("Could not create fsl_mc_device cache\n");
return -ENOMEM;
}
error = bus_register(&fsl_mc_bus_type);
if (error < 0) {
pr_err("fsl-mc bus type registration failed: %d\n", error);
goto error_cleanup_cache;
}
pr_info("fsl-mc bus type registered\n");
error = platform_driver_register(&fsl_mc_bus_driver);
if (error < 0) {
pr_err("platform_driver_register() failed: %d\n", error);
goto error_cleanup_bus;
}
error = dprc_driver_init();
if (error < 0)
goto error_cleanup_driver;
error = fsl_mc_allocator_driver_init();
if (error < 0)
goto error_cleanup_dprc_driver;
error = its_fsl_mc_msi_init();
if (error < 0)
goto error_cleanup_mc_allocator;
return 0;
error_cleanup_mc_allocator:
fsl_mc_allocator_driver_exit();
error_cleanup_dprc_driver:
dprc_driver_exit();
error_cleanup_driver:
platform_driver_unregister(&fsl_mc_bus_driver);
error_cleanup_bus:
bus_unregister(&fsl_mc_bus_type);
error_cleanup_cache:
kmem_cache_destroy(mc_dev_cache);
return error;
}
static void __exit fsl_mc_bus_driver_exit(void)
{
if (WARN_ON(!mc_dev_cache))
return;
its_fsl_mc_msi_cleanup();
fsl_mc_allocator_driver_exit();
dprc_driver_exit();
platform_driver_unregister(&fsl_mc_bus_driver);
bus_unregister(&fsl_mc_bus_type);
kmem_cache_destroy(mc_dev_cache);
pr_info("MC bus unregistered\n");
}
