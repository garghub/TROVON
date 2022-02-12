static int __init init_rc_map_real_audio_220_32_keys(void)
{
return rc_map_register(&real_audio_220_32_keys_map);
}
static void __exit exit_rc_map_real_audio_220_32_keys(void)
{
rc_map_unregister(&real_audio_220_32_keys_map);
}
