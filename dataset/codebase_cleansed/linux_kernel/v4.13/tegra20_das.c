static inline void tegra20_das_write(u32 reg, u32 val)
{
regmap_write(das->regmap, reg, val);
}
static inline u32 tegra20_das_read(u32 reg)
{
u32 val;
regmap_read(das->regmap, reg, &val);
return val;
}
int tegra20_das_connect_dap_to_dac(int dap, int dac)
{
u32 addr;
u32 reg;
if (!das)
return -ENODEV;
addr = TEGRA20_DAS_DAP_CTRL_SEL +
(dap * TEGRA20_DAS_DAP_CTRL_SEL_STRIDE);
reg = dac << TEGRA20_DAS_DAP_CTRL_SEL_DAP_CTRL_SEL_P;
tegra20_das_write(addr, reg);
return 0;
}
int tegra20_das_connect_dap_to_dap(int dap, int otherdap, int master,
int sdata1rx, int sdata2rx)
{
u32 addr;
u32 reg;
if (!das)
return -ENODEV;
addr = TEGRA20_DAS_DAP_CTRL_SEL +
(dap * TEGRA20_DAS_DAP_CTRL_SEL_STRIDE);
reg = otherdap << TEGRA20_DAS_DAP_CTRL_SEL_DAP_CTRL_SEL_P |
!!sdata2rx << TEGRA20_DAS_DAP_CTRL_SEL_DAP_SDATA2_TX_RX_P |
!!sdata1rx << TEGRA20_DAS_DAP_CTRL_SEL_DAP_SDATA1_TX_RX_P |
!!master << TEGRA20_DAS_DAP_CTRL_SEL_DAP_MS_SEL_P;
tegra20_das_write(addr, reg);
return 0;
}
int tegra20_das_connect_dac_to_dap(int dac, int dap)
{
u32 addr;
u32 reg;
if (!das)
return -ENODEV;
addr = TEGRA20_DAS_DAC_INPUT_DATA_CLK_SEL +
(dac * TEGRA20_DAS_DAC_INPUT_DATA_CLK_SEL_STRIDE);
reg = dap << TEGRA20_DAS_DAC_INPUT_DATA_CLK_SEL_DAC_CLK_SEL_P |
dap << TEGRA20_DAS_DAC_INPUT_DATA_CLK_SEL_DAC_SDATA1_SEL_P |
dap << TEGRA20_DAS_DAC_INPUT_DATA_CLK_SEL_DAC_SDATA2_SEL_P;
tegra20_das_write(addr, reg);
return 0;
}
static bool tegra20_das_wr_rd_reg(struct device *dev, unsigned int reg)
{
if ((reg >= TEGRA20_DAS_DAP_CTRL_SEL) &&
(reg <= LAST_REG(DAP_CTRL_SEL)))
return true;
if ((reg >= TEGRA20_DAS_DAC_INPUT_DATA_CLK_SEL) &&
(reg <= LAST_REG(DAC_INPUT_DATA_CLK_SEL)))
return true;
return false;
}
static int tegra20_das_probe(struct platform_device *pdev)
{
struct resource *res;
void __iomem *regs;
int ret = 0;
if (das)
return -ENODEV;
das = devm_kzalloc(&pdev->dev, sizeof(struct tegra20_das), GFP_KERNEL);
if (!das) {
ret = -ENOMEM;
goto err;
}
das->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(regs)) {
ret = PTR_ERR(regs);
goto err;
}
das->regmap = devm_regmap_init_mmio(&pdev->dev, regs,
&tegra20_das_regmap_config);
if (IS_ERR(das->regmap)) {
dev_err(&pdev->dev, "regmap init failed\n");
ret = PTR_ERR(das->regmap);
goto err;
}
ret = tegra20_das_connect_dap_to_dac(TEGRA20_DAS_DAP_ID_1,
TEGRA20_DAS_DAP_SEL_DAC1);
if (ret) {
dev_err(&pdev->dev, "Can't set up DAS DAP connection\n");
goto err;
}
ret = tegra20_das_connect_dac_to_dap(TEGRA20_DAS_DAC_ID_1,
TEGRA20_DAS_DAC_SEL_DAP1);
if (ret) {
dev_err(&pdev->dev, "Can't set up DAS DAC connection\n");
goto err;
}
ret = tegra20_das_connect_dap_to_dac(TEGRA20_DAS_DAP_ID_3,
TEGRA20_DAS_DAP_SEL_DAC3);
if (ret) {
dev_err(&pdev->dev, "Can't set up DAS DAP connection\n");
goto err;
}
ret = tegra20_das_connect_dac_to_dap(TEGRA20_DAS_DAC_ID_3,
TEGRA20_DAS_DAC_SEL_DAP3);
if (ret) {
dev_err(&pdev->dev, "Can't set up DAS DAC connection\n");
goto err;
}
platform_set_drvdata(pdev, das);
return 0;
err:
das = NULL;
return ret;
}
static int tegra20_das_remove(struct platform_device *pdev)
{
if (!das)
return -ENODEV;
das = NULL;
return 0;
}
