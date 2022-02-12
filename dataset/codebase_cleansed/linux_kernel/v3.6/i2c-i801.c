static int i801_check_pre(struct i801_priv *priv)
{
int status;
status = inb_p(SMBHSTSTS(priv));
if (status & SMBHSTSTS_HOST_BUSY) {
dev_err(&priv->pci_dev->dev, "SMBus is busy, can't use it!\n");
return -EBUSY;
}
status &= STATUS_FLAGS;
if (status) {
dev_dbg(&priv->pci_dev->dev, "Clearing status flags (%02x)\n",
status);
outb_p(status, SMBHSTSTS(priv));
status = inb_p(SMBHSTSTS(priv)) & STATUS_FLAGS;
if (status) {
dev_err(&priv->pci_dev->dev,
"Failed clearing status flags (%02x)\n",
status);
return -EBUSY;
}
}
return 0;
}
static int i801_check_post(struct i801_priv *priv, int status)
{
int result = 0;
if (unlikely(status < 0)) {
dev_err(&priv->pci_dev->dev, "Transaction timeout\n");
dev_dbg(&priv->pci_dev->dev, "Terminating the current operation\n");
outb_p(inb_p(SMBHSTCNT(priv)) | SMBHSTCNT_KILL,
SMBHSTCNT(priv));
usleep_range(1000, 2000);
outb_p(inb_p(SMBHSTCNT(priv)) & (~SMBHSTCNT_KILL),
SMBHSTCNT(priv));
status = inb_p(SMBHSTSTS(priv));
if ((status & SMBHSTSTS_HOST_BUSY) ||
!(status & SMBHSTSTS_FAILED))
dev_err(&priv->pci_dev->dev,
"Failed terminating the transaction\n");
outb_p(STATUS_FLAGS, SMBHSTSTS(priv));
return -ETIMEDOUT;
}
if (status & SMBHSTSTS_FAILED) {
result = -EIO;
dev_err(&priv->pci_dev->dev, "Transaction failed\n");
}
if (status & SMBHSTSTS_DEV_ERR) {
result = -ENXIO;
dev_dbg(&priv->pci_dev->dev, "No response\n");
}
if (status & SMBHSTSTS_BUS_ERR) {
result = -EAGAIN;
dev_dbg(&priv->pci_dev->dev, "Lost arbitration\n");
}
outb_p(status, SMBHSTSTS(priv));
return result;
}
static int i801_wait_intr(struct i801_priv *priv)
{
int timeout = 0;
int status;
do {
usleep_range(250, 500);
status = inb_p(SMBHSTSTS(priv));
} while (((status & SMBHSTSTS_HOST_BUSY) ||
!(status & (STATUS_ERROR_FLAGS | SMBHSTSTS_INTR))) &&
(timeout++ < MAX_RETRIES));
if (timeout > MAX_RETRIES) {
dev_dbg(&priv->pci_dev->dev, "INTR Timeout!\n");
return -ETIMEDOUT;
}
return status & (STATUS_ERROR_FLAGS | SMBHSTSTS_INTR);
}
static int i801_wait_byte_done(struct i801_priv *priv)
{
int timeout = 0;
int status;
do {
usleep_range(250, 500);
status = inb_p(SMBHSTSTS(priv));
} while (!(status & (STATUS_ERROR_FLAGS | SMBHSTSTS_BYTE_DONE)) &&
(timeout++ < MAX_RETRIES));
if (timeout > MAX_RETRIES) {
dev_dbg(&priv->pci_dev->dev, "BYTE_DONE Timeout!\n");
return -ETIMEDOUT;
}
return status & STATUS_ERROR_FLAGS;
}
static int i801_transaction(struct i801_priv *priv, int xact)
{
int status;
int result;
result = i801_check_pre(priv);
if (result < 0)
return result;
if (priv->features & FEATURE_IRQ) {
outb_p(xact | SMBHSTCNT_INTREN | SMBHSTCNT_START,
SMBHSTCNT(priv));
wait_event(priv->waitq, (status = priv->status));
priv->status = 0;
return i801_check_post(priv, status);
}
outb_p(xact | SMBHSTCNT_START, SMBHSTCNT(priv));
status = i801_wait_intr(priv);
return i801_check_post(priv, status);
}
static int i801_block_transaction_by_block(struct i801_priv *priv,
union i2c_smbus_data *data,
char read_write, int hwpec)
{
int i, len;
int status;
inb_p(SMBHSTCNT(priv));
if (read_write == I2C_SMBUS_WRITE) {
len = data->block[0];
outb_p(len, SMBHSTDAT0(priv));
for (i = 0; i < len; i++)
outb_p(data->block[i+1], SMBBLKDAT(priv));
}
status = i801_transaction(priv, I801_BLOCK_DATA |
(hwpec ? SMBHSTCNT_PEC_EN : 0));
if (status)
return status;
if (read_write == I2C_SMBUS_READ) {
len = inb_p(SMBHSTDAT0(priv));
if (len < 1 || len > I2C_SMBUS_BLOCK_MAX)
return -EPROTO;
data->block[0] = len;
for (i = 0; i < len; i++)
data->block[i + 1] = inb_p(SMBBLKDAT(priv));
}
return 0;
}
static void i801_isr_byte_done(struct i801_priv *priv)
{
if (priv->is_read) {
if (((priv->cmd & 0x1c) == I801_BLOCK_DATA) &&
(priv->count == 0)) {
priv->len = inb_p(SMBHSTDAT0(priv));
if (priv->len < 1 || priv->len > I2C_SMBUS_BLOCK_MAX) {
dev_err(&priv->pci_dev->dev,
"Illegal SMBus block read size %d\n",
priv->len);
priv->len = I2C_SMBUS_BLOCK_MAX;
} else {
dev_dbg(&priv->pci_dev->dev,
"SMBus block read size is %d\n",
priv->len);
}
priv->data[-1] = priv->len;
}
if (priv->count < priv->len)
priv->data[priv->count++] = inb(SMBBLKDAT(priv));
else
dev_dbg(&priv->pci_dev->dev,
"Discarding extra byte on block read\n");
if (priv->count == priv->len - 1)
outb_p(priv->cmd | SMBHSTCNT_LAST_BYTE,
SMBHSTCNT(priv));
} else if (priv->count < priv->len - 1) {
outb_p(priv->data[++priv->count], SMBBLKDAT(priv));
}
outb_p(SMBHSTSTS_BYTE_DONE, SMBHSTSTS(priv));
}
static irqreturn_t i801_isr(int irq, void *dev_id)
{
struct i801_priv *priv = dev_id;
u16 pcists;
u8 status;
pci_read_config_word(priv->pci_dev, SMBPCISTS, &pcists);
if (!(pcists & SMBPCISTS_INTS))
return IRQ_NONE;
status = inb_p(SMBHSTSTS(priv));
if (status != 0x42)
dev_dbg(&priv->pci_dev->dev, "irq: status = %02x\n", status);
if (status & SMBHSTSTS_BYTE_DONE)
i801_isr_byte_done(priv);
status &= SMBHSTSTS_INTR | STATUS_ERROR_FLAGS;
if (status) {
outb_p(status, SMBHSTSTS(priv));
priv->status |= status;
wake_up(&priv->waitq);
}
return IRQ_HANDLED;
}
static int i801_block_transaction_byte_by_byte(struct i801_priv *priv,
union i2c_smbus_data *data,
char read_write, int command,
int hwpec)
{
int i, len;
int smbcmd;
int status;
int result;
result = i801_check_pre(priv);
if (result < 0)
return result;
len = data->block[0];
if (read_write == I2C_SMBUS_WRITE) {
outb_p(len, SMBHSTDAT0(priv));
outb_p(data->block[1], SMBBLKDAT(priv));
}
if (command == I2C_SMBUS_I2C_BLOCK_DATA &&
read_write == I2C_SMBUS_READ)
smbcmd = I801_I2C_BLOCK_DATA;
else
smbcmd = I801_BLOCK_DATA;
if (priv->features & FEATURE_IRQ) {
priv->is_read = (read_write == I2C_SMBUS_READ);
if (len == 1 && priv->is_read)
smbcmd |= SMBHSTCNT_LAST_BYTE;
priv->cmd = smbcmd | SMBHSTCNT_INTREN;
priv->len = len;
priv->count = 0;
priv->data = &data->block[1];
outb_p(priv->cmd | SMBHSTCNT_START, SMBHSTCNT(priv));
wait_event(priv->waitq, (status = priv->status));
priv->status = 0;
return i801_check_post(priv, status);
}
for (i = 1; i <= len; i++) {
if (i == len && read_write == I2C_SMBUS_READ)
smbcmd |= SMBHSTCNT_LAST_BYTE;
outb_p(smbcmd, SMBHSTCNT(priv));
if (i == 1)
outb_p(inb(SMBHSTCNT(priv)) | SMBHSTCNT_START,
SMBHSTCNT(priv));
status = i801_wait_byte_done(priv);
if (status)
goto exit;
if (i == 1 && read_write == I2C_SMBUS_READ
&& command != I2C_SMBUS_I2C_BLOCK_DATA) {
len = inb_p(SMBHSTDAT0(priv));
if (len < 1 || len > I2C_SMBUS_BLOCK_MAX) {
dev_err(&priv->pci_dev->dev,
"Illegal SMBus block read size %d\n",
len);
while (inb_p(SMBHSTSTS(priv)) &
SMBHSTSTS_HOST_BUSY)
outb_p(SMBHSTSTS_BYTE_DONE,
SMBHSTSTS(priv));
outb_p(SMBHSTSTS_INTR, SMBHSTSTS(priv));
return -EPROTO;
}
data->block[0] = len;
}
if (read_write == I2C_SMBUS_READ)
data->block[i] = inb_p(SMBBLKDAT(priv));
if (read_write == I2C_SMBUS_WRITE && i+1 <= len)
outb_p(data->block[i+1], SMBBLKDAT(priv));
outb_p(SMBHSTSTS_BYTE_DONE, SMBHSTSTS(priv));
}
status = i801_wait_intr(priv);
exit:
return i801_check_post(priv, status);
}
static int i801_set_block_buffer_mode(struct i801_priv *priv)
{
outb_p(inb_p(SMBAUXCTL(priv)) | SMBAUXCTL_E32B, SMBAUXCTL(priv));
if ((inb_p(SMBAUXCTL(priv)) & SMBAUXCTL_E32B) == 0)
return -EIO;
return 0;
}
static int i801_block_transaction(struct i801_priv *priv,
union i2c_smbus_data *data, char read_write,
int command, int hwpec)
{
int result = 0;
unsigned char hostc;
if (command == I2C_SMBUS_I2C_BLOCK_DATA) {
if (read_write == I2C_SMBUS_WRITE) {
pci_read_config_byte(priv->pci_dev, SMBHSTCFG, &hostc);
pci_write_config_byte(priv->pci_dev, SMBHSTCFG,
hostc | SMBHSTCFG_I2C_EN);
} else if (!(priv->features & FEATURE_I2C_BLOCK_READ)) {
dev_err(&priv->pci_dev->dev,
"I2C block read is unsupported!\n");
return -EOPNOTSUPP;
}
}
if (read_write == I2C_SMBUS_WRITE
|| command == I2C_SMBUS_I2C_BLOCK_DATA) {
if (data->block[0] < 1)
data->block[0] = 1;
if (data->block[0] > I2C_SMBUS_BLOCK_MAX)
data->block[0] = I2C_SMBUS_BLOCK_MAX;
} else {
data->block[0] = 32;
}
if ((priv->features & FEATURE_BLOCK_BUFFER)
&& command != I2C_SMBUS_I2C_BLOCK_DATA
&& i801_set_block_buffer_mode(priv) == 0)
result = i801_block_transaction_by_block(priv, data,
read_write, hwpec);
else
result = i801_block_transaction_byte_by_byte(priv, data,
read_write,
command, hwpec);
if (command == I2C_SMBUS_I2C_BLOCK_DATA
&& read_write == I2C_SMBUS_WRITE) {
pci_write_config_byte(priv->pci_dev, SMBHSTCFG, hostc);
}
return result;
}
static s32 i801_access(struct i2c_adapter *adap, u16 addr,
unsigned short flags, char read_write, u8 command,
int size, union i2c_smbus_data *data)
{
int hwpec;
int block = 0;
int ret, xact = 0;
struct i801_priv *priv = i2c_get_adapdata(adap);
hwpec = (priv->features & FEATURE_SMBUS_PEC) && (flags & I2C_CLIENT_PEC)
&& size != I2C_SMBUS_QUICK
&& size != I2C_SMBUS_I2C_BLOCK_DATA;
switch (size) {
case I2C_SMBUS_QUICK:
outb_p(((addr & 0x7f) << 1) | (read_write & 0x01),
SMBHSTADD(priv));
xact = I801_QUICK;
break;
case I2C_SMBUS_BYTE:
outb_p(((addr & 0x7f) << 1) | (read_write & 0x01),
SMBHSTADD(priv));
if (read_write == I2C_SMBUS_WRITE)
outb_p(command, SMBHSTCMD(priv));
xact = I801_BYTE;
break;
case I2C_SMBUS_BYTE_DATA:
outb_p(((addr & 0x7f) << 1) | (read_write & 0x01),
SMBHSTADD(priv));
outb_p(command, SMBHSTCMD(priv));
if (read_write == I2C_SMBUS_WRITE)
outb_p(data->byte, SMBHSTDAT0(priv));
xact = I801_BYTE_DATA;
break;
case I2C_SMBUS_WORD_DATA:
outb_p(((addr & 0x7f) << 1) | (read_write & 0x01),
SMBHSTADD(priv));
outb_p(command, SMBHSTCMD(priv));
if (read_write == I2C_SMBUS_WRITE) {
outb_p(data->word & 0xff, SMBHSTDAT0(priv));
outb_p((data->word & 0xff00) >> 8, SMBHSTDAT1(priv));
}
xact = I801_WORD_DATA;
break;
case I2C_SMBUS_BLOCK_DATA:
outb_p(((addr & 0x7f) << 1) | (read_write & 0x01),
SMBHSTADD(priv));
outb_p(command, SMBHSTCMD(priv));
block = 1;
break;
case I2C_SMBUS_I2C_BLOCK_DATA:
outb_p((addr & 0x7f) << 1, SMBHSTADD(priv));
if (read_write == I2C_SMBUS_READ) {
outb_p(command, SMBHSTDAT1(priv));
} else
outb_p(command, SMBHSTCMD(priv));
block = 1;
break;
default:
dev_err(&priv->pci_dev->dev, "Unsupported transaction %d\n",
size);
return -EOPNOTSUPP;
}
if (hwpec)
outb_p(inb_p(SMBAUXCTL(priv)) | SMBAUXCTL_CRC, SMBAUXCTL(priv));
else
outb_p(inb_p(SMBAUXCTL(priv)) & (~SMBAUXCTL_CRC),
SMBAUXCTL(priv));
if (block)
ret = i801_block_transaction(priv, data, read_write, size,
hwpec);
else
ret = i801_transaction(priv, xact);
if (hwpec || block)
outb_p(inb_p(SMBAUXCTL(priv)) &
~(SMBAUXCTL_CRC | SMBAUXCTL_E32B), SMBAUXCTL(priv));
if (block)
return ret;
if (ret)
return ret;
if ((read_write == I2C_SMBUS_WRITE) || (xact == I801_QUICK))
return 0;
switch (xact & 0x7f) {
case I801_BYTE:
case I801_BYTE_DATA:
data->byte = inb_p(SMBHSTDAT0(priv));
break;
case I801_WORD_DATA:
data->word = inb_p(SMBHSTDAT0(priv)) +
(inb_p(SMBHSTDAT1(priv)) << 8);
break;
}
return 0;
}
static u32 i801_func(struct i2c_adapter *adapter)
{
struct i801_priv *priv = i2c_get_adapdata(adapter);
return I2C_FUNC_SMBUS_QUICK | I2C_FUNC_SMBUS_BYTE |
I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA |
I2C_FUNC_SMBUS_BLOCK_DATA | I2C_FUNC_SMBUS_WRITE_I2C_BLOCK |
((priv->features & FEATURE_SMBUS_PEC) ? I2C_FUNC_SMBUS_PEC : 0) |
((priv->features & FEATURE_I2C_BLOCK_READ) ?
I2C_FUNC_SMBUS_READ_I2C_BLOCK : 0);
}
static __init const void __iomem *bios_signature(const void __iomem *bios)
{
ssize_t offset;
const unsigned char signature[] = "FJKEYINF";
for (offset = 0; offset < 0x10000; offset += 0x10) {
if (check_signature(bios + offset, signature,
sizeof(signature)-1))
return bios + offset;
}
return NULL;
}
static void __init input_apanel_init(void)
{
void __iomem *bios;
const void __iomem *p;
bios = ioremap(0xF0000, 0x10000);
p = bios_signature(bios);
if (p) {
apanel_addr = readb(p + 8 + 3) >> 1;
}
iounmap(bios);
}
static void __devinit dmi_check_onboard_device(u8 type, const char *name,
struct i2c_adapter *adap)
{
int i;
struct i2c_board_info info;
for (i = 0; i < ARRAY_SIZE(dmi_devices); i++) {
if ((type & ~0x80) != dmi_devices[i].type)
continue;
if (strcasecmp(name, dmi_devices[i].name))
continue;
memset(&info, 0, sizeof(struct i2c_board_info));
info.addr = dmi_devices[i].i2c_addr;
strlcpy(info.type, dmi_devices[i].i2c_type, I2C_NAME_SIZE);
i2c_new_device(adap, &info);
break;
}
}
static void __devinit dmi_check_onboard_devices(const struct dmi_header *dm,
void *adap)
{
int i, count;
if (dm->type != 10)
return;
count = (dm->length - sizeof(struct dmi_header)) / 2;
for (i = 0; i < count; i++) {
const u8 *d = (char *)(dm + 1) + (i * 2);
const char *name = ((char *) dm) + dm->length;
u8 type = d[0];
u8 s = d[1];
if (!s)
continue;
s--;
while (s > 0 && name[0]) {
name += strlen(name) + 1;
s--;
}
if (name[0] == 0)
continue;
dmi_check_onboard_device(type, name, adap);
}
}
static void __devinit i801_probe_optional_slaves(struct i801_priv *priv)
{
if (priv->features & FEATURE_IDF)
return;
if (apanel_addr) {
struct i2c_board_info info;
memset(&info, 0, sizeof(struct i2c_board_info));
info.addr = apanel_addr;
strlcpy(info.type, "fujitsu_apanel", I2C_NAME_SIZE);
i2c_new_device(&priv->adapter, &info);
}
if (dmi_name_in_vendors("FUJITSU"))
dmi_walk(dmi_check_onboard_devices, &priv->adapter);
}
static void __init input_apanel_init(void) {}
static void __devinit i801_probe_optional_slaves(struct i801_priv *priv) {}
static int __devinit i801_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
unsigned char temp;
int err, i;
struct i801_priv *priv;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
i2c_set_adapdata(&priv->adapter, priv);
priv->adapter.owner = THIS_MODULE;
priv->adapter.class = I2C_CLASS_HWMON | I2C_CLASS_SPD;
priv->adapter.algo = &smbus_algorithm;
priv->pci_dev = dev;
switch (dev->device) {
case PCI_DEVICE_ID_INTEL_PATSBURG_SMBUS_IDF0:
case PCI_DEVICE_ID_INTEL_PATSBURG_SMBUS_IDF1:
case PCI_DEVICE_ID_INTEL_PATSBURG_SMBUS_IDF2:
priv->features |= FEATURE_IDF;
default:
priv->features |= FEATURE_I2C_BLOCK_READ;
case PCI_DEVICE_ID_INTEL_82801DB_3:
priv->features |= FEATURE_SMBUS_PEC;
priv->features |= FEATURE_BLOCK_BUFFER;
case PCI_DEVICE_ID_INTEL_82801CA_3:
case PCI_DEVICE_ID_INTEL_82801BA_2:
case PCI_DEVICE_ID_INTEL_82801AB_3:
case PCI_DEVICE_ID_INTEL_82801AA_3:
break;
}
if (dev->device == PCI_DEVICE_ID_INTEL_COUGARPOINT_SMBUS ||
dev->device == PCI_DEVICE_ID_INTEL_82801EB_3 ||
dev->device == PCI_DEVICE_ID_INTEL_ICH7_17 ||
dev->device == PCI_DEVICE_ID_INTEL_ICH8_5 ||
dev->device == PCI_DEVICE_ID_INTEL_ICH9_6 ||
dev->device == PCI_DEVICE_ID_INTEL_ICH10_4 ||
dev->device == PCI_DEVICE_ID_INTEL_ICH10_5)
priv->features |= FEATURE_IRQ;
for (i = 0; i < ARRAY_SIZE(i801_feature_names); i++) {
if (priv->features & disable_features & (1 << i))
dev_notice(&dev->dev, "%s disabled by user\n",
i801_feature_names[i]);
}
priv->features &= ~disable_features;
err = pci_enable_device(dev);
if (err) {
dev_err(&dev->dev, "Failed to enable SMBus PCI device (%d)\n",
err);
goto exit;
}
priv->smba = pci_resource_start(dev, SMBBAR);
if (!priv->smba) {
dev_err(&dev->dev, "SMBus base address uninitialized, "
"upgrade BIOS\n");
err = -ENODEV;
goto exit;
}
err = acpi_check_resource_conflict(&dev->resource[SMBBAR]);
if (err) {
err = -ENODEV;
goto exit;
}
err = pci_request_region(dev, SMBBAR, i801_driver.name);
if (err) {
dev_err(&dev->dev, "Failed to request SMBus region "
"0x%lx-0x%Lx\n", priv->smba,
(unsigned long long)pci_resource_end(dev, SMBBAR));
goto exit;
}
pci_read_config_byte(priv->pci_dev, SMBHSTCFG, &temp);
priv->original_hstcfg = temp;
temp &= ~SMBHSTCFG_I2C_EN;
if (!(temp & SMBHSTCFG_HST_EN)) {
dev_info(&dev->dev, "Enabling SMBus device\n");
temp |= SMBHSTCFG_HST_EN;
}
pci_write_config_byte(priv->pci_dev, SMBHSTCFG, temp);
if (temp & SMBHSTCFG_SMB_SMI_EN) {
dev_dbg(&dev->dev, "SMBus using interrupt SMI#\n");
priv->features &= ~FEATURE_IRQ;
}
if (priv->features & (FEATURE_SMBUS_PEC | FEATURE_BLOCK_BUFFER))
outb_p(inb_p(SMBAUXCTL(priv)) &
~(SMBAUXCTL_CRC | SMBAUXCTL_E32B), SMBAUXCTL(priv));
if (priv->features & FEATURE_IRQ) {
init_waitqueue_head(&priv->waitq);
err = request_irq(dev->irq, i801_isr, IRQF_SHARED,
i801_driver.name, priv);
if (err) {
dev_err(&dev->dev, "Failed to allocate irq %d: %d\n",
dev->irq, err);
goto exit_release;
}
dev_info(&dev->dev, "SMBus using PCI Interrupt\n");
}
priv->adapter.dev.parent = &dev->dev;
priv->adapter.retries = 3;
snprintf(priv->adapter.name, sizeof(priv->adapter.name),
"SMBus I801 adapter at %04lx", priv->smba);
err = i2c_add_adapter(&priv->adapter);
if (err) {
dev_err(&dev->dev, "Failed to add SMBus adapter\n");
goto exit_free_irq;
}
i801_probe_optional_slaves(priv);
pci_set_drvdata(dev, priv);
return 0;
exit_free_irq:
if (priv->features & FEATURE_IRQ)
free_irq(dev->irq, priv);
exit_release:
pci_release_region(dev, SMBBAR);
exit:
kfree(priv);
return err;
}
static void __devexit i801_remove(struct pci_dev *dev)
{
struct i801_priv *priv = pci_get_drvdata(dev);
i2c_del_adapter(&priv->adapter);
pci_write_config_byte(dev, SMBHSTCFG, priv->original_hstcfg);
if (priv->features & FEATURE_IRQ)
free_irq(dev->irq, priv);
pci_release_region(dev, SMBBAR);
pci_set_drvdata(dev, NULL);
kfree(priv);
}
static int i801_suspend(struct pci_dev *dev, pm_message_t mesg)
{
struct i801_priv *priv = pci_get_drvdata(dev);
pci_save_state(dev);
pci_write_config_byte(dev, SMBHSTCFG, priv->original_hstcfg);
pci_set_power_state(dev, pci_choose_state(dev, mesg));
return 0;
}
static int i801_resume(struct pci_dev *dev)
{
pci_set_power_state(dev, PCI_D0);
pci_restore_state(dev);
return pci_enable_device(dev);
}
static int __init i2c_i801_init(void)
{
if (dmi_name_in_vendors("FUJITSU"))
input_apanel_init();
return pci_register_driver(&i801_driver);
}
static void __exit i2c_i801_exit(void)
{
pci_unregister_driver(&i801_driver);
}
