void et131x_enable_interrupts(struct et131x_adapter *adapter)
{
u32 mask;
if (adapter->flowcontrol == FLOW_TXONLY || adapter->flowcontrol == FLOW_BOTH)
mask = INT_MASK_ENABLE;
else
mask = INT_MASK_ENABLE_NO_FLOW;
adapter->CachedMaskValue = mask;
writel(mask, &adapter->regs->global.int_mask);
}
void et131x_disable_interrupts(struct et131x_adapter *adapter)
{
adapter->CachedMaskValue = INT_MASK_DISABLE;
writel(INT_MASK_DISABLE, &adapter->regs->global.int_mask);
}
irqreturn_t et131x_isr(int irq, void *dev_id)
{
bool handled = true;
struct net_device *netdev = (struct net_device *)dev_id;
struct et131x_adapter *adapter = NULL;
u32 status;
if (!netif_device_present(netdev)) {
handled = false;
goto out;
}
adapter = netdev_priv(netdev);
et131x_disable_interrupts(adapter);
status = readl(&adapter->regs->global.int_status);
if (adapter->flowcontrol == FLOW_TXONLY ||
adapter->flowcontrol == FLOW_BOTH) {
status &= ~INT_MASK_ENABLE;
} else {
status &= ~INT_MASK_ENABLE_NO_FLOW;
}
if (!status) {
handled = false;
et131x_enable_interrupts(adapter);
goto out;
}
if (status & ET_INTR_WATCHDOG) {
struct tcb *tcb = adapter->tx_ring.send_head;
if (tcb)
if (++tcb->stale > 1)
status |= ET_INTR_TXDMA_ISR;
if (adapter->rx_ring.UnfinishedReceives)
status |= ET_INTR_RXDMA_XFR_DONE;
else if (tcb == NULL)
writel(0, &adapter->regs->global.watchdog_timer);
status &= ~ET_INTR_WATCHDOG;
}
if (status == 0) {
et131x_enable_interrupts(adapter);
goto out;
}
adapter->stats.InterruptStatus = status;
schedule_work(&adapter->task);
out:
return IRQ_RETVAL(handled);
}
void et131x_isr_handler(struct work_struct *work)
{
struct et131x_adapter *etdev =
container_of(work, struct et131x_adapter, task);
u32 status = etdev->stats.InterruptStatus;
struct address_map __iomem *iomem = etdev->regs;
if (status & ET_INTR_TXDMA_ISR)
et131x_handle_send_interrupt(etdev);
if (status & ET_INTR_RXDMA_XFR_DONE)
et131x_handle_recv_interrupt(etdev);
status &= 0xffffffd7;
if (status) {
if (status & ET_INTR_TXDMA_ERR) {
u32 txdma_err;
txdma_err = readl(&iomem->txdma.tx_dma_error);
dev_warn(&etdev->pdev->dev,
"TXDMA_ERR interrupt, error = %d\n",
txdma_err);
}
if (status & (ET_INTR_RXDMA_FB_R0_LOW | ET_INTR_RXDMA_FB_R1_LOW)) {
if (etdev->flowcontrol == FLOW_TXONLY ||
etdev->flowcontrol == FLOW_BOTH) {
u32 pm_csr;
pm_csr = readl(&iomem->global.pm_csr);
if ((pm_csr & ET_PM_PHY_SW_COMA) == 0)
writel(3, &iomem->txmac.bp_ctrl);
}
}
if (status & ET_INTR_RXDMA_STAT_LOW) {
}
if (status & ET_INTR_RXDMA_ERR) {
dev_warn(&etdev->pdev->dev,
"RxDMA_ERR interrupt, error %x\n",
readl(&iomem->txmac.tx_test));
}
if (status & ET_INTR_WOL) {
dev_err(&etdev->pdev->dev, "WAKE_ON_LAN interrupt\n");
}
if (status & ET_INTR_PHY) {
u32 pm_csr;
u16 bmsr_ints;
u16 bmsr_data;
u16 myisr;
pm_csr = readl(&iomem->global.pm_csr);
if (pm_csr & ET_PM_PHY_SW_COMA) {
DisablePhyComa(etdev);
}
MiRead(etdev, (uint8_t) offsetof(struct mi_regs, isr),
&myisr);
if (!etdev->ReplicaPhyLoopbk) {
MiRead(etdev,
(uint8_t) offsetof(struct mi_regs, bmsr),
&bmsr_data);
bmsr_ints = etdev->bmsr ^ bmsr_data;
etdev->bmsr = bmsr_data;
et131x_Mii_check(etdev, bmsr_data, bmsr_ints);
}
}
if (status & ET_INTR_TXMAC) {
u32 err = readl(&iomem->txmac.err);
dev_warn(&etdev->pdev->dev,
"TXMAC interrupt, error 0x%08x\n",
err);
}
if (status & ET_INTR_RXMAC) {
dev_warn(&etdev->pdev->dev,
"RXMAC interrupt, error 0x%08x. Requesting reset\n",
readl(&iomem->rxmac.err_reg));
dev_warn(&etdev->pdev->dev,
"Enable 0x%08x, Diag 0x%08x\n",
readl(&iomem->rxmac.ctrl),
readl(&iomem->rxmac.rxq_diag));
}
if (status & ET_INTR_MAC_STAT) {
HandleMacStatInterrupt(etdev);
}
if (status & ET_INTR_SLV_TIMEOUT) {
}
}
et131x_enable_interrupts(etdev);
}
