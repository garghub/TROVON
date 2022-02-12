static void sata_clear_glue_reg(uint64_t regbase, uint32_t off, uint32_t bit)
{
uint32_t reg_val;
reg_val = nlm_read_sata_reg(regbase, off);
nlm_write_sata_reg(regbase, off, (reg_val & ~bit));
}
static void sata_set_glue_reg(uint64_t regbase, uint32_t off, uint32_t bit)
{
uint32_t reg_val;
reg_val = nlm_read_sata_reg(regbase, off);
nlm_write_sata_reg(regbase, off, (reg_val | bit));
}
static void nlm_sata_firmware_init(int node)
{
uint32_t reg_val;
uint64_t regbase;
int i;
pr_info("XLP AHCI Initialization started.\n");
regbase = nlm_get_sata_regbase(node);
sata_clear_glue_reg(regbase, SATA_CTL, SATA_RST_N);
sata_clear_glue_reg(regbase, SATA_CTL,
(PHY3_RESET_N | PHY2_RESET_N
| PHY1_RESET_N | PHY0_RESET_N));
sata_set_glue_reg(regbase, SATA_CTL, SATA_RST_N);
sata_set_glue_reg(regbase, SATA_CTL,
(PHY3_RESET_N | PHY2_RESET_N
| PHY1_RESET_N | PHY0_RESET_N));
pr_debug("Waiting for PHYs to come up.\n");
i = 0;
do {
reg_val = nlm_read_sata_reg(regbase, SATA_STATUS);
i++;
} while (((reg_val & 0xF0) != 0xF0) && (i < 10000));
for (i = 0; i < 4; i++) {
if (reg_val & (P0_PHY_READY << i))
pr_info("PHY%d is up.\n", i);
else
pr_info("PHY%d is down.\n", i);
}
pr_info("XLP AHCI init done.\n");
}
static int __init nlm_ahci_init(void)
{
int node = 0;
int chip = read_c0_prid() & PRID_IMP_MASK;
if (chip == PRID_IMP_NETLOGIC_XLP3XX)
nlm_sata_firmware_init(node);
return 0;
}
static void nlm_sata_intr_ack(struct irq_data *data)
{
uint32_t val = 0;
uint64_t regbase;
regbase = nlm_get_sata_regbase(nlm_nodeid());
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
uint32_t val;
uint64_t regbase;
int node = 0;
regbase = nlm_get_sata_regbase(node);
val = nlm_read_sata_reg(regbase, SATA_INT);
sata_set_glue_reg(regbase, SATA_INT, val);
sata_set_glue_reg(regbase, SATA_INT_MASK, 0x1);
dev->irq = PIC_SATA_IRQ;
nlm_set_pic_extra_ack(node, PIC_SATA_IRQ, nlm_sata_intr_ack);
}
