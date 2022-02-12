static void mvs_94xx_detect_porttype(struct mvs_info *mvi, int i)
{
u32 reg;
struct mvs_phy *phy = &mvi->phy[i];
u32 phy_status;
mvs_write_port_vsr_addr(mvi, i, VSR_PHY_MODE3);
reg = mvs_read_port_vsr_data(mvi, i);
phy_status = ((reg & 0x3f0000) >> 16) & 0xff;
phy->phy_type &= ~(PORT_TYPE_SAS | PORT_TYPE_SATA);
switch (phy_status) {
case 0x10:
phy->phy_type |= PORT_TYPE_SAS;
break;
case 0x1d:
default:
phy->phy_type |= PORT_TYPE_SATA;
break;
}
}
static void __devinit mvs_94xx_enable_xmt(struct mvs_info *mvi, int phy_id)
{
void __iomem *regs = mvi->regs;
u32 tmp;
tmp = mr32(MVS_PCS);
tmp |= 1 << (phy_id + PCS_EN_PORT_XMT_SHIFT2);
mw32(MVS_PCS, tmp);
}
static void mvs_94xx_phy_reset(struct mvs_info *mvi, u32 phy_id, int hard)
{
u32 tmp;
tmp = mvs_read_port_irq_stat(mvi, phy_id);
tmp &= ~PHYEV_RDY_CH;
mvs_write_port_irq_stat(mvi, phy_id, tmp);
if (hard) {
tmp = mvs_read_phy_ctl(mvi, phy_id);
tmp |= PHY_RST_HARD;
mvs_write_phy_ctl(mvi, phy_id, tmp);
do {
tmp = mvs_read_phy_ctl(mvi, phy_id);
} while (tmp & PHY_RST_HARD);
} else {
mvs_write_port_vsr_addr(mvi, phy_id, VSR_PHY_STAT);
tmp = mvs_read_port_vsr_data(mvi, phy_id);
tmp |= PHY_RST;
mvs_write_port_vsr_data(mvi, phy_id, tmp);
}
}
static void mvs_94xx_phy_disable(struct mvs_info *mvi, u32 phy_id)
{
u32 tmp;
mvs_write_port_vsr_addr(mvi, phy_id, VSR_PHY_MODE2);
tmp = mvs_read_port_vsr_data(mvi, phy_id);
mvs_write_port_vsr_data(mvi, phy_id, tmp | 0x00800000);
}
static void mvs_94xx_phy_enable(struct mvs_info *mvi, u32 phy_id)
{
mvs_write_port_vsr_addr(mvi, phy_id, 0x1B4);
mvs_write_port_vsr_data(mvi, phy_id, 0x8300ffc1);
mvs_write_port_vsr_addr(mvi, phy_id, 0x104);
mvs_write_port_vsr_data(mvi, phy_id, 0x00018080);
mvs_write_port_vsr_addr(mvi, phy_id, VSR_PHY_MODE2);
mvs_write_port_vsr_data(mvi, phy_id, 0x00207fff);
}
static int __devinit mvs_94xx_init(struct mvs_info *mvi)
{
void __iomem *regs = mvi->regs;
int i;
u32 tmp, cctl;
mvs_show_pcie_usage(mvi);
if (mvi->flags & MVF_FLAG_SOC) {
tmp = mr32(MVS_PHY_CTL);
tmp &= ~PCTL_PWR_OFF;
tmp |= PCTL_PHY_DSBL;
mw32(MVS_PHY_CTL, tmp);
}
cctl = mr32(MVS_CTL) & 0xFFFF;
if (cctl & CCTL_RST)
cctl &= ~CCTL_RST;
else
mw32_f(MVS_CTL, cctl | CCTL_RST);
if (mvi->flags & MVF_FLAG_SOC) {
tmp = mr32(MVS_PHY_CTL);
tmp &= ~PCTL_PWR_OFF;
tmp |= PCTL_COM_ON;
tmp &= ~PCTL_PHY_DSBL;
tmp |= PCTL_LINK_RST;
mw32(MVS_PHY_CTL, tmp);
msleep(100);
tmp &= ~PCTL_LINK_RST;
mw32(MVS_PHY_CTL, tmp);
msleep(100);
}
mw32(MVS_PCS, 0);
mw32(MVS_STP_REG_SET_0, 0);
mw32(MVS_STP_REG_SET_1, 0);
mvs_phy_hacks(mvi);
mw32(MVS_PORTS_IMP, 0xFF);
mw32(MVS_PA_VSR_ADDR, 0x00000104);
mw32(MVS_PA_VSR_PORT, 0x00018080);
mw32(MVS_PA_VSR_ADDR, VSR_PHY_MODE8);
mw32(MVS_PA_VSR_PORT, 0x0084ffff);
mw32(MVS_PA_VSR_ADDR, 0x00000030);
tmp = mr32(MVS_PA_VSR_PORT);
tmp &= 0xFFFF00FF;
tmp |= 0x00003300;
mw32(MVS_PA_VSR_PORT, tmp);
mw32(MVS_CMD_LIST_LO, mvi->slot_dma);
mw32(MVS_CMD_LIST_HI, (mvi->slot_dma >> 16) >> 16);
mw32(MVS_RX_FIS_LO, mvi->rx_fis_dma);
mw32(MVS_RX_FIS_HI, (mvi->rx_fis_dma >> 16) >> 16);
mw32(MVS_TX_CFG, MVS_CHIP_SLOT_SZ);
mw32(MVS_TX_LO, mvi->tx_dma);
mw32(MVS_TX_HI, (mvi->tx_dma >> 16) >> 16);
mw32(MVS_RX_CFG, MVS_RX_RING_SZ);
mw32(MVS_RX_LO, mvi->rx_dma);
mw32(MVS_RX_HI, (mvi->rx_dma >> 16) >> 16);
for (i = 0; i < mvi->chip->n_phy; i++) {
mvs_94xx_phy_disable(mvi, i);
mvs_set_sas_addr(mvi, i, CONFIG_ID_FRAME3, CONFIG_ID_FRAME4,
(mvi->phy[i].dev_sas_addr));
mvs_94xx_enable_xmt(mvi, i);
mvs_94xx_phy_enable(mvi, i);
mvs_94xx_phy_reset(mvi, i, 1);
msleep(500);
mvs_94xx_detect_porttype(mvi, i);
}
if (mvi->flags & MVF_FLAG_SOC) {
writel(0x0E008000, regs + 0x000);
writel(0x59000008, regs + 0x004);
writel(0x20, regs + 0x008);
writel(0x20, regs + 0x00c);
writel(0x20, regs + 0x010);
writel(0x20, regs + 0x014);
writel(0x20, regs + 0x018);
writel(0x20, regs + 0x01c);
}
for (i = 0; i < mvi->chip->n_phy; i++) {
tmp = mvs_read_port_irq_stat(mvi, i);
tmp &= ~PHYEV_SIG_FIS;
mvs_write_port_irq_stat(mvi, i, tmp);
tmp = PHYEV_RDY_CH | PHYEV_BROAD_CH |
PHYEV_ID_DONE | PHYEV_DCDR_ERR | PHYEV_CRC_ERR ;
mvs_write_port_irq_mask(mvi, i, tmp);
msleep(100);
mvs_update_phyinfo(mvi, i, 1);
}
cctl = mr32(MVS_CTL);
cctl |= CCTL_ENDIAN_CMD;
cctl |= CCTL_ENDIAN_DATA;
cctl &= ~CCTL_ENDIAN_OPEN;
cctl |= CCTL_ENDIAN_RSP;
mw32_f(MVS_CTL, cctl);
tmp = mr32(MVS_PCS);
tmp |= PCS_CMD_RST;
mw32(MVS_PCS, tmp);
tmp = 0;
mw32(MVS_INT_COAL, tmp);
tmp = 0x100;
mw32(MVS_INT_COAL_TMOUT, tmp);
mw32(MVS_TX_CFG, 0);
mw32(MVS_TX_CFG, MVS_CHIP_SLOT_SZ | TX_EN);
mw32(MVS_RX_CFG, MVS_RX_RING_SZ | RX_EN);
mw32(MVS_PCS, PCS_SATA_RETRY_2 | PCS_FIS_RX_EN |
PCS_CMD_EN | PCS_CMD_STOP_ERR);
tmp = (CINT_PORT_MASK | CINT_DONE | CINT_MEM | CINT_SRS | CINT_CI_STOP |
CINT_DMA_PCIE);
tmp |= CINT_PHY_MASK;
mw32(MVS_INT_MASK, tmp);
mw32(MVS_INT_MASK_SRS_0, 0xFFFF);
return 0;
}
static int mvs_94xx_ioremap(struct mvs_info *mvi)
{
if (!mvs_ioremap(mvi, 2, -1)) {
mvi->regs_ex = mvi->regs + 0x10200;
mvi->regs += 0x20000;
if (mvi->id == 1)
mvi->regs += 0x4000;
return 0;
}
return -1;
}
static void mvs_94xx_iounmap(struct mvs_info *mvi)
{
if (mvi->regs) {
mvi->regs -= 0x20000;
if (mvi->id == 1)
mvi->regs -= 0x4000;
mvs_iounmap(mvi->regs);
}
}
static void mvs_94xx_interrupt_enable(struct mvs_info *mvi)
{
void __iomem *regs = mvi->regs_ex;
u32 tmp;
tmp = mr32(MVS_GBL_CTL);
tmp |= (IRQ_SAS_A | IRQ_SAS_B);
mw32(MVS_GBL_INT_STAT, tmp);
writel(tmp, regs + 0x0C);
writel(tmp, regs + 0x10);
writel(tmp, regs + 0x14);
writel(tmp, regs + 0x18);
mw32(MVS_GBL_CTL, tmp);
}
static void mvs_94xx_interrupt_disable(struct mvs_info *mvi)
{
void __iomem *regs = mvi->regs_ex;
u32 tmp;
tmp = mr32(MVS_GBL_CTL);
tmp &= ~(IRQ_SAS_A | IRQ_SAS_B);
mw32(MVS_GBL_INT_STAT, tmp);
writel(tmp, regs + 0x0C);
writel(tmp, regs + 0x10);
writel(tmp, regs + 0x14);
writel(tmp, regs + 0x18);
mw32(MVS_GBL_CTL, tmp);
}
static u32 mvs_94xx_isr_status(struct mvs_info *mvi, int irq)
{
void __iomem *regs = mvi->regs_ex;
u32 stat = 0;
if (!(mvi->flags & MVF_FLAG_SOC)) {
stat = mr32(MVS_GBL_INT_STAT);
if (!(stat & (IRQ_SAS_A | IRQ_SAS_B)))
return 0;
}
return stat;
}
static irqreturn_t mvs_94xx_isr(struct mvs_info *mvi, int irq, u32 stat)
{
void __iomem *regs = mvi->regs;
if (((stat & IRQ_SAS_A) && mvi->id == 0) ||
((stat & IRQ_SAS_B) && mvi->id == 1)) {
mw32_f(MVS_INT_STAT, CINT_DONE);
#ifndef MVS_USE_TASKLET
spin_lock(&mvi->lock);
#endif
mvs_int_full(mvi);
#ifndef MVS_USE_TASKLET
spin_unlock(&mvi->lock);
#endif
}
return IRQ_HANDLED;
}
static void mvs_94xx_command_active(struct mvs_info *mvi, u32 slot_idx)
{
u32 tmp;
mvs_cw32(mvi, 0x300 + (slot_idx >> 3), 1 << (slot_idx % 32));
do {
tmp = mvs_cr32(mvi, 0x300 + (slot_idx >> 3));
} while (tmp & 1 << (slot_idx % 32));
}
static void mvs_94xx_issue_stop(struct mvs_info *mvi, enum mvs_port_type type,
u32 tfs)
{
void __iomem *regs = mvi->regs;
u32 tmp;
if (type == PORT_TYPE_SATA) {
tmp = mr32(MVS_INT_STAT_SRS_0) | (1U << tfs);
mw32(MVS_INT_STAT_SRS_0, tmp);
}
mw32(MVS_INT_STAT, CINT_CI_STOP);
tmp = mr32(MVS_PCS) | 0xFF00;
mw32(MVS_PCS, tmp);
}
static void mvs_94xx_free_reg_set(struct mvs_info *mvi, u8 *tfs)
{
void __iomem *regs = mvi->regs;
u32 tmp;
u8 reg_set = *tfs;
if (*tfs == MVS_ID_NOT_MAPPED)
return;
mvi->sata_reg_set &= ~bit(reg_set);
if (reg_set < 32) {
w_reg_set_enable(reg_set, (u32)mvi->sata_reg_set);
tmp = mr32(MVS_INT_STAT_SRS_0) & (u32)mvi->sata_reg_set;
if (tmp)
mw32(MVS_INT_STAT_SRS_0, tmp);
} else {
w_reg_set_enable(reg_set, mvi->sata_reg_set);
tmp = mr32(MVS_INT_STAT_SRS_1) & mvi->sata_reg_set;
if (tmp)
mw32(MVS_INT_STAT_SRS_1, tmp);
}
*tfs = MVS_ID_NOT_MAPPED;
return;
}
static u8 mvs_94xx_assign_reg_set(struct mvs_info *mvi, u8 *tfs)
{
int i;
void __iomem *regs = mvi->regs;
if (*tfs != MVS_ID_NOT_MAPPED)
return 0;
i = mv_ffc64(mvi->sata_reg_set);
if (i > 32) {
mvi->sata_reg_set |= bit(i);
w_reg_set_enable(i, (u32)(mvi->sata_reg_set >> 32));
*tfs = i;
return 0;
} else if (i >= 0) {
mvi->sata_reg_set |= bit(i);
w_reg_set_enable(i, (u32)mvi->sata_reg_set);
*tfs = i;
return 0;
}
return MVS_ID_NOT_MAPPED;
}
static void mvs_94xx_make_prd(struct scatterlist *scatter, int nr, void *prd)
{
int i;
struct scatterlist *sg;
struct mvs_prd *buf_prd = prd;
for_each_sg(scatter, sg, nr, i) {
buf_prd->addr = cpu_to_le64(sg_dma_address(sg));
buf_prd->im_len.len = cpu_to_le32(sg_dma_len(sg));
buf_prd++;
}
}
static int mvs_94xx_oob_done(struct mvs_info *mvi, int i)
{
u32 phy_st;
phy_st = mvs_read_phy_ctl(mvi, i);
if (phy_st & PHY_READY_MASK)
return 1;
return 0;
}
static void mvs_94xx_get_dev_identify_frame(struct mvs_info *mvi, int port_id,
struct sas_identify_frame *id)
{
int i;
u32 id_frame[7];
for (i = 0; i < 7; i++) {
mvs_write_port_cfg_addr(mvi, port_id,
CONFIG_ID_FRAME0 + i * 4);
id_frame[i] = mvs_read_port_cfg_data(mvi, port_id);
}
memcpy(id, id_frame, 28);
}
static void mvs_94xx_get_att_identify_frame(struct mvs_info *mvi, int port_id,
struct sas_identify_frame *id)
{
int i;
u32 id_frame[7];
for (i = 0; i < 7; i++) {
mvs_write_port_cfg_addr(mvi, port_id,
CONFIG_ATT_ID_FRAME0 + i * 4);
id_frame[i] = mvs_read_port_cfg_data(mvi, port_id);
mv_dprintk("94xx phy %d atta frame %d %x.\n",
port_id + mvi->id * mvi->chip->n_phy, i, id_frame[i]);
}
memcpy(id, id_frame, 28);
}
static u32 mvs_94xx_make_dev_info(struct sas_identify_frame *id)
{
u32 att_dev_info = 0;
att_dev_info |= id->dev_type;
if (id->stp_iport)
att_dev_info |= PORT_DEV_STP_INIT;
if (id->smp_iport)
att_dev_info |= PORT_DEV_SMP_INIT;
if (id->ssp_iport)
att_dev_info |= PORT_DEV_SSP_INIT;
if (id->stp_tport)
att_dev_info |= PORT_DEV_STP_TRGT;
if (id->smp_tport)
att_dev_info |= PORT_DEV_SMP_TRGT;
if (id->ssp_tport)
att_dev_info |= PORT_DEV_SSP_TRGT;
att_dev_info |= (u32)id->phy_id<<24;
return att_dev_info;
}
static u32 mvs_94xx_make_att_info(struct sas_identify_frame *id)
{
return mvs_94xx_make_dev_info(id);
}
static void mvs_94xx_fix_phy_info(struct mvs_info *mvi, int i,
struct sas_identify_frame *id)
{
struct mvs_phy *phy = &mvi->phy[i];
struct asd_sas_phy *sas_phy = &phy->sas_phy;
mv_dprintk("get all reg link rate is 0x%x\n", phy->phy_status);
sas_phy->linkrate =
(phy->phy_status & PHY_NEG_SPP_PHYS_LINK_RATE_MASK) >>
PHY_NEG_SPP_PHYS_LINK_RATE_MASK_OFFSET;
sas_phy->linkrate += 0x8;
mv_dprintk("get link rate is %d\n", sas_phy->linkrate);
phy->minimum_linkrate = SAS_LINK_RATE_1_5_GBPS;
phy->maximum_linkrate = SAS_LINK_RATE_6_0_GBPS;
mvs_94xx_get_dev_identify_frame(mvi, i, id);
phy->dev_info = mvs_94xx_make_dev_info(id);
if (phy->phy_type & PORT_TYPE_SAS) {
mvs_94xx_get_att_identify_frame(mvi, i, id);
phy->att_dev_info = mvs_94xx_make_att_info(id);
phy->att_dev_sas_addr = *(u64 *)id->sas_addr;
} else {
phy->att_dev_info = PORT_DEV_STP_TRGT | 1;
}
}
void mvs_94xx_phy_set_link_rate(struct mvs_info *mvi, u32 phy_id,
struct sas_phy_linkrates *rates)
{
}
static void mvs_94xx_clear_active_cmds(struct mvs_info *mvi)
{
u32 tmp;
void __iomem *regs = mvi->regs;
tmp = mr32(MVS_STP_REG_SET_0);
mw32(MVS_STP_REG_SET_0, 0);
mw32(MVS_STP_REG_SET_0, tmp);
tmp = mr32(MVS_STP_REG_SET_1);
mw32(MVS_STP_REG_SET_1, 0);
mw32(MVS_STP_REG_SET_1, tmp);
}
u32 mvs_94xx_spi_read_data(struct mvs_info *mvi)
{
void __iomem *regs = mvi->regs_ex - 0x10200;
return mr32(SPI_RD_DATA_REG_94XX);
}
void mvs_94xx_spi_write_data(struct mvs_info *mvi, u32 data)
{
void __iomem *regs = mvi->regs_ex - 0x10200;
mw32(SPI_RD_DATA_REG_94XX, data);
}
int mvs_94xx_spi_buildcmd(struct mvs_info *mvi,
u32 *dwCmd,
u8 cmd,
u8 read,
u8 length,
u32 addr
)
{
void __iomem *regs = mvi->regs_ex - 0x10200;
u32 dwTmp;
dwTmp = ((u32)cmd << 8) | ((u32)length << 4);
if (read)
dwTmp |= SPI_CTRL_READ_94XX;
if (addr != MV_MAX_U32) {
mw32(SPI_ADDR_REG_94XX, (addr & 0x0003FFFFL));
dwTmp |= SPI_ADDR_VLD_94XX;
}
*dwCmd = dwTmp;
return 0;
}
int mvs_94xx_spi_issuecmd(struct mvs_info *mvi, u32 cmd)
{
void __iomem *regs = mvi->regs_ex - 0x10200;
mw32(SPI_CTRL_REG_94XX, cmd | SPI_CTRL_SpiStart_94XX);
return 0;
}
int mvs_94xx_spi_waitdataready(struct mvs_info *mvi, u32 timeout)
{
void __iomem *regs = mvi->regs_ex - 0x10200;
u32 i, dwTmp;
for (i = 0; i < timeout; i++) {
dwTmp = mr32(SPI_CTRL_REG_94XX);
if (!(dwTmp & SPI_CTRL_SpiStart_94XX))
return 0;
msleep(10);
}
return -1;
}
void mvs_94xx_fix_dma(dma_addr_t buf_dma, int buf_len, int from, void *prd)
{
int i;
struct mvs_prd *buf_prd = prd;
buf_prd += from;
for (i = 0; i < MAX_SG_ENTRY - from; i++) {
buf_prd->addr = cpu_to_le64(buf_dma);
buf_prd->im_len.len = cpu_to_le32(buf_len);
++buf_prd;
}
}
static void mvs_94xx_clear_srs_irq(struct mvs_info *mvi, u8 reg_set,
u8 clear_all)
{
}
