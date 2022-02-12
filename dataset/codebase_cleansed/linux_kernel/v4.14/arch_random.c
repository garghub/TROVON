static int __init s390_arch_random_init(void)\r\n{\r\nif (cpacf_query_func(CPACF_PRNO, CPACF_PRNO_TRNG))\r\nstatic_branch_enable(&s390_arch_random_available);\r\nreturn 0;\r\n}
