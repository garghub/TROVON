void __init usi_topkick_init(void)
{
kirkwood_mpp_conf(topkick_mpp_config);
kirkwood_ge00_init(&topkick_ge00_data);
kirkwood_sdio_init(&topkick_mvsdio_data);
}
