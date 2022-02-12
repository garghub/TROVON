static void sata_clear_glue_reg(u64 regbase, u32 off, u32 bit)
{
u32 reg_val;
reg_val = nlm_read_sata_reg(regbase, off);
nlm_write_sata_reg(regbase, off, (reg_val & ~bit));
}
static void sata_set_glue_reg(u64 regbase, u32 off, u32 bit)
{
u32 reg_val;
reg_val = nlm_read_sata_reg(regbase, off);
nlm_write_sata_reg(regbase, off, (reg_val | bit));
}
static void write_phy_reg(u64 regbase, u32 addr, u32 physel, u8 data)
{
nlm_write_sata_reg(regbase, PHY_MEM_ACCESS,
(1u << 31) | (physel << 24) | (data << 16) | addr);
udelay(850);
}
static u8 read_phy_reg(u64 regbase, u32 addr, u32 physel)
{
u32 val;
nlm_write_sata_reg(regbase, PHY_MEM_ACCESS,
(0 << 31) | (physel << 24) | (0 << 16) | addr);
udelay(850);
val = nlm_read_sata_reg(regbase, PHY_MEM_ACCESS);
return (val >> 16) & 0xff;
}
static void config_sata_phy(u64 regbase)
{
u32 port, i, reg;
for (port = 0; port < 2; port++) {
for (i = 0, reg = RXCDRCALFOSC0; reg <= CALDUTY; reg++, i++)
write_phy_reg(regbase, reg, port, sata_phy_config1[i]);
for (i = 0, reg = RXDPIF; reg <= PPMDRIFTMAX_HI; reg++, i++)
write_phy_reg(regbase, reg, port, sata_phy_config2[i]);
}
}
static void check_phy_register(u64 regbase, u32 addr, u32 physel, u8 xdata)
{
u8 data;
data = read_phy_reg(regbase, addr, physel);
pr_info("PHY read addr = 0x%x physel = %d data = 0x%x %s\n",
addr, physel, data, data == xdata ? "TRUE" : "FALSE");
}
static void verify_sata_phy_config(u64 regbase)
{
u32 port, i, reg;
for (port = 0; port < 2; port++) {
for (i = 0, reg = RXCDRCALFOSC0; reg <= CALDUTY; reg++, i++)
check_phy_register(regbase, reg, port,
sata_phy_config1[i]);
for (i = 0, reg = RXDPIF; reg <= PPMDRIFTMAX_HI; reg++, i++)
check_phy_register(regbase, reg, port,
sata_phy_config2[i]);
}
}
static void nlm_sata_firmware_init(int node)
{
u32 reg_val;
u64 regbase;
int n;
pr_info("Initializing XLP9XX On-chip AHCI...\n");
regbase = nlm_get_sata_regbase(node);
sata_clear_glue_reg(regbase, SATA_CTL, P0_IRST_POR);
sata_clear_glue_reg(regbase, SATA_CTL, P0_IRST_HARD_TXRX);
sata_clear_glue_reg(regbase, SATA_CTL, P0_IRST_HARD_SYNTH);
sata_clear_glue_reg(regbase, SATA_CTL, P0_IPDTXL);
sata_clear_glue_reg(regbase, SATA_CTL, P0_IPDRXL);
sata_clear_glue_reg(regbase, SATA_CTL, P0_IPDIPDMSYNTH);
sata_clear_glue_reg(regbase, SATA_CTL, P1_IRST_POR);
sata_clear_glue_reg(regbase, SATA_CTL, P1_IRST_HARD_TXRX);
sata_clear_glue_reg(regbase, SATA_CTL, P1_IRST_HARD_SYNTH);
sata_clear_glue_reg(regbase, SATA_CTL, P1_IPDTXL);
sata_clear_glue_reg(regbase, SATA_CTL, P1_IPDRXL);
sata_clear_glue_reg(regbase, SATA_CTL, P1_IPDIPDMSYNTH);
udelay(300);
sata_set_glue_reg(regbase, SATA_CTL, P0_IPDTXL);
sata_set_glue_reg(regbase, SATA_CTL, P0_IPDRXL);
sata_set_glue_reg(regbase, SATA_CTL, P0_IPDIPDMSYNTH);
sata_set_glue_reg(regbase, SATA_CTL, P1_IPDTXL);
sata_set_glue_reg(regbase, SATA_CTL, P1_IPDRXL);
sata_set_glue_reg(regbase, SATA_CTL, P1_IPDIPDMSYNTH);
udelay(1000);
sata_set_glue_reg(regbase, SATA_CTL, P0_IRST_POR);
udelay(1000);
sata_set_glue_reg(regbase, SATA_CTL, P1_IRST_POR);
udelay(1000);
config_sata_phy(regbase);
if (sata_phy_debug)
verify_sata_phy_config(regbase);
udelay(1000);
sata_set_glue_reg(regbase, SATA_CTL, P0_IRST_HARD_TXRX);
sata_set_glue_reg(regbase, SATA_CTL, P0_IRST_HARD_SYNTH);
sata_set_glue_reg(regbase, SATA_CTL, P1_IRST_HARD_TXRX);
sata_set_glue_reg(regbase, SATA_CTL, P1_IRST_HARD_SYNTH);
udelay(300);
sata_set_glue_reg(regbase, CR_REG_TIMER, CR_TIME_SCALE);
sata_set_glue_reg(regbase, SATA_CTL, SATA_RST_N);
sata_set_glue_reg(regbase, SATA_CTL, M_CSYSREQ);
sata_set_glue_reg(regbase, SATA_CTL, S_CSYSREQ);
pr_debug("Waiting for PHYs to come up.\n");
n = 10000;
do {
reg_val = nlm_read_sata_reg(regbase, SATA_STATUS);
if ((reg_val & P1_PHY_READY) && (reg_val & P0_PHY_READY))
break;
udelay(10);
} while (--n > 0);
if (reg_val & P0_PHY_READY)
pr_info("PHY0 is up.\n");
else
pr_info("PHY0 is down.\n");
if (reg_val & P1_PHY_READY)
pr_info("PHY1 is up.\n");
else
pr_info("PHY1 is down.\n");
pr_info("XLP AHCI Init Done.\n");
}
static int __init nlm_ahci_init(void)
{
int node;
if (!cpu_is_xlp9xx())
return 0;
for (node = 0; node < NLM_NR_NODES; node++)
if (nlm_node_present(node))
nlm_sata_firmware_init(node);
return 0;
}
static void nlm_sata_intr_ack(struct irq_data *data)
{
u64 regbase;
u32 val;
int node;
node = data->irq / NLM_IRQS_PER_NODE;
regbase = nlm_get_sata_regbase(node);
val = nlm_read_sata_reg(regbase, SATA_INT);
sata_set_glue_reg(regbase, SATA_INT, val);
}
static void nlm_sata_fixup_bar(struct pci_dev *dev)
{
dev->resource[5] = dev->resource[0];
memset(&dev->resource[0], 0, sizeof(dev->resource[0]));
}
static void nlm_sata_fixup_final(struct pci_dev *dev)
{
u32 val;
u64 regbase;
int node;
node = xlp_socdev_to_node(dev);
regbase = nlm_get_sata_regbase(node);
val = nlm_read_sata_reg(regbase, SATA_INT);
sata_set_glue_reg(regbase, SATA_INT, val);
sata_set_glue_reg(regbase, SATA_INT_MASK, 0x1);
dev->irq = nlm_irq_to_xirq(node, PIC_SATA_IRQ);
nlm_set_pic_extra_ack(node, PIC_SATA_IRQ, nlm_sata_intr_ack);
}
