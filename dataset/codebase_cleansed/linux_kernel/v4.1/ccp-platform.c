static int ccp_get_irq(struct ccp_device *ccp)
{
struct device *dev = ccp->dev;
struct platform_device *pdev = container_of(dev,
struct platform_device, dev);
int ret;
ret = platform_get_irq(pdev, 0);
if (ret < 0)
return ret;
ccp->irq = ret;
ret = request_irq(ccp->irq, ccp_irq_handler, 0, "ccp", dev);
if (ret) {
dev_notice(dev, "unable to allocate IRQ (%d)\n", ret);
return ret;
}
return 0;
}
static int ccp_get_irqs(struct ccp_device *ccp)
{
struct device *dev = ccp->dev;
int ret;
ret = ccp_get_irq(ccp);
if (!ret)
return 0;
dev_notice(dev, "could not enable interrupts (%d)\n", ret);
return ret;
}
static void ccp_free_irqs(struct ccp_device *ccp)
{
struct device *dev = ccp->dev;
free_irq(ccp->irq, dev);
}
static struct resource *ccp_find_mmio_area(struct ccp_device *ccp)
{
struct device *dev = ccp->dev;
struct platform_device *pdev = container_of(dev,
struct platform_device, dev);
struct resource *ior;
ior = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (ior && (resource_size(ior) >= 0x800))
return ior;
return NULL;
}
static int ccp_acpi_support(struct ccp_device *ccp)
{
struct ccp_platform *ccp_platform = ccp->dev_specific;
struct acpi_device *adev = ACPI_COMPANION(ccp->dev);
acpi_handle handle;
acpi_status status;
unsigned long long data;
int cca;
handle = adev->handle;
do {
status = acpi_evaluate_integer(handle, "_CCA", NULL, &data);
if (!ACPI_FAILURE(status)) {
cca = data;
break;
}
} while (!ACPI_FAILURE(status));
if (ACPI_FAILURE(status)) {
dev_err(ccp->dev, "error obtaining acpi coherency value\n");
return -EINVAL;
}
ccp_platform->coherent = !!cca;
return 0;
}
static int ccp_acpi_support(struct ccp_device *ccp)
{
return -EINVAL;
}
static int ccp_of_support(struct ccp_device *ccp)
{
struct ccp_platform *ccp_platform = ccp->dev_specific;
ccp_platform->coherent = of_dma_is_coherent(ccp->dev->of_node);
return 0;
}
static int ccp_of_support(struct ccp_device *ccp)
{
return -EINVAL;
}
static int ccp_platform_probe(struct platform_device *pdev)
{
struct ccp_device *ccp;
struct ccp_platform *ccp_platform;
struct device *dev = &pdev->dev;
struct acpi_device *adev = ACPI_COMPANION(dev);
struct resource *ior;
int ret;
ret = -ENOMEM;
ccp = ccp_alloc_struct(dev);
if (!ccp)
goto e_err;
ccp_platform = devm_kzalloc(dev, sizeof(*ccp_platform), GFP_KERNEL);
if (!ccp_platform)
goto e_err;
ccp->dev_specific = ccp_platform;
ccp->get_irq = ccp_get_irqs;
ccp->free_irq = ccp_free_irqs;
ccp_platform->use_acpi = (!adev || acpi_disabled) ? 0 : 1;
ior = ccp_find_mmio_area(ccp);
ccp->io_map = devm_ioremap_resource(dev, ior);
if (IS_ERR(ccp->io_map)) {
ret = PTR_ERR(ccp->io_map);
goto e_err;
}
ccp->io_regs = ccp->io_map;
if (!dev->dma_mask)
dev->dma_mask = &dev->coherent_dma_mask;
ret = dma_set_mask_and_coherent(dev, DMA_BIT_MASK(48));
if (ret) {
dev_err(dev, "dma_set_mask_and_coherent failed (%d)\n", ret);
goto e_err;
}
if (ccp_platform->use_acpi)
ret = ccp_acpi_support(ccp);
else
ret = ccp_of_support(ccp);
if (ret)
goto e_err;
if (ccp_platform->coherent)
ccp->axcache = CACHE_WB_NO_ALLOC;
else
ccp->axcache = CACHE_NONE;
dev_set_drvdata(dev, ccp);
ret = ccp_init(ccp);
if (ret)
goto e_err;
dev_notice(dev, "enabled\n");
return 0;
e_err:
dev_notice(dev, "initialization failed\n");
return ret;
}
static int ccp_platform_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct ccp_device *ccp = dev_get_drvdata(dev);
ccp_destroy(ccp);
dev_notice(dev, "disabled\n");
return 0;
}
static int ccp_platform_suspend(struct platform_device *pdev,
pm_message_t state)
{
struct device *dev = &pdev->dev;
struct ccp_device *ccp = dev_get_drvdata(dev);
unsigned long flags;
unsigned int i;
spin_lock_irqsave(&ccp->cmd_lock, flags);
ccp->suspending = 1;
for (i = 0; i < ccp->cmd_q_count; i++)
wake_up_process(ccp->cmd_q[i].kthread);
spin_unlock_irqrestore(&ccp->cmd_lock, flags);
while (!ccp_queues_suspended(ccp))
wait_event_interruptible(ccp->suspend_queue,
ccp_queues_suspended(ccp));
return 0;
}
static int ccp_platform_resume(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct ccp_device *ccp = dev_get_drvdata(dev);
unsigned long flags;
unsigned int i;
spin_lock_irqsave(&ccp->cmd_lock, flags);
ccp->suspending = 0;
for (i = 0; i < ccp->cmd_q_count; i++) {
ccp->cmd_q[i].suspended = 0;
wake_up_process(ccp->cmd_q[i].kthread);
}
spin_unlock_irqrestore(&ccp->cmd_lock, flags);
return 0;
}
int ccp_platform_init(void)
{
return platform_driver_register(&ccp_platform_driver);
}
void ccp_platform_exit(void)
{
platform_driver_unregister(&ccp_platform_driver);
}
