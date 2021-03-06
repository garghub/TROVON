static irqreturn_t aac_src_intr_message(int irq, void *dev_id)
{
struct aac_dev *dev = dev_id;
unsigned long bellbits, bellbits_shifted;
int our_interrupt = 0;
int isFastResponse;
u32 index, handle;
bellbits = src_readl(dev, MUnit.ODR_R);
if (bellbits & PmDoorBellResponseSent) {
bellbits = PmDoorBellResponseSent;
our_interrupt = 1;
index = dev->host_rrq_idx;
if (dev->host_rrq[index] == 0) {
u32 old_index = index;
do {
index++;
if (index == dev->scsi_host_ptr->can_queue +
AAC_NUM_MGT_FIB)
index = 0;
if (dev->host_rrq[index] != 0)
break;
} while (index != old_index);
dev->host_rrq_idx = index;
}
for (;;) {
isFastResponse = 0;
handle = (dev->host_rrq[index] & 0x7fffffff);
if (handle & 0x40000000)
isFastResponse = 1;
handle &= 0x0000ffff;
if (handle == 0)
break;
aac_intr_normal(dev, handle-1, 0, isFastResponse, NULL);
dev->host_rrq[index++] = 0;
if (index == dev->scsi_host_ptr->can_queue +
AAC_NUM_MGT_FIB)
index = 0;
dev->host_rrq_idx = index;
}
} else {
bellbits_shifted = (bellbits >> SRC_ODR_SHIFT);
if (bellbits_shifted & DoorBellAifPending) {
our_interrupt = 1;
aac_intr_normal(dev, 0, 2, 0, NULL);
}
}
if (our_interrupt) {
src_writel(dev, MUnit.ODR_C, bellbits);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static void aac_src_disable_interrupt(struct aac_dev *dev)
{
src_writel(dev, MUnit.OIMR, dev->OIMR = 0xffffffff);
}
static void aac_src_enable_interrupt_message(struct aac_dev *dev)
{
src_writel(dev, MUnit.OIMR, dev->OIMR = 0xfffffff8);
}
static int src_sync_cmd(struct aac_dev *dev, u32 command,
u32 p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6,
u32 *status, u32 * r1, u32 * r2, u32 * r3, u32 * r4)
{
unsigned long start;
int ok;
writel(command, &dev->IndexRegs->Mailbox[0]);
writel(p1, &dev->IndexRegs->Mailbox[1]);
writel(p2, &dev->IndexRegs->Mailbox[2]);
writel(p3, &dev->IndexRegs->Mailbox[3]);
writel(p4, &dev->IndexRegs->Mailbox[4]);
src_writel(dev, MUnit.ODR_C, OUTBOUNDDOORBELL_0 << SRC_ODR_SHIFT);
src_writel(dev, MUnit.OIMR, dev->OIMR = 0xffffffff);
src_readl(dev, MUnit.OIMR);
src_writel(dev, MUnit.IDR, INBOUNDDOORBELL_0 << SRC_IDR_SHIFT);
ok = 0;
start = jiffies;
while (time_before(jiffies, start+30*HZ)) {
udelay(5);
if ((src_readl(dev, MUnit.ODR_R) >> SRC_ODR_SHIFT) & OUTBOUNDDOORBELL_0) {
src_writel(dev,
MUnit.ODR_C,
OUTBOUNDDOORBELL_0 << SRC_ODR_SHIFT);
ok = 1;
break;
}
msleep(1);
}
if (unlikely(ok != 1)) {
aac_adapter_enable_int(dev);
return -ETIMEDOUT;
}
if (status)
*status = readl(&dev->IndexRegs->Mailbox[0]);
if (r1)
*r1 = readl(&dev->IndexRegs->Mailbox[1]);
if (r2)
*r2 = readl(&dev->IndexRegs->Mailbox[2]);
if (r3)
*r3 = readl(&dev->IndexRegs->Mailbox[3]);
if (r4)
*r4 = readl(&dev->IndexRegs->Mailbox[4]);
src_writel(dev, MUnit.ODR_C, OUTBOUNDDOORBELL_0 << SRC_ODR_SHIFT);
aac_adapter_enable_int(dev);
return 0;
}
static void aac_src_interrupt_adapter(struct aac_dev *dev)
{
src_sync_cmd(dev, BREAKPOINT_REQUEST,
0, 0, 0, 0, 0, 0,
NULL, NULL, NULL, NULL, NULL);
}
static void aac_src_notify_adapter(struct aac_dev *dev, u32 event)
{
switch (event) {
case AdapNormCmdQue:
src_writel(dev, MUnit.ODR_C,
INBOUNDDOORBELL_1 << SRC_ODR_SHIFT);
break;
case HostNormRespNotFull:
src_writel(dev, MUnit.ODR_C,
INBOUNDDOORBELL_4 << SRC_ODR_SHIFT);
break;
case AdapNormRespQue:
src_writel(dev, MUnit.ODR_C,
INBOUNDDOORBELL_2 << SRC_ODR_SHIFT);
break;
case HostNormCmdNotFull:
src_writel(dev, MUnit.ODR_C,
INBOUNDDOORBELL_3 << SRC_ODR_SHIFT);
break;
case FastIo:
src_writel(dev, MUnit.ODR_C,
INBOUNDDOORBELL_6 << SRC_ODR_SHIFT);
break;
case AdapPrintfDone:
src_writel(dev, MUnit.ODR_C,
INBOUNDDOORBELL_5 << SRC_ODR_SHIFT);
break;
default:
BUG();
break;
}
}
static void aac_src_start_adapter(struct aac_dev *dev)
{
struct aac_init *init;
init = dev->init;
init->HostElapsedSeconds = cpu_to_le32(get_seconds());
src_sync_cmd(dev, INIT_STRUCT_BASE_ADDRESS, (u32)(ulong)dev->init_pa,
0, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL);
}
static int aac_src_check_health(struct aac_dev *dev)
{
u32 status = src_readl(dev, MUnit.OMR);
if (unlikely(status & SELF_TEST_FAILED))
return -1;
if (unlikely(status & KERNEL_PANIC))
return (status >> 16) & 0xFF;
if (unlikely(!(status & KERNEL_UP_AND_RUNNING)))
return -3;
return 0;
}
static int aac_src_deliver_message(struct fib *fib)
{
struct aac_dev *dev = fib->dev;
struct aac_queue *q = &dev->queues->queue[AdapNormCmdQueue];
unsigned long qflags;
u32 fibsize;
u64 address;
struct aac_fib_xporthdr *pFibX;
spin_lock_irqsave(q->lock, qflags);
q->numpending++;
spin_unlock_irqrestore(q->lock, qflags);
fibsize = (sizeof(struct aac_fib_xporthdr) +
fib->hw_fib_va->header.Size + 127) / 128 - 1;
if (fibsize > (ALIGN32 - 1))
fibsize = ALIGN32 - 1;
pFibX = (struct aac_fib_xporthdr *)
((unsigned char *)fib->hw_fib_va -
sizeof(struct aac_fib_xporthdr));
pFibX->Handle = fib->hw_fib_va->header.SenderData + 1;
pFibX->HostAddress = fib->hw_fib_pa;
pFibX->Size = fib->hw_fib_va->header.Size;
address = fib->hw_fib_pa - (u64)sizeof(struct aac_fib_xporthdr);
src_writel(dev, MUnit.IQ_H, (u32)(address >> 32));
src_writel(dev, MUnit.IQ_L, (u32)(address & 0xffffffff) + fibsize);
return 0;
}
static int aac_src_ioremap(struct aac_dev *dev, u32 size)
{
if (!size) {
iounmap(dev->regs.src.bar0);
dev->regs.src.bar0 = NULL;
iounmap(dev->base);
dev->base = NULL;
return 0;
}
dev->regs.src.bar1 = ioremap(pci_resource_start(dev->pdev, 2),
AAC_MIN_SRC_BAR1_SIZE);
dev->base = NULL;
if (dev->regs.src.bar1 == NULL)
return -1;
dev->base = dev->regs.src.bar0 = ioremap(dev->scsi_host_ptr->base,
size);
if (dev->base == NULL) {
iounmap(dev->regs.src.bar1);
dev->regs.src.bar1 = NULL;
return -1;
}
dev->IndexRegs = &((struct src_registers __iomem *)
dev->base)->IndexRegs;
return 0;
}
static int aac_src_restart_adapter(struct aac_dev *dev, int bled)
{
u32 var, reset_mask;
if (bled >= 0) {
if (bled)
printk(KERN_ERR "%s%d: adapter kernel panic'd %x.\n",
dev->name, dev->id, bled);
bled = aac_adapter_sync_cmd(dev, IOP_RESET_ALWAYS,
0, 0, 0, 0, 0, 0, &var, &reset_mask, NULL, NULL, NULL);
if (bled || (var != 0x00000001))
bled = -EINVAL;
if (dev->supplement_adapter_info.SupportedOptions2 &
AAC_OPTION_DOORBELL_RESET) {
src_writel(dev, MUnit.IDR, reset_mask);
msleep(5000);
}
}
if (src_readl(dev, MUnit.OMR) & KERNEL_PANIC)
return -ENODEV;
if (startup_timeout < 300)
startup_timeout = 300;
return 0;
}
int aac_src_select_comm(struct aac_dev *dev, int comm)
{
switch (comm) {
case AAC_COMM_MESSAGE:
dev->a_ops.adapter_enable_int = aac_src_enable_interrupt_message;
dev->a_ops.adapter_intr = aac_src_intr_message;
dev->a_ops.adapter_deliver = aac_src_deliver_message;
break;
default:
return 1;
}
return 0;
}
int aac_src_init(struct aac_dev *dev)
{
unsigned long start;
unsigned long status;
int restart = 0;
int instance = dev->id;
const char *name = dev->name;
dev->a_ops.adapter_ioremap = aac_src_ioremap;
dev->a_ops.adapter_comm = aac_src_select_comm;
dev->base_size = AAC_MIN_SRC_BAR0_SIZE;
if (aac_adapter_ioremap(dev, dev->base_size)) {
printk(KERN_WARNING "%s: unable to map adapter.\n", name);
goto error_iounmap;
}
dev->a_ops.adapter_sync_cmd = src_sync_cmd;
dev->a_ops.adapter_enable_int = aac_src_disable_interrupt;
if ((aac_reset_devices || reset_devices) &&
!aac_src_restart_adapter(dev, 0))
++restart;
status = src_readl(dev, MUnit.OMR);
if (status & KERNEL_PANIC) {
if (aac_src_restart_adapter(dev, aac_src_check_health(dev)))
goto error_iounmap;
++restart;
}
status = src_readl(dev, MUnit.OMR);
if (status & SELF_TEST_FAILED) {
printk(KERN_ERR "%s%d: adapter self-test failed.\n",
dev->name, instance);
goto error_iounmap;
}
if (status & MONITOR_PANIC) {
printk(KERN_ERR "%s%d: adapter monitor panic.\n",
dev->name, instance);
goto error_iounmap;
}
start = jiffies;
while (!((status = src_readl(dev, MUnit.OMR)) &
KERNEL_UP_AND_RUNNING)) {
if ((restart &&
(status & (KERNEL_PANIC|SELF_TEST_FAILED|MONITOR_PANIC))) ||
time_after(jiffies, start+HZ*startup_timeout)) {
printk(KERN_ERR "%s%d: adapter kernel failed to start, init status = %lx.\n",
dev->name, instance, status);
goto error_iounmap;
}
if (!restart &&
((status & (KERNEL_PANIC|SELF_TEST_FAILED|MONITOR_PANIC)) ||
time_after(jiffies, start + HZ *
((startup_timeout > 60)
? (startup_timeout - 60)
: (startup_timeout / 2))))) {
if (likely(!aac_src_restart_adapter(dev,
aac_src_check_health(dev))))
start = jiffies;
++restart;
}
msleep(1);
}
if (restart && aac_commit)
aac_commit = 1;
dev->a_ops.adapter_interrupt = aac_src_interrupt_adapter;
dev->a_ops.adapter_disable_int = aac_src_disable_interrupt;
dev->a_ops.adapter_notify = aac_src_notify_adapter;
dev->a_ops.adapter_sync_cmd = src_sync_cmd;
dev->a_ops.adapter_check_health = aac_src_check_health;
dev->a_ops.adapter_restart = aac_src_restart_adapter;
aac_adapter_comm(dev, AAC_COMM_MESSAGE);
aac_adapter_disable_int(dev);
src_writel(dev, MUnit.ODR_C, 0xffffffff);
aac_adapter_enable_int(dev);
if (aac_init_adapter(dev) == NULL)
goto error_iounmap;
if (dev->comm_interface != AAC_COMM_MESSAGE_TYPE1)
goto error_iounmap;
dev->msi = aac_msi && !pci_enable_msi(dev->pdev);
if (request_irq(dev->pdev->irq, dev->a_ops.adapter_intr,
IRQF_SHARED|IRQF_DISABLED, "aacraid", dev) < 0) {
if (dev->msi)
pci_disable_msi(dev->pdev);
printk(KERN_ERR "%s%d: Interrupt unavailable.\n",
name, instance);
goto error_iounmap;
}
dev->dbg_base = pci_resource_start(dev->pdev, 2);
dev->dbg_base_mapped = dev->regs.src.bar1;
dev->dbg_size = AAC_MIN_SRC_BAR1_SIZE;
aac_adapter_enable_int(dev);
aac_src_start_adapter(dev);
return 0;
error_iounmap:
return -1;
}
