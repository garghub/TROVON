static inline void put_be32(__be32 val, __be32 __iomem * p)
{
__raw_writel((__force __u32) val, (__force void __iomem *)p);
}
static void set_fw_name(struct myri10ge_priv *mgp, char *name, bool allocated)
{
if (mgp->fw_name_allocated)
kfree(mgp->fw_name);
mgp->fw_name = name;
mgp->fw_name_allocated = allocated;
}
static int
myri10ge_send_cmd(struct myri10ge_priv *mgp, u32 cmd,
struct myri10ge_cmd *data, int atomic)
{
struct mcp_cmd *buf;
char buf_bytes[sizeof(*buf) + 8];
struct mcp_cmd_response *response = mgp->cmd;
char __iomem *cmd_addr = mgp->sram + MXGEFW_ETH_CMD;
u32 dma_low, dma_high, result, value;
int sleep_total = 0;
buf = (struct mcp_cmd *)ALIGN((unsigned long)buf_bytes, 8);
buf->data0 = htonl(data->data0);
buf->data1 = htonl(data->data1);
buf->data2 = htonl(data->data2);
buf->cmd = htonl(cmd);
dma_low = MYRI10GE_LOWPART_TO_U32(mgp->cmd_bus);
dma_high = MYRI10GE_HIGHPART_TO_U32(mgp->cmd_bus);
buf->response_addr.low = htonl(dma_low);
buf->response_addr.high = htonl(dma_high);
response->result = htonl(MYRI10GE_NO_RESPONSE_RESULT);
mb();
myri10ge_pio_copy(cmd_addr, buf, sizeof(*buf));
if (atomic) {
for (sleep_total = 0;
sleep_total < 1000 &&
response->result == htonl(MYRI10GE_NO_RESPONSE_RESULT);
sleep_total += 10) {
udelay(10);
mb();
}
} else {
for (sleep_total = 0;
sleep_total < 15 &&
response->result == htonl(MYRI10GE_NO_RESPONSE_RESULT);
sleep_total++)
msleep(1);
}
result = ntohl(response->result);
value = ntohl(response->data);
if (result != MYRI10GE_NO_RESPONSE_RESULT) {
if (result == 0) {
data->data0 = value;
return 0;
} else if (result == MXGEFW_CMD_UNKNOWN) {
return -ENOSYS;
} else if (result == MXGEFW_CMD_ERROR_UNALIGNED) {
return -E2BIG;
} else if (result == MXGEFW_CMD_ERROR_RANGE &&
cmd == MXGEFW_CMD_ENABLE_RSS_QUEUES &&
(data->
data1 & MXGEFW_SLICE_ENABLE_MULTIPLE_TX_QUEUES) !=
0) {
return -ERANGE;
} else {
dev_err(&mgp->pdev->dev,
"command %d failed, result = %d\n",
cmd, result);
return -ENXIO;
}
}
dev_err(&mgp->pdev->dev, "command %d timed out, result = %d\n",
cmd, result);
return -EAGAIN;
}
static int myri10ge_read_mac_addr(struct myri10ge_priv *mgp)
{
char *ptr, *limit;
int i;
ptr = mgp->eeprom_strings;
limit = mgp->eeprom_strings + MYRI10GE_EEPROM_STRINGS_SIZE;
while (*ptr != '\0' && ptr < limit) {
if (memcmp(ptr, "MAC=", 4) == 0) {
ptr += 4;
mgp->mac_addr_string = ptr;
for (i = 0; i < 6; i++) {
if ((ptr + 2) > limit)
goto abort;
mgp->mac_addr[i] =
simple_strtoul(ptr, &ptr, 16);
ptr += 1;
}
}
if (memcmp(ptr, "PC=", 3) == 0) {
ptr += 3;
mgp->product_code_string = ptr;
}
if (memcmp((const void *)ptr, "SN=", 3) == 0) {
ptr += 3;
mgp->serial_number = simple_strtoul(ptr, &ptr, 10);
}
while (ptr < limit && *ptr++) ;
}
return 0;
abort:
dev_err(&mgp->pdev->dev, "failed to parse eeprom_strings\n");
return -ENXIO;
}
static void myri10ge_dummy_rdma(struct myri10ge_priv *mgp, int enable)
{
char __iomem *submit;
__be32 buf[16] __attribute__ ((__aligned__(8)));
u32 dma_low, dma_high;
int i;
mgp->cmd->data = 0;
mb();
dma_low = MYRI10GE_LOWPART_TO_U32(mgp->cmd_bus);
dma_high = MYRI10GE_HIGHPART_TO_U32(mgp->cmd_bus);
buf[0] = htonl(dma_high);
buf[1] = htonl(dma_low);
buf[2] = MYRI10GE_NO_CONFIRM_DATA;
buf[3] = htonl(dma_high);
buf[4] = htonl(dma_low);
buf[5] = htonl(enable);
submit = mgp->sram + MXGEFW_BOOT_DUMMY_RDMA;
myri10ge_pio_copy(submit, &buf, sizeof(buf));
for (i = 0; mgp->cmd->data != MYRI10GE_NO_CONFIRM_DATA && i < 20; i++)
msleep(1);
if (mgp->cmd->data != MYRI10GE_NO_CONFIRM_DATA)
dev_err(&mgp->pdev->dev, "dummy rdma %s failed\n",
(enable ? "enable" : "disable"));
}
static int
myri10ge_validate_firmware(struct myri10ge_priv *mgp,
struct mcp_gen_header *hdr)
{
struct device *dev = &mgp->pdev->dev;
if (ntohl(hdr->mcp_type) != MCP_TYPE_ETH) {
dev_err(dev, "Bad firmware type: 0x%x\n", ntohl(hdr->mcp_type));
return -EINVAL;
}
strncpy(mgp->fw_version, hdr->version, sizeof(mgp->fw_version));
sscanf(mgp->fw_version, "%d.%d.%d", &mgp->fw_ver_major,
&mgp->fw_ver_minor, &mgp->fw_ver_tiny);
if (!(mgp->fw_ver_major == MXGEFW_VERSION_MAJOR &&
mgp->fw_ver_minor == MXGEFW_VERSION_MINOR)) {
dev_err(dev, "Found firmware version %s\n", mgp->fw_version);
dev_err(dev, "Driver needs %d.%d\n", MXGEFW_VERSION_MAJOR,
MXGEFW_VERSION_MINOR);
return -EINVAL;
}
return 0;
}
static int myri10ge_load_hotplug_firmware(struct myri10ge_priv *mgp, u32 * size)
{
unsigned crc, reread_crc;
const struct firmware *fw;
struct device *dev = &mgp->pdev->dev;
unsigned char *fw_readback;
struct mcp_gen_header *hdr;
size_t hdr_offset;
int status;
unsigned i;
if ((status = request_firmware(&fw, mgp->fw_name, dev)) < 0) {
dev_err(dev, "Unable to load %s firmware image via hotplug\n",
mgp->fw_name);
status = -EINVAL;
goto abort_with_nothing;
}
if (fw->size >= mgp->sram_size - MYRI10GE_FW_OFFSET ||
fw->size < MCP_HEADER_PTR_OFFSET + 4) {
dev_err(dev, "Firmware size invalid:%d\n", (int)fw->size);
status = -EINVAL;
goto abort_with_fw;
}
hdr_offset = ntohl(*(__be32 *) (fw->data + MCP_HEADER_PTR_OFFSET));
if ((hdr_offset & 3) || hdr_offset + sizeof(*hdr) > fw->size) {
dev_err(dev, "Bad firmware file\n");
status = -EINVAL;
goto abort_with_fw;
}
hdr = (void *)(fw->data + hdr_offset);
status = myri10ge_validate_firmware(mgp, hdr);
if (status != 0)
goto abort_with_fw;
crc = crc32(~0, fw->data, fw->size);
for (i = 0; i < fw->size; i += 256) {
myri10ge_pio_copy(mgp->sram + MYRI10GE_FW_OFFSET + i,
fw->data + i,
min(256U, (unsigned)(fw->size - i)));
mb();
readb(mgp->sram);
}
fw_readback = vmalloc(fw->size);
if (!fw_readback) {
status = -ENOMEM;
goto abort_with_fw;
}
memcpy_fromio(fw_readback, mgp->sram + MYRI10GE_FW_OFFSET, fw->size);
reread_crc = crc32(~0, fw_readback, fw->size);
vfree(fw_readback);
if (crc != reread_crc) {
dev_err(dev, "CRC failed(fw-len=%u), got 0x%x (expect 0x%x)\n",
(unsigned)fw->size, reread_crc, crc);
status = -EIO;
goto abort_with_fw;
}
*size = (u32) fw->size;
abort_with_fw:
release_firmware(fw);
abort_with_nothing:
return status;
}
static int myri10ge_adopt_running_firmware(struct myri10ge_priv *mgp)
{
struct mcp_gen_header *hdr;
struct device *dev = &mgp->pdev->dev;
const size_t bytes = sizeof(struct mcp_gen_header);
size_t hdr_offset;
int status;
hdr_offset = swab32(readl(mgp->sram + MCP_HEADER_PTR_OFFSET));
if ((hdr_offset & 3) || hdr_offset + sizeof(*hdr) > mgp->sram_size) {
dev_err(dev, "Running firmware has bad header offset (%d)\n",
(int)hdr_offset);
return -EIO;
}
hdr = kmalloc(bytes, GFP_KERNEL);
if (hdr == NULL)
return -ENOMEM;
memcpy_fromio(hdr, mgp->sram + hdr_offset, bytes);
status = myri10ge_validate_firmware(mgp, hdr);
kfree(hdr);
if (mgp->fw_ver_major == 1 && mgp->fw_ver_minor == 4 &&
mgp->fw_ver_tiny >= 4 && mgp->fw_ver_tiny <= 11) {
mgp->adopted_rx_filter_bug = 1;
dev_warn(dev, "Adopting fw %d.%d.%d: "
"working around rx filter bug\n",
mgp->fw_ver_major, mgp->fw_ver_minor,
mgp->fw_ver_tiny);
}
return status;
}
static int myri10ge_get_firmware_capabilities(struct myri10ge_priv *mgp)
{
struct myri10ge_cmd cmd;
int status;
mgp->features = NETIF_F_SG | NETIF_F_HW_CSUM | NETIF_F_TSO;
status = myri10ge_send_cmd(mgp, MXGEFW_CMD_GET_MAX_TSO6_HDR_SIZE,
&cmd, 0);
if (status == 0) {
mgp->max_tso6 = cmd.data0;
mgp->features |= NETIF_F_TSO6;
}
status = myri10ge_send_cmd(mgp, MXGEFW_CMD_GET_RX_RING_SIZE, &cmd, 0);
if (status != 0) {
dev_err(&mgp->pdev->dev,
"failed MXGEFW_CMD_GET_RX_RING_SIZE\n");
return -ENXIO;
}
mgp->max_intr_slots = 2 * (cmd.data0 / sizeof(struct mcp_dma_addr));
return 0;
}
static int myri10ge_load_firmware(struct myri10ge_priv *mgp, int adopt)
{
char __iomem *submit;
__be32 buf[16] __attribute__ ((__aligned__(8)));
u32 dma_low, dma_high, size;
int status, i;
size = 0;
status = myri10ge_load_hotplug_firmware(mgp, &size);
if (status) {
if (!adopt)
return status;
dev_warn(&mgp->pdev->dev, "hotplug firmware loading failed\n");
if (status == -EIO)
return status;
status = myri10ge_adopt_running_firmware(mgp);
if (status != 0) {
dev_err(&mgp->pdev->dev,
"failed to adopt running firmware\n");
return status;
}
dev_info(&mgp->pdev->dev,
"Successfully adopted running firmware\n");
if (mgp->tx_boundary == 4096) {
dev_warn(&mgp->pdev->dev,
"Using firmware currently running on NIC"
". For optimal\n");
dev_warn(&mgp->pdev->dev,
"performance consider loading optimized "
"firmware\n");
dev_warn(&mgp->pdev->dev, "via hotplug\n");
}
set_fw_name(mgp, "adopted", false);
mgp->tx_boundary = 2048;
myri10ge_dummy_rdma(mgp, 1);
status = myri10ge_get_firmware_capabilities(mgp);
return status;
}
mgp->cmd->data = 0;
mb();
dma_low = MYRI10GE_LOWPART_TO_U32(mgp->cmd_bus);
dma_high = MYRI10GE_HIGHPART_TO_U32(mgp->cmd_bus);
buf[0] = htonl(dma_high);
buf[1] = htonl(dma_low);
buf[2] = MYRI10GE_NO_CONFIRM_DATA;
buf[3] = htonl(MYRI10GE_FW_OFFSET + 8);
buf[4] = htonl(size - 8);
buf[5] = htonl(8);
buf[6] = htonl(0);
submit = mgp->sram + MXGEFW_BOOT_HANDOFF;
myri10ge_pio_copy(submit, &buf, sizeof(buf));
mb();
msleep(1);
mb();
i = 0;
while (mgp->cmd->data != MYRI10GE_NO_CONFIRM_DATA && i < 9) {
msleep(1 << i);
i++;
}
if (mgp->cmd->data != MYRI10GE_NO_CONFIRM_DATA) {
dev_err(&mgp->pdev->dev, "handoff failed\n");
return -ENXIO;
}
myri10ge_dummy_rdma(mgp, 1);
status = myri10ge_get_firmware_capabilities(mgp);
return status;
}
static int myri10ge_update_mac_address(struct myri10ge_priv *mgp, u8 * addr)
{
struct myri10ge_cmd cmd;
int status;
cmd.data0 = ((addr[0] << 24) | (addr[1] << 16)
| (addr[2] << 8) | addr[3]);
cmd.data1 = ((addr[4] << 8) | (addr[5]));
status = myri10ge_send_cmd(mgp, MXGEFW_SET_MAC_ADDRESS, &cmd, 0);
return status;
}
static int myri10ge_change_pause(struct myri10ge_priv *mgp, int pause)
{
struct myri10ge_cmd cmd;
int status, ctl;
ctl = pause ? MXGEFW_ENABLE_FLOW_CONTROL : MXGEFW_DISABLE_FLOW_CONTROL;
status = myri10ge_send_cmd(mgp, ctl, &cmd, 0);
if (status) {
netdev_err(mgp->dev, "Failed to set flow control mode\n");
return status;
}
mgp->pause = pause;
return 0;
}
static void
myri10ge_change_promisc(struct myri10ge_priv *mgp, int promisc, int atomic)
{
struct myri10ge_cmd cmd;
int status, ctl;
ctl = promisc ? MXGEFW_ENABLE_PROMISC : MXGEFW_DISABLE_PROMISC;
status = myri10ge_send_cmd(mgp, ctl, &cmd, atomic);
if (status)
netdev_err(mgp->dev, "Failed to set promisc mode\n");
}
static int myri10ge_dma_test(struct myri10ge_priv *mgp, int test_type)
{
struct myri10ge_cmd cmd;
int status;
u32 len;
struct page *dmatest_page;
dma_addr_t dmatest_bus;
char *test = " ";
dmatest_page = alloc_page(GFP_KERNEL);
if (!dmatest_page)
return -ENOMEM;
dmatest_bus = pci_map_page(mgp->pdev, dmatest_page, 0, PAGE_SIZE,
DMA_BIDIRECTIONAL);
len = mgp->tx_boundary;
cmd.data0 = MYRI10GE_LOWPART_TO_U32(dmatest_bus);
cmd.data1 = MYRI10GE_HIGHPART_TO_U32(dmatest_bus);
cmd.data2 = len * 0x10000;
status = myri10ge_send_cmd(mgp, test_type, &cmd, 0);
if (status != 0) {
test = "read";
goto abort;
}
mgp->read_dma = ((cmd.data0 >> 16) * len * 2) / (cmd.data0 & 0xffff);
cmd.data0 = MYRI10GE_LOWPART_TO_U32(dmatest_bus);
cmd.data1 = MYRI10GE_HIGHPART_TO_U32(dmatest_bus);
cmd.data2 = len * 0x1;
status = myri10ge_send_cmd(mgp, test_type, &cmd, 0);
if (status != 0) {
test = "write";
goto abort;
}
mgp->write_dma = ((cmd.data0 >> 16) * len * 2) / (cmd.data0 & 0xffff);
cmd.data0 = MYRI10GE_LOWPART_TO_U32(dmatest_bus);
cmd.data1 = MYRI10GE_HIGHPART_TO_U32(dmatest_bus);
cmd.data2 = len * 0x10001;
status = myri10ge_send_cmd(mgp, test_type, &cmd, 0);
if (status != 0) {
test = "read/write";
goto abort;
}
mgp->read_write_dma = ((cmd.data0 >> 16) * len * 2 * 2) /
(cmd.data0 & 0xffff);
abort:
pci_unmap_page(mgp->pdev, dmatest_bus, PAGE_SIZE, DMA_BIDIRECTIONAL);
put_page(dmatest_page);
if (status != 0 && test_type != MXGEFW_CMD_UNALIGNED_TEST)
dev_warn(&mgp->pdev->dev, "DMA %s benchmark failed: %d\n",
test, status);
return status;
}
static inline void myri10ge_ss_init_lock(struct myri10ge_slice_state *ss)
{
spin_lock_init(&ss->lock);
ss->state = SLICE_STATE_IDLE;
}
static inline bool myri10ge_ss_lock_napi(struct myri10ge_slice_state *ss)
{
bool rc = true;
spin_lock(&ss->lock);
if ((ss->state & SLICE_LOCKED)) {
WARN_ON((ss->state & SLICE_STATE_NAPI));
ss->state |= SLICE_STATE_NAPI_YIELD;
rc = false;
ss->lock_napi_yield++;
} else
ss->state = SLICE_STATE_NAPI;
spin_unlock(&ss->lock);
return rc;
}
static inline void myri10ge_ss_unlock_napi(struct myri10ge_slice_state *ss)
{
spin_lock(&ss->lock);
WARN_ON((ss->state & (SLICE_STATE_POLL | SLICE_STATE_NAPI_YIELD)));
ss->state = SLICE_STATE_IDLE;
spin_unlock(&ss->lock);
}
static inline bool myri10ge_ss_lock_poll(struct myri10ge_slice_state *ss)
{
bool rc = true;
spin_lock_bh(&ss->lock);
if ((ss->state & SLICE_LOCKED)) {
ss->state |= SLICE_STATE_POLL_YIELD;
rc = false;
ss->lock_poll_yield++;
} else
ss->state |= SLICE_STATE_POLL;
spin_unlock_bh(&ss->lock);
return rc;
}
static inline void myri10ge_ss_unlock_poll(struct myri10ge_slice_state *ss)
{
spin_lock_bh(&ss->lock);
WARN_ON((ss->state & SLICE_STATE_NAPI));
ss->state = SLICE_STATE_IDLE;
spin_unlock_bh(&ss->lock);
}
static inline bool myri10ge_ss_busy_polling(struct myri10ge_slice_state *ss)
{
WARN_ON(!(ss->state & SLICE_LOCKED));
return (ss->state & SLICE_USER_PEND);
}
static inline void myri10ge_ss_init_lock(struct myri10ge_slice_state *ss)
{
}
static inline bool myri10ge_ss_lock_napi(struct myri10ge_slice_state *ss)
{
return false;
}
static inline void myri10ge_ss_unlock_napi(struct myri10ge_slice_state *ss)
{
}
static inline bool myri10ge_ss_lock_poll(struct myri10ge_slice_state *ss)
{
return false;
}
static inline void myri10ge_ss_unlock_poll(struct myri10ge_slice_state *ss)
{
}
static inline bool myri10ge_ss_busy_polling(struct myri10ge_slice_state *ss)
{
return false;
}
static int myri10ge_reset(struct myri10ge_priv *mgp)
{
struct myri10ge_cmd cmd;
struct myri10ge_slice_state *ss;
int i, status;
size_t bytes;
#ifdef CONFIG_MYRI10GE_DCA
unsigned long dca_tag_off;
#endif
memset(&cmd, 0, sizeof(cmd));
status = myri10ge_send_cmd(mgp, MXGEFW_CMD_RESET, &cmd, 0);
if (status != 0) {
dev_err(&mgp->pdev->dev, "failed reset\n");
return -ENXIO;
}
(void)myri10ge_dma_test(mgp, MXGEFW_DMA_TEST);
cmd.data0 = MXGEFW_RSS_MCP_SLOT_TYPE_MIN;
(void)myri10ge_send_cmd(mgp, MXGEFW_CMD_SET_RSS_MCP_SLOT_TYPE, &cmd, 0);
bytes = mgp->max_intr_slots * sizeof(*mgp->ss[0].rx_done.entry);
cmd.data0 = (u32) bytes;
status = myri10ge_send_cmd(mgp, MXGEFW_CMD_SET_INTRQ_SIZE, &cmd, 0);
if (mgp->num_slices > 1) {
status = myri10ge_send_cmd(mgp, MXGEFW_CMD_GET_MAX_RSS_QUEUES,
&cmd, 0);
if (status != 0) {
dev_err(&mgp->pdev->dev,
"failed to get number of slices\n");
}
cmd.data0 = mgp->num_slices;
cmd.data1 = MXGEFW_SLICE_INTR_MODE_ONE_PER_SLICE;
if (mgp->dev->real_num_tx_queues > 1)
cmd.data1 |= MXGEFW_SLICE_ENABLE_MULTIPLE_TX_QUEUES;
status = myri10ge_send_cmd(mgp, MXGEFW_CMD_ENABLE_RSS_QUEUES,
&cmd, 0);
if (status != 0 && mgp->dev->real_num_tx_queues > 1) {
netif_set_real_num_tx_queues(mgp->dev, 1);
cmd.data0 = mgp->num_slices;
cmd.data1 = MXGEFW_SLICE_INTR_MODE_ONE_PER_SLICE;
status = myri10ge_send_cmd(mgp,
MXGEFW_CMD_ENABLE_RSS_QUEUES,
&cmd, 0);
}
if (status != 0) {
dev_err(&mgp->pdev->dev,
"failed to set number of slices\n");
return status;
}
}
for (i = 0; i < mgp->num_slices; i++) {
ss = &mgp->ss[i];
cmd.data0 = MYRI10GE_LOWPART_TO_U32(ss->rx_done.bus);
cmd.data1 = MYRI10GE_HIGHPART_TO_U32(ss->rx_done.bus);
cmd.data2 = i;
status |= myri10ge_send_cmd(mgp, MXGEFW_CMD_SET_INTRQ_DMA,
&cmd, 0);
}
status |=
myri10ge_send_cmd(mgp, MXGEFW_CMD_GET_IRQ_ACK_OFFSET, &cmd, 0);
for (i = 0; i < mgp->num_slices; i++) {
ss = &mgp->ss[i];
ss->irq_claim =
(__iomem __be32 *) (mgp->sram + cmd.data0 + 8 * i);
}
status |= myri10ge_send_cmd(mgp, MXGEFW_CMD_GET_IRQ_DEASSERT_OFFSET,
&cmd, 0);
mgp->irq_deassert = (__iomem __be32 *) (mgp->sram + cmd.data0);
status |= myri10ge_send_cmd
(mgp, MXGEFW_CMD_GET_INTR_COAL_DELAY_OFFSET, &cmd, 0);
mgp->intr_coal_delay_ptr = (__iomem __be32 *) (mgp->sram + cmd.data0);
if (status != 0) {
dev_err(&mgp->pdev->dev, "failed set interrupt parameters\n");
return status;
}
put_be32(htonl(mgp->intr_coal_delay), mgp->intr_coal_delay_ptr);
#ifdef CONFIG_MYRI10GE_DCA
status = myri10ge_send_cmd(mgp, MXGEFW_CMD_GET_DCA_OFFSET, &cmd, 0);
dca_tag_off = cmd.data0;
for (i = 0; i < mgp->num_slices; i++) {
ss = &mgp->ss[i];
if (status == 0) {
ss->dca_tag = (__iomem __be32 *)
(mgp->sram + dca_tag_off + 4 * i);
} else {
ss->dca_tag = NULL;
}
}
#endif
mgp->link_changes = 0;
for (i = 0; i < mgp->num_slices; i++) {
ss = &mgp->ss[i];
memset(ss->rx_done.entry, 0, bytes);
ss->tx.req = 0;
ss->tx.done = 0;
ss->tx.pkt_start = 0;
ss->tx.pkt_done = 0;
ss->rx_big.cnt = 0;
ss->rx_small.cnt = 0;
ss->rx_done.idx = 0;
ss->rx_done.cnt = 0;
ss->tx.wake_queue = 0;
ss->tx.stop_queue = 0;
}
status = myri10ge_update_mac_address(mgp, mgp->dev->dev_addr);
myri10ge_change_pause(mgp, mgp->pause);
myri10ge_set_multicast_list(mgp->dev);
return status;
}
static int myri10ge_toggle_relaxed(struct pci_dev *pdev, int on)
{
int ret;
u16 ctl;
pcie_capability_read_word(pdev, PCI_EXP_DEVCTL, &ctl);
ret = (ctl & PCI_EXP_DEVCTL_RELAX_EN) >> 4;
if (ret != on) {
ctl &= ~PCI_EXP_DEVCTL_RELAX_EN;
ctl |= (on << 4);
pcie_capability_write_word(pdev, PCI_EXP_DEVCTL, ctl);
}
return ret;
}
static void
myri10ge_write_dca(struct myri10ge_slice_state *ss, int cpu, int tag)
{
ss->cached_dca_tag = tag;
put_be32(htonl(tag), ss->dca_tag);
}
static inline void myri10ge_update_dca(struct myri10ge_slice_state *ss)
{
int cpu = get_cpu();
int tag;
if (cpu != ss->cpu) {
tag = dca3_get_tag(&ss->mgp->pdev->dev, cpu);
if (ss->cached_dca_tag != tag)
myri10ge_write_dca(ss, cpu, tag);
ss->cpu = cpu;
}
put_cpu();
}
static void myri10ge_setup_dca(struct myri10ge_priv *mgp)
{
int err, i;
struct pci_dev *pdev = mgp->pdev;
if (mgp->ss[0].dca_tag == NULL || mgp->dca_enabled)
return;
if (!myri10ge_dca) {
dev_err(&pdev->dev, "dca disabled by administrator\n");
return;
}
err = dca_add_requester(&pdev->dev);
if (err) {
if (err != -ENODEV)
dev_err(&pdev->dev,
"dca_add_requester() failed, err=%d\n", err);
return;
}
mgp->relaxed_order = myri10ge_toggle_relaxed(pdev, 0);
mgp->dca_enabled = 1;
for (i = 0; i < mgp->num_slices; i++) {
mgp->ss[i].cpu = -1;
mgp->ss[i].cached_dca_tag = -1;
myri10ge_update_dca(&mgp->ss[i]);
}
}
static void myri10ge_teardown_dca(struct myri10ge_priv *mgp)
{
struct pci_dev *pdev = mgp->pdev;
if (!mgp->dca_enabled)
return;
mgp->dca_enabled = 0;
if (mgp->relaxed_order)
myri10ge_toggle_relaxed(pdev, 1);
dca_remove_requester(&pdev->dev);
}
static int myri10ge_notify_dca_device(struct device *dev, void *data)
{
struct myri10ge_priv *mgp;
unsigned long event;
mgp = dev_get_drvdata(dev);
event = *(unsigned long *)data;
if (event == DCA_PROVIDER_ADD)
myri10ge_setup_dca(mgp);
else if (event == DCA_PROVIDER_REMOVE)
myri10ge_teardown_dca(mgp);
return 0;
}
static inline void
myri10ge_submit_8rx(struct mcp_kreq_ether_recv __iomem * dst,
struct mcp_kreq_ether_recv *src)
{
__be32 low;
low = src->addr_low;
src->addr_low = htonl(DMA_BIT_MASK(32));
myri10ge_pio_copy(dst, src, 4 * sizeof(*src));
mb();
myri10ge_pio_copy(dst + 4, src + 4, 4 * sizeof(*src));
mb();
src->addr_low = low;
put_be32(low, &dst->addr_low);
mb();
}
static inline void myri10ge_vlan_ip_csum(struct sk_buff *skb, __wsum hw_csum)
{
struct vlan_hdr *vh = (struct vlan_hdr *)(skb->data);
if ((skb->protocol == htons(ETH_P_8021Q)) &&
(vh->h_vlan_encapsulated_proto == htons(ETH_P_IP) ||
vh->h_vlan_encapsulated_proto == htons(ETH_P_IPV6))) {
skb->csum = hw_csum;
skb->ip_summed = CHECKSUM_COMPLETE;
}
}
static void
myri10ge_alloc_rx_pages(struct myri10ge_priv *mgp, struct myri10ge_rx_buf *rx,
int bytes, int watchdog)
{
struct page *page;
int idx;
#if MYRI10GE_ALLOC_SIZE > 4096
int end_offset;
#endif
if (unlikely(rx->watchdog_needed && !watchdog))
return;
while (rx->fill_cnt != (rx->cnt + rx->mask + 1)) {
idx = rx->fill_cnt & rx->mask;
if (rx->page_offset + bytes <= MYRI10GE_ALLOC_SIZE) {
get_page(rx->page);
} else {
page =
alloc_pages(GFP_ATOMIC | __GFP_COMP,
MYRI10GE_ALLOC_ORDER);
if (unlikely(page == NULL)) {
if (rx->fill_cnt - rx->cnt < 16)
rx->watchdog_needed = 1;
return;
}
rx->page = page;
rx->page_offset = 0;
rx->bus = pci_map_page(mgp->pdev, page, 0,
MYRI10GE_ALLOC_SIZE,
PCI_DMA_FROMDEVICE);
}
rx->info[idx].page = rx->page;
rx->info[idx].page_offset = rx->page_offset;
dma_unmap_addr_set(&rx->info[idx], bus, rx->bus);
rx->shadow[idx].addr_low =
htonl(MYRI10GE_LOWPART_TO_U32(rx->bus) + rx->page_offset);
rx->shadow[idx].addr_high =
htonl(MYRI10GE_HIGHPART_TO_U32(rx->bus));
rx->page_offset += SKB_DATA_ALIGN(bytes);
#if MYRI10GE_ALLOC_SIZE > 4096
end_offset = rx->page_offset + bytes - 1;
if ((unsigned)(rx->page_offset ^ end_offset) > 4095)
rx->page_offset = end_offset & ~4095;
#endif
rx->fill_cnt++;
if ((idx & 7) == 7) {
myri10ge_submit_8rx(&rx->lanai[idx - 7],
&rx->shadow[idx - 7]);
}
}
}
static inline void
myri10ge_unmap_rx_page(struct pci_dev *pdev,
struct myri10ge_rx_buffer_state *info, int bytes)
{
if (bytes >= MYRI10GE_ALLOC_SIZE / 2 ||
(info->page_offset + 2 * bytes) > MYRI10GE_ALLOC_SIZE) {
pci_unmap_page(pdev, (dma_unmap_addr(info, bus)
& ~(MYRI10GE_ALLOC_SIZE - 1)),
MYRI10GE_ALLOC_SIZE, PCI_DMA_FROMDEVICE);
}
}
static inline void
myri10ge_vlan_rx(struct net_device *dev, void *addr, struct sk_buff *skb)
{
u8 *va;
struct vlan_ethhdr *veh;
struct skb_frag_struct *frag;
__wsum vsum;
va = addr;
va += MXGEFW_PAD;
veh = (struct vlan_ethhdr *)va;
if ((dev->features & NETIF_F_HW_VLAN_CTAG_RX) ==
NETIF_F_HW_VLAN_CTAG_RX &&
veh->h_vlan_proto == htons(ETH_P_8021Q)) {
if (skb->ip_summed == CHECKSUM_COMPLETE) {
vsum = csum_partial(va + ETH_HLEN, VLAN_HLEN, 0);
skb->csum = csum_sub(skb->csum, vsum);
}
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q), ntohs(veh->h_vlan_TCI));
memmove(va + VLAN_HLEN, va, 2 * ETH_ALEN);
skb->len -= VLAN_HLEN;
skb->data_len -= VLAN_HLEN;
frag = skb_shinfo(skb)->frags;
frag->page_offset += VLAN_HLEN;
skb_frag_size_set(frag, skb_frag_size(frag) - VLAN_HLEN);
}
}
static inline int
myri10ge_rx_done(struct myri10ge_slice_state *ss, int len, __wsum csum)
{
struct myri10ge_priv *mgp = ss->mgp;
struct sk_buff *skb;
struct skb_frag_struct *rx_frags;
struct myri10ge_rx_buf *rx;
int i, idx, remainder, bytes;
struct pci_dev *pdev = mgp->pdev;
struct net_device *dev = mgp->dev;
u8 *va;
bool polling;
if (len <= mgp->small_bytes) {
rx = &ss->rx_small;
bytes = mgp->small_bytes;
} else {
rx = &ss->rx_big;
bytes = mgp->big_bytes;
}
len += MXGEFW_PAD;
idx = rx->cnt & rx->mask;
va = page_address(rx->info[idx].page) + rx->info[idx].page_offset;
prefetch(va);
polling = myri10ge_ss_busy_polling(ss);
if (polling)
skb = netdev_alloc_skb(dev, MYRI10GE_HLEN + 16);
else
skb = napi_get_frags(&ss->napi);
if (unlikely(skb == NULL)) {
ss->stats.rx_dropped++;
for (i = 0, remainder = len; remainder > 0; i++) {
myri10ge_unmap_rx_page(pdev, &rx->info[idx], bytes);
put_page(rx->info[idx].page);
rx->cnt++;
idx = rx->cnt & rx->mask;
remainder -= MYRI10GE_ALLOC_SIZE;
}
return 0;
}
rx_frags = skb_shinfo(skb)->frags;
for (i = 0, remainder = len; remainder > 0; i++) {
myri10ge_unmap_rx_page(pdev, &rx->info[idx], bytes);
skb_fill_page_desc(skb, i, rx->info[idx].page,
rx->info[idx].page_offset,
remainder < MYRI10GE_ALLOC_SIZE ?
remainder : MYRI10GE_ALLOC_SIZE);
rx->cnt++;
idx = rx->cnt & rx->mask;
remainder -= MYRI10GE_ALLOC_SIZE;
}
rx_frags[0].page_offset += MXGEFW_PAD;
rx_frags[0].size -= MXGEFW_PAD;
len -= MXGEFW_PAD;
skb->len = len;
skb->data_len = len;
skb->truesize += len;
if (dev->features & NETIF_F_RXCSUM) {
skb->ip_summed = CHECKSUM_COMPLETE;
skb->csum = csum;
}
myri10ge_vlan_rx(mgp->dev, va, skb);
skb_record_rx_queue(skb, ss - &mgp->ss[0]);
skb_mark_napi_id(skb, &ss->napi);
if (polling) {
int hlen;
hlen = MYRI10GE_HLEN > skb->len ? skb->len : MYRI10GE_HLEN;
va = page_address(skb_frag_page(&rx_frags[0])) +
rx_frags[0].page_offset;
skb_copy_to_linear_data(skb, va, hlen);
rx_frags[0].page_offset += hlen;
rx_frags[0].size -= hlen;
skb->data_len -= hlen;
skb->tail += hlen;
skb->protocol = eth_type_trans(skb, dev);
netif_receive_skb(skb);
}
else
napi_gro_frags(&ss->napi);
return 1;
}
static inline void
myri10ge_tx_done(struct myri10ge_slice_state *ss, int mcp_index)
{
struct pci_dev *pdev = ss->mgp->pdev;
struct myri10ge_tx_buf *tx = &ss->tx;
struct netdev_queue *dev_queue;
struct sk_buff *skb;
int idx, len;
while (tx->pkt_done != mcp_index) {
idx = tx->done & tx->mask;
skb = tx->info[idx].skb;
tx->info[idx].skb = NULL;
if (tx->info[idx].last) {
tx->pkt_done++;
tx->info[idx].last = 0;
}
tx->done++;
len = dma_unmap_len(&tx->info[idx], len);
dma_unmap_len_set(&tx->info[idx], len, 0);
if (skb) {
ss->stats.tx_bytes += skb->len;
ss->stats.tx_packets++;
dev_kfree_skb_irq(skb);
if (len)
pci_unmap_single(pdev,
dma_unmap_addr(&tx->info[idx],
bus), len,
PCI_DMA_TODEVICE);
} else {
if (len)
pci_unmap_page(pdev,
dma_unmap_addr(&tx->info[idx],
bus), len,
PCI_DMA_TODEVICE);
}
}
dev_queue = netdev_get_tx_queue(ss->dev, ss - ss->mgp->ss);
if ((ss->mgp->dev->real_num_tx_queues > 1) &&
__netif_tx_trylock(dev_queue)) {
if (tx->req == tx->done) {
tx->queue_active = 0;
put_be32(htonl(1), tx->send_stop);
mb();
mmiowb();
}
__netif_tx_unlock(dev_queue);
}
if (netif_tx_queue_stopped(dev_queue) &&
tx->req - tx->done < (tx->mask >> 1) &&
ss->mgp->running == MYRI10GE_ETH_RUNNING) {
tx->wake_queue++;
netif_tx_wake_queue(dev_queue);
}
}
static inline int
myri10ge_clean_rx_done(struct myri10ge_slice_state *ss, int budget)
{
struct myri10ge_rx_done *rx_done = &ss->rx_done;
struct myri10ge_priv *mgp = ss->mgp;
unsigned long rx_bytes = 0;
unsigned long rx_packets = 0;
unsigned long rx_ok;
int idx = rx_done->idx;
int cnt = rx_done->cnt;
int work_done = 0;
u16 length;
__wsum checksum;
while (rx_done->entry[idx].length != 0 && work_done < budget) {
length = ntohs(rx_done->entry[idx].length);
rx_done->entry[idx].length = 0;
checksum = csum_unfold(rx_done->entry[idx].checksum);
rx_ok = myri10ge_rx_done(ss, length, checksum);
rx_packets += rx_ok;
rx_bytes += rx_ok * (unsigned long)length;
cnt++;
idx = cnt & (mgp->max_intr_slots - 1);
work_done++;
}
rx_done->idx = idx;
rx_done->cnt = cnt;
ss->stats.rx_packets += rx_packets;
ss->stats.rx_bytes += rx_bytes;
if (ss->rx_small.fill_cnt - ss->rx_small.cnt < myri10ge_fill_thresh)
myri10ge_alloc_rx_pages(mgp, &ss->rx_small,
mgp->small_bytes + MXGEFW_PAD, 0);
if (ss->rx_big.fill_cnt - ss->rx_big.cnt < myri10ge_fill_thresh)
myri10ge_alloc_rx_pages(mgp, &ss->rx_big, mgp->big_bytes, 0);
return work_done;
}
static inline void myri10ge_check_statblock(struct myri10ge_priv *mgp)
{
struct mcp_irq_data *stats = mgp->ss[0].fw_stats;
if (unlikely(stats->stats_updated)) {
unsigned link_up = ntohl(stats->link_up);
if (mgp->link_state != link_up) {
mgp->link_state = link_up;
if (mgp->link_state == MXGEFW_LINK_UP) {
netif_info(mgp, link, mgp->dev, "link up\n");
netif_carrier_on(mgp->dev);
mgp->link_changes++;
} else {
netif_info(mgp, link, mgp->dev, "link %s\n",
(link_up == MXGEFW_LINK_MYRINET ?
"mismatch (Myrinet detected)" :
"down"));
netif_carrier_off(mgp->dev);
mgp->link_changes++;
}
}
if (mgp->rdma_tags_available !=
ntohl(stats->rdma_tags_available)) {
mgp->rdma_tags_available =
ntohl(stats->rdma_tags_available);
netdev_warn(mgp->dev, "RDMA timed out! %d tags left\n",
mgp->rdma_tags_available);
}
mgp->down_cnt += stats->link_down;
if (stats->link_down)
wake_up(&mgp->down_wq);
}
}
static int myri10ge_poll(struct napi_struct *napi, int budget)
{
struct myri10ge_slice_state *ss =
container_of(napi, struct myri10ge_slice_state, napi);
int work_done;
#ifdef CONFIG_MYRI10GE_DCA
if (ss->mgp->dca_enabled)
myri10ge_update_dca(ss);
#endif
if (!myri10ge_ss_lock_napi(ss))
return budget;
work_done = myri10ge_clean_rx_done(ss, budget);
myri10ge_ss_unlock_napi(ss);
if (work_done < budget) {
napi_complete(napi);
put_be32(htonl(3), ss->irq_claim);
}
return work_done;
}
static int myri10ge_busy_poll(struct napi_struct *napi)
{
struct myri10ge_slice_state *ss =
container_of(napi, struct myri10ge_slice_state, napi);
struct myri10ge_priv *mgp = ss->mgp;
int work_done;
if (mgp->link_state != MXGEFW_LINK_UP)
return LL_FLUSH_FAILED;
if (!myri10ge_ss_lock_poll(ss))
return LL_FLUSH_BUSY;
work_done = myri10ge_clean_rx_done(ss, 4);
if (work_done)
ss->busy_poll_cnt += work_done;
else
ss->busy_poll_miss++;
myri10ge_ss_unlock_poll(ss);
return work_done;
}
static irqreturn_t myri10ge_intr(int irq, void *arg)
{
struct myri10ge_slice_state *ss = arg;
struct myri10ge_priv *mgp = ss->mgp;
struct mcp_irq_data *stats = ss->fw_stats;
struct myri10ge_tx_buf *tx = &ss->tx;
u32 send_done_count;
int i;
if ((mgp->dev->real_num_tx_queues == 1) && (ss != mgp->ss)) {
napi_schedule(&ss->napi);
return IRQ_HANDLED;
}
if (unlikely(!stats->valid))
return IRQ_NONE;
if (stats->valid & 1)
napi_schedule(&ss->napi);
if (!mgp->msi_enabled && !mgp->msix_enabled) {
put_be32(0, mgp->irq_deassert);
if (!myri10ge_deassert_wait)
stats->valid = 0;
mb();
} else
stats->valid = 0;
i = 0;
while (1) {
i++;
send_done_count = ntohl(stats->send_done_count);
if (send_done_count != tx->pkt_done)
myri10ge_tx_done(ss, (int)send_done_count);
if (unlikely(i > myri10ge_max_irq_loops)) {
netdev_warn(mgp->dev, "irq stuck?\n");
stats->valid = 0;
schedule_work(&mgp->watchdog_work);
}
if (likely(stats->valid == 0))
break;
cpu_relax();
barrier();
}
if (ss == mgp->ss)
myri10ge_check_statblock(mgp);
put_be32(htonl(3), ss->irq_claim + 1);
return IRQ_HANDLED;
}
static int
myri10ge_get_settings(struct net_device *netdev, struct ethtool_cmd *cmd)
{
struct myri10ge_priv *mgp = netdev_priv(netdev);
char *ptr;
int i;
cmd->autoneg = AUTONEG_DISABLE;
ethtool_cmd_speed_set(cmd, SPEED_10000);
cmd->duplex = DUPLEX_FULL;
ptr = mgp->product_code_string;
if (ptr == NULL) {
netdev_err(netdev, "Missing product code\n");
return 0;
}
for (i = 0; i < 3; i++, ptr++) {
ptr = strchr(ptr, '-');
if (ptr == NULL) {
netdev_err(netdev, "Invalid product code %s\n",
mgp->product_code_string);
return 0;
}
}
if (*ptr == '2')
ptr++;
if (*ptr == 'R' || *ptr == 'Q' || *ptr == 'S') {
cmd->port = PORT_FIBRE;
cmd->supported |= SUPPORTED_FIBRE;
cmd->advertising |= ADVERTISED_FIBRE;
} else {
cmd->port = PORT_OTHER;
}
if (*ptr == 'R' || *ptr == 'S')
cmd->transceiver = XCVR_EXTERNAL;
else
cmd->transceiver = XCVR_INTERNAL;
return 0;
}
static void
myri10ge_get_drvinfo(struct net_device *netdev, struct ethtool_drvinfo *info)
{
struct myri10ge_priv *mgp = netdev_priv(netdev);
strlcpy(info->driver, "myri10ge", sizeof(info->driver));
strlcpy(info->version, MYRI10GE_VERSION_STR, sizeof(info->version));
strlcpy(info->fw_version, mgp->fw_version, sizeof(info->fw_version));
strlcpy(info->bus_info, pci_name(mgp->pdev), sizeof(info->bus_info));
}
static int
myri10ge_get_coalesce(struct net_device *netdev, struct ethtool_coalesce *coal)
{
struct myri10ge_priv *mgp = netdev_priv(netdev);
coal->rx_coalesce_usecs = mgp->intr_coal_delay;
return 0;
}
static int
myri10ge_set_coalesce(struct net_device *netdev, struct ethtool_coalesce *coal)
{
struct myri10ge_priv *mgp = netdev_priv(netdev);
mgp->intr_coal_delay = coal->rx_coalesce_usecs;
put_be32(htonl(mgp->intr_coal_delay), mgp->intr_coal_delay_ptr);
return 0;
}
static void
myri10ge_get_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct myri10ge_priv *mgp = netdev_priv(netdev);
pause->autoneg = 0;
pause->rx_pause = mgp->pause;
pause->tx_pause = mgp->pause;
}
static int
myri10ge_set_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct myri10ge_priv *mgp = netdev_priv(netdev);
if (pause->tx_pause != mgp->pause)
return myri10ge_change_pause(mgp, pause->tx_pause);
if (pause->rx_pause != mgp->pause)
return myri10ge_change_pause(mgp, pause->rx_pause);
if (pause->autoneg != 0)
return -EINVAL;
return 0;
}
static void
myri10ge_get_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct myri10ge_priv *mgp = netdev_priv(netdev);
ring->rx_mini_max_pending = mgp->ss[0].rx_small.mask + 1;
ring->rx_max_pending = mgp->ss[0].rx_big.mask + 1;
ring->rx_jumbo_max_pending = 0;
ring->tx_max_pending = mgp->ss[0].tx.mask + 1;
ring->rx_mini_pending = ring->rx_mini_max_pending;
ring->rx_pending = ring->rx_max_pending;
ring->rx_jumbo_pending = ring->rx_jumbo_max_pending;
ring->tx_pending = ring->tx_max_pending;
}
static void
myri10ge_get_strings(struct net_device *netdev, u32 stringset, u8 * data)
{
struct myri10ge_priv *mgp = netdev_priv(netdev);
int i;
switch (stringset) {
case ETH_SS_STATS:
memcpy(data, *myri10ge_gstrings_main_stats,
sizeof(myri10ge_gstrings_main_stats));
data += sizeof(myri10ge_gstrings_main_stats);
for (i = 0; i < mgp->num_slices; i++) {
memcpy(data, *myri10ge_gstrings_slice_stats,
sizeof(myri10ge_gstrings_slice_stats));
data += sizeof(myri10ge_gstrings_slice_stats);
}
break;
}
}
static int myri10ge_get_sset_count(struct net_device *netdev, int sset)
{
struct myri10ge_priv *mgp = netdev_priv(netdev);
switch (sset) {
case ETH_SS_STATS:
return MYRI10GE_MAIN_STATS_LEN +
mgp->num_slices * MYRI10GE_SLICE_STATS_LEN;
default:
return -EOPNOTSUPP;
}
}
static void
myri10ge_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats, u64 * data)
{
struct myri10ge_priv *mgp = netdev_priv(netdev);
struct myri10ge_slice_state *ss;
struct rtnl_link_stats64 link_stats;
int slice;
int i;
memset(&link_stats, 0, sizeof(link_stats));
(void)myri10ge_get_stats(netdev, &link_stats);
for (i = 0; i < MYRI10GE_NET_STATS_LEN; i++)
data[i] = ((u64 *)&link_stats)[i];
data[i++] = (unsigned int)mgp->tx_boundary;
data[i++] = (unsigned int)mgp->wc_enabled;
data[i++] = (unsigned int)mgp->pdev->irq;
data[i++] = (unsigned int)mgp->msi_enabled;
data[i++] = (unsigned int)mgp->msix_enabled;
data[i++] = (unsigned int)mgp->read_dma;
data[i++] = (unsigned int)mgp->write_dma;
data[i++] = (unsigned int)mgp->read_write_dma;
data[i++] = (unsigned int)mgp->serial_number;
data[i++] = (unsigned int)mgp->watchdog_resets;
#ifdef CONFIG_MYRI10GE_DCA
data[i++] = (unsigned int)(mgp->ss[0].dca_tag != NULL);
data[i++] = (unsigned int)(mgp->dca_enabled);
#endif
data[i++] = (unsigned int)mgp->link_changes;
ss = &mgp->ss[0];
data[i++] = (unsigned int)ntohl(ss->fw_stats->link_up);
data[i++] = (unsigned int)ntohl(ss->fw_stats->dropped_link_overflow);
data[i++] =
(unsigned int)ntohl(ss->fw_stats->dropped_link_error_or_filtered);
data[i++] = (unsigned int)ntohl(ss->fw_stats->dropped_pause);
data[i++] = (unsigned int)ntohl(ss->fw_stats->dropped_bad_phy);
data[i++] = (unsigned int)ntohl(ss->fw_stats->dropped_bad_crc32);
data[i++] = (unsigned int)ntohl(ss->fw_stats->dropped_unicast_filtered);
data[i++] =
(unsigned int)ntohl(ss->fw_stats->dropped_multicast_filtered);
data[i++] = (unsigned int)ntohl(ss->fw_stats->dropped_runt);
data[i++] = (unsigned int)ntohl(ss->fw_stats->dropped_overrun);
data[i++] = (unsigned int)ntohl(ss->fw_stats->dropped_no_small_buffer);
data[i++] = (unsigned int)ntohl(ss->fw_stats->dropped_no_big_buffer);
for (slice = 0; slice < mgp->num_slices; slice++) {
ss = &mgp->ss[slice];
data[i++] = slice;
data[i++] = (unsigned int)ss->tx.pkt_start;
data[i++] = (unsigned int)ss->tx.pkt_done;
data[i++] = (unsigned int)ss->tx.req;
data[i++] = (unsigned int)ss->tx.done;
data[i++] = (unsigned int)ss->rx_small.cnt;
data[i++] = (unsigned int)ss->rx_big.cnt;
data[i++] = (unsigned int)ss->tx.wake_queue;
data[i++] = (unsigned int)ss->tx.stop_queue;
data[i++] = (unsigned int)ss->tx.linearized;
#ifdef CONFIG_NET_RX_BUSY_POLL
data[i++] = ss->lock_napi_yield;
data[i++] = ss->lock_poll_yield;
data[i++] = ss->busy_poll_miss;
data[i++] = ss->busy_poll_cnt;
#endif
}
}
static void myri10ge_set_msglevel(struct net_device *netdev, u32 value)
{
struct myri10ge_priv *mgp = netdev_priv(netdev);
mgp->msg_enable = value;
}
static u32 myri10ge_get_msglevel(struct net_device *netdev)
{
struct myri10ge_priv *mgp = netdev_priv(netdev);
return mgp->msg_enable;
}
static int myri10ge_led(struct myri10ge_priv *mgp, int on)
{
struct mcp_gen_header *hdr;
struct device *dev = &mgp->pdev->dev;
size_t hdr_off, pattern_off, hdr_len;
u32 pattern = 0xfffffffe;
hdr_off = swab32(readl(mgp->sram + MCP_HEADER_PTR_OFFSET));
if ((hdr_off & 3) || hdr_off + sizeof(*hdr) > mgp->sram_size) {
dev_err(dev, "Running firmware has bad header offset (%d)\n",
(int)hdr_off);
return -EIO;
}
hdr_len = swab32(readl(mgp->sram + hdr_off +
offsetof(struct mcp_gen_header, header_length)));
pattern_off = hdr_off + offsetof(struct mcp_gen_header, led_pattern);
if (pattern_off >= (hdr_len + hdr_off)) {
dev_info(dev, "Firmware does not support LED identification\n");
return -EINVAL;
}
if (!on)
pattern = swab32(readl(mgp->sram + pattern_off + 4));
writel(swab32(pattern), mgp->sram + pattern_off);
return 0;
}
static int
myri10ge_phys_id(struct net_device *netdev, enum ethtool_phys_id_state state)
{
struct myri10ge_priv *mgp = netdev_priv(netdev);
int rc;
switch (state) {
case ETHTOOL_ID_ACTIVE:
rc = myri10ge_led(mgp, 1);
break;
case ETHTOOL_ID_INACTIVE:
rc = myri10ge_led(mgp, 0);
break;
default:
rc = -EINVAL;
}
return rc;
}
static int myri10ge_allocate_rings(struct myri10ge_slice_state *ss)
{
struct myri10ge_priv *mgp = ss->mgp;
struct myri10ge_cmd cmd;
struct net_device *dev = mgp->dev;
int tx_ring_size, rx_ring_size;
int tx_ring_entries, rx_ring_entries;
int i, slice, status;
size_t bytes;
slice = ss - mgp->ss;
cmd.data0 = slice;
status = myri10ge_send_cmd(mgp, MXGEFW_CMD_GET_SEND_RING_SIZE, &cmd, 0);
tx_ring_size = cmd.data0;
cmd.data0 = slice;
status |= myri10ge_send_cmd(mgp, MXGEFW_CMD_GET_RX_RING_SIZE, &cmd, 0);
if (status != 0)
return status;
rx_ring_size = cmd.data0;
tx_ring_entries = tx_ring_size / sizeof(struct mcp_kreq_ether_send);
rx_ring_entries = rx_ring_size / sizeof(struct mcp_dma_addr);
ss->tx.mask = tx_ring_entries - 1;
ss->rx_small.mask = ss->rx_big.mask = rx_ring_entries - 1;
status = -ENOMEM;
bytes = 8 + (MYRI10GE_MAX_SEND_DESC_TSO + 4)
* sizeof(*ss->tx.req_list);
ss->tx.req_bytes = kzalloc(bytes, GFP_KERNEL);
if (ss->tx.req_bytes == NULL)
goto abort_with_nothing;
ss->tx.req_list = (struct mcp_kreq_ether_send *)
ALIGN((unsigned long)ss->tx.req_bytes, 8);
ss->tx.queue_active = 0;
bytes = rx_ring_entries * sizeof(*ss->rx_small.shadow);
ss->rx_small.shadow = kzalloc(bytes, GFP_KERNEL);
if (ss->rx_small.shadow == NULL)
goto abort_with_tx_req_bytes;
bytes = rx_ring_entries * sizeof(*ss->rx_big.shadow);
ss->rx_big.shadow = kzalloc(bytes, GFP_KERNEL);
if (ss->rx_big.shadow == NULL)
goto abort_with_rx_small_shadow;
bytes = tx_ring_entries * sizeof(*ss->tx.info);
ss->tx.info = kzalloc(bytes, GFP_KERNEL);
if (ss->tx.info == NULL)
goto abort_with_rx_big_shadow;
bytes = rx_ring_entries * sizeof(*ss->rx_small.info);
ss->rx_small.info = kzalloc(bytes, GFP_KERNEL);
if (ss->rx_small.info == NULL)
goto abort_with_tx_info;
bytes = rx_ring_entries * sizeof(*ss->rx_big.info);
ss->rx_big.info = kzalloc(bytes, GFP_KERNEL);
if (ss->rx_big.info == NULL)
goto abort_with_rx_small_info;
ss->rx_big.cnt = 0;
ss->rx_small.cnt = 0;
ss->rx_big.fill_cnt = 0;
ss->rx_small.fill_cnt = 0;
ss->rx_small.page_offset = MYRI10GE_ALLOC_SIZE;
ss->rx_big.page_offset = MYRI10GE_ALLOC_SIZE;
ss->rx_small.watchdog_needed = 0;
ss->rx_big.watchdog_needed = 0;
if (mgp->small_bytes == 0) {
ss->rx_small.fill_cnt = ss->rx_small.mask + 1;
} else {
myri10ge_alloc_rx_pages(mgp, &ss->rx_small,
mgp->small_bytes + MXGEFW_PAD, 0);
}
if (ss->rx_small.fill_cnt < ss->rx_small.mask + 1) {
netdev_err(dev, "slice-%d: alloced only %d small bufs\n",
slice, ss->rx_small.fill_cnt);
goto abort_with_rx_small_ring;
}
myri10ge_alloc_rx_pages(mgp, &ss->rx_big, mgp->big_bytes, 0);
if (ss->rx_big.fill_cnt < ss->rx_big.mask + 1) {
netdev_err(dev, "slice-%d: alloced only %d big bufs\n",
slice, ss->rx_big.fill_cnt);
goto abort_with_rx_big_ring;
}
return 0;
abort_with_rx_big_ring:
for (i = ss->rx_big.cnt; i < ss->rx_big.fill_cnt; i++) {
int idx = i & ss->rx_big.mask;
myri10ge_unmap_rx_page(mgp->pdev, &ss->rx_big.info[idx],
mgp->big_bytes);
put_page(ss->rx_big.info[idx].page);
}
abort_with_rx_small_ring:
if (mgp->small_bytes == 0)
ss->rx_small.fill_cnt = ss->rx_small.cnt;
for (i = ss->rx_small.cnt; i < ss->rx_small.fill_cnt; i++) {
int idx = i & ss->rx_small.mask;
myri10ge_unmap_rx_page(mgp->pdev, &ss->rx_small.info[idx],
mgp->small_bytes + MXGEFW_PAD);
put_page(ss->rx_small.info[idx].page);
}
kfree(ss->rx_big.info);
abort_with_rx_small_info:
kfree(ss->rx_small.info);
abort_with_tx_info:
kfree(ss->tx.info);
abort_with_rx_big_shadow:
kfree(ss->rx_big.shadow);
abort_with_rx_small_shadow:
kfree(ss->rx_small.shadow);
abort_with_tx_req_bytes:
kfree(ss->tx.req_bytes);
ss->tx.req_bytes = NULL;
ss->tx.req_list = NULL;
abort_with_nothing:
return status;
}
static void myri10ge_free_rings(struct myri10ge_slice_state *ss)
{
struct myri10ge_priv *mgp = ss->mgp;
struct sk_buff *skb;
struct myri10ge_tx_buf *tx;
int i, len, idx;
if (ss->tx.req_list == NULL)
return;
for (i = ss->rx_big.cnt; i < ss->rx_big.fill_cnt; i++) {
idx = i & ss->rx_big.mask;
if (i == ss->rx_big.fill_cnt - 1)
ss->rx_big.info[idx].page_offset = MYRI10GE_ALLOC_SIZE;
myri10ge_unmap_rx_page(mgp->pdev, &ss->rx_big.info[idx],
mgp->big_bytes);
put_page(ss->rx_big.info[idx].page);
}
if (mgp->small_bytes == 0)
ss->rx_small.fill_cnt = ss->rx_small.cnt;
for (i = ss->rx_small.cnt; i < ss->rx_small.fill_cnt; i++) {
idx = i & ss->rx_small.mask;
if (i == ss->rx_small.fill_cnt - 1)
ss->rx_small.info[idx].page_offset =
MYRI10GE_ALLOC_SIZE;
myri10ge_unmap_rx_page(mgp->pdev, &ss->rx_small.info[idx],
mgp->small_bytes + MXGEFW_PAD);
put_page(ss->rx_small.info[idx].page);
}
tx = &ss->tx;
while (tx->done != tx->req) {
idx = tx->done & tx->mask;
skb = tx->info[idx].skb;
tx->info[idx].skb = NULL;
tx->done++;
len = dma_unmap_len(&tx->info[idx], len);
dma_unmap_len_set(&tx->info[idx], len, 0);
if (skb) {
ss->stats.tx_dropped++;
dev_kfree_skb_any(skb);
if (len)
pci_unmap_single(mgp->pdev,
dma_unmap_addr(&tx->info[idx],
bus), len,
PCI_DMA_TODEVICE);
} else {
if (len)
pci_unmap_page(mgp->pdev,
dma_unmap_addr(&tx->info[idx],
bus), len,
PCI_DMA_TODEVICE);
}
}
kfree(ss->rx_big.info);
kfree(ss->rx_small.info);
kfree(ss->tx.info);
kfree(ss->rx_big.shadow);
kfree(ss->rx_small.shadow);
kfree(ss->tx.req_bytes);
ss->tx.req_bytes = NULL;
ss->tx.req_list = NULL;
}
static int myri10ge_request_irq(struct myri10ge_priv *mgp)
{
struct pci_dev *pdev = mgp->pdev;
struct myri10ge_slice_state *ss;
struct net_device *netdev = mgp->dev;
int i;
int status;
mgp->msi_enabled = 0;
mgp->msix_enabled = 0;
status = 0;
if (myri10ge_msi) {
if (mgp->num_slices > 1) {
status = pci_enable_msix_range(pdev, mgp->msix_vectors,
mgp->num_slices, mgp->num_slices);
if (status < 0) {
dev_err(&pdev->dev,
"Error %d setting up MSI-X\n", status);
return status;
}
mgp->msix_enabled = 1;
}
if (mgp->msix_enabled == 0) {
status = pci_enable_msi(pdev);
if (status != 0) {
dev_err(&pdev->dev,
"Error %d setting up MSI; falling back to xPIC\n",
status);
} else {
mgp->msi_enabled = 1;
}
}
}
if (mgp->msix_enabled) {
for (i = 0; i < mgp->num_slices; i++) {
ss = &mgp->ss[i];
snprintf(ss->irq_desc, sizeof(ss->irq_desc),
"%s:slice-%d", netdev->name, i);
status = request_irq(mgp->msix_vectors[i].vector,
myri10ge_intr, 0, ss->irq_desc,
ss);
if (status != 0) {
dev_err(&pdev->dev,
"slice %d failed to allocate IRQ\n", i);
i--;
while (i >= 0) {
free_irq(mgp->msix_vectors[i].vector,
&mgp->ss[i]);
i--;
}
pci_disable_msix(pdev);
return status;
}
}
} else {
status = request_irq(pdev->irq, myri10ge_intr, IRQF_SHARED,
mgp->dev->name, &mgp->ss[0]);
if (status != 0) {
dev_err(&pdev->dev, "failed to allocate IRQ\n");
if (mgp->msi_enabled)
pci_disable_msi(pdev);
}
}
return status;
}
static void myri10ge_free_irq(struct myri10ge_priv *mgp)
{
struct pci_dev *pdev = mgp->pdev;
int i;
if (mgp->msix_enabled) {
for (i = 0; i < mgp->num_slices; i++)
free_irq(mgp->msix_vectors[i].vector, &mgp->ss[i]);
} else {
free_irq(pdev->irq, &mgp->ss[0]);
}
if (mgp->msi_enabled)
pci_disable_msi(pdev);
if (mgp->msix_enabled)
pci_disable_msix(pdev);
}
static int myri10ge_get_txrx(struct myri10ge_priv *mgp, int slice)
{
struct myri10ge_cmd cmd;
struct myri10ge_slice_state *ss;
int status;
ss = &mgp->ss[slice];
status = 0;
if (slice == 0 || (mgp->dev->real_num_tx_queues > 1)) {
cmd.data0 = slice;
status = myri10ge_send_cmd(mgp, MXGEFW_CMD_GET_SEND_OFFSET,
&cmd, 0);
ss->tx.lanai = (struct mcp_kreq_ether_send __iomem *)
(mgp->sram + cmd.data0);
}
cmd.data0 = slice;
status |= myri10ge_send_cmd(mgp, MXGEFW_CMD_GET_SMALL_RX_OFFSET,
&cmd, 0);
ss->rx_small.lanai = (struct mcp_kreq_ether_recv __iomem *)
(mgp->sram + cmd.data0);
cmd.data0 = slice;
status |= myri10ge_send_cmd(mgp, MXGEFW_CMD_GET_BIG_RX_OFFSET, &cmd, 0);
ss->rx_big.lanai = (struct mcp_kreq_ether_recv __iomem *)
(mgp->sram + cmd.data0);
ss->tx.send_go = (__iomem __be32 *)
(mgp->sram + MXGEFW_ETH_SEND_GO + 64 * slice);
ss->tx.send_stop = (__iomem __be32 *)
(mgp->sram + MXGEFW_ETH_SEND_STOP + 64 * slice);
return status;
}
static int myri10ge_set_stats(struct myri10ge_priv *mgp, int slice)
{
struct myri10ge_cmd cmd;
struct myri10ge_slice_state *ss;
int status;
ss = &mgp->ss[slice];
cmd.data0 = MYRI10GE_LOWPART_TO_U32(ss->fw_stats_bus);
cmd.data1 = MYRI10GE_HIGHPART_TO_U32(ss->fw_stats_bus);
cmd.data2 = sizeof(struct mcp_irq_data) | (slice << 16);
status = myri10ge_send_cmd(mgp, MXGEFW_CMD_SET_STATS_DMA_V2, &cmd, 0);
if (status == -ENOSYS) {
dma_addr_t bus = ss->fw_stats_bus;
if (slice != 0)
return -EINVAL;
bus += offsetof(struct mcp_irq_data, send_done_count);
cmd.data0 = MYRI10GE_LOWPART_TO_U32(bus);
cmd.data1 = MYRI10GE_HIGHPART_TO_U32(bus);
status = myri10ge_send_cmd(mgp,
MXGEFW_CMD_SET_STATS_DMA_OBSOLETE,
&cmd, 0);
mgp->fw_multicast_support = 0;
} else {
mgp->fw_multicast_support = 1;
}
return 0;
}
static int myri10ge_open(struct net_device *dev)
{
struct myri10ge_slice_state *ss;
struct myri10ge_priv *mgp = netdev_priv(dev);
struct myri10ge_cmd cmd;
int i, status, big_pow2, slice;
u8 __iomem *itable;
if (mgp->running != MYRI10GE_ETH_STOPPED)
return -EBUSY;
mgp->running = MYRI10GE_ETH_STARTING;
status = myri10ge_reset(mgp);
if (status != 0) {
netdev_err(dev, "failed reset\n");
goto abort_with_nothing;
}
if (mgp->num_slices > 1) {
cmd.data0 = mgp->num_slices;
cmd.data1 = MXGEFW_SLICE_INTR_MODE_ONE_PER_SLICE;
if (mgp->dev->real_num_tx_queues > 1)
cmd.data1 |= MXGEFW_SLICE_ENABLE_MULTIPLE_TX_QUEUES;
status = myri10ge_send_cmd(mgp, MXGEFW_CMD_ENABLE_RSS_QUEUES,
&cmd, 0);
if (status != 0) {
netdev_err(dev, "failed to set number of slices\n");
goto abort_with_nothing;
}
cmd.data0 = mgp->num_slices;
status = myri10ge_send_cmd(mgp, MXGEFW_CMD_SET_RSS_TABLE_SIZE,
&cmd, 0);
status |= myri10ge_send_cmd(mgp,
MXGEFW_CMD_GET_RSS_TABLE_OFFSET,
&cmd, 0);
if (status != 0) {
netdev_err(dev, "failed to setup rss tables\n");
goto abort_with_nothing;
}
itable = mgp->sram + cmd.data0;
for (i = 0; i < mgp->num_slices; i++)
__raw_writeb(i, &itable[i]);
cmd.data0 = 1;
cmd.data1 = myri10ge_rss_hash;
status = myri10ge_send_cmd(mgp, MXGEFW_CMD_SET_RSS_ENABLE,
&cmd, 0);
if (status != 0) {
netdev_err(dev, "failed to enable slices\n");
goto abort_with_nothing;
}
}
status = myri10ge_request_irq(mgp);
if (status != 0)
goto abort_with_nothing;
if (dev->mtu <= ETH_DATA_LEN)
mgp->small_bytes = (128 > SMP_CACHE_BYTES)
? (128 - MXGEFW_PAD)
: (SMP_CACHE_BYTES - MXGEFW_PAD);
else
mgp->small_bytes = VLAN_ETH_FRAME_LEN;
if (myri10ge_small_bytes >= 0)
mgp->small_bytes = myri10ge_small_bytes;
big_pow2 = dev->mtu + ETH_HLEN + VLAN_HLEN + MXGEFW_PAD;
if (big_pow2 < MYRI10GE_ALLOC_SIZE / 2) {
while (!is_power_of_2(big_pow2))
big_pow2++;
mgp->big_bytes = dev->mtu + ETH_HLEN + VLAN_HLEN + MXGEFW_PAD;
} else {
big_pow2 = MYRI10GE_ALLOC_SIZE;
mgp->big_bytes = big_pow2;
}
for (slice = 0; slice < mgp->num_slices; slice++) {
ss = &mgp->ss[slice];
status = myri10ge_get_txrx(mgp, slice);
if (status != 0) {
netdev_err(dev, "failed to get ring sizes or locations\n");
goto abort_with_rings;
}
status = myri10ge_allocate_rings(ss);
if (status != 0)
goto abort_with_rings;
if (slice == 0 || mgp->dev->real_num_tx_queues > 1)
status = myri10ge_set_stats(mgp, slice);
if (status) {
netdev_err(dev, "Couldn't set stats DMA\n");
goto abort_with_rings;
}
myri10ge_ss_init_lock(ss);
napi_enable(&(ss)->napi);
}
cmd.data0 = dev->mtu + ETH_HLEN + VLAN_HLEN;
status = myri10ge_send_cmd(mgp, MXGEFW_CMD_SET_MTU, &cmd, 0);
cmd.data0 = mgp->small_bytes;
status |=
myri10ge_send_cmd(mgp, MXGEFW_CMD_SET_SMALL_BUFFER_SIZE, &cmd, 0);
cmd.data0 = big_pow2;
status |=
myri10ge_send_cmd(mgp, MXGEFW_CMD_SET_BIG_BUFFER_SIZE, &cmd, 0);
if (status) {
netdev_err(dev, "Couldn't set buffer sizes\n");
goto abort_with_rings;
}
cmd.data0 = 0;
status = myri10ge_send_cmd(mgp, MXGEFW_CMD_SET_TSO_MODE, &cmd, 0);
if (status && status != -ENOSYS) {
netdev_err(dev, "Couldn't set TSO mode\n");
goto abort_with_rings;
}
mgp->link_state = ~0U;
mgp->rdma_tags_available = 15;
status = myri10ge_send_cmd(mgp, MXGEFW_CMD_ETHERNET_UP, &cmd, 0);
if (status) {
netdev_err(dev, "Couldn't bring up link\n");
goto abort_with_rings;
}
mgp->running = MYRI10GE_ETH_RUNNING;
mgp->watchdog_timer.expires = jiffies + myri10ge_watchdog_timeout * HZ;
add_timer(&mgp->watchdog_timer);
netif_tx_wake_all_queues(dev);
return 0;
abort_with_rings:
while (slice) {
slice--;
napi_disable(&mgp->ss[slice].napi);
}
for (i = 0; i < mgp->num_slices; i++)
myri10ge_free_rings(&mgp->ss[i]);
myri10ge_free_irq(mgp);
abort_with_nothing:
mgp->running = MYRI10GE_ETH_STOPPED;
return -ENOMEM;
}
static int myri10ge_close(struct net_device *dev)
{
struct myri10ge_priv *mgp = netdev_priv(dev);
struct myri10ge_cmd cmd;
int status, old_down_cnt;
int i;
if (mgp->running != MYRI10GE_ETH_RUNNING)
return 0;
if (mgp->ss[0].tx.req_bytes == NULL)
return 0;
del_timer_sync(&mgp->watchdog_timer);
mgp->running = MYRI10GE_ETH_STOPPING;
local_bh_disable();
for (i = 0; i < mgp->num_slices; i++) {
napi_disable(&mgp->ss[i].napi);
while (!myri10ge_ss_lock_napi(&mgp->ss[i])) {
pr_info("Slice %d locked\n", i);
mdelay(1);
}
}
local_bh_enable();
netif_carrier_off(dev);
netif_tx_stop_all_queues(dev);
if (mgp->rebooted == 0) {
old_down_cnt = mgp->down_cnt;
mb();
status =
myri10ge_send_cmd(mgp, MXGEFW_CMD_ETHERNET_DOWN, &cmd, 0);
if (status)
netdev_err(dev, "Couldn't bring down link\n");
wait_event_timeout(mgp->down_wq, old_down_cnt != mgp->down_cnt,
HZ);
if (old_down_cnt == mgp->down_cnt)
netdev_err(dev, "never got down irq\n");
}
netif_tx_disable(dev);
myri10ge_free_irq(mgp);
for (i = 0; i < mgp->num_slices; i++)
myri10ge_free_rings(&mgp->ss[i]);
mgp->running = MYRI10GE_ETH_STOPPED;
return 0;
}
static inline void
myri10ge_submit_req_backwards(struct myri10ge_tx_buf *tx,
struct mcp_kreq_ether_send *src, int cnt)
{
int idx, starting_slot;
starting_slot = tx->req;
while (cnt > 1) {
cnt--;
idx = (starting_slot + cnt) & tx->mask;
myri10ge_pio_copy(&tx->lanai[idx], &src[cnt], sizeof(*src));
mb();
}
}
static inline void
myri10ge_submit_req(struct myri10ge_tx_buf *tx, struct mcp_kreq_ether_send *src,
int cnt)
{
int idx, i;
struct mcp_kreq_ether_send __iomem *dstp, *dst;
struct mcp_kreq_ether_send *srcp;
u8 last_flags;
idx = tx->req & tx->mask;
last_flags = src->flags;
src->flags = 0;
mb();
dst = dstp = &tx->lanai[idx];
srcp = src;
if ((idx + cnt) < tx->mask) {
for (i = 0; i < (cnt - 1); i += 2) {
myri10ge_pio_copy(dstp, srcp, 2 * sizeof(*src));
mb();
srcp += 2;
dstp += 2;
}
} else {
myri10ge_submit_req_backwards(tx, src, cnt);
i = 0;
}
if (i < cnt) {
myri10ge_pio_copy(dstp, srcp, sizeof(*src));
mb();
}
src->flags = last_flags;
put_be32(*((__be32 *) src + 3), (__be32 __iomem *) dst + 3);
tx->req += cnt;
mb();
}
static netdev_tx_t myri10ge_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct myri10ge_priv *mgp = netdev_priv(dev);
struct myri10ge_slice_state *ss;
struct mcp_kreq_ether_send *req;
struct myri10ge_tx_buf *tx;
struct skb_frag_struct *frag;
struct netdev_queue *netdev_queue;
dma_addr_t bus;
u32 low;
__be32 high_swapped;
unsigned int len;
int idx, last_idx, avail, frag_cnt, frag_idx, count, mss, max_segments;
u16 pseudo_hdr_offset, cksum_offset, queue;
int cum_len, seglen, boundary, rdma_count;
u8 flags, odd_flag;
queue = skb_get_queue_mapping(skb);
ss = &mgp->ss[queue];
netdev_queue = netdev_get_tx_queue(mgp->dev, queue);
tx = &ss->tx;
again:
req = tx->req_list;
avail = tx->mask - 1 - (tx->req - tx->done);
mss = 0;
max_segments = MXGEFW_MAX_SEND_DESC;
if (skb_is_gso(skb)) {
mss = skb_shinfo(skb)->gso_size;
max_segments = MYRI10GE_MAX_SEND_DESC_TSO;
}
if ((unlikely(avail < max_segments))) {
tx->stop_queue++;
netif_tx_stop_queue(netdev_queue);
return NETDEV_TX_BUSY;
}
cksum_offset = 0;
pseudo_hdr_offset = 0;
odd_flag = 0;
flags = (MXGEFW_FLAGS_NO_TSO | MXGEFW_FLAGS_FIRST);
if (likely(skb->ip_summed == CHECKSUM_PARTIAL)) {
cksum_offset = skb_checksum_start_offset(skb);
pseudo_hdr_offset = cksum_offset + skb->csum_offset;
if (unlikely(!mss && (cksum_offset > 255 ||
pseudo_hdr_offset > 127))) {
if (skb_checksum_help(skb))
goto drop;
cksum_offset = 0;
pseudo_hdr_offset = 0;
} else {
odd_flag = MXGEFW_FLAGS_ALIGN_ODD;
flags |= MXGEFW_FLAGS_CKSUM;
}
}
cum_len = 0;
if (mss) {
flags = (MXGEFW_FLAGS_TSO_HDR | MXGEFW_FLAGS_FIRST);
cum_len = -(skb_transport_offset(skb) + tcp_hdrlen(skb));
if (skb_is_gso_v6(skb)) {
cksum_offset = tcp_hdrlen(skb);
if (unlikely(-cum_len > mgp->max_tso6))
return myri10ge_sw_tso(skb, dev);
}
pseudo_hdr_offset = mss;
} else
if (skb->len <= MXGEFW_SEND_SMALL_SIZE) {
flags |= MXGEFW_FLAGS_SMALL;
if (unlikely(skb->len < ETH_ZLEN)) {
if (skb_padto(skb, ETH_ZLEN)) {
ss->stats.tx_dropped += 1;
return NETDEV_TX_OK;
}
skb->len = ETH_ZLEN;
}
}
len = skb_headlen(skb);
idx = tx->req & tx->mask;
tx->info[idx].skb = skb;
bus = pci_map_single(mgp->pdev, skb->data, len, PCI_DMA_TODEVICE);
dma_unmap_addr_set(&tx->info[idx], bus, bus);
dma_unmap_len_set(&tx->info[idx], len, len);
frag_cnt = skb_shinfo(skb)->nr_frags;
frag_idx = 0;
count = 0;
rdma_count = 0;
while (1) {
low = MYRI10GE_LOWPART_TO_U32(bus);
high_swapped = htonl(MYRI10GE_HIGHPART_TO_U32(bus));
while (len) {
u8 flags_next;
int cum_len_next;
if (unlikely(count == max_segments))
goto abort_linearize;
boundary =
(low + mgp->tx_boundary) & ~(mgp->tx_boundary - 1);
seglen = boundary - low;
if (seglen > len)
seglen = len;
flags_next = flags & ~MXGEFW_FLAGS_FIRST;
cum_len_next = cum_len + seglen;
if (mss) {
(req - rdma_count)->rdma_count = rdma_count + 1;
if (likely(cum_len >= 0)) {
int next_is_first, chop;
chop = (cum_len_next > mss);
cum_len_next = cum_len_next % mss;
next_is_first = (cum_len_next == 0);
flags |= chop * MXGEFW_FLAGS_TSO_CHOP;
flags_next |= next_is_first *
MXGEFW_FLAGS_FIRST;
rdma_count |= -(chop | next_is_first);
rdma_count += chop & ~next_is_first;
} else if (likely(cum_len_next >= 0)) {
int small;
rdma_count = -1;
cum_len_next = 0;
seglen = -cum_len;
small = (mss <= MXGEFW_SEND_SMALL_SIZE);
flags_next = MXGEFW_FLAGS_TSO_PLD |
MXGEFW_FLAGS_FIRST |
(small * MXGEFW_FLAGS_SMALL);
}
}
req->addr_high = high_swapped;
req->addr_low = htonl(low);
req->pseudo_hdr_offset = htons(pseudo_hdr_offset);
req->pad = 0;
req->rdma_count = 1;
req->length = htons(seglen);
req->cksum_offset = cksum_offset;
req->flags = flags | ((cum_len & 1) * odd_flag);
low += seglen;
len -= seglen;
cum_len = cum_len_next;
flags = flags_next;
req++;
count++;
rdma_count++;
if (cksum_offset != 0 && !(mss && skb_is_gso_v6(skb))) {
if (unlikely(cksum_offset > seglen))
cksum_offset -= seglen;
else
cksum_offset = 0;
}
}
if (frag_idx == frag_cnt)
break;
idx = (count + tx->req) & tx->mask;
frag = &skb_shinfo(skb)->frags[frag_idx];
frag_idx++;
len = skb_frag_size(frag);
bus = skb_frag_dma_map(&mgp->pdev->dev, frag, 0, len,
DMA_TO_DEVICE);
dma_unmap_addr_set(&tx->info[idx], bus, bus);
dma_unmap_len_set(&tx->info[idx], len, len);
}
(req - rdma_count)->rdma_count = rdma_count;
if (mss)
do {
req--;
req->flags |= MXGEFW_FLAGS_TSO_LAST;
} while (!(req->flags & (MXGEFW_FLAGS_TSO_CHOP |
MXGEFW_FLAGS_FIRST)));
idx = ((count - 1) + tx->req) & tx->mask;
tx->info[idx].last = 1;
myri10ge_submit_req(tx, tx->req_list, count);
if ((mgp->dev->real_num_tx_queues > 1) && tx->queue_active == 0) {
tx->queue_active = 1;
put_be32(htonl(1), tx->send_go);
mb();
mmiowb();
}
tx->pkt_start++;
if ((avail - count) < MXGEFW_MAX_SEND_DESC) {
tx->stop_queue++;
netif_tx_stop_queue(netdev_queue);
}
return NETDEV_TX_OK;
abort_linearize:
last_idx = (idx + 1) & tx->mask;
idx = tx->req & tx->mask;
tx->info[idx].skb = NULL;
do {
len = dma_unmap_len(&tx->info[idx], len);
if (len) {
if (tx->info[idx].skb != NULL)
pci_unmap_single(mgp->pdev,
dma_unmap_addr(&tx->info[idx],
bus), len,
PCI_DMA_TODEVICE);
else
pci_unmap_page(mgp->pdev,
dma_unmap_addr(&tx->info[idx],
bus), len,
PCI_DMA_TODEVICE);
dma_unmap_len_set(&tx->info[idx], len, 0);
tx->info[idx].skb = NULL;
}
idx = (idx + 1) & tx->mask;
} while (idx != last_idx);
if (skb_is_gso(skb)) {
netdev_err(mgp->dev, "TSO but wanted to linearize?!?!?\n");
goto drop;
}
if (skb_linearize(skb))
goto drop;
tx->linearized++;
goto again;
drop:
dev_kfree_skb_any(skb);
ss->stats.tx_dropped += 1;
return NETDEV_TX_OK;
}
static netdev_tx_t myri10ge_sw_tso(struct sk_buff *skb,
struct net_device *dev)
{
struct sk_buff *segs, *curr;
struct myri10ge_priv *mgp = netdev_priv(dev);
struct myri10ge_slice_state *ss;
netdev_tx_t status;
segs = skb_gso_segment(skb, dev->features & ~NETIF_F_TSO6);
if (IS_ERR(segs))
goto drop;
while (segs) {
curr = segs;
segs = segs->next;
curr->next = NULL;
status = myri10ge_xmit(curr, dev);
if (status != 0) {
dev_kfree_skb_any(curr);
if (segs != NULL) {
curr = segs;
segs = segs->next;
curr->next = NULL;
dev_kfree_skb_any(segs);
}
goto drop;
}
}
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
drop:
ss = &mgp->ss[skb_get_queue_mapping(skb)];
dev_kfree_skb_any(skb);
ss->stats.tx_dropped += 1;
return NETDEV_TX_OK;
}
static struct rtnl_link_stats64 *myri10ge_get_stats(struct net_device *dev,
struct rtnl_link_stats64 *stats)
{
const struct myri10ge_priv *mgp = netdev_priv(dev);
const struct myri10ge_slice_netstats *slice_stats;
int i;
for (i = 0; i < mgp->num_slices; i++) {
slice_stats = &mgp->ss[i].stats;
stats->rx_packets += slice_stats->rx_packets;
stats->tx_packets += slice_stats->tx_packets;
stats->rx_bytes += slice_stats->rx_bytes;
stats->tx_bytes += slice_stats->tx_bytes;
stats->rx_dropped += slice_stats->rx_dropped;
stats->tx_dropped += slice_stats->tx_dropped;
}
return stats;
}
static void myri10ge_set_multicast_list(struct net_device *dev)
{
struct myri10ge_priv *mgp = netdev_priv(dev);
struct myri10ge_cmd cmd;
struct netdev_hw_addr *ha;
__be32 data[2] = { 0, 0 };
int err;
myri10ge_change_promisc(mgp, dev->flags & IFF_PROMISC, 1);
if (!mgp->fw_multicast_support)
return;
err = myri10ge_send_cmd(mgp, MXGEFW_ENABLE_ALLMULTI, &cmd, 1);
if (err != 0) {
netdev_err(dev, "Failed MXGEFW_ENABLE_ALLMULTI, error status: %d\n",
err);
goto abort;
}
if ((dev->flags & IFF_ALLMULTI) || mgp->adopted_rx_filter_bug) {
return;
}
err = myri10ge_send_cmd(mgp, MXGEFW_LEAVE_ALL_MULTICAST_GROUPS,
&cmd, 1);
if (err != 0) {
netdev_err(dev, "Failed MXGEFW_LEAVE_ALL_MULTICAST_GROUPS, error status: %d\n",
err);
goto abort;
}
netdev_for_each_mc_addr(ha, dev) {
memcpy(data, &ha->addr, ETH_ALEN);
cmd.data0 = ntohl(data[0]);
cmd.data1 = ntohl(data[1]);
err = myri10ge_send_cmd(mgp, MXGEFW_JOIN_MULTICAST_GROUP,
&cmd, 1);
if (err != 0) {
netdev_err(dev, "Failed MXGEFW_JOIN_MULTICAST_GROUP, error status:%d %pM\n",
err, ha->addr);
goto abort;
}
}
err = myri10ge_send_cmd(mgp, MXGEFW_DISABLE_ALLMULTI, &cmd, 1);
if (err != 0) {
netdev_err(dev, "Failed MXGEFW_DISABLE_ALLMULTI, error status: %d\n",
err);
goto abort;
}
return;
abort:
return;
}
static int myri10ge_set_mac_address(struct net_device *dev, void *addr)
{
struct sockaddr *sa = addr;
struct myri10ge_priv *mgp = netdev_priv(dev);
int status;
if (!is_valid_ether_addr(sa->sa_data))
return -EADDRNOTAVAIL;
status = myri10ge_update_mac_address(mgp, sa->sa_data);
if (status != 0) {
netdev_err(dev, "changing mac address failed with %d\n",
status);
return status;
}
memcpy(dev->dev_addr, sa->sa_data, ETH_ALEN);
return 0;
}
static int myri10ge_change_mtu(struct net_device *dev, int new_mtu)
{
struct myri10ge_priv *mgp = netdev_priv(dev);
int error = 0;
if ((new_mtu < 68) || (ETH_HLEN + new_mtu > MYRI10GE_MAX_ETHER_MTU)) {
netdev_err(dev, "new mtu (%d) is not valid\n", new_mtu);
return -EINVAL;
}
netdev_info(dev, "changing mtu from %d to %d\n", dev->mtu, new_mtu);
if (mgp->running) {
myri10ge_close(dev);
dev->mtu = new_mtu;
myri10ge_open(dev);
} else
dev->mtu = new_mtu;
return error;
}
static void myri10ge_enable_ecrc(struct myri10ge_priv *mgp)
{
struct pci_dev *bridge = mgp->pdev->bus->self;
struct device *dev = &mgp->pdev->dev;
int cap;
unsigned err_cap;
int ret;
if (!myri10ge_ecrc_enable || !bridge)
return;
if (pci_pcie_type(bridge) != PCI_EXP_TYPE_ROOT_PORT) {
if (myri10ge_ecrc_enable > 1) {
struct pci_dev *prev_bridge, *old_bridge = bridge;
do {
prev_bridge = bridge;
bridge = bridge->bus->self;
if (!bridge || prev_bridge == bridge) {
dev_err(dev,
"Failed to find root port"
" to force ECRC\n");
return;
}
} while (pci_pcie_type(bridge) !=
PCI_EXP_TYPE_ROOT_PORT);
dev_info(dev,
"Forcing ECRC on non-root port %s"
" (enabling on root port %s)\n",
pci_name(old_bridge), pci_name(bridge));
} else {
dev_err(dev,
"Not enabling ECRC on non-root port %s\n",
pci_name(bridge));
return;
}
}
cap = pci_find_ext_capability(bridge, PCI_EXT_CAP_ID_ERR);
if (!cap)
return;
ret = pci_read_config_dword(bridge, cap + PCI_ERR_CAP, &err_cap);
if (ret) {
dev_err(dev, "failed reading ext-conf-space of %s\n",
pci_name(bridge));
dev_err(dev, "\t pci=nommconf in use? "
"or buggy/incomplete/absent ACPI MCFG attr?\n");
return;
}
if (!(err_cap & PCI_ERR_CAP_ECRC_GENC))
return;
err_cap |= PCI_ERR_CAP_ECRC_GENE;
pci_write_config_dword(bridge, cap + PCI_ERR_CAP, err_cap);
dev_info(dev, "Enabled ECRC on upstream bridge %s\n", pci_name(bridge));
}
static void myri10ge_firmware_probe(struct myri10ge_priv *mgp)
{
struct pci_dev *pdev = mgp->pdev;
struct device *dev = &pdev->dev;
int status;
mgp->tx_boundary = 4096;
status = pcie_get_readrq(pdev);
if (status < 0) {
dev_err(dev, "Couldn't read max read req size: %d\n", status);
goto abort;
}
if (status != 4096) {
dev_warn(dev, "Max Read Request size != 4096 (%d)\n", status);
mgp->tx_boundary = 2048;
}
set_fw_name(mgp, myri10ge_fw_aligned, false);
status = myri10ge_load_firmware(mgp, 1);
if (status != 0) {
goto abort;
}
myri10ge_enable_ecrc(mgp);
status = myri10ge_dma_test(mgp, MXGEFW_CMD_UNALIGNED_TEST);
if (status == 0)
return;
if (status != -E2BIG)
dev_warn(dev, "DMA test failed: %d\n", status);
if (status == -ENOSYS)
dev_warn(dev, "Falling back to ethp! "
"Please install up to date fw\n");
abort:
mgp->tx_boundary = 2048;
set_fw_name(mgp, myri10ge_fw_unaligned, false);
}
static void myri10ge_select_firmware(struct myri10ge_priv *mgp)
{
int overridden = 0;
if (myri10ge_force_firmware == 0) {
int link_width;
u16 lnk;
pcie_capability_read_word(mgp->pdev, PCI_EXP_LNKSTA, &lnk);
link_width = (lnk >> 4) & 0x3f;
if (link_width < 8) {
dev_info(&mgp->pdev->dev, "PCIE x%d Link\n",
link_width);
mgp->tx_boundary = 4096;
set_fw_name(mgp, myri10ge_fw_aligned, false);
} else {
myri10ge_firmware_probe(mgp);
}
} else {
if (myri10ge_force_firmware == 1) {
dev_info(&mgp->pdev->dev,
"Assuming aligned completions (forced)\n");
mgp->tx_boundary = 4096;
set_fw_name(mgp, myri10ge_fw_aligned, false);
} else {
dev_info(&mgp->pdev->dev,
"Assuming unaligned completions (forced)\n");
mgp->tx_boundary = 2048;
set_fw_name(mgp, myri10ge_fw_unaligned, false);
}
}
kparam_block_sysfs_write(myri10ge_fw_name);
if (myri10ge_fw_name != NULL) {
char *fw_name = kstrdup(myri10ge_fw_name, GFP_KERNEL);
if (fw_name) {
overridden = 1;
set_fw_name(mgp, fw_name, true);
}
}
kparam_unblock_sysfs_write(myri10ge_fw_name);
if (mgp->board_number < MYRI10GE_MAX_BOARDS &&
myri10ge_fw_names[mgp->board_number] != NULL &&
strlen(myri10ge_fw_names[mgp->board_number])) {
set_fw_name(mgp, myri10ge_fw_names[mgp->board_number], false);
overridden = 1;
}
if (overridden)
dev_info(&mgp->pdev->dev, "overriding firmware to %s\n",
mgp->fw_name);
}
static void myri10ge_mask_surprise_down(struct pci_dev *pdev)
{
struct pci_dev *bridge = pdev->bus->self;
int cap;
u32 mask;
if (bridge == NULL)
return;
cap = pci_find_ext_capability(bridge, PCI_EXT_CAP_ID_ERR);
if (cap) {
pci_read_config_dword(bridge, cap + PCI_ERR_UNCOR_MASK, &mask);
mask |= 0x20;
pci_write_config_dword(bridge, cap + PCI_ERR_UNCOR_MASK, mask);
}
}
static int myri10ge_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct myri10ge_priv *mgp;
struct net_device *netdev;
mgp = pci_get_drvdata(pdev);
if (mgp == NULL)
return -EINVAL;
netdev = mgp->dev;
netif_device_detach(netdev);
if (netif_running(netdev)) {
netdev_info(netdev, "closing\n");
rtnl_lock();
myri10ge_close(netdev);
rtnl_unlock();
}
myri10ge_dummy_rdma(mgp, 0);
pci_save_state(pdev);
pci_disable_device(pdev);
return pci_set_power_state(pdev, pci_choose_state(pdev, state));
}
static int myri10ge_resume(struct pci_dev *pdev)
{
struct myri10ge_priv *mgp;
struct net_device *netdev;
int status;
u16 vendor;
mgp = pci_get_drvdata(pdev);
if (mgp == NULL)
return -EINVAL;
netdev = mgp->dev;
pci_set_power_state(pdev, PCI_D0);
msleep(5);
pci_read_config_word(mgp->pdev, PCI_VENDOR_ID, &vendor);
if (vendor == 0xffff) {
netdev_err(mgp->dev, "device disappeared!\n");
return -EIO;
}
pci_restore_state(pdev);
status = pci_enable_device(pdev);
if (status) {
dev_err(&pdev->dev, "failed to enable device\n");
return status;
}
pci_set_master(pdev);
myri10ge_reset(mgp);
myri10ge_dummy_rdma(mgp, 1);
pci_save_state(pdev);
if (netif_running(netdev)) {
rtnl_lock();
status = myri10ge_open(netdev);
rtnl_unlock();
if (status != 0)
goto abort_with_enabled;
}
netif_device_attach(netdev);
return 0;
abort_with_enabled:
pci_disable_device(pdev);
return -EIO;
}
static u32 myri10ge_read_reboot(struct myri10ge_priv *mgp)
{
struct pci_dev *pdev = mgp->pdev;
int vs = mgp->vendor_specific_offset;
u32 reboot;
pci_write_config_byte(pdev, vs + 0x10, 0x3);
pci_write_config_dword(pdev, vs + 0x18, 0xfffffff0);
pci_read_config_dword(pdev, vs + 0x14, &reboot);
return reboot;
}
static void
myri10ge_check_slice(struct myri10ge_slice_state *ss, int *reset_needed,
int *busy_slice_cnt, u32 rx_pause_cnt)
{
struct myri10ge_priv *mgp = ss->mgp;
int slice = ss - mgp->ss;
if (ss->tx.req != ss->tx.done &&
ss->tx.done == ss->watchdog_tx_done &&
ss->watchdog_tx_req != ss->watchdog_tx_done) {
if (rx_pause_cnt != mgp->watchdog_pause) {
if (net_ratelimit())
netdev_warn(mgp->dev, "slice %d: TX paused, "
"check link partner\n", slice);
} else {
netdev_warn(mgp->dev,
"slice %d: TX stuck %d %d %d %d %d %d\n",
slice, ss->tx.queue_active, ss->tx.req,
ss->tx.done, ss->tx.pkt_start,
ss->tx.pkt_done,
(int)ntohl(mgp->ss[slice].fw_stats->
send_done_count));
*reset_needed = 1;
ss->stuck = 1;
}
}
if (ss->watchdog_tx_done != ss->tx.done ||
ss->watchdog_rx_done != ss->rx_done.cnt) {
*busy_slice_cnt += 1;
}
ss->watchdog_tx_done = ss->tx.done;
ss->watchdog_tx_req = ss->tx.req;
ss->watchdog_rx_done = ss->rx_done.cnt;
}
static void myri10ge_watchdog(struct work_struct *work)
{
struct myri10ge_priv *mgp =
container_of(work, struct myri10ge_priv, watchdog_work);
struct myri10ge_slice_state *ss;
u32 reboot, rx_pause_cnt;
int status, rebooted;
int i;
int reset_needed = 0;
int busy_slice_cnt = 0;
u16 cmd, vendor;
mgp->watchdog_resets++;
pci_read_config_word(mgp->pdev, PCI_COMMAND, &cmd);
rebooted = 0;
if ((cmd & PCI_COMMAND_MASTER) == 0) {
reboot = myri10ge_read_reboot(mgp);
netdev_err(mgp->dev, "NIC rebooted (0x%x),%s resetting\n",
reboot, myri10ge_reset_recover ? "" : " not");
if (myri10ge_reset_recover == 0)
return;
rtnl_lock();
mgp->rebooted = 1;
rebooted = 1;
myri10ge_close(mgp->dev);
myri10ge_reset_recover--;
mgp->rebooted = 0;
pci_restore_state(mgp->pdev);
pci_save_state(mgp->pdev);
} else {
if (cmd == 0xffff) {
pci_read_config_word(mgp->pdev, PCI_VENDOR_ID, &vendor);
if (vendor == 0xffff) {
netdev_err(mgp->dev, "device disappeared!\n");
return;
}
}
rx_pause_cnt = ntohl(mgp->ss[0].fw_stats->dropped_pause);
for (i = 0; i < mgp->num_slices; i++) {
ss = mgp->ss;
if (ss->stuck) {
myri10ge_check_slice(ss, &reset_needed,
&busy_slice_cnt,
rx_pause_cnt);
ss->stuck = 0;
}
}
if (!reset_needed) {
netdev_dbg(mgp->dev, "not resetting\n");
return;
}
netdev_err(mgp->dev, "device timeout, resetting\n");
}
if (!rebooted) {
rtnl_lock();
myri10ge_close(mgp->dev);
}
status = myri10ge_load_firmware(mgp, 1);
if (status != 0)
netdev_err(mgp->dev, "failed to load firmware\n");
else
myri10ge_open(mgp->dev);
rtnl_unlock();
}
static void myri10ge_watchdog_timer(unsigned long arg)
{
struct myri10ge_priv *mgp;
struct myri10ge_slice_state *ss;
int i, reset_needed, busy_slice_cnt;
u32 rx_pause_cnt;
u16 cmd;
mgp = (struct myri10ge_priv *)arg;
rx_pause_cnt = ntohl(mgp->ss[0].fw_stats->dropped_pause);
busy_slice_cnt = 0;
for (i = 0, reset_needed = 0;
i < mgp->num_slices && reset_needed == 0; ++i) {
ss = &mgp->ss[i];
if (ss->rx_small.watchdog_needed) {
myri10ge_alloc_rx_pages(mgp, &ss->rx_small,
mgp->small_bytes + MXGEFW_PAD,
1);
if (ss->rx_small.fill_cnt - ss->rx_small.cnt >=
myri10ge_fill_thresh)
ss->rx_small.watchdog_needed = 0;
}
if (ss->rx_big.watchdog_needed) {
myri10ge_alloc_rx_pages(mgp, &ss->rx_big,
mgp->big_bytes, 1);
if (ss->rx_big.fill_cnt - ss->rx_big.cnt >=
myri10ge_fill_thresh)
ss->rx_big.watchdog_needed = 0;
}
myri10ge_check_slice(ss, &reset_needed, &busy_slice_cnt,
rx_pause_cnt);
}
if (busy_slice_cnt == 0) {
pci_read_config_word(mgp->pdev, PCI_COMMAND, &cmd);
if ((cmd & PCI_COMMAND_MASTER) == 0) {
reset_needed = 1;
}
}
mgp->watchdog_pause = rx_pause_cnt;
if (reset_needed) {
schedule_work(&mgp->watchdog_work);
} else {
mod_timer(&mgp->watchdog_timer,
jiffies + myri10ge_watchdog_timeout * HZ);
}
}
static void myri10ge_free_slices(struct myri10ge_priv *mgp)
{
struct myri10ge_slice_state *ss;
struct pci_dev *pdev = mgp->pdev;
size_t bytes;
int i;
if (mgp->ss == NULL)
return;
for (i = 0; i < mgp->num_slices; i++) {
ss = &mgp->ss[i];
if (ss->rx_done.entry != NULL) {
bytes = mgp->max_intr_slots *
sizeof(*ss->rx_done.entry);
dma_free_coherent(&pdev->dev, bytes,
ss->rx_done.entry, ss->rx_done.bus);
ss->rx_done.entry = NULL;
}
if (ss->fw_stats != NULL) {
bytes = sizeof(*ss->fw_stats);
dma_free_coherent(&pdev->dev, bytes,
ss->fw_stats, ss->fw_stats_bus);
ss->fw_stats = NULL;
}
napi_hash_del(&ss->napi);
netif_napi_del(&ss->napi);
}
synchronize_rcu();
kfree(mgp->ss);
mgp->ss = NULL;
}
static int myri10ge_alloc_slices(struct myri10ge_priv *mgp)
{
struct myri10ge_slice_state *ss;
struct pci_dev *pdev = mgp->pdev;
size_t bytes;
int i;
bytes = sizeof(*mgp->ss) * mgp->num_slices;
mgp->ss = kzalloc(bytes, GFP_KERNEL);
if (mgp->ss == NULL) {
return -ENOMEM;
}
for (i = 0; i < mgp->num_slices; i++) {
ss = &mgp->ss[i];
bytes = mgp->max_intr_slots * sizeof(*ss->rx_done.entry);
ss->rx_done.entry = dma_zalloc_coherent(&pdev->dev, bytes,
&ss->rx_done.bus,
GFP_KERNEL);
if (ss->rx_done.entry == NULL)
goto abort;
bytes = sizeof(*ss->fw_stats);
ss->fw_stats = dma_alloc_coherent(&pdev->dev, bytes,
&ss->fw_stats_bus,
GFP_KERNEL);
if (ss->fw_stats == NULL)
goto abort;
ss->mgp = mgp;
ss->dev = mgp->dev;
netif_napi_add(ss->dev, &ss->napi, myri10ge_poll,
myri10ge_napi_weight);
napi_hash_add(&ss->napi);
}
return 0;
abort:
myri10ge_free_slices(mgp);
return -ENOMEM;
}
static void myri10ge_probe_slices(struct myri10ge_priv *mgp)
{
struct myri10ge_cmd cmd;
struct pci_dev *pdev = mgp->pdev;
char *old_fw;
bool old_allocated;
int i, status, ncpus;
mgp->num_slices = 1;
ncpus = netif_get_num_default_rss_queues();
if (myri10ge_max_slices == 1 || !pdev->msix_cap ||
(myri10ge_max_slices == -1 && ncpus < 2))
return;
old_fw = mgp->fw_name;
old_allocated = mgp->fw_name_allocated;
mgp->fw_name_allocated = false;
if (myri10ge_fw_name != NULL) {
dev_info(&mgp->pdev->dev, "overriding rss firmware to %s\n",
myri10ge_fw_name);
set_fw_name(mgp, myri10ge_fw_name, false);
} else if (old_fw == myri10ge_fw_aligned)
set_fw_name(mgp, myri10ge_fw_rss_aligned, false);
else
set_fw_name(mgp, myri10ge_fw_rss_unaligned, false);
status = myri10ge_load_firmware(mgp, 0);
if (status != 0) {
dev_info(&pdev->dev, "Rss firmware not found\n");
if (old_allocated)
kfree(old_fw);
return;
}
memset(&cmd, 0, sizeof(cmd));
status = myri10ge_send_cmd(mgp, MXGEFW_CMD_RESET, &cmd, 0);
if (status != 0) {
dev_err(&mgp->pdev->dev, "failed reset\n");
goto abort_with_fw;
}
mgp->max_intr_slots = cmd.data0 / sizeof(struct mcp_slot);
cmd.data0 = mgp->max_intr_slots * sizeof(struct mcp_slot);
status = myri10ge_send_cmd(mgp, MXGEFW_CMD_SET_INTRQ_SIZE, &cmd, 0);
if (status != 0) {
dev_err(&mgp->pdev->dev, "failed MXGEFW_CMD_SET_INTRQ_SIZE\n");
goto abort_with_fw;
}
status = myri10ge_send_cmd(mgp, MXGEFW_CMD_GET_MAX_RSS_QUEUES, &cmd, 0);
if (status != 0)
goto abort_with_fw;
else
mgp->num_slices = cmd.data0;
if (!myri10ge_msi) {
goto abort_with_fw;
}
if (myri10ge_max_slices == -1)
myri10ge_max_slices = ncpus;
if (mgp->num_slices > myri10ge_max_slices)
mgp->num_slices = myri10ge_max_slices;
mgp->msix_vectors = kcalloc(mgp->num_slices, sizeof(*mgp->msix_vectors),
GFP_KERNEL);
if (mgp->msix_vectors == NULL)
goto no_msix;
for (i = 0; i < mgp->num_slices; i++) {
mgp->msix_vectors[i].entry = i;
}
while (mgp->num_slices > 1) {
mgp->num_slices = rounddown_pow_of_two(mgp->num_slices);
if (mgp->num_slices == 1)
goto no_msix;
status = pci_enable_msix_range(pdev,
mgp->msix_vectors,
mgp->num_slices,
mgp->num_slices);
if (status < 0)
goto no_msix;
pci_disable_msix(pdev);
if (status == mgp->num_slices) {
if (old_allocated)
kfree(old_fw);
return;
} else {
mgp->num_slices = status;
}
}
no_msix:
if (mgp->msix_vectors != NULL) {
kfree(mgp->msix_vectors);
mgp->msix_vectors = NULL;
}
abort_with_fw:
mgp->num_slices = 1;
set_fw_name(mgp, old_fw, old_allocated);
myri10ge_load_firmware(mgp, 0);
}
static int myri10ge_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct net_device *netdev;
struct myri10ge_priv *mgp;
struct device *dev = &pdev->dev;
int i;
int status = -ENXIO;
int dac_enabled;
unsigned hdr_offset, ss_offset;
static int board_number;
netdev = alloc_etherdev_mq(sizeof(*mgp), MYRI10GE_MAX_SLICES);
if (netdev == NULL)
return -ENOMEM;
SET_NETDEV_DEV(netdev, &pdev->dev);
mgp = netdev_priv(netdev);
mgp->dev = netdev;
mgp->pdev = pdev;
mgp->pause = myri10ge_flow_control;
mgp->intr_coal_delay = myri10ge_intr_coal_delay;
mgp->msg_enable = netif_msg_init(myri10ge_debug, MYRI10GE_MSG_DEFAULT);
mgp->board_number = board_number;
init_waitqueue_head(&mgp->down_wq);
if (pci_enable_device(pdev)) {
dev_err(&pdev->dev, "pci_enable_device call failed\n");
status = -ENODEV;
goto abort_with_netdev;
}
mgp->vendor_specific_offset
= pci_find_capability(pdev, PCI_CAP_ID_VNDR);
status = pcie_set_readrq(pdev, 4096);
if (status != 0) {
dev_err(&pdev->dev, "Error %d writing PCI_EXP_DEVCTL\n",
status);
goto abort_with_enabled;
}
myri10ge_mask_surprise_down(pdev);
pci_set_master(pdev);
dac_enabled = 1;
status = pci_set_dma_mask(pdev, DMA_BIT_MASK(64));
if (status != 0) {
dac_enabled = 0;
dev_err(&pdev->dev,
"64-bit pci address mask was refused, "
"trying 32-bit\n");
status = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
}
if (status != 0) {
dev_err(&pdev->dev, "Error %d setting DMA mask\n", status);
goto abort_with_enabled;
}
(void)pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64));
mgp->cmd = dma_alloc_coherent(&pdev->dev, sizeof(*mgp->cmd),
&mgp->cmd_bus, GFP_KERNEL);
if (mgp->cmd == NULL)
goto abort_with_enabled;
mgp->board_span = pci_resource_len(pdev, 0);
mgp->iomem_base = pci_resource_start(pdev, 0);
mgp->mtrr = -1;
mgp->wc_enabled = 0;
#ifdef CONFIG_MTRR
mgp->mtrr = mtrr_add(mgp->iomem_base, mgp->board_span,
MTRR_TYPE_WRCOMB, 1);
if (mgp->mtrr >= 0)
mgp->wc_enabled = 1;
#endif
mgp->sram = ioremap_wc(mgp->iomem_base, mgp->board_span);
if (mgp->sram == NULL) {
dev_err(&pdev->dev, "ioremap failed for %ld bytes at 0x%lx\n",
mgp->board_span, mgp->iomem_base);
status = -ENXIO;
goto abort_with_mtrr;
}
hdr_offset =
swab32(readl(mgp->sram + MCP_HEADER_PTR_OFFSET)) & 0xffffc;
ss_offset = hdr_offset + offsetof(struct mcp_gen_header, string_specs);
mgp->sram_size = swab32(readl(mgp->sram + ss_offset));
if (mgp->sram_size > mgp->board_span ||
mgp->sram_size <= MYRI10GE_FW_OFFSET) {
dev_err(&pdev->dev,
"invalid sram_size %dB or board span %ldB\n",
mgp->sram_size, mgp->board_span);
goto abort_with_ioremap;
}
memcpy_fromio(mgp->eeprom_strings,
mgp->sram + mgp->sram_size, MYRI10GE_EEPROM_STRINGS_SIZE);
memset(mgp->eeprom_strings + MYRI10GE_EEPROM_STRINGS_SIZE - 2, 0, 2);
status = myri10ge_read_mac_addr(mgp);
if (status)
goto abort_with_ioremap;
for (i = 0; i < ETH_ALEN; i++)
netdev->dev_addr[i] = mgp->mac_addr[i];
myri10ge_select_firmware(mgp);
status = myri10ge_load_firmware(mgp, 1);
if (status != 0) {
dev_err(&pdev->dev, "failed to load firmware\n");
goto abort_with_ioremap;
}
myri10ge_probe_slices(mgp);
status = myri10ge_alloc_slices(mgp);
if (status != 0) {
dev_err(&pdev->dev, "failed to alloc slice state\n");
goto abort_with_firmware;
}
netif_set_real_num_tx_queues(netdev, mgp->num_slices);
netif_set_real_num_rx_queues(netdev, mgp->num_slices);
status = myri10ge_reset(mgp);
if (status != 0) {
dev_err(&pdev->dev, "failed reset\n");
goto abort_with_slices;
}
#ifdef CONFIG_MYRI10GE_DCA
myri10ge_setup_dca(mgp);
#endif
pci_set_drvdata(pdev, mgp);
if ((myri10ge_initial_mtu + ETH_HLEN) > MYRI10GE_MAX_ETHER_MTU)
myri10ge_initial_mtu = MYRI10GE_MAX_ETHER_MTU - ETH_HLEN;
if ((myri10ge_initial_mtu + ETH_HLEN) < 68)
myri10ge_initial_mtu = 68;
netdev->netdev_ops = &myri10ge_netdev_ops;
netdev->mtu = myri10ge_initial_mtu;
netdev->hw_features = mgp->features | NETIF_F_RXCSUM;
netdev->hw_features |= NETIF_F_HW_VLAN_CTAG_RX;
netdev->features = netdev->hw_features;
if (dac_enabled)
netdev->features |= NETIF_F_HIGHDMA;
netdev->vlan_features |= mgp->features;
if (mgp->fw_ver_tiny < 37)
netdev->vlan_features &= ~NETIF_F_TSO6;
if (mgp->fw_ver_tiny < 32)
netdev->vlan_features &= ~NETIF_F_TSO;
status = myri10ge_request_irq(mgp);
if (status != 0)
goto abort_with_firmware;
myri10ge_free_irq(mgp);
pci_save_state(pdev);
setup_timer(&mgp->watchdog_timer, myri10ge_watchdog_timer,
(unsigned long)mgp);
SET_ETHTOOL_OPS(netdev, &myri10ge_ethtool_ops);
INIT_WORK(&mgp->watchdog_work, myri10ge_watchdog);
status = register_netdev(netdev);
if (status != 0) {
dev_err(&pdev->dev, "register_netdev failed: %d\n", status);
goto abort_with_state;
}
if (mgp->msix_enabled)
dev_info(dev, "%d MSI-X IRQs, tx bndry %d, fw %s, WC %s\n",
mgp->num_slices, mgp->tx_boundary, mgp->fw_name,
(mgp->wc_enabled ? "Enabled" : "Disabled"));
else
dev_info(dev, "%s IRQ %d, tx bndry %d, fw %s, WC %s\n",
mgp->msi_enabled ? "MSI" : "xPIC",
pdev->irq, mgp->tx_boundary, mgp->fw_name,
(mgp->wc_enabled ? "Enabled" : "Disabled"));
board_number++;
return 0;
abort_with_state:
pci_restore_state(pdev);
abort_with_slices:
myri10ge_free_slices(mgp);
abort_with_firmware:
myri10ge_dummy_rdma(mgp, 0);
abort_with_ioremap:
if (mgp->mac_addr_string != NULL)
dev_err(&pdev->dev,
"myri10ge_probe() failed: MAC=%s, SN=%ld\n",
mgp->mac_addr_string, mgp->serial_number);
iounmap(mgp->sram);
abort_with_mtrr:
#ifdef CONFIG_MTRR
if (mgp->mtrr >= 0)
mtrr_del(mgp->mtrr, mgp->iomem_base, mgp->board_span);
#endif
dma_free_coherent(&pdev->dev, sizeof(*mgp->cmd),
mgp->cmd, mgp->cmd_bus);
abort_with_enabled:
pci_disable_device(pdev);
abort_with_netdev:
set_fw_name(mgp, NULL, false);
free_netdev(netdev);
return status;
}
static void myri10ge_remove(struct pci_dev *pdev)
{
struct myri10ge_priv *mgp;
struct net_device *netdev;
mgp = pci_get_drvdata(pdev);
if (mgp == NULL)
return;
cancel_work_sync(&mgp->watchdog_work);
netdev = mgp->dev;
unregister_netdev(netdev);
#ifdef CONFIG_MYRI10GE_DCA
myri10ge_teardown_dca(mgp);
#endif
myri10ge_dummy_rdma(mgp, 0);
pci_restore_state(pdev);
iounmap(mgp->sram);
#ifdef CONFIG_MTRR
if (mgp->mtrr >= 0)
mtrr_del(mgp->mtrr, mgp->iomem_base, mgp->board_span);
#endif
myri10ge_free_slices(mgp);
if (mgp->msix_vectors != NULL)
kfree(mgp->msix_vectors);
dma_free_coherent(&pdev->dev, sizeof(*mgp->cmd),
mgp->cmd, mgp->cmd_bus);
set_fw_name(mgp, NULL, false);
free_netdev(netdev);
pci_disable_device(pdev);
}
static int
myri10ge_notify_dca(struct notifier_block *nb, unsigned long event, void *p)
{
int err = driver_for_each_device(&myri10ge_driver.driver,
NULL, &event,
myri10ge_notify_dca_device);
if (err)
return NOTIFY_BAD;
return NOTIFY_DONE;
}
static __init int myri10ge_init_module(void)
{
pr_info("Version %s\n", MYRI10GE_VERSION_STR);
if (myri10ge_rss_hash > MXGEFW_RSS_HASH_TYPE_MAX) {
pr_err("Illegal rssh hash type %d, defaulting to source port\n",
myri10ge_rss_hash);
myri10ge_rss_hash = MXGEFW_RSS_HASH_TYPE_SRC_PORT;
}
#ifdef CONFIG_MYRI10GE_DCA
dca_register_notify(&myri10ge_dca_notifier);
#endif
if (myri10ge_max_slices > MYRI10GE_MAX_SLICES)
myri10ge_max_slices = MYRI10GE_MAX_SLICES;
return pci_register_driver(&myri10ge_driver);
}
static __exit void myri10ge_cleanup_module(void)
{
#ifdef CONFIG_MYRI10GE_DCA
dca_unregister_notify(&myri10ge_dca_notifier);
#endif
pci_unregister_driver(&myri10ge_driver);
}
