static inline u8 get_chip_id(u8 val)
{
return (val >> ID1_CHIPID_S) & ID1_CHIPID_M;
}
static inline u8 get_chip_rev(u8 val)
{
return (val >> ID1_REVISION_S) & ID1_REVISION_M;
}
static inline __be16 create_spi_cmd(struct ks8995_switch *ks, int cmd,
unsigned address)
{
u16 result = cmd;
result <<= ks->chip->addr_width + ks->chip->addr_shift;
result |= address << ks->chip->addr_shift;
return cpu_to_be16(result);
}
static int ks8995_read(struct ks8995_switch *ks, char *buf,
unsigned offset, size_t count)
{
__be16 cmd;
struct spi_transfer t[2];
struct spi_message m;
int err;
cmd = create_spi_cmd(ks, KS8995_CMD_READ, offset);
spi_message_init(&m);
memset(&t, 0, sizeof(t));
t[0].tx_buf = &cmd;
t[0].len = sizeof(cmd);
spi_message_add_tail(&t[0], &m);
t[1].rx_buf = buf;
t[1].len = count;
spi_message_add_tail(&t[1], &m);
mutex_lock(&ks->lock);
err = spi_sync(ks->spi, &m);
mutex_unlock(&ks->lock);
return err ? err : count;
}
static int ks8995_write(struct ks8995_switch *ks, char *buf,
unsigned offset, size_t count)
{
__be16 cmd;
struct spi_transfer t[2];
struct spi_message m;
int err;
cmd = create_spi_cmd(ks, KS8995_CMD_WRITE, offset);
spi_message_init(&m);
memset(&t, 0, sizeof(t));
t[0].tx_buf = &cmd;
t[0].len = sizeof(cmd);
spi_message_add_tail(&t[0], &m);
t[1].tx_buf = buf;
t[1].len = count;
spi_message_add_tail(&t[1], &m);
mutex_lock(&ks->lock);
err = spi_sync(ks->spi, &m);
mutex_unlock(&ks->lock);
return err ? err : count;
}
static inline int ks8995_read_reg(struct ks8995_switch *ks, u8 addr, u8 *buf)
{
return ks8995_read(ks, buf, addr, 1) != 1;
}
static inline int ks8995_write_reg(struct ks8995_switch *ks, u8 addr, u8 val)
{
char buf = val;
return ks8995_write(ks, &buf, addr, 1) != 1;
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
return ks8995_read(ks8995, buf, off, count);
}
static ssize_t ks8995_registers_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf, loff_t off, size_t count)
{
struct device *dev;
struct ks8995_switch *ks8995;
dev = container_of(kobj, struct device, kobj);
ks8995 = dev_get_drvdata(dev);
return ks8995_write(ks8995, buf, off, count);
}
static int ks8995_get_revision(struct ks8995_switch *ks)
{
int err;
u8 id0, id1, ksz8864_id;
err = ks8995_read_reg(ks, KS8995_REG_ID0, &id0);
if (err) {
err = -EIO;
goto err_out;
}
if (id0 != ks->chip->family_id) {
dev_err(&ks->spi->dev, "chip family id mismatch: expected 0x%02x but 0x%02x read\n",
ks->chip->family_id, id0);
err = -ENODEV;
goto err_out;
}
switch (ks->chip->family_id) {
case FAMILY_KS8995:
err = ks8995_read_reg(ks, KS8995_REG_ID1, &id1);
if (err) {
err = -EIO;
goto err_out;
}
if ((get_chip_id(id1) == CHIPID_M) &&
(get_chip_id(id1) == ks->chip->chip_id)) {
ks->revision_id = get_chip_rev(id1);
} else if (get_chip_id(id1) != CHIPID_M) {
err = ks8995_read_reg(ks, KS8995_REG_ID1, &ksz8864_id);
if (err) {
err = -EIO;
goto err_out;
}
if ((ksz8864_id & 0x80) &&
(ks->chip->chip_id == KSZ8864_CHIP_ID)) {
ks->revision_id = get_chip_rev(id1);
}
} else {
dev_err(&ks->spi->dev, "unsupported chip id for KS8995 family: 0x%02x\n",
id1);
err = -ENODEV;
}
break;
case FAMILY_KSZ8795:
err = ks8995_read_reg(ks, KS8995_REG_ID1, &id1);
if (err) {
err = -EIO;
goto err_out;
}
if (get_chip_id(id1) == ks->chip->chip_id) {
ks->revision_id = get_chip_rev(id1);
} else {
dev_err(&ks->spi->dev, "unsupported chip id for KSZ8795 family: 0x%02x\n",
id1);
err = -ENODEV;
}
break;
default:
dev_err(&ks->spi->dev, "unsupported family id: 0x%02x\n", id0);
err = -ENODEV;
break;
}
err_out:
return err;
}
static void ks8995_parse_dt(struct ks8995_switch *ks)
{
struct device_node *np = ks->spi->dev.of_node;
struct ks8995_pdata *pdata = ks->pdata;
if (!np)
return;
pdata->reset_gpio = of_get_named_gpio_flags(np, "reset-gpios", 0,
&pdata->reset_gpio_flags);
}
static int ks8995_probe(struct spi_device *spi)
{
struct ks8995_switch *ks;
int err;
int variant = spi_get_device_id(spi)->driver_data;
if (variant >= max_variant) {
dev_err(&spi->dev, "bad chip variant %d\n", variant);
return -ENODEV;
}
ks = devm_kzalloc(&spi->dev, sizeof(*ks), GFP_KERNEL);
if (!ks)
return -ENOMEM;
mutex_init(&ks->lock);
ks->spi = spi;
ks->chip = &ks8995_chip[variant];
if (ks->spi->dev.of_node) {
ks->pdata = devm_kzalloc(&spi->dev, sizeof(*ks->pdata),
GFP_KERNEL);
if (!ks->pdata)
return -ENOMEM;
ks->pdata->reset_gpio = -1;
ks8995_parse_dt(ks);
}
if (!ks->pdata)
ks->pdata = spi->dev.platform_data;
if (ks->pdata && gpio_is_valid(ks->pdata->reset_gpio)) {
unsigned long flags;
flags = (ks->pdata->reset_gpio_flags == OF_GPIO_ACTIVE_LOW ?
GPIOF_ACTIVE_LOW : 0);
err = devm_gpio_request_one(&spi->dev,
ks->pdata->reset_gpio,
flags, "switch-reset");
if (err) {
dev_err(&spi->dev,
"failed to get reset-gpios: %d\n", err);
return -EIO;
}
gpiod_set_value(gpio_to_desc(ks->pdata->reset_gpio), 0);
}
spi_set_drvdata(spi, ks);
spi->mode = SPI_MODE_0;
spi->bits_per_word = 8;
err = spi_setup(spi);
if (err) {
dev_err(&spi->dev, "spi_setup failed, err=%d\n", err);
return err;
}
err = ks8995_get_revision(ks);
if (err)
return err;
memcpy(&ks->regs_attr, &ks8995_registers_attr, sizeof(ks->regs_attr));
ks->regs_attr.size = ks->chip->regs_size;
err = ks8995_reset(ks);
if (err)
return err;
sysfs_attr_init(&ks->regs_attr.attr);
err = sysfs_create_bin_file(&spi->dev.kobj, &ks->regs_attr);
if (err) {
dev_err(&spi->dev, "unable to create sysfs file, err=%d\n",
err);
return err;
}
dev_info(&spi->dev, "%s device found, Chip ID:%x, Revision:%x\n",
ks->chip->name, ks->chip->chip_id, ks->revision_id);
return 0;
}
static int ks8995_remove(struct spi_device *spi)
{
struct ks8995_switch *ks = spi_get_drvdata(spi);
sysfs_remove_bin_file(&spi->dev.kobj, &ks->regs_attr);
if (ks->pdata && gpio_is_valid(ks->pdata->reset_gpio))
gpiod_set_value(gpio_to_desc(ks->pdata->reset_gpio), 1);
return 0;
}
