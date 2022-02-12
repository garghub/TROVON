static int __init debug_alt(char *str)
{
debug_alternative = 1;
return 1;
}
static int __init setup_noreplace_smp(char *str)
{
noreplace_smp = 1;
return 1;
}
static int __init setup_noreplace_paravirt(char *str)
{
noreplace_paravirt = 1;
return 1;
}
void __init arch_init_ideal_nops(void)
{
switch (boot_cpu_data.x86_vendor) {
case X86_VENDOR_INTEL:
if (boot_cpu_data.x86 == 6 &&
boot_cpu_data.x86_model >= 0x0f &&
boot_cpu_data.x86_model != 0x1c &&
boot_cpu_data.x86_model != 0x26 &&
boot_cpu_data.x86_model != 0x27 &&
boot_cpu_data.x86_model < 0x30) {
ideal_nops = k8_nops;
} else if (boot_cpu_has(X86_FEATURE_NOPL)) {
ideal_nops = p6_nops;
} else {
#ifdef CONFIG_X86_64
ideal_nops = k8_nops;
#else
ideal_nops = intel_nops;
#endif
}
break;
case X86_VENDOR_AMD:
if (boot_cpu_data.x86 > 0xf) {
ideal_nops = p6_nops;
return;
}
default:
#ifdef CONFIG_X86_64
ideal_nops = k8_nops;
#else
if (boot_cpu_has(X86_FEATURE_K8))
ideal_nops = k8_nops;
else if (boot_cpu_has(X86_FEATURE_K7))
ideal_nops = k7_nops;
else
ideal_nops = intel_nops;
#endif
}
}
static void __init_or_module add_nops(void *insns, unsigned int len)
{
while (len > 0) {
unsigned int noplen = len;
if (noplen > ASM_NOP_MAX)
noplen = ASM_NOP_MAX;
memcpy(insns, ideal_nops[noplen], noplen);
insns += noplen;
len -= noplen;
}
}
static inline bool is_jmp(const u8 opcode)
{
return opcode == 0xeb || opcode == 0xe9;
}
static void __init_or_module
recompute_jump(struct alt_instr *a, u8 *orig_insn, u8 *repl_insn, u8 *insnbuf)
{
u8 *next_rip, *tgt_rip;
s32 n_dspl, o_dspl;
int repl_len;
if (a->replacementlen != 5)
return;
o_dspl = *(s32 *)(insnbuf + 1);
next_rip = repl_insn + a->replacementlen;
tgt_rip = next_rip + o_dspl;
n_dspl = tgt_rip - orig_insn;
DPRINTK("target RIP: %p, new_displ: 0x%x", tgt_rip, n_dspl);
if (tgt_rip - orig_insn >= 0) {
if (n_dspl - 2 <= 127)
goto two_byte_jmp;
else
goto five_byte_jmp;
} else {
if (((n_dspl - 2) & 0xff) == (n_dspl - 2))
goto two_byte_jmp;
else
goto five_byte_jmp;
}
two_byte_jmp:
n_dspl -= 2;
insnbuf[0] = 0xeb;
insnbuf[1] = (s8)n_dspl;
add_nops(insnbuf + 2, 3);
repl_len = 2;
goto done;
five_byte_jmp:
n_dspl -= 5;
insnbuf[0] = 0xe9;
*(s32 *)&insnbuf[1] = n_dspl;
repl_len = 5;
done:
DPRINTK("final displ: 0x%08x, JMP 0x%lx",
n_dspl, (unsigned long)orig_insn + n_dspl + repl_len);
}
static void __init_or_module noinline optimize_nops(struct alt_instr *a, u8 *instr)
{
unsigned long flags;
if (instr[0] != 0x90)
return;
local_irq_save(flags);
add_nops(instr + (a->instrlen - a->padlen), a->padlen);
local_irq_restore(flags);
DUMP_BYTES(instr, a->instrlen, "%p: [%d:%d) optimized NOPs: ",
instr, a->instrlen - a->padlen, a->padlen);
}
void __init_or_module noinline apply_alternatives(struct alt_instr *start,
struct alt_instr *end)
{
struct alt_instr *a;
u8 *instr, *replacement;
u8 insnbuf[MAX_PATCH_LEN];
DPRINTK("alt table %p -> %p", start, end);
for (a = start; a < end; a++) {
int insnbuf_sz = 0;
instr = (u8 *)&a->instr_offset + a->instr_offset;
replacement = (u8 *)&a->repl_offset + a->repl_offset;
BUG_ON(a->instrlen > sizeof(insnbuf));
BUG_ON(a->cpuid >= (NCAPINTS + NBUGINTS) * 32);
if (!boot_cpu_has(a->cpuid)) {
if (a->padlen > 1)
optimize_nops(a, instr);
continue;
}
DPRINTK("feat: %d*32+%d, old: (%p, len: %d), repl: (%p, len: %d), pad: %d",
a->cpuid >> 5,
a->cpuid & 0x1f,
instr, a->instrlen,
replacement, a->replacementlen, a->padlen);
DUMP_BYTES(instr, a->instrlen, "%p: old_insn: ", instr);
DUMP_BYTES(replacement, a->replacementlen, "%p: rpl_insn: ", replacement);
memcpy(insnbuf, replacement, a->replacementlen);
insnbuf_sz = a->replacementlen;
if (a->replacementlen == 5 && *insnbuf == 0xe8) {
*(s32 *)(insnbuf + 1) += replacement - instr;
DPRINTK("Fix CALL offset: 0x%x, CALL 0x%lx",
*(s32 *)(insnbuf + 1),
(unsigned long)instr + *(s32 *)(insnbuf + 1) + 5);
}
if (a->replacementlen && is_jmp(replacement[0]))
recompute_jump(a, instr, replacement, insnbuf);
if (a->instrlen > a->replacementlen) {
add_nops(insnbuf + a->replacementlen,
a->instrlen - a->replacementlen);
insnbuf_sz += a->instrlen - a->replacementlen;
}
DUMP_BYTES(insnbuf, insnbuf_sz, "%p: final_insn: ", instr);
text_poke_early(instr, insnbuf, insnbuf_sz);
}
}
static void alternatives_smp_lock(const s32 *start, const s32 *end,
u8 *text, u8 *text_end)
{
const s32 *poff;
mutex_lock(&text_mutex);
for (poff = start; poff < end; poff++) {
u8 *ptr = (u8 *)poff + *poff;
if (!*poff || ptr < text || ptr >= text_end)
continue;
if (*ptr == 0x3e)
text_poke(ptr, ((unsigned char []){0xf0}), 1);
}
mutex_unlock(&text_mutex);
}
static void alternatives_smp_unlock(const s32 *start, const s32 *end,
u8 *text, u8 *text_end)
{
const s32 *poff;
mutex_lock(&text_mutex);
for (poff = start; poff < end; poff++) {
u8 *ptr = (u8 *)poff + *poff;
if (!*poff || ptr < text || ptr >= text_end)
continue;
if (*ptr == 0xf0)
text_poke(ptr, ((unsigned char []){0x3E}), 1);
}
mutex_unlock(&text_mutex);
}
void __init_or_module alternatives_smp_module_add(struct module *mod,
char *name,
void *locks, void *locks_end,
void *text, void *text_end)
{
struct smp_alt_module *smp;
mutex_lock(&smp_alt);
if (!uniproc_patched)
goto unlock;
if (num_possible_cpus() == 1)
goto smp_unlock;
smp = kzalloc(sizeof(*smp), GFP_KERNEL);
if (NULL == smp)
goto unlock;
smp->mod = mod;
smp->name = name;
smp->locks = locks;
smp->locks_end = locks_end;
smp->text = text;
smp->text_end = text_end;
DPRINTK("locks %p -> %p, text %p -> %p, name %s\n",
smp->locks, smp->locks_end,
smp->text, smp->text_end, smp->name);
list_add_tail(&smp->next, &smp_alt_modules);
smp_unlock:
alternatives_smp_unlock(locks, locks_end, text, text_end);
unlock:
mutex_unlock(&smp_alt);
}
void __init_or_module alternatives_smp_module_del(struct module *mod)
{
struct smp_alt_module *item;
mutex_lock(&smp_alt);
list_for_each_entry(item, &smp_alt_modules, next) {
if (mod != item->mod)
continue;
list_del(&item->next);
kfree(item);
break;
}
mutex_unlock(&smp_alt);
}
void alternatives_enable_smp(void)
{
struct smp_alt_module *mod;
BUG_ON(num_possible_cpus() == 1);
mutex_lock(&smp_alt);
if (uniproc_patched) {
pr_info("switching to SMP code\n");
BUG_ON(num_online_cpus() != 1);
clear_cpu_cap(&boot_cpu_data, X86_FEATURE_UP);
clear_cpu_cap(&cpu_data(0), X86_FEATURE_UP);
list_for_each_entry(mod, &smp_alt_modules, next)
alternatives_smp_lock(mod->locks, mod->locks_end,
mod->text, mod->text_end);
uniproc_patched = false;
}
mutex_unlock(&smp_alt);
}
int alternatives_text_reserved(void *start, void *end)
{
struct smp_alt_module *mod;
const s32 *poff;
u8 *text_start = start;
u8 *text_end = end;
list_for_each_entry(mod, &smp_alt_modules, next) {
if (mod->text > text_end || mod->text_end < text_start)
continue;
for (poff = mod->locks; poff < mod->locks_end; poff++) {
const u8 *ptr = (const u8 *)poff + *poff;
if (text_start <= ptr && text_end > ptr)
return 1;
}
}
return 0;
}
void __init_or_module apply_paravirt(struct paravirt_patch_site *start,
struct paravirt_patch_site *end)
{
struct paravirt_patch_site *p;
char insnbuf[MAX_PATCH_LEN];
if (noreplace_paravirt)
return;
for (p = start; p < end; p++) {
unsigned int used;
BUG_ON(p->len > MAX_PATCH_LEN);
memcpy(insnbuf, p->instr, p->len);
used = pv_init_ops.patch(p->instrtype, p->clobbers, insnbuf,
(unsigned long)p->instr, p->len);
BUG_ON(used > p->len);
add_nops(insnbuf + used, p->len - used);
text_poke_early(p->instr, insnbuf, p->len);
}
}
void __init alternative_instructions(void)
{
stop_nmi();
apply_alternatives(__alt_instructions, __alt_instructions_end);
#ifdef CONFIG_SMP
if (!noreplace_smp && (num_present_cpus() == 1 || setup_max_cpus <= 1)) {
uniproc_patched = true;
alternatives_smp_module_add(NULL, "core kernel",
__smp_locks, __smp_locks_end,
_text, _etext);
}
if (!uniproc_patched || num_possible_cpus() == 1)
free_init_pages("SMP alternatives",
(unsigned long)__smp_locks,
(unsigned long)__smp_locks_end);
#endif
apply_paravirt(__parainstructions, __parainstructions_end);
restart_nmi();
alternatives_patched = 1;
}
void *__init_or_module text_poke_early(void *addr, const void *opcode,
size_t len)
{
unsigned long flags;
local_irq_save(flags);
memcpy(addr, opcode, len);
local_irq_restore(flags);
return addr;
}
void *text_poke(void *addr, const void *opcode, size_t len)
{
unsigned long flags;
char *vaddr;
struct page *pages[2];
int i;
if (!core_kernel_text((unsigned long)addr)) {
pages[0] = vmalloc_to_page(addr);
pages[1] = vmalloc_to_page(addr + PAGE_SIZE);
} else {
pages[0] = virt_to_page(addr);
WARN_ON(!PageReserved(pages[0]));
pages[1] = virt_to_page(addr + PAGE_SIZE);
}
BUG_ON(!pages[0]);
local_irq_save(flags);
set_fixmap(FIX_TEXT_POKE0, page_to_phys(pages[0]));
if (pages[1])
set_fixmap(FIX_TEXT_POKE1, page_to_phys(pages[1]));
vaddr = (char *)fix_to_virt(FIX_TEXT_POKE0);
memcpy(&vaddr[(unsigned long)addr & ~PAGE_MASK], opcode, len);
clear_fixmap(FIX_TEXT_POKE0);
if (pages[1])
clear_fixmap(FIX_TEXT_POKE1);
local_flush_tlb();
sync_core();
for (i = 0; i < len; i++)
BUG_ON(((char *)addr)[i] != ((char *)opcode)[i]);
local_irq_restore(flags);
return addr;
}
static void do_sync_core(void *info)
{
sync_core();
}
int poke_int3_handler(struct pt_regs *regs)
{
smp_rmb();
if (likely(!bp_patching_in_progress))
return 0;
if (user_mode(regs) || regs->ip != (unsigned long)bp_int3_addr)
return 0;
regs->ip = (unsigned long) bp_int3_handler;
return 1;
}
void *text_poke_bp(void *addr, const void *opcode, size_t len, void *handler)
{
unsigned char int3 = 0xcc;
bp_int3_handler = handler;
bp_int3_addr = (u8 *)addr + sizeof(int3);
bp_patching_in_progress = true;
smp_wmb();
text_poke(addr, &int3, sizeof(int3));
on_each_cpu(do_sync_core, NULL, 1);
if (len - sizeof(int3) > 0) {
text_poke((char *)addr + sizeof(int3),
(const char *) opcode + sizeof(int3),
len - sizeof(int3));
on_each_cpu(do_sync_core, NULL, 1);
}
text_poke(addr, opcode, sizeof(int3));
on_each_cpu(do_sync_core, NULL, 1);
bp_patching_in_progress = false;
return addr;
}
