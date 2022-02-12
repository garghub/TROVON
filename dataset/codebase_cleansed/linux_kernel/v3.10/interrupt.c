static inline void wil_icr_clear(u32 x, void __iomem *addr)
{
}
static inline void wil_icr_clear(u32 x, void __iomem *addr)
{
iowrite32(x, addr);
}
static inline u32 wil_ioread32_and_clear(void __iomem *addr)
{
u32 x = ioread32(addr);
wil_icr_clear(x, addr);
return x;
}
static void wil6210_mask_irq_tx(struct wil6210_priv *wil)
{
iowrite32(WIL6210_IRQ_DISABLE, wil->csr +
HOSTADDR(RGF_DMA_EP_TX_ICR) +
offsetof(struct RGF_ICR, IMS));
}
static void wil6210_mask_irq_rx(struct wil6210_priv *wil)
{
iowrite32(WIL6210_IRQ_DISABLE, wil->csr +
HOSTADDR(RGF_DMA_EP_RX_ICR) +
offsetof(struct RGF_ICR, IMS));
}
static void wil6210_mask_irq_misc(struct wil6210_priv *wil)
{
iowrite32(WIL6210_IRQ_DISABLE, wil->csr +
HOSTADDR(RGF_DMA_EP_MISC_ICR) +
offsetof(struct RGF_ICR, IMS));
}
static void wil6210_mask_irq_pseudo(struct wil6210_priv *wil)
{
wil_dbg_irq(wil, "%s()\n", __func__);
iowrite32(WIL6210_IRQ_DISABLE, wil->csr +
HOSTADDR(RGF_DMA_PSEUDO_CAUSE_MASK_SW));
clear_bit(wil_status_irqen, &wil->status);
}
static void wil6210_unmask_irq_tx(struct wil6210_priv *wil)
{
iowrite32(WIL6210_IMC_TX, wil->csr +
HOSTADDR(RGF_DMA_EP_TX_ICR) +
offsetof(struct RGF_ICR, IMC));
}
static void wil6210_unmask_irq_rx(struct wil6210_priv *wil)
{
iowrite32(WIL6210_IMC_RX, wil->csr +
HOSTADDR(RGF_DMA_EP_RX_ICR) +
offsetof(struct RGF_ICR, IMC));
}
static void wil6210_unmask_irq_misc(struct wil6210_priv *wil)
{
iowrite32(WIL6210_IMC_MISC, wil->csr +
HOSTADDR(RGF_DMA_EP_MISC_ICR) +
offsetof(struct RGF_ICR, IMC));
}
static void wil6210_unmask_irq_pseudo(struct wil6210_priv *wil)
{
wil_dbg_irq(wil, "%s()\n", __func__);
set_bit(wil_status_irqen, &wil->status);
iowrite32(WIL6210_IRQ_PSEUDO_MASK, wil->csr +
HOSTADDR(RGF_DMA_PSEUDO_CAUSE_MASK_SW));
}
void wil6210_disable_irq(struct wil6210_priv *wil)
{
wil_dbg_irq(wil, "%s()\n", __func__);
wil6210_mask_irq_tx(wil);
wil6210_mask_irq_rx(wil);
wil6210_mask_irq_misc(wil);
wil6210_mask_irq_pseudo(wil);
}
void wil6210_enable_irq(struct wil6210_priv *wil)
{
wil_dbg_irq(wil, "%s()\n", __func__);
iowrite32(WIL_ICR_ICC_VALUE, wil->csr + HOSTADDR(RGF_DMA_EP_RX_ICR) +
offsetof(struct RGF_ICR, ICC));
iowrite32(WIL_ICR_ICC_VALUE, wil->csr + HOSTADDR(RGF_DMA_EP_TX_ICR) +
offsetof(struct RGF_ICR, ICC));
iowrite32(WIL_ICR_ICC_VALUE, wil->csr + HOSTADDR(RGF_DMA_EP_MISC_ICR) +
offsetof(struct RGF_ICR, ICC));
wil6210_unmask_irq_pseudo(wil);
wil6210_unmask_irq_tx(wil);
wil6210_unmask_irq_rx(wil);
wil6210_unmask_irq_misc(wil);
}
static irqreturn_t wil6210_irq_rx(int irq, void *cookie)
{
struct wil6210_priv *wil = cookie;
u32 isr = wil_ioread32_and_clear(wil->csr +
HOSTADDR(RGF_DMA_EP_RX_ICR) +
offsetof(struct RGF_ICR, ICR));
wil_dbg_irq(wil, "ISR RX 0x%08x\n", isr);
if (!isr) {
wil_err(wil, "spurious IRQ: RX\n");
return IRQ_NONE;
}
wil6210_mask_irq_rx(wil);
if (isr & BIT_DMA_EP_RX_ICR_RX_DONE) {
wil_dbg_irq(wil, "RX done\n");
isr &= ~BIT_DMA_EP_RX_ICR_RX_DONE;
wil_rx_handle(wil);
}
if (isr)
wil_err(wil, "un-handled RX ISR bits 0x%08x\n", isr);
wil6210_unmask_irq_rx(wil);
return IRQ_HANDLED;
}
static irqreturn_t wil6210_irq_tx(int irq, void *cookie)
{
struct wil6210_priv *wil = cookie;
u32 isr = wil_ioread32_and_clear(wil->csr +
HOSTADDR(RGF_DMA_EP_TX_ICR) +
offsetof(struct RGF_ICR, ICR));
wil_dbg_irq(wil, "ISR TX 0x%08x\n", isr);
if (!isr) {
wil_err(wil, "spurious IRQ: TX\n");
return IRQ_NONE;
}
wil6210_mask_irq_tx(wil);
if (isr & BIT_DMA_EP_TX_ICR_TX_DONE) {
uint i;
wil_dbg_irq(wil, "TX done\n");
isr &= ~BIT_DMA_EP_TX_ICR_TX_DONE;
for (i = 0; i < 24; i++) {
u32 mask = BIT_DMA_EP_TX_ICR_TX_DONE_N(i);
if (isr & mask) {
isr &= ~mask;
wil_dbg_irq(wil, "TX done(%i)\n", i);
wil_tx_complete(wil, i);
}
}
}
if (isr)
wil_err(wil, "un-handled TX ISR bits 0x%08x\n", isr);
wil6210_unmask_irq_tx(wil);
return IRQ_HANDLED;
}
static void wil_notify_fw_error(struct wil6210_priv *wil)
{
struct device *dev = &wil_to_ndev(wil)->dev;
char *envp[3] = {
[0] = "SOURCE=wil6210",
[1] = "EVENT=FW_ERROR",
[2] = NULL,
};
kobject_uevent_env(&dev->kobj, KOBJ_CHANGE, envp);
}
static void wil_cache_mbox_regs(struct wil6210_priv *wil)
{
wil_memcpy_fromio_32(&wil->mbox_ctl, wil->csr + HOST_MBOX,
sizeof(struct wil6210_mbox_ctl));
wil_mbox_ring_le2cpus(&wil->mbox_ctl.rx);
wil_mbox_ring_le2cpus(&wil->mbox_ctl.tx);
}
static irqreturn_t wil6210_irq_misc(int irq, void *cookie)
{
struct wil6210_priv *wil = cookie;
u32 isr = wil_ioread32_and_clear(wil->csr +
HOSTADDR(RGF_DMA_EP_MISC_ICR) +
offsetof(struct RGF_ICR, ICR));
wil_dbg_irq(wil, "ISR MISC 0x%08x\n", isr);
if (!isr) {
wil_err(wil, "spurious IRQ: MISC\n");
return IRQ_NONE;
}
wil6210_mask_irq_misc(wil);
if (isr & ISR_MISC_FW_ERROR) {
wil_err(wil, "Firmware error detected\n");
clear_bit(wil_status_fwready, &wil->status);
}
if (isr & ISR_MISC_FW_READY) {
wil_dbg_irq(wil, "IRQ: FW ready\n");
wil_cache_mbox_regs(wil);
set_bit(wil_status_reset_done, &wil->status);
isr &= ~ISR_MISC_FW_READY;
}
wil->isr_misc = isr;
if (isr) {
return IRQ_WAKE_THREAD;
} else {
wil6210_unmask_irq_misc(wil);
return IRQ_HANDLED;
}
}
static irqreturn_t wil6210_irq_misc_thread(int irq, void *cookie)
{
struct wil6210_priv *wil = cookie;
u32 isr = wil->isr_misc;
wil_dbg_irq(wil, "Thread ISR MISC 0x%08x\n", isr);
if (isr & ISR_MISC_FW_ERROR) {
wil_notify_fw_error(wil);
isr &= ~ISR_MISC_FW_ERROR;
}
if (isr & ISR_MISC_MBOX_EVT) {
wil_dbg_irq(wil, "MBOX event\n");
wmi_recv_cmd(wil);
isr &= ~ISR_MISC_MBOX_EVT;
}
if (isr)
wil_err(wil, "un-handled MISC ISR bits 0x%08x\n", isr);
wil->isr_misc = 0;
wil6210_unmask_irq_misc(wil);
return IRQ_HANDLED;
}
static irqreturn_t wil6210_thread_irq(int irq, void *cookie)
{
struct wil6210_priv *wil = cookie;
wil_dbg_irq(wil, "Thread IRQ\n");
if (wil->isr_misc)
wil6210_irq_misc_thread(irq, cookie);
wil6210_unmask_irq_pseudo(wil);
return IRQ_HANDLED;
}
static int wil6210_debug_irq_mask(struct wil6210_priv *wil, u32 pseudo_cause)
{
if (!test_bit(wil_status_irqen, &wil->status)) {
u32 icm_rx = wil_ioread32_and_clear(wil->csr +
HOSTADDR(RGF_DMA_EP_RX_ICR) +
offsetof(struct RGF_ICR, ICM));
u32 icr_rx = wil_ioread32_and_clear(wil->csr +
HOSTADDR(RGF_DMA_EP_RX_ICR) +
offsetof(struct RGF_ICR, ICR));
u32 imv_rx = ioread32(wil->csr +
HOSTADDR(RGF_DMA_EP_RX_ICR) +
offsetof(struct RGF_ICR, IMV));
u32 icm_tx = wil_ioread32_and_clear(wil->csr +
HOSTADDR(RGF_DMA_EP_TX_ICR) +
offsetof(struct RGF_ICR, ICM));
u32 icr_tx = wil_ioread32_and_clear(wil->csr +
HOSTADDR(RGF_DMA_EP_TX_ICR) +
offsetof(struct RGF_ICR, ICR));
u32 imv_tx = ioread32(wil->csr +
HOSTADDR(RGF_DMA_EP_TX_ICR) +
offsetof(struct RGF_ICR, IMV));
u32 icm_misc = wil_ioread32_and_clear(wil->csr +
HOSTADDR(RGF_DMA_EP_MISC_ICR) +
offsetof(struct RGF_ICR, ICM));
u32 icr_misc = wil_ioread32_and_clear(wil->csr +
HOSTADDR(RGF_DMA_EP_MISC_ICR) +
offsetof(struct RGF_ICR, ICR));
u32 imv_misc = ioread32(wil->csr +
HOSTADDR(RGF_DMA_EP_MISC_ICR) +
offsetof(struct RGF_ICR, IMV));
wil_err(wil, "IRQ when it should be masked: pseudo 0x%08x\n"
"Rx icm:icr:imv 0x%08x 0x%08x 0x%08x\n"
"Tx icm:icr:imv 0x%08x 0x%08x 0x%08x\n"
"Misc icm:icr:imv 0x%08x 0x%08x 0x%08x\n",
pseudo_cause,
icm_rx, icr_rx, imv_rx,
icm_tx, icr_tx, imv_tx,
icm_misc, icr_misc, imv_misc);
return -EINVAL;
}
return 0;
}
static irqreturn_t wil6210_hardirq(int irq, void *cookie)
{
irqreturn_t rc = IRQ_HANDLED;
struct wil6210_priv *wil = cookie;
u32 pseudo_cause = ioread32(wil->csr + HOSTADDR(RGF_DMA_PSEUDO_CAUSE));
if ((pseudo_cause == 0) || ((pseudo_cause & 0xff) == 0xff))
return IRQ_NONE;
if (wil6210_debug_irq_mask(wil, pseudo_cause))
return IRQ_NONE;
wil_dbg_irq(wil, "Pseudo IRQ 0x%08x\n", pseudo_cause);
wil6210_mask_irq_pseudo(wil);
if ((pseudo_cause & BIT_DMA_PSEUDO_CAUSE_RX) &&
(wil6210_irq_rx(irq, cookie) == IRQ_WAKE_THREAD))
rc = IRQ_WAKE_THREAD;
if ((pseudo_cause & BIT_DMA_PSEUDO_CAUSE_TX) &&
(wil6210_irq_tx(irq, cookie) == IRQ_WAKE_THREAD))
rc = IRQ_WAKE_THREAD;
if ((pseudo_cause & BIT_DMA_PSEUDO_CAUSE_MISC) &&
(wil6210_irq_misc(irq, cookie) == IRQ_WAKE_THREAD))
rc = IRQ_WAKE_THREAD;
if (rc != IRQ_WAKE_THREAD)
wil6210_unmask_irq_pseudo(wil);
return rc;
}
static int wil6210_request_3msi(struct wil6210_priv *wil, int irq)
{
int rc;
rc = request_irq(irq, wil6210_irq_tx, IRQF_SHARED,
WIL_NAME"_tx", wil);
if (rc)
return rc;
rc = request_irq(irq + 1, wil6210_irq_rx, IRQF_SHARED,
WIL_NAME"_rx", wil);
if (rc)
goto free0;
rc = request_threaded_irq(irq + 2, wil6210_irq_misc,
wil6210_irq_misc_thread,
IRQF_SHARED, WIL_NAME"_misc", wil);
if (rc)
goto free1;
return 0;
free1:
free_irq(irq + 1, wil);
free0:
free_irq(irq, wil);
return rc;
}
int wil6210_init_irq(struct wil6210_priv *wil, int irq)
{
int rc;
if (wil->n_msi == 3)
rc = wil6210_request_3msi(wil, irq);
else
rc = request_threaded_irq(irq, wil6210_hardirq,
wil6210_thread_irq,
wil->n_msi ? 0 : IRQF_SHARED,
WIL_NAME, wil);
if (rc)
return rc;
wil6210_enable_irq(wil);
return 0;
}
void wil6210_fini_irq(struct wil6210_priv *wil, int irq)
{
wil6210_disable_irq(wil);
free_irq(irq, wil);
if (wil->n_msi == 3) {
free_irq(irq + 1, wil);
free_irq(irq + 2, wil);
}
}
