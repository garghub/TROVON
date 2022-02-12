static void ep_bd_list_free(struct bdc_ep *ep, u32 num_tabs)
{
struct bd_list *bd_list = &ep->bd_list;
struct bdc *bdc = ep->bdc;
struct bd_table *bd_table;
int index;
dev_dbg(bdc->dev, "%s ep:%s num_tabs:%d\n",
__func__, ep->name, num_tabs);
if (!bd_list->bd_table_array) {
dev_dbg(bdc->dev, "%s already freed\n", ep->name);
return;
}
for (index = 0; index < num_tabs; index++) {
bd_table = bd_list->bd_table_array[index];
dev_dbg(bdc->dev, "bd_table:%p index:%d\n", bd_table, index);
if (!bd_table) {
dev_dbg(bdc->dev, "bd_table not allocated\n");
continue;
}
if (!bd_table->start_bd) {
dev_dbg(bdc->dev, "bd dma pool not allocated\n");
continue;
}
dev_dbg(bdc->dev,
"Free dma pool start_bd:%p dma:%llx\n",
bd_table->start_bd,
(unsigned long long)bd_table->dma);
dma_pool_free(bdc->bd_table_pool,
bd_table->start_bd,
bd_table->dma);
kfree(bd_table);
}
kfree(ep->bd_list.bd_table_array);
}
static inline void chain_table(struct bd_table *prev_table,
struct bd_table *next_table,
u32 bd_p_tab)
{
prev_table->start_bd[bd_p_tab-1].offset[0] =
cpu_to_le32(lower_32_bits(next_table->dma));
prev_table->start_bd[bd_p_tab-1].offset[1] =
cpu_to_le32(upper_32_bits(next_table->dma));
prev_table->start_bd[bd_p_tab-1].offset[2] =
0x0;
prev_table->start_bd[bd_p_tab-1].offset[3] =
cpu_to_le32(MARK_CHAIN_BD);
}
static int ep_bd_list_alloc(struct bdc_ep *ep)
{
struct bd_table *prev_table = NULL;
int index, num_tabs, bd_p_tab;
struct bdc *bdc = ep->bdc;
struct bd_table *bd_table;
dma_addr_t dma;
if (usb_endpoint_xfer_isoc(ep->desc))
num_tabs = NUM_TABLES_ISOCH;
else
num_tabs = NUM_TABLES;
bd_p_tab = NUM_BDS_PER_TABLE;
dev_dbg(bdc->dev,
"%s ep:%p num_tabs:%d\n",
__func__, ep, num_tabs);
ep->bd_list.bd_table_array = kzalloc(
num_tabs * sizeof(struct bd_table *),
GFP_ATOMIC);
if (!ep->bd_list.bd_table_array)
return -ENOMEM;
for (index = 0; index < num_tabs; index++) {
bd_table = kzalloc(sizeof(struct bd_table), GFP_ATOMIC);
if (!bd_table)
goto fail;
bd_table->start_bd = dma_pool_alloc(bdc->bd_table_pool,
GFP_ATOMIC,
&dma);
if (!bd_table->start_bd) {
kfree(bd_table);
goto fail;
}
bd_table->dma = dma;
dev_dbg(bdc->dev,
"index:%d start_bd:%p dma=%08llx prev_table:%p\n",
index, bd_table->start_bd,
(unsigned long long)bd_table->dma, prev_table);
ep->bd_list.bd_table_array[index] = bd_table;
memset(bd_table->start_bd, 0, bd_p_tab * sizeof(struct bdc_bd));
if (prev_table)
chain_table(prev_table, bd_table, bd_p_tab);
prev_table = bd_table;
}
chain_table(prev_table, ep->bd_list.bd_table_array[0], bd_p_tab);
ep->bd_list.num_tabs = num_tabs;
ep->bd_list.max_bdi = (num_tabs * bd_p_tab) - 1;
ep->bd_list.num_tabs = num_tabs;
ep->bd_list.num_bds_table = bd_p_tab;
ep->bd_list.eqp_bdi = 0;
ep->bd_list.hwd_bdi = 0;
return 0;
fail:
ep_bd_list_free(ep, num_tabs);
return -ENOMEM;
}
static inline int bd_needed_req(struct bdc_req *req)
{
int bd_needed = 0;
int remaining;
if (req->usb_req.length == 0)
return 1;
remaining = req->usb_req.length % BD_MAX_BUFF_SIZE;
if (remaining)
bd_needed++;
remaining = req->usb_req.length / BD_MAX_BUFF_SIZE;
bd_needed += remaining;
return bd_needed;
}
static int bd_add_to_bdi(struct bdc_ep *ep, dma_addr_t bd_dma_addr)
{
struct bd_list *bd_list = &ep->bd_list;
dma_addr_t dma_first_bd, dma_last_bd;
struct bdc *bdc = ep->bdc;
struct bd_table *bd_table;
bool found = false;
int tbi, bdi;
dma_first_bd = dma_last_bd = 0;
dev_dbg(bdc->dev, "%s %llx\n",
__func__, (unsigned long long)bd_dma_addr);
for (tbi = 0; tbi < bd_list->num_tabs; tbi++) {
bd_table = bd_list->bd_table_array[tbi];
dma_first_bd = bd_table->dma;
dma_last_bd = bd_table->dma +
(sizeof(struct bdc_bd) *
(bd_list->num_bds_table - 1));
dev_dbg(bdc->dev, "dma_first_bd:%llx dma_last_bd:%llx\n",
(unsigned long long)dma_first_bd,
(unsigned long long)dma_last_bd);
if (bd_dma_addr >= dma_first_bd && bd_dma_addr <= dma_last_bd) {
found = true;
break;
}
}
if (unlikely(!found)) {
dev_err(bdc->dev, "%s FATAL err, bd not found\n", __func__);
return -EINVAL;
}
bdi = (bd_dma_addr - dma_first_bd) / sizeof(struct bdc_bd);
return (bdi + (tbi * bd_list->num_bds_table));
}
static int bdi_to_tbi(struct bdc_ep *ep, int bdi)
{
int tbi;
tbi = bdi / ep->bd_list.num_bds_table;
dev_vdbg(ep->bdc->dev,
"bdi:%d num_bds_table:%d tbi:%d\n",
bdi, ep->bd_list.num_bds_table, tbi);
return tbi;
}
static inline int find_end_bdi(struct bdc_ep *ep, int next_hwd_bdi)
{
int end_bdi;
end_bdi = next_hwd_bdi - 1;
if (end_bdi < 0)
end_bdi = ep->bd_list.max_bdi - 1;
else if ((end_bdi % (ep->bd_list.num_bds_table-1)) == 0)
end_bdi--;
return end_bdi;
}
static int bd_available_ep(struct bdc_ep *ep)
{
struct bd_list *bd_list = &ep->bd_list;
int available1, available2;
struct bdc *bdc = ep->bdc;
int chain_bd1, chain_bd2;
int available_bd = 0;
available1 = available2 = chain_bd1 = chain_bd2 = 0;
if (bd_list->eqp_bdi == bd_list->hwd_bdi)
return bd_list->max_bdi - bd_list->num_tabs;
if (bd_list->hwd_bdi < bd_list->eqp_bdi) {
available1 = bd_list->max_bdi - bd_list->eqp_bdi;
available2 = bd_list->hwd_bdi;
chain_bd1 = available1 / bd_list->num_bds_table;
chain_bd2 = available2 / bd_list->num_bds_table;
dev_vdbg(bdc->dev, "chain_bd1:%d chain_bd2:%d\n",
chain_bd1, chain_bd2);
available_bd = available1 + available2 - chain_bd1 - chain_bd2;
} else {
available1 = bd_list->hwd_bdi - bd_list->eqp_bdi;
if ((bd_list->hwd_bdi - bd_list->eqp_bdi)
<= bd_list->num_bds_table) {
if (!(bdi_to_tbi(ep, bd_list->hwd_bdi)
== bdi_to_tbi(ep, bd_list->eqp_bdi))) {
available_bd = available1 - 1;
}
} else {
chain_bd1 = available1 / bd_list->num_bds_table;
available_bd = available1 - chain_bd1;
}
}
available_bd--;
dev_vdbg(bdc->dev, "available_bd:%d\n", available_bd);
return available_bd;
}
void bdc_notify_xfr(struct bdc *bdc, u32 epnum)
{
struct bdc_ep *ep = bdc->bdc_ep_array[epnum];
dev_vdbg(bdc->dev, "%s epnum:%d\n", __func__, epnum);
if (unlikely(ep->flags & BDC_EP_STOP))
ep->flags &= ~BDC_EP_STOP;
bdc_writel(bdc->regs, BDC_XSFNTF, epnum);
}
static struct bdc_bd *bdi_to_bd(struct bdc_ep *ep, int bdi)
{
int tbi = bdi_to_tbi(ep, bdi);
int local_bdi = 0;
local_bdi = bdi - (tbi * ep->bd_list.num_bds_table);
dev_vdbg(ep->bdc->dev,
"%s bdi:%d local_bdi:%d\n",
__func__, bdi, local_bdi);
return (ep->bd_list.bd_table_array[tbi]->start_bd + local_bdi);
}
static void ep_bdlist_eqp_adv(struct bdc_ep *ep)
{
ep->bd_list.eqp_bdi++;
if (((ep->bd_list.eqp_bdi + 1) % ep->bd_list.num_bds_table) == 0)
ep->bd_list.eqp_bdi++;
if (ep->bd_list.eqp_bdi == (ep->bd_list.max_bdi + 1))
ep->bd_list.eqp_bdi = 0;
}
static int setup_first_bd_ep0(struct bdc *bdc, struct bdc_req *req, u32 *dword3)
{
u16 wValue;
u32 req_len;
req->ep->dir = 0;
req_len = req->usb_req.length;
switch (bdc->ep0_state) {
case WAIT_FOR_DATA_START:
*dword3 |= BD_TYPE_DS;
if (bdc->setup_pkt.bRequestType & USB_DIR_IN)
*dword3 |= BD_DIR_IN;
wValue = le16_to_cpu(bdc->setup_pkt.wValue);
if ((wValue > req_len) &&
(req_len % bdc->gadget.ep0->maxpacket == 0)) {
dev_dbg(bdc->dev, "ZLP needed wVal:%d len:%d MaxP:%d\n",
wValue, req_len,
bdc->gadget.ep0->maxpacket);
bdc->zlp_needed = true;
}
break;
case WAIT_FOR_STATUS_START:
*dword3 |= BD_TYPE_SS;
if (!le16_to_cpu(bdc->setup_pkt.wLength) ||
!(bdc->setup_pkt.bRequestType & USB_DIR_IN))
*dword3 |= BD_DIR_IN;
break;
default:
dev_err(bdc->dev,
"Unknown ep0 state for queueing bd ep0_state:%s\n",
ep0_state_string[bdc->ep0_state]);
return -EINVAL;
}
return 0;
}
static int setup_bd_list_xfr(struct bdc *bdc, struct bdc_req *req, int num_bds)
{
dma_addr_t buf_add = req->usb_req.dma;
u32 maxp, tfs, dword2, dword3;
struct bd_transfer *bd_xfr;
struct bd_list *bd_list;
struct bdc_ep *ep;
struct bdc_bd *bd;
int ret, bdnum;
u32 req_len;
ep = req->ep;
bd_list = &ep->bd_list;
bd_xfr = &req->bd_xfr;
bd_xfr->req = req;
bd_xfr->start_bdi = bd_list->eqp_bdi;
bd = bdi_to_bd(ep, bd_list->eqp_bdi);
req_len = req->usb_req.length;
maxp = usb_endpoint_maxp(ep->desc);
tfs = roundup(req->usb_req.length, maxp);
tfs = tfs/maxp;
dev_vdbg(bdc->dev, "%s ep:%s num_bds:%d tfs:%d r_len:%d bd:%p\n",
__func__, ep->name, num_bds, tfs, req_len, bd);
for (bdnum = 0; bdnum < num_bds; bdnum++) {
dword2 = dword3 = 0;
if (!bdnum) {
dword3 |= BD_SOT|BD_SBF|(tfs<<BD_TFS_SHIFT);
dword2 |= BD_LTF;
if (ep->ep_num == 1) {
ret = setup_first_bd_ep0(bdc, req, &dword3);
if (ret)
return ret;
}
}
if (!req->ep->dir)
dword3 |= BD_ISP;
if (req_len > BD_MAX_BUFF_SIZE) {
dword2 |= BD_MAX_BUFF_SIZE;
req_len -= BD_MAX_BUFF_SIZE;
} else {
dword2 |= req_len;
dword3 |= BD_IOC;
dword3 |= BD_EOT;
}
dword2 |= BD_INTR_TARGET(0);
bd = bdi_to_bd(ep, ep->bd_list.eqp_bdi);
if (unlikely(!bd)) {
dev_err(bdc->dev, "Err bd pointing to wrong addr\n");
return -EINVAL;
}
bd->offset[0] = cpu_to_le32(lower_32_bits(buf_add));
bd->offset[1] = cpu_to_le32(upper_32_bits(buf_add));
bd->offset[2] = cpu_to_le32(dword2);
bd->offset[3] = cpu_to_le32(dword3);
ep_bdlist_eqp_adv(ep);
buf_add += BD_MAX_BUFF_SIZE;
dev_vdbg(bdc->dev, "buf_add:%08llx req_len:%d bd:%p eqp:%d\n",
(unsigned long long)buf_add, req_len, bd,
ep->bd_list.eqp_bdi);
bd = bdi_to_bd(ep, ep->bd_list.eqp_bdi);
bd->offset[3] = cpu_to_le32(BD_SBF);
}
bd = bdi_to_bd(ep, bd_xfr->start_bdi);
bd->offset[3] &= cpu_to_le32(~BD_SBF);
bd_xfr->num_bds = num_bds;
bd_xfr->next_hwd_bdi = ep->bd_list.eqp_bdi;
wmb();
return 0;
}
static int bdc_queue_xfr(struct bdc *bdc, struct bdc_req *req)
{
int num_bds, bd_available;
struct bdc_ep *ep;
int ret;
ep = req->ep;
dev_dbg(bdc->dev, "%s req:%p\n", __func__, req);
dev_dbg(bdc->dev, "eqp_bdi:%d hwd_bdi:%d\n",
ep->bd_list.eqp_bdi, ep->bd_list.hwd_bdi);
num_bds = bd_needed_req(req);
bd_available = bd_available_ep(ep);
if (num_bds > bd_available)
return -ENOMEM;
ret = setup_bd_list_xfr(bdc, req, num_bds);
if (ret)
return ret;
list_add_tail(&req->queue, &ep->queue);
bdc_dbg_bd_list(bdc, ep);
bdc_notify_xfr(bdc, ep->ep_num);
return 0;
}
static void bdc_req_complete(struct bdc_ep *ep, struct bdc_req *req,
int status)
{
struct bdc *bdc = ep->bdc;
if (req == NULL || &req->queue == NULL || &req->usb_req == NULL)
return;
dev_dbg(bdc->dev, "%s ep:%s status:%d\n", __func__, ep->name, status);
list_del(&req->queue);
req->usb_req.status = status;
usb_gadget_unmap_request(&bdc->gadget, &req->usb_req, ep->dir);
if (req->usb_req.complete) {
spin_unlock(&bdc->lock);
usb_gadget_giveback_request(&ep->usb_ep, &req->usb_req);
spin_lock(&bdc->lock);
}
}
int bdc_ep_disable(struct bdc_ep *ep)
{
struct bdc_req *req;
struct bdc *bdc;
int ret;
ret = 0;
bdc = ep->bdc;
dev_dbg(bdc->dev, "%s() ep->ep_num=%d\n", __func__, ep->ep_num);
ret = bdc_stop_ep(bdc, ep->ep_num);
while (!list_empty(&ep->queue)) {
req = list_entry(ep->queue.next, struct bdc_req,
queue);
bdc_req_complete(ep, req, -ESHUTDOWN);
}
ret = bdc_dconfig_ep(bdc, ep);
if (ret)
dev_warn(bdc->dev,
"dconfig fail but continue with memory free");
ep->flags = 0;
if (ep->ep_num == 1)
return 0;
ep_bd_list_free(ep, ep->bd_list.num_tabs);
ep->desc = NULL;
ep->comp_desc = NULL;
ep->usb_ep.desc = NULL;
ep->ep_type = 0;
return ret;
}
int bdc_ep_enable(struct bdc_ep *ep)
{
struct bdc *bdc;
int ret = 0;
bdc = ep->bdc;
dev_dbg(bdc->dev, "%s NUM_TABLES:%d %d\n",
__func__, NUM_TABLES, NUM_TABLES_ISOCH);
ret = ep_bd_list_alloc(ep);
if (ret) {
dev_err(bdc->dev, "ep bd list allocation failed:%d\n", ret);
return -ENOMEM;
}
bdc_dbg_bd_list(bdc, ep);
ep->flags |= BDC_EP_ENABLED;
if (ep->ep_num == 1)
return ret;
ret = bdc_config_ep(bdc, ep);
if (ret)
return ret;
ep->usb_ep.maxpacket = usb_endpoint_maxp(ep->desc);
ep->usb_ep.desc = ep->desc;
ep->usb_ep.comp_desc = ep->comp_desc;
ep->ep_type = usb_endpoint_type(ep->desc);
ep->flags |= BDC_EP_ENABLED;
return 0;
}
static int ep0_queue_status_stage(struct bdc *bdc)
{
struct bdc_req *status_req;
struct bdc_ep *ep;
status_req = &bdc->status_req;
ep = bdc->bdc_ep_array[1];
status_req->ep = ep;
status_req->usb_req.length = 0;
status_req->usb_req.status = -EINPROGRESS;
status_req->usb_req.actual = 0;
status_req->usb_req.complete = NULL;
bdc_queue_xfr(bdc, status_req);
return 0;
}
static int ep0_queue(struct bdc_ep *ep, struct bdc_req *req)
{
struct bdc *bdc;
int ret;
bdc = ep->bdc;
dev_dbg(bdc->dev, "%s()\n", __func__);
req->usb_req.actual = 0;
req->usb_req.status = -EINPROGRESS;
req->epnum = ep->ep_num;
if (bdc->delayed_status) {
bdc->delayed_status = false;
if (bdc->ep0_state == WAIT_FOR_STATUS_START) {
ep0_queue_status_stage(bdc);
bdc->ep0_state = WAIT_FOR_STATUS_XMIT;
return 0;
}
} else {
if (req->usb_req.length == 0)
return 0;
}
ret = usb_gadget_map_request(&bdc->gadget, &req->usb_req, ep->dir);
if (ret) {
dev_err(bdc->dev, "dma mapping failed %s\n", ep->name);
return ret;
}
return bdc_queue_xfr(bdc, req);
}
static int ep0_queue_data_stage(struct bdc *bdc)
{
struct bdc_ep *ep;
dev_dbg(bdc->dev, "%s\n", __func__);
ep = bdc->bdc_ep_array[1];
bdc->ep0_req.ep = ep;
bdc->ep0_req.usb_req.complete = NULL;
return ep0_queue(ep, &bdc->ep0_req);
}
static int ep_queue(struct bdc_ep *ep, struct bdc_req *req)
{
struct bdc *bdc;
int ret = 0;
if (!req || !ep->usb_ep.desc)
return -EINVAL;
bdc = ep->bdc;
req->usb_req.actual = 0;
req->usb_req.status = -EINPROGRESS;
req->epnum = ep->ep_num;
ret = usb_gadget_map_request(&bdc->gadget, &req->usb_req, ep->dir);
if (ret) {
dev_err(bdc->dev, "dma mapping failed\n");
return ret;
}
return bdc_queue_xfr(bdc, req);
}
static int ep_dequeue(struct bdc_ep *ep, struct bdc_req *req)
{
int start_bdi, end_bdi, tbi, eqp_bdi, curr_hw_dqpi;
bool start_pending, end_pending;
bool first_remove = false;
struct bdc_req *first_req;
struct bdc_bd *bd_start;
struct bd_table *table;
dma_addr_t next_bd_dma;
u64 deq_ptr_64 = 0;
struct bdc *bdc;
u32 tmp_32;
int ret;
bdc = ep->bdc;
start_pending = end_pending = false;
eqp_bdi = ep->bd_list.eqp_bdi - 1;
if (eqp_bdi < 0)
eqp_bdi = ep->bd_list.max_bdi;
start_bdi = req->bd_xfr.start_bdi;
end_bdi = find_end_bdi(ep, req->bd_xfr.next_hwd_bdi);
dev_dbg(bdc->dev, "%s ep:%s start:%d end:%d\n",
__func__, ep->name, start_bdi, end_bdi);
dev_dbg(bdc->dev, "ep_dequeue ep=%p ep->desc=%p\n",
ep, (void *)ep->usb_ep.desc);
ret = bdc_stop_ep(bdc, ep->ep_num);
if (ret)
return 0;
tmp_32 = bdc_readl(bdc->regs, BDC_EPSTS0);
deq_ptr_64 = tmp_32;
tmp_32 = bdc_readl(bdc->regs, BDC_EPSTS1);
deq_ptr_64 |= ((u64)tmp_32 << 32);
curr_hw_dqpi = bd_add_to_bdi(ep, deq_ptr_64);
if (curr_hw_dqpi < 0)
return curr_hw_dqpi;
if (curr_hw_dqpi > eqp_bdi) {
if (start_bdi >= curr_hw_dqpi || start_bdi <= eqp_bdi) {
start_pending = true;
end_pending = true;
} else if (end_bdi >= curr_hw_dqpi || end_bdi <= eqp_bdi) {
end_pending = true;
}
} else {
if (start_bdi >= curr_hw_dqpi) {
start_pending = true;
end_pending = true;
} else if (end_bdi >= curr_hw_dqpi) {
end_pending = true;
}
}
dev_dbg(bdc->dev,
"start_pending:%d end_pending:%d speed:%d\n",
start_pending, end_pending, bdc->gadget.speed);
if (!start_pending && !end_pending)
return -EINVAL;
if (bdc->gadget.speed == USB_SPEED_UNKNOWN)
return 0;
tbi = bdi_to_tbi(ep, req->bd_xfr.next_hwd_bdi);
table = ep->bd_list.bd_table_array[tbi];
next_bd_dma = table->dma +
sizeof(struct bdc_bd)*(req->bd_xfr.next_hwd_bdi -
tbi * ep->bd_list.num_bds_table);
first_req = list_first_entry(&ep->queue, struct bdc_req,
queue);
if (req == first_req)
first_remove = true;
if (start_pending && !first_remove) {
bd_start = bdi_to_bd(ep, start_bdi);
bd_start->offset[0] = cpu_to_le32(lower_32_bits(next_bd_dma));
bd_start->offset[1] = cpu_to_le32(upper_32_bits(next_bd_dma));
bd_start->offset[2] = 0x0;
bd_start->offset[3] = cpu_to_le32(MARK_CHAIN_BD);
bdc_dbg_bd_list(bdc, ep);
} else if (end_pending) {
ret = bdc_ep_bla(bdc, ep, next_bd_dma);
if (ret) {
dev_err(bdc->dev, "error in ep_bla:%d\n", ret);
return ret;
}
}
return 0;
}
static int ep_set_halt(struct bdc_ep *ep, u32 value)
{
struct bdc *bdc;
int ret;
bdc = ep->bdc;
dev_dbg(bdc->dev, "%s ep:%s value=%d\n", __func__, ep->name, value);
if (value) {
dev_dbg(bdc->dev, "Halt\n");
if (ep->ep_num == 1)
bdc->ep0_state = WAIT_FOR_SETUP;
ret = bdc_ep_set_stall(bdc, ep->ep_num);
if (ret)
dev_err(bdc->dev, "failed to set STALL on %s\n",
ep->name);
else
ep->flags |= BDC_EP_STALL;
} else {
dev_dbg(bdc->dev, "Before Clear\n");
ret = bdc_ep_clear_stall(bdc, ep->ep_num);
if (ret)
dev_err(bdc->dev, "failed to clear STALL on %s\n",
ep->name);
else
ep->flags &= ~BDC_EP_STALL;
dev_dbg(bdc->dev, "After Clear\n");
}
return ret;
}
void bdc_free_ep(struct bdc *bdc)
{
struct bdc_ep *ep;
u8 epnum;
dev_dbg(bdc->dev, "%s\n", __func__);
for (epnum = 1; epnum < bdc->num_eps; epnum++) {
ep = bdc->bdc_ep_array[epnum];
if (!ep)
continue;
if (ep->flags & BDC_EP_ENABLED)
ep_bd_list_free(ep, ep->bd_list.num_tabs);
if (epnum != 1)
list_del(&ep->usb_ep.ep_list);
kfree(ep);
}
}
static int bdc_set_test_mode(struct bdc *bdc)
{
u32 usb2_pm;
usb2_pm = bdc_readl(bdc->regs, BDC_USPPM2);
usb2_pm &= ~BDC_PTC_MASK;
dev_dbg(bdc->dev, "%s\n", __func__);
switch (bdc->test_mode) {
case TEST_J:
case TEST_K:
case TEST_SE0_NAK:
case TEST_PACKET:
case TEST_FORCE_EN:
usb2_pm |= bdc->test_mode << 28;
break;
default:
return -EINVAL;
}
dev_dbg(bdc->dev, "usb2_pm=%08x", usb2_pm);
bdc_writel(bdc->regs, BDC_USPPM2, usb2_pm);
return 0;
}
static void handle_xsr_succ_status(struct bdc *bdc, struct bdc_ep *ep,
struct bdc_sr *sreport)
{
int short_bdi, start_bdi, end_bdi, max_len_bds, chain_bds;
struct bd_list *bd_list = &ep->bd_list;
int actual_length, length_short;
struct bd_transfer *bd_xfr;
struct bdc_bd *short_bd;
struct bdc_req *req;
u64 deq_ptr_64 = 0;
int status = 0;
int sr_status;
u32 tmp_32;
dev_dbg(bdc->dev, "%s ep:%p\n", __func__, ep);
bdc_dbg_srr(bdc, 0);
if (ep->ignore_next_sr) {
ep->ignore_next_sr = false;
return;
}
if (unlikely(list_empty(&ep->queue))) {
dev_warn(bdc->dev, "xfr srr with no BD's queued\n");
return;
}
req = list_entry(ep->queue.next, struct bdc_req,
queue);
bd_xfr = &req->bd_xfr;
sr_status = XSF_STS(le32_to_cpu(sreport->offset[3]));
if (sr_status == XSF_SHORT && bd_xfr->num_bds > 1) {
tmp_32 = le32_to_cpu(sreport->offset[0]);
deq_ptr_64 = tmp_32;
tmp_32 = le32_to_cpu(sreport->offset[1]);
deq_ptr_64 |= ((u64)tmp_32 << 32);
short_bdi = bd_add_to_bdi(ep, deq_ptr_64);
if (unlikely(short_bdi < 0))
dev_warn(bdc->dev, "bd doesn't exist?\n");
start_bdi = bd_xfr->start_bdi;
if (start_bdi <= short_bdi) {
max_len_bds = short_bdi - start_bdi;
if (max_len_bds <= bd_list->num_bds_table) {
if (!(bdi_to_tbi(ep, start_bdi) ==
bdi_to_tbi(ep, short_bdi)))
max_len_bds--;
} else {
chain_bds = max_len_bds/bd_list->num_bds_table;
max_len_bds -= chain_bds;
}
} else {
chain_bds = (bd_list->max_bdi - start_bdi)/
bd_list->num_bds_table;
chain_bds += short_bdi/bd_list->num_bds_table;
max_len_bds = bd_list->max_bdi - start_bdi;
max_len_bds += short_bdi;
max_len_bds -= chain_bds;
}
end_bdi = find_end_bdi(ep, bd_xfr->next_hwd_bdi);
if (!(end_bdi == short_bdi))
ep->ignore_next_sr = true;
actual_length = max_len_bds * BD_MAX_BUFF_SIZE;
short_bd = bdi_to_bd(ep, short_bdi);
length_short = le32_to_cpu(short_bd->offset[2]) & 0x1FFFFF;
length_short -= SR_BD_LEN(le32_to_cpu(sreport->offset[2]));
actual_length += length_short;
req->usb_req.actual = actual_length;
} else {
req->usb_req.actual = req->usb_req.length -
SR_BD_LEN(le32_to_cpu(sreport->offset[2]));
dev_dbg(bdc->dev,
"len=%d actual=%d bd_xfr->next_hwd_bdi:%d\n",
req->usb_req.length, req->usb_req.actual,
bd_xfr->next_hwd_bdi);
}
ep->bd_list.hwd_bdi = bd_xfr->next_hwd_bdi;
if (req->usb_req.actual < req->usb_req.length) {
dev_dbg(bdc->dev, "short xfr on %d\n", ep->ep_num);
if (req->usb_req.short_not_ok)
status = -EREMOTEIO;
}
bdc_req_complete(ep, bd_xfr->req, status);
}
void bdc_xsf_ep0_setup_recv(struct bdc *bdc, struct bdc_sr *sreport)
{
struct usb_ctrlrequest *setup_pkt;
u32 len;
dev_dbg(bdc->dev,
"%s ep0_state:%s\n",
__func__, ep0_state_string[bdc->ep0_state]);
setup_pkt = &bdc->setup_pkt;
memcpy(setup_pkt, &sreport->offset[0], sizeof(*setup_pkt));
len = le16_to_cpu(setup_pkt->wLength);
if (!len)
bdc->ep0_state = WAIT_FOR_STATUS_START;
else
bdc->ep0_state = WAIT_FOR_DATA_START;
dev_dbg(bdc->dev,
"%s exit ep0_state:%s\n",
__func__, ep0_state_string[bdc->ep0_state]);
}
static void ep0_stall(struct bdc *bdc)
{
struct bdc_ep *ep = bdc->bdc_ep_array[1];
struct bdc_req *req;
dev_dbg(bdc->dev, "%s\n", __func__);
bdc->delayed_status = false;
ep_set_halt(ep, 1);
while (!list_empty(&ep->queue)) {
req = list_entry(ep->queue.next, struct bdc_req,
queue);
bdc_req_complete(ep, req, -ESHUTDOWN);
}
}
static int ep0_set_address(struct bdc *bdc, struct usb_ctrlrequest *ctrl)
{
enum usb_device_state state = bdc->gadget.state;
int ret = 0;
u32 addr;
addr = le16_to_cpu(ctrl->wValue);
dev_dbg(bdc->dev,
"%s addr:%d dev state:%d\n",
__func__, addr, state);
if (addr > 127)
return -EINVAL;
switch (state) {
case USB_STATE_DEFAULT:
case USB_STATE_ADDRESS:
ret = bdc_address_device(bdc, addr);
if (ret)
return ret;
if (addr)
usb_gadget_set_state(&bdc->gadget, USB_STATE_ADDRESS);
else
usb_gadget_set_state(&bdc->gadget, USB_STATE_DEFAULT);
bdc->dev_addr = addr;
break;
default:
dev_warn(bdc->dev,
"SET Address in wrong device state %d\n",
state);
ret = -EINVAL;
}
return ret;
}
static int ep0_handle_feature_dev(struct bdc *bdc, u16 wValue,
u16 wIndex, bool set)
{
enum usb_device_state state = bdc->gadget.state;
u32 usppms = 0;
dev_dbg(bdc->dev, "%s set:%d dev state:%d\n",
__func__, set, state);
switch (wValue) {
case USB_DEVICE_REMOTE_WAKEUP:
dev_dbg(bdc->dev, "USB_DEVICE_REMOTE_WAKEUP\n");
if (set)
bdc->devstatus |= REMOTE_WAKE_ENABLE;
else
bdc->devstatus &= ~REMOTE_WAKE_ENABLE;
break;
case USB_DEVICE_TEST_MODE:
dev_dbg(bdc->dev, "USB_DEVICE_TEST_MODE\n");
if ((wIndex & 0xFF) ||
(bdc->gadget.speed != USB_SPEED_HIGH) || !set)
return -EINVAL;
bdc->test_mode = wIndex >> 8;
break;
case USB_DEVICE_U1_ENABLE:
dev_dbg(bdc->dev, "USB_DEVICE_U1_ENABLE\n");
if (bdc->gadget.speed != USB_SPEED_SUPER ||
state != USB_STATE_CONFIGURED)
return -EINVAL;
usppms = bdc_readl(bdc->regs, BDC_USPPMS);
if (set) {
usppms &= ~BDC_U1T(BDC_U1T_MASK);
usppms |= BDC_U1T(U1_TIMEOUT);
usppms |= BDC_U1E | BDC_PORT_W1S;
bdc->devstatus |= (1 << USB_DEV_STAT_U1_ENABLED);
} else {
usppms &= ~BDC_U1E;
usppms |= BDC_PORT_W1S;
bdc->devstatus &= ~(1 << USB_DEV_STAT_U1_ENABLED);
}
bdc_writel(bdc->regs, BDC_USPPMS, usppms);
break;
case USB_DEVICE_U2_ENABLE:
dev_dbg(bdc->dev, "USB_DEVICE_U2_ENABLE\n");
if (bdc->gadget.speed != USB_SPEED_SUPER ||
state != USB_STATE_CONFIGURED)
return -EINVAL;
usppms = bdc_readl(bdc->regs, BDC_USPPMS);
if (set) {
usppms |= BDC_U2E;
usppms |= BDC_U2A;
bdc->devstatus |= (1 << USB_DEV_STAT_U2_ENABLED);
} else {
usppms &= ~BDC_U2E;
usppms &= ~BDC_U2A;
bdc->devstatus &= ~(1 << USB_DEV_STAT_U2_ENABLED);
}
bdc_writel(bdc->regs, BDC_USPPMS, usppms);
break;
case USB_DEVICE_LTM_ENABLE:
dev_dbg(bdc->dev, "USB_DEVICE_LTM_ENABLE?\n");
if (bdc->gadget.speed != USB_SPEED_SUPER ||
state != USB_STATE_CONFIGURED)
return -EINVAL;
break;
default:
dev_err(bdc->dev, "Unknown wValue:%d\n", wValue);
return -EOPNOTSUPP;
}
return 0;
}
static int ep0_handle_feature(struct bdc *bdc,
struct usb_ctrlrequest *setup_pkt, bool set)
{
enum usb_device_state state = bdc->gadget.state;
struct bdc_ep *ep;
u16 wValue;
u16 wIndex;
int epnum;
wValue = le16_to_cpu(setup_pkt->wValue);
wIndex = le16_to_cpu(setup_pkt->wIndex);
dev_dbg(bdc->dev,
"%s wValue=%d wIndex=%d devstate=%08x speed=%d set=%d",
__func__, wValue, wIndex, state,
bdc->gadget.speed, set);
switch (setup_pkt->bRequestType & USB_RECIP_MASK) {
case USB_RECIP_DEVICE:
return ep0_handle_feature_dev(bdc, wValue, wIndex, set);
case USB_RECIP_INTERFACE:
dev_dbg(bdc->dev, "USB_RECIP_INTERFACE\n");
if (wValue != USB_INTRF_FUNC_SUSPEND)
return -EINVAL;
if (set) {
if (wIndex & USB_INTRF_FUNC_SUSPEND_RW) {
dev_dbg(bdc->dev, "SET REMOTE_WAKEUP\n");
bdc->devstatus |= REMOTE_WAKE_ENABLE;
} else {
dev_dbg(bdc->dev, "CLEAR REMOTE_WAKEUP\n");
bdc->devstatus &= ~REMOTE_WAKE_ENABLE;
}
}
break;
case USB_RECIP_ENDPOINT:
dev_dbg(bdc->dev, "USB_RECIP_ENDPOINT\n");
if (wValue != USB_ENDPOINT_HALT)
return -EINVAL;
epnum = wIndex & USB_ENDPOINT_NUMBER_MASK;
if (epnum) {
if ((wIndex & USB_ENDPOINT_DIR_MASK) == USB_DIR_IN)
epnum = epnum * 2 + 1;
else
epnum *= 2;
} else {
epnum = 1;
}
if (epnum == 1 && !set) {
dev_dbg(bdc->dev, "ep0 stall already cleared\n");
return 0;
}
dev_dbg(bdc->dev, "epnum=%d\n", epnum);
ep = bdc->bdc_ep_array[epnum];
if (!ep)
return -EINVAL;
return ep_set_halt(ep, set);
default:
dev_err(bdc->dev, "Unknown recipient\n");
return -EINVAL;
}
return 0;
}
static int ep0_handle_status(struct bdc *bdc,
struct usb_ctrlrequest *setup_pkt)
{
enum usb_device_state state = bdc->gadget.state;
struct bdc_ep *ep;
u16 usb_status = 0;
u32 epnum;
u16 wIndex;
if (state == USB_STATE_DEFAULT)
return -EINVAL;
wIndex = le16_to_cpu(setup_pkt->wIndex);
dev_dbg(bdc->dev, "%s\n", __func__);
usb_status = bdc->devstatus;
switch (setup_pkt->bRequestType & USB_RECIP_MASK) {
case USB_RECIP_DEVICE:
dev_dbg(bdc->dev,
"USB_RECIP_DEVICE devstatus:%08x\n",
bdc->devstatus);
if (bdc->gadget.speed == USB_SPEED_SUPER)
usb_status &= ~REMOTE_WAKE_ENABLE;
break;
case USB_RECIP_INTERFACE:
dev_dbg(bdc->dev, "USB_RECIP_INTERFACE\n");
if (bdc->gadget.speed == USB_SPEED_SUPER) {
if (bdc->devstatus & REMOTE_WAKE_ENABLE)
usb_status |= REMOTE_WAKE_ENABLE;
} else {
usb_status = 0;
}
break;
case USB_RECIP_ENDPOINT:
dev_dbg(bdc->dev, "USB_RECIP_ENDPOINT\n");
epnum = wIndex & USB_ENDPOINT_NUMBER_MASK;
if (epnum) {
if ((wIndex & USB_ENDPOINT_DIR_MASK) == USB_DIR_IN)
epnum = epnum*2 + 1;
else
epnum *= 2;
} else {
epnum = 1;
}
ep = bdc->bdc_ep_array[epnum];
if (!ep) {
dev_err(bdc->dev, "ISSUE, GET_STATUS for invalid EP ?");
return -EINVAL;
}
if (ep->flags & BDC_EP_STALL)
usb_status |= 1 << USB_ENDPOINT_HALT;
break;
default:
dev_err(bdc->dev, "Unknown recipient for get_status\n");
return -EINVAL;
}
dev_dbg(bdc->dev, "usb_status=%08x\n", usb_status);
*(__le16 *)bdc->ep0_response_buff = cpu_to_le16(usb_status);
bdc->ep0_req.usb_req.length = 2;
bdc->ep0_req.usb_req.buf = &bdc->ep0_response_buff;
ep0_queue_data_stage(bdc);
return 0;
}
static void ep0_set_sel_cmpl(struct usb_ep *_ep, struct usb_request *_req)
{
}
static int ep0_set_sel(struct bdc *bdc,
struct usb_ctrlrequest *setup_pkt)
{
struct bdc_ep *ep;
u16 wLength;
dev_dbg(bdc->dev, "%s\n", __func__);
wLength = le16_to_cpu(setup_pkt->wLength);
if (unlikely(wLength != 6)) {
dev_err(bdc->dev, "%s Wrong wLength:%d\n", __func__, wLength);
return -EINVAL;
}
ep = bdc->bdc_ep_array[1];
bdc->ep0_req.ep = ep;
bdc->ep0_req.usb_req.length = 6;
bdc->ep0_req.usb_req.buf = bdc->ep0_response_buff;
bdc->ep0_req.usb_req.complete = ep0_set_sel_cmpl;
ep0_queue_data_stage(bdc);
return 0;
}
static int ep0_queue_zlp(struct bdc *bdc)
{
int ret;
dev_dbg(bdc->dev, "%s\n", __func__);
bdc->ep0_req.ep = bdc->bdc_ep_array[1];
bdc->ep0_req.usb_req.length = 0;
bdc->ep0_req.usb_req.complete = NULL;
bdc->ep0_state = WAIT_FOR_DATA_START;
ret = bdc_queue_xfr(bdc, &bdc->ep0_req);
if (ret) {
dev_err(bdc->dev, "err queueing zlp :%d\n", ret);
return ret;
}
bdc->ep0_state = WAIT_FOR_DATA_XMIT;
return 0;
}
static int handle_control_request(struct bdc *bdc)
{
enum usb_device_state state = bdc->gadget.state;
struct usb_ctrlrequest *setup_pkt;
int delegate_setup = 0;
int ret = 0;
int config = 0;
setup_pkt = &bdc->setup_pkt;
dev_dbg(bdc->dev, "%s\n", __func__);
if ((setup_pkt->bRequestType & USB_TYPE_MASK) == USB_TYPE_STANDARD) {
switch (setup_pkt->bRequest) {
case USB_REQ_SET_ADDRESS:
dev_dbg(bdc->dev, "USB_REQ_SET_ADDRESS\n");
ret = ep0_set_address(bdc, setup_pkt);
bdc->devstatus &= DEVSTATUS_CLEAR;
break;
case USB_REQ_SET_CONFIGURATION:
dev_dbg(bdc->dev, "USB_REQ_SET_CONFIGURATION\n");
if (state == USB_STATE_ADDRESS) {
usb_gadget_set_state(&bdc->gadget,
USB_STATE_CONFIGURED);
} else if (state == USB_STATE_CONFIGURED) {
config = le16_to_cpu(setup_pkt->wValue);
if (!config)
usb_gadget_set_state(
&bdc->gadget,
USB_STATE_ADDRESS);
}
delegate_setup = 1;
break;
case USB_REQ_SET_FEATURE:
dev_dbg(bdc->dev, "USB_REQ_SET_FEATURE\n");
ret = ep0_handle_feature(bdc, setup_pkt, 1);
break;
case USB_REQ_CLEAR_FEATURE:
dev_dbg(bdc->dev, "USB_REQ_CLEAR_FEATURE\n");
ret = ep0_handle_feature(bdc, setup_pkt, 0);
break;
case USB_REQ_GET_STATUS:
dev_dbg(bdc->dev, "USB_REQ_GET_STATUS\n");
ret = ep0_handle_status(bdc, setup_pkt);
break;
case USB_REQ_SET_SEL:
dev_dbg(bdc->dev, "USB_REQ_SET_SEL\n");
ret = ep0_set_sel(bdc, setup_pkt);
break;
case USB_REQ_SET_ISOCH_DELAY:
dev_warn(bdc->dev,
"USB_REQ_SET_ISOCH_DELAY not handled\n");
ret = 0;
break;
default:
delegate_setup = 1;
}
} else {
delegate_setup = 1;
}
if (delegate_setup) {
spin_unlock(&bdc->lock);
ret = bdc->gadget_driver->setup(&bdc->gadget, setup_pkt);
spin_lock(&bdc->lock);
}
return ret;
}
void bdc_xsf_ep0_data_start(struct bdc *bdc, struct bdc_sr *sreport)
{
struct bdc_ep *ep;
int ret = 0;
dev_dbg(bdc->dev, "%s\n", __func__);
ep = bdc->bdc_ep_array[1];
if (ep->flags & BDC_EP_STALL) {
ret = ep_set_halt(ep, 0);
if (ret)
goto err;
}
if (bdc->ep0_state != WAIT_FOR_DATA_START)
dev_warn(bdc->dev,
"Data stage not expected ep0_state:%s\n",
ep0_state_string[bdc->ep0_state]);
ret = handle_control_request(bdc);
if (ret == USB_GADGET_DELAYED_STATUS) {
bdc->delayed_status = true;
return;
}
if (!ret) {
bdc->ep0_state = WAIT_FOR_DATA_XMIT;
dev_dbg(bdc->dev,
"ep0_state:%s", ep0_state_string[bdc->ep0_state]);
return;
}
err:
ep0_stall(bdc);
}
void bdc_xsf_ep0_status_start(struct bdc *bdc, struct bdc_sr *sreport)
{
struct usb_ctrlrequest *setup_pkt;
struct bdc_ep *ep;
int ret = 0;
dev_dbg(bdc->dev,
"%s ep0_state:%s",
__func__, ep0_state_string[bdc->ep0_state]);
ep = bdc->bdc_ep_array[1];
if (bdc->zlp_needed)
bdc->zlp_needed = false;
if (ep->flags & BDC_EP_STALL) {
ret = ep_set_halt(ep, 0);
if (ret)
goto err;
}
if ((bdc->ep0_state != WAIT_FOR_STATUS_START) &&
(bdc->ep0_state != WAIT_FOR_DATA_XMIT))
dev_err(bdc->dev,
"Status stage recv but ep0_state:%s\n",
ep0_state_string[bdc->ep0_state]);
if (bdc->ep0_state == WAIT_FOR_DATA_XMIT) {
bdc->ep0_state = STATUS_PENDING;
dev_dbg(bdc->dev,
"status started but data not transmitted yet\n");
return;
}
setup_pkt = &bdc->setup_pkt;
if (!le16_to_cpu(setup_pkt->wLength)) {
ret = handle_control_request(bdc);
if (ret == USB_GADGET_DELAYED_STATUS) {
bdc->delayed_status = true;
return;
}
}
if (!ret) {
ep0_queue_status_stage(bdc);
bdc->ep0_state = WAIT_FOR_STATUS_XMIT;
dev_dbg(bdc->dev,
"ep0_state:%s", ep0_state_string[bdc->ep0_state]);
return;
}
err:
ep0_stall(bdc);
}
static void ep0_xsf_complete(struct bdc *bdc, struct bdc_sr *sreport)
{
dev_dbg(bdc->dev, "%s\n", __func__);
switch (bdc->ep0_state) {
case WAIT_FOR_DATA_XMIT:
bdc->ep0_state = WAIT_FOR_STATUS_START;
break;
case WAIT_FOR_STATUS_XMIT:
bdc->ep0_state = WAIT_FOR_SETUP;
if (bdc->test_mode) {
int ret;
dev_dbg(bdc->dev, "test_mode:%d\n", bdc->test_mode);
ret = bdc_set_test_mode(bdc);
if (ret < 0) {
dev_err(bdc->dev, "Err in setting Test mode\n");
return;
}
bdc->test_mode = 0;
}
break;
case STATUS_PENDING:
bdc_xsf_ep0_status_start(bdc, sreport);
break;
default:
dev_err(bdc->dev,
"Unknown ep0_state:%s\n",
ep0_state_string[bdc->ep0_state]);
}
}
void bdc_sr_xsf(struct bdc *bdc, struct bdc_sr *sreport)
{
struct bdc_ep *ep;
u32 sr_status;
u8 ep_num;
ep_num = (le32_to_cpu(sreport->offset[3])>>4) & 0x1f;
ep = bdc->bdc_ep_array[ep_num];
if (!ep || !(ep->flags & BDC_EP_ENABLED)) {
dev_err(bdc->dev, "xsf for ep not enabled\n");
return;
}
if (bdc->devstatus & FUNC_WAKE_ISSUED) {
bdc->devstatus &= ~(FUNC_WAKE_ISSUED);
dev_dbg(bdc->dev, "%s clearing FUNC_WAKE_ISSUED flag\n",
__func__);
}
sr_status = XSF_STS(le32_to_cpu(sreport->offset[3]));
dev_dbg_ratelimited(bdc->dev, "%s sr_status=%d ep:%s\n",
__func__, sr_status, ep->name);
switch (sr_status) {
case XSF_SUCC:
case XSF_SHORT:
handle_xsr_succ_status(bdc, ep, sreport);
if (ep_num == 1)
ep0_xsf_complete(bdc, sreport);
break;
case XSF_SETUP_RECV:
case XSF_DATA_START:
case XSF_STATUS_START:
if (ep_num != 1) {
dev_err(bdc->dev,
"ep0 related packets on non ep0 endpoint");
return;
}
bdc->sr_xsf_ep0[sr_status - XSF_SETUP_RECV](bdc, sreport);
break;
case XSF_BABB:
if (ep_num == 1) {
dev_dbg(bdc->dev, "Babble on ep0 zlp_need:%d\n",
bdc->zlp_needed);
if (bdc->zlp_needed) {
ep0_queue_zlp(bdc);
return;
}
}
dev_warn(bdc->dev, "Babble on ep not handled\n");
break;
default:
dev_warn(bdc->dev, "sr status not handled:%x\n", sr_status);
break;
}
}
static int bdc_gadget_ep_queue(struct usb_ep *_ep,
struct usb_request *_req, gfp_t gfp_flags)
{
struct bdc_req *req;
unsigned long flags;
struct bdc_ep *ep;
struct bdc *bdc;
int ret;
if (!_ep || !_ep->desc)
return -ESHUTDOWN;
if (!_req || !_req->complete || !_req->buf)
return -EINVAL;
ep = to_bdc_ep(_ep);
req = to_bdc_req(_req);
bdc = ep->bdc;
dev_dbg(bdc->dev, "%s ep:%p req:%p\n", __func__, ep, req);
dev_dbg(bdc->dev, "queuing request %p to %s length %d zero:%d\n",
_req, ep->name, _req->length, _req->zero);
if (!ep->usb_ep.desc) {
dev_warn(bdc->dev,
"trying to queue req %p to disabled %s\n",
_req, ep->name);
return -ESHUTDOWN;
}
if (_req->length > MAX_XFR_LEN) {
dev_warn(bdc->dev,
"req length > supported MAX:%d requested:%d\n",
MAX_XFR_LEN, _req->length);
return -EOPNOTSUPP;
}
spin_lock_irqsave(&bdc->lock, flags);
if (ep == bdc->bdc_ep_array[1])
ret = ep0_queue(ep, req);
else
ret = ep_queue(ep, req);
spin_unlock_irqrestore(&bdc->lock, flags);
return ret;
}
static int bdc_gadget_ep_dequeue(struct usb_ep *_ep,
struct usb_request *_req)
{
struct bdc_req *req;
unsigned long flags;
struct bdc_ep *ep;
struct bdc *bdc;
int ret;
if (!_ep || !_req)
return -EINVAL;
ep = to_bdc_ep(_ep);
req = to_bdc_req(_req);
bdc = ep->bdc;
dev_dbg(bdc->dev, "%s ep:%s req:%p\n", __func__, ep->name, req);
bdc_dbg_bd_list(bdc, ep);
spin_lock_irqsave(&bdc->lock, flags);
list_for_each_entry(req, &ep->queue, queue) {
if (&req->usb_req == _req)
break;
}
if (&req->usb_req != _req) {
spin_unlock_irqrestore(&bdc->lock, flags);
dev_err(bdc->dev, "usb_req !=req n");
return -EINVAL;
}
ret = ep_dequeue(ep, req);
if (ret) {
ret = -EOPNOTSUPP;
goto err;
}
bdc_req_complete(ep, req, -ECONNRESET);
err:
bdc_dbg_bd_list(bdc, ep);
spin_unlock_irqrestore(&bdc->lock, flags);
return ret;
}
static int bdc_gadget_ep_set_halt(struct usb_ep *_ep, int value)
{
unsigned long flags;
struct bdc_ep *ep;
struct bdc *bdc;
int ret;
ep = to_bdc_ep(_ep);
bdc = ep->bdc;
dev_dbg(bdc->dev, "%s ep:%s value=%d\n", __func__, ep->name, value);
spin_lock_irqsave(&bdc->lock, flags);
if (usb_endpoint_xfer_isoc(ep->usb_ep.desc))
ret = -EINVAL;
else if (!list_empty(&ep->queue))
ret = -EAGAIN;
else
ret = ep_set_halt(ep, value);
spin_unlock_irqrestore(&bdc->lock, flags);
return ret;
}
static struct usb_request *bdc_gadget_alloc_request(struct usb_ep *_ep,
gfp_t gfp_flags)
{
struct bdc_req *req;
struct bdc_ep *ep;
req = kzalloc(sizeof(*req), gfp_flags);
if (!req)
return NULL;
ep = to_bdc_ep(_ep);
req->ep = ep;
req->epnum = ep->ep_num;
req->usb_req.dma = DMA_ADDR_INVALID;
dev_dbg(ep->bdc->dev, "%s ep:%s req:%p\n", __func__, ep->name, req);
return &req->usb_req;
}
static void bdc_gadget_free_request(struct usb_ep *_ep,
struct usb_request *_req)
{
struct bdc_req *req;
req = to_bdc_req(_req);
kfree(req);
}
static int bdc_gadget_ep_enable(struct usb_ep *_ep,
const struct usb_endpoint_descriptor *desc)
{
unsigned long flags;
struct bdc_ep *ep;
struct bdc *bdc;
int ret;
if (!_ep || !desc || desc->bDescriptorType != USB_DT_ENDPOINT) {
pr_debug("bdc_gadget_ep_enable invalid parameters\n");
return -EINVAL;
}
if (!desc->wMaxPacketSize) {
pr_debug("bdc_gadget_ep_enable missing wMaxPacketSize\n");
return -EINVAL;
}
ep = to_bdc_ep(_ep);
bdc = ep->bdc;
if (ep == bdc->bdc_ep_array[1])
return -EINVAL;
if (!bdc->gadget_driver
|| bdc->gadget.speed == USB_SPEED_UNKNOWN) {
return -ESHUTDOWN;
}
dev_dbg(bdc->dev, "%s Enabling %s\n", __func__, ep->name);
spin_lock_irqsave(&bdc->lock, flags);
ep->desc = desc;
ep->comp_desc = _ep->comp_desc;
ret = bdc_ep_enable(ep);
spin_unlock_irqrestore(&bdc->lock, flags);
return ret;
}
static int bdc_gadget_ep_disable(struct usb_ep *_ep)
{
unsigned long flags;
struct bdc_ep *ep;
struct bdc *bdc;
int ret;
if (!_ep) {
pr_debug("bdc: invalid parameters\n");
return -EINVAL;
}
ep = to_bdc_ep(_ep);
bdc = ep->bdc;
if (ep == bdc->bdc_ep_array[1]) {
dev_warn(bdc->dev, "%s called for ep0\n", __func__);
return -EINVAL;
}
dev_dbg(bdc->dev,
"%s() ep:%s ep->flags:%08x\n",
__func__, ep->name, ep->flags);
if (!(ep->flags & BDC_EP_ENABLED)) {
dev_warn(bdc->dev, "%s is already disabled\n", ep->name);
return 0;
}
spin_lock_irqsave(&bdc->lock, flags);
ret = bdc_ep_disable(ep);
spin_unlock_irqrestore(&bdc->lock, flags);
return ret;
}
static int init_ep(struct bdc *bdc, u32 epnum, u32 dir)
{
struct bdc_ep *ep;
dev_dbg(bdc->dev, "%s epnum=%d dir=%d\n", __func__, epnum, dir);
ep = kzalloc(sizeof(*ep), GFP_KERNEL);
if (!ep)
return -ENOMEM;
ep->bdc = bdc;
ep->dir = dir;
if (dir)
ep->usb_ep.caps.dir_in = true;
else
ep->usb_ep.caps.dir_out = true;
if (epnum == 1) {
ep->ep_num = 1;
bdc->bdc_ep_array[ep->ep_num] = ep;
snprintf(ep->name, sizeof(ep->name), "ep%d", epnum - 1);
usb_ep_set_maxpacket_limit(&ep->usb_ep, EP0_MAX_PKT_SIZE);
ep->usb_ep.caps.type_control = true;
ep->comp_desc = NULL;
bdc->gadget.ep0 = &ep->usb_ep;
} else {
if (dir)
ep->ep_num = epnum * 2 - 1;
else
ep->ep_num = epnum * 2 - 2;
bdc->bdc_ep_array[ep->ep_num] = ep;
snprintf(ep->name, sizeof(ep->name), "ep%d%s", epnum - 1,
dir & 1 ? "in" : "out");
usb_ep_set_maxpacket_limit(&ep->usb_ep, 1024);
ep->usb_ep.caps.type_iso = true;
ep->usb_ep.caps.type_bulk = true;
ep->usb_ep.caps.type_int = true;
ep->usb_ep.max_streams = 0;
list_add_tail(&ep->usb_ep.ep_list, &bdc->gadget.ep_list);
}
ep->usb_ep.ops = &bdc_gadget_ep_ops;
ep->usb_ep.name = ep->name;
ep->flags = 0;
ep->ignore_next_sr = false;
dev_dbg(bdc->dev, "ep=%p ep->usb_ep.name=%s epnum=%d ep->epnum=%d\n",
ep, ep->usb_ep.name, epnum, ep->ep_num);
INIT_LIST_HEAD(&ep->queue);
return 0;
}
int bdc_init_ep(struct bdc *bdc)
{
u8 epnum;
int ret;
dev_dbg(bdc->dev, "%s()\n", __func__);
INIT_LIST_HEAD(&bdc->gadget.ep_list);
ret = init_ep(bdc, 1, 0);
if (ret) {
dev_err(bdc->dev, "init ep ep0 fail %d\n", ret);
return ret;
}
for (epnum = 2; epnum <= bdc->num_eps / 2; epnum++) {
ret = init_ep(bdc, epnum, 0);
if (ret) {
dev_err(bdc->dev,
"init ep failed for:%d error: %d\n",
epnum, ret);
return ret;
}
ret = init_ep(bdc, epnum, 1);
if (ret) {
dev_err(bdc->dev,
"init ep failed for:%d error: %d\n",
epnum, ret);
return ret;
}
}
return 0;
}
