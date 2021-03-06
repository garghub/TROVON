static inline bool has_quirk_single_word_read(struct eeprom_93xx46_dev *edev)
{
return edev->pdata->quirks & EEPROM_93XX46_QUIRK_SINGLE_WORD_READ;
}
static inline bool has_quirk_instruction_length(struct eeprom_93xx46_dev *edev)
{
return edev->pdata->quirks & EEPROM_93XX46_QUIRK_INSTRUCTION_LENGTH;
}
static ssize_t
eeprom_93xx46_read(struct eeprom_93xx46_dev *edev, char *buf,
unsigned off, size_t count)
{
ssize_t ret = 0;
if (unlikely(off >= edev->size))
return 0;
if ((off + count) > edev->size)
count = edev->size - off;
if (unlikely(!count))
return count;
mutex_lock(&edev->lock);
if (edev->pdata->prepare)
edev->pdata->prepare(edev);
while (count) {
struct spi_message m;
struct spi_transfer t[2] = { { 0 } };
u16 cmd_addr = OP_READ << edev->addrlen;
size_t nbytes = count;
int bits;
int err;
if (edev->addrlen == 7) {
cmd_addr |= off & 0x7f;
bits = 10;
if (has_quirk_single_word_read(edev))
nbytes = 1;
} else {
cmd_addr |= (off >> 1) & 0x3f;
bits = 9;
if (has_quirk_single_word_read(edev))
nbytes = 2;
}
dev_dbg(&edev->spi->dev, "read cmd 0x%x, %d Hz\n",
cmd_addr, edev->spi->max_speed_hz);
spi_message_init(&m);
t[0].tx_buf = (char *)&cmd_addr;
t[0].len = 2;
t[0].bits_per_word = bits;
spi_message_add_tail(&t[0], &m);
t[1].rx_buf = buf;
t[1].len = count;
t[1].bits_per_word = 8;
spi_message_add_tail(&t[1], &m);
err = spi_sync(edev->spi, &m);
ndelay(250);
if (err) {
dev_err(&edev->spi->dev, "read %zu bytes at %d: err. %d\n",
nbytes, (int)off, err);
ret = err;
break;
}
buf += nbytes;
off += nbytes;
count -= nbytes;
ret += nbytes;
}
if (edev->pdata->finish)
edev->pdata->finish(edev);
mutex_unlock(&edev->lock);
return ret;
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
if (has_quirk_instruction_length(edev)) {
cmd_addr <<= 2;
bits += 2;
}
dev_dbg(&edev->spi->dev, "ew%s cmd 0x%04x, %d bits\n",
is_on ? "en" : "ds", cmd_addr, bits);
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
cmd_addr |= (off >> 1) & 0x3f;
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
eeprom_93xx46_write(struct eeprom_93xx46_dev *edev, const char *buf,
loff_t off, size_t count)
{
int i, ret, step = 1;
if (unlikely(off >= edev->size))
return -EFBIG;
if ((off + count) > edev->size)
count = edev->size - off;
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
static int eeprom_93xx46_regmap_read(void *context, const void *reg,
size_t reg_size, void *val,
size_t val_size)
{
struct eeprom_93xx46_dev *eeprom_93xx46 = context;
off_t offset = *(u32 *)reg;
int err;
err = eeprom_93xx46_read(eeprom_93xx46, val, offset, val_size);
if (err)
return err;
return 0;
}
static int eeprom_93xx46_regmap_write(void *context, const void *data,
size_t count)
{
struct eeprom_93xx46_dev *eeprom_93xx46 = context;
const char *buf;
u32 offset;
size_t len;
int err;
memcpy(&offset, data, sizeof(offset));
buf = (const char *)data + sizeof(offset);
len = count - sizeof(offset);
err = eeprom_93xx46_write(eeprom_93xx46, buf, offset, len);
if (err)
return err;
return 0;
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
if (has_quirk_instruction_length(edev)) {
cmd_addr <<= 2;
bits += 2;
}
dev_dbg(&edev->spi->dev, "eral cmd 0x%04x, %d bits\n", cmd_addr, bits);
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
static void select_assert(void *context)
{
struct eeprom_93xx46_dev *edev = context;
gpiod_set_value_cansleep(edev->pdata->select, 1);
}
static void select_deassert(void *context)
{
struct eeprom_93xx46_dev *edev = context;
gpiod_set_value_cansleep(edev->pdata->select, 0);
}
static int eeprom_93xx46_probe_dt(struct spi_device *spi)
{
const struct of_device_id *of_id =
of_match_device(eeprom_93xx46_of_table, &spi->dev);
struct device_node *np = spi->dev.of_node;
struct eeprom_93xx46_platform_data *pd;
u32 tmp;
int gpio;
enum of_gpio_flags of_flags;
int ret;
pd = devm_kzalloc(&spi->dev, sizeof(*pd), GFP_KERNEL);
if (!pd)
return -ENOMEM;
ret = of_property_read_u32(np, "data-size", &tmp);
if (ret < 0) {
dev_err(&spi->dev, "data-size property not found\n");
return ret;
}
if (tmp == 8) {
pd->flags |= EE_ADDR8;
} else if (tmp == 16) {
pd->flags |= EE_ADDR16;
} else {
dev_err(&spi->dev, "invalid data-size (%d)\n", tmp);
return -EINVAL;
}
if (of_property_read_bool(np, "read-only"))
pd->flags |= EE_READONLY;
gpio = of_get_named_gpio_flags(np, "select-gpios", 0, &of_flags);
if (gpio_is_valid(gpio)) {
unsigned long flags =
of_flags == OF_GPIO_ACTIVE_LOW ? GPIOF_ACTIVE_LOW : 0;
ret = devm_gpio_request_one(&spi->dev, gpio, flags,
"eeprom_93xx46_select");
if (ret)
return ret;
pd->select = gpio_to_desc(gpio);
pd->prepare = select_assert;
pd->finish = select_deassert;
gpiod_direction_output(pd->select, 0);
}
if (of_id->data) {
const struct eeprom_93xx46_devtype_data *data = of_id->data;
pd->quirks = data->quirks;
}
spi->dev.platform_data = pd;
return 0;
}
static int eeprom_93xx46_probe(struct spi_device *spi)
{
struct eeprom_93xx46_platform_data *pd;
struct eeprom_93xx46_dev *edev;
struct regmap *regmap;
int err;
if (spi->dev.of_node) {
err = eeprom_93xx46_probe_dt(spi);
if (err < 0)
return err;
}
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
edev->size = 128;
edev->regmap_config.reg_bits = 32;
edev->regmap_config.val_bits = 8;
edev->regmap_config.reg_stride = 1;
edev->regmap_config.max_register = edev->size - 1;
regmap = devm_regmap_init(&spi->dev, &eeprom_93xx46_regmap_bus, edev,
&edev->regmap_config);
if (IS_ERR(regmap)) {
dev_err(&spi->dev, "regmap init failed\n");
err = PTR_ERR(regmap);
goto fail;
}
edev->nvmem_config.name = dev_name(&spi->dev);
edev->nvmem_config.dev = &spi->dev;
edev->nvmem_config.read_only = pd->flags & EE_READONLY;
edev->nvmem_config.root_only = true;
edev->nvmem_config.owner = THIS_MODULE;
edev->nvmem_config.compat = true;
edev->nvmem_config.base_dev = &spi->dev;
edev->nvmem = nvmem_register(&edev->nvmem_config);
if (IS_ERR(edev->nvmem)) {
err = PTR_ERR(edev->nvmem);
goto fail;
}
dev_info(&spi->dev, "%d-bit eeprom %s\n",
(pd->flags & EE_ADDR8) ? 8 : 16,
(pd->flags & EE_READONLY) ? "(readonly)" : "");
if (!(pd->flags & EE_READONLY)) {
if (device_create_file(&spi->dev, &dev_attr_erase))
dev_err(&spi->dev, "can't create erase interface\n");
}
spi_set_drvdata(spi, edev);
return 0;
fail:
kfree(edev);
return err;
}
static int eeprom_93xx46_remove(struct spi_device *spi)
{
struct eeprom_93xx46_dev *edev = spi_get_drvdata(spi);
nvmem_unregister(edev->nvmem);
if (!(edev->pdata->flags & EE_READONLY))
device_remove_file(&spi->dev, &dev_attr_erase);
kfree(edev);
return 0;
}
