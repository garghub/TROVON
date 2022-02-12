bool sci_remote_node_context_is_ready(
struct sci_remote_node_context *sci_rnc)
{
u32 current_state = sci_rnc->sm.current_state_id;
if (current_state == SCI_RNC_READY) {
return true;
}
return false;
}
static union scu_remote_node_context *sci_rnc_by_id(struct isci_host *ihost, u16 id)
{
if (id < ihost->remote_node_entries &&
ihost->device_table[id])
return &ihost->remote_node_context_table[id];
return NULL;
}
static void sci_remote_node_context_construct_buffer(struct sci_remote_node_context *sci_rnc)
{
struct isci_remote_device *idev = rnc_to_dev(sci_rnc);
struct domain_device *dev = idev->domain_dev;
int rni = sci_rnc->remote_node_index;
union scu_remote_node_context *rnc;
struct isci_host *ihost;
__le64 sas_addr;
ihost = idev->owning_port->owning_controller;
rnc = sci_rnc_by_id(ihost, rni);
memset(rnc, 0, sizeof(union scu_remote_node_context)
* sci_remote_device_node_count(idev));
rnc->ssp.remote_node_index = rni;
rnc->ssp.remote_node_port_width = idev->device_port_width;
rnc->ssp.logical_port_index = idev->owning_port->physical_port_index;
sas_addr = cpu_to_le64(SAS_ADDR(dev->sas_addr));
rnc->ssp.remote_sas_address_hi = upper_32_bits(sas_addr);
rnc->ssp.remote_sas_address_lo = lower_32_bits(sas_addr);
rnc->ssp.nexus_loss_timer_enable = true;
rnc->ssp.check_bit = false;
rnc->ssp.is_valid = false;
rnc->ssp.is_remote_node_context = true;
rnc->ssp.function_number = 0;
rnc->ssp.arbitration_wait_time = 0;
if (dev->dev_type == SATA_DEV || (dev->tproto & SAS_PROTOCOL_STP)) {
rnc->ssp.connection_occupancy_timeout =
ihost->user_parameters.stp_max_occupancy_timeout;
rnc->ssp.connection_inactivity_timeout =
ihost->user_parameters.stp_inactivity_timeout;
} else {
rnc->ssp.connection_occupancy_timeout =
ihost->user_parameters.ssp_max_occupancy_timeout;
rnc->ssp.connection_inactivity_timeout =
ihost->user_parameters.ssp_inactivity_timeout;
}
rnc->ssp.initial_arbitration_wait_time = 0;
rnc->ssp.oaf_connection_rate = idev->connection_rate;
rnc->ssp.oaf_features = 0;
rnc->ssp.oaf_source_zone_group = 0;
rnc->ssp.oaf_more_compatibility_features = 0;
}
static void sci_remote_node_context_setup_to_resume(
struct sci_remote_node_context *sci_rnc,
scics_sds_remote_node_context_callback callback,
void *callback_parameter)
{
if (sci_rnc->destination_state != SCIC_SDS_REMOTE_NODE_DESTINATION_STATE_FINAL) {
sci_rnc->destination_state = SCIC_SDS_REMOTE_NODE_DESTINATION_STATE_READY;
sci_rnc->user_callback = callback;
sci_rnc->user_cookie = callback_parameter;
}
}
static void sci_remote_node_context_setup_to_destory(
struct sci_remote_node_context *sci_rnc,
scics_sds_remote_node_context_callback callback,
void *callback_parameter)
{
sci_rnc->destination_state = SCIC_SDS_REMOTE_NODE_DESTINATION_STATE_FINAL;
sci_rnc->user_callback = callback;
sci_rnc->user_cookie = callback_parameter;
}
static void sci_remote_node_context_notify_user(
struct sci_remote_node_context *rnc)
{
if (rnc->user_callback != NULL) {
(*rnc->user_callback)(rnc->user_cookie);
rnc->user_callback = NULL;
rnc->user_cookie = NULL;
}
}
static void sci_remote_node_context_continue_state_transitions(struct sci_remote_node_context *rnc)
{
if (rnc->destination_state == SCIC_SDS_REMOTE_NODE_DESTINATION_STATE_READY)
sci_remote_node_context_resume(rnc, rnc->user_callback,
rnc->user_cookie);
}
static void sci_remote_node_context_validate_context_buffer(struct sci_remote_node_context *sci_rnc)
{
union scu_remote_node_context *rnc_buffer;
struct isci_remote_device *idev = rnc_to_dev(sci_rnc);
struct domain_device *dev = idev->domain_dev;
struct isci_host *ihost = idev->owning_port->owning_controller;
rnc_buffer = sci_rnc_by_id(ihost, sci_rnc->remote_node_index);
rnc_buffer->ssp.is_valid = true;
if (!idev->is_direct_attached &&
(dev->dev_type == SATA_DEV || (dev->tproto & SAS_PROTOCOL_STP))) {
sci_remote_device_post_request(idev, SCU_CONTEXT_COMMAND_POST_RNC_96);
} else {
sci_remote_device_post_request(idev, SCU_CONTEXT_COMMAND_POST_RNC_32);
if (idev->is_direct_attached)
sci_port_setup_transports(idev->owning_port,
sci_rnc->remote_node_index);
}
}
static void sci_remote_node_context_invalidate_context_buffer(struct sci_remote_node_context *sci_rnc)
{
union scu_remote_node_context *rnc_buffer;
struct isci_remote_device *idev = rnc_to_dev(sci_rnc);
struct isci_host *ihost = idev->owning_port->owning_controller;
rnc_buffer = sci_rnc_by_id(ihost, sci_rnc->remote_node_index);
rnc_buffer->ssp.is_valid = false;
sci_remote_device_post_request(rnc_to_dev(sci_rnc),
SCU_CONTEXT_COMMAND_POST_RNC_INVALIDATE);
}
static void sci_remote_node_context_initial_state_enter(struct sci_base_state_machine *sm)
{
struct sci_remote_node_context *rnc = container_of(sm, typeof(*rnc), sm);
if (sm->previous_state_id == SCI_RNC_INVALIDATING) {
rnc->destination_state = SCIC_SDS_REMOTE_NODE_DESTINATION_STATE_UNSPECIFIED;
sci_remote_node_context_notify_user(rnc);
}
}
static void sci_remote_node_context_posting_state_enter(struct sci_base_state_machine *sm)
{
struct sci_remote_node_context *sci_rnc = container_of(sm, typeof(*sci_rnc), sm);
sci_remote_node_context_validate_context_buffer(sci_rnc);
}
static void sci_remote_node_context_invalidating_state_enter(struct sci_base_state_machine *sm)
{
struct sci_remote_node_context *rnc = container_of(sm, typeof(*rnc), sm);
sci_remote_node_context_invalidate_context_buffer(rnc);
}
static void sci_remote_node_context_resuming_state_enter(struct sci_base_state_machine *sm)
{
struct sci_remote_node_context *rnc = container_of(sm, typeof(*rnc), sm);
struct isci_remote_device *idev;
struct domain_device *dev;
idev = rnc_to_dev(rnc);
dev = idev->domain_dev;
if ((dev->dev_type == SATA_DEV || (dev->tproto & SAS_PROTOCOL_STP)) &&
idev->is_direct_attached)
sci_port_setup_transports(idev->owning_port,
rnc->remote_node_index);
sci_remote_device_post_request(idev, SCU_CONTEXT_COMMAND_POST_RNC_RESUME);
}
static void sci_remote_node_context_ready_state_enter(struct sci_base_state_machine *sm)
{
struct sci_remote_node_context *rnc = container_of(sm, typeof(*rnc), sm);
rnc->destination_state = SCIC_SDS_REMOTE_NODE_DESTINATION_STATE_UNSPECIFIED;
if (rnc->user_callback)
sci_remote_node_context_notify_user(rnc);
}
static void sci_remote_node_context_tx_suspended_state_enter(struct sci_base_state_machine *sm)
{
struct sci_remote_node_context *rnc = container_of(sm, typeof(*rnc), sm);
sci_remote_node_context_continue_state_transitions(rnc);
}
static void sci_remote_node_context_tx_rx_suspended_state_enter(struct sci_base_state_machine *sm)
{
struct sci_remote_node_context *rnc = container_of(sm, typeof(*rnc), sm);
sci_remote_node_context_continue_state_transitions(rnc);
}
void sci_remote_node_context_construct(struct sci_remote_node_context *rnc,
u16 remote_node_index)
{
memset(rnc, 0, sizeof(struct sci_remote_node_context));
rnc->remote_node_index = remote_node_index;
rnc->destination_state = SCIC_SDS_REMOTE_NODE_DESTINATION_STATE_UNSPECIFIED;
sci_init_sm(&rnc->sm, sci_remote_node_context_state_table, SCI_RNC_INITIAL);
}
enum sci_status sci_remote_node_context_event_handler(struct sci_remote_node_context *sci_rnc,
u32 event_code)
{
enum scis_sds_remote_node_context_states state;
state = sci_rnc->sm.current_state_id;
switch (state) {
case SCI_RNC_POSTING:
switch (scu_get_event_code(event_code)) {
case SCU_EVENT_POST_RNC_COMPLETE:
sci_change_state(&sci_rnc->sm, SCI_RNC_READY);
break;
default:
goto out;
}
break;
case SCI_RNC_INVALIDATING:
if (scu_get_event_code(event_code) == SCU_EVENT_POST_RNC_INVALIDATE_COMPLETE) {
if (sci_rnc->destination_state == SCIC_SDS_REMOTE_NODE_DESTINATION_STATE_FINAL)
state = SCI_RNC_INITIAL;
else
state = SCI_RNC_POSTING;
sci_change_state(&sci_rnc->sm, state);
} else {
switch (scu_get_event_type(event_code)) {
case SCU_EVENT_TYPE_RNC_SUSPEND_TX:
case SCU_EVENT_TYPE_RNC_SUSPEND_TX_RX:
dev_dbg(scirdev_to_dev(rnc_to_dev(sci_rnc)),
"%s: SCIC Remote Node Context 0x%p was "
"suspeneded by hardware while being "
"invalidated.\n", __func__, sci_rnc);
break;
default:
goto out;
}
}
break;
case SCI_RNC_RESUMING:
if (scu_get_event_code(event_code) == SCU_EVENT_POST_RCN_RELEASE) {
sci_change_state(&sci_rnc->sm, SCI_RNC_READY);
} else {
switch (scu_get_event_type(event_code)) {
case SCU_EVENT_TYPE_RNC_SUSPEND_TX:
case SCU_EVENT_TYPE_RNC_SUSPEND_TX_RX:
dev_dbg(scirdev_to_dev(rnc_to_dev(sci_rnc)),
"%s: SCIC Remote Node Context 0x%p was "
"suspeneded by hardware while being resumed.\n",
__func__, sci_rnc);
break;
default:
goto out;
}
}
break;
case SCI_RNC_READY:
switch (scu_get_event_type(event_code)) {
case SCU_EVENT_TL_RNC_SUSPEND_TX:
sci_change_state(&sci_rnc->sm, SCI_RNC_TX_SUSPENDED);
sci_rnc->suspension_code = scu_get_event_specifier(event_code);
break;
case SCU_EVENT_TL_RNC_SUSPEND_TX_RX:
sci_change_state(&sci_rnc->sm, SCI_RNC_TX_RX_SUSPENDED);
sci_rnc->suspension_code = scu_get_event_specifier(event_code);
break;
default:
goto out;
}
break;
case SCI_RNC_AWAIT_SUSPENSION:
switch (scu_get_event_type(event_code)) {
case SCU_EVENT_TL_RNC_SUSPEND_TX:
sci_change_state(&sci_rnc->sm, SCI_RNC_TX_SUSPENDED);
sci_rnc->suspension_code = scu_get_event_specifier(event_code);
break;
case SCU_EVENT_TL_RNC_SUSPEND_TX_RX:
sci_change_state(&sci_rnc->sm, SCI_RNC_TX_RX_SUSPENDED);
sci_rnc->suspension_code = scu_get_event_specifier(event_code);
break;
default:
goto out;
}
break;
default:
dev_warn(scirdev_to_dev(rnc_to_dev(sci_rnc)),
"%s: invalid state %d\n", __func__, state);
return SCI_FAILURE_INVALID_STATE;
}
return SCI_SUCCESS;
out:
dev_warn(scirdev_to_dev(rnc_to_dev(sci_rnc)),
"%s: code: %#x state: %d\n", __func__, event_code, state);
return SCI_FAILURE;
}
enum sci_status sci_remote_node_context_destruct(struct sci_remote_node_context *sci_rnc,
scics_sds_remote_node_context_callback cb_fn,
void *cb_p)
{
enum scis_sds_remote_node_context_states state;
state = sci_rnc->sm.current_state_id;
switch (state) {
case SCI_RNC_INVALIDATING:
sci_remote_node_context_setup_to_destory(sci_rnc, cb_fn, cb_p);
return SCI_SUCCESS;
case SCI_RNC_POSTING:
case SCI_RNC_RESUMING:
case SCI_RNC_READY:
case SCI_RNC_TX_SUSPENDED:
case SCI_RNC_TX_RX_SUSPENDED:
case SCI_RNC_AWAIT_SUSPENSION:
sci_remote_node_context_setup_to_destory(sci_rnc, cb_fn, cb_p);
sci_change_state(&sci_rnc->sm, SCI_RNC_INVALIDATING);
return SCI_SUCCESS;
case SCI_RNC_INITIAL:
dev_warn(scirdev_to_dev(rnc_to_dev(sci_rnc)),
"%s: invalid state %d\n", __func__, state);
return SCI_SUCCESS;
default:
dev_warn(scirdev_to_dev(rnc_to_dev(sci_rnc)),
"%s: invalid state %d\n", __func__, state);
return SCI_FAILURE_INVALID_STATE;
}
}
enum sci_status sci_remote_node_context_suspend(struct sci_remote_node_context *sci_rnc,
u32 suspend_type,
scics_sds_remote_node_context_callback cb_fn,
void *cb_p)
{
enum scis_sds_remote_node_context_states state;
state = sci_rnc->sm.current_state_id;
if (state != SCI_RNC_READY) {
dev_warn(scirdev_to_dev(rnc_to_dev(sci_rnc)),
"%s: invalid state %d\n", __func__, state);
return SCI_FAILURE_INVALID_STATE;
}
sci_rnc->user_callback = cb_fn;
sci_rnc->user_cookie = cb_p;
sci_rnc->suspension_code = suspend_type;
if (suspend_type == SCI_SOFTWARE_SUSPENSION) {
sci_remote_device_post_request(rnc_to_dev(sci_rnc),
SCU_CONTEXT_COMMAND_POST_RNC_SUSPEND_TX);
}
sci_change_state(&sci_rnc->sm, SCI_RNC_AWAIT_SUSPENSION);
return SCI_SUCCESS;
}
enum sci_status sci_remote_node_context_resume(struct sci_remote_node_context *sci_rnc,
scics_sds_remote_node_context_callback cb_fn,
void *cb_p)
{
enum scis_sds_remote_node_context_states state;
state = sci_rnc->sm.current_state_id;
switch (state) {
case SCI_RNC_INITIAL:
if (sci_rnc->remote_node_index == SCIC_SDS_REMOTE_NODE_CONTEXT_INVALID_INDEX)
return SCI_FAILURE_INVALID_STATE;
sci_remote_node_context_setup_to_resume(sci_rnc, cb_fn, cb_p);
sci_remote_node_context_construct_buffer(sci_rnc);
sci_change_state(&sci_rnc->sm, SCI_RNC_POSTING);
return SCI_SUCCESS;
case SCI_RNC_POSTING:
case SCI_RNC_INVALIDATING:
case SCI_RNC_RESUMING:
if (sci_rnc->destination_state != SCIC_SDS_REMOTE_NODE_DESTINATION_STATE_READY)
return SCI_FAILURE_INVALID_STATE;
sci_rnc->user_callback = cb_fn;
sci_rnc->user_cookie = cb_p;
return SCI_SUCCESS;
case SCI_RNC_TX_SUSPENDED: {
struct isci_remote_device *idev = rnc_to_dev(sci_rnc);
struct domain_device *dev = idev->domain_dev;
sci_remote_node_context_setup_to_resume(sci_rnc, cb_fn, cb_p);
if (dev->dev_type == SAS_END_DEV || dev_is_expander(dev))
sci_change_state(&sci_rnc->sm, SCI_RNC_RESUMING);
else if (dev->dev_type == SATA_DEV || (dev->tproto & SAS_PROTOCOL_STP)) {
if (idev->is_direct_attached) {
sci_change_state(&sci_rnc->sm, SCI_RNC_RESUMING);
} else {
sci_change_state(&sci_rnc->sm, SCI_RNC_INVALIDATING);
}
} else
return SCI_FAILURE;
return SCI_SUCCESS;
}
case SCI_RNC_TX_RX_SUSPENDED:
sci_remote_node_context_setup_to_resume(sci_rnc, cb_fn, cb_p);
sci_change_state(&sci_rnc->sm, SCI_RNC_RESUMING);
return SCI_FAILURE_INVALID_STATE;
case SCI_RNC_AWAIT_SUSPENSION:
sci_remote_node_context_setup_to_resume(sci_rnc, cb_fn, cb_p);
return SCI_SUCCESS;
default:
dev_warn(scirdev_to_dev(rnc_to_dev(sci_rnc)),
"%s: invalid state %d\n", __func__, state);
return SCI_FAILURE_INVALID_STATE;
}
}
enum sci_status sci_remote_node_context_start_io(struct sci_remote_node_context *sci_rnc,
struct isci_request *ireq)
{
enum scis_sds_remote_node_context_states state;
state = sci_rnc->sm.current_state_id;
switch (state) {
case SCI_RNC_READY:
return SCI_SUCCESS;
case SCI_RNC_TX_SUSPENDED:
case SCI_RNC_TX_RX_SUSPENDED:
case SCI_RNC_AWAIT_SUSPENSION:
dev_warn(scirdev_to_dev(rnc_to_dev(sci_rnc)),
"%s: invalid state %d\n", __func__, state);
return SCI_FAILURE_REMOTE_DEVICE_RESET_REQUIRED;
default:
break;
}
dev_dbg(scirdev_to_dev(rnc_to_dev(sci_rnc)),
"%s: requested to start IO while still resuming, %d\n",
__func__, state);
return SCI_FAILURE_INVALID_STATE;
}
enum sci_status sci_remote_node_context_start_task(struct sci_remote_node_context *sci_rnc,
struct isci_request *ireq)
{
enum scis_sds_remote_node_context_states state;
state = sci_rnc->sm.current_state_id;
switch (state) {
case SCI_RNC_RESUMING:
case SCI_RNC_READY:
case SCI_RNC_AWAIT_SUSPENSION:
return SCI_SUCCESS;
case SCI_RNC_TX_SUSPENDED:
case SCI_RNC_TX_RX_SUSPENDED:
sci_remote_node_context_resume(sci_rnc, NULL, NULL);
return SCI_SUCCESS;
default:
dev_warn(scirdev_to_dev(rnc_to_dev(sci_rnc)),
"%s: invalid state %d\n", __func__, state);
return SCI_FAILURE_INVALID_STATE;
}
}
