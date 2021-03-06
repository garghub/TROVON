static inline void s3c_adc_convert(struct adc_device *adc)
{
unsigned con = readl(adc->regs + S3C2410_ADCCON);
con |= S3C2410_ADCCON_ENABLE_START;
writel(con, adc->regs + S3C2410_ADCCON);
}
static inline void s3c_adc_select(struct adc_device *adc,
struct s3c_adc_client *client)
{
unsigned con = readl(adc->regs + S3C2410_ADCCON);
client->select_cb(client, 1);
con &= ~S3C2410_ADCCON_MUXMASK;
con &= ~S3C2410_ADCCON_STDBM;
con &= ~S3C2410_ADCCON_STARTMASK;
if (!client->is_ts)
con |= S3C2410_ADCCON_SELMUX(client->channel);
writel(con, adc->regs + S3C2410_ADCCON);
}
static void s3c_adc_dbgshow(struct adc_device *adc)
{
adc_dbg(adc, "CON=%08x, TSC=%08x, DLY=%08x\n",
readl(adc->regs + S3C2410_ADCCON),
readl(adc->regs + S3C2410_ADCTSC),
readl(adc->regs + S3C2410_ADCDLY));
}
static void s3c_adc_try(struct adc_device *adc)
{
struct s3c_adc_client *next = adc->ts_pend;
if (!next && !list_empty(&adc_pending)) {
next = list_first_entry(&adc_pending,
struct s3c_adc_client, pend);
list_del(&next->pend);
} else
adc->ts_pend = NULL;
if (next) {
adc_dbg(adc, "new client is %p\n", next);
adc->cur = next;
s3c_adc_select(adc, next);
s3c_adc_convert(adc);
s3c_adc_dbgshow(adc);
}
}
int s3c_adc_start(struct s3c_adc_client *client,
unsigned int channel, unsigned int nr_samples)
{
struct adc_device *adc = adc_dev;
unsigned long flags;
if (!adc) {
printk(KERN_ERR "%s: failed to find adc\n", __func__);
return -EINVAL;
}
if (client->is_ts && adc->ts_pend)
return -EAGAIN;
spin_lock_irqsave(&adc->lock, flags);
client->channel = channel;
client->nr_samples = nr_samples;
if (client->is_ts)
adc->ts_pend = client;
else
list_add_tail(&client->pend, &adc_pending);
if (!adc->cur)
s3c_adc_try(adc);
spin_unlock_irqrestore(&adc->lock, flags);
return 0;
}
static void s3c_convert_done(struct s3c_adc_client *client,
unsigned v, unsigned u, unsigned *left)
{
client->result = v;
wake_up(client->wait);
}
int s3c_adc_read(struct s3c_adc_client *client, unsigned int ch)
{
DECLARE_WAIT_QUEUE_HEAD_ONSTACK(wake);
int ret;
client->convert_cb = s3c_convert_done;
client->wait = &wake;
client->result = -1;
ret = s3c_adc_start(client, ch, 1);
if (ret < 0)
goto err;
ret = wait_event_timeout(wake, client->result >= 0, HZ / 2);
if (client->result < 0) {
ret = -ETIMEDOUT;
goto err;
}
client->convert_cb = NULL;
return client->result;
err:
return ret;
}
static void s3c_adc_default_select(struct s3c_adc_client *client,
unsigned select)
{
}
struct s3c_adc_client *s3c_adc_register(struct platform_device *pdev,
void (*select)(struct s3c_adc_client *client,
unsigned int selected),
void (*conv)(struct s3c_adc_client *client,
unsigned d0, unsigned d1,
unsigned *samples_left),
unsigned int is_ts)
{
struct s3c_adc_client *client;
WARN_ON(!pdev);
if (!select)
select = s3c_adc_default_select;
if (!pdev)
return ERR_PTR(-EINVAL);
client = kzalloc(sizeof(struct s3c_adc_client), GFP_KERNEL);
if (!client) {
dev_err(&pdev->dev, "no memory for adc client\n");
return ERR_PTR(-ENOMEM);
}
client->pdev = pdev;
client->is_ts = is_ts;
client->select_cb = select;
client->convert_cb = conv;
return client;
}
void s3c_adc_release(struct s3c_adc_client *client)
{
unsigned long flags;
spin_lock_irqsave(&adc_dev->lock, flags);
if (adc_dev->cur == client)
adc_dev->cur = NULL;
if (adc_dev->ts_pend == client)
adc_dev->ts_pend = NULL;
else {
struct list_head *p, *n;
struct s3c_adc_client *tmp;
list_for_each_safe(p, n, &adc_pending) {
tmp = list_entry(p, struct s3c_adc_client, pend);
if (tmp == client)
list_del(&tmp->pend);
}
}
if (adc_dev->cur == NULL)
s3c_adc_try(adc_dev);
spin_unlock_irqrestore(&adc_dev->lock, flags);
kfree(client);
}
static irqreturn_t s3c_adc_irq(int irq, void *pw)
{
struct adc_device *adc = pw;
struct s3c_adc_client *client = adc->cur;
enum s3c_cpu_type cpu = platform_get_device_id(adc->pdev)->driver_data;
unsigned data0, data1;
if (!client) {
dev_warn(&adc->pdev->dev, "%s: no adc pending\n", __func__);
goto exit;
}
data0 = readl(adc->regs + S3C2410_ADCDAT0);
data1 = readl(adc->regs + S3C2410_ADCDAT1);
adc_dbg(adc, "read %d: 0x%04x, 0x%04x\n", client->nr_samples, data0, data1);
client->nr_samples--;
if (cpu == TYPE_S3C64XX) {
data0 &= 0xfff;
data1 &= 0xfff;
} else {
data0 &= 0x3ff;
data1 &= 0x3ff;
}
if (client->convert_cb)
(client->convert_cb)(client, data0, data1, &client->nr_samples);
if (client->nr_samples > 0) {
client->select_cb(client, 1);
s3c_adc_convert(adc);
} else {
spin_lock(&adc->lock);
(client->select_cb)(client, 0);
adc->cur = NULL;
s3c_adc_try(adc);
spin_unlock(&adc->lock);
}
exit:
if (cpu == TYPE_S3C64XX) {
writel(0, adc->regs + S3C64XX_ADCCLRINT);
}
return IRQ_HANDLED;
}
static int s3c_adc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct adc_device *adc;
struct resource *regs;
int ret;
unsigned tmp;
adc = kzalloc(sizeof(struct adc_device), GFP_KERNEL);
if (adc == NULL) {
dev_err(dev, "failed to allocate adc_device\n");
return -ENOMEM;
}
spin_lock_init(&adc->lock);
adc->pdev = pdev;
adc->prescale = S3C2410_ADCCON_PRSCVL(49);
adc->irq = platform_get_irq(pdev, 1);
if (adc->irq <= 0) {
dev_err(dev, "failed to get adc irq\n");
ret = -ENOENT;
goto err_alloc;
}
ret = request_irq(adc->irq, s3c_adc_irq, 0, dev_name(dev), adc);
if (ret < 0) {
dev_err(dev, "failed to attach adc irq\n");
goto err_alloc;
}
adc->clk = clk_get(dev, "adc");
if (IS_ERR(adc->clk)) {
dev_err(dev, "failed to get adc clock\n");
ret = PTR_ERR(adc->clk);
goto err_irq;
}
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!regs) {
dev_err(dev, "failed to find registers\n");
ret = -ENXIO;
goto err_clk;
}
adc->regs = ioremap(regs->start, resource_size(regs));
if (!adc->regs) {
dev_err(dev, "failed to map registers\n");
ret = -ENXIO;
goto err_clk;
}
clk_enable(adc->clk);
tmp = adc->prescale | S3C2410_ADCCON_PRSCEN;
if (platform_get_device_id(pdev)->driver_data == TYPE_S3C64XX) {
tmp |= S3C64XX_ADCCON_RESSEL;
}
writel(tmp, adc->regs + S3C2410_ADCCON);
dev_info(dev, "attached adc driver\n");
platform_set_drvdata(pdev, adc);
adc_dev = adc;
return 0;
err_clk:
clk_put(adc->clk);
err_irq:
free_irq(adc->irq, adc);
err_alloc:
kfree(adc);
return ret;
}
static int __devexit s3c_adc_remove(struct platform_device *pdev)
{
struct adc_device *adc = platform_get_drvdata(pdev);
iounmap(adc->regs);
free_irq(adc->irq, adc);
clk_disable(adc->clk);
clk_put(adc->clk);
kfree(adc);
return 0;
}
static int s3c_adc_suspend(struct platform_device *pdev, pm_message_t state)
{
struct adc_device *adc = platform_get_drvdata(pdev);
unsigned long flags;
u32 con;
spin_lock_irqsave(&adc->lock, flags);
con = readl(adc->regs + S3C2410_ADCCON);
con |= S3C2410_ADCCON_STDBM;
writel(con, adc->regs + S3C2410_ADCCON);
disable_irq(adc->irq);
spin_unlock_irqrestore(&adc->lock, flags);
clk_disable(adc->clk);
return 0;
}
static int s3c_adc_resume(struct platform_device *pdev)
{
struct adc_device *adc = platform_get_drvdata(pdev);
clk_enable(adc->clk);
enable_irq(adc->irq);
writel(adc->prescale | S3C2410_ADCCON_PRSCEN,
adc->regs + S3C2410_ADCCON);
return 0;
}
static int __init adc_init(void)
{
int ret;
ret = platform_driver_register(&s3c_adc_driver);
if (ret)
printk(KERN_ERR "%s: failed to add adc driver\n", __func__);
return ret;
}
