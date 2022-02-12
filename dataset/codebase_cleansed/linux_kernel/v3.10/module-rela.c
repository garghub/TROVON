static int apply_r_mips_32_rela(struct module *me, u32 *location, Elf_Addr v)
{
*location = v;
return 0;
}
static int apply_r_mips_26_rela(struct module *me, u32 *location, Elf_Addr v)
{
if (v % 4) {
pr_err("module %s: dangerous R_MIPS_26 RELArelocation\n",
me->name);
return -ENOEXEC;
}
if ((v & 0xf0000000) != (((unsigned long)location + 4) & 0xf0000000)) {
printk(KERN_ERR
"module %s: relocation overflow\n",
me->name);
return -ENOEXEC;
}
*location = (*location & ~0x03ffffff) | ((v >> 2) & 0x03ffffff);
return 0;
}
static int apply_r_mips_hi16_rela(struct module *me, u32 *location, Elf_Addr v)
{
*location = (*location & 0xffff0000) |
((((long long) v + 0x8000LL) >> 16) & 0xffff);
return 0;
}
static int apply_r_mips_lo16_rela(struct module *me, u32 *location, Elf_Addr v)
{
*location = (*location & 0xffff0000) | (v & 0xffff);
return 0;
}
static int apply_r_mips_64_rela(struct module *me, u32 *location, Elf_Addr v)
{
*(Elf_Addr *)location = v;
return 0;
}
static int apply_r_mips_higher_rela(struct module *me, u32 *location,
Elf_Addr v)
{
*location = (*location & 0xffff0000) |
((((long long) v + 0x80008000LL) >> 32) & 0xffff);
return 0;
}
static int apply_r_mips_highest_rela(struct module *me, u32 *location,
Elf_Addr v)
{
*location = (*location & 0xffff0000) |
((((long long) v + 0x800080008000LL) >> 48) & 0xffff);
return 0;
}
int apply_relocate_add(Elf_Shdr *sechdrs, const char *strtab,
unsigned int symindex, unsigned int relsec,
struct module *me)
{
Elf_Mips_Rela *rel = (void *) sechdrs[relsec].sh_addr;
Elf_Sym *sym;
u32 *location;
unsigned int i;
Elf_Addr v;
int res;
pr_debug("Applying relocate section %u to %u\n", relsec,
sechdrs[relsec].sh_info);
for (i = 0; i < sechdrs[relsec].sh_size / sizeof(*rel); i++) {
location = (void *)sechdrs[sechdrs[relsec].sh_info].sh_addr
+ rel[i].r_offset;
sym = (Elf_Sym *)sechdrs[symindex].sh_addr
+ ELF_MIPS_R_SYM(rel[i]);
if (IS_ERR_VALUE(sym->st_value)) {
if (ELF_ST_BIND(sym->st_info) == STB_WEAK)
continue;
printk(KERN_WARNING "%s: Unknown symbol %s\n",
me->name, strtab + sym->st_name);
return -ENOENT;
}
v = sym->st_value + rel[i].r_addend;
res = reloc_handlers_rela[ELF_MIPS_R_TYPE(rel[i])](me, location, v);
if (res)
return res;
}
return 0;
}
