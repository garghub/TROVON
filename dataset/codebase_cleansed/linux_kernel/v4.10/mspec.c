static inline int
mspec_zero_block(unsigned long addr, int len)
{
int status;
if (is_sn2) {
if (is_shub2()) {
int nid;
void *p;
int i;
nid = nasid_to_cnodeid(get_node_number(__pa(addr)));
p = (void *)TO_AMO(scratch_page[nid]);
for (i=0; i < SH2_AMO_CACHE_ENTRIES; i++) {
FETCHOP_LOAD_OP(p, FETCHOP_LOAD);
p += FETCHOP_VAR_SIZE;
}
}
status = bte_copy(0, addr & ~__IA64_UNCACHED_OFFSET, len,
BTE_WACQUIRE | BTE_ZERO_FILL, NULL);
} else {
memset((char *) addr, 0, len);
status = 0;
}
return status;
}
static void
mspec_open(struct vm_area_struct *vma)
{
struct vma_data *vdata;
vdata = vma->vm_private_data;
atomic_inc(&vdata->refcnt);
}
static void
mspec_close(struct vm_area_struct *vma)
{
struct vma_data *vdata;
int index, last_index;
unsigned long my_page;
vdata = vma->vm_private_data;
if (!atomic_dec_and_test(&vdata->refcnt))
return;
last_index = (vdata->vm_end - vdata->vm_start) >> PAGE_SHIFT;
for (index = 0; index < last_index; index++) {
if (vdata->maddr[index] == 0)
continue;
my_page = vdata->maddr[index];
vdata->maddr[index] = 0;
if (!mspec_zero_block(my_page, PAGE_SIZE))
uncached_free_page(my_page, 1);
else
printk(KERN_WARNING "mspec_close(): "
"failed to zero page %ld\n", my_page);
}
kvfree(vdata);
}
static int
mspec_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
unsigned long paddr, maddr;
unsigned long pfn;
pgoff_t index = vmf->pgoff;
struct vma_data *vdata = vma->vm_private_data;
maddr = (volatile unsigned long) vdata->maddr[index];
if (maddr == 0) {
maddr = uncached_alloc_page(numa_node_id(), 1);
if (maddr == 0)
return VM_FAULT_OOM;
spin_lock(&vdata->lock);
if (vdata->maddr[index] == 0) {
vdata->count++;
vdata->maddr[index] = maddr;
} else {
uncached_free_page(maddr, 1);
maddr = vdata->maddr[index];
}
spin_unlock(&vdata->lock);
}
if (vdata->type == MSPEC_FETCHOP)
paddr = TO_AMO(maddr);
else
paddr = maddr & ~__IA64_UNCACHED_OFFSET;
pfn = paddr >> PAGE_SHIFT;
vm_insert_pfn(vma, vmf->address, pfn);
return VM_FAULT_NOPAGE;
}
static int
mspec_mmap(struct file *file, struct vm_area_struct *vma,
enum mspec_page_type type)
{
struct vma_data *vdata;
int pages, vdata_size;
if (vma->vm_pgoff != 0)
return -EINVAL;
if ((vma->vm_flags & VM_SHARED) == 0)
return -EINVAL;
if ((vma->vm_flags & VM_WRITE) == 0)
return -EPERM;
pages = vma_pages(vma);
vdata_size = sizeof(struct vma_data) + pages * sizeof(long);
if (vdata_size <= PAGE_SIZE)
vdata = kzalloc(vdata_size, GFP_KERNEL);
else
vdata = vzalloc(vdata_size);
if (!vdata)
return -ENOMEM;
vdata->vm_start = vma->vm_start;
vdata->vm_end = vma->vm_end;
vdata->type = type;
spin_lock_init(&vdata->lock);
atomic_set(&vdata->refcnt, 1);
vma->vm_private_data = vdata;
vma->vm_flags |= VM_IO | VM_PFNMAP | VM_DONTEXPAND | VM_DONTDUMP;
if (vdata->type == MSPEC_FETCHOP || vdata->type == MSPEC_UNCACHED)
vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
vma->vm_ops = &mspec_vm_ops;
return 0;
}
static int
fetchop_mmap(struct file *file, struct vm_area_struct *vma)
{
return mspec_mmap(file, vma, MSPEC_FETCHOP);
}
static int
cached_mmap(struct file *file, struct vm_area_struct *vma)
{
return mspec_mmap(file, vma, MSPEC_CACHED);
}
static int
uncached_mmap(struct file *file, struct vm_area_struct *vma)
{
return mspec_mmap(file, vma, MSPEC_UNCACHED);
}
static int __init
mspec_init(void)
{
int ret;
int nid;
#ifdef CONFIG_SGI_SN
if (ia64_platform_is("sn2")) {
is_sn2 = 1;
if (is_shub2()) {
ret = -ENOMEM;
for_each_node_state(nid, N_ONLINE) {
int actual_nid;
int nasid;
unsigned long phys;
scratch_page[nid] = uncached_alloc_page(nid, 1);
if (scratch_page[nid] == 0)
goto free_scratch_pages;
phys = __pa(scratch_page[nid]);
nasid = get_node_number(phys);
actual_nid = nasid_to_cnodeid(nasid);
if (actual_nid != nid)
goto free_scratch_pages;
}
}
ret = misc_register(&fetchop_miscdev);
if (ret) {
printk(KERN_ERR
"%s: failed to register device %i\n",
FETCHOP_ID, ret);
goto free_scratch_pages;
}
}
#endif
ret = misc_register(&cached_miscdev);
if (ret) {
printk(KERN_ERR "%s: failed to register device %i\n",
CACHED_ID, ret);
if (is_sn2)
misc_deregister(&fetchop_miscdev);
goto free_scratch_pages;
}
ret = misc_register(&uncached_miscdev);
if (ret) {
printk(KERN_ERR "%s: failed to register device %i\n",
UNCACHED_ID, ret);
misc_deregister(&cached_miscdev);
if (is_sn2)
misc_deregister(&fetchop_miscdev);
goto free_scratch_pages;
}
printk(KERN_INFO "%s %s initialized devices: %s %s %s\n",
MSPEC_BASENAME, REVISION, is_sn2 ? FETCHOP_ID : "",
CACHED_ID, UNCACHED_ID);
return 0;
free_scratch_pages:
for_each_node(nid) {
if (scratch_page[nid] != 0)
uncached_free_page(scratch_page[nid], 1);
}
return ret;
}
static void __exit
mspec_exit(void)
{
int nid;
misc_deregister(&uncached_miscdev);
misc_deregister(&cached_miscdev);
if (is_sn2) {
misc_deregister(&fetchop_miscdev);
for_each_node(nid) {
if (scratch_page[nid] != 0)
uncached_free_page(scratch_page[nid], 1);
}
}
}
