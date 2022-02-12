static bool in_init(const struct module *mod, void *loc)
{
return (u64)loc - (u64)mod->init_layout.base < mod->init_layout.size;
}
u64 module_emit_plt_entry(struct module *mod, void *loc, const Elf64_Rela *rela,
Elf64_Sym *sym)
{
struct mod_plt_sec *pltsec = !in_init(mod, loc) ? &mod->arch.core :
&mod->arch.init;
struct plt_entry *plt = (struct plt_entry *)pltsec->plt->sh_addr;
int i = pltsec->plt_num_entries;
u64 val = sym->st_value + rela->r_addend;
plt[i] = (struct plt_entry){
cpu_to_le32(0x92800010 | (((~val ) & 0xffff)) << 5),
cpu_to_le32(0xf2a00010 | ((( val >> 16) & 0xffff)) << 5),
cpu_to_le32(0xf2c00010 | ((( val >> 32) & 0xffff)) << 5),
cpu_to_le32(0xd61f0200)
};
if (i > 0 &&
plt[i].mov0 == plt[i - 1].mov0 &&
plt[i].mov1 == plt[i - 1].mov1 &&
plt[i].mov2 == plt[i - 1].mov2)
return (u64)&plt[i - 1];
pltsec->plt_num_entries++;
BUG_ON(pltsec->plt_num_entries > pltsec->plt_max_entries);
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
static unsigned int count_plts(Elf64_Sym *syms, Elf64_Rela *rela, int num,
Elf64_Word dstidx)
{
unsigned int ret = 0;
Elf64_Sym *s;
int i;
for (i = 0; i < num; i++) {
switch (ELF64_R_TYPE(rela[i].r_info)) {
case R_AARCH64_JUMP26:
case R_AARCH64_CALL26:
s = syms + ELF64_R_SYM(rela[i].r_info);
if (s->st_shndx == dstidx)
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
unsigned long core_plts = 0;
unsigned long init_plts = 0;
Elf64_Sym *syms = NULL;
int i;
for (i = 0; i < ehdr->e_shnum; i++) {
if (!strcmp(secstrings + sechdrs[i].sh_name, ".plt"))
mod->arch.core.plt = sechdrs + i;
else if (!strcmp(secstrings + sechdrs[i].sh_name, ".init.plt"))
mod->arch.init.plt = sechdrs + i;
else if (sechdrs[i].sh_type == SHT_SYMTAB)
syms = (Elf64_Sym *)sechdrs[i].sh_addr;
}
if (!mod->arch.core.plt || !mod->arch.init.plt) {
pr_err("%s: module PLT section(s) missing\n", mod->name);
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
if (strncmp(secstrings + dstsec->sh_name, ".init", 5) != 0)
core_plts += count_plts(syms, rels, numrels,
sechdrs[i].sh_info);
else
init_plts += count_plts(syms, rels, numrels,
sechdrs[i].sh_info);
}
mod->arch.core.plt->sh_type = SHT_NOBITS;
mod->arch.core.plt->sh_flags = SHF_EXECINSTR | SHF_ALLOC;
mod->arch.core.plt->sh_addralign = L1_CACHE_BYTES;
mod->arch.core.plt->sh_size = (core_plts + 1) * sizeof(struct plt_entry);
mod->arch.core.plt_num_entries = 0;
mod->arch.core.plt_max_entries = core_plts;
mod->arch.init.plt->sh_type = SHT_NOBITS;
mod->arch.init.plt->sh_flags = SHF_EXECINSTR | SHF_ALLOC;
mod->arch.init.plt->sh_addralign = L1_CACHE_BYTES;
mod->arch.init.plt->sh_size = (init_plts + 1) * sizeof(struct plt_entry);
mod->arch.init.plt_num_entries = 0;
mod->arch.init.plt_max_entries = init_plts;
return 0;
}
