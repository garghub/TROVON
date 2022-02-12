static inline int test_vfacility(unsigned long nr)
{
return __test_facility(nr, (void *) vfacilities);
}
int kvm_arch_hardware_enable(void *garbage)
{
return 0;
}
void kvm_arch_hardware_disable(void *garbage)
{
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
void kvm_arch_check_processor_compat(void *rtn)
{
}
int kvm_arch_init(void *opaque)
{
return 0;
}
void kvm_arch_exit(void)
{
}
long kvm_arch_dev_ioctl(struct file *filp,
unsigned int ioctl, unsigned long arg)
{
if (ioctl == KVM_S390_ENABLE_SIE)
return s390_enable_sie();
return -EINVAL;
}
int kvm_dev_ioctl_check_extension(long ext)
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
int kvm_vm_ioctl_get_dirty_log(struct kvm *kvm,
struct kvm_dirty_log *log)
{
return 0;
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
long kvm_arch_vm_ioctl(struct file *filp,
unsigned int ioctl, unsigned long arg)
{
struct kvm *kvm = filp->private_data;
void __user *argp = (void __user *)arg;
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
default:
r = -ENOTTY;
}
return r;
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
spin_lock_init(&kvm->arch.float_int.lock);
INIT_LIST_HEAD(&kvm->arch.float_int.list);
debug_register_view(kvm->arch.dbf, &debug_sprintf_view);
VM_EVENT(kvm, 3, "%s", "vm created");
if (type & KVM_VM_S390_UCONTROL) {
kvm->arch.gmap = NULL;
} else {
kvm->arch.gmap = gmap_alloc(current->mm);
if (!kvm->arch.gmap)
goto out_nogmap;
kvm->arch.gmap->private = kvm;
kvm->arch.gmap->pfault_enabled = 0;
}
kvm->arch.css_support = 0;
kvm->arch.use_irqchip = 0;
return 0;
out_nogmap:
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
if (vcpu->arch.sie_block->cbrlo)
__free_page(__pfn_to_page(
vcpu->arch.sie_block->cbrlo >> PAGE_SHIFT));
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
void kvm_arch_sync_events(struct kvm *kvm)
{
}
void kvm_arch_destroy_vm(struct kvm *kvm)
{
kvm_free_vcpus(kvm);
free_page((unsigned long)(kvm->arch.sca));
debug_unregister(kvm->arch.dbf);
if (!kvm_is_ucontrol(kvm))
gmap_free(kvm->arch.gmap);
kvm_s390_destroy_adapters(kvm);
}
int kvm_arch_vcpu_init(struct kvm_vcpu *vcpu)
{
vcpu->arch.pfault_token = KVM_S390_PFAULT_TOKEN_INVALID;
kvm_clear_async_pf_completion_queue(vcpu);
if (kvm_is_ucontrol(vcpu->kvm)) {
vcpu->arch.gmap = gmap_alloc(current->mm);
if (!vcpu->arch.gmap)
return -ENOMEM;
vcpu->arch.gmap->private = vcpu->kvm;
return 0;
}
vcpu->arch.gmap = vcpu->kvm->arch.gmap;
vcpu->run->kvm_valid_regs = KVM_SYNC_PREFIX |
KVM_SYNC_GPRS |
KVM_SYNC_ACRS |
KVM_SYNC_CRS;
return 0;
}
void kvm_arch_vcpu_uninit(struct kvm_vcpu *vcpu)
{
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
atomic_set_mask(CPUSTAT_STOPPED, &vcpu->arch.sie_block->cpuflags);
kvm_s390_clear_local_irqs(vcpu);
}
int kvm_arch_vcpu_postcreate(struct kvm_vcpu *vcpu)
{
return 0;
}
int kvm_arch_vcpu_setup(struct kvm_vcpu *vcpu)
{
struct page *cbrl;
atomic_set(&vcpu->arch.sie_block->cpuflags, CPUSTAT_ZARCH |
CPUSTAT_SM |
CPUSTAT_STOPPED |
CPUSTAT_GED);
vcpu->arch.sie_block->ecb = 6;
if (test_vfacility(50) && test_vfacility(73))
vcpu->arch.sie_block->ecb |= 0x10;
vcpu->arch.sie_block->ecb2 = 8;
vcpu->arch.sie_block->eca = 0xC1002001U;
vcpu->arch.sie_block->fac = (int) (long) vfacilities;
if (kvm_enabled_cmma()) {
cbrl = alloc_page(GFP_KERNEL | __GFP_ZERO);
if (cbrl) {
vcpu->arch.sie_block->ecb2 |= 0x80;
vcpu->arch.sie_block->ecb2 &= ~0x08;
vcpu->arch.sie_block->cbrlo = page_to_phys(cbrl);
}
}
hrtimer_init(&vcpu->arch.ckc_timer, CLOCK_REALTIME, HRTIMER_MODE_ABS);
tasklet_init(&vcpu->arch.tasklet, kvm_s390_tasklet,
(unsigned long) vcpu);
vcpu->arch.ckc_timer.function = kvm_s390_idle_wakeup;
get_cpu_id(&vcpu->arch.cpu_id);
vcpu->arch.cpu_id.version = 0xff;
return 0;
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
INIT_LIST_HEAD(&vcpu->arch.local_int.list);
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
if (vcpu->arch.sie_block->prefix == (address & ~0x1000UL)) {
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
if (!(atomic_read(&vcpu->arch.sie_block->cpuflags) & CPUSTAT_STOPPED))
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
return -EINVAL;
}
int kvm_arch_vcpu_ioctl_get_mpstate(struct kvm_vcpu *vcpu,
struct kvm_mp_state *mp_state)
{
return -EINVAL;
}
int kvm_arch_vcpu_ioctl_set_mpstate(struct kvm_vcpu *vcpu,
struct kvm_mp_state *mp_state)
{
return -EINVAL;
}
static int kvm_s390_handle_requests(struct kvm_vcpu *vcpu)
{
while (kvm_check_request(KVM_REQ_MMU_RELOAD, vcpu)) {
int rc;
rc = gmap_ipte_notify(vcpu->arch.gmap,
vcpu->arch.sie_block->prefix,
PAGE_SIZE * 2);
if (rc)
return rc;
s390_vcpu_unblock(vcpu);
}
return 0;
}
static long kvm_arch_fault_in_sync(struct kvm_vcpu *vcpu)
{
long rc;
hva_t fault = gmap_fault(current->thread.gmap_addr, vcpu->arch.gmap);
struct mm_struct *mm = current->mm;
down_read(&mm->mmap_sem);
rc = get_user_pages(current, mm, fault, 1, 1, 0, NULL, NULL);
up_read(&mm->mmap_sem);
return rc;
}
static void __kvm_inject_pfault_token(struct kvm_vcpu *vcpu, bool start_token,
unsigned long token)
{
struct kvm_s390_interrupt inti;
inti.parm64 = token;
if (start_token) {
inti.type = KVM_S390_INT_PFAULT_INIT;
WARN_ON_ONCE(kvm_s390_inject_vcpu(vcpu, &inti));
} else {
inti.type = KVM_S390_INT_PFAULT_DONE;
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
hva = gmap_fault(current->thread.gmap_addr, vcpu->arch.gmap);
if (copy_from_guest(vcpu, &arch.pfault_token, vcpu->arch.pfault_token, 8))
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
if (test_thread_flag(TIF_MCCK_PENDING))
s390_handle_mcck();
if (!kvm_is_ucontrol(vcpu->kvm))
kvm_s390_deliver_pending_interrupts(vcpu);
rc = kvm_s390_handle_requests(vcpu);
if (rc)
return rc;
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
if (kvm_arch_setup_async_pf(vcpu) ||
(kvm_arch_fault_in_sync(vcpu) >= 0))
rc = 0;
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
bool kvm_enabled_cmma(void)
{
if (!MACHINE_IS_LPAR)
return false;
if (!MACHINE_HAS_EDAT1)
return false;
return true;
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
} while (!signal_pending(current) && !rc);
srcu_read_unlock(&vcpu->kvm->srcu, vcpu->srcu_idx);
return rc;
}
int kvm_arch_vcpu_ioctl_run(struct kvm_vcpu *vcpu, struct kvm_run *kvm_run)
{
int rc;
sigset_t sigsaved;
if (vcpu->sigset_active)
sigprocmask(SIG_SETMASK, &vcpu->sigset, &sigsaved);
atomic_clear_mask(CPUSTAT_STOPPED, &vcpu->arch.sie_block->cpuflags);
switch (kvm_run->exit_reason) {
case KVM_EXIT_S390_SIEIC:
case KVM_EXIT_UNKNOWN:
case KVM_EXIT_INTR:
case KVM_EXIT_S390_RESET:
case KVM_EXIT_S390_UCONTROL:
case KVM_EXIT_S390_TSCH:
break;
default:
BUG();
}
vcpu->arch.sie_block->gpsw.mask = kvm_run->psw_mask;
vcpu->arch.sie_block->gpsw.addr = kvm_run->psw_addr;
if (kvm_run->kvm_dirty_regs & KVM_SYNC_PREFIX) {
kvm_run->kvm_dirty_regs &= ~KVM_SYNC_PREFIX;
kvm_s390_set_prefix(vcpu, kvm_run->s.regs.prefix);
}
if (kvm_run->kvm_dirty_regs & KVM_SYNC_CRS) {
kvm_run->kvm_dirty_regs &= ~KVM_SYNC_CRS;
memcpy(&vcpu->arch.sie_block->gcr, &kvm_run->s.regs.crs, 128);
kvm_s390_set_prefix(vcpu, kvm_run->s.regs.prefix);
}
might_fault();
rc = __vcpu_run(vcpu);
if (signal_pending(current) && !rc) {
kvm_run->exit_reason = KVM_EXIT_INTR;
rc = -EINTR;
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
kvm_run->psw_mask = vcpu->arch.sie_block->gpsw.mask;
kvm_run->psw_addr = vcpu->arch.sie_block->gpsw.addr;
kvm_run->s.regs.prefix = vcpu->arch.sie_block->prefix;
memcpy(&kvm_run->s.regs.crs, &vcpu->arch.sie_block->gcr, 128);
if (vcpu->sigset_active)
sigprocmask(SIG_SETMASK, &sigsaved, NULL);
vcpu->stat.exit_userspace++;
return rc;
}
static int __guestcopy(struct kvm_vcpu *vcpu, u64 guestdest, void *from,
unsigned long n, int prefix)
{
if (prefix)
return copy_to_guest(vcpu, guestdest, from, n);
else
return copy_to_guest_absolute(vcpu, guestdest, from, n);
}
int kvm_s390_store_status_unloaded(struct kvm_vcpu *vcpu, unsigned long addr)
{
unsigned char archmode = 1;
int prefix;
u64 clkcomp;
if (addr == KVM_S390_STORE_STATUS_NOADDR) {
if (copy_to_guest_absolute(vcpu, 163ul, &archmode, 1))
return -EFAULT;
addr = SAVE_AREA_BASE;
prefix = 0;
} else if (addr == KVM_S390_STORE_STATUS_PREFIXED) {
if (copy_to_guest(vcpu, 163ul, &archmode, 1))
return -EFAULT;
addr = SAVE_AREA_BASE;
prefix = 1;
} else
prefix = 0;
if (__guestcopy(vcpu, addr + offsetof(struct save_area, fp_regs),
vcpu->arch.guest_fpregs.fprs, 128, prefix))
return -EFAULT;
if (__guestcopy(vcpu, addr + offsetof(struct save_area, gp_regs),
vcpu->run->s.regs.gprs, 128, prefix))
return -EFAULT;
if (__guestcopy(vcpu, addr + offsetof(struct save_area, psw),
&vcpu->arch.sie_block->gpsw, 16, prefix))
return -EFAULT;
if (__guestcopy(vcpu, addr + offsetof(struct save_area, pref_reg),
&vcpu->arch.sie_block->prefix, 4, prefix))
return -EFAULT;
if (__guestcopy(vcpu,
addr + offsetof(struct save_area, fp_ctrl_reg),
&vcpu->arch.guest_fpregs.fpc, 4, prefix))
return -EFAULT;
if (__guestcopy(vcpu, addr + offsetof(struct save_area, tod_reg),
&vcpu->arch.sie_block->todpr, 4, prefix))
return -EFAULT;
if (__guestcopy(vcpu, addr + offsetof(struct save_area, timer),
&vcpu->arch.sie_block->cputm, 8, prefix))
return -EFAULT;
clkcomp = vcpu->arch.sie_block->ckc >> 8;
if (__guestcopy(vcpu, addr + offsetof(struct save_area, clk_cmp),
&clkcomp, 8, prefix))
return -EFAULT;
if (__guestcopy(vcpu, addr + offsetof(struct save_area, acc_regs),
&vcpu->run->s.regs.acrs, 64, prefix))
return -EFAULT;
if (__guestcopy(vcpu,
addr + offsetof(struct save_area, ctrl_regs),
&vcpu->arch.sie_block->gcr, 128, prefix))
return -EFAULT;
return 0;
}
int kvm_s390_vcpu_store_status(struct kvm_vcpu *vcpu, unsigned long addr)
{
save_fp_ctl(&vcpu->arch.guest_fpregs.fpc);
save_fp_regs(vcpu->arch.guest_fpregs.fprs);
save_access_regs(vcpu->run->s.regs.acrs);
return kvm_s390_store_status_unloaded(vcpu, addr);
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
r = -EFAULT;
if (copy_from_user(&s390int, argp, sizeof(s390int)))
break;
r = kvm_s390_inject_vcpu(vcpu, &s390int);
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
r = gmap_fault(arg, vcpu->arch.gmap);
if (!IS_ERR_VALUE(r))
r = 0;
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
void kvm_arch_free_memslot(struct kvm *kvm, struct kvm_memory_slot *free,
struct kvm_memory_slot *dont)
{
}
int kvm_arch_create_memslot(struct kvm *kvm, struct kvm_memory_slot *slot,
unsigned long npages)
{
return 0;
}
void kvm_arch_memslots_updated(struct kvm *kvm)
{
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
void kvm_arch_flush_shadow_all(struct kvm *kvm)
{
}
void kvm_arch_flush_shadow_memslot(struct kvm *kvm,
struct kvm_memory_slot *slot)
{
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
vfacilities[0] &= 0xff82fff3f4fc2000UL;
vfacilities[1] &= 0x005c000000000000UL;
return 0;
}
static void __exit kvm_s390_exit(void)
{
free_page((unsigned long) vfacilities);
kvm_exit();
}
