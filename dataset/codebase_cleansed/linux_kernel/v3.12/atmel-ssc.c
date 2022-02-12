struct ssc_device *ssc_request(unsigned int ssc_num)
{
int ssc_valid = 0;
struct ssc_device *ssc;
spin_lock(&user_lock);
list_for_each_entry(ssc, &ssc_list, list) {
if (ssc->pdev->dev.of_node) {
if (of_alias_get_id(ssc->pdev->dev.of_node, "ssc")
== ssc_num) {
ssc_valid = 1;
break;
}
} else if (ssc->pdev->id == ssc_num) {
ssc_valid = 1;
break;
}
}
if (!ssc_valid) {
spin_unlock(&user_lock);
pr_err("ssc: ssc%d platform device is missing\n", ssc_num);
return ERR_PTR(-ENODEV);
}
if (ssc->user) {
spin_unlock(&user_lock);
dev_dbg(&ssc->pdev->dev, "module busy\n");
return ERR_PTR(-EBUSY);
}
ssc->user++;
spin_unlock(&user_lock);
clk_prepare_enable(ssc->clk);
return ssc;
}
void ssc_free(struct ssc_device *ssc)
{
bool disable_clk = true;
spin_lock(&user_lock);
if (ssc->user)
ssc->user--;
else {
disable_clk = false;
dev_dbg(&ssc->pdev->dev, "device already free\n");
}
spin_unlock(&user_lock);
if (disable_clk)
clk_disable_unprepare(ssc->clk);
}
static inline const struct atmel_ssc_platform_data * __init
atmel_ssc_get_driver_data(struct platform_device *pdev)
{
if (pdev->dev.of_node) {
const struct of_device_id *match;
match = of_match_node(atmel_ssc_dt_ids, pdev->dev.of_node);
if (match == NULL)
return NULL;
return match->data;
}
return (struct atmel_ssc_platform_data *)
platform_get_device_id(pdev)->driver_data;
}
static int ssc_probe(struct platform_device *pdev)
{
struct resource *regs;
struct ssc_device *ssc;
const struct atmel_ssc_platform_data *plat_dat;
ssc = devm_kzalloc(&pdev->dev, sizeof(struct ssc_device), GFP_KERNEL);
if (!ssc) {
dev_dbg(&pdev->dev, "out of memory\n");
return -ENOMEM;
}
ssc->pdev = pdev;
plat_dat = atmel_ssc_get_driver_data(pdev);
if (!plat_dat)
return -ENODEV;
ssc->pdata = (struct atmel_ssc_platform_data *)plat_dat;
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ssc->regs = devm_ioremap_resource(&pdev->dev, regs);
if (IS_ERR(ssc->regs))
return PTR_ERR(ssc->regs);
ssc->phybase = regs->start;
ssc->clk = devm_clk_get(&pdev->dev, "pclk");
if (IS_ERR(ssc->clk)) {
dev_dbg(&pdev->dev, "no pclk clock defined\n");
return -ENXIO;
}
clk_prepare_enable(ssc->clk);
ssc_writel(ssc->regs, IDR, -1);
ssc_readl(ssc->regs, SR);
clk_disable_unprepare(ssc->clk);
ssc->irq = platform_get_irq(pdev, 0);
if (!ssc->irq) {
dev_dbg(&pdev->dev, "could not get irq\n");
return -ENXIO;
}
spin_lock(&user_lock);
list_add_tail(&ssc->list, &ssc_list);
spin_unlock(&user_lock);
platform_set_drvdata(pdev, ssc);
dev_info(&pdev->dev, "Atmel SSC device at 0x%p (irq %d)\n",
ssc->regs, ssc->irq);
return 0;
}
static int ssc_remove(struct platform_device *pdev)
{
struct ssc_device *ssc = platform_get_drvdata(pdev);
spin_lock(&user_lock);
list_del(&ssc->list);
spin_unlock(&user_lock);
return 0;
}
