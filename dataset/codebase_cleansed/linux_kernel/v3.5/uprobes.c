static bool valid_vma(struct vm_area_struct *vma, bool is_register)
{
if (!vma->vm_file)
return false;
if (!is_register)
return true;
if ((vma->vm_flags & (VM_READ|VM_WRITE|VM_EXEC|VM_SHARED)) == (VM_READ|VM_EXEC))
return true;
return false;
}
static loff_t vma_address(struct vm_area_struct *vma, loff_t offset)
{
loff_t vaddr;
vaddr = vma->vm_start + offset;
vaddr -= vma->vm_pgoff << PAGE_SHIFT;
return vaddr;
}
static int __replace_page(struct vm_area_struct *vma, struct page *page, struct page *kpage)
{
struct mm_struct *mm = vma->vm_mm;
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
pte_t *ptep;
spinlock_t *ptl;
unsigned long addr;
int err = -EFAULT;
addr = page_address_in_vma(page, vma);
if (addr == -EFAULT)
goto out;
pgd = pgd_offset(mm, addr);
if (!pgd_present(*pgd))
goto out;
pud = pud_offset(pgd, addr);
if (!pud_present(*pud))
goto out;
pmd = pmd_offset(pud, addr);
if (!pmd_present(*pmd))
goto out;
ptep = pte_offset_map_lock(mm, pmd, addr, &ptl);
if (!ptep)
goto out;
get_page(kpage);
page_add_new_anon_rmap(kpage, vma, addr);
if (!PageAnon(page)) {
dec_mm_counter(mm, MM_FILEPAGES);
inc_mm_counter(mm, MM_ANONPAGES);
}
flush_cache_page(vma, addr, pte_pfn(*ptep));
ptep_clear_flush(vma, addr, ptep);
set_pte_at_notify(mm, addr, ptep, mk_pte(kpage, vma->vm_page_prot));
page_remove_rmap(page);
if (!page_mapped(page))
try_to_free_swap(page);
put_page(page);
pte_unmap_unlock(ptep, ptl);
err = 0;
out:
return err;
}
bool __weak is_swbp_insn(uprobe_opcode_t *insn)
{
return *insn == UPROBE_SWBP_INSN;
}
static int write_opcode(struct arch_uprobe *auprobe, struct mm_struct *mm,
unsigned long vaddr, uprobe_opcode_t opcode)
{
struct page *old_page, *new_page;
struct address_space *mapping;
void *vaddr_old, *vaddr_new;
struct vm_area_struct *vma;
struct uprobe *uprobe;
loff_t addr;
int ret;
ret = get_user_pages(NULL, mm, vaddr, 1, 0, 0, &old_page, &vma);
if (ret <= 0)
return ret;
ret = -EINVAL;
if (!valid_vma(vma, is_swbp_insn(&opcode)))
goto put_out;
uprobe = container_of(auprobe, struct uprobe, arch);
mapping = uprobe->inode->i_mapping;
if (mapping != vma->vm_file->f_mapping)
goto put_out;
addr = vma_address(vma, uprobe->offset);
if (vaddr != (unsigned long)addr)
goto put_out;
ret = -ENOMEM;
new_page = alloc_page_vma(GFP_HIGHUSER_MOVABLE, vma, vaddr);
if (!new_page)
goto put_out;
__SetPageUptodate(new_page);
lock_page(old_page);
vaddr_old = kmap_atomic(old_page);
vaddr_new = kmap_atomic(new_page);
memcpy(vaddr_new, vaddr_old, PAGE_SIZE);
vaddr &= ~PAGE_MASK;
BUG_ON(vaddr + UPROBE_SWBP_INSN_SIZE > PAGE_SIZE);
memcpy(vaddr_new + vaddr, &opcode, UPROBE_SWBP_INSN_SIZE);
kunmap_atomic(vaddr_new);
kunmap_atomic(vaddr_old);
ret = anon_vma_prepare(vma);
if (ret)
goto unlock_out;
lock_page(new_page);
ret = __replace_page(vma, old_page, new_page);
unlock_page(new_page);
unlock_out:
unlock_page(old_page);
page_cache_release(new_page);
put_out:
put_page(old_page);
return ret;
}
static int read_opcode(struct mm_struct *mm, unsigned long vaddr, uprobe_opcode_t *opcode)
{
struct page *page;
void *vaddr_new;
int ret;
ret = get_user_pages(NULL, mm, vaddr, 1, 0, 0, &page, NULL);
if (ret <= 0)
return ret;
lock_page(page);
vaddr_new = kmap_atomic(page);
vaddr &= ~PAGE_MASK;
memcpy(opcode, vaddr_new + vaddr, UPROBE_SWBP_INSN_SIZE);
kunmap_atomic(vaddr_new);
unlock_page(page);
put_page(page);
return 0;
}
static int is_swbp_at_addr(struct mm_struct *mm, unsigned long vaddr)
{
uprobe_opcode_t opcode;
int result;
result = read_opcode(mm, vaddr, &opcode);
if (result)
return result;
if (is_swbp_insn(&opcode))
return 1;
return 0;
}
int __weak set_swbp(struct arch_uprobe *auprobe, struct mm_struct *mm, unsigned long vaddr)
{
int result;
result = is_swbp_at_addr(mm, vaddr);
if (result == 1)
return -EEXIST;
if (result)
return result;
return write_opcode(auprobe, mm, vaddr, UPROBE_SWBP_INSN);
}
int __weak
set_orig_insn(struct arch_uprobe *auprobe, struct mm_struct *mm, unsigned long vaddr, bool verify)
{
if (verify) {
int result;
result = is_swbp_at_addr(mm, vaddr);
if (!result)
return -EINVAL;
if (result != 1)
return result;
}
return write_opcode(auprobe, mm, vaddr, *(uprobe_opcode_t *)auprobe->insn);
}
static int match_uprobe(struct uprobe *l, struct uprobe *r)
{
if (l->inode < r->inode)
return -1;
if (l->inode > r->inode)
return 1;
if (l->offset < r->offset)
return -1;
if (l->offset > r->offset)
return 1;
return 0;
}
static struct uprobe *__find_uprobe(struct inode *inode, loff_t offset)
{
struct uprobe u = { .inode = inode, .offset = offset };
struct rb_node *n = uprobes_tree.rb_node;
struct uprobe *uprobe;
int match;
while (n) {
uprobe = rb_entry(n, struct uprobe, rb_node);
match = match_uprobe(&u, uprobe);
if (!match) {
atomic_inc(&uprobe->ref);
return uprobe;
}
if (match < 0)
n = n->rb_left;
else
n = n->rb_right;
}
return NULL;
}
static struct uprobe *find_uprobe(struct inode *inode, loff_t offset)
{
struct uprobe *uprobe;
unsigned long flags;
spin_lock_irqsave(&uprobes_treelock, flags);
uprobe = __find_uprobe(inode, offset);
spin_unlock_irqrestore(&uprobes_treelock, flags);
return uprobe;
}
static struct uprobe *__insert_uprobe(struct uprobe *uprobe)
{
struct rb_node **p = &uprobes_tree.rb_node;
struct rb_node *parent = NULL;
struct uprobe *u;
int match;
while (*p) {
parent = *p;
u = rb_entry(parent, struct uprobe, rb_node);
match = match_uprobe(uprobe, u);
if (!match) {
atomic_inc(&u->ref);
return u;
}
if (match < 0)
p = &parent->rb_left;
else
p = &parent->rb_right;
}
u = NULL;
rb_link_node(&uprobe->rb_node, parent, p);
rb_insert_color(&uprobe->rb_node, &uprobes_tree);
atomic_set(&uprobe->ref, 2);
return u;
}
static struct uprobe *insert_uprobe(struct uprobe *uprobe)
{
unsigned long flags;
struct uprobe *u;
spin_lock_irqsave(&uprobes_treelock, flags);
u = __insert_uprobe(uprobe);
spin_unlock_irqrestore(&uprobes_treelock, flags);
uprobe->flags |= UPROBE_SKIP_SSTEP;
return u;
}
static void put_uprobe(struct uprobe *uprobe)
{
if (atomic_dec_and_test(&uprobe->ref))
kfree(uprobe);
}
static struct uprobe *alloc_uprobe(struct inode *inode, loff_t offset)
{
struct uprobe *uprobe, *cur_uprobe;
uprobe = kzalloc(sizeof(struct uprobe), GFP_KERNEL);
if (!uprobe)
return NULL;
uprobe->inode = igrab(inode);
uprobe->offset = offset;
init_rwsem(&uprobe->consumer_rwsem);
INIT_LIST_HEAD(&uprobe->pending_list);
cur_uprobe = insert_uprobe(uprobe);
if (cur_uprobe) {
kfree(uprobe);
uprobe = cur_uprobe;
iput(inode);
} else {
atomic_inc(&uprobe_events);
}
return uprobe;
}
static void handler_chain(struct uprobe *uprobe, struct pt_regs *regs)
{
struct uprobe_consumer *uc;
if (!(uprobe->flags & UPROBE_RUN_HANDLER))
return;
down_read(&uprobe->consumer_rwsem);
for (uc = uprobe->consumers; uc; uc = uc->next) {
if (!uc->filter || uc->filter(uc, current))
uc->handler(uc, regs);
}
up_read(&uprobe->consumer_rwsem);
}
static struct uprobe_consumer *
consumer_add(struct uprobe *uprobe, struct uprobe_consumer *uc)
{
down_write(&uprobe->consumer_rwsem);
uc->next = uprobe->consumers;
uprobe->consumers = uc;
up_write(&uprobe->consumer_rwsem);
return uc->next;
}
static bool consumer_del(struct uprobe *uprobe, struct uprobe_consumer *uc)
{
struct uprobe_consumer **con;
bool ret = false;
down_write(&uprobe->consumer_rwsem);
for (con = &uprobe->consumers; *con; con = &(*con)->next) {
if (*con == uc) {
*con = uc->next;
ret = true;
break;
}
}
up_write(&uprobe->consumer_rwsem);
return ret;
}
static int
__copy_insn(struct address_space *mapping, struct vm_area_struct *vma, char *insn,
unsigned long nbytes, unsigned long offset)
{
struct file *filp = vma->vm_file;
struct page *page;
void *vaddr;
unsigned long off1;
unsigned long idx;
if (!filp)
return -EINVAL;
idx = (unsigned long)(offset >> PAGE_CACHE_SHIFT);
off1 = offset &= ~PAGE_MASK;
page = read_mapping_page(mapping, idx, filp);
if (IS_ERR(page))
return PTR_ERR(page);
vaddr = kmap_atomic(page);
memcpy(insn, vaddr + off1, nbytes);
kunmap_atomic(vaddr);
page_cache_release(page);
return 0;
}
static int
copy_insn(struct uprobe *uprobe, struct vm_area_struct *vma, unsigned long addr)
{
struct address_space *mapping;
unsigned long nbytes;
int bytes;
addr &= ~PAGE_MASK;
nbytes = PAGE_SIZE - addr;
mapping = uprobe->inode->i_mapping;
if (uprobe->offset + MAX_UINSN_BYTES > uprobe->inode->i_size)
bytes = uprobe->inode->i_size - uprobe->offset;
else
bytes = MAX_UINSN_BYTES;
if (nbytes < bytes) {
if (__copy_insn(mapping, vma, uprobe->arch.insn + nbytes,
bytes - nbytes, uprobe->offset + nbytes))
return -ENOMEM;
bytes = nbytes;
}
return __copy_insn(mapping, vma, uprobe->arch.insn, bytes, uprobe->offset);
}
static int
install_breakpoint(struct uprobe *uprobe, struct mm_struct *mm,
struct vm_area_struct *vma, loff_t vaddr)
{
unsigned long addr;
int ret;
if (!uprobe->consumers)
return -EEXIST;
addr = (unsigned long)vaddr;
if (!(uprobe->flags & UPROBE_COPY_INSN)) {
ret = copy_insn(uprobe, vma, addr);
if (ret)
return ret;
if (is_swbp_insn((uprobe_opcode_t *)uprobe->arch.insn))
return -EEXIST;
ret = arch_uprobe_analyze_insn(&uprobe->arch, mm);
if (ret)
return ret;
uprobe->flags |= UPROBE_COPY_INSN;
}
atomic_inc(&mm->uprobes_state.count);
ret = set_swbp(&uprobe->arch, mm, addr);
if (ret)
atomic_dec(&mm->uprobes_state.count);
return ret;
}
static void
remove_breakpoint(struct uprobe *uprobe, struct mm_struct *mm, loff_t vaddr)
{
if (!set_orig_insn(&uprobe->arch, mm, (unsigned long)vaddr, true))
atomic_dec(&mm->uprobes_state.count);
}
static void delete_uprobe(struct uprobe *uprobe)
{
unsigned long flags;
synchronize_srcu(&uprobes_srcu);
spin_lock_irqsave(&uprobes_treelock, flags);
rb_erase(&uprobe->rb_node, &uprobes_tree);
spin_unlock_irqrestore(&uprobes_treelock, flags);
iput(uprobe->inode);
put_uprobe(uprobe);
atomic_dec(&uprobe_events);
}
static struct vma_info *
__find_next_vma_info(struct address_space *mapping, struct list_head *head,
struct vma_info *vi, loff_t offset, bool is_register)
{
struct prio_tree_iter iter;
struct vm_area_struct *vma;
struct vma_info *tmpvi;
unsigned long pgoff;
int existing_vma;
loff_t vaddr;
pgoff = offset >> PAGE_SHIFT;
vma_prio_tree_foreach(vma, &iter, &mapping->i_mmap, pgoff, pgoff) {
if (!valid_vma(vma, is_register))
continue;
existing_vma = 0;
vaddr = vma_address(vma, offset);
list_for_each_entry(tmpvi, head, probe_list) {
if (tmpvi->mm == vma->vm_mm && tmpvi->vaddr == vaddr) {
existing_vma = 1;
break;
}
}
if (!existing_vma && atomic_inc_not_zero(&vma->vm_mm->mm_users)) {
vi->mm = vma->vm_mm;
vi->vaddr = vaddr;
list_add(&vi->probe_list, head);
return vi;
}
}
return NULL;
}
static struct vma_info *
find_next_vma_info(struct address_space *mapping, struct list_head *head,
loff_t offset, bool is_register)
{
struct vma_info *vi, *retvi;
vi = kzalloc(sizeof(struct vma_info), GFP_KERNEL);
if (!vi)
return ERR_PTR(-ENOMEM);
mutex_lock(&mapping->i_mmap_mutex);
retvi = __find_next_vma_info(mapping, head, vi, offset, is_register);
mutex_unlock(&mapping->i_mmap_mutex);
if (!retvi)
kfree(vi);
return retvi;
}
static int register_for_each_vma(struct uprobe *uprobe, bool is_register)
{
struct list_head try_list;
struct vm_area_struct *vma;
struct address_space *mapping;
struct vma_info *vi, *tmpvi;
struct mm_struct *mm;
loff_t vaddr;
int ret;
mapping = uprobe->inode->i_mapping;
INIT_LIST_HEAD(&try_list);
ret = 0;
for (;;) {
vi = find_next_vma_info(mapping, &try_list, uprobe->offset, is_register);
if (!vi)
break;
if (IS_ERR(vi)) {
ret = PTR_ERR(vi);
break;
}
mm = vi->mm;
down_read(&mm->mmap_sem);
vma = find_vma(mm, (unsigned long)vi->vaddr);
if (!vma || !valid_vma(vma, is_register)) {
list_del(&vi->probe_list);
kfree(vi);
up_read(&mm->mmap_sem);
mmput(mm);
continue;
}
vaddr = vma_address(vma, uprobe->offset);
if (vma->vm_file->f_mapping->host != uprobe->inode ||
vaddr != vi->vaddr) {
list_del(&vi->probe_list);
kfree(vi);
up_read(&mm->mmap_sem);
mmput(mm);
continue;
}
if (is_register)
ret = install_breakpoint(uprobe, mm, vma, vi->vaddr);
else
remove_breakpoint(uprobe, mm, vi->vaddr);
up_read(&mm->mmap_sem);
mmput(mm);
if (is_register) {
if (ret && ret == -EEXIST)
ret = 0;
if (ret)
break;
}
}
list_for_each_entry_safe(vi, tmpvi, &try_list, probe_list) {
list_del(&vi->probe_list);
kfree(vi);
}
return ret;
}
static int __uprobe_register(struct uprobe *uprobe)
{
return register_for_each_vma(uprobe, true);
}
static void __uprobe_unregister(struct uprobe *uprobe)
{
if (!register_for_each_vma(uprobe, false))
delete_uprobe(uprobe);
}
int uprobe_register(struct inode *inode, loff_t offset, struct uprobe_consumer *uc)
{
struct uprobe *uprobe;
int ret;
if (!inode || !uc || uc->next)
return -EINVAL;
if (offset > i_size_read(inode))
return -EINVAL;
ret = 0;
mutex_lock(uprobes_hash(inode));
uprobe = alloc_uprobe(inode, offset);
if (uprobe && !consumer_add(uprobe, uc)) {
ret = __uprobe_register(uprobe);
if (ret) {
uprobe->consumers = NULL;
__uprobe_unregister(uprobe);
} else {
uprobe->flags |= UPROBE_RUN_HANDLER;
}
}
mutex_unlock(uprobes_hash(inode));
put_uprobe(uprobe);
return ret;
}
void uprobe_unregister(struct inode *inode, loff_t offset, struct uprobe_consumer *uc)
{
struct uprobe *uprobe;
if (!inode || !uc)
return;
uprobe = find_uprobe(inode, offset);
if (!uprobe)
return;
mutex_lock(uprobes_hash(inode));
if (consumer_del(uprobe, uc)) {
if (!uprobe->consumers) {
__uprobe_unregister(uprobe);
uprobe->flags &= ~UPROBE_RUN_HANDLER;
}
}
mutex_unlock(uprobes_hash(inode));
if (uprobe)
put_uprobe(uprobe);
}
static struct rb_node *find_least_offset_node(struct inode *inode)
{
struct uprobe u = { .inode = inode, .offset = 0};
struct rb_node *n = uprobes_tree.rb_node;
struct rb_node *close_node = NULL;
struct uprobe *uprobe;
int match;
while (n) {
uprobe = rb_entry(n, struct uprobe, rb_node);
match = match_uprobe(&u, uprobe);
if (uprobe->inode == inode)
close_node = n;
if (!match)
return close_node;
if (match < 0)
n = n->rb_left;
else
n = n->rb_right;
}
return close_node;
}
static void build_probe_list(struct inode *inode, struct list_head *head)
{
struct uprobe *uprobe;
unsigned long flags;
struct rb_node *n;
spin_lock_irqsave(&uprobes_treelock, flags);
n = find_least_offset_node(inode);
for (; n; n = rb_next(n)) {
uprobe = rb_entry(n, struct uprobe, rb_node);
if (uprobe->inode != inode)
break;
list_add(&uprobe->pending_list, head);
atomic_inc(&uprobe->ref);
}
spin_unlock_irqrestore(&uprobes_treelock, flags);
}
int uprobe_mmap(struct vm_area_struct *vma)
{
struct list_head tmp_list;
struct uprobe *uprobe, *u;
struct inode *inode;
int ret, count;
if (!atomic_read(&uprobe_events) || !valid_vma(vma, true))
return 0;
inode = vma->vm_file->f_mapping->host;
if (!inode)
return 0;
INIT_LIST_HEAD(&tmp_list);
mutex_lock(uprobes_mmap_hash(inode));
build_probe_list(inode, &tmp_list);
ret = 0;
count = 0;
list_for_each_entry_safe(uprobe, u, &tmp_list, pending_list) {
loff_t vaddr;
list_del(&uprobe->pending_list);
if (!ret) {
vaddr = vma_address(vma, uprobe->offset);
if (vaddr < vma->vm_start || vaddr >= vma->vm_end) {
put_uprobe(uprobe);
continue;
}
ret = install_breakpoint(uprobe, vma->vm_mm, vma, vaddr);
if (ret == -EEXIST) {
ret = 0;
if (!is_swbp_at_addr(vma->vm_mm, vaddr))
continue;
atomic_inc(&vma->vm_mm->uprobes_state.count);
}
if (!ret)
count++;
}
put_uprobe(uprobe);
}
mutex_unlock(uprobes_mmap_hash(inode));
if (ret)
atomic_sub(count, &vma->vm_mm->uprobes_state.count);
return ret;
}
void uprobe_munmap(struct vm_area_struct *vma, unsigned long start, unsigned long end)
{
struct list_head tmp_list;
struct uprobe *uprobe, *u;
struct inode *inode;
if (!atomic_read(&uprobe_events) || !valid_vma(vma, false))
return;
if (!atomic_read(&vma->vm_mm->uprobes_state.count))
return;
inode = vma->vm_file->f_mapping->host;
if (!inode)
return;
INIT_LIST_HEAD(&tmp_list);
mutex_lock(uprobes_mmap_hash(inode));
build_probe_list(inode, &tmp_list);
list_for_each_entry_safe(uprobe, u, &tmp_list, pending_list) {
loff_t vaddr;
list_del(&uprobe->pending_list);
vaddr = vma_address(vma, uprobe->offset);
if (vaddr >= start && vaddr < end) {
if (is_swbp_at_addr(vma->vm_mm, vaddr) == 1)
atomic_dec(&vma->vm_mm->uprobes_state.count);
}
put_uprobe(uprobe);
}
mutex_unlock(uprobes_mmap_hash(inode));
}
static int xol_add_vma(struct xol_area *area)
{
struct mm_struct *mm;
int ret;
area->page = alloc_page(GFP_HIGHUSER);
if (!area->page)
return -ENOMEM;
ret = -EALREADY;
mm = current->mm;
down_write(&mm->mmap_sem);
if (mm->uprobes_state.xol_area)
goto fail;
ret = -ENOMEM;
area->vaddr = get_unmapped_area(NULL, TASK_SIZE - PAGE_SIZE, PAGE_SIZE, 0, 0);
if (area->vaddr & ~PAGE_MASK) {
ret = area->vaddr;
goto fail;
}
ret = install_special_mapping(mm, area->vaddr, PAGE_SIZE,
VM_EXEC|VM_MAYEXEC|VM_DONTCOPY|VM_IO, &area->page);
if (ret)
goto fail;
smp_wmb();
mm->uprobes_state.xol_area = area;
ret = 0;
fail:
up_write(&mm->mmap_sem);
if (ret)
__free_page(area->page);
return ret;
}
static struct xol_area *get_xol_area(struct mm_struct *mm)
{
struct xol_area *area;
area = mm->uprobes_state.xol_area;
smp_read_barrier_depends();
return area;
}
static struct xol_area *xol_alloc_area(void)
{
struct xol_area *area;
area = kzalloc(sizeof(*area), GFP_KERNEL);
if (unlikely(!area))
return NULL;
area->bitmap = kzalloc(BITS_TO_LONGS(UINSNS_PER_PAGE) * sizeof(long), GFP_KERNEL);
if (!area->bitmap)
goto fail;
init_waitqueue_head(&area->wq);
if (!xol_add_vma(area))
return area;
fail:
kfree(area->bitmap);
kfree(area);
return get_xol_area(current->mm);
}
void uprobe_clear_state(struct mm_struct *mm)
{
struct xol_area *area = mm->uprobes_state.xol_area;
if (!area)
return;
put_page(area->page);
kfree(area->bitmap);
kfree(area);
}
void uprobe_reset_state(struct mm_struct *mm)
{
mm->uprobes_state.xol_area = NULL;
atomic_set(&mm->uprobes_state.count, 0);
}
static unsigned long xol_take_insn_slot(struct xol_area *area)
{
unsigned long slot_addr;
int slot_nr;
do {
slot_nr = find_first_zero_bit(area->bitmap, UINSNS_PER_PAGE);
if (slot_nr < UINSNS_PER_PAGE) {
if (!test_and_set_bit(slot_nr, area->bitmap))
break;
slot_nr = UINSNS_PER_PAGE;
continue;
}
wait_event(area->wq, (atomic_read(&area->slot_count) < UINSNS_PER_PAGE));
} while (slot_nr >= UINSNS_PER_PAGE);
slot_addr = area->vaddr + (slot_nr * UPROBE_XOL_SLOT_BYTES);
atomic_inc(&area->slot_count);
return slot_addr;
}
static unsigned long xol_get_insn_slot(struct uprobe *uprobe, unsigned long slot_addr)
{
struct xol_area *area;
unsigned long offset;
void *vaddr;
area = get_xol_area(current->mm);
if (!area) {
area = xol_alloc_area();
if (!area)
return 0;
}
current->utask->xol_vaddr = xol_take_insn_slot(area);
if (unlikely(!current->utask->xol_vaddr))
return 0;
current->utask->vaddr = slot_addr;
offset = current->utask->xol_vaddr & ~PAGE_MASK;
vaddr = kmap_atomic(area->page);
memcpy(vaddr + offset, uprobe->arch.insn, MAX_UINSN_BYTES);
kunmap_atomic(vaddr);
return current->utask->xol_vaddr;
}
static void xol_free_insn_slot(struct task_struct *tsk)
{
struct xol_area *area;
unsigned long vma_end;
unsigned long slot_addr;
if (!tsk->mm || !tsk->mm->uprobes_state.xol_area || !tsk->utask)
return;
slot_addr = tsk->utask->xol_vaddr;
if (unlikely(!slot_addr || IS_ERR_VALUE(slot_addr)))
return;
area = tsk->mm->uprobes_state.xol_area;
vma_end = area->vaddr + PAGE_SIZE;
if (area->vaddr <= slot_addr && slot_addr < vma_end) {
unsigned long offset;
int slot_nr;
offset = slot_addr - area->vaddr;
slot_nr = offset / UPROBE_XOL_SLOT_BYTES;
if (slot_nr >= UINSNS_PER_PAGE)
return;
clear_bit(slot_nr, area->bitmap);
atomic_dec(&area->slot_count);
if (waitqueue_active(&area->wq))
wake_up(&area->wq);
tsk->utask->xol_vaddr = 0;
}
}
unsigned long __weak uprobe_get_swbp_addr(struct pt_regs *regs)
{
return instruction_pointer(regs) - UPROBE_SWBP_INSN_SIZE;
}
void uprobe_free_utask(struct task_struct *t)
{
struct uprobe_task *utask = t->utask;
if (t->uprobe_srcu_id != -1)
srcu_read_unlock_raw(&uprobes_srcu, t->uprobe_srcu_id);
if (!utask)
return;
if (utask->active_uprobe)
put_uprobe(utask->active_uprobe);
xol_free_insn_slot(t);
kfree(utask);
t->utask = NULL;
}
void uprobe_copy_process(struct task_struct *t)
{
t->utask = NULL;
t->uprobe_srcu_id = -1;
}
static struct uprobe_task *add_utask(void)
{
struct uprobe_task *utask;
utask = kzalloc(sizeof *utask, GFP_KERNEL);
if (unlikely(!utask))
return NULL;
utask->active_uprobe = NULL;
current->utask = utask;
return utask;
}
static int
pre_ssout(struct uprobe *uprobe, struct pt_regs *regs, unsigned long vaddr)
{
if (xol_get_insn_slot(uprobe, vaddr) && !arch_uprobe_pre_xol(&uprobe->arch, regs))
return 0;
return -EFAULT;
}
bool uprobe_deny_signal(void)
{
struct task_struct *t = current;
struct uprobe_task *utask = t->utask;
if (likely(!utask || !utask->active_uprobe))
return false;
WARN_ON_ONCE(utask->state != UTASK_SSTEP);
if (signal_pending(t)) {
spin_lock_irq(&t->sighand->siglock);
clear_tsk_thread_flag(t, TIF_SIGPENDING);
spin_unlock_irq(&t->sighand->siglock);
if (__fatal_signal_pending(t) || arch_uprobe_xol_was_trapped(t)) {
utask->state = UTASK_SSTEP_TRAPPED;
set_tsk_thread_flag(t, TIF_UPROBE);
set_tsk_thread_flag(t, TIF_NOTIFY_RESUME);
}
}
return true;
}
static bool can_skip_sstep(struct uprobe *uprobe, struct pt_regs *regs)
{
if (arch_uprobe_skip_sstep(&uprobe->arch, regs))
return true;
uprobe->flags &= ~UPROBE_SKIP_SSTEP;
return false;
}
static void handle_swbp(struct pt_regs *regs)
{
struct vm_area_struct *vma;
struct uprobe_task *utask;
struct uprobe *uprobe;
struct mm_struct *mm;
unsigned long bp_vaddr;
uprobe = NULL;
bp_vaddr = uprobe_get_swbp_addr(regs);
mm = current->mm;
down_read(&mm->mmap_sem);
vma = find_vma(mm, bp_vaddr);
if (vma && vma->vm_start <= bp_vaddr && valid_vma(vma, false)) {
struct inode *inode;
loff_t offset;
inode = vma->vm_file->f_mapping->host;
offset = bp_vaddr - vma->vm_start;
offset += (vma->vm_pgoff << PAGE_SHIFT);
uprobe = find_uprobe(inode, offset);
}
srcu_read_unlock_raw(&uprobes_srcu, current->uprobe_srcu_id);
current->uprobe_srcu_id = -1;
up_read(&mm->mmap_sem);
if (!uprobe) {
send_sig(SIGTRAP, current, 0);
return;
}
utask = current->utask;
if (!utask) {
utask = add_utask();
if (!utask)
goto cleanup_ret;
}
utask->active_uprobe = uprobe;
handler_chain(uprobe, regs);
if (uprobe->flags & UPROBE_SKIP_SSTEP && can_skip_sstep(uprobe, regs))
goto cleanup_ret;
utask->state = UTASK_SSTEP;
if (!pre_ssout(uprobe, regs, bp_vaddr)) {
user_enable_single_step(current);
return;
}
cleanup_ret:
if (utask) {
utask->active_uprobe = NULL;
utask->state = UTASK_RUNNING;
}
if (uprobe) {
if (!(uprobe->flags & UPROBE_SKIP_SSTEP))
instruction_pointer_set(regs, bp_vaddr);
put_uprobe(uprobe);
}
}
static void handle_singlestep(struct uprobe_task *utask, struct pt_regs *regs)
{
struct uprobe *uprobe;
uprobe = utask->active_uprobe;
if (utask->state == UTASK_SSTEP_ACK)
arch_uprobe_post_xol(&uprobe->arch, regs);
else if (utask->state == UTASK_SSTEP_TRAPPED)
arch_uprobe_abort_xol(&uprobe->arch, regs);
else
WARN_ON_ONCE(1);
put_uprobe(uprobe);
utask->active_uprobe = NULL;
utask->state = UTASK_RUNNING;
user_disable_single_step(current);
xol_free_insn_slot(current);
spin_lock_irq(&current->sighand->siglock);
recalc_sigpending();
spin_unlock_irq(&current->sighand->siglock);
}
void uprobe_notify_resume(struct pt_regs *regs)
{
struct uprobe_task *utask;
utask = current->utask;
if (!utask || utask->state == UTASK_BP_HIT)
handle_swbp(regs);
else
handle_singlestep(utask, regs);
}
int uprobe_pre_sstep_notifier(struct pt_regs *regs)
{
struct uprobe_task *utask;
if (!current->mm || !atomic_read(&current->mm->uprobes_state.count))
return 0;
utask = current->utask;
if (utask)
utask->state = UTASK_BP_HIT;
set_thread_flag(TIF_UPROBE);
current->uprobe_srcu_id = srcu_read_lock_raw(&uprobes_srcu);
return 1;
}
int uprobe_post_sstep_notifier(struct pt_regs *regs)
{
struct uprobe_task *utask = current->utask;
if (!current->mm || !utask || !utask->active_uprobe)
return 0;
utask->state = UTASK_SSTEP_ACK;
set_thread_flag(TIF_UPROBE);
return 1;
}
static int __init init_uprobes(void)
{
int i;
for (i = 0; i < UPROBES_HASH_SZ; i++) {
mutex_init(&uprobes_mutex[i]);
mutex_init(&uprobes_mmap_mutex[i]);
}
init_srcu_struct(&uprobes_srcu);
return register_die_notifier(&uprobe_exception_nb);
}
static void __exit exit_uprobes(void)
{
}
