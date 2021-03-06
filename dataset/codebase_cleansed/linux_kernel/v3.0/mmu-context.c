int init_new_context(struct task_struct *tsk, struct mm_struct *mm)
{
memset(&mm->context, 0, sizeof(mm->context));
INIT_LIST_HEAD(&mm->context.id_link);
mm->context.itlb_cached_pge = 0xffffffffUL;
mm->context.dtlb_cached_pge = 0xffffffffUL;
return 0;
}
static unsigned get_cxn(mm_context_t *ctx)
{
struct list_head *_p;
mm_context_t *p;
unsigned cxn;
if (!list_empty(&ctx->id_link)) {
list_move_tail(&ctx->id_link, &cxn_owners_lru);
}
else {
cxn = find_next_zero_bit(cxn_bitmap, NR_CXN, 1);
if (cxn < NR_CXN) {
set_bit(cxn, cxn_bitmap);
}
else {
p = NULL;
list_for_each(_p, &cxn_owners_lru) {
p = list_entry(_p, mm_context_t, id_link);
if (!p->id_busy && p->id != cxn_pinned)
break;
}
BUG_ON(_p == &cxn_owners_lru);
cxn = p->id;
p->id = 0;
list_del_init(&p->id_link);
__flush_tlb_mm(cxn);
}
ctx->id = cxn;
list_add_tail(&ctx->id_link, &cxn_owners_lru);
}
return ctx->id;
}
void change_mm_context(mm_context_t *old, mm_context_t *ctx, pgd_t *pgd)
{
unsigned long _pgd;
_pgd = virt_to_phys(pgd);
old->id_busy = 0;
asm volatile("movsg scr0,%0" : "=r"(old->itlb_cached_pge));
asm volatile("movsg dampr4,%0" : "=r"(old->itlb_ptd_mapping));
asm volatile("movsg scr1,%0" : "=r"(old->dtlb_cached_pge));
asm volatile("movsg dampr5,%0" : "=r"(old->dtlb_ptd_mapping));
spin_lock(&cxn_owners_lock);
get_cxn(ctx);
ctx->id_busy = 1;
spin_unlock(&cxn_owners_lock);
asm volatile("movgs %0,cxnr" : : "r"(ctx->id));
asm volatile("movgs %0,scr0" : : "r"(ctx->itlb_cached_pge));
asm volatile("movgs %0,dampr4" : : "r"(ctx->itlb_ptd_mapping));
asm volatile("movgs %0,scr1" : : "r"(ctx->dtlb_cached_pge));
asm volatile("movgs %0,dampr5" : : "r"(ctx->dtlb_ptd_mapping));
asm volatile("movgs %0,ttbr" : : "r"(_pgd));
asm volatile("movgs %0,dampr3"
:: "r"(_pgd | xAMPRx_L | xAMPRx_M | xAMPRx_SS_16Kb |
xAMPRx_S | xAMPRx_C | xAMPRx_V));
}
void destroy_context(struct mm_struct *mm)
{
mm_context_t *ctx = &mm->context;
spin_lock(&cxn_owners_lock);
if (!list_empty(&ctx->id_link)) {
if (ctx->id == cxn_pinned)
cxn_pinned = -1;
list_del_init(&ctx->id_link);
clear_bit(ctx->id, cxn_bitmap);
__flush_tlb_mm(ctx->id);
ctx->id = 0;
}
spin_unlock(&cxn_owners_lock);
}
char *proc_pid_status_frv_cxnr(struct mm_struct *mm, char *buffer)
{
spin_lock(&cxn_owners_lock);
buffer += sprintf(buffer, "CXNR: %u\n", mm->context.id);
spin_unlock(&cxn_owners_lock);
return buffer;
}
int cxn_pin_by_pid(pid_t pid)
{
struct task_struct *tsk;
struct mm_struct *mm = NULL;
int ret;
if (pid == 0) {
cxn_pinned = -1;
return 0;
}
ret = -ESRCH;
read_lock(&tasklist_lock);
tsk = find_task_by_vpid(pid);
if (tsk) {
ret = -EINVAL;
task_lock(tsk);
if (tsk->mm) {
mm = tsk->mm;
atomic_inc(&mm->mm_users);
ret = 0;
}
task_unlock(tsk);
}
read_unlock(&tasklist_lock);
if (ret < 0)
return ret;
spin_lock(&cxn_owners_lock);
cxn_pinned = get_cxn(&mm->context);
spin_unlock(&cxn_owners_lock);
mmput(mm);
return 0;
}
