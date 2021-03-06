static void bfin_twi_handle_interrupt(struct bfin_twi_iface *iface,
unsigned short twi_int_status)
{
unsigned short mast_stat = read_MASTER_STAT(iface);
if (twi_int_status & XMTSERV) {
if (iface->writeNum <= 0) {
if (iface->cur_mode == TWI_I2C_MODE_COMBINED)
write_MASTER_CTL(iface,
read_MASTER_CTL(iface) | MDIR);
else if (iface->manual_stop)
write_MASTER_CTL(iface,
read_MASTER_CTL(iface) | STOP);
else if (iface->cur_mode == TWI_I2C_MODE_REPEAT &&
iface->cur_msg + 1 < iface->msg_num) {
if (iface->pmsg[iface->cur_msg + 1].flags &
I2C_M_RD)
write_MASTER_CTL(iface,
read_MASTER_CTL(iface) |
MDIR);
else
write_MASTER_CTL(iface,
read_MASTER_CTL(iface) &
~MDIR);
}
}
while (iface->writeNum > 0 &&
(read_FIFO_STAT(iface) & XMTSTAT) != XMT_FULL) {
SSYNC();
write_XMT_DATA8(iface, *(iface->transPtr++));
iface->writeNum--;
}
}
if (twi_int_status & RCVSERV) {
while (iface->readNum > 0 &&
(read_FIFO_STAT(iface) & RCVSTAT)) {
*(iface->transPtr) = read_RCV_DATA8(iface);
if (iface->cur_mode == TWI_I2C_MODE_COMBINED) {
iface->cur_mode = TWI_I2C_MODE_STANDARDSUB;
if (iface->readNum == 1 && iface->manual_stop)
iface->readNum = *iface->transPtr + 1;
}
iface->transPtr++;
iface->readNum--;
}
if (iface->readNum == 0) {
if (iface->manual_stop) {
read_RCV_DATA16(iface);
write_MASTER_CTL(iface,
read_MASTER_CTL(iface) | STOP);
} else if (iface->cur_mode == TWI_I2C_MODE_REPEAT &&
iface->cur_msg + 1 < iface->msg_num) {
if (iface->pmsg[iface->cur_msg + 1].flags & I2C_M_RD)
write_MASTER_CTL(iface,
read_MASTER_CTL(iface) | MDIR);
else
write_MASTER_CTL(iface,
read_MASTER_CTL(iface) & ~MDIR);
}
}
}
if (twi_int_status & MERR) {
write_INT_MASK(iface, 0);
write_MASTER_STAT(iface, 0x3e);
write_MASTER_CTL(iface, 0);
iface->result = -EIO;
if (mast_stat & LOSTARB)
dev_dbg(&iface->adap.dev, "Lost Arbitration\n");
if (mast_stat & ANAK)
dev_dbg(&iface->adap.dev, "Address Not Acknowledged\n");
if (mast_stat & DNAK)
dev_dbg(&iface->adap.dev, "Data Not Acknowledged\n");
if (mast_stat & BUFRDERR)
dev_dbg(&iface->adap.dev, "Buffer Read Error\n");
if (mast_stat & BUFWRERR)
dev_dbg(&iface->adap.dev, "Buffer Write Error\n");
if (read_MASTER_STAT(iface) & SDASEN) {
int cnt = 9;
do {
write_MASTER_CTL(iface, SCLOVR);
udelay(6);
write_MASTER_CTL(iface, 0);
udelay(6);
} while ((read_MASTER_STAT(iface) & SDASEN) && cnt--);
write_MASTER_CTL(iface, SDAOVR | SCLOVR);
udelay(6);
write_MASTER_CTL(iface, SDAOVR);
udelay(6);
write_MASTER_CTL(iface, 0);
}
if (iface->cur_mode == TWI_I2C_MODE_STANDARD &&
iface->transPtr == NULL &&
(twi_int_status & MCOMP) && (mast_stat & DNAK))
iface->result = 1;
complete(&iface->complete);
return;
}
if (twi_int_status & MCOMP) {
if (twi_int_status & (XMTSERV | RCVSERV) &&
(read_MASTER_CTL(iface) & MEN) == 0 &&
(iface->cur_mode == TWI_I2C_MODE_REPEAT ||
iface->cur_mode == TWI_I2C_MODE_COMBINED)) {
iface->result = -1;
write_INT_MASK(iface, 0);
write_MASTER_CTL(iface, 0);
} else if (iface->cur_mode == TWI_I2C_MODE_COMBINED) {
if (iface->readNum == 0) {
iface->readNum = 1;
iface->manual_stop = 1;
write_MASTER_CTL(iface,
read_MASTER_CTL(iface) | (0xff << 6));
} else {
write_MASTER_CTL(iface,
(read_MASTER_CTL(iface) &
(~(0xff << 6))) |
(iface->readNum << 6));
}
write_MASTER_CTL(iface,
read_MASTER_CTL(iface) & ~RSTART);
} else if (iface->cur_mode == TWI_I2C_MODE_REPEAT &&
iface->cur_msg + 1 < iface->msg_num) {
iface->cur_msg++;
iface->transPtr = iface->pmsg[iface->cur_msg].buf;
iface->writeNum = iface->readNum =
iface->pmsg[iface->cur_msg].len;
write_MASTER_ADDR(iface,
iface->pmsg[iface->cur_msg].addr);
if (iface->pmsg[iface->cur_msg].flags & I2C_M_RD)
iface->read_write = I2C_SMBUS_READ;
else {
iface->read_write = I2C_SMBUS_WRITE;
if (iface->writeNum > 0) {
write_XMT_DATA8(iface,
*(iface->transPtr++));
iface->writeNum--;
}
}
if (iface->pmsg[iface->cur_msg].len <= 255) {
write_MASTER_CTL(iface,
(read_MASTER_CTL(iface) &
(~(0xff << 6))) |
(iface->pmsg[iface->cur_msg].len << 6));
iface->manual_stop = 0;
} else {
write_MASTER_CTL(iface,
(read_MASTER_CTL(iface) |
(0xff << 6)));
iface->manual_stop = 1;
}
if (iface->cur_msg + 1 == iface->msg_num)
write_MASTER_CTL(iface,
read_MASTER_CTL(iface) & ~RSTART);
} else {
iface->result = 1;
write_INT_MASK(iface, 0);
write_MASTER_CTL(iface, 0);
}
complete(&iface->complete);
}
}
static irqreturn_t bfin_twi_interrupt_entry(int irq, void *dev_id)
{
struct bfin_twi_iface *iface = dev_id;
unsigned long flags;
unsigned short twi_int_status;
spin_lock_irqsave(&iface->lock, flags);
while (1) {
twi_int_status = read_INT_STAT(iface);
if (!twi_int_status)
break;
write_INT_STAT(iface, twi_int_status);
bfin_twi_handle_interrupt(iface, twi_int_status);
SSYNC();
}
spin_unlock_irqrestore(&iface->lock, flags);
return IRQ_HANDLED;
}
static int bfin_twi_do_master_xfer(struct i2c_adapter *adap,
struct i2c_msg *msgs, int num)
{
struct bfin_twi_iface *iface = adap->algo_data;
struct i2c_msg *pmsg;
int rc = 0;
if (!(read_CONTROL(iface) & TWI_ENA))
return -ENXIO;
if (read_MASTER_STAT(iface) & BUSBUSY)
return -EAGAIN;
iface->pmsg = msgs;
iface->msg_num = num;
iface->cur_msg = 0;
pmsg = &msgs[0];
if (pmsg->flags & I2C_M_TEN) {
dev_err(&adap->dev, "10 bits addr not supported!\n");
return -EINVAL;
}
if (iface->msg_num > 1)
iface->cur_mode = TWI_I2C_MODE_REPEAT;
iface->manual_stop = 0;
iface->transPtr = pmsg->buf;
iface->writeNum = iface->readNum = pmsg->len;
iface->result = 0;
init_completion(&(iface->complete));
write_MASTER_ADDR(iface, pmsg->addr);
write_FIFO_CTL(iface, 0x3);
SSYNC();
write_FIFO_CTL(iface, 0);
SSYNC();
if (pmsg->flags & I2C_M_RD)
iface->read_write = I2C_SMBUS_READ;
else {
iface->read_write = I2C_SMBUS_WRITE;
if (iface->writeNum > 0) {
write_XMT_DATA8(iface, *(iface->transPtr++));
iface->writeNum--;
SSYNC();
}
}
write_INT_STAT(iface, MERR | MCOMP | XMTSERV | RCVSERV);
write_INT_MASK(iface, MCOMP | MERR | RCVSERV | XMTSERV);
SSYNC();
if (pmsg->len <= 255)
write_MASTER_CTL(iface, pmsg->len << 6);
else {
write_MASTER_CTL(iface, 0xff << 6);
iface->manual_stop = 1;
}
write_MASTER_CTL(iface, read_MASTER_CTL(iface) | MEN |
(iface->msg_num > 1 ? RSTART : 0) |
((iface->read_write == I2C_SMBUS_READ) ? MDIR : 0) |
((CONFIG_I2C_BLACKFIN_TWI_CLK_KHZ > 100) ? FAST : 0));
SSYNC();
while (!iface->result) {
if (!wait_for_completion_timeout(&iface->complete,
adap->timeout)) {
iface->result = -1;
dev_err(&adap->dev, "master transfer timeout\n");
}
}
if (iface->result == 1)
rc = iface->cur_msg + 1;
else
rc = iface->result;
return rc;
}
static int bfin_twi_master_xfer(struct i2c_adapter *adap,
struct i2c_msg *msgs, int num)
{
return bfin_twi_do_master_xfer(adap, msgs, num);
}
int bfin_twi_do_smbus_xfer(struct i2c_adapter *adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size, union i2c_smbus_data *data)
{
struct bfin_twi_iface *iface = adap->algo_data;
int rc = 0;
if (!(read_CONTROL(iface) & TWI_ENA))
return -ENXIO;
if (read_MASTER_STAT(iface) & BUSBUSY)
return -EAGAIN;
iface->writeNum = 0;
iface->readNum = 0;
switch (size) {
case I2C_SMBUS_QUICK:
iface->transPtr = NULL;
iface->cur_mode = TWI_I2C_MODE_STANDARD;
break;
case I2C_SMBUS_BYTE:
if (data == NULL)
iface->transPtr = NULL;
else {
if (read_write == I2C_SMBUS_READ)
iface->readNum = 1;
else
iface->writeNum = 1;
iface->transPtr = &data->byte;
}
iface->cur_mode = TWI_I2C_MODE_STANDARD;
break;
case I2C_SMBUS_BYTE_DATA:
if (read_write == I2C_SMBUS_READ) {
iface->readNum = 1;
iface->cur_mode = TWI_I2C_MODE_COMBINED;
} else {
iface->writeNum = 1;
iface->cur_mode = TWI_I2C_MODE_STANDARDSUB;
}
iface->transPtr = &data->byte;
break;
case I2C_SMBUS_WORD_DATA:
if (read_write == I2C_SMBUS_READ) {
iface->readNum = 2;
iface->cur_mode = TWI_I2C_MODE_COMBINED;
} else {
iface->writeNum = 2;
iface->cur_mode = TWI_I2C_MODE_STANDARDSUB;
}
iface->transPtr = (u8 *)&data->word;
break;
case I2C_SMBUS_PROC_CALL:
iface->writeNum = 2;
iface->readNum = 2;
iface->cur_mode = TWI_I2C_MODE_COMBINED;
iface->transPtr = (u8 *)&data->word;
break;
case I2C_SMBUS_BLOCK_DATA:
if (read_write == I2C_SMBUS_READ) {
iface->readNum = 0;
iface->cur_mode = TWI_I2C_MODE_COMBINED;
} else {
iface->writeNum = data->block[0] + 1;
iface->cur_mode = TWI_I2C_MODE_STANDARDSUB;
}
iface->transPtr = data->block;
break;
case I2C_SMBUS_I2C_BLOCK_DATA:
if (read_write == I2C_SMBUS_READ) {
iface->readNum = data->block[0];
iface->cur_mode = TWI_I2C_MODE_COMBINED;
} else {
iface->writeNum = data->block[0];
iface->cur_mode = TWI_I2C_MODE_STANDARDSUB;
}
iface->transPtr = (u8 *)&data->block[1];
break;
default:
return -1;
}
iface->result = 0;
iface->manual_stop = 0;
iface->read_write = read_write;
iface->command = command;
init_completion(&(iface->complete));
write_FIFO_CTL(iface, 0x3);
SSYNC();
write_FIFO_CTL(iface, 0);
write_INT_STAT(iface, MERR | MCOMP | XMTSERV | RCVSERV);
write_MASTER_ADDR(iface, addr);
SSYNC();
switch (iface->cur_mode) {
case TWI_I2C_MODE_STANDARDSUB:
write_XMT_DATA8(iface, iface->command);
write_INT_MASK(iface, MCOMP | MERR |
((iface->read_write == I2C_SMBUS_READ) ?
RCVSERV : XMTSERV));
SSYNC();
if (iface->writeNum + 1 <= 255)
write_MASTER_CTL(iface, (iface->writeNum + 1) << 6);
else {
write_MASTER_CTL(iface, 0xff << 6);
iface->manual_stop = 1;
}
write_MASTER_CTL(iface, read_MASTER_CTL(iface) | MEN |
((CONFIG_I2C_BLACKFIN_TWI_CLK_KHZ>100) ? FAST : 0));
break;
case TWI_I2C_MODE_COMBINED:
write_XMT_DATA8(iface, iface->command);
write_INT_MASK(iface, MCOMP | MERR | RCVSERV | XMTSERV);
SSYNC();
if (iface->writeNum > 0)
write_MASTER_CTL(iface, (iface->writeNum + 1) << 6);
else
write_MASTER_CTL(iface, 0x1 << 6);
write_MASTER_CTL(iface, read_MASTER_CTL(iface) | MEN | RSTART |
((CONFIG_I2C_BLACKFIN_TWI_CLK_KHZ>100) ? FAST : 0));
break;
default:
write_MASTER_CTL(iface, 0);
if (size != I2C_SMBUS_QUICK) {
if (iface->read_write != I2C_SMBUS_READ) {
if (iface->writeNum > 0) {
write_XMT_DATA8(iface,
*(iface->transPtr++));
if (iface->writeNum <= 255)
write_MASTER_CTL(iface,
iface->writeNum << 6);
else {
write_MASTER_CTL(iface,
0xff << 6);
iface->manual_stop = 1;
}
iface->writeNum--;
} else {
write_XMT_DATA8(iface, iface->command);
write_MASTER_CTL(iface, 1 << 6);
}
} else {
if (iface->readNum > 0 && iface->readNum <= 255)
write_MASTER_CTL(iface,
iface->readNum << 6);
else if (iface->readNum > 255) {
write_MASTER_CTL(iface, 0xff << 6);
iface->manual_stop = 1;
} else
break;
}
}
write_INT_MASK(iface, MCOMP | MERR |
((iface->read_write == I2C_SMBUS_READ) ?
RCVSERV : XMTSERV));
SSYNC();
write_MASTER_CTL(iface, read_MASTER_CTL(iface) | MEN |
((iface->read_write == I2C_SMBUS_READ) ? MDIR : 0) |
((CONFIG_I2C_BLACKFIN_TWI_CLK_KHZ > 100) ? FAST : 0));
break;
}
SSYNC();
while (!iface->result) {
if (!wait_for_completion_timeout(&iface->complete,
adap->timeout)) {
iface->result = -1;
dev_err(&adap->dev, "smbus transfer timeout\n");
}
}
rc = (iface->result >= 0) ? 0 : -1;
return rc;
}
int bfin_twi_smbus_xfer(struct i2c_adapter *adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size, union i2c_smbus_data *data)
{
return bfin_twi_do_smbus_xfer(adap, addr, flags,
read_write, command, size, data);
}
static u32 bfin_twi_functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_SMBUS_QUICK | I2C_FUNC_SMBUS_BYTE |
I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA |
I2C_FUNC_SMBUS_BLOCK_DATA | I2C_FUNC_SMBUS_PROC_CALL |
I2C_FUNC_I2C | I2C_FUNC_SMBUS_I2C_BLOCK;
}
static int i2c_bfin_twi_suspend(struct device *dev)
{
struct bfin_twi_iface *iface = dev_get_drvdata(dev);
iface->saved_clkdiv = read_CLKDIV(iface);
iface->saved_control = read_CONTROL(iface);
free_irq(iface->irq, iface);
write_CONTROL(iface, iface->saved_control & ~TWI_ENA);
return 0;
}
static int i2c_bfin_twi_resume(struct device *dev)
{
struct bfin_twi_iface *iface = dev_get_drvdata(dev);
int rc = request_irq(iface->irq, bfin_twi_interrupt_entry,
0, to_platform_device(dev)->name, iface);
if (rc) {
dev_err(dev, "Can't get IRQ %d !\n", iface->irq);
return -ENODEV;
}
write_CLKDIV(iface, iface->saved_clkdiv);
write_CONTROL(iface, iface->saved_control);
return 0;
}
static int i2c_bfin_twi_probe(struct platform_device *pdev)
{
struct bfin_twi_iface *iface;
struct i2c_adapter *p_adap;
struct resource *res;
int rc;
unsigned int clkhilow;
iface = kzalloc(sizeof(struct bfin_twi_iface), GFP_KERNEL);
if (!iface) {
dev_err(&pdev->dev, "Cannot allocate memory\n");
rc = -ENOMEM;
goto out_error_nomem;
}
spin_lock_init(&(iface->lock));
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(&pdev->dev, "Cannot get IORESOURCE_MEM\n");
rc = -ENOENT;
goto out_error_get_res;
}
iface->regs_base = ioremap(res->start, resource_size(res));
if (iface->regs_base == NULL) {
dev_err(&pdev->dev, "Cannot map IO\n");
rc = -ENXIO;
goto out_error_ioremap;
}
iface->irq = platform_get_irq(pdev, 0);
if (iface->irq < 0) {
dev_err(&pdev->dev, "No IRQ specified\n");
rc = -ENOENT;
goto out_error_no_irq;
}
p_adap = &iface->adap;
p_adap->nr = pdev->id;
strlcpy(p_adap->name, pdev->name, sizeof(p_adap->name));
p_adap->algo = &bfin_twi_algorithm;
p_adap->algo_data = iface;
p_adap->class = I2C_CLASS_HWMON | I2C_CLASS_SPD;
p_adap->dev.parent = &pdev->dev;
p_adap->timeout = 5 * HZ;
p_adap->retries = 3;
rc = peripheral_request_list(
(unsigned short *)dev_get_platdata(&pdev->dev),
"i2c-bfin-twi");
if (rc) {
dev_err(&pdev->dev, "Can't setup pin mux!\n");
goto out_error_pin_mux;
}
rc = request_irq(iface->irq, bfin_twi_interrupt_entry,
0, pdev->name, iface);
if (rc) {
dev_err(&pdev->dev, "Can't get IRQ %d !\n", iface->irq);
rc = -ENODEV;
goto out_error_req_irq;
}
write_CONTROL(iface, ((get_sclk() / 1000 / 1000 + 5) / 10) & 0x7F);
clkhilow = ((10 * 1000 / CONFIG_I2C_BLACKFIN_TWI_CLK_KHZ) + 1) / 2;
write_CLKDIV(iface, (clkhilow << 8) | clkhilow);
write_CONTROL(iface, read_CONTROL(iface) | TWI_ENA);
SSYNC();
rc = i2c_add_numbered_adapter(p_adap);
if (rc < 0) {
dev_err(&pdev->dev, "Can't add i2c adapter!\n");
goto out_error_add_adapter;
}
platform_set_drvdata(pdev, iface);
dev_info(&pdev->dev, "Blackfin BF5xx on-chip I2C TWI Contoller, "
"regs_base@%p\n", iface->regs_base);
return 0;
out_error_add_adapter:
free_irq(iface->irq, iface);
out_error_req_irq:
out_error_no_irq:
peripheral_free_list((unsigned short *)dev_get_platdata(&pdev->dev));
out_error_pin_mux:
iounmap(iface->regs_base);
out_error_ioremap:
out_error_get_res:
kfree(iface);
out_error_nomem:
return rc;
}
static int i2c_bfin_twi_remove(struct platform_device *pdev)
{
struct bfin_twi_iface *iface = platform_get_drvdata(pdev);
i2c_del_adapter(&(iface->adap));
free_irq(iface->irq, iface);
peripheral_free_list((unsigned short *)dev_get_platdata(&pdev->dev));
iounmap(iface->regs_base);
kfree(iface);
return 0;
}
static int __init i2c_bfin_twi_init(void)
{
return platform_driver_register(&i2c_bfin_twi_driver);
}
static void __exit i2c_bfin_twi_exit(void)
{
platform_driver_unregister(&i2c_bfin_twi_driver);
}
