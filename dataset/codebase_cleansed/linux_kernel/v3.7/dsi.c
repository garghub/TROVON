static inline struct dsi_data *dsi_get_dsidrv_data(struct platform_device *dsidev)
{
return dev_get_drvdata(&dsidev->dev);
}
static inline struct platform_device *dsi_get_dsidev_from_dssdev(struct omap_dss_device *dssdev)
{
return dssdev->output->pdev;
}
struct platform_device *dsi_get_dsidev_from_id(int module)
{
struct omap_dss_output *out;
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
return out ? out->pdev : NULL;
}
static inline void dsi_write_reg(struct platform_device *dsidev,
const struct dsi_reg idx, u32 val)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
__raw_writel(val, dsi->base + idx.idx);
}
static inline u32 dsi_read_reg(struct platform_device *dsidev,
const struct dsi_reg idx)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
return __raw_readl(dsi->base + idx.idx);
}
void dsi_bus_lock(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
down(&dsi->bus_lock);
}
void dsi_bus_unlock(struct omap_dss_device *dssdev)
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
#ifndef VERBOSE_IRQ
if ((status & ~DSI_IRQ_CHANNEL_MASK) == 0)
return;
#endif
printk(KERN_DEBUG "DSI IRQ: 0x%x: ", status);
#define PIS(x) \
if (status & DSI_IRQ_##x) \
printk(#x " ");
#ifdef VERBOSE_IRQ
PIS(VC0);
PIS(VC1);
PIS(VC2);
PIS(VC3);
#endif
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
printk("\n");
}
static void print_irq_status_vc(int channel, u32 status)
{
if (status == 0)
return;
#ifndef VERBOSE_IRQ
if ((status & ~DSI_VC_IRQ_PACKET_SENT) == 0)
return;
#endif
printk(KERN_DEBUG "DSI VC(%d) IRQ 0x%x: ", channel, status);
#define PIS(x) \
if (status & DSI_VC_IRQ_##x) \
printk(#x " ");
PIS(CS);
PIS(ECC_CORR);
#ifdef VERBOSE_IRQ
PIS(PACKET_SENT);
#endif
PIS(FIFO_TX_OVF);
PIS(FIFO_RX_OVF);
PIS(BTA);
PIS(ECC_NO_CORR);
PIS(FIFO_TX_UDF);
PIS(PP_BUSY_CHANGE);
#undef PIS
printk("\n");
}
static void print_irq_status_cio(u32 status)
{
if (status == 0)
return;
printk(KERN_DEBUG "DSI CIO IRQ 0x%x: ", status);
#define PIS(x) \
if (status & DSI_CIO_IRQ_##x) \
printk(#x " ");
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
printk("\n");
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
int dsi_runtime_get(struct platform_device *dsidev)
{
int r;
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
DSSDBG("dsi_runtime_get\n");
r = pm_runtime_get_sync(&dsi->pdev->dev);
WARN_ON(r < 0);
return r < 0 ? r : 0;
}
void dsi_runtime_put(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int r;
DSSDBG("dsi_runtime_put\n");
r = pm_runtime_put_sync(&dsi->pdev->dev);
WARN_ON(r < 0 && r != -ENOSYS);
}
static inline void dsi_enable_pll_clock(struct platform_device *dsidev,
bool enable)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
if (enable)
clk_prepare_enable(dsi->sys_clk);
else
clk_disable_unprepare(dsi->sys_clk);
if (enable && dsi->pll_locked) {
if (wait_for_bit_change(dsidev, DSI_PLL_STATUS, 1, 1) != 1)
DSSERR("cannot lock PLL when enabling clocks\n");
}
}
static void _dsi_print_reset_status(struct platform_device *dsidev)
{
u32 l;
int b0, b1, b2;
if (!dss_debug)
return;
l = dsi_read_reg(dsidev, DSI_DSIPHY_CFG5);
printk(KERN_DEBUG "DSI resets: ");
l = dsi_read_reg(dsidev, DSI_PLL_STATUS);
printk("PLL (%d) ", FLD_GET(l, 0, 0));
l = dsi_read_reg(dsidev, DSI_COMPLEXIO_CFG1);
printk("CIO (%d) ", FLD_GET(l, 29, 29));
if (dss_has_feature(FEAT_DSI_REVERSE_TXCLKESC)) {
b0 = 28;
b1 = 27;
b2 = 26;
} else {
b0 = 24;
b1 = 25;
b2 = 26;
}
l = dsi_read_reg(dsidev, DSI_DSIPHY_CFG5);
printk("PHY (%x%x%x, %d, %d, %d)\n",
FLD_GET(l, b0, b0),
FLD_GET(l, b1, b1),
FLD_GET(l, b2, b2),
FLD_GET(l, 29, 29),
FLD_GET(l, 30, 30),
FLD_GET(l, 31, 31));
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
unsigned long dsi_get_pll_hsdiv_dispc_rate(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
return dsi->current_cinfo.dsi_pll_hsdiv_dispc_clk;
}
static unsigned long dsi_get_pll_hsdiv_dsi_rate(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
return dsi->current_cinfo.dsi_pll_hsdiv_dsi_clk;
}
static unsigned long dsi_get_txbyteclkhs(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
return dsi->current_cinfo.clkin4ddr / 16;
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
static int dsi_set_lp_clk_divisor(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
unsigned long dsi_fclk;
unsigned lp_clk_div;
unsigned long lp_clk;
lp_clk_div = dssdev->clocks.dsi.lp_clk_div;
if (lp_clk_div == 0 || lp_clk_div > dsi->lpdiv_max)
return -EINVAL;
dsi_fclk = dsi_fclk_rate(dsidev);
lp_clk = dsi_fclk / 2 / lp_clk_div;
DSSDBG("LP_CLK_DIV %u, LP_CLK %lu\n", lp_clk_div, lp_clk);
dsi->current_cinfo.lp_clk = lp_clk;
dsi->current_cinfo.lp_clk_div = lp_clk_div;
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
static int dsi_calc_clock_rates(struct platform_device *dsidev,
struct dsi_clock_info *cinfo)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
if (cinfo->regn == 0 || cinfo->regn > dsi->regn_max)
return -EINVAL;
if (cinfo->regm == 0 || cinfo->regm > dsi->regm_max)
return -EINVAL;
if (cinfo->regm_dispc > dsi->regm_dispc_max)
return -EINVAL;
if (cinfo->regm_dsi > dsi->regm_dsi_max)
return -EINVAL;
cinfo->clkin = clk_get_rate(dsi->sys_clk);
cinfo->fint = cinfo->clkin / cinfo->regn;
if (cinfo->fint > dsi->fint_max || cinfo->fint < dsi->fint_min)
return -EINVAL;
cinfo->clkin4ddr = 2 * cinfo->regm * cinfo->fint;
if (cinfo->clkin4ddr > 1800 * 1000 * 1000)
return -EINVAL;
if (cinfo->regm_dispc > 0)
cinfo->dsi_pll_hsdiv_dispc_clk =
cinfo->clkin4ddr / cinfo->regm_dispc;
else
cinfo->dsi_pll_hsdiv_dispc_clk = 0;
if (cinfo->regm_dsi > 0)
cinfo->dsi_pll_hsdiv_dsi_clk =
cinfo->clkin4ddr / cinfo->regm_dsi;
else
cinfo->dsi_pll_hsdiv_dsi_clk = 0;
return 0;
}
int dsi_pll_calc_clock_div_pck(struct platform_device *dsidev,
unsigned long req_pck, struct dsi_clock_info *dsi_cinfo,
struct dispc_clock_info *dispc_cinfo)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct dsi_clock_info cur, best;
struct dispc_clock_info best_dispc;
int min_fck_per_pck;
int match = 0;
unsigned long dss_sys_clk, max_dss_fck;
dss_sys_clk = clk_get_rate(dsi->sys_clk);
max_dss_fck = dss_feat_get_param_max(FEAT_PARAM_DSS_FCK);
if (req_pck == dsi->cache_req_pck &&
dsi->cache_cinfo.clkin == dss_sys_clk) {
DSSDBG("DSI clock info found from cache\n");
*dsi_cinfo = dsi->cache_cinfo;
dispc_find_clk_divs(req_pck, dsi_cinfo->dsi_pll_hsdiv_dispc_clk,
dispc_cinfo);
return 0;
}
min_fck_per_pck = CONFIG_OMAP2_DSS_MIN_FCK_PER_PCK;
if (min_fck_per_pck &&
req_pck * min_fck_per_pck > max_dss_fck) {
DSSERR("Requested pixel clock not possible with the current "
"OMAP2_DSS_MIN_FCK_PER_PCK setting. Turning "
"the constraint off.\n");
min_fck_per_pck = 0;
}
DSSDBG("dsi_pll_calc\n");
retry:
memset(&best, 0, sizeof(best));
memset(&best_dispc, 0, sizeof(best_dispc));
memset(&cur, 0, sizeof(cur));
cur.clkin = dss_sys_clk;
for (cur.regn = 1; cur.regn < dsi->regn_max; ++cur.regn) {
cur.fint = cur.clkin / cur.regn;
if (cur.fint > dsi->fint_max || cur.fint < dsi->fint_min)
continue;
for (cur.regm = 1; cur.regm < dsi->regm_max; ++cur.regm) {
unsigned long a, b;
a = 2 * cur.regm * (cur.clkin/1000);
b = cur.regn;
cur.clkin4ddr = a / b * 1000;
if (cur.clkin4ddr > 1800 * 1000 * 1000)
break;
for (cur.regm_dispc = 1; cur.regm_dispc <
dsi->regm_dispc_max; ++cur.regm_dispc) {
struct dispc_clock_info cur_dispc;
cur.dsi_pll_hsdiv_dispc_clk =
cur.clkin4ddr / cur.regm_dispc;
if (cur.dsi_pll_hsdiv_dispc_clk < req_pck)
break;
if (cur.dsi_pll_hsdiv_dispc_clk > max_dss_fck)
continue;
if (min_fck_per_pck &&
cur.dsi_pll_hsdiv_dispc_clk <
req_pck * min_fck_per_pck)
continue;
match = 1;
dispc_find_clk_divs(req_pck,
cur.dsi_pll_hsdiv_dispc_clk,
&cur_dispc);
if (abs(cur_dispc.pck - req_pck) <
abs(best_dispc.pck - req_pck)) {
best = cur;
best_dispc = cur_dispc;
if (cur_dispc.pck == req_pck)
goto found;
}
}
}
}
found:
if (!match) {
if (min_fck_per_pck) {
DSSERR("Could not find suitable clock settings.\n"
"Turning FCK/PCK constraint off and"
"trying again.\n");
min_fck_per_pck = 0;
goto retry;
}
DSSERR("Could not find suitable clock settings.\n");
return -EINVAL;
}
best.regm_dsi = 0;
best.dsi_pll_hsdiv_dsi_clk = 0;
if (dsi_cinfo)
*dsi_cinfo = best;
if (dispc_cinfo)
*dispc_cinfo = best_dispc;
dsi->cache_req_pck = req_pck;
dsi->cache_clk_freq = 0;
dsi->cache_cinfo = best;
return 0;
}
static int dsi_pll_calc_ddrfreq(struct platform_device *dsidev,
unsigned long req_clkin4ddr, struct dsi_clock_info *cinfo)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct dsi_clock_info cur, best;
DSSDBG("dsi_pll_calc_ddrfreq\n");
memset(&best, 0, sizeof(best));
memset(&cur, 0, sizeof(cur));
cur.clkin = clk_get_rate(dsi->sys_clk);
for (cur.regn = 1; cur.regn < dsi->regn_max; ++cur.regn) {
cur.fint = cur.clkin / cur.regn;
if (cur.fint > dsi->fint_max || cur.fint < dsi->fint_min)
continue;
for (cur.regm = 1; cur.regm < dsi->regm_max; ++cur.regm) {
unsigned long a, b;
a = 2 * cur.regm * (cur.clkin/1000);
b = cur.regn;
cur.clkin4ddr = a / b * 1000;
if (cur.clkin4ddr > 1800 * 1000 * 1000)
break;
if (abs(cur.clkin4ddr - req_clkin4ddr) <
abs(best.clkin4ddr - req_clkin4ddr)) {
best = cur;
DSSDBG("best %ld\n", best.clkin4ddr);
}
if (cur.clkin4ddr == req_clkin4ddr)
goto found;
}
}
found:
if (cinfo)
*cinfo = best;
return 0;
}
static void dsi_pll_calc_dsi_fck(struct platform_device *dsidev,
struct dsi_clock_info *cinfo)
{
unsigned long max_dsi_fck;
max_dsi_fck = dss_feat_get_param_max(FEAT_PARAM_DSI_FCK);
cinfo->regm_dsi = DIV_ROUND_UP(cinfo->clkin4ddr, max_dsi_fck);
cinfo->dsi_pll_hsdiv_dsi_clk = cinfo->clkin4ddr / cinfo->regm_dsi;
}
static int dsi_pll_calc_dispc_fck(struct platform_device *dsidev,
unsigned long req_pck, struct dsi_clock_info *cinfo,
struct dispc_clock_info *dispc_cinfo)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
unsigned regm_dispc, best_regm_dispc;
unsigned long dispc_clk, best_dispc_clk;
int min_fck_per_pck;
unsigned long max_dss_fck;
struct dispc_clock_info best_dispc;
bool match;
max_dss_fck = dss_feat_get_param_max(FEAT_PARAM_DSS_FCK);
min_fck_per_pck = CONFIG_OMAP2_DSS_MIN_FCK_PER_PCK;
if (min_fck_per_pck &&
req_pck * min_fck_per_pck > max_dss_fck) {
DSSERR("Requested pixel clock not possible with the current "
"OMAP2_DSS_MIN_FCK_PER_PCK setting. Turning "
"the constraint off.\n");
min_fck_per_pck = 0;
}
retry:
best_regm_dispc = 0;
best_dispc_clk = 0;
memset(&best_dispc, 0, sizeof(best_dispc));
match = false;
for (regm_dispc = 1; regm_dispc < dsi->regm_dispc_max; ++regm_dispc) {
struct dispc_clock_info cur_dispc;
dispc_clk = cinfo->clkin4ddr / regm_dispc;
if (dispc_clk < req_pck)
break;
if (dispc_clk > max_dss_fck)
continue;
if (min_fck_per_pck && dispc_clk < req_pck * min_fck_per_pck)
continue;
match = true;
dispc_find_clk_divs(req_pck, dispc_clk, &cur_dispc);
if (abs(cur_dispc.pck - req_pck) <
abs(best_dispc.pck - req_pck)) {
best_regm_dispc = regm_dispc;
best_dispc_clk = dispc_clk;
best_dispc = cur_dispc;
if (cur_dispc.pck == req_pck)
goto found;
}
}
if (!match) {
if (min_fck_per_pck) {
DSSERR("Could not find suitable clock settings.\n"
"Turning FCK/PCK constraint off and"
"trying again.\n");
min_fck_per_pck = 0;
goto retry;
}
DSSERR("Could not find suitable clock settings.\n");
return -EINVAL;
}
found:
cinfo->regm_dispc = best_regm_dispc;
cinfo->dsi_pll_hsdiv_dispc_clk = best_dispc_clk;
*dispc_cinfo = best_dispc;
return 0;
}
int dsi_pll_set_clock_div(struct platform_device *dsidev,
struct dsi_clock_info *cinfo)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int r = 0;
u32 l;
int f = 0;
u8 regn_start, regn_end, regm_start, regm_end;
u8 regm_dispc_start, regm_dispc_end, regm_dsi_start, regm_dsi_end;
DSSDBGF();
dsi->current_cinfo.clkin = cinfo->clkin;
dsi->current_cinfo.fint = cinfo->fint;
dsi->current_cinfo.clkin4ddr = cinfo->clkin4ddr;
dsi->current_cinfo.dsi_pll_hsdiv_dispc_clk =
cinfo->dsi_pll_hsdiv_dispc_clk;
dsi->current_cinfo.dsi_pll_hsdiv_dsi_clk =
cinfo->dsi_pll_hsdiv_dsi_clk;
dsi->current_cinfo.regn = cinfo->regn;
dsi->current_cinfo.regm = cinfo->regm;
dsi->current_cinfo.regm_dispc = cinfo->regm_dispc;
dsi->current_cinfo.regm_dsi = cinfo->regm_dsi;
DSSDBG("DSI Fint %ld\n", cinfo->fint);
DSSDBG("clkin rate %ld\n", cinfo->clkin);
DSSDBG("CLKIN4DDR = 2 * %d / %d * %lu = %lu\n",
cinfo->regm,
cinfo->regn,
cinfo->clkin,
cinfo->clkin4ddr);
DSSDBG("Data rate on 1 DSI lane %ld Mbps\n",
cinfo->clkin4ddr / 1000 / 1000 / 2);
DSSDBG("Clock lane freq %ld Hz\n", cinfo->clkin4ddr / 4);
DSSDBG("regm_dispc = %d, %s (%s) = %lu\n", cinfo->regm_dispc,
dss_get_generic_clk_source_name(OMAP_DSS_CLK_SRC_DSI_PLL_HSDIV_DISPC),
dss_feat_get_clk_source_name(OMAP_DSS_CLK_SRC_DSI_PLL_HSDIV_DISPC),
cinfo->dsi_pll_hsdiv_dispc_clk);
DSSDBG("regm_dsi = %d, %s (%s) = %lu\n", cinfo->regm_dsi,
dss_get_generic_clk_source_name(OMAP_DSS_CLK_SRC_DSI_PLL_HSDIV_DSI),
dss_feat_get_clk_source_name(OMAP_DSS_CLK_SRC_DSI_PLL_HSDIV_DSI),
cinfo->dsi_pll_hsdiv_dsi_clk);
dss_feat_get_reg_field(FEAT_REG_DSIPLL_REGN, &regn_start, &regn_end);
dss_feat_get_reg_field(FEAT_REG_DSIPLL_REGM, &regm_start, &regm_end);
dss_feat_get_reg_field(FEAT_REG_DSIPLL_REGM_DISPC, &regm_dispc_start,
&regm_dispc_end);
dss_feat_get_reg_field(FEAT_REG_DSIPLL_REGM_DSI, &regm_dsi_start,
&regm_dsi_end);
REG_FLD_MOD(dsidev, DSI_PLL_CONTROL, 0, 0, 0);
l = dsi_read_reg(dsidev, DSI_PLL_CONFIGURATION1);
l = FLD_MOD(l, 1, 0, 0);
l = FLD_MOD(l, cinfo->regn - 1, regn_start, regn_end);
l = FLD_MOD(l, cinfo->regm, regm_start, regm_end);
l = FLD_MOD(l, cinfo->regm_dispc > 0 ? cinfo->regm_dispc - 1 : 0,
regm_dispc_start, regm_dispc_end);
l = FLD_MOD(l, cinfo->regm_dsi > 0 ? cinfo->regm_dsi - 1 : 0,
regm_dsi_start, regm_dsi_end);
dsi_write_reg(dsidev, DSI_PLL_CONFIGURATION1, l);
BUG_ON(cinfo->fint < dsi->fint_min || cinfo->fint > dsi->fint_max);
l = dsi_read_reg(dsidev, DSI_PLL_CONFIGURATION2);
if (dss_has_feature(FEAT_DSI_PLL_FREQSEL)) {
f = cinfo->fint < 1000000 ? 0x3 :
cinfo->fint < 1250000 ? 0x4 :
cinfo->fint < 1500000 ? 0x5 :
cinfo->fint < 1750000 ? 0x6 :
0x7;
l = FLD_MOD(l, f, 4, 1);
} else if (dss_has_feature(FEAT_DSI_PLL_SELFREQDCO)) {
f = cinfo->clkin4ddr < 1000000000 ? 0x2 : 0x4;
l = FLD_MOD(l, f, 4, 1);
}
l = FLD_MOD(l, 1, 13, 13);
l = FLD_MOD(l, 0, 14, 14);
l = FLD_MOD(l, 1, 20, 20);
if (dss_has_feature(FEAT_DSI_PLL_REFSEL))
l = FLD_MOD(l, 3, 22, 21);
dsi_write_reg(dsidev, DSI_PLL_CONFIGURATION2, l);
REG_FLD_MOD(dsidev, DSI_PLL_GO, 1, 0, 0);
if (wait_for_bit_change(dsidev, DSI_PLL_GO, 0, 0) != 0) {
DSSERR("dsi pll go bit not going down.\n");
r = -EIO;
goto err;
}
if (wait_for_bit_change(dsidev, DSI_PLL_STATUS, 1, 1) != 1) {
DSSERR("cannot lock PLL\n");
r = -EIO;
goto err;
}
dsi->pll_locked = 1;
l = dsi_read_reg(dsidev, DSI_PLL_CONFIGURATION2);
l = FLD_MOD(l, 0, 0, 0);
l = FLD_MOD(l, 0, 5, 5);
l = FLD_MOD(l, 0, 6, 6);
l = FLD_MOD(l, 0, 7, 7);
l = FLD_MOD(l, 0, 8, 8);
l = FLD_MOD(l, 0, 10, 9);
l = FLD_MOD(l, 1, 13, 13);
l = FLD_MOD(l, 1, 14, 14);
l = FLD_MOD(l, 0, 15, 15);
l = FLD_MOD(l, 1, 16, 16);
l = FLD_MOD(l, 0, 17, 17);
l = FLD_MOD(l, 1, 18, 18);
l = FLD_MOD(l, 0, 19, 19);
l = FLD_MOD(l, 0, 20, 20);
dsi_write_reg(dsidev, DSI_PLL_CONFIGURATION2, l);
DSSDBG("PLL config done\n");
err:
return r;
}
int dsi_pll_init(struct platform_device *dsidev, bool enable_hsclk,
bool enable_hsdiv)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int r = 0;
enum dsi_pll_power_state pwstate;
DSSDBG("PLL init\n");
if (dsi->vdds_dsi_reg == NULL) {
struct regulator *vdds_dsi;
vdds_dsi = regulator_get(&dsi->pdev->dev, "vdds_dsi");
if (IS_ERR(vdds_dsi)) {
DSSERR("can't get VDDS_DSI regulator\n");
return PTR_ERR(vdds_dsi);
}
dsi->vdds_dsi_reg = vdds_dsi;
}
dsi_enable_pll_clock(dsidev, 1);
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
if (enable_hsclk && enable_hsdiv)
pwstate = DSI_PLL_POWER_ON_ALL;
else if (enable_hsclk)
pwstate = DSI_PLL_POWER_ON_HSCLK;
else if (enable_hsdiv)
pwstate = DSI_PLL_POWER_ON_DIV;
else
pwstate = DSI_PLL_POWER_OFF;
r = dsi_pll_power(dsidev, pwstate);
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
dsi_enable_pll_clock(dsidev, 0);
return r;
}
void dsi_pll_uninit(struct platform_device *dsidev, bool disconnect_lanes)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
dsi->pll_locked = 0;
dsi_pll_power(dsidev, DSI_PLL_POWER_OFF);
if (disconnect_lanes) {
WARN_ON(!dsi->vdds_dsi_enabled);
regulator_disable(dsi->vdds_dsi_reg);
dsi->vdds_dsi_enabled = false;
}
dsi_disable_scp_clk(dsidev);
dsi_enable_pll_clock(dsidev, 0);
DSSDBG("PLL uninit done\n");
}
static void dsi_dump_dsidev_clocks(struct platform_device *dsidev,
struct seq_file *s)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct dsi_clock_info *cinfo = &dsi->current_cinfo;
enum omap_dss_clk_source dispc_clk_src, dsi_clk_src;
int dsi_module = dsi->module_id;
dispc_clk_src = dss_get_dispc_clk_source();
dsi_clk_src = dss_get_dsi_clk_source(dsi_module);
if (dsi_runtime_get(dsidev))
return;
seq_printf(s, "- DSI%d PLL -\n", dsi_module + 1);
seq_printf(s, "dsi pll clkin\t%lu\n", cinfo->clkin);
seq_printf(s, "Fint\t\t%-16luregn %u\n", cinfo->fint, cinfo->regn);
seq_printf(s, "CLKIN4DDR\t%-16luregm %u\n",
cinfo->clkin4ddr, cinfo->regm);
seq_printf(s, "DSI_PLL_HSDIV_DISPC (%s)\t%-16luregm_dispc %u\t(%s)\n",
dss_feat_get_clk_source_name(dsi_module == 0 ?
OMAP_DSS_CLK_SRC_DSI_PLL_HSDIV_DISPC :
OMAP_DSS_CLK_SRC_DSI2_PLL_HSDIV_DISPC),
cinfo->dsi_pll_hsdiv_dispc_clk,
cinfo->regm_dispc,
dispc_clk_src == OMAP_DSS_CLK_SRC_FCK ?
"off" : "on");
seq_printf(s, "DSI_PLL_HSDIV_DSI (%s)\t%-16luregm_dsi %u\t(%s)\n",
dss_feat_get_clk_source_name(dsi_module == 0 ?
OMAP_DSS_CLK_SRC_DSI_PLL_HSDIV_DSI :
OMAP_DSS_CLK_SRC_DSI2_PLL_HSDIV_DSI),
cinfo->dsi_pll_hsdiv_dsi_clk,
cinfo->regm_dsi,
dsi_clk_src == OMAP_DSS_CLK_SRC_FCK ?
"off" : "on");
seq_printf(s, "- DSI%d -\n", dsi_module + 1);
seq_printf(s, "dsi fclk source = %s (%s)\n",
dss_get_generic_clk_source_name(dsi_clk_src),
dss_feat_get_clk_source_name(dsi_clk_src));
seq_printf(s, "DSI_FCLK\t%lu\n", dsi_fclk_rate(dsidev));
seq_printf(s, "DDR_CLK\t\t%lu\n",
cinfo->clkin4ddr / 4);
seq_printf(s, "TxByteClkHS\t%lu\n", dsi_get_txbyteclkhs(dsidev));
seq_printf(s, "LP_CLK\t\t%lu\n", cinfo->lp_clk);
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
unsigned long ddr_clk = dsi->current_cinfo.clkin4ddr / 4;
return (ns * (ddr_clk / 1000 / 1000) + 999) / 1000;
}
static inline unsigned ddr2ns(struct platform_device *dsidev, unsigned ddr)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
unsigned long ddr_clk = dsi->current_cinfo.clkin4ddr / 4;
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
DSSDBGF();
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
dsi->vc[0].fifo_size = size1;
dsi->vc[1].fifo_size = size2;
dsi->vc[2].fifo_size = size3;
dsi->vc[3].fifo_size = size4;
for (i = 0; i < 4; i++) {
u8 v;
int size = dsi->vc[i].fifo_size;
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
dsi->vc[0].fifo_size = size1;
dsi->vc[1].fifo_size = size2;
dsi->vc[2].fifo_size = size3;
dsi->vc[3].fifo_size = size4;
for (i = 0; i < 4; i++) {
u8 v;
int size = dsi->vc[i].fifo_size;
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
struct dsi_packet_sent_handler_data vp_data = { dsidev, &completion };
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
struct dsi_packet_sent_handler_data l4_data = { dsidev, &completion };
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
u32 r;
DSSDBGF("%d", channel);
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
}
static int dsi_vc_config_source(struct platform_device *dsidev, int channel,
enum dsi_vc_source source)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
if (dsi->vc[channel].source == source)
return 0;
DSSDBGF("%d", channel);
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
void omapdss_dsi_vc_enable_hs(struct omap_dss_device *dssdev, int channel,
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
int dsi_vc_send_bta_sync(struct omap_dss_device *dssdev, int channel)
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
if (dsi->vc[channel].fifo_size * 32 * 4 < len + 4) {
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
int dsi_vc_send_null(struct omap_dss_device *dssdev, int channel)
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
int dsi_vc_dcs_write_nosync(struct omap_dss_device *dssdev, int channel,
u8 *data, int len)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
return dsi_vc_write_nosync_common(dsidev, channel, data, len,
DSS_DSI_CONTENT_DCS);
}
int dsi_vc_generic_write_nosync(struct omap_dss_device *dssdev, int channel,
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
int dsi_vc_dcs_write(struct omap_dss_device *dssdev, int channel, u8 *data,
int len)
{
return dsi_vc_write_common(dssdev, channel, data, len,
DSS_DSI_CONTENT_DCS);
}
int dsi_vc_generic_write(struct omap_dss_device *dssdev, int channel, u8 *data,
int len)
{
return dsi_vc_write_common(dssdev, channel, data, len,
DSS_DSI_CONTENT_GENERIC);
}
int dsi_vc_dcs_write_0(struct omap_dss_device *dssdev, int channel, u8 dcs_cmd)
{
return dsi_vc_dcs_write(dssdev, channel, &dcs_cmd, 1);
}
int dsi_vc_generic_write_0(struct omap_dss_device *dssdev, int channel)
{
return dsi_vc_generic_write(dssdev, channel, NULL, 0);
}
int dsi_vc_dcs_write_1(struct omap_dss_device *dssdev, int channel, u8 dcs_cmd,
u8 param)
{
u8 buf[2];
buf[0] = dcs_cmd;
buf[1] = param;
return dsi_vc_dcs_write(dssdev, channel, buf, 2);
}
int dsi_vc_generic_write_1(struct omap_dss_device *dssdev, int channel,
u8 param)
{
return dsi_vc_generic_write(dssdev, channel, &param, 1);
}
int dsi_vc_generic_write_2(struct omap_dss_device *dssdev, int channel,
u8 param1, u8 param2)
{
u8 buf[2];
buf[0] = param1;
buf[1] = param2;
return dsi_vc_generic_write(dssdev, channel, buf, 2);
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
int dsi_vc_dcs_read(struct omap_dss_device *dssdev, int channel, u8 dcs_cmd,
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
int dsi_vc_generic_read_0(struct omap_dss_device *dssdev, int channel, u8 *buf,
int buflen)
{
int r;
r = dsi_vc_generic_read(dssdev, channel, NULL, 0, buf, buflen);
if (r) {
DSSERR("dsi_vc_generic_read_0(ch %d) failed\n", channel);
return r;
}
return 0;
}
int dsi_vc_generic_read_1(struct omap_dss_device *dssdev, int channel, u8 param,
u8 *buf, int buflen)
{
int r;
r = dsi_vc_generic_read(dssdev, channel, &param, 1, buf, buflen);
if (r) {
DSSERR("dsi_vc_generic_read_1(ch %d) failed\n", channel);
return r;
}
return 0;
}
int dsi_vc_generic_read_2(struct omap_dss_device *dssdev, int channel,
u8 param1, u8 param2, u8 *buf, int buflen)
{
int r;
u8 reqdata[2];
reqdata[0] = param1;
reqdata[1] = param2;
r = dsi_vc_generic_read(dssdev, channel, reqdata, 2, buf, buflen);
if (r) {
DSSERR("dsi_vc_generic_read_2(ch %d) failed\n", channel);
return r;
}
return 0;
}
int dsi_vc_set_max_rx_packet_size(struct omap_dss_device *dssdev, int channel,
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
DSSDBGF();
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
unsigned line_buf_size = dsi_get_line_buf_size(dsidev);
struct omap_video_timings *timings = &dsi->timings;
if (line_buf_size <= timings->x_res * bpp / 8)
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
bool vsync_end = dsi->vm_timings.vp_vsync_end;
bool hsync_end = dsi->vm_timings.vp_hsync_end;
u32 r;
r = dsi_read_reg(dsidev, DSI_CTRL);
r = FLD_MOD(r, 1, 9, 9);
r = FLD_MOD(r, 1, 10, 10);
r = FLD_MOD(r, 1, 11, 11);
r = FLD_MOD(r, 1, 15, 15);
r = FLD_MOD(r, vsync_end, 16, 16);
r = FLD_MOD(r, 1, 17, 17);
r = FLD_MOD(r, hsync_end, 18, 18);
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
static void dsi_config_cmd_mode_interleaving(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
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
int dsi_fclk_hsdiv = dssdev->clocks.dsi.regm_dsi + 1;
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
static int dsi_proto_config(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
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
dsi_config_cmd_mode_interleaving(dssdev);
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
bool hsync_end = dsi->vm_timings.vp_hsync_end;
struct omap_video_timings *timings = &dsi->timings;
int bpp = dsi_get_pixel_size(dsi->pix_fmt);
int tl, t_he, width_bytes;
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
int omapdss_dsi_configure_pins(struct omap_dss_device *dssdev,
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
int omapdss_dsi_set_clocks(struct omap_dss_device *dssdev,
unsigned long ddr_clk, unsigned long lp_clk)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct dsi_clock_info cinfo;
struct dispc_clock_info dispc_cinfo;
unsigned lp_clk_div;
unsigned long dsi_fclk;
int bpp = dsi_get_pixel_size(dssdev->panel.dsi_pix_fmt);
unsigned long pck;
int r;
DSSDBGF("ddr_clk %lu, lp_clk %lu", ddr_clk, lp_clk);
mutex_lock(&dsi->lock);
r = dsi_pll_calc_ddrfreq(dsidev, ddr_clk * 4, &cinfo);
if (r)
goto err;
dsi_pll_calc_dsi_fck(dsidev, &cinfo);
pck = cinfo.clkin4ddr / 16 * (dsi->num_lanes_used - 1) * 8 / bpp;
DSSDBG("finding dispc dividers for pck %lu\n", pck);
r = dsi_pll_calc_dispc_fck(dsidev, pck, &cinfo, &dispc_cinfo);
if (r)
goto err;
dsi_fclk = cinfo.dsi_pll_hsdiv_dsi_clk;
lp_clk_div = DIV_ROUND_UP(dsi_fclk, lp_clk * 2);
dssdev->clocks.dsi.regn = cinfo.regn;
dssdev->clocks.dsi.regm = cinfo.regm;
dssdev->clocks.dsi.regm_dispc = cinfo.regm_dispc;
dssdev->clocks.dsi.regm_dsi = cinfo.regm_dsi;
dssdev->clocks.dsi.lp_clk_div = lp_clk_div;
dssdev->clocks.dispc.channel.lck_div = dispc_cinfo.lck_div;
dssdev->clocks.dispc.channel.pck_div = dispc_cinfo.pck_div;
dssdev->clocks.dispc.dispc_fclk_src = OMAP_DSS_CLK_SRC_FCK;
dssdev->clocks.dispc.channel.lcd_clk_src =
dsi->module_id == 0 ?
OMAP_DSS_CLK_SRC_DSI_PLL_HSDIV_DISPC :
OMAP_DSS_CLK_SRC_DSI2_PLL_HSDIV_DISPC;
dssdev->clocks.dsi.dsi_fclk_src =
dsi->module_id == 0 ?
OMAP_DSS_CLK_SRC_DSI_PLL_HSDIV_DSI :
OMAP_DSS_CLK_SRC_DSI2_PLL_HSDIV_DSI;
mutex_unlock(&dsi->lock);
return 0;
err:
mutex_unlock(&dsi->lock);
return r;
}
int dsi_enable_video_output(struct omap_dss_device *dssdev, int channel)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct omap_overlay_manager *mgr = dssdev->output->manager;
int bpp = dsi_get_pixel_size(dsi->pix_fmt);
u8 data_type;
u16 word_count;
int r;
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
BUG();
return -EINVAL;
};
dsi_if_enable(dsidev, false);
dsi_vc_enable(dsidev, channel, false);
REG_FLD_MOD(dsidev, DSI_VC_CTRL(channel), 1, 4, 4);
word_count = DIV_ROUND_UP(dsi->timings.x_res * bpp, 8);
dsi_vc_write_long_header(dsidev, channel, data_type,
word_count, 0);
dsi_vc_enable(dsidev, channel, true);
dsi_if_enable(dsidev, true);
}
r = dss_mgr_enable(mgr);
if (r) {
if (dsi->mode == OMAP_DSS_DSI_VIDEO_MODE) {
dsi_if_enable(dsidev, false);
dsi_vc_enable(dsidev, channel, false);
}
return r;
}
return 0;
}
void dsi_disable_video_output(struct omap_dss_device *dssdev, int channel)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct omap_overlay_manager *mgr = dssdev->output->manager;
if (dsi->mode == OMAP_DSS_DSI_VIDEO_MODE) {
dsi_if_enable(dsidev, false);
dsi_vc_enable(dsidev, channel, false);
REG_FLD_MOD(dsidev, DSI_VC_CTRL(channel), 0, 4, 4);
dsi_vc_enable(dsidev, channel, true);
dsi_if_enable(dsidev, true);
}
dss_mgr_disable(mgr);
}
static void dsi_update_screen_dispc(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct omap_overlay_manager *mgr = dssdev->output->manager;
unsigned bytespp;
unsigned bytespl;
unsigned bytespf;
unsigned total_len;
unsigned packet_payload;
unsigned packet_len;
u32 l;
int r;
const unsigned channel = dsi->update_channel;
const unsigned line_buf_size = dsi_get_line_buf_size(dsidev);
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
dss_mgr_set_timings(mgr, &dsi->timings);
dss_mgr_start_update(mgr);
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
static void dsi_framedone_irq_callback(void *data, u32 mask)
{
struct platform_device *dsidev = (struct platform_device *) data;
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
cancel_delayed_work(&dsi->framedone_timeout_work);
dsi_handle_framedone(dsidev, 0);
}
int omap_dsi_update(struct omap_dss_device *dssdev, int channel,
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
#ifdef DEBUG
dsi->update_bytes = dw * dh *
dsi_get_pixel_size(dsi->pix_fmt) / 8;
#endif
dsi_update_screen_dispc(dssdev);
return 0;
}
static int dsi_configure_dispc_clocks(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct dispc_clock_info dispc_cinfo;
int r;
unsigned long long fck;
fck = dsi_get_pll_hsdiv_dispc_rate(dsidev);
dispc_cinfo.lck_div = dssdev->clocks.dispc.channel.lck_div;
dispc_cinfo.pck_div = dssdev->clocks.dispc.channel.pck_div;
r = dispc_calc_clock_rates(fck, &dispc_cinfo);
if (r) {
DSSERR("Failed to calc dispc clocks\n");
return r;
}
dsi->mgr_config.clock_info = dispc_cinfo;
return 0;
}
static int dsi_display_init_dispc(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct omap_overlay_manager *mgr = dssdev->output->manager;
int r;
u32 irq = 0;
if (dsi->mode == OMAP_DSS_DSI_CMD_MODE) {
dsi->timings.hsw = 1;
dsi->timings.hfp = 1;
dsi->timings.hbp = 1;
dsi->timings.vsw = 1;
dsi->timings.vfp = 0;
dsi->timings.vbp = 0;
irq = dispc_mgr_get_framedone_irq(mgr->id);
r = omap_dispc_register_isr(dsi_framedone_irq_callback,
(void *) dsidev, irq);
if (r) {
DSSERR("can't get FRAMEDONE irq\n");
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
dsi->timings.sync_pclk_edge = OMAPDSS_DRIVE_SIG_OPPOSITE_EDGES;
dss_mgr_set_timings(mgr, &dsi->timings);
r = dsi_configure_dispc_clocks(dssdev);
if (r)
goto err1;
dsi->mgr_config.io_pad_mode = DSS_IO_PAD_MODE_BYPASS;
dsi->mgr_config.video_port_width =
dsi_get_pixel_size(dsi->pix_fmt);
dsi->mgr_config.lcden_sig_polarity = 0;
dss_mgr_set_lcd_config(mgr, &dsi->mgr_config);
return 0;
err1:
if (dsi->mode == OMAP_DSS_DSI_CMD_MODE)
omap_dispc_unregister_isr(dsi_framedone_irq_callback,
(void *) dsidev, irq);
err:
return r;
}
static void dsi_display_uninit_dispc(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct omap_overlay_manager *mgr = dssdev->output->manager;
if (dsi->mode == OMAP_DSS_DSI_CMD_MODE) {
u32 irq;
irq = dispc_mgr_get_framedone_irq(mgr->id);
omap_dispc_unregister_isr(dsi_framedone_irq_callback,
(void *) dsidev, irq);
}
}
static int dsi_configure_dsi_clocks(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_clock_info cinfo;
int r;
cinfo.regn = dssdev->clocks.dsi.regn;
cinfo.regm = dssdev->clocks.dsi.regm;
cinfo.regm_dispc = dssdev->clocks.dsi.regm_dispc;
cinfo.regm_dsi = dssdev->clocks.dsi.regm_dsi;
r = dsi_calc_clock_rates(dsidev, &cinfo);
if (r) {
DSSERR("Failed to calc dsi clocks\n");
return r;
}
r = dsi_pll_set_clock_div(dsidev, &cinfo);
if (r) {
DSSERR("Failed to set dsi clocks\n");
return r;
}
return 0;
}
static int dsi_display_init_dsi(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct omap_overlay_manager *mgr = dssdev->output->manager;
int r;
r = dsi_pll_init(dsidev, true, true);
if (r)
goto err0;
r = dsi_configure_dsi_clocks(dssdev);
if (r)
goto err1;
dss_select_dispc_clk_source(dssdev->clocks.dispc.dispc_fclk_src);
dss_select_dsi_clk_source(dsi->module_id, dssdev->clocks.dsi.dsi_fclk_src);
dss_select_lcd_clk_source(mgr->id,
dssdev->clocks.dispc.channel.lcd_clk_src);
DSSDBG("PLL OK\n");
r = dsi_cio_init(dsidev);
if (r)
goto err2;
_dsi_print_reset_status(dsidev);
dsi_proto_timings(dsidev);
dsi_set_lp_clk_divisor(dssdev);
if (1)
_dsi_print_reset_status(dsidev);
r = dsi_proto_config(dssdev);
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
dss_select_dispc_clk_source(OMAP_DSS_CLK_SRC_FCK);
dss_select_dsi_clk_source(dsi->module_id, OMAP_DSS_CLK_SRC_FCK);
dss_select_lcd_clk_source(mgr->id, OMAP_DSS_CLK_SRC_FCK);
err1:
dsi_pll_uninit(dsidev, true);
err0:
return r;
}
static void dsi_display_uninit_dsi(struct omap_dss_device *dssdev,
bool disconnect_lanes, bool enter_ulps)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct omap_overlay_manager *mgr = dssdev->output->manager;
if (enter_ulps && !dsi->ulps_enabled)
dsi_enter_ulps(dsidev);
dsi_if_enable(dsidev, 0);
dsi_vc_enable(dsidev, 0, 0);
dsi_vc_enable(dsidev, 1, 0);
dsi_vc_enable(dsidev, 2, 0);
dsi_vc_enable(dsidev, 3, 0);
dss_select_dispc_clk_source(OMAP_DSS_CLK_SRC_FCK);
dss_select_dsi_clk_source(dsi->module_id, OMAP_DSS_CLK_SRC_FCK);
dss_select_lcd_clk_source(mgr->id, OMAP_DSS_CLK_SRC_FCK);
dsi_cio_uninit(dsidev);
dsi_pll_uninit(dsidev, disconnect_lanes);
}
int omapdss_dsi_display_enable(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct omap_dss_output *out = dssdev->output;
int r = 0;
DSSDBG("dsi_display_enable\n");
WARN_ON(!dsi_bus_is_locked(dsidev));
mutex_lock(&dsi->lock);
if (out == NULL || out->manager == NULL) {
DSSERR("failed to enable display: no output/manager\n");
r = -ENODEV;
goto err_start_dev;
}
r = omap_dss_start_device(dssdev);
if (r) {
DSSERR("failed to start device\n");
goto err_start_dev;
}
r = dsi_runtime_get(dsidev);
if (r)
goto err_get_dsi;
dsi_enable_pll_clock(dsidev, 1);
_dsi_initialize_irq(dsidev);
r = dsi_display_init_dispc(dssdev);
if (r)
goto err_init_dispc;
r = dsi_display_init_dsi(dssdev);
if (r)
goto err_init_dsi;
mutex_unlock(&dsi->lock);
return 0;
err_init_dsi:
dsi_display_uninit_dispc(dssdev);
err_init_dispc:
dsi_enable_pll_clock(dsidev, 0);
dsi_runtime_put(dsidev);
err_get_dsi:
omap_dss_stop_device(dssdev);
err_start_dev:
mutex_unlock(&dsi->lock);
DSSDBG("dsi_display_enable FAILED\n");
return r;
}
void omapdss_dsi_display_disable(struct omap_dss_device *dssdev,
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
dsi_display_uninit_dispc(dssdev);
dsi_display_uninit_dsi(dssdev, disconnect_lanes, enter_ulps);
dsi_runtime_put(dsidev);
dsi_enable_pll_clock(dsidev, 0);
omap_dss_stop_device(dssdev);
mutex_unlock(&dsi->lock);
}
int omapdss_dsi_enable_te(struct omap_dss_device *dssdev, bool enable)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
dsi->te_enabled = enable;
return 0;
}
void omapdss_dsi_set_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
mutex_lock(&dsi->lock);
dsi->timings = *timings;
mutex_unlock(&dsi->lock);
}
void omapdss_dsi_set_size(struct omap_dss_device *dssdev, u16 w, u16 h)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
mutex_lock(&dsi->lock);
dsi->timings.x_res = w;
dsi->timings.y_res = h;
mutex_unlock(&dsi->lock);
}
void omapdss_dsi_set_pixel_format(struct omap_dss_device *dssdev,
enum omap_dss_dsi_pixel_format fmt)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
mutex_lock(&dsi->lock);
dsi->pix_fmt = fmt;
mutex_unlock(&dsi->lock);
}
void omapdss_dsi_set_operation_mode(struct omap_dss_device *dssdev,
enum omap_dss_dsi_mode mode)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
mutex_lock(&dsi->lock);
dsi->mode = mode;
mutex_unlock(&dsi->lock);
}
void omapdss_dsi_set_videomode_timings(struct omap_dss_device *dssdev,
struct omap_dss_dsi_videomode_timings *timings)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
mutex_lock(&dsi->lock);
dsi->vm_timings = *timings;
mutex_unlock(&dsi->lock);
}
static int __init dsi_init_display(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev =
dsi_get_dsidev_from_id(dssdev->phy.dsi.module);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
DSSDBG("DSI init\n");
if (dsi->vdds_dsi_reg == NULL) {
struct regulator *vdds_dsi;
vdds_dsi = regulator_get(&dsi->pdev->dev, "vdds_dsi");
if (IS_ERR(vdds_dsi)) {
DSSERR("can't get VDDS_DSI regulator\n");
return PTR_ERR(vdds_dsi);
}
dsi->vdds_dsi_reg = vdds_dsi;
}
return 0;
}
int omap_dsi_request_vc(struct omap_dss_device *dssdev, int *channel)
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
int omap_dsi_set_vc_id(struct omap_dss_device *dssdev, int channel, int vc_id)
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
void omap_dsi_release_vc(struct omap_dss_device *dssdev, int channel)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
if ((channel >= 0 && channel <= 3) &&
dsi->vc[channel].dssdev == dssdev) {
dsi->vc[channel].dssdev = NULL;
dsi->vc[channel].vc_id = 0;
}
}
void dsi_wait_pll_hsdiv_dispc_active(struct platform_device *dsidev)
{
if (wait_for_bit_change(dsidev, DSI_PLL_STATUS, 7, 1) != 1)
DSSERR("%s (%s) not active\n",
dss_get_generic_clk_source_name(OMAP_DSS_CLK_SRC_DSI_PLL_HSDIV_DISPC),
dss_feat_get_clk_source_name(OMAP_DSS_CLK_SRC_DSI_PLL_HSDIV_DISPC));
}
void dsi_wait_pll_hsdiv_dsi_active(struct platform_device *dsidev)
{
if (wait_for_bit_change(dsidev, DSI_PLL_STATUS, 8, 1) != 1)
DSSERR("%s (%s) not active\n",
dss_get_generic_clk_source_name(OMAP_DSS_CLK_SRC_DSI_PLL_HSDIV_DSI),
dss_feat_get_clk_source_name(OMAP_DSS_CLK_SRC_DSI_PLL_HSDIV_DSI));
}
static void dsi_calc_clock_param_ranges(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
dsi->regn_max = dss_feat_get_param_max(FEAT_PARAM_DSIPLL_REGN);
dsi->regm_max = dss_feat_get_param_max(FEAT_PARAM_DSIPLL_REGM);
dsi->regm_dispc_max =
dss_feat_get_param_max(FEAT_PARAM_DSIPLL_REGM_DISPC);
dsi->regm_dsi_max = dss_feat_get_param_max(FEAT_PARAM_DSIPLL_REGM_DSI);
dsi->fint_min = dss_feat_get_param_min(FEAT_PARAM_DSIPLL_FINT);
dsi->fint_max = dss_feat_get_param_max(FEAT_PARAM_DSIPLL_FINT);
dsi->lpdiv_max = dss_feat_get_param_max(FEAT_PARAM_DSIPLL_LPDIV);
}
static int dsi_get_clocks(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct clk *clk;
clk = clk_get(&dsidev->dev, "fck");
if (IS_ERR(clk)) {
DSSERR("can't get fck\n");
return PTR_ERR(clk);
}
dsi->dss_clk = clk;
clk = clk_get(&dsidev->dev, "sys_clk");
if (IS_ERR(clk)) {
DSSERR("can't get sys_clk\n");
clk_put(dsi->dss_clk);
dsi->dss_clk = NULL;
return PTR_ERR(clk);
}
dsi->sys_clk = clk;
return 0;
}
static void dsi_put_clocks(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
if (dsi->dss_clk)
clk_put(dsi->dss_clk);
if (dsi->sys_clk)
clk_put(dsi->sys_clk);
}
static struct omap_dss_device * __init dsi_find_dssdev(struct platform_device *pdev)
{
struct omap_dss_board_info *pdata = pdev->dev.platform_data;
struct dsi_data *dsi = dsi_get_dsidrv_data(pdev);
const char *def_disp_name = dss_get_default_display_name();
struct omap_dss_device *def_dssdev;
int i;
def_dssdev = NULL;
for (i = 0; i < pdata->num_devices; ++i) {
struct omap_dss_device *dssdev = pdata->devices[i];
if (dssdev->type != OMAP_DISPLAY_TYPE_DSI)
continue;
if (dssdev->phy.dsi.module != dsi->module_id)
continue;
if (def_dssdev == NULL)
def_dssdev = dssdev;
if (def_disp_name != NULL &&
strcmp(dssdev->name, def_disp_name) == 0) {
def_dssdev = dssdev;
break;
}
}
return def_dssdev;
}
static void __init dsi_probe_pdata(struct platform_device *dsidev)
{
struct omap_dss_device *plat_dssdev;
struct omap_dss_device *dssdev;
int r;
plat_dssdev = dsi_find_dssdev(dsidev);
if (!plat_dssdev)
return;
dssdev = dss_alloc_and_init_device(&dsidev->dev);
if (!dssdev)
return;
dss_copy_device_pdata(dssdev, plat_dssdev);
r = dsi_init_display(dssdev);
if (r) {
DSSERR("device %s init failed: %d\n", dssdev->name, r);
dss_put_device(dssdev);
return;
}
r = dss_add_device(dssdev);
if (r) {
DSSERR("device %s register failed: %d\n", dssdev->name, r);
dss_put_device(dssdev);
return;
}
}
static void __init dsi_init_output(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct omap_dss_output *out = &dsi->output;
out->pdev = dsidev;
out->id = dsi->module_id == 0 ?
OMAP_DSS_OUTPUT_DSI1 : OMAP_DSS_OUTPUT_DSI2;
out->type = OMAP_DISPLAY_TYPE_DSI;
dss_register_output(out);
}
static void __exit dsi_uninit_output(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
struct omap_dss_output *out = &dsi->output;
dss_unregister_output(out);
}
static int __init omap_dsihw_probe(struct platform_device *dsidev)
{
u32 rev;
int r, i;
struct resource *dsi_mem;
struct dsi_data *dsi;
dsi = devm_kzalloc(&dsidev->dev, sizeof(*dsi), GFP_KERNEL);
if (!dsi)
return -ENOMEM;
dsi->module_id = dsidev->id;
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
dsi_mem = platform_get_resource(dsi->pdev, IORESOURCE_MEM, 0);
if (!dsi_mem) {
DSSERR("can't get IORESOURCE_MEM DSI\n");
return -EINVAL;
}
dsi->base = devm_ioremap(&dsidev->dev, dsi_mem->start,
resource_size(dsi_mem));
if (!dsi->base) {
DSSERR("can't ioremap DSI\n");
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
for (i = 0; i < ARRAY_SIZE(dsi->vc); i++) {
dsi->vc[i].source = DSI_VC_SOURCE_L4;
dsi->vc[i].dssdev = NULL;
dsi->vc[i].vc_id = 0;
}
dsi_calc_clock_param_ranges(dsidev);
r = dsi_get_clocks(dsidev);
if (r)
return r;
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
dsi_init_output(dsidev);
dsi_probe_pdata(dsidev);
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
err_runtime_get:
pm_runtime_disable(&dsidev->dev);
dsi_put_clocks(dsidev);
return r;
}
static int __exit omap_dsihw_remove(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
WARN_ON(dsi->scp_clk_refcount > 0);
dss_unregister_child_devices(&dsidev->dev);
dsi_uninit_output(dsidev);
pm_runtime_disable(&dsidev->dev);
dsi_put_clocks(dsidev);
if (dsi->vdds_dsi_reg != NULL) {
if (dsi->vdds_dsi_enabled) {
regulator_disable(dsi->vdds_dsi_reg);
dsi->vdds_dsi_enabled = false;
}
regulator_put(dsi->vdds_dsi_reg);
dsi->vdds_dsi_reg = NULL;
}
return 0;
}
static int dsi_runtime_suspend(struct device *dev)
{
dispc_runtime_put();
return 0;
}
static int dsi_runtime_resume(struct device *dev)
{
int r;
r = dispc_runtime_get();
if (r)
return r;
return 0;
}
int __init dsi_init_platform_driver(void)
{
return platform_driver_probe(&omap_dsihw_driver, omap_dsihw_probe);
}
void __exit dsi_uninit_platform_driver(void)
{
platform_driver_unregister(&omap_dsihw_driver);
}
