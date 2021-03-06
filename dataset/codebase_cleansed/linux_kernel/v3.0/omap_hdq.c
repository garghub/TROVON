static inline u8 hdq_reg_in(struct hdq_data *hdq_data, u32 offset)
{
return __raw_readb(hdq_data->hdq_base + offset);
}
static inline void hdq_reg_out(struct hdq_data *hdq_data, u32 offset, u8 val)
{
__raw_writeb(val, hdq_data->hdq_base + offset);
}
static inline u8 hdq_reg_merge(struct hdq_data *hdq_data, u32 offset,
u8 val, u8 mask)
{
u8 new_val = (__raw_readb(hdq_data->hdq_base + offset) & ~mask)
| (val & mask);
__raw_writeb(new_val, hdq_data->hdq_base + offset);
return new_val;
}
static int hdq_wait_for_flag(struct hdq_data *hdq_data, u32 offset,
u8 flag, u8 flag_set, u8 *status)
{
int ret = 0;
unsigned long timeout = jiffies + OMAP_HDQ_TIMEOUT;
if (flag_set == OMAP_HDQ_FLAG_CLEAR) {
while (((*status = hdq_reg_in(hdq_data, offset)) & flag)
&& time_before(jiffies, timeout)) {
schedule_timeout_uninterruptible(1);
}
if (*status & flag)
ret = -ETIMEDOUT;
} else if (flag_set == OMAP_HDQ_FLAG_SET) {
while (!((*status = hdq_reg_in(hdq_data, offset)) & flag)
&& time_before(jiffies, timeout)) {
schedule_timeout_uninterruptible(1);
}
if (!(*status & flag))
ret = -ETIMEDOUT;
} else
return -EINVAL;
return ret;
}
static int hdq_write_byte(struct hdq_data *hdq_data, u8 val, u8 *status)
{
int ret;
u8 tmp_status;
unsigned long irqflags;
*status = 0;
spin_lock_irqsave(&hdq_data->hdq_spinlock, irqflags);
hdq_reg_in(hdq_data, OMAP_HDQ_INT_STATUS);
hdq_data->hdq_irqstatus = 0;
spin_unlock_irqrestore(&hdq_data->hdq_spinlock, irqflags);
hdq_reg_out(hdq_data, OMAP_HDQ_TX_DATA, val);
hdq_reg_merge(hdq_data, OMAP_HDQ_CTRL_STATUS, OMAP_HDQ_CTRL_STATUS_GO,
OMAP_HDQ_CTRL_STATUS_DIR | OMAP_HDQ_CTRL_STATUS_GO);
ret = wait_event_timeout(hdq_wait_queue,
hdq_data->hdq_irqstatus, OMAP_HDQ_TIMEOUT);
if (ret == 0) {
dev_dbg(hdq_data->dev, "TX wait elapsed\n");
goto out;
}
*status = hdq_data->hdq_irqstatus;
if (!(*status & OMAP_HDQ_INT_STATUS_TXCOMPLETE)) {
dev_dbg(hdq_data->dev, "timeout waiting for"
"TXCOMPLETE/RXCOMPLETE, %x", *status);
ret = -ETIMEDOUT;
goto out;
}
ret = hdq_wait_for_flag(hdq_data, OMAP_HDQ_CTRL_STATUS,
OMAP_HDQ_CTRL_STATUS_GO,
OMAP_HDQ_FLAG_CLEAR, &tmp_status);
if (ret) {
dev_dbg(hdq_data->dev, "timeout waiting GO bit"
"return to zero, %x", tmp_status);
}
out:
return ret;
}
static irqreturn_t hdq_isr(int irq, void *_hdq)
{
struct hdq_data *hdq_data = _hdq;
unsigned long irqflags;
spin_lock_irqsave(&hdq_data->hdq_spinlock, irqflags);
hdq_data->hdq_irqstatus = hdq_reg_in(hdq_data, OMAP_HDQ_INT_STATUS);
spin_unlock_irqrestore(&hdq_data->hdq_spinlock, irqflags);
dev_dbg(hdq_data->dev, "hdq_isr: %x", hdq_data->hdq_irqstatus);
if (hdq_data->hdq_irqstatus &
(OMAP_HDQ_INT_STATUS_TXCOMPLETE | OMAP_HDQ_INT_STATUS_RXCOMPLETE
| OMAP_HDQ_INT_STATUS_TIMEOUT)) {
wake_up(&hdq_wait_queue);
}
return IRQ_HANDLED;
}
static u8 omap_w1_reset_bus(void *_hdq)
{
return 0;
}
static void omap_w1_search_bus(void *_hdq, struct w1_master *master_dev,
u8 search_type, w1_slave_found_callback slave_found)
{
u64 module_id, rn_le, cs, id;
if (w1_id)
module_id = w1_id;
else
module_id = 0x1;
rn_le = cpu_to_le64(module_id);
cs = w1_calc_crc8((u8 *)&rn_le, 7);
id = (cs << 56) | module_id;
slave_found(master_dev, id);
}
static int _omap_hdq_reset(struct hdq_data *hdq_data)
{
int ret;
u8 tmp_status;
hdq_reg_out(hdq_data, OMAP_HDQ_SYSCONFIG, OMAP_HDQ_SYSCONFIG_SOFTRESET);
hdq_reg_out(hdq_data, OMAP_HDQ_CTRL_STATUS,
OMAP_HDQ_CTRL_STATUS_CLOCKENABLE |
OMAP_HDQ_CTRL_STATUS_INTERRUPTMASK);
ret = hdq_wait_for_flag(hdq_data, OMAP_HDQ_SYSSTATUS,
OMAP_HDQ_SYSSTATUS_RESETDONE, OMAP_HDQ_FLAG_SET, &tmp_status);
if (ret)
dev_dbg(hdq_data->dev, "timeout waiting HDQ reset, %x",
tmp_status);
else {
hdq_reg_out(hdq_data, OMAP_HDQ_CTRL_STATUS,
OMAP_HDQ_CTRL_STATUS_CLOCKENABLE |
OMAP_HDQ_CTRL_STATUS_INTERRUPTMASK);
hdq_reg_out(hdq_data, OMAP_HDQ_SYSCONFIG,
OMAP_HDQ_SYSCONFIG_AUTOIDLE);
}
return ret;
}
static int omap_hdq_break(struct hdq_data *hdq_data)
{
int ret = 0;
u8 tmp_status;
unsigned long irqflags;
ret = mutex_lock_interruptible(&hdq_data->hdq_mutex);
if (ret < 0) {
dev_dbg(hdq_data->dev, "Could not acquire mutex\n");
ret = -EINTR;
goto rtn;
}
spin_lock_irqsave(&hdq_data->hdq_spinlock, irqflags);
hdq_reg_in(hdq_data, OMAP_HDQ_INT_STATUS);
hdq_data->hdq_irqstatus = 0;
spin_unlock_irqrestore(&hdq_data->hdq_spinlock, irqflags);
hdq_reg_merge(hdq_data, OMAP_HDQ_CTRL_STATUS,
OMAP_HDQ_CTRL_STATUS_INITIALIZATION | OMAP_HDQ_CTRL_STATUS_GO,
OMAP_HDQ_CTRL_STATUS_DIR | OMAP_HDQ_CTRL_STATUS_INITIALIZATION |
OMAP_HDQ_CTRL_STATUS_GO);
ret = wait_event_timeout(hdq_wait_queue,
hdq_data->hdq_irqstatus, OMAP_HDQ_TIMEOUT);
if (ret == 0) {
dev_dbg(hdq_data->dev, "break wait elapsed\n");
ret = -EINTR;
goto out;
}
tmp_status = hdq_data->hdq_irqstatus;
if (!(tmp_status & OMAP_HDQ_INT_STATUS_TIMEOUT)) {
dev_dbg(hdq_data->dev, "timeout waiting for TIMEOUT, %x",
tmp_status);
ret = -ETIMEDOUT;
goto out;
}
ret = hdq_wait_for_flag(hdq_data, OMAP_HDQ_CTRL_STATUS,
OMAP_HDQ_CTRL_STATUS_INITIALIZATION |
OMAP_HDQ_CTRL_STATUS_GO, OMAP_HDQ_FLAG_CLEAR,
&tmp_status);
if (ret)
dev_dbg(hdq_data->dev, "timeout waiting INIT&GO bits"
"return to zero, %x", tmp_status);
out:
mutex_unlock(&hdq_data->hdq_mutex);
rtn:
return ret;
}
static int hdq_read_byte(struct hdq_data *hdq_data, u8 *val)
{
int ret = 0;
u8 status;
unsigned long timeout = jiffies + OMAP_HDQ_TIMEOUT;
ret = mutex_lock_interruptible(&hdq_data->hdq_mutex);
if (ret < 0) {
ret = -EINTR;
goto rtn;
}
if (!hdq_data->hdq_usecount) {
ret = -EINVAL;
goto out;
}
if (!(hdq_data->hdq_irqstatus & OMAP_HDQ_INT_STATUS_RXCOMPLETE)) {
hdq_reg_merge(hdq_data, OMAP_HDQ_CTRL_STATUS,
OMAP_HDQ_CTRL_STATUS_DIR | OMAP_HDQ_CTRL_STATUS_GO,
OMAP_HDQ_CTRL_STATUS_DIR | OMAP_HDQ_CTRL_STATUS_GO);
while (!(hdq_data->hdq_irqstatus
& OMAP_HDQ_INT_STATUS_RXCOMPLETE)
&& time_before(jiffies, timeout)) {
schedule_timeout_uninterruptible(1);
}
hdq_reg_merge(hdq_data, OMAP_HDQ_CTRL_STATUS, 0,
OMAP_HDQ_CTRL_STATUS_DIR);
status = hdq_data->hdq_irqstatus;
if (!(status & OMAP_HDQ_INT_STATUS_RXCOMPLETE)) {
dev_dbg(hdq_data->dev, "timeout waiting for"
"RXCOMPLETE, %x", status);
ret = -ETIMEDOUT;
goto out;
}
}
*val = hdq_reg_in(hdq_data, OMAP_HDQ_RX_DATA);
out:
mutex_unlock(&hdq_data->hdq_mutex);
rtn:
return 0;
}
static int omap_hdq_get(struct hdq_data *hdq_data)
{
int ret = 0;
ret = mutex_lock_interruptible(&hdq_data->hdq_mutex);
if (ret < 0) {
ret = -EINTR;
goto rtn;
}
if (OMAP_HDQ_MAX_USER == hdq_data->hdq_usecount) {
dev_dbg(hdq_data->dev, "attempt to exceed the max use count");
ret = -EINVAL;
goto out;
} else {
hdq_data->hdq_usecount++;
try_module_get(THIS_MODULE);
if (1 == hdq_data->hdq_usecount) {
if (clk_enable(hdq_data->hdq_ick)) {
dev_dbg(hdq_data->dev, "Can not enable ick\n");
ret = -ENODEV;
goto clk_err;
}
if (clk_enable(hdq_data->hdq_fck)) {
dev_dbg(hdq_data->dev, "Can not enable fck\n");
clk_disable(hdq_data->hdq_ick);
ret = -ENODEV;
goto clk_err;
}
if (!(hdq_reg_in(hdq_data, OMAP_HDQ_SYSSTATUS) &
OMAP_HDQ_SYSSTATUS_RESETDONE)) {
ret = _omap_hdq_reset(hdq_data);
if (ret)
hdq_data->hdq_usecount--;
} else {
hdq_reg_out(hdq_data, OMAP_HDQ_CTRL_STATUS,
OMAP_HDQ_CTRL_STATUS_CLOCKENABLE |
OMAP_HDQ_CTRL_STATUS_INTERRUPTMASK);
hdq_reg_out(hdq_data, OMAP_HDQ_SYSCONFIG,
OMAP_HDQ_SYSCONFIG_AUTOIDLE);
hdq_reg_in(hdq_data, OMAP_HDQ_INT_STATUS);
}
}
}
clk_err:
clk_put(hdq_data->hdq_ick);
clk_put(hdq_data->hdq_fck);
out:
mutex_unlock(&hdq_data->hdq_mutex);
rtn:
return ret;
}
static int omap_hdq_put(struct hdq_data *hdq_data)
{
int ret = 0;
ret = mutex_lock_interruptible(&hdq_data->hdq_mutex);
if (ret < 0)
return -EINTR;
if (0 == hdq_data->hdq_usecount) {
dev_dbg(hdq_data->dev, "attempt to decrement use count"
"when it is zero");
ret = -EINVAL;
} else {
hdq_data->hdq_usecount--;
module_put(THIS_MODULE);
if (0 == hdq_data->hdq_usecount) {
clk_disable(hdq_data->hdq_ick);
clk_disable(hdq_data->hdq_fck);
}
}
mutex_unlock(&hdq_data->hdq_mutex);
return ret;
}
static u8 omap_w1_read_byte(void *_hdq)
{
struct hdq_data *hdq_data = _hdq;
u8 val = 0;
int ret;
ret = hdq_read_byte(hdq_data, &val);
if (ret) {
ret = mutex_lock_interruptible(&hdq_data->hdq_mutex);
if (ret < 0) {
dev_dbg(hdq_data->dev, "Could not acquire mutex\n");
return -EINTR;
}
hdq_data->init_trans = 0;
mutex_unlock(&hdq_data->hdq_mutex);
omap_hdq_put(hdq_data);
return -1;
}
if (hdq_data->init_trans) {
ret = mutex_lock_interruptible(&hdq_data->hdq_mutex);
if (ret < 0) {
dev_dbg(hdq_data->dev, "Could not acquire mutex\n");
return -EINTR;
}
hdq_data->init_trans = 0;
mutex_unlock(&hdq_data->hdq_mutex);
omap_hdq_put(hdq_data);
}
return val;
}
static void omap_w1_write_byte(void *_hdq, u8 byte)
{
struct hdq_data *hdq_data = _hdq;
int ret;
u8 status;
if (hdq_data->init_trans == 0)
omap_hdq_get(hdq_data);
ret = mutex_lock_interruptible(&hdq_data->hdq_mutex);
if (ret < 0) {
dev_dbg(hdq_data->dev, "Could not acquire mutex\n");
return;
}
hdq_data->init_trans++;
mutex_unlock(&hdq_data->hdq_mutex);
ret = hdq_write_byte(hdq_data, byte, &status);
if (ret == 0) {
dev_dbg(hdq_data->dev, "TX failure:Ctrl status %x\n", status);
return;
}
if (hdq_data->init_trans > 1) {
omap_hdq_put(hdq_data);
ret = mutex_lock_interruptible(&hdq_data->hdq_mutex);
if (ret < 0) {
dev_dbg(hdq_data->dev, "Could not acquire mutex\n");
return;
}
hdq_data->init_trans = 0;
mutex_unlock(&hdq_data->hdq_mutex);
}
return;
}
static int __devinit omap_hdq_probe(struct platform_device *pdev)
{
struct hdq_data *hdq_data;
struct resource *res;
int ret, irq;
u8 rev;
hdq_data = kmalloc(sizeof(*hdq_data), GFP_KERNEL);
if (!hdq_data) {
dev_dbg(&pdev->dev, "unable to allocate memory\n");
ret = -ENOMEM;
goto err_kmalloc;
}
hdq_data->dev = &pdev->dev;
platform_set_drvdata(pdev, hdq_data);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_dbg(&pdev->dev, "unable to get resource\n");
ret = -ENXIO;
goto err_resource;
}
hdq_data->hdq_base = ioremap(res->start, SZ_4K);
if (!hdq_data->hdq_base) {
dev_dbg(&pdev->dev, "ioremap failed\n");
ret = -EINVAL;
goto err_ioremap;
}
hdq_data->hdq_ick = clk_get(&pdev->dev, "ick");
if (IS_ERR(hdq_data->hdq_ick)) {
dev_dbg(&pdev->dev, "Can't get HDQ ick clock object\n");
ret = PTR_ERR(hdq_data->hdq_ick);
goto err_ick;
}
hdq_data->hdq_fck = clk_get(&pdev->dev, "fck");
if (IS_ERR(hdq_data->hdq_fck)) {
dev_dbg(&pdev->dev, "Can't get HDQ fck clock object\n");
ret = PTR_ERR(hdq_data->hdq_fck);
goto err_fck;
}
hdq_data->hdq_usecount = 0;
mutex_init(&hdq_data->hdq_mutex);
if (clk_enable(hdq_data->hdq_ick)) {
dev_dbg(&pdev->dev, "Can not enable ick\n");
ret = -ENODEV;
goto err_intfclk;
}
if (clk_enable(hdq_data->hdq_fck)) {
dev_dbg(&pdev->dev, "Can not enable fck\n");
ret = -ENODEV;
goto err_fnclk;
}
rev = hdq_reg_in(hdq_data, OMAP_HDQ_REVISION);
dev_info(&pdev->dev, "OMAP HDQ Hardware Rev %c.%c. Driver in %s mode\n",
(rev >> 4) + '0', (rev & 0x0f) + '0', "Interrupt");
spin_lock_init(&hdq_data->hdq_spinlock);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
ret = -ENXIO;
goto err_irq;
}
ret = request_irq(irq, hdq_isr, IRQF_DISABLED, "omap_hdq", hdq_data);
if (ret < 0) {
dev_dbg(&pdev->dev, "could not request irq\n");
goto err_irq;
}
omap_hdq_break(hdq_data);
clk_disable(hdq_data->hdq_ick);
clk_disable(hdq_data->hdq_fck);
omap_w1_master.data = hdq_data;
ret = w1_add_master_device(&omap_w1_master);
if (ret) {
dev_dbg(&pdev->dev, "Failure in registering w1 master\n");
goto err_w1;
}
return 0;
err_w1:
err_irq:
clk_disable(hdq_data->hdq_fck);
err_fnclk:
clk_disable(hdq_data->hdq_ick);
err_intfclk:
clk_put(hdq_data->hdq_fck);
err_fck:
clk_put(hdq_data->hdq_ick);
err_ick:
iounmap(hdq_data->hdq_base);
err_ioremap:
err_resource:
platform_set_drvdata(pdev, NULL);
kfree(hdq_data);
err_kmalloc:
return ret;
}
static int omap_hdq_remove(struct platform_device *pdev)
{
struct hdq_data *hdq_data = platform_get_drvdata(pdev);
mutex_lock(&hdq_data->hdq_mutex);
if (hdq_data->hdq_usecount) {
dev_dbg(&pdev->dev, "removed when use count is not zero\n");
mutex_unlock(&hdq_data->hdq_mutex);
return -EBUSY;
}
mutex_unlock(&hdq_data->hdq_mutex);
clk_put(hdq_data->hdq_ick);
clk_put(hdq_data->hdq_fck);
free_irq(INT_24XX_HDQ_IRQ, hdq_data);
platform_set_drvdata(pdev, NULL);
iounmap(hdq_data->hdq_base);
kfree(hdq_data);
return 0;
}
static int __init
omap_hdq_init(void)
{
return platform_driver_register(&omap_hdq_driver);
}
static void __exit
omap_hdq_exit(void)
{
platform_driver_unregister(&omap_hdq_driver);
}
