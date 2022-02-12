static struct vfio_dma *vfio_find_dma(struct vfio_iommu *iommu,
dma_addr_t start, size_t size)
{
struct rb_node *node = iommu->dma_list.rb_node;
while (node) {
struct vfio_dma *dma = rb_entry(node, struct vfio_dma, node);
if (start + size <= dma->iova)
node = node->rb_left;
else if (start >= dma->iova + dma->size)
node = node->rb_right;
else
return dma;
}
return NULL;
}
static void vfio_insert_dma(struct vfio_iommu *iommu, struct vfio_dma *new)
{
struct rb_node **link = &iommu->dma_list.rb_node, *parent = NULL;
struct vfio_dma *dma;
while (*link) {
parent = *link;
dma = rb_entry(parent, struct vfio_dma, node);
if (new->iova + new->size <= dma->iova)
link = &(*link)->rb_left;
else
link = &(*link)->rb_right;
}
rb_link_node(&new->node, parent, link);
rb_insert_color(&new->node, &iommu->dma_list);
}
static void vfio_remove_dma(struct vfio_iommu *iommu, struct vfio_dma *old)
{
rb_erase(&old->node, &iommu->dma_list);
}
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
if (!current->mm || !npage)
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
static long vfio_pin_pages(unsigned long vaddr, long npage,
int prot, unsigned long *pfn_base)
{
unsigned long limit = rlimit(RLIMIT_MEMLOCK) >> PAGE_SHIFT;
bool lock_cap = capable(CAP_IPC_LOCK);
long ret, i;
if (!current->mm)
return -ENODEV;
ret = vaddr_get_pfn(vaddr, prot, pfn_base);
if (ret)
return ret;
if (is_invalid_reserved_pfn(*pfn_base))
return 1;
if (!lock_cap && current->mm->locked_vm + 1 > limit) {
put_pfn(*pfn_base, prot);
pr_warn("%s: RLIMIT_MEMLOCK (%ld) exceeded\n", __func__,
limit << PAGE_SHIFT);
return -ENOMEM;
}
if (unlikely(disable_hugepages)) {
vfio_lock_acct(1);
return 1;
}
for (i = 1, vaddr += PAGE_SIZE; i < npage; i++, vaddr += PAGE_SIZE) {
unsigned long pfn = 0;
ret = vaddr_get_pfn(vaddr, prot, &pfn);
if (ret)
break;
if (pfn != *pfn_base + i || is_invalid_reserved_pfn(pfn)) {
put_pfn(pfn, prot);
break;
}
if (!lock_cap && current->mm->locked_vm + i + 1 > limit) {
put_pfn(pfn, prot);
pr_warn("%s: RLIMIT_MEMLOCK (%ld) exceeded\n",
__func__, limit << PAGE_SHIFT);
break;
}
}
vfio_lock_acct(i);
return i;
}
static long vfio_unpin_pages(unsigned long pfn, long npage,
int prot, bool do_accounting)
{
unsigned long unlocked = 0;
long i;
for (i = 0; i < npage; i++)
unlocked += put_pfn(pfn++, prot);
if (do_accounting)
vfio_lock_acct(-unlocked);
return unlocked;
}
static int vfio_unmap_unpin(struct vfio_iommu *iommu, struct vfio_dma *dma,
dma_addr_t iova, size_t *size)
{
dma_addr_t start = iova, end = iova + *size;
long unlocked = 0;
while (iova < end) {
size_t unmapped;
phys_addr_t phys;
phys = iommu_iova_to_phys(iommu->domain, iova);
if (WARN_ON(!phys)) {
iova += PAGE_SIZE;
continue;
}
unmapped = iommu_unmap(iommu->domain, iova, PAGE_SIZE);
if (!unmapped)
break;
unlocked += vfio_unpin_pages(phys >> PAGE_SHIFT,
unmapped >> PAGE_SHIFT,
dma->prot, false);
iova += unmapped;
}
vfio_lock_acct(-unlocked);
*size = iova - start;
return 0;
}
static int vfio_remove_dma_overlap(struct vfio_iommu *iommu, dma_addr_t start,
size_t *size, struct vfio_dma *dma)
{
size_t offset, overlap, tmp;
struct vfio_dma *split;
int ret;
if (!*size)
return 0;
if (likely(start <= dma->iova &&
start + *size >= dma->iova + dma->size)) {
*size = dma->size;
ret = vfio_unmap_unpin(iommu, dma, dma->iova, size);
if (ret)
return ret;
WARN_ON(*size != dma->size);
vfio_remove_dma(iommu, dma);
kfree(dma);
return 0;
}
if (start <= dma->iova) {
overlap = start + *size - dma->iova;
ret = vfio_unmap_unpin(iommu, dma, dma->iova, &overlap);
if (ret)
return ret;
vfio_remove_dma(iommu, dma);
if (overlap < dma->size) {
dma->iova += overlap;
dma->vaddr += overlap;
dma->size -= overlap;
vfio_insert_dma(iommu, dma);
} else
kfree(dma);
*size = overlap;
return 0;
}
if (start + *size >= dma->iova + dma->size) {
offset = start - dma->iova;
overlap = dma->size - offset;
ret = vfio_unmap_unpin(iommu, dma, start, &overlap);
if (ret)
return ret;
dma->size -= overlap;
*size = overlap;
return 0;
}
split = kzalloc(sizeof(*split), GFP_KERNEL);
if (!split)
return -ENOMEM;
offset = start - dma->iova;
ret = vfio_unmap_unpin(iommu, dma, start, size);
if (ret || !*size) {
kfree(split);
return ret;
}
tmp = dma->size;
dma->size = offset;
if (likely(offset + *size < tmp)) {
split->size = tmp - offset - *size;
split->iova = dma->iova + offset + *size;
split->vaddr = dma->vaddr + offset + *size;
split->prot = dma->prot;
vfio_insert_dma(iommu, split);
} else
kfree(split);
return 0;
}
static int vfio_dma_do_unmap(struct vfio_iommu *iommu,
struct vfio_iommu_type1_dma_unmap *unmap)
{
uint64_t mask;
struct vfio_dma *dma;
size_t unmapped = 0, size;
int ret = 0;
mask = ((uint64_t)1 << __ffs(iommu->domain->ops->pgsize_bitmap)) - 1;
if (unmap->iova & mask)
return -EINVAL;
if (!unmap->size || unmap->size & mask)
return -EINVAL;
WARN_ON(mask & PAGE_MASK);
mutex_lock(&iommu->lock);
while ((dma = vfio_find_dma(iommu, unmap->iova, unmap->size))) {
size = unmap->size;
ret = vfio_remove_dma_overlap(iommu, unmap->iova, &size, dma);
if (ret || !size)
break;
unmapped += size;
}
mutex_unlock(&iommu->lock);
unmap->size = unmapped;
return ret;
}
static int map_try_harder(struct vfio_iommu *iommu, dma_addr_t iova,
unsigned long pfn, long npage, int prot)
{
long i;
int ret;
for (i = 0; i < npage; i++, pfn++, iova += PAGE_SIZE) {
ret = iommu_map(iommu->domain, iova,
(phys_addr_t)pfn << PAGE_SHIFT,
PAGE_SIZE, prot);
if (ret)
break;
}
for (; i < npage && i > 0; i--, iova -= PAGE_SIZE)
iommu_unmap(iommu->domain, iova, PAGE_SIZE);
return ret;
}
static int vfio_dma_do_map(struct vfio_iommu *iommu,
struct vfio_iommu_type1_dma_map *map)
{
dma_addr_t end, iova;
unsigned long vaddr = map->vaddr;
size_t size = map->size;
long npage;
int ret = 0, prot = 0;
uint64_t mask;
struct vfio_dma *dma = NULL;
unsigned long pfn;
end = map->iova + map->size;
mask = ((uint64_t)1 << __ffs(iommu->domain->ops->pgsize_bitmap)) - 1;
if (map->flags & VFIO_DMA_MAP_FLAG_WRITE)
prot |= IOMMU_WRITE;
if (map->flags & VFIO_DMA_MAP_FLAG_READ)
prot |= IOMMU_READ;
if (!prot)
return -EINVAL;
if (iommu->cache)
prot |= IOMMU_CACHE;
if (vaddr & mask)
return -EINVAL;
if (map->iova & mask)
return -EINVAL;
if (!map->size || map->size & mask)
return -EINVAL;
WARN_ON(mask & PAGE_MASK);
if (end && end < map->iova)
return -EINVAL;
if (vaddr + map->size && vaddr + map->size < vaddr)
return -EINVAL;
mutex_lock(&iommu->lock);
if (vfio_find_dma(iommu, map->iova, map->size)) {
mutex_unlock(&iommu->lock);
return -EEXIST;
}
for (iova = map->iova; iova < end; iova += size, vaddr += size) {
long i;
npage = vfio_pin_pages(vaddr, (end - iova) >> PAGE_SHIFT,
prot, &pfn);
if (npage <= 0) {
WARN_ON(!npage);
ret = (int)npage;
goto out;
}
for (i = 0; i < npage; i++) {
if (iommu_iova_to_phys(iommu->domain,
iova + (i << PAGE_SHIFT))) {
ret = -EBUSY;
goto out_unpin;
}
}
ret = iommu_map(iommu->domain, iova,
(phys_addr_t)pfn << PAGE_SHIFT,
npage << PAGE_SHIFT, prot);
if (ret) {
if (ret != -EBUSY ||
map_try_harder(iommu, iova, pfn, npage, prot)) {
goto out_unpin;
}
}
size = npage << PAGE_SHIFT;
if (likely(iova)) {
struct vfio_dma *tmp;
tmp = vfio_find_dma(iommu, iova - 1, 1);
if (tmp && tmp->prot == prot &&
tmp->vaddr + tmp->size == vaddr) {
tmp->size += size;
iova = tmp->iova;
size = tmp->size;
vaddr = tmp->vaddr;
dma = tmp;
}
}
if (likely(iova + size)) {
struct vfio_dma *tmp;
tmp = vfio_find_dma(iommu, iova + size, 1);
if (tmp && tmp->prot == prot &&
tmp->vaddr == vaddr + size) {
vfio_remove_dma(iommu, tmp);
if (dma) {
dma->size += tmp->size;
kfree(tmp);
} else {
size += tmp->size;
tmp->size = size;
tmp->iova = iova;
tmp->vaddr = vaddr;
vfio_insert_dma(iommu, tmp);
dma = tmp;
}
}
}
if (!dma) {
dma = kzalloc(sizeof(*dma), GFP_KERNEL);
if (!dma) {
iommu_unmap(iommu->domain, iova, size);
ret = -ENOMEM;
goto out_unpin;
}
dma->size = size;
dma->iova = iova;
dma->vaddr = vaddr;
dma->prot = prot;
vfio_insert_dma(iommu, dma);
}
}
WARN_ON(ret);
mutex_unlock(&iommu->lock);
return ret;
out_unpin:
vfio_unpin_pages(pfn, npage, prot, true);
out:
iova = map->iova;
size = map->size;
while ((dma = vfio_find_dma(iommu, iova, size))) {
int r = vfio_remove_dma_overlap(iommu, iova,
&size, dma);
if (WARN_ON(r || !size))
break;
}
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
iommu->dma_list = RB_ROOT;
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
struct rb_node *node;
list_for_each_entry_safe(group, group_tmp, &iommu->group_list, next) {
iommu_detach_group(iommu->domain, group->iommu_group);
list_del(&group->next);
kfree(group);
}
while ((node = rb_first(&iommu->dma_list))) {
struct vfio_dma *dma = rb_entry(node, struct vfio_dma, node);
size_t size = dma->size;
vfio_remove_dma_overlap(iommu, dma->iova, &size, dma);
if (WARN_ON(!size))
break;
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
long ret;
minsz = offsetofend(struct vfio_iommu_type1_dma_unmap, size);
if (copy_from_user(&unmap, (void __user *)arg, minsz))
return -EFAULT;
if (unmap.argsz < minsz || unmap.flags)
return -EINVAL;
ret = vfio_dma_do_unmap(iommu, &unmap);
if (ret)
return ret;
return copy_to_user((void __user *)arg, &unmap, minsz);
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
