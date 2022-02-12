static bool valid_vma(struct vm_area_struct *vma, bool is_register)
{
if (!vma->vm_file)
return false;
if (!is_register)
return true;
if ((vma->vm_flags & (VM_HUGETLB|VM_READ|VM_WRITE|VM_EXEC|VM_SHARED))
== (VM_READ|VM_EXEC))
return true;
return false;
}
static unsigned long offset_to_vaddr(struct vm_area_struct *vma, loff_t offset)
{
return vma->vm_start + offset - ((loff_t)vma->vm_pgoff << PAGE_SHIFT);
}
static loff_t vaddr_to_offset(struct vm_area_struct *vma, unsigned long vaddr)
{
return ((loff_t)vma->vm_pgoff << PAGE_SHIFT) + (vaddr - vma->vm_start);
}
static int __replace_page(struct vm_area_struct *vma, unsigned long addr,
struct page *page, struct page *kpage)
{
struct mm_struct *mm = vma->vm_mm;
spinlock_t *ptl;
pte_t *ptep;
int err;
lock_page(page);
err = -EAGAIN;
ptep = page_check_address(page, mm, addr, &ptl, 0);
if (!ptep)
goto unlock;
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
pte_unmap_unlock(ptep, ptl);
if (vma->vm_flags & VM_LOCKED)
munlock_vma_page(page);
put_page(page);
err = 0;
unlock:
unlock_page(page);
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
void *vaddr_old, *vaddr_new;
struct vm_area_struct *vma;
int ret;
retry:
ret = get_user_pages(NULL, mm, vaddr, 1, 0, 0, &old_page, &vma);
if (ret <= 0)
return ret;
ret = -ENOMEM;
new_page = alloc_page_vma(GFP_HIGHUSER_MOVABLE, vma, vaddr);
if (!new_page)
goto put_old;
__SetPageUptodate(new_page);
vaddr_old = kmap_atomic(old_page);
vaddr_new = kmap_atomic(new_page);
memcpy(vaddr_new, vaddr_old, PAGE_SIZE);
memcpy(vaddr_new + (vaddr & ~PAGE_MASK), &opcode, UPROBE_SWBP_INSN_SIZE);
kunmap_atomic(vaddr_new);
kunmap_atomic(vaddr_old);
ret = anon_vma_prepare(vma);
if (ret)
goto put_new;
ret = __replace_page(vma, vaddr, old_page, new_page);
put_new:
page_cache_release(new_page);
put_old:
put_page(old_page);
if (unlikely(ret == -EAGAIN))
goto retry;
return ret;
}
static int read_opcode(struct mm_struct *mm, unsigned long vaddr, uprobe_opcode_t *opcode)
{
struct page *page;
void *vaddr_new;
int ret;
ret = get_user_pages(NULL, mm, vaddr, 1, 0, 1, &page, NULL);
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
if (current->mm == mm) {
pagefault_disable();
result = __copy_from_user_inatomic(&opcode, (void __user*)vaddr,
sizeof(opcode));
pagefault_enable();
if (likely(result == 0))
goto out;
}
result = read_opcode(mm, vaddr, &opcode);
if (result)
return result;
out:
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
__copy_insn(struct address_space *mapping, struct file *filp, char *insn,
unsigned long nbytes, loff_t offset)
{
struct page *page;
void *vaddr;
unsigned long off;
pgoff_t idx;
if (!filp)
return -EINVAL;
if (!mapping->a_ops->readpage)
return -EIO;
idx = offset >> PAGE_CACHE_SHIFT;
off = offset & ~PAGE_MASK;
page = read_mapping_page(mapping, idx, filp);
if (IS_ERR(page))
return PTR_ERR(page);
vaddr = kmap_atomic(page);
memcpy(insn, vaddr + off, nbytes);
kunmap_atomic(vaddr);
page_cache_release(page);
return 0;
}
static int copy_insn(struct uprobe *uprobe, struct file *filp)
{
struct address_space *mapping;
unsigned long nbytes;
int bytes;
nbytes = PAGE_SIZE - (uprobe->offset & ~PAGE_MASK);
mapping = uprobe->inode->i_mapping;
if (uprobe->offset + MAX_UINSN_BYTES > uprobe->inode->i_size)
bytes = uprobe->inode->i_size - uprobe->offset;
else
bytes = MAX_UINSN_BYTES;
if (nbytes < bytes) {
int err = __copy_insn(mapping, filp, uprobe->arch.insn + nbytes,
bytes - nbytes, uprobe->offset + nbytes);
if (err)
return err;
bytes = nbytes;
}
return __copy_insn(mapping, filp, uprobe->arch.insn, bytes, uprobe->offset);
}
static int
install_breakpoint(struct uprobe *uprobe, struct mm_struct *mm,
struct vm_area_struct *vma, unsigned long vaddr)
{
int ret;
if (!uprobe->consumers)
return -EEXIST;
if (!(uprobe->flags & UPROBE_COPY_INSN)) {
ret = copy_insn(uprobe, vma->vm_file);
if (ret)
return ret;
if (is_swbp_insn((uprobe_opcode_t *)uprobe->arch.insn))
return -ENOTSUPP;
ret = arch_uprobe_analyze_insn(&uprobe->arch, mm, vaddr);
if (ret)
return ret;
BUG_ON((uprobe->offset & ~PAGE_MASK) +
UPROBE_SWBP_INSN_SIZE > PAGE_SIZE);
uprobe->flags |= UPROBE_COPY_INSN;
}
atomic_inc(&mm->uprobes_state.count);
ret = set_swbp(&uprobe->arch, mm, vaddr);
if (ret)
atomic_dec(&mm->uprobes_state.count);
return ret;
}
static void
remove_breakpoint(struct uprobe *uprobe, struct mm_struct *mm, unsigned long vaddr)
{
if (!set_orig_insn(&uprobe->arch, mm, vaddr, true))
atomic_dec(&mm->uprobes_state.count);
}
static void delete_uprobe(struct uprobe *uprobe)
{
unsigned long flags;
spin_lock_irqsave(&uprobes_treelock, flags);
rb_erase(&uprobe->rb_node, &uprobes_tree);
spin_unlock_irqrestore(&uprobes_treelock, flags);
iput(uprobe->inode);
put_uprobe(uprobe);
atomic_dec(&uprobe_events);
}
static inline struct map_info *free_map_info(struct map_info *info)
{
struct map_info *next = info->next;
kfree(info);
return next;
}
static struct map_info *
build_map_info(struct address_space *mapping, loff_t offset, bool is_register)
{
unsigned long pgoff = offset >> PAGE_SHIFT;
struct prio_tree_iter iter;
struct vm_area_struct *vma;
struct map_info *curr = NULL;
struct map_info *prev = NULL;
struct map_info *info;
int more = 0;
again:
mutex_lock(&mapping->i_mmap_mutex);
vma_prio_tree_foreach(vma, &iter, &mapping->i_mmap, pgoff, pgoff) {
if (!valid_vma(vma, is_register))
continue;
if (!prev && !more) {
prev = kmalloc(sizeof(struct map_info),
GFP_NOWAIT | __GFP_NOMEMALLOC | __GFP_NOWARN);
if (prev)
prev->next = NULL;
}
if (!prev) {
more++;
continue;
}
if (!atomic_inc_not_zero(&vma->vm_mm->mm_users))
continue;
info = prev;
prev = prev->next;
info->next = curr;
curr = info;
info->mm = vma->vm_mm;
info->vaddr = offset_to_vaddr(vma, offset);
}
mutex_unlock(&mapping->i_mmap_mutex);
if (!more)
goto out;
prev = curr;
while (curr) {
mmput(curr->mm);
curr = curr->next;
}
do {
info = kmalloc(sizeof(struct map_info), GFP_KERNEL);
if (!info) {
curr = ERR_PTR(-ENOMEM);
goto out;
}
info->next = prev;
prev = info;
} while (--more);
goto again;
out:
while (prev)
prev = free_map_info(prev);
return curr;
}
static int register_for_each_vma(struct uprobe *uprobe, bool is_register)
{
struct map_info *info;
int err = 0;
info = build_map_info(uprobe->inode->i_mapping,
uprobe->offset, is_register);
if (IS_ERR(info))
return PTR_ERR(info);
while (info) {
struct mm_struct *mm = info->mm;
struct vm_area_struct *vma;
if (err)
goto free;
down_write(&mm->mmap_sem);
vma = find_vma(mm, info->vaddr);
if (!vma || !valid_vma(vma, is_register) ||
vma->vm_file->f_mapping->host != uprobe->inode)
goto unlock;
if (vma->vm_start > info->vaddr ||
vaddr_to_offset(vma, info->vaddr) != uprobe->offset)
goto unlock;
if (is_register) {
err = install_breakpoint(uprobe, mm, vma, info->vaddr);
if (err == -EEXIST)
err = 0;
} else {
remove_breakpoint(uprobe, mm, info->vaddr);
}
unlock:
up_write(&mm->mmap_sem);
free:
mmput(mm);
info = free_map_info(info);
}
return err;
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
static struct rb_node *
find_node_in_range(struct inode *inode, loff_t min, loff_t max)
{
struct rb_node *n = uprobes_tree.rb_node;
while (n) {
struct uprobe *u = rb_entry(n, struct uprobe, rb_node);
if (inode < u->inode) {
n = n->rb_left;
} else if (inode > u->inode) {
n = n->rb_right;
} else {
if (max < u->offset)
n = n->rb_left;
else if (min > u->offset)
n = n->rb_right;
else
break;
}
}
return n;
}
static void build_probe_list(struct inode *inode,
struct vm_area_struct *vma,
unsigned long start, unsigned long end,
struct list_head *head)
{
loff_t min, max;
unsigned long flags;
struct rb_node *n, *t;
struct uprobe *u;
INIT_LIST_HEAD(head);
min = vaddr_to_offset(vma, start);
max = min + (end - start) - 1;
spin_lock_irqsave(&uprobes_treelock, flags);
n = find_node_in_range(inode, min, max);
if (n) {
for (t = n; t; t = rb_prev(t)) {
u = rb_entry(t, struct uprobe, rb_node);
if (u->inode != inode || u->offset < min)
break;
list_add(&u->pending_list, head);
atomic_inc(&u->ref);
}
for (t = n; (t = rb_next(t)); ) {
u = rb_entry(t, struct uprobe, rb_node);
if (u->inode != inode || u->offset > max)
break;
list_add(&u->pending_list, head);
atomic_inc(&u->ref);
}
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
mutex_lock(uprobes_mmap_hash(inode));
build_probe_list(inode, vma, vma->vm_start, vma->vm_end, &tmp_list);
ret = 0;
count = 0;
list_for_each_entry_safe(uprobe, u, &tmp_list, pending_list) {
if (!ret) {
unsigned long vaddr = offset_to_vaddr(vma, uprobe->offset);
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
if (!atomic_read(&vma->vm_mm->mm_users))
return;
if (!atomic_read(&vma->vm_mm->uprobes_state.count))
return;
inode = vma->vm_file->f_mapping->host;
if (!inode)
return;
mutex_lock(uprobes_mmap_hash(inode));
build_probe_list(inode, vma, start, end, &tmp_list);
list_for_each_entry_safe(uprobe, u, &tmp_list, pending_list) {
unsigned long vaddr = offset_to_vaddr(vma, uprobe->offset);
if (is_swbp_at_addr(vma->vm_mm, vaddr) == 1)
atomic_dec(&vma->vm_mm->uprobes_state.count);
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
}
static struct uprobe_task *add_utask(void)
{
struct uprobe_task *utask;
utask = kzalloc(sizeof *utask, GFP_KERNEL);
if (unlikely(!utask))
return NULL;
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
static struct uprobe *find_active_uprobe(unsigned long bp_vaddr, int *is_swbp)
{
struct mm_struct *mm = current->mm;
struct uprobe *uprobe = NULL;
struct vm_area_struct *vma;
down_read(&mm->mmap_sem);
vma = find_vma(mm, bp_vaddr);
if (vma && vma->vm_start <= bp_vaddr) {
if (valid_vma(vma, false)) {
struct inode *inode = vma->vm_file->f_mapping->host;
loff_t offset = vaddr_to_offset(vma, bp_vaddr);
uprobe = find_uprobe(inode, offset);
}
if (!uprobe)
*is_swbp = is_swbp_at_addr(mm, bp_vaddr);
} else {
*is_swbp = -EFAULT;
}
up_read(&mm->mmap_sem);
return uprobe;
}
static void handle_swbp(struct pt_regs *regs)
{
struct uprobe_task *utask;
struct uprobe *uprobe;
unsigned long bp_vaddr;
int uninitialized_var(is_swbp);
bp_vaddr = uprobe_get_swbp_addr(regs);
uprobe = find_active_uprobe(bp_vaddr, &is_swbp);
if (!uprobe) {
if (is_swbp > 0) {
send_sig(SIGTRAP, current, 0);
} else {
instruction_pointer_set(regs, bp_vaddr);
}
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
return register_die_notifier(&uprobe_exception_nb);
}
static void __exit exit_uprobes(void)
{
}
