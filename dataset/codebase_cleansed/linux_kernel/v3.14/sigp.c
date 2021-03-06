static int __sigp_sense(struct kvm_vcpu *vcpu, u16 cpu_addr,
u64 *reg)
{
struct kvm_s390_float_interrupt *fi = &vcpu->kvm->arch.float_int;
int rc;
if (cpu_addr >= KVM_MAX_VCPUS)
return SIGP_CC_NOT_OPERATIONAL;
spin_lock(&fi->lock);
if (fi->local_int[cpu_addr] == NULL)
rc = SIGP_CC_NOT_OPERATIONAL;
else if (!(atomic_read(fi->local_int[cpu_addr]->cpuflags)
& (CPUSTAT_ECALL_PEND | CPUSTAT_STOPPED)))
rc = SIGP_CC_ORDER_CODE_ACCEPTED;
else {
*reg &= 0xffffffff00000000UL;
if (atomic_read(fi->local_int[cpu_addr]->cpuflags)
& CPUSTAT_ECALL_PEND)
*reg |= SIGP_STATUS_EXT_CALL_PENDING;
if (atomic_read(fi->local_int[cpu_addr]->cpuflags)
& CPUSTAT_STOPPED)
*reg |= SIGP_STATUS_STOPPED;
rc = SIGP_CC_STATUS_STORED;
}
spin_unlock(&fi->lock);
VCPU_EVENT(vcpu, 4, "sensed status of cpu %x rc %x", cpu_addr, rc);
return rc;
}
static int __sigp_emergency(struct kvm_vcpu *vcpu, u16 cpu_addr)
{
struct kvm_s390_float_interrupt *fi = &vcpu->kvm->arch.float_int;
struct kvm_s390_local_interrupt *li;
struct kvm_s390_interrupt_info *inti;
int rc;
if (cpu_addr >= KVM_MAX_VCPUS)
return SIGP_CC_NOT_OPERATIONAL;
inti = kzalloc(sizeof(*inti), GFP_KERNEL);
if (!inti)
return -ENOMEM;
inti->type = KVM_S390_INT_EMERGENCY;
inti->emerg.code = vcpu->vcpu_id;
spin_lock(&fi->lock);
li = fi->local_int[cpu_addr];
if (li == NULL) {
rc = SIGP_CC_NOT_OPERATIONAL;
kfree(inti);
goto unlock;
}
spin_lock_bh(&li->lock);
list_add_tail(&inti->list, &li->list);
atomic_set(&li->active, 1);
atomic_set_mask(CPUSTAT_EXT_INT, li->cpuflags);
if (waitqueue_active(li->wq))
wake_up_interruptible(li->wq);
spin_unlock_bh(&li->lock);
rc = SIGP_CC_ORDER_CODE_ACCEPTED;
VCPU_EVENT(vcpu, 4, "sent sigp emerg to cpu %x", cpu_addr);
unlock:
spin_unlock(&fi->lock);
return rc;
}
static int __sigp_conditional_emergency(struct kvm_vcpu *vcpu, u16 cpu_addr,
u16 asn, u64 *reg)
{
struct kvm_vcpu *dst_vcpu = NULL;
const u64 psw_int_mask = PSW_MASK_IO | PSW_MASK_EXT;
u16 p_asn, s_asn;
psw_t *psw;
u32 flags;
if (cpu_addr < KVM_MAX_VCPUS)
dst_vcpu = kvm_get_vcpu(vcpu->kvm, cpu_addr);
if (!dst_vcpu)
return SIGP_CC_NOT_OPERATIONAL;
flags = atomic_read(&dst_vcpu->arch.sie_block->cpuflags);
psw = &dst_vcpu->arch.sie_block->gpsw;
p_asn = dst_vcpu->arch.sie_block->gcr[4] & 0xffff;
s_asn = dst_vcpu->arch.sie_block->gcr[3] & 0xffff;
if (!(flags & CPUSTAT_STOPPED)
|| (psw->mask & psw_int_mask) != psw_int_mask
|| ((flags & CPUSTAT_WAIT) && psw->addr != 0)
|| (!(flags & CPUSTAT_WAIT) && (asn == p_asn || asn == s_asn))) {
return __sigp_emergency(vcpu, cpu_addr);
} else {
*reg &= 0xffffffff00000000UL;
*reg |= SIGP_STATUS_INCORRECT_STATE;
return SIGP_CC_STATUS_STORED;
}
}
static int __sigp_external_call(struct kvm_vcpu *vcpu, u16 cpu_addr)
{
struct kvm_s390_float_interrupt *fi = &vcpu->kvm->arch.float_int;
struct kvm_s390_local_interrupt *li;
struct kvm_s390_interrupt_info *inti;
int rc;
if (cpu_addr >= KVM_MAX_VCPUS)
return SIGP_CC_NOT_OPERATIONAL;
inti = kzalloc(sizeof(*inti), GFP_KERNEL);
if (!inti)
return -ENOMEM;
inti->type = KVM_S390_INT_EXTERNAL_CALL;
inti->extcall.code = vcpu->vcpu_id;
spin_lock(&fi->lock);
li = fi->local_int[cpu_addr];
if (li == NULL) {
rc = SIGP_CC_NOT_OPERATIONAL;
kfree(inti);
goto unlock;
}
spin_lock_bh(&li->lock);
list_add_tail(&inti->list, &li->list);
atomic_set(&li->active, 1);
atomic_set_mask(CPUSTAT_EXT_INT, li->cpuflags);
if (waitqueue_active(li->wq))
wake_up_interruptible(li->wq);
spin_unlock_bh(&li->lock);
rc = SIGP_CC_ORDER_CODE_ACCEPTED;
VCPU_EVENT(vcpu, 4, "sent sigp ext call to cpu %x", cpu_addr);
unlock:
spin_unlock(&fi->lock);
return rc;
}
static int __inject_sigp_stop(struct kvm_s390_local_interrupt *li, int action)
{
struct kvm_s390_interrupt_info *inti;
int rc = SIGP_CC_ORDER_CODE_ACCEPTED;
inti = kzalloc(sizeof(*inti), GFP_ATOMIC);
if (!inti)
return -ENOMEM;
inti->type = KVM_S390_SIGP_STOP;
spin_lock_bh(&li->lock);
if ((atomic_read(li->cpuflags) & CPUSTAT_STOPPED)) {
kfree(inti);
if ((action & ACTION_STORE_ON_STOP) != 0)
rc = -ESHUTDOWN;
goto out;
}
list_add_tail(&inti->list, &li->list);
atomic_set(&li->active, 1);
atomic_set_mask(CPUSTAT_STOP_INT, li->cpuflags);
li->action_bits |= action;
if (waitqueue_active(li->wq))
wake_up_interruptible(li->wq);
out:
spin_unlock_bh(&li->lock);
return rc;
}
static int __sigp_stop(struct kvm_vcpu *vcpu, u16 cpu_addr, int action)
{
struct kvm_s390_float_interrupt *fi = &vcpu->kvm->arch.float_int;
struct kvm_s390_local_interrupt *li;
int rc;
if (cpu_addr >= KVM_MAX_VCPUS)
return SIGP_CC_NOT_OPERATIONAL;
spin_lock(&fi->lock);
li = fi->local_int[cpu_addr];
if (li == NULL) {
rc = SIGP_CC_NOT_OPERATIONAL;
goto unlock;
}
rc = __inject_sigp_stop(li, action);
unlock:
spin_unlock(&fi->lock);
VCPU_EVENT(vcpu, 4, "sent sigp stop to cpu %x", cpu_addr);
if ((action & ACTION_STORE_ON_STOP) != 0 && rc == -ESHUTDOWN) {
struct kvm_vcpu *dst_vcpu = kvm_get_vcpu(vcpu->kvm, cpu_addr);
rc = kvm_s390_store_status_unloaded(dst_vcpu,
KVM_S390_STORE_STATUS_NOADDR);
}
return rc;
}
static int __sigp_set_arch(struct kvm_vcpu *vcpu, u32 parameter)
{
int rc;
switch (parameter & 0xff) {
case 0:
rc = SIGP_CC_NOT_OPERATIONAL;
break;
case 1:
case 2:
rc = SIGP_CC_ORDER_CODE_ACCEPTED;
break;
default:
rc = -EOPNOTSUPP;
}
return rc;
}
static int __sigp_set_prefix(struct kvm_vcpu *vcpu, u16 cpu_addr, u32 address,
u64 *reg)
{
struct kvm_s390_float_interrupt *fi = &vcpu->kvm->arch.float_int;
struct kvm_s390_local_interrupt *li = NULL;
struct kvm_s390_interrupt_info *inti;
int rc;
u8 tmp;
address = address & 0x7fffe000u;
if (copy_from_guest_absolute(vcpu, &tmp, address, 1) ||
copy_from_guest_absolute(vcpu, &tmp, address + PAGE_SIZE, 1)) {
*reg &= 0xffffffff00000000UL;
*reg |= SIGP_STATUS_INVALID_PARAMETER;
return SIGP_CC_STATUS_STORED;
}
inti = kzalloc(sizeof(*inti), GFP_KERNEL);
if (!inti)
return SIGP_CC_BUSY;
spin_lock(&fi->lock);
if (cpu_addr < KVM_MAX_VCPUS)
li = fi->local_int[cpu_addr];
if (li == NULL) {
*reg &= 0xffffffff00000000UL;
*reg |= SIGP_STATUS_INCORRECT_STATE;
rc = SIGP_CC_STATUS_STORED;
kfree(inti);
goto out_fi;
}
spin_lock_bh(&li->lock);
if (!(atomic_read(li->cpuflags) & CPUSTAT_STOPPED)) {
*reg &= 0xffffffff00000000UL;
*reg |= SIGP_STATUS_INCORRECT_STATE;
rc = SIGP_CC_STATUS_STORED;
kfree(inti);
goto out_li;
}
inti->type = KVM_S390_SIGP_SET_PREFIX;
inti->prefix.address = address;
list_add_tail(&inti->list, &li->list);
atomic_set(&li->active, 1);
if (waitqueue_active(li->wq))
wake_up_interruptible(li->wq);
rc = SIGP_CC_ORDER_CODE_ACCEPTED;
VCPU_EVENT(vcpu, 4, "set prefix of cpu %02x to %x", cpu_addr, address);
out_li:
spin_unlock_bh(&li->lock);
out_fi:
spin_unlock(&fi->lock);
return rc;
}
static int __sigp_store_status_at_addr(struct kvm_vcpu *vcpu, u16 cpu_id,
u32 addr, u64 *reg)
{
struct kvm_vcpu *dst_vcpu = NULL;
int flags;
int rc;
if (cpu_id < KVM_MAX_VCPUS)
dst_vcpu = kvm_get_vcpu(vcpu->kvm, cpu_id);
if (!dst_vcpu)
return SIGP_CC_NOT_OPERATIONAL;
spin_lock_bh(&dst_vcpu->arch.local_int.lock);
flags = atomic_read(dst_vcpu->arch.local_int.cpuflags);
spin_unlock_bh(&dst_vcpu->arch.local_int.lock);
if (!(flags & CPUSTAT_STOPPED)) {
*reg &= 0xffffffff00000000UL;
*reg |= SIGP_STATUS_INCORRECT_STATE;
return SIGP_CC_STATUS_STORED;
}
addr &= 0x7ffffe00;
rc = kvm_s390_store_status_unloaded(dst_vcpu, addr);
if (rc == -EFAULT) {
*reg &= 0xffffffff00000000UL;
*reg |= SIGP_STATUS_INVALID_PARAMETER;
rc = SIGP_CC_STATUS_STORED;
}
return rc;
}
static int __sigp_sense_running(struct kvm_vcpu *vcpu, u16 cpu_addr,
u64 *reg)
{
int rc;
struct kvm_s390_float_interrupt *fi = &vcpu->kvm->arch.float_int;
if (cpu_addr >= KVM_MAX_VCPUS)
return SIGP_CC_NOT_OPERATIONAL;
spin_lock(&fi->lock);
if (fi->local_int[cpu_addr] == NULL)
rc = SIGP_CC_NOT_OPERATIONAL;
else {
if (atomic_read(fi->local_int[cpu_addr]->cpuflags)
& CPUSTAT_RUNNING) {
rc = SIGP_CC_ORDER_CODE_ACCEPTED;
} else {
*reg &= 0xffffffff00000000UL;
*reg |= SIGP_STATUS_NOT_RUNNING;
rc = SIGP_CC_STATUS_STORED;
}
}
spin_unlock(&fi->lock);
VCPU_EVENT(vcpu, 4, "sensed running status of cpu %x rc %x", cpu_addr,
rc);
return rc;
}
static int sigp_check_callable(struct kvm_vcpu *vcpu, u16 cpu_addr)
{
struct kvm_s390_float_interrupt *fi = &vcpu->kvm->arch.float_int;
struct kvm_s390_local_interrupt *li;
int rc = SIGP_CC_ORDER_CODE_ACCEPTED;
if (cpu_addr >= KVM_MAX_VCPUS)
return SIGP_CC_NOT_OPERATIONAL;
spin_lock(&fi->lock);
li = fi->local_int[cpu_addr];
if (li == NULL) {
rc = SIGP_CC_NOT_OPERATIONAL;
goto out;
}
spin_lock_bh(&li->lock);
if (li->action_bits & ACTION_STOP_ON_STOP)
rc = SIGP_CC_BUSY;
spin_unlock_bh(&li->lock);
out:
spin_unlock(&fi->lock);
return rc;
}
int kvm_s390_handle_sigp(struct kvm_vcpu *vcpu)
{
int r1 = (vcpu->arch.sie_block->ipa & 0x00f0) >> 4;
int r3 = vcpu->arch.sie_block->ipa & 0x000f;
u32 parameter;
u16 cpu_addr = vcpu->run->s.regs.gprs[r3];
u8 order_code;
int rc;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
order_code = kvm_s390_get_base_disp_rs(vcpu);
if (r1 % 2)
parameter = vcpu->run->s.regs.gprs[r1];
else
parameter = vcpu->run->s.regs.gprs[r1 + 1];
trace_kvm_s390_handle_sigp(vcpu, order_code, cpu_addr, parameter);
switch (order_code) {
case SIGP_SENSE:
vcpu->stat.instruction_sigp_sense++;
rc = __sigp_sense(vcpu, cpu_addr,
&vcpu->run->s.regs.gprs[r1]);
break;
case SIGP_EXTERNAL_CALL:
vcpu->stat.instruction_sigp_external_call++;
rc = __sigp_external_call(vcpu, cpu_addr);
break;
case SIGP_EMERGENCY_SIGNAL:
vcpu->stat.instruction_sigp_emergency++;
rc = __sigp_emergency(vcpu, cpu_addr);
break;
case SIGP_STOP:
vcpu->stat.instruction_sigp_stop++;
rc = __sigp_stop(vcpu, cpu_addr, ACTION_STOP_ON_STOP);
break;
case SIGP_STOP_AND_STORE_STATUS:
vcpu->stat.instruction_sigp_stop++;
rc = __sigp_stop(vcpu, cpu_addr, ACTION_STORE_ON_STOP |
ACTION_STOP_ON_STOP);
break;
case SIGP_STORE_STATUS_AT_ADDRESS:
rc = __sigp_store_status_at_addr(vcpu, cpu_addr, parameter,
&vcpu->run->s.regs.gprs[r1]);
break;
case SIGP_SET_ARCHITECTURE:
vcpu->stat.instruction_sigp_arch++;
rc = __sigp_set_arch(vcpu, parameter);
break;
case SIGP_SET_PREFIX:
vcpu->stat.instruction_sigp_prefix++;
rc = __sigp_set_prefix(vcpu, cpu_addr, parameter,
&vcpu->run->s.regs.gprs[r1]);
break;
case SIGP_COND_EMERGENCY_SIGNAL:
rc = __sigp_conditional_emergency(vcpu, cpu_addr, parameter,
&vcpu->run->s.regs.gprs[r1]);
break;
case SIGP_SENSE_RUNNING:
vcpu->stat.instruction_sigp_sense_running++;
rc = __sigp_sense_running(vcpu, cpu_addr,
&vcpu->run->s.regs.gprs[r1]);
break;
case SIGP_START:
rc = sigp_check_callable(vcpu, cpu_addr);
if (rc == SIGP_CC_ORDER_CODE_ACCEPTED)
rc = -EOPNOTSUPP;
break;
case SIGP_RESTART:
vcpu->stat.instruction_sigp_restart++;
rc = sigp_check_callable(vcpu, cpu_addr);
if (rc == SIGP_CC_ORDER_CODE_ACCEPTED) {
VCPU_EVENT(vcpu, 4,
"sigp restart %x to handle userspace",
cpu_addr);
rc = -EOPNOTSUPP;
}
break;
default:
return -EOPNOTSUPP;
}
if (rc < 0)
return rc;
kvm_s390_set_psw_cc(vcpu, rc);
return 0;
}
