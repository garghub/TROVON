static int kvm_mips_reset_vcpu(struct kvm_vcpu *vcpu)
{
int i;
for_each_possible_cpu(i) {
vcpu->arch.guest_kernel_asid[i] = 0;
vcpu->arch.guest_user_asid[i] = 0;
}
return 0;
}
int kvm_arch_vcpu_runnable(struct kvm_vcpu *vcpu)
{
return !!(vcpu->arch.pending_exceptions);
}
int kvm_arch_vcpu_should_kick(struct kvm_vcpu *vcpu)
{
return 1;
}
int kvm_arch_hardware_enable(void)
{
return 0;
}
int kvm_arch_hardware_setup(void)
{
return 0;
}
void kvm_arch_check_processor_compat(void *rtn)
{
*(int *)rtn = 0;
}
static void kvm_mips_init_tlbs(struct kvm *kvm)
{
unsigned long wired;
wired = read_c0_wired();
write_c0_wired(wired + 1);
mtc0_tlbw_hazard();
kvm->arch.commpage_tlb = wired;
kvm_debug("[%d] commpage TLB: %d\n", smp_processor_id(),
kvm->arch.commpage_tlb);
}
static void kvm_mips_init_vm_percpu(void *arg)
{
struct kvm *kvm = (struct kvm *)arg;
kvm_mips_init_tlbs(kvm);
kvm_mips_callbacks->vm_init(kvm);
}
int kvm_arch_init_vm(struct kvm *kvm, unsigned long type)
{
if (atomic_inc_return(&kvm_mips_instance) == 1) {
kvm_debug("%s: 1st KVM instance, setup host TLB parameters\n",
__func__);
on_each_cpu(kvm_mips_init_vm_percpu, kvm, 1);
}
return 0;
}
bool kvm_arch_has_vcpu_debugfs(void)
{
return false;
}
int kvm_arch_create_vcpu_debugfs(struct kvm_vcpu *vcpu)
{
return 0;
}
void kvm_mips_free_vcpus(struct kvm *kvm)
{
unsigned int i;
struct kvm_vcpu *vcpu;
for (i = 0; i < kvm->arch.guest_pmap_npages; i++) {
if (kvm->arch.guest_pmap[i] != KVM_INVALID_PAGE)
kvm_release_pfn_clean(kvm->arch.guest_pmap[i]);
}
kfree(kvm->arch.guest_pmap);
kvm_for_each_vcpu(i, vcpu, kvm) {
kvm_arch_vcpu_free(vcpu);
}
mutex_lock(&kvm->lock);
for (i = 0; i < atomic_read(&kvm->online_vcpus); i++)
kvm->vcpus[i] = NULL;
atomic_set(&kvm->online_vcpus, 0);
mutex_unlock(&kvm->lock);
}
static void kvm_mips_uninit_tlbs(void *arg)
{
write_c0_wired(0);
mtc0_tlbw_hazard();
kvm_local_flush_tlb_all();
}
void kvm_arch_destroy_vm(struct kvm *kvm)
{
kvm_mips_free_vcpus(kvm);
if (atomic_dec_return(&kvm_mips_instance) == 0) {
kvm_debug("%s: last KVM instance, restoring TLB parameters\n",
__func__);
on_each_cpu(kvm_mips_uninit_tlbs, NULL, 1);
}
}
long kvm_arch_dev_ioctl(struct file *filp, unsigned int ioctl,
unsigned long arg)
{
return -ENOIOCTLCMD;
}
int kvm_arch_create_memslot(struct kvm *kvm, struct kvm_memory_slot *slot,
unsigned long npages)
{
return 0;
}
int kvm_arch_prepare_memory_region(struct kvm *kvm,
struct kvm_memory_slot *memslot,
const struct kvm_userspace_memory_region *mem,
enum kvm_mr_change change)
{
return 0;
}
void kvm_arch_commit_memory_region(struct kvm *kvm,
const struct kvm_userspace_memory_region *mem,
const struct kvm_memory_slot *old,
const struct kvm_memory_slot *new,
enum kvm_mr_change change)
{
unsigned long npages = 0;
int i;
kvm_debug("%s: kvm: %p slot: %d, GPA: %llx, size: %llx, QVA: %llx\n",
__func__, kvm, mem->slot, mem->guest_phys_addr,
mem->memory_size, mem->userspace_addr);
if (!kvm->arch.guest_pmap) {
if (mem->slot == 0)
npages = mem->memory_size >> PAGE_SHIFT;
if (npages) {
kvm->arch.guest_pmap_npages = npages;
kvm->arch.guest_pmap =
kzalloc(npages * sizeof(unsigned long), GFP_KERNEL);
if (!kvm->arch.guest_pmap) {
kvm_err("Failed to allocate guest PMAP\n");
return;
}
kvm_debug("Allocated space for Guest PMAP Table (%ld pages) @ %p\n",
npages, kvm->arch.guest_pmap);
for (i = 0; i < npages; i++)
kvm->arch.guest_pmap[i] = KVM_INVALID_PAGE;
}
}
}
static inline void dump_handler(const char *symbol, void *start, void *end)
{
u32 *p;
pr_debug("LEAF(%s)\n", symbol);
pr_debug("\t.set push\n");
pr_debug("\t.set noreorder\n");
for (p = start; p < (u32 *)end; ++p)
pr_debug("\t.word\t0x%08x\t\t# %p\n", *p, p);
pr_debug("\t.set\tpop\n");
pr_debug("\tEND(%s)\n", symbol);
}
struct kvm_vcpu *kvm_arch_vcpu_create(struct kvm *kvm, unsigned int id)
{
int err, size;
void *gebase, *p, *handler;
int i;
struct kvm_vcpu *vcpu = kzalloc(sizeof(struct kvm_vcpu), GFP_KERNEL);
if (!vcpu) {
err = -ENOMEM;
goto out;
}
err = kvm_vcpu_init(vcpu, kvm, id);
if (err)
goto out_free_cpu;
kvm_debug("kvm @ %p: create cpu %d at %p\n", kvm, id, vcpu);
if (cpu_has_veic || cpu_has_vint)
size = 0x200 + VECTORSPACING * 64;
else
size = 0x4000;
gebase = kzalloc(ALIGN(size, PAGE_SIZE), GFP_KERNEL);
if (!gebase) {
err = -ENOMEM;
goto out_uninit_cpu;
}
kvm_debug("Allocated %d bytes for KVM Exception Handlers @ %p\n",
ALIGN(size, PAGE_SIZE), gebase);
if (!cpu_has_ebase_wg && virt_to_phys(gebase) >= 0x20000000) {
kvm_err("CP0_EBase.WG required for guest exception base %pK\n",
gebase);
err = -ENOMEM;
goto out_free_gebase;
}
vcpu->arch.guest_ebase = gebase;
handler = gebase + 0x2000;
kvm_mips_build_exception(gebase, handler);
kvm_mips_build_exception(gebase + 0x180, handler);
for (i = 0; i < 8; i++) {
kvm_debug("L1 Vectored handler @ %p\n",
gebase + 0x200 + (i * VECTORSPACING));
kvm_mips_build_exception(gebase + 0x200 + i * VECTORSPACING,
handler);
}
p = handler;
p = kvm_mips_build_exit(p);
vcpu->arch.vcpu_run = p;
p = kvm_mips_build_vcpu_run(p);
pr_debug("#include <asm/asm.h>\n");
pr_debug("#include <asm/regdef.h>\n");
pr_debug("\n");
dump_handler("kvm_vcpu_run", vcpu->arch.vcpu_run, p);
dump_handler("kvm_gen_exc", gebase + 0x180, gebase + 0x200);
dump_handler("kvm_exit", gebase + 0x2000, vcpu->arch.vcpu_run);
local_flush_icache_range((unsigned long)gebase,
(unsigned long)gebase + ALIGN(size, PAGE_SIZE));
vcpu->arch.kseg0_commpage = kzalloc(PAGE_SIZE << 1, GFP_KERNEL);
if (!vcpu->arch.kseg0_commpage) {
err = -ENOMEM;
goto out_free_gebase;
}
kvm_debug("Allocated COMM page @ %p\n", vcpu->arch.kseg0_commpage);
kvm_mips_commpage_init(vcpu);
vcpu->arch.last_sched_cpu = -1;
kvm_mips_init_count(vcpu);
return vcpu;
out_free_gebase:
kfree(gebase);
out_uninit_cpu:
kvm_vcpu_uninit(vcpu);
out_free_cpu:
kfree(vcpu);
out:
return ERR_PTR(err);
}
void kvm_arch_vcpu_free(struct kvm_vcpu *vcpu)
{
hrtimer_cancel(&vcpu->arch.comparecount_timer);
kvm_vcpu_uninit(vcpu);
kvm_mips_dump_stats(vcpu);
kfree(vcpu->arch.guest_ebase);
kfree(vcpu->arch.kseg0_commpage);
kfree(vcpu);
}
void kvm_arch_vcpu_destroy(struct kvm_vcpu *vcpu)
{
kvm_arch_vcpu_free(vcpu);
}
int kvm_arch_vcpu_ioctl_set_guest_debug(struct kvm_vcpu *vcpu,
struct kvm_guest_debug *dbg)
{
return -ENOIOCTLCMD;
}
static void kvm_mips_check_asids(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
int i, cpu = smp_processor_id();
unsigned int gasid;
if (!KVM_GUEST_KERNEL_MODE(vcpu)) {
gasid = kvm_read_c0_guest_entryhi(cop0) & KVM_ENTRYHI_ASID;
if (gasid != vcpu->arch.last_user_gasid) {
kvm_get_new_mmu_context(&vcpu->arch.guest_user_mm, cpu,
vcpu);
vcpu->arch.guest_user_asid[cpu] =
vcpu->arch.guest_user_mm.context.asid[cpu];
for_each_possible_cpu(i)
if (i != cpu)
vcpu->arch.guest_user_asid[cpu] = 0;
vcpu->arch.last_user_gasid = gasid;
}
}
}
int kvm_arch_vcpu_ioctl_run(struct kvm_vcpu *vcpu, struct kvm_run *run)
{
int r = 0;
sigset_t sigsaved;
if (vcpu->sigset_active)
sigprocmask(SIG_SETMASK, &vcpu->sigset, &sigsaved);
if (vcpu->mmio_needed) {
if (!vcpu->mmio_is_write)
kvm_mips_complete_mmio_load(vcpu, run);
vcpu->mmio_needed = 0;
}
lose_fpu(1);
local_irq_disable();
kvm_mips_deliver_interrupts(vcpu,
kvm_read_c0_guest_cause(vcpu->arch.cop0));
guest_enter_irqoff();
htw_stop();
trace_kvm_enter(vcpu);
kvm_mips_check_asids(vcpu);
r = vcpu->arch.vcpu_run(run, vcpu);
trace_kvm_out(vcpu);
htw_start();
guest_exit_irqoff();
local_irq_enable();
if (vcpu->sigset_active)
sigprocmask(SIG_SETMASK, &sigsaved, NULL);
return r;
}
int kvm_vcpu_ioctl_interrupt(struct kvm_vcpu *vcpu,
struct kvm_mips_interrupt *irq)
{
int intr = (int)irq->irq;
struct kvm_vcpu *dvcpu = NULL;
if (intr == 3 || intr == -3 || intr == 4 || intr == -4)
kvm_debug("%s: CPU: %d, INTR: %d\n", __func__, irq->cpu,
(int)intr);
if (irq->cpu == -1)
dvcpu = vcpu;
else
dvcpu = vcpu->kvm->vcpus[irq->cpu];
if (intr == 2 || intr == 3 || intr == 4) {
kvm_mips_callbacks->queue_io_int(dvcpu, irq);
} else if (intr == -2 || intr == -3 || intr == -4) {
kvm_mips_callbacks->dequeue_io_int(dvcpu, irq);
} else {
kvm_err("%s: invalid interrupt ioctl (%d:%d)\n", __func__,
irq->cpu, irq->irq);
return -EINVAL;
}
dvcpu->arch.wait = 0;
if (swait_active(&dvcpu->wq))
swake_up(&dvcpu->wq);
return 0;
}
int kvm_arch_vcpu_ioctl_get_mpstate(struct kvm_vcpu *vcpu,
struct kvm_mp_state *mp_state)
{
return -ENOIOCTLCMD;
}
int kvm_arch_vcpu_ioctl_set_mpstate(struct kvm_vcpu *vcpu,
struct kvm_mp_state *mp_state)
{
return -ENOIOCTLCMD;
}
static unsigned long kvm_mips_num_regs(struct kvm_vcpu *vcpu)
{
unsigned long ret;
ret = ARRAY_SIZE(kvm_mips_get_one_regs);
if (kvm_mips_guest_can_have_fpu(&vcpu->arch)) {
ret += ARRAY_SIZE(kvm_mips_get_one_regs_fpu) + 48;
if (boot_cpu_data.fpu_id & MIPS_FPIR_F64)
ret += 16;
}
if (kvm_mips_guest_can_have_msa(&vcpu->arch))
ret += ARRAY_SIZE(kvm_mips_get_one_regs_msa) + 32;
ret += __arch_hweight8(vcpu->arch.kscratch_enabled);
ret += kvm_mips_callbacks->num_regs(vcpu);
return ret;
}
static int kvm_mips_copy_reg_indices(struct kvm_vcpu *vcpu, u64 __user *indices)
{
u64 index;
unsigned int i;
if (copy_to_user(indices, kvm_mips_get_one_regs,
sizeof(kvm_mips_get_one_regs)))
return -EFAULT;
indices += ARRAY_SIZE(kvm_mips_get_one_regs);
if (kvm_mips_guest_can_have_fpu(&vcpu->arch)) {
if (copy_to_user(indices, kvm_mips_get_one_regs_fpu,
sizeof(kvm_mips_get_one_regs_fpu)))
return -EFAULT;
indices += ARRAY_SIZE(kvm_mips_get_one_regs_fpu);
for (i = 0; i < 32; ++i) {
index = KVM_REG_MIPS_FPR_32(i);
if (copy_to_user(indices, &index, sizeof(index)))
return -EFAULT;
++indices;
if (i & 1 && !(boot_cpu_data.fpu_id & MIPS_FPIR_F64))
continue;
index = KVM_REG_MIPS_FPR_64(i);
if (copy_to_user(indices, &index, sizeof(index)))
return -EFAULT;
++indices;
}
}
if (kvm_mips_guest_can_have_msa(&vcpu->arch)) {
if (copy_to_user(indices, kvm_mips_get_one_regs_msa,
sizeof(kvm_mips_get_one_regs_msa)))
return -EFAULT;
indices += ARRAY_SIZE(kvm_mips_get_one_regs_msa);
for (i = 0; i < 32; ++i) {
index = KVM_REG_MIPS_VEC_128(i);
if (copy_to_user(indices, &index, sizeof(index)))
return -EFAULT;
++indices;
}
}
for (i = 0; i < 6; ++i) {
if (!(vcpu->arch.kscratch_enabled & BIT(i + 2)))
continue;
if (copy_to_user(indices, &kvm_mips_get_one_regs_kscratch[i],
sizeof(kvm_mips_get_one_regs_kscratch[i])))
return -EFAULT;
++indices;
}
return kvm_mips_callbacks->copy_reg_indices(vcpu, indices);
}
static int kvm_mips_get_reg(struct kvm_vcpu *vcpu,
const struct kvm_one_reg *reg)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
struct mips_fpu_struct *fpu = &vcpu->arch.fpu;
int ret;
s64 v;
s64 vs[2];
unsigned int idx;
switch (reg->id) {
case KVM_REG_MIPS_R0 ... KVM_REG_MIPS_R31:
v = (long)vcpu->arch.gprs[reg->id - KVM_REG_MIPS_R0];
break;
#ifndef CONFIG_CPU_MIPSR6
case KVM_REG_MIPS_HI:
v = (long)vcpu->arch.hi;
break;
case KVM_REG_MIPS_LO:
v = (long)vcpu->arch.lo;
break;
#endif
case KVM_REG_MIPS_PC:
v = (long)vcpu->arch.pc;
break;
case KVM_REG_MIPS_FPR_32(0) ... KVM_REG_MIPS_FPR_32(31):
if (!kvm_mips_guest_has_fpu(&vcpu->arch))
return -EINVAL;
idx = reg->id - KVM_REG_MIPS_FPR_32(0);
if (kvm_read_c0_guest_status(cop0) & ST0_FR)
v = get_fpr32(&fpu->fpr[idx], 0);
else
v = get_fpr32(&fpu->fpr[idx & ~1], idx & 1);
break;
case KVM_REG_MIPS_FPR_64(0) ... KVM_REG_MIPS_FPR_64(31):
if (!kvm_mips_guest_has_fpu(&vcpu->arch))
return -EINVAL;
idx = reg->id - KVM_REG_MIPS_FPR_64(0);
if (idx & 1 && !(kvm_read_c0_guest_status(cop0) & ST0_FR))
return -EINVAL;
v = get_fpr64(&fpu->fpr[idx], 0);
break;
case KVM_REG_MIPS_FCR_IR:
if (!kvm_mips_guest_has_fpu(&vcpu->arch))
return -EINVAL;
v = boot_cpu_data.fpu_id;
break;
case KVM_REG_MIPS_FCR_CSR:
if (!kvm_mips_guest_has_fpu(&vcpu->arch))
return -EINVAL;
v = fpu->fcr31;
break;
case KVM_REG_MIPS_VEC_128(0) ... KVM_REG_MIPS_VEC_128(31):
if (!kvm_mips_guest_has_msa(&vcpu->arch))
return -EINVAL;
if (!(kvm_read_c0_guest_status(cop0) & ST0_FR))
return -EINVAL;
idx = reg->id - KVM_REG_MIPS_VEC_128(0);
#ifdef CONFIG_CPU_LITTLE_ENDIAN
vs[0] = get_fpr64(&fpu->fpr[idx], 0);
vs[1] = get_fpr64(&fpu->fpr[idx], 1);
#else
vs[0] = get_fpr64(&fpu->fpr[idx], 1);
vs[1] = get_fpr64(&fpu->fpr[idx], 0);
#endif
break;
case KVM_REG_MIPS_MSA_IR:
if (!kvm_mips_guest_has_msa(&vcpu->arch))
return -EINVAL;
v = boot_cpu_data.msa_id;
break;
case KVM_REG_MIPS_MSA_CSR:
if (!kvm_mips_guest_has_msa(&vcpu->arch))
return -EINVAL;
v = fpu->msacsr;
break;
case KVM_REG_MIPS_CP0_INDEX:
v = (long)kvm_read_c0_guest_index(cop0);
break;
case KVM_REG_MIPS_CP0_CONTEXT:
v = (long)kvm_read_c0_guest_context(cop0);
break;
case KVM_REG_MIPS_CP0_USERLOCAL:
v = (long)kvm_read_c0_guest_userlocal(cop0);
break;
case KVM_REG_MIPS_CP0_PAGEMASK:
v = (long)kvm_read_c0_guest_pagemask(cop0);
break;
case KVM_REG_MIPS_CP0_WIRED:
v = (long)kvm_read_c0_guest_wired(cop0);
break;
case KVM_REG_MIPS_CP0_HWRENA:
v = (long)kvm_read_c0_guest_hwrena(cop0);
break;
case KVM_REG_MIPS_CP0_BADVADDR:
v = (long)kvm_read_c0_guest_badvaddr(cop0);
break;
case KVM_REG_MIPS_CP0_ENTRYHI:
v = (long)kvm_read_c0_guest_entryhi(cop0);
break;
case KVM_REG_MIPS_CP0_COMPARE:
v = (long)kvm_read_c0_guest_compare(cop0);
break;
case KVM_REG_MIPS_CP0_STATUS:
v = (long)kvm_read_c0_guest_status(cop0);
break;
case KVM_REG_MIPS_CP0_CAUSE:
v = (long)kvm_read_c0_guest_cause(cop0);
break;
case KVM_REG_MIPS_CP0_EPC:
v = (long)kvm_read_c0_guest_epc(cop0);
break;
case KVM_REG_MIPS_CP0_PRID:
v = (long)kvm_read_c0_guest_prid(cop0);
break;
case KVM_REG_MIPS_CP0_CONFIG:
v = (long)kvm_read_c0_guest_config(cop0);
break;
case KVM_REG_MIPS_CP0_CONFIG1:
v = (long)kvm_read_c0_guest_config1(cop0);
break;
case KVM_REG_MIPS_CP0_CONFIG2:
v = (long)kvm_read_c0_guest_config2(cop0);
break;
case KVM_REG_MIPS_CP0_CONFIG3:
v = (long)kvm_read_c0_guest_config3(cop0);
break;
case KVM_REG_MIPS_CP0_CONFIG4:
v = (long)kvm_read_c0_guest_config4(cop0);
break;
case KVM_REG_MIPS_CP0_CONFIG5:
v = (long)kvm_read_c0_guest_config5(cop0);
break;
case KVM_REG_MIPS_CP0_CONFIG7:
v = (long)kvm_read_c0_guest_config7(cop0);
break;
case KVM_REG_MIPS_CP0_ERROREPC:
v = (long)kvm_read_c0_guest_errorepc(cop0);
break;
case KVM_REG_MIPS_CP0_KSCRATCH1 ... KVM_REG_MIPS_CP0_KSCRATCH6:
idx = reg->id - KVM_REG_MIPS_CP0_KSCRATCH1 + 2;
if (!(vcpu->arch.kscratch_enabled & BIT(idx)))
return -EINVAL;
switch (idx) {
case 2:
v = (long)kvm_read_c0_guest_kscratch1(cop0);
break;
case 3:
v = (long)kvm_read_c0_guest_kscratch2(cop0);
break;
case 4:
v = (long)kvm_read_c0_guest_kscratch3(cop0);
break;
case 5:
v = (long)kvm_read_c0_guest_kscratch4(cop0);
break;
case 6:
v = (long)kvm_read_c0_guest_kscratch5(cop0);
break;
case 7:
v = (long)kvm_read_c0_guest_kscratch6(cop0);
break;
}
break;
default:
ret = kvm_mips_callbacks->get_one_reg(vcpu, reg, &v);
if (ret)
return ret;
break;
}
if ((reg->id & KVM_REG_SIZE_MASK) == KVM_REG_SIZE_U64) {
u64 __user *uaddr64 = (u64 __user *)(long)reg->addr;
return put_user(v, uaddr64);
} else if ((reg->id & KVM_REG_SIZE_MASK) == KVM_REG_SIZE_U32) {
u32 __user *uaddr32 = (u32 __user *)(long)reg->addr;
u32 v32 = (u32)v;
return put_user(v32, uaddr32);
} else if ((reg->id & KVM_REG_SIZE_MASK) == KVM_REG_SIZE_U128) {
void __user *uaddr = (void __user *)(long)reg->addr;
return copy_to_user(uaddr, vs, 16) ? -EFAULT : 0;
} else {
return -EINVAL;
}
}
static int kvm_mips_set_reg(struct kvm_vcpu *vcpu,
const struct kvm_one_reg *reg)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
struct mips_fpu_struct *fpu = &vcpu->arch.fpu;
s64 v;
s64 vs[2];
unsigned int idx;
if ((reg->id & KVM_REG_SIZE_MASK) == KVM_REG_SIZE_U64) {
u64 __user *uaddr64 = (u64 __user *)(long)reg->addr;
if (get_user(v, uaddr64) != 0)
return -EFAULT;
} else if ((reg->id & KVM_REG_SIZE_MASK) == KVM_REG_SIZE_U32) {
u32 __user *uaddr32 = (u32 __user *)(long)reg->addr;
s32 v32;
if (get_user(v32, uaddr32) != 0)
return -EFAULT;
v = (s64)v32;
} else if ((reg->id & KVM_REG_SIZE_MASK) == KVM_REG_SIZE_U128) {
void __user *uaddr = (void __user *)(long)reg->addr;
return copy_from_user(vs, uaddr, 16) ? -EFAULT : 0;
} else {
return -EINVAL;
}
switch (reg->id) {
case KVM_REG_MIPS_R0:
break;
case KVM_REG_MIPS_R1 ... KVM_REG_MIPS_R31:
vcpu->arch.gprs[reg->id - KVM_REG_MIPS_R0] = v;
break;
#ifndef CONFIG_CPU_MIPSR6
case KVM_REG_MIPS_HI:
vcpu->arch.hi = v;
break;
case KVM_REG_MIPS_LO:
vcpu->arch.lo = v;
break;
#endif
case KVM_REG_MIPS_PC:
vcpu->arch.pc = v;
break;
case KVM_REG_MIPS_FPR_32(0) ... KVM_REG_MIPS_FPR_32(31):
if (!kvm_mips_guest_has_fpu(&vcpu->arch))
return -EINVAL;
idx = reg->id - KVM_REG_MIPS_FPR_32(0);
if (kvm_read_c0_guest_status(cop0) & ST0_FR)
set_fpr32(&fpu->fpr[idx], 0, v);
else
set_fpr32(&fpu->fpr[idx & ~1], idx & 1, v);
break;
case KVM_REG_MIPS_FPR_64(0) ... KVM_REG_MIPS_FPR_64(31):
if (!kvm_mips_guest_has_fpu(&vcpu->arch))
return -EINVAL;
idx = reg->id - KVM_REG_MIPS_FPR_64(0);
if (idx & 1 && !(kvm_read_c0_guest_status(cop0) & ST0_FR))
return -EINVAL;
set_fpr64(&fpu->fpr[idx], 0, v);
break;
case KVM_REG_MIPS_FCR_IR:
if (!kvm_mips_guest_has_fpu(&vcpu->arch))
return -EINVAL;
break;
case KVM_REG_MIPS_FCR_CSR:
if (!kvm_mips_guest_has_fpu(&vcpu->arch))
return -EINVAL;
fpu->fcr31 = v;
break;
case KVM_REG_MIPS_VEC_128(0) ... KVM_REG_MIPS_VEC_128(31):
if (!kvm_mips_guest_has_msa(&vcpu->arch))
return -EINVAL;
idx = reg->id - KVM_REG_MIPS_VEC_128(0);
#ifdef CONFIG_CPU_LITTLE_ENDIAN
set_fpr64(&fpu->fpr[idx], 0, vs[0]);
set_fpr64(&fpu->fpr[idx], 1, vs[1]);
#else
set_fpr64(&fpu->fpr[idx], 1, vs[0]);
set_fpr64(&fpu->fpr[idx], 0, vs[1]);
#endif
break;
case KVM_REG_MIPS_MSA_IR:
if (!kvm_mips_guest_has_msa(&vcpu->arch))
return -EINVAL;
break;
case KVM_REG_MIPS_MSA_CSR:
if (!kvm_mips_guest_has_msa(&vcpu->arch))
return -EINVAL;
fpu->msacsr = v;
break;
case KVM_REG_MIPS_CP0_INDEX:
kvm_write_c0_guest_index(cop0, v);
break;
case KVM_REG_MIPS_CP0_CONTEXT:
kvm_write_c0_guest_context(cop0, v);
break;
case KVM_REG_MIPS_CP0_USERLOCAL:
kvm_write_c0_guest_userlocal(cop0, v);
break;
case KVM_REG_MIPS_CP0_PAGEMASK:
kvm_write_c0_guest_pagemask(cop0, v);
break;
case KVM_REG_MIPS_CP0_WIRED:
kvm_write_c0_guest_wired(cop0, v);
break;
case KVM_REG_MIPS_CP0_HWRENA:
kvm_write_c0_guest_hwrena(cop0, v);
break;
case KVM_REG_MIPS_CP0_BADVADDR:
kvm_write_c0_guest_badvaddr(cop0, v);
break;
case KVM_REG_MIPS_CP0_ENTRYHI:
kvm_write_c0_guest_entryhi(cop0, v);
break;
case KVM_REG_MIPS_CP0_STATUS:
kvm_write_c0_guest_status(cop0, v);
break;
case KVM_REG_MIPS_CP0_EPC:
kvm_write_c0_guest_epc(cop0, v);
break;
case KVM_REG_MIPS_CP0_PRID:
kvm_write_c0_guest_prid(cop0, v);
break;
case KVM_REG_MIPS_CP0_ERROREPC:
kvm_write_c0_guest_errorepc(cop0, v);
break;
case KVM_REG_MIPS_CP0_KSCRATCH1 ... KVM_REG_MIPS_CP0_KSCRATCH6:
idx = reg->id - KVM_REG_MIPS_CP0_KSCRATCH1 + 2;
if (!(vcpu->arch.kscratch_enabled & BIT(idx)))
return -EINVAL;
switch (idx) {
case 2:
kvm_write_c0_guest_kscratch1(cop0, v);
break;
case 3:
kvm_write_c0_guest_kscratch2(cop0, v);
break;
case 4:
kvm_write_c0_guest_kscratch3(cop0, v);
break;
case 5:
kvm_write_c0_guest_kscratch4(cop0, v);
break;
case 6:
kvm_write_c0_guest_kscratch5(cop0, v);
break;
case 7:
kvm_write_c0_guest_kscratch6(cop0, v);
break;
}
break;
default:
return kvm_mips_callbacks->set_one_reg(vcpu, reg, v);
}
return 0;
}
static int kvm_vcpu_ioctl_enable_cap(struct kvm_vcpu *vcpu,
struct kvm_enable_cap *cap)
{
int r = 0;
if (!kvm_vm_ioctl_check_extension(vcpu->kvm, cap->cap))
return -EINVAL;
if (cap->flags)
return -EINVAL;
if (cap->args[0])
return -EINVAL;
switch (cap->cap) {
case KVM_CAP_MIPS_FPU:
vcpu->arch.fpu_enabled = true;
break;
case KVM_CAP_MIPS_MSA:
vcpu->arch.msa_enabled = true;
break;
default:
r = -EINVAL;
break;
}
return r;
}
long kvm_arch_vcpu_ioctl(struct file *filp, unsigned int ioctl,
unsigned long arg)
{
struct kvm_vcpu *vcpu = filp->private_data;
void __user *argp = (void __user *)arg;
long r;
switch (ioctl) {
case KVM_SET_ONE_REG:
case KVM_GET_ONE_REG: {
struct kvm_one_reg reg;
if (copy_from_user(&reg, argp, sizeof(reg)))
return -EFAULT;
if (ioctl == KVM_SET_ONE_REG)
return kvm_mips_set_reg(vcpu, &reg);
else
return kvm_mips_get_reg(vcpu, &reg);
}
case KVM_GET_REG_LIST: {
struct kvm_reg_list __user *user_list = argp;
struct kvm_reg_list reg_list;
unsigned n;
if (copy_from_user(&reg_list, user_list, sizeof(reg_list)))
return -EFAULT;
n = reg_list.n;
reg_list.n = kvm_mips_num_regs(vcpu);
if (copy_to_user(user_list, &reg_list, sizeof(reg_list)))
return -EFAULT;
if (n < reg_list.n)
return -E2BIG;
return kvm_mips_copy_reg_indices(vcpu, user_list->reg);
}
case KVM_NMI:
r = kvm_mips_reset_vcpu(vcpu);
break;
case KVM_INTERRUPT:
{
struct kvm_mips_interrupt irq;
r = -EFAULT;
if (copy_from_user(&irq, argp, sizeof(irq)))
goto out;
kvm_debug("[%d] %s: irq: %d\n", vcpu->vcpu_id, __func__,
irq.irq);
r = kvm_vcpu_ioctl_interrupt(vcpu, &irq);
break;
}
case KVM_ENABLE_CAP: {
struct kvm_enable_cap cap;
r = -EFAULT;
if (copy_from_user(&cap, argp, sizeof(cap)))
goto out;
r = kvm_vcpu_ioctl_enable_cap(vcpu, &cap);
break;
}
default:
r = -ENOIOCTLCMD;
}
out:
return r;
}
int kvm_vm_ioctl_get_dirty_log(struct kvm *kvm, struct kvm_dirty_log *log)
{
struct kvm_memslots *slots;
struct kvm_memory_slot *memslot;
unsigned long ga, ga_end;
int is_dirty = 0;
int r;
unsigned long n;
mutex_lock(&kvm->slots_lock);
r = kvm_get_dirty_log(kvm, log, &is_dirty);
if (r)
goto out;
if (is_dirty) {
slots = kvm_memslots(kvm);
memslot = id_to_memslot(slots, log->slot);
ga = memslot->base_gfn << PAGE_SHIFT;
ga_end = ga + (memslot->npages << PAGE_SHIFT);
kvm_info("%s: dirty, ga: %#lx, ga_end %#lx\n", __func__, ga,
ga_end);
n = kvm_dirty_bitmap_bytes(memslot);
memset(memslot->dirty_bitmap, 0, n);
}
r = 0;
out:
mutex_unlock(&kvm->slots_lock);
return r;
}
long kvm_arch_vm_ioctl(struct file *filp, unsigned int ioctl, unsigned long arg)
{
long r;
switch (ioctl) {
default:
r = -ENOIOCTLCMD;
}
return r;
}
int kvm_arch_init(void *opaque)
{
if (kvm_mips_callbacks) {
kvm_err("kvm: module already exists\n");
return -EEXIST;
}
return kvm_mips_emulation_init(&kvm_mips_callbacks);
}
void kvm_arch_exit(void)
{
kvm_mips_callbacks = NULL;
}
int kvm_arch_vcpu_ioctl_get_sregs(struct kvm_vcpu *vcpu,
struct kvm_sregs *sregs)
{
return -ENOIOCTLCMD;
}
int kvm_arch_vcpu_ioctl_set_sregs(struct kvm_vcpu *vcpu,
struct kvm_sregs *sregs)
{
return -ENOIOCTLCMD;
}
void kvm_arch_vcpu_postcreate(struct kvm_vcpu *vcpu)
{
}
int kvm_arch_vcpu_ioctl_get_fpu(struct kvm_vcpu *vcpu, struct kvm_fpu *fpu)
{
return -ENOIOCTLCMD;
}
int kvm_arch_vcpu_ioctl_set_fpu(struct kvm_vcpu *vcpu, struct kvm_fpu *fpu)
{
return -ENOIOCTLCMD;
}
int kvm_arch_vcpu_fault(struct kvm_vcpu *vcpu, struct vm_fault *vmf)
{
return VM_FAULT_SIGBUS;
}
int kvm_vm_ioctl_check_extension(struct kvm *kvm, long ext)
{
int r;
switch (ext) {
case KVM_CAP_ONE_REG:
case KVM_CAP_ENABLE_CAP:
r = 1;
break;
case KVM_CAP_COALESCED_MMIO:
r = KVM_COALESCED_MMIO_PAGE_OFFSET;
break;
case KVM_CAP_MIPS_FPU:
r = !!raw_cpu_has_fpu;
break;
case KVM_CAP_MIPS_MSA:
r = cpu_has_msa && !(boot_cpu_data.msa_id & MSA_IR_WRPF);
break;
default:
r = 0;
break;
}
return r;
}
int kvm_cpu_has_pending_timer(struct kvm_vcpu *vcpu)
{
return kvm_mips_pending_timer(vcpu);
}
int kvm_arch_vcpu_dump_regs(struct kvm_vcpu *vcpu)
{
int i;
struct mips_coproc *cop0;
if (!vcpu)
return -1;
kvm_debug("VCPU Register Dump:\n");
kvm_debug("\tpc = 0x%08lx\n", vcpu->arch.pc);
kvm_debug("\texceptions: %08lx\n", vcpu->arch.pending_exceptions);
for (i = 0; i < 32; i += 4) {
kvm_debug("\tgpr%02d: %08lx %08lx %08lx %08lx\n", i,
vcpu->arch.gprs[i],
vcpu->arch.gprs[i + 1],
vcpu->arch.gprs[i + 2], vcpu->arch.gprs[i + 3]);
}
kvm_debug("\thi: 0x%08lx\n", vcpu->arch.hi);
kvm_debug("\tlo: 0x%08lx\n", vcpu->arch.lo);
cop0 = vcpu->arch.cop0;
kvm_debug("\tStatus: 0x%08lx, Cause: 0x%08lx\n",
kvm_read_c0_guest_status(cop0),
kvm_read_c0_guest_cause(cop0));
kvm_debug("\tEPC: 0x%08lx\n", kvm_read_c0_guest_epc(cop0));
return 0;
}
int kvm_arch_vcpu_ioctl_set_regs(struct kvm_vcpu *vcpu, struct kvm_regs *regs)
{
int i;
for (i = 1; i < ARRAY_SIZE(vcpu->arch.gprs); i++)
vcpu->arch.gprs[i] = regs->gpr[i];
vcpu->arch.gprs[0] = 0;
vcpu->arch.hi = regs->hi;
vcpu->arch.lo = regs->lo;
vcpu->arch.pc = regs->pc;
return 0;
}
int kvm_arch_vcpu_ioctl_get_regs(struct kvm_vcpu *vcpu, struct kvm_regs *regs)
{
int i;
for (i = 0; i < ARRAY_SIZE(vcpu->arch.gprs); i++)
regs->gpr[i] = vcpu->arch.gprs[i];
regs->hi = vcpu->arch.hi;
regs->lo = vcpu->arch.lo;
regs->pc = vcpu->arch.pc;
return 0;
}
static void kvm_mips_comparecount_func(unsigned long data)
{
struct kvm_vcpu *vcpu = (struct kvm_vcpu *)data;
kvm_mips_callbacks->queue_timer_int(vcpu);
vcpu->arch.wait = 0;
if (swait_active(&vcpu->wq))
swake_up(&vcpu->wq);
}
static enum hrtimer_restart kvm_mips_comparecount_wakeup(struct hrtimer *timer)
{
struct kvm_vcpu *vcpu;
vcpu = container_of(timer, struct kvm_vcpu, arch.comparecount_timer);
kvm_mips_comparecount_func((unsigned long) vcpu);
return kvm_mips_count_timeout(vcpu);
}
int kvm_arch_vcpu_init(struct kvm_vcpu *vcpu)
{
kvm_mips_callbacks->vcpu_init(vcpu);
hrtimer_init(&vcpu->arch.comparecount_timer, CLOCK_MONOTONIC,
HRTIMER_MODE_REL);
vcpu->arch.comparecount_timer.function = kvm_mips_comparecount_wakeup;
return 0;
}
int kvm_arch_vcpu_ioctl_translate(struct kvm_vcpu *vcpu,
struct kvm_translation *tr)
{
return 0;
}
int kvm_arch_vcpu_setup(struct kvm_vcpu *vcpu)
{
return kvm_mips_callbacks->vcpu_setup(vcpu);
}
static void kvm_mips_set_c0_status(void)
{
u32 status = read_c0_status();
if (cpu_has_dsp)
status |= (ST0_MX);
write_c0_status(status);
ehb();
}
int kvm_mips_handle_exit(struct kvm_run *run, struct kvm_vcpu *vcpu)
{
u32 cause = vcpu->arch.host_cp0_cause;
u32 exccode = (cause >> CAUSEB_EXCCODE) & 0x1f;
u32 __user *opc = (u32 __user *) vcpu->arch.pc;
unsigned long badvaddr = vcpu->arch.host_cp0_badvaddr;
enum emulation_result er = EMULATE_DONE;
int ret = RESUME_GUEST;
htw_start();
run->exit_reason = KVM_EXIT_UNKNOWN;
run->ready_for_interrupt_injection = 1;
kvm_mips_set_c0_status();
local_irq_enable();
kvm_debug("kvm_mips_handle_exit: cause: %#x, PC: %p, kvm_run: %p, kvm_vcpu: %p\n",
cause, opc, run, vcpu);
trace_kvm_exit(vcpu, exccode);
er = kvm_mips_check_privilege(cause, opc, run, vcpu);
if (er == EMULATE_PRIV_FAIL) {
goto skip_emul;
} else if (er == EMULATE_FAIL) {
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
goto skip_emul;
}
switch (exccode) {
case EXCCODE_INT:
kvm_debug("[%d]EXCCODE_INT @ %p\n", vcpu->vcpu_id, opc);
++vcpu->stat.int_exits;
if (need_resched())
cond_resched();
ret = RESUME_GUEST;
break;
case EXCCODE_CPU:
kvm_debug("EXCCODE_CPU: @ PC: %p\n", opc);
++vcpu->stat.cop_unusable_exits;
ret = kvm_mips_callbacks->handle_cop_unusable(vcpu);
if (run->exit_reason == KVM_EXIT_IRQ_WINDOW_OPEN)
ret = RESUME_HOST;
break;
case EXCCODE_MOD:
++vcpu->stat.tlbmod_exits;
ret = kvm_mips_callbacks->handle_tlb_mod(vcpu);
break;
case EXCCODE_TLBS:
kvm_debug("TLB ST fault: cause %#x, status %#lx, PC: %p, BadVaddr: %#lx\n",
cause, kvm_read_c0_guest_status(vcpu->arch.cop0), opc,
badvaddr);
++vcpu->stat.tlbmiss_st_exits;
ret = kvm_mips_callbacks->handle_tlb_st_miss(vcpu);
break;
case EXCCODE_TLBL:
kvm_debug("TLB LD fault: cause %#x, PC: %p, BadVaddr: %#lx\n",
cause, opc, badvaddr);
++vcpu->stat.tlbmiss_ld_exits;
ret = kvm_mips_callbacks->handle_tlb_ld_miss(vcpu);
break;
case EXCCODE_ADES:
++vcpu->stat.addrerr_st_exits;
ret = kvm_mips_callbacks->handle_addr_err_st(vcpu);
break;
case EXCCODE_ADEL:
++vcpu->stat.addrerr_ld_exits;
ret = kvm_mips_callbacks->handle_addr_err_ld(vcpu);
break;
case EXCCODE_SYS:
++vcpu->stat.syscall_exits;
ret = kvm_mips_callbacks->handle_syscall(vcpu);
break;
case EXCCODE_RI:
++vcpu->stat.resvd_inst_exits;
ret = kvm_mips_callbacks->handle_res_inst(vcpu);
break;
case EXCCODE_BP:
++vcpu->stat.break_inst_exits;
ret = kvm_mips_callbacks->handle_break(vcpu);
break;
case EXCCODE_TR:
++vcpu->stat.trap_inst_exits;
ret = kvm_mips_callbacks->handle_trap(vcpu);
break;
case EXCCODE_MSAFPE:
++vcpu->stat.msa_fpe_exits;
ret = kvm_mips_callbacks->handle_msa_fpe(vcpu);
break;
case EXCCODE_FPE:
++vcpu->stat.fpe_exits;
ret = kvm_mips_callbacks->handle_fpe(vcpu);
break;
case EXCCODE_MSADIS:
++vcpu->stat.msa_disabled_exits;
ret = kvm_mips_callbacks->handle_msa_disabled(vcpu);
break;
default:
kvm_err("Exception Code: %d, not yet handled, @ PC: %p, inst: 0x%08x BadVaddr: %#lx Status: %#lx\n",
exccode, opc, kvm_get_inst(opc, vcpu), badvaddr,
kvm_read_c0_guest_status(vcpu->arch.cop0));
kvm_arch_vcpu_dump_regs(vcpu);
run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
ret = RESUME_HOST;
break;
}
skip_emul:
local_irq_disable();
if (er == EMULATE_DONE && !(ret & RESUME_HOST))
kvm_mips_deliver_interrupts(vcpu, cause);
if (!(ret & RESUME_HOST)) {
if (signal_pending(current)) {
run->exit_reason = KVM_EXIT_INTR;
ret = (-EINTR << 2) | RESUME_HOST;
++vcpu->stat.signal_exits;
trace_kvm_exit(vcpu, KVM_TRACE_EXIT_SIGNAL);
}
}
if (ret == RESUME_GUEST) {
trace_kvm_reenter(vcpu);
kvm_mips_check_asids(vcpu);
if (kvm_mips_guest_has_fpu(&vcpu->arch) &&
read_c0_status() & ST0_CU1)
__kvm_restore_fcsr(&vcpu->arch);
if (kvm_mips_guest_has_msa(&vcpu->arch) &&
read_c0_config5() & MIPS_CONF5_MSAEN)
__kvm_restore_msacsr(&vcpu->arch);
}
htw_stop();
return ret;
}
void kvm_own_fpu(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
unsigned int sr, cfg5;
preempt_disable();
sr = kvm_read_c0_guest_status(cop0);
if (cpu_has_msa && sr & ST0_CU1 && !(sr & ST0_FR) &&
vcpu->arch.aux_inuse & KVM_MIPS_AUX_MSA)
kvm_lose_fpu(vcpu);
change_c0_status(ST0_CU1 | ST0_FR, sr);
if (cpu_has_fre) {
cfg5 = kvm_read_c0_guest_config5(cop0);
change_c0_config5(MIPS_CONF5_FRE, cfg5);
}
enable_fpu_hazard();
if (!(vcpu->arch.aux_inuse & KVM_MIPS_AUX_FPU)) {
__kvm_restore_fpu(&vcpu->arch);
vcpu->arch.aux_inuse |= KVM_MIPS_AUX_FPU;
trace_kvm_aux(vcpu, KVM_TRACE_AUX_RESTORE, KVM_TRACE_AUX_FPU);
} else {
trace_kvm_aux(vcpu, KVM_TRACE_AUX_ENABLE, KVM_TRACE_AUX_FPU);
}
preempt_enable();
}
void kvm_own_msa(struct kvm_vcpu *vcpu)
{
struct mips_coproc *cop0 = vcpu->arch.cop0;
unsigned int sr, cfg5;
preempt_disable();
if (kvm_mips_guest_has_fpu(&vcpu->arch)) {
sr = kvm_read_c0_guest_status(cop0);
if (!(sr & ST0_FR) &&
(vcpu->arch.aux_inuse & (KVM_MIPS_AUX_FPU |
KVM_MIPS_AUX_MSA)) == KVM_MIPS_AUX_FPU)
kvm_lose_fpu(vcpu);
change_c0_status(ST0_CU1 | ST0_FR, sr);
if (sr & ST0_CU1 && cpu_has_fre) {
cfg5 = kvm_read_c0_guest_config5(cop0);
change_c0_config5(MIPS_CONF5_FRE, cfg5);
}
}
set_c0_config5(MIPS_CONF5_MSAEN);
enable_fpu_hazard();
switch (vcpu->arch.aux_inuse & (KVM_MIPS_AUX_FPU | KVM_MIPS_AUX_MSA)) {
case KVM_MIPS_AUX_FPU:
__kvm_restore_msa_upper(&vcpu->arch);
vcpu->arch.aux_inuse |= KVM_MIPS_AUX_MSA;
trace_kvm_aux(vcpu, KVM_TRACE_AUX_RESTORE, KVM_TRACE_AUX_MSA);
break;
case 0:
__kvm_restore_msa(&vcpu->arch);
vcpu->arch.aux_inuse |= KVM_MIPS_AUX_MSA;
if (kvm_mips_guest_has_fpu(&vcpu->arch))
vcpu->arch.aux_inuse |= KVM_MIPS_AUX_FPU;
trace_kvm_aux(vcpu, KVM_TRACE_AUX_RESTORE,
KVM_TRACE_AUX_FPU_MSA);
break;
default:
trace_kvm_aux(vcpu, KVM_TRACE_AUX_ENABLE, KVM_TRACE_AUX_MSA);
break;
}
preempt_enable();
}
void kvm_drop_fpu(struct kvm_vcpu *vcpu)
{
preempt_disable();
if (cpu_has_msa && vcpu->arch.aux_inuse & KVM_MIPS_AUX_MSA) {
disable_msa();
trace_kvm_aux(vcpu, KVM_TRACE_AUX_DISCARD, KVM_TRACE_AUX_MSA);
vcpu->arch.aux_inuse &= ~KVM_MIPS_AUX_MSA;
}
if (vcpu->arch.aux_inuse & KVM_MIPS_AUX_FPU) {
clear_c0_status(ST0_CU1 | ST0_FR);
trace_kvm_aux(vcpu, KVM_TRACE_AUX_DISCARD, KVM_TRACE_AUX_FPU);
vcpu->arch.aux_inuse &= ~KVM_MIPS_AUX_FPU;
}
preempt_enable();
}
void kvm_lose_fpu(struct kvm_vcpu *vcpu)
{
preempt_disable();
if (cpu_has_msa && vcpu->arch.aux_inuse & KVM_MIPS_AUX_MSA) {
set_c0_config5(MIPS_CONF5_MSAEN);
enable_fpu_hazard();
__kvm_save_msa(&vcpu->arch);
trace_kvm_aux(vcpu, KVM_TRACE_AUX_SAVE, KVM_TRACE_AUX_FPU_MSA);
disable_msa();
if (vcpu->arch.aux_inuse & KVM_MIPS_AUX_FPU) {
clear_c0_status(ST0_CU1 | ST0_FR);
disable_fpu_hazard();
}
vcpu->arch.aux_inuse &= ~(KVM_MIPS_AUX_FPU | KVM_MIPS_AUX_MSA);
} else if (vcpu->arch.aux_inuse & KVM_MIPS_AUX_FPU) {
set_c0_status(ST0_CU1);
enable_fpu_hazard();
__kvm_save_fpu(&vcpu->arch);
vcpu->arch.aux_inuse &= ~KVM_MIPS_AUX_FPU;
trace_kvm_aux(vcpu, KVM_TRACE_AUX_SAVE, KVM_TRACE_AUX_FPU);
clear_c0_status(ST0_CU1 | ST0_FR);
disable_fpu_hazard();
}
preempt_enable();
}
static int kvm_mips_csr_die_notify(struct notifier_block *self,
unsigned long cmd, void *ptr)
{
struct die_args *args = (struct die_args *)ptr;
struct pt_regs *regs = args->regs;
unsigned long pc;
if (cmd != DIE_FP && cmd != DIE_MSAFP)
return NOTIFY_DONE;
if (!(current->flags & PF_VCPU))
return NOTIFY_DONE;
BUG_ON(user_mode(regs));
pc = instruction_pointer(regs);
switch (cmd) {
case DIE_FP:
if (pc != (unsigned long)&__kvm_restore_fcsr + 4)
return NOTIFY_DONE;
break;
case DIE_MSAFP:
if (!cpu_has_msa ||
pc < (unsigned long)&__kvm_restore_msacsr + 4 ||
pc > (unsigned long)&__kvm_restore_msacsr + 8)
return NOTIFY_DONE;
break;
}
instruction_pointer(regs) += 4;
return NOTIFY_STOP;
}
static int __init kvm_mips_init(void)
{
int ret;
ret = kvm_mips_entry_setup();
if (ret)
return ret;
ret = kvm_init(NULL, sizeof(struct kvm_vcpu), 0, THIS_MODULE);
if (ret)
return ret;
register_die_notifier(&kvm_mips_csr_die_notifier);
return 0;
}
static void __exit kvm_mips_exit(void)
{
kvm_exit();
unregister_die_notifier(&kvm_mips_csr_die_notifier);
}
