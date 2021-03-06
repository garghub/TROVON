void sci_init_sm(struct sci_base_state_machine *sm,
const struct sci_base_state *state_table, u32 initial_state)
{
sci_state_transition_t handler;
sm->initial_state_id = initial_state;
sm->previous_state_id = initial_state;
sm->current_state_id = initial_state;
sm->state_table = state_table;
handler = sm->state_table[initial_state].enter_state;
if (handler)
handler(sm);
}
void sci_change_state(struct sci_base_state_machine *sm, u32 next_state)
{
sci_state_transition_t handler;
handler = sm->state_table[sm->current_state_id].exit_state;
if (handler)
handler(sm);
sm->previous_state_id = sm->current_state_id;
sm->current_state_id = next_state;
handler = sm->state_table[sm->current_state_id].enter_state;
if (handler)
handler(sm);
}
static bool sci_controller_completion_queue_has_entries(struct isci_host *ihost)
{
u32 get_value = ihost->completion_queue_get;
u32 get_index = get_value & SMU_COMPLETION_QUEUE_GET_POINTER_MASK;
if (NORMALIZE_GET_POINTER_CYCLE_BIT(get_value) ==
COMPLETION_QUEUE_CYCLE_BIT(ihost->completion_queue[get_index]))
return true;
return false;
}
static bool sci_controller_isr(struct isci_host *ihost)
{
if (sci_controller_completion_queue_has_entries(ihost)) {
return true;
} else {
writel(SMU_ISR_COMPLETION, &ihost->smu_registers->interrupt_status);
writel(0xFF000000, &ihost->smu_registers->interrupt_mask);
writel(0, &ihost->smu_registers->interrupt_mask);
}
return false;
}
irqreturn_t isci_msix_isr(int vec, void *data)
{
struct isci_host *ihost = data;
if (sci_controller_isr(ihost))
tasklet_schedule(&ihost->completion_tasklet);
return IRQ_HANDLED;
}
static bool sci_controller_error_isr(struct isci_host *ihost)
{
u32 interrupt_status;
interrupt_status =
readl(&ihost->smu_registers->interrupt_status);
interrupt_status &= (SMU_ISR_QUEUE_ERROR | SMU_ISR_QUEUE_SUSPEND);
if (interrupt_status != 0) {
return true;
}
writel(0xff, &ihost->smu_registers->interrupt_mask);
writel(0, &ihost->smu_registers->interrupt_mask);
return false;
}
static void sci_controller_task_completion(struct isci_host *ihost, u32 ent)
{
u32 index = SCU_GET_COMPLETION_INDEX(ent);
struct isci_request *ireq = ihost->reqs[index];
if (test_bit(IREQ_ACTIVE, &ireq->flags) &&
ireq->io_tag != SCI_CONTROLLER_INVALID_IO_TAG &&
ISCI_TAG_SEQ(ireq->io_tag) == ihost->io_request_sequence[index])
sci_io_request_tc_completion(ireq, ent);
}
static void sci_controller_sdma_completion(struct isci_host *ihost, u32 ent)
{
u32 index;
struct isci_request *ireq;
struct isci_remote_device *idev;
index = SCU_GET_COMPLETION_INDEX(ent);
switch (scu_get_command_request_type(ent)) {
case SCU_CONTEXT_COMMAND_REQUEST_TYPE_POST_TC:
case SCU_CONTEXT_COMMAND_REQUEST_TYPE_DUMP_TC:
ireq = ihost->reqs[index];
dev_warn(&ihost->pdev->dev, "%s: %x for io request %p\n",
__func__, ent, ireq);
break;
case SCU_CONTEXT_COMMAND_REQUEST_TYPE_DUMP_RNC:
case SCU_CONTEXT_COMMAND_REQUEST_TYPE_OTHER_RNC:
case SCU_CONTEXT_COMMAND_REQUEST_TYPE_POST_RNC:
idev = ihost->device_table[index];
dev_warn(&ihost->pdev->dev, "%s: %x for device %p\n",
__func__, ent, idev);
break;
default:
dev_warn(&ihost->pdev->dev, "%s: unknown completion type %x\n",
__func__, ent);
break;
}
}
static void sci_controller_unsolicited_frame(struct isci_host *ihost, u32 ent)
{
u32 index;
u32 frame_index;
struct scu_unsolicited_frame_header *frame_header;
struct isci_phy *iphy;
struct isci_remote_device *idev;
enum sci_status result = SCI_FAILURE;
frame_index = SCU_GET_FRAME_INDEX(ent);
frame_header = ihost->uf_control.buffers.array[frame_index].header;
ihost->uf_control.buffers.array[frame_index].state = UNSOLICITED_FRAME_IN_USE;
if (SCU_GET_FRAME_ERROR(ent)) {
sci_controller_release_frame(ihost, frame_index);
return;
}
if (frame_header->is_address_frame) {
index = SCU_GET_PROTOCOL_ENGINE_INDEX(ent);
iphy = &ihost->phys[index];
result = sci_phy_frame_handler(iphy, frame_index);
} else {
index = SCU_GET_COMPLETION_INDEX(ent);
if (index == SCIC_SDS_REMOTE_NODE_CONTEXT_INVALID_INDEX) {
index = SCU_GET_PROTOCOL_ENGINE_INDEX(ent);
iphy = &ihost->phys[index];
result = sci_phy_frame_handler(iphy, frame_index);
} else {
if (index < ihost->remote_node_entries)
idev = ihost->device_table[index];
else
idev = NULL;
if (idev != NULL)
result = sci_remote_device_frame_handler(idev, frame_index);
else
sci_controller_release_frame(ihost, frame_index);
}
}
if (result != SCI_SUCCESS) {
}
}
static void sci_controller_event_completion(struct isci_host *ihost, u32 ent)
{
struct isci_remote_device *idev;
struct isci_request *ireq;
struct isci_phy *iphy;
u32 index;
index = SCU_GET_COMPLETION_INDEX(ent);
switch (scu_get_event_type(ent)) {
case SCU_EVENT_TYPE_SMU_COMMAND_ERROR:
dev_err(&ihost->pdev->dev,
"%s: SCIC Controller 0x%p received SMU command error "
"0x%x\n",
__func__,
ihost,
ent);
break;
case SCU_EVENT_TYPE_SMU_PCQ_ERROR:
case SCU_EVENT_TYPE_SMU_ERROR:
case SCU_EVENT_TYPE_FATAL_MEMORY_ERROR:
dev_err(&ihost->pdev->dev,
"%s: SCIC Controller 0x%p received fatal controller "
"event 0x%x\n",
__func__,
ihost,
ent);
break;
case SCU_EVENT_TYPE_TRANSPORT_ERROR:
ireq = ihost->reqs[index];
sci_io_request_event_handler(ireq, ent);
break;
case SCU_EVENT_TYPE_PTX_SCHEDULE_EVENT:
switch (scu_get_event_specifier(ent)) {
case SCU_EVENT_SPECIFIC_SMP_RESPONSE_NO_PE:
case SCU_EVENT_SPECIFIC_TASK_TIMEOUT:
ireq = ihost->reqs[index];
if (ireq != NULL)
sci_io_request_event_handler(ireq, ent);
else
dev_warn(&ihost->pdev->dev,
"%s: SCIC Controller 0x%p received "
"event 0x%x for io request object "
"that doesnt exist.\n",
__func__,
ihost,
ent);
break;
case SCU_EVENT_SPECIFIC_IT_NEXUS_TIMEOUT:
idev = ihost->device_table[index];
if (idev != NULL)
sci_remote_device_event_handler(idev, ent);
else
dev_warn(&ihost->pdev->dev,
"%s: SCIC Controller 0x%p received "
"event 0x%x for remote device object "
"that doesnt exist.\n",
__func__,
ihost,
ent);
break;
}
break;
case SCU_EVENT_TYPE_BROADCAST_CHANGE:
case SCU_EVENT_TYPE_ERR_CNT_EVENT:
case SCU_EVENT_TYPE_OSSP_EVENT:
index = SCU_GET_PROTOCOL_ENGINE_INDEX(ent);
iphy = &ihost->phys[index];
sci_phy_event_handler(iphy, ent);
break;
case SCU_EVENT_TYPE_RNC_SUSPEND_TX:
case SCU_EVENT_TYPE_RNC_SUSPEND_TX_RX:
case SCU_EVENT_TYPE_RNC_OPS_MISC:
if (index < ihost->remote_node_entries) {
idev = ihost->device_table[index];
if (idev != NULL)
sci_remote_device_event_handler(idev, ent);
} else
dev_err(&ihost->pdev->dev,
"%s: SCIC Controller 0x%p received event 0x%x "
"for remote device object 0x%0x that doesnt "
"exist.\n",
__func__,
ihost,
ent,
index);
break;
default:
dev_warn(&ihost->pdev->dev,
"%s: SCIC Controller received unknown event code %x\n",
__func__,
ent);
break;
}
}
static void sci_controller_process_completions(struct isci_host *ihost)
{
u32 completion_count = 0;
u32 ent;
u32 get_index;
u32 get_cycle;
u32 event_get;
u32 event_cycle;
dev_dbg(&ihost->pdev->dev,
"%s: completion queue begining get:0x%08x\n",
__func__,
ihost->completion_queue_get);
get_index = NORMALIZE_GET_POINTER(ihost->completion_queue_get);
get_cycle = SMU_CQGR_CYCLE_BIT & ihost->completion_queue_get;
event_get = NORMALIZE_EVENT_POINTER(ihost->completion_queue_get);
event_cycle = SMU_CQGR_EVENT_CYCLE_BIT & ihost->completion_queue_get;
while (
NORMALIZE_GET_POINTER_CYCLE_BIT(get_cycle)
== COMPLETION_QUEUE_CYCLE_BIT(ihost->completion_queue[get_index])
) {
completion_count++;
ent = ihost->completion_queue[get_index];
get_cycle ^= ((get_index+1) & SCU_MAX_COMPLETION_QUEUE_ENTRIES) <<
(SMU_COMPLETION_QUEUE_GET_CYCLE_BIT_SHIFT - SCU_MAX_COMPLETION_QUEUE_SHIFT);
get_index = (get_index+1) & (SCU_MAX_COMPLETION_QUEUE_ENTRIES-1);
dev_dbg(&ihost->pdev->dev,
"%s: completion queue entry:0x%08x\n",
__func__,
ent);
switch (SCU_GET_COMPLETION_TYPE(ent)) {
case SCU_COMPLETION_TYPE_TASK:
sci_controller_task_completion(ihost, ent);
break;
case SCU_COMPLETION_TYPE_SDMA:
sci_controller_sdma_completion(ihost, ent);
break;
case SCU_COMPLETION_TYPE_UFI:
sci_controller_unsolicited_frame(ihost, ent);
break;
case SCU_COMPLETION_TYPE_EVENT:
sci_controller_event_completion(ihost, ent);
break;
case SCU_COMPLETION_TYPE_NOTIFY: {
event_cycle ^= ((event_get+1) & SCU_MAX_EVENTS) <<
(SMU_COMPLETION_QUEUE_GET_EVENT_CYCLE_BIT_SHIFT - SCU_MAX_EVENTS_SHIFT);
event_get = (event_get+1) & (SCU_MAX_EVENTS-1);
sci_controller_event_completion(ihost, ent);
break;
}
default:
dev_warn(&ihost->pdev->dev,
"%s: SCIC Controller received unknown "
"completion type %x\n",
__func__,
ent);
break;
}
}
if (completion_count > 0) {
ihost->completion_queue_get =
SMU_CQGR_GEN_BIT(ENABLE) |
SMU_CQGR_GEN_BIT(EVENT_ENABLE) |
event_cycle |
SMU_CQGR_GEN_VAL(EVENT_POINTER, event_get) |
get_cycle |
SMU_CQGR_GEN_VAL(POINTER, get_index);
writel(ihost->completion_queue_get,
&ihost->smu_registers->completion_queue_get);
}
dev_dbg(&ihost->pdev->dev,
"%s: completion queue ending get:0x%08x\n",
__func__,
ihost->completion_queue_get);
}
static void sci_controller_error_handler(struct isci_host *ihost)
{
u32 interrupt_status;
interrupt_status =
readl(&ihost->smu_registers->interrupt_status);
if ((interrupt_status & SMU_ISR_QUEUE_SUSPEND) &&
sci_controller_completion_queue_has_entries(ihost)) {
sci_controller_process_completions(ihost);
writel(SMU_ISR_QUEUE_SUSPEND, &ihost->smu_registers->interrupt_status);
} else {
dev_err(&ihost->pdev->dev, "%s: status: %#x\n", __func__,
interrupt_status);
sci_change_state(&ihost->sm, SCIC_FAILED);
return;
}
writel(0, &ihost->smu_registers->interrupt_mask);
}
irqreturn_t isci_intx_isr(int vec, void *data)
{
irqreturn_t ret = IRQ_NONE;
struct isci_host *ihost = data;
if (sci_controller_isr(ihost)) {
writel(SMU_ISR_COMPLETION, &ihost->smu_registers->interrupt_status);
tasklet_schedule(&ihost->completion_tasklet);
ret = IRQ_HANDLED;
} else if (sci_controller_error_isr(ihost)) {
spin_lock(&ihost->scic_lock);
sci_controller_error_handler(ihost);
spin_unlock(&ihost->scic_lock);
ret = IRQ_HANDLED;
}
return ret;
}
irqreturn_t isci_error_isr(int vec, void *data)
{
struct isci_host *ihost = data;
if (sci_controller_error_isr(ihost))
sci_controller_error_handler(ihost);
return IRQ_HANDLED;
}
static void isci_host_start_complete(struct isci_host *ihost, enum sci_status completion_status)
{
if (completion_status != SCI_SUCCESS)
dev_info(&ihost->pdev->dev,
"controller start timed out, continuing...\n");
isci_host_change_state(ihost, isci_ready);
clear_bit(IHOST_START_PENDING, &ihost->flags);
wake_up(&ihost->eventq);
}
int isci_host_scan_finished(struct Scsi_Host *shost, unsigned long time)
{
struct isci_host *ihost = SHOST_TO_SAS_HA(shost)->lldd_ha;
if (test_bit(IHOST_START_PENDING, &ihost->flags))
return 0;
scsi_flush_work(shost);
scsi_flush_work(shost);
dev_dbg(&ihost->pdev->dev,
"%s: ihost->status = %d, time = %ld\n",
__func__, isci_host_get_state(ihost), time);
return 1;
}
static u32 sci_controller_get_suggested_start_timeout(struct isci_host *ihost)
{
if (!ihost)
return 0;
return SCIC_SDS_SIGNATURE_FIS_TIMEOUT
+ SCIC_SDS_CONTROLLER_PHY_START_TIMEOUT
+ ((SCI_MAX_PHYS - 1) * SCIC_SDS_CONTROLLER_POWER_CONTROL_INTERVAL);
}
static void sci_controller_enable_interrupts(struct isci_host *ihost)
{
BUG_ON(ihost->smu_registers == NULL);
writel(0, &ihost->smu_registers->interrupt_mask);
}
void sci_controller_disable_interrupts(struct isci_host *ihost)
{
BUG_ON(ihost->smu_registers == NULL);
writel(0xffffffff, &ihost->smu_registers->interrupt_mask);
}
static void sci_controller_enable_port_task_scheduler(struct isci_host *ihost)
{
u32 port_task_scheduler_value;
port_task_scheduler_value =
readl(&ihost->scu_registers->peg0.ptsg.control);
port_task_scheduler_value |=
(SCU_PTSGCR_GEN_BIT(ETM_ENABLE) |
SCU_PTSGCR_GEN_BIT(PTSG_ENABLE));
writel(port_task_scheduler_value,
&ihost->scu_registers->peg0.ptsg.control);
}
static void sci_controller_assign_task_entries(struct isci_host *ihost)
{
u32 task_assignment;
task_assignment =
readl(&ihost->smu_registers->task_context_assignment[0]);
task_assignment |= (SMU_TCA_GEN_VAL(STARTING, 0)) |
(SMU_TCA_GEN_VAL(ENDING, ihost->task_context_entries - 1)) |
(SMU_TCA_GEN_BIT(RANGE_CHECK_ENABLE));
writel(task_assignment,
&ihost->smu_registers->task_context_assignment[0]);
}
static void sci_controller_initialize_completion_queue(struct isci_host *ihost)
{
u32 index;
u32 completion_queue_control_value;
u32 completion_queue_get_value;
u32 completion_queue_put_value;
ihost->completion_queue_get = 0;
completion_queue_control_value =
(SMU_CQC_QUEUE_LIMIT_SET(SCU_MAX_COMPLETION_QUEUE_ENTRIES - 1) |
SMU_CQC_EVENT_LIMIT_SET(SCU_MAX_EVENTS - 1));
writel(completion_queue_control_value,
&ihost->smu_registers->completion_queue_control);
completion_queue_get_value = (
(SMU_CQGR_GEN_VAL(POINTER, 0))
| (SMU_CQGR_GEN_VAL(EVENT_POINTER, 0))
| (SMU_CQGR_GEN_BIT(ENABLE))
| (SMU_CQGR_GEN_BIT(EVENT_ENABLE))
);
writel(completion_queue_get_value,
&ihost->smu_registers->completion_queue_get);
completion_queue_put_value = (
(SMU_CQPR_GEN_VAL(POINTER, 0))
| (SMU_CQPR_GEN_VAL(EVENT_POINTER, 0))
);
writel(completion_queue_put_value,
&ihost->smu_registers->completion_queue_put);
for (index = 0; index < SCU_MAX_COMPLETION_QUEUE_ENTRIES; index++) {
ihost->completion_queue[index] = 0x80000000;
}
}
static void sci_controller_initialize_unsolicited_frame_queue(struct isci_host *ihost)
{
u32 frame_queue_control_value;
u32 frame_queue_get_value;
u32 frame_queue_put_value;
frame_queue_control_value =
SCU_UFQC_GEN_VAL(QUEUE_SIZE, SCU_MAX_UNSOLICITED_FRAMES);
writel(frame_queue_control_value,
&ihost->scu_registers->sdma.unsolicited_frame_queue_control);
frame_queue_get_value = (
SCU_UFQGP_GEN_VAL(POINTER, 0)
| SCU_UFQGP_GEN_BIT(ENABLE_BIT)
);
writel(frame_queue_get_value,
&ihost->scu_registers->sdma.unsolicited_frame_get_pointer);
frame_queue_put_value = SCU_UFQPP_GEN_VAL(POINTER, 0);
writel(frame_queue_put_value,
&ihost->scu_registers->sdma.unsolicited_frame_put_pointer);
}
static void sci_controller_transition_to_ready(struct isci_host *ihost, enum sci_status status)
{
if (ihost->sm.current_state_id == SCIC_STARTING) {
sci_change_state(&ihost->sm, SCIC_READY);
isci_host_start_complete(ihost, status);
}
}
static bool is_phy_starting(struct isci_phy *iphy)
{
enum sci_phy_states state;
state = iphy->sm.current_state_id;
switch (state) {
case SCI_PHY_STARTING:
case SCI_PHY_SUB_INITIAL:
case SCI_PHY_SUB_AWAIT_SAS_SPEED_EN:
case SCI_PHY_SUB_AWAIT_IAF_UF:
case SCI_PHY_SUB_AWAIT_SAS_POWER:
case SCI_PHY_SUB_AWAIT_SATA_POWER:
case SCI_PHY_SUB_AWAIT_SATA_PHY_EN:
case SCI_PHY_SUB_AWAIT_SATA_SPEED_EN:
case SCI_PHY_SUB_AWAIT_SIG_FIS_UF:
case SCI_PHY_SUB_FINAL:
return true;
default:
return false;
}
}
static enum sci_status sci_controller_start_next_phy(struct isci_host *ihost)
{
struct sci_oem_params *oem = &ihost->oem_parameters;
struct isci_phy *iphy;
enum sci_status status;
status = SCI_SUCCESS;
if (ihost->phy_startup_timer_pending)
return status;
if (ihost->next_phy_to_start >= SCI_MAX_PHYS) {
bool is_controller_start_complete = true;
u32 state;
u8 index;
for (index = 0; index < SCI_MAX_PHYS; index++) {
iphy = &ihost->phys[index];
state = iphy->sm.current_state_id;
if (!phy_get_non_dummy_port(iphy))
continue;
if ((iphy->is_in_link_training == false && state == SCI_PHY_INITIAL) ||
(iphy->is_in_link_training == false && state == SCI_PHY_STOPPED) ||
(iphy->is_in_link_training == true && is_phy_starting(iphy))) {
is_controller_start_complete = false;
break;
}
}
if (is_controller_start_complete == true) {
sci_controller_transition_to_ready(ihost, SCI_SUCCESS);
sci_del_timer(&ihost->phy_timer);
ihost->phy_startup_timer_pending = false;
}
} else {
iphy = &ihost->phys[ihost->next_phy_to_start];
if (oem->controller.mode_type == SCIC_PORT_MANUAL_CONFIGURATION_MODE) {
if (phy_get_non_dummy_port(iphy) == NULL) {
ihost->next_phy_to_start++;
return sci_controller_start_next_phy(ihost);
}
}
status = sci_phy_start(iphy);
if (status == SCI_SUCCESS) {
sci_mod_timer(&ihost->phy_timer,
SCIC_SDS_CONTROLLER_PHY_START_TIMEOUT);
ihost->phy_startup_timer_pending = true;
} else {
dev_warn(&ihost->pdev->dev,
"%s: Controller stop operation failed "
"to stop phy %d because of status "
"%d.\n",
__func__,
ihost->phys[ihost->next_phy_to_start].phy_index,
status);
}
ihost->next_phy_to_start++;
}
return status;
}
static void phy_startup_timeout(unsigned long data)
{
struct sci_timer *tmr = (struct sci_timer *)data;
struct isci_host *ihost = container_of(tmr, typeof(*ihost), phy_timer);
unsigned long flags;
enum sci_status status;
spin_lock_irqsave(&ihost->scic_lock, flags);
if (tmr->cancel)
goto done;
ihost->phy_startup_timer_pending = false;
do {
status = sci_controller_start_next_phy(ihost);
} while (status != SCI_SUCCESS);
done:
spin_unlock_irqrestore(&ihost->scic_lock, flags);
}
static u16 isci_tci_active(struct isci_host *ihost)
{
return CIRC_CNT(ihost->tci_head, ihost->tci_tail, SCI_MAX_IO_REQUESTS);
}
static enum sci_status sci_controller_start(struct isci_host *ihost,
u32 timeout)
{
enum sci_status result;
u16 index;
if (ihost->sm.current_state_id != SCIC_INITIALIZED) {
dev_warn(&ihost->pdev->dev,
"SCIC Controller start operation requested in "
"invalid state\n");
return SCI_FAILURE_INVALID_STATE;
}
BUILD_BUG_ON(SCI_MAX_IO_REQUESTS > 1 << sizeof(ihost->tci_pool[0]) * 8);
ihost->tci_head = 0;
ihost->tci_tail = 0;
for (index = 0; index < ihost->task_context_entries; index++)
isci_tci_free(ihost, index);
sci_remote_node_table_initialize(&ihost->available_remote_nodes,
ihost->remote_node_entries);
sci_controller_disable_interrupts(ihost);
sci_controller_enable_port_task_scheduler(ihost);
sci_controller_assign_task_entries(ihost);
sci_controller_initialize_completion_queue(ihost);
sci_controller_initialize_unsolicited_frame_queue(ihost);
for (index = 0; index < ihost->logical_port_entries; index++) {
struct isci_port *iport = &ihost->ports[index];
result = sci_port_start(iport);
if (result)
return result;
}
sci_controller_start_next_phy(ihost);
sci_mod_timer(&ihost->timer, timeout);
sci_change_state(&ihost->sm, SCIC_STARTING);
return SCI_SUCCESS;
}
void isci_host_scan_start(struct Scsi_Host *shost)
{
struct isci_host *ihost = SHOST_TO_SAS_HA(shost)->lldd_ha;
unsigned long tmo = sci_controller_get_suggested_start_timeout(ihost);
set_bit(IHOST_START_PENDING, &ihost->flags);
spin_lock_irq(&ihost->scic_lock);
sci_controller_start(ihost, tmo);
sci_controller_enable_interrupts(ihost);
spin_unlock_irq(&ihost->scic_lock);
}
static void isci_host_stop_complete(struct isci_host *ihost, enum sci_status completion_status)
{
isci_host_change_state(ihost, isci_stopped);
sci_controller_disable_interrupts(ihost);
clear_bit(IHOST_STOP_PENDING, &ihost->flags);
wake_up(&ihost->eventq);
}
static void sci_controller_completion_handler(struct isci_host *ihost)
{
if (sci_controller_completion_queue_has_entries(ihost))
sci_controller_process_completions(ihost);
writel(SMU_ISR_COMPLETION, &ihost->smu_registers->interrupt_status);
writel(0xFF000000, &ihost->smu_registers->interrupt_mask);
writel(0, &ihost->smu_registers->interrupt_mask);
}
static void isci_host_completion_routine(unsigned long data)
{
struct isci_host *ihost = (struct isci_host *)data;
struct list_head completed_request_list;
struct list_head errored_request_list;
struct list_head *current_position;
struct list_head *next_position;
struct isci_request *request;
struct isci_request *next_request;
struct sas_task *task;
u16 active;
INIT_LIST_HEAD(&completed_request_list);
INIT_LIST_HEAD(&errored_request_list);
spin_lock_irq(&ihost->scic_lock);
sci_controller_completion_handler(ihost);
list_splice_init(&ihost->requests_to_complete,
&completed_request_list);
list_splice_init(&ihost->requests_to_errorback,
&errored_request_list);
spin_unlock_irq(&ihost->scic_lock);
list_for_each_safe(current_position, next_position,
&completed_request_list) {
request = list_entry(current_position, struct isci_request,
completed_node);
task = isci_request_access_task(request);
dev_dbg(&ihost->pdev->dev,
"%s: Normal - request/task = %p/%p\n",
__func__,
request,
task);
if (task != NULL) {
task->lldd_task = NULL;
if (!(task->task_state_flags & SAS_TASK_STATE_ABORTED)) {
task->task_done(task);
}
}
spin_lock_irq(&ihost->scic_lock);
isci_free_tag(ihost, request->io_tag);
spin_unlock_irq(&ihost->scic_lock);
}
list_for_each_entry_safe(request, next_request, &errored_request_list,
completed_node) {
task = isci_request_access_task(request);
dev_warn(&ihost->pdev->dev,
"%s: Error - request/task = %p/%p\n",
__func__,
request,
task);
if (task != NULL) {
if (!(task->task_state_flags & SAS_TASK_STATE_ABORTED))
sas_task_abort(task);
} else {
spin_lock_irq(&ihost->scic_lock);
list_del_init(&request->dev_node);
isci_free_tag(ihost, request->io_tag);
spin_unlock_irq(&ihost->scic_lock);
}
}
active = isci_tci_active(ihost);
writel(SMU_ICC_GEN_VAL(NUMBER, active) |
SMU_ICC_GEN_VAL(TIMER, ISCI_COALESCE_BASE + ilog2(active)),
&ihost->smu_registers->interrupt_coalesce_control);
}
static enum sci_status sci_controller_stop(struct isci_host *ihost, u32 timeout)
{
if (ihost->sm.current_state_id != SCIC_READY) {
dev_warn(&ihost->pdev->dev,
"SCIC Controller stop operation requested in "
"invalid state\n");
return SCI_FAILURE_INVALID_STATE;
}
sci_mod_timer(&ihost->timer, timeout);
sci_change_state(&ihost->sm, SCIC_STOPPING);
return SCI_SUCCESS;
}
static enum sci_status sci_controller_reset(struct isci_host *ihost)
{
switch (ihost->sm.current_state_id) {
case SCIC_RESET:
case SCIC_READY:
case SCIC_STOPPED:
case SCIC_FAILED:
sci_change_state(&ihost->sm, SCIC_RESETTING);
return SCI_SUCCESS;
default:
dev_warn(&ihost->pdev->dev,
"SCIC Controller reset operation requested in "
"invalid state\n");
return SCI_FAILURE_INVALID_STATE;
}
}
void isci_host_deinit(struct isci_host *ihost)
{
int i;
for (i = 0; i < isci_gpio_count(ihost); i++)
writel(SGPIO_HW_CONTROL, &ihost->scu_registers->peg0.sgpio.output_data_select[i]);
isci_host_change_state(ihost, isci_stopping);
for (i = 0; i < SCI_MAX_PORTS; i++) {
struct isci_port *iport = &ihost->ports[i];
struct isci_remote_device *idev, *d;
list_for_each_entry_safe(idev, d, &iport->remote_dev_list, node) {
if (test_bit(IDEV_ALLOCATED, &idev->flags))
isci_remote_device_stop(ihost, idev);
}
}
set_bit(IHOST_STOP_PENDING, &ihost->flags);
spin_lock_irq(&ihost->scic_lock);
sci_controller_stop(ihost, SCIC_CONTROLLER_STOP_TIMEOUT);
spin_unlock_irq(&ihost->scic_lock);
wait_for_stop(ihost);
writel(0, &ihost->scu_registers->peg0.sgpio.interface_control);
sci_controller_reset(ihost);
for (i = 0; i < ihost->logical_port_entries; i++) {
struct isci_port *iport = &ihost->ports[i];
del_timer_sync(&iport->timer.timer);
}
for (i = 0; i < SCI_MAX_PHYS; i++) {
struct isci_phy *iphy = &ihost->phys[i];
del_timer_sync(&iphy->sata_timer.timer);
}
del_timer_sync(&ihost->port_agent.timer.timer);
del_timer_sync(&ihost->power_control.timer.timer);
del_timer_sync(&ihost->timer.timer);
del_timer_sync(&ihost->phy_timer.timer);
}
static void __iomem *scu_base(struct isci_host *isci_host)
{
struct pci_dev *pdev = isci_host->pdev;
int id = isci_host->id;
return pcim_iomap_table(pdev)[SCI_SCU_BAR * 2] + SCI_SCU_BAR_SIZE * id;
}
static void __iomem *smu_base(struct isci_host *isci_host)
{
struct pci_dev *pdev = isci_host->pdev;
int id = isci_host->id;
return pcim_iomap_table(pdev)[SCI_SMU_BAR * 2] + SCI_SMU_BAR_SIZE * id;
}
static void isci_user_parameters_get(struct sci_user_parameters *u)
{
int i;
for (i = 0; i < SCI_MAX_PHYS; i++) {
struct sci_phy_user_params *u_phy = &u->phys[i];
u_phy->max_speed_generation = phy_gen;
u_phy->align_insertion_frequency = 0x7f;
u_phy->in_connection_align_insertion_frequency = 0xff;
u_phy->notify_enable_spin_up_insertion_frequency = 0x33;
}
u->stp_inactivity_timeout = stp_inactive_to;
u->ssp_inactivity_timeout = ssp_inactive_to;
u->stp_max_occupancy_timeout = stp_max_occ_to;
u->ssp_max_occupancy_timeout = ssp_max_occ_to;
u->no_outbound_task_timeout = no_outbound_task_to;
u->max_concurr_spinup = max_concurr_spinup;
}
static void sci_controller_initial_state_enter(struct sci_base_state_machine *sm)
{
struct isci_host *ihost = container_of(sm, typeof(*ihost), sm);
sci_change_state(&ihost->sm, SCIC_RESET);
}
static inline void sci_controller_starting_state_exit(struct sci_base_state_machine *sm)
{
struct isci_host *ihost = container_of(sm, typeof(*ihost), sm);
sci_del_timer(&ihost->timer);
}
static enum sci_status
sci_controller_set_interrupt_coalescence(struct isci_host *ihost,
u32 coalesce_number,
u32 coalesce_timeout)
{
u8 timeout_encode = 0;
u32 min = 0;
u32 max = 0;
if (coalesce_number > INTERRUPT_COALESCE_NUMBER_MAX)
return SCI_FAILURE_INVALID_PARAMETER_VALUE;
if (coalesce_timeout == 0)
timeout_encode = 0;
else{
coalesce_timeout = coalesce_timeout * 100;
min = INTERRUPT_COALESCE_TIMEOUT_BASE_RANGE_LOWER_BOUND_NS / 10;
max = INTERRUPT_COALESCE_TIMEOUT_BASE_RANGE_UPPER_BOUND_NS / 10;
for (timeout_encode = INTERRUPT_COALESCE_TIMEOUT_ENCODE_MIN;
timeout_encode <= INTERRUPT_COALESCE_TIMEOUT_ENCODE_MAX;
timeout_encode++) {
if (min <= coalesce_timeout && max > coalesce_timeout)
break;
else if (coalesce_timeout >= max && coalesce_timeout < min * 2
&& coalesce_timeout <= INTERRUPT_COALESCE_TIMEOUT_MAX_US * 100) {
if ((coalesce_timeout - max) < (2 * min - coalesce_timeout))
break;
else{
timeout_encode++;
break;
}
} else {
max = max * 2;
min = min * 2;
}
}
if (timeout_encode == INTERRUPT_COALESCE_TIMEOUT_ENCODE_MAX + 1)
return SCI_FAILURE_INVALID_PARAMETER_VALUE;
}
writel(SMU_ICC_GEN_VAL(NUMBER, coalesce_number) |
SMU_ICC_GEN_VAL(TIMER, timeout_encode),
&ihost->smu_registers->interrupt_coalesce_control);
ihost->interrupt_coalesce_number = (u16)coalesce_number;
ihost->interrupt_coalesce_timeout = coalesce_timeout / 100;
return SCI_SUCCESS;
}
static void sci_controller_ready_state_enter(struct sci_base_state_machine *sm)
{
struct isci_host *ihost = container_of(sm, typeof(*ihost), sm);
sci_controller_set_interrupt_coalescence(ihost, 0, 0);
}
static void sci_controller_ready_state_exit(struct sci_base_state_machine *sm)
{
struct isci_host *ihost = container_of(sm, typeof(*ihost), sm);
sci_controller_set_interrupt_coalescence(ihost, 0, 0);
}
static enum sci_status sci_controller_stop_phys(struct isci_host *ihost)
{
u32 index;
enum sci_status status;
enum sci_status phy_status;
status = SCI_SUCCESS;
for (index = 0; index < SCI_MAX_PHYS; index++) {
phy_status = sci_phy_stop(&ihost->phys[index]);
if (phy_status != SCI_SUCCESS &&
phy_status != SCI_FAILURE_INVALID_STATE) {
status = SCI_FAILURE;
dev_warn(&ihost->pdev->dev,
"%s: Controller stop operation failed to stop "
"phy %d because of status %d.\n",
__func__,
ihost->phys[index].phy_index, phy_status);
}
}
return status;
}
static enum sci_status sci_controller_stop_ports(struct isci_host *ihost)
{
u32 index;
enum sci_status port_status;
enum sci_status status = SCI_SUCCESS;
for (index = 0; index < ihost->logical_port_entries; index++) {
struct isci_port *iport = &ihost->ports[index];
port_status = sci_port_stop(iport);
if ((port_status != SCI_SUCCESS) &&
(port_status != SCI_FAILURE_INVALID_STATE)) {
status = SCI_FAILURE;
dev_warn(&ihost->pdev->dev,
"%s: Controller stop operation failed to "
"stop port %d because of status %d.\n",
__func__,
iport->logical_port_index,
port_status);
}
}
return status;
}
static enum sci_status sci_controller_stop_devices(struct isci_host *ihost)
{
u32 index;
enum sci_status status;
enum sci_status device_status;
status = SCI_SUCCESS;
for (index = 0; index < ihost->remote_node_entries; index++) {
if (ihost->device_table[index] != NULL) {
device_status = sci_remote_device_stop(ihost->device_table[index], 0);
if ((device_status != SCI_SUCCESS) &&
(device_status != SCI_FAILURE_INVALID_STATE)) {
dev_warn(&ihost->pdev->dev,
"%s: Controller stop operation failed "
"to stop device 0x%p because of "
"status %d.\n",
__func__,
ihost->device_table[index], device_status);
}
}
}
return status;
}
static void sci_controller_stopping_state_enter(struct sci_base_state_machine *sm)
{
struct isci_host *ihost = container_of(sm, typeof(*ihost), sm);
sci_controller_stop_phys(ihost);
sci_controller_stop_ports(ihost);
sci_controller_stop_devices(ihost);
}
static void sci_controller_stopping_state_exit(struct sci_base_state_machine *sm)
{
struct isci_host *ihost = container_of(sm, typeof(*ihost), sm);
sci_del_timer(&ihost->timer);
}
static void sci_controller_reset_hardware(struct isci_host *ihost)
{
sci_controller_disable_interrupts(ihost);
writel(0xFFFFFFFF, &ihost->smu_registers->soft_reset_control);
udelay(1000);
writel(0x00000000, &ihost->smu_registers->completion_queue_get);
writel(0, &ihost->scu_registers->sdma.unsolicited_frame_get_pointer);
}
static void sci_controller_resetting_state_enter(struct sci_base_state_machine *sm)
{
struct isci_host *ihost = container_of(sm, typeof(*ihost), sm);
sci_controller_reset_hardware(ihost);
sci_change_state(&ihost->sm, SCIC_RESET);
}
static void sci_controller_set_default_config_parameters(struct isci_host *ihost)
{
u16 index;
ihost->oem_parameters.controller.mode_type = SCIC_PORT_AUTOMATIC_CONFIGURATION_MODE;
ihost->oem_parameters.controller.max_concurr_spin_up = 1;
ihost->oem_parameters.controller.do_enable_ssc = false;
for (index = 0; index < SCI_MAX_PORTS; index++) {
ihost->oem_parameters.ports[index].phy_mask = 0;
}
for (index = 0; index < SCI_MAX_PHYS; index++) {
ihost->user_parameters.phys[index].max_speed_generation = 3;
ihost->user_parameters.phys[index].align_insertion_frequency = 0x7f;
ihost->user_parameters.phys[index].in_connection_align_insertion_frequency = 0xff;
ihost->user_parameters.phys[index].notify_enable_spin_up_insertion_frequency = 0x33;
ihost->oem_parameters.phys[index].sas_address.low = 0x1 + ihost->id;
ihost->oem_parameters.phys[index].sas_address.high = 0x5FCFFFFF;
}
ihost->user_parameters.stp_inactivity_timeout = 5;
ihost->user_parameters.ssp_inactivity_timeout = 5;
ihost->user_parameters.stp_max_occupancy_timeout = 5;
ihost->user_parameters.ssp_max_occupancy_timeout = 20;
ihost->user_parameters.no_outbound_task_timeout = 20;
}
static void controller_timeout(unsigned long data)
{
struct sci_timer *tmr = (struct sci_timer *)data;
struct isci_host *ihost = container_of(tmr, typeof(*ihost), timer);
struct sci_base_state_machine *sm = &ihost->sm;
unsigned long flags;
spin_lock_irqsave(&ihost->scic_lock, flags);
if (tmr->cancel)
goto done;
if (sm->current_state_id == SCIC_STARTING)
sci_controller_transition_to_ready(ihost, SCI_FAILURE_TIMEOUT);
else if (sm->current_state_id == SCIC_STOPPING) {
sci_change_state(sm, SCIC_FAILED);
isci_host_stop_complete(ihost, SCI_FAILURE_TIMEOUT);
} else
dev_err(&ihost->pdev->dev,
"%s: Controller timer fired when controller was not "
"in a state being timed.\n",
__func__);
done:
spin_unlock_irqrestore(&ihost->scic_lock, flags);
}
static enum sci_status sci_controller_construct(struct isci_host *ihost,
void __iomem *scu_base,
void __iomem *smu_base)
{
u8 i;
sci_init_sm(&ihost->sm, sci_controller_state_table, SCIC_INITIAL);
ihost->scu_registers = scu_base;
ihost->smu_registers = smu_base;
sci_port_configuration_agent_construct(&ihost->port_agent);
for (i = 0; i < SCI_MAX_PORTS; i++)
sci_port_construct(&ihost->ports[i], i, ihost);
sci_port_construct(&ihost->ports[i], SCIC_SDS_DUMMY_PORT, ihost);
for (i = 0; i < SCI_MAX_PHYS; i++) {
sci_phy_construct(&ihost->phys[i],
&ihost->ports[SCI_MAX_PORTS], i);
}
ihost->invalid_phy_mask = 0;
sci_init_timer(&ihost->timer, controller_timeout);
sci_controller_set_default_config_parameters(ihost);
return sci_controller_reset(ihost);
}
int sci_oem_parameters_validate(struct sci_oem_params *oem)
{
int i;
for (i = 0; i < SCI_MAX_PORTS; i++)
if (oem->ports[i].phy_mask > SCIC_SDS_PARM_PHY_MASK_MAX)
return -EINVAL;
for (i = 0; i < SCI_MAX_PHYS; i++)
if (oem->phys[i].sas_address.high == 0 &&
oem->phys[i].sas_address.low == 0)
return -EINVAL;
if (oem->controller.mode_type == SCIC_PORT_AUTOMATIC_CONFIGURATION_MODE) {
for (i = 0; i < SCI_MAX_PHYS; i++)
if (oem->ports[i].phy_mask != 0)
return -EINVAL;
} else if (oem->controller.mode_type == SCIC_PORT_MANUAL_CONFIGURATION_MODE) {
u8 phy_mask = 0;
for (i = 0; i < SCI_MAX_PHYS; i++)
phy_mask |= oem->ports[i].phy_mask;
if (phy_mask == 0)
return -EINVAL;
} else
return -EINVAL;
if (oem->controller.max_concurr_spin_up > MAX_CONCURRENT_DEVICE_SPIN_UP_COUNT ||
oem->controller.max_concurr_spin_up < 1)
return -EINVAL;
return 0;
}
static enum sci_status sci_oem_parameters_set(struct isci_host *ihost)
{
u32 state = ihost->sm.current_state_id;
if (state == SCIC_RESET ||
state == SCIC_INITIALIZING ||
state == SCIC_INITIALIZED) {
if (sci_oem_parameters_validate(&ihost->oem_parameters))
return SCI_FAILURE_INVALID_PARAMETER_VALUE;
return SCI_SUCCESS;
}
return SCI_FAILURE_INVALID_STATE;
}
static u8 max_spin_up(struct isci_host *ihost)
{
if (ihost->user_parameters.max_concurr_spinup)
return min_t(u8, ihost->user_parameters.max_concurr_spinup,
MAX_CONCURRENT_DEVICE_SPIN_UP_COUNT);
else
return min_t(u8, ihost->oem_parameters.controller.max_concurr_spin_up,
MAX_CONCURRENT_DEVICE_SPIN_UP_COUNT);
}
static void power_control_timeout(unsigned long data)
{
struct sci_timer *tmr = (struct sci_timer *)data;
struct isci_host *ihost = container_of(tmr, typeof(*ihost), power_control.timer);
struct isci_phy *iphy;
unsigned long flags;
u8 i;
spin_lock_irqsave(&ihost->scic_lock, flags);
if (tmr->cancel)
goto done;
ihost->power_control.phys_granted_power = 0;
if (ihost->power_control.phys_waiting == 0) {
ihost->power_control.timer_started = false;
goto done;
}
for (i = 0; i < SCI_MAX_PHYS; i++) {
if (ihost->power_control.phys_waiting == 0)
break;
iphy = ihost->power_control.requesters[i];
if (iphy == NULL)
continue;
if (ihost->power_control.phys_granted_power >= max_spin_up(ihost))
break;
ihost->power_control.requesters[i] = NULL;
ihost->power_control.phys_waiting--;
ihost->power_control.phys_granted_power++;
sci_phy_consume_power_handler(iphy);
}
sci_mod_timer(tmr, SCIC_SDS_CONTROLLER_POWER_CONTROL_INTERVAL);
ihost->power_control.timer_started = true;
done:
spin_unlock_irqrestore(&ihost->scic_lock, flags);
}
void sci_controller_power_control_queue_insert(struct isci_host *ihost,
struct isci_phy *iphy)
{
BUG_ON(iphy == NULL);
if (ihost->power_control.phys_granted_power < max_spin_up(ihost)) {
ihost->power_control.phys_granted_power++;
sci_phy_consume_power_handler(iphy);
if (ihost->power_control.timer_started)
sci_del_timer(&ihost->power_control.timer);
sci_mod_timer(&ihost->power_control.timer,
SCIC_SDS_CONTROLLER_POWER_CONTROL_INTERVAL);
ihost->power_control.timer_started = true;
} else {
ihost->power_control.requesters[iphy->phy_index] = iphy;
ihost->power_control.phys_waiting++;
}
}
void sci_controller_power_control_queue_remove(struct isci_host *ihost,
struct isci_phy *iphy)
{
BUG_ON(iphy == NULL);
if (ihost->power_control.requesters[iphy->phy_index])
ihost->power_control.phys_waiting--;
ihost->power_control.requesters[iphy->phy_index] = NULL;
}
static void sci_controller_afe_initialization(struct isci_host *ihost)
{
const struct sci_oem_params *oem = &ihost->oem_parameters;
struct pci_dev *pdev = ihost->pdev;
u32 afe_status;
u32 phy_id;
writel(0x0081000f, &ihost->scu_registers->afe.afe_dfx_master_control0);
udelay(AFE_REGISTER_WRITE_DELAY);
if (is_b0(pdev)) {
writel(0x0007BFFF, &ihost->scu_registers->afe.afe_pmsn_master_control2);
udelay(AFE_REGISTER_WRITE_DELAY);
}
if (is_a2(pdev))
writel(0x00005A00, &ihost->scu_registers->afe.afe_bias_control);
else if (is_b0(pdev) || is_c0(pdev))
writel(0x00005F00, &ihost->scu_registers->afe.afe_bias_control);
udelay(AFE_REGISTER_WRITE_DELAY);
if (is_b0(pdev) || is_c0(pdev))
writel(0x80040A08, &ihost->scu_registers->afe.afe_pll_control0);
else
writel(0x80040908, &ihost->scu_registers->afe.afe_pll_control0);
udelay(AFE_REGISTER_WRITE_DELAY);
do {
afe_status = readl(&ihost->scu_registers->afe.afe_common_block_status);
udelay(AFE_REGISTER_WRITE_DELAY);
} while ((afe_status & 0x00001000) == 0);
if (is_a2(pdev)) {
writel(0x7bcc96ad, &ihost->scu_registers->afe.afe_pmsn_master_control0);
udelay(AFE_REGISTER_WRITE_DELAY);
}
for (phy_id = 0; phy_id < SCI_MAX_PHYS; phy_id++) {
const struct sci_phy_oem_params *oem_phy = &oem->phys[phy_id];
if (is_b0(pdev)) {
writel(0x00030000, &ihost->scu_registers->afe.scu_afe_xcvr[phy_id].afe_tx_ssc_control);
udelay(AFE_REGISTER_WRITE_DELAY);
} else if (is_c0(pdev)) {
writel(0x0003000, &ihost->scu_registers->afe.scu_afe_xcvr[phy_id].afe_tx_ssc_control);
udelay(AFE_REGISTER_WRITE_DELAY);
writel(0x00004500, &ihost->scu_registers->afe.scu_afe_xcvr[phy_id].afe_xcvr_control0);
udelay(AFE_REGISTER_WRITE_DELAY);
} else {
writel(0x00004512, &ihost->scu_registers->afe.scu_afe_xcvr[phy_id].afe_xcvr_control0);
udelay(AFE_REGISTER_WRITE_DELAY);
writel(0x0050100F, &ihost->scu_registers->afe.scu_afe_xcvr[phy_id].afe_xcvr_control1);
udelay(AFE_REGISTER_WRITE_DELAY);
}
if (is_a2(pdev))
writel(0x000003F0, &ihost->scu_registers->afe.scu_afe_xcvr[phy_id].afe_channel_control);
else if (is_b0(pdev)) {
writel(0x000003D7, &ihost->scu_registers->afe.scu_afe_xcvr[phy_id].afe_channel_control);
udelay(AFE_REGISTER_WRITE_DELAY);
writel(0x000003D4, &ihost->scu_registers->afe.scu_afe_xcvr[phy_id].afe_channel_control);
} else {
writel(0x000001E7, &ihost->scu_registers->afe.scu_afe_xcvr[phy_id].afe_channel_control);
udelay(AFE_REGISTER_WRITE_DELAY);
writel(0x000001E4, &ihost->scu_registers->afe.scu_afe_xcvr[phy_id].afe_channel_control);
}
udelay(AFE_REGISTER_WRITE_DELAY);
if (is_a2(pdev)) {
writel(0x00040000, &ihost->scu_registers->afe.scu_afe_xcvr[phy_id].afe_tx_control);
udelay(AFE_REGISTER_WRITE_DELAY);
}
writel(0x00004100, &ihost->scu_registers->afe.scu_afe_xcvr[phy_id].afe_xcvr_control0);
udelay(AFE_REGISTER_WRITE_DELAY);
if (is_a2(pdev))
writel(0x3F11103F, &ihost->scu_registers->afe.scu_afe_xcvr[phy_id].afe_rx_ssc_control0);
else if (is_b0(pdev)) {
writel(0x3F11103F, &ihost->scu_registers->afe.scu_afe_xcvr[phy_id].afe_rx_ssc_control0);
udelay(AFE_REGISTER_WRITE_DELAY);
writel(0x00040000, &ihost->scu_registers->afe.scu_afe_xcvr[phy_id].afe_tx_control);
} else {
writel(0x0140DF0F, &ihost->scu_registers->afe.scu_afe_xcvr[phy_id].afe_rx_ssc_control1);
udelay(AFE_REGISTER_WRITE_DELAY);
writel(0x3F6F103F, &ihost->scu_registers->afe.scu_afe_xcvr[phy_id].afe_rx_ssc_control0);
udelay(AFE_REGISTER_WRITE_DELAY);
writel(0x00040000, &ihost->scu_registers->afe.scu_afe_xcvr[phy_id].afe_tx_control);
}
udelay(AFE_REGISTER_WRITE_DELAY);
writel(oem_phy->afe_tx_amp_control0,
&ihost->scu_registers->afe.scu_afe_xcvr[phy_id].afe_tx_amp_control0);
udelay(AFE_REGISTER_WRITE_DELAY);
writel(oem_phy->afe_tx_amp_control1,
&ihost->scu_registers->afe.scu_afe_xcvr[phy_id].afe_tx_amp_control1);
udelay(AFE_REGISTER_WRITE_DELAY);
writel(oem_phy->afe_tx_amp_control2,
&ihost->scu_registers->afe.scu_afe_xcvr[phy_id].afe_tx_amp_control2);
udelay(AFE_REGISTER_WRITE_DELAY);
writel(oem_phy->afe_tx_amp_control3,
&ihost->scu_registers->afe.scu_afe_xcvr[phy_id].afe_tx_amp_control3);
udelay(AFE_REGISTER_WRITE_DELAY);
}
writel(0x00010f00, &ihost->scu_registers->afe.afe_dfx_master_control0);
udelay(AFE_REGISTER_WRITE_DELAY);
}
static void sci_controller_initialize_power_control(struct isci_host *ihost)
{
sci_init_timer(&ihost->power_control.timer, power_control_timeout);
memset(ihost->power_control.requesters, 0,
sizeof(ihost->power_control.requesters));
ihost->power_control.phys_waiting = 0;
ihost->power_control.phys_granted_power = 0;
}
static enum sci_status sci_controller_initialize(struct isci_host *ihost)
{
struct sci_base_state_machine *sm = &ihost->sm;
enum sci_status result = SCI_FAILURE;
unsigned long i, state, val;
if (ihost->sm.current_state_id != SCIC_RESET) {
dev_warn(&ihost->pdev->dev,
"SCIC Controller initialize operation requested "
"in invalid state\n");
return SCI_FAILURE_INVALID_STATE;
}
sci_change_state(sm, SCIC_INITIALIZING);
sci_init_timer(&ihost->phy_timer, phy_startup_timeout);
ihost->next_phy_to_start = 0;
ihost->phy_startup_timer_pending = false;
sci_controller_initialize_power_control(ihost);
sci_controller_afe_initialization(ihost);
writel(0, &ihost->smu_registers->soft_reset_control);
for (i = 100; i >= 1; i--) {
u32 status;
udelay(SCU_CONTEXT_RAM_INIT_STALL_TIME);
status = readl(&ihost->smu_registers->control_status);
if ((status & SCU_RAM_INIT_COMPLETED) == SCU_RAM_INIT_COMPLETED)
break;
}
if (i == 0)
goto out;
val = readl(&ihost->smu_registers->device_context_capacity);
ihost->logical_port_entries = min(smu_max_ports(val), SCI_MAX_PORTS);
ihost->task_context_entries = min(smu_max_task_contexts(val), SCI_MAX_IO_REQUESTS);
ihost->remote_node_entries = min(smu_max_rncs(val), SCI_MAX_REMOTE_DEVICES);
for (i = 0; i < ihost->logical_port_entries; i++) {
struct scu_port_task_scheduler_group_registers __iomem
*ptsg = &ihost->scu_registers->peg0.ptsg;
writel(i, &ptsg->protocol_engine[i]);
}
val = readl(&ihost->scu_registers->sdma.pdma_configuration);
val |= SCU_PDMACR_GEN_BIT(PCI_RELAXED_ORDERING_ENABLE);
writel(val, &ihost->scu_registers->sdma.pdma_configuration);
val = readl(&ihost->scu_registers->sdma.cdma_configuration);
val |= SCU_CDMACR_GEN_BIT(PCI_RELAXED_ORDERING_ENABLE);
writel(val, &ihost->scu_registers->sdma.cdma_configuration);
for (i = 0; i < SCI_MAX_PHYS; i++) {
result = sci_phy_initialize(&ihost->phys[i],
&ihost->scu_registers->peg0.pe[i].tl,
&ihost->scu_registers->peg0.pe[i].ll);
if (result != SCI_SUCCESS)
goto out;
}
for (i = 0; i < ihost->logical_port_entries; i++) {
struct isci_port *iport = &ihost->ports[i];
iport->port_task_scheduler_registers = &ihost->scu_registers->peg0.ptsg.port[i];
iport->port_pe_configuration_register = &ihost->scu_registers->peg0.ptsg.protocol_engine[0];
iport->viit_registers = &ihost->scu_registers->peg0.viit[i];
}
result = sci_port_configuration_agent_initialize(ihost, &ihost->port_agent);
out:
if (result == SCI_SUCCESS)
state = SCIC_INITIALIZED;
else
state = SCIC_FAILED;
sci_change_state(sm, state);
return result;
}
static enum sci_status sci_user_parameters_set(struct isci_host *ihost,
struct sci_user_parameters *sci_parms)
{
u32 state = ihost->sm.current_state_id;
if (state == SCIC_RESET ||
state == SCIC_INITIALIZING ||
state == SCIC_INITIALIZED) {
u16 index;
for (index = 0; index < SCI_MAX_PHYS; index++) {
struct sci_phy_user_params *user_phy;
user_phy = &sci_parms->phys[index];
if (!((user_phy->max_speed_generation <=
SCIC_SDS_PARM_MAX_SPEED) &&
(user_phy->max_speed_generation >
SCIC_SDS_PARM_NO_SPEED)))
return SCI_FAILURE_INVALID_PARAMETER_VALUE;
if (user_phy->in_connection_align_insertion_frequency <
3)
return SCI_FAILURE_INVALID_PARAMETER_VALUE;
if ((user_phy->in_connection_align_insertion_frequency <
3) ||
(user_phy->align_insertion_frequency == 0) ||
(user_phy->
notify_enable_spin_up_insertion_frequency ==
0))
return SCI_FAILURE_INVALID_PARAMETER_VALUE;
}
if ((sci_parms->stp_inactivity_timeout == 0) ||
(sci_parms->ssp_inactivity_timeout == 0) ||
(sci_parms->stp_max_occupancy_timeout == 0) ||
(sci_parms->ssp_max_occupancy_timeout == 0) ||
(sci_parms->no_outbound_task_timeout == 0))
return SCI_FAILURE_INVALID_PARAMETER_VALUE;
memcpy(&ihost->user_parameters, sci_parms, sizeof(*sci_parms));
return SCI_SUCCESS;
}
return SCI_FAILURE_INVALID_STATE;
}
static int sci_controller_mem_init(struct isci_host *ihost)
{
struct device *dev = &ihost->pdev->dev;
dma_addr_t dma;
size_t size;
int err;
size = SCU_MAX_COMPLETION_QUEUE_ENTRIES * sizeof(u32);
ihost->completion_queue = dmam_alloc_coherent(dev, size, &dma, GFP_KERNEL);
if (!ihost->completion_queue)
return -ENOMEM;
writel(lower_32_bits(dma), &ihost->smu_registers->completion_queue_lower);
writel(upper_32_bits(dma), &ihost->smu_registers->completion_queue_upper);
size = ihost->remote_node_entries * sizeof(union scu_remote_node_context);
ihost->remote_node_context_table = dmam_alloc_coherent(dev, size, &dma,
GFP_KERNEL);
if (!ihost->remote_node_context_table)
return -ENOMEM;
writel(lower_32_bits(dma), &ihost->smu_registers->remote_node_context_lower);
writel(upper_32_bits(dma), &ihost->smu_registers->remote_node_context_upper);
size = ihost->task_context_entries * sizeof(struct scu_task_context),
ihost->task_context_table = dmam_alloc_coherent(dev, size, &dma, GFP_KERNEL);
if (!ihost->task_context_table)
return -ENOMEM;
ihost->task_context_dma = dma;
writel(lower_32_bits(dma), &ihost->smu_registers->host_task_table_lower);
writel(upper_32_bits(dma), &ihost->smu_registers->host_task_table_upper);
err = sci_unsolicited_frame_control_construct(ihost);
if (err)
return err;
writel(lower_32_bits(ihost->uf_control.headers.physical_address),
&ihost->scu_registers->sdma.uf_header_base_address_lower);
writel(upper_32_bits(ihost->uf_control.headers.physical_address),
&ihost->scu_registers->sdma.uf_header_base_address_upper);
writel(lower_32_bits(ihost->uf_control.address_table.physical_address),
&ihost->scu_registers->sdma.uf_address_table_lower);
writel(upper_32_bits(ihost->uf_control.address_table.physical_address),
&ihost->scu_registers->sdma.uf_address_table_upper);
return 0;
}
int isci_host_init(struct isci_host *ihost)
{
int err = 0, i;
enum sci_status status;
struct sci_user_parameters sci_user_params;
struct isci_pci_info *pci_info = to_pci_info(ihost->pdev);
spin_lock_init(&ihost->state_lock);
spin_lock_init(&ihost->scic_lock);
init_waitqueue_head(&ihost->eventq);
isci_host_change_state(ihost, isci_starting);
status = sci_controller_construct(ihost, scu_base(ihost),
smu_base(ihost));
if (status != SCI_SUCCESS) {
dev_err(&ihost->pdev->dev,
"%s: sci_controller_construct failed - status = %x\n",
__func__,
status);
return -ENODEV;
}
ihost->sas_ha.dev = &ihost->pdev->dev;
ihost->sas_ha.lldd_ha = ihost;
isci_user_parameters_get(&sci_user_params);
status = sci_user_parameters_set(ihost, &sci_user_params);
if (status != SCI_SUCCESS) {
dev_warn(&ihost->pdev->dev,
"%s: sci_user_parameters_set failed\n",
__func__);
return -ENODEV;
}
if (pci_info->orom) {
status = isci_parse_oem_parameters(&ihost->oem_parameters,
pci_info->orom,
ihost->id);
if (status != SCI_SUCCESS) {
dev_warn(&ihost->pdev->dev,
"parsing firmware oem parameters failed\n");
return -EINVAL;
}
}
status = sci_oem_parameters_set(ihost);
if (status != SCI_SUCCESS) {
dev_warn(&ihost->pdev->dev,
"%s: sci_oem_parameters_set failed\n",
__func__);
return -ENODEV;
}
tasklet_init(&ihost->completion_tasklet,
isci_host_completion_routine, (unsigned long)ihost);
INIT_LIST_HEAD(&ihost->requests_to_complete);
INIT_LIST_HEAD(&ihost->requests_to_errorback);
spin_lock_irq(&ihost->scic_lock);
status = sci_controller_initialize(ihost);
spin_unlock_irq(&ihost->scic_lock);
if (status != SCI_SUCCESS) {
dev_warn(&ihost->pdev->dev,
"%s: sci_controller_initialize failed -"
" status = 0x%x\n",
__func__, status);
return -ENODEV;
}
err = sci_controller_mem_init(ihost);
if (err)
return err;
for (i = 0; i < SCI_MAX_PORTS; i++)
isci_port_init(&ihost->ports[i], ihost, i);
for (i = 0; i < SCI_MAX_PHYS; i++)
isci_phy_init(&ihost->phys[i], ihost, i);
writel(1, &ihost->scu_registers->peg0.sgpio.interface_control);
for (i = 0; i < isci_gpio_count(ihost); i++)
writel(SGPIO_HW_CONTROL, &ihost->scu_registers->peg0.sgpio.output_data_select[i]);
writel(0, &ihost->scu_registers->peg0.sgpio.vendor_specific_code);
for (i = 0; i < SCI_MAX_REMOTE_DEVICES; i++) {
struct isci_remote_device *idev = &ihost->devices[i];
INIT_LIST_HEAD(&idev->reqs_in_process);
INIT_LIST_HEAD(&idev->node);
}
for (i = 0; i < SCI_MAX_IO_REQUESTS; i++) {
struct isci_request *ireq;
dma_addr_t dma;
ireq = dmam_alloc_coherent(&ihost->pdev->dev,
sizeof(struct isci_request), &dma,
GFP_KERNEL);
if (!ireq)
return -ENOMEM;
ireq->tc = &ihost->task_context_table[i];
ireq->owning_controller = ihost;
spin_lock_init(&ireq->state_lock);
ireq->request_daddr = dma;
ireq->isci_host = ihost;
ihost->reqs[i] = ireq;
}
return 0;
}
void sci_controller_link_up(struct isci_host *ihost, struct isci_port *iport,
struct isci_phy *iphy)
{
switch (ihost->sm.current_state_id) {
case SCIC_STARTING:
sci_del_timer(&ihost->phy_timer);
ihost->phy_startup_timer_pending = false;
ihost->port_agent.link_up_handler(ihost, &ihost->port_agent,
iport, iphy);
sci_controller_start_next_phy(ihost);
break;
case SCIC_READY:
ihost->port_agent.link_up_handler(ihost, &ihost->port_agent,
iport, iphy);
break;
default:
dev_dbg(&ihost->pdev->dev,
"%s: SCIC Controller linkup event from phy %d in "
"unexpected state %d\n", __func__, iphy->phy_index,
ihost->sm.current_state_id);
}
}
void sci_controller_link_down(struct isci_host *ihost, struct isci_port *iport,
struct isci_phy *iphy)
{
switch (ihost->sm.current_state_id) {
case SCIC_STARTING:
case SCIC_READY:
ihost->port_agent.link_down_handler(ihost, &ihost->port_agent,
iport, iphy);
break;
default:
dev_dbg(&ihost->pdev->dev,
"%s: SCIC Controller linkdown event from phy %d in "
"unexpected state %d\n",
__func__,
iphy->phy_index,
ihost->sm.current_state_id);
}
}
static bool sci_controller_has_remote_devices_stopping(struct isci_host *ihost)
{
u32 index;
for (index = 0; index < ihost->remote_node_entries; index++) {
if ((ihost->device_table[index] != NULL) &&
(ihost->device_table[index]->sm.current_state_id == SCI_DEV_STOPPING))
return true;
}
return false;
}
void sci_controller_remote_device_stopped(struct isci_host *ihost,
struct isci_remote_device *idev)
{
if (ihost->sm.current_state_id != SCIC_STOPPING) {
dev_dbg(&ihost->pdev->dev,
"SCIC Controller 0x%p remote device stopped event "
"from device 0x%p in unexpected state %d\n",
ihost, idev,
ihost->sm.current_state_id);
return;
}
if (!sci_controller_has_remote_devices_stopping(ihost))
sci_change_state(&ihost->sm, SCIC_STOPPED);
}
void sci_controller_post_request(struct isci_host *ihost, u32 request)
{
dev_dbg(&ihost->pdev->dev, "%s[%d]: %#x\n",
__func__, ihost->id, request);
writel(request, &ihost->smu_registers->post_context_port);
}
struct isci_request *sci_request_by_tag(struct isci_host *ihost, u16 io_tag)
{
u16 task_index;
u16 task_sequence;
task_index = ISCI_TAG_TCI(io_tag);
if (task_index < ihost->task_context_entries) {
struct isci_request *ireq = ihost->reqs[task_index];
if (test_bit(IREQ_ACTIVE, &ireq->flags)) {
task_sequence = ISCI_TAG_SEQ(io_tag);
if (task_sequence == ihost->io_request_sequence[task_index])
return ireq;
}
}
return NULL;
}
enum sci_status sci_controller_allocate_remote_node_context(struct isci_host *ihost,
struct isci_remote_device *idev,
u16 *node_id)
{
u16 node_index;
u32 remote_node_count = sci_remote_device_node_count(idev);
node_index = sci_remote_node_table_allocate_remote_node(
&ihost->available_remote_nodes, remote_node_count
);
if (node_index != SCIC_SDS_REMOTE_NODE_CONTEXT_INVALID_INDEX) {
ihost->device_table[node_index] = idev;
*node_id = node_index;
return SCI_SUCCESS;
}
return SCI_FAILURE_INSUFFICIENT_RESOURCES;
}
void sci_controller_free_remote_node_context(struct isci_host *ihost,
struct isci_remote_device *idev,
u16 node_id)
{
u32 remote_node_count = sci_remote_device_node_count(idev);
if (ihost->device_table[node_id] == idev) {
ihost->device_table[node_id] = NULL;
sci_remote_node_table_release_remote_node_index(
&ihost->available_remote_nodes, remote_node_count, node_id
);
}
}
void sci_controller_copy_sata_response(void *response_buffer,
void *frame_header,
void *frame_buffer)
{
memcpy(response_buffer, frame_header, sizeof(u32));
memcpy(response_buffer + sizeof(u32),
frame_buffer,
sizeof(struct dev_to_host_fis) - sizeof(u32));
}
void sci_controller_release_frame(struct isci_host *ihost, u32 frame_index)
{
if (sci_unsolicited_frame_control_release_frame(&ihost->uf_control, frame_index))
writel(ihost->uf_control.get,
&ihost->scu_registers->sdma.unsolicited_frame_get_pointer);
}
void isci_tci_free(struct isci_host *ihost, u16 tci)
{
u16 tail = ihost->tci_tail & (SCI_MAX_IO_REQUESTS-1);
ihost->tci_pool[tail] = tci;
ihost->tci_tail = tail + 1;
}
static u16 isci_tci_alloc(struct isci_host *ihost)
{
u16 head = ihost->tci_head & (SCI_MAX_IO_REQUESTS-1);
u16 tci = ihost->tci_pool[head];
ihost->tci_head = head + 1;
return tci;
}
static u16 isci_tci_space(struct isci_host *ihost)
{
return CIRC_SPACE(ihost->tci_head, ihost->tci_tail, SCI_MAX_IO_REQUESTS);
}
u16 isci_alloc_tag(struct isci_host *ihost)
{
if (isci_tci_space(ihost)) {
u16 tci = isci_tci_alloc(ihost);
u8 seq = ihost->io_request_sequence[tci];
return ISCI_TAG(seq, tci);
}
return SCI_CONTROLLER_INVALID_IO_TAG;
}
enum sci_status isci_free_tag(struct isci_host *ihost, u16 io_tag)
{
u16 tci = ISCI_TAG_TCI(io_tag);
u16 seq = ISCI_TAG_SEQ(io_tag);
if (isci_tci_active(ihost) == 0)
return SCI_FAILURE_INVALID_IO_TAG;
if (seq == ihost->io_request_sequence[tci]) {
ihost->io_request_sequence[tci] = (seq+1) & (SCI_MAX_SEQ-1);
isci_tci_free(ihost, tci);
return SCI_SUCCESS;
}
return SCI_FAILURE_INVALID_IO_TAG;
}
enum sci_status sci_controller_start_io(struct isci_host *ihost,
struct isci_remote_device *idev,
struct isci_request *ireq)
{
enum sci_status status;
if (ihost->sm.current_state_id != SCIC_READY) {
dev_warn(&ihost->pdev->dev, "invalid state to start I/O");
return SCI_FAILURE_INVALID_STATE;
}
status = sci_remote_device_start_io(ihost, idev, ireq);
if (status != SCI_SUCCESS)
return status;
set_bit(IREQ_ACTIVE, &ireq->flags);
sci_controller_post_request(ihost, ireq->post_context);
return SCI_SUCCESS;
}
enum sci_status sci_controller_terminate_request(struct isci_host *ihost,
struct isci_remote_device *idev,
struct isci_request *ireq)
{
enum sci_status status;
if (ihost->sm.current_state_id != SCIC_READY) {
dev_warn(&ihost->pdev->dev,
"invalid state to terminate request\n");
return SCI_FAILURE_INVALID_STATE;
}
status = sci_io_request_terminate(ireq);
if (status != SCI_SUCCESS)
return status;
sci_controller_post_request(ihost,
ireq->post_context | SCU_CONTEXT_COMMAND_REQUEST_POST_TC_ABORT);
return SCI_SUCCESS;
}
enum sci_status sci_controller_complete_io(struct isci_host *ihost,
struct isci_remote_device *idev,
struct isci_request *ireq)
{
enum sci_status status;
u16 index;
switch (ihost->sm.current_state_id) {
case SCIC_STOPPING:
return SCI_FAILURE;
case SCIC_READY:
status = sci_remote_device_complete_io(ihost, idev, ireq);
if (status != SCI_SUCCESS)
return status;
index = ISCI_TAG_TCI(ireq->io_tag);
clear_bit(IREQ_ACTIVE, &ireq->flags);
return SCI_SUCCESS;
default:
dev_warn(&ihost->pdev->dev, "invalid state to complete I/O");
return SCI_FAILURE_INVALID_STATE;
}
}
enum sci_status sci_controller_continue_io(struct isci_request *ireq)
{
struct isci_host *ihost = ireq->owning_controller;
if (ihost->sm.current_state_id != SCIC_READY) {
dev_warn(&ihost->pdev->dev, "invalid state to continue I/O");
return SCI_FAILURE_INVALID_STATE;
}
set_bit(IREQ_ACTIVE, &ireq->flags);
sci_controller_post_request(ihost, ireq->post_context);
return SCI_SUCCESS;
}
enum sci_task_status sci_controller_start_task(struct isci_host *ihost,
struct isci_remote_device *idev,
struct isci_request *ireq)
{
enum sci_status status;
if (ihost->sm.current_state_id != SCIC_READY) {
dev_warn(&ihost->pdev->dev,
"%s: SCIC Controller starting task from invalid "
"state\n",
__func__);
return SCI_TASK_FAILURE_INVALID_STATE;
}
status = sci_remote_device_start_task(ihost, idev, ireq);
switch (status) {
case SCI_FAILURE_RESET_DEVICE_PARTIAL_SUCCESS:
set_bit(IREQ_ACTIVE, &ireq->flags);
return SCI_SUCCESS;
case SCI_SUCCESS:
set_bit(IREQ_ACTIVE, &ireq->flags);
sci_controller_post_request(ihost, ireq->post_context);
break;
default:
break;
}
return status;
}
static int sci_write_gpio_tx_gp(struct isci_host *ihost, u8 reg_index, u8 reg_count, u8 *write_data)
{
int d;
if (reg_index == 0)
return -EINVAL;
for (d = 0; d < isci_gpio_count(ihost); d++) {
u32 val = 0x444;
int i;
for (i = 0; i < 3; i++) {
int bit = (i << 2) + 2;
bit = try_test_sas_gpio_gp_bit(to_sas_gpio_od(d, i),
write_data, reg_index,
reg_count);
if (bit < 0)
break;
val &= ~(bit << ((i << 2) + 2));
}
if (i < 3)
break;
writel(val, &ihost->scu_registers->peg0.sgpio.output_data_select[d]);
}
return d > 0;
}
int isci_gpio_write(struct sas_ha_struct *sas_ha, u8 reg_type, u8 reg_index,
u8 reg_count, u8 *write_data)
{
struct isci_host *ihost = sas_ha->lldd_ha;
int written;
switch (reg_type) {
case SAS_GPIO_REG_TX_GP:
written = sci_write_gpio_tx_gp(ihost, reg_index, reg_count, write_data);
break;
default:
written = -EINVAL;
}
return written;
}
