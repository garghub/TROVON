static u32 socfpga_fpga_readl(struct socfpga_fpga_priv *priv, u32 reg_offset)
{
return readl(priv->fpga_base_addr + reg_offset);
}
static void socfpga_fpga_writel(struct socfpga_fpga_priv *priv, u32 reg_offset,
u32 value)
{
writel(value, priv->fpga_base_addr + reg_offset);
}
static u32 socfpga_fpga_raw_readl(struct socfpga_fpga_priv *priv,
u32 reg_offset)
{
return __raw_readl(priv->fpga_base_addr + reg_offset);
}
static void socfpga_fpga_raw_writel(struct socfpga_fpga_priv *priv,
u32 reg_offset, u32 value)
{
__raw_writel(value, priv->fpga_base_addr + reg_offset);
}
static void socfpga_fpga_data_writel(struct socfpga_fpga_priv *priv, u32 value)
{
writel(value, priv->fpga_data_addr);
}
static inline void socfpga_fpga_set_bitsl(struct socfpga_fpga_priv *priv,
u32 offset, u32 bits)
{
u32 val;
val = socfpga_fpga_readl(priv, offset);
val |= bits;
socfpga_fpga_writel(priv, offset, val);
}
static inline void socfpga_fpga_clr_bitsl(struct socfpga_fpga_priv *priv,
u32 offset, u32 bits)
{
u32 val;
val = socfpga_fpga_readl(priv, offset);
val &= ~bits;
socfpga_fpga_writel(priv, offset, val);
}
static u32 socfpga_fpga_mon_status_get(struct socfpga_fpga_priv *priv)
{
return socfpga_fpga_readl(priv, SOCFPGA_FPGMGR_GPIO_EXT_PORTA_OFST) &
SOCFPGA_FPGMGR_MON_STATUS_MASK;
}
static u32 socfpga_fpga_state_get(struct socfpga_fpga_priv *priv)
{
u32 status = socfpga_fpga_mon_status_get(priv);
if ((status & SOCFPGA_FPGMGR_MON_FPGA_POWER_ON) == 0)
return SOCFPGA_FPGMGR_STAT_POWER_OFF;
return socfpga_fpga_readl(priv, SOCFPGA_FPGMGR_STAT_OFST) &
SOCFPGA_FPGMGR_STAT_STATE_MASK;
}
static void socfpga_fpga_clear_done_status(struct socfpga_fpga_priv *priv)
{
socfpga_fpga_writel(priv, SOCFPGA_FPGMGR_DCLKSTAT_OFST,
SOCFPGA_FPGMGR_DCLKSTAT_DCNTDONE_E_DONE);
}
static int socfpga_fpga_dclk_set_and_wait_clear(struct socfpga_fpga_priv *priv,
u32 count)
{
int timeout = 2;
u32 done;
if (socfpga_fpga_readl(priv, SOCFPGA_FPGMGR_DCLKSTAT_OFST))
socfpga_fpga_clear_done_status(priv);
socfpga_fpga_writel(priv, SOCFPGA_FPGMGR_DCLKCNT_OFST, count);
do {
done = socfpga_fpga_readl(priv, SOCFPGA_FPGMGR_DCLKSTAT_OFST);
if (done == SOCFPGA_FPGMGR_DCLKSTAT_DCNTDONE_E_DONE) {
socfpga_fpga_clear_done_status(priv);
return 0;
}
udelay(1);
} while (timeout--);
return -ETIMEDOUT;
}
static int socfpga_fpga_wait_for_state(struct socfpga_fpga_priv *priv,
u32 state)
{
int timeout = 2;
do {
if ((socfpga_fpga_state_get(priv) & state) != 0)
return 0;
msleep(20);
} while (timeout--);
return -ETIMEDOUT;
}
static void socfpga_fpga_enable_irqs(struct socfpga_fpga_priv *priv, u32 irqs)
{
socfpga_fpga_writel(priv, SOCFPGA_FPGMGR_GPIO_INTTYPE_LEVEL_OFST, 0);
socfpga_fpga_writel(priv, SOCFPGA_FPGMGR_GPIO_INT_POL_OFST, irqs);
socfpga_fpga_writel(priv, SOCFPGA_FPGMGR_GPIO_PORTA_EOI_OFST, irqs);
socfpga_fpga_writel(priv, SOCFPGA_FPGMGR_GPIO_INTMSK_OFST, 0);
socfpga_fpga_writel(priv, SOCFPGA_FPGMGR_GPIO_INTEN_OFST, irqs);
}
static void socfpga_fpga_disable_irqs(struct socfpga_fpga_priv *priv)
{
socfpga_fpga_writel(priv, SOCFPGA_FPGMGR_GPIO_INTEN_OFST, 0);
}
static irqreturn_t socfpga_fpga_isr(int irq, void *dev_id)
{
struct socfpga_fpga_priv *priv = dev_id;
u32 irqs, st;
bool conf_done, nstatus;
irqs = socfpga_fpga_raw_readl(priv, SOCFPGA_FPGMGR_GPIO_INTSTAT_OFST);
socfpga_fpga_raw_writel(priv, SOCFPGA_FPGMGR_GPIO_PORTA_EOI_OFST, irqs);
st = socfpga_fpga_raw_readl(priv, SOCFPGA_FPGMGR_GPIO_EXT_PORTA_OFST);
conf_done = (st & SOCFPGA_FPGMGR_MON_CONF_DONE) != 0;
nstatus = (st & SOCFPGA_FPGMGR_MON_NSTATUS) != 0;
if (conf_done && nstatus) {
socfpga_fpga_raw_writel(priv,
SOCFPGA_FPGMGR_GPIO_INTEN_OFST, 0);
complete(&priv->status_complete);
}
return IRQ_HANDLED;
}
static int socfpga_fpga_wait_for_config_done(struct socfpga_fpga_priv *priv)
{
int timeout, ret = 0;
socfpga_fpga_disable_irqs(priv);
init_completion(&priv->status_complete);
socfpga_fpga_enable_irqs(priv, SOCFPGA_FPGMGR_MON_CONF_DONE);
timeout = wait_for_completion_interruptible_timeout(
&priv->status_complete,
msecs_to_jiffies(10));
if (timeout == 0)
ret = -ETIMEDOUT;
socfpga_fpga_disable_irqs(priv);
return ret;
}
static int socfpga_fpga_cfg_mode_get(struct socfpga_fpga_priv *priv)
{
u32 msel;
msel = socfpga_fpga_readl(priv, SOCFPGA_FPGMGR_STAT_OFST);
msel &= SOCFPGA_FPGMGR_STAT_MSEL_MASK;
msel >>= SOCFPGA_FPGMGR_STAT_MSEL_SHIFT;
if ((msel >= ARRAY_SIZE(cfgmgr_modes)) || !cfgmgr_modes[msel].valid)
return -EINVAL;
return msel;
}
static int socfpga_fpga_cfg_mode_set(struct socfpga_fpga_priv *priv)
{
u32 ctrl_reg;
int mode;
mode = socfpga_fpga_cfg_mode_get(priv);
if (mode < 0)
return mode;
ctrl_reg = socfpga_fpga_readl(priv, SOCFPGA_FPGMGR_CTL_OFST);
ctrl_reg &= ~SOCFPGA_FPGMGR_CTL_CDRATIO_MASK;
ctrl_reg &= ~SOCFPGA_FPGMGR_CTL_CFGWDTH_MASK;
ctrl_reg |= cfgmgr_modes[mode].ctrl;
ctrl_reg &= ~SOCFPGA_FPGMGR_CTL_NCE;
socfpga_fpga_writel(priv, SOCFPGA_FPGMGR_CTL_OFST, ctrl_reg);
return 0;
}
static int socfpga_fpga_reset(struct fpga_manager *mgr)
{
struct socfpga_fpga_priv *priv = mgr->priv;
u32 ctrl_reg, status;
int ret;
ret = socfpga_fpga_cfg_mode_set(priv);
if (ret)
return ret;
socfpga_fpga_set_bitsl(priv, SOCFPGA_FPGMGR_CTL_OFST,
SOCFPGA_FPGMGR_CTL_EN);
ctrl_reg = socfpga_fpga_readl(priv, SOCFPGA_FPGMGR_CTL_OFST);
ctrl_reg |= SOCFPGA_FPGMGR_CTL_NCFGPULL;
socfpga_fpga_writel(priv, SOCFPGA_FPGMGR_CTL_OFST, ctrl_reg);
status = socfpga_fpga_wait_for_state(priv, SOCFPGA_FPGMGR_STAT_RESET);
ctrl_reg &= ~SOCFPGA_FPGMGR_CTL_NCFGPULL;
socfpga_fpga_writel(priv, SOCFPGA_FPGMGR_CTL_OFST, ctrl_reg);
if (status)
return -ETIMEDOUT;
return 0;
}
static int socfpga_fpga_ops_configure_init(struct fpga_manager *mgr,
struct fpga_image_info *info,
const char *buf, size_t count)
{
struct socfpga_fpga_priv *priv = mgr->priv;
int ret;
if (info->flags & FPGA_MGR_PARTIAL_RECONFIG) {
dev_err(&mgr->dev, "Partial reconfiguration not supported.\n");
return -EINVAL;
}
ret = socfpga_fpga_reset(mgr);
if (ret)
return ret;
if (socfpga_fpga_wait_for_state(priv, SOCFPGA_FPGMGR_STAT_CFG))
return -ETIMEDOUT;
socfpga_fpga_writel(priv, SOCFPGA_FPGMGR_GPIO_PORTA_EOI_OFST,
SOCFPGA_FPGMGR_MON_NSTATUS);
socfpga_fpga_set_bitsl(priv, SOCFPGA_FPGMGR_CTL_OFST,
SOCFPGA_FPGMGR_CTL_AXICFGEN);
return 0;
}
static int socfpga_fpga_ops_configure_write(struct fpga_manager *mgr,
const char *buf, size_t count)
{
struct socfpga_fpga_priv *priv = mgr->priv;
u32 *buffer_32 = (u32 *)buf;
size_t i = 0;
if (count <= 0)
return -EINVAL;
while (count >= sizeof(u32)) {
socfpga_fpga_data_writel(priv, buffer_32[i++]);
count -= sizeof(u32);
}
switch (count) {
case 3:
socfpga_fpga_data_writel(priv, buffer_32[i++] & 0x00ffffff);
break;
case 2:
socfpga_fpga_data_writel(priv, buffer_32[i++] & 0x0000ffff);
break;
case 1:
socfpga_fpga_data_writel(priv, buffer_32[i++] & 0x000000ff);
break;
case 0:
break;
default:
return -EFAULT;
}
return 0;
}
static int socfpga_fpga_ops_configure_complete(struct fpga_manager *mgr,
struct fpga_image_info *info)
{
struct socfpga_fpga_priv *priv = mgr->priv;
u32 status;
status = socfpga_fpga_wait_for_config_done(priv);
if (status)
return status;
socfpga_fpga_clr_bitsl(priv, SOCFPGA_FPGMGR_CTL_OFST,
SOCFPGA_FPGMGR_CTL_AXICFGEN);
if (socfpga_fpga_dclk_set_and_wait_clear(priv, 4))
return -ETIMEDOUT;
if (socfpga_fpga_wait_for_state(priv, SOCFPGA_FPGMGR_STAT_USER_MODE))
return -ETIMEDOUT;
socfpga_fpga_clr_bitsl(priv, SOCFPGA_FPGMGR_CTL_OFST,
SOCFPGA_FPGMGR_CTL_EN);
return 0;
}
static enum fpga_mgr_states socfpga_fpga_ops_state(struct fpga_manager *mgr)
{
struct socfpga_fpga_priv *priv = mgr->priv;
enum fpga_mgr_states ret;
u32 state;
state = socfpga_fpga_state_get(priv);
if (state < ARRAY_SIZE(socfpga_state_to_framework_state))
ret = socfpga_state_to_framework_state[state];
else
ret = FPGA_MGR_STATE_UNKNOWN;
return ret;
}
static int socfpga_fpga_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct socfpga_fpga_priv *priv;
struct resource *res;
int ret;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->fpga_base_addr = devm_ioremap_resource(dev, res);
if (IS_ERR(priv->fpga_base_addr))
return PTR_ERR(priv->fpga_base_addr);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
priv->fpga_data_addr = devm_ioremap_resource(dev, res);
if (IS_ERR(priv->fpga_data_addr))
return PTR_ERR(priv->fpga_data_addr);
priv->irq = platform_get_irq(pdev, 0);
if (priv->irq < 0)
return priv->irq;
ret = devm_request_irq(dev, priv->irq, socfpga_fpga_isr, 0,
dev_name(dev), priv);
if (ret)
return ret;
return fpga_mgr_register(dev, "Altera SOCFPGA FPGA Manager",
&socfpga_fpga_ops, priv);
}
static int socfpga_fpga_remove(struct platform_device *pdev)
{
fpga_mgr_unregister(&pdev->dev);
return 0;
}
