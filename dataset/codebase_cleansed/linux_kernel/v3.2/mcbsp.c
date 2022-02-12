static void omap_mcbsp_write(struct omap_mcbsp *mcbsp, u16 reg, u32 val)
{
void __iomem *addr = mcbsp->io_base + reg * mcbsp->pdata->reg_step;
if (mcbsp->pdata->reg_size == 2) {
((u16 *)mcbsp->reg_cache)[reg] = (u16)val;
__raw_writew((u16)val, addr);
} else {
((u32 *)mcbsp->reg_cache)[reg] = val;
__raw_writel(val, addr);
}
}
static int omap_mcbsp_read(struct omap_mcbsp *mcbsp, u16 reg, bool from_cache)
{
void __iomem *addr = mcbsp->io_base + reg * mcbsp->pdata->reg_step;
if (mcbsp->pdata->reg_size == 2) {
return !from_cache ? __raw_readw(addr) :
((u16 *)mcbsp->reg_cache)[reg];
} else {
return !from_cache ? __raw_readl(addr) :
((u32 *)mcbsp->reg_cache)[reg];
}
}
static void omap_mcbsp_st_write(struct omap_mcbsp *mcbsp, u16 reg, u32 val)
{
__raw_writel(val, mcbsp->st_data->io_base_st + reg);
}
static int omap_mcbsp_st_read(struct omap_mcbsp *mcbsp, u16 reg)
{
return __raw_readl(mcbsp->st_data->io_base_st + reg);
}
static void omap_mcbsp_dump_reg(u8 id)
{
struct omap_mcbsp *mcbsp = id_to_mcbsp_ptr(id);
dev_dbg(mcbsp->dev, "**** McBSP%d regs ****\n", mcbsp->id);
dev_dbg(mcbsp->dev, "DRR2: 0x%04x\n",
MCBSP_READ(mcbsp, DRR2));
dev_dbg(mcbsp->dev, "DRR1: 0x%04x\n",
MCBSP_READ(mcbsp, DRR1));
dev_dbg(mcbsp->dev, "DXR2: 0x%04x\n",
MCBSP_READ(mcbsp, DXR2));
dev_dbg(mcbsp->dev, "DXR1: 0x%04x\n",
MCBSP_READ(mcbsp, DXR1));
dev_dbg(mcbsp->dev, "SPCR2: 0x%04x\n",
MCBSP_READ(mcbsp, SPCR2));
dev_dbg(mcbsp->dev, "SPCR1: 0x%04x\n",
MCBSP_READ(mcbsp, SPCR1));
dev_dbg(mcbsp->dev, "RCR2: 0x%04x\n",
MCBSP_READ(mcbsp, RCR2));
dev_dbg(mcbsp->dev, "RCR1: 0x%04x\n",
MCBSP_READ(mcbsp, RCR1));
dev_dbg(mcbsp->dev, "XCR2: 0x%04x\n",
MCBSP_READ(mcbsp, XCR2));
dev_dbg(mcbsp->dev, "XCR1: 0x%04x\n",
MCBSP_READ(mcbsp, XCR1));
dev_dbg(mcbsp->dev, "SRGR2: 0x%04x\n",
MCBSP_READ(mcbsp, SRGR2));
dev_dbg(mcbsp->dev, "SRGR1: 0x%04x\n",
MCBSP_READ(mcbsp, SRGR1));
dev_dbg(mcbsp->dev, "PCR0: 0x%04x\n",
MCBSP_READ(mcbsp, PCR0));
dev_dbg(mcbsp->dev, "***********************\n");
}
static irqreturn_t omap_mcbsp_tx_irq_handler(int irq, void *dev_id)
{
struct omap_mcbsp *mcbsp_tx = dev_id;
u16 irqst_spcr2;
irqst_spcr2 = MCBSP_READ(mcbsp_tx, SPCR2);
dev_dbg(mcbsp_tx->dev, "TX IRQ callback : 0x%x\n", irqst_spcr2);
if (irqst_spcr2 & XSYNC_ERR) {
dev_err(mcbsp_tx->dev, "TX Frame Sync Error! : 0x%x\n",
irqst_spcr2);
MCBSP_WRITE(mcbsp_tx, SPCR2, MCBSP_READ_CACHE(mcbsp_tx, SPCR2));
}
return IRQ_HANDLED;
}
static irqreturn_t omap_mcbsp_rx_irq_handler(int irq, void *dev_id)
{
struct omap_mcbsp *mcbsp_rx = dev_id;
u16 irqst_spcr1;
irqst_spcr1 = MCBSP_READ(mcbsp_rx, SPCR1);
dev_dbg(mcbsp_rx->dev, "RX IRQ callback : 0x%x\n", irqst_spcr1);
if (irqst_spcr1 & RSYNC_ERR) {
dev_err(mcbsp_rx->dev, "RX Frame Sync Error! : 0x%x\n",
irqst_spcr1);
MCBSP_WRITE(mcbsp_rx, SPCR1, MCBSP_READ_CACHE(mcbsp_rx, SPCR1));
}
return IRQ_HANDLED;
}
void omap_mcbsp_config(unsigned int id, const struct omap_mcbsp_reg_cfg *config)
{
struct omap_mcbsp *mcbsp;
if (!omap_mcbsp_check_valid_id(id)) {
printk(KERN_ERR "%s: Invalid id (%d)\n", __func__, id + 1);
return;
}
mcbsp = id_to_mcbsp_ptr(id);
dev_dbg(mcbsp->dev, "Configuring McBSP%d phys_base: 0x%08lx\n",
mcbsp->id, mcbsp->phys_base);
MCBSP_WRITE(mcbsp, SPCR2, config->spcr2);
MCBSP_WRITE(mcbsp, SPCR1, config->spcr1);
MCBSP_WRITE(mcbsp, RCR2, config->rcr2);
MCBSP_WRITE(mcbsp, RCR1, config->rcr1);
MCBSP_WRITE(mcbsp, XCR2, config->xcr2);
MCBSP_WRITE(mcbsp, XCR1, config->xcr1);
MCBSP_WRITE(mcbsp, SRGR2, config->srgr2);
MCBSP_WRITE(mcbsp, SRGR1, config->srgr1);
MCBSP_WRITE(mcbsp, MCR2, config->mcr2);
MCBSP_WRITE(mcbsp, MCR1, config->mcr1);
MCBSP_WRITE(mcbsp, PCR0, config->pcr0);
if (mcbsp->pdata->has_ccr) {
MCBSP_WRITE(mcbsp, XCCR, config->xccr);
MCBSP_WRITE(mcbsp, RCCR, config->rccr);
}
}
int omap_mcbsp_dma_ch_params(unsigned int id, unsigned int stream)
{
struct omap_mcbsp *mcbsp;
if (!omap_mcbsp_check_valid_id(id)) {
printk(KERN_ERR "%s: Invalid id (%d)\n", __func__, id + 1);
return -ENODEV;
}
mcbsp = id_to_mcbsp_ptr(id);
if (stream)
return mcbsp->dma_rx_sync;
else
return mcbsp->dma_tx_sync;
}
int omap_mcbsp_dma_reg_params(unsigned int id, unsigned int stream)
{
struct omap_mcbsp *mcbsp;
int data_reg;
if (!omap_mcbsp_check_valid_id(id)) {
printk(KERN_ERR "%s: Invalid id (%d)\n", __func__, id + 1);
return -ENODEV;
}
mcbsp = id_to_mcbsp_ptr(id);
if (mcbsp->pdata->reg_size == 2) {
if (stream)
data_reg = OMAP_MCBSP_REG_DRR1;
else
data_reg = OMAP_MCBSP_REG_DXR1;
} else {
if (stream)
data_reg = OMAP_MCBSP_REG_DRR;
else
data_reg = OMAP_MCBSP_REG_DXR;
}
return mcbsp->phys_dma_base + data_reg * mcbsp->pdata->reg_step;
}
static void omap_st_on(struct omap_mcbsp *mcbsp)
{
unsigned int w;
if (mcbsp->pdata->enable_st_clock)
mcbsp->pdata->enable_st_clock(mcbsp->id, 1);
w = MCBSP_READ(mcbsp, SSELCR);
MCBSP_WRITE(mcbsp, SSELCR, w | SIDETONEEN);
w = MCBSP_ST_READ(mcbsp, SSELCR);
MCBSP_ST_WRITE(mcbsp, SSELCR, w | ST_SIDETONEEN);
}
static void omap_st_off(struct omap_mcbsp *mcbsp)
{
unsigned int w;
w = MCBSP_ST_READ(mcbsp, SSELCR);
MCBSP_ST_WRITE(mcbsp, SSELCR, w & ~(ST_SIDETONEEN));
w = MCBSP_READ(mcbsp, SSELCR);
MCBSP_WRITE(mcbsp, SSELCR, w & ~(SIDETONEEN));
if (mcbsp->pdata->enable_st_clock)
mcbsp->pdata->enable_st_clock(mcbsp->id, 0);
}
static void omap_st_fir_write(struct omap_mcbsp *mcbsp, s16 *fir)
{
u16 val, i;
val = MCBSP_ST_READ(mcbsp, SSELCR);
if (val & ST_COEFFWREN)
MCBSP_ST_WRITE(mcbsp, SSELCR, val & ~(ST_COEFFWREN));
MCBSP_ST_WRITE(mcbsp, SSELCR, val | ST_COEFFWREN);
for (i = 0; i < 128; i++)
MCBSP_ST_WRITE(mcbsp, SFIRCR, fir[i]);
i = 0;
val = MCBSP_ST_READ(mcbsp, SSELCR);
while (!(val & ST_COEFFWRDONE) && (++i < 1000))
val = MCBSP_ST_READ(mcbsp, SSELCR);
MCBSP_ST_WRITE(mcbsp, SSELCR, val & ~(ST_COEFFWREN));
if (i == 1000)
dev_err(mcbsp->dev, "McBSP FIR load error!\n");
}
static void omap_st_chgain(struct omap_mcbsp *mcbsp)
{
u16 w;
struct omap_mcbsp_st_data *st_data = mcbsp->st_data;
w = MCBSP_ST_READ(mcbsp, SSELCR);
MCBSP_ST_WRITE(mcbsp, SGAINCR, ST_CH0GAIN(st_data->ch0gain) | \
ST_CH1GAIN(st_data->ch1gain));
}
int omap_st_set_chgain(unsigned int id, int channel, s16 chgain)
{
struct omap_mcbsp *mcbsp;
struct omap_mcbsp_st_data *st_data;
int ret = 0;
if (!omap_mcbsp_check_valid_id(id)) {
printk(KERN_ERR "%s: Invalid id (%d)\n", __func__, id + 1);
return -ENODEV;
}
mcbsp = id_to_mcbsp_ptr(id);
st_data = mcbsp->st_data;
if (!st_data)
return -ENOENT;
spin_lock_irq(&mcbsp->lock);
if (channel == 0)
st_data->ch0gain = chgain;
else if (channel == 1)
st_data->ch1gain = chgain;
else
ret = -EINVAL;
if (st_data->enabled)
omap_st_chgain(mcbsp);
spin_unlock_irq(&mcbsp->lock);
return ret;
}
int omap_st_get_chgain(unsigned int id, int channel, s16 *chgain)
{
struct omap_mcbsp *mcbsp;
struct omap_mcbsp_st_data *st_data;
int ret = 0;
if (!omap_mcbsp_check_valid_id(id)) {
printk(KERN_ERR "%s: Invalid id (%d)\n", __func__, id + 1);
return -ENODEV;
}
mcbsp = id_to_mcbsp_ptr(id);
st_data = mcbsp->st_data;
if (!st_data)
return -ENOENT;
spin_lock_irq(&mcbsp->lock);
if (channel == 0)
*chgain = st_data->ch0gain;
else if (channel == 1)
*chgain = st_data->ch1gain;
else
ret = -EINVAL;
spin_unlock_irq(&mcbsp->lock);
return ret;
}
static int omap_st_start(struct omap_mcbsp *mcbsp)
{
struct omap_mcbsp_st_data *st_data = mcbsp->st_data;
if (st_data && st_data->enabled && !st_data->running) {
omap_st_fir_write(mcbsp, st_data->taps);
omap_st_chgain(mcbsp);
if (!mcbsp->free) {
omap_st_on(mcbsp);
st_data->running = 1;
}
}
return 0;
}
int omap_st_enable(unsigned int id)
{
struct omap_mcbsp *mcbsp;
struct omap_mcbsp_st_data *st_data;
if (!omap_mcbsp_check_valid_id(id)) {
printk(KERN_ERR "%s: Invalid id (%d)\n", __func__, id + 1);
return -ENODEV;
}
mcbsp = id_to_mcbsp_ptr(id);
st_data = mcbsp->st_data;
if (!st_data)
return -ENODEV;
spin_lock_irq(&mcbsp->lock);
st_data->enabled = 1;
omap_st_start(mcbsp);
spin_unlock_irq(&mcbsp->lock);
return 0;
}
static int omap_st_stop(struct omap_mcbsp *mcbsp)
{
struct omap_mcbsp_st_data *st_data = mcbsp->st_data;
if (st_data && st_data->running) {
if (!mcbsp->free) {
omap_st_off(mcbsp);
st_data->running = 0;
}
}
return 0;
}
int omap_st_disable(unsigned int id)
{
struct omap_mcbsp *mcbsp;
struct omap_mcbsp_st_data *st_data;
int ret = 0;
if (!omap_mcbsp_check_valid_id(id)) {
printk(KERN_ERR "%s: Invalid id (%d)\n", __func__, id + 1);
return -ENODEV;
}
mcbsp = id_to_mcbsp_ptr(id);
st_data = mcbsp->st_data;
if (!st_data)
return -ENODEV;
spin_lock_irq(&mcbsp->lock);
omap_st_stop(mcbsp);
st_data->enabled = 0;
spin_unlock_irq(&mcbsp->lock);
return ret;
}
int omap_st_is_enabled(unsigned int id)
{
struct omap_mcbsp *mcbsp;
struct omap_mcbsp_st_data *st_data;
if (!omap_mcbsp_check_valid_id(id)) {
printk(KERN_ERR "%s: Invalid id (%d)\n", __func__, id + 1);
return -ENODEV;
}
mcbsp = id_to_mcbsp_ptr(id);
st_data = mcbsp->st_data;
if (!st_data)
return -ENODEV;
return st_data->enabled;
}
void omap_mcbsp_set_tx_threshold(unsigned int id, u16 threshold)
{
struct omap_mcbsp *mcbsp;
if (!omap_mcbsp_check_valid_id(id)) {
printk(KERN_ERR "%s: Invalid id (%d)\n", __func__, id + 1);
return;
}
mcbsp = id_to_mcbsp_ptr(id);
if (mcbsp->pdata->buffer_size == 0)
return;
if (threshold && threshold <= mcbsp->max_tx_thres)
MCBSP_WRITE(mcbsp, THRSH2, threshold - 1);
}
void omap_mcbsp_set_rx_threshold(unsigned int id, u16 threshold)
{
struct omap_mcbsp *mcbsp;
if (!omap_mcbsp_check_valid_id(id)) {
printk(KERN_ERR "%s: Invalid id (%d)\n", __func__, id + 1);
return;
}
mcbsp = id_to_mcbsp_ptr(id);
if (mcbsp->pdata->buffer_size == 0)
return;
if (threshold && threshold <= mcbsp->max_rx_thres)
MCBSP_WRITE(mcbsp, THRSH1, threshold - 1);
}
u16 omap_mcbsp_get_max_tx_threshold(unsigned int id)
{
struct omap_mcbsp *mcbsp;
if (!omap_mcbsp_check_valid_id(id)) {
printk(KERN_ERR "%s: Invalid id (%d)\n", __func__, id + 1);
return -ENODEV;
}
mcbsp = id_to_mcbsp_ptr(id);
return mcbsp->max_tx_thres;
}
u16 omap_mcbsp_get_max_rx_threshold(unsigned int id)
{
struct omap_mcbsp *mcbsp;
if (!omap_mcbsp_check_valid_id(id)) {
printk(KERN_ERR "%s: Invalid id (%d)\n", __func__, id + 1);
return -ENODEV;
}
mcbsp = id_to_mcbsp_ptr(id);
return mcbsp->max_rx_thres;
}
u16 omap_mcbsp_get_fifo_size(unsigned int id)
{
struct omap_mcbsp *mcbsp;
if (!omap_mcbsp_check_valid_id(id)) {
printk(KERN_ERR "%s: Invalid id (%d)\n", __func__, id + 1);
return -ENODEV;
}
mcbsp = id_to_mcbsp_ptr(id);
return mcbsp->pdata->buffer_size;
}
u16 omap_mcbsp_get_tx_delay(unsigned int id)
{
struct omap_mcbsp *mcbsp;
u16 buffstat;
if (!omap_mcbsp_check_valid_id(id)) {
printk(KERN_ERR "%s: Invalid id (%d)\n", __func__, id + 1);
return -ENODEV;
}
mcbsp = id_to_mcbsp_ptr(id);
if (mcbsp->pdata->buffer_size == 0)
return 0;
buffstat = MCBSP_READ(mcbsp, XBUFFSTAT);
return mcbsp->pdata->buffer_size - buffstat;
}
u16 omap_mcbsp_get_rx_delay(unsigned int id)
{
struct omap_mcbsp *mcbsp;
u16 buffstat, threshold;
if (!omap_mcbsp_check_valid_id(id)) {
printk(KERN_ERR "%s: Invalid id (%d)\n", __func__, id + 1);
return -ENODEV;
}
mcbsp = id_to_mcbsp_ptr(id);
if (mcbsp->pdata->buffer_size == 0)
return 0;
buffstat = MCBSP_READ(mcbsp, RBUFFSTAT);
threshold = MCBSP_READ(mcbsp, THRSH1);
if (threshold <= buffstat)
return 0;
else
return threshold - buffstat;
}
int omap_mcbsp_get_dma_op_mode(unsigned int id)
{
struct omap_mcbsp *mcbsp;
int dma_op_mode;
if (!omap_mcbsp_check_valid_id(id)) {
printk(KERN_ERR "%s: Invalid id (%u)\n", __func__, id + 1);
return -ENODEV;
}
mcbsp = id_to_mcbsp_ptr(id);
dma_op_mode = mcbsp->dma_op_mode;
return dma_op_mode;
}
int omap_mcbsp_request(unsigned int id)
{
struct omap_mcbsp *mcbsp;
void *reg_cache;
int err;
if (!omap_mcbsp_check_valid_id(id)) {
printk(KERN_ERR "%s: Invalid id (%d)\n", __func__, id + 1);
return -ENODEV;
}
mcbsp = id_to_mcbsp_ptr(id);
reg_cache = kzalloc(mcbsp->reg_cache_size, GFP_KERNEL);
if (!reg_cache) {
return -ENOMEM;
}
spin_lock(&mcbsp->lock);
if (!mcbsp->free) {
dev_err(mcbsp->dev, "McBSP%d is currently in use\n",
mcbsp->id);
err = -EBUSY;
goto err_kfree;
}
mcbsp->free = false;
mcbsp->reg_cache = reg_cache;
spin_unlock(&mcbsp->lock);
if (mcbsp->pdata && mcbsp->pdata->ops && mcbsp->pdata->ops->request)
mcbsp->pdata->ops->request(id);
pm_runtime_get_sync(mcbsp->dev);
if (mcbsp->pdata->has_wakeup)
MCBSP_WRITE(mcbsp, WAKEUPEN, XRDYEN | RRDYEN);
MCBSP_WRITE(mcbsp, SPCR1, 0);
MCBSP_WRITE(mcbsp, SPCR2, 0);
err = request_irq(mcbsp->tx_irq, omap_mcbsp_tx_irq_handler,
0, "McBSP", (void *)mcbsp);
if (err != 0) {
dev_err(mcbsp->dev, "Unable to request TX IRQ %d "
"for McBSP%d\n", mcbsp->tx_irq,
mcbsp->id);
goto err_clk_disable;
}
if (mcbsp->rx_irq) {
err = request_irq(mcbsp->rx_irq,
omap_mcbsp_rx_irq_handler,
0, "McBSP", (void *)mcbsp);
if (err != 0) {
dev_err(mcbsp->dev, "Unable to request RX IRQ %d "
"for McBSP%d\n", mcbsp->rx_irq,
mcbsp->id);
goto err_free_irq;
}
}
return 0;
err_free_irq:
free_irq(mcbsp->tx_irq, (void *)mcbsp);
err_clk_disable:
if (mcbsp->pdata && mcbsp->pdata->ops && mcbsp->pdata->ops->free)
mcbsp->pdata->ops->free(id);
if (mcbsp->pdata->has_wakeup)
MCBSP_WRITE(mcbsp, WAKEUPEN, 0);
pm_runtime_put_sync(mcbsp->dev);
spin_lock(&mcbsp->lock);
mcbsp->free = true;
mcbsp->reg_cache = NULL;
err_kfree:
spin_unlock(&mcbsp->lock);
kfree(reg_cache);
return err;
}
void omap_mcbsp_free(unsigned int id)
{
struct omap_mcbsp *mcbsp;
void *reg_cache;
if (!omap_mcbsp_check_valid_id(id)) {
printk(KERN_ERR "%s: Invalid id (%d)\n", __func__, id + 1);
return;
}
mcbsp = id_to_mcbsp_ptr(id);
if (mcbsp->pdata && mcbsp->pdata->ops && mcbsp->pdata->ops->free)
mcbsp->pdata->ops->free(id);
if (mcbsp->pdata->has_wakeup)
MCBSP_WRITE(mcbsp, WAKEUPEN, 0);
pm_runtime_put_sync(mcbsp->dev);
if (mcbsp->rx_irq)
free_irq(mcbsp->rx_irq, (void *)mcbsp);
free_irq(mcbsp->tx_irq, (void *)mcbsp);
reg_cache = mcbsp->reg_cache;
spin_lock(&mcbsp->lock);
if (mcbsp->free)
dev_err(mcbsp->dev, "McBSP%d was not reserved\n", mcbsp->id);
else
mcbsp->free = true;
mcbsp->reg_cache = NULL;
spin_unlock(&mcbsp->lock);
if (reg_cache)
kfree(reg_cache);
}
void omap_mcbsp_start(unsigned int id, int tx, int rx)
{
struct omap_mcbsp *mcbsp;
int enable_srg = 0;
u16 w;
if (!omap_mcbsp_check_valid_id(id)) {
printk(KERN_ERR "%s: Invalid id (%d)\n", __func__, id + 1);
return;
}
mcbsp = id_to_mcbsp_ptr(id);
if (mcbsp->st_data)
omap_st_start(mcbsp);
w = MCBSP_READ_CACHE(mcbsp, PCR0);
if (w & (FSXM | FSRM | CLKXM | CLKRM))
enable_srg = !((MCBSP_READ_CACHE(mcbsp, SPCR2) |
MCBSP_READ_CACHE(mcbsp, SPCR1)) & 1);
if (enable_srg) {
w = MCBSP_READ_CACHE(mcbsp, SPCR2);
MCBSP_WRITE(mcbsp, SPCR2, w | (1 << 6));
}
tx &= 1;
w = MCBSP_READ_CACHE(mcbsp, SPCR2);
MCBSP_WRITE(mcbsp, SPCR2, w | tx);
rx &= 1;
w = MCBSP_READ_CACHE(mcbsp, SPCR1);
MCBSP_WRITE(mcbsp, SPCR1, w | rx);
udelay(500);
if (enable_srg) {
w = MCBSP_READ_CACHE(mcbsp, SPCR2);
MCBSP_WRITE(mcbsp, SPCR2, w | (1 << 7));
}
if (mcbsp->pdata->has_ccr) {
w = MCBSP_READ_CACHE(mcbsp, XCCR);
w &= ~(tx ? XDISABLE : 0);
MCBSP_WRITE(mcbsp, XCCR, w);
w = MCBSP_READ_CACHE(mcbsp, RCCR);
w &= ~(rx ? RDISABLE : 0);
MCBSP_WRITE(mcbsp, RCCR, w);
}
omap_mcbsp_dump_reg(id);
}
void omap_mcbsp_stop(unsigned int id, int tx, int rx)
{
struct omap_mcbsp *mcbsp;
int idle;
u16 w;
if (!omap_mcbsp_check_valid_id(id)) {
printk(KERN_ERR "%s: Invalid id (%d)\n", __func__, id + 1);
return;
}
mcbsp = id_to_mcbsp_ptr(id);
tx &= 1;
if (mcbsp->pdata->has_ccr) {
w = MCBSP_READ_CACHE(mcbsp, XCCR);
w |= (tx ? XDISABLE : 0);
MCBSP_WRITE(mcbsp, XCCR, w);
}
w = MCBSP_READ_CACHE(mcbsp, SPCR2);
MCBSP_WRITE(mcbsp, SPCR2, w & ~tx);
rx &= 1;
if (mcbsp->pdata->has_ccr) {
w = MCBSP_READ_CACHE(mcbsp, RCCR);
w |= (rx ? RDISABLE : 0);
MCBSP_WRITE(mcbsp, RCCR, w);
}
w = MCBSP_READ_CACHE(mcbsp, SPCR1);
MCBSP_WRITE(mcbsp, SPCR1, w & ~rx);
idle = !((MCBSP_READ_CACHE(mcbsp, SPCR2) |
MCBSP_READ_CACHE(mcbsp, SPCR1)) & 1);
if (idle) {
w = MCBSP_READ_CACHE(mcbsp, SPCR2);
MCBSP_WRITE(mcbsp, SPCR2, w & ~(1 << 6));
}
if (mcbsp->st_data)
omap_st_stop(mcbsp);
}
int omap2_mcbsp_set_clks_src(u8 id, u8 fck_src_id)
{
struct omap_mcbsp *mcbsp;
const char *src;
if (!omap_mcbsp_check_valid_id(id)) {
pr_err("%s: Invalid id (%d)\n", __func__, id + 1);
return -EINVAL;
}
mcbsp = id_to_mcbsp_ptr(id);
if (fck_src_id == MCBSP_CLKS_PAD_SRC)
src = "clks_ext";
else if (fck_src_id == MCBSP_CLKS_PRCM_SRC)
src = "clks_fclk";
else
return -EINVAL;
if (mcbsp->pdata->set_clk_src)
return mcbsp->pdata->set_clk_src(mcbsp->dev, mcbsp->fclk, src);
else
return -EINVAL;
}
void omap2_mcbsp1_mux_clkr_src(u8 mux)
{
struct omap_mcbsp *mcbsp;
const char *src;
if (mux == CLKR_SRC_CLKR)
src = "clkr";
else if (mux == CLKR_SRC_CLKX)
src = "clkx";
else
return;
mcbsp = id_to_mcbsp_ptr(0);
if (mcbsp->pdata->mux_signal)
mcbsp->pdata->mux_signal(mcbsp->dev, "clkr", src);
}
void omap2_mcbsp1_mux_fsr_src(u8 mux)
{
struct omap_mcbsp *mcbsp;
const char *src;
if (mux == FSR_SRC_FSR)
src = "fsr";
else if (mux == FSR_SRC_FSX)
src = "fsx";
else
return;
mcbsp = id_to_mcbsp_ptr(0);
if (mcbsp->pdata->mux_signal)
mcbsp->pdata->mux_signal(mcbsp->dev, "fsr", src);
}
static ssize_t dma_op_mode_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct omap_mcbsp *mcbsp = dev_get_drvdata(dev);
int dma_op_mode, i = 0;
ssize_t len = 0;
const char * const *s;
dma_op_mode = mcbsp->dma_op_mode;
for (s = &dma_op_modes[i]; i < ARRAY_SIZE(dma_op_modes); s++, i++) {
if (dma_op_mode == i)
len += sprintf(buf + len, "[%s] ", *s);
else
len += sprintf(buf + len, "%s ", *s);
}
len += sprintf(buf + len, "\n");
return len;
}
static ssize_t dma_op_mode_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
struct omap_mcbsp *mcbsp = dev_get_drvdata(dev);
const char * const *s;
int i = 0;
for (s = &dma_op_modes[i]; i < ARRAY_SIZE(dma_op_modes); s++, i++)
if (sysfs_streq(buf, *s))
break;
if (i == ARRAY_SIZE(dma_op_modes))
return -EINVAL;
spin_lock_irq(&mcbsp->lock);
if (!mcbsp->free) {
size = -EBUSY;
goto unlock;
}
mcbsp->dma_op_mode = i;
unlock:
spin_unlock_irq(&mcbsp->lock);
return size;
}
static ssize_t st_taps_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct omap_mcbsp *mcbsp = dev_get_drvdata(dev);
struct omap_mcbsp_st_data *st_data = mcbsp->st_data;
ssize_t status = 0;
int i;
spin_lock_irq(&mcbsp->lock);
for (i = 0; i < st_data->nr_taps; i++)
status += sprintf(&buf[status], (i ? ", %d" : "%d"),
st_data->taps[i]);
if (i)
status += sprintf(&buf[status], "\n");
spin_unlock_irq(&mcbsp->lock);
return status;
}
static ssize_t st_taps_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
struct omap_mcbsp *mcbsp = dev_get_drvdata(dev);
struct omap_mcbsp_st_data *st_data = mcbsp->st_data;
int val, tmp, status, i = 0;
spin_lock_irq(&mcbsp->lock);
memset(st_data->taps, 0, sizeof(st_data->taps));
st_data->nr_taps = 0;
do {
status = sscanf(buf, "%d%n", &val, &tmp);
if (status < 0 || status == 0) {
size = -EINVAL;
goto out;
}
if (val < -32768 || val > 32767) {
size = -EINVAL;
goto out;
}
st_data->taps[i++] = val;
buf += tmp;
if (*buf != ',')
break;
buf++;
} while (1);
st_data->nr_taps = i;
out:
spin_unlock_irq(&mcbsp->lock);
return size;
}
static int __devinit omap_st_add(struct omap_mcbsp *mcbsp,
struct resource *res)
{
struct omap_mcbsp_st_data *st_data;
int err;
st_data = kzalloc(sizeof(*mcbsp->st_data), GFP_KERNEL);
if (!st_data) {
err = -ENOMEM;
goto err1;
}
st_data->io_base_st = ioremap(res->start, resource_size(res));
if (!st_data->io_base_st) {
err = -ENOMEM;
goto err2;
}
err = sysfs_create_group(&mcbsp->dev->kobj, &sidetone_attr_group);
if (err)
goto err3;
mcbsp->st_data = st_data;
return 0;
err3:
iounmap(st_data->io_base_st);
err2:
kfree(st_data);
err1:
return err;
}
static void __devexit omap_st_remove(struct omap_mcbsp *mcbsp)
{
struct omap_mcbsp_st_data *st_data = mcbsp->st_data;
sysfs_remove_group(&mcbsp->dev->kobj, &sidetone_attr_group);
iounmap(st_data->io_base_st);
kfree(st_data);
}
static int __devinit omap_mcbsp_probe(struct platform_device *pdev)
{
struct omap_mcbsp_platform_data *pdata = pdev->dev.platform_data;
struct omap_mcbsp *mcbsp;
int id = pdev->id - 1;
struct resource *res;
int ret = 0;
if (!pdata) {
dev_err(&pdev->dev, "McBSP device initialized without"
"platform data\n");
ret = -EINVAL;
goto exit;
}
dev_dbg(&pdev->dev, "Initializing OMAP McBSP (%d).\n", pdev->id);
if (id >= omap_mcbsp_count) {
dev_err(&pdev->dev, "Invalid McBSP device id (%d)\n", id);
ret = -EINVAL;
goto exit;
}
mcbsp = kzalloc(sizeof(struct omap_mcbsp), GFP_KERNEL);
if (!mcbsp) {
ret = -ENOMEM;
goto exit;
}
spin_lock_init(&mcbsp->lock);
mcbsp->id = id + 1;
mcbsp->free = true;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "mpu");
if (!res) {
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "%s:mcbsp%d has invalid memory"
"resource\n", __func__, pdev->id);
ret = -ENOMEM;
goto exit;
}
}
mcbsp->phys_base = res->start;
mcbsp->reg_cache_size = resource_size(res);
mcbsp->io_base = ioremap(res->start, resource_size(res));
if (!mcbsp->io_base) {
ret = -ENOMEM;
goto err_ioremap;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "dma");
if (!res)
mcbsp->phys_dma_base = mcbsp->phys_base;
else
mcbsp->phys_dma_base = res->start;
mcbsp->tx_irq = platform_get_irq_byname(pdev, "tx");
mcbsp->rx_irq = platform_get_irq_byname(pdev, "rx");
if (mcbsp->tx_irq == -ENXIO)
mcbsp->tx_irq = platform_get_irq(pdev, 0);
res = platform_get_resource_byname(pdev, IORESOURCE_DMA, "rx");
if (!res) {
dev_err(&pdev->dev, "%s:mcbsp%d has invalid rx DMA channel\n",
__func__, pdev->id);
ret = -ENODEV;
goto err_res;
}
mcbsp->dma_rx_sync = res->start;
res = platform_get_resource_byname(pdev, IORESOURCE_DMA, "tx");
if (!res) {
dev_err(&pdev->dev, "%s:mcbsp%d has invalid tx DMA channel\n",
__func__, pdev->id);
ret = -ENODEV;
goto err_res;
}
mcbsp->dma_tx_sync = res->start;
mcbsp->fclk = clk_get(&pdev->dev, "fck");
if (IS_ERR(mcbsp->fclk)) {
ret = PTR_ERR(mcbsp->fclk);
dev_err(&pdev->dev, "unable to get fck: %d\n", ret);
goto err_res;
}
mcbsp->pdata = pdata;
mcbsp->dev = &pdev->dev;
mcbsp_ptr[id] = mcbsp;
platform_set_drvdata(pdev, mcbsp);
pm_runtime_enable(mcbsp->dev);
mcbsp->dma_op_mode = MCBSP_DMA_MODE_ELEMENT;
if (mcbsp->pdata->buffer_size) {
mcbsp->max_tx_thres = max_thres(mcbsp) - 0x10;
mcbsp->max_rx_thres = max_thres(mcbsp) - 0x10;
ret = sysfs_create_group(&mcbsp->dev->kobj,
&additional_attr_group);
if (ret) {
dev_err(mcbsp->dev,
"Unable to create additional controls\n");
goto err_thres;
}
} else {
mcbsp->max_tx_thres = -EINVAL;
mcbsp->max_rx_thres = -EINVAL;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "sidetone");
if (res) {
ret = omap_st_add(mcbsp, res);
if (ret) {
dev_err(mcbsp->dev,
"Unable to create sidetone controls\n");
goto err_st;
}
}
return 0;
err_st:
if (mcbsp->pdata->buffer_size)
sysfs_remove_group(&mcbsp->dev->kobj,
&additional_attr_group);
err_thres:
clk_put(mcbsp->fclk);
err_res:
iounmap(mcbsp->io_base);
err_ioremap:
kfree(mcbsp);
exit:
return ret;
}
static int __devexit omap_mcbsp_remove(struct platform_device *pdev)
{
struct omap_mcbsp *mcbsp = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
if (mcbsp) {
if (mcbsp->pdata && mcbsp->pdata->ops &&
mcbsp->pdata->ops->free)
mcbsp->pdata->ops->free(mcbsp->id);
if (mcbsp->pdata->buffer_size)
sysfs_remove_group(&mcbsp->dev->kobj,
&additional_attr_group);
if (mcbsp->st_data)
omap_st_remove(mcbsp);
clk_put(mcbsp->fclk);
iounmap(mcbsp->io_base);
kfree(mcbsp);
}
return 0;
}
int __init omap_mcbsp_init(void)
{
return platform_driver_register(&omap_mcbsp_driver);
}
