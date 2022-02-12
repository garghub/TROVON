static inline void *phys_to_ptr(u64 address)
{
return (void *)(address | (1ull << 63));
}
static void l2c_lock_line(u64 addr)
{
char *addr_ptr = phys_to_ptr(addr);
asm volatile (
"cache 31, %[line]"
::[line] "m" (*addr_ptr));
}
static void l2c_unlock_line(u64 addr)
{
char *addr_ptr = phys_to_ptr(addr);
asm volatile (
"cache 23, %[line]"
::[line] "m" (*addr_ptr));
}
static void l2c_lock_mem_region(u64 start, u64 len)
{
u64 end;
end = ALIGN(start + len - 1, CVMX_CACHE_LINE_SIZE);
start = ALIGN(start, CVMX_CACHE_LINE_SIZE);
while (start <= end) {
l2c_lock_line(start);
start += CVMX_CACHE_LINE_SIZE;
}
asm volatile("sync");
}
static void l2c_unlock_mem_region(u64 start, u64 len)
{
u64 end;
end = ALIGN(start + len - 1, CVMX_CACHE_LINE_SIZE);
start = ALIGN(start, CVMX_CACHE_LINE_SIZE);
while (start <= end) {
l2c_unlock_line(start);
start += CVMX_CACHE_LINE_SIZE;
}
}
static void octeon_mmc_acquire_bus(struct cvm_mmc_host *host)
{
if (!host->has_ciu3) {
down(&octeon_bootbus_sem);
if (OCTEON_IS_MODEL(OCTEON_CN70XX))
writeq(0, (void __iomem *)CVMX_MIO_BOOT_CTL);
} else {
down(&host->mmc_serializer);
}
}
static void octeon_mmc_release_bus(struct cvm_mmc_host *host)
{
if (!host->has_ciu3)
up(&octeon_bootbus_sem);
else
up(&host->mmc_serializer);
}
static void octeon_mmc_int_enable(struct cvm_mmc_host *host, u64 val)
{
writeq(val, host->base + MIO_EMM_INT(host));
if (!host->has_ciu3)
writeq(val, host->base + MIO_EMM_INT_EN(host));
}
static void octeon_mmc_set_shared_power(struct cvm_mmc_host *host, int dir)
{
if (dir == 0)
if (!atomic_dec_return(&host->shared_power_users))
gpiod_set_value_cansleep(host->global_pwr_gpiod, 0);
if (dir == 1)
if (atomic_inc_return(&host->shared_power_users) == 1)
gpiod_set_value_cansleep(host->global_pwr_gpiod, 1);
}
static void octeon_mmc_dmar_fixup(struct cvm_mmc_host *host,
struct mmc_command *cmd,
struct mmc_data *data,
u64 addr)
{
if (cmd->opcode != MMC_WRITE_MULTIPLE_BLOCK)
return;
if (data->blksz * data->blocks <= 1024)
return;
host->n_minus_one = addr + (data->blksz * data->blocks) - 1024;
l2c_lock_mem_region(host->n_minus_one, 512);
}
static void octeon_mmc_dmar_fixup_done(struct cvm_mmc_host *host)
{
if (!host->n_minus_one)
return;
l2c_unlock_mem_region(host->n_minus_one, 512);
host->n_minus_one = 0;
}
static int octeon_mmc_probe(struct platform_device *pdev)
{
struct device_node *cn, *node = pdev->dev.of_node;
struct cvm_mmc_host *host;
struct resource *res;
void __iomem *base;
int mmc_irq[9];
int i, ret = 0;
u64 val;
host = devm_kzalloc(&pdev->dev, sizeof(*host), GFP_KERNEL);
if (!host)
return -ENOMEM;
spin_lock_init(&host->irq_handler_lock);
sema_init(&host->mmc_serializer, 1);
host->dev = &pdev->dev;
host->acquire_bus = octeon_mmc_acquire_bus;
host->release_bus = octeon_mmc_release_bus;
host->int_enable = octeon_mmc_int_enable;
host->set_shared_power = octeon_mmc_set_shared_power;
if (OCTEON_IS_MODEL(OCTEON_CN6XXX) ||
OCTEON_IS_MODEL(OCTEON_CNF7XXX)) {
host->dmar_fixup = octeon_mmc_dmar_fixup;
host->dmar_fixup_done = octeon_mmc_dmar_fixup_done;
}
host->sys_freq = octeon_get_io_clock_rate();
if (of_device_is_compatible(node, "cavium,octeon-7890-mmc")) {
host->big_dma_addr = true;
host->need_irq_handler_lock = true;
host->has_ciu3 = true;
host->use_sg = true;
for (i = 0; i < 9; i++) {
mmc_irq[i] = platform_get_irq(pdev, i);
if (mmc_irq[i] < 0)
return mmc_irq[i];
irq_set_irq_type(mmc_irq[i], IRQ_TYPE_EDGE_RISING);
}
} else {
host->big_dma_addr = false;
host->need_irq_handler_lock = false;
host->has_ciu3 = false;
for (i = 0; i < 2; i++) {
mmc_irq[i] = platform_get_irq(pdev, i);
if (mmc_irq[i] < 0)
return mmc_irq[i];
}
}
host->last_slot = -1;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Platform resource[0] is missing\n");
return -ENXIO;
}
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
host->base = (void __iomem *)base;
host->reg_off = 0;
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!res) {
dev_err(&pdev->dev, "Platform resource[1] is missing\n");
return -EINVAL;
}
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
host->dma_base = (void __iomem *)base;
host->reg_off_dma = -0x20;
ret = dma_set_mask(&pdev->dev, DMA_BIT_MASK(64));
if (ret)
return ret;
val = readq(host->base + MIO_EMM_INT(host));
writeq(val, host->base + MIO_EMM_INT(host));
if (host->has_ciu3) {
for (i = 1; i <= 4; i++) {
ret = devm_request_irq(&pdev->dev, mmc_irq[i],
cvm_mmc_interrupt,
0, cvm_mmc_irq_names[i], host);
if (ret < 0) {
dev_err(&pdev->dev, "Error: devm_request_irq %d\n",
mmc_irq[i]);
return ret;
}
}
} else {
ret = devm_request_irq(&pdev->dev, mmc_irq[0],
cvm_mmc_interrupt, 0, KBUILD_MODNAME,
host);
if (ret < 0) {
dev_err(&pdev->dev, "Error: devm_request_irq %d\n",
mmc_irq[0]);
return ret;
}
}
host->global_pwr_gpiod = devm_gpiod_get_optional(&pdev->dev,
"power",
GPIOD_OUT_HIGH);
if (IS_ERR(host->global_pwr_gpiod)) {
dev_err(&pdev->dev, "Invalid power GPIO\n");
return PTR_ERR(host->global_pwr_gpiod);
}
platform_set_drvdata(pdev, host);
i = 0;
for_each_child_of_node(node, cn) {
host->slot_pdev[i] =
of_platform_device_create(cn, NULL, &pdev->dev);
if (!host->slot_pdev[i]) {
i++;
continue;
}
ret = cvm_mmc_of_slot_probe(&host->slot_pdev[i]->dev, host);
if (ret) {
dev_err(&pdev->dev, "Error populating slots\n");
octeon_mmc_set_shared_power(host, 0);
goto error;
}
i++;
}
return 0;
error:
for (i = 0; i < CAVIUM_MAX_MMC; i++) {
if (host->slot[i])
cvm_mmc_of_slot_remove(host->slot[i]);
if (host->slot_pdev[i])
of_platform_device_destroy(&host->slot_pdev[i]->dev, NULL);
}
return ret;
}
static int octeon_mmc_remove(struct platform_device *pdev)
{
struct cvm_mmc_host *host = platform_get_drvdata(pdev);
u64 dma_cfg;
int i;
for (i = 0; i < CAVIUM_MAX_MMC; i++)
if (host->slot[i])
cvm_mmc_of_slot_remove(host->slot[i]);
dma_cfg = readq(host->dma_base + MIO_EMM_DMA_CFG(host));
dma_cfg &= ~MIO_EMM_DMA_CFG_EN;
writeq(dma_cfg, host->dma_base + MIO_EMM_DMA_CFG(host));
octeon_mmc_set_shared_power(host, 0);
return 0;
}
static int __init octeon_mmc_init(void)
{
return platform_driver_register(&octeon_mmc_driver);
}
static void __exit octeon_mmc_cleanup(void)
{
platform_driver_unregister(&octeon_mmc_driver);
}
