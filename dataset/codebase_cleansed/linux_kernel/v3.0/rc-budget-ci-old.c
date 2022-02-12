static int __init init_rc_map_budget_ci_old(void)
{
return rc_map_register(&budget_ci_old_map);
}
static void __exit exit_rc_map_budget_ci_old(void)
{
rc_map_unregister(&budget_ci_old_map);
}
