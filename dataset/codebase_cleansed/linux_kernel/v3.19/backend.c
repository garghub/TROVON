struct agp_bridge_data *agp_backend_acquire(struct pci_dev *pdev)
{
struct agp_bridge_data *bridge;
bridge = agp_find_bridge(pdev);
if (!bridge)
return NULL;
if (atomic_read(&bridge->agp_in_use))
return NULL;
atomic_inc(&bridge->agp_in_use);
return bridge;
}
void agp_backend_release(struct agp_bridge_data *bridge)
{
if (bridge)
atomic_dec(&bridge->agp_in_use);
}
static int agp_find_max(void)
{
long memory, index, result;
#if PAGE_SHIFT < 20
memory = totalram_pages >> (20 - PAGE_SHIFT);
#else
memory = totalram_pages << (PAGE_SHIFT - 20);
#endif
index = 1;
while ((memory > maxes_table[index].mem) && (index < 8))
index++;
result = maxes_table[index - 1].agp +
( (memory - maxes_table[index - 1].mem) *
(maxes_table[index].agp - maxes_table[index - 1].agp)) /
(maxes_table[index].mem - maxes_table[index - 1].mem);
result = result << (20 - PAGE_SHIFT);
return result;
}
static int agp_backend_initialize(struct agp_bridge_data *bridge)
{
int size_value, rc, got_gatt=0, got_keylist=0;
bridge->max_memory_agp = agp_find_max();
bridge->version = &agp_current_version;
if (bridge->driver->needs_scratch_page) {
struct page *page = bridge->driver->agp_alloc_page(bridge);
if (!page) {
dev_err(&bridge->dev->dev,
"can't get memory for scratch page\n");
return -ENOMEM;
}
bridge->scratch_page_page = page;
bridge->scratch_page_dma = page_to_phys(page);
bridge->scratch_page = bridge->driver->mask_memory(bridge,
bridge->scratch_page_dma, 0);
}
size_value = bridge->driver->fetch_size();
if (size_value == 0) {
dev_err(&bridge->dev->dev, "can't determine aperture size\n");
rc = -EINVAL;
goto err_out;
}
if (bridge->driver->create_gatt_table(bridge)) {
dev_err(&bridge->dev->dev,
"can't get memory for graphics translation table\n");
rc = -ENOMEM;
goto err_out;
}
got_gatt = 1;
bridge->key_list = vzalloc(PAGE_SIZE * 4);
if (bridge->key_list == NULL) {
dev_err(&bridge->dev->dev,
"can't allocate memory for key lists\n");
rc = -ENOMEM;
goto err_out;
}
got_keylist = 1;
if (bridge->driver->configure()) {
dev_err(&bridge->dev->dev, "error configuring host chipset\n");
rc = -EINVAL;
goto err_out;
}
INIT_LIST_HEAD(&bridge->mapped_list);
spin_lock_init(&bridge->mapped_lock);
return 0;
err_out:
if (bridge->driver->needs_scratch_page) {
struct page *page = bridge->scratch_page_page;
bridge->driver->agp_destroy_page(page, AGP_PAGE_DESTROY_UNMAP);
bridge->driver->agp_destroy_page(page, AGP_PAGE_DESTROY_FREE);
}
if (got_gatt)
bridge->driver->free_gatt_table(bridge);
if (got_keylist) {
vfree(bridge->key_list);
bridge->key_list = NULL;
}
return rc;
}
static void agp_backend_cleanup(struct agp_bridge_data *bridge)
{
if (bridge->driver->cleanup)
bridge->driver->cleanup();
if (bridge->driver->free_gatt_table)
bridge->driver->free_gatt_table(bridge);
vfree(bridge->key_list);
bridge->key_list = NULL;
if (bridge->driver->agp_destroy_page &&
bridge->driver->needs_scratch_page) {
struct page *page = bridge->scratch_page_page;
bridge->driver->agp_destroy_page(page, AGP_PAGE_DESTROY_UNMAP);
bridge->driver->agp_destroy_page(page, AGP_PAGE_DESTROY_FREE);
}
}
struct agp_bridge_data *agp_alloc_bridge(void)
{
struct agp_bridge_data *bridge;
bridge = kzalloc(sizeof(*bridge), GFP_KERNEL);
if (!bridge)
return NULL;
atomic_set(&bridge->agp_in_use, 0);
atomic_set(&bridge->current_memory_agp, 0);
if (list_empty(&agp_bridges))
agp_bridge = bridge;
return bridge;
}
void agp_put_bridge(struct agp_bridge_data *bridge)
{
kfree(bridge);
if (list_empty(&agp_bridges))
agp_bridge = NULL;
}
int agp_add_bridge(struct agp_bridge_data *bridge)
{
int error;
if (agp_off) {
error = -ENODEV;
goto err_put_bridge;
}
if (!bridge->dev) {
printk (KERN_DEBUG PFX "Erk, registering with no pci_dev!\n");
error = -EINVAL;
goto err_put_bridge;
}
if (!try_module_get(bridge->driver->owner)) {
dev_info(&bridge->dev->dev, "can't lock chipset driver\n");
error = -EINVAL;
goto err_put_bridge;
}
error = agp_backend_initialize(bridge);
if (error) {
dev_info(&bridge->dev->dev,
"agp_backend_initialize() failed\n");
goto err_out;
}
if (list_empty(&agp_bridges)) {
error = agp_frontend_initialize();
if (error) {
dev_info(&bridge->dev->dev,
"agp_frontend_initialize() failed\n");
goto frontend_err;
}
dev_info(&bridge->dev->dev, "AGP aperture is %dM @ 0x%lx\n",
bridge->driver->fetch_size(), bridge->gart_bus_addr);
}
list_add(&bridge->list, &agp_bridges);
return 0;
frontend_err:
agp_backend_cleanup(bridge);
err_out:
module_put(bridge->driver->owner);
err_put_bridge:
agp_put_bridge(bridge);
return error;
}
void agp_remove_bridge(struct agp_bridge_data *bridge)
{
agp_backend_cleanup(bridge);
list_del(&bridge->list);
if (list_empty(&agp_bridges))
agp_frontend_cleanup();
module_put(bridge->driver->owner);
}
static int __init agp_init(void)
{
if (!agp_off)
printk(KERN_INFO "Linux agpgart interface v%d.%d\n",
AGPGART_VERSION_MAJOR, AGPGART_VERSION_MINOR);
return 0;
}
static void __exit agp_exit(void)
{
}
static __init int agp_setup(char *s)
{
if (!strcmp(s,"off"))
agp_off = 1;
if (!strcmp(s,"try_unsupported"))
agp_try_unsupported_boot = 1;
return 1;
}
