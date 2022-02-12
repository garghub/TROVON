static int __init init_rc_map_pctv_sedna(void)
{
return rc_map_register(&pctv_sedna_map);
}
static void __exit exit_rc_map_pctv_sedna(void)
{
rc_map_unregister(&pctv_sedna_map);
}
