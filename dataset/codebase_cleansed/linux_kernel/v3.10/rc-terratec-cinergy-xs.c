static int __init init_rc_map_terratec_cinergy_xs(void)
{
return rc_map_register(&terratec_cinergy_xs_map);
}
static void __exit exit_rc_map_terratec_cinergy_xs(void)
{
rc_map_unregister(&terratec_cinergy_xs_map);
}
