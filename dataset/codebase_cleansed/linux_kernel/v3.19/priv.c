static int handle_set_clock(struct kvm_vcpu *vcpu)
{
struct kvm_vcpu *cpup;
s64 hostclk, val;
int i, rc;
u64 op2;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
op2 = kvm_s390_get_base_disp_s(vcpu);
if (op2 & 7)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
rc = read_guest(vcpu, op2, &val, sizeof(val));
if (rc)
return kvm_s390_inject_prog_cond(vcpu, rc);
if (store_tod_clock(&hostclk)) {
kvm_s390_set_psw_cc(vcpu, 3);
return 0;
}
val = (val - hostclk) & ~0x3fUL;
mutex_lock(&vcpu->kvm->lock);
kvm_for_each_vcpu(i, cpup, vcpu->kvm)
cpup->arch.sie_block->epoch = val;
mutex_unlock(&vcpu->kvm->lock);
kvm_s390_set_psw_cc(vcpu, 0);
return 0;
}
static int handle_set_prefix(struct kvm_vcpu *vcpu)
{
u64 operand2;
u32 address;
int rc;
vcpu->stat.instruction_spx++;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
operand2 = kvm_s390_get_base_disp_s(vcpu);
if (operand2 & 3)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
rc = read_guest(vcpu, operand2, &address, sizeof(address));
if (rc)
return kvm_s390_inject_prog_cond(vcpu, rc);
address &= 0x7fffe000u;
if (kvm_is_error_gpa(vcpu->kvm, address))
return kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
kvm_s390_set_prefix(vcpu, address);
VCPU_EVENT(vcpu, 5, "setting prefix to %x", address);
trace_kvm_s390_handle_prefix(vcpu, 1, address);
return 0;
}
static int handle_store_prefix(struct kvm_vcpu *vcpu)
{
u64 operand2;
u32 address;
int rc;
vcpu->stat.instruction_stpx++;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
operand2 = kvm_s390_get_base_disp_s(vcpu);
if (operand2 & 3)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
address = kvm_s390_get_prefix(vcpu);
rc = write_guest(vcpu, operand2, &address, sizeof(address));
if (rc)
return kvm_s390_inject_prog_cond(vcpu, rc);
VCPU_EVENT(vcpu, 5, "storing prefix to %x", address);
trace_kvm_s390_handle_prefix(vcpu, 0, address);
return 0;
}
static int handle_store_cpu_address(struct kvm_vcpu *vcpu)
{
u16 vcpu_id = vcpu->vcpu_id;
u64 ga;
int rc;
vcpu->stat.instruction_stap++;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
ga = kvm_s390_get_base_disp_s(vcpu);
if (ga & 1)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
rc = write_guest(vcpu, ga, &vcpu_id, sizeof(vcpu_id));
if (rc)
return kvm_s390_inject_prog_cond(vcpu, rc);
VCPU_EVENT(vcpu, 5, "storing cpu address to %llx", ga);
trace_kvm_s390_handle_stap(vcpu, ga);
return 0;
}
static int __skey_check_enable(struct kvm_vcpu *vcpu)
{
int rc = 0;
if (!(vcpu->arch.sie_block->ictl & (ICTL_ISKE | ICTL_SSKE | ICTL_RRBE)))
return rc;
rc = s390_enable_skey();
trace_kvm_s390_skey_related_inst(vcpu);
vcpu->arch.sie_block->ictl &= ~(ICTL_ISKE | ICTL_SSKE | ICTL_RRBE);
return rc;
}
static int handle_skey(struct kvm_vcpu *vcpu)
{
int rc = __skey_check_enable(vcpu);
if (rc)
return rc;
vcpu->stat.instruction_storage_key++;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
kvm_s390_rewind_psw(vcpu, 4);
VCPU_EVENT(vcpu, 4, "%s", "retrying storage key operation");
return 0;
}
static int handle_ipte_interlock(struct kvm_vcpu *vcpu)
{
vcpu->stat.instruction_ipte_interlock++;
if (psw_bits(vcpu->arch.sie_block->gpsw).p)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
wait_event(vcpu->kvm->arch.ipte_wq, !ipte_lock_held(vcpu));
kvm_s390_rewind_psw(vcpu, 4);
VCPU_EVENT(vcpu, 4, "%s", "retrying ipte interlock operation");
return 0;
}
static int handle_test_block(struct kvm_vcpu *vcpu)
{
gpa_t addr;
int reg2;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
kvm_s390_get_regs_rre(vcpu, NULL, &reg2);
addr = vcpu->run->s.regs.gprs[reg2] & PAGE_MASK;
addr = kvm_s390_logical_to_effective(vcpu, addr);
if (kvm_s390_check_low_addr_protection(vcpu, addr))
return kvm_s390_inject_prog_irq(vcpu, &vcpu->arch.pgm);
addr = kvm_s390_real_to_abs(vcpu, addr);
if (kvm_is_error_gpa(vcpu->kvm, addr))
return kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
if (kvm_clear_guest(vcpu->kvm, addr, PAGE_SIZE))
return -EFAULT;
kvm_s390_set_psw_cc(vcpu, 0);
vcpu->run->s.regs.gprs[0] = 0;
return 0;
}
static int handle_tpi(struct kvm_vcpu *vcpu)
{
struct kvm_s390_interrupt_info *inti;
unsigned long len;
u32 tpi_data[3];
int cc, rc;
u64 addr;
rc = 0;
addr = kvm_s390_get_base_disp_s(vcpu);
if (addr & 3)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
cc = 0;
inti = kvm_s390_get_io_int(vcpu->kvm, vcpu->arch.sie_block->gcr[6], 0);
if (!inti)
goto no_interrupt;
cc = 1;
tpi_data[0] = inti->io.subchannel_id << 16 | inti->io.subchannel_nr;
tpi_data[1] = inti->io.io_int_parm;
tpi_data[2] = inti->io.io_int_word;
if (addr) {
len = sizeof(tpi_data) - 4;
rc = write_guest(vcpu, addr, &tpi_data, len);
if (rc)
return kvm_s390_inject_prog_cond(vcpu, rc);
} else {
len = sizeof(tpi_data);
if (write_guest_lc(vcpu, __LC_SUBCHANNEL_ID, &tpi_data, len))
rc = -EFAULT;
}
if (!rc)
kfree(inti);
else
kvm_s390_reinject_io_int(vcpu->kvm, inti);
no_interrupt:
if (!rc)
kvm_s390_set_psw_cc(vcpu, cc);
return rc ? -EFAULT : 0;
}
static int handle_tsch(struct kvm_vcpu *vcpu)
{
struct kvm_s390_interrupt_info *inti;
inti = kvm_s390_get_io_int(vcpu->kvm, 0,
vcpu->run->s.regs.gprs[1]);
vcpu->run->exit_reason = KVM_EXIT_S390_TSCH;
vcpu->run->s390_tsch.dequeued = !!inti;
if (inti) {
vcpu->run->s390_tsch.subchannel_id = inti->io.subchannel_id;
vcpu->run->s390_tsch.subchannel_nr = inti->io.subchannel_nr;
vcpu->run->s390_tsch.io_int_parm = inti->io.io_int_parm;
vcpu->run->s390_tsch.io_int_word = inti->io.io_int_word;
}
vcpu->run->s390_tsch.ipb = vcpu->arch.sie_block->ipb;
kfree(inti);
return -EREMOTE;
}
static int handle_io_inst(struct kvm_vcpu *vcpu)
{
VCPU_EVENT(vcpu, 4, "%s", "I/O instruction");
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
if (vcpu->kvm->arch.css_support) {
if (vcpu->arch.sie_block->ipa == 0xb236)
return handle_tpi(vcpu);
if (vcpu->arch.sie_block->ipa == 0xb235)
return handle_tsch(vcpu);
return -EOPNOTSUPP;
} else {
kvm_s390_set_psw_cc(vcpu, 3);
return 0;
}
}
static int handle_stfl(struct kvm_vcpu *vcpu)
{
int rc;
vcpu->stat.instruction_stfl++;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
rc = write_guest_lc(vcpu, offsetof(struct _lowcore, stfl_fac_list),
vfacilities, 4);
if (rc)
return rc;
VCPU_EVENT(vcpu, 5, "store facility list value %x",
*(unsigned int *) vfacilities);
trace_kvm_s390_handle_stfl(vcpu, *(unsigned int *) vfacilities);
return 0;
}
int is_valid_psw(psw_t *psw)
{
if (psw->mask & PSW_MASK_UNASSIGNED)
return 0;
if ((psw->mask & PSW_MASK_ADDR_MODE) == PSW_MASK_BA) {
if (psw->addr & ~PSW_ADDR_31)
return 0;
}
if (!(psw->mask & PSW_MASK_ADDR_MODE) && (psw->addr & ~PSW_ADDR_24))
return 0;
if ((psw->mask & PSW_MASK_ADDR_MODE) == PSW_MASK_EA)
return 0;
if (psw->addr & 1)
return 0;
return 1;
}
int kvm_s390_handle_lpsw(struct kvm_vcpu *vcpu)
{
psw_t *gpsw = &vcpu->arch.sie_block->gpsw;
psw_compat_t new_psw;
u64 addr;
int rc;
if (gpsw->mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
addr = kvm_s390_get_base_disp_s(vcpu);
if (addr & 7)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
rc = read_guest(vcpu, addr, &new_psw, sizeof(new_psw));
if (rc)
return kvm_s390_inject_prog_cond(vcpu, rc);
if (!(new_psw.mask & PSW32_MASK_BASE))
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
gpsw->mask = (new_psw.mask & ~PSW32_MASK_BASE) << 32;
gpsw->mask |= new_psw.addr & PSW32_ADDR_AMODE;
gpsw->addr = new_psw.addr & ~PSW32_ADDR_AMODE;
if (!is_valid_psw(gpsw))
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
return 0;
}
static int handle_lpswe(struct kvm_vcpu *vcpu)
{
psw_t new_psw;
u64 addr;
int rc;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
addr = kvm_s390_get_base_disp_s(vcpu);
if (addr & 7)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
rc = read_guest(vcpu, addr, &new_psw, sizeof(new_psw));
if (rc)
return kvm_s390_inject_prog_cond(vcpu, rc);
vcpu->arch.sie_block->gpsw = new_psw;
if (!is_valid_psw(&vcpu->arch.sie_block->gpsw))
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
return 0;
}
static int handle_stidp(struct kvm_vcpu *vcpu)
{
u64 stidp_data = vcpu->arch.stidp_data;
u64 operand2;
int rc;
vcpu->stat.instruction_stidp++;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
operand2 = kvm_s390_get_base_disp_s(vcpu);
if (operand2 & 7)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
rc = write_guest(vcpu, operand2, &stidp_data, sizeof(stidp_data));
if (rc)
return kvm_s390_inject_prog_cond(vcpu, rc);
VCPU_EVENT(vcpu, 5, "%s", "store cpu id");
return 0;
}
static void handle_stsi_3_2_2(struct kvm_vcpu *vcpu, struct sysinfo_3_2_2 *mem)
{
int cpus = 0;
int n;
cpus = atomic_read(&vcpu->kvm->online_vcpus);
if (stsi(mem, 3, 2, 2))
mem->count = 0;
if (mem->count < 8)
mem->count++;
for (n = mem->count - 1; n > 0 ; n--)
memcpy(&mem->vm[n], &mem->vm[n - 1], sizeof(mem->vm[0]));
mem->vm[0].cpus_total = cpus;
mem->vm[0].cpus_configured = cpus;
mem->vm[0].cpus_standby = 0;
mem->vm[0].cpus_reserved = 0;
mem->vm[0].caf = 1000;
memcpy(mem->vm[0].name, "KVMguest", 8);
ASCEBC(mem->vm[0].name, 8);
memcpy(mem->vm[0].cpi, "KVM/Linux ", 16);
ASCEBC(mem->vm[0].cpi, 16);
}
static int handle_stsi(struct kvm_vcpu *vcpu)
{
int fc = (vcpu->run->s.regs.gprs[0] & 0xf0000000) >> 28;
int sel1 = vcpu->run->s.regs.gprs[0] & 0xff;
int sel2 = vcpu->run->s.regs.gprs[1] & 0xffff;
unsigned long mem = 0;
u64 operand2;
int rc = 0;
vcpu->stat.instruction_stsi++;
VCPU_EVENT(vcpu, 4, "stsi: fc: %x sel1: %x sel2: %x", fc, sel1, sel2);
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
if (fc > 3) {
kvm_s390_set_psw_cc(vcpu, 3);
return 0;
}
if (vcpu->run->s.regs.gprs[0] & 0x0fffff00
|| vcpu->run->s.regs.gprs[1] & 0xffff0000)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
if (fc == 0) {
vcpu->run->s.regs.gprs[0] = 3 << 28;
kvm_s390_set_psw_cc(vcpu, 0);
return 0;
}
operand2 = kvm_s390_get_base_disp_s(vcpu);
if (operand2 & 0xfff)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
switch (fc) {
case 1:
case 2:
mem = get_zeroed_page(GFP_KERNEL);
if (!mem)
goto out_no_data;
if (stsi((void *) mem, fc, sel1, sel2))
goto out_no_data;
break;
case 3:
if (sel1 != 2 || sel2 != 2)
goto out_no_data;
mem = get_zeroed_page(GFP_KERNEL);
if (!mem)
goto out_no_data;
handle_stsi_3_2_2(vcpu, (void *) mem);
break;
}
rc = write_guest(vcpu, operand2, (void *)mem, PAGE_SIZE);
if (rc) {
rc = kvm_s390_inject_prog_cond(vcpu, rc);
goto out;
}
trace_kvm_s390_handle_stsi(vcpu, fc, sel1, sel2, operand2);
free_page(mem);
kvm_s390_set_psw_cc(vcpu, 0);
vcpu->run->s.regs.gprs[0] = 0;
return 0;
out_no_data:
kvm_s390_set_psw_cc(vcpu, 3);
out:
free_page(mem);
return rc;
}
int kvm_s390_handle_b2(struct kvm_vcpu *vcpu)
{
intercept_handler_t handler;
handler = b2_handlers[vcpu->arch.sie_block->ipa & 0x00ff];
if (handler)
return handler(vcpu);
return -EOPNOTSUPP;
}
static int handle_epsw(struct kvm_vcpu *vcpu)
{
int reg1, reg2;
kvm_s390_get_regs_rre(vcpu, &reg1, &reg2);
vcpu->run->s.regs.gprs[reg1] &= 0xffffffff00000000UL;
vcpu->run->s.regs.gprs[reg1] |= vcpu->arch.sie_block->gpsw.mask >> 32;
if (reg2) {
vcpu->run->s.regs.gprs[reg2] &= 0xffffffff00000000UL;
vcpu->run->s.regs.gprs[reg2] |=
vcpu->arch.sie_block->gpsw.mask & 0x00000000ffffffffUL;
}
return 0;
}
static int handle_pfmf(struct kvm_vcpu *vcpu)
{
int reg1, reg2;
unsigned long start, end;
vcpu->stat.instruction_pfmf++;
kvm_s390_get_regs_rre(vcpu, &reg1, &reg2);
if (!MACHINE_HAS_PFMF)
return kvm_s390_inject_program_int(vcpu, PGM_OPERATION);
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
if (vcpu->run->s.regs.gprs[reg1] & PFMF_RESERVED)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
if (vcpu->run->s.regs.gprs[reg1] & PFMF_NQ && !test_facility(14))
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
if (vcpu->run->s.regs.gprs[reg1] & (PFMF_MR | PFMF_MC))
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
start = vcpu->run->s.regs.gprs[reg2] & PAGE_MASK;
start = kvm_s390_logical_to_effective(vcpu, start);
switch (vcpu->run->s.regs.gprs[reg1] & PFMF_FSC) {
case 0x00000000:
end = (start + (1UL << 12)) & ~((1UL << 12) - 1);
break;
case 0x00001000:
end = (start + (1UL << 20)) & ~((1UL << 20) - 1);
break;
default:
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
}
if (vcpu->run->s.regs.gprs[reg1] & PFMF_CF) {
if (kvm_s390_check_low_addr_protection(vcpu, start))
return kvm_s390_inject_prog_irq(vcpu, &vcpu->arch.pgm);
}
while (start < end) {
unsigned long useraddr, abs_addr;
if ((vcpu->run->s.regs.gprs[reg1] & PFMF_FSC) == 0)
abs_addr = kvm_s390_real_to_abs(vcpu, start);
else
abs_addr = start;
useraddr = gfn_to_hva(vcpu->kvm, gpa_to_gfn(abs_addr));
if (kvm_is_error_hva(useraddr))
return kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
if (vcpu->run->s.regs.gprs[reg1] & PFMF_CF) {
if (clear_user((void __user *)useraddr, PAGE_SIZE))
return kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
}
if (vcpu->run->s.regs.gprs[reg1] & PFMF_SK) {
int rc = __skey_check_enable(vcpu);
if (rc)
return rc;
if (set_guest_storage_key(current->mm, useraddr,
vcpu->run->s.regs.gprs[reg1] & PFMF_KEY,
vcpu->run->s.regs.gprs[reg1] & PFMF_NQ))
return kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
}
start += PAGE_SIZE;
}
if (vcpu->run->s.regs.gprs[reg1] & PFMF_FSC)
vcpu->run->s.regs.gprs[reg2] = end;
return 0;
}
static int handle_essa(struct kvm_vcpu *vcpu)
{
int entries = (vcpu->arch.sie_block->cbrlo & ~PAGE_MASK) >> 3;
unsigned long *cbrlo, cbrle;
struct gmap *gmap;
int i;
VCPU_EVENT(vcpu, 5, "cmma release %d pages", entries);
gmap = vcpu->arch.gmap;
vcpu->stat.instruction_essa++;
if (!kvm_s390_cmma_enabled(vcpu->kvm))
return kvm_s390_inject_program_int(vcpu, PGM_OPERATION);
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
if (((vcpu->arch.sie_block->ipb & 0xf0000000) >> 28) > 6)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
kvm_s390_rewind_psw(vcpu, 4);
vcpu->arch.sie_block->cbrlo &= PAGE_MASK;
cbrlo = phys_to_virt(vcpu->arch.sie_block->cbrlo);
down_read(&gmap->mm->mmap_sem);
for (i = 0; i < entries; ++i) {
cbrle = cbrlo[i];
if (unlikely(cbrle & ~PAGE_MASK || cbrle < 2 * PAGE_SIZE))
break;
__gmap_zap(gmap, cbrle);
}
up_read(&gmap->mm->mmap_sem);
if (i < entries)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
return 0;
}
int kvm_s390_handle_b9(struct kvm_vcpu *vcpu)
{
intercept_handler_t handler;
handler = b9_handlers[vcpu->arch.sie_block->ipa & 0x00ff];
if (handler)
return handler(vcpu);
return -EOPNOTSUPP;
}
int kvm_s390_handle_lctl(struct kvm_vcpu *vcpu)
{
int reg1 = (vcpu->arch.sie_block->ipa & 0x00f0) >> 4;
int reg3 = vcpu->arch.sie_block->ipa & 0x000f;
int reg, rc, nr_regs;
u32 ctl_array[16];
u64 ga;
vcpu->stat.instruction_lctl++;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
ga = kvm_s390_get_base_disp_rs(vcpu);
if (ga & 3)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
VCPU_EVENT(vcpu, 5, "lctl r1:%x, r3:%x, addr:%llx", reg1, reg3, ga);
trace_kvm_s390_handle_lctl(vcpu, 0, reg1, reg3, ga);
nr_regs = ((reg3 - reg1) & 0xf) + 1;
rc = read_guest(vcpu, ga, ctl_array, nr_regs * sizeof(u32));
if (rc)
return kvm_s390_inject_prog_cond(vcpu, rc);
reg = reg1;
nr_regs = 0;
do {
vcpu->arch.sie_block->gcr[reg] &= 0xffffffff00000000ul;
vcpu->arch.sie_block->gcr[reg] |= ctl_array[nr_regs++];
if (reg == reg3)
break;
reg = (reg + 1) % 16;
} while (1);
kvm_make_request(KVM_REQ_TLB_FLUSH, vcpu);
return 0;
}
int kvm_s390_handle_stctl(struct kvm_vcpu *vcpu)
{
int reg1 = (vcpu->arch.sie_block->ipa & 0x00f0) >> 4;
int reg3 = vcpu->arch.sie_block->ipa & 0x000f;
int reg, rc, nr_regs;
u32 ctl_array[16];
u64 ga;
vcpu->stat.instruction_stctl++;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
ga = kvm_s390_get_base_disp_rs(vcpu);
if (ga & 3)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
VCPU_EVENT(vcpu, 5, "stctl r1:%x, r3:%x, addr:%llx", reg1, reg3, ga);
trace_kvm_s390_handle_stctl(vcpu, 0, reg1, reg3, ga);
reg = reg1;
nr_regs = 0;
do {
ctl_array[nr_regs++] = vcpu->arch.sie_block->gcr[reg];
if (reg == reg3)
break;
reg = (reg + 1) % 16;
} while (1);
rc = write_guest(vcpu, ga, ctl_array, nr_regs * sizeof(u32));
return rc ? kvm_s390_inject_prog_cond(vcpu, rc) : 0;
}
static int handle_lctlg(struct kvm_vcpu *vcpu)
{
int reg1 = (vcpu->arch.sie_block->ipa & 0x00f0) >> 4;
int reg3 = vcpu->arch.sie_block->ipa & 0x000f;
int reg, rc, nr_regs;
u64 ctl_array[16];
u64 ga;
vcpu->stat.instruction_lctlg++;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
ga = kvm_s390_get_base_disp_rsy(vcpu);
if (ga & 7)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
VCPU_EVENT(vcpu, 5, "lctlg r1:%x, r3:%x, addr:%llx", reg1, reg3, ga);
trace_kvm_s390_handle_lctl(vcpu, 1, reg1, reg3, ga);
nr_regs = ((reg3 - reg1) & 0xf) + 1;
rc = read_guest(vcpu, ga, ctl_array, nr_regs * sizeof(u64));
if (rc)
return kvm_s390_inject_prog_cond(vcpu, rc);
reg = reg1;
nr_regs = 0;
do {
vcpu->arch.sie_block->gcr[reg] = ctl_array[nr_regs++];
if (reg == reg3)
break;
reg = (reg + 1) % 16;
} while (1);
kvm_make_request(KVM_REQ_TLB_FLUSH, vcpu);
return 0;
}
static int handle_stctg(struct kvm_vcpu *vcpu)
{
int reg1 = (vcpu->arch.sie_block->ipa & 0x00f0) >> 4;
int reg3 = vcpu->arch.sie_block->ipa & 0x000f;
int reg, rc, nr_regs;
u64 ctl_array[16];
u64 ga;
vcpu->stat.instruction_stctg++;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
ga = kvm_s390_get_base_disp_rsy(vcpu);
if (ga & 7)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
VCPU_EVENT(vcpu, 5, "stctg r1:%x, r3:%x, addr:%llx", reg1, reg3, ga);
trace_kvm_s390_handle_stctl(vcpu, 1, reg1, reg3, ga);
reg = reg1;
nr_regs = 0;
do {
ctl_array[nr_regs++] = vcpu->arch.sie_block->gcr[reg];
if (reg == reg3)
break;
reg = (reg + 1) % 16;
} while (1);
rc = write_guest(vcpu, ga, ctl_array, nr_regs * sizeof(u64));
return rc ? kvm_s390_inject_prog_cond(vcpu, rc) : 0;
}
int kvm_s390_handle_eb(struct kvm_vcpu *vcpu)
{
intercept_handler_t handler;
handler = eb_handlers[vcpu->arch.sie_block->ipb & 0xff];
if (handler)
return handler(vcpu);
return -EOPNOTSUPP;
}
static int handle_tprot(struct kvm_vcpu *vcpu)
{
u64 address1, address2;
unsigned long hva, gpa;
int ret = 0, cc = 0;
bool writable;
vcpu->stat.instruction_tprot++;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
kvm_s390_get_base_disp_sse(vcpu, &address1, &address2);
if (address2 & 0xf0)
return -EOPNOTSUPP;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_DAT)
ipte_lock(vcpu);
ret = guest_translate_address(vcpu, address1, &gpa, 1);
if (ret == PGM_PROTECTION) {
cc = 1;
ret = guest_translate_address(vcpu, address1, &gpa, 0);
}
if (ret) {
if (ret == PGM_ADDRESSING || ret == PGM_TRANSLATION_SPEC) {
ret = kvm_s390_inject_program_int(vcpu, ret);
} else if (ret > 0) {
kvm_s390_set_psw_cc(vcpu, 3);
ret = 0;
}
goto out_unlock;
}
hva = gfn_to_hva_prot(vcpu->kvm, gpa_to_gfn(gpa), &writable);
if (kvm_is_error_hva(hva)) {
ret = kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
} else {
if (!writable)
cc = 1;
kvm_s390_set_psw_cc(vcpu, cc);
}
out_unlock:
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_DAT)
ipte_unlock(vcpu);
return ret;
}
int kvm_s390_handle_e5(struct kvm_vcpu *vcpu)
{
if ((vcpu->arch.sie_block->ipa & 0x00ff) == 0x01)
return handle_tprot(vcpu);
return -EOPNOTSUPP;
}
static int handle_sckpf(struct kvm_vcpu *vcpu)
{
u32 value;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
if (vcpu->run->s.regs.gprs[0] & 0x00000000ffff0000)
return kvm_s390_inject_program_int(vcpu,
PGM_SPECIFICATION);
value = vcpu->run->s.regs.gprs[0] & 0x000000000000ffff;
vcpu->arch.sie_block->todpr = value;
return 0;
}
int kvm_s390_handle_01(struct kvm_vcpu *vcpu)
{
intercept_handler_t handler;
handler = x01_handlers[vcpu->arch.sie_block->ipa & 0x00ff];
if (handler)
return handler(vcpu);
return -EOPNOTSUPP;
}
