static void gru_load_kernel_context(struct gru_blade_state *bs, int blade_id)
{
struct gru_state *gru;
struct gru_thread_state *kgts;
void *vaddr;
int ctxnum, ncpus;
up_read(&bs->bs_kgts_sema);
down_write(&bs->bs_kgts_sema);
if (!bs->bs_kgts) {
do {
bs->bs_kgts = gru_alloc_gts(NULL, 0, 0, 0, 0, 0);
if (!IS_ERR(bs->bs_kgts))
break;
msleep(1);
} while (true);
bs->bs_kgts->ts_user_blade_id = blade_id;
}
kgts = bs->bs_kgts;
if (!kgts->ts_gru) {
STAT(load_kernel_context);
ncpus = uv_blade_nr_possible_cpus(blade_id);
kgts->ts_cbr_au_count = GRU_CB_COUNT_TO_AU(
GRU_NUM_KERNEL_CBR * ncpus + bs->bs_async_cbrs);
kgts->ts_dsr_au_count = GRU_DS_BYTES_TO_AU(
GRU_NUM_KERNEL_DSR_BYTES * ncpus +
bs->bs_async_dsr_bytes);
while (!gru_assign_gru_context(kgts)) {
msleep(1);
gru_steal_context(kgts);
}
gru_load_context(kgts);
gru = bs->bs_kgts->ts_gru;
vaddr = gru->gs_gru_base_vaddr;
ctxnum = kgts->ts_ctxnum;
bs->kernel_cb = get_gseg_base_address_cb(vaddr, ctxnum, 0);
bs->kernel_dsr = get_gseg_base_address_ds(vaddr, ctxnum, 0);
}
downgrade_write(&bs->bs_kgts_sema);
}
static int gru_free_kernel_contexts(void)
{
struct gru_blade_state *bs;
struct gru_thread_state *kgts;
int bid, ret = 0;
for (bid = 0; bid < GRU_MAX_BLADES; bid++) {
bs = gru_base[bid];
if (!bs)
continue;
if (down_write_trylock(&bs->bs_kgts_sema)) {
kgts = bs->bs_kgts;
if (kgts && kgts->ts_gru)
gru_unload_context(kgts, 0);
bs->bs_kgts = NULL;
up_write(&bs->bs_kgts_sema);
kfree(kgts);
} else {
ret++;
}
}
return ret;
}
static struct gru_blade_state *gru_lock_kernel_context(int blade_id)
{
struct gru_blade_state *bs;
int bid;
STAT(lock_kernel_context);
again:
bid = blade_id < 0 ? uv_numa_blade_id() : blade_id;
bs = gru_base[bid];
down_read(&bs->bs_kgts_sema);
if (blade_id < 0 && bid != uv_numa_blade_id()) {
up_read(&bs->bs_kgts_sema);
goto again;
}
if (!bs->bs_kgts || !bs->bs_kgts->ts_gru)
gru_load_kernel_context(bs, bid);
return bs;
}
static void gru_unlock_kernel_context(int blade_id)
{
struct gru_blade_state *bs;
bs = gru_base[blade_id];
up_read(&bs->bs_kgts_sema);
STAT(unlock_kernel_context);
}
static int gru_get_cpu_resources(int dsr_bytes, void **cb, void **dsr)
{
struct gru_blade_state *bs;
int lcpu;
BUG_ON(dsr_bytes > GRU_NUM_KERNEL_DSR_BYTES);
preempt_disable();
bs = gru_lock_kernel_context(-1);
lcpu = uv_blade_processor_id();
*cb = bs->kernel_cb + lcpu * GRU_HANDLE_STRIDE;
*dsr = bs->kernel_dsr + lcpu * GRU_NUM_KERNEL_DSR_BYTES;
return 0;
}
static void gru_free_cpu_resources(void *cb, void *dsr)
{
gru_unlock_kernel_context(uv_numa_blade_id());
preempt_enable();
}
unsigned long gru_reserve_async_resources(int blade_id, int cbrs, int dsr_bytes,
struct completion *cmp)
{
struct gru_blade_state *bs;
struct gru_thread_state *kgts;
int ret = 0;
bs = gru_base[blade_id];
down_write(&bs->bs_kgts_sema);
if (bs->bs_async_dsr_bytes + bs->bs_async_cbrs)
goto done;
bs->bs_async_dsr_bytes = dsr_bytes;
bs->bs_async_cbrs = cbrs;
bs->bs_async_wq = cmp;
kgts = bs->bs_kgts;
if (kgts && kgts->ts_gru)
gru_unload_context(kgts, 0);
ret = ASYNC_BID_TO_HAN(blade_id);
done:
up_write(&bs->bs_kgts_sema);
return ret;
}
void gru_release_async_resources(unsigned long han)
{
struct gru_blade_state *bs = ASYNC_HAN_TO_BS(han);
down_write(&bs->bs_kgts_sema);
bs->bs_async_dsr_bytes = 0;
bs->bs_async_cbrs = 0;
bs->bs_async_wq = NULL;
up_write(&bs->bs_kgts_sema);
}
void gru_wait_async_cbr(unsigned long han)
{
struct gru_blade_state *bs = ASYNC_HAN_TO_BS(han);
wait_for_completion(bs->bs_async_wq);
mb();
}
void gru_lock_async_resource(unsigned long han, void **cb, void **dsr)
{
struct gru_blade_state *bs = ASYNC_HAN_TO_BS(han);
int blade_id = ASYNC_HAN_TO_BID(han);
int ncpus;
gru_lock_kernel_context(blade_id);
ncpus = uv_blade_nr_possible_cpus(blade_id);
if (cb)
*cb = bs->kernel_cb + ncpus * GRU_HANDLE_STRIDE;
if (dsr)
*dsr = bs->kernel_dsr + ncpus * GRU_NUM_KERNEL_DSR_BYTES;
}
void gru_unlock_async_resource(unsigned long han)
{
int blade_id = ASYNC_HAN_TO_BID(han);
gru_unlock_kernel_context(blade_id);
}
int gru_get_cb_exception_detail(void *cb,
struct control_block_extended_exc_detail *excdet)
{
struct gru_control_block_extended *cbe;
struct gru_thread_state *kgts = NULL;
unsigned long off;
int cbrnum, bid;
for_each_possible_blade(bid) {
if (!gru_base[bid])
break;
kgts = gru_base[bid]->bs_kgts;
if (!kgts || !kgts->ts_gru)
continue;
off = cb - kgts->ts_gru->gs_gru_base_vaddr;
if (off < GRU_SIZE)
break;
kgts = NULL;
}
BUG_ON(!kgts);
cbrnum = thread_cbr_number(kgts, get_cb_number(cb));
cbe = get_cbe(GRUBASE(cb), cbrnum);
gru_flush_cache(cbe);
sync_core();
excdet->opc = cbe->opccpy;
excdet->exopc = cbe->exopccpy;
excdet->ecause = cbe->ecause;
excdet->exceptdet0 = cbe->idef1upd;
excdet->exceptdet1 = cbe->idef3upd;
gru_flush_cache(cbe);
return 0;
}
static char *gru_get_cb_exception_detail_str(int ret, void *cb,
char *buf, int size)
{
struct gru_control_block_status *gen = (void *)cb;
struct control_block_extended_exc_detail excdet;
if (ret > 0 && gen->istatus == CBS_EXCEPTION) {
gru_get_cb_exception_detail(cb, &excdet);
snprintf(buf, size,
"GRU:%d exception: cb %p, opc %d, exopc %d, ecause 0x%x,"
"excdet0 0x%lx, excdet1 0x%x", smp_processor_id(),
gen, excdet.opc, excdet.exopc, excdet.ecause,
excdet.exceptdet0, excdet.exceptdet1);
} else {
snprintf(buf, size, "No exception");
}
return buf;
}
static int gru_wait_idle_or_exception(struct gru_control_block_status *gen)
{
while (gen->istatus >= CBS_ACTIVE) {
cpu_relax();
barrier();
}
return gen->istatus;
}
static int gru_retry_exception(void *cb)
{
struct gru_control_block_status *gen = (void *)cb;
struct control_block_extended_exc_detail excdet;
int retry = EXCEPTION_RETRY_LIMIT;
while (1) {
if (gru_wait_idle_or_exception(gen) == CBS_IDLE)
return CBS_IDLE;
if (gru_get_cb_message_queue_substatus(cb))
return CBS_EXCEPTION;
gru_get_cb_exception_detail(cb, &excdet);
if ((excdet.ecause & ~EXCEPTION_RETRY_BITS) ||
(excdet.cbrexecstatus & CBR_EXS_ABORT_OCC))
break;
if (retry-- == 0)
break;
gen->icmd = 1;
gru_flush_cache(gen);
}
return CBS_EXCEPTION;
}
int gru_check_status_proc(void *cb)
{
struct gru_control_block_status *gen = (void *)cb;
int ret;
ret = gen->istatus;
if (ret == CBS_EXCEPTION)
ret = gru_retry_exception(cb);
rmb();
return ret;
}
int gru_wait_proc(void *cb)
{
struct gru_control_block_status *gen = (void *)cb;
int ret;
ret = gru_wait_idle_or_exception(gen);
if (ret == CBS_EXCEPTION)
ret = gru_retry_exception(cb);
rmb();
return ret;
}
static void gru_abort(int ret, void *cb, char *str)
{
char buf[GRU_EXC_STR_SIZE];
panic("GRU FATAL ERROR: %s - %s\n", str,
gru_get_cb_exception_detail_str(ret, cb, buf, sizeof(buf)));
}
void gru_wait_abort_proc(void *cb)
{
int ret;
ret = gru_wait_proc(cb);
if (ret)
gru_abort(ret, cb, "gru_wait_abort");
}
static inline int get_present2(void *p)
{
struct message_header *mhdr = p + GRU_CACHE_LINE_BYTES;
return mhdr->present;
}
static inline void restore_present2(void *p, int val)
{
struct message_header *mhdr = p + GRU_CACHE_LINE_BYTES;
mhdr->present = val;
}
int gru_create_message_queue(struct gru_message_queue_desc *mqd,
void *p, unsigned int bytes, int nasid, int vector, int apicid)
{
struct message_queue *mq = p;
unsigned int qlines;
qlines = bytes / GRU_CACHE_LINE_BYTES - 2;
memset(mq, 0, bytes);
mq->start = &mq->data;
mq->start2 = &mq->data + (qlines / 2 - 1) * GRU_CACHE_LINE_BYTES;
mq->next = &mq->data;
mq->limit = &mq->data + (qlines - 2) * GRU_CACHE_LINE_BYTES;
mq->qlines = qlines;
mq->hstatus[0] = 0;
mq->hstatus[1] = 1;
mq->head = gru_mesq_head(2, qlines / 2 + 1);
mqd->mq = mq;
mqd->mq_gpa = uv_gpa(mq);
mqd->qlines = qlines;
mqd->interrupt_pnode = nasid >> 1;
mqd->interrupt_vector = vector;
mqd->interrupt_apicid = apicid;
return 0;
}
static int send_noop_message(void *cb, struct gru_message_queue_desc *mqd,
void *mesg)
{
const struct message_header noop_header = {
.present = MQS_NOOP, .lines = 1};
unsigned long m;
int substatus, ret;
struct message_header save_mhdr, *mhdr = mesg;
STAT(mesq_noop);
save_mhdr = *mhdr;
*mhdr = noop_header;
gru_mesq(cb, mqd->mq_gpa, gru_get_tri(mhdr), 1, IMA);
ret = gru_wait(cb);
if (ret) {
substatus = gru_get_cb_message_queue_substatus(cb);
switch (substatus) {
case CBSS_NO_ERROR:
STAT(mesq_noop_unexpected_error);
ret = MQE_UNEXPECTED_CB_ERR;
break;
case CBSS_LB_OVERFLOWED:
STAT(mesq_noop_lb_overflow);
ret = MQE_CONGESTION;
break;
case CBSS_QLIMIT_REACHED:
STAT(mesq_noop_qlimit_reached);
ret = 0;
break;
case CBSS_AMO_NACKED:
STAT(mesq_noop_amo_nacked);
ret = MQE_CONGESTION;
break;
case CBSS_PUT_NACKED:
STAT(mesq_noop_put_nacked);
m = mqd->mq_gpa + (gru_get_amo_value_head(cb) << 6);
gru_vstore(cb, m, gru_get_tri(mesg), XTYPE_CL, 1, 1,
IMA);
if (gru_wait(cb) == CBS_IDLE)
ret = MQIE_AGAIN;
else
ret = MQE_UNEXPECTED_CB_ERR;
break;
case CBSS_PAGE_OVERFLOW:
STAT(mesq_noop_page_overflow);
default:
BUG();
}
}
*mhdr = save_mhdr;
return ret;
}
static int send_message_queue_full(void *cb, struct gru_message_queue_desc *mqd,
void *mesg, int lines)
{
union gru_mesqhead mqh;
unsigned int limit, head;
unsigned long avalue;
int half, qlines;
avalue = gru_get_amo_value(cb);
head = gru_get_amo_value_head(cb);
limit = gru_get_amo_value_limit(cb);
qlines = mqd->qlines;
half = (limit != qlines);
if (half)
mqh = gru_mesq_head(qlines / 2 + 1, qlines);
else
mqh = gru_mesq_head(2, qlines / 2 + 1);
gru_gamir(cb, EOP_IR_CLR, HSTATUS(mqd->mq_gpa, half), XTYPE_DW, IMA);
if (gru_wait(cb) != CBS_IDLE)
goto cberr;
if (!gru_get_amo_value(cb)) {
STAT(mesq_qf_locked);
return MQE_QUEUE_FULL;
}
if (head != limit) {
if (send_noop_message(cb, mqd, mesg)) {
gru_gamir(cb, EOP_IR_INC, HSTATUS(mqd->mq_gpa, half),
XTYPE_DW, IMA);
if (gru_wait(cb) != CBS_IDLE)
goto cberr;
STAT(mesq_qf_noop_not_full);
return MQIE_AGAIN;
}
avalue++;
}
gru_gamer(cb, EOP_ERR_CSWAP, mqd->mq_gpa, XTYPE_DW, mqh.val, avalue,
IMA);
if (gru_wait(cb) != CBS_IDLE)
goto cberr;
if (gru_get_amo_value(cb) != avalue) {
STAT(mesq_qf_switch_head_failed);
gru_gamir(cb, EOP_IR_INC, HSTATUS(mqd->mq_gpa, half), XTYPE_DW,
IMA);
if (gru_wait(cb) != CBS_IDLE)
goto cberr;
}
return MQIE_AGAIN;
cberr:
STAT(mesq_qf_unexpected_error);
return MQE_UNEXPECTED_CB_ERR;
}
static int send_message_put_nacked(void *cb, struct gru_message_queue_desc *mqd,
void *mesg, int lines)
{
unsigned long m, *val = mesg, gpa, save;
int ret;
m = mqd->mq_gpa + (gru_get_amo_value_head(cb) << 6);
if (lines == 2) {
gru_vset(cb, m, 0, XTYPE_CL, lines, 1, IMA);
if (gru_wait(cb) != CBS_IDLE)
return MQE_UNEXPECTED_CB_ERR;
}
gru_vstore(cb, m, gru_get_tri(mesg), XTYPE_CL, lines, 1, IMA);
if (gru_wait(cb) != CBS_IDLE)
return MQE_UNEXPECTED_CB_ERR;
if (!mqd->interrupt_vector)
return MQE_OK;
gpa = uv_global_gru_mmr_address(mqd->interrupt_pnode, UVH_IPI_INT);
save = *val;
*val = uv_hub_ipi_value(mqd->interrupt_apicid, mqd->interrupt_vector,
dest_Fixed);
gru_vstore_phys(cb, gpa, gru_get_tri(mesg), IAA_REGISTER, IMA);
ret = gru_wait(cb);
*val = save;
if (ret != CBS_IDLE)
return MQE_UNEXPECTED_CB_ERR;
return MQE_OK;
}
static int send_message_failure(void *cb, struct gru_message_queue_desc *mqd,
void *mesg, int lines)
{
int substatus, ret = 0;
substatus = gru_get_cb_message_queue_substatus(cb);
switch (substatus) {
case CBSS_NO_ERROR:
STAT(mesq_send_unexpected_error);
ret = MQE_UNEXPECTED_CB_ERR;
break;
case CBSS_LB_OVERFLOWED:
STAT(mesq_send_lb_overflow);
ret = MQE_CONGESTION;
break;
case CBSS_QLIMIT_REACHED:
STAT(mesq_send_qlimit_reached);
ret = send_message_queue_full(cb, mqd, mesg, lines);
break;
case CBSS_AMO_NACKED:
STAT(mesq_send_amo_nacked);
ret = MQE_CONGESTION;
break;
case CBSS_PUT_NACKED:
STAT(mesq_send_put_nacked);
ret = send_message_put_nacked(cb, mqd, mesg, lines);
break;
case CBSS_PAGE_OVERFLOW:
STAT(mesq_page_overflow);
default:
BUG();
}
return ret;
}
int gru_send_message_gpa(struct gru_message_queue_desc *mqd, void *mesg,
unsigned int bytes)
{
struct message_header *mhdr;
void *cb;
void *dsr;
int istatus, clines, ret;
STAT(mesq_send);
BUG_ON(bytes < sizeof(int) || bytes > 2 * GRU_CACHE_LINE_BYTES);
clines = DIV_ROUND_UP(bytes, GRU_CACHE_LINE_BYTES);
if (gru_get_cpu_resources(bytes, &cb, &dsr))
return MQE_BUG_NO_RESOURCES;
memcpy(dsr, mesg, bytes);
mhdr = dsr;
mhdr->present = MQS_FULL;
mhdr->lines = clines;
if (clines == 2) {
mhdr->present2 = get_present2(mhdr);
restore_present2(mhdr, MQS_FULL);
}
do {
ret = MQE_OK;
gru_mesq(cb, mqd->mq_gpa, gru_get_tri(mhdr), clines, IMA);
istatus = gru_wait(cb);
if (istatus != CBS_IDLE)
ret = send_message_failure(cb, mqd, dsr, clines);
} while (ret == MQIE_AGAIN);
gru_free_cpu_resources(cb, dsr);
if (ret)
STAT(mesq_send_failed);
return ret;
}
void gru_free_message(struct gru_message_queue_desc *mqd, void *mesg)
{
struct message_queue *mq = mqd->mq;
struct message_header *mhdr = mq->next;
void *next, *pnext;
int half = -1;
int lines = mhdr->lines;
if (lines == 2)
restore_present2(mhdr, MQS_EMPTY);
mhdr->present = MQS_EMPTY;
pnext = mq->next;
next = pnext + GRU_CACHE_LINE_BYTES * lines;
if (next == mq->limit) {
next = mq->start;
half = 1;
} else if (pnext < mq->start2 && next >= mq->start2) {
half = 0;
}
if (half >= 0)
mq->hstatus[half] = 1;
mq->next = next;
}
void *gru_get_next_message(struct gru_message_queue_desc *mqd)
{
struct message_queue *mq = mqd->mq;
struct message_header *mhdr = mq->next;
int present = mhdr->present;
while (present == MQS_NOOP) {
gru_free_message(mqd, mhdr);
mhdr = mq->next;
present = mhdr->present;
}
if (present == MQS_FULL && mhdr->lines == 2 &&
get_present2(mhdr) == MQS_EMPTY)
present = MQS_EMPTY;
if (!present) {
STAT(mesq_receive_none);
return NULL;
}
if (mhdr->lines == 2)
restore_present2(mhdr, mhdr->present2);
STAT(mesq_receive);
return mhdr;
}
int gru_read_gpa(unsigned long *value, unsigned long gpa)
{
void *cb;
void *dsr;
int ret, iaa;
STAT(read_gpa);
if (gru_get_cpu_resources(GRU_NUM_KERNEL_DSR_BYTES, &cb, &dsr))
return MQE_BUG_NO_RESOURCES;
iaa = gpa >> 62;
gru_vload_phys(cb, gpa, gru_get_tri(dsr), iaa, IMA);
ret = gru_wait(cb);
if (ret == CBS_IDLE)
*value = *(unsigned long *)dsr;
gru_free_cpu_resources(cb, dsr);
return ret;
}
int gru_copy_gpa(unsigned long dest_gpa, unsigned long src_gpa,
unsigned int bytes)
{
void *cb;
void *dsr;
int ret;
STAT(copy_gpa);
if (gru_get_cpu_resources(GRU_NUM_KERNEL_DSR_BYTES, &cb, &dsr))
return MQE_BUG_NO_RESOURCES;
gru_bcopy(cb, src_gpa, dest_gpa, gru_get_tri(dsr),
XTYPE_B, bytes, GRU_NUM_KERNEL_DSR_CL, IMA);
ret = gru_wait(cb);
gru_free_cpu_resources(cb, dsr);
return ret;
}
static int quicktest0(unsigned long arg)
{
unsigned long word0;
unsigned long word1;
void *cb;
void *dsr;
unsigned long *p;
int ret = -EIO;
if (gru_get_cpu_resources(GRU_CACHE_LINE_BYTES, &cb, &dsr))
return MQE_BUG_NO_RESOURCES;
p = dsr;
word0 = MAGIC;
word1 = 0;
gru_vload(cb, uv_gpa(&word0), gru_get_tri(dsr), XTYPE_DW, 1, 1, IMA);
if (gru_wait(cb) != CBS_IDLE) {
printk(KERN_DEBUG "GRU:%d quicktest0: CBR failure 1\n", smp_processor_id());
goto done;
}
if (*p != MAGIC) {
printk(KERN_DEBUG "GRU:%d quicktest0 bad magic 0x%lx\n", smp_processor_id(), *p);
goto done;
}
gru_vstore(cb, uv_gpa(&word1), gru_get_tri(dsr), XTYPE_DW, 1, 1, IMA);
if (gru_wait(cb) != CBS_IDLE) {
printk(KERN_DEBUG "GRU:%d quicktest0: CBR failure 2\n", smp_processor_id());
goto done;
}
if (word0 != word1 || word1 != MAGIC) {
printk(KERN_DEBUG
"GRU:%d quicktest0 err: found 0x%lx, expected 0x%lx\n",
smp_processor_id(), word1, MAGIC);
goto done;
}
ret = 0;
done:
gru_free_cpu_resources(cb, dsr);
return ret;
}
static int quicktest1(unsigned long arg)
{
struct gru_message_queue_desc mqd;
void *p, *mq;
int i, ret = -EIO;
char mes[GRU_CACHE_LINE_BYTES], *m;
p = kmalloc(4096, 0);
if (p == NULL)
return -ENOMEM;
mq = ALIGNUP(p, 1024);
memset(mes, 0xee, sizeof(mes));
gru_create_message_queue(&mqd, mq, 8 * GRU_CACHE_LINE_BYTES, 0, 0, 0);
for (i = 0; i < 6; i++) {
mes[8] = i;
do {
ret = gru_send_message_gpa(&mqd, mes, sizeof(mes));
} while (ret == MQE_CONGESTION);
if (ret)
break;
}
if (ret != MQE_QUEUE_FULL || i != 4) {
printk(KERN_DEBUG "GRU:%d quicktest1: unexpect status %d, i %d\n",
smp_processor_id(), ret, i);
goto done;
}
for (i = 0; i < 6; i++) {
m = gru_get_next_message(&mqd);
if (!m || m[8] != i)
break;
gru_free_message(&mqd, m);
}
if (i != 4) {
printk(KERN_DEBUG "GRU:%d quicktest2: bad message, i %d, m %p, m8 %d\n",
smp_processor_id(), i, m, m ? m[8] : -1);
goto done;
}
ret = 0;
done:
kfree(p);
return ret;
}
static int quicktest2(unsigned long arg)
{
static DECLARE_COMPLETION(cmp);
unsigned long han;
int blade_id = 0;
int numcb = 4;
int ret = 0;
unsigned long *buf;
void *cb0, *cb;
struct gru_control_block_status *gen;
int i, k, istatus, bytes;
bytes = numcb * 4 * 8;
buf = kmalloc(bytes, GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = -EBUSY;
han = gru_reserve_async_resources(blade_id, numcb, 0, &cmp);
if (!han)
goto done;
gru_lock_async_resource(han, &cb0, NULL);
memset(buf, 0xee, bytes);
for (i = 0; i < numcb; i++)
gru_vset(cb0 + i * GRU_HANDLE_STRIDE, uv_gpa(&buf[i * 4]), 0,
XTYPE_DW, 4, 1, IMA_INTERRUPT);
ret = 0;
k = numcb;
do {
gru_wait_async_cbr(han);
for (i = 0; i < numcb; i++) {
cb = cb0 + i * GRU_HANDLE_STRIDE;
istatus = gru_check_status(cb);
if (istatus != CBS_ACTIVE && istatus != CBS_CALL_OS)
break;
}
if (i == numcb)
continue;
if (istatus != CBS_IDLE) {
printk(KERN_DEBUG "GRU:%d quicktest2: cb %d, exception\n", smp_processor_id(), i);
ret = -EFAULT;
} else if (buf[4 * i] || buf[4 * i + 1] || buf[4 * i + 2] ||
buf[4 * i + 3]) {
printk(KERN_DEBUG "GRU:%d quicktest2:cb %d, buf 0x%lx, 0x%lx, 0x%lx, 0x%lx\n",
smp_processor_id(), i, buf[4 * i], buf[4 * i + 1], buf[4 * i + 2], buf[4 * i + 3]);
ret = -EIO;
}
k--;
gen = cb;
gen->istatus = CBS_CALL_OS;
} while (k);
BUG_ON(cmp.done);
gru_unlock_async_resource(han);
gru_release_async_resources(han);
done:
kfree(buf);
return ret;
}
static int quicktest3(unsigned long arg)
{
char buf1[BUFSIZE], buf2[BUFSIZE];
int ret = 0;
memset(buf2, 0, sizeof(buf2));
memset(buf1, get_cycles() & 255, sizeof(buf1));
gru_copy_gpa(uv_gpa(buf2), uv_gpa(buf1), BUFSIZE);
if (memcmp(buf1, buf2, BUFSIZE)) {
printk(KERN_DEBUG "GRU:%d quicktest3 error\n", smp_processor_id());
ret = -EIO;
}
return ret;
}
int gru_ktest(unsigned long arg)
{
int ret = -EINVAL;
switch (arg & 0xff) {
case 0:
ret = quicktest0(arg);
break;
case 1:
ret = quicktest1(arg);
break;
case 2:
ret = quicktest2(arg);
break;
case 3:
ret = quicktest3(arg);
break;
case 99:
ret = gru_free_kernel_contexts();
break;
}
return ret;
}
int gru_kservices_init(void)
{
return 0;
}
void gru_kservices_exit(void)
{
if (gru_free_kernel_contexts())
BUG();
}
