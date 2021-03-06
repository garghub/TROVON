static inline struct dsi_data *dsi_get_dsidrv_data(struct platform_device *dsidev)
{
return dev_get_drvdata(&dsidev->dev);
}
static inline struct platform_device *dsi_get_dsidev_from_dssdev(struct omap_dss_device *dssdev)
{
return dsi_pdev_map[dssdev->phy.dsi.module];
}
struct platform_device *dsi_get_dsidev_from_id(int module)
{
return dsi_pdev_map[module];
}
static inline int dsi_get_dsidev_id(struct platform_device *dsidev)
{
return dsidev->id;
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
int t = 100000;
while (REG_GET(dsidev, idx, bitnum, bitnum) != value) {
if (--t == 0)
return !value;
}
return value;
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
struct omap_dss_device *dssdev = dsi->update_region.device;
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
total_bytes = dsi->update_region.w *
dsi->update_region.h *
dsi_get_pixel_size(dssdev->panel.dsi_pix_fmt) / 8;
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
r = pm_runtime_put(&dsi->pdev->dev);
WARN_ON(r < 0);
}
static inline void dsi_enable_pll_clock(struct platform_device *dsidev,
bool enable)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
if (enable)
clk_enable(dsi->sys_clk);
else
clk_disable(dsi->sys_clk);
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
int dsi_module = dsi_get_dsidev_id(dsidev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
if (dss_get_dsi_clk_source(dsi_module) == OMAP_DSS_CLK_SRC_FCK) {
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
static int dsi_calc_clock_rates(struct omap_dss_device *dssdev,
struct dsi_clock_info *cinfo)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
if (cinfo->regn == 0 || cinfo->regn > dsi->regn_max)
return -EINVAL;
if (cinfo->regm == 0 || cinfo->regm > dsi->regm_max)
return -EINVAL;
if (cinfo->regm_dispc > dsi->regm_dispc_max)
return -EINVAL;
if (cinfo->regm_dsi > dsi->regm_dsi_max)
return -EINVAL;
if (cinfo->use_sys_clk) {
cinfo->clkin = clk_get_rate(dsi->sys_clk);
cinfo->highfreq = 0;
} else {
cinfo->clkin = dispc_mgr_pclk_rate(dssdev->manager->id);
if (cinfo->clkin < 32000000)
cinfo->highfreq = 0;
else
cinfo->highfreq = 1;
}
cinfo->fint = cinfo->clkin / (cinfo->regn * (cinfo->highfreq ? 2 : 1));
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
int dsi_pll_calc_clock_div_pck(struct platform_device *dsidev, bool is_tft,
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
dispc_find_clk_divs(is_tft, req_pck,
dsi_cinfo->dsi_pll_hsdiv_dispc_clk, dispc_cinfo);
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
cur.use_sys_clk = 1;
cur.highfreq = 0;
for (cur.regn = 1; cur.regn < dsi->regn_max; ++cur.regn) {
if (cur.highfreq == 0)
cur.fint = cur.clkin / cur.regn;
else
cur.fint = cur.clkin / (2 * cur.regn);
if (cur.fint > dsi->fint_max || cur.fint < dsi->fint_min)
continue;
for (cur.regm = 1; cur.regm < dsi->regm_max; ++cur.regm) {
unsigned long a, b;
a = 2 * cur.regm * (cur.clkin/1000);
b = cur.regn * (cur.highfreq + 1);
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
dispc_find_clk_divs(is_tft, req_pck,
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
dsi->current_cinfo.use_sys_clk = cinfo->use_sys_clk;
dsi->current_cinfo.highfreq = cinfo->highfreq;
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
DSSDBG("clkin (%s) rate %ld, highfreq %d\n",
cinfo->use_sys_clk ? "dss_sys_clk" : "pclkfree",
cinfo->clkin,
cinfo->highfreq);
DSSDBG("CLKIN4DDR = 2 * %d / %d * %lu / %d = %lu\n",
cinfo->regm,
cinfo->regn,
cinfo->clkin,
cinfo->highfreq + 1,
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
if (dss_has_feature(FEAT_DSI_PLL_FREQSEL)) {
f = cinfo->fint < 1000000 ? 0x3 :
cinfo->fint < 1250000 ? 0x4 :
cinfo->fint < 1500000 ? 0x5 :
cinfo->fint < 1750000 ? 0x6 :
0x7;
}
l = dsi_read_reg(dsidev, DSI_PLL_CONFIGURATION2);
if (dss_has_feature(FEAT_DSI_PLL_FREQSEL))
l = FLD_MOD(l, f, 4, 1);
l = FLD_MOD(l, cinfo->use_sys_clk ? 0 : 1,
11, 11);
l = FLD_MOD(l, cinfo->highfreq,
12, 12);
l = FLD_MOD(l, 1, 13, 13);
l = FLD_MOD(l, 0, 14, 14);
l = FLD_MOD(l, 1, 20, 20);
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
int dsi_module = dsi_get_dsidev_id(dsidev);
dispc_clk_src = dss_get_dispc_clk_source();
dsi_clk_src = dss_get_dsi_clk_source(dsi_module);
if (dsi_runtime_get(dsidev))
return;
seq_printf(s, "- DSI%d PLL -\n", dsi_module + 1);
seq_printf(s, "dsi pll source = %s\n",
cinfo->use_sys_clk ? "dss_sys_clk" : "pclkfree");
seq_printf(s, "Fint\t\t%-16luregn %u\n", cinfo->fint, cinfo->regn);
seq_printf(s, "CLKIN4DDR\t%-16luregm %u\n",
cinfo->clkin4ddr, cinfo->regm);
seq_printf(s, "%s (%s)\t%-16luregm_dispc %u\t(%s)\n",
dss_get_generic_clk_source_name(dispc_clk_src),
dss_feat_get_clk_source_name(dispc_clk_src),
cinfo->dsi_pll_hsdiv_dispc_clk,
cinfo->regm_dispc,
dispc_clk_src == OMAP_DSS_CLK_SRC_FCK ?
"off" : "on");
seq_printf(s, "%s (%s)\t%-16luregm_dsi %u\t(%s)\n",
dss_get_generic_clk_source_name(dsi_clk_src),
dss_feat_get_clk_source_name(dsi_clk_src),
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
int dsi_module = dsi_get_dsidev_id(dsidev);
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
seq_printf(s, "-- DSI%d interrupts --\n", dsi_module + 1);
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
void dsi_create_debugfs_files_irq(struct dentry *debugfs_dir,
const struct file_operations *debug_fops)
{
struct platform_device *dsidev;
dsidev = dsi_get_dsidev_from_id(0);
if (dsidev)
debugfs_create_file("dsi1_irqs", S_IRUGO, debugfs_dir,
&dsi1_dump_irqs, debug_fops);
dsidev = dsi_get_dsidev_from_id(1);
if (dsidev)
debugfs_create_file("dsi2_irqs", S_IRUGO, debugfs_dir,
&dsi2_dump_irqs, debug_fops);
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
void dsi_create_debugfs_files_reg(struct dentry *debugfs_dir,
const struct file_operations *debug_fops)
{
struct platform_device *dsidev;
dsidev = dsi_get_dsidev_from_id(0);
if (dsidev)
debugfs_create_file("dsi1_regs", S_IRUGO, debugfs_dir,
&dsi1_dump_regs, debug_fops);
dsidev = dsi_get_dsidev_from_id(1);
if (dsidev)
debugfs_create_file("dsi2_regs", S_IRUGO, debugfs_dir,
&dsi2_dump_regs, debug_fops);
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
static inline int dsi_get_num_data_lanes(struct platform_device *dsidev)
{
if (dss_has_feature(FEAT_DSI_GNQ))
return REG_GET(dsidev, DSI_GNQ, 11, 9);
else
return 2;
}
static inline int dsi_get_num_data_lanes_dssdev(struct omap_dss_device *dssdev)
{
int num_data_lanes = 0;
if (dssdev->phy.dsi.data1_lane != 0)
num_data_lanes++;
if (dssdev->phy.dsi.data2_lane != 0)
num_data_lanes++;
if (dssdev->phy.dsi.data3_lane != 0)
num_data_lanes++;
if (dssdev->phy.dsi.data4_lane != 0)
num_data_lanes++;
return num_data_lanes;
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
default:
BUG();
}
}
static void dsi_set_lane_config(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
u32 r;
int num_data_lanes_dssdev = dsi_get_num_data_lanes_dssdev(dssdev);
int clk_lane = dssdev->phy.dsi.clk_lane;
int data1_lane = dssdev->phy.dsi.data1_lane;
int data2_lane = dssdev->phy.dsi.data2_lane;
int clk_pol = dssdev->phy.dsi.clk_pol;
int data1_pol = dssdev->phy.dsi.data1_pol;
int data2_pol = dssdev->phy.dsi.data2_pol;
r = dsi_read_reg(dsidev, DSI_COMPLEXIO_CFG1);
r = FLD_MOD(r, clk_lane, 2, 0);
r = FLD_MOD(r, clk_pol, 3, 3);
r = FLD_MOD(r, data1_lane, 6, 4);
r = FLD_MOD(r, data1_pol, 7, 7);
r = FLD_MOD(r, data2_lane, 10, 8);
r = FLD_MOD(r, data2_pol, 11, 11);
if (num_data_lanes_dssdev > 2) {
int data3_lane = dssdev->phy.dsi.data3_lane;
int data3_pol = dssdev->phy.dsi.data3_pol;
r = FLD_MOD(r, data3_lane, 14, 12);
r = FLD_MOD(r, data3_pol, 15, 15);
}
if (num_data_lanes_dssdev > 3) {
int data4_lane = dssdev->phy.dsi.data4_lane;
int data4_pol = dssdev->phy.dsi.data4_pol;
r = FLD_MOD(r, data4_lane, 18, 16);
r = FLD_MOD(r, data4_pol, 19, 19);
}
dsi_write_reg(dsidev, DSI_COMPLEXIO_CFG1, r);
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
r = FLD_MOD(r, tlpx_half, 22, 16);
r = FLD_MOD(r, tclk_trail, 15, 8);
r = FLD_MOD(r, tclk_zero, 7, 0);
dsi_write_reg(dsidev, DSI_DSIPHY_CFG1, r);
r = dsi_read_reg(dsidev, DSI_DSIPHY_CFG2);
r = FLD_MOD(r, tclk_prepare, 7, 0);
dsi_write_reg(dsidev, DSI_DSIPHY_CFG2, r);
}
static void dsi_cio_enable_lane_override(struct omap_dss_device *dssdev,
enum dsi_lane lanes)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int clk_lane = dssdev->phy.dsi.clk_lane;
int data1_lane = dssdev->phy.dsi.data1_lane;
int data2_lane = dssdev->phy.dsi.data2_lane;
int data3_lane = dssdev->phy.dsi.data3_lane;
int data4_lane = dssdev->phy.dsi.data4_lane;
int clk_pol = dssdev->phy.dsi.clk_pol;
int data1_pol = dssdev->phy.dsi.data1_pol;
int data2_pol = dssdev->phy.dsi.data2_pol;
int data3_pol = dssdev->phy.dsi.data3_pol;
int data4_pol = dssdev->phy.dsi.data4_pol;
u32 l = 0;
u8 lptxscp_start = dsi->num_data_lanes == 2 ? 22 : 26;
if (lanes & DSI_CLK_P)
l |= 1 << ((clk_lane - 1) * 2 + (clk_pol ? 0 : 1));
if (lanes & DSI_CLK_N)
l |= 1 << ((clk_lane - 1) * 2 + (clk_pol ? 1 : 0));
if (lanes & DSI_DATA1_P)
l |= 1 << ((data1_lane - 1) * 2 + (data1_pol ? 0 : 1));
if (lanes & DSI_DATA1_N)
l |= 1 << ((data1_lane - 1) * 2 + (data1_pol ? 1 : 0));
if (lanes & DSI_DATA2_P)
l |= 1 << ((data2_lane - 1) * 2 + (data2_pol ? 0 : 1));
if (lanes & DSI_DATA2_N)
l |= 1 << ((data2_lane - 1) * 2 + (data2_pol ? 1 : 0));
if (lanes & DSI_DATA3_P)
l |= 1 << ((data3_lane - 1) * 2 + (data3_pol ? 0 : 1));
if (lanes & DSI_DATA3_N)
l |= 1 << ((data3_lane - 1) * 2 + (data3_pol ? 1 : 0));
if (lanes & DSI_DATA4_P)
l |= 1 << ((data4_lane - 1) * 2 + (data4_pol ? 0 : 1));
if (lanes & DSI_DATA4_N)
l |= 1 << ((data4_lane - 1) * 2 + (data4_pol ? 1 : 0));
REG_FLD_MOD(dsidev, DSI_DSIPHY_CFG10, l, lptxscp_start, 17);
REG_FLD_MOD(dsidev, DSI_DSIPHY_CFG10, 1, 27, 27);
}
static void dsi_cio_disable_lane_override(struct platform_device *dsidev)
{
REG_FLD_MOD(dsidev, DSI_DSIPHY_CFG10, 0, 27, 27);
REG_FLD_MOD(dsidev, DSI_DSIPHY_CFG10, 0, 22, 17);
}
static int dsi_cio_wait_tx_clk_esc_reset(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
int t;
int bits[3];
bool in_use[3];
if (dss_has_feature(FEAT_DSI_REVERSE_TXCLKESC)) {
bits[0] = 28;
bits[1] = 27;
bits[2] = 26;
} else {
bits[0] = 24;
bits[1] = 25;
bits[2] = 26;
}
in_use[0] = false;
in_use[1] = false;
in_use[2] = false;
if (dssdev->phy.dsi.clk_lane != 0)
in_use[dssdev->phy.dsi.clk_lane - 1] = true;
if (dssdev->phy.dsi.data1_lane != 0)
in_use[dssdev->phy.dsi.data1_lane - 1] = true;
if (dssdev->phy.dsi.data2_lane != 0)
in_use[dssdev->phy.dsi.data2_lane - 1] = true;
t = 100000;
while (true) {
u32 l;
int i;
int ok;
l = dsi_read_reg(dsidev, DSI_DSIPHY_CFG5);
ok = 0;
for (i = 0; i < 3; ++i) {
if (!in_use[i] || (l & (1 << bits[i])))
ok++;
}
if (ok == 3)
break;
if (--t == 0) {
for (i = 0; i < 3; ++i) {
if (!in_use[i] || (l & (1 << bits[i])))
continue;
DSSERR("CIO TXCLKESC%d domain not coming " \
"out of reset\n", i);
}
return -EIO;
}
}
return 0;
}
static unsigned dsi_get_lane_mask(struct omap_dss_device *dssdev)
{
unsigned lanes = 0;
if (dssdev->phy.dsi.clk_lane != 0)
lanes |= 1 << (dssdev->phy.dsi.clk_lane - 1);
if (dssdev->phy.dsi.data1_lane != 0)
lanes |= 1 << (dssdev->phy.dsi.data1_lane - 1);
if (dssdev->phy.dsi.data2_lane != 0)
lanes |= 1 << (dssdev->phy.dsi.data2_lane - 1);
if (dssdev->phy.dsi.data3_lane != 0)
lanes |= 1 << (dssdev->phy.dsi.data3_lane - 1);
if (dssdev->phy.dsi.data4_lane != 0)
lanes |= 1 << (dssdev->phy.dsi.data4_lane - 1);
return lanes;
}
static int dsi_cio_init(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int r;
int num_data_lanes_dssdev = dsi_get_num_data_lanes_dssdev(dssdev);
u32 l;
DSSDBGF();
r = dsi->enable_pads(dsidev->id, dsi_get_lane_mask(dssdev));
if (r)
return r;
dsi_enable_scp_clk(dsidev);
dsi_read_reg(dsidev, DSI_DSIPHY_CFG5);
if (wait_for_bit_change(dsidev, DSI_DSIPHY_CFG5, 30, 1) != 1) {
DSSERR("CIO SCP Clock domain not coming out of reset.\n");
r = -EIO;
goto err_scp_clk_dom;
}
dsi_set_lane_config(dssdev);
l = dsi_read_reg(dsidev, DSI_TIMING1);
l = FLD_MOD(l, 1, 15, 15);
l = FLD_MOD(l, 1, 14, 14);
l = FLD_MOD(l, 1, 13, 13);
l = FLD_MOD(l, 0x1fff, 12, 0);
dsi_write_reg(dsidev, DSI_TIMING1, l);
if (dsi->ulps_enabled) {
u32 lane_mask = DSI_CLK_P | DSI_DATA1_P | DSI_DATA2_P;
DSSDBG("manual ulps exit\n");
if (num_data_lanes_dssdev > 2)
lane_mask |= DSI_DATA3_P;
if (num_data_lanes_dssdev > 3)
lane_mask |= DSI_DATA4_P;
dsi_cio_enable_lane_override(dssdev, lane_mask);
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
r = dsi_cio_wait_tx_clk_esc_reset(dssdev);
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
if (dssdev->panel.dsi_mode == OMAP_DSS_DSI_VIDEO_MODE) {
REG_FLD_MOD(dsidev, DSI_CLK_CTRL,
dssdev->panel.dsi_vm_data.ddr_clk_always_on, 13, 13);
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
dsi->disable_pads(dsidev->id, dsi_get_lane_mask(dssdev));
return r;
}
static void dsi_cio_uninit(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
REG_FLD_MOD(dsidev, DSI_CLK_CTRL, 0, 13, 13);
dsi_cio_power(dsidev, DSI_COMPLEXIO_POWER_OFF);
dsi_disable_scp_clk(dsidev);
dsi->disable_pads(dsidev->id, dsi_get_lane_mask(dssdev));
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
DSSDBG("dsi_vc_enable_hs(%d, %d)\n", channel, enable);
WARN_ON(!dsi_bus_is_locked(dsidev));
dsi_vc_enable(dsidev, channel, 0);
dsi_if_enable(dsidev, 0);
REG_FLD_MOD(dsidev, DSI_VC_CTRL(channel), enable, 9, 9);
dsi_vc_enable(dsidev, channel, 1);
dsi_if_enable(dsidev, 1);
dsi_force_tx_stop_mode_io(dsidev);
if (dssdev->panel.dsi_vm_data.ddr_clk_always_on && enable)
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
static int dsi_vc_write_nosync_common(struct omap_dss_device *dssdev,
int channel, u8 *data, int len, enum dss_dsi_content_type type)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
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
return dsi_vc_write_nosync_common(dssdev, channel, data, len,
DSS_DSI_CONTENT_DCS);
}
int dsi_vc_generic_write_nosync(struct omap_dss_device *dssdev, int channel,
u8 *data, int len)
{
return dsi_vc_write_nosync_common(dssdev, channel, data, len,
DSS_DSI_CONTENT_GENERIC);
}
static int dsi_vc_write_common(struct omap_dss_device *dssdev, int channel,
u8 *data, int len, enum dss_dsi_content_type type)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
int r;
r = dsi_vc_write_nosync_common(dssdev, channel, data, len, type);
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
static int dsi_vc_dcs_send_read_request(struct omap_dss_device *dssdev,
int channel, u8 dcs_cmd)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
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
static int dsi_vc_generic_send_read_request(struct omap_dss_device *dssdev,
int channel, u8 *reqdata, int reqlen)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
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
BUG();
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
r = dsi_vc_dcs_send_read_request(dssdev, channel, dcs_cmd);
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
r = dsi_vc_generic_send_read_request(dssdev, channel, reqdata, reqlen);
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
int r;
DSSDBGF();
WARN_ON(!dsi_bus_is_locked(dsidev));
WARN_ON(dsi->ulps_enabled);
if (dsi->ulps_enabled)
return 0;
if (REG_GET(dsidev, DSI_CLK_CTRL, 13, 13)) {
DSSERR("DDR_CLK_ALWAYS_ON enabled when entering ULPS\n");
return -EIO;
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
REG_FLD_MOD(dsidev, DSI_COMPLEXIO_CFG2, (1 << 0) | (1 << 1) | (1 << 2),
7, 5);
if (wait_for_completion_timeout(&completion,
msecs_to_jiffies(1000)) == 0) {
DSSERR("ULPS enable timeout\n");
r = -EIO;
goto err;
}
dsi_unregister_isr_cio(dsidev, dsi_completion_handler, &completion,
DSI_CIO_IRQ_ULPSACTIVENOT_ALL0);
REG_FLD_MOD(dsidev, DSI_COMPLEXIO_CFG2, (0 << 0) | (0 << 1) | (0 << 2),
7, 5);
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
static void dsi_config_vp_num_line_buffers(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
int num_line_buffers;
if (dssdev->panel.dsi_mode == OMAP_DSS_DSI_VIDEO_MODE) {
int bpp = dsi_get_pixel_size(dssdev->panel.dsi_pix_fmt);
unsigned line_buf_size = dsi_get_line_buf_size(dsidev);
struct omap_video_timings *timings = &dssdev->panel.timings;
if (line_buf_size <= timings->x_res * bpp / 8)
num_line_buffers = 0;
else
num_line_buffers = 2;
} else {
num_line_buffers = 2;
}
REG_FLD_MOD(dsidev, DSI_CTRL, num_line_buffers, 13, 12);
}
static void dsi_config_vp_sync_events(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
int de_pol = dssdev->panel.dsi_vm_data.vp_de_pol;
int hsync_pol = dssdev->panel.dsi_vm_data.vp_hsync_pol;
int vsync_pol = dssdev->panel.dsi_vm_data.vp_vsync_pol;
bool vsync_end = dssdev->panel.dsi_vm_data.vp_vsync_end;
bool hsync_end = dssdev->panel.dsi_vm_data.vp_hsync_end;
u32 r;
r = dsi_read_reg(dsidev, DSI_CTRL);
r = FLD_MOD(r, de_pol, 9, 9);
r = FLD_MOD(r, hsync_pol, 10, 10);
r = FLD_MOD(r, vsync_pol, 11, 11);
r = FLD_MOD(r, 1, 15, 15);
r = FLD_MOD(r, vsync_end, 16, 16);
r = FLD_MOD(r, 1, 17, 17);
r = FLD_MOD(r, hsync_end, 18, 18);
dsi_write_reg(dsidev, DSI_CTRL, r);
}
static void dsi_config_blanking_modes(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
int blanking_mode = dssdev->panel.dsi_vm_data.blanking_mode;
int hfp_blanking_mode = dssdev->panel.dsi_vm_data.hfp_blanking_mode;
int hbp_blanking_mode = dssdev->panel.dsi_vm_data.hbp_blanking_mode;
int hsa_blanking_mode = dssdev->panel.dsi_vm_data.hsa_blanking_mode;
u32 r;
r = dsi_read_reg(dsidev, DSI_CTRL);
r = FLD_MOD(r, blanking_mode, 20, 20);
r = FLD_MOD(r, hfp_blanking_mode, 21, 21);
r = FLD_MOD(r, hbp_blanking_mode, 22, 22);
r = FLD_MOD(r, hsa_blanking_mode, 23, 23);
dsi_write_reg(dsidev, DSI_CTRL, r);
}
static int dsi_proto_config(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
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
switch (dsi_get_pixel_size(dssdev->panel.dsi_pix_fmt)) {
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
dsi_config_vp_num_line_buffers(dssdev);
if (dssdev->panel.dsi_mode == OMAP_DSS_DSI_VIDEO_MODE) {
dsi_config_vp_sync_events(dssdev);
dsi_config_blanking_modes(dssdev);
}
dsi_vc_initial_config(dsidev, 0);
dsi_vc_initial_config(dsidev, 1);
dsi_vc_initial_config(dsidev, 2);
dsi_vc_initial_config(dsidev, 3);
return 0;
}
static void dsi_proto_timings(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
unsigned tlpx, tclk_zero, tclk_prepare, tclk_trail;
unsigned tclk_pre, tclk_post;
unsigned ths_prepare, ths_prepare_ths_zero, ths_zero;
unsigned ths_trail, ths_exit;
unsigned ddr_clk_pre, ddr_clk_post;
unsigned enter_hs_mode_lat, exit_hs_mode_lat;
unsigned ths_eot;
int ndl = dsi_get_num_data_lanes_dssdev(dssdev);
u32 r;
r = dsi_read_reg(dsidev, DSI_DSIPHY_CFG0);
ths_prepare = FLD_GET(r, 31, 24);
ths_prepare_ths_zero = FLD_GET(r, 23, 16);
ths_zero = ths_prepare_ths_zero - ths_prepare;
ths_trail = FLD_GET(r, 15, 8);
ths_exit = FLD_GET(r, 7, 0);
r = dsi_read_reg(dsidev, DSI_DSIPHY_CFG1);
tlpx = FLD_GET(r, 22, 16) * 2;
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
if (dssdev->panel.dsi_mode == OMAP_DSS_DSI_VIDEO_MODE) {
int hsa = dssdev->panel.dsi_vm_data.hsa;
int hfp = dssdev->panel.dsi_vm_data.hfp;
int hbp = dssdev->panel.dsi_vm_data.hbp;
int vsa = dssdev->panel.dsi_vm_data.vsa;
int vfp = dssdev->panel.dsi_vm_data.vfp;
int vbp = dssdev->panel.dsi_vm_data.vbp;
int window_sync = dssdev->panel.dsi_vm_data.window_sync;
bool hsync_end = dssdev->panel.dsi_vm_data.vp_hsync_end;
struct omap_video_timings *timings = &dssdev->panel.timings;
int bpp = dsi_get_pixel_size(dssdev->panel.dsi_pix_fmt);
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
int dsi_video_mode_enable(struct omap_dss_device *dssdev, int channel)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
int bpp = dsi_get_pixel_size(dssdev->panel.dsi_pix_fmt);
u8 data_type;
u16 word_count;
switch (dssdev->panel.dsi_pix_fmt) {
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
};
dsi_if_enable(dsidev, false);
dsi_vc_enable(dsidev, channel, false);
REG_FLD_MOD(dsidev, DSI_VC_CTRL(channel), 1, 4, 4);
word_count = DIV_ROUND_UP(dssdev->panel.timings.x_res * bpp, 8);
dsi_vc_write_long_header(dsidev, channel, data_type, word_count, 0);
dsi_vc_enable(dsidev, channel, true);
dsi_if_enable(dsidev, true);
dssdev->manager->enable(dssdev->manager);
return 0;
}
void dsi_video_mode_disable(struct omap_dss_device *dssdev, int channel)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
dsi_if_enable(dsidev, false);
dsi_vc_enable(dsidev, channel, false);
REG_FLD_MOD(dsidev, DSI_VC_CTRL(channel), 0, 4, 4);
dsi_vc_enable(dsidev, channel, true);
dsi_if_enable(dsidev, true);
dssdev->manager->disable(dssdev->manager);
}
static void dsi_update_screen_dispc(struct omap_dss_device *dssdev,
u16 x, u16 y, u16 w, u16 h)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
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
DSSDBG("dsi_update_screen_dispc(%d,%d %dx%d)\n",
x, y, w, h);
dsi_vc_config_source(dsidev, channel, DSI_VC_SOURCE_VP);
bytespp = dsi_get_pixel_size(dssdev->panel.dsi_pix_fmt) / 8;
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
dss_start_update(dssdev);
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
struct omap_dss_device *dssdev = (struct omap_dss_device *) data;
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
__cancel_delayed_work(&dsi->framedone_timeout_work);
dsi_handle_framedone(dsidev, 0);
#ifdef CONFIG_OMAP2_DSS_FAKE_VSYNC
dispc_fake_vsync_irq();
#endif
}
int omap_dsi_prepare_update(struct omap_dss_device *dssdev,
u16 *x, u16 *y, u16 *w, u16 *h,
bool enlarge_update_area)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
u16 dw, dh;
dssdev->driver->get_resolution(dssdev, &dw, &dh);
if (*x > dw || *y > dh)
return -EINVAL;
if (*x + *w > dw)
return -EINVAL;
if (*y + *h > dh)
return -EINVAL;
if (*w == 1)
return -EINVAL;
if (*w == 0 || *h == 0)
return -EINVAL;
dsi_perf_mark_setup(dsidev);
dss_setup_partial_planes(dssdev, x, y, w, h,
enlarge_update_area);
dispc_mgr_set_lcd_size(dssdev->manager->id, *w, *h);
return 0;
}
int omap_dsi_update(struct omap_dss_device *dssdev,
int channel,
u16 x, u16 y, u16 w, u16 h,
void (*callback)(int, void *), void *data)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
dsi->update_channel = channel;
BUG_ON(x % 2 == 1);
dsi->framedone_callback = callback;
dsi->framedone_data = data;
dsi->update_region.x = x;
dsi->update_region.y = y;
dsi->update_region.w = w;
dsi->update_region.h = h;
dsi->update_region.device = dssdev;
dsi_update_screen_dispc(dssdev, x, y, w, h);
return 0;
}
static int dsi_display_init_dispc(struct omap_dss_device *dssdev)
{
int r;
if (dssdev->panel.dsi_mode == OMAP_DSS_DSI_CMD_MODE) {
u32 irq;
struct omap_video_timings timings = {
.hsw = 1,
.hfp = 1,
.hbp = 1,
.vsw = 1,
.vfp = 0,
.vbp = 0,
};
irq = dssdev->manager->id == OMAP_DSS_CHANNEL_LCD ?
DISPC_IRQ_FRAMEDONE : DISPC_IRQ_FRAMEDONE2;
r = omap_dispc_register_isr(dsi_framedone_irq_callback,
(void *) dssdev, irq);
if (r) {
DSSERR("can't get FRAMEDONE irq\n");
return r;
}
dispc_mgr_enable_stallmode(dssdev->manager->id, true);
dispc_mgr_enable_fifohandcheck(dssdev->manager->id, 1);
dispc_mgr_set_lcd_timings(dssdev->manager->id, &timings);
} else {
dispc_mgr_enable_stallmode(dssdev->manager->id, false);
dispc_mgr_enable_fifohandcheck(dssdev->manager->id, 0);
dispc_mgr_set_lcd_timings(dssdev->manager->id,
&dssdev->panel.timings);
}
dispc_mgr_set_lcd_display_type(dssdev->manager->id,
OMAP_DSS_LCD_DISPLAY_TFT);
dispc_mgr_set_tft_data_lines(dssdev->manager->id,
dsi_get_pixel_size(dssdev->panel.dsi_pix_fmt));
return 0;
}
static void dsi_display_uninit_dispc(struct omap_dss_device *dssdev)
{
if (dssdev->panel.dsi_mode == OMAP_DSS_DSI_CMD_MODE) {
u32 irq;
irq = dssdev->manager->id == OMAP_DSS_CHANNEL_LCD ?
DISPC_IRQ_FRAMEDONE : DISPC_IRQ_FRAMEDONE2;
omap_dispc_unregister_isr(dsi_framedone_irq_callback,
(void *) dssdev, irq);
}
}
static int dsi_configure_dsi_clocks(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_clock_info cinfo;
int r;
cinfo.use_sys_clk = true;
cinfo.regn = dssdev->clocks.dsi.regn;
cinfo.regm = dssdev->clocks.dsi.regm;
cinfo.regm_dispc = dssdev->clocks.dsi.regm_dispc;
cinfo.regm_dsi = dssdev->clocks.dsi.regm_dsi;
r = dsi_calc_clock_rates(dssdev, &cinfo);
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
static int dsi_configure_dispc_clocks(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
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
r = dispc_mgr_set_clock_div(dssdev->manager->id, &dispc_cinfo);
if (r) {
DSSERR("Failed to set dispc clocks\n");
return r;
}
return 0;
}
static int dsi_display_init_dsi(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
int dsi_module = dsi_get_dsidev_id(dsidev);
int r;
r = dsi_pll_init(dsidev, true, true);
if (r)
goto err0;
r = dsi_configure_dsi_clocks(dssdev);
if (r)
goto err1;
dss_select_dispc_clk_source(dssdev->clocks.dispc.dispc_fclk_src);
dss_select_dsi_clk_source(dsi_module, dssdev->clocks.dsi.dsi_fclk_src);
dss_select_lcd_clk_source(dssdev->manager->id,
dssdev->clocks.dispc.channel.lcd_clk_src);
DSSDBG("PLL OK\n");
r = dsi_configure_dispc_clocks(dssdev);
if (r)
goto err2;
r = dsi_cio_init(dssdev);
if (r)
goto err2;
_dsi_print_reset_status(dsidev);
dsi_proto_timings(dssdev);
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
dsi_cio_uninit(dssdev);
err2:
dss_select_dispc_clk_source(OMAP_DSS_CLK_SRC_FCK);
dss_select_dsi_clk_source(dsi_module, OMAP_DSS_CLK_SRC_FCK);
dss_select_lcd_clk_source(dssdev->manager->id, OMAP_DSS_CLK_SRC_FCK);
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
int dsi_module = dsi_get_dsidev_id(dsidev);
if (enter_ulps && !dsi->ulps_enabled)
dsi_enter_ulps(dsidev);
dsi_if_enable(dsidev, 0);
dsi_vc_enable(dsidev, 0, 0);
dsi_vc_enable(dsidev, 1, 0);
dsi_vc_enable(dsidev, 2, 0);
dsi_vc_enable(dsidev, 3, 0);
dss_select_dispc_clk_source(OMAP_DSS_CLK_SRC_FCK);
dss_select_dsi_clk_source(dsi_module, OMAP_DSS_CLK_SRC_FCK);
dss_select_lcd_clk_source(dssdev->manager->id, OMAP_DSS_CLK_SRC_FCK);
dsi_cio_uninit(dssdev);
dsi_pll_uninit(dsidev, disconnect_lanes);
}
int omapdss_dsi_display_enable(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int r = 0;
DSSDBG("dsi_display_enable\n");
WARN_ON(!dsi_bus_is_locked(dsidev));
mutex_lock(&dsi->lock);
if (dssdev->manager == NULL) {
DSSERR("failed to enable display: no manager\n");
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
void dsi_get_overlay_fifo_thresholds(enum omap_plane plane,
u32 fifo_size, u32 burst_size,
u32 *fifo_low, u32 *fifo_high)
{
*fifo_high = fifo_size - burst_size;
*fifo_low = fifo_size - burst_size * 2;
}
int dsi_init_display(struct omap_dss_device *dssdev)
{
struct platform_device *dsidev = dsi_get_dsidev_from_dssdev(dssdev);
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
int dsi_module = dsi_get_dsidev_id(dsidev);
DSSDBG("DSI init\n");
if (dssdev->panel.dsi_mode == OMAP_DSS_DSI_CMD_MODE) {
dssdev->caps = OMAP_DSS_DISPLAY_CAP_MANUAL_UPDATE |
OMAP_DSS_DISPLAY_CAP_TEAR_ELIM;
}
if (dsi->vdds_dsi_reg == NULL) {
struct regulator *vdds_dsi;
vdds_dsi = regulator_get(&dsi->pdev->dev, "vdds_dsi");
if (IS_ERR(vdds_dsi)) {
DSSERR("can't get VDDS_DSI regulator\n");
return PTR_ERR(vdds_dsi);
}
dsi->vdds_dsi_reg = vdds_dsi;
}
if (dsi_get_num_data_lanes_dssdev(dssdev) > dsi->num_data_lanes) {
DSSERR("DSI%d can't support more than %d data lanes\n",
dsi_module + 1, dsi->num_data_lanes);
return -EINVAL;
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
static int omap_dsihw_probe(struct platform_device *dsidev)
{
struct omap_display_platform_data *dss_plat_data;
struct omap_dss_board_info *board_info;
u32 rev;
int r, i, dsi_module = dsi_get_dsidev_id(dsidev);
struct resource *dsi_mem;
struct dsi_data *dsi;
dsi = kzalloc(sizeof(*dsi), GFP_KERNEL);
if (!dsi) {
r = -ENOMEM;
goto err_alloc;
}
dsi->pdev = dsidev;
dsi_pdev_map[dsi_module] = dsidev;
dev_set_drvdata(&dsidev->dev, dsi);
dss_plat_data = dsidev->dev.platform_data;
board_info = dss_plat_data->board_data;
dsi->enable_pads = board_info->dsi_enable_pads;
dsi->disable_pads = board_info->dsi_disable_pads;
spin_lock_init(&dsi->irq_lock);
spin_lock_init(&dsi->errors_lock);
dsi->errors = 0;
#ifdef CONFIG_OMAP2_DSS_COLLECT_IRQ_STATS
spin_lock_init(&dsi->irq_stats_lock);
dsi->irq_stats.last_reset = jiffies;
#endif
mutex_init(&dsi->lock);
sema_init(&dsi->bus_lock, 1);
r = dsi_get_clocks(dsidev);
if (r)
goto err_get_clk;
pm_runtime_enable(&dsidev->dev);
INIT_DELAYED_WORK_DEFERRABLE(&dsi->framedone_timeout_work,
dsi_framedone_timeout_work_callback);
#ifdef DSI_CATCH_MISSING_TE
init_timer(&dsi->te_timer);
dsi->te_timer.function = dsi_te_timeout;
dsi->te_timer.data = 0;
#endif
dsi_mem = platform_get_resource(dsi->pdev, IORESOURCE_MEM, 0);
if (!dsi_mem) {
DSSERR("can't get IORESOURCE_MEM DSI\n");
r = -EINVAL;
goto err_ioremap;
}
dsi->base = ioremap(dsi_mem->start, resource_size(dsi_mem));
if (!dsi->base) {
DSSERR("can't ioremap DSI\n");
r = -ENOMEM;
goto err_ioremap;
}
dsi->irq = platform_get_irq(dsi->pdev, 0);
if (dsi->irq < 0) {
DSSERR("platform_get_irq failed\n");
r = -ENODEV;
goto err_get_irq;
}
r = request_irq(dsi->irq, omap_dsi_irq_handler, IRQF_SHARED,
dev_name(&dsidev->dev), dsi->pdev);
if (r < 0) {
DSSERR("request_irq failed\n");
goto err_get_irq;
}
for (i = 0; i < ARRAY_SIZE(dsi->vc); i++) {
dsi->vc[i].source = DSI_VC_SOURCE_L4;
dsi->vc[i].dssdev = NULL;
dsi->vc[i].vc_id = 0;
}
dsi_calc_clock_param_ranges(dsidev);
r = dsi_runtime_get(dsidev);
if (r)
goto err_get_dsi;
rev = dsi_read_reg(dsidev, DSI_REVISION);
dev_dbg(&dsidev->dev, "OMAP DSI rev %d.%d\n",
FLD_GET(rev, 7, 4), FLD_GET(rev, 3, 0));
dsi->num_data_lanes = dsi_get_num_data_lanes(dsidev);
dsi_runtime_put(dsidev);
return 0;
err_get_dsi:
free_irq(dsi->irq, dsi->pdev);
err_get_irq:
iounmap(dsi->base);
err_ioremap:
pm_runtime_disable(&dsidev->dev);
err_get_clk:
kfree(dsi);
err_alloc:
return r;
}
static int omap_dsihw_remove(struct platform_device *dsidev)
{
struct dsi_data *dsi = dsi_get_dsidrv_data(dsidev);
WARN_ON(dsi->scp_clk_refcount > 0);
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
free_irq(dsi->irq, dsi->pdev);
iounmap(dsi->base);
kfree(dsi);
return 0;
}
static int dsi_runtime_suspend(struct device *dev)
{
dispc_runtime_put();
dss_runtime_put();
return 0;
}
static int dsi_runtime_resume(struct device *dev)
{
int r;
r = dss_runtime_get();
if (r)
goto err_get_dss;
r = dispc_runtime_get();
if (r)
goto err_get_dispc;
return 0;
err_get_dispc:
dss_runtime_put();
err_get_dss:
return r;
}
int dsi_init_platform_driver(void)
{
return platform_driver_register(&omap_dsihw_driver);
}
void dsi_uninit_platform_driver(void)
{
return platform_driver_unregister(&omap_dsihw_driver);
}
