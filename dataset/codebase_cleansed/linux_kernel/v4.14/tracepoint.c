int trace_pagefault_reg(void)
{
static_branch_inc(&trace_pagefault_key);
return 0;
}
void trace_pagefault_unreg(void)
{
static_branch_dec(&trace_pagefault_key);
}
int trace_resched_ipi_reg(void)
{
static_branch_inc(&trace_resched_ipi_key);
return 0;
}
void trace_resched_ipi_unreg(void)
{
static_branch_dec(&trace_resched_ipi_key);
}
