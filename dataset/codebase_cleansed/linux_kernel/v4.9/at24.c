static struct i2c_client *at24_translate_offset(struct at24_data *at24,
unsigned int *offset)
{
unsigned i;
if (at24->chip.flags & AT24_FLAG_ADDR16) {
i = *offset >> 16;
*offset &= 0xffff;
} else {
i = *offset >> 8;
*offset &= 0xff;
}
return at24->client[i];
}
static ssize_t at24_eeprom_read_smbus(struct at24_data *at24, char *buf,
unsigned int offset, size_t count)
{
unsigned long timeout, read_time;
struct i2c_client *client;
int status;
client = at24_translate_offset(at24, &offset);
if (count > io_limit)
count = io_limit;
if (count > I2C_SMBUS_BLOCK_MAX)
count = I2C_SMBUS_BLOCK_MAX;
loop_until_timeout(timeout, read_time) {
status = i2c_smbus_read_i2c_block_data_or_emulated(client,
offset,
count, buf);
dev_dbg(&client->dev, "read %zu@%d --> %d (%ld)\n",
count, offset, status, jiffies);
if (status == count)
return count;
}
return -ETIMEDOUT;
}
static ssize_t at24_eeprom_read_i2c(struct at24_data *at24, char *buf,
unsigned int offset, size_t count)
{
unsigned long timeout, read_time;
struct i2c_client *client;
struct i2c_msg msg[2];
int status, i;
u8 msgbuf[2];
memset(msg, 0, sizeof(msg));
client = at24_translate_offset(at24, &offset);
if (count > io_limit)
count = io_limit;
i = 0;
if (at24->chip.flags & AT24_FLAG_ADDR16)
msgbuf[i++] = offset >> 8;
msgbuf[i++] = offset;
msg[0].addr = client->addr;
msg[0].buf = msgbuf;
msg[0].len = i;
msg[1].addr = client->addr;
msg[1].flags = I2C_M_RD;
msg[1].buf = buf;
msg[1].len = count;
loop_until_timeout(timeout, read_time) {
status = i2c_transfer(client->adapter, msg, 2);
if (status == 2)
status = count;
dev_dbg(&client->dev, "read %zu@%d --> %d (%ld)\n",
count, offset, status, jiffies);
if (status == count)
return count;
}
return -ETIMEDOUT;
}
static ssize_t at24_eeprom_read_serial(struct at24_data *at24, char *buf,
unsigned int offset, size_t count)
{
unsigned long timeout, read_time;
struct i2c_client *client;
struct i2c_msg msg[2];
u8 addrbuf[2];
int status;
client = at24_translate_offset(at24, &offset);
memset(msg, 0, sizeof(msg));
msg[0].addr = client->addr;
msg[0].buf = addrbuf;
if (at24->chip.flags & AT24_FLAG_ADDR16) {
addrbuf[0] = 0x08;
addrbuf[1] = offset;
msg[0].len = 2;
} else {
addrbuf[0] = 0x80 + offset;
msg[0].len = 1;
}
msg[1].addr = client->addr;
msg[1].flags = I2C_M_RD;
msg[1].buf = buf;
msg[1].len = count;
loop_until_timeout(timeout, read_time) {
status = i2c_transfer(client->adapter, msg, 2);
if (status == 2)
return count;
}
return -ETIMEDOUT;
}
static ssize_t at24_eeprom_read_mac(struct at24_data *at24, char *buf,
unsigned int offset, size_t count)
{
unsigned long timeout, read_time;
struct i2c_client *client;
struct i2c_msg msg[2];
u8 addrbuf[2];
int status;
client = at24_translate_offset(at24, &offset);
memset(msg, 0, sizeof(msg));
msg[0].addr = client->addr;
msg[0].buf = addrbuf;
addrbuf[0] = 0x90 + offset;
msg[0].len = 1;
msg[1].addr = client->addr;
msg[1].flags = I2C_M_RD;
msg[1].buf = buf;
msg[1].len = count;
loop_until_timeout(timeout, read_time) {
status = i2c_transfer(client->adapter, msg, 2);
if (status == 2)
return count;
}
return -ETIMEDOUT;
}
static size_t at24_adjust_write_count(struct at24_data *at24,
unsigned int offset, size_t count)
{
unsigned next_page;
if (count > at24->write_max)
count = at24->write_max;
next_page = roundup(offset + 1, at24->chip.page_size);
if (offset + count > next_page)
count = next_page - offset;
return count;
}
static ssize_t at24_eeprom_write_smbus_block(struct at24_data *at24,
const char *buf,
unsigned int offset, size_t count)
{
unsigned long timeout, write_time;
struct i2c_client *client;
ssize_t status = 0;
client = at24_translate_offset(at24, &offset);
count = at24_adjust_write_count(at24, offset, count);
loop_until_timeout(timeout, write_time) {
status = i2c_smbus_write_i2c_block_data(client,
offset, count, buf);
if (status == 0)
status = count;
dev_dbg(&client->dev, "write %zu@%d --> %zd (%ld)\n",
count, offset, status, jiffies);
if (status == count)
return count;
}
return -ETIMEDOUT;
}
static ssize_t at24_eeprom_write_smbus_byte(struct at24_data *at24,
const char *buf,
unsigned int offset, size_t count)
{
unsigned long timeout, write_time;
struct i2c_client *client;
ssize_t status = 0;
client = at24_translate_offset(at24, &offset);
loop_until_timeout(timeout, write_time) {
status = i2c_smbus_write_byte_data(client, offset, buf[0]);
if (status == 0)
status = count;
dev_dbg(&client->dev, "write %zu@%d --> %zd (%ld)\n",
count, offset, status, jiffies);
if (status == count)
return count;
}
return -ETIMEDOUT;
}
static ssize_t at24_eeprom_write_i2c(struct at24_data *at24, const char *buf,
unsigned int offset, size_t count)
{
unsigned long timeout, write_time;
struct i2c_client *client;
struct i2c_msg msg;
ssize_t status = 0;
int i = 0;
client = at24_translate_offset(at24, &offset);
count = at24_adjust_write_count(at24, offset, count);
msg.addr = client->addr;
msg.flags = 0;
msg.buf = at24->writebuf;
if (at24->chip.flags & AT24_FLAG_ADDR16)
msg.buf[i++] = offset >> 8;
msg.buf[i++] = offset;
memcpy(&msg.buf[i], buf, count);
msg.len = i + count;
loop_until_timeout(timeout, write_time) {
status = i2c_transfer(client->adapter, &msg, 1);
if (status == 1)
status = count;
dev_dbg(&client->dev, "write %zu@%d --> %zd (%ld)\n",
count, offset, status, jiffies);
if (status == count)
return count;
}
return -ETIMEDOUT;
}
static int at24_read(void *priv, unsigned int off, void *val, size_t count)
{
struct at24_data *at24 = priv;
char *buf = val;
if (unlikely(!count))
return count;
mutex_lock(&at24->lock);
while (count) {
int status;
status = at24->read_func(at24, buf, off, count);
if (status < 0) {
mutex_unlock(&at24->lock);
return status;
}
buf += status;
off += status;
count -= status;
}
mutex_unlock(&at24->lock);
return 0;
}
static int at24_write(void *priv, unsigned int off, void *val, size_t count)
{
struct at24_data *at24 = priv;
char *buf = val;
if (unlikely(!count))
return -EINVAL;
mutex_lock(&at24->lock);
while (count) {
int status;
status = at24->write_func(at24, buf, off, count);
if (status < 0) {
mutex_unlock(&at24->lock);
return status;
}
buf += status;
off += status;
count -= status;
}
mutex_unlock(&at24->lock);
return 0;
}
static void at24_get_ofdata(struct i2c_client *client,
struct at24_platform_data *chip)
{
const __be32 *val;
struct device_node *node = client->dev.of_node;
if (node) {
if (of_get_property(node, "read-only", NULL))
chip->flags |= AT24_FLAG_READONLY;
val = of_get_property(node, "pagesize", NULL);
if (val)
chip->page_size = be32_to_cpup(val);
}
}
static void at24_get_ofdata(struct i2c_client *client,
struct at24_platform_data *chip)
{ }
static int at24_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct at24_platform_data chip;
kernel_ulong_t magic = 0;
bool writable;
int use_smbus = 0;
int use_smbus_write = 0;
struct at24_data *at24;
int err;
unsigned i, num_addresses;
u8 test_byte;
if (client->dev.platform_data) {
chip = *(struct at24_platform_data *)client->dev.platform_data;
} else {
if (id) {
magic = id->driver_data;
} else {
const struct acpi_device_id *aid;
aid = acpi_match_device(at24_acpi_ids, &client->dev);
if (aid)
magic = aid->driver_data;
}
if (!magic)
return -ENODEV;
chip.byte_len = BIT(magic & AT24_BITMASK(AT24_SIZE_BYTELEN));
magic >>= AT24_SIZE_BYTELEN;
chip.flags = magic & AT24_BITMASK(AT24_SIZE_FLAGS);
chip.page_size = 1;
at24_get_ofdata(client, &chip);
chip.setup = NULL;
chip.context = NULL;
}
if (!is_power_of_2(chip.byte_len))
dev_warn(&client->dev,
"byte_len looks suspicious (no power of 2)!\n");
if (!chip.page_size) {
dev_err(&client->dev, "page_size must not be 0!\n");
return -EINVAL;
}
if (!is_power_of_2(chip.page_size))
dev_warn(&client->dev,
"page_size looks suspicious (no power of 2)!\n");
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
if (chip.flags & AT24_FLAG_ADDR16)
return -EPFNOSUPPORT;
if (i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_READ_I2C_BLOCK)) {
use_smbus = I2C_SMBUS_I2C_BLOCK_DATA;
} else if (i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_READ_WORD_DATA)) {
use_smbus = I2C_SMBUS_WORD_DATA;
} else if (i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_READ_BYTE_DATA)) {
use_smbus = I2C_SMBUS_BYTE_DATA;
} else {
return -EPFNOSUPPORT;
}
if (i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_WRITE_I2C_BLOCK)) {
use_smbus_write = I2C_SMBUS_I2C_BLOCK_DATA;
} else if (i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_WRITE_BYTE_DATA)) {
use_smbus_write = I2C_SMBUS_BYTE_DATA;
chip.page_size = 1;
}
}
if (chip.flags & AT24_FLAG_TAKE8ADDR)
num_addresses = 8;
else
num_addresses = DIV_ROUND_UP(chip.byte_len,
(chip.flags & AT24_FLAG_ADDR16) ? 65536 : 256);
at24 = devm_kzalloc(&client->dev, sizeof(struct at24_data) +
num_addresses * sizeof(struct i2c_client *), GFP_KERNEL);
if (!at24)
return -ENOMEM;
mutex_init(&at24->lock);
at24->use_smbus = use_smbus;
at24->use_smbus_write = use_smbus_write;
at24->chip = chip;
at24->num_addresses = num_addresses;
if ((chip.flags & AT24_FLAG_SERIAL) && (chip.flags & AT24_FLAG_MAC)) {
dev_err(&client->dev,
"invalid device data - cannot have both AT24_FLAG_SERIAL & AT24_FLAG_MAC.");
return -EINVAL;
}
if (chip.flags & AT24_FLAG_SERIAL) {
at24->read_func = at24_eeprom_read_serial;
} else if (chip.flags & AT24_FLAG_MAC) {
at24->read_func = at24_eeprom_read_mac;
} else {
at24->read_func = at24->use_smbus ? at24_eeprom_read_smbus
: at24_eeprom_read_i2c;
}
if (at24->use_smbus) {
if (at24->use_smbus_write == I2C_SMBUS_I2C_BLOCK_DATA)
at24->write_func = at24_eeprom_write_smbus_block;
else
at24->write_func = at24_eeprom_write_smbus_byte;
} else {
at24->write_func = at24_eeprom_write_i2c;
}
writable = !(chip.flags & AT24_FLAG_READONLY);
if (writable) {
if (!use_smbus || use_smbus_write) {
unsigned write_max = chip.page_size;
if (write_max > io_limit)
write_max = io_limit;
if (use_smbus && write_max > I2C_SMBUS_BLOCK_MAX)
write_max = I2C_SMBUS_BLOCK_MAX;
at24->write_max = write_max;
at24->writebuf = devm_kzalloc(&client->dev,
write_max + 2, GFP_KERNEL);
if (!at24->writebuf)
return -ENOMEM;
} else {
dev_warn(&client->dev,
"cannot write due to controller restrictions.");
}
}
at24->client[0] = client;
for (i = 1; i < num_addresses; i++) {
at24->client[i] = i2c_new_dummy(client->adapter,
client->addr + i);
if (!at24->client[i]) {
dev_err(&client->dev, "address 0x%02x unavailable\n",
client->addr + i);
err = -EADDRINUSE;
goto err_clients;
}
}
i2c_set_clientdata(client, at24);
err = at24_read(at24, 0, &test_byte, 1);
if (err) {
err = -ENODEV;
goto err_clients;
}
at24->nvmem_config.name = dev_name(&client->dev);
at24->nvmem_config.dev = &client->dev;
at24->nvmem_config.read_only = !writable;
at24->nvmem_config.root_only = true;
at24->nvmem_config.owner = THIS_MODULE;
at24->nvmem_config.compat = true;
at24->nvmem_config.base_dev = &client->dev;
at24->nvmem_config.reg_read = at24_read;
at24->nvmem_config.reg_write = at24_write;
at24->nvmem_config.priv = at24;
at24->nvmem_config.stride = 4;
at24->nvmem_config.word_size = 1;
at24->nvmem_config.size = chip.byte_len;
at24->nvmem = nvmem_register(&at24->nvmem_config);
if (IS_ERR(at24->nvmem)) {
err = PTR_ERR(at24->nvmem);
goto err_clients;
}
dev_info(&client->dev, "%u byte %s EEPROM, %s, %u bytes/write\n",
chip.byte_len, client->name,
writable ? "writable" : "read-only", at24->write_max);
if (use_smbus == I2C_SMBUS_WORD_DATA ||
use_smbus == I2C_SMBUS_BYTE_DATA) {
dev_notice(&client->dev, "Falling back to %s reads, "
"performance will suffer\n", use_smbus ==
I2C_SMBUS_WORD_DATA ? "word" : "byte");
}
if (chip.setup)
chip.setup(at24->nvmem, chip.context);
return 0;
err_clients:
for (i = 1; i < num_addresses; i++)
if (at24->client[i])
i2c_unregister_device(at24->client[i]);
return err;
}
static int at24_remove(struct i2c_client *client)
{
struct at24_data *at24;
int i;
at24 = i2c_get_clientdata(client);
nvmem_unregister(at24->nvmem);
for (i = 1; i < at24->num_addresses; i++)
i2c_unregister_device(at24->client[i]);
return 0;
}
static int __init at24_init(void)
{
if (!io_limit) {
pr_err("at24: io_limit must not be 0!\n");
return -EINVAL;
}
io_limit = rounddown_pow_of_two(io_limit);
return i2c_add_driver(&at24_driver);
}
static void __exit at24_exit(void)
{
i2c_del_driver(&at24_driver);
}
