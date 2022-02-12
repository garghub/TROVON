static s32 stub_xfer(struct i2c_adapter * adap, u16 addr, unsigned short flags,
char read_write, u8 command, int size, union i2c_smbus_data * data)
{
s32 ret;
int i, len;
struct stub_chip *chip = NULL;
for (i = 0; i < MAX_CHIPS && chip_addr[i]; i++) {
if (addr == chip_addr[i]) {
chip = stub_chips + i;
break;
}
}
if (!chip)
return -ENODEV;
switch (size) {
case I2C_SMBUS_QUICK:
dev_dbg(&adap->dev, "smbus quick - addr 0x%02x\n", addr);
ret = 0;
break;
case I2C_SMBUS_BYTE:
if (read_write == I2C_SMBUS_WRITE) {
chip->pointer = command;
dev_dbg(&adap->dev, "smbus byte - addr 0x%02x, "
"wrote 0x%02x.\n",
addr, command);
} else {
data->byte = chip->words[chip->pointer++] & 0xff;
dev_dbg(&adap->dev, "smbus byte - addr 0x%02x, "
"read 0x%02x.\n",
addr, data->byte);
}
ret = 0;
break;
case I2C_SMBUS_BYTE_DATA:
if (read_write == I2C_SMBUS_WRITE) {
chip->words[command] &= 0xff00;
chip->words[command] |= data->byte;
dev_dbg(&adap->dev, "smbus byte data - addr 0x%02x, "
"wrote 0x%02x at 0x%02x.\n",
addr, data->byte, command);
} else {
data->byte = chip->words[command] & 0xff;
dev_dbg(&adap->dev, "smbus byte data - addr 0x%02x, "
"read 0x%02x at 0x%02x.\n",
addr, data->byte, command);
}
chip->pointer = command + 1;
ret = 0;
break;
case I2C_SMBUS_WORD_DATA:
if (read_write == I2C_SMBUS_WRITE) {
chip->words[command] = data->word;
dev_dbg(&adap->dev, "smbus word data - addr 0x%02x, "
"wrote 0x%04x at 0x%02x.\n",
addr, data->word, command);
} else {
data->word = chip->words[command];
dev_dbg(&adap->dev, "smbus word data - addr 0x%02x, "
"read 0x%04x at 0x%02x.\n",
addr, data->word, command);
}
ret = 0;
break;
case I2C_SMBUS_I2C_BLOCK_DATA:
len = data->block[0];
if (read_write == I2C_SMBUS_WRITE) {
for (i = 0; i < len; i++) {
chip->words[command + i] &= 0xff00;
chip->words[command + i] |= data->block[1 + i];
}
dev_dbg(&adap->dev, "i2c block data - addr 0x%02x, "
"wrote %d bytes at 0x%02x.\n",
addr, len, command);
} else {
for (i = 0; i < len; i++) {
data->block[1 + i] =
chip->words[command + i] & 0xff;
}
dev_dbg(&adap->dev, "i2c block data - addr 0x%02x, "
"read %d bytes at 0x%02x.\n",
addr, len, command);
}
ret = 0;
break;
default:
dev_dbg(&adap->dev, "Unsupported I2C/SMBus command\n");
ret = -EOPNOTSUPP;
break;
}
return ret;
}
static u32 stub_func(struct i2c_adapter *adapter)
{
return STUB_FUNC & functionality;
}
static int __init i2c_stub_init(void)
{
int i, ret;
if (!chip_addr[0]) {
printk(KERN_ERR "i2c-stub: Please specify a chip address\n");
return -ENODEV;
}
for (i = 0; i < MAX_CHIPS && chip_addr[i]; i++) {
if (chip_addr[i] < 0x03 || chip_addr[i] > 0x77) {
printk(KERN_ERR "i2c-stub: Invalid chip address "
"0x%02x\n", chip_addr[i]);
return -EINVAL;
}
printk(KERN_INFO "i2c-stub: Virtual chip at 0x%02x\n",
chip_addr[i]);
}
stub_chips = kzalloc(i * sizeof(struct stub_chip), GFP_KERNEL);
if (!stub_chips) {
printk(KERN_ERR "i2c-stub: Out of memory\n");
return -ENOMEM;
}
ret = i2c_add_adapter(&stub_adapter);
if (ret)
kfree(stub_chips);
return ret;
}
static void __exit i2c_stub_exit(void)
{
i2c_del_adapter(&stub_adapter);
kfree(stub_chips);
}
