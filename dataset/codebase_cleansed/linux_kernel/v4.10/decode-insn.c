static bool __kprobes aarch64_insn_is_steppable(u32 insn)
{
if (aarch64_get_insn_class(insn) == AARCH64_INSN_CLS_BR_SYS) {
if (aarch64_insn_is_branch(insn) ||
aarch64_insn_is_msr_imm(insn) ||
aarch64_insn_is_msr_reg(insn) ||
aarch64_insn_is_exception(insn) ||
aarch64_insn_is_eret(insn))
return false;
if (aarch64_insn_is_mrs(insn))
return aarch64_insn_extract_system_reg(insn)
!= AARCH64_INSN_SPCLREG_DAIF;
if (aarch64_insn_is_hint(insn))
return aarch64_insn_is_nop(insn);
return true;
}
if (aarch64_insn_uses_literal(insn) ||
aarch64_insn_is_exclusive(insn))
return false;
return true;
}
enum probe_insn __kprobes
arm_probe_decode_insn(probe_opcode_t insn, struct arch_probe_insn *api)
{
if (aarch64_insn_is_steppable(insn))
return INSN_GOOD;
if (aarch64_insn_is_bcond(insn)) {
api->handler = simulate_b_cond;
} else if (aarch64_insn_is_cbz(insn) ||
aarch64_insn_is_cbnz(insn)) {
api->handler = simulate_cbz_cbnz;
} else if (aarch64_insn_is_tbz(insn) ||
aarch64_insn_is_tbnz(insn)) {
api->handler = simulate_tbz_tbnz;
} else if (aarch64_insn_is_adr_adrp(insn)) {
api->handler = simulate_adr_adrp;
} else if (aarch64_insn_is_b(insn) ||
aarch64_insn_is_bl(insn)) {
api->handler = simulate_b_bl;
} else if (aarch64_insn_is_br(insn) ||
aarch64_insn_is_blr(insn) ||
aarch64_insn_is_ret(insn)) {
api->handler = simulate_br_blr_ret;
} else if (aarch64_insn_is_ldr_lit(insn)) {
api->handler = simulate_ldr_literal;
} else if (aarch64_insn_is_ldrsw_lit(insn)) {
api->handler = simulate_ldrsw_literal;
} else {
return INSN_REJECTED;
}
return INSN_GOOD_NO_SLOT;
}
static bool __kprobes
is_probed_address_atomic(kprobe_opcode_t *scan_start, kprobe_opcode_t *scan_end)
{
while (scan_start >= scan_end) {
if (aarch64_insn_is_store_ex(le32_to_cpu(*scan_start)))
return false;
else if (aarch64_insn_is_load_ex(le32_to_cpu(*scan_start)))
return true;
scan_start--;
}
return false;
}
enum probe_insn __kprobes
arm_kprobe_decode_insn(kprobe_opcode_t *addr, struct arch_specific_insn *asi)
{
enum probe_insn decoded;
probe_opcode_t insn = le32_to_cpu(*addr);
probe_opcode_t *scan_end = NULL;
unsigned long size = 0, offset = 0;
if (kallsyms_lookup_size_offset((unsigned long) addr, &size, &offset)) {
if (offset < (MAX_ATOMIC_CONTEXT_SIZE*sizeof(kprobe_opcode_t)))
scan_end = addr - (offset / sizeof(kprobe_opcode_t));
else
scan_end = addr - MAX_ATOMIC_CONTEXT_SIZE;
}
decoded = arm_probe_decode_insn(insn, &asi->api);
if (decoded != INSN_REJECTED && scan_end)
if (is_probed_address_atomic(addr - 1, scan_end))
return INSN_REJECTED;
return decoded;
}
