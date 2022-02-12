static int __init bootonly(char *str)
{
smp_alt_once = 1;
return 1;
}
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
void __init_or_module apply_alternatives(struct alt_instr *start,
struct alt_instr *end)
{
struct alt_instr *a;
u8 *instr, *replacement;
u8 insnbuf[MAX_PATCH_LEN];
DPRINTK("%s: alt table %p -> %p\n", __func__, start, end);
for (a = start; a < end; a++) {
instr = (u8 *)&a->instr_offset + a->instr_offset;
replacement = (u8 *)&a->repl_offset + a->repl_offset;
BUG_ON(a->replacementlen > a->instrlen);
BUG_ON(a->instrlen > sizeof(insnbuf));
BUG_ON(a->cpuid >= NCAPINTS*32);
if (!boot_cpu_has(a->cpuid))
continue;
memcpy(insnbuf, replacement, a->replacementlen);
if (*insnbuf == 0xe8 && a->replacementlen == 5)
*(s32 *)(insnbuf + 1) += replacement - instr;
add_nops(insnbuf + a->replacementlen,
a->instrlen - a->replacementlen);
text_poke_early(instr, insnbuf, a->instrlen);
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
};
mutex_unlock(&text_mutex);
}
static void alternatives_smp_unlock(const s32 *start, const s32 *end,
u8 *text, u8 *text_end)
{
const s32 *poff;
if (noreplace_smp)
return;
mutex_lock(&text_mutex);
for (poff = start; poff < end; poff++) {
u8 *ptr = (u8 *)poff + *poff;
if (!*poff || ptr < text || ptr >= text_end)
continue;
if (*ptr == 0xf0)
text_poke(ptr, ((unsigned char []){0x3E}), 1);
};
mutex_unlock(&text_mutex);
}
void __init_or_module alternatives_smp_module_add(struct module *mod,
char *name,
void *locks, void *locks_end,
void *text, void *text_end)
{
struct smp_alt_module *smp;
if (noreplace_smp)
return;
if (smp_alt_once) {
if (boot_cpu_has(X86_FEATURE_UP))
alternatives_smp_unlock(locks, locks_end,
text, text_end);
return;
}
smp = kzalloc(sizeof(*smp), GFP_KERNEL);
if (NULL == smp)
return;
smp->mod = mod;
smp->name = name;
smp->locks = locks;
smp->locks_end = locks_end;
smp->text = text;
smp->text_end = text_end;
DPRINTK("%s: locks %p -> %p, text %p -> %p, name %s\n",
__func__, smp->locks, smp->locks_end,
smp->text, smp->text_end, smp->name);
mutex_lock(&smp_alt);
list_add_tail(&smp->next, &smp_alt_modules);
if (boot_cpu_has(X86_FEATURE_UP))
alternatives_smp_unlock(smp->locks, smp->locks_end,
smp->text, smp->text_end);
mutex_unlock(&smp_alt);
}
void __init_or_module alternatives_smp_module_del(struct module *mod)
{
struct smp_alt_module *item;
if (smp_alt_once || noreplace_smp)
return;
mutex_lock(&smp_alt);
list_for_each_entry(item, &smp_alt_modules, next) {
if (mod != item->mod)
continue;
list_del(&item->next);
mutex_unlock(&smp_alt);
DPRINTK("%s: %s\n", __func__, item->name);
kfree(item);
return;
}
mutex_unlock(&smp_alt);
}
void alternatives_smp_switch(int smp)
{
struct smp_alt_module *mod;
#ifdef CONFIG_LOCKDEP
pr_info("lockdep: fixing up alternatives\n");
#endif
if (noreplace_smp || smp_alt_once || skip_smp_alternatives)
return;
BUG_ON(!smp && (num_online_cpus() > 1));
mutex_lock(&smp_alt);
if (smp == smp_mode) {
} else if (smp) {
pr_info("switching to SMP code\n");
clear_cpu_cap(&boot_cpu_data, X86_FEATURE_UP);
clear_cpu_cap(&cpu_data(0), X86_FEATURE_UP);
list_for_each_entry(mod, &smp_alt_modules, next)
alternatives_smp_lock(mod->locks, mod->locks_end,
mod->text, mod->text_end);
} else {
pr_info("switching to UP code\n");
set_cpu_cap(&boot_cpu_data, X86_FEATURE_UP);
set_cpu_cap(&cpu_data(0), X86_FEATURE_UP);
list_for_each_entry(mod, &smp_alt_modules, next)
alternatives_smp_unlock(mod->locks, mod->locks_end,
mod->text, mod->text_end);
}
smp_mode = smp;
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
#ifdef CONFIG_HOTPLUG_CPU
if (num_possible_cpus() < 2)
smp_alt_once = 1;
#endif
#ifdef CONFIG_SMP
if (smp_alt_once) {
if (1 == num_possible_cpus()) {
pr_info("switching to UP code\n");
set_cpu_cap(&boot_cpu_data, X86_FEATURE_UP);
set_cpu_cap(&cpu_data(0), X86_FEATURE_UP);
alternatives_smp_unlock(__smp_locks, __smp_locks_end,
_text, _etext);
}
} else {
alternatives_smp_module_add(NULL, "core kernel",
__smp_locks, __smp_locks_end,
_text, _etext);
if (num_present_cpus() == 1 || setup_max_cpus <= 1)
alternatives_smp_switch(0);
}
#endif
apply_paravirt(__parainstructions, __parainstructions_end);
if (smp_alt_once)
free_init_pages("SMP alternatives",
(unsigned long)__smp_locks,
(unsigned long)__smp_locks_end);
restart_nmi();
}
void *__init_or_module text_poke_early(void *addr, const void *opcode,
size_t len)
{
unsigned long flags;
local_irq_save(flags);
memcpy(addr, opcode, len);
sync_core();
local_irq_restore(flags);
return addr;
}
void *__kprobes text_poke(void *addr, const void *opcode, size_t len)
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
static int __kprobes stop_machine_text_poke(void *data)
{
struct text_poke_params *tpp = data;
struct text_poke_param *p;
int i;
if (atomic_xchg(&stop_machine_first, 0)) {
for (i = 0; i < tpp->nparams; i++) {
p = &tpp->params[i];
text_poke(p->addr, p->opcode, p->len);
}
smp_wmb();
wrote_text = 1;
} else {
while (!wrote_text)
cpu_relax();
smp_mb();
}
for (i = 0; i < tpp->nparams; i++) {
p = &tpp->params[i];
flush_icache_range((unsigned long)p->addr,
(unsigned long)p->addr + p->len);
}
sync_core();
return 0;
}
void *__kprobes text_poke_smp(void *addr, const void *opcode, size_t len)
{
struct text_poke_params tpp;
struct text_poke_param p;
p.addr = addr;
p.opcode = opcode;
p.len = len;
tpp.params = &p;
tpp.nparams = 1;
atomic_set(&stop_machine_first, 1);
wrote_text = 0;
__stop_machine(stop_machine_text_poke, (void *)&tpp, cpu_online_mask);
return addr;
}
void __kprobes text_poke_smp_batch(struct text_poke_param *params, int n)
{
struct text_poke_params tpp = {.params = params, .nparams = n};
atomic_set(&stop_machine_first, 1);
wrote_text = 0;
__stop_machine(stop_machine_text_poke, (void *)&tpp, cpu_online_mask);
}
