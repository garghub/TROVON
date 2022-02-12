static inline u32 mei_me_reg_read(const struct mei_me_hw *hw,
unsigned long offset)
{
return ioread32(hw->mem_addr + offset);
}
static inline void mei_me_reg_write(const struct mei_me_hw *hw,
unsigned long offset, u32 value)
{
iowrite32(value, hw->mem_addr + offset);
}
static inline u32 mei_me_mecbrw_read(const struct mei_device *dev)
{
return mei_me_reg_read(to_me_hw(dev), ME_CB_RW);
}
static inline void mei_me_hcbww_write(struct mei_device *dev, u32 data)
{
mei_me_reg_write(to_me_hw(dev), H_CB_WW, data);
}
static inline u32 mei_me_mecsr_read(const struct mei_device *dev)
{
u32 reg;
reg = mei_me_reg_read(to_me_hw(dev), ME_CSR_HA);
trace_mei_reg_read(dev->dev, "ME_CSR_HA", ME_CSR_HA, reg);
return reg;
}
static inline u32 mei_hcsr_read(const struct mei_device *dev)
{
u32 reg;
reg = mei_me_reg_read(to_me_hw(dev), H_CSR);
trace_mei_reg_read(dev->dev, "H_CSR", H_CSR, reg);
return reg;
}
static inline void mei_hcsr_write(struct mei_device *dev, u32 reg)
{
trace_mei_reg_write(dev->dev, "H_CSR", H_CSR, reg);
mei_me_reg_write(to_me_hw(dev), H_CSR, reg);
}
static inline void mei_hcsr_set(struct mei_device *dev, u32 reg)
{
reg &= ~H_CSR_IS_MASK;
mei_hcsr_write(dev, reg);
}
static inline u32 mei_me_d0i3c_read(const struct mei_device *dev)
{
u32 reg;
reg = mei_me_reg_read(to_me_hw(dev), H_D0I3C);
trace_mei_reg_read(dev->dev, "H_D0I3C", H_D0I3C, reg);
return reg;
}
static inline void mei_me_d0i3c_write(struct mei_device *dev, u32 reg)
{
trace_mei_reg_write(dev->dev, "H_D0I3C", H_D0I3C, reg);
mei_me_reg_write(to_me_hw(dev), H_D0I3C, reg);
}
static int mei_me_fw_status(struct mei_device *dev,
struct mei_fw_status *fw_status)
{
struct pci_dev *pdev = to_pci_dev(dev->dev);
struct mei_me_hw *hw = to_me_hw(dev);
const struct mei_fw_status *fw_src = &hw->cfg->fw_status;
int ret;
int i;
if (!fw_status)
return -EINVAL;
fw_status->count = fw_src->count;
for (i = 0; i < fw_src->count && i < MEI_FW_STATUS_MAX; i++) {
ret = pci_read_config_dword(pdev, fw_src->status[i],
&fw_status->status[i]);
trace_mei_pci_cfg_read(dev->dev, "PCI_CFG_HSF_X",
fw_src->status[i],
fw_status->status[i]);
if (ret)
return ret;
}
return 0;
}
static void mei_me_hw_config(struct mei_device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev->dev);
struct mei_me_hw *hw = to_me_hw(dev);
u32 hcsr, reg;
hcsr = mei_hcsr_read(dev);
dev->hbuf_depth = (hcsr & H_CBD) >> 24;
reg = 0;
pci_read_config_dword(pdev, PCI_CFG_HFS_1, &reg);
trace_mei_pci_cfg_read(dev->dev, "PCI_CFG_HFS_1", PCI_CFG_HFS_1, reg);
hw->d0i3_supported =
((reg & PCI_CFG_HFS_1_D0I3_MSK) == PCI_CFG_HFS_1_D0I3_MSK);
hw->pg_state = MEI_PG_OFF;
if (hw->d0i3_supported) {
reg = mei_me_d0i3c_read(dev);
if (reg & H_D0I3C_I3)
hw->pg_state = MEI_PG_ON;
}
}
static inline enum mei_pg_state mei_me_pg_state(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
return hw->pg_state;
}
static void mei_me_intr_clear(struct mei_device *dev)
{
u32 hcsr = mei_hcsr_read(dev);
if (hcsr & H_CSR_IS_MASK)
mei_hcsr_write(dev, hcsr);
}
static void mei_me_intr_enable(struct mei_device *dev)
{
u32 hcsr = mei_hcsr_read(dev);
hcsr |= H_CSR_IE_MASK;
mei_hcsr_set(dev, hcsr);
}
static void mei_me_intr_disable(struct mei_device *dev)
{
u32 hcsr = mei_hcsr_read(dev);
hcsr &= ~H_CSR_IE_MASK;
mei_hcsr_set(dev, hcsr);
}
static void mei_me_hw_reset_release(struct mei_device *dev)
{
u32 hcsr = mei_hcsr_read(dev);
hcsr |= H_IG;
hcsr &= ~H_RST;
mei_hcsr_set(dev, hcsr);
mmiowb();
}
static void mei_me_host_set_ready(struct mei_device *dev)
{
u32 hcsr = mei_hcsr_read(dev);
hcsr |= H_CSR_IE_MASK | H_IG | H_RDY;
mei_hcsr_set(dev, hcsr);
}
static bool mei_me_host_is_ready(struct mei_device *dev)
{
u32 hcsr = mei_hcsr_read(dev);
return (hcsr & H_RDY) == H_RDY;
}
static bool mei_me_hw_is_ready(struct mei_device *dev)
{
u32 mecsr = mei_me_mecsr_read(dev);
return (mecsr & ME_RDY_HRA) == ME_RDY_HRA;
}
static int mei_me_hw_ready_wait(struct mei_device *dev)
{
mutex_unlock(&dev->device_lock);
wait_event_timeout(dev->wait_hw_ready,
dev->recvd_hw_ready,
mei_secs_to_jiffies(MEI_HW_READY_TIMEOUT));
mutex_lock(&dev->device_lock);
if (!dev->recvd_hw_ready) {
dev_err(dev->dev, "wait hw ready failed\n");
return -ETIME;
}
mei_me_hw_reset_release(dev);
dev->recvd_hw_ready = false;
return 0;
}
static int mei_me_hw_start(struct mei_device *dev)
{
int ret = mei_me_hw_ready_wait(dev);
if (ret)
return ret;
dev_dbg(dev->dev, "hw is ready\n");
mei_me_host_set_ready(dev);
return ret;
}
static unsigned char mei_hbuf_filled_slots(struct mei_device *dev)
{
u32 hcsr;
char read_ptr, write_ptr;
hcsr = mei_hcsr_read(dev);
read_ptr = (char) ((hcsr & H_CBRP) >> 8);
write_ptr = (char) ((hcsr & H_CBWP) >> 16);
return (unsigned char) (write_ptr - read_ptr);
}
static bool mei_me_hbuf_is_empty(struct mei_device *dev)
{
return mei_hbuf_filled_slots(dev) == 0;
}
static int mei_me_hbuf_empty_slots(struct mei_device *dev)
{
unsigned char filled_slots, empty_slots;
filled_slots = mei_hbuf_filled_slots(dev);
empty_slots = dev->hbuf_depth - filled_slots;
if (filled_slots > dev->hbuf_depth)
return -EOVERFLOW;
return empty_slots;
}
static size_t mei_me_hbuf_max_len(const struct mei_device *dev)
{
return dev->hbuf_depth * sizeof(u32) - sizeof(struct mei_msg_hdr);
}
static int mei_me_write_message(struct mei_device *dev,
struct mei_msg_hdr *header,
unsigned char *buf)
{
unsigned long rem;
unsigned long length = header->length;
u32 *reg_buf = (u32 *)buf;
u32 hcsr;
u32 dw_cnt;
int i;
int empty_slots;
dev_dbg(dev->dev, MEI_HDR_FMT, MEI_HDR_PRM(header));
empty_slots = mei_hbuf_empty_slots(dev);
dev_dbg(dev->dev, "empty slots = %hu.\n", empty_slots);
dw_cnt = mei_data2slots(length);
if (empty_slots < 0 || dw_cnt > empty_slots)
return -EMSGSIZE;
mei_me_hcbww_write(dev, *((u32 *) header));
for (i = 0; i < length / 4; i++)
mei_me_hcbww_write(dev, reg_buf[i]);
rem = length & 0x3;
if (rem > 0) {
u32 reg = 0;
memcpy(&reg, &buf[length - rem], rem);
mei_me_hcbww_write(dev, reg);
}
hcsr = mei_hcsr_read(dev) | H_IG;
mei_hcsr_set(dev, hcsr);
if (!mei_me_hw_is_ready(dev))
return -EIO;
return 0;
}
static int mei_me_count_full_read_slots(struct mei_device *dev)
{
u32 me_csr;
char read_ptr, write_ptr;
unsigned char buffer_depth, filled_slots;
me_csr = mei_me_mecsr_read(dev);
buffer_depth = (unsigned char)((me_csr & ME_CBD_HRA) >> 24);
read_ptr = (char) ((me_csr & ME_CBRP_HRA) >> 8);
write_ptr = (char) ((me_csr & ME_CBWP_HRA) >> 16);
filled_slots = (unsigned char) (write_ptr - read_ptr);
if (filled_slots > buffer_depth)
return -EOVERFLOW;
dev_dbg(dev->dev, "filled_slots =%08x\n", filled_slots);
return (int)filled_slots;
}
static int mei_me_read_slots(struct mei_device *dev, unsigned char *buffer,
unsigned long buffer_length)
{
u32 *reg_buf = (u32 *)buffer;
u32 hcsr;
for (; buffer_length >= sizeof(u32); buffer_length -= sizeof(u32))
*reg_buf++ = mei_me_mecbrw_read(dev);
if (buffer_length > 0) {
u32 reg = mei_me_mecbrw_read(dev);
memcpy(reg_buf, &reg, buffer_length);
}
hcsr = mei_hcsr_read(dev) | H_IG;
mei_hcsr_set(dev, hcsr);
return 0;
}
static void mei_me_pg_set(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
u32 reg;
reg = mei_me_reg_read(hw, H_HPG_CSR);
trace_mei_reg_read(dev->dev, "H_HPG_CSR", H_HPG_CSR, reg);
reg |= H_HPG_CSR_PGI;
trace_mei_reg_write(dev->dev, "H_HPG_CSR", H_HPG_CSR, reg);
mei_me_reg_write(hw, H_HPG_CSR, reg);
}
static void mei_me_pg_unset(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
u32 reg;
reg = mei_me_reg_read(hw, H_HPG_CSR);
trace_mei_reg_read(dev->dev, "H_HPG_CSR", H_HPG_CSR, reg);
WARN(!(reg & H_HPG_CSR_PGI), "PGI is not set\n");
reg |= H_HPG_CSR_PGIHEXR;
trace_mei_reg_write(dev->dev, "H_HPG_CSR", H_HPG_CSR, reg);
mei_me_reg_write(hw, H_HPG_CSR, reg);
}
static int mei_me_pg_legacy_enter_sync(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
unsigned long timeout = mei_secs_to_jiffies(MEI_PGI_TIMEOUT);
int ret;
dev->pg_event = MEI_PG_EVENT_WAIT;
ret = mei_hbm_pg(dev, MEI_PG_ISOLATION_ENTRY_REQ_CMD);
if (ret)
return ret;
mutex_unlock(&dev->device_lock);
wait_event_timeout(dev->wait_pg,
dev->pg_event == MEI_PG_EVENT_RECEIVED, timeout);
mutex_lock(&dev->device_lock);
if (dev->pg_event == MEI_PG_EVENT_RECEIVED) {
mei_me_pg_set(dev);
ret = 0;
} else {
ret = -ETIME;
}
dev->pg_event = MEI_PG_EVENT_IDLE;
hw->pg_state = MEI_PG_ON;
return ret;
}
static int mei_me_pg_legacy_exit_sync(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
unsigned long timeout = mei_secs_to_jiffies(MEI_PGI_TIMEOUT);
int ret;
if (dev->pg_event == MEI_PG_EVENT_RECEIVED)
goto reply;
dev->pg_event = MEI_PG_EVENT_WAIT;
mei_me_pg_unset(dev);
mutex_unlock(&dev->device_lock);
wait_event_timeout(dev->wait_pg,
dev->pg_event == MEI_PG_EVENT_RECEIVED, timeout);
mutex_lock(&dev->device_lock);
reply:
if (dev->pg_event != MEI_PG_EVENT_RECEIVED) {
ret = -ETIME;
goto out;
}
dev->pg_event = MEI_PG_EVENT_INTR_WAIT;
ret = mei_hbm_pg(dev, MEI_PG_ISOLATION_EXIT_RES_CMD);
if (ret)
return ret;
mutex_unlock(&dev->device_lock);
wait_event_timeout(dev->wait_pg,
dev->pg_event == MEI_PG_EVENT_INTR_RECEIVED, timeout);
mutex_lock(&dev->device_lock);
if (dev->pg_event == MEI_PG_EVENT_INTR_RECEIVED)
ret = 0;
else
ret = -ETIME;
out:
dev->pg_event = MEI_PG_EVENT_IDLE;
hw->pg_state = MEI_PG_OFF;
return ret;
}
static bool mei_me_pg_in_transition(struct mei_device *dev)
{
return dev->pg_event >= MEI_PG_EVENT_WAIT &&
dev->pg_event <= MEI_PG_EVENT_INTR_WAIT;
}
static bool mei_me_pg_is_enabled(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
u32 reg = mei_me_mecsr_read(dev);
if (hw->d0i3_supported)
return true;
if ((reg & ME_PGIC_HRA) == 0)
goto notsupported;
if (!dev->hbm_f_pg_supported)
goto notsupported;
return true;
notsupported:
dev_dbg(dev->dev, "pg: not supported: d0i3 = %d HGP = %d hbm version %d.%d ?= %d.%d\n",
hw->d0i3_supported,
!!(reg & ME_PGIC_HRA),
dev->version.major_version,
dev->version.minor_version,
HBM_MAJOR_VERSION_PGI,
HBM_MINOR_VERSION_PGI);
return false;
}
static u32 mei_me_d0i3_set(struct mei_device *dev, bool intr)
{
u32 reg = mei_me_d0i3c_read(dev);
reg |= H_D0I3C_I3;
if (intr)
reg |= H_D0I3C_IR;
else
reg &= ~H_D0I3C_IR;
mei_me_d0i3c_write(dev, reg);
reg = mei_me_d0i3c_read(dev);
return reg;
}
static u32 mei_me_d0i3_unset(struct mei_device *dev)
{
u32 reg = mei_me_d0i3c_read(dev);
reg &= ~H_D0I3C_I3;
reg |= H_D0I3C_IR;
mei_me_d0i3c_write(dev, reg);
reg = mei_me_d0i3c_read(dev);
return reg;
}
static int mei_me_d0i3_enter_sync(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
unsigned long d0i3_timeout = mei_secs_to_jiffies(MEI_D0I3_TIMEOUT);
unsigned long pgi_timeout = mei_secs_to_jiffies(MEI_PGI_TIMEOUT);
int ret;
u32 reg;
reg = mei_me_d0i3c_read(dev);
if (reg & H_D0I3C_I3) {
dev_dbg(dev->dev, "d0i3 set not needed\n");
ret = 0;
goto on;
}
dev->pg_event = MEI_PG_EVENT_WAIT;
ret = mei_hbm_pg(dev, MEI_PG_ISOLATION_ENTRY_REQ_CMD);
if (ret)
goto out;
mutex_unlock(&dev->device_lock);
wait_event_timeout(dev->wait_pg,
dev->pg_event == MEI_PG_EVENT_RECEIVED, pgi_timeout);
mutex_lock(&dev->device_lock);
if (dev->pg_event != MEI_PG_EVENT_RECEIVED) {
ret = -ETIME;
goto out;
}
dev->pg_event = MEI_PG_EVENT_INTR_WAIT;
reg = mei_me_d0i3_set(dev, true);
if (!(reg & H_D0I3C_CIP)) {
dev_dbg(dev->dev, "d0i3 enter wait not needed\n");
ret = 0;
goto on;
}
mutex_unlock(&dev->device_lock);
wait_event_timeout(dev->wait_pg,
dev->pg_event == MEI_PG_EVENT_INTR_RECEIVED, d0i3_timeout);
mutex_lock(&dev->device_lock);
if (dev->pg_event != MEI_PG_EVENT_INTR_RECEIVED) {
reg = mei_me_d0i3c_read(dev);
if (!(reg & H_D0I3C_I3)) {
ret = -ETIME;
goto out;
}
}
ret = 0;
on:
hw->pg_state = MEI_PG_ON;
out:
dev->pg_event = MEI_PG_EVENT_IDLE;
dev_dbg(dev->dev, "d0i3 enter ret = %d\n", ret);
return ret;
}
static int mei_me_d0i3_enter(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
u32 reg;
reg = mei_me_d0i3c_read(dev);
if (reg & H_D0I3C_I3) {
dev_dbg(dev->dev, "already d0i3 : set not needed\n");
goto on;
}
mei_me_d0i3_set(dev, false);
on:
hw->pg_state = MEI_PG_ON;
dev->pg_event = MEI_PG_EVENT_IDLE;
dev_dbg(dev->dev, "d0i3 enter\n");
return 0;
}
static int mei_me_d0i3_exit_sync(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
unsigned long timeout = mei_secs_to_jiffies(MEI_D0I3_TIMEOUT);
int ret;
u32 reg;
dev->pg_event = MEI_PG_EVENT_INTR_WAIT;
reg = mei_me_d0i3c_read(dev);
if (!(reg & H_D0I3C_I3)) {
dev_dbg(dev->dev, "d0i3 exit not needed\n");
ret = 0;
goto off;
}
reg = mei_me_d0i3_unset(dev);
if (!(reg & H_D0I3C_CIP)) {
dev_dbg(dev->dev, "d0i3 exit wait not needed\n");
ret = 0;
goto off;
}
mutex_unlock(&dev->device_lock);
wait_event_timeout(dev->wait_pg,
dev->pg_event == MEI_PG_EVENT_INTR_RECEIVED, timeout);
mutex_lock(&dev->device_lock);
if (dev->pg_event != MEI_PG_EVENT_INTR_RECEIVED) {
reg = mei_me_d0i3c_read(dev);
if (reg & H_D0I3C_I3) {
ret = -ETIME;
goto out;
}
}
ret = 0;
off:
hw->pg_state = MEI_PG_OFF;
out:
dev->pg_event = MEI_PG_EVENT_IDLE;
dev_dbg(dev->dev, "d0i3 exit ret = %d\n", ret);
return ret;
}
static void mei_me_pg_legacy_intr(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
if (dev->pg_event != MEI_PG_EVENT_INTR_WAIT)
return;
dev->pg_event = MEI_PG_EVENT_INTR_RECEIVED;
hw->pg_state = MEI_PG_OFF;
if (waitqueue_active(&dev->wait_pg))
wake_up(&dev->wait_pg);
}
static void mei_me_d0i3_intr(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
if (dev->pg_event == MEI_PG_EVENT_INTR_WAIT &&
(hw->intr_source & H_D0I3C_IS)) {
dev->pg_event = MEI_PG_EVENT_INTR_RECEIVED;
if (hw->pg_state == MEI_PG_ON) {
hw->pg_state = MEI_PG_OFF;
if (dev->hbm_state != MEI_HBM_IDLE) {
dev_dbg(dev->dev, "d0i3 set host ready\n");
mei_me_host_set_ready(dev);
}
} else {
hw->pg_state = MEI_PG_ON;
}
wake_up(&dev->wait_pg);
}
if (hw->pg_state == MEI_PG_ON && (hw->intr_source & H_IS)) {
dev_dbg(dev->dev, "d0i3 want resume\n");
mei_hbm_pg_resume(dev);
}
}
static void mei_me_pg_intr(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
if (hw->d0i3_supported)
mei_me_d0i3_intr(dev);
else
mei_me_pg_legacy_intr(dev);
}
int mei_me_pg_enter_sync(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
if (hw->d0i3_supported)
return mei_me_d0i3_enter_sync(dev);
else
return mei_me_pg_legacy_enter_sync(dev);
}
int mei_me_pg_exit_sync(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
if (hw->d0i3_supported)
return mei_me_d0i3_exit_sync(dev);
else
return mei_me_pg_legacy_exit_sync(dev);
}
static int mei_me_hw_reset(struct mei_device *dev, bool intr_enable)
{
struct mei_me_hw *hw = to_me_hw(dev);
int ret;
u32 hcsr;
if (intr_enable) {
mei_me_intr_enable(dev);
if (hw->d0i3_supported) {
ret = mei_me_d0i3_exit_sync(dev);
if (ret)
return ret;
}
}
pm_runtime_set_active(dev->dev);
hcsr = mei_hcsr_read(dev);
if ((hcsr & H_RST) == H_RST) {
dev_warn(dev->dev, "H_RST is set = 0x%08X", hcsr);
hcsr &= ~H_RST;
mei_hcsr_set(dev, hcsr);
hcsr = mei_hcsr_read(dev);
}
hcsr |= H_RST | H_IG | H_CSR_IS_MASK;
if (!intr_enable)
hcsr &= ~H_CSR_IE_MASK;
dev->recvd_hw_ready = false;
mei_hcsr_write(dev, hcsr);
hcsr = mei_hcsr_read(dev);
if ((hcsr & H_RST) == 0)
dev_warn(dev->dev, "H_RST is not set = 0x%08X", hcsr);
if ((hcsr & H_RDY) == H_RDY)
dev_warn(dev->dev, "H_RDY is not cleared 0x%08X", hcsr);
if (!intr_enable) {
mei_me_hw_reset_release(dev);
if (hw->d0i3_supported) {
ret = mei_me_d0i3_enter(dev);
if (ret)
return ret;
}
}
return 0;
}
irqreturn_t mei_me_irq_quick_handler(int irq, void *dev_id)
{
struct mei_device *dev = (struct mei_device *)dev_id;
struct mei_me_hw *hw = to_me_hw(dev);
u32 hcsr;
hcsr = mei_hcsr_read(dev);
if (!(hcsr & H_CSR_IS_MASK))
return IRQ_NONE;
hw->intr_source = hcsr & H_CSR_IS_MASK;
dev_dbg(dev->dev, "interrupt source 0x%08X.\n", hw->intr_source);
mei_hcsr_write(dev, hcsr);
return IRQ_WAKE_THREAD;
}
irqreturn_t mei_me_irq_thread_handler(int irq, void *dev_id)
{
struct mei_device *dev = (struct mei_device *) dev_id;
struct mei_cl_cb complete_list;
s32 slots;
int rets = 0;
dev_dbg(dev->dev, "function called after ISR to handle the interrupt processing.\n");
mutex_lock(&dev->device_lock);
mei_io_list_init(&complete_list);
if (!mei_hw_is_ready(dev) && dev->dev_state != MEI_DEV_RESETTING) {
dev_warn(dev->dev, "FW not ready: resetting.\n");
schedule_work(&dev->reset_work);
goto end;
}
mei_me_pg_intr(dev);
if (!mei_host_is_ready(dev)) {
if (mei_hw_is_ready(dev)) {
dev_dbg(dev->dev, "we need to start the dev.\n");
dev->recvd_hw_ready = true;
wake_up(&dev->wait_hw_ready);
} else {
dev_dbg(dev->dev, "Spurious Interrupt\n");
}
goto end;
}
slots = mei_count_full_read_slots(dev);
while (slots > 0) {
dev_dbg(dev->dev, "slots to read = %08x\n", slots);
rets = mei_irq_read_handler(dev, &complete_list, &slots);
if (rets == -ENODATA)
break;
if (rets && dev->dev_state != MEI_DEV_RESETTING) {
dev_err(dev->dev, "mei_irq_read_handler ret = %d.\n",
rets);
schedule_work(&dev->reset_work);
goto end;
}
}
dev->hbuf_is_ready = mei_hbuf_is_ready(dev);
if (dev->pg_event != MEI_PG_EVENT_WAIT &&
dev->pg_event != MEI_PG_EVENT_RECEIVED) {
rets = mei_irq_write_handler(dev, &complete_list);
dev->hbuf_is_ready = mei_hbuf_is_ready(dev);
}
mei_irq_compl_handler(dev, &complete_list);
end:
dev_dbg(dev->dev, "interrupt thread end ret = %d\n", rets);
mutex_unlock(&dev->device_lock);
return IRQ_HANDLED;
}
static bool mei_me_fw_type_nm(struct pci_dev *pdev)
{
u32 reg;
pci_read_config_dword(pdev, PCI_CFG_HFS_2, &reg);
trace_mei_pci_cfg_read(&pdev->dev, "PCI_CFG_HFS_2", PCI_CFG_HFS_2, reg);
return (reg & 0x600) == 0x200;
}
static bool mei_me_fw_type_sps(struct pci_dev *pdev)
{
u32 reg;
unsigned int devfn;
devfn = PCI_DEVFN(PCI_SLOT(pdev->devfn), 0);
pci_bus_read_config_dword(pdev->bus, devfn, PCI_CFG_HFS_1, &reg);
trace_mei_pci_cfg_read(&pdev->dev, "PCI_CFG_HFS_1", PCI_CFG_HFS_1, reg);
return (reg & 0xf0000) == 0xf0000;
}
struct mei_device *mei_me_dev_init(struct pci_dev *pdev,
const struct mei_cfg *cfg)
{
struct mei_device *dev;
struct mei_me_hw *hw;
dev = kzalloc(sizeof(struct mei_device) +
sizeof(struct mei_me_hw), GFP_KERNEL);
if (!dev)
return NULL;
hw = to_me_hw(dev);
mei_device_init(dev, &pdev->dev, &mei_me_hw_ops);
hw->cfg = cfg;
return dev;
}
