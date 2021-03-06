static unsigned int count_relocs(const Elf32_Rela *rela, unsigned int num)
{
unsigned int i, r_info, r_addend, _count_relocs;
_count_relocs = 0;
r_info = 0;
r_addend = 0;
for (i = 0; i < num; i++)
if (ELF32_R_TYPE(rela[i].r_info) == R_PPC_REL24 &&
(r_info != ELF32_R_SYM(rela[i].r_info) ||
r_addend != rela[i].r_addend)) {
_count_relocs++;
r_info = ELF32_R_SYM(rela[i].r_info);
r_addend = rela[i].r_addend;
}
#ifdef CONFIG_DYNAMIC_FTRACE
_count_relocs++;
#endif
return _count_relocs;
}
static int relacmp(const void *_x, const void *_y)
{
const Elf32_Rela *x, *y;
y = (Elf32_Rela *)_x;
x = (Elf32_Rela *)_y;
if (x->r_info < y->r_info)
return -1;
else if (x->r_info > y->r_info)
return 1;
else if (x->r_addend < y->r_addend)
return -1;
else if (x->r_addend > y->r_addend)
return 1;
else
return 0;
}
static void relaswap(void *_x, void *_y, int size)
{
uint32_t *x, *y, tmp;
int i;
y = (uint32_t *)_x;
x = (uint32_t *)_y;
for (i = 0; i < sizeof(Elf32_Rela) / sizeof(uint32_t); i++) {
tmp = x[i];
x[i] = y[i];
y[i] = tmp;
}
}
static unsigned long get_plt_size(const Elf32_Ehdr *hdr,
const Elf32_Shdr *sechdrs,
const char *secstrings,
int is_init)
{
unsigned long ret = 0;
unsigned i;
for (i = 1; i < hdr->e_shnum; i++) {
if ((strstr(secstrings + sechdrs[i].sh_name, ".init") != 0)
!= is_init)
continue;
if (strstr(secstrings + sechdrs[i].sh_name, ".debug") != 0)
continue;
if (sechdrs[i].sh_type == SHT_RELA) {
pr_debug("Found relocations in section %u\n", i);
pr_debug("Ptr: %p. Number: %u\n",
(void *)hdr + sechdrs[i].sh_offset,
sechdrs[i].sh_size / sizeof(Elf32_Rela));
sort((void *)hdr + sechdrs[i].sh_offset,
sechdrs[i].sh_size / sizeof(Elf32_Rela),
sizeof(Elf32_Rela), relacmp, relaswap);
ret += count_relocs((void *)hdr
+ sechdrs[i].sh_offset,
sechdrs[i].sh_size
/ sizeof(Elf32_Rela))
* sizeof(struct ppc_plt_entry);
}
}
return ret;
}
int module_frob_arch_sections(Elf32_Ehdr *hdr,
Elf32_Shdr *sechdrs,
char *secstrings,
struct module *me)
{
unsigned int i;
for (i = 0; i < hdr->e_shnum; i++) {
if (strcmp(secstrings + sechdrs[i].sh_name, ".init.plt") == 0)
me->arch.init_plt_section = i;
else if (strcmp(secstrings + sechdrs[i].sh_name, ".plt") == 0)
me->arch.core_plt_section = i;
}
if (!me->arch.core_plt_section || !me->arch.init_plt_section) {
pr_err("Module doesn't contain .plt or .init.plt sections.\n");
return -ENOEXEC;
}
sechdrs[me->arch.core_plt_section].sh_size
= get_plt_size(hdr, sechdrs, secstrings, 0);
sechdrs[me->arch.init_plt_section].sh_size
= get_plt_size(hdr, sechdrs, secstrings, 1);
return 0;
}
static inline int entry_matches(struct ppc_plt_entry *entry, Elf32_Addr val)
{
if (entry->jump[0] == 0x3d800000 + ((val + 0x8000) >> 16)
&& entry->jump[1] == 0x398c0000 + (val & 0xffff))
return 1;
return 0;
}
static uint32_t do_plt_call(void *location,
Elf32_Addr val,
Elf32_Shdr *sechdrs,
struct module *mod)
{
struct ppc_plt_entry *entry;
pr_debug("Doing plt for call to 0x%x at 0x%x\n", val, (unsigned int)location);
if (location >= mod->core_layout.base
&& location < mod->core_layout.base + mod->core_layout.size)
entry = (void *)sechdrs[mod->arch.core_plt_section].sh_addr;
else
entry = (void *)sechdrs[mod->arch.init_plt_section].sh_addr;
while (entry->jump[0]) {
if (entry_matches(entry, val)) return (uint32_t)entry;
entry++;
}
entry->jump[0] = 0x3d800000+((val+0x8000)>>16);
entry->jump[1] = 0x398c0000 + (val&0xffff);
entry->jump[2] = 0x7d8903a6;
entry->jump[3] = 0x4e800420;
pr_debug("Initialized plt for 0x%x at %p\n", val, entry);
return (uint32_t)entry;
}
int apply_relocate_add(Elf32_Shdr *sechdrs,
const char *strtab,
unsigned int symindex,
unsigned int relsec,
struct module *module)
{
unsigned int i;
Elf32_Rela *rela = (void *)sechdrs[relsec].sh_addr;
Elf32_Sym *sym;
uint32_t *location;
uint32_t value;
pr_debug("Applying ADD relocate section %u to %u\n", relsec,
sechdrs[relsec].sh_info);
for (i = 0; i < sechdrs[relsec].sh_size / sizeof(*rela); i++) {
location = (void *)sechdrs[sechdrs[relsec].sh_info].sh_addr
+ rela[i].r_offset;
sym = (Elf32_Sym *)sechdrs[symindex].sh_addr
+ ELF32_R_SYM(rela[i].r_info);
value = sym->st_value + rela[i].r_addend;
switch (ELF32_R_TYPE(rela[i].r_info)) {
case R_PPC_ADDR32:
*(uint32_t *)location = value;
break;
case R_PPC_ADDR16_LO:
*(uint16_t *)location = value;
break;
case R_PPC_ADDR16_HI:
*(uint16_t *)location = (value >> 16);
break;
case R_PPC_ADDR16_HA:
*(uint16_t *)location = (value + 0x8000) >> 16;
break;
case R_PPC_REL24:
if ((int)(value - (uint32_t)location) < -0x02000000
|| (int)(value - (uint32_t)location) >= 0x02000000)
value = do_plt_call(location, value,
sechdrs, module);
pr_debug("REL24 value = %08X. location = %08X\n",
value, (uint32_t)location);
pr_debug("Location before: %08X.\n",
*(uint32_t *)location);
*(uint32_t *)location
= (*(uint32_t *)location & ~0x03fffffc)
| ((value - (uint32_t)location)
& 0x03fffffc);
pr_debug("Location after: %08X.\n",
*(uint32_t *)location);
pr_debug("ie. jump to %08X+%08X = %08X\n",
*(uint32_t *)location & 0x03fffffc,
(uint32_t)location,
(*(uint32_t *)location & 0x03fffffc)
+ (uint32_t)location);
break;
case R_PPC_REL32:
*(uint32_t *)location = value - (uint32_t)location;
break;
default:
pr_err("%s: unknown ADD relocation: %u\n",
module->name,
ELF32_R_TYPE(rela[i].r_info));
return -ENOEXEC;
}
}
#ifdef CONFIG_DYNAMIC_FTRACE
module->arch.tramp =
do_plt_call(module->core_layout.base,
(unsigned long)ftrace_caller,
sechdrs, module);
#endif
return 0;
}
