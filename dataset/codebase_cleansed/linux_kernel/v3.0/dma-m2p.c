static void feed_buf(struct m2p_channel *ch, struct ep93xx_dma_buffer *buf)
{
if (ch->next_slot == 0) {
writel(buf->size, ch->base + M2P_MAXCNT0);
writel(buf->bus_addr, ch->base + M2P_BASE0);
} else {
writel(buf->size, ch->base + M2P_MAXCNT1);
writel(buf->bus_addr, ch->base + M2P_BASE1);
}
ch->next_slot ^= 1;
}
static void choose_buffer_xfer(struct m2p_channel *ch)
{
struct ep93xx_dma_buffer *buf;
ch->buffer_xfer = NULL;
if (!list_empty(&ch->buffers_pending)) {
buf = list_entry(ch->buffers_pending.next,
struct ep93xx_dma_buffer, list);
list_del(&buf->list);
feed_buf(ch, buf);
ch->buffer_xfer = buf;
}
}
static void choose_buffer_next(struct m2p_channel *ch)
{
struct ep93xx_dma_buffer *buf;
ch->buffer_next = NULL;
if (!list_empty(&ch->buffers_pending)) {
buf = list_entry(ch->buffers_pending.next,
struct ep93xx_dma_buffer, list);
list_del(&buf->list);
feed_buf(ch, buf);
ch->buffer_next = buf;
}
}
static inline void m2p_set_control(struct m2p_channel *ch, u32 v)
{
writel(v, ch->base + M2P_CONTROL);
readl(ch->base + M2P_CONTROL);
}
static inline int m2p_channel_state(struct m2p_channel *ch)
{
return (readl(ch->base + M2P_STATUS) >> 4) & 0x3;
}
static irqreturn_t m2p_irq(int irq, void *dev_id)
{
struct m2p_channel *ch = dev_id;
struct ep93xx_dma_m2p_client *cl;
u32 irq_status, v;
int error = 0;
cl = ch->client;
spin_lock(&ch->lock);
irq_status = readl(ch->base + M2P_INTERRUPT);
if (irq_status & M2P_INTERRUPT_ERROR) {
writel(M2P_INTERRUPT_ERROR, ch->base + M2P_INTERRUPT);
error = 1;
}
if ((irq_status & (M2P_INTERRUPT_STALL | M2P_INTERRUPT_NFB)) == 0) {
spin_unlock(&ch->lock);
return IRQ_NONE;
}
switch (m2p_channel_state(ch)) {
case STATE_IDLE:
pr_crit("dma interrupt without a dma buffer\n");
BUG();
break;
case STATE_STALL:
cl->buffer_finished(cl->cookie, ch->buffer_xfer, 0, error);
if (ch->buffer_next != NULL) {
cl->buffer_finished(cl->cookie, ch->buffer_next,
0, error);
}
choose_buffer_xfer(ch);
choose_buffer_next(ch);
if (ch->buffer_xfer != NULL)
cl->buffer_started(cl->cookie, ch->buffer_xfer);
break;
case STATE_ON:
cl->buffer_finished(cl->cookie, ch->buffer_xfer, 0, error);
ch->buffer_xfer = ch->buffer_next;
choose_buffer_next(ch);
cl->buffer_started(cl->cookie, ch->buffer_xfer);
break;
case STATE_NEXT:
pr_crit("dma interrupt while next\n");
BUG();
break;
}
v = readl(ch->base + M2P_CONTROL) & ~(M2P_CONTROL_STALL_IRQ_EN |
M2P_CONTROL_NFB_IRQ_EN);
if (ch->buffer_xfer != NULL)
v |= M2P_CONTROL_STALL_IRQ_EN;
if (ch->buffer_next != NULL)
v |= M2P_CONTROL_NFB_IRQ_EN;
m2p_set_control(ch, v);
spin_unlock(&ch->lock);
return IRQ_HANDLED;
}
static struct m2p_channel *find_free_channel(struct ep93xx_dma_m2p_client *cl)
{
struct m2p_channel *ch;
int i;
if (cl->flags & EP93XX_DMA_M2P_RX)
ch = m2p_rx;
else
ch = m2p_tx;
for (i = 0; ch[i].base; i++) {
struct ep93xx_dma_m2p_client *client;
client = ch[i].client;
if (client != NULL) {
int port;
port = cl->flags & EP93XX_DMA_M2P_PORT_MASK;
if (port == (client->flags &
EP93XX_DMA_M2P_PORT_MASK)) {
pr_warning("DMA channel already used by %s\n",
cl->name ? : "unknown client");
return ERR_PTR(-EBUSY);
}
}
}
for (i = 0; ch[i].base; i++) {
if (ch[i].client == NULL)
return ch + i;
}
pr_warning("No free DMA channel for %s\n",
cl->name ? : "unknown client");
return ERR_PTR(-ENODEV);
}
static void channel_enable(struct m2p_channel *ch)
{
struct ep93xx_dma_m2p_client *cl = ch->client;
u32 v;
clk_enable(ch->clk);
v = cl->flags & EP93XX_DMA_M2P_PORT_MASK;
writel(v, ch->base + M2P_PPALLOC);
v = cl->flags & EP93XX_DMA_M2P_ERROR_MASK;
v |= M2P_CONTROL_ENABLE | M2P_CONTROL_ERROR_IRQ_EN;
m2p_set_control(ch, v);
}
static void channel_disable(struct m2p_channel *ch)
{
u32 v;
v = readl(ch->base + M2P_CONTROL);
v &= ~(M2P_CONTROL_STALL_IRQ_EN | M2P_CONTROL_NFB_IRQ_EN);
m2p_set_control(ch, v);
while (m2p_channel_state(ch) >= STATE_ON)
cpu_relax();
m2p_set_control(ch, 0x0);
while (m2p_channel_state(ch) == STATE_STALL)
cpu_relax();
clk_disable(ch->clk);
}
int ep93xx_dma_m2p_client_register(struct ep93xx_dma_m2p_client *cl)
{
struct m2p_channel *ch;
int err;
ch = find_free_channel(cl);
if (IS_ERR(ch))
return PTR_ERR(ch);
err = request_irq(ch->irq, m2p_irq, 0, cl->name ? : "dma-m2p", ch);
if (err)
return err;
ch->client = cl;
ch->next_slot = 0;
ch->buffer_xfer = NULL;
ch->buffer_next = NULL;
INIT_LIST_HEAD(&ch->buffers_pending);
cl->channel = ch;
channel_enable(ch);
return 0;
}
void ep93xx_dma_m2p_client_unregister(struct ep93xx_dma_m2p_client *cl)
{
struct m2p_channel *ch = cl->channel;
channel_disable(ch);
free_irq(ch->irq, ch);
ch->client = NULL;
}
void ep93xx_dma_m2p_submit(struct ep93xx_dma_m2p_client *cl,
struct ep93xx_dma_buffer *buf)
{
struct m2p_channel *ch = cl->channel;
unsigned long flags;
u32 v;
spin_lock_irqsave(&ch->lock, flags);
v = readl(ch->base + M2P_CONTROL);
if (ch->buffer_xfer == NULL) {
ch->buffer_xfer = buf;
feed_buf(ch, buf);
cl->buffer_started(cl->cookie, buf);
v |= M2P_CONTROL_STALL_IRQ_EN;
m2p_set_control(ch, v);
} else if (ch->buffer_next == NULL) {
ch->buffer_next = buf;
feed_buf(ch, buf);
v |= M2P_CONTROL_NFB_IRQ_EN;
m2p_set_control(ch, v);
} else {
list_add_tail(&buf->list, &ch->buffers_pending);
}
spin_unlock_irqrestore(&ch->lock, flags);
}
void ep93xx_dma_m2p_submit_recursive(struct ep93xx_dma_m2p_client *cl,
struct ep93xx_dma_buffer *buf)
{
struct m2p_channel *ch = cl->channel;
list_add_tail(&buf->list, &ch->buffers_pending);
}
void ep93xx_dma_m2p_flush(struct ep93xx_dma_m2p_client *cl)
{
struct m2p_channel *ch = cl->channel;
channel_disable(ch);
ch->next_slot = 0;
ch->buffer_xfer = NULL;
ch->buffer_next = NULL;
INIT_LIST_HEAD(&ch->buffers_pending);
channel_enable(ch);
}
static int init_channel(struct m2p_channel *ch)
{
ch->clk = clk_get(NULL, ch->name);
if (IS_ERR(ch->clk))
return PTR_ERR(ch->clk);
spin_lock_init(&ch->lock);
ch->client = NULL;
return 0;
}
static int __init ep93xx_dma_m2p_init(void)
{
int i;
int ret;
for (i = 0; m2p_rx[i].base; i++) {
ret = init_channel(m2p_rx + i);
if (ret)
return ret;
}
for (i = 0; m2p_tx[i].base; i++) {
ret = init_channel(m2p_tx + i);
if (ret)
return ret;
}
pr_info("M2P DMA subsystem initialized\n");
return 0;
}
