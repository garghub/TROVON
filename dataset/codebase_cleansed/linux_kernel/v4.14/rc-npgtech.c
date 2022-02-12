static int __init init_rc_map_npgtech(void)
{
return rc_map_register(&npgtech_map);
}
static void __exit exit_rc_map_npgtech(void)
{
rc_map_unregister(&npgtech_map);
}
