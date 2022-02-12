static int __init init_rc_map_em_terratec(void)
{
return rc_map_register(&em_terratec_map);
}
static void __exit exit_rc_map_em_terratec(void)
{
rc_map_unregister(&em_terratec_map);
}
