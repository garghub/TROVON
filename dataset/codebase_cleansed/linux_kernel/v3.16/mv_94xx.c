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
void set_phy_tuning(struct mvs_info *mvi, int phy_id,
struct phy_tuning phy_tuning)
{
u32 tmp, setting_0 = 0, setting_1 = 0;
u8 i;
if (mvi->pdev->revision == VANIR_A0_REV)
return;
for (i = 0; i < 3; i++) {
switch (i) {
case 0:
setting_0 = GENERATION_1_SETTING;
setting_1 = GENERATION_1_2_SETTING;
break;
case 1:
setting_0 = GENERATION_1_2_SETTING;
setting_1 = GENERATION_2_3_SETTING;
break;
case 2:
setting_0 = GENERATION_2_3_SETTING;
setting_1 = GENERATION_3_4_SETTING;
break;
}
mvs_write_port_vsr_addr(mvi, phy_id, setting_0);
tmp = mvs_read_port_vsr_data(mvi, phy_id);
tmp &= ~(0xFBE << 16);
tmp |= (((phy_tuning.trans_emp_en << 11) |
(phy_tuning.trans_emp_amp << 7) |
(phy_tuning.trans_amp << 1)) << 16);
mvs_write_port_vsr_data(mvi, phy_id, tmp);
mvs_write_port_vsr_addr(mvi, phy_id, setting_1);
tmp = mvs_read_port_vsr_data(mvi, phy_id);
tmp &= ~(0xC000);
tmp |= (phy_tuning.trans_amp_adj << 14);
mvs_write_port_vsr_data(mvi, phy_id, tmp);
}
}
void set_phy_ffe_tuning(struct mvs_info *mvi, int phy_id,
struct ffe_control ffe)
{
u32 tmp;
if ((mvi->pdev->revision == VANIR_A0_REV)
|| (mvi->pdev->revision == VANIR_B0_REV))
return;
mvs_write_port_vsr_addr(mvi, phy_id, VSR_PHY_FFE_CONTROL);
tmp = mvs_read_port_vsr_data(mvi, phy_id);
tmp &= ~0xFF;
tmp |= ((0x1 << 7) |
(ffe.ffe_rss_sel << 4) |
(ffe.ffe_cap_sel << 0));
mvs_write_port_vsr_data(mvi, phy_id, tmp);
mvs_write_port_vsr_addr(mvi, phy_id, VSR_REF_CLOCK_CRTL);
tmp = mvs_read_port_vsr_data(mvi, phy_id);
tmp &= ~0x40001;
tmp |= (0 << 18);
mvs_write_port_vsr_data(mvi, phy_id, tmp);
mvs_write_port_vsr_addr(mvi, phy_id, VSR_PHY_DFE_UPDATE_CRTL);
tmp = mvs_read_port_vsr_data(mvi, phy_id);
tmp &= ~0xFFF;
tmp |= ((0x3F << 6) | (0x0 << 0));
mvs_write_port_vsr_data(mvi, phy_id, tmp);
mvs_write_port_vsr_addr(mvi, phy_id, VSR_REF_CLOCK_CRTL);
tmp = mvs_read_port_vsr_data(mvi, phy_id);
tmp &= ~0x8;
tmp |= (0 << 3);
mvs_write_port_vsr_data(mvi, phy_id, tmp);
}
void set_phy_rate(struct mvs_info *mvi, int phy_id, u8 rate)
{
union reg_phy_cfg phy_cfg, phy_cfg_tmp;
mvs_write_port_vsr_addr(mvi, phy_id, VSR_PHY_MODE2);
phy_cfg_tmp.v = mvs_read_port_vsr_data(mvi, phy_id);
phy_cfg.v = 0;
phy_cfg.u.disable_phy = phy_cfg_tmp.u.disable_phy;
phy_cfg.u.sas_support = 1;
phy_cfg.u.sata_support = 1;
phy_cfg.u.sata_host_mode = 1;
switch (rate) {
case 0x0:
phy_cfg.u.speed_support = 1;
phy_cfg.u.snw_3_support = 0;
phy_cfg.u.tx_lnk_parity = 1;
phy_cfg.u.tx_spt_phs_lnk_rate = 0x30;
break;
case 0x1:
phy_cfg.u.speed_support = 3;
phy_cfg.u.tx_spt_phs_lnk_rate = 0x3c;
phy_cfg.u.tx_lgcl_lnk_rate = 0x08;
break;
case 0x2:
default:
phy_cfg.u.speed_support = 7;
phy_cfg.u.snw_3_support = 1;
phy_cfg.u.tx_lnk_parity = 1;
phy_cfg.u.tx_spt_phs_lnk_rate = 0x3f;
phy_cfg.u.tx_lgcl_lnk_rate = 0x09;
break;
}
mvs_write_port_vsr_data(mvi, phy_id, phy_cfg.v);
}
static void mvs_94xx_config_reg_from_hba(struct mvs_info *mvi, int phy_id)
{
u32 temp;
temp = (u32)(*(u32 *)&mvi->hba_info_param.phy_tuning[phy_id]);
if (temp == 0xFFFFFFFFL) {
mvi->hba_info_param.phy_tuning[phy_id].trans_emp_amp = 0x6;
mvi->hba_info_param.phy_tuning[phy_id].trans_amp = 0x1A;
mvi->hba_info_param.phy_tuning[phy_id].trans_amp_adj = 0x3;
}
temp = (u8)(*(u8 *)&mvi->hba_info_param.ffe_ctl[phy_id]);
if (temp == 0xFFL) {
switch (mvi->pdev->revision) {
case VANIR_A0_REV:
case VANIR_B0_REV:
mvi->hba_info_param.ffe_ctl[phy_id].ffe_rss_sel = 0x7;
mvi->hba_info_param.ffe_ctl[phy_id].ffe_cap_sel = 0x7;
break;
case VANIR_C0_REV:
case VANIR_C1_REV:
case VANIR_C2_REV:
default:
mvi->hba_info_param.ffe_ctl[phy_id].ffe_rss_sel = 0x7;
mvi->hba_info_param.ffe_ctl[phy_id].ffe_cap_sel = 0xC;
break;
}
}
temp = (u8)(*(u8 *)&mvi->hba_info_param.phy_rate[phy_id]);
if (temp == 0xFFL)
mvi->hba_info_param.phy_rate[phy_id] = 0x2;
set_phy_tuning(mvi, phy_id,
mvi->hba_info_param.phy_tuning[phy_id]);
set_phy_ffe_tuning(mvi, phy_id,
mvi->hba_info_param.ffe_ctl[phy_id]);
set_phy_rate(mvi, phy_id,
mvi->hba_info_param.phy_rate[phy_id]);
}
static void mvs_94xx_enable_xmt(struct mvs_info *mvi, int phy_id)
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
u32 delay = 5000;
if (hard == MVS_PHY_TUNE) {
mvs_write_port_cfg_addr(mvi, phy_id, PHYR_SATA_CTL);
tmp = mvs_read_port_cfg_data(mvi, phy_id);
mvs_write_port_cfg_data(mvi, phy_id, tmp|0x20000000);
mvs_write_port_cfg_data(mvi, phy_id, tmp|0x100000);
return;
}
tmp = mvs_read_port_irq_stat(mvi, phy_id);
tmp &= ~PHYEV_RDY_CH;
mvs_write_port_irq_stat(mvi, phy_id, tmp);
if (hard) {
tmp = mvs_read_phy_ctl(mvi, phy_id);
tmp |= PHY_RST_HARD;
mvs_write_phy_ctl(mvi, phy_id, tmp);
do {
tmp = mvs_read_phy_ctl(mvi, phy_id);
udelay(10);
delay--;
} while ((tmp & PHY_RST_HARD) && delay);
if (!delay)
mv_dprintk("phy hard reset failed.\n");
} else {
tmp = mvs_read_phy_ctl(mvi, phy_id);
tmp |= PHY_RST;
mvs_write_phy_ctl(mvi, phy_id, tmp);
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
u32 tmp;
u8 revision = 0;
revision = mvi->pdev->revision;
if (revision == VANIR_A0_REV) {
mvs_write_port_vsr_addr(mvi, phy_id, CMD_HOST_RD_DATA);
mvs_write_port_vsr_data(mvi, phy_id, 0x8300ffc1);
}
if (revision == VANIR_B0_REV) {
mvs_write_port_vsr_addr(mvi, phy_id, CMD_APP_MEM_CTL);
mvs_write_port_vsr_data(mvi, phy_id, 0x08001006);
mvs_write_port_vsr_addr(mvi, phy_id, CMD_HOST_RD_DATA);
mvs_write_port_vsr_data(mvi, phy_id, 0x0000705f);
}
mvs_write_port_vsr_addr(mvi, phy_id, VSR_PHY_MODE2);
tmp = mvs_read_port_vsr_data(mvi, phy_id);
tmp |= bit(0);
mvs_write_port_vsr_data(mvi, phy_id, tmp & 0xfd7fffff);
}
static int mvs_94xx_init(struct mvs_info *mvi)
{
void __iomem *regs = mvi->regs;
int i;
u32 tmp, cctl;
u8 revision;
revision = mvi->pdev->revision;
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
mw32(MVS_PORTS_IMP, 0xFF);
if (revision == VANIR_A0_REV) {
mw32(MVS_PA_VSR_ADDR, CMD_CMWK_OOB_DET);
mw32(MVS_PA_VSR_PORT, 0x00018080);
}
mw32(MVS_PA_VSR_ADDR, VSR_PHY_MODE2);
if (revision == VANIR_A0_REV || revision == VANIR_B0_REV)
mw32(MVS_PA_VSR_PORT, 0x0084d4fe);
else
mw32(MVS_PA_VSR_PORT, 0x0084fffe);
if (revision == VANIR_B0_REV) {
mw32(MVS_PA_VSR_ADDR, CMD_APP_MEM_CTL);
mw32(MVS_PA_VSR_PORT, 0x08001006);
mw32(MVS_PA_VSR_ADDR, CMD_HOST_RD_DATA);
mw32(MVS_PA_VSR_PORT, 0x0000705f);
}
mw32(MVS_PCS, 0);
mw32(MVS_STP_REG_SET_0, 0);
mw32(MVS_STP_REG_SET_1, 0);
mvs_phy_hacks(mvi);
tmp = mvs_cr32(mvi, CMD_SAS_CTL1);
if ((revision == VANIR_A0_REV) ||
(revision == VANIR_B0_REV) ||
(revision == VANIR_C0_REV)) {
tmp &= ~0xffff;
tmp |= 0x007f;
mvs_cw32(mvi, CMD_SAS_CTL1, tmp);
}
mw32(MVS_PA_VSR_ADDR, VSR_PHY_ACT_LED);
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
cpu_to_le64(mvi->phy[i].dev_sas_addr));
mvs_94xx_enable_xmt(mvi, i);
mvs_94xx_config_reg_from_hba(mvi, i);
mvs_94xx_phy_enable(mvi, i);
mvs_94xx_phy_reset(mvi, i, PHY_RST_HARD);
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
cctl &= ~CCTL_ENDIAN_OPEN;
cctl |= CCTL_ENDIAN_RSP;
mw32_f(MVS_CTL, cctl);
tmp = mr32(MVS_PCS);
tmp |= PCS_CMD_RST;
tmp &= ~PCS_SELF_CLEAR;
mw32(MVS_PCS, tmp);
tmp = 0;
if (MVS_CHIP_SLOT_SZ > 0x1ff)
mw32(MVS_INT_COAL, 0x1ff | COAL_EN);
else
mw32(MVS_INT_COAL, MVS_CHIP_SLOT_SZ | COAL_EN);
tmp = 0x10000 | interrupt_coalescing;
mw32(MVS_INT_COAL_TMOUT, tmp);
mw32(MVS_TX_CFG, 0);
mw32(MVS_TX_CFG, MVS_CHIP_SLOT_SZ | TX_EN);
mw32(MVS_RX_CFG, MVS_RX_RING_SZ | RX_EN);
mw32(MVS_PCS, PCS_SATA_RETRY_2 | PCS_FIS_RX_EN |
PCS_CMD_EN | PCS_CMD_STOP_ERR);
tmp = (CINT_PORT_MASK | CINT_DONE | CINT_MEM | CINT_SRS | CINT_CI_STOP |
CINT_DMA_PCIE | CINT_NON_SPEC_NCQ_ERROR);
tmp |= CINT_PHY_MASK;
mw32(MVS_INT_MASK, tmp);
tmp = mvs_cr32(mvi, CMD_LINK_TIMER);
tmp |= 0xFFFF0000;
mvs_cw32(mvi, CMD_LINK_TIMER, tmp);
tmp = 0x003F003F;
mvs_cw32(mvi, CMD_PL_TIMER, tmp);
tmp = mvs_cr32(mvi, CMD_PORT_LAYER_TIMER1);
tmp |= 0xFFFF007F;
mvs_cw32(mvi, CMD_PORT_LAYER_TIMER1, tmp);
tmp = mvs_cr32(mvi, CMD_SL_MODE0);
tmp |= 0x00000300;
tmp &= 0xFFFFFFFE;
mvs_cw32(mvi, CMD_SL_MODE0, tmp);
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
tmp |= (MVS_IRQ_SAS_A | MVS_IRQ_SAS_B);
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
tmp &= ~(MVS_IRQ_SAS_A | MVS_IRQ_SAS_B);
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
if (!(stat & (MVS_IRQ_SAS_A | MVS_IRQ_SAS_B)))
return 0;
}
return stat;
}
static irqreturn_t mvs_94xx_isr(struct mvs_info *mvi, int irq, u32 stat)
{
void __iomem *regs = mvi->regs;
if (((stat & MVS_IRQ_SAS_A) && mvi->id == 0) ||
((stat & MVS_IRQ_SAS_B) && mvi->id == 1)) {
mw32_f(MVS_INT_STAT, CINT_DONE);
spin_lock(&mvi->lock);
mvs_int_full(mvi);
spin_unlock(&mvi->lock);
}
return IRQ_HANDLED;
}
static void mvs_94xx_command_active(struct mvs_info *mvi, u32 slot_idx)
{
u32 tmp;
tmp = mvs_cr32(mvi, MVS_COMMAND_ACTIVE+(slot_idx >> 3));
if (tmp && 1 << (slot_idx % 32)) {
mv_printk("command active %08X, slot [%x].\n", tmp, slot_idx);
mvs_cw32(mvi, MVS_COMMAND_ACTIVE + (slot_idx >> 3),
1 << (slot_idx % 32));
do {
tmp = mvs_cr32(mvi,
MVS_COMMAND_ACTIVE + (slot_idx >> 3));
} while (tmp & 1 << (slot_idx % 32));
}
}
void mvs_94xx_clear_srs_irq(struct mvs_info *mvi, u8 reg_set, u8 clear_all)
{
void __iomem *regs = mvi->regs;
u32 tmp;
if (clear_all) {
tmp = mr32(MVS_INT_STAT_SRS_0);
if (tmp) {
mv_dprintk("check SRS 0 %08X.\n", tmp);
mw32(MVS_INT_STAT_SRS_0, tmp);
}
tmp = mr32(MVS_INT_STAT_SRS_1);
if (tmp) {
mv_dprintk("check SRS 1 %08X.\n", tmp);
mw32(MVS_INT_STAT_SRS_1, tmp);
}
} else {
if (reg_set > 31)
tmp = mr32(MVS_INT_STAT_SRS_1);
else
tmp = mr32(MVS_INT_STAT_SRS_0);
if (tmp & (1 << (reg_set % 32))) {
mv_dprintk("register set 0x%x was stopped.\n", reg_set);
if (reg_set > 31)
mw32(MVS_INT_STAT_SRS_1, 1 << (reg_set % 32));
else
mw32(MVS_INT_STAT_SRS_0, 1 << (reg_set % 32));
}
}
}
static void mvs_94xx_issue_stop(struct mvs_info *mvi, enum mvs_port_type type,
u32 tfs)
{
void __iomem *regs = mvi->regs;
u32 tmp;
mvs_94xx_clear_srs_irq(mvi, 0, 1);
tmp = mr32(MVS_INT_STAT);
mw32(MVS_INT_STAT, tmp | CINT_CI_STOP);
tmp = mr32(MVS_PCS) | 0xFF00;
mw32(MVS_PCS, tmp);
}
static void mvs_94xx_non_spec_ncq_error(struct mvs_info *mvi)
{
void __iomem *regs = mvi->regs;
u32 err_0, err_1;
u8 i;
struct mvs_device *device;
err_0 = mr32(MVS_NON_NCQ_ERR_0);
err_1 = mr32(MVS_NON_NCQ_ERR_1);
mv_dprintk("non specific ncq error err_0:%x,err_1:%x.\n",
err_0, err_1);
for (i = 0; i < 32; i++) {
if (err_0 & bit(i)) {
device = mvs_find_dev_by_reg_set(mvi, i);
if (device)
mvs_release_task(mvi, device->sas_device);
}
if (err_1 & bit(i)) {
device = mvs_find_dev_by_reg_set(mvi, i+32);
if (device)
mvs_release_task(mvi, device->sas_device);
}
}
mw32(MVS_NON_NCQ_ERR_0, err_0);
mw32(MVS_NON_NCQ_ERR_1, err_1);
}
static void mvs_94xx_free_reg_set(struct mvs_info *mvi, u8 *tfs)
{
void __iomem *regs = mvi->regs;
u8 reg_set = *tfs;
if (*tfs == MVS_ID_NOT_MAPPED)
return;
mvi->sata_reg_set &= ~bit(reg_set);
if (reg_set < 32)
w_reg_set_enable(reg_set, (u32)mvi->sata_reg_set);
else
w_reg_set_enable(reg_set, (u32)(mvi->sata_reg_set >> 32));
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
if (i >= 32) {
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
struct mvs_prd_imt im_len;
*(u32 *)&im_len = 0;
for_each_sg(scatter, sg, nr, i) {
buf_prd->addr = cpu_to_le64(sg_dma_address(sg));
im_len.len = sg_dma_len(sg);
buf_prd->im_len = cpu_to_le32(*(u32 *)&im_len);
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
id_frame[i] = cpu_to_le32(mvs_read_port_cfg_data(mvi, port_id));
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
id_frame[i] = cpu_to_le32(mvs_read_port_cfg_data(mvi, port_id));
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
mvs_write_port_cfg_addr(mvi, i, PHYR_PHY_STAT);
mvs_write_port_cfg_data(mvi, i, 0x04);
}
void mvs_94xx_phy_set_link_rate(struct mvs_info *mvi, u32 phy_id,
struct sas_phy_linkrates *rates)
{
u32 lrmax = 0;
u32 tmp;
tmp = mvs_read_phy_ctl(mvi, phy_id);
lrmax = (rates->maximum_linkrate - SAS_LINK_RATE_1_5_GBPS) << 12;
if (lrmax) {
tmp &= ~(0x3 << 12);
tmp |= lrmax;
}
mvs_write_phy_ctl(mvi, phy_id, tmp);
mvs_94xx_phy_reset(mvi, phy_id, PHY_RST_HARD);
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
void mvs_94xx_fix_dma(struct mvs_info *mvi, u32 phy_mask,
int buf_len, int from, void *prd)
{
int i;
struct mvs_prd *buf_prd = prd;
dma_addr_t buf_dma;
struct mvs_prd_imt im_len;
*(u32 *)&im_len = 0;
buf_prd += from;
#define PRD_CHAINED_ENTRY 0x01
if ((mvi->pdev->revision == VANIR_A0_REV) ||
(mvi->pdev->revision == VANIR_B0_REV))
buf_dma = (phy_mask <= 0x08) ?
mvi->bulk_buffer_dma : mvi->bulk_buffer_dma1;
else
return;
for (i = from; i < MAX_SG_ENTRY; i++, ++buf_prd) {
if (i == MAX_SG_ENTRY - 1) {
buf_prd->addr = cpu_to_le64(virt_to_phys(buf_prd - 1));
im_len.len = 2;
im_len.misc_ctl = PRD_CHAINED_ENTRY;
} else {
buf_prd->addr = cpu_to_le64(buf_dma);
im_len.len = buf_len;
}
buf_prd->im_len = cpu_to_le32(*(u32 *)&im_len);
}
}
static void mvs_94xx_tune_interrupt(struct mvs_info *mvi, u32 time)
{
void __iomem *regs = mvi->regs;
u32 tmp = 0;
if (time == 0) {
mw32(MVS_INT_COAL, 0);
mw32(MVS_INT_COAL_TMOUT, 0x10000);
} else {
if (MVS_CHIP_SLOT_SZ > 0x1ff)
mw32(MVS_INT_COAL, 0x1ff|COAL_EN);
else
mw32(MVS_INT_COAL, MVS_CHIP_SLOT_SZ|COAL_EN);
tmp = 0x10000 | time;
mw32(MVS_INT_COAL_TMOUT, tmp);
}
}
