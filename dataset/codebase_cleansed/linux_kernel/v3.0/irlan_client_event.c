void irlan_do_client_event(struct irlan_cb *self, IRLAN_EVENT event,
struct sk_buff *skb)
{
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRLAN_MAGIC, return;);
(*state[ self->client.state]) (self, event, skb);
}
static int irlan_client_state_idle(struct irlan_cb *self, IRLAN_EVENT event,
struct sk_buff *skb)
{
IRDA_DEBUG(4, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRLAN_MAGIC, return -1;);
switch (event) {
case IRLAN_DISCOVERY_INDICATION:
if (self->client.iriap) {
IRDA_WARNING("%s(), busy with a previous query\n",
__func__);
return -EBUSY;
}
self->client.iriap = iriap_open(LSAP_ANY, IAS_CLIENT, self,
irlan_client_get_value_confirm);
irlan_next_client_state(self, IRLAN_QUERY);
iriap_getvaluebyclass_request(self->client.iriap,
self->saddr, self->daddr,
"IrLAN", "IrDA:TinyTP:LsapSel");
break;
case IRLAN_WATCHDOG_TIMEOUT:
IRDA_DEBUG(2, "%s(), IRLAN_WATCHDOG_TIMEOUT\n", __func__ );
break;
default:
IRDA_DEBUG(4, "%s(), Unknown event %d\n", __func__ , event);
break;
}
if (skb)
dev_kfree_skb(skb);
return 0;
}
static int irlan_client_state_query(struct irlan_cb *self, IRLAN_EVENT event,
struct sk_buff *skb)
{
IRDA_DEBUG(4, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRLAN_MAGIC, return -1;);
switch(event) {
case IRLAN_IAS_PROVIDER_AVAIL:
IRDA_ASSERT(self->dtsap_sel_ctrl != 0, return -1;);
self->client.open_retries = 0;
irttp_connect_request(self->client.tsap_ctrl,
self->dtsap_sel_ctrl,
self->saddr, self->daddr, NULL,
IRLAN_MTU, NULL);
irlan_next_client_state(self, IRLAN_CONN);
break;
case IRLAN_IAS_PROVIDER_NOT_AVAIL:
IRDA_DEBUG(2, "%s(), IAS_PROVIDER_NOT_AVAIL\n", __func__ );
irlan_next_client_state(self, IRLAN_IDLE);
if ((self->provider.access_type == ACCESS_PEER) &&
(self->provider.state != IRLAN_IDLE))
irlan_client_wakeup(self, self->saddr, self->daddr);
break;
case IRLAN_LMP_DISCONNECT:
case IRLAN_LAP_DISCONNECT:
irlan_next_client_state(self, IRLAN_IDLE);
break;
case IRLAN_WATCHDOG_TIMEOUT:
IRDA_DEBUG(2, "%s(), IRLAN_WATCHDOG_TIMEOUT\n", __func__ );
break;
default:
IRDA_DEBUG(2, "%s(), Unknown event %d\n", __func__ , event);
break;
}
if (skb)
dev_kfree_skb(skb);
return 0;
}
static int irlan_client_state_conn(struct irlan_cb *self, IRLAN_EVENT event,
struct sk_buff *skb)
{
IRDA_DEBUG(4, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return -1;);
switch (event) {
case IRLAN_CONNECT_COMPLETE:
irlan_get_provider_info(self);
irlan_next_client_state(self, IRLAN_INFO);
break;
case IRLAN_LMP_DISCONNECT:
case IRLAN_LAP_DISCONNECT:
irlan_next_client_state(self, IRLAN_IDLE);
break;
case IRLAN_WATCHDOG_TIMEOUT:
IRDA_DEBUG(2, "%s(), IRLAN_WATCHDOG_TIMEOUT\n", __func__ );
break;
default:
IRDA_DEBUG(2, "%s(), Unknown event %d\n", __func__ , event);
break;
}
if (skb)
dev_kfree_skb(skb);
return 0;
}
static int irlan_client_state_info(struct irlan_cb *self, IRLAN_EVENT event,
struct sk_buff *skb)
{
IRDA_DEBUG(4, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return -1;);
switch (event) {
case IRLAN_DATA_INDICATION:
IRDA_ASSERT(skb != NULL, return -1;);
irlan_client_parse_response(self, skb);
irlan_next_client_state(self, IRLAN_MEDIA);
irlan_get_media_char(self);
break;
case IRLAN_LMP_DISCONNECT:
case IRLAN_LAP_DISCONNECT:
irlan_next_client_state(self, IRLAN_IDLE);
break;
case IRLAN_WATCHDOG_TIMEOUT:
IRDA_DEBUG(2, "%s(), IRLAN_WATCHDOG_TIMEOUT\n", __func__ );
break;
default:
IRDA_DEBUG(2, "%s(), Unknown event %d\n", __func__ , event);
break;
}
if (skb)
dev_kfree_skb(skb);
return 0;
}
static int irlan_client_state_media(struct irlan_cb *self, IRLAN_EVENT event,
struct sk_buff *skb)
{
IRDA_DEBUG(4, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return -1;);
switch(event) {
case IRLAN_DATA_INDICATION:
irlan_client_parse_response(self, skb);
irlan_open_data_channel(self);
irlan_next_client_state(self, IRLAN_OPEN);
break;
case IRLAN_LMP_DISCONNECT:
case IRLAN_LAP_DISCONNECT:
irlan_next_client_state(self, IRLAN_IDLE);
break;
case IRLAN_WATCHDOG_TIMEOUT:
IRDA_DEBUG(2, "%s(), IRLAN_WATCHDOG_TIMEOUT\n", __func__ );
break;
default:
IRDA_DEBUG(2, "%s(), Unknown event %d\n", __func__ , event);
break;
}
if (skb)
dev_kfree_skb(skb);
return 0;
}
static int irlan_client_state_open(struct irlan_cb *self, IRLAN_EVENT event,
struct sk_buff *skb)
{
struct qos_info qos;
IRDA_DEBUG(4, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return -1;);
switch(event) {
case IRLAN_DATA_INDICATION:
irlan_client_parse_response(self, skb);
IRDA_ASSERT(self->dtsap_sel_data != 0, return -1;);
switch (self->client.access_type) {
case ACCESS_PEER:
if (self->provider.state == IRLAN_OPEN) {
irlan_next_client_state(self, IRLAN_ARB);
irlan_do_client_event(self, IRLAN_CHECK_CON_ARB,
NULL);
} else {
irlan_next_client_state(self, IRLAN_WAIT);
}
break;
case ACCESS_DIRECT:
case ACCESS_HOSTED:
qos.link_disc_time.bits = 0x01;
irttp_connect_request(self->tsap_data,
self->dtsap_sel_data,
self->saddr, self->daddr, &qos,
IRLAN_MTU, NULL);
irlan_next_client_state(self, IRLAN_DATA);
break;
default:
IRDA_DEBUG(2, "%s(), unknown access type!\n", __func__ );
break;
}
break;
case IRLAN_LMP_DISCONNECT:
case IRLAN_LAP_DISCONNECT:
irlan_next_client_state(self, IRLAN_IDLE);
break;
case IRLAN_WATCHDOG_TIMEOUT:
IRDA_DEBUG(2, "%s(), IRLAN_WATCHDOG_TIMEOUT\n", __func__ );
break;
default:
IRDA_DEBUG(2, "%s(), Unknown event %d\n", __func__ , event);
break;
}
if (skb)
dev_kfree_skb(skb);
return 0;
}
static int irlan_client_state_wait(struct irlan_cb *self, IRLAN_EVENT event,
struct sk_buff *skb)
{
IRDA_DEBUG(4, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return -1;);
switch(event) {
case IRLAN_PROVIDER_SIGNAL:
irlan_next_client_state(self, IRLAN_ARB);
irlan_do_client_event(self, IRLAN_CHECK_CON_ARB, NULL);
break;
case IRLAN_LMP_DISCONNECT:
case IRLAN_LAP_DISCONNECT:
irlan_next_client_state(self, IRLAN_IDLE);
break;
case IRLAN_WATCHDOG_TIMEOUT:
IRDA_DEBUG(2, "%s(), IRLAN_WATCHDOG_TIMEOUT\n", __func__ );
break;
default:
IRDA_DEBUG(2, "%s(), Unknown event %d\n", __func__ , event);
break;
}
if (skb)
dev_kfree_skb(skb);
return 0;
}
static int irlan_client_state_arb(struct irlan_cb *self, IRLAN_EVENT event,
struct sk_buff *skb)
{
struct qos_info qos;
IRDA_DEBUG(2, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return -1;);
switch(event) {
case IRLAN_CHECK_CON_ARB:
if (self->client.recv_arb_val == self->provider.send_arb_val) {
irlan_next_client_state(self, IRLAN_CLOSE);
irlan_close_data_channel(self);
} else if (self->client.recv_arb_val <
self->provider.send_arb_val)
{
qos.link_disc_time.bits = 0x01;
irlan_next_client_state(self, IRLAN_DATA);
irttp_connect_request(self->tsap_data,
self->dtsap_sel_data,
self->saddr, self->daddr, &qos,
IRLAN_MTU, NULL);
} else if (self->client.recv_arb_val >
self->provider.send_arb_val)
{
IRDA_DEBUG(2, "%s(), lost the battle :-(\n", __func__ );
}
break;
case IRLAN_DATA_CONNECT_INDICATION:
irlan_next_client_state(self, IRLAN_DATA);
break;
case IRLAN_LMP_DISCONNECT:
case IRLAN_LAP_DISCONNECT:
irlan_next_client_state(self, IRLAN_IDLE);
break;
case IRLAN_WATCHDOG_TIMEOUT:
IRDA_DEBUG(2, "%s(), IRLAN_WATCHDOG_TIMEOUT\n", __func__ );
break;
default:
IRDA_DEBUG(2, "%s(), Unknown event %d\n", __func__ , event);
break;
}
if (skb)
dev_kfree_skb(skb);
return 0;
}
static int irlan_client_state_data(struct irlan_cb *self, IRLAN_EVENT event,
struct sk_buff *skb)
{
IRDA_DEBUG(4, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRLAN_MAGIC, return -1;);
switch(event) {
case IRLAN_DATA_INDICATION:
irlan_client_parse_response(self, skb);
break;
case IRLAN_LMP_DISCONNECT:
case IRLAN_LAP_DISCONNECT:
irlan_next_client_state(self, IRLAN_IDLE);
break;
default:
IRDA_DEBUG(2, "%s(), Unknown event %d\n", __func__ , event);
break;
}
if (skb)
dev_kfree_skb(skb);
return 0;
}
static int irlan_client_state_close(struct irlan_cb *self, IRLAN_EVENT event,
struct sk_buff *skb)
{
IRDA_DEBUG(2, "%s()\n", __func__ );
if (skb)
dev_kfree_skb(skb);
return 0;
}
static int irlan_client_state_sync(struct irlan_cb *self, IRLAN_EVENT event,
struct sk_buff *skb)
{
IRDA_DEBUG(2, "%s()\n", __func__ );
if (skb)
dev_kfree_skb(skb);
return 0;
}
