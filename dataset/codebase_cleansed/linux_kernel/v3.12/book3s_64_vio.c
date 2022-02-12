static long kvmppc_stt_npages(unsigned long window_size)
{
return ALIGN((window_size >> SPAPR_TCE_SHIFT)
* sizeof(u64), PAGE_SIZE) / PAGE_SIZE;
}
static void release_spapr_tce_table(struct kvmppc_spapr_tce_table *stt)
{
struct kvm *kvm = stt->kvm;
int i;
mutex_lock(&kvm->lock);
list_del(&stt->list);
for (i = 0; i < kvmppc_stt_npages(stt->window_size); i++)
__free_page(stt->pages[i]);
kfree(stt);
mutex_unlock(&kvm->lock);
kvm_put_kvm(kvm);
}
static int kvm_spapr_tce_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct kvmppc_spapr_tce_table *stt = vma->vm_file->private_data;
struct page *page;
if (vmf->pgoff >= kvmppc_stt_npages(stt->window_size))
return VM_FAULT_SIGBUS;
page = stt->pages[vmf->pgoff];
get_page(page);
vmf->page = page;
return 0;
}
static int kvm_spapr_tce_mmap(struct file *file, struct vm_area_struct *vma)
{
vma->vm_ops = &kvm_spapr_tce_vm_ops;
return 0;
}
static int kvm_spapr_tce_release(struct inode *inode, struct file *filp)
{
struct kvmppc_spapr_tce_table *stt = filp->private_data;
release_spapr_tce_table(stt);
return 0;
}
long kvm_vm_ioctl_create_spapr_tce(struct kvm *kvm,
struct kvm_create_spapr_tce *args)
{
struct kvmppc_spapr_tce_table *stt = NULL;
long npages;
int ret = -ENOMEM;
int i;
list_for_each_entry(stt, &kvm->arch.spapr_tce_tables, list) {
if (stt->liobn == args->liobn)
return -EBUSY;
}
npages = kvmppc_stt_npages(args->window_size);
stt = kzalloc(sizeof(*stt) + npages * sizeof(struct page *),
GFP_KERNEL);
if (!stt)
goto fail;
stt->liobn = args->liobn;
stt->window_size = args->window_size;
stt->kvm = kvm;
for (i = 0; i < npages; i++) {
stt->pages[i] = alloc_page(GFP_KERNEL | __GFP_ZERO);
if (!stt->pages[i])
goto fail;
}
kvm_get_kvm(kvm);
mutex_lock(&kvm->lock);
list_add(&stt->list, &kvm->arch.spapr_tce_tables);
mutex_unlock(&kvm->lock);
return anon_inode_getfd("kvm-spapr-tce", &kvm_spapr_tce_fops,
stt, O_RDWR | O_CLOEXEC);
fail:
if (stt) {
for (i = 0; i < npages; i++)
if (stt->pages[i])
__free_page(stt->pages[i]);
kfree(stt);
}
return ret;
}
