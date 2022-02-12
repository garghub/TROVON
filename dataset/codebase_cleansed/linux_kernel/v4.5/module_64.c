static func_desc_t func_desc(unsigned long addr)
{
return addr;
}
static unsigned long func_addr(unsigned long addr)
{
return addr;
}
static unsigned long stub_func_addr(func_desc_t func)
{
return func;
}
static unsigned int local_entry_offset(const Elf64_Sym *sym)
{
return PPC64_LOCAL_ENTRY_OFFSET(sym->st_other);
}
static func_desc_t func_desc(unsigned long addr)
{
return *(struct ppc64_opd_entry *)addr;
}
static unsigned long func_addr(unsigned long addr)
{
return func_desc(addr).funcaddr;
}
static unsigned long stub_func_addr(func_desc_t func)
{
return func.funcaddr;
}
static unsigned int local_entry_offset(const Elf64_Sym *sym)
{
return 0;
}
bool is_module_trampoline(u32 *p)
{
unsigned int i;
u32 insns[ARRAY_SIZE(ppc64_stub_insns)];
BUILD_BUG_ON(sizeof(ppc64_stub_insns) != sizeof(ppc64_stub_mask));
if (probe_kernel_read(insns, p, sizeof(insns)))
return -EFAULT;
for (i = 0; i < ARRAY_SIZE(ppc64_stub_insns); i++) {
u32 insna = insns[i];
u32 insnb = ppc64_stub_insns[i];
u32 mask = ppc64_stub_mask[i];
if ((insna & mask) != (insnb & mask))
return false;
}
return true;
}
int module_trampoline_target(struct module *mod, u32 *trampoline,
unsigned long *target)
{
u32 buf[2];
u16 upper, lower;
long offset;
void *toc_entry;
if (probe_kernel_read(buf, trampoline, sizeof(buf)))
return -EFAULT;
upper = buf[0] & 0xffff;
lower = buf[1] & 0xffff;
offset = ((short)upper << 16) + (short)lower;
toc_entry = (void *)mod->arch.toc + offset + 32;
if (probe_kernel_read(target, toc_entry, sizeof(*target)))
return -EFAULT;
return 0;
}
static unsigned int count_relocs(const Elf64_Rela *rela, unsigned int num)
{
unsigned int i, r_info, r_addend, _count_relocs;
_count_relocs = 0;
r_info = 0;
r_addend = 0;
for (i = 0; i < num; i++)
if (ELF64_R_TYPE(rela[i].r_info) == R_PPC_REL24 &&
(r_info != ELF64_R_SYM(rela[i].r_info) ||
r_addend != rela[i].r_addend)) {
_count_relocs++;
r_info = ELF64_R_SYM(rela[i].r_info);
r_addend = rela[i].r_addend;
}
return _count_relocs;
}
static int relacmp(const void *_x, const void *_y)
{
const Elf64_Rela *x, *y;
y = (Elf64_Rela *)_x;
x = (Elf64_Rela *)_y;
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
uint64_t *x, *y, tmp;
int i;
y = (uint64_t *)_x;
x = (uint64_t *)_y;
for (i = 0; i < sizeof(Elf64_Rela) / sizeof(uint64_t); i++) {
tmp = x[i];
x[i] = y[i];
y[i] = tmp;
}
}
static unsigned long get_stubs_size(const Elf64_Ehdr *hdr,
const Elf64_Shdr *sechdrs)
{
unsigned long relocs = 1;
unsigned i;
for (i = 1; i < hdr->e_shnum; i++) {
if (sechdrs[i].sh_type == SHT_RELA) {
pr_debug("Found relocations in section %u\n", i);
pr_debug("Ptr: %p. Number: %Lu\n",
(void *)sechdrs[i].sh_addr,
sechdrs[i].sh_size / sizeof(Elf64_Rela));
sort((void *)sechdrs[i].sh_addr,
sechdrs[i].sh_size / sizeof(Elf64_Rela),
sizeof(Elf64_Rela), relacmp, relaswap);
relocs += count_relocs((void *)sechdrs[i].sh_addr,
sechdrs[i].sh_size
/ sizeof(Elf64_Rela));
}
}
#ifdef CONFIG_DYNAMIC_FTRACE
relocs++;
#endif
pr_debug("Looks like a total of %lu stubs, max\n", relocs);
return relocs * sizeof(struct ppc64_stub_entry);
}
static void dedotify_versions(struct modversion_info *vers,
unsigned long size)
{
struct modversion_info *end;
for (end = (void *)vers + size; vers < end; vers++)
if (vers->name[0] == '.') {
memmove(vers->name, vers->name+1, strlen(vers->name));
#ifdef ARCH_RELOCATES_KCRCTAB
if (!strcmp(vers->name, "TOC."))
vers->crc = -(unsigned long)reloc_start;
#endif
}
}
static void dedotify(Elf64_Sym *syms, unsigned int numsyms, char *strtab)
{
unsigned int i;
for (i = 1; i < numsyms; i++) {
if (syms[i].st_shndx == SHN_UNDEF) {
char *name = strtab + syms[i].st_name;
if (name[0] == '.') {
if (strcmp(name+1, "TOC.") == 0)
syms[i].st_shndx = SHN_ABS;
syms[i].st_name++;
}
}
}
}
static Elf64_Sym *find_dot_toc(Elf64_Shdr *sechdrs,
const char *strtab,
unsigned int symindex)
{
unsigned int i, numsyms;
Elf64_Sym *syms;
syms = (Elf64_Sym *)sechdrs[symindex].sh_addr;
numsyms = sechdrs[symindex].sh_size / sizeof(Elf64_Sym);
for (i = 1; i < numsyms; i++) {
if (syms[i].st_shndx == SHN_ABS
&& strcmp(strtab + syms[i].st_name, "TOC.") == 0)
return &syms[i];
}
return NULL;
}
int module_frob_arch_sections(Elf64_Ehdr *hdr,
Elf64_Shdr *sechdrs,
char *secstrings,
struct module *me)
{
unsigned int i;
for (i = 1; i < hdr->e_shnum; i++) {
char *p;
if (strcmp(secstrings + sechdrs[i].sh_name, ".stubs") == 0)
me->arch.stubs_section = i;
else if (strcmp(secstrings + sechdrs[i].sh_name, ".toc") == 0)
me->arch.toc_section = i;
else if (strcmp(secstrings+sechdrs[i].sh_name,"__versions")==0)
dedotify_versions((void *)hdr + sechdrs[i].sh_offset,
sechdrs[i].sh_size);
while ((p = strstr(secstrings + sechdrs[i].sh_name, ".init")))
p[0] = '_';
if (sechdrs[i].sh_type == SHT_SYMTAB)
dedotify((void *)hdr + sechdrs[i].sh_offset,
sechdrs[i].sh_size / sizeof(Elf64_Sym),
(void *)hdr
+ sechdrs[sechdrs[i].sh_link].sh_offset);
}
if (!me->arch.stubs_section) {
pr_err("%s: doesn't contain .stubs.\n", me->name);
return -ENOEXEC;
}
if (!me->arch.toc_section)
me->arch.toc_section = me->arch.stubs_section;
sechdrs[me->arch.stubs_section].sh_size = get_stubs_size(hdr, sechdrs);
return 0;
}
static inline unsigned long my_r2(Elf64_Shdr *sechdrs, struct module *me)
{
return sechdrs[me->arch.toc_section].sh_addr + 0x8000;
}
static inline int create_stub(Elf64_Shdr *sechdrs,
struct ppc64_stub_entry *entry,
unsigned long addr,
struct module *me)
{
long reladdr;
memcpy(entry->jump, ppc64_stub_insns, sizeof(ppc64_stub_insns));
reladdr = (unsigned long)entry - my_r2(sechdrs, me);
if (reladdr > 0x7FFFFFFF || reladdr < -(0x80000000L)) {
pr_err("%s: Address %p of stub out of range of %p.\n",
me->name, (void *)reladdr, (void *)my_r2);
return 0;
}
pr_debug("Stub %p get data from reladdr %li\n", entry, reladdr);
entry->jump[0] |= PPC_HA(reladdr);
entry->jump[1] |= PPC_LO(reladdr);
entry->funcdata = func_desc(addr);
return 1;
}
static unsigned long stub_for_addr(Elf64_Shdr *sechdrs,
unsigned long addr,
struct module *me)
{
struct ppc64_stub_entry *stubs;
unsigned int i, num_stubs;
num_stubs = sechdrs[me->arch.stubs_section].sh_size / sizeof(*stubs);
stubs = (void *)sechdrs[me->arch.stubs_section].sh_addr;
for (i = 0; stub_func_addr(stubs[i].funcdata); i++) {
BUG_ON(i >= num_stubs);
if (stub_func_addr(stubs[i].funcdata) == func_addr(addr))
return (unsigned long)&stubs[i];
}
if (!create_stub(sechdrs, &stubs[i], addr, me))
return 0;
return (unsigned long)&stubs[i];
}
static int restore_r2(u32 *instruction, struct module *me)
{
if (*instruction != PPC_INST_NOP) {
pr_err("%s: Expect noop after relocate, got %08x\n",
me->name, *instruction);
return 0;
}
*instruction = 0xe8410000 | R2_STACK_OFFSET;
return 1;
}
int apply_relocate_add(Elf64_Shdr *sechdrs,
const char *strtab,
unsigned int symindex,
unsigned int relsec,
struct module *me)
{
unsigned int i;
Elf64_Rela *rela = (void *)sechdrs[relsec].sh_addr;
Elf64_Sym *sym;
unsigned long *location;
unsigned long value;
pr_debug("Applying ADD relocate section %u to %u\n", relsec,
sechdrs[relsec].sh_info);
if (!me->arch.toc_fixed) {
sym = find_dot_toc(sechdrs, strtab, symindex);
if (sym)
sym->st_value = my_r2(sechdrs, me);
me->arch.toc_fixed = true;
}
for (i = 0; i < sechdrs[relsec].sh_size / sizeof(*rela); i++) {
location = (void *)sechdrs[sechdrs[relsec].sh_info].sh_addr
+ rela[i].r_offset;
sym = (Elf64_Sym *)sechdrs[symindex].sh_addr
+ ELF64_R_SYM(rela[i].r_info);
pr_debug("RELOC at %p: %li-type as %s (0x%lx) + %li\n",
location, (long)ELF64_R_TYPE(rela[i].r_info),
strtab + sym->st_name, (unsigned long)sym->st_value,
(long)rela[i].r_addend);
value = sym->st_value + rela[i].r_addend;
switch (ELF64_R_TYPE(rela[i].r_info)) {
case R_PPC64_ADDR32:
*(u32 *)location = value;
break;
case R_PPC64_ADDR64:
*(unsigned long *)location = value;
break;
case R_PPC64_TOC:
*(unsigned long *)location = my_r2(sechdrs, me);
break;
case R_PPC64_TOC16:
value -= my_r2(sechdrs, me);
if (value + 0x8000 > 0xffff) {
pr_err("%s: bad TOC16 relocation (0x%lx)\n",
me->name, value);
return -ENOEXEC;
}
*((uint16_t *) location)
= (*((uint16_t *) location) & ~0xffff)
| (value & 0xffff);
break;
case R_PPC64_TOC16_LO:
value -= my_r2(sechdrs, me);
*((uint16_t *) location)
= (*((uint16_t *) location) & ~0xffff)
| (value & 0xffff);
break;
case R_PPC64_TOC16_DS:
value -= my_r2(sechdrs, me);
if ((value & 3) != 0 || value + 0x8000 > 0xffff) {
pr_err("%s: bad TOC16_DS relocation (0x%lx)\n",
me->name, value);
return -ENOEXEC;
}
*((uint16_t *) location)
= (*((uint16_t *) location) & ~0xfffc)
| (value & 0xfffc);
break;
case R_PPC64_TOC16_LO_DS:
value -= my_r2(sechdrs, me);
if ((value & 3) != 0) {
pr_err("%s: bad TOC16_LO_DS relocation (0x%lx)\n",
me->name, value);
return -ENOEXEC;
}
*((uint16_t *) location)
= (*((uint16_t *) location) & ~0xfffc)
| (value & 0xfffc);
break;
case R_PPC64_TOC16_HA:
value -= my_r2(sechdrs, me);
value = ((value + 0x8000) >> 16);
*((uint16_t *) location)
= (*((uint16_t *) location) & ~0xffff)
| (value & 0xffff);
break;
case R_PPC_REL24:
if (sym->st_shndx == SHN_UNDEF) {
value = stub_for_addr(sechdrs, value, me);
if (!value)
return -ENOENT;
if (!restore_r2((u32 *)location + 1, me))
return -ENOEXEC;
} else
value += local_entry_offset(sym);
value -= (unsigned long)location;
if (value + 0x2000000 > 0x3ffffff || (value & 3) != 0){
pr_err("%s: REL24 %li out of range!\n",
me->name, (long int)value);
return -ENOEXEC;
}
*(uint32_t *)location
= (*(uint32_t *)location & ~0x03fffffc)
| (value & 0x03fffffc);
break;
case R_PPC64_REL64:
*location = value - (unsigned long)location;
break;
case R_PPC64_TOCSAVE:
break;
case R_PPC64_ENTRY:
value = my_r2(sechdrs, me) - (unsigned long)location;
if (value + 0x80008000 > 0xffffffff)
break;
if ((((uint32_t *)location)[0] & ~0xfffc)
!= 0xe84c0000)
break;
if (((uint32_t *)location)[1] != 0x7c426214)
break;
((uint32_t *)location)[0] = 0x3c4c0000 + PPC_HA(value);
((uint32_t *)location)[1] = 0x38420000 + PPC_LO(value);
break;
case R_PPC64_REL16_HA:
value -= (unsigned long)location;
value = ((value + 0x8000) >> 16);
*((uint16_t *) location)
= (*((uint16_t *) location) & ~0xffff)
| (value & 0xffff);
break;
case R_PPC64_REL16_LO:
value -= (unsigned long)location;
*((uint16_t *) location)
= (*((uint16_t *) location) & ~0xffff)
| (value & 0xffff);
break;
default:
pr_err("%s: Unknown ADD relocation: %lu\n",
me->name,
(unsigned long)ELF64_R_TYPE(rela[i].r_info));
return -ENOEXEC;
}
}
#ifdef CONFIG_DYNAMIC_FTRACE
me->arch.toc = my_r2(sechdrs, me);
me->arch.tramp = stub_for_addr(sechdrs,
(unsigned long)ftrace_caller,
me);
#endif
return 0;
}
