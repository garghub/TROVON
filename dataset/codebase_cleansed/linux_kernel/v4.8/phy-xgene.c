static void sds_wr(void __iomem *csr_base, u32 indirect_cmd_reg,
u32 indirect_data_reg, u32 addr, u32 data)
{
unsigned long deadline = jiffies + HZ;
u32 val;
u32 cmd;
cmd = CFG_IND_WR_CMD_MASK | CFG_IND_CMD_DONE_MASK;
cmd = CFG_IND_ADDR_SET(cmd, addr);
writel(data, csr_base + indirect_data_reg);
readl(csr_base + indirect_data_reg);
writel(cmd, csr_base + indirect_cmd_reg);
readl(csr_base + indirect_cmd_reg);
do {
val = readl(csr_base + indirect_cmd_reg);
} while (!(val & CFG_IND_CMD_DONE_MASK) &&
time_before(jiffies, deadline));
if (!(val & CFG_IND_CMD_DONE_MASK))
pr_err("SDS WR timeout at 0x%p offset 0x%08X value 0x%08X\n",
csr_base + indirect_cmd_reg, addr, data);
}
static void sds_rd(void __iomem *csr_base, u32 indirect_cmd_reg,
u32 indirect_data_reg, u32 addr, u32 *data)
{
unsigned long deadline = jiffies + HZ;
u32 val;
u32 cmd;
cmd = CFG_IND_RD_CMD_MASK | CFG_IND_CMD_DONE_MASK;
cmd = CFG_IND_ADDR_SET(cmd, addr);
writel(cmd, csr_base + indirect_cmd_reg);
readl(csr_base + indirect_cmd_reg);
do {
val = readl(csr_base + indirect_cmd_reg);
} while (!(val & CFG_IND_CMD_DONE_MASK) &&
time_before(jiffies, deadline));
*data = readl(csr_base + indirect_data_reg);
if (!(val & CFG_IND_CMD_DONE_MASK))
pr_err("SDS WR timeout at 0x%p offset 0x%08X value 0x%08X\n",
csr_base + indirect_cmd_reg, addr, *data);
}
static void cmu_wr(struct xgene_phy_ctx *ctx, enum cmu_type_t cmu_type,
u32 reg, u32 data)
{
void __iomem *sds_base = ctx->sds_base;
u32 val;
if (cmu_type == REF_CMU)
reg += SERDES_PLL_REF_INDIRECT_OFFSET;
else
reg += SERDES_PLL_INDIRECT_OFFSET;
sds_wr(sds_base, SATA_ENET_SDS_IND_CMD_REG,
SATA_ENET_SDS_IND_WDATA_REG, reg, data);
sds_rd(sds_base, SATA_ENET_SDS_IND_CMD_REG,
SATA_ENET_SDS_IND_RDATA_REG, reg, &val);
pr_debug("CMU WR addr 0x%X value 0x%08X <-> 0x%08X\n", reg, data, val);
}
static void cmu_rd(struct xgene_phy_ctx *ctx, enum cmu_type_t cmu_type,
u32 reg, u32 *data)
{
void __iomem *sds_base = ctx->sds_base;
if (cmu_type == REF_CMU)
reg += SERDES_PLL_REF_INDIRECT_OFFSET;
else
reg += SERDES_PLL_INDIRECT_OFFSET;
sds_rd(sds_base, SATA_ENET_SDS_IND_CMD_REG,
SATA_ENET_SDS_IND_RDATA_REG, reg, data);
pr_debug("CMU RD addr 0x%X value 0x%08X\n", reg, *data);
}
static void cmu_toggle1to0(struct xgene_phy_ctx *ctx, enum cmu_type_t cmu_type,
u32 reg, u32 bits)
{
u32 val;
cmu_rd(ctx, cmu_type, reg, &val);
val |= bits;
cmu_wr(ctx, cmu_type, reg, val);
cmu_rd(ctx, cmu_type, reg, &val);
val &= ~bits;
cmu_wr(ctx, cmu_type, reg, val);
}
static void cmu_clrbits(struct xgene_phy_ctx *ctx, enum cmu_type_t cmu_type,
u32 reg, u32 bits)
{
u32 val;
cmu_rd(ctx, cmu_type, reg, &val);
val &= ~bits;
cmu_wr(ctx, cmu_type, reg, val);
}
static void cmu_setbits(struct xgene_phy_ctx *ctx, enum cmu_type_t cmu_type,
u32 reg, u32 bits)
{
u32 val;
cmu_rd(ctx, cmu_type, reg, &val);
val |= bits;
cmu_wr(ctx, cmu_type, reg, val);
}
static void serdes_wr(struct xgene_phy_ctx *ctx, int lane, u32 reg, u32 data)
{
void __iomem *sds_base = ctx->sds_base;
u32 val;
reg += SERDES_INDIRECT_OFFSET;
reg += lane * SERDES_LANE_STRIDE;
sds_wr(sds_base, SATA_ENET_SDS_IND_CMD_REG,
SATA_ENET_SDS_IND_WDATA_REG, reg, data);
sds_rd(sds_base, SATA_ENET_SDS_IND_CMD_REG,
SATA_ENET_SDS_IND_RDATA_REG, reg, &val);
pr_debug("SERDES WR addr 0x%X value 0x%08X <-> 0x%08X\n", reg, data,
val);
}
static void serdes_rd(struct xgene_phy_ctx *ctx, int lane, u32 reg, u32 *data)
{
void __iomem *sds_base = ctx->sds_base;
reg += SERDES_INDIRECT_OFFSET;
reg += lane * SERDES_LANE_STRIDE;
sds_rd(sds_base, SATA_ENET_SDS_IND_CMD_REG,
SATA_ENET_SDS_IND_RDATA_REG, reg, data);
pr_debug("SERDES RD addr 0x%X value 0x%08X\n", reg, *data);
}
static void serdes_clrbits(struct xgene_phy_ctx *ctx, int lane, u32 reg,
u32 bits)
{
u32 val;
serdes_rd(ctx, lane, reg, &val);
val &= ~bits;
serdes_wr(ctx, lane, reg, val);
}
static void serdes_setbits(struct xgene_phy_ctx *ctx, int lane, u32 reg,
u32 bits)
{
u32 val;
serdes_rd(ctx, lane, reg, &val);
val |= bits;
serdes_wr(ctx, lane, reg, val);
}
static void xgene_phy_cfg_cmu_clk_type(struct xgene_phy_ctx *ctx,
enum cmu_type_t cmu_type,
enum clk_type_t clk_type)
{
u32 val;
cmu_rd(ctx, cmu_type, CMU_REG12, &val);
val = CMU_REG12_STATE_DELAY9_SET(val, 0x1);
cmu_wr(ctx, cmu_type, CMU_REG12, val);
cmu_wr(ctx, cmu_type, CMU_REG13, 0x0222);
cmu_wr(ctx, cmu_type, CMU_REG14, 0x2225);
if (clk_type == CLK_EXT_DIFF) {
cmu_rd(ctx, cmu_type, CMU_REG0, &val);
val = CMU_REG0_PLL_REF_SEL_SET(val, 0x0);
cmu_wr(ctx, cmu_type, CMU_REG0, val);
cmu_rd(ctx, cmu_type, CMU_REG1, &val);
val = CMU_REG1_REFCLK_CMOS_SEL_SET(val, 0x0);
cmu_wr(ctx, cmu_type, CMU_REG1, val);
dev_dbg(ctx->dev, "Set external reference clock\n");
} else if (clk_type == CLK_INT_DIFF) {
cmu_rd(ctx, cmu_type, CMU_REG0, &val);
val = CMU_REG0_PLL_REF_SEL_SET(val, 0x1);
cmu_wr(ctx, cmu_type, CMU_REG0, val);
cmu_rd(ctx, cmu_type, CMU_REG1, &val);
val = CMU_REG1_REFCLK_CMOS_SEL_SET(val, 0x1);
cmu_wr(ctx, cmu_type, CMU_REG1, val);
dev_dbg(ctx->dev, "Set internal reference clock\n");
} else if (clk_type == CLK_INT_SING) {
cmu_rd(ctx, cmu_type, CMU_REG1, &val);
val = CMU_REG1_REFCLK_CMOS_SEL_SET(val, 0x1);
cmu_wr(ctx, cmu_type, CMU_REG1, val);
cmu_rd(ctx, cmu_type, CMU_REG1, &val);
val = CMU_REG1_REFCLK_CMOS_SEL_SET(val, 0x0);
cmu_wr(ctx, cmu_type, CMU_REG1, val);
dev_dbg(ctx->dev,
"Set internal single ended reference clock\n");
}
}
static void xgene_phy_sata_cfg_cmu_core(struct xgene_phy_ctx *ctx,
enum cmu_type_t cmu_type,
enum clk_type_t clk_type)
{
u32 val;
int ref_100MHz;
if (cmu_type == REF_CMU) {
cmu_rd(ctx, cmu_type, CMU_REG34, &val);
val = CMU_REG34_VCO_CAL_VTH_LO_MAX_SET(val, 0x7);
val = CMU_REG34_VCO_CAL_VTH_HI_MAX_SET(val, 0xc);
val = CMU_REG34_VCO_CAL_VTH_LO_MIN_SET(val, 0x3);
val = CMU_REG34_VCO_CAL_VTH_HI_MIN_SET(val, 0x8);
cmu_wr(ctx, cmu_type, CMU_REG34, val);
}
cmu_rd(ctx, cmu_type, CMU_REG0, &val);
if (cmu_type == REF_CMU || preA3Chip)
val = CMU_REG0_CAL_COUNT_RESOL_SET(val, 0x4);
else
val = CMU_REG0_CAL_COUNT_RESOL_SET(val, 0x7);
cmu_wr(ctx, cmu_type, CMU_REG0, val);
cmu_rd(ctx, cmu_type, CMU_REG1, &val);
val = CMU_REG1_PLL_CP_SET(val, 0x1);
if (cmu_type == REF_CMU || preA3Chip)
val = CMU_REG1_PLL_CP_SEL_SET(val, 0x5);
else
val = CMU_REG1_PLL_CP_SEL_SET(val, 0x3);
if (cmu_type == REF_CMU)
val = CMU_REG1_PLL_MANUALCAL_SET(val, 0x0);
else
val = CMU_REG1_PLL_MANUALCAL_SET(val, 0x1);
cmu_wr(ctx, cmu_type, CMU_REG1, val);
if (cmu_type != REF_CMU)
cmu_clrbits(ctx, cmu_type, CMU_REG5, CMU_REG5_PLL_RESETB_MASK);
cmu_rd(ctx, cmu_type, CMU_REG2, &val);
if (cmu_type == REF_CMU) {
val = CMU_REG2_PLL_LFRES_SET(val, 0xa);
ref_100MHz = 1;
} else {
val = CMU_REG2_PLL_LFRES_SET(val, 0x3);
if (clk_type == CLK_EXT_DIFF)
ref_100MHz = 0;
else
ref_100MHz = 1;
}
if (ref_100MHz) {
val = CMU_REG2_PLL_FBDIV_SET(val, FBDIV_VAL_100M);
val = CMU_REG2_PLL_REFDIV_SET(val, REFDIV_VAL_100M);
} else {
val = CMU_REG2_PLL_FBDIV_SET(val, FBDIV_VAL_50M);
val = CMU_REG2_PLL_REFDIV_SET(val, REFDIV_VAL_50M);
}
cmu_wr(ctx, cmu_type, CMU_REG2, val);
cmu_rd(ctx, cmu_type, CMU_REG3, &val);
if (cmu_type == REF_CMU) {
val = CMU_REG3_VCOVARSEL_SET(val, 0x3);
val = CMU_REG3_VCO_MOMSEL_INIT_SET(val, 0x10);
} else {
val = CMU_REG3_VCOVARSEL_SET(val, 0xF);
if (preA3Chip)
val = CMU_REG3_VCO_MOMSEL_INIT_SET(val, 0x15);
else
val = CMU_REG3_VCO_MOMSEL_INIT_SET(val, 0x1a);
val = CMU_REG3_VCO_MANMOMSEL_SET(val, 0x15);
}
cmu_wr(ctx, cmu_type, CMU_REG3, val);
cmu_rd(ctx, cmu_type, CMU_REG26, &val);
val = CMU_REG26_FORCE_PLL_LOCK_SET(val, 0x0);
cmu_wr(ctx, cmu_type, CMU_REG26, val);
cmu_rd(ctx, cmu_type, CMU_REG5, &val);
val = CMU_REG5_PLL_LFSMCAP_SET(val, 0x3);
val = CMU_REG5_PLL_LFCAP_SET(val, 0x3);
if (cmu_type == REF_CMU || !preA3Chip)
val = CMU_REG5_PLL_LOCK_RESOLUTION_SET(val, 0x7);
else
val = CMU_REG5_PLL_LOCK_RESOLUTION_SET(val, 0x4);
cmu_wr(ctx, cmu_type, CMU_REG5, val);
cmu_rd(ctx, cmu_type, CMU_REG6, &val);
val = CMU_REG6_PLL_VREGTRIM_SET(val, preA3Chip ? 0x0 : 0x2);
val = CMU_REG6_MAN_PVT_CAL_SET(val, preA3Chip ? 0x1 : 0x0);
cmu_wr(ctx, cmu_type, CMU_REG6, val);
if (cmu_type == PHY_CMU) {
cmu_rd(ctx, cmu_type, CMU_REG9, &val);
val = CMU_REG9_TX_WORD_MODE_CH1_SET(val,
CMU_REG9_WORD_LEN_20BIT);
val = CMU_REG9_TX_WORD_MODE_CH0_SET(val,
CMU_REG9_WORD_LEN_20BIT);
val = CMU_REG9_PLL_POST_DIVBY2_SET(val, 0x1);
if (!preA3Chip) {
val = CMU_REG9_VBG_BYPASSB_SET(val, 0x0);
val = CMU_REG9_IGEN_BYPASS_SET(val , 0x0);
}
cmu_wr(ctx, cmu_type, CMU_REG9, val);
if (!preA3Chip) {
cmu_rd(ctx, cmu_type, CMU_REG10, &val);
val = CMU_REG10_VREG_REFSEL_SET(val, 0x1);
cmu_wr(ctx, cmu_type, CMU_REG10, val);
}
}
cmu_rd(ctx, cmu_type, CMU_REG16, &val);
val = CMU_REG16_CALIBRATION_DONE_OVERRIDE_SET(val, 0x1);
val = CMU_REG16_BYPASS_PLL_LOCK_SET(val, 0x1);
if (cmu_type == REF_CMU || preA3Chip)
val = CMU_REG16_VCOCAL_WAIT_BTW_CODE_SET(val, 0x4);
else
val = CMU_REG16_VCOCAL_WAIT_BTW_CODE_SET(val, 0x7);
cmu_wr(ctx, cmu_type, CMU_REG16, val);
cmu_rd(ctx, cmu_type, CMU_REG30, &val);
val = CMU_REG30_PCIE_MODE_SET(val, 0x0);
val = CMU_REG30_LOCK_COUNT_SET(val, 0x3);
cmu_wr(ctx, cmu_type, CMU_REG30, val);
cmu_wr(ctx, cmu_type, CMU_REG31, 0xF);
cmu_rd(ctx, cmu_type, CMU_REG32, &val);
val = CMU_REG32_PVT_CAL_WAIT_SEL_SET(val, 0x3);
if (cmu_type == REF_CMU || preA3Chip)
val = CMU_REG32_IREF_ADJ_SET(val, 0x3);
else
val = CMU_REG32_IREF_ADJ_SET(val, 0x1);
cmu_wr(ctx, cmu_type, CMU_REG32, val);
if (cmu_type != REF_CMU && preA3Chip)
cmu_wr(ctx, cmu_type, CMU_REG34, 0x8d27);
else
cmu_wr(ctx, cmu_type, CMU_REG34, 0x873c);
cmu_wr(ctx, cmu_type, CMU_REG37, 0xF00F);
}
static void xgene_phy_ssc_enable(struct xgene_phy_ctx *ctx,
enum cmu_type_t cmu_type)
{
u32 val;
cmu_rd(ctx, cmu_type, CMU_REG35, &val);
val = CMU_REG35_PLL_SSC_MOD_SET(val, 98);
cmu_wr(ctx, cmu_type, CMU_REG35, val);
cmu_rd(ctx, cmu_type, CMU_REG36, &val);
val = CMU_REG36_PLL_SSC_VSTEP_SET(val, 30);
val = CMU_REG36_PLL_SSC_EN_SET(val, 1);
val = CMU_REG36_PLL_SSC_DSMSEL_SET(val, 1);
cmu_wr(ctx, cmu_type, CMU_REG36, val);
cmu_clrbits(ctx, cmu_type, CMU_REG5, CMU_REG5_PLL_RESETB_MASK);
cmu_setbits(ctx, cmu_type, CMU_REG5, CMU_REG5_PLL_RESETB_MASK);
cmu_toggle1to0(ctx, cmu_type, CMU_REG32,
CMU_REG32_FORCE_VCOCAL_START_MASK);
}
static void xgene_phy_sata_cfg_lanes(struct xgene_phy_ctx *ctx)
{
u32 val;
u32 reg;
int i;
int lane;
for (lane = 0; lane < MAX_LANE; lane++) {
serdes_wr(ctx, lane, RXTX_REG147, 0x6);
serdes_rd(ctx, lane, RXTX_REG0, &val);
val = RXTX_REG0_CTLE_EQ_HR_SET(val, 0x10);
val = RXTX_REG0_CTLE_EQ_QR_SET(val, 0x10);
val = RXTX_REG0_CTLE_EQ_FR_SET(val, 0x10);
serdes_wr(ctx, lane, RXTX_REG0, val);
serdes_rd(ctx, lane, RXTX_REG1, &val);
val = RXTX_REG1_RXACVCM_SET(val, 0x7);
val = RXTX_REG1_CTLE_EQ_SET(val,
ctx->sata_param.txboostgain[lane * 3 +
ctx->sata_param.speed[lane]]);
serdes_wr(ctx, lane, RXTX_REG1, val);
serdes_rd(ctx, lane, RXTX_REG2, &val);
val = RXTX_REG2_VTT_ENA_SET(val, 0x1);
val = RXTX_REG2_VTT_SEL_SET(val, 0x1);
val = RXTX_REG2_TX_FIFO_ENA_SET(val, 0x1);
serdes_wr(ctx, lane, RXTX_REG2, val);
serdes_rd(ctx, lane, RXTX_REG4, &val);
val = RXTX_REG4_TX_WORD_MODE_SET(val, CMU_REG9_WORD_LEN_20BIT);
serdes_wr(ctx, lane, RXTX_REG4, val);
if (!preA3Chip) {
serdes_rd(ctx, lane, RXTX_REG1, &val);
val = RXTX_REG1_RXVREG1_SET(val, 0x2);
val = RXTX_REG1_RXIREF_ADJ_SET(val, 0x2);
serdes_wr(ctx, lane, RXTX_REG1, val);
}
serdes_rd(ctx, lane, RXTX_REG5, &val);
val = RXTX_REG5_TX_CN1_SET(val,
ctx->sata_param.txprecursor_cn1[lane * 3 +
ctx->sata_param.speed[lane]]);
val = RXTX_REG5_TX_CP1_SET(val,
ctx->sata_param.txpostcursor_cp1[lane * 3 +
ctx->sata_param.speed[lane]]);
val = RXTX_REG5_TX_CN2_SET(val,
ctx->sata_param.txprecursor_cn2[lane * 3 +
ctx->sata_param.speed[lane]]);
serdes_wr(ctx, lane, RXTX_REG5, val);
serdes_rd(ctx, lane, RXTX_REG6, &val);
val = RXTX_REG6_TXAMP_CNTL_SET(val,
ctx->sata_param.txamplitude[lane * 3 +
ctx->sata_param.speed[lane]]);
val = RXTX_REG6_TXAMP_ENA_SET(val, 0x1);
val = RXTX_REG6_TX_IDLE_SET(val, 0x0);
val = RXTX_REG6_RX_BIST_RESYNC_SET(val, 0x0);
val = RXTX_REG6_RX_BIST_ERRCNT_RD_SET(val, 0x0);
serdes_wr(ctx, lane, RXTX_REG6, val);
serdes_rd(ctx, lane, RXTX_REG7, &val);
val = RXTX_REG7_BIST_ENA_RX_SET(val, 0x0);
val = RXTX_REG7_RX_WORD_MODE_SET(val, CMU_REG9_WORD_LEN_20BIT);
serdes_wr(ctx, lane, RXTX_REG7, val);
serdes_rd(ctx, lane, RXTX_REG8, &val);
val = RXTX_REG8_CDR_LOOP_ENA_SET(val, 0x1);
val = RXTX_REG8_CDR_BYPASS_RXLOS_SET(val, 0x0);
val = RXTX_REG8_SSC_ENABLE_SET(val, 0x1);
val = RXTX_REG8_SD_DISABLE_SET(val, 0x0);
val = RXTX_REG8_SD_VREF_SET(val, 0x4);
serdes_wr(ctx, lane, RXTX_REG8, val);
serdes_rd(ctx, lane, RXTX_REG11, &val);
val = RXTX_REG11_PHASE_ADJUST_LIMIT_SET(val, 0x0);
serdes_wr(ctx, lane, RXTX_REG11, val);
serdes_rd(ctx, lane, RXTX_REG12, &val);
val = RXTX_REG12_LATCH_OFF_ENA_SET(val, 0x1);
val = RXTX_REG12_SUMOS_ENABLE_SET(val, 0x0);
val = RXTX_REG12_RX_DET_TERM_ENABLE_SET(val, 0x0);
serdes_wr(ctx, lane, RXTX_REG12, val);
serdes_rd(ctx, lane, RXTX_REG26, &val);
val = RXTX_REG26_PERIOD_ERROR_LATCH_SET(val, 0x0);
val = RXTX_REG26_BLWC_ENA_SET(val, 0x1);
serdes_wr(ctx, lane, RXTX_REG26, val);
serdes_wr(ctx, lane, RXTX_REG28, 0x0);
serdes_wr(ctx, lane, RXTX_REG31, 0x0);
serdes_rd(ctx, lane, RXTX_REG61, &val);
val = RXTX_REG61_ISCAN_INBERT_SET(val, 0x1);
val = RXTX_REG61_LOADFREQ_SHIFT_SET(val, 0x0);
val = RXTX_REG61_EYE_COUNT_WIDTH_SEL_SET(val, 0x0);
serdes_wr(ctx, lane, RXTX_REG61, val);
serdes_rd(ctx, lane, RXTX_REG62, &val);
val = RXTX_REG62_PERIOD_H1_QLATCH_SET(val, 0x0);
serdes_wr(ctx, lane, RXTX_REG62, val);
for (i = 0; i < 9; i++) {
reg = RXTX_REG81 + i * 2;
serdes_rd(ctx, lane, reg, &val);
val = RXTX_REG89_MU_TH7_SET(val, 0xe);
val = RXTX_REG89_MU_TH8_SET(val, 0xe);
val = RXTX_REG89_MU_TH9_SET(val, 0xe);
serdes_wr(ctx, lane, reg, val);
}
for (i = 0; i < 3; i++) {
reg = RXTX_REG96 + i * 2;
serdes_rd(ctx, lane, reg, &val);
val = RXTX_REG96_MU_FREQ1_SET(val, 0x10);
val = RXTX_REG96_MU_FREQ2_SET(val, 0x10);
val = RXTX_REG96_MU_FREQ3_SET(val, 0x10);
serdes_wr(ctx, lane, reg, val);
}
for (i = 0; i < 3; i++) {
reg = RXTX_REG99 + i * 2;
serdes_rd(ctx, lane, reg, &val);
val = RXTX_REG99_MU_PHASE1_SET(val, 0x7);
val = RXTX_REG99_MU_PHASE2_SET(val, 0x7);
val = RXTX_REG99_MU_PHASE3_SET(val, 0x7);
serdes_wr(ctx, lane, reg, val);
}
serdes_rd(ctx, lane, RXTX_REG102, &val);
val = RXTX_REG102_FREQLOOP_LIMIT_SET(val, 0x0);
serdes_wr(ctx, lane, RXTX_REG102, val);
serdes_wr(ctx, lane, RXTX_REG114, 0xffe0);
serdes_rd(ctx, lane, RXTX_REG125, &val);
val = RXTX_REG125_SIGN_PQ_SET(val,
ctx->sata_param.txeyedirection[lane * 3 +
ctx->sata_param.speed[lane]]);
val = RXTX_REG125_PQ_REG_SET(val,
ctx->sata_param.txeyetuning[lane * 3 +
ctx->sata_param.speed[lane]]);
val = RXTX_REG125_PHZ_MANUAL_SET(val, 0x1);
serdes_wr(ctx, lane, RXTX_REG125, val);
serdes_rd(ctx, lane, RXTX_REG127, &val);
val = RXTX_REG127_LATCH_MAN_CAL_ENA_SET(val, 0x0);
serdes_wr(ctx, lane, RXTX_REG127, val);
serdes_rd(ctx, lane, RXTX_REG128, &val);
val = RXTX_REG128_LATCH_CAL_WAIT_SEL_SET(val, 0x3);
serdes_wr(ctx, lane, RXTX_REG128, val);
serdes_rd(ctx, lane, RXTX_REG145, &val);
val = RXTX_REG145_RXDFE_CONFIG_SET(val, 0x3);
val = RXTX_REG145_TX_IDLE_SATA_SET(val, 0x0);
if (preA3Chip) {
val = RXTX_REG145_RXES_ENA_SET(val, 0x1);
val = RXTX_REG145_RXVWES_LATENA_SET(val, 0x1);
} else {
val = RXTX_REG145_RXES_ENA_SET(val, 0x0);
val = RXTX_REG145_RXVWES_LATENA_SET(val, 0x0);
}
serdes_wr(ctx, lane, RXTX_REG145, val);
for (i = 0; i < 4; i++) {
reg = RXTX_REG148 + i * 2;
serdes_wr(ctx, lane, reg, 0xFFFF);
}
}
}
static int xgene_phy_cal_rdy_chk(struct xgene_phy_ctx *ctx,
enum cmu_type_t cmu_type,
enum clk_type_t clk_type)
{
void __iomem *csr_serdes = ctx->sds_base;
int loop;
u32 val;
writel(0xdf, csr_serdes + SATA_ENET_SDS_RST_CTL);
readl(csr_serdes + SATA_ENET_SDS_RST_CTL);
if (cmu_type != REF_CMU) {
cmu_setbits(ctx, cmu_type, CMU_REG5, CMU_REG5_PLL_RESETB_MASK);
usleep_range(800, 1000);
cmu_rd(ctx, cmu_type, CMU_REG1, &val);
val = CMU_REG1_PLL_MANUALCAL_SET(val, 0x0);
cmu_wr(ctx, cmu_type, CMU_REG1, val);
usleep_range(800, 1000);
cmu_toggle1to0(ctx, cmu_type, CMU_REG32,
CMU_REG32_FORCE_VCOCAL_START_MASK);
usleep_range(800, 1000);
}
if (!preA3Chip)
goto skip_manual_cal;
cmu_rd(ctx, cmu_type, CMU_REG17, &val);
val = CMU_REG17_PVT_CODE_R2A_SET(val, 0x12);
val = CMU_REG17_RESERVED_7_SET(val, 0x0);
cmu_wr(ctx, cmu_type, CMU_REG17, val);
cmu_toggle1to0(ctx, cmu_type, CMU_REG17,
CMU_REG17_PVT_TERM_MAN_ENA_MASK);
cmu_rd(ctx, cmu_type, CMU_REG17, &val);
val = CMU_REG17_PVT_CODE_R2A_SET(val, 0x29);
val = CMU_REG17_RESERVED_7_SET(val, 0x0);
cmu_wr(ctx, cmu_type, CMU_REG17, val);
cmu_toggle1to0(ctx, cmu_type, CMU_REG16,
CMU_REG16_PVT_DN_MAN_ENA_MASK);
cmu_rd(ctx, cmu_type, CMU_REG17, &val);
val = CMU_REG17_PVT_CODE_R2A_SET(val, 0x28);
val = CMU_REG17_RESERVED_7_SET(val, 0x0);
cmu_wr(ctx, cmu_type, CMU_REG17, val);
cmu_toggle1to0(ctx, cmu_type, CMU_REG16,
CMU_REG16_PVT_UP_MAN_ENA_MASK);
skip_manual_cal:
loop = 100;
do {
cmu_rd(ctx, cmu_type, CMU_REG7, &val);
if (CMU_REG7_PLL_CALIB_DONE_RD(val))
break;
usleep_range(10, 100);
} while (--loop > 0);
cmu_rd(ctx, cmu_type, CMU_REG7, &val);
dev_dbg(ctx->dev, "PLL calibration %s\n",
CMU_REG7_PLL_CALIB_DONE_RD(val) ? "done" : "failed");
if (CMU_REG7_VCO_CAL_FAIL_RD(val)) {
dev_err(ctx->dev,
"PLL calibration failed due to VCO failure\n");
return -1;
}
dev_dbg(ctx->dev, "PLL calibration successful\n");
cmu_rd(ctx, cmu_type, CMU_REG15, &val);
dev_dbg(ctx->dev, "PHY Tx is %sready\n", val & 0x300 ? "" : "not ");
return 0;
}
static void xgene_phy_pdwn_force_vco(struct xgene_phy_ctx *ctx,
enum cmu_type_t cmu_type,
enum clk_type_t clk_type)
{
u32 val;
dev_dbg(ctx->dev, "Reset VCO and re-start again\n");
if (cmu_type == PHY_CMU) {
cmu_rd(ctx, cmu_type, CMU_REG16, &val);
val = CMU_REG16_VCOCAL_WAIT_BTW_CODE_SET(val, 0x7);
cmu_wr(ctx, cmu_type, CMU_REG16, val);
}
cmu_toggle1to0(ctx, cmu_type, CMU_REG0, CMU_REG0_PDOWN_MASK);
cmu_toggle1to0(ctx, cmu_type, CMU_REG32,
CMU_REG32_FORCE_VCOCAL_START_MASK);
}
static int xgene_phy_hw_init_sata(struct xgene_phy_ctx *ctx,
enum clk_type_t clk_type, int ssc_enable)
{
void __iomem *sds_base = ctx->sds_base;
u32 val;
int i;
dev_dbg(ctx->dev, "Reset PHY\n");
writel(0x0, sds_base + SATA_ENET_SDS_RST_CTL);
val = readl(sds_base + SATA_ENET_SDS_RST_CTL);
writel(0x20, sds_base + SATA_ENET_SDS_RST_CTL);
readl(sds_base + SATA_ENET_SDS_RST_CTL);
writel(0xde, sds_base + SATA_ENET_SDS_RST_CTL);
readl(sds_base + SATA_ENET_SDS_RST_CTL);
val = readl(sds_base + SATA_ENET_SDS_CTL1);
val = CFG_I_SPD_SEL_CDR_OVR1_SET(val,
ctx->sata_param.txspeed[ctx->sata_param.speed[0]]);
writel(val, sds_base + SATA_ENET_SDS_CTL1);
dev_dbg(ctx->dev, "Set the customer pin mode to SATA\n");
val = readl(sds_base + SATA_ENET_SDS_CTL0);
val = REGSPEC_CFG_I_CUSTOMER_PIN_MODE0_SET(val, 0x4421);
writel(val, sds_base + SATA_ENET_SDS_CTL0);
xgene_phy_cfg_cmu_clk_type(ctx, PHY_CMU, clk_type);
xgene_phy_sata_cfg_cmu_core(ctx, PHY_CMU, clk_type);
if (ssc_enable)
xgene_phy_ssc_enable(ctx, PHY_CMU);
xgene_phy_sata_cfg_lanes(ctx);
val = readl(sds_base + SATA_ENET_SDS_PCS_CTL0);
val = REGSPEC_CFG_I_RX_WORDMODE0_SET(val, 0x3);
val = REGSPEC_CFG_I_TX_WORDMODE0_SET(val, 0x3);
writel(val, sds_base + SATA_ENET_SDS_PCS_CTL0);
i = 10;
do {
if (!xgene_phy_cal_rdy_chk(ctx, PHY_CMU, clk_type))
break;
xgene_phy_pdwn_force_vco(ctx, PHY_CMU, clk_type);
} while (--i > 0);
if (i <= 0)
dev_err(ctx->dev, "PLL calibration failed\n");
return 0;
}
static int xgene_phy_hw_initialize(struct xgene_phy_ctx *ctx,
enum clk_type_t clk_type,
int ssc_enable)
{
int rc;
dev_dbg(ctx->dev, "PHY init clk type %d\n", clk_type);
if (ctx->mode == MODE_SATA) {
rc = xgene_phy_hw_init_sata(ctx, clk_type, ssc_enable);
if (rc)
return rc;
} else {
dev_err(ctx->dev, "Un-supported customer pin mode %d\n",
ctx->mode);
return -ENODEV;
}
return 0;
}
static void xgene_phy_force_lat_summer_cal(struct xgene_phy_ctx *ctx, int lane)
{
int i;
struct {
u32 reg;
u32 val;
} serdes_reg[] = {
{RXTX_REG38, 0x0},
{RXTX_REG39, 0xff00},
{RXTX_REG40, 0xffff},
{RXTX_REG41, 0xffff},
{RXTX_REG42, 0xffff},
{RXTX_REG43, 0xffff},
{RXTX_REG44, 0xffff},
{RXTX_REG45, 0xffff},
{RXTX_REG46, 0xffff},
{RXTX_REG47, 0xfffc},
{RXTX_REG48, 0x0},
{RXTX_REG49, 0x0},
{RXTX_REG50, 0x0},
{RXTX_REG51, 0x0},
{RXTX_REG52, 0x0},
{RXTX_REG53, 0x0},
{RXTX_REG54, 0x0},
{RXTX_REG55, 0x0},
};
serdes_setbits(ctx, lane, RXTX_REG127,
RXTX_REG127_FORCE_SUM_CAL_START_MASK);
usleep_range(100, 500);
serdes_clrbits(ctx, lane, RXTX_REG127,
RXTX_REG127_FORCE_SUM_CAL_START_MASK);
usleep_range(100, 500);
serdes_setbits(ctx, lane, RXTX_REG127,
RXTX_REG127_FORCE_LAT_CAL_START_MASK);
usleep_range(100, 500);
serdes_clrbits(ctx, lane, RXTX_REG127,
RXTX_REG127_FORCE_LAT_CAL_START_MASK);
serdes_wr(ctx, lane, RXTX_REG28, 0x7);
serdes_wr(ctx, lane, RXTX_REG31, 0x7e00);
serdes_clrbits(ctx, lane, RXTX_REG4,
RXTX_REG4_TX_LOOPBACK_BUF_EN_MASK);
serdes_clrbits(ctx, lane, RXTX_REG7,
RXTX_REG7_LOOP_BACK_ENA_CTLE_MASK);
for (i = 0; i < ARRAY_SIZE(serdes_reg); i++)
serdes_wr(ctx, lane, serdes_reg[i].reg,
serdes_reg[i].val);
}
static void xgene_phy_reset_rxd(struct xgene_phy_ctx *ctx, int lane)
{
serdes_clrbits(ctx, lane, RXTX_REG7, RXTX_REG7_RESETB_RXD_MASK);
usleep_range(100, 150);
serdes_setbits(ctx, lane, RXTX_REG7, RXTX_REG7_RESETB_RXD_MASK);
}
static int xgene_phy_get_avg(int accum, int samples)
{
return (accum + (samples / 2)) / samples;
}
static void xgene_phy_gen_avg_val(struct xgene_phy_ctx *ctx, int lane)
{
int max_loop = 10;
int avg_loop = 0;
int lat_do = 0, lat_xo = 0, lat_eo = 0, lat_so = 0;
int lat_de = 0, lat_xe = 0, lat_ee = 0, lat_se = 0;
int sum_cal = 0;
int lat_do_itr, lat_xo_itr, lat_eo_itr, lat_so_itr;
int lat_de_itr, lat_xe_itr, lat_ee_itr, lat_se_itr;
int sum_cal_itr;
int fail_even;
int fail_odd;
u32 val;
dev_dbg(ctx->dev, "Generating avg calibration value for lane %d\n",
lane);
serdes_setbits(ctx, lane, RXTX_REG12,
RXTX_REG12_RX_DET_TERM_ENABLE_MASK);
serdes_wr(ctx, lane, RXTX_REG28, 0x0000);
serdes_wr(ctx, lane, RXTX_REG31, 0x0000);
while (avg_loop < max_loop) {
xgene_phy_force_lat_summer_cal(ctx, lane);
serdes_rd(ctx, lane, RXTX_REG21, &val);
lat_do_itr = RXTX_REG21_DO_LATCH_CALOUT_RD(val);
lat_xo_itr = RXTX_REG21_XO_LATCH_CALOUT_RD(val);
fail_odd = RXTX_REG21_LATCH_CAL_FAIL_ODD_RD(val);
serdes_rd(ctx, lane, RXTX_REG22, &val);
lat_eo_itr = RXTX_REG22_EO_LATCH_CALOUT_RD(val);
lat_so_itr = RXTX_REG22_SO_LATCH_CALOUT_RD(val);
fail_even = RXTX_REG22_LATCH_CAL_FAIL_EVEN_RD(val);
serdes_rd(ctx, lane, RXTX_REG23, &val);
lat_de_itr = RXTX_REG23_DE_LATCH_CALOUT_RD(val);
lat_xe_itr = RXTX_REG23_XE_LATCH_CALOUT_RD(val);
serdes_rd(ctx, lane, RXTX_REG24, &val);
lat_ee_itr = RXTX_REG24_EE_LATCH_CALOUT_RD(val);
lat_se_itr = RXTX_REG24_SE_LATCH_CALOUT_RD(val);
serdes_rd(ctx, lane, RXTX_REG121, &val);
sum_cal_itr = RXTX_REG121_SUMOS_CAL_CODE_RD(val);
if ((fail_even == 0 || fail_even == 1) &&
(fail_odd == 0 || fail_odd == 1)) {
lat_do += lat_do_itr;
lat_xo += lat_xo_itr;
lat_eo += lat_eo_itr;
lat_so += lat_so_itr;
lat_de += lat_de_itr;
lat_xe += lat_xe_itr;
lat_ee += lat_ee_itr;
lat_se += lat_se_itr;
sum_cal += sum_cal_itr;
dev_dbg(ctx->dev, "Iteration %d:\n", avg_loop);
dev_dbg(ctx->dev, "DO 0x%x XO 0x%x EO 0x%x SO 0x%x\n",
lat_do_itr, lat_xo_itr, lat_eo_itr,
lat_so_itr);
dev_dbg(ctx->dev, "DE 0x%x XE 0x%x EE 0x%x SE 0x%x\n",
lat_de_itr, lat_xe_itr, lat_ee_itr,
lat_se_itr);
dev_dbg(ctx->dev, "SUM 0x%x\n", sum_cal_itr);
++avg_loop;
} else {
dev_err(ctx->dev,
"Receiver calibration failed at %d loop\n",
avg_loop);
}
xgene_phy_reset_rxd(ctx, lane);
}
serdes_rd(ctx, lane, RXTX_REG127, &val);
val = RXTX_REG127_DO_LATCH_MANCAL_SET(val,
xgene_phy_get_avg(lat_do, max_loop));
val = RXTX_REG127_XO_LATCH_MANCAL_SET(val,
xgene_phy_get_avg(lat_xo, max_loop));
serdes_wr(ctx, lane, RXTX_REG127, val);
serdes_rd(ctx, lane, RXTX_REG128, &val);
val = RXTX_REG128_EO_LATCH_MANCAL_SET(val,
xgene_phy_get_avg(lat_eo, max_loop));
val = RXTX_REG128_SO_LATCH_MANCAL_SET(val,
xgene_phy_get_avg(lat_so, max_loop));
serdes_wr(ctx, lane, RXTX_REG128, val);
serdes_rd(ctx, lane, RXTX_REG129, &val);
val = RXTX_REG129_DE_LATCH_MANCAL_SET(val,
xgene_phy_get_avg(lat_de, max_loop));
val = RXTX_REG129_XE_LATCH_MANCAL_SET(val,
xgene_phy_get_avg(lat_xe, max_loop));
serdes_wr(ctx, lane, RXTX_REG129, val);
serdes_rd(ctx, lane, RXTX_REG130, &val);
val = RXTX_REG130_EE_LATCH_MANCAL_SET(val,
xgene_phy_get_avg(lat_ee, max_loop));
val = RXTX_REG130_SE_LATCH_MANCAL_SET(val,
xgene_phy_get_avg(lat_se, max_loop));
serdes_wr(ctx, lane, RXTX_REG130, val);
serdes_rd(ctx, lane, RXTX_REG14, &val);
val = RXTX_REG14_CLTE_LATCAL_MAN_PROG_SET(val,
xgene_phy_get_avg(sum_cal, max_loop));
serdes_wr(ctx, lane, RXTX_REG14, val);
dev_dbg(ctx->dev, "Average Value:\n");
dev_dbg(ctx->dev, "DO 0x%x XO 0x%x EO 0x%x SO 0x%x\n",
xgene_phy_get_avg(lat_do, max_loop),
xgene_phy_get_avg(lat_xo, max_loop),
xgene_phy_get_avg(lat_eo, max_loop),
xgene_phy_get_avg(lat_so, max_loop));
dev_dbg(ctx->dev, "DE 0x%x XE 0x%x EE 0x%x SE 0x%x\n",
xgene_phy_get_avg(lat_de, max_loop),
xgene_phy_get_avg(lat_xe, max_loop),
xgene_phy_get_avg(lat_ee, max_loop),
xgene_phy_get_avg(lat_se, max_loop));
dev_dbg(ctx->dev, "SUM 0x%x\n",
xgene_phy_get_avg(sum_cal, max_loop));
serdes_rd(ctx, lane, RXTX_REG14, &val);
val = RXTX_REG14_CTLE_LATCAL_MAN_ENA_SET(val, 0x1);
serdes_wr(ctx, lane, RXTX_REG14, val);
dev_dbg(ctx->dev, "Enable Manual Summer calibration\n");
serdes_rd(ctx, lane, RXTX_REG127, &val);
val = RXTX_REG127_LATCH_MAN_CAL_ENA_SET(val, 0x1);
dev_dbg(ctx->dev, "Enable Manual Latch calibration\n");
serdes_wr(ctx, lane, RXTX_REG127, val);
serdes_rd(ctx, lane, RXTX_REG12, &val);
val = RXTX_REG12_RX_DET_TERM_ENABLE_SET(val, 0);
serdes_wr(ctx, lane, RXTX_REG12, val);
serdes_wr(ctx, lane, RXTX_REG28, 0x0007);
serdes_wr(ctx, lane, RXTX_REG31, 0x7e00);
}
static int xgene_phy_hw_init(struct phy *phy)
{
struct xgene_phy_ctx *ctx = phy_get_drvdata(phy);
int rc;
int i;
rc = xgene_phy_hw_initialize(ctx, CLK_EXT_DIFF, SSC_DISABLE);
if (rc) {
dev_err(ctx->dev, "PHY initialize failed %d\n", rc);
return rc;
}
if (!IS_ERR(ctx->clk)) {
clk_prepare_enable(ctx->clk);
clk_disable_unprepare(ctx->clk);
clk_prepare_enable(ctx->clk);
}
for (i = 0; i < MAX_LANE; i++)
xgene_phy_gen_avg_val(ctx, i);
dev_dbg(ctx->dev, "PHY initialized\n");
return 0;
}
static struct phy *xgene_phy_xlate(struct device *dev,
struct of_phandle_args *args)
{
struct xgene_phy_ctx *ctx = dev_get_drvdata(dev);
if (args->args_count <= 0)
return ERR_PTR(-EINVAL);
if (args->args[0] < MODE_SATA || args->args[0] >= MODE_MAX)
return ERR_PTR(-EINVAL);
ctx->mode = args->args[0];
return ctx->phy;
}
static void xgene_phy_get_param(struct platform_device *pdev,
const char *name, u32 *buffer,
int count, u32 *default_val,
u32 conv_factor)
{
int i;
if (!of_property_read_u32_array(pdev->dev.of_node, name, buffer,
count)) {
for (i = 0; i < count; i++)
buffer[i] /= conv_factor;
return;
}
for (i = 0; i < count; i++)
buffer[i] = default_val[i % 3];
}
static int xgene_phy_probe(struct platform_device *pdev)
{
struct phy_provider *phy_provider;
struct xgene_phy_ctx *ctx;
struct resource *res;
u32 default_spd[] = DEFAULT_SATA_SPD_SEL;
u32 default_txboost_gain[] = DEFAULT_SATA_TXBOOST_GAIN;
u32 default_txeye_direction[] = DEFAULT_SATA_TXEYEDIRECTION;
u32 default_txeye_tuning[] = DEFAULT_SATA_TXEYETUNING;
u32 default_txamp[] = DEFAULT_SATA_TXAMP;
u32 default_txcn1[] = DEFAULT_SATA_TXCN1;
u32 default_txcn2[] = DEFAULT_SATA_TXCN2;
u32 default_txcp1[] = DEFAULT_SATA_TXCP1;
int i;
ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
ctx->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ctx->sds_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(ctx->sds_base))
return PTR_ERR(ctx->sds_base);
ctx->clk = clk_get(&pdev->dev, NULL);
xgene_phy_get_param(pdev, "apm,tx-eye-tuning",
ctx->sata_param.txeyetuning, 6, default_txeye_tuning, 1);
xgene_phy_get_param(pdev, "apm,tx-eye-direction",
ctx->sata_param.txeyedirection, 6, default_txeye_direction, 1);
xgene_phy_get_param(pdev, "apm,tx-boost-gain",
ctx->sata_param.txboostgain, 6, default_txboost_gain, 1);
xgene_phy_get_param(pdev, "apm,tx-amplitude",
ctx->sata_param.txamplitude, 6, default_txamp, 13300);
xgene_phy_get_param(pdev, "apm,tx-pre-cursor1",
ctx->sata_param.txprecursor_cn1, 6, default_txcn1, 18200);
xgene_phy_get_param(pdev, "apm,tx-pre-cursor2",
ctx->sata_param.txprecursor_cn2, 6, default_txcn2, 18200);
xgene_phy_get_param(pdev, "apm,tx-post-cursor",
ctx->sata_param.txpostcursor_cp1, 6, default_txcp1, 18200);
xgene_phy_get_param(pdev, "apm,tx-speed",
ctx->sata_param.txspeed, 3, default_spd, 1);
for (i = 0; i < MAX_LANE; i++)
ctx->sata_param.speed[i] = 2;
platform_set_drvdata(pdev, ctx);
ctx->phy = devm_phy_create(ctx->dev, NULL, &xgene_phy_ops);
if (IS_ERR(ctx->phy)) {
dev_dbg(&pdev->dev, "Failed to create PHY\n");
return PTR_ERR(ctx->phy);
}
phy_set_drvdata(ctx->phy, ctx);
phy_provider = devm_of_phy_provider_register(ctx->dev, xgene_phy_xlate);
return PTR_ERR_OR_ZERO(phy_provider);
}
