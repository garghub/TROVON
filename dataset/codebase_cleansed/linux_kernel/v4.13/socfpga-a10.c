static bool socfpga_a10_fpga_writeable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case A10_FPGAMGR_DCLKCNT_OFST:
case A10_FPGAMGR_DCLKSTAT_OFST:
case A10_FPGAMGR_IMGCFG_CTL_00_OFST:
case A10_FPGAMGR_IMGCFG_CTL_01_OFST:
case A10_FPGAMGR_IMGCFG_CTL_02_OFST:
return true;
}
return false;
}
static bool socfpga_a10_fpga_readable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case A10_FPGAMGR_DCLKCNT_OFST:
case A10_FPGAMGR_DCLKSTAT_OFST:
case A10_FPGAMGR_IMGCFG_CTL_00_OFST:
case A10_FPGAMGR_IMGCFG_CTL_01_OFST:
case A10_FPGAMGR_IMGCFG_CTL_02_OFST:
case A10_FPGAMGR_IMGCFG_STAT_OFST:
return true;
}
return false;
}
static void socfpga_a10_fpga_set_cfg_width(struct a10_fpga_priv *priv,
int width)
{
width <<= A10_FPGAMGR_IMGCFG_CTL_02_CFGWIDTH_SHIFT;
regmap_update_bits(priv->regmap, A10_FPGAMGR_IMGCFG_CTL_02_OFST,
A10_FPGAMGR_IMGCFG_CTL_02_CFGWIDTH, width);
}
static void socfpga_a10_fpga_generate_dclks(struct a10_fpga_priv *priv,
u32 count)
{
u32 val;
regmap_write(priv->regmap, A10_FPGAMGR_DCLKSTAT_OFST,
A10_FPGAMGR_DCLKSTAT_DCLKDONE);
regmap_write(priv->regmap, A10_FPGAMGR_DCLKCNT_OFST, count);
regmap_read_poll_timeout(priv->regmap, A10_FPGAMGR_DCLKSTAT_OFST, val,
val, 1, 100);
regmap_write(priv->regmap, A10_FPGAMGR_DCLKSTAT_OFST,
A10_FPGAMGR_DCLKSTAT_DCLKDONE);
}
static int socfpga_a10_fpga_encrypted(u32 *buf32, size_t buf32_size)
{
if (buf32_size < RBF_ENCRYPTION_MODE_OFFSET + 1)
return -EINVAL;
return ((buf32[RBF_ENCRYPTION_MODE_OFFSET] >> 2) & 3) != 0;
}
static int socfpga_a10_fpga_compressed(u32 *buf32, size_t buf32_size)
{
if (buf32_size < RBF_DECOMPRESS_OFFSET + 1)
return -EINVAL;
return !((buf32[RBF_DECOMPRESS_OFFSET] >> 1) & 1);
}
static unsigned int socfpga_a10_fpga_get_cd_ratio(unsigned int cfg_width,
bool encrypt, bool compress)
{
unsigned int cd_ratio;
if (!compress && !encrypt)
return CDRATIO_x1;
if (compress)
cd_ratio = CDRATIO_x4;
else
cd_ratio = CDRATIO_x2;
if (cfg_width == CFGWDTH_32)
cd_ratio += 1;
return cd_ratio;
}
static int socfpga_a10_fpga_set_cdratio(struct fpga_manager *mgr,
unsigned int cfg_width,
const char *buf, size_t count)
{
struct a10_fpga_priv *priv = mgr->priv;
unsigned int cd_ratio;
int encrypt, compress;
encrypt = socfpga_a10_fpga_encrypted((u32 *)buf, count / 4);
if (encrypt < 0)
return -EINVAL;
compress = socfpga_a10_fpga_compressed((u32 *)buf, count / 4);
if (compress < 0)
return -EINVAL;
cd_ratio = socfpga_a10_fpga_get_cd_ratio(cfg_width, encrypt, compress);
regmap_update_bits(priv->regmap, A10_FPGAMGR_IMGCFG_CTL_02_OFST,
A10_FPGAMGR_IMGCFG_CTL_02_CDRATIO_MASK,
cd_ratio << A10_FPGAMGR_IMGCFG_CTL_02_CDRATIO_SHIFT);
return 0;
}
static u32 socfpga_a10_fpga_read_stat(struct a10_fpga_priv *priv)
{
u32 val;
regmap_read(priv->regmap, A10_FPGAMGR_IMGCFG_STAT_OFST, &val);
return val;
}
static int socfpga_a10_fpga_wait_for_pr_ready(struct a10_fpga_priv *priv)
{
u32 reg, i;
for (i = 0; i < 10 ; i++) {
reg = socfpga_a10_fpga_read_stat(priv);
if (reg & A10_FPGAMGR_IMGCFG_STAT_F2S_PR_ERROR)
return -EINVAL;
if (reg & A10_FPGAMGR_IMGCFG_STAT_F2S_PR_READY)
return 0;
}
return -ETIMEDOUT;
}
static int socfpga_a10_fpga_wait_for_pr_done(struct a10_fpga_priv *priv)
{
u32 reg, i;
for (i = 0; i < 10 ; i++) {
reg = socfpga_a10_fpga_read_stat(priv);
if (reg & A10_FPGAMGR_IMGCFG_STAT_F2S_PR_ERROR)
return -EINVAL;
if (reg & A10_FPGAMGR_IMGCFG_STAT_F2S_PR_DONE)
return 0;
}
return -ETIMEDOUT;
}
static int socfpga_a10_fpga_write_init(struct fpga_manager *mgr,
struct fpga_image_info *info,
const char *buf, size_t count)
{
struct a10_fpga_priv *priv = mgr->priv;
unsigned int cfg_width;
u32 msel, stat, mask;
int ret;
if (info->flags & FPGA_MGR_PARTIAL_RECONFIG)
cfg_width = CFGWDTH_16;
else
return -EINVAL;
msel = socfpga_a10_fpga_read_stat(priv);
msel &= A10_FPGAMGR_IMGCFG_STAT_F2S_MSEL_MASK;
msel >>= A10_FPGAMGR_IMGCFG_STAT_F2S_MSEL_SHIFT;
if ((msel != 0) && (msel != 1)) {
dev_dbg(&mgr->dev, "Fail: invalid msel=%d\n", msel);
return -EINVAL;
}
stat = socfpga_a10_fpga_read_stat(priv);
mask = A10_FPGAMGR_IMGCFG_STAT_F2S_NCONFIG_PIN |
A10_FPGAMGR_IMGCFG_STAT_F2S_NSTATUS_PIN;
if ((stat & mask) != mask)
return -EINVAL;
socfpga_a10_fpga_set_cfg_width(priv, cfg_width);
ret = socfpga_a10_fpga_set_cdratio(mgr, cfg_width, buf, count);
if (ret)
return ret;
regmap_write(priv->regmap, A10_FPGAMGR_IMGCFG_CTL_01_OFST,
A10_FPGAMGR_IMGCFG_CTL_01_S2F_NENABLE_CONFIG);
regmap_update_bits(priv->regmap, A10_FPGAMGR_IMGCFG_CTL_02_OFST,
A10_FPGAMGR_IMGCFG_CTL_02_EN_CFG_CTRL,
A10_FPGAMGR_IMGCFG_CTL_02_EN_CFG_CTRL);
regmap_write(priv->regmap, A10_FPGAMGR_IMGCFG_CTL_00_OFST,
A10_FPGAMGR_IMGCFG_CTL_00_S2F_NENABLE_NCONFIG |
A10_FPGAMGR_IMGCFG_CTL_00_S2F_NENABLE_NSTATUS |
A10_FPGAMGR_IMGCFG_CTL_00_S2F_NENABLE_CONDONE |
A10_FPGAMGR_IMGCFG_CTL_00_S2F_NCONFIG);
regmap_update_bits(priv->regmap, A10_FPGAMGR_IMGCFG_CTL_01_OFST,
A10_FPGAMGR_IMGCFG_CTL_01_S2F_NENABLE_CONFIG, 0);
socfpga_a10_fpga_generate_dclks(priv, 256);
regmap_update_bits(priv->regmap, A10_FPGAMGR_IMGCFG_CTL_01_OFST,
A10_FPGAMGR_IMGCFG_CTL_01_S2F_PR_REQUEST,
A10_FPGAMGR_IMGCFG_CTL_01_S2F_PR_REQUEST);
socfpga_a10_fpga_generate_dclks(priv, 0x7ff);
return socfpga_a10_fpga_wait_for_pr_ready(priv);
}
static int socfpga_a10_fpga_write(struct fpga_manager *mgr, const char *buf,
size_t count)
{
struct a10_fpga_priv *priv = mgr->priv;
u32 *buffer_32 = (u32 *)buf;
size_t i = 0;
if (count <= 0)
return -EINVAL;
while (count >= sizeof(u32)) {
writel(buffer_32[i++], priv->fpga_data_addr);
count -= sizeof(u32);
}
switch (count) {
case 3:
writel(buffer_32[i++] & 0x00ffffff, priv->fpga_data_addr);
break;
case 2:
writel(buffer_32[i++] & 0x0000ffff, priv->fpga_data_addr);
break;
case 1:
writel(buffer_32[i++] & 0x000000ff, priv->fpga_data_addr);
break;
case 0:
break;
default:
return -EFAULT;
}
return 0;
}
static int socfpga_a10_fpga_write_complete(struct fpga_manager *mgr,
struct fpga_image_info *info)
{
struct a10_fpga_priv *priv = mgr->priv;
u32 reg;
int ret;
ret = socfpga_a10_fpga_wait_for_pr_done(priv);
regmap_update_bits(priv->regmap, A10_FPGAMGR_IMGCFG_CTL_01_OFST,
A10_FPGAMGR_IMGCFG_CTL_01_S2F_PR_REQUEST, 0);
socfpga_a10_fpga_generate_dclks(priv, 256);
regmap_update_bits(priv->regmap, A10_FPGAMGR_IMGCFG_CTL_02_OFST,
A10_FPGAMGR_IMGCFG_CTL_02_EN_CFG_CTRL, 0);
regmap_update_bits(priv->regmap, A10_FPGAMGR_IMGCFG_CTL_01_OFST,
A10_FPGAMGR_IMGCFG_CTL_01_S2F_NCE,
A10_FPGAMGR_IMGCFG_CTL_01_S2F_NCE);
regmap_update_bits(priv->regmap, A10_FPGAMGR_IMGCFG_CTL_01_OFST,
A10_FPGAMGR_IMGCFG_CTL_01_S2F_NENABLE_CONFIG,
A10_FPGAMGR_IMGCFG_CTL_01_S2F_NENABLE_CONFIG);
if (ret)
return ret;
reg = socfpga_a10_fpga_read_stat(priv);
if (((reg & A10_FPGAMGR_IMGCFG_STAT_F2S_USERMODE) == 0) ||
((reg & A10_FPGAMGR_IMGCFG_STAT_F2S_CONDONE_PIN) == 0) ||
((reg & A10_FPGAMGR_IMGCFG_STAT_F2S_NSTATUS_PIN) == 0)) {
dev_dbg(&mgr->dev,
"Timeout in final check. Status=%08xf\n", reg);
return -ETIMEDOUT;
}
return 0;
}
static enum fpga_mgr_states socfpga_a10_fpga_state(struct fpga_manager *mgr)
{
struct a10_fpga_priv *priv = mgr->priv;
u32 reg = socfpga_a10_fpga_read_stat(priv);
if (reg & A10_FPGAMGR_IMGCFG_STAT_F2S_USERMODE)
return FPGA_MGR_STATE_OPERATING;
if (reg & A10_FPGAMGR_IMGCFG_STAT_F2S_PR_READY)
return FPGA_MGR_STATE_WRITE;
if (reg & A10_FPGAMGR_IMGCFG_STAT_F2S_CRC_ERROR)
return FPGA_MGR_STATE_WRITE_COMPLETE_ERR;
if ((reg & A10_FPGAMGR_IMGCFG_STAT_F2S_NSTATUS_PIN) == 0)
return FPGA_MGR_STATE_RESET;
return FPGA_MGR_STATE_UNKNOWN;
}
static int socfpga_a10_fpga_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct a10_fpga_priv *priv;
void __iomem *reg_base;
struct resource *res;
int ret;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reg_base = devm_ioremap_resource(dev, res);
if (IS_ERR(reg_base))
return PTR_ERR(reg_base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
priv->fpga_data_addr = devm_ioremap_resource(dev, res);
if (IS_ERR(priv->fpga_data_addr))
return PTR_ERR(priv->fpga_data_addr);
priv->regmap = devm_regmap_init_mmio(dev, reg_base,
&socfpga_a10_fpga_regmap_config);
if (IS_ERR(priv->regmap))
return -ENODEV;
priv->clk = devm_clk_get(dev, NULL);
if (IS_ERR(priv->clk)) {
dev_err(dev, "no clock specified\n");
return PTR_ERR(priv->clk);
}
ret = clk_prepare_enable(priv->clk);
if (ret) {
dev_err(dev, "could not enable clock\n");
return -EBUSY;
}
return fpga_mgr_register(dev, "SoCFPGA Arria10 FPGA Manager",
&socfpga_a10_fpga_mgr_ops, priv);
}
static int socfpga_a10_fpga_remove(struct platform_device *pdev)
{
struct fpga_manager *mgr = platform_get_drvdata(pdev);
struct a10_fpga_priv *priv = mgr->priv;
fpga_mgr_unregister(&pdev->dev);
clk_disable_unprepare(priv->clk);
return 0;
}
