static void __ismt_desc_dump(struct device *dev, const struct ismt_desc *desc)
{
dev_dbg(dev, "Descriptor struct: %p\n", desc);
dev_dbg(dev, "\ttgtaddr_rw=0x%02X\n", desc->tgtaddr_rw);
dev_dbg(dev, "\twr_len_cmd=0x%02X\n", desc->wr_len_cmd);
dev_dbg(dev, "\trd_len= 0x%02X\n", desc->rd_len);
dev_dbg(dev, "\tcontrol= 0x%02X\n", desc->control);
dev_dbg(dev, "\tstatus= 0x%02X\n", desc->status);
dev_dbg(dev, "\tretry= 0x%02X\n", desc->retry);
dev_dbg(dev, "\trxbytes= 0x%02X\n", desc->rxbytes);
dev_dbg(dev, "\ttxbytes= 0x%02X\n", desc->txbytes);
dev_dbg(dev, "\tdptr_low= 0x%08X\n", desc->dptr_low);
dev_dbg(dev, "\tdptr_high= 0x%08X\n", desc->dptr_high);
}
static void ismt_desc_dump(struct ismt_priv *priv)
{
struct device *dev = &priv->pci_dev->dev;
struct ismt_desc *desc = &priv->hw[priv->head];
dev_dbg(dev, "Dump of the descriptor struct: 0x%X\n", priv->head);
__ismt_desc_dump(dev, desc);
}
static void ismt_gen_reg_dump(struct ismt_priv *priv)
{
struct device *dev = &priv->pci_dev->dev;
dev_dbg(dev, "Dump of the iSMT General Registers\n");
dev_dbg(dev, " GCTRL.... : (0x%p)=0x%X\n",
priv->smba + ISMT_GR_GCTRL,
readl(priv->smba + ISMT_GR_GCTRL));
dev_dbg(dev, " SMTICL... : (0x%p)=0x%016llX\n",
priv->smba + ISMT_GR_SMTICL,
(long long unsigned int)readq(priv->smba + ISMT_GR_SMTICL));
dev_dbg(dev, " ERRINTMSK : (0x%p)=0x%X\n",
priv->smba + ISMT_GR_ERRINTMSK,
readl(priv->smba + ISMT_GR_ERRINTMSK));
dev_dbg(dev, " ERRAERMSK : (0x%p)=0x%X\n",
priv->smba + ISMT_GR_ERRAERMSK,
readl(priv->smba + ISMT_GR_ERRAERMSK));
dev_dbg(dev, " ERRSTS... : (0x%p)=0x%X\n",
priv->smba + ISMT_GR_ERRSTS,
readl(priv->smba + ISMT_GR_ERRSTS));
dev_dbg(dev, " ERRINFO.. : (0x%p)=0x%X\n",
priv->smba + ISMT_GR_ERRINFO,
readl(priv->smba + ISMT_GR_ERRINFO));
}
static void ismt_mstr_reg_dump(struct ismt_priv *priv)
{
struct device *dev = &priv->pci_dev->dev;
dev_dbg(dev, "Dump of the iSMT Master Registers\n");
dev_dbg(dev, " MDBA..... : (0x%p)=0x%016llX\n",
priv->smba + ISMT_MSTR_MDBA,
(long long unsigned int)readq(priv->smba + ISMT_MSTR_MDBA));
dev_dbg(dev, " MCTRL.... : (0x%p)=0x%X\n",
priv->smba + ISMT_MSTR_MCTRL,
readl(priv->smba + ISMT_MSTR_MCTRL));
dev_dbg(dev, " MSTS..... : (0x%p)=0x%X\n",
priv->smba + ISMT_MSTR_MSTS,
readl(priv->smba + ISMT_MSTR_MSTS));
dev_dbg(dev, " MDS...... : (0x%p)=0x%X\n",
priv->smba + ISMT_MSTR_MDS,
readl(priv->smba + ISMT_MSTR_MDS));
dev_dbg(dev, " RPOLICY.. : (0x%p)=0x%X\n",
priv->smba + ISMT_MSTR_RPOLICY,
readl(priv->smba + ISMT_MSTR_RPOLICY));
dev_dbg(dev, " SPGT..... : (0x%p)=0x%X\n",
priv->smba + ISMT_SPGT,
readl(priv->smba + ISMT_SPGT));
}
static void ismt_submit_desc(struct ismt_priv *priv)
{
uint fmhp;
uint val;
ismt_desc_dump(priv);
ismt_gen_reg_dump(priv);
ismt_mstr_reg_dump(priv);
fmhp = ((priv->head + 1) % ISMT_DESC_ENTRIES) << 16;
val = readl(priv->smba + ISMT_MSTR_MCTRL);
writel((val & ~ISMT_MCTRL_FMHP) | fmhp,
priv->smba + ISMT_MSTR_MCTRL);
val = readl(priv->smba + ISMT_MSTR_MCTRL);
writel(val | ISMT_MCTRL_SS,
priv->smba + ISMT_MSTR_MCTRL);
}
static int ismt_process_desc(const struct ismt_desc *desc,
union i2c_smbus_data *data,
struct ismt_priv *priv, int size,
char read_write)
{
u8 *dma_buffer = priv->dma_buffer;
dev_dbg(&priv->pci_dev->dev, "Processing completed descriptor\n");
__ismt_desc_dump(&priv->pci_dev->dev, desc);
if (desc->status & ISMT_DESC_SCS) {
if (read_write == I2C_SMBUS_WRITE &&
size != I2C_SMBUS_PROC_CALL)
return 0;
switch (size) {
case I2C_SMBUS_BYTE:
case I2C_SMBUS_BYTE_DATA:
data->byte = dma_buffer[0];
break;
case I2C_SMBUS_WORD_DATA:
case I2C_SMBUS_PROC_CALL:
data->word = dma_buffer[0] | (dma_buffer[1] << 8);
break;
case I2C_SMBUS_BLOCK_DATA:
case I2C_SMBUS_I2C_BLOCK_DATA:
memcpy(&data->block[1], dma_buffer, desc->rxbytes);
data->block[0] = desc->rxbytes;
break;
}
return 0;
}
if (likely(desc->status & ISMT_DESC_NAK))
return -ENXIO;
if (desc->status & ISMT_DESC_CRC)
return -EBADMSG;
if (desc->status & ISMT_DESC_COL)
return -EAGAIN;
if (desc->status & ISMT_DESC_LPR)
return -EPROTO;
if (desc->status & (ISMT_DESC_DLTO | ISMT_DESC_CLTO))
return -ETIMEDOUT;
return -EIO;
}
static int ismt_access(struct i2c_adapter *adap, u16 addr,
unsigned short flags, char read_write, u8 command,
int size, union i2c_smbus_data *data)
{
int ret;
unsigned long time_left;
dma_addr_t dma_addr = 0;
u8 dma_size = 0;
enum dma_data_direction dma_direction = 0;
struct ismt_desc *desc;
struct ismt_priv *priv = i2c_get_adapdata(adap);
struct device *dev = &priv->pci_dev->dev;
desc = &priv->hw[priv->head];
memset(priv->dma_buffer, 0, sizeof(priv->dma_buffer));
memset(desc, 0, sizeof(struct ismt_desc));
desc->tgtaddr_rw = ISMT_DESC_ADDR_RW(addr, read_write);
if (likely(pci_dev_msi_enabled(priv->pci_dev)))
desc->control = ISMT_DESC_INT | ISMT_DESC_FAIR;
else
desc->control = ISMT_DESC_FAIR;
if ((flags & I2C_CLIENT_PEC) && (size != I2C_SMBUS_QUICK)
&& (size != I2C_SMBUS_I2C_BLOCK_DATA))
desc->control |= ISMT_DESC_PEC;
switch (size) {
case I2C_SMBUS_QUICK:
dev_dbg(dev, "I2C_SMBUS_QUICK\n");
break;
case I2C_SMBUS_BYTE:
if (read_write == I2C_SMBUS_WRITE) {
dev_dbg(dev, "I2C_SMBUS_BYTE: WRITE\n");
desc->control |= ISMT_DESC_CWRL;
desc->wr_len_cmd = command;
} else {
dev_dbg(dev, "I2C_SMBUS_BYTE: READ\n");
dma_size = 1;
dma_direction = DMA_FROM_DEVICE;
desc->rd_len = 1;
}
break;
case I2C_SMBUS_BYTE_DATA:
if (read_write == I2C_SMBUS_WRITE) {
dev_dbg(dev, "I2C_SMBUS_BYTE_DATA: WRITE\n");
desc->wr_len_cmd = 2;
dma_size = 2;
dma_direction = DMA_TO_DEVICE;
priv->dma_buffer[0] = command;
priv->dma_buffer[1] = data->byte;
} else {
dev_dbg(dev, "I2C_SMBUS_BYTE_DATA: READ\n");
desc->control |= ISMT_DESC_CWRL;
desc->wr_len_cmd = command;
desc->rd_len = 1;
dma_size = 1;
dma_direction = DMA_FROM_DEVICE;
}
break;
case I2C_SMBUS_WORD_DATA:
if (read_write == I2C_SMBUS_WRITE) {
dev_dbg(dev, "I2C_SMBUS_WORD_DATA: WRITE\n");
desc->wr_len_cmd = 3;
dma_size = 3;
dma_direction = DMA_TO_DEVICE;
priv->dma_buffer[0] = command;
priv->dma_buffer[1] = data->word & 0xff;
priv->dma_buffer[2] = data->word >> 8;
} else {
dev_dbg(dev, "I2C_SMBUS_WORD_DATA: READ\n");
desc->wr_len_cmd = command;
desc->control |= ISMT_DESC_CWRL;
desc->rd_len = 2;
dma_size = 2;
dma_direction = DMA_FROM_DEVICE;
}
break;
case I2C_SMBUS_PROC_CALL:
dev_dbg(dev, "I2C_SMBUS_PROC_CALL\n");
desc->wr_len_cmd = 3;
desc->rd_len = 2;
dma_size = 3;
dma_direction = DMA_BIDIRECTIONAL;
priv->dma_buffer[0] = command;
priv->dma_buffer[1] = data->word & 0xff;
priv->dma_buffer[2] = data->word >> 8;
break;
case I2C_SMBUS_BLOCK_DATA:
if (read_write == I2C_SMBUS_WRITE) {
dev_dbg(dev, "I2C_SMBUS_BLOCK_DATA: WRITE\n");
dma_size = data->block[0] + 1;
dma_direction = DMA_TO_DEVICE;
desc->wr_len_cmd = dma_size;
desc->control |= ISMT_DESC_BLK;
priv->dma_buffer[0] = command;
memcpy(&priv->dma_buffer[1], &data->block[1], dma_size - 1);
} else {
dev_dbg(dev, "I2C_SMBUS_BLOCK_DATA: READ\n");
dma_size = I2C_SMBUS_BLOCK_MAX;
dma_direction = DMA_FROM_DEVICE;
desc->rd_len = dma_size;
desc->wr_len_cmd = command;
desc->control |= (ISMT_DESC_BLK | ISMT_DESC_CWRL);
}
break;
case I2C_SMBUS_I2C_BLOCK_DATA:
if (data->block[0] < 1)
data->block[0] = 1;
if (data->block[0] > I2C_SMBUS_BLOCK_MAX)
data->block[0] = I2C_SMBUS_BLOCK_MAX;
if (read_write == I2C_SMBUS_WRITE) {
dev_dbg(dev, "I2C_SMBUS_I2C_BLOCK_DATA: WRITE\n");
dma_size = data->block[0] + 1;
dma_direction = DMA_TO_DEVICE;
desc->wr_len_cmd = dma_size;
desc->control |= ISMT_DESC_I2C;
priv->dma_buffer[0] = command;
memcpy(&priv->dma_buffer[1], &data->block[1], dma_size - 1);
} else {
dev_dbg(dev, "I2C_SMBUS_I2C_BLOCK_DATA: READ\n");
dma_size = data->block[0];
dma_direction = DMA_FROM_DEVICE;
desc->rd_len = dma_size;
desc->wr_len_cmd = command;
desc->control |= (ISMT_DESC_I2C | ISMT_DESC_CWRL);
desc->tgtaddr_rw = ISMT_DESC_ADDR_RW(addr, 0);
}
break;
default:
dev_err(dev, "Unsupported transaction %d\n",
size);
return -EOPNOTSUPP;
}
if (dma_size != 0) {
dev_dbg(dev, " dev=%p\n", dev);
dev_dbg(dev, " data=%p\n", data);
dev_dbg(dev, " dma_buffer=%p\n", priv->dma_buffer);
dev_dbg(dev, " dma_size=%d\n", dma_size);
dev_dbg(dev, " dma_direction=%d\n", dma_direction);
dma_addr = dma_map_single(dev,
priv->dma_buffer,
dma_size,
dma_direction);
if (dma_mapping_error(dev, dma_addr)) {
dev_err(dev, "Error in mapping dma buffer %p\n",
priv->dma_buffer);
return -EIO;
}
dev_dbg(dev, " dma_addr = 0x%016llX\n",
(unsigned long long)dma_addr);
desc->dptr_low = lower_32_bits(dma_addr);
desc->dptr_high = upper_32_bits(dma_addr);
}
reinit_completion(&priv->cmp);
ismt_submit_desc(priv);
time_left = wait_for_completion_timeout(&priv->cmp, HZ*1);
if (dma_size != 0)
dma_unmap_single(&adap->dev, dma_addr, dma_size, dma_direction);
if (unlikely(!time_left)) {
dev_err(dev, "completion wait timed out\n");
ret = -ETIMEDOUT;
goto out;
}
ret = ismt_process_desc(desc, data, priv, size, read_write);
out:
priv->head++;
priv->head %= ISMT_DESC_ENTRIES;
return ret;
}
static u32 ismt_func(struct i2c_adapter *adap)
{
return I2C_FUNC_SMBUS_QUICK |
I2C_FUNC_SMBUS_BYTE |
I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA |
I2C_FUNC_SMBUS_PROC_CALL |
I2C_FUNC_SMBUS_BLOCK_DATA |
I2C_FUNC_SMBUS_I2C_BLOCK |
I2C_FUNC_SMBUS_PEC;
}
static irqreturn_t ismt_handle_isr(struct ismt_priv *priv)
{
complete(&priv->cmp);
return IRQ_HANDLED;
}
static irqreturn_t ismt_do_interrupt(int vec, void *data)
{
u32 val;
struct ismt_priv *priv = data;
val = readl(priv->smba + ISMT_MSTR_MSTS);
if (!(val & (ISMT_MSTS_MIS | ISMT_MSTS_MEIS)))
return IRQ_NONE;
else
writel(val | ISMT_MSTS_MIS | ISMT_MSTS_MEIS,
priv->smba + ISMT_MSTR_MSTS);
return ismt_handle_isr(priv);
}
static irqreturn_t ismt_do_msi_interrupt(int vec, void *data)
{
return ismt_handle_isr(data);
}
static void ismt_hw_init(struct ismt_priv *priv)
{
u32 val;
struct device *dev = &priv->pci_dev->dev;
writeq(priv->io_rng_dma, priv->smba + ISMT_MSTR_MDBA);
writel(ISMT_MCTRL_MEIE, priv->smba + ISMT_MSTR_MCTRL);
writel(0, priv->smba + ISMT_MSTR_MSTS);
val = readl(priv->smba + ISMT_MSTR_MDS);
writel((val & ~ISMT_MDS_MASK) | (ISMT_DESC_ENTRIES - 1),
priv->smba + ISMT_MSTR_MDS);
val = readl(priv->smba + ISMT_SPGT);
switch (bus_speed) {
case 0:
break;
case 80:
dev_dbg(dev, "Setting SMBus clock to 80 kHz\n");
writel(((val & ~ISMT_SPGT_SPD_MASK) | ISMT_SPGT_SPD_80K),
priv->smba + ISMT_SPGT);
break;
case 100:
dev_dbg(dev, "Setting SMBus clock to 100 kHz\n");
writel(((val & ~ISMT_SPGT_SPD_MASK) | ISMT_SPGT_SPD_100K),
priv->smba + ISMT_SPGT);
break;
case 400:
dev_dbg(dev, "Setting SMBus clock to 400 kHz\n");
writel(((val & ~ISMT_SPGT_SPD_MASK) | ISMT_SPGT_SPD_400K),
priv->smba + ISMT_SPGT);
break;
case 1000:
dev_dbg(dev, "Setting SMBus clock to 1000 kHz\n");
writel(((val & ~ISMT_SPGT_SPD_MASK) | ISMT_SPGT_SPD_1M),
priv->smba + ISMT_SPGT);
break;
default:
dev_warn(dev, "Invalid SMBus clock speed, only 0, 80, 100, 400, and 1000 are valid\n");
break;
}
val = readl(priv->smba + ISMT_SPGT);
switch (val & ISMT_SPGT_SPD_MASK) {
case ISMT_SPGT_SPD_80K:
bus_speed = 80;
break;
case ISMT_SPGT_SPD_100K:
bus_speed = 100;
break;
case ISMT_SPGT_SPD_400K:
bus_speed = 400;
break;
case ISMT_SPGT_SPD_1M:
bus_speed = 1000;
break;
}
dev_dbg(dev, "SMBus clock is running at %d kHz\n", bus_speed);
}
static int ismt_dev_init(struct ismt_priv *priv)
{
priv->hw = dmam_alloc_coherent(&priv->pci_dev->dev,
(ISMT_DESC_ENTRIES
* sizeof(struct ismt_desc)),
&priv->io_rng_dma,
GFP_KERNEL);
if (!priv->hw)
return -ENOMEM;
memset(priv->hw, 0, (ISMT_DESC_ENTRIES * sizeof(struct ismt_desc)));
priv->head = 0;
init_completion(&priv->cmp);
return 0;
}
static int ismt_int_init(struct ismt_priv *priv)
{
int err;
err = pci_enable_msi(priv->pci_dev);
if (err)
goto intx;
err = devm_request_irq(&priv->pci_dev->dev,
priv->pci_dev->irq,
ismt_do_msi_interrupt,
0,
"ismt-msi",
priv);
if (err) {
pci_disable_msi(priv->pci_dev);
goto intx;
}
return 0;
intx:
dev_warn(&priv->pci_dev->dev,
"Unable to use MSI interrupts, falling back to legacy\n");
err = devm_request_irq(&priv->pci_dev->dev,
priv->pci_dev->irq,
ismt_do_interrupt,
IRQF_SHARED,
"ismt-intx",
priv);
if (err) {
dev_err(&priv->pci_dev->dev, "no usable interrupts\n");
return err;
}
return 0;
}
static int
ismt_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
int err;
struct ismt_priv *priv;
unsigned long start, len;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
pci_set_drvdata(pdev, priv);
i2c_set_adapdata(&priv->adapter, priv);
priv->adapter.owner = THIS_MODULE;
priv->adapter.class = I2C_CLASS_HWMON;
priv->adapter.algo = &smbus_algorithm;
priv->adapter.dev.parent = &pdev->dev;
ACPI_COMPANION_SET(&priv->adapter.dev, ACPI_COMPANION(&pdev->dev));
priv->adapter.retries = ISMT_MAX_RETRIES;
priv->pci_dev = pdev;
err = pcim_enable_device(pdev);
if (err) {
dev_err(&pdev->dev, "Failed to enable SMBus PCI device (%d)\n",
err);
return err;
}
pci_set_master(pdev);
start = pci_resource_start(pdev, SMBBAR);
len = pci_resource_len(pdev, SMBBAR);
if (!start || !len) {
dev_err(&pdev->dev,
"SMBus base address uninitialized, upgrade BIOS\n");
return -ENODEV;
}
snprintf(priv->adapter.name, sizeof(priv->adapter.name),
"SMBus iSMT adapter at %lx", start);
dev_dbg(&priv->pci_dev->dev, " start=0x%lX\n", start);
dev_dbg(&priv->pci_dev->dev, " len=0x%lX\n", len);
err = acpi_check_resource_conflict(&pdev->resource[SMBBAR]);
if (err) {
dev_err(&pdev->dev, "ACPI resource conflict!\n");
return err;
}
err = pci_request_region(pdev, SMBBAR, ismt_driver.name);
if (err) {
dev_err(&pdev->dev,
"Failed to request SMBus region 0x%lx-0x%lx\n",
start, start + len);
return err;
}
priv->smba = pcim_iomap(pdev, SMBBAR, len);
if (!priv->smba) {
dev_err(&pdev->dev, "Unable to ioremap SMBus BAR\n");
return -ENODEV;
}
if ((pci_set_dma_mask(pdev, DMA_BIT_MASK(64)) != 0) ||
(pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64)) != 0)) {
if ((pci_set_dma_mask(pdev, DMA_BIT_MASK(32)) != 0) ||
(pci_set_consistent_dma_mask(pdev,
DMA_BIT_MASK(32)) != 0)) {
dev_err(&pdev->dev, "pci_set_dma_mask fail %p\n",
pdev);
return -ENODEV;
}
}
err = ismt_dev_init(priv);
if (err)
return err;
ismt_hw_init(priv);
err = ismt_int_init(priv);
if (err)
return err;
err = i2c_add_adapter(&priv->adapter);
if (err)
return -ENODEV;
return 0;
}
static void ismt_remove(struct pci_dev *pdev)
{
struct ismt_priv *priv = pci_get_drvdata(pdev);
i2c_del_adapter(&priv->adapter);
}
