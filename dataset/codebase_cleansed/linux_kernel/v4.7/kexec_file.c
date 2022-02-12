int __weak arch_kexec_kernel_image_probe(struct kimage *image, void *buf,
unsigned long buf_len)
{
return -ENOEXEC;
}
void * __weak arch_kexec_kernel_image_load(struct kimage *image)
{
return ERR_PTR(-ENOEXEC);
}
int __weak arch_kimage_file_post_load_cleanup(struct kimage *image)
{
return -EINVAL;
}
int __weak arch_kexec_kernel_verify_sig(struct kimage *image, void *buf,
unsigned long buf_len)
{
return -EKEYREJECTED;
}
int __weak
arch_kexec_apply_relocations_add(const Elf_Ehdr *ehdr, Elf_Shdr *sechdrs,
unsigned int relsec)
{
pr_err("RELA relocation unsupported.\n");
return -ENOEXEC;
}
int __weak
arch_kexec_apply_relocations(const Elf_Ehdr *ehdr, Elf_Shdr *sechdrs,
unsigned int relsec)
{
pr_err("REL relocation unsupported.\n");
return -ENOEXEC;
}
void kimage_file_post_load_cleanup(struct kimage *image)
{
struct purgatory_info *pi = &image->purgatory_info;
vfree(image->kernel_buf);
image->kernel_buf = NULL;
vfree(image->initrd_buf);
image->initrd_buf = NULL;
kfree(image->cmdline_buf);
image->cmdline_buf = NULL;
vfree(pi->purgatory_buf);
pi->purgatory_buf = NULL;
vfree(pi->sechdrs);
pi->sechdrs = NULL;
arch_kimage_file_post_load_cleanup(image);
kfree(image->image_loader_data);
image->image_loader_data = NULL;
}
static int
kimage_file_prepare_segments(struct kimage *image, int kernel_fd, int initrd_fd,
const char __user *cmdline_ptr,
unsigned long cmdline_len, unsigned flags)
{
int ret = 0;
void *ldata;
loff_t size;
ret = kernel_read_file_from_fd(kernel_fd, &image->kernel_buf,
&size, INT_MAX, READING_KEXEC_IMAGE);
if (ret)
return ret;
image->kernel_buf_len = size;
ret = arch_kexec_kernel_image_probe(image, image->kernel_buf,
image->kernel_buf_len);
if (ret)
goto out;
#ifdef CONFIG_KEXEC_VERIFY_SIG
ret = arch_kexec_kernel_verify_sig(image, image->kernel_buf,
image->kernel_buf_len);
if (ret) {
pr_debug("kernel signature verification failed.\n");
goto out;
}
pr_debug("kernel signature verification successful.\n");
#endif
if (!(flags & KEXEC_FILE_NO_INITRAMFS)) {
ret = kernel_read_file_from_fd(initrd_fd, &image->initrd_buf,
&size, INT_MAX,
READING_KEXEC_INITRAMFS);
if (ret)
goto out;
image->initrd_buf_len = size;
}
if (cmdline_len) {
image->cmdline_buf = kzalloc(cmdline_len, GFP_KERNEL);
if (!image->cmdline_buf) {
ret = -ENOMEM;
goto out;
}
ret = copy_from_user(image->cmdline_buf, cmdline_ptr,
cmdline_len);
if (ret) {
ret = -EFAULT;
goto out;
}
image->cmdline_buf_len = cmdline_len;
if (image->cmdline_buf[cmdline_len - 1] != '\0') {
ret = -EINVAL;
goto out;
}
}
ldata = arch_kexec_kernel_image_load(image);
if (IS_ERR(ldata)) {
ret = PTR_ERR(ldata);
goto out;
}
image->image_loader_data = ldata;
out:
if (ret)
kimage_file_post_load_cleanup(image);
return ret;
}
static int
kimage_file_alloc_init(struct kimage **rimage, int kernel_fd,
int initrd_fd, const char __user *cmdline_ptr,
unsigned long cmdline_len, unsigned long flags)
{
int ret;
struct kimage *image;
bool kexec_on_panic = flags & KEXEC_FILE_ON_CRASH;
image = do_kimage_alloc_init();
if (!image)
return -ENOMEM;
image->file_mode = 1;
if (kexec_on_panic) {
image->control_page = crashk_res.start;
image->type = KEXEC_TYPE_CRASH;
}
ret = kimage_file_prepare_segments(image, kernel_fd, initrd_fd,
cmdline_ptr, cmdline_len, flags);
if (ret)
goto out_free_image;
ret = sanity_check_segment_list(image);
if (ret)
goto out_free_post_load_bufs;
ret = -ENOMEM;
image->control_code_page = kimage_alloc_control_pages(image,
get_order(KEXEC_CONTROL_PAGE_SIZE));
if (!image->control_code_page) {
pr_err("Could not allocate control_code_buffer\n");
goto out_free_post_load_bufs;
}
if (!kexec_on_panic) {
image->swap_page = kimage_alloc_control_pages(image, 0);
if (!image->swap_page) {
pr_err("Could not allocate swap buffer\n");
goto out_free_control_pages;
}
}
*rimage = image;
return 0;
out_free_control_pages:
kimage_free_page_list(&image->control_pages);
out_free_post_load_bufs:
kimage_file_post_load_cleanup(image);
out_free_image:
kfree(image);
return ret;
}
static int locate_mem_hole_top_down(unsigned long start, unsigned long end,
struct kexec_buf *kbuf)
{
struct kimage *image = kbuf->image;
unsigned long temp_start, temp_end;
temp_end = min(end, kbuf->buf_max);
temp_start = temp_end - kbuf->memsz;
do {
temp_start = temp_start & (~(kbuf->buf_align - 1));
if (temp_start < start || temp_start < kbuf->buf_min)
return 0;
temp_end = temp_start + kbuf->memsz - 1;
if (kimage_is_destination_range(image, temp_start, temp_end)) {
temp_start = temp_start - PAGE_SIZE;
continue;
}
break;
} while (1);
kbuf->mem = temp_start;
return 1;
}
static int locate_mem_hole_bottom_up(unsigned long start, unsigned long end,
struct kexec_buf *kbuf)
{
struct kimage *image = kbuf->image;
unsigned long temp_start, temp_end;
temp_start = max(start, kbuf->buf_min);
do {
temp_start = ALIGN(temp_start, kbuf->buf_align);
temp_end = temp_start + kbuf->memsz - 1;
if (temp_end > end || temp_end > kbuf->buf_max)
return 0;
if (kimage_is_destination_range(image, temp_start, temp_end)) {
temp_start = temp_start + PAGE_SIZE;
continue;
}
break;
} while (1);
kbuf->mem = temp_start;
return 1;
}
static int locate_mem_hole_callback(u64 start, u64 end, void *arg)
{
struct kexec_buf *kbuf = (struct kexec_buf *)arg;
unsigned long sz = end - start + 1;
if (sz < kbuf->memsz)
return 0;
if (end < kbuf->buf_min || start > kbuf->buf_max)
return 0;
if (kbuf->top_down)
return locate_mem_hole_top_down(start, end, kbuf);
return locate_mem_hole_bottom_up(start, end, kbuf);
}
int kexec_add_buffer(struct kimage *image, char *buffer, unsigned long bufsz,
unsigned long memsz, unsigned long buf_align,
unsigned long buf_min, unsigned long buf_max,
bool top_down, unsigned long *load_addr)
{
struct kexec_segment *ksegment;
struct kexec_buf buf, *kbuf;
int ret;
if (!image->file_mode)
return -EINVAL;
if (image->nr_segments >= KEXEC_SEGMENT_MAX)
return -EINVAL;
if (!list_empty(&image->control_pages)) {
WARN_ON(1);
return -EINVAL;
}
memset(&buf, 0, sizeof(struct kexec_buf));
kbuf = &buf;
kbuf->image = image;
kbuf->buffer = buffer;
kbuf->bufsz = bufsz;
kbuf->memsz = ALIGN(memsz, PAGE_SIZE);
kbuf->buf_align = max(buf_align, PAGE_SIZE);
kbuf->buf_min = buf_min;
kbuf->buf_max = buf_max;
kbuf->top_down = top_down;
if (image->type == KEXEC_TYPE_CRASH)
ret = walk_iomem_res_desc(crashk_res.desc,
IORESOURCE_SYSTEM_RAM | IORESOURCE_BUSY,
crashk_res.start, crashk_res.end, kbuf,
locate_mem_hole_callback);
else
ret = walk_system_ram_res(0, -1, kbuf,
locate_mem_hole_callback);
if (ret != 1) {
return -EADDRNOTAVAIL;
}
ksegment = &image->segment[image->nr_segments];
ksegment->kbuf = kbuf->buffer;
ksegment->bufsz = kbuf->bufsz;
ksegment->mem = kbuf->mem;
ksegment->memsz = kbuf->memsz;
image->nr_segments++;
*load_addr = ksegment->mem;
return 0;
}
static int kexec_calculate_store_digests(struct kimage *image)
{
struct crypto_shash *tfm;
struct shash_desc *desc;
int ret = 0, i, j, zero_buf_sz, sha_region_sz;
size_t desc_size, nullsz;
char *digest;
void *zero_buf;
struct kexec_sha_region *sha_regions;
struct purgatory_info *pi = &image->purgatory_info;
zero_buf = __va(page_to_pfn(ZERO_PAGE(0)) << PAGE_SHIFT);
zero_buf_sz = PAGE_SIZE;
tfm = crypto_alloc_shash("sha256", 0, 0);
if (IS_ERR(tfm)) {
ret = PTR_ERR(tfm);
goto out;
}
desc_size = crypto_shash_descsize(tfm) + sizeof(*desc);
desc = kzalloc(desc_size, GFP_KERNEL);
if (!desc) {
ret = -ENOMEM;
goto out_free_tfm;
}
sha_region_sz = KEXEC_SEGMENT_MAX * sizeof(struct kexec_sha_region);
sha_regions = vzalloc(sha_region_sz);
if (!sha_regions)
goto out_free_desc;
desc->tfm = tfm;
desc->flags = 0;
ret = crypto_shash_init(desc);
if (ret < 0)
goto out_free_sha_regions;
digest = kzalloc(SHA256_DIGEST_SIZE, GFP_KERNEL);
if (!digest) {
ret = -ENOMEM;
goto out_free_sha_regions;
}
for (j = i = 0; i < image->nr_segments; i++) {
struct kexec_segment *ksegment;
ksegment = &image->segment[i];
if (ksegment->kbuf == pi->purgatory_buf)
continue;
ret = crypto_shash_update(desc, ksegment->kbuf,
ksegment->bufsz);
if (ret)
break;
nullsz = ksegment->memsz - ksegment->bufsz;
while (nullsz) {
unsigned long bytes = nullsz;
if (bytes > zero_buf_sz)
bytes = zero_buf_sz;
ret = crypto_shash_update(desc, zero_buf, bytes);
if (ret)
break;
nullsz -= bytes;
}
if (ret)
break;
sha_regions[j].start = ksegment->mem;
sha_regions[j].len = ksegment->memsz;
j++;
}
if (!ret) {
ret = crypto_shash_final(desc, digest);
if (ret)
goto out_free_digest;
ret = kexec_purgatory_get_set_symbol(image, "sha_regions",
sha_regions, sha_region_sz, 0);
if (ret)
goto out_free_digest;
ret = kexec_purgatory_get_set_symbol(image, "sha256_digest",
digest, SHA256_DIGEST_SIZE, 0);
if (ret)
goto out_free_digest;
}
out_free_digest:
kfree(digest);
out_free_sha_regions:
vfree(sha_regions);
out_free_desc:
kfree(desc);
out_free_tfm:
kfree(tfm);
out:
return ret;
}
static int __kexec_load_purgatory(struct kimage *image, unsigned long min,
unsigned long max, int top_down)
{
struct purgatory_info *pi = &image->purgatory_info;
unsigned long align, buf_align, bss_align, buf_sz, bss_sz, bss_pad;
unsigned long memsz, entry, load_addr, curr_load_addr, bss_addr, offset;
unsigned char *buf_addr, *src;
int i, ret = 0, entry_sidx = -1;
const Elf_Shdr *sechdrs_c;
Elf_Shdr *sechdrs = NULL;
void *purgatory_buf = NULL;
sechdrs_c = (void *)pi->ehdr + pi->ehdr->e_shoff;
sechdrs = vzalloc(pi->ehdr->e_shnum * sizeof(Elf_Shdr));
if (!sechdrs)
return -ENOMEM;
memcpy(sechdrs, sechdrs_c, pi->ehdr->e_shnum * sizeof(Elf_Shdr));
for (i = 0; i < pi->ehdr->e_shnum; i++) {
if (sechdrs[i].sh_type == SHT_NOBITS)
continue;
sechdrs[i].sh_offset = (unsigned long)pi->ehdr +
sechdrs[i].sh_offset;
}
entry = pi->ehdr->e_entry;
for (i = 0; i < pi->ehdr->e_shnum; i++) {
if (!(sechdrs[i].sh_flags & SHF_ALLOC))
continue;
if (!(sechdrs[i].sh_flags & SHF_EXECINSTR))
continue;
if (sechdrs[i].sh_addr <= pi->ehdr->e_entry &&
((sechdrs[i].sh_addr + sechdrs[i].sh_size) >
pi->ehdr->e_entry)) {
entry_sidx = i;
entry -= sechdrs[i].sh_addr;
break;
}
}
buf_align = 1;
bss_align = 1;
buf_sz = 0;
bss_sz = 0;
for (i = 0; i < pi->ehdr->e_shnum; i++) {
if (!(sechdrs[i].sh_flags & SHF_ALLOC))
continue;
align = sechdrs[i].sh_addralign;
if (sechdrs[i].sh_type != SHT_NOBITS) {
if (buf_align < align)
buf_align = align;
buf_sz = ALIGN(buf_sz, align);
buf_sz += sechdrs[i].sh_size;
} else {
if (bss_align < align)
bss_align = align;
bss_sz = ALIGN(bss_sz, align);
bss_sz += sechdrs[i].sh_size;
}
}
bss_pad = 0;
if (buf_sz & (bss_align - 1))
bss_pad = bss_align - (buf_sz & (bss_align - 1));
memsz = buf_sz + bss_pad + bss_sz;
purgatory_buf = vzalloc(buf_sz);
if (!purgatory_buf) {
ret = -ENOMEM;
goto out;
}
if (buf_align < bss_align)
buf_align = bss_align;
ret = kexec_add_buffer(image, purgatory_buf, buf_sz, memsz,
buf_align, min, max, top_down,
&pi->purgatory_load_addr);
if (ret)
goto out;
buf_addr = purgatory_buf;
load_addr = curr_load_addr = pi->purgatory_load_addr;
bss_addr = load_addr + buf_sz + bss_pad;
for (i = 0; i < pi->ehdr->e_shnum; i++) {
if (!(sechdrs[i].sh_flags & SHF_ALLOC))
continue;
align = sechdrs[i].sh_addralign;
if (sechdrs[i].sh_type != SHT_NOBITS) {
curr_load_addr = ALIGN(curr_load_addr, align);
offset = curr_load_addr - load_addr;
src = (char *) sechdrs[i].sh_offset;
memcpy(buf_addr + offset, src, sechdrs[i].sh_size);
sechdrs[i].sh_addr = curr_load_addr;
sechdrs[i].sh_offset = (unsigned long)(buf_addr + offset);
curr_load_addr += sechdrs[i].sh_size;
} else {
bss_addr = ALIGN(bss_addr, align);
sechdrs[i].sh_addr = bss_addr;
bss_addr += sechdrs[i].sh_size;
}
}
if (entry_sidx >= 0)
entry += sechdrs[entry_sidx].sh_addr;
image->start = entry;
pi->sechdrs = sechdrs;
pi->purgatory_buf = purgatory_buf;
return ret;
out:
vfree(sechdrs);
vfree(purgatory_buf);
return ret;
}
static int kexec_apply_relocations(struct kimage *image)
{
int i, ret;
struct purgatory_info *pi = &image->purgatory_info;
Elf_Shdr *sechdrs = pi->sechdrs;
for (i = 0; i < pi->ehdr->e_shnum; i++) {
Elf_Shdr *section, *symtab;
if (sechdrs[i].sh_type != SHT_RELA &&
sechdrs[i].sh_type != SHT_REL)
continue;
if (sechdrs[i].sh_info >= pi->ehdr->e_shnum ||
sechdrs[i].sh_link >= pi->ehdr->e_shnum)
return -ENOEXEC;
section = &sechdrs[sechdrs[i].sh_info];
symtab = &sechdrs[sechdrs[i].sh_link];
if (!(section->sh_flags & SHF_ALLOC))
continue;
if (symtab->sh_link >= pi->ehdr->e_shnum)
continue;
if (sechdrs[i].sh_type == SHT_RELA)
ret = arch_kexec_apply_relocations_add(pi->ehdr,
sechdrs, i);
else if (sechdrs[i].sh_type == SHT_REL)
ret = arch_kexec_apply_relocations(pi->ehdr,
sechdrs, i);
if (ret)
return ret;
}
return 0;
}
int kexec_load_purgatory(struct kimage *image, unsigned long min,
unsigned long max, int top_down,
unsigned long *load_addr)
{
struct purgatory_info *pi = &image->purgatory_info;
int ret;
if (kexec_purgatory_size <= 0)
return -EINVAL;
if (kexec_purgatory_size < sizeof(Elf_Ehdr))
return -ENOEXEC;
pi->ehdr = (Elf_Ehdr *)kexec_purgatory;
if (memcmp(pi->ehdr->e_ident, ELFMAG, SELFMAG) != 0
|| pi->ehdr->e_type != ET_REL
|| !elf_check_arch(pi->ehdr)
|| pi->ehdr->e_shentsize != sizeof(Elf_Shdr))
return -ENOEXEC;
if (pi->ehdr->e_shoff >= kexec_purgatory_size
|| (pi->ehdr->e_shnum * sizeof(Elf_Shdr) >
kexec_purgatory_size - pi->ehdr->e_shoff))
return -ENOEXEC;
ret = __kexec_load_purgatory(image, min, max, top_down);
if (ret)
return ret;
ret = kexec_apply_relocations(image);
if (ret)
goto out;
*load_addr = pi->purgatory_load_addr;
return 0;
out:
vfree(pi->sechdrs);
vfree(pi->purgatory_buf);
return ret;
}
static Elf_Sym *kexec_purgatory_find_symbol(struct purgatory_info *pi,
const char *name)
{
Elf_Sym *syms;
Elf_Shdr *sechdrs;
Elf_Ehdr *ehdr;
int i, k;
const char *strtab;
if (!pi->sechdrs || !pi->ehdr)
return NULL;
sechdrs = pi->sechdrs;
ehdr = pi->ehdr;
for (i = 0; i < ehdr->e_shnum; i++) {
if (sechdrs[i].sh_type != SHT_SYMTAB)
continue;
if (sechdrs[i].sh_link >= ehdr->e_shnum)
continue;
strtab = (char *)sechdrs[sechdrs[i].sh_link].sh_offset;
syms = (Elf_Sym *)sechdrs[i].sh_offset;
for (k = 0; k < sechdrs[i].sh_size/sizeof(Elf_Sym); k++) {
if (ELF_ST_BIND(syms[k].st_info) != STB_GLOBAL)
continue;
if (strcmp(strtab + syms[k].st_name, name) != 0)
continue;
if (syms[k].st_shndx == SHN_UNDEF ||
syms[k].st_shndx >= ehdr->e_shnum) {
pr_debug("Symbol: %s has bad section index %d.\n",
name, syms[k].st_shndx);
return NULL;
}
return &syms[k];
}
}
return NULL;
}
void *kexec_purgatory_get_symbol_addr(struct kimage *image, const char *name)
{
struct purgatory_info *pi = &image->purgatory_info;
Elf_Sym *sym;
Elf_Shdr *sechdr;
sym = kexec_purgatory_find_symbol(pi, name);
if (!sym)
return ERR_PTR(-EINVAL);
sechdr = &pi->sechdrs[sym->st_shndx];
return (void *)(sechdr->sh_addr + sym->st_value);
}
int kexec_purgatory_get_set_symbol(struct kimage *image, const char *name,
void *buf, unsigned int size, bool get_value)
{
Elf_Sym *sym;
Elf_Shdr *sechdrs;
struct purgatory_info *pi = &image->purgatory_info;
char *sym_buf;
sym = kexec_purgatory_find_symbol(pi, name);
if (!sym)
return -EINVAL;
if (sym->st_size != size) {
pr_err("symbol %s size mismatch: expected %lu actual %u\n",
name, (unsigned long)sym->st_size, size);
return -EINVAL;
}
sechdrs = pi->sechdrs;
if (sechdrs[sym->st_shndx].sh_type == SHT_NOBITS) {
pr_err("symbol %s is in a bss section. Cannot %s\n", name,
get_value ? "get" : "set");
return -EINVAL;
}
sym_buf = (unsigned char *)sechdrs[sym->st_shndx].sh_offset +
sym->st_value;
if (get_value)
memcpy((void *)buf, sym_buf, size);
else
memcpy((void *)sym_buf, buf, size);
return 0;
}
