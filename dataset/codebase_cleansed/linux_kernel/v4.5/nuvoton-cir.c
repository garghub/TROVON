static inline bool is_w83667hg(struct nvt_dev *nvt)
{
return nvt->chip_ver == NVT_W83667HG;
}
static inline void nvt_cr_write(struct nvt_dev *nvt, u8 val, u8 reg)
{
outb(reg, nvt->cr_efir);
outb(val, nvt->cr_efdr);
}
static inline u8 nvt_cr_read(struct nvt_dev *nvt, u8 reg)
{
outb(reg, nvt->cr_efir);
return inb(nvt->cr_efdr);
}
static inline void nvt_set_reg_bit(struct nvt_dev *nvt, u8 val, u8 reg)
{
u8 tmp = nvt_cr_read(nvt, reg) | val;
nvt_cr_write(nvt, tmp, reg);
}
static inline void nvt_clear_reg_bit(struct nvt_dev *nvt, u8 val, u8 reg)
{
u8 tmp = nvt_cr_read(nvt, reg) & ~val;
nvt_cr_write(nvt, tmp, reg);
}
static inline void nvt_efm_enable(struct nvt_dev *nvt)
{
outb(EFER_EFM_ENABLE, nvt->cr_efir);
outb(EFER_EFM_ENABLE, nvt->cr_efir);
}
static inline void nvt_efm_disable(struct nvt_dev *nvt)
{
outb(EFER_EFM_DISABLE, nvt->cr_efir);
}
static inline void nvt_select_logical_dev(struct nvt_dev *nvt, u8 ldev)
{
outb(CR_LOGICAL_DEV_SEL, nvt->cr_efir);
outb(ldev, nvt->cr_efdr);
}
static inline void nvt_cir_reg_write(struct nvt_dev *nvt, u8 val, u8 offset)
{
outb(val, nvt->cir_addr + offset);
}
static u8 nvt_cir_reg_read(struct nvt_dev *nvt, u8 offset)
{
u8 val;
val = inb(nvt->cir_addr + offset);
return val;
}
static inline void nvt_cir_wake_reg_write(struct nvt_dev *nvt,
u8 val, u8 offset)
{
outb(val, nvt->cir_wake_addr + offset);
}
static u8 nvt_cir_wake_reg_read(struct nvt_dev *nvt, u8 offset)
{
u8 val;
val = inb(nvt->cir_wake_addr + offset);
return val;
}
static void cir_dump_regs(struct nvt_dev *nvt)
{
nvt_efm_enable(nvt);
nvt_select_logical_dev(nvt, LOGICAL_DEV_CIR);
pr_info("%s: Dump CIR logical device registers:\n", NVT_DRIVER_NAME);
pr_info(" * CR CIR ACTIVE : 0x%x\n",
nvt_cr_read(nvt, CR_LOGICAL_DEV_EN));
pr_info(" * CR CIR BASE ADDR: 0x%x\n",
(nvt_cr_read(nvt, CR_CIR_BASE_ADDR_HI) << 8) |
nvt_cr_read(nvt, CR_CIR_BASE_ADDR_LO));
pr_info(" * CR CIR IRQ NUM: 0x%x\n",
nvt_cr_read(nvt, CR_CIR_IRQ_RSRC));
nvt_efm_disable(nvt);
pr_info("%s: Dump CIR registers:\n", NVT_DRIVER_NAME);
pr_info(" * IRCON: 0x%x\n", nvt_cir_reg_read(nvt, CIR_IRCON));
pr_info(" * IRSTS: 0x%x\n", nvt_cir_reg_read(nvt, CIR_IRSTS));
pr_info(" * IREN: 0x%x\n", nvt_cir_reg_read(nvt, CIR_IREN));
pr_info(" * RXFCONT: 0x%x\n", nvt_cir_reg_read(nvt, CIR_RXFCONT));
pr_info(" * CP: 0x%x\n", nvt_cir_reg_read(nvt, CIR_CP));
pr_info(" * CC: 0x%x\n", nvt_cir_reg_read(nvt, CIR_CC));
pr_info(" * SLCH: 0x%x\n", nvt_cir_reg_read(nvt, CIR_SLCH));
pr_info(" * SLCL: 0x%x\n", nvt_cir_reg_read(nvt, CIR_SLCL));
pr_info(" * FIFOCON: 0x%x\n", nvt_cir_reg_read(nvt, CIR_FIFOCON));
pr_info(" * IRFIFOSTS: 0x%x\n", nvt_cir_reg_read(nvt, CIR_IRFIFOSTS));
pr_info(" * SRXFIFO: 0x%x\n", nvt_cir_reg_read(nvt, CIR_SRXFIFO));
pr_info(" * TXFCONT: 0x%x\n", nvt_cir_reg_read(nvt, CIR_TXFCONT));
pr_info(" * STXFIFO: 0x%x\n", nvt_cir_reg_read(nvt, CIR_STXFIFO));
pr_info(" * FCCH: 0x%x\n", nvt_cir_reg_read(nvt, CIR_FCCH));
pr_info(" * FCCL: 0x%x\n", nvt_cir_reg_read(nvt, CIR_FCCL));
pr_info(" * IRFSM: 0x%x\n", nvt_cir_reg_read(nvt, CIR_IRFSM));
}
static void cir_wake_dump_regs(struct nvt_dev *nvt)
{
u8 i, fifo_len;
nvt_efm_enable(nvt);
nvt_select_logical_dev(nvt, LOGICAL_DEV_CIR_WAKE);
pr_info("%s: Dump CIR WAKE logical device registers:\n",
NVT_DRIVER_NAME);
pr_info(" * CR CIR WAKE ACTIVE : 0x%x\n",
nvt_cr_read(nvt, CR_LOGICAL_DEV_EN));
pr_info(" * CR CIR WAKE BASE ADDR: 0x%x\n",
(nvt_cr_read(nvt, CR_CIR_BASE_ADDR_HI) << 8) |
nvt_cr_read(nvt, CR_CIR_BASE_ADDR_LO));
pr_info(" * CR CIR WAKE IRQ NUM: 0x%x\n",
nvt_cr_read(nvt, CR_CIR_IRQ_RSRC));
nvt_efm_disable(nvt);
pr_info("%s: Dump CIR WAKE registers\n", NVT_DRIVER_NAME);
pr_info(" * IRCON: 0x%x\n",
nvt_cir_wake_reg_read(nvt, CIR_WAKE_IRCON));
pr_info(" * IRSTS: 0x%x\n",
nvt_cir_wake_reg_read(nvt, CIR_WAKE_IRSTS));
pr_info(" * IREN: 0x%x\n",
nvt_cir_wake_reg_read(nvt, CIR_WAKE_IREN));
pr_info(" * FIFO CMP DEEP: 0x%x\n",
nvt_cir_wake_reg_read(nvt, CIR_WAKE_FIFO_CMP_DEEP));
pr_info(" * FIFO CMP TOL: 0x%x\n",
nvt_cir_wake_reg_read(nvt, CIR_WAKE_FIFO_CMP_TOL));
pr_info(" * FIFO COUNT: 0x%x\n",
nvt_cir_wake_reg_read(nvt, CIR_WAKE_FIFO_COUNT));
pr_info(" * SLCH: 0x%x\n",
nvt_cir_wake_reg_read(nvt, CIR_WAKE_SLCH));
pr_info(" * SLCL: 0x%x\n",
nvt_cir_wake_reg_read(nvt, CIR_WAKE_SLCL));
pr_info(" * FIFOCON: 0x%x\n",
nvt_cir_wake_reg_read(nvt, CIR_WAKE_FIFOCON));
pr_info(" * SRXFSTS: 0x%x\n",
nvt_cir_wake_reg_read(nvt, CIR_WAKE_SRXFSTS));
pr_info(" * SAMPLE RX FIFO: 0x%x\n",
nvt_cir_wake_reg_read(nvt, CIR_WAKE_SAMPLE_RX_FIFO));
pr_info(" * WR FIFO DATA: 0x%x\n",
nvt_cir_wake_reg_read(nvt, CIR_WAKE_WR_FIFO_DATA));
pr_info(" * RD FIFO ONLY: 0x%x\n",
nvt_cir_wake_reg_read(nvt, CIR_WAKE_RD_FIFO_ONLY));
pr_info(" * RD FIFO ONLY IDX: 0x%x\n",
nvt_cir_wake_reg_read(nvt, CIR_WAKE_RD_FIFO_ONLY_IDX));
pr_info(" * FIFO IGNORE: 0x%x\n",
nvt_cir_wake_reg_read(nvt, CIR_WAKE_FIFO_IGNORE));
pr_info(" * IRFSM: 0x%x\n",
nvt_cir_wake_reg_read(nvt, CIR_WAKE_IRFSM));
fifo_len = nvt_cir_wake_reg_read(nvt, CIR_WAKE_FIFO_COUNT);
pr_info("%s: Dump CIR WAKE FIFO (len %d)\n", NVT_DRIVER_NAME, fifo_len);
pr_info("* Contents =");
for (i = 0; i < fifo_len; i++)
pr_cont(" %02x",
nvt_cir_wake_reg_read(nvt, CIR_WAKE_RD_FIFO_ONLY));
pr_cont("\n");
}
static inline const char *nvt_find_chip(struct nvt_dev *nvt, int id)
{
int i;
for (i = 0; i < ARRAY_SIZE(nvt_chips); i++)
if ((id & SIO_ID_MASK) == nvt_chips[i].chip_ver) {
nvt->chip_ver = nvt_chips[i].chip_ver;
return nvt_chips[i].name;
}
return NULL;
}
static void nvt_hw_detect(struct nvt_dev *nvt)
{
const char *chip_name;
int chip_id;
nvt_efm_enable(nvt);
nvt->chip_major = nvt_cr_read(nvt, CR_CHIP_ID_HI);
if (nvt->chip_major == 0xff) {
nvt->cr_efir = CR_EFIR2;
nvt->cr_efdr = CR_EFDR2;
nvt_efm_enable(nvt);
nvt->chip_major = nvt_cr_read(nvt, CR_CHIP_ID_HI);
}
nvt->chip_minor = nvt_cr_read(nvt, CR_CHIP_ID_LO);
chip_id = nvt->chip_major << 8 | nvt->chip_minor;
chip_name = nvt_find_chip(nvt, chip_id);
if (!chip_name)
dev_warn(&nvt->pdev->dev,
"unknown chip, id: 0x%02x 0x%02x, it may not work...",
nvt->chip_major, nvt->chip_minor);
else
dev_info(&nvt->pdev->dev,
"found %s or compatible: chip id: 0x%02x 0x%02x",
chip_name, nvt->chip_major, nvt->chip_minor);
nvt_efm_disable(nvt);
}
static void nvt_cir_ldev_init(struct nvt_dev *nvt)
{
u8 val, psreg, psmask, psval;
if (is_w83667hg(nvt)) {
psreg = CR_MULTIFUNC_PIN_SEL;
psmask = MULTIFUNC_PIN_SEL_MASK;
psval = MULTIFUNC_ENABLE_CIR | MULTIFUNC_ENABLE_CIRWB;
} else {
psreg = CR_OUTPUT_PIN_SEL;
psmask = OUTPUT_PIN_SEL_MASK;
psval = OUTPUT_ENABLE_CIR | OUTPUT_ENABLE_CIRWB;
}
val = nvt_cr_read(nvt, psreg);
val &= psmask;
val |= psval;
nvt_cr_write(nvt, val, psreg);
nvt_select_logical_dev(nvt, LOGICAL_DEV_CIR);
nvt_cr_write(nvt, LOGICAL_DEV_ENABLE, CR_LOGICAL_DEV_EN);
nvt_cr_write(nvt, nvt->cir_addr >> 8, CR_CIR_BASE_ADDR_HI);
nvt_cr_write(nvt, nvt->cir_addr & 0xff, CR_CIR_BASE_ADDR_LO);
nvt_cr_write(nvt, nvt->cir_irq, CR_CIR_IRQ_RSRC);
nvt_dbg("CIR initialized, base io port address: 0x%lx, irq: %d",
nvt->cir_addr, nvt->cir_irq);
}
static void nvt_cir_wake_ldev_init(struct nvt_dev *nvt)
{
nvt_select_logical_dev(nvt, LOGICAL_DEV_ACPI);
nvt_cr_write(nvt, LOGICAL_DEV_ENABLE, CR_LOGICAL_DEV_EN);
nvt_set_reg_bit(nvt, CIR_WAKE_ENABLE_BIT, CR_ACPI_CIR_WAKE);
nvt_set_reg_bit(nvt, PME_INTR_CIR_PASS_BIT, CR_ACPI_IRQ_EVENTS2);
nvt_select_logical_dev(nvt, LOGICAL_DEV_CIR_WAKE);
nvt_cr_write(nvt, LOGICAL_DEV_ENABLE, CR_LOGICAL_DEV_EN);
nvt_cr_write(nvt, nvt->cir_wake_addr >> 8, CR_CIR_BASE_ADDR_HI);
nvt_cr_write(nvt, nvt->cir_wake_addr & 0xff, CR_CIR_BASE_ADDR_LO);
nvt_cr_write(nvt, nvt->cir_wake_irq, CR_CIR_IRQ_RSRC);
nvt_dbg("CIR Wake initialized, base io port address: 0x%lx, irq: %d",
nvt->cir_wake_addr, nvt->cir_wake_irq);
}
static void nvt_clear_cir_fifo(struct nvt_dev *nvt)
{
u8 val;
val = nvt_cir_reg_read(nvt, CIR_FIFOCON);
nvt_cir_reg_write(nvt, val | CIR_FIFOCON_RXFIFOCLR, CIR_FIFOCON);
}
static void nvt_clear_cir_wake_fifo(struct nvt_dev *nvt)
{
u8 val;
val = nvt_cir_wake_reg_read(nvt, CIR_WAKE_FIFOCON);
nvt_cir_wake_reg_write(nvt, val | CIR_WAKE_FIFOCON_RXFIFOCLR,
CIR_WAKE_FIFOCON);
}
static void nvt_clear_tx_fifo(struct nvt_dev *nvt)
{
u8 val;
val = nvt_cir_reg_read(nvt, CIR_FIFOCON);
nvt_cir_reg_write(nvt, val | CIR_FIFOCON_TXFIFOCLR, CIR_FIFOCON);
}
static void nvt_set_cir_iren(struct nvt_dev *nvt)
{
u8 iren;
iren = CIR_IREN_RTR | CIR_IREN_PE;
nvt_cir_reg_write(nvt, iren, CIR_IREN);
}
static void nvt_cir_regs_init(struct nvt_dev *nvt)
{
nvt_cir_reg_write(nvt, CIR_RX_LIMIT_COUNT >> 8, CIR_SLCH);
nvt_cir_reg_write(nvt, CIR_RX_LIMIT_COUNT & 0xff, CIR_SLCL);
nvt_cir_reg_write(nvt, CIR_FIFOCON_TX_TRIGGER_LEV |
CIR_FIFOCON_RX_TRIGGER_LEV, CIR_FIFOCON);
nvt_cir_reg_write(nvt,
CIR_IRCON_TXEN | CIR_IRCON_RXEN |
CIR_IRCON_RXINV | CIR_IRCON_SAMPLE_PERIOD_SEL,
CIR_IRCON);
nvt_clear_cir_fifo(nvt);
nvt_clear_tx_fifo(nvt);
nvt_cir_reg_write(nvt, 0xff, CIR_IRSTS);
nvt_set_cir_iren(nvt);
}
static void nvt_cir_wake_regs_init(struct nvt_dev *nvt)
{
nvt_cir_wake_reg_write(nvt, CIR_WAKE_FIFO_CMP_BYTES,
CIR_WAKE_FIFO_CMP_DEEP);
nvt_cir_wake_reg_write(nvt, CIR_WAKE_CMP_TOLERANCE,
CIR_WAKE_FIFO_CMP_TOL);
nvt_cir_wake_reg_write(nvt, CIR_RX_LIMIT_COUNT >> 8, CIR_WAKE_SLCH);
nvt_cir_wake_reg_write(nvt, CIR_RX_LIMIT_COUNT & 0xff, CIR_WAKE_SLCL);
nvt_cir_wake_reg_write(nvt, CIR_WAKE_FIFOCON_RX_TRIGGER_LEV,
CIR_WAKE_FIFOCON);
nvt_cir_wake_reg_write(nvt, CIR_WAKE_IRCON_MODE0 | CIR_WAKE_IRCON_RXEN |
CIR_WAKE_IRCON_R | CIR_WAKE_IRCON_RXINV |
CIR_WAKE_IRCON_SAMPLE_PERIOD_SEL,
CIR_WAKE_IRCON);
nvt_clear_cir_wake_fifo(nvt);
nvt_cir_wake_reg_write(nvt, 0xff, CIR_WAKE_IRSTS);
}
static void nvt_enable_wake(struct nvt_dev *nvt)
{
nvt_efm_enable(nvt);
nvt_select_logical_dev(nvt, LOGICAL_DEV_ACPI);
nvt_set_reg_bit(nvt, CIR_WAKE_ENABLE_BIT, CR_ACPI_CIR_WAKE);
nvt_set_reg_bit(nvt, PME_INTR_CIR_PASS_BIT, CR_ACPI_IRQ_EVENTS2);
nvt_select_logical_dev(nvt, LOGICAL_DEV_CIR_WAKE);
nvt_cr_write(nvt, LOGICAL_DEV_ENABLE, CR_LOGICAL_DEV_EN);
nvt_efm_disable(nvt);
nvt_cir_wake_reg_write(nvt, CIR_WAKE_IRCON_MODE0 | CIR_WAKE_IRCON_RXEN |
CIR_WAKE_IRCON_R | CIR_WAKE_IRCON_RXINV |
CIR_WAKE_IRCON_SAMPLE_PERIOD_SEL,
CIR_WAKE_IRCON);
nvt_cir_wake_reg_write(nvt, 0xff, CIR_WAKE_IRSTS);
nvt_cir_wake_reg_write(nvt, 0, CIR_WAKE_IREN);
}
static int nvt_set_tx_carrier(struct rc_dev *dev, u32 carrier)
{
struct nvt_dev *nvt = dev->priv;
u16 val;
if (carrier == 0)
return -EINVAL;
nvt_cir_reg_write(nvt, 1, CIR_CP);
val = 3000000 / (carrier) - 1;
nvt_cir_reg_write(nvt, val & 0xff, CIR_CC);
nvt_dbg("cp: 0x%x cc: 0x%x\n",
nvt_cir_reg_read(nvt, CIR_CP), nvt_cir_reg_read(nvt, CIR_CC));
return 0;
}
static int nvt_tx_ir(struct rc_dev *dev, unsigned *txbuf, unsigned n)
{
struct nvt_dev *nvt = dev->priv;
unsigned long flags;
unsigned int i;
u8 iren;
int ret;
spin_lock_irqsave(&nvt->tx.lock, flags);
ret = min((unsigned)(TX_BUF_LEN / sizeof(unsigned)), n);
nvt->tx.buf_count = (ret * sizeof(unsigned));
memcpy(nvt->tx.buf, txbuf, nvt->tx.buf_count);
nvt->tx.cur_buf_num = 0;
iren = nvt_cir_reg_read(nvt, CIR_IREN);
nvt_cir_reg_write(nvt, CIR_IREN_TFU | CIR_IREN_TTR, CIR_IREN);
nvt->tx.tx_state = ST_TX_REPLY;
nvt_cir_reg_write(nvt, CIR_FIFOCON_TX_TRIGGER_LEV_8 |
CIR_FIFOCON_RXFIFOCLR, CIR_FIFOCON);
for (i = 0; i < 9; i++)
nvt_cir_reg_write(nvt, 0x01, CIR_STXFIFO);
spin_unlock_irqrestore(&nvt->tx.lock, flags);
wait_event(nvt->tx.queue, nvt->tx.tx_state == ST_TX_REQUEST);
spin_lock_irqsave(&nvt->tx.lock, flags);
nvt->tx.tx_state = ST_TX_NONE;
spin_unlock_irqrestore(&nvt->tx.lock, flags);
nvt_cir_reg_write(nvt, iren, CIR_IREN);
return ret;
}
static void nvt_dump_rx_buf(struct nvt_dev *nvt)
{
int i;
printk(KERN_DEBUG "%s (len %d): ", __func__, nvt->pkts);
for (i = 0; (i < nvt->pkts) && (i < RX_BUF_LEN); i++)
printk(KERN_CONT "0x%02x ", nvt->buf[i]);
printk(KERN_CONT "\n");
}
static void nvt_process_rx_ir_data(struct nvt_dev *nvt)
{
DEFINE_IR_RAW_EVENT(rawir);
u8 sample;
int i;
nvt_dbg_verbose("%s firing", __func__);
if (debug)
nvt_dump_rx_buf(nvt);
nvt_dbg_verbose("Processing buffer of len %d", nvt->pkts);
init_ir_raw_event(&rawir);
for (i = 0; i < nvt->pkts; i++) {
sample = nvt->buf[i];
rawir.pulse = ((sample & BUF_PULSE_BIT) != 0);
rawir.duration = US_TO_NS((sample & BUF_LEN_MASK)
* SAMPLE_PERIOD);
nvt_dbg("Storing %s with duration %d",
rawir.pulse ? "pulse" : "space", rawir.duration);
ir_raw_event_store_with_filter(nvt->rdev, &rawir);
if ((sample == BUF_PULSE_BIT) && (i + 1 < nvt->pkts)) {
nvt_dbg("Calling ir_raw_event_handle (signal end)\n");
ir_raw_event_handle(nvt->rdev);
}
}
nvt->pkts = 0;
nvt_dbg("Calling ir_raw_event_handle (buffer empty)\n");
ir_raw_event_handle(nvt->rdev);
nvt_dbg_verbose("%s done", __func__);
}
static void nvt_handle_rx_fifo_overrun(struct nvt_dev *nvt)
{
dev_warn(&nvt->pdev->dev, "RX FIFO overrun detected, flushing data!");
nvt->pkts = 0;
nvt_clear_cir_fifo(nvt);
ir_raw_event_reset(nvt->rdev);
}
static void nvt_get_rx_ir_data(struct nvt_dev *nvt)
{
unsigned long flags;
u8 fifocount, val;
unsigned int b_idx;
bool overrun = false;
int i;
fifocount = nvt_cir_reg_read(nvt, CIR_RXFCONT);
if (fifocount == 0xff)
return;
else if (fifocount > RX_BUF_LEN) {
overrun = true;
fifocount = RX_BUF_LEN;
}
nvt_dbg("attempting to fetch %u bytes from hw rx fifo", fifocount);
spin_lock_irqsave(&nvt->nvt_lock, flags);
b_idx = nvt->pkts;
if (b_idx + fifocount > RX_BUF_LEN) {
nvt_process_rx_ir_data(nvt);
b_idx = 0;
}
for (i = 0; i < fifocount; i++) {
val = nvt_cir_reg_read(nvt, CIR_SRXFIFO);
nvt->buf[b_idx + i] = val;
}
nvt->pkts += fifocount;
nvt_dbg("%s: pkts now %d", __func__, nvt->pkts);
nvt_process_rx_ir_data(nvt);
if (overrun)
nvt_handle_rx_fifo_overrun(nvt);
spin_unlock_irqrestore(&nvt->nvt_lock, flags);
}
static void nvt_cir_log_irqs(u8 status, u8 iren)
{
nvt_dbg("IRQ 0x%02x (IREN 0x%02x) :%s%s%s%s%s%s%s%s%s",
status, iren,
status & CIR_IRSTS_RDR ? " RDR" : "",
status & CIR_IRSTS_RTR ? " RTR" : "",
status & CIR_IRSTS_PE ? " PE" : "",
status & CIR_IRSTS_RFO ? " RFO" : "",
status & CIR_IRSTS_TE ? " TE" : "",
status & CIR_IRSTS_TTR ? " TTR" : "",
status & CIR_IRSTS_TFU ? " TFU" : "",
status & CIR_IRSTS_GH ? " GH" : "",
status & ~(CIR_IRSTS_RDR | CIR_IRSTS_RTR | CIR_IRSTS_PE |
CIR_IRSTS_RFO | CIR_IRSTS_TE | CIR_IRSTS_TTR |
CIR_IRSTS_TFU | CIR_IRSTS_GH) ? " ?" : "");
}
static bool nvt_cir_tx_inactive(struct nvt_dev *nvt)
{
unsigned long flags;
bool tx_inactive;
u8 tx_state;
spin_lock_irqsave(&nvt->tx.lock, flags);
tx_state = nvt->tx.tx_state;
spin_unlock_irqrestore(&nvt->tx.lock, flags);
tx_inactive = (tx_state == ST_TX_NONE);
return tx_inactive;
}
static irqreturn_t nvt_cir_isr(int irq, void *data)
{
struct nvt_dev *nvt = data;
u8 status, iren, cur_state;
unsigned long flags;
nvt_dbg_verbose("%s firing", __func__);
nvt_efm_enable(nvt);
nvt_select_logical_dev(nvt, LOGICAL_DEV_CIR);
nvt_efm_disable(nvt);
status = nvt_cir_reg_read(nvt, CIR_IRSTS);
if (!status) {
nvt_dbg_verbose("%s exiting, IRSTS 0x0", __func__);
nvt_cir_reg_write(nvt, 0xff, CIR_IRSTS);
return IRQ_NONE;
}
nvt_cir_reg_write(nvt, status, CIR_IRSTS);
nvt_cir_reg_write(nvt, 0, CIR_IRSTS);
iren = nvt_cir_reg_read(nvt, CIR_IREN);
if (!iren) {
nvt_dbg_verbose("%s exiting, CIR not enabled", __func__);
return IRQ_NONE;
}
nvt_cir_log_irqs(status, iren);
if (status & CIR_IRSTS_RTR) {
if (nvt_cir_tx_inactive(nvt))
nvt_get_rx_ir_data(nvt);
}
if (status & CIR_IRSTS_PE) {
if (nvt_cir_tx_inactive(nvt))
nvt_get_rx_ir_data(nvt);
spin_lock_irqsave(&nvt->nvt_lock, flags);
cur_state = nvt->study_state;
spin_unlock_irqrestore(&nvt->nvt_lock, flags);
if (cur_state == ST_STUDY_NONE)
nvt_clear_cir_fifo(nvt);
}
if (status & CIR_IRSTS_TE)
nvt_clear_tx_fifo(nvt);
if (status & CIR_IRSTS_TTR) {
unsigned int pos, count;
u8 tmp;
spin_lock_irqsave(&nvt->tx.lock, flags);
pos = nvt->tx.cur_buf_num;
count = nvt->tx.buf_count;
if (pos < count) {
nvt_cir_reg_write(nvt, nvt->tx.buf[pos], CIR_STXFIFO);
nvt->tx.cur_buf_num++;
} else {
tmp = nvt_cir_reg_read(nvt, CIR_IREN);
nvt_cir_reg_write(nvt, tmp & ~CIR_IREN_TTR, CIR_IREN);
}
spin_unlock_irqrestore(&nvt->tx.lock, flags);
}
if (status & CIR_IRSTS_TFU) {
spin_lock_irqsave(&nvt->tx.lock, flags);
if (nvt->tx.tx_state == ST_TX_REPLY) {
nvt->tx.tx_state = ST_TX_REQUEST;
wake_up(&nvt->tx.queue);
}
spin_unlock_irqrestore(&nvt->tx.lock, flags);
}
nvt_dbg_verbose("%s done", __func__);
return IRQ_HANDLED;
}
static irqreturn_t nvt_cir_wake_isr(int irq, void *data)
{
u8 status, iren, val;
struct nvt_dev *nvt = data;
unsigned long flags;
nvt_dbg_wake("%s firing", __func__);
status = nvt_cir_wake_reg_read(nvt, CIR_WAKE_IRSTS);
if (!status)
return IRQ_NONE;
if (status & CIR_WAKE_IRSTS_IR_PENDING)
nvt_clear_cir_wake_fifo(nvt);
nvt_cir_wake_reg_write(nvt, status, CIR_WAKE_IRSTS);
nvt_cir_wake_reg_write(nvt, 0, CIR_WAKE_IRSTS);
iren = nvt_cir_wake_reg_read(nvt, CIR_WAKE_IREN);
if (!iren) {
nvt_dbg_wake("%s exiting, wake not enabled", __func__);
return IRQ_HANDLED;
}
if ((status & CIR_WAKE_IRSTS_PE) &&
(nvt->wake_state == ST_WAKE_START)) {
while (nvt_cir_wake_reg_read(nvt, CIR_WAKE_RD_FIFO_ONLY_IDX)) {
val = nvt_cir_wake_reg_read(nvt, CIR_WAKE_RD_FIFO_ONLY);
nvt_dbg("setting wake up key: 0x%x", val);
}
nvt_cir_wake_reg_write(nvt, 0, CIR_WAKE_IREN);
spin_lock_irqsave(&nvt->nvt_lock, flags);
nvt->wake_state = ST_WAKE_FINISH;
spin_unlock_irqrestore(&nvt->nvt_lock, flags);
}
nvt_dbg_wake("%s done", __func__);
return IRQ_HANDLED;
}
static void nvt_enable_cir(struct nvt_dev *nvt)
{
nvt_cir_reg_write(nvt, CIR_IRCON_TXEN | CIR_IRCON_RXEN |
CIR_IRCON_RXINV | CIR_IRCON_SAMPLE_PERIOD_SEL,
CIR_IRCON);
nvt_efm_enable(nvt);
nvt_select_logical_dev(nvt, LOGICAL_DEV_CIR);
nvt_cr_write(nvt, LOGICAL_DEV_ENABLE, CR_LOGICAL_DEV_EN);
nvt_efm_disable(nvt);
nvt_cir_reg_write(nvt, 0xff, CIR_IRSTS);
nvt_set_cir_iren(nvt);
}
static void nvt_disable_cir(struct nvt_dev *nvt)
{
nvt_cir_reg_write(nvt, 0, CIR_IREN);
nvt_cir_reg_write(nvt, 0xff, CIR_IRSTS);
nvt_cir_reg_write(nvt, 0, CIR_IRCON);
nvt_clear_cir_fifo(nvt);
nvt_clear_tx_fifo(nvt);
nvt_efm_enable(nvt);
nvt_select_logical_dev(nvt, LOGICAL_DEV_CIR);
nvt_cr_write(nvt, LOGICAL_DEV_DISABLE, CR_LOGICAL_DEV_EN);
nvt_efm_disable(nvt);
}
static int nvt_open(struct rc_dev *dev)
{
struct nvt_dev *nvt = dev->priv;
unsigned long flags;
spin_lock_irqsave(&nvt->nvt_lock, flags);
nvt_enable_cir(nvt);
spin_unlock_irqrestore(&nvt->nvt_lock, flags);
return 0;
}
static void nvt_close(struct rc_dev *dev)
{
struct nvt_dev *nvt = dev->priv;
unsigned long flags;
spin_lock_irqsave(&nvt->nvt_lock, flags);
nvt_disable_cir(nvt);
spin_unlock_irqrestore(&nvt->nvt_lock, flags);
}
static int nvt_probe(struct pnp_dev *pdev, const struct pnp_device_id *dev_id)
{
struct nvt_dev *nvt;
struct rc_dev *rdev;
int ret = -ENOMEM;
nvt = devm_kzalloc(&pdev->dev, sizeof(struct nvt_dev), GFP_KERNEL);
if (!nvt)
return ret;
rdev = rc_allocate_device();
if (!rdev)
goto exit_free_dev_rdev;
ret = -ENODEV;
if (pnp_activate_dev(pdev) < 0) {
dev_err(&pdev->dev, "Could not activate PNP device!\n");
goto exit_free_dev_rdev;
}
if (!pnp_port_valid(pdev, 0) ||
pnp_port_len(pdev, 0) < CIR_IOREG_LENGTH) {
dev_err(&pdev->dev, "IR PNP Port not valid!\n");
goto exit_free_dev_rdev;
}
if (!pnp_irq_valid(pdev, 0)) {
dev_err(&pdev->dev, "PNP IRQ not valid!\n");
goto exit_free_dev_rdev;
}
if (!pnp_port_valid(pdev, 1) ||
pnp_port_len(pdev, 1) < CIR_IOREG_LENGTH) {
dev_err(&pdev->dev, "Wake PNP Port not valid!\n");
goto exit_free_dev_rdev;
}
nvt->cir_addr = pnp_port_start(pdev, 0);
nvt->cir_irq = pnp_irq(pdev, 0);
nvt->cir_wake_addr = pnp_port_start(pdev, 1);
nvt->cir_wake_irq = nvt->cir_irq;
nvt->cr_efir = CR_EFIR;
nvt->cr_efdr = CR_EFDR;
spin_lock_init(&nvt->nvt_lock);
spin_lock_init(&nvt->tx.lock);
pnp_set_drvdata(pdev, nvt);
nvt->pdev = pdev;
init_waitqueue_head(&nvt->tx.queue);
nvt_hw_detect(nvt);
nvt_efm_enable(nvt);
nvt_cir_ldev_init(nvt);
nvt_cir_wake_ldev_init(nvt);
nvt_efm_disable(nvt);
nvt_cir_regs_init(nvt);
nvt_cir_wake_regs_init(nvt);
rdev->priv = nvt;
rdev->driver_type = RC_DRIVER_IR_RAW;
rdev->allowed_protocols = RC_BIT_ALL;
rdev->open = nvt_open;
rdev->close = nvt_close;
rdev->tx_ir = nvt_tx_ir;
rdev->s_tx_carrier = nvt_set_tx_carrier;
rdev->input_name = "Nuvoton w836x7hg Infrared Remote Transceiver";
rdev->input_phys = "nuvoton/cir0";
rdev->input_id.bustype = BUS_HOST;
rdev->input_id.vendor = PCI_VENDOR_ID_WINBOND2;
rdev->input_id.product = nvt->chip_major;
rdev->input_id.version = nvt->chip_minor;
rdev->dev.parent = &pdev->dev;
rdev->driver_name = NVT_DRIVER_NAME;
rdev->map_name = RC_MAP_RC6_MCE;
rdev->timeout = MS_TO_NS(100);
rdev->rx_resolution = US_TO_NS(CIR_SAMPLE_PERIOD);
#if 0
rdev->min_timeout = XYZ;
rdev->max_timeout = XYZ;
rdev->tx_resolution = XYZ;
#endif
nvt->rdev = rdev;
ret = rc_register_device(rdev);
if (ret)
goto exit_free_dev_rdev;
ret = -EBUSY;
if (!devm_request_region(&pdev->dev, nvt->cir_addr,
CIR_IOREG_LENGTH, NVT_DRIVER_NAME))
goto exit_unregister_device;
if (devm_request_irq(&pdev->dev, nvt->cir_irq, nvt_cir_isr,
IRQF_SHARED, NVT_DRIVER_NAME, (void *)nvt))
goto exit_unregister_device;
if (!devm_request_region(&pdev->dev, nvt->cir_wake_addr,
CIR_IOREG_LENGTH, NVT_DRIVER_NAME))
goto exit_unregister_device;
if (devm_request_irq(&pdev->dev, nvt->cir_wake_irq,
nvt_cir_wake_isr, IRQF_SHARED,
NVT_DRIVER_NAME, (void *)nvt))
goto exit_unregister_device;
device_init_wakeup(&pdev->dev, true);
dev_notice(&pdev->dev, "driver has been successfully loaded\n");
if (debug) {
cir_dump_regs(nvt);
cir_wake_dump_regs(nvt);
}
return 0;
exit_unregister_device:
rc_unregister_device(rdev);
rdev = NULL;
exit_free_dev_rdev:
rc_free_device(rdev);
return ret;
}
static void nvt_remove(struct pnp_dev *pdev)
{
struct nvt_dev *nvt = pnp_get_drvdata(pdev);
unsigned long flags;
spin_lock_irqsave(&nvt->nvt_lock, flags);
nvt_cir_reg_write(nvt, 0, CIR_IREN);
nvt_disable_cir(nvt);
nvt_enable_wake(nvt);
spin_unlock_irqrestore(&nvt->nvt_lock, flags);
rc_unregister_device(nvt->rdev);
}
static int nvt_suspend(struct pnp_dev *pdev, pm_message_t state)
{
struct nvt_dev *nvt = pnp_get_drvdata(pdev);
unsigned long flags;
nvt_dbg("%s called", __func__);
spin_lock_irqsave(&nvt->nvt_lock, flags);
nvt->study_state = ST_STUDY_NONE;
nvt->wake_state = ST_WAKE_NONE;
spin_unlock_irqrestore(&nvt->nvt_lock, flags);
spin_lock_irqsave(&nvt->tx.lock, flags);
nvt->tx.tx_state = ST_TX_NONE;
spin_unlock_irqrestore(&nvt->tx.lock, flags);
nvt_cir_reg_write(nvt, 0, CIR_IREN);
nvt_efm_enable(nvt);
nvt_select_logical_dev(nvt, LOGICAL_DEV_CIR);
nvt_cr_write(nvt, LOGICAL_DEV_DISABLE, CR_LOGICAL_DEV_EN);
nvt_efm_disable(nvt);
nvt_enable_wake(nvt);
return 0;
}
static int nvt_resume(struct pnp_dev *pdev)
{
struct nvt_dev *nvt = pnp_get_drvdata(pdev);
nvt_dbg("%s called", __func__);
nvt_set_cir_iren(nvt);
nvt_efm_enable(nvt);
nvt_select_logical_dev(nvt, LOGICAL_DEV_CIR);
nvt_cr_write(nvt, LOGICAL_DEV_ENABLE, CR_LOGICAL_DEV_EN);
nvt_efm_disable(nvt);
nvt_cir_regs_init(nvt);
nvt_cir_wake_regs_init(nvt);
return 0;
}
static void nvt_shutdown(struct pnp_dev *pdev)
{
struct nvt_dev *nvt = pnp_get_drvdata(pdev);
nvt_enable_wake(nvt);
}
