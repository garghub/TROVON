static void config_mac(struct xlr_net_data *nd, int phy, u32 __iomem *serdes,
u32 __iomem *pcs, int rfr, int tx, int *bkt_size,
struct xlr_fmn_info *gmac_fmn_info, int phy_addr)
{
nd->cpu_mask = nlm_current_node()->coremask;
nd->phy_interface = phy;
nd->rfr_station = rfr;
nd->tx_stnid = tx;
nd->mii_addr = gmac0_addr;
nd->serdes_addr = serdes;
nd->pcs_addr = pcs;
nd->gpio_addr = gpio_addr;
nd->bucket_size = bkt_size;
nd->gmac_fmn_info = gmac_fmn_info;
nd->phy_addr = phy_addr;
}
static void net_device_init(int id, struct resource *res, int offset, int irq)
{
res[0].name = "gmac";
res[0].start = CPHYSADDR(nlm_mmio_base(offset));
res[0].end = res[0].start + 0xfff;
res[0].flags = IORESOURCE_MEM;
res[1].name = "gmac";
res[1].start = irq;
res[1].end = irq;
res[1].flags = IORESOURCE_IRQ;
xlr_net_dev[id].name = "xlr-net";
xlr_net_dev[id].id = id;
xlr_net_dev[id].num_resources = 2;
xlr_net_dev[id].resource = res;
xlr_net_dev[id].dev.platform_data = &ndata[id];
}
static void xls_gmac_init(void)
{
int mac;
gmac4_addr = ioremap(CPHYSADDR(
nlm_mmio_base(NETLOGIC_IO_GMAC_4_OFFSET)), 0xfff);
gpio_addr = ioremap(CPHYSADDR(
nlm_mmio_base(NETLOGIC_IO_GPIO_OFFSET)), 0xfff);
switch (nlm_prom_info.board_major_version) {
case 12:
config_mac(&ndata[0],
PHY_INTERFACE_MODE_RGMII,
gmac0_addr,
gmac0_addr,
FMN_STNID_GMACRFR_0,
FMN_STNID_GMAC0_TX0,
xlr_board_fmn_config.bucket_size,
&xlr_board_fmn_config.gmac[0],
0);
net_device_init(0, xlr_net_res[0], xlr_gmac_offsets[0],
xlr_gmac_irqs[0]);
platform_device_register(&xlr_net_dev[0]);
break;
default:
for (mac = 0; mac < 4; mac++) {
config_mac(&ndata[mac],
PHY_INTERFACE_MODE_SGMII,
gmac0_addr,
gmac0_addr,
FMN_STNID_GMACRFR_0,
FMN_STNID_GMAC0_TX0 + mac,
xlr_board_fmn_config.bucket_size,
&xlr_board_fmn_config.gmac[0],
mac + 0x10);
net_device_init(mac, xlr_net_res[mac],
xlr_gmac_offsets[mac],
xlr_gmac_irqs[mac]);
platform_device_register(&xlr_net_dev[mac]);
}
for (mac = 4; mac < MAX_NUM_XLS_GMAC; mac++) {
config_mac(&ndata[mac],
PHY_INTERFACE_MODE_SGMII,
gmac4_addr,
gmac4_addr,
FMN_STNID_GMAC1_FR_0,
FMN_STNID_GMAC1_TX0 + mac - 4,
xlr_board_fmn_config.bucket_size,
&xlr_board_fmn_config.gmac[1],
mac + 0x10);
net_device_init(mac, xlr_net_res[mac],
xlr_gmac_offsets[mac],
xlr_gmac_irqs[mac]);
platform_device_register(&xlr_net_dev[mac]);
}
}
}
static void xlr_gmac_init(void)
{
int mac;
for (mac = 0; mac < MAX_NUM_XLR_GMAC; mac++) {
config_mac(&ndata[mac],
PHY_INTERFACE_MODE_RGMII,
0,
0,
FMN_STNID_GMACRFR_0,
FMN_STNID_GMAC0_TX0,
xlr_board_fmn_config.bucket_size,
&xlr_board_fmn_config.gmac[0],
mac);
net_device_init(mac, xlr_net_res[mac], xlr_gmac_offsets[mac],
xlr_gmac_irqs[mac]);
platform_device_register(&xlr_net_dev[mac]);
}
}
static int __init xlr_net_init(void)
{
gmac0_addr = ioremap(CPHYSADDR(
nlm_mmio_base(NETLOGIC_IO_GMAC_0_OFFSET)), 0xfff);
if (nlm_chip_is_xls())
xls_gmac_init();
else
xlr_gmac_init();
return 0;
}
