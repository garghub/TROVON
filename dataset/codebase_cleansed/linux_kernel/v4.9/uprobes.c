static bool valid_vma(struct vm_area_struct *vma, bool is_register)
{
vm_flags_t flags = VM_HUGETLB | VM_MAYEXEC | VM_MAYSHARE;
if (is_register)
flags |= VM_WRITE;
return vma->vm_file && (vma->vm_flags & flags) == VM_MAYEXEC;
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
struct page *old_page, struct page *new_page)
{
struct mm_struct *mm = vma->vm_mm;
spinlock_t *ptl;
pte_t *ptep;
int err;
const unsigned long mmun_start = addr;
const unsigned long mmun_end = addr + PAGE_SIZE;
struct mem_cgroup *memcg;
err = mem_cgroup_try_charge(new_page, vma->vm_mm, GFP_KERNEL, &memcg,
false);
if (err)
return err;
lock_page(old_page);
mmu_notifier_invalidate_range_start(mm, mmun_start, mmun_end);
err = -EAGAIN;
ptep = page_check_address(old_page, mm, addr, &ptl, 0);
if (!ptep) {
mem_cgroup_cancel_charge(new_page, memcg, false);
goto unlock;
}
get_page(new_page);
page_add_new_anon_rmap(new_page, vma, addr, false);
mem_cgroup_commit_charge(new_page, memcg, false, false);
lru_cache_add_active_or_unevictable(new_page, vma);
if (!PageAnon(old_page)) {
dec_mm_counter(mm, mm_counter_file(old_page));
inc_mm_counter(mm, MM_ANONPAGES);
}
flush_cache_page(vma, addr, pte_pfn(*ptep));
ptep_clear_flush_notify(vma, addr, ptep);
set_pte_at_notify(mm, addr, ptep, mk_pte(new_page, vma->vm_page_prot));
page_remove_rmap(old_page, false);
if (!page_mapped(old_page))
try_to_free_swap(old_page);
pte_unmap_unlock(ptep, ptl);
if (vma->vm_flags & VM_LOCKED)
munlock_vma_page(old_page);
put_page(old_page);
err = 0;
unlock:
mmu_notifier_invalidate_range_end(mm, mmun_start, mmun_end);
unlock_page(old_page);
return err;
}
bool __weak is_swbp_insn(uprobe_opcode_t *insn)
{
return *insn == UPROBE_SWBP_INSN;
}
bool __weak is_trap_insn(uprobe_opcode_t *insn)
{
return is_swbp_insn(insn);
}
static void copy_from_page(struct page *page, unsigned long vaddr, void *dst, int len)
{
void *kaddr = kmap_atomic(page);
memcpy(dst, kaddr + (vaddr & ~PAGE_MASK), len);
kunmap_atomic(kaddr);
}
static void copy_to_page(struct page *page, unsigned long vaddr, const void *src, int len)
{
void *kaddr = kmap_atomic(page);
memcpy(kaddr + (vaddr & ~PAGE_MASK), src, len);
kunmap_atomic(kaddr);
}
static int verify_opcode(struct page *page, unsigned long vaddr, uprobe_opcode_t *new_opcode)
{
uprobe_opcode_t old_opcode;
bool is_swbp;
copy_from_page(page, vaddr, &old_opcode, UPROBE_SWBP_INSN_SIZE);
is_swbp = is_swbp_insn(&old_opcode);
if (is_swbp_insn(new_opcode)) {
if (is_swbp)
return 0;
} else {
if (!is_swbp)
return 0;
}
return 1;
}
int uprobe_write_opcode(struct mm_struct *mm, unsigned long vaddr,
uprobe_opcode_t opcode)
{
struct page *old_page, *new_page;
struct vm_area_struct *vma;
int ret;
retry:
ret = get_user_pages_remote(NULL, mm, vaddr, 1, FOLL_FORCE, &old_page,
&vma);
if (ret <= 0)
return ret;
ret = verify_opcode(old_page, vaddr, &opcode);
if (ret <= 0)
goto put_old;
ret = anon_vma_prepare(vma);
if (ret)
goto put_old;
ret = -ENOMEM;
new_page = alloc_page_vma(GFP_HIGHUSER_MOVABLE, vma, vaddr);
if (!new_page)
goto put_old;
__SetPageUptodate(new_page);
copy_highpage(new_page, old_page);
copy_to_page(new_page, vaddr, &opcode, UPROBE_SWBP_INSN_SIZE);
ret = __replace_page(vma, vaddr, old_page, new_page);
put_page(new_page);
put_old:
put_page(old_page);
if (unlikely(ret == -EAGAIN))
goto retry;
return ret;
}
int __weak set_swbp(struct arch_uprobe *auprobe, struct mm_struct *mm, unsigned long vaddr)
{
return uprobe_write_opcode(mm, vaddr, UPROBE_SWBP_INSN);
}
int __weak
set_orig_insn(struct arch_uprobe *auprobe, struct mm_struct *mm, unsigned long vaddr)
{
return uprobe_write_opcode(mm, vaddr, *(uprobe_opcode_t *)&auprobe->insn);
}
static struct uprobe *get_uprobe(struct uprobe *uprobe)
{
atomic_inc(&uprobe->ref);
return uprobe;
}
static void put_uprobe(struct uprobe *uprobe)
{
if (atomic_dec_and_test(&uprobe->ref))
kfree(uprobe);
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
if (!match)
return get_uprobe(uprobe);
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
spin_lock(&uprobes_treelock);
uprobe = __find_uprobe(inode, offset);
spin_unlock(&uprobes_treelock);
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
if (!match)
return get_uprobe(u);
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
struct uprobe *u;
spin_lock(&uprobes_treelock);
u = __insert_uprobe(uprobe);
spin_unlock(&uprobes_treelock);
return u;
}
static struct uprobe *alloc_uprobe(struct inode *inode, loff_t offset)
{
struct uprobe *uprobe, *cur_uprobe;
uprobe = kzalloc(sizeof(struct uprobe), GFP_KERNEL);
if (!uprobe)
return NULL;
uprobe->inode = igrab(inode);
uprobe->offset = offset;
init_rwsem(&uprobe->register_rwsem);
init_rwsem(&uprobe->consumer_rwsem);
cur_uprobe = insert_uprobe(uprobe);
if (cur_uprobe) {
kfree(uprobe);
uprobe = cur_uprobe;
iput(inode);
}
return uprobe;
}
static void consumer_add(struct uprobe *uprobe, struct uprobe_consumer *uc)
{
down_write(&uprobe->consumer_rwsem);
uc->next = uprobe->consumers;
uprobe->consumers = uc;
up_write(&uprobe->consumer_rwsem);
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
static int __copy_insn(struct address_space *mapping, struct file *filp,
void *insn, int nbytes, loff_t offset)
{
struct page *page;
if (mapping->a_ops->readpage)
page = read_mapping_page(mapping, offset >> PAGE_SHIFT, filp);
else
page = shmem_read_mapping_page(mapping, offset >> PAGE_SHIFT);
if (IS_ERR(page))
return PTR_ERR(page);
copy_from_page(page, offset, insn, nbytes);
put_page(page);
return 0;
}
static int copy_insn(struct uprobe *uprobe, struct file *filp)
{
struct address_space *mapping = uprobe->inode->i_mapping;
loff_t offs = uprobe->offset;
void *insn = &uprobe->arch.insn;
int size = sizeof(uprobe->arch.insn);
int len, err = -EIO;
do {
if (offs >= i_size_read(uprobe->inode))
break;
len = min_t(int, size, PAGE_SIZE - (offs & ~PAGE_MASK));
err = __copy_insn(mapping, filp, insn, len, offs);
if (err)
break;
insn += len;
offs += len;
size -= len;
} while (size);
return err;
}
static int prepare_uprobe(struct uprobe *uprobe, struct file *file,
struct mm_struct *mm, unsigned long vaddr)
{
int ret = 0;
if (test_bit(UPROBE_COPY_INSN, &uprobe->flags))
return ret;
down_write(&uprobe->consumer_rwsem);
if (test_bit(UPROBE_COPY_INSN, &uprobe->flags))
goto out;
ret = copy_insn(uprobe, file);
if (ret)
goto out;
ret = -ENOTSUPP;
if (is_trap_insn((uprobe_opcode_t *)&uprobe->arch.insn))
goto out;
ret = arch_uprobe_analyze_insn(&uprobe->arch, mm, vaddr);
if (ret)
goto out;
BUG_ON((uprobe->offset & ~PAGE_MASK) +
UPROBE_SWBP_INSN_SIZE > PAGE_SIZE);
smp_wmb();
set_bit(UPROBE_COPY_INSN, &uprobe->flags);
out:
up_write(&uprobe->consumer_rwsem);
return ret;
}
static inline bool consumer_filter(struct uprobe_consumer *uc,
enum uprobe_filter_ctx ctx, struct mm_struct *mm)
{
return !uc->filter || uc->filter(uc, ctx, mm);
}
static bool filter_chain(struct uprobe *uprobe,
enum uprobe_filter_ctx ctx, struct mm_struct *mm)
{
struct uprobe_consumer *uc;
bool ret = false;
down_read(&uprobe->consumer_rwsem);
for (uc = uprobe->consumers; uc; uc = uc->next) {
ret = consumer_filter(uc, ctx, mm);
if (ret)
break;
}
up_read(&uprobe->consumer_rwsem);
return ret;
}
static int
install_breakpoint(struct uprobe *uprobe, struct mm_struct *mm,
struct vm_area_struct *vma, unsigned long vaddr)
{
bool first_uprobe;
int ret;
ret = prepare_uprobe(uprobe, vma->vm_file, mm, vaddr);
if (ret)
return ret;
first_uprobe = !test_bit(MMF_HAS_UPROBES, &mm->flags);
if (first_uprobe)
set_bit(MMF_HAS_UPROBES, &mm->flags);
ret = set_swbp(&uprobe->arch, mm, vaddr);
if (!ret)
clear_bit(MMF_RECALC_UPROBES, &mm->flags);
else if (first_uprobe)
clear_bit(MMF_HAS_UPROBES, &mm->flags);
return ret;
}
static int
remove_breakpoint(struct uprobe *uprobe, struct mm_struct *mm, unsigned long vaddr)
{
set_bit(MMF_RECALC_UPROBES, &mm->flags);
return set_orig_insn(&uprobe->arch, mm, vaddr);
}
static inline bool uprobe_is_active(struct uprobe *uprobe)
{
return !RB_EMPTY_NODE(&uprobe->rb_node);
}
static void delete_uprobe(struct uprobe *uprobe)
{
if (WARN_ON(!uprobe_is_active(uprobe)))
return;
spin_lock(&uprobes_treelock);
rb_erase(&uprobe->rb_node, &uprobes_tree);
spin_unlock(&uprobes_treelock);
RB_CLEAR_NODE(&uprobe->rb_node);
iput(uprobe->inode);
put_uprobe(uprobe);
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
struct vm_area_struct *vma;
struct map_info *curr = NULL;
struct map_info *prev = NULL;
struct map_info *info;
int more = 0;
again:
i_mmap_lock_read(mapping);
vma_interval_tree_foreach(vma, &mapping->i_mmap, pgoff, pgoff) {
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
i_mmap_unlock_read(mapping);
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
static int
register_for_each_vma(struct uprobe *uprobe, struct uprobe_consumer *new)
{
bool is_register = !!new;
struct map_info *info;
int err = 0;
percpu_down_write(&dup_mmap_sem);
info = build_map_info(uprobe->inode->i_mapping,
uprobe->offset, is_register);
if (IS_ERR(info)) {
err = PTR_ERR(info);
goto out;
}
while (info) {
struct mm_struct *mm = info->mm;
struct vm_area_struct *vma;
if (err && is_register)
goto free;
down_write(&mm->mmap_sem);
vma = find_vma(mm, info->vaddr);
if (!vma || !valid_vma(vma, is_register) ||
file_inode(vma->vm_file) != uprobe->inode)
goto unlock;
if (vma->vm_start > info->vaddr ||
vaddr_to_offset(vma, info->vaddr) != uprobe->offset)
goto unlock;
if (is_register) {
if (consumer_filter(new,
UPROBE_FILTER_REGISTER, mm))
err = install_breakpoint(uprobe, mm, vma, info->vaddr);
} else if (test_bit(MMF_HAS_UPROBES, &mm->flags)) {
if (!filter_chain(uprobe,
UPROBE_FILTER_UNREGISTER, mm))
err |= remove_breakpoint(uprobe, mm, info->vaddr);
}
unlock:
up_write(&mm->mmap_sem);
free:
mmput(mm);
info = free_map_info(info);
}
out:
percpu_up_write(&dup_mmap_sem);
return err;
}
static int __uprobe_register(struct uprobe *uprobe, struct uprobe_consumer *uc)
{
consumer_add(uprobe, uc);
return register_for_each_vma(uprobe, uc);
}
static void __uprobe_unregister(struct uprobe *uprobe, struct uprobe_consumer *uc)
{
int err;
if (WARN_ON(!consumer_del(uprobe, uc)))
return;
err = register_for_each_vma(uprobe, NULL);
if (!uprobe->consumers && !err)
delete_uprobe(uprobe);
}
int uprobe_register(struct inode *inode, loff_t offset, struct uprobe_consumer *uc)
{
struct uprobe *uprobe;
int ret;
if (!uc->handler && !uc->ret_handler)
return -EINVAL;
if (!inode->i_mapping->a_ops->readpage && !shmem_mapping(inode->i_mapping))
return -EIO;
if (offset > i_size_read(inode))
return -EINVAL;
retry:
uprobe = alloc_uprobe(inode, offset);
if (!uprobe)
return -ENOMEM;
down_write(&uprobe->register_rwsem);
ret = -EAGAIN;
if (likely(uprobe_is_active(uprobe))) {
ret = __uprobe_register(uprobe, uc);
if (ret)
__uprobe_unregister(uprobe, uc);
}
up_write(&uprobe->register_rwsem);
put_uprobe(uprobe);
if (unlikely(ret == -EAGAIN))
goto retry;
return ret;
}
int uprobe_apply(struct inode *inode, loff_t offset,
struct uprobe_consumer *uc, bool add)
{
struct uprobe *uprobe;
struct uprobe_consumer *con;
int ret = -ENOENT;
uprobe = find_uprobe(inode, offset);
if (WARN_ON(!uprobe))
return ret;
down_write(&uprobe->register_rwsem);
for (con = uprobe->consumers; con && con != uc ; con = con->next)
;
if (con)
ret = register_for_each_vma(uprobe, add ? uc : NULL);
up_write(&uprobe->register_rwsem);
put_uprobe(uprobe);
return ret;
}
void uprobe_unregister(struct inode *inode, loff_t offset, struct uprobe_consumer *uc)
{
struct uprobe *uprobe;
uprobe = find_uprobe(inode, offset);
if (WARN_ON(!uprobe))
return;
down_write(&uprobe->register_rwsem);
__uprobe_unregister(uprobe, uc);
up_write(&uprobe->register_rwsem);
put_uprobe(uprobe);
}
static int unapply_uprobe(struct uprobe *uprobe, struct mm_struct *mm)
{
struct vm_area_struct *vma;
int err = 0;
down_read(&mm->mmap_sem);
for (vma = mm->mmap; vma; vma = vma->vm_next) {
unsigned long vaddr;
loff_t offset;
if (!valid_vma(vma, false) ||
file_inode(vma->vm_file) != uprobe->inode)
continue;
offset = (loff_t)vma->vm_pgoff << PAGE_SHIFT;
if (uprobe->offset < offset ||
uprobe->offset >= offset + vma->vm_end - vma->vm_start)
continue;
vaddr = offset_to_vaddr(vma, uprobe->offset);
err |= remove_breakpoint(uprobe, mm, vaddr);
}
up_read(&mm->mmap_sem);
return err;
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
struct rb_node *n, *t;
struct uprobe *u;
INIT_LIST_HEAD(head);
min = vaddr_to_offset(vma, start);
max = min + (end - start) - 1;
spin_lock(&uprobes_treelock);
n = find_node_in_range(inode, min, max);
if (n) {
for (t = n; t; t = rb_prev(t)) {
u = rb_entry(t, struct uprobe, rb_node);
if (u->inode != inode || u->offset < min)
break;
list_add(&u->pending_list, head);
get_uprobe(u);
}
for (t = n; (t = rb_next(t)); ) {
u = rb_entry(t, struct uprobe, rb_node);
if (u->inode != inode || u->offset > max)
break;
list_add(&u->pending_list, head);
get_uprobe(u);
}
}
spin_unlock(&uprobes_treelock);
}
int uprobe_mmap(struct vm_area_struct *vma)
{
struct list_head tmp_list;
struct uprobe *uprobe, *u;
struct inode *inode;
if (no_uprobe_events() || !valid_vma(vma, true))
return 0;
inode = file_inode(vma->vm_file);
if (!inode)
return 0;
mutex_lock(uprobes_mmap_hash(inode));
build_probe_list(inode, vma, vma->vm_start, vma->vm_end, &tmp_list);
list_for_each_entry_safe(uprobe, u, &tmp_list, pending_list) {
if (!fatal_signal_pending(current) &&
filter_chain(uprobe, UPROBE_FILTER_MMAP, vma->vm_mm)) {
unsigned long vaddr = offset_to_vaddr(vma, uprobe->offset);
install_breakpoint(uprobe, vma->vm_mm, vma, vaddr);
}
put_uprobe(uprobe);
}
mutex_unlock(uprobes_mmap_hash(inode));
return 0;
}
static bool
vma_has_uprobes(struct vm_area_struct *vma, unsigned long start, unsigned long end)
{
loff_t min, max;
struct inode *inode;
struct rb_node *n;
inode = file_inode(vma->vm_file);
min = vaddr_to_offset(vma, start);
max = min + (end - start) - 1;
spin_lock(&uprobes_treelock);
n = find_node_in_range(inode, min, max);
spin_unlock(&uprobes_treelock);
return !!n;
}
void uprobe_munmap(struct vm_area_struct *vma, unsigned long start, unsigned long end)
{
if (no_uprobe_events() || !valid_vma(vma, false))
return;
if (!atomic_read(&vma->vm_mm->mm_users))
return;
if (!test_bit(MMF_HAS_UPROBES, &vma->vm_mm->flags) ||
test_bit(MMF_RECALC_UPROBES, &vma->vm_mm->flags))
return;
if (vma_has_uprobes(vma, start, end))
set_bit(MMF_RECALC_UPROBES, &vma->vm_mm->flags);
}
static int xol_add_vma(struct mm_struct *mm, struct xol_area *area)
{
struct vm_area_struct *vma;
int ret;
if (down_write_killable(&mm->mmap_sem))
return -EINTR;
if (mm->uprobes_state.xol_area) {
ret = -EALREADY;
goto fail;
}
if (!area->vaddr) {
area->vaddr = get_unmapped_area(NULL, TASK_SIZE - PAGE_SIZE,
PAGE_SIZE, 0, 0);
if (area->vaddr & ~PAGE_MASK) {
ret = area->vaddr;
goto fail;
}
}
vma = _install_special_mapping(mm, area->vaddr, PAGE_SIZE,
VM_EXEC|VM_MAYEXEC|VM_DONTCOPY|VM_IO,
&area->xol_mapping);
if (IS_ERR(vma)) {
ret = PTR_ERR(vma);
goto fail;
}
ret = 0;
smp_wmb();
mm->uprobes_state.xol_area = area;
fail:
up_write(&mm->mmap_sem);
return ret;
}
static struct xol_area *__create_xol_area(unsigned long vaddr)
{
struct mm_struct *mm = current->mm;
uprobe_opcode_t insn = UPROBE_SWBP_INSN;
struct xol_area *area;
area = kmalloc(sizeof(*area), GFP_KERNEL);
if (unlikely(!area))
goto out;
area->bitmap = kzalloc(BITS_TO_LONGS(UINSNS_PER_PAGE) * sizeof(long), GFP_KERNEL);
if (!area->bitmap)
goto free_area;
area->xol_mapping.name = "[uprobes]";
area->xol_mapping.fault = NULL;
area->xol_mapping.pages = area->pages;
area->pages[0] = alloc_page(GFP_HIGHUSER);
if (!area->pages[0])
goto free_bitmap;
area->pages[1] = NULL;
area->vaddr = vaddr;
init_waitqueue_head(&area->wq);
set_bit(0, area->bitmap);
atomic_set(&area->slot_count, 1);
copy_to_page(area->pages[0], 0, &insn, UPROBE_SWBP_INSN_SIZE);
if (!xol_add_vma(mm, area))
return area;
__free_page(area->pages[0]);
free_bitmap:
kfree(area->bitmap);
free_area:
kfree(area);
out:
return NULL;
}
static struct xol_area *get_xol_area(void)
{
struct mm_struct *mm = current->mm;
struct xol_area *area;
if (!mm->uprobes_state.xol_area)
__create_xol_area(0);
area = mm->uprobes_state.xol_area;
smp_read_barrier_depends();
return area;
}
void uprobe_clear_state(struct mm_struct *mm)
{
struct xol_area *area = mm->uprobes_state.xol_area;
if (!area)
return;
put_page(area->pages[0]);
kfree(area->bitmap);
kfree(area);
}
void uprobe_start_dup_mmap(void)
{
percpu_down_read(&dup_mmap_sem);
}
void uprobe_end_dup_mmap(void)
{
percpu_up_read(&dup_mmap_sem);
}
void uprobe_dup_mmap(struct mm_struct *oldmm, struct mm_struct *newmm)
{
newmm->uprobes_state.xol_area = NULL;
if (test_bit(MMF_HAS_UPROBES, &oldmm->flags)) {
set_bit(MMF_HAS_UPROBES, &newmm->flags);
set_bit(MMF_RECALC_UPROBES, &newmm->flags);
}
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
static unsigned long xol_get_insn_slot(struct uprobe *uprobe)
{
struct xol_area *area;
unsigned long xol_vaddr;
area = get_xol_area();
if (!area)
return 0;
xol_vaddr = xol_take_insn_slot(area);
if (unlikely(!xol_vaddr))
return 0;
arch_uprobe_copy_ixol(area->pages[0], xol_vaddr,
&uprobe->arch.ixol, sizeof(uprobe->arch.ixol));
return xol_vaddr;
}
static void xol_free_insn_slot(struct task_struct *tsk)
{
struct xol_area *area;
unsigned long vma_end;
unsigned long slot_addr;
if (!tsk->mm || !tsk->mm->uprobes_state.xol_area || !tsk->utask)
return;
slot_addr = tsk->utask->xol_vaddr;
if (unlikely(!slot_addr))
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
smp_mb__after_atomic();
if (waitqueue_active(&area->wq))
wake_up(&area->wq);
tsk->utask->xol_vaddr = 0;
}
}
void __weak arch_uprobe_copy_ixol(struct page *page, unsigned long vaddr,
void *src, unsigned long len)
{
copy_to_page(page, vaddr, src, len);
flush_dcache_page(page);
}
unsigned long __weak uprobe_get_swbp_addr(struct pt_regs *regs)
{
return instruction_pointer(regs) - UPROBE_SWBP_INSN_SIZE;
}
unsigned long uprobe_get_trap_addr(struct pt_regs *regs)
{
struct uprobe_task *utask = current->utask;
if (unlikely(utask && utask->active_uprobe))
return utask->vaddr;
return instruction_pointer(regs);
}
static struct return_instance *free_ret_instance(struct return_instance *ri)
{
struct return_instance *next = ri->next;
put_uprobe(ri->uprobe);
kfree(ri);
return next;
}
void uprobe_free_utask(struct task_struct *t)
{
struct uprobe_task *utask = t->utask;
struct return_instance *ri;
if (!utask)
return;
if (utask->active_uprobe)
put_uprobe(utask->active_uprobe);
ri = utask->return_instances;
while (ri)
ri = free_ret_instance(ri);
xol_free_insn_slot(t);
kfree(utask);
t->utask = NULL;
}
static struct uprobe_task *get_utask(void)
{
if (!current->utask)
current->utask = kzalloc(sizeof(struct uprobe_task), GFP_KERNEL);
return current->utask;
}
static int dup_utask(struct task_struct *t, struct uprobe_task *o_utask)
{
struct uprobe_task *n_utask;
struct return_instance **p, *o, *n;
n_utask = kzalloc(sizeof(struct uprobe_task), GFP_KERNEL);
if (!n_utask)
return -ENOMEM;
t->utask = n_utask;
p = &n_utask->return_instances;
for (o = o_utask->return_instances; o; o = o->next) {
n = kmalloc(sizeof(struct return_instance), GFP_KERNEL);
if (!n)
return -ENOMEM;
*n = *o;
get_uprobe(n->uprobe);
n->next = NULL;
*p = n;
p = &n->next;
n_utask->depth++;
}
return 0;
}
static void uprobe_warn(struct task_struct *t, const char *msg)
{
pr_warn("uprobe: %s:%d failed to %s\n",
current->comm, current->pid, msg);
}
static void dup_xol_work(struct callback_head *work)
{
if (current->flags & PF_EXITING)
return;
if (!__create_xol_area(current->utask->dup_xol_addr) &&
!fatal_signal_pending(current))
uprobe_warn(current, "dup xol area");
}
void uprobe_copy_process(struct task_struct *t, unsigned long flags)
{
struct uprobe_task *utask = current->utask;
struct mm_struct *mm = current->mm;
struct xol_area *area;
t->utask = NULL;
if (!utask || !utask->return_instances)
return;
if (mm == t->mm && !(flags & CLONE_VFORK))
return;
if (dup_utask(t, utask))
return uprobe_warn(t, "dup ret instances");
area = mm->uprobes_state.xol_area;
if (!area)
return uprobe_warn(t, "dup xol area");
if (mm == t->mm)
return;
t->utask->dup_xol_addr = area->vaddr;
init_task_work(&t->utask->dup_xol_work, dup_xol_work);
task_work_add(t, &t->utask->dup_xol_work, true);
}
static unsigned long get_trampoline_vaddr(void)
{
struct xol_area *area;
unsigned long trampoline_vaddr = -1;
area = current->mm->uprobes_state.xol_area;
smp_read_barrier_depends();
if (area)
trampoline_vaddr = area->vaddr;
return trampoline_vaddr;
}
static void cleanup_return_instances(struct uprobe_task *utask, bool chained,
struct pt_regs *regs)
{
struct return_instance *ri = utask->return_instances;
enum rp_check ctx = chained ? RP_CHECK_CHAIN_CALL : RP_CHECK_CALL;
while (ri && !arch_uretprobe_is_alive(ri, ctx, regs)) {
ri = free_ret_instance(ri);
utask->depth--;
}
utask->return_instances = ri;
}
static void prepare_uretprobe(struct uprobe *uprobe, struct pt_regs *regs)
{
struct return_instance *ri;
struct uprobe_task *utask;
unsigned long orig_ret_vaddr, trampoline_vaddr;
bool chained;
if (!get_xol_area())
return;
utask = get_utask();
if (!utask)
return;
if (utask->depth >= MAX_URETPROBE_DEPTH) {
printk_ratelimited(KERN_INFO "uprobe: omit uretprobe due to"
" nestedness limit pid/tgid=%d/%d\n",
current->pid, current->tgid);
return;
}
ri = kmalloc(sizeof(struct return_instance), GFP_KERNEL);
if (!ri)
return;
trampoline_vaddr = get_trampoline_vaddr();
orig_ret_vaddr = arch_uretprobe_hijack_return_addr(trampoline_vaddr, regs);
if (orig_ret_vaddr == -1)
goto fail;
chained = (orig_ret_vaddr == trampoline_vaddr);
cleanup_return_instances(utask, chained, regs);
if (chained) {
if (!utask->return_instances) {
uprobe_warn(current, "handle tail call");
goto fail;
}
orig_ret_vaddr = utask->return_instances->orig_ret_vaddr;
}
ri->uprobe = get_uprobe(uprobe);
ri->func = instruction_pointer(regs);
ri->stack = user_stack_pointer(regs);
ri->orig_ret_vaddr = orig_ret_vaddr;
ri->chained = chained;
utask->depth++;
ri->next = utask->return_instances;
utask->return_instances = ri;
return;
fail:
kfree(ri);
}
static int
pre_ssout(struct uprobe *uprobe, struct pt_regs *regs, unsigned long bp_vaddr)
{
struct uprobe_task *utask;
unsigned long xol_vaddr;
int err;
utask = get_utask();
if (!utask)
return -ENOMEM;
xol_vaddr = xol_get_insn_slot(uprobe);
if (!xol_vaddr)
return -ENOMEM;
utask->xol_vaddr = xol_vaddr;
utask->vaddr = bp_vaddr;
err = arch_uprobe_pre_xol(&uprobe->arch, regs);
if (unlikely(err)) {
xol_free_insn_slot(current);
return err;
}
utask->active_uprobe = uprobe;
utask->state = UTASK_SSTEP;
return 0;
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
}
}
return true;
}
static void mmf_recalc_uprobes(struct mm_struct *mm)
{
struct vm_area_struct *vma;
for (vma = mm->mmap; vma; vma = vma->vm_next) {
if (!valid_vma(vma, false))
continue;
if (vma_has_uprobes(vma, vma->vm_start, vma->vm_end))
return;
}
clear_bit(MMF_HAS_UPROBES, &mm->flags);
}
static int is_trap_at_addr(struct mm_struct *mm, unsigned long vaddr)
{
struct page *page;
uprobe_opcode_t opcode;
int result;
pagefault_disable();
result = __get_user(opcode, (uprobe_opcode_t __user *)vaddr);
pagefault_enable();
if (likely(result == 0))
goto out;
result = get_user_pages_remote(NULL, mm, vaddr, 1, FOLL_FORCE, &page,
NULL);
if (result < 0)
return result;
copy_from_page(page, vaddr, &opcode, UPROBE_SWBP_INSN_SIZE);
put_page(page);
out:
return is_trap_insn(&opcode);
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
struct inode *inode = file_inode(vma->vm_file);
loff_t offset = vaddr_to_offset(vma, bp_vaddr);
uprobe = find_uprobe(inode, offset);
}
if (!uprobe)
*is_swbp = is_trap_at_addr(mm, bp_vaddr);
} else {
*is_swbp = -EFAULT;
}
if (!uprobe && test_and_clear_bit(MMF_RECALC_UPROBES, &mm->flags))
mmf_recalc_uprobes(mm);
up_read(&mm->mmap_sem);
return uprobe;
}
static void handler_chain(struct uprobe *uprobe, struct pt_regs *regs)
{
struct uprobe_consumer *uc;
int remove = UPROBE_HANDLER_REMOVE;
bool need_prep = false;
down_read(&uprobe->register_rwsem);
for (uc = uprobe->consumers; uc; uc = uc->next) {
int rc = 0;
if (uc->handler) {
rc = uc->handler(uc, regs);
WARN(rc & ~UPROBE_HANDLER_MASK,
"bad rc=0x%x from %pf()\n", rc, uc->handler);
}
if (uc->ret_handler)
need_prep = true;
remove &= rc;
}
if (need_prep && !remove)
prepare_uretprobe(uprobe, regs);
if (remove && uprobe->consumers) {
WARN_ON(!uprobe_is_active(uprobe));
unapply_uprobe(uprobe, current->mm);
}
up_read(&uprobe->register_rwsem);
}
static void
handle_uretprobe_chain(struct return_instance *ri, struct pt_regs *regs)
{
struct uprobe *uprobe = ri->uprobe;
struct uprobe_consumer *uc;
down_read(&uprobe->register_rwsem);
for (uc = uprobe->consumers; uc; uc = uc->next) {
if (uc->ret_handler)
uc->ret_handler(uc, ri->func, regs);
}
up_read(&uprobe->register_rwsem);
}
static struct return_instance *find_next_ret_chain(struct return_instance *ri)
{
bool chained;
do {
chained = ri->chained;
ri = ri->next;
} while (chained);
return ri;
}
static void handle_trampoline(struct pt_regs *regs)
{
struct uprobe_task *utask;
struct return_instance *ri, *next;
bool valid;
utask = current->utask;
if (!utask)
goto sigill;
ri = utask->return_instances;
if (!ri)
goto sigill;
do {
next = find_next_ret_chain(ri);
valid = !next || arch_uretprobe_is_alive(next, RP_CHECK_RET, regs);
instruction_pointer_set(regs, ri->orig_ret_vaddr);
do {
if (valid)
handle_uretprobe_chain(ri, regs);
ri = free_ret_instance(ri);
utask->depth--;
} while (ri != next);
} while (!valid);
utask->return_instances = ri;
return;
sigill:
uprobe_warn(current, "handle uretprobe, sending SIGILL.");
force_sig_info(SIGILL, SEND_SIG_FORCED, current);
}
bool __weak arch_uprobe_ignore(struct arch_uprobe *aup, struct pt_regs *regs)
{
return false;
}
bool __weak arch_uretprobe_is_alive(struct return_instance *ret, enum rp_check ctx,
struct pt_regs *regs)
{
return true;
}
static void handle_swbp(struct pt_regs *regs)
{
struct uprobe *uprobe;
unsigned long bp_vaddr;
int uninitialized_var(is_swbp);
bp_vaddr = uprobe_get_swbp_addr(regs);
if (bp_vaddr == get_trampoline_vaddr())
return handle_trampoline(regs);
uprobe = find_active_uprobe(bp_vaddr, &is_swbp);
if (!uprobe) {
if (is_swbp > 0) {
send_sig(SIGTRAP, current, 0);
} else {
instruction_pointer_set(regs, bp_vaddr);
}
return;
}
instruction_pointer_set(regs, bp_vaddr);
smp_rmb();
if (unlikely(!test_bit(UPROBE_COPY_INSN, &uprobe->flags)))
goto out;
if (!get_utask())
goto out;
if (arch_uprobe_ignore(&uprobe->arch, regs))
goto out;
handler_chain(uprobe, regs);
if (arch_uprobe_skip_sstep(&uprobe->arch, regs))
goto out;
if (!pre_ssout(uprobe, regs, bp_vaddr))
return;
out:
put_uprobe(uprobe);
}
static void handle_singlestep(struct uprobe_task *utask, struct pt_regs *regs)
{
struct uprobe *uprobe;
int err = 0;
uprobe = utask->active_uprobe;
if (utask->state == UTASK_SSTEP_ACK)
err = arch_uprobe_post_xol(&uprobe->arch, regs);
else if (utask->state == UTASK_SSTEP_TRAPPED)
arch_uprobe_abort_xol(&uprobe->arch, regs);
else
WARN_ON_ONCE(1);
put_uprobe(uprobe);
utask->active_uprobe = NULL;
utask->state = UTASK_RUNNING;
xol_free_insn_slot(current);
spin_lock_irq(&current->sighand->siglock);
recalc_sigpending();
spin_unlock_irq(&current->sighand->siglock);
if (unlikely(err)) {
uprobe_warn(current, "execute the probed insn, sending SIGILL.");
force_sig_info(SIGILL, SEND_SIG_FORCED, current);
}
}
void uprobe_notify_resume(struct pt_regs *regs)
{
struct uprobe_task *utask;
clear_thread_flag(TIF_UPROBE);
utask = current->utask;
if (utask && utask->active_uprobe)
handle_singlestep(utask, regs);
else
handle_swbp(regs);
}
int uprobe_pre_sstep_notifier(struct pt_regs *regs)
{
if (!current->mm)
return 0;
if (!test_bit(MMF_HAS_UPROBES, &current->mm->flags) &&
(!current->utask || !current->utask->return_instances))
return 0;
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
for (i = 0; i < UPROBES_HASH_SZ; i++)
mutex_init(&uprobes_mmap_mutex[i]);
if (percpu_init_rwsem(&dup_mmap_sem))
return -ENOMEM;
return register_die_notifier(&uprobe_exception_nb);
}
