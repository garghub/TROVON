static int mpc8568_fixup_125_clock(struct phy_device *phydev)
{
int scr;
int err;
scr = phy_read(phydev, MV88E1111_SCR);
if (scr < 0)
return scr;
err = phy_write(phydev, MV88E1111_SCR, scr & ~(MV88E1111_SCR_125CLK));
if (err)
return err;
err = phy_write(phydev, MII_BMCR, BMCR_RESET);
if (err)
return err;
scr = phy_read(phydev, MV88E1111_SCR);
if (scr < 0)
return scr;
err = phy_write(phydev, MV88E1111_SCR, scr | 0x0008);
return err;
}
static int mpc8568_mds_phy_fixups(struct phy_device *phydev)
{
int temp;
int err;
err = phy_write(phydev,29, 0x0006);
if (err)
return err;
temp = phy_read(phydev, 30);
if (temp < 0)
return temp;
temp = (temp & (~0x8000)) | 0x4000;
err = phy_write(phydev,30, temp);
if (err)
return err;
err = phy_write(phydev,29, 0x000a);
if (err)
return err;
temp = phy_read(phydev, 30);
if (temp < 0)
return temp;
temp = phy_read(phydev, 30);
if (temp < 0)
return temp;
temp &= ~0x0020;
err = phy_write(phydev,30,temp);
if (err)
return err;
temp = phy_read(phydev, 16);
if (temp < 0)
return temp;
temp &= ~0x0060;
err = phy_write(phydev,16,temp);
return err;
}
static void __init mpc85xx_mds_reset_ucc_phys(void)
{
struct device_node *np;
static u8 __iomem *bcsr_regs;
np = of_find_node_by_name(NULL, "bcsr");
if (!np)
return;
bcsr_regs = of_iomap(np, 0);
of_node_put(np);
if (!bcsr_regs)
return;
if (machine_is(mpc8568_mds)) {
#define BCSR_UCC1_GETH_EN (0x1 << 7)
#define BCSR_UCC2_GETH_EN (0x1 << 7)
#define BCSR_UCC1_MODE_MSK (0x3 << 4)
#define BCSR_UCC2_MODE_MSK (0x3 << 0)
clrbits8(&bcsr_regs[8], BCSR_UCC1_GETH_EN);
clrbits8(&bcsr_regs[9], BCSR_UCC2_GETH_EN);
clrbits8(&bcsr_regs[11], BCSR_UCC1_MODE_MSK |
BCSR_UCC2_MODE_MSK);
setbits8(&bcsr_regs[8], BCSR_UCC1_GETH_EN);
setbits8(&bcsr_regs[9], BCSR_UCC2_GETH_EN);
} else if (machine_is(mpc8569_mds)) {
#define BCSR7_UCC12_GETHnRST (0x1 << 2)
#define BCSR8_UEM_MARVELL_RST (0x1 << 1)
#define BCSR_UCC_RGMII (0x1 << 6)
#define BCSR_UCC_RTBI (0x1 << 5)
clrbits8(&bcsr_regs[7], BCSR7_UCC12_GETHnRST);
setbits8(&bcsr_regs[8], BCSR8_UEM_MARVELL_RST);
setbits8(&bcsr_regs[7], BCSR7_UCC12_GETHnRST);
clrbits8(&bcsr_regs[8], BCSR8_UEM_MARVELL_RST);
for (np = NULL; (np = of_find_compatible_node(np,
"network",
"ucc_geth")) != NULL;) {
const unsigned int *prop;
int ucc_num;
prop = of_get_property(np, "cell-index", NULL);
if (prop == NULL)
continue;
ucc_num = *prop - 1;
prop = of_get_property(np, "phy-connection-type", NULL);
if (prop == NULL)
continue;
if (strcmp("rtbi", (const char *)prop) == 0)
clrsetbits_8(&bcsr_regs[7 + ucc_num],
BCSR_UCC_RGMII, BCSR_UCC_RTBI);
}
} else if (machine_is(p1021_mds)) {
#define BCSR11_ENET_MICRST (0x1 << 5)
clrbits8(&bcsr_regs[11], BCSR11_ENET_MICRST);
setbits8(&bcsr_regs[11], BCSR11_ENET_MICRST);
}
iounmap(bcsr_regs);
}
static void __init mpc85xx_mds_qe_init(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "fsl,qe");
if (!np) {
np = of_find_node_by_name(NULL, "qe");
if (!np)
return;
}
if (!of_device_is_available(np)) {
of_node_put(np);
return;
}
qe_reset();
of_node_put(np);
np = of_find_node_by_name(NULL, "par_io");
if (np) {
struct device_node *ucc;
par_io_init(np);
of_node_put(np);
for_each_node_by_name(ucc, "ucc")
par_io_of_config(ucc);
}
mpc85xx_mds_reset_ucc_phys();
if (machine_is(p1021_mds)) {
struct ccsr_guts __iomem *guts;
np = of_find_node_by_name(NULL, "global-utilities");
if (np) {
guts = of_iomap(np, 0);
if (!guts)
pr_err("mpc85xx-rdb: could not map global utilities register\n");
else{
setbits32(&guts->pmuxcr, MPC85xx_PMUXCR_QE(0) |
MPC85xx_PMUXCR_QE(3) |
MPC85xx_PMUXCR_QE(9) |
MPC85xx_PMUXCR_QE(12));
iounmap(guts);
}
of_node_put(np);
}
}
}
static void __init mpc85xx_mds_qeic_init(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "fsl,qe");
if (!of_device_is_available(np)) {
of_node_put(np);
return;
}
np = of_find_compatible_node(NULL, NULL, "fsl,qe-ic");
if (!np) {
np = of_find_node_by_type(NULL, "qeic");
if (!np)
return;
}
if (machine_is(p1021_mds))
qe_ic_init(np, 0, qe_ic_cascade_low_mpic,
qe_ic_cascade_high_mpic);
else
qe_ic_init(np, 0, qe_ic_cascade_muxed_mpic, NULL);
of_node_put(np);
}
static void __init mpc85xx_mds_qe_init(void) { }
static void __init mpc85xx_mds_qeic_init(void) { }
static void __init mpc85xx_mds_setup_arch(void)
{
#ifdef CONFIG_PCI
struct pci_controller *hose;
struct device_node *np;
#endif
dma_addr_t max = 0xffffffff;
if (ppc_md.progress)
ppc_md.progress("mpc85xx_mds_setup_arch()", 0);
#ifdef CONFIG_PCI
for_each_node_by_type(np, "pci") {
if (of_device_is_compatible(np, "fsl,mpc8540-pci") ||
of_device_is_compatible(np, "fsl,mpc8548-pcie")) {
struct resource rsrc;
of_address_to_resource(np, 0, &rsrc);
if ((rsrc.start & 0xfffff) == 0x8000)
fsl_add_bridge(np, 1);
else
fsl_add_bridge(np, 0);
hose = pci_find_hose_for_OF_device(np);
max = min(max, hose->dma_window_base_cur +
hose->dma_window_size);
}
}
#endif
mpc85xx_smp_init();
mpc85xx_mds_qe_init();
#ifdef CONFIG_SWIOTLB
if (memblock_end_of_DRAM() > max) {
ppc_swiotlb_enable = 1;
set_pci_dma_ops(&swiotlb_dma_ops);
ppc_md.pci_dma_dev_setup = pci_dma_dev_setup_swiotlb;
}
#endif
}
static int __init board_fixups(void)
{
char phy_id[20];
char *compstrs[2] = {"fsl,gianfar-mdio", "fsl,ucc-mdio"};
struct device_node *mdio;
struct resource res;
int i;
for (i = 0; i < ARRAY_SIZE(compstrs); i++) {
mdio = of_find_compatible_node(NULL, NULL, compstrs[i]);
of_address_to_resource(mdio, 0, &res);
snprintf(phy_id, sizeof(phy_id), "%llx:%02x",
(unsigned long long)res.start, 1);
phy_register_fixup_for_id(phy_id, mpc8568_fixup_125_clock);
phy_register_fixup_for_id(phy_id, mpc8568_mds_phy_fixups);
snprintf(phy_id, sizeof(phy_id), "%llx:%02x",
(unsigned long long)res.start, 7);
phy_register_fixup_for_id(phy_id, mpc8568_mds_phy_fixups);
of_node_put(mdio);
}
return 0;
}
static int __init mpc85xx_publish_devices(void)
{
if (machine_is(mpc8568_mds))
simple_gpiochip_init("fsl,mpc8568mds-bcsr-gpio");
if (machine_is(mpc8569_mds))
simple_gpiochip_init("fsl,mpc8569mds-bcsr-gpio");
return mpc85xx_common_publish_devices();
}
static void __init mpc85xx_mds_pic_init(void)
{
struct mpic *mpic = mpic_alloc(NULL, 0, MPIC_BIG_ENDIAN |
MPIC_SINGLE_DEST_CPU,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
mpic_init(mpic);
mpc85xx_mds_qeic_init();
}
static int __init mpc85xx_mds_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "MPC85xxMDS");
}
static int __init mpc8569_mds_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "fsl,MPC8569EMDS");
}
static int __init p1021_mds_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "fsl,P1021MDS");
}
