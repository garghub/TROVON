static void kvmppc_fast_vcpu_kick_hv(struct kvm_vcpu *vcpu)
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
if (cpu != me && cpu >= 0 && cpu < nr_cpu_ids) {
#ifdef CONFIG_PPC_ICP_NATIVE
int real_cpu = cpu + vcpu->arch.ptid;
if (paca[real_cpu].kvm_hstate.xics_phys)
xics_wake_cpu(real_cpu);
else
#endif
if (cpu_online(cpu))
smp_send_reschedule(cpu);
}
put_cpu();
}
static void kvmppc_core_vcpu_load_hv(struct kvm_vcpu *vcpu, int cpu)
{
struct kvmppc_vcore *vc = vcpu->arch.vcore;
unsigned long flags;
if (vc->runner == vcpu && vc->vcore_state != VCORE_INACTIVE) {
spin_lock_irqsave(&vc->stoltb_lock, flags);
if (vc->preempt_tb != TB_NIL) {
vc->stolen_tb += mftb() - vc->preempt_tb;
vc->preempt_tb = TB_NIL;
}
spin_unlock_irqrestore(&vc->stoltb_lock, flags);
}
spin_lock_irqsave(&vcpu->arch.tbacct_lock, flags);
if (vcpu->arch.state == KVMPPC_VCPU_BUSY_IN_HOST &&
vcpu->arch.busy_preempt != TB_NIL) {
vcpu->arch.busy_stolen += mftb() - vcpu->arch.busy_preempt;
vcpu->arch.busy_preempt = TB_NIL;
}
spin_unlock_irqrestore(&vcpu->arch.tbacct_lock, flags);
}
static void kvmppc_core_vcpu_put_hv(struct kvm_vcpu *vcpu)
{
struct kvmppc_vcore *vc = vcpu->arch.vcore;
unsigned long flags;
if (vc->runner == vcpu && vc->vcore_state != VCORE_INACTIVE) {
spin_lock_irqsave(&vc->stoltb_lock, flags);
vc->preempt_tb = mftb();
spin_unlock_irqrestore(&vc->stoltb_lock, flags);
}
spin_lock_irqsave(&vcpu->arch.tbacct_lock, flags);
if (vcpu->arch.state == KVMPPC_VCPU_BUSY_IN_HOST)
vcpu->arch.busy_preempt = mftb();
spin_unlock_irqrestore(&vcpu->arch.tbacct_lock, flags);
}
static void kvmppc_set_msr_hv(struct kvm_vcpu *vcpu, u64 msr)
{
vcpu->arch.shregs.msr = msr;
kvmppc_end_cede(vcpu);
}
void kvmppc_set_pvr_hv(struct kvm_vcpu *vcpu, u32 pvr)
{
vcpu->arch.pvr = pvr;
}
int kvmppc_set_arch_compat(struct kvm_vcpu *vcpu, u32 arch_compat)
{
unsigned long pcr = 0;
struct kvmppc_vcore *vc = vcpu->arch.vcore;
if (arch_compat) {
switch (arch_compat) {
case PVR_ARCH_205:
pcr = PCR_ARCH_206 | PCR_ARCH_205;
break;
case PVR_ARCH_206:
case PVR_ARCH_206p:
pcr = PCR_ARCH_206;
break;
case PVR_ARCH_207:
break;
default:
return -EINVAL;
}
if (!cpu_has_feature(CPU_FTR_ARCH_207S)) {
if (!(pcr & PCR_ARCH_206))
return -EINVAL;
pcr &= ~PCR_ARCH_206;
}
}
spin_lock(&vc->lock);
vc->arch_compat = arch_compat;
vc->pcr = pcr;
spin_unlock(&vc->lock);
return 0;
}
void kvmppc_dump_regs(struct kvm_vcpu *vcpu)
{
int r;
pr_err("vcpu %p (%d):\n", vcpu, vcpu->vcpu_id);
pr_err("pc = %.16lx msr = %.16llx trap = %x\n",
vcpu->arch.pc, vcpu->arch.shregs.msr, vcpu->arch.trap);
for (r = 0; r < 16; ++r)
pr_err("r%2d = %.16lx r%d = %.16lx\n",
r, kvmppc_get_gpr(vcpu, r),
r+16, kvmppc_get_gpr(vcpu, r+16));
pr_err("ctr = %.16lx lr = %.16lx\n",
vcpu->arch.ctr, vcpu->arch.lr);
pr_err("srr0 = %.16llx srr1 = %.16llx\n",
vcpu->arch.shregs.srr0, vcpu->arch.shregs.srr1);
pr_err("sprg0 = %.16llx sprg1 = %.16llx\n",
vcpu->arch.shregs.sprg0, vcpu->arch.shregs.sprg1);
pr_err("sprg2 = %.16llx sprg3 = %.16llx\n",
vcpu->arch.shregs.sprg2, vcpu->arch.shregs.sprg3);
pr_err("cr = %.8x xer = %.16lx dsisr = %.8x\n",
vcpu->arch.cr, vcpu->arch.xer, vcpu->arch.shregs.dsisr);
pr_err("dar = %.16llx\n", vcpu->arch.shregs.dar);
pr_err("fault dar = %.16lx dsisr = %.8x\n",
vcpu->arch.fault_dar, vcpu->arch.fault_dsisr);
pr_err("SLB (%d entries):\n", vcpu->arch.slb_max);
for (r = 0; r < vcpu->arch.slb_max; ++r)
pr_err(" ESID = %.16llx VSID = %.16llx\n",
vcpu->arch.slb[r].orige, vcpu->arch.slb[r].origv);
pr_err("lpcr = %.16lx sdr1 = %.16lx last_inst = %.8x\n",
vcpu->arch.vcore->lpcr, vcpu->kvm->arch.sdr1,
vcpu->arch.last_inst);
}
struct kvm_vcpu *kvmppc_find_vcpu(struct kvm *kvm, int id)
{
int r;
struct kvm_vcpu *v, *ret = NULL;
mutex_lock(&kvm->lock);
kvm_for_each_vcpu(r, v, kvm) {
if (v->vcpu_id == id) {
ret = v;
break;
}
}
mutex_unlock(&kvm->lock);
return ret;
}
static void init_vpa(struct kvm_vcpu *vcpu, struct lppaca *vpa)
{
vpa->__old_status |= LPPACA_OLD_SHARED_PROC;
vpa->yield_count = cpu_to_be32(1);
}
static int set_vpa(struct kvm_vcpu *vcpu, struct kvmppc_vpa *v,
unsigned long addr, unsigned long len)
{
if (addr & (L1_CACHE_BYTES - 1))
return -EINVAL;
spin_lock(&vcpu->arch.vpa_update_lock);
if (v->next_gpa != addr || v->len != len) {
v->next_gpa = addr;
v->len = addr ? len : 0;
v->update_pending = 1;
}
spin_unlock(&vcpu->arch.vpa_update_lock);
return 0;
}
static int vpa_is_registered(struct kvmppc_vpa *vpap)
{
if (vpap->update_pending)
return vpap->next_gpa != 0;
return vpap->pinned_addr != NULL;
}
static unsigned long do_h_register_vpa(struct kvm_vcpu *vcpu,
unsigned long flags,
unsigned long vcpuid, unsigned long vpa)
{
struct kvm *kvm = vcpu->kvm;
unsigned long len, nb;
void *va;
struct kvm_vcpu *tvcpu;
int err;
int subfunc;
struct kvmppc_vpa *vpap;
tvcpu = kvmppc_find_vcpu(kvm, vcpuid);
if (!tvcpu)
return H_PARAMETER;
subfunc = (flags >> H_VPA_FUNC_SHIFT) & H_VPA_FUNC_MASK;
if (subfunc == H_VPA_REG_VPA || subfunc == H_VPA_REG_DTL ||
subfunc == H_VPA_REG_SLB) {
if ((vpa & (L1_CACHE_BYTES - 1)) || !vpa)
return H_PARAMETER;
va = kvmppc_pin_guest_page(kvm, vpa, &nb);
if (va == NULL)
return H_PARAMETER;
if (subfunc == H_VPA_REG_VPA)
len = be16_to_cpu(((struct reg_vpa *)va)->length.hword);
else
len = be32_to_cpu(((struct reg_vpa *)va)->length.word);
kvmppc_unpin_guest_page(kvm, va, vpa, false);
if (len > nb || len < sizeof(struct reg_vpa))
return H_PARAMETER;
} else {
vpa = 0;
len = 0;
}
err = H_PARAMETER;
vpap = NULL;
spin_lock(&tvcpu->arch.vpa_update_lock);
switch (subfunc) {
case H_VPA_REG_VPA:
if (len < sizeof(struct lppaca))
break;
vpap = &tvcpu->arch.vpa;
err = 0;
break;
case H_VPA_REG_DTL:
if (len < sizeof(struct dtl_entry))
break;
len -= len % sizeof(struct dtl_entry);
err = H_RESOURCE;
if (!vpa_is_registered(&tvcpu->arch.vpa))
break;
vpap = &tvcpu->arch.dtl;
err = 0;
break;
case H_VPA_REG_SLB:
err = H_RESOURCE;
if (!vpa_is_registered(&tvcpu->arch.vpa))
break;
vpap = &tvcpu->arch.slb_shadow;
err = 0;
break;
case H_VPA_DEREG_VPA:
err = H_RESOURCE;
if (vpa_is_registered(&tvcpu->arch.dtl) ||
vpa_is_registered(&tvcpu->arch.slb_shadow))
break;
vpap = &tvcpu->arch.vpa;
err = 0;
break;
case H_VPA_DEREG_DTL:
vpap = &tvcpu->arch.dtl;
err = 0;
break;
case H_VPA_DEREG_SLB:
vpap = &tvcpu->arch.slb_shadow;
err = 0;
break;
}
if (vpap) {
vpap->next_gpa = vpa;
vpap->len = len;
vpap->update_pending = 1;
}
spin_unlock(&tvcpu->arch.vpa_update_lock);
return err;
}
static void kvmppc_update_vpa(struct kvm_vcpu *vcpu, struct kvmppc_vpa *vpap)
{
struct kvm *kvm = vcpu->kvm;
void *va;
unsigned long nb;
unsigned long gpa;
for (;;) {
gpa = vpap->next_gpa;
spin_unlock(&vcpu->arch.vpa_update_lock);
va = NULL;
nb = 0;
if (gpa)
va = kvmppc_pin_guest_page(kvm, gpa, &nb);
spin_lock(&vcpu->arch.vpa_update_lock);
if (gpa == vpap->next_gpa)
break;
if (va)
kvmppc_unpin_guest_page(kvm, va, gpa, false);
}
vpap->update_pending = 0;
if (va && nb < vpap->len) {
kvmppc_unpin_guest_page(kvm, va, gpa, false);
va = NULL;
}
if (vpap->pinned_addr)
kvmppc_unpin_guest_page(kvm, vpap->pinned_addr, vpap->gpa,
vpap->dirty);
vpap->gpa = gpa;
vpap->pinned_addr = va;
vpap->dirty = false;
if (va)
vpap->pinned_end = va + vpap->len;
}
static void kvmppc_update_vpas(struct kvm_vcpu *vcpu)
{
if (!(vcpu->arch.vpa.update_pending ||
vcpu->arch.slb_shadow.update_pending ||
vcpu->arch.dtl.update_pending))
return;
spin_lock(&vcpu->arch.vpa_update_lock);
if (vcpu->arch.vpa.update_pending) {
kvmppc_update_vpa(vcpu, &vcpu->arch.vpa);
if (vcpu->arch.vpa.pinned_addr)
init_vpa(vcpu, vcpu->arch.vpa.pinned_addr);
}
if (vcpu->arch.dtl.update_pending) {
kvmppc_update_vpa(vcpu, &vcpu->arch.dtl);
vcpu->arch.dtl_ptr = vcpu->arch.dtl.pinned_addr;
vcpu->arch.dtl_index = 0;
}
if (vcpu->arch.slb_shadow.update_pending)
kvmppc_update_vpa(vcpu, &vcpu->arch.slb_shadow);
spin_unlock(&vcpu->arch.vpa_update_lock);
}
static u64 vcore_stolen_time(struct kvmppc_vcore *vc, u64 now)
{
u64 p;
unsigned long flags;
spin_lock_irqsave(&vc->stoltb_lock, flags);
p = vc->stolen_tb;
if (vc->vcore_state != VCORE_INACTIVE &&
vc->preempt_tb != TB_NIL)
p += now - vc->preempt_tb;
spin_unlock_irqrestore(&vc->stoltb_lock, flags);
return p;
}
static void kvmppc_create_dtl_entry(struct kvm_vcpu *vcpu,
struct kvmppc_vcore *vc)
{
struct dtl_entry *dt;
struct lppaca *vpa;
unsigned long stolen;
unsigned long core_stolen;
u64 now;
dt = vcpu->arch.dtl_ptr;
vpa = vcpu->arch.vpa.pinned_addr;
now = mftb();
core_stolen = vcore_stolen_time(vc, now);
stolen = core_stolen - vcpu->arch.stolen_logged;
vcpu->arch.stolen_logged = core_stolen;
spin_lock_irq(&vcpu->arch.tbacct_lock);
stolen += vcpu->arch.busy_stolen;
vcpu->arch.busy_stolen = 0;
spin_unlock_irq(&vcpu->arch.tbacct_lock);
if (!dt || !vpa)
return;
memset(dt, 0, sizeof(struct dtl_entry));
dt->dispatch_reason = 7;
dt->processor_id = cpu_to_be16(vc->pcpu + vcpu->arch.ptid);
dt->timebase = cpu_to_be64(now + vc->tb_offset);
dt->enqueue_to_dispatch_time = cpu_to_be32(stolen);
dt->srr0 = cpu_to_be64(kvmppc_get_pc(vcpu));
dt->srr1 = cpu_to_be64(vcpu->arch.shregs.msr);
++dt;
if (dt == vcpu->arch.dtl.pinned_end)
dt = vcpu->arch.dtl.pinned_addr;
vcpu->arch.dtl_ptr = dt;
smp_wmb();
vpa->dtl_idx = cpu_to_be64(++vcpu->arch.dtl_index);
vcpu->arch.dtl.dirty = true;
}
static bool kvmppc_power8_compatible(struct kvm_vcpu *vcpu)
{
if (vcpu->arch.vcore->arch_compat >= PVR_ARCH_207)
return true;
if ((!vcpu->arch.vcore->arch_compat) &&
cpu_has_feature(CPU_FTR_ARCH_207S))
return true;
return false;
}
static int kvmppc_h_set_mode(struct kvm_vcpu *vcpu, unsigned long mflags,
unsigned long resource, unsigned long value1,
unsigned long value2)
{
switch (resource) {
case H_SET_MODE_RESOURCE_SET_CIABR:
if (!kvmppc_power8_compatible(vcpu))
return H_P2;
if (value2)
return H_P4;
if (mflags)
return H_UNSUPPORTED_FLAG_START;
if ((value1 & CIABR_PRIV) == CIABR_PRIV_HYPER)
return H_P3;
vcpu->arch.ciabr = value1;
return H_SUCCESS;
case H_SET_MODE_RESOURCE_SET_DAWR:
if (!kvmppc_power8_compatible(vcpu))
return H_P2;
if (mflags)
return H_UNSUPPORTED_FLAG_START;
if (value2 & DABRX_HYP)
return H_P4;
vcpu->arch.dawr = value1;
vcpu->arch.dawrx = value2;
return H_SUCCESS;
default:
return H_TOO_HARD;
}
}
static int kvm_arch_vcpu_yield_to(struct kvm_vcpu *target)
{
struct kvmppc_vcore *vcore = target->arch.vcore;
spin_lock(&vcore->lock);
if (target->arch.state == KVMPPC_VCPU_RUNNABLE &&
vcore->vcore_state != VCORE_INACTIVE)
target = vcore->runner;
spin_unlock(&vcore->lock);
return kvm_vcpu_yield_to(target);
}
static int kvmppc_get_yield_count(struct kvm_vcpu *vcpu)
{
int yield_count = 0;
struct lppaca *lppaca;
spin_lock(&vcpu->arch.vpa_update_lock);
lppaca = (struct lppaca *)vcpu->arch.vpa.pinned_addr;
if (lppaca)
yield_count = be32_to_cpu(lppaca->yield_count);
spin_unlock(&vcpu->arch.vpa_update_lock);
return yield_count;
}
int kvmppc_pseries_do_hcall(struct kvm_vcpu *vcpu)
{
unsigned long req = kvmppc_get_gpr(vcpu, 3);
unsigned long target, ret = H_SUCCESS;
int yield_count;
struct kvm_vcpu *tvcpu;
int idx, rc;
if (req <= MAX_HCALL_OPCODE &&
!test_bit(req/4, vcpu->kvm->arch.enabled_hcalls))
return RESUME_HOST;
switch (req) {
case H_CEDE:
break;
case H_PROD:
target = kvmppc_get_gpr(vcpu, 4);
tvcpu = kvmppc_find_vcpu(vcpu->kvm, target);
if (!tvcpu) {
ret = H_PARAMETER;
break;
}
tvcpu->arch.prodded = 1;
smp_mb();
if (vcpu->arch.ceded) {
if (waitqueue_active(&vcpu->wq)) {
wake_up_interruptible(&vcpu->wq);
vcpu->stat.halt_wakeup++;
}
}
break;
case H_CONFER:
target = kvmppc_get_gpr(vcpu, 4);
if (target == -1)
break;
tvcpu = kvmppc_find_vcpu(vcpu->kvm, target);
if (!tvcpu) {
ret = H_PARAMETER;
break;
}
yield_count = kvmppc_get_gpr(vcpu, 5);
if (kvmppc_get_yield_count(tvcpu) != yield_count)
break;
kvm_arch_vcpu_yield_to(tvcpu);
break;
case H_REGISTER_VPA:
ret = do_h_register_vpa(vcpu, kvmppc_get_gpr(vcpu, 4),
kvmppc_get_gpr(vcpu, 5),
kvmppc_get_gpr(vcpu, 6));
break;
case H_RTAS:
if (list_empty(&vcpu->kvm->arch.rtas_tokens))
return RESUME_HOST;
idx = srcu_read_lock(&vcpu->kvm->srcu);
rc = kvmppc_rtas_hcall(vcpu);
srcu_read_unlock(&vcpu->kvm->srcu, idx);
if (rc == -ENOENT)
return RESUME_HOST;
else if (rc == 0)
break;
return rc;
case H_SET_MODE:
ret = kvmppc_h_set_mode(vcpu, kvmppc_get_gpr(vcpu, 4),
kvmppc_get_gpr(vcpu, 5),
kvmppc_get_gpr(vcpu, 6),
kvmppc_get_gpr(vcpu, 7));
if (ret == H_TOO_HARD)
return RESUME_HOST;
break;
case H_XIRR:
case H_CPPR:
case H_EOI:
case H_IPI:
case H_IPOLL:
case H_XIRR_X:
if (kvmppc_xics_enabled(vcpu)) {
ret = kvmppc_xics_hcall(vcpu, req);
break;
}
default:
return RESUME_HOST;
}
kvmppc_set_gpr(vcpu, 3, ret);
vcpu->arch.hcall_needed = 0;
return RESUME_GUEST;
}
static int kvmppc_hcall_impl_hv(unsigned long cmd)
{
switch (cmd) {
case H_CEDE:
case H_PROD:
case H_CONFER:
case H_REGISTER_VPA:
case H_SET_MODE:
#ifdef CONFIG_KVM_XICS
case H_XIRR:
case H_CPPR:
case H_EOI:
case H_IPI:
case H_IPOLL:
case H_XIRR_X:
#endif
return 1;
}
return kvmppc_hcall_impl_hv_realmode(cmd);
}
static int kvmppc_emulate_debug_inst(struct kvm_run *run,
struct kvm_vcpu *vcpu)
{
u32 last_inst;
if (kvmppc_get_last_inst(vcpu, INST_GENERIC, &last_inst) !=
EMULATE_DONE) {
return RESUME_GUEST;
}
if (last_inst == KVMPPC_INST_SW_BREAKPOINT) {
run->exit_reason = KVM_EXIT_DEBUG;
run->debug.arch.address = kvmppc_get_pc(vcpu);
return RESUME_HOST;
} else {
kvmppc_core_queue_program(vcpu, SRR1_PROGILL);
return RESUME_GUEST;
}
}
static int kvmppc_handle_exit_hv(struct kvm_run *run, struct kvm_vcpu *vcpu,
struct task_struct *tsk)
{
int r = RESUME_HOST;
vcpu->stat.sum_exits++;
run->exit_reason = KVM_EXIT_UNKNOWN;
run->ready_for_interrupt_injection = 1;
switch (vcpu->arch.trap) {
case BOOK3S_INTERRUPT_HV_DECREMENTER:
vcpu->stat.dec_exits++;
r = RESUME_GUEST;
break;
case BOOK3S_INTERRUPT_EXTERNAL:
case BOOK3S_INTERRUPT_H_DOORBELL:
vcpu->stat.ext_intr_exits++;
r = RESUME_GUEST;
break;
case BOOK3S_INTERRUPT_HMI:
case BOOK3S_INTERRUPT_PERFMON:
r = RESUME_GUEST;
break;
case BOOK3S_INTERRUPT_MACHINE_CHECK:
kvmppc_book3s_queue_irqprio(vcpu,
BOOK3S_INTERRUPT_MACHINE_CHECK);
r = RESUME_GUEST;
break;
case BOOK3S_INTERRUPT_PROGRAM:
{
ulong flags;
flags = vcpu->arch.shregs.msr & 0x1f0000ull;
kvmppc_core_queue_program(vcpu, flags);
r = RESUME_GUEST;
break;
}
case BOOK3S_INTERRUPT_SYSCALL:
{
int i;
run->papr_hcall.nr = kvmppc_get_gpr(vcpu, 3);
for (i = 0; i < 9; ++i)
run->papr_hcall.args[i] = kvmppc_get_gpr(vcpu, 4 + i);
run->exit_reason = KVM_EXIT_PAPR_HCALL;
vcpu->arch.hcall_needed = 1;
r = RESUME_HOST;
break;
}
case BOOK3S_INTERRUPT_H_DATA_STORAGE:
r = RESUME_PAGE_FAULT;
break;
case BOOK3S_INTERRUPT_H_INST_STORAGE:
vcpu->arch.fault_dar = kvmppc_get_pc(vcpu);
vcpu->arch.fault_dsisr = 0;
r = RESUME_PAGE_FAULT;
break;
case BOOK3S_INTERRUPT_H_EMUL_ASSIST:
if (vcpu->arch.emul_inst != KVM_INST_FETCH_FAILED)
vcpu->arch.last_inst = kvmppc_need_byteswap(vcpu) ?
swab32(vcpu->arch.emul_inst) :
vcpu->arch.emul_inst;
if (vcpu->guest_debug & KVM_GUESTDBG_USE_SW_BP) {
r = kvmppc_emulate_debug_inst(run, vcpu);
} else {
kvmppc_core_queue_program(vcpu, SRR1_PROGILL);
r = RESUME_GUEST;
}
break;
case BOOK3S_INTERRUPT_H_FAC_UNAVAIL:
kvmppc_core_queue_program(vcpu, SRR1_PROGILL);
r = RESUME_GUEST;
break;
default:
kvmppc_dump_regs(vcpu);
printk(KERN_EMERG "trap=0x%x | pc=0x%lx | msr=0x%llx\n",
vcpu->arch.trap, kvmppc_get_pc(vcpu),
vcpu->arch.shregs.msr);
run->hw.hardware_exit_reason = vcpu->arch.trap;
r = RESUME_HOST;
break;
}
return r;
}
static int kvm_arch_vcpu_ioctl_get_sregs_hv(struct kvm_vcpu *vcpu,
struct kvm_sregs *sregs)
{
int i;
memset(sregs, 0, sizeof(struct kvm_sregs));
sregs->pvr = vcpu->arch.pvr;
for (i = 0; i < vcpu->arch.slb_max; i++) {
sregs->u.s.ppc64.slb[i].slbe = vcpu->arch.slb[i].orige;
sregs->u.s.ppc64.slb[i].slbv = vcpu->arch.slb[i].origv;
}
return 0;
}
static int kvm_arch_vcpu_ioctl_set_sregs_hv(struct kvm_vcpu *vcpu,
struct kvm_sregs *sregs)
{
int i, j;
if (sregs->pvr != vcpu->arch.pvr)
return -EINVAL;
j = 0;
for (i = 0; i < vcpu->arch.slb_nr; i++) {
if (sregs->u.s.ppc64.slb[i].slbe & SLB_ESID_V) {
vcpu->arch.slb[j].orige = sregs->u.s.ppc64.slb[i].slbe;
vcpu->arch.slb[j].origv = sregs->u.s.ppc64.slb[i].slbv;
++j;
}
}
vcpu->arch.slb_max = j;
return 0;
}
static void kvmppc_set_lpcr(struct kvm_vcpu *vcpu, u64 new_lpcr,
bool preserve_top32)
{
struct kvm *kvm = vcpu->kvm;
struct kvmppc_vcore *vc = vcpu->arch.vcore;
u64 mask;
mutex_lock(&kvm->lock);
spin_lock(&vc->lock);
if ((new_lpcr & LPCR_ILE) != (vc->lpcr & LPCR_ILE)) {
struct kvm_vcpu *vcpu;
int i;
kvm_for_each_vcpu(i, vcpu, kvm) {
if (vcpu->arch.vcore != vc)
continue;
if (new_lpcr & LPCR_ILE)
vcpu->arch.intr_msr |= MSR_LE;
else
vcpu->arch.intr_msr &= ~MSR_LE;
}
}
mask = LPCR_DPFD | LPCR_ILE | LPCR_TC;
if (cpu_has_feature(CPU_FTR_ARCH_207S))
mask |= LPCR_AIL;
if (preserve_top32)
mask &= 0xFFFFFFFF;
vc->lpcr = (vc->lpcr & ~mask) | (new_lpcr & mask);
spin_unlock(&vc->lock);
mutex_unlock(&kvm->lock);
}
static int kvmppc_get_one_reg_hv(struct kvm_vcpu *vcpu, u64 id,
union kvmppc_one_reg *val)
{
int r = 0;
long int i;
switch (id) {
case KVM_REG_PPC_DEBUG_INST:
*val = get_reg_val(id, KVMPPC_INST_SW_BREAKPOINT);
break;
case KVM_REG_PPC_HIOR:
*val = get_reg_val(id, 0);
break;
case KVM_REG_PPC_DABR:
*val = get_reg_val(id, vcpu->arch.dabr);
break;
case KVM_REG_PPC_DABRX:
*val = get_reg_val(id, vcpu->arch.dabrx);
break;
case KVM_REG_PPC_DSCR:
*val = get_reg_val(id, vcpu->arch.dscr);
break;
case KVM_REG_PPC_PURR:
*val = get_reg_val(id, vcpu->arch.purr);
break;
case KVM_REG_PPC_SPURR:
*val = get_reg_val(id, vcpu->arch.spurr);
break;
case KVM_REG_PPC_AMR:
*val = get_reg_val(id, vcpu->arch.amr);
break;
case KVM_REG_PPC_UAMOR:
*val = get_reg_val(id, vcpu->arch.uamor);
break;
case KVM_REG_PPC_MMCR0 ... KVM_REG_PPC_MMCRS:
i = id - KVM_REG_PPC_MMCR0;
*val = get_reg_val(id, vcpu->arch.mmcr[i]);
break;
case KVM_REG_PPC_PMC1 ... KVM_REG_PPC_PMC8:
i = id - KVM_REG_PPC_PMC1;
*val = get_reg_val(id, vcpu->arch.pmc[i]);
break;
case KVM_REG_PPC_SPMC1 ... KVM_REG_PPC_SPMC2:
i = id - KVM_REG_PPC_SPMC1;
*val = get_reg_val(id, vcpu->arch.spmc[i]);
break;
case KVM_REG_PPC_SIAR:
*val = get_reg_val(id, vcpu->arch.siar);
break;
case KVM_REG_PPC_SDAR:
*val = get_reg_val(id, vcpu->arch.sdar);
break;
case KVM_REG_PPC_SIER:
*val = get_reg_val(id, vcpu->arch.sier);
break;
case KVM_REG_PPC_IAMR:
*val = get_reg_val(id, vcpu->arch.iamr);
break;
case KVM_REG_PPC_PSPB:
*val = get_reg_val(id, vcpu->arch.pspb);
break;
case KVM_REG_PPC_DPDES:
*val = get_reg_val(id, vcpu->arch.vcore->dpdes);
break;
case KVM_REG_PPC_DAWR:
*val = get_reg_val(id, vcpu->arch.dawr);
break;
case KVM_REG_PPC_DAWRX:
*val = get_reg_val(id, vcpu->arch.dawrx);
break;
case KVM_REG_PPC_CIABR:
*val = get_reg_val(id, vcpu->arch.ciabr);
break;
case KVM_REG_PPC_CSIGR:
*val = get_reg_val(id, vcpu->arch.csigr);
break;
case KVM_REG_PPC_TACR:
*val = get_reg_val(id, vcpu->arch.tacr);
break;
case KVM_REG_PPC_TCSCR:
*val = get_reg_val(id, vcpu->arch.tcscr);
break;
case KVM_REG_PPC_PID:
*val = get_reg_val(id, vcpu->arch.pid);
break;
case KVM_REG_PPC_ACOP:
*val = get_reg_val(id, vcpu->arch.acop);
break;
case KVM_REG_PPC_WORT:
*val = get_reg_val(id, vcpu->arch.wort);
break;
case KVM_REG_PPC_VPA_ADDR:
spin_lock(&vcpu->arch.vpa_update_lock);
*val = get_reg_val(id, vcpu->arch.vpa.next_gpa);
spin_unlock(&vcpu->arch.vpa_update_lock);
break;
case KVM_REG_PPC_VPA_SLB:
spin_lock(&vcpu->arch.vpa_update_lock);
val->vpaval.addr = vcpu->arch.slb_shadow.next_gpa;
val->vpaval.length = vcpu->arch.slb_shadow.len;
spin_unlock(&vcpu->arch.vpa_update_lock);
break;
case KVM_REG_PPC_VPA_DTL:
spin_lock(&vcpu->arch.vpa_update_lock);
val->vpaval.addr = vcpu->arch.dtl.next_gpa;
val->vpaval.length = vcpu->arch.dtl.len;
spin_unlock(&vcpu->arch.vpa_update_lock);
break;
case KVM_REG_PPC_TB_OFFSET:
*val = get_reg_val(id, vcpu->arch.vcore->tb_offset);
break;
case KVM_REG_PPC_LPCR:
case KVM_REG_PPC_LPCR_64:
*val = get_reg_val(id, vcpu->arch.vcore->lpcr);
break;
case KVM_REG_PPC_PPR:
*val = get_reg_val(id, vcpu->arch.ppr);
break;
#ifdef CONFIG_PPC_TRANSACTIONAL_MEM
case KVM_REG_PPC_TFHAR:
*val = get_reg_val(id, vcpu->arch.tfhar);
break;
case KVM_REG_PPC_TFIAR:
*val = get_reg_val(id, vcpu->arch.tfiar);
break;
case KVM_REG_PPC_TEXASR:
*val = get_reg_val(id, vcpu->arch.texasr);
break;
case KVM_REG_PPC_TM_GPR0 ... KVM_REG_PPC_TM_GPR31:
i = id - KVM_REG_PPC_TM_GPR0;
*val = get_reg_val(id, vcpu->arch.gpr_tm[i]);
break;
case KVM_REG_PPC_TM_VSR0 ... KVM_REG_PPC_TM_VSR63:
{
int j;
i = id - KVM_REG_PPC_TM_VSR0;
if (i < 32)
for (j = 0; j < TS_FPRWIDTH; j++)
val->vsxval[j] = vcpu->arch.fp_tm.fpr[i][j];
else {
if (cpu_has_feature(CPU_FTR_ALTIVEC))
val->vval = vcpu->arch.vr_tm.vr[i-32];
else
r = -ENXIO;
}
break;
}
case KVM_REG_PPC_TM_CR:
*val = get_reg_val(id, vcpu->arch.cr_tm);
break;
case KVM_REG_PPC_TM_LR:
*val = get_reg_val(id, vcpu->arch.lr_tm);
break;
case KVM_REG_PPC_TM_CTR:
*val = get_reg_val(id, vcpu->arch.ctr_tm);
break;
case KVM_REG_PPC_TM_FPSCR:
*val = get_reg_val(id, vcpu->arch.fp_tm.fpscr);
break;
case KVM_REG_PPC_TM_AMR:
*val = get_reg_val(id, vcpu->arch.amr_tm);
break;
case KVM_REG_PPC_TM_PPR:
*val = get_reg_val(id, vcpu->arch.ppr_tm);
break;
case KVM_REG_PPC_TM_VRSAVE:
*val = get_reg_val(id, vcpu->arch.vrsave_tm);
break;
case KVM_REG_PPC_TM_VSCR:
if (cpu_has_feature(CPU_FTR_ALTIVEC))
*val = get_reg_val(id, vcpu->arch.vr_tm.vscr.u[3]);
else
r = -ENXIO;
break;
case KVM_REG_PPC_TM_DSCR:
*val = get_reg_val(id, vcpu->arch.dscr_tm);
break;
case KVM_REG_PPC_TM_TAR:
*val = get_reg_val(id, vcpu->arch.tar_tm);
break;
#endif
case KVM_REG_PPC_ARCH_COMPAT:
*val = get_reg_val(id, vcpu->arch.vcore->arch_compat);
break;
default:
r = -EINVAL;
break;
}
return r;
}
static int kvmppc_set_one_reg_hv(struct kvm_vcpu *vcpu, u64 id,
union kvmppc_one_reg *val)
{
int r = 0;
long int i;
unsigned long addr, len;
switch (id) {
case KVM_REG_PPC_HIOR:
if (set_reg_val(id, *val))
r = -EINVAL;
break;
case KVM_REG_PPC_DABR:
vcpu->arch.dabr = set_reg_val(id, *val);
break;
case KVM_REG_PPC_DABRX:
vcpu->arch.dabrx = set_reg_val(id, *val) & ~DABRX_HYP;
break;
case KVM_REG_PPC_DSCR:
vcpu->arch.dscr = set_reg_val(id, *val);
break;
case KVM_REG_PPC_PURR:
vcpu->arch.purr = set_reg_val(id, *val);
break;
case KVM_REG_PPC_SPURR:
vcpu->arch.spurr = set_reg_val(id, *val);
break;
case KVM_REG_PPC_AMR:
vcpu->arch.amr = set_reg_val(id, *val);
break;
case KVM_REG_PPC_UAMOR:
vcpu->arch.uamor = set_reg_val(id, *val);
break;
case KVM_REG_PPC_MMCR0 ... KVM_REG_PPC_MMCRS:
i = id - KVM_REG_PPC_MMCR0;
vcpu->arch.mmcr[i] = set_reg_val(id, *val);
break;
case KVM_REG_PPC_PMC1 ... KVM_REG_PPC_PMC8:
i = id - KVM_REG_PPC_PMC1;
vcpu->arch.pmc[i] = set_reg_val(id, *val);
break;
case KVM_REG_PPC_SPMC1 ... KVM_REG_PPC_SPMC2:
i = id - KVM_REG_PPC_SPMC1;
vcpu->arch.spmc[i] = set_reg_val(id, *val);
break;
case KVM_REG_PPC_SIAR:
vcpu->arch.siar = set_reg_val(id, *val);
break;
case KVM_REG_PPC_SDAR:
vcpu->arch.sdar = set_reg_val(id, *val);
break;
case KVM_REG_PPC_SIER:
vcpu->arch.sier = set_reg_val(id, *val);
break;
case KVM_REG_PPC_IAMR:
vcpu->arch.iamr = set_reg_val(id, *val);
break;
case KVM_REG_PPC_PSPB:
vcpu->arch.pspb = set_reg_val(id, *val);
break;
case KVM_REG_PPC_DPDES:
vcpu->arch.vcore->dpdes = set_reg_val(id, *val);
break;
case KVM_REG_PPC_DAWR:
vcpu->arch.dawr = set_reg_val(id, *val);
break;
case KVM_REG_PPC_DAWRX:
vcpu->arch.dawrx = set_reg_val(id, *val) & ~DAWRX_HYP;
break;
case KVM_REG_PPC_CIABR:
vcpu->arch.ciabr = set_reg_val(id, *val);
if ((vcpu->arch.ciabr & CIABR_PRIV) == CIABR_PRIV_HYPER)
vcpu->arch.ciabr &= ~CIABR_PRIV;
break;
case KVM_REG_PPC_CSIGR:
vcpu->arch.csigr = set_reg_val(id, *val);
break;
case KVM_REG_PPC_TACR:
vcpu->arch.tacr = set_reg_val(id, *val);
break;
case KVM_REG_PPC_TCSCR:
vcpu->arch.tcscr = set_reg_val(id, *val);
break;
case KVM_REG_PPC_PID:
vcpu->arch.pid = set_reg_val(id, *val);
break;
case KVM_REG_PPC_ACOP:
vcpu->arch.acop = set_reg_val(id, *val);
break;
case KVM_REG_PPC_WORT:
vcpu->arch.wort = set_reg_val(id, *val);
break;
case KVM_REG_PPC_VPA_ADDR:
addr = set_reg_val(id, *val);
r = -EINVAL;
if (!addr && (vcpu->arch.slb_shadow.next_gpa ||
vcpu->arch.dtl.next_gpa))
break;
r = set_vpa(vcpu, &vcpu->arch.vpa, addr, sizeof(struct lppaca));
break;
case KVM_REG_PPC_VPA_SLB:
addr = val->vpaval.addr;
len = val->vpaval.length;
r = -EINVAL;
if (addr && !vcpu->arch.vpa.next_gpa)
break;
r = set_vpa(vcpu, &vcpu->arch.slb_shadow, addr, len);
break;
case KVM_REG_PPC_VPA_DTL:
addr = val->vpaval.addr;
len = val->vpaval.length;
r = -EINVAL;
if (addr && (len < sizeof(struct dtl_entry) ||
!vcpu->arch.vpa.next_gpa))
break;
len -= len % sizeof(struct dtl_entry);
r = set_vpa(vcpu, &vcpu->arch.dtl, addr, len);
break;
case KVM_REG_PPC_TB_OFFSET:
vcpu->arch.vcore->tb_offset =
ALIGN(set_reg_val(id, *val), 1UL << 24);
break;
case KVM_REG_PPC_LPCR:
kvmppc_set_lpcr(vcpu, set_reg_val(id, *val), true);
break;
case KVM_REG_PPC_LPCR_64:
kvmppc_set_lpcr(vcpu, set_reg_val(id, *val), false);
break;
case KVM_REG_PPC_PPR:
vcpu->arch.ppr = set_reg_val(id, *val);
break;
#ifdef CONFIG_PPC_TRANSACTIONAL_MEM
case KVM_REG_PPC_TFHAR:
vcpu->arch.tfhar = set_reg_val(id, *val);
break;
case KVM_REG_PPC_TFIAR:
vcpu->arch.tfiar = set_reg_val(id, *val);
break;
case KVM_REG_PPC_TEXASR:
vcpu->arch.texasr = set_reg_val(id, *val);
break;
case KVM_REG_PPC_TM_GPR0 ... KVM_REG_PPC_TM_GPR31:
i = id - KVM_REG_PPC_TM_GPR0;
vcpu->arch.gpr_tm[i] = set_reg_val(id, *val);
break;
case KVM_REG_PPC_TM_VSR0 ... KVM_REG_PPC_TM_VSR63:
{
int j;
i = id - KVM_REG_PPC_TM_VSR0;
if (i < 32)
for (j = 0; j < TS_FPRWIDTH; j++)
vcpu->arch.fp_tm.fpr[i][j] = val->vsxval[j];
else
if (cpu_has_feature(CPU_FTR_ALTIVEC))
vcpu->arch.vr_tm.vr[i-32] = val->vval;
else
r = -ENXIO;
break;
}
case KVM_REG_PPC_TM_CR:
vcpu->arch.cr_tm = set_reg_val(id, *val);
break;
case KVM_REG_PPC_TM_LR:
vcpu->arch.lr_tm = set_reg_val(id, *val);
break;
case KVM_REG_PPC_TM_CTR:
vcpu->arch.ctr_tm = set_reg_val(id, *val);
break;
case KVM_REG_PPC_TM_FPSCR:
vcpu->arch.fp_tm.fpscr = set_reg_val(id, *val);
break;
case KVM_REG_PPC_TM_AMR:
vcpu->arch.amr_tm = set_reg_val(id, *val);
break;
case KVM_REG_PPC_TM_PPR:
vcpu->arch.ppr_tm = set_reg_val(id, *val);
break;
case KVM_REG_PPC_TM_VRSAVE:
vcpu->arch.vrsave_tm = set_reg_val(id, *val);
break;
case KVM_REG_PPC_TM_VSCR:
if (cpu_has_feature(CPU_FTR_ALTIVEC))
vcpu->arch.vr.vscr.u[3] = set_reg_val(id, *val);
else
r = - ENXIO;
break;
case KVM_REG_PPC_TM_DSCR:
vcpu->arch.dscr_tm = set_reg_val(id, *val);
break;
case KVM_REG_PPC_TM_TAR:
vcpu->arch.tar_tm = set_reg_val(id, *val);
break;
#endif
case KVM_REG_PPC_ARCH_COMPAT:
r = kvmppc_set_arch_compat(vcpu, set_reg_val(id, *val));
break;
default:
r = -EINVAL;
break;
}
return r;
}
static struct kvmppc_vcore *kvmppc_vcore_create(struct kvm *kvm, int core)
{
struct kvmppc_vcore *vcore;
vcore = kzalloc(sizeof(struct kvmppc_vcore), GFP_KERNEL);
if (vcore == NULL)
return NULL;
INIT_LIST_HEAD(&vcore->runnable_threads);
spin_lock_init(&vcore->lock);
spin_lock_init(&vcore->stoltb_lock);
init_waitqueue_head(&vcore->wq);
vcore->preempt_tb = TB_NIL;
vcore->lpcr = kvm->arch.lpcr;
vcore->first_vcpuid = core * threads_per_subcore;
vcore->kvm = kvm;
vcore->mpp_buffer_is_valid = false;
if (cpu_has_feature(CPU_FTR_ARCH_207S))
vcore->mpp_buffer = (void *)__get_free_pages(
GFP_KERNEL|__GFP_ZERO,
MPP_BUFFER_ORDER);
return vcore;
}
static struct kvm_vcpu *kvmppc_core_vcpu_create_hv(struct kvm *kvm,
unsigned int id)
{
struct kvm_vcpu *vcpu;
int err = -EINVAL;
int core;
struct kvmppc_vcore *vcore;
core = id / threads_per_subcore;
if (core >= KVM_MAX_VCORES)
goto out;
err = -ENOMEM;
vcpu = kmem_cache_zalloc(kvm_vcpu_cache, GFP_KERNEL);
if (!vcpu)
goto out;
err = kvm_vcpu_init(vcpu, kvm, id);
if (err)
goto free_vcpu;
vcpu->arch.shared = &vcpu->arch.shregs;
#ifdef CONFIG_KVM_BOOK3S_PR_POSSIBLE
#ifdef __BIG_ENDIAN__
vcpu->arch.shared_big_endian = true;
#else
vcpu->arch.shared_big_endian = false;
#endif
#endif
vcpu->arch.mmcr[0] = MMCR0_FC;
vcpu->arch.ctrl = CTRL_RUNLATCH;
kvmppc_set_pvr_hv(vcpu, mfspr(SPRN_PVR));
spin_lock_init(&vcpu->arch.vpa_update_lock);
spin_lock_init(&vcpu->arch.tbacct_lock);
vcpu->arch.busy_preempt = TB_NIL;
vcpu->arch.intr_msr = MSR_SF | MSR_ME;
kvmppc_mmu_book3s_hv_init(vcpu);
vcpu->arch.state = KVMPPC_VCPU_NOTREADY;
init_waitqueue_head(&vcpu->arch.cpu_run);
mutex_lock(&kvm->lock);
vcore = kvm->arch.vcores[core];
if (!vcore) {
vcore = kvmppc_vcore_create(kvm, core);
kvm->arch.vcores[core] = vcore;
kvm->arch.online_vcores++;
}
mutex_unlock(&kvm->lock);
if (!vcore)
goto free_vcpu;
spin_lock(&vcore->lock);
++vcore->num_threads;
spin_unlock(&vcore->lock);
vcpu->arch.vcore = vcore;
vcpu->arch.ptid = vcpu->vcpu_id - vcore->first_vcpuid;
vcpu->arch.cpu_type = KVM_CPU_3S_64;
kvmppc_sanity_check(vcpu);
return vcpu;
free_vcpu:
kmem_cache_free(kvm_vcpu_cache, vcpu);
out:
return ERR_PTR(err);
}
static void unpin_vpa(struct kvm *kvm, struct kvmppc_vpa *vpa)
{
if (vpa->pinned_addr)
kvmppc_unpin_guest_page(kvm, vpa->pinned_addr, vpa->gpa,
vpa->dirty);
}
static void kvmppc_core_vcpu_free_hv(struct kvm_vcpu *vcpu)
{
spin_lock(&vcpu->arch.vpa_update_lock);
unpin_vpa(vcpu->kvm, &vcpu->arch.dtl);
unpin_vpa(vcpu->kvm, &vcpu->arch.slb_shadow);
unpin_vpa(vcpu->kvm, &vcpu->arch.vpa);
spin_unlock(&vcpu->arch.vpa_update_lock);
kvm_vcpu_uninit(vcpu);
kmem_cache_free(kvm_vcpu_cache, vcpu);
}
static int kvmppc_core_check_requests_hv(struct kvm_vcpu *vcpu)
{
return 1;
}
static void kvmppc_set_timer(struct kvm_vcpu *vcpu)
{
unsigned long dec_nsec, now;
now = get_tb();
if (now > vcpu->arch.dec_expires) {
kvmppc_core_queue_dec(vcpu);
kvmppc_core_prepare_to_enter(vcpu);
return;
}
dec_nsec = (vcpu->arch.dec_expires - now) * NSEC_PER_SEC
/ tb_ticks_per_sec;
hrtimer_start(&vcpu->arch.dec_timer, ktime_set(0, dec_nsec),
HRTIMER_MODE_REL);
vcpu->arch.timer_running = 1;
}
static void kvmppc_end_cede(struct kvm_vcpu *vcpu)
{
vcpu->arch.ceded = 0;
if (vcpu->arch.timer_running) {
hrtimer_try_to_cancel(&vcpu->arch.dec_timer);
vcpu->arch.timer_running = 0;
}
}
static void kvmppc_remove_runnable(struct kvmppc_vcore *vc,
struct kvm_vcpu *vcpu)
{
u64 now;
if (vcpu->arch.state != KVMPPC_VCPU_RUNNABLE)
return;
spin_lock_irq(&vcpu->arch.tbacct_lock);
now = mftb();
vcpu->arch.busy_stolen += vcore_stolen_time(vc, now) -
vcpu->arch.stolen_logged;
vcpu->arch.busy_preempt = now;
vcpu->arch.state = KVMPPC_VCPU_BUSY_IN_HOST;
spin_unlock_irq(&vcpu->arch.tbacct_lock);
--vc->n_runnable;
list_del(&vcpu->arch.run_list);
}
static int kvmppc_grab_hwthread(int cpu)
{
struct paca_struct *tpaca;
long timeout = 10000;
tpaca = &paca[cpu];
tpaca->kvm_hstate.hwthread_req = 1;
tpaca->kvm_hstate.kvm_vcpu = NULL;
smp_mb();
while (tpaca->kvm_hstate.hwthread_state == KVM_HWTHREAD_IN_KERNEL) {
if (--timeout <= 0) {
pr_err("KVM: couldn't grab cpu %d\n", cpu);
return -EBUSY;
}
udelay(1);
}
return 0;
}
static void kvmppc_release_hwthread(int cpu)
{
struct paca_struct *tpaca;
tpaca = &paca[cpu];
tpaca->kvm_hstate.hwthread_req = 0;
tpaca->kvm_hstate.kvm_vcpu = NULL;
}
static void kvmppc_start_thread(struct kvm_vcpu *vcpu)
{
int cpu;
struct paca_struct *tpaca;
struct kvmppc_vcore *vc = vcpu->arch.vcore;
if (vcpu->arch.timer_running) {
hrtimer_try_to_cancel(&vcpu->arch.dec_timer);
vcpu->arch.timer_running = 0;
}
cpu = vc->pcpu + vcpu->arch.ptid;
tpaca = &paca[cpu];
tpaca->kvm_hstate.kvm_vcpu = vcpu;
tpaca->kvm_hstate.kvm_vcore = vc;
tpaca->kvm_hstate.ptid = vcpu->arch.ptid;
vcpu->cpu = vc->pcpu;
smp_wmb();
#if defined(CONFIG_PPC_ICP_NATIVE) && defined(CONFIG_SMP)
if (cpu != smp_processor_id()) {
xics_wake_cpu(cpu);
if (vcpu->arch.ptid)
++vc->n_woken;
}
#endif
}
static void kvmppc_wait_for_nap(struct kvmppc_vcore *vc)
{
int i;
HMT_low();
i = 0;
while (vc->nap_count < vc->n_woken) {
if (++i >= 1000000) {
pr_err("kvmppc_wait_for_nap timeout %d %d\n",
vc->nap_count, vc->n_woken);
break;
}
cpu_relax();
}
HMT_medium();
}
static int on_primary_thread(void)
{
int cpu = smp_processor_id();
int thr;
if (cpu_thread_in_subcore(cpu))
return 0;
thr = 0;
while (++thr < threads_per_subcore)
if (cpu_online(cpu + thr))
return 0;
for (thr = 1; thr < threads_per_subcore; ++thr) {
if (kvmppc_grab_hwthread(cpu + thr)) {
do {
kvmppc_release_hwthread(cpu + thr);
} while (--thr > 0);
return 0;
}
}
return 1;
}
static void kvmppc_start_saving_l2_cache(struct kvmppc_vcore *vc)
{
phys_addr_t phy_addr, mpp_addr;
phy_addr = (phys_addr_t)virt_to_phys(vc->mpp_buffer);
mpp_addr = phy_addr & PPC_MPPE_ADDRESS_MASK;
mtspr(SPRN_MPPR, mpp_addr | PPC_MPPR_FETCH_ABORT);
logmpp(mpp_addr | PPC_LOGMPP_LOG_L2);
vc->mpp_buffer_is_valid = true;
}
static void kvmppc_start_restoring_l2_cache(const struct kvmppc_vcore *vc)
{
phys_addr_t phy_addr, mpp_addr;
phy_addr = virt_to_phys(vc->mpp_buffer);
mpp_addr = phy_addr & PPC_MPPE_ADDRESS_MASK;
logmpp(mpp_addr | PPC_LOGMPP_LOG_ABORT);
mtspr(SPRN_MPPR, mpp_addr | PPC_MPPR_FETCH_WHOLE_TABLE);
}
static void kvmppc_run_core(struct kvmppc_vcore *vc)
{
struct kvm_vcpu *vcpu, *vnext;
long ret;
u64 now;
int i, need_vpa_update;
int srcu_idx;
struct kvm_vcpu *vcpus_to_update[threads_per_core];
need_vpa_update = 0;
list_for_each_entry(vcpu, &vc->runnable_threads, arch.run_list) {
if (signal_pending(vcpu->arch.run_task))
return;
if (vcpu->arch.vpa.update_pending ||
vcpu->arch.slb_shadow.update_pending ||
vcpu->arch.dtl.update_pending)
vcpus_to_update[need_vpa_update++] = vcpu;
}
vc->n_woken = 0;
vc->nap_count = 0;
vc->entry_exit_count = 0;
vc->preempt_tb = TB_NIL;
vc->vcore_state = VCORE_STARTING;
vc->in_guest = 0;
vc->napping_threads = 0;
vc->conferring_threads = 0;
if (need_vpa_update) {
spin_unlock(&vc->lock);
for (i = 0; i < need_vpa_update; ++i)
kvmppc_update_vpas(vcpus_to_update[i]);
spin_lock(&vc->lock);
}
if ((threads_per_core > 1) &&
((vc->num_threads > threads_per_subcore) || !on_primary_thread())) {
list_for_each_entry(vcpu, &vc->runnable_threads, arch.run_list)
vcpu->arch.ret = -EBUSY;
goto out;
}
vc->pcpu = smp_processor_id();
list_for_each_entry(vcpu, &vc->runnable_threads, arch.run_list) {
kvmppc_start_thread(vcpu);
kvmppc_create_dtl_entry(vcpu, vc);
trace_kvm_guest_enter(vcpu);
}
get_paca()->kvm_hstate.kvm_vcore = vc;
get_paca()->kvm_hstate.ptid = 0;
vc->vcore_state = VCORE_RUNNING;
preempt_disable();
trace_kvmppc_run_core(vc, 0);
spin_unlock(&vc->lock);
kvm_guest_enter();
srcu_idx = srcu_read_lock(&vc->kvm->srcu);
if (vc->mpp_buffer_is_valid)
kvmppc_start_restoring_l2_cache(vc);
__kvmppc_vcore_entry();
spin_lock(&vc->lock);
if (vc->mpp_buffer)
kvmppc_start_saving_l2_cache(vc);
list_for_each_entry(vcpu, &vc->runnable_threads, arch.run_list)
vcpu->cpu = -1;
if (vc->nap_count < vc->n_woken)
kvmppc_wait_for_nap(vc);
for (i = 0; i < threads_per_subcore; ++i)
kvmppc_release_hwthread(vc->pcpu + i);
vc->vcore_state = VCORE_EXITING;
spin_unlock(&vc->lock);
srcu_read_unlock(&vc->kvm->srcu, srcu_idx);
smp_mb();
kvm_guest_exit();
preempt_enable();
cond_resched();
spin_lock(&vc->lock);
now = get_tb();
list_for_each_entry(vcpu, &vc->runnable_threads, arch.run_list) {
if (now < vcpu->arch.dec_expires &&
kvmppc_core_pending_dec(vcpu))
kvmppc_core_dequeue_dec(vcpu);
trace_kvm_guest_exit(vcpu);
ret = RESUME_GUEST;
if (vcpu->arch.trap)
ret = kvmppc_handle_exit_hv(vcpu->arch.kvm_run, vcpu,
vcpu->arch.run_task);
vcpu->arch.ret = ret;
vcpu->arch.trap = 0;
if (vcpu->arch.ceded) {
if (!is_kvmppc_resume_guest(ret))
kvmppc_end_cede(vcpu);
else
kvmppc_set_timer(vcpu);
}
}
out:
vc->vcore_state = VCORE_INACTIVE;
list_for_each_entry_safe(vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if (!is_kvmppc_resume_guest(vcpu->arch.ret)) {
kvmppc_remove_runnable(vc, vcpu);
wake_up(&vcpu->arch.cpu_run);
}
}
trace_kvmppc_run_core(vc, 1);
}
static void kvmppc_wait_for_exec(struct kvm_vcpu *vcpu, int wait_state)
{
DEFINE_WAIT(wait);
prepare_to_wait(&vcpu->arch.cpu_run, &wait, wait_state);
if (vcpu->arch.state == KVMPPC_VCPU_RUNNABLE)
schedule();
finish_wait(&vcpu->arch.cpu_run, &wait);
}
static void kvmppc_vcore_blocked(struct kvmppc_vcore *vc)
{
struct kvm_vcpu *vcpu;
int do_sleep = 1;
DEFINE_WAIT(wait);
prepare_to_wait(&vc->wq, &wait, TASK_INTERRUPTIBLE);
list_for_each_entry(vcpu, &vc->runnable_threads, arch.run_list) {
if (vcpu->arch.pending_exceptions || !vcpu->arch.ceded) {
do_sleep = 0;
break;
}
}
if (!do_sleep) {
finish_wait(&vc->wq, &wait);
return;
}
vc->vcore_state = VCORE_SLEEPING;
trace_kvmppc_vcore_blocked(vc, 0);
spin_unlock(&vc->lock);
schedule();
finish_wait(&vc->wq, &wait);
spin_lock(&vc->lock);
vc->vcore_state = VCORE_INACTIVE;
trace_kvmppc_vcore_blocked(vc, 1);
}
static int kvmppc_run_vcpu(struct kvm_run *kvm_run, struct kvm_vcpu *vcpu)
{
int n_ceded;
struct kvmppc_vcore *vc;
struct kvm_vcpu *v, *vn;
trace_kvmppc_run_vcpu_enter(vcpu);
kvm_run->exit_reason = 0;
vcpu->arch.ret = RESUME_GUEST;
vcpu->arch.trap = 0;
kvmppc_update_vpas(vcpu);
vc = vcpu->arch.vcore;
spin_lock(&vc->lock);
vcpu->arch.ceded = 0;
vcpu->arch.run_task = current;
vcpu->arch.kvm_run = kvm_run;
vcpu->arch.stolen_logged = vcore_stolen_time(vc, mftb());
vcpu->arch.state = KVMPPC_VCPU_RUNNABLE;
vcpu->arch.busy_preempt = TB_NIL;
list_add_tail(&vcpu->arch.run_list, &vc->runnable_threads);
++vc->n_runnable;
if (!signal_pending(current)) {
if (vc->vcore_state == VCORE_RUNNING &&
VCORE_EXIT_COUNT(vc) == 0) {
kvmppc_create_dtl_entry(vcpu, vc);
kvmppc_start_thread(vcpu);
trace_kvm_guest_enter(vcpu);
} else if (vc->vcore_state == VCORE_SLEEPING) {
wake_up(&vc->wq);
}
}
while (vcpu->arch.state == KVMPPC_VCPU_RUNNABLE &&
!signal_pending(current)) {
if (vc->vcore_state != VCORE_INACTIVE) {
spin_unlock(&vc->lock);
kvmppc_wait_for_exec(vcpu, TASK_INTERRUPTIBLE);
spin_lock(&vc->lock);
continue;
}
list_for_each_entry_safe(v, vn, &vc->runnable_threads,
arch.run_list) {
kvmppc_core_prepare_to_enter(v);
if (signal_pending(v->arch.run_task)) {
kvmppc_remove_runnable(vc, v);
v->stat.signal_exits++;
v->arch.kvm_run->exit_reason = KVM_EXIT_INTR;
v->arch.ret = -EINTR;
wake_up(&v->arch.cpu_run);
}
}
if (!vc->n_runnable || vcpu->arch.state != KVMPPC_VCPU_RUNNABLE)
break;
vc->runner = vcpu;
n_ceded = 0;
list_for_each_entry(v, &vc->runnable_threads, arch.run_list) {
if (!v->arch.pending_exceptions)
n_ceded += v->arch.ceded;
else
v->arch.ceded = 0;
}
if (n_ceded == vc->n_runnable)
kvmppc_vcore_blocked(vc);
else
kvmppc_run_core(vc);
vc->runner = NULL;
}
while (vcpu->arch.state == KVMPPC_VCPU_RUNNABLE &&
(vc->vcore_state == VCORE_RUNNING ||
vc->vcore_state == VCORE_EXITING)) {
spin_unlock(&vc->lock);
kvmppc_wait_for_exec(vcpu, TASK_UNINTERRUPTIBLE);
spin_lock(&vc->lock);
}
if (vcpu->arch.state == KVMPPC_VCPU_RUNNABLE) {
kvmppc_remove_runnable(vc, vcpu);
vcpu->stat.signal_exits++;
kvm_run->exit_reason = KVM_EXIT_INTR;
vcpu->arch.ret = -EINTR;
}
if (vc->n_runnable && vc->vcore_state == VCORE_INACTIVE) {
v = list_first_entry(&vc->runnable_threads,
struct kvm_vcpu, arch.run_list);
wake_up(&v->arch.cpu_run);
}
trace_kvmppc_run_vcpu_exit(vcpu, kvm_run);
spin_unlock(&vc->lock);
return vcpu->arch.ret;
}
static int kvmppc_vcpu_run_hv(struct kvm_run *run, struct kvm_vcpu *vcpu)
{
int r;
int srcu_idx;
if (!vcpu->arch.sane) {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
return -EINVAL;
}
kvmppc_core_prepare_to_enter(vcpu);
if (signal_pending(current)) {
run->exit_reason = KVM_EXIT_INTR;
return -EINTR;
}
atomic_inc(&vcpu->kvm->arch.vcpus_running);
smp_mb();
if (!vcpu->kvm->arch.rma_setup_done) {
r = kvmppc_hv_setup_htab_rma(vcpu);
if (r)
goto out;
}
flush_fp_to_thread(current);
flush_altivec_to_thread(current);
flush_vsx_to_thread(current);
vcpu->arch.wqp = &vcpu->arch.vcore->wq;
vcpu->arch.pgdir = current->mm->pgd;
vcpu->arch.state = KVMPPC_VCPU_BUSY_IN_HOST;
do {
r = kvmppc_run_vcpu(run, vcpu);
if (run->exit_reason == KVM_EXIT_PAPR_HCALL &&
!(vcpu->arch.shregs.msr & MSR_PR)) {
trace_kvm_hcall_enter(vcpu);
r = kvmppc_pseries_do_hcall(vcpu);
trace_kvm_hcall_exit(vcpu, r);
kvmppc_core_prepare_to_enter(vcpu);
} else if (r == RESUME_PAGE_FAULT) {
srcu_idx = srcu_read_lock(&vcpu->kvm->srcu);
r = kvmppc_book3s_hv_page_fault(run, vcpu,
vcpu->arch.fault_dar, vcpu->arch.fault_dsisr);
srcu_read_unlock(&vcpu->kvm->srcu, srcu_idx);
}
} while (is_kvmppc_resume_guest(r));
out:
vcpu->arch.state = KVMPPC_VCPU_NOTREADY;
atomic_dec(&vcpu->kvm->arch.vcpus_running);
return r;
}
static void kvmppc_add_seg_page_size(struct kvm_ppc_one_seg_page_size **sps,
int linux_psize)
{
struct mmu_psize_def *def = &mmu_psize_defs[linux_psize];
if (!def->shift)
return;
(*sps)->page_shift = def->shift;
(*sps)->slb_enc = def->sllp;
(*sps)->enc[0].page_shift = def->shift;
(*sps)->enc[0].pte_enc = def->penc[linux_psize];
if (linux_psize != MMU_PAGE_16M && def->penc[MMU_PAGE_16M] != -1) {
(*sps)->enc[1].page_shift = 24;
(*sps)->enc[1].pte_enc = def->penc[MMU_PAGE_16M];
}
(*sps)++;
}
static int kvm_vm_ioctl_get_smmu_info_hv(struct kvm *kvm,
struct kvm_ppc_smmu_info *info)
{
struct kvm_ppc_one_seg_page_size *sps;
info->flags = KVM_PPC_PAGE_SIZES_REAL;
if (mmu_has_feature(MMU_FTR_1T_SEGMENT))
info->flags |= KVM_PPC_1T_SEGMENTS;
info->slb_size = mmu_slb_size;
sps = &info->sps[0];
kvmppc_add_seg_page_size(&sps, MMU_PAGE_4K);
kvmppc_add_seg_page_size(&sps, MMU_PAGE_64K);
kvmppc_add_seg_page_size(&sps, MMU_PAGE_16M);
return 0;
}
static int kvm_vm_ioctl_get_dirty_log_hv(struct kvm *kvm,
struct kvm_dirty_log *log)
{
struct kvm_memory_slot *memslot;
int r;
unsigned long n;
mutex_lock(&kvm->slots_lock);
r = -EINVAL;
if (log->slot >= KVM_USER_MEM_SLOTS)
goto out;
memslot = id_to_memslot(kvm->memslots, log->slot);
r = -ENOENT;
if (!memslot->dirty_bitmap)
goto out;
n = kvm_dirty_bitmap_bytes(memslot);
memset(memslot->dirty_bitmap, 0, n);
r = kvmppc_hv_get_dirty_log(kvm, memslot, memslot->dirty_bitmap);
if (r)
goto out;
r = -EFAULT;
if (copy_to_user(log->dirty_bitmap, memslot->dirty_bitmap, n))
goto out;
r = 0;
out:
mutex_unlock(&kvm->slots_lock);
return r;
}
static void kvmppc_core_free_memslot_hv(struct kvm_memory_slot *free,
struct kvm_memory_slot *dont)
{
if (!dont || free->arch.rmap != dont->arch.rmap) {
vfree(free->arch.rmap);
free->arch.rmap = NULL;
}
}
static int kvmppc_core_create_memslot_hv(struct kvm_memory_slot *slot,
unsigned long npages)
{
slot->arch.rmap = vzalloc(npages * sizeof(*slot->arch.rmap));
if (!slot->arch.rmap)
return -ENOMEM;
return 0;
}
static int kvmppc_core_prepare_memory_region_hv(struct kvm *kvm,
struct kvm_memory_slot *memslot,
struct kvm_userspace_memory_region *mem)
{
return 0;
}
static void kvmppc_core_commit_memory_region_hv(struct kvm *kvm,
struct kvm_userspace_memory_region *mem,
const struct kvm_memory_slot *old)
{
unsigned long npages = mem->memory_size >> PAGE_SHIFT;
struct kvm_memory_slot *memslot;
if (npages && old->npages) {
memslot = id_to_memslot(kvm->memslots, mem->slot);
kvmppc_hv_get_dirty_log(kvm, memslot, NULL);
}
}
void kvmppc_update_lpcr(struct kvm *kvm, unsigned long lpcr, unsigned long mask)
{
long int i;
u32 cores_done = 0;
if ((kvm->arch.lpcr & mask) == lpcr)
return;
kvm->arch.lpcr = (kvm->arch.lpcr & ~mask) | lpcr;
for (i = 0; i < KVM_MAX_VCORES; ++i) {
struct kvmppc_vcore *vc = kvm->arch.vcores[i];
if (!vc)
continue;
spin_lock(&vc->lock);
vc->lpcr = (vc->lpcr & ~mask) | lpcr;
spin_unlock(&vc->lock);
if (++cores_done >= kvm->arch.online_vcores)
break;
}
}
static void kvmppc_mmu_destroy_hv(struct kvm_vcpu *vcpu)
{
return;
}
static int kvmppc_hv_setup_htab_rma(struct kvm_vcpu *vcpu)
{
int err = 0;
struct kvm *kvm = vcpu->kvm;
unsigned long hva;
struct kvm_memory_slot *memslot;
struct vm_area_struct *vma;
unsigned long lpcr = 0, senc;
unsigned long psize, porder;
int srcu_idx;
mutex_lock(&kvm->lock);
if (kvm->arch.rma_setup_done)
goto out;
if (!kvm->arch.hpt_virt) {
err = kvmppc_alloc_hpt(kvm, NULL);
if (err) {
pr_err("KVM: Couldn't alloc HPT\n");
goto out;
}
}
srcu_idx = srcu_read_lock(&kvm->srcu);
memslot = gfn_to_memslot(kvm, 0);
err = -EINVAL;
if (!memslot || (memslot->flags & KVM_MEMSLOT_INVALID))
goto out_srcu;
hva = memslot->userspace_addr;
down_read(&current->mm->mmap_sem);
vma = find_vma(current->mm, hva);
if (!vma || vma->vm_start > hva || (vma->vm_flags & VM_IO))
goto up_out;
psize = vma_kernel_pagesize(vma);
porder = __ilog2(psize);
up_read(&current->mm->mmap_sem);
err = -EINVAL;
if (!(psize == 0x1000 || psize == 0x10000 ||
psize == 0x1000000))
goto out_srcu;
senc = slb_pgsize_encoding(psize);
kvm->arch.vrma_slb_v = senc | SLB_VSID_B_1T |
(VRMA_VSID << SLB_VSID_SHIFT_1T);
lpcr = senc << (LPCR_VRMASD_SH - 4);
kvmppc_map_vrma(vcpu, memslot, porder);
kvmppc_update_lpcr(kvm, lpcr, LPCR_VRMASD);
smp_wmb();
kvm->arch.rma_setup_done = 1;
err = 0;
out_srcu:
srcu_read_unlock(&kvm->srcu, srcu_idx);
out:
mutex_unlock(&kvm->lock);
return err;
up_out:
up_read(&current->mm->mmap_sem);
goto out_srcu;
}
static int kvmppc_core_init_vm_hv(struct kvm *kvm)
{
unsigned long lpcr, lpid;
lpid = kvmppc_alloc_lpid();
if ((long)lpid < 0)
return -ENOMEM;
kvm->arch.lpid = lpid;
cpumask_setall(&kvm->arch.need_tlb_flush);
memcpy(kvm->arch.enabled_hcalls, default_enabled_hcalls,
sizeof(kvm->arch.enabled_hcalls));
kvm->arch.host_sdr1 = mfspr(SPRN_SDR1);
kvm->arch.host_lpid = mfspr(SPRN_LPID);
kvm->arch.host_lpcr = lpcr = mfspr(SPRN_LPCR);
lpcr &= LPCR_PECE | LPCR_LPES;
lpcr |= (4UL << LPCR_DPFD_SH) | LPCR_HDICE |
LPCR_VPM0 | LPCR_VPM1;
kvm->arch.vrma_slb_v = SLB_VSID_B_1T |
(VRMA_VSID << SLB_VSID_SHIFT_1T);
if (cpu_has_feature(CPU_FTR_ARCH_207S))
lpcr |= LPCR_ONL;
kvm->arch.lpcr = lpcr;
kvm_hv_vm_activated();
return 0;
}
static void kvmppc_free_vcores(struct kvm *kvm)
{
long int i;
for (i = 0; i < KVM_MAX_VCORES; ++i) {
if (kvm->arch.vcores[i] && kvm->arch.vcores[i]->mpp_buffer) {
struct kvmppc_vcore *vc = kvm->arch.vcores[i];
free_pages((unsigned long)vc->mpp_buffer,
MPP_BUFFER_ORDER);
}
kfree(kvm->arch.vcores[i]);
}
kvm->arch.online_vcores = 0;
}
static void kvmppc_core_destroy_vm_hv(struct kvm *kvm)
{
kvm_hv_vm_deactivated();
kvmppc_free_vcores(kvm);
kvmppc_free_hpt(kvm);
}
static int kvmppc_core_emulate_op_hv(struct kvm_run *run, struct kvm_vcpu *vcpu,
unsigned int inst, int *advance)
{
return EMULATE_FAIL;
}
static int kvmppc_core_emulate_mtspr_hv(struct kvm_vcpu *vcpu, int sprn,
ulong spr_val)
{
return EMULATE_FAIL;
}
static int kvmppc_core_emulate_mfspr_hv(struct kvm_vcpu *vcpu, int sprn,
ulong *spr_val)
{
return EMULATE_FAIL;
}
static int kvmppc_core_check_processor_compat_hv(void)
{
if (!cpu_has_feature(CPU_FTR_HVMODE) ||
!cpu_has_feature(CPU_FTR_ARCH_206))
return -EIO;
return 0;
}
static long kvm_arch_vm_ioctl_hv(struct file *filp,
unsigned int ioctl, unsigned long arg)
{
struct kvm *kvm __maybe_unused = filp->private_data;
void __user *argp = (void __user *)arg;
long r;
switch (ioctl) {
case KVM_PPC_ALLOCATE_HTAB: {
u32 htab_order;
r = -EFAULT;
if (get_user(htab_order, (u32 __user *)argp))
break;
r = kvmppc_alloc_reset_hpt(kvm, &htab_order);
if (r)
break;
r = -EFAULT;
if (put_user(htab_order, (u32 __user *)argp))
break;
r = 0;
break;
}
case KVM_PPC_GET_HTAB_FD: {
struct kvm_get_htab_fd ghf;
r = -EFAULT;
if (copy_from_user(&ghf, argp, sizeof(ghf)))
break;
r = kvm_vm_ioctl_get_htab_fd(kvm, &ghf);
break;
}
default:
r = -ENOTTY;
}
return r;
}
static void init_default_hcalls(void)
{
int i;
unsigned int hcall;
for (i = 0; default_hcall_list[i]; ++i) {
hcall = default_hcall_list[i];
WARN_ON(!kvmppc_hcall_impl_hv(hcall));
__set_bit(hcall / 4, default_enabled_hcalls);
}
}
static int kvmppc_book3s_init_hv(void)
{
int r;
r = kvmppc_core_check_processor_compat_hv();
if (r < 0)
return -ENODEV;
kvm_ops_hv.owner = THIS_MODULE;
kvmppc_hv_ops = &kvm_ops_hv;
init_default_hcalls();
r = kvmppc_mmu_hv_init();
return r;
}
static void kvmppc_book3s_exit_hv(void)
{
kvmppc_hv_ops = NULL;
}
