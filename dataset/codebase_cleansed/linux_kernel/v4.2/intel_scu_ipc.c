static inline void ipc_command(u32 cmd)
{
if (ipcdev.irq_mode) {
reinit_completion(&ipcdev.cmd_complete);
writel(cmd | IPC_IOC, ipcdev.ipc_base);
}
writel(cmd, ipcdev.ipc_base);
}
static inline void ipc_data_writel(u32 data, u32 offset)
{
writel(data, ipcdev.ipc_base + 0x80 + offset);
}
static inline u8 ipc_read_status(void)
{
return __raw_readl(ipcdev.ipc_base + 0x04);
}
static inline u8 ipc_data_readb(u32 offset)
{
return readb(ipcdev.ipc_base + IPC_READ_BUFFER + offset);
}
static inline u32 ipc_data_readl(u32 offset)
{
return readl(ipcdev.ipc_base + IPC_READ_BUFFER + offset);
}
static inline int busy_loop(void)
{
u32 status = ipc_read_status();
u32 loop_count = 100000;
while ((status & BIT(0)) && --loop_count) {
udelay(1);
status = ipc_read_status();
}
if (status & BIT(0)) {
dev_err(&ipcdev.pdev->dev, "IPC timed out");
return -ETIMEDOUT;
}
if (status & BIT(1))
return -EIO;
return 0;
}
static inline int ipc_wait_for_interrupt(void)
{
int status;
if (!wait_for_completion_timeout(&ipcdev.cmd_complete, 3 * HZ)) {
struct device *dev = &ipcdev.pdev->dev;
dev_err(dev, "IPC timed out\n");
return -ETIMEDOUT;
}
status = ipc_read_status();
if (status & BIT(1))
return -EIO;
return 0;
}
static int intel_scu_ipc_check_status(void)
{
return ipcdev.irq_mode ? ipc_wait_for_interrupt() : busy_loop();
}
static int pwr_reg_rdwr(u16 *addr, u8 *data, u32 count, u32 op, u32 id)
{
int nc;
u32 offset = 0;
int err;
u8 cbuf[IPC_WWBUF_SIZE];
u32 *wbuf = (u32 *)&cbuf;
memset(cbuf, 0, sizeof(cbuf));
mutex_lock(&ipclock);
if (ipcdev.pdev == NULL) {
mutex_unlock(&ipclock);
return -ENODEV;
}
for (nc = 0; nc < count; nc++, offset += 2) {
cbuf[offset] = addr[nc];
cbuf[offset + 1] = addr[nc] >> 8;
}
if (id == IPC_CMD_PCNTRL_R) {
for (nc = 0, offset = 0; nc < count; nc++, offset += 4)
ipc_data_writel(wbuf[nc], offset);
ipc_command((count * 2) << 16 | id << 12 | 0 << 8 | op);
} else if (id == IPC_CMD_PCNTRL_W) {
for (nc = 0; nc < count; nc++, offset += 1)
cbuf[offset] = data[nc];
for (nc = 0, offset = 0; nc < count; nc++, offset += 4)
ipc_data_writel(wbuf[nc], offset);
ipc_command((count * 3) << 16 | id << 12 | 0 << 8 | op);
} else if (id == IPC_CMD_PCNTRL_M) {
cbuf[offset] = data[0];
cbuf[offset + 1] = data[1];
ipc_data_writel(wbuf[0], 0);
ipc_command(4 << 16 | id << 12 | 0 << 8 | op);
}
err = intel_scu_ipc_check_status();
if (!err && id == IPC_CMD_PCNTRL_R) {
memcpy_fromio(cbuf, ipcdev.ipc_base + 0x90, 16);
for (nc = 0; nc < count; nc++)
data[nc] = ipc_data_readb(nc);
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
int err;
mutex_lock(&ipclock);
if (ipcdev.pdev == NULL) {
mutex_unlock(&ipclock);
return -ENODEV;
}
ipc_command(sub << 12 | cmd);
err = intel_scu_ipc_check_status();
mutex_unlock(&ipclock);
return err;
}
int intel_scu_ipc_command(int cmd, int sub, u32 *in, int inlen,
u32 *out, int outlen)
{
int i, err;
mutex_lock(&ipclock);
if (ipcdev.pdev == NULL) {
mutex_unlock(&ipclock);
return -ENODEV;
}
for (i = 0; i < inlen; i++)
ipc_data_writel(*in++, 4 * i);
ipc_command((inlen << 16) | (sub << 12) | cmd);
err = intel_scu_ipc_check_status();
if (!err) {
for (i = 0; i < outlen; i++)
*out++ = ipc_data_readl(4 * i);
}
mutex_unlock(&ipclock);
return err;
}
int intel_scu_ipc_i2c_cntrl(u32 addr, u32 *data)
{
u32 cmd = 0;
mutex_lock(&ipclock);
if (ipcdev.pdev == NULL) {
mutex_unlock(&ipclock);
return -ENODEV;
}
cmd = (addr >> 24) & 0xFF;
if (cmd == IPC_I2C_READ) {
writel(addr, ipcdev.i2c_base + IPC_I2C_CNTRL_ADDR);
mdelay(1);
*data = readl(ipcdev.i2c_base + I2C_DATA_ADDR);
} else if (cmd == IPC_I2C_WRITE) {
writel(*data, ipcdev.i2c_base + I2C_DATA_ADDR);
mdelay(1);
writel(addr, ipcdev.i2c_base + IPC_I2C_CNTRL_ADDR);
} else {
dev_err(&ipcdev.pdev->dev,
"intel_scu_ipc: I2C INVALID_CMD = 0x%x\n", cmd);
mutex_unlock(&ipclock);
return -EIO;
}
mutex_unlock(&ipclock);
return 0;
}
static irqreturn_t ioc(int irq, void *dev_id)
{
if (ipcdev.irq_mode)
complete(&ipcdev.cmd_complete);
return IRQ_HANDLED;
}
static int ipc_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
int err;
struct intel_scu_ipc_pdata_t *pdata;
resource_size_t base;
if (ipcdev.pdev)
return -EBUSY;
pdata = (struct intel_scu_ipc_pdata_t *)id->driver_data;
ipcdev.pdev = pci_dev_get(dev);
ipcdev.irq_mode = pdata->irq_mode;
err = pci_enable_device(dev);
if (err)
return err;
err = pci_request_regions(dev, "intel_scu_ipc");
if (err)
return err;
base = pci_resource_start(dev, 0);
if (!base)
return -ENOMEM;
init_completion(&ipcdev.cmd_complete);
if (request_irq(dev->irq, ioc, 0, "intel_scu_ipc", &ipcdev))
return -EBUSY;
ipcdev.ipc_base = ioremap_nocache(base, pci_resource_len(dev, 0));
if (!ipcdev.ipc_base)
return -ENOMEM;
ipcdev.i2c_base = ioremap_nocache(pdata->i2c_base, pdata->i2c_len);
if (!ipcdev.i2c_base) {
iounmap(ipcdev.ipc_base);
return -ENOMEM;
}
intel_scu_devices_create();
return 0;
}
static void ipc_remove(struct pci_dev *pdev)
{
free_irq(pdev->irq, &ipcdev);
pci_release_regions(pdev);
pci_dev_put(ipcdev.pdev);
iounmap(ipcdev.ipc_base);
iounmap(ipcdev.i2c_base);
ipcdev.pdev = NULL;
intel_scu_devices_destroy();
}
static int __init intel_scu_ipc_init(void)
{
int platform;
platform = intel_mid_identify_cpu();
if (platform == 0)
return -ENODEV;
return pci_register_driver(&ipc_driver);
}
static void __exit intel_scu_ipc_exit(void)
{
pci_unregister_driver(&ipc_driver);
}
