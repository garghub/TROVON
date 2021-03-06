static irqreturn_t charlcd_interrupt(int irq, void *data)
{
struct charlcd *lcd = data;
u8 status;
status = readl(lcd->virtbase + CHAR_STAT) & 0x01;
writel(CHAR_RAW_CLEAR, lcd->virtbase + CHAR_RAW);
if (status)
complete(&lcd->complete);
else
dev_info(lcd->dev, "Spurious IRQ (%02x)\n", status);
return IRQ_HANDLED;
}
static void charlcd_wait_complete_irq(struct charlcd *lcd)
{
int ret;
ret = wait_for_completion_interruptible_timeout(&lcd->complete,
CHARLCD_TIMEOUT);
writel(0x00, lcd->virtbase + CHAR_MASK);
if (ret < 0) {
dev_err(lcd->dev,
"wait_for_completion_interruptible_timeout() "
"returned %d waiting for ready\n", ret);
return;
}
if (ret == 0) {
dev_err(lcd->dev, "charlcd controller timed out "
"waiting for ready\n");
return;
}
}
static u8 charlcd_4bit_read_char(struct charlcd *lcd)
{
u8 data;
u32 val;
int i;
if (lcd->irq >= 0)
charlcd_wait_complete_irq(lcd);
else {
i = 0;
val = 0;
while (!(val & CHAR_RAW_VALID) && i < 10) {
udelay(100);
val = readl(lcd->virtbase + CHAR_RAW);
i++;
}
writel(CHAR_RAW_CLEAR, lcd->virtbase + CHAR_RAW);
}
msleep(1);
data = readl(lcd->virtbase + CHAR_RD) & 0xf0;
i = 0;
val = 0;
while (!(val & CHAR_RAW_VALID) && i < 10) {
udelay(100);
val = readl(lcd->virtbase + CHAR_RAW);
i++;
}
writel(CHAR_RAW_CLEAR, lcd->virtbase + CHAR_RAW);
msleep(1);
data |= (readl(lcd->virtbase + CHAR_RD) >> 4) & 0x0f;
return data;
}
static bool charlcd_4bit_read_bf(struct charlcd *lcd)
{
if (lcd->irq >= 0) {
writel(CHAR_RAW_CLEAR, lcd->virtbase + CHAR_RAW);
init_completion(&lcd->complete);
writel(0x01, lcd->virtbase + CHAR_MASK);
}
readl(lcd->virtbase + CHAR_COM);
return charlcd_4bit_read_char(lcd) & HD_BUSY_FLAG ? true : false;
}
static void charlcd_4bit_wait_busy(struct charlcd *lcd)
{
int retries = 50;
udelay(100);
while (charlcd_4bit_read_bf(lcd) && retries)
retries--;
if (!retries)
dev_err(lcd->dev, "timeout waiting for busyflag\n");
}
static void charlcd_4bit_command(struct charlcd *lcd, u8 cmd)
{
u32 cmdlo = (cmd << 4) & 0xf0;
u32 cmdhi = (cmd & 0xf0);
writel(cmdhi, lcd->virtbase + CHAR_COM);
udelay(10);
writel(cmdlo, lcd->virtbase + CHAR_COM);
charlcd_4bit_wait_busy(lcd);
}
static void charlcd_4bit_char(struct charlcd *lcd, u8 ch)
{
u32 chlo = (ch << 4) & 0xf0;
u32 chhi = (ch & 0xf0);
writel(chhi, lcd->virtbase + CHAR_DAT);
udelay(10);
writel(chlo, lcd->virtbase + CHAR_DAT);
charlcd_4bit_wait_busy(lcd);
}
static void charlcd_4bit_print(struct charlcd *lcd, int line, const char *str)
{
u8 offset;
int i;
if (line == 0)
offset = 0;
else if (line == 1)
offset = 0x28;
else
return;
charlcd_4bit_command(lcd, HD_SET_DDRAM | offset);
for (i = 0; i < strlen(str) && i < 0x28; i++)
charlcd_4bit_char(lcd, str[i]);
}
static void charlcd_4bit_init(struct charlcd *lcd)
{
writel(HD_FUNCSET | HD_FUNCSET_8BIT, lcd->virtbase + CHAR_COM);
msleep(5);
writel(HD_FUNCSET | HD_FUNCSET_8BIT, lcd->virtbase + CHAR_COM);
udelay(100);
writel(HD_FUNCSET | HD_FUNCSET_8BIT, lcd->virtbase + CHAR_COM);
udelay(100);
writel(HD_FUNCSET, lcd->virtbase + CHAR_COM);
udelay(100);
charlcd_4bit_command(lcd, HD_FUNCSET | HD_FUNCSET_2_LINES);
charlcd_4bit_command(lcd, HD_DISPCTRL | HD_DISPCTRL_ON);
charlcd_4bit_command(lcd, HD_ENTRYMODE | HD_ENTRYMODE_INCREMENT);
charlcd_4bit_command(lcd, HD_CLEAR);
charlcd_4bit_command(lcd, HD_HOME);
charlcd_4bit_print(lcd, 0, "ARM Linux");
charlcd_4bit_print(lcd, 1, UTS_RELEASE);
}
static void charlcd_init_work(struct work_struct *work)
{
struct charlcd *lcd =
container_of(work, struct charlcd, init_work.work);
charlcd_4bit_init(lcd);
}
static int __init charlcd_probe(struct platform_device *pdev)
{
int ret;
struct charlcd *lcd;
struct resource *res;
lcd = kzalloc(sizeof(struct charlcd), GFP_KERNEL);
if (!lcd)
return -ENOMEM;
lcd->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
ret = -ENOENT;
goto out_no_resource;
}
lcd->phybase = res->start;
lcd->physize = resource_size(res);
if (request_mem_region(lcd->phybase, lcd->physize,
DRIVERNAME) == NULL) {
ret = -EBUSY;
goto out_no_memregion;
}
lcd->virtbase = ioremap(lcd->phybase, lcd->physize);
if (!lcd->virtbase) {
ret = -ENOMEM;
goto out_no_remap;
}
lcd->irq = platform_get_irq(pdev, 0);
if (lcd->irq >= 0) {
if (request_irq(lcd->irq, charlcd_interrupt, IRQF_DISABLED,
DRIVERNAME, lcd)) {
ret = -EIO;
goto out_no_irq;
}
}
platform_set_drvdata(pdev, lcd);
INIT_DELAYED_WORK(&lcd->init_work, charlcd_init_work);
schedule_delayed_work(&lcd->init_work, 0);
dev_info(&pdev->dev, "initialized ARM character LCD at %08x\n",
lcd->phybase);
return 0;
out_no_irq:
iounmap(lcd->virtbase);
out_no_remap:
platform_set_drvdata(pdev, NULL);
out_no_memregion:
release_mem_region(lcd->phybase, SZ_4K);
out_no_resource:
kfree(lcd);
return ret;
}
static int __exit charlcd_remove(struct platform_device *pdev)
{
struct charlcd *lcd = platform_get_drvdata(pdev);
if (lcd) {
free_irq(lcd->irq, lcd);
iounmap(lcd->virtbase);
release_mem_region(lcd->phybase, lcd->physize);
platform_set_drvdata(pdev, NULL);
kfree(lcd);
}
return 0;
}
static int charlcd_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct charlcd *lcd = platform_get_drvdata(pdev);
charlcd_4bit_command(lcd, HD_DISPCTRL);
return 0;
}
static int charlcd_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct charlcd *lcd = platform_get_drvdata(pdev);
charlcd_4bit_command(lcd, HD_DISPCTRL | HD_DISPCTRL_ON);
return 0;
}
static int __init charlcd_init(void)
{
return platform_driver_probe(&charlcd_driver, charlcd_probe);
}
static void __exit charlcd_exit(void)
{
platform_driver_unregister(&charlcd_driver);
}
