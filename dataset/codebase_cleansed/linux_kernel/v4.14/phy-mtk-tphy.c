static void hs_slew_rate_calibrate(struct mtk_tphy *tphy,
struct mtk_phy_instance *instance)
{
struct u2phy_banks *u2_banks = &instance->u2_banks;
void __iomem *fmreg = u2_banks->fmreg;
void __iomem *com = u2_banks->com;
int calibration_val;
int fm_out;
u32 tmp;
tmp = readl(com + U3P_USBPHYACR5);
tmp |= PA5_RG_U2_HSTX_SRCAL_EN;
writel(tmp, com + U3P_USBPHYACR5);
udelay(1);
tmp = readl(fmreg + U3P_U2FREQ_FMMONR1);
tmp |= P2F_RG_FRCK_EN;
writel(tmp, fmreg + U3P_U2FREQ_FMMONR1);
tmp = readl(fmreg + U3P_U2FREQ_FMCR0);
tmp &= ~(P2F_RG_CYCLECNT | P2F_RG_MONCLK_SEL);
tmp |= P2F_RG_CYCLECNT_VAL(U3P_FM_DET_CYCLE_CNT);
if (tphy->pdata->version == MTK_PHY_V1)
tmp |= P2F_RG_MONCLK_SEL_VAL(instance->index >> 1);
writel(tmp, fmreg + U3P_U2FREQ_FMCR0);
tmp = readl(fmreg + U3P_U2FREQ_FMCR0);
tmp |= P2F_RG_FREQDET_EN;
writel(tmp, fmreg + U3P_U2FREQ_FMCR0);
readl_poll_timeout(fmreg + U3P_U2FREQ_FMMONR1, tmp,
(tmp & P2F_USB_FM_VALID), 10, 200);
fm_out = readl(fmreg + U3P_U2FREQ_VALUE);
tmp = readl(fmreg + U3P_U2FREQ_FMCR0);
tmp &= ~P2F_RG_FREQDET_EN;
writel(tmp, fmreg + U3P_U2FREQ_FMCR0);
tmp = readl(fmreg + U3P_U2FREQ_FMMONR1);
tmp &= ~P2F_RG_FRCK_EN;
writel(tmp, fmreg + U3P_U2FREQ_FMMONR1);
if (fm_out) {
tmp = U3P_FM_DET_CYCLE_CNT * U3P_REF_CLK * U3P_SLEW_RATE_COEF;
tmp /= fm_out;
calibration_val = DIV_ROUND_CLOSEST(tmp, U3P_SR_COEF_DIVISOR);
} else {
calibration_val = 4;
}
dev_dbg(tphy->dev, "phy:%d, fm_out:%d, calib:%d\n",
instance->index, fm_out, calibration_val);
tmp = readl(com + U3P_USBPHYACR5);
tmp &= ~PA5_RG_U2_HSTX_SRCTRL;
tmp |= PA5_RG_U2_HSTX_SRCTRL_VAL(calibration_val);
writel(tmp, com + U3P_USBPHYACR5);
tmp = readl(com + U3P_USBPHYACR5);
tmp &= ~PA5_RG_U2_HSTX_SRCAL_EN;
writel(tmp, com + U3P_USBPHYACR5);
}
static void u3_phy_instance_init(struct mtk_tphy *tphy,
struct mtk_phy_instance *instance)
{
struct u3phy_banks *u3_banks = &instance->u3_banks;
u32 tmp;
tmp = readl(u3_banks->spllc + U3P_SPLLC_XTALCTL3);
tmp |= XC3_RG_U3_XTAL_RX_PWD | XC3_RG_U3_FRC_XTAL_RX_PWD;
writel(tmp, u3_banks->spllc + U3P_SPLLC_XTALCTL3);
tmp = readl(u3_banks->phya + U3P_U3_PHYA_DA_REG0);
tmp &= ~P3A_RG_XTAL_EXT_EN_U3;
tmp |= P3A_RG_XTAL_EXT_EN_U3_VAL(2);
writel(tmp, u3_banks->phya + U3P_U3_PHYA_DA_REG0);
tmp = readl(u3_banks->phya + U3P_U3_PHYA_REG9);
tmp &= ~P3A_RG_RX_DAC_MUX;
tmp |= P3A_RG_RX_DAC_MUX_VAL(4);
writel(tmp, u3_banks->phya + U3P_U3_PHYA_REG9);
tmp = readl(u3_banks->phya + U3P_U3_PHYA_REG6);
tmp &= ~P3A_RG_TX_EIDLE_CM;
tmp |= P3A_RG_TX_EIDLE_CM_VAL(0xe);
writel(tmp, u3_banks->phya + U3P_U3_PHYA_REG6);
tmp = readl(u3_banks->phyd + U3P_U3_PHYD_CDR1);
tmp &= ~(P3D_RG_CDR_BIR_LTD0 | P3D_RG_CDR_BIR_LTD1);
tmp |= P3D_RG_CDR_BIR_LTD0_VAL(0xc) | P3D_RG_CDR_BIR_LTD1_VAL(0x3);
writel(tmp, u3_banks->phyd + U3P_U3_PHYD_CDR1);
tmp = readl(u3_banks->phyd + U3P_U3_PHYD_LFPS1);
tmp &= ~P3D_RG_FWAKE_TH;
tmp |= P3D_RG_FWAKE_TH_VAL(0x34);
writel(tmp, u3_banks->phyd + U3P_U3_PHYD_LFPS1);
tmp = readl(u3_banks->phyd + U3P_U3_PHYD_RXDET1);
tmp &= ~P3D_RG_RXDET_STB2_SET;
tmp |= P3D_RG_RXDET_STB2_SET_VAL(0x10);
writel(tmp, u3_banks->phyd + U3P_U3_PHYD_RXDET1);
tmp = readl(u3_banks->phyd + U3P_U3_PHYD_RXDET2);
tmp &= ~P3D_RG_RXDET_STB2_SET_P3;
tmp |= P3D_RG_RXDET_STB2_SET_P3_VAL(0x10);
writel(tmp, u3_banks->phyd + U3P_U3_PHYD_RXDET2);
dev_dbg(tphy->dev, "%s(%d)\n", __func__, instance->index);
}
static void u2_phy_instance_init(struct mtk_tphy *tphy,
struct mtk_phy_instance *instance)
{
struct u2phy_banks *u2_banks = &instance->u2_banks;
void __iomem *com = u2_banks->com;
u32 index = instance->index;
u32 tmp;
tmp = readl(com + U3P_U2PHYDTM0);
tmp &= ~P2C_FORCE_UART_EN;
tmp |= P2C_RG_XCVRSEL_VAL(1) | P2C_RG_DATAIN_VAL(0);
writel(tmp, com + U3P_U2PHYDTM0);
tmp = readl(com + U3P_U2PHYDTM1);
tmp &= ~P2C_RG_UART_EN;
writel(tmp, com + U3P_U2PHYDTM1);
tmp = readl(com + U3P_USBPHYACR0);
tmp |= PA0_RG_USB20_INTR_EN;
writel(tmp, com + U3P_USBPHYACR0);
tmp = readl(com + U3P_USBPHYACR5);
tmp &= ~PA5_RG_U2_HS_100U_U3_EN;
writel(tmp, com + U3P_USBPHYACR5);
if (!index) {
tmp = readl(com + U3P_U2PHYACR4);
tmp &= ~P2C_U2_GPIO_CTR_MSK;
writel(tmp, com + U3P_U2PHYACR4);
}
if (tphy->pdata->avoid_rx_sen_degradation) {
if (!index) {
tmp = readl(com + U3P_USBPHYACR2);
tmp |= PA2_RG_SIF_U2PLL_FORCE_EN;
writel(tmp, com + U3P_USBPHYACR2);
tmp = readl(com + U3D_U2PHYDCR0);
tmp &= ~P2C_RG_SIF_U2PLL_FORCE_ON;
writel(tmp, com + U3D_U2PHYDCR0);
} else {
tmp = readl(com + U3D_U2PHYDCR0);
tmp |= P2C_RG_SIF_U2PLL_FORCE_ON;
writel(tmp, com + U3D_U2PHYDCR0);
tmp = readl(com + U3P_U2PHYDTM0);
tmp |= P2C_RG_SUSPENDM | P2C_FORCE_SUSPENDM;
writel(tmp, com + U3P_U2PHYDTM0);
}
}
tmp = readl(com + U3P_USBPHYACR6);
tmp &= ~PA6_RG_U2_BC11_SW_EN;
tmp &= ~PA6_RG_U2_SQTH;
tmp |= PA6_RG_U2_SQTH_VAL(2);
writel(tmp, com + U3P_USBPHYACR6);
dev_dbg(tphy->dev, "%s(%d)\n", __func__, index);
}
static void u2_phy_instance_power_on(struct mtk_tphy *tphy,
struct mtk_phy_instance *instance)
{
struct u2phy_banks *u2_banks = &instance->u2_banks;
void __iomem *com = u2_banks->com;
u32 index = instance->index;
u32 tmp;
tmp = readl(com + U3P_U2PHYDTM0);
tmp &= ~(P2C_FORCE_SUSPENDM | P2C_RG_XCVRSEL);
tmp &= ~(P2C_RG_DATAIN | P2C_DTM0_PART_MASK);
writel(tmp, com + U3P_U2PHYDTM0);
tmp = readl(com + U3P_USBPHYACR6);
tmp |= PA6_RG_U2_OTG_VBUSCMP_EN;
writel(tmp, com + U3P_USBPHYACR6);
tmp = readl(com + U3P_U2PHYDTM1);
tmp |= P2C_RG_VBUSVALID | P2C_RG_AVALID;
tmp &= ~P2C_RG_SESSEND;
writel(tmp, com + U3P_U2PHYDTM1);
if (tphy->pdata->avoid_rx_sen_degradation && index) {
tmp = readl(com + U3D_U2PHYDCR0);
tmp |= P2C_RG_SIF_U2PLL_FORCE_ON;
writel(tmp, com + U3D_U2PHYDCR0);
tmp = readl(com + U3P_U2PHYDTM0);
tmp |= P2C_RG_SUSPENDM | P2C_FORCE_SUSPENDM;
writel(tmp, com + U3P_U2PHYDTM0);
}
dev_dbg(tphy->dev, "%s(%d)\n", __func__, index);
}
static void u2_phy_instance_power_off(struct mtk_tphy *tphy,
struct mtk_phy_instance *instance)
{
struct u2phy_banks *u2_banks = &instance->u2_banks;
void __iomem *com = u2_banks->com;
u32 index = instance->index;
u32 tmp;
tmp = readl(com + U3P_U2PHYDTM0);
tmp &= ~(P2C_RG_XCVRSEL | P2C_RG_DATAIN);
tmp |= P2C_FORCE_SUSPENDM;
writel(tmp, com + U3P_U2PHYDTM0);
tmp = readl(com + U3P_USBPHYACR6);
tmp &= ~PA6_RG_U2_OTG_VBUSCMP_EN;
writel(tmp, com + U3P_USBPHYACR6);
tmp = readl(com + U3P_U2PHYDTM0);
tmp &= ~P2C_RG_SUSPENDM;
writel(tmp, com + U3P_U2PHYDTM0);
udelay(1);
tmp = readl(com + U3P_U2PHYDTM1);
tmp &= ~(P2C_RG_VBUSVALID | P2C_RG_AVALID);
tmp |= P2C_RG_SESSEND;
writel(tmp, com + U3P_U2PHYDTM1);
if (tphy->pdata->avoid_rx_sen_degradation && index) {
tmp = readl(com + U3D_U2PHYDCR0);
tmp &= ~P2C_RG_SIF_U2PLL_FORCE_ON;
writel(tmp, com + U3D_U2PHYDCR0);
}
dev_dbg(tphy->dev, "%s(%d)\n", __func__, index);
}
static void u2_phy_instance_exit(struct mtk_tphy *tphy,
struct mtk_phy_instance *instance)
{
struct u2phy_banks *u2_banks = &instance->u2_banks;
void __iomem *com = u2_banks->com;
u32 index = instance->index;
u32 tmp;
if (tphy->pdata->avoid_rx_sen_degradation && index) {
tmp = readl(com + U3D_U2PHYDCR0);
tmp &= ~P2C_RG_SIF_U2PLL_FORCE_ON;
writel(tmp, com + U3D_U2PHYDCR0);
tmp = readl(com + U3P_U2PHYDTM0);
tmp &= ~P2C_FORCE_SUSPENDM;
writel(tmp, com + U3P_U2PHYDTM0);
}
}
static void pcie_phy_instance_init(struct mtk_tphy *tphy,
struct mtk_phy_instance *instance)
{
struct u3phy_banks *u3_banks = &instance->u3_banks;
u32 tmp;
if (tphy->pdata->version != MTK_PHY_V1)
return;
tmp = readl(u3_banks->phya + U3P_U3_PHYA_DA_REG0);
tmp &= ~(P3A_RG_XTAL_EXT_PE1H | P3A_RG_XTAL_EXT_PE2H);
tmp |= P3A_RG_XTAL_EXT_PE1H_VAL(0x2) | P3A_RG_XTAL_EXT_PE2H_VAL(0x2);
writel(tmp, u3_banks->phya + U3P_U3_PHYA_DA_REG0);
tmp = readl(u3_banks->phya + U3P_U3_PHYA_REG1);
tmp &= ~P3A_RG_CLKDRV_AMP;
tmp |= P3A_RG_CLKDRV_AMP_VAL(0x4);
writel(tmp, u3_banks->phya + U3P_U3_PHYA_REG1);
tmp = readl(u3_banks->phya + U3P_U3_PHYA_REG0);
tmp &= ~P3A_RG_CLKDRV_OFF;
tmp |= P3A_RG_CLKDRV_OFF_VAL(0x1);
writel(tmp, u3_banks->phya + U3P_U3_PHYA_REG0);
tmp = readl(u3_banks->phya + U3P_U3_PHYA_DA_REG20);
tmp &= ~P3A_RG_PLL_DELTA1_PE2H;
tmp |= P3A_RG_PLL_DELTA1_PE2H_VAL(0x3c);
writel(tmp, u3_banks->phya + U3P_U3_PHYA_DA_REG20);
tmp = readl(u3_banks->phya + U3P_U3_PHYA_DA_REG25);
tmp &= ~P3A_RG_PLL_DELTA_PE2H;
tmp |= P3A_RG_PLL_DELTA_PE2H_VAL(0x36);
writel(tmp, u3_banks->phya + U3P_U3_PHYA_DA_REG25);
tmp = readl(u3_banks->phya + U3P_U3_PHYA_DA_REG5);
tmp &= ~(P3A_RG_PLL_BR_PE2H | P3A_RG_PLL_IC_PE2H);
tmp |= P3A_RG_PLL_BR_PE2H_VAL(0x1) | P3A_RG_PLL_IC_PE2H_VAL(0x1);
writel(tmp, u3_banks->phya + U3P_U3_PHYA_DA_REG5);
tmp = readl(u3_banks->phya + U3P_U3_PHYA_DA_REG4);
tmp &= ~(P3A_RG_PLL_DIVEN_PE2H | P3A_RG_PLL_BC_PE2H);
tmp |= P3A_RG_PLL_BC_PE2H_VAL(0x3);
writel(tmp, u3_banks->phya + U3P_U3_PHYA_DA_REG4);
tmp = readl(u3_banks->phya + U3P_U3_PHYA_DA_REG6);
tmp &= ~P3A_RG_PLL_IR_PE2H;
tmp |= P3A_RG_PLL_IR_PE2H_VAL(0x2);
writel(tmp, u3_banks->phya + U3P_U3_PHYA_DA_REG6);
tmp = readl(u3_banks->phya + U3P_U3_PHYA_DA_REG7);
tmp &= ~P3A_RG_PLL_BP_PE2H;
tmp |= P3A_RG_PLL_BP_PE2H_VAL(0xa);
writel(tmp, u3_banks->phya + U3P_U3_PHYA_DA_REG7);
tmp = readl(u3_banks->phyd + U3P_U3_PHYD_RXDET1);
tmp &= ~P3D_RG_RXDET_STB2_SET;
tmp |= P3D_RG_RXDET_STB2_SET_VAL(0x10);
writel(tmp, u3_banks->phyd + U3P_U3_PHYD_RXDET1);
tmp = readl(u3_banks->phyd + U3P_U3_PHYD_RXDET2);
tmp &= ~P3D_RG_RXDET_STB2_SET_P3;
tmp |= P3D_RG_RXDET_STB2_SET_P3_VAL(0x10);
writel(tmp, u3_banks->phyd + U3P_U3_PHYD_RXDET2);
usleep_range(2500, 3000);
dev_dbg(tphy->dev, "%s(%d)\n", __func__, instance->index);
}
static void pcie_phy_instance_power_on(struct mtk_tphy *tphy,
struct mtk_phy_instance *instance)
{
struct u3phy_banks *bank = &instance->u3_banks;
u32 tmp;
tmp = readl(bank->chip + U3P_U3_CHIP_GPIO_CTLD);
tmp &= ~(P3C_FORCE_IP_SW_RST | P3C_MCU_BUS_CK_GATE_EN |
P3C_REG_IP_SW_RST);
writel(tmp, bank->chip + U3P_U3_CHIP_GPIO_CTLD);
tmp = readl(bank->chip + U3P_U3_CHIP_GPIO_CTLE);
tmp &= ~(P3C_RG_SWRST_U3_PHYD_FORCE_EN | P3C_RG_SWRST_U3_PHYD);
writel(tmp, bank->chip + U3P_U3_CHIP_GPIO_CTLE);
}
static void pcie_phy_instance_power_off(struct mtk_tphy *tphy,
struct mtk_phy_instance *instance)
{
struct u3phy_banks *bank = &instance->u3_banks;
u32 tmp;
tmp = readl(bank->chip + U3P_U3_CHIP_GPIO_CTLD);
tmp |= P3C_FORCE_IP_SW_RST | P3C_REG_IP_SW_RST;
writel(tmp, bank->chip + U3P_U3_CHIP_GPIO_CTLD);
tmp = readl(bank->chip + U3P_U3_CHIP_GPIO_CTLE);
tmp |= P3C_RG_SWRST_U3_PHYD_FORCE_EN | P3C_RG_SWRST_U3_PHYD;
writel(tmp, bank->chip + U3P_U3_CHIP_GPIO_CTLE);
}
static void sata_phy_instance_init(struct mtk_tphy *tphy,
struct mtk_phy_instance *instance)
{
struct u3phy_banks *u3_banks = &instance->u3_banks;
void __iomem *phyd = u3_banks->phyd;
u32 tmp;
tmp = readl(phyd + ANA_RG_CTRL_SIGNAL6);
tmp &= ~(RG_CDR_BIRLTR_GEN1_MSK | RG_CDR_BC_GEN1_MSK);
tmp |= RG_CDR_BIRLTR_GEN1_VAL(0x6) | RG_CDR_BC_GEN1_VAL(0x1a);
writel(tmp, phyd + ANA_RG_CTRL_SIGNAL6);
tmp = readl(phyd + ANA_EQ_EYE_CTRL_SIGNAL4);
tmp &= ~RG_CDR_BIRLTD0_GEN1_MSK;
tmp |= RG_CDR_BIRLTD0_GEN1_VAL(0x18);
writel(tmp, phyd + ANA_EQ_EYE_CTRL_SIGNAL4);
tmp = readl(phyd + ANA_EQ_EYE_CTRL_SIGNAL5);
tmp &= ~RG_CDR_BIRLTD0_GEN3_MSK;
tmp |= RG_CDR_BIRLTD0_GEN3_VAL(0x06);
writel(tmp, phyd + ANA_EQ_EYE_CTRL_SIGNAL5);
tmp = readl(phyd + ANA_RG_CTRL_SIGNAL4);
tmp &= ~(RG_CDR_BICLTR_GEN1_MSK | RG_CDR_BR_GEN2_MSK);
tmp |= RG_CDR_BICLTR_GEN1_VAL(0x0c) | RG_CDR_BR_GEN2_VAL(0x07);
writel(tmp, phyd + ANA_RG_CTRL_SIGNAL4);
tmp = readl(phyd + PHYD_CTRL_SIGNAL_MODE4);
tmp &= ~(RG_CDR_BICLTD0_GEN1_MSK | RG_CDR_BICLTD1_GEN1_MSK);
tmp |= RG_CDR_BICLTD0_GEN1_VAL(0x08) | RG_CDR_BICLTD1_GEN1_VAL(0x02);
writel(tmp, phyd + PHYD_CTRL_SIGNAL_MODE4);
tmp = readl(phyd + PHYD_DESIGN_OPTION2);
tmp &= ~RG_LOCK_CNT_SEL_MSK;
tmp |= RG_LOCK_CNT_SEL_VAL(0x02);
writel(tmp, phyd + PHYD_DESIGN_OPTION2);
tmp = readl(phyd + PHYD_DESIGN_OPTION9);
tmp &= ~(RG_T2_MIN_MSK | RG_TG_MIN_MSK |
RG_T2_MAX_MSK | RG_TG_MAX_MSK);
tmp |= RG_T2_MIN_VAL(0x12) | RG_TG_MIN_VAL(0x04) |
RG_T2_MAX_VAL(0x31) | RG_TG_MAX_VAL(0x0e);
writel(tmp, phyd + PHYD_DESIGN_OPTION9);
tmp = readl(phyd + ANA_RG_CTRL_SIGNAL1);
tmp &= ~RG_IDRV_0DB_GEN1_MSK;
tmp |= RG_IDRV_0DB_GEN1_VAL(0x20);
writel(tmp, phyd + ANA_RG_CTRL_SIGNAL1);
tmp = readl(phyd + ANA_EQ_EYE_CTRL_SIGNAL1);
tmp &= ~RG_EQ_DLEQ_LFI_GEN1_MSK;
tmp |= RG_EQ_DLEQ_LFI_GEN1_VAL(0x03);
writel(tmp, phyd + ANA_EQ_EYE_CTRL_SIGNAL1);
dev_dbg(tphy->dev, "%s(%d)\n", __func__, instance->index);
}
static void phy_v1_banks_init(struct mtk_tphy *tphy,
struct mtk_phy_instance *instance)
{
struct u2phy_banks *u2_banks = &instance->u2_banks;
struct u3phy_banks *u3_banks = &instance->u3_banks;
switch (instance->type) {
case PHY_TYPE_USB2:
u2_banks->misc = NULL;
u2_banks->fmreg = tphy->sif_base + SSUSB_SIFSLV_V1_U2FREQ;
u2_banks->com = instance->port_base + SSUSB_SIFSLV_V1_U2PHY_COM;
break;
case PHY_TYPE_USB3:
case PHY_TYPE_PCIE:
u3_banks->spllc = tphy->sif_base + SSUSB_SIFSLV_V1_SPLLC;
u3_banks->chip = tphy->sif_base + SSUSB_SIFSLV_V1_CHIP;
u3_banks->phyd = instance->port_base + SSUSB_SIFSLV_V1_U3PHYD;
u3_banks->phya = instance->port_base + SSUSB_SIFSLV_V1_U3PHYA;
break;
case PHY_TYPE_SATA:
u3_banks->phyd = instance->port_base + SSUSB_SIFSLV_V1_U3PHYD;
break;
default:
dev_err(tphy->dev, "incompatible PHY type\n");
return;
}
}
static void phy_v2_banks_init(struct mtk_tphy *tphy,
struct mtk_phy_instance *instance)
{
struct u2phy_banks *u2_banks = &instance->u2_banks;
struct u3phy_banks *u3_banks = &instance->u3_banks;
switch (instance->type) {
case PHY_TYPE_USB2:
u2_banks->misc = instance->port_base + SSUSB_SIFSLV_V2_MISC;
u2_banks->fmreg = instance->port_base + SSUSB_SIFSLV_V2_U2FREQ;
u2_banks->com = instance->port_base + SSUSB_SIFSLV_V2_U2PHY_COM;
break;
case PHY_TYPE_USB3:
case PHY_TYPE_PCIE:
u3_banks->spllc = instance->port_base + SSUSB_SIFSLV_V2_SPLLC;
u3_banks->chip = instance->port_base + SSUSB_SIFSLV_V2_CHIP;
u3_banks->phyd = instance->port_base + SSUSB_SIFSLV_V2_U3PHYD;
u3_banks->phya = instance->port_base + SSUSB_SIFSLV_V2_U3PHYA;
break;
default:
dev_err(tphy->dev, "incompatible PHY type\n");
return;
}
}
static int mtk_phy_init(struct phy *phy)
{
struct mtk_phy_instance *instance = phy_get_drvdata(phy);
struct mtk_tphy *tphy = dev_get_drvdata(phy->dev.parent);
int ret;
ret = clk_prepare_enable(tphy->u3phya_ref);
if (ret) {
dev_err(tphy->dev, "failed to enable u3phya_ref\n");
return ret;
}
ret = clk_prepare_enable(instance->ref_clk);
if (ret) {
dev_err(tphy->dev, "failed to enable ref_clk\n");
return ret;
}
switch (instance->type) {
case PHY_TYPE_USB2:
u2_phy_instance_init(tphy, instance);
break;
case PHY_TYPE_USB3:
u3_phy_instance_init(tphy, instance);
break;
case PHY_TYPE_PCIE:
pcie_phy_instance_init(tphy, instance);
break;
case PHY_TYPE_SATA:
sata_phy_instance_init(tphy, instance);
break;
default:
dev_err(tphy->dev, "incompatible PHY type\n");
return -EINVAL;
}
return 0;
}
static int mtk_phy_power_on(struct phy *phy)
{
struct mtk_phy_instance *instance = phy_get_drvdata(phy);
struct mtk_tphy *tphy = dev_get_drvdata(phy->dev.parent);
if (instance->type == PHY_TYPE_USB2) {
u2_phy_instance_power_on(tphy, instance);
hs_slew_rate_calibrate(tphy, instance);
} else if (instance->type == PHY_TYPE_PCIE) {
pcie_phy_instance_power_on(tphy, instance);
}
return 0;
}
static int mtk_phy_power_off(struct phy *phy)
{
struct mtk_phy_instance *instance = phy_get_drvdata(phy);
struct mtk_tphy *tphy = dev_get_drvdata(phy->dev.parent);
if (instance->type == PHY_TYPE_USB2)
u2_phy_instance_power_off(tphy, instance);
else if (instance->type == PHY_TYPE_PCIE)
pcie_phy_instance_power_off(tphy, instance);
return 0;
}
static int mtk_phy_exit(struct phy *phy)
{
struct mtk_phy_instance *instance = phy_get_drvdata(phy);
struct mtk_tphy *tphy = dev_get_drvdata(phy->dev.parent);
if (instance->type == PHY_TYPE_USB2)
u2_phy_instance_exit(tphy, instance);
clk_disable_unprepare(instance->ref_clk);
clk_disable_unprepare(tphy->u3phya_ref);
return 0;
}
static struct phy *mtk_phy_xlate(struct device *dev,
struct of_phandle_args *args)
{
struct mtk_tphy *tphy = dev_get_drvdata(dev);
struct mtk_phy_instance *instance = NULL;
struct device_node *phy_np = args->np;
int index;
if (args->args_count != 1) {
dev_err(dev, "invalid number of cells in 'phy' property\n");
return ERR_PTR(-EINVAL);
}
for (index = 0; index < tphy->nphys; index++)
if (phy_np == tphy->phys[index]->phy->dev.of_node) {
instance = tphy->phys[index];
break;
}
if (!instance) {
dev_err(dev, "failed to find appropriate phy\n");
return ERR_PTR(-EINVAL);
}
instance->type = args->args[0];
if (!(instance->type == PHY_TYPE_USB2 ||
instance->type == PHY_TYPE_USB3 ||
instance->type == PHY_TYPE_PCIE ||
instance->type == PHY_TYPE_SATA)) {
dev_err(dev, "unsupported device type: %d\n", instance->type);
return ERR_PTR(-EINVAL);
}
if (tphy->pdata->version == MTK_PHY_V1) {
phy_v1_banks_init(tphy, instance);
} else if (tphy->pdata->version == MTK_PHY_V2) {
phy_v2_banks_init(tphy, instance);
} else {
dev_err(dev, "phy version is not supported\n");
return ERR_PTR(-EINVAL);
}
return instance->phy;
}
static int mtk_tphy_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct device_node *child_np;
struct phy_provider *provider;
struct resource *sif_res;
struct mtk_tphy *tphy;
struct resource res;
int port, retval;
match = of_match_node(mtk_tphy_id_table, pdev->dev.of_node);
if (!match)
return -EINVAL;
tphy = devm_kzalloc(dev, sizeof(*tphy), GFP_KERNEL);
if (!tphy)
return -ENOMEM;
tphy->pdata = match->data;
tphy->nphys = of_get_child_count(np);
tphy->phys = devm_kcalloc(dev, tphy->nphys,
sizeof(*tphy->phys), GFP_KERNEL);
if (!tphy->phys)
return -ENOMEM;
tphy->dev = dev;
platform_set_drvdata(pdev, tphy);
if (tphy->pdata->version == MTK_PHY_V1) {
sif_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
tphy->sif_base = devm_ioremap_resource(dev, sif_res);
if (IS_ERR(tphy->sif_base)) {
dev_err(dev, "failed to remap sif regs\n");
return PTR_ERR(tphy->sif_base);
}
}
tphy->u3phya_ref = devm_clk_get(dev, "u3phya_ref");
if (IS_ERR(tphy->u3phya_ref)) {
if (PTR_ERR(tphy->u3phya_ref) == -EPROBE_DEFER)
return -EPROBE_DEFER;
tphy->u3phya_ref = NULL;
}
port = 0;
for_each_child_of_node(np, child_np) {
struct mtk_phy_instance *instance;
struct phy *phy;
instance = devm_kzalloc(dev, sizeof(*instance), GFP_KERNEL);
if (!instance) {
retval = -ENOMEM;
goto put_child;
}
tphy->phys[port] = instance;
phy = devm_phy_create(dev, child_np, &mtk_tphy_ops);
if (IS_ERR(phy)) {
dev_err(dev, "failed to create phy\n");
retval = PTR_ERR(phy);
goto put_child;
}
retval = of_address_to_resource(child_np, 0, &res);
if (retval) {
dev_err(dev, "failed to get address resource(id-%d)\n",
port);
goto put_child;
}
instance->port_base = devm_ioremap_resource(&phy->dev, &res);
if (IS_ERR(instance->port_base)) {
dev_err(dev, "failed to remap phy regs\n");
retval = PTR_ERR(instance->port_base);
goto put_child;
}
instance->phy = phy;
instance->index = port;
phy_set_drvdata(phy, instance);
port++;
if (tphy->u3phya_ref)
continue;
instance->ref_clk = devm_clk_get(&phy->dev, "ref");
if (IS_ERR(instance->ref_clk)) {
dev_err(dev, "failed to get ref_clk(id-%d)\n", port);
retval = PTR_ERR(instance->ref_clk);
goto put_child;
}
}
provider = devm_of_phy_provider_register(dev, mtk_phy_xlate);
return PTR_ERR_OR_ZERO(provider);
put_child:
of_node_put(child_np);
return retval;
}
