static irqreturn_t l3_interrupt_handler(int irq, void *_l3)
{
struct omap4_l3 *l3 = _l3;
int inttype, i, k;
int err_src = 0;
u32 std_err_main, err_reg, clear, masterid;
void __iomem *base, *l3_targ_base;
char *target_name, *master_name = "UN IDENTIFIED";
inttype = irq == l3->app_irq ? L3_APPLICATION_ERROR : L3_DEBUG_ERROR;
for (i = 0; i < L3_MODULES; i++) {
base = l3->l3_base[i];
err_reg = __raw_readl(base + l3_flagmux[i] +
+ L3_FLAGMUX_REGERR0 + (inttype << 3));
if (err_reg) {
err_src = __ffs(err_reg);
l3_targ_base = base + *(l3_targ[i] + err_src);
std_err_main = __raw_readl(l3_targ_base +
L3_TARG_STDERRLOG_MAIN);
masterid = __raw_readl(l3_targ_base +
L3_TARG_STDERRLOG_MSTADDR);
switch (std_err_main & CUSTOM_ERROR) {
case STANDARD_ERROR:
target_name =
l3_targ_inst_name[i][err_src];
WARN(true, "L3 standard error: TARGET:%s at address 0x%x\n",
target_name,
__raw_readl(l3_targ_base +
L3_TARG_STDERRLOG_SLVOFSLSB));
clear = std_err_main | CLEAR_STDERR_LOG;
writel(clear, l3_targ_base +
L3_TARG_STDERRLOG_MAIN);
break;
case CUSTOM_ERROR:
target_name =
l3_targ_inst_name[i][err_src];
for (k = 0; k < NUM_OF_L3_MASTERS; k++) {
if (masterid == l3_masters[k].id)
master_name =
l3_masters[k].name;
}
WARN(true, "L3 custom error: MASTER:%s TARGET:%s\n",
master_name, target_name);
clear = std_err_main | CLEAR_STDERR_LOG;
writel(clear, l3_targ_base +
L3_TARG_STDERRLOG_MAIN);
break;
default:
break;
}
break;
}
}
return IRQ_HANDLED;
}
static int omap4_l3_probe(struct platform_device *pdev)
{
static struct omap4_l3 *l3;
struct resource *res;
int ret;
l3 = kzalloc(sizeof(*l3), GFP_KERNEL);
if (!l3)
return -ENOMEM;
platform_set_drvdata(pdev, l3);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "couldn't find resource 0\n");
ret = -ENODEV;
goto err0;
}
l3->l3_base[0] = ioremap(res->start, resource_size(res));
if (!l3->l3_base[0]) {
dev_err(&pdev->dev, "ioremap failed\n");
ret = -ENOMEM;
goto err0;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!res) {
dev_err(&pdev->dev, "couldn't find resource 1\n");
ret = -ENODEV;
goto err1;
}
l3->l3_base[1] = ioremap(res->start, resource_size(res));
if (!l3->l3_base[1]) {
dev_err(&pdev->dev, "ioremap failed\n");
ret = -ENOMEM;
goto err1;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 2);
if (!res) {
dev_err(&pdev->dev, "couldn't find resource 2\n");
ret = -ENODEV;
goto err2;
}
l3->l3_base[2] = ioremap(res->start, resource_size(res));
if (!l3->l3_base[2]) {
dev_err(&pdev->dev, "ioremap failed\n");
ret = -ENOMEM;
goto err2;
}
l3->debug_irq = platform_get_irq(pdev, 0);
ret = request_irq(l3->debug_irq,
l3_interrupt_handler,
IRQF_DISABLED, "l3-dbg-irq", l3);
if (ret) {
pr_crit("L3: request_irq failed to register for 0x%x\n",
l3->debug_irq);
goto err3;
}
l3->app_irq = platform_get_irq(pdev, 1);
ret = request_irq(l3->app_irq,
l3_interrupt_handler,
IRQF_DISABLED, "l3-app-irq", l3);
if (ret) {
pr_crit("L3: request_irq failed to register for 0x%x\n",
l3->app_irq);
goto err4;
}
return 0;
err4:
free_irq(l3->debug_irq, l3);
err3:
iounmap(l3->l3_base[2]);
err2:
iounmap(l3->l3_base[1]);
err1:
iounmap(l3->l3_base[0]);
err0:
kfree(l3);
return ret;
}
static int omap4_l3_remove(struct platform_device *pdev)
{
struct omap4_l3 *l3 = platform_get_drvdata(pdev);
free_irq(l3->app_irq, l3);
free_irq(l3->debug_irq, l3);
iounmap(l3->l3_base[0]);
iounmap(l3->l3_base[1]);
iounmap(l3->l3_base[2]);
kfree(l3);
return 0;
}
static int __init omap4_l3_init(void)
{
return platform_driver_register(&omap4_l3_driver);
}
static void __exit omap4_l3_exit(void)
{
platform_driver_unregister(&omap4_l3_driver);
}
