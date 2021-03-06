static inline unsigned char
iic_cook_addr(struct i2c_msg *msg)
{
unsigned char addr;
addr = (msg->addr << 1);
if (msg->flags & I2C_M_RD)
addr |= 1;
return addr;
}
static void
iop3xx_i2c_reset(struct i2c_algo_iop3xx_data *iop3xx_adap)
{
__raw_writel(IOP3XX_ICR_UNIT_RESET, iop3xx_adap->ioaddr + CR_OFFSET);
__raw_writel(IOP3XX_ISR_CLEARBITS, iop3xx_adap->ioaddr + SR_OFFSET);
__raw_writel(0, iop3xx_adap->ioaddr + CR_OFFSET);
}
static void
iop3xx_i2c_enable(struct i2c_algo_iop3xx_data *iop3xx_adap)
{
u32 cr = IOP3XX_ICR_GCD | IOP3XX_ICR_SCLEN | IOP3XX_ICR_UE;
#if defined(CONFIG_ARCH_IOP32X) || defined(CONFIG_ARCH_IOP33X)
if (iop3xx_adap->id == 0) {
gpio_line_set(IOP3XX_GPIO_LINE(7), GPIO_LOW);
gpio_line_set(IOP3XX_GPIO_LINE(6), GPIO_LOW);
} else {
gpio_line_set(IOP3XX_GPIO_LINE(5), GPIO_LOW);
gpio_line_set(IOP3XX_GPIO_LINE(4), GPIO_LOW);
}
#endif
iop3xx_adap->SR_enabled =
IOP3XX_ISR_ALD | IOP3XX_ISR_BERRD |
IOP3XX_ISR_RXFULL | IOP3XX_ISR_TXEMPTY;
cr |= IOP3XX_ICR_ALD_IE | IOP3XX_ICR_BERR_IE |
IOP3XX_ICR_RXFULL_IE | IOP3XX_ICR_TXEMPTY_IE;
__raw_writel(cr, iop3xx_adap->ioaddr + CR_OFFSET);
}
static void
iop3xx_i2c_transaction_cleanup(struct i2c_algo_iop3xx_data *iop3xx_adap)
{
unsigned long cr = __raw_readl(iop3xx_adap->ioaddr + CR_OFFSET);
cr &= ~(IOP3XX_ICR_MSTART | IOP3XX_ICR_TBYTE |
IOP3XX_ICR_MSTOP | IOP3XX_ICR_SCLEN);
__raw_writel(cr, iop3xx_adap->ioaddr + CR_OFFSET);
}
static irqreturn_t
iop3xx_i2c_irq_handler(int this_irq, void *dev_id)
{
struct i2c_algo_iop3xx_data *iop3xx_adap = dev_id;
u32 sr = __raw_readl(iop3xx_adap->ioaddr + SR_OFFSET);
if ((sr &= iop3xx_adap->SR_enabled)) {
__raw_writel(sr, iop3xx_adap->ioaddr + SR_OFFSET);
iop3xx_adap->SR_received |= sr;
wake_up_interruptible(&iop3xx_adap->waitq);
}
return IRQ_HANDLED;
}
static int
iop3xx_i2c_error(u32 sr)
{
int rc = 0;
if ((sr & IOP3XX_ISR_BERRD)) {
if ( !rc ) rc = -I2C_ERR_BERR;
}
if ((sr & IOP3XX_ISR_ALD)) {
if ( !rc ) rc = -I2C_ERR_ALD;
}
return rc;
}
static inline u32
iop3xx_i2c_get_srstat(struct i2c_algo_iop3xx_data *iop3xx_adap)
{
unsigned long flags;
u32 sr;
spin_lock_irqsave(&iop3xx_adap->lock, flags);
sr = iop3xx_adap->SR_received;
iop3xx_adap->SR_received = 0;
spin_unlock_irqrestore(&iop3xx_adap->lock, flags);
return sr;
}
static int
iop3xx_i2c_wait_event(struct i2c_algo_iop3xx_data *iop3xx_adap,
unsigned flags, unsigned* status,
compare_func compare)
{
unsigned sr = 0;
int interrupted;
int done;
int rc = 0;
do {
interrupted = wait_event_interruptible_timeout (
iop3xx_adap->waitq,
(done = compare( sr = iop3xx_i2c_get_srstat(iop3xx_adap) ,flags )),
1 * HZ;
);
if ((rc = iop3xx_i2c_error(sr)) < 0) {
*status = sr;
return rc;
} else if (!interrupted) {
*status = sr;
return -ETIMEDOUT;
}
} while(!done);
*status = sr;
return 0;
}
static int
all_bits_clear(unsigned test, unsigned mask)
{
return (test & mask) == 0;
}
static int
any_bits_set(unsigned test, unsigned mask)
{
return (test & mask) != 0;
}
static int
iop3xx_i2c_wait_tx_done(struct i2c_algo_iop3xx_data *iop3xx_adap, int *status)
{
return iop3xx_i2c_wait_event(
iop3xx_adap,
IOP3XX_ISR_TXEMPTY | IOP3XX_ISR_ALD | IOP3XX_ISR_BERRD,
status, any_bits_set);
}
static int
iop3xx_i2c_wait_rx_done(struct i2c_algo_iop3xx_data *iop3xx_adap, int *status)
{
return iop3xx_i2c_wait_event(
iop3xx_adap,
IOP3XX_ISR_RXFULL | IOP3XX_ISR_ALD | IOP3XX_ISR_BERRD,
status, any_bits_set);
}
static int
iop3xx_i2c_wait_idle(struct i2c_algo_iop3xx_data *iop3xx_adap, int *status)
{
return iop3xx_i2c_wait_event(
iop3xx_adap, IOP3XX_ISR_UNITBUSY, status, all_bits_clear);
}
static int
iop3xx_i2c_send_target_addr(struct i2c_algo_iop3xx_data *iop3xx_adap,
struct i2c_msg* msg)
{
unsigned long cr = __raw_readl(iop3xx_adap->ioaddr + CR_OFFSET);
int status;
int rc;
if (msg->addr == MYSAR) {
return -EBUSY;
}
__raw_writel(iic_cook_addr(msg), iop3xx_adap->ioaddr + DBR_OFFSET);
cr &= ~(IOP3XX_ICR_MSTOP | IOP3XX_ICR_NACK);
cr |= IOP3XX_ICR_MSTART | IOP3XX_ICR_TBYTE;
__raw_writel(cr, iop3xx_adap->ioaddr + CR_OFFSET);
rc = iop3xx_i2c_wait_tx_done(iop3xx_adap, &status);
return rc;
}
static int
iop3xx_i2c_write_byte(struct i2c_algo_iop3xx_data *iop3xx_adap, char byte,
int stop)
{
unsigned long cr = __raw_readl(iop3xx_adap->ioaddr + CR_OFFSET);
int status;
int rc = 0;
__raw_writel(byte, iop3xx_adap->ioaddr + DBR_OFFSET);
cr &= ~IOP3XX_ICR_MSTART;
if (stop) {
cr |= IOP3XX_ICR_MSTOP;
} else {
cr &= ~IOP3XX_ICR_MSTOP;
}
cr |= IOP3XX_ICR_TBYTE;
__raw_writel(cr, iop3xx_adap->ioaddr + CR_OFFSET);
rc = iop3xx_i2c_wait_tx_done(iop3xx_adap, &status);
return rc;
}
static int
iop3xx_i2c_read_byte(struct i2c_algo_iop3xx_data *iop3xx_adap, char* byte,
int stop)
{
unsigned long cr = __raw_readl(iop3xx_adap->ioaddr + CR_OFFSET);
int status;
int rc = 0;
cr &= ~IOP3XX_ICR_MSTART;
if (stop) {
cr |= IOP3XX_ICR_MSTOP | IOP3XX_ICR_NACK;
} else {
cr &= ~(IOP3XX_ICR_MSTOP | IOP3XX_ICR_NACK);
}
cr |= IOP3XX_ICR_TBYTE;
__raw_writel(cr, iop3xx_adap->ioaddr + CR_OFFSET);
rc = iop3xx_i2c_wait_rx_done(iop3xx_adap, &status);
*byte = __raw_readl(iop3xx_adap->ioaddr + DBR_OFFSET);
return rc;
}
static int
iop3xx_i2c_writebytes(struct i2c_adapter *i2c_adap, const char *buf, int count)
{
struct i2c_algo_iop3xx_data *iop3xx_adap = i2c_adap->algo_data;
int ii;
int rc = 0;
for (ii = 0; rc == 0 && ii != count; ++ii)
rc = iop3xx_i2c_write_byte(iop3xx_adap, buf[ii], ii==count-1);
return rc;
}
static int
iop3xx_i2c_readbytes(struct i2c_adapter *i2c_adap, char *buf, int count)
{
struct i2c_algo_iop3xx_data *iop3xx_adap = i2c_adap->algo_data;
int ii;
int rc = 0;
for (ii = 0; rc == 0 && ii != count; ++ii)
rc = iop3xx_i2c_read_byte(iop3xx_adap, &buf[ii], ii==count-1);
return rc;
}
static int
iop3xx_i2c_handle_msg(struct i2c_adapter *i2c_adap, struct i2c_msg* pmsg)
{
struct i2c_algo_iop3xx_data *iop3xx_adap = i2c_adap->algo_data;
int rc;
rc = iop3xx_i2c_send_target_addr(iop3xx_adap, pmsg);
if (rc < 0) {
return rc;
}
if ((pmsg->flags&I2C_M_RD)) {
return iop3xx_i2c_readbytes(i2c_adap, pmsg->buf, pmsg->len);
} else {
return iop3xx_i2c_writebytes(i2c_adap, pmsg->buf, pmsg->len);
}
}
static int
iop3xx_i2c_master_xfer(struct i2c_adapter *i2c_adap, struct i2c_msg *msgs,
int num)
{
struct i2c_algo_iop3xx_data *iop3xx_adap = i2c_adap->algo_data;
int im = 0;
int ret = 0;
int status;
iop3xx_i2c_wait_idle(iop3xx_adap, &status);
iop3xx_i2c_reset(iop3xx_adap);
iop3xx_i2c_enable(iop3xx_adap);
for (im = 0; ret == 0 && im != num; im++) {
ret = iop3xx_i2c_handle_msg(i2c_adap, &msgs[im]);
}
iop3xx_i2c_transaction_cleanup(iop3xx_adap);
if(ret)
return ret;
return im;
}
static u32
iop3xx_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int
iop3xx_i2c_remove(struct platform_device *pdev)
{
struct i2c_adapter *padapter = platform_get_drvdata(pdev);
struct i2c_algo_iop3xx_data *adapter_data =
(struct i2c_algo_iop3xx_data *)padapter->algo_data;
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
unsigned long cr = __raw_readl(adapter_data->ioaddr + CR_OFFSET);
cr &= ~(IOP3XX_ICR_ALD_IE | IOP3XX_ICR_BERR_IE |
IOP3XX_ICR_RXFULL_IE | IOP3XX_ICR_TXEMPTY_IE);
__raw_writel(cr, adapter_data->ioaddr + CR_OFFSET);
iounmap(adapter_data->ioaddr);
release_mem_region(res->start, IOP3XX_I2C_IO_SIZE);
kfree(adapter_data);
kfree(padapter);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int
iop3xx_i2c_probe(struct platform_device *pdev)
{
struct resource *res;
int ret, irq;
struct i2c_adapter *new_adapter;
struct i2c_algo_iop3xx_data *adapter_data;
new_adapter = kzalloc(sizeof(struct i2c_adapter), GFP_KERNEL);
if (!new_adapter) {
ret = -ENOMEM;
goto out;
}
adapter_data = kzalloc(sizeof(struct i2c_algo_iop3xx_data), GFP_KERNEL);
if (!adapter_data) {
ret = -ENOMEM;
goto free_adapter;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
ret = -ENODEV;
goto free_both;
}
if (!request_mem_region(res->start, IOP3XX_I2C_IO_SIZE, pdev->name)) {
ret = -EBUSY;
goto free_both;
}
adapter_data->id = i2c_id++;
adapter_data->ioaddr = ioremap(res->start, IOP3XX_I2C_IO_SIZE);
if (!adapter_data->ioaddr) {
ret = -ENOMEM;
goto release_region;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
ret = -ENXIO;
goto unmap;
}
ret = request_irq(irq, iop3xx_i2c_irq_handler, 0,
pdev->name, adapter_data);
if (ret) {
ret = -EIO;
goto unmap;
}
memcpy(new_adapter->name, pdev->name, strlen(pdev->name));
new_adapter->owner = THIS_MODULE;
new_adapter->class = I2C_CLASS_HWMON | I2C_CLASS_SPD;
new_adapter->dev.parent = &pdev->dev;
new_adapter->nr = pdev->id;
new_adapter->timeout = HZ;
new_adapter->algo = &iop3xx_i2c_algo;
init_waitqueue_head(&adapter_data->waitq);
spin_lock_init(&adapter_data->lock);
iop3xx_i2c_reset(adapter_data);
iop3xx_i2c_enable(adapter_data);
platform_set_drvdata(pdev, new_adapter);
new_adapter->algo_data = adapter_data;
i2c_add_numbered_adapter(new_adapter);
return 0;
unmap:
iounmap(adapter_data->ioaddr);
release_region:
release_mem_region(res->start, IOP3XX_I2C_IO_SIZE);
free_both:
kfree(adapter_data);
free_adapter:
kfree(new_adapter);
out:
return ret;
}
