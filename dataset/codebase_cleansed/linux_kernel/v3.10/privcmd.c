static long privcmd_ioctl_hypercall(void __user *udata)
{
struct privcmd_hypercall hypercall;
long ret;
if (copy_from_user(&hypercall, udata, sizeof(hypercall)))
return -EFAULT;
ret = privcmd_call(hypercall.op,
hypercall.arg[0], hypercall.arg[1],
hypercall.arg[2], hypercall.arg[3],
hypercall.arg[4]);
return ret;
}
static void free_page_list(struct list_head *pages)
{
struct page *p, *n;
list_for_each_entry_safe(p, n, pages, lru)
__free_page(p);
INIT_LIST_HEAD(pages);
}
static int gather_array(struct list_head *pagelist,
unsigned nelem, size_t size,
const void __user *data)
{
unsigned pageidx;
void *pagedata;
int ret;
if (size > PAGE_SIZE)
return 0;
pageidx = PAGE_SIZE;
pagedata = NULL;
while (nelem--) {
if (pageidx > PAGE_SIZE-size) {
struct page *page = alloc_page(GFP_KERNEL);
ret = -ENOMEM;
if (page == NULL)
goto fail;
pagedata = page_address(page);
list_add_tail(&page->lru, pagelist);
pageidx = 0;
}
ret = -EFAULT;
if (copy_from_user(pagedata + pageidx, data, size))
goto fail;
data += size;
pageidx += size;
}
ret = 0;
fail:
return ret;
}
static int traverse_pages(unsigned nelem, size_t size,
struct list_head *pos,
int (*fn)(void *data, void *state),
void *state)
{
void *pagedata;
unsigned pageidx;
int ret = 0;
BUG_ON(size > PAGE_SIZE);
pageidx = PAGE_SIZE;
pagedata = NULL;
while (nelem--) {
if (pageidx > PAGE_SIZE-size) {
struct page *page;
pos = pos->next;
page = list_entry(pos, struct page, lru);
pagedata = page_address(page);
pageidx = 0;
}
ret = (*fn)(pagedata + pageidx, state);
if (ret)
break;
pageidx += size;
}
return ret;
}
static int mmap_mfn_range(void *data, void *state)
{
struct privcmd_mmap_entry *msg = data;
struct mmap_mfn_state *st = state;
struct vm_area_struct *vma = st->vma;
int rc;
if ((msg->npages > (LONG_MAX >> PAGE_SHIFT)) ||
((unsigned long)(msg->npages << PAGE_SHIFT) >= -st->va))
return -EINVAL;
if ((msg->va != st->va) ||
((msg->va+(msg->npages<<PAGE_SHIFT)) > vma->vm_end))
return -EINVAL;
rc = xen_remap_domain_mfn_range(vma,
msg->va & PAGE_MASK,
msg->mfn, msg->npages,
vma->vm_page_prot,
st->domain, NULL);
if (rc < 0)
return rc;
st->va += msg->npages << PAGE_SHIFT;
return 0;
}
static long privcmd_ioctl_mmap(void __user *udata)
{
struct privcmd_mmap mmapcmd;
struct mm_struct *mm = current->mm;
struct vm_area_struct *vma;
int rc;
LIST_HEAD(pagelist);
struct mmap_mfn_state state;
if (xen_feature(XENFEAT_auto_translated_physmap))
return -ENOSYS;
if (copy_from_user(&mmapcmd, udata, sizeof(mmapcmd)))
return -EFAULT;
rc = gather_array(&pagelist,
mmapcmd.num, sizeof(struct privcmd_mmap_entry),
mmapcmd.entry);
if (rc || list_empty(&pagelist))
goto out;
down_write(&mm->mmap_sem);
{
struct page *page = list_first_entry(&pagelist,
struct page, lru);
struct privcmd_mmap_entry *msg = page_address(page);
vma = find_vma(mm, msg->va);
rc = -EINVAL;
if (!vma || (msg->va != vma->vm_start) ||
!privcmd_enforce_singleshot_mapping(vma))
goto out_up;
}
state.va = vma->vm_start;
state.vma = vma;
state.domain = mmapcmd.dom;
rc = traverse_pages(mmapcmd.num, sizeof(struct privcmd_mmap_entry),
&pagelist,
mmap_mfn_range, &state);
out_up:
up_write(&mm->mmap_sem);
out:
free_page_list(&pagelist);
return rc;
}
static int mmap_batch_fn(void *data, void *state)
{
xen_pfn_t *mfnp = data;
struct mmap_batch_state *st = state;
struct vm_area_struct *vma = st->vma;
struct page **pages = vma->vm_private_data;
struct page *cur_page = NULL;
int ret;
if (xen_feature(XENFEAT_auto_translated_physmap))
cur_page = pages[st->index++];
ret = xen_remap_domain_mfn_range(st->vma, st->va & PAGE_MASK, *mfnp, 1,
st->vma->vm_page_prot, st->domain,
&cur_page);
if (st->version == 1) {
if (ret < 0) {
*mfnp |= (ret == -ENOENT) ?
PRIVCMD_MMAPBATCH_PAGED_ERROR :
PRIVCMD_MMAPBATCH_MFN_ERROR;
}
} else {
*((int *) mfnp) = ret;
}
if (ret < 0) {
if (ret == -ENOENT)
st->global_error = -ENOENT;
else {
if (st->global_error == 0)
st->global_error = 1;
}
}
st->va += PAGE_SIZE;
return 0;
}
static int mmap_return_errors(void *data, void *state)
{
struct mmap_batch_state *st = state;
if (st->version == 1) {
xen_pfn_t mfnp = *((xen_pfn_t *) data);
if (mfnp & PRIVCMD_MMAPBATCH_MFN_ERROR)
return __put_user(mfnp, st->user_mfn++);
else
st->user_mfn++;
} else {
int err = *((int *) data);
if (err)
return __put_user(err, st->user_err++);
else
st->user_err++;
}
return 0;
}
static int alloc_empty_pages(struct vm_area_struct *vma, int numpgs)
{
int rc;
struct page **pages;
pages = kcalloc(numpgs, sizeof(pages[0]), GFP_KERNEL);
if (pages == NULL)
return -ENOMEM;
rc = alloc_xenballooned_pages(numpgs, pages, 0);
if (rc != 0) {
pr_warn("%s Could not alloc %d pfns rc:%d\n", __func__,
numpgs, rc);
kfree(pages);
return -ENOMEM;
}
BUG_ON(vma->vm_private_data != PRIV_VMA_LOCKED);
vma->vm_private_data = pages;
return 0;
}
static long privcmd_ioctl_mmap_batch(void __user *udata, int version)
{
int ret;
struct privcmd_mmapbatch_v2 m;
struct mm_struct *mm = current->mm;
struct vm_area_struct *vma;
unsigned long nr_pages;
LIST_HEAD(pagelist);
struct mmap_batch_state state;
switch (version) {
case 1:
if (copy_from_user(&m, udata, sizeof(struct privcmd_mmapbatch)))
return -EFAULT;
m.err = NULL;
if (!access_ok(VERIFY_WRITE, m.arr, m.num * sizeof(*m.arr)))
return -EFAULT;
break;
case 2:
if (copy_from_user(&m, udata, sizeof(struct privcmd_mmapbatch_v2)))
return -EFAULT;
if (!access_ok(VERIFY_WRITE, m.err, m.num * (sizeof(*m.err))))
return -EFAULT;
break;
default:
return -EINVAL;
}
nr_pages = m.num;
if ((m.num <= 0) || (nr_pages > (LONG_MAX >> PAGE_SHIFT)))
return -EINVAL;
ret = gather_array(&pagelist, m.num, sizeof(xen_pfn_t), m.arr);
if (ret)
goto out;
if (list_empty(&pagelist)) {
ret = -EINVAL;
goto out;
}
if (version == 2) {
if (clear_user(m.err, sizeof(int) * m.num)) {
ret = -EFAULT;
goto out;
}
}
down_write(&mm->mmap_sem);
vma = find_vma(mm, m.addr);
if (!vma ||
vma->vm_ops != &privcmd_vm_ops ||
(m.addr != vma->vm_start) ||
((m.addr + (nr_pages << PAGE_SHIFT)) != vma->vm_end) ||
!privcmd_enforce_singleshot_mapping(vma)) {
up_write(&mm->mmap_sem);
ret = -EINVAL;
goto out;
}
if (xen_feature(XENFEAT_auto_translated_physmap)) {
ret = alloc_empty_pages(vma, m.num);
if (ret < 0) {
up_write(&mm->mmap_sem);
goto out;
}
}
state.domain = m.dom;
state.vma = vma;
state.va = m.addr;
state.index = 0;
state.global_error = 0;
state.version = version;
BUG_ON(traverse_pages(m.num, sizeof(xen_pfn_t),
&pagelist, mmap_batch_fn, &state));
up_write(&mm->mmap_sem);
if (state.global_error) {
state.user_mfn = (xen_pfn_t *)m.arr;
state.user_err = m.err;
ret = traverse_pages(m.num, sizeof(xen_pfn_t),
&pagelist, mmap_return_errors, &state);
} else
ret = 0;
if ((ret == 0) && (state.global_error == -ENOENT))
ret = -ENOENT;
out:
free_page_list(&pagelist);
return ret;
}
static long privcmd_ioctl(struct file *file,
unsigned int cmd, unsigned long data)
{
int ret = -ENOSYS;
void __user *udata = (void __user *) data;
switch (cmd) {
case IOCTL_PRIVCMD_HYPERCALL:
ret = privcmd_ioctl_hypercall(udata);
break;
case IOCTL_PRIVCMD_MMAP:
ret = privcmd_ioctl_mmap(udata);
break;
case IOCTL_PRIVCMD_MMAPBATCH:
ret = privcmd_ioctl_mmap_batch(udata, 1);
break;
case IOCTL_PRIVCMD_MMAPBATCH_V2:
ret = privcmd_ioctl_mmap_batch(udata, 2);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static void privcmd_close(struct vm_area_struct *vma)
{
struct page **pages = vma->vm_private_data;
int numpgs = (vma->vm_end - vma->vm_start) >> PAGE_SHIFT;
if (!xen_feature(XENFEAT_auto_translated_physmap) || !numpgs || !pages)
return;
xen_unmap_domain_mfn_range(vma, numpgs, pages);
free_xenballooned_pages(numpgs, pages);
kfree(pages);
}
static int privcmd_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
printk(KERN_DEBUG "privcmd_fault: vma=%p %lx-%lx, pgoff=%lx, uv=%p\n",
vma, vma->vm_start, vma->vm_end,
vmf->pgoff, vmf->virtual_address);
return VM_FAULT_SIGBUS;
}
static int privcmd_mmap(struct file *file, struct vm_area_struct *vma)
{
vma->vm_flags |= VM_IO | VM_PFNMAP | VM_DONTCOPY |
VM_DONTEXPAND | VM_DONTDUMP;
vma->vm_ops = &privcmd_vm_ops;
vma->vm_private_data = NULL;
return 0;
}
static int privcmd_enforce_singleshot_mapping(struct vm_area_struct *vma)
{
return !cmpxchg(&vma->vm_private_data, NULL, PRIV_VMA_LOCKED);
}
static int __init privcmd_init(void)
{
int err;
if (!xen_domain())
return -ENODEV;
err = misc_register(&privcmd_dev);
if (err != 0) {
printk(KERN_ERR "Could not register Xen privcmd device\n");
return err;
}
return 0;
}
static void __exit privcmd_exit(void)
{
misc_deregister(&privcmd_dev);
}
