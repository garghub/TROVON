void EnablePhyComa(struct et131x_adapter *etdev)
{
unsigned long flags;
u32 pmcsr;
pmcsr = readl(&etdev->regs->global.pm_csr);
etdev->pdown_speed = etdev->AiForceSpeed;
etdev->pdown_duplex = etdev->AiForceDpx;
spin_lock_irqsave(&etdev->send_hw_lock, flags);
etdev->Flags |= fMP_ADAPTER_LOWER_POWER;
spin_unlock_irqrestore(&etdev->send_hw_lock, flags);
pmcsr &= ~ET_PMCSR_INIT;
writel(pmcsr, &etdev->regs->global.pm_csr);
pmcsr |= ET_PM_PHY_SW_COMA;
writel(pmcsr, &etdev->regs->global.pm_csr);
}
void DisablePhyComa(struct et131x_adapter *etdev)
{
u32 pmcsr;
pmcsr = readl(&etdev->regs->global.pm_csr);
pmcsr |= ET_PMCSR_INIT;
pmcsr &= ~ET_PM_PHY_SW_COMA;
writel(pmcsr, &etdev->regs->global.pm_csr);
etdev->AiForceSpeed = etdev->pdown_speed;
etdev->AiForceDpx = etdev->pdown_duplex;
et131x_init_send(etdev);
et131x_reset_recv(etdev);
et131x_soft_reset(etdev);
et131x_adapter_setup(etdev);
etdev->Flags &= ~fMP_ADAPTER_LOWER_POWER;
et131x_rx_dma_enable(etdev);
}
