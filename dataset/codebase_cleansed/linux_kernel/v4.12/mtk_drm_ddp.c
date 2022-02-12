static unsigned int mtk_ddp_mout_en(enum mtk_ddp_comp_id cur,
enum mtk_ddp_comp_id next,
unsigned int *addr)
{
unsigned int value;
if (cur == DDP_COMPONENT_OVL0 && next == DDP_COMPONENT_COLOR0) {
*addr = DISP_REG_CONFIG_DISP_OVL0_MOUT_EN;
value = OVL0_MOUT_EN_COLOR0;
} else if (cur == DDP_COMPONENT_OVL0 && next == DDP_COMPONENT_RDMA0) {
*addr = DISP_REG_CONFIG_DISP_OVL_MOUT_EN;
value = OVL_MOUT_EN_RDMA;
} else if (cur == DDP_COMPONENT_OD && next == DDP_COMPONENT_RDMA0) {
*addr = DISP_REG_CONFIG_DISP_OD_MOUT_EN;
value = OD_MOUT_EN_RDMA0;
} else if (cur == DDP_COMPONENT_UFOE && next == DDP_COMPONENT_DSI0) {
*addr = DISP_REG_CONFIG_DISP_UFOE_MOUT_EN;
value = UFOE_MOUT_EN_DSI0;
} else if (cur == DDP_COMPONENT_OVL1 && next == DDP_COMPONENT_COLOR1) {
*addr = DISP_REG_CONFIG_DISP_OVL1_MOUT_EN;
value = OVL1_MOUT_EN_COLOR1;
} else if (cur == DDP_COMPONENT_GAMMA && next == DDP_COMPONENT_RDMA1) {
*addr = DISP_REG_CONFIG_DISP_GAMMA_MOUT_EN;
value = GAMMA_MOUT_EN_RDMA1;
} else if (cur == DDP_COMPONENT_RDMA1 && next == DDP_COMPONENT_DPI0) {
*addr = DISP_REG_CONFIG_DISP_RDMA1_MOUT_EN;
value = RDMA1_MOUT_DPI0;
} else {
value = 0;
}
return value;
}
static unsigned int mtk_ddp_sel_in(enum mtk_ddp_comp_id cur,
enum mtk_ddp_comp_id next,
unsigned int *addr)
{
unsigned int value;
if (cur == DDP_COMPONENT_OVL0 && next == DDP_COMPONENT_COLOR0) {
*addr = DISP_REG_CONFIG_DISP_COLOR0_SEL_IN;
value = COLOR0_SEL_IN_OVL0;
} else if (cur == DDP_COMPONENT_RDMA1 && next == DDP_COMPONENT_DPI0) {
*addr = DISP_REG_CONFIG_DPI_SEL_IN;
value = DPI0_SEL_IN_RDMA1;
} else if (cur == DDP_COMPONENT_OVL1 && next == DDP_COMPONENT_COLOR1) {
*addr = DISP_REG_CONFIG_DISP_COLOR1_SEL_IN;
value = COLOR1_SEL_IN_OVL1;
} else if (cur == DDP_COMPONENT_BLS && next == DDP_COMPONENT_DSI0) {
*addr = DISP_REG_CONFIG_DSI_SEL;
value = DSI_SEL_IN_BLS;
} else {
value = 0;
}
return value;
}
static void mtk_ddp_sout_sel(void __iomem *config_regs,
enum mtk_ddp_comp_id cur,
enum mtk_ddp_comp_id next)
{
if (cur == DDP_COMPONENT_BLS && next == DDP_COMPONENT_DSI0)
writel_relaxed(BLS_TO_DSI_RDMA1_TO_DPI1,
config_regs + DISP_REG_CONFIG_OUT_SEL);
}
void mtk_ddp_add_comp_to_path(void __iomem *config_regs,
enum mtk_ddp_comp_id cur,
enum mtk_ddp_comp_id next)
{
unsigned int addr, value, reg;
value = mtk_ddp_mout_en(cur, next, &addr);
if (value) {
reg = readl_relaxed(config_regs + addr) | value;
writel_relaxed(reg, config_regs + addr);
}
mtk_ddp_sout_sel(config_regs, cur, next);
value = mtk_ddp_sel_in(cur, next, &addr);
if (value) {
reg = readl_relaxed(config_regs + addr) | value;
writel_relaxed(reg, config_regs + addr);
}
}
void mtk_ddp_remove_comp_from_path(void __iomem *config_regs,
enum mtk_ddp_comp_id cur,
enum mtk_ddp_comp_id next)
{
unsigned int addr, value, reg;
value = mtk_ddp_mout_en(cur, next, &addr);
if (value) {
reg = readl_relaxed(config_regs + addr) & ~value;
writel_relaxed(reg, config_regs + addr);
}
value = mtk_ddp_sel_in(cur, next, &addr);
if (value) {
reg = readl_relaxed(config_regs + addr) & ~value;
writel_relaxed(reg, config_regs + addr);
}
}
struct mtk_disp_mutex *mtk_disp_mutex_get(struct device *dev, unsigned int id)
{
struct mtk_ddp *ddp = dev_get_drvdata(dev);
if (id >= 10)
return ERR_PTR(-EINVAL);
if (ddp->mutex[id].claimed)
return ERR_PTR(-EBUSY);
ddp->mutex[id].claimed = true;
return &ddp->mutex[id];
}
void mtk_disp_mutex_put(struct mtk_disp_mutex *mutex)
{
struct mtk_ddp *ddp = container_of(mutex, struct mtk_ddp,
mutex[mutex->id]);
WARN_ON(&ddp->mutex[mutex->id] != mutex);
mutex->claimed = false;
}
int mtk_disp_mutex_prepare(struct mtk_disp_mutex *mutex)
{
struct mtk_ddp *ddp = container_of(mutex, struct mtk_ddp,
mutex[mutex->id]);
return clk_prepare_enable(ddp->clk);
}
void mtk_disp_mutex_unprepare(struct mtk_disp_mutex *mutex)
{
struct mtk_ddp *ddp = container_of(mutex, struct mtk_ddp,
mutex[mutex->id]);
clk_disable_unprepare(ddp->clk);
}
void mtk_disp_mutex_add_comp(struct mtk_disp_mutex *mutex,
enum mtk_ddp_comp_id id)
{
struct mtk_ddp *ddp = container_of(mutex, struct mtk_ddp,
mutex[mutex->id]);
unsigned int reg;
WARN_ON(&ddp->mutex[mutex->id] != mutex);
switch (id) {
case DDP_COMPONENT_DSI0:
reg = MUTEX_SOF_DSI0;
break;
case DDP_COMPONENT_DSI1:
reg = MUTEX_SOF_DSI0;
break;
case DDP_COMPONENT_DPI0:
reg = MUTEX_SOF_DPI0;
break;
default:
reg = readl_relaxed(ddp->regs + DISP_REG_MUTEX_MOD(mutex->id));
reg |= ddp->mutex_mod[id];
writel_relaxed(reg, ddp->regs + DISP_REG_MUTEX_MOD(mutex->id));
return;
}
writel_relaxed(reg, ddp->regs + DISP_REG_MUTEX_SOF(mutex->id));
}
void mtk_disp_mutex_remove_comp(struct mtk_disp_mutex *mutex,
enum mtk_ddp_comp_id id)
{
struct mtk_ddp *ddp = container_of(mutex, struct mtk_ddp,
mutex[mutex->id]);
unsigned int reg;
WARN_ON(&ddp->mutex[mutex->id] != mutex);
switch (id) {
case DDP_COMPONENT_DSI0:
case DDP_COMPONENT_DSI1:
case DDP_COMPONENT_DPI0:
writel_relaxed(MUTEX_SOF_SINGLE_MODE,
ddp->regs + DISP_REG_MUTEX_SOF(mutex->id));
break;
default:
reg = readl_relaxed(ddp->regs + DISP_REG_MUTEX_MOD(mutex->id));
reg &= ~(ddp->mutex_mod[id]);
writel_relaxed(reg, ddp->regs + DISP_REG_MUTEX_MOD(mutex->id));
break;
}
}
void mtk_disp_mutex_enable(struct mtk_disp_mutex *mutex)
{
struct mtk_ddp *ddp = container_of(mutex, struct mtk_ddp,
mutex[mutex->id]);
WARN_ON(&ddp->mutex[mutex->id] != mutex);
writel(1, ddp->regs + DISP_REG_MUTEX_EN(mutex->id));
}
void mtk_disp_mutex_disable(struct mtk_disp_mutex *mutex)
{
struct mtk_ddp *ddp = container_of(mutex, struct mtk_ddp,
mutex[mutex->id]);
WARN_ON(&ddp->mutex[mutex->id] != mutex);
writel(0, ddp->regs + DISP_REG_MUTEX_EN(mutex->id));
}
void mtk_disp_mutex_acquire(struct mtk_disp_mutex *mutex)
{
struct mtk_ddp *ddp = container_of(mutex, struct mtk_ddp,
mutex[mutex->id]);
u32 tmp;
writel(1, ddp->regs + DISP_REG_MUTEX_EN(mutex->id));
writel(1, ddp->regs + DISP_REG_MUTEX(mutex->id));
if (readl_poll_timeout_atomic(ddp->regs + DISP_REG_MUTEX(mutex->id),
tmp, tmp & INT_MUTEX, 1, 10000))
pr_err("could not acquire mutex %d\n", mutex->id);
}
void mtk_disp_mutex_release(struct mtk_disp_mutex *mutex)
{
struct mtk_ddp *ddp = container_of(mutex, struct mtk_ddp,
mutex[mutex->id]);
writel(0, ddp->regs + DISP_REG_MUTEX(mutex->id));
}
static int mtk_ddp_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct mtk_ddp *ddp;
struct resource *regs;
int i;
ddp = devm_kzalloc(dev, sizeof(*ddp), GFP_KERNEL);
if (!ddp)
return -ENOMEM;
for (i = 0; i < 10; i++)
ddp->mutex[i].id = i;
ddp->clk = devm_clk_get(dev, NULL);
if (IS_ERR(ddp->clk)) {
dev_err(dev, "Failed to get clock\n");
return PTR_ERR(ddp->clk);
}
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ddp->regs = devm_ioremap_resource(dev, regs);
if (IS_ERR(ddp->regs)) {
dev_err(dev, "Failed to map mutex registers\n");
return PTR_ERR(ddp->regs);
}
ddp->mutex_mod = of_device_get_match_data(dev);
platform_set_drvdata(pdev, ddp);
return 0;
}
static int mtk_ddp_remove(struct platform_device *pdev)
{
return 0;
}
