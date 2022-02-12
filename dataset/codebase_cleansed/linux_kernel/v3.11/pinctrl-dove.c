static int dove_pmu_mpp_ctrl_get(struct mvebu_mpp_ctrl *ctrl,
unsigned long *config)
{
unsigned off = (ctrl->pid / MPPS_PER_REG) * MPP_BITS;
unsigned shift = (ctrl->pid % MPPS_PER_REG) * MPP_BITS;
unsigned long pmu = readl(DOVE_PMU_MPP_GENERAL_CTRL);
unsigned long func;
if (pmu & (1 << ctrl->pid)) {
func = readl(DOVE_PMU_SIGNAL_SELECT_0 + off);
*config = (func >> shift) & MPP_MASK;
*config |= CONFIG_PMU;
} else {
func = readl(DOVE_MPP_VIRT_BASE + off);
*config = (func >> shift) & MPP_MASK;
}
return 0;
}
static int dove_pmu_mpp_ctrl_set(struct mvebu_mpp_ctrl *ctrl,
unsigned long config)
{
unsigned off = (ctrl->pid / MPPS_PER_REG) * MPP_BITS;
unsigned shift = (ctrl->pid % MPPS_PER_REG) * MPP_BITS;
unsigned long pmu = readl(DOVE_PMU_MPP_GENERAL_CTRL);
unsigned long func;
if (config & CONFIG_PMU) {
writel(pmu | (1 << ctrl->pid), DOVE_PMU_MPP_GENERAL_CTRL);
func = readl(DOVE_PMU_SIGNAL_SELECT_0 + off);
func &= ~(MPP_MASK << shift);
func |= (config & MPP_MASK) << shift;
writel(func, DOVE_PMU_SIGNAL_SELECT_0 + off);
} else {
writel(pmu & ~(1 << ctrl->pid), DOVE_PMU_MPP_GENERAL_CTRL);
func = readl(DOVE_MPP_VIRT_BASE + off);
func &= ~(MPP_MASK << shift);
func |= (config & MPP_MASK) << shift;
writel(func, DOVE_MPP_VIRT_BASE + off);
}
return 0;
}
static int dove_mpp4_ctrl_get(struct mvebu_mpp_ctrl *ctrl,
unsigned long *config)
{
unsigned long mpp4 = readl(DOVE_MPP_CTRL4_VIRT_BASE);
unsigned long mask;
switch (ctrl->pid) {
case 24:
mask = DOVE_CAM_GPIO_SEL;
break;
case 40:
mask = DOVE_SD0_GPIO_SEL;
break;
case 46:
mask = DOVE_SD1_GPIO_SEL;
break;
case 58:
mask = DOVE_SPI_GPIO_SEL;
break;
case 62:
mask = DOVE_UART1_GPIO_SEL;
break;
default:
return -EINVAL;
}
*config = ((mpp4 & mask) != 0);
return 0;
}
static int dove_mpp4_ctrl_set(struct mvebu_mpp_ctrl *ctrl,
unsigned long config)
{
unsigned long mpp4 = readl(DOVE_MPP_CTRL4_VIRT_BASE);
unsigned long mask;
switch (ctrl->pid) {
case 24:
mask = DOVE_CAM_GPIO_SEL;
break;
case 40:
mask = DOVE_SD0_GPIO_SEL;
break;
case 46:
mask = DOVE_SD1_GPIO_SEL;
break;
case 58:
mask = DOVE_SPI_GPIO_SEL;
break;
case 62:
mask = DOVE_UART1_GPIO_SEL;
break;
default:
return -EINVAL;
}
mpp4 &= ~mask;
if (config)
mpp4 |= mask;
writel(mpp4, DOVE_MPP_CTRL4_VIRT_BASE);
return 0;
}
static int dove_nand_ctrl_get(struct mvebu_mpp_ctrl *ctrl,
unsigned long *config)
{
unsigned long gmpp = readl(DOVE_MPP_GENERAL_VIRT_BASE);
*config = ((gmpp & DOVE_NAND_GPIO_EN) != 0);
return 0;
}
static int dove_nand_ctrl_set(struct mvebu_mpp_ctrl *ctrl,
unsigned long config)
{
unsigned long gmpp = readl(DOVE_MPP_GENERAL_VIRT_BASE);
gmpp &= ~DOVE_NAND_GPIO_EN;
if (config)
gmpp |= DOVE_NAND_GPIO_EN;
writel(gmpp, DOVE_MPP_GENERAL_VIRT_BASE);
return 0;
}
static int dove_audio0_ctrl_get(struct mvebu_mpp_ctrl *ctrl,
unsigned long *config)
{
unsigned long pmu = readl(DOVE_PMU_MPP_GENERAL_CTRL);
*config = ((pmu & DOVE_AU0_AC97_SEL) != 0);
return 0;
}
static int dove_audio0_ctrl_set(struct mvebu_mpp_ctrl *ctrl,
unsigned long config)
{
unsigned long pmu = readl(DOVE_PMU_MPP_GENERAL_CTRL);
pmu &= ~DOVE_AU0_AC97_SEL;
if (config)
pmu |= DOVE_AU0_AC97_SEL;
writel(pmu, DOVE_PMU_MPP_GENERAL_CTRL);
return 0;
}
static int dove_audio1_ctrl_get(struct mvebu_mpp_ctrl *ctrl,
unsigned long *config)
{
unsigned long mpp4 = readl(DOVE_MPP_CTRL4_VIRT_BASE);
unsigned long sspc1 = readl(DOVE_SSP_CTRL_STATUS_1);
unsigned long gmpp = readl(DOVE_MPP_GENERAL_VIRT_BASE);
unsigned long gcfg2 = readl(DOVE_GLOBAL_CONFIG_2);
*config = 0;
if (mpp4 & DOVE_AU1_GPIO_SEL)
*config |= BIT(3);
if (sspc1 & DOVE_SSP_ON_AU1)
*config |= BIT(2);
if (gmpp & DOVE_AU1_SPDIFO_GPIO_EN)
*config |= BIT(1);
if (gcfg2 & DOVE_TWSI_OPTION3_GPIO)
*config |= BIT(0);
if ((*config & BIT(3)) == 0)
*config &= ~(BIT(2) | BIT(0));
if ((*config & BIT(1)) == 0)
*config &= ~BIT(0);
return 0;
}
static int dove_audio1_ctrl_set(struct mvebu_mpp_ctrl *ctrl,
unsigned long config)
{
unsigned long mpp4 = readl(DOVE_MPP_CTRL4_VIRT_BASE);
unsigned long sspc1 = readl(DOVE_SSP_CTRL_STATUS_1);
unsigned long gmpp = readl(DOVE_MPP_GENERAL_VIRT_BASE);
unsigned long gcfg2 = readl(DOVE_GLOBAL_CONFIG_2);
gcfg2 &= ~DOVE_TWSI_OPTION3_GPIO;
gmpp &= ~DOVE_AU1_SPDIFO_GPIO_EN;
sspc1 &= ~DOVE_SSP_ON_AU1;
mpp4 &= ~DOVE_AU1_GPIO_SEL;
if (config & BIT(0))
gcfg2 |= DOVE_TWSI_OPTION3_GPIO;
if (config & BIT(1))
gmpp |= DOVE_AU1_SPDIFO_GPIO_EN;
if (config & BIT(2))
sspc1 |= DOVE_SSP_ON_AU1;
if (config & BIT(3))
mpp4 |= DOVE_AU1_GPIO_SEL;
writel(mpp4, DOVE_MPP_CTRL4_VIRT_BASE);
writel(sspc1, DOVE_SSP_CTRL_STATUS_1);
writel(gmpp, DOVE_MPP_GENERAL_VIRT_BASE);
writel(gcfg2, DOVE_GLOBAL_CONFIG_2);
return 0;
}
static int dove_audio1_ctrl_gpio_req(struct mvebu_mpp_ctrl *ctrl, u8 pid)
{
unsigned long config;
dove_audio1_ctrl_get(ctrl, &config);
switch (config) {
case 0x02:
case 0x0e:
if (pid >= 56)
return 0;
return -ENOTSUPP;
case 0x08:
case 0x0b:
if (pid <= 55)
return 0;
return -ENOTSUPP;
case 0x0a:
return 0;
}
return -ENOTSUPP;
}
static int dove_audio1_ctrl_gpio_dir(struct mvebu_mpp_ctrl *ctrl, u8 pid,
bool input)
{
if (pid < 52 || pid > 57)
return -ENOTSUPP;
return 0;
}
static int dove_twsi_ctrl_get(struct mvebu_mpp_ctrl *ctrl,
unsigned long *config)
{
unsigned long gcfg1 = readl(DOVE_GLOBAL_CONFIG_1);
unsigned long gcfg2 = readl(DOVE_GLOBAL_CONFIG_2);
*config = 0;
if (gcfg1 & DOVE_TWSI_ENABLE_OPTION1)
*config = 1;
else if (gcfg2 & DOVE_TWSI_ENABLE_OPTION2)
*config = 2;
else if (gcfg2 & DOVE_TWSI_ENABLE_OPTION3)
*config = 3;
return 0;
}
static int dove_twsi_ctrl_set(struct mvebu_mpp_ctrl *ctrl,
unsigned long config)
{
unsigned long gcfg1 = readl(DOVE_GLOBAL_CONFIG_1);
unsigned long gcfg2 = readl(DOVE_GLOBAL_CONFIG_2);
gcfg1 &= ~DOVE_TWSI_ENABLE_OPTION1;
gcfg2 &= ~(DOVE_TWSI_ENABLE_OPTION2 | DOVE_TWSI_ENABLE_OPTION2);
switch (config) {
case 1:
gcfg1 |= DOVE_TWSI_ENABLE_OPTION1;
break;
case 2:
gcfg2 |= DOVE_TWSI_ENABLE_OPTION2;
break;
case 3:
gcfg2 |= DOVE_TWSI_ENABLE_OPTION3;
break;
}
writel(gcfg1, DOVE_GLOBAL_CONFIG_1);
writel(gcfg2, DOVE_GLOBAL_CONFIG_2);
return 0;
}
static int dove_pinctrl_probe(struct platform_device *pdev)
{
const struct of_device_id *match =
of_match_device(dove_pinctrl_of_match, &pdev->dev);
pdev->dev.platform_data = (void *)match->data;
clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "Unable to get pdma clock");
return PTR_RET(clk);
}
clk_prepare_enable(clk);
return mvebu_pinctrl_probe(pdev);
}
static int dove_pinctrl_remove(struct platform_device *pdev)
{
int ret;
ret = mvebu_pinctrl_remove(pdev);
if (!IS_ERR(clk))
clk_disable_unprepare(clk);
return ret;
}
