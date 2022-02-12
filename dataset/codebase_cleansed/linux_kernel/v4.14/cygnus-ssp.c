static struct cygnus_aio_port *cygnus_dai_get_portinfo(struct snd_soc_dai *dai)
{
struct cygnus_audio *cygaud = snd_soc_dai_get_drvdata(dai);
return &cygaud->portinfo[dai->id];
}
static int audio_ssp_init_portregs(struct cygnus_aio_port *aio)
{
u32 value, fci_id;
int status = 0;
switch (aio->port_type) {
case PORT_TDM:
value = readl(aio->cygaud->audio + aio->regs.i2s_stream_cfg);
value &= ~I2S_STREAM_CFG_MASK;
writel(aio->portnum,
aio->cygaud->audio + aio->regs.bf_sourcech_grp);
value |= aio->portnum << I2S_OUT_STREAM_CFG_GROUP_ID;
value |= aio->portnum;
value |= CH_GRP_STEREO << I2S_OUT_STREAM_CFG_CHANNEL_GROUPING;
writel(value, aio->cygaud->audio + aio->regs.i2s_stream_cfg);
value = readl(aio->cygaud->audio + aio->regs.bf_sourcech_cfg);
value &= ~BIT(BF_SRC_CFGX_NOT_PAUSE_WHEN_EMPTY);
value |= BIT(BF_SRC_CFGX_SFIFO_SZ_DOUBLE);
value |= BIT(BF_SRC_CFGX_PROCESS_SEQ_ID_VALID);
writel(value, aio->cygaud->audio + aio->regs.bf_sourcech_cfg);
value = readl(aio->cygaud->i2s_in +
aio->regs.i2s_cap_stream_cfg);
value &= ~I2S_CAP_STREAM_CFG_MASK;
value |= aio->portnum << I2S_IN_STREAM_CFG_0_GROUP_ID;
writel(value, aio->cygaud->i2s_in +
aio->regs.i2s_cap_stream_cfg);
fci_id = CAPTURE_FCI_ID_BASE + aio->portnum;
value = readl(aio->cygaud->audio + aio->regs.bf_destch_cfg);
value |= BIT(BF_DST_CFGX_DFIFO_SZ_DOUBLE);
value &= ~BIT(BF_DST_CFGX_NOT_PAUSE_WHEN_FULL);
value |= (fci_id << BF_DST_CFGX_FCI_ID);
value |= BIT(BF_DST_CFGX_PROC_SEQ_ID_VALID);
writel(value, aio->cygaud->audio + aio->regs.bf_destch_cfg);
value = readl(aio->cygaud->audio + AUD_MISC_SEROUT_OE_REG_BASE);
value &= ~BIT((aio->portnum * 4) + AUD_MISC_SEROUT_SDAT_OE);
writel(value, aio->cygaud->audio + AUD_MISC_SEROUT_OE_REG_BASE);
break;
case PORT_SPDIF:
writel(aio->portnum, aio->cygaud->audio + BF_SRC_GRP3_OFFSET);
value = readl(aio->cygaud->audio + SPDIF_CTRL_OFFSET);
value |= BIT(SPDIF_0_OUT_DITHER_ENA);
writel(value, aio->cygaud->audio + SPDIF_CTRL_OFFSET);
value = readl(aio->cygaud->audio + SPDIF_STREAM_CFG_OFFSET);
value &= ~SPDIF_STREAM_CFG_MASK;
value |= aio->portnum;
value |= BIT(SPDIF_0_OUT_STREAM_ENA);
writel(value, aio->cygaud->audio + SPDIF_STREAM_CFG_OFFSET);
value = readl(aio->cygaud->audio + aio->regs.bf_sourcech_cfg);
value &= ~BIT(BF_SRC_CFGX_NOT_PAUSE_WHEN_EMPTY);
value |= BIT(BF_SRC_CFGX_SFIFO_SZ_DOUBLE);
value |= BIT(BF_SRC_CFGX_PROCESS_SEQ_ID_VALID);
writel(value, aio->cygaud->audio + aio->regs.bf_sourcech_cfg);
value = readl(aio->cygaud->audio + AUD_MISC_SEROUT_OE_REG_BASE);
value &= ~BIT(AUD_MISC_SEROUT_SPDIF_OE);
writel(value, aio->cygaud->audio + AUD_MISC_SEROUT_OE_REG_BASE);
break;
default:
dev_err(aio->cygaud->dev, "Port not supported\n");
status = -EINVAL;
}
return status;
}
static void audio_ssp_in_enable(struct cygnus_aio_port *aio)
{
u32 value;
value = readl(aio->cygaud->audio + aio->regs.bf_destch_cfg);
value |= BIT(BF_DST_CFGX_CAP_ENA);
writel(value, aio->cygaud->audio + aio->regs.bf_destch_cfg);
writel(0x1, aio->cygaud->audio + aio->regs.bf_destch_ctrl);
value = readl(aio->cygaud->audio + aio->regs.i2s_cfg);
value |= BIT(I2S_OUT_CFGX_CLK_ENA);
value |= BIT(I2S_OUT_CFGX_DATA_ENABLE);
writel(value, aio->cygaud->audio + aio->regs.i2s_cfg);
value = readl(aio->cygaud->i2s_in + aio->regs.i2s_cap_stream_cfg);
value |= BIT(I2S_IN_STREAM_CFG_CAP_ENA);
writel(value, aio->cygaud->i2s_in + aio->regs.i2s_cap_stream_cfg);
aio->streams_on |= CAPTURE_STREAM_MASK;
}
static void audio_ssp_in_disable(struct cygnus_aio_port *aio)
{
u32 value;
value = readl(aio->cygaud->i2s_in + aio->regs.i2s_cap_stream_cfg);
value &= ~BIT(I2S_IN_STREAM_CFG_CAP_ENA);
writel(value, aio->cygaud->i2s_in + aio->regs.i2s_cap_stream_cfg);
aio->streams_on &= ~CAPTURE_STREAM_MASK;
if (!aio->streams_on) {
value = readl(aio->cygaud->audio + aio->regs.i2s_cfg);
value &= ~BIT(I2S_OUT_CFGX_CLK_ENA);
value &= ~BIT(I2S_OUT_CFGX_DATA_ENABLE);
writel(value, aio->cygaud->audio + aio->regs.i2s_cfg);
}
writel(0x0, aio->cygaud->audio + aio->regs.bf_destch_ctrl);
value = readl(aio->cygaud->audio + aio->regs.bf_destch_cfg);
value &= ~BIT(BF_DST_CFGX_CAP_ENA);
writel(value, aio->cygaud->audio + aio->regs.bf_destch_cfg);
}
static int audio_ssp_out_enable(struct cygnus_aio_port *aio)
{
u32 value;
int status = 0;
switch (aio->port_type) {
case PORT_TDM:
value = readl(aio->cygaud->audio + aio->regs.i2s_stream_cfg);
value |= BIT(I2S_OUT_STREAM_ENA);
writel(value, aio->cygaud->audio + aio->regs.i2s_stream_cfg);
writel(1, aio->cygaud->audio + aio->regs.bf_sourcech_ctrl);
value = readl(aio->cygaud->audio + aio->regs.i2s_cfg);
value |= BIT(I2S_OUT_CFGX_CLK_ENA);
value |= BIT(I2S_OUT_CFGX_DATA_ENABLE);
writel(value, aio->cygaud->audio + aio->regs.i2s_cfg);
value = readl(aio->cygaud->audio + aio->regs.bf_sourcech_cfg);
value |= BIT(BF_SRC_CFGX_SFIFO_ENA);
writel(value, aio->cygaud->audio + aio->regs.bf_sourcech_cfg);
aio->streams_on |= PLAYBACK_STREAM_MASK;
break;
case PORT_SPDIF:
value = readl(aio->cygaud->audio + SPDIF_FORMAT_CFG_OFFSET);
value |= 0x3;
writel(value, aio->cygaud->audio + SPDIF_FORMAT_CFG_OFFSET);
writel(1, aio->cygaud->audio + aio->regs.bf_sourcech_ctrl);
value = readl(aio->cygaud->audio + aio->regs.bf_sourcech_cfg);
value |= BIT(BF_SRC_CFGX_SFIFO_ENA);
writel(value, aio->cygaud->audio + aio->regs.bf_sourcech_cfg);
break;
default:
dev_err(aio->cygaud->dev,
"Port not supported %d\n", aio->portnum);
status = -EINVAL;
}
return status;
}
static int audio_ssp_out_disable(struct cygnus_aio_port *aio)
{
u32 value;
int status = 0;
switch (aio->port_type) {
case PORT_TDM:
aio->streams_on &= ~PLAYBACK_STREAM_MASK;
if (!aio->streams_on) {
value = readl(aio->cygaud->audio + aio->regs.i2s_cfg);
value &= ~BIT(I2S_OUT_CFGX_CLK_ENA);
value &= ~BIT(I2S_OUT_CFGX_DATA_ENABLE);
writel(value, aio->cygaud->audio + aio->regs.i2s_cfg);
}
value = readl(aio->cygaud->audio + BF_SRC_GRP_SYNC_DIS_OFFSET);
value |= BIT(aio->portnum);
writel(value, aio->cygaud->audio + BF_SRC_GRP_SYNC_DIS_OFFSET);
writel(0, aio->cygaud->audio + aio->regs.bf_sourcech_ctrl);
value = readl(aio->cygaud->audio + aio->regs.bf_sourcech_cfg);
value &= ~BIT(BF_SRC_CFGX_SFIFO_ENA);
writel(value, aio->cygaud->audio + aio->regs.bf_sourcech_cfg);
value = readl(aio->cygaud->audio + BF_SRC_GRP_SYNC_DIS_OFFSET);
value &= ~BIT(aio->portnum);
writel(value, aio->cygaud->audio + BF_SRC_GRP_SYNC_DIS_OFFSET);
value = readl(aio->cygaud->audio + aio->regs.i2s_stream_cfg);
value &= ~BIT(I2S_OUT_STREAM_ENA);
writel(value, aio->cygaud->audio + aio->regs.i2s_stream_cfg);
value = readl(aio->cygaud->i2s_in + IOP_SW_INIT_LOGIC);
value |= BIT(aio->portnum);
writel(value, aio->cygaud->i2s_in + IOP_SW_INIT_LOGIC);
value &= ~BIT(aio->portnum);
writel(value, aio->cygaud->i2s_in + IOP_SW_INIT_LOGIC);
break;
case PORT_SPDIF:
value = readl(aio->cygaud->audio + SPDIF_FORMAT_CFG_OFFSET);
value &= ~0x3;
writel(value, aio->cygaud->audio + SPDIF_FORMAT_CFG_OFFSET);
writel(0, aio->cygaud->audio + aio->regs.bf_sourcech_ctrl);
value = readl(aio->cygaud->audio + aio->regs.bf_sourcech_cfg);
value &= ~BIT(BF_SRC_CFGX_SFIFO_ENA);
writel(value, aio->cygaud->audio + aio->regs.bf_sourcech_cfg);
break;
default:
dev_err(aio->cygaud->dev,
"Port not supported %d\n", aio->portnum);
status = -EINVAL;
}
return status;
}
static int pll_configure_mclk(struct cygnus_audio *cygaud, u32 mclk,
struct cygnus_aio_port *aio)
{
int i = 0, error;
bool found = false;
const struct pll_macro_entry *p_entry;
struct clk *ch_clk;
for (i = 0; i < ARRAY_SIZE(pll_predef_mclk); i++) {
p_entry = &pll_predef_mclk[i];
if (p_entry->mclk == mclk) {
found = true;
break;
}
}
if (!found) {
dev_err(cygaud->dev,
"%s No valid mclk freq (%u) found!\n", __func__, mclk);
return -EINVAL;
}
ch_clk = cygaud->audio_clk[p_entry->pll_ch_num];
if ((aio->clk_trace.cap_en) && (!aio->clk_trace.cap_clk_en)) {
error = clk_prepare_enable(ch_clk);
if (error) {
dev_err(cygaud->dev, "%s clk_prepare_enable failed %d\n",
__func__, error);
return error;
}
aio->clk_trace.cap_clk_en = true;
}
if ((aio->clk_trace.play_en) && (!aio->clk_trace.play_clk_en)) {
error = clk_prepare_enable(ch_clk);
if (error) {
dev_err(cygaud->dev, "%s clk_prepare_enable failed %d\n",
__func__, error);
return error;
}
aio->clk_trace.play_clk_en = true;
}
error = clk_set_rate(ch_clk, mclk);
if (error) {
dev_err(cygaud->dev, "%s Set MCLK rate failed: %d\n",
__func__, error);
return error;
}
return p_entry->pll_ch_num;
}
static int cygnus_ssp_set_clocks(struct cygnus_aio_port *aio)
{
u32 value;
u32 mask = 0xf;
u32 sclk;
u32 mclk_rate;
unsigned int bit_rate;
unsigned int ratio;
bit_rate = aio->bit_per_frame * aio->lrclk;
if ((aio->mclk % bit_rate) != 0)
return -EINVAL;
ratio = aio->mclk / bit_rate;
switch (ratio) {
case 2:
case 4:
case 6:
case 8:
case 10:
case 12:
case 14:
mclk_rate = ratio / 2;
break;
default:
dev_err(aio->cygaud->dev,
"Invalid combination of MCLK and BCLK\n");
dev_err(aio->cygaud->dev, "lrclk = %u, bits/frame = %u, mclk = %u\n",
aio->lrclk, aio->bit_per_frame, aio->mclk);
return -EINVAL;
}
switch (aio->port_type) {
case PORT_TDM:
sclk = aio->bit_per_frame;
if (sclk == 512)
sclk = 0;
sclk /= 32;
value = readl(aio->cygaud->audio + aio->regs.i2s_cfg);
value &= ~(mask << I2S_OUT_CFGX_SCLKS_PER_1FS_DIV32);
value |= sclk << I2S_OUT_CFGX_SCLKS_PER_1FS_DIV32;
writel(value, aio->cygaud->audio + aio->regs.i2s_cfg);
dev_dbg(aio->cygaud->dev,
"SCLKS_PER_1FS_DIV32 = 0x%x\n", value);
break;
case PORT_SPDIF:
break;
default:
dev_err(aio->cygaud->dev, "Unknown port type\n");
return -EINVAL;
}
value = readl(aio->cygaud->audio + aio->regs.i2s_mclk_cfg);
value &= ~(0xf << I2S_OUT_MCLKRATE_SHIFT);
value |= (mclk_rate << I2S_OUT_MCLKRATE_SHIFT);
writel(value, aio->cygaud->audio + aio->regs.i2s_mclk_cfg);
dev_dbg(aio->cygaud->dev, "mclk cfg reg = 0x%x\n", value);
dev_dbg(aio->cygaud->dev, "bits per frame = %u, mclk = %u Hz, lrclk = %u Hz\n",
aio->bit_per_frame, aio->mclk, aio->lrclk);
return 0;
}
static int cygnus_ssp_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct cygnus_aio_port *aio = cygnus_dai_get_portinfo(dai);
int rate, bitres;
u32 value;
u32 mask = 0x1f;
int ret = 0;
dev_dbg(aio->cygaud->dev, "%s port = %d\n", __func__, aio->portnum);
dev_dbg(aio->cygaud->dev, "params_channels %d\n",
params_channels(params));
dev_dbg(aio->cygaud->dev, "rate %d\n", params_rate(params));
dev_dbg(aio->cygaud->dev, "format %d\n", params_format(params));
rate = params_rate(params);
switch (aio->mode) {
case CYGNUS_SSPMODE_TDM:
if ((rate == 192000) && (params_channels(params) > 4)) {
dev_err(aio->cygaud->dev, "Cannot run %d channels at %dHz\n",
params_channels(params), rate);
return -EINVAL;
}
break;
case CYGNUS_SSPMODE_I2S:
aio->bit_per_frame = 64;
break;
default:
dev_err(aio->cygaud->dev,
"%s port running in unknown mode\n", __func__);
return -EINVAL;
}
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
value = readl(aio->cygaud->audio + aio->regs.bf_sourcech_cfg);
value &= ~BIT(BF_SRC_CFGX_BUFFER_PAIR_ENABLE);
if (params_channels(params) == 1)
value |= BIT(BF_SRC_CFGX_SAMPLE_CH_MODE);
else
value &= ~BIT(BF_SRC_CFGX_SAMPLE_CH_MODE);
writel(value, aio->cygaud->audio + aio->regs.bf_sourcech_cfg);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S8:
if (aio->port_type == PORT_SPDIF) {
dev_err(aio->cygaud->dev,
"SPDIF does not support 8bit format\n");
return -EINVAL;
}
bitres = 8;
break;
case SNDRV_PCM_FORMAT_S16_LE:
bitres = 16;
break;
case SNDRV_PCM_FORMAT_S32_LE:
bitres = 0;
break;
default:
return -EINVAL;
}
value = readl(aio->cygaud->audio + aio->regs.bf_sourcech_cfg);
value &= ~(mask << BF_SRC_CFGX_BIT_RES);
value |= (bitres << BF_SRC_CFGX_BIT_RES);
writel(value, aio->cygaud->audio + aio->regs.bf_sourcech_cfg);
} else {
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
value = readl(aio->cygaud->audio +
aio->regs.bf_destch_cfg);
value |= BIT(BF_DST_CFGX_CAP_MODE);
writel(value, aio->cygaud->audio +
aio->regs.bf_destch_cfg);
break;
case SNDRV_PCM_FORMAT_S32_LE:
value = readl(aio->cygaud->audio +
aio->regs.bf_destch_cfg);
value &= ~BIT(BF_DST_CFGX_CAP_MODE);
writel(value, aio->cygaud->audio +
aio->regs.bf_destch_cfg);
break;
default:
return -EINVAL;
}
}
aio->lrclk = rate;
if (!aio->is_slave)
ret = cygnus_ssp_set_clocks(aio);
return ret;
}
static int cygnus_ssp_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
int sel;
u32 value;
struct cygnus_aio_port *aio = cygnus_dai_get_portinfo(dai);
struct cygnus_audio *cygaud = snd_soc_dai_get_drvdata(dai);
dev_dbg(aio->cygaud->dev,
"%s Enter port = %d\n", __func__, aio->portnum);
sel = pll_configure_mclk(cygaud, freq, aio);
if (sel < 0) {
dev_err(aio->cygaud->dev,
"%s Setting mclk failed.\n", __func__);
return -EINVAL;
}
aio->mclk = freq;
dev_dbg(aio->cygaud->dev, "%s Setting MCLKSEL to %d\n", __func__, sel);
value = readl(aio->cygaud->audio + aio->regs.i2s_mclk_cfg);
value &= ~(0xf << I2S_OUT_PLLCLKSEL_SHIFT);
value |= (sel << I2S_OUT_PLLCLKSEL_SHIFT);
writel(value, aio->cygaud->audio + aio->regs.i2s_mclk_cfg);
return 0;
}
static int cygnus_ssp_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct cygnus_aio_port *aio = cygnus_dai_get_portinfo(dai);
snd_soc_dai_set_dma_data(dai, substream, aio);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
aio->clk_trace.play_en = true;
else
aio->clk_trace.cap_en = true;
substream->runtime->hw.rate_min = CYGNUS_RATE_MIN;
substream->runtime->hw.rate_max = CYGNUS_RATE_MAX;
snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE, &cygnus_rate_constraint);
return 0;
}
static void cygnus_ssp_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct cygnus_aio_port *aio = cygnus_dai_get_portinfo(dai);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
aio->clk_trace.play_en = false;
else
aio->clk_trace.cap_en = false;
if (!aio->is_slave) {
u32 val;
val = readl(aio->cygaud->audio + aio->regs.i2s_mclk_cfg);
val &= CYGNUS_PLLCLKSEL_MASK;
if (val >= ARRAY_SIZE(aio->cygaud->audio_clk)) {
dev_err(aio->cygaud->dev, "Clk index %u is out of bounds\n",
val);
return;
}
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
if (aio->clk_trace.play_clk_en) {
clk_disable_unprepare(aio->cygaud->
audio_clk[val]);
aio->clk_trace.play_clk_en = false;
}
} else {
if (aio->clk_trace.cap_clk_en) {
clk_disable_unprepare(aio->cygaud->
audio_clk[val]);
aio->clk_trace.cap_clk_en = false;
}
}
}
}
int cygnus_ssp_set_custom_fsync_width(struct snd_soc_dai *cpu_dai, int len)
{
struct cygnus_aio_port *aio = cygnus_dai_get_portinfo(cpu_dai);
if ((len > 0) && (len < 256)) {
aio->fsync_width = len;
return 0;
} else {
return -EINVAL;
}
}
static int cygnus_ssp_set_fmt(struct snd_soc_dai *cpu_dai, unsigned int fmt)
{
struct cygnus_aio_port *aio = cygnus_dai_get_portinfo(cpu_dai);
u32 ssp_curcfg;
u32 ssp_newcfg;
u32 ssp_outcfg;
u32 ssp_incfg;
u32 val;
u32 mask;
dev_dbg(aio->cygaud->dev, "%s Enter fmt: %x\n", __func__, fmt);
if (aio->port_type == PORT_SPDIF)
return -EINVAL;
ssp_newcfg = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
ssp_newcfg |= BIT(I2S_OUT_CFGX_SLAVE_MODE);
aio->is_slave = 1;
break;
case SND_SOC_DAIFMT_CBS_CFS:
ssp_newcfg &= ~BIT(I2S_OUT_CFGX_SLAVE_MODE);
aio->is_slave = 0;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
ssp_newcfg |= BIT(I2S_OUT_CFGX_DATA_ALIGNMENT);
ssp_newcfg |= BIT(I2S_OUT_CFGX_FSYNC_WIDTH);
aio->mode = CYGNUS_SSPMODE_I2S;
break;
case SND_SOC_DAIFMT_DSP_A:
case SND_SOC_DAIFMT_DSP_B:
ssp_newcfg |= BIT(I2S_OUT_CFGX_TDM_MODE);
if ((fmt & SND_SOC_DAIFMT_FORMAT_MASK) == SND_SOC_DAIFMT_DSP_A)
ssp_newcfg |= BIT(I2S_OUT_CFGX_DATA_ALIGNMENT);
if ((aio->fsync_width > 0) && (aio->fsync_width < 256))
ssp_newcfg |=
(aio->fsync_width << I2S_OUT_CFGX_FSYNC_WIDTH);
else
ssp_newcfg |= BIT(I2S_OUT_CFGX_FSYNC_WIDTH);
aio->mode = CYGNUS_SSPMODE_TDM;
break;
default:
return -EINVAL;
}
ssp_curcfg = readl(aio->cygaud->audio + aio->regs.i2s_cfg);
ssp_outcfg = (ssp_curcfg & I2S_OUT_CFG_REG_UPDATE_MASK) | ssp_newcfg;
writel(ssp_outcfg, aio->cygaud->audio + aio->regs.i2s_cfg);
ssp_curcfg = readl(aio->cygaud->i2s_in + aio->regs.i2s_cap_cfg);
ssp_incfg = (ssp_curcfg & I2S_IN_CFG_REG_UPDATE_MASK) | ssp_newcfg;
writel(ssp_incfg, aio->cygaud->i2s_in + aio->regs.i2s_cap_cfg);
val = readl(aio->cygaud->audio + AUD_MISC_SEROUT_OE_REG_BASE);
mask = BIT(AUD_MISC_SEROUT_LRCK_OE)
| BIT(AUD_MISC_SEROUT_SCLK_OE)
| BIT(AUD_MISC_SEROUT_MCLK_OE);
mask = mask << (aio->portnum * 4);
if (aio->is_slave)
val |= mask;
else
val &= ~mask;
dev_dbg(aio->cygaud->dev, "%s Set OE bits 0x%x\n", __func__, val);
writel(val, aio->cygaud->audio + AUD_MISC_SEROUT_OE_REG_BASE);
return 0;
}
static int cygnus_ssp_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct cygnus_aio_port *aio = cygnus_dai_get_portinfo(dai);
struct cygnus_audio *cygaud = snd_soc_dai_get_drvdata(dai);
dev_dbg(aio->cygaud->dev,
"%s cmd %d at port = %d\n", __func__, cmd, aio->portnum);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
case SNDRV_PCM_TRIGGER_RESUME:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
audio_ssp_out_enable(aio);
else
audio_ssp_in_enable(aio);
cygaud->active_ports++;
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_SUSPEND:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
audio_ssp_out_disable(aio);
else
audio_ssp_in_disable(aio);
cygaud->active_ports--;
break;
default:
return -EINVAL;
}
return 0;
}
static int cygnus_set_dai_tdm_slot(struct snd_soc_dai *cpu_dai,
unsigned int tx_mask, unsigned int rx_mask, int slots, int slot_width)
{
struct cygnus_aio_port *aio = cygnus_dai_get_portinfo(cpu_dai);
u32 value;
int bits_per_slot = 0;
int frame_bits;
unsigned int active_slots;
bool found = false;
int i;
if (tx_mask != rx_mask) {
dev_err(aio->cygaud->dev,
"%s tx_mask must equal rx_mask\n", __func__);
return -EINVAL;
}
active_slots = hweight32(tx_mask);
if ((active_slots < 0) || (active_slots > 16))
return -EINVAL;
if (active_slots % 2)
return -EINVAL;
if (active_slots == 16)
active_slots = 0;
switch (slot_width) {
case 16:
bits_per_slot = 1;
break;
case 32:
bits_per_slot = 0;
break;
default:
bits_per_slot = 0;
dev_warn(aio->cygaud->dev,
"%s Defaulting Slot Width to 32\n", __func__);
}
frame_bits = slots * slot_width;
for (i = 0; i < ARRAY_SIZE(ssp_valid_tdm_framesize); i++) {
if (ssp_valid_tdm_framesize[i] == frame_bits) {
found = true;
break;
}
}
if (!found) {
dev_err(aio->cygaud->dev,
"%s In TDM mode, frame bits INVALID (%d)\n",
__func__, frame_bits);
return -EINVAL;
}
aio->bit_per_frame = frame_bits;
dev_dbg(aio->cygaud->dev, "%s active_slots %u, bits per frame %d\n",
__func__, active_slots, frame_bits);
value = readl(aio->cygaud->i2s_in + aio->regs.i2s_cap_cfg);
value &= ~(0xf << I2S_OUT_CFGX_VALID_SLOT);
value |= (active_slots << I2S_OUT_CFGX_VALID_SLOT);
value &= ~BIT(I2S_OUT_CFGX_BITS_PER_SLOT);
value |= (bits_per_slot << I2S_OUT_CFGX_BITS_PER_SLOT);
writel(value, aio->cygaud->i2s_in + aio->regs.i2s_cap_cfg);
value = readl(aio->cygaud->audio + aio->regs.i2s_cfg);
value &= ~(0xf << I2S_OUT_CFGX_VALID_SLOT);
value |= (active_slots << I2S_OUT_CFGX_VALID_SLOT);
value &= ~BIT(I2S_OUT_CFGX_BITS_PER_SLOT);
value |= (bits_per_slot << I2S_OUT_CFGX_BITS_PER_SLOT);
writel(value, aio->cygaud->audio + aio->regs.i2s_cfg);
return 0;
}
static int cygnus_ssp_suspend(struct snd_soc_dai *cpu_dai)
{
struct cygnus_aio_port *aio = cygnus_dai_get_portinfo(cpu_dai);
if (!aio->is_slave) {
u32 val;
val = readl(aio->cygaud->audio + aio->regs.i2s_mclk_cfg);
val &= CYGNUS_PLLCLKSEL_MASK;
if (val >= ARRAY_SIZE(aio->cygaud->audio_clk)) {
dev_err(aio->cygaud->dev, "Clk index %u is out of bounds\n",
val);
return -EINVAL;
}
if (aio->clk_trace.cap_clk_en)
clk_disable_unprepare(aio->cygaud->audio_clk[val]);
if (aio->clk_trace.play_clk_en)
clk_disable_unprepare(aio->cygaud->audio_clk[val]);
aio->pll_clk_num = val;
}
return 0;
}
static int cygnus_ssp_resume(struct snd_soc_dai *cpu_dai)
{
struct cygnus_aio_port *aio = cygnus_dai_get_portinfo(cpu_dai);
int error;
if (!aio->is_slave) {
if (aio->clk_trace.cap_clk_en) {
error = clk_prepare_enable(aio->cygaud->
audio_clk[aio->pll_clk_num]);
if (error) {
dev_err(aio->cygaud->dev, "%s clk_prepare_enable failed\n",
__func__);
return -EINVAL;
}
}
if (aio->clk_trace.play_clk_en) {
error = clk_prepare_enable(aio->cygaud->
audio_clk[aio->pll_clk_num]);
if (error) {
if (aio->clk_trace.cap_clk_en)
clk_disable_unprepare(aio->cygaud->
audio_clk[aio->pll_clk_num]);
dev_err(aio->cygaud->dev, "%s clk_prepare_enable failed\n",
__func__);
return -EINVAL;
}
}
}
return 0;
}
static int parse_ssp_child_node(struct platform_device *pdev,
struct device_node *dn,
struct cygnus_audio *cygaud,
struct snd_soc_dai_driver *p_dai)
{
struct cygnus_aio_port *aio;
struct cygnus_ssp_regs ssp_regs[3];
u32 rawval;
int portnum = -1;
enum cygnus_audio_port_type port_type;
if (of_property_read_u32(dn, "reg", &rawval)) {
dev_err(&pdev->dev, "Missing reg property\n");
return -EINVAL;
}
portnum = rawval;
switch (rawval) {
case 0:
ssp_regs[0] = INIT_SSP_REGS(0);
port_type = PORT_TDM;
break;
case 1:
ssp_regs[1] = INIT_SSP_REGS(1);
port_type = PORT_TDM;
break;
case 2:
ssp_regs[2] = INIT_SSP_REGS(2);
port_type = PORT_TDM;
break;
case 3:
port_type = PORT_SPDIF;
break;
default:
dev_err(&pdev->dev, "Bad value for reg %u\n", rawval);
return -EINVAL;
}
aio = &cygaud->portinfo[portnum];
aio->cygaud = cygaud;
aio->portnum = portnum;
aio->port_type = port_type;
aio->fsync_width = -1;
switch (port_type) {
case PORT_TDM:
aio->regs = ssp_regs[portnum];
*p_dai = cygnus_ssp_dai_info[portnum];
aio->mode = CYGNUS_SSPMODE_UNKNOWN;
break;
case PORT_SPDIF:
aio->regs.bf_sourcech_cfg = BF_SRC_CFG3_OFFSET;
aio->regs.bf_sourcech_ctrl = BF_SRC_CTRL3_OFFSET;
aio->regs.i2s_mclk_cfg = SPDIF_MCLK_CFG_OFFSET;
aio->regs.i2s_stream_cfg = SPDIF_STREAM_CFG_OFFSET;
*p_dai = cygnus_spdif_dai_info;
aio->mode = CYGNUS_SSPMODE_I2S;
break;
default:
dev_err(&pdev->dev, "Bad value for port_type %d\n", port_type);
return -EINVAL;
}
dev_dbg(&pdev->dev, "%s portnum = %d\n", __func__, aio->portnum);
aio->streams_on = 0;
aio->cygaud->dev = &pdev->dev;
aio->clk_trace.play_en = false;
aio->clk_trace.cap_en = false;
audio_ssp_init_portregs(aio);
return 0;
}
static int audio_clk_init(struct platform_device *pdev,
struct cygnus_audio *cygaud)
{
int i;
char clk_name[PROP_LEN_MAX];
for (i = 0; i < ARRAY_SIZE(cygaud->audio_clk); i++) {
snprintf(clk_name, PROP_LEN_MAX, "ch%d_audio", i);
cygaud->audio_clk[i] = devm_clk_get(&pdev->dev, clk_name);
if (IS_ERR(cygaud->audio_clk[i]))
return PTR_ERR(cygaud->audio_clk[i]);
}
return 0;
}
static int cygnus_ssp_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *child_node;
struct resource *res = pdev->resource;
struct cygnus_audio *cygaud;
int err = -EINVAL;
int node_count;
int active_port_count;
cygaud = devm_kzalloc(dev, sizeof(struct cygnus_audio), GFP_KERNEL);
if (!cygaud)
return -ENOMEM;
dev_set_drvdata(dev, cygaud);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "aud");
cygaud->audio = devm_ioremap_resource(dev, res);
if (IS_ERR(cygaud->audio))
return PTR_ERR(cygaud->audio);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "i2s_in");
cygaud->i2s_in = devm_ioremap_resource(dev, res);
if (IS_ERR(cygaud->i2s_in))
return PTR_ERR(cygaud->i2s_in);
writel(CYGNUS_SSP_TRISTATE_MASK,
cygaud->audio + AUD_MISC_SEROUT_OE_REG_BASE);
node_count = of_get_child_count(pdev->dev.of_node);
if ((node_count < 1) || (node_count > CYGNUS_MAX_PORTS)) {
dev_err(dev, "child nodes is %d. Must be between 1 and %d\n",
node_count, CYGNUS_MAX_PORTS);
return -EINVAL;
}
active_port_count = 0;
for_each_available_child_of_node(pdev->dev.of_node, child_node) {
err = parse_ssp_child_node(pdev, child_node, cygaud,
&cygnus_ssp_dai[active_port_count]);
if (err < 0)
return err;
else if (!err) {
dev_dbg(dev, "Activating DAI: %s\n",
cygnus_ssp_dai[active_port_count].name);
active_port_count++;
}
}
cygaud->dev = dev;
cygaud->active_ports = 0;
dev_dbg(dev, "Registering %d DAIs\n", active_port_count);
err = snd_soc_register_component(dev, &cygnus_ssp_component,
cygnus_ssp_dai, active_port_count);
if (err) {
dev_err(dev, "snd_soc_register_dai failed\n");
return err;
}
cygaud->irq_num = platform_get_irq(pdev, 0);
if (cygaud->irq_num <= 0) {
dev_err(dev, "platform_get_irq failed\n");
err = cygaud->irq_num;
goto err_irq;
}
err = audio_clk_init(pdev, cygaud);
if (err) {
dev_err(dev, "audio clock initialization failed\n");
goto err_irq;
}
err = cygnus_soc_platform_register(dev, cygaud);
if (err) {
dev_err(dev, "platform reg error %d\n", err);
goto err_irq;
}
return 0;
err_irq:
snd_soc_unregister_component(dev);
return err;
}
static int cygnus_ssp_remove(struct platform_device *pdev)
{
cygnus_soc_platform_unregister(&pdev->dev);
snd_soc_unregister_component(&pdev->dev);
return 0;
}
