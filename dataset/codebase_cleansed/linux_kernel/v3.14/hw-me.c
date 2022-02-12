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
static u32 mei_me_mecbrw_read(const struct mei_device *dev)
{
return mei_me_reg_read(to_me_hw(dev), ME_CB_RW);
}
static inline u32 mei_me_mecsr_read(const struct mei_me_hw *hw)
{
return mei_me_reg_read(hw, ME_CSR_HA);
}
static inline u32 mei_hcsr_read(const struct mei_me_hw *hw)
{
return mei_me_reg_read(hw, H_CSR);
}
static inline void mei_hcsr_set(struct mei_me_hw *hw, u32 hcsr)
{
hcsr &= ~H_IS;
mei_me_reg_write(hw, H_CSR, hcsr);
}
static void mei_me_hw_config(struct mei_device *dev)
{
u32 hcsr = mei_hcsr_read(to_me_hw(dev));
dev->hbuf_depth = (hcsr & H_CBD) >> 24;
}
static void mei_me_intr_clear(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
u32 hcsr = mei_hcsr_read(hw);
if ((hcsr & H_IS) == H_IS)
mei_me_reg_write(hw, H_CSR, hcsr);
}
static void mei_me_intr_enable(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
u32 hcsr = mei_hcsr_read(hw);
hcsr |= H_IE;
mei_hcsr_set(hw, hcsr);
}
static void mei_me_intr_disable(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
u32 hcsr = mei_hcsr_read(hw);
hcsr &= ~H_IE;
mei_hcsr_set(hw, hcsr);
}
static void mei_me_hw_reset_release(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
u32 hcsr = mei_hcsr_read(hw);
hcsr |= H_IG;
hcsr &= ~H_RST;
mei_hcsr_set(hw, hcsr);
}
static int mei_me_hw_reset(struct mei_device *dev, bool intr_enable)
{
struct mei_me_hw *hw = to_me_hw(dev);
u32 hcsr = mei_hcsr_read(hw);
hcsr |= H_RST | H_IG | H_IS;
if (intr_enable)
hcsr |= H_IE;
else
hcsr &= ~H_IE;
mei_me_reg_write(hw, H_CSR, hcsr);
if (intr_enable == false)
mei_me_hw_reset_release(dev);
return 0;
}
static void mei_me_host_set_ready(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
hw->host_hw_state |= H_IE | H_IG | H_RDY;
mei_hcsr_set(hw, hw->host_hw_state);
}
static bool mei_me_host_is_ready(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
hw->host_hw_state = mei_hcsr_read(hw);
return (hw->host_hw_state & H_RDY) == H_RDY;
}
static bool mei_me_hw_is_ready(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
hw->me_hw_state = mei_me_mecsr_read(hw);
return (hw->me_hw_state & ME_RDY_HRA) == ME_RDY_HRA;
}
static int mei_me_hw_ready_wait(struct mei_device *dev)
{
int err;
if (mei_me_hw_is_ready(dev))
return 0;
dev->recvd_hw_ready = false;
mutex_unlock(&dev->device_lock);
err = wait_event_interruptible_timeout(dev->wait_hw_ready,
dev->recvd_hw_ready,
mei_secs_to_jiffies(MEI_INTEROP_TIMEOUT));
mutex_lock(&dev->device_lock);
if (!err && !dev->recvd_hw_ready) {
if (!err)
err = -ETIMEDOUT;
dev_err(&dev->pdev->dev,
"wait hw ready failed. status = %d\n", err);
return err;
}
dev->recvd_hw_ready = false;
return 0;
}
static int mei_me_hw_start(struct mei_device *dev)
{
int ret = mei_me_hw_ready_wait(dev);
if (ret)
return ret;
dev_dbg(&dev->pdev->dev, "hw is ready\n");
mei_me_host_set_ready(dev);
return ret;
}
static unsigned char mei_hbuf_filled_slots(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
char read_ptr, write_ptr;
hw->host_hw_state = mei_hcsr_read(hw);
read_ptr = (char) ((hw->host_hw_state & H_CBRP) >> 8);
write_ptr = (char) ((hw->host_hw_state & H_CBWP) >> 16);
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
struct mei_me_hw *hw = to_me_hw(dev);
unsigned long rem;
unsigned long length = header->length;
u32 *reg_buf = (u32 *)buf;
u32 hcsr;
u32 dw_cnt;
int i;
int empty_slots;
dev_dbg(&dev->pdev->dev, MEI_HDR_FMT, MEI_HDR_PRM(header));
empty_slots = mei_hbuf_empty_slots(dev);
dev_dbg(&dev->pdev->dev, "empty slots = %hu.\n", empty_slots);
dw_cnt = mei_data2slots(length);
if (empty_slots < 0 || dw_cnt > empty_slots)
return -EIO;
mei_me_reg_write(hw, H_CB_WW, *((u32 *) header));
for (i = 0; i < length / 4; i++)
mei_me_reg_write(hw, H_CB_WW, reg_buf[i]);
rem = length & 0x3;
if (rem > 0) {
u32 reg = 0;
memcpy(&reg, &buf[length - rem], rem);
mei_me_reg_write(hw, H_CB_WW, reg);
}
hcsr = mei_hcsr_read(hw) | H_IG;
mei_hcsr_set(hw, hcsr);
if (!mei_me_hw_is_ready(dev))
return -EIO;
return 0;
}
static int mei_me_count_full_read_slots(struct mei_device *dev)
{
struct mei_me_hw *hw = to_me_hw(dev);
char read_ptr, write_ptr;
unsigned char buffer_depth, filled_slots;
hw->me_hw_state = mei_me_mecsr_read(hw);
buffer_depth = (unsigned char)((hw->me_hw_state & ME_CBD_HRA) >> 24);
read_ptr = (char) ((hw->me_hw_state & ME_CBRP_HRA) >> 8);
write_ptr = (char) ((hw->me_hw_state & ME_CBWP_HRA) >> 16);
filled_slots = (unsigned char) (write_ptr - read_ptr);
if (filled_slots > buffer_depth)
return -EOVERFLOW;
dev_dbg(&dev->pdev->dev, "filled_slots =%08x\n", filled_slots);
return (int)filled_slots;
}
static int mei_me_read_slots(struct mei_device *dev, unsigned char *buffer,
unsigned long buffer_length)
{
struct mei_me_hw *hw = to_me_hw(dev);
u32 *reg_buf = (u32 *)buffer;
u32 hcsr;
for (; buffer_length >= sizeof(u32); buffer_length -= sizeof(u32))
*reg_buf++ = mei_me_mecbrw_read(dev);
if (buffer_length > 0) {
u32 reg = mei_me_mecbrw_read(dev);
memcpy(reg_buf, &reg, buffer_length);
}
hcsr = mei_hcsr_read(hw) | H_IG;
mei_hcsr_set(hw, hcsr);
return 0;
}
irqreturn_t mei_me_irq_quick_handler(int irq, void *dev_id)
{
struct mei_device *dev = (struct mei_device *) dev_id;
struct mei_me_hw *hw = to_me_hw(dev);
u32 csr_reg = mei_hcsr_read(hw);
if ((csr_reg & H_IS) != H_IS)
return IRQ_NONE;
mei_me_reg_write(hw, H_CSR, csr_reg);
return IRQ_WAKE_THREAD;
}
irqreturn_t mei_me_irq_thread_handler(int irq, void *dev_id)
{
struct mei_device *dev = (struct mei_device *) dev_id;
struct mei_cl_cb complete_list;
s32 slots;
int rets = 0;
dev_dbg(&dev->pdev->dev, "function called after ISR to handle the interrupt processing.\n");
mutex_lock(&dev->device_lock);
mei_io_list_init(&complete_list);
if (pci_dev_msi_enabled(dev->pdev))
mei_clear_interrupts(dev);
if (!mei_hw_is_ready(dev) && dev->dev_state != MEI_DEV_RESETTING) {
dev_warn(&dev->pdev->dev, "FW not ready: resetting.\n");
schedule_work(&dev->reset_work);
goto end;
}
if (!mei_host_is_ready(dev)) {
if (mei_hw_is_ready(dev)) {
dev_dbg(&dev->pdev->dev, "we need to start the dev.\n");
dev->recvd_hw_ready = true;
wake_up_interruptible(&dev->wait_hw_ready);
} else {
dev_dbg(&dev->pdev->dev, "Reset Completed.\n");
mei_me_hw_reset_release(dev);
}
goto end;
}
slots = mei_count_full_read_slots(dev);
while (slots > 0) {
if (dev->wr_ext_msg.hdr.length)
break;
dev_dbg(&dev->pdev->dev, "slots to read = %08x\n", slots);
rets = mei_irq_read_handler(dev, &complete_list, &slots);
if (rets && dev->dev_state != MEI_DEV_RESETTING) {
schedule_work(&dev->reset_work);
goto end;
}
}
rets = mei_irq_write_handler(dev, &complete_list);
dev->hbuf_is_ready = mei_hbuf_is_ready(dev);
mei_irq_compl_handler(dev, &complete_list);
end:
dev_dbg(&dev->pdev->dev, "interrupt thread end ret = %d\n", rets);
mutex_unlock(&dev->device_lock);
return IRQ_HANDLED;
}
struct mei_device *mei_me_dev_init(struct pci_dev *pdev)
{
struct mei_device *dev;
dev = kzalloc(sizeof(struct mei_device) +
sizeof(struct mei_me_hw), GFP_KERNEL);
if (!dev)
return NULL;
mei_device_init(dev);
dev->ops = &mei_me_hw_ops;
dev->pdev = pdev;
return dev;
}
