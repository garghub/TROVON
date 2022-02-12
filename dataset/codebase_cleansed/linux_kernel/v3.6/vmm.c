static int __init kvm_vmm_init(void)
{
vmm_fpswa_interface = fpswa_interface;
return kvm_init(&vmm_info, 1024, 0, THIS_MODULE);
}
static void __exit kvm_vmm_exit(void)
{
kvm_exit();
return ;
}
void vmm_spin_lock(vmm_spinlock_t *lock)
{
_vmm_raw_spin_lock(lock);
}
void vmm_spin_unlock(vmm_spinlock_t *lock)
{
_vmm_raw_spin_unlock(lock);
}
static void vcpu_debug_exit(struct kvm_vcpu *vcpu)
{
struct exit_ctl_data *p = &vcpu->arch.exit_data;
long psr;
local_irq_save(psr);
p->exit_reason = EXIT_REASON_DEBUG;
vmm_transition(vcpu);
local_irq_restore(psr);
}
asmlinkage int printk(const char *fmt, ...)
{
struct kvm_vcpu *vcpu = current_vcpu;
va_list args;
int r;
memset(vcpu->arch.log_buf, 0, VMM_LOG_LEN);
va_start(args, fmt);
r = vsnprintf(vcpu->arch.log_buf, VMM_LOG_LEN, fmt, args);
va_end(args);
vcpu_debug_exit(vcpu);
return r;
}
