static int at25_ee_read(void *priv, unsigned int offset,
void *val, size_t count)
{
struct at25_data *at25 = priv;
char *buf = val;
u8 command[EE_MAXADDRLEN + 1];
u8 *cp;
ssize_t status;
struct spi_transfer t[2];
struct spi_message m;
u8 instr;
if (unlikely(offset >= at25->chip.byte_len))
return -EINVAL;
if ((offset + count) > at25->chip.byte_len)
count = at25->chip.byte_len - offset;
if (unlikely(!count))
return -EINVAL;
cp = command;
instr = AT25_READ;
if (at25->chip.flags & EE_INSTR_BIT3_IS_ADDR)
if (offset >= (1U << (at25->addrlen * 8)))
instr |= AT25_INSTR_BIT3;
*cp++ = instr;
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
dev_dbg(&at25->spi->dev, "read %zu bytes at %d --> %zd\n",
count, offset, status);
mutex_unlock(&at25->lock);
return status;
}
static int at25_ee_write(void *priv, unsigned int off, void *val, size_t count)
{
struct at25_data *at25 = priv;
const char *buf = val;
int status = 0;
unsigned buf_size;
u8 *bounce;
if (unlikely(off >= at25->chip.byte_len))
return -EFBIG;
if ((off + count) > at25->chip.byte_len)
count = at25->chip.byte_len - off;
if (unlikely(!count))
return -EINVAL;
buf_size = at25->chip.page_size;
if (buf_size > io_limit)
buf_size = io_limit;
bounce = kmalloc(buf_size + at25->addrlen + 1, GFP_KERNEL);
if (!bounce)
return -ENOMEM;
mutex_lock(&at25->lock);
do {
unsigned long timeout, retries;
unsigned segment;
unsigned offset = (unsigned) off;
u8 *cp = bounce;
int sr;
u8 instr;
*cp = AT25_WREN;
status = spi_write(at25->spi, cp, 1);
if (status < 0) {
dev_dbg(&at25->spi->dev, "WREN --> %d\n", status);
break;
}
instr = AT25_WRITE;
if (at25->chip.flags & EE_INSTR_BIT3_IS_ADDR)
if (offset >= (1U << (at25->addrlen * 8)))
instr |= AT25_INSTR_BIT3;
*cp++ = instr;
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
dev_dbg(&at25->spi->dev, "write %u bytes at %u --> %d\n",
segment, offset, status);
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
"write %u bytes offset %u, timeout after %u msecs\n",
segment, offset,
jiffies_to_msecs(jiffies -
(timeout - EE_TIMEOUT)));
status = -ETIMEDOUT;
break;
}
off += segment;
buf += segment;
count -= segment;
} while (count > 0);
mutex_unlock(&at25->lock);
kfree(bounce);
return status;
}
static int at25_fw_to_chip(struct device *dev, struct spi_eeprom *chip)
{
u32 val;
memset(chip, 0, sizeof(*chip));
strncpy(chip->name, "at25", sizeof(chip->name));
if (device_property_read_u32(dev, "size", &val) == 0 ||
device_property_read_u32(dev, "at25,byte-len", &val) == 0) {
chip->byte_len = val;
} else {
dev_err(dev, "Error: missing \"size\" property\n");
return -ENODEV;
}
if (device_property_read_u32(dev, "pagesize", &val) == 0 ||
device_property_read_u32(dev, "at25,page-size", &val) == 0) {
chip->page_size = (u16)val;
} else {
dev_err(dev, "Error: missing \"pagesize\" property\n");
return -ENODEV;
}
if (device_property_read_u32(dev, "at25,addr-mode", &val) == 0) {
chip->flags = (u16)val;
} else {
if (device_property_read_u32(dev, "address-width", &val)) {
dev_err(dev,
"Error: missing \"address-width\" property\n");
return -ENODEV;
}
switch (val) {
case 8:
chip->flags |= EE_ADDR1;
break;
case 16:
chip->flags |= EE_ADDR2;
break;
case 24:
chip->flags |= EE_ADDR3;
break;
default:
dev_err(dev,
"Error: bad \"address-width\" property: %u\n",
val);
return -ENODEV;
}
if (device_property_present(dev, "read-only"))
chip->flags |= EE_READONLY;
}
return 0;
}
static int at25_probe(struct spi_device *spi)
{
struct at25_data *at25 = NULL;
struct spi_eeprom chip;
int err;
int sr;
int addrlen;
if (!spi->dev.platform_data) {
err = at25_fw_to_chip(&spi->dev, &chip);
if (err)
return err;
} else
chip = *(struct spi_eeprom *)spi->dev.platform_data;
if (chip.flags & EE_ADDR1)
addrlen = 1;
else if (chip.flags & EE_ADDR2)
addrlen = 2;
else if (chip.flags & EE_ADDR3)
addrlen = 3;
else {
dev_dbg(&spi->dev, "unsupported address type\n");
return -EINVAL;
}
sr = spi_w8r8(spi, AT25_RDSR);
if (sr < 0 || sr & AT25_SR_nRDY) {
dev_dbg(&spi->dev, "rdsr --> %d (%02x)\n", sr, sr);
return -ENXIO;
}
at25 = devm_kzalloc(&spi->dev, sizeof(struct at25_data), GFP_KERNEL);
if (!at25)
return -ENOMEM;
mutex_init(&at25->lock);
at25->chip = chip;
at25->spi = spi;
spi_set_drvdata(spi, at25);
at25->addrlen = addrlen;
at25->nvmem_config.name = dev_name(&spi->dev);
at25->nvmem_config.dev = &spi->dev;
at25->nvmem_config.read_only = chip.flags & EE_READONLY;
at25->nvmem_config.root_only = true;
at25->nvmem_config.owner = THIS_MODULE;
at25->nvmem_config.compat = true;
at25->nvmem_config.base_dev = &spi->dev;
at25->nvmem_config.reg_read = at25_ee_read;
at25->nvmem_config.reg_write = at25_ee_write;
at25->nvmem_config.priv = at25;
at25->nvmem_config.stride = 4;
at25->nvmem_config.word_size = 1;
at25->nvmem_config.size = chip.byte_len;
at25->nvmem = nvmem_register(&at25->nvmem_config);
if (IS_ERR(at25->nvmem))
return PTR_ERR(at25->nvmem);
dev_info(&spi->dev, "%d %s %s eeprom%s, pagesize %u\n",
(chip.byte_len < 1024) ? chip.byte_len : (chip.byte_len / 1024),
(chip.byte_len < 1024) ? "Byte" : "KByte",
at25->chip.name,
(chip.flags & EE_READONLY) ? " (readonly)" : "",
at25->chip.page_size);
return 0;
}
static int at25_remove(struct spi_device *spi)
{
struct at25_data *at25;
at25 = spi_get_drvdata(spi);
nvmem_unregister(at25->nvmem);
return 0;
}
