static void init_disassembler(void)
{
ud_init(&ud);
ud_set_syntax(&ud, UD_SYN_ATT);
}
static const char *disassemble(unsigned char *insn, int len, uint64_t rip,
int cr0_pe, int eflags_vm,
int cs_d, int cs_l)
{
int mode;
if (!cr0_pe)
mode = 16;
else if (eflags_vm)
mode = 16;
else if (cs_l)
mode = 64;
else if (cs_d)
mode = 32;
else
mode = 16;
ud_set_pc(&ud, rip);
ud_set_mode(&ud, mode);
ud_set_input_buffer(&ud, insn, len);
ud_disassemble(&ud);
return ud_insn_asm(&ud);
}
static void init_disassembler(void)
{
}
static const char *disassemble(unsigned char *insn, int len, uint64_t rip,
int cr0_pe, int eflags_vm,
int cs_d, int cs_l)
{
static char out[15*3+1];
int i;
for (i = 0; i < len; ++i)
sprintf(out + i * 3, "%02x ", insn[i]);
out[len*3-1] = '\0';
return out;
}
static const char *find_exit_reason(unsigned isa, int val)
{
struct str_values *strings = NULL;
int i;
for (i = 0; isa_exit_reasons[i].strings; ++i)
if (isa_exit_reasons[i].isa == isa) {
strings = isa_exit_reasons[i].strings;
break;
}
if (!strings)
return "UNKNOWN-ISA";
for (i = 0; strings[i].val >= 0; i++)
if (strings[i].val == val)
break;
return strings[i].str;
}
static int print_exit_reason(struct trace_seq *s, struct pevent_record *record,
struct event_format *event, const char *field)
{
unsigned long long isa;
unsigned long long val;
const char *reason;
if (pevent_get_field_val(s, event, field, record, &val, 1) < 0)
return -1;
if (pevent_get_field_val(s, event, "isa", record, &isa, 0) < 0)
isa = 1;
reason = find_exit_reason(isa, val);
if (reason)
trace_seq_printf(s, "reason %s", reason);
else
trace_seq_printf(s, "reason UNKNOWN (%llu)", val);
return 0;
}
static int kvm_exit_handler(struct trace_seq *s, struct pevent_record *record,
struct event_format *event, void *context)
{
unsigned long long info1 = 0, info2 = 0;
if (print_exit_reason(s, record, event, "exit_reason") < 0)
return -1;
pevent_print_num_field(s, " rip 0x%lx", event, "guest_rip", record, 1);
if (pevent_get_field_val(s, event, "info1", record, &info1, 0) >= 0
&& pevent_get_field_val(s, event, "info2", record, &info2, 0) >= 0)
trace_seq_printf(s, " info %llx %llx", info1, info2);
return 0;
}
static int kvm_emulate_insn_handler(struct trace_seq *s,
struct pevent_record *record,
struct event_format *event, void *context)
{
unsigned long long rip, csbase, len, flags, failed;
int llen;
uint8_t *insn;
const char *disasm;
if (pevent_get_field_val(s, event, "rip", record, &rip, 1) < 0)
return -1;
if (pevent_get_field_val(s, event, "csbase", record, &csbase, 1) < 0)
return -1;
if (pevent_get_field_val(s, event, "len", record, &len, 1) < 0)
return -1;
if (pevent_get_field_val(s, event, "flags", record, &flags, 1) < 0)
return -1;
if (pevent_get_field_val(s, event, "failed", record, &failed, 1) < 0)
return -1;
insn = pevent_get_field_raw(s, event, "insn", record, &llen, 1);
if (!insn)
return -1;
disasm = disassemble(insn, len, rip,
flags & KVM_EMUL_INSN_F_CR0_PE,
flags & KVM_EMUL_INSN_F_EFL_VM,
flags & KVM_EMUL_INSN_F_CS_D,
flags & KVM_EMUL_INSN_F_CS_L);
trace_seq_printf(s, "%llx:%llx: %s%s", csbase, rip, disasm,
failed ? " FAIL" : "");
return 0;
}
static int kvm_nested_vmexit_inject_handler(struct trace_seq *s, struct pevent_record *record,
struct event_format *event, void *context)
{
if (print_exit_reason(s, record, event, "exit_code") < 0)
return -1;
pevent_print_num_field(s, " info1 %llx", event, "exit_info1", record, 1);
pevent_print_num_field(s, " info2 %llx", event, "exit_info2", record, 1);
pevent_print_num_field(s, " int_info %llx", event, "exit_int_info", record, 1);
pevent_print_num_field(s, " int_info_err %llx", event, "exit_int_info_err", record, 1);
return 0;
}
static int kvm_nested_vmexit_handler(struct trace_seq *s, struct pevent_record *record,
struct event_format *event, void *context)
{
pevent_print_num_field(s, "rip %llx ", event, "rip", record, 1);
return kvm_nested_vmexit_inject_handler(s, record, event, context);
}
static int kvm_mmu_print_role(struct trace_seq *s, struct pevent_record *record,
struct event_format *event, void *context)
{
unsigned long long val;
static const char *access_str[] = {
"---", "--x", "w--", "w-x", "-u-", "-ux", "wu-", "wux"
};
union kvm_mmu_page_role role;
if (pevent_get_field_val(s, event, "role", record, &val, 1) < 0)
return -1;
role.word = (int)val;
if (pevent_is_file_bigendian(event->pevent) ==
pevent_is_host_bigendian(event->pevent)) {
trace_seq_printf(s, "%u q%u%s %s%s %spae %snxe %swp%s%s%s",
role.level,
role.quadrant,
role.direct ? " direct" : "",
access_str[role.access],
role.invalid ? " invalid" : "",
role.cr4_pae ? "" : "!",
role.nxe ? "" : "!",
role.cr0_wp ? "" : "!",
role.smep_and_not_wp ? " smep" : "",
role.smap_and_not_wp ? " smap" : "",
role.smm ? " smm" : "");
} else
trace_seq_printf(s, "WORD: %08x", role.word);
pevent_print_num_field(s, " root %u ", event,
"root_count", record, 1);
if (pevent_get_field_val(s, event, "unsync", record, &val, 1) < 0)
return -1;
trace_seq_printf(s, "%s%c", val ? "unsync" : "sync", 0);
return 0;
}
static int kvm_mmu_get_page_handler(struct trace_seq *s,
struct pevent_record *record,
struct event_format *event, void *context)
{
unsigned long long val;
if (pevent_get_field_val(s, event, "created", record, &val, 1) < 0)
return -1;
trace_seq_printf(s, "%s ", val ? "new" : "existing");
if (pevent_get_field_val(s, event, "gfn", record, &val, 1) < 0)
return -1;
trace_seq_printf(s, "sp gfn %llx ", val);
return kvm_mmu_print_role(s, record, event, context);
}
static unsigned long long
process_is_writable_pte(struct trace_seq *s, unsigned long long *args)
{
unsigned long pte = args[0];
return pte & PT_WRITABLE_MASK;
}
int PEVENT_PLUGIN_LOADER(struct pevent *pevent)
{
init_disassembler();
pevent_register_event_handler(pevent, -1, "kvm", "kvm_exit",
kvm_exit_handler, NULL);
pevent_register_event_handler(pevent, -1, "kvm", "kvm_emulate_insn",
kvm_emulate_insn_handler, NULL);
pevent_register_event_handler(pevent, -1, "kvm", "kvm_nested_vmexit",
kvm_nested_vmexit_handler, NULL);
pevent_register_event_handler(pevent, -1, "kvm", "kvm_nested_vmexit_inject",
kvm_nested_vmexit_inject_handler, NULL);
pevent_register_event_handler(pevent, -1, "kvmmmu", "kvm_mmu_get_page",
kvm_mmu_get_page_handler, NULL);
pevent_register_event_handler(pevent, -1, "kvmmmu", "kvm_mmu_sync_page",
kvm_mmu_print_role, NULL);
pevent_register_event_handler(pevent, -1,
"kvmmmu", "kvm_mmu_unsync_page",
kvm_mmu_print_role, NULL);
pevent_register_event_handler(pevent, -1, "kvmmmu", "kvm_mmu_zap_page",
kvm_mmu_print_role, NULL);
pevent_register_event_handler(pevent, -1, "kvmmmu",
"kvm_mmu_prepare_zap_page", kvm_mmu_print_role,
NULL);
pevent_register_print_function(pevent,
process_is_writable_pte,
PEVENT_FUNC_ARG_INT,
"is_writable_pte",
PEVENT_FUNC_ARG_LONG,
PEVENT_FUNC_ARG_VOID);
return 0;
}
void PEVENT_PLUGIN_UNLOADER(struct pevent *pevent)
{
pevent_unregister_event_handler(pevent, -1, "kvm", "kvm_exit",
kvm_exit_handler, NULL);
pevent_unregister_event_handler(pevent, -1, "kvm", "kvm_emulate_insn",
kvm_emulate_insn_handler, NULL);
pevent_unregister_event_handler(pevent, -1, "kvm", "kvm_nested_vmexit",
kvm_nested_vmexit_handler, NULL);
pevent_unregister_event_handler(pevent, -1, "kvm", "kvm_nested_vmexit_inject",
kvm_nested_vmexit_inject_handler, NULL);
pevent_unregister_event_handler(pevent, -1, "kvmmmu", "kvm_mmu_get_page",
kvm_mmu_get_page_handler, NULL);
pevent_unregister_event_handler(pevent, -1, "kvmmmu", "kvm_mmu_sync_page",
kvm_mmu_print_role, NULL);
pevent_unregister_event_handler(pevent, -1,
"kvmmmu", "kvm_mmu_unsync_page",
kvm_mmu_print_role, NULL);
pevent_unregister_event_handler(pevent, -1, "kvmmmu", "kvm_mmu_zap_page",
kvm_mmu_print_role, NULL);
pevent_unregister_event_handler(pevent, -1, "kvmmmu",
"kvm_mmu_prepare_zap_page", kvm_mmu_print_role,
NULL);
pevent_unregister_print_function(pevent, process_is_writable_pte,
"is_writable_pte");
}
