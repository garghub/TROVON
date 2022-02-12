struct vpe *get_vpe(int minor)
{
struct vpe *res, *v;
if (!cpu_has_mipsmt)
return NULL;
res = NULL;
spin_lock(&vpecontrol.vpe_list_lock);
list_for_each_entry(v, &vpecontrol.vpe_list, list) {
if (v->minor == VPE_MODULE_MINOR) {
res = v;
break;
}
}
spin_unlock(&vpecontrol.vpe_list_lock);
return res;
}
struct tc *get_tc(int index)
{
struct tc *res, *t;
res = NULL;
spin_lock(&vpecontrol.tc_list_lock);
list_for_each_entry(t, &vpecontrol.tc_list, list) {
if (t->index == index) {
res = t;
break;
}
}
spin_unlock(&vpecontrol.tc_list_lock);
return res;
}
struct vpe *alloc_vpe(int minor)
{
struct vpe *v;
v = kzalloc(sizeof(struct vpe), GFP_KERNEL);
if (v == NULL)
goto out;
INIT_LIST_HEAD(&v->tc);
spin_lock(&vpecontrol.vpe_list_lock);
list_add_tail(&v->list, &vpecontrol.vpe_list);
spin_unlock(&vpecontrol.vpe_list_lock);
INIT_LIST_HEAD(&v->notify);
v->minor = VPE_MODULE_MINOR;
out:
return v;
}
struct tc *alloc_tc(int index)
{
struct tc *tc;
tc = kzalloc(sizeof(struct tc), GFP_KERNEL);
if (tc == NULL)
goto out;
INIT_LIST_HEAD(&tc->tc);
tc->index = index;
spin_lock(&vpecontrol.tc_list_lock);
list_add_tail(&tc->list, &vpecontrol.tc_list);
spin_unlock(&vpecontrol.tc_list_lock);
out:
return tc;
}
void release_vpe(struct vpe *v)
{
list_del(&v->list);
if (v->load_addr)
release_progmem(v);
kfree(v);
}
void *alloc_progmem(unsigned long len)
{
void *addr;
#ifdef CONFIG_MIPS_VPE_LOADER_TOM
addr = pfn_to_kaddr(max_low_pfn);
memset(addr, 0, len);
#else
addr = kzalloc(len, GFP_KERNEL);
#endif
return addr;
}
void release_progmem(void *ptr)
{
#ifndef CONFIG_MIPS_VPE_LOADER_TOM
kfree(ptr);
#endif
}
static long get_offset(unsigned long *size, Elf_Shdr *sechdr)
{
long ret;
ret = ALIGN(*size, sechdr->sh_addralign ? : 1);
*size = ret + sechdr->sh_size;
return ret;
}
static void layout_sections(struct module *mod, const Elf_Ehdr *hdr,
Elf_Shdr *sechdrs, const char *secstrings)
{
static unsigned long const masks[][2] = {
{SHF_EXECINSTR | SHF_ALLOC, ARCH_SHF_SMALL},
{SHF_ALLOC, SHF_WRITE | ARCH_SHF_SMALL},
{SHF_WRITE | SHF_ALLOC, ARCH_SHF_SMALL},
{ARCH_SHF_SMALL | SHF_ALLOC, 0}
};
unsigned int m, i;
for (i = 0; i < hdr->e_shnum; i++)
sechdrs[i].sh_entsize = ~0UL;
for (m = 0; m < ARRAY_SIZE(masks); ++m) {
for (i = 0; i < hdr->e_shnum; ++i) {
Elf_Shdr *s = &sechdrs[i];
if ((s->sh_flags & masks[m][0]) != masks[m][0]
|| (s->sh_flags & masks[m][1])
|| s->sh_entsize != ~0UL)
continue;
s->sh_entsize =
get_offset((unsigned long *)&mod->core_size, s);
}
if (m == 0)
mod->core_text_size = mod->core_size;
}
}
static int apply_r_mips_none(struct module *me, uint32_t *location,
Elf32_Addr v)
{
return 0;
}
static int apply_r_mips_gprel16(struct module *me, uint32_t *location,
Elf32_Addr v)
{
int rel;
if (!(*location & 0xffff)) {
rel = (int)v - gp_addr;
} else {
rel = (int)(short)((int)v + gp_offs +
(int)(short)(*location & 0xffff) - gp_addr);
}
if ((rel > 32768) || (rel < -32768)) {
pr_debug("VPE loader: apply_r_mips_gprel16: relative address 0x%x out of range of gp register\n",
rel);
return -ENOEXEC;
}
*location = (*location & 0xffff0000) | (rel & 0xffff);
return 0;
}
static int apply_r_mips_pc16(struct module *me, uint32_t *location,
Elf32_Addr v)
{
int rel;
rel = (((unsigned int)v - (unsigned int)location));
rel >>= 2;
rel -= 1;
if ((rel > 32768) || (rel < -32768)) {
pr_debug("VPE loader: apply_r_mips_pc16: relative address out of range 0x%x\n",
rel);
return -ENOEXEC;
}
*location = (*location & 0xffff0000) | (rel & 0xffff);
return 0;
}
static int apply_r_mips_32(struct module *me, uint32_t *location,
Elf32_Addr v)
{
*location += v;
return 0;
}
static int apply_r_mips_26(struct module *me, uint32_t *location,
Elf32_Addr v)
{
if (v % 4) {
pr_debug("VPE loader: apply_r_mips_26: unaligned relocation\n");
return -ENOEXEC;
}
*location = (*location & ~0x03ffffff) |
((*location + (v >> 2)) & 0x03ffffff);
return 0;
}
static int apply_r_mips_hi16(struct module *me, uint32_t *location,
Elf32_Addr v)
{
struct mips_hi16 *n;
n = kmalloc(sizeof(*n), GFP_KERNEL);
if (!n)
return -ENOMEM;
n->addr = location;
n->value = v;
n->next = mips_hi16_list;
mips_hi16_list = n;
return 0;
}
static int apply_r_mips_lo16(struct module *me, uint32_t *location,
Elf32_Addr v)
{
unsigned long insnlo = *location;
Elf32_Addr val, vallo;
struct mips_hi16 *l, *next;
vallo = ((insnlo & 0xffff) ^ 0x8000) - 0x8000;
if (mips_hi16_list != NULL) {
l = mips_hi16_list;
while (l != NULL) {
unsigned long insn;
if (v != l->value) {
pr_debug("VPE loader: apply_r_mips_lo16/hi16: inconsistent value information\n");
goto out_free;
}
insn = *l->addr;
val = ((insn & 0xffff) << 16) + vallo;
val += v;
val = ((val >> 16) + ((val & 0x8000) != 0)) & 0xffff;
insn = (insn & ~0xffff) | val;
*l->addr = insn;
next = l->next;
kfree(l);
l = next;
}
mips_hi16_list = NULL;
}
val = v + vallo;
insnlo = (insnlo & ~0xffff) | (val & 0xffff);
*location = insnlo;
return 0;
out_free:
while (l != NULL) {
next = l->next;
kfree(l);
l = next;
}
mips_hi16_list = NULL;
return -ENOEXEC;
}
static int apply_relocations(Elf32_Shdr *sechdrs,
const char *strtab,
unsigned int symindex,
unsigned int relsec,
struct module *me)
{
Elf32_Rel *rel = (void *) sechdrs[relsec].sh_addr;
Elf32_Sym *sym;
uint32_t *location;
unsigned int i;
Elf32_Addr v;
int res;
for (i = 0; i < sechdrs[relsec].sh_size / sizeof(*rel); i++) {
Elf32_Word r_info = rel[i].r_info;
location = (void *)sechdrs[sechdrs[relsec].sh_info].sh_addr
+ rel[i].r_offset;
sym = (Elf32_Sym *)sechdrs[symindex].sh_addr
+ ELF32_R_SYM(r_info);
if (!sym->st_value) {
pr_debug("%s: undefined weak symbol %s\n",
me->name, strtab + sym->st_name);
}
v = sym->st_value;
res = reloc_handlers[ELF32_R_TYPE(r_info)](me, location, v);
if (res) {
char *r = rstrs[ELF32_R_TYPE(r_info)];
pr_warn("VPE loader: .text+0x%x relocation type %s for symbol \"%s\" failed\n",
rel[i].r_offset, r ? r : "UNKNOWN",
strtab + sym->st_name);
return res;
}
}
return 0;
}
static inline void save_gp_address(unsigned int secbase, unsigned int rel)
{
gp_addr = secbase + rel;
gp_offs = gp_addr - (secbase & 0xffff0000);
}
static void simplify_symbols(Elf_Shdr *sechdrs,
unsigned int symindex,
const char *strtab,
const char *secstrings,
unsigned int nsecs, struct module *mod)
{
Elf_Sym *sym = (void *)sechdrs[symindex].sh_addr;
unsigned long secbase, bssbase = 0;
unsigned int i, n = sechdrs[symindex].sh_size / sizeof(Elf_Sym);
int size;
for (i = 0; i < nsecs; i++) {
if (strncmp(secstrings + sechdrs[i].sh_name, ".bss", 4) == 0) {
bssbase = sechdrs[i].sh_addr;
break;
}
}
for (i = 1; i < n; i++) {
switch (sym[i].st_shndx) {
case SHN_COMMON:
size = sym[i].st_value;
sym[i].st_value = bssbase;
bssbase += size;
break;
case SHN_ABS:
break;
case SHN_UNDEF:
break;
case SHN_MIPS_SCOMMON:
pr_debug("simplify_symbols: ignoring SHN_MIPS_SCOMMON symbol <%s> st_shndx %d\n",
strtab + sym[i].st_name, sym[i].st_shndx);
break;
default:
secbase = sechdrs[sym[i].st_shndx].sh_addr;
if (strncmp(strtab + sym[i].st_name, "_gp", 3) == 0)
save_gp_address(secbase, sym[i].st_value);
sym[i].st_value += secbase;
break;
}
}
}
static void dump_elfsymbols(Elf_Shdr *sechdrs, unsigned int symindex,
const char *strtab, struct module *mod)
{
Elf_Sym *sym = (void *)sechdrs[symindex].sh_addr;
unsigned int i, n = sechdrs[symindex].sh_size / sizeof(Elf_Sym);
pr_debug("dump_elfsymbols: n %d\n", n);
for (i = 1; i < n; i++) {
pr_debug(" i %d name <%s> 0x%x\n", i, strtab + sym[i].st_name,
sym[i].st_value);
}
}
static int find_vpe_symbols(struct vpe *v, Elf_Shdr *sechdrs,
unsigned int symindex, const char *strtab,
struct module *mod)
{
Elf_Sym *sym = (void *)sechdrs[symindex].sh_addr;
unsigned int i, n = sechdrs[symindex].sh_size / sizeof(Elf_Sym);
for (i = 1; i < n; i++) {
if (strcmp(strtab + sym[i].st_name, "__start") == 0)
v->__start = sym[i].st_value;
if (strcmp(strtab + sym[i].st_name, "vpe_shared") == 0)
v->shared_ptr = (void *)sym[i].st_value;
}
if ((v->__start == 0) || (v->shared_ptr == NULL))
return -1;
return 0;
}
static int vpe_elfload(struct vpe *v)
{
Elf_Ehdr *hdr;
Elf_Shdr *sechdrs;
long err = 0;
char *secstrings, *strtab = NULL;
unsigned int len, i, symindex = 0, strindex = 0, relocate = 0;
struct module mod;
memset(&mod, 0, sizeof(struct module));
strcpy(mod.name, "VPE loader");
hdr = (Elf_Ehdr *) v->pbuffer;
len = v->plen;
if (memcmp(hdr->e_ident, ELFMAG, SELFMAG) != 0
|| (hdr->e_type != ET_REL && hdr->e_type != ET_EXEC)
|| !elf_check_arch(hdr)
|| hdr->e_shentsize != sizeof(*sechdrs)) {
pr_warn("VPE loader: program wrong arch or weird elf version\n");
return -ENOEXEC;
}
if (hdr->e_type == ET_REL)
relocate = 1;
if (len < hdr->e_shoff + hdr->e_shnum * sizeof(Elf_Shdr)) {
pr_err("VPE loader: program length %u truncated\n", len);
return -ENOEXEC;
}
sechdrs = (void *)hdr + hdr->e_shoff;
secstrings = (void *)hdr + sechdrs[hdr->e_shstrndx].sh_offset;
sechdrs[0].sh_addr = 0;
symindex = strindex = 0;
if (relocate) {
for (i = 1; i < hdr->e_shnum; i++) {
if ((sechdrs[i].sh_type != SHT_NOBITS) &&
(len < sechdrs[i].sh_offset + sechdrs[i].sh_size)) {
pr_err("VPE program length %u truncated\n",
len);
return -ENOEXEC;
}
sechdrs[i].sh_addr = (size_t) hdr +
sechdrs[i].sh_offset;
if (sechdrs[i].sh_type == SHT_SYMTAB) {
symindex = i;
strindex = sechdrs[i].sh_link;
strtab = (char *)hdr +
sechdrs[strindex].sh_offset;
}
}
layout_sections(&mod, hdr, sechdrs, secstrings);
}
v->load_addr = alloc_progmem(mod.core_size);
if (!v->load_addr)
return -ENOMEM;
pr_info("VPE loader: loading to %p\n", v->load_addr);
if (relocate) {
for (i = 0; i < hdr->e_shnum; i++) {
void *dest;
if (!(sechdrs[i].sh_flags & SHF_ALLOC))
continue;
dest = v->load_addr + sechdrs[i].sh_entsize;
if (sechdrs[i].sh_type != SHT_NOBITS)
memcpy(dest, (void *)sechdrs[i].sh_addr,
sechdrs[i].sh_size);
sechdrs[i].sh_addr = (unsigned long)dest;
pr_debug(" section sh_name %s sh_addr 0x%x\n",
secstrings + sechdrs[i].sh_name,
sechdrs[i].sh_addr);
}
simplify_symbols(sechdrs, symindex, strtab, secstrings,
hdr->e_shnum, &mod);
for (i = 1; i < hdr->e_shnum; i++) {
const char *strtab = (char *)sechdrs[strindex].sh_addr;
unsigned int info = sechdrs[i].sh_info;
if (info >= hdr->e_shnum)
continue;
if (!(sechdrs[info].sh_flags & SHF_ALLOC))
continue;
if (sechdrs[i].sh_type == SHT_REL)
err = apply_relocations(sechdrs, strtab,
symindex, i, &mod);
else if (sechdrs[i].sh_type == SHT_RELA)
err = apply_relocate_add(sechdrs, strtab,
symindex, i, &mod);
if (err < 0)
return err;
}
} else {
struct elf_phdr *phdr = (struct elf_phdr *)
((char *)hdr + hdr->e_phoff);
for (i = 0; i < hdr->e_phnum; i++) {
if (phdr->p_type == PT_LOAD) {
memcpy((void *)phdr->p_paddr,
(char *)hdr + phdr->p_offset,
phdr->p_filesz);
memset((void *)phdr->p_paddr + phdr->p_filesz,
0, phdr->p_memsz - phdr->p_filesz);
}
phdr++;
}
for (i = 0; i < hdr->e_shnum; i++) {
if (sechdrs[i].sh_type == SHT_SYMTAB) {
symindex = i;
strindex = sechdrs[i].sh_link;
strtab = (char *)hdr +
sechdrs[strindex].sh_offset;
sechdrs[i].sh_addr = (size_t) hdr +
sechdrs[i].sh_offset;
}
}
}
flush_icache_range((unsigned long)v->load_addr,
(unsigned long)v->load_addr + v->len);
if ((find_vpe_symbols(v, sechdrs, symindex, strtab, &mod)) < 0) {
if (v->__start == 0) {
pr_warn("VPE loader: program does not contain a __start symbol\n");
return -ENOEXEC;
}
if (v->shared_ptr == NULL)
pr_warn("VPE loader: program does not contain vpe_shared symbol.\n"
" Unable to use AMVP (AP/SP) facilities.\n");
}
pr_info(" elf loaded\n");
return 0;
}
static int getcwd(char *buff, int size)
{
mm_segment_t old_fs;
int ret;
old_fs = get_fs();
set_fs(KERNEL_DS);
ret = sys_getcwd(buff, size);
set_fs(old_fs);
return ret;
}
static int vpe_open(struct inode *inode, struct file *filp)
{
enum vpe_state state;
struct vpe_notifications *notifier;
struct vpe *v;
int ret;
if (VPE_MODULE_MINOR != iminor(inode)) {
pr_warn("VPE loader: only vpe1 is supported\n");
return -ENODEV;
}
v = get_vpe(aprp_cpu_index());
if (v == NULL) {
pr_warn("VPE loader: unable to get vpe\n");
return -ENODEV;
}
state = xchg(&v->state, VPE_STATE_INUSE);
if (state != VPE_STATE_UNUSED) {
pr_debug("VPE loader: tc in use dumping regs\n");
list_for_each_entry(notifier, &v->notify, list)
notifier->stop(aprp_cpu_index());
release_progmem(v->load_addr);
cleanup_tc(get_tc(aprp_cpu_index()));
}
v->pbuffer = vmalloc(P_SIZE);
if (!v->pbuffer) {
pr_warn("VPE loader: unable to allocate memory\n");
return -ENOMEM;
}
v->plen = P_SIZE;
v->load_addr = NULL;
v->len = 0;
v->cwd[0] = 0;
ret = getcwd(v->cwd, VPE_PATH_MAX);
if (ret < 0)
pr_warn("VPE loader: open, getcwd returned %d\n", ret);
v->shared_ptr = NULL;
v->__start = 0;
return 0;
}
static int vpe_release(struct inode *inode, struct file *filp)
{
#if defined(CONFIG_MIPS_VPE_LOADER_MT) || defined(CONFIG_MIPS_VPE_LOADER_CMP)
struct vpe *v;
Elf_Ehdr *hdr;
int ret = 0;
v = get_vpe(aprp_cpu_index());
if (v == NULL)
return -ENODEV;
hdr = (Elf_Ehdr *) v->pbuffer;
if (memcmp(hdr->e_ident, ELFMAG, SELFMAG) == 0) {
if (vpe_elfload(v) >= 0) {
vpe_run(v);
} else {
pr_warn("VPE loader: ELF load failed.\n");
ret = -ENOEXEC;
}
} else {
pr_warn("VPE loader: only elf files are supported\n");
ret = -ENOEXEC;
}
if (ret < 0)
v->shared_ptr = NULL;
vfree(v->pbuffer);
v->plen = 0;
return ret;
#else
pr_warn("VPE loader: ELF load failed.\n");
return -ENOEXEC;
#endif
}
static ssize_t vpe_write(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos)
{
size_t ret = count;
struct vpe *v;
if (iminor(file_inode(file)) != VPE_MODULE_MINOR)
return -ENODEV;
v = get_vpe(aprp_cpu_index());
if (v == NULL)
return -ENODEV;
if ((count + v->len) > v->plen) {
pr_warn("VPE loader: elf size too big. Perhaps strip uneeded symbols\n");
return -ENOMEM;
}
count -= copy_from_user(v->pbuffer + v->len, buffer, count);
if (!count)
return -EFAULT;
v->len += count;
return ret;
}
void *vpe_get_shared(int index)
{
struct vpe *v = get_vpe(index);
if (v == NULL)
return NULL;
return v->shared_ptr;
}
int vpe_notify(int index, struct vpe_notifications *notify)
{
struct vpe *v = get_vpe(index);
if (v == NULL)
return -1;
list_add(&notify->list, &v->notify);
return 0;
}
char *vpe_getcwd(int index)
{
struct vpe *v = get_vpe(index);
if (v == NULL)
return NULL;
return v->cwd;
}
