static inline struct ipu_flow *to_flow(struct ipu_dp *dp)
{
if (dp->foreground)
return container_of(dp, struct ipu_flow, foreground);
else
return container_of(dp, struct ipu_flow, background);
}
int ipu_dp_set_global_alpha(struct ipu_dp *dp, bool enable,
u8 alpha, bool bg_chan)
{
struct ipu_flow *flow = to_flow(dp);
struct ipu_dp_priv *priv = flow->priv;
u32 reg;
mutex_lock(&priv->mutex);
reg = readl(flow->base + DP_COM_CONF);
if (bg_chan)
reg &= ~DP_COM_CONF_GWSEL;
else
reg |= DP_COM_CONF_GWSEL;
writel(reg, flow->base + DP_COM_CONF);
if (enable) {
reg = readl(flow->base + DP_GRAPH_WIND_CTRL) & 0x00FFFFFFL;
writel(reg | ((u32) alpha << 24),
flow->base + DP_GRAPH_WIND_CTRL);
reg = readl(flow->base + DP_COM_CONF);
writel(reg | DP_COM_CONF_GWAM, flow->base + DP_COM_CONF);
} else {
reg = readl(flow->base + DP_COM_CONF);
writel(reg & ~DP_COM_CONF_GWAM, flow->base + DP_COM_CONF);
}
ipu_srm_dp_sync_update(priv->ipu);
mutex_unlock(&priv->mutex);
return 0;
}
int ipu_dp_set_window_pos(struct ipu_dp *dp, u16 x_pos, u16 y_pos)
{
struct ipu_flow *flow = to_flow(dp);
struct ipu_dp_priv *priv = flow->priv;
writel((x_pos << 16) | y_pos, flow->base + DP_FG_POS);
ipu_srm_dp_sync_update(priv->ipu);
return 0;
}
static void ipu_dp_csc_init(struct ipu_flow *flow,
enum ipu_color_space in,
enum ipu_color_space out,
u32 place)
{
u32 reg;
reg = readl(flow->base + DP_COM_CONF);
reg &= ~DP_COM_CONF_CSC_DEF_MASK;
if (in == out) {
writel(reg, flow->base + DP_COM_CONF);
return;
}
if (in == IPUV3_COLORSPACE_RGB && out == IPUV3_COLORSPACE_YUV) {
writel(0x099 | (0x12d << 16), flow->base + DP_CSC_A_0);
writel(0x03a | (0x3a9 << 16), flow->base + DP_CSC_A_1);
writel(0x356 | (0x100 << 16), flow->base + DP_CSC_A_2);
writel(0x100 | (0x329 << 16), flow->base + DP_CSC_A_3);
writel(0x3d6 | (0x0000 << 16) | (2 << 30),
flow->base + DP_CSC_0);
writel(0x200 | (2 << 14) | (0x200 << 16) | (2 << 30),
flow->base + DP_CSC_1);
} else {
writel(0x095 | (0x000 << 16), flow->base + DP_CSC_A_0);
writel(0x0cc | (0x095 << 16), flow->base + DP_CSC_A_1);
writel(0x3ce | (0x398 << 16), flow->base + DP_CSC_A_2);
writel(0x095 | (0x0ff << 16), flow->base + DP_CSC_A_3);
writel(0x000 | (0x3e42 << 16) | (1 << 30),
flow->base + DP_CSC_0);
writel(0x10a | (1 << 14) | (0x3dd6 << 16) | (1 << 30),
flow->base + DP_CSC_1);
}
reg |= place;
writel(reg, flow->base + DP_COM_CONF);
}
int ipu_dp_setup_channel(struct ipu_dp *dp,
enum ipu_color_space in,
enum ipu_color_space out)
{
struct ipu_flow *flow = to_flow(dp);
struct ipu_dp_priv *priv = flow->priv;
mutex_lock(&priv->mutex);
dp->in_cs = in;
if (!dp->foreground)
flow->out_cs = out;
if (flow->foreground.in_cs == flow->background.in_cs) {
ipu_dp_csc_init(flow, flow->foreground.in_cs, flow->out_cs,
DP_COM_CONF_CSC_DEF_BOTH);
} else {
if (flow->foreground.in_cs == flow->out_cs)
ipu_dp_csc_init(flow, flow->background.in_cs,
flow->out_cs, DP_COM_CONF_CSC_DEF_BG);
else
ipu_dp_csc_init(flow, flow->foreground.in_cs,
flow->out_cs, DP_COM_CONF_CSC_DEF_FG);
}
ipu_srm_dp_sync_update(priv->ipu);
mutex_unlock(&priv->mutex);
return 0;
}
int ipu_dp_enable(struct ipu_soc *ipu)
{
struct ipu_dp_priv *priv = ipu->dp_priv;
mutex_lock(&priv->mutex);
if (!priv->use_count)
ipu_module_enable(priv->ipu, IPU_CONF_DP_EN);
priv->use_count++;
mutex_unlock(&priv->mutex);
return 0;
}
int ipu_dp_enable_channel(struct ipu_dp *dp)
{
struct ipu_flow *flow = to_flow(dp);
struct ipu_dp_priv *priv = flow->priv;
u32 reg;
if (!dp->foreground)
return 0;
mutex_lock(&priv->mutex);
reg = readl(flow->base + DP_COM_CONF);
reg |= DP_COM_CONF_FG_EN;
writel(reg, flow->base + DP_COM_CONF);
ipu_srm_dp_sync_update(priv->ipu);
mutex_unlock(&priv->mutex);
return 0;
}
void ipu_dp_disable_channel(struct ipu_dp *dp)
{
struct ipu_flow *flow = to_flow(dp);
struct ipu_dp_priv *priv = flow->priv;
u32 reg, csc;
if (!dp->foreground)
return;
mutex_lock(&priv->mutex);
reg = readl(flow->base + DP_COM_CONF);
csc = reg & DP_COM_CONF_CSC_DEF_MASK;
if (csc == DP_COM_CONF_CSC_DEF_FG)
reg &= ~DP_COM_CONF_CSC_DEF_MASK;
reg &= ~DP_COM_CONF_FG_EN;
writel(reg, flow->base + DP_COM_CONF);
writel(0, flow->base + DP_FG_POS);
ipu_srm_dp_sync_update(priv->ipu);
if (ipu_idmac_channel_busy(priv->ipu, IPUV3_CHANNEL_MEM_BG_SYNC))
ipu_wait_interrupt(priv->ipu, IPU_IRQ_DP_SF_END, 50);
mutex_unlock(&priv->mutex);
}
void ipu_dp_disable(struct ipu_soc *ipu)
{
struct ipu_dp_priv *priv = ipu->dp_priv;
mutex_lock(&priv->mutex);
priv->use_count--;
if (!priv->use_count)
ipu_module_disable(priv->ipu, IPU_CONF_DP_EN);
if (priv->use_count < 0)
priv->use_count = 0;
mutex_unlock(&priv->mutex);
}
struct ipu_dp *ipu_dp_get(struct ipu_soc *ipu, unsigned int flow)
{
struct ipu_dp_priv *priv = ipu->dp_priv;
struct ipu_dp *dp;
if ((flow >> 1) >= IPUV3_NUM_FLOWS)
return ERR_PTR(-EINVAL);
if (flow & 1)
dp = &priv->flow[flow >> 1].foreground;
else
dp = &priv->flow[flow >> 1].background;
if (dp->in_use)
return ERR_PTR(-EBUSY);
dp->in_use = true;
return dp;
}
void ipu_dp_put(struct ipu_dp *dp)
{
dp->in_use = false;
}
int ipu_dp_init(struct ipu_soc *ipu, struct device *dev, unsigned long base)
{
struct ipu_dp_priv *priv;
int i;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->dev = dev;
priv->ipu = ipu;
ipu->dp_priv = priv;
priv->base = devm_ioremap(dev, base, PAGE_SIZE);
if (!priv->base)
return -ENOMEM;
mutex_init(&priv->mutex);
for (i = 0; i < IPUV3_NUM_FLOWS; i++) {
priv->flow[i].foreground.foreground = true;
priv->flow[i].base = priv->base + ipu_dp_flow_base[i];
priv->flow[i].priv = priv;
}
return 0;
}
void ipu_dp_exit(struct ipu_soc *ipu)
{
}
