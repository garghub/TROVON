static inline u32 mei_txe_reg_read(void __iomem *base_addr,
unsigned long offset)
{
return ioread32(base_addr + offset);
}
static inline void mei_txe_reg_write(void __iomem *base_addr,
unsigned long offset, u32 value)
{
iowrite32(value, base_addr + offset);
}
static inline u32 mei_txe_sec_reg_read_silent(struct mei_txe_hw *hw,
unsigned long offset)
{
return mei_txe_reg_read(hw->mem_addr[SEC_BAR], offset);
}
static inline u32 mei_txe_sec_reg_read(struct mei_txe_hw *hw,
unsigned long offset)
{
WARN(!hw->aliveness, "sec read: aliveness not asserted\n");
return mei_txe_sec_reg_read_silent(hw, offset);
}
static inline void mei_txe_sec_reg_write_silent(struct mei_txe_hw *hw,
unsigned long offset, u32 value)
{
mei_txe_reg_write(hw->mem_addr[SEC_BAR], offset, value);
}
static inline void mei_txe_sec_reg_write(struct mei_txe_hw *hw,
unsigned long offset, u32 value)
{
WARN(!hw->aliveness, "sec write: aliveness not asserted\n");
mei_txe_sec_reg_write_silent(hw, offset, value);
}
static inline u32 mei_txe_br_reg_read(struct mei_txe_hw *hw,
unsigned long offset)
{
return mei_txe_reg_read(hw->mem_addr[BRIDGE_BAR], offset);
}
static inline void mei_txe_br_reg_write(struct mei_txe_hw *hw,
unsigned long offset, u32 value)
{
mei_txe_reg_write(hw->mem_addr[BRIDGE_BAR], offset, value);
}
static bool mei_txe_aliveness_set(struct mei_device *dev, u32 req)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
bool do_req = hw->aliveness != req;
dev_dbg(dev->dev, "Aliveness current=%d request=%d\n",
hw->aliveness, req);
if (do_req) {
dev->pg_event = MEI_PG_EVENT_WAIT;
mei_txe_br_reg_write(hw, SICR_HOST_ALIVENESS_REQ_REG, req);
}
return do_req;
}
static u32 mei_txe_aliveness_req_get(struct mei_device *dev)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
u32 reg;
reg = mei_txe_br_reg_read(hw, SICR_HOST_ALIVENESS_REQ_REG);
return reg & SICR_HOST_ALIVENESS_REQ_REQUESTED;
}
static u32 mei_txe_aliveness_get(struct mei_device *dev)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
u32 reg;
reg = mei_txe_br_reg_read(hw, HICR_HOST_ALIVENESS_RESP_REG);
return reg & HICR_HOST_ALIVENESS_RESP_ACK;
}
static int mei_txe_aliveness_poll(struct mei_device *dev, u32 expected)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
int t = 0;
do {
hw->aliveness = mei_txe_aliveness_get(dev);
if (hw->aliveness == expected) {
dev->pg_event = MEI_PG_EVENT_IDLE;
dev_dbg(dev->dev,
"aliveness settled after %d msecs\n", t);
return t;
}
mutex_unlock(&dev->device_lock);
msleep(MSEC_PER_SEC / 5);
mutex_lock(&dev->device_lock);
t += MSEC_PER_SEC / 5;
} while (t < SEC_ALIVENESS_WAIT_TIMEOUT);
dev->pg_event = MEI_PG_EVENT_IDLE;
dev_err(dev->dev, "aliveness timed out\n");
return -ETIME;
}
static int mei_txe_aliveness_wait(struct mei_device *dev, u32 expected)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
const unsigned long timeout =
msecs_to_jiffies(SEC_ALIVENESS_WAIT_TIMEOUT);
long err;
int ret;
hw->aliveness = mei_txe_aliveness_get(dev);
if (hw->aliveness == expected)
return 0;
mutex_unlock(&dev->device_lock);
err = wait_event_timeout(hw->wait_aliveness_resp,
dev->pg_event == MEI_PG_EVENT_RECEIVED, timeout);
mutex_lock(&dev->device_lock);
hw->aliveness = mei_txe_aliveness_get(dev);
ret = hw->aliveness == expected ? 0 : -ETIME;
if (ret)
dev_warn(dev->dev, "aliveness timed out = %ld aliveness = %d event = %d\n",
err, hw->aliveness, dev->pg_event);
else
dev_dbg(dev->dev, "aliveness settled after = %d msec aliveness = %d event = %d\n",
jiffies_to_msecs(timeout - err),
hw->aliveness, dev->pg_event);
dev->pg_event = MEI_PG_EVENT_IDLE;
return ret;
}
int mei_txe_aliveness_set_sync(struct mei_device *dev, u32 req)
{
if (mei_txe_aliveness_set(dev, req))
return mei_txe_aliveness_wait(dev, req);
return 0;
}
static bool mei_txe_pg_is_enabled(struct mei_device *dev)
{
return true;
}
static inline enum mei_pg_state mei_txe_pg_state(struct mei_device *dev)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
return hw->aliveness ? MEI_PG_OFF : MEI_PG_ON;
}
static void mei_txe_input_ready_interrupt_enable(struct mei_device *dev)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
u32 hintmsk;
hintmsk = mei_txe_sec_reg_read(hw, SEC_IPC_HOST_INT_MASK_REG);
hintmsk |= SEC_IPC_HOST_INT_MASK_IN_RDY;
mei_txe_sec_reg_write(hw, SEC_IPC_HOST_INT_MASK_REG, hintmsk);
}
static void mei_txe_input_doorbell_set(struct mei_txe_hw *hw)
{
clear_bit(TXE_INTR_IN_READY_BIT, &hw->intr_cause);
mei_txe_sec_reg_write(hw, SEC_IPC_INPUT_DOORBELL_REG, 1);
}
static void mei_txe_output_ready_set(struct mei_txe_hw *hw)
{
mei_txe_br_reg_write(hw,
SICR_SEC_IPC_OUTPUT_STATUS_REG,
SEC_IPC_OUTPUT_STATUS_RDY);
}
static bool mei_txe_is_input_ready(struct mei_device *dev)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
u32 status;
status = mei_txe_sec_reg_read(hw, SEC_IPC_INPUT_STATUS_REG);
return !!(SEC_IPC_INPUT_STATUS_RDY & status);
}
static inline void mei_txe_intr_clear(struct mei_device *dev)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
mei_txe_sec_reg_write_silent(hw, SEC_IPC_HOST_INT_STATUS_REG,
SEC_IPC_HOST_INT_STATUS_PENDING);
mei_txe_br_reg_write(hw, HISR_REG, HISR_INT_STS_MSK);
mei_txe_br_reg_write(hw, HHISR_REG, IPC_HHIER_MSK);
}
static void mei_txe_intr_disable(struct mei_device *dev)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
mei_txe_br_reg_write(hw, HHIER_REG, 0);
mei_txe_br_reg_write(hw, HIER_REG, 0);
}
static void mei_txe_intr_enable(struct mei_device *dev)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
mei_txe_br_reg_write(hw, HHIER_REG, IPC_HHIER_MSK);
mei_txe_br_reg_write(hw, HIER_REG, HIER_INT_EN_MSK);
}
static bool mei_txe_pending_interrupts(struct mei_device *dev)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
bool ret = (hw->intr_cause & (TXE_INTR_READINESS |
TXE_INTR_ALIVENESS |
TXE_INTR_IN_READY |
TXE_INTR_OUT_DB));
if (ret) {
dev_dbg(dev->dev,
"Pending Interrupts InReady=%01d Readiness=%01d, Aliveness=%01d, OutDoor=%01d\n",
!!(hw->intr_cause & TXE_INTR_IN_READY),
!!(hw->intr_cause & TXE_INTR_READINESS),
!!(hw->intr_cause & TXE_INTR_ALIVENESS),
!!(hw->intr_cause & TXE_INTR_OUT_DB));
}
return ret;
}
static void mei_txe_input_payload_write(struct mei_device *dev,
unsigned long idx, u32 value)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
mei_txe_sec_reg_write(hw, SEC_IPC_INPUT_PAYLOAD_REG +
(idx * sizeof(u32)), value);
}
static u32 mei_txe_out_data_read(const struct mei_device *dev,
unsigned long idx)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
return mei_txe_br_reg_read(hw,
BRIDGE_IPC_OUTPUT_PAYLOAD_REG + (idx * sizeof(u32)));
}
static void mei_txe_readiness_set_host_rdy(struct mei_device *dev)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
mei_txe_br_reg_write(hw,
SICR_HOST_IPC_READINESS_REQ_REG,
SICR_HOST_IPC_READINESS_HOST_RDY);
}
static void mei_txe_readiness_clear(struct mei_device *dev)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
mei_txe_br_reg_write(hw, SICR_HOST_IPC_READINESS_REQ_REG,
SICR_HOST_IPC_READINESS_RDY_CLR);
}
static u32 mei_txe_readiness_get(struct mei_device *dev)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
return mei_txe_br_reg_read(hw, HICR_SEC_IPC_READINESS_REG);
}
static inline bool mei_txe_readiness_is_sec_rdy(u32 readiness)
{
return !!(readiness & HICR_SEC_IPC_READINESS_SEC_RDY);
}
static bool mei_txe_hw_is_ready(struct mei_device *dev)
{
u32 readiness = mei_txe_readiness_get(dev);
return mei_txe_readiness_is_sec_rdy(readiness);
}
static inline bool mei_txe_host_is_ready(struct mei_device *dev)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
u32 reg = mei_txe_br_reg_read(hw, HICR_SEC_IPC_READINESS_REG);
return !!(reg & HICR_SEC_IPC_READINESS_HOST_RDY);
}
static int mei_txe_readiness_wait(struct mei_device *dev)
{
if (mei_txe_hw_is_ready(dev))
return 0;
mutex_unlock(&dev->device_lock);
wait_event_timeout(dev->wait_hw_ready, dev->recvd_hw_ready,
msecs_to_jiffies(SEC_RESET_WAIT_TIMEOUT));
mutex_lock(&dev->device_lock);
if (!dev->recvd_hw_ready) {
dev_err(dev->dev, "wait for readiness failed\n");
return -ETIME;
}
dev->recvd_hw_ready = false;
return 0;
}
static int mei_txe_fw_status(struct mei_device *dev,
struct mei_fw_status *fw_status)
{
const struct mei_fw_status *fw_src = &mei_txe_fw_sts;
struct pci_dev *pdev = to_pci_dev(dev->dev);
int ret;
int i;
if (!fw_status)
return -EINVAL;
fw_status->count = fw_src->count;
for (i = 0; i < fw_src->count && i < MEI_FW_STATUS_MAX; i++) {
ret = pci_read_config_dword(pdev,
fw_src->status[i], &fw_status->status[i]);
if (ret)
return ret;
}
return 0;
}
static void mei_txe_hw_config(struct mei_device *dev)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
dev->hbuf_depth = PAYLOAD_SIZE / 4;
hw->aliveness = mei_txe_aliveness_get(dev);
hw->readiness = mei_txe_readiness_get(dev);
dev_dbg(dev->dev, "aliveness_resp = 0x%08x, readiness = 0x%08x.\n",
hw->aliveness, hw->readiness);
}
static int mei_txe_write(struct mei_device *dev,
struct mei_msg_hdr *header, unsigned char *buf)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
unsigned long rem;
unsigned long length;
int slots = dev->hbuf_depth;
u32 *reg_buf = (u32 *)buf;
u32 dw_cnt;
int i;
if (WARN_ON(!header || !buf))
return -EINVAL;
length = header->length;
dev_dbg(dev->dev, MEI_HDR_FMT, MEI_HDR_PRM(header));
dw_cnt = mei_data2slots(length);
if (dw_cnt > slots)
return -EMSGSIZE;
if (WARN(!hw->aliveness, "txe write: aliveness not asserted\n"))
return -EAGAIN;
mei_txe_input_ready_interrupt_enable(dev);
if (!mei_txe_is_input_ready(dev)) {
char fw_sts_str[MEI_FW_STATUS_STR_SZ];
mei_fw_status_str(dev, fw_sts_str, MEI_FW_STATUS_STR_SZ);
dev_err(dev->dev, "Input is not ready %s\n", fw_sts_str);
return -EAGAIN;
}
mei_txe_input_payload_write(dev, 0, *((u32 *)header));
for (i = 0; i < length / 4; i++)
mei_txe_input_payload_write(dev, i + 1, reg_buf[i]);
rem = length & 0x3;
if (rem > 0) {
u32 reg = 0;
memcpy(&reg, &buf[length - rem], rem);
mei_txe_input_payload_write(dev, i + 1, reg);
}
hw->slots = 0;
mei_txe_input_doorbell_set(hw);
return 0;
}
static size_t mei_txe_hbuf_max_len(const struct mei_device *dev)
{
return PAYLOAD_SIZE - sizeof(struct mei_msg_hdr);
}
static int mei_txe_hbuf_empty_slots(struct mei_device *dev)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
return hw->slots;
}
static int mei_txe_count_full_read_slots(struct mei_device *dev)
{
return PAYLOAD_SIZE / 4;
}
static u32 mei_txe_read_hdr(const struct mei_device *dev)
{
return mei_txe_out_data_read(dev, 0);
}
static int mei_txe_read(struct mei_device *dev,
unsigned char *buf, unsigned long len)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
u32 *reg_buf, reg;
u32 rem;
u32 i;
if (WARN_ON(!buf || !len))
return -EINVAL;
reg_buf = (u32 *)buf;
rem = len & 0x3;
dev_dbg(dev->dev, "buffer-length = %lu buf[0]0x%08X\n",
len, mei_txe_out_data_read(dev, 0));
for (i = 0; i < len / 4; i++) {
reg = mei_txe_out_data_read(dev, i + 1);
dev_dbg(dev->dev, "buf[%d] = 0x%08X\n", i, reg);
*reg_buf++ = reg;
}
if (rem) {
reg = mei_txe_out_data_read(dev, i + 1);
memcpy(reg_buf, &reg, rem);
}
mei_txe_output_ready_set(hw);
return 0;
}
static int mei_txe_hw_reset(struct mei_device *dev, bool intr_enable)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
u32 aliveness_req;
(void)mei_txe_sec_reg_read_silent(hw, SEC_IPC_INPUT_DOORBELL_REG);
aliveness_req = mei_txe_aliveness_req_get(dev);
hw->aliveness = mei_txe_aliveness_get(dev);
mei_txe_intr_disable(dev);
if (aliveness_req != hw->aliveness)
if (mei_txe_aliveness_poll(dev, aliveness_req) < 0) {
dev_err(dev->dev, "wait for aliveness settle failed ... bailing out\n");
return -EIO;
}
if (aliveness_req) {
mei_txe_aliveness_set(dev, 0);
if (mei_txe_aliveness_poll(dev, 0) < 0) {
dev_err(dev->dev, "wait for aliveness failed ... bailing out\n");
return -EIO;
}
}
mei_txe_readiness_clear(dev);
return 0;
}
static int mei_txe_hw_start(struct mei_device *dev)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
int ret;
u32 hisr;
mei_txe_intr_enable(dev);
ret = mei_txe_readiness_wait(dev);
if (ret < 0) {
dev_err(dev->dev, "waiting for readiness failed\n");
return ret;
}
hisr = mei_txe_br_reg_read(hw, HISR_REG);
if (hisr & HISR_INT_2_STS)
mei_txe_br_reg_write(hw, HISR_REG, HISR_INT_2_STS);
clear_bit(TXE_INTR_OUT_DB_BIT, &hw->intr_cause);
ret = mei_txe_aliveness_set_sync(dev, 1);
if (ret < 0) {
dev_err(dev->dev, "wait for aliveness failed ... bailing out\n");
return ret;
}
mei_txe_input_ready_interrupt_enable(dev);
mei_txe_output_ready_set(hw);
mei_txe_readiness_set_host_rdy(dev);
return 0;
}
static bool mei_txe_check_and_ack_intrs(struct mei_device *dev, bool do_ack)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
u32 hisr;
u32 hhisr;
u32 ipc_isr;
u32 aliveness;
bool generated;
hhisr = mei_txe_br_reg_read(hw, HHISR_REG);
generated = (hhisr & IPC_HHIER_MSK);
if (!generated)
goto out;
hisr = mei_txe_br_reg_read(hw, HISR_REG);
aliveness = mei_txe_aliveness_get(dev);
if (hhisr & IPC_HHIER_SEC && aliveness)
ipc_isr = mei_txe_sec_reg_read_silent(hw,
SEC_IPC_HOST_INT_STATUS_REG);
else
ipc_isr = 0;
generated = generated ||
(hisr & HISR_INT_STS_MSK) ||
(ipc_isr & SEC_IPC_HOST_INT_STATUS_PENDING);
if (generated && do_ack) {
hw->intr_cause |= hisr & HISR_INT_STS_MSK;
if (ipc_isr & SEC_IPC_HOST_INT_STATUS_IN_RDY)
hw->intr_cause |= TXE_INTR_IN_READY;
mei_txe_intr_disable(dev);
mei_txe_sec_reg_write_silent(hw,
SEC_IPC_HOST_INT_STATUS_REG, ipc_isr);
mei_txe_br_reg_write(hw, HISR_REG, hisr);
mei_txe_br_reg_write(hw, HHISR_REG, hhisr);
}
out:
return generated;
}
irqreturn_t mei_txe_irq_quick_handler(int irq, void *dev_id)
{
struct mei_device *dev = dev_id;
if (mei_txe_check_and_ack_intrs(dev, true))
return IRQ_WAKE_THREAD;
return IRQ_NONE;
}
irqreturn_t mei_txe_irq_thread_handler(int irq, void *dev_id)
{
struct mei_device *dev = (struct mei_device *) dev_id;
struct mei_txe_hw *hw = to_txe_hw(dev);
struct mei_cl_cb complete_list;
s32 slots;
int rets = 0;
dev_dbg(dev->dev, "irq thread: Interrupt Registers HHISR|HISR|SEC=%02X|%04X|%02X\n",
mei_txe_br_reg_read(hw, HHISR_REG),
mei_txe_br_reg_read(hw, HISR_REG),
mei_txe_sec_reg_read_silent(hw, SEC_IPC_HOST_INT_STATUS_REG));
mutex_lock(&dev->device_lock);
mei_io_list_init(&complete_list);
if (pci_dev_msi_enabled(to_pci_dev(dev->dev)))
mei_txe_check_and_ack_intrs(dev, true);
mei_txe_pending_interrupts(dev);
hw->aliveness = mei_txe_aliveness_get(dev);
hw->readiness = mei_txe_readiness_get(dev);
if (test_and_clear_bit(TXE_INTR_READINESS_BIT, &hw->intr_cause)) {
dev_dbg(dev->dev, "Readiness Interrupt was received...\n");
if (mei_txe_readiness_is_sec_rdy(hw->readiness)) {
dev_dbg(dev->dev, "we need to start the dev.\n");
dev->recvd_hw_ready = true;
} else {
dev->recvd_hw_ready = false;
if (dev->dev_state != MEI_DEV_RESETTING) {
dev_warn(dev->dev, "FW not ready: resetting.\n");
schedule_work(&dev->reset_work);
goto end;
}
}
wake_up(&dev->wait_hw_ready);
}
if (test_and_clear_bit(TXE_INTR_ALIVENESS_BIT, &hw->intr_cause)) {
dev_dbg(dev->dev,
"Aliveness Interrupt: Status: %d\n", hw->aliveness);
dev->pg_event = MEI_PG_EVENT_RECEIVED;
if (waitqueue_active(&hw->wait_aliveness_resp))
wake_up(&hw->wait_aliveness_resp);
}
slots = mei_count_full_read_slots(dev);
if (test_and_clear_bit(TXE_INTR_OUT_DB_BIT, &hw->intr_cause)) {
rets = mei_irq_read_handler(dev, &complete_list, &slots);
if (rets && dev->dev_state != MEI_DEV_RESETTING) {
dev_err(dev->dev,
"mei_irq_read_handler ret = %d.\n", rets);
schedule_work(&dev->reset_work);
goto end;
}
}
if (test_and_clear_bit(TXE_INTR_IN_READY_BIT, &hw->intr_cause)) {
dev->hbuf_is_ready = true;
hw->slots = dev->hbuf_depth;
}
if (hw->aliveness && dev->hbuf_is_ready) {
dev->hbuf_is_ready = mei_hbuf_is_ready(dev);
rets = mei_irq_write_handler(dev, &complete_list);
if (rets && rets != -EMSGSIZE)
dev_err(dev->dev, "mei_irq_write_handler ret = %d.\n",
rets);
dev->hbuf_is_ready = mei_hbuf_is_ready(dev);
}
mei_irq_compl_handler(dev, &complete_list);
end:
dev_dbg(dev->dev, "interrupt thread end ret = %d\n", rets);
mutex_unlock(&dev->device_lock);
mei_enable_interrupts(dev);
return IRQ_HANDLED;
}
struct mei_device *mei_txe_dev_init(struct pci_dev *pdev)
{
struct mei_device *dev;
struct mei_txe_hw *hw;
dev = kzalloc(sizeof(struct mei_device) +
sizeof(struct mei_txe_hw), GFP_KERNEL);
if (!dev)
return NULL;
mei_device_init(dev, &pdev->dev, &mei_txe_hw_ops);
hw = to_txe_hw(dev);
init_waitqueue_head(&hw->wait_aliveness_resp);
return dev;
}
int mei_txe_setup_satt2(struct mei_device *dev, phys_addr_t addr, u32 range)
{
struct mei_txe_hw *hw = to_txe_hw(dev);
u32 lo32 = lower_32_bits(addr);
u32 hi32 = upper_32_bits(addr);
u32 ctrl;
if (hi32 & ~0xF)
return -EINVAL;
if (lo32 & 0xF)
return -EINVAL;
if (range & 0x4)
return -EINVAL;
if (range > SATT_RANGE_MAX)
return -EINVAL;
ctrl = SATT2_CTRL_VALID_MSK;
ctrl |= hi32 << SATT2_CTRL_BR_BASE_ADDR_REG_SHIFT;
mei_txe_br_reg_write(hw, SATT2_SAP_SIZE_REG, range);
mei_txe_br_reg_write(hw, SATT2_BRG_BA_LSB_REG, lo32);
mei_txe_br_reg_write(hw, SATT2_CTRL_REG, ctrl);
dev_dbg(dev->dev, "SATT2: SAP_SIZE_OFFSET=0x%08X, BRG_BA_LSB_OFFSET=0x%08X, CTRL_OFFSET=0x%08X\n",
range, lo32, ctrl);
return 0;
}
