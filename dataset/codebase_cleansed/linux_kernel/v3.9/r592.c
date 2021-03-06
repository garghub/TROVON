const char *memstick_debug_get_tpc_name(int tpc)
{
return tpc_names[tpc-1];
}
static inline u32 r592_read_reg(struct r592_device *dev, int address)
{
u32 value = readl(dev->mmio + address);
dbg_reg("reg #%02d == 0x%08x", address, value);
return value;
}
static inline void r592_write_reg(struct r592_device *dev,
int address, u32 value)
{
dbg_reg("reg #%02d <- 0x%08x", address, value);
writel(value, dev->mmio + address);
}
static inline u32 r592_read_reg_raw_be(struct r592_device *dev, int address)
{
u32 value = __raw_readl(dev->mmio + address);
dbg_reg("reg #%02d == 0x%08x", address, value);
return be32_to_cpu(value);
}
static inline void r592_write_reg_raw_be(struct r592_device *dev,
int address, u32 value)
{
dbg_reg("reg #%02d <- 0x%08x", address, value);
__raw_writel(cpu_to_be32(value), dev->mmio + address);
}
static inline void r592_set_reg_mask(struct r592_device *dev,
int address, u32 mask)
{
u32 reg = readl(dev->mmio + address);
dbg_reg("reg #%02d |= 0x%08x (old =0x%08x)", address, mask, reg);
writel(reg | mask , dev->mmio + address);
}
static inline void r592_clear_reg_mask(struct r592_device *dev,
int address, u32 mask)
{
u32 reg = readl(dev->mmio + address);
dbg_reg("reg #%02d &= 0x%08x (old = 0x%08x, mask = 0x%08x)",
address, ~mask, reg, mask);
writel(reg & ~mask, dev->mmio + address);
}
static int r592_wait_status(struct r592_device *dev, u32 mask, u32 wanted_mask)
{
unsigned long timeout = jiffies + msecs_to_jiffies(1000);
u32 reg = r592_read_reg(dev, R592_STATUS);
if ((reg & mask) == wanted_mask)
return 0;
while (time_before(jiffies, timeout)) {
reg = r592_read_reg(dev, R592_STATUS);
if ((reg & mask) == wanted_mask)
return 0;
if (reg & (R592_STATUS_SEND_ERR | R592_STATUS_RECV_ERR))
return -EIO;
cpu_relax();
}
return -ETIME;
}
static int r592_enable_device(struct r592_device *dev, bool enable)
{
dbg("%sabling the device", enable ? "en" : "dis");
if (enable) {
r592_write_reg(dev, R592_POWER, R592_POWER_0 | R592_POWER_1);
r592_set_reg_mask(dev, R592_IO, R592_IO_RESET);
msleep(100);
} else
r592_write_reg(dev, R592_POWER, 0);
return 0;
}
static int r592_set_mode(struct r592_device *dev, bool parallel_mode)
{
if (!parallel_mode) {
dbg("switching to serial mode");
r592_write_reg(dev, R592_IO_MODE, R592_IO_MODE_SERIAL);
r592_clear_reg_mask(dev, R592_POWER, R592_POWER_20);
} else {
dbg("switching to parallel mode");
r592_set_reg_mask(dev, R592_POWER, R592_POWER_20);
r592_clear_reg_mask(dev, R592_IO,
R592_IO_SERIAL1 | R592_IO_SERIAL2);
r592_write_reg(dev, R592_IO_MODE, R592_IO_MODE_PARALLEL);
}
dev->parallel_mode = parallel_mode;
return 0;
}
static void r592_host_reset(struct r592_device *dev)
{
r592_set_reg_mask(dev, R592_IO, R592_IO_RESET);
msleep(100);
r592_set_mode(dev, dev->parallel_mode);
}
static void r592_clear_interrupts(struct r592_device *dev)
{
r592_clear_reg_mask(dev, R592_REG_MSC, IRQ_ALL_ACK_MASK);
r592_clear_reg_mask(dev, R592_REG_MSC, IRQ_ALL_EN_MASK);
}
static int r592_test_io_error(struct r592_device *dev)
{
if (!(r592_read_reg(dev, R592_STATUS) &
(R592_STATUS_SEND_ERR | R592_STATUS_RECV_ERR)))
return 0;
return -EIO;
}
static int r592_test_fifo_empty(struct r592_device *dev)
{
if (r592_read_reg(dev, R592_REG_MSC) & R592_REG_MSC_FIFO_EMPTY)
return 0;
dbg("FIFO not ready, trying to reset the device");
r592_host_reset(dev);
if (r592_read_reg(dev, R592_REG_MSC) & R592_REG_MSC_FIFO_EMPTY)
return 0;
message("FIFO still not ready, giving up");
return -EIO;
}
static void r592_start_dma(struct r592_device *dev, bool is_write)
{
unsigned long flags;
u32 reg;
spin_lock_irqsave(&dev->irq_lock, flags);
r592_clear_reg_mask(dev, R592_REG_MSC, DMA_IRQ_ACK_MASK);
r592_set_reg_mask(dev, R592_REG_MSC, DMA_IRQ_EN_MASK);
r592_write_reg(dev, R592_FIFO_DMA, sg_dma_address(&dev->req->sg));
reg = r592_read_reg(dev, R592_FIFO_DMA_SETTINGS);
reg |= R592_FIFO_DMA_SETTINGS_EN;
if (!is_write)
reg |= R592_FIFO_DMA_SETTINGS_DIR;
else
reg &= ~R592_FIFO_DMA_SETTINGS_DIR;
r592_write_reg(dev, R592_FIFO_DMA_SETTINGS, reg);
spin_unlock_irqrestore(&dev->irq_lock, flags);
}
static void r592_stop_dma(struct r592_device *dev, int error)
{
r592_clear_reg_mask(dev, R592_FIFO_DMA_SETTINGS,
R592_FIFO_DMA_SETTINGS_EN);
r592_write_reg(dev, R592_FIFO_DMA,
dev->dummy_dma_page_physical_address);
r592_clear_reg_mask(dev, R592_REG_MSC, DMA_IRQ_EN_MASK);
r592_clear_reg_mask(dev, R592_REG_MSC, DMA_IRQ_ACK_MASK);
dev->dma_error = error;
}
static void r592_check_dma(struct r592_device *dev)
{
dev->dma_capable = r592_enable_dma &&
(r592_read_reg(dev, R592_FIFO_DMA_SETTINGS) &
R592_FIFO_DMA_SETTINGS_CAP);
}
static int r592_transfer_fifo_dma(struct r592_device *dev)
{
int len, sg_count;
bool is_write;
if (!dev->dma_capable || !dev->req->long_data)
return -EINVAL;
len = dev->req->sg.length;
is_write = dev->req->data_dir == WRITE;
if (len != R592_LFIFO_SIZE)
return -EINVAL;
dbg_verbose("doing dma transfer");
dev->dma_error = 0;
INIT_COMPLETION(dev->dma_done);
sg_count = dma_map_sg(&dev->pci_dev->dev, &dev->req->sg, 1, is_write ?
PCI_DMA_TODEVICE : PCI_DMA_FROMDEVICE);
if (sg_count != 1 ||
(sg_dma_len(&dev->req->sg) < dev->req->sg.length)) {
message("problem in dma_map_sg");
return -EIO;
}
r592_start_dma(dev, is_write);
if (!wait_for_completion_timeout(
&dev->dma_done, msecs_to_jiffies(1000))) {
message("DMA timeout");
r592_stop_dma(dev, -ETIMEDOUT);
}
dma_unmap_sg(&dev->pci_dev->dev, &dev->req->sg, 1, is_write ?
PCI_DMA_TODEVICE : PCI_DMA_FROMDEVICE);
return dev->dma_error;
}
static void r592_write_fifo_pio(struct r592_device *dev,
unsigned char *buffer, int len)
{
if (!kfifo_is_empty(&dev->pio_fifo)) {
u8 tmp[4] = {0};
int copy_len = kfifo_in(&dev->pio_fifo, buffer, len);
if (!kfifo_is_full(&dev->pio_fifo))
return;
len -= copy_len;
buffer += copy_len;
copy_len = kfifo_out(&dev->pio_fifo, tmp, 4);
WARN_ON(copy_len != 4);
r592_write_reg_raw_be(dev, R592_FIFO_PIO, *(u32 *)tmp);
}
WARN_ON(!kfifo_is_empty(&dev->pio_fifo));
while (len >= 4) {
r592_write_reg_raw_be(dev, R592_FIFO_PIO, *(u32 *)buffer);
buffer += 4;
len -= 4;
}
if (len)
kfifo_in(&dev->pio_fifo, buffer, len);
}
static void r592_flush_fifo_write(struct r592_device *dev)
{
u8 buffer[4] = { 0 };
int len;
if (kfifo_is_empty(&dev->pio_fifo))
return;
len = kfifo_out(&dev->pio_fifo, buffer, 4);
r592_write_reg_raw_be(dev, R592_FIFO_PIO, *(u32 *)buffer);
}
static void r592_read_fifo_pio(struct r592_device *dev,
unsigned char *buffer, int len)
{
u8 tmp[4];
if (!kfifo_is_empty(&dev->pio_fifo)) {
int bytes_copied =
kfifo_out(&dev->pio_fifo, buffer, min(4, len));
buffer += bytes_copied;
len -= bytes_copied;
if (!kfifo_is_empty(&dev->pio_fifo))
return;
}
while (len >= 4) {
*(u32 *)buffer = r592_read_reg_raw_be(dev, R592_FIFO_PIO);
buffer += 4;
len -= 4;
}
if (len) {
*(u32 *)tmp = r592_read_reg_raw_be(dev, R592_FIFO_PIO);
kfifo_in(&dev->pio_fifo, tmp, 4);
len -= kfifo_out(&dev->pio_fifo, buffer, len);
}
WARN_ON(len);
return;
}
static int r592_transfer_fifo_pio(struct r592_device *dev)
{
unsigned long flags;
bool is_write = dev->req->tpc >= MS_TPC_SET_RW_REG_ADRS;
struct sg_mapping_iter miter;
kfifo_reset(&dev->pio_fifo);
if (!dev->req->long_data) {
if (is_write) {
r592_write_fifo_pio(dev, dev->req->data,
dev->req->data_len);
r592_flush_fifo_write(dev);
} else
r592_read_fifo_pio(dev, dev->req->data,
dev->req->data_len);
return 0;
}
local_irq_save(flags);
sg_miter_start(&miter, &dev->req->sg, 1, SG_MITER_ATOMIC |
(is_write ? SG_MITER_FROM_SG : SG_MITER_TO_SG));
while (sg_miter_next(&miter))
if (is_write)
r592_write_fifo_pio(dev, miter.addr, miter.length);
else
r592_read_fifo_pio(dev, miter.addr, miter.length);
if (is_write)
r592_flush_fifo_write(dev);
sg_miter_stop(&miter);
local_irq_restore(flags);
return 0;
}
static void r592_execute_tpc(struct r592_device *dev)
{
bool is_write;
int len, error;
u32 status, reg;
if (!dev->req) {
message("BUG: tpc execution without request!");
return;
}
is_write = dev->req->tpc >= MS_TPC_SET_RW_REG_ADRS;
len = dev->req->long_data ?
dev->req->sg.length : dev->req->data_len;
if (len > R592_LFIFO_SIZE) {
message("IO: hardware doesn't support TPCs longer that 512");
error = -ENOSYS;
goto out;
}
if (!(r592_read_reg(dev, R592_REG_MSC) & R592_REG_MSC_PRSNT)) {
dbg("IO: refusing to send TPC because card is absent");
error = -ENODEV;
goto out;
}
dbg("IO: executing %s LEN=%d",
memstick_debug_get_tpc_name(dev->req->tpc), len);
if (is_write)
r592_set_reg_mask(dev, R592_IO, R592_IO_DIRECTION);
else
r592_clear_reg_mask(dev, R592_IO, R592_IO_DIRECTION);
error = r592_test_fifo_empty(dev);
if (error)
goto out;
if (is_write) {
error = r592_transfer_fifo_dma(dev);
if (error == -EINVAL)
error = r592_transfer_fifo_pio(dev);
}
if (error)
goto out;
reg = (len << R592_TPC_EXEC_LEN_SHIFT) |
(dev->req->tpc << R592_TPC_EXEC_TPC_SHIFT) |
R592_TPC_EXEC_BIG_FIFO;
r592_write_reg(dev, R592_TPC_EXEC, reg);
status = R592_STATUS_RDY;
if (dev->req->need_card_int)
status |= R592_STATUS_CED;
error = r592_wait_status(dev, status, status);
if (error) {
message("card didn't respond");
goto out;
}
error = r592_test_io_error(dev);
if (error) {
dbg("IO error");
goto out;
}
if (!is_write) {
error = r592_transfer_fifo_dma(dev);
if (error == -EINVAL)
error = r592_transfer_fifo_pio(dev);
}
if (dev->parallel_mode && dev->req->need_card_int) {
dev->req->int_reg = 0;
status = r592_read_reg(dev, R592_STATUS);
if (status & R592_STATUS_P_CMDNACK)
dev->req->int_reg |= MEMSTICK_INT_CMDNAK;
if (status & R592_STATUS_P_BREQ)
dev->req->int_reg |= MEMSTICK_INT_BREQ;
if (status & R592_STATUS_P_INTERR)
dev->req->int_reg |= MEMSTICK_INT_ERR;
if (status & R592_STATUS_P_CED)
dev->req->int_reg |= MEMSTICK_INT_CED;
}
if (error)
dbg("FIFO read error");
out:
dev->req->error = error;
r592_clear_reg_mask(dev, R592_REG_MSC, R592_REG_MSC_LED);
return;
}
static int r592_process_thread(void *data)
{
int error;
struct r592_device *dev = (struct r592_device *)data;
unsigned long flags;
while (!kthread_should_stop()) {
spin_lock_irqsave(&dev->io_thread_lock, flags);
set_current_state(TASK_INTERRUPTIBLE);
error = memstick_next_req(dev->host, &dev->req);
spin_unlock_irqrestore(&dev->io_thread_lock, flags);
if (error) {
if (error == -ENXIO || error == -EAGAIN) {
dbg_verbose("IO: done IO, sleeping");
} else {
dbg("IO: unknown error from "
"memstick_next_req %d", error);
}
if (kthread_should_stop())
set_current_state(TASK_RUNNING);
schedule();
} else {
set_current_state(TASK_RUNNING);
r592_execute_tpc(dev);
}
}
return 0;
}
static void r592_update_card_detect(struct r592_device *dev)
{
u32 reg = r592_read_reg(dev, R592_REG_MSC);
bool card_detected = reg & R592_REG_MSC_PRSNT;
dbg("update card detect. card state: %s", card_detected ?
"present" : "absent");
reg &= ~((R592_REG_MSC_IRQ_REMOVE | R592_REG_MSC_IRQ_INSERT) << 16);
if (card_detected)
reg |= (R592_REG_MSC_IRQ_REMOVE << 16);
else
reg |= (R592_REG_MSC_IRQ_INSERT << 16);
r592_write_reg(dev, R592_REG_MSC, reg);
}
static void r592_detect_timer(long unsigned int data)
{
struct r592_device *dev = (struct r592_device *)data;
r592_update_card_detect(dev);
memstick_detect_change(dev->host);
}
static irqreturn_t r592_irq(int irq, void *data)
{
struct r592_device *dev = (struct r592_device *)data;
irqreturn_t ret = IRQ_NONE;
u32 reg;
u16 irq_enable, irq_status;
unsigned long flags;
int error;
spin_lock_irqsave(&dev->irq_lock, flags);
reg = r592_read_reg(dev, R592_REG_MSC);
irq_enable = reg >> 16;
irq_status = reg & 0xFFFF;
reg &= ~irq_status;
r592_write_reg(dev, R592_REG_MSC, reg);
irq_status &= (irq_enable);
if (irq_status & (R592_REG_MSC_IRQ_INSERT | R592_REG_MSC_IRQ_REMOVE)) {
bool card_was_added = irq_status & R592_REG_MSC_IRQ_INSERT;
ret = IRQ_HANDLED;
message("IRQ: card %s", card_was_added ? "added" : "removed");
mod_timer(&dev->detect_timer,
jiffies + msecs_to_jiffies(card_was_added ? 500 : 50));
}
if (irq_status &
(R592_REG_MSC_FIFO_DMA_DONE | R592_REG_MSC_FIFO_DMA_ERR)) {
ret = IRQ_HANDLED;
if (irq_status & R592_REG_MSC_FIFO_DMA_ERR) {
message("IRQ: DMA error");
error = -EIO;
} else {
dbg_verbose("IRQ: dma done");
error = 0;
}
r592_stop_dma(dev, error);
complete(&dev->dma_done);
}
spin_unlock_irqrestore(&dev->irq_lock, flags);
return ret;
}
static int r592_set_param(struct memstick_host *host,
enum memstick_param param, int value)
{
struct r592_device *dev = memstick_priv(host);
switch (param) {
case MEMSTICK_POWER:
switch (value) {
case MEMSTICK_POWER_ON:
return r592_enable_device(dev, true);
case MEMSTICK_POWER_OFF:
return r592_enable_device(dev, false);
default:
return -EINVAL;
}
case MEMSTICK_INTERFACE:
switch (value) {
case MEMSTICK_SERIAL:
return r592_set_mode(dev, 0);
case MEMSTICK_PAR4:
return r592_set_mode(dev, 1);
default:
return -EINVAL;
}
default:
return -EINVAL;
}
}
static void r592_submit_req(struct memstick_host *host)
{
struct r592_device *dev = memstick_priv(host);
unsigned long flags;
if (dev->req)
return;
spin_lock_irqsave(&dev->io_thread_lock, flags);
if (wake_up_process(dev->io_thread))
dbg_verbose("IO thread woken to process requests");
spin_unlock_irqrestore(&dev->io_thread_lock, flags);
}
static int r592_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
int error = -ENOMEM;
struct memstick_host *host;
struct r592_device *dev;
host = memstick_alloc_host(sizeof(struct r592_device), &pdev->dev);
if (!host)
goto error1;
dev = memstick_priv(host);
dev->host = host;
dev->pci_dev = pdev;
pci_set_drvdata(pdev, dev);
error = pci_enable_device(pdev);
if (error)
goto error2;
pci_set_master(pdev);
error = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (error)
goto error3;
error = pci_request_regions(pdev, DRV_NAME);
if (error)
goto error3;
dev->mmio = pci_ioremap_bar(pdev, 0);
if (!dev->mmio)
goto error4;
dev->irq = pdev->irq;
spin_lock_init(&dev->irq_lock);
spin_lock_init(&dev->io_thread_lock);
init_completion(&dev->dma_done);
INIT_KFIFO(dev->pio_fifo);
setup_timer(&dev->detect_timer,
r592_detect_timer, (long unsigned int)dev);
host->caps = MEMSTICK_CAP_PAR4;
host->request = r592_submit_req;
host->set_param = r592_set_param;
r592_check_dma(dev);
dev->io_thread = kthread_run(r592_process_thread, dev, "r592_io");
if (IS_ERR(dev->io_thread)) {
error = PTR_ERR(dev->io_thread);
goto error5;
}
dev->dummy_dma_page = pci_alloc_consistent(pdev, PAGE_SIZE,
&dev->dummy_dma_page_physical_address);
r592_stop_dma(dev , 0);
if (request_irq(dev->irq, &r592_irq, IRQF_SHARED,
DRV_NAME, dev))
goto error6;
r592_update_card_detect(dev);
if (memstick_add_host(host))
goto error7;
message("driver successfully loaded");
return 0;
error7:
free_irq(dev->irq, dev);
error6:
if (dev->dummy_dma_page)
pci_free_consistent(pdev, PAGE_SIZE, dev->dummy_dma_page,
dev->dummy_dma_page_physical_address);
kthread_stop(dev->io_thread);
error5:
iounmap(dev->mmio);
error4:
pci_release_regions(pdev);
error3:
pci_disable_device(pdev);
error2:
memstick_free_host(host);
error1:
return error;
}
static void r592_remove(struct pci_dev *pdev)
{
int error = 0;
struct r592_device *dev = pci_get_drvdata(pdev);
kthread_stop(dev->io_thread);
r592_enable_device(dev, false);
while (!error && dev->req) {
dev->req->error = -ETIME;
error = memstick_next_req(dev->host, &dev->req);
}
memstick_remove_host(dev->host);
free_irq(dev->irq, dev);
iounmap(dev->mmio);
pci_release_regions(pdev);
pci_disable_device(pdev);
memstick_free_host(dev->host);
if (dev->dummy_dma_page)
pci_free_consistent(pdev, PAGE_SIZE, dev->dummy_dma_page,
dev->dummy_dma_page_physical_address);
}
static int r592_suspend(struct device *core_dev)
{
struct pci_dev *pdev = to_pci_dev(core_dev);
struct r592_device *dev = pci_get_drvdata(pdev);
r592_clear_interrupts(dev);
memstick_suspend_host(dev->host);
del_timer_sync(&dev->detect_timer);
return 0;
}
static int r592_resume(struct device *core_dev)
{
struct pci_dev *pdev = to_pci_dev(core_dev);
struct r592_device *dev = pci_get_drvdata(pdev);
r592_clear_interrupts(dev);
r592_enable_device(dev, false);
memstick_resume_host(dev->host);
r592_update_card_detect(dev);
return 0;
}
static __init int r592_module_init(void)
{
return pci_register_driver(&r852_pci_driver);
}
static void __exit r592_module_exit(void)
{
pci_unregister_driver(&r852_pci_driver);
}
