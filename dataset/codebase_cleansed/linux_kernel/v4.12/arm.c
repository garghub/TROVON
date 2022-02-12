static void kvm_arm_set_running_vcpu(struct kvm_vcpu *vcpu)
{
BUG_ON(preemptible());
__this_cpu_write(kvm_arm_running_vcpu, vcpu);
}
struct kvm_vcpu *kvm_arm_get_running_vcpu(void)
{
BUG_ON(preemptible());
return __this_cpu_read(kvm_arm_running_vcpu);
}
struct kvm_vcpu * __percpu *kvm_get_running_vcpus(void)
{
return &kvm_arm_running_vcpu;
}
int kvm_arch_vcpu_should_kick(struct kvm_vcpu *vcpu)
{
return kvm_vcpu_exiting_guest_mode(vcpu) == IN_GUEST_MODE;
}
int kvm_arch_hardware_setup(void)
{
return 0;
}
void kvm_arch_check_processor_compat(void *rtn)
{
*(int *)rtn = 0;
}
int kvm_arch_init_vm(struct kvm *kvm, unsigned long type)
{
int ret, cpu;
if (type)
return -EINVAL;
kvm->arch.last_vcpu_ran = alloc_percpu(typeof(*kvm->arch.last_vcpu_ran));
if (!kvm->arch.last_vcpu_ran)
return -ENOMEM;
for_each_possible_cpu(cpu)
*per_cpu_ptr(kvm->arch.last_vcpu_ran, cpu) = -1;
ret = kvm_alloc_stage2_pgd(kvm);
if (ret)
goto out_fail_alloc;
ret = create_hyp_mappings(kvm, kvm + 1, PAGE_HYP);
if (ret)
goto out_free_stage2_pgd;
kvm_vgic_early_init(kvm);
kvm->arch.vmid_gen = 0;
kvm->arch.max_vcpus = vgic_present ?
kvm_vgic_get_max_vcpus() : KVM_MAX_VCPUS;
return ret;
out_free_stage2_pgd:
kvm_free_stage2_pgd(kvm);
out_fail_alloc:
free_percpu(kvm->arch.last_vcpu_ran);
kvm->arch.last_vcpu_ran = NULL;
return ret;
}
bool kvm_arch_has_vcpu_debugfs(void)
{
return false;
}
int kvm_arch_create_vcpu_debugfs(struct kvm_vcpu *vcpu)
{
return 0;
}
int kvm_arch_vcpu_fault(struct kvm_vcpu *vcpu, struct vm_fault *vmf)
{
return VM_FAULT_SIGBUS;
}
void kvm_arch_destroy_vm(struct kvm *kvm)
{
int i;
free_percpu(kvm->arch.last_vcpu_ran);
kvm->arch.last_vcpu_ran = NULL;
for (i = 0; i < KVM_MAX_VCPUS; ++i) {
if (kvm->vcpus[i]) {
kvm_arch_vcpu_free(kvm->vcpus[i]);
kvm->vcpus[i] = NULL;
}
}
kvm_vgic_destroy(kvm);
}
int kvm_vm_ioctl_check_extension(struct kvm *kvm, long ext)
{
int r;
switch (ext) {
case KVM_CAP_IRQCHIP:
r = vgic_present;
break;
case KVM_CAP_IOEVENTFD:
case KVM_CAP_DEVICE_CTRL:
case KVM_CAP_USER_MEMORY:
case KVM_CAP_SYNC_MMU:
case KVM_CAP_DESTROY_MEMORY_REGION_WORKS:
case KVM_CAP_ONE_REG:
case KVM_CAP_ARM_PSCI:
case KVM_CAP_ARM_PSCI_0_2:
case KVM_CAP_READONLY_MEM:
case KVM_CAP_MP_STATE:
case KVM_CAP_IMMEDIATE_EXIT:
r = 1;
break;
case KVM_CAP_ARM_SET_DEVICE_ADDR:
r = 1;
break;
case KVM_CAP_NR_VCPUS:
r = num_online_cpus();
break;
case KVM_CAP_MAX_VCPUS:
r = KVM_MAX_VCPUS;
break;
case KVM_CAP_NR_MEMSLOTS:
r = KVM_USER_MEM_SLOTS;
break;
case KVM_CAP_MSI_DEVID:
if (!kvm)
r = -EINVAL;
else
r = kvm->arch.vgic.msis_require_devid;
break;
case KVM_CAP_ARM_USER_IRQ:
r = 1;
break;
default:
r = kvm_arch_dev_ioctl_check_extension(kvm, ext);
break;
}
return r;
}
long kvm_arch_dev_ioctl(struct file *filp,
unsigned int ioctl, unsigned long arg)
{
return -EINVAL;
}
struct kvm_vcpu *kvm_arch_vcpu_create(struct kvm *kvm, unsigned int id)
{
int err;
struct kvm_vcpu *vcpu;
if (irqchip_in_kernel(kvm) && vgic_initialized(kvm)) {
err = -EBUSY;
goto out;
}
if (id >= kvm->arch.max_vcpus) {
err = -EINVAL;
goto out;
}
vcpu = kmem_cache_zalloc(kvm_vcpu_cache, GFP_KERNEL);
if (!vcpu) {
err = -ENOMEM;
goto out;
}
err = kvm_vcpu_init(vcpu, kvm, id);
if (err)
goto free_vcpu;
err = create_hyp_mappings(vcpu, vcpu + 1, PAGE_HYP);
if (err)
goto vcpu_uninit;
return vcpu;
vcpu_uninit:
kvm_vcpu_uninit(vcpu);
free_vcpu:
kmem_cache_free(kvm_vcpu_cache, vcpu);
out:
return ERR_PTR(err);
}
void kvm_arch_vcpu_postcreate(struct kvm_vcpu *vcpu)
{
kvm_vgic_vcpu_early_init(vcpu);
}
void kvm_arch_vcpu_free(struct kvm_vcpu *vcpu)
{
kvm_mmu_free_memory_caches(vcpu);
kvm_timer_vcpu_terminate(vcpu);
kvm_vgic_vcpu_destroy(vcpu);
kvm_pmu_vcpu_destroy(vcpu);
kvm_vcpu_uninit(vcpu);
kmem_cache_free(kvm_vcpu_cache, vcpu);
}
void kvm_arch_vcpu_destroy(struct kvm_vcpu *vcpu)
{
kvm_arch_vcpu_free(vcpu);
}
int kvm_cpu_has_pending_timer(struct kvm_vcpu *vcpu)
{
return kvm_timer_should_fire(vcpu_vtimer(vcpu)) ||
kvm_timer_should_fire(vcpu_ptimer(vcpu));
}
void kvm_arch_vcpu_blocking(struct kvm_vcpu *vcpu)
{
kvm_timer_schedule(vcpu);
}
void kvm_arch_vcpu_unblocking(struct kvm_vcpu *vcpu)
{
kvm_timer_unschedule(vcpu);
}
int kvm_arch_vcpu_init(struct kvm_vcpu *vcpu)
{
vcpu->arch.target = -1;
bitmap_zero(vcpu->arch.features, KVM_VCPU_MAX_FEATURES);
kvm_timer_vcpu_init(vcpu);
kvm_arm_reset_debug_ptr(vcpu);
return kvm_vgic_vcpu_init(vcpu);
}
void kvm_arch_vcpu_load(struct kvm_vcpu *vcpu, int cpu)
{
int *last_ran;
last_ran = this_cpu_ptr(vcpu->kvm->arch.last_vcpu_ran);
if (*last_ran != vcpu->vcpu_id) {
kvm_call_hyp(__kvm_tlb_flush_local_vmid, vcpu);
*last_ran = vcpu->vcpu_id;
}
vcpu->cpu = cpu;
vcpu->arch.host_cpu_context = this_cpu_ptr(kvm_host_cpu_state);
kvm_arm_set_running_vcpu(vcpu);
kvm_vgic_load(vcpu);
}
void kvm_arch_vcpu_put(struct kvm_vcpu *vcpu)
{
kvm_vgic_put(vcpu);
vcpu->cpu = -1;
kvm_arm_set_running_vcpu(NULL);
kvm_timer_vcpu_put(vcpu);
}
int kvm_arch_vcpu_ioctl_get_mpstate(struct kvm_vcpu *vcpu,
struct kvm_mp_state *mp_state)
{
if (vcpu->arch.power_off)
mp_state->mp_state = KVM_MP_STATE_STOPPED;
else
mp_state->mp_state = KVM_MP_STATE_RUNNABLE;
return 0;
}
int kvm_arch_vcpu_ioctl_set_mpstate(struct kvm_vcpu *vcpu,
struct kvm_mp_state *mp_state)
{
switch (mp_state->mp_state) {
case KVM_MP_STATE_RUNNABLE:
vcpu->arch.power_off = false;
break;
case KVM_MP_STATE_STOPPED:
vcpu->arch.power_off = true;
break;
default:
return -EINVAL;
}
return 0;
}
int kvm_arch_vcpu_runnable(struct kvm_vcpu *v)
{
return ((!!v->arch.irq_lines || kvm_vgic_vcpu_pending_irq(v))
&& !v->arch.power_off && !v->arch.pause);
}
static void exit_vm_noop(void *info)
{
}
void force_vm_exit(const cpumask_t *mask)
{
preempt_disable();
smp_call_function_many(mask, exit_vm_noop, NULL, true);
preempt_enable();
}
static bool need_new_vmid_gen(struct kvm *kvm)
{
return unlikely(kvm->arch.vmid_gen != atomic64_read(&kvm_vmid_gen));
}
static void update_vttbr(struct kvm *kvm)
{
phys_addr_t pgd_phys;
u64 vmid;
if (!need_new_vmid_gen(kvm))
return;
spin_lock(&kvm_vmid_lock);
if (!need_new_vmid_gen(kvm)) {
spin_unlock(&kvm_vmid_lock);
return;
}
if (unlikely(kvm_next_vmid == 0)) {
atomic64_inc(&kvm_vmid_gen);
kvm_next_vmid = 1;
force_vm_exit(cpu_all_mask);
kvm_call_hyp(__kvm_flush_vm_context);
}
kvm->arch.vmid_gen = atomic64_read(&kvm_vmid_gen);
kvm->arch.vmid = kvm_next_vmid;
kvm_next_vmid++;
kvm_next_vmid &= (1 << kvm_vmid_bits) - 1;
pgd_phys = virt_to_phys(kvm->arch.pgd);
BUG_ON(pgd_phys & ~VTTBR_BADDR_MASK);
vmid = ((u64)(kvm->arch.vmid) << VTTBR_VMID_SHIFT) & VTTBR_VMID_MASK(kvm_vmid_bits);
kvm->arch.vttbr = pgd_phys | vmid;
spin_unlock(&kvm_vmid_lock);
}
static int kvm_vcpu_first_run_init(struct kvm_vcpu *vcpu)
{
struct kvm *kvm = vcpu->kvm;
int ret = 0;
if (likely(vcpu->arch.has_run_once))
return 0;
vcpu->arch.has_run_once = true;
if (unlikely(irqchip_in_kernel(kvm) && !vgic_ready(kvm))) {
ret = kvm_vgic_map_resources(kvm);
if (ret)
return ret;
}
ret = kvm_timer_enable(vcpu);
return ret;
}
bool kvm_arch_intc_initialized(struct kvm *kvm)
{
return vgic_initialized(kvm);
}
void kvm_arm_halt_guest(struct kvm *kvm)
{
int i;
struct kvm_vcpu *vcpu;
kvm_for_each_vcpu(i, vcpu, kvm)
vcpu->arch.pause = true;
kvm_make_all_cpus_request(kvm, KVM_REQ_VCPU_EXIT);
}
void kvm_arm_halt_vcpu(struct kvm_vcpu *vcpu)
{
vcpu->arch.pause = true;
kvm_vcpu_kick(vcpu);
}
void kvm_arm_resume_vcpu(struct kvm_vcpu *vcpu)
{
struct swait_queue_head *wq = kvm_arch_vcpu_wq(vcpu);
vcpu->arch.pause = false;
swake_up(wq);
}
void kvm_arm_resume_guest(struct kvm *kvm)
{
int i;
struct kvm_vcpu *vcpu;
kvm_for_each_vcpu(i, vcpu, kvm)
kvm_arm_resume_vcpu(vcpu);
}
static void vcpu_sleep(struct kvm_vcpu *vcpu)
{
struct swait_queue_head *wq = kvm_arch_vcpu_wq(vcpu);
swait_event_interruptible(*wq, ((!vcpu->arch.power_off) &&
(!vcpu->arch.pause)));
}
static int kvm_vcpu_initialized(struct kvm_vcpu *vcpu)
{
return vcpu->arch.target >= 0;
}
int kvm_arch_vcpu_ioctl_run(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
int ret;
sigset_t sigsaved;
if (unlikely(!kvm_vcpu_initialized(vcpu)))
return -ENOEXEC;
ret = kvm_vcpu_first_run_init(vcpu);
if (ret)
return ret;
if (run->exit_reason == KVM_EXIT_MMIO) {
ret = kvm_handle_mmio_return(vcpu, vcpu->run);
if (ret)
return ret;
}
if (run->immediate_exit)
return -EINTR;
if (vcpu->sigset_active)
sigprocmask(SIG_SETMASK, &vcpu->sigset, &sigsaved);
ret = 1;
run->exit_reason = KVM_EXIT_UNKNOWN;
while (ret > 0) {
cond_resched();
update_vttbr(vcpu->kvm);
if (vcpu->arch.power_off || vcpu->arch.pause)
vcpu_sleep(vcpu);
preempt_disable();
kvm_pmu_flush_hwstate(vcpu);
kvm_timer_flush_hwstate(vcpu);
kvm_vgic_flush_hwstate(vcpu);
local_irq_disable();
if (signal_pending(current) ||
kvm_timer_should_notify_user(vcpu) ||
kvm_pmu_should_notify_user(vcpu)) {
ret = -EINTR;
run->exit_reason = KVM_EXIT_INTR;
}
if (ret <= 0 || need_new_vmid_gen(vcpu->kvm) ||
vcpu->arch.power_off || vcpu->arch.pause) {
local_irq_enable();
kvm_pmu_sync_hwstate(vcpu);
kvm_timer_sync_hwstate(vcpu);
kvm_vgic_sync_hwstate(vcpu);
preempt_enable();
continue;
}
kvm_arm_setup_debug(vcpu);
trace_kvm_entry(*vcpu_pc(vcpu));
guest_enter_irqoff();
vcpu->mode = IN_GUEST_MODE;
ret = kvm_call_hyp(__kvm_vcpu_run, vcpu);
vcpu->mode = OUTSIDE_GUEST_MODE;
vcpu->stat.exits++;
kvm_arm_clear_debug(vcpu);
local_irq_enable();
guest_exit();
trace_kvm_exit(ret, kvm_vcpu_trap_get_class(vcpu), *vcpu_pc(vcpu));
kvm_pmu_sync_hwstate(vcpu);
kvm_timer_sync_hwstate(vcpu);
kvm_vgic_sync_hwstate(vcpu);
preempt_enable();
ret = handle_exit(vcpu, run, ret);
}
if (unlikely(!irqchip_in_kernel(vcpu->kvm))) {
kvm_timer_update_run(vcpu);
kvm_pmu_update_run(vcpu);
}
if (vcpu->sigset_active)
sigprocmask(SIG_SETMASK, &sigsaved, NULL);
return ret;
}
static int vcpu_interrupt_line(struct kvm_vcpu *vcpu, int number, bool level)
{
int bit_index;
bool set;
unsigned long *ptr;
if (number == KVM_ARM_IRQ_CPU_IRQ)
bit_index = __ffs(HCR_VI);
else
bit_index = __ffs(HCR_VF);
ptr = (unsigned long *)&vcpu->arch.irq_lines;
if (level)
set = test_and_set_bit(bit_index, ptr);
else
set = test_and_clear_bit(bit_index, ptr);
if (set == level)
return 0;
kvm_vcpu_kick(vcpu);
return 0;
}
int kvm_vm_ioctl_irq_line(struct kvm *kvm, struct kvm_irq_level *irq_level,
bool line_status)
{
u32 irq = irq_level->irq;
unsigned int irq_type, vcpu_idx, irq_num;
int nrcpus = atomic_read(&kvm->online_vcpus);
struct kvm_vcpu *vcpu = NULL;
bool level = irq_level->level;
irq_type = (irq >> KVM_ARM_IRQ_TYPE_SHIFT) & KVM_ARM_IRQ_TYPE_MASK;
vcpu_idx = (irq >> KVM_ARM_IRQ_VCPU_SHIFT) & KVM_ARM_IRQ_VCPU_MASK;
irq_num = (irq >> KVM_ARM_IRQ_NUM_SHIFT) & KVM_ARM_IRQ_NUM_MASK;
trace_kvm_irq_line(irq_type, vcpu_idx, irq_num, irq_level->level);
switch (irq_type) {
case KVM_ARM_IRQ_TYPE_CPU:
if (irqchip_in_kernel(kvm))
return -ENXIO;
if (vcpu_idx >= nrcpus)
return -EINVAL;
vcpu = kvm_get_vcpu(kvm, vcpu_idx);
if (!vcpu)
return -EINVAL;
if (irq_num > KVM_ARM_IRQ_CPU_FIQ)
return -EINVAL;
return vcpu_interrupt_line(vcpu, irq_num, level);
case KVM_ARM_IRQ_TYPE_PPI:
if (!irqchip_in_kernel(kvm))
return -ENXIO;
if (vcpu_idx >= nrcpus)
return -EINVAL;
vcpu = kvm_get_vcpu(kvm, vcpu_idx);
if (!vcpu)
return -EINVAL;
if (irq_num < VGIC_NR_SGIS || irq_num >= VGIC_NR_PRIVATE_IRQS)
return -EINVAL;
return kvm_vgic_inject_irq(kvm, vcpu->vcpu_id, irq_num, level);
case KVM_ARM_IRQ_TYPE_SPI:
if (!irqchip_in_kernel(kvm))
return -ENXIO;
if (irq_num < VGIC_NR_PRIVATE_IRQS)
return -EINVAL;
return kvm_vgic_inject_irq(kvm, 0, irq_num, level);
}
return -EINVAL;
}
static int kvm_vcpu_set_target(struct kvm_vcpu *vcpu,
const struct kvm_vcpu_init *init)
{
unsigned int i;
int phys_target = kvm_target_cpu();
if (init->target != phys_target)
return -EINVAL;
if (vcpu->arch.target != -1 && vcpu->arch.target != init->target)
return -EINVAL;
for (i = 0; i < sizeof(init->features) * 8; i++) {
bool set = (init->features[i / 32] & (1 << (i % 32)));
if (set && i >= KVM_VCPU_MAX_FEATURES)
return -ENOENT;
if (vcpu->arch.target != -1 && i < KVM_VCPU_MAX_FEATURES &&
test_bit(i, vcpu->arch.features) != set)
return -EINVAL;
if (set)
set_bit(i, vcpu->arch.features);
}
vcpu->arch.target = phys_target;
return kvm_reset_vcpu(vcpu);
}
static int kvm_arch_vcpu_ioctl_vcpu_init(struct kvm_vcpu *vcpu,
struct kvm_vcpu_init *init)
{
int ret;
ret = kvm_vcpu_set_target(vcpu, init);
if (ret)
return ret;
if (vcpu->arch.has_run_once)
stage2_unmap_vm(vcpu->kvm);
vcpu_reset_hcr(vcpu);
if (test_bit(KVM_ARM_VCPU_POWER_OFF, vcpu->arch.features))
vcpu->arch.power_off = true;
else
vcpu->arch.power_off = false;
return 0;
}
static int kvm_arm_vcpu_set_attr(struct kvm_vcpu *vcpu,
struct kvm_device_attr *attr)
{
int ret = -ENXIO;
switch (attr->group) {
default:
ret = kvm_arm_vcpu_arch_set_attr(vcpu, attr);
break;
}
return ret;
}
static int kvm_arm_vcpu_get_attr(struct kvm_vcpu *vcpu,
struct kvm_device_attr *attr)
{
int ret = -ENXIO;
switch (attr->group) {
default:
ret = kvm_arm_vcpu_arch_get_attr(vcpu, attr);
break;
}
return ret;
}
static int kvm_arm_vcpu_has_attr(struct kvm_vcpu *vcpu,
struct kvm_device_attr *attr)
{
int ret = -ENXIO;
switch (attr->group) {
default:
ret = kvm_arm_vcpu_arch_has_attr(vcpu, attr);
break;
}
return ret;
}
long kvm_arch_vcpu_ioctl(struct file *filp,
unsigned int ioctl, unsigned long arg)
{
struct kvm_vcpu *vcpu = filp->private_data;
void __user *argp = (void __user *)arg;
struct kvm_device_attr attr;
switch (ioctl) {
case KVM_ARM_VCPU_INIT: {
struct kvm_vcpu_init init;
if (copy_from_user(&init, argp, sizeof(init)))
return -EFAULT;
return kvm_arch_vcpu_ioctl_vcpu_init(vcpu, &init);
}
case KVM_SET_ONE_REG:
case KVM_GET_ONE_REG: {
struct kvm_one_reg reg;
if (unlikely(!kvm_vcpu_initialized(vcpu)))
return -ENOEXEC;
if (copy_from_user(&reg, argp, sizeof(reg)))
return -EFAULT;
if (ioctl == KVM_SET_ONE_REG)
return kvm_arm_set_reg(vcpu, &reg);
else
return kvm_arm_get_reg(vcpu, &reg);
}
case KVM_GET_REG_LIST: {
struct kvm_reg_list __user *user_list = argp;
struct kvm_reg_list reg_list;
unsigned n;
if (unlikely(!kvm_vcpu_initialized(vcpu)))
return -ENOEXEC;
if (copy_from_user(&reg_list, user_list, sizeof(reg_list)))
return -EFAULT;
n = reg_list.n;
reg_list.n = kvm_arm_num_regs(vcpu);
if (copy_to_user(user_list, &reg_list, sizeof(reg_list)))
return -EFAULT;
if (n < reg_list.n)
return -E2BIG;
return kvm_arm_copy_reg_indices(vcpu, user_list->reg);
}
case KVM_SET_DEVICE_ATTR: {
if (copy_from_user(&attr, argp, sizeof(attr)))
return -EFAULT;
return kvm_arm_vcpu_set_attr(vcpu, &attr);
}
case KVM_GET_DEVICE_ATTR: {
if (copy_from_user(&attr, argp, sizeof(attr)))
return -EFAULT;
return kvm_arm_vcpu_get_attr(vcpu, &attr);
}
case KVM_HAS_DEVICE_ATTR: {
if (copy_from_user(&attr, argp, sizeof(attr)))
return -EFAULT;
return kvm_arm_vcpu_has_attr(vcpu, &attr);
}
default:
return -EINVAL;
}
}
int kvm_vm_ioctl_get_dirty_log(struct kvm *kvm, struct kvm_dirty_log *log)
{
bool is_dirty = false;
int r;
mutex_lock(&kvm->slots_lock);
r = kvm_get_dirty_log_protect(kvm, log, &is_dirty);
if (is_dirty)
kvm_flush_remote_tlbs(kvm);
mutex_unlock(&kvm->slots_lock);
return r;
}
static int kvm_vm_ioctl_set_device_addr(struct kvm *kvm,
struct kvm_arm_device_addr *dev_addr)
{
unsigned long dev_id, type;
dev_id = (dev_addr->id & KVM_ARM_DEVICE_ID_MASK) >>
KVM_ARM_DEVICE_ID_SHIFT;
type = (dev_addr->id & KVM_ARM_DEVICE_TYPE_MASK) >>
KVM_ARM_DEVICE_TYPE_SHIFT;
switch (dev_id) {
case KVM_ARM_DEVICE_VGIC_V2:
if (!vgic_present)
return -ENXIO;
return kvm_vgic_addr(kvm, type, &dev_addr->addr, true);
default:
return -ENODEV;
}
}
long kvm_arch_vm_ioctl(struct file *filp,
unsigned int ioctl, unsigned long arg)
{
struct kvm *kvm = filp->private_data;
void __user *argp = (void __user *)arg;
switch (ioctl) {
case KVM_CREATE_IRQCHIP: {
int ret;
if (!vgic_present)
return -ENXIO;
mutex_lock(&kvm->lock);
ret = kvm_vgic_create(kvm, KVM_DEV_TYPE_ARM_VGIC_V2);
mutex_unlock(&kvm->lock);
return ret;
}
case KVM_ARM_SET_DEVICE_ADDR: {
struct kvm_arm_device_addr dev_addr;
if (copy_from_user(&dev_addr, argp, sizeof(dev_addr)))
return -EFAULT;
return kvm_vm_ioctl_set_device_addr(kvm, &dev_addr);
}
case KVM_ARM_PREFERRED_TARGET: {
int err;
struct kvm_vcpu_init init;
err = kvm_vcpu_preferred_target(&init);
if (err)
return err;
if (copy_to_user(argp, &init, sizeof(init)))
return -EFAULT;
return 0;
}
default:
return -EINVAL;
}
}
static void cpu_init_hyp_mode(void *dummy)
{
phys_addr_t pgd_ptr;
unsigned long hyp_stack_ptr;
unsigned long stack_page;
unsigned long vector_ptr;
__hyp_set_vectors(kvm_get_idmap_vector());
pgd_ptr = kvm_mmu_get_httbr();
stack_page = __this_cpu_read(kvm_arm_hyp_stack_page);
hyp_stack_ptr = stack_page + PAGE_SIZE;
vector_ptr = (unsigned long)kvm_ksym_ref(__kvm_hyp_vector);
__cpu_init_hyp_mode(pgd_ptr, hyp_stack_ptr, vector_ptr);
__cpu_init_stage2();
if (is_kernel_in_hyp_mode())
kvm_timer_init_vhe();
kvm_arm_init_debug();
}
static void cpu_hyp_reset(void)
{
if (!is_kernel_in_hyp_mode())
__hyp_reset_vectors();
}
static void cpu_hyp_reinit(void)
{
cpu_hyp_reset();
if (is_kernel_in_hyp_mode()) {
__cpu_init_stage2();
} else {
cpu_init_hyp_mode(NULL);
}
if (vgic_present)
kvm_vgic_init_cpu_hardware();
}
static void _kvm_arch_hardware_enable(void *discard)
{
if (!__this_cpu_read(kvm_arm_hardware_enabled)) {
cpu_hyp_reinit();
__this_cpu_write(kvm_arm_hardware_enabled, 1);
}
}
int kvm_arch_hardware_enable(void)
{
_kvm_arch_hardware_enable(NULL);
return 0;
}
static void _kvm_arch_hardware_disable(void *discard)
{
if (__this_cpu_read(kvm_arm_hardware_enabled)) {
cpu_hyp_reset();
__this_cpu_write(kvm_arm_hardware_enabled, 0);
}
}
void kvm_arch_hardware_disable(void)
{
_kvm_arch_hardware_disable(NULL);
}
static int hyp_init_cpu_pm_notifier(struct notifier_block *self,
unsigned long cmd,
void *v)
{
switch (cmd) {
case CPU_PM_ENTER:
if (__this_cpu_read(kvm_arm_hardware_enabled))
cpu_hyp_reset();
return NOTIFY_OK;
case CPU_PM_EXIT:
if (__this_cpu_read(kvm_arm_hardware_enabled))
cpu_hyp_reinit();
return NOTIFY_OK;
default:
return NOTIFY_DONE;
}
}
static void __init hyp_cpu_pm_init(void)
{
cpu_pm_register_notifier(&hyp_init_cpu_pm_nb);
}
static void __init hyp_cpu_pm_exit(void)
{
cpu_pm_unregister_notifier(&hyp_init_cpu_pm_nb);
}
static inline void hyp_cpu_pm_init(void)
{
}
static inline void hyp_cpu_pm_exit(void)
{
}
static void teardown_common_resources(void)
{
free_percpu(kvm_host_cpu_state);
}
static int init_common_resources(void)
{
kvm_host_cpu_state = alloc_percpu(kvm_cpu_context_t);
if (!kvm_host_cpu_state) {
kvm_err("Cannot allocate host CPU state\n");
return -ENOMEM;
}
kvm_vmid_bits = kvm_get_vmid_bits();
kvm_info("%d-bit VMID\n", kvm_vmid_bits);
return 0;
}
static int init_subsystems(void)
{
int err = 0;
on_each_cpu(_kvm_arch_hardware_enable, NULL, 1);
hyp_cpu_pm_init();
err = kvm_vgic_hyp_init();
switch (err) {
case 0:
vgic_present = true;
break;
case -ENODEV:
case -ENXIO:
vgic_present = false;
err = 0;
break;
default:
goto out;
}
err = kvm_timer_hyp_init();
if (err)
goto out;
kvm_perf_init();
kvm_coproc_table_init();
out:
on_each_cpu(_kvm_arch_hardware_disable, NULL, 1);
return err;
}
static void teardown_hyp_mode(void)
{
int cpu;
if (is_kernel_in_hyp_mode())
return;
free_hyp_pgds();
for_each_possible_cpu(cpu)
free_page(per_cpu(kvm_arm_hyp_stack_page, cpu));
hyp_cpu_pm_exit();
}
static int init_vhe_mode(void)
{
kvm_info("VHE mode initialized successfully\n");
return 0;
}
static int init_hyp_mode(void)
{
int cpu;
int err = 0;
err = kvm_mmu_init();
if (err)
goto out_err;
for_each_possible_cpu(cpu) {
unsigned long stack_page;
stack_page = __get_free_page(GFP_KERNEL);
if (!stack_page) {
err = -ENOMEM;
goto out_err;
}
per_cpu(kvm_arm_hyp_stack_page, cpu) = stack_page;
}
err = create_hyp_mappings(kvm_ksym_ref(__hyp_text_start),
kvm_ksym_ref(__hyp_text_end), PAGE_HYP_EXEC);
if (err) {
kvm_err("Cannot map world-switch code\n");
goto out_err;
}
err = create_hyp_mappings(kvm_ksym_ref(__start_rodata),
kvm_ksym_ref(__end_rodata), PAGE_HYP_RO);
if (err) {
kvm_err("Cannot map rodata section\n");
goto out_err;
}
err = create_hyp_mappings(kvm_ksym_ref(__bss_start),
kvm_ksym_ref(__bss_stop), PAGE_HYP_RO);
if (err) {
kvm_err("Cannot map bss section\n");
goto out_err;
}
for_each_possible_cpu(cpu) {
char *stack_page = (char *)per_cpu(kvm_arm_hyp_stack_page, cpu);
err = create_hyp_mappings(stack_page, stack_page + PAGE_SIZE,
PAGE_HYP);
if (err) {
kvm_err("Cannot map hyp stack\n");
goto out_err;
}
}
for_each_possible_cpu(cpu) {
kvm_cpu_context_t *cpu_ctxt;
cpu_ctxt = per_cpu_ptr(kvm_host_cpu_state, cpu);
err = create_hyp_mappings(cpu_ctxt, cpu_ctxt + 1, PAGE_HYP);
if (err) {
kvm_err("Cannot map host CPU state: %d\n", err);
goto out_err;
}
}
kvm_info("Hyp mode initialized successfully\n");
return 0;
out_err:
teardown_hyp_mode();
kvm_err("error initializing Hyp mode: %d\n", err);
return err;
}
static void check_kvm_target_cpu(void *ret)
{
*(int *)ret = kvm_target_cpu();
}
struct kvm_vcpu *kvm_mpidr_to_vcpu(struct kvm *kvm, unsigned long mpidr)
{
struct kvm_vcpu *vcpu;
int i;
mpidr &= MPIDR_HWID_BITMASK;
kvm_for_each_vcpu(i, vcpu, kvm) {
if (mpidr == kvm_vcpu_get_mpidr_aff(vcpu))
return vcpu;
}
return NULL;
}
int kvm_arch_init(void *opaque)
{
int err;
int ret, cpu;
if (!is_hyp_mode_available()) {
kvm_err("HYP mode not available\n");
return -ENODEV;
}
for_each_online_cpu(cpu) {
smp_call_function_single(cpu, check_kvm_target_cpu, &ret, 1);
if (ret < 0) {
kvm_err("Error, CPU %d not supported!\n", cpu);
return -ENODEV;
}
}
err = init_common_resources();
if (err)
return err;
if (is_kernel_in_hyp_mode())
err = init_vhe_mode();
else
err = init_hyp_mode();
if (err)
goto out_err;
err = init_subsystems();
if (err)
goto out_hyp;
return 0;
out_hyp:
teardown_hyp_mode();
out_err:
teardown_common_resources();
return err;
}
void kvm_arch_exit(void)
{
kvm_perf_teardown();
}
static int arm_init(void)
{
int rc = kvm_init(NULL, sizeof(struct kvm_vcpu), 0, THIS_MODULE);
return rc;
}
