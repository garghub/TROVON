static unsigned long kvmppc_tce_pages(unsigned long iommu_pages)
{
return ALIGN(iommu_pages * sizeof(u64), PAGE_SIZE) / PAGE_SIZE;
}
static unsigned long kvmppc_stt_pages(unsigned long tce_pages)
{
unsigned long stt_bytes = sizeof(struct kvmppc_spapr_tce_table) +
(tce_pages * sizeof(struct page *));
return tce_pages + ALIGN(stt_bytes, PAGE_SIZE) / PAGE_SIZE;
}
static long kvmppc_account_memlimit(unsigned long stt_pages, bool inc)
{
long ret = 0;
if (!current || !current->mm)
return ret;
down_write(&current->mm->mmap_sem);
if (inc) {
unsigned long locked, lock_limit;
locked = current->mm->locked_vm + stt_pages;
lock_limit = rlimit(RLIMIT_MEMLOCK) >> PAGE_SHIFT;
if (locked > lock_limit && !capable(CAP_IPC_LOCK))
ret = -ENOMEM;
else
current->mm->locked_vm += stt_pages;
} else {
if (WARN_ON_ONCE(stt_pages > current->mm->locked_vm))
stt_pages = current->mm->locked_vm;
current->mm->locked_vm -= stt_pages;
}
pr_debug("[%d] RLIMIT_MEMLOCK KVM %c%ld %ld/%ld%s\n", current->pid,
inc ? '+' : '-',
stt_pages << PAGE_SHIFT,
current->mm->locked_vm << PAGE_SHIFT,
rlimit(RLIMIT_MEMLOCK),
ret ? " - exceeded" : "");
up_write(&current->mm->mmap_sem);
return ret;
}
static void kvm_spapr_tce_iommu_table_free(struct rcu_head *head)
{
struct kvmppc_spapr_tce_iommu_table *stit = container_of(head,
struct kvmppc_spapr_tce_iommu_table, rcu);
iommu_tce_table_put(stit->tbl);
kfree(stit);
}
static void kvm_spapr_tce_liobn_put(struct kref *kref)
{
struct kvmppc_spapr_tce_iommu_table *stit = container_of(kref,
struct kvmppc_spapr_tce_iommu_table, kref);
list_del_rcu(&stit->next);
call_rcu(&stit->rcu, kvm_spapr_tce_iommu_table_free);
}
extern void kvm_spapr_tce_release_iommu_group(struct kvm *kvm,
struct iommu_group *grp)
{
int i;
struct kvmppc_spapr_tce_table *stt;
struct kvmppc_spapr_tce_iommu_table *stit, *tmp;
struct iommu_table_group *table_group = NULL;
list_for_each_entry_rcu(stt, &kvm->arch.spapr_tce_tables, list) {
table_group = iommu_group_get_iommudata(grp);
if (WARN_ON(!table_group))
continue;
list_for_each_entry_safe(stit, tmp, &stt->iommu_tables, next) {
for (i = 0; i < IOMMU_TABLE_GROUP_MAX_TABLES; ++i) {
if (table_group->tables[i] != stit->tbl)
continue;
kref_put(&stit->kref, kvm_spapr_tce_liobn_put);
return;
}
}
}
}
extern long kvm_spapr_tce_attach_iommu_group(struct kvm *kvm, int tablefd,
struct iommu_group *grp)
{
struct kvmppc_spapr_tce_table *stt = NULL;
bool found = false;
struct iommu_table *tbl = NULL;
struct iommu_table_group *table_group;
long i;
struct kvmppc_spapr_tce_iommu_table *stit;
struct fd f;
f = fdget(tablefd);
if (!f.file)
return -EBADF;
list_for_each_entry_rcu(stt, &kvm->arch.spapr_tce_tables, list) {
if (stt == f.file->private_data) {
found = true;
break;
}
}
fdput(f);
if (!found)
return -EINVAL;
table_group = iommu_group_get_iommudata(grp);
if (WARN_ON(!table_group))
return -EFAULT;
for (i = 0; i < IOMMU_TABLE_GROUP_MAX_TABLES; ++i) {
struct iommu_table *tbltmp = table_group->tables[i];
if (!tbltmp)
continue;
if ((tbltmp->it_page_shift == stt->page_shift) &&
(tbltmp->it_offset == stt->offset) &&
(tbltmp->it_size == stt->size)) {
tbl = iommu_tce_table_get(tbltmp);
break;
}
}
if (!tbl)
return -EINVAL;
list_for_each_entry_rcu(stit, &stt->iommu_tables, next) {
if (tbl != stit->tbl)
continue;
if (!kref_get_unless_zero(&stit->kref)) {
iommu_tce_table_put(tbl);
return -ENOTTY;
}
return 0;
}
stit = kzalloc(sizeof(*stit), GFP_KERNEL);
if (!stit) {
iommu_tce_table_put(tbl);
return -ENOMEM;
}
stit->tbl = tbl;
kref_init(&stit->kref);
list_add_rcu(&stit->next, &stt->iommu_tables);
return 0;
}
static void release_spapr_tce_table(struct rcu_head *head)
{
struct kvmppc_spapr_tce_table *stt = container_of(head,
struct kvmppc_spapr_tce_table, rcu);
unsigned long i, npages = kvmppc_tce_pages(stt->size);
for (i = 0; i < npages; i++)
__free_page(stt->pages[i]);
kfree(stt);
}
static int kvm_spapr_tce_fault(struct vm_fault *vmf)
{
struct kvmppc_spapr_tce_table *stt = vmf->vma->vm_file->private_data;
struct page *page;
if (vmf->pgoff >= kvmppc_tce_pages(stt->size))
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
struct kvmppc_spapr_tce_iommu_table *stit, *tmp;
list_del_rcu(&stt->list);
list_for_each_entry_safe(stit, tmp, &stt->iommu_tables, next) {
WARN_ON(!kref_read(&stit->kref));
while (1) {
if (kref_put(&stit->kref, kvm_spapr_tce_liobn_put))
break;
}
}
kvm_put_kvm(stt->kvm);
kvmppc_account_memlimit(
kvmppc_stt_pages(kvmppc_tce_pages(stt->size)), false);
call_rcu(&stt->rcu, release_spapr_tce_table);
return 0;
}
long kvm_vm_ioctl_create_spapr_tce(struct kvm *kvm,
struct kvm_create_spapr_tce_64 *args)
{
struct kvmppc_spapr_tce_table *stt = NULL;
struct kvmppc_spapr_tce_table *siter;
unsigned long npages, size;
int ret = -ENOMEM;
int i;
int fd = -1;
if (!args->size)
return -EINVAL;
size = _ALIGN_UP(args->size, PAGE_SIZE >> 3);
npages = kvmppc_tce_pages(size);
ret = kvmppc_account_memlimit(kvmppc_stt_pages(npages), true);
if (ret)
return ret;
ret = -ENOMEM;
stt = kzalloc(sizeof(*stt) + npages * sizeof(struct page *),
GFP_KERNEL);
if (!stt)
goto fail_acct;
stt->liobn = args->liobn;
stt->page_shift = args->page_shift;
stt->offset = args->offset;
stt->size = size;
stt->kvm = kvm;
INIT_LIST_HEAD_RCU(&stt->iommu_tables);
for (i = 0; i < npages; i++) {
stt->pages[i] = alloc_page(GFP_KERNEL | __GFP_ZERO);
if (!stt->pages[i])
goto fail;
}
ret = fd = anon_inode_getfd("kvm-spapr-tce", &kvm_spapr_tce_fops,
stt, O_RDWR | O_CLOEXEC);
if (ret < 0)
goto fail;
mutex_lock(&kvm->lock);
ret = 0;
list_for_each_entry(siter, &kvm->arch.spapr_tce_tables, list) {
if (siter->liobn == args->liobn) {
ret = -EBUSY;
break;
}
}
if (!ret) {
list_add_rcu(&stt->list, &kvm->arch.spapr_tce_tables);
kvm_get_kvm(kvm);
}
mutex_unlock(&kvm->lock);
if (!ret)
return fd;
put_unused_fd(fd);
fail:
for (i = 0; i < npages; i++)
if (stt->pages[i])
__free_page(stt->pages[i]);
kfree(stt);
fail_acct:
kvmppc_account_memlimit(kvmppc_stt_pages(npages), false);
return ret;
}
static void kvmppc_clear_tce(struct iommu_table *tbl, unsigned long entry)
{
unsigned long hpa = 0;
enum dma_data_direction dir = DMA_NONE;
iommu_tce_xchg(tbl, entry, &hpa, &dir);
}
static long kvmppc_tce_iommu_mapped_dec(struct kvm *kvm,
struct iommu_table *tbl, unsigned long entry)
{
struct mm_iommu_table_group_mem_t *mem = NULL;
const unsigned long pgsize = 1ULL << tbl->it_page_shift;
unsigned long *pua = IOMMU_TABLE_USERSPACE_ENTRY(tbl, entry);
if (!pua)
return H_TOO_HARD;
mem = mm_iommu_lookup(kvm->mm, *pua, pgsize);
if (!mem)
return H_TOO_HARD;
mm_iommu_mapped_dec(mem);
*pua = 0;
return H_SUCCESS;
}
static long kvmppc_tce_iommu_unmap(struct kvm *kvm,
struct iommu_table *tbl, unsigned long entry)
{
enum dma_data_direction dir = DMA_NONE;
unsigned long hpa = 0;
long ret;
if (WARN_ON_ONCE(iommu_tce_xchg(tbl, entry, &hpa, &dir)))
return H_HARDWARE;
if (dir == DMA_NONE)
return H_SUCCESS;
ret = kvmppc_tce_iommu_mapped_dec(kvm, tbl, entry);
if (ret != H_SUCCESS)
iommu_tce_xchg(tbl, entry, &hpa, &dir);
return ret;
}
long kvmppc_tce_iommu_map(struct kvm *kvm, struct iommu_table *tbl,
unsigned long entry, unsigned long ua,
enum dma_data_direction dir)
{
long ret;
unsigned long hpa, *pua = IOMMU_TABLE_USERSPACE_ENTRY(tbl, entry);
struct mm_iommu_table_group_mem_t *mem;
if (!pua)
return H_TOO_HARD;
mem = mm_iommu_lookup(kvm->mm, ua, 1ULL << tbl->it_page_shift);
if (!mem)
return H_TOO_HARD;
if (WARN_ON_ONCE(mm_iommu_ua_to_hpa(mem, ua, &hpa)))
return H_HARDWARE;
if (mm_iommu_mapped_inc(mem))
return H_CLOSED;
ret = iommu_tce_xchg(tbl, entry, &hpa, &dir);
if (WARN_ON_ONCE(ret)) {
mm_iommu_mapped_dec(mem);
return H_HARDWARE;
}
if (dir != DMA_NONE)
kvmppc_tce_iommu_mapped_dec(kvm, tbl, entry);
*pua = ua;
return 0;
}
long kvmppc_h_put_tce(struct kvm_vcpu *vcpu, unsigned long liobn,
unsigned long ioba, unsigned long tce)
{
struct kvmppc_spapr_tce_table *stt;
long ret, idx;
struct kvmppc_spapr_tce_iommu_table *stit;
unsigned long entry, ua = 0;
enum dma_data_direction dir;
stt = kvmppc_find_table(vcpu->kvm, liobn);
if (!stt)
return H_TOO_HARD;
ret = kvmppc_ioba_validate(stt, ioba, 1);
if (ret != H_SUCCESS)
return ret;
ret = kvmppc_tce_validate(stt, tce);
if (ret != H_SUCCESS)
return ret;
dir = iommu_tce_direction(tce);
if ((dir != DMA_NONE) && kvmppc_gpa_to_ua(vcpu->kvm,
tce & ~(TCE_PCI_READ | TCE_PCI_WRITE), &ua, NULL))
return H_PARAMETER;
entry = ioba >> stt->page_shift;
list_for_each_entry_lockless(stit, &stt->iommu_tables, next) {
if (dir == DMA_NONE) {
ret = kvmppc_tce_iommu_unmap(vcpu->kvm,
stit->tbl, entry);
} else {
idx = srcu_read_lock(&vcpu->kvm->srcu);
ret = kvmppc_tce_iommu_map(vcpu->kvm, stit->tbl,
entry, ua, dir);
srcu_read_unlock(&vcpu->kvm->srcu, idx);
}
if (ret == H_SUCCESS)
continue;
if (ret == H_TOO_HARD)
return ret;
WARN_ON_ONCE(1);
kvmppc_clear_tce(stit->tbl, entry);
}
kvmppc_tce_put(stt, entry, tce);
return H_SUCCESS;
}
long kvmppc_h_put_tce_indirect(struct kvm_vcpu *vcpu,
unsigned long liobn, unsigned long ioba,
unsigned long tce_list, unsigned long npages)
{
struct kvmppc_spapr_tce_table *stt;
long i, ret = H_SUCCESS, idx;
unsigned long entry, ua = 0;
u64 __user *tces;
u64 tce;
struct kvmppc_spapr_tce_iommu_table *stit;
stt = kvmppc_find_table(vcpu->kvm, liobn);
if (!stt)
return H_TOO_HARD;
entry = ioba >> stt->page_shift;
if (npages > 512)
return H_PARAMETER;
if (tce_list & (SZ_4K - 1))
return H_PARAMETER;
ret = kvmppc_ioba_validate(stt, ioba, npages);
if (ret != H_SUCCESS)
return ret;
idx = srcu_read_lock(&vcpu->kvm->srcu);
if (kvmppc_gpa_to_ua(vcpu->kvm, tce_list, &ua, NULL)) {
ret = H_TOO_HARD;
goto unlock_exit;
}
tces = (u64 __user *) ua;
for (i = 0; i < npages; ++i) {
if (get_user(tce, tces + i)) {
ret = H_TOO_HARD;
goto unlock_exit;
}
tce = be64_to_cpu(tce);
ret = kvmppc_tce_validate(stt, tce);
if (ret != H_SUCCESS)
goto unlock_exit;
if (kvmppc_gpa_to_ua(vcpu->kvm,
tce & ~(TCE_PCI_READ | TCE_PCI_WRITE),
&ua, NULL))
return H_PARAMETER;
list_for_each_entry_lockless(stit, &stt->iommu_tables, next) {
ret = kvmppc_tce_iommu_map(vcpu->kvm,
stit->tbl, entry + i, ua,
iommu_tce_direction(tce));
if (ret == H_SUCCESS)
continue;
if (ret == H_TOO_HARD)
goto unlock_exit;
WARN_ON_ONCE(1);
kvmppc_clear_tce(stit->tbl, entry);
}
kvmppc_tce_put(stt, entry + i, tce);
}
unlock_exit:
srcu_read_unlock(&vcpu->kvm->srcu, idx);
return ret;
}
long kvmppc_h_stuff_tce(struct kvm_vcpu *vcpu,
unsigned long liobn, unsigned long ioba,
unsigned long tce_value, unsigned long npages)
{
struct kvmppc_spapr_tce_table *stt;
long i, ret;
struct kvmppc_spapr_tce_iommu_table *stit;
stt = kvmppc_find_table(vcpu->kvm, liobn);
if (!stt)
return H_TOO_HARD;
ret = kvmppc_ioba_validate(stt, ioba, npages);
if (ret != H_SUCCESS)
return ret;
if (tce_value & (TCE_PCI_WRITE | TCE_PCI_READ))
return H_PARAMETER;
list_for_each_entry_lockless(stit, &stt->iommu_tables, next) {
unsigned long entry = ioba >> stit->tbl->it_page_shift;
for (i = 0; i < npages; ++i) {
ret = kvmppc_tce_iommu_unmap(vcpu->kvm,
stit->tbl, entry + i);
if (ret == H_SUCCESS)
continue;
if (ret == H_TOO_HARD)
return ret;
WARN_ON_ONCE(1);
kvmppc_clear_tce(stit->tbl, entry);
}
}
for (i = 0; i < npages; ++i, ioba += (1ULL << stt->page_shift))
kvmppc_tce_put(stt, ioba >> stt->page_shift, tce_value);
return H_SUCCESS;
}
