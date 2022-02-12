static pgprot_t drm_io_prot(struct drm_local_map *map,
struct vm_area_struct *vma)
{
pgprot_t tmp = vm_get_page_prot(vma->vm_flags);
#if defined(__i386__) || defined(__x86_64__)
if (map->type == _DRM_REGISTERS && !(map->flags & _DRM_WRITE_COMBINING))
tmp = pgprot_noncached(tmp);
else
tmp = pgprot_writecombine(tmp);
#elif defined(__powerpc__)
pgprot_val(tmp) |= _PAGE_NO_CACHE;
if (map->type == _DRM_REGISTERS)
pgprot_val(tmp) |= _PAGE_GUARDED;
#elif defined(__ia64__)
if (efi_range_is_wc(vma->vm_start, vma->vm_end -
vma->vm_start))
tmp = pgprot_writecombine(tmp);
else
tmp = pgprot_noncached(tmp);
#elif defined(__sparc__) || defined(__arm__) || defined(__mips__)
tmp = pgprot_noncached(tmp);
#endif
return tmp;
}
static pgprot_t drm_dma_prot(uint32_t map_type, struct vm_area_struct *vma)
{
pgprot_t tmp = vm_get_page_prot(vma->vm_flags);
#if defined(__powerpc__) && defined(CONFIG_NOT_COHERENT_CACHE)
tmp |= _PAGE_NO_CACHE;
#endif
return tmp;
}
static int drm_do_vm_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct drm_file *priv = vma->vm_file->private_data;
struct drm_device *dev = priv->minor->dev;
struct drm_local_map *map = NULL;
struct drm_map_list *r_list;
struct drm_hash_item *hash;
if (!dev->agp)
goto vm_fault_error;
if (!dev->agp || !dev->agp->cant_use_aperture)
goto vm_fault_error;
if (drm_ht_find_item(&dev->map_hash, vma->vm_pgoff, &hash))
goto vm_fault_error;
r_list = drm_hash_entry(hash, struct drm_map_list, hash);
map = r_list->map;
if (map && map->type == _DRM_AGP) {
resource_size_t offset = (unsigned long)vmf->virtual_address -
vma->vm_start;
resource_size_t baddr = map->offset + offset;
struct drm_agp_mem *agpmem;
struct page *page;
#ifdef __alpha__
baddr -= dev->hose->mem_space->start;
#endif
list_for_each_entry(agpmem, &dev->agp->memory, head) {
if (agpmem->bound <= baddr &&
agpmem->bound + agpmem->pages * PAGE_SIZE > baddr)
break;
}
if (&agpmem->head == &dev->agp->memory)
goto vm_fault_error;
offset = (baddr - agpmem->bound) >> PAGE_SHIFT;
page = agpmem->memory->pages[offset];
get_page(page);
vmf->page = page;
DRM_DEBUG
("baddr = 0x%llx page = 0x%p, offset = 0x%llx, count=%d\n",
(unsigned long long)baddr,
agpmem->memory->pages[offset],
(unsigned long long)offset,
page_count(page));
return 0;
}
vm_fault_error:
return VM_FAULT_SIGBUS;
}
static int drm_do_vm_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
return VM_FAULT_SIGBUS;
}
static int drm_do_vm_shm_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct drm_local_map *map = vma->vm_private_data;
unsigned long offset;
unsigned long i;
struct page *page;
if (!map)
return VM_FAULT_SIGBUS;
offset = (unsigned long)vmf->virtual_address - vma->vm_start;
i = (unsigned long)map->handle + offset;
page = vmalloc_to_page((void *)i);
if (!page)
return VM_FAULT_SIGBUS;
get_page(page);
vmf->page = page;
DRM_DEBUG("shm_fault 0x%lx\n", offset);
return 0;
}
static void drm_vm_shm_close(struct vm_area_struct *vma)
{
struct drm_file *priv = vma->vm_file->private_data;
struct drm_device *dev = priv->minor->dev;
struct drm_vma_entry *pt, *temp;
struct drm_local_map *map;
struct drm_map_list *r_list;
int found_maps = 0;
DRM_DEBUG("0x%08lx,0x%08lx\n",
vma->vm_start, vma->vm_end - vma->vm_start);
map = vma->vm_private_data;
mutex_lock(&dev->struct_mutex);
list_for_each_entry_safe(pt, temp, &dev->vmalist, head) {
if (pt->vma->vm_private_data == map)
found_maps++;
if (pt->vma == vma) {
list_del(&pt->head);
kfree(pt);
}
}
if (found_maps == 1 && map->flags & _DRM_REMOVABLE) {
found_maps = 0;
list_for_each_entry(r_list, &dev->maplist, head) {
if (r_list->map == map)
found_maps++;
}
if (!found_maps) {
drm_dma_handle_t dmah;
switch (map->type) {
case _DRM_REGISTERS:
case _DRM_FRAME_BUFFER:
arch_phys_wc_del(map->mtrr);
iounmap(map->handle);
break;
case _DRM_SHM:
vfree(map->handle);
break;
case _DRM_AGP:
case _DRM_SCATTER_GATHER:
break;
case _DRM_CONSISTENT:
dmah.vaddr = map->handle;
dmah.busaddr = map->offset;
dmah.size = map->size;
__drm_pci_free(dev, &dmah);
break;
}
kfree(map);
}
}
mutex_unlock(&dev->struct_mutex);
}
static int drm_do_vm_dma_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct drm_file *priv = vma->vm_file->private_data;
struct drm_device *dev = priv->minor->dev;
struct drm_device_dma *dma = dev->dma;
unsigned long offset;
unsigned long page_nr;
struct page *page;
if (!dma)
return VM_FAULT_SIGBUS;
if (!dma->pagelist)
return VM_FAULT_SIGBUS;
offset = (unsigned long)vmf->virtual_address - vma->vm_start;
page_nr = offset >> PAGE_SHIFT;
page = virt_to_page((void *)dma->pagelist[page_nr]);
get_page(page);
vmf->page = page;
DRM_DEBUG("dma_fault 0x%lx (page %lu)\n", offset, page_nr);
return 0;
}
static int drm_do_vm_sg_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct drm_local_map *map = vma->vm_private_data;
struct drm_file *priv = vma->vm_file->private_data;
struct drm_device *dev = priv->minor->dev;
struct drm_sg_mem *entry = dev->sg;
unsigned long offset;
unsigned long map_offset;
unsigned long page_offset;
struct page *page;
if (!entry)
return VM_FAULT_SIGBUS;
if (!entry->pagelist)
return VM_FAULT_SIGBUS;
offset = (unsigned long)vmf->virtual_address - vma->vm_start;
map_offset = map->offset - (unsigned long)dev->sg->virtual;
page_offset = (offset >> PAGE_SHIFT) + (map_offset >> PAGE_SHIFT);
page = entry->pagelist[page_offset];
get_page(page);
vmf->page = page;
return 0;
}
static int drm_vm_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
return drm_do_vm_fault(vma, vmf);
}
static int drm_vm_shm_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
return drm_do_vm_shm_fault(vma, vmf);
}
static int drm_vm_dma_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
return drm_do_vm_dma_fault(vma, vmf);
}
static int drm_vm_sg_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
return drm_do_vm_sg_fault(vma, vmf);
}
void drm_vm_open_locked(struct drm_device *dev,
struct vm_area_struct *vma)
{
struct drm_vma_entry *vma_entry;
DRM_DEBUG("0x%08lx,0x%08lx\n",
vma->vm_start, vma->vm_end - vma->vm_start);
vma_entry = kmalloc(sizeof(*vma_entry), GFP_KERNEL);
if (vma_entry) {
vma_entry->vma = vma;
vma_entry->pid = current->pid;
list_add(&vma_entry->head, &dev->vmalist);
}
}
static void drm_vm_open(struct vm_area_struct *vma)
{
struct drm_file *priv = vma->vm_file->private_data;
struct drm_device *dev = priv->minor->dev;
mutex_lock(&dev->struct_mutex);
drm_vm_open_locked(dev, vma);
mutex_unlock(&dev->struct_mutex);
}
void drm_vm_close_locked(struct drm_device *dev,
struct vm_area_struct *vma)
{
struct drm_vma_entry *pt, *temp;
DRM_DEBUG("0x%08lx,0x%08lx\n",
vma->vm_start, vma->vm_end - vma->vm_start);
list_for_each_entry_safe(pt, temp, &dev->vmalist, head) {
if (pt->vma == vma) {
list_del(&pt->head);
kfree(pt);
break;
}
}
}
static void drm_vm_close(struct vm_area_struct *vma)
{
struct drm_file *priv = vma->vm_file->private_data;
struct drm_device *dev = priv->minor->dev;
mutex_lock(&dev->struct_mutex);
drm_vm_close_locked(dev, vma);
mutex_unlock(&dev->struct_mutex);
}
static int drm_mmap_dma(struct file *filp, struct vm_area_struct *vma)
{
struct drm_file *priv = filp->private_data;
struct drm_device *dev;
struct drm_device_dma *dma;
unsigned long length = vma->vm_end - vma->vm_start;
dev = priv->minor->dev;
dma = dev->dma;
DRM_DEBUG("start = 0x%lx, end = 0x%lx, page offset = 0x%lx\n",
vma->vm_start, vma->vm_end, vma->vm_pgoff);
if (!dma || (length >> PAGE_SHIFT) != dma->page_count) {
return -EINVAL;
}
if (!capable(CAP_SYS_ADMIN) &&
(dma->flags & _DRM_DMA_USE_PCI_RO)) {
vma->vm_flags &= ~(VM_WRITE | VM_MAYWRITE);
#if defined(__i386__) || defined(__x86_64__)
pgprot_val(vma->vm_page_prot) &= ~_PAGE_RW;
#else
vma->vm_page_prot =
__pgprot(pte_val
(pte_wrprotect
(__pte(pgprot_val(vma->vm_page_prot)))));
#endif
}
vma->vm_ops = &drm_vm_dma_ops;
vma->vm_flags |= VM_DONTEXPAND | VM_DONTDUMP;
drm_vm_open_locked(dev, vma);
return 0;
}
static resource_size_t drm_core_get_reg_ofs(struct drm_device *dev)
{
#ifdef __alpha__
return dev->hose->dense_mem_base;
#else
return 0;
#endif
}
int drm_mmap_locked(struct file *filp, struct vm_area_struct *vma)
{
struct drm_file *priv = filp->private_data;
struct drm_device *dev = priv->minor->dev;
struct drm_local_map *map = NULL;
resource_size_t offset = 0;
struct drm_hash_item *hash;
DRM_DEBUG("start = 0x%lx, end = 0x%lx, page offset = 0x%lx\n",
vma->vm_start, vma->vm_end, vma->vm_pgoff);
if (!priv->authenticated)
return -EACCES;
if (!vma->vm_pgoff
#if __OS_HAS_AGP
&& (!dev->agp
|| dev->agp->agp_info.device->vendor != PCI_VENDOR_ID_APPLE)
#endif
)
return drm_mmap_dma(filp, vma);
if (drm_ht_find_item(&dev->map_hash, vma->vm_pgoff, &hash)) {
DRM_ERROR("Could not find map\n");
return -EINVAL;
}
map = drm_hash_entry(hash, struct drm_map_list, hash)->map;
if (!map || ((map->flags & _DRM_RESTRICTED) && !capable(CAP_SYS_ADMIN)))
return -EPERM;
if (map->size < vma->vm_end - vma->vm_start)
return -EINVAL;
if (!capable(CAP_SYS_ADMIN) && (map->flags & _DRM_READ_ONLY)) {
vma->vm_flags &= ~(VM_WRITE | VM_MAYWRITE);
#if defined(__i386__) || defined(__x86_64__)
pgprot_val(vma->vm_page_prot) &= ~_PAGE_RW;
#else
vma->vm_page_prot =
__pgprot(pte_val
(pte_wrprotect
(__pte(pgprot_val(vma->vm_page_prot)))));
#endif
}
switch (map->type) {
#if !defined(__arm__)
case _DRM_AGP:
if (dev->agp && dev->agp->cant_use_aperture) {
#if defined(__powerpc__)
pgprot_val(vma->vm_page_prot) |= _PAGE_NO_CACHE;
#endif
vma->vm_ops = &drm_vm_ops;
break;
}
#endif
case _DRM_FRAME_BUFFER:
case _DRM_REGISTERS:
offset = drm_core_get_reg_ofs(dev);
vma->vm_page_prot = drm_io_prot(map, vma);
if (io_remap_pfn_range(vma, vma->vm_start,
(map->offset + offset) >> PAGE_SHIFT,
vma->vm_end - vma->vm_start,
vma->vm_page_prot))
return -EAGAIN;
DRM_DEBUG(" Type = %d; start = 0x%lx, end = 0x%lx,"
" offset = 0x%llx\n",
map->type,
vma->vm_start, vma->vm_end, (unsigned long long)(map->offset + offset));
vma->vm_ops = &drm_vm_ops;
break;
case _DRM_CONSISTENT:
if (remap_pfn_range(vma, vma->vm_start,
page_to_pfn(virt_to_page(map->handle)),
vma->vm_end - vma->vm_start, vma->vm_page_prot))
return -EAGAIN;
vma->vm_page_prot = drm_dma_prot(map->type, vma);
case _DRM_SHM:
vma->vm_ops = &drm_vm_shm_ops;
vma->vm_private_data = (void *)map;
break;
case _DRM_SCATTER_GATHER:
vma->vm_ops = &drm_vm_sg_ops;
vma->vm_private_data = (void *)map;
vma->vm_page_prot = drm_dma_prot(map->type, vma);
break;
default:
return -EINVAL;
}
vma->vm_flags |= VM_DONTEXPAND | VM_DONTDUMP;
drm_vm_open_locked(dev, vma);
return 0;
}
int drm_mmap(struct file *filp, struct vm_area_struct *vma)
{
struct drm_file *priv = filp->private_data;
struct drm_device *dev = priv->minor->dev;
int ret;
if (drm_device_is_unplugged(dev))
return -ENODEV;
mutex_lock(&dev->struct_mutex);
ret = drm_mmap_locked(filp, vma);
mutex_unlock(&dev->struct_mutex);
return ret;
}
