static int __init init_rc_map_terratec_slim_2(void)
{
return rc_map_register(&terratec_slim_2_map);
}
static void __exit exit_rc_map_terratec_slim_2(void)
{
rc_map_unregister(&terratec_slim_2_map);
}
