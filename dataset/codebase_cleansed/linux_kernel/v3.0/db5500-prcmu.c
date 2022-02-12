int db5500_prcmu_abb_read(u8 slave, u8 reg, u8 *value, u8 size)
{
int r;
if ((size < 1) || (4 < size))
return -EINVAL;
mutex_lock(&mb5_transfer.lock);
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(5))
cpu_relax();
writeb(slave, PRCM_REQ_MB5_I2C_SLAVE);
writeb(reg, PRCM_REQ_MB5_I2C_REG);
writeb(size, PRCM_REQ_MB5_I2C_SIZE);
writeb(MB5H_I2C_READ, PRCM_REQ_MB5_HEADER);
writel(MBOX_BIT(5), PRCM_MBOX_CPU_SET);
wait_for_completion(&mb5_transfer.work);
r = 0;
if ((mb5_transfer.ack.header == MB5H_I2C_READ) &&
(mb5_transfer.ack.status == RC_SUCCESS))
memcpy(value, mb5_transfer.ack.value, (size_t)size);
else
r = -EIO;
mutex_unlock(&mb5_transfer.lock);
return r;
}
int db5500_prcmu_abb_write(u8 slave, u8 reg, u8 *value, u8 size)
{
int r;
if ((size < 1) || (4 < size))
return -EINVAL;
mutex_lock(&mb5_transfer.lock);
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(5))
cpu_relax();
writeb(slave, PRCM_REQ_MB5_I2C_SLAVE);
writeb(reg, PRCM_REQ_MB5_I2C_REG);
writeb(size, PRCM_REQ_MB5_I2C_SIZE);
memcpy_toio(PRCM_REQ_MB5_I2C_DATA, value, size);
writeb(MB5H_I2C_WRITE, PRCM_REQ_MB5_HEADER);
writel(MBOX_BIT(5), PRCM_MBOX_CPU_SET);
wait_for_completion(&mb5_transfer.work);
if ((mb5_transfer.ack.header == MB5H_I2C_WRITE) &&
(mb5_transfer.ack.status == RC_SUCCESS))
r = 0;
else
r = -EIO;
mutex_unlock(&mb5_transfer.lock);
return r;
}
int db5500_prcmu_enable_dsipll(void)
{
int i;
writel(PRCMU_RESET_DSIPLL, PRCM_APE_RESETN_CLR);
writel(PRCMU_UNCLAMP_DSIPLL, PRCM_MMIP_LS_CLAMP_CLR);
writel(PRCMU_PLLDSI_FREQ_SETTING, PRCM_PLLDSI_FREQ);
writel(PRCMU_DSI_PLLOUT_SEL_SETTING,
PRCM_DSI_PLLOUT_SEL);
writel(PRCMU_ENABLE_ESCAPE_CLOCK_DIV, PRCM_DSITVCLK_DIV);
writel(PRCMU_ENABLE_PLLDSI, PRCM_PLLDSI_ENABLE);
writel(PRCMU_DSI_RESET_SW, PRCM_DSI_SW_RESET);
for (i = 0; i < 10; i++) {
if ((readl(PRCM_PLLDSI_LOCKP) &
PRCMU_PLLDSI_LOCKP_LOCKED) == PRCMU_PLLDSI_LOCKP_LOCKED)
break;
udelay(100);
}
writel(PRCMU_RESET_DSIPLL, PRCM_APE_RESETN_SET);
return 0;
}
int db5500_prcmu_disable_dsipll(void)
{
writel(PRCMU_DISABLE_PLLDSI, PRCM_PLLDSI_ENABLE);
writel(PRCMU_DISABLE_ESCAPE_CLOCK_DIV, PRCM_DSITVCLK_DIV);
return 0;
}
int db5500_prcmu_set_display_clocks(void)
{
writel(PRCMU_DSI_CLOCK_SETTING, PRCM_HDMICLK_MGT);
writel(PRCMU_DSI_LP_CLOCK_SETTING, PRCM_TVCLK_MGT);
return 0;
}
static void ack_dbb_wakeup(void)
{
unsigned long flags;
spin_lock_irqsave(&mb0_transfer.lock, flags);
while (readl(PRCM_MBOX_CPU_VAL) & MBOX_BIT(0))
cpu_relax();
writeb(RMB0H_RD_WAKE_UP_ACK, PRCM_REQ_MB0_HEADER);
writel(MBOX_BIT(0), PRCM_MBOX_CPU_SET);
spin_unlock_irqrestore(&mb0_transfer.lock, flags);
}
static inline void print_unknown_header_warning(u8 n, u8 header)
{
pr_warning("prcmu: Unknown message header (%d) in mailbox %d.\n",
header, n);
}
static bool read_mailbox_0(void)
{
bool r;
u8 header;
header = readb(PRCM_ACK_MB0_HEADER);
switch (header) {
case AMB0H_WAKE_UP:
r = true;
break;
default:
print_unknown_header_warning(0, header);
r = false;
break;
}
writel(MBOX_BIT(0), PRCM_ARM_IT1_CLEAR);
return r;
}
static bool read_mailbox_1(void)
{
writel(MBOX_BIT(1), PRCM_ARM_IT1_CLEAR);
return false;
}
static bool read_mailbox_2(void)
{
writel(MBOX_BIT(2), PRCM_ARM_IT1_CLEAR);
return false;
}
static bool read_mailbox_3(void)
{
writel(MBOX_BIT(3), PRCM_ARM_IT1_CLEAR);
return false;
}
static bool read_mailbox_4(void)
{
writel(MBOX_BIT(4), PRCM_ARM_IT1_CLEAR);
return false;
}
static bool read_mailbox_5(void)
{
u8 header;
header = readb(PRCM_ACK_MB5_HEADER);
switch (header) {
case MB5H_I2C_READ:
memcpy_fromio(mb5_transfer.ack.value, PRCM_ACK_MB5_I2C_DATA, 4);
case MB5H_I2C_WRITE:
mb5_transfer.ack.header = header;
mb5_transfer.ack.status = readb(PRCM_ACK_MB5_RETURN_CODE);
complete(&mb5_transfer.work);
break;
default:
print_unknown_header_warning(5, header);
break;
}
writel(MBOX_BIT(5), PRCM_ARM_IT1_CLEAR);
return false;
}
static bool read_mailbox_6(void)
{
writel(MBOX_BIT(6), PRCM_ARM_IT1_CLEAR);
return false;
}
static bool read_mailbox_7(void)
{
writel(MBOX_BIT(7), PRCM_ARM_IT1_CLEAR);
return false;
}
static irqreturn_t prcmu_irq_handler(int irq, void *data)
{
u32 bits;
u8 n;
irqreturn_t r;
bits = (readl(PRCM_ARM_IT1_VAL) & ALL_MBOX_BITS);
if (unlikely(!bits))
return IRQ_NONE;
r = IRQ_HANDLED;
for (n = 0; bits; n++) {
if (bits & MBOX_BIT(n)) {
bits -= MBOX_BIT(n);
if (read_mailbox[n]())
r = IRQ_WAKE_THREAD;
}
}
return r;
}
static irqreturn_t prcmu_irq_thread_fn(int irq, void *data)
{
ack_dbb_wakeup();
return IRQ_HANDLED;
}
void __init db5500_prcmu_early_init(void)
{
tcdm_base = __io_address(U5500_PRCMU_TCDM_BASE);
spin_lock_init(&mb0_transfer.lock);
mutex_init(&mb5_transfer.lock);
init_completion(&mb5_transfer.work);
}
int __init db5500_prcmu_init(void)
{
int r = 0;
if (ux500_is_svp() || !cpu_is_u5500())
return -ENODEV;
writel(ALL_MBOX_BITS, PRCM_ARM_IT1_CLEAR);
r = request_threaded_irq(IRQ_DB5500_PRCMU1, prcmu_irq_handler,
prcmu_irq_thread_fn, 0, "prcmu", NULL);
if (r < 0) {
pr_err("prcmu: Failed to allocate IRQ_DB5500_PRCMU1.\n");
return -EBUSY;
}
return 0;
}
