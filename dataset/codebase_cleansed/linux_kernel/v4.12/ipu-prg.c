struct ipu_prg *
ipu_prg_lookup_by_phandle(struct device *dev, const char *name, int ipu_id)
{
struct device_node *prg_node = of_parse_phandle(dev->of_node,
name, 0);
struct ipu_prg *prg;
mutex_lock(&ipu_prg_list_mutex);
list_for_each_entry(prg, &ipu_prg_list, list) {
if (prg_node == prg->dev->of_node) {
mutex_unlock(&ipu_prg_list_mutex);
device_link_add(dev, prg->dev, DL_FLAG_AUTOREMOVE);
prg->id = ipu_id;
return prg;
}
}
mutex_unlock(&ipu_prg_list_mutex);
return NULL;
}
int ipu_prg_max_active_channels(void)
{
return ipu_pre_get_available_count();
}
bool ipu_prg_present(struct ipu_soc *ipu)
{
if (ipu->prg_priv)
return true;
return false;
}
bool ipu_prg_format_supported(struct ipu_soc *ipu, uint32_t format,
uint64_t modifier)
{
const struct drm_format_info *info = drm_format_info(format);
if (info->num_planes != 1)
return false;
return true;
}
int ipu_prg_enable(struct ipu_soc *ipu)
{
struct ipu_prg *prg = ipu->prg_priv;
int ret;
if (!prg)
return 0;
ret = clk_prepare_enable(prg->clk_axi);
if (ret)
goto fail_disable_ipg;
return 0;
fail_disable_ipg:
clk_disable_unprepare(prg->clk_ipg);
return ret;
}
void ipu_prg_disable(struct ipu_soc *ipu)
{
struct ipu_prg *prg = ipu->prg_priv;
if (!prg)
return;
clk_disable_unprepare(prg->clk_axi);
}
static int ipu_prg_ipu_to_prg_chan(int ipu_chan)
{
switch (ipu_chan) {
case IPUV3_CHANNEL_MEM_BG_SYNC:
return 0;
case IPUV3_CHANNEL_MEM_FG_SYNC:
return 1;
case IPUV3_CHANNEL_MEM_DC_SYNC:
return 2;
default:
return -EINVAL;
}
}
static int ipu_prg_get_pre(struct ipu_prg *prg, int prg_chan)
{
int i, ret;
if (prg_chan == 0) {
ret = ipu_pre_get(prg->pres[0]);
if (ret)
goto fail;
prg->chan[prg_chan].used_pre = 0;
return 0;
}
for (i = 1; i < 3; i++) {
ret = ipu_pre_get(prg->pres[i]);
if (!ret) {
u32 val, mux;
int shift;
prg->chan[prg_chan].used_pre = i;
shift = (i == 1) ? 12 : 14;
mux = (prg->id << 1) | (prg_chan - 1);
regmap_update_bits(prg->iomuxc_gpr, IOMUXC_GPR5,
0x3 << shift, mux << shift);
shift = (i == 1) ? 14 : 12;
regmap_read(prg->iomuxc_gpr, IOMUXC_GPR5, &val);
if (((val >> shift) & 0x3) == mux) {
regmap_update_bits(prg->iomuxc_gpr, IOMUXC_GPR5,
0x3 << shift,
(mux ^ 0x1) << shift);
}
return 0;
}
}
fail:
dev_err(prg->dev, "could not get PRE for PRG chan %d", prg_chan);
return ret;
}
static void ipu_prg_put_pre(struct ipu_prg *prg, int prg_chan)
{
struct ipu_prg_channel *chan = &prg->chan[prg_chan];
ipu_pre_put(prg->pres[chan->used_pre]);
chan->used_pre = -1;
}
void ipu_prg_channel_disable(struct ipuv3_channel *ipu_chan)
{
int prg_chan = ipu_prg_ipu_to_prg_chan(ipu_chan->num);
struct ipu_prg *prg = ipu_chan->ipu->prg_priv;
struct ipu_prg_channel *chan = &prg->chan[prg_chan];
u32 val;
if (!chan->enabled || prg_chan < 0)
return;
clk_prepare_enable(prg->clk_ipg);
val = readl(prg->regs + IPU_PRG_CTL);
val |= IPU_PRG_CTL_BYPASS(prg_chan);
writel(val, prg->regs + IPU_PRG_CTL);
val = IPU_PRG_REG_UPDATE_REG_UPDATE;
writel(val, prg->regs + IPU_PRG_REG_UPDATE);
clk_disable_unprepare(prg->clk_ipg);
ipu_prg_put_pre(prg, prg_chan);
chan->enabled = false;
}
int ipu_prg_channel_configure(struct ipuv3_channel *ipu_chan,
unsigned int axi_id, unsigned int width,
unsigned int height, unsigned int stride,
u32 format, unsigned long *eba)
{
int prg_chan = ipu_prg_ipu_to_prg_chan(ipu_chan->num);
struct ipu_prg *prg = ipu_chan->ipu->prg_priv;
struct ipu_prg_channel *chan = &prg->chan[prg_chan];
u32 val;
int ret;
if (prg_chan < 0)
return prg_chan;
if (chan->enabled) {
ipu_pre_update(prg->pres[chan->used_pre], *eba);
return 0;
}
ret = ipu_prg_get_pre(prg, prg_chan);
if (ret)
return ret;
ipu_pre_configure(prg->pres[chan->used_pre],
width, height, stride, format, *eba);
ret = clk_prepare_enable(prg->clk_ipg);
if (ret) {
ipu_prg_put_pre(prg, prg_chan);
return ret;
}
val = (stride - 1) & IPU_PRG_STRIDE_STRIDE_MASK;
writel(val, prg->regs + IPU_PRG_STRIDE(prg_chan));
val = ((height & IPU_PRG_HEIGHT_PRE_HEIGHT_MASK) <<
IPU_PRG_HEIGHT_PRE_HEIGHT_SHIFT) |
((height & IPU_PRG_HEIGHT_IPU_HEIGHT_MASK) <<
IPU_PRG_HEIGHT_IPU_HEIGHT_SHIFT);
writel(val, prg->regs + IPU_PRG_HEIGHT(prg_chan));
val = ipu_pre_get_baddr(prg->pres[chan->used_pre]);
*eba = val;
writel(val, prg->regs + IPU_PRG_BADDR(prg_chan));
val = readl(prg->regs + IPU_PRG_CTL);
val |= IPU_PRG_CTL_CNT_LOAD_EN(prg_chan);
val &= ~(IPU_PRG_CTL_SOFT_ARID_MASK <<
IPU_PRG_CTL_SOFT_ARID_SHIFT(prg_chan));
val |= IPU_PRG_CTL_SOFT_ARID(prg_chan, axi_id);
val &= ~IPU_PRG_CTL_BYPASS(prg_chan);
writel(val, prg->regs + IPU_PRG_CTL);
val = IPU_PRG_REG_UPDATE_REG_UPDATE;
writel(val, prg->regs + IPU_PRG_REG_UPDATE);
clk_disable_unprepare(prg->clk_ipg);
chan->enabled = true;
return 0;
}
static int ipu_prg_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct ipu_prg *prg;
u32 val;
int i, ret;
prg = devm_kzalloc(dev, sizeof(*prg), GFP_KERNEL);
if (!prg)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
prg->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(prg->regs))
return PTR_ERR(prg->regs);
prg->clk_ipg = devm_clk_get(dev, "ipg");
if (IS_ERR(prg->clk_ipg))
return PTR_ERR(prg->clk_ipg);
prg->clk_axi = devm_clk_get(dev, "axi");
if (IS_ERR(prg->clk_axi))
return PTR_ERR(prg->clk_axi);
prg->iomuxc_gpr =
syscon_regmap_lookup_by_compatible("fsl,imx6q-iomuxc-gpr");
if (IS_ERR(prg->iomuxc_gpr))
return PTR_ERR(prg->iomuxc_gpr);
for (i = 0; i < 3; i++) {
prg->pres[i] = ipu_pre_lookup_by_phandle(dev, "fsl,pres", i);
if (!prg->pres[i])
return -EPROBE_DEFER;
}
ret = clk_prepare_enable(prg->clk_ipg);
if (ret)
return ret;
val = readl(prg->regs + IPU_PRG_CTL);
val |= IPU_PRG_CTL_SHADOW_EN;
writel(val, prg->regs + IPU_PRG_CTL);
writel(0xffffffff, prg->regs + IPU_PRG_THD);
clk_disable_unprepare(prg->clk_ipg);
prg->dev = dev;
platform_set_drvdata(pdev, prg);
mutex_lock(&ipu_prg_list_mutex);
list_add(&prg->list, &ipu_prg_list);
mutex_unlock(&ipu_prg_list_mutex);
return 0;
}
static int ipu_prg_remove(struct platform_device *pdev)
{
struct ipu_prg *prg = platform_get_drvdata(pdev);
mutex_lock(&ipu_prg_list_mutex);
list_del(&prg->list);
mutex_unlock(&ipu_prg_list_mutex);
return 0;
}
