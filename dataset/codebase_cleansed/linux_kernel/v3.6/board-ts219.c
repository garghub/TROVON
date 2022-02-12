void __init qnap_dt_ts219_init(void)
{
u32 dev, rev;
kirkwood_mpp_conf(qnap_ts219_mpp_config);
kirkwood_pcie_id(&dev, &rev);
if (dev == MV88F6282_DEV_ID)
qnap_ts219_ge00_data.phy_addr = MV643XX_ETH_PHY_ADDR(0);
kirkwood_ge00_init(&qnap_ts219_ge00_data);
kirkwood_ehci_init();
pm_power_off = qnap_tsx1x_power_off;
}
static int __init ts219_pci_init(void)
{
if (machine_is_ts219())
kirkwood_pcie_init(KW_PCIE0);
return 0;
}
