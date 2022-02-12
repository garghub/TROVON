void *module_alloc(unsigned long size)
{
if (size == 0)
return NULL;
return vmalloc(size);
}
void module_free(struct module *mod, void *module_region)
{
vfree(module_region);
}
int module_frob_arch_sections(Elf_Ehdr *hdr,
Elf_Shdr *sechdrs,
char *secstrings,
struct module *mod)
{
return 0;
}
int apply_relocate(Elf32_Shdr *sechdrs,
const char *strtab,
unsigned int symindex,
unsigned int relsec,
struct module *me)
{
unsigned int i;
Elf32_Rel *rel = (void *)sechdrs[relsec].sh_addr;
Elf32_Sym *sym;
uint32_t *location;
DEBUGP("Applying relocate section %u to %u\n", relsec,
sechdrs[relsec].sh_info);
for (i = 0; i < sechdrs[relsec].sh_size / sizeof(*rel); i++) {
location = (void *)sechdrs[sechdrs[relsec].sh_info].sh_addr
+ rel[i].r_offset;
sym = (Elf32_Sym *)sechdrs[symindex].sh_addr
+ ELF32_R_SYM(rel[i].r_info);
switch (ELF32_R_TYPE(rel[i].r_info)) {
case R_68K_32:
*location += sym->st_value;
break;
case R_68K_PC32:
*location += sym->st_value - (uint32_t)location;
break;
default:
printk(KERN_ERR "module %s: Unknown relocation: %u\n",
me->name, ELF32_R_TYPE(rel[i].r_info));
return -ENOEXEC;
}
}
return 0;
}
int apply_relocate_add(Elf32_Shdr *sechdrs,
const char *strtab,
unsigned int symindex,
unsigned int relsec,
struct module *me)
{
unsigned int i;
Elf32_Rela *rel = (void *)sechdrs[relsec].sh_addr;
Elf32_Sym *sym;
uint32_t *location;
DEBUGP("Applying relocate_add section %u to %u\n", relsec,
sechdrs[relsec].sh_info);
for (i = 0; i < sechdrs[relsec].sh_size / sizeof(*rel); i++) {
location = (void *)sechdrs[sechdrs[relsec].sh_info].sh_addr
+ rel[i].r_offset;
sym = (Elf32_Sym *)sechdrs[symindex].sh_addr
+ ELF32_R_SYM(rel[i].r_info);
switch (ELF32_R_TYPE(rel[i].r_info)) {
case R_68K_32:
*location = rel[i].r_addend + sym->st_value;
break;
case R_68K_PC32:
*location = rel[i].r_addend + sym->st_value - (uint32_t)location;
break;
default:
printk(KERN_ERR "module %s: Unknown relocation: %u\n",
me->name, ELF32_R_TYPE(rel[i].r_info));
return -ENOEXEC;
}
}
return 0;
}
int module_finalize(const Elf_Ehdr *hdr,
const Elf_Shdr *sechdrs,
struct module *me)
{
return 0;
}
void module_arch_cleanup(struct module *mod)
{
}
