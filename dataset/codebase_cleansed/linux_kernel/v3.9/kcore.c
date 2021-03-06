void
kclist_add(struct kcore_list *new, void *addr, size_t size, int type)
{
new->addr = (unsigned long)addr;
new->size = size;
new->type = type;
write_lock(&kclist_lock);
list_add_tail(&new->list, &kclist_head);
write_unlock(&kclist_lock);
}
static size_t get_kcore_size(int *nphdr, size_t *elf_buflen)
{
size_t try, size;
struct kcore_list *m;
*nphdr = 1;
size = 0;
list_for_each_entry(m, &kclist_head, list) {
try = kc_vaddr_to_offset((size_t)m->addr + m->size);
if (try > size)
size = try;
*nphdr = *nphdr + 1;
}
*elf_buflen = sizeof(struct elfhdr) +
(*nphdr + 2)*sizeof(struct elf_phdr) +
3 * ((sizeof(struct elf_note)) +
roundup(sizeof(CORE_STR), 4)) +
roundup(sizeof(struct elf_prstatus), 4) +
roundup(sizeof(struct elf_prpsinfo), 4) +
roundup(sizeof(struct task_struct), 4);
*elf_buflen = PAGE_ALIGN(*elf_buflen);
return size + *elf_buflen;
}
static void free_kclist_ents(struct list_head *head)
{
struct kcore_list *tmp, *pos;
list_for_each_entry_safe(pos, tmp, head, list) {
list_del(&pos->list);
kfree(pos);
}
}
static void __kcore_update_ram(struct list_head *list)
{
int nphdr;
size_t size;
struct kcore_list *tmp, *pos;
LIST_HEAD(garbage);
write_lock(&kclist_lock);
if (kcore_need_update) {
list_for_each_entry_safe(pos, tmp, &kclist_head, list) {
if (pos->type == KCORE_RAM
|| pos->type == KCORE_VMEMMAP)
list_move(&pos->list, &garbage);
}
list_splice_tail(list, &kclist_head);
} else
list_splice(list, &garbage);
kcore_need_update = 0;
proc_root_kcore->size = get_kcore_size(&nphdr, &size);
write_unlock(&kclist_lock);
free_kclist_ents(&garbage);
}
static int kcore_update_ram(void)
{
LIST_HEAD(head);
struct kcore_list *ent;
int ret = 0;
ent = kmalloc(sizeof(*ent), GFP_KERNEL);
if (!ent)
return -ENOMEM;
ent->addr = (unsigned long)__va(0);
ent->size = max_low_pfn << PAGE_SHIFT;
ent->type = KCORE_RAM;
list_add(&ent->list, &head);
__kcore_update_ram(&head);
return ret;
}
static int
get_sparsemem_vmemmap_info(struct kcore_list *ent, struct list_head *head)
{
unsigned long pfn = __pa(ent->addr) >> PAGE_SHIFT;
unsigned long nr_pages = ent->size >> PAGE_SHIFT;
unsigned long start, end;
struct kcore_list *vmm, *tmp;
start = ((unsigned long)pfn_to_page(pfn)) & PAGE_MASK;
end = ((unsigned long)pfn_to_page(pfn + nr_pages)) - 1;
end = ALIGN(end, PAGE_SIZE);
list_for_each_entry(tmp, head, list) {
if (tmp->type != KCORE_VMEMMAP)
continue;
if (start < tmp->addr + tmp->size)
if (end > tmp->addr)
end = tmp->addr;
}
if (start < end) {
vmm = kmalloc(sizeof(*vmm), GFP_KERNEL);
if (!vmm)
return 0;
vmm->addr = start;
vmm->size = end - start;
vmm->type = KCORE_VMEMMAP;
list_add_tail(&vmm->list, head);
}
return 1;
}
static int
get_sparsemem_vmemmap_info(struct kcore_list *ent, struct list_head *head)
{
return 1;
}
static int
kclist_add_private(unsigned long pfn, unsigned long nr_pages, void *arg)
{
struct list_head *head = (struct list_head *)arg;
struct kcore_list *ent;
ent = kmalloc(sizeof(*ent), GFP_KERNEL);
if (!ent)
return -ENOMEM;
ent->addr = (unsigned long)__va((pfn << PAGE_SHIFT));
ent->size = nr_pages << PAGE_SHIFT;
if (ent->addr < (unsigned long) __va(0))
goto free_out;
if (ULONG_MAX - ent->addr < ent->size)
ent->size = ULONG_MAX - ent->addr;
if (VMALLOC_START > (unsigned long)__va(0)) {
if (ent->addr > VMALLOC_START)
goto free_out;
if (VMALLOC_START - ent->addr < ent->size)
ent->size = VMALLOC_START - ent->addr;
}
ent->type = KCORE_RAM;
list_add_tail(&ent->list, head);
if (!get_sparsemem_vmemmap_info(ent, head)) {
list_del(&ent->list);
goto free_out;
}
return 0;
free_out:
kfree(ent);
return 1;
}
static int kcore_update_ram(void)
{
int nid, ret;
unsigned long end_pfn;
LIST_HEAD(head);
end_pfn = 0;
for_each_node_state(nid, N_MEMORY) {
unsigned long node_end;
node_end = NODE_DATA(nid)->node_start_pfn +
NODE_DATA(nid)->node_spanned_pages;
if (end_pfn < node_end)
end_pfn = node_end;
}
ret = walk_system_ram_range(0, end_pfn, &head, kclist_add_private);
if (ret) {
free_kclist_ents(&head);
return -ENOMEM;
}
__kcore_update_ram(&head);
return ret;
}
static int notesize(struct memelfnote *en)
{
int sz;
sz = sizeof(struct elf_note);
sz += roundup((strlen(en->name) + 1), 4);
sz += roundup(en->datasz, 4);
return sz;
}
static char *storenote(struct memelfnote *men, char *bufp)
{
struct elf_note en;
#define DUMP_WRITE(addr,nr) do { memcpy(bufp,addr,nr); bufp += nr; } while(0)
en.n_namesz = strlen(men->name) + 1;
en.n_descsz = men->datasz;
en.n_type = men->type;
DUMP_WRITE(&en, sizeof(en));
DUMP_WRITE(men->name, en.n_namesz);
bufp = (char*) roundup((unsigned long)bufp,4);
DUMP_WRITE(men->data, men->datasz);
bufp = (char*) roundup((unsigned long)bufp,4);
#undef DUMP_WRITE
return bufp;
}
static void elf_kcore_store_hdr(char *bufp, int nphdr, int dataoff)
{
struct elf_prstatus prstatus;
struct elf_prpsinfo prpsinfo;
struct elf_phdr *nhdr, *phdr;
struct elfhdr *elf;
struct memelfnote notes[3];
off_t offset = 0;
struct kcore_list *m;
elf = (struct elfhdr *) bufp;
bufp += sizeof(struct elfhdr);
offset += sizeof(struct elfhdr);
memcpy(elf->e_ident, ELFMAG, SELFMAG);
elf->e_ident[EI_CLASS] = ELF_CLASS;
elf->e_ident[EI_DATA] = ELF_DATA;
elf->e_ident[EI_VERSION]= EV_CURRENT;
elf->e_ident[EI_OSABI] = ELF_OSABI;
memset(elf->e_ident+EI_PAD, 0, EI_NIDENT-EI_PAD);
elf->e_type = ET_CORE;
elf->e_machine = ELF_ARCH;
elf->e_version = EV_CURRENT;
elf->e_entry = 0;
elf->e_phoff = sizeof(struct elfhdr);
elf->e_shoff = 0;
elf->e_flags = ELF_CORE_EFLAGS;
elf->e_ehsize = sizeof(struct elfhdr);
elf->e_phentsize= sizeof(struct elf_phdr);
elf->e_phnum = nphdr;
elf->e_shentsize= 0;
elf->e_shnum = 0;
elf->e_shstrndx = 0;
nhdr = (struct elf_phdr *) bufp;
bufp += sizeof(struct elf_phdr);
offset += sizeof(struct elf_phdr);
nhdr->p_type = PT_NOTE;
nhdr->p_offset = 0;
nhdr->p_vaddr = 0;
nhdr->p_paddr = 0;
nhdr->p_filesz = 0;
nhdr->p_memsz = 0;
nhdr->p_flags = 0;
nhdr->p_align = 0;
list_for_each_entry(m, &kclist_head, list) {
phdr = (struct elf_phdr *) bufp;
bufp += sizeof(struct elf_phdr);
offset += sizeof(struct elf_phdr);
phdr->p_type = PT_LOAD;
phdr->p_flags = PF_R|PF_W|PF_X;
phdr->p_offset = kc_vaddr_to_offset(m->addr) + dataoff;
phdr->p_vaddr = (size_t)m->addr;
phdr->p_paddr = 0;
phdr->p_filesz = phdr->p_memsz = m->size;
phdr->p_align = PAGE_SIZE;
}
nhdr->p_offset = offset;
notes[0].name = CORE_STR;
notes[0].type = NT_PRSTATUS;
notes[0].datasz = sizeof(struct elf_prstatus);
notes[0].data = &prstatus;
memset(&prstatus, 0, sizeof(struct elf_prstatus));
nhdr->p_filesz = notesize(&notes[0]);
bufp = storenote(&notes[0], bufp);
notes[1].name = CORE_STR;
notes[1].type = NT_PRPSINFO;
notes[1].datasz = sizeof(struct elf_prpsinfo);
notes[1].data = &prpsinfo;
memset(&prpsinfo, 0, sizeof(struct elf_prpsinfo));
prpsinfo.pr_state = 0;
prpsinfo.pr_sname = 'R';
prpsinfo.pr_zomb = 0;
strcpy(prpsinfo.pr_fname, "vmlinux");
strncpy(prpsinfo.pr_psargs, saved_command_line, ELF_PRARGSZ);
nhdr->p_filesz += notesize(&notes[1]);
bufp = storenote(&notes[1], bufp);
notes[2].name = CORE_STR;
notes[2].type = NT_TASKSTRUCT;
notes[2].datasz = sizeof(struct task_struct);
notes[2].data = current;
nhdr->p_filesz += notesize(&notes[2]);
bufp = storenote(&notes[2], bufp);
}
static ssize_t
read_kcore(struct file *file, char __user *buffer, size_t buflen, loff_t *fpos)
{
ssize_t acc = 0;
size_t size, tsz;
size_t elf_buflen;
int nphdr;
unsigned long start;
read_lock(&kclist_lock);
size = get_kcore_size(&nphdr, &elf_buflen);
if (buflen == 0 || *fpos >= size) {
read_unlock(&kclist_lock);
return 0;
}
if (buflen > size - *fpos)
buflen = size - *fpos;
if (*fpos < elf_buflen) {
char * elf_buf;
tsz = elf_buflen - *fpos;
if (buflen < tsz)
tsz = buflen;
elf_buf = kzalloc(elf_buflen, GFP_ATOMIC);
if (!elf_buf) {
read_unlock(&kclist_lock);
return -ENOMEM;
}
elf_kcore_store_hdr(elf_buf, nphdr, elf_buflen);
read_unlock(&kclist_lock);
if (copy_to_user(buffer, elf_buf + *fpos, tsz)) {
kfree(elf_buf);
return -EFAULT;
}
kfree(elf_buf);
buflen -= tsz;
*fpos += tsz;
buffer += tsz;
acc += tsz;
if (buflen == 0)
return acc;
} else
read_unlock(&kclist_lock);
start = kc_offset_to_vaddr(*fpos - elf_buflen);
if ((tsz = (PAGE_SIZE - (start & ~PAGE_MASK))) > buflen)
tsz = buflen;
while (buflen) {
struct kcore_list *m;
read_lock(&kclist_lock);
list_for_each_entry(m, &kclist_head, list) {
if (start >= m->addr && start < (m->addr+m->size))
break;
}
read_unlock(&kclist_lock);
if (&m->list == &kclist_head) {
if (clear_user(buffer, tsz))
return -EFAULT;
} else if (is_vmalloc_or_module_addr((void *)start)) {
char * elf_buf;
elf_buf = kzalloc(tsz, GFP_KERNEL);
if (!elf_buf)
return -ENOMEM;
vread(elf_buf, (char *)start, tsz);
if (copy_to_user(buffer, elf_buf, tsz)) {
kfree(elf_buf);
return -EFAULT;
}
kfree(elf_buf);
} else {
if (kern_addr_valid(start)) {
unsigned long n;
n = copy_to_user(buffer, (char *)start, tsz);
if (n) {
if (clear_user(buffer + tsz - n,
n))
return -EFAULT;
}
} else {
if (clear_user(buffer, tsz))
return -EFAULT;
}
}
buflen -= tsz;
*fpos += tsz;
buffer += tsz;
acc += tsz;
start += tsz;
tsz = (buflen > PAGE_SIZE ? PAGE_SIZE : buflen);
}
return acc;
}
static int open_kcore(struct inode *inode, struct file *filp)
{
if (!capable(CAP_SYS_RAWIO))
return -EPERM;
if (kcore_need_update)
kcore_update_ram();
if (i_size_read(inode) != proc_root_kcore->size) {
mutex_lock(&inode->i_mutex);
i_size_write(inode, proc_root_kcore->size);
mutex_unlock(&inode->i_mutex);
}
return 0;
}
static int __meminit kcore_callback(struct notifier_block *self,
unsigned long action, void *arg)
{
switch (action) {
case MEM_ONLINE:
case MEM_OFFLINE:
write_lock(&kclist_lock);
kcore_need_update = 1;
write_unlock(&kclist_lock);
}
return NOTIFY_OK;
}
static void __init proc_kcore_text_init(void)
{
kclist_add(&kcore_text, _text, _end - _text, KCORE_TEXT);
}
static void __init proc_kcore_text_init(void)
{
}
static void __init add_modules_range(void)
{
kclist_add(&kcore_modules, (void *)MODULES_VADDR,
MODULES_END - MODULES_VADDR, KCORE_VMALLOC);
}
static void __init add_modules_range(void)
{
}
static int __init proc_kcore_init(void)
{
proc_root_kcore = proc_create("kcore", S_IRUSR, NULL,
&proc_kcore_operations);
if (!proc_root_kcore) {
pr_err("couldn't create /proc/kcore\n");
return 0;
}
proc_kcore_text_init();
kclist_add(&kcore_vmalloc, (void *)VMALLOC_START,
VMALLOC_END - VMALLOC_START, KCORE_VMALLOC);
add_modules_range();
kcore_update_ram();
hotplug_memory_notifier(kcore_callback, 0);
return 0;
}
