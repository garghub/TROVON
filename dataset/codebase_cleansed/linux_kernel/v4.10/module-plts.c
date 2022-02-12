u64 module_emit_plt_entry(struct module *mod, const Elf64_Rela *rela,
Elf64_Sym *sym)
{
struct plt_entry *plt = (struct plt_entry *)mod->arch.plt->sh_addr;
int i = mod->arch.plt_num_entries;
u64 val = sym->st_value + rela->r_addend;
if (rela->r_addend == 0 && sym->st_size != 0) {
BUG_ON(sym->st_size < (u64)plt || sym->st_size >= (u64)&plt[i]);
return sym->st_size;
}
mod->arch.plt_num_entries++;
BUG_ON(mod->arch.plt_num_entries > mod->arch.plt_max_entries);
plt[i] = (struct plt_entry){
cpu_to_le32(0x92800010 | (((~val ) & 0xffff)) << 5),
cpu_to_le32(0xf2a00010 | ((( val >> 16) & 0xffff)) << 5),
cpu_to_le32(0xf2c00010 | ((( val >> 32) & 0xffff)) << 5),
cpu_to_le32(0xd61f0200)
};
if (rela->r_addend == 0)
sym->st_size = (u64)&plt[i];
return (u64)&plt[i];
}
static int cmp_rela(const void *a, const void *b)
{
const Elf64_Rela *x = a, *y = b;
int i;
i = cmp_3way(ELF64_R_TYPE(x->r_info), ELF64_R_TYPE(y->r_info));
if (i == 0)
i = cmp_3way(ELF64_R_SYM(x->r_info), ELF64_R_SYM(y->r_info));
if (i == 0)
i = cmp_3way(x->r_addend, y->r_addend);
return i;
}
static bool duplicate_rel(const Elf64_Rela *rela, int num)
{
return num > 0 && cmp_rela(rela + num, rela + num - 1) == 0;
}
static unsigned int count_plts(Elf64_Sym *syms, Elf64_Rela *rela, int num)
{
unsigned int ret = 0;
Elf64_Sym *s;
int i;
for (i = 0; i < num; i++) {
switch (ELF64_R_TYPE(rela[i].r_info)) {
case R_AARCH64_JUMP26:
case R_AARCH64_CALL26:
s = syms + ELF64_R_SYM(rela[i].r_info);
if (s->st_shndx != SHN_UNDEF)
break;
if (rela[i].r_addend != 0 || !duplicate_rel(rela, i))
ret++;
break;
}
}
return ret;
}
int module_frob_arch_sections(Elf_Ehdr *ehdr, Elf_Shdr *sechdrs,
char *secstrings, struct module *mod)
{
unsigned long plt_max_entries = 0;
Elf64_Sym *syms = NULL;
int i;
for (i = 0; i < ehdr->e_shnum; i++) {
if (strcmp(".plt", secstrings + sechdrs[i].sh_name) == 0)
mod->arch.plt = sechdrs + i;
else if (sechdrs[i].sh_type == SHT_SYMTAB)
syms = (Elf64_Sym *)sechdrs[i].sh_addr;
}
if (!mod->arch.plt) {
pr_err("%s: module PLT section missing\n", mod->name);
return -ENOEXEC;
}
if (!syms) {
pr_err("%s: module symtab section missing\n", mod->name);
return -ENOEXEC;
}
for (i = 0; i < ehdr->e_shnum; i++) {
Elf64_Rela *rels = (void *)ehdr + sechdrs[i].sh_offset;
int numrels = sechdrs[i].sh_size / sizeof(Elf64_Rela);
Elf64_Shdr *dstsec = sechdrs + sechdrs[i].sh_info;
if (sechdrs[i].sh_type != SHT_RELA)
continue;
if (!(dstsec->sh_flags & SHF_EXECINSTR))
continue;
sort(rels, numrels, sizeof(Elf64_Rela), cmp_rela, NULL);
plt_max_entries += count_plts(syms, rels, numrels);
}
mod->arch.plt->sh_type = SHT_NOBITS;
mod->arch.plt->sh_flags = SHF_EXECINSTR | SHF_ALLOC;
mod->arch.plt->sh_addralign = L1_CACHE_BYTES;
mod->arch.plt->sh_size = plt_max_entries * sizeof(struct plt_entry);
mod->arch.plt_num_entries = 0;
mod->arch.plt_max_entries = plt_max_entries;
return 0;
}
