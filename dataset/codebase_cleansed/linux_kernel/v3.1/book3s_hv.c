void kvmppc_core_vcpu_load(struct kvm_vcpu *vcpu, int cpu)
{
local_paca->kvm_hstate.kvm_vcpu = vcpu;
local_paca->kvm_hstate.kvm_vcore = vcpu->arch.vcore;
}
void kvmppc_core_vcpu_put(struct kvm_vcpu *vcpu)
{
}
void kvmppc_vcpu_block(struct kvm_vcpu *vcpu)
{
u64 now;
unsigned long dec_nsec;
now = get_tb();
if (now >= vcpu->arch.dec_expires && !kvmppc_core_pending_dec(vcpu))
kvmppc_core_queue_dec(vcpu);
if (vcpu->arch.pending_exceptions)
return;
if (vcpu->arch.dec_expires != ~(u64)0) {
dec_nsec = (vcpu->arch.dec_expires - now) * NSEC_PER_SEC /
tb_ticks_per_sec;
hrtimer_start(&vcpu->arch.dec_timer, ktime_set(0, dec_nsec),
HRTIMER_MODE_REL);
}
kvmppc_vcpu_blocked(vcpu);
kvm_vcpu_block(vcpu);
vcpu->stat.halt_wakeup++;
if (vcpu->arch.dec_expires != ~(u64)0)
hrtimer_try_to_cancel(&vcpu->arch.dec_timer);
kvmppc_vcpu_unblocked(vcpu);
}
void kvmppc_set_msr(struct kvm_vcpu *vcpu, u64 msr)
{
vcpu->arch.shregs.msr = msr;
}
void kvmppc_set_pvr(struct kvm_vcpu *vcpu, u32 pvr)
{
vcpu->arch.pvr = pvr;
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
vcpu->kvm->arch.lpcr, vcpu->kvm->arch.sdr1,
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
vpa->shared_proc = 1;
vpa->yield_count = 1;
}
static unsigned long do_h_register_vpa(struct kvm_vcpu *vcpu,
unsigned long flags,
unsigned long vcpuid, unsigned long vpa)
{
struct kvm *kvm = vcpu->kvm;
unsigned long pg_index, ra, len;
unsigned long pg_offset;
void *va;
struct kvm_vcpu *tvcpu;
tvcpu = kvmppc_find_vcpu(kvm, vcpuid);
if (!tvcpu)
return H_PARAMETER;
flags >>= 63 - 18;
flags &= 7;
if (flags == 0 || flags == 4)
return H_PARAMETER;
if (flags < 4) {
if (vpa & 0x7f)
return H_PARAMETER;
pg_index = vpa >> kvm->arch.ram_porder;
pg_offset = vpa & (kvm->arch.ram_psize - 1);
if (pg_index >= kvm->arch.ram_npages)
return H_PARAMETER;
if (kvm->arch.ram_pginfo[pg_index].pfn == 0)
return H_PARAMETER;
ra = kvm->arch.ram_pginfo[pg_index].pfn << PAGE_SHIFT;
ra |= pg_offset;
va = __va(ra);
if (flags <= 1)
len = *(unsigned short *)(va + 4);
else
len = *(unsigned int *)(va + 4);
if (pg_offset + len > kvm->arch.ram_psize)
return H_PARAMETER;
switch (flags) {
case 1:
if (len < 640)
return H_PARAMETER;
tvcpu->arch.vpa = va;
init_vpa(vcpu, va);
break;
case 2:
if (len < 48)
return H_PARAMETER;
if (!tvcpu->arch.vpa)
return H_RESOURCE;
len -= len % 48;
tvcpu->arch.dtl = va;
tvcpu->arch.dtl_end = va + len;
break;
case 3:
if (len < 8)
return H_PARAMETER;
if (!tvcpu->arch.vpa)
return H_RESOURCE;
tvcpu->arch.slb_shadow = va;
len = (len - 16) / 16;
tvcpu->arch.slb_shadow = va;
break;
}
} else {
switch (flags) {
case 5:
if (tvcpu->arch.slb_shadow || tvcpu->arch.dtl)
return H_RESOURCE;
tvcpu->arch.vpa = NULL;
break;
case 6:
tvcpu->arch.dtl = NULL;
break;
case 7:
tvcpu->arch.slb_shadow = NULL;
break;
}
}
return H_SUCCESS;
}
int kvmppc_pseries_do_hcall(struct kvm_vcpu *vcpu)
{
unsigned long req = kvmppc_get_gpr(vcpu, 3);
unsigned long target, ret = H_SUCCESS;
struct kvm_vcpu *tvcpu;
switch (req) {
case H_CEDE:
vcpu->arch.shregs.msr |= MSR_EE;
vcpu->arch.ceded = 1;
smp_mb();
if (!vcpu->arch.prodded)
kvmppc_vcpu_block(vcpu);
else
vcpu->arch.prodded = 0;
smp_mb();
vcpu->arch.ceded = 0;
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
break;
case H_REGISTER_VPA:
ret = do_h_register_vpa(vcpu, kvmppc_get_gpr(vcpu, 4),
kvmppc_get_gpr(vcpu, 5),
kvmppc_get_gpr(vcpu, 6));
break;
default:
return RESUME_HOST;
}
kvmppc_set_gpr(vcpu, 3, ret);
vcpu->arch.hcall_needed = 0;
return RESUME_GUEST;
}
static int kvmppc_handle_exit(struct kvm_run *run, struct kvm_vcpu *vcpu,
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
vcpu->stat.ext_intr_exits++;
r = RESUME_GUEST;
break;
case BOOK3S_INTERRUPT_PERFMON:
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
if (vcpu->arch.shregs.msr & MSR_PR) {
kvmppc_book3s_queue_irqprio(vcpu, BOOK3S_INTERRUPT_SYSCALL);
r = RESUME_GUEST;
break;
}
run->papr_hcall.nr = kvmppc_get_gpr(vcpu, 3);
for (i = 0; i < 9; ++i)
run->papr_hcall.args[i] = kvmppc_get_gpr(vcpu, 4 + i);
run->exit_reason = KVM_EXIT_PAPR_HCALL;
vcpu->arch.hcall_needed = 1;
r = RESUME_HOST;
break;
}
case BOOK3S_INTERRUPT_H_DATA_STORAGE:
vcpu->arch.shregs.dsisr = vcpu->arch.fault_dsisr;
vcpu->arch.shregs.dar = vcpu->arch.fault_dar;
kvmppc_inject_interrupt(vcpu, BOOK3S_INTERRUPT_DATA_STORAGE, 0);
r = RESUME_GUEST;
break;
case BOOK3S_INTERRUPT_H_INST_STORAGE:
kvmppc_inject_interrupt(vcpu, BOOK3S_INTERRUPT_INST_STORAGE,
0x08000000);
r = RESUME_GUEST;
break;
case BOOK3S_INTERRUPT_H_EMUL_ASSIST:
kvmppc_core_queue_program(vcpu, 0x80000);
r = RESUME_GUEST;
break;
default:
kvmppc_dump_regs(vcpu);
printk(KERN_EMERG "trap=0x%x | pc=0x%lx | msr=0x%llx\n",
vcpu->arch.trap, kvmppc_get_pc(vcpu),
vcpu->arch.shregs.msr);
r = RESUME_HOST;
BUG();
break;
}
if (!(r & RESUME_HOST)) {
if (signal_pending(tsk)) {
vcpu->stat.signal_exits++;
run->exit_reason = KVM_EXIT_INTR;
r = -EINTR;
} else {
kvmppc_core_deliver_interrupts(vcpu);
}
}
return r;
}
int kvm_arch_vcpu_ioctl_get_sregs(struct kvm_vcpu *vcpu,
struct kvm_sregs *sregs)
{
int i;
sregs->pvr = vcpu->arch.pvr;
memset(sregs, 0, sizeof(struct kvm_sregs));
for (i = 0; i < vcpu->arch.slb_max; i++) {
sregs->u.s.ppc64.slb[i].slbe = vcpu->arch.slb[i].orige;
sregs->u.s.ppc64.slb[i].slbv = vcpu->arch.slb[i].origv;
}
return 0;
}
int kvm_arch_vcpu_ioctl_set_sregs(struct kvm_vcpu *vcpu,
struct kvm_sregs *sregs)
{
int i, j;
kvmppc_set_pvr(vcpu, sregs->pvr);
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
int kvmppc_core_check_processor_compat(void)
{
if (cpu_has_feature(CPU_FTR_HVMODE))
return 0;
return -EIO;
}
struct kvm_vcpu *kvmppc_core_vcpu_create(struct kvm *kvm, unsigned int id)
{
struct kvm_vcpu *vcpu;
int err = -EINVAL;
int core;
struct kvmppc_vcore *vcore;
core = id / threads_per_core;
if (core >= KVM_MAX_VCORES)
goto out;
err = -ENOMEM;
vcpu = kzalloc(sizeof(struct kvm_vcpu), GFP_KERNEL);
if (!vcpu)
goto out;
err = kvm_vcpu_init(vcpu, kvm, id);
if (err)
goto free_vcpu;
vcpu->arch.shared = &vcpu->arch.shregs;
vcpu->arch.last_cpu = -1;
vcpu->arch.mmcr[0] = MMCR0_FC;
vcpu->arch.ctrl = CTRL_RUNLATCH;
vcpu->arch.pvr = mfspr(SPRN_PVR);
kvmppc_set_pvr(vcpu, vcpu->arch.pvr);
kvmppc_mmu_book3s_hv_init(vcpu);
vcpu->arch.state = KVMPPC_VCPU_BLOCKED;
init_waitqueue_head(&vcpu->arch.cpu_run);
mutex_lock(&kvm->lock);
vcore = kvm->arch.vcores[core];
if (!vcore) {
vcore = kzalloc(sizeof(struct kvmppc_vcore), GFP_KERNEL);
if (vcore) {
INIT_LIST_HEAD(&vcore->runnable_threads);
spin_lock_init(&vcore->lock);
}
kvm->arch.vcores[core] = vcore;
}
mutex_unlock(&kvm->lock);
if (!vcore)
goto free_vcpu;
spin_lock(&vcore->lock);
++vcore->num_threads;
++vcore->n_blocked;
spin_unlock(&vcore->lock);
vcpu->arch.vcore = vcore;
return vcpu;
free_vcpu:
kfree(vcpu);
out:
return ERR_PTR(err);
}
void kvmppc_core_vcpu_free(struct kvm_vcpu *vcpu)
{
kvm_vcpu_uninit(vcpu);
kfree(vcpu);
}
static void kvmppc_vcpu_blocked(struct kvm_vcpu *vcpu)
{
struct kvmppc_vcore *vc = vcpu->arch.vcore;
spin_lock(&vc->lock);
vcpu->arch.state = KVMPPC_VCPU_BLOCKED;
++vc->n_blocked;
if (vc->n_runnable > 0 &&
vc->n_runnable + vc->n_blocked == vc->num_threads) {
vcpu = list_first_entry(&vc->runnable_threads, struct kvm_vcpu,
arch.run_list);
wake_up(&vcpu->arch.cpu_run);
}
spin_unlock(&vc->lock);
}
static void kvmppc_vcpu_unblocked(struct kvm_vcpu *vcpu)
{
struct kvmppc_vcore *vc = vcpu->arch.vcore;
spin_lock(&vc->lock);
vcpu->arch.state = KVMPPC_VCPU_BUSY_IN_HOST;
--vc->n_blocked;
spin_unlock(&vc->lock);
}
static void kvmppc_remove_runnable(struct kvmppc_vcore *vc,
struct kvm_vcpu *vcpu)
{
struct kvm_vcpu *v;
if (vcpu->arch.state != KVMPPC_VCPU_RUNNABLE)
return;
vcpu->arch.state = KVMPPC_VCPU_BUSY_IN_HOST;
--vc->n_runnable;
v = vcpu;
list_for_each_entry_continue(v, &vc->runnable_threads, arch.run_list)
--v->arch.ptid;
list_del(&vcpu->arch.run_list);
}
static void kvmppc_start_thread(struct kvm_vcpu *vcpu)
{
int cpu;
struct paca_struct *tpaca;
struct kvmppc_vcore *vc = vcpu->arch.vcore;
cpu = vc->pcpu + vcpu->arch.ptid;
tpaca = &paca[cpu];
tpaca->kvm_hstate.kvm_vcpu = vcpu;
tpaca->kvm_hstate.kvm_vcore = vc;
smp_wmb();
#ifdef CONFIG_PPC_ICP_NATIVE
if (vcpu->arch.ptid) {
tpaca->cpu_start = 0x80;
tpaca->kvm_hstate.in_guest = KVM_GUEST_MODE_GUEST;
wmb();
xics_wake_cpu(cpu);
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
int thr = cpu_thread_in_core(cpu);
if (thr)
return 0;
while (++thr < threads_per_core)
if (cpu_online(cpu + thr))
return 0;
return 1;
}
static int kvmppc_run_core(struct kvmppc_vcore *vc)
{
struct kvm_vcpu *vcpu, *vnext;
long ret;
u64 now;
list_for_each_entry(vcpu, &vc->runnable_threads, arch.run_list)
if (signal_pending(vcpu->arch.run_task))
return 0;
if (threads_per_core > 1 && !on_primary_thread()) {
list_for_each_entry(vcpu, &vc->runnable_threads, arch.run_list)
vcpu->arch.ret = -EBUSY;
goto out;
}
vc->n_woken = 0;
vc->nap_count = 0;
vc->entry_exit_count = 0;
vc->vcore_running = 1;
vc->in_guest = 0;
vc->pcpu = smp_processor_id();
list_for_each_entry(vcpu, &vc->runnable_threads, arch.run_list)
kvmppc_start_thread(vcpu);
vcpu = list_first_entry(&vc->runnable_threads, struct kvm_vcpu,
arch.run_list);
spin_unlock(&vc->lock);
preempt_disable();
kvm_guest_enter();
__kvmppc_vcore_entry(NULL, vcpu);
spin_lock(&vc->lock);
if (vc->nap_count < vc->n_woken)
kvmppc_wait_for_nap(vc);
vc->vcore_running = 2;
spin_unlock(&vc->lock);
smp_mb();
kvm_guest_exit();
preempt_enable();
kvm_resched(vcpu);
now = get_tb();
list_for_each_entry(vcpu, &vc->runnable_threads, arch.run_list) {
if (now < vcpu->arch.dec_expires &&
kvmppc_core_pending_dec(vcpu))
kvmppc_core_dequeue_dec(vcpu);
if (!vcpu->arch.trap) {
if (signal_pending(vcpu->arch.run_task)) {
vcpu->arch.kvm_run->exit_reason = KVM_EXIT_INTR;
vcpu->arch.ret = -EINTR;
}
continue;
}
ret = kvmppc_handle_exit(vcpu->arch.kvm_run, vcpu,
vcpu->arch.run_task);
vcpu->arch.ret = ret;
vcpu->arch.trap = 0;
}
spin_lock(&vc->lock);
out:
vc->vcore_running = 0;
list_for_each_entry_safe(vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if (vcpu->arch.ret != RESUME_GUEST) {
kvmppc_remove_runnable(vc, vcpu);
wake_up(&vcpu->arch.cpu_run);
}
}
return 1;
}
static int kvmppc_run_vcpu(struct kvm_run *kvm_run, struct kvm_vcpu *vcpu)
{
int ptid;
int wait_state;
struct kvmppc_vcore *vc;
DEFINE_WAIT(wait);
if (signal_pending(current)) {
kvm_run->exit_reason = KVM_EXIT_INTR;
return -EINTR;
}
if (!vcpu->kvm->arch.rma && cpu_has_feature(CPU_FTR_ARCH_201))
return -EPERM;
kvm_run->exit_reason = 0;
vcpu->arch.ret = RESUME_GUEST;
vcpu->arch.trap = 0;
flush_fp_to_thread(current);
flush_altivec_to_thread(current);
flush_vsx_to_thread(current);
vc = vcpu->arch.vcore;
spin_lock(&vc->lock);
if (vcpu->arch.state == KVMPPC_VCPU_BLOCKED)
--vc->n_blocked;
vcpu->arch.state = KVMPPC_VCPU_RUNNABLE;
ptid = vc->n_runnable;
vcpu->arch.run_task = current;
vcpu->arch.kvm_run = kvm_run;
vcpu->arch.ptid = ptid;
list_add_tail(&vcpu->arch.run_list, &vc->runnable_threads);
++vc->n_runnable;
wait_state = TASK_INTERRUPTIBLE;
while (vcpu->arch.state == KVMPPC_VCPU_RUNNABLE) {
if (signal_pending(current)) {
if (!vc->vcore_running) {
kvm_run->exit_reason = KVM_EXIT_INTR;
vcpu->arch.ret = -EINTR;
break;
}
wait_state = TASK_UNINTERRUPTIBLE;
smp_send_reschedule(vc->pcpu);
}
if (!vc->vcore_running &&
vc->n_runnable + vc->n_blocked == vc->num_threads) {
if (kvmppc_run_core(vc))
continue;
}
if (vc->vcore_running == 1 && VCORE_EXIT_COUNT(vc) == 0)
kvmppc_start_thread(vcpu);
prepare_to_wait(&vcpu->arch.cpu_run, &wait, wait_state);
spin_unlock(&vc->lock);
schedule();
finish_wait(&vcpu->arch.cpu_run, &wait);
spin_lock(&vc->lock);
}
if (vcpu->arch.state == KVMPPC_VCPU_RUNNABLE)
kvmppc_remove_runnable(vc, vcpu);
spin_unlock(&vc->lock);
return vcpu->arch.ret;
}
int kvmppc_vcpu_run(struct kvm_run *run, struct kvm_vcpu *vcpu)
{
int r;
do {
r = kvmppc_run_vcpu(run, vcpu);
if (run->exit_reason == KVM_EXIT_PAPR_HCALL &&
!(vcpu->arch.shregs.msr & MSR_PR)) {
r = kvmppc_pseries_do_hcall(vcpu);
kvmppc_core_deliver_interrupts(vcpu);
}
} while (r == RESUME_GUEST);
return r;
}
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
stt = kzalloc(sizeof(*stt) + npages* sizeof(struct page *),
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
stt, O_RDWR);
fail:
if (stt) {
for (i = 0; i < npages; i++)
if (stt->pages[i])
__free_page(stt->pages[i]);
kfree(stt);
}
return ret;
}
static inline int lpcr_rmls(unsigned long rma_size)
{
switch (rma_size) {
case 32ul << 20:
if (cpu_has_feature(CPU_FTR_ARCH_206))
return 8;
return -1;
case 64ul << 20:
return 3;
case 128ul << 20:
return 7;
case 256ul << 20:
return 4;
case 1ul << 30:
return 2;
case 16ul << 30:
return 1;
case 256ul << 30:
return 0;
default:
return -1;
}
}
static int kvm_rma_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct kvmppc_rma_info *ri = vma->vm_file->private_data;
struct page *page;
if (vmf->pgoff >= ri->npages)
return VM_FAULT_SIGBUS;
page = pfn_to_page(ri->base_pfn + vmf->pgoff);
get_page(page);
vmf->page = page;
return 0;
}
static int kvm_rma_mmap(struct file *file, struct vm_area_struct *vma)
{
vma->vm_flags |= VM_RESERVED;
vma->vm_ops = &kvm_rma_vm_ops;
return 0;
}
static int kvm_rma_release(struct inode *inode, struct file *filp)
{
struct kvmppc_rma_info *ri = filp->private_data;
kvm_release_rma(ri);
return 0;
}
long kvm_vm_ioctl_allocate_rma(struct kvm *kvm, struct kvm_allocate_rma *ret)
{
struct kvmppc_rma_info *ri;
long fd;
ri = kvm_alloc_rma();
if (!ri)
return -ENOMEM;
fd = anon_inode_getfd("kvm-rma", &kvm_rma_fops, ri, O_RDWR);
if (fd < 0)
kvm_release_rma(ri);
ret->rma_size = ri->npages << PAGE_SHIFT;
return fd;
}
static struct page *hva_to_page(unsigned long addr)
{
struct page *page[1];
int npages;
might_sleep();
npages = get_user_pages_fast(addr, 1, 1, page);
if (unlikely(npages != 1))
return 0;
return page[0];
}
int kvmppc_core_prepare_memory_region(struct kvm *kvm,
struct kvm_userspace_memory_region *mem)
{
unsigned long psize, porder;
unsigned long i, npages, totalpages;
unsigned long pg_ix;
struct kvmppc_pginfo *pginfo;
unsigned long hva;
struct kvmppc_rma_info *ri = NULL;
struct page *page;
porder = LARGE_PAGE_ORDER;
psize = 1ul << porder;
if ((mem->memory_size & (psize - 1)) ||
(mem->guest_phys_addr & (psize - 1))) {
pr_err("bad memory_size=%llx @ %llx\n",
mem->memory_size, mem->guest_phys_addr);
return -EINVAL;
}
npages = mem->memory_size >> porder;
totalpages = (mem->guest_phys_addr + mem->memory_size) >> porder;
if (totalpages > (1ul << (MAX_MEM_ORDER - LARGE_PAGE_ORDER)))
return -EINVAL;
if (mem->guest_phys_addr == 0 && kvm->arch.rma)
return -EINVAL;
if (totalpages > kvm->arch.ram_npages)
kvm->arch.ram_npages = totalpages;
if (mem->guest_phys_addr == 0) {
struct vm_area_struct *vma;
down_read(&current->mm->mmap_sem);
vma = find_vma(current->mm, mem->userspace_addr);
if (vma && vma->vm_file &&
vma->vm_file->f_op == &kvm_rma_fops &&
mem->userspace_addr == vma->vm_start)
ri = vma->vm_file->private_data;
up_read(&current->mm->mmap_sem);
if (!ri && cpu_has_feature(CPU_FTR_ARCH_201)) {
pr_err("CPU requires an RMO\n");
return -EINVAL;
}
}
if (ri) {
unsigned long rma_size;
unsigned long lpcr;
long rmls;
rma_size = ri->npages << PAGE_SHIFT;
if (rma_size > mem->memory_size)
rma_size = mem->memory_size;
rmls = lpcr_rmls(rma_size);
if (rmls < 0) {
pr_err("Can't use RMA of 0x%lx bytes\n", rma_size);
return -EINVAL;
}
atomic_inc(&ri->use_count);
kvm->arch.rma = ri;
kvm->arch.n_rma_pages = rma_size >> porder;
lpcr = kvm->arch.lpcr;
if (cpu_has_feature(CPU_FTR_ARCH_201)) {
lpcr &= ~((1ul << HID4_RMLS0_SH) |
(3ul << HID4_RMLS2_SH));
lpcr |= ((rmls >> 2) << HID4_RMLS0_SH) |
((rmls & 3) << HID4_RMLS2_SH);
lpcr |= ((ri->base_pfn >> (26 - PAGE_SHIFT)) & 0xffff)
<< HID4_RMOR_SH;
} else {
lpcr &= ~(LPCR_VPM0 | LPCR_VRMA_L);
lpcr |= rmls << LPCR_RMLS_SH;
kvm->arch.rmor = kvm->arch.rma->base_pfn << PAGE_SHIFT;
}
kvm->arch.lpcr = lpcr;
pr_info("Using RMO at %lx size %lx (LPCR = %lx)\n",
ri->base_pfn << PAGE_SHIFT, rma_size, lpcr);
}
pg_ix = mem->guest_phys_addr >> porder;
pginfo = kvm->arch.ram_pginfo + pg_ix;
for (i = 0; i < npages; ++i, ++pg_ix) {
if (ri && pg_ix < kvm->arch.n_rma_pages) {
pginfo[i].pfn = ri->base_pfn +
(pg_ix << (porder - PAGE_SHIFT));
continue;
}
hva = mem->userspace_addr + (i << porder);
page = hva_to_page(hva);
if (!page) {
pr_err("oops, no pfn for hva %lx\n", hva);
goto err;
}
if (!PageHead(page) ||
compound_order(page) != (LARGE_PAGE_ORDER - PAGE_SHIFT)) {
pr_err("page at %lx isn't 16MB (o=%d)\n",
hva, compound_order(page));
goto err;
}
pginfo[i].pfn = page_to_pfn(page);
}
return 0;
err:
return -EINVAL;
}
void kvmppc_core_commit_memory_region(struct kvm *kvm,
struct kvm_userspace_memory_region *mem)
{
if (mem->guest_phys_addr == 0 && mem->memory_size != 0 &&
!kvm->arch.rma)
kvmppc_map_vrma(kvm, mem);
}
int kvmppc_core_init_vm(struct kvm *kvm)
{
long r;
unsigned long npages = 1ul << (MAX_MEM_ORDER - LARGE_PAGE_ORDER);
long err = -ENOMEM;
unsigned long lpcr;
r = kvmppc_alloc_hpt(kvm);
if (r)
return r;
INIT_LIST_HEAD(&kvm->arch.spapr_tce_tables);
kvm->arch.ram_pginfo = kzalloc(npages * sizeof(struct kvmppc_pginfo),
GFP_KERNEL);
if (!kvm->arch.ram_pginfo) {
pr_err("kvmppc_core_init_vm: couldn't alloc %lu bytes\n",
npages * sizeof(struct kvmppc_pginfo));
goto out_free;
}
kvm->arch.ram_npages = 0;
kvm->arch.ram_psize = 1ul << LARGE_PAGE_ORDER;
kvm->arch.ram_porder = LARGE_PAGE_ORDER;
kvm->arch.rma = NULL;
kvm->arch.n_rma_pages = 0;
kvm->arch.host_sdr1 = mfspr(SPRN_SDR1);
if (cpu_has_feature(CPU_FTR_ARCH_201)) {
unsigned long lpid = kvm->arch.lpid;
kvm->arch.host_lpid = 0;
kvm->arch.host_lpcr = lpcr = mfspr(SPRN_HID4);
lpcr &= ~((3 << HID4_LPID1_SH) | (0xful << HID4_LPID5_SH));
lpcr |= ((lpid >> 4) << HID4_LPID1_SH) |
((lpid & 0xf) << HID4_LPID5_SH);
} else {
kvm->arch.host_lpid = mfspr(SPRN_LPID);
kvm->arch.host_lpcr = lpcr = mfspr(SPRN_LPCR);
lpcr &= LPCR_PECE | LPCR_LPES;
lpcr |= (4UL << LPCR_DPFD_SH) | LPCR_HDICE |
LPCR_VPM0 | LPCR_VRMA_L;
}
kvm->arch.lpcr = lpcr;
return 0;
out_free:
kvmppc_free_hpt(kvm);
return err;
}
void kvmppc_core_destroy_vm(struct kvm *kvm)
{
struct kvmppc_pginfo *pginfo;
unsigned long i;
if (kvm->arch.ram_pginfo) {
pginfo = kvm->arch.ram_pginfo;
kvm->arch.ram_pginfo = NULL;
for (i = kvm->arch.n_rma_pages; i < kvm->arch.ram_npages; ++i)
if (pginfo[i].pfn)
put_page(pfn_to_page(pginfo[i].pfn));
kfree(pginfo);
}
if (kvm->arch.rma) {
kvm_release_rma(kvm->arch.rma);
kvm->arch.rma = NULL;
}
kvmppc_free_hpt(kvm);
WARN_ON(!list_empty(&kvm->arch.spapr_tce_tables));
}
void kvmppc_mmu_pte_pflush(struct kvm_vcpu *vcpu, ulong pa_start, ulong pa_end)
{
}
int kvmppc_core_emulate_op(struct kvm_run *run, struct kvm_vcpu *vcpu,
unsigned int inst, int *advance)
{
return EMULATE_FAIL;
}
int kvmppc_core_emulate_mtspr(struct kvm_vcpu *vcpu, int sprn, int rs)
{
return EMULATE_FAIL;
}
int kvmppc_core_emulate_mfspr(struct kvm_vcpu *vcpu, int sprn, int rt)
{
return EMULATE_FAIL;
}
static int kvmppc_book3s_hv_init(void)
{
int r;
r = kvm_init(NULL, sizeof(struct kvm_vcpu), 0, THIS_MODULE);
if (r)
return r;
r = kvmppc_mmu_hv_init();
return r;
}
static void kvmppc_book3s_hv_exit(void)
{
kvm_exit();
}
