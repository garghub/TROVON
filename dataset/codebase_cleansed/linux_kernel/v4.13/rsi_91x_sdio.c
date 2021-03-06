static u32 rsi_sdio_set_cmd52_arg(bool rw,
u8 func,
u8 raw,
u32 address,
u8 writedata)
{
return ((rw & 1) << 31) | ((func & 0x7) << 28) |
((raw & 1) << 27) | (1 << 26) |
((address & 0x1FFFF) << 9) | (1 << 8) |
(writedata & 0xFF);
}
static int rsi_cmd52writebyte(struct mmc_card *card,
u32 address,
u8 byte)
{
struct mmc_command io_cmd;
u32 arg;
memset(&io_cmd, 0, sizeof(io_cmd));
arg = rsi_sdio_set_cmd52_arg(1, 0, 0, address, byte);
io_cmd.opcode = SD_IO_RW_DIRECT;
io_cmd.arg = arg;
io_cmd.flags = MMC_RSP_R5 | MMC_CMD_AC;
return mmc_wait_for_cmd(card->host, &io_cmd, 0);
}
static int rsi_cmd52readbyte(struct mmc_card *card,
u32 address,
u8 *byte)
{
struct mmc_command io_cmd;
u32 arg;
int err;
memset(&io_cmd, 0, sizeof(io_cmd));
arg = rsi_sdio_set_cmd52_arg(0, 0, 0, address, 0);
io_cmd.opcode = SD_IO_RW_DIRECT;
io_cmd.arg = arg;
io_cmd.flags = MMC_RSP_R5 | MMC_CMD_AC;
err = mmc_wait_for_cmd(card->host, &io_cmd, 0);
if ((!err) && (byte))
*byte = io_cmd.resp[0] & 0xFF;
return err;
}
static int rsi_issue_sdiocommand(struct sdio_func *func,
u32 opcode,
u32 arg,
u32 flags,
u32 *resp)
{
struct mmc_command cmd;
struct mmc_host *host;
int err;
host = func->card->host;
memset(&cmd, 0, sizeof(struct mmc_command));
cmd.opcode = opcode;
cmd.arg = arg;
cmd.flags = flags;
err = mmc_wait_for_cmd(host, &cmd, 3);
if ((!err) && (resp))
*resp = cmd.resp[0];
return err;
}
static void rsi_handle_interrupt(struct sdio_func *function)
{
struct rsi_hw *adapter = sdio_get_drvdata(function);
if (adapter->priv->fsm_state == FSM_FW_NOT_LOADED)
return;
sdio_release_host(function);
rsi_interrupt_handler(adapter);
sdio_claim_host(function);
}
static void rsi_reset_card(struct sdio_func *pfunction)
{
int ret = 0;
int err;
struct mmc_card *card = pfunction->card;
struct mmc_host *host = card->host;
s32 bit = (fls(host->ocr_avail) - 1);
u8 cmd52_resp;
u32 clock, resp, i;
u16 rca;
ret = rsi_cmd52writebyte(pfunction->card,
SDIO_CCCR_ABORT,
(1 << 3));
if (ret != -ETIMEDOUT)
rsi_dbg(ERR_ZONE, "%s: Reset failed : %d\n", __func__, ret);
msleep(20);
host->ios.vdd = bit;
host->ios.chip_select = MMC_CS_DONTCARE;
host->ios.bus_mode = MMC_BUSMODE_OPENDRAIN;
host->ios.power_mode = MMC_POWER_UP;
host->ios.bus_width = MMC_BUS_WIDTH_1;
host->ios.timing = MMC_TIMING_LEGACY;
host->ops->set_ios(host, &host->ios);
msleep(20);
host->ios.clock = host->f_min;
host->ios.power_mode = MMC_POWER_ON;
host->ops->set_ios(host, &host->ios);
msleep(20);
host->ios.chip_select = MMC_CS_HIGH;
host->ops->set_ios(host, &host->ios);
msleep(20);
err = rsi_issue_sdiocommand(pfunction,
MMC_GO_IDLE_STATE,
0,
(MMC_RSP_NONE | MMC_CMD_BC),
NULL);
host->ios.chip_select = MMC_CS_DONTCARE;
host->ops->set_ios(host, &host->ios);
msleep(20);
host->use_spi_crc = 0;
if (err)
rsi_dbg(ERR_ZONE, "%s: CMD0 failed : %d\n", __func__, err);
if (!host->ocr_avail) {
err = rsi_issue_sdiocommand(pfunction,
SD_IO_SEND_OP_COND,
0,
(MMC_RSP_R4 | MMC_CMD_BCR),
&resp);
if (err)
rsi_dbg(ERR_ZONE, "%s: CMD5 failed : %d\n",
__func__, err);
host->ocr_avail = resp;
}
for (i = 0; i < 100; i++) {
err = rsi_issue_sdiocommand(pfunction,
SD_IO_SEND_OP_COND,
host->ocr_avail,
(MMC_RSP_R4 | MMC_CMD_BCR),
&resp);
if (err) {
rsi_dbg(ERR_ZONE, "%s: CMD5 failed : %d\n",
__func__, err);
break;
}
if (resp & MMC_CARD_BUSY)
break;
msleep(20);
}
if ((i == 100) || (err)) {
rsi_dbg(ERR_ZONE, "%s: card in not ready : %d %d\n",
__func__, i, err);
return;
}
err = rsi_issue_sdiocommand(pfunction,
SD_SEND_RELATIVE_ADDR,
0,
(MMC_RSP_R6 | MMC_CMD_BCR),
&resp);
if (err) {
rsi_dbg(ERR_ZONE, "%s: CMD3 failed : %d\n", __func__, err);
return;
}
rca = resp >> 16;
host->ios.bus_mode = MMC_BUSMODE_PUSHPULL;
host->ops->set_ios(host, &host->ios);
err = rsi_issue_sdiocommand(pfunction,
MMC_SELECT_CARD,
(rca << 16),
(MMC_RSP_R1 | MMC_CMD_AC),
NULL);
if (err) {
rsi_dbg(ERR_ZONE, "%s: CMD7 failed : %d\n", __func__, err);
return;
}
if (card->host->caps & MMC_CAP_SD_HIGHSPEED) {
rsi_dbg(ERR_ZONE, "%s: Set high speed mode\n", __func__);
err = rsi_cmd52readbyte(card, SDIO_CCCR_SPEED, &cmd52_resp);
if (err) {
rsi_dbg(ERR_ZONE, "%s: CCCR speed reg read failed: %d\n",
__func__, err);
} else {
err = rsi_cmd52writebyte(card,
SDIO_CCCR_SPEED,
(cmd52_resp | SDIO_SPEED_EHS));
if (err) {
rsi_dbg(ERR_ZONE,
"%s: CCR speed regwrite failed %d\n",
__func__, err);
return;
}
host->ios.timing = MMC_TIMING_SD_HS;
host->ops->set_ios(host, &host->ios);
}
}
if (mmc_card_hs(card))
clock = 50000000;
else
clock = card->cis.max_dtr;
if (clock > host->f_max)
clock = host->f_max;
host->ios.clock = clock;
host->ops->set_ios(host, &host->ios);
if (card->host->caps & MMC_CAP_4_BIT_DATA) {
err = rsi_cmd52writebyte(card,
SDIO_CCCR_IF,
(SDIO_BUS_CD_DISABLE |
SDIO_BUS_WIDTH_4BIT));
if (err) {
rsi_dbg(ERR_ZONE, "%s: Set bus mode failed : %d\n",
__func__, err);
return;
}
host->ios.bus_width = MMC_BUS_WIDTH_4;
host->ops->set_ios(host, &host->ios);
}
}
static void rsi_setclock(struct rsi_hw *adapter, u32 freq)
{
struct rsi_91x_sdiodev *dev =
(struct rsi_91x_sdiodev *)adapter->rsi_dev;
struct mmc_host *host = dev->pfunction->card->host;
u32 clock;
clock = freq * 1000;
if (clock > host->f_max)
clock = host->f_max;
host->ios.clock = clock;
host->ops->set_ios(host, &host->ios);
}
static int rsi_setblocklength(struct rsi_hw *adapter, u32 length)
{
struct rsi_91x_sdiodev *dev =
(struct rsi_91x_sdiodev *)adapter->rsi_dev;
int status;
rsi_dbg(INIT_ZONE, "%s: Setting the block length\n", __func__);
status = sdio_set_block_size(dev->pfunction, length);
dev->pfunction->max_blksize = 256;
adapter->block_size = dev->pfunction->max_blksize;
rsi_dbg(INFO_ZONE,
"%s: Operational blk length is %d\n", __func__, length);
return status;
}
static int rsi_setupcard(struct rsi_hw *adapter)
{
struct rsi_91x_sdiodev *dev =
(struct rsi_91x_sdiodev *)adapter->rsi_dev;
int status = 0;
rsi_setclock(adapter, 50000);
dev->tx_blk_size = 256;
status = rsi_setblocklength(adapter, dev->tx_blk_size);
if (status)
rsi_dbg(ERR_ZONE,
"%s: Unable to set block length\n", __func__);
return status;
}
int rsi_sdio_read_register(struct rsi_hw *adapter,
u32 addr,
u8 *data)
{
struct rsi_91x_sdiodev *dev =
(struct rsi_91x_sdiodev *)adapter->rsi_dev;
u8 fun_num = 0;
int status;
sdio_claim_host(dev->pfunction);
if (fun_num == 0)
*data = sdio_f0_readb(dev->pfunction, addr, &status);
else
*data = sdio_readb(dev->pfunction, addr, &status);
sdio_release_host(dev->pfunction);
return status;
}
int rsi_sdio_write_register(struct rsi_hw *adapter,
u8 function,
u32 addr,
u8 *data)
{
struct rsi_91x_sdiodev *dev =
(struct rsi_91x_sdiodev *)adapter->rsi_dev;
int status = 0;
sdio_claim_host(dev->pfunction);
if (function == 0)
sdio_f0_writeb(dev->pfunction, *data, addr, &status);
else
sdio_writeb(dev->pfunction, *data, addr, &status);
sdio_release_host(dev->pfunction);
return status;
}
void rsi_sdio_ack_intr(struct rsi_hw *adapter, u8 int_bit)
{
int status;
status = rsi_sdio_write_register(adapter,
1,
(SDIO_FUN1_INTR_CLR_REG |
RSI_SD_REQUEST_MASTER),
&int_bit);
if (status)
rsi_dbg(ERR_ZONE, "%s: unable to send ack\n", __func__);
}
static int rsi_sdio_read_register_multiple(struct rsi_hw *adapter,
u32 addr,
u8 *data,
u16 count)
{
struct rsi_91x_sdiodev *dev =
(struct rsi_91x_sdiodev *)adapter->rsi_dev;
u32 status;
sdio_claim_host(dev->pfunction);
status = sdio_readsb(dev->pfunction, data, addr, count);
sdio_release_host(dev->pfunction);
if (status != 0)
rsi_dbg(ERR_ZONE, "%s: Synch Cmd53 read failed\n", __func__);
return status;
}
int rsi_sdio_write_register_multiple(struct rsi_hw *adapter,
u32 addr,
u8 *data,
u16 count)
{
struct rsi_91x_sdiodev *dev =
(struct rsi_91x_sdiodev *)adapter->rsi_dev;
int status;
if (dev->write_fail > 1) {
rsi_dbg(ERR_ZONE, "%s: Stopping card writes\n", __func__);
return 0;
} else if (dev->write_fail == 1) {
rsi_dbg(ERR_ZONE, "%s: Continue card writes\n", __func__);
dev->write_fail++;
}
sdio_claim_host(dev->pfunction);
status = sdio_writesb(dev->pfunction, addr, data, count);
sdio_release_host(dev->pfunction);
if (status) {
rsi_dbg(ERR_ZONE, "%s: Synch Cmd53 write failed %d\n",
__func__, status);
dev->write_fail = 2;
} else {
memcpy(dev->prev_desc, data, FRAME_DESC_SZ);
}
return status;
}
static int rsi_sdio_load_data_master_write(struct rsi_hw *adapter,
u32 base_address,
u32 instructions_sz,
u16 block_size,
u8 *ta_firmware)
{
u32 num_blocks, offset, i;
u16 msb_address, lsb_address;
u8 temp_buf[block_size];
int status;
num_blocks = instructions_sz / block_size;
msb_address = base_address >> 16;
rsi_dbg(INFO_ZONE, "ins_size: %d, num_blocks: %d\n",
instructions_sz, num_blocks);
status = rsi_sdio_master_access_msword(adapter, msb_address);
if (status < 0) {
rsi_dbg(ERR_ZONE, "%s: Unable to set ms word reg\n", __func__);
return status;
}
for (offset = 0, i = 0; i < num_blocks; i++, offset += block_size) {
memset(temp_buf, 0, block_size);
memcpy(temp_buf, ta_firmware + offset, block_size);
lsb_address = (u16)base_address;
status = rsi_sdio_write_register_multiple
(adapter,
lsb_address | RSI_SD_REQUEST_MASTER,
temp_buf, block_size);
if (status < 0) {
rsi_dbg(ERR_ZONE, "%s: failed to write\n", __func__);
return status;
}
rsi_dbg(INFO_ZONE, "%s: loading block: %d\n", __func__, i);
base_address += block_size;
if ((base_address >> 16) != msb_address) {
msb_address += 1;
status = rsi_sdio_master_access_msword(adapter,
msb_address);
if (status < 0) {
rsi_dbg(ERR_ZONE,
"%s: Unable to set ms word reg\n",
__func__);
return status;
}
}
}
if (instructions_sz % block_size) {
memset(temp_buf, 0, block_size);
memcpy(temp_buf, ta_firmware + offset,
instructions_sz % block_size);
lsb_address = (u16)base_address;
status = rsi_sdio_write_register_multiple
(adapter,
lsb_address | RSI_SD_REQUEST_MASTER,
temp_buf,
instructions_sz % block_size);
if (status < 0)
return status;
rsi_dbg(INFO_ZONE,
"Written Last Block in Address 0x%x Successfully\n",
offset | RSI_SD_REQUEST_MASTER);
}
return 0;
}
static int rsi_sdio_master_reg_read(struct rsi_hw *adapter, u32 addr,
u32 *read_buf, u16 size)
{
u32 addr_on_bus, *data;
u32 align[2] = {};
u16 ms_addr;
int status;
data = PTR_ALIGN(&align[0], 8);
ms_addr = (addr >> 16);
status = rsi_sdio_master_access_msword(adapter, ms_addr);
if (status < 0) {
rsi_dbg(ERR_ZONE,
"%s: Unable to set ms word to common reg\n",
__func__);
return status;
}
addr &= 0xFFFF;
addr_on_bus = (addr & 0xFF000000);
if ((addr_on_bus == (FLASH_SIZE_ADDR & 0xFF000000)) ||
(addr_on_bus == 0x0))
addr_on_bus = (addr & ~(0x3));
else
addr_on_bus = addr;
status = rsi_sdio_read_register_multiple
(adapter,
(addr_on_bus | RSI_SD_REQUEST_MASTER),
(u8 *)data, 4);
if (status < 0) {
rsi_dbg(ERR_ZONE, "%s: AHB register read failed\n", __func__);
return status;
}
if (size == 2) {
if ((addr & 0x3) == 0)
*read_buf = *data;
else
*read_buf = (*data >> 16);
*read_buf = (*read_buf & 0xFFFF);
} else if (size == 1) {
if ((addr & 0x3) == 0)
*read_buf = *data;
else if ((addr & 0x3) == 1)
*read_buf = (*data >> 8);
else if ((addr & 0x3) == 2)
*read_buf = (*data >> 16);
else
*read_buf = (*data >> 24);
*read_buf = (*read_buf & 0xFF);
} else {
*read_buf = *data;
}
return 0;
}
static int rsi_sdio_master_reg_write(struct rsi_hw *adapter,
unsigned long addr,
unsigned long data, u16 size)
{
unsigned long data1[2], *data_aligned;
int status;
data_aligned = PTR_ALIGN(&data1[0], 8);
if (size == 2) {
*data_aligned = ((data << 16) | (data & 0xFFFF));
} else if (size == 1) {
u32 temp_data = data & 0xFF;
*data_aligned = ((temp_data << 24) | (temp_data << 16) |
(temp_data << 8) | temp_data);
} else {
*data_aligned = data;
}
size = 4;
status = rsi_sdio_master_access_msword(adapter, (addr >> 16));
if (status < 0) {
rsi_dbg(ERR_ZONE,
"%s: Unable to set ms word to common reg\n",
__func__);
return -EIO;
}
addr = addr & 0xFFFF;
status = rsi_sdio_write_register_multiple
(adapter,
(addr | RSI_SD_REQUEST_MASTER),
(u8 *)data_aligned, size);
if (status < 0) {
rsi_dbg(ERR_ZONE,
"%s: Unable to do AHB reg write\n", __func__);
return status;
}
return 0;
}
static int rsi_sdio_host_intf_write_pkt(struct rsi_hw *adapter,
u8 *pkt,
u32 len)
{
struct rsi_91x_sdiodev *dev =
(struct rsi_91x_sdiodev *)adapter->rsi_dev;
u32 block_size = dev->tx_blk_size;
u32 num_blocks, address, length;
u32 queueno;
int status;
queueno = ((pkt[1] >> 4) & 0xf);
num_blocks = len / block_size;
if (len % block_size)
num_blocks++;
address = (num_blocks * block_size | (queueno << 12));
length = num_blocks * block_size;
status = rsi_sdio_write_register_multiple(adapter,
address,
(u8 *)pkt,
length);
if (status)
rsi_dbg(ERR_ZONE, "%s: Unable to write onto the card: %d\n",
__func__, status);
rsi_dbg(DATA_TX_ZONE, "%s: Successfully written onto card\n", __func__);
return status;
}
int rsi_sdio_host_intf_read_pkt(struct rsi_hw *adapter,
u8 *pkt,
u32 length)
{
int status = -EINVAL;
if (!length) {
rsi_dbg(ERR_ZONE, "%s: Pkt size is zero\n", __func__);
return status;
}
status = rsi_sdio_read_register_multiple(adapter,
length,
(u8 *)pkt,
length);
if (status)
rsi_dbg(ERR_ZONE, "%s: Failed to read frame: %d\n", __func__,
status);
return status;
}
static int rsi_init_sdio_interface(struct rsi_hw *adapter,
struct sdio_func *pfunction)
{
struct rsi_91x_sdiodev *rsi_91x_dev;
int status = -ENOMEM;
rsi_91x_dev = kzalloc(sizeof(*rsi_91x_dev), GFP_KERNEL);
if (!rsi_91x_dev)
return status;
adapter->rsi_dev = rsi_91x_dev;
sdio_claim_host(pfunction);
pfunction->enable_timeout = 100;
status = sdio_enable_func(pfunction);
if (status) {
rsi_dbg(ERR_ZONE, "%s: Failed to enable interface\n", __func__);
sdio_release_host(pfunction);
return status;
}
rsi_dbg(INIT_ZONE, "%s: Enabled the interface\n", __func__);
rsi_91x_dev->pfunction = pfunction;
adapter->device = &pfunction->dev;
sdio_set_drvdata(pfunction, adapter);
status = rsi_setupcard(adapter);
if (status) {
rsi_dbg(ERR_ZONE, "%s: Failed to setup card\n", __func__);
goto fail;
}
rsi_dbg(INIT_ZONE, "%s: Setup card succesfully\n", __func__);
status = rsi_init_sdio_slave_regs(adapter);
if (status) {
rsi_dbg(ERR_ZONE, "%s: Failed to init slave regs\n", __func__);
goto fail;
}
sdio_release_host(pfunction);
adapter->determine_event_timeout = rsi_sdio_determine_event_timeout;
adapter->check_hw_queue_status = rsi_sdio_read_buffer_status_register;
#ifdef CONFIG_RSI_DEBUGFS
adapter->num_debugfs_entries = MAX_DEBUGFS_ENTRIES;
#endif
return status;
fail:
sdio_disable_func(pfunction);
sdio_release_host(pfunction);
return status;
}
static int rsi_probe(struct sdio_func *pfunction,
const struct sdio_device_id *id)
{
struct rsi_hw *adapter;
rsi_dbg(INIT_ZONE, "%s: Init function called\n", __func__);
adapter = rsi_91x_init();
if (!adapter) {
rsi_dbg(ERR_ZONE, "%s: Failed to init os intf ops\n",
__func__);
return 1;
}
adapter->rsi_host_intf = RSI_HOST_INTF_SDIO;
adapter->host_intf_ops = &sdio_host_intf_ops;
if (rsi_init_sdio_interface(adapter, pfunction)) {
rsi_dbg(ERR_ZONE, "%s: Failed to init sdio interface\n",
__func__);
goto fail;
}
sdio_claim_host(pfunction);
if (sdio_claim_irq(pfunction, rsi_handle_interrupt)) {
rsi_dbg(ERR_ZONE, "%s: Failed to request IRQ\n", __func__);
sdio_release_host(pfunction);
goto fail;
}
sdio_release_host(pfunction);
rsi_dbg(INIT_ZONE, "%s: Registered Interrupt handler\n", __func__);
if (rsi_hal_device_init(adapter)) {
rsi_dbg(ERR_ZONE, "%s: Failed in device init\n", __func__);
sdio_claim_host(pfunction);
sdio_release_irq(pfunction);
sdio_disable_func(pfunction);
sdio_release_host(pfunction);
goto fail;
}
rsi_dbg(INFO_ZONE, "===> RSI Device Init Done <===\n");
if (rsi_sdio_master_access_msword(adapter, MISC_CFG_BASE_ADDR)) {
rsi_dbg(ERR_ZONE, "%s: Unable to set ms word reg\n", __func__);
return -EIO;
}
return 0;
fail:
rsi_91x_deinit(adapter);
rsi_dbg(ERR_ZONE, "%s: Failed in probe...Exiting\n", __func__);
return 1;
}
static void rsi_disconnect(struct sdio_func *pfunction)
{
struct rsi_hw *adapter = sdio_get_drvdata(pfunction);
struct rsi_91x_sdiodev *dev;
if (!adapter)
return;
dev = (struct rsi_91x_sdiodev *)adapter->rsi_dev;
dev->write_fail = 2;
rsi_mac80211_detach(adapter);
sdio_claim_host(pfunction);
sdio_release_irq(pfunction);
sdio_disable_func(pfunction);
rsi_91x_deinit(adapter);
rsi_reset_card(pfunction);
sdio_release_host(pfunction);
}
static int rsi_suspend(struct device *dev)
{
return -ENOSYS;
}
static int rsi_resume(struct device *dev)
{
return -ENOSYS;
}
static int rsi_module_init(void)
{
int ret;
ret = sdio_register_driver(&rsi_driver);
rsi_dbg(INIT_ZONE, "%s: Registering driver\n", __func__);
return ret;
}
static void rsi_module_exit(void)
{
sdio_unregister_driver(&rsi_driver);
rsi_dbg(INFO_ZONE, "%s: Unregistering driver\n", __func__);
}
