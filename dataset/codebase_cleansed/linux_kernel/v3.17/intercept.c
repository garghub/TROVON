static int handle_noop(struct kvm_vcpu *vcpu)
{
switch (vcpu->arch.sie_block->icptcode) {
case 0x0:
vcpu->stat.exit_null++;
break;
case 0x10:
vcpu->stat.exit_external_request++;
break;
default:
break;
}
return 0;
}
static int handle_stop(struct kvm_vcpu *vcpu)
{
int rc = 0;
unsigned int action_bits;
vcpu->stat.exit_stop_request++;
trace_kvm_s390_stop_request(vcpu->arch.local_int.action_bits);
action_bits = vcpu->arch.local_int.action_bits;
if (!(action_bits & ACTION_STOP_ON_STOP))
return 0;
if (action_bits & ACTION_STORE_ON_STOP) {
rc = kvm_s390_vcpu_store_status(vcpu,
KVM_S390_STORE_STATUS_NOADDR);
if (rc)
return rc;
}
if (!kvm_s390_user_cpu_state_ctrl(vcpu->kvm))
kvm_s390_vcpu_stop(vcpu);
return -EOPNOTSUPP;
}
static int handle_validity(struct kvm_vcpu *vcpu)
{
int viwhy = vcpu->arch.sie_block->ipb >> 16;
vcpu->stat.exit_validity++;
trace_kvm_s390_intercept_validity(vcpu, viwhy);
WARN_ONCE(true, "kvm: unhandled validity intercept 0x%x\n", viwhy);
return -EOPNOTSUPP;
}
static int handle_instruction(struct kvm_vcpu *vcpu)
{
intercept_handler_t handler;
vcpu->stat.exit_instruction++;
trace_kvm_s390_intercept_instruction(vcpu,
vcpu->arch.sie_block->ipa,
vcpu->arch.sie_block->ipb);
handler = instruction_handlers[vcpu->arch.sie_block->ipa >> 8];
if (handler)
return handler(vcpu);
return -EOPNOTSUPP;
}
static void __extract_prog_irq(struct kvm_vcpu *vcpu,
struct kvm_s390_pgm_info *pgm_info)
{
memset(pgm_info, 0, sizeof(struct kvm_s390_pgm_info));
pgm_info->code = vcpu->arch.sie_block->iprcc;
switch (vcpu->arch.sie_block->iprcc & ~PGM_PER) {
case PGM_AFX_TRANSLATION:
case PGM_ASX_TRANSLATION:
case PGM_EX_TRANSLATION:
case PGM_LFX_TRANSLATION:
case PGM_LSTE_SEQUENCE:
case PGM_LSX_TRANSLATION:
case PGM_LX_TRANSLATION:
case PGM_PRIMARY_AUTHORITY:
case PGM_SECONDARY_AUTHORITY:
case PGM_SPACE_SWITCH:
pgm_info->trans_exc_code = vcpu->arch.sie_block->tecmc;
break;
case PGM_ALEN_TRANSLATION:
case PGM_ALE_SEQUENCE:
case PGM_ASTE_INSTANCE:
case PGM_ASTE_SEQUENCE:
case PGM_ASTE_VALIDITY:
case PGM_EXTENDED_AUTHORITY:
pgm_info->exc_access_id = vcpu->arch.sie_block->eai;
break;
case PGM_ASCE_TYPE:
case PGM_PAGE_TRANSLATION:
case PGM_REGION_FIRST_TRANS:
case PGM_REGION_SECOND_TRANS:
case PGM_REGION_THIRD_TRANS:
case PGM_SEGMENT_TRANSLATION:
pgm_info->trans_exc_code = vcpu->arch.sie_block->tecmc;
pgm_info->exc_access_id = vcpu->arch.sie_block->eai;
pgm_info->op_access_id = vcpu->arch.sie_block->oai;
break;
case PGM_MONITOR:
pgm_info->mon_class_nr = vcpu->arch.sie_block->mcn;
pgm_info->mon_code = vcpu->arch.sie_block->tecmc;
break;
case PGM_DATA:
pgm_info->data_exc_code = vcpu->arch.sie_block->dxc;
break;
case PGM_PROTECTION:
pgm_info->trans_exc_code = vcpu->arch.sie_block->tecmc;
pgm_info->exc_access_id = vcpu->arch.sie_block->eai;
break;
default:
break;
}
if (vcpu->arch.sie_block->iprcc & PGM_PER) {
pgm_info->per_code = vcpu->arch.sie_block->perc;
pgm_info->per_atmid = vcpu->arch.sie_block->peratmid;
pgm_info->per_address = vcpu->arch.sie_block->peraddr;
pgm_info->per_access_id = vcpu->arch.sie_block->peraid;
}
}
static int handle_itdb(struct kvm_vcpu *vcpu)
{
struct kvm_s390_itdb *itdb;
int rc;
if (!IS_TE_ENABLED(vcpu) || !IS_ITDB_VALID(vcpu))
return 0;
if (current->thread.per_flags & PER_FLAG_NO_TE)
return 0;
itdb = (struct kvm_s390_itdb *)vcpu->arch.sie_block->itdba;
rc = write_guest_lc(vcpu, __LC_PGM_TDB, itdb, sizeof(*itdb));
if (rc)
return rc;
memset(itdb, 0, sizeof(*itdb));
return 0;
}
static int handle_prog(struct kvm_vcpu *vcpu)
{
struct kvm_s390_pgm_info pgm_info;
psw_t psw;
int rc;
vcpu->stat.exit_program_interruption++;
if (guestdbg_enabled(vcpu) && per_event(vcpu)) {
kvm_s390_handle_per_event(vcpu);
if (vcpu->arch.sie_block->iprcc == 0)
return 0;
}
trace_kvm_s390_intercept_prog(vcpu, vcpu->arch.sie_block->iprcc);
if (vcpu->arch.sie_block->iprcc == PGM_SPECIFICATION) {
rc = read_guest_lc(vcpu, __LC_PGM_NEW_PSW, &psw, sizeof(psw_t));
if (rc)
return rc;
if (!is_valid_psw(&psw))
return -EOPNOTSUPP;
}
rc = handle_itdb(vcpu);
if (rc)
return rc;
__extract_prog_irq(vcpu, &pgm_info);
return kvm_s390_inject_prog_irq(vcpu, &pgm_info);
}
static int handle_instruction_and_prog(struct kvm_vcpu *vcpu)
{
int rc, rc2;
vcpu->stat.exit_instr_and_program++;
rc = handle_instruction(vcpu);
rc2 = handle_prog(vcpu);
if (rc == -EOPNOTSUPP)
vcpu->arch.sie_block->icptcode = 0x04;
if (rc)
return rc;
return rc2;
}
static int handle_external_interrupt(struct kvm_vcpu *vcpu)
{
u16 eic = vcpu->arch.sie_block->eic;
struct kvm_s390_interrupt irq;
psw_t newpsw;
int rc;
vcpu->stat.exit_external_interrupt++;
rc = read_guest_lc(vcpu, __LC_EXT_NEW_PSW, &newpsw, sizeof(psw_t));
if (rc)
return rc;
if ((eic == EXT_IRQ_CLK_COMP || eic == EXT_IRQ_CPU_TIMER) &&
(newpsw.mask & PSW_MASK_EXT))
return -EOPNOTSUPP;
switch (eic) {
case EXT_IRQ_CLK_COMP:
irq.type = KVM_S390_INT_CLOCK_COMP;
break;
case EXT_IRQ_CPU_TIMER:
irq.type = KVM_S390_INT_CPU_TIMER;
break;
case EXT_IRQ_EXTERNAL_CALL:
if (kvm_s390_si_ext_call_pending(vcpu))
return 0;
irq.type = KVM_S390_INT_EXTERNAL_CALL;
irq.parm = vcpu->arch.sie_block->extcpuaddr;
break;
default:
return -EOPNOTSUPP;
}
return kvm_s390_inject_vcpu(vcpu, &irq);
}
static int handle_mvpg_pei(struct kvm_vcpu *vcpu)
{
psw_t *psw = &vcpu->arch.sie_block->gpsw;
unsigned long srcaddr, dstaddr;
int reg1, reg2, rc;
kvm_s390_get_regs_rre(vcpu, &reg1, &reg2);
srcaddr = kvm_s390_real_to_abs(vcpu, vcpu->run->s.regs.gprs[reg2]);
if (kvm_is_error_gpa(vcpu->kvm, srcaddr))
return kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
rc = kvm_arch_fault_in_page(vcpu, srcaddr, 0);
if (rc != 0)
return rc;
dstaddr = kvm_s390_real_to_abs(vcpu, vcpu->run->s.regs.gprs[reg1]);
if (kvm_is_error_gpa(vcpu->kvm, dstaddr))
return kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
rc = kvm_arch_fault_in_page(vcpu, dstaddr, 1);
if (rc != 0)
return rc;
psw->addr = __rewind_psw(*psw, 4);
return 0;
}
static int handle_partial_execution(struct kvm_vcpu *vcpu)
{
if (vcpu->arch.sie_block->ipa == 0xb254)
return handle_mvpg_pei(vcpu);
if (vcpu->arch.sie_block->ipa >> 8 == 0xae)
return kvm_s390_handle_sigp_pei(vcpu);
return -EOPNOTSUPP;
}
int kvm_handle_sie_intercept(struct kvm_vcpu *vcpu)
{
intercept_handler_t func;
u8 code = vcpu->arch.sie_block->icptcode;
if (code & 3 || (code >> 2) >= ARRAY_SIZE(intercept_funcs))
return -EOPNOTSUPP;
func = intercept_funcs[code >> 2];
if (func)
return func(vcpu);
return -EOPNOTSUPP;
}
