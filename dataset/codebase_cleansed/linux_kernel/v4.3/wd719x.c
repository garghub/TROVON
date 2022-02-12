static inline u8 wd719x_readb(struct wd719x *wd, u8 reg)
{
return ioread8(wd->base + reg);
}
static inline u32 wd719x_readl(struct wd719x *wd, u8 reg)
{
return ioread32(wd->base + reg);
}
static inline void wd719x_writeb(struct wd719x *wd, u8 reg, u8 val)
{
iowrite8(val, wd->base + reg);
}
static inline void wd719x_writew(struct wd719x *wd, u8 reg, u16 val)
{
iowrite16(val, wd->base + reg);
}
static inline void wd719x_writel(struct wd719x *wd, u8 reg, u32 val)
{
iowrite32(val, wd->base + reg);
}
static inline int wd719x_wait_ready(struct wd719x *wd)
{
int i = 0;
do {
if (wd719x_readb(wd, WD719X_AMR_COMMAND) == WD719X_CMD_READY)
return 0;
udelay(1);
} while (i++ < WD719X_WAIT_FOR_CMD_READY);
dev_err(&wd->pdev->dev, "command register is not ready: 0x%02x\n",
wd719x_readb(wd, WD719X_AMR_COMMAND));
return -ETIMEDOUT;
}
static inline int wd719x_wait_done(struct wd719x *wd, int timeout)
{
u8 status;
while (timeout > 0) {
status = wd719x_readb(wd, WD719X_AMR_INT_STATUS);
if (status)
break;
timeout--;
udelay(1);
}
if (timeout <= 0) {
dev_err(&wd->pdev->dev, "direct command timed out\n");
return -ETIMEDOUT;
}
if (status != WD719X_INT_NOERRORS) {
dev_err(&wd->pdev->dev, "direct command failed, status 0x%02x, SUE 0x%02x\n",
status, wd719x_readb(wd, WD719X_AMR_SCB_ERROR));
return -EIO;
}
return 0;
}
static int wd719x_direct_cmd(struct wd719x *wd, u8 opcode, u8 dev, u8 lun,
u8 tag, dma_addr_t data, int timeout)
{
int ret = 0;
wd719x_writeb(wd, WD719X_AMR_INT_STATUS, WD719X_INT_NONE);
if (wd719x_wait_ready(wd))
return -ETIMEDOUT;
dev |= WD719X_DISABLE_INT;
wd719x_writeb(wd, WD719X_AMR_CMD_PARAM, dev);
wd719x_writeb(wd, WD719X_AMR_CMD_PARAM_2, lun);
wd719x_writeb(wd, WD719X_AMR_CMD_PARAM_3, tag);
if (data)
wd719x_writel(wd, WD719X_AMR_SCB_IN, data);
wd719x_writeb(wd, WD719X_AMR_INT_STATUS, WD719X_INT_NONE);
wd719x_writeb(wd, WD719X_AMR_COMMAND, opcode);
if (timeout)
ret = wd719x_wait_done(wd, timeout);
if (opcode != WD719X_CMD_READ_FIRMVER)
wd719x_writeb(wd, WD719X_AMR_INT_STATUS, WD719X_INT_NONE);
return ret;
}
static void wd719x_destroy(struct wd719x *wd)
{
struct wd719x_scb *scb;
if (wd719x_direct_cmd(wd, WD719X_CMD_SLEEP, 0, 0, 0, 0,
WD719X_WAIT_FOR_RISC))
dev_warn(&wd->pdev->dev, "RISC sleep command failed\n");
wd719x_writeb(wd, WD719X_PCI_MODE_SELECT, 0);
list_for_each_entry(scb, &wd->active_scbs, list)
pci_free_consistent(wd->pdev, sizeof(struct wd719x_scb), scb,
scb->phys);
list_for_each_entry(scb, &wd->free_scbs, list)
pci_free_consistent(wd->pdev, sizeof(struct wd719x_scb), scb,
scb->phys);
pci_free_consistent(wd->pdev, wd->fw_size, wd->fw_virt, wd->fw_phys);
wd->fw_virt = NULL;
pci_free_consistent(wd->pdev, WD719X_HASH_TABLE_SIZE, wd->hash_virt,
wd->hash_phys);
wd->hash_virt = NULL;
pci_free_consistent(wd->pdev, sizeof(struct wd719x_host_param),
wd->params, wd->params_phys);
wd->params = NULL;
free_irq(wd->pdev->irq, wd);
}
static void wd719x_finish_cmd(struct scsi_cmnd *cmd, int result)
{
struct wd719x *wd = shost_priv(cmd->device->host);
struct wd719x_scb *scb = (struct wd719x_scb *) cmd->host_scribble;
if (scb) {
list_move(&scb->list, &wd->free_scbs);
dma_unmap_single(&wd->pdev->dev, cmd->SCp.dma_handle,
SCSI_SENSE_BUFFERSIZE, DMA_FROM_DEVICE);
scsi_dma_unmap(cmd);
}
cmd->result = result << 16;
cmd->scsi_done(cmd);
}
static int wd719x_queuecommand(struct Scsi_Host *sh, struct scsi_cmnd *cmd)
{
int i, count_sg;
unsigned long flags;
struct wd719x_scb *scb;
struct wd719x *wd = shost_priv(sh);
dma_addr_t phys;
cmd->host_scribble = NULL;
spin_lock_irqsave(wd->sh->host_lock, flags);
scb = list_first_entry_or_null(&wd->free_scbs, struct wd719x_scb, list);
if (scb) {
list_del(&scb->list);
phys = scb->phys;
} else {
spin_unlock_irqrestore(wd->sh->host_lock, flags);
scb = pci_alloc_consistent(wd->pdev, sizeof(struct wd719x_scb),
&phys);
spin_lock_irqsave(wd->sh->host_lock, flags);
if (!scb) {
dev_err(&wd->pdev->dev, "unable to allocate SCB\n");
wd719x_finish_cmd(cmd, DID_ERROR);
spin_unlock_irqrestore(wd->sh->host_lock, flags);
return 0;
}
}
memset(scb, 0, sizeof(struct wd719x_scb));
list_add(&scb->list, &wd->active_scbs);
scb->phys = phys;
scb->cmd = cmd;
cmd->host_scribble = (char *) scb;
scb->CDB_tag = 0;
scb->devid = cmd->device->id;
scb->lun = cmd->device->lun;
memcpy(scb->CDB, cmd->cmnd, cmd->cmd_len);
scb->sense_buf_length = SCSI_SENSE_BUFFERSIZE;
cmd->SCp.dma_handle = dma_map_single(&wd->pdev->dev, cmd->sense_buffer,
SCSI_SENSE_BUFFERSIZE, DMA_FROM_DEVICE);
scb->sense_buf = cpu_to_le32(cmd->SCp.dma_handle);
scb->SCB_options |= WD719X_SCB_FLAGS_AUTO_REQUEST_SENSE;
if (cmd->sc_data_direction == DMA_TO_DEVICE)
scb->SCB_options |= WD719X_SCB_FLAGS_CHECK_DIRECTION
| WD719X_SCB_FLAGS_PCI_TO_SCSI;
else if (cmd->sc_data_direction == DMA_FROM_DEVICE)
scb->SCB_options |= WD719X_SCB_FLAGS_CHECK_DIRECTION;
count_sg = scsi_dma_map(cmd);
if (count_sg < 0) {
wd719x_finish_cmd(cmd, DID_ERROR);
spin_unlock_irqrestore(wd->sh->host_lock, flags);
return 0;
}
BUG_ON(count_sg > WD719X_SG);
if (count_sg) {
struct scatterlist *sg;
scb->data_length = cpu_to_le32(count_sg *
sizeof(struct wd719x_sglist));
scb->data_p = cpu_to_le32(scb->phys +
offsetof(struct wd719x_scb, sg_list));
scsi_for_each_sg(cmd, sg, count_sg, i) {
scb->sg_list[i].ptr = cpu_to_le32(sg_dma_address(sg));
scb->sg_list[i].length = cpu_to_le32(sg_dma_len(sg));
}
scb->SCB_options |= WD719X_SCB_FLAGS_DO_SCATTER_GATHER;
} else {
scb->data_length = 0;
scb->data_p = 0;
}
if (wd719x_readb(wd, WD719X_AMR_COMMAND) != WD719X_CMD_READY) {
spin_unlock_irqrestore(wd->sh->host_lock, flags);
return SCSI_MLQUEUE_HOST_BUSY;
}
wd719x_writel(wd, WD719X_AMR_SCB_IN, scb->phys);
wd719x_writeb(wd, WD719X_AMR_COMMAND, WD719X_CMD_PROCESS_SCB);
spin_unlock_irqrestore(wd->sh->host_lock, flags);
return 0;
}
static int wd719x_chip_init(struct wd719x *wd)
{
int i, ret;
u32 risc_init[3];
const struct firmware *fw_wcs, *fw_risc;
const char fwname_wcs[] = "wd719x-wcs.bin";
const char fwname_risc[] = "wd719x-risc.bin";
memset(wd->hash_virt, 0, WD719X_HASH_TABLE_SIZE);
ret = request_firmware(&fw_wcs, fwname_wcs, &wd->pdev->dev);
if (ret) {
dev_err(&wd->pdev->dev, "Unable to load firmware %s: %d\n",
fwname_wcs, ret);
return ret;
}
ret = request_firmware(&fw_risc, fwname_risc, &wd->pdev->dev);
if (ret) {
dev_err(&wd->pdev->dev, "Unable to load firmware %s: %d\n",
fwname_risc, ret);
release_firmware(fw_wcs);
return ret;
}
wd->fw_size = ALIGN(fw_wcs->size, 4) + fw_risc->size;
if (!wd->fw_virt)
wd->fw_virt = pci_alloc_consistent(wd->pdev, wd->fw_size,
&wd->fw_phys);
if (!wd->fw_virt) {
ret = -ENOMEM;
goto wd719x_init_end;
}
memcpy(wd->fw_virt, fw_wcs->data, fw_wcs->size);
memcpy(wd->fw_virt + ALIGN(fw_wcs->size, 4), fw_risc->data,
fw_risc->size);
wd719x_writeb(wd, WD719X_PCI_PORT_RESET, WD719X_PCI_RESET);
udelay(WD719X_WAIT_FOR_RISC);
wd719x_writeb(wd, WD719X_AMR_CMD_PARAM, 0);
wd719x_writeb(wd, WD719X_PCI_MODE_SELECT, 0);
wd719x_writeb(wd, WD719X_AMR_COMMAND, 0);
if (wd719x_wait_ready(wd)) {
ret = -ETIMEDOUT;
goto wd719x_init_end;
}
risc_init[0] = wd->fw_phys;
risc_init[1] = wd->fw_phys + ALIGN(fw_wcs->size, 4);
risc_init[2] = wd->hash_phys;
wd719x_writeb(wd, WD719X_PCI_CHANNEL2_3STATUS, 0);
wd719x_writel(wd, WD719X_PCI_EXTERNAL_ADDR, risc_init[1]);
wd719x_writew(wd, WD719X_PCI_INTERNAL_ADDR, WD719X_PRAM_BASE_ADDR);
wd719x_writew(wd, WD719X_PCI_DMA_TRANSFER_SIZE, 2048 * 2);
wd719x_writeb(wd, WD719X_PCI_CHANNEL2_3CMD, WD719X_START_CHANNEL2_3DMA);
i = WD719X_WAIT_FOR_RISC;
while (i-- > 0) {
u8 status = wd719x_readb(wd, WD719X_PCI_CHANNEL2_3STATUS);
if (status == WD719X_START_CHANNEL2_3DONE)
break;
if (status == WD719X_START_CHANNEL2_3ABORT) {
dev_warn(&wd->pdev->dev, "RISC bootstrap failed: DMA aborted\n");
ret = -EIO;
goto wd719x_init_end;
}
udelay(1);
}
if (i < 1) {
dev_warn(&wd->pdev->dev, "RISC bootstrap failed: DMA timeout\n");
ret = -ETIMEDOUT;
goto wd719x_init_end;
}
wd719x_writel(wd, WD719X_AMR_SCB_IN, risc_init[0]);
wd719x_writel(wd, WD719X_AMR_SCB_IN + 4, risc_init[1]);
wd719x_writel(wd, WD719X_AMR_SCB_IN + 8, risc_init[2]);
wd719x_writeb(wd, WD719X_AMR_CMD_PARAM, WD719X_DISABLE_INT);
wd719x_writeb(wd, WD719X_AMR_COMMAND, WD719X_CMD_INIT_RISC);
wd719x_writeb(wd, WD719X_PCI_MODE_SELECT, WD719X_ENABLE_ADVANCE_MODE);
udelay(WD719X_WAIT_FOR_RISC);
ret = wd719x_wait_done(wd, WD719X_WAIT_FOR_RISC);
wd719x_writeb(wd, WD719X_AMR_INT_STATUS, WD719X_INT_NONE);
if (ret) {
dev_warn(&wd->pdev->dev, "Unable to initialize RISC\n");
goto wd719x_init_end;
}
ret = wd719x_direct_cmd(wd, WD719X_CMD_READ_FIRMVER, 0, 0, 0, 0,
WD719X_WAIT_FOR_RISC);
if (ret) {
dev_warn(&wd->pdev->dev, "Unable to read firmware version\n");
goto wd719x_init_end;
}
dev_info(&wd->pdev->dev, "RISC initialized with firmware version %.2x.%.2x\n",
wd719x_readb(wd, WD719X_AMR_SCB_OUT + 1),
wd719x_readb(wd, WD719X_AMR_SCB_OUT));
ret = wd719x_direct_cmd(wd, WD719X_CMD_BUSRESET, 0, 0, 0, 0,
WD719X_WAIT_FOR_SCSI_RESET);
if (ret) {
dev_warn(&wd->pdev->dev, "SCSI bus reset failed\n");
goto wd719x_init_end;
}
ret = wd719x_direct_cmd(wd, WD719X_CMD_SET_PARAM, 0,
sizeof(struct wd719x_host_param), 0,
wd->params_phys, WD719X_WAIT_FOR_RISC);
if (ret) {
dev_warn(&wd->pdev->dev, "Failed to set HOST PARAMETERS\n");
goto wd719x_init_end;
}
ret = wd719x_direct_cmd(wd, WD719X_CMD_INIT_SCAM, 0, 0, 0, 0,
WD719X_WAIT_FOR_SCSI_RESET);
if (ret) {
dev_warn(&wd->pdev->dev, "SCAM initialization failed\n");
goto wd719x_init_end;
}
wd719x_writeb(wd, WD719X_AMR_BIOS_SHARE_INT, 0);
wd719x_init_end:
release_firmware(fw_wcs);
release_firmware(fw_risc);
return ret;
}
static int wd719x_abort(struct scsi_cmnd *cmd)
{
int action, result;
unsigned long flags;
struct wd719x_scb *scb = (struct wd719x_scb *)cmd->host_scribble;
struct wd719x *wd = shost_priv(cmd->device->host);
dev_info(&wd->pdev->dev, "abort command, tag: %x\n", cmd->tag);
action = WD719X_CMD_ABORT;
spin_lock_irqsave(wd->sh->host_lock, flags);
result = wd719x_direct_cmd(wd, action, cmd->device->id,
cmd->device->lun, cmd->tag, scb->phys, 0);
spin_unlock_irqrestore(wd->sh->host_lock, flags);
if (result)
return FAILED;
return SUCCESS;
}
static int wd719x_reset(struct scsi_cmnd *cmd, u8 opcode, u8 device)
{
int result;
unsigned long flags;
struct wd719x *wd = shost_priv(cmd->device->host);
dev_info(&wd->pdev->dev, "%s reset requested\n",
(opcode == WD719X_CMD_BUSRESET) ? "bus" : "device");
spin_lock_irqsave(wd->sh->host_lock, flags);
result = wd719x_direct_cmd(wd, opcode, device, 0, 0, 0,
WD719X_WAIT_FOR_SCSI_RESET);
spin_unlock_irqrestore(wd->sh->host_lock, flags);
if (result)
return FAILED;
return SUCCESS;
}
static int wd719x_dev_reset(struct scsi_cmnd *cmd)
{
return wd719x_reset(cmd, WD719X_CMD_RESET, cmd->device->id);
}
static int wd719x_bus_reset(struct scsi_cmnd *cmd)
{
return wd719x_reset(cmd, WD719X_CMD_BUSRESET, 0);
}
static int wd719x_host_reset(struct scsi_cmnd *cmd)
{
struct wd719x *wd = shost_priv(cmd->device->host);
struct wd719x_scb *scb, *tmp;
unsigned long flags;
int result;
dev_info(&wd->pdev->dev, "host reset requested\n");
spin_lock_irqsave(wd->sh->host_lock, flags);
if (wd719x_chip_init(wd) == 0)
result = SUCCESS;
else
result = FAILED;
list_for_each_entry_safe(scb, tmp, &wd->active_scbs, list) {
struct scsi_cmnd *tmp_cmd = scb->cmd;
wd719x_finish_cmd(tmp_cmd, result);
}
spin_unlock_irqrestore(wd->sh->host_lock, flags);
return result;
}
static int wd719x_biosparam(struct scsi_device *sdev, struct block_device *bdev,
sector_t capacity, int geom[])
{
if (capacity >= 0x200000) {
geom[0] = 255;
geom[1] = 63;
} else {
geom[0] = 64;
geom[1] = 32;
}
geom[2] = sector_div(capacity, geom[0] * geom[1]);
return 0;
}
static inline void wd719x_interrupt_SCB(struct wd719x *wd,
union wd719x_regs regs,
struct wd719x_scb *scb)
{
struct scsi_cmnd *cmd;
int result;
switch (regs.bytes.SUE) {
case WD719X_SUE_NOERRORS:
result = DID_OK;
break;
case WD719X_SUE_REJECTED:
dev_err(&wd->pdev->dev, "command rejected\n");
result = DID_ERROR;
break;
case WD719X_SUE_SCBQFULL:
dev_err(&wd->pdev->dev, "SCB queue is full\n");
result = DID_ERROR;
break;
case WD719X_SUE_TERM:
dev_dbg(&wd->pdev->dev, "SCB terminated by direct command\n");
result = DID_ABORT;
break;
case WD719X_SUE_CHAN1ABORT:
case WD719X_SUE_CHAN23ABORT:
result = DID_ABORT;
dev_err(&wd->pdev->dev, "DMA abort\n");
break;
case WD719X_SUE_CHAN1PAR:
case WD719X_SUE_CHAN23PAR:
result = DID_PARITY;
dev_err(&wd->pdev->dev, "DMA parity error\n");
break;
case WD719X_SUE_TIMEOUT:
result = DID_TIME_OUT;
dev_dbg(&wd->pdev->dev, "selection timeout\n");
break;
case WD719X_SUE_RESET:
dev_dbg(&wd->pdev->dev, "bus reset occurred\n");
result = DID_RESET;
break;
case WD719X_SUE_BUSERROR:
dev_dbg(&wd->pdev->dev, "SCSI bus error\n");
result = DID_ERROR;
break;
case WD719X_SUE_WRONGWAY:
dev_err(&wd->pdev->dev, "wrong data transfer direction\n");
result = DID_ERROR;
break;
case WD719X_SUE_BADPHASE:
dev_err(&wd->pdev->dev, "invalid SCSI phase\n");
result = DID_ERROR;
break;
case WD719X_SUE_TOOLONG:
dev_err(&wd->pdev->dev, "record too long\n");
result = DID_ERROR;
break;
case WD719X_SUE_BUSFREE:
dev_err(&wd->pdev->dev, "unexpected bus free\n");
result = DID_NO_CONNECT;
break;
case WD719X_SUE_ARSDONE:
dev_dbg(&wd->pdev->dev, "auto request sense\n");
if (regs.bytes.SCSI == 0)
result = DID_OK;
else
result = DID_PARITY;
break;
case WD719X_SUE_IGNORED:
dev_err(&wd->pdev->dev, "target id %d ignored command\n",
scb->cmd->device->id);
result = DID_NO_CONNECT;
break;
case WD719X_SUE_WRONGTAGS:
dev_err(&wd->pdev->dev, "reversed tags\n");
result = DID_ERROR;
break;
case WD719X_SUE_BADTAGS:
dev_err(&wd->pdev->dev, "tag type not supported by target\n");
result = DID_ERROR;
break;
case WD719X_SUE_NOSCAMID:
dev_err(&wd->pdev->dev, "no SCAM soft ID available\n");
result = DID_ERROR;
break;
default:
dev_warn(&wd->pdev->dev, "unknown SUE error code: 0x%x\n",
regs.bytes.SUE);
result = DID_ERROR;
break;
}
cmd = scb->cmd;
wd719x_finish_cmd(cmd, result);
}
static irqreturn_t wd719x_interrupt(int irq, void *dev_id)
{
struct wd719x *wd = dev_id;
union wd719x_regs regs;
unsigned long flags;
u32 SCB_out;
spin_lock_irqsave(wd->sh->host_lock, flags);
SCB_out = wd719x_readl(wd, WD719X_AMR_SCB_OUT);
regs.all = cpu_to_le32(wd719x_readl(wd, WD719X_AMR_OP_CODE));
switch (regs.bytes.INT) {
case WD719X_INT_NONE:
spin_unlock_irqrestore(wd->sh->host_lock, flags);
return IRQ_NONE;
case WD719X_INT_LINKNOSTATUS:
dev_err(&wd->pdev->dev, "linked command completed with no status\n");
break;
case WD719X_INT_BADINT:
dev_err(&wd->pdev->dev, "unsolicited interrupt\n");
break;
case WD719X_INT_NOERRORS:
case WD719X_INT_LINKNOERRORS:
case WD719X_INT_ERRORSLOGGED:
case WD719X_INT_SPIDERFAILED:
if (regs.bytes.OPC == WD719X_CMD_PROCESS_SCB) {
struct wd719x_scb *scb;
list_for_each_entry(scb, &wd->active_scbs, list)
if (SCB_out == scb->phys)
break;
if (SCB_out == scb->phys)
wd719x_interrupt_SCB(wd, regs, scb);
else
dev_err(&wd->pdev->dev, "card returned invalid SCB pointer\n");
} else
dev_warn(&wd->pdev->dev, "direct command 0x%x completed\n",
regs.bytes.OPC);
break;
case WD719X_INT_PIOREADY:
dev_err(&wd->pdev->dev, "card indicates PIO data ready but we never use PIO\n");
break;
default:
dev_err(&wd->pdev->dev, "unknown interrupt reason: %d\n",
regs.bytes.INT);
}
wd719x_writeb(wd, WD719X_AMR_INT_STATUS, WD719X_INT_NONE);
spin_unlock_irqrestore(wd->sh->host_lock, flags);
return IRQ_HANDLED;
}
static void wd719x_eeprom_reg_read(struct eeprom_93cx6 *eeprom)
{
struct wd719x *wd = eeprom->data;
u8 reg = wd719x_readb(wd, WD719X_PCI_GPIO_DATA);
eeprom->reg_data_out = reg & WD719X_EE_DO;
}
static void wd719x_eeprom_reg_write(struct eeprom_93cx6 *eeprom)
{
struct wd719x *wd = eeprom->data;
u8 reg = 0;
if (eeprom->reg_data_in)
reg |= WD719X_EE_DI;
if (eeprom->reg_data_clock)
reg |= WD719X_EE_CLK;
if (eeprom->reg_chip_select)
reg |= WD719X_EE_CS;
wd719x_writeb(wd, WD719X_PCI_GPIO_DATA, reg);
}
static void wd719x_read_eeprom(struct wd719x *wd)
{
struct eeprom_93cx6 eeprom;
u8 gpio;
struct wd719x_eeprom_header header;
eeprom.data = wd;
eeprom.register_read = wd719x_eeprom_reg_read;
eeprom.register_write = wd719x_eeprom_reg_write;
eeprom.width = PCI_EEPROM_WIDTH_93C46;
wd719x_writeb(wd, WD719X_PCI_GPIO_DATA, 0);
gpio = wd719x_readb(wd, WD719X_PCI_GPIO_CONTROL);
gpio &= (~(WD719X_EE_CLK | WD719X_EE_DI | WD719X_EE_CS));
gpio |= WD719X_EE_DO;
wd719x_writeb(wd, WD719X_PCI_GPIO_CONTROL, gpio);
eeprom_93cx6_multireadb(&eeprom, 0, (u8 *)&header, sizeof(header));
if (header.sig1 == 'W' && header.sig2 == 'D')
eeprom_93cx6_multireadb(&eeprom, header.cfg_offset,
(u8 *)wd->params,
sizeof(struct wd719x_host_param));
else {
dev_warn(&wd->pdev->dev, "EEPROM signature is invalid (0x%02x 0x%02x), using default values\n",
header.sig1, header.sig2);
wd->params->ch_1_th = 0x10;
wd->params->scsi_conf = 0x4c;
wd->params->own_scsi_id = 0x07;
wd->params->sel_timeout = 0x4d;
wd->params->sleep_timer = 0x01;
wd->params->cdb_size = cpu_to_le16(0x5555);
wd->params->scsi_pad = 0x1b;
if (wd->type == WD719X_TYPE_7193)
wd->params->wide = cpu_to_le32(0x00000000);
else
wd->params->wide = cpu_to_le32(0xffffffff);
wd->params->sync = cpu_to_le32(0xffffffff);
wd->params->soft_mask = 0x00;
wd->params->unsol_mask = 0x00;
}
wd->params->tag_en = cpu_to_le16(0x0000);
}
static enum wd719x_card_type wd719x_detect_type(struct wd719x *wd)
{
u8 card = wd719x_readb(wd, WD719X_PCI_GPIO_CONTROL);
card |= WD719X_GPIO_ID_BITS;
wd719x_writeb(wd, WD719X_PCI_GPIO_CONTROL, card);
card = wd719x_readb(wd, WD719X_PCI_GPIO_DATA) & WD719X_GPIO_ID_BITS;
switch (card) {
case 0x08:
return WD719X_TYPE_7193;
case 0x02:
return WD719X_TYPE_7197;
case 0x00:
return WD719X_TYPE_7296;
default:
dev_warn(&wd->pdev->dev, "unknown card type 0x%x\n", card);
return WD719X_TYPE_UNKNOWN;
}
}
static int wd719x_board_found(struct Scsi_Host *sh)
{
struct wd719x *wd = shost_priv(sh);
char *card_types[] = { "Unknown card", "WD7193", "WD7197", "WD7296" };
int ret;
INIT_LIST_HEAD(&wd->active_scbs);
INIT_LIST_HEAD(&wd->free_scbs);
sh->base = pci_resource_start(wd->pdev, 0);
wd->type = wd719x_detect_type(wd);
wd->sh = sh;
sh->irq = wd->pdev->irq;
wd->fw_virt = NULL;
wd->params = pci_alloc_consistent(wd->pdev,
sizeof(struct wd719x_host_param),
&wd->params_phys);
if (!wd->params) {
dev_warn(&wd->pdev->dev, "unable to allocate parameter buffer\n");
return -ENOMEM;
}
wd->hash_virt = pci_alloc_consistent(wd->pdev, WD719X_HASH_TABLE_SIZE,
&wd->hash_phys);
if (!wd->hash_virt) {
dev_warn(&wd->pdev->dev, "unable to allocate hash buffer\n");
ret = -ENOMEM;
goto fail_free_params;
}
ret = request_irq(wd->pdev->irq, wd719x_interrupt, IRQF_SHARED,
"wd719x", wd);
if (ret) {
dev_warn(&wd->pdev->dev, "unable to assign IRQ %d\n",
wd->pdev->irq);
goto fail_free_hash;
}
wd719x_read_eeprom(wd);
ret = wd719x_chip_init(wd);
if (ret)
goto fail_free_irq;
sh->this_id = wd->params->own_scsi_id & WD719X_EE_SCSI_ID_MASK;
dev_info(&wd->pdev->dev, "%s at I/O 0x%lx, IRQ %u, SCSI ID %d\n",
card_types[wd->type], sh->base, sh->irq, sh->this_id);
return 0;
fail_free_irq:
free_irq(wd->pdev->irq, wd);
fail_free_hash:
pci_free_consistent(wd->pdev, WD719X_HASH_TABLE_SIZE, wd->hash_virt,
wd->hash_phys);
fail_free_params:
pci_free_consistent(wd->pdev, sizeof(struct wd719x_host_param),
wd->params, wd->params_phys);
return ret;
}
static int wd719x_pci_probe(struct pci_dev *pdev, const struct pci_device_id *d)
{
int err;
struct Scsi_Host *sh;
struct wd719x *wd;
err = pci_enable_device(pdev);
if (err)
goto fail;
if (pci_set_dma_mask(pdev, DMA_BIT_MASK(32))) {
dev_warn(&pdev->dev, "Unable to set 32-bit DMA mask\n");
goto disable_device;
}
err = pci_request_regions(pdev, "wd719x");
if (err)
goto disable_device;
pci_set_master(pdev);
err = -ENODEV;
if (pci_resource_len(pdev, 0) == 0)
goto release_region;
err = -ENOMEM;
sh = scsi_host_alloc(&wd719x_template, sizeof(struct wd719x));
if (!sh)
goto release_region;
wd = shost_priv(sh);
wd->base = pci_iomap(pdev, 0, 0);
if (!wd->base)
goto free_host;
wd->pdev = pdev;
err = wd719x_board_found(sh);
if (err)
goto unmap;
err = scsi_add_host(sh, &wd->pdev->dev);
if (err)
goto destroy;
scsi_scan_host(sh);
pci_set_drvdata(pdev, sh);
return 0;
destroy:
wd719x_destroy(wd);
unmap:
pci_iounmap(pdev, wd->base);
free_host:
scsi_host_put(sh);
release_region:
pci_release_regions(pdev);
disable_device:
pci_disable_device(pdev);
fail:
return err;
}
static void wd719x_pci_remove(struct pci_dev *pdev)
{
struct Scsi_Host *sh = pci_get_drvdata(pdev);
struct wd719x *wd = shost_priv(sh);
scsi_remove_host(sh);
wd719x_destroy(wd);
pci_iounmap(pdev, wd->base);
pci_release_regions(pdev);
pci_disable_device(pdev);
scsi_host_put(sh);
}
static int __init wd719x_init(void)
{
return pci_register_driver(&wd719x_pci_driver);
}
static void __exit wd719x_exit(void)
{
pci_unregister_driver(&wd719x_pci_driver);
}
