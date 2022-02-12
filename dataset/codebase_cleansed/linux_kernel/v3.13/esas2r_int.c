void esas2r_polled_interrupt(struct esas2r_adapter *a)
{
u32 intstat;
u32 doorbell;
esas2r_disable_chip_interrupts(a);
intstat = esas2r_read_register_dword(a, MU_INT_STATUS_OUT);
if (intstat & MU_INTSTAT_POST_OUT) {
esas2r_write_register_dword(a, MU_OUT_LIST_INT_STAT,
MU_OLIS_INT);
esas2r_flush_register_dword(a, MU_OUT_LIST_INT_STAT);
esas2r_get_outbound_responses(a);
}
if (intstat & MU_INTSTAT_DRBL) {
doorbell = esas2r_read_register_dword(a, MU_DOORBELL_OUT);
if (doorbell != 0)
esas2r_doorbell_interrupt(a, doorbell);
}
esas2r_enable_chip_interrupts(a);
if (atomic_read(&a->disable_cnt) == 0)
esas2r_do_deferred_processes(a);
}
irqreturn_t esas2r_interrupt(int irq, void *dev_id)
{
struct esas2r_adapter *a = (struct esas2r_adapter *)dev_id;
if (!esas2r_adapter_interrupt_pending(a))
return IRQ_NONE;
set_bit(AF2_INT_PENDING, &a->flags2);
esas2r_schedule_tasklet(a);
return IRQ_HANDLED;
}
void esas2r_adapter_interrupt(struct esas2r_adapter *a)
{
u32 doorbell;
if (likely(a->int_stat & MU_INTSTAT_POST_OUT)) {
esas2r_write_register_dword(a, MU_OUT_LIST_INT_STAT,
MU_OLIS_INT);
esas2r_flush_register_dword(a, MU_OUT_LIST_INT_STAT);
esas2r_get_outbound_responses(a);
}
if (unlikely(a->int_stat & MU_INTSTAT_DRBL)) {
doorbell = esas2r_read_register_dword(a, MU_DOORBELL_OUT);
if (doorbell != 0)
esas2r_doorbell_interrupt(a, doorbell);
}
a->int_mask = ESAS2R_INT_STS_MASK;
esas2r_enable_chip_interrupts(a);
if (likely(atomic_read(&a->disable_cnt) == 0))
esas2r_do_deferred_processes(a);
}
irqreturn_t esas2r_msi_interrupt(int irq, void *dev_id)
{
struct esas2r_adapter *a = (struct esas2r_adapter *)dev_id;
u32 intstat;
u32 doorbell;
intstat = esas2r_read_register_dword(a, MU_INT_STATUS_OUT);
if (likely(intstat & MU_INTSTAT_POST_OUT)) {
esas2r_write_register_dword(a, MU_OUT_LIST_INT_STAT,
MU_OLIS_INT);
esas2r_flush_register_dword(a, MU_OUT_LIST_INT_STAT);
esas2r_get_outbound_responses(a);
}
if (unlikely(intstat & MU_INTSTAT_DRBL)) {
doorbell = esas2r_read_register_dword(a, MU_DOORBELL_OUT);
if (doorbell != 0)
esas2r_doorbell_interrupt(a, doorbell);
}
esas2r_disable_chip_interrupts(a);
esas2r_enable_chip_interrupts(a);
if (likely(atomic_read(&a->disable_cnt) == 0))
esas2r_do_deferred_processes(a);
esas2r_do_tasklet_tasks(a);
return 1;
}
static void esas2r_handle_outbound_rsp_err(struct esas2r_adapter *a,
struct esas2r_request *rq,
struct atto_vda_ob_rsp *rsp)
{
if (unlikely(rq->req_stat != RS_SUCCESS)) {
memcpy(&rq->func_rsp, &rsp->func_rsp, sizeof(rsp->func_rsp));
if (rq->req_stat == RS_ABORTED) {
if (rq->timeout > RQ_MAX_TIMEOUT)
rq->req_stat = RS_TIMEOUT;
} else if (rq->req_stat == RS_SCSI_ERROR) {
u8 scsistatus = rq->func_rsp.scsi_rsp.scsi_stat;
esas2r_trace("scsistatus: %x", scsistatus);
if (scsistatus == SAM_STAT_GOOD || scsistatus ==
SAM_STAT_CONDITION_MET || scsistatus ==
SAM_STAT_INTERMEDIATE || scsistatus ==
SAM_STAT_INTERMEDIATE_CONDITION_MET) {
rq->req_stat = RS_SUCCESS;
rq->func_rsp.scsi_rsp.scsi_stat =
SAM_STAT_GOOD;
}
}
}
}
static void esas2r_get_outbound_responses(struct esas2r_adapter *a)
{
struct atto_vda_ob_rsp *rsp;
u32 rspput_ptr;
u32 rspget_ptr;
struct esas2r_request *rq;
u32 handle;
unsigned long flags;
LIST_HEAD(comp_list);
esas2r_trace_enter();
spin_lock_irqsave(&a->queue_lock, flags);
rspput_ptr = le32_to_cpu(*a->outbound_copy) & MU_OLC_WRT_PTR;
rspget_ptr = a->last_read;
esas2r_trace("rspput_ptr: %x, rspget_ptr: %x", rspput_ptr, rspget_ptr);
if (unlikely(rspget_ptr == rspput_ptr)) {
spin_unlock_irqrestore(&a->queue_lock, flags);
esas2r_trace_exit();
return;
}
if (unlikely(rspput_ptr >= a->list_size)) {
spin_unlock_irqrestore(&a->queue_lock, flags);
esas2r_bugon();
esas2r_local_reset_adapter(a);
esas2r_trace_exit();
return;
}
do {
rspget_ptr++;
if (rspget_ptr >= a->list_size)
rspget_ptr = 0;
rsp = (struct atto_vda_ob_rsp *)a->outbound_list_md.virt_addr
+ rspget_ptr;
handle = rsp->handle;
if (unlikely(LOWORD(handle) == 0
|| LOWORD(handle) > num_requests +
num_ae_requests + 1)) {
esas2r_bugon();
continue;
}
rq = a->req_table[LOWORD(handle)];
if (unlikely(rq == NULL || rq->vrq->scsi.handle != handle)) {
esas2r_bugon();
continue;
}
list_del(&rq->req_list);
rq->req_stat = rsp->req_stat;
esas2r_trace("handle: %x", handle);
esas2r_trace("rq: %p", rq);
esas2r_trace("req_status: %x", rq->req_stat);
if (likely(rq->vrq->scsi.function == VDA_FUNC_SCSI)) {
esas2r_handle_outbound_rsp_err(a, rq, rsp);
} else {
memcpy(&rq->func_rsp, &rsp->func_rsp,
sizeof(rsp->func_rsp));
}
list_add_tail(&rq->comp_list, &comp_list);
} while (rspget_ptr != rspput_ptr);
a->last_read = rspget_ptr;
spin_unlock_irqrestore(&a->queue_lock, flags);
esas2r_comp_list_drain(a, &comp_list);
esas2r_trace_exit();
}
void esas2r_do_deferred_processes(struct esas2r_adapter *a)
{
int startreqs = 2;
struct esas2r_request *rq;
unsigned long flags;
if (test_bit(AF_CHPRST_PENDING, &a->flags) ||
test_bit(AF_FLASHING, &a->flags))
startreqs = 0;
else if (test_bit(AF_DISC_PENDING, &a->flags))
startreqs = 1;
atomic_inc(&a->disable_cnt);
if (esas2r_is_tasklet_pending(a)) {
esas2r_schedule_tasklet(a);
startreqs = 0;
}
if (startreqs && !list_empty(&a->defer_list)) {
LIST_HEAD(comp_list);
struct list_head *element, *next;
spin_lock_irqsave(&a->queue_lock, flags);
list_for_each_safe(element, next, &a->defer_list) {
rq = list_entry(element, struct esas2r_request,
req_list);
if (rq->req_stat != RS_PENDING) {
list_del(element);
list_add_tail(&rq->comp_list, &comp_list);
}
else if (rq->req_type == RT_DISC_REQ) {
list_del(element);
esas2r_disc_local_start_request(a, rq);
} else if (startreqs == 2) {
list_del(element);
esas2r_local_start_request(a, rq);
if (test_bit(AF_FLASHING, &a->flags))
break;
}
}
spin_unlock_irqrestore(&a->queue_lock, flags);
esas2r_comp_list_drain(a, &comp_list);
}
atomic_dec(&a->disable_cnt);
}
void esas2r_process_adapter_reset(struct esas2r_adapter *a)
{
struct esas2r_request *rq = &a->general_req;
unsigned long flags;
struct esas2r_disc_context *dc;
LIST_HEAD(comp_list);
struct list_head *element;
esas2r_trace_enter();
spin_lock_irqsave(&a->queue_lock, flags);
if (rq->interrupt_cx) {
dc = (struct esas2r_disc_context *)rq->interrupt_cx;
dc->disc_evt = 0;
clear_bit(AF_DISC_IN_PROG, &a->flags);
}
rq->interrupt_cx = NULL;
rq->interrupt_cb = NULL;
rq->comp_cb = esas2r_dummy_complete;
*a->outbound_copy =
a->last_write =
a->last_read = a->list_size - 1;
set_bit(AF_COMM_LIST_TOGGLE, &a->flags);
list_for_each(element, &a->defer_list) {
rq = list_entry(element, struct esas2r_request, req_list);
if (rq->req_stat == RS_STARTED)
if (esas2r_ioreq_aborted(a, rq, RS_ABORTED))
list_add_tail(&rq->comp_list, &comp_list);
}
spin_unlock_irqrestore(&a->queue_lock, flags);
esas2r_comp_list_drain(a, &comp_list);
esas2r_process_bus_reset(a);
esas2r_trace_exit();
}
static void esas2r_process_bus_reset(struct esas2r_adapter *a)
{
struct esas2r_request *rq;
struct list_head *element;
unsigned long flags;
LIST_HEAD(comp_list);
esas2r_trace_enter();
esas2r_hdebug("reset detected");
spin_lock_irqsave(&a->queue_lock, flags);
list_for_each(element, &a->defer_list) {
rq = list_entry(element, struct esas2r_request, req_list);
if (esas2r_ioreq_aborted(a, rq, RS_ABORTED))
list_add_tail(&rq->comp_list, &comp_list);
}
spin_unlock_irqrestore(&a->queue_lock, flags);
esas2r_comp_list_drain(a, &comp_list);
if (atomic_read(&a->disable_cnt) == 0)
esas2r_do_deferred_processes(a);
clear_bit(AF_OS_RESET, &a->flags);
esas2r_trace_exit();
}
static void esas2r_chip_rst_needed_during_tasklet(struct esas2r_adapter *a)
{
clear_bit(AF_CHPRST_NEEDED, &a->flags);
clear_bit(AF_BUSRST_NEEDED, &a->flags);
clear_bit(AF_BUSRST_DETECTED, &a->flags);
clear_bit(AF_BUSRST_PENDING, &a->flags);
if (!esas2r_is_adapter_present(a) || (a->chip_uptime >=
ESAS2R_CHP_UPTIME_MAX)) {
esas2r_hdebug("*** adapter disabled ***");
set_bit(AF_DEGRADED_MODE, &a->flags);
set_bit(AF_DISABLED, &a->flags);
clear_bit(AF_CHPRST_PENDING, &a->flags);
clear_bit(AF_DISC_PENDING, &a->flags);
esas2r_disable_chip_interrupts(a);
a->int_mask = 0;
esas2r_process_adapter_reset(a);
esas2r_log(ESAS2R_LOG_CRIT,
"Adapter disabled because of hardware failure");
} else {
bool alrdyrst = test_and_set_bit(AF_CHPRST_STARTED, &a->flags);
if (!alrdyrst)
esas2r_disable_chip_interrupts(a);
if ((test_bit(AF_POWER_MGT, &a->flags)) &&
!test_bit(AF_FIRST_INIT, &a->flags) && !alrdyrst) {
} else {
esas2r_hdebug("*** resetting chip ***");
esas2r_reset_chip(a);
}
a->chip_uptime += ESAS2R_CHP_UPTIME_CNT;
a->chip_init_time = jiffies_to_msecs(jiffies);
if (!test_bit(AF_POWER_MGT, &a->flags)) {
esas2r_process_adapter_reset(a);
if (!alrdyrst) {
a->prev_dev_cnt =
esas2r_targ_db_get_tgt_cnt(a);
esas2r_targ_db_remove_all(a, false);
}
}
a->int_mask = 0;
}
}
static void esas2r_handle_chip_rst_during_tasklet(struct esas2r_adapter *a)
{
while (test_bit(AF_CHPRST_DETECTED, &a->flags)) {
if (!test_bit(AF_DEGRADED_MODE, &a->flags) &&
!test_bit(AF_POWER_MGT, &a->flags))
esas2r_disable_chip_interrupts(a);
esas2r_check_adapter(a);
esas2r_init_adapter_hw(a, 0);
if (test_bit(AF_CHPRST_NEEDED, &a->flags))
break;
if (test_bit(AF_POWER_MGT, &a->flags)) {
if (test_bit(AF_FIRST_INIT, &a->flags)) {
esas2r_log(ESAS2R_LOG_CRIT,
"The firmware was reset during a normal power-up sequence");
} else {
clear_bit(AF_POWER_MGT, &a->flags);
esas2r_send_reset_ae(a, true);
}
} else {
if (test_bit(AF_FIRST_INIT, &a->flags)) {
} else {
esas2r_send_reset_ae(a, false);
}
esas2r_log(ESAS2R_LOG_CRIT,
"Recovering from a chip reset while the chip was online");
}
clear_bit(AF_CHPRST_STARTED, &a->flags);
esas2r_enable_chip_interrupts(a);
clear_bit(AF_CHPRST_DETECTED, &a->flags);
}
}
void esas2r_do_tasklet_tasks(struct esas2r_adapter *a)
{
if (test_bit(AF_CHPRST_NEEDED, &a->flags) ||
test_bit(AF_CHPRST_DETECTED, &a->flags)) {
if (test_bit(AF_CHPRST_NEEDED, &a->flags))
esas2r_chip_rst_needed_during_tasklet(a);
esas2r_handle_chip_rst_during_tasklet(a);
}
if (test_bit(AF_BUSRST_NEEDED, &a->flags)) {
esas2r_hdebug("hard resetting bus");
clear_bit(AF_BUSRST_NEEDED, &a->flags);
if (test_bit(AF_FLASHING, &a->flags))
set_bit(AF_BUSRST_DETECTED, &a->flags);
else
esas2r_write_register_dword(a, MU_DOORBELL_IN,
DRBL_RESET_BUS);
}
if (test_bit(AF_BUSRST_DETECTED, &a->flags)) {
esas2r_process_bus_reset(a);
esas2r_log_dev(ESAS2R_LOG_WARN,
&(a->host->shost_gendev),
"scsi_report_bus_reset() called");
scsi_report_bus_reset(a->host, 0);
clear_bit(AF_BUSRST_DETECTED, &a->flags);
clear_bit(AF_BUSRST_PENDING, &a->flags);
esas2r_log(ESAS2R_LOG_WARN, "Bus reset complete");
}
if (test_bit(AF_PORT_CHANGE, &a->flags)) {
clear_bit(AF_PORT_CHANGE, &a->flags);
esas2r_targ_db_report_changes(a);
}
if (atomic_read(&a->disable_cnt) == 0)
esas2r_do_deferred_processes(a);
}
static void esas2r_doorbell_interrupt(struct esas2r_adapter *a, u32 doorbell)
{
if (!(doorbell & DRBL_FORCE_INT)) {
esas2r_trace_enter();
esas2r_trace("doorbell: %x", doorbell);
}
esas2r_write_register_dword(a, MU_DOORBELL_OUT, doorbell);
if (doorbell & DRBL_RESET_BUS)
set_bit(AF_BUSRST_DETECTED, &a->flags);
if (doorbell & DRBL_FORCE_INT)
clear_bit(AF_HEARTBEAT, &a->flags);
if (doorbell & DRBL_PANIC_REASON_MASK) {
esas2r_hdebug("*** Firmware Panic ***");
esas2r_log(ESAS2R_LOG_CRIT, "The firmware has panicked");
}
if (doorbell & DRBL_FW_RESET) {
set_bit(AF2_COREDUMP_AVAIL, &a->flags2);
esas2r_local_reset_adapter(a);
}
if (!(doorbell & DRBL_FORCE_INT))
esas2r_trace_exit();
}
void esas2r_force_interrupt(struct esas2r_adapter *a)
{
esas2r_write_register_dword(a, MU_DOORBELL_IN, DRBL_FORCE_INT |
DRBL_DRV_VER);
}
static void esas2r_lun_event(struct esas2r_adapter *a, union atto_vda_ae *ae,
u16 target, u32 length)
{
struct esas2r_target *t = a->targetdb + target;
u32 cplen = length;
unsigned long flags;
if (cplen > sizeof(t->lu_event))
cplen = sizeof(t->lu_event);
esas2r_trace("ae->lu.dwevent: %x", ae->lu.dwevent);
esas2r_trace("ae->lu.bystate: %x", ae->lu.bystate);
spin_lock_irqsave(&a->mem_lock, flags);
t->new_target_state = TS_INVALID;
if (ae->lu.dwevent & VDAAE_LU_LOST) {
t->new_target_state = TS_NOT_PRESENT;
} else {
switch (ae->lu.bystate) {
case VDAAE_LU_NOT_PRESENT:
case VDAAE_LU_OFFLINE:
case VDAAE_LU_DELETED:
case VDAAE_LU_FACTORY_DISABLED:
t->new_target_state = TS_NOT_PRESENT;
break;
case VDAAE_LU_ONLINE:
case VDAAE_LU_DEGRADED:
t->new_target_state = TS_PRESENT;
break;
}
}
if (t->new_target_state != TS_INVALID) {
memcpy(&t->lu_event, &ae->lu, cplen);
esas2r_disc_queue_event(a, DCDE_DEV_CHANGE);
}
spin_unlock_irqrestore(&a->mem_lock, flags);
}
void esas2r_ae_complete(struct esas2r_adapter *a, struct esas2r_request *rq)
{
union atto_vda_ae *ae =
(union atto_vda_ae *)rq->vda_rsp_data->ae_data.event_data;
u32 length = le32_to_cpu(rq->func_rsp.ae_rsp.length);
union atto_vda_ae *last =
(union atto_vda_ae *)(rq->vda_rsp_data->ae_data.event_data
+ length);
esas2r_trace_enter();
esas2r_trace("length: %d", length);
if (length > sizeof(struct atto_vda_ae_data)
|| (length & 3) != 0
|| length == 0) {
esas2r_log(ESAS2R_LOG_WARN,
"The AE request response length (%p) is too long: %d",
rq, length);
esas2r_hdebug("aereq->length (0x%x) too long", length);
esas2r_bugon();
last = ae;
}
while (ae < last) {
u16 target;
esas2r_trace("ae: %p", ae);
esas2r_trace("ae->hdr: %p", &(ae->hdr));
length = ae->hdr.bylength;
if (length > (u32)((u8 *)last - (u8 *)ae)
|| (length & 3) != 0
|| length == 0) {
esas2r_log(ESAS2R_LOG_CRIT,
"the async event length is invalid (%p): %d",
ae, length);
esas2r_hdebug("ae->hdr.length (0x%x) invalid", length);
esas2r_bugon();
break;
}
esas2r_nuxi_ae_data(ae);
esas2r_queue_fw_event(a, fw_event_vda_ae, ae,
sizeof(union atto_vda_ae));
switch (ae->hdr.bytype) {
case VDAAE_HDR_TYPE_RAID:
if (ae->raid.dwflags & (VDAAE_GROUP_STATE
| VDAAE_RBLD_STATE
| VDAAE_MEMBER_CHG
| VDAAE_PART_CHG)) {
esas2r_log(ESAS2R_LOG_INFO,
"RAID event received - name:%s rebuild_state:%d group_state:%d",
ae->raid.acname,
ae->raid.byrebuild_state,
ae->raid.bygroup_state);
}
break;
case VDAAE_HDR_TYPE_LU:
esas2r_log(ESAS2R_LOG_INFO,
"LUN event received: event:%d target_id:%d LUN:%d state:%d",
ae->lu.dwevent,
ae->lu.id.tgtlun.wtarget_id,
ae->lu.id.tgtlun.bylun,
ae->lu.bystate);
target = ae->lu.id.tgtlun.wtarget_id;
if (target < ESAS2R_MAX_TARGETS)
esas2r_lun_event(a, ae, target, length);
break;
case VDAAE_HDR_TYPE_DISK:
esas2r_log(ESAS2R_LOG_INFO, "Disk event received");
break;
default:
break;
}
ae = (union atto_vda_ae *)((u8 *)ae + length);
}
esas2r_start_ae_request(a, rq);
esas2r_trace_exit();
}
void esas2r_send_reset_ae(struct esas2r_adapter *a, bool pwr_mgt)
{
struct atto_vda_ae_hdr ae;
if (pwr_mgt)
ae.bytype = VDAAE_HDR_TYPE_PWRMGT;
else
ae.bytype = VDAAE_HDR_TYPE_RESET;
ae.byversion = VDAAE_HDR_VER_0;
ae.byflags = 0;
ae.bylength = (u8)sizeof(struct atto_vda_ae_hdr);
if (pwr_mgt)
esas2r_hdebug("*** sending power management AE ***");
else
esas2r_hdebug("*** sending reset AE ***");
esas2r_queue_fw_event(a, fw_event_vda_ae, &ae,
sizeof(union atto_vda_ae));
}
void esas2r_dummy_complete(struct esas2r_adapter *a, struct esas2r_request *rq)
{}
static void esas2r_check_req_rsp_sense(struct esas2r_adapter *a,
struct esas2r_request *rq)
{
u8 snslen, snslen2;
snslen = snslen2 = rq->func_rsp.scsi_rsp.sense_len;
if (snslen > rq->sense_len)
snslen = rq->sense_len;
if (snslen) {
if (rq->sense_buf)
memcpy(rq->sense_buf, rq->data_buf, snslen);
else
rq->sense_buf = (u8 *)rq->data_buf;
if (snslen2 > 0x0c) {
u8 *s = (u8 *)rq->data_buf;
esas2r_trace_enter();
if (s[0x0c] == 0x3f && s[0x0d] == 0x0E) {
esas2r_trace("rq->target_id: %d",
rq->target_id);
esas2r_target_state_changed(a, rq->target_id,
TS_LUN_CHANGE);
}
esas2r_trace("add_sense_key=%x", s[0x0c]);
esas2r_trace("add_sense_qual=%x", s[0x0d]);
esas2r_trace_exit();
}
}
rq->sense_len = snslen;
}
void esas2r_complete_request(struct esas2r_adapter *a,
struct esas2r_request *rq)
{
if (rq->vrq->scsi.function == VDA_FUNC_FLASH
&& rq->vrq->flash.sub_func == VDA_FLASH_COMMIT)
clear_bit(AF_FLASHING, &a->flags);
if (rq->interrupt_cb) {
(*rq->interrupt_cb)(a, rq);
if (rq->req_stat == RS_PENDING) {
esas2r_start_request(a, rq);
return;
}
}
if (likely(rq->vrq->scsi.function == VDA_FUNC_SCSI)
&& unlikely(rq->req_stat != RS_SUCCESS)) {
esas2r_check_req_rsp_sense(a, rq);
esas2r_log_request_failure(a, rq);
}
(*rq->comp_cb)(a, rq);
}
