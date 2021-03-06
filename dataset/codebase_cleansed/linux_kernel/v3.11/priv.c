static int handle_set_prefix(struct kvm_vcpu *vcpu)
{
u64 operand2;
u32 address = 0;
u8 tmp;
vcpu->stat.instruction_spx++;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
operand2 = kvm_s390_get_base_disp_s(vcpu);
if (operand2 & 3)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
if (get_guest(vcpu, address, (u32 __user *) operand2))
return kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
address = address & 0x7fffe000u;
if (copy_from_guest_absolute(vcpu, &tmp, address, 1) ||
(copy_from_guest_absolute(vcpu, &tmp, address + PAGE_SIZE, 1)))
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
vcpu->stat.instruction_stpx++;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
operand2 = kvm_s390_get_base_disp_s(vcpu);
if (operand2 & 3)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
address = vcpu->arch.sie_block->prefix;
address = address & 0x7fffe000u;
if (put_guest(vcpu, address, (u32 __user *)operand2))
return kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
VCPU_EVENT(vcpu, 5, "storing prefix to %x", address);
trace_kvm_s390_handle_prefix(vcpu, 0, address);
return 0;
}
static int handle_store_cpu_address(struct kvm_vcpu *vcpu)
{
u64 useraddr;
vcpu->stat.instruction_stap++;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
useraddr = kvm_s390_get_base_disp_s(vcpu);
if (useraddr & 1)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
if (put_guest(vcpu, vcpu->vcpu_id, (u16 __user *)useraddr))
return kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
VCPU_EVENT(vcpu, 5, "storing cpu address to %llx", useraddr);
trace_kvm_s390_handle_stap(vcpu, useraddr);
return 0;
}
static int handle_skey(struct kvm_vcpu *vcpu)
{
vcpu->stat.instruction_storage_key++;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
vcpu->arch.sie_block->gpsw.addr =
__rewind_psw(vcpu->arch.sie_block->gpsw, 4);
VCPU_EVENT(vcpu, 4, "%s", "retrying storage key operation");
return 0;
}
static int handle_tpi(struct kvm_vcpu *vcpu)
{
struct kvm_s390_interrupt_info *inti;
u64 addr;
int cc;
addr = kvm_s390_get_base_disp_s(vcpu);
if (addr & 3)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
cc = 0;
inti = kvm_s390_get_io_int(vcpu->kvm, vcpu->run->s.regs.crs[6], 0);
if (!inti)
goto no_interrupt;
cc = 1;
if (addr) {
if (put_guest(vcpu, inti->io.subchannel_id, (u16 __user *)addr)
|| put_guest(vcpu, inti->io.subchannel_nr, (u16 __user *)(addr + 2))
|| put_guest(vcpu, inti->io.io_int_parm, (u32 __user *)(addr + 4)))
return kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
} else {
put_guest(vcpu, inti->io.subchannel_id, (u16 __user *) __LC_SUBCHANNEL_ID);
put_guest(vcpu, inti->io.subchannel_nr, (u16 __user *) __LC_SUBCHANNEL_NR);
put_guest(vcpu, inti->io.io_int_parm, (u32 __user *) __LC_IO_INT_PARM);
put_guest(vcpu, inti->io.io_int_word, (u32 __user *) __LC_IO_INT_WORD);
}
kfree(inti);
no_interrupt:
vcpu->arch.sie_block->gpsw.mask &= ~(3ul << 44);
vcpu->arch.sie_block->gpsw.mask |= (cc & 3ul) << 44;
return 0;
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
vcpu->arch.sie_block->gpsw.mask &= ~(3ul << 44);
vcpu->arch.sie_block->gpsw.mask |= (3 & 3ul) << 44;
return 0;
}
}
static int handle_stfl(struct kvm_vcpu *vcpu)
{
unsigned int facility_list;
int rc;
vcpu->stat.instruction_stfl++;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
facility_list = S390_lowcore.stfl_fac_list & 0xff82fff3;
rc = copy_to_guest(vcpu, offsetof(struct _lowcore, stfl_fac_list),
&facility_list, sizeof(facility_list));
if (rc)
return kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
VCPU_EVENT(vcpu, 5, "store facility list value %x", facility_list);
trace_kvm_s390_handle_stfl(vcpu, facility_list);
return 0;
}
static void handle_new_psw(struct kvm_vcpu *vcpu)
{
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_MCHECK)
kvm_s390_deliver_pending_machine_checks(vcpu);
}
static int is_valid_psw(psw_t *psw) {
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
return 1;
}
int kvm_s390_handle_lpsw(struct kvm_vcpu *vcpu)
{
psw_t *gpsw = &vcpu->arch.sie_block->gpsw;
psw_compat_t new_psw;
u64 addr;
if (gpsw->mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
addr = kvm_s390_get_base_disp_s(vcpu);
if (addr & 7)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
if (copy_from_guest(vcpu, &new_psw, addr, sizeof(new_psw)))
return kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
if (!(new_psw.mask & PSW32_MASK_BASE))
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
gpsw->mask = (new_psw.mask & ~PSW32_MASK_BASE) << 32;
gpsw->mask |= new_psw.addr & PSW32_ADDR_AMODE;
gpsw->addr = new_psw.addr & ~PSW32_ADDR_AMODE;
if (!is_valid_psw(gpsw))
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
handle_new_psw(vcpu);
return 0;
}
static int handle_lpswe(struct kvm_vcpu *vcpu)
{
psw_t new_psw;
u64 addr;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
addr = kvm_s390_get_base_disp_s(vcpu);
if (addr & 7)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
if (copy_from_guest(vcpu, &new_psw, addr, sizeof(new_psw)))
return kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
vcpu->arch.sie_block->gpsw = new_psw;
if (!is_valid_psw(&vcpu->arch.sie_block->gpsw))
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
handle_new_psw(vcpu);
return 0;
}
static int handle_stidp(struct kvm_vcpu *vcpu)
{
u64 operand2;
vcpu->stat.instruction_stidp++;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
operand2 = kvm_s390_get_base_disp_s(vcpu);
if (operand2 & 7)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
if (put_guest(vcpu, vcpu->arch.stidp_data, (u64 __user *)operand2))
return kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
VCPU_EVENT(vcpu, 5, "%s", "store cpu id");
return 0;
}
static void handle_stsi_3_2_2(struct kvm_vcpu *vcpu, struct sysinfo_3_2_2 *mem)
{
struct kvm_s390_float_interrupt *fi = &vcpu->kvm->arch.float_int;
int cpus = 0;
int n;
spin_lock(&fi->lock);
for (n = 0; n < KVM_MAX_VCPUS; n++)
if (fi->local_int[n])
cpus++;
spin_unlock(&fi->lock);
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
vcpu->arch.sie_block->gpsw.mask |= 3ul << 44;
return 0;
}
if (vcpu->run->s.regs.gprs[0] & 0x0fffff00
|| vcpu->run->s.regs.gprs[1] & 0xffff0000)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
if (fc == 0) {
vcpu->run->s.regs.gprs[0] = 3 << 28;
vcpu->arch.sie_block->gpsw.mask &= ~(3ul << 44);
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
if (copy_to_guest_absolute(vcpu, operand2, (void *) mem, PAGE_SIZE)) {
rc = kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
goto out_exception;
}
trace_kvm_s390_handle_stsi(vcpu, fc, sel1, sel2, operand2);
free_page(mem);
vcpu->arch.sie_block->gpsw.mask &= ~(3ul << 44);
vcpu->run->s.regs.gprs[0] = 0;
return 0;
out_no_data:
vcpu->arch.sie_block->gpsw.mask |= 3ul << 44;
out_exception:
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
vcpu->run->s.regs.gprs[reg1] &= 0xffffffff00000000;
vcpu->run->s.regs.gprs[reg1] |= vcpu->arch.sie_block->gpsw.mask >> 32;
if (reg2) {
vcpu->run->s.regs.gprs[reg2] &= 0xffffffff00000000;
vcpu->run->s.regs.gprs[reg2] |=
vcpu->arch.sie_block->gpsw.mask & 0x00000000ffffffff;
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
while (start < end) {
unsigned long useraddr;
useraddr = gmap_translate(start, vcpu->arch.gmap);
if (IS_ERR((void *)useraddr))
return kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
if (vcpu->run->s.regs.gprs[reg1] & PFMF_CF) {
if (clear_user((void __user *)useraddr, PAGE_SIZE))
return kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
}
if (vcpu->run->s.regs.gprs[reg1] & PFMF_SK) {
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
u64 useraddr;
u32 val = 0;
int reg, rc;
vcpu->stat.instruction_lctl++;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
useraddr = kvm_s390_get_base_disp_rs(vcpu);
if (useraddr & 3)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
VCPU_EVENT(vcpu, 5, "lctl r1:%x, r3:%x, addr:%llx", reg1, reg3,
useraddr);
trace_kvm_s390_handle_lctl(vcpu, 0, reg1, reg3, useraddr);
reg = reg1;
do {
rc = get_guest(vcpu, val, (u32 __user *) useraddr);
if (rc)
return kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
vcpu->arch.sie_block->gcr[reg] &= 0xffffffff00000000ul;
vcpu->arch.sie_block->gcr[reg] |= val;
useraddr += 4;
if (reg == reg3)
break;
reg = (reg + 1) % 16;
} while (1);
return 0;
}
static int handle_lctlg(struct kvm_vcpu *vcpu)
{
int reg1 = (vcpu->arch.sie_block->ipa & 0x00f0) >> 4;
int reg3 = vcpu->arch.sie_block->ipa & 0x000f;
u64 useraddr;
int reg, rc;
vcpu->stat.instruction_lctlg++;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
useraddr = kvm_s390_get_base_disp_rsy(vcpu);
if (useraddr & 7)
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
reg = reg1;
VCPU_EVENT(vcpu, 5, "lctlg r1:%x, r3:%x, addr:%llx", reg1, reg3,
useraddr);
trace_kvm_s390_handle_lctl(vcpu, 1, reg1, reg3, useraddr);
do {
rc = get_guest(vcpu, vcpu->arch.sie_block->gcr[reg],
(u64 __user *) useraddr);
if (rc)
return kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
useraddr += 8;
if (reg == reg3)
break;
reg = (reg + 1) % 16;
} while (1);
return 0;
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
struct vm_area_struct *vma;
unsigned long user_address;
vcpu->stat.instruction_tprot++;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
kvm_s390_get_base_disp_sse(vcpu, &address1, &address2);
if (address2 & 0xf0)
return -EOPNOTSUPP;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_DAT)
return -EOPNOTSUPP;
down_read(&current->mm->mmap_sem);
user_address = __gmap_translate(address1, vcpu->arch.gmap);
if (IS_ERR_VALUE(user_address))
goto out_inject;
vma = find_vma(current->mm, user_address);
if (!vma)
goto out_inject;
vcpu->arch.sie_block->gpsw.mask &= ~(3ul << 44);
if (!(vma->vm_flags & VM_WRITE) && (vma->vm_flags & VM_READ))
vcpu->arch.sie_block->gpsw.mask |= (1ul << 44);
if (!(vma->vm_flags & VM_WRITE) && !(vma->vm_flags & VM_READ))
vcpu->arch.sie_block->gpsw.mask |= (2ul << 44);
up_read(&current->mm->mmap_sem);
return 0;
out_inject:
up_read(&current->mm->mmap_sem);
return kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
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
