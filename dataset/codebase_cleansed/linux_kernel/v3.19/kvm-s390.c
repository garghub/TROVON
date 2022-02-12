int test_vfacility(unsigned long nr)
{
return __test_facility(nr, (void *) vfacilities);
}
int kvm_arch_hardware_enable(void)
{
return 0;
}
int kvm_arch_hardware_setup(void)
{
gmap_notifier.notifier_call = kvm_gmap_notifier;
gmap_register_ipte_notifier(&gmap_notifier);
return 0;
}
void kvm_arch_hardware_unsetup(void)
{
gmap_unregister_ipte_notifier(&gmap_notifier);
}
int kvm_arch_init(void *opaque)
{
return kvm_register_device_ops(&kvm_flic_ops, KVM_DEV_TYPE_FLIC);
}
long kvm_arch_dev_ioctl(struct file *filp,
unsigned int ioctl, unsigned long arg)
{
if (ioctl == KVM_S390_ENABLE_SIE)
return s390_enable_sie();
return -EINVAL;
}
int kvm_vm_ioctl_check_extension(struct kvm *kvm, long ext)
{
int r;
switch (ext) {
case KVM_CAP_S390_PSW:
case KVM_CAP_S390_GMAP:
case KVM_CAP_SYNC_MMU:
#ifdef CONFIG_KVM_S390_UCONTROL
case KVM_CAP_S390_UCONTROL:
#endif
case KVM_CAP_ASYNC_PF:
case KVM_CAP_SYNC_REGS:
case KVM_CAP_ONE_REG:
case KVM_CAP_ENABLE_CAP:
case KVM_CAP_S390_CSS_SUPPORT:
case KVM_CAP_IRQFD:
case KVM_CAP_IOEVENTFD:
case KVM_CAP_DEVICE_CTRL:
case KVM_CAP_ENABLE_CAP_VM:
case KVM_CAP_S390_IRQCHIP:
case KVM_CAP_VM_ATTRIBUTES:
case KVM_CAP_MP_STATE:
r = 1;
break;
case KVM_CAP_NR_VCPUS:
case KVM_CAP_MAX_VCPUS:
r = KVM_MAX_VCPUS;
break;
case KVM_CAP_NR_MEMSLOTS:
r = KVM_USER_MEM_SLOTS;
break;
case KVM_CAP_S390_COW:
r = MACHINE_HAS_ESOP;
break;
default:
r = 0;
}
return r;
}
static void kvm_s390_sync_dirty_log(struct kvm *kvm,
struct kvm_memory_slot *memslot)
{
gfn_t cur_gfn, last_gfn;
unsigned long address;
struct gmap *gmap = kvm->arch.gmap;
down_read(&gmap->mm->mmap_sem);
last_gfn = memslot->base_gfn + memslot->npages;
for (cur_gfn = memslot->base_gfn; cur_gfn <= last_gfn; cur_gfn++) {
address = gfn_to_hva_memslot(memslot, cur_gfn);
if (gmap_test_and_clear_dirty(address, gmap))
mark_page_dirty(kvm, cur_gfn);
}
up_read(&gmap->mm->mmap_sem);
}
int kvm_vm_ioctl_get_dirty_log(struct kvm *kvm,
struct kvm_dirty_log *log)
{
int r;
unsigned long n;
struct kvm_memory_slot *memslot;
int is_dirty = 0;
mutex_lock(&kvm->slots_lock);
r = -EINVAL;
if (log->slot >= KVM_USER_MEM_SLOTS)
goto out;
memslot = id_to_memslot(kvm->memslots, log->slot);
r = -ENOENT;
if (!memslot->dirty_bitmap)
goto out;
kvm_s390_sync_dirty_log(kvm, memslot);
r = kvm_get_dirty_log(kvm, log, &is_dirty);
if (r)
goto out;
if (is_dirty) {
n = kvm_dirty_bitmap_bytes(memslot);
memset(memslot->dirty_bitmap, 0, n);
}
r = 0;
out:
mutex_unlock(&kvm->slots_lock);
return r;
}
static int kvm_vm_ioctl_enable_cap(struct kvm *kvm, struct kvm_enable_cap *cap)
{
int r;
if (cap->flags)
return -EINVAL;
switch (cap->cap) {
case KVM_CAP_S390_IRQCHIP:
kvm->arch.use_irqchip = 1;
r = 0;
break;
default:
r = -EINVAL;
break;
}
return r;
}
static int kvm_s390_mem_control(struct kvm *kvm, struct kvm_device_attr *attr)
{
int ret;
unsigned int idx;
switch (attr->attr) {
case KVM_S390_VM_MEM_ENABLE_CMMA:
ret = -EBUSY;
mutex_lock(&kvm->lock);
if (atomic_read(&kvm->online_vcpus) == 0) {
kvm->arch.use_cmma = 1;
ret = 0;
}
mutex_unlock(&kvm->lock);
break;
case KVM_S390_VM_MEM_CLR_CMMA:
mutex_lock(&kvm->lock);
idx = srcu_read_lock(&kvm->srcu);
s390_reset_cmma(kvm->arch.gmap->mm);
srcu_read_unlock(&kvm->srcu, idx);
mutex_unlock(&kvm->lock);
ret = 0;
break;
default:
ret = -ENXIO;
break;
}
return ret;
}
static int kvm_s390_vm_set_attr(struct kvm *kvm, struct kvm_device_attr *attr)
{
int ret;
switch (attr->group) {
case KVM_S390_VM_MEM_CTRL:
ret = kvm_s390_mem_control(kvm, attr);
break;
default:
ret = -ENXIO;
break;
}
return ret;
}
static int kvm_s390_vm_get_attr(struct kvm *kvm, struct kvm_device_attr *attr)
{
return -ENXIO;
}
static int kvm_s390_vm_has_attr(struct kvm *kvm, struct kvm_device_attr *attr)
{
int ret;
switch (attr->group) {
case KVM_S390_VM_MEM_CTRL:
switch (attr->attr) {
case KVM_S390_VM_MEM_ENABLE_CMMA:
case KVM_S390_VM_MEM_CLR_CMMA:
ret = 0;
break;
default:
ret = -ENXIO;
break;
}
break;
default:
ret = -ENXIO;
break;
}
return ret;
}
long kvm_arch_vm_ioctl(struct file *filp,
unsigned int ioctl, unsigned long arg)
{
struct kvm *kvm = filp->private_data;
void __user *argp = (void __user *)arg;
struct kvm_device_attr attr;
int r;
switch (ioctl) {
case KVM_S390_INTERRUPT: {
struct kvm_s390_interrupt s390int;
r = -EFAULT;
if (copy_from_user(&s390int, argp, sizeof(s390int)))
break;
r = kvm_s390_inject_vm(kvm, &s390int);
break;
}
case KVM_ENABLE_CAP: {
struct kvm_enable_cap cap;
r = -EFAULT;
if (copy_from_user(&cap, argp, sizeof(cap)))
break;
r = kvm_vm_ioctl_enable_cap(kvm, &cap);
break;
}
case KVM_CREATE_IRQCHIP: {
struct kvm_irq_routing_entry routing;
r = -EINVAL;
if (kvm->arch.use_irqchip) {
memset(&routing, 0, sizeof(routing));
kvm_set_irq_routing(kvm, &routing, 0, 0);
r = 0;
}
break;
}
case KVM_SET_DEVICE_ATTR: {
r = -EFAULT;
if (copy_from_user(&attr, (void __user *)arg, sizeof(attr)))
break;
r = kvm_s390_vm_set_attr(kvm, &attr);
break;
}
case KVM_GET_DEVICE_ATTR: {
r = -EFAULT;
if (copy_from_user(&attr, (void __user *)arg, sizeof(attr)))
break;
r = kvm_s390_vm_get_attr(kvm, &attr);
break;
}
case KVM_HAS_DEVICE_ATTR: {
r = -EFAULT;
if (copy_from_user(&attr, (void __user *)arg, sizeof(attr)))
break;
r = kvm_s390_vm_has_attr(kvm, &attr);
break;
}
default:
r = -ENOTTY;
}
return r;
}
static int kvm_s390_crypto_init(struct kvm *kvm)
{
if (!test_vfacility(76))
return 0;
kvm->arch.crypto.crycb = kzalloc(sizeof(*kvm->arch.crypto.crycb),
GFP_KERNEL | GFP_DMA);
if (!kvm->arch.crypto.crycb)
return -ENOMEM;
kvm->arch.crypto.crycbd = (__u32) (unsigned long) kvm->arch.crypto.crycb |
CRYCB_FORMAT1;
return 0;
}
int kvm_arch_init_vm(struct kvm *kvm, unsigned long type)
{
int rc;
char debug_name[16];
static unsigned long sca_offset;
rc = -EINVAL;
#ifdef CONFIG_KVM_S390_UCONTROL
if (type & ~KVM_VM_S390_UCONTROL)
goto out_err;
if ((type & KVM_VM_S390_UCONTROL) && (!capable(CAP_SYS_ADMIN)))
goto out_err;
#else
if (type)
goto out_err;
#endif
rc = s390_enable_sie();
if (rc)
goto out_err;
rc = -ENOMEM;
kvm->arch.sca = (struct sca_block *) get_zeroed_page(GFP_KERNEL);
if (!kvm->arch.sca)
goto out_err;
spin_lock(&kvm_lock);
sca_offset = (sca_offset + 16) & 0x7f0;
kvm->arch.sca = (struct sca_block *) ((char *) kvm->arch.sca + sca_offset);
spin_unlock(&kvm_lock);
sprintf(debug_name, "kvm-%u", current->pid);
kvm->arch.dbf = debug_register(debug_name, 8, 2, 8 * sizeof(long));
if (!kvm->arch.dbf)
goto out_nodbf;
if (kvm_s390_crypto_init(kvm) < 0)
goto out_crypto;
spin_lock_init(&kvm->arch.float_int.lock);
INIT_LIST_HEAD(&kvm->arch.float_int.list);
init_waitqueue_head(&kvm->arch.ipte_wq);
mutex_init(&kvm->arch.ipte_mutex);
debug_register_view(kvm->arch.dbf, &debug_sprintf_view);
VM_EVENT(kvm, 3, "%s", "vm created");
if (type & KVM_VM_S390_UCONTROL) {
kvm->arch.gmap = NULL;
} else {
kvm->arch.gmap = gmap_alloc(current->mm, (1UL << 44) - 1);
if (!kvm->arch.gmap)
goto out_nogmap;
kvm->arch.gmap->private = kvm;
kvm->arch.gmap->pfault_enabled = 0;
}
kvm->arch.css_support = 0;
kvm->arch.use_irqchip = 0;
spin_lock_init(&kvm->arch.start_stop_lock);
return 0;
out_nogmap:
kfree(kvm->arch.crypto.crycb);
out_crypto:
debug_unregister(kvm->arch.dbf);
out_nodbf:
free_page((unsigned long)(kvm->arch.sca));
out_err:
return rc;
}
void kvm_arch_vcpu_destroy(struct kvm_vcpu *vcpu)
{
VCPU_EVENT(vcpu, 3, "%s", "free cpu");
trace_kvm_s390_destroy_vcpu(vcpu->vcpu_id);
kvm_s390_clear_local_irqs(vcpu);
kvm_clear_async_pf_completion_queue(vcpu);
if (!kvm_is_ucontrol(vcpu->kvm)) {
clear_bit(63 - vcpu->vcpu_id,
(unsigned long *) &vcpu->kvm->arch.sca->mcn);
if (vcpu->kvm->arch.sca->cpu[vcpu->vcpu_id].sda ==
(__u64) vcpu->arch.sie_block)
vcpu->kvm->arch.sca->cpu[vcpu->vcpu_id].sda = 0;
}
smp_mb();
if (kvm_is_ucontrol(vcpu->kvm))
gmap_free(vcpu->arch.gmap);
if (kvm_s390_cmma_enabled(vcpu->kvm))
kvm_s390_vcpu_unsetup_cmma(vcpu);
free_page((unsigned long)(vcpu->arch.sie_block));
kvm_vcpu_uninit(vcpu);
kmem_cache_free(kvm_vcpu_cache, vcpu);
}
static void kvm_free_vcpus(struct kvm *kvm)
{
unsigned int i;
struct kvm_vcpu *vcpu;
kvm_for_each_vcpu(i, vcpu, kvm)
kvm_arch_vcpu_destroy(vcpu);
mutex_lock(&kvm->lock);
for (i = 0; i < atomic_read(&kvm->online_vcpus); i++)
kvm->vcpus[i] = NULL;
atomic_set(&kvm->online_vcpus, 0);
mutex_unlock(&kvm->lock);
}
void kvm_arch_destroy_vm(struct kvm *kvm)
{
kvm_free_vcpus(kvm);
free_page((unsigned long)(kvm->arch.sca));
debug_unregister(kvm->arch.dbf);
kfree(kvm->arch.crypto.crycb);
if (!kvm_is_ucontrol(kvm))
gmap_free(kvm->arch.gmap);
kvm_s390_destroy_adapters(kvm);
kvm_s390_clear_float_irqs(kvm);
}
int kvm_arch_vcpu_init(struct kvm_vcpu *vcpu)
{
vcpu->arch.pfault_token = KVM_S390_PFAULT_TOKEN_INVALID;
kvm_clear_async_pf_completion_queue(vcpu);
if (kvm_is_ucontrol(vcpu->kvm)) {
vcpu->arch.gmap = gmap_alloc(current->mm, -1UL);
if (!vcpu->arch.gmap)
return -ENOMEM;
vcpu->arch.gmap->private = vcpu->kvm;
return 0;
}
vcpu->arch.gmap = vcpu->kvm->arch.gmap;
vcpu->run->kvm_valid_regs = KVM_SYNC_PREFIX |
KVM_SYNC_GPRS |
KVM_SYNC_ACRS |
KVM_SYNC_CRS |
KVM_SYNC_ARCH0 |
KVM_SYNC_PFAULT;
return 0;
}
void kvm_arch_vcpu_load(struct kvm_vcpu *vcpu, int cpu)
{
save_fp_ctl(&vcpu->arch.host_fpregs.fpc);
save_fp_regs(vcpu->arch.host_fpregs.fprs);
save_access_regs(vcpu->arch.host_acrs);
restore_fp_ctl(&vcpu->arch.guest_fpregs.fpc);
restore_fp_regs(vcpu->arch.guest_fpregs.fprs);
restore_access_regs(vcpu->run->s.regs.acrs);
gmap_enable(vcpu->arch.gmap);
atomic_set_mask(CPUSTAT_RUNNING, &vcpu->arch.sie_block->cpuflags);
}
void kvm_arch_vcpu_put(struct kvm_vcpu *vcpu)
{
atomic_clear_mask(CPUSTAT_RUNNING, &vcpu->arch.sie_block->cpuflags);
gmap_disable(vcpu->arch.gmap);
save_fp_ctl(&vcpu->arch.guest_fpregs.fpc);
save_fp_regs(vcpu->arch.guest_fpregs.fprs);
save_access_regs(vcpu->run->s.regs.acrs);
restore_fp_ctl(&vcpu->arch.host_fpregs.fpc);
restore_fp_regs(vcpu->arch.host_fpregs.fprs);
restore_access_regs(vcpu->arch.host_acrs);
}
static void kvm_s390_vcpu_initial_reset(struct kvm_vcpu *vcpu)
{
vcpu->arch.sie_block->gpsw.mask = 0UL;
vcpu->arch.sie_block->gpsw.addr = 0UL;
kvm_s390_set_prefix(vcpu, 0);
vcpu->arch.sie_block->cputm = 0UL;
vcpu->arch.sie_block->ckc = 0UL;
vcpu->arch.sie_block->todpr = 0;
memset(vcpu->arch.sie_block->gcr, 0, 16 * sizeof(__u64));
vcpu->arch.sie_block->gcr[0] = 0xE0UL;
vcpu->arch.sie_block->gcr[14] = 0xC2000000UL;
vcpu->arch.guest_fpregs.fpc = 0;
asm volatile("lfpc %0" : : "Q" (vcpu->arch.guest_fpregs.fpc));
vcpu->arch.sie_block->gbea = 1;
vcpu->arch.sie_block->pp = 0;
vcpu->arch.pfault_token = KVM_S390_PFAULT_TOKEN_INVALID;
kvm_clear_async_pf_completion_queue(vcpu);
if (!kvm_s390_user_cpu_state_ctrl(vcpu->kvm))
kvm_s390_vcpu_stop(vcpu);
kvm_s390_clear_local_irqs(vcpu);
}
int kvm_arch_vcpu_postcreate(struct kvm_vcpu *vcpu)
{
return 0;
}
static void kvm_s390_vcpu_crypto_setup(struct kvm_vcpu *vcpu)
{
if (!test_vfacility(76))
return;
vcpu->arch.sie_block->crycbd = vcpu->kvm->arch.crypto.crycbd;
}
void kvm_s390_vcpu_unsetup_cmma(struct kvm_vcpu *vcpu)
{
free_page(vcpu->arch.sie_block->cbrlo);
vcpu->arch.sie_block->cbrlo = 0;
}
int kvm_s390_vcpu_setup_cmma(struct kvm_vcpu *vcpu)
{
vcpu->arch.sie_block->cbrlo = get_zeroed_page(GFP_KERNEL);
if (!vcpu->arch.sie_block->cbrlo)
return -ENOMEM;
vcpu->arch.sie_block->ecb2 |= 0x80;
vcpu->arch.sie_block->ecb2 &= ~0x08;
return 0;
}
int kvm_arch_vcpu_setup(struct kvm_vcpu *vcpu)
{
int rc = 0;
atomic_set(&vcpu->arch.sie_block->cpuflags, CPUSTAT_ZARCH |
CPUSTAT_SM |
CPUSTAT_STOPPED |
CPUSTAT_GED);
vcpu->arch.sie_block->ecb = 6;
if (test_vfacility(50) && test_vfacility(73))
vcpu->arch.sie_block->ecb |= 0x10;
vcpu->arch.sie_block->ecb2 = 8;
vcpu->arch.sie_block->eca = 0xD1002000U;
if (sclp_has_siif())
vcpu->arch.sie_block->eca |= 1;
vcpu->arch.sie_block->fac = (int) (long) vfacilities;
vcpu->arch.sie_block->ictl |= ICTL_ISKE | ICTL_SSKE | ICTL_RRBE |
ICTL_TPROT;
if (kvm_s390_cmma_enabled(vcpu->kvm)) {
rc = kvm_s390_vcpu_setup_cmma(vcpu);
if (rc)
return rc;
}
hrtimer_init(&vcpu->arch.ckc_timer, CLOCK_REALTIME, HRTIMER_MODE_ABS);
vcpu->arch.ckc_timer.function = kvm_s390_idle_wakeup;
get_cpu_id(&vcpu->arch.cpu_id);
vcpu->arch.cpu_id.version = 0xff;
kvm_s390_vcpu_crypto_setup(vcpu);
return rc;
}
struct kvm_vcpu *kvm_arch_vcpu_create(struct kvm *kvm,
unsigned int id)
{
struct kvm_vcpu *vcpu;
struct sie_page *sie_page;
int rc = -EINVAL;
if (id >= KVM_MAX_VCPUS)
goto out;
rc = -ENOMEM;
vcpu = kmem_cache_zalloc(kvm_vcpu_cache, GFP_KERNEL);
if (!vcpu)
goto out;
sie_page = (struct sie_page *) get_zeroed_page(GFP_KERNEL);
if (!sie_page)
goto out_free_cpu;
vcpu->arch.sie_block = &sie_page->sie_block;
vcpu->arch.sie_block->itdba = (unsigned long) &sie_page->itdb;
vcpu->arch.sie_block->icpua = id;
if (!kvm_is_ucontrol(kvm)) {
if (!kvm->arch.sca) {
WARN_ON_ONCE(1);
goto out_free_cpu;
}
if (!kvm->arch.sca->cpu[id].sda)
kvm->arch.sca->cpu[id].sda =
(__u64) vcpu->arch.sie_block;
vcpu->arch.sie_block->scaoh =
(__u32)(((__u64)kvm->arch.sca) >> 32);
vcpu->arch.sie_block->scaol = (__u32)(__u64)kvm->arch.sca;
set_bit(63 - id, (unsigned long *) &kvm->arch.sca->mcn);
}
spin_lock_init(&vcpu->arch.local_int.lock);
vcpu->arch.local_int.float_int = &kvm->arch.float_int;
vcpu->arch.local_int.wq = &vcpu->wq;
vcpu->arch.local_int.cpuflags = &vcpu->arch.sie_block->cpuflags;
rc = kvm_vcpu_init(vcpu, kvm, id);
if (rc)
goto out_free_sie_block;
VM_EVENT(kvm, 3, "create cpu %d at %p, sie block at %p", id, vcpu,
vcpu->arch.sie_block);
trace_kvm_s390_create_vcpu(id, vcpu, vcpu->arch.sie_block);
return vcpu;
out_free_sie_block:
free_page((unsigned long)(vcpu->arch.sie_block));
out_free_cpu:
kmem_cache_free(kvm_vcpu_cache, vcpu);
out:
return ERR_PTR(rc);
}
int kvm_arch_vcpu_runnable(struct kvm_vcpu *vcpu)
{
return kvm_cpu_has_interrupt(vcpu);
}
void s390_vcpu_block(struct kvm_vcpu *vcpu)
{
atomic_set_mask(PROG_BLOCK_SIE, &vcpu->arch.sie_block->prog20);
}
void s390_vcpu_unblock(struct kvm_vcpu *vcpu)
{
atomic_clear_mask(PROG_BLOCK_SIE, &vcpu->arch.sie_block->prog20);
}
void exit_sie(struct kvm_vcpu *vcpu)
{
atomic_set_mask(CPUSTAT_STOP_INT, &vcpu->arch.sie_block->cpuflags);
while (vcpu->arch.sie_block->prog0c & PROG_IN_SIE)
cpu_relax();
}
void exit_sie_sync(struct kvm_vcpu *vcpu)
{
s390_vcpu_block(vcpu);
exit_sie(vcpu);
}
static void kvm_gmap_notifier(struct gmap *gmap, unsigned long address)
{
int i;
struct kvm *kvm = gmap->private;
struct kvm_vcpu *vcpu;
kvm_for_each_vcpu(i, vcpu, kvm) {
if (kvm_s390_get_prefix(vcpu) == (address & ~0x1000UL)) {
VCPU_EVENT(vcpu, 2, "gmap notifier for %lx", address);
kvm_make_request(KVM_REQ_MMU_RELOAD, vcpu);
exit_sie_sync(vcpu);
}
}
}
int kvm_arch_vcpu_should_kick(struct kvm_vcpu *vcpu)
{
BUG();
return 0;
}
static int kvm_arch_vcpu_ioctl_get_one_reg(struct kvm_vcpu *vcpu,
struct kvm_one_reg *reg)
{
int r = -EINVAL;
switch (reg->id) {
case KVM_REG_S390_TODPR:
r = put_user(vcpu->arch.sie_block->todpr,
(u32 __user *)reg->addr);
break;
case KVM_REG_S390_EPOCHDIFF:
r = put_user(vcpu->arch.sie_block->epoch,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_CPU_TIMER:
r = put_user(vcpu->arch.sie_block->cputm,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_CLOCK_COMP:
r = put_user(vcpu->arch.sie_block->ckc,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_PFTOKEN:
r = put_user(vcpu->arch.pfault_token,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_PFCOMPARE:
r = put_user(vcpu->arch.pfault_compare,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_PFSELECT:
r = put_user(vcpu->arch.pfault_select,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_PP:
r = put_user(vcpu->arch.sie_block->pp,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_GBEA:
r = put_user(vcpu->arch.sie_block->gbea,
(u64 __user *)reg->addr);
break;
default:
break;
}
return r;
}
static int kvm_arch_vcpu_ioctl_set_one_reg(struct kvm_vcpu *vcpu,
struct kvm_one_reg *reg)
{
int r = -EINVAL;
switch (reg->id) {
case KVM_REG_S390_TODPR:
r = get_user(vcpu->arch.sie_block->todpr,
(u32 __user *)reg->addr);
break;
case KVM_REG_S390_EPOCHDIFF:
r = get_user(vcpu->arch.sie_block->epoch,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_CPU_TIMER:
r = get_user(vcpu->arch.sie_block->cputm,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_CLOCK_COMP:
r = get_user(vcpu->arch.sie_block->ckc,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_PFTOKEN:
r = get_user(vcpu->arch.pfault_token,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_PFCOMPARE:
r = get_user(vcpu->arch.pfault_compare,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_PFSELECT:
r = get_user(vcpu->arch.pfault_select,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_PP:
r = get_user(vcpu->arch.sie_block->pp,
(u64 __user *)reg->addr);
break;
case KVM_REG_S390_GBEA:
r = get_user(vcpu->arch.sie_block->gbea,
(u64 __user *)reg->addr);
break;
default:
break;
}
return r;
}
static int kvm_arch_vcpu_ioctl_initial_reset(struct kvm_vcpu *vcpu)
{
kvm_s390_vcpu_initial_reset(vcpu);
return 0;
}
int kvm_arch_vcpu_ioctl_set_regs(struct kvm_vcpu *vcpu, struct kvm_regs *regs)
{
memcpy(&vcpu->run->s.regs.gprs, &regs->gprs, sizeof(regs->gprs));
return 0;
}
int kvm_arch_vcpu_ioctl_get_regs(struct kvm_vcpu *vcpu, struct kvm_regs *regs)
{
memcpy(&regs->gprs, &vcpu->run->s.regs.gprs, sizeof(regs->gprs));
return 0;
}
int kvm_arch_vcpu_ioctl_set_sregs(struct kvm_vcpu *vcpu,
struct kvm_sregs *sregs)
{
memcpy(&vcpu->run->s.regs.acrs, &sregs->acrs, sizeof(sregs->acrs));
memcpy(&vcpu->arch.sie_block->gcr, &sregs->crs, sizeof(sregs->crs));
restore_access_regs(vcpu->run->s.regs.acrs);
return 0;
}
int kvm_arch_vcpu_ioctl_get_sregs(struct kvm_vcpu *vcpu,
struct kvm_sregs *sregs)
{
memcpy(&sregs->acrs, &vcpu->run->s.regs.acrs, sizeof(sregs->acrs));
memcpy(&sregs->crs, &vcpu->arch.sie_block->gcr, sizeof(sregs->crs));
return 0;
}
int kvm_arch_vcpu_ioctl_set_fpu(struct kvm_vcpu *vcpu, struct kvm_fpu *fpu)
{
if (test_fp_ctl(fpu->fpc))
return -EINVAL;
memcpy(&vcpu->arch.guest_fpregs.fprs, &fpu->fprs, sizeof(fpu->fprs));
vcpu->arch.guest_fpregs.fpc = fpu->fpc;
restore_fp_ctl(&vcpu->arch.guest_fpregs.fpc);
restore_fp_regs(vcpu->arch.guest_fpregs.fprs);
return 0;
}
int kvm_arch_vcpu_ioctl_get_fpu(struct kvm_vcpu *vcpu, struct kvm_fpu *fpu)
{
memcpy(&fpu->fprs, &vcpu->arch.guest_fpregs.fprs, sizeof(fpu->fprs));
fpu->fpc = vcpu->arch.guest_fpregs.fpc;
return 0;
}
static int kvm_arch_vcpu_ioctl_set_initial_psw(struct kvm_vcpu *vcpu, psw_t psw)
{
int rc = 0;
if (!is_vcpu_stopped(vcpu))
rc = -EBUSY;
else {
vcpu->run->psw_mask = psw.mask;
vcpu->run->psw_addr = psw.addr;
}
return rc;
}
int kvm_arch_vcpu_ioctl_translate(struct kvm_vcpu *vcpu,
struct kvm_translation *tr)
{
return -EINVAL;
}
int kvm_arch_vcpu_ioctl_set_guest_debug(struct kvm_vcpu *vcpu,
struct kvm_guest_debug *dbg)
{
int rc = 0;
vcpu->guest_debug = 0;
kvm_s390_clear_bp_data(vcpu);
if (dbg->control & ~VALID_GUESTDBG_FLAGS)
return -EINVAL;
if (dbg->control & KVM_GUESTDBG_ENABLE) {
vcpu->guest_debug = dbg->control;
atomic_set_mask(CPUSTAT_P, &vcpu->arch.sie_block->cpuflags);
if (dbg->control & KVM_GUESTDBG_USE_HW_BP)
rc = kvm_s390_import_bp_data(vcpu, dbg);
} else {
atomic_clear_mask(CPUSTAT_P, &vcpu->arch.sie_block->cpuflags);
vcpu->arch.guestdbg.last_bp = 0;
}
if (rc) {
vcpu->guest_debug = 0;
kvm_s390_clear_bp_data(vcpu);
atomic_clear_mask(CPUSTAT_P, &vcpu->arch.sie_block->cpuflags);
}
return rc;
}
int kvm_arch_vcpu_ioctl_get_mpstate(struct kvm_vcpu *vcpu,
struct kvm_mp_state *mp_state)
{
return is_vcpu_stopped(vcpu) ? KVM_MP_STATE_STOPPED :
KVM_MP_STATE_OPERATING;
}
int kvm_arch_vcpu_ioctl_set_mpstate(struct kvm_vcpu *vcpu,
struct kvm_mp_state *mp_state)
{
int rc = 0;
vcpu->kvm->arch.user_cpu_state_ctrl = 1;
switch (mp_state->mp_state) {
case KVM_MP_STATE_STOPPED:
kvm_s390_vcpu_stop(vcpu);
break;
case KVM_MP_STATE_OPERATING:
kvm_s390_vcpu_start(vcpu);
break;
case KVM_MP_STATE_LOAD:
case KVM_MP_STATE_CHECK_STOP:
default:
rc = -ENXIO;
}
return rc;
}
bool kvm_s390_cmma_enabled(struct kvm *kvm)
{
if (!MACHINE_IS_LPAR)
return false;
if (!MACHINE_HAS_EDAT1)
return false;
if (!kvm->arch.use_cmma)
return false;
return true;
}
static bool ibs_enabled(struct kvm_vcpu *vcpu)
{
return atomic_read(&vcpu->arch.sie_block->cpuflags) & CPUSTAT_IBS;
}
static int kvm_s390_handle_requests(struct kvm_vcpu *vcpu)
{
retry:
s390_vcpu_unblock(vcpu);
if (kvm_check_request(KVM_REQ_MMU_RELOAD, vcpu)) {
int rc;
rc = gmap_ipte_notify(vcpu->arch.gmap,
kvm_s390_get_prefix(vcpu),
PAGE_SIZE * 2);
if (rc)
return rc;
goto retry;
}
if (kvm_check_request(KVM_REQ_TLB_FLUSH, vcpu)) {
vcpu->arch.sie_block->ihcpu = 0xffff;
goto retry;
}
if (kvm_check_request(KVM_REQ_ENABLE_IBS, vcpu)) {
if (!ibs_enabled(vcpu)) {
trace_kvm_s390_enable_disable_ibs(vcpu->vcpu_id, 1);
atomic_set_mask(CPUSTAT_IBS,
&vcpu->arch.sie_block->cpuflags);
}
goto retry;
}
if (kvm_check_request(KVM_REQ_DISABLE_IBS, vcpu)) {
if (ibs_enabled(vcpu)) {
trace_kvm_s390_enable_disable_ibs(vcpu->vcpu_id, 0);
atomic_clear_mask(CPUSTAT_IBS,
&vcpu->arch.sie_block->cpuflags);
}
goto retry;
}
clear_bit(KVM_REQ_UNHALT, &vcpu->requests);
return 0;
}
long kvm_arch_fault_in_page(struct kvm_vcpu *vcpu, gpa_t gpa, int writable)
{
return gmap_fault(vcpu->arch.gmap, gpa,
writable ? FAULT_FLAG_WRITE : 0);
}
static void __kvm_inject_pfault_token(struct kvm_vcpu *vcpu, bool start_token,
unsigned long token)
{
struct kvm_s390_interrupt inti;
struct kvm_s390_irq irq;
if (start_token) {
irq.u.ext.ext_params2 = token;
irq.type = KVM_S390_INT_PFAULT_INIT;
WARN_ON_ONCE(kvm_s390_inject_vcpu(vcpu, &irq));
} else {
inti.type = KVM_S390_INT_PFAULT_DONE;
inti.parm64 = token;
WARN_ON_ONCE(kvm_s390_inject_vm(vcpu->kvm, &inti));
}
}
void kvm_arch_async_page_not_present(struct kvm_vcpu *vcpu,
struct kvm_async_pf *work)
{
trace_kvm_s390_pfault_init(vcpu, work->arch.pfault_token);
__kvm_inject_pfault_token(vcpu, true, work->arch.pfault_token);
}
void kvm_arch_async_page_present(struct kvm_vcpu *vcpu,
struct kvm_async_pf *work)
{
trace_kvm_s390_pfault_done(vcpu, work->arch.pfault_token);
__kvm_inject_pfault_token(vcpu, false, work->arch.pfault_token);
}
void kvm_arch_async_page_ready(struct kvm_vcpu *vcpu,
struct kvm_async_pf *work)
{
}
bool kvm_arch_can_inject_async_page_present(struct kvm_vcpu *vcpu)
{
return true;
}
static int kvm_arch_setup_async_pf(struct kvm_vcpu *vcpu)
{
hva_t hva;
struct kvm_arch_async_pf arch;
int rc;
if (vcpu->arch.pfault_token == KVM_S390_PFAULT_TOKEN_INVALID)
return 0;
if ((vcpu->arch.sie_block->gpsw.mask & vcpu->arch.pfault_select) !=
vcpu->arch.pfault_compare)
return 0;
if (psw_extint_disabled(vcpu))
return 0;
if (kvm_cpu_has_interrupt(vcpu))
return 0;
if (!(vcpu->arch.sie_block->gcr[0] & 0x200ul))
return 0;
if (!vcpu->arch.gmap->pfault_enabled)
return 0;
hva = gfn_to_hva(vcpu->kvm, gpa_to_gfn(current->thread.gmap_addr));
hva += current->thread.gmap_addr & ~PAGE_MASK;
if (read_guest_real(vcpu, vcpu->arch.pfault_token, &arch.pfault_token, 8))
return 0;
rc = kvm_setup_async_pf(vcpu, current->thread.gmap_addr, hva, &arch);
return rc;
}
static int vcpu_pre_run(struct kvm_vcpu *vcpu)
{
int rc, cpuflags;
kvm_check_async_pf_completion(vcpu);
memcpy(&vcpu->arch.sie_block->gg14, &vcpu->run->s.regs.gprs[14], 16);
if (need_resched())
schedule();
if (test_cpu_flag(CIF_MCCK_PENDING))
s390_handle_mcck();
if (!kvm_is_ucontrol(vcpu->kvm)) {
rc = kvm_s390_deliver_pending_interrupts(vcpu);
if (rc)
return rc;
}
rc = kvm_s390_handle_requests(vcpu);
if (rc)
return rc;
if (guestdbg_enabled(vcpu)) {
kvm_s390_backup_guest_per_regs(vcpu);
kvm_s390_patch_guest_per_regs(vcpu);
}
vcpu->arch.sie_block->icptcode = 0;
cpuflags = atomic_read(&vcpu->arch.sie_block->cpuflags);
VCPU_EVENT(vcpu, 6, "entering sie flags %x", cpuflags);
trace_kvm_s390_sie_enter(vcpu, cpuflags);
return 0;
}
static int vcpu_post_run(struct kvm_vcpu *vcpu, int exit_reason)
{
int rc = -1;
VCPU_EVENT(vcpu, 6, "exit sie icptcode %d",
vcpu->arch.sie_block->icptcode);
trace_kvm_s390_sie_exit(vcpu, vcpu->arch.sie_block->icptcode);
if (guestdbg_enabled(vcpu))
kvm_s390_restore_guest_per_regs(vcpu);
if (exit_reason >= 0) {
rc = 0;
} else if (kvm_is_ucontrol(vcpu->kvm)) {
vcpu->run->exit_reason = KVM_EXIT_S390_UCONTROL;
vcpu->run->s390_ucontrol.trans_exc_code =
current->thread.gmap_addr;
vcpu->run->s390_ucontrol.pgm_code = 0x10;
rc = -EREMOTE;
} else if (current->thread.gmap_pfault) {
trace_kvm_s390_major_guest_pfault(vcpu);
current->thread.gmap_pfault = 0;
if (kvm_arch_setup_async_pf(vcpu)) {
rc = 0;
} else {
gpa_t gpa = current->thread.gmap_addr;
rc = kvm_arch_fault_in_page(vcpu, gpa, 1);
}
}
if (rc == -1) {
VCPU_EVENT(vcpu, 3, "%s", "fault in sie instruction");
trace_kvm_s390_sie_fault(vcpu);
rc = kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
}
memcpy(&vcpu->run->s.regs.gprs[14], &vcpu->arch.sie_block->gg14, 16);
if (rc == 0) {
if (kvm_is_ucontrol(vcpu->kvm))
rc = vcpu->arch.sie_block->icptcode ? -EOPNOTSUPP : 0;
else
rc = kvm_handle_sie_intercept(vcpu);
}
return rc;
}
static int __vcpu_run(struct kvm_vcpu *vcpu)
{
int rc, exit_reason;
vcpu->srcu_idx = srcu_read_lock(&vcpu->kvm->srcu);
do {
rc = vcpu_pre_run(vcpu);
if (rc)
break;
srcu_read_unlock(&vcpu->kvm->srcu, vcpu->srcu_idx);
preempt_disable();
kvm_guest_enter();
preempt_enable();
exit_reason = sie64a(vcpu->arch.sie_block,
vcpu->run->s.regs.gprs);
kvm_guest_exit();
vcpu->srcu_idx = srcu_read_lock(&vcpu->kvm->srcu);
rc = vcpu_post_run(vcpu, exit_reason);
} while (!signal_pending(current) && !guestdbg_exit_pending(vcpu) && !rc);
srcu_read_unlock(&vcpu->kvm->srcu, vcpu->srcu_idx);
return rc;
}
static void sync_regs(struct kvm_vcpu *vcpu, struct kvm_run *kvm_run)
{
vcpu->arch.sie_block->gpsw.mask = kvm_run->psw_mask;
vcpu->arch.sie_block->gpsw.addr = kvm_run->psw_addr;
if (kvm_run->kvm_dirty_regs & KVM_SYNC_PREFIX)
kvm_s390_set_prefix(vcpu, kvm_run->s.regs.prefix);
if (kvm_run->kvm_dirty_regs & KVM_SYNC_CRS) {
memcpy(&vcpu->arch.sie_block->gcr, &kvm_run->s.regs.crs, 128);
kvm_make_request(KVM_REQ_TLB_FLUSH, vcpu);
}
if (kvm_run->kvm_dirty_regs & KVM_SYNC_ARCH0) {
vcpu->arch.sie_block->cputm = kvm_run->s.regs.cputm;
vcpu->arch.sie_block->ckc = kvm_run->s.regs.ckc;
vcpu->arch.sie_block->todpr = kvm_run->s.regs.todpr;
vcpu->arch.sie_block->pp = kvm_run->s.regs.pp;
vcpu->arch.sie_block->gbea = kvm_run->s.regs.gbea;
}
if (kvm_run->kvm_dirty_regs & KVM_SYNC_PFAULT) {
vcpu->arch.pfault_token = kvm_run->s.regs.pft;
vcpu->arch.pfault_select = kvm_run->s.regs.pfs;
vcpu->arch.pfault_compare = kvm_run->s.regs.pfc;
}
kvm_run->kvm_dirty_regs = 0;
}
static void store_regs(struct kvm_vcpu *vcpu, struct kvm_run *kvm_run)
{
kvm_run->psw_mask = vcpu->arch.sie_block->gpsw.mask;
kvm_run->psw_addr = vcpu->arch.sie_block->gpsw.addr;
kvm_run->s.regs.prefix = kvm_s390_get_prefix(vcpu);
memcpy(&kvm_run->s.regs.crs, &vcpu->arch.sie_block->gcr, 128);
kvm_run->s.regs.cputm = vcpu->arch.sie_block->cputm;
kvm_run->s.regs.ckc = vcpu->arch.sie_block->ckc;
kvm_run->s.regs.todpr = vcpu->arch.sie_block->todpr;
kvm_run->s.regs.pp = vcpu->arch.sie_block->pp;
kvm_run->s.regs.gbea = vcpu->arch.sie_block->gbea;
kvm_run->s.regs.pft = vcpu->arch.pfault_token;
kvm_run->s.regs.pfs = vcpu->arch.pfault_select;
kvm_run->s.regs.pfc = vcpu->arch.pfault_compare;
}
int kvm_arch_vcpu_ioctl_run(struct kvm_vcpu *vcpu, struct kvm_run *kvm_run)
{
int rc;
sigset_t sigsaved;
if (guestdbg_exit_pending(vcpu)) {
kvm_s390_prepare_debug_exit(vcpu);
return 0;
}
if (vcpu->sigset_active)
sigprocmask(SIG_SETMASK, &vcpu->sigset, &sigsaved);
if (!kvm_s390_user_cpu_state_ctrl(vcpu->kvm)) {
kvm_s390_vcpu_start(vcpu);
} else if (is_vcpu_stopped(vcpu)) {
pr_err_ratelimited("kvm-s390: can't run stopped vcpu %d\n",
vcpu->vcpu_id);
return -EINVAL;
}
sync_regs(vcpu, kvm_run);
might_fault();
rc = __vcpu_run(vcpu);
if (signal_pending(current) && !rc) {
kvm_run->exit_reason = KVM_EXIT_INTR;
rc = -EINTR;
}
if (guestdbg_exit_pending(vcpu) && !rc) {
kvm_s390_prepare_debug_exit(vcpu);
rc = 0;
}
if (rc == -EOPNOTSUPP) {
kvm_run->exit_reason = KVM_EXIT_S390_SIEIC;
kvm_run->s390_sieic.icptcode = vcpu->arch.sie_block->icptcode;
kvm_run->s390_sieic.ipa = vcpu->arch.sie_block->ipa;
kvm_run->s390_sieic.ipb = vcpu->arch.sie_block->ipb;
rc = 0;
}
if (rc == -EREMOTE) {
rc = 0;
}
store_regs(vcpu, kvm_run);
if (vcpu->sigset_active)
sigprocmask(SIG_SETMASK, &sigsaved, NULL);
vcpu->stat.exit_userspace++;
return rc;
}
int kvm_s390_store_status_unloaded(struct kvm_vcpu *vcpu, unsigned long gpa)
{
unsigned char archmode = 1;
unsigned int px;
u64 clkcomp;
int rc;
if (gpa == KVM_S390_STORE_STATUS_NOADDR) {
if (write_guest_abs(vcpu, 163, &archmode, 1))
return -EFAULT;
gpa = SAVE_AREA_BASE;
} else if (gpa == KVM_S390_STORE_STATUS_PREFIXED) {
if (write_guest_real(vcpu, 163, &archmode, 1))
return -EFAULT;
gpa = kvm_s390_real_to_abs(vcpu, SAVE_AREA_BASE);
}
rc = write_guest_abs(vcpu, gpa + offsetof(struct save_area, fp_regs),
vcpu->arch.guest_fpregs.fprs, 128);
rc |= write_guest_abs(vcpu, gpa + offsetof(struct save_area, gp_regs),
vcpu->run->s.regs.gprs, 128);
rc |= write_guest_abs(vcpu, gpa + offsetof(struct save_area, psw),
&vcpu->arch.sie_block->gpsw, 16);
px = kvm_s390_get_prefix(vcpu);
rc |= write_guest_abs(vcpu, gpa + offsetof(struct save_area, pref_reg),
&px, 4);
rc |= write_guest_abs(vcpu,
gpa + offsetof(struct save_area, fp_ctrl_reg),
&vcpu->arch.guest_fpregs.fpc, 4);
rc |= write_guest_abs(vcpu, gpa + offsetof(struct save_area, tod_reg),
&vcpu->arch.sie_block->todpr, 4);
rc |= write_guest_abs(vcpu, gpa + offsetof(struct save_area, timer),
&vcpu->arch.sie_block->cputm, 8);
clkcomp = vcpu->arch.sie_block->ckc >> 8;
rc |= write_guest_abs(vcpu, gpa + offsetof(struct save_area, clk_cmp),
&clkcomp, 8);
rc |= write_guest_abs(vcpu, gpa + offsetof(struct save_area, acc_regs),
&vcpu->run->s.regs.acrs, 64);
rc |= write_guest_abs(vcpu, gpa + offsetof(struct save_area, ctrl_regs),
&vcpu->arch.sie_block->gcr, 128);
return rc ? -EFAULT : 0;
}
int kvm_s390_vcpu_store_status(struct kvm_vcpu *vcpu, unsigned long addr)
{
save_fp_ctl(&vcpu->arch.guest_fpregs.fpc);
save_fp_regs(vcpu->arch.guest_fpregs.fprs);
save_access_regs(vcpu->run->s.regs.acrs);
return kvm_s390_store_status_unloaded(vcpu, addr);
}
static void __disable_ibs_on_vcpu(struct kvm_vcpu *vcpu)
{
kvm_check_request(KVM_REQ_ENABLE_IBS, vcpu);
kvm_make_request(KVM_REQ_DISABLE_IBS, vcpu);
exit_sie_sync(vcpu);
}
static void __disable_ibs_on_all_vcpus(struct kvm *kvm)
{
unsigned int i;
struct kvm_vcpu *vcpu;
kvm_for_each_vcpu(i, vcpu, kvm) {
__disable_ibs_on_vcpu(vcpu);
}
}
static void __enable_ibs_on_vcpu(struct kvm_vcpu *vcpu)
{
kvm_check_request(KVM_REQ_DISABLE_IBS, vcpu);
kvm_make_request(KVM_REQ_ENABLE_IBS, vcpu);
exit_sie_sync(vcpu);
}
void kvm_s390_vcpu_start(struct kvm_vcpu *vcpu)
{
int i, online_vcpus, started_vcpus = 0;
if (!is_vcpu_stopped(vcpu))
return;
trace_kvm_s390_vcpu_start_stop(vcpu->vcpu_id, 1);
spin_lock(&vcpu->kvm->arch.start_stop_lock);
online_vcpus = atomic_read(&vcpu->kvm->online_vcpus);
for (i = 0; i < online_vcpus; i++) {
if (!is_vcpu_stopped(vcpu->kvm->vcpus[i]))
started_vcpus++;
}
if (started_vcpus == 0) {
__enable_ibs_on_vcpu(vcpu);
} else if (started_vcpus == 1) {
__disable_ibs_on_all_vcpus(vcpu->kvm);
}
atomic_clear_mask(CPUSTAT_STOPPED, &vcpu->arch.sie_block->cpuflags);
kvm_make_request(KVM_REQ_TLB_FLUSH, vcpu);
spin_unlock(&vcpu->kvm->arch.start_stop_lock);
return;
}
void kvm_s390_vcpu_stop(struct kvm_vcpu *vcpu)
{
int i, online_vcpus, started_vcpus = 0;
struct kvm_vcpu *started_vcpu = NULL;
if (is_vcpu_stopped(vcpu))
return;
trace_kvm_s390_vcpu_start_stop(vcpu->vcpu_id, 0);
spin_lock(&vcpu->kvm->arch.start_stop_lock);
online_vcpus = atomic_read(&vcpu->kvm->online_vcpus);
spin_lock(&vcpu->arch.local_int.lock);
atomic_set_mask(CPUSTAT_STOPPED, &vcpu->arch.sie_block->cpuflags);
vcpu->arch.local_int.action_bits &=
~(ACTION_STOP_ON_STOP | ACTION_STORE_ON_STOP);
spin_unlock(&vcpu->arch.local_int.lock);
__disable_ibs_on_vcpu(vcpu);
for (i = 0; i < online_vcpus; i++) {
if (!is_vcpu_stopped(vcpu->kvm->vcpus[i])) {
started_vcpus++;
started_vcpu = vcpu->kvm->vcpus[i];
}
}
if (started_vcpus == 1) {
__enable_ibs_on_vcpu(started_vcpu);
}
spin_unlock(&vcpu->kvm->arch.start_stop_lock);
return;
}
static int kvm_vcpu_ioctl_enable_cap(struct kvm_vcpu *vcpu,
struct kvm_enable_cap *cap)
{
int r;
if (cap->flags)
return -EINVAL;
switch (cap->cap) {
case KVM_CAP_S390_CSS_SUPPORT:
if (!vcpu->kvm->arch.css_support) {
vcpu->kvm->arch.css_support = 1;
trace_kvm_s390_enable_css(vcpu->kvm);
}
r = 0;
break;
default:
r = -EINVAL;
break;
}
return r;
}
long kvm_arch_vcpu_ioctl(struct file *filp,
unsigned int ioctl, unsigned long arg)
{
struct kvm_vcpu *vcpu = filp->private_data;
void __user *argp = (void __user *)arg;
int idx;
long r;
switch (ioctl) {
case KVM_S390_INTERRUPT: {
struct kvm_s390_interrupt s390int;
struct kvm_s390_irq s390irq;
r = -EFAULT;
if (copy_from_user(&s390int, argp, sizeof(s390int)))
break;
if (s390int_to_s390irq(&s390int, &s390irq))
return -EINVAL;
r = kvm_s390_inject_vcpu(vcpu, &s390irq);
break;
}
case KVM_S390_STORE_STATUS:
idx = srcu_read_lock(&vcpu->kvm->srcu);
r = kvm_s390_vcpu_store_status(vcpu, arg);
srcu_read_unlock(&vcpu->kvm->srcu, idx);
break;
case KVM_S390_SET_INITIAL_PSW: {
psw_t psw;
r = -EFAULT;
if (copy_from_user(&psw, argp, sizeof(psw)))
break;
r = kvm_arch_vcpu_ioctl_set_initial_psw(vcpu, psw);
break;
}
case KVM_S390_INITIAL_RESET:
r = kvm_arch_vcpu_ioctl_initial_reset(vcpu);
break;
case KVM_SET_ONE_REG:
case KVM_GET_ONE_REG: {
struct kvm_one_reg reg;
r = -EFAULT;
if (copy_from_user(&reg, argp, sizeof(reg)))
break;
if (ioctl == KVM_SET_ONE_REG)
r = kvm_arch_vcpu_ioctl_set_one_reg(vcpu, &reg);
else
r = kvm_arch_vcpu_ioctl_get_one_reg(vcpu, &reg);
break;
}
#ifdef CONFIG_KVM_S390_UCONTROL
case KVM_S390_UCAS_MAP: {
struct kvm_s390_ucas_mapping ucasmap;
if (copy_from_user(&ucasmap, argp, sizeof(ucasmap))) {
r = -EFAULT;
break;
}
if (!kvm_is_ucontrol(vcpu->kvm)) {
r = -EINVAL;
break;
}
r = gmap_map_segment(vcpu->arch.gmap, ucasmap.user_addr,
ucasmap.vcpu_addr, ucasmap.length);
break;
}
case KVM_S390_UCAS_UNMAP: {
struct kvm_s390_ucas_mapping ucasmap;
if (copy_from_user(&ucasmap, argp, sizeof(ucasmap))) {
r = -EFAULT;
break;
}
if (!kvm_is_ucontrol(vcpu->kvm)) {
r = -EINVAL;
break;
}
r = gmap_unmap_segment(vcpu->arch.gmap, ucasmap.vcpu_addr,
ucasmap.length);
break;
}
#endif
case KVM_S390_VCPU_FAULT: {
r = gmap_fault(vcpu->arch.gmap, arg, 0);
break;
}
case KVM_ENABLE_CAP:
{
struct kvm_enable_cap cap;
r = -EFAULT;
if (copy_from_user(&cap, argp, sizeof(cap)))
break;
r = kvm_vcpu_ioctl_enable_cap(vcpu, &cap);
break;
}
default:
r = -ENOTTY;
}
return r;
}
int kvm_arch_vcpu_fault(struct kvm_vcpu *vcpu, struct vm_fault *vmf)
{
#ifdef CONFIG_KVM_S390_UCONTROL
if ((vmf->pgoff == KVM_S390_SIE_PAGE_OFFSET)
&& (kvm_is_ucontrol(vcpu->kvm))) {
vmf->page = virt_to_page(vcpu->arch.sie_block);
get_page(vmf->page);
return 0;
}
#endif
return VM_FAULT_SIGBUS;
}
int kvm_arch_create_memslot(struct kvm *kvm, struct kvm_memory_slot *slot,
unsigned long npages)
{
return 0;
}
int kvm_arch_prepare_memory_region(struct kvm *kvm,
struct kvm_memory_slot *memslot,
struct kvm_userspace_memory_region *mem,
enum kvm_mr_change change)
{
if (mem->userspace_addr & 0xffffful)
return -EINVAL;
if (mem->memory_size & 0xffffful)
return -EINVAL;
return 0;
}
void kvm_arch_commit_memory_region(struct kvm *kvm,
struct kvm_userspace_memory_region *mem,
const struct kvm_memory_slot *old,
enum kvm_mr_change change)
{
int rc;
if (old->userspace_addr == mem->userspace_addr &&
old->base_gfn * PAGE_SIZE == mem->guest_phys_addr &&
old->npages * PAGE_SIZE == mem->memory_size)
return;
rc = gmap_map_segment(kvm->arch.gmap, mem->userspace_addr,
mem->guest_phys_addr, mem->memory_size);
if (rc)
printk(KERN_WARNING "kvm-s390: failed to commit memory region\n");
return;
}
static int __init kvm_s390_init(void)
{
int ret;
ret = kvm_init(NULL, sizeof(struct kvm_vcpu), 0, THIS_MODULE);
if (ret)
return ret;
vfacilities = (unsigned long *) get_zeroed_page(GFP_KERNEL|GFP_DMA);
if (!vfacilities) {
kvm_exit();
return -ENOMEM;
}
memcpy(vfacilities, S390_lowcore.stfle_fac_list, 16);
vfacilities[0] &= 0xff82fffbf47c2000UL;
vfacilities[1] &= 0x005c000000000000UL;
return 0;
}
static void __exit kvm_s390_exit(void)
{
free_page((unsigned long) vfacilities);
kvm_exit();
}
