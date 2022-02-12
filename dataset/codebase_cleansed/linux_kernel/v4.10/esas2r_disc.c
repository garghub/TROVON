void esas2r_disc_initialize(struct esas2r_adapter *a)
{
struct esas2r_sas_nvram *nvr = a->nvram;
esas2r_trace_enter();
clear_bit(AF_DISC_IN_PROG, &a->flags);
clear_bit(AF2_DEV_SCAN, &a->flags2);
clear_bit(AF2_DEV_CNT_OK, &a->flags2);
a->disc_start_time = jiffies_to_msecs(jiffies);
a->disc_wait_time = nvr->dev_wait_time * 1000;
a->disc_wait_cnt = nvr->dev_wait_count;
if (a->disc_wait_cnt > ESAS2R_MAX_TARGETS)
a->disc_wait_cnt = ESAS2R_MAX_TARGETS;
esas2r_hdebug("starting discovery...");
a->general_req.interrupt_cx = NULL;
if (test_bit(AF_CHPRST_DETECTED, &a->flags) ||
test_bit(AF_POWER_MGT, &a->flags)) {
if (a->prev_dev_cnt == 0) {
a->disc_wait_time = 0;
} else {
a->disc_wait_cnt = a->prev_dev_cnt;
if (a->disc_wait_time < 15000)
a->disc_wait_time = 15000;
}
}
esas2r_trace("disc wait count: %d", a->disc_wait_cnt);
esas2r_trace("disc wait time: %d", a->disc_wait_time);
if (a->disc_wait_time == 0)
esas2r_disc_check_complete(a);
esas2r_trace_exit();
}
void esas2r_disc_start_waiting(struct esas2r_adapter *a)
{
unsigned long flags;
spin_lock_irqsave(&a->mem_lock, flags);
if (a->disc_ctx.disc_evt)
esas2r_disc_start_port(a);
spin_unlock_irqrestore(&a->mem_lock, flags);
}
void esas2r_disc_check_for_work(struct esas2r_adapter *a)
{
struct esas2r_request *rq = &a->general_req;
esas2r_polled_interrupt(a);
esas2r_disc_start_waiting(a);
if (rq->interrupt_cx == NULL)
return;
if (rq->req_stat == RS_STARTED
&& rq->timeout <= RQ_MAX_TIMEOUT) {
esas2r_wait_request(a, rq);
if (rq->req_stat == RS_TIMEOUT) {
esas2r_disc_abort(a, rq);
esas2r_local_reset_adapter(a);
return;
}
}
if (rq->req_stat == RS_PENDING
|| rq->req_stat == RS_STARTED)
return;
esas2r_disc_continue(a, rq);
}
void esas2r_disc_check_complete(struct esas2r_adapter *a)
{
unsigned long flags;
esas2r_trace_enter();
if (a->disc_wait_time) {
u32 currtime = jiffies_to_msecs(jiffies);
u32 time = currtime - a->disc_start_time;
if (time < a->disc_wait_time
&& (esas2r_targ_db_get_tgt_cnt(a) < a->disc_wait_cnt
|| a->disc_wait_cnt == 0)) {
if (time >= 3000
&& !test_and_set_bit(AF2_DEV_SCAN, &a->flags2)) {
spin_lock_irqsave(&a->mem_lock, flags);
esas2r_disc_queue_event(a, DCDE_DEV_SCAN);
spin_unlock_irqrestore(&a->mem_lock, flags);
}
esas2r_trace_exit();
return;
}
if (!test_and_set_bit(AF2_DEV_CNT_OK, &a->flags2))
a->disc_wait_time = time + 3000;
if (!test_and_set_bit(AF2_DEV_SCAN, &a->flags2)) {
spin_lock_irqsave(&a->mem_lock, flags);
esas2r_disc_queue_event(a, DCDE_DEV_SCAN);
spin_unlock_irqrestore(&a->mem_lock, flags);
esas2r_trace_exit();
return;
}
if (time < a->disc_wait_time) {
esas2r_trace_exit();
return;
}
} else {
if (!test_and_set_bit(AF2_DEV_SCAN, &a->flags2)) {
spin_lock_irqsave(&a->mem_lock, flags);
esas2r_disc_queue_event(a, DCDE_DEV_SCAN);
spin_unlock_irqrestore(&a->mem_lock, flags);
}
}
a->disc_wait_time = 0;
if (test_bit(AF_DISC_POLLED, &a->flags) &&
test_bit(AF_DISC_IN_PROG, &a->flags)) {
} else {
esas2r_disc_fix_curr_requests(a);
clear_bit(AF_DISC_PENDING, &a->flags);
set_bit(AF_PORT_CHANGE, &a->flags);
}
esas2r_trace_exit();
}
void esas2r_disc_queue_event(struct esas2r_adapter *a, u8 disc_evt)
{
struct esas2r_disc_context *dc = &a->disc_ctx;
esas2r_trace_enter();
esas2r_trace("disc_event: %d", disc_evt);
dc->disc_evt |= disc_evt;
if (!test_bit(AF_CHPRST_PENDING, &a->flags) &&
!test_bit(AF_DISC_POLLED, &a->flags))
esas2r_disc_start_port(a);
esas2r_trace_exit();
}
bool esas2r_disc_start_port(struct esas2r_adapter *a)
{
struct esas2r_request *rq = &a->general_req;
struct esas2r_disc_context *dc = &a->disc_ctx;
bool ret;
esas2r_trace_enter();
if (test_bit(AF_DISC_IN_PROG, &a->flags)) {
esas2r_trace_exit();
return false;
}
if (dc->disc_evt) {
if (test_bit(AF_DISC_POLLED, &a->flags)
&& a->disc_wait_time == 0) {
esas2r_trace_exit();
return false;
}
} else {
esas2r_hdebug("disc done");
set_bit(AF_PORT_CHANGE, &a->flags);
esas2r_trace_exit();
return false;
}
esas2r_trace("disc_evt: %d", dc->disc_evt);
set_bit(AF_DISC_IN_PROG, &a->flags);
dc->flags = 0;
if (test_bit(AF_DISC_POLLED, &a->flags))
dc->flags |= DCF_POLLED;
rq->interrupt_cx = dc;
rq->req_stat = RS_SUCCESS;
if (dc->disc_evt & DCDE_DEV_SCAN) {
dc->disc_evt &= ~DCDE_DEV_SCAN;
dc->flags |= DCF_DEV_SCAN;
dc->state = DCS_BLOCK_DEV_SCAN;
} else if (dc->disc_evt & DCDE_DEV_CHANGE) {
dc->disc_evt &= ~DCDE_DEV_CHANGE;
dc->flags |= DCF_DEV_CHANGE;
dc->state = DCS_DEV_RMV;
}
if (!test_bit(AF_DISC_POLLED, &a->flags))
ret = esas2r_disc_continue(a, rq);
else
ret = true;
esas2r_trace_exit();
return ret;
}
static bool esas2r_disc_continue(struct esas2r_adapter *a,
struct esas2r_request *rq)
{
struct esas2r_disc_context *dc =
(struct esas2r_disc_context *)rq->interrupt_cx;
bool rslt;
while (dc->flags & (DCF_DEV_CHANGE | DCF_DEV_SCAN)) {
rslt = false;
switch (dc->state) {
case DCS_DEV_RMV:
rslt = esas2r_disc_dev_remove(a, rq);
break;
case DCS_DEV_ADD:
rslt = esas2r_disc_dev_add(a, rq);
break;
case DCS_BLOCK_DEV_SCAN:
rslt = esas2r_disc_block_dev_scan(a, rq);
break;
case DCS_RAID_GRP_INFO:
rslt = esas2r_disc_raid_grp_info(a, rq);
break;
case DCS_PART_INFO:
rslt = esas2r_disc_part_info(a, rq);
break;
case DCS_PT_DEV_INFO:
rslt = esas2r_disc_passthru_dev_info(a, rq);
break;
case DCS_PT_DEV_ADDR:
rslt = esas2r_disc_passthru_dev_addr(a, rq);
break;
case DCS_DISC_DONE:
dc->flags &= ~(DCF_DEV_CHANGE | DCF_DEV_SCAN);
break;
default:
esas2r_bugon();
dc->state = DCS_DISC_DONE;
break;
}
if (rslt)
return true;
}
rq->interrupt_cx = NULL;
if (!test_bit(AF_DISC_PENDING, &a->flags))
esas2r_disc_fix_curr_requests(a);
clear_bit(AF_DISC_IN_PROG, &a->flags);
return esas2r_disc_start_port(a);
}
static bool esas2r_disc_start_request(struct esas2r_adapter *a,
struct esas2r_request *rq)
{
unsigned long flags;
if (rq->timeout < ESAS2R_DEFAULT_TMO)
rq->timeout = ESAS2R_DEFAULT_TMO;
rq->req_type = RT_DISC_REQ;
spin_lock_irqsave(&a->queue_lock, flags);
if (!test_bit(AF_CHPRST_PENDING, &a->flags) &&
!test_bit(AF_FLASHING, &a->flags))
esas2r_disc_local_start_request(a, rq);
else
list_add_tail(&rq->req_list, &a->defer_list);
spin_unlock_irqrestore(&a->queue_lock, flags);
return true;
}
void esas2r_disc_local_start_request(struct esas2r_adapter *a,
struct esas2r_request *rq)
{
esas2r_trace_enter();
list_add_tail(&rq->req_list, &a->active_list);
esas2r_start_vda_request(a, rq);
esas2r_trace_exit();
return;
}
static void esas2r_disc_abort(struct esas2r_adapter *a,
struct esas2r_request *rq)
{
struct esas2r_disc_context *dc =
(struct esas2r_disc_context *)rq->interrupt_cx;
esas2r_trace_enter();
dc->state = DCS_DISC_DONE;
esas2r_trace_exit();
}
static bool esas2r_disc_block_dev_scan(struct esas2r_adapter *a,
struct esas2r_request *rq)
{
struct esas2r_disc_context *dc =
(struct esas2r_disc_context *)rq->interrupt_cx;
bool rslt;
esas2r_trace_enter();
esas2r_rq_init_request(rq, a);
esas2r_build_mgt_req(a,
rq,
VDAMGT_DEV_SCAN,
0,
0,
0,
NULL);
rq->comp_cb = esas2r_disc_block_dev_scan_cb;
rq->timeout = 30000;
rq->interrupt_cx = dc;
rslt = esas2r_disc_start_request(a, rq);
esas2r_trace_exit();
return rslt;
}
static void esas2r_disc_block_dev_scan_cb(struct esas2r_adapter *a,
struct esas2r_request *rq)
{
struct esas2r_disc_context *dc =
(struct esas2r_disc_context *)rq->interrupt_cx;
unsigned long flags;
esas2r_trace_enter();
spin_lock_irqsave(&a->mem_lock, flags);
if (rq->req_stat == RS_SUCCESS)
dc->scan_gen = rq->func_rsp.mgt_rsp.scan_generation;
dc->state = DCS_RAID_GRP_INFO;
dc->raid_grp_ix = 0;
esas2r_rq_destroy_request(rq, a);
if (!(dc->flags & DCF_POLLED))
esas2r_disc_continue(a, rq);
spin_unlock_irqrestore(&a->mem_lock, flags);
esas2r_trace_exit();
}
static bool esas2r_disc_raid_grp_info(struct esas2r_adapter *a,
struct esas2r_request *rq)
{
struct esas2r_disc_context *dc =
(struct esas2r_disc_context *)rq->interrupt_cx;
bool rslt;
struct atto_vda_grp_info *grpinfo;
esas2r_trace_enter();
esas2r_trace("raid_group_idx: %d", dc->raid_grp_ix);
if (dc->raid_grp_ix >= VDA_MAX_RAID_GROUPS) {
dc->state = DCS_DISC_DONE;
esas2r_trace_exit();
return false;
}
esas2r_rq_init_request(rq, a);
grpinfo = &rq->vda_rsp_data->mgt_data.data.grp_info;
memset(grpinfo, 0, sizeof(struct atto_vda_grp_info));
esas2r_build_mgt_req(a,
rq,
VDAMGT_GRP_INFO,
dc->scan_gen,
0,
sizeof(struct atto_vda_grp_info),
NULL);
grpinfo->grp_index = dc->raid_grp_ix;
rq->comp_cb = esas2r_disc_raid_grp_info_cb;
rq->interrupt_cx = dc;
rslt = esas2r_disc_start_request(a, rq);
esas2r_trace_exit();
return rslt;
}
static void esas2r_disc_raid_grp_info_cb(struct esas2r_adapter *a,
struct esas2r_request *rq)
{
struct esas2r_disc_context *dc =
(struct esas2r_disc_context *)rq->interrupt_cx;
unsigned long flags;
struct atto_vda_grp_info *grpinfo;
esas2r_trace_enter();
spin_lock_irqsave(&a->mem_lock, flags);
if (rq->req_stat == RS_SCAN_GEN) {
dc->scan_gen = rq->func_rsp.mgt_rsp.scan_generation;
dc->raid_grp_ix = 0;
goto done;
}
if (rq->req_stat == RS_SUCCESS) {
grpinfo = &rq->vda_rsp_data->mgt_data.data.grp_info;
if (grpinfo->status != VDA_GRP_STAT_ONLINE
&& grpinfo->status != VDA_GRP_STAT_DEGRADED) {
dc->raid_grp_ix++;
} else {
memcpy(&dc->raid_grp_name[0],
&grpinfo->grp_name[0],
sizeof(grpinfo->grp_name));
dc->interleave = le32_to_cpu(grpinfo->interleave);
dc->block_size = le32_to_cpu(grpinfo->block_size);
dc->state = DCS_PART_INFO;
dc->part_num = 0;
}
} else {
if (!(rq->req_stat == RS_GRP_INVALID)) {
esas2r_log(ESAS2R_LOG_WARN,
"A request for RAID group info failed - "
"returned with %x",
rq->req_stat);
}
dc->dev_ix = 0;
dc->state = DCS_PT_DEV_INFO;
}
done:
esas2r_rq_destroy_request(rq, a);
if (!(dc->flags & DCF_POLLED))
esas2r_disc_continue(a, rq);
spin_unlock_irqrestore(&a->mem_lock, flags);
esas2r_trace_exit();
}
static bool esas2r_disc_part_info(struct esas2r_adapter *a,
struct esas2r_request *rq)
{
struct esas2r_disc_context *dc =
(struct esas2r_disc_context *)rq->interrupt_cx;
bool rslt;
struct atto_vdapart_info *partinfo;
esas2r_trace_enter();
esas2r_trace("part_num: %d", dc->part_num);
if (dc->part_num >= VDA_MAX_PARTITIONS) {
dc->state = DCS_RAID_GRP_INFO;
dc->raid_grp_ix++;
esas2r_trace_exit();
return false;
}
esas2r_rq_init_request(rq, a);
partinfo = &rq->vda_rsp_data->mgt_data.data.part_info;
memset(partinfo, 0, sizeof(struct atto_vdapart_info));
esas2r_build_mgt_req(a,
rq,
VDAMGT_PART_INFO,
dc->scan_gen,
0,
sizeof(struct atto_vdapart_info),
NULL);
partinfo->part_no = dc->part_num;
memcpy(&partinfo->grp_name[0],
&dc->raid_grp_name[0],
sizeof(partinfo->grp_name));
rq->comp_cb = esas2r_disc_part_info_cb;
rq->interrupt_cx = dc;
rslt = esas2r_disc_start_request(a, rq);
esas2r_trace_exit();
return rslt;
}
static void esas2r_disc_part_info_cb(struct esas2r_adapter *a,
struct esas2r_request *rq)
{
struct esas2r_disc_context *dc =
(struct esas2r_disc_context *)rq->interrupt_cx;
unsigned long flags;
struct atto_vdapart_info *partinfo;
esas2r_trace_enter();
spin_lock_irqsave(&a->mem_lock, flags);
if (rq->req_stat == RS_SCAN_GEN) {
dc->scan_gen = rq->func_rsp.mgt_rsp.scan_generation;
dc->raid_grp_ix = 0;
dc->state = DCS_RAID_GRP_INFO;
} else if (rq->req_stat == RS_SUCCESS) {
partinfo = &rq->vda_rsp_data->mgt_data.data.part_info;
dc->part_num = partinfo->part_no;
dc->curr_virt_id = le16_to_cpu(partinfo->target_id);
esas2r_targ_db_add_raid(a, dc);
dc->part_num++;
} else {
if (!(rq->req_stat == RS_PART_LAST)) {
esas2r_log(ESAS2R_LOG_WARN,
"A request for RAID group partition info "
"failed - status:%d", rq->req_stat);
}
dc->state = DCS_RAID_GRP_INFO;
dc->raid_grp_ix++;
}
esas2r_rq_destroy_request(rq, a);
if (!(dc->flags & DCF_POLLED))
esas2r_disc_continue(a, rq);
spin_unlock_irqrestore(&a->mem_lock, flags);
esas2r_trace_exit();
}
static bool esas2r_disc_passthru_dev_info(struct esas2r_adapter *a,
struct esas2r_request *rq)
{
struct esas2r_disc_context *dc =
(struct esas2r_disc_context *)rq->interrupt_cx;
bool rslt;
struct atto_vda_devinfo *devinfo;
esas2r_trace_enter();
esas2r_trace("dev_ix: %d", dc->dev_ix);
esas2r_rq_init_request(rq, a);
devinfo = &rq->vda_rsp_data->mgt_data.data.dev_info;
memset(devinfo, 0, sizeof(struct atto_vda_devinfo));
esas2r_build_mgt_req(a,
rq,
VDAMGT_DEV_PT_INFO,
dc->scan_gen,
dc->dev_ix,
sizeof(struct atto_vda_devinfo),
NULL);
rq->comp_cb = esas2r_disc_passthru_dev_info_cb;
rq->interrupt_cx = dc;
rslt = esas2r_disc_start_request(a, rq);
esas2r_trace_exit();
return rslt;
}
static void esas2r_disc_passthru_dev_info_cb(struct esas2r_adapter *a,
struct esas2r_request *rq)
{
struct esas2r_disc_context *dc =
(struct esas2r_disc_context *)rq->interrupt_cx;
unsigned long flags;
struct atto_vda_devinfo *devinfo;
esas2r_trace_enter();
spin_lock_irqsave(&a->mem_lock, flags);
if (rq->req_stat == RS_SCAN_GEN) {
dc->scan_gen = rq->func_rsp.mgt_rsp.scan_generation;
dc->dev_ix = 0;
dc->state = DCS_PT_DEV_INFO;
} else if (rq->req_stat == RS_SUCCESS) {
devinfo = &rq->vda_rsp_data->mgt_data.data.dev_info;
dc->dev_ix = le16_to_cpu(rq->func_rsp.mgt_rsp.dev_index);
dc->curr_virt_id = le16_to_cpu(devinfo->target_id);
if (le16_to_cpu(devinfo->features) & VDADEVFEAT_PHYS_ID) {
dc->curr_phys_id =
le16_to_cpu(devinfo->phys_target_id);
dc->dev_addr_type = ATTO_GDA_AT_PORT;
dc->state = DCS_PT_DEV_ADDR;
esas2r_trace("curr_virt_id: %d", dc->curr_virt_id);
esas2r_trace("curr_phys_id: %d", dc->curr_phys_id);
} else {
dc->dev_ix++;
}
} else {
if (!(rq->req_stat == RS_DEV_INVALID)) {
esas2r_log(ESAS2R_LOG_WARN,
"A request for device information failed - "
"status:%d", rq->req_stat);
}
dc->state = DCS_DISC_DONE;
}
esas2r_rq_destroy_request(rq, a);
if (!(dc->flags & DCF_POLLED))
esas2r_disc_continue(a, rq);
spin_unlock_irqrestore(&a->mem_lock, flags);
esas2r_trace_exit();
}
static bool esas2r_disc_passthru_dev_addr(struct esas2r_adapter *a,
struct esas2r_request *rq)
{
struct esas2r_disc_context *dc =
(struct esas2r_disc_context *)rq->interrupt_cx;
bool rslt;
struct atto_ioctl *hi;
struct esas2r_sg_context sgc;
esas2r_trace_enter();
esas2r_rq_init_request(rq, a);
sgc.cur_offset = NULL;
sgc.get_phys_addr = (PGETPHYSADDR)esas2r_disc_get_phys_addr;
sgc.length = offsetof(struct atto_ioctl, data)
+ sizeof(struct atto_hba_get_device_address);
esas2r_sgc_init(&sgc, a, rq, rq->vrq->ioctl.sge);
esas2r_build_ioctl_req(a, rq, sgc.length, VDA_IOCTL_HBA);
if (!esas2r_build_sg_list(a, rq, &sgc)) {
esas2r_rq_destroy_request(rq, a);
esas2r_trace_exit();
return false;
}
rq->comp_cb = esas2r_disc_passthru_dev_addr_cb;
rq->interrupt_cx = dc;
hi = (struct atto_ioctl *)a->disc_buffer;
memset(a->disc_buffer, 0, ESAS2R_DISC_BUF_LEN);
hi->version = ATTO_VER_GET_DEV_ADDR0;
hi->function = ATTO_FUNC_GET_DEV_ADDR;
hi->flags = HBAF_TUNNEL;
hi->data.get_dev_addr.target_id = le32_to_cpu(dc->curr_phys_id);
hi->data.get_dev_addr.addr_type = dc->dev_addr_type;
rslt = esas2r_disc_start_request(a, rq);
esas2r_trace_exit();
return rslt;
}
static void esas2r_disc_passthru_dev_addr_cb(struct esas2r_adapter *a,
struct esas2r_request *rq)
{
struct esas2r_disc_context *dc =
(struct esas2r_disc_context *)rq->interrupt_cx;
struct esas2r_target *t = NULL;
unsigned long flags;
struct atto_ioctl *hi;
u16 addrlen;
esas2r_trace_enter();
spin_lock_irqsave(&a->mem_lock, flags);
hi = (struct atto_ioctl *)a->disc_buffer;
if (rq->req_stat == RS_SUCCESS
&& hi->status == ATTO_STS_SUCCESS) {
addrlen = le16_to_cpu(hi->data.get_dev_addr.addr_len);
if (dc->dev_addr_type == ATTO_GDA_AT_PORT) {
if (addrlen == sizeof(u64))
memcpy(&dc->sas_addr,
&hi->data.get_dev_addr.address[0],
addrlen);
else
memset(&dc->sas_addr, 0, sizeof(dc->sas_addr));
dc->dev_addr_type = ATTO_GDA_AT_UNIQUE;
goto next_dev_addr;
} else {
if (HIBYTE(addrlen) == 0) {
t = esas2r_targ_db_add_pthru(a,
dc,
&hi->data.
get_dev_addr.
address[0],
(u8)hi->data.
get_dev_addr.
addr_len);
if (t)
memcpy(&t->sas_addr, &dc->sas_addr,
sizeof(t->sas_addr));
} else {
esas2r_log(ESAS2R_LOG_WARN,
"an error occurred retrieving the "
"back end data (%s:%d)",
__func__,
__LINE__);
}
}
} else {
esas2r_log(ESAS2R_LOG_WARN,
"an error occurred retrieving the back end data - "
"rq->req_stat:%d hi->status:%d",
rq->req_stat, hi->status);
}
if (dc->flags & DCF_DEV_SCAN) {
dc->dev_ix++;
dc->state = DCS_PT_DEV_INFO;
} else if (dc->flags & DCF_DEV_CHANGE) {
dc->curr_targ++;
dc->state = DCS_DEV_ADD;
} else {
esas2r_bugon();
}
next_dev_addr:
esas2r_rq_destroy_request(rq, a);
if (!(dc->flags & DCF_POLLED))
esas2r_disc_continue(a, rq);
spin_unlock_irqrestore(&a->mem_lock, flags);
esas2r_trace_exit();
}
static u32 esas2r_disc_get_phys_addr(struct esas2r_sg_context *sgc, u64 *addr)
{
struct esas2r_adapter *a = sgc->adapter;
if (sgc->length > ESAS2R_DISC_BUF_LEN)
esas2r_bugon();
*addr = a->uncached_phys
+ (u64)((u8 *)a->disc_buffer - a->uncached);
return sgc->length;
}
static bool esas2r_disc_dev_remove(struct esas2r_adapter *a,
struct esas2r_request *rq)
{
struct esas2r_disc_context *dc =
(struct esas2r_disc_context *)rq->interrupt_cx;
struct esas2r_target *t;
struct esas2r_target *t2;
esas2r_trace_enter();
for (t = a->targetdb; t < a->targetdb_end; t++) {
if (t->new_target_state != TS_NOT_PRESENT)
continue;
t->new_target_state = TS_INVALID;
t2 =
esas2r_targ_db_find_by_virt_id(a,
esas2r_targ_get_id(t,
a));
if (t2)
esas2r_targ_db_remove(a, t2);
}
dc->state = DCS_DEV_ADD;
dc->curr_targ = a->targetdb;
esas2r_trace_exit();
return false;
}
static bool esas2r_disc_dev_add(struct esas2r_adapter *a,
struct esas2r_request *rq)
{
struct esas2r_disc_context *dc =
(struct esas2r_disc_context *)rq->interrupt_cx;
struct esas2r_target *t = dc->curr_targ;
if (t >= a->targetdb_end) {
dc->state = DCS_DISC_DONE;
} else if (t->new_target_state == TS_PRESENT) {
struct atto_vda_ae_lu *luevt = &t->lu_event;
esas2r_trace_enter();
t->new_target_state = TS_INVALID;
dc->curr_virt_id = esas2r_targ_get_id(t, a);
if ((luevt->hdr.bylength >= offsetof(struct atto_vda_ae_lu, id)
+ sizeof(struct atto_vda_ae_lu_tgt_lun_raid))
&& !(luevt->dwevent & VDAAE_LU_PASSTHROUGH)) {
dc->block_size = luevt->id.tgtlun_raid.dwblock_size;
dc->interleave = luevt->id.tgtlun_raid.dwinterleave;
} else {
dc->block_size = 0;
dc->interleave = 0;
}
if (luevt->dwevent & VDAAE_LU_PASSTHROUGH) {
if (luevt->dwevent & VDAAE_LU_PHYS_ID) {
dc->state = DCS_PT_DEV_ADDR;
dc->dev_addr_type = ATTO_GDA_AT_PORT;
dc->curr_phys_id = luevt->wphys_target_id;
} else {
esas2r_log(ESAS2R_LOG_WARN,
"luevt->dwevent does not have the "
"VDAAE_LU_PHYS_ID bit set (%s:%d)",
__func__, __LINE__);
}
} else {
dc->raid_grp_name[0] = 0;
esas2r_targ_db_add_raid(a, dc);
}
esas2r_trace("curr_virt_id: %d", dc->curr_virt_id);
esas2r_trace("curr_phys_id: %d", dc->curr_phys_id);
esas2r_trace("dwevent: %d", luevt->dwevent);
esas2r_trace_exit();
}
if (dc->state == DCS_DEV_ADD) {
dc->curr_targ++;
}
return false;
}
static void esas2r_disc_fix_curr_requests(struct esas2r_adapter *a)
{
unsigned long flags;
struct esas2r_target *t;
struct esas2r_request *rq;
struct list_head *element;
spin_lock_irqsave(&a->queue_lock, flags);
list_for_each(element, &a->defer_list) {
rq = list_entry(element, struct esas2r_request, req_list);
if (rq->vrq->scsi.function == VDA_FUNC_SCSI) {
t = a->targetdb + rq->target_id;
if (t->target_state == TS_PRESENT)
rq->vrq->scsi.target_id = le16_to_cpu(
t->virt_targ_id);
else
rq->req_stat = RS_SEL;
}
}
spin_unlock_irqrestore(&a->queue_lock, flags);
}
