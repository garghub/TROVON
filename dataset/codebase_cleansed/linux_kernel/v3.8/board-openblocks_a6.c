void __init openblocks_a6_init(void)
{
kirkwood_mpp_conf(openblocks_a6_mpp_config);
kirkwood_ge00_init(&openblocks_ge00_data);
}
