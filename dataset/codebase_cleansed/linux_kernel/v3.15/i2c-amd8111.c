static int amd_ec_wait_write(struct amd_smbus *smbus)
{
int timeout = 500;
while ((inb(smbus->base + AMD_EC_SC) & AMD_EC_SC_IBF) && --timeout)
udelay(1);
if (!timeout) {
dev_warn(&smbus->dev->dev,
"Timeout while waiting for IBF to clear\n");
return -ETIMEDOUT;
}
return 0;
}
static int amd_ec_wait_read(struct amd_smbus *smbus)
{
int timeout = 500;
while ((~inb(smbus->base + AMD_EC_SC) & AMD_EC_SC_OBF) && --timeout)
udelay(1);
if (!timeout) {
dev_warn(&smbus->dev->dev,
"Timeout while waiting for OBF to set\n");
return -ETIMEDOUT;
}
return 0;
}
static int amd_ec_read(struct amd_smbus *smbus, unsigned char address,
unsigned char *data)
{
int status;
status = amd_ec_wait_write(smbus);
if (status)
return status;
outb(AMD_EC_CMD_RD, smbus->base + AMD_EC_CMD);
status = amd_ec_wait_write(smbus);
if (status)
return status;
outb(address, smbus->base + AMD_EC_DATA);
status = amd_ec_wait_read(smbus);
if (status)
return status;
*data = inb(smbus->base + AMD_EC_DATA);
return 0;
}
static int amd_ec_write(struct amd_smbus *smbus, unsigned char address,
unsigned char data)
{
int status;
status = amd_ec_wait_write(smbus);
if (status)
return status;
outb(AMD_EC_CMD_WR, smbus->base + AMD_EC_CMD);
status = amd_ec_wait_write(smbus);
if (status)
return status;
outb(address, smbus->base + AMD_EC_DATA);
status = amd_ec_wait_write(smbus);
if (status)
return status;
outb(data, smbus->base + AMD_EC_DATA);
return 0;
}
static s32 amd8111_access(struct i2c_adapter * adap, u16 addr,
unsigned short flags, char read_write, u8 command, int size,
union i2c_smbus_data * data)
{
struct amd_smbus *smbus = adap->algo_data;
unsigned char protocol, len, pec, temp[2];
int i, status;
protocol = (read_write == I2C_SMBUS_READ) ? AMD_SMB_PRTCL_READ
: AMD_SMB_PRTCL_WRITE;
pec = (flags & I2C_CLIENT_PEC) ? AMD_SMB_PRTCL_PEC : 0;
switch (size) {
case I2C_SMBUS_QUICK:
protocol |= AMD_SMB_PRTCL_QUICK;
read_write = I2C_SMBUS_WRITE;
break;
case I2C_SMBUS_BYTE:
if (read_write == I2C_SMBUS_WRITE) {
status = amd_ec_write(smbus, AMD_SMB_CMD,
command);
if (status)
return status;
}
protocol |= AMD_SMB_PRTCL_BYTE;
break;
case I2C_SMBUS_BYTE_DATA:
status = amd_ec_write(smbus, AMD_SMB_CMD, command);
if (status)
return status;
if (read_write == I2C_SMBUS_WRITE) {
status = amd_ec_write(smbus, AMD_SMB_DATA,
data->byte);
if (status)
return status;
}
protocol |= AMD_SMB_PRTCL_BYTE_DATA;
break;
case I2C_SMBUS_WORD_DATA:
status = amd_ec_write(smbus, AMD_SMB_CMD, command);
if (status)
return status;
if (read_write == I2C_SMBUS_WRITE) {
status = amd_ec_write(smbus, AMD_SMB_DATA,
data->word & 0xff);
if (status)
return status;
status = amd_ec_write(smbus, AMD_SMB_DATA + 1,
data->word >> 8);
if (status)
return status;
}
protocol |= AMD_SMB_PRTCL_WORD_DATA | pec;
break;
case I2C_SMBUS_BLOCK_DATA:
status = amd_ec_write(smbus, AMD_SMB_CMD, command);
if (status)
return status;
if (read_write == I2C_SMBUS_WRITE) {
len = min_t(u8, data->block[0],
I2C_SMBUS_BLOCK_MAX);
status = amd_ec_write(smbus, AMD_SMB_BCNT, len);
if (status)
return status;
for (i = 0; i < len; i++) {
status =
amd_ec_write(smbus, AMD_SMB_DATA + i,
data->block[i + 1]);
if (status)
return status;
}
}
protocol |= AMD_SMB_PRTCL_BLOCK_DATA | pec;
break;
case I2C_SMBUS_I2C_BLOCK_DATA:
len = min_t(u8, data->block[0],
I2C_SMBUS_BLOCK_MAX);
status = amd_ec_write(smbus, AMD_SMB_CMD, command);
if (status)
return status;
status = amd_ec_write(smbus, AMD_SMB_BCNT, len);
if (status)
return status;
if (read_write == I2C_SMBUS_WRITE)
for (i = 0; i < len; i++) {
status =
amd_ec_write(smbus, AMD_SMB_DATA + i,
data->block[i + 1]);
if (status)
return status;
}
protocol |= AMD_SMB_PRTCL_I2C_BLOCK_DATA;
break;
case I2C_SMBUS_PROC_CALL:
status = amd_ec_write(smbus, AMD_SMB_CMD, command);
if (status)
return status;
status = amd_ec_write(smbus, AMD_SMB_DATA,
data->word & 0xff);
if (status)
return status;
status = amd_ec_write(smbus, AMD_SMB_DATA + 1,
data->word >> 8);
if (status)
return status;
protocol = AMD_SMB_PRTCL_PROC_CALL | pec;
read_write = I2C_SMBUS_READ;
break;
case I2C_SMBUS_BLOCK_PROC_CALL:
len = min_t(u8, data->block[0],
I2C_SMBUS_BLOCK_MAX - 1);
status = amd_ec_write(smbus, AMD_SMB_CMD, command);
if (status)
return status;
status = amd_ec_write(smbus, AMD_SMB_BCNT, len);
if (status)
return status;
for (i = 0; i < len; i++) {
status = amd_ec_write(smbus, AMD_SMB_DATA + i,
data->block[i + 1]);
if (status)
return status;
}
protocol = AMD_SMB_PRTCL_BLOCK_PROC_CALL | pec;
read_write = I2C_SMBUS_READ;
break;
default:
dev_warn(&adap->dev, "Unsupported transaction %d\n", size);
return -EOPNOTSUPP;
}
status = amd_ec_write(smbus, AMD_SMB_ADDR, addr << 1);
if (status)
return status;
status = amd_ec_write(smbus, AMD_SMB_PRTCL, protocol);
if (status)
return status;
status = amd_ec_read(smbus, AMD_SMB_STS, temp + 0);
if (status)
return status;
if (~temp[0] & AMD_SMB_STS_DONE) {
udelay(500);
status = amd_ec_read(smbus, AMD_SMB_STS, temp + 0);
if (status)
return status;
}
if (~temp[0] & AMD_SMB_STS_DONE) {
msleep(1);
status = amd_ec_read(smbus, AMD_SMB_STS, temp + 0);
if (status)
return status;
}
if ((~temp[0] & AMD_SMB_STS_DONE) || (temp[0] & AMD_SMB_STS_STATUS))
return -EIO;
if (read_write == I2C_SMBUS_WRITE)
return 0;
switch (size) {
case I2C_SMBUS_BYTE:
case I2C_SMBUS_BYTE_DATA:
status = amd_ec_read(smbus, AMD_SMB_DATA, &data->byte);
if (status)
return status;
break;
case I2C_SMBUS_WORD_DATA:
case I2C_SMBUS_PROC_CALL:
status = amd_ec_read(smbus, AMD_SMB_DATA, temp + 0);
if (status)
return status;
status = amd_ec_read(smbus, AMD_SMB_DATA + 1, temp + 1);
if (status)
return status;
data->word = (temp[1] << 8) | temp[0];
break;
case I2C_SMBUS_BLOCK_DATA:
case I2C_SMBUS_BLOCK_PROC_CALL:
status = amd_ec_read(smbus, AMD_SMB_BCNT, &len);
if (status)
return status;
len = min_t(u8, len, I2C_SMBUS_BLOCK_MAX);
case I2C_SMBUS_I2C_BLOCK_DATA:
for (i = 0; i < len; i++) {
status = amd_ec_read(smbus, AMD_SMB_DATA + i,
data->block + i + 1);
if (status)
return status;
}
data->block[0] = len;
break;
}
return 0;
}
static u32 amd8111_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_SMBUS_QUICK | I2C_FUNC_SMBUS_BYTE |
I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA | I2C_FUNC_SMBUS_BLOCK_DATA |
I2C_FUNC_SMBUS_PROC_CALL | I2C_FUNC_SMBUS_BLOCK_PROC_CALL |
I2C_FUNC_SMBUS_I2C_BLOCK | I2C_FUNC_SMBUS_PEC;
}
static int amd8111_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
struct amd_smbus *smbus;
int error;
if (!(pci_resource_flags(dev, 0) & IORESOURCE_IO))
return -ENODEV;
smbus = kzalloc(sizeof(struct amd_smbus), GFP_KERNEL);
if (!smbus)
return -ENOMEM;
smbus->dev = dev;
smbus->base = pci_resource_start(dev, 0);
smbus->size = pci_resource_len(dev, 0);
error = acpi_check_resource_conflict(&dev->resource[0]);
if (error) {
error = -ENODEV;
goto out_kfree;
}
if (!request_region(smbus->base, smbus->size, amd8111_driver.name)) {
error = -EBUSY;
goto out_kfree;
}
smbus->adapter.owner = THIS_MODULE;
snprintf(smbus->adapter.name, sizeof(smbus->adapter.name),
"SMBus2 AMD8111 adapter at %04x", smbus->base);
smbus->adapter.class = I2C_CLASS_HWMON | I2C_CLASS_SPD;
smbus->adapter.algo = &smbus_algorithm;
smbus->adapter.algo_data = smbus;
smbus->adapter.dev.parent = &dev->dev;
pci_write_config_dword(smbus->dev, AMD_PCI_MISC, 0);
error = i2c_add_adapter(&smbus->adapter);
if (error)
goto out_release_region;
pci_set_drvdata(dev, smbus);
return 0;
out_release_region:
release_region(smbus->base, smbus->size);
out_kfree:
kfree(smbus);
return error;
}
static void amd8111_remove(struct pci_dev *dev)
{
struct amd_smbus *smbus = pci_get_drvdata(dev);
i2c_del_adapter(&smbus->adapter);
release_region(smbus->base, smbus->size);
kfree(smbus);
}
