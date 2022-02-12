static int __init bf5xx_board_init(void)
{
int ret;
bf5xx_board_snd_device = platform_device_alloc("soc-audio", -1);
if (!bf5xx_board_snd_device)
return -ENOMEM;
platform_set_drvdata(bf5xx_board_snd_device, &bf5xx_board);
ret = platform_device_add(bf5xx_board_snd_device);
if (ret)
platform_device_put(bf5xx_board_snd_device);
return ret;
}
static void __exit bf5xx_board_exit(void)
{
platform_device_unregister(bf5xx_board_snd_device);
}
