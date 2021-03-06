static void vfio_lock_acct_bg(struct work_struct *work)
{
struct vwork *vwork = container_of(work, struct vwork, work);
struct mm_struct *mm;
mm = vwork->mm;
down_write(&mm->mmap_sem);
mm->locked_vm += vwork->npage;
up_write(&mm->mmap_sem);
mmput(mm);
kfree(vwork);
}
static void vfio_lock_acct(long npage)
{
struct vwork *vwork;
struct mm_struct *mm;
if (!current->mm)
return;
if (down_write_trylock(&current->mm->mmap_sem)) {
current->mm->locked_vm += npage;
up_write(&current->mm->mmap_sem);
return;
}
vwork = kmalloc(sizeof(struct vwork), GFP_KERNEL);
if (!vwork)
return;
mm = get_task_mm(current);
if (!mm) {
kfree(vwork);
return;
}
INIT_WORK(&vwork->work, vfio_lock_acct_bg);
vwork->mm = mm;
vwork->npage = npage;
schedule_work(&vwork->work);
}
static bool is_invalid_reserved_pfn(unsigned long pfn)
{
if (pfn_valid(pfn)) {
bool reserved;
struct page *tail = pfn_to_page(pfn);
struct page *head = compound_trans_head(tail);
reserved = !!(PageReserved(head));
if (head != tail) {
smp_rmb();
if (PageTail(tail))
return reserved;
}
return PageReserved(tail);
}
return true;
}
static int put_pfn(unsigned long pfn, int prot)
{
if (!is_invalid_reserved_pfn(pfn)) {
struct page *page = pfn_to_page(pfn);
if (prot & IOMMU_WRITE)
SetPageDirty(page);
put_page(page);
return 1;
}
return 0;
}
static long __vfio_dma_do_unmap(struct vfio_iommu *iommu, dma_addr_t iova,
long npage, int prot)
{
long i, unlocked = 0;
for (i = 0; i < npage; i++, iova += PAGE_SIZE) {
unsigned long pfn;
pfn = iommu_iova_to_phys(iommu->domain, iova) >> PAGE_SHIFT;
if (pfn) {
iommu_unmap(iommu->domain, iova, PAGE_SIZE);
unlocked += put_pfn(pfn, prot);
}
}
return unlocked;
}
static void vfio_dma_unmap(struct vfio_iommu *iommu, dma_addr_t iova,
long npage, int prot)
{
long unlocked;
unlocked = __vfio_dma_do_unmap(iommu, iova, npage, prot);
vfio_lock_acct(-unlocked);
}
static int vaddr_get_pfn(unsigned long vaddr, int prot, unsigned long *pfn)
{
struct page *page[1];
struct vm_area_struct *vma;
int ret = -EFAULT;
if (get_user_pages_fast(vaddr, 1, !!(prot & IOMMU_WRITE), page) == 1) {
*pfn = page_to_pfn(page[0]);
return 0;
}
down_read(&current->mm->mmap_sem);
vma = find_vma_intersection(current->mm, vaddr, vaddr + 1);
if (vma && vma->vm_flags & VM_PFNMAP) {
*pfn = ((vaddr - vma->vm_start) >> PAGE_SHIFT) + vma->vm_pgoff;
if (is_invalid_reserved_pfn(*pfn))
ret = 0;
}
up_read(&current->mm->mmap_sem);
return ret;
}
static int __vfio_dma_map(struct vfio_iommu *iommu, dma_addr_t iova,
unsigned long vaddr, long npage, int prot)
{
dma_addr_t start = iova;
long i, locked = 0;
int ret;
for (i = 0; i < npage; i++, iova += PAGE_SIZE)
if (iommu_iova_to_phys(iommu->domain, iova))
return -EBUSY;
iova = start;
if (iommu->cache)
prot |= IOMMU_CACHE;
for (i = 0; i < npage; i++, iova += PAGE_SIZE, vaddr += PAGE_SIZE) {
unsigned long pfn = 0;
ret = vaddr_get_pfn(vaddr, prot, &pfn);
if (ret) {
__vfio_dma_do_unmap(iommu, start, i, prot);
return ret;
}
if (!is_invalid_reserved_pfn(pfn))
locked++;
ret = iommu_map(iommu->domain, iova,
(phys_addr_t)pfn << PAGE_SHIFT,
PAGE_SIZE, prot);
if (ret) {
put_pfn(pfn, prot);
__vfio_dma_do_unmap(iommu, start, i, prot);
return ret;
}
}
vfio_lock_acct(locked);
return 0;
}
static inline bool ranges_overlap(dma_addr_t start1, size_t size1,
dma_addr_t start2, size_t size2)
{
if (start1 < start2)
return (start2 - start1 < size1);
else if (start2 < start1)
return (start1 - start2 < size2);
return (size1 > 0 && size2 > 0);
}
static struct vfio_dma *vfio_find_dma(struct vfio_iommu *iommu,
dma_addr_t start, size_t size)
{
struct vfio_dma *dma;
list_for_each_entry(dma, &iommu->dma_list, next) {
if (ranges_overlap(dma->iova, NPAGE_TO_SIZE(dma->npage),
start, size))
return dma;
}
return NULL;
}
static long vfio_remove_dma_overlap(struct vfio_iommu *iommu, dma_addr_t start,
size_t size, struct vfio_dma *dma)
{
struct vfio_dma *split;
long npage_lo, npage_hi;
if (start <= dma->iova &&
start + size >= dma->iova + NPAGE_TO_SIZE(dma->npage)) {
vfio_dma_unmap(iommu, dma->iova, dma->npage, dma->prot);
list_del(&dma->next);
npage_lo = dma->npage;
kfree(dma);
return npage_lo;
}
if (start <= dma->iova) {
size_t overlap;
overlap = start + size - dma->iova;
npage_lo = overlap >> PAGE_SHIFT;
vfio_dma_unmap(iommu, dma->iova, npage_lo, dma->prot);
dma->iova += overlap;
dma->vaddr += overlap;
dma->npage -= npage_lo;
return npage_lo;
}
if (start + size >= dma->iova + NPAGE_TO_SIZE(dma->npage)) {
size_t overlap;
overlap = dma->iova + NPAGE_TO_SIZE(dma->npage) - start;
npage_hi = overlap >> PAGE_SHIFT;
vfio_dma_unmap(iommu, start, npage_hi, dma->prot);
dma->npage -= npage_hi;
return npage_hi;
}
npage_lo = (start - dma->iova) >> PAGE_SHIFT;
npage_hi = dma->npage - (size >> PAGE_SHIFT) - npage_lo;
split = kzalloc(sizeof *split, GFP_KERNEL);
if (!split)
return -ENOMEM;
vfio_dma_unmap(iommu, start, size >> PAGE_SHIFT, dma->prot);
dma->npage = npage_lo;
split->npage = npage_hi;
split->iova = start + size;
split->vaddr = dma->vaddr + NPAGE_TO_SIZE(npage_lo) + size;
split->prot = dma->prot;
list_add(&split->next, &iommu->dma_list);
return size >> PAGE_SHIFT;
}
static int vfio_dma_do_unmap(struct vfio_iommu *iommu,
struct vfio_iommu_type1_dma_unmap *unmap)
{
long ret = 0, npage = unmap->size >> PAGE_SHIFT;
struct vfio_dma *dma, *tmp;
uint64_t mask;
mask = ((uint64_t)1 << __ffs(iommu->domain->ops->pgsize_bitmap)) - 1;
if (unmap->iova & mask)
return -EINVAL;
if (unmap->size & mask)
return -EINVAL;
WARN_ON(mask & PAGE_MASK);
mutex_lock(&iommu->lock);
list_for_each_entry_safe(dma, tmp, &iommu->dma_list, next) {
if (ranges_overlap(dma->iova, NPAGE_TO_SIZE(dma->npage),
unmap->iova, unmap->size)) {
ret = vfio_remove_dma_overlap(iommu, unmap->iova,
unmap->size, dma);
if (ret > 0)
npage -= ret;
if (ret < 0 || npage == 0)
break;
}
}
mutex_unlock(&iommu->lock);
return ret > 0 ? 0 : (int)ret;
}
static int vfio_dma_do_map(struct vfio_iommu *iommu,
struct vfio_iommu_type1_dma_map *map)
{
struct vfio_dma *dma, *pdma = NULL;
dma_addr_t iova = map->iova;
unsigned long locked, lock_limit, vaddr = map->vaddr;
size_t size = map->size;
int ret = 0, prot = 0;
uint64_t mask;
long npage;
mask = ((uint64_t)1 << __ffs(iommu->domain->ops->pgsize_bitmap)) - 1;
if (map->flags & VFIO_DMA_MAP_FLAG_WRITE)
prot |= IOMMU_WRITE;
if (map->flags & VFIO_DMA_MAP_FLAG_READ)
prot |= IOMMU_READ;
if (!prot)
return -EINVAL;
if (vaddr & mask)
return -EINVAL;
if (iova & mask)
return -EINVAL;
if (size & mask)
return -EINVAL;
WARN_ON(mask & PAGE_MASK);
if (iova + size && iova + size < iova)
return -EINVAL;
if (vaddr + size && vaddr + size < vaddr)
return -EINVAL;
npage = size >> PAGE_SHIFT;
if (!npage)
return -EINVAL;
mutex_lock(&iommu->lock);
if (vfio_find_dma(iommu, iova, size)) {
ret = -EBUSY;
goto out_lock;
}
locked = current->mm->locked_vm + npage;
lock_limit = rlimit(RLIMIT_MEMLOCK) >> PAGE_SHIFT;
if (locked > lock_limit && !capable(CAP_IPC_LOCK)) {
pr_warn("%s: RLIMIT_MEMLOCK (%ld) exceeded\n",
__func__, rlimit(RLIMIT_MEMLOCK));
ret = -ENOMEM;
goto out_lock;
}
ret = __vfio_dma_map(iommu, iova, vaddr, npage, prot);
if (ret)
goto out_lock;
if (iova) {
dma = vfio_find_dma(iommu, iova - 1, 1);
if (dma && dma->prot == prot &&
dma->vaddr + NPAGE_TO_SIZE(dma->npage) == vaddr) {
dma->npage += npage;
iova = dma->iova;
vaddr = dma->vaddr;
npage = dma->npage;
size = NPAGE_TO_SIZE(npage);
pdma = dma;
}
}
if (iova + size) {
dma = vfio_find_dma(iommu, iova + size, 1);
if (dma && dma->prot == prot &&
dma->vaddr == vaddr + size) {
dma->npage += npage;
dma->iova = iova;
dma->vaddr = vaddr;
if (pdma) {
list_del(&pdma->next);
kfree(pdma);
}
pdma = dma;
}
}
if (!pdma) {
dma = kzalloc(sizeof *dma, GFP_KERNEL);
if (!dma) {
ret = -ENOMEM;
vfio_dma_unmap(iommu, iova, npage, prot);
goto out_lock;
}
dma->npage = npage;
dma->iova = iova;
dma->vaddr = vaddr;
dma->prot = prot;
list_add(&dma->next, &iommu->dma_list);
}
out_lock:
mutex_unlock(&iommu->lock);
return ret;
}
static int vfio_iommu_type1_attach_group(void *iommu_data,
struct iommu_group *iommu_group)
{
struct vfio_iommu *iommu = iommu_data;
struct vfio_group *group, *tmp;
int ret;
group = kzalloc(sizeof(*group), GFP_KERNEL);
if (!group)
return -ENOMEM;
mutex_lock(&iommu->lock);
list_for_each_entry(tmp, &iommu->group_list, next) {
if (tmp->iommu_group == iommu_group) {
mutex_unlock(&iommu->lock);
kfree(group);
return -EINVAL;
}
}
ret = iommu_attach_group(iommu->domain, iommu_group);
if (ret) {
mutex_unlock(&iommu->lock);
kfree(group);
return ret;
}
group->iommu_group = iommu_group;
list_add(&group->next, &iommu->group_list);
mutex_unlock(&iommu->lock);
return 0;
}
static void vfio_iommu_type1_detach_group(void *iommu_data,
struct iommu_group *iommu_group)
{
struct vfio_iommu *iommu = iommu_data;
struct vfio_group *group;
mutex_lock(&iommu->lock);
list_for_each_entry(group, &iommu->group_list, next) {
if (group->iommu_group == iommu_group) {
iommu_detach_group(iommu->domain, iommu_group);
list_del(&group->next);
kfree(group);
break;
}
}
mutex_unlock(&iommu->lock);
}
static void *vfio_iommu_type1_open(unsigned long arg)
{
struct vfio_iommu *iommu;
if (arg != VFIO_TYPE1_IOMMU)
return ERR_PTR(-EINVAL);
iommu = kzalloc(sizeof(*iommu), GFP_KERNEL);
if (!iommu)
return ERR_PTR(-ENOMEM);
INIT_LIST_HEAD(&iommu->group_list);
INIT_LIST_HEAD(&iommu->dma_list);
mutex_init(&iommu->lock);
iommu->domain = iommu_domain_alloc(&pci_bus_type);
if (!iommu->domain) {
kfree(iommu);
return ERR_PTR(-EIO);
}
if (!allow_unsafe_interrupts &&
!iommu_domain_has_cap(iommu->domain, IOMMU_CAP_INTR_REMAP)) {
pr_warn("%s: No interrupt remapping support. Use the module param \"allow_unsafe_interrupts\" to enable VFIO IOMMU support on this platform\n",
__func__);
iommu_domain_free(iommu->domain);
kfree(iommu);
return ERR_PTR(-EPERM);
}
return iommu;
}
static void vfio_iommu_type1_release(void *iommu_data)
{
struct vfio_iommu *iommu = iommu_data;
struct vfio_group *group, *group_tmp;
struct vfio_dma *dma, *dma_tmp;
list_for_each_entry_safe(group, group_tmp, &iommu->group_list, next) {
iommu_detach_group(iommu->domain, group->iommu_group);
list_del(&group->next);
kfree(group);
}
list_for_each_entry_safe(dma, dma_tmp, &iommu->dma_list, next) {
vfio_dma_unmap(iommu, dma->iova, dma->npage, dma->prot);
list_del(&dma->next);
kfree(dma);
}
iommu_domain_free(iommu->domain);
iommu->domain = NULL;
kfree(iommu);
}
static long vfio_iommu_type1_ioctl(void *iommu_data,
unsigned int cmd, unsigned long arg)
{
struct vfio_iommu *iommu = iommu_data;
unsigned long minsz;
if (cmd == VFIO_CHECK_EXTENSION) {
switch (arg) {
case VFIO_TYPE1_IOMMU:
return 1;
default:
return 0;
}
} else if (cmd == VFIO_IOMMU_GET_INFO) {
struct vfio_iommu_type1_info info;
minsz = offsetofend(struct vfio_iommu_type1_info, iova_pgsizes);
if (copy_from_user(&info, (void __user *)arg, minsz))
return -EFAULT;
if (info.argsz < minsz)
return -EINVAL;
info.flags = 0;
info.iova_pgsizes = iommu->domain->ops->pgsize_bitmap;
return copy_to_user((void __user *)arg, &info, minsz);
} else if (cmd == VFIO_IOMMU_MAP_DMA) {
struct vfio_iommu_type1_dma_map map;
uint32_t mask = VFIO_DMA_MAP_FLAG_READ |
VFIO_DMA_MAP_FLAG_WRITE;
minsz = offsetofend(struct vfio_iommu_type1_dma_map, size);
if (copy_from_user(&map, (void __user *)arg, minsz))
return -EFAULT;
if (map.argsz < minsz || map.flags & ~mask)
return -EINVAL;
return vfio_dma_do_map(iommu, &map);
} else if (cmd == VFIO_IOMMU_UNMAP_DMA) {
struct vfio_iommu_type1_dma_unmap unmap;
minsz = offsetofend(struct vfio_iommu_type1_dma_unmap, size);
if (copy_from_user(&unmap, (void __user *)arg, minsz))
return -EFAULT;
if (unmap.argsz < minsz || unmap.flags)
return -EINVAL;
return vfio_dma_do_unmap(iommu, &unmap);
}
return -ENOTTY;
}
static int __init vfio_iommu_type1_init(void)
{
if (!iommu_present(&pci_bus_type))
return -ENODEV;
return vfio_register_iommu_driver(&vfio_iommu_driver_ops_type1);
}
static void __exit vfio_iommu_type1_cleanup(void)
{
vfio_unregister_iommu_driver(&vfio_iommu_driver_ops_type1);
}
