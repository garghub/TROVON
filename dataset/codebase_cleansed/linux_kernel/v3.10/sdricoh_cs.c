static inline unsigned int sdricoh_readl(struct sdricoh_host *host,
unsigned int reg)
{
unsigned int value = readl(host->iobase + reg);
dev_vdbg(host->dev, "rl %x 0x%x\n", reg, value);
return value;
}
static inline void sdricoh_writel(struct sdricoh_host *host, unsigned int reg,
unsigned int value)
{
writel(value, host->iobase + reg);
dev_vdbg(host->dev, "wl %x 0x%x\n", reg, value);
}
static inline unsigned int sdricoh_readw(struct sdricoh_host *host,
unsigned int reg)
{
unsigned int value = readw(host->iobase + reg);
dev_vdbg(host->dev, "rb %x 0x%x\n", reg, value);
return value;
}
static inline void sdricoh_writew(struct sdricoh_host *host, unsigned int reg,
unsigned short value)
{
writew(value, host->iobase + reg);
dev_vdbg(host->dev, "ww %x 0x%x\n", reg, value);
}
static inline unsigned int sdricoh_readb(struct sdricoh_host *host,
unsigned int reg)
{
unsigned int value = readb(host->iobase + reg);
dev_vdbg(host->dev, "rb %x 0x%x\n", reg, value);
return value;
}
static int sdricoh_query_status(struct sdricoh_host *host, unsigned int wanted,
unsigned int timeout){
unsigned int loop;
unsigned int status = 0;
struct device *dev = host->dev;
for (loop = 0; loop < timeout; loop++) {
status = sdricoh_readl(host, R21C_STATUS);
sdricoh_writel(host, R2E4_STATUS_RESP, status);
if (status & wanted)
break;
}
if (loop == timeout) {
dev_err(dev, "query_status: timeout waiting for %x\n", wanted);
return -ETIMEDOUT;
}
if (status & 0x7F0000) {
dev_err(dev, "waiting for status bit %x failed\n", wanted);
return -EINVAL;
}
return 0;
}
static int sdricoh_mmc_cmd(struct sdricoh_host *host, unsigned char opcode,
unsigned int arg)
{
unsigned int status;
int result = 0;
unsigned int loop = 0;
sdricoh_writel(host, R21C_STATUS, 0x18);
sdricoh_writel(host, R204_CMD_ARG, arg);
sdricoh_writel(host, R200_CMD, (0x10000 << 8) | opcode);
if (opcode) {
for (loop = 0; loop < CMD_TIMEOUT; loop++) {
status = sdricoh_readl(host, R21C_STATUS);
sdricoh_writel(host, R2E4_STATUS_RESP, status);
if (status & STATUS_CMD_FINISHED)
break;
}
if (loop == CMD_TIMEOUT || status & STATUS_CMD_TIMEOUT)
result = -ETIMEDOUT;
}
return result;
}
static int sdricoh_reset(struct sdricoh_host *host)
{
dev_dbg(host->dev, "reset\n");
sdricoh_writel(host, R2F0_RESET, 0x10001);
sdricoh_writel(host, R2E0_INIT, 0x10000);
if (sdricoh_readl(host, R2E0_INIT) != 0x10000)
return -EIO;
sdricoh_writel(host, R2E0_INIT, 0x10007);
sdricoh_writel(host, R224_MODE, 0x2000000);
sdricoh_writel(host, R228_POWER, 0xe0);
sdricoh_writel(host, R21C_STATUS, 0x18);
return 0;
}
static int sdricoh_blockio(struct sdricoh_host *host, int read,
u8 *buf, int len)
{
int size;
u32 data = 0;
if (read) {
if (sdricoh_query_status(host, STATUS_READY_TO_READ,
TRANSFER_TIMEOUT))
return -ETIMEDOUT;
sdricoh_writel(host, R21C_STATUS, 0x18);
while (len) {
data = sdricoh_readl(host, R230_DATA);
size = min(len, 4);
len -= size;
while (size) {
*buf = data & 0xFF;
buf++;
data >>= 8;
size--;
}
}
} else {
if (sdricoh_query_status(host, STATUS_READY_TO_WRITE,
TRANSFER_TIMEOUT))
return -ETIMEDOUT;
sdricoh_writel(host, R21C_STATUS, 0x18);
while (len) {
size = min(len, 4);
len -= size;
while (size) {
data >>= 8;
data |= (u32)*buf << 24;
buf++;
size--;
}
sdricoh_writel(host, R230_DATA, data);
}
}
if (len)
return -EIO;
return 0;
}
static void sdricoh_request(struct mmc_host *mmc, struct mmc_request *mrq)
{
struct sdricoh_host *host = mmc_priv(mmc);
struct mmc_command *cmd = mrq->cmd;
struct mmc_data *data = cmd->data;
struct device *dev = host->dev;
unsigned char opcode = cmd->opcode;
int i;
dev_dbg(dev, "=============================\n");
dev_dbg(dev, "sdricoh_request opcode=%i\n", opcode);
sdricoh_writel(host, R21C_STATUS, 0x18);
if (host->app_cmd) {
opcode |= 64;
host->app_cmd = 0;
} else if (opcode == 55)
host->app_cmd = 1;
if (data) {
sdricoh_writew(host, R226_BLOCKSIZE, data->blksz);
sdricoh_writel(host, R208_DATAIO, 0);
}
cmd->error = sdricoh_mmc_cmd(host, opcode, cmd->arg);
if (cmd->flags & MMC_RSP_PRESENT) {
if (cmd->flags & MMC_RSP_136) {
for (i = 0; i < 4; i++) {
cmd->resp[i] =
sdricoh_readl(host,
R20C_RESP + (3 - i) * 4) << 8;
if (i != 3)
cmd->resp[i] |=
sdricoh_readb(host, R20C_RESP +
(3 - i) * 4 - 1);
}
} else
cmd->resp[0] = sdricoh_readl(host, R20C_RESP);
}
if (data && cmd->error == 0) {
dev_dbg(dev, "transfer: blksz %i blocks %i sg_len %i "
"sg length %i\n", data->blksz, data->blocks,
data->sg_len, data->sg->length);
sdricoh_writel(host, R21C_STATUS, 0x837f031e);
for (i = 0; i < data->blocks; i++) {
size_t len = data->blksz;
u8 *buf;
struct page *page;
int result;
page = sg_page(data->sg);
buf = kmap(page) + data->sg->offset + (len * i);
result =
sdricoh_blockio(host,
data->flags & MMC_DATA_READ, buf, len);
kunmap(page);
flush_dcache_page(page);
if (result) {
dev_err(dev, "sdricoh_request: cmd %i "
"block transfer failed\n", cmd->opcode);
cmd->error = result;
break;
} else
data->bytes_xfered += len;
}
sdricoh_writel(host, R208_DATAIO, 1);
if (sdricoh_query_status(host, STATUS_TRANSFER_FINISHED,
TRANSFER_TIMEOUT)) {
dev_err(dev, "sdricoh_request: transfer end error\n");
cmd->error = -EINVAL;
}
}
mmc_request_done(mmc, mrq);
dev_dbg(dev, "=============================\n");
}
static void sdricoh_set_ios(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct sdricoh_host *host = mmc_priv(mmc);
dev_dbg(host->dev, "set_ios\n");
if (ios->power_mode == MMC_POWER_ON) {
sdricoh_writel(host, R228_POWER, 0xc0e0);
if (ios->bus_width == MMC_BUS_WIDTH_4) {
sdricoh_writel(host, R224_MODE, 0x2000300);
sdricoh_writel(host, R228_POWER, 0x40e0);
} else {
sdricoh_writel(host, R224_MODE, 0x2000340);
}
} else if (ios->power_mode == MMC_POWER_UP) {
sdricoh_writel(host, R224_MODE, 0x2000320);
sdricoh_writel(host, R228_POWER, 0xe0);
}
}
static int sdricoh_get_ro(struct mmc_host *mmc)
{
struct sdricoh_host *host = mmc_priv(mmc);
unsigned int status;
status = sdricoh_readl(host, R21C_STATUS);
sdricoh_writel(host, R2E4_STATUS_RESP, status);
if (switchlocked)
return !(status & STATUS_CARD_LOCKED);
return (status & STATUS_CARD_LOCKED);
}
static int sdricoh_init_mmc(struct pci_dev *pci_dev,
struct pcmcia_device *pcmcia_dev)
{
int result = 0;
void __iomem *iobase = NULL;
struct mmc_host *mmc = NULL;
struct sdricoh_host *host = NULL;
struct device *dev = &pcmcia_dev->dev;
if (pci_resource_len(pci_dev, SDRICOH_PCI_REGION) !=
SDRICOH_PCI_REGION_SIZE) {
dev_dbg(dev, "unexpected pci resource len\n");
return -ENODEV;
}
iobase =
pci_iomap(pci_dev, SDRICOH_PCI_REGION, SDRICOH_PCI_REGION_SIZE);
if (!iobase) {
dev_err(dev, "unable to map iobase\n");
return -ENODEV;
}
if (readl(iobase + R104_VERSION) != 0x4000) {
dev_dbg(dev, "no supported mmc controller found\n");
result = -ENODEV;
goto err;
}
mmc = pcmcia_dev->priv =
mmc_alloc_host(sizeof(struct sdricoh_host), &pcmcia_dev->dev);
if (!mmc) {
dev_err(dev, "mmc_alloc_host failed\n");
result = -ENOMEM;
goto err;
}
host = mmc_priv(mmc);
host->iobase = iobase;
host->dev = dev;
host->pci_dev = pci_dev;
mmc->ops = &sdricoh_ops;
mmc->f_min = 450000;
mmc->f_max = 24000000;
mmc->ocr_avail = MMC_VDD_32_33 | MMC_VDD_33_34;
mmc->caps |= MMC_CAP_4_BIT_DATA;
mmc->max_seg_size = 1024 * 512;
mmc->max_blk_size = 512;
if (sdricoh_reset(host)) {
dev_dbg(dev, "could not reset\n");
result = -EIO;
goto err;
}
result = mmc_add_host(mmc);
if (!result) {
dev_dbg(dev, "mmc host registered\n");
return 0;
}
err:
if (iobase)
pci_iounmap(pci_dev, iobase);
if (mmc)
mmc_free_host(mmc);
return result;
}
static int sdricoh_pcmcia_probe(struct pcmcia_device *pcmcia_dev)
{
struct pci_dev *pci_dev = NULL;
dev_info(&pcmcia_dev->dev, "Searching MMC controller for pcmcia device"
" %s %s ...\n", pcmcia_dev->prod_id[0], pcmcia_dev->prod_id[1]);
while ((pci_dev =
pci_get_device(PCI_VENDOR_ID_RICOH, PCI_DEVICE_ID_RICOH_RL5C476,
pci_dev))) {
if (!sdricoh_init_mmc(pci_dev, pcmcia_dev)) {
dev_info(&pcmcia_dev->dev, "MMC controller found\n");
return 0;
}
}
dev_err(&pcmcia_dev->dev, "No MMC controller was found.\n");
return -ENODEV;
}
static void sdricoh_pcmcia_detach(struct pcmcia_device *link)
{
struct mmc_host *mmc = link->priv;
dev_dbg(&link->dev, "detach\n");
if (mmc) {
struct sdricoh_host *host = mmc_priv(mmc);
mmc_remove_host(mmc);
pci_iounmap(host->pci_dev, host->iobase);
pci_dev_put(host->pci_dev);
mmc_free_host(mmc);
}
pcmcia_disable_device(link);
}
static int sdricoh_pcmcia_suspend(struct pcmcia_device *link)
{
struct mmc_host *mmc = link->priv;
dev_dbg(&link->dev, "suspend\n");
mmc_suspend_host(mmc);
return 0;
}
static int sdricoh_pcmcia_resume(struct pcmcia_device *link)
{
struct mmc_host *mmc = link->priv;
dev_dbg(&link->dev, "resume\n");
sdricoh_reset(mmc_priv(mmc));
mmc_resume_host(mmc);
return 0;
}
