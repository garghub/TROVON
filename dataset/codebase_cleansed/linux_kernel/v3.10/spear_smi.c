static inline struct spear_snor_flash *get_flash_data(struct mtd_info *mtd)
{
return container_of(mtd, struct spear_snor_flash, mtd);
}
static int spear_smi_read_sr(struct spear_smi *dev, u32 bank)
{
int ret;
u32 ctrlreg1;
mutex_lock(&dev->lock);
dev->status = 0;
ctrlreg1 = readl(dev->io_base + SMI_CR1);
writel(ctrlreg1 & ~(SW_MODE | WB_MODE), dev->io_base + SMI_CR1);
writel((bank << BANK_SHIFT) | RD_STATUS_REG | TFIE,
dev->io_base + SMI_CR2);
ret = wait_event_interruptible_timeout(dev->cmd_complete,
dev->status & TFF, SMI_CMD_TIMEOUT);
if (ret > 0)
ret = dev->status & 0xffff;
else if (ret == 0)
ret = -ETIMEDOUT;
writel(ctrlreg1, dev->io_base + SMI_CR1);
writel(0, dev->io_base + SMI_CR2);
mutex_unlock(&dev->lock);
return ret;
}
static int spear_smi_wait_till_ready(struct spear_smi *dev, u32 bank,
unsigned long timeout)
{
unsigned long finish;
int status;
finish = jiffies + timeout;
do {
status = spear_smi_read_sr(dev, bank);
if (status < 0) {
if (status == -ETIMEDOUT)
continue;
return status;
} else if (!(status & SR_WIP)) {
return 0;
}
cond_resched();
} while (!time_after_eq(jiffies, finish));
dev_err(&dev->pdev->dev, "smi controller is busy, timeout\n");
return -EBUSY;
}
static irqreturn_t spear_smi_int_handler(int irq, void *dev_id)
{
u32 status = 0;
struct spear_smi *dev = dev_id;
status = readl(dev->io_base + SMI_SR);
if (unlikely(!status))
return IRQ_NONE;
writel(0, dev->io_base + SMI_SR);
dev->status |= status;
wake_up_interruptible(&dev->cmd_complete);
return IRQ_HANDLED;
}
static void spear_smi_hw_init(struct spear_smi *dev)
{
unsigned long rate = 0;
u32 prescale = 0;
u32 val;
rate = clk_get_rate(dev->clk);
prescale = DIV_ROUND_UP(rate, dev->clk_rate);
val = HOLD1 | BANK_EN | DSEL_TIME | (prescale << 8);
mutex_lock(&dev->lock);
writel(0, dev->io_base + SMI_SR);
writel(val, dev->io_base + SMI_CR1);
mutex_unlock(&dev->lock);
}
static int get_flash_index(u32 flash_id)
{
int index;
for (index = 0; index < ARRAY_SIZE(flash_devices); index++) {
if (flash_devices[index].device_id == flash_id)
return index;
}
return -ENODEV;
}
static int spear_smi_write_enable(struct spear_smi *dev, u32 bank)
{
int ret;
u32 ctrlreg1;
mutex_lock(&dev->lock);
dev->status = 0;
ctrlreg1 = readl(dev->io_base + SMI_CR1);
writel(ctrlreg1 & ~SW_MODE, dev->io_base + SMI_CR1);
writel((bank << BANK_SHIFT) | WE | TFIE, dev->io_base + SMI_CR2);
ret = wait_event_interruptible_timeout(dev->cmd_complete,
dev->status & TFF, SMI_CMD_TIMEOUT);
writel(ctrlreg1, dev->io_base + SMI_CR1);
writel(0, dev->io_base + SMI_CR2);
if (ret == 0) {
ret = -EIO;
dev_err(&dev->pdev->dev,
"smi controller failed on write enable\n");
} else if (ret > 0) {
if (dev->status & (1 << (bank + WM_SHIFT)))
ret = 0;
else {
dev_err(&dev->pdev->dev, "couldn't enable write\n");
ret = -EIO;
}
}
mutex_unlock(&dev->lock);
return ret;
}
static inline u32
get_sector_erase_cmd(struct spear_snor_flash *flash, u32 offset)
{
u32 cmd;
u8 *x = (u8 *)&cmd;
x[0] = flash->erase_cmd;
x[1] = offset >> 16;
x[2] = offset >> 8;
x[3] = offset;
return cmd;
}
static int spear_smi_erase_sector(struct spear_smi *dev,
u32 bank, u32 command, u32 bytes)
{
u32 ctrlreg1 = 0;
int ret;
ret = spear_smi_wait_till_ready(dev, bank, SMI_MAX_TIME_OUT);
if (ret)
return ret;
ret = spear_smi_write_enable(dev, bank);
if (ret)
return ret;
mutex_lock(&dev->lock);
ctrlreg1 = readl(dev->io_base + SMI_CR1);
writel((ctrlreg1 | SW_MODE) & ~WB_MODE, dev->io_base + SMI_CR1);
writel(command, dev->io_base + SMI_TR);
writel((bank << BANK_SHIFT) | SEND | TFIE | (bytes << TX_LEN_SHIFT),
dev->io_base + SMI_CR2);
ret = wait_event_interruptible_timeout(dev->cmd_complete,
dev->status & TFF, SMI_CMD_TIMEOUT);
if (ret == 0) {
ret = -EIO;
dev_err(&dev->pdev->dev, "sector erase failed\n");
} else if (ret > 0)
ret = 0;
writel(ctrlreg1, dev->io_base + SMI_CR1);
writel(0, dev->io_base + SMI_CR2);
mutex_unlock(&dev->lock);
return ret;
}
static int spear_mtd_erase(struct mtd_info *mtd, struct erase_info *e_info)
{
struct spear_snor_flash *flash = get_flash_data(mtd);
struct spear_smi *dev = mtd->priv;
u32 addr, command, bank;
int len, ret;
if (!flash || !dev)
return -ENODEV;
bank = flash->bank;
if (bank > dev->num_flashes - 1) {
dev_err(&dev->pdev->dev, "Invalid Bank Num");
return -EINVAL;
}
addr = e_info->addr;
len = e_info->len;
mutex_lock(&flash->lock);
while (len) {
command = get_sector_erase_cmd(flash, addr);
ret = spear_smi_erase_sector(dev, bank, command, 4);
if (ret) {
e_info->state = MTD_ERASE_FAILED;
mutex_unlock(&flash->lock);
return ret;
}
addr += mtd->erasesize;
len -= mtd->erasesize;
}
mutex_unlock(&flash->lock);
e_info->state = MTD_ERASE_DONE;
mtd_erase_callback(e_info);
return 0;
}
static int spear_mtd_read(struct mtd_info *mtd, loff_t from, size_t len,
size_t *retlen, u8 *buf)
{
struct spear_snor_flash *flash = get_flash_data(mtd);
struct spear_smi *dev = mtd->priv;
void *src;
u32 ctrlreg1, val;
int ret;
if (!flash || !dev)
return -ENODEV;
if (flash->bank > dev->num_flashes - 1) {
dev_err(&dev->pdev->dev, "Invalid Bank Num");
return -EINVAL;
}
src = flash->base_addr + from;
mutex_lock(&flash->lock);
ret = spear_smi_wait_till_ready(dev, flash->bank, SMI_MAX_TIME_OUT);
if (ret) {
mutex_unlock(&flash->lock);
return ret;
}
mutex_lock(&dev->lock);
ctrlreg1 = val = readl(dev->io_base + SMI_CR1);
val &= ~(SW_MODE | WB_MODE);
if (flash->fast_mode)
val |= FAST_MODE;
writel(val, dev->io_base + SMI_CR1);
memcpy_fromio(buf, (u8 *)src, len);
writel(ctrlreg1, dev->io_base + SMI_CR1);
mutex_unlock(&dev->lock);
*retlen = len;
mutex_unlock(&flash->lock);
return 0;
}
static inline int spear_smi_cpy_toio(struct spear_smi *dev, u32 bank,
void *dest, const void *src, size_t len)
{
int ret;
u32 ctrlreg1;
ret = spear_smi_wait_till_ready(dev, bank, SMI_MAX_TIME_OUT);
if (ret)
return ret;
ret = spear_smi_write_enable(dev, bank);
if (ret)
return ret;
mutex_lock(&dev->lock);
ctrlreg1 = readl(dev->io_base + SMI_CR1);
writel((ctrlreg1 | WB_MODE) & ~SW_MODE, dev->io_base + SMI_CR1);
memcpy_toio(dest, src, len);
writel(ctrlreg1, dev->io_base + SMI_CR1);
mutex_unlock(&dev->lock);
return 0;
}
static int spear_mtd_write(struct mtd_info *mtd, loff_t to, size_t len,
size_t *retlen, const u8 *buf)
{
struct spear_snor_flash *flash = get_flash_data(mtd);
struct spear_smi *dev = mtd->priv;
void *dest;
u32 page_offset, page_size;
int ret;
if (!flash || !dev)
return -ENODEV;
if (flash->bank > dev->num_flashes - 1) {
dev_err(&dev->pdev->dev, "Invalid Bank Num");
return -EINVAL;
}
dest = flash->base_addr + to;
mutex_lock(&flash->lock);
page_offset = (u32)to % flash->page_size;
if (page_offset + len <= flash->page_size) {
ret = spear_smi_cpy_toio(dev, flash->bank, dest, buf, len);
if (!ret)
*retlen += len;
} else {
u32 i;
page_size = flash->page_size - page_offset;
ret = spear_smi_cpy_toio(dev, flash->bank, dest, buf,
page_size);
if (ret)
goto err_write;
else
*retlen += page_size;
for (i = page_size; i < len; i += page_size) {
page_size = len - i;
if (page_size > flash->page_size)
page_size = flash->page_size;
ret = spear_smi_cpy_toio(dev, flash->bank, dest + i,
buf + i, page_size);
if (ret)
break;
else
*retlen += page_size;
}
}
err_write:
mutex_unlock(&flash->lock);
return ret;
}
static int spear_smi_probe_flash(struct spear_smi *dev, u32 bank)
{
int ret;
u32 val = 0;
ret = spear_smi_wait_till_ready(dev, bank, SMI_PROBE_TIMEOUT);
if (ret)
return ret;
mutex_lock(&dev->lock);
dev->status = 0;
val = readl(dev->io_base + SMI_CR1);
writel(val | SW_MODE, dev->io_base + SMI_CR1);
writel(OPCODE_RDID, dev->io_base + SMI_TR);
val = (bank << BANK_SHIFT) | SEND | (1 << TX_LEN_SHIFT) |
(3 << RX_LEN_SHIFT) | TFIE;
writel(val, dev->io_base + SMI_CR2);
ret = wait_event_interruptible_timeout(dev->cmd_complete,
dev->status & TFF, SMI_CMD_TIMEOUT);
if (ret <= 0) {
ret = -ENODEV;
goto err_probe;
}
val = readl(dev->io_base + SMI_RR);
val &= 0x00ffffff;
ret = get_flash_index(val);
err_probe:
val = readl(dev->io_base + SMI_CR1);
writel(val & ~SW_MODE, dev->io_base + SMI_CR1);
mutex_unlock(&dev->lock);
return ret;
}
static int spear_smi_probe_config_dt(struct platform_device *pdev,
struct device_node *np)
{
struct spear_smi_plat_data *pdata = dev_get_platdata(&pdev->dev);
struct device_node *pp = NULL;
const __be32 *addr;
u32 val;
int len;
int i = 0;
if (!np)
return -ENODEV;
of_property_read_u32(np, "clock-rate", &val);
pdata->clk_rate = val;
pdata->board_flash_info = devm_kzalloc(&pdev->dev,
sizeof(*pdata->board_flash_info),
GFP_KERNEL);
while ((pp = of_get_next_child(np, pp))) {
struct spear_smi_flash_info *flash_info;
flash_info = &pdata->board_flash_info[i];
pdata->np[i] = pp;
addr = of_get_property(pp, "reg", &len);
pdata->board_flash_info->mem_base = be32_to_cpup(&addr[0]);
pdata->board_flash_info->size = be32_to_cpup(&addr[1]);
if (of_get_property(pp, "st,smi-fast-mode", NULL))
pdata->board_flash_info->fast_mode = 1;
i++;
}
pdata->num_flashes = i;
return 0;
}
static int spear_smi_probe_config_dt(struct platform_device *pdev,
struct device_node *np)
{
return -ENOSYS;
}
static int spear_smi_setup_banks(struct platform_device *pdev,
u32 bank, struct device_node *np)
{
struct spear_smi *dev = platform_get_drvdata(pdev);
struct mtd_part_parser_data ppdata = {};
struct spear_smi_flash_info *flash_info;
struct spear_smi_plat_data *pdata;
struct spear_snor_flash *flash;
struct mtd_partition *parts = NULL;
int count = 0;
int flash_index;
int ret = 0;
pdata = dev_get_platdata(&pdev->dev);
if (bank > pdata->num_flashes - 1)
return -EINVAL;
flash_info = &pdata->board_flash_info[bank];
if (!flash_info)
return -ENODEV;
flash = devm_kzalloc(&pdev->dev, sizeof(*flash), GFP_ATOMIC);
if (!flash)
return -ENOMEM;
flash->bank = bank;
flash->fast_mode = flash_info->fast_mode ? 1 : 0;
mutex_init(&flash->lock);
flash_index = spear_smi_probe_flash(dev, bank);
if (flash_index < 0) {
dev_info(&dev->pdev->dev, "smi-nor%d not found\n", bank);
return flash_index;
}
flash->base_addr = devm_ioremap(&pdev->dev, flash_info->mem_base,
flash_info->size);
if (!flash->base_addr)
return -EIO;
dev->flash[bank] = flash;
flash->mtd.priv = dev;
if (flash_info->name)
flash->mtd.name = flash_info->name;
else
flash->mtd.name = flash_devices[flash_index].name;
flash->mtd.type = MTD_NORFLASH;
flash->mtd.writesize = 1;
flash->mtd.flags = MTD_CAP_NORFLASH;
flash->mtd.size = flash_info->size;
flash->mtd.erasesize = flash_devices[flash_index].sectorsize;
flash->page_size = flash_devices[flash_index].pagesize;
flash->mtd.writebufsize = flash->page_size;
flash->erase_cmd = flash_devices[flash_index].erase_cmd;
flash->mtd._erase = spear_mtd_erase;
flash->mtd._read = spear_mtd_read;
flash->mtd._write = spear_mtd_write;
flash->dev_id = flash_devices[flash_index].device_id;
dev_info(&dev->pdev->dev, "mtd .name=%s .size=%llx(%lluM)\n",
flash->mtd.name, flash->mtd.size,
flash->mtd.size / (1024 * 1024));
dev_info(&dev->pdev->dev, ".erasesize = 0x%x(%uK)\n",
flash->mtd.erasesize, flash->mtd.erasesize / 1024);
#ifndef CONFIG_OF
if (flash_info->partitions) {
parts = flash_info->partitions;
count = flash_info->nr_partitions;
}
#endif
ppdata.of_node = np;
ret = mtd_device_parse_register(&flash->mtd, NULL, &ppdata, parts,
count);
if (ret) {
dev_err(&dev->pdev->dev, "Err MTD partition=%d\n", ret);
return ret;
}
return 0;
}
static int spear_smi_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct spear_smi_plat_data *pdata = NULL;
struct spear_smi *dev;
struct resource *smi_base;
int irq, ret = 0;
int i;
if (np) {
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata) {
pr_err("%s: ERROR: no memory", __func__);
ret = -ENOMEM;
goto err;
}
pdev->dev.platform_data = pdata;
ret = spear_smi_probe_config_dt(pdev, np);
if (ret) {
ret = -ENODEV;
dev_err(&pdev->dev, "no platform data\n");
goto err;
}
} else {
pdata = dev_get_platdata(&pdev->dev);
if (!pdata) {
ret = -ENODEV;
dev_err(&pdev->dev, "no platform data\n");
goto err;
}
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
ret = -ENODEV;
dev_err(&pdev->dev, "invalid smi irq\n");
goto err;
}
dev = devm_kzalloc(&pdev->dev, sizeof(*dev), GFP_ATOMIC);
if (!dev) {
ret = -ENOMEM;
dev_err(&pdev->dev, "mem alloc fail\n");
goto err;
}
smi_base = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dev->io_base = devm_ioremap_resource(&pdev->dev, smi_base);
if (IS_ERR(dev->io_base)) {
ret = PTR_ERR(dev->io_base);
goto err;
}
dev->pdev = pdev;
dev->clk_rate = pdata->clk_rate;
if (dev->clk_rate > SMI_MAX_CLOCK_FREQ)
dev->clk_rate = SMI_MAX_CLOCK_FREQ;
dev->num_flashes = pdata->num_flashes;
if (dev->num_flashes > MAX_NUM_FLASH_CHIP) {
dev_err(&pdev->dev, "exceeding max number of flashes\n");
dev->num_flashes = MAX_NUM_FLASH_CHIP;
}
dev->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(dev->clk)) {
ret = PTR_ERR(dev->clk);
goto err;
}
ret = clk_prepare_enable(dev->clk);
if (ret)
goto err;
ret = devm_request_irq(&pdev->dev, irq, spear_smi_int_handler, 0,
pdev->name, dev);
if (ret) {
dev_err(&dev->pdev->dev, "SMI IRQ allocation failed\n");
goto err_irq;
}
mutex_init(&dev->lock);
init_waitqueue_head(&dev->cmd_complete);
spear_smi_hw_init(dev);
platform_set_drvdata(pdev, dev);
for (i = 0; i < dev->num_flashes; i++) {
ret = spear_smi_setup_banks(pdev, i, pdata->np[i]);
if (ret) {
dev_err(&dev->pdev->dev, "bank setup failed\n");
goto err_bank_setup;
}
}
return 0;
err_bank_setup:
platform_set_drvdata(pdev, NULL);
err_irq:
clk_disable_unprepare(dev->clk);
err:
return ret;
}
static int spear_smi_remove(struct platform_device *pdev)
{
struct spear_smi *dev;
struct spear_snor_flash *flash;
int ret, i;
dev = platform_get_drvdata(pdev);
if (!dev) {
dev_err(&pdev->dev, "dev is null\n");
return -ENODEV;
}
for (i = 0; i < dev->num_flashes; i++) {
flash = dev->flash[i];
if (!flash)
continue;
ret = mtd_device_unregister(&flash->mtd);
if (ret)
dev_err(&pdev->dev, "error removing mtd\n");
}
clk_disable_unprepare(dev->clk);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int spear_smi_suspend(struct device *dev)
{
struct spear_smi *sdev = dev_get_drvdata(dev);
if (sdev && sdev->clk)
clk_disable_unprepare(sdev->clk);
return 0;
}
static int spear_smi_resume(struct device *dev)
{
struct spear_smi *sdev = dev_get_drvdata(dev);
int ret = -EPERM;
if (sdev && sdev->clk)
ret = clk_prepare_enable(sdev->clk);
if (!ret)
spear_smi_hw_init(sdev);
return ret;
}
