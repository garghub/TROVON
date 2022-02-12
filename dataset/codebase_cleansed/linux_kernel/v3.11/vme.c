static struct vme_dev *dev_to_vme_dev(struct device *dev)
{
return container_of(dev, struct vme_dev, dev);
}
static struct vme_bridge *find_bridge(struct vme_resource *resource)
{
switch (resource->type) {
case VME_MASTER:
return list_entry(resource->entry, struct vme_master_resource,
list)->parent;
break;
case VME_SLAVE:
return list_entry(resource->entry, struct vme_slave_resource,
list)->parent;
break;
case VME_DMA:
return list_entry(resource->entry, struct vme_dma_resource,
list)->parent;
break;
case VME_LM:
return list_entry(resource->entry, struct vme_lm_resource,
list)->parent;
break;
default:
printk(KERN_ERR "Unknown resource type\n");
return NULL;
break;
}
}
void *vme_alloc_consistent(struct vme_resource *resource, size_t size,
dma_addr_t *dma)
{
struct vme_bridge *bridge;
if (resource == NULL) {
printk(KERN_ERR "No resource\n");
return NULL;
}
bridge = find_bridge(resource);
if (bridge == NULL) {
printk(KERN_ERR "Can't find bridge\n");
return NULL;
}
if (bridge->parent == NULL) {
printk(KERN_ERR "Dev entry NULL for bridge %s\n", bridge->name);
return NULL;
}
if (bridge->alloc_consistent == NULL) {
printk(KERN_ERR "alloc_consistent not supported by bridge %s\n",
bridge->name);
return NULL;
}
return bridge->alloc_consistent(bridge->parent, size, dma);
}
void vme_free_consistent(struct vme_resource *resource, size_t size,
void *vaddr, dma_addr_t dma)
{
struct vme_bridge *bridge;
if (resource == NULL) {
printk(KERN_ERR "No resource\n");
return;
}
bridge = find_bridge(resource);
if (bridge == NULL) {
printk(KERN_ERR "Can't find bridge\n");
return;
}
if (bridge->parent == NULL) {
printk(KERN_ERR "Dev entry NULL for bridge %s\n", bridge->name);
return;
}
if (bridge->free_consistent == NULL) {
printk(KERN_ERR "free_consistent not supported by bridge %s\n",
bridge->name);
return;
}
bridge->free_consistent(bridge->parent, size, vaddr, dma);
}
size_t vme_get_size(struct vme_resource *resource)
{
int enabled, retval;
unsigned long long base, size;
dma_addr_t buf_base;
u32 aspace, cycle, dwidth;
switch (resource->type) {
case VME_MASTER:
retval = vme_master_get(resource, &enabled, &base, &size,
&aspace, &cycle, &dwidth);
return size;
break;
case VME_SLAVE:
retval = vme_slave_get(resource, &enabled, &base, &size,
&buf_base, &aspace, &cycle);
return size;
break;
case VME_DMA:
return 0;
break;
default:
printk(KERN_ERR "Unknown resource type\n");
return 0;
break;
}
}
static int vme_check_window(u32 aspace, unsigned long long vme_base,
unsigned long long size)
{
int retval = 0;
switch (aspace) {
case VME_A16:
if (((vme_base + size) > VME_A16_MAX) ||
(vme_base > VME_A16_MAX))
retval = -EFAULT;
break;
case VME_A24:
if (((vme_base + size) > VME_A24_MAX) ||
(vme_base > VME_A24_MAX))
retval = -EFAULT;
break;
case VME_A32:
if (((vme_base + size) > VME_A32_MAX) ||
(vme_base > VME_A32_MAX))
retval = -EFAULT;
break;
case VME_A64:
break;
case VME_CRCSR:
if (((vme_base + size) > VME_CRCSR_MAX) ||
(vme_base > VME_CRCSR_MAX))
retval = -EFAULT;
break;
case VME_USER1:
case VME_USER2:
case VME_USER3:
case VME_USER4:
break;
default:
printk(KERN_ERR "Invalid address space\n");
retval = -EINVAL;
break;
}
return retval;
}
struct vme_resource *vme_slave_request(struct vme_dev *vdev, u32 address,
u32 cycle)
{
struct vme_bridge *bridge;
struct list_head *slave_pos = NULL;
struct vme_slave_resource *allocated_image = NULL;
struct vme_slave_resource *slave_image = NULL;
struct vme_resource *resource = NULL;
bridge = vdev->bridge;
if (bridge == NULL) {
printk(KERN_ERR "Can't find VME bus\n");
goto err_bus;
}
list_for_each(slave_pos, &bridge->slave_resources) {
slave_image = list_entry(slave_pos,
struct vme_slave_resource, list);
if (slave_image == NULL) {
printk(KERN_ERR "Registered NULL Slave resource\n");
continue;
}
mutex_lock(&slave_image->mtx);
if (((slave_image->address_attr & address) == address) &&
((slave_image->cycle_attr & cycle) == cycle) &&
(slave_image->locked == 0)) {
slave_image->locked = 1;
mutex_unlock(&slave_image->mtx);
allocated_image = slave_image;
break;
}
mutex_unlock(&slave_image->mtx);
}
if (allocated_image == NULL)
goto err_image;
resource = kmalloc(sizeof(struct vme_resource), GFP_KERNEL);
if (resource == NULL) {
printk(KERN_WARNING "Unable to allocate resource structure\n");
goto err_alloc;
}
resource->type = VME_SLAVE;
resource->entry = &allocated_image->list;
return resource;
err_alloc:
mutex_lock(&slave_image->mtx);
slave_image->locked = 0;
mutex_unlock(&slave_image->mtx);
err_image:
err_bus:
return NULL;
}
int vme_slave_set(struct vme_resource *resource, int enabled,
unsigned long long vme_base, unsigned long long size,
dma_addr_t buf_base, u32 aspace, u32 cycle)
{
struct vme_bridge *bridge = find_bridge(resource);
struct vme_slave_resource *image;
int retval;
if (resource->type != VME_SLAVE) {
printk(KERN_ERR "Not a slave resource\n");
return -EINVAL;
}
image = list_entry(resource->entry, struct vme_slave_resource, list);
if (bridge->slave_set == NULL) {
printk(KERN_ERR "Function not supported\n");
return -ENOSYS;
}
if (!(((image->address_attr & aspace) == aspace) &&
((image->cycle_attr & cycle) == cycle))) {
printk(KERN_ERR "Invalid attributes\n");
return -EINVAL;
}
retval = vme_check_window(aspace, vme_base, size);
if (retval)
return retval;
return bridge->slave_set(image, enabled, vme_base, size, buf_base,
aspace, cycle);
}
int vme_slave_get(struct vme_resource *resource, int *enabled,
unsigned long long *vme_base, unsigned long long *size,
dma_addr_t *buf_base, u32 *aspace, u32 *cycle)
{
struct vme_bridge *bridge = find_bridge(resource);
struct vme_slave_resource *image;
if (resource->type != VME_SLAVE) {
printk(KERN_ERR "Not a slave resource\n");
return -EINVAL;
}
image = list_entry(resource->entry, struct vme_slave_resource, list);
if (bridge->slave_get == NULL) {
printk(KERN_ERR "vme_slave_get not supported\n");
return -EINVAL;
}
return bridge->slave_get(image, enabled, vme_base, size, buf_base,
aspace, cycle);
}
void vme_slave_free(struct vme_resource *resource)
{
struct vme_slave_resource *slave_image;
if (resource->type != VME_SLAVE) {
printk(KERN_ERR "Not a slave resource\n");
return;
}
slave_image = list_entry(resource->entry, struct vme_slave_resource,
list);
if (slave_image == NULL) {
printk(KERN_ERR "Can't find slave resource\n");
return;
}
mutex_lock(&slave_image->mtx);
if (slave_image->locked == 0)
printk(KERN_ERR "Image is already free\n");
slave_image->locked = 0;
mutex_unlock(&slave_image->mtx);
kfree(resource);
}
struct vme_resource *vme_master_request(struct vme_dev *vdev, u32 address,
u32 cycle, u32 dwidth)
{
struct vme_bridge *bridge;
struct list_head *master_pos = NULL;
struct vme_master_resource *allocated_image = NULL;
struct vme_master_resource *master_image = NULL;
struct vme_resource *resource = NULL;
bridge = vdev->bridge;
if (bridge == NULL) {
printk(KERN_ERR "Can't find VME bus\n");
goto err_bus;
}
list_for_each(master_pos, &bridge->master_resources) {
master_image = list_entry(master_pos,
struct vme_master_resource, list);
if (master_image == NULL) {
printk(KERN_WARNING "Registered NULL master resource\n");
continue;
}
spin_lock(&master_image->lock);
if (((master_image->address_attr & address) == address) &&
((master_image->cycle_attr & cycle) == cycle) &&
((master_image->width_attr & dwidth) == dwidth) &&
(master_image->locked == 0)) {
master_image->locked = 1;
spin_unlock(&master_image->lock);
allocated_image = master_image;
break;
}
spin_unlock(&master_image->lock);
}
if (allocated_image == NULL) {
printk(KERN_ERR "Can't find a suitable resource\n");
goto err_image;
}
resource = kmalloc(sizeof(struct vme_resource), GFP_KERNEL);
if (resource == NULL) {
printk(KERN_ERR "Unable to allocate resource structure\n");
goto err_alloc;
}
resource->type = VME_MASTER;
resource->entry = &allocated_image->list;
return resource;
err_alloc:
spin_lock(&master_image->lock);
master_image->locked = 0;
spin_unlock(&master_image->lock);
err_image:
err_bus:
return NULL;
}
int vme_master_set(struct vme_resource *resource, int enabled,
unsigned long long vme_base, unsigned long long size, u32 aspace,
u32 cycle, u32 dwidth)
{
struct vme_bridge *bridge = find_bridge(resource);
struct vme_master_resource *image;
int retval;
if (resource->type != VME_MASTER) {
printk(KERN_ERR "Not a master resource\n");
return -EINVAL;
}
image = list_entry(resource->entry, struct vme_master_resource, list);
if (bridge->master_set == NULL) {
printk(KERN_WARNING "vme_master_set not supported\n");
return -EINVAL;
}
if (!(((image->address_attr & aspace) == aspace) &&
((image->cycle_attr & cycle) == cycle) &&
((image->width_attr & dwidth) == dwidth))) {
printk(KERN_WARNING "Invalid attributes\n");
return -EINVAL;
}
retval = vme_check_window(aspace, vme_base, size);
if (retval)
return retval;
return bridge->master_set(image, enabled, vme_base, size, aspace,
cycle, dwidth);
}
int vme_master_get(struct vme_resource *resource, int *enabled,
unsigned long long *vme_base, unsigned long long *size, u32 *aspace,
u32 *cycle, u32 *dwidth)
{
struct vme_bridge *bridge = find_bridge(resource);
struct vme_master_resource *image;
if (resource->type != VME_MASTER) {
printk(KERN_ERR "Not a master resource\n");
return -EINVAL;
}
image = list_entry(resource->entry, struct vme_master_resource, list);
if (bridge->master_get == NULL) {
printk(KERN_WARNING "vme_master_set not supported\n");
return -EINVAL;
}
return bridge->master_get(image, enabled, vme_base, size, aspace,
cycle, dwidth);
}
ssize_t vme_master_read(struct vme_resource *resource, void *buf, size_t count,
loff_t offset)
{
struct vme_bridge *bridge = find_bridge(resource);
struct vme_master_resource *image;
size_t length;
if (bridge->master_read == NULL) {
printk(KERN_WARNING "Reading from resource not supported\n");
return -EINVAL;
}
if (resource->type != VME_MASTER) {
printk(KERN_ERR "Not a master resource\n");
return -EINVAL;
}
image = list_entry(resource->entry, struct vme_master_resource, list);
length = vme_get_size(resource);
if (offset > length) {
printk(KERN_WARNING "Invalid Offset\n");
return -EFAULT;
}
if ((offset + count) > length)
count = length - offset;
return bridge->master_read(image, buf, count, offset);
}
ssize_t vme_master_write(struct vme_resource *resource, void *buf,
size_t count, loff_t offset)
{
struct vme_bridge *bridge = find_bridge(resource);
struct vme_master_resource *image;
size_t length;
if (bridge->master_write == NULL) {
printk(KERN_WARNING "Writing to resource not supported\n");
return -EINVAL;
}
if (resource->type != VME_MASTER) {
printk(KERN_ERR "Not a master resource\n");
return -EINVAL;
}
image = list_entry(resource->entry, struct vme_master_resource, list);
length = vme_get_size(resource);
if (offset > length) {
printk(KERN_WARNING "Invalid Offset\n");
return -EFAULT;
}
if ((offset + count) > length)
count = length - offset;
return bridge->master_write(image, buf, count, offset);
}
unsigned int vme_master_rmw(struct vme_resource *resource, unsigned int mask,
unsigned int compare, unsigned int swap, loff_t offset)
{
struct vme_bridge *bridge = find_bridge(resource);
struct vme_master_resource *image;
if (bridge->master_rmw == NULL) {
printk(KERN_WARNING "Writing to resource not supported\n");
return -EINVAL;
}
if (resource->type != VME_MASTER) {
printk(KERN_ERR "Not a master resource\n");
return -EINVAL;
}
image = list_entry(resource->entry, struct vme_master_resource, list);
return bridge->master_rmw(image, mask, compare, swap, offset);
}
void vme_master_free(struct vme_resource *resource)
{
struct vme_master_resource *master_image;
if (resource->type != VME_MASTER) {
printk(KERN_ERR "Not a master resource\n");
return;
}
master_image = list_entry(resource->entry, struct vme_master_resource,
list);
if (master_image == NULL) {
printk(KERN_ERR "Can't find master resource\n");
return;
}
spin_lock(&master_image->lock);
if (master_image->locked == 0)
printk(KERN_ERR "Image is already free\n");
master_image->locked = 0;
spin_unlock(&master_image->lock);
kfree(resource);
}
struct vme_resource *vme_dma_request(struct vme_dev *vdev, u32 route)
{
struct vme_bridge *bridge;
struct list_head *dma_pos = NULL;
struct vme_dma_resource *allocated_ctrlr = NULL;
struct vme_dma_resource *dma_ctrlr = NULL;
struct vme_resource *resource = NULL;
printk(KERN_ERR "No VME resource Attribute tests done\n");
bridge = vdev->bridge;
if (bridge == NULL) {
printk(KERN_ERR "Can't find VME bus\n");
goto err_bus;
}
list_for_each(dma_pos, &bridge->dma_resources) {
dma_ctrlr = list_entry(dma_pos,
struct vme_dma_resource, list);
if (dma_ctrlr == NULL) {
printk(KERN_ERR "Registered NULL DMA resource\n");
continue;
}
mutex_lock(&dma_ctrlr->mtx);
if (((dma_ctrlr->route_attr & route) == route) &&
(dma_ctrlr->locked == 0)) {
dma_ctrlr->locked = 1;
mutex_unlock(&dma_ctrlr->mtx);
allocated_ctrlr = dma_ctrlr;
break;
}
mutex_unlock(&dma_ctrlr->mtx);
}
if (allocated_ctrlr == NULL)
goto err_ctrlr;
resource = kmalloc(sizeof(struct vme_resource), GFP_KERNEL);
if (resource == NULL) {
printk(KERN_WARNING "Unable to allocate resource structure\n");
goto err_alloc;
}
resource->type = VME_DMA;
resource->entry = &allocated_ctrlr->list;
return resource;
err_alloc:
mutex_lock(&dma_ctrlr->mtx);
dma_ctrlr->locked = 0;
mutex_unlock(&dma_ctrlr->mtx);
err_ctrlr:
err_bus:
return NULL;
}
struct vme_dma_list *vme_new_dma_list(struct vme_resource *resource)
{
struct vme_dma_resource *ctrlr;
struct vme_dma_list *dma_list;
if (resource->type != VME_DMA) {
printk(KERN_ERR "Not a DMA resource\n");
return NULL;
}
ctrlr = list_entry(resource->entry, struct vme_dma_resource, list);
dma_list = kmalloc(sizeof(struct vme_dma_list), GFP_KERNEL);
if (dma_list == NULL) {
printk(KERN_ERR "Unable to allocate memory for new dma list\n");
return NULL;
}
INIT_LIST_HEAD(&dma_list->entries);
dma_list->parent = ctrlr;
mutex_init(&dma_list->mtx);
return dma_list;
}
struct vme_dma_attr *vme_dma_pattern_attribute(u32 pattern, u32 type)
{
struct vme_dma_attr *attributes;
struct vme_dma_pattern *pattern_attr;
attributes = kmalloc(sizeof(struct vme_dma_attr), GFP_KERNEL);
if (attributes == NULL) {
printk(KERN_ERR "Unable to allocate memory for attributes structure\n");
goto err_attr;
}
pattern_attr = kmalloc(sizeof(struct vme_dma_pattern), GFP_KERNEL);
if (pattern_attr == NULL) {
printk(KERN_ERR "Unable to allocate memory for pattern attributes\n");
goto err_pat;
}
attributes->type = VME_DMA_PATTERN;
attributes->private = (void *)pattern_attr;
pattern_attr->pattern = pattern;
pattern_attr->type = type;
return attributes;
err_pat:
kfree(attributes);
err_attr:
return NULL;
}
struct vme_dma_attr *vme_dma_pci_attribute(dma_addr_t address)
{
struct vme_dma_attr *attributes;
struct vme_dma_pci *pci_attr;
attributes = kmalloc(sizeof(struct vme_dma_attr), GFP_KERNEL);
if (attributes == NULL) {
printk(KERN_ERR "Unable to allocate memory for attributes structure\n");
goto err_attr;
}
pci_attr = kmalloc(sizeof(struct vme_dma_pci), GFP_KERNEL);
if (pci_attr == NULL) {
printk(KERN_ERR "Unable to allocate memory for pci attributes\n");
goto err_pci;
}
attributes->type = VME_DMA_PCI;
attributes->private = (void *)pci_attr;
pci_attr->address = address;
return attributes;
err_pci:
kfree(attributes);
err_attr:
return NULL;
}
struct vme_dma_attr *vme_dma_vme_attribute(unsigned long long address,
u32 aspace, u32 cycle, u32 dwidth)
{
struct vme_dma_attr *attributes;
struct vme_dma_vme *vme_attr;
attributes = kmalloc(
sizeof(struct vme_dma_attr), GFP_KERNEL);
if (attributes == NULL) {
printk(KERN_ERR "Unable to allocate memory for attributes structure\n");
goto err_attr;
}
vme_attr = kmalloc(sizeof(struct vme_dma_vme), GFP_KERNEL);
if (vme_attr == NULL) {
printk(KERN_ERR "Unable to allocate memory for vme attributes\n");
goto err_vme;
}
attributes->type = VME_DMA_VME;
attributes->private = (void *)vme_attr;
vme_attr->address = address;
vme_attr->aspace = aspace;
vme_attr->cycle = cycle;
vme_attr->dwidth = dwidth;
return attributes;
err_vme:
kfree(attributes);
err_attr:
return NULL;
}
void vme_dma_free_attribute(struct vme_dma_attr *attributes)
{
kfree(attributes->private);
kfree(attributes);
}
int vme_dma_list_add(struct vme_dma_list *list, struct vme_dma_attr *src,
struct vme_dma_attr *dest, size_t count)
{
struct vme_bridge *bridge = list->parent->parent;
int retval;
if (bridge->dma_list_add == NULL) {
printk(KERN_WARNING "Link List DMA generation not supported\n");
return -EINVAL;
}
if (!mutex_trylock(&list->mtx)) {
printk(KERN_ERR "Link List already submitted\n");
return -EINVAL;
}
retval = bridge->dma_list_add(list, src, dest, count);
mutex_unlock(&list->mtx);
return retval;
}
int vme_dma_list_exec(struct vme_dma_list *list)
{
struct vme_bridge *bridge = list->parent->parent;
int retval;
if (bridge->dma_list_exec == NULL) {
printk(KERN_ERR "Link List DMA execution not supported\n");
return -EINVAL;
}
mutex_lock(&list->mtx);
retval = bridge->dma_list_exec(list);
mutex_unlock(&list->mtx);
return retval;
}
int vme_dma_list_free(struct vme_dma_list *list)
{
struct vme_bridge *bridge = list->parent->parent;
int retval;
if (bridge->dma_list_empty == NULL) {
printk(KERN_WARNING "Emptying of Link Lists not supported\n");
return -EINVAL;
}
if (!mutex_trylock(&list->mtx)) {
printk(KERN_ERR "Link List in use\n");
return -EINVAL;
}
retval = bridge->dma_list_empty(list);
if (retval) {
printk(KERN_ERR "Unable to empty link-list entries\n");
mutex_unlock(&list->mtx);
return retval;
}
mutex_unlock(&list->mtx);
kfree(list);
return retval;
}
int vme_dma_free(struct vme_resource *resource)
{
struct vme_dma_resource *ctrlr;
if (resource->type != VME_DMA) {
printk(KERN_ERR "Not a DMA resource\n");
return -EINVAL;
}
ctrlr = list_entry(resource->entry, struct vme_dma_resource, list);
if (!mutex_trylock(&ctrlr->mtx)) {
printk(KERN_ERR "Resource busy, can't free\n");
return -EBUSY;
}
if (!(list_empty(&ctrlr->pending) && list_empty(&ctrlr->running))) {
printk(KERN_WARNING "Resource still processing transfers\n");
mutex_unlock(&ctrlr->mtx);
return -EBUSY;
}
ctrlr->locked = 0;
mutex_unlock(&ctrlr->mtx);
kfree(resource);
return 0;
}
void vme_irq_handler(struct vme_bridge *bridge, int level, int statid)
{
void (*call)(int, int, void *);
void *priv_data;
call = bridge->irq[level - 1].callback[statid].func;
priv_data = bridge->irq[level - 1].callback[statid].priv_data;
if (call != NULL)
call(level, statid, priv_data);
else
printk(KERN_WARNING "Spurilous VME interrupt, level:%x, vector:%x\n",
level, statid);
}
int vme_irq_request(struct vme_dev *vdev, int level, int statid,
void (*callback)(int, int, void *),
void *priv_data)
{
struct vme_bridge *bridge;
bridge = vdev->bridge;
if (bridge == NULL) {
printk(KERN_ERR "Can't find VME bus\n");
return -EINVAL;
}
if ((level < 1) || (level > 7)) {
printk(KERN_ERR "Invalid interrupt level\n");
return -EINVAL;
}
if (bridge->irq_set == NULL) {
printk(KERN_ERR "Configuring interrupts not supported\n");
return -EINVAL;
}
mutex_lock(&bridge->irq_mtx);
if (bridge->irq[level - 1].callback[statid].func) {
mutex_unlock(&bridge->irq_mtx);
printk(KERN_WARNING "VME Interrupt already taken\n");
return -EBUSY;
}
bridge->irq[level - 1].count++;
bridge->irq[level - 1].callback[statid].priv_data = priv_data;
bridge->irq[level - 1].callback[statid].func = callback;
bridge->irq_set(bridge, level, 1, 1);
mutex_unlock(&bridge->irq_mtx);
return 0;
}
void vme_irq_free(struct vme_dev *vdev, int level, int statid)
{
struct vme_bridge *bridge;
bridge = vdev->bridge;
if (bridge == NULL) {
printk(KERN_ERR "Can't find VME bus\n");
return;
}
if ((level < 1) || (level > 7)) {
printk(KERN_ERR "Invalid interrupt level\n");
return;
}
if (bridge->irq_set == NULL) {
printk(KERN_ERR "Configuring interrupts not supported\n");
return;
}
mutex_lock(&bridge->irq_mtx);
bridge->irq[level - 1].count--;
if (bridge->irq[level - 1].count == 0)
bridge->irq_set(bridge, level, 0, 1);
bridge->irq[level - 1].callback[statid].func = NULL;
bridge->irq[level - 1].callback[statid].priv_data = NULL;
mutex_unlock(&bridge->irq_mtx);
}
int vme_irq_generate(struct vme_dev *vdev, int level, int statid)
{
struct vme_bridge *bridge;
bridge = vdev->bridge;
if (bridge == NULL) {
printk(KERN_ERR "Can't find VME bus\n");
return -EINVAL;
}
if ((level < 1) || (level > 7)) {
printk(KERN_WARNING "Invalid interrupt level\n");
return -EINVAL;
}
if (bridge->irq_generate == NULL) {
printk(KERN_WARNING "Interrupt generation not supported\n");
return -EINVAL;
}
return bridge->irq_generate(bridge, level, statid);
}
struct vme_resource *vme_lm_request(struct vme_dev *vdev)
{
struct vme_bridge *bridge;
struct list_head *lm_pos = NULL;
struct vme_lm_resource *allocated_lm = NULL;
struct vme_lm_resource *lm = NULL;
struct vme_resource *resource = NULL;
bridge = vdev->bridge;
if (bridge == NULL) {
printk(KERN_ERR "Can't find VME bus\n");
goto err_bus;
}
list_for_each(lm_pos, &bridge->lm_resources) {
lm = list_entry(lm_pos,
struct vme_lm_resource, list);
if (lm == NULL) {
printk(KERN_ERR "Registered NULL Location Monitor resource\n");
continue;
}
mutex_lock(&lm->mtx);
if (lm->locked == 0) {
lm->locked = 1;
mutex_unlock(&lm->mtx);
allocated_lm = lm;
break;
}
mutex_unlock(&lm->mtx);
}
if (allocated_lm == NULL)
goto err_lm;
resource = kmalloc(sizeof(struct vme_resource), GFP_KERNEL);
if (resource == NULL) {
printk(KERN_ERR "Unable to allocate resource structure\n");
goto err_alloc;
}
resource->type = VME_LM;
resource->entry = &allocated_lm->list;
return resource;
err_alloc:
mutex_lock(&lm->mtx);
lm->locked = 0;
mutex_unlock(&lm->mtx);
err_lm:
err_bus:
return NULL;
}
int vme_lm_count(struct vme_resource *resource)
{
struct vme_lm_resource *lm;
if (resource->type != VME_LM) {
printk(KERN_ERR "Not a Location Monitor resource\n");
return -EINVAL;
}
lm = list_entry(resource->entry, struct vme_lm_resource, list);
return lm->monitors;
}
int vme_lm_set(struct vme_resource *resource, unsigned long long lm_base,
u32 aspace, u32 cycle)
{
struct vme_bridge *bridge = find_bridge(resource);
struct vme_lm_resource *lm;
if (resource->type != VME_LM) {
printk(KERN_ERR "Not a Location Monitor resource\n");
return -EINVAL;
}
lm = list_entry(resource->entry, struct vme_lm_resource, list);
if (bridge->lm_set == NULL) {
printk(KERN_ERR "vme_lm_set not supported\n");
return -EINVAL;
}
return bridge->lm_set(lm, lm_base, aspace, cycle);
}
int vme_lm_get(struct vme_resource *resource, unsigned long long *lm_base,
u32 *aspace, u32 *cycle)
{
struct vme_bridge *bridge = find_bridge(resource);
struct vme_lm_resource *lm;
if (resource->type != VME_LM) {
printk(KERN_ERR "Not a Location Monitor resource\n");
return -EINVAL;
}
lm = list_entry(resource->entry, struct vme_lm_resource, list);
if (bridge->lm_get == NULL) {
printk(KERN_ERR "vme_lm_get not supported\n");
return -EINVAL;
}
return bridge->lm_get(lm, lm_base, aspace, cycle);
}
int vme_lm_attach(struct vme_resource *resource, int monitor,
void (*callback)(int))
{
struct vme_bridge *bridge = find_bridge(resource);
struct vme_lm_resource *lm;
if (resource->type != VME_LM) {
printk(KERN_ERR "Not a Location Monitor resource\n");
return -EINVAL;
}
lm = list_entry(resource->entry, struct vme_lm_resource, list);
if (bridge->lm_attach == NULL) {
printk(KERN_ERR "vme_lm_attach not supported\n");
return -EINVAL;
}
return bridge->lm_attach(lm, monitor, callback);
}
int vme_lm_detach(struct vme_resource *resource, int monitor)
{
struct vme_bridge *bridge = find_bridge(resource);
struct vme_lm_resource *lm;
if (resource->type != VME_LM) {
printk(KERN_ERR "Not a Location Monitor resource\n");
return -EINVAL;
}
lm = list_entry(resource->entry, struct vme_lm_resource, list);
if (bridge->lm_detach == NULL) {
printk(KERN_ERR "vme_lm_detach not supported\n");
return -EINVAL;
}
return bridge->lm_detach(lm, monitor);
}
void vme_lm_free(struct vme_resource *resource)
{
struct vme_lm_resource *lm;
if (resource->type != VME_LM) {
printk(KERN_ERR "Not a Location Monitor resource\n");
return;
}
lm = list_entry(resource->entry, struct vme_lm_resource, list);
mutex_lock(&lm->mtx);
lm->locked = 0;
mutex_unlock(&lm->mtx);
kfree(resource);
}
int vme_slot_get(struct vme_dev *vdev)
{
struct vme_bridge *bridge;
bridge = vdev->bridge;
if (bridge == NULL) {
printk(KERN_ERR "Can't find VME bus\n");
return -EINVAL;
}
if (bridge->slot_get == NULL) {
printk(KERN_WARNING "vme_slot_get not supported\n");
return -EINVAL;
}
return bridge->slot_get(bridge);
}
static void vme_dev_release(struct device *dev)
{
kfree(dev_to_vme_dev(dev));
}
int vme_register_bridge(struct vme_bridge *bridge)
{
int i;
int ret = -1;
mutex_lock(&vme_buses_lock);
for (i = 0; i < sizeof(vme_bus_numbers) * 8; i++) {
if ((vme_bus_numbers & (1 << i)) == 0) {
vme_bus_numbers |= (1 << i);
bridge->num = i;
INIT_LIST_HEAD(&bridge->devices);
list_add_tail(&bridge->bus_list, &vme_bus_list);
ret = 0;
break;
}
}
mutex_unlock(&vme_buses_lock);
return ret;
}
void vme_unregister_bridge(struct vme_bridge *bridge)
{
struct vme_dev *vdev;
struct vme_dev *tmp;
mutex_lock(&vme_buses_lock);
vme_bus_numbers &= ~(1 << bridge->num);
list_for_each_entry_safe(vdev, tmp, &bridge->devices, bridge_list) {
list_del(&vdev->drv_list);
list_del(&vdev->bridge_list);
device_unregister(&vdev->dev);
}
list_del(&bridge->bus_list);
mutex_unlock(&vme_buses_lock);
}
static int __vme_register_driver_bus(struct vme_driver *drv,
struct vme_bridge *bridge, unsigned int ndevs)
{
int err;
unsigned int i;
struct vme_dev *vdev;
struct vme_dev *tmp;
for (i = 0; i < ndevs; i++) {
vdev = kzalloc(sizeof(struct vme_dev), GFP_KERNEL);
if (!vdev) {
err = -ENOMEM;
goto err_devalloc;
}
vdev->num = i;
vdev->bridge = bridge;
vdev->dev.platform_data = drv;
vdev->dev.release = vme_dev_release;
vdev->dev.parent = bridge->parent;
vdev->dev.bus = &vme_bus_type;
dev_set_name(&vdev->dev, "%s.%u-%u", drv->name, bridge->num,
vdev->num);
err = device_register(&vdev->dev);
if (err)
goto err_reg;
if (vdev->dev.platform_data) {
list_add_tail(&vdev->drv_list, &drv->devices);
list_add_tail(&vdev->bridge_list, &bridge->devices);
} else
device_unregister(&vdev->dev);
}
return 0;
err_reg:
put_device(&vdev->dev);
kfree(vdev);
err_devalloc:
list_for_each_entry_safe(vdev, tmp, &drv->devices, drv_list) {
list_del(&vdev->drv_list);
list_del(&vdev->bridge_list);
device_unregister(&vdev->dev);
}
return err;
}
static int __vme_register_driver(struct vme_driver *drv, unsigned int ndevs)
{
struct vme_bridge *bridge;
int err = 0;
mutex_lock(&vme_buses_lock);
list_for_each_entry(bridge, &vme_bus_list, bus_list) {
err = __vme_register_driver_bus(drv, bridge, ndevs);
if (err)
break;
}
mutex_unlock(&vme_buses_lock);
return err;
}
int vme_register_driver(struct vme_driver *drv, unsigned int ndevs)
{
int err;
drv->driver.name = drv->name;
drv->driver.bus = &vme_bus_type;
INIT_LIST_HEAD(&drv->devices);
err = driver_register(&drv->driver);
if (err)
return err;
err = __vme_register_driver(drv, ndevs);
if (err)
driver_unregister(&drv->driver);
return err;
}
void vme_unregister_driver(struct vme_driver *drv)
{
struct vme_dev *dev, *dev_tmp;
mutex_lock(&vme_buses_lock);
list_for_each_entry_safe(dev, dev_tmp, &drv->devices, drv_list) {
list_del(&dev->drv_list);
list_del(&dev->bridge_list);
device_unregister(&dev->dev);
}
mutex_unlock(&vme_buses_lock);
driver_unregister(&drv->driver);
}
static int vme_bus_match(struct device *dev, struct device_driver *drv)
{
struct vme_driver *vme_drv;
vme_drv = container_of(drv, struct vme_driver, driver);
if (dev->platform_data == vme_drv) {
struct vme_dev *vdev = dev_to_vme_dev(dev);
if (vme_drv->match && vme_drv->match(vdev))
return 1;
dev->platform_data = NULL;
}
return 0;
}
static int vme_bus_probe(struct device *dev)
{
int retval = -ENODEV;
struct vme_driver *driver;
struct vme_dev *vdev = dev_to_vme_dev(dev);
driver = dev->platform_data;
if (driver->probe != NULL)
retval = driver->probe(vdev);
return retval;
}
static int vme_bus_remove(struct device *dev)
{
int retval = -ENODEV;
struct vme_driver *driver;
struct vme_dev *vdev = dev_to_vme_dev(dev);
driver = dev->platform_data;
if (driver->remove != NULL)
retval = driver->remove(vdev);
return retval;
}
static int __init vme_init(void)
{
return bus_register(&vme_bus_type);
}
static void __exit vme_exit(void)
{
bus_unregister(&vme_bus_type);
}
