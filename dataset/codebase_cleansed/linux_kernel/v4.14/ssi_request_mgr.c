void request_mgr_fini(struct ssi_drvdata *drvdata)
{
struct ssi_request_mgr_handle *req_mgr_h = drvdata->request_mgr_handle;
if (!req_mgr_h)
return;
if (req_mgr_h->dummy_comp_buff_dma != 0) {
dma_free_coherent(&drvdata->plat_dev->dev,
sizeof(u32), req_mgr_h->dummy_comp_buff,
req_mgr_h->dummy_comp_buff_dma);
}
SSI_LOG_DEBUG("max_used_hw_slots=%d\n", (req_mgr_h->hw_queue_size -
req_mgr_h->min_free_hw_slots));
SSI_LOG_DEBUG("max_used_sw_slots=%d\n", req_mgr_h->max_used_sw_slots);
#ifdef COMP_IN_WQ
flush_workqueue(req_mgr_h->workq);
destroy_workqueue(req_mgr_h->workq);
#else
tasklet_kill(&req_mgr_h->comptask);
#endif
memset(req_mgr_h, 0, sizeof(struct ssi_request_mgr_handle));
kfree(req_mgr_h);
drvdata->request_mgr_handle = NULL;
}
int request_mgr_init(struct ssi_drvdata *drvdata)
{
struct ssi_request_mgr_handle *req_mgr_h;
int rc = 0;
req_mgr_h = kzalloc(sizeof(*req_mgr_h), GFP_KERNEL);
if (!req_mgr_h) {
rc = -ENOMEM;
goto req_mgr_init_err;
}
drvdata->request_mgr_handle = req_mgr_h;
spin_lock_init(&req_mgr_h->hw_lock);
#ifdef COMP_IN_WQ
SSI_LOG_DEBUG("Initializing completion workqueue\n");
req_mgr_h->workq = create_singlethread_workqueue("arm_cc7x_wq");
if (unlikely(!req_mgr_h->workq)) {
SSI_LOG_ERR("Failed creating work queue\n");
rc = -ENOMEM;
goto req_mgr_init_err;
}
INIT_DELAYED_WORK(&req_mgr_h->compwork, comp_work_handler);
#else
SSI_LOG_DEBUG("Initializing completion tasklet\n");
tasklet_init(&req_mgr_h->comptask, comp_handler, (unsigned long)drvdata);
#endif
req_mgr_h->hw_queue_size = READ_REGISTER(drvdata->cc_base +
CC_REG_OFFSET(CRY_KERNEL, DSCRPTR_QUEUE_SRAM_SIZE));
SSI_LOG_DEBUG("hw_queue_size=0x%08X\n", req_mgr_h->hw_queue_size);
if (req_mgr_h->hw_queue_size < MIN_HW_QUEUE_SIZE) {
SSI_LOG_ERR("Invalid HW queue size = %u (Min. required is %u)\n",
req_mgr_h->hw_queue_size, MIN_HW_QUEUE_SIZE);
rc = -ENOMEM;
goto req_mgr_init_err;
}
req_mgr_h->min_free_hw_slots = req_mgr_h->hw_queue_size;
req_mgr_h->max_used_sw_slots = 0;
req_mgr_h->dummy_comp_buff = dma_alloc_coherent(&drvdata->plat_dev->dev,
sizeof(u32),
&req_mgr_h->dummy_comp_buff_dma,
GFP_KERNEL);
if (!req_mgr_h->dummy_comp_buff) {
SSI_LOG_ERR("Not enough memory to allocate DMA (%zu) dropped "
"buffer\n", sizeof(u32));
rc = -ENOMEM;
goto req_mgr_init_err;
}
hw_desc_init(&req_mgr_h->compl_desc);
set_din_const(&req_mgr_h->compl_desc, 0, sizeof(u32));
set_dout_dlli(&req_mgr_h->compl_desc, req_mgr_h->dummy_comp_buff_dma,
sizeof(u32), NS_BIT, 1);
set_flow_mode(&req_mgr_h->compl_desc, BYPASS);
set_queue_last_ind(&req_mgr_h->compl_desc);
return 0;
req_mgr_init_err:
request_mgr_fini(drvdata);
return rc;
}
static inline void enqueue_seq(
void __iomem *cc_base,
struct cc_hw_desc seq[], unsigned int seq_len)
{
int i;
for (i = 0; i < seq_len; i++) {
writel_relaxed(seq[i].word[0], (volatile void __iomem *)(cc_base + CC_REG_OFFSET(CRY_KERNEL, DSCRPTR_QUEUE_WORD0)));
writel_relaxed(seq[i].word[1], (volatile void __iomem *)(cc_base + CC_REG_OFFSET(CRY_KERNEL, DSCRPTR_QUEUE_WORD0)));
writel_relaxed(seq[i].word[2], (volatile void __iomem *)(cc_base + CC_REG_OFFSET(CRY_KERNEL, DSCRPTR_QUEUE_WORD0)));
writel_relaxed(seq[i].word[3], (volatile void __iomem *)(cc_base + CC_REG_OFFSET(CRY_KERNEL, DSCRPTR_QUEUE_WORD0)));
writel_relaxed(seq[i].word[4], (volatile void __iomem *)(cc_base + CC_REG_OFFSET(CRY_KERNEL, DSCRPTR_QUEUE_WORD0)));
wmb();
writel_relaxed(seq[i].word[5], (volatile void __iomem *)(cc_base + CC_REG_OFFSET(CRY_KERNEL, DSCRPTR_QUEUE_WORD0)));
#ifdef DX_DUMP_DESCS
SSI_LOG_DEBUG("desc[%02d]: 0x%08X 0x%08X 0x%08X 0x%08X 0x%08X 0x%08X\n", i,
seq[i].word[0], seq[i].word[1], seq[i].word[2],
seq[i].word[3], seq[i].word[4], seq[i].word[5]);
#endif
}
}
static void request_mgr_complete(struct device *dev, void *dx_compl_h, void __iomem *cc_base)
{
struct completion *this_compl = dx_compl_h;
complete(this_compl);
}
static inline int request_mgr_queues_status_check(
struct ssi_request_mgr_handle *req_mgr_h,
void __iomem *cc_base,
unsigned int total_seq_len)
{
unsigned long poll_queue;
if (unlikely(((req_mgr_h->req_queue_head + 1) &
(MAX_REQUEST_QUEUE_SIZE - 1)) ==
req_mgr_h->req_queue_tail)) {
SSI_LOG_ERR("SW FIFO is full. req_queue_head=%d sw_fifo_len=%d\n",
req_mgr_h->req_queue_head, MAX_REQUEST_QUEUE_SIZE);
return -EBUSY;
}
if ((likely(req_mgr_h->q_free_slots >= total_seq_len)))
return 0;
for (poll_queue = 0; poll_queue < SSI_MAX_POLL_ITER ; poll_queue++) {
req_mgr_h->q_free_slots =
CC_HAL_READ_REGISTER(CC_REG_OFFSET(CRY_KERNEL,
DSCRPTR_QUEUE_CONTENT));
if (unlikely(req_mgr_h->q_free_slots <
req_mgr_h->min_free_hw_slots)) {
req_mgr_h->min_free_hw_slots = req_mgr_h->q_free_slots;
}
if (likely(req_mgr_h->q_free_slots >= total_seq_len)) {
return 0;
}
SSI_LOG_DEBUG("HW FIFO is full. q_free_slots=%d total_seq_len=%d\n",
req_mgr_h->q_free_slots, total_seq_len);
}
SSI_LOG_DEBUG("HW FIFO full, timeout. req_queue_head=%d "
"sw_fifo_len=%d q_free_slots=%d total_seq_len=%d\n",
req_mgr_h->req_queue_head,
MAX_REQUEST_QUEUE_SIZE,
req_mgr_h->q_free_slots,
total_seq_len);
return -EAGAIN;
}
int send_request(
struct ssi_drvdata *drvdata, struct ssi_crypto_req *ssi_req,
struct cc_hw_desc *desc, unsigned int len, bool is_dout)
{
void __iomem *cc_base = drvdata->cc_base;
struct ssi_request_mgr_handle *req_mgr_h = drvdata->request_mgr_handle;
unsigned int used_sw_slots;
unsigned int iv_seq_len = 0;
unsigned int total_seq_len = len;
struct cc_hw_desc iv_seq[SSI_IVPOOL_SEQ_LEN];
int rc;
unsigned int max_required_seq_len = (total_seq_len +
((ssi_req->ivgen_dma_addr_len == 0) ? 0 :
SSI_IVPOOL_SEQ_LEN) +
((is_dout == 0) ? 1 : 0));
#if defined(CONFIG_PM_RUNTIME) || defined(CONFIG_PM_SLEEP)
rc = ssi_power_mgr_runtime_get(&drvdata->plat_dev->dev);
if (rc != 0) {
SSI_LOG_ERR("ssi_power_mgr_runtime_get returned %x\n", rc);
return rc;
}
#endif
do {
spin_lock_bh(&req_mgr_h->hw_lock);
rc = request_mgr_queues_status_check(req_mgr_h, cc_base,
max_required_seq_len);
if (likely(rc == 0))
break;
spin_unlock_bh(&req_mgr_h->hw_lock);
if (rc != -EAGAIN) {
#if defined(CONFIG_PM_RUNTIME) || defined(CONFIG_PM_SLEEP)
ssi_power_mgr_runtime_put_suspend(&drvdata->plat_dev->dev);
#endif
return rc;
}
msleep(1);
} while (1);
if (!is_dout) {
init_completion(&ssi_req->seq_compl);
ssi_req->user_cb = request_mgr_complete;
ssi_req->user_arg = &ssi_req->seq_compl;
total_seq_len++;
}
if (ssi_req->ivgen_dma_addr_len > 0) {
SSI_LOG_DEBUG("Acquire IV from pool into %d DMA addresses %pad, %pad, %pad, IV-size=%u\n",
ssi_req->ivgen_dma_addr_len,
ssi_req->ivgen_dma_addr[0],
ssi_req->ivgen_dma_addr[1],
ssi_req->ivgen_dma_addr[2],
ssi_req->ivgen_size);
rc = ssi_ivgen_getiv(drvdata, ssi_req->ivgen_dma_addr,
ssi_req->ivgen_dma_addr_len,
ssi_req->ivgen_size, iv_seq, &iv_seq_len);
if (unlikely(rc != 0)) {
SSI_LOG_ERR("Failed to generate IV (rc=%d)\n", rc);
spin_unlock_bh(&req_mgr_h->hw_lock);
#if defined(CONFIG_PM_RUNTIME) || defined(CONFIG_PM_SLEEP)
ssi_power_mgr_runtime_put_suspend(&drvdata->plat_dev->dev);
#endif
return rc;
}
total_seq_len += iv_seq_len;
}
used_sw_slots = ((req_mgr_h->req_queue_head - req_mgr_h->req_queue_tail) & (MAX_REQUEST_QUEUE_SIZE - 1));
if (unlikely(used_sw_slots > req_mgr_h->max_used_sw_slots))
req_mgr_h->max_used_sw_slots = used_sw_slots;
req_mgr_h->req_queue[req_mgr_h->req_queue_head] = *ssi_req;
req_mgr_h->req_queue_head = (req_mgr_h->req_queue_head + 1) & (MAX_REQUEST_QUEUE_SIZE - 1);
SSI_LOG_DEBUG("Enqueue request head=%u\n", req_mgr_h->req_queue_head);
#ifdef FLUSH_CACHE_ALL
flush_cache_all();
#endif
enqueue_seq(cc_base, iv_seq, iv_seq_len);
enqueue_seq(cc_base, desc, len);
enqueue_seq(cc_base, &req_mgr_h->compl_desc, (is_dout ? 0 : 1));
if (unlikely(req_mgr_h->q_free_slots < total_seq_len)) {
BUG();
}
req_mgr_h->q_free_slots -= total_seq_len;
spin_unlock_bh(&req_mgr_h->hw_lock);
if (!is_dout) {
wait_for_completion(&ssi_req->seq_compl);
return 0;
} else {
return -EINPROGRESS;
}
}
int send_request_init(
struct ssi_drvdata *drvdata, struct cc_hw_desc *desc, unsigned int len)
{
void __iomem *cc_base = drvdata->cc_base;
struct ssi_request_mgr_handle *req_mgr_h = drvdata->request_mgr_handle;
unsigned int total_seq_len = len;
int rc = 0;
rc = request_mgr_queues_status_check(req_mgr_h, cc_base, total_seq_len);
if (unlikely(rc != 0))
return rc;
set_queue_last_ind(&desc[(len - 1)]);
enqueue_seq(cc_base, desc, len);
req_mgr_h->q_free_slots = CC_HAL_READ_REGISTER(CC_REG_OFFSET(CRY_KERNEL,
DSCRPTR_QUEUE_CONTENT));
return 0;
}
void complete_request(struct ssi_drvdata *drvdata)
{
struct ssi_request_mgr_handle *request_mgr_handle =
drvdata->request_mgr_handle;
#ifdef COMP_IN_WQ
queue_delayed_work(request_mgr_handle->workq, &request_mgr_handle->compwork, 0);
#else
tasklet_schedule(&request_mgr_handle->comptask);
#endif
}
static void comp_work_handler(struct work_struct *work)
{
struct ssi_drvdata *drvdata =
container_of(work, struct ssi_drvdata, compwork.work);
comp_handler((unsigned long)drvdata);
}
static void proc_completions(struct ssi_drvdata *drvdata)
{
struct ssi_crypto_req *ssi_req;
struct platform_device *plat_dev = drvdata->plat_dev;
struct ssi_request_mgr_handle *request_mgr_handle =
drvdata->request_mgr_handle;
#if defined(CONFIG_PM_RUNTIME) || defined(CONFIG_PM_SLEEP)
int rc = 0;
#endif
while (request_mgr_handle->axi_completed) {
request_mgr_handle->axi_completed--;
if (unlikely(request_mgr_handle->req_queue_head == request_mgr_handle->req_queue_tail)) {
SSI_LOG_ERR("Request queue is empty req_queue_head==req_queue_tail==%u\n", request_mgr_handle->req_queue_head);
BUG();
}
ssi_req = &request_mgr_handle->req_queue[request_mgr_handle->req_queue_tail];
#ifdef FLUSH_CACHE_ALL
flush_cache_all();
#endif
#ifdef COMPLETION_DELAY
{
u32 axi_err;
int i;
SSI_LOG_INFO("Delay\n");
for (i = 0; i < 1000000; i++)
axi_err = READ_REGISTER(drvdata->cc_base + CC_REG_OFFSET(CRY_KERNEL, AXIM_MON_ERR));
}
#endif
if (likely(ssi_req->user_cb))
ssi_req->user_cb(&plat_dev->dev, ssi_req->user_arg, drvdata->cc_base);
request_mgr_handle->req_queue_tail = (request_mgr_handle->req_queue_tail + 1) & (MAX_REQUEST_QUEUE_SIZE - 1);
SSI_LOG_DEBUG("Dequeue request tail=%u\n", request_mgr_handle->req_queue_tail);
SSI_LOG_DEBUG("Request completed. axi_completed=%d\n", request_mgr_handle->axi_completed);
#if defined(CONFIG_PM_RUNTIME) || defined(CONFIG_PM_SLEEP)
rc = ssi_power_mgr_runtime_put_suspend(&plat_dev->dev);
if (rc != 0)
SSI_LOG_ERR("Failed to set runtime suspension %d\n", rc);
#endif
}
}
static inline u32 cc_axi_comp_count(void __iomem *cc_base)
{
return FIELD_GET(AXIM_MON_COMP_VALUE,
CC_HAL_READ_REGISTER(AXIM_MON_BASE_OFFSET));
}
static void comp_handler(unsigned long devarg)
{
struct ssi_drvdata *drvdata = (struct ssi_drvdata *)devarg;
void __iomem *cc_base = drvdata->cc_base;
struct ssi_request_mgr_handle *request_mgr_handle =
drvdata->request_mgr_handle;
u32 irq;
irq = (drvdata->irq & SSI_COMP_IRQ_MASK);
if (irq & SSI_COMP_IRQ_MASK) {
CC_HAL_WRITE_REGISTER(CC_REG_OFFSET(HOST_RGF, HOST_ICR), SSI_COMP_IRQ_MASK);
request_mgr_handle->axi_completed +=
cc_axi_comp_count(cc_base);
while (request_mgr_handle->axi_completed) {
do {
proc_completions(drvdata);
request_mgr_handle->axi_completed =
cc_axi_comp_count(cc_base);
} while (request_mgr_handle->axi_completed > 0);
CC_HAL_WRITE_REGISTER(CC_REG_OFFSET(HOST_RGF, HOST_ICR), SSI_COMP_IRQ_MASK);
request_mgr_handle->axi_completed +=
cc_axi_comp_count(cc_base);
}
}
CC_HAL_WRITE_REGISTER(CC_REG_OFFSET(HOST_RGF, HOST_IMR),
CC_HAL_READ_REGISTER(CC_REG_OFFSET(HOST_RGF, HOST_IMR)) & ~irq);
}
int ssi_request_mgr_runtime_resume_queue(struct ssi_drvdata *drvdata)
{
struct ssi_request_mgr_handle *request_mgr_handle = drvdata->request_mgr_handle;
spin_lock_bh(&request_mgr_handle->hw_lock);
request_mgr_handle->is_runtime_suspended = false;
spin_unlock_bh(&request_mgr_handle->hw_lock);
return 0;
}
int ssi_request_mgr_runtime_suspend_queue(struct ssi_drvdata *drvdata)
{
struct ssi_request_mgr_handle *request_mgr_handle =
drvdata->request_mgr_handle;
spin_lock_bh(&request_mgr_handle->hw_lock);
if (request_mgr_handle->req_queue_head !=
request_mgr_handle->req_queue_tail) {
spin_unlock_bh(&request_mgr_handle->hw_lock);
return -EBUSY;
}
request_mgr_handle->is_runtime_suspended = true;
spin_unlock_bh(&request_mgr_handle->hw_lock);
return 0;
}
bool ssi_request_mgr_is_queue_runtime_suspend(struct ssi_drvdata *drvdata)
{
struct ssi_request_mgr_handle *request_mgr_handle =
drvdata->request_mgr_handle;
return request_mgr_handle->is_runtime_suspended;
}
