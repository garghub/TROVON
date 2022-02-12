static unsigned long elf_hash(const unsigned char *name)
{
unsigned long h = 0, g;
while (*name)
{
h = (h << 4) + *name++;
if (g = h & 0xf0000000)
h ^= g >> 24;
h &= ~g;
}
return h;
}
void vdso_init_from_sysinfo_ehdr(uintptr_t base)
{
size_t i;
bool found_vaddr = false;
vdso_info.valid = false;
vdso_info.load_addr = base;
Elf64_Ehdr *hdr = (Elf64_Ehdr*)base;
Elf64_Phdr *pt = (Elf64_Phdr*)(vdso_info.load_addr + hdr->e_phoff);
Elf64_Dyn *dyn = 0;
for (i = 0; i < hdr->e_phnum; i++)
{
if (pt[i].p_type == PT_LOAD && !found_vaddr) {
found_vaddr = true;
vdso_info.load_offset = base
+ (uintptr_t)pt[i].p_offset
- (uintptr_t)pt[i].p_vaddr;
} else if (pt[i].p_type == PT_DYNAMIC) {
dyn = (Elf64_Dyn*)(base + pt[i].p_offset);
}
}
if (!found_vaddr || !dyn)
return;
Elf64_Word *hash = 0;
vdso_info.symstrings = 0;
vdso_info.symtab = 0;
vdso_info.versym = 0;
vdso_info.verdef = 0;
for (i = 0; dyn[i].d_tag != DT_NULL; i++) {
switch (dyn[i].d_tag) {
case DT_STRTAB:
vdso_info.symstrings = (const char *)
((uintptr_t)dyn[i].d_un.d_ptr
+ vdso_info.load_offset);
break;
case DT_SYMTAB:
vdso_info.symtab = (Elf64_Sym *)
((uintptr_t)dyn[i].d_un.d_ptr
+ vdso_info.load_offset);
break;
case DT_HASH:
hash = (Elf64_Word *)
((uintptr_t)dyn[i].d_un.d_ptr
+ vdso_info.load_offset);
break;
case DT_VERSYM:
vdso_info.versym = (Elf64_Versym *)
((uintptr_t)dyn[i].d_un.d_ptr
+ vdso_info.load_offset);
break;
case DT_VERDEF:
vdso_info.verdef = (Elf64_Verdef *)
((uintptr_t)dyn[i].d_un.d_ptr
+ vdso_info.load_offset);
break;
}
}
if (!vdso_info.symstrings || !vdso_info.symtab || !hash)
return;
if (!vdso_info.verdef)
vdso_info.versym = 0;
vdso_info.nbucket = hash[0];
vdso_info.nchain = hash[1];
vdso_info.bucket = &hash[2];
vdso_info.chain = &hash[vdso_info.nbucket + 2];
vdso_info.valid = true;
}
static bool vdso_match_version(Elf64_Versym ver,
const char *name, Elf64_Word hash)
{
ver &= 0x7fff;
Elf64_Verdef *def = vdso_info.verdef;
while(true) {
if ((def->vd_flags & VER_FLG_BASE) == 0
&& (def->vd_ndx & 0x7fff) == ver)
break;
if (def->vd_next == 0)
return false;
def = (Elf64_Verdef *)((char *)def + def->vd_next);
}
Elf64_Verdaux *aux = (Elf64_Verdaux*)((char *)def + def->vd_aux);
return def->vd_hash == hash
&& !strcmp(name, vdso_info.symstrings + aux->vda_name);
}
void *vdso_sym(const char *version, const char *name)
{
unsigned long ver_hash;
if (!vdso_info.valid)
return 0;
ver_hash = elf_hash(version);
Elf64_Word chain = vdso_info.bucket[elf_hash(name) % vdso_info.nbucket];
for (; chain != STN_UNDEF; chain = vdso_info.chain[chain]) {
Elf64_Sym *sym = &vdso_info.symtab[chain];
if (ELF64_ST_TYPE(sym->st_info) != STT_FUNC)
continue;
if (ELF64_ST_BIND(sym->st_info) != STB_GLOBAL &&
ELF64_ST_BIND(sym->st_info) != STB_WEAK)
continue;
if (sym->st_shndx == SHN_UNDEF)
continue;
if (strcmp(name, vdso_info.symstrings + sym->st_name))
continue;
if (vdso_info.versym
&& !vdso_match_version(vdso_info.versym[chain],
version, ver_hash))
continue;
return (void *)(vdso_info.load_offset + sym->st_value);
}
return 0;
}
void vdso_init_from_auxv(void *auxv)
{
Elf64_auxv_t *elf_auxv = auxv;
for (int i = 0; elf_auxv[i].a_type != AT_NULL; i++)
{
if (elf_auxv[i].a_type == AT_SYSINFO_EHDR) {
vdso_init_from_sysinfo_ehdr(elf_auxv[i].a_un.a_val);
return;
}
}
vdso_info.valid = false;
}
