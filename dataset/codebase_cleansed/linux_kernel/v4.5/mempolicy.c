struct mempolicy *get_task_policy(struct task_struct *p)
{
struct mempolicy *pol = p->mempolicy;
int node;
if (pol)
return pol;
node = numa_node_id();
if (node != NUMA_NO_NODE) {
pol = &preferred_node_policy[node];
if (pol->mode)
return pol;
}
return &default_policy;
}
static inline int mpol_store_user_nodemask(const struct mempolicy *pol)
{
return pol->flags & MPOL_MODE_FLAGS;
}
static void mpol_relative_nodemask(nodemask_t *ret, const nodemask_t *orig,
const nodemask_t *rel)
{
nodemask_t tmp;
nodes_fold(tmp, *orig, nodes_weight(*rel));
nodes_onto(*ret, tmp, *rel);
}
static int mpol_new_interleave(struct mempolicy *pol, const nodemask_t *nodes)
{
if (nodes_empty(*nodes))
return -EINVAL;
pol->v.nodes = *nodes;
return 0;
}
static int mpol_new_preferred(struct mempolicy *pol, const nodemask_t *nodes)
{
if (!nodes)
pol->flags |= MPOL_F_LOCAL;
else if (nodes_empty(*nodes))
return -EINVAL;
else
pol->v.preferred_node = first_node(*nodes);
return 0;
}
static int mpol_new_bind(struct mempolicy *pol, const nodemask_t *nodes)
{
if (nodes_empty(*nodes))
return -EINVAL;
pol->v.nodes = *nodes;
return 0;
}
static int mpol_set_nodemask(struct mempolicy *pol,
const nodemask_t *nodes, struct nodemask_scratch *nsc)
{
int ret;
if (pol == NULL)
return 0;
nodes_and(nsc->mask1,
cpuset_current_mems_allowed, node_states[N_MEMORY]);
VM_BUG_ON(!nodes);
if (pol->mode == MPOL_PREFERRED && nodes_empty(*nodes))
nodes = NULL;
else {
if (pol->flags & MPOL_F_RELATIVE_NODES)
mpol_relative_nodemask(&nsc->mask2, nodes, &nsc->mask1);
else
nodes_and(nsc->mask2, *nodes, nsc->mask1);
if (mpol_store_user_nodemask(pol))
pol->w.user_nodemask = *nodes;
else
pol->w.cpuset_mems_allowed =
cpuset_current_mems_allowed;
}
if (nodes)
ret = mpol_ops[pol->mode].create(pol, &nsc->mask2);
else
ret = mpol_ops[pol->mode].create(pol, NULL);
return ret;
}
static struct mempolicy *mpol_new(unsigned short mode, unsigned short flags,
nodemask_t *nodes)
{
struct mempolicy *policy;
pr_debug("setting mode %d flags %d nodes[0] %lx\n",
mode, flags, nodes ? nodes_addr(*nodes)[0] : NUMA_NO_NODE);
if (mode == MPOL_DEFAULT) {
if (nodes && !nodes_empty(*nodes))
return ERR_PTR(-EINVAL);
return NULL;
}
VM_BUG_ON(!nodes);
if (mode == MPOL_PREFERRED) {
if (nodes_empty(*nodes)) {
if (((flags & MPOL_F_STATIC_NODES) ||
(flags & MPOL_F_RELATIVE_NODES)))
return ERR_PTR(-EINVAL);
}
} else if (mode == MPOL_LOCAL) {
if (!nodes_empty(*nodes))
return ERR_PTR(-EINVAL);
mode = MPOL_PREFERRED;
} else if (nodes_empty(*nodes))
return ERR_PTR(-EINVAL);
policy = kmem_cache_alloc(policy_cache, GFP_KERNEL);
if (!policy)
return ERR_PTR(-ENOMEM);
atomic_set(&policy->refcnt, 1);
policy->mode = mode;
policy->flags = flags;
return policy;
}
void __mpol_put(struct mempolicy *p)
{
if (!atomic_dec_and_test(&p->refcnt))
return;
kmem_cache_free(policy_cache, p);
}
static void mpol_rebind_default(struct mempolicy *pol, const nodemask_t *nodes,
enum mpol_rebind_step step)
{
}
static void mpol_rebind_nodemask(struct mempolicy *pol, const nodemask_t *nodes,
enum mpol_rebind_step step)
{
nodemask_t tmp;
if (pol->flags & MPOL_F_STATIC_NODES)
nodes_and(tmp, pol->w.user_nodemask, *nodes);
else if (pol->flags & MPOL_F_RELATIVE_NODES)
mpol_relative_nodemask(&tmp, &pol->w.user_nodemask, nodes);
else {
if (step == MPOL_REBIND_ONCE || step == MPOL_REBIND_STEP1) {
nodes_remap(tmp, pol->v.nodes,
pol->w.cpuset_mems_allowed, *nodes);
pol->w.cpuset_mems_allowed = step ? tmp : *nodes;
} else if (step == MPOL_REBIND_STEP2) {
tmp = pol->w.cpuset_mems_allowed;
pol->w.cpuset_mems_allowed = *nodes;
} else
BUG();
}
if (nodes_empty(tmp))
tmp = *nodes;
if (step == MPOL_REBIND_STEP1)
nodes_or(pol->v.nodes, pol->v.nodes, tmp);
else if (step == MPOL_REBIND_ONCE || step == MPOL_REBIND_STEP2)
pol->v.nodes = tmp;
else
BUG();
if (!node_isset(current->il_next, tmp)) {
current->il_next = next_node(current->il_next, tmp);
if (current->il_next >= MAX_NUMNODES)
current->il_next = first_node(tmp);
if (current->il_next >= MAX_NUMNODES)
current->il_next = numa_node_id();
}
}
static void mpol_rebind_preferred(struct mempolicy *pol,
const nodemask_t *nodes,
enum mpol_rebind_step step)
{
nodemask_t tmp;
if (pol->flags & MPOL_F_STATIC_NODES) {
int node = first_node(pol->w.user_nodemask);
if (node_isset(node, *nodes)) {
pol->v.preferred_node = node;
pol->flags &= ~MPOL_F_LOCAL;
} else
pol->flags |= MPOL_F_LOCAL;
} else if (pol->flags & MPOL_F_RELATIVE_NODES) {
mpol_relative_nodemask(&tmp, &pol->w.user_nodemask, nodes);
pol->v.preferred_node = first_node(tmp);
} else if (!(pol->flags & MPOL_F_LOCAL)) {
pol->v.preferred_node = node_remap(pol->v.preferred_node,
pol->w.cpuset_mems_allowed,
*nodes);
pol->w.cpuset_mems_allowed = *nodes;
}
}
static void mpol_rebind_policy(struct mempolicy *pol, const nodemask_t *newmask,
enum mpol_rebind_step step)
{
if (!pol)
return;
if (!mpol_store_user_nodemask(pol) && step == MPOL_REBIND_ONCE &&
nodes_equal(pol->w.cpuset_mems_allowed, *newmask))
return;
if (step == MPOL_REBIND_STEP1 && (pol->flags & MPOL_F_REBINDING))
return;
if (step == MPOL_REBIND_STEP2 && !(pol->flags & MPOL_F_REBINDING))
BUG();
if (step == MPOL_REBIND_STEP1)
pol->flags |= MPOL_F_REBINDING;
else if (step == MPOL_REBIND_STEP2)
pol->flags &= ~MPOL_F_REBINDING;
else if (step >= MPOL_REBIND_NSTEP)
BUG();
mpol_ops[pol->mode].rebind(pol, newmask, step);
}
void mpol_rebind_task(struct task_struct *tsk, const nodemask_t *new,
enum mpol_rebind_step step)
{
mpol_rebind_policy(tsk->mempolicy, new, step);
}
void mpol_rebind_mm(struct mm_struct *mm, nodemask_t *new)
{
struct vm_area_struct *vma;
down_write(&mm->mmap_sem);
for (vma = mm->mmap; vma; vma = vma->vm_next)
mpol_rebind_policy(vma->vm_policy, new, MPOL_REBIND_ONCE);
up_write(&mm->mmap_sem);
}
static int queue_pages_pte_range(pmd_t *pmd, unsigned long addr,
unsigned long end, struct mm_walk *walk)
{
struct vm_area_struct *vma = walk->vma;
struct page *page;
struct queue_pages *qp = walk->private;
unsigned long flags = qp->flags;
int nid, ret;
pte_t *pte;
spinlock_t *ptl;
if (pmd_trans_huge(*pmd)) {
ptl = pmd_lock(walk->mm, pmd);
if (pmd_trans_huge(*pmd)) {
page = pmd_page(*pmd);
if (is_huge_zero_page(page)) {
spin_unlock(ptl);
split_huge_pmd(vma, pmd, addr);
} else {
get_page(page);
spin_unlock(ptl);
lock_page(page);
ret = split_huge_page(page);
unlock_page(page);
put_page(page);
if (ret)
return 0;
}
} else {
spin_unlock(ptl);
}
}
retry:
pte = pte_offset_map_lock(walk->mm, pmd, addr, &ptl);
for (; addr != end; pte++, addr += PAGE_SIZE) {
if (!pte_present(*pte))
continue;
page = vm_normal_page(vma, addr, *pte);
if (!page)
continue;
if (PageReserved(page))
continue;
nid = page_to_nid(page);
if (node_isset(nid, *qp->nmask) == !!(flags & MPOL_MF_INVERT))
continue;
if (PageTransCompound(page) && PageAnon(page)) {
get_page(page);
pte_unmap_unlock(pte, ptl);
lock_page(page);
ret = split_huge_page(page);
unlock_page(page);
put_page(page);
if (ret) {
pte = pte_offset_map_lock(walk->mm, pmd,
addr, &ptl);
continue;
}
goto retry;
}
migrate_page_add(page, qp->pagelist, flags);
}
pte_unmap_unlock(pte - 1, ptl);
cond_resched();
return 0;
}
static int queue_pages_hugetlb(pte_t *pte, unsigned long hmask,
unsigned long addr, unsigned long end,
struct mm_walk *walk)
{
#ifdef CONFIG_HUGETLB_PAGE
struct queue_pages *qp = walk->private;
unsigned long flags = qp->flags;
int nid;
struct page *page;
spinlock_t *ptl;
pte_t entry;
ptl = huge_pte_lock(hstate_vma(walk->vma), walk->mm, pte);
entry = huge_ptep_get(pte);
if (!pte_present(entry))
goto unlock;
page = pte_page(entry);
nid = page_to_nid(page);
if (node_isset(nid, *qp->nmask) == !!(flags & MPOL_MF_INVERT))
goto unlock;
if (flags & (MPOL_MF_MOVE_ALL) ||
(flags & MPOL_MF_MOVE && page_mapcount(page) == 1))
isolate_huge_page(page, qp->pagelist);
unlock:
spin_unlock(ptl);
#else
BUG();
#endif
return 0;
}
unsigned long change_prot_numa(struct vm_area_struct *vma,
unsigned long addr, unsigned long end)
{
int nr_updated;
nr_updated = change_protection(vma, addr, end, PAGE_NONE, 0, 1);
if (nr_updated)
count_vm_numa_events(NUMA_PTE_UPDATES, nr_updated);
return nr_updated;
}
static unsigned long change_prot_numa(struct vm_area_struct *vma,
unsigned long addr, unsigned long end)
{
return 0;
}
static int queue_pages_test_walk(unsigned long start, unsigned long end,
struct mm_walk *walk)
{
struct vm_area_struct *vma = walk->vma;
struct queue_pages *qp = walk->private;
unsigned long endvma = vma->vm_end;
unsigned long flags = qp->flags;
if (!vma_migratable(vma))
return 1;
if (endvma > end)
endvma = end;
if (vma->vm_start > start)
start = vma->vm_start;
if (!(flags & MPOL_MF_DISCONTIG_OK)) {
if (!vma->vm_next && vma->vm_end < end)
return -EFAULT;
if (qp->prev && qp->prev->vm_end < vma->vm_start)
return -EFAULT;
}
qp->prev = vma;
if (flags & MPOL_MF_LAZY) {
if (vma->vm_flags & (VM_READ | VM_EXEC | VM_WRITE))
change_prot_numa(vma, start, endvma);
return 1;
}
if (flags & (MPOL_MF_MOVE | MPOL_MF_MOVE_ALL))
return 0;
return 1;
}
static int
queue_pages_range(struct mm_struct *mm, unsigned long start, unsigned long end,
nodemask_t *nodes, unsigned long flags,
struct list_head *pagelist)
{
struct queue_pages qp = {
.pagelist = pagelist,
.flags = flags,
.nmask = nodes,
.prev = NULL,
};
struct mm_walk queue_pages_walk = {
.hugetlb_entry = queue_pages_hugetlb,
.pmd_entry = queue_pages_pte_range,
.test_walk = queue_pages_test_walk,
.mm = mm,
.private = &qp,
};
return walk_page_range(start, end, &queue_pages_walk);
}
static int vma_replace_policy(struct vm_area_struct *vma,
struct mempolicy *pol)
{
int err;
struct mempolicy *old;
struct mempolicy *new;
pr_debug("vma %lx-%lx/%lx vm_ops %p vm_file %p set_policy %p\n",
vma->vm_start, vma->vm_end, vma->vm_pgoff,
vma->vm_ops, vma->vm_file,
vma->vm_ops ? vma->vm_ops->set_policy : NULL);
new = mpol_dup(pol);
if (IS_ERR(new))
return PTR_ERR(new);
if (vma->vm_ops && vma->vm_ops->set_policy) {
err = vma->vm_ops->set_policy(vma, new);
if (err)
goto err_out;
}
old = vma->vm_policy;
vma->vm_policy = new;
mpol_put(old);
return 0;
err_out:
mpol_put(new);
return err;
}
static int mbind_range(struct mm_struct *mm, unsigned long start,
unsigned long end, struct mempolicy *new_pol)
{
struct vm_area_struct *next;
struct vm_area_struct *prev;
struct vm_area_struct *vma;
int err = 0;
pgoff_t pgoff;
unsigned long vmstart;
unsigned long vmend;
vma = find_vma(mm, start);
if (!vma || vma->vm_start > start)
return -EFAULT;
prev = vma->vm_prev;
if (start > vma->vm_start)
prev = vma;
for (; vma && vma->vm_start < end; prev = vma, vma = next) {
next = vma->vm_next;
vmstart = max(start, vma->vm_start);
vmend = min(end, vma->vm_end);
if (mpol_equal(vma_policy(vma), new_pol))
continue;
pgoff = vma->vm_pgoff +
((vmstart - vma->vm_start) >> PAGE_SHIFT);
prev = vma_merge(mm, prev, vmstart, vmend, vma->vm_flags,
vma->anon_vma, vma->vm_file, pgoff,
new_pol, vma->vm_userfaultfd_ctx);
if (prev) {
vma = prev;
next = vma->vm_next;
if (mpol_equal(vma_policy(vma), new_pol))
continue;
goto replace;
}
if (vma->vm_start != vmstart) {
err = split_vma(vma->vm_mm, vma, vmstart, 1);
if (err)
goto out;
}
if (vma->vm_end != vmend) {
err = split_vma(vma->vm_mm, vma, vmend, 0);
if (err)
goto out;
}
replace:
err = vma_replace_policy(vma, new_pol);
if (err)
goto out;
}
out:
return err;
}
static long do_set_mempolicy(unsigned short mode, unsigned short flags,
nodemask_t *nodes)
{
struct mempolicy *new, *old;
NODEMASK_SCRATCH(scratch);
int ret;
if (!scratch)
return -ENOMEM;
new = mpol_new(mode, flags, nodes);
if (IS_ERR(new)) {
ret = PTR_ERR(new);
goto out;
}
task_lock(current);
ret = mpol_set_nodemask(new, nodes, scratch);
if (ret) {
task_unlock(current);
mpol_put(new);
goto out;
}
old = current->mempolicy;
current->mempolicy = new;
if (new && new->mode == MPOL_INTERLEAVE &&
nodes_weight(new->v.nodes))
current->il_next = first_node(new->v.nodes);
task_unlock(current);
mpol_put(old);
ret = 0;
out:
NODEMASK_SCRATCH_FREE(scratch);
return ret;
}
static void get_policy_nodemask(struct mempolicy *p, nodemask_t *nodes)
{
nodes_clear(*nodes);
if (p == &default_policy)
return;
switch (p->mode) {
case MPOL_BIND:
case MPOL_INTERLEAVE:
*nodes = p->v.nodes;
break;
case MPOL_PREFERRED:
if (!(p->flags & MPOL_F_LOCAL))
node_set(p->v.preferred_node, *nodes);
break;
default:
BUG();
}
}
static int lookup_node(struct mm_struct *mm, unsigned long addr)
{
struct page *p;
int err;
err = get_user_pages(current, mm, addr & PAGE_MASK, 1, 0, 0, &p, NULL);
if (err >= 0) {
err = page_to_nid(p);
put_page(p);
}
return err;
}
static long do_get_mempolicy(int *policy, nodemask_t *nmask,
unsigned long addr, unsigned long flags)
{
int err;
struct mm_struct *mm = current->mm;
struct vm_area_struct *vma = NULL;
struct mempolicy *pol = current->mempolicy;
if (flags &
~(unsigned long)(MPOL_F_NODE|MPOL_F_ADDR|MPOL_F_MEMS_ALLOWED))
return -EINVAL;
if (flags & MPOL_F_MEMS_ALLOWED) {
if (flags & (MPOL_F_NODE|MPOL_F_ADDR))
return -EINVAL;
*policy = 0;
task_lock(current);
*nmask = cpuset_current_mems_allowed;
task_unlock(current);
return 0;
}
if (flags & MPOL_F_ADDR) {
down_read(&mm->mmap_sem);
vma = find_vma_intersection(mm, addr, addr+1);
if (!vma) {
up_read(&mm->mmap_sem);
return -EFAULT;
}
if (vma->vm_ops && vma->vm_ops->get_policy)
pol = vma->vm_ops->get_policy(vma, addr);
else
pol = vma->vm_policy;
} else if (addr)
return -EINVAL;
if (!pol)
pol = &default_policy;
if (flags & MPOL_F_NODE) {
if (flags & MPOL_F_ADDR) {
err = lookup_node(mm, addr);
if (err < 0)
goto out;
*policy = err;
} else if (pol == current->mempolicy &&
pol->mode == MPOL_INTERLEAVE) {
*policy = current->il_next;
} else {
err = -EINVAL;
goto out;
}
} else {
*policy = pol == &default_policy ? MPOL_DEFAULT :
pol->mode;
*policy |= (pol->flags & MPOL_MODE_FLAGS);
}
if (vma) {
up_read(&current->mm->mmap_sem);
vma = NULL;
}
err = 0;
if (nmask) {
if (mpol_store_user_nodemask(pol)) {
*nmask = pol->w.user_nodemask;
} else {
task_lock(current);
get_policy_nodemask(pol, nmask);
task_unlock(current);
}
}
out:
mpol_cond_put(pol);
if (vma)
up_read(&current->mm->mmap_sem);
return err;
}
static void migrate_page_add(struct page *page, struct list_head *pagelist,
unsigned long flags)
{
if ((flags & MPOL_MF_MOVE_ALL) || page_mapcount(page) == 1) {
if (!isolate_lru_page(page)) {
list_add_tail(&page->lru, pagelist);
inc_zone_page_state(page, NR_ISOLATED_ANON +
page_is_file_cache(page));
}
}
}
static struct page *new_node_page(struct page *page, unsigned long node, int **x)
{
if (PageHuge(page))
return alloc_huge_page_node(page_hstate(compound_head(page)),
node);
else
return __alloc_pages_node(node, GFP_HIGHUSER_MOVABLE |
__GFP_THISNODE, 0);
}
static int migrate_to_node(struct mm_struct *mm, int source, int dest,
int flags)
{
nodemask_t nmask;
LIST_HEAD(pagelist);
int err = 0;
nodes_clear(nmask);
node_set(source, nmask);
VM_BUG_ON(!(flags & (MPOL_MF_MOVE | MPOL_MF_MOVE_ALL)));
queue_pages_range(mm, mm->mmap->vm_start, mm->task_size, &nmask,
flags | MPOL_MF_DISCONTIG_OK, &pagelist);
if (!list_empty(&pagelist)) {
err = migrate_pages(&pagelist, new_node_page, NULL, dest,
MIGRATE_SYNC, MR_SYSCALL);
if (err)
putback_movable_pages(&pagelist);
}
return err;
}
int do_migrate_pages(struct mm_struct *mm, const nodemask_t *from,
const nodemask_t *to, int flags)
{
int busy = 0;
int err;
nodemask_t tmp;
err = migrate_prep();
if (err)
return err;
down_read(&mm->mmap_sem);
tmp = *from;
while (!nodes_empty(tmp)) {
int s,d;
int source = NUMA_NO_NODE;
int dest = 0;
for_each_node_mask(s, tmp) {
if ((nodes_weight(*from) != nodes_weight(*to)) &&
(node_isset(s, *to)))
continue;
d = node_remap(s, *from, *to);
if (s == d)
continue;
source = s;
dest = d;
if (!node_isset(dest, tmp))
break;
}
if (source == NUMA_NO_NODE)
break;
node_clear(source, tmp);
err = migrate_to_node(mm, source, dest, flags);
if (err > 0)
busy += err;
if (err < 0)
break;
}
up_read(&mm->mmap_sem);
if (err < 0)
return err;
return busy;
}
static struct page *new_page(struct page *page, unsigned long start, int **x)
{
struct vm_area_struct *vma;
unsigned long uninitialized_var(address);
vma = find_vma(current->mm, start);
while (vma) {
address = page_address_in_vma(page, vma);
if (address != -EFAULT)
break;
vma = vma->vm_next;
}
if (PageHuge(page)) {
BUG_ON(!vma);
return alloc_huge_page_noerr(vma, address, 1);
}
return alloc_page_vma(GFP_HIGHUSER_MOVABLE, vma, address);
}
static void migrate_page_add(struct page *page, struct list_head *pagelist,
unsigned long flags)
{
}
int do_migrate_pages(struct mm_struct *mm, const nodemask_t *from,
const nodemask_t *to, int flags)
{
return -ENOSYS;
}
static struct page *new_page(struct page *page, unsigned long start, int **x)
{
return NULL;
}
static long do_mbind(unsigned long start, unsigned long len,
unsigned short mode, unsigned short mode_flags,
nodemask_t *nmask, unsigned long flags)
{
struct mm_struct *mm = current->mm;
struct mempolicy *new;
unsigned long end;
int err;
LIST_HEAD(pagelist);
if (flags & ~(unsigned long)MPOL_MF_VALID)
return -EINVAL;
if ((flags & MPOL_MF_MOVE_ALL) && !capable(CAP_SYS_NICE))
return -EPERM;
if (start & ~PAGE_MASK)
return -EINVAL;
if (mode == MPOL_DEFAULT)
flags &= ~MPOL_MF_STRICT;
len = (len + PAGE_SIZE - 1) & PAGE_MASK;
end = start + len;
if (end < start)
return -EINVAL;
if (end == start)
return 0;
new = mpol_new(mode, mode_flags, nmask);
if (IS_ERR(new))
return PTR_ERR(new);
if (flags & MPOL_MF_LAZY)
new->flags |= MPOL_F_MOF;
if (!new)
flags |= MPOL_MF_DISCONTIG_OK;
pr_debug("mbind %lx-%lx mode:%d flags:%d nodes:%lx\n",
start, start + len, mode, mode_flags,
nmask ? nodes_addr(*nmask)[0] : NUMA_NO_NODE);
if (flags & (MPOL_MF_MOVE | MPOL_MF_MOVE_ALL)) {
err = migrate_prep();
if (err)
goto mpol_out;
}
{
NODEMASK_SCRATCH(scratch);
if (scratch) {
down_write(&mm->mmap_sem);
task_lock(current);
err = mpol_set_nodemask(new, nmask, scratch);
task_unlock(current);
if (err)
up_write(&mm->mmap_sem);
} else
err = -ENOMEM;
NODEMASK_SCRATCH_FREE(scratch);
}
if (err)
goto mpol_out;
err = queue_pages_range(mm, start, end, nmask,
flags | MPOL_MF_INVERT, &pagelist);
if (!err)
err = mbind_range(mm, start, end, new);
if (!err) {
int nr_failed = 0;
if (!list_empty(&pagelist)) {
WARN_ON_ONCE(flags & MPOL_MF_LAZY);
nr_failed = migrate_pages(&pagelist, new_page, NULL,
start, MIGRATE_SYNC, MR_MEMPOLICY_MBIND);
if (nr_failed)
putback_movable_pages(&pagelist);
}
if (nr_failed && (flags & MPOL_MF_STRICT))
err = -EIO;
} else
putback_movable_pages(&pagelist);
up_write(&mm->mmap_sem);
mpol_out:
mpol_put(new);
return err;
}
static int get_nodes(nodemask_t *nodes, const unsigned long __user *nmask,
unsigned long maxnode)
{
unsigned long k;
unsigned long nlongs;
unsigned long endmask;
--maxnode;
nodes_clear(*nodes);
if (maxnode == 0 || !nmask)
return 0;
if (maxnode > PAGE_SIZE*BITS_PER_BYTE)
return -EINVAL;
nlongs = BITS_TO_LONGS(maxnode);
if ((maxnode % BITS_PER_LONG) == 0)
endmask = ~0UL;
else
endmask = (1UL << (maxnode % BITS_PER_LONG)) - 1;
if (nlongs > BITS_TO_LONGS(MAX_NUMNODES)) {
if (nlongs > PAGE_SIZE/sizeof(long))
return -EINVAL;
for (k = BITS_TO_LONGS(MAX_NUMNODES); k < nlongs; k++) {
unsigned long t;
if (get_user(t, nmask + k))
return -EFAULT;
if (k == nlongs - 1) {
if (t & endmask)
return -EINVAL;
} else if (t)
return -EINVAL;
}
nlongs = BITS_TO_LONGS(MAX_NUMNODES);
endmask = ~0UL;
}
if (copy_from_user(nodes_addr(*nodes), nmask, nlongs*sizeof(unsigned long)))
return -EFAULT;
nodes_addr(*nodes)[nlongs-1] &= endmask;
return 0;
}
static int copy_nodes_to_user(unsigned long __user *mask, unsigned long maxnode,
nodemask_t *nodes)
{
unsigned long copy = ALIGN(maxnode-1, 64) / 8;
const int nbytes = BITS_TO_LONGS(MAX_NUMNODES) * sizeof(long);
if (copy > nbytes) {
if (copy > PAGE_SIZE)
return -EINVAL;
if (clear_user((char __user *)mask + nbytes, copy - nbytes))
return -EFAULT;
copy = nbytes;
}
return copy_to_user(mask, nodes_addr(*nodes), copy) ? -EFAULT : 0;
}
struct mempolicy *__get_vma_policy(struct vm_area_struct *vma,
unsigned long addr)
{
struct mempolicy *pol = NULL;
if (vma) {
if (vma->vm_ops && vma->vm_ops->get_policy) {
pol = vma->vm_ops->get_policy(vma, addr);
} else if (vma->vm_policy) {
pol = vma->vm_policy;
if (mpol_needs_cond_ref(pol))
mpol_get(pol);
}
}
return pol;
}
static struct mempolicy *get_vma_policy(struct vm_area_struct *vma,
unsigned long addr)
{
struct mempolicy *pol = __get_vma_policy(vma, addr);
if (!pol)
pol = get_task_policy(current);
return pol;
}
bool vma_policy_mof(struct vm_area_struct *vma)
{
struct mempolicy *pol;
if (vma->vm_ops && vma->vm_ops->get_policy) {
bool ret = false;
pol = vma->vm_ops->get_policy(vma, vma->vm_start);
if (pol && (pol->flags & MPOL_F_MOF))
ret = true;
mpol_cond_put(pol);
return ret;
}
pol = vma->vm_policy;
if (!pol)
pol = get_task_policy(current);
return pol->flags & MPOL_F_MOF;
}
static int apply_policy_zone(struct mempolicy *policy, enum zone_type zone)
{
enum zone_type dynamic_policy_zone = policy_zone;
BUG_ON(dynamic_policy_zone == ZONE_MOVABLE);
if (!nodes_intersects(policy->v.nodes, node_states[N_HIGH_MEMORY]))
dynamic_policy_zone = ZONE_MOVABLE;
return zone >= dynamic_policy_zone;
}
static nodemask_t *policy_nodemask(gfp_t gfp, struct mempolicy *policy)
{
if (unlikely(policy->mode == MPOL_BIND) &&
apply_policy_zone(policy, gfp_zone(gfp)) &&
cpuset_nodemask_valid_mems_allowed(&policy->v.nodes))
return &policy->v.nodes;
return NULL;
}
static struct zonelist *policy_zonelist(gfp_t gfp, struct mempolicy *policy,
int nd)
{
switch (policy->mode) {
case MPOL_PREFERRED:
if (!(policy->flags & MPOL_F_LOCAL))
nd = policy->v.preferred_node;
break;
case MPOL_BIND:
if (unlikely(gfp & __GFP_THISNODE) &&
unlikely(!node_isset(nd, policy->v.nodes)))
nd = first_node(policy->v.nodes);
break;
default:
BUG();
}
return node_zonelist(nd, gfp);
}
static unsigned interleave_nodes(struct mempolicy *policy)
{
unsigned nid, next;
struct task_struct *me = current;
nid = me->il_next;
next = next_node(nid, policy->v.nodes);
if (next >= MAX_NUMNODES)
next = first_node(policy->v.nodes);
if (next < MAX_NUMNODES)
me->il_next = next;
return nid;
}
unsigned int mempolicy_slab_node(void)
{
struct mempolicy *policy;
int node = numa_mem_id();
if (in_interrupt())
return node;
policy = current->mempolicy;
if (!policy || policy->flags & MPOL_F_LOCAL)
return node;
switch (policy->mode) {
case MPOL_PREFERRED:
return policy->v.preferred_node;
case MPOL_INTERLEAVE:
return interleave_nodes(policy);
case MPOL_BIND: {
struct zonelist *zonelist;
struct zone *zone;
enum zone_type highest_zoneidx = gfp_zone(GFP_KERNEL);
zonelist = &NODE_DATA(node)->node_zonelists[0];
(void)first_zones_zonelist(zonelist, highest_zoneidx,
&policy->v.nodes,
&zone);
return zone ? zone->node : node;
}
default:
BUG();
}
}
static unsigned offset_il_node(struct mempolicy *pol,
struct vm_area_struct *vma, unsigned long off)
{
unsigned nnodes = nodes_weight(pol->v.nodes);
unsigned target;
int c;
int nid = NUMA_NO_NODE;
if (!nnodes)
return numa_node_id();
target = (unsigned int)off % nnodes;
c = 0;
do {
nid = next_node(nid, pol->v.nodes);
c++;
} while (c <= target);
return nid;
}
static inline unsigned interleave_nid(struct mempolicy *pol,
struct vm_area_struct *vma, unsigned long addr, int shift)
{
if (vma) {
unsigned long off;
BUG_ON(shift < PAGE_SHIFT);
off = vma->vm_pgoff >> (shift - PAGE_SHIFT);
off += (addr - vma->vm_start) >> shift;
return offset_il_node(pol, vma, off);
} else
return interleave_nodes(pol);
}
int node_random(const nodemask_t *maskp)
{
int w, bit = NUMA_NO_NODE;
w = nodes_weight(*maskp);
if (w)
bit = bitmap_ord_to_pos(maskp->bits,
get_random_int() % w, MAX_NUMNODES);
return bit;
}
struct zonelist *huge_zonelist(struct vm_area_struct *vma, unsigned long addr,
gfp_t gfp_flags, struct mempolicy **mpol,
nodemask_t **nodemask)
{
struct zonelist *zl;
*mpol = get_vma_policy(vma, addr);
*nodemask = NULL;
if (unlikely((*mpol)->mode == MPOL_INTERLEAVE)) {
zl = node_zonelist(interleave_nid(*mpol, vma, addr,
huge_page_shift(hstate_vma(vma))), gfp_flags);
} else {
zl = policy_zonelist(gfp_flags, *mpol, numa_node_id());
if ((*mpol)->mode == MPOL_BIND)
*nodemask = &(*mpol)->v.nodes;
}
return zl;
}
bool init_nodemask_of_mempolicy(nodemask_t *mask)
{
struct mempolicy *mempolicy;
int nid;
if (!(mask && current->mempolicy))
return false;
task_lock(current);
mempolicy = current->mempolicy;
switch (mempolicy->mode) {
case MPOL_PREFERRED:
if (mempolicy->flags & MPOL_F_LOCAL)
nid = numa_node_id();
else
nid = mempolicy->v.preferred_node;
init_nodemask_of_node(mask, nid);
break;
case MPOL_BIND:
case MPOL_INTERLEAVE:
*mask = mempolicy->v.nodes;
break;
default:
BUG();
}
task_unlock(current);
return true;
}
bool mempolicy_nodemask_intersects(struct task_struct *tsk,
const nodemask_t *mask)
{
struct mempolicy *mempolicy;
bool ret = true;
if (!mask)
return ret;
task_lock(tsk);
mempolicy = tsk->mempolicy;
if (!mempolicy)
goto out;
switch (mempolicy->mode) {
case MPOL_PREFERRED:
break;
case MPOL_BIND:
case MPOL_INTERLEAVE:
ret = nodes_intersects(mempolicy->v.nodes, *mask);
break;
default:
BUG();
}
out:
task_unlock(tsk);
return ret;
}
static struct page *alloc_page_interleave(gfp_t gfp, unsigned order,
unsigned nid)
{
struct zonelist *zl;
struct page *page;
zl = node_zonelist(nid, gfp);
page = __alloc_pages(gfp, order, zl);
if (page && page_zone(page) == zonelist_zone(&zl->_zonerefs[0]))
inc_zone_page_state(page, NUMA_INTERLEAVE_HIT);
return page;
}
struct page *
alloc_pages_vma(gfp_t gfp, int order, struct vm_area_struct *vma,
unsigned long addr, int node, bool hugepage)
{
struct mempolicy *pol;
struct page *page;
unsigned int cpuset_mems_cookie;
struct zonelist *zl;
nodemask_t *nmask;
retry_cpuset:
pol = get_vma_policy(vma, addr);
cpuset_mems_cookie = read_mems_allowed_begin();
if (pol->mode == MPOL_INTERLEAVE) {
unsigned nid;
nid = interleave_nid(pol, vma, addr, PAGE_SHIFT + order);
mpol_cond_put(pol);
page = alloc_page_interleave(gfp, order, nid);
goto out;
}
if (unlikely(IS_ENABLED(CONFIG_TRANSPARENT_HUGEPAGE) && hugepage)) {
int hpage_node = node;
if (pol->mode == MPOL_PREFERRED &&
!(pol->flags & MPOL_F_LOCAL))
hpage_node = pol->v.preferred_node;
nmask = policy_nodemask(gfp, pol);
if (!nmask || node_isset(hpage_node, *nmask)) {
mpol_cond_put(pol);
page = __alloc_pages_node(hpage_node,
gfp | __GFP_THISNODE, order);
goto out;
}
}
nmask = policy_nodemask(gfp, pol);
zl = policy_zonelist(gfp, pol, node);
mpol_cond_put(pol);
page = __alloc_pages_nodemask(gfp, order, zl, nmask);
out:
if (unlikely(!page && read_mems_allowed_retry(cpuset_mems_cookie)))
goto retry_cpuset;
return page;
}
struct page *alloc_pages_current(gfp_t gfp, unsigned order)
{
struct mempolicy *pol = &default_policy;
struct page *page;
unsigned int cpuset_mems_cookie;
if (!in_interrupt() && !(gfp & __GFP_THISNODE))
pol = get_task_policy(current);
retry_cpuset:
cpuset_mems_cookie = read_mems_allowed_begin();
if (pol->mode == MPOL_INTERLEAVE)
page = alloc_page_interleave(gfp, order, interleave_nodes(pol));
else
page = __alloc_pages_nodemask(gfp, order,
policy_zonelist(gfp, pol, numa_node_id()),
policy_nodemask(gfp, pol));
if (unlikely(!page && read_mems_allowed_retry(cpuset_mems_cookie)))
goto retry_cpuset;
return page;
}
int vma_dup_policy(struct vm_area_struct *src, struct vm_area_struct *dst)
{
struct mempolicy *pol = mpol_dup(vma_policy(src));
if (IS_ERR(pol))
return PTR_ERR(pol);
dst->vm_policy = pol;
return 0;
}
struct mempolicy *__mpol_dup(struct mempolicy *old)
{
struct mempolicy *new = kmem_cache_alloc(policy_cache, GFP_KERNEL);
if (!new)
return ERR_PTR(-ENOMEM);
if (old == current->mempolicy) {
task_lock(current);
*new = *old;
task_unlock(current);
} else
*new = *old;
if (current_cpuset_is_being_rebound()) {
nodemask_t mems = cpuset_mems_allowed(current);
if (new->flags & MPOL_F_REBINDING)
mpol_rebind_policy(new, &mems, MPOL_REBIND_STEP2);
else
mpol_rebind_policy(new, &mems, MPOL_REBIND_ONCE);
}
atomic_set(&new->refcnt, 1);
return new;
}
bool __mpol_equal(struct mempolicy *a, struct mempolicy *b)
{
if (!a || !b)
return false;
if (a->mode != b->mode)
return false;
if (a->flags != b->flags)
return false;
if (mpol_store_user_nodemask(a))
if (!nodes_equal(a->w.user_nodemask, b->w.user_nodemask))
return false;
switch (a->mode) {
case MPOL_BIND:
case MPOL_INTERLEAVE:
return !!nodes_equal(a->v.nodes, b->v.nodes);
case MPOL_PREFERRED:
return a->v.preferred_node == b->v.preferred_node;
default:
BUG();
return false;
}
}
static struct sp_node *
sp_lookup(struct shared_policy *sp, unsigned long start, unsigned long end)
{
struct rb_node *n = sp->root.rb_node;
while (n) {
struct sp_node *p = rb_entry(n, struct sp_node, nd);
if (start >= p->end)
n = n->rb_right;
else if (end <= p->start)
n = n->rb_left;
else
break;
}
if (!n)
return NULL;
for (;;) {
struct sp_node *w = NULL;
struct rb_node *prev = rb_prev(n);
if (!prev)
break;
w = rb_entry(prev, struct sp_node, nd);
if (w->end <= start)
break;
n = prev;
}
return rb_entry(n, struct sp_node, nd);
}
static void sp_insert(struct shared_policy *sp, struct sp_node *new)
{
struct rb_node **p = &sp->root.rb_node;
struct rb_node *parent = NULL;
struct sp_node *nd;
while (*p) {
parent = *p;
nd = rb_entry(parent, struct sp_node, nd);
if (new->start < nd->start)
p = &(*p)->rb_left;
else if (new->end > nd->end)
p = &(*p)->rb_right;
else
BUG();
}
rb_link_node(&new->nd, parent, p);
rb_insert_color(&new->nd, &sp->root);
pr_debug("inserting %lx-%lx: %d\n", new->start, new->end,
new->policy ? new->policy->mode : 0);
}
struct mempolicy *
mpol_shared_policy_lookup(struct shared_policy *sp, unsigned long idx)
{
struct mempolicy *pol = NULL;
struct sp_node *sn;
if (!sp->root.rb_node)
return NULL;
read_lock(&sp->lock);
sn = sp_lookup(sp, idx, idx+1);
if (sn) {
mpol_get(sn->policy);
pol = sn->policy;
}
read_unlock(&sp->lock);
return pol;
}
static void sp_free(struct sp_node *n)
{
mpol_put(n->policy);
kmem_cache_free(sn_cache, n);
}
int mpol_misplaced(struct page *page, struct vm_area_struct *vma, unsigned long addr)
{
struct mempolicy *pol;
struct zone *zone;
int curnid = page_to_nid(page);
unsigned long pgoff;
int thiscpu = raw_smp_processor_id();
int thisnid = cpu_to_node(thiscpu);
int polnid = -1;
int ret = -1;
BUG_ON(!vma);
pol = get_vma_policy(vma, addr);
if (!(pol->flags & MPOL_F_MOF))
goto out;
switch (pol->mode) {
case MPOL_INTERLEAVE:
BUG_ON(addr >= vma->vm_end);
BUG_ON(addr < vma->vm_start);
pgoff = vma->vm_pgoff;
pgoff += (addr - vma->vm_start) >> PAGE_SHIFT;
polnid = offset_il_node(pol, vma, pgoff);
break;
case MPOL_PREFERRED:
if (pol->flags & MPOL_F_LOCAL)
polnid = numa_node_id();
else
polnid = pol->v.preferred_node;
break;
case MPOL_BIND:
if (node_isset(curnid, pol->v.nodes))
goto out;
(void)first_zones_zonelist(
node_zonelist(numa_node_id(), GFP_HIGHUSER),
gfp_zone(GFP_HIGHUSER),
&pol->v.nodes, &zone);
polnid = zone->node;
break;
default:
BUG();
}
if (pol->flags & MPOL_F_MORON) {
polnid = thisnid;
if (!should_numa_migrate_memory(current, page, curnid, thiscpu))
goto out;
}
if (curnid != polnid)
ret = polnid;
out:
mpol_cond_put(pol);
return ret;
}
static void sp_delete(struct shared_policy *sp, struct sp_node *n)
{
pr_debug("deleting %lx-l%lx\n", n->start, n->end);
rb_erase(&n->nd, &sp->root);
sp_free(n);
}
static void sp_node_init(struct sp_node *node, unsigned long start,
unsigned long end, struct mempolicy *pol)
{
node->start = start;
node->end = end;
node->policy = pol;
}
static struct sp_node *sp_alloc(unsigned long start, unsigned long end,
struct mempolicy *pol)
{
struct sp_node *n;
struct mempolicy *newpol;
n = kmem_cache_alloc(sn_cache, GFP_KERNEL);
if (!n)
return NULL;
newpol = mpol_dup(pol);
if (IS_ERR(newpol)) {
kmem_cache_free(sn_cache, n);
return NULL;
}
newpol->flags |= MPOL_F_SHARED;
sp_node_init(n, start, end, newpol);
return n;
}
static int shared_policy_replace(struct shared_policy *sp, unsigned long start,
unsigned long end, struct sp_node *new)
{
struct sp_node *n;
struct sp_node *n_new = NULL;
struct mempolicy *mpol_new = NULL;
int ret = 0;
restart:
write_lock(&sp->lock);
n = sp_lookup(sp, start, end);
while (n && n->start < end) {
struct rb_node *next = rb_next(&n->nd);
if (n->start >= start) {
if (n->end <= end)
sp_delete(sp, n);
else
n->start = end;
} else {
if (n->end > end) {
if (!n_new)
goto alloc_new;
*mpol_new = *n->policy;
atomic_set(&mpol_new->refcnt, 1);
sp_node_init(n_new, end, n->end, mpol_new);
n->end = start;
sp_insert(sp, n_new);
n_new = NULL;
mpol_new = NULL;
break;
} else
n->end = start;
}
if (!next)
break;
n = rb_entry(next, struct sp_node, nd);
}
if (new)
sp_insert(sp, new);
write_unlock(&sp->lock);
ret = 0;
err_out:
if (mpol_new)
mpol_put(mpol_new);
if (n_new)
kmem_cache_free(sn_cache, n_new);
return ret;
alloc_new:
write_unlock(&sp->lock);
ret = -ENOMEM;
n_new = kmem_cache_alloc(sn_cache, GFP_KERNEL);
if (!n_new)
goto err_out;
mpol_new = kmem_cache_alloc(policy_cache, GFP_KERNEL);
if (!mpol_new)
goto err_out;
goto restart;
}
void mpol_shared_policy_init(struct shared_policy *sp, struct mempolicy *mpol)
{
int ret;
sp->root = RB_ROOT;
rwlock_init(&sp->lock);
if (mpol) {
struct vm_area_struct pvma;
struct mempolicy *new;
NODEMASK_SCRATCH(scratch);
if (!scratch)
goto put_mpol;
new = mpol_new(mpol->mode, mpol->flags, &mpol->w.user_nodemask);
if (IS_ERR(new))
goto free_scratch;
task_lock(current);
ret = mpol_set_nodemask(new, &mpol->w.user_nodemask, scratch);
task_unlock(current);
if (ret)
goto put_new;
memset(&pvma, 0, sizeof(struct vm_area_struct));
pvma.vm_end = TASK_SIZE;
mpol_set_shared_policy(sp, &pvma, new);
put_new:
mpol_put(new);
free_scratch:
NODEMASK_SCRATCH_FREE(scratch);
put_mpol:
mpol_put(mpol);
}
}
int mpol_set_shared_policy(struct shared_policy *info,
struct vm_area_struct *vma, struct mempolicy *npol)
{
int err;
struct sp_node *new = NULL;
unsigned long sz = vma_pages(vma);
pr_debug("set_shared_policy %lx sz %lu %d %d %lx\n",
vma->vm_pgoff,
sz, npol ? npol->mode : -1,
npol ? npol->flags : -1,
npol ? nodes_addr(npol->v.nodes)[0] : NUMA_NO_NODE);
if (npol) {
new = sp_alloc(vma->vm_pgoff, vma->vm_pgoff + sz, npol);
if (!new)
return -ENOMEM;
}
err = shared_policy_replace(info, vma->vm_pgoff, vma->vm_pgoff+sz, new);
if (err && new)
sp_free(new);
return err;
}
void mpol_free_shared_policy(struct shared_policy *p)
{
struct sp_node *n;
struct rb_node *next;
if (!p->root.rb_node)
return;
write_lock(&p->lock);
next = rb_first(&p->root);
while (next) {
n = rb_entry(next, struct sp_node, nd);
next = rb_next(&n->nd);
sp_delete(p, n);
}
write_unlock(&p->lock);
}
static void __init check_numabalancing_enable(void)
{
bool numabalancing_default = false;
if (IS_ENABLED(CONFIG_NUMA_BALANCING_DEFAULT_ENABLED))
numabalancing_default = true;
if (numabalancing_override)
set_numabalancing_state(numabalancing_override == 1);
if (num_online_nodes() > 1 && !numabalancing_override) {
pr_info("%s automatic NUMA balancing. "
"Configure with numa_balancing= or the "
"kernel.numa_balancing sysctl",
numabalancing_default ? "Enabling" : "Disabling");
set_numabalancing_state(numabalancing_default);
}
}
static int __init setup_numabalancing(char *str)
{
int ret = 0;
if (!str)
goto out;
if (!strcmp(str, "enable")) {
numabalancing_override = 1;
ret = 1;
} else if (!strcmp(str, "disable")) {
numabalancing_override = -1;
ret = 1;
}
out:
if (!ret)
pr_warn("Unable to parse numa_balancing=\n");
return ret;
}
static inline void __init check_numabalancing_enable(void)
{
}
void __init numa_policy_init(void)
{
nodemask_t interleave_nodes;
unsigned long largest = 0;
int nid, prefer = 0;
policy_cache = kmem_cache_create("numa_policy",
sizeof(struct mempolicy),
0, SLAB_PANIC, NULL);
sn_cache = kmem_cache_create("shared_policy_node",
sizeof(struct sp_node),
0, SLAB_PANIC, NULL);
for_each_node(nid) {
preferred_node_policy[nid] = (struct mempolicy) {
.refcnt = ATOMIC_INIT(1),
.mode = MPOL_PREFERRED,
.flags = MPOL_F_MOF | MPOL_F_MORON,
.v = { .preferred_node = nid, },
};
}
nodes_clear(interleave_nodes);
for_each_node_state(nid, N_MEMORY) {
unsigned long total_pages = node_present_pages(nid);
if (largest < total_pages) {
largest = total_pages;
prefer = nid;
}
if ((total_pages << PAGE_SHIFT) >= (16 << 20))
node_set(nid, interleave_nodes);
}
if (unlikely(nodes_empty(interleave_nodes)))
node_set(prefer, interleave_nodes);
if (do_set_mempolicy(MPOL_INTERLEAVE, 0, &interleave_nodes))
pr_err("%s: interleaving failed\n", __func__);
check_numabalancing_enable();
}
void numa_default_policy(void)
{
do_set_mempolicy(MPOL_DEFAULT, 0, NULL);
}
int mpol_parse_str(char *str, struct mempolicy **mpol)
{
struct mempolicy *new = NULL;
unsigned short mode;
unsigned short mode_flags;
nodemask_t nodes;
char *nodelist = strchr(str, ':');
char *flags = strchr(str, '=');
int err = 1;
if (nodelist) {
*nodelist++ = '\0';
if (nodelist_parse(nodelist, nodes))
goto out;
if (!nodes_subset(nodes, node_states[N_MEMORY]))
goto out;
} else
nodes_clear(nodes);
if (flags)
*flags++ = '\0';
for (mode = 0; mode < MPOL_MAX; mode++) {
if (!strcmp(str, policy_modes[mode])) {
break;
}
}
if (mode >= MPOL_MAX)
goto out;
switch (mode) {
case MPOL_PREFERRED:
if (nodelist) {
char *rest = nodelist;
while (isdigit(*rest))
rest++;
if (*rest)
goto out;
}
break;
case MPOL_INTERLEAVE:
if (!nodelist)
nodes = node_states[N_MEMORY];
break;
case MPOL_LOCAL:
if (nodelist)
goto out;
mode = MPOL_PREFERRED;
break;
case MPOL_DEFAULT:
if (!nodelist)
err = 0;
goto out;
case MPOL_BIND:
if (!nodelist)
goto out;
}
mode_flags = 0;
if (flags) {
if (!strcmp(flags, "static"))
mode_flags |= MPOL_F_STATIC_NODES;
else if (!strcmp(flags, "relative"))
mode_flags |= MPOL_F_RELATIVE_NODES;
else
goto out;
}
new = mpol_new(mode, mode_flags, &nodes);
if (IS_ERR(new))
goto out;
if (mode != MPOL_PREFERRED)
new->v.nodes = nodes;
else if (nodelist)
new->v.preferred_node = first_node(nodes);
else
new->flags |= MPOL_F_LOCAL;
new->w.user_nodemask = nodes;
err = 0;
out:
if (nodelist)
*--nodelist = ':';
if (flags)
*--flags = '=';
if (!err)
*mpol = new;
return err;
}
void mpol_to_str(char *buffer, int maxlen, struct mempolicy *pol)
{
char *p = buffer;
nodemask_t nodes = NODE_MASK_NONE;
unsigned short mode = MPOL_DEFAULT;
unsigned short flags = 0;
if (pol && pol != &default_policy && !(pol->flags & MPOL_F_MORON)) {
mode = pol->mode;
flags = pol->flags;
}
switch (mode) {
case MPOL_DEFAULT:
break;
case MPOL_PREFERRED:
if (flags & MPOL_F_LOCAL)
mode = MPOL_LOCAL;
else
node_set(pol->v.preferred_node, nodes);
break;
case MPOL_BIND:
case MPOL_INTERLEAVE:
nodes = pol->v.nodes;
break;
default:
WARN_ON_ONCE(1);
snprintf(p, maxlen, "unknown");
return;
}
p += snprintf(p, maxlen, "%s", policy_modes[mode]);
if (flags & MPOL_MODE_FLAGS) {
p += snprintf(p, buffer + maxlen - p, "=");
if (flags & MPOL_F_STATIC_NODES)
p += snprintf(p, buffer + maxlen - p, "static");
else if (flags & MPOL_F_RELATIVE_NODES)
p += snprintf(p, buffer + maxlen - p, "relative");
}
if (!nodes_empty(nodes))
p += scnprintf(p, buffer + maxlen - p, ":%*pbl",
nodemask_pr_args(&nodes));
}
