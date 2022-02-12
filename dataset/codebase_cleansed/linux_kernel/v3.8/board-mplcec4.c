void __init mplcec4_init(void)
{
kirkwood_ge00_init(&mplcec4_ge00_data);
kirkwood_ge01_init(&mplcec4_ge01_data);
kirkwood_sdio_init(&mplcec4_mvsdio_data);
kirkwood_pcie_init(KW_PCIE0);
}
