static inline void set_destination(int source, int mbox)
{
__raw_writel(CHAN_MASK(source), ipc_base + IPCMxDSET(mbox));
__raw_writel(CHAN_MASK(source), ipc_base + IPCMxMSET(mbox));
}
static inline void clear_destination(int source, int mbox)
{
__raw_writel(CHAN_MASK(source), ipc_base + IPCMxDCLEAR(mbox));
__raw_writel(CHAN_MASK(source), ipc_base + IPCMxMCLEAR(mbox));
}
static void __ipc_send(int mbox, u32 *data)
{
int i;
for (i = 0; i < 7; i++)
__raw_writel(data[i], ipc_base + IPCMxDR(mbox, i));
__raw_writel(0x1, ipc_base + IPCMxSEND(mbox));
}
static u32 __ipc_rcv(int mbox, u32 *data)
{
int i;
for (i = 0; i < 7; i++)
data[i] = __raw_readl(ipc_base + IPCMxDR(mbox, i));
return data[1];
}
int pl320_ipc_transmit(u32 *data)
{
int ret;
mutex_lock(&ipc_m1_lock);
init_completion(&ipc_completion);
__ipc_send(IPC_TX_MBOX, data);
ret = wait_for_completion_timeout(&ipc_completion,
msecs_to_jiffies(1000));
if (ret == 0) {
ret = -ETIMEDOUT;
goto out;
}
ret = __ipc_rcv(IPC_TX_MBOX, data);
out:
mutex_unlock(&ipc_m1_lock);
return ret;
}
static irqreturn_t ipc_handler(int irq, void *dev)
{
u32 irq_stat;
u32 data[7];
irq_stat = __raw_readl(ipc_base + IPCMMIS(1));
if (irq_stat & MBOX_MASK(IPC_TX_MBOX)) {
__raw_writel(0, ipc_base + IPCMxSEND(IPC_TX_MBOX));
complete(&ipc_completion);
}
if (irq_stat & MBOX_MASK(IPC_RX_MBOX)) {
__ipc_rcv(IPC_RX_MBOX, data);
atomic_notifier_call_chain(&ipc_notifier, data[0], data + 1);
__raw_writel(2, ipc_base + IPCMxSEND(IPC_RX_MBOX));
}
return IRQ_HANDLED;
}
int pl320_ipc_register_notifier(struct notifier_block *nb)
{
return atomic_notifier_chain_register(&ipc_notifier, nb);
}
int pl320_ipc_unregister_notifier(struct notifier_block *nb)
{
return atomic_notifier_chain_unregister(&ipc_notifier, nb);
}
static int pl320_probe(struct amba_device *adev, const struct amba_id *id)
{
int ret;
ipc_base = ioremap(adev->res.start, resource_size(&adev->res));
if (ipc_base == NULL)
return -ENOMEM;
__raw_writel(0, ipc_base + IPCMxSEND(IPC_TX_MBOX));
ipc_irq = adev->irq[0];
ret = request_irq(ipc_irq, ipc_handler, 0, dev_name(&adev->dev), NULL);
if (ret < 0)
goto err;
__raw_writel(CHAN_MASK(A9_SOURCE),
ipc_base + IPCMxSOURCE(IPC_TX_MBOX));
__raw_writel(CHAN_MASK(M3_SOURCE),
ipc_base + IPCMxDSET(IPC_TX_MBOX));
__raw_writel(CHAN_MASK(M3_SOURCE) | CHAN_MASK(A9_SOURCE),
ipc_base + IPCMxMSET(IPC_TX_MBOX));
__raw_writel(CHAN_MASK(M3_SOURCE),
ipc_base + IPCMxSOURCE(IPC_RX_MBOX));
__raw_writel(CHAN_MASK(A9_SOURCE),
ipc_base + IPCMxDSET(IPC_RX_MBOX));
__raw_writel(CHAN_MASK(M3_SOURCE) | CHAN_MASK(A9_SOURCE),
ipc_base + IPCMxMSET(IPC_RX_MBOX));
return 0;
err:
iounmap(ipc_base);
return ret;
}
static int __init ipc_init(void)
{
return amba_driver_register(&pl320_driver);
}
