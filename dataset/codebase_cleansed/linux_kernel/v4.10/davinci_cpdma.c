static void cpdma_desc_pool_destroy(struct cpdma_desc_pool *pool)
{
if (!pool)
return;
WARN(gen_pool_size(pool->gen_pool) != gen_pool_avail(pool->gen_pool),
"cpdma_desc_pool size %d != avail %d",
gen_pool_size(pool->gen_pool),
gen_pool_avail(pool->gen_pool));
if (pool->cpumap)
dma_free_coherent(pool->dev, pool->mem_size, pool->cpumap,
pool->phys);
else
iounmap(pool->iomap);
}
static struct cpdma_desc_pool *
cpdma_desc_pool_create(struct device *dev, u32 phys, dma_addr_t hw_addr,
int size, int align)
{
struct cpdma_desc_pool *pool;
int ret;
pool = devm_kzalloc(dev, sizeof(*pool), GFP_KERNEL);
if (!pool)
goto gen_pool_create_fail;
pool->dev = dev;
pool->mem_size = size;
pool->desc_size = ALIGN(sizeof(struct cpdma_desc), align);
pool->num_desc = size / pool->desc_size;
pool->gen_pool = devm_gen_pool_create(dev, ilog2(pool->desc_size), -1,
"cpdma");
if (IS_ERR(pool->gen_pool)) {
dev_err(dev, "pool create failed %ld\n",
PTR_ERR(pool->gen_pool));
goto gen_pool_create_fail;
}
if (phys) {
pool->phys = phys;
pool->iomap = ioremap(phys, size);
pool->hw_addr = hw_addr;
} else {
pool->cpumap = dma_alloc_coherent(dev, size, &pool->hw_addr,
GFP_KERNEL);
pool->iomap = (void __iomem __force *)pool->cpumap;
pool->phys = pool->hw_addr;
}
if (!pool->iomap)
goto gen_pool_create_fail;
ret = gen_pool_add_virt(pool->gen_pool, (unsigned long)pool->iomap,
pool->phys, pool->mem_size, -1);
if (ret < 0) {
dev_err(dev, "pool add failed %d\n", ret);
goto gen_pool_add_virt_fail;
}
return pool;
gen_pool_add_virt_fail:
cpdma_desc_pool_destroy(pool);
gen_pool_create_fail:
return NULL;
}
static inline dma_addr_t desc_phys(struct cpdma_desc_pool *pool,
struct cpdma_desc __iomem *desc)
{
if (!desc)
return 0;
return pool->hw_addr + (__force long)desc - (__force long)pool->iomap;
}
static inline struct cpdma_desc __iomem *
desc_from_phys(struct cpdma_desc_pool *pool, dma_addr_t dma)
{
return dma ? pool->iomap + dma - pool->hw_addr : NULL;
}
static struct cpdma_desc __iomem *
cpdma_desc_alloc(struct cpdma_desc_pool *pool)
{
return (struct cpdma_desc __iomem *)
gen_pool_alloc(pool->gen_pool, pool->desc_size);
}
static void cpdma_desc_free(struct cpdma_desc_pool *pool,
struct cpdma_desc __iomem *desc, int num_desc)
{
gen_pool_free(pool->gen_pool, (unsigned long)desc, pool->desc_size);
}
static int _cpdma_control_set(struct cpdma_ctlr *ctlr, int control, int value)
{
struct cpdma_control_info *info = &controls[control];
u32 val;
if (!ctlr->params.has_ext_regs)
return -ENOTSUPP;
if (ctlr->state != CPDMA_STATE_ACTIVE)
return -EINVAL;
if (control < 0 || control >= ARRAY_SIZE(controls))
return -ENOENT;
if ((info->access & ACCESS_WO) != ACCESS_WO)
return -EPERM;
val = dma_reg_read(ctlr, info->reg);
val &= ~(info->mask << info->shift);
val |= (value & info->mask) << info->shift;
dma_reg_write(ctlr, info->reg, val);
return 0;
}
static int _cpdma_control_get(struct cpdma_ctlr *ctlr, int control)
{
struct cpdma_control_info *info = &controls[control];
int ret;
if (!ctlr->params.has_ext_regs)
return -ENOTSUPP;
if (ctlr->state != CPDMA_STATE_ACTIVE)
return -EINVAL;
if (control < 0 || control >= ARRAY_SIZE(controls))
return -ENOENT;
if ((info->access & ACCESS_RO) != ACCESS_RO)
return -EPERM;
ret = (dma_reg_read(ctlr, info->reg) >> info->shift) & info->mask;
return ret;
}
static int cpdma_chan_set_chan_shaper(struct cpdma_chan *chan)
{
struct cpdma_ctlr *ctlr = chan->ctlr;
u32 rate_reg;
u32 rmask;
int ret;
if (!chan->rate)
return 0;
rate_reg = CPDMA_TX_PRI0_RATE + 4 * chan->chan_num;
dma_reg_write(ctlr, rate_reg, chan->rate_factor);
rmask = _cpdma_control_get(ctlr, CPDMA_TX_RLIM);
rmask |= chan->mask;
ret = _cpdma_control_set(ctlr, CPDMA_TX_RLIM, rmask);
return ret;
}
static int cpdma_chan_on(struct cpdma_chan *chan)
{
struct cpdma_ctlr *ctlr = chan->ctlr;
struct cpdma_desc_pool *pool = ctlr->pool;
unsigned long flags;
spin_lock_irqsave(&chan->lock, flags);
if (chan->state != CPDMA_STATE_IDLE) {
spin_unlock_irqrestore(&chan->lock, flags);
return -EBUSY;
}
if (ctlr->state != CPDMA_STATE_ACTIVE) {
spin_unlock_irqrestore(&chan->lock, flags);
return -EINVAL;
}
dma_reg_write(ctlr, chan->int_set, chan->mask);
chan->state = CPDMA_STATE_ACTIVE;
if (chan->head) {
chan_write(chan, hdp, desc_phys(pool, chan->head));
if (chan->rxfree)
chan_write(chan, rxfree, chan->count);
}
spin_unlock_irqrestore(&chan->lock, flags);
return 0;
}
static int cpdma_chan_fit_rate(struct cpdma_chan *ch, u32 rate,
u32 *rmask, int *prio_mode)
{
struct cpdma_ctlr *ctlr = ch->ctlr;
struct cpdma_chan *chan;
u32 old_rate = ch->rate;
u32 new_rmask = 0;
int rlim = 1;
int i;
*prio_mode = 0;
for (i = tx_chan_num(0); i < tx_chan_num(CPDMA_MAX_CHANNELS); i++) {
chan = ctlr->channels[i];
if (!chan) {
rlim = 0;
continue;
}
if (chan == ch)
chan->rate = rate;
if (chan->rate) {
if (rlim) {
new_rmask |= chan->mask;
} else {
ch->rate = old_rate;
dev_err(ctlr->dev, "Prev channel of %dch is not rate limited\n",
chan->chan_num);
return -EINVAL;
}
} else {
*prio_mode = 1;
rlim = 0;
}
}
*rmask = new_rmask;
return 0;
}
static u32 cpdma_chan_set_factors(struct cpdma_ctlr *ctlr,
struct cpdma_chan *ch)
{
u32 delta = UINT_MAX, prev_delta = UINT_MAX, best_delta = UINT_MAX;
u32 best_send_cnt = 0, best_idle_cnt = 0;
u32 new_rate, best_rate = 0, rate_reg;
u64 send_cnt, idle_cnt;
u32 min_send_cnt, freq;
u64 divident, divisor;
if (!ch->rate) {
ch->rate_factor = 0;
goto set_factor;
}
freq = ctlr->params.bus_freq_mhz * 1000 * 32;
if (!freq) {
dev_err(ctlr->dev, "The bus frequency is not set\n");
return -EINVAL;
}
min_send_cnt = freq - ch->rate;
send_cnt = DIV_ROUND_UP(min_send_cnt, ch->rate);
while (send_cnt <= CPDMA_MAX_RLIM_CNT) {
divident = ch->rate * send_cnt;
divisor = min_send_cnt;
idle_cnt = DIV_ROUND_CLOSEST_ULL(divident, divisor);
divident = freq * idle_cnt;
divisor = idle_cnt + send_cnt;
new_rate = DIV_ROUND_CLOSEST_ULL(divident, divisor);
delta = new_rate >= ch->rate ? new_rate - ch->rate : delta;
if (delta < best_delta) {
best_delta = delta;
best_send_cnt = send_cnt;
best_idle_cnt = idle_cnt;
best_rate = new_rate;
if (!delta)
break;
}
if (prev_delta >= delta) {
prev_delta = delta;
send_cnt++;
continue;
}
idle_cnt++;
divident = freq * idle_cnt;
send_cnt = DIV_ROUND_CLOSEST_ULL(divident, ch->rate);
send_cnt -= idle_cnt;
prev_delta = UINT_MAX;
}
ch->rate = best_rate;
ch->rate_factor = best_send_cnt | (best_idle_cnt << 16);
set_factor:
rate_reg = CPDMA_TX_PRI0_RATE + 4 * ch->chan_num;
dma_reg_write(ctlr, rate_reg, ch->rate_factor);
return 0;
}
struct cpdma_ctlr *cpdma_ctlr_create(struct cpdma_params *params)
{
struct cpdma_ctlr *ctlr;
ctlr = devm_kzalloc(params->dev, sizeof(*ctlr), GFP_KERNEL);
if (!ctlr)
return NULL;
ctlr->state = CPDMA_STATE_IDLE;
ctlr->params = *params;
ctlr->dev = params->dev;
ctlr->chan_num = 0;
spin_lock_init(&ctlr->lock);
ctlr->pool = cpdma_desc_pool_create(ctlr->dev,
ctlr->params.desc_mem_phys,
ctlr->params.desc_hw_addr,
ctlr->params.desc_mem_size,
ctlr->params.desc_align);
if (!ctlr->pool)
return NULL;
if (WARN_ON(ctlr->num_chan > CPDMA_MAX_CHANNELS))
ctlr->num_chan = CPDMA_MAX_CHANNELS;
return ctlr;
}
int cpdma_ctlr_start(struct cpdma_ctlr *ctlr)
{
struct cpdma_chan *chan;
unsigned long flags;
int i, prio_mode;
spin_lock_irqsave(&ctlr->lock, flags);
if (ctlr->state != CPDMA_STATE_IDLE) {
spin_unlock_irqrestore(&ctlr->lock, flags);
return -EBUSY;
}
if (ctlr->params.has_soft_reset) {
unsigned timeout = 10 * 100;
dma_reg_write(ctlr, CPDMA_SOFTRESET, 1);
while (timeout) {
if (dma_reg_read(ctlr, CPDMA_SOFTRESET) == 0)
break;
udelay(10);
timeout--;
}
WARN_ON(!timeout);
}
for (i = 0; i < ctlr->num_chan; i++) {
__raw_writel(0, ctlr->params.txhdp + 4 * i);
__raw_writel(0, ctlr->params.rxhdp + 4 * i);
__raw_writel(0, ctlr->params.txcp + 4 * i);
__raw_writel(0, ctlr->params.rxcp + 4 * i);
}
dma_reg_write(ctlr, CPDMA_RXINTMASKCLEAR, 0xffffffff);
dma_reg_write(ctlr, CPDMA_TXINTMASKCLEAR, 0xffffffff);
dma_reg_write(ctlr, CPDMA_TXCONTROL, 1);
dma_reg_write(ctlr, CPDMA_RXCONTROL, 1);
ctlr->state = CPDMA_STATE_ACTIVE;
prio_mode = 0;
for (i = 0; i < ARRAY_SIZE(ctlr->channels); i++) {
chan = ctlr->channels[i];
if (chan) {
cpdma_chan_set_chan_shaper(chan);
cpdma_chan_on(chan);
if (is_tx_chan(chan) && !chan->rate)
prio_mode = 1;
}
}
_cpdma_control_set(ctlr, CPDMA_TX_PRIO_FIXED, prio_mode);
_cpdma_control_set(ctlr, CPDMA_RX_BUFFER_OFFSET, 0);
spin_unlock_irqrestore(&ctlr->lock, flags);
return 0;
}
int cpdma_ctlr_stop(struct cpdma_ctlr *ctlr)
{
unsigned long flags;
int i;
spin_lock_irqsave(&ctlr->lock, flags);
if (ctlr->state != CPDMA_STATE_ACTIVE) {
spin_unlock_irqrestore(&ctlr->lock, flags);
return -EINVAL;
}
ctlr->state = CPDMA_STATE_TEARDOWN;
spin_unlock_irqrestore(&ctlr->lock, flags);
for (i = 0; i < ARRAY_SIZE(ctlr->channels); i++) {
if (ctlr->channels[i])
cpdma_chan_stop(ctlr->channels[i]);
}
spin_lock_irqsave(&ctlr->lock, flags);
dma_reg_write(ctlr, CPDMA_RXINTMASKCLEAR, 0xffffffff);
dma_reg_write(ctlr, CPDMA_TXINTMASKCLEAR, 0xffffffff);
dma_reg_write(ctlr, CPDMA_TXCONTROL, 0);
dma_reg_write(ctlr, CPDMA_RXCONTROL, 0);
ctlr->state = CPDMA_STATE_IDLE;
spin_unlock_irqrestore(&ctlr->lock, flags);
return 0;
}
int cpdma_ctlr_destroy(struct cpdma_ctlr *ctlr)
{
int ret = 0, i;
if (!ctlr)
return -EINVAL;
if (ctlr->state != CPDMA_STATE_IDLE)
cpdma_ctlr_stop(ctlr);
for (i = 0; i < ARRAY_SIZE(ctlr->channels); i++)
cpdma_chan_destroy(ctlr->channels[i]);
cpdma_desc_pool_destroy(ctlr->pool);
return ret;
}
int cpdma_ctlr_int_ctrl(struct cpdma_ctlr *ctlr, bool enable)
{
unsigned long flags;
int i, reg;
spin_lock_irqsave(&ctlr->lock, flags);
if (ctlr->state != CPDMA_STATE_ACTIVE) {
spin_unlock_irqrestore(&ctlr->lock, flags);
return -EINVAL;
}
reg = enable ? CPDMA_DMAINTMASKSET : CPDMA_DMAINTMASKCLEAR;
dma_reg_write(ctlr, reg, CPDMA_DMAINT_HOSTERR);
for (i = 0; i < ARRAY_SIZE(ctlr->channels); i++) {
if (ctlr->channels[i])
cpdma_chan_int_ctrl(ctlr->channels[i], enable);
}
spin_unlock_irqrestore(&ctlr->lock, flags);
return 0;
}
void cpdma_ctlr_eoi(struct cpdma_ctlr *ctlr, u32 value)
{
dma_reg_write(ctlr, CPDMA_MACEOIVECTOR, value);
}
u32 cpdma_ctrl_rxchs_state(struct cpdma_ctlr *ctlr)
{
return dma_reg_read(ctlr, CPDMA_RXINTSTATMASKED);
}
u32 cpdma_ctrl_txchs_state(struct cpdma_ctlr *ctlr)
{
return dma_reg_read(ctlr, CPDMA_TXINTSTATMASKED);
}
static void cpdma_chan_set_descs(struct cpdma_ctlr *ctlr,
int rx, int desc_num,
int per_ch_desc)
{
struct cpdma_chan *chan, *most_chan = NULL;
int desc_cnt = desc_num;
int most_dnum = 0;
int min, max, i;
if (!desc_num)
return;
if (rx) {
min = rx_chan_num(0);
max = rx_chan_num(CPDMA_MAX_CHANNELS);
} else {
min = tx_chan_num(0);
max = tx_chan_num(CPDMA_MAX_CHANNELS);
}
for (i = min; i < max; i++) {
chan = ctlr->channels[i];
if (!chan)
continue;
if (chan->weight)
chan->desc_num = (chan->weight * desc_num) / 100;
else
chan->desc_num = per_ch_desc;
desc_cnt -= chan->desc_num;
if (most_dnum < chan->desc_num) {
most_dnum = chan->desc_num;
most_chan = chan;
}
}
most_chan->desc_num += desc_cnt;
}
static int cpdma_chan_split_pool(struct cpdma_ctlr *ctlr)
{
int tx_per_ch_desc = 0, rx_per_ch_desc = 0;
struct cpdma_desc_pool *pool = ctlr->pool;
int free_rx_num = 0, free_tx_num = 0;
int rx_weight = 0, tx_weight = 0;
int tx_desc_num, rx_desc_num;
struct cpdma_chan *chan;
int i, tx_num = 0;
if (!ctlr->chan_num)
return 0;
for (i = 0; i < ARRAY_SIZE(ctlr->channels); i++) {
chan = ctlr->channels[i];
if (!chan)
continue;
if (is_rx_chan(chan)) {
if (!chan->weight)
free_rx_num++;
rx_weight += chan->weight;
} else {
if (!chan->weight)
free_tx_num++;
tx_weight += chan->weight;
tx_num++;
}
}
if (rx_weight > 100 || tx_weight > 100)
return -EINVAL;
tx_desc_num = (tx_num * pool->num_desc) / ctlr->chan_num;
rx_desc_num = pool->num_desc - tx_desc_num;
if (free_tx_num) {
tx_per_ch_desc = tx_desc_num - (tx_weight * tx_desc_num) / 100;
tx_per_ch_desc /= free_tx_num;
}
if (free_rx_num) {
rx_per_ch_desc = rx_desc_num - (rx_weight * rx_desc_num) / 100;
rx_per_ch_desc /= free_rx_num;
}
cpdma_chan_set_descs(ctlr, 0, tx_desc_num, tx_per_ch_desc);
cpdma_chan_set_descs(ctlr, 1, rx_desc_num, rx_per_ch_desc);
return 0;
}
int cpdma_chan_set_weight(struct cpdma_chan *ch, int weight)
{
struct cpdma_ctlr *ctlr = ch->ctlr;
unsigned long flags, ch_flags;
int ret;
spin_lock_irqsave(&ctlr->lock, flags);
spin_lock_irqsave(&ch->lock, ch_flags);
if (ch->weight == weight) {
spin_unlock_irqrestore(&ch->lock, ch_flags);
spin_unlock_irqrestore(&ctlr->lock, flags);
return 0;
}
ch->weight = weight;
spin_unlock_irqrestore(&ch->lock, ch_flags);
ret = cpdma_chan_split_pool(ctlr);
spin_unlock_irqrestore(&ctlr->lock, flags);
return ret;
}
u32 cpdma_chan_get_min_rate(struct cpdma_ctlr *ctlr)
{
unsigned int divident, divisor;
divident = ctlr->params.bus_freq_mhz * 32 * 1000;
divisor = 1 + CPDMA_MAX_RLIM_CNT;
return DIV_ROUND_UP(divident, divisor);
}
int cpdma_chan_set_rate(struct cpdma_chan *ch, u32 rate)
{
struct cpdma_ctlr *ctlr = ch->ctlr;
unsigned long flags, ch_flags;
int ret, prio_mode;
u32 rmask;
if (!ch || !is_tx_chan(ch))
return -EINVAL;
if (ch->rate == rate)
return rate;
spin_lock_irqsave(&ctlr->lock, flags);
spin_lock_irqsave(&ch->lock, ch_flags);
ret = cpdma_chan_fit_rate(ch, rate, &rmask, &prio_mode);
if (ret)
goto err;
ret = cpdma_chan_set_factors(ctlr, ch);
if (ret)
goto err;
spin_unlock_irqrestore(&ch->lock, ch_flags);
_cpdma_control_set(ctlr, CPDMA_TX_RLIM, rmask);
_cpdma_control_set(ctlr, CPDMA_TX_PRIO_FIXED, prio_mode);
spin_unlock_irqrestore(&ctlr->lock, flags);
return ret;
err:
spin_unlock_irqrestore(&ch->lock, ch_flags);
spin_unlock_irqrestore(&ctlr->lock, flags);
return ret;
}
u32 cpdma_chan_get_rate(struct cpdma_chan *ch)
{
unsigned long flags;
u32 rate;
spin_lock_irqsave(&ch->lock, flags);
rate = ch->rate;
spin_unlock_irqrestore(&ch->lock, flags);
return rate;
}
struct cpdma_chan *cpdma_chan_create(struct cpdma_ctlr *ctlr, int chan_num,
cpdma_handler_fn handler, int rx_type)
{
int offset = chan_num * 4;
struct cpdma_chan *chan;
unsigned long flags;
chan_num = rx_type ? rx_chan_num(chan_num) : tx_chan_num(chan_num);
if (__chan_linear(chan_num) >= ctlr->num_chan)
return NULL;
chan = devm_kzalloc(ctlr->dev, sizeof(*chan), GFP_KERNEL);
if (!chan)
return ERR_PTR(-ENOMEM);
spin_lock_irqsave(&ctlr->lock, flags);
if (ctlr->channels[chan_num]) {
spin_unlock_irqrestore(&ctlr->lock, flags);
devm_kfree(ctlr->dev, chan);
return ERR_PTR(-EBUSY);
}
chan->ctlr = ctlr;
chan->state = CPDMA_STATE_IDLE;
chan->chan_num = chan_num;
chan->handler = handler;
chan->rate = 0;
chan->desc_num = ctlr->pool->num_desc / 2;
chan->weight = 0;
if (is_rx_chan(chan)) {
chan->hdp = ctlr->params.rxhdp + offset;
chan->cp = ctlr->params.rxcp + offset;
chan->rxfree = ctlr->params.rxfree + offset;
chan->int_set = CPDMA_RXINTMASKSET;
chan->int_clear = CPDMA_RXINTMASKCLEAR;
chan->td = CPDMA_RXTEARDOWN;
chan->dir = DMA_FROM_DEVICE;
} else {
chan->hdp = ctlr->params.txhdp + offset;
chan->cp = ctlr->params.txcp + offset;
chan->int_set = CPDMA_TXINTMASKSET;
chan->int_clear = CPDMA_TXINTMASKCLEAR;
chan->td = CPDMA_TXTEARDOWN;
chan->dir = DMA_TO_DEVICE;
}
chan->mask = BIT(chan_linear(chan));
spin_lock_init(&chan->lock);
ctlr->channels[chan_num] = chan;
ctlr->chan_num++;
cpdma_chan_split_pool(ctlr);
spin_unlock_irqrestore(&ctlr->lock, flags);
return chan;
}
int cpdma_chan_get_rx_buf_num(struct cpdma_chan *chan)
{
unsigned long flags;
int desc_num;
spin_lock_irqsave(&chan->lock, flags);
desc_num = chan->desc_num;
spin_unlock_irqrestore(&chan->lock, flags);
return desc_num;
}
int cpdma_chan_destroy(struct cpdma_chan *chan)
{
struct cpdma_ctlr *ctlr;
unsigned long flags;
if (!chan)
return -EINVAL;
ctlr = chan->ctlr;
spin_lock_irqsave(&ctlr->lock, flags);
if (chan->state != CPDMA_STATE_IDLE)
cpdma_chan_stop(chan);
ctlr->channels[chan->chan_num] = NULL;
ctlr->chan_num--;
devm_kfree(ctlr->dev, chan);
cpdma_chan_split_pool(ctlr);
spin_unlock_irqrestore(&ctlr->lock, flags);
return 0;
}
int cpdma_chan_get_stats(struct cpdma_chan *chan,
struct cpdma_chan_stats *stats)
{
unsigned long flags;
if (!chan)
return -EINVAL;
spin_lock_irqsave(&chan->lock, flags);
memcpy(stats, &chan->stats, sizeof(*stats));
spin_unlock_irqrestore(&chan->lock, flags);
return 0;
}
static void __cpdma_chan_submit(struct cpdma_chan *chan,
struct cpdma_desc __iomem *desc)
{
struct cpdma_ctlr *ctlr = chan->ctlr;
struct cpdma_desc __iomem *prev = chan->tail;
struct cpdma_desc_pool *pool = ctlr->pool;
dma_addr_t desc_dma;
u32 mode;
desc_dma = desc_phys(pool, desc);
if (!chan->head) {
chan->stats.head_enqueue++;
chan->head = desc;
chan->tail = desc;
if (chan->state == CPDMA_STATE_ACTIVE)
chan_write(chan, hdp, desc_dma);
return;
}
desc_write(prev, hw_next, desc_dma);
chan->tail = desc;
chan->stats.tail_enqueue++;
mode = desc_read(prev, hw_mode);
if (((mode & (CPDMA_DESC_EOQ | CPDMA_DESC_OWNER)) == CPDMA_DESC_EOQ) &&
(chan->state == CPDMA_STATE_ACTIVE)) {
desc_write(prev, hw_mode, mode & ~CPDMA_DESC_EOQ);
chan_write(chan, hdp, desc_dma);
chan->stats.misqueued++;
}
}
int cpdma_chan_submit(struct cpdma_chan *chan, void *token, void *data,
int len, int directed)
{
struct cpdma_ctlr *ctlr = chan->ctlr;
struct cpdma_desc __iomem *desc;
dma_addr_t buffer;
unsigned long flags;
u32 mode;
int ret = 0;
spin_lock_irqsave(&chan->lock, flags);
if (chan->state == CPDMA_STATE_TEARDOWN) {
ret = -EINVAL;
goto unlock_ret;
}
if (chan->count >= chan->desc_num) {
chan->stats.desc_alloc_fail++;
ret = -ENOMEM;
goto unlock_ret;
}
desc = cpdma_desc_alloc(ctlr->pool);
if (!desc) {
chan->stats.desc_alloc_fail++;
ret = -ENOMEM;
goto unlock_ret;
}
if (len < ctlr->params.min_packet_size) {
len = ctlr->params.min_packet_size;
chan->stats.runt_transmit_buff++;
}
buffer = dma_map_single(ctlr->dev, data, len, chan->dir);
ret = dma_mapping_error(ctlr->dev, buffer);
if (ret) {
cpdma_desc_free(ctlr->pool, desc, 1);
ret = -EINVAL;
goto unlock_ret;
}
mode = CPDMA_DESC_OWNER | CPDMA_DESC_SOP | CPDMA_DESC_EOP;
cpdma_desc_to_port(chan, mode, directed);
desc_write(desc, hw_next, 0);
desc_write(desc, hw_buffer, buffer);
desc_write(desc, hw_len, len);
desc_write(desc, hw_mode, mode | len);
desc_write(desc, sw_token, token);
desc_write(desc, sw_buffer, buffer);
desc_write(desc, sw_len, len);
__cpdma_chan_submit(chan, desc);
if (chan->state == CPDMA_STATE_ACTIVE && chan->rxfree)
chan_write(chan, rxfree, 1);
chan->count++;
unlock_ret:
spin_unlock_irqrestore(&chan->lock, flags);
return ret;
}
bool cpdma_check_free_tx_desc(struct cpdma_chan *chan)
{
struct cpdma_ctlr *ctlr = chan->ctlr;
struct cpdma_desc_pool *pool = ctlr->pool;
bool free_tx_desc;
unsigned long flags;
spin_lock_irqsave(&chan->lock, flags);
free_tx_desc = (chan->count < chan->desc_num) &&
gen_pool_avail(pool->gen_pool);
spin_unlock_irqrestore(&chan->lock, flags);
return free_tx_desc;
}
static void __cpdma_chan_free(struct cpdma_chan *chan,
struct cpdma_desc __iomem *desc,
int outlen, int status)
{
struct cpdma_ctlr *ctlr = chan->ctlr;
struct cpdma_desc_pool *pool = ctlr->pool;
dma_addr_t buff_dma;
int origlen;
void *token;
token = (void *)desc_read(desc, sw_token);
buff_dma = desc_read(desc, sw_buffer);
origlen = desc_read(desc, sw_len);
dma_unmap_single(ctlr->dev, buff_dma, origlen, chan->dir);
cpdma_desc_free(pool, desc, 1);
(*chan->handler)(token, outlen, status);
}
static int __cpdma_chan_process(struct cpdma_chan *chan)
{
struct cpdma_ctlr *ctlr = chan->ctlr;
struct cpdma_desc __iomem *desc;
int status, outlen;
int cb_status = 0;
struct cpdma_desc_pool *pool = ctlr->pool;
dma_addr_t desc_dma;
unsigned long flags;
spin_lock_irqsave(&chan->lock, flags);
desc = chan->head;
if (!desc) {
chan->stats.empty_dequeue++;
status = -ENOENT;
goto unlock_ret;
}
desc_dma = desc_phys(pool, desc);
status = __raw_readl(&desc->hw_mode);
outlen = status & 0x7ff;
if (status & CPDMA_DESC_OWNER) {
chan->stats.busy_dequeue++;
status = -EBUSY;
goto unlock_ret;
}
if (status & CPDMA_DESC_PASS_CRC)
outlen -= CPDMA_DESC_CRC_LEN;
status = status & (CPDMA_DESC_EOQ | CPDMA_DESC_TD_COMPLETE |
CPDMA_DESC_PORT_MASK);
chan->head = desc_from_phys(pool, desc_read(desc, hw_next));
chan_write(chan, cp, desc_dma);
chan->count--;
chan->stats.good_dequeue++;
if (status & CPDMA_DESC_EOQ) {
chan->stats.requeue++;
chan_write(chan, hdp, desc_phys(pool, chan->head));
}
spin_unlock_irqrestore(&chan->lock, flags);
if (unlikely(status & CPDMA_DESC_TD_COMPLETE))
cb_status = -ENOSYS;
else
cb_status = status;
__cpdma_chan_free(chan, desc, outlen, cb_status);
return status;
unlock_ret:
spin_unlock_irqrestore(&chan->lock, flags);
return status;
}
int cpdma_chan_process(struct cpdma_chan *chan, int quota)
{
int used = 0, ret = 0;
if (chan->state != CPDMA_STATE_ACTIVE)
return -EINVAL;
while (used < quota) {
ret = __cpdma_chan_process(chan);
if (ret < 0)
break;
used++;
}
return used;
}
int cpdma_chan_start(struct cpdma_chan *chan)
{
struct cpdma_ctlr *ctlr = chan->ctlr;
unsigned long flags;
int ret;
spin_lock_irqsave(&ctlr->lock, flags);
ret = cpdma_chan_set_chan_shaper(chan);
spin_unlock_irqrestore(&ctlr->lock, flags);
if (ret)
return ret;
ret = cpdma_chan_on(chan);
if (ret)
return ret;
return 0;
}
int cpdma_chan_stop(struct cpdma_chan *chan)
{
struct cpdma_ctlr *ctlr = chan->ctlr;
struct cpdma_desc_pool *pool = ctlr->pool;
unsigned long flags;
int ret;
unsigned timeout;
spin_lock_irqsave(&chan->lock, flags);
if (chan->state == CPDMA_STATE_TEARDOWN) {
spin_unlock_irqrestore(&chan->lock, flags);
return -EINVAL;
}
chan->state = CPDMA_STATE_TEARDOWN;
dma_reg_write(ctlr, chan->int_clear, chan->mask);
dma_reg_write(ctlr, chan->td, chan_linear(chan));
timeout = 100 * 100;
while (timeout) {
u32 cp = chan_read(chan, cp);
if ((cp & CPDMA_TEARDOWN_VALUE) == CPDMA_TEARDOWN_VALUE)
break;
udelay(10);
timeout--;
}
WARN_ON(!timeout);
chan_write(chan, cp, CPDMA_TEARDOWN_VALUE);
spin_unlock_irqrestore(&chan->lock, flags);
do {
ret = __cpdma_chan_process(chan);
if (ret < 0)
break;
} while ((ret & CPDMA_DESC_TD_COMPLETE) == 0);
spin_lock_irqsave(&chan->lock, flags);
while (chan->head) {
struct cpdma_desc __iomem *desc = chan->head;
dma_addr_t next_dma;
next_dma = desc_read(desc, hw_next);
chan->head = desc_from_phys(pool, next_dma);
chan->count--;
chan->stats.teardown_dequeue++;
spin_unlock_irqrestore(&chan->lock, flags);
__cpdma_chan_free(chan, desc, 0, -ENOSYS);
spin_lock_irqsave(&chan->lock, flags);
}
chan->state = CPDMA_STATE_IDLE;
spin_unlock_irqrestore(&chan->lock, flags);
return 0;
}
int cpdma_chan_int_ctrl(struct cpdma_chan *chan, bool enable)
{
unsigned long flags;
spin_lock_irqsave(&chan->lock, flags);
if (chan->state != CPDMA_STATE_ACTIVE) {
spin_unlock_irqrestore(&chan->lock, flags);
return -EINVAL;
}
dma_reg_write(chan->ctlr, enable ? chan->int_set : chan->int_clear,
chan->mask);
spin_unlock_irqrestore(&chan->lock, flags);
return 0;
}
int cpdma_control_get(struct cpdma_ctlr *ctlr, int control)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&ctlr->lock, flags);
ret = _cpdma_control_get(ctlr, control);
spin_unlock_irqrestore(&ctlr->lock, flags);
return ret;
}
int cpdma_control_set(struct cpdma_ctlr *ctlr, int control, int value)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&ctlr->lock, flags);
ret = _cpdma_control_set(ctlr, control, value);
spin_unlock_irqrestore(&ctlr->lock, flags);
return ret;
}
