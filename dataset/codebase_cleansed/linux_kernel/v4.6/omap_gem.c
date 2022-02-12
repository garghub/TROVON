static uint64_t mmap_offset(struct drm_gem_object *obj)
{
struct drm_device *dev = obj->dev;
int ret;
size_t size;
WARN_ON(!mutex_is_locked(&dev->struct_mutex));
size = omap_gem_mmap_size(obj);
ret = drm_gem_create_mmap_offset_size(obj, size);
if (ret) {
dev_err(dev->dev, "could not allocate mmap offset\n");
return 0;
}
return drm_vma_node_offset_addr(&obj->vma_node);
}
static bool is_contiguous(struct omap_gem_object *omap_obj)
{
if (omap_obj->flags & OMAP_BO_MEM_DMA_API)
return true;
if ((omap_obj->flags & OMAP_BO_MEM_DMABUF) && omap_obj->sgt->nents == 1)
return true;
return false;
}
static void evict_entry(struct drm_gem_object *obj,
enum tiler_fmt fmt, struct omap_drm_usergart_entry *entry)
{
struct omap_gem_object *omap_obj = to_omap_bo(obj);
struct omap_drm_private *priv = obj->dev->dev_private;
int n = priv->usergart[fmt].height;
size_t size = PAGE_SIZE * n;
loff_t off = mmap_offset(obj) +
(entry->obj_pgoff << PAGE_SHIFT);
const int m = 1 + ((omap_obj->width << fmt) / PAGE_SIZE);
if (m > 1) {
int i;
for (i = n; i > 0; i--) {
unmap_mapping_range(obj->dev->anon_inode->i_mapping,
off, PAGE_SIZE, 1);
off += PAGE_SIZE * m;
}
} else {
unmap_mapping_range(obj->dev->anon_inode->i_mapping,
off, size, 1);
}
entry->obj = NULL;
}
static void evict(struct drm_gem_object *obj)
{
struct omap_gem_object *omap_obj = to_omap_bo(obj);
struct omap_drm_private *priv = obj->dev->dev_private;
if (omap_obj->flags & OMAP_BO_TILED) {
enum tiler_fmt fmt = gem2fmt(omap_obj->flags);
int i;
for (i = 0; i < NUM_USERGART_ENTRIES; i++) {
struct omap_drm_usergart_entry *entry =
&priv->usergart[fmt].entry[i];
if (entry->obj == obj)
evict_entry(obj, fmt, entry);
}
}
}
static int omap_gem_attach_pages(struct drm_gem_object *obj)
{
struct drm_device *dev = obj->dev;
struct omap_gem_object *omap_obj = to_omap_bo(obj);
struct page **pages;
int npages = obj->size >> PAGE_SHIFT;
int i, ret;
dma_addr_t *addrs;
WARN_ON(omap_obj->pages);
pages = drm_gem_get_pages(obj);
if (IS_ERR(pages)) {
dev_err(obj->dev->dev, "could not get pages: %ld\n", PTR_ERR(pages));
return PTR_ERR(pages);
}
if (omap_obj->flags & (OMAP_BO_WC|OMAP_BO_UNCACHED)) {
addrs = kmalloc(npages * sizeof(*addrs), GFP_KERNEL);
if (!addrs) {
ret = -ENOMEM;
goto free_pages;
}
for (i = 0; i < npages; i++) {
addrs[i] = dma_map_page(dev->dev, pages[i],
0, PAGE_SIZE, DMA_BIDIRECTIONAL);
if (dma_mapping_error(dev->dev, addrs[i])) {
dev_warn(dev->dev,
"%s: failed to map page\n", __func__);
for (i = i - 1; i >= 0; --i) {
dma_unmap_page(dev->dev, addrs[i],
PAGE_SIZE, DMA_BIDIRECTIONAL);
}
ret = -ENOMEM;
goto free_addrs;
}
}
} else {
addrs = kzalloc(npages * sizeof(*addrs), GFP_KERNEL);
if (!addrs) {
ret = -ENOMEM;
goto free_pages;
}
}
omap_obj->addrs = addrs;
omap_obj->pages = pages;
return 0;
free_addrs:
kfree(addrs);
free_pages:
drm_gem_put_pages(obj, pages, true, false);
return ret;
}
static int get_pages(struct drm_gem_object *obj, struct page ***pages)
{
struct omap_gem_object *omap_obj = to_omap_bo(obj);
int ret = 0;
if ((omap_obj->flags & OMAP_BO_MEM_SHMEM) && !omap_obj->pages) {
ret = omap_gem_attach_pages(obj);
if (ret) {
dev_err(obj->dev->dev, "could not attach pages\n");
return ret;
}
}
*pages = omap_obj->pages;
return 0;
}
static void omap_gem_detach_pages(struct drm_gem_object *obj)
{
struct omap_gem_object *omap_obj = to_omap_bo(obj);
if (omap_obj->flags & (OMAP_BO_WC|OMAP_BO_UNCACHED)) {
int i, npages = obj->size >> PAGE_SHIFT;
for (i = 0; i < npages; i++) {
dma_unmap_page(obj->dev->dev, omap_obj->addrs[i],
PAGE_SIZE, DMA_BIDIRECTIONAL);
}
}
kfree(omap_obj->addrs);
omap_obj->addrs = NULL;
drm_gem_put_pages(obj, omap_obj->pages, true, false);
omap_obj->pages = NULL;
}
uint32_t omap_gem_flags(struct drm_gem_object *obj)
{
return to_omap_bo(obj)->flags;
}
uint64_t omap_gem_mmap_offset(struct drm_gem_object *obj)
{
uint64_t offset;
mutex_lock(&obj->dev->struct_mutex);
offset = mmap_offset(obj);
mutex_unlock(&obj->dev->struct_mutex);
return offset;
}
size_t omap_gem_mmap_size(struct drm_gem_object *obj)
{
struct omap_gem_object *omap_obj = to_omap_bo(obj);
size_t size = obj->size;
if (omap_obj->flags & OMAP_BO_TILED) {
size = tiler_vsize(gem2fmt(omap_obj->flags),
omap_obj->width, omap_obj->height);
}
return size;
}
int omap_gem_tiled_size(struct drm_gem_object *obj, uint16_t *w, uint16_t *h)
{
struct omap_gem_object *omap_obj = to_omap_bo(obj);
if (omap_obj->flags & OMAP_BO_TILED) {
*w = omap_obj->width;
*h = omap_obj->height;
return 0;
}
return -EINVAL;
}
static int fault_1d(struct drm_gem_object *obj,
struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct omap_gem_object *omap_obj = to_omap_bo(obj);
unsigned long pfn;
pgoff_t pgoff;
pgoff = ((unsigned long)vmf->virtual_address -
vma->vm_start) >> PAGE_SHIFT;
if (omap_obj->pages) {
omap_gem_cpu_sync(obj, pgoff);
pfn = page_to_pfn(omap_obj->pages[pgoff]);
} else {
BUG_ON(!is_contiguous(omap_obj));
pfn = (omap_obj->paddr >> PAGE_SHIFT) + pgoff;
}
VERB("Inserting %p pfn %lx, pa %lx", vmf->virtual_address,
pfn, pfn << PAGE_SHIFT);
return vm_insert_mixed(vma, (unsigned long)vmf->virtual_address,
__pfn_to_pfn_t(pfn, PFN_DEV));
}
static int fault_2d(struct drm_gem_object *obj,
struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct omap_gem_object *omap_obj = to_omap_bo(obj);
struct omap_drm_private *priv = obj->dev->dev_private;
struct omap_drm_usergart_entry *entry;
enum tiler_fmt fmt = gem2fmt(omap_obj->flags);
struct page *pages[64];
unsigned long pfn;
pgoff_t pgoff, base_pgoff;
void __user *vaddr;
int i, ret, slots;
const int n = priv->usergart[fmt].height;
const int n_shift = priv->usergart[fmt].height_shift;
const int m = 1 + ((omap_obj->width << fmt) / PAGE_SIZE);
pgoff = ((unsigned long)vmf->virtual_address -
vma->vm_start) >> PAGE_SHIFT;
base_pgoff = round_down(pgoff, m << n_shift);
slots = omap_obj->width >> priv->usergart[fmt].slot_shift;
vaddr = vmf->virtual_address - ((pgoff - base_pgoff) << PAGE_SHIFT);
entry = &priv->usergart[fmt].entry[priv->usergart[fmt].last];
if (entry->obj)
evict_entry(entry->obj, fmt, entry);
entry->obj = obj;
entry->obj_pgoff = base_pgoff;
base_pgoff = (base_pgoff >> n_shift) * slots;
if (m > 1) {
int off = pgoff % m;
entry->obj_pgoff += off;
base_pgoff /= m;
slots = min(slots - (off << n_shift), n);
base_pgoff += off << n_shift;
vaddr += off << PAGE_SHIFT;
}
memcpy(pages, &omap_obj->pages[base_pgoff],
sizeof(struct page *) * slots);
memset(pages + slots, 0,
sizeof(struct page *) * (n - slots));
ret = tiler_pin(entry->block, pages, ARRAY_SIZE(pages), 0, true);
if (ret) {
dev_err(obj->dev->dev, "failed to pin: %d\n", ret);
return ret;
}
pfn = entry->paddr >> PAGE_SHIFT;
VERB("Inserting %p pfn %lx, pa %lx", vmf->virtual_address,
pfn, pfn << PAGE_SHIFT);
for (i = n; i > 0; i--) {
vm_insert_mixed(vma, (unsigned long)vaddr,
__pfn_to_pfn_t(pfn, PFN_DEV));
pfn += priv->usergart[fmt].stride_pfn;
vaddr += PAGE_SIZE * m;
}
priv->usergart[fmt].last = (priv->usergart[fmt].last + 1)
% NUM_USERGART_ENTRIES;
return 0;
}
int omap_gem_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct drm_gem_object *obj = vma->vm_private_data;
struct omap_gem_object *omap_obj = to_omap_bo(obj);
struct drm_device *dev = obj->dev;
struct page **pages;
int ret;
mutex_lock(&dev->struct_mutex);
ret = get_pages(obj, &pages);
if (ret)
goto fail;
if (omap_obj->flags & OMAP_BO_TILED)
ret = fault_2d(obj, vma, vmf);
else
ret = fault_1d(obj, vma, vmf);
fail:
mutex_unlock(&dev->struct_mutex);
switch (ret) {
case 0:
case -ERESTARTSYS:
case -EINTR:
case -EBUSY:
return VM_FAULT_NOPAGE;
case -ENOMEM:
return VM_FAULT_OOM;
default:
return VM_FAULT_SIGBUS;
}
}
int omap_gem_mmap(struct file *filp, struct vm_area_struct *vma)
{
int ret;
ret = drm_gem_mmap(filp, vma);
if (ret) {
DBG("mmap failed: %d", ret);
return ret;
}
return omap_gem_mmap_obj(vma->vm_private_data, vma);
}
int omap_gem_mmap_obj(struct drm_gem_object *obj,
struct vm_area_struct *vma)
{
struct omap_gem_object *omap_obj = to_omap_bo(obj);
vma->vm_flags &= ~VM_PFNMAP;
vma->vm_flags |= VM_MIXEDMAP;
if (omap_obj->flags & OMAP_BO_WC) {
vma->vm_page_prot = pgprot_writecombine(vm_get_page_prot(vma->vm_flags));
} else if (omap_obj->flags & OMAP_BO_UNCACHED) {
vma->vm_page_prot = pgprot_noncached(vm_get_page_prot(vma->vm_flags));
} else {
if (WARN_ON(!obj->filp))
return -EINVAL;
fput(vma->vm_file);
vma->vm_pgoff = 0;
vma->vm_file = get_file(obj->filp);
vma->vm_page_prot = vm_get_page_prot(vma->vm_flags);
}
return 0;
}
int omap_gem_dumb_create(struct drm_file *file, struct drm_device *dev,
struct drm_mode_create_dumb *args)
{
union omap_gem_size gsize;
args->pitch = align_pitch(0, args->width, args->bpp);
args->size = PAGE_ALIGN(args->pitch * args->height);
gsize = (union omap_gem_size){
.bytes = args->size,
};
return omap_gem_new_handle(dev, file, gsize,
OMAP_BO_SCANOUT | OMAP_BO_WC, &args->handle);
}
int omap_gem_dumb_map_offset(struct drm_file *file, struct drm_device *dev,
uint32_t handle, uint64_t *offset)
{
struct drm_gem_object *obj;
int ret = 0;
obj = drm_gem_object_lookup(dev, file, handle);
if (obj == NULL) {
ret = -ENOENT;
goto fail;
}
*offset = omap_gem_mmap_offset(obj);
drm_gem_object_unreference_unlocked(obj);
fail:
return ret;
}
int omap_gem_roll(struct drm_gem_object *obj, uint32_t roll)
{
struct omap_gem_object *omap_obj = to_omap_bo(obj);
uint32_t npages = obj->size >> PAGE_SHIFT;
int ret = 0;
if (roll > npages) {
dev_err(obj->dev->dev, "invalid roll: %d\n", roll);
return -EINVAL;
}
omap_obj->roll = roll;
mutex_lock(&obj->dev->struct_mutex);
if (omap_obj->block) {
struct page **pages;
ret = get_pages(obj, &pages);
if (ret)
goto fail;
ret = tiler_pin(omap_obj->block, pages, npages, roll, true);
if (ret)
dev_err(obj->dev->dev, "could not repin: %d\n", ret);
}
fail:
mutex_unlock(&obj->dev->struct_mutex);
return ret;
}
static inline bool is_cached_coherent(struct drm_gem_object *obj)
{
struct omap_gem_object *omap_obj = to_omap_bo(obj);
return (omap_obj->flags & OMAP_BO_MEM_SHMEM) &&
((omap_obj->flags & OMAP_BO_CACHE_MASK) == OMAP_BO_CACHED);
}
void omap_gem_cpu_sync(struct drm_gem_object *obj, int pgoff)
{
struct drm_device *dev = obj->dev;
struct omap_gem_object *omap_obj = to_omap_bo(obj);
if (is_cached_coherent(obj) && omap_obj->addrs[pgoff]) {
dma_unmap_page(dev->dev, omap_obj->addrs[pgoff],
PAGE_SIZE, DMA_BIDIRECTIONAL);
omap_obj->addrs[pgoff] = 0;
}
}
void omap_gem_dma_sync(struct drm_gem_object *obj,
enum dma_data_direction dir)
{
struct drm_device *dev = obj->dev;
struct omap_gem_object *omap_obj = to_omap_bo(obj);
if (is_cached_coherent(obj)) {
int i, npages = obj->size >> PAGE_SHIFT;
struct page **pages = omap_obj->pages;
bool dirty = false;
for (i = 0; i < npages; i++) {
if (!omap_obj->addrs[i]) {
dma_addr_t addr;
addr = dma_map_page(dev->dev, pages[i], 0,
PAGE_SIZE, DMA_BIDIRECTIONAL);
if (dma_mapping_error(dev->dev, addr)) {
dev_warn(dev->dev,
"%s: failed to map page\n",
__func__);
break;
}
dirty = true;
omap_obj->addrs[i] = addr;
}
}
if (dirty) {
unmap_mapping_range(obj->filp->f_mapping, 0,
omap_gem_mmap_size(obj), 1);
}
}
}
int omap_gem_get_paddr(struct drm_gem_object *obj,
dma_addr_t *paddr, bool remap)
{
struct omap_drm_private *priv = obj->dev->dev_private;
struct omap_gem_object *omap_obj = to_omap_bo(obj);
int ret = 0;
mutex_lock(&obj->dev->struct_mutex);
if (!is_contiguous(omap_obj) && remap && priv->has_dmm) {
if (omap_obj->paddr_cnt == 0) {
struct page **pages;
uint32_t npages = obj->size >> PAGE_SHIFT;
enum tiler_fmt fmt = gem2fmt(omap_obj->flags);
struct tiler_block *block;
BUG_ON(omap_obj->block);
ret = get_pages(obj, &pages);
if (ret)
goto fail;
if (omap_obj->flags & OMAP_BO_TILED) {
block = tiler_reserve_2d(fmt,
omap_obj->width,
omap_obj->height, 0);
} else {
block = tiler_reserve_1d(obj->size);
}
if (IS_ERR(block)) {
ret = PTR_ERR(block);
dev_err(obj->dev->dev,
"could not remap: %d (%d)\n", ret, fmt);
goto fail;
}
ret = tiler_pin(block, pages, npages,
omap_obj->roll, true);
if (ret) {
tiler_release(block);
dev_err(obj->dev->dev,
"could not pin: %d\n", ret);
goto fail;
}
omap_obj->paddr = tiler_ssptr(block);
omap_obj->block = block;
DBG("got paddr: %pad", &omap_obj->paddr);
}
omap_obj->paddr_cnt++;
*paddr = omap_obj->paddr;
} else if (is_contiguous(omap_obj)) {
*paddr = omap_obj->paddr;
} else {
ret = -EINVAL;
goto fail;
}
fail:
mutex_unlock(&obj->dev->struct_mutex);
return ret;
}
void omap_gem_put_paddr(struct drm_gem_object *obj)
{
struct omap_gem_object *omap_obj = to_omap_bo(obj);
int ret;
mutex_lock(&obj->dev->struct_mutex);
if (omap_obj->paddr_cnt > 0) {
omap_obj->paddr_cnt--;
if (omap_obj->paddr_cnt == 0) {
ret = tiler_unpin(omap_obj->block);
if (ret) {
dev_err(obj->dev->dev,
"could not unpin pages: %d\n", ret);
}
ret = tiler_release(omap_obj->block);
if (ret) {
dev_err(obj->dev->dev,
"could not release unmap: %d\n", ret);
}
omap_obj->paddr = 0;
omap_obj->block = NULL;
}
}
mutex_unlock(&obj->dev->struct_mutex);
}
int omap_gem_rotated_paddr(struct drm_gem_object *obj, uint32_t orient,
int x, int y, dma_addr_t *paddr)
{
struct omap_gem_object *omap_obj = to_omap_bo(obj);
int ret = -EINVAL;
mutex_lock(&obj->dev->struct_mutex);
if ((omap_obj->paddr_cnt > 0) && omap_obj->block &&
(omap_obj->flags & OMAP_BO_TILED)) {
*paddr = tiler_tsptr(omap_obj->block, orient, x, y);
ret = 0;
}
mutex_unlock(&obj->dev->struct_mutex);
return ret;
}
int omap_gem_tiled_stride(struct drm_gem_object *obj, uint32_t orient)
{
struct omap_gem_object *omap_obj = to_omap_bo(obj);
int ret = -EINVAL;
if (omap_obj->flags & OMAP_BO_TILED)
ret = tiler_stride(gem2fmt(omap_obj->flags), orient);
return ret;
}
int omap_gem_get_pages(struct drm_gem_object *obj, struct page ***pages,
bool remap)
{
int ret;
if (!remap) {
struct omap_gem_object *omap_obj = to_omap_bo(obj);
if (!omap_obj->pages)
return -ENOMEM;
*pages = omap_obj->pages;
return 0;
}
mutex_lock(&obj->dev->struct_mutex);
ret = get_pages(obj, pages);
mutex_unlock(&obj->dev->struct_mutex);
return ret;
}
int omap_gem_put_pages(struct drm_gem_object *obj)
{
return 0;
}
void *omap_gem_vaddr(struct drm_gem_object *obj)
{
struct omap_gem_object *omap_obj = to_omap_bo(obj);
WARN_ON(!mutex_is_locked(&obj->dev->struct_mutex));
if (!omap_obj->vaddr) {
struct page **pages;
int ret = get_pages(obj, &pages);
if (ret)
return ERR_PTR(ret);
omap_obj->vaddr = vmap(pages, obj->size >> PAGE_SHIFT,
VM_MAP, pgprot_writecombine(PAGE_KERNEL));
}
return omap_obj->vaddr;
}
int omap_gem_resume(struct device *dev)
{
struct drm_device *drm_dev = dev_get_drvdata(dev);
struct omap_drm_private *priv = drm_dev->dev_private;
struct omap_gem_object *omap_obj;
int ret = 0;
list_for_each_entry(omap_obj, &priv->obj_list, mm_list) {
if (omap_obj->block) {
struct drm_gem_object *obj = &omap_obj->base;
uint32_t npages = obj->size >> PAGE_SHIFT;
WARN_ON(!omap_obj->pages);
ret = tiler_pin(omap_obj->block,
omap_obj->pages, npages,
omap_obj->roll, true);
if (ret) {
dev_err(dev, "could not repin: %d\n", ret);
return ret;
}
}
}
return 0;
}
void omap_gem_describe(struct drm_gem_object *obj, struct seq_file *m)
{
struct omap_gem_object *omap_obj = to_omap_bo(obj);
uint64_t off;
off = drm_vma_node_start(&obj->vma_node);
seq_printf(m, "%08x: %2d (%2d) %08llx %pad (%2d) %p %4d",
omap_obj->flags, obj->name, obj->refcount.refcount.counter,
off, &omap_obj->paddr, omap_obj->paddr_cnt,
omap_obj->vaddr, omap_obj->roll);
if (omap_obj->flags & OMAP_BO_TILED) {
seq_printf(m, " %dx%d", omap_obj->width, omap_obj->height);
if (omap_obj->block) {
struct tcm_area *area = &omap_obj->block->area;
seq_printf(m, " (%dx%d, %dx%d)",
area->p0.x, area->p0.y,
area->p1.x, area->p1.y);
}
} else {
seq_printf(m, " %d", obj->size);
}
seq_printf(m, "\n");
}
void omap_gem_describe_objects(struct list_head *list, struct seq_file *m)
{
struct omap_gem_object *omap_obj;
int count = 0;
size_t size = 0;
list_for_each_entry(omap_obj, list, mm_list) {
struct drm_gem_object *obj = &omap_obj->base;
seq_printf(m, " ");
omap_gem_describe(obj, m);
count++;
size += obj->size;
}
seq_printf(m, "Total %d objects, %zu bytes\n", count, size);
}
static inline bool is_waiting(struct omap_gem_sync_waiter *waiter)
{
struct omap_gem_object *omap_obj = waiter->omap_obj;
if ((waiter->op & OMAP_GEM_READ) &&
(omap_obj->sync->write_complete < waiter->write_target))
return true;
if ((waiter->op & OMAP_GEM_WRITE) &&
(omap_obj->sync->read_complete < waiter->read_target))
return true;
return false;
}
static void sync_op_update(void)
{
struct omap_gem_sync_waiter *waiter, *n;
list_for_each_entry_safe(waiter, n, &waiters, list) {
if (!is_waiting(waiter)) {
list_del(&waiter->list);
SYNC("notify: %p", waiter);
waiter->notify(waiter->arg);
kfree(waiter);
}
}
}
static inline int sync_op(struct drm_gem_object *obj,
enum omap_gem_op op, bool start)
{
struct omap_gem_object *omap_obj = to_omap_bo(obj);
int ret = 0;
spin_lock(&sync_lock);
if (!omap_obj->sync) {
omap_obj->sync = kzalloc(sizeof(*omap_obj->sync), GFP_ATOMIC);
if (!omap_obj->sync) {
ret = -ENOMEM;
goto unlock;
}
}
if (start) {
if (op & OMAP_GEM_READ)
omap_obj->sync->read_pending++;
if (op & OMAP_GEM_WRITE)
omap_obj->sync->write_pending++;
} else {
if (op & OMAP_GEM_READ)
omap_obj->sync->read_complete++;
if (op & OMAP_GEM_WRITE)
omap_obj->sync->write_complete++;
sync_op_update();
}
unlock:
spin_unlock(&sync_lock);
return ret;
}
int omap_gem_op_start(struct drm_gem_object *obj, enum omap_gem_op op)
{
return sync_op(obj, op, true);
}
int omap_gem_op_finish(struct drm_gem_object *obj, enum omap_gem_op op)
{
return sync_op(obj, op, false);
}
static void sync_notify(void *arg)
{
struct task_struct **waiter_task = arg;
*waiter_task = NULL;
wake_up_all(&sync_event);
}
int omap_gem_op_sync(struct drm_gem_object *obj, enum omap_gem_op op)
{
struct omap_gem_object *omap_obj = to_omap_bo(obj);
int ret = 0;
if (omap_obj->sync) {
struct task_struct *waiter_task = current;
struct omap_gem_sync_waiter *waiter =
kzalloc(sizeof(*waiter), GFP_KERNEL);
if (!waiter)
return -ENOMEM;
waiter->omap_obj = omap_obj;
waiter->op = op;
waiter->read_target = omap_obj->sync->read_pending;
waiter->write_target = omap_obj->sync->write_pending;
waiter->notify = sync_notify;
waiter->arg = &waiter_task;
spin_lock(&sync_lock);
if (is_waiting(waiter)) {
SYNC("waited: %p", waiter);
list_add_tail(&waiter->list, &waiters);
spin_unlock(&sync_lock);
ret = wait_event_interruptible(sync_event,
(waiter_task == NULL));
spin_lock(&sync_lock);
if (waiter_task) {
SYNC("interrupted: %p", waiter);
list_del(&waiter->list);
waiter_task = NULL;
} else {
waiter = NULL;
}
}
spin_unlock(&sync_lock);
kfree(waiter);
}
return ret;
}
int omap_gem_op_async(struct drm_gem_object *obj, enum omap_gem_op op,
void (*fxn)(void *arg), void *arg)
{
struct omap_gem_object *omap_obj = to_omap_bo(obj);
if (omap_obj->sync) {
struct omap_gem_sync_waiter *waiter =
kzalloc(sizeof(*waiter), GFP_ATOMIC);
if (!waiter)
return -ENOMEM;
waiter->omap_obj = omap_obj;
waiter->op = op;
waiter->read_target = omap_obj->sync->read_pending;
waiter->write_target = omap_obj->sync->write_pending;
waiter->notify = fxn;
waiter->arg = arg;
spin_lock(&sync_lock);
if (is_waiting(waiter)) {
SYNC("waited: %p", waiter);
list_add_tail(&waiter->list, &waiters);
spin_unlock(&sync_lock);
return 0;
}
spin_unlock(&sync_lock);
kfree(waiter);
}
fxn(arg);
return 0;
}
void omap_gem_free_object(struct drm_gem_object *obj)
{
struct drm_device *dev = obj->dev;
struct omap_drm_private *priv = dev->dev_private;
struct omap_gem_object *omap_obj = to_omap_bo(obj);
evict(obj);
WARN_ON(!mutex_is_locked(&dev->struct_mutex));
spin_lock(&priv->list_lock);
list_del(&omap_obj->mm_list);
spin_unlock(&priv->list_lock);
WARN_ON(omap_obj->paddr_cnt > 0);
if (omap_obj->pages) {
if (omap_obj->flags & OMAP_BO_MEM_DMABUF)
kfree(omap_obj->pages);
else
omap_gem_detach_pages(obj);
}
if (omap_obj->flags & OMAP_BO_MEM_DMA_API) {
dma_free_wc(dev->dev, obj->size, omap_obj->vaddr,
omap_obj->paddr);
} else if (omap_obj->vaddr) {
vunmap(omap_obj->vaddr);
} else if (obj->import_attach) {
drm_prime_gem_destroy(obj, omap_obj->sgt);
}
kfree(omap_obj->sync);
drm_gem_object_release(obj);
kfree(omap_obj);
}
struct drm_gem_object *omap_gem_new(struct drm_device *dev,
union omap_gem_size gsize, uint32_t flags)
{
struct omap_drm_private *priv = dev->dev_private;
struct omap_gem_object *omap_obj;
struct drm_gem_object *obj;
struct address_space *mapping;
size_t size;
int ret;
if (flags & OMAP_BO_TILED) {
if (!priv->usergart) {
dev_err(dev->dev, "Tiled buffers require DMM\n");
return NULL;
}
flags &= ~OMAP_BO_SCANOUT;
flags |= OMAP_BO_MEM_SHMEM;
flags &= ~(OMAP_BO_CACHED|OMAP_BO_WC|OMAP_BO_UNCACHED);
flags |= tiler_get_cpu_cache_flags();
} else if ((flags & OMAP_BO_SCANOUT) && !priv->has_dmm) {
flags |= OMAP_BO_MEM_DMA_API;
} else if (!(flags & OMAP_BO_MEM_DMABUF)) {
flags |= OMAP_BO_MEM_SHMEM;
}
omap_obj = kzalloc(sizeof(*omap_obj), GFP_KERNEL);
if (!omap_obj)
return NULL;
obj = &omap_obj->base;
omap_obj->flags = flags;
if (flags & OMAP_BO_TILED) {
tiler_align(gem2fmt(flags), &gsize.tiled.width,
&gsize.tiled.height);
size = tiler_size(gem2fmt(flags), gsize.tiled.width,
gsize.tiled.height);
omap_obj->width = gsize.tiled.width;
omap_obj->height = gsize.tiled.height;
} else {
size = PAGE_ALIGN(gsize.bytes);
}
if (!(flags & OMAP_BO_MEM_SHMEM)) {
drm_gem_private_object_init(dev, obj, size);
} else {
ret = drm_gem_object_init(dev, obj, size);
if (ret)
goto err_free;
mapping = file_inode(obj->filp)->i_mapping;
mapping_set_gfp_mask(mapping, GFP_USER | __GFP_DMA32);
}
if (flags & OMAP_BO_MEM_DMA_API) {
omap_obj->vaddr = dma_alloc_wc(dev->dev, size,
&omap_obj->paddr,
GFP_KERNEL);
if (!omap_obj->vaddr)
goto err_release;
}
spin_lock(&priv->list_lock);
list_add(&omap_obj->mm_list, &priv->obj_list);
spin_unlock(&priv->list_lock);
return obj;
err_release:
drm_gem_object_release(obj);
err_free:
kfree(omap_obj);
return NULL;
}
struct drm_gem_object *omap_gem_new_dmabuf(struct drm_device *dev, size_t size,
struct sg_table *sgt)
{
struct omap_drm_private *priv = dev->dev_private;
struct omap_gem_object *omap_obj;
struct drm_gem_object *obj;
union omap_gem_size gsize;
if (sgt->orig_nents != 1 && !priv->has_dmm)
return ERR_PTR(-EINVAL);
mutex_lock(&dev->struct_mutex);
gsize.bytes = PAGE_ALIGN(size);
obj = omap_gem_new(dev, gsize, OMAP_BO_MEM_DMABUF | OMAP_BO_WC);
if (!obj) {
obj = ERR_PTR(-ENOMEM);
goto done;
}
omap_obj = to_omap_bo(obj);
omap_obj->sgt = sgt;
if (sgt->orig_nents == 1) {
omap_obj->paddr = sg_dma_address(sgt->sgl);
} else {
struct sg_page_iter iter;
struct page **pages;
unsigned int npages;
unsigned int i = 0;
npages = DIV_ROUND_UP(size, PAGE_SIZE);
pages = kcalloc(npages, sizeof(*pages), GFP_KERNEL);
if (!pages) {
omap_gem_free_object(obj);
obj = ERR_PTR(-ENOMEM);
goto done;
}
omap_obj->pages = pages;
for_each_sg_page(sgt->sgl, &iter, sgt->orig_nents, 0) {
pages[i++] = sg_page_iter_page(&iter);
if (i > npages)
break;
}
if (WARN_ON(i != npages)) {
omap_gem_free_object(obj);
obj = ERR_PTR(-ENOMEM);
goto done;
}
}
done:
mutex_unlock(&dev->struct_mutex);
return obj;
}
int omap_gem_new_handle(struct drm_device *dev, struct drm_file *file,
union omap_gem_size gsize, uint32_t flags, uint32_t *handle)
{
struct drm_gem_object *obj;
int ret;
obj = omap_gem_new(dev, gsize, flags);
if (!obj)
return -ENOMEM;
ret = drm_gem_handle_create(file, obj, handle);
if (ret) {
omap_gem_free_object(obj);
return ret;
}
drm_gem_object_unreference_unlocked(obj);
return 0;
}
void omap_gem_init(struct drm_device *dev)
{
struct omap_drm_private *priv = dev->dev_private;
struct omap_drm_usergart *usergart;
const enum tiler_fmt fmts[] = {
TILFMT_8BIT, TILFMT_16BIT, TILFMT_32BIT
};
int i, j;
if (!dmm_is_available()) {
dev_warn(dev->dev, "DMM not available, disable DMM support\n");
return;
}
usergart = kcalloc(3, sizeof(*usergart), GFP_KERNEL);
if (!usergart)
return;
for (i = 0; i < ARRAY_SIZE(fmts); i++) {
uint16_t h = 1, w = PAGE_SIZE >> i;
tiler_align(fmts[i], &w, &h);
usergart[i].height = h;
usergart[i].height_shift = ilog2(h);
usergart[i].stride_pfn = tiler_stride(fmts[i], 0) >> PAGE_SHIFT;
usergart[i].slot_shift = ilog2((PAGE_SIZE / h) >> i);
for (j = 0; j < NUM_USERGART_ENTRIES; j++) {
struct omap_drm_usergart_entry *entry;
struct tiler_block *block;
entry = &usergart[i].entry[j];
block = tiler_reserve_2d(fmts[i], w, h, PAGE_SIZE);
if (IS_ERR(block)) {
dev_err(dev->dev,
"reserve failed: %d, %d, %ld\n",
i, j, PTR_ERR(block));
return;
}
entry->paddr = tiler_ssptr(block);
entry->block = block;
DBG("%d:%d: %dx%d: paddr=%pad stride=%d", i, j, w, h,
&entry->paddr,
usergart[i].stride_pfn << PAGE_SHIFT);
}
}
priv->usergart = usergart;
priv->has_dmm = true;
}
void omap_gem_deinit(struct drm_device *dev)
{
struct omap_drm_private *priv = dev->dev_private;
kfree(priv->usergart);
}
