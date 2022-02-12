void __init qnap_dt_ts219_init(void)
{
u32 dev, rev;
kirkwood_pcie_id(&dev, &rev);
if (dev == MV88F6282_DEV_ID)
qnap_ts219_ge00_data.phy_addr = MV643XX_ETH_PHY_ADDR(0);
kirkwood_ge00_init(&qnap_ts219_ge00_data);
pm_power_off = qnap_tsx1x_power_off;
}
