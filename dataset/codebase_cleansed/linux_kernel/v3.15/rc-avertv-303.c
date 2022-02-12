static int __init init_rc_map_avertv_303(void)
{
return rc_map_register(&avertv_303_map);
}
static void __exit exit_rc_map_avertv_303(void)
{
rc_map_unregister(&avertv_303_map);
}
