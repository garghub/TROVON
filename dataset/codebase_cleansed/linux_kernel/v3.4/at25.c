static ssize_t
at25_ee_read(
struct at25_data *at25,
char *buf,
unsigned offset,
size_t count
)
{
u8 command[EE_MAXADDRLEN + 1];
u8 *cp;
ssize_t status;
struct spi_transfer t[2];
struct spi_message m;
if (unlikely(offset >= at25->bin.size))
return 0;
if ((offset + count) > at25->bin.size)
count = at25->bin.size - offset;
if (unlikely(!count))
return count;
cp = command;
*cp++ = AT25_READ;
switch (at25->addrlen) {
default:
*cp++ = offset >> 16;
case 2:
*cp++ = offset >> 8;
case 1:
case 0:
*cp++ = offset >> 0;
}
spi_message_init(&m);
memset(t, 0, sizeof t);
t[0].tx_buf = command;
t[0].len = at25->addrlen + 1;
spi_message_add_tail(&t[0], &m);
t[1].rx_buf = buf;
t[1].len = count;
spi_message_add_tail(&t[1], &m);
mutex_lock(&at25->lock);
status = spi_sync(at25->spi, &m);
dev_dbg(&at25->spi->dev,
"read %Zd bytes at %d --> %d\n",
count, offset, (int) status);
mutex_unlock(&at25->lock);
return status ? status : count;
}
static ssize_t
at25_bin_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct device *dev;
struct at25_data *at25;
dev = container_of(kobj, struct device, kobj);
at25 = dev_get_drvdata(dev);
return at25_ee_read(at25, buf, off, count);
}
static ssize_t
at25_ee_write(struct at25_data *at25, const char *buf, loff_t off,
size_t count)
{
ssize_t status = 0;
unsigned written = 0;
unsigned buf_size;
u8 *bounce;
if (unlikely(off >= at25->bin.size))
return -EFBIG;
if ((off + count) > at25->bin.size)
count = at25->bin.size - off;
if (unlikely(!count))
return count;
buf_size = at25->chip.page_size;
if (buf_size > io_limit)
buf_size = io_limit;
bounce = kmalloc(buf_size + at25->addrlen + 1, GFP_KERNEL);
if (!bounce)
return -ENOMEM;
bounce[0] = AT25_WRITE;
mutex_lock(&at25->lock);
do {
unsigned long timeout, retries;
unsigned segment;
unsigned offset = (unsigned) off;
u8 *cp = bounce + 1;
int sr;
*cp = AT25_WREN;
status = spi_write(at25->spi, cp, 1);
if (status < 0) {
dev_dbg(&at25->spi->dev, "WREN --> %d\n",
(int) status);
break;
}
switch (at25->addrlen) {
default:
*cp++ = offset >> 16;
case 2:
*cp++ = offset >> 8;
case 1:
case 0:
*cp++ = offset >> 0;
}
segment = buf_size - (offset % buf_size);
if (segment > count)
segment = count;
memcpy(cp, buf, segment);
status = spi_write(at25->spi, bounce,
segment + at25->addrlen + 1);
dev_dbg(&at25->spi->dev,
"write %u bytes at %u --> %d\n",
segment, offset, (int) status);
if (status < 0)
break;
timeout = jiffies + msecs_to_jiffies(EE_TIMEOUT);
retries = 0;
do {
sr = spi_w8r8(at25->spi, AT25_RDSR);
if (sr < 0 || (sr & AT25_SR_nRDY)) {
dev_dbg(&at25->spi->dev,
"rdsr --> %d (%02x)\n", sr, sr);
msleep(1);
continue;
}
if (!(sr & AT25_SR_nRDY))
break;
} while (retries++ < 3 || time_before_eq(jiffies, timeout));
if ((sr < 0) || (sr & AT25_SR_nRDY)) {
dev_err(&at25->spi->dev,
"write %d bytes offset %d, "
"timeout after %u msecs\n",
segment, offset,
jiffies_to_msecs(jiffies -
(timeout - EE_TIMEOUT)));
status = -ETIMEDOUT;
break;
}
off += segment;
buf += segment;
count -= segment;
written += segment;
} while (count > 0);
mutex_unlock(&at25->lock);
kfree(bounce);
return written ? written : status;
}
static ssize_t
at25_bin_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct device *dev;
struct at25_data *at25;
dev = container_of(kobj, struct device, kobj);
at25 = dev_get_drvdata(dev);
return at25_ee_write(at25, buf, off, count);
}
static ssize_t at25_mem_read(struct memory_accessor *mem, char *buf,
off_t offset, size_t count)
{
struct at25_data *at25 = container_of(mem, struct at25_data, mem);
return at25_ee_read(at25, buf, offset, count);
}
static ssize_t at25_mem_write(struct memory_accessor *mem, const char *buf,
off_t offset, size_t count)
{
struct at25_data *at25 = container_of(mem, struct at25_data, mem);
return at25_ee_write(at25, buf, offset, count);
}
static int at25_probe(struct spi_device *spi)
{
struct at25_data *at25 = NULL;
const struct spi_eeprom *chip;
int err;
int sr;
int addrlen;
chip = spi->dev.platform_data;
if (!chip) {
dev_dbg(&spi->dev, "no chip description\n");
err = -ENODEV;
goto fail;
}
if (chip->flags & EE_ADDR1)
addrlen = 1;
else if (chip->flags & EE_ADDR2)
addrlen = 2;
else if (chip->flags & EE_ADDR3)
addrlen = 3;
else {
dev_dbg(&spi->dev, "unsupported address type\n");
err = -EINVAL;
goto fail;
}
sr = spi_w8r8(spi, AT25_RDSR);
if (sr < 0 || sr & AT25_SR_nRDY) {
dev_dbg(&spi->dev, "rdsr --> %d (%02x)\n", sr, sr);
err = -ENXIO;
goto fail;
}
if (!(at25 = kzalloc(sizeof *at25, GFP_KERNEL))) {
err = -ENOMEM;
goto fail;
}
mutex_init(&at25->lock);
at25->chip = *chip;
at25->spi = spi_dev_get(spi);
dev_set_drvdata(&spi->dev, at25);
at25->addrlen = addrlen;
sysfs_bin_attr_init(&at25->bin);
at25->bin.attr.name = "eeprom";
at25->bin.attr.mode = S_IRUSR;
at25->bin.read = at25_bin_read;
at25->mem.read = at25_mem_read;
at25->bin.size = at25->chip.byte_len;
if (!(chip->flags & EE_READONLY)) {
at25->bin.write = at25_bin_write;
at25->bin.attr.mode |= S_IWUSR;
at25->mem.write = at25_mem_write;
}
err = sysfs_create_bin_file(&spi->dev.kobj, &at25->bin);
if (err)
goto fail;
if (chip->setup)
chip->setup(&at25->mem, chip->context);
dev_info(&spi->dev, "%Zd %s %s eeprom%s, pagesize %u\n",
(at25->bin.size < 1024)
? at25->bin.size
: (at25->bin.size / 1024),
(at25->bin.size < 1024) ? "Byte" : "KByte",
at25->chip.name,
(chip->flags & EE_READONLY) ? " (readonly)" : "",
at25->chip.page_size);
return 0;
fail:
dev_dbg(&spi->dev, "probe err %d\n", err);
kfree(at25);
return err;
}
static int __devexit at25_remove(struct spi_device *spi)
{
struct at25_data *at25;
at25 = dev_get_drvdata(&spi->dev);
sysfs_remove_bin_file(&spi->dev.kobj, &at25->bin);
kfree(at25);
return 0;
}
