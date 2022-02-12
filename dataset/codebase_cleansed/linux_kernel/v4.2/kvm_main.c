bool kvm_is_reserved_pfn(pfn_t pfn)
{
if (pfn_valid(pfn))
return PageReserved(pfn_to_page(pfn));
return true;
}
int vcpu_load(struct kvm_vcpu *vcpu)
{
int cpu;
if (mutex_lock_killable(&vcpu->mutex))
return -EINTR;
cpu = get_cpu();
preempt_notifier_register(&vcpu->preempt_notifier);
kvm_arch_vcpu_load(vcpu, cpu);
put_cpu();
return 0;
}
void vcpu_put(struct kvm_vcpu *vcpu)
{
preempt_disable();
kvm_arch_vcpu_put(vcpu);
preempt_notifier_unregister(&vcpu->preempt_notifier);
preempt_enable();
mutex_unlock(&vcpu->mutex);
}
static void ack_flush(void *_completed)
{
}
bool kvm_make_all_cpus_request(struct kvm *kvm, unsigned int req)
{
int i, cpu, me;
cpumask_var_t cpus;
bool called = true;
struct kvm_vcpu *vcpu;
zalloc_cpumask_var(&cpus, GFP_ATOMIC);
me = get_cpu();
kvm_for_each_vcpu(i, vcpu, kvm) {
kvm_make_request(req, vcpu);
cpu = vcpu->cpu;
smp_mb();
if (cpus != NULL && cpu != -1 && cpu != me &&
kvm_vcpu_exiting_guest_mode(vcpu) != OUTSIDE_GUEST_MODE)
cpumask_set_cpu(cpu, cpus);
}
if (unlikely(cpus == NULL))
smp_call_function_many(cpu_online_mask, ack_flush, NULL, 1);
else if (!cpumask_empty(cpus))
smp_call_function_many(cpus, ack_flush, NULL, 1);
else
called = false;
put_cpu();
free_cpumask_var(cpus);
return called;
}
void kvm_flush_remote_tlbs(struct kvm *kvm)
{
long dirty_count = kvm->tlbs_dirty;
smp_mb();
if (kvm_make_all_cpus_request(kvm, KVM_REQ_TLB_FLUSH))
++kvm->stat.remote_tlb_flush;
cmpxchg(&kvm->tlbs_dirty, dirty_count, 0);
}
void kvm_reload_remote_mmus(struct kvm *kvm)
{
kvm_make_all_cpus_request(kvm, KVM_REQ_MMU_RELOAD);
}
void kvm_make_mclock_inprogress_request(struct kvm *kvm)
{
kvm_make_all_cpus_request(kvm, KVM_REQ_MCLOCK_INPROGRESS);
}
void kvm_make_scan_ioapic_request(struct kvm *kvm)
{
kvm_make_all_cpus_request(kvm, KVM_REQ_SCAN_IOAPIC);
}
int kvm_vcpu_init(struct kvm_vcpu *vcpu, struct kvm *kvm, unsigned id)
{
struct page *page;
int r;
mutex_init(&vcpu->mutex);
vcpu->cpu = -1;
vcpu->kvm = kvm;
vcpu->vcpu_id = id;
vcpu->pid = NULL;
init_waitqueue_head(&vcpu->wq);
kvm_async_pf_vcpu_init(vcpu);
page = alloc_page(GFP_KERNEL | __GFP_ZERO);
if (!page) {
r = -ENOMEM;
goto fail;
}
vcpu->run = page_address(page);
kvm_vcpu_set_in_spin_loop(vcpu, false);
kvm_vcpu_set_dy_eligible(vcpu, false);
vcpu->preempted = false;
r = kvm_arch_vcpu_init(vcpu);
if (r < 0)
goto fail_free_run;
return 0;
fail_free_run:
free_page((unsigned long)vcpu->run);
fail:
return r;
}
void kvm_vcpu_uninit(struct kvm_vcpu *vcpu)
{
put_pid(vcpu->pid);
kvm_arch_vcpu_uninit(vcpu);
free_page((unsigned long)vcpu->run);
}
static inline struct kvm *mmu_notifier_to_kvm(struct mmu_notifier *mn)
{
return container_of(mn, struct kvm, mmu_notifier);
}
static void kvm_mmu_notifier_invalidate_page(struct mmu_notifier *mn,
struct mm_struct *mm,
unsigned long address)
{
struct kvm *kvm = mmu_notifier_to_kvm(mn);
int need_tlb_flush, idx;
idx = srcu_read_lock(&kvm->srcu);
spin_lock(&kvm->mmu_lock);
kvm->mmu_notifier_seq++;
need_tlb_flush = kvm_unmap_hva(kvm, address) | kvm->tlbs_dirty;
if (need_tlb_flush)
kvm_flush_remote_tlbs(kvm);
spin_unlock(&kvm->mmu_lock);
kvm_arch_mmu_notifier_invalidate_page(kvm, address);
srcu_read_unlock(&kvm->srcu, idx);
}
static void kvm_mmu_notifier_change_pte(struct mmu_notifier *mn,
struct mm_struct *mm,
unsigned long address,
pte_t pte)
{
struct kvm *kvm = mmu_notifier_to_kvm(mn);
int idx;
idx = srcu_read_lock(&kvm->srcu);
spin_lock(&kvm->mmu_lock);
kvm->mmu_notifier_seq++;
kvm_set_spte_hva(kvm, address, pte);
spin_unlock(&kvm->mmu_lock);
srcu_read_unlock(&kvm->srcu, idx);
}
static void kvm_mmu_notifier_invalidate_range_start(struct mmu_notifier *mn,
struct mm_struct *mm,
unsigned long start,
unsigned long end)
{
struct kvm *kvm = mmu_notifier_to_kvm(mn);
int need_tlb_flush = 0, idx;
idx = srcu_read_lock(&kvm->srcu);
spin_lock(&kvm->mmu_lock);
kvm->mmu_notifier_count++;
need_tlb_flush = kvm_unmap_hva_range(kvm, start, end);
need_tlb_flush |= kvm->tlbs_dirty;
if (need_tlb_flush)
kvm_flush_remote_tlbs(kvm);
spin_unlock(&kvm->mmu_lock);
srcu_read_unlock(&kvm->srcu, idx);
}
static void kvm_mmu_notifier_invalidate_range_end(struct mmu_notifier *mn,
struct mm_struct *mm,
unsigned long start,
unsigned long end)
{
struct kvm *kvm = mmu_notifier_to_kvm(mn);
spin_lock(&kvm->mmu_lock);
kvm->mmu_notifier_seq++;
smp_wmb();
kvm->mmu_notifier_count--;
spin_unlock(&kvm->mmu_lock);
BUG_ON(kvm->mmu_notifier_count < 0);
}
static int kvm_mmu_notifier_clear_flush_young(struct mmu_notifier *mn,
struct mm_struct *mm,
unsigned long start,
unsigned long end)
{
struct kvm *kvm = mmu_notifier_to_kvm(mn);
int young, idx;
idx = srcu_read_lock(&kvm->srcu);
spin_lock(&kvm->mmu_lock);
young = kvm_age_hva(kvm, start, end);
if (young)
kvm_flush_remote_tlbs(kvm);
spin_unlock(&kvm->mmu_lock);
srcu_read_unlock(&kvm->srcu, idx);
return young;
}
static int kvm_mmu_notifier_test_young(struct mmu_notifier *mn,
struct mm_struct *mm,
unsigned long address)
{
struct kvm *kvm = mmu_notifier_to_kvm(mn);
int young, idx;
idx = srcu_read_lock(&kvm->srcu);
spin_lock(&kvm->mmu_lock);
young = kvm_test_age_hva(kvm, address);
spin_unlock(&kvm->mmu_lock);
srcu_read_unlock(&kvm->srcu, idx);
return young;
}
static void kvm_mmu_notifier_release(struct mmu_notifier *mn,
struct mm_struct *mm)
{
struct kvm *kvm = mmu_notifier_to_kvm(mn);
int idx;
idx = srcu_read_lock(&kvm->srcu);
kvm_arch_flush_shadow_all(kvm);
srcu_read_unlock(&kvm->srcu, idx);
}
static int kvm_init_mmu_notifier(struct kvm *kvm)
{
kvm->mmu_notifier.ops = &kvm_mmu_notifier_ops;
return mmu_notifier_register(&kvm->mmu_notifier, current->mm);
}
static int kvm_init_mmu_notifier(struct kvm *kvm)
{
return 0;
}
static struct kvm_memslots *kvm_alloc_memslots(void)
{
int i;
struct kvm_memslots *slots;
slots = kvm_kvzalloc(sizeof(struct kvm_memslots));
if (!slots)
return NULL;
slots->generation = -150;
for (i = 0; i < KVM_MEM_SLOTS_NUM; i++)
slots->id_to_index[i] = slots->memslots[i].id = i;
return slots;
}
static void kvm_destroy_dirty_bitmap(struct kvm_memory_slot *memslot)
{
if (!memslot->dirty_bitmap)
return;
kvfree(memslot->dirty_bitmap);
memslot->dirty_bitmap = NULL;
}
static void kvm_free_memslot(struct kvm *kvm, struct kvm_memory_slot *free,
struct kvm_memory_slot *dont)
{
if (!dont || free->dirty_bitmap != dont->dirty_bitmap)
kvm_destroy_dirty_bitmap(free);
kvm_arch_free_memslot(kvm, free, dont);
free->npages = 0;
}
static void kvm_free_memslots(struct kvm *kvm, struct kvm_memslots *slots)
{
struct kvm_memory_slot *memslot;
if (!slots)
return;
kvm_for_each_memslot(memslot, slots)
kvm_free_memslot(kvm, memslot, NULL);
kvfree(slots);
}
static struct kvm *kvm_create_vm(unsigned long type)
{
int r, i;
struct kvm *kvm = kvm_arch_alloc_vm();
if (!kvm)
return ERR_PTR(-ENOMEM);
r = kvm_arch_init_vm(kvm, type);
if (r)
goto out_err_no_disable;
r = hardware_enable_all();
if (r)
goto out_err_no_disable;
#ifdef CONFIG_HAVE_KVM_IRQFD
INIT_HLIST_HEAD(&kvm->irq_ack_notifier_list);
#endif
BUILD_BUG_ON(KVM_MEM_SLOTS_NUM > SHRT_MAX);
r = -ENOMEM;
for (i = 0; i < KVM_ADDRESS_SPACE_NUM; i++) {
kvm->memslots[i] = kvm_alloc_memslots();
if (!kvm->memslots[i])
goto out_err_no_srcu;
}
if (init_srcu_struct(&kvm->srcu))
goto out_err_no_srcu;
if (init_srcu_struct(&kvm->irq_srcu))
goto out_err_no_irq_srcu;
for (i = 0; i < KVM_NR_BUSES; i++) {
kvm->buses[i] = kzalloc(sizeof(struct kvm_io_bus),
GFP_KERNEL);
if (!kvm->buses[i])
goto out_err;
}
spin_lock_init(&kvm->mmu_lock);
kvm->mm = current->mm;
atomic_inc(&kvm->mm->mm_count);
kvm_eventfd_init(kvm);
mutex_init(&kvm->lock);
mutex_init(&kvm->irq_lock);
mutex_init(&kvm->slots_lock);
atomic_set(&kvm->users_count, 1);
INIT_LIST_HEAD(&kvm->devices);
r = kvm_init_mmu_notifier(kvm);
if (r)
goto out_err;
spin_lock(&kvm_lock);
list_add(&kvm->vm_list, &vm_list);
spin_unlock(&kvm_lock);
preempt_notifier_inc();
return kvm;
out_err:
cleanup_srcu_struct(&kvm->irq_srcu);
out_err_no_irq_srcu:
cleanup_srcu_struct(&kvm->srcu);
out_err_no_srcu:
hardware_disable_all();
out_err_no_disable:
for (i = 0; i < KVM_NR_BUSES; i++)
kfree(kvm->buses[i]);
for (i = 0; i < KVM_ADDRESS_SPACE_NUM; i++)
kvm_free_memslots(kvm, kvm->memslots[i]);
kvm_arch_free_vm(kvm);
return ERR_PTR(r);
}
void *kvm_kvzalloc(unsigned long size)
{
if (size > PAGE_SIZE)
return vzalloc(size);
else
return kzalloc(size, GFP_KERNEL);
}
static void kvm_destroy_devices(struct kvm *kvm)
{
struct list_head *node, *tmp;
list_for_each_safe(node, tmp, &kvm->devices) {
struct kvm_device *dev =
list_entry(node, struct kvm_device, vm_node);
list_del(node);
dev->ops->destroy(dev);
}
}
static void kvm_destroy_vm(struct kvm *kvm)
{
int i;
struct mm_struct *mm = kvm->mm;
kvm_arch_sync_events(kvm);
spin_lock(&kvm_lock);
list_del(&kvm->vm_list);
spin_unlock(&kvm_lock);
kvm_free_irq_routing(kvm);
for (i = 0; i < KVM_NR_BUSES; i++)
kvm_io_bus_destroy(kvm->buses[i]);
kvm_coalesced_mmio_free(kvm);
#if defined(CONFIG_MMU_NOTIFIER) && defined(KVM_ARCH_WANT_MMU_NOTIFIER)
mmu_notifier_unregister(&kvm->mmu_notifier, kvm->mm);
#else
kvm_arch_flush_shadow_all(kvm);
#endif
kvm_arch_destroy_vm(kvm);
kvm_destroy_devices(kvm);
for (i = 0; i < KVM_ADDRESS_SPACE_NUM; i++)
kvm_free_memslots(kvm, kvm->memslots[i]);
cleanup_srcu_struct(&kvm->irq_srcu);
cleanup_srcu_struct(&kvm->srcu);
kvm_arch_free_vm(kvm);
preempt_notifier_dec();
hardware_disable_all();
mmdrop(mm);
}
void kvm_get_kvm(struct kvm *kvm)
{
atomic_inc(&kvm->users_count);
}
void kvm_put_kvm(struct kvm *kvm)
{
if (atomic_dec_and_test(&kvm->users_count))
kvm_destroy_vm(kvm);
}
static int kvm_vm_release(struct inode *inode, struct file *filp)
{
struct kvm *kvm = filp->private_data;
kvm_irqfd_release(kvm);
kvm_put_kvm(kvm);
return 0;
}
static int kvm_create_dirty_bitmap(struct kvm_memory_slot *memslot)
{
unsigned long dirty_bytes = 2 * kvm_dirty_bitmap_bytes(memslot);
memslot->dirty_bitmap = kvm_kvzalloc(dirty_bytes);
if (!memslot->dirty_bitmap)
return -ENOMEM;
return 0;
}
static void update_memslots(struct kvm_memslots *slots,
struct kvm_memory_slot *new)
{
int id = new->id;
int i = slots->id_to_index[id];
struct kvm_memory_slot *mslots = slots->memslots;
WARN_ON(mslots[i].id != id);
if (!new->npages) {
WARN_ON(!mslots[i].npages);
if (mslots[i].npages)
slots->used_slots--;
} else {
if (!mslots[i].npages)
slots->used_slots++;
}
while (i < KVM_MEM_SLOTS_NUM - 1 &&
new->base_gfn <= mslots[i + 1].base_gfn) {
if (!mslots[i + 1].npages)
break;
mslots[i] = mslots[i + 1];
slots->id_to_index[mslots[i].id] = i;
i++;
}
if (new->npages) {
while (i > 0 &&
new->base_gfn >= mslots[i - 1].base_gfn) {
mslots[i] = mslots[i - 1];
slots->id_to_index[mslots[i].id] = i;
i--;
}
} else
WARN_ON_ONCE(i != slots->used_slots);
mslots[i] = *new;
slots->id_to_index[mslots[i].id] = i;
}
static int check_memory_region_flags(const struct kvm_userspace_memory_region *mem)
{
u32 valid_flags = KVM_MEM_LOG_DIRTY_PAGES;
#ifdef __KVM_HAVE_READONLY_MEM
valid_flags |= KVM_MEM_READONLY;
#endif
if (mem->flags & ~valid_flags)
return -EINVAL;
return 0;
}
static struct kvm_memslots *install_new_memslots(struct kvm *kvm,
int as_id, struct kvm_memslots *slots)
{
struct kvm_memslots *old_memslots = __kvm_memslots(kvm, as_id);
WARN_ON(old_memslots->generation & 1);
slots->generation = old_memslots->generation + 1;
rcu_assign_pointer(kvm->memslots[as_id], slots);
synchronize_srcu_expedited(&kvm->srcu);
slots->generation++;
kvm_arch_memslots_updated(kvm, slots);
return old_memslots;
}
int __kvm_set_memory_region(struct kvm *kvm,
const struct kvm_userspace_memory_region *mem)
{
int r;
gfn_t base_gfn;
unsigned long npages;
struct kvm_memory_slot *slot;
struct kvm_memory_slot old, new;
struct kvm_memslots *slots = NULL, *old_memslots;
int as_id, id;
enum kvm_mr_change change;
r = check_memory_region_flags(mem);
if (r)
goto out;
r = -EINVAL;
as_id = mem->slot >> 16;
id = (u16)mem->slot;
if (mem->memory_size & (PAGE_SIZE - 1))
goto out;
if (mem->guest_phys_addr & (PAGE_SIZE - 1))
goto out;
if ((id < KVM_USER_MEM_SLOTS) &&
((mem->userspace_addr & (PAGE_SIZE - 1)) ||
!access_ok(VERIFY_WRITE,
(void __user *)(unsigned long)mem->userspace_addr,
mem->memory_size)))
goto out;
if (as_id >= KVM_ADDRESS_SPACE_NUM || id >= KVM_MEM_SLOTS_NUM)
goto out;
if (mem->guest_phys_addr + mem->memory_size < mem->guest_phys_addr)
goto out;
slot = id_to_memslot(__kvm_memslots(kvm, as_id), id);
base_gfn = mem->guest_phys_addr >> PAGE_SHIFT;
npages = mem->memory_size >> PAGE_SHIFT;
if (npages > KVM_MEM_MAX_NR_PAGES)
goto out;
new = old = *slot;
new.id = id;
new.base_gfn = base_gfn;
new.npages = npages;
new.flags = mem->flags;
if (npages) {
if (!old.npages)
change = KVM_MR_CREATE;
else {
if ((mem->userspace_addr != old.userspace_addr) ||
(npages != old.npages) ||
((new.flags ^ old.flags) & KVM_MEM_READONLY))
goto out;
if (base_gfn != old.base_gfn)
change = KVM_MR_MOVE;
else if (new.flags != old.flags)
change = KVM_MR_FLAGS_ONLY;
else {
r = 0;
goto out;
}
}
} else {
if (!old.npages)
goto out;
change = KVM_MR_DELETE;
new.base_gfn = 0;
new.flags = 0;
}
if ((change == KVM_MR_CREATE) || (change == KVM_MR_MOVE)) {
r = -EEXIST;
kvm_for_each_memslot(slot, __kvm_memslots(kvm, as_id)) {
if ((slot->id >= KVM_USER_MEM_SLOTS) ||
(slot->id == id))
continue;
if (!((base_gfn + npages <= slot->base_gfn) ||
(base_gfn >= slot->base_gfn + slot->npages)))
goto out;
}
}
if (!(new.flags & KVM_MEM_LOG_DIRTY_PAGES))
new.dirty_bitmap = NULL;
r = -ENOMEM;
if (change == KVM_MR_CREATE) {
new.userspace_addr = mem->userspace_addr;
if (kvm_arch_create_memslot(kvm, &new, npages))
goto out_free;
}
if ((new.flags & KVM_MEM_LOG_DIRTY_PAGES) && !new.dirty_bitmap) {
if (kvm_create_dirty_bitmap(&new) < 0)
goto out_free;
}
slots = kvm_kvzalloc(sizeof(struct kvm_memslots));
if (!slots)
goto out_free;
memcpy(slots, __kvm_memslots(kvm, as_id), sizeof(struct kvm_memslots));
if ((change == KVM_MR_DELETE) || (change == KVM_MR_MOVE)) {
slot = id_to_memslot(slots, id);
slot->flags |= KVM_MEMSLOT_INVALID;
old_memslots = install_new_memslots(kvm, as_id, slots);
kvm_iommu_unmap_pages(kvm, &old);
kvm_arch_flush_shadow_memslot(kvm, slot);
slots = old_memslots;
}
r = kvm_arch_prepare_memory_region(kvm, &new, mem, change);
if (r)
goto out_slots;
if (change == KVM_MR_DELETE) {
new.dirty_bitmap = NULL;
memset(&new.arch, 0, sizeof(new.arch));
}
update_memslots(slots, &new);
old_memslots = install_new_memslots(kvm, as_id, slots);
kvm_arch_commit_memory_region(kvm, mem, &old, &new, change);
kvm_free_memslot(kvm, &old, &new);
kvfree(old_memslots);
if ((change == KVM_MR_CREATE) || (change == KVM_MR_MOVE)) {
r = kvm_iommu_map_pages(kvm, &new);
return r;
}
return 0;
out_slots:
kvfree(slots);
out_free:
kvm_free_memslot(kvm, &new, &old);
out:
return r;
}
int kvm_set_memory_region(struct kvm *kvm,
const struct kvm_userspace_memory_region *mem)
{
int r;
mutex_lock(&kvm->slots_lock);
r = __kvm_set_memory_region(kvm, mem);
mutex_unlock(&kvm->slots_lock);
return r;
}
static int kvm_vm_ioctl_set_memory_region(struct kvm *kvm,
struct kvm_userspace_memory_region *mem)
{
if ((u16)mem->slot >= KVM_USER_MEM_SLOTS)
return -EINVAL;
return kvm_set_memory_region(kvm, mem);
}
int kvm_get_dirty_log(struct kvm *kvm,
struct kvm_dirty_log *log, int *is_dirty)
{
struct kvm_memslots *slots;
struct kvm_memory_slot *memslot;
int r, i, as_id, id;
unsigned long n;
unsigned long any = 0;
r = -EINVAL;
as_id = log->slot >> 16;
id = (u16)log->slot;
if (as_id >= KVM_ADDRESS_SPACE_NUM || id >= KVM_USER_MEM_SLOTS)
goto out;
slots = __kvm_memslots(kvm, as_id);
memslot = id_to_memslot(slots, id);
r = -ENOENT;
if (!memslot->dirty_bitmap)
goto out;
n = kvm_dirty_bitmap_bytes(memslot);
for (i = 0; !any && i < n/sizeof(long); ++i)
any = memslot->dirty_bitmap[i];
r = -EFAULT;
if (copy_to_user(log->dirty_bitmap, memslot->dirty_bitmap, n))
goto out;
if (any)
*is_dirty = 1;
r = 0;
out:
return r;
}
int kvm_get_dirty_log_protect(struct kvm *kvm,
struct kvm_dirty_log *log, bool *is_dirty)
{
struct kvm_memslots *slots;
struct kvm_memory_slot *memslot;
int r, i, as_id, id;
unsigned long n;
unsigned long *dirty_bitmap;
unsigned long *dirty_bitmap_buffer;
r = -EINVAL;
as_id = log->slot >> 16;
id = (u16)log->slot;
if (as_id >= KVM_ADDRESS_SPACE_NUM || id >= KVM_USER_MEM_SLOTS)
goto out;
slots = __kvm_memslots(kvm, as_id);
memslot = id_to_memslot(slots, id);
dirty_bitmap = memslot->dirty_bitmap;
r = -ENOENT;
if (!dirty_bitmap)
goto out;
n = kvm_dirty_bitmap_bytes(memslot);
dirty_bitmap_buffer = dirty_bitmap + n / sizeof(long);
memset(dirty_bitmap_buffer, 0, n);
spin_lock(&kvm->mmu_lock);
*is_dirty = false;
for (i = 0; i < n / sizeof(long); i++) {
unsigned long mask;
gfn_t offset;
if (!dirty_bitmap[i])
continue;
*is_dirty = true;
mask = xchg(&dirty_bitmap[i], 0);
dirty_bitmap_buffer[i] = mask;
if (mask) {
offset = i * BITS_PER_LONG;
kvm_arch_mmu_enable_log_dirty_pt_masked(kvm, memslot,
offset, mask);
}
}
spin_unlock(&kvm->mmu_lock);
r = -EFAULT;
if (copy_to_user(log->dirty_bitmap, dirty_bitmap_buffer, n))
goto out;
r = 0;
out:
return r;
}
bool kvm_largepages_enabled(void)
{
return largepages_enabled;
}
void kvm_disable_largepages(void)
{
largepages_enabled = false;
}
struct kvm_memory_slot *gfn_to_memslot(struct kvm *kvm, gfn_t gfn)
{
return __gfn_to_memslot(kvm_memslots(kvm), gfn);
}
struct kvm_memory_slot *kvm_vcpu_gfn_to_memslot(struct kvm_vcpu *vcpu, gfn_t gfn)
{
return __gfn_to_memslot(kvm_vcpu_memslots(vcpu), gfn);
}
int kvm_is_visible_gfn(struct kvm *kvm, gfn_t gfn)
{
struct kvm_memory_slot *memslot = gfn_to_memslot(kvm, gfn);
if (!memslot || memslot->id >= KVM_USER_MEM_SLOTS ||
memslot->flags & KVM_MEMSLOT_INVALID)
return 0;
return 1;
}
unsigned long kvm_host_page_size(struct kvm *kvm, gfn_t gfn)
{
struct vm_area_struct *vma;
unsigned long addr, size;
size = PAGE_SIZE;
addr = gfn_to_hva(kvm, gfn);
if (kvm_is_error_hva(addr))
return PAGE_SIZE;
down_read(&current->mm->mmap_sem);
vma = find_vma(current->mm, addr);
if (!vma)
goto out;
size = vma_kernel_pagesize(vma);
out:
up_read(&current->mm->mmap_sem);
return size;
}
static bool memslot_is_readonly(struct kvm_memory_slot *slot)
{
return slot->flags & KVM_MEM_READONLY;
}
static unsigned long __gfn_to_hva_many(struct kvm_memory_slot *slot, gfn_t gfn,
gfn_t *nr_pages, bool write)
{
if (!slot || slot->flags & KVM_MEMSLOT_INVALID)
return KVM_HVA_ERR_BAD;
if (memslot_is_readonly(slot) && write)
return KVM_HVA_ERR_RO_BAD;
if (nr_pages)
*nr_pages = slot->npages - (gfn - slot->base_gfn);
return __gfn_to_hva_memslot(slot, gfn);
}
static unsigned long gfn_to_hva_many(struct kvm_memory_slot *slot, gfn_t gfn,
gfn_t *nr_pages)
{
return __gfn_to_hva_many(slot, gfn, nr_pages, true);
}
unsigned long gfn_to_hva_memslot(struct kvm_memory_slot *slot,
gfn_t gfn)
{
return gfn_to_hva_many(slot, gfn, NULL);
}
unsigned long gfn_to_hva(struct kvm *kvm, gfn_t gfn)
{
return gfn_to_hva_many(gfn_to_memslot(kvm, gfn), gfn, NULL);
}
unsigned long kvm_vcpu_gfn_to_hva(struct kvm_vcpu *vcpu, gfn_t gfn)
{
return gfn_to_hva_many(kvm_vcpu_gfn_to_memslot(vcpu, gfn), gfn, NULL);
}
unsigned long gfn_to_hva_memslot_prot(struct kvm_memory_slot *slot,
gfn_t gfn, bool *writable)
{
unsigned long hva = __gfn_to_hva_many(slot, gfn, NULL, false);
if (!kvm_is_error_hva(hva) && writable)
*writable = !memslot_is_readonly(slot);
return hva;
}
unsigned long gfn_to_hva_prot(struct kvm *kvm, gfn_t gfn, bool *writable)
{
struct kvm_memory_slot *slot = gfn_to_memslot(kvm, gfn);
return gfn_to_hva_memslot_prot(slot, gfn, writable);
}
unsigned long kvm_vcpu_gfn_to_hva_prot(struct kvm_vcpu *vcpu, gfn_t gfn, bool *writable)
{
struct kvm_memory_slot *slot = kvm_vcpu_gfn_to_memslot(vcpu, gfn);
return gfn_to_hva_memslot_prot(slot, gfn, writable);
}
static int get_user_page_nowait(struct task_struct *tsk, struct mm_struct *mm,
unsigned long start, int write, struct page **page)
{
int flags = FOLL_TOUCH | FOLL_NOWAIT | FOLL_HWPOISON | FOLL_GET;
if (write)
flags |= FOLL_WRITE;
return __get_user_pages(tsk, mm, start, 1, flags, page, NULL, NULL);
}
static inline int check_user_page_hwpoison(unsigned long addr)
{
int rc, flags = FOLL_TOUCH | FOLL_HWPOISON | FOLL_WRITE;
rc = __get_user_pages(current, current->mm, addr, 1,
flags, NULL, NULL, NULL);
return rc == -EHWPOISON;
}
static bool hva_to_pfn_fast(unsigned long addr, bool atomic, bool *async,
bool write_fault, bool *writable, pfn_t *pfn)
{
struct page *page[1];
int npages;
if (!(async || atomic))
return false;
if (!(write_fault || writable))
return false;
npages = __get_user_pages_fast(addr, 1, 1, page);
if (npages == 1) {
*pfn = page_to_pfn(page[0]);
if (writable)
*writable = true;
return true;
}
return false;
}
static int hva_to_pfn_slow(unsigned long addr, bool *async, bool write_fault,
bool *writable, pfn_t *pfn)
{
struct page *page[1];
int npages = 0;
might_sleep();
if (writable)
*writable = write_fault;
if (async) {
down_read(&current->mm->mmap_sem);
npages = get_user_page_nowait(current, current->mm,
addr, write_fault, page);
up_read(&current->mm->mmap_sem);
} else
npages = __get_user_pages_unlocked(current, current->mm, addr, 1,
write_fault, 0, page,
FOLL_TOUCH|FOLL_HWPOISON);
if (npages != 1)
return npages;
if (unlikely(!write_fault) && writable) {
struct page *wpage[1];
npages = __get_user_pages_fast(addr, 1, 1, wpage);
if (npages == 1) {
*writable = true;
put_page(page[0]);
page[0] = wpage[0];
}
npages = 1;
}
*pfn = page_to_pfn(page[0]);
return npages;
}
static bool vma_is_valid(struct vm_area_struct *vma, bool write_fault)
{
if (unlikely(!(vma->vm_flags & VM_READ)))
return false;
if (write_fault && (unlikely(!(vma->vm_flags & VM_WRITE))))
return false;
return true;
}
static pfn_t hva_to_pfn(unsigned long addr, bool atomic, bool *async,
bool write_fault, bool *writable)
{
struct vm_area_struct *vma;
pfn_t pfn = 0;
int npages;
BUG_ON(atomic && async);
if (hva_to_pfn_fast(addr, atomic, async, write_fault, writable, &pfn))
return pfn;
if (atomic)
return KVM_PFN_ERR_FAULT;
npages = hva_to_pfn_slow(addr, async, write_fault, writable, &pfn);
if (npages == 1)
return pfn;
down_read(&current->mm->mmap_sem);
if (npages == -EHWPOISON ||
(!async && check_user_page_hwpoison(addr))) {
pfn = KVM_PFN_ERR_HWPOISON;
goto exit;
}
vma = find_vma_intersection(current->mm, addr, addr + 1);
if (vma == NULL)
pfn = KVM_PFN_ERR_FAULT;
else if ((vma->vm_flags & VM_PFNMAP)) {
pfn = ((addr - vma->vm_start) >> PAGE_SHIFT) +
vma->vm_pgoff;
BUG_ON(!kvm_is_reserved_pfn(pfn));
} else {
if (async && vma_is_valid(vma, write_fault))
*async = true;
pfn = KVM_PFN_ERR_FAULT;
}
exit:
up_read(&current->mm->mmap_sem);
return pfn;
}
pfn_t __gfn_to_pfn_memslot(struct kvm_memory_slot *slot, gfn_t gfn, bool atomic,
bool *async, bool write_fault, bool *writable)
{
unsigned long addr = __gfn_to_hva_many(slot, gfn, NULL, write_fault);
if (addr == KVM_HVA_ERR_RO_BAD)
return KVM_PFN_ERR_RO_FAULT;
if (kvm_is_error_hva(addr))
return KVM_PFN_NOSLOT;
if (writable && memslot_is_readonly(slot)) {
*writable = false;
writable = NULL;
}
return hva_to_pfn(addr, atomic, async, write_fault,
writable);
}
pfn_t gfn_to_pfn_prot(struct kvm *kvm, gfn_t gfn, bool write_fault,
bool *writable)
{
return __gfn_to_pfn_memslot(gfn_to_memslot(kvm, gfn), gfn, false, NULL,
write_fault, writable);
}
pfn_t gfn_to_pfn_memslot(struct kvm_memory_slot *slot, gfn_t gfn)
{
return __gfn_to_pfn_memslot(slot, gfn, false, NULL, true, NULL);
}
pfn_t gfn_to_pfn_memslot_atomic(struct kvm_memory_slot *slot, gfn_t gfn)
{
return __gfn_to_pfn_memslot(slot, gfn, true, NULL, true, NULL);
}
pfn_t gfn_to_pfn_atomic(struct kvm *kvm, gfn_t gfn)
{
return gfn_to_pfn_memslot_atomic(gfn_to_memslot(kvm, gfn), gfn);
}
pfn_t kvm_vcpu_gfn_to_pfn_atomic(struct kvm_vcpu *vcpu, gfn_t gfn)
{
return gfn_to_pfn_memslot_atomic(kvm_vcpu_gfn_to_memslot(vcpu, gfn), gfn);
}
pfn_t gfn_to_pfn(struct kvm *kvm, gfn_t gfn)
{
return gfn_to_pfn_memslot(gfn_to_memslot(kvm, gfn), gfn);
}
pfn_t kvm_vcpu_gfn_to_pfn(struct kvm_vcpu *vcpu, gfn_t gfn)
{
return gfn_to_pfn_memslot(kvm_vcpu_gfn_to_memslot(vcpu, gfn), gfn);
}
int gfn_to_page_many_atomic(struct kvm_memory_slot *slot, gfn_t gfn,
struct page **pages, int nr_pages)
{
unsigned long addr;
gfn_t entry;
addr = gfn_to_hva_many(slot, gfn, &entry);
if (kvm_is_error_hva(addr))
return -1;
if (entry < nr_pages)
return 0;
return __get_user_pages_fast(addr, nr_pages, 1, pages);
}
static struct page *kvm_pfn_to_page(pfn_t pfn)
{
if (is_error_noslot_pfn(pfn))
return KVM_ERR_PTR_BAD_PAGE;
if (kvm_is_reserved_pfn(pfn)) {
WARN_ON(1);
return KVM_ERR_PTR_BAD_PAGE;
}
return pfn_to_page(pfn);
}
struct page *gfn_to_page(struct kvm *kvm, gfn_t gfn)
{
pfn_t pfn;
pfn = gfn_to_pfn(kvm, gfn);
return kvm_pfn_to_page(pfn);
}
struct page *kvm_vcpu_gfn_to_page(struct kvm_vcpu *vcpu, gfn_t gfn)
{
pfn_t pfn;
pfn = kvm_vcpu_gfn_to_pfn(vcpu, gfn);
return kvm_pfn_to_page(pfn);
}
void kvm_release_page_clean(struct page *page)
{
WARN_ON(is_error_page(page));
kvm_release_pfn_clean(page_to_pfn(page));
}
void kvm_release_pfn_clean(pfn_t pfn)
{
if (!is_error_noslot_pfn(pfn) && !kvm_is_reserved_pfn(pfn))
put_page(pfn_to_page(pfn));
}
void kvm_release_page_dirty(struct page *page)
{
WARN_ON(is_error_page(page));
kvm_release_pfn_dirty(page_to_pfn(page));
}
static void kvm_release_pfn_dirty(pfn_t pfn)
{
kvm_set_pfn_dirty(pfn);
kvm_release_pfn_clean(pfn);
}
void kvm_set_pfn_dirty(pfn_t pfn)
{
if (!kvm_is_reserved_pfn(pfn)) {
struct page *page = pfn_to_page(pfn);
if (!PageReserved(page))
SetPageDirty(page);
}
}
void kvm_set_pfn_accessed(pfn_t pfn)
{
if (!kvm_is_reserved_pfn(pfn))
mark_page_accessed(pfn_to_page(pfn));
}
void kvm_get_pfn(pfn_t pfn)
{
if (!kvm_is_reserved_pfn(pfn))
get_page(pfn_to_page(pfn));
}
static int next_segment(unsigned long len, int offset)
{
if (len > PAGE_SIZE - offset)
return PAGE_SIZE - offset;
else
return len;
}
static int __kvm_read_guest_page(struct kvm_memory_slot *slot, gfn_t gfn,
void *data, int offset, int len)
{
int r;
unsigned long addr;
addr = gfn_to_hva_memslot_prot(slot, gfn, NULL);
if (kvm_is_error_hva(addr))
return -EFAULT;
r = __copy_from_user(data, (void __user *)addr + offset, len);
if (r)
return -EFAULT;
return 0;
}
int kvm_read_guest_page(struct kvm *kvm, gfn_t gfn, void *data, int offset,
int len)
{
struct kvm_memory_slot *slot = gfn_to_memslot(kvm, gfn);
return __kvm_read_guest_page(slot, gfn, data, offset, len);
}
int kvm_vcpu_read_guest_page(struct kvm_vcpu *vcpu, gfn_t gfn, void *data,
int offset, int len)
{
struct kvm_memory_slot *slot = kvm_vcpu_gfn_to_memslot(vcpu, gfn);
return __kvm_read_guest_page(slot, gfn, data, offset, len);
}
int kvm_read_guest(struct kvm *kvm, gpa_t gpa, void *data, unsigned long len)
{
gfn_t gfn = gpa >> PAGE_SHIFT;
int seg;
int offset = offset_in_page(gpa);
int ret;
while ((seg = next_segment(len, offset)) != 0) {
ret = kvm_read_guest_page(kvm, gfn, data, offset, seg);
if (ret < 0)
return ret;
offset = 0;
len -= seg;
data += seg;
++gfn;
}
return 0;
}
int kvm_vcpu_read_guest(struct kvm_vcpu *vcpu, gpa_t gpa, void *data, unsigned long len)
{
gfn_t gfn = gpa >> PAGE_SHIFT;
int seg;
int offset = offset_in_page(gpa);
int ret;
while ((seg = next_segment(len, offset)) != 0) {
ret = kvm_vcpu_read_guest_page(vcpu, gfn, data, offset, seg);
if (ret < 0)
return ret;
offset = 0;
len -= seg;
data += seg;
++gfn;
}
return 0;
}
static int __kvm_read_guest_atomic(struct kvm_memory_slot *slot, gfn_t gfn,
void *data, int offset, unsigned long len)
{
int r;
unsigned long addr;
addr = gfn_to_hva_memslot_prot(slot, gfn, NULL);
if (kvm_is_error_hva(addr))
return -EFAULT;
pagefault_disable();
r = __copy_from_user_inatomic(data, (void __user *)addr + offset, len);
pagefault_enable();
if (r)
return -EFAULT;
return 0;
}
int kvm_read_guest_atomic(struct kvm *kvm, gpa_t gpa, void *data,
unsigned long len)
{
gfn_t gfn = gpa >> PAGE_SHIFT;
struct kvm_memory_slot *slot = gfn_to_memslot(kvm, gfn);
int offset = offset_in_page(gpa);
return __kvm_read_guest_atomic(slot, gfn, data, offset, len);
}
int kvm_vcpu_read_guest_atomic(struct kvm_vcpu *vcpu, gpa_t gpa,
void *data, unsigned long len)
{
gfn_t gfn = gpa >> PAGE_SHIFT;
struct kvm_memory_slot *slot = kvm_vcpu_gfn_to_memslot(vcpu, gfn);
int offset = offset_in_page(gpa);
return __kvm_read_guest_atomic(slot, gfn, data, offset, len);
}
static int __kvm_write_guest_page(struct kvm_memory_slot *memslot, gfn_t gfn,
const void *data, int offset, int len)
{
int r;
unsigned long addr;
addr = gfn_to_hva_memslot(memslot, gfn);
if (kvm_is_error_hva(addr))
return -EFAULT;
r = __copy_to_user((void __user *)addr + offset, data, len);
if (r)
return -EFAULT;
mark_page_dirty_in_slot(memslot, gfn);
return 0;
}
int kvm_write_guest_page(struct kvm *kvm, gfn_t gfn,
const void *data, int offset, int len)
{
struct kvm_memory_slot *slot = gfn_to_memslot(kvm, gfn);
return __kvm_write_guest_page(slot, gfn, data, offset, len);
}
int kvm_vcpu_write_guest_page(struct kvm_vcpu *vcpu, gfn_t gfn,
const void *data, int offset, int len)
{
struct kvm_memory_slot *slot = kvm_vcpu_gfn_to_memslot(vcpu, gfn);
return __kvm_write_guest_page(slot, gfn, data, offset, len);
}
int kvm_write_guest(struct kvm *kvm, gpa_t gpa, const void *data,
unsigned long len)
{
gfn_t gfn = gpa >> PAGE_SHIFT;
int seg;
int offset = offset_in_page(gpa);
int ret;
while ((seg = next_segment(len, offset)) != 0) {
ret = kvm_write_guest_page(kvm, gfn, data, offset, seg);
if (ret < 0)
return ret;
offset = 0;
len -= seg;
data += seg;
++gfn;
}
return 0;
}
int kvm_vcpu_write_guest(struct kvm_vcpu *vcpu, gpa_t gpa, const void *data,
unsigned long len)
{
gfn_t gfn = gpa >> PAGE_SHIFT;
int seg;
int offset = offset_in_page(gpa);
int ret;
while ((seg = next_segment(len, offset)) != 0) {
ret = kvm_vcpu_write_guest_page(vcpu, gfn, data, offset, seg);
if (ret < 0)
return ret;
offset = 0;
len -= seg;
data += seg;
++gfn;
}
return 0;
}
int kvm_gfn_to_hva_cache_init(struct kvm *kvm, struct gfn_to_hva_cache *ghc,
gpa_t gpa, unsigned long len)
{
struct kvm_memslots *slots = kvm_memslots(kvm);
int offset = offset_in_page(gpa);
gfn_t start_gfn = gpa >> PAGE_SHIFT;
gfn_t end_gfn = (gpa + len - 1) >> PAGE_SHIFT;
gfn_t nr_pages_needed = end_gfn - start_gfn + 1;
gfn_t nr_pages_avail;
ghc->gpa = gpa;
ghc->generation = slots->generation;
ghc->len = len;
ghc->memslot = gfn_to_memslot(kvm, start_gfn);
ghc->hva = gfn_to_hva_many(ghc->memslot, start_gfn, NULL);
if (!kvm_is_error_hva(ghc->hva) && nr_pages_needed <= 1) {
ghc->hva += offset;
} else {
while (start_gfn <= end_gfn) {
ghc->memslot = gfn_to_memslot(kvm, start_gfn);
ghc->hva = gfn_to_hva_many(ghc->memslot, start_gfn,
&nr_pages_avail);
if (kvm_is_error_hva(ghc->hva))
return -EFAULT;
start_gfn += nr_pages_avail;
}
ghc->memslot = NULL;
}
return 0;
}
int kvm_write_guest_cached(struct kvm *kvm, struct gfn_to_hva_cache *ghc,
void *data, unsigned long len)
{
struct kvm_memslots *slots = kvm_memslots(kvm);
int r;
BUG_ON(len > ghc->len);
if (slots->generation != ghc->generation)
kvm_gfn_to_hva_cache_init(kvm, ghc, ghc->gpa, ghc->len);
if (unlikely(!ghc->memslot))
return kvm_write_guest(kvm, ghc->gpa, data, len);
if (kvm_is_error_hva(ghc->hva))
return -EFAULT;
r = __copy_to_user((void __user *)ghc->hva, data, len);
if (r)
return -EFAULT;
mark_page_dirty_in_slot(ghc->memslot, ghc->gpa >> PAGE_SHIFT);
return 0;
}
int kvm_read_guest_cached(struct kvm *kvm, struct gfn_to_hva_cache *ghc,
void *data, unsigned long len)
{
struct kvm_memslots *slots = kvm_memslots(kvm);
int r;
BUG_ON(len > ghc->len);
if (slots->generation != ghc->generation)
kvm_gfn_to_hva_cache_init(kvm, ghc, ghc->gpa, ghc->len);
if (unlikely(!ghc->memslot))
return kvm_read_guest(kvm, ghc->gpa, data, len);
if (kvm_is_error_hva(ghc->hva))
return -EFAULT;
r = __copy_from_user(data, (void __user *)ghc->hva, len);
if (r)
return -EFAULT;
return 0;
}
int kvm_clear_guest_page(struct kvm *kvm, gfn_t gfn, int offset, int len)
{
const void *zero_page = (const void *) __va(page_to_phys(ZERO_PAGE(0)));
return kvm_write_guest_page(kvm, gfn, zero_page, offset, len);
}
int kvm_clear_guest(struct kvm *kvm, gpa_t gpa, unsigned long len)
{
gfn_t gfn = gpa >> PAGE_SHIFT;
int seg;
int offset = offset_in_page(gpa);
int ret;
while ((seg = next_segment(len, offset)) != 0) {
ret = kvm_clear_guest_page(kvm, gfn, offset, seg);
if (ret < 0)
return ret;
offset = 0;
len -= seg;
++gfn;
}
return 0;
}
static void mark_page_dirty_in_slot(struct kvm_memory_slot *memslot,
gfn_t gfn)
{
if (memslot && memslot->dirty_bitmap) {
unsigned long rel_gfn = gfn - memslot->base_gfn;
set_bit_le(rel_gfn, memslot->dirty_bitmap);
}
}
void mark_page_dirty(struct kvm *kvm, gfn_t gfn)
{
struct kvm_memory_slot *memslot;
memslot = gfn_to_memslot(kvm, gfn);
mark_page_dirty_in_slot(memslot, gfn);
}
void kvm_vcpu_mark_page_dirty(struct kvm_vcpu *vcpu, gfn_t gfn)
{
struct kvm_memory_slot *memslot;
memslot = kvm_vcpu_gfn_to_memslot(vcpu, gfn);
mark_page_dirty_in_slot(memslot, gfn);
}
static int kvm_vcpu_check_block(struct kvm_vcpu *vcpu)
{
if (kvm_arch_vcpu_runnable(vcpu)) {
kvm_make_request(KVM_REQ_UNHALT, vcpu);
return -EINTR;
}
if (kvm_cpu_has_pending_timer(vcpu))
return -EINTR;
if (signal_pending(current))
return -EINTR;
return 0;
}
void kvm_vcpu_block(struct kvm_vcpu *vcpu)
{
ktime_t start, cur;
DEFINE_WAIT(wait);
bool waited = false;
start = cur = ktime_get();
if (halt_poll_ns) {
ktime_t stop = ktime_add_ns(ktime_get(), halt_poll_ns);
do {
if (kvm_vcpu_check_block(vcpu) < 0) {
++vcpu->stat.halt_successful_poll;
goto out;
}
cur = ktime_get();
} while (single_task_running() && ktime_before(cur, stop));
}
for (;;) {
prepare_to_wait(&vcpu->wq, &wait, TASK_INTERRUPTIBLE);
if (kvm_vcpu_check_block(vcpu) < 0)
break;
waited = true;
schedule();
}
finish_wait(&vcpu->wq, &wait);
cur = ktime_get();
out:
trace_kvm_vcpu_wakeup(ktime_to_ns(cur) - ktime_to_ns(start), waited);
}
void kvm_vcpu_kick(struct kvm_vcpu *vcpu)
{
int me;
int cpu = vcpu->cpu;
wait_queue_head_t *wqp;
wqp = kvm_arch_vcpu_wq(vcpu);
if (waitqueue_active(wqp)) {
wake_up_interruptible(wqp);
++vcpu->stat.halt_wakeup;
}
me = get_cpu();
if (cpu != me && (unsigned)cpu < nr_cpu_ids && cpu_online(cpu))
if (kvm_arch_vcpu_should_kick(vcpu))
smp_send_reschedule(cpu);
put_cpu();
}
int kvm_vcpu_yield_to(struct kvm_vcpu *target)
{
struct pid *pid;
struct task_struct *task = NULL;
int ret = 0;
rcu_read_lock();
pid = rcu_dereference(target->pid);
if (pid)
task = get_pid_task(pid, PIDTYPE_PID);
rcu_read_unlock();
if (!task)
return ret;
ret = yield_to(task, 1);
put_task_struct(task);
return ret;
}
static bool kvm_vcpu_eligible_for_directed_yield(struct kvm_vcpu *vcpu)
{
#ifdef CONFIG_HAVE_KVM_CPU_RELAX_INTERCEPT
bool eligible;
eligible = !vcpu->spin_loop.in_spin_loop ||
vcpu->spin_loop.dy_eligible;
if (vcpu->spin_loop.in_spin_loop)
kvm_vcpu_set_dy_eligible(vcpu, !vcpu->spin_loop.dy_eligible);
return eligible;
#else
return true;
#endif
}
void kvm_vcpu_on_spin(struct kvm_vcpu *me)
{
struct kvm *kvm = me->kvm;
struct kvm_vcpu *vcpu;
int last_boosted_vcpu = me->kvm->last_boosted_vcpu;
int yielded = 0;
int try = 3;
int pass;
int i;
kvm_vcpu_set_in_spin_loop(me, true);
for (pass = 0; pass < 2 && !yielded && try; pass++) {
kvm_for_each_vcpu(i, vcpu, kvm) {
if (!pass && i <= last_boosted_vcpu) {
i = last_boosted_vcpu;
continue;
} else if (pass && i > last_boosted_vcpu)
break;
if (!ACCESS_ONCE(vcpu->preempted))
continue;
if (vcpu == me)
continue;
if (waitqueue_active(&vcpu->wq) && !kvm_arch_vcpu_runnable(vcpu))
continue;
if (!kvm_vcpu_eligible_for_directed_yield(vcpu))
continue;
yielded = kvm_vcpu_yield_to(vcpu);
if (yielded > 0) {
kvm->last_boosted_vcpu = i;
break;
} else if (yielded < 0) {
try--;
if (!try)
break;
}
}
}
kvm_vcpu_set_in_spin_loop(me, false);
kvm_vcpu_set_dy_eligible(me, false);
}
static int kvm_vcpu_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct kvm_vcpu *vcpu = vma->vm_file->private_data;
struct page *page;
if (vmf->pgoff == 0)
page = virt_to_page(vcpu->run);
#ifdef CONFIG_X86
else if (vmf->pgoff == KVM_PIO_PAGE_OFFSET)
page = virt_to_page(vcpu->arch.pio_data);
#endif
#ifdef KVM_COALESCED_MMIO_PAGE_OFFSET
else if (vmf->pgoff == KVM_COALESCED_MMIO_PAGE_OFFSET)
page = virt_to_page(vcpu->kvm->coalesced_mmio_ring);
#endif
else
return kvm_arch_vcpu_fault(vcpu, vmf);
get_page(page);
vmf->page = page;
return 0;
}
static int kvm_vcpu_mmap(struct file *file, struct vm_area_struct *vma)
{
vma->vm_ops = &kvm_vcpu_vm_ops;
return 0;
}
static int kvm_vcpu_release(struct inode *inode, struct file *filp)
{
struct kvm_vcpu *vcpu = filp->private_data;
kvm_put_kvm(vcpu->kvm);
return 0;
}
static int create_vcpu_fd(struct kvm_vcpu *vcpu)
{
return anon_inode_getfd("kvm-vcpu", &kvm_vcpu_fops, vcpu, O_RDWR | O_CLOEXEC);
}
static int kvm_vm_ioctl_create_vcpu(struct kvm *kvm, u32 id)
{
int r;
struct kvm_vcpu *vcpu, *v;
if (id >= KVM_MAX_VCPUS)
return -EINVAL;
vcpu = kvm_arch_vcpu_create(kvm, id);
if (IS_ERR(vcpu))
return PTR_ERR(vcpu);
preempt_notifier_init(&vcpu->preempt_notifier, &kvm_preempt_ops);
r = kvm_arch_vcpu_setup(vcpu);
if (r)
goto vcpu_destroy;
mutex_lock(&kvm->lock);
if (!kvm_vcpu_compatible(vcpu)) {
r = -EINVAL;
goto unlock_vcpu_destroy;
}
if (atomic_read(&kvm->online_vcpus) == KVM_MAX_VCPUS) {
r = -EINVAL;
goto unlock_vcpu_destroy;
}
kvm_for_each_vcpu(r, v, kvm)
if (v->vcpu_id == id) {
r = -EEXIST;
goto unlock_vcpu_destroy;
}
BUG_ON(kvm->vcpus[atomic_read(&kvm->online_vcpus)]);
kvm_get_kvm(kvm);
r = create_vcpu_fd(vcpu);
if (r < 0) {
kvm_put_kvm(kvm);
goto unlock_vcpu_destroy;
}
kvm->vcpus[atomic_read(&kvm->online_vcpus)] = vcpu;
smp_wmb();
atomic_inc(&kvm->online_vcpus);
mutex_unlock(&kvm->lock);
kvm_arch_vcpu_postcreate(vcpu);
return r;
unlock_vcpu_destroy:
mutex_unlock(&kvm->lock);
vcpu_destroy:
kvm_arch_vcpu_destroy(vcpu);
return r;
}
static int kvm_vcpu_ioctl_set_sigmask(struct kvm_vcpu *vcpu, sigset_t *sigset)
{
if (sigset) {
sigdelsetmask(sigset, sigmask(SIGKILL)|sigmask(SIGSTOP));
vcpu->sigset_active = 1;
vcpu->sigset = *sigset;
} else
vcpu->sigset_active = 0;
return 0;
}
static long kvm_vcpu_ioctl(struct file *filp,
unsigned int ioctl, unsigned long arg)
{
struct kvm_vcpu *vcpu = filp->private_data;
void __user *argp = (void __user *)arg;
int r;
struct kvm_fpu *fpu = NULL;
struct kvm_sregs *kvm_sregs = NULL;
if (vcpu->kvm->mm != current->mm)
return -EIO;
if (unlikely(_IOC_TYPE(ioctl) != KVMIO))
return -EINVAL;
#if defined(CONFIG_S390) || defined(CONFIG_PPC) || defined(CONFIG_MIPS)
if (ioctl == KVM_S390_INTERRUPT || ioctl == KVM_S390_IRQ || ioctl == KVM_INTERRUPT)
return kvm_arch_vcpu_ioctl(filp, ioctl, arg);
#endif
r = vcpu_load(vcpu);
if (r)
return r;
switch (ioctl) {
case KVM_RUN:
r = -EINVAL;
if (arg)
goto out;
if (unlikely(vcpu->pid != current->pids[PIDTYPE_PID].pid)) {
struct pid *oldpid = vcpu->pid;
struct pid *newpid = get_task_pid(current, PIDTYPE_PID);
rcu_assign_pointer(vcpu->pid, newpid);
if (oldpid)
synchronize_rcu();
put_pid(oldpid);
}
r = kvm_arch_vcpu_ioctl_run(vcpu, vcpu->run);
trace_kvm_userspace_exit(vcpu->run->exit_reason, r);
break;
case KVM_GET_REGS: {
struct kvm_regs *kvm_regs;
r = -ENOMEM;
kvm_regs = kzalloc(sizeof(struct kvm_regs), GFP_KERNEL);
if (!kvm_regs)
goto out;
r = kvm_arch_vcpu_ioctl_get_regs(vcpu, kvm_regs);
if (r)
goto out_free1;
r = -EFAULT;
if (copy_to_user(argp, kvm_regs, sizeof(struct kvm_regs)))
goto out_free1;
r = 0;
out_free1:
kfree(kvm_regs);
break;
}
case KVM_SET_REGS: {
struct kvm_regs *kvm_regs;
r = -ENOMEM;
kvm_regs = memdup_user(argp, sizeof(*kvm_regs));
if (IS_ERR(kvm_regs)) {
r = PTR_ERR(kvm_regs);
goto out;
}
r = kvm_arch_vcpu_ioctl_set_regs(vcpu, kvm_regs);
kfree(kvm_regs);
break;
}
case KVM_GET_SREGS: {
kvm_sregs = kzalloc(sizeof(struct kvm_sregs), GFP_KERNEL);
r = -ENOMEM;
if (!kvm_sregs)
goto out;
r = kvm_arch_vcpu_ioctl_get_sregs(vcpu, kvm_sregs);
if (r)
goto out;
r = -EFAULT;
if (copy_to_user(argp, kvm_sregs, sizeof(struct kvm_sregs)))
goto out;
r = 0;
break;
}
case KVM_SET_SREGS: {
kvm_sregs = memdup_user(argp, sizeof(*kvm_sregs));
if (IS_ERR(kvm_sregs)) {
r = PTR_ERR(kvm_sregs);
kvm_sregs = NULL;
goto out;
}
r = kvm_arch_vcpu_ioctl_set_sregs(vcpu, kvm_sregs);
break;
}
case KVM_GET_MP_STATE: {
struct kvm_mp_state mp_state;
r = kvm_arch_vcpu_ioctl_get_mpstate(vcpu, &mp_state);
if (r)
goto out;
r = -EFAULT;
if (copy_to_user(argp, &mp_state, sizeof(mp_state)))
goto out;
r = 0;
break;
}
case KVM_SET_MP_STATE: {
struct kvm_mp_state mp_state;
r = -EFAULT;
if (copy_from_user(&mp_state, argp, sizeof(mp_state)))
goto out;
r = kvm_arch_vcpu_ioctl_set_mpstate(vcpu, &mp_state);
break;
}
case KVM_TRANSLATE: {
struct kvm_translation tr;
r = -EFAULT;
if (copy_from_user(&tr, argp, sizeof(tr)))
goto out;
r = kvm_arch_vcpu_ioctl_translate(vcpu, &tr);
if (r)
goto out;
r = -EFAULT;
if (copy_to_user(argp, &tr, sizeof(tr)))
goto out;
r = 0;
break;
}
case KVM_SET_GUEST_DEBUG: {
struct kvm_guest_debug dbg;
r = -EFAULT;
if (copy_from_user(&dbg, argp, sizeof(dbg)))
goto out;
r = kvm_arch_vcpu_ioctl_set_guest_debug(vcpu, &dbg);
break;
}
case KVM_SET_SIGNAL_MASK: {
struct kvm_signal_mask __user *sigmask_arg = argp;
struct kvm_signal_mask kvm_sigmask;
sigset_t sigset, *p;
p = NULL;
if (argp) {
r = -EFAULT;
if (copy_from_user(&kvm_sigmask, argp,
sizeof(kvm_sigmask)))
goto out;
r = -EINVAL;
if (kvm_sigmask.len != sizeof(sigset))
goto out;
r = -EFAULT;
if (copy_from_user(&sigset, sigmask_arg->sigset,
sizeof(sigset)))
goto out;
p = &sigset;
}
r = kvm_vcpu_ioctl_set_sigmask(vcpu, p);
break;
}
case KVM_GET_FPU: {
fpu = kzalloc(sizeof(struct kvm_fpu), GFP_KERNEL);
r = -ENOMEM;
if (!fpu)
goto out;
r = kvm_arch_vcpu_ioctl_get_fpu(vcpu, fpu);
if (r)
goto out;
r = -EFAULT;
if (copy_to_user(argp, fpu, sizeof(struct kvm_fpu)))
goto out;
r = 0;
break;
}
case KVM_SET_FPU: {
fpu = memdup_user(argp, sizeof(*fpu));
if (IS_ERR(fpu)) {
r = PTR_ERR(fpu);
fpu = NULL;
goto out;
}
r = kvm_arch_vcpu_ioctl_set_fpu(vcpu, fpu);
break;
}
default:
r = kvm_arch_vcpu_ioctl(filp, ioctl, arg);
}
out:
vcpu_put(vcpu);
kfree(fpu);
kfree(kvm_sregs);
return r;
}
static long kvm_vcpu_compat_ioctl(struct file *filp,
unsigned int ioctl, unsigned long arg)
{
struct kvm_vcpu *vcpu = filp->private_data;
void __user *argp = compat_ptr(arg);
int r;
if (vcpu->kvm->mm != current->mm)
return -EIO;
switch (ioctl) {
case KVM_SET_SIGNAL_MASK: {
struct kvm_signal_mask __user *sigmask_arg = argp;
struct kvm_signal_mask kvm_sigmask;
compat_sigset_t csigset;
sigset_t sigset;
if (argp) {
r = -EFAULT;
if (copy_from_user(&kvm_sigmask, argp,
sizeof(kvm_sigmask)))
goto out;
r = -EINVAL;
if (kvm_sigmask.len != sizeof(csigset))
goto out;
r = -EFAULT;
if (copy_from_user(&csigset, sigmask_arg->sigset,
sizeof(csigset)))
goto out;
sigset_from_compat(&sigset, &csigset);
r = kvm_vcpu_ioctl_set_sigmask(vcpu, &sigset);
} else
r = kvm_vcpu_ioctl_set_sigmask(vcpu, NULL);
break;
}
default:
r = kvm_vcpu_ioctl(filp, ioctl, arg);
}
out:
return r;
}
static int kvm_device_ioctl_attr(struct kvm_device *dev,
int (*accessor)(struct kvm_device *dev,
struct kvm_device_attr *attr),
unsigned long arg)
{
struct kvm_device_attr attr;
if (!accessor)
return -EPERM;
if (copy_from_user(&attr, (void __user *)arg, sizeof(attr)))
return -EFAULT;
return accessor(dev, &attr);
}
static long kvm_device_ioctl(struct file *filp, unsigned int ioctl,
unsigned long arg)
{
struct kvm_device *dev = filp->private_data;
switch (ioctl) {
case KVM_SET_DEVICE_ATTR:
return kvm_device_ioctl_attr(dev, dev->ops->set_attr, arg);
case KVM_GET_DEVICE_ATTR:
return kvm_device_ioctl_attr(dev, dev->ops->get_attr, arg);
case KVM_HAS_DEVICE_ATTR:
return kvm_device_ioctl_attr(dev, dev->ops->has_attr, arg);
default:
if (dev->ops->ioctl)
return dev->ops->ioctl(dev, ioctl, arg);
return -ENOTTY;
}
}
static int kvm_device_release(struct inode *inode, struct file *filp)
{
struct kvm_device *dev = filp->private_data;
struct kvm *kvm = dev->kvm;
kvm_put_kvm(kvm);
return 0;
}
struct kvm_device *kvm_device_from_filp(struct file *filp)
{
if (filp->f_op != &kvm_device_fops)
return NULL;
return filp->private_data;
}
int kvm_register_device_ops(struct kvm_device_ops *ops, u32 type)
{
if (type >= ARRAY_SIZE(kvm_device_ops_table))
return -ENOSPC;
if (kvm_device_ops_table[type] != NULL)
return -EEXIST;
kvm_device_ops_table[type] = ops;
return 0;
}
void kvm_unregister_device_ops(u32 type)
{
if (kvm_device_ops_table[type] != NULL)
kvm_device_ops_table[type] = NULL;
}
static int kvm_ioctl_create_device(struct kvm *kvm,
struct kvm_create_device *cd)
{
struct kvm_device_ops *ops = NULL;
struct kvm_device *dev;
bool test = cd->flags & KVM_CREATE_DEVICE_TEST;
int ret;
if (cd->type >= ARRAY_SIZE(kvm_device_ops_table))
return -ENODEV;
ops = kvm_device_ops_table[cd->type];
if (ops == NULL)
return -ENODEV;
if (test)
return 0;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
dev->ops = ops;
dev->kvm = kvm;
ret = ops->create(dev, cd->type);
if (ret < 0) {
kfree(dev);
return ret;
}
ret = anon_inode_getfd(ops->name, &kvm_device_fops, dev, O_RDWR | O_CLOEXEC);
if (ret < 0) {
ops->destroy(dev);
return ret;
}
list_add(&dev->vm_node, &kvm->devices);
kvm_get_kvm(kvm);
cd->fd = ret;
return 0;
}
static long kvm_vm_ioctl_check_extension_generic(struct kvm *kvm, long arg)
{
switch (arg) {
case KVM_CAP_USER_MEMORY:
case KVM_CAP_DESTROY_MEMORY_REGION_WORKS:
case KVM_CAP_JOIN_MEMORY_REGIONS_WORKS:
#ifdef CONFIG_KVM_APIC_ARCHITECTURE
case KVM_CAP_SET_BOOT_CPU_ID:
#endif
case KVM_CAP_INTERNAL_ERROR_DATA:
#ifdef CONFIG_HAVE_KVM_MSI
case KVM_CAP_SIGNAL_MSI:
#endif
#ifdef CONFIG_HAVE_KVM_IRQFD
case KVM_CAP_IRQFD:
case KVM_CAP_IRQFD_RESAMPLE:
#endif
case KVM_CAP_CHECK_EXTENSION_VM:
return 1;
#ifdef CONFIG_HAVE_KVM_IRQ_ROUTING
case KVM_CAP_IRQ_ROUTING:
return KVM_MAX_IRQ_ROUTES;
#endif
#if KVM_ADDRESS_SPACE_NUM > 1
case KVM_CAP_MULTI_ADDRESS_SPACE:
return KVM_ADDRESS_SPACE_NUM;
#endif
default:
break;
}
return kvm_vm_ioctl_check_extension(kvm, arg);
}
static long kvm_vm_ioctl(struct file *filp,
unsigned int ioctl, unsigned long arg)
{
struct kvm *kvm = filp->private_data;
void __user *argp = (void __user *)arg;
int r;
if (kvm->mm != current->mm)
return -EIO;
switch (ioctl) {
case KVM_CREATE_VCPU:
r = kvm_vm_ioctl_create_vcpu(kvm, arg);
break;
case KVM_SET_USER_MEMORY_REGION: {
struct kvm_userspace_memory_region kvm_userspace_mem;
r = -EFAULT;
if (copy_from_user(&kvm_userspace_mem, argp,
sizeof(kvm_userspace_mem)))
goto out;
r = kvm_vm_ioctl_set_memory_region(kvm, &kvm_userspace_mem);
break;
}
case KVM_GET_DIRTY_LOG: {
struct kvm_dirty_log log;
r = -EFAULT;
if (copy_from_user(&log, argp, sizeof(log)))
goto out;
r = kvm_vm_ioctl_get_dirty_log(kvm, &log);
break;
}
#ifdef KVM_COALESCED_MMIO_PAGE_OFFSET
case KVM_REGISTER_COALESCED_MMIO: {
struct kvm_coalesced_mmio_zone zone;
r = -EFAULT;
if (copy_from_user(&zone, argp, sizeof(zone)))
goto out;
r = kvm_vm_ioctl_register_coalesced_mmio(kvm, &zone);
break;
}
case KVM_UNREGISTER_COALESCED_MMIO: {
struct kvm_coalesced_mmio_zone zone;
r = -EFAULT;
if (copy_from_user(&zone, argp, sizeof(zone)))
goto out;
r = kvm_vm_ioctl_unregister_coalesced_mmio(kvm, &zone);
break;
}
#endif
case KVM_IRQFD: {
struct kvm_irqfd data;
r = -EFAULT;
if (copy_from_user(&data, argp, sizeof(data)))
goto out;
r = kvm_irqfd(kvm, &data);
break;
}
case KVM_IOEVENTFD: {
struct kvm_ioeventfd data;
r = -EFAULT;
if (copy_from_user(&data, argp, sizeof(data)))
goto out;
r = kvm_ioeventfd(kvm, &data);
break;
}
#ifdef CONFIG_KVM_APIC_ARCHITECTURE
case KVM_SET_BOOT_CPU_ID:
r = 0;
mutex_lock(&kvm->lock);
if (atomic_read(&kvm->online_vcpus) != 0)
r = -EBUSY;
else
kvm->bsp_vcpu_id = arg;
mutex_unlock(&kvm->lock);
break;
#endif
#ifdef CONFIG_HAVE_KVM_MSI
case KVM_SIGNAL_MSI: {
struct kvm_msi msi;
r = -EFAULT;
if (copy_from_user(&msi, argp, sizeof(msi)))
goto out;
r = kvm_send_userspace_msi(kvm, &msi);
break;
}
#endif
#ifdef __KVM_HAVE_IRQ_LINE
case KVM_IRQ_LINE_STATUS:
case KVM_IRQ_LINE: {
struct kvm_irq_level irq_event;
r = -EFAULT;
if (copy_from_user(&irq_event, argp, sizeof(irq_event)))
goto out;
r = kvm_vm_ioctl_irq_line(kvm, &irq_event,
ioctl == KVM_IRQ_LINE_STATUS);
if (r)
goto out;
r = -EFAULT;
if (ioctl == KVM_IRQ_LINE_STATUS) {
if (copy_to_user(argp, &irq_event, sizeof(irq_event)))
goto out;
}
r = 0;
break;
}
#endif
#ifdef CONFIG_HAVE_KVM_IRQ_ROUTING
case KVM_SET_GSI_ROUTING: {
struct kvm_irq_routing routing;
struct kvm_irq_routing __user *urouting;
struct kvm_irq_routing_entry *entries;
r = -EFAULT;
if (copy_from_user(&routing, argp, sizeof(routing)))
goto out;
r = -EINVAL;
if (routing.nr >= KVM_MAX_IRQ_ROUTES)
goto out;
if (routing.flags)
goto out;
r = -ENOMEM;
entries = vmalloc(routing.nr * sizeof(*entries));
if (!entries)
goto out;
r = -EFAULT;
urouting = argp;
if (copy_from_user(entries, urouting->entries,
routing.nr * sizeof(*entries)))
goto out_free_irq_routing;
r = kvm_set_irq_routing(kvm, entries, routing.nr,
routing.flags);
out_free_irq_routing:
vfree(entries);
break;
}
#endif
case KVM_CREATE_DEVICE: {
struct kvm_create_device cd;
r = -EFAULT;
if (copy_from_user(&cd, argp, sizeof(cd)))
goto out;
r = kvm_ioctl_create_device(kvm, &cd);
if (r)
goto out;
r = -EFAULT;
if (copy_to_user(argp, &cd, sizeof(cd)))
goto out;
r = 0;
break;
}
case KVM_CHECK_EXTENSION:
r = kvm_vm_ioctl_check_extension_generic(kvm, arg);
break;
default:
r = kvm_arch_vm_ioctl(filp, ioctl, arg);
}
out:
return r;
}
static long kvm_vm_compat_ioctl(struct file *filp,
unsigned int ioctl, unsigned long arg)
{
struct kvm *kvm = filp->private_data;
int r;
if (kvm->mm != current->mm)
return -EIO;
switch (ioctl) {
case KVM_GET_DIRTY_LOG: {
struct compat_kvm_dirty_log compat_log;
struct kvm_dirty_log log;
r = -EFAULT;
if (copy_from_user(&compat_log, (void __user *)arg,
sizeof(compat_log)))
goto out;
log.slot = compat_log.slot;
log.padding1 = compat_log.padding1;
log.padding2 = compat_log.padding2;
log.dirty_bitmap = compat_ptr(compat_log.dirty_bitmap);
r = kvm_vm_ioctl_get_dirty_log(kvm, &log);
break;
}
default:
r = kvm_vm_ioctl(filp, ioctl, arg);
}
out:
return r;
}
static int kvm_dev_ioctl_create_vm(unsigned long type)
{
int r;
struct kvm *kvm;
kvm = kvm_create_vm(type);
if (IS_ERR(kvm))
return PTR_ERR(kvm);
#ifdef KVM_COALESCED_MMIO_PAGE_OFFSET
r = kvm_coalesced_mmio_init(kvm);
if (r < 0) {
kvm_put_kvm(kvm);
return r;
}
#endif
r = anon_inode_getfd("kvm-vm", &kvm_vm_fops, kvm, O_RDWR | O_CLOEXEC);
if (r < 0)
kvm_put_kvm(kvm);
return r;
}
static long kvm_dev_ioctl(struct file *filp,
unsigned int ioctl, unsigned long arg)
{
long r = -EINVAL;
switch (ioctl) {
case KVM_GET_API_VERSION:
if (arg)
goto out;
r = KVM_API_VERSION;
break;
case KVM_CREATE_VM:
r = kvm_dev_ioctl_create_vm(arg);
break;
case KVM_CHECK_EXTENSION:
r = kvm_vm_ioctl_check_extension_generic(NULL, arg);
break;
case KVM_GET_VCPU_MMAP_SIZE:
if (arg)
goto out;
r = PAGE_SIZE;
#ifdef CONFIG_X86
r += PAGE_SIZE;
#endif
#ifdef KVM_COALESCED_MMIO_PAGE_OFFSET
r += PAGE_SIZE;
#endif
break;
case KVM_TRACE_ENABLE:
case KVM_TRACE_PAUSE:
case KVM_TRACE_DISABLE:
r = -EOPNOTSUPP;
break;
default:
return kvm_arch_dev_ioctl(filp, ioctl, arg);
}
out:
return r;
}
static void hardware_enable_nolock(void *junk)
{
int cpu = raw_smp_processor_id();
int r;
if (cpumask_test_cpu(cpu, cpus_hardware_enabled))
return;
cpumask_set_cpu(cpu, cpus_hardware_enabled);
r = kvm_arch_hardware_enable();
if (r) {
cpumask_clear_cpu(cpu, cpus_hardware_enabled);
atomic_inc(&hardware_enable_failed);
pr_info("kvm: enabling virtualization on CPU%d failed\n", cpu);
}
}
static void hardware_enable(void)
{
raw_spin_lock(&kvm_count_lock);
if (kvm_usage_count)
hardware_enable_nolock(NULL);
raw_spin_unlock(&kvm_count_lock);
}
static void hardware_disable_nolock(void *junk)
{
int cpu = raw_smp_processor_id();
if (!cpumask_test_cpu(cpu, cpus_hardware_enabled))
return;
cpumask_clear_cpu(cpu, cpus_hardware_enabled);
kvm_arch_hardware_disable();
}
static void hardware_disable(void)
{
raw_spin_lock(&kvm_count_lock);
if (kvm_usage_count)
hardware_disable_nolock(NULL);
raw_spin_unlock(&kvm_count_lock);
}
static void hardware_disable_all_nolock(void)
{
BUG_ON(!kvm_usage_count);
kvm_usage_count--;
if (!kvm_usage_count)
on_each_cpu(hardware_disable_nolock, NULL, 1);
}
static void hardware_disable_all(void)
{
raw_spin_lock(&kvm_count_lock);
hardware_disable_all_nolock();
raw_spin_unlock(&kvm_count_lock);
}
static int hardware_enable_all(void)
{
int r = 0;
raw_spin_lock(&kvm_count_lock);
kvm_usage_count++;
if (kvm_usage_count == 1) {
atomic_set(&hardware_enable_failed, 0);
on_each_cpu(hardware_enable_nolock, NULL, 1);
if (atomic_read(&hardware_enable_failed)) {
hardware_disable_all_nolock();
r = -EBUSY;
}
}
raw_spin_unlock(&kvm_count_lock);
return r;
}
static int kvm_cpu_hotplug(struct notifier_block *notifier, unsigned long val,
void *v)
{
val &= ~CPU_TASKS_FROZEN;
switch (val) {
case CPU_DYING:
hardware_disable();
break;
case CPU_STARTING:
hardware_enable();
break;
}
return NOTIFY_OK;
}
static int kvm_reboot(struct notifier_block *notifier, unsigned long val,
void *v)
{
pr_info("kvm: exiting hardware virtualization\n");
kvm_rebooting = true;
on_each_cpu(hardware_disable_nolock, NULL, 1);
return NOTIFY_OK;
}
static void kvm_io_bus_destroy(struct kvm_io_bus *bus)
{
int i;
for (i = 0; i < bus->dev_count; i++) {
struct kvm_io_device *pos = bus->range[i].dev;
kvm_iodevice_destructor(pos);
}
kfree(bus);
}
static inline int kvm_io_bus_cmp(const struct kvm_io_range *r1,
const struct kvm_io_range *r2)
{
if (r1->addr < r2->addr)
return -1;
if (r1->addr + r1->len > r2->addr + r2->len)
return 1;
return 0;
}
static int kvm_io_bus_sort_cmp(const void *p1, const void *p2)
{
return kvm_io_bus_cmp(p1, p2);
}
static int kvm_io_bus_insert_dev(struct kvm_io_bus *bus, struct kvm_io_device *dev,
gpa_t addr, int len)
{
bus->range[bus->dev_count++] = (struct kvm_io_range) {
.addr = addr,
.len = len,
.dev = dev,
};
sort(bus->range, bus->dev_count, sizeof(struct kvm_io_range),
kvm_io_bus_sort_cmp, NULL);
return 0;
}
static int kvm_io_bus_get_first_dev(struct kvm_io_bus *bus,
gpa_t addr, int len)
{
struct kvm_io_range *range, key;
int off;
key = (struct kvm_io_range) {
.addr = addr,
.len = len,
};
range = bsearch(&key, bus->range, bus->dev_count,
sizeof(struct kvm_io_range), kvm_io_bus_sort_cmp);
if (range == NULL)
return -ENOENT;
off = range - bus->range;
while (off > 0 && kvm_io_bus_cmp(&key, &bus->range[off-1]) == 0)
off--;
return off;
}
static int __kvm_io_bus_write(struct kvm_vcpu *vcpu, struct kvm_io_bus *bus,
struct kvm_io_range *range, const void *val)
{
int idx;
idx = kvm_io_bus_get_first_dev(bus, range->addr, range->len);
if (idx < 0)
return -EOPNOTSUPP;
while (idx < bus->dev_count &&
kvm_io_bus_cmp(range, &bus->range[idx]) == 0) {
if (!kvm_iodevice_write(vcpu, bus->range[idx].dev, range->addr,
range->len, val))
return idx;
idx++;
}
return -EOPNOTSUPP;
}
int kvm_io_bus_write(struct kvm_vcpu *vcpu, enum kvm_bus bus_idx, gpa_t addr,
int len, const void *val)
{
struct kvm_io_bus *bus;
struct kvm_io_range range;
int r;
range = (struct kvm_io_range) {
.addr = addr,
.len = len,
};
bus = srcu_dereference(vcpu->kvm->buses[bus_idx], &vcpu->kvm->srcu);
r = __kvm_io_bus_write(vcpu, bus, &range, val);
return r < 0 ? r : 0;
}
int kvm_io_bus_write_cookie(struct kvm_vcpu *vcpu, enum kvm_bus bus_idx,
gpa_t addr, int len, const void *val, long cookie)
{
struct kvm_io_bus *bus;
struct kvm_io_range range;
range = (struct kvm_io_range) {
.addr = addr,
.len = len,
};
bus = srcu_dereference(vcpu->kvm->buses[bus_idx], &vcpu->kvm->srcu);
if ((cookie >= 0) && (cookie < bus->dev_count) &&
(kvm_io_bus_cmp(&range, &bus->range[cookie]) == 0))
if (!kvm_iodevice_write(vcpu, bus->range[cookie].dev, addr, len,
val))
return cookie;
return __kvm_io_bus_write(vcpu, bus, &range, val);
}
static int __kvm_io_bus_read(struct kvm_vcpu *vcpu, struct kvm_io_bus *bus,
struct kvm_io_range *range, void *val)
{
int idx;
idx = kvm_io_bus_get_first_dev(bus, range->addr, range->len);
if (idx < 0)
return -EOPNOTSUPP;
while (idx < bus->dev_count &&
kvm_io_bus_cmp(range, &bus->range[idx]) == 0) {
if (!kvm_iodevice_read(vcpu, bus->range[idx].dev, range->addr,
range->len, val))
return idx;
idx++;
}
return -EOPNOTSUPP;
}
int kvm_io_bus_read(struct kvm_vcpu *vcpu, enum kvm_bus bus_idx, gpa_t addr,
int len, void *val)
{
struct kvm_io_bus *bus;
struct kvm_io_range range;
int r;
range = (struct kvm_io_range) {
.addr = addr,
.len = len,
};
bus = srcu_dereference(vcpu->kvm->buses[bus_idx], &vcpu->kvm->srcu);
r = __kvm_io_bus_read(vcpu, bus, &range, val);
return r < 0 ? r : 0;
}
int kvm_io_bus_register_dev(struct kvm *kvm, enum kvm_bus bus_idx, gpa_t addr,
int len, struct kvm_io_device *dev)
{
struct kvm_io_bus *new_bus, *bus;
bus = kvm->buses[bus_idx];
if (bus->dev_count - bus->ioeventfd_count > NR_IOBUS_DEVS - 1)
return -ENOSPC;
new_bus = kzalloc(sizeof(*bus) + ((bus->dev_count + 1) *
sizeof(struct kvm_io_range)), GFP_KERNEL);
if (!new_bus)
return -ENOMEM;
memcpy(new_bus, bus, sizeof(*bus) + (bus->dev_count *
sizeof(struct kvm_io_range)));
kvm_io_bus_insert_dev(new_bus, dev, addr, len);
rcu_assign_pointer(kvm->buses[bus_idx], new_bus);
synchronize_srcu_expedited(&kvm->srcu);
kfree(bus);
return 0;
}
int kvm_io_bus_unregister_dev(struct kvm *kvm, enum kvm_bus bus_idx,
struct kvm_io_device *dev)
{
int i, r;
struct kvm_io_bus *new_bus, *bus;
bus = kvm->buses[bus_idx];
r = -ENOENT;
for (i = 0; i < bus->dev_count; i++)
if (bus->range[i].dev == dev) {
r = 0;
break;
}
if (r)
return r;
new_bus = kzalloc(sizeof(*bus) + ((bus->dev_count - 1) *
sizeof(struct kvm_io_range)), GFP_KERNEL);
if (!new_bus)
return -ENOMEM;
memcpy(new_bus, bus, sizeof(*bus) + i * sizeof(struct kvm_io_range));
new_bus->dev_count--;
memcpy(new_bus->range + i, bus->range + i + 1,
(new_bus->dev_count - i) * sizeof(struct kvm_io_range));
rcu_assign_pointer(kvm->buses[bus_idx], new_bus);
synchronize_srcu_expedited(&kvm->srcu);
kfree(bus);
return r;
}
static int vm_stat_get(void *_offset, u64 *val)
{
unsigned offset = (long)_offset;
struct kvm *kvm;
*val = 0;
spin_lock(&kvm_lock);
list_for_each_entry(kvm, &vm_list, vm_list)
*val += *(u32 *)((void *)kvm + offset);
spin_unlock(&kvm_lock);
return 0;
}
static int vcpu_stat_get(void *_offset, u64 *val)
{
unsigned offset = (long)_offset;
struct kvm *kvm;
struct kvm_vcpu *vcpu;
int i;
*val = 0;
spin_lock(&kvm_lock);
list_for_each_entry(kvm, &vm_list, vm_list)
kvm_for_each_vcpu(i, vcpu, kvm)
*val += *(u32 *)((void *)vcpu + offset);
spin_unlock(&kvm_lock);
return 0;
}
static int kvm_init_debug(void)
{
int r = -EEXIST;
struct kvm_stats_debugfs_item *p;
kvm_debugfs_dir = debugfs_create_dir("kvm", NULL);
if (kvm_debugfs_dir == NULL)
goto out;
for (p = debugfs_entries; p->name; ++p) {
p->dentry = debugfs_create_file(p->name, 0444, kvm_debugfs_dir,
(void *)(long)p->offset,
stat_fops[p->kind]);
if (p->dentry == NULL)
goto out_dir;
}
return 0;
out_dir:
debugfs_remove_recursive(kvm_debugfs_dir);
out:
return r;
}
static void kvm_exit_debug(void)
{
struct kvm_stats_debugfs_item *p;
for (p = debugfs_entries; p->name; ++p)
debugfs_remove(p->dentry);
debugfs_remove(kvm_debugfs_dir);
}
static int kvm_suspend(void)
{
if (kvm_usage_count)
hardware_disable_nolock(NULL);
return 0;
}
static void kvm_resume(void)
{
if (kvm_usage_count) {
WARN_ON(raw_spin_is_locked(&kvm_count_lock));
hardware_enable_nolock(NULL);
}
}
static inline
struct kvm_vcpu *preempt_notifier_to_vcpu(struct preempt_notifier *pn)
{
return container_of(pn, struct kvm_vcpu, preempt_notifier);
}
static void kvm_sched_in(struct preempt_notifier *pn, int cpu)
{
struct kvm_vcpu *vcpu = preempt_notifier_to_vcpu(pn);
if (vcpu->preempted)
vcpu->preempted = false;
kvm_arch_sched_in(vcpu, cpu);
kvm_arch_vcpu_load(vcpu, cpu);
}
static void kvm_sched_out(struct preempt_notifier *pn,
struct task_struct *next)
{
struct kvm_vcpu *vcpu = preempt_notifier_to_vcpu(pn);
if (current->state == TASK_RUNNING)
vcpu->preempted = true;
kvm_arch_vcpu_put(vcpu);
}
int kvm_init(void *opaque, unsigned vcpu_size, unsigned vcpu_align,
struct module *module)
{
int r;
int cpu;
r = kvm_arch_init(opaque);
if (r)
goto out_fail;
r = kvm_irqfd_init();
if (r)
goto out_irqfd;
if (!zalloc_cpumask_var(&cpus_hardware_enabled, GFP_KERNEL)) {
r = -ENOMEM;
goto out_free_0;
}
r = kvm_arch_hardware_setup();
if (r < 0)
goto out_free_0a;
for_each_online_cpu(cpu) {
smp_call_function_single(cpu,
kvm_arch_check_processor_compat,
&r, 1);
if (r < 0)
goto out_free_1;
}
r = register_cpu_notifier(&kvm_cpu_notifier);
if (r)
goto out_free_2;
register_reboot_notifier(&kvm_reboot_notifier);
if (!vcpu_align)
vcpu_align = __alignof__(struct kvm_vcpu);
kvm_vcpu_cache = kmem_cache_create("kvm_vcpu", vcpu_size, vcpu_align,
0, NULL);
if (!kvm_vcpu_cache) {
r = -ENOMEM;
goto out_free_3;
}
r = kvm_async_pf_init();
if (r)
goto out_free;
kvm_chardev_ops.owner = module;
kvm_vm_fops.owner = module;
kvm_vcpu_fops.owner = module;
r = misc_register(&kvm_dev);
if (r) {
pr_err("kvm: misc device register failed\n");
goto out_unreg;
}
register_syscore_ops(&kvm_syscore_ops);
kvm_preempt_ops.sched_in = kvm_sched_in;
kvm_preempt_ops.sched_out = kvm_sched_out;
r = kvm_init_debug();
if (r) {
pr_err("kvm: create debugfs files failed\n");
goto out_undebugfs;
}
r = kvm_vfio_ops_init();
WARN_ON(r);
return 0;
out_undebugfs:
unregister_syscore_ops(&kvm_syscore_ops);
misc_deregister(&kvm_dev);
out_unreg:
kvm_async_pf_deinit();
out_free:
kmem_cache_destroy(kvm_vcpu_cache);
out_free_3:
unregister_reboot_notifier(&kvm_reboot_notifier);
unregister_cpu_notifier(&kvm_cpu_notifier);
out_free_2:
out_free_1:
kvm_arch_hardware_unsetup();
out_free_0a:
free_cpumask_var(cpus_hardware_enabled);
out_free_0:
kvm_irqfd_exit();
out_irqfd:
kvm_arch_exit();
out_fail:
return r;
}
void kvm_exit(void)
{
kvm_exit_debug();
misc_deregister(&kvm_dev);
kmem_cache_destroy(kvm_vcpu_cache);
kvm_async_pf_deinit();
unregister_syscore_ops(&kvm_syscore_ops);
unregister_reboot_notifier(&kvm_reboot_notifier);
unregister_cpu_notifier(&kvm_cpu_notifier);
on_each_cpu(hardware_disable_nolock, NULL, 1);
kvm_arch_hardware_unsetup();
kvm_arch_exit();
kvm_irqfd_exit();
free_cpumask_var(cpus_hardware_enabled);
kvm_vfio_ops_exit();
}
