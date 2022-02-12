static int __init s390_arch_random_init(void)
{
if (cpacf_query_func(CPACF_PRNO, CPACF_PRNO_TRNG))
static_branch_enable(&s390_arch_random_available);
return 0;
}
