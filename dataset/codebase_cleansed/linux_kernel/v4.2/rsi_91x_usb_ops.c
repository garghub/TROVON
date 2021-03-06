static int rsi_copy_to_card(struct rsi_common *common,
const u8 *fw,
u32 len,
u32 num_blocks)
{
struct rsi_hw *adapter = common->priv;
struct rsi_91x_usbdev *dev = (struct rsi_91x_usbdev *)adapter->rsi_dev;
u32 indx, ii;
u32 block_size = dev->tx_blk_size;
u32 lsb_address;
u32 base_address;
base_address = TA_LOAD_ADDRESS;
for (indx = 0, ii = 0; ii < num_blocks; ii++, indx += block_size) {
lsb_address = base_address;
if (rsi_usb_write_register_multiple(adapter,
lsb_address,
(u8 *)(fw + indx),
block_size)) {
rsi_dbg(ERR_ZONE,
"%s: Unable to load %s blk\n", __func__,
FIRMWARE_RSI9113);
return -EIO;
}
rsi_dbg(INIT_ZONE, "%s: loading block: %d\n", __func__, ii);
base_address += block_size;
}
if (len % block_size) {
lsb_address = base_address;
if (rsi_usb_write_register_multiple(adapter,
lsb_address,
(u8 *)(fw + indx),
len % block_size)) {
rsi_dbg(ERR_ZONE,
"%s: Unable to load %s blk\n", __func__,
FIRMWARE_RSI9113);
return -EIO;
}
}
rsi_dbg(INIT_ZONE,
"%s: Succesfully loaded %s instructions\n", __func__,
FIRMWARE_RSI9113);
rsi_dbg(INIT_ZONE, "%s: loaded firmware\n", __func__);
return 0;
}
void rsi_usb_rx_thread(struct rsi_common *common)
{
struct rsi_hw *adapter = common->priv;
struct rsi_91x_usbdev *dev = (struct rsi_91x_usbdev *)adapter->rsi_dev;
int status;
do {
rsi_wait_event(&dev->rx_thread.event, EVENT_WAIT_FOREVER);
if (atomic_read(&dev->rx_thread.thread_done))
goto out;
mutex_lock(&common->tx_rxlock);
status = rsi_read_pkt(common, 0);
if (status) {
rsi_dbg(ERR_ZONE, "%s: Failed To read data", __func__);
mutex_unlock(&common->tx_rxlock);
return;
}
mutex_unlock(&common->tx_rxlock);
rsi_reset_event(&dev->rx_thread.event);
if (adapter->rx_urb_submit(adapter)) {
rsi_dbg(ERR_ZONE,
"%s: Failed in urb submission", __func__);
return;
}
} while (1);
out:
rsi_dbg(INFO_ZONE, "%s: Terminated thread\n", __func__);
complete_and_exit(&dev->rx_thread.completion, 0);
}
static int rsi_load_ta_instructions(struct rsi_common *common)
{
struct rsi_hw *adapter = common->priv;
struct rsi_91x_usbdev *dev = (struct rsi_91x_usbdev *)adapter->rsi_dev;
const struct firmware *fw_entry = NULL;
u32 block_size = dev->tx_blk_size;
const u8 *fw;
u32 num_blocks, len;
int status = 0;
status = request_firmware(&fw_entry, FIRMWARE_RSI9113, adapter->device);
if (status < 0) {
rsi_dbg(ERR_ZONE, "%s Firmware file %s not found\n",
__func__, FIRMWARE_RSI9113);
return status;
}
fw = kmemdup(fw_entry->data, fw_entry->size, GFP_KERNEL);
if (!fw)
return -ENOMEM;
len = fw_entry->size;
if (len % 4)
len += (4 - (len % 4));
num_blocks = (len / block_size);
rsi_dbg(INIT_ZONE, "%s: Instruction size:%d\n", __func__, len);
rsi_dbg(INIT_ZONE, "%s: num blocks: %d\n", __func__, num_blocks);
status = rsi_copy_to_card(common, fw, len, num_blocks);
kfree(fw);
release_firmware(fw_entry);
return status;
}
int rsi_usb_device_init(struct rsi_common *common)
{
if (rsi_load_ta_instructions(common))
return -EIO;
return 0;
}
