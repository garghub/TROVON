static int recursive_loop(int remaining)
{
char buf[REC_STACK_SIZE];
memset(buf, (remaining & 0xff) | 0x1, REC_STACK_SIZE);
if (!remaining)
return 0;
else
return recursive_loop(remaining - 1);
}
void __init lkdtm_bugs_init(int *recur_param)
{
if (*recur_param < 0)
*recur_param = recur_count;
else
recur_count = *recur_param;
}
void lkdtm_PANIC(void)
{
panic("dumptest");
}
void lkdtm_BUG(void)
{
BUG();
}
void lkdtm_WARNING(void)
{
WARN_ON(1);
}
void lkdtm_EXCEPTION(void)
{
*((int *) 0) = 0;
}
void lkdtm_LOOP(void)
{
for (;;)
;
}
void lkdtm_OVERFLOW(void)
{
(void) recursive_loop(recur_count);
}
noinline void lkdtm_CORRUPT_STACK(void)
{
char data[8];
memset((void *)data, 'a', 64);
pr_info("Corrupted stack with '%16s'...\n", data);
}
void lkdtm_UNALIGNED_LOAD_STORE_WRITE(void)
{
static u8 data[5] __attribute__((aligned(4))) = {1, 2, 3, 4, 5};
u32 *p;
u32 val = 0x12345678;
p = (u32 *)(data + 1);
if (*p == 0)
val = 0x87654321;
*p = val;
}
void lkdtm_SOFTLOCKUP(void)
{
preempt_disable();
for (;;)
cpu_relax();
}
void lkdtm_HARDLOCKUP(void)
{
local_irq_disable();
for (;;)
cpu_relax();
}
void lkdtm_SPINLOCKUP(void)
{
spin_lock(&lock_me_up);
__release(&lock_me_up);
}
void lkdtm_HUNG_TASK(void)
{
set_current_state(TASK_UNINTERRUPTIBLE);
schedule();
}
void lkdtm_ATOMIC_UNDERFLOW(void)
{
atomic_t under = ATOMIC_INIT(INT_MIN);
pr_info("attempting good atomic increment\n");
atomic_inc(&under);
atomic_dec(&under);
pr_info("attempting bad atomic underflow\n");
atomic_dec(&under);
}
void lkdtm_ATOMIC_OVERFLOW(void)
{
atomic_t over = ATOMIC_INIT(INT_MAX);
pr_info("attempting good atomic decrement\n");
atomic_dec(&over);
atomic_inc(&over);
pr_info("attempting bad atomic overflow\n");
atomic_inc(&over);
}
void lkdtm_CORRUPT_LIST_ADD(void)
{
LIST_HEAD(test_head);
struct lkdtm_list good, bad;
void *target[2] = { };
void *redirection = &target;
pr_info("attempting good list addition\n");
list_add(&good.node, &test_head);
pr_info("attempting corrupted list addition\n");
test_head.next = redirection;
list_add(&bad.node, &test_head);
if (target[0] == NULL && target[1] == NULL)
pr_err("Overwrite did not happen, but no BUG?!\n");
else
pr_err("list_add() corruption not detected!\n");
}
void lkdtm_CORRUPT_LIST_DEL(void)
{
LIST_HEAD(test_head);
struct lkdtm_list item;
void *target[2] = { };
void *redirection = &target;
list_add(&item.node, &test_head);
pr_info("attempting good list removal\n");
list_del(&item.node);
pr_info("attempting corrupted list removal\n");
list_add(&item.node, &test_head);
item.node.next = redirection;
list_del(&item.node);
if (target[0] == NULL && target[1] == NULL)
pr_err("Overwrite did not happen, but no BUG?!\n");
else
pr_err("list_del() corruption not detected!\n");
}
