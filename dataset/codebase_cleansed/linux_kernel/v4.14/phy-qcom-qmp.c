static inline void qphy_setbits(void __iomem *base, u32 offset, u32 val)
{
u32 reg;
reg = readl(base + offset);
reg |= val;
writel(reg, base + offset);
readl(base + offset);
}
static inline void qphy_clrbits(void __iomem *base, u32 offset, u32 val)
{
u32 reg;
reg = readl(base + offset);
reg &= ~val;
writel(reg, base + offset);
readl(base + offset);
}
static void qcom_qmp_phy_configure(void __iomem *base,
const unsigned int *regs,
const struct qmp_phy_init_tbl tbl[],
int num)
{
int i;
const struct qmp_phy_init_tbl *t = tbl;
if (!t)
return;
for (i = 0; i < num; i++, t++) {
if (t->in_layout)
writel(t->val, base + regs[t->offset]);
else
writel(t->val, base + t->offset);
}
}
static int qcom_qmp_phy_poweron(struct phy *phy)
{
struct qmp_phy *qphy = phy_get_drvdata(phy);
struct qcom_qmp *qmp = qphy->qmp;
int num = qmp->cfg->num_vregs;
int ret;
dev_vdbg(&phy->dev, "Powering on QMP phy\n");
ret = regulator_bulk_enable(num, qmp->vregs);
if (ret) {
dev_err(qmp->dev, "failed to enable regulators, err=%d\n", ret);
return ret;
}
ret = clk_prepare_enable(qphy->pipe_clk);
if (ret) {
dev_err(qmp->dev, "pipe_clk enable failed, err=%d\n", ret);
regulator_bulk_disable(num, qmp->vregs);
return ret;
}
return 0;
}
static int qcom_qmp_phy_poweroff(struct phy *phy)
{
struct qmp_phy *qphy = phy_get_drvdata(phy);
struct qcom_qmp *qmp = qphy->qmp;
clk_disable_unprepare(qphy->pipe_clk);
regulator_bulk_disable(qmp->cfg->num_vregs, qmp->vregs);
return 0;
}
static int qcom_qmp_phy_com_init(struct qcom_qmp *qmp)
{
const struct qmp_phy_cfg *cfg = qmp->cfg;
void __iomem *serdes = qmp->serdes;
int ret, i;
mutex_lock(&qmp->phy_mutex);
if (qmp->init_count++) {
mutex_unlock(&qmp->phy_mutex);
return 0;
}
for (i = 0; i < cfg->num_resets; i++) {
ret = reset_control_deassert(qmp->resets[i]);
if (ret) {
dev_err(qmp->dev, "%s reset deassert failed\n",
qmp->cfg->reset_list[i]);
goto err_rst;
}
}
if (cfg->has_phy_com_ctrl)
qphy_setbits(serdes, cfg->regs[QPHY_COM_POWER_DOWN_CONTROL],
SW_PWRDN);
qcom_qmp_phy_configure(serdes, cfg->regs, cfg->serdes_tbl,
cfg->serdes_tbl_num);
if (cfg->has_phy_com_ctrl) {
void __iomem *status;
unsigned int mask, val;
qphy_clrbits(serdes, cfg->regs[QPHY_COM_SW_RESET], SW_RESET);
qphy_setbits(serdes, cfg->regs[QPHY_COM_START_CONTROL],
SERDES_START | PCS_START);
status = serdes + cfg->regs[QPHY_COM_PCS_READY_STATUS];
mask = cfg->mask_com_pcs_ready;
ret = readl_poll_timeout(status, val, (val & mask), 10,
PHY_INIT_COMPLETE_TIMEOUT);
if (ret) {
dev_err(qmp->dev,
"phy common block init timed-out\n");
goto err_rst;
}
}
mutex_unlock(&qmp->phy_mutex);
return 0;
err_rst:
while (--i >= 0)
reset_control_assert(qmp->resets[i]);
mutex_unlock(&qmp->phy_mutex);
return ret;
}
static int qcom_qmp_phy_com_exit(struct qcom_qmp *qmp)
{
const struct qmp_phy_cfg *cfg = qmp->cfg;
void __iomem *serdes = qmp->serdes;
int i = cfg->num_resets;
mutex_lock(&qmp->phy_mutex);
if (--qmp->init_count) {
mutex_unlock(&qmp->phy_mutex);
return 0;
}
if (cfg->has_phy_com_ctrl) {
qphy_setbits(serdes, cfg->regs[QPHY_COM_START_CONTROL],
SERDES_START | PCS_START);
qphy_clrbits(serdes, cfg->regs[QPHY_COM_SW_RESET],
SW_RESET);
qphy_setbits(serdes, cfg->regs[QPHY_COM_POWER_DOWN_CONTROL],
SW_PWRDN);
}
while (--i >= 0)
reset_control_assert(qmp->resets[i]);
mutex_unlock(&qmp->phy_mutex);
return 0;
}
static int qcom_qmp_phy_init(struct phy *phy)
{
struct qmp_phy *qphy = phy_get_drvdata(phy);
struct qcom_qmp *qmp = qphy->qmp;
const struct qmp_phy_cfg *cfg = qmp->cfg;
void __iomem *tx = qphy->tx;
void __iomem *rx = qphy->rx;
void __iomem *pcs = qphy->pcs;
void __iomem *status;
unsigned int mask, val;
int ret, i;
dev_vdbg(qmp->dev, "Initializing QMP phy\n");
for (i = 0; i < qmp->cfg->num_clks; i++) {
ret = clk_prepare_enable(qmp->clks[i]);
if (ret) {
dev_err(qmp->dev, "failed to enable %s clk, err=%d\n",
qmp->cfg->clk_list[i], ret);
goto err_clk;
}
}
ret = qcom_qmp_phy_com_init(qmp);
if (ret)
goto err_clk;
if (cfg->has_lane_rst) {
ret = reset_control_deassert(qphy->lane_rst);
if (ret) {
dev_err(qmp->dev, "lane%d reset deassert failed\n",
qphy->index);
goto err_lane_rst;
}
}
qcom_qmp_phy_configure(tx, cfg->regs, cfg->tx_tbl, cfg->tx_tbl_num);
qcom_qmp_phy_configure(rx, cfg->regs, cfg->rx_tbl, cfg->rx_tbl_num);
qcom_qmp_phy_configure(pcs, cfg->regs, cfg->pcs_tbl, cfg->pcs_tbl_num);
qphy_setbits(pcs, QPHY_POWER_DOWN_CONTROL, cfg->pwrdn_ctrl);
if (cfg->has_pwrdn_delay)
usleep_range(cfg->pwrdn_delay_min, cfg->pwrdn_delay_max);
qphy_setbits(pcs, cfg->regs[QPHY_START_CTRL], cfg->start_ctrl);
qphy_clrbits(pcs, cfg->regs[QPHY_SW_RESET], SW_RESET);
status = pcs + cfg->regs[QPHY_PCS_READY_STATUS];
mask = cfg->mask_pcs_ready;
ret = readl_poll_timeout(status, val, !(val & mask), 1,
PHY_INIT_COMPLETE_TIMEOUT);
if (ret) {
dev_err(qmp->dev, "phy initialization timed-out\n");
goto err_pcs_ready;
}
return ret;
err_pcs_ready:
if (cfg->has_lane_rst)
reset_control_assert(qphy->lane_rst);
err_lane_rst:
qcom_qmp_phy_com_exit(qmp);
err_clk:
while (--i >= 0)
clk_disable_unprepare(qmp->clks[i]);
return ret;
}
static int qcom_qmp_phy_exit(struct phy *phy)
{
struct qmp_phy *qphy = phy_get_drvdata(phy);
struct qcom_qmp *qmp = qphy->qmp;
const struct qmp_phy_cfg *cfg = qmp->cfg;
int i = cfg->num_clks;
qphy_setbits(qphy->pcs, cfg->regs[QPHY_SW_RESET], SW_RESET);
qphy_clrbits(qphy->pcs, cfg->regs[QPHY_START_CTRL], cfg->start_ctrl);
qphy_clrbits(qphy->pcs, QPHY_POWER_DOWN_CONTROL, cfg->pwrdn_ctrl);
if (cfg->has_lane_rst)
reset_control_assert(qphy->lane_rst);
qcom_qmp_phy_com_exit(qmp);
while (--i >= 0)
clk_disable_unprepare(qmp->clks[i]);
return 0;
}
static int qcom_qmp_phy_vreg_init(struct device *dev)
{
struct qcom_qmp *qmp = dev_get_drvdata(dev);
int num = qmp->cfg->num_vregs;
int i;
qmp->vregs = devm_kcalloc(dev, num, sizeof(*qmp->vregs), GFP_KERNEL);
if (!qmp->vregs)
return -ENOMEM;
for (i = 0; i < num; i++)
qmp->vregs[i].supply = qmp->cfg->vreg_list[i];
return devm_regulator_bulk_get(dev, num, qmp->vregs);
}
static int qcom_qmp_phy_reset_init(struct device *dev)
{
struct qcom_qmp *qmp = dev_get_drvdata(dev);
int i;
qmp->resets = devm_kcalloc(dev, qmp->cfg->num_resets,
sizeof(*qmp->resets), GFP_KERNEL);
if (!qmp->resets)
return -ENOMEM;
for (i = 0; i < qmp->cfg->num_resets; i++) {
struct reset_control *rst;
const char *name = qmp->cfg->reset_list[i];
rst = devm_reset_control_get(dev, name);
if (IS_ERR(rst)) {
dev_err(dev, "failed to get %s reset\n", name);
return PTR_ERR(rst);
}
qmp->resets[i] = rst;
}
return 0;
}
static int qcom_qmp_phy_clk_init(struct device *dev)
{
struct qcom_qmp *qmp = dev_get_drvdata(dev);
int ret, i;
qmp->clks = devm_kcalloc(dev, qmp->cfg->num_clks,
sizeof(*qmp->clks), GFP_KERNEL);
if (!qmp->clks)
return -ENOMEM;
for (i = 0; i < qmp->cfg->num_clks; i++) {
struct clk *_clk;
const char *name = qmp->cfg->clk_list[i];
_clk = devm_clk_get(dev, name);
if (IS_ERR(_clk)) {
ret = PTR_ERR(_clk);
if (ret != -EPROBE_DEFER)
dev_err(dev, "failed to get %s clk, %d\n",
name, ret);
return ret;
}
qmp->clks[i] = _clk;
}
return 0;
}
static int phy_pipe_clk_register(struct qcom_qmp *qmp, struct device_node *np)
{
struct clk_fixed_rate *fixed;
struct clk_init_data init = { };
int ret;
if ((qmp->cfg->type != PHY_TYPE_USB3) &&
(qmp->cfg->type != PHY_TYPE_PCIE)) {
return 0;
}
ret = of_property_read_string(np, "clock-output-names", &init.name);
if (ret) {
dev_err(qmp->dev, "%s: No clock-output-names\n", np->name);
return ret;
}
fixed = devm_kzalloc(qmp->dev, sizeof(*fixed), GFP_KERNEL);
if (!fixed)
return -ENOMEM;
init.ops = &clk_fixed_rate_ops;
fixed->fixed_rate = 125000000;
fixed->hw.init = &init;
return devm_clk_hw_register(qmp->dev, &fixed->hw);
}
static
int qcom_qmp_phy_create(struct device *dev, struct device_node *np, int id)
{
struct qcom_qmp *qmp = dev_get_drvdata(dev);
struct phy *generic_phy;
struct qmp_phy *qphy;
char prop_name[MAX_PROP_NAME];
int ret;
qphy = devm_kzalloc(dev, sizeof(*qphy), GFP_KERNEL);
if (!qphy)
return -ENOMEM;
qphy->tx = of_iomap(np, 0);
if (!qphy->tx)
return -ENOMEM;
qphy->rx = of_iomap(np, 1);
if (!qphy->rx)
return -ENOMEM;
qphy->pcs = of_iomap(np, 2);
if (!qphy->pcs)
return -ENOMEM;
snprintf(prop_name, sizeof(prop_name), "pipe%d", id);
qphy->pipe_clk = of_clk_get_by_name(np, prop_name);
if (IS_ERR(qphy->pipe_clk)) {
if (qmp->cfg->type == PHY_TYPE_PCIE ||
qmp->cfg->type == PHY_TYPE_USB3) {
ret = PTR_ERR(qphy->pipe_clk);
if (ret != -EPROBE_DEFER)
dev_err(dev,
"failed to get lane%d pipe_clk, %d\n",
id, ret);
return ret;
}
qphy->pipe_clk = NULL;
}
if (qmp->cfg->has_lane_rst) {
snprintf(prop_name, sizeof(prop_name), "lane%d", id);
qphy->lane_rst = of_reset_control_get(np, prop_name);
if (IS_ERR(qphy->lane_rst)) {
dev_err(dev, "failed to get lane%d reset\n", id);
return PTR_ERR(qphy->lane_rst);
}
}
generic_phy = devm_phy_create(dev, np, &qcom_qmp_phy_gen_ops);
if (IS_ERR(generic_phy)) {
ret = PTR_ERR(generic_phy);
dev_err(dev, "failed to create qphy %d\n", ret);
return ret;
}
qphy->phy = generic_phy;
qphy->index = id;
qphy->qmp = qmp;
qmp->phys[id] = qphy;
phy_set_drvdata(generic_phy, qphy);
return 0;
}
static int qcom_qmp_phy_probe(struct platform_device *pdev)
{
struct qcom_qmp *qmp;
struct device *dev = &pdev->dev;
struct resource *res;
struct device_node *child;
struct phy_provider *phy_provider;
void __iomem *base;
int num, id;
int ret;
qmp = devm_kzalloc(dev, sizeof(*qmp), GFP_KERNEL);
if (!qmp)
return -ENOMEM;
qmp->dev = dev;
dev_set_drvdata(dev, qmp);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
qmp->serdes = base;
mutex_init(&qmp->phy_mutex);
qmp->cfg = of_device_get_match_data(dev);
ret = qcom_qmp_phy_clk_init(dev);
if (ret)
return ret;
ret = qcom_qmp_phy_reset_init(dev);
if (ret)
return ret;
ret = qcom_qmp_phy_vreg_init(dev);
if (ret) {
dev_err(dev, "failed to get regulator supplies\n");
return ret;
}
num = of_get_available_child_count(dev->of_node);
if (num > qmp->cfg->nlanes)
return -EINVAL;
qmp->phys = devm_kcalloc(dev, num, sizeof(*qmp->phys), GFP_KERNEL);
if (!qmp->phys)
return -ENOMEM;
id = 0;
for_each_available_child_of_node(dev->of_node, child) {
ret = qcom_qmp_phy_create(dev, child, id);
if (ret) {
dev_err(dev, "failed to create lane%d phy, %d\n",
id, ret);
return ret;
}
ret = phy_pipe_clk_register(qmp, child);
if (ret) {
dev_err(qmp->dev,
"failed to register pipe clock source\n");
return ret;
}
id++;
}
phy_provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
if (!IS_ERR(phy_provider))
dev_info(dev, "Registered Qcom-QMP phy\n");
return PTR_ERR_OR_ZERO(phy_provider);
}
