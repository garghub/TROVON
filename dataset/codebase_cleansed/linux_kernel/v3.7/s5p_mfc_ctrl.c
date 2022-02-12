int s5p_mfc_alloc_and_load_firmware(struct s5p_mfc_dev *dev)
{
struct firmware *fw_blob;
size_t bank2_base_phys;
void *b_base;
int err;
mfc_debug_enter();
err = request_firmware((const struct firmware **)&fw_blob,
dev->variant->fw_name, dev->v4l2_dev.dev);
if (err != 0) {
mfc_err("Firmware is not present in the /lib/firmware directory nor compiled in kernel\n");
return -EINVAL;
}
dev->fw_size = dev->variant->buf_size->fw;
if (fw_blob->size > dev->fw_size) {
mfc_err("MFC firmware is too big to be loaded\n");
release_firmware(fw_blob);
return -ENOMEM;
}
if (s5p_mfc_bitproc_buf) {
mfc_err("Attempting to allocate firmware when it seems that it is already loaded\n");
release_firmware(fw_blob);
return -ENOMEM;
}
s5p_mfc_bitproc_buf = vb2_dma_contig_memops.alloc(
dev->alloc_ctx[MFC_BANK1_ALLOC_CTX], dev->fw_size);
if (IS_ERR(s5p_mfc_bitproc_buf)) {
s5p_mfc_bitproc_buf = NULL;
mfc_err("Allocating bitprocessor buffer failed\n");
release_firmware(fw_blob);
return -ENOMEM;
}
s5p_mfc_bitproc_phys = s5p_mfc_mem_cookie(
dev->alloc_ctx[MFC_BANK1_ALLOC_CTX], s5p_mfc_bitproc_buf);
if (s5p_mfc_bitproc_phys & ((1 << MFC_BASE_ALIGN_ORDER) - 1)) {
mfc_err("The base memory for bank 1 is not aligned to 128KB\n");
vb2_dma_contig_memops.put(s5p_mfc_bitproc_buf);
s5p_mfc_bitproc_phys = 0;
s5p_mfc_bitproc_buf = NULL;
release_firmware(fw_blob);
return -EIO;
}
s5p_mfc_bitproc_virt = vb2_dma_contig_memops.vaddr(s5p_mfc_bitproc_buf);
if (!s5p_mfc_bitproc_virt) {
mfc_err("Bitprocessor memory remap failed\n");
vb2_dma_contig_memops.put(s5p_mfc_bitproc_buf);
s5p_mfc_bitproc_phys = 0;
s5p_mfc_bitproc_buf = NULL;
release_firmware(fw_blob);
return -EIO;
}
dev->bank1 = s5p_mfc_bitproc_phys;
if (HAS_PORTNUM(dev) && IS_TWOPORT(dev)) {
b_base = vb2_dma_contig_memops.alloc(
dev->alloc_ctx[MFC_BANK2_ALLOC_CTX],
1 << MFC_BASE_ALIGN_ORDER);
if (IS_ERR(b_base)) {
vb2_dma_contig_memops.put(s5p_mfc_bitproc_buf);
s5p_mfc_bitproc_phys = 0;
s5p_mfc_bitproc_buf = NULL;
mfc_err("Allocating bank2 base failed\n");
release_firmware(fw_blob);
return -ENOMEM;
}
bank2_base_phys = s5p_mfc_mem_cookie(
dev->alloc_ctx[MFC_BANK2_ALLOC_CTX], b_base);
vb2_dma_contig_memops.put(b_base);
if (bank2_base_phys & ((1 << MFC_BASE_ALIGN_ORDER) - 1)) {
mfc_err("The base memory for bank 2 is not aligned to 128KB\n");
vb2_dma_contig_memops.put(s5p_mfc_bitproc_buf);
s5p_mfc_bitproc_phys = 0;
s5p_mfc_bitproc_buf = NULL;
release_firmware(fw_blob);
return -EIO;
}
dev->bank2 = bank2_base_phys - (1 << MFC_BASE_ALIGN_ORDER);
} else {
dev->bank2 = dev->bank1;
}
memcpy(s5p_mfc_bitproc_virt, fw_blob->data, fw_blob->size);
wmb();
release_firmware(fw_blob);
mfc_debug_leave();
return 0;
}
int s5p_mfc_reload_firmware(struct s5p_mfc_dev *dev)
{
struct firmware *fw_blob;
int err;
mfc_debug_enter();
err = request_firmware((const struct firmware **)&fw_blob,
dev->variant->fw_name, dev->v4l2_dev.dev);
if (err != 0) {
mfc_err("Firmware is not present in the /lib/firmware directory nor compiled in kernel\n");
return -EINVAL;
}
if (fw_blob->size > dev->fw_size) {
mfc_err("MFC firmware is too big to be loaded\n");
release_firmware(fw_blob);
return -ENOMEM;
}
if (s5p_mfc_bitproc_buf == NULL || s5p_mfc_bitproc_phys == 0) {
mfc_err("MFC firmware is not allocated or was not mapped correctly\n");
release_firmware(fw_blob);
return -EINVAL;
}
memcpy(s5p_mfc_bitproc_virt, fw_blob->data, fw_blob->size);
wmb();
release_firmware(fw_blob);
mfc_debug_leave();
return 0;
}
int s5p_mfc_release_firmware(struct s5p_mfc_dev *dev)
{
if (!s5p_mfc_bitproc_buf)
return -EINVAL;
vb2_dma_contig_memops.put(s5p_mfc_bitproc_buf);
s5p_mfc_bitproc_virt = NULL;
s5p_mfc_bitproc_phys = 0;
s5p_mfc_bitproc_buf = NULL;
return 0;
}
int s5p_mfc_reset(struct s5p_mfc_dev *dev)
{
unsigned int mc_status;
unsigned long timeout;
int i;
mfc_debug_enter();
if (IS_MFCV6(dev)) {
mfc_write(dev, 0xFEE, S5P_FIMV_MFC_RESET_V6);
mfc_write(dev, 0x0, S5P_FIMV_MFC_RESET_V6);
mfc_write(dev, 0, S5P_FIMV_RISC2HOST_CMD_V6);
mfc_write(dev, 0, S5P_FIMV_HOST2RISC_CMD_V6);
mfc_write(dev, 0, S5P_FIMV_FW_VERSION_V6);
for (i = 0; i < S5P_FIMV_REG_CLEAR_COUNT_V6; i++)
mfc_write(dev, 0, S5P_FIMV_REG_CLEAR_BEGIN_V6 + (i*4));
mfc_write(dev, 0, S5P_FIMV_RISC_ON_V6);
mfc_write(dev, 0x1FFF, S5P_FIMV_MFC_RESET_V6);
mfc_write(dev, 0, S5P_FIMV_MFC_RESET_V6);
} else {
mfc_write(dev, 0x3f6, S5P_FIMV_SW_RESET);
mfc_write(dev, 0x3e2, S5P_FIMV_SW_RESET);
mdelay(10);
timeout = jiffies + msecs_to_jiffies(MFC_BW_TIMEOUT);
do {
if (time_after(jiffies, timeout)) {
mfc_err("Timeout while resetting MFC\n");
return -EIO;
}
mc_status = mfc_read(dev, S5P_FIMV_MC_STATUS);
} while (mc_status & 0x3);
mfc_write(dev, 0x0, S5P_FIMV_SW_RESET);
mfc_write(dev, 0x3fe, S5P_FIMV_SW_RESET);
}
mfc_debug_leave();
return 0;
}
static inline void s5p_mfc_init_memctrl(struct s5p_mfc_dev *dev)
{
if (IS_MFCV6(dev)) {
mfc_write(dev, dev->bank1, S5P_FIMV_RISC_BASE_ADDRESS_V6);
mfc_debug(2, "Base Address : %08x\n", dev->bank1);
} else {
mfc_write(dev, dev->bank1, S5P_FIMV_MC_DRAMBASE_ADR_A);
mfc_write(dev, dev->bank2, S5P_FIMV_MC_DRAMBASE_ADR_B);
mfc_debug(2, "Bank1: %08x, Bank2: %08x\n",
dev->bank1, dev->bank2);
}
}
static inline void s5p_mfc_clear_cmds(struct s5p_mfc_dev *dev)
{
if (IS_MFCV6(dev)) {
} else {
mfc_write(dev, 0xffffffff, S5P_FIMV_SI_CH0_INST_ID);
mfc_write(dev, 0xffffffff, S5P_FIMV_SI_CH1_INST_ID);
mfc_write(dev, 0, S5P_FIMV_RISC2HOST_CMD);
mfc_write(dev, 0, S5P_FIMV_HOST2RISC_CMD);
}
}
int s5p_mfc_init_hw(struct s5p_mfc_dev *dev)
{
unsigned int ver;
int ret;
mfc_debug_enter();
if (!s5p_mfc_bitproc_buf)
return -EINVAL;
mfc_debug(2, "MFC reset..\n");
s5p_mfc_clock_on();
ret = s5p_mfc_reset(dev);
if (ret) {
mfc_err("Failed to reset MFC - timeout\n");
return ret;
}
mfc_debug(2, "Done MFC reset..\n");
s5p_mfc_init_memctrl(dev);
s5p_mfc_clear_cmds(dev);
s5p_mfc_clean_dev_int_flags(dev);
if (IS_MFCV6(dev))
mfc_write(dev, 0x1, S5P_FIMV_RISC_ON_V6);
else
mfc_write(dev, 0x3ff, S5P_FIMV_SW_RESET);
mfc_debug(2, "Will now wait for completion of firmware transfer\n");
if (s5p_mfc_wait_for_done_dev(dev, S5P_MFC_R2H_CMD_FW_STATUS_RET)) {
mfc_err("Failed to load firmware\n");
s5p_mfc_reset(dev);
s5p_mfc_clock_off();
return -EIO;
}
s5p_mfc_clean_dev_int_flags(dev);
ret = s5p_mfc_hw_call(dev->mfc_cmds, sys_init_cmd, dev);
if (ret) {
mfc_err("Failed to send command to MFC - timeout\n");
s5p_mfc_reset(dev);
s5p_mfc_clock_off();
return ret;
}
mfc_debug(2, "Ok, now will write a command to init the system\n");
if (s5p_mfc_wait_for_done_dev(dev, S5P_MFC_R2H_CMD_SYS_INIT_RET)) {
mfc_err("Failed to load firmware\n");
s5p_mfc_reset(dev);
s5p_mfc_clock_off();
return -EIO;
}
dev->int_cond = 0;
if (dev->int_err != 0 || dev->int_type !=
S5P_MFC_R2H_CMD_SYS_INIT_RET) {
mfc_err("Failed to init firmware - error: %d int: %d\n",
dev->int_err, dev->int_type);
s5p_mfc_reset(dev);
s5p_mfc_clock_off();
return -EIO;
}
if (IS_MFCV6(dev))
ver = mfc_read(dev, S5P_FIMV_FW_VERSION_V6);
else
ver = mfc_read(dev, S5P_FIMV_FW_VERSION);
mfc_debug(2, "MFC F/W version : %02xyy, %02xmm, %02xdd\n",
(ver >> 16) & 0xFF, (ver >> 8) & 0xFF, ver & 0xFF);
s5p_mfc_clock_off();
mfc_debug_leave();
return 0;
}
void s5p_mfc_deinit_hw(struct s5p_mfc_dev *dev)
{
s5p_mfc_clock_on();
s5p_mfc_reset(dev);
s5p_mfc_hw_call(dev->mfc_ops, release_dev_context_buffer, dev);
s5p_mfc_clock_off();
}
int s5p_mfc_sleep(struct s5p_mfc_dev *dev)
{
int ret;
mfc_debug_enter();
s5p_mfc_clock_on();
s5p_mfc_clean_dev_int_flags(dev);
ret = s5p_mfc_hw_call(dev->mfc_cmds, sleep_cmd, dev);
if (ret) {
mfc_err("Failed to send command to MFC - timeout\n");
return ret;
}
if (s5p_mfc_wait_for_done_dev(dev, S5P_MFC_R2H_CMD_SLEEP_RET)) {
mfc_err("Failed to sleep\n");
return -EIO;
}
s5p_mfc_clock_off();
dev->int_cond = 0;
if (dev->int_err != 0 || dev->int_type !=
S5P_MFC_R2H_CMD_SLEEP_RET) {
mfc_err("Failed to sleep - error: %d int: %d\n", dev->int_err,
dev->int_type);
return -EIO;
}
mfc_debug_leave();
return ret;
}
int s5p_mfc_wakeup(struct s5p_mfc_dev *dev)
{
int ret;
mfc_debug_enter();
mfc_debug(2, "MFC reset..\n");
s5p_mfc_clock_on();
ret = s5p_mfc_reset(dev);
if (ret) {
mfc_err("Failed to reset MFC - timeout\n");
return ret;
}
mfc_debug(2, "Done MFC reset..\n");
s5p_mfc_init_memctrl(dev);
s5p_mfc_clear_cmds(dev);
s5p_mfc_clean_dev_int_flags(dev);
ret = s5p_mfc_hw_call(dev->mfc_cmds, wakeup_cmd, dev);
if (ret) {
mfc_err("Failed to send command to MFC - timeout\n");
return ret;
}
if (IS_MFCV6(dev))
mfc_write(dev, 0x1, S5P_FIMV_RISC_ON_V6);
else
mfc_write(dev, 0x3ff, S5P_FIMV_SW_RESET);
mfc_debug(2, "Ok, now will write a command to wakeup the system\n");
if (s5p_mfc_wait_for_done_dev(dev, S5P_MFC_R2H_CMD_WAKEUP_RET)) {
mfc_err("Failed to load firmware\n");
return -EIO;
}
s5p_mfc_clock_off();
dev->int_cond = 0;
if (dev->int_err != 0 || dev->int_type !=
S5P_MFC_R2H_CMD_WAKEUP_RET) {
mfc_err("Failed to wakeup - error: %d int: %d\n", dev->int_err,
dev->int_type);
return -EIO;
}
mfc_debug_leave();
return 0;
}
