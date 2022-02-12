int mt2701_init_clock(struct mtk_base_afe *afe)
{
struct mt2701_afe_private *afe_priv = afe->platform_priv;
int i = 0;
for (i = 0; i < MT2701_CLOCK_NUM; i++) {
afe_priv->clocks[i] = devm_clk_get(afe->dev, aud_clks[i]);
if (IS_ERR(aud_clks[i])) {
dev_warn(afe->dev, "%s devm_clk_get %s fail\n",
__func__, aud_clks[i]);
return PTR_ERR(aud_clks[i]);
}
}
return 0;
}
int mt2701_afe_enable_clock(struct mtk_base_afe *afe)
{
int ret = 0;
ret = mt2701_turn_on_a1sys_clock(afe);
if (ret) {
dev_err(afe->dev, "%s turn_on_a1sys_clock fail %d\n",
__func__, ret);
return ret;
}
ret = mt2701_turn_on_a2sys_clock(afe);
if (ret) {
dev_err(afe->dev, "%s turn_on_a2sys_clock fail %d\n",
__func__, ret);
mt2701_turn_off_a1sys_clock(afe);
return ret;
}
ret = mt2701_turn_on_afe_clock(afe);
if (ret) {
dev_err(afe->dev, "%s turn_on_afe_clock fail %d\n",
__func__, ret);
mt2701_turn_off_a1sys_clock(afe);
mt2701_turn_off_a2sys_clock(afe);
return ret;
}
regmap_update_bits(afe->regmap, ASYS_TOP_CON,
AUDIO_TOP_CON0_A1SYS_A2SYS_ON,
AUDIO_TOP_CON0_A1SYS_A2SYS_ON);
regmap_update_bits(afe->regmap, AFE_DAC_CON0,
AFE_DAC_CON0_AFE_ON,
AFE_DAC_CON0_AFE_ON);
regmap_write(afe->regmap, PWR2_TOP_CON,
PWR2_TOP_CON_INIT_VAL);
regmap_write(afe->regmap, PWR1_ASM_CON1,
PWR1_ASM_CON1_INIT_VAL);
regmap_write(afe->regmap, PWR2_ASM_CON1,
PWR2_ASM_CON1_INIT_VAL);
return 0;
}
void mt2701_afe_disable_clock(struct mtk_base_afe *afe)
{
mt2701_turn_off_afe_clock(afe);
mt2701_turn_off_a1sys_clock(afe);
mt2701_turn_off_a2sys_clock(afe);
regmap_update_bits(afe->regmap, ASYS_TOP_CON,
AUDIO_TOP_CON0_A1SYS_A2SYS_ON, 0);
regmap_update_bits(afe->regmap, AFE_DAC_CON0,
AFE_DAC_CON0_AFE_ON, 0);
}
int mt2701_turn_on_a1sys_clock(struct mtk_base_afe *afe)
{
struct mt2701_afe_private *afe_priv = afe->platform_priv;
int ret = 0;
ret = clk_prepare_enable(afe_priv->clocks[MT2701_AUD_AUD_MUX1_SEL]);
if (ret) {
dev_err(afe->dev, "%s clk_prepare_enable %s fail %d\n",
__func__, aud_clks[MT2701_AUD_AUD_MUX1_SEL], ret);
goto A1SYS_CLK_AUD_MUX1_SEL_ERR;
}
ret = clk_set_parent(afe_priv->clocks[MT2701_AUD_AUD_MUX1_SEL],
afe_priv->clocks[MT2701_AUD_AUD1PLL_98M]);
if (ret) {
dev_err(afe->dev, "%s clk_set_parent %s-%s fail %d\n", __func__,
aud_clks[MT2701_AUD_AUD_MUX1_SEL],
aud_clks[MT2701_AUD_AUD1PLL_98M], ret);
goto A1SYS_CLK_AUD_MUX1_SEL_ERR;
}
ret = clk_prepare_enable(afe_priv->clocks[MT2701_AUD_AUD_MUX1_DIV]);
if (ret) {
dev_err(afe->dev, "%s clk_prepare_enable %s fail %d\n",
__func__,
aud_clks[MT2701_AUD_AUD_MUX1_DIV],
ret);
goto A1SYS_CLK_AUD_MUX1_DIV_ERR;
}
ret = clk_set_rate(afe_priv->clocks[MT2701_AUD_AUD_MUX1_DIV],
MT2701_AUD_AUD_MUX1_DIV_RATE);
if (ret) {
dev_err(afe->dev, "%s clk_set_parent %s-%d fail %d\n", __func__,
aud_clks[MT2701_AUD_AUD_MUX1_DIV],
MT2701_AUD_AUD_MUX1_DIV_RATE, ret);
goto A1SYS_CLK_AUD_MUX1_DIV_ERR;
}
ret = clk_prepare_enable(afe_priv->clocks[MT2701_AUD_AUD_48K_TIMING]);
if (ret) {
dev_err(afe->dev, "%s clk_prepare_enable %s fail %d\n",
__func__, aud_clks[MT2701_AUD_AUD_48K_TIMING], ret);
goto A1SYS_CLK_AUD_48K_ERR;
}
ret = clk_prepare_enable(afe_priv->clocks[MT2701_AUD_INFRA_SYS_AUDIO]);
if (ret) {
dev_err(afe->dev, "%s clk_prepare_enable %s fail %d\n",
__func__, aud_clks[MT2701_AUD_INFRA_SYS_AUDIO], ret);
goto A1SYS_CLK_INFRA_ERR;
}
return 0;
A1SYS_CLK_INFRA_ERR:
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_INFRA_SYS_AUDIO]);
A1SYS_CLK_AUD_48K_ERR:
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_AUD_48K_TIMING]);
A1SYS_CLK_AUD_MUX1_DIV_ERR:
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_AUD_MUX1_DIV]);
A1SYS_CLK_AUD_MUX1_SEL_ERR:
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_AUD_MUX1_SEL]);
return ret;
}
void mt2701_turn_off_a1sys_clock(struct mtk_base_afe *afe)
{
struct mt2701_afe_private *afe_priv = afe->platform_priv;
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_INFRA_SYS_AUDIO]);
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_AUD_48K_TIMING]);
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_AUD_MUX1_DIV]);
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_AUD_MUX1_SEL]);
}
int mt2701_turn_on_a2sys_clock(struct mtk_base_afe *afe)
{
struct mt2701_afe_private *afe_priv = afe->platform_priv;
int ret = 0;
ret = clk_prepare_enable(afe_priv->clocks[MT2701_AUD_AUD_MUX2_SEL]);
if (ret) {
dev_err(afe->dev, "%s clk_prepare_enable %s fail %d\n",
__func__, aud_clks[MT2701_AUD_AUD_MUX2_SEL], ret);
goto A2SYS_CLK_AUD_MUX2_SEL_ERR;
}
ret = clk_set_parent(afe_priv->clocks[MT2701_AUD_AUD_MUX2_SEL],
afe_priv->clocks[MT2701_AUD_AUD2PLL_90M]);
if (ret) {
dev_err(afe->dev, "%s clk_set_parent %s-%s fail %d\n", __func__,
aud_clks[MT2701_AUD_AUD_MUX2_SEL],
aud_clks[MT2701_AUD_AUD2PLL_90M], ret);
goto A2SYS_CLK_AUD_MUX2_SEL_ERR;
}
ret = clk_prepare_enable(afe_priv->clocks[MT2701_AUD_AUD_MUX2_DIV]);
if (ret) {
dev_err(afe->dev, "%s clk_prepare_enable %s fail %d\n",
__func__, aud_clks[MT2701_AUD_AUD_MUX2_DIV], ret);
goto A2SYS_CLK_AUD_MUX2_DIV_ERR;
}
ret = clk_set_rate(afe_priv->clocks[MT2701_AUD_AUD_MUX2_DIV],
MT2701_AUD_AUD_MUX2_DIV_RATE);
if (ret) {
dev_err(afe->dev, "%s clk_set_parent %s-%d fail %d\n", __func__,
aud_clks[MT2701_AUD_AUD_MUX2_DIV],
MT2701_AUD_AUD_MUX2_DIV_RATE, ret);
goto A2SYS_CLK_AUD_MUX2_DIV_ERR;
}
ret = clk_prepare_enable(afe_priv->clocks[MT2701_AUD_AUD_44K_TIMING]);
if (ret) {
dev_err(afe->dev, "%s clk_prepare_enable %s fail %d\n",
__func__, aud_clks[MT2701_AUD_AUD_44K_TIMING], ret);
goto A2SYS_CLK_AUD_44K_ERR;
}
ret = clk_prepare_enable(afe_priv->clocks[MT2701_AUD_INFRA_SYS_AUDIO]);
if (ret) {
dev_err(afe->dev, "%s clk_prepare_enable %s fail %d\n",
__func__, aud_clks[MT2701_AUD_INFRA_SYS_AUDIO], ret);
goto A2SYS_CLK_INFRA_ERR;
}
return 0;
A2SYS_CLK_INFRA_ERR:
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_INFRA_SYS_AUDIO]);
A2SYS_CLK_AUD_44K_ERR:
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_AUD_44K_TIMING]);
A2SYS_CLK_AUD_MUX2_DIV_ERR:
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_AUD_MUX2_DIV]);
A2SYS_CLK_AUD_MUX2_SEL_ERR:
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_AUD_MUX2_SEL]);
return ret;
}
void mt2701_turn_off_a2sys_clock(struct mtk_base_afe *afe)
{
struct mt2701_afe_private *afe_priv = afe->platform_priv;
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_INFRA_SYS_AUDIO]);
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_AUD_44K_TIMING]);
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_AUD_MUX2_DIV]);
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_AUD_MUX2_SEL]);
}
int mt2701_turn_on_afe_clock(struct mtk_base_afe *afe)
{
struct mt2701_afe_private *afe_priv = afe->platform_priv;
int ret;
ret = clk_prepare_enable(afe_priv->clocks[MT2701_AUD_INFRA_SYS_AUDIO]);
if (ret) {
dev_err(afe->dev, "%s clk_prepare_enable %s fail %d\n",
__func__, aud_clks[MT2701_AUD_INFRA_SYS_AUDIO], ret);
goto AFE_AUD_INFRA_ERR;
}
ret = clk_prepare_enable(afe_priv->clocks[MT2701_AUD_AUDINTBUS]);
if (ret) {
dev_err(afe->dev, "%s clk_prepare_enable %s fail %d\n",
__func__, aud_clks[MT2701_AUD_AUDINTBUS], ret);
goto AFE_AUD_AUDINTBUS_ERR;
}
ret = clk_set_parent(afe_priv->clocks[MT2701_AUD_AUDINTBUS],
afe_priv->clocks[MT2701_AUD_SYSPLL1_D4]);
if (ret) {
dev_err(afe->dev, "%s clk_set_parent %s-%s fail %d\n", __func__,
aud_clks[MT2701_AUD_AUDINTBUS],
aud_clks[MT2701_AUD_SYSPLL1_D4], ret);
goto AFE_AUD_AUDINTBUS_ERR;
}
ret = clk_prepare_enable(afe_priv->clocks[MT2701_AUD_ASM_H_SEL]);
if (ret) {
dev_err(afe->dev, "%s clk_prepare_enable %s fail %d\n",
__func__, aud_clks[MT2701_AUD_ASM_H_SEL], ret);
goto AFE_AUD_ASM_H_ERR;
}
ret = clk_set_parent(afe_priv->clocks[MT2701_AUD_ASM_H_SEL],
afe_priv->clocks[MT2701_AUD_UNIVPLL2_D2]);
if (ret) {
dev_err(afe->dev, "%s clk_set_parent %s-%s fail %d\n", __func__,
aud_clks[MT2701_AUD_ASM_H_SEL],
aud_clks[MT2701_AUD_UNIVPLL2_D2], ret);
goto AFE_AUD_ASM_H_ERR;
}
ret = clk_prepare_enable(afe_priv->clocks[MT2701_AUD_ASM_M_SEL]);
if (ret) {
dev_err(afe->dev, "%s clk_prepare_enable %s fail %d\n",
__func__, aud_clks[MT2701_AUD_ASM_M_SEL], ret);
goto AFE_AUD_ASM_M_ERR;
}
ret = clk_set_parent(afe_priv->clocks[MT2701_AUD_ASM_M_SEL],
afe_priv->clocks[MT2701_AUD_UNIVPLL2_D4]);
if (ret) {
dev_err(afe->dev, "%s clk_set_parent %s-%s fail %d\n", __func__,
aud_clks[MT2701_AUD_ASM_M_SEL],
aud_clks[MT2701_AUD_UNIVPLL2_D4], ret);
goto AFE_AUD_ASM_M_ERR;
}
regmap_update_bits(afe->regmap, AUDIO_TOP_CON0,
AUDIO_TOP_CON0_PDN_AFE, 0);
regmap_update_bits(afe->regmap, AUDIO_TOP_CON0,
AUDIO_TOP_CON0_PDN_APLL_CK, 0);
regmap_update_bits(afe->regmap, AUDIO_TOP_CON4,
AUDIO_TOP_CON4_PDN_A1SYS, 0);
regmap_update_bits(afe->regmap, AUDIO_TOP_CON4,
AUDIO_TOP_CON4_PDN_A2SYS, 0);
regmap_update_bits(afe->regmap, AUDIO_TOP_CON4,
AUDIO_TOP_CON4_PDN_AFE_CONN, 0);
return 0;
AFE_AUD_ASM_M_ERR:
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_ASM_M_SEL]);
AFE_AUD_ASM_H_ERR:
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_ASM_H_SEL]);
AFE_AUD_AUDINTBUS_ERR:
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_AUDINTBUS]);
AFE_AUD_INFRA_ERR:
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_INFRA_SYS_AUDIO]);
return ret;
}
void mt2701_turn_off_afe_clock(struct mtk_base_afe *afe)
{
struct mt2701_afe_private *afe_priv = afe->platform_priv;
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_INFRA_SYS_AUDIO]);
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_AUDINTBUS]);
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_ASM_H_SEL]);
clk_disable_unprepare(afe_priv->clocks[MT2701_AUD_ASM_M_SEL]);
regmap_update_bits(afe->regmap, AUDIO_TOP_CON0,
AUDIO_TOP_CON0_PDN_AFE, AUDIO_TOP_CON0_PDN_AFE);
regmap_update_bits(afe->regmap, AUDIO_TOP_CON0,
AUDIO_TOP_CON0_PDN_APLL_CK,
AUDIO_TOP_CON0_PDN_APLL_CK);
regmap_update_bits(afe->regmap, AUDIO_TOP_CON4,
AUDIO_TOP_CON4_PDN_A1SYS,
AUDIO_TOP_CON4_PDN_A1SYS);
regmap_update_bits(afe->regmap, AUDIO_TOP_CON4,
AUDIO_TOP_CON4_PDN_A2SYS,
AUDIO_TOP_CON4_PDN_A2SYS);
regmap_update_bits(afe->regmap, AUDIO_TOP_CON4,
AUDIO_TOP_CON4_PDN_AFE_CONN,
AUDIO_TOP_CON4_PDN_AFE_CONN);
}
void mt2701_mclk_configuration(struct mtk_base_afe *afe, int id, int domain,
int mclk)
{
struct mt2701_afe_private *afe_priv = afe->platform_priv;
int ret;
int aud_src_div_id = MT2701_AUD_AUD_K1_SRC_DIV + id;
int aud_src_clk_id = MT2701_AUD_AUD_K1_SRC_SEL + id;
ret = clk_prepare_enable(afe_priv->clocks[aud_src_clk_id]);
if (ret)
dev_err(afe->dev, "%s clk_prepare_enable %s fail %d\n",
__func__, aud_clks[aud_src_clk_id], ret);
if (domain == 0) {
ret = clk_set_parent(afe_priv->clocks[aud_src_clk_id],
afe_priv->clocks[MT2701_AUD_AUD_MUX1_SEL]);
if (ret)
dev_err(afe->dev, "%s clk_set_parent %s-%s fail %d\n",
__func__, aud_clks[aud_src_clk_id],
aud_clks[MT2701_AUD_AUD_MUX1_SEL], ret);
} else {
ret = clk_set_parent(afe_priv->clocks[aud_src_clk_id],
afe_priv->clocks[MT2701_AUD_AUD_MUX2_SEL]);
if (ret)
dev_err(afe->dev, "%s clk_set_parent %s-%s fail %d\n",
__func__, aud_clks[aud_src_clk_id],
aud_clks[MT2701_AUD_AUD_MUX2_SEL], ret);
}
clk_disable_unprepare(afe_priv->clocks[aud_src_clk_id]);
ret = clk_prepare_enable(afe_priv->clocks[aud_src_div_id]);
if (ret)
dev_err(afe->dev, "%s clk_prepare_enable %s fail %d\n",
__func__, aud_clks[aud_src_div_id], ret);
ret = clk_set_rate(afe_priv->clocks[aud_src_div_id], mclk);
if (ret)
dev_err(afe->dev, "%s clk_set_rate %s-%d fail %d\n", __func__,
aud_clks[aud_src_div_id], mclk, ret);
clk_disable_unprepare(afe_priv->clocks[aud_src_div_id]);
}
