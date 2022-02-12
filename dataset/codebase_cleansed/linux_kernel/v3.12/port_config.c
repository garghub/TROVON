static s32 sci_sas_address_compare(
struct sci_sas_address address_one,
struct sci_sas_address address_two)
{
if (address_one.high > address_two.high) {
return 1;
} else if (address_one.high < address_two.high) {
return -1;
} else if (address_one.low > address_two.low) {
return 1;
} else if (address_one.low < address_two.low) {
return -1;
}
return 0;
}
static struct isci_port *sci_port_configuration_agent_find_port(
struct isci_host *ihost,
struct isci_phy *iphy)
{
u8 i;
struct sci_sas_address port_sas_address;
struct sci_sas_address port_attached_device_address;
struct sci_sas_address phy_sas_address;
struct sci_sas_address phy_attached_device_address;
sci_phy_get_sas_address(iphy, &phy_sas_address);
sci_phy_get_attached_sas_address(iphy, &phy_attached_device_address);
for (i = 0; i < ihost->logical_port_entries; i++) {
struct isci_port *iport = &ihost->ports[i];
sci_port_get_sas_address(iport, &port_sas_address);
sci_port_get_attached_sas_address(iport, &port_attached_device_address);
if (sci_sas_address_compare(port_sas_address, phy_sas_address) == 0 &&
sci_sas_address_compare(port_attached_device_address, phy_attached_device_address) == 0)
return iport;
}
return NULL;
}
static enum sci_status sci_port_configuration_agent_validate_ports(
struct isci_host *ihost,
struct sci_port_configuration_agent *port_agent)
{
struct sci_sas_address first_address;
struct sci_sas_address second_address;
if (port_agent->phy_valid_port_range[0].max_index != 0 ||
port_agent->phy_valid_port_range[1].max_index != 1 ||
port_agent->phy_valid_port_range[2].max_index != 2 ||
port_agent->phy_valid_port_range[3].max_index != 3)
return SCI_FAILURE_UNSUPPORTED_PORT_CONFIGURATION;
if (port_agent->phy_valid_port_range[0].min_index == 0 &&
port_agent->phy_valid_port_range[1].min_index == 0 &&
port_agent->phy_valid_port_range[2].min_index == 0 &&
port_agent->phy_valid_port_range[3].min_index == 0)
return SCI_SUCCESS;
if (port_agent->phy_valid_port_range[2].min_index == 1) {
return SCI_FAILURE_UNSUPPORTED_PORT_CONFIGURATION;
}
sci_phy_get_sas_address(&ihost->phys[0], &first_address);
sci_phy_get_sas_address(&ihost->phys[3], &second_address);
if (sci_sas_address_compare(first_address, second_address) == 0) {
return SCI_FAILURE_UNSUPPORTED_PORT_CONFIGURATION;
}
if (port_agent->phy_valid_port_range[0].min_index == 0 &&
port_agent->phy_valid_port_range[1].min_index == 1) {
sci_phy_get_sas_address(&ihost->phys[0], &first_address);
sci_phy_get_sas_address(&ihost->phys[2], &second_address);
if (sci_sas_address_compare(first_address, second_address) == 0) {
return SCI_FAILURE_UNSUPPORTED_PORT_CONFIGURATION;
}
}
if (port_agent->phy_valid_port_range[2].min_index == 2 &&
port_agent->phy_valid_port_range[3].min_index == 3) {
sci_phy_get_sas_address(&ihost->phys[1], &first_address);
sci_phy_get_sas_address(&ihost->phys[3], &second_address);
if (sci_sas_address_compare(first_address, second_address) == 0) {
return SCI_FAILURE_UNSUPPORTED_PORT_CONFIGURATION;
}
}
return SCI_SUCCESS;
}
static enum sci_status
sci_mpc_agent_validate_phy_configuration(struct isci_host *ihost,
struct sci_port_configuration_agent *port_agent)
{
u32 phy_mask;
u32 assigned_phy_mask;
struct sci_sas_address sas_address;
struct sci_sas_address phy_assigned_address;
u8 port_index;
u8 phy_index;
assigned_phy_mask = 0;
sas_address.high = 0;
sas_address.low = 0;
for (port_index = 0; port_index < SCI_MAX_PORTS; port_index++) {
phy_mask = ihost->oem_parameters.ports[port_index].phy_mask;
if (!phy_mask)
continue;
if ((phy_mask & ~assigned_phy_mask) == 0) {
return SCI_FAILURE_UNSUPPORTED_PORT_CONFIGURATION;
}
for (phy_index = 0; phy_index < SCI_MAX_PHYS; phy_index++) {
if ((phy_mask & (1 << phy_index)) == 0)
continue;
sci_phy_get_sas_address(&ihost->phys[phy_index],
&sas_address);
port_agent->phy_valid_port_range[phy_index].min_index = port_index;
port_agent->phy_valid_port_range[phy_index].max_index = phy_index;
if (phy_index != port_index) {
return SCI_FAILURE_UNSUPPORTED_PORT_CONFIGURATION;
}
break;
}
while (phy_index < SCI_MAX_PHYS) {
if ((phy_mask & (1 << phy_index)) == 0)
continue;
sci_phy_get_sas_address(&ihost->phys[phy_index],
&phy_assigned_address);
if (sci_sas_address_compare(sas_address, phy_assigned_address) != 0) {
return SCI_FAILURE_UNSUPPORTED_PORT_CONFIGURATION;
}
port_agent->phy_valid_port_range[phy_index].min_index = port_index;
port_agent->phy_valid_port_range[phy_index].max_index = phy_index;
sci_port_add_phy(&ihost->ports[port_index],
&ihost->phys[phy_index]);
assigned_phy_mask |= (1 << phy_index);
phy_index++;
}
}
return sci_port_configuration_agent_validate_ports(ihost, port_agent);
}
static void mpc_agent_timeout(unsigned long data)
{
u8 index;
struct sci_timer *tmr = (struct sci_timer *)data;
struct sci_port_configuration_agent *port_agent;
struct isci_host *ihost;
unsigned long flags;
u16 configure_phy_mask;
port_agent = container_of(tmr, typeof(*port_agent), timer);
ihost = container_of(port_agent, typeof(*ihost), port_agent);
spin_lock_irqsave(&ihost->scic_lock, flags);
if (tmr->cancel)
goto done;
port_agent->timer_pending = false;
configure_phy_mask = ~port_agent->phy_configured_mask & port_agent->phy_ready_mask;
for (index = 0; index < SCI_MAX_PHYS; index++) {
struct isci_phy *iphy = &ihost->phys[index];
if (configure_phy_mask & (1 << index)) {
port_agent->link_up_handler(ihost, port_agent,
phy_get_non_dummy_port(iphy),
iphy);
}
}
done:
spin_unlock_irqrestore(&ihost->scic_lock, flags);
}
static void sci_mpc_agent_link_up(struct isci_host *ihost,
struct sci_port_configuration_agent *port_agent,
struct isci_port *iport,
struct isci_phy *iphy)
{
if (!iport)
return;
port_agent->phy_ready_mask |= (1 << iphy->phy_index);
sci_port_link_up(iport, iphy);
if ((iport->active_phy_mask & (1 << iphy->phy_index)))
port_agent->phy_configured_mask |= (1 << iphy->phy_index);
}
static void sci_mpc_agent_link_down(
struct isci_host *ihost,
struct sci_port_configuration_agent *port_agent,
struct isci_port *iport,
struct isci_phy *iphy)
{
if (iport != NULL) {
port_agent->phy_ready_mask &= ~(1 << iphy->phy_index);
port_agent->phy_configured_mask &= ~(1 << iphy->phy_index);
if ((port_agent->phy_configured_mask == 0x0000) &&
(port_agent->phy_ready_mask != 0x0000) &&
!port_agent->timer_pending) {
port_agent->timer_pending = true;
sci_mod_timer(&port_agent->timer,
SCIC_SDS_MPC_RECONFIGURATION_TIMEOUT);
}
sci_port_link_down(iport, iphy);
}
}
static enum sci_status
sci_apc_agent_validate_phy_configuration(struct isci_host *ihost,
struct sci_port_configuration_agent *port_agent)
{
u8 phy_index;
u8 port_index;
struct sci_sas_address sas_address;
struct sci_sas_address phy_assigned_address;
phy_index = 0;
while (phy_index < SCI_MAX_PHYS) {
port_index = phy_index;
sci_phy_get_sas_address(&ihost->phys[phy_index],
&sas_address);
while (++phy_index < SCI_MAX_PHYS) {
sci_phy_get_sas_address(&ihost->phys[phy_index],
&phy_assigned_address);
if (sci_sas_address_compare(sas_address, phy_assigned_address) == 0) {
port_agent->phy_valid_port_range[phy_index].min_index = port_index;
port_agent->phy_valid_port_range[phy_index].max_index = phy_index;
} else {
port_agent->phy_valid_port_range[phy_index].min_index = phy_index;
port_agent->phy_valid_port_range[phy_index].max_index = phy_index;
break;
}
}
}
return sci_port_configuration_agent_validate_ports(ihost, port_agent);
}
static void sci_apc_agent_start_timer(struct sci_port_configuration_agent *port_agent,
u32 timeout)
{
port_agent->timer_pending = true;
sci_mod_timer(&port_agent->timer, timeout);
}
static void sci_apc_agent_configure_ports(struct isci_host *ihost,
struct sci_port_configuration_agent *port_agent,
struct isci_phy *iphy,
bool start_timer)
{
u8 port_index;
enum sci_status status;
struct isci_port *iport;
enum SCIC_SDS_APC_ACTIVITY apc_activity = SCIC_SDS_APC_SKIP_PHY;
iport = sci_port_configuration_agent_find_port(ihost, iphy);
if (iport) {
if (sci_port_is_valid_phy_assignment(iport, iphy->phy_index))
apc_activity = SCIC_SDS_APC_ADD_PHY;
else
apc_activity = SCIC_SDS_APC_SKIP_PHY;
} else {
for (port_index = port_agent->phy_valid_port_range[iphy->phy_index].min_index;
port_index <= port_agent->phy_valid_port_range[iphy->phy_index].max_index;
port_index++) {
iport = &ihost->ports[port_index];
if (sci_port_is_valid_phy_assignment(iport, iphy->phy_index)) {
if (iport->active_phy_mask > (1 << iphy->phy_index)) {
apc_activity = SCIC_SDS_APC_SKIP_PHY;
break;
}
if (iport->physical_port_index == iphy->phy_index) {
if (apc_activity != SCIC_SDS_APC_START_TIMER) {
apc_activity = SCIC_SDS_APC_ADD_PHY;
}
break;
}
if (iport->active_phy_mask == 0) {
apc_activity = SCIC_SDS_APC_START_TIMER;
}
} else if (iport->active_phy_mask != 0) {
apc_activity = SCIC_SDS_APC_SKIP_PHY;
}
}
}
if (
(start_timer == false)
&& (apc_activity == SCIC_SDS_APC_START_TIMER)
) {
apc_activity = SCIC_SDS_APC_ADD_PHY;
}
switch (apc_activity) {
case SCIC_SDS_APC_ADD_PHY:
status = sci_port_add_phy(iport, iphy);
if (status == SCI_SUCCESS) {
port_agent->phy_configured_mask |= (1 << iphy->phy_index);
}
break;
case SCIC_SDS_APC_START_TIMER:
sci_apc_agent_start_timer(port_agent,
SCIC_SDS_APC_WAIT_LINK_UP_NOTIFICATION);
break;
case SCIC_SDS_APC_SKIP_PHY:
default:
break;
}
}
static void sci_apc_agent_link_up(struct isci_host *ihost,
struct sci_port_configuration_agent *port_agent,
struct isci_port *iport,
struct isci_phy *iphy)
{
u8 phy_index = iphy->phy_index;
if (!iport) {
port_agent->phy_ready_mask |= 1 << phy_index;
sci_apc_agent_start_timer(port_agent,
SCIC_SDS_APC_WAIT_LINK_UP_NOTIFICATION);
} else {
u32 port_state = iport->sm.current_state_id;
BUG_ON(port_state != SCI_PORT_RESETTING);
port_agent->phy_ready_mask |= 1 << phy_index;
sci_port_link_up(iport, iphy);
}
}
static void sci_apc_agent_link_down(
struct isci_host *ihost,
struct sci_port_configuration_agent *port_agent,
struct isci_port *iport,
struct isci_phy *iphy)
{
port_agent->phy_ready_mask &= ~(1 << iphy->phy_index);
if (!iport)
return;
if (port_agent->phy_configured_mask & (1 << iphy->phy_index)) {
enum sci_status status;
status = sci_port_remove_phy(iport, iphy);
if (status == SCI_SUCCESS)
port_agent->phy_configured_mask &= ~(1 << iphy->phy_index);
}
}
static void apc_agent_timeout(unsigned long data)
{
u32 index;
struct sci_timer *tmr = (struct sci_timer *)data;
struct sci_port_configuration_agent *port_agent;
struct isci_host *ihost;
unsigned long flags;
u16 configure_phy_mask;
port_agent = container_of(tmr, typeof(*port_agent), timer);
ihost = container_of(port_agent, typeof(*ihost), port_agent);
spin_lock_irqsave(&ihost->scic_lock, flags);
if (tmr->cancel)
goto done;
port_agent->timer_pending = false;
configure_phy_mask = ~port_agent->phy_configured_mask & port_agent->phy_ready_mask;
if (!configure_phy_mask)
goto done;
for (index = 0; index < SCI_MAX_PHYS; index++) {
if ((configure_phy_mask & (1 << index)) == 0)
continue;
sci_apc_agent_configure_ports(ihost, port_agent,
&ihost->phys[index], false);
}
if (is_controller_start_complete(ihost))
sci_controller_transition_to_ready(ihost, SCI_SUCCESS);
done:
spin_unlock_irqrestore(&ihost->scic_lock, flags);
}
void sci_port_configuration_agent_construct(
struct sci_port_configuration_agent *port_agent)
{
u32 index;
port_agent->phy_configured_mask = 0x00;
port_agent->phy_ready_mask = 0x00;
port_agent->link_up_handler = NULL;
port_agent->link_down_handler = NULL;
port_agent->timer_pending = false;
for (index = 0; index < SCI_MAX_PORTS; index++) {
port_agent->phy_valid_port_range[index].min_index = 0;
port_agent->phy_valid_port_range[index].max_index = 0;
}
}
bool is_port_config_apc(struct isci_host *ihost)
{
return ihost->port_agent.link_up_handler == sci_apc_agent_link_up;
}
enum sci_status sci_port_configuration_agent_initialize(
struct isci_host *ihost,
struct sci_port_configuration_agent *port_agent)
{
enum sci_status status;
enum sci_port_configuration_mode mode;
mode = ihost->oem_parameters.controller.mode_type;
if (mode == SCIC_PORT_MANUAL_CONFIGURATION_MODE) {
status = sci_mpc_agent_validate_phy_configuration(
ihost, port_agent);
port_agent->link_up_handler = sci_mpc_agent_link_up;
port_agent->link_down_handler = sci_mpc_agent_link_down;
sci_init_timer(&port_agent->timer, mpc_agent_timeout);
} else {
status = sci_apc_agent_validate_phy_configuration(
ihost, port_agent);
port_agent->link_up_handler = sci_apc_agent_link_up;
port_agent->link_down_handler = sci_apc_agent_link_down;
sci_init_timer(&port_agent->timer, apc_agent_timeout);
}
return status;
}
