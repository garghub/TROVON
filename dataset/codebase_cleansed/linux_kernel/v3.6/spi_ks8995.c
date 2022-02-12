static inline u8 get_chip_id(u8 val)
{
return (val >> ID1_CHIPID_S) & ID1_CHIPID_M;
}
static inline u8 get_chip_rev(u8 val)
{
return (val >> ID1_REVISION_S) & ID1_REVISION_M;
}
static int ks8995_read(struct ks8995_switch *ks, char *buf,
unsigned offset, size_t count)
{
u8 cmd[2];
struct spi_transfer t[2];
struct spi_message m;
int err;
spi_message_init(&m);
memset(&t, 0, sizeof(t));
t[0].tx_buf = cmd;
t[0].len = sizeof(cmd);
spi_message_add_tail(&t[0], &m);
t[1].rx_buf = buf;
t[1].len = count;
spi_message_add_tail(&t[1], &m);
cmd[0] = KS8995_CMD_READ;
cmd[1] = offset;
mutex_lock(&ks->lock);
err = spi_sync(ks->spi, &m);
mutex_unlock(&ks->lock);
return err ? err : count;
}
static int ks8995_write(struct ks8995_switch *ks, char *buf,
unsigned offset, size_t count)
{
u8 cmd[2];
struct spi_transfer t[2];
struct spi_message m;
int err;
spi_message_init(&m);
memset(&t, 0, sizeof(t));
t[0].tx_buf = cmd;
t[0].len = sizeof(cmd);
spi_message_add_tail(&t[0], &m);
t[1].tx_buf = buf;
t[1].len = count;
spi_message_add_tail(&t[1], &m);
cmd[0] = KS8995_CMD_WRITE;
cmd[1] = offset;
mutex_lock(&ks->lock);
err = spi_sync(ks->spi, &m);
mutex_unlock(&ks->lock);
return err ? err : count;
}
static inline int ks8995_read_reg(struct ks8995_switch *ks, u8 addr, u8 *buf)
{
return (ks8995_read(ks, buf, addr, 1) != 1);
}
static inline int ks8995_write_reg(struct ks8995_switch *ks, u8 addr, u8 val)
{
char buf = val;
return (ks8995_write(ks, &buf, addr, 1) != 1);
}
static int ks8995_stop(struct ks8995_switch *ks)
{
return ks8995_write_reg(ks, KS8995_REG_ID1, 0);
}
static int ks8995_start(struct ks8995_switch *ks)
{
return ks8995_write_reg(ks, KS8995_REG_ID1, 1);
}
static int ks8995_reset(struct ks8995_switch *ks)
{
int err;
err = ks8995_stop(ks);
if (err)
return err;
udelay(KS8995_RESET_DELAY);
return ks8995_start(ks);
}
static ssize_t ks8995_registers_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf, loff_t off, size_t count)
{
struct device *dev;
struct ks8995_switch *ks8995;
dev = container_of(kobj, struct device, kobj);
ks8995 = dev_get_drvdata(dev);
if (unlikely(off > KS8995_REGS_SIZE))
return 0;
if ((off + count) > KS8995_REGS_SIZE)
count = KS8995_REGS_SIZE - off;
if (unlikely(!count))
return count;
return ks8995_read(ks8995, buf, off, count);
}
static ssize_t ks8995_registers_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf, loff_t off, size_t count)
{
struct device *dev;
struct ks8995_switch *ks8995;
dev = container_of(kobj, struct device, kobj);
ks8995 = dev_get_drvdata(dev);
if (unlikely(off >= KS8995_REGS_SIZE))
return -EFBIG;
if ((off + count) > KS8995_REGS_SIZE)
count = KS8995_REGS_SIZE - off;
if (unlikely(!count))
return count;
return ks8995_write(ks8995, buf, off, count);
}
static int __devinit ks8995_probe(struct spi_device *spi)
{
struct ks8995_switch *ks;
struct ks8995_pdata *pdata;
u8 ids[2];
int err;
pdata = spi->dev.platform_data;
ks = kzalloc(sizeof(*ks), GFP_KERNEL);
if (!ks) {
dev_err(&spi->dev, "no memory for private data\n");
return -ENOMEM;
}
mutex_init(&ks->lock);
ks->pdata = pdata;
ks->spi = spi_dev_get(spi);
dev_set_drvdata(&spi->dev, ks);
spi->mode = SPI_MODE_0;
spi->bits_per_word = 8;
err = spi_setup(spi);
if (err) {
dev_err(&spi->dev, "spi_setup failed, err=%d\n", err);
goto err_drvdata;
}
err = ks8995_read(ks, ids, KS8995_REG_ID0, sizeof(ids));
if (err < 0) {
dev_err(&spi->dev, "unable to read id registers, err=%d\n",
err);
goto err_drvdata;
}
switch (ids[0]) {
case FAMILY_KS8995:
break;
default:
dev_err(&spi->dev, "unknown family id:%02x\n", ids[0]);
err = -ENODEV;
goto err_drvdata;
}
err = ks8995_reset(ks);
if (err)
goto err_drvdata;
err = sysfs_create_bin_file(&spi->dev.kobj, &ks8995_registers_attr);
if (err) {
dev_err(&spi->dev, "unable to create sysfs file, err=%d\n",
err);
goto err_drvdata;
}
dev_info(&spi->dev, "KS89%02X device found, Chip ID:%01x, "
"Revision:%01x\n", ids[0],
get_chip_id(ids[1]), get_chip_rev(ids[1]));
return 0;
err_drvdata:
dev_set_drvdata(&spi->dev, NULL);
kfree(ks);
return err;
}
static int __devexit ks8995_remove(struct spi_device *spi)
{
struct ks8995_data *ks8995;
ks8995 = dev_get_drvdata(&spi->dev);
sysfs_remove_bin_file(&spi->dev.kobj, &ks8995_registers_attr);
dev_set_drvdata(&spi->dev, NULL);
kfree(ks8995);
return 0;
}
static int __init ks8995_init(void)
{
pr_info(DRV_DESC " version " DRV_VERSION "\n");
return spi_register_driver(&ks8995_driver);
}
static void __exit ks8995_exit(void)
{
spi_unregister_driver(&ks8995_driver);
}
