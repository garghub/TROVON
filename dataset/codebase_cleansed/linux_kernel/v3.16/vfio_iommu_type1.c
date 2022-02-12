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
static void vfio_link_dma(struct vfio_iommu *iommu, struct vfio_dma *new)
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
static void vfio_unlink_dma(struct vfio_iommu *iommu, struct vfio_dma *old)
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
struct page *head = compound_head(tail);
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
static void vfio_unmap_unpin(struct vfio_iommu *iommu, struct vfio_dma *dma)
{
dma_addr_t iova = dma->iova, end = dma->iova + dma->size;
struct vfio_domain *domain, *d;
long unlocked = 0;
if (!dma->size)
return;
domain = d = list_first_entry(&iommu->domain_list,
struct vfio_domain, next);
list_for_each_entry_continue(d, &iommu->domain_list, next)
iommu_unmap(d->domain, dma->iova, dma->size);
while (iova < end) {
size_t unmapped;
phys_addr_t phys;
phys = iommu_iova_to_phys(domain->domain, iova);
if (WARN_ON(!phys)) {
iova += PAGE_SIZE;
continue;
}
unmapped = iommu_unmap(domain->domain, iova, PAGE_SIZE);
if (WARN_ON(!unmapped))
break;
unlocked += vfio_unpin_pages(phys >> PAGE_SHIFT,
unmapped >> PAGE_SHIFT,
dma->prot, false);
iova += unmapped;
}
vfio_lock_acct(-unlocked);
}
static void vfio_remove_dma(struct vfio_iommu *iommu, struct vfio_dma *dma)
{
vfio_unmap_unpin(iommu, dma);
vfio_unlink_dma(iommu, dma);
kfree(dma);
}
static unsigned long vfio_pgsize_bitmap(struct vfio_iommu *iommu)
{
struct vfio_domain *domain;
unsigned long bitmap = PAGE_MASK;
mutex_lock(&iommu->lock);
list_for_each_entry(domain, &iommu->domain_list, next)
bitmap &= domain->domain->ops->pgsize_bitmap;
mutex_unlock(&iommu->lock);
return bitmap;
}
static int vfio_dma_do_unmap(struct vfio_iommu *iommu,
struct vfio_iommu_type1_dma_unmap *unmap)
{
uint64_t mask;
struct vfio_dma *dma;
size_t unmapped = 0;
int ret = 0;
mask = ((uint64_t)1 << __ffs(vfio_pgsize_bitmap(iommu))) - 1;
if (unmap->iova & mask)
return -EINVAL;
if (!unmap->size || unmap->size & mask)
return -EINVAL;
WARN_ON(mask & PAGE_MASK);
mutex_lock(&iommu->lock);
if (iommu->v2) {
dma = vfio_find_dma(iommu, unmap->iova, 0);
if (dma && dma->iova != unmap->iova) {
ret = -EINVAL;
goto unlock;
}
dma = vfio_find_dma(iommu, unmap->iova + unmap->size - 1, 0);
if (dma && dma->iova + dma->size != unmap->iova + unmap->size) {
ret = -EINVAL;
goto unlock;
}
}
while ((dma = vfio_find_dma(iommu, unmap->iova, unmap->size))) {
if (!iommu->v2 && unmap->iova > dma->iova)
break;
unmapped += dma->size;
vfio_remove_dma(iommu, dma);
}
unlock:
mutex_unlock(&iommu->lock);
unmap->size = unmapped;
return ret;
}
static int map_try_harder(struct vfio_domain *domain, dma_addr_t iova,
unsigned long pfn, long npage, int prot)
{
long i;
int ret;
for (i = 0; i < npage; i++, pfn++, iova += PAGE_SIZE) {
ret = iommu_map(domain->domain, iova,
(phys_addr_t)pfn << PAGE_SHIFT,
PAGE_SIZE, prot | domain->prot);
if (ret)
break;
}
for (; i < npage && i > 0; i--, iova -= PAGE_SIZE)
iommu_unmap(domain->domain, iova, PAGE_SIZE);
return ret;
}
static int vfio_iommu_map(struct vfio_iommu *iommu, dma_addr_t iova,
unsigned long pfn, long npage, int prot)
{
struct vfio_domain *d;
int ret;
list_for_each_entry(d, &iommu->domain_list, next) {
ret = iommu_map(d->domain, iova, (phys_addr_t)pfn << PAGE_SHIFT,
npage << PAGE_SHIFT, prot | d->prot);
if (ret) {
if (ret != -EBUSY ||
map_try_harder(d, iova, pfn, npage, prot))
goto unwind;
}
}
return 0;
unwind:
list_for_each_entry_continue_reverse(d, &iommu->domain_list, next)
iommu_unmap(d->domain, iova, npage << PAGE_SHIFT);
return ret;
}
static int vfio_dma_do_map(struct vfio_iommu *iommu,
struct vfio_iommu_type1_dma_map *map)
{
dma_addr_t iova = map->iova;
unsigned long vaddr = map->vaddr;
size_t size = map->size;
long npage;
int ret = 0, prot = 0;
uint64_t mask;
struct vfio_dma *dma;
unsigned long pfn;
if (map->size != size || map->vaddr != vaddr || map->iova != iova)
return -EINVAL;
mask = ((uint64_t)1 << __ffs(vfio_pgsize_bitmap(iommu))) - 1;
WARN_ON(mask & PAGE_MASK);
if (map->flags & VFIO_DMA_MAP_FLAG_WRITE)
prot |= IOMMU_WRITE;
if (map->flags & VFIO_DMA_MAP_FLAG_READ)
prot |= IOMMU_READ;
if (!prot || !size || (size | iova | vaddr) & mask)
return -EINVAL;
if (iova + size - 1 < iova || vaddr + size - 1 < vaddr)
return -EINVAL;
mutex_lock(&iommu->lock);
if (vfio_find_dma(iommu, iova, size)) {
mutex_unlock(&iommu->lock);
return -EEXIST;
}
dma = kzalloc(sizeof(*dma), GFP_KERNEL);
if (!dma) {
mutex_unlock(&iommu->lock);
return -ENOMEM;
}
dma->iova = iova;
dma->vaddr = vaddr;
dma->prot = prot;
vfio_link_dma(iommu, dma);
while (size) {
npage = vfio_pin_pages(vaddr + dma->size,
size >> PAGE_SHIFT, prot, &pfn);
if (npage <= 0) {
WARN_ON(!npage);
ret = (int)npage;
break;
}
ret = vfio_iommu_map(iommu, iova + dma->size, pfn, npage, prot);
if (ret) {
vfio_unpin_pages(pfn, npage, prot, true);
break;
}
size -= npage << PAGE_SHIFT;
dma->size += npage << PAGE_SHIFT;
}
if (ret)
vfio_remove_dma(iommu, dma);
mutex_unlock(&iommu->lock);
return ret;
}
static int vfio_bus_type(struct device *dev, void *data)
{
struct bus_type **bus = data;
if (*bus && *bus != dev->bus)
return -EINVAL;
*bus = dev->bus;
return 0;
}
static int vfio_iommu_replay(struct vfio_iommu *iommu,
struct vfio_domain *domain)
{
struct vfio_domain *d;
struct rb_node *n;
int ret;
d = list_first_entry(&iommu->domain_list, struct vfio_domain, next);
n = rb_first(&iommu->dma_list);
if (WARN_ON(n && !d))
return -EINVAL;
for (; n; n = rb_next(n)) {
struct vfio_dma *dma;
dma_addr_t iova;
dma = rb_entry(n, struct vfio_dma, node);
iova = dma->iova;
while (iova < dma->iova + dma->size) {
phys_addr_t phys = iommu_iova_to_phys(d->domain, iova);
size_t size;
if (WARN_ON(!phys)) {
iova += PAGE_SIZE;
continue;
}
size = PAGE_SIZE;
while (iova + size < dma->iova + dma->size &&
phys + size == iommu_iova_to_phys(d->domain,
iova + size))
size += PAGE_SIZE;
ret = iommu_map(domain->domain, iova, phys,
size, dma->prot | domain->prot);
if (ret)
return ret;
iova += size;
}
}
return 0;
}
static int vfio_iommu_type1_attach_group(void *iommu_data,
struct iommu_group *iommu_group)
{
struct vfio_iommu *iommu = iommu_data;
struct vfio_group *group, *g;
struct vfio_domain *domain, *d;
struct bus_type *bus = NULL;
int ret;
mutex_lock(&iommu->lock);
list_for_each_entry(d, &iommu->domain_list, next) {
list_for_each_entry(g, &d->group_list, next) {
if (g->iommu_group != iommu_group)
continue;
mutex_unlock(&iommu->lock);
return -EINVAL;
}
}
group = kzalloc(sizeof(*group), GFP_KERNEL);
domain = kzalloc(sizeof(*domain), GFP_KERNEL);
if (!group || !domain) {
ret = -ENOMEM;
goto out_free;
}
group->iommu_group = iommu_group;
ret = iommu_group_for_each_dev(iommu_group, &bus, vfio_bus_type);
if (ret)
goto out_free;
domain->domain = iommu_domain_alloc(bus);
if (!domain->domain) {
ret = -EIO;
goto out_free;
}
ret = iommu_attach_group(domain->domain, iommu_group);
if (ret)
goto out_domain;
INIT_LIST_HEAD(&domain->group_list);
list_add(&group->next, &domain->group_list);
if (!allow_unsafe_interrupts &&
!iommu_domain_has_cap(domain->domain, IOMMU_CAP_INTR_REMAP)) {
pr_warn("%s: No interrupt remapping support. Use the module param \"allow_unsafe_interrupts\" to enable VFIO IOMMU support on this platform\n",
__func__);
ret = -EPERM;
goto out_detach;
}
if (iommu_domain_has_cap(domain->domain, IOMMU_CAP_CACHE_COHERENCY))
domain->prot |= IOMMU_CACHE;
list_for_each_entry(d, &iommu->domain_list, next) {
if (d->domain->ops == domain->domain->ops &&
d->prot == domain->prot) {
iommu_detach_group(domain->domain, iommu_group);
if (!iommu_attach_group(d->domain, iommu_group)) {
list_add(&group->next, &d->group_list);
iommu_domain_free(domain->domain);
kfree(domain);
mutex_unlock(&iommu->lock);
return 0;
}
ret = iommu_attach_group(domain->domain, iommu_group);
if (ret)
goto out_domain;
}
}
ret = vfio_iommu_replay(iommu, domain);
if (ret)
goto out_detach;
list_add(&domain->next, &iommu->domain_list);
mutex_unlock(&iommu->lock);
return 0;
out_detach:
iommu_detach_group(domain->domain, iommu_group);
out_domain:
iommu_domain_free(domain->domain);
out_free:
kfree(domain);
kfree(group);
mutex_unlock(&iommu->lock);
return ret;
}
static void vfio_iommu_unmap_unpin_all(struct vfio_iommu *iommu)
{
struct rb_node *node;
while ((node = rb_first(&iommu->dma_list)))
vfio_remove_dma(iommu, rb_entry(node, struct vfio_dma, node));
}
static void vfio_iommu_type1_detach_group(void *iommu_data,
struct iommu_group *iommu_group)
{
struct vfio_iommu *iommu = iommu_data;
struct vfio_domain *domain;
struct vfio_group *group;
mutex_lock(&iommu->lock);
list_for_each_entry(domain, &iommu->domain_list, next) {
list_for_each_entry(group, &domain->group_list, next) {
if (group->iommu_group != iommu_group)
continue;
iommu_detach_group(domain->domain, iommu_group);
list_del(&group->next);
kfree(group);
if (list_empty(&domain->group_list)) {
if (list_is_singular(&iommu->domain_list))
vfio_iommu_unmap_unpin_all(iommu);
iommu_domain_free(domain->domain);
list_del(&domain->next);
kfree(domain);
}
goto done;
}
}
done:
mutex_unlock(&iommu->lock);
}
static void *vfio_iommu_type1_open(unsigned long arg)
{
struct vfio_iommu *iommu;
if (arg != VFIO_TYPE1_IOMMU && arg != VFIO_TYPE1v2_IOMMU)
return ERR_PTR(-EINVAL);
iommu = kzalloc(sizeof(*iommu), GFP_KERNEL);
if (!iommu)
return ERR_PTR(-ENOMEM);
INIT_LIST_HEAD(&iommu->domain_list);
iommu->dma_list = RB_ROOT;
mutex_init(&iommu->lock);
iommu->v2 = (arg == VFIO_TYPE1v2_IOMMU);
return iommu;
}
static void vfio_iommu_type1_release(void *iommu_data)
{
struct vfio_iommu *iommu = iommu_data;
struct vfio_domain *domain, *domain_tmp;
struct vfio_group *group, *group_tmp;
vfio_iommu_unmap_unpin_all(iommu);
list_for_each_entry_safe(domain, domain_tmp,
&iommu->domain_list, next) {
list_for_each_entry_safe(group, group_tmp,
&domain->group_list, next) {
iommu_detach_group(domain->domain, group->iommu_group);
list_del(&group->next);
kfree(group);
}
iommu_domain_free(domain->domain);
list_del(&domain->next);
kfree(domain);
}
kfree(iommu);
}
static int vfio_domains_have_iommu_cache(struct vfio_iommu *iommu)
{
struct vfio_domain *domain;
int ret = 1;
mutex_lock(&iommu->lock);
list_for_each_entry(domain, &iommu->domain_list, next) {
if (!(domain->prot & IOMMU_CACHE)) {
ret = 0;
break;
}
}
mutex_unlock(&iommu->lock);
return ret;
}
static long vfio_iommu_type1_ioctl(void *iommu_data,
unsigned int cmd, unsigned long arg)
{
struct vfio_iommu *iommu = iommu_data;
unsigned long minsz;
if (cmd == VFIO_CHECK_EXTENSION) {
switch (arg) {
case VFIO_TYPE1_IOMMU:
case VFIO_TYPE1v2_IOMMU:
return 1;
case VFIO_DMA_CC_IOMMU:
if (!iommu)
return 0;
return vfio_domains_have_iommu_cache(iommu);
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
info.iova_pgsizes = vfio_pgsize_bitmap(iommu);
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
return vfio_register_iommu_driver(&vfio_iommu_driver_ops_type1);
}
static void __exit vfio_iommu_type1_cleanup(void)
{
vfio_unregister_iommu_driver(&vfio_iommu_driver_ops_type1);
}
