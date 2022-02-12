static inline void ipc_command(struct intel_scu_ipc_dev *scu, u32 cmd)
{
if (scu->irq_mode) {
reinit_completion(&scu->cmd_complete);
writel(cmd | IPC_IOC, scu->ipc_base);
}
writel(cmd, scu->ipc_base);
}
static inline void ipc_data_writel(struct intel_scu_ipc_dev *scu, u32 data, u32 offset)
{
writel(data, scu->ipc_base + 0x80 + offset);
}
static inline u8 ipc_read_status(struct intel_scu_ipc_dev *scu)
{
return __raw_readl(scu->ipc_base + 0x04);
}
static inline u8 ipc_data_readb(struct intel_scu_ipc_dev *scu, u32 offset)
{
return readb(scu->ipc_base + IPC_READ_BUFFER + offset);
}
static inline u32 ipc_data_readl(struct intel_scu_ipc_dev *scu, u32 offset)
{
return readl(scu->ipc_base + IPC_READ_BUFFER + offset);
}
static inline int busy_loop(struct intel_scu_ipc_dev *scu)
{
u32 status = ipc_read_status(scu);
u32 loop_count = 100000;
while ((status & BIT(0)) && --loop_count) {
udelay(1);
status = ipc_read_status(scu);
}
if (status & BIT(0)) {
dev_err(scu->dev, "IPC timed out");
return -ETIMEDOUT;
}
if (status & BIT(1))
return -EIO;
return 0;
}
static inline int ipc_wait_for_interrupt(struct intel_scu_ipc_dev *scu)
{
int status;
if (!wait_for_completion_timeout(&scu->cmd_complete, 3 * HZ)) {
dev_err(scu->dev, "IPC timed out\n");
return -ETIMEDOUT;
}
status = ipc_read_status(scu);
if (status & BIT(1))
return -EIO;
return 0;
}
static int intel_scu_ipc_check_status(struct intel_scu_ipc_dev *scu)
{
return scu->irq_mode ? ipc_wait_for_interrupt(scu) : busy_loop(scu);
}
static int pwr_reg_rdwr(u16 *addr, u8 *data, u32 count, u32 op, u32 id)
{
struct intel_scu_ipc_dev *scu = &ipcdev;
int nc;
u32 offset = 0;
int err;
u8 cbuf[IPC_WWBUF_SIZE];
u32 *wbuf = (u32 *)&cbuf;
memset(cbuf, 0, sizeof(cbuf));
mutex_lock(&ipclock);
if (scu->dev == NULL) {
mutex_unlock(&ipclock);
return -ENODEV;
}
for (nc = 0; nc < count; nc++, offset += 2) {
cbuf[offset] = addr[nc];
cbuf[offset + 1] = addr[nc] >> 8;
}
if (id == IPC_CMD_PCNTRL_R) {
for (nc = 0, offset = 0; nc < count; nc++, offset += 4)
ipc_data_writel(scu, wbuf[nc], offset);
ipc_command(scu, (count * 2) << 16 | id << 12 | 0 << 8 | op);
} else if (id == IPC_CMD_PCNTRL_W) {
for (nc = 0; nc < count; nc++, offset += 1)
cbuf[offset] = data[nc];
for (nc = 0, offset = 0; nc < count; nc++, offset += 4)
ipc_data_writel(scu, wbuf[nc], offset);
ipc_command(scu, (count * 3) << 16 | id << 12 | 0 << 8 | op);
} else if (id == IPC_CMD_PCNTRL_M) {
cbuf[offset] = data[0];
cbuf[offset + 1] = data[1];
ipc_data_writel(scu, wbuf[0], 0);
ipc_command(scu, 4 << 16 | id << 12 | 0 << 8 | op);
}
err = intel_scu_ipc_check_status(scu);
if (!err && id == IPC_CMD_PCNTRL_R) {
memcpy_fromio(cbuf, scu->ipc_base + 0x90, 16);
for (nc = 0; nc < count; nc++)
data[nc] = ipc_data_readb(scu, nc);
}
mutex_unlock(&ipclock);
return err;
}
int intel_scu_ipc_ioread8(u16 addr, u8 *data)
{
return pwr_reg_rdwr(&addr, data, 1, IPCMSG_PCNTRL, IPC_CMD_PCNTRL_R);
}
int intel_scu_ipc_ioread16(u16 addr, u16 *data)
{
u16 x[2] = {addr, addr + 1};
return pwr_reg_rdwr(x, (u8 *)data, 2, IPCMSG_PCNTRL, IPC_CMD_PCNTRL_R);
}
int intel_scu_ipc_ioread32(u16 addr, u32 *data)
{
u16 x[4] = {addr, addr + 1, addr + 2, addr + 3};
return pwr_reg_rdwr(x, (u8 *)data, 4, IPCMSG_PCNTRL, IPC_CMD_PCNTRL_R);
}
int intel_scu_ipc_iowrite8(u16 addr, u8 data)
{
return pwr_reg_rdwr(&addr, &data, 1, IPCMSG_PCNTRL, IPC_CMD_PCNTRL_W);
}
int intel_scu_ipc_iowrite16(u16 addr, u16 data)
{
u16 x[2] = {addr, addr + 1};
return pwr_reg_rdwr(x, (u8 *)&data, 2, IPCMSG_PCNTRL, IPC_CMD_PCNTRL_W);
}
int intel_scu_ipc_iowrite32(u16 addr, u32 data)
{
u16 x[4] = {addr, addr + 1, addr + 2, addr + 3};
return pwr_reg_rdwr(x, (u8 *)&data, 4, IPCMSG_PCNTRL, IPC_CMD_PCNTRL_W);
}
int intel_scu_ipc_readv(u16 *addr, u8 *data, int len)
{
return pwr_reg_rdwr(addr, data, len, IPCMSG_PCNTRL, IPC_CMD_PCNTRL_R);
}
int intel_scu_ipc_writev(u16 *addr, u8 *data, int len)
{
return pwr_reg_rdwr(addr, data, len, IPCMSG_PCNTRL, IPC_CMD_PCNTRL_W);
}
int intel_scu_ipc_update_register(u16 addr, u8 bits, u8 mask)
{
u8 data[2] = { bits, mask };
return pwr_reg_rdwr(&addr, data, 1, IPCMSG_PCNTRL, IPC_CMD_PCNTRL_M);
}
int intel_scu_ipc_simple_command(int cmd, int sub)
{
struct intel_scu_ipc_dev *scu = &ipcdev;
int err;
mutex_lock(&ipclock);
if (scu->dev == NULL) {
mutex_unlock(&ipclock);
return -ENODEV;
}
ipc_command(scu, sub << 12 | cmd);
err = intel_scu_ipc_check_status(scu);
mutex_unlock(&ipclock);
return err;
}
int intel_scu_ipc_command(int cmd, int sub, u32 *in, int inlen,
u32 *out, int outlen)
{
struct intel_scu_ipc_dev *scu = &ipcdev;
int i, err;
mutex_lock(&ipclock);
if (scu->dev == NULL) {
mutex_unlock(&ipclock);
return -ENODEV;
}
for (i = 0; i < inlen; i++)
ipc_data_writel(scu, *in++, 4 * i);
ipc_command(scu, (inlen << 16) | (sub << 12) | cmd);
err = intel_scu_ipc_check_status(scu);
if (!err) {
for (i = 0; i < outlen; i++)
*out++ = ipc_data_readl(scu, 4 * i);
}
mutex_unlock(&ipclock);
return err;
}
int intel_scu_ipc_i2c_cntrl(u32 addr, u32 *data)
{
struct intel_scu_ipc_dev *scu = &ipcdev;
u32 cmd = 0;
mutex_lock(&ipclock);
if (scu->dev == NULL) {
mutex_unlock(&ipclock);
return -ENODEV;
}
cmd = (addr >> 24) & 0xFF;
if (cmd == IPC_I2C_READ) {
writel(addr, scu->i2c_base + IPC_I2C_CNTRL_ADDR);
mdelay(1);
*data = readl(scu->i2c_base + I2C_DATA_ADDR);
} else if (cmd == IPC_I2C_WRITE) {
writel(*data, scu->i2c_base + I2C_DATA_ADDR);
mdelay(1);
writel(addr, scu->i2c_base + IPC_I2C_CNTRL_ADDR);
} else {
dev_err(scu->dev,
"intel_scu_ipc: I2C INVALID_CMD = 0x%x\n", cmd);
mutex_unlock(&ipclock);
return -EIO;
}
mutex_unlock(&ipclock);
return 0;
}
static irqreturn_t ioc(int irq, void *dev_id)
{
struct intel_scu_ipc_dev *scu = dev_id;
if (scu->irq_mode)
complete(&scu->cmd_complete);
return IRQ_HANDLED;
}
static int ipc_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
int platform;
int err;
struct intel_scu_ipc_dev *scu = &ipcdev;
struct intel_scu_ipc_pdata_t *pdata;
platform = intel_mid_identify_cpu();
if (platform == 0)
return -ENODEV;
if (scu->dev)
return -EBUSY;
pdata = (struct intel_scu_ipc_pdata_t *)id->driver_data;
scu->dev = &pdev->dev;
scu->irq_mode = pdata->irq_mode;
err = pcim_enable_device(pdev);
if (err)
return err;
err = pcim_iomap_regions(pdev, 1 << 0, pci_name(pdev));
if (err)
return err;
init_completion(&scu->cmd_complete);
err = devm_request_irq(&pdev->dev, pdev->irq, ioc, 0, "intel_scu_ipc",
scu);
if (err)
return err;
scu->ipc_base = pcim_iomap_table(pdev)[0];
scu->i2c_base = ioremap_nocache(pdata->i2c_base, pdata->i2c_len);
if (!scu->i2c_base)
return -ENOMEM;
intel_scu_devices_create();
pci_set_drvdata(pdev, scu);
return 0;
}
static void ipc_remove(struct pci_dev *pdev)
{
struct intel_scu_ipc_dev *scu = pci_get_drvdata(pdev);
mutex_lock(&ipclock);
scu->dev = NULL;
mutex_unlock(&ipclock);
iounmap(scu->i2c_base);
intel_scu_devices_destroy();
}
