static inline void msm_a2m_int(uint32_t irq)
{
#if defined(CONFIG_ARCH_MSM7X30)
writel(1 << irq, MSM_GCC_BASE + 0x8);
#else
writel(1, MSM_CSR_BASE + 0x400 + (irq * 4));
#endif
}
static inline void notify_other_proc_comm(void)
{
msm_a2m_int(6);
}
static int proc_comm_wait_for(void __iomem *addr, unsigned value)
{
for (;;) {
if (readl(addr) == value)
return 0;
if (msm_check_for_modem_crash)
if (msm_check_for_modem_crash())
return -EAGAIN;
}
}
int msm_proc_comm(unsigned cmd, unsigned *data1, unsigned *data2)
{
void __iomem *base = MSM_SHARED_RAM_BASE;
unsigned long flags;
int ret;
spin_lock_irqsave(&proc_comm_lock, flags);
for (;;) {
if (proc_comm_wait_for(base + MDM_STATUS, PCOM_READY))
continue;
writel(cmd, base + APP_COMMAND);
writel(data1 ? *data1 : 0, base + APP_DATA1);
writel(data2 ? *data2 : 0, base + APP_DATA2);
notify_other_proc_comm();
if (proc_comm_wait_for(base + APP_COMMAND, PCOM_CMD_DONE))
continue;
if (readl(base + APP_STATUS) != PCOM_CMD_FAIL) {
if (data1)
*data1 = readl(base + APP_DATA1);
if (data2)
*data2 = readl(base + APP_DATA2);
ret = 0;
} else {
ret = -EIO;
}
break;
}
writel(PCOM_CMD_IDLE, base + APP_COMMAND);
spin_unlock_irqrestore(&proc_comm_lock, flags);
return ret;
}
void proc_comm_boot_wait(void)
{
void __iomem *base = MSM_SHARED_RAM_BASE;
proc_comm_wait_for(base + MDM_STATUS, PCOM_READY);
}
