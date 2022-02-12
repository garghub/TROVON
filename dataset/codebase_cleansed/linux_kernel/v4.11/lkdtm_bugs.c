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
static noinline void __lkdtm_CORRUPT_STACK(void *stack)
{
memset(stack, 'a', 64);
}
noinline void lkdtm_CORRUPT_STACK(void)
{
char data[8];
__lkdtm_CORRUPT_STACK(&data);
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
void lkdtm_REFCOUNT_SATURATE_INC(void)
{
refcount_t over = REFCOUNT_INIT(UINT_MAX - 1);
pr_info("attempting good refcount decrement\n");
refcount_dec(&over);
refcount_inc(&over);
pr_info("attempting bad refcount inc overflow\n");
refcount_inc(&over);
refcount_inc(&over);
if (refcount_read(&over) == UINT_MAX)
pr_err("Correctly stayed saturated, but no BUG?!\n");
else
pr_err("Fail: refcount wrapped\n");
}
void lkdtm_REFCOUNT_SATURATE_ADD(void)
{
refcount_t over = REFCOUNT_INIT(UINT_MAX - 1);
pr_info("attempting good refcount decrement\n");
refcount_dec(&over);
refcount_inc(&over);
pr_info("attempting bad refcount add overflow\n");
refcount_add(2, &over);
if (refcount_read(&over) == UINT_MAX)
pr_err("Correctly stayed saturated, but no BUG?!\n");
else
pr_err("Fail: refcount wrapped\n");
}
void lkdtm_REFCOUNT_ZERO_DEC(void)
{
refcount_t zero = REFCOUNT_INIT(1);
pr_info("attempting bad refcount decrement to zero\n");
refcount_dec(&zero);
if (refcount_read(&zero) == 0)
pr_err("Stayed at zero, but no BUG?!\n");
else
pr_err("Fail: refcount went crazy\n");
}
void lkdtm_REFCOUNT_ZERO_SUB(void)
{
refcount_t zero = REFCOUNT_INIT(1);
pr_info("attempting bad refcount subtract past zero\n");
if (!refcount_sub_and_test(2, &zero))
pr_info("wrap attempt was noticed\n");
if (refcount_read(&zero) == 1)
pr_err("Correctly stayed above 0, but no BUG?!\n");
else
pr_err("Fail: refcount wrapped\n");
}
void lkdtm_REFCOUNT_ZERO_INC(void)
{
refcount_t zero = REFCOUNT_INIT(0);
pr_info("attempting bad refcount increment from zero\n");
refcount_inc(&zero);
if (refcount_read(&zero) == 0)
pr_err("Stayed at zero, but no BUG?!\n");
else
pr_err("Fail: refcount went past zero\n");
}
void lkdtm_REFCOUNT_ZERO_ADD(void)
{
refcount_t zero = REFCOUNT_INIT(0);
pr_info("attempting bad refcount addition from zero\n");
refcount_add(2, &zero);
if (refcount_read(&zero) == 0)
pr_err("Stayed at zero, but no BUG?!\n");
else
pr_err("Fail: refcount went past zero\n");
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
