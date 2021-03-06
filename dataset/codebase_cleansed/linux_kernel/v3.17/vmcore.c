int register_oldmem_pfn_is_ram(int (*fn)(unsigned long pfn))
{
if (oldmem_pfn_is_ram)
return -EBUSY;
oldmem_pfn_is_ram = fn;
return 0;
}
void unregister_oldmem_pfn_is_ram(void)
{
oldmem_pfn_is_ram = NULL;
wmb();
}
static int pfn_is_ram(unsigned long pfn)
{
int (*fn)(unsigned long pfn);
int ret = 1;
fn = oldmem_pfn_is_ram;
if (fn)
ret = fn(pfn);
return ret;
}
static ssize_t read_from_oldmem(char *buf, size_t count,
u64 *ppos, int userbuf)
{
unsigned long pfn, offset;
size_t nr_bytes;
ssize_t read = 0, tmp;
if (!count)
return 0;
offset = (unsigned long)(*ppos % PAGE_SIZE);
pfn = (unsigned long)(*ppos / PAGE_SIZE);
do {
if (count > (PAGE_SIZE - offset))
nr_bytes = PAGE_SIZE - offset;
else
nr_bytes = count;
if (pfn_is_ram(pfn) == 0)
memset(buf, 0, nr_bytes);
else {
tmp = copy_oldmem_page(pfn, buf, nr_bytes,
offset, userbuf);
if (tmp < 0)
return tmp;
}
*ppos += nr_bytes;
count -= nr_bytes;
buf += nr_bytes;
read += nr_bytes;
++pfn;
offset = 0;
} while (count);
return read;
}
int __weak elfcorehdr_alloc(unsigned long long *addr, unsigned long long *size)
{
return 0;
}
void __weak elfcorehdr_free(unsigned long long addr)
{}
ssize_t __weak elfcorehdr_read(char *buf, size_t count, u64 *ppos)
{
return read_from_oldmem(buf, count, ppos, 0);
}
ssize_t __weak elfcorehdr_read_notes(char *buf, size_t count, u64 *ppos)
{
return read_from_oldmem(buf, count, ppos, 0);
}
int __weak remap_oldmem_pfn_range(struct vm_area_struct *vma,
unsigned long from, unsigned long pfn,
unsigned long size, pgprot_t prot)
{
return remap_pfn_range(vma, from, pfn, size, prot);
}
static int copy_to(void *target, void *src, size_t size, int userbuf)
{
if (userbuf) {
if (copy_to_user((char __user *) target, src, size))
return -EFAULT;
} else {
memcpy(target, src, size);
}
return 0;
}
static ssize_t __read_vmcore(char *buffer, size_t buflen, loff_t *fpos,
int userbuf)
{
ssize_t acc = 0, tmp;
size_t tsz;
u64 start;
struct vmcore *m = NULL;
if (buflen == 0 || *fpos >= vmcore_size)
return 0;
if (buflen > vmcore_size - *fpos)
buflen = vmcore_size - *fpos;
if (*fpos < elfcorebuf_sz) {
tsz = min(elfcorebuf_sz - (size_t)*fpos, buflen);
if (copy_to(buffer, elfcorebuf + *fpos, tsz, userbuf))
return -EFAULT;
buflen -= tsz;
*fpos += tsz;
buffer += tsz;
acc += tsz;
if (buflen == 0)
return acc;
}
if (*fpos < elfcorebuf_sz + elfnotes_sz) {
void *kaddr;
tsz = min(elfcorebuf_sz + elfnotes_sz - (size_t)*fpos, buflen);
kaddr = elfnotes_buf + *fpos - elfcorebuf_sz;
if (copy_to(buffer, kaddr, tsz, userbuf))
return -EFAULT;
buflen -= tsz;
*fpos += tsz;
buffer += tsz;
acc += tsz;
if (buflen == 0)
return acc;
}
list_for_each_entry(m, &vmcore_list, list) {
if (*fpos < m->offset + m->size) {
tsz = min_t(size_t, m->offset + m->size - *fpos, buflen);
start = m->paddr + *fpos - m->offset;
tmp = read_from_oldmem(buffer, tsz, &start, userbuf);
if (tmp < 0)
return tmp;
buflen -= tsz;
*fpos += tsz;
buffer += tsz;
acc += tsz;
if (buflen == 0)
return acc;
}
}
return acc;
}
static ssize_t read_vmcore(struct file *file, char __user *buffer,
size_t buflen, loff_t *fpos)
{
return __read_vmcore((__force char *) buffer, buflen, fpos, 1);
}
static int mmap_vmcore_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
#ifdef CONFIG_S390
struct address_space *mapping = vma->vm_file->f_mapping;
pgoff_t index = vmf->pgoff;
struct page *page;
loff_t offset;
char *buf;
int rc;
page = find_or_create_page(mapping, index, GFP_KERNEL);
if (!page)
return VM_FAULT_OOM;
if (!PageUptodate(page)) {
offset = (loff_t) index << PAGE_CACHE_SHIFT;
buf = __va((page_to_pfn(page) << PAGE_SHIFT));
rc = __read_vmcore(buf, PAGE_SIZE, &offset, 0);
if (rc < 0) {
unlock_page(page);
page_cache_release(page);
return (rc == -ENOMEM) ? VM_FAULT_OOM : VM_FAULT_SIGBUS;
}
SetPageUptodate(page);
}
unlock_page(page);
vmf->page = page;
return 0;
#else
return VM_FAULT_SIGBUS;
#endif
}
static inline char *alloc_elfnotes_buf(size_t notes_sz)
{
#ifdef CONFIG_MMU
return vmalloc_user(notes_sz);
#else
return vzalloc(notes_sz);
#endif
}
static int remap_oldmem_pfn_checked(struct vm_area_struct *vma,
unsigned long from, unsigned long pfn,
unsigned long size, pgprot_t prot)
{
unsigned long map_size;
unsigned long pos_start, pos_end, pos;
unsigned long zeropage_pfn = my_zero_pfn(0);
size_t len = 0;
pos_start = pfn;
pos_end = pfn + (size >> PAGE_SHIFT);
for (pos = pos_start; pos < pos_end; ++pos) {
if (!pfn_is_ram(pos)) {
if (pos > pos_start) {
map_size = (pos - pos_start) << PAGE_SHIFT;
if (remap_oldmem_pfn_range(vma, from + len,
pos_start, map_size,
prot))
goto fail;
len += map_size;
}
if (remap_oldmem_pfn_range(vma, from + len,
zeropage_pfn,
PAGE_SIZE, prot))
goto fail;
len += PAGE_SIZE;
pos_start = pos + 1;
}
}
if (pos > pos_start) {
map_size = (pos - pos_start) << PAGE_SHIFT;
if (remap_oldmem_pfn_range(vma, from + len, pos_start,
map_size, prot))
goto fail;
}
return 0;
fail:
do_munmap(vma->vm_mm, from, len);
return -EAGAIN;
}
static int vmcore_remap_oldmem_pfn(struct vm_area_struct *vma,
unsigned long from, unsigned long pfn,
unsigned long size, pgprot_t prot)
{
if (oldmem_pfn_is_ram)
return remap_oldmem_pfn_checked(vma, from, pfn, size, prot);
else
return remap_oldmem_pfn_range(vma, from, pfn, size, prot);
}
static int mmap_vmcore(struct file *file, struct vm_area_struct *vma)
{
size_t size = vma->vm_end - vma->vm_start;
u64 start, end, len, tsz;
struct vmcore *m;
start = (u64)vma->vm_pgoff << PAGE_SHIFT;
end = start + size;
if (size > vmcore_size || end > vmcore_size)
return -EINVAL;
if (vma->vm_flags & (VM_WRITE | VM_EXEC))
return -EPERM;
vma->vm_flags &= ~(VM_MAYWRITE | VM_MAYEXEC);
vma->vm_flags |= VM_MIXEDMAP;
vma->vm_ops = &vmcore_mmap_ops;
len = 0;
if (start < elfcorebuf_sz) {
u64 pfn;
tsz = min(elfcorebuf_sz - (size_t)start, size);
pfn = __pa(elfcorebuf + start) >> PAGE_SHIFT;
if (remap_pfn_range(vma, vma->vm_start, pfn, tsz,
vma->vm_page_prot))
return -EAGAIN;
size -= tsz;
start += tsz;
len += tsz;
if (size == 0)
return 0;
}
if (start < elfcorebuf_sz + elfnotes_sz) {
void *kaddr;
tsz = min(elfcorebuf_sz + elfnotes_sz - (size_t)start, size);
kaddr = elfnotes_buf + start - elfcorebuf_sz;
if (remap_vmalloc_range_partial(vma, vma->vm_start + len,
kaddr, tsz))
goto fail;
size -= tsz;
start += tsz;
len += tsz;
if (size == 0)
return 0;
}
list_for_each_entry(m, &vmcore_list, list) {
if (start < m->offset + m->size) {
u64 paddr = 0;
tsz = min_t(size_t, m->offset + m->size - start, size);
paddr = m->paddr + start - m->offset;
if (vmcore_remap_oldmem_pfn(vma, vma->vm_start + len,
paddr >> PAGE_SHIFT, tsz,
vma->vm_page_prot))
goto fail;
size -= tsz;
start += tsz;
len += tsz;
if (size == 0)
return 0;
}
}
return 0;
fail:
do_munmap(vma->vm_mm, vma->vm_start, len);
return -EAGAIN;
}
static int mmap_vmcore(struct file *file, struct vm_area_struct *vma)
{
return -ENOSYS;
}
static struct vmcore* __init get_new_element(void)
{
return kzalloc(sizeof(struct vmcore), GFP_KERNEL);
}
static u64 __init get_vmcore_size(size_t elfsz, size_t elfnotesegsz,
struct list_head *vc_list)
{
u64 size;
struct vmcore *m;
size = elfsz + elfnotesegsz;
list_for_each_entry(m, vc_list, list) {
size += m->size;
}
return size;
}
static int __init update_note_header_size_elf64(const Elf64_Ehdr *ehdr_ptr)
{
int i, rc=0;
Elf64_Phdr *phdr_ptr;
Elf64_Nhdr *nhdr_ptr;
phdr_ptr = (Elf64_Phdr *)(ehdr_ptr + 1);
for (i = 0; i < ehdr_ptr->e_phnum; i++, phdr_ptr++) {
void *notes_section;
u64 offset, max_sz, sz, real_sz = 0;
if (phdr_ptr->p_type != PT_NOTE)
continue;
max_sz = phdr_ptr->p_memsz;
offset = phdr_ptr->p_offset;
notes_section = kmalloc(max_sz, GFP_KERNEL);
if (!notes_section)
return -ENOMEM;
rc = elfcorehdr_read_notes(notes_section, max_sz, &offset);
if (rc < 0) {
kfree(notes_section);
return rc;
}
nhdr_ptr = notes_section;
while (nhdr_ptr->n_namesz != 0) {
sz = sizeof(Elf64_Nhdr) +
((nhdr_ptr->n_namesz + 3) & ~3) +
((nhdr_ptr->n_descsz + 3) & ~3);
if ((real_sz + sz) > max_sz) {
pr_warn("Warning: Exceeded p_memsz, dropping PT_NOTE entry n_namesz=0x%x, n_descsz=0x%x\n",
nhdr_ptr->n_namesz, nhdr_ptr->n_descsz);
break;
}
real_sz += sz;
nhdr_ptr = (Elf64_Nhdr*)((char*)nhdr_ptr + sz);
}
kfree(notes_section);
phdr_ptr->p_memsz = real_sz;
if (real_sz == 0) {
pr_warn("Warning: Zero PT_NOTE entries found\n");
}
}
return 0;
}
static int __init get_note_number_and_size_elf64(const Elf64_Ehdr *ehdr_ptr,
int *nr_ptnote, u64 *sz_ptnote)
{
int i;
Elf64_Phdr *phdr_ptr;
*nr_ptnote = *sz_ptnote = 0;
phdr_ptr = (Elf64_Phdr *)(ehdr_ptr + 1);
for (i = 0; i < ehdr_ptr->e_phnum; i++, phdr_ptr++) {
if (phdr_ptr->p_type != PT_NOTE)
continue;
*nr_ptnote += 1;
*sz_ptnote += phdr_ptr->p_memsz;
}
return 0;
}
static int __init copy_notes_elf64(const Elf64_Ehdr *ehdr_ptr, char *notes_buf)
{
int i, rc=0;
Elf64_Phdr *phdr_ptr;
phdr_ptr = (Elf64_Phdr*)(ehdr_ptr + 1);
for (i = 0; i < ehdr_ptr->e_phnum; i++, phdr_ptr++) {
u64 offset;
if (phdr_ptr->p_type != PT_NOTE)
continue;
offset = phdr_ptr->p_offset;
rc = elfcorehdr_read_notes(notes_buf, phdr_ptr->p_memsz,
&offset);
if (rc < 0)
return rc;
notes_buf += phdr_ptr->p_memsz;
}
return 0;
}
static int __init merge_note_headers_elf64(char *elfptr, size_t *elfsz,
char **notes_buf, size_t *notes_sz)
{
int i, nr_ptnote=0, rc=0;
char *tmp;
Elf64_Ehdr *ehdr_ptr;
Elf64_Phdr phdr;
u64 phdr_sz = 0, note_off;
ehdr_ptr = (Elf64_Ehdr *)elfptr;
rc = update_note_header_size_elf64(ehdr_ptr);
if (rc < 0)
return rc;
rc = get_note_number_and_size_elf64(ehdr_ptr, &nr_ptnote, &phdr_sz);
if (rc < 0)
return rc;
*notes_sz = roundup(phdr_sz, PAGE_SIZE);
*notes_buf = alloc_elfnotes_buf(*notes_sz);
if (!*notes_buf)
return -ENOMEM;
rc = copy_notes_elf64(ehdr_ptr, *notes_buf);
if (rc < 0)
return rc;
phdr.p_type = PT_NOTE;
phdr.p_flags = 0;
note_off = sizeof(Elf64_Ehdr) +
(ehdr_ptr->e_phnum - nr_ptnote +1) * sizeof(Elf64_Phdr);
phdr.p_offset = roundup(note_off, PAGE_SIZE);
phdr.p_vaddr = phdr.p_paddr = 0;
phdr.p_filesz = phdr.p_memsz = phdr_sz;
phdr.p_align = 0;
tmp = elfptr + sizeof(Elf64_Ehdr);
memcpy(tmp, &phdr, sizeof(phdr));
tmp += sizeof(phdr);
i = (nr_ptnote - 1) * sizeof(Elf64_Phdr);
*elfsz = *elfsz - i;
memmove(tmp, tmp+i, ((*elfsz)-sizeof(Elf64_Ehdr)-sizeof(Elf64_Phdr)));
memset(elfptr + *elfsz, 0, i);
*elfsz = roundup(*elfsz, PAGE_SIZE);
ehdr_ptr->e_phnum = ehdr_ptr->e_phnum - nr_ptnote + 1;
return 0;
}
static int __init update_note_header_size_elf32(const Elf32_Ehdr *ehdr_ptr)
{
int i, rc=0;
Elf32_Phdr *phdr_ptr;
Elf32_Nhdr *nhdr_ptr;
phdr_ptr = (Elf32_Phdr *)(ehdr_ptr + 1);
for (i = 0; i < ehdr_ptr->e_phnum; i++, phdr_ptr++) {
void *notes_section;
u64 offset, max_sz, sz, real_sz = 0;
if (phdr_ptr->p_type != PT_NOTE)
continue;
max_sz = phdr_ptr->p_memsz;
offset = phdr_ptr->p_offset;
notes_section = kmalloc(max_sz, GFP_KERNEL);
if (!notes_section)
return -ENOMEM;
rc = elfcorehdr_read_notes(notes_section, max_sz, &offset);
if (rc < 0) {
kfree(notes_section);
return rc;
}
nhdr_ptr = notes_section;
while (nhdr_ptr->n_namesz != 0) {
sz = sizeof(Elf32_Nhdr) +
((nhdr_ptr->n_namesz + 3) & ~3) +
((nhdr_ptr->n_descsz + 3) & ~3);
if ((real_sz + sz) > max_sz) {
pr_warn("Warning: Exceeded p_memsz, dropping PT_NOTE entry n_namesz=0x%x, n_descsz=0x%x\n",
nhdr_ptr->n_namesz, nhdr_ptr->n_descsz);
break;
}
real_sz += sz;
nhdr_ptr = (Elf32_Nhdr*)((char*)nhdr_ptr + sz);
}
kfree(notes_section);
phdr_ptr->p_memsz = real_sz;
if (real_sz == 0) {
pr_warn("Warning: Zero PT_NOTE entries found\n");
}
}
return 0;
}
static int __init get_note_number_and_size_elf32(const Elf32_Ehdr *ehdr_ptr,
int *nr_ptnote, u64 *sz_ptnote)
{
int i;
Elf32_Phdr *phdr_ptr;
*nr_ptnote = *sz_ptnote = 0;
phdr_ptr = (Elf32_Phdr *)(ehdr_ptr + 1);
for (i = 0; i < ehdr_ptr->e_phnum; i++, phdr_ptr++) {
if (phdr_ptr->p_type != PT_NOTE)
continue;
*nr_ptnote += 1;
*sz_ptnote += phdr_ptr->p_memsz;
}
return 0;
}
static int __init copy_notes_elf32(const Elf32_Ehdr *ehdr_ptr, char *notes_buf)
{
int i, rc=0;
Elf32_Phdr *phdr_ptr;
phdr_ptr = (Elf32_Phdr*)(ehdr_ptr + 1);
for (i = 0; i < ehdr_ptr->e_phnum; i++, phdr_ptr++) {
u64 offset;
if (phdr_ptr->p_type != PT_NOTE)
continue;
offset = phdr_ptr->p_offset;
rc = elfcorehdr_read_notes(notes_buf, phdr_ptr->p_memsz,
&offset);
if (rc < 0)
return rc;
notes_buf += phdr_ptr->p_memsz;
}
return 0;
}
static int __init merge_note_headers_elf32(char *elfptr, size_t *elfsz,
char **notes_buf, size_t *notes_sz)
{
int i, nr_ptnote=0, rc=0;
char *tmp;
Elf32_Ehdr *ehdr_ptr;
Elf32_Phdr phdr;
u64 phdr_sz = 0, note_off;
ehdr_ptr = (Elf32_Ehdr *)elfptr;
rc = update_note_header_size_elf32(ehdr_ptr);
if (rc < 0)
return rc;
rc = get_note_number_and_size_elf32(ehdr_ptr, &nr_ptnote, &phdr_sz);
if (rc < 0)
return rc;
*notes_sz = roundup(phdr_sz, PAGE_SIZE);
*notes_buf = alloc_elfnotes_buf(*notes_sz);
if (!*notes_buf)
return -ENOMEM;
rc = copy_notes_elf32(ehdr_ptr, *notes_buf);
if (rc < 0)
return rc;
phdr.p_type = PT_NOTE;
phdr.p_flags = 0;
note_off = sizeof(Elf32_Ehdr) +
(ehdr_ptr->e_phnum - nr_ptnote +1) * sizeof(Elf32_Phdr);
phdr.p_offset = roundup(note_off, PAGE_SIZE);
phdr.p_vaddr = phdr.p_paddr = 0;
phdr.p_filesz = phdr.p_memsz = phdr_sz;
phdr.p_align = 0;
tmp = elfptr + sizeof(Elf32_Ehdr);
memcpy(tmp, &phdr, sizeof(phdr));
tmp += sizeof(phdr);
i = (nr_ptnote - 1) * sizeof(Elf32_Phdr);
*elfsz = *elfsz - i;
memmove(tmp, tmp+i, ((*elfsz)-sizeof(Elf32_Ehdr)-sizeof(Elf32_Phdr)));
memset(elfptr + *elfsz, 0, i);
*elfsz = roundup(*elfsz, PAGE_SIZE);
ehdr_ptr->e_phnum = ehdr_ptr->e_phnum - nr_ptnote + 1;
return 0;
}
static int __init process_ptload_program_headers_elf64(char *elfptr,
size_t elfsz,
size_t elfnotes_sz,
struct list_head *vc_list)
{
int i;
Elf64_Ehdr *ehdr_ptr;
Elf64_Phdr *phdr_ptr;
loff_t vmcore_off;
struct vmcore *new;
ehdr_ptr = (Elf64_Ehdr *)elfptr;
phdr_ptr = (Elf64_Phdr*)(elfptr + sizeof(Elf64_Ehdr));
vmcore_off = elfsz + elfnotes_sz;
for (i = 0; i < ehdr_ptr->e_phnum; i++, phdr_ptr++) {
u64 paddr, start, end, size;
if (phdr_ptr->p_type != PT_LOAD)
continue;
paddr = phdr_ptr->p_offset;
start = rounddown(paddr, PAGE_SIZE);
end = roundup(paddr + phdr_ptr->p_memsz, PAGE_SIZE);
size = end - start;
new = get_new_element();
if (!new)
return -ENOMEM;
new->paddr = start;
new->size = size;
list_add_tail(&new->list, vc_list);
phdr_ptr->p_offset = vmcore_off + (paddr - start);
vmcore_off = vmcore_off + size;
}
return 0;
}
static int __init process_ptload_program_headers_elf32(char *elfptr,
size_t elfsz,
size_t elfnotes_sz,
struct list_head *vc_list)
{
int i;
Elf32_Ehdr *ehdr_ptr;
Elf32_Phdr *phdr_ptr;
loff_t vmcore_off;
struct vmcore *new;
ehdr_ptr = (Elf32_Ehdr *)elfptr;
phdr_ptr = (Elf32_Phdr*)(elfptr + sizeof(Elf32_Ehdr));
vmcore_off = elfsz + elfnotes_sz;
for (i = 0; i < ehdr_ptr->e_phnum; i++, phdr_ptr++) {
u64 paddr, start, end, size;
if (phdr_ptr->p_type != PT_LOAD)
continue;
paddr = phdr_ptr->p_offset;
start = rounddown(paddr, PAGE_SIZE);
end = roundup(paddr + phdr_ptr->p_memsz, PAGE_SIZE);
size = end - start;
new = get_new_element();
if (!new)
return -ENOMEM;
new->paddr = start;
new->size = size;
list_add_tail(&new->list, vc_list);
phdr_ptr->p_offset = vmcore_off + (paddr - start);
vmcore_off = vmcore_off + size;
}
return 0;
}
static void __init set_vmcore_list_offsets(size_t elfsz, size_t elfnotes_sz,
struct list_head *vc_list)
{
loff_t vmcore_off;
struct vmcore *m;
vmcore_off = elfsz + elfnotes_sz;
list_for_each_entry(m, vc_list, list) {
m->offset = vmcore_off;
vmcore_off += m->size;
}
}
static void free_elfcorebuf(void)
{
free_pages((unsigned long)elfcorebuf, get_order(elfcorebuf_sz_orig));
elfcorebuf = NULL;
vfree(elfnotes_buf);
elfnotes_buf = NULL;
}
static int __init parse_crash_elf64_headers(void)
{
int rc=0;
Elf64_Ehdr ehdr;
u64 addr;
addr = elfcorehdr_addr;
rc = elfcorehdr_read((char *)&ehdr, sizeof(Elf64_Ehdr), &addr);
if (rc < 0)
return rc;
if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0 ||
(ehdr.e_type != ET_CORE) ||
!vmcore_elf64_check_arch(&ehdr) ||
ehdr.e_ident[EI_CLASS] != ELFCLASS64 ||
ehdr.e_ident[EI_VERSION] != EV_CURRENT ||
ehdr.e_version != EV_CURRENT ||
ehdr.e_ehsize != sizeof(Elf64_Ehdr) ||
ehdr.e_phentsize != sizeof(Elf64_Phdr) ||
ehdr.e_phnum == 0) {
pr_warn("Warning: Core image elf header is not sane\n");
return -EINVAL;
}
elfcorebuf_sz_orig = sizeof(Elf64_Ehdr) +
ehdr.e_phnum * sizeof(Elf64_Phdr);
elfcorebuf_sz = elfcorebuf_sz_orig;
elfcorebuf = (void *)__get_free_pages(GFP_KERNEL | __GFP_ZERO,
get_order(elfcorebuf_sz_orig));
if (!elfcorebuf)
return -ENOMEM;
addr = elfcorehdr_addr;
rc = elfcorehdr_read(elfcorebuf, elfcorebuf_sz_orig, &addr);
if (rc < 0)
goto fail;
rc = merge_note_headers_elf64(elfcorebuf, &elfcorebuf_sz,
&elfnotes_buf, &elfnotes_sz);
if (rc)
goto fail;
rc = process_ptload_program_headers_elf64(elfcorebuf, elfcorebuf_sz,
elfnotes_sz, &vmcore_list);
if (rc)
goto fail;
set_vmcore_list_offsets(elfcorebuf_sz, elfnotes_sz, &vmcore_list);
return 0;
fail:
free_elfcorebuf();
return rc;
}
static int __init parse_crash_elf32_headers(void)
{
int rc=0;
Elf32_Ehdr ehdr;
u64 addr;
addr = elfcorehdr_addr;
rc = elfcorehdr_read((char *)&ehdr, sizeof(Elf32_Ehdr), &addr);
if (rc < 0)
return rc;
if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0 ||
(ehdr.e_type != ET_CORE) ||
!elf_check_arch(&ehdr) ||
ehdr.e_ident[EI_CLASS] != ELFCLASS32||
ehdr.e_ident[EI_VERSION] != EV_CURRENT ||
ehdr.e_version != EV_CURRENT ||
ehdr.e_ehsize != sizeof(Elf32_Ehdr) ||
ehdr.e_phentsize != sizeof(Elf32_Phdr) ||
ehdr.e_phnum == 0) {
pr_warn("Warning: Core image elf header is not sane\n");
return -EINVAL;
}
elfcorebuf_sz_orig = sizeof(Elf32_Ehdr) + ehdr.e_phnum * sizeof(Elf32_Phdr);
elfcorebuf_sz = elfcorebuf_sz_orig;
elfcorebuf = (void *)__get_free_pages(GFP_KERNEL | __GFP_ZERO,
get_order(elfcorebuf_sz_orig));
if (!elfcorebuf)
return -ENOMEM;
addr = elfcorehdr_addr;
rc = elfcorehdr_read(elfcorebuf, elfcorebuf_sz_orig, &addr);
if (rc < 0)
goto fail;
rc = merge_note_headers_elf32(elfcorebuf, &elfcorebuf_sz,
&elfnotes_buf, &elfnotes_sz);
if (rc)
goto fail;
rc = process_ptload_program_headers_elf32(elfcorebuf, elfcorebuf_sz,
elfnotes_sz, &vmcore_list);
if (rc)
goto fail;
set_vmcore_list_offsets(elfcorebuf_sz, elfnotes_sz, &vmcore_list);
return 0;
fail:
free_elfcorebuf();
return rc;
}
static int __init parse_crash_elf_headers(void)
{
unsigned char e_ident[EI_NIDENT];
u64 addr;
int rc=0;
addr = elfcorehdr_addr;
rc = elfcorehdr_read(e_ident, EI_NIDENT, &addr);
if (rc < 0)
return rc;
if (memcmp(e_ident, ELFMAG, SELFMAG) != 0) {
pr_warn("Warning: Core image elf header not found\n");
return -EINVAL;
}
if (e_ident[EI_CLASS] == ELFCLASS64) {
rc = parse_crash_elf64_headers();
if (rc)
return rc;
} else if (e_ident[EI_CLASS] == ELFCLASS32) {
rc = parse_crash_elf32_headers();
if (rc)
return rc;
} else {
pr_warn("Warning: Core image elf header is not sane\n");
return -EINVAL;
}
vmcore_size = get_vmcore_size(elfcorebuf_sz, elfnotes_sz,
&vmcore_list);
return 0;
}
static int __init vmcore_init(void)
{
int rc = 0;
rc = elfcorehdr_alloc(&elfcorehdr_addr, &elfcorehdr_size);
if (rc)
return rc;
if (!(is_vmcore_usable()))
return rc;
rc = parse_crash_elf_headers();
if (rc) {
pr_warn("Kdump: vmcore not initialized\n");
return rc;
}
elfcorehdr_free(elfcorehdr_addr);
elfcorehdr_addr = ELFCORE_ADDR_ERR;
proc_vmcore = proc_create("vmcore", S_IRUSR, NULL, &proc_vmcore_operations);
if (proc_vmcore)
proc_vmcore->size = vmcore_size;
return 0;
}
void vmcore_cleanup(void)
{
struct list_head *pos, *next;
if (proc_vmcore) {
proc_remove(proc_vmcore);
proc_vmcore = NULL;
}
list_for_each_safe(pos, next, &vmcore_list) {
struct vmcore *m;
m = list_entry(pos, struct vmcore, list);
list_del(&m->list);
kfree(m);
}
free_elfcorebuf();
}
