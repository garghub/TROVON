static int __init init_rc_lme2510_map(void)
{
return rc_map_register(&lme2510_map);
}
static void __exit exit_rc_lme2510_map(void)
{
rc_map_unregister(&lme2510_map);
}
