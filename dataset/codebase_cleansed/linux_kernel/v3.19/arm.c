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
int kvm_arch_hardware_enable(void)
{
return 0;
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
int ret = 0;
if (type)
return -EINVAL;
ret = kvm_alloc_stage2_pgd(kvm);
if (ret)
goto out_fail_alloc;
ret = create_hyp_mappings(kvm, kvm + 1);
if (ret)
goto out_free_stage2_pgd;
kvm_timer_init(kvm);
kvm->arch.vmid_gen = 0;
return ret;
out_free_stage2_pgd:
kvm_free_stage2_pgd(kvm);
out_fail_alloc:
return ret;
}
int kvm_arch_vcpu_fault(struct kvm_vcpu *vcpu, struct vm_fault *vmf)
{
return VM_FAULT_SIGBUS;
}
void kvm_arch_destroy_vm(struct kvm *kvm)
{
int i;
kvm_free_stage2_pgd(kvm);
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
case KVM_CAP_DEVICE_CTRL:
case KVM_CAP_USER_MEMORY:
case KVM_CAP_SYNC_MMU:
case KVM_CAP_DESTROY_MEMORY_REGION_WORKS:
case KVM_CAP_ONE_REG:
case KVM_CAP_ARM_PSCI:
case KVM_CAP_ARM_PSCI_0_2:
case KVM_CAP_READONLY_MEM:
r = 1;
break;
case KVM_CAP_COALESCED_MMIO:
r = KVM_COALESCED_MMIO_PAGE_OFFSET;
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
default:
r = kvm_arch_dev_ioctl_check_extension(ext);
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
vcpu = kmem_cache_zalloc(kvm_vcpu_cache, GFP_KERNEL);
if (!vcpu) {
err = -ENOMEM;
goto out;
}
err = kvm_vcpu_init(vcpu, kvm, id);
if (err)
goto free_vcpu;
err = create_hyp_mappings(vcpu, vcpu + 1);
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
int kvm_arch_vcpu_postcreate(struct kvm_vcpu *vcpu)
{
return 0;
}
void kvm_arch_vcpu_free(struct kvm_vcpu *vcpu)
{
kvm_mmu_free_memory_caches(vcpu);
kvm_timer_vcpu_terminate(vcpu);
kvm_vgic_vcpu_destroy(vcpu);
kmem_cache_free(kvm_vcpu_cache, vcpu);
}
void kvm_arch_vcpu_destroy(struct kvm_vcpu *vcpu)
{
kvm_arch_vcpu_free(vcpu);
}
int kvm_cpu_has_pending_timer(struct kvm_vcpu *vcpu)
{
return 0;
}
int kvm_arch_vcpu_init(struct kvm_vcpu *vcpu)
{
vcpu->arch.target = -1;
bitmap_zero(vcpu->arch.features, KVM_VCPU_MAX_FEATURES);
kvm_timer_vcpu_init(vcpu);
return 0;
}
void kvm_arch_vcpu_load(struct kvm_vcpu *vcpu, int cpu)
{
vcpu->cpu = cpu;
vcpu->arch.host_cpu_context = this_cpu_ptr(kvm_host_cpu_state);
kvm_arm_set_running_vcpu(vcpu);
}
void kvm_arch_vcpu_put(struct kvm_vcpu *vcpu)
{
vcpu->cpu = -1;
kvm_arm_set_running_vcpu(NULL);
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
int kvm_arch_vcpu_runnable(struct kvm_vcpu *v)
{
return !!v->arch.irq_lines || kvm_vgic_vcpu_pending_irq(v);
}
static void exit_vm_noop(void *info)
{
}
void force_vm_exit(const cpumask_t *mask)
{
smp_call_function_many(mask, exit_vm_noop, NULL, true);
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
pgd_phys = virt_to_phys(kvm_get_hwpgd(kvm));
BUG_ON(pgd_phys & ~VTTBR_BADDR_MASK);
vmid = ((u64)(kvm->arch.vmid) << VTTBR_VMID_SHIFT) & VTTBR_VMID_MASK;
kvm->arch.vttbr = pgd_phys | vmid;
spin_unlock(&kvm_vmid_lock);
}
static int kvm_vcpu_first_run_init(struct kvm_vcpu *vcpu)
{
struct kvm *kvm = vcpu->kvm;
int ret;
if (likely(vcpu->arch.has_run_once))
return 0;
vcpu->arch.has_run_once = true;
if (unlikely(!vgic_ready(kvm))) {
ret = kvm_vgic_map_resources(kvm);
if (ret)
return ret;
}
if (irqchip_in_kernel(kvm) && vgic_initialized(kvm))
kvm_timer_enable(kvm);
return 0;
}
static void vcpu_pause(struct kvm_vcpu *vcpu)
{
wait_queue_head_t *wq = kvm_arch_vcpu_wq(vcpu);
wait_event_interruptible(*wq, !vcpu->arch.pause);
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
if (vcpu->sigset_active)
sigprocmask(SIG_SETMASK, &vcpu->sigset, &sigsaved);
ret = 1;
run->exit_reason = KVM_EXIT_UNKNOWN;
while (ret > 0) {
cond_resched();
update_vttbr(vcpu->kvm);
if (vcpu->arch.pause)
vcpu_pause(vcpu);
kvm_vgic_flush_hwstate(vcpu);
kvm_timer_flush_hwstate(vcpu);
local_irq_disable();
if (signal_pending(current)) {
ret = -EINTR;
run->exit_reason = KVM_EXIT_INTR;
}
if (ret <= 0 || need_new_vmid_gen(vcpu->kvm)) {
local_irq_enable();
kvm_timer_sync_hwstate(vcpu);
kvm_vgic_sync_hwstate(vcpu);
continue;
}
trace_kvm_entry(*vcpu_pc(vcpu));
kvm_guest_enter();
vcpu->mode = IN_GUEST_MODE;
ret = kvm_call_hyp(__kvm_vcpu_run, vcpu);
vcpu->mode = OUTSIDE_GUEST_MODE;
kvm_guest_exit();
trace_kvm_exit(*vcpu_pc(vcpu));
local_irq_enable();
kvm_timer_sync_hwstate(vcpu);
kvm_vgic_sync_hwstate(vcpu);
ret = handle_exit(vcpu, run, ret);
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
if (irq_num < VGIC_NR_PRIVATE_IRQS ||
irq_num > KVM_ARM_IRQ_GIC_MAX)
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
vcpu->arch.pause = true;
else
vcpu->arch.pause = false;
return 0;
}
long kvm_arch_vcpu_ioctl(struct file *filp,
unsigned int ioctl, unsigned long arg)
{
struct kvm_vcpu *vcpu = filp->private_data;
void __user *argp = (void __user *)arg;
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
default:
return -EINVAL;
}
}
int kvm_vm_ioctl_get_dirty_log(struct kvm *kvm, struct kvm_dirty_log *log)
{
return -EINVAL;
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
if (vgic_present)
return kvm_vgic_create(kvm);
else
return -ENXIO;
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
phys_addr_t boot_pgd_ptr;
phys_addr_t pgd_ptr;
unsigned long hyp_stack_ptr;
unsigned long stack_page;
unsigned long vector_ptr;
__hyp_set_vectors(kvm_get_idmap_vector());
boot_pgd_ptr = kvm_mmu_get_boot_httbr();
pgd_ptr = kvm_mmu_get_httbr();
stack_page = __this_cpu_read(kvm_arm_hyp_stack_page);
hyp_stack_ptr = stack_page + PAGE_SIZE;
vector_ptr = (unsigned long)__kvm_hyp_vector;
__cpu_init_hyp_mode(boot_pgd_ptr, pgd_ptr, hyp_stack_ptr, vector_ptr);
}
static int hyp_init_cpu_notify(struct notifier_block *self,
unsigned long action, void *cpu)
{
switch (action) {
case CPU_STARTING:
case CPU_STARTING_FROZEN:
if (__hyp_get_vectors() == hyp_default_vectors)
cpu_init_hyp_mode(NULL);
break;
}
return NOTIFY_OK;
}
static int hyp_init_cpu_pm_notifier(struct notifier_block *self,
unsigned long cmd,
void *v)
{
if (cmd == CPU_PM_EXIT &&
__hyp_get_vectors() == hyp_default_vectors) {
cpu_init_hyp_mode(NULL);
return NOTIFY_OK;
}
return NOTIFY_DONE;
}
static void __init hyp_cpu_pm_init(void)
{
cpu_pm_register_notifier(&hyp_init_cpu_pm_nb);
}
static inline void hyp_cpu_pm_init(void)
{
}
static int init_hyp_mode(void)
{
int cpu;
int err = 0;
err = kvm_mmu_init();
if (err)
goto out_err;
hyp_default_vectors = __hyp_get_vectors();
for_each_possible_cpu(cpu) {
unsigned long stack_page;
stack_page = __get_free_page(GFP_KERNEL);
if (!stack_page) {
err = -ENOMEM;
goto out_free_stack_pages;
}
per_cpu(kvm_arm_hyp_stack_page, cpu) = stack_page;
}
err = create_hyp_mappings(__kvm_hyp_code_start, __kvm_hyp_code_end);
if (err) {
kvm_err("Cannot map world-switch code\n");
goto out_free_mappings;
}
for_each_possible_cpu(cpu) {
char *stack_page = (char *)per_cpu(kvm_arm_hyp_stack_page, cpu);
err = create_hyp_mappings(stack_page, stack_page + PAGE_SIZE);
if (err) {
kvm_err("Cannot map hyp stack\n");
goto out_free_mappings;
}
}
kvm_host_cpu_state = alloc_percpu(kvm_cpu_context_t);
if (!kvm_host_cpu_state) {
err = -ENOMEM;
kvm_err("Cannot allocate host CPU state\n");
goto out_free_mappings;
}
for_each_possible_cpu(cpu) {
kvm_cpu_context_t *cpu_ctxt;
cpu_ctxt = per_cpu_ptr(kvm_host_cpu_state, cpu);
err = create_hyp_mappings(cpu_ctxt, cpu_ctxt + 1);
if (err) {
kvm_err("Cannot map host CPU state: %d\n", err);
goto out_free_context;
}
}
on_each_cpu(cpu_init_hyp_mode, NULL, 1);
err = kvm_vgic_hyp_init();
if (err)
goto out_free_context;
#ifdef CONFIG_KVM_ARM_VGIC
vgic_present = true;
#endif
err = kvm_timer_hyp_init();
if (err)
goto out_free_mappings;
#ifndef CONFIG_HOTPLUG_CPU
free_boot_hyp_pgd();
#endif
kvm_perf_init();
kvm_info("Hyp mode initialized successfully\n");
return 0;
out_free_context:
free_percpu(kvm_host_cpu_state);
out_free_mappings:
free_hyp_pgds();
out_free_stack_pages:
for_each_possible_cpu(cpu)
free_page(per_cpu(kvm_arm_hyp_stack_page, cpu));
out_err:
kvm_err("error initializing Hyp mode: %d\n", err);
return err;
}
static void check_kvm_target_cpu(void *ret)
{
*(int *)ret = kvm_target_cpu();
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
cpu_notifier_register_begin();
err = init_hyp_mode();
if (err)
goto out_err;
err = __register_cpu_notifier(&hyp_init_cpu_nb);
if (err) {
kvm_err("Cannot register HYP init CPU notifier (%d)\n", err);
goto out_err;
}
cpu_notifier_register_done();
hyp_cpu_pm_init();
kvm_coproc_table_init();
return 0;
out_err:
cpu_notifier_register_done();
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
