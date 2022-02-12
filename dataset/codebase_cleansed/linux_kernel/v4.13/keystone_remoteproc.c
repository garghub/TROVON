static void keystone_rproc_dsp_reset(struct keystone_rproc *ksproc)
{
reset_control_assert(ksproc->reset);
}
static int keystone_rproc_dsp_boot(struct keystone_rproc *ksproc, u32 boot_addr)
{
int ret;
if (boot_addr & (SZ_1K - 1)) {
dev_err(ksproc->dev, "invalid boot address 0x%x, must be aligned on a 1KB boundary\n",
boot_addr);
return -EINVAL;
}
ret = regmap_write(ksproc->dev_ctrl, ksproc->boot_offset, boot_addr);
if (ret) {
dev_err(ksproc->dev, "regmap_write of boot address failed, status = %d\n",
ret);
return ret;
}
reset_control_deassert(ksproc->reset);
return 0;
}
static irqreturn_t keystone_rproc_exception_interrupt(int irq, void *dev_id)
{
struct keystone_rproc *ksproc = dev_id;
rproc_report_crash(ksproc->rproc, RPROC_FATAL_ERROR);
return IRQ_HANDLED;
}
static void handle_event(struct work_struct *work)
{
struct keystone_rproc *ksproc =
container_of(work, struct keystone_rproc, workqueue);
rproc_vq_interrupt(ksproc->rproc, 0);
rproc_vq_interrupt(ksproc->rproc, 1);
}
static irqreturn_t keystone_rproc_vring_interrupt(int irq, void *dev_id)
{
struct keystone_rproc *ksproc = dev_id;
schedule_work(&ksproc->workqueue);
return IRQ_HANDLED;
}
static int keystone_rproc_start(struct rproc *rproc)
{
struct keystone_rproc *ksproc = rproc->priv;
int ret;
INIT_WORK(&ksproc->workqueue, handle_event);
ret = request_irq(ksproc->irq_ring, keystone_rproc_vring_interrupt, 0,
dev_name(ksproc->dev), ksproc);
if (ret) {
dev_err(ksproc->dev, "failed to enable vring interrupt, ret = %d\n",
ret);
goto out;
}
ret = request_irq(ksproc->irq_fault, keystone_rproc_exception_interrupt,
0, dev_name(ksproc->dev), ksproc);
if (ret) {
dev_err(ksproc->dev, "failed to enable exception interrupt, ret = %d\n",
ret);
goto free_vring_irq;
}
ret = keystone_rproc_dsp_boot(ksproc, rproc->bootaddr);
if (ret)
goto free_exc_irq;
return 0;
free_exc_irq:
free_irq(ksproc->irq_fault, ksproc);
free_vring_irq:
free_irq(ksproc->irq_ring, ksproc);
flush_work(&ksproc->workqueue);
out:
return ret;
}
static int keystone_rproc_stop(struct rproc *rproc)
{
struct keystone_rproc *ksproc = rproc->priv;
keystone_rproc_dsp_reset(ksproc);
free_irq(ksproc->irq_fault, ksproc);
free_irq(ksproc->irq_ring, ksproc);
flush_work(&ksproc->workqueue);
return 0;
}
static void keystone_rproc_kick(struct rproc *rproc, int vqid)
{
struct keystone_rproc *ksproc = rproc->priv;
if (WARN_ON(ksproc->kick_gpio < 0))
return;
gpio_set_value(ksproc->kick_gpio, 1);
}
static void *keystone_rproc_da_to_va(struct rproc *rproc, u64 da, int len)
{
struct keystone_rproc *ksproc = rproc->priv;
void __iomem *va = NULL;
phys_addr_t bus_addr;
u32 dev_addr, offset;
size_t size;
int i;
if (len <= 0)
return NULL;
for (i = 0; i < ksproc->num_mems; i++) {
bus_addr = ksproc->mem[i].bus_addr;
dev_addr = ksproc->mem[i].dev_addr;
size = ksproc->mem[i].size;
if (da < KEYSTONE_RPROC_LOCAL_ADDRESS_MASK) {
if ((da >= dev_addr) &&
((da + len) <= (dev_addr + size))) {
offset = da - dev_addr;
va = ksproc->mem[i].cpu_addr + offset;
break;
}
} else {
if ((da >= bus_addr) &&
(da + len) <= (bus_addr + size)) {
offset = da - bus_addr;
va = ksproc->mem[i].cpu_addr + offset;
break;
}
}
}
return (__force void *)va;
}
static int keystone_rproc_of_get_memories(struct platform_device *pdev,
struct keystone_rproc *ksproc)
{
static const char * const mem_names[] = {"l2sram", "l1pram", "l1dram"};
struct device *dev = &pdev->dev;
struct resource *res;
int num_mems = 0;
int i;
num_mems = ARRAY_SIZE(mem_names);
ksproc->mem = devm_kcalloc(ksproc->dev, num_mems,
sizeof(*ksproc->mem), GFP_KERNEL);
if (!ksproc->mem)
return -ENOMEM;
for (i = 0; i < num_mems; i++) {
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
mem_names[i]);
ksproc->mem[i].cpu_addr = devm_ioremap_resource(dev, res);
if (IS_ERR(ksproc->mem[i].cpu_addr)) {
dev_err(dev, "failed to parse and map %s memory\n",
mem_names[i]);
return PTR_ERR(ksproc->mem[i].cpu_addr);
}
ksproc->mem[i].bus_addr = res->start;
ksproc->mem[i].dev_addr =
res->start & KEYSTONE_RPROC_LOCAL_ADDRESS_MASK;
ksproc->mem[i].size = resource_size(res);
memset((__force void *)ksproc->mem[i].cpu_addr, 0,
ksproc->mem[i].size);
}
ksproc->num_mems = num_mems;
return 0;
}
static int keystone_rproc_of_get_dev_syscon(struct platform_device *pdev,
struct keystone_rproc *ksproc)
{
struct device_node *np = pdev->dev.of_node;
struct device *dev = &pdev->dev;
int ret;
if (!of_property_read_bool(np, "ti,syscon-dev")) {
dev_err(dev, "ti,syscon-dev property is absent\n");
return -EINVAL;
}
ksproc->dev_ctrl =
syscon_regmap_lookup_by_phandle(np, "ti,syscon-dev");
if (IS_ERR(ksproc->dev_ctrl)) {
ret = PTR_ERR(ksproc->dev_ctrl);
return ret;
}
if (of_property_read_u32_index(np, "ti,syscon-dev", 1,
&ksproc->boot_offset)) {
dev_err(dev, "couldn't read the boot register offset\n");
return -EINVAL;
}
return 0;
}
static int keystone_rproc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct keystone_rproc *ksproc;
struct rproc *rproc;
int dsp_id;
char *fw_name = NULL;
char *template = "keystone-dsp%d-fw";
int name_len = 0;
int ret = 0;
if (!np) {
dev_err(dev, "only DT-based devices are supported\n");
return -ENODEV;
}
dsp_id = of_alias_get_id(np, "rproc");
if (dsp_id < 0) {
dev_warn(dev, "device does not have an alias id\n");
return dsp_id;
}
name_len = strlen(template);
fw_name = devm_kzalloc(dev, name_len, GFP_KERNEL);
if (!fw_name)
return -ENOMEM;
snprintf(fw_name, name_len, template, dsp_id);
rproc = rproc_alloc(dev, dev_name(dev), &keystone_rproc_ops, fw_name,
sizeof(*ksproc));
if (!rproc)
return -ENOMEM;
rproc->has_iommu = false;
ksproc = rproc->priv;
ksproc->rproc = rproc;
ksproc->dev = dev;
ret = keystone_rproc_of_get_dev_syscon(pdev, ksproc);
if (ret)
goto free_rproc;
ksproc->reset = devm_reset_control_get(dev, NULL);
if (IS_ERR(ksproc->reset)) {
ret = PTR_ERR(ksproc->reset);
goto free_rproc;
}
pm_runtime_enable(dev);
ret = pm_runtime_get_sync(dev);
if (ret < 0) {
dev_err(dev, "failed to enable clock, status = %d\n", ret);
pm_runtime_put_noidle(dev);
goto disable_rpm;
}
ret = keystone_rproc_of_get_memories(pdev, ksproc);
if (ret)
goto disable_clk;
ksproc->irq_ring = platform_get_irq_byname(pdev, "vring");
if (ksproc->irq_ring < 0) {
ret = ksproc->irq_ring;
dev_err(dev, "failed to get vring interrupt, status = %d\n",
ret);
goto disable_clk;
}
ksproc->irq_fault = platform_get_irq_byname(pdev, "exception");
if (ksproc->irq_fault < 0) {
ret = ksproc->irq_fault;
dev_err(dev, "failed to get exception interrupt, status = %d\n",
ret);
goto disable_clk;
}
ksproc->kick_gpio = of_get_named_gpio_flags(np, "kick-gpios", 0, NULL);
if (ksproc->kick_gpio < 0) {
ret = ksproc->kick_gpio;
dev_err(dev, "failed to get gpio for virtio kicks, status = %d\n",
ret);
goto disable_clk;
}
if (of_reserved_mem_device_init(dev))
dev_warn(dev, "device does not have specific CMA pool\n");
ret = reset_control_status(ksproc->reset);
if (ret < 0) {
dev_err(dev, "failed to get reset status, status = %d\n", ret);
goto release_mem;
} else if (ret == 0) {
WARN(1, "device is not in reset\n");
keystone_rproc_dsp_reset(ksproc);
}
ret = rproc_add(rproc);
if (ret) {
dev_err(dev, "failed to add register device with remoteproc core, status = %d\n",
ret);
goto release_mem;
}
platform_set_drvdata(pdev, ksproc);
return 0;
release_mem:
of_reserved_mem_device_release(dev);
disable_clk:
pm_runtime_put_sync(dev);
disable_rpm:
pm_runtime_disable(dev);
free_rproc:
rproc_free(rproc);
return ret;
}
static int keystone_rproc_remove(struct platform_device *pdev)
{
struct keystone_rproc *ksproc = platform_get_drvdata(pdev);
rproc_del(ksproc->rproc);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
rproc_free(ksproc->rproc);
of_reserved_mem_device_release(&pdev->dev);
return 0;
}
