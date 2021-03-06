static void c67x00_probe_sie(struct c67x00_sie *sie,
struct c67x00_device *dev, int sie_num)
{
spin_lock_init(&sie->lock);
sie->dev = dev;
sie->sie_num = sie_num;
sie->mode = c67x00_sie_config(dev->pdata->sie_config, sie_num);
switch (sie->mode) {
case C67X00_SIE_HOST:
c67x00_hcd_probe(sie);
break;
case C67X00_SIE_UNUSED:
dev_info(sie_dev(sie),
"Not using SIE %d as requested\n", sie->sie_num);
break;
default:
dev_err(sie_dev(sie),
"Unsupported configuration: 0x%x for SIE %d\n",
sie->mode, sie->sie_num);
break;
}
}
static void c67x00_remove_sie(struct c67x00_sie *sie)
{
switch (sie->mode) {
case C67X00_SIE_HOST:
c67x00_hcd_remove(sie);
break;
default:
break;
}
}
static irqreturn_t c67x00_irq(int irq, void *__dev)
{
struct c67x00_device *c67x00 = __dev;
struct c67x00_sie *sie;
u16 msg, int_status;
int i, count = 8;
int_status = c67x00_ll_hpi_status(c67x00);
if (!int_status)
return IRQ_NONE;
while (int_status != 0 && (count-- >= 0)) {
c67x00_ll_irq(c67x00, int_status);
for (i = 0; i < C67X00_SIES; i++) {
sie = &c67x00->sie[i];
msg = 0;
if (int_status & SIEMSG_FLG(i))
msg = c67x00_ll_fetch_siemsg(c67x00, i);
if (sie->irq)
sie->irq(sie, int_status, msg);
}
int_status = c67x00_ll_hpi_status(c67x00);
}
if (int_status)
dev_warn(&c67x00->pdev->dev, "Not all interrupts handled! "
"status = 0x%04x\n", int_status);
return IRQ_HANDLED;
}
static int __devinit c67x00_drv_probe(struct platform_device *pdev)
{
struct c67x00_device *c67x00;
struct c67x00_platform_data *pdata;
struct resource *res, *res2;
int ret, i;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
res2 = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res2)
return -ENODEV;
pdata = pdev->dev.platform_data;
if (!pdata)
return -ENODEV;
c67x00 = kzalloc(sizeof(*c67x00), GFP_KERNEL);
if (!c67x00)
return -ENOMEM;
if (!request_mem_region(res->start, resource_size(res),
pdev->name)) {
dev_err(&pdev->dev, "Memory region busy\n");
ret = -EBUSY;
goto request_mem_failed;
}
c67x00->hpi.base = ioremap(res->start, resource_size(res));
if (!c67x00->hpi.base) {
dev_err(&pdev->dev, "Unable to map HPI registers\n");
ret = -EIO;
goto map_failed;
}
spin_lock_init(&c67x00->hpi.lock);
c67x00->hpi.regstep = pdata->hpi_regstep;
c67x00->pdata = pdev->dev.platform_data;
c67x00->pdev = pdev;
c67x00_ll_init(c67x00);
c67x00_ll_hpi_reg_init(c67x00);
ret = request_irq(res2->start, c67x00_irq, 0, pdev->name, c67x00);
if (ret) {
dev_err(&pdev->dev, "Cannot claim IRQ\n");
goto request_irq_failed;
}
ret = c67x00_ll_reset(c67x00);
if (ret) {
dev_err(&pdev->dev, "Device reset failed\n");
goto reset_failed;
}
for (i = 0; i < C67X00_SIES; i++)
c67x00_probe_sie(&c67x00->sie[i], c67x00, i);
platform_set_drvdata(pdev, c67x00);
return 0;
reset_failed:
free_irq(res2->start, c67x00);
request_irq_failed:
iounmap(c67x00->hpi.base);
map_failed:
release_mem_region(res->start, resource_size(res));
request_mem_failed:
kfree(c67x00);
return ret;
}
static int __devexit c67x00_drv_remove(struct platform_device *pdev)
{
struct c67x00_device *c67x00 = platform_get_drvdata(pdev);
struct resource *res;
int i;
for (i = 0; i < C67X00_SIES; i++)
c67x00_remove_sie(&c67x00->sie[i]);
c67x00_ll_release(c67x00);
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (res)
free_irq(res->start, c67x00);
iounmap(c67x00->hpi.base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res)
release_mem_region(res->start, resource_size(res));
kfree(c67x00);
return 0;
}
