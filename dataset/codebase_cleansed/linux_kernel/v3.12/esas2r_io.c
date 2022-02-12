void esas2r_start_request(struct esas2r_adapter *a, struct esas2r_request *rq)
{
struct esas2r_target *t = NULL;
struct esas2r_request *startrq = rq;
unsigned long flags;
if (unlikely(a->flags & (AF_DEGRADED_MODE | AF_POWER_DOWN))) {
if (rq->vrq->scsi.function == VDA_FUNC_SCSI)
rq->req_stat = RS_SEL2;
else
rq->req_stat = RS_DEGRADED;
} else if (likely(rq->vrq->scsi.function == VDA_FUNC_SCSI)) {
t = a->targetdb + rq->target_id;
if (unlikely(t >= a->targetdb_end
|| !(t->flags & TF_USED))) {
rq->req_stat = RS_SEL;
} else {
rq->vrq->scsi.target_id = cpu_to_le16(t->virt_targ_id);
if (unlikely(t->target_state != TS_PRESENT
&& !(a->flags & AF_DISC_PENDING)))
rq->req_stat = RS_SEL;
}
}
if (unlikely(rq->req_stat != RS_PENDING)) {
esas2r_complete_request(a, rq);
return;
}
esas2r_trace("rq=%p", rq);
esas2r_trace("rq->vrq->scsi.handle=%x", rq->vrq->scsi.handle);
if (rq->vrq->scsi.function == VDA_FUNC_SCSI) {
esas2r_trace("rq->target_id=%d", rq->target_id);
esas2r_trace("rq->vrq->scsi.flags=%x", rq->vrq->scsi.flags);
}
spin_lock_irqsave(&a->queue_lock, flags);
if (likely(list_empty(&a->defer_list) &&
!(a->flags &
(AF_CHPRST_PENDING | AF_FLASHING | AF_DISC_PENDING))))
esas2r_local_start_request(a, startrq);
else
list_add_tail(&startrq->req_list, &a->defer_list);
spin_unlock_irqrestore(&a->queue_lock, flags);
}
void esas2r_local_start_request(struct esas2r_adapter *a,
struct esas2r_request *rq)
{
esas2r_trace_enter();
esas2r_trace("rq=%p", rq);
esas2r_trace("rq->vrq:%p", rq->vrq);
esas2r_trace("rq->vrq_md->phys_addr:%x", rq->vrq_md->phys_addr);
if (unlikely(rq->vrq->scsi.function == VDA_FUNC_FLASH
&& rq->vrq->flash.sub_func == VDA_FLASH_COMMIT))
esas2r_lock_set_flags(&a->flags, AF_FLASHING);
list_add_tail(&rq->req_list, &a->active_list);
esas2r_start_vda_request(a, rq);
esas2r_trace_exit();
return;
}
void esas2r_start_vda_request(struct esas2r_adapter *a,
struct esas2r_request *rq)
{
struct esas2r_inbound_list_source_entry *element;
u32 dw;
rq->req_stat = RS_STARTED;
a->last_write++;
if (a->last_write >= a->list_size) {
a->last_write = 0;
if (a->flags & AF_COMM_LIST_TOGGLE)
esas2r_lock_clear_flags(&a->flags,
AF_COMM_LIST_TOGGLE);
else
esas2r_lock_set_flags(&a->flags, AF_COMM_LIST_TOGGLE);
}
element =
(struct esas2r_inbound_list_source_entry *)a->inbound_list_md.
virt_addr
+ a->last_write;
if (rq->vda_req_sz == RQ_SIZE_DEFAULT)
rq->vda_req_sz = (u16)(a->max_vdareq_size / sizeof(u32));
element->address = cpu_to_le64(rq->vrq_md->phys_addr);
element->length = cpu_to_le32(rq->vda_req_sz);
dw = a->last_write;
if (a->flags & AF_COMM_LIST_TOGGLE)
dw |= MU_ILW_TOGGLE;
esas2r_trace("rq->vrq->scsi.handle:%x", rq->vrq->scsi.handle);
esas2r_trace("dw:%x", dw);
esas2r_trace("rq->vda_req_sz:%x", rq->vda_req_sz);
esas2r_write_register_dword(a, MU_IN_LIST_WRITE, dw);
}
bool esas2r_build_sg_list_sge(struct esas2r_adapter *a,
struct esas2r_sg_context *sgc)
{
struct esas2r_request *rq = sgc->first_req;
union atto_vda_req *vrq = rq->vrq;
while (sgc->length) {
u32 rem = 0;
u64 addr;
u32 len;
len = (*sgc->get_phys_addr)(sgc, &addr);
if (unlikely(len == 0))
return false;
if (unlikely(len > sgc->length))
len = sgc->length;
another_entry:
if (len > SGE_LEN_MAX) {
rem = len - SGE_LEN_MAX;
len = SGE_LEN_MAX;
}
if (unlikely(sgc->sge.a64.curr > sgc->sge.a64.limit)) {
u8 sgelen;
struct esas2r_mem_desc *sgl;
sgl = esas2r_alloc_sgl(a);
if (unlikely(sgl == NULL))
return false;
sgelen = (u8)((u8 *)sgc->sge.a64.curr
- (u8 *)sgc->sge.a64.last);
memcpy(sgl->virt_addr, sgc->sge.a64.last, sgelen);
sgc->sge.a64.curr =
(struct atto_vda_sge *)((u8 *)sgl->virt_addr +
sgelen);
sgc->sge.a64.limit =
(struct atto_vda_sge *)((u8 *)sgl->virt_addr
+ sgl_page_size
- sizeof(struct
atto_vda_sge));
sgc->sge.a64.last->length = cpu_to_le32(
SGE_CHAIN | SGE_ADDR_64);
sgc->sge.a64.last->address =
cpu_to_le64(sgl->phys_addr);
if (sgc->sge.a64.chain) {
sgc->sge.a64.chain->length |=
cpu_to_le32(
((u8 *)(sgc->sge.a64.
last + 1)
- (u8 *)rq->sg_table->
virt_addr)
+ sizeof(struct atto_vda_sge) *
LOBIT(SGE_CHAIN_SZ));
} else {
vrq->scsi.chain_offset = (u8)
((u8 *)sgc->
sge.a64.last -
(u8 *)vrq);
rq->vda_req_sz =
(vrq->scsi.chain_offset +
sizeof(struct atto_vda_sge) +
3)
/ sizeof(u32);
}
sgc->sge.a64.chain = sgc->sge.a64.last;
list_add(&sgl->next_desc, &rq->sg_table_head);
}
sgc->sge.a64.last = sgc->sge.a64.curr;
sgc->sge.a64.curr->length = cpu_to_le32(SGE_ADDR_64 | len);
sgc->sge.a64.curr->address = cpu_to_le32(addr);
sgc->sge.a64.curr++;
sgc->cur_offset += len;
sgc->length -= len;
if (rem) {
addr += len;
len = rem;
rem = 0;
goto another_entry;
}
}
sgc->sge.a64.last->length |= cpu_to_le32(SGE_LAST);
if (sgc->sge.a64.chain) {
sgc->sge.a64.chain->length |= cpu_to_le32(
((u8 *)(sgc->sge.a64.curr) -
(u8 *)rq->sg_table->virt_addr));
} else {
u16 reqsize;
reqsize =
((u16)((u8 *)sgc->sge.a64.last - (u8 *)vrq)
+ sizeof(struct atto_vda_sge) + 3) / sizeof(u32);
if (reqsize > rq->vda_req_sz)
rq->vda_req_sz = reqsize;
}
return true;
}
static bool esas2r_build_prd_iblk(struct esas2r_adapter *a,
struct esas2r_sg_context *sgc)
{
struct esas2r_request *rq = sgc->first_req;
u64 addr;
u32 len;
struct esas2r_mem_desc *sgl;
u32 numchain = 1;
u32 rem = 0;
while (sgc->length) {
len = (*sgc->get_phys_addr)(sgc, &addr);
if (unlikely(len == 0))
return false;
if (unlikely(len > sgc->length))
len = sgc->length;
another_entry:
if (len > PRD_LEN_MAX) {
rem = len - PRD_LEN_MAX;
len = PRD_LEN_MAX;
}
if (sgc->sge.prd.sge_cnt == 0) {
if (len == sgc->length) {
sgc->sge.prd.curr->ctl_len = cpu_to_le32(
PRD_DATA | len);
sgc->sge.prd.curr->address = cpu_to_le64(addr);
sgc->cur_offset += len;
sgc->length -= len;
numchain = 0;
break;
}
if (sgc->sge.prd.chain) {
sgc->sge.prd.chain->ctl_len |= cpu_to_le32(
sgc->sge.prd.sgl_max_cnt);
}
sgl = esas2r_alloc_sgl(a);
if (unlikely(sgl == NULL))
return false;
list_add(&sgl->next_desc, &rq->sg_table_head);
sgc->sge.prd.chain = sgc->sge.prd.curr;
sgc->sge.prd.chain->ctl_len = cpu_to_le32(PRD_CHAIN);
sgc->sge.prd.chain->address =
cpu_to_le64(sgl->phys_addr);
sgc->sge.prd.curr =
(struct atto_physical_region_description *)sgl
->
virt_addr;
sgc->sge.prd.sge_cnt = sgc->sge.prd.sgl_max_cnt - 1;
}
sgc->sge.prd.sge_cnt--;
sgc->sge.prd.curr->ctl_len = cpu_to_le32(PRD_DATA | len);
sgc->sge.prd.curr->address = cpu_to_le64(addr);
sgc->sge.prd.curr++;
sgc->cur_offset += len;
sgc->length -= len;
if (rem) {
addr += len;
len = rem;
rem = 0;
goto another_entry;
}
}
if (!list_empty(&rq->sg_table_head)) {
if (sgc->sge.prd.chain) {
sgc->sge.prd.chain->ctl_len |=
cpu_to_le32(sgc->sge.prd.sgl_max_cnt
- sgc->sge.prd.sge_cnt
- numchain);
}
}
return true;
}
bool esas2r_build_sg_list_prd(struct esas2r_adapter *a,
struct esas2r_sg_context *sgc)
{
struct esas2r_request *rq = sgc->first_req;
u32 len = sgc->length;
struct esas2r_target *t = a->targetdb + rq->target_id;
u8 is_i_o = 0;
u16 reqsize;
struct atto_physical_region_description *curr_iblk_chn;
u8 *cdb = (u8 *)&rq->vrq->scsi.cdb[0];
if (rq->vrq->scsi.function == VDA_FUNC_SCSI
&& t->target_state == TS_PRESENT
&& !(t->flags & TF_PASS_THRU)) {
u32 lbalo = 0;
switch (rq->vrq->scsi.cdb[0]) {
case READ_16:
case WRITE_16:
{
lbalo =
MAKEDWORD(MAKEWORD(cdb[9],
cdb[8]),
MAKEWORD(cdb[7],
cdb[6]));
is_i_o = 1;
break;
}
case READ_12:
case WRITE_12:
case READ_10:
case WRITE_10:
{
lbalo =
MAKEDWORD(MAKEWORD(cdb[5],
cdb[4]),
MAKEWORD(cdb[3],
cdb[2]));
is_i_o = 1;
break;
}
case READ_6:
case WRITE_6:
{
lbalo =
MAKEDWORD(MAKEWORD(cdb[3],
cdb[2]),
MAKEWORD(cdb[1] & 0x1F,
0));
is_i_o = 1;
break;
}
default:
break;
}
if (is_i_o) {
u32 startlba;
rq->vrq->scsi.iblk_cnt_prd = 0;
startlba = t->inter_block - (lbalo & (t->inter_block -
1));
sgc->length = startlba * t->block_size;
if ((lbalo & (t->inter_block - 1)) == 0)
rq->flags |= RF_1ST_IBLK_BASE;
if (sgc->length > len)
sgc->length = len;
} else {
sgc->length = len;
}
} else {
sgc->length = len;
}
curr_iblk_chn =
(struct atto_physical_region_description *)sgc->sge.a64.curr;
sgc->sge.prd.sgl_max_cnt = sgl_page_size /
sizeof(struct
atto_physical_region_description);
while (len) {
sgc->sge.prd.sge_cnt = 0;
sgc->sge.prd.chain = NULL;
sgc->sge.prd.curr = curr_iblk_chn;
len -= sgc->length;
if (unlikely(!esas2r_build_prd_iblk(a, sgc)))
return false;
curr_iblk_chn++;
if (is_i_o) {
rq->vrq->scsi.iblk_cnt_prd++;
if (len > t->inter_byte)
sgc->length = t->inter_byte;
else
sgc->length = len;
}
}
reqsize = ((u16)((u8 *)curr_iblk_chn - (u8 *)rq->vrq))
/ sizeof(u32);
if (reqsize > rq->vda_req_sz)
rq->vda_req_sz = reqsize;
return true;
}
static void esas2r_handle_pending_reset(struct esas2r_adapter *a, u32 currtime)
{
u32 delta = currtime - a->chip_init_time;
if (delta <= ESAS2R_CHPRST_WAIT_TIME) {
} else if (delta >= ESAS2R_CHPRST_TIME) {
esas2r_local_reset_adapter(a);
} else {
u32 doorbell;
doorbell = esas2r_read_register_dword(a, MU_DOORBELL_OUT);
if (doorbell == 0xFFFFFFFF || !(doorbell & DRBL_FORCE_INT)) {
esas2r_force_interrupt(a);
} else {
u32 ver = (doorbell & DRBL_FW_VER_MSK);
esas2r_write_register_dword(a, MU_DOORBELL_OUT,
doorbell);
if (ver == DRBL_FW_VER_0) {
esas2r_lock_set_flags(&a->flags,
AF_CHPRST_DETECTED);
esas2r_lock_set_flags(&a->flags,
AF_LEGACY_SGE_MODE);
a->max_vdareq_size = 128;
a->build_sgl = esas2r_build_sg_list_sge;
} else if (ver == DRBL_FW_VER_1) {
esas2r_lock_set_flags(&a->flags,
AF_CHPRST_DETECTED);
esas2r_lock_clear_flags(&a->flags,
AF_LEGACY_SGE_MODE);
a->max_vdareq_size = 1024;
a->build_sgl = esas2r_build_sg_list_prd;
} else {
esas2r_local_reset_adapter(a);
}
}
}
}
void esas2r_timer_tick(struct esas2r_adapter *a)
{
u32 currtime = jiffies_to_msecs(jiffies);
u32 deltatime = currtime - a->last_tick_time;
a->last_tick_time = currtime;
if (a->chip_uptime
&& !(a->flags & (AF_CHPRST_PENDING | AF_DISC_PENDING))) {
if (deltatime >= a->chip_uptime)
a->chip_uptime = 0;
else
a->chip_uptime -= deltatime;
}
if (a->flags & AF_CHPRST_PENDING) {
if (!(a->flags & AF_CHPRST_NEEDED)
&& !(a->flags & AF_CHPRST_DETECTED))
esas2r_handle_pending_reset(a, currtime);
} else {
if (a->flags & AF_DISC_PENDING)
esas2r_disc_check_complete(a);
if (a->flags & AF_HEARTBEAT_ENB) {
if (a->flags & AF_HEARTBEAT) {
if ((currtime - a->heartbeat_time) >=
ESAS2R_HEARTBEAT_TIME) {
esas2r_lock_clear_flags(&a->flags,
AF_HEARTBEAT);
esas2r_hdebug("heartbeat failed");
esas2r_log(ESAS2R_LOG_CRIT,
"heartbeat failed");
esas2r_bugon();
esas2r_local_reset_adapter(a);
}
} else {
esas2r_lock_set_flags(&a->flags, AF_HEARTBEAT);
a->heartbeat_time = currtime;
esas2r_force_interrupt(a);
}
}
}
if (atomic_read(&a->disable_cnt) == 0)
esas2r_do_deferred_processes(a);
}
bool esas2r_send_task_mgmt(struct esas2r_adapter *a,
struct esas2r_request *rqaux, u8 task_mgt_func)
{
u16 targetid = rqaux->target_id;
u8 lun = (u8)le32_to_cpu(rqaux->vrq->scsi.flags);
bool ret = false;
struct esas2r_request *rq;
struct list_head *next, *element;
unsigned long flags;
LIST_HEAD(comp_list);
esas2r_trace_enter();
esas2r_trace("rqaux:%p", rqaux);
esas2r_trace("task_mgt_func:%x", task_mgt_func);
spin_lock_irqsave(&a->queue_lock, flags);
list_for_each_safe(element, next, &a->defer_list) {
rq = list_entry(element, struct esas2r_request, req_list);
if (rq->vrq->scsi.function == VDA_FUNC_SCSI
&& rq->target_id == targetid
&& (((u8)le32_to_cpu(rq->vrq->scsi.flags)) == lun
|| task_mgt_func == 0x20)) {
if (rq->req_stat == RS_PENDING) {
if (esas2r_ioreq_aborted(a, rq, RS_ABORTED))
list_add_tail(&rq->comp_list,
&comp_list);
}
}
}
rqaux->sense_len = 0;
rqaux->vrq->scsi.length = 0;
rqaux->target_id = targetid;
rqaux->vrq->scsi.flags |= cpu_to_le32(lun);
memset(rqaux->vrq->scsi.cdb, 0, sizeof(rqaux->vrq->scsi.cdb));
rqaux->vrq->scsi.flags |=
cpu_to_le16(task_mgt_func * LOBIT(FCP_CMND_TM_MASK));
if (a->flags & AF_FLASHING) {
rqaux->req_stat = RS_SUCCESS;
list_for_each_safe(element, next, &a->active_list) {
rq = list_entry(element, struct esas2r_request,
req_list);
if (rq->vrq->scsi.function == VDA_FUNC_SCSI
&& rq->target_id == targetid
&& (((u8)le32_to_cpu(rq->vrq->scsi.flags)) == lun
|| task_mgt_func == 0x20))
rqaux->req_stat = RS_BUSY;
}
ret = true;
}
spin_unlock_irqrestore(&a->queue_lock, flags);
if (!(a->flags & AF_FLASHING))
esas2r_start_request(a, rqaux);
esas2r_comp_list_drain(a, &comp_list);
if (atomic_read(&a->disable_cnt) == 0)
esas2r_do_deferred_processes(a);
esas2r_trace_exit();
return ret;
}
void esas2r_reset_bus(struct esas2r_adapter *a)
{
esas2r_log(ESAS2R_LOG_INFO, "performing a bus reset");
if (!(a->flags & AF_DEGRADED_MODE)
&& !(a->flags & (AF_CHPRST_PENDING | AF_DISC_PENDING))) {
esas2r_lock_set_flags(&a->flags, AF_BUSRST_NEEDED);
esas2r_lock_set_flags(&a->flags, AF_BUSRST_PENDING);
esas2r_lock_set_flags(&a->flags, AF_OS_RESET);
esas2r_schedule_tasklet(a);
}
}
bool esas2r_ioreq_aborted(struct esas2r_adapter *a, struct esas2r_request *rq,
u8 status)
{
esas2r_trace_enter();
esas2r_trace("rq:%p", rq);
list_del_init(&rq->req_list);
if (rq->timeout > RQ_MAX_TIMEOUT) {
rq->req_stat = RS_BUSY;
esas2r_trace_exit();
return true;
}
rq->req_stat = status;
esas2r_trace_exit();
return true;
}
