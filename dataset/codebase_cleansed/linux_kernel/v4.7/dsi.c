static inline struct dsi_data *dsi_get_dsidrv_data(struct platform_device *dsidev)
{
return dev_get_drvdata(&dsidev->dev);
}
static inline struct platform_device *dsi_get_dsidev_from_dssdev(struct omap_dss_device *dssdev)
{
return to_platform_device(dssdev->dev);
}
static struct platform_device *dsi_get_dsidev_from_id(int module)
{
struct omap_dss_device *out;
enum omap_dss_output_id id;
switch (module) {
case 0:
id = OMAP_DSS_OUTPUT_DSI1;
break;
case 1:
id = OMAP_DSS_OUTPUT_DSI2;
break;
default:
return NULL;
}
out = omap_dss_get_output(id);
return out ? to_platform_device(out->dev) : NULL;
}
static inline void dsi_write_reg(struct platform_device *dsidev,
const struct dsi_reg idx, u32 val)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
void __iomem *base;
switch(idx.module) {
case DSI_PROTO: base = dsi->proto_base; break;
case DSI_PHY: base = dsi->phy_base; break;
case DSI_PLL: base = dsi->pll_base; break;
default: return;
}
__raw_writel(val, base + idx.idx);
}
static inline u32 dsi_read_reg(struct platform_device *dsidev,
const struct dsi_reg idx)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
void __iomem *base;
switch(idx.module) {
case DSI_PROTO: base = dsi->proto_base; break;
case DSI_PHY: base = dsi->phy_base; break;
case DSI_PLL: base = dsi->pll_base; break;
default: return 0;
}
return __raw_readl(base + idx.idx);
}
static void dsi_bus_lock(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
down(&dsi->bus_lock);
}
static void dsi_bus_unlock(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
up(&dsi->bus_lock);
}
static bool dsi_bus_is_locked(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
return dsi->bus_lock.count == 0;
}
static void dsi_completion_handler(void *data, u32 mask)
{
complete((struct completion *)data);
}
static inline int wait_for_bit_change(struct platform_device *dsidev,
const struct dsi_reg idx, int bitnum, int value)
{
unsigned long timeout;
ktime_t wait;
int t;
t = 100;
while (t-- > 0) {
if (REG_GET(dsidev, idx, bitnum, bitnum) == value)
return value;
}
timeout = jiffies + msecs_to_jiffies(500);
while (time_before(jiffies, timeout)) {
if (REG_GET(dsidev, idx, bitnum, bitnum) == value)
return value;
wait = ns_to_ktime(1000 * 1000);
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_hrtimeout(&wait, HRTIMER_MODE_REL);
}
return !value;
}
u8 dsi_get_pixel_size(enum omap_dss_dsi_pixel_format fmt)
{
switch (fmt) {
case OMAP_DSS_DSI_FMT_RGB888:
case OMAP_DSS_DSI_FMT_RGB666:
return 24;
case OMAP_DSS_DSI_FMT_RGB666_PACKED:
return 18;
case OMAP_DSS_DSI_FMT_RGB565:
return 16;
default:
BUG();
return 0;
}
}
static void dsi_perf_mark_setup(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
dsi->perf_setup_time = ktime_get();
}
static void dsi_perf_mark_start(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
dsi->perf_start_time = ktime_get();
}
static void dsi_perf_show(struct platform_device *dsidev, const char *name)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
ktime_t t, setup_time, trans_time;
u32 total_bytes;
u32 setup_us, trans_us, total_us;
if (!dsi_perf)
return;
t = ktime_get();
setup_time = ktime_sub(dsi->perf_start_time, dsi->perf_setup_time);
setup_us = (u32)ktime_to_us(setup_time);
if (setup_us == 0)
setup_us = 1;
trans_time = ktime_sub(t, dsi->perf_start_time);
trans_us = (u32)ktime_to_us(trans_time);
if (trans_us == 0)
trans_us = 1;
total_us = setup_us + trans_us;
total_bytes = dsi->update_bytes;
printk(KERN_INFO "DSI(%s): %u us + %u us = %u us (%uHz), "
"%u bytes, %u kbytes/sec\n",
name,
setup_us,
trans_us,
total_us,
1000*1000 / total_us,
total_bytes,
total_bytes * 1000 / total_us);
}
static inline void dsi_perf_mark_setup(struct platform_device *dsidev)
{
}
static inline void dsi_perf_mark_start(struct platform_device *dsidev)
{
}
static inline void dsi_perf_show(struct platform_device *dsidev,
const char *name)
{
}
static void print_irq_status(u32 status)
{
if (status == 0)
return;
if (!verbose_irq && (status & ~DSI_IRQ_CHANNEL_MASK) == 0)
return;
#define PIS(x) (status & DSI_IRQ_##x) ? (#x " ") : ""
pr_debug("DSI IRQ: 0x%x: %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s\n",
status,
verbose_irq ? PIS(VC0) : "",
verbose_irq ? PIS(VC1) : "",
verbose_irq ? PIS(VC2) : "",
verbose_irq ? PIS(VC3) : "",
PIS(WAKEUP),
PIS(RESYNC),
PIS(PLL_LOCK),
PIS(PLL_UNLOCK),
PIS(PLL_RECALL),
PIS(COMPLEXIO_ERR),
PIS(HS_TX_TIMEOUT),
PIS(LP_RX_TIMEOUT),
PIS(TE_TRIGGER),
PIS(ACK_TRIGGER),
PIS(SYNC_LOST),
PIS(LDO_POWER_GOOD),
PIS(TA_TIMEOUT));
#undef PIS
}
static void print_irq_status_vc(int channel, u32 status)
{
if (status == 0)
return;
if (!verbose_irq && (status & ~DSI_VC_IRQ_PACKET_SENT) == 0)
return;
#define PIS(x) (status & DSI_VC_IRQ_##x) ? (#x " ") : ""
pr_debug("DSI VC(%d) IRQ 0x%x: %s%s%s%s%s%s%s%s%s\n",
channel,
status,
PIS(CS),
PIS(ECC_CORR),
PIS(ECC_NO_CORR),
verbose_irq ? PIS(PACKET_SENT) : "",
PIS(BTA),
PIS(FIFO_TX_OVF),
PIS(FIFO_RX_OVF),
PIS(FIFO_TX_UDF),
PIS(PP_BUSY_CHANGE));
#undef PIS
}
static void print_irq_status_cio(u32 status)
{
if (status == 0)
return;
#define PIS(x) (status & DSI_CIO_IRQ_##x) ? (#x " ") : ""
pr_debug("DSI CIO IRQ 0x%x: %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s\n",
status,
PIS(ERRSYNCESC1),
PIS(ERRSYNCESC2),
PIS(ERRSYNCESC3),
PIS(ERRESC1),
PIS(ERRESC2),
PIS(ERRESC3),
PIS(ERRCONTROL1),
PIS(ERRCONTROL2),
PIS(ERRCONTROL3),
PIS(STATEULPS1),
PIS(STATEULPS2),
PIS(STATEULPS3),
PIS(ERRCONTENTIONLP0_1),
PIS(ERRCONTENTIONLP1_1),
PIS(ERRCONTENTIONLP0_2),
PIS(ERRCONTENTIONLP1_2),
PIS(ERRCONTENTIONLP0_3),
PIS(ERRCONTENTIONLP1_3),
PIS(ULPSACTIVENOT_ALL0),
PIS(ULPSACTIVENOT_ALL1));
#undef PIS
}
static void dsi_collect_irq_stats(struct platform_device *dsidev, u32 irqstatus,
u32 *vcstatus, u32 ciostatus)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int i;
spin_lock(&dsi->irq_stats_lock);
dsi->irq_stats.irq_count++;
dss_collect_irq_stats(irqstatus, dsi->irq_stats.dsi_irqs);
for (i = 0; i < 4; ++i)
dss_collect_irq_stats(vcstatus[i], dsi->irq_stats.vc_irqs[i]);
dss_collect_irq_stats(ciostatus, dsi->irq_stats.cio_irqs);
spin_unlock(&dsi->irq_stats_lock);
}
static void dsi_handle_irq_errors(struct platform_device *dsidev, u32 irqstatus,
u32 *vcstatus, u32 ciostatus)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int i;
if (irqstatus & DSI_IRQ_ERROR_MASK) {
DSSERR("DSI error, irqstatus %x\n", irqstatus);
print_irq_status(irqstatus);
spin_lock(&dsi->errors_lock);
dsi->errors |= irqstatus & DSI_IRQ_ERROR_MASK;
spin_unlock(&dsi->errors_lock);
} else if (debug_irq) {
print_irq_status(irqstatus);
}
for (i = 0; i < 4; ++i) {
if (vcstatus[i] & DSI_VC_IRQ_ERROR_MASK) {
DSSERR("DSI VC(%d) error, vc irqstatus %x\n",
i, vcstatus[i]);
print_irq_status_vc(i, vcstatus[i]);
} else if (debug_irq) {
print_irq_status_vc(i, vcstatus[i]);
}
}
if (ciostatus & DSI_CIO_IRQ_ERROR_MASK) {
DSSERR("DSI CIO error, cio irqstatus %x\n", ciostatus);
print_irq_status_cio(ciostatus);
} else if (debug_irq) {
print_irq_status_cio(ciostatus);
}
}
static void dsi_call_isrs(struct dsi_isr_data *isr_array,
unsigned isr_array_size, u32 irqstatus)
{
struct dsi_isr_data *isr_data;
int i;
for (i = 0; i < isr_array_size; i++) {
isr_data = &isr_array[i];
if (isr_data->isr && isr_data->mask & irqstatus)
isr_data->isr(isr_data->arg, irqstatus);
}
}
static void dsi_handle_isrs(struct dsi_isr_tables *isr_tables,
u32 irqstatus, u32 *vcstatus, u32 ciostatus)
{
int i;
dsi_call_isrs(isr_tables->isr_table,
ARRAY_SIZE(isr_tables->isr_table),
irqstatus);
for (i = 0; i < 4; ++i) {
if (vcstatus[i] == 0)
continue;
dsi_call_isrs(isr_tables->isr_table_vc[i],
ARRAY_SIZE(isr_tables->isr_table_vc[i]),
vcstatus[i]);
}
if (ciostatus != 0)
dsi_call_isrs(isr_tables->isr_table_cio,
ARRAY_SIZE(isr_tables->isr_table_cio),
ciostatus);
}
static irqreturn_t omap_dsi_irq_handler(int irq, void *arg)
{
struct platform_device *dsidev;
struct dsi_data *dsi;
u32 irqstatus, vcstatus[4], ciostatus;
int i;
dsidev = (struct platform_device *) arg;
dsi = dsi_get_dsidrv_data(dsidev);
if (!dsi->is_enabled)
return IRQ_NONE;
spin_lock(&dsi->irq_lock);
irqstatus = dsi_read_reg(dsidev, DSI_IRQSTATUS);
if (!irqstatus) {
spin_unlock(&dsi->irq_lock);
return IRQ_NONE;
}
dsi_write_reg(dsidev, DSI_IRQSTATUS, irqstatus & ~DSI_IRQ_CHANNEL_MASK);
dsi_read_reg(dsidev, DSI_IRQSTATUS);
for (i = 0; i < 4; ++i) {
if ((irqstatus & (1 << i)) == 0) {
vcstatus[i] = 0;
continue;
}
vcstatus[i] = dsi_read_reg(dsidev, DSI_VC_IRQSTATUS(i));
dsi_write_reg(dsidev, DSI_VC_IRQSTATUS(i), vcstatus[i]);
dsi_read_reg(dsidev, DSI_VC_IRQSTATUS(i));
}
if (irqstatus & DSI_IRQ_COMPLEXIO_ERR) {
ciostatus = dsi_read_reg(dsidev, DSI_COMPLEXIO_IRQ_STATUS);
dsi_write_reg(dsidev, DSI_COMPLEXIO_IRQ_STATUS, ciostatus);
dsi_read_reg(dsidev, DSI_COMPLEXIO_IRQ_STATUS);
} else {
ciostatus = 0;
}
#ifdef DSI_CATCH_MISSING_TE
if (irqstatus & DSI_IRQ_TE_TRIGGER)
del_timer(&dsi->te_timer);
#endif
memcpy(&dsi->isr_tables_copy, &dsi->isr_tables,
sizeof(dsi->isr_tables));
spin_unlock(&dsi->irq_lock);
dsi_handle_isrs(&dsi->isr_tables_copy, irqstatus, vcstatus, ciostatus);
dsi_handle_irq_errors(dsidev, irqstatus, vcstatus, ciostatus);
dsi_collect_irq_stats(dsidev, irqstatus, vcstatus, ciostatus);
return IRQ_HANDLED;
}
static void _omap_dsi_configure_irqs(struct platform_device *dsidev,
struct dsi_isr_data *isr_array,
unsigned isr_array_size, u32 default_mask,
const struct dsi_reg enable_reg,
const struct dsi_reg status_reg)
{
struct dsi_isr_data *isr_data;
u32 mask;
u32 old_mask;
int i;
mask = default_mask;
for (i = 0; i < isr_array_size; i++) {
isr_data = &isr_array[i];
if (isr_data->isr == NULL)
continue;
mask |= isr_data->mask;
}
old_mask = dsi_read_reg(dsidev, enable_reg);
dsi_write_reg(dsidev, status_reg, (mask ^ old_mask) & mask);
dsi_write_reg(dsidev, enable_reg, mask);
dsi_read_reg(dsidev, enable_reg);
dsi_read_reg(dsidev, status_reg);
}
static void _omap_dsi_set_irqs(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
u32 mask = DSI_IRQ_ERROR_MASK;
#ifdef DSI_CATCH_MISSING_TE
mask |= DSI_IRQ_TE_TRIGGER;
#endif
_omap_dsi_configure_irqs(dsidev, dsi->isr_tables.isr_table,
ARRAY_SIZE(dsi->isr_tables.isr_table), mask,
DSI_IRQENABLE, DSI_IRQSTATUS);
}
static void _omap_dsi_set_irqs_vc(struct platform_device *dsidev, int vc)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
_omap_dsi_configure_irqs(dsidev, dsi->isr_tables.isr_table_vc[vc],
ARRAY_SIZE(dsi->isr_tables.isr_table_vc[vc]),
DSI_VC_IRQ_ERROR_MASK,
DSI_VC_IRQENABLE(vc), DSI_VC_IRQSTATUS(vc));
}
static void _omap_dsi_set_irqs_cio(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
_omap_dsi_configure_irqs(dsidev, dsi->isr_tables.isr_table_cio,
ARRAY_SIZE(dsi->isr_tables.isr_table_cio),
DSI_CIO_IRQ_ERROR_MASK,
DSI_COMPLEXIO_IRQ_ENABLE, DSI_COMPLEXIO_IRQ_STATUS);
}
static void _dsi_initialize_irq(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
unsigned long flags;
int vc;
spin_lock_irqsave(&dsi->irq_lock, flags);
memset(&dsi->isr_tables, 0, sizeof(dsi->isr_tables));
_omap_dsi_set_irqs(dsidev);
for (vc = 0; vc < 4; ++vc)
_omap_dsi_set_irqs_vc(dsidev, vc);
_omap_dsi_set_irqs_cio(dsidev);
spin_unlock_irqrestore(&dsi->irq_lock, flags);
}
static int _dsi_register_isr(omap_dsi_isr_t isr, void *arg, u32 mask,
struct dsi_isr_data *isr_array, unsigned isr_array_size)
{
struct dsi_isr_data *isr_data;
int free_idx;
int i;
BUG_ON(isr == NULL);
free_idx = -1;
for (i = 0; i < isr_array_size; i++) {
isr_data = &isr_array[i];
if (isr_data->isr == isr && isr_data->arg == arg &&
isr_data->mask == mask) {
return -EINVAL;
}
if (isr_data->isr == NULL && free_idx == -1)
free_idx = i;
}
if (free_idx == -1)
return -EBUSY;
isr_data = &isr_array[free_idx];
isr_data->isr = isr;
isr_data->arg = arg;
isr_data->mask = mask;
return 0;
}
static int _dsi_unregister_isr(omap_dsi_isr_t isr, void *arg, u32 mask,
struct dsi_isr_data *isr_array, unsigned isr_array_size)
{
struct dsi_isr_data *isr_data;
int i;
for (i = 0; i < isr_array_size; i++) {
isr_data = &isr_array[i];
if (isr_data->isr != isr || isr_data->arg != arg ||
isr_data->mask != mask)
continue;
isr_data->isr = NULL;
isr_data->arg = NULL;
isr_data->mask = 0;
return 0;
}
return -EINVAL;
}
static int dsi_register_isr(struct platform_device *dsidev, omap_dsi_isr_t isr,
void *arg, u32 mask)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
unsigned long flags;
int r;
spin_lock_irqsave(&dsi->irq_lock, flags);
r = _dsi_register_isr(isr, arg, mask, dsi->isr_tables.isr_table,
ARRAY_SIZE(dsi->isr_tables.isr_table));
if (r == 0)
_omap_dsi_set_irqs(dsidev);
spin_unlock_irqrestore(&dsi->irq_lock, flags);
return r;
}
static int dsi_unregister_isr(struct platform_device *dsidev,
omap_dsi_isr_t isr, void *arg, u32 mask)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
unsigned long flags;
int r;
spin_lock_irqsave(&dsi->irq_lock, flags);
r = _dsi_unregister_isr(isr, arg, mask, dsi->isr_tables.isr_table,
ARRAY_SIZE(dsi->isr_tables.isr_table));
if (r == 0)
_omap_dsi_set_irqs(dsidev);
spin_unlock_irqrestore(&dsi->irq_lock, flags);
return r;
}
static int dsi_register_isr_vc(struct platform_device *dsidev, int channel,
omap_dsi_isr_t isr, void *arg, u32 mask)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
unsigned long flags;
int r;
spin_lock_irqsave(&dsi->irq_lock, flags);
r = _dsi_register_isr(isr, arg, mask,
dsi->isr_tables.isr_table_vc[channel],
ARRAY_SIZE(dsi->isr_tables.isr_table_vc[channel]));
if (r == 0)
_omap_dsi_set_irqs_vc(dsidev, channel);
spin_unlock_irqrestore(&dsi->irq_lock, flags);
return r;
}
static int dsi_unregister_isr_vc(struct platform_device *dsidev, int channel,
omap_dsi_isr_t isr, void *arg, u32 mask)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
unsigned long flags;
int r;
spin_lock_irqsave(&dsi->irq_lock, flags);
r = _dsi_unregister_isr(isr, arg, mask,
dsi->isr_tables.isr_table_vc[channel],
ARRAY_SIZE(dsi->isr_tables.isr_table_vc[channel]));
if (r == 0)
_omap_dsi_set_irqs_vc(dsidev, channel);
spin_unlock_irqrestore(&dsi->irq_lock, flags);
return r;
}
static int dsi_register_isr_cio(struct platform_device *dsidev,
omap_dsi_isr_t isr, void *arg, u32 mask)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
unsigned long flags;
int r;
spin_lock_irqsave(&dsi->irq_lock, flags);
r = _dsi_register_isr(isr, arg, mask, dsi->isr_tables.isr_table_cio,
ARRAY_SIZE(dsi->isr_tables.isr_table_cio));
if (r == 0)
_omap_dsi_set_irqs_cio(dsidev);
spin_unlock_irqrestore(&dsi->irq_lock, flags);
return r;
}
static int dsi_unregister_isr_cio(struct platform_device *dsidev,
omap_dsi_isr_t isr, void *arg, u32 mask)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
unsigned long flags;
int r;
spin_lock_irqsave(&dsi->irq_lock, flags);
r = _dsi_unregister_isr(isr, arg, mask, dsi->isr_tables.isr_table_cio,
ARRAY_SIZE(dsi->isr_tables.isr_table_cio));
if (r == 0)
_omap_dsi_set_irqs_cio(dsidev);
spin_unlock_irqrestore(&dsi->irq_lock, flags);
return r;
}
static u32 dsi_get_errors(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
unsigned long flags;
u32 e;
spin_lock_irqsave(&dsi->errors_lock, flags);
e = dsi->errors;
dsi->errors = 0;
spin_unlock_irqrestore(&dsi->errors_lock, flags);
return e;
}
static int dsi_runtime_get(struct platform_device *dsidev)
{
int r;
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
DSSDBG("dsi_runtime_get\n");
r = pm_runtime_get_sync(&dsi->pdev->dev);
WARN_ON(r < 0);
return r < 0 ? r : 0;
}
static void dsi_runtime_put(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int r;
DSSDBG("dsi_runtime_put\n");
r = pm_runtime_put_sync(&dsi->pdev->dev);
WARN_ON(r < 0 && r != -ENOSYS);
}
static int dsi_regulator_init(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct regulator *vdds_dsi;
if (dsi->vdds_dsi_reg != NULL)
return 0;
vdds_dsi = devm_regulator_get(&dsi->pdev->dev, "vdd");
if (IS_ERR(vdds_dsi)) {
if (PTR_ERR(vdds_dsi) != -EPROBE_DEFER)
DSSERR("can't get DSI VDD regulator\n");
return PTR_ERR(vdds_dsi);
}
dsi->vdds_dsi_reg = vdds_dsi;
return 0;
}
static void _dsi_print_reset_status(struct platform_device *dsidev)
{
u32 l;
int b0, b1, b2;
l = dsi_read_reg(dsidev, DSI_DSIPHY_CFG5);
if (dss_has_feature(FEAT_DSI_REVERSE_TXCLKESC)) {
b0 = 28;
b1 = 27;
b2 = 26;
} else {
b0 = 24;
b1 = 25;
b2 = 26;
}
#define DSI_FLD_GET(fld, start, end)\
FLD_GET(dsi_read_reg(dsidev, DSI_##fld), start, end)
pr_debug("DSI resets: PLL (%d) CIO (%d) PHY (%x%x%x, %d, %d, %d)\n",
DSI_FLD_GET(PLL_STATUS, 0, 0),
DSI_FLD_GET(COMPLEXIO_CFG1, 29, 29),
DSI_FLD_GET(DSIPHY_CFG5, b0, b0),
DSI_FLD_GET(DSIPHY_CFG5, b1, b1),
DSI_FLD_GET(DSIPHY_CFG5, b2, b2),
DSI_FLD_GET(DSIPHY_CFG5, 29, 29),
DSI_FLD_GET(DSIPHY_CFG5, 30, 30),
DSI_FLD_GET(DSIPHY_CFG5, 31, 31));
#undef DSI_FLD_GET
}
static inline int dsi_if_enable(struct platform_device *dsidev, bool enable)
{
DSSDBG("dsi_if_enable(%d)\n", enable);
enable = enable ? 1 : 0;
REG_FLD_MOD(dsidev, DSI_CTRL, enable, 0, 0);
if (wait_for_bit_change(dsidev, DSI_CTRL, 0, enable) != enable) {
DSSERR("Failed to set dsi_if_enable to %d\n", enable);
return -EIO;
}
return 0;
}
static unsigned long dsi_get_pll_hsdiv_dispc_rate(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
return dsi->pll.cinfo.clkout[HSDIV_DISPC];
}
static unsigned long dsi_get_pll_hsdiv_dsi_rate(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
return dsi->pll.cinfo.clkout[HSDIV_DSI];
}
static unsigned long dsi_get_txbyteclkhs(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
return dsi->pll.cinfo.clkdco / 16;
}
static unsigned long dsi_fclk_rate(struct platform_device *dsidev)
{
unsigned long r;
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
if (dss_get_dsi_clk_source(dsi->module_id) == OMAP_DSS_CLK_SRC_FCK) {
r = clk_get_rate(dsi->dss_clk);
} else {
r = dsi_get_pll_hsdiv_dsi_rate(dsidev);
}
return r;
}
static int dsi_lp_clock_calc(unsigned long dsi_fclk,
unsigned long lp_clk_min, unsigned long lp_clk_max,
struct dsi_lp_clock_info *lp_cinfo)
{
unsigned lp_clk_div;
unsigned long lp_clk;
lp_clk_div = DIV_ROUND_UP(dsi_fclk, lp_clk_max * 2);
lp_clk = dsi_fclk / 2 / lp_clk_div;
if (lp_clk < lp_clk_min || lp_clk > lp_clk_max)
return -EINVAL;
lp_cinfo->lp_clk_div = lp_clk_div;
lp_cinfo->lp_clk = lp_clk;
return 0;
}
static int dsi_set_lp_clk_divisor(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
unsigned long dsi_fclk;
unsigned lp_clk_div;
unsigned long lp_clk;
unsigned lpdiv_max = dss_feat_get_param_max(FEAT_PARAM_DSIPLL_LPDIV);
lp_clk_div = dsi->user_lp_cinfo.lp_clk_div;
if (lp_clk_div == 0 || lp_clk_div > lpdiv_max)
return -EINVAL;
dsi_fclk = dsi_fclk_rate(dsidev);
lp_clk = dsi_fclk / 2 / lp_clk_div;
DSSDBG("LP_CLK_DIV %u, LP_CLK %lu\n", lp_clk_div, lp_clk);
dsi->current_lp_cinfo.lp_clk = lp_clk;
dsi->current_lp_cinfo.lp_clk_div = lp_clk_div;
REG_FLD_MOD(dsidev, DSI_CLK_CTRL, lp_clk_div, 12, 0);
REG_FLD_MOD(dsidev, DSI_CLK_CTRL, dsi_fclk > 30000000 ? 1 : 0, 21, 21);
return 0;
}
static void dsi_enable_scp_clk(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
if (dsi->scp_clk_refcount++ == 0)
REG_FLD_MOD(dsidev, DSI_CLK_CTRL, 1, 14, 14);
}
static void dsi_disable_scp_clk(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
WARN_ON(dsi->scp_clk_refcount == 0);
if (--dsi->scp_clk_refcount == 0)
REG_FLD_MOD(dsidev, DSI_CLK_CTRL, 0, 14, 14);
}
static int dsi_pll_power(struct platform_device *dsidev,
enum dsi_pll_power_state state)
{
int t = 0;
if (dss_has_feature(FEAT_DSI_PLL_PWR_BUG) &&
state == DSI_PLL_POWER_ON_DIV)
state = DSI_PLL_POWER_ON_ALL;
REG_FLD_MOD(dsidev, DSI_CLK_CTRL, state, 31, 30);
while (FLD_GET(dsi_read_reg(dsidev, DSI_CLK_CTRL), 29, 28) != state) {
if (++t > 1000) {
DSSERR("Failed to set DSI PLL power mode to %d\n",
state);
return -ENODEV;
}
udelay(1);
}
return 0;
}
static void dsi_pll_calc_dsi_fck(struct dss_pll_clock_info *cinfo)
{
unsigned long max_dsi_fck;
max_dsi_fck = dss_feat_get_param_max(FEAT_PARAM_DSI_FCK);
cinfo->mX[HSDIV_DSI] = DIV_ROUND_UP(cinfo->clkdco, max_dsi_fck);
cinfo->clkout[HSDIV_DSI] = cinfo->clkdco / cinfo->mX[HSDIV_DSI];
}
static int dsi_pll_enable(struct dss_pll *pll)
{
struct dsi_data *dsi = container_of(pll, struct dsi_data, pll);
struct platform_device *dsidev = dsi->pdev;
int r = 0;
DSSDBG("PLL init\n");
r = dsi_regulator_init(dsidev);
if (r)
return r;
r = dsi_runtime_get(dsidev);
if (r)
return r;
dsi_enable_scp_clk(dsidev);
if (!dsi->vdds_dsi_enabled) {
r = regulator_enable(dsi->vdds_dsi_reg);
if (r)
goto err0;
dsi->vdds_dsi_enabled = true;
}
dispc_pck_free_enable(1);
if (wait_for_bit_change(dsidev, DSI_PLL_STATUS, 0, 1) != 1) {
DSSERR("PLL not coming out of reset.\n");
r = -ENODEV;
dispc_pck_free_enable(0);
goto err1;
}
dispc_pck_free_enable(0);
r = dsi_pll_power(dsidev, DSI_PLL_POWER_ON_ALL);
if (r)
goto err1;
DSSDBG("PLL init done\n");
return 0;
err1:
if (dsi->vdds_dsi_enabled) {
regulator_disable(dsi->vdds_dsi_reg);
dsi->vdds_dsi_enabled = false;
}
err0:
dsi_disable_scp_clk(dsidev);
dsi_runtime_put(dsidev);
return r;
}
static void dsi_pll_uninit(struct platform_device *dsidev, bool disconnect_lanes)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
dsi_pll_power(dsidev, DSI_PLL_POWER_OFF);
if (disconnect_lanes) {
WARN_ON(!dsi->vdds_dsi_enabled);
regulator_disable(dsi->vdds_dsi_reg);
dsi->vdds_dsi_enabled = false;
}
dsi_disable_scp_clk(dsidev);
dsi_runtime_put(dsidev);
DSSDBG("PLL uninit done\n");
}
static void dsi_pll_disable(struct dss_pll *pll)
{
struct dsi_data *dsi = container_of(pll, struct dsi_data, pll);
struct platform_device *dsidev = dsi->pdev;
dsi_pll_uninit(dsidev, true);
}
static void dsi_dump_dsidev_clocks(struct platform_device *dsidev,
struct seq_file *s)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct dss_pll_clock_info *cinfo = &dsi->pll.cinfo;
enum omap_dss_clk_source dispc_clk_src, dsi_clk_src;
int dsi_module = dsi->module_id;
struct dss_pll *pll = &dsi->pll;
dispc_clk_src = dss_get_dispc_clk_source();
dsi_clk_src = dss_get_dsi_clk_source(dsi_module);
if (dsi_runtime_get(dsidev))
return;
seq_printf(s, "- DSI%d PLL -\n", dsi_module + 1);
seq_printf(s, "dsi pll clkin\t%lu\n", clk_get_rate(pll->clkin));
seq_printf(s, "Fint\t\t%-16lun %u\n", cinfo->fint, cinfo->n);
seq_printf(s, "CLKIN4DDR\t%-16lum %u\n",
cinfo->clkdco, cinfo->m);
seq_printf(s, "DSI_PLL_HSDIV_DISPC (%s)\t%-16lum_dispc %u\t(%s)\n",
dss_feat_get_clk_source_name(dsi_module == 0 ?
OMAP_DSS_CLK_SRC_DSI_PLL_HSDIV_DISPC :
OMAP_DSS_CLK_SRC_DSI2_PLL_HSDIV_DISPC),
cinfo->clkout[HSDIV_DISPC],
cinfo->mX[HSDIV_DISPC],
dispc_clk_src == OMAP_DSS_CLK_SRC_FCK ?
"off" : "on");
seq_printf(s, "DSI_PLL_HSDIV_DSI (%s)\t%-16lum_dsi %u\t(%s)\n",
dss_feat_get_clk_source_name(dsi_module == 0 ?
OMAP_DSS_CLK_SRC_DSI_PLL_HSDIV_DSI :
OMAP_DSS_CLK_SRC_DSI2_PLL_HSDIV_DSI),
cinfo->clkout[HSDIV_DSI],
cinfo->mX[HSDIV_DSI],
dsi_clk_src == OMAP_DSS_CLK_SRC_FCK ?
"off" : "on");
seq_printf(s, "- DSI%d -\n", dsi_module + 1);
seq_printf(s, "dsi fclk source = %s (%s)\n",
dss_get_generic_clk_source_name(dsi_clk_src),
dss_feat_get_clk_source_name(dsi_clk_src));
seq_printf(s, "DSI_FCLK\t%lu\n", dsi_fclk_rate(dsidev));
seq_printf(s, "DDR_CLK\t\t%lu\n",
cinfo->clkdco / 4);
seq_printf(s, "TxByteClkHS\t%lu\n", dsi_get_txbyteclkhs(dsidev));
seq_printf(s, "LP_CLK\t\t%lu\n", dsi->current_lp_cinfo.lp_clk);
dsi_runtime_put(dsidev);
}
void dsi_dump_clocks(struct seq_file *s)
{
struct platform_device *dsidev;
int i;
for (i = 0; i < MAX_NUM_DSI; i++) {
dsidev = dsi_get_dsidev_from_id(i);
if (dsidev)
dsi_dump_dsidev_clocks(dsidev, s);
}
}
static void dsi_dump_dsidev_irqs(struct platform_device *dsidev,
struct seq_file *s)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
unsigned long flags;
struct dsi_irq_stats stats;
spin_lock_irqsave(&dsi->irq_stats_lock, flags);
stats = dsi->irq_stats;
memset(&dsi->irq_stats, 0, sizeof(dsi->irq_stats));
dsi->irq_stats.last_reset = jiffies;
spin_unlock_irqrestore(&dsi->irq_stats_lock, flags);
seq_printf(s, "period %u ms\n",
jiffies_to_msecs(jiffies - stats.last_reset));
seq_printf(s, "irqs %d\n", stats.irq_count);
#define PIS(x) \
seq_printf(s, "%-20s %10d\n", #x, stats.dsi_irqs[ffs(DSI_IRQ_##x)-1]);
seq_printf(s, "-- DSI%d interrupts --\n", dsi->module_id + 1);
PIS(VC0);
PIS(VC1);
PIS(VC2);
PIS(VC3);
PIS(WAKEUP);
PIS(RESYNC);
PIS(PLL_LOCK);
PIS(PLL_UNLOCK);
PIS(PLL_RECALL);
PIS(COMPLEXIO_ERR);
PIS(HS_TX_TIMEOUT);
PIS(LP_RX_TIMEOUT);
PIS(TE_TRIGGER);
PIS(ACK_TRIGGER);
PIS(SYNC_LOST);
PIS(LDO_POWER_GOOD);
PIS(TA_TIMEOUT);
#undef PIS
#define PIS(x) \
seq_printf(s, "%-20s %10d %10d %10d %10d\n", #x, \
stats.vc_irqs[0][ffs(DSI_VC_IRQ_##x)-1], \
stats.vc_irqs[1][ffs(DSI_VC_IRQ_##x)-1], \
stats.vc_irqs[2][ffs(DSI_VC_IRQ_##x)-1], \
stats.vc_irqs[3][ffs(DSI_VC_IRQ_##x)-1]);
seq_printf(s, "-- VC interrupts --\n");
PIS(CS);
PIS(ECC_CORR);
PIS(PACKET_SENT);
PIS(FIFO_TX_OVF);
PIS(FIFO_RX_OVF);
PIS(BTA);
PIS(ECC_NO_CORR);
PIS(FIFO_TX_UDF);
PIS(PP_BUSY_CHANGE);
#undef PIS
#define PIS(x) \
seq_printf(s, "%-20s %10d\n", #x, \
stats.cio_irqs[ffs(DSI_CIO_IRQ_##x)-1]);
seq_printf(s, "-- CIO interrupts --\n");
PIS(ERRSYNCESC1);
PIS(ERRSYNCESC2);
PIS(ERRSYNCESC3);
PIS(ERRESC1);
PIS(ERRESC2);
PIS(ERRESC3);
PIS(ERRCONTROL1);
PIS(ERRCONTROL2);
PIS(ERRCONTROL3);
PIS(STATEULPS1);
PIS(STATEULPS2);
PIS(STATEULPS3);
PIS(ERRCONTENTIONLP0_1);
PIS(ERRCONTENTIONLP1_1);
PIS(ERRCONTENTIONLP0_2);
PIS(ERRCONTENTIONLP1_2);
PIS(ERRCONTENTIONLP0_3);
PIS(ERRCONTENTIONLP1_3);
PIS(ULPSACTIVENOT_ALL0);
PIS(ULPSACTIVENOT_ALL1);
#undef PIS
}
static void dsi1_dump_irqs(struct seq_file *s)
{
struct platform_device *dsidev = dsi_get_dsidev_from_id(0);
dsi_dump_dsidev_irqs(dsidev, s);
}
static void dsi2_dump_irqs(struct seq_file *s)
{
struct platform_device *dsidev = dsi_get_dsidev_from_id(1);
dsi_dump_dsidev_irqs(dsidev, s);
}
static void dsi_dump_dsidev_regs(struct platform_device *dsidev,
struct seq_file *s)
{
#define DUMPREG(r) seq_printf(s, "%-35s %08x\n", #r, dsi_read_reg(dsidev, r))
if (dsi_runtime_get(dsidev))
return;
dsi_enable_scp_clk(dsidev);
DUMPREG(DSI_REVISION);
DUMPREG(DSI_SYSCONFIG);
DUMPREG(DSI_SYSSTATUS);
DUMPREG(DSI_IRQSTATUS);
DUMPREG(DSI_IRQENABLE);
DUMPREG(DSI_CTRL);
DUMPREG(DSI_COMPLEXIO_CFG1);
DUMPREG(DSI_COMPLEXIO_IRQ_STATUS);
DUMPREG(DSI_COMPLEXIO_IRQ_ENABLE);
DUMPREG(DSI_CLK_CTRL);
DUMPREG(DSI_TIMING1);
DUMPREG(DSI_TIMING2);
DUMPREG(DSI_VM_TIMING1);
DUMPREG(DSI_VM_TIMING2);
DUMPREG(DSI_VM_TIMING3);
DUMPREG(DSI_CLK_TIMING);
DUMPREG(DSI_TX_FIFO_VC_SIZE);
DUMPREG(DSI_RX_FIFO_VC_SIZE);
DUMPREG(DSI_COMPLEXIO_CFG2);
DUMPREG(DSI_RX_FIFO_VC_FULLNESS);
DUMPREG(DSI_VM_TIMING4);
DUMPREG(DSI_TX_FIFO_VC_EMPTINESS);
DUMPREG(DSI_VM_TIMING5);
DUMPREG(DSI_VM_TIMING6);
DUMPREG(DSI_VM_TIMING7);
DUMPREG(DSI_STOPCLK_TIMING);
DUMPREG(DSI_VC_CTRL(0));
DUMPREG(DSI_VC_TE(0));
DUMPREG(DSI_VC_LONG_PACKET_HEADER(0));
DUMPREG(DSI_VC_LONG_PACKET_PAYLOAD(0));
DUMPREG(DSI_VC_SHORT_PACKET_HEADER(0));
DUMPREG(DSI_VC_IRQSTATUS(0));
DUMPREG(DSI_VC_IRQENABLE(0));
DUMPREG(DSI_VC_CTRL(1));
DUMPREG(DSI_VC_TE(1));
DUMPREG(DSI_VC_LONG_PACKET_HEADER(1));
DUMPREG(DSI_VC_LONG_PACKET_PAYLOAD(1));
DUMPREG(DSI_VC_SHORT_PACKET_HEADER(1));
DUMPREG(DSI_VC_IRQSTATUS(1));
DUMPREG(DSI_VC_IRQENABLE(1));
DUMPREG(DSI_VC_CTRL(2));
DUMPREG(DSI_VC_TE(2));
DUMPREG(DSI_VC_LONG_PACKET_HEADER(2));
DUMPREG(DSI_VC_LONG_PACKET_PAYLOAD(2));
DUMPREG(DSI_VC_SHORT_PACKET_HEADER(2));
DUMPREG(DSI_VC_IRQSTATUS(2));
DUMPREG(DSI_VC_IRQENABLE(2));
DUMPREG(DSI_VC_CTRL(3));
DUMPREG(DSI_VC_TE(3));
DUMPREG(DSI_VC_LONG_PACKET_HEADER(3));
DUMPREG(DSI_VC_LONG_PACKET_PAYLOAD(3));
DUMPREG(DSI_VC_SHORT_PACKET_HEADER(3));
DUMPREG(DSI_VC_IRQSTATUS(3));
DUMPREG(DSI_VC_IRQENABLE(3));
DUMPREG(DSI_DSIPHY_CFG0);
DUMPREG(DSI_DSIPHY_CFG1);
DUMPREG(DSI_DSIPHY_CFG2);
DUMPREG(DSI_DSIPHY_CFG5);
DUMPREG(DSI_PLL_CONTROL);
DUMPREG(DSI_PLL_STATUS);
DUMPREG(DSI_PLL_GO);
DUMPREG(DSI_PLL_CONFIGURATION1);
DUMPREG(DSI_PLL_CONFIGURATION2);
dsi_disable_scp_clk(dsidev);
dsi_runtime_put(dsidev);
#undef DUMPREG
}
static void dsi1_dump_regs(struct seq_file *s)
{
struct platform_device *dsidev = dsi_get_dsidev_from_id(0);
dsi_dump_dsidev_regs(dsidev, s);
}
static void dsi2_dump_regs(struct seq_file *s)
{
struct platform_device *dsidev = dsi_get_dsidev_from_id(1);
dsi_dump_dsidev_regs(dsidev, s);
}
static int dsi_cio_power(struct platform_device *dsidev,
enum dsi_cio_power_state state)
{
int t = 0;
REG_FLD_MOD(dsidev, DSI_COMPLEXIO_CFG1, state, 28, 27);
while (FLD_GET(dsi_read_reg(dsidev, DSI_COMPLEXIO_CFG1),
26, 25) != state) {
if (++t > 1000) {
DSSERR("failed to set complexio power state to "
"%d\n", state);
return -ENODEV;
}
udelay(1);
}
return 0;
}
static unsigned dsi_get_line_buf_size(struct platform_device *dsidev)
{
int val;
if (!dss_has_feature(FEAT_DSI_GNQ))
return 1023 * 3;
val = REG_GET(dsidev, DSI_GNQ, 14, 12);
switch (val) {
case 1:
return 512 * 3;
case 2:
return 682 * 3;
case 3:
return 853 * 3;
case 4:
return 1024 * 3;
case 5:
return 1194 * 3;
case 6:
return 1365 * 3;
case 7:
return 1920 * 3;
default:
BUG();
return 0;
}
}
static int dsi_set_lane_config(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
static const u8 offsets[] = { 0, 4, 8, 12, 16 };
static const enum dsi_lane_function functions[] = {
DSI_LANE_CLK,
DSI_LANE_DATA1,
DSI_LANE_DATA2,
DSI_LANE_DATA3,
DSI_LANE_DATA4,
};
u32 r;
int i;
r = dsi_read_reg(dsidev, DSI_COMPLEXIO_CFG1);
for (i = 0; i < dsi->num_lanes_used; ++i) {
unsigned offset = offsets[i];
unsigned polarity, lane_number;
unsigned t;
for (t = 0; t < dsi->num_lanes_supported; ++t)
if (dsi->lanes[t].function == functions[i])
break;
if (t == dsi->num_lanes_supported)
return -EINVAL;
lane_number = t;
polarity = dsi->lanes[t].polarity;
r = FLD_MOD(r, lane_number + 1, offset + 2, offset);
r = FLD_MOD(r, polarity, offset + 3, offset + 3);
}
for (; i < dsi->num_lanes_supported; ++i) {
unsigned offset = offsets[i];
r = FLD_MOD(r, 0, offset + 2, offset);
r = FLD_MOD(r, 0, offset + 3, offset + 3);
}
dsi_write_reg(dsidev, DSI_COMPLEXIO_CFG1, r);
return 0;
}
static inline unsigned ns2ddr(struct platform_device *dsidev, unsigned ns)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
unsigned long ddr_clk = dsi->pll.cinfo.clkdco / 4;
return (ns * (ddr_clk / 1000 / 1000) + 999) / 1000;
}
static inline unsigned ddr2ns(struct platform_device *dsidev, unsigned ddr)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
unsigned long ddr_clk = dsi->pll.cinfo.clkdco / 4;
return ddr * 1000 * 1000 / (ddr_clk / 1000);
}
static void dsi_cio_timings(struct platform_device *dsidev)
{
u32 r;
u32 ths_prepare, ths_prepare_ths_zero, ths_trail, ths_exit;
u32 tlpx_half, tclk_trail, tclk_zero;
u32 tclk_prepare;
ths_prepare = ns2ddr(dsidev, 70) + 2;
ths_prepare_ths_zero = ns2ddr(dsidev, 175) + 2;
ths_trail = ns2ddr(dsidev, 60) + 5;
ths_exit = ns2ddr(dsidev, 145);
tlpx_half = ns2ddr(dsidev, 25);
tclk_trail = ns2ddr(dsidev, 60) + 2;
tclk_prepare = ns2ddr(dsidev, 65);
tclk_zero = ns2ddr(dsidev, 260);
DSSDBG("ths_prepare %u (%uns), ths_prepare_ths_zero %u (%uns)\n",
ths_prepare, ddr2ns(dsidev, ths_prepare),
ths_prepare_ths_zero, ddr2ns(dsidev, ths_prepare_ths_zero));
DSSDBG("ths_trail %u (%uns), ths_exit %u (%uns)\n",
ths_trail, ddr2ns(dsidev, ths_trail),
ths_exit, ddr2ns(dsidev, ths_exit));
DSSDBG("tlpx_half %u (%uns), tclk_trail %u (%uns), "
"tclk_zero %u (%uns)\n",
tlpx_half, ddr2ns(dsidev, tlpx_half),
tclk_trail, ddr2ns(dsidev, tclk_trail),
tclk_zero, ddr2ns(dsidev, tclk_zero));
DSSDBG("tclk_prepare %u (%uns)\n",
tclk_prepare, ddr2ns(dsidev, tclk_prepare));
r = dsi_read_reg(dsidev, DSI_DSIPHY_CFG0);
r = FLD_MOD(r, ths_prepare, 31, 24);
r = FLD_MOD(r, ths_prepare_ths_zero, 23, 16);
r = FLD_MOD(r, ths_trail, 15, 8);
r = FLD_MOD(r, ths_exit, 7, 0);
dsi_write_reg(dsidev, DSI_DSIPHY_CFG0, r);
r = dsi_read_reg(dsidev, DSI_DSIPHY_CFG1);
r = FLD_MOD(r, tlpx_half, 20, 16);
r = FLD_MOD(r, tclk_trail, 15, 8);
r = FLD_MOD(r, tclk_zero, 7, 0);
if (dss_has_feature(FEAT_DSI_PHY_DCC)) {
r = FLD_MOD(r, 0, 21, 21);
r = FLD_MOD(r, 1, 22, 22);
r = FLD_MOD(r, 1, 23, 23);
}
dsi_write_reg(dsidev, DSI_DSIPHY_CFG1, r);
r = dsi_read_reg(dsidev, DSI_DSIPHY_CFG2);
r = FLD_MOD(r, tclk_prepare, 7, 0);
dsi_write_reg(dsidev, DSI_DSIPHY_CFG2, r);
}
static void dsi_cio_enable_lane_override(struct platform_device *dsidev,
unsigned mask_p, unsigned mask_n)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int i;
u32 l;
u8 lptxscp_start = dsi->num_lanes_supported == 3 ? 22 : 26;
l = 0;
for (i = 0; i < dsi->num_lanes_supported; ++i) {
unsigned p = dsi->lanes[i].polarity;
if (mask_p & (1 << i))
l |= 1 << (i * 2 + (p ? 0 : 1));
if (mask_n & (1 << i))
l |= 1 << (i * 2 + (p ? 1 : 0));
}
REG_FLD_MOD(dsidev, DSI_DSIPHY_CFG10, l, lptxscp_start, 17);
REG_FLD_MOD(dsidev, DSI_DSIPHY_CFG10, 1, 27, 27);
}
static void dsi_cio_disable_lane_override(struct platform_device *dsidev)
{
REG_FLD_MOD(dsidev, DSI_DSIPHY_CFG10, 0, 27, 27);
REG_FLD_MOD(dsidev, DSI_DSIPHY_CFG10, 0, 22, 17);
}
static int dsi_cio_wait_tx_clk_esc_reset(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int t, i;
bool in_use[DSI_MAX_NR_LANES];
static const u8 offsets_old[] = { 28, 27, 26 };
static const u8 offsets_new[] = { 24, 25, 26, 27, 28 };
const u8 *offsets;
if (dss_has_feature(FEAT_DSI_REVERSE_TXCLKESC))
offsets = offsets_old;
else
offsets = offsets_new;
for (i = 0; i < dsi->num_lanes_supported; ++i)
in_use[i] = dsi->lanes[i].function != DSI_LANE_UNUSED;
t = 100000;
while (true) {
u32 l;
int ok;
l = dsi_read_reg(dsidev, DSI_DSIPHY_CFG5);
ok = 0;
for (i = 0; i < dsi->num_lanes_supported; ++i) {
if (!in_use[i] || (l & (1 << offsets[i])))
ok++;
}
if (ok == dsi->num_lanes_supported)
break;
if (--t == 0) {
for (i = 0; i < dsi->num_lanes_supported; ++i) {
if (!in_use[i] || (l & (1 << offsets[i])))
continue;
DSSERR("CIO TXCLKESC%d domain not coming " \
"out of reset\n", i);
}
return -EIO;
}
}
return 0;
}
static unsigned dsi_get_lane_mask(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
unsigned mask = 0;
int i;
for (i = 0; i < dsi->num_lanes_supported; ++i) {
if (dsi->lanes[i].function != DSI_LANE_UNUSED)
mask |= 1 << i;
}
return mask;
}
static int dsi_cio_init(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int r;
u32 l;
DSSDBG("DSI CIO init starts");
r = dss_dsi_enable_pads(dsi->module_id, dsi_get_lane_mask(dsidev));
if (r)
return r;
dsi_enable_scp_clk(dsidev);
dsi_read_reg(dsidev, DSI_DSIPHY_CFG5);
if (wait_for_bit_change(dsidev, DSI_DSIPHY_CFG5, 30, 1) != 1) {
DSSERR("CIO SCP Clock domain not coming out of reset.\n");
r = -EIO;
goto err_scp_clk_dom;
}
r = dsi_set_lane_config(dsidev);
if (r)
goto err_scp_clk_dom;
l = dsi_read_reg(dsidev, DSI_TIMING1);
l = FLD_MOD(l, 1, 15, 15);
l = FLD_MOD(l, 1, 14, 14);
l = FLD_MOD(l, 1, 13, 13);
l = FLD_MOD(l, 0x1fff, 12, 0);
dsi_write_reg(dsidev, DSI_TIMING1, l);
if (dsi->ulps_enabled) {
unsigned mask_p;
int i;
DSSDBG("manual ulps exit\n");
mask_p = 0;
for (i = 0; i < dsi->num_lanes_supported; ++i) {
if (dsi->lanes[i].function == DSI_LANE_UNUSED)
continue;
mask_p |= 1 << i;
}
dsi_cio_enable_lane_override(dsidev, mask_p, 0);
}
r = dsi_cio_power(dsidev, DSI_COMPLEXIO_POWER_ON);
if (r)
goto err_cio_pwr;
if (wait_for_bit_change(dsidev, DSI_COMPLEXIO_CFG1, 29, 1) != 1) {
DSSERR("CIO PWR clock domain not coming out of reset.\n");
r = -ENODEV;
goto err_cio_pwr_dom;
}
dsi_if_enable(dsidev, true);
dsi_if_enable(dsidev, false);
REG_FLD_MOD(dsidev, DSI_CLK_CTRL, 1, 20, 20);
r = dsi_cio_wait_tx_clk_esc_reset(dsidev);
if (r)
goto err_tx_clk_esc_rst;
if (dsi->ulps_enabled) {
ktime_t wait = ns_to_ktime(1000 * 1000);
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_hrtimeout(&wait, HRTIMER_MODE_REL);
dsi_cio_disable_lane_override(dsidev);
}
REG_FLD_MOD(dsidev, DSI_TIMING1, 0, 15, 15);
dsi_cio_timings(dsidev);
if (dsi->mode == OMAP_DSS_DSI_VIDEO_MODE) {
REG_FLD_MOD(dsidev, DSI_CLK_CTRL,
dsi->vm_timings.ddr_clk_always_on, 13, 13);
}
dsi->ulps_enabled = false;
DSSDBG("CIO init done\n");
return 0;
err_tx_clk_esc_rst:
REG_FLD_MOD(dsidev, DSI_CLK_CTRL, 0, 20, 20);
err_cio_pwr_dom:
dsi_cio_power(dsidev, DSI_COMPLEXIO_POWER_OFF);
err_cio_pwr:
if (dsi->ulps_enabled)
dsi_cio_disable_lane_override(dsidev);
err_scp_clk_dom:
dsi_disable_scp_clk(dsidev);
dss_dsi_disable_pads(dsi->module_id, dsi_get_lane_mask(dsidev));
return r;
}
static void dsi_cio_uninit(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
REG_FLD_MOD(dsidev, DSI_CLK_CTRL, 0, 13, 13);
dsi_cio_power(dsidev, DSI_COMPLEXIO_POWER_OFF);
dsi_disable_scp_clk(dsidev);
dss_dsi_disable_pads(dsi->module_id, dsi_get_lane_mask(dsidev));
}
static void dsi_config_tx_fifo(struct platform_device *dsidev,
enum fifo_size size1, enum fifo_size size2,
enum fifo_size size3, enum fifo_size size4)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
u32 r = 0;
int add = 0;
int i;
dsi->vc[0].tx_fifo_size = size1;
dsi->vc[1].tx_fifo_size = size2;
dsi->vc[2].tx_fifo_size = size3;
dsi->vc[3].tx_fifo_size = size4;
for (i = 0; i < 4; i++) {
u8 v;
int size = dsi->vc[i].tx_fifo_size;
if (add + size > 4) {
DSSERR("Illegal FIFO configuration\n");
BUG();
return;
}
v = FLD_VAL(add, 2, 0) | FLD_VAL(size, 7, 4);
r |= v << (8 * i);
add += size;
}
dsi_write_reg(dsidev, DSI_TX_FIFO_VC_SIZE, r);
}
static void dsi_config_rx_fifo(struct platform_device *dsidev,
enum fifo_size size1, enum fifo_size size2,
enum fifo_size size3, enum fifo_size size4)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
u32 r = 0;
int add = 0;
int i;
dsi->vc[0].rx_fifo_size = size1;
dsi->vc[1].rx_fifo_size = size2;
dsi->vc[2].rx_fifo_size = size3;
dsi->vc[3].rx_fifo_size = size4;
for (i = 0; i < 4; i++) {
u8 v;
int size = dsi->vc[i].rx_fifo_size;
if (add + size > 4) {
DSSERR("Illegal FIFO configuration\n");
BUG();
return;
}
v = FLD_VAL(add, 2, 0) | FLD_VAL(size, 7, 4);
r |= v << (8 * i);
add += size;
}
dsi_write_reg(dsidev, DSI_RX_FIFO_VC_SIZE, r);
}
static int dsi_force_tx_stop_mode_io(struct platform_device *dsidev)
{
u32 r;
r = dsi_read_reg(dsidev, DSI_TIMING1);
r = FLD_MOD(r, 1, 15, 15);
dsi_write_reg(dsidev, DSI_TIMING1, r);
if (wait_for_bit_change(dsidev, DSI_TIMING1, 15, 0) != 0) {
DSSERR("TX_STOP bit not going down\n");
return -EIO;
}
return 0;
}
static bool dsi_vc_is_enabled(struct platform_device *dsidev, int channel)
{
return REG_GET(dsidev, DSI_VC_CTRL(channel), 0, 0);
}
static void dsi_packet_sent_handler_vp(void *data, u32 mask)
{
struct dsi_packet_sent_handler_data *vp_data =
(struct dsi_packet_sent_handler_data *) data;
struct dsi_data *dsi = dsi_get_dsidrv_data(vp_data->dsidev);
const int channel = dsi->update_channel;
u8 bit = dsi->te_enabled ? 30 : 31;
if (REG_GET(vp_data->dsidev, DSI_VC_TE(channel), bit, bit) == 0)
complete(vp_data->completion);
}
static int dsi_sync_vc_vp(struct platform_device *dsidev, int channel)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
DECLARE_COMPLETION_ONSTACK(completion);
struct dsi_packet_sent_handler_data vp_data = {
.dsidev = dsidev,
.completion = &completion
};
int r = 0;
u8 bit;
bit = dsi->te_enabled ? 30 : 31;
r = dsi_register_isr_vc(dsidev, channel, dsi_packet_sent_handler_vp,
&vp_data, DSI_VC_IRQ_PACKET_SENT);
if (r)
goto err0;
if (REG_GET(dsidev, DSI_VC_TE(channel), bit, bit)) {
if (wait_for_completion_timeout(&completion,
msecs_to_jiffies(10)) == 0) {
DSSERR("Failed to complete previous frame transfer\n");
r = -EIO;
goto err1;
}
}
dsi_unregister_isr_vc(dsidev, channel, dsi_packet_sent_handler_vp,
&vp_data, DSI_VC_IRQ_PACKET_SENT);
return 0;
err1:
dsi_unregister_isr_vc(dsidev, channel, dsi_packet_sent_handler_vp,
&vp_data, DSI_VC_IRQ_PACKET_SENT);
err0:
return r;
}
static void dsi_packet_sent_handler_l4(void *data, u32 mask)
{
struct dsi_packet_sent_handler_data *l4_data =
(struct dsi_packet_sent_handler_data *) data;
struct dsi_data *dsi = dsi_get_dsidrv_data(l4_data->dsidev);
const int channel = dsi->update_channel;
if (REG_GET(l4_data->dsidev, DSI_VC_CTRL(channel), 5, 5) == 0)
complete(l4_data->completion);
}
static int dsi_sync_vc_l4(struct platform_device *dsidev, int channel)
{
DECLARE_COMPLETION_ONSTACK(completion);
struct dsi_packet_sent_handler_data l4_data = {
.dsidev = dsidev,
.completion = &completion
};
int r = 0;
r = dsi_register_isr_vc(dsidev, channel, dsi_packet_sent_handler_l4,
&l4_data, DSI_VC_IRQ_PACKET_SENT);
if (r)
goto err0;
if (REG_GET(dsidev, DSI_VC_CTRL(channel), 5, 5)) {
if (wait_for_completion_timeout(&completion,
msecs_to_jiffies(10)) == 0) {
DSSERR("Failed to complete previous l4 transfer\n");
r = -EIO;
goto err1;
}
}
dsi_unregister_isr_vc(dsidev, channel, dsi_packet_sent_handler_l4,
&l4_data, DSI_VC_IRQ_PACKET_SENT);
return 0;
err1:
dsi_unregister_isr_vc(dsidev, channel, dsi_packet_sent_handler_l4,
&l4_data, DSI_VC_IRQ_PACKET_SENT);
err0:
return r;
}
static int dsi_sync_vc(struct platform_device *dsidev, int channel)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
WARN_ON(!dsi_bus_is_locked(dsidev));
WARN_ON(in_interrupt());
if (!dsi_vc_is_enabled(dsidev, channel))
return 0;
switch (dsi->vc[channel].source) {
case DSI_VC_SOURCE_VP:
return dsi_sync_vc_vp(dsidev, channel);
case DSI_VC_SOURCE_L4:
return dsi_sync_vc_l4(dsidev, channel);
default:
BUG();
return -EINVAL;
}
}
static int dsi_vc_enable(struct platform_device *dsidev, int channel,
bool enable)
{
DSSDBG("dsi_vc_enable channel %d, enable %d\n",
channel, enable);
enable = enable ? 1 : 0;
REG_FLD_MOD(dsidev, DSI_VC_CTRL(channel), enable, 0, 0);
if (wait_for_bit_change(dsidev, DSI_VC_CTRL(channel),
0, enable) != enable) {
DSSERR("Failed to set dsi_vc_enable to %d\n", enable);
return -EIO;
}
return 0;
}
static void dsi_vc_initial_config(struct platform_device *dsidev, int channel)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
u32 r;
DSSDBG("Initial config of virtual channel %d", channel);
r = dsi_read_reg(dsidev, DSI_VC_CTRL(channel));
if (FLD_GET(r, 15, 15))
DSSERR("VC(%d) busy when trying to configure it!\n",
channel);
r = FLD_MOD(r, 0, 1, 1);
r = FLD_MOD(r, 0, 2, 2);
r = FLD_MOD(r, 0, 3, 3);
r = FLD_MOD(r, 0, 4, 4);
r = FLD_MOD(r, 1, 7, 7);
r = FLD_MOD(r, 1, 8, 8);
r = FLD_MOD(r, 0, 9, 9);
if (dss_has_feature(FEAT_DSI_VC_OCP_WIDTH))
r = FLD_MOD(r, 3, 11, 10);
r = FLD_MOD(r, 4, 29, 27);
r = FLD_MOD(r, 4, 23, 21);
dsi_write_reg(dsidev, DSI_VC_CTRL(channel), r);
dsi->vc[channel].source = DSI_VC_SOURCE_L4;
}
static int dsi_vc_config_source(struct platform_device *dsidev, int channel,
enum dsi_vc_source source)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
if (dsi->vc[channel].source == source)
return 0;
DSSDBG("Source config of virtual channel %d", channel);
dsi_sync_vc(dsidev, channel);
dsi_vc_enable(dsidev, channel, 0);
if (wait_for_bit_change(dsidev, DSI_VC_CTRL(channel), 15, 0) != 0) {
DSSERR("vc(%d) busy when trying to config for VP\n", channel);
return -EIO;
}
REG_FLD_MOD(dsidev, DSI_VC_CTRL(channel), source, 1, 1);
if (dss_has_feature(FEAT_DSI_DCS_CMD_CONFIG_VC)) {
bool enable = source == DSI_VC_SOURCE_VP;
REG_FLD_MOD(dsidev, DSI_VC_CTRL(channel), enable, 30, 30);
}
dsi_vc_enable(dsidev, channel, 1);
dsi->vc[channel].source = source;
return 0;
}
static void dsi_vc_enable_hs(struct omap_dss_device *dssdev, int channel,
bool enable)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
DSSDBG("dsi_vc_enable_hs(%d, %d)\n", channel, enable);
WARN_ON(!dsi_bus_is_locked(dsidev));
dsi_vc_enable(dsidev, channel, 0);
dsi_if_enable(dsidev, 0);
REG_FLD_MOD(dsidev, DSI_VC_CTRL(channel), enable, 9, 9);
dsi_vc_enable(dsidev, channel, 1);
dsi_if_enable(dsidev, 1);
dsi_force_tx_stop_mode_io(dsidev);
if (dsi->vm_timings.ddr_clk_always_on && enable)
dsi_vc_send_null(dssdev, channel);
}
static void dsi_vc_flush_long_data(struct platform_device *dsidev, int channel)
{
while (REG_GET(dsidev, DSI_VC_CTRL(channel), 20, 20)) {
u32 val;
val = dsi_read_reg(dsidev, DSI_VC_SHORT_PACKET_HEADER(channel));
DSSDBG("\t\tb1 %#02x b2 %#02x b3 %#02x b4 %#02x\n",
(val >> 0) & 0xff,
(val >> 8) & 0xff,
(val >> 16) & 0xff,
(val >> 24) & 0xff);
}
}
static void dsi_show_rx_ack_with_err(u16 err)
{
DSSERR("\tACK with ERROR (%#x):\n", err);
if (err & (1 << 0))
DSSERR("\t\tSoT Error\n");
if (err & (1 << 1))
DSSERR("\t\tSoT Sync Error\n");
if (err & (1 << 2))
DSSERR("\t\tEoT Sync Error\n");
if (err & (1 << 3))
DSSERR("\t\tEscape Mode Entry Command Error\n");
if (err & (1 << 4))
DSSERR("\t\tLP Transmit Sync Error\n");
if (err & (1 << 5))
DSSERR("\t\tHS Receive Timeout Error\n");
if (err & (1 << 6))
DSSERR("\t\tFalse Control Error\n");
if (err & (1 << 7))
DSSERR("\t\t(reserved7)\n");
if (err & (1 << 8))
DSSERR("\t\tECC Error, single-bit (corrected)\n");
if (err & (1 << 9))
DSSERR("\t\tECC Error, multi-bit (not corrected)\n");
if (err & (1 << 10))
DSSERR("\t\tChecksum Error\n");
if (err & (1 << 11))
DSSERR("\t\tData type not recognized\n");
if (err & (1 << 12))
DSSERR("\t\tInvalid VC ID\n");
if (err & (1 << 13))
DSSERR("\t\tInvalid Transmission Length\n");
if (err & (1 << 14))
DSSERR("\t\t(reserved14)\n");
if (err & (1 << 15))
DSSERR("\t\tDSI Protocol Violation\n");
}
static u16 dsi_vc_flush_receive_data(struct platform_device *dsidev,
int channel)
{
while (REG_GET(dsidev, DSI_VC_CTRL(channel), 20, 20)) {
u32 val;
u8 dt;
val = dsi_read_reg(dsidev, DSI_VC_SHORT_PACKET_HEADER(channel));
DSSERR("\trawval %#08x\n", val);
dt = FLD_GET(val, 5, 0);
if (dt == MIPI_DSI_RX_ACKNOWLEDGE_AND_ERROR_REPORT) {
u16 err = FLD_GET(val, 23, 8);
dsi_show_rx_ack_with_err(err);
} else if (dt == MIPI_DSI_RX_DCS_SHORT_READ_RESPONSE_1BYTE) {
DSSERR("\tDCS short response, 1 byte: %#x\n",
FLD_GET(val, 23, 8));
} else if (dt == MIPI_DSI_RX_DCS_SHORT_READ_RESPONSE_2BYTE) {
DSSERR("\tDCS short response, 2 byte: %#x\n",
FLD_GET(val, 23, 8));
} else if (dt == MIPI_DSI_RX_DCS_LONG_READ_RESPONSE) {
DSSERR("\tDCS long response, len %d\n",
FLD_GET(val, 23, 8));
dsi_vc_flush_long_data(dsidev, channel);
} else {
DSSERR("\tunknown datatype 0x%02x\n", dt);
}
}
return 0;
}
static int dsi_vc_send_bta(struct platform_device *dsidev, int channel)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
if (dsi->debug_write || dsi->debug_read)
DSSDBG("dsi_vc_send_bta %d\n", channel);
WARN_ON(!dsi_bus_is_locked(dsidev));
if (REG_GET(dsidev, DSI_VC_CTRL(channel), 20, 20)) {
DSSERR("rx fifo not empty when sending BTA, dumping data:\n");
dsi_vc_flush_receive_data(dsidev, channel);
}
REG_FLD_MOD(dsidev, DSI_VC_CTRL(channel), 1, 6, 6);
dsi_read_reg(dsidev, DSI_VC_CTRL(channel));
return 0;
}
static int dsi_vc_send_bta_sync(struct omap_dss_device *dssdev, int channel)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
DECLARE_COMPLETION_ONSTACK(completion);
int r = 0;
u32 err;
r = dsi_register_isr_vc(dsidev, channel, dsi_completion_handler,
&completion, DSI_VC_IRQ_BTA);
if (r)
goto err0;
r = dsi_register_isr(dsidev, dsi_completion_handler, &completion,
DSI_IRQ_ERROR_MASK);
if (r)
goto err1;
r = dsi_vc_send_bta(dsidev, channel);
if (r)
goto err2;
if (wait_for_completion_timeout(&completion,
msecs_to_jiffies(500)) == 0) {
DSSERR("Failed to receive BTA\n");
r = -EIO;
goto err2;
}
err = dsi_get_errors(dsidev);
if (err) {
DSSERR("Error while sending BTA: %x\n", err);
r = -EIO;
goto err2;
}
err2:
dsi_unregister_isr(dsidev, dsi_completion_handler, &completion,
DSI_IRQ_ERROR_MASK);
err1:
dsi_unregister_isr_vc(dsidev, channel, dsi_completion_handler,
&completion, DSI_VC_IRQ_BTA);
err0:
return r;
}
static inline void dsi_vc_write_long_header(struct platform_device *dsidev,
int channel, u8 data_type, u16 len, u8 ecc)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
u32 val;
u8 data_id;
WARN_ON(!dsi_bus_is_locked(dsidev));
data_id = data_type | dsi->vc[channel].vc_id << 6;
val = FLD_VAL(data_id, 7, 0) | FLD_VAL(len, 23, 8) |
FLD_VAL(ecc, 31, 24);
dsi_write_reg(dsidev, DSI_VC_LONG_PACKET_HEADER(channel), val);
}
static inline void dsi_vc_write_long_payload(struct platform_device *dsidev,
int channel, u8 b1, u8 b2, u8 b3, u8 b4)
{
u32 val;
val = b4 << 24 | b3 << 16 | b2 << 8 | b1 << 0;
dsi_write_reg(dsidev, DSI_VC_LONG_PACKET_PAYLOAD(channel), val);
}
static int dsi_vc_send_long(struct platform_device *dsidev, int channel,
u8 data_type, u8 *data, u16 len, u8 ecc)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int i;
u8 *p;
int r = 0;
u8 b1, b2, b3, b4;
if (dsi->debug_write)
DSSDBG("dsi_vc_send_long, %d bytes\n", len);
if (dsi->vc[channel].tx_fifo_size * 32 * 4 < len + 4) {
DSSERR("unable to send long packet: packet too long.\n");
return -EINVAL;
}
dsi_vc_config_source(dsidev, channel, DSI_VC_SOURCE_L4);
dsi_vc_write_long_header(dsidev, channel, data_type, len, ecc);
p = data;
for (i = 0; i < len >> 2; i++) {
if (dsi->debug_write)
DSSDBG("\tsending full packet %d\n", i);
b1 = *p++;
b2 = *p++;
b3 = *p++;
b4 = *p++;
dsi_vc_write_long_payload(dsidev, channel, b1, b2, b3, b4);
}
i = len % 4;
if (i) {
b1 = 0; b2 = 0; b3 = 0;
if (dsi->debug_write)
DSSDBG("\tsending remainder bytes %d\n", i);
switch (i) {
case 3:
b1 = *p++;
b2 = *p++;
b3 = *p++;
break;
case 2:
b1 = *p++;
b2 = *p++;
break;
case 1:
b1 = *p++;
break;
}
dsi_vc_write_long_payload(dsidev, channel, b1, b2, b3, 0);
}
return r;
}
static int dsi_vc_send_short(struct platform_device *dsidev, int channel,
u8 data_type, u16 data, u8 ecc)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
u32 r;
u8 data_id;
WARN_ON(!dsi_bus_is_locked(dsidev));
if (dsi->debug_write)
DSSDBG("dsi_vc_send_short(ch%d, dt %#x, b1 %#x, b2 %#x)\n",
channel,
data_type, data & 0xff, (data >> 8) & 0xff);
dsi_vc_config_source(dsidev, channel, DSI_VC_SOURCE_L4);
if (FLD_GET(dsi_read_reg(dsidev, DSI_VC_CTRL(channel)), 16, 16)) {
DSSERR("ERROR FIFO FULL, aborting transfer\n");
return -EINVAL;
}
data_id = data_type | dsi->vc[channel].vc_id << 6;
r = (data_id << 0) | (data << 8) | (ecc << 24);
dsi_write_reg(dsidev, DSI_VC_SHORT_PACKET_HEADER(channel), r);
return 0;
}
static int dsi_vc_send_null(struct omap_dss_device *dssdev, int channel)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
return dsi_vc_send_long(dsidev, channel, MIPI_DSI_NULL_PACKET, NULL,
0, 0);
}
static int dsi_vc_write_nosync_common(struct platform_device *dsidev,
int channel, u8 *data, int len, enum dss_dsi_content_type type)
{
int r;
if (len == 0) {
BUG_ON(type == DSS_DSI_CONTENT_DCS);
r = dsi_vc_send_short(dsidev, channel,
MIPI_DSI_GENERIC_SHORT_WRITE_0_PARAM, 0, 0);
} else if (len == 1) {
r = dsi_vc_send_short(dsidev, channel,
type == DSS_DSI_CONTENT_GENERIC ?
MIPI_DSI_GENERIC_SHORT_WRITE_1_PARAM :
MIPI_DSI_DCS_SHORT_WRITE, data[0], 0);
} else if (len == 2) {
r = dsi_vc_send_short(dsidev, channel,
type == DSS_DSI_CONTENT_GENERIC ?
MIPI_DSI_GENERIC_SHORT_WRITE_2_PARAM :
MIPI_DSI_DCS_SHORT_WRITE_PARAM,
data[0] | (data[1] << 8), 0);
} else {
r = dsi_vc_send_long(dsidev, channel,
type == DSS_DSI_CONTENT_GENERIC ?
MIPI_DSI_GENERIC_LONG_WRITE :
MIPI_DSI_DCS_LONG_WRITE, data, len, 0);
}
return r;
}
static int dsi_vc_dcs_write_nosync(struct omap_dss_device *dssdev, int channel,
u8 *data, int len)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
return dsi_vc_write_nosync_common(dsidev, channel, data, len,
DSS_DSI_CONTENT_DCS);
}
static int dsi_vc_generic_write_nosync(struct omap_dss_device *dssdev, int channel,
u8 *data, int len)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
return dsi_vc_write_nosync_common(dsidev, channel, data, len,
DSS_DSI_CONTENT_GENERIC);
}
static int dsi_vc_write_common(struct omap_dss_device *dssdev, int channel,
u8 *data, int len, enum dss_dsi_content_type type)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
int r;
r = dsi_vc_write_nosync_common(dsidev, channel, data, len, type);
if (r)
goto err;
r = dsi_vc_send_bta_sync(dssdev, channel);
if (r)
goto err;
if (REG_GET(dsidev, DSI_VC_CTRL(channel), 20, 20)) {
DSSERR("rx fifo not empty after write, dumping data:\n");
dsi_vc_flush_receive_data(dsidev, channel);
r = -EIO;
goto err;
}
return 0;
err:
DSSERR("dsi_vc_write_common(ch %d, cmd 0x%02x, len %d) failed\n",
channel, data[0], len);
return r;
}
static int dsi_vc_dcs_write(struct omap_dss_device *dssdev, int channel, u8 *data,
int len)
{
return dsi_vc_write_common(dssdev, channel, data, len,
DSS_DSI_CONTENT_DCS);
}
static int dsi_vc_generic_write(struct omap_dss_device *dssdev, int channel, u8 *data,
int len)
{
return dsi_vc_write_common(dssdev, channel, data, len,
DSS_DSI_CONTENT_GENERIC);
}
static int dsi_vc_dcs_send_read_request(struct platform_device *dsidev,
int channel, u8 dcs_cmd)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int r;
if (dsi->debug_read)
DSSDBG("dsi_vc_dcs_send_read_request(ch%d, dcs_cmd %x)\n",
channel, dcs_cmd);
r = dsi_vc_send_short(dsidev, channel, MIPI_DSI_DCS_READ, dcs_cmd, 0);
if (r) {
DSSERR("dsi_vc_dcs_send_read_request(ch %d, cmd 0x%02x)"
" failed\n", channel, dcs_cmd);
return r;
}
return 0;
}
static int dsi_vc_generic_send_read_request(struct platform_device *dsidev,
int channel, u8 *reqdata, int reqlen)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
u16 data;
u8 data_type;
int r;
if (dsi->debug_read)
DSSDBG("dsi_vc_generic_send_read_request(ch %d, reqlen %d)\n",
channel, reqlen);
if (reqlen == 0) {
data_type = MIPI_DSI_GENERIC_READ_REQUEST_0_PARAM;
data = 0;
} else if (reqlen == 1) {
data_type = MIPI_DSI_GENERIC_READ_REQUEST_1_PARAM;
data = reqdata[0];
} else if (reqlen == 2) {
data_type = MIPI_DSI_GENERIC_READ_REQUEST_2_PARAM;
data = reqdata[0] | (reqdata[1] << 8);
} else {
BUG();
return -EINVAL;
}
r = dsi_vc_send_short(dsidev, channel, data_type, data, 0);
if (r) {
DSSERR("dsi_vc_generic_send_read_request(ch %d, reqlen %d)"
" failed\n", channel, reqlen);
return r;
}
return 0;
}
static int dsi_vc_read_rx_fifo(struct platform_device *dsidev, int channel,
u8 *buf, int buflen, enum dss_dsi_content_type type)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
u32 val;
u8 dt;
int r;
if (REG_GET(dsidev, DSI_VC_CTRL(channel), 20, 20) == 0) {
DSSERR("RX fifo empty when trying to read.\n");
r = -EIO;
goto err;
}
val = dsi_read_reg(dsidev, DSI_VC_SHORT_PACKET_HEADER(channel));
if (dsi->debug_read)
DSSDBG("\theader: %08x\n", val);
dt = FLD_GET(val, 5, 0);
if (dt == MIPI_DSI_RX_ACKNOWLEDGE_AND_ERROR_REPORT) {
u16 err = FLD_GET(val, 23, 8);
dsi_show_rx_ack_with_err(err);
r = -EIO;
goto err;
} else if (dt == (type == DSS_DSI_CONTENT_GENERIC ?
MIPI_DSI_RX_GENERIC_SHORT_READ_RESPONSE_1BYTE :
MIPI_DSI_RX_DCS_SHORT_READ_RESPONSE_1BYTE)) {
u8 data = FLD_GET(val, 15, 8);
if (dsi->debug_read)
DSSDBG("\t%s short response, 1 byte: %02x\n",
type == DSS_DSI_CONTENT_GENERIC ? "GENERIC" :
"DCS", data);
if (buflen < 1) {
r = -EIO;
goto err;
}
buf[0] = data;
return 1;
} else if (dt == (type == DSS_DSI_CONTENT_GENERIC ?
MIPI_DSI_RX_GENERIC_SHORT_READ_RESPONSE_2BYTE :
MIPI_DSI_RX_DCS_SHORT_READ_RESPONSE_2BYTE)) {
u16 data = FLD_GET(val, 23, 8);
if (dsi->debug_read)
DSSDBG("\t%s short response, 2 byte: %04x\n",
type == DSS_DSI_CONTENT_GENERIC ? "GENERIC" :
"DCS", data);
if (buflen < 2) {
r = -EIO;
goto err;
}
buf[0] = data & 0xff;
buf[1] = (data >> 8) & 0xff;
return 2;
} else if (dt == (type == DSS_DSI_CONTENT_GENERIC ?
MIPI_DSI_RX_GENERIC_LONG_READ_RESPONSE :
MIPI_DSI_RX_DCS_LONG_READ_RESPONSE)) {
int w;
int len = FLD_GET(val, 23, 8);
if (dsi->debug_read)
DSSDBG("\t%s long response, len %d\n",
type == DSS_DSI_CONTENT_GENERIC ? "GENERIC" :
"DCS", len);
if (len > buflen) {
r = -EIO;
goto err;
}
for (w = 0; w < len + 2;) {
int b;
val = dsi_read_reg(dsidev,
DSI_VC_SHORT_PACKET_HEADER(channel));
if (dsi->debug_read)
DSSDBG("\t\t%02x %02x %02x %02x\n",
(val >> 0) & 0xff,
(val >> 8) & 0xff,
(val >> 16) & 0xff,
(val >> 24) & 0xff);
for (b = 0; b < 4; ++b) {
if (w < len)
buf[w] = (val >> (b * 8)) & 0xff;
++w;
}
}
return len;
} else {
DSSERR("\tunknown datatype 0x%02x\n", dt);
r = -EIO;
goto err;
}
err:
DSSERR("dsi_vc_read_rx_fifo(ch %d type %s) failed\n", channel,
type == DSS_DSI_CONTENT_GENERIC ? "GENERIC" : "DCS");
return r;
}
static int dsi_vc_dcs_read(struct omap_dss_device *dssdev, int channel, u8 dcs_cmd,
u8 *buf, int buflen)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
int r;
r = dsi_vc_dcs_send_read_request(dsidev, channel, dcs_cmd);
if (r)
goto err;
r = dsi_vc_send_bta_sync(dssdev, channel);
if (r)
goto err;
r = dsi_vc_read_rx_fifo(dsidev, channel, buf, buflen,
DSS_DSI_CONTENT_DCS);
if (r < 0)
goto err;
if (r != buflen) {
r = -EIO;
goto err;
}
return 0;
err:
DSSERR("dsi_vc_dcs_read(ch %d, cmd 0x%02x) failed\n", channel, dcs_cmd);
return r;
}
static int dsi_vc_generic_read(struct omap_dss_device *dssdev, int channel,
u8 *reqdata, int reqlen, u8 *buf, int buflen)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
int r;
r = dsi_vc_generic_send_read_request(dsidev, channel, reqdata, reqlen);
if (r)
return r;
r = dsi_vc_send_bta_sync(dssdev, channel);
if (r)
return r;
r = dsi_vc_read_rx_fifo(dsidev, channel, buf, buflen,
DSS_DSI_CONTENT_GENERIC);
if (r < 0)
return r;
if (r != buflen) {
r = -EIO;
return r;
}
return 0;
}
static int dsi_vc_set_max_rx_packet_size(struct omap_dss_device *dssdev, int channel,
u16 len)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
return dsi_vc_send_short(dsidev, channel,
MIPI_DSI_SET_MAXIMUM_RETURN_PACKET_SIZE, len, 0);
}
static int dsi_enter_ulps(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
DECLARE_COMPLETION_ONSTACK(completion);
int r, i;
unsigned mask;
DSSDBG("Entering ULPS");
WARN_ON(!dsi_bus_is_locked(dsidev));
WARN_ON(dsi->ulps_enabled);
if (dsi->ulps_enabled)
return 0;
if (REG_GET(dsidev, DSI_CLK_CTRL, 13, 13)) {
dsi_if_enable(dsidev, 0);
REG_FLD_MOD(dsidev, DSI_CLK_CTRL, 0, 13, 13);
dsi_if_enable(dsidev, 1);
}
dsi_sync_vc(dsidev, 0);
dsi_sync_vc(dsidev, 1);
dsi_sync_vc(dsidev, 2);
dsi_sync_vc(dsidev, 3);
dsi_force_tx_stop_mode_io(dsidev);
dsi_vc_enable(dsidev, 0, false);
dsi_vc_enable(dsidev, 1, false);
dsi_vc_enable(dsidev, 2, false);
dsi_vc_enable(dsidev, 3, false);
if (REG_GET(dsidev, DSI_COMPLEXIO_CFG2, 16, 16)) {
DSSERR("HS busy when enabling ULPS\n");
return -EIO;
}
if (REG_GET(dsidev, DSI_COMPLEXIO_CFG2, 17, 17)) {
DSSERR("LP busy when enabling ULPS\n");
return -EIO;
}
r = dsi_register_isr_cio(dsidev, dsi_completion_handler, &completion,
DSI_CIO_IRQ_ULPSACTIVENOT_ALL0);
if (r)
return r;
mask = 0;
for (i = 0; i < dsi->num_lanes_supported; ++i) {
if (dsi->lanes[i].function == DSI_LANE_UNUSED)
continue;
mask |= 1 << i;
}
REG_FLD_MOD(dsidev, DSI_COMPLEXIO_CFG2, mask, 9, 5);
dsi_read_reg(dsidev, DSI_COMPLEXIO_CFG2);
if (wait_for_completion_timeout(&completion,
msecs_to_jiffies(1000)) == 0) {
DSSERR("ULPS enable timeout\n");
r = -EIO;
goto err;
}
dsi_unregister_isr_cio(dsidev, dsi_completion_handler, &completion,
DSI_CIO_IRQ_ULPSACTIVENOT_ALL0);
REG_FLD_MOD(dsidev, DSI_COMPLEXIO_CFG2, 0, 9, 5);
dsi_read_reg(dsidev, DSI_COMPLEXIO_CFG2);
dsi_cio_power(dsidev, DSI_COMPLEXIO_POWER_ULPS);
dsi_if_enable(dsidev, false);
dsi->ulps_enabled = true;
return 0;
err:
dsi_unregister_isr_cio(dsidev, dsi_completion_handler, &completion,
DSI_CIO_IRQ_ULPSACTIVENOT_ALL0);
return r;
}
static void dsi_set_lp_rx_timeout(struct platform_device *dsidev,
unsigned ticks, bool x4, bool x16)
{
unsigned long fck;
unsigned long total_ticks;
u32 r;
BUG_ON(ticks > 0x1fff);
fck = dsi_fclk_rate(dsidev);
r = dsi_read_reg(dsidev, DSI_TIMING2);
r = FLD_MOD(r, 1, 15, 15);
r = FLD_MOD(r, x16 ? 1 : 0, 14, 14);
r = FLD_MOD(r, x4 ? 1 : 0, 13, 13);
r = FLD_MOD(r, ticks, 12, 0);
dsi_write_reg(dsidev, DSI_TIMING2, r);
total_ticks = ticks * (x16 ? 16 : 1) * (x4 ? 4 : 1);
DSSDBG("LP_RX_TO %lu ticks (%#x%s%s) = %lu ns\n",
total_ticks,
ticks, x4 ? " x4" : "", x16 ? " x16" : "",
(total_ticks * 1000) / (fck / 1000 / 1000));
}
static void dsi_set_ta_timeout(struct platform_device *dsidev, unsigned ticks,
bool x8, bool x16)
{
unsigned long fck;
unsigned long total_ticks;
u32 r;
BUG_ON(ticks > 0x1fff);
fck = dsi_fclk_rate(dsidev);
r = dsi_read_reg(dsidev, DSI_TIMING1);
r = FLD_MOD(r, 1, 31, 31);
r = FLD_MOD(r, x16 ? 1 : 0, 30, 30);
r = FLD_MOD(r, x8 ? 1 : 0, 29, 29);
r = FLD_MOD(r, ticks, 28, 16);
dsi_write_reg(dsidev, DSI_TIMING1, r);
total_ticks = ticks * (x16 ? 16 : 1) * (x8 ? 8 : 1);
DSSDBG("TA_TO %lu ticks (%#x%s%s) = %lu ns\n",
total_ticks,
ticks, x8 ? " x8" : "", x16 ? " x16" : "",
(total_ticks * 1000) / (fck / 1000 / 1000));
}
static void dsi_set_stop_state_counter(struct platform_device *dsidev,
unsigned ticks, bool x4, bool x16)
{
unsigned long fck;
unsigned long total_ticks;
u32 r;
BUG_ON(ticks > 0x1fff);
fck = dsi_fclk_rate(dsidev);
r = dsi_read_reg(dsidev, DSI_TIMING1);
r = FLD_MOD(r, 1, 15, 15);
r = FLD_MOD(r, x16 ? 1 : 0, 14, 14);
r = FLD_MOD(r, x4 ? 1 : 0, 13, 13);
r = FLD_MOD(r, ticks, 12, 0);
dsi_write_reg(dsidev, DSI_TIMING1, r);
total_ticks = ticks * (x16 ? 16 : 1) * (x4 ? 4 : 1);
DSSDBG("STOP_STATE_COUNTER %lu ticks (%#x%s%s) = %lu ns\n",
total_ticks,
ticks, x4 ? " x4" : "", x16 ? " x16" : "",
(total_ticks * 1000) / (fck / 1000 / 1000));
}
static void dsi_set_hs_tx_timeout(struct platform_device *dsidev,
unsigned ticks, bool x4, bool x16)
{
unsigned long fck;
unsigned long total_ticks;
u32 r;
BUG_ON(ticks > 0x1fff);
fck = dsi_get_txbyteclkhs(dsidev);
r = dsi_read_reg(dsidev, DSI_TIMING2);
r = FLD_MOD(r, 1, 31, 31);
r = FLD_MOD(r, x16 ? 1 : 0, 30, 30);
r = FLD_MOD(r, x4 ? 1 : 0, 29, 29);
r = FLD_MOD(r, ticks, 28, 16);
dsi_write_reg(dsidev, DSI_TIMING2, r);
total_ticks = ticks * (x16 ? 16 : 1) * (x4 ? 4 : 1);
DSSDBG("HS_TX_TO %lu ticks (%#x%s%s) = %lu ns\n",
total_ticks,
ticks, x4 ? " x4" : "", x16 ? " x16" : "",
(total_ticks * 1000) / (fck / 1000 / 1000));
}
static void dsi_config_vp_num_line_buffers(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int num_line_buffers;
if (dsi->mode == OMAP_DSS_DSI_VIDEO_MODE) {
int bpp = dsi_get_pixel_size(dsi->pix_fmt);
struct omap_video_timings *timings = &dsi->timings;
if (dsi->line_buffer_size <= timings->x_res * bpp / 8)
num_line_buffers = 0;
else
num_line_buffers = 2;
} else {
num_line_buffers = 2;
}
REG_FLD_MOD(dsidev, DSI_CTRL, num_line_buffers, 13, 12);
}
static void dsi_config_vp_sync_events(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
bool sync_end;
u32 r;
if (dsi->vm_timings.trans_mode == OMAP_DSS_DSI_PULSE_MODE)
sync_end = true;
else
sync_end = false;
r = dsi_read_reg(dsidev, DSI_CTRL);
r = FLD_MOD(r, 1, 9, 9);
r = FLD_MOD(r, 1, 10, 10);
r = FLD_MOD(r, 1, 11, 11);
r = FLD_MOD(r, 1, 15, 15);
r = FLD_MOD(r, sync_end, 16, 16);
r = FLD_MOD(r, 1, 17, 17);
r = FLD_MOD(r, sync_end, 18, 18);
dsi_write_reg(dsidev, DSI_CTRL, r);
}
static void dsi_config_blanking_modes(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int blanking_mode = dsi->vm_timings.blanking_mode;
int hfp_blanking_mode = dsi->vm_timings.hfp_blanking_mode;
int hbp_blanking_mode = dsi->vm_timings.hbp_blanking_mode;
int hsa_blanking_mode = dsi->vm_timings.hsa_blanking_mode;
u32 r;
r = dsi_read_reg(dsidev, DSI_CTRL);
r = FLD_MOD(r, blanking_mode, 20, 20);
r = FLD_MOD(r, hfp_blanking_mode, 21, 21);
r = FLD_MOD(r, hbp_blanking_mode, 22, 22);
r = FLD_MOD(r, hsa_blanking_mode, 23, 23);
dsi_write_reg(dsidev, DSI_CTRL, r);
}
static int dsi_compute_interleave_hs(int blank, bool ddr_alwon, int enter_hs,
int exit_hs, int exiths_clk, int ddr_pre, int ddr_post)
{
int transition;
if (ddr_alwon) {
transition = enter_hs + exit_hs + max(enter_hs, 2) + 1;
} else {
int trans1, trans2;
trans1 = ddr_pre + enter_hs + exit_hs + max(enter_hs, 2) + 1;
trans2 = ddr_pre + enter_hs + exiths_clk + ddr_post + ddr_pre +
enter_hs + 1;
transition = max(trans1, trans2);
}
return blank > transition ? blank - transition : 0;
}
static int dsi_compute_interleave_lp(int blank, int enter_hs, int exit_hs,
int lp_clk_div, int tdsi_fclk)
{
int trans_lp;
int tlp_avail;
int ttxclkesc;
int thsbyte_clk = 16;
int lp_inter;
trans_lp = exit_hs + max(enter_hs, 2) + 1;
tlp_avail = thsbyte_clk * (blank - trans_lp);
ttxclkesc = tdsi_fclk * lp_clk_div;
lp_inter = ((tlp_avail - 8 * thsbyte_clk - 5 * tdsi_fclk) / ttxclkesc -
26) / 16;
return max(lp_inter, 0);
}
static void dsi_config_cmd_mode_interleaving(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int blanking_mode;
int hfp_blanking_mode, hbp_blanking_mode, hsa_blanking_mode;
int hsa, hfp, hbp, width_bytes, bllp, lp_clk_div;
int ddr_clk_pre, ddr_clk_post, enter_hs_mode_lat, exit_hs_mode_lat;
int tclk_trail, ths_exit, exiths_clk;
bool ddr_alwon;
struct omap_video_timings *timings = &dsi->timings;
int bpp = dsi_get_pixel_size(dsi->pix_fmt);
int ndl = dsi->num_lanes_used - 1;
int dsi_fclk_hsdiv = dsi->user_dsi_cinfo.mX[HSDIV_DSI] + 1;
int hsa_interleave_hs = 0, hsa_interleave_lp = 0;
int hfp_interleave_hs = 0, hfp_interleave_lp = 0;
int hbp_interleave_hs = 0, hbp_interleave_lp = 0;
int bl_interleave_hs = 0, bl_interleave_lp = 0;
u32 r;
r = dsi_read_reg(dsidev, DSI_CTRL);
blanking_mode = FLD_GET(r, 20, 20);
hfp_blanking_mode = FLD_GET(r, 21, 21);
hbp_blanking_mode = FLD_GET(r, 22, 22);
hsa_blanking_mode = FLD_GET(r, 23, 23);
r = dsi_read_reg(dsidev, DSI_VM_TIMING1);
hbp = FLD_GET(r, 11, 0);
hfp = FLD_GET(r, 23, 12);
hsa = FLD_GET(r, 31, 24);
r = dsi_read_reg(dsidev, DSI_CLK_TIMING);
ddr_clk_post = FLD_GET(r, 7, 0);
ddr_clk_pre = FLD_GET(r, 15, 8);
r = dsi_read_reg(dsidev, DSI_VM_TIMING7);
exit_hs_mode_lat = FLD_GET(r, 15, 0);
enter_hs_mode_lat = FLD_GET(r, 31, 16);
r = dsi_read_reg(dsidev, DSI_CLK_CTRL);
lp_clk_div = FLD_GET(r, 12, 0);
ddr_alwon = FLD_GET(r, 13, 13);
r = dsi_read_reg(dsidev, DSI_DSIPHY_CFG0);
ths_exit = FLD_GET(r, 7, 0);
r = dsi_read_reg(dsidev, DSI_DSIPHY_CFG1);
tclk_trail = FLD_GET(r, 15, 8);
exiths_clk = ths_exit + tclk_trail;
width_bytes = DIV_ROUND_UP(timings->x_res * bpp, 8);
bllp = hbp + hfp + hsa + DIV_ROUND_UP(width_bytes + 6, ndl);
if (!hsa_blanking_mode) {
hsa_interleave_hs = dsi_compute_interleave_hs(hsa, ddr_alwon,
enter_hs_mode_lat, exit_hs_mode_lat,
exiths_clk, ddr_clk_pre, ddr_clk_post);
hsa_interleave_lp = dsi_compute_interleave_lp(hsa,
enter_hs_mode_lat, exit_hs_mode_lat,
lp_clk_div, dsi_fclk_hsdiv);
}
if (!hfp_blanking_mode) {
hfp_interleave_hs = dsi_compute_interleave_hs(hfp, ddr_alwon,
enter_hs_mode_lat, exit_hs_mode_lat,
exiths_clk, ddr_clk_pre, ddr_clk_post);
hfp_interleave_lp = dsi_compute_interleave_lp(hfp,
enter_hs_mode_lat, exit_hs_mode_lat,
lp_clk_div, dsi_fclk_hsdiv);
}
if (!hbp_blanking_mode) {
hbp_interleave_hs = dsi_compute_interleave_hs(hbp, ddr_alwon,
enter_hs_mode_lat, exit_hs_mode_lat,
exiths_clk, ddr_clk_pre, ddr_clk_post);
hbp_interleave_lp = dsi_compute_interleave_lp(hbp,
enter_hs_mode_lat, exit_hs_mode_lat,
lp_clk_div, dsi_fclk_hsdiv);
}
if (!blanking_mode) {
bl_interleave_hs = dsi_compute_interleave_hs(bllp, ddr_alwon,
enter_hs_mode_lat, exit_hs_mode_lat,
exiths_clk, ddr_clk_pre, ddr_clk_post);
bl_interleave_lp = dsi_compute_interleave_lp(bllp,
enter_hs_mode_lat, exit_hs_mode_lat,
lp_clk_div, dsi_fclk_hsdiv);
}
DSSDBG("DSI HS interleaving(TXBYTECLKHS) HSA %d, HFP %d, HBP %d, BLLP %d\n",
hsa_interleave_hs, hfp_interleave_hs, hbp_interleave_hs,
bl_interleave_hs);
DSSDBG("DSI LP interleaving(bytes) HSA %d, HFP %d, HBP %d, BLLP %d\n",
hsa_interleave_lp, hfp_interleave_lp, hbp_interleave_lp,
bl_interleave_lp);
r = dsi_read_reg(dsidev, DSI_VM_TIMING4);
r = FLD_MOD(r, hsa_interleave_hs, 23, 16);
r = FLD_MOD(r, hfp_interleave_hs, 15, 8);
r = FLD_MOD(r, hbp_interleave_hs, 7, 0);
dsi_write_reg(dsidev, DSI_VM_TIMING4, r);
r = dsi_read_reg(dsidev, DSI_VM_TIMING5);
r = FLD_MOD(r, hsa_interleave_lp, 23, 16);
r = FLD_MOD(r, hfp_interleave_lp, 15, 8);
r = FLD_MOD(r, hbp_interleave_lp, 7, 0);
dsi_write_reg(dsidev, DSI_VM_TIMING5, r);
r = dsi_read_reg(dsidev, DSI_VM_TIMING6);
r = FLD_MOD(r, bl_interleave_hs, 31, 15);
r = FLD_MOD(r, bl_interleave_lp, 16, 0);
dsi_write_reg(dsidev, DSI_VM_TIMING6, r);
}
static int dsi_proto_config(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
u32 r;
int buswidth = 0;
dsi_config_tx_fifo(dsidev, DSI_FIFO_SIZE_32,
DSI_FIFO_SIZE_32,
DSI_FIFO_SIZE_32,
DSI_FIFO_SIZE_32);
dsi_config_rx_fifo(dsidev, DSI_FIFO_SIZE_32,
DSI_FIFO_SIZE_32,
DSI_FIFO_SIZE_32,
DSI_FIFO_SIZE_32);
dsi_set_stop_state_counter(dsidev, 0x1000, false, false);
dsi_set_ta_timeout(dsidev, 0x1fff, true, true);
dsi_set_lp_rx_timeout(dsidev, 0x1fff, true, true);
dsi_set_hs_tx_timeout(dsidev, 0x1fff, true, true);
switch (dsi_get_pixel_size(dsi->pix_fmt)) {
case 16:
buswidth = 0;
break;
case 18:
buswidth = 1;
break;
case 24:
buswidth = 2;
break;
default:
BUG();
return -EINVAL;
}
r = dsi_read_reg(dsidev, DSI_CTRL);
r = FLD_MOD(r, 1, 1, 1);
r = FLD_MOD(r, 1, 2, 2);
r = FLD_MOD(r, 1, 3, 3);
r = FLD_MOD(r, 1, 4, 4);
r = FLD_MOD(r, buswidth, 7, 6);
r = FLD_MOD(r, 0, 8, 8);
r = FLD_MOD(r, 1, 14, 14);
r = FLD_MOD(r, 1, 19, 19);
if (!dss_has_feature(FEAT_DSI_DCS_CMD_CONFIG_VC)) {
r = FLD_MOD(r, 1, 24, 24);
r = FLD_MOD(r, 0, 25, 25);
}
dsi_write_reg(dsidev, DSI_CTRL, r);
dsi_config_vp_num_line_buffers(dsidev);
if (dsi->mode == OMAP_DSS_DSI_VIDEO_MODE) {
dsi_config_vp_sync_events(dsidev);
dsi_config_blanking_modes(dsidev);
dsi_config_cmd_mode_interleaving(dsidev);
}
dsi_vc_initial_config(dsidev, 0);
dsi_vc_initial_config(dsidev, 1);
dsi_vc_initial_config(dsidev, 2);
dsi_vc_initial_config(dsidev, 3);
return 0;
}
static void dsi_proto_timings(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
unsigned tlpx, tclk_zero, tclk_prepare, tclk_trail;
unsigned tclk_pre, tclk_post;
unsigned ths_prepare, ths_prepare_ths_zero, ths_zero;
unsigned ths_trail, ths_exit;
unsigned ddr_clk_pre, ddr_clk_post;
unsigned enter_hs_mode_lat, exit_hs_mode_lat;
unsigned ths_eot;
int ndl = dsi->num_lanes_used - 1;
u32 r;
r = dsi_read_reg(dsidev, DSI_DSIPHY_CFG0);
ths_prepare = FLD_GET(r, 31, 24);
ths_prepare_ths_zero = FLD_GET(r, 23, 16);
ths_zero = ths_prepare_ths_zero - ths_prepare;
ths_trail = FLD_GET(r, 15, 8);
ths_exit = FLD_GET(r, 7, 0);
r = dsi_read_reg(dsidev, DSI_DSIPHY_CFG1);
tlpx = FLD_GET(r, 20, 16) * 2;
tclk_trail = FLD_GET(r, 15, 8);
tclk_zero = FLD_GET(r, 7, 0);
r = dsi_read_reg(dsidev, DSI_DSIPHY_CFG2);
tclk_prepare = FLD_GET(r, 7, 0);
tclk_pre = 20;
tclk_post = ns2ddr(dsidev, 60) + 26;
ths_eot = DIV_ROUND_UP(4, ndl);
ddr_clk_pre = DIV_ROUND_UP(tclk_pre + tlpx + tclk_zero + tclk_prepare,
4);
ddr_clk_post = DIV_ROUND_UP(tclk_post + ths_trail, 4) + ths_eot;
BUG_ON(ddr_clk_pre == 0 || ddr_clk_pre > 255);
BUG_ON(ddr_clk_post == 0 || ddr_clk_post > 255);
r = dsi_read_reg(dsidev, DSI_CLK_TIMING);
r = FLD_MOD(r, ddr_clk_pre, 15, 8);
r = FLD_MOD(r, ddr_clk_post, 7, 0);
dsi_write_reg(dsidev, DSI_CLK_TIMING, r);
DSSDBG("ddr_clk_pre %u, ddr_clk_post %u\n",
ddr_clk_pre,
ddr_clk_post);
enter_hs_mode_lat = 1 + DIV_ROUND_UP(tlpx, 4) +
DIV_ROUND_UP(ths_prepare, 4) +
DIV_ROUND_UP(ths_zero + 3, 4);
exit_hs_mode_lat = DIV_ROUND_UP(ths_trail + ths_exit, 4) + 1 + ths_eot;
r = FLD_VAL(enter_hs_mode_lat, 31, 16) |
FLD_VAL(exit_hs_mode_lat, 15, 0);
dsi_write_reg(dsidev, DSI_VM_TIMING7, r);
DSSDBG("enter_hs_mode_lat %u, exit_hs_mode_lat %u\n",
enter_hs_mode_lat, exit_hs_mode_lat);
if (dsi->mode == OMAP_DSS_DSI_VIDEO_MODE) {
int hsa = dsi->vm_timings.hsa;
int hfp = dsi->vm_timings.hfp;
int hbp = dsi->vm_timings.hbp;
int vsa = dsi->vm_timings.vsa;
int vfp = dsi->vm_timings.vfp;
int vbp = dsi->vm_timings.vbp;
int window_sync = dsi->vm_timings.window_sync;
bool hsync_end;
struct omap_video_timings *timings = &dsi->timings;
int bpp = dsi_get_pixel_size(dsi->pix_fmt);
int tl, t_he, width_bytes;
hsync_end = dsi->vm_timings.trans_mode == OMAP_DSS_DSI_PULSE_MODE;
t_he = hsync_end ?
((hsa == 0 && ndl == 3) ? 1 : DIV_ROUND_UP(4, ndl)) : 0;
width_bytes = DIV_ROUND_UP(timings->x_res * bpp, 8);
tl = DIV_ROUND_UP(4, ndl) + (hsync_end ? hsa : 0) + t_he + hfp +
DIV_ROUND_UP(width_bytes + 6, ndl) + hbp;
DSSDBG("HBP: %d, HFP: %d, HSA: %d, TL: %d TXBYTECLKHS\n", hbp,
hfp, hsync_end ? hsa : 0, tl);
DSSDBG("VBP: %d, VFP: %d, VSA: %d, VACT: %d lines\n", vbp, vfp,
vsa, timings->y_res);
r = dsi_read_reg(dsidev, DSI_VM_TIMING1);
r = FLD_MOD(r, hbp, 11, 0);
r = FLD_MOD(r, hfp, 23, 12);
r = FLD_MOD(r, hsync_end ? hsa : 0, 31, 24);
dsi_write_reg(dsidev, DSI_VM_TIMING1, r);
r = dsi_read_reg(dsidev, DSI_VM_TIMING2);
r = FLD_MOD(r, vbp, 7, 0);
r = FLD_MOD(r, vfp, 15, 8);
r = FLD_MOD(r, vsa, 23, 16);
r = FLD_MOD(r, window_sync, 27, 24);
dsi_write_reg(dsidev, DSI_VM_TIMING2, r);
r = dsi_read_reg(dsidev, DSI_VM_TIMING3);
r = FLD_MOD(r, timings->y_res, 14, 0);
r = FLD_MOD(r, tl, 31, 16);
dsi_write_reg(dsidev, DSI_VM_TIMING3, r);
}
}
static int dsi_configure_pins(struct omap_dss_device *dssdev,
const struct omap_dsi_pin_config *pin_cfg)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int num_pins;
const int *pins;
struct dsi_lane_config lanes[DSI_MAX_NR_LANES];
int num_lanes;
int i;
static const enum dsi_lane_function functions[] = {
DSI_LANE_CLK,
DSI_LANE_DATA1,
DSI_LANE_DATA2,
DSI_LANE_DATA3,
DSI_LANE_DATA4,
};
num_pins = pin_cfg->num_pins;
pins = pin_cfg->pins;
if (num_pins < 4 || num_pins > dsi->num_lanes_supported * 2
|| num_pins % 2 != 0)
return -EINVAL;
for (i = 0; i < DSI_MAX_NR_LANES; ++i)
lanes[i].function = DSI_LANE_UNUSED;
num_lanes = 0;
for (i = 0; i < num_pins; i += 2) {
u8 lane, pol;
int dx, dy;
dx = pins[i];
dy = pins[i + 1];
if (dx < 0 || dx >= dsi->num_lanes_supported * 2)
return -EINVAL;
if (dy < 0 || dy >= dsi->num_lanes_supported * 2)
return -EINVAL;
if (dx & 1) {
if (dy != dx - 1)
return -EINVAL;
pol = 1;
} else {
if (dy != dx + 1)
return -EINVAL;
pol = 0;
}
lane = dx / 2;
lanes[lane].function = functions[i / 2];
lanes[lane].polarity = pol;
num_lanes++;
}
memcpy(dsi->lanes, lanes, sizeof(dsi->lanes));
dsi->num_lanes_used = num_lanes;
return 0;
}
static int dsi_enable_video_output(struct omap_dss_device *dssdev, int channel)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
enum omap_channel dispc_channel = dssdev->dispc_channel;
int bpp = dsi_get_pixel_size(dsi->pix_fmt);
struct omap_dss_device *out = &dsi->output;
u8 data_type;
u16 word_count;
int r;
if (!out->dispc_channel_connected) {
DSSERR("failed to enable display: no output/manager\n");
return -ENODEV;
}
r = dsi_display_init_dispc(dsidev, dispc_channel);
if (r)
goto err_init_dispc;
if (dsi->mode == OMAP_DSS_DSI_VIDEO_MODE) {
switch (dsi->pix_fmt) {
case OMAP_DSS_DSI_FMT_RGB888:
data_type = MIPI_DSI_PACKED_PIXEL_STREAM_24;
break;
case OMAP_DSS_DSI_FMT_RGB666:
data_type = MIPI_DSI_PIXEL_STREAM_3BYTE_18;
break;
case OMAP_DSS_DSI_FMT_RGB666_PACKED:
data_type = MIPI_DSI_PACKED_PIXEL_STREAM_18;
break;
case OMAP_DSS_DSI_FMT_RGB565:
data_type = MIPI_DSI_PACKED_PIXEL_STREAM_16;
break;
default:
r = -EINVAL;
goto err_pix_fmt;
}
dsi_if_enable(dsidev, false);
dsi_vc_enable(dsidev, channel, false);
REG_FLD_MOD(dsidev, DSI_VC_CTRL(channel), 1, 4, 4);
word_count = DIV_ROUND_UP(dsi->timings.x_res * bpp, 8);
dsi_vc_write_long_header(dsidev, channel, data_type,
word_count, 0);
dsi_vc_enable(dsidev, channel, true);
dsi_if_enable(dsidev, true);
}
r = dss_mgr_enable(dispc_channel);
if (r)
goto err_mgr_enable;
return 0;
err_mgr_enable:
if (dsi->mode == OMAP_DSS_DSI_VIDEO_MODE) {
dsi_if_enable(dsidev, false);
dsi_vc_enable(dsidev, channel, false);
}
err_pix_fmt:
dsi_display_uninit_dispc(dsidev, dispc_channel);
err_init_dispc:
return r;
}
static void dsi_disable_video_output(struct omap_dss_device *dssdev, int channel)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
enum omap_channel dispc_channel = dssdev->dispc_channel;
if (dsi->mode == OMAP_DSS_DSI_VIDEO_MODE) {
dsi_if_enable(dsidev, false);
dsi_vc_enable(dsidev, channel, false);
REG_FLD_MOD(dsidev, DSI_VC_CTRL(channel), 0, 4, 4);
dsi_vc_enable(dsidev, channel, true);
dsi_if_enable(dsidev, true);
}
dss_mgr_disable(dispc_channel);
dsi_display_uninit_dispc(dsidev, dispc_channel);
}
static void dsi_update_screen_dispc(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
enum omap_channel dispc_channel = dsi->output.dispc_channel;
unsigned bytespp;
unsigned bytespl;
unsigned bytespf;
unsigned total_len;
unsigned packet_payload;
unsigned packet_len;
u32 l;
int r;
const unsigned channel = dsi->update_channel;
const unsigned line_buf_size = dsi->line_buffer_size;
u16 w = dsi->timings.x_res;
u16 h = dsi->timings.y_res;
DSSDBG("dsi_update_screen_dispc(%dx%d)\n", w, h);
dsi_vc_config_source(dsidev, channel, DSI_VC_SOURCE_VP);
bytespp = dsi_get_pixel_size(dsi->pix_fmt) / 8;
bytespl = w * bytespp;
bytespf = bytespl * h;
if (bytespf < line_buf_size)
packet_payload = bytespf;
else
packet_payload = (line_buf_size) / bytespl * bytespl;
packet_len = packet_payload + 1;
total_len = (bytespf / packet_payload) * packet_len;
if (bytespf % packet_payload)
total_len += (bytespf % packet_payload) + 1;
l = FLD_VAL(total_len, 23, 0);
dsi_write_reg(dsidev, DSI_VC_TE(channel), l);
dsi_vc_write_long_header(dsidev, channel, MIPI_DSI_DCS_LONG_WRITE,
packet_len, 0);
if (dsi->te_enabled)
l = FLD_MOD(l, 1, 30, 30);
else
l = FLD_MOD(l, 1, 31, 31);
dsi_write_reg(dsidev, DSI_VC_TE(channel), l);
dispc_disable_sidle();
dsi_perf_mark_start(dsidev);
r = schedule_delayed_work(&dsi->framedone_timeout_work,
msecs_to_jiffies(250));
BUG_ON(r == 0);
dss_mgr_set_timings(dispc_channel, &dsi->timings);
dss_mgr_start_update(dispc_channel);
if (dsi->te_enabled) {
REG_FLD_MOD(dsidev, DSI_TIMING2, 0, 15, 15);
dsi_vc_send_bta(dsidev, channel);
#ifdef DSI_CATCH_MISSING_TE
mod_timer(&dsi->te_timer, jiffies + msecs_to_jiffies(250));
#endif
}
}
static void dsi_te_timeout(unsigned long arg)
{
DSSERR("TE not received for 250ms!\n");
}
static void dsi_handle_framedone(struct platform_device *dsidev, int error)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
dispc_enable_sidle();
if (dsi->te_enabled) {
REG_FLD_MOD(dsidev, DSI_TIMING2, 1, 15, 15);
}
dsi->framedone_callback(error, dsi->framedone_data);
if (!error)
dsi_perf_show(dsidev, "DISPC");
}
static void dsi_framedone_timeout_work_callback(struct work_struct *work)
{
struct dsi_data *dsi = container_of(work, struct dsi_data,
framedone_timeout_work.work);
DSSERR("Framedone not received for 250ms!\n");
dsi_handle_framedone(dsi->pdev, -ETIMEDOUT);
}
static void dsi_framedone_irq_callback(void *data)
{
struct platform_device *dsidev = (struct platform_device *) data;
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
cancel_delayed_work(&dsi->framedone_timeout_work);
dsi_handle_framedone(dsidev, 0);
}
static int dsi_update(struct omap_dss_device *dssdev, int channel,
void (*callback)(int, void *), void *data)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
u16 dw, dh;
dsi_perf_mark_setup(dsidev);
dsi->update_channel = channel;
dsi->framedone_callback = callback;
dsi->framedone_data = data;
dw = dsi->timings.x_res;
dh = dsi->timings.y_res;
#ifdef DSI_PERF_MEASURE
dsi->update_bytes = dw * dh *
dsi_get_pixel_size(dsi->pix_fmt) / 8;
#endif
dsi_update_screen_dispc(dsidev);
return 0;
}
static int dsi_configure_dispc_clocks(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct dispc_clock_info dispc_cinfo;
int r;
unsigned long fck;
fck = dsi_get_pll_hsdiv_dispc_rate(dsidev);
dispc_cinfo.lck_div = dsi->user_dispc_cinfo.lck_div;
dispc_cinfo.pck_div = dsi->user_dispc_cinfo.pck_div;
r = dispc_calc_clock_rates(fck, &dispc_cinfo);
if (r) {
DSSERR("Failed to calc dispc clocks\n");
return r;
}
dsi->mgr_config.clock_info = dispc_cinfo;
return 0;
}
static int dsi_display_init_dispc(struct platform_device *dsidev,
enum omap_channel channel)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int r;
dss_select_lcd_clk_source(channel, dsi->module_id == 0 ?
OMAP_DSS_CLK_SRC_DSI_PLL_HSDIV_DISPC :
OMAP_DSS_CLK_SRC_DSI2_PLL_HSDIV_DISPC);
if (dsi->mode == OMAP_DSS_DSI_CMD_MODE) {
r = dss_mgr_register_framedone_handler(channel,
dsi_framedone_irq_callback, dsidev);
if (r) {
DSSERR("can't register FRAMEDONE handler\n");
goto err;
}
dsi->mgr_config.stallmode = true;
dsi->mgr_config.fifohandcheck = true;
} else {
dsi->mgr_config.stallmode = false;
dsi->mgr_config.fifohandcheck = false;
}
dsi->timings.interlace = false;
dsi->timings.hsync_level = OMAPDSS_SIG_ACTIVE_HIGH;
dsi->timings.vsync_level = OMAPDSS_SIG_ACTIVE_HIGH;
dsi->timings.data_pclk_edge = OMAPDSS_DRIVE_SIG_RISING_EDGE;
dsi->timings.de_level = OMAPDSS_SIG_ACTIVE_HIGH;
dsi->timings.sync_pclk_edge = OMAPDSS_DRIVE_SIG_FALLING_EDGE;
dss_mgr_set_timings(channel, &dsi->timings);
r = dsi_configure_dispc_clocks(dsidev);
if (r)
goto err1;
dsi->mgr_config.io_pad_mode = DSS_IO_PAD_MODE_BYPASS;
dsi->mgr_config.video_port_width =
dsi_get_pixel_size(dsi->pix_fmt);
dsi->mgr_config.lcden_sig_polarity = 0;
dss_mgr_set_lcd_config(channel, &dsi->mgr_config);
return 0;
err1:
if (dsi->mode == OMAP_DSS_DSI_CMD_MODE)
dss_mgr_unregister_framedone_handler(channel,
dsi_framedone_irq_callback, dsidev);
err:
dss_select_lcd_clk_source(channel, OMAP_DSS_CLK_SRC_FCK);
return r;
}
static void dsi_display_uninit_dispc(struct platform_device *dsidev,
enum omap_channel channel)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
if (dsi->mode == OMAP_DSS_DSI_CMD_MODE)
dss_mgr_unregister_framedone_handler(channel,
dsi_framedone_irq_callback, dsidev);
dss_select_lcd_clk_source(channel, OMAP_DSS_CLK_SRC_FCK);
}
static int dsi_configure_dsi_clocks(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct dss_pll_clock_info cinfo;
int r;
cinfo = dsi->user_dsi_cinfo;
r = dss_pll_set_config(&dsi->pll, &cinfo);
if (r) {
DSSERR("Failed to set dsi clocks\n");
return r;
}
return 0;
}
static int dsi_display_init_dsi(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int r;
r = dss_pll_enable(&dsi->pll);
if (r)
goto err0;
r = dsi_configure_dsi_clocks(dsidev);
if (r)
goto err1;
dss_select_dsi_clk_source(dsi->module_id, dsi->module_id == 0 ?
OMAP_DSS_CLK_SRC_DSI_PLL_HSDIV_DSI :
OMAP_DSS_CLK_SRC_DSI2_PLL_HSDIV_DSI);
DSSDBG("PLL OK\n");
r = dsi_cio_init(dsidev);
if (r)
goto err2;
_dsi_print_reset_status(dsidev);
dsi_proto_timings(dsidev);
dsi_set_lp_clk_divisor(dsidev);
if (1)
_dsi_print_reset_status(dsidev);
r = dsi_proto_config(dsidev);
if (r)
goto err3;
dsi_vc_enable(dsidev, 0, 1);
dsi_vc_enable(dsidev, 1, 1);
dsi_vc_enable(dsidev, 2, 1);
dsi_vc_enable(dsidev, 3, 1);
dsi_if_enable(dsidev, 1);
dsi_force_tx_stop_mode_io(dsidev);
return 0;
err3:
dsi_cio_uninit(dsidev);
err2:
dss_select_dsi_clk_source(dsi->module_id, OMAP_DSS_CLK_SRC_FCK);
err1:
dss_pll_disable(&dsi->pll);
err0:
return r;
}
static void dsi_display_uninit_dsi(struct platform_device *dsidev,
bool disconnect_lanes, bool enter_ulps)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
if (enter_ulps && !dsi->ulps_enabled)
dsi_enter_ulps(dsidev);
dsi_if_enable(dsidev, 0);
dsi_vc_enable(dsidev, 0, 0);
dsi_vc_enable(dsidev, 1, 0);
dsi_vc_enable(dsidev, 2, 0);
dsi_vc_enable(dsidev, 3, 0);
dss_select_dsi_clk_source(dsi->module_id, OMAP_DSS_CLK_SRC_FCK);
dsi_cio_uninit(dsidev);
dsi_pll_uninit(dsidev, disconnect_lanes);
}
static int dsi_display_enable(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int r = 0;
DSSDBG("dsi_display_enable\n");
WARN_ON(!dsi_bus_is_locked(dsidev));
mutex_lock(&dsi->lock);
r = dsi_runtime_get(dsidev);
if (r)
goto err_get_dsi;
_dsi_initialize_irq(dsidev);
r = dsi_display_init_dsi(dsidev);
if (r)
goto err_init_dsi;
mutex_unlock(&dsi->lock);
return 0;
err_init_dsi:
dsi_runtime_put(dsidev);
err_get_dsi:
mutex_unlock(&dsi->lock);
DSSDBG("dsi_display_enable FAILED\n");
return r;
}
static void dsi_display_disable(struct omap_dss_device *dssdev,
bool disconnect_lanes, bool enter_ulps)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
DSSDBG("dsi_display_disable\n");
WARN_ON(!dsi_bus_is_locked(dsidev));
mutex_lock(&dsi->lock);
dsi_sync_vc(dsidev, 0);
dsi_sync_vc(dsidev, 1);
dsi_sync_vc(dsidev, 2);
dsi_sync_vc(dsidev, 3);
dsi_display_uninit_dsi(dsidev, disconnect_lanes, enter_ulps);
dsi_runtime_put(dsidev);
mutex_unlock(&dsi->lock);
}
static int dsi_enable_te(struct omap_dss_device *dssdev, bool enable)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
dsi->te_enabled = enable;
return 0;
}
static void print_dsi_vm(const char *str,
const struct omap_dss_dsi_videomode_timings *t)
{
unsigned long byteclk = t->hsclk / 4;
int bl, wc, pps, tot;
wc = DIV_ROUND_UP(t->hact * t->bitspp, 8);
pps = DIV_ROUND_UP(wc + 6, t->ndl);
bl = t->hss + t->hsa + t->hse + t->hbp + t->hfp;
tot = bl + pps;
#define TO_DSI_T(x) ((u32)div64_u64((u64)x * 1000000000llu, byteclk))
pr_debug("%s bck %lu, %u/%u/%u/%u/%u/%u = %u+%u = %u, "
"%u/%u/%u/%u/%u/%u = %u + %u = %u\n",
str,
byteclk,
t->hss, t->hsa, t->hse, t->hbp, pps, t->hfp,
bl, pps, tot,
TO_DSI_T(t->hss),
TO_DSI_T(t->hsa),
TO_DSI_T(t->hse),
TO_DSI_T(t->hbp),
TO_DSI_T(pps),
TO_DSI_T(t->hfp),
TO_DSI_T(bl),
TO_DSI_T(pps),
TO_DSI_T(tot));
#undef TO_DSI_T
}
static void print_dispc_vm(const char *str, const struct omap_video_timings *t)
{
unsigned long pck = t->pixelclock;
int hact, bl, tot;
hact = t->x_res;
bl = t->hsw + t->hbp + t->hfp;
tot = hact + bl;
#define TO_DISPC_T(x) ((u32)div64_u64((u64)x * 1000000000llu, pck))
pr_debug("%s pck %lu, %u/%u/%u/%u = %u+%u = %u, "
"%u/%u/%u/%u = %u + %u = %u\n",
str,
pck,
t->hsw, t->hbp, hact, t->hfp,
bl, hact, tot,
TO_DISPC_T(t->hsw),
TO_DISPC_T(t->hbp),
TO_DISPC_T(hact),
TO_DISPC_T(t->hfp),
TO_DISPC_T(bl),
TO_DISPC_T(hact),
TO_DISPC_T(tot));
#undef TO_DISPC_T
}
static void print_dsi_dispc_vm(const char *str,
const struct omap_dss_dsi_videomode_timings *t)
{
struct omap_video_timings vm = { 0 };
unsigned long byteclk = t->hsclk / 4;
unsigned long pck;
u64 dsi_tput;
int dsi_hact, dsi_htot;
dsi_tput = (u64)byteclk * t->ndl * 8;
pck = (u32)div64_u64(dsi_tput, t->bitspp);
dsi_hact = DIV_ROUND_UP(DIV_ROUND_UP(t->hact * t->bitspp, 8) + 6, t->ndl);
dsi_htot = t->hss + t->hsa + t->hse + t->hbp + dsi_hact + t->hfp;
vm.pixelclock = pck;
vm.hsw = div64_u64((u64)(t->hsa + t->hse) * pck, byteclk);
vm.hbp = div64_u64((u64)t->hbp * pck, byteclk);
vm.hfp = div64_u64((u64)t->hfp * pck, byteclk);
vm.x_res = t->hact;
print_dispc_vm(str, &vm);
}
static bool dsi_cm_calc_dispc_cb(int lckd, int pckd, unsigned long lck,
unsigned long pck, void *data)
{
struct dsi_clk_calc_ctx *ctx = data;
struct omap_video_timings *t = &ctx->dispc_vm;
ctx->dispc_cinfo.lck_div = lckd;
ctx->dispc_cinfo.pck_div = pckd;
ctx->dispc_cinfo.lck = lck;
ctx->dispc_cinfo.pck = pck;
*t = *ctx->config->timings;
t->pixelclock = pck;
t->x_res = ctx->config->timings->x_res;
t->y_res = ctx->config->timings->y_res;
t->hsw = t->hfp = t->hbp = t->vsw = 1;
t->vfp = t->vbp = 0;
return true;
}
static bool dsi_cm_calc_hsdiv_cb(int m_dispc, unsigned long dispc,
void *data)
{
struct dsi_clk_calc_ctx *ctx = data;
ctx->dsi_cinfo.mX[HSDIV_DISPC] = m_dispc;
ctx->dsi_cinfo.clkout[HSDIV_DISPC] = dispc;
return dispc_div_calc(dispc, ctx->req_pck_min, ctx->req_pck_max,
dsi_cm_calc_dispc_cb, ctx);
}
static bool dsi_cm_calc_pll_cb(int n, int m, unsigned long fint,
unsigned long clkdco, void *data)
{
struct dsi_clk_calc_ctx *ctx = data;
ctx->dsi_cinfo.n = n;
ctx->dsi_cinfo.m = m;
ctx->dsi_cinfo.fint = fint;
ctx->dsi_cinfo.clkdco = clkdco;
return dss_pll_hsdiv_calc(ctx->pll, clkdco, ctx->req_pck_min,
dss_feat_get_param_max(FEAT_PARAM_DSS_FCK),
dsi_cm_calc_hsdiv_cb, ctx);
}
static bool dsi_cm_calc(struct dsi_data *dsi,
const struct omap_dss_dsi_config *cfg,
struct dsi_clk_calc_ctx *ctx)
{
unsigned long clkin;
int bitspp, ndl;
unsigned long pll_min, pll_max;
unsigned long pck, txbyteclk;
clkin = clk_get_rate(dsi->pll.clkin);
bitspp = dsi_get_pixel_size(cfg->pixel_format);
ndl = dsi->num_lanes_used - 1;
pck = cfg->timings->pixelclock;
pck = pck * 3 / 2;
txbyteclk = pck * bitspp / 8 / ndl;
memset(ctx, 0, sizeof(*ctx));
ctx->dsidev = dsi->pdev;
ctx->pll = &dsi->pll;
ctx->config = cfg;
ctx->req_pck_min = pck;
ctx->req_pck_nom = pck;
ctx->req_pck_max = pck * 3 / 2;
pll_min = max(cfg->hs_clk_min * 4, txbyteclk * 4 * 4);
pll_max = cfg->hs_clk_max * 4;
return dss_pll_calc(ctx->pll, clkin,
pll_min, pll_max,
dsi_cm_calc_pll_cb, ctx);
}
static bool dsi_vm_calc_blanking(struct dsi_clk_calc_ctx *ctx)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(ctx->dsidev);
const struct omap_dss_dsi_config *cfg = ctx->config;
int bitspp = dsi_get_pixel_size(cfg->pixel_format);
int ndl = dsi->num_lanes_used - 1;
unsigned long hsclk = ctx->dsi_cinfo.clkdco / 4;
unsigned long byteclk = hsclk / 4;
unsigned long dispc_pck, req_pck_min, req_pck_nom, req_pck_max;
int xres;
int panel_htot, panel_hbl;
int dispc_htot, dispc_hbl;
int dsi_htot, dsi_hact, dsi_hbl, hss, hse;
int hfp, hsa, hbp;
const struct omap_video_timings *req_vm;
struct omap_video_timings *dispc_vm;
struct omap_dss_dsi_videomode_timings *dsi_vm;
u64 dsi_tput, dispc_tput;
dsi_tput = (u64)byteclk * ndl * 8;
req_vm = cfg->timings;
req_pck_min = ctx->req_pck_min;
req_pck_max = ctx->req_pck_max;
req_pck_nom = ctx->req_pck_nom;
dispc_pck = ctx->dispc_cinfo.pck;
dispc_tput = (u64)dispc_pck * bitspp;
xres = req_vm->x_res;
panel_hbl = req_vm->hfp + req_vm->hbp + req_vm->hsw;
panel_htot = xres + panel_hbl;
dsi_hact = DIV_ROUND_UP(DIV_ROUND_UP(xres * bitspp, 8) + 6, ndl);
if (dsi->line_buffer_size < xres * bitspp / 8) {
if (dispc_tput != dsi_tput)
return false;
} else {
if (dispc_tput < dsi_tput)
return false;
}
if (dsi_tput < (u64)bitspp * req_pck_min)
return false;
if (cfg->trans_mode != OMAP_DSS_DSI_BURST_MODE) {
if (dsi_tput > (u64)bitspp * req_pck_max)
return false;
}
hss = DIV_ROUND_UP(4, ndl);
if (cfg->trans_mode == OMAP_DSS_DSI_PULSE_MODE) {
if (ndl == 3 && req_vm->hsw == 0)
hse = 1;
else
hse = DIV_ROUND_UP(4, ndl);
} else {
hse = 0;
}
dsi_htot = div64_u64((u64)panel_htot * byteclk, req_pck_nom);
if (dsi_htot < hss + hse + dsi_hact)
return false;
dsi_hbl = dsi_htot - dsi_hact;
dispc_htot = div64_u64((u64)dsi_htot * dispc_pck, byteclk);
if ((u64)dsi_htot * dispc_pck != (u64)dispc_htot * byteclk)
return false;
dispc_hbl = dispc_htot - xres;
dsi_vm = &ctx->dsi_vm;
memset(dsi_vm, 0, sizeof(*dsi_vm));
dsi_vm->hsclk = hsclk;
dsi_vm->ndl = ndl;
dsi_vm->bitspp = bitspp;
if (cfg->trans_mode != OMAP_DSS_DSI_PULSE_MODE) {
hsa = 0;
} else if (ndl == 3 && req_vm->hsw == 0) {
hsa = 0;
} else {
hsa = div64_u64((u64)req_vm->hsw * byteclk, req_pck_nom);
hsa = max(hsa - hse, 1);
}
hbp = div64_u64((u64)req_vm->hbp * byteclk, req_pck_nom);
hbp = max(hbp, 1);
hfp = dsi_hbl - (hss + hsa + hse + hbp);
if (hfp < 1) {
int t;
t = 1 - hfp;
hbp = max(hbp - t, 1);
hfp = dsi_hbl - (hss + hsa + hse + hbp);
if (hfp < 1 && hsa > 0) {
t = 1 - hfp;
hsa = max(hsa - t, 1);
hfp = dsi_hbl - (hss + hsa + hse + hbp);
}
}
if (hfp < 1)
return false;
dsi_vm->hss = hss;
dsi_vm->hsa = hsa;
dsi_vm->hse = hse;
dsi_vm->hbp = hbp;
dsi_vm->hact = xres;
dsi_vm->hfp = hfp;
dsi_vm->vsa = req_vm->vsw;
dsi_vm->vbp = req_vm->vbp;
dsi_vm->vact = req_vm->y_res;
dsi_vm->vfp = req_vm->vfp;
dsi_vm->trans_mode = cfg->trans_mode;
dsi_vm->blanking_mode = 0;
dsi_vm->hsa_blanking_mode = 1;
dsi_vm->hfp_blanking_mode = 1;
dsi_vm->hbp_blanking_mode = 1;
dsi_vm->ddr_clk_always_on = cfg->ddr_clk_always_on;
dsi_vm->window_sync = 4;
dispc_vm = &ctx->dispc_vm;
*dispc_vm = *req_vm;
dispc_vm->pixelclock = dispc_pck;
if (cfg->trans_mode == OMAP_DSS_DSI_PULSE_MODE) {
hsa = div64_u64((u64)req_vm->hsw * dispc_pck,
req_pck_nom);
hsa = max(hsa, 1);
} else {
hsa = 1;
}
hbp = div64_u64((u64)req_vm->hbp * dispc_pck, req_pck_nom);
hbp = max(hbp, 1);
hfp = dispc_hbl - hsa - hbp;
if (hfp < 1) {
int t;
t = 1 - hfp;
hbp = max(hbp - t, 1);
hfp = dispc_hbl - hsa - hbp;
if (hfp < 1) {
t = 1 - hfp;
hsa = max(hsa - t, 1);
hfp = dispc_hbl - hsa - hbp;
}
}
if (hfp < 1)
return false;
dispc_vm->hfp = hfp;
dispc_vm->hsw = hsa;
dispc_vm->hbp = hbp;
return true;
}
static bool dsi_vm_calc_dispc_cb(int lckd, int pckd, unsigned long lck,
unsigned long pck, void *data)
{
struct dsi_clk_calc_ctx *ctx = data;
ctx->dispc_cinfo.lck_div = lckd;
ctx->dispc_cinfo.pck_div = pckd;
ctx->dispc_cinfo.lck = lck;
ctx->dispc_cinfo.pck = pck;
if (dsi_vm_calc_blanking(ctx) == false)
return false;
#ifdef PRINT_VERBOSE_VM_TIMINGS
print_dispc_vm("dispc", &ctx->dispc_vm);
print_dsi_vm("dsi ", &ctx->dsi_vm);
print_dispc_vm("req ", ctx->config->timings);
print_dsi_dispc_vm("act ", &ctx->dsi_vm);
#endif
return true;
}
static bool dsi_vm_calc_hsdiv_cb(int m_dispc, unsigned long dispc,
void *data)
{
struct dsi_clk_calc_ctx *ctx = data;
unsigned long pck_max;
ctx->dsi_cinfo.mX[HSDIV_DISPC] = m_dispc;
ctx->dsi_cinfo.clkout[HSDIV_DISPC] = dispc;
if (ctx->config->trans_mode == OMAP_DSS_DSI_BURST_MODE)
pck_max = ctx->req_pck_max + 10000000;
else
pck_max = ctx->req_pck_max;
return dispc_div_calc(dispc, ctx->req_pck_min, pck_max,
dsi_vm_calc_dispc_cb, ctx);
}
static bool dsi_vm_calc_pll_cb(int n, int m, unsigned long fint,
unsigned long clkdco, void *data)
{
struct dsi_clk_calc_ctx *ctx = data;
ctx->dsi_cinfo.n = n;
ctx->dsi_cinfo.m = m;
ctx->dsi_cinfo.fint = fint;
ctx->dsi_cinfo.clkdco = clkdco;
return dss_pll_hsdiv_calc(ctx->pll, clkdco, ctx->req_pck_min,
dss_feat_get_param_max(FEAT_PARAM_DSS_FCK),
dsi_vm_calc_hsdiv_cb, ctx);
}
static bool dsi_vm_calc(struct dsi_data *dsi,
const struct omap_dss_dsi_config *cfg,
struct dsi_clk_calc_ctx *ctx)
{
const struct omap_video_timings *t = cfg->timings;
unsigned long clkin;
unsigned long pll_min;
unsigned long pll_max;
int ndl = dsi->num_lanes_used - 1;
int bitspp = dsi_get_pixel_size(cfg->pixel_format);
unsigned long byteclk_min;
clkin = clk_get_rate(dsi->pll.clkin);
memset(ctx, 0, sizeof(*ctx));
ctx->dsidev = dsi->pdev;
ctx->pll = &dsi->pll;
ctx->config = cfg;
ctx->req_pck_min = t->pixelclock - 1000;
ctx->req_pck_nom = t->pixelclock;
ctx->req_pck_max = t->pixelclock + 1000;
byteclk_min = div64_u64((u64)ctx->req_pck_min * bitspp, ndl * 8);
pll_min = max(cfg->hs_clk_min * 4, byteclk_min * 4 * 4);
if (cfg->trans_mode == OMAP_DSS_DSI_BURST_MODE) {
pll_max = cfg->hs_clk_max * 4;
} else {
unsigned long byteclk_max;
byteclk_max = div64_u64((u64)ctx->req_pck_max * bitspp,
ndl * 8);
pll_max = byteclk_max * 4 * 4;
}
return dss_pll_calc(ctx->pll, clkin,
pll_min, pll_max,
dsi_vm_calc_pll_cb, ctx);
}
static int dsi_set_config(struct omap_dss_device *dssdev,
const struct omap_dss_dsi_config *config)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct dsi_clk_calc_ctx ctx;
bool ok;
int r;
mutex_lock(&dsi->lock);
dsi->pix_fmt = config->pixel_format;
dsi->mode = config->mode;
if (config->mode == OMAP_DSS_DSI_VIDEO_MODE)
ok = dsi_vm_calc(dsi, config, &ctx);
else
ok = dsi_cm_calc(dsi, config, &ctx);
if (!ok) {
DSSERR("failed to find suitable DSI clock settings\n");
r = -EINVAL;
goto err;
}
dsi_pll_calc_dsi_fck(&ctx.dsi_cinfo);
r = dsi_lp_clock_calc(ctx.dsi_cinfo.clkout[HSDIV_DSI],
config->lp_clk_min, config->lp_clk_max, &dsi->user_lp_cinfo);
if (r) {
DSSERR("failed to find suitable DSI LP clock settings\n");
goto err;
}
dsi->user_dsi_cinfo = ctx.dsi_cinfo;
dsi->user_dispc_cinfo = ctx.dispc_cinfo;
dsi->timings = ctx.dispc_vm;
dsi->vm_timings = ctx.dsi_vm;
mutex_unlock(&dsi->lock);
return 0;
err:
mutex_unlock(&dsi->lock);
return r;
}
static enum omap_channel dsi_get_channel(int module_id)
{
switch (omapdss_get_version()) {
case OMAPDSS_VER_OMAP24xx:
case OMAPDSS_VER_AM43xx:
DSSWARN("DSI not supported\n");
return OMAP_DSS_CHANNEL_LCD;
case OMAPDSS_VER_OMAP34xx_ES1:
case OMAPDSS_VER_OMAP34xx_ES3:
case OMAPDSS_VER_OMAP3630:
case OMAPDSS_VER_AM35xx:
return OMAP_DSS_CHANNEL_LCD;
case OMAPDSS_VER_OMAP4430_ES1:
case OMAPDSS_VER_OMAP4430_ES2:
case OMAPDSS_VER_OMAP4:
switch (module_id) {
case 0:
return OMAP_DSS_CHANNEL_LCD;
case 1:
return OMAP_DSS_CHANNEL_LCD2;
default:
DSSWARN("unsupported module id\n");
return OMAP_DSS_CHANNEL_LCD;
}
case OMAPDSS_VER_OMAP5:
switch (module_id) {
case 0:
return OMAP_DSS_CHANNEL_LCD;
case 1:
return OMAP_DSS_CHANNEL_LCD3;
default:
DSSWARN("unsupported module id\n");
return OMAP_DSS_CHANNEL_LCD;
}
default:
DSSWARN("unsupported DSS version\n");
return OMAP_DSS_CHANNEL_LCD;
}
}
static int dsi_request_vc(struct omap_dss_device *dssdev, int *channel)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int i;
for (i = 0; i < ARRAY_SIZE(dsi->vc); i++) {
if (!dsi->vc[i].dssdev) {
dsi->vc[i].dssdev = dssdev;
*channel = i;
return 0;
}
}
DSSERR("cannot get VC for display %s", dssdev->name);
return -ENOSPC;
}
static int dsi_set_vc_id(struct omap_dss_device *dssdev, int channel, int vc_id)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
if (vc_id < 0 || vc_id > 3) {
DSSERR("VC ID out of range\n");
return -EINVAL;
}
if (channel < 0 || channel > 3) {
DSSERR("Virtual Channel out of range\n");
return -EINVAL;
}
if (dsi->vc[channel].dssdev != dssdev) {
DSSERR("Virtual Channel not allocated to display %s\n",
dssdev->name);
return -EINVAL;
}
dsi->vc[channel].vc_id = vc_id;
return 0;
}
static void dsi_release_vc(struct omap_dss_device *dssdev, int channel)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
if ((channel >= 0 && channel <= 3) &&
dsi->vc[channel].dssdev == dssdev) {
dsi->vc[channel].dssdev = NULL;
dsi->vc[channel].vc_id = 0;
}
}
static int dsi_get_clocks(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct clk *clk;
clk = devm_clk_get(&dsidev->dev, "fck");
if (IS_ERR(clk)) {
DSSERR("can't get fck\n");
return PTR_ERR(clk);
}
dsi->dss_clk = clk;
return 0;
}
static int dsi_connect(struct omap_dss_device *dssdev,
struct omap_dss_device *dst)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
enum omap_channel dispc_channel = dssdev->dispc_channel;
int r;
r = dsi_regulator_init(dsidev);
if (r)
return r;
r = dss_mgr_connect(dispc_channel, dssdev);
if (r)
return r;
r = omapdss_output_set_device(dssdev, dst);
if (r) {
DSSERR("failed to connect output to new device: %s\n",
dssdev->name);
dss_mgr_disconnect(dispc_channel, dssdev);
return r;
}
return 0;
}
static void dsi_disconnect(struct omap_dss_device *dssdev,
struct omap_dss_device *dst)
{
enum omap_channel dispc_channel = dssdev->dispc_channel;
WARN_ON(dst != dssdev->dst);
if (dst != dssdev->dst)
return;
omapdss_output_unset_device(dssdev);
dss_mgr_disconnect(dispc_channel, dssdev);
}
static void dsi_init_output(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct omap_dss_device *out = &dsi->output;
out->dev = &dsidev->dev;
out->id = dsi->module_id == 0 ?
OMAP_DSS_OUTPUT_DSI1 : OMAP_DSS_OUTPUT_DSI2;
out->output_type = OMAP_DISPLAY_TYPE_DSI;
out->name = dsi->module_id == 0 ? "dsi.0" : "dsi.1";
out->dispc_channel = dsi_get_channel(dsi->module_id);
out->ops.dsi = &dsi_ops;
out->owner = THIS_MODULE;
omapdss_register_output(out);
}
static void dsi_uninit_output(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct omap_dss_device *out = &dsi->output;
omapdss_unregister_output(out);
}
static int dsi_probe_of(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct dsi_data *dsi = dsi_get_dsidrv_data(pdev);
struct property *prop;
u32 lane_arr[10];
int len, num_pins;
int r, i;
struct device_node *ep;
struct omap_dsi_pin_config pin_cfg;
ep = omapdss_of_get_first_endpoint(node);
if (!ep)
return 0;
prop = of_find_property(ep, "lanes", &len);
if (prop == NULL) {
dev_err(&pdev->dev, "failed to find lane data\n");
r = -EINVAL;
goto err;
}
num_pins = len / sizeof(u32);
if (num_pins < 4 || num_pins % 2 != 0 ||
num_pins > dsi->num_lanes_supported * 2) {
dev_err(&pdev->dev, "bad number of lanes\n");
r = -EINVAL;
goto err;
}
r = of_property_read_u32_array(ep, "lanes", lane_arr, num_pins);
if (r) {
dev_err(&pdev->dev, "failed to read lane data\n");
goto err;
}
pin_cfg.num_pins = num_pins;
for (i = 0; i < num_pins; ++i)
pin_cfg.pins[i] = (int)lane_arr[i];
r = dsi_configure_pins(&dsi->output, &pin_cfg);
if (r) {
dev_err(&pdev->dev, "failed to configure pins");
goto err;
}
of_node_put(ep);
return 0;
err:
of_node_put(ep);
return r;
}
static int dsi_init_pll_data(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct dss_pll *pll = &dsi->pll;
struct clk *clk;
int r;
clk = devm_clk_get(&dsidev->dev, "sys_clk");
if (IS_ERR(clk)) {
DSSERR("can't get sys_clk\n");
return PTR_ERR(clk);
}
pll->name = dsi->module_id == 0 ? "dsi0" : "dsi1";
pll->id = dsi->module_id == 0 ? DSS_PLL_DSI1 : DSS_PLL_DSI2;
pll->clkin = clk;
pll->base = dsi->pll_base;
switch (omapdss_get_version()) {
case OMAPDSS_VER_OMAP34xx_ES1:
case OMAPDSS_VER_OMAP34xx_ES3:
case OMAPDSS_VER_OMAP3630:
case OMAPDSS_VER_AM35xx:
pll->hw = &dss_omap3_dsi_pll_hw;
break;
case OMAPDSS_VER_OMAP4430_ES1:
case OMAPDSS_VER_OMAP4430_ES2:
case OMAPDSS_VER_OMAP4:
pll->hw = &dss_omap4_dsi_pll_hw;
break;
case OMAPDSS_VER_OMAP5:
pll->hw = &dss_omap5_dsi_pll_hw;
break;
default:
return -ENODEV;
}
pll->ops = &dsi_pll_ops;
r = dss_pll_register(pll);
if (r)
return r;
return 0;
}
static int dsi_bind(struct device *dev, struct device *master, void *data)
{
struct platform_device *dsidev = to_platform_device(dev);
u32 rev;
int r, i;
struct dsi_data *dsi;
struct resource *dsi_mem;
struct resource *res;
struct resource temp_res;
dsi = devm_kzalloc(&dsidev->dev, sizeof(*dsi), GFP_KERNEL);
if (!dsi)
return -ENOMEM;
dsi->pdev = dsidev;
dev_set_drvdata(&dsidev->dev, dsi);
spin_lock_init(&dsi->irq_lock);
spin_lock_init(&dsi->errors_lock);
dsi->errors = 0;
#ifdef CONFIG_OMAP2_DSS_COLLECT_IRQ_STATS
spin_lock_init(&dsi->irq_stats_lock);
dsi->irq_stats.last_reset = jiffies;
#endif
mutex_init(&dsi->lock);
sema_init(&dsi->bus_lock, 1);
INIT_DEFERRABLE_WORK(&dsi->framedone_timeout_work,
dsi_framedone_timeout_work_callback);
#ifdef DSI_CATCH_MISSING_TE
init_timer(&dsi->te_timer);
dsi->te_timer.function = dsi_te_timeout;
dsi->te_timer.data = 0;
#endif
res = platform_get_resource_byname(dsidev, IORESOURCE_MEM, "proto");
if (!res) {
res = platform_get_resource(dsidev, IORESOURCE_MEM, 0);
if (!res) {
DSSERR("can't get IORESOURCE_MEM DSI\n");
return -EINVAL;
}
temp_res.start = res->start;
temp_res.end = temp_res.start + DSI_PROTO_SZ - 1;
res = &temp_res;
}
dsi_mem = res;
dsi->proto_base = devm_ioremap(&dsidev->dev, res->start,
resource_size(res));
if (!dsi->proto_base) {
DSSERR("can't ioremap DSI protocol engine\n");
return -ENOMEM;
}
res = platform_get_resource_byname(dsidev, IORESOURCE_MEM, "phy");
if (!res) {
res = platform_get_resource(dsidev, IORESOURCE_MEM, 0);
if (!res) {
DSSERR("can't get IORESOURCE_MEM DSI\n");
return -EINVAL;
}
temp_res.start = res->start + DSI_PHY_OFFSET;
temp_res.end = temp_res.start + DSI_PHY_SZ - 1;
res = &temp_res;
}
dsi->phy_base = devm_ioremap(&dsidev->dev, res->start,
resource_size(res));
if (!dsi->proto_base) {
DSSERR("can't ioremap DSI PHY\n");
return -ENOMEM;
}
res = platform_get_resource_byname(dsidev, IORESOURCE_MEM, "pll");
if (!res) {
res = platform_get_resource(dsidev, IORESOURCE_MEM, 0);
if (!res) {
DSSERR("can't get IORESOURCE_MEM DSI\n");
return -EINVAL;
}
temp_res.start = res->start + DSI_PLL_OFFSET;
temp_res.end = temp_res.start + DSI_PLL_SZ - 1;
res = &temp_res;
}
dsi->pll_base = devm_ioremap(&dsidev->dev, res->start,
resource_size(res));
if (!dsi->proto_base) {
DSSERR("can't ioremap DSI PLL\n");
return -ENOMEM;
}
dsi->irq = platform_get_irq(dsi->pdev, 0);
if (dsi->irq < 0) {
DSSERR("platform_get_irq failed\n");
return -ENODEV;
}
r = devm_request_irq(&dsidev->dev, dsi->irq, omap_dsi_irq_handler,
IRQF_SHARED, dev_name(&dsidev->dev), dsi->pdev);
if (r < 0) {
DSSERR("request_irq failed\n");
return r;
}
if (dsidev->dev.of_node) {
const struct of_device_id *match;
const struct dsi_module_id_data *d;
match = of_match_node(dsi_of_match, dsidev->dev.of_node);
if (!match) {
DSSERR("unsupported DSI module\n");
return -ENODEV;
}
d = match->data;
while (d->address != 0 && d->address != dsi_mem->start)
d++;
if (d->address == 0) {
DSSERR("unsupported DSI module\n");
return -ENODEV;
}
dsi->module_id = d->id;
} else {
dsi->module_id = dsidev->id;
}
for (i = 0; i < ARRAY_SIZE(dsi->vc); i++) {
dsi->vc[i].source = DSI_VC_SOURCE_L4;
dsi->vc[i].dssdev = NULL;
dsi->vc[i].vc_id = 0;
}
r = dsi_get_clocks(dsidev);
if (r)
return r;
dsi_init_pll_data(dsidev);
pm_runtime_enable(&dsidev->dev);
r = dsi_runtime_get(dsidev);
if (r)
goto err_runtime_get;
rev = dsi_read_reg(dsidev, DSI_REVISION);
dev_dbg(&dsidev->dev, "OMAP DSI rev %d.%d\n",
FLD_GET(rev, 7, 4), FLD_GET(rev, 3, 0));
if (dss_has_feature(FEAT_DSI_GNQ))
dsi->num_lanes_supported = 1 + REG_GET(dsidev, DSI_GNQ, 11, 9);
else
dsi->num_lanes_supported = 3;
dsi->line_buffer_size = dsi_get_line_buf_size(dsidev);
dsi_init_output(dsidev);
if (dsidev->dev.of_node) {
r = dsi_probe_of(dsidev);
if (r) {
DSSERR("Invalid DSI DT data\n");
goto err_probe_of;
}
r = of_platform_populate(dsidev->dev.of_node, NULL, NULL,
&dsidev->dev);
if (r)
DSSERR("Failed to populate DSI child devices: %d\n", r);
}
dsi_runtime_put(dsidev);
if (dsi->module_id == 0)
dss_debugfs_create_file("dsi1_regs", dsi1_dump_regs);
else if (dsi->module_id == 1)
dss_debugfs_create_file("dsi2_regs", dsi2_dump_regs);
#ifdef CONFIG_OMAP2_DSS_COLLECT_IRQ_STATS
if (dsi->module_id == 0)
dss_debugfs_create_file("dsi1_irqs", dsi1_dump_irqs);
else if (dsi->module_id == 1)
dss_debugfs_create_file("dsi2_irqs", dsi2_dump_irqs);
#endif
return 0;
err_probe_of:
dsi_uninit_output(dsidev);
dsi_runtime_put(dsidev);
err_runtime_get:
pm_runtime_disable(&dsidev->dev);
return r;
}
static void dsi_unbind(struct device *dev, struct device *master, void *data)
{
struct platform_device *dsidev = to_platform_device(dev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
of_platform_depopulate(&dsidev->dev);
WARN_ON(dsi->scp_clk_refcount > 0);
dss_pll_unregister(&dsi->pll);
dsi_uninit_output(dsidev);
pm_runtime_disable(&dsidev->dev);
if (dsi->vdds_dsi_reg != NULL && dsi->vdds_dsi_enabled) {
regulator_disable(dsi->vdds_dsi_reg);
dsi->vdds_dsi_enabled = false;
}
}
static int dsi_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &dsi_component_ops);
}
static int dsi_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &dsi_component_ops);
return 0;
}
static int dsi_runtime_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct dsi_data *dsi = dsi_get_dsidrv_data(pdev);
dsi->is_enabled = false;
smp_wmb();
synchronize_irq(dsi->irq);
dispc_runtime_put();
return 0;
}
static int dsi_runtime_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct dsi_data *dsi = dsi_get_dsidrv_data(pdev);
int r;
r = dispc_runtime_get();
if (r)
return r;
dsi->is_enabled = true;
smp_wmb();
return 0;
}
int __init dsi_init_platform_driver(void)
{
return platform_driver_register(&omap_dsihw_driver);
}
void dsi_uninit_platform_driver(void)
{
platform_driver_unregister(&omap_dsihw_driver);
}
