void __init t5325_init(void)
{
i2c_register_board_info(0, i2c_board_info, ARRAY_SIZE(i2c_board_info));
platform_device_register(&hp_t5325_audio_device);
}
