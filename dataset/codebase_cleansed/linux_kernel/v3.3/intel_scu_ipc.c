static inline void ipc_command(u32 cmd)
{
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
u32 status = 0;
u32 loop_count = 0;
status = ipc_read_status();
while (status & 1) {
udelay(1);
status = ipc_read_status();
loop_count++;
if (loop_count > 100000) {
dev_err(&ipcdev.pdev->dev, "IPC timed out");
return -ETIMEDOUT;
}
}
if ((status >> 1) & 1)
return -EIO;
return 0;
}
static int pwr_reg_rdwr(u16 *addr, u8 *data, u32 count, u32 op, u32 id)
{
int i, nc, bytes, d;
u32 offset = 0;
int err;
u8 cbuf[IPC_WWBUF_SIZE] = { };
u32 *wbuf = (u32 *)&cbuf;
mutex_lock(&ipclock);
memset(cbuf, 0, sizeof(cbuf));
if (ipcdev.pdev == NULL) {
mutex_unlock(&ipclock);
return -ENODEV;
}
if (platform != MRST_CPU_CHIP_PENWELL) {
bytes = 0;
d = 0;
for (i = 0; i < count; i++) {
cbuf[bytes++] = addr[i];
cbuf[bytes++] = addr[i] >> 8;
if (id != IPC_CMD_PCNTRL_R)
cbuf[bytes++] = data[d++];
if (id == IPC_CMD_PCNTRL_M)
cbuf[bytes++] = data[d++];
}
for (i = 0; i < bytes; i += 4)
ipc_data_writel(wbuf[i/4], i);
ipc_command(bytes << 16 | id << 12 | 0 << 8 | op);
} else {
for (nc = 0; nc < count; nc++, offset += 2) {
cbuf[offset] = addr[nc];
cbuf[offset + 1] = addr[nc] >> 8;
}
if (id == IPC_CMD_PCNTRL_R) {
for (nc = 0, offset = 0; nc < count; nc++, offset += 4)
ipc_data_writel(wbuf[nc], offset);
ipc_command((count*2) << 16 | id << 12 | 0 << 8 | op);
} else if (id == IPC_CMD_PCNTRL_W) {
for (nc = 0; nc < count; nc++, offset += 1)
cbuf[offset] = data[nc];
for (nc = 0, offset = 0; nc < count; nc++, offset += 4)
ipc_data_writel(wbuf[nc], offset);
ipc_command((count*3) << 16 | id << 12 | 0 << 8 | op);
} else if (id == IPC_CMD_PCNTRL_M) {
cbuf[offset] = data[0];
cbuf[offset + 1] = data[1];
ipc_data_writel(wbuf[0], 0);
ipc_command(4 << 16 | id << 12 | 0 << 8 | op);
}
}
err = busy_loop();
if (id == IPC_CMD_PCNTRL_R) {
memcpy_fromio(cbuf, ipcdev.ipc_base + 0x90, 16);
if (platform != MRST_CPU_CHIP_PENWELL) {
for (nc = 0, offset = 2; nc < count; nc++, offset += 3)
data[nc] = ipc_data_readb(offset);
} else {
for (nc = 0; nc < count; nc++)
data[nc] = ipc_data_readb(nc);
}
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
u16 x[2] = {addr, addr + 1 };
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
u16 x[2] = {addr, addr + 1 };
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
err = busy_loop();
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
err = busy_loop();
for (i = 0; i < outlen; i++)
*out++ = ipc_data_readl(4 * i);
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
int intel_scu_ipc_fw_update(u8 *buffer, u32 length)
{
void __iomem *fw_update_base;
struct fw_update_mailbox __iomem *mailbox = NULL;
int retry_cnt = 0;
u32 status;
mutex_lock(&ipclock);
fw_update_base = ioremap_nocache(IPC_FW_LOAD_ADDR, (128*1024));
if (fw_update_base == NULL) {
mutex_unlock(&ipclock);
return -ENOMEM;
}
mailbox = ioremap_nocache(IPC_FW_UPDATE_MBOX_ADDR,
sizeof(struct fw_update_mailbox));
if (mailbox == NULL) {
iounmap(fw_update_base);
mutex_unlock(&ipclock);
return -ENOMEM;
}
ipc_command(IPC_CMD_FW_UPDATE_READY);
writel(0, &mailbox->status);
writel(0, &mailbox->scu_flag);
writel(0, &mailbox->driver_flag);
memcpy_toio(fw_update_base, buffer, 0x800);
ipc_command(IPC_CMD_FW_UPDATE_GO);
while (readl(&mailbox->scu_flag) != 1) {
rmb();
mdelay(1);
}
while (readl(&mailbox->status) != IPC_FW_TXLOW) {
rmb();
mdelay(10);
}
mdelay(10);
update_retry:
if (retry_cnt > 5)
goto update_end;
if (readl(&mailbox->status) != IPC_FW_TXLOW)
goto update_end;
buffer = buffer + 0x800;
memcpy_toio(fw_update_base, buffer, 0x20000);
writel(1, &mailbox->driver_flag);
while (readl(&mailbox->scu_flag) == 1) {
rmb();
mdelay(1);
}
if (readl(&mailbox->status) == IPC_FW_UPDATE_BADN)
goto update_end;
while (readl(&mailbox->status) != IPC_FW_TXHIGH) {
rmb();
mdelay(10);
}
mdelay(10);
if (readl(&mailbox->status) != IPC_FW_TXHIGH)
goto update_end;
buffer = buffer + 0x20000;
memcpy_toio(fw_update_base, buffer, 0x20000);
writel(0, &mailbox->driver_flag);
while (mailbox->scu_flag == 0) {
rmb();
mdelay(1);
}
if (readl(&mailbox->status) == IPC_FW_UPDATE_BADN)
goto update_end;
if (readl(&mailbox->status) == IPC_FW_TXLOW) {
++retry_cnt;
goto update_retry;
}
update_end:
status = readl(&mailbox->status);
iounmap(fw_update_base);
iounmap(mailbox);
mutex_unlock(&ipclock);
if (status == IPC_FW_UPDATE_SUCCESS)
return 0;
return -EIO;
}
static irqreturn_t ioc(int irq, void *dev_id)
{
return IRQ_HANDLED;
}
static int ipc_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
int err;
resource_size_t pci_resource;
if (ipcdev.pdev)
return -EBUSY;
ipcdev.pdev = pci_dev_get(dev);
err = pci_enable_device(dev);
if (err)
return err;
err = pci_request_regions(dev, "intel_scu_ipc");
if (err)
return err;
pci_resource = pci_resource_start(dev, 0);
if (!pci_resource)
return -ENOMEM;
if (request_irq(dev->irq, ioc, 0, "intel_scu_ipc", &ipcdev))
return -EBUSY;
ipcdev.ipc_base = ioremap_nocache(IPC_BASE_ADDR, IPC_MAX_ADDR);
if (!ipcdev.ipc_base)
return -ENOMEM;
ipcdev.i2c_base = ioremap_nocache(IPC_I2C_BASE, IPC_I2C_MAX_ADDR);
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
platform = mrst_identify_cpu();
if (platform == 0)
return -ENODEV;
return pci_register_driver(&ipc_driver);
}
static void __exit intel_scu_ipc_exit(void)
{
pci_unregister_driver(&ipc_driver);
}
