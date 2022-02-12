static ssize_t
eeprom_93xx46_bin_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct eeprom_93xx46_dev *edev;
struct device *dev;
struct spi_message m;
struct spi_transfer t[2];
int bits, ret;
u16 cmd_addr;
dev = container_of(kobj, struct device, kobj);
edev = dev_get_drvdata(dev);
if (unlikely(off >= edev->bin.size))
return 0;
if ((off + count) > edev->bin.size)
count = edev->bin.size - off;
if (unlikely(!count))
return count;
cmd_addr = OP_READ << edev->addrlen;
if (edev->addrlen == 7) {
cmd_addr |= off & 0x7f;
bits = 10;
} else {
cmd_addr |= off & 0x3f;
bits = 9;
}
dev_dbg(&edev->spi->dev, "read cmd 0x%x, %d Hz\n",
cmd_addr, edev->spi->max_speed_hz);
spi_message_init(&m);
memset(t, 0, sizeof(t));
t[0].tx_buf = (char *)&cmd_addr;
t[0].len = 2;
t[0].bits_per_word = bits;
spi_message_add_tail(&t[0], &m);
t[1].rx_buf = buf;
t[1].len = count;
t[1].bits_per_word = 8;
spi_message_add_tail(&t[1], &m);
mutex_lock(&edev->lock);
if (edev->pdata->prepare)
edev->pdata->prepare(edev);
ret = spi_sync(edev->spi, &m);
ndelay(250);
if (ret) {
dev_err(&edev->spi->dev, "read %zu bytes at %d: err. %d\n",
count, (int)off, ret);
}
if (edev->pdata->finish)
edev->pdata->finish(edev);
mutex_unlock(&edev->lock);
return ret ? : count;
}
static int eeprom_93xx46_ew(struct eeprom_93xx46_dev *edev, int is_on)
{
struct spi_message m;
struct spi_transfer t;
int bits, ret;
u16 cmd_addr;
cmd_addr = OP_START << edev->addrlen;
if (edev->addrlen == 7) {
cmd_addr |= (is_on ? ADDR_EWEN : ADDR_EWDS) << 1;
bits = 10;
} else {
cmd_addr |= (is_on ? ADDR_EWEN : ADDR_EWDS);
bits = 9;
}
dev_dbg(&edev->spi->dev, "ew cmd 0x%04x\n", cmd_addr);
spi_message_init(&m);
memset(&t, 0, sizeof(t));
t.tx_buf = &cmd_addr;
t.len = 2;
t.bits_per_word = bits;
spi_message_add_tail(&t, &m);
mutex_lock(&edev->lock);
if (edev->pdata->prepare)
edev->pdata->prepare(edev);
ret = spi_sync(edev->spi, &m);
ndelay(250);
if (ret)
dev_err(&edev->spi->dev, "erase/write %sable error %d\n",
is_on ? "en" : "dis", ret);
if (edev->pdata->finish)
edev->pdata->finish(edev);
mutex_unlock(&edev->lock);
return ret;
}
static ssize_t
eeprom_93xx46_write_word(struct eeprom_93xx46_dev *edev,
const char *buf, unsigned off)
{
struct spi_message m;
struct spi_transfer t[2];
int bits, data_len, ret;
u16 cmd_addr;
cmd_addr = OP_WRITE << edev->addrlen;
if (edev->addrlen == 7) {
cmd_addr |= off & 0x7f;
bits = 10;
data_len = 1;
} else {
cmd_addr |= off & 0x3f;
bits = 9;
data_len = 2;
}
dev_dbg(&edev->spi->dev, "write cmd 0x%x\n", cmd_addr);
spi_message_init(&m);
memset(t, 0, sizeof(t));
t[0].tx_buf = (char *)&cmd_addr;
t[0].len = 2;
t[0].bits_per_word = bits;
spi_message_add_tail(&t[0], &m);
t[1].tx_buf = buf;
t[1].len = data_len;
t[1].bits_per_word = 8;
spi_message_add_tail(&t[1], &m);
ret = spi_sync(edev->spi, &m);
mdelay(6);
return ret;
}
static ssize_t
eeprom_93xx46_bin_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct eeprom_93xx46_dev *edev;
struct device *dev;
int i, ret, step = 1;
dev = container_of(kobj, struct device, kobj);
edev = dev_get_drvdata(dev);
if (unlikely(off >= edev->bin.size))
return 0;
if ((off + count) > edev->bin.size)
count = edev->bin.size - off;
if (unlikely(!count))
return count;
if (edev->addrlen == 6) {
step = 2;
count &= ~1;
}
ret = eeprom_93xx46_ew(edev, 1);
if (ret)
return ret;
mutex_lock(&edev->lock);
if (edev->pdata->prepare)
edev->pdata->prepare(edev);
for (i = 0; i < count; i += step) {
ret = eeprom_93xx46_write_word(edev, &buf[i], off + i);
if (ret) {
dev_err(&edev->spi->dev, "write failed at %d: %d\n",
(int)off + i, ret);
break;
}
}
if (edev->pdata->finish)
edev->pdata->finish(edev);
mutex_unlock(&edev->lock);
eeprom_93xx46_ew(edev, 0);
return ret ? : count;
}
static int eeprom_93xx46_eral(struct eeprom_93xx46_dev *edev)
{
struct eeprom_93xx46_platform_data *pd = edev->pdata;
struct spi_message m;
struct spi_transfer t;
int bits, ret;
u16 cmd_addr;
cmd_addr = OP_START << edev->addrlen;
if (edev->addrlen == 7) {
cmd_addr |= ADDR_ERAL << 1;
bits = 10;
} else {
cmd_addr |= ADDR_ERAL;
bits = 9;
}
spi_message_init(&m);
memset(&t, 0, sizeof(t));
t.tx_buf = &cmd_addr;
t.len = 2;
t.bits_per_word = bits;
spi_message_add_tail(&t, &m);
mutex_lock(&edev->lock);
if (edev->pdata->prepare)
edev->pdata->prepare(edev);
ret = spi_sync(edev->spi, &m);
if (ret)
dev_err(&edev->spi->dev, "erase error %d\n", ret);
mdelay(6);
if (pd->finish)
pd->finish(edev);
mutex_unlock(&edev->lock);
return ret;
}
static ssize_t eeprom_93xx46_store_erase(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct eeprom_93xx46_dev *edev = dev_get_drvdata(dev);
int erase = 0, ret;
sscanf(buf, "%d", &erase);
if (erase) {
ret = eeprom_93xx46_ew(edev, 1);
if (ret)
return ret;
ret = eeprom_93xx46_eral(edev);
if (ret)
return ret;
ret = eeprom_93xx46_ew(edev, 0);
if (ret)
return ret;
}
return count;
}
static int __devinit eeprom_93xx46_probe(struct spi_device *spi)
{
struct eeprom_93xx46_platform_data *pd;
struct eeprom_93xx46_dev *edev;
int err;
pd = spi->dev.platform_data;
if (!pd) {
dev_err(&spi->dev, "missing platform data\n");
return -ENODEV;
}
edev = kzalloc(sizeof(*edev), GFP_KERNEL);
if (!edev)
return -ENOMEM;
if (pd->flags & EE_ADDR8)
edev->addrlen = 7;
else if (pd->flags & EE_ADDR16)
edev->addrlen = 6;
else {
dev_err(&spi->dev, "unspecified address type\n");
err = -EINVAL;
goto fail;
}
mutex_init(&edev->lock);
edev->spi = spi_dev_get(spi);
edev->pdata = pd;
sysfs_bin_attr_init(&edev->bin);
edev->bin.attr.name = "eeprom";
edev->bin.attr.mode = S_IRUSR;
edev->bin.read = eeprom_93xx46_bin_read;
edev->bin.size = 128;
if (!(pd->flags & EE_READONLY)) {
edev->bin.write = eeprom_93xx46_bin_write;
edev->bin.attr.mode |= S_IWUSR;
}
err = sysfs_create_bin_file(&spi->dev.kobj, &edev->bin);
if (err)
goto fail;
dev_info(&spi->dev, "%d-bit eeprom %s\n",
(pd->flags & EE_ADDR8) ? 8 : 16,
(pd->flags & EE_READONLY) ? "(readonly)" : "");
if (!(pd->flags & EE_READONLY)) {
if (device_create_file(&spi->dev, &dev_attr_erase))
dev_err(&spi->dev, "can't create erase interface\n");
}
dev_set_drvdata(&spi->dev, edev);
return 0;
fail:
kfree(edev);
return err;
}
static int __devexit eeprom_93xx46_remove(struct spi_device *spi)
{
struct eeprom_93xx46_dev *edev = dev_get_drvdata(&spi->dev);
if (!(edev->pdata->flags & EE_READONLY))
device_remove_file(&spi->dev, &dev_attr_erase);
sysfs_remove_bin_file(&spi->dev.kobj, &edev->bin);
dev_set_drvdata(&spi->dev, NULL);
kfree(edev);
return 0;
}
