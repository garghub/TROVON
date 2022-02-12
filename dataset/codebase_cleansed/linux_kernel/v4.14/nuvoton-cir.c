static inline struct device *nvt_get_dev(const struct nvt_dev *nvt)
{
return nvt->rdev->dev.parent;
}
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
static inline int nvt_efm_enable(struct nvt_dev *nvt)
{
if (!request_muxed_region(nvt->cr_efir, 2, NVT_DRIVER_NAME))
return -EBUSY;
outb(EFER_EFM_ENABLE, nvt->cr_efir);
outb(EFER_EFM_ENABLE, nvt->cr_efir);
return 0;
}
static inline void nvt_efm_disable(struct nvt_dev *nvt)
{
outb(EFER_EFM_DISABLE, nvt->cr_efir);
release_region(nvt->cr_efir, 2);
}
static inline void nvt_select_logical_dev(struct nvt_dev *nvt, u8 ldev)
{
nvt_cr_write(nvt, ldev, CR_LOGICAL_DEV_SEL);
}
static inline void nvt_enable_logical_dev(struct nvt_dev *nvt, u8 ldev)
{
nvt_efm_enable(nvt);
nvt_select_logical_dev(nvt, ldev);
nvt_cr_write(nvt, LOGICAL_DEV_ENABLE, CR_LOGICAL_DEV_EN);
nvt_efm_disable(nvt);
}
static inline void nvt_disable_logical_dev(struct nvt_dev *nvt, u8 ldev)
{
nvt_efm_enable(nvt);
nvt_select_logical_dev(nvt, ldev);
nvt_cr_write(nvt, LOGICAL_DEV_DISABLE, CR_LOGICAL_DEV_EN);
nvt_efm_disable(nvt);
}
static inline void nvt_cir_reg_write(struct nvt_dev *nvt, u8 val, u8 offset)
{
outb(val, nvt->cir_addr + offset);
}
static u8 nvt_cir_reg_read(struct nvt_dev *nvt, u8 offset)
{
return inb(nvt->cir_addr + offset);
}
static inline void nvt_cir_wake_reg_write(struct nvt_dev *nvt,
u8 val, u8 offset)
{
outb(val, nvt->cir_wake_addr + offset);
}
static u8 nvt_cir_wake_reg_read(struct nvt_dev *nvt, u8 offset)
{
return inb(nvt->cir_wake_addr + offset);
}
static void nvt_set_ioaddr(struct nvt_dev *nvt, unsigned long *ioaddr)
{
unsigned long old_addr;
old_addr = nvt_cr_read(nvt, CR_CIR_BASE_ADDR_HI) << 8;
old_addr |= nvt_cr_read(nvt, CR_CIR_BASE_ADDR_LO);
if (old_addr)
*ioaddr = old_addr;
else {
nvt_cr_write(nvt, *ioaddr >> 8, CR_CIR_BASE_ADDR_HI);
nvt_cr_write(nvt, *ioaddr & 0xff, CR_CIR_BASE_ADDR_LO);
}
}
static void nvt_write_wakeup_codes(struct rc_dev *dev,
const u8 *wbuf, int count)
{
u8 tolerance, config;
struct nvt_dev *nvt = dev->priv;
unsigned long flags;
int i;
tolerance = DIV_ROUND_UP(count, 10);
spin_lock_irqsave(&nvt->lock, flags);
nvt_clear_cir_wake_fifo(nvt);
nvt_cir_wake_reg_write(nvt, count, CIR_WAKE_FIFO_CMP_DEEP);
nvt_cir_wake_reg_write(nvt, tolerance, CIR_WAKE_FIFO_CMP_TOL);
config = nvt_cir_wake_reg_read(nvt, CIR_WAKE_IRCON);
nvt_cir_wake_reg_write(nvt, config | CIR_WAKE_IRCON_MODE1,
CIR_WAKE_IRCON);
if (count)
pr_info("Wake samples (%d) =", count);
else
pr_info("Wake sample fifo cleared");
for (i = 0; i < count; i++)
nvt_cir_wake_reg_write(nvt, wbuf[i], CIR_WAKE_WR_FIFO_DATA);
nvt_cir_wake_reg_write(nvt, config, CIR_WAKE_IRCON);
spin_unlock_irqrestore(&nvt->lock, flags);
}
static ssize_t wakeup_data_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct rc_dev *rc_dev = to_rc_dev(dev);
struct nvt_dev *nvt = rc_dev->priv;
int fifo_len, duration;
unsigned long flags;
ssize_t buf_len = 0;
int i;
spin_lock_irqsave(&nvt->lock, flags);
fifo_len = nvt_cir_wake_reg_read(nvt, CIR_WAKE_FIFO_COUNT);
fifo_len = min(fifo_len, WAKEUP_MAX_SIZE);
while (nvt_cir_wake_reg_read(nvt, CIR_WAKE_RD_FIFO_ONLY_IDX))
nvt_cir_wake_reg_read(nvt, CIR_WAKE_RD_FIFO_ONLY);
for (i = 0; i < fifo_len; i++) {
duration = nvt_cir_wake_reg_read(nvt, CIR_WAKE_RD_FIFO_ONLY);
duration = (duration & BUF_LEN_MASK) * SAMPLE_PERIOD;
buf_len += snprintf(buf + buf_len, PAGE_SIZE - buf_len,
"%d ", duration);
}
buf_len += snprintf(buf + buf_len, PAGE_SIZE - buf_len, "\n");
spin_unlock_irqrestore(&nvt->lock, flags);
return buf_len;
}
static ssize_t wakeup_data_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct rc_dev *rc_dev = to_rc_dev(dev);
u8 wake_buf[WAKEUP_MAX_SIZE];
char **argv;
int i, count;
unsigned int val;
ssize_t ret;
argv = argv_split(GFP_KERNEL, buf, &count);
if (!argv)
return -ENOMEM;
if (!count || count > WAKEUP_MAX_SIZE) {
ret = -EINVAL;
goto out;
}
for (i = 0; i < count; i++) {
ret = kstrtouint(argv[i], 10, &val);
if (ret)
goto out;
val = DIV_ROUND_CLOSEST(val, SAMPLE_PERIOD);
if (!val || val > 0x7f) {
ret = -EINVAL;
goto out;
}
wake_buf[i] = val;
if (i % 2 == 0)
wake_buf[i] |= BUF_PULSE_BIT;
}
nvt_write_wakeup_codes(rc_dev, wake_buf, count);
ret = len;
out:
argv_free(argv);
return ret;
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
static int nvt_hw_detect(struct nvt_dev *nvt)
{
struct device *dev = nvt_get_dev(nvt);
const char *chip_name;
int chip_id;
nvt_efm_enable(nvt);
nvt->chip_major = nvt_cr_read(nvt, CR_CHIP_ID_HI);
if (nvt->chip_major == 0xff) {
nvt_efm_disable(nvt);
nvt->cr_efir = CR_EFIR2;
nvt->cr_efdr = CR_EFDR2;
nvt_efm_enable(nvt);
nvt->chip_major = nvt_cr_read(nvt, CR_CHIP_ID_HI);
}
nvt->chip_minor = nvt_cr_read(nvt, CR_CHIP_ID_LO);
nvt_efm_disable(nvt);
chip_id = nvt->chip_major << 8 | nvt->chip_minor;
if (chip_id == NVT_INVALID) {
dev_err(dev, "No device found on either EFM port\n");
return -ENODEV;
}
chip_name = nvt_find_chip(nvt, chip_id);
if (!chip_name)
dev_warn(dev,
"unknown chip, id: 0x%02x 0x%02x, it may not work...",
nvt->chip_major, nvt->chip_minor);
else
dev_info(dev, "found %s or compatible: chip id: 0x%02x 0x%02x",
chip_name, nvt->chip_major, nvt->chip_minor);
return 0;
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
nvt_set_ioaddr(nvt, &nvt->cir_addr);
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
nvt_set_ioaddr(nvt, &nvt->cir_wake_addr);
nvt_dbg("CIR Wake initialized, base io port address: 0x%lx",
nvt->cir_wake_addr);
}
static void nvt_clear_cir_fifo(struct nvt_dev *nvt)
{
u8 val = nvt_cir_reg_read(nvt, CIR_FIFOCON);
nvt_cir_reg_write(nvt, val | CIR_FIFOCON_RXFIFOCLR, CIR_FIFOCON);
}
static void nvt_clear_cir_wake_fifo(struct nvt_dev *nvt)
{
u8 val, config;
config = nvt_cir_wake_reg_read(nvt, CIR_WAKE_IRCON);
nvt_cir_wake_reg_write(nvt, config & ~CIR_WAKE_IRCON_MODE0,
CIR_WAKE_IRCON);
val = nvt_cir_wake_reg_read(nvt, CIR_WAKE_FIFOCON);
nvt_cir_wake_reg_write(nvt, val | CIR_WAKE_FIFOCON_RXFIFOCLR,
CIR_WAKE_FIFOCON);
nvt_cir_wake_reg_write(nvt, config, CIR_WAKE_IRCON);
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
iren = CIR_IREN_RTR | CIR_IREN_PE | CIR_IREN_RFO;
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
nvt_enable_logical_dev(nvt, LOGICAL_DEV_CIR);
}
static void nvt_cir_wake_regs_init(struct nvt_dev *nvt)
{
nvt_cir_wake_reg_write(nvt, CIR_WAKE_IRCON_MODE0 |
CIR_WAKE_IRCON_R | CIR_WAKE_IRCON_RXINV |
CIR_WAKE_IRCON_SAMPLE_PERIOD_SEL,
CIR_WAKE_IRCON);
nvt_cir_wake_reg_write(nvt, 0xff, CIR_WAKE_IRSTS);
nvt_enable_logical_dev(nvt, LOGICAL_DEV_CIR_WAKE);
}
static void nvt_enable_wake(struct nvt_dev *nvt)
{
unsigned long flags;
nvt_efm_enable(nvt);
nvt_select_logical_dev(nvt, LOGICAL_DEV_ACPI);
nvt_set_reg_bit(nvt, CIR_WAKE_ENABLE_BIT, CR_ACPI_CIR_WAKE);
nvt_set_reg_bit(nvt, PME_INTR_CIR_PASS_BIT, CR_ACPI_IRQ_EVENTS2);
nvt_select_logical_dev(nvt, LOGICAL_DEV_CIR_WAKE);
nvt_cr_write(nvt, LOGICAL_DEV_ENABLE, CR_LOGICAL_DEV_EN);
nvt_efm_disable(nvt);
spin_lock_irqsave(&nvt->lock, flags);
nvt_cir_wake_reg_write(nvt, CIR_WAKE_IRCON_MODE0 | CIR_WAKE_IRCON_RXEN |
CIR_WAKE_IRCON_R | CIR_WAKE_IRCON_RXINV |
CIR_WAKE_IRCON_SAMPLE_PERIOD_SEL,
CIR_WAKE_IRCON);
nvt_cir_wake_reg_write(nvt, 0xff, CIR_WAKE_IRSTS);
nvt_cir_wake_reg_write(nvt, 0, CIR_WAKE_IREN);
spin_unlock_irqrestore(&nvt->lock, flags);
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
static int nvt_ir_raw_set_wakeup_filter(struct rc_dev *dev,
struct rc_scancode_filter *sc_filter)
{
u8 buf_val;
int i, ret, count;
unsigned int val;
struct ir_raw_event *raw;
u8 wake_buf[WAKEUP_MAX_SIZE];
bool complete;
if (!sc_filter->mask)
return 0;
raw = kmalloc_array(WAKEUP_MAX_SIZE, sizeof(*raw), GFP_KERNEL);
if (!raw)
return -ENOMEM;
ret = ir_raw_encode_scancode(dev->wakeup_protocol, sc_filter->data,
raw, WAKEUP_MAX_SIZE);
complete = (ret != -ENOBUFS);
if (!complete)
ret = WAKEUP_MAX_SIZE;
else if (ret < 0)
goto out_raw;
for (i = 0, count = 0; i < ret && count < WAKEUP_MAX_SIZE; ++i) {
val = DIV_ROUND_UP(raw[i].duration, 1000L) / SAMPLE_PERIOD;
while (val > 0 && count < WAKEUP_MAX_SIZE) {
if (complete && i == ret - 1 && val < BUF_LEN_MASK)
break;
buf_val = (val > BUF_LEN_MASK) ? BUF_LEN_MASK : val;
wake_buf[count] = buf_val;
val -= buf_val;
if ((raw[i]).pulse)
wake_buf[count] |= BUF_PULSE_BIT;
count++;
}
}
nvt_write_wakeup_codes(dev, wake_buf, count);
ret = 0;
out_raw:
kfree(raw);
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
for (i = 0; i < nvt->pkts; i++) {
sample = nvt->buf[i];
rawir.pulse = ((sample & BUF_PULSE_BIT) != 0);
rawir.duration = US_TO_NS((sample & BUF_LEN_MASK)
* SAMPLE_PERIOD);
nvt_dbg("Storing %s with duration %d",
rawir.pulse ? "pulse" : "space", rawir.duration);
ir_raw_event_store_with_filter(nvt->rdev, &rawir);
}
nvt->pkts = 0;
nvt_dbg("Calling ir_raw_event_handle\n");
ir_raw_event_handle(nvt->rdev);
nvt_dbg_verbose("%s done", __func__);
}
static void nvt_handle_rx_fifo_overrun(struct nvt_dev *nvt)
{
dev_warn(nvt_get_dev(nvt), "RX FIFO overrun detected, flushing data!");
nvt->pkts = 0;
nvt_clear_cir_fifo(nvt);
ir_raw_event_reset(nvt->rdev);
}
static void nvt_get_rx_ir_data(struct nvt_dev *nvt)
{
u8 fifocount;
int i;
fifocount = nvt_cir_reg_read(nvt, CIR_RXFCONT);
nvt_dbg("attempting to fetch %u bytes from hw rx fifo", fifocount);
for (i = 0; i < fifocount; i++)
nvt->buf[i] = nvt_cir_reg_read(nvt, CIR_SRXFIFO);
nvt->pkts = fifocount;
nvt_dbg("%s: pkts now %d", __func__, nvt->pkts);
nvt_process_rx_ir_data(nvt);
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
static irqreturn_t nvt_cir_isr(int irq, void *data)
{
struct nvt_dev *nvt = data;
u8 status, iren;
nvt_dbg_verbose("%s firing", __func__);
spin_lock(&nvt->lock);
status = nvt_cir_reg_read(nvt, CIR_IRSTS);
iren = nvt_cir_reg_read(nvt, CIR_IREN);
if (status == 0xff && iren == 0xff) {
spin_unlock(&nvt->lock);
nvt_dbg_verbose("Spurious interrupt detected");
return IRQ_HANDLED;
}
if (!(status & iren)) {
spin_unlock(&nvt->lock);
nvt_dbg_verbose("%s exiting, IRSTS 0x0", __func__);
return IRQ_NONE;
}
nvt_cir_reg_write(nvt, status, CIR_IRSTS);
nvt_cir_reg_write(nvt, 0, CIR_IRSTS);
nvt_cir_log_irqs(status, iren);
if (status & CIR_IRSTS_RFO)
nvt_handle_rx_fifo_overrun(nvt);
else if (status & (CIR_IRSTS_RTR | CIR_IRSTS_PE))
nvt_get_rx_ir_data(nvt);
spin_unlock(&nvt->lock);
nvt_dbg_verbose("%s done", __func__);
return IRQ_HANDLED;
}
static void nvt_disable_cir(struct nvt_dev *nvt)
{
unsigned long flags;
spin_lock_irqsave(&nvt->lock, flags);
nvt_cir_reg_write(nvt, 0, CIR_IREN);
nvt_cir_reg_write(nvt, 0xff, CIR_IRSTS);
nvt_cir_reg_write(nvt, 0, CIR_IRCON);
nvt_clear_cir_fifo(nvt);
nvt_clear_tx_fifo(nvt);
spin_unlock_irqrestore(&nvt->lock, flags);
nvt_disable_logical_dev(nvt, LOGICAL_DEV_CIR);
}
static int nvt_open(struct rc_dev *dev)
{
struct nvt_dev *nvt = dev->priv;
unsigned long flags;
spin_lock_irqsave(&nvt->lock, flags);
nvt_cir_reg_write(nvt, CIR_IRCON_TXEN | CIR_IRCON_RXEN |
CIR_IRCON_RXINV | CIR_IRCON_SAMPLE_PERIOD_SEL,
CIR_IRCON);
nvt_cir_reg_write(nvt, 0xff, CIR_IRSTS);
nvt_set_cir_iren(nvt);
spin_unlock_irqrestore(&nvt->lock, flags);
nvt_enable_logical_dev(nvt, LOGICAL_DEV_CIR);
return 0;
}
static void nvt_close(struct rc_dev *dev)
{
struct nvt_dev *nvt = dev->priv;
nvt_disable_cir(nvt);
}
static int nvt_probe(struct pnp_dev *pdev, const struct pnp_device_id *dev_id)
{
struct nvt_dev *nvt;
struct rc_dev *rdev;
int ret;
nvt = devm_kzalloc(&pdev->dev, sizeof(struct nvt_dev), GFP_KERNEL);
if (!nvt)
return -ENOMEM;
nvt->rdev = devm_rc_allocate_device(&pdev->dev, RC_DRIVER_IR_RAW);
if (!nvt->rdev)
return -ENOMEM;
rdev = nvt->rdev;
ret = pnp_activate_dev(pdev);
if (ret) {
dev_err(&pdev->dev, "Could not activate PNP device!\n");
return ret;
}
if (!pnp_port_valid(pdev, 0) ||
pnp_port_len(pdev, 0) < CIR_IOREG_LENGTH) {
dev_err(&pdev->dev, "IR PNP Port not valid!\n");
return -EINVAL;
}
if (!pnp_irq_valid(pdev, 0)) {
dev_err(&pdev->dev, "PNP IRQ not valid!\n");
return -EINVAL;
}
if (!pnp_port_valid(pdev, 1) ||
pnp_port_len(pdev, 1) < CIR_IOREG_LENGTH) {
dev_err(&pdev->dev, "Wake PNP Port not valid!\n");
return -EINVAL;
}
nvt->cir_addr = pnp_port_start(pdev, 0);
nvt->cir_irq = pnp_irq(pdev, 0);
nvt->cir_wake_addr = pnp_port_start(pdev, 1);
nvt->cr_efir = CR_EFIR;
nvt->cr_efdr = CR_EFDR;
spin_lock_init(&nvt->lock);
pnp_set_drvdata(pdev, nvt);
ret = nvt_hw_detect(nvt);
if (ret)
return ret;
nvt_efm_enable(nvt);
nvt_cir_ldev_init(nvt);
nvt_cir_wake_ldev_init(nvt);
nvt_efm_disable(nvt);
nvt_cir_regs_init(nvt);
nvt_cir_wake_regs_init(nvt);
rdev->priv = nvt;
rdev->allowed_protocols = RC_PROTO_BIT_ALL_IR_DECODER;
rdev->allowed_wakeup_protocols = RC_PROTO_BIT_ALL_IR_ENCODER;
rdev->encode_wakeup = true;
rdev->open = nvt_open;
rdev->close = nvt_close;
rdev->s_tx_carrier = nvt_set_tx_carrier;
rdev->s_wakeup_filter = nvt_ir_raw_set_wakeup_filter;
rdev->device_name = "Nuvoton w836x7hg Infrared Remote Transceiver";
rdev->input_phys = "nuvoton/cir0";
rdev->input_id.bustype = BUS_HOST;
rdev->input_id.vendor = PCI_VENDOR_ID_WINBOND2;
rdev->input_id.product = nvt->chip_major;
rdev->input_id.version = nvt->chip_minor;
rdev->driver_name = NVT_DRIVER_NAME;
rdev->map_name = RC_MAP_RC6_MCE;
rdev->timeout = MS_TO_NS(100);
rdev->rx_resolution = US_TO_NS(CIR_SAMPLE_PERIOD);
#if 0
rdev->min_timeout = XYZ;
rdev->max_timeout = XYZ;
#endif
ret = devm_rc_register_device(&pdev->dev, rdev);
if (ret)
return ret;
if (!devm_request_region(&pdev->dev, nvt->cir_addr,
CIR_IOREG_LENGTH, NVT_DRIVER_NAME))
return -EBUSY;
ret = devm_request_irq(&pdev->dev, nvt->cir_irq, nvt_cir_isr,
IRQF_SHARED, NVT_DRIVER_NAME, nvt);
if (ret)
return ret;
if (!devm_request_region(&pdev->dev, nvt->cir_wake_addr,
CIR_IOREG_LENGTH, NVT_DRIVER_NAME "-wake"))
return -EBUSY;
ret = device_create_file(&rdev->dev, &dev_attr_wakeup_data);
if (ret)
return ret;
device_init_wakeup(&pdev->dev, true);
dev_notice(&pdev->dev, "driver has been successfully loaded\n");
if (debug) {
cir_dump_regs(nvt);
cir_wake_dump_regs(nvt);
}
return 0;
}
static void nvt_remove(struct pnp_dev *pdev)
{
struct nvt_dev *nvt = pnp_get_drvdata(pdev);
device_remove_file(&nvt->rdev->dev, &dev_attr_wakeup_data);
nvt_disable_cir(nvt);
nvt_enable_wake(nvt);
}
static int nvt_suspend(struct pnp_dev *pdev, pm_message_t state)
{
struct nvt_dev *nvt = pnp_get_drvdata(pdev);
unsigned long flags;
nvt_dbg("%s called", __func__);
spin_lock_irqsave(&nvt->lock, flags);
nvt_cir_reg_write(nvt, 0, CIR_IREN);
spin_unlock_irqrestore(&nvt->lock, flags);
nvt_disable_logical_dev(nvt, LOGICAL_DEV_CIR);
nvt_enable_wake(nvt);
return 0;
}
static int nvt_resume(struct pnp_dev *pdev)
{
struct nvt_dev *nvt = pnp_get_drvdata(pdev);
nvt_dbg("%s called", __func__);
nvt_cir_regs_init(nvt);
nvt_cir_wake_regs_init(nvt);
return 0;
}
static void nvt_shutdown(struct pnp_dev *pdev)
{
struct nvt_dev *nvt = pnp_get_drvdata(pdev);
nvt_enable_wake(nvt);
}
