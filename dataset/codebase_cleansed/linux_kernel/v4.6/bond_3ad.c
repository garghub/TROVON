static inline struct bonding *__get_bond_by_port(struct port *port)
{
if (port->slave == NULL)
return NULL;
return bond_get_bond_by_slave(port->slave);
}
static inline struct aggregator *__get_first_agg(struct port *port)
{
struct bonding *bond = __get_bond_by_port(port);
struct slave *first_slave;
struct aggregator *agg;
if (bond == NULL)
return NULL;
rcu_read_lock();
first_slave = bond_first_slave_rcu(bond);
agg = first_slave ? &(SLAVE_AD_INFO(first_slave)->aggregator) : NULL;
rcu_read_unlock();
return agg;
}
static inline int __agg_has_partner(struct aggregator *agg)
{
return !is_zero_ether_addr(agg->partner_system.mac_addr_value);
}
static inline void __disable_port(struct port *port)
{
bond_set_slave_inactive_flags(port->slave, BOND_SLAVE_NOTIFY_LATER);
}
static inline void __enable_port(struct port *port)
{
struct slave *slave = port->slave;
if ((slave->link == BOND_LINK_UP) && bond_slave_is_up(slave))
bond_set_slave_active_flags(slave, BOND_SLAVE_NOTIFY_LATER);
}
static inline int __port_is_enabled(struct port *port)
{
return bond_is_active_slave(port->slave);
}
static inline u32 __get_agg_selection_mode(struct port *port)
{
struct bonding *bond = __get_bond_by_port(port);
if (bond == NULL)
return BOND_AD_STABLE;
return bond->params.ad_select;
}
static inline int __check_agg_selection_timer(struct port *port)
{
struct bonding *bond = __get_bond_by_port(port);
if (bond == NULL)
return 0;
return BOND_AD_INFO(bond).agg_select_timer ? 1 : 0;
}
static u16 __get_link_speed(struct port *port)
{
struct slave *slave = port->slave;
u16 speed;
if (slave->link != BOND_LINK_UP)
speed = 0;
else {
switch (slave->speed) {
case SPEED_10:
speed = AD_LINK_SPEED_10MBPS;
break;
case SPEED_100:
speed = AD_LINK_SPEED_100MBPS;
break;
case SPEED_1000:
speed = AD_LINK_SPEED_1000MBPS;
break;
case SPEED_2500:
speed = AD_LINK_SPEED_2500MBPS;
break;
case SPEED_10000:
speed = AD_LINK_SPEED_10000MBPS;
break;
case SPEED_20000:
speed = AD_LINK_SPEED_20000MBPS;
break;
case SPEED_40000:
speed = AD_LINK_SPEED_40000MBPS;
break;
case SPEED_56000:
speed = AD_LINK_SPEED_56000MBPS;
break;
case SPEED_100000:
speed = AD_LINK_SPEED_100000MBPS;
break;
default:
speed = 0;
break;
}
}
netdev_dbg(slave->bond->dev, "Port %d Received link speed %d update from adapter\n",
port->actor_port_number, speed);
return speed;
}
static u8 __get_duplex(struct port *port)
{
struct slave *slave = port->slave;
u8 retval = 0x0;
if (slave->link == BOND_LINK_UP) {
switch (slave->duplex) {
case DUPLEX_FULL:
retval = 0x1;
netdev_dbg(slave->bond->dev, "Port %d Received status full duplex update from adapter\n",
port->actor_port_number);
break;
case DUPLEX_HALF:
default:
retval = 0x0;
netdev_dbg(slave->bond->dev, "Port %d Received status NOT full duplex update from adapter\n",
port->actor_port_number);
break;
}
}
return retval;
}
static void __ad_actor_update_port(struct port *port)
{
const struct bonding *bond = bond_get_bond_by_slave(port->slave);
port->actor_system = BOND_AD_INFO(bond).system.sys_mac_addr;
port->actor_system_priority = BOND_AD_INFO(bond).system.sys_priority;
}
static u16 __ad_timer_to_ticks(u16 timer_type, u16 par)
{
u16 retval = 0;
switch (timer_type) {
case AD_CURRENT_WHILE_TIMER:
if (par)
retval = (AD_SHORT_TIMEOUT_TIME*ad_ticks_per_sec);
else
retval = (AD_LONG_TIMEOUT_TIME*ad_ticks_per_sec);
break;
case AD_ACTOR_CHURN_TIMER:
retval = (AD_CHURN_DETECTION_TIME*ad_ticks_per_sec);
break;
case AD_PERIODIC_TIMER:
retval = (par*ad_ticks_per_sec);
break;
case AD_PARTNER_CHURN_TIMER:
retval = (AD_CHURN_DETECTION_TIME*ad_ticks_per_sec);
break;
case AD_WAIT_WHILE_TIMER:
retval = (AD_AGGREGATE_WAIT_TIME*ad_ticks_per_sec);
break;
}
return retval;
}
static void __choose_matched(struct lacpdu *lacpdu, struct port *port)
{
if (((ntohs(lacpdu->partner_port) == port->actor_port_number) &&
(ntohs(lacpdu->partner_port_priority) == port->actor_port_priority) &&
MAC_ADDRESS_EQUAL(&(lacpdu->partner_system), &(port->actor_system)) &&
(ntohs(lacpdu->partner_system_priority) == port->actor_system_priority) &&
(ntohs(lacpdu->partner_key) == port->actor_oper_port_key) &&
((lacpdu->partner_state & AD_STATE_AGGREGATION) == (port->actor_oper_port_state & AD_STATE_AGGREGATION))) ||
((lacpdu->actor_state & AD_STATE_AGGREGATION) == 0)
) {
port->sm_vars |= AD_PORT_MATCHED;
} else {
port->sm_vars &= ~AD_PORT_MATCHED;
}
}
static void __record_pdu(struct lacpdu *lacpdu, struct port *port)
{
if (lacpdu && port) {
struct port_params *partner = &port->partner_oper;
__choose_matched(lacpdu, port);
partner->port_number = ntohs(lacpdu->actor_port);
partner->port_priority = ntohs(lacpdu->actor_port_priority);
partner->system = lacpdu->actor_system;
partner->system_priority = ntohs(lacpdu->actor_system_priority);
partner->key = ntohs(lacpdu->actor_key);
partner->port_state = lacpdu->actor_state;
port->actor_oper_port_state &= ~AD_STATE_DEFAULTED;
if ((port->sm_vars & AD_PORT_MATCHED) &&
(lacpdu->actor_state & AD_STATE_SYNCHRONIZATION)) {
partner->port_state |= AD_STATE_SYNCHRONIZATION;
pr_debug("%s partner sync=1\n", port->slave->dev->name);
} else {
partner->port_state &= ~AD_STATE_SYNCHRONIZATION;
pr_debug("%s partner sync=0\n", port->slave->dev->name);
}
}
}
static void __record_default(struct port *port)
{
if (port) {
memcpy(&port->partner_oper, &port->partner_admin,
sizeof(struct port_params));
port->actor_oper_port_state |= AD_STATE_DEFAULTED;
}
}
static void __update_selected(struct lacpdu *lacpdu, struct port *port)
{
if (lacpdu && port) {
const struct port_params *partner = &port->partner_oper;
if (ntohs(lacpdu->actor_port) != partner->port_number ||
ntohs(lacpdu->actor_port_priority) != partner->port_priority ||
!MAC_ADDRESS_EQUAL(&lacpdu->actor_system, &partner->system) ||
ntohs(lacpdu->actor_system_priority) != partner->system_priority ||
ntohs(lacpdu->actor_key) != partner->key ||
(lacpdu->actor_state & AD_STATE_AGGREGATION) != (partner->port_state & AD_STATE_AGGREGATION)) {
port->sm_vars &= ~AD_PORT_SELECTED;
}
}
}
static void __update_default_selected(struct port *port)
{
if (port) {
const struct port_params *admin = &port->partner_admin;
const struct port_params *oper = &port->partner_oper;
if (admin->port_number != oper->port_number ||
admin->port_priority != oper->port_priority ||
!MAC_ADDRESS_EQUAL(&admin->system, &oper->system) ||
admin->system_priority != oper->system_priority ||
admin->key != oper->key ||
(admin->port_state & AD_STATE_AGGREGATION)
!= (oper->port_state & AD_STATE_AGGREGATION)) {
port->sm_vars &= ~AD_PORT_SELECTED;
}
}
}
static void __update_ntt(struct lacpdu *lacpdu, struct port *port)
{
if (lacpdu && port) {
if ((ntohs(lacpdu->partner_port) != port->actor_port_number) ||
(ntohs(lacpdu->partner_port_priority) != port->actor_port_priority) ||
!MAC_ADDRESS_EQUAL(&(lacpdu->partner_system), &(port->actor_system)) ||
(ntohs(lacpdu->partner_system_priority) != port->actor_system_priority) ||
(ntohs(lacpdu->partner_key) != port->actor_oper_port_key) ||
((lacpdu->partner_state & AD_STATE_LACP_ACTIVITY) != (port->actor_oper_port_state & AD_STATE_LACP_ACTIVITY)) ||
((lacpdu->partner_state & AD_STATE_LACP_TIMEOUT) != (port->actor_oper_port_state & AD_STATE_LACP_TIMEOUT)) ||
((lacpdu->partner_state & AD_STATE_SYNCHRONIZATION) != (port->actor_oper_port_state & AD_STATE_SYNCHRONIZATION)) ||
((lacpdu->partner_state & AD_STATE_AGGREGATION) != (port->actor_oper_port_state & AD_STATE_AGGREGATION))
) {
port->ntt = true;
}
}
}
static int __agg_ports_are_ready(struct aggregator *aggregator)
{
struct port *port;
int retval = 1;
if (aggregator) {
for (port = aggregator->lag_ports;
port;
port = port->next_port_in_aggregator) {
if (!(port->sm_vars & AD_PORT_READY_N)) {
retval = 0;
break;
}
}
}
return retval;
}
static void __set_agg_ports_ready(struct aggregator *aggregator, int val)
{
struct port *port;
for (port = aggregator->lag_ports; port;
port = port->next_port_in_aggregator) {
if (val)
port->sm_vars |= AD_PORT_READY;
else
port->sm_vars &= ~AD_PORT_READY;
}
}
static u32 __get_agg_bandwidth(struct aggregator *aggregator)
{
u32 bandwidth = 0;
if (aggregator->num_of_ports) {
switch (__get_link_speed(aggregator->lag_ports)) {
case AD_LINK_SPEED_1MBPS:
bandwidth = aggregator->num_of_ports;
break;
case AD_LINK_SPEED_10MBPS:
bandwidth = aggregator->num_of_ports * 10;
break;
case AD_LINK_SPEED_100MBPS:
bandwidth = aggregator->num_of_ports * 100;
break;
case AD_LINK_SPEED_1000MBPS:
bandwidth = aggregator->num_of_ports * 1000;
break;
case AD_LINK_SPEED_2500MBPS:
bandwidth = aggregator->num_of_ports * 2500;
break;
case AD_LINK_SPEED_10000MBPS:
bandwidth = aggregator->num_of_ports * 10000;
break;
case AD_LINK_SPEED_20000MBPS:
bandwidth = aggregator->num_of_ports * 20000;
break;
case AD_LINK_SPEED_40000MBPS:
bandwidth = aggregator->num_of_ports * 40000;
break;
case AD_LINK_SPEED_56000MBPS:
bandwidth = aggregator->num_of_ports * 56000;
break;
case AD_LINK_SPEED_100000MBPS:
bandwidth = aggregator->num_of_ports * 100000;
break;
default:
bandwidth = 0;
}
}
return bandwidth;
}
static struct aggregator *__get_active_agg(struct aggregator *aggregator)
{
struct bonding *bond = aggregator->slave->bond;
struct list_head *iter;
struct slave *slave;
bond_for_each_slave_rcu(bond, slave, iter)
if (SLAVE_AD_INFO(slave)->aggregator.is_active)
return &(SLAVE_AD_INFO(slave)->aggregator);
return NULL;
}
static inline void __update_lacpdu_from_port(struct port *port)
{
struct lacpdu *lacpdu = &port->lacpdu;
const struct port_params *partner = &port->partner_oper;
lacpdu->actor_system_priority = htons(port->actor_system_priority);
lacpdu->actor_system = port->actor_system;
lacpdu->actor_key = htons(port->actor_oper_port_key);
lacpdu->actor_port_priority = htons(port->actor_port_priority);
lacpdu->actor_port = htons(port->actor_port_number);
lacpdu->actor_state = port->actor_oper_port_state;
pr_debug("update lacpdu: %s, actor port state %x\n",
port->slave->dev->name, port->actor_oper_port_state);
lacpdu->partner_system_priority = htons(partner->system_priority);
lacpdu->partner_system = partner->system;
lacpdu->partner_key = htons(partner->key);
lacpdu->partner_port_priority = htons(partner->port_priority);
lacpdu->partner_port = htons(partner->port_number);
lacpdu->partner_state = partner->port_state;
}
static int ad_lacpdu_send(struct port *port)
{
struct slave *slave = port->slave;
struct sk_buff *skb;
struct lacpdu_header *lacpdu_header;
int length = sizeof(struct lacpdu_header);
skb = dev_alloc_skb(length);
if (!skb)
return -ENOMEM;
skb->dev = slave->dev;
skb_reset_mac_header(skb);
skb->network_header = skb->mac_header + ETH_HLEN;
skb->protocol = PKT_TYPE_LACPDU;
skb->priority = TC_PRIO_CONTROL;
lacpdu_header = (struct lacpdu_header *)skb_put(skb, length);
ether_addr_copy(lacpdu_header->hdr.h_dest, lacpdu_mcast_addr);
ether_addr_copy(lacpdu_header->hdr.h_source, slave->perm_hwaddr);
lacpdu_header->hdr.h_proto = PKT_TYPE_LACPDU;
lacpdu_header->lacpdu = port->lacpdu;
dev_queue_xmit(skb);
return 0;
}
static int ad_marker_send(struct port *port, struct bond_marker *marker)
{
struct slave *slave = port->slave;
struct sk_buff *skb;
struct bond_marker_header *marker_header;
int length = sizeof(struct bond_marker_header);
skb = dev_alloc_skb(length + 16);
if (!skb)
return -ENOMEM;
skb_reserve(skb, 16);
skb->dev = slave->dev;
skb_reset_mac_header(skb);
skb->network_header = skb->mac_header + ETH_HLEN;
skb->protocol = PKT_TYPE_LACPDU;
marker_header = (struct bond_marker_header *)skb_put(skb, length);
ether_addr_copy(marker_header->hdr.h_dest, lacpdu_mcast_addr);
ether_addr_copy(marker_header->hdr.h_source, slave->perm_hwaddr);
marker_header->hdr.h_proto = PKT_TYPE_LACPDU;
marker_header->marker = *marker;
dev_queue_xmit(skb);
return 0;
}
static void ad_mux_machine(struct port *port, bool *update_slave_arr)
{
mux_states_t last_state;
last_state = port->sm_mux_state;
if (port->sm_vars & AD_PORT_BEGIN) {
port->sm_mux_state = AD_MUX_DETACHED;
} else {
switch (port->sm_mux_state) {
case AD_MUX_DETACHED:
if ((port->sm_vars & AD_PORT_SELECTED)
|| (port->sm_vars & AD_PORT_STANDBY))
port->sm_mux_state = AD_MUX_WAITING;
break;
case AD_MUX_WAITING:
if (!(port->sm_vars & AD_PORT_SELECTED)) {
port->sm_vars &= ~AD_PORT_READY_N;
__set_agg_ports_ready(port->aggregator, __agg_ports_are_ready(port->aggregator));
port->sm_mux_state = AD_MUX_DETACHED;
break;
}
if (port->sm_mux_timer_counter
&& !(--port->sm_mux_timer_counter))
port->sm_vars |= AD_PORT_READY_N;
__set_agg_ports_ready(port->aggregator, __agg_ports_are_ready(port->aggregator));
if ((port->sm_vars & AD_PORT_READY)
&& !port->sm_mux_timer_counter)
port->sm_mux_state = AD_MUX_ATTACHED;
break;
case AD_MUX_ATTACHED:
if ((port->sm_vars & AD_PORT_SELECTED) &&
(port->partner_oper.port_state & AD_STATE_SYNCHRONIZATION) &&
!__check_agg_selection_timer(port)) {
if (port->aggregator->is_active)
port->sm_mux_state =
AD_MUX_COLLECTING_DISTRIBUTING;
} else if (!(port->sm_vars & AD_PORT_SELECTED) ||
(port->sm_vars & AD_PORT_STANDBY)) {
port->sm_vars &= ~AD_PORT_READY_N;
__set_agg_ports_ready(port->aggregator, __agg_ports_are_ready(port->aggregator));
port->sm_mux_state = AD_MUX_DETACHED;
} else if (port->aggregator->is_active) {
port->actor_oper_port_state |=
AD_STATE_SYNCHRONIZATION;
}
break;
case AD_MUX_COLLECTING_DISTRIBUTING:
if (!(port->sm_vars & AD_PORT_SELECTED) ||
(port->sm_vars & AD_PORT_STANDBY) ||
!(port->partner_oper.port_state & AD_STATE_SYNCHRONIZATION) ||
!(port->actor_oper_port_state & AD_STATE_SYNCHRONIZATION)) {
port->sm_mux_state = AD_MUX_ATTACHED;
} else {
if (port->aggregator &&
port->aggregator->is_active &&
!__port_is_enabled(port)) {
__enable_port(port);
}
}
break;
default:
break;
}
}
if (port->sm_mux_state != last_state) {
pr_debug("Mux Machine: Port=%d (%s), Last State=%d, Curr State=%d\n",
port->actor_port_number,
port->slave->dev->name,
last_state,
port->sm_mux_state);
switch (port->sm_mux_state) {
case AD_MUX_DETACHED:
port->actor_oper_port_state &= ~AD_STATE_SYNCHRONIZATION;
ad_disable_collecting_distributing(port,
update_slave_arr);
port->actor_oper_port_state &= ~AD_STATE_COLLECTING;
port->actor_oper_port_state &= ~AD_STATE_DISTRIBUTING;
port->ntt = true;
break;
case AD_MUX_WAITING:
port->sm_mux_timer_counter = __ad_timer_to_ticks(AD_WAIT_WHILE_TIMER, 0);
break;
case AD_MUX_ATTACHED:
if (port->aggregator->is_active)
port->actor_oper_port_state |=
AD_STATE_SYNCHRONIZATION;
else
port->actor_oper_port_state &=
~AD_STATE_SYNCHRONIZATION;
port->actor_oper_port_state &= ~AD_STATE_COLLECTING;
port->actor_oper_port_state &= ~AD_STATE_DISTRIBUTING;
ad_disable_collecting_distributing(port,
update_slave_arr);
port->ntt = true;
break;
case AD_MUX_COLLECTING_DISTRIBUTING:
port->actor_oper_port_state |= AD_STATE_COLLECTING;
port->actor_oper_port_state |= AD_STATE_DISTRIBUTING;
port->actor_oper_port_state |= AD_STATE_SYNCHRONIZATION;
ad_enable_collecting_distributing(port,
update_slave_arr);
port->ntt = true;
break;
default:
break;
}
}
}
static void ad_rx_machine(struct lacpdu *lacpdu, struct port *port)
{
rx_states_t last_state;
last_state = port->sm_rx_state;
if (port->sm_vars & AD_PORT_BEGIN) {
port->sm_rx_state = AD_RX_INITIALIZE;
port->sm_vars |= AD_PORT_CHURNED;
} else if (!(port->sm_vars & AD_PORT_BEGIN)
&& !port->is_enabled && !(port->sm_vars & AD_PORT_MOVED))
port->sm_rx_state = AD_RX_PORT_DISABLED;
else if (lacpdu && ((port->sm_rx_state == AD_RX_EXPIRED) ||
(port->sm_rx_state == AD_RX_DEFAULTED) ||
(port->sm_rx_state == AD_RX_CURRENT))) {
if (port->sm_rx_state != AD_RX_CURRENT)
port->sm_vars |= AD_PORT_CHURNED;
port->sm_rx_timer_counter = 0;
port->sm_rx_state = AD_RX_CURRENT;
} else {
if (port->sm_rx_timer_counter &&
!(--port->sm_rx_timer_counter)) {
switch (port->sm_rx_state) {
case AD_RX_EXPIRED:
port->sm_rx_state = AD_RX_DEFAULTED;
break;
case AD_RX_CURRENT:
port->sm_rx_state = AD_RX_EXPIRED;
break;
default:
break;
}
} else {
switch (port->sm_rx_state) {
case AD_RX_PORT_DISABLED:
if (port->sm_vars & AD_PORT_MOVED)
port->sm_rx_state = AD_RX_INITIALIZE;
else if (port->is_enabled
&& (port->sm_vars
& AD_PORT_LACP_ENABLED))
port->sm_rx_state = AD_RX_EXPIRED;
else if (port->is_enabled
&& ((port->sm_vars
& AD_PORT_LACP_ENABLED) == 0))
port->sm_rx_state = AD_RX_LACP_DISABLED;
break;
default:
break;
}
}
}
if ((port->sm_rx_state != last_state) || (lacpdu)) {
pr_debug("Rx Machine: Port=%d (%s), Last State=%d, Curr State=%d\n",
port->actor_port_number,
port->slave->dev->name,
last_state,
port->sm_rx_state);
switch (port->sm_rx_state) {
case AD_RX_INITIALIZE:
if (!(port->actor_oper_port_key & AD_DUPLEX_KEY_MASKS))
port->sm_vars &= ~AD_PORT_LACP_ENABLED;
else
port->sm_vars |= AD_PORT_LACP_ENABLED;
port->sm_vars &= ~AD_PORT_SELECTED;
__record_default(port);
port->actor_oper_port_state &= ~AD_STATE_EXPIRED;
port->sm_vars &= ~AD_PORT_MOVED;
port->sm_rx_state = AD_RX_PORT_DISABLED;
case AD_RX_PORT_DISABLED:
port->sm_vars &= ~AD_PORT_MATCHED;
break;
case AD_RX_LACP_DISABLED:
port->sm_vars &= ~AD_PORT_SELECTED;
__record_default(port);
port->partner_oper.port_state &= ~AD_STATE_AGGREGATION;
port->sm_vars |= AD_PORT_MATCHED;
port->actor_oper_port_state &= ~AD_STATE_EXPIRED;
break;
case AD_RX_EXPIRED:
port->partner_oper.port_state &= ~AD_STATE_SYNCHRONIZATION;
port->sm_vars &= ~AD_PORT_MATCHED;
port->partner_oper.port_state |= AD_STATE_LACP_TIMEOUT;
port->partner_oper.port_state |= AD_STATE_LACP_ACTIVITY;
port->sm_rx_timer_counter = __ad_timer_to_ticks(AD_CURRENT_WHILE_TIMER, (u16)(AD_SHORT_TIMEOUT));
port->actor_oper_port_state |= AD_STATE_EXPIRED;
port->sm_vars |= AD_PORT_CHURNED;
break;
case AD_RX_DEFAULTED:
__update_default_selected(port);
__record_default(port);
port->sm_vars |= AD_PORT_MATCHED;
port->actor_oper_port_state &= ~AD_STATE_EXPIRED;
break;
case AD_RX_CURRENT:
if (MAC_ADDRESS_EQUAL(&(lacpdu->actor_system),
&(port->actor_system))) {
netdev_err(port->slave->bond->dev, "An illegal loopback occurred on adapter (%s)\n"
"Check the configuration to verify that all adapters are connected to 802.3ad compliant switch ports\n",
port->slave->dev->name);
return;
}
__update_selected(lacpdu, port);
__update_ntt(lacpdu, port);
__record_pdu(lacpdu, port);
port->sm_rx_timer_counter = __ad_timer_to_ticks(AD_CURRENT_WHILE_TIMER, (u16)(port->actor_oper_port_state & AD_STATE_LACP_TIMEOUT));
port->actor_oper_port_state &= ~AD_STATE_EXPIRED;
break;
default:
break;
}
}
}
static void ad_churn_machine(struct port *port)
{
if (port->sm_vars & AD_PORT_CHURNED) {
port->sm_vars &= ~AD_PORT_CHURNED;
port->sm_churn_actor_state = AD_CHURN_MONITOR;
port->sm_churn_partner_state = AD_CHURN_MONITOR;
port->sm_churn_actor_timer_counter =
__ad_timer_to_ticks(AD_ACTOR_CHURN_TIMER, 0);
port->sm_churn_partner_timer_counter =
__ad_timer_to_ticks(AD_PARTNER_CHURN_TIMER, 0);
return;
}
if (port->sm_churn_actor_timer_counter &&
!(--port->sm_churn_actor_timer_counter) &&
port->sm_churn_actor_state == AD_CHURN_MONITOR) {
if (port->actor_oper_port_state & AD_STATE_SYNCHRONIZATION) {
port->sm_churn_actor_state = AD_NO_CHURN;
} else {
port->churn_actor_count++;
port->sm_churn_actor_state = AD_CHURN;
}
}
if (port->sm_churn_partner_timer_counter &&
!(--port->sm_churn_partner_timer_counter) &&
port->sm_churn_partner_state == AD_CHURN_MONITOR) {
if (port->partner_oper.port_state & AD_STATE_SYNCHRONIZATION) {
port->sm_churn_partner_state = AD_NO_CHURN;
} else {
port->churn_partner_count++;
port->sm_churn_partner_state = AD_CHURN;
}
}
}
static void ad_tx_machine(struct port *port)
{
if (port->sm_tx_timer_counter && !(--port->sm_tx_timer_counter)) {
if (port->ntt && (port->sm_vars & AD_PORT_LACP_ENABLED)) {
__update_lacpdu_from_port(port);
if (ad_lacpdu_send(port) >= 0) {
pr_debug("Sent LACPDU on port %d\n",
port->actor_port_number);
port->ntt = false;
}
}
port->sm_tx_timer_counter = ad_ticks_per_sec/AD_MAX_TX_IN_SECOND;
}
}
static void ad_periodic_machine(struct port *port)
{
periodic_states_t last_state;
last_state = port->sm_periodic_state;
if (((port->sm_vars & AD_PORT_BEGIN) || !(port->sm_vars & AD_PORT_LACP_ENABLED) || !port->is_enabled) ||
(!(port->actor_oper_port_state & AD_STATE_LACP_ACTIVITY) && !(port->partner_oper.port_state & AD_STATE_LACP_ACTIVITY))
) {
port->sm_periodic_state = AD_NO_PERIODIC;
}
else if (port->sm_periodic_timer_counter) {
if (!(--port->sm_periodic_timer_counter)) {
port->sm_periodic_state = AD_PERIODIC_TX;
} else {
switch (port->sm_periodic_state) {
case AD_FAST_PERIODIC:
if (!(port->partner_oper.port_state
& AD_STATE_LACP_TIMEOUT))
port->sm_periodic_state = AD_SLOW_PERIODIC;
break;
case AD_SLOW_PERIODIC:
if ((port->partner_oper.port_state & AD_STATE_LACP_TIMEOUT)) {
port->sm_periodic_timer_counter = 0;
port->sm_periodic_state = AD_PERIODIC_TX;
}
break;
default:
break;
}
}
} else {
switch (port->sm_periodic_state) {
case AD_NO_PERIODIC:
port->sm_periodic_state = AD_FAST_PERIODIC;
break;
case AD_PERIODIC_TX:
if (!(port->partner_oper.port_state &
AD_STATE_LACP_TIMEOUT))
port->sm_periodic_state = AD_SLOW_PERIODIC;
else
port->sm_periodic_state = AD_FAST_PERIODIC;
break;
default:
break;
}
}
if (port->sm_periodic_state != last_state) {
pr_debug("Periodic Machine: Port=%d, Last State=%d, Curr State=%d\n",
port->actor_port_number, last_state,
port->sm_periodic_state);
switch (port->sm_periodic_state) {
case AD_NO_PERIODIC:
port->sm_periodic_timer_counter = 0;
break;
case AD_FAST_PERIODIC:
port->sm_periodic_timer_counter = __ad_timer_to_ticks(AD_PERIODIC_TIMER, (u16)(AD_FAST_PERIODIC_TIME))-1;
break;
case AD_SLOW_PERIODIC:
port->sm_periodic_timer_counter = __ad_timer_to_ticks(AD_PERIODIC_TIMER, (u16)(AD_SLOW_PERIODIC_TIME))-1;
break;
case AD_PERIODIC_TX:
port->ntt = true;
break;
default:
break;
}
}
}
static void ad_port_selection_logic(struct port *port, bool *update_slave_arr)
{
struct aggregator *aggregator, *free_aggregator = NULL, *temp_aggregator;
struct port *last_port = NULL, *curr_port;
struct list_head *iter;
struct bonding *bond;
struct slave *slave;
int found = 0;
if (port->sm_vars & AD_PORT_SELECTED)
return;
bond = __get_bond_by_port(port);
if (port->aggregator) {
temp_aggregator = port->aggregator;
for (curr_port = temp_aggregator->lag_ports; curr_port;
last_port = curr_port,
curr_port = curr_port->next_port_in_aggregator) {
if (curr_port == port) {
temp_aggregator->num_of_ports--;
if (!last_port) {
temp_aggregator->lag_ports =
port->next_port_in_aggregator;
} else {
last_port->next_port_in_aggregator =
port->next_port_in_aggregator;
}
port->aggregator = NULL;
port->next_port_in_aggregator = NULL;
port->actor_port_aggregator_identifier = 0;
netdev_dbg(bond->dev, "Port %d left LAG %d\n",
port->actor_port_number,
temp_aggregator->aggregator_identifier);
if (!temp_aggregator->lag_ports)
ad_clear_agg(temp_aggregator);
break;
}
}
if (!curr_port) {
net_warn_ratelimited("%s: Warning: Port %d (on %s) was related to aggregator %d but was not on its port list\n",
port->slave->bond->dev->name,
port->actor_port_number,
port->slave->dev->name,
port->aggregator->aggregator_identifier);
}
}
bond_for_each_slave(bond, slave, iter) {
aggregator = &(SLAVE_AD_INFO(slave)->aggregator);
if (!aggregator->lag_ports) {
if (!free_aggregator)
free_aggregator = aggregator;
continue;
}
if (((aggregator->actor_oper_aggregator_key == port->actor_oper_port_key) &&
MAC_ADDRESS_EQUAL(&(aggregator->partner_system), &(port->partner_oper.system)) &&
(aggregator->partner_system_priority == port->partner_oper.system_priority) &&
(aggregator->partner_oper_aggregator_key == port->partner_oper.key)
) &&
((!MAC_ADDRESS_EQUAL(&(port->partner_oper.system), &(null_mac_addr)) &&
!aggregator->is_individual)
)
) {
port->aggregator = aggregator;
port->actor_port_aggregator_identifier =
port->aggregator->aggregator_identifier;
port->next_port_in_aggregator = aggregator->lag_ports;
port->aggregator->num_of_ports++;
aggregator->lag_ports = port;
netdev_dbg(bond->dev, "Port %d joined LAG %d(existing LAG)\n",
port->actor_port_number,
port->aggregator->aggregator_identifier);
port->sm_vars |= AD_PORT_SELECTED;
found = 1;
break;
}
}
if (!found) {
if (free_aggregator) {
port->aggregator = free_aggregator;
port->actor_port_aggregator_identifier =
port->aggregator->aggregator_identifier;
if (port->actor_oper_port_key & AD_DUPLEX_KEY_MASKS)
port->aggregator->is_individual = false;
else
port->aggregator->is_individual = true;
port->aggregator->actor_admin_aggregator_key =
port->actor_admin_port_key;
port->aggregator->actor_oper_aggregator_key =
port->actor_oper_port_key;
port->aggregator->partner_system =
port->partner_oper.system;
port->aggregator->partner_system_priority =
port->partner_oper.system_priority;
port->aggregator->partner_oper_aggregator_key = port->partner_oper.key;
port->aggregator->receive_state = 1;
port->aggregator->transmit_state = 1;
port->aggregator->lag_ports = port;
port->aggregator->num_of_ports++;
port->sm_vars |= AD_PORT_SELECTED;
netdev_dbg(bond->dev, "Port %d joined LAG %d(new LAG)\n",
port->actor_port_number,
port->aggregator->aggregator_identifier);
} else {
netdev_err(bond->dev, "Port %d (on %s) did not find a suitable aggregator\n",
port->actor_port_number, port->slave->dev->name);
}
}
__set_agg_ports_ready(port->aggregator,
__agg_ports_are_ready(port->aggregator));
aggregator = __get_first_agg(port);
ad_agg_selection_logic(aggregator, update_slave_arr);
if (!port->aggregator->is_active)
port->actor_oper_port_state &= ~AD_STATE_SYNCHRONIZATION;
}
static struct aggregator *ad_agg_selection_test(struct aggregator *best,
struct aggregator *curr)
{
if (!best)
return curr;
if (!curr->is_individual && best->is_individual)
return curr;
if (curr->is_individual && !best->is_individual)
return best;
if (__agg_has_partner(curr) && !__agg_has_partner(best))
return curr;
if (!__agg_has_partner(curr) && __agg_has_partner(best))
return best;
switch (__get_agg_selection_mode(curr->lag_ports)) {
case BOND_AD_COUNT:
if (curr->num_of_ports > best->num_of_ports)
return curr;
if (curr->num_of_ports < best->num_of_ports)
return best;
case BOND_AD_STABLE:
case BOND_AD_BANDWIDTH:
if (__get_agg_bandwidth(curr) > __get_agg_bandwidth(best))
return curr;
break;
default:
net_warn_ratelimited("%s: Impossible agg select mode %d\n",
curr->slave->bond->dev->name,
__get_agg_selection_mode(curr->lag_ports));
break;
}
return best;
}
static int agg_device_up(const struct aggregator *agg)
{
struct port *port = agg->lag_ports;
if (!port)
return 0;
return netif_running(port->slave->dev) &&
netif_carrier_ok(port->slave->dev);
}
static void ad_agg_selection_logic(struct aggregator *agg,
bool *update_slave_arr)
{
struct aggregator *best, *active, *origin;
struct bonding *bond = agg->slave->bond;
struct list_head *iter;
struct slave *slave;
struct port *port;
rcu_read_lock();
origin = agg;
active = __get_active_agg(agg);
best = (active && agg_device_up(active)) ? active : NULL;
bond_for_each_slave_rcu(bond, slave, iter) {
agg = &(SLAVE_AD_INFO(slave)->aggregator);
agg->is_active = 0;
if (agg->num_of_ports && agg_device_up(agg))
best = ad_agg_selection_test(best, agg);
}
if (best &&
__get_agg_selection_mode(best->lag_ports) == BOND_AD_STABLE) {
if (active && active->lag_ports &&
active->lag_ports->is_enabled &&
(__agg_has_partner(active) ||
(!__agg_has_partner(active) &&
!__agg_has_partner(best)))) {
if (!(!active->actor_oper_aggregator_key &&
best->actor_oper_aggregator_key)) {
best = NULL;
active->is_active = 1;
}
}
}
if (best && (best == active)) {
best = NULL;
active->is_active = 1;
}
if (best) {
netdev_dbg(bond->dev, "best Agg=%d; P=%d; a k=%d; p k=%d; Ind=%d; Act=%d\n",
best->aggregator_identifier, best->num_of_ports,
best->actor_oper_aggregator_key,
best->partner_oper_aggregator_key,
best->is_individual, best->is_active);
netdev_dbg(bond->dev, "best ports %p slave %p %s\n",
best->lag_ports, best->slave,
best->slave ? best->slave->dev->name : "NULL");
bond_for_each_slave_rcu(bond, slave, iter) {
agg = &(SLAVE_AD_INFO(slave)->aggregator);
netdev_dbg(bond->dev, "Agg=%d; P=%d; a k=%d; p k=%d; Ind=%d; Act=%d\n",
agg->aggregator_identifier, agg->num_of_ports,
agg->actor_oper_aggregator_key,
agg->partner_oper_aggregator_key,
agg->is_individual, agg->is_active);
}
if (best->is_individual) {
net_warn_ratelimited("%s: Warning: No 802.3ad response from the link partner for any adapters in the bond\n",
best->slave ?
best->slave->bond->dev->name : "NULL");
}
best->is_active = 1;
netdev_dbg(bond->dev, "LAG %d chosen as the active LAG\n",
best->aggregator_identifier);
netdev_dbg(bond->dev, "Agg=%d; P=%d; a k=%d; p k=%d; Ind=%d; Act=%d\n",
best->aggregator_identifier, best->num_of_ports,
best->actor_oper_aggregator_key,
best->partner_oper_aggregator_key,
best->is_individual, best->is_active);
if (active) {
for (port = active->lag_ports; port;
port = port->next_port_in_aggregator) {
__disable_port(port);
}
}
*update_slave_arr = true;
}
active = __get_active_agg(origin);
if (active) {
if (!__agg_has_partner(active)) {
for (port = active->lag_ports; port;
port = port->next_port_in_aggregator) {
__enable_port(port);
}
}
}
rcu_read_unlock();
bond_3ad_set_carrier(bond);
}
static void ad_clear_agg(struct aggregator *aggregator)
{
if (aggregator) {
aggregator->is_individual = false;
aggregator->actor_admin_aggregator_key = 0;
aggregator->actor_oper_aggregator_key = 0;
aggregator->partner_system = null_mac_addr;
aggregator->partner_system_priority = 0;
aggregator->partner_oper_aggregator_key = 0;
aggregator->receive_state = 0;
aggregator->transmit_state = 0;
aggregator->lag_ports = NULL;
aggregator->is_active = 0;
aggregator->num_of_ports = 0;
pr_debug("LAG %d was cleared\n",
aggregator->aggregator_identifier);
}
}
static void ad_initialize_agg(struct aggregator *aggregator)
{
if (aggregator) {
ad_clear_agg(aggregator);
aggregator->aggregator_mac_address = null_mac_addr;
aggregator->aggregator_identifier = 0;
aggregator->slave = NULL;
}
}
static void ad_initialize_port(struct port *port, int lacp_fast)
{
static const struct port_params tmpl = {
.system_priority = 0xffff,
.key = 1,
.port_number = 1,
.port_priority = 0xff,
.port_state = 1,
};
static const struct lacpdu lacpdu = {
.subtype = 0x01,
.version_number = 0x01,
.tlv_type_actor_info = 0x01,
.actor_information_length = 0x14,
.tlv_type_partner_info = 0x02,
.partner_information_length = 0x14,
.tlv_type_collector_info = 0x03,
.collector_information_length = 0x10,
.collector_max_delay = htons(AD_COLLECTOR_MAX_DELAY),
};
if (port) {
port->actor_port_priority = 0xff;
port->actor_port_aggregator_identifier = 0;
port->ntt = false;
port->actor_admin_port_state = AD_STATE_AGGREGATION |
AD_STATE_LACP_ACTIVITY;
port->actor_oper_port_state = AD_STATE_AGGREGATION |
AD_STATE_LACP_ACTIVITY;
if (lacp_fast)
port->actor_oper_port_state |= AD_STATE_LACP_TIMEOUT;
memcpy(&port->partner_admin, &tmpl, sizeof(tmpl));
memcpy(&port->partner_oper, &tmpl, sizeof(tmpl));
port->is_enabled = true;
port->sm_vars = AD_PORT_BEGIN | AD_PORT_LACP_ENABLED;
port->sm_rx_state = 0;
port->sm_rx_timer_counter = 0;
port->sm_periodic_state = 0;
port->sm_periodic_timer_counter = 0;
port->sm_mux_state = 0;
port->sm_mux_timer_counter = 0;
port->sm_tx_state = 0;
port->aggregator = NULL;
port->next_port_in_aggregator = NULL;
port->transaction_id = 0;
port->sm_churn_actor_timer_counter = 0;
port->sm_churn_actor_state = 0;
port->churn_actor_count = 0;
port->sm_churn_partner_timer_counter = 0;
port->sm_churn_partner_state = 0;
port->churn_partner_count = 0;
memcpy(&port->lacpdu, &lacpdu, sizeof(lacpdu));
}
}
static void ad_enable_collecting_distributing(struct port *port,
bool *update_slave_arr)
{
if (port->aggregator->is_active) {
pr_debug("Enabling port %d(LAG %d)\n",
port->actor_port_number,
port->aggregator->aggregator_identifier);
__enable_port(port);
*update_slave_arr = true;
}
}
static void ad_disable_collecting_distributing(struct port *port,
bool *update_slave_arr)
{
if (port->aggregator &&
!MAC_ADDRESS_EQUAL(&(port->aggregator->partner_system),
&(null_mac_addr))) {
pr_debug("Disabling port %d(LAG %d)\n",
port->actor_port_number,
port->aggregator->aggregator_identifier);
__disable_port(port);
*update_slave_arr = true;
}
}
static void ad_marker_info_received(struct bond_marker *marker_info,
struct port *port)
{
struct bond_marker marker;
memcpy(&marker, marker_info, sizeof(struct bond_marker));
marker.tlv_type = AD_MARKER_RESPONSE_SUBTYPE;
if (ad_marker_send(port, &marker) >= 0) {
pr_debug("Sent Marker Response on port %d\n",
port->actor_port_number);
}
}
static void ad_marker_response_received(struct bond_marker *marker,
struct port *port)
{
}
void bond_3ad_initiate_agg_selection(struct bonding *bond, int timeout)
{
BOND_AD_INFO(bond).agg_select_timer = timeout;
}
void bond_3ad_initialize(struct bonding *bond, u16 tick_resolution)
{
if (!MAC_ADDRESS_EQUAL(&(BOND_AD_INFO(bond).system.sys_mac_addr),
bond->dev->dev_addr)) {
BOND_AD_INFO(bond).aggregator_identifier = 0;
BOND_AD_INFO(bond).system.sys_priority =
bond->params.ad_actor_sys_prio;
if (is_zero_ether_addr(bond->params.ad_actor_system))
BOND_AD_INFO(bond).system.sys_mac_addr =
*((struct mac_addr *)bond->dev->dev_addr);
else
BOND_AD_INFO(bond).system.sys_mac_addr =
*((struct mac_addr *)bond->params.ad_actor_system);
ad_ticks_per_sec = tick_resolution;
bond_3ad_initiate_agg_selection(bond,
AD_AGGREGATOR_SELECTION_TIMER *
ad_ticks_per_sec);
}
}
void bond_3ad_bind_slave(struct slave *slave)
{
struct bonding *bond = bond_get_bond_by_slave(slave);
struct port *port;
struct aggregator *aggregator;
if (SLAVE_AD_INFO(slave)->port.slave != slave) {
port = &(SLAVE_AD_INFO(slave)->port);
ad_initialize_port(port, bond->params.lacp_fast);
port->slave = slave;
port->actor_port_number = SLAVE_AD_INFO(slave)->id;
port->actor_admin_port_key = bond->params.ad_user_port_key << 6;
ad_update_actor_keys(port, false);
__ad_actor_update_port(port);
port->sm_tx_timer_counter = ad_ticks_per_sec/AD_MAX_TX_IN_SECOND;
__disable_port(port);
aggregator = &(SLAVE_AD_INFO(slave)->aggregator);
ad_initialize_agg(aggregator);
aggregator->aggregator_mac_address = *((struct mac_addr *)bond->dev->dev_addr);
aggregator->aggregator_identifier = ++BOND_AD_INFO(bond).aggregator_identifier;
aggregator->slave = slave;
aggregator->is_active = 0;
aggregator->num_of_ports = 0;
}
}
void bond_3ad_unbind_slave(struct slave *slave)
{
struct port *port, *prev_port, *temp_port;
struct aggregator *aggregator, *new_aggregator, *temp_aggregator;
int select_new_active_agg = 0;
struct bonding *bond = slave->bond;
struct slave *slave_iter;
struct list_head *iter;
bool dummy_slave_update;
spin_lock_bh(&bond->mode_lock);
aggregator = &(SLAVE_AD_INFO(slave)->aggregator);
port = &(SLAVE_AD_INFO(slave)->port);
if (!port->slave) {
netdev_warn(bond->dev, "Trying to unbind an uninitialized port on %s\n",
slave->dev->name);
goto out;
}
netdev_dbg(bond->dev, "Unbinding Link Aggregation Group %d\n",
aggregator->aggregator_identifier);
port->actor_oper_port_state &= ~AD_STATE_AGGREGATION;
__update_lacpdu_from_port(port);
ad_lacpdu_send(port);
if (aggregator->lag_ports) {
if ((aggregator->lag_ports != port) ||
(aggregator->lag_ports->next_port_in_aggregator)) {
bond_for_each_slave(bond, slave_iter, iter) {
new_aggregator = &(SLAVE_AD_INFO(slave_iter)->aggregator);
if (!new_aggregator->lag_ports ||
((new_aggregator->lag_ports == port) &&
!new_aggregator->lag_ports->next_port_in_aggregator))
break;
}
if (!slave_iter)
new_aggregator = NULL;
if ((new_aggregator) && ((!new_aggregator->lag_ports) || ((new_aggregator->lag_ports == port) && !new_aggregator->lag_ports->next_port_in_aggregator))) {
netdev_dbg(bond->dev, "Some port(s) related to LAG %d - replacing with LAG %d\n",
aggregator->aggregator_identifier,
new_aggregator->aggregator_identifier);
if ((new_aggregator->lag_ports == port) &&
new_aggregator->is_active) {
netdev_info(bond->dev, "Removing an active aggregator\n");
select_new_active_agg = 1;
}
new_aggregator->is_individual = aggregator->is_individual;
new_aggregator->actor_admin_aggregator_key = aggregator->actor_admin_aggregator_key;
new_aggregator->actor_oper_aggregator_key = aggregator->actor_oper_aggregator_key;
new_aggregator->partner_system = aggregator->partner_system;
new_aggregator->partner_system_priority = aggregator->partner_system_priority;
new_aggregator->partner_oper_aggregator_key = aggregator->partner_oper_aggregator_key;
new_aggregator->receive_state = aggregator->receive_state;
new_aggregator->transmit_state = aggregator->transmit_state;
new_aggregator->lag_ports = aggregator->lag_ports;
new_aggregator->is_active = aggregator->is_active;
new_aggregator->num_of_ports = aggregator->num_of_ports;
for (temp_port = aggregator->lag_ports; temp_port;
temp_port = temp_port->next_port_in_aggregator) {
temp_port->aggregator = new_aggregator;
temp_port->actor_port_aggregator_identifier = new_aggregator->aggregator_identifier;
}
ad_clear_agg(aggregator);
if (select_new_active_agg)
ad_agg_selection_logic(__get_first_agg(port),
&dummy_slave_update);
} else {
netdev_warn(bond->dev, "unbinding aggregator, and could not find a new aggregator for its ports\n");
}
} else {
select_new_active_agg = aggregator->is_active;
ad_clear_agg(aggregator);
if (select_new_active_agg) {
netdev_info(bond->dev, "Removing an active aggregator\n");
temp_aggregator = __get_first_agg(port);
if (temp_aggregator)
ad_agg_selection_logic(temp_aggregator,
&dummy_slave_update);
}
}
}
netdev_dbg(bond->dev, "Unbinding port %d\n", port->actor_port_number);
bond_for_each_slave(bond, slave_iter, iter) {
temp_aggregator = &(SLAVE_AD_INFO(slave_iter)->aggregator);
prev_port = NULL;
for (temp_port = temp_aggregator->lag_ports; temp_port;
prev_port = temp_port,
temp_port = temp_port->next_port_in_aggregator) {
if (temp_port == port) {
if (prev_port)
prev_port->next_port_in_aggregator = temp_port->next_port_in_aggregator;
else
temp_aggregator->lag_ports = temp_port->next_port_in_aggregator;
temp_aggregator->num_of_ports--;
if (temp_aggregator->num_of_ports == 0) {
select_new_active_agg = temp_aggregator->is_active;
ad_clear_agg(temp_aggregator);
if (select_new_active_agg) {
netdev_info(bond->dev, "Removing an active aggregator\n");
ad_agg_selection_logic(__get_first_agg(port),
&dummy_slave_update);
}
}
break;
}
}
}
port->slave = NULL;
out:
spin_unlock_bh(&bond->mode_lock);
}
void bond_3ad_update_ad_actor_settings(struct bonding *bond)
{
struct list_head *iter;
struct slave *slave;
ASSERT_RTNL();
BOND_AD_INFO(bond).system.sys_priority = bond->params.ad_actor_sys_prio;
if (is_zero_ether_addr(bond->params.ad_actor_system))
BOND_AD_INFO(bond).system.sys_mac_addr =
*((struct mac_addr *)bond->dev->dev_addr);
else
BOND_AD_INFO(bond).system.sys_mac_addr =
*((struct mac_addr *)bond->params.ad_actor_system);
spin_lock_bh(&bond->mode_lock);
bond_for_each_slave(bond, slave, iter) {
struct port *port = &(SLAVE_AD_INFO(slave))->port;
__ad_actor_update_port(port);
port->ntt = true;
}
spin_unlock_bh(&bond->mode_lock);
}
void bond_3ad_state_machine_handler(struct work_struct *work)
{
struct bonding *bond = container_of(work, struct bonding,
ad_work.work);
struct aggregator *aggregator;
struct list_head *iter;
struct slave *slave;
struct port *port;
bool should_notify_rtnl = BOND_SLAVE_NOTIFY_LATER;
bool update_slave_arr = false;
spin_lock_bh(&bond->mode_lock);
rcu_read_lock();
if (!bond_has_slaves(bond))
goto re_arm;
if (BOND_AD_INFO(bond).agg_select_timer &&
!(--BOND_AD_INFO(bond).agg_select_timer)) {
slave = bond_first_slave_rcu(bond);
port = slave ? &(SLAVE_AD_INFO(slave)->port) : NULL;
if (port) {
if (!port->slave) {
net_warn_ratelimited("%s: Warning: bond's first port is uninitialized\n",
bond->dev->name);
goto re_arm;
}
aggregator = __get_first_agg(port);
ad_agg_selection_logic(aggregator, &update_slave_arr);
}
bond_3ad_set_carrier(bond);
}
bond_for_each_slave_rcu(bond, slave, iter) {
port = &(SLAVE_AD_INFO(slave)->port);
if (!port->slave) {
net_warn_ratelimited("%s: Warning: Found an uninitialized port\n",
bond->dev->name);
goto re_arm;
}
ad_rx_machine(NULL, port);
ad_periodic_machine(port);
ad_port_selection_logic(port, &update_slave_arr);
ad_mux_machine(port, &update_slave_arr);
ad_tx_machine(port);
ad_churn_machine(port);
if (port->sm_vars & AD_PORT_BEGIN)
port->sm_vars &= ~AD_PORT_BEGIN;
}
re_arm:
bond_for_each_slave_rcu(bond, slave, iter) {
if (slave->should_notify) {
should_notify_rtnl = BOND_SLAVE_NOTIFY_NOW;
break;
}
}
rcu_read_unlock();
spin_unlock_bh(&bond->mode_lock);
if (update_slave_arr)
bond_slave_arr_work_rearm(bond, 0);
if (should_notify_rtnl && rtnl_trylock()) {
bond_slave_state_notify(bond);
rtnl_unlock();
}
queue_delayed_work(bond->wq, &bond->ad_work, ad_delta_in_ticks);
}
static int bond_3ad_rx_indication(struct lacpdu *lacpdu, struct slave *slave,
u16 length)
{
struct port *port;
int ret = RX_HANDLER_ANOTHER;
if (length >= sizeof(struct lacpdu)) {
port = &(SLAVE_AD_INFO(slave)->port);
if (!port->slave) {
net_warn_ratelimited("%s: Warning: port of slave %s is uninitialized\n",
slave->dev->name, slave->bond->dev->name);
return ret;
}
switch (lacpdu->subtype) {
case AD_TYPE_LACPDU:
ret = RX_HANDLER_CONSUMED;
netdev_dbg(slave->bond->dev,
"Received LACPDU on port %d slave %s\n",
port->actor_port_number,
slave->dev->name);
spin_lock(&slave->bond->mode_lock);
ad_rx_machine(lacpdu, port);
spin_unlock(&slave->bond->mode_lock);
break;
case AD_TYPE_MARKER:
ret = RX_HANDLER_CONSUMED;
switch (((struct bond_marker *)lacpdu)->tlv_type) {
case AD_MARKER_INFORMATION_SUBTYPE:
netdev_dbg(slave->bond->dev, "Received Marker Information on port %d\n",
port->actor_port_number);
ad_marker_info_received((struct bond_marker *)lacpdu, port);
break;
case AD_MARKER_RESPONSE_SUBTYPE:
netdev_dbg(slave->bond->dev, "Received Marker Response on port %d\n",
port->actor_port_number);
ad_marker_response_received((struct bond_marker *)lacpdu, port);
break;
default:
netdev_dbg(slave->bond->dev, "Received an unknown Marker subtype on slot %d\n",
port->actor_port_number);
}
}
}
return ret;
}
static void ad_update_actor_keys(struct port *port, bool reset)
{
u8 duplex = 0;
u16 ospeed = 0, speed = 0;
u16 old_oper_key = port->actor_oper_port_key;
port->actor_admin_port_key &= ~(AD_SPEED_KEY_MASKS|AD_DUPLEX_KEY_MASKS);
if (!reset) {
speed = __get_link_speed(port);
ospeed = (old_oper_key & AD_SPEED_KEY_MASKS) >> 1;
duplex = __get_duplex(port);
port->actor_admin_port_key |= (speed << 1) | duplex;
}
port->actor_oper_port_key = port->actor_admin_port_key;
if (old_oper_key != port->actor_oper_port_key) {
if (duplex)
port->sm_vars |= AD_PORT_LACP_ENABLED;
else
port->sm_vars &= ~AD_PORT_LACP_ENABLED;
if (!reset) {
if (!speed) {
netdev_err(port->slave->dev,
"speed changed to 0 for port %s",
port->slave->dev->name);
} else if (duplex && ospeed != speed) {
port->sm_vars |= AD_PORT_BEGIN;
}
}
}
}
void bond_3ad_adapter_speed_duplex_changed(struct slave *slave)
{
struct port *port;
port = &(SLAVE_AD_INFO(slave)->port);
if (!port->slave) {
netdev_warn(slave->bond->dev,
"speed/duplex changed for uninitialized port %s\n",
slave->dev->name);
return;
}
spin_lock_bh(&slave->bond->mode_lock);
ad_update_actor_keys(port, false);
netdev_dbg(slave->bond->dev, "Port %d slave %s changed speed/duplex\n",
port->actor_port_number, slave->dev->name);
spin_unlock_bh(&slave->bond->mode_lock);
}
void bond_3ad_handle_link_change(struct slave *slave, char link)
{
struct port *port;
port = &(SLAVE_AD_INFO(slave)->port);
if (!port->slave) {
netdev_warn(slave->bond->dev, "link status changed for uninitialized port on %s\n",
slave->dev->name);
return;
}
spin_lock_bh(&slave->bond->mode_lock);
if (link == BOND_LINK_UP) {
port->is_enabled = true;
ad_update_actor_keys(port, false);
} else {
port->is_enabled = false;
ad_update_actor_keys(port, true);
}
netdev_dbg(slave->bond->dev, "Port %d changed link status to %s\n",
port->actor_port_number,
link == BOND_LINK_UP ? "UP" : "DOWN");
spin_unlock_bh(&slave->bond->mode_lock);
bond_update_slave_arr(slave->bond, NULL);
}
int bond_3ad_set_carrier(struct bonding *bond)
{
struct aggregator *active;
struct slave *first_slave;
int ret = 1;
rcu_read_lock();
first_slave = bond_first_slave_rcu(bond);
if (!first_slave) {
ret = 0;
goto out;
}
active = __get_active_agg(&(SLAVE_AD_INFO(first_slave)->aggregator));
if (active) {
if (active->num_of_ports < bond->params.min_links) {
if (netif_carrier_ok(bond->dev)) {
netif_carrier_off(bond->dev);
goto out;
}
} else if (!netif_carrier_ok(bond->dev)) {
netif_carrier_on(bond->dev);
goto out;
}
} else if (netif_carrier_ok(bond->dev)) {
netif_carrier_off(bond->dev);
}
out:
rcu_read_unlock();
return ret;
}
int __bond_3ad_get_active_agg_info(struct bonding *bond,
struct ad_info *ad_info)
{
struct aggregator *aggregator = NULL;
struct list_head *iter;
struct slave *slave;
struct port *port;
bond_for_each_slave_rcu(bond, slave, iter) {
port = &(SLAVE_AD_INFO(slave)->port);
if (port->aggregator && port->aggregator->is_active) {
aggregator = port->aggregator;
break;
}
}
if (!aggregator)
return -1;
ad_info->aggregator_id = aggregator->aggregator_identifier;
ad_info->ports = aggregator->num_of_ports;
ad_info->actor_key = aggregator->actor_oper_aggregator_key;
ad_info->partner_key = aggregator->partner_oper_aggregator_key;
ether_addr_copy(ad_info->partner_system,
aggregator->partner_system.mac_addr_value);
return 0;
}
int bond_3ad_get_active_agg_info(struct bonding *bond, struct ad_info *ad_info)
{
int ret;
rcu_read_lock();
ret = __bond_3ad_get_active_agg_info(bond, ad_info);
rcu_read_unlock();
return ret;
}
int bond_3ad_lacpdu_recv(const struct sk_buff *skb, struct bonding *bond,
struct slave *slave)
{
struct lacpdu *lacpdu, _lacpdu;
if (skb->protocol != PKT_TYPE_LACPDU)
return RX_HANDLER_ANOTHER;
if (!MAC_ADDRESS_EQUAL(eth_hdr(skb)->h_dest, lacpdu_mcast_addr))
return RX_HANDLER_ANOTHER;
lacpdu = skb_header_pointer(skb, 0, sizeof(_lacpdu), &_lacpdu);
if (!lacpdu)
return RX_HANDLER_ANOTHER;
return bond_3ad_rx_indication(lacpdu, slave, skb->len);
}
void bond_3ad_update_lacp_rate(struct bonding *bond)
{
struct port *port = NULL;
struct list_head *iter;
struct slave *slave;
int lacp_fast;
lacp_fast = bond->params.lacp_fast;
spin_lock_bh(&bond->mode_lock);
bond_for_each_slave(bond, slave, iter) {
port = &(SLAVE_AD_INFO(slave)->port);
if (lacp_fast)
port->actor_oper_port_state |= AD_STATE_LACP_TIMEOUT;
else
port->actor_oper_port_state &= ~AD_STATE_LACP_TIMEOUT;
}
spin_unlock_bh(&bond->mode_lock);
}
