static struct s3c_pl330_chan *id_to_chan(const enum dma_ch id)
{
struct s3c_pl330_chan *ch;
list_for_each_entry(ch, &chan_list, node)
if (ch->id == id)
return ch;
return NULL;
}
static void chan_add(const enum dma_ch id)
{
struct s3c_pl330_chan *ch = id_to_chan(id);
if (ch)
return;
ch = kmalloc(sizeof(*ch), GFP_KERNEL);
if (!ch)
return;
ch->id = id;
ch->dmac = NULL;
list_add_tail(&ch->node, &chan_list);
}
static bool chan_free(struct s3c_pl330_chan *ch)
{
if (!ch)
return false;
return ch->dmac ? false : true;
}
static unsigned iface_of_dmac(struct s3c_pl330_dmac *dmac, enum dma_ch ch_id)
{
enum dma_ch *id = dmac->peri;
int i;
if (ch_id == DMACH_MAX)
return 0;
for (i = 0; i < PL330_MAX_PERI; i++)
if (id[i] == ch_id)
return i + 1;
return 0;
}
static inline bool dmac_busy(struct s3c_pl330_dmac *dmac)
{
struct pl330_info *pi = dmac->pi;
return (dmac->busy_chan < pi->pcfg.num_chan) ? false : true;
}
static unsigned ch_onlyby_dmac(struct s3c_pl330_dmac *dmac)
{
enum dma_ch *id = dmac->peri;
struct s3c_pl330_dmac *d;
struct s3c_pl330_chan *ch;
unsigned found, count = 0;
enum dma_ch p;
int i;
for (i = 0; i < PL330_MAX_PERI; i++) {
p = id[i];
ch = id_to_chan(p);
if (p == DMACH_MAX || !chan_free(ch))
continue;
found = 0;
list_for_each_entry(d, &dmac_list, node) {
if (d != dmac && iface_of_dmac(d, ch->id)) {
found = 1;
break;
}
}
if (!found)
count++;
}
return count;
}
static unsigned suitablility(struct s3c_pl330_dmac *dmac,
struct s3c_pl330_chan *ch)
{
struct pl330_info *pi = dmac->pi;
enum dma_ch *id = dmac->peri;
struct s3c_pl330_dmac *d;
unsigned s;
int i;
s = MIN_SUIT;
if (dmac_busy(dmac))
return s;
for (i = 0; i < PL330_MAX_PERI; i++)
if (id[i] == ch->id)
break;
if (i == PL330_MAX_PERI)
return s;
s = MAX_SUIT;
list_for_each_entry(d, &dmac_list, node) {
if (d != dmac && iface_of_dmac(d, ch->id) && !dmac_busy(d)) {
s = 0;
break;
}
}
if (s)
return s;
s = 100;
s += (pi->pcfg.num_chan - dmac->busy_chan) - ch_onlyby_dmac(dmac);
return s;
}
static struct s3c_pl330_dmac *map_chan_to_dmac(struct s3c_pl330_chan *ch)
{
struct s3c_pl330_dmac *d, *dmac = NULL;
unsigned sn, sl = MIN_SUIT;
list_for_each_entry(d, &dmac_list, node) {
sn = suitablility(d, ch);
if (sn == MAX_SUIT)
return d;
if (sn > sl)
dmac = d;
}
return dmac;
}
static struct s3c_pl330_chan *chan_acquire(const enum dma_ch id)
{
struct s3c_pl330_chan *ch = id_to_chan(id);
struct s3c_pl330_dmac *dmac;
if (!ch || !chan_free(ch)) {
ch = NULL;
goto acq_exit;
}
dmac = map_chan_to_dmac(ch);
if (!dmac) {
ch = NULL;
goto acq_exit;
}
dmac->busy_chan++;
ch->dmac = dmac;
acq_exit:
return ch;
}
static inline void del_from_queue(struct s3c_pl330_xfer *xfer)
{
struct s3c_pl330_xfer *t;
struct s3c_pl330_chan *ch;
int found;
if (!xfer)
return;
ch = xfer->chan;
found = 0;
list_for_each_entry(t, &ch->xfer_list, node)
if (t == xfer) {
found = 1;
break;
}
if (!found)
return;
if (xfer->node.next == &ch->xfer_list)
t = list_entry(ch->xfer_list.next,
struct s3c_pl330_xfer, node);
else
t = list_entry(xfer->node.next,
struct s3c_pl330_xfer, node);
if (t == xfer)
ch->xfer_head = NULL;
else if (ch->xfer_head == xfer)
ch->xfer_head = t;
list_del(&xfer->node);
}
static struct s3c_pl330_xfer *get_from_queue(struct s3c_pl330_chan *ch,
int pluck)
{
struct s3c_pl330_xfer *xfer = ch->xfer_head;
if (!xfer)
return NULL;
if (xfer->node.next == &ch->xfer_list)
ch->xfer_head = list_entry(ch->xfer_list.next,
struct s3c_pl330_xfer, node);
else
ch->xfer_head = list_entry(xfer->node.next,
struct s3c_pl330_xfer, node);
if (pluck || !(ch->options & S3C2410_DMAF_CIRCULAR))
del_from_queue(xfer);
return xfer;
}
static inline void add_to_queue(struct s3c_pl330_chan *ch,
struct s3c_pl330_xfer *xfer, int front)
{
struct pl330_xfer *xt;
if (ch->xfer_head == NULL)
ch->xfer_head = xfer;
xt = &ch->xfer_head->px;
if (ch->options & S3C2410_DMAF_CIRCULAR &&
(xt == ch->req[0].x || xt == ch->req[1].x))
ch->xfer_head = xfer;
if (front) {
ch->xfer_head = xfer;
list_add(&xfer->node, &ch->xfer_list);
} else {
list_add_tail(&xfer->node, &ch->xfer_list);
}
}
static inline void _finish_off(struct s3c_pl330_xfer *xfer,
enum s3c2410_dma_buffresult res, int ffree)
{
struct s3c_pl330_chan *ch;
if (!xfer)
return;
ch = xfer->chan;
if (ch->callback_fn)
ch->callback_fn(NULL, xfer->token, xfer->px.bytes, res);
if (ffree || !(ch->options & S3C2410_DMAF_CIRCULAR))
kmem_cache_free(ch->dmac->kmcache, xfer);
}
static inline int s3c_pl330_submit(struct s3c_pl330_chan *ch,
struct pl330_req *r)
{
struct s3c_pl330_xfer *xfer;
int ret = 0;
if (r->x)
return 0;
xfer = get_from_queue(ch, 0);
if (xfer) {
r->x = &xfer->px;
if (r->rqtype == MEMTOMEM) {
struct pl330_info *pi = xfer->chan->dmac->pi;
int burst = 1 << ch->rqcfg.brst_size;
u32 bytes = r->x->bytes;
int bl;
bl = pi->pcfg.data_bus_width / 8;
bl *= pi->pcfg.data_buf_dep;
bl /= burst;
if (bl > 16)
bl = 16;
while (bl > 1) {
if (!(bytes % (bl * burst)))
break;
bl--;
}
ch->rqcfg.brst_len = bl;
} else {
ch->rqcfg.brst_len = 1;
}
ret = pl330_submit_req(ch->pl330_chan_id, r);
if (!ret) {
ch->lrq = r;
return 0;
}
r->x = NULL;
if (ret == -EAGAIN) {
dev_err(ch->dmac->pi->dev, "%s:%d!\n",
__func__, __LINE__);
add_to_queue(ch, xfer, 1);
ret = 0;
} else {
dev_err(ch->dmac->pi->dev, "%s:%d!\n",
__func__, __LINE__);
_finish_off(xfer, S3C2410_RES_ERR, 0);
}
}
return ret;
}
static void s3c_pl330_rq(struct s3c_pl330_chan *ch,
struct pl330_req *r, enum pl330_op_err err)
{
unsigned long flags;
struct s3c_pl330_xfer *xfer;
struct pl330_xfer *xl = r->x;
enum s3c2410_dma_buffresult res;
spin_lock_irqsave(&res_lock, flags);
r->x = NULL;
s3c_pl330_submit(ch, r);
spin_unlock_irqrestore(&res_lock, flags);
if (err == PL330_ERR_NONE)
res = S3C2410_RES_OK;
else if (err == PL330_ERR_ABORT)
res = S3C2410_RES_ABORT;
else
res = S3C2410_RES_ERR;
if (xl) {
xfer = container_of(xl, struct s3c_pl330_xfer, px);
_finish_off(xfer, res, 0);
} else {
dev_info(ch->dmac->pi->dev, "%s:%d No Xfer?!\n",
__func__, __LINE__);
}
}
static void s3c_pl330_rq0(void *token, enum pl330_op_err err)
{
struct pl330_req *r = token;
struct s3c_pl330_chan *ch = container_of(r,
struct s3c_pl330_chan, req[0]);
s3c_pl330_rq(ch, r, err);
}
static void s3c_pl330_rq1(void *token, enum pl330_op_err err)
{
struct pl330_req *r = token;
struct s3c_pl330_chan *ch = container_of(r,
struct s3c_pl330_chan, req[1]);
s3c_pl330_rq(ch, r, err);
}
static void chan_release(struct s3c_pl330_chan *ch)
{
struct s3c_pl330_dmac *dmac;
if (chan_free(ch))
return;
dmac = ch->dmac;
ch->dmac = NULL;
dmac->busy_chan--;
}
int s3c2410_dma_ctrl(enum dma_ch id, enum s3c2410_chan_op op)
{
struct s3c_pl330_xfer *xfer;
enum pl330_chan_op pl330op;
struct s3c_pl330_chan *ch;
unsigned long flags;
int idx, ret;
spin_lock_irqsave(&res_lock, flags);
ch = id_to_chan(id);
if (!ch || chan_free(ch)) {
ret = -EINVAL;
goto ctrl_exit;
}
switch (op) {
case S3C2410_DMAOP_START:
idx = (ch->lrq == &ch->req[0]) ? 1 : 0;
s3c_pl330_submit(ch, &ch->req[idx]);
s3c_pl330_submit(ch, &ch->req[1 - idx]);
pl330op = PL330_OP_START;
break;
case S3C2410_DMAOP_STOP:
pl330op = PL330_OP_ABORT;
break;
case S3C2410_DMAOP_FLUSH:
pl330op = PL330_OP_FLUSH;
break;
case S3C2410_DMAOP_PAUSE:
case S3C2410_DMAOP_RESUME:
case S3C2410_DMAOP_TIMEOUT:
case S3C2410_DMAOP_STARTED:
spin_unlock_irqrestore(&res_lock, flags);
return 0;
default:
spin_unlock_irqrestore(&res_lock, flags);
return -EINVAL;
}
ret = pl330_chan_ctrl(ch->pl330_chan_id, pl330op);
if (pl330op == PL330_OP_START) {
spin_unlock_irqrestore(&res_lock, flags);
return ret;
}
idx = (ch->lrq == &ch->req[0]) ? 1 : 0;
if (ch->req[idx].x) {
xfer = container_of(ch->req[idx].x,
struct s3c_pl330_xfer, px);
if (pl330op == PL330_OP_FLUSH)
del_from_queue(xfer);
ch->req[idx].x = NULL;
spin_unlock_irqrestore(&res_lock, flags);
_finish_off(xfer, S3C2410_RES_ABORT,
pl330op == PL330_OP_FLUSH ? 1 : 0);
spin_lock_irqsave(&res_lock, flags);
}
if (pl330op == PL330_OP_FLUSH) {
if (ch->req[1 - idx].x) {
xfer = container_of(ch->req[1 - idx].x,
struct s3c_pl330_xfer, px);
del_from_queue(xfer);
ch->req[1 - idx].x = NULL;
spin_unlock_irqrestore(&res_lock, flags);
_finish_off(xfer, S3C2410_RES_ABORT, 1);
spin_lock_irqsave(&res_lock, flags);
}
xfer = ch->xfer_head;
while (xfer) {
del_from_queue(xfer);
spin_unlock_irqrestore(&res_lock, flags);
_finish_off(xfer, S3C2410_RES_ABORT, 1);
spin_lock_irqsave(&res_lock, flags);
xfer = ch->xfer_head;
}
}
ctrl_exit:
spin_unlock_irqrestore(&res_lock, flags);
return ret;
}
int s3c2410_dma_enqueue(enum dma_ch id, void *token,
dma_addr_t addr, int size)
{
struct s3c_pl330_chan *ch;
struct s3c_pl330_xfer *xfer;
unsigned long flags;
int idx, ret = 0;
spin_lock_irqsave(&res_lock, flags);
ch = id_to_chan(id);
if (!ch || chan_free(ch)) {
ret = -EINVAL;
goto enq_exit;
}
if (ch->rqcfg.brst_size && size % (1 << ch->rqcfg.brst_size)) {
ret = -EINVAL;
goto enq_exit;
}
xfer = kmem_cache_alloc(ch->dmac->kmcache, GFP_ATOMIC);
if (!xfer) {
ret = -ENOMEM;
goto enq_exit;
}
xfer->token = token;
xfer->chan = ch;
xfer->px.bytes = size;
xfer->px.next = NULL;
if (ch->req[0].rqtype == MEMTODEV) {
xfer->px.src_addr = addr;
xfer->px.dst_addr = ch->sdaddr;
} else {
xfer->px.src_addr = ch->sdaddr;
xfer->px.dst_addr = addr;
}
add_to_queue(ch, xfer, 0);
idx = (ch->lrq == &ch->req[0]) ? 1 : 0;
if (!ch->req[idx].x)
s3c_pl330_submit(ch, &ch->req[idx]);
else
s3c_pl330_submit(ch, &ch->req[1 - idx]);
spin_unlock_irqrestore(&res_lock, flags);
if (ch->options & S3C2410_DMAF_AUTOSTART)
s3c2410_dma_ctrl(id, S3C2410_DMAOP_START);
return 0;
enq_exit:
spin_unlock_irqrestore(&res_lock, flags);
return ret;
}
int s3c2410_dma_request(enum dma_ch id,
struct s3c2410_dma_client *client,
void *dev)
{
struct s3c_pl330_dmac *dmac;
struct s3c_pl330_chan *ch;
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&res_lock, flags);
ch = chan_acquire(id);
if (!ch) {
ret = -EBUSY;
goto req_exit;
}
dmac = ch->dmac;
ch->pl330_chan_id = pl330_request_channel(dmac->pi);
if (!ch->pl330_chan_id) {
chan_release(ch);
ret = -EBUSY;
goto req_exit;
}
ch->client = client;
ch->options = 0;
ch->callback_fn = NULL;
ch->lrq = NULL;
ch->rqcfg.brst_size = 2;
ch->rqcfg.swap = SWAP_NO;
ch->rqcfg.scctl = SCCTRL0;
ch->rqcfg.dcctl = DCCTRL0;
ch->rqcfg.privileged = 0;
ch->rqcfg.insnaccess = 0;
ch->req[0].rqtype = DEVTODEV;
ch->req[1].rqtype = ch->req[0].rqtype;
ch->req[0].cfg = &ch->rqcfg;
ch->req[1].cfg = ch->req[0].cfg;
ch->req[0].peri = iface_of_dmac(dmac, id) - 1;
ch->req[1].peri = ch->req[0].peri;
ch->req[0].token = &ch->req[0];
ch->req[0].xfer_cb = s3c_pl330_rq0;
ch->req[1].token = &ch->req[1];
ch->req[1].xfer_cb = s3c_pl330_rq1;
ch->req[0].x = NULL;
ch->req[1].x = NULL;
INIT_LIST_HEAD(&ch->xfer_list);
ch->xfer_head = NULL;
req_exit:
spin_unlock_irqrestore(&res_lock, flags);
return ret;
}
int s3c2410_dma_free(enum dma_ch id, struct s3c2410_dma_client *client)
{
struct s3c_pl330_chan *ch;
struct s3c_pl330_xfer *xfer;
unsigned long flags;
int ret = 0;
unsigned idx;
spin_lock_irqsave(&res_lock, flags);
ch = id_to_chan(id);
if (!ch || chan_free(ch))
goto free_exit;
if (ch->client != client) {
ret = -EBUSY;
goto free_exit;
}
pl330_chan_ctrl(ch->pl330_chan_id, PL330_OP_FLUSH);
idx = (ch->lrq == &ch->req[0]) ? 1 : 0;
if (ch->req[idx].x) {
xfer = container_of(ch->req[idx].x,
struct s3c_pl330_xfer, px);
ch->req[idx].x = NULL;
del_from_queue(xfer);
spin_unlock_irqrestore(&res_lock, flags);
_finish_off(xfer, S3C2410_RES_ABORT, 1);
spin_lock_irqsave(&res_lock, flags);
}
if (ch->req[1 - idx].x) {
xfer = container_of(ch->req[1 - idx].x,
struct s3c_pl330_xfer, px);
ch->req[1 - idx].x = NULL;
del_from_queue(xfer);
spin_unlock_irqrestore(&res_lock, flags);
_finish_off(xfer, S3C2410_RES_ABORT, 1);
spin_lock_irqsave(&res_lock, flags);
}
do {
xfer = get_from_queue(ch, 1);
spin_unlock_irqrestore(&res_lock, flags);
_finish_off(xfer, S3C2410_RES_ABORT, 1);
spin_lock_irqsave(&res_lock, flags);
} while (xfer);
ch->client = NULL;
pl330_release_channel(ch->pl330_chan_id);
ch->pl330_chan_id = NULL;
chan_release(ch);
free_exit:
spin_unlock_irqrestore(&res_lock, flags);
return ret;
}
int s3c2410_dma_config(enum dma_ch id, int xferunit)
{
struct s3c_pl330_chan *ch;
struct pl330_info *pi;
unsigned long flags;
int i, dbwidth, ret = 0;
spin_lock_irqsave(&res_lock, flags);
ch = id_to_chan(id);
if (!ch || chan_free(ch)) {
ret = -EINVAL;
goto cfg_exit;
}
pi = ch->dmac->pi;
dbwidth = pi->pcfg.data_bus_width / 8;
if (xferunit > dbwidth) {
ret = -EINVAL;
goto cfg_exit;
}
i = 0;
while (xferunit != (1 << i))
i++;
if (xferunit == (1 << i))
ch->rqcfg.brst_size = i;
else
ret = -EINVAL;
cfg_exit:
spin_unlock_irqrestore(&res_lock, flags);
return ret;
}
int s3c2410_dma_setflags(enum dma_ch id, unsigned int options)
{
struct s3c_pl330_chan *ch;
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&res_lock, flags);
ch = id_to_chan(id);
if (!ch || chan_free(ch) || options & ~(S3C_PL330_FLAGS))
ret = -EINVAL;
else
ch->options = options;
spin_unlock_irqrestore(&res_lock, flags);
return 0;
}
int s3c2410_dma_set_buffdone_fn(enum dma_ch id, s3c2410_dma_cbfn_t rtn)
{
struct s3c_pl330_chan *ch;
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&res_lock, flags);
ch = id_to_chan(id);
if (!ch || chan_free(ch))
ret = -EINVAL;
else
ch->callback_fn = rtn;
spin_unlock_irqrestore(&res_lock, flags);
return ret;
}
int s3c2410_dma_devconfig(enum dma_ch id, enum s3c2410_dmasrc source,
unsigned long address)
{
struct s3c_pl330_chan *ch;
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&res_lock, flags);
ch = id_to_chan(id);
if (!ch || chan_free(ch)) {
ret = -EINVAL;
goto devcfg_exit;
}
switch (source) {
case S3C2410_DMASRC_HW:
ch->req[0].rqtype = DEVTOMEM;
ch->req[1].rqtype = DEVTOMEM;
ch->rqcfg.src_inc = 0;
ch->rqcfg.dst_inc = 1;
break;
case S3C2410_DMASRC_MEM:
ch->req[0].rqtype = MEMTODEV;
ch->req[1].rqtype = MEMTODEV;
ch->rqcfg.src_inc = 1;
ch->rqcfg.dst_inc = 0;
break;
default:
ret = -EINVAL;
goto devcfg_exit;
}
ch->sdaddr = address;
devcfg_exit:
spin_unlock_irqrestore(&res_lock, flags);
return ret;
}
int s3c2410_dma_getposition(enum dma_ch id, dma_addr_t *src, dma_addr_t *dst)
{
struct s3c_pl330_chan *ch = id_to_chan(id);
struct pl330_chanstatus status;
int ret;
if (!ch || chan_free(ch))
return -EINVAL;
ret = pl330_chan_status(ch->pl330_chan_id, &status);
if (ret < 0)
return ret;
*src = status.src_addr;
*dst = status.dst_addr;
return 0;
}
static irqreturn_t pl330_irq_handler(int irq, void *data)
{
if (pl330_update(data))
return IRQ_HANDLED;
else
return IRQ_NONE;
}
static int pl330_probe(struct platform_device *pdev)
{
struct s3c_pl330_dmac *s3c_pl330_dmac;
struct s3c_pl330_platdata *pl330pd;
struct pl330_info *pl330_info;
struct resource *res;
int i, ret, irq;
pl330pd = pdev->dev.platform_data;
if (!pl330pd || !pl330pd->peri) {
dev_err(&pdev->dev, "platform data missing!\n");
return -ENODEV;
}
pl330_info = kzalloc(sizeof(*pl330_info), GFP_KERNEL);
if (!pl330_info)
return -ENOMEM;
pl330_info->pl330_data = NULL;
pl330_info->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
ret = -ENODEV;
goto probe_err1;
}
request_mem_region(res->start, resource_size(res), pdev->name);
pl330_info->base = ioremap(res->start, resource_size(res));
if (!pl330_info->base) {
ret = -ENXIO;
goto probe_err2;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
ret = irq;
goto probe_err3;
}
ret = request_irq(irq, pl330_irq_handler, 0,
dev_name(&pdev->dev), pl330_info);
if (ret)
goto probe_err4;
s3c_pl330_dmac = kmalloc(sizeof(*s3c_pl330_dmac), GFP_KERNEL);
if (!s3c_pl330_dmac) {
ret = -ENOMEM;
goto probe_err5;
}
s3c_pl330_dmac->clk = clk_get(&pdev->dev, "pdma");
if (IS_ERR(s3c_pl330_dmac->clk)) {
dev_err(&pdev->dev, "Cannot get operation clock.\n");
ret = -EINVAL;
goto probe_err6;
}
clk_enable(s3c_pl330_dmac->clk);
ret = pl330_add(pl330_info);
if (ret)
goto probe_err7;
s3c_pl330_dmac->pi = pl330_info;
s3c_pl330_dmac->busy_chan = 0;
s3c_pl330_dmac->kmcache = kmem_cache_create(dev_name(&pdev->dev),
sizeof(struct s3c_pl330_xfer), 0, 0, NULL);
if (!s3c_pl330_dmac->kmcache) {
ret = -ENOMEM;
goto probe_err8;
}
s3c_pl330_dmac->peri = pl330pd->peri;
list_add_tail(&s3c_pl330_dmac->node, &dmac_list);
for (i = 0; i < PL330_MAX_PERI; i++)
if (s3c_pl330_dmac->peri[i] != DMACH_MAX)
chan_add(s3c_pl330_dmac->peri[i]);
printk(KERN_INFO
"Loaded driver for PL330 DMAC-%d %s\n", pdev->id, pdev->name);
printk(KERN_INFO
"\tDBUFF-%ux%ubytes Num_Chans-%u Num_Peri-%u Num_Events-%u\n",
pl330_info->pcfg.data_buf_dep,
pl330_info->pcfg.data_bus_width / 8, pl330_info->pcfg.num_chan,
pl330_info->pcfg.num_peri, pl330_info->pcfg.num_events);
return 0;
probe_err8:
pl330_del(pl330_info);
probe_err7:
clk_disable(s3c_pl330_dmac->clk);
clk_put(s3c_pl330_dmac->clk);
probe_err6:
kfree(s3c_pl330_dmac);
probe_err5:
free_irq(irq, pl330_info);
probe_err4:
probe_err3:
iounmap(pl330_info->base);
probe_err2:
release_mem_region(res->start, resource_size(res));
probe_err1:
kfree(pl330_info);
return ret;
}
static int pl330_remove(struct platform_device *pdev)
{
struct s3c_pl330_dmac *dmac, *d;
struct s3c_pl330_chan *ch;
unsigned long flags;
int del, found;
if (!pdev->dev.platform_data)
return -EINVAL;
spin_lock_irqsave(&res_lock, flags);
found = 0;
list_for_each_entry(d, &dmac_list, node)
if (d->pi->dev == &pdev->dev) {
found = 1;
break;
}
if (!found) {
spin_unlock_irqrestore(&res_lock, flags);
return 0;
}
dmac = d;
list_for_each_entry(ch, &chan_list, node) {
if (iface_of_dmac(dmac, ch->id))
del = 1;
else
continue;
list_for_each_entry(d, &dmac_list, node)
if (d != dmac && iface_of_dmac(d, ch->id)) {
del = 0;
break;
}
if (del) {
spin_unlock_irqrestore(&res_lock, flags);
s3c2410_dma_free(ch->id, ch->client);
spin_lock_irqsave(&res_lock, flags);
list_del(&ch->node);
kfree(ch);
}
}
clk_disable(dmac->clk);
clk_put(dmac->clk);
list_del(&dmac->node);
kfree(dmac);
spin_unlock_irqrestore(&res_lock, flags);
return 0;
}
static int __init pl330_init(void)
{
return platform_driver_register(&pl330_driver);
}
static void __exit pl330_exit(void)
{
platform_driver_unregister(&pl330_driver);
return;
}
