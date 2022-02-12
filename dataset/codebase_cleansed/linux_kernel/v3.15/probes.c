void __init find_str_pc_offset(void)
{
int addr, scratch, ret;
__asm__ (
"sub %[ret], pc, #4 \n\t"
"str pc, %[addr] \n\t"
"ldr %[scr], %[addr] \n\t"
"sub %[ret], %[scr], %[ret] \n\t"
: [ret] "=r" (ret), [scr] "=r" (scratch), [addr] "+m" (addr));
str_pc_offset = ret;
}
void __init test_load_write_pc_interworking(void)
{
int arch = cpu_architecture();
BUG_ON(arch == CPU_ARCH_UNKNOWN);
load_write_pc_interworks = arch >= CPU_ARCH_ARMv5T;
}
void __init test_alu_write_pc_interworking(void)
{
int arch = cpu_architecture();
BUG_ON(arch == CPU_ARCH_UNKNOWN);
alu_write_pc_interworks = arch >= CPU_ARCH_ARMv7;
}
void __init arm_probes_decode_init(void)
{
find_str_pc_offset();
test_load_write_pc_interworking();
test_alu_write_pc_interworking();
}
static unsigned long __kprobes __check_eq(unsigned long cpsr)
{
return cpsr & PSR_Z_BIT;
}
static unsigned long __kprobes __check_ne(unsigned long cpsr)
{
return (~cpsr) & PSR_Z_BIT;
}
static unsigned long __kprobes __check_cs(unsigned long cpsr)
{
return cpsr & PSR_C_BIT;
}
static unsigned long __kprobes __check_cc(unsigned long cpsr)
{
return (~cpsr) & PSR_C_BIT;
}
static unsigned long __kprobes __check_mi(unsigned long cpsr)
{
return cpsr & PSR_N_BIT;
}
static unsigned long __kprobes __check_pl(unsigned long cpsr)
{
return (~cpsr) & PSR_N_BIT;
}
static unsigned long __kprobes __check_vs(unsigned long cpsr)
{
return cpsr & PSR_V_BIT;
}
static unsigned long __kprobes __check_vc(unsigned long cpsr)
{
return (~cpsr) & PSR_V_BIT;
}
static unsigned long __kprobes __check_hi(unsigned long cpsr)
{
cpsr &= ~(cpsr >> 1);
return cpsr & PSR_C_BIT;
}
static unsigned long __kprobes __check_ls(unsigned long cpsr)
{
cpsr &= ~(cpsr >> 1);
return (~cpsr) & PSR_C_BIT;
}
static unsigned long __kprobes __check_ge(unsigned long cpsr)
{
cpsr ^= (cpsr << 3);
return (~cpsr) & PSR_N_BIT;
}
static unsigned long __kprobes __check_lt(unsigned long cpsr)
{
cpsr ^= (cpsr << 3);
return cpsr & PSR_N_BIT;
}
static unsigned long __kprobes __check_gt(unsigned long cpsr)
{
unsigned long temp = cpsr ^ (cpsr << 3);
temp |= (cpsr << 1);
return (~temp) & PSR_N_BIT;
}
static unsigned long __kprobes __check_le(unsigned long cpsr)
{
unsigned long temp = cpsr ^ (cpsr << 3);
temp |= (cpsr << 1);
return temp & PSR_N_BIT;
}
static unsigned long __kprobes __check_al(unsigned long cpsr)
{
return true;
}
void __kprobes probes_simulate_nop(probes_opcode_t opcode,
struct arch_probes_insn *asi,
struct pt_regs *regs)
{
}
void __kprobes probes_emulate_none(probes_opcode_t opcode,
struct arch_probes_insn *asi,
struct pt_regs *regs)
{
asi->insn_fn();
}
static probes_opcode_t __kprobes
prepare_emulated_insn(probes_opcode_t insn, struct arch_probes_insn *asi,
bool thumb)
{
#ifdef CONFIG_THUMB2_KERNEL
if (thumb) {
u16 *thumb_insn = (u16 *)asi->insn;
thumb_insn[1] = __opcode_to_mem_thumb16(0x4770);
thumb_insn[2] = __opcode_to_mem_thumb16(0x4770);
return insn;
}
asi->insn[1] = __opcode_to_mem_arm(0xe12fff1e);
#else
asi->insn[1] = __opcode_to_mem_arm(0xe1a0f00e);
#endif
if (insn < 0xe0000000)
insn = (insn | 0xe0000000) & ~0x10000000;
return insn;
}
static void __kprobes
set_emulated_insn(probes_opcode_t insn, struct arch_probes_insn *asi,
bool thumb)
{
#ifdef CONFIG_THUMB2_KERNEL
if (thumb) {
u16 *ip = (u16 *)asi->insn;
if (is_wide_instruction(insn))
*ip++ = __opcode_to_mem_thumb16(insn >> 16);
*ip++ = __opcode_to_mem_thumb16(insn);
return;
}
#endif
asi->insn[0] = __opcode_to_mem_arm(insn);
}
static bool __kprobes decode_regs(probes_opcode_t *pinsn, u32 regs, bool modify)
{
probes_opcode_t insn = *pinsn;
probes_opcode_t mask = 0xf;
for (; regs != 0; regs >>= 4, mask <<= 4) {
probes_opcode_t new_bits = INSN_NEW_BITS;
switch (regs & 0xf) {
case REG_TYPE_NONE:
continue;
case REG_TYPE_ANY:
break;
case REG_TYPE_SAMEAS16:
new_bits = INSN_SAMEAS16_BITS;
break;
case REG_TYPE_SP:
if ((insn ^ 0xdddddddd) & mask)
goto reject;
break;
case REG_TYPE_PC:
if ((insn ^ 0xffffffff) & mask)
goto reject;
break;
case REG_TYPE_NOSP:
if (((insn ^ 0xdddddddd) & mask) == 0)
goto reject;
break;
case REG_TYPE_NOSPPC:
case REG_TYPE_NOSPPCX:
if (((insn ^ 0xdddddddd) & 0xdddddddd & mask) == 0)
goto reject;
break;
case REG_TYPE_NOPCWB:
if (!is_writeback(insn))
break;
case REG_TYPE_NOPC:
case REG_TYPE_NOPCX:
if (((insn ^ 0xffffffff) & mask) == 0)
goto reject;
break;
}
insn &= ~mask;
insn |= new_bits & mask;
}
if (modify)
*pinsn = insn;
return true;
reject:
return false;
}
int __kprobes
probes_decode_insn(probes_opcode_t insn, struct arch_probes_insn *asi,
const union decode_item *table, bool thumb,
bool emulate, const union decode_action *actions)
{
const struct decode_header *h = (struct decode_header *)table;
const struct decode_header *next;
bool matched = false;
if (emulate)
insn = prepare_emulated_insn(insn, asi, thumb);
for (;; h = next) {
enum decode_type type = h->type_regs.bits & DECODE_TYPE_MASK;
u32 regs = h->type_regs.bits >> DECODE_TYPE_BITS;
if (type == DECODE_TYPE_END)
return INSN_REJECTED;
next = (struct decode_header *)
((uintptr_t)h + decode_struct_sizes[type]);
if (!matched && (insn & h->mask.bits) != h->value.bits)
continue;
if (!decode_regs(&insn, regs, emulate))
return INSN_REJECTED;
switch (type) {
case DECODE_TYPE_TABLE: {
struct decode_table *d = (struct decode_table *)h;
next = (struct decode_header *)d->table.table;
break;
}
case DECODE_TYPE_CUSTOM: {
struct decode_custom *d = (struct decode_custom *)h;
return actions[d->decoder.action].decoder(insn, asi, h);
}
case DECODE_TYPE_SIMULATE: {
struct decode_simulate *d = (struct decode_simulate *)h;
asi->insn_handler = actions[d->handler.action].handler;
return INSN_GOOD_NO_SLOT;
}
case DECODE_TYPE_EMULATE: {
struct decode_emulate *d = (struct decode_emulate *)h;
if (!emulate)
return actions[d->handler.action].decoder(insn,
asi, h);
asi->insn_handler = actions[d->handler.action].handler;
set_emulated_insn(insn, asi, thumb);
return INSN_GOOD;
}
case DECODE_TYPE_OR:
matched = true;
break;
case DECODE_TYPE_REJECT:
default:
return INSN_REJECTED;
}
}
}
