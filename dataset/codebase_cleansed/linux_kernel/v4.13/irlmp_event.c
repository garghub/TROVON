static inline void irlmp_next_lap_state(struct lap_cb *self,
IRLMP_STATE state)
{
self->lap_state = state;
}
static inline void irlmp_next_lsap_state(struct lsap_cb *self,
LSAP_STATE state)
{
self->lsap_state = state;
}
int irlmp_do_lsap_event(struct lsap_cb *self, IRLMP_EVENT event,
struct sk_buff *skb)
{
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == LMP_LSAP_MAGIC, return -1;);
pr_debug("%s(), EVENT = %s, STATE = %s\n",
__func__, irlmp_event[event], irlsap_state[self->lsap_state]);
return (*lsap_state[self->lsap_state]) (self, event, skb);
}
void irlmp_do_lap_event(struct lap_cb *self, IRLMP_EVENT event,
struct sk_buff *skb)
{
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == LMP_LAP_MAGIC, return;);
pr_debug("%s(), EVENT = %s, STATE = %s\n", __func__,
irlmp_event[event],
irlmp_state[self->lap_state]);
(*lap_state[self->lap_state]) (self, event, skb);
}
void irlmp_discovery_timer_expired(void *data)
{
irlmp_do_expiry();
irlmp_do_discovery(sysctl_discovery_slots);
irlmp_start_discovery_timer(irlmp, sysctl_discovery_timeout * HZ);
}
void irlmp_watchdog_timer_expired(void *data)
{
struct lsap_cb *self = (struct lsap_cb *) data;
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == LMP_LSAP_MAGIC, return;);
irlmp_do_lsap_event(self, LM_WATCHDOG_TIMEOUT, NULL);
}
void irlmp_idle_timer_expired(void *data)
{
struct lap_cb *self = (struct lap_cb *) data;
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == LMP_LAP_MAGIC, return;);
irlmp_do_lap_event(self, LM_LAP_IDLE_TIMEOUT, NULL);
}
static inline void
irlmp_do_all_lsap_event(hashbin_t * lsap_hashbin,
IRLMP_EVENT event)
{
struct lsap_cb *lsap;
struct lsap_cb *lsap_next;
lsap = (struct lsap_cb *) hashbin_get_first(lsap_hashbin);
while (NULL != hashbin_find_next(lsap_hashbin,
(long) lsap,
NULL,
(void *) &lsap_next) ) {
irlmp_do_lsap_event(lsap, event, NULL);
lsap = lsap_next;
}
}
static void irlmp_state_standby(struct lap_cb *self, IRLMP_EVENT event,
struct sk_buff *skb)
{
IRDA_ASSERT(self->irlap != NULL, return;);
switch (event) {
case LM_LAP_DISCOVERY_REQUEST:
irlap_discovery_request(self->irlap, &irlmp->discovery_cmd);
break;
case LM_LAP_CONNECT_INDICATION:
irlmp_next_lap_state(self, LAP_ACTIVE);
irlap_connect_response(self->irlap, skb);
break;
case LM_LAP_CONNECT_REQUEST:
pr_debug("%s() LS_CONNECT_REQUEST\n", __func__);
irlmp_next_lap_state(self, LAP_U_CONNECT);
irlap_connect_request(self->irlap, self->daddr, NULL, 0);
break;
case LM_LAP_DISCONNECT_INDICATION:
pr_debug("%s(), Error LM_LAP_DISCONNECT_INDICATION\n",
__func__);
irlmp_next_lap_state(self, LAP_STANDBY);
break;
default:
pr_debug("%s(), Unknown event %s\n",
__func__, irlmp_event[event]);
break;
}
}
static void irlmp_state_u_connect(struct lap_cb *self, IRLMP_EVENT event,
struct sk_buff *skb)
{
pr_debug("%s(), event=%s\n", __func__, irlmp_event[event]);
switch (event) {
case LM_LAP_CONNECT_INDICATION:
irlmp_next_lap_state(self, LAP_ACTIVE);
irlap_connect_response(self->irlap, skb);
irlmp_do_all_lsap_event(self->lsaps, LM_LAP_CONNECT_CONFIRM);
if (HASHBIN_GET_SIZE(self->lsaps) == 0) {
pr_debug("%s() NO LSAPs !\n", __func__);
irlmp_start_idle_timer(self, LM_IDLE_TIMEOUT);
}
break;
case LM_LAP_CONNECT_REQUEST:
break;
case LM_LAP_CONNECT_CONFIRM:
irlmp_next_lap_state(self, LAP_ACTIVE);
irlmp_do_all_lsap_event(self->lsaps, LM_LAP_CONNECT_CONFIRM);
if (HASHBIN_GET_SIZE(self->lsaps) == 0) {
pr_debug("%s() NO LSAPs !\n", __func__);
irlmp_start_idle_timer(self, LM_IDLE_TIMEOUT);
}
break;
case LM_LAP_DISCONNECT_INDICATION:
pr_debug("%s(), LM_LAP_DISCONNECT_INDICATION\n", __func__);
irlmp_next_lap_state(self, LAP_STANDBY);
irlmp_do_all_lsap_event(self->lsaps,
LM_LAP_DISCONNECT_INDICATION);
break;
case LM_LAP_DISCONNECT_REQUEST:
pr_debug("%s(), LM_LAP_DISCONNECT_REQUEST\n", __func__);
if (HASHBIN_GET_SIZE(self->lsaps) <= 1) {
irlap_disconnect_request(self->irlap);
}
break;
default:
pr_debug("%s(), Unknown event %s\n",
__func__, irlmp_event[event]);
break;
}
}
static void irlmp_state_active(struct lap_cb *self, IRLMP_EVENT event,
struct sk_buff *skb)
{
switch (event) {
case LM_LAP_CONNECT_REQUEST:
pr_debug("%s(), LS_CONNECT_REQUEST\n", __func__);
irlap_clear_disconnect(self->irlap);
irlmp_do_all_lsap_event(self->lsaps, LM_LAP_CONNECT_CONFIRM);
irlmp_do_all_lsap_event(irlmp->unconnected_lsaps,
LM_LAP_CONNECT_CONFIRM);
break;
case LM_LAP_DISCONNECT_REQUEST:
if (HASHBIN_GET_SIZE(self->lsaps) > 0) {
irlmp_start_idle_timer(self, sysctl_lap_keepalive_time * HZ / 1000);
} else {
irlap_disconnect_request(self->irlap);
}
break;
case LM_LAP_IDLE_TIMEOUT:
if (HASHBIN_GET_SIZE(self->lsaps) == 0) {
irlap_disconnect_request(self->irlap);
}
break;
case LM_LAP_DISCONNECT_INDICATION:
irlmp_next_lap_state(self, LAP_STANDBY);
irlmp_stop_idle_timer(self);
irlmp_do_all_lsap_event(self->lsaps,
LM_LAP_DISCONNECT_INDICATION);
irlmp_do_expiry();
break;
default:
pr_debug("%s(), Unknown event %s\n",
__func__, irlmp_event[event]);
break;
}
}
static int irlmp_state_disconnected(struct lsap_cb *self, IRLMP_EVENT event,
struct sk_buff *skb)
{
int ret = 0;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == LMP_LSAP_MAGIC, return -1;);
switch (event) {
#ifdef CONFIG_IRDA_ULTRA
case LM_UDATA_INDICATION:
irlmp_connless_data_indication(self, skb);
break;
#endif
case LM_CONNECT_REQUEST:
pr_debug("%s(), LM_CONNECT_REQUEST\n", __func__);
if (self->conn_skb) {
net_warn_ratelimited("%s: busy with another request!\n",
__func__);
return -EBUSY;
}
skb_get(skb);
self->conn_skb = skb;
irlmp_next_lsap_state(self, LSAP_SETUP_PEND);
irlmp_start_watchdog_timer(self, 5*HZ);
irlmp_do_lap_event(self->lap, LM_LAP_CONNECT_REQUEST, NULL);
break;
case LM_CONNECT_INDICATION:
if (self->conn_skb) {
net_warn_ratelimited("%s: busy with another request!\n",
__func__);
return -EBUSY;
}
skb_get(skb);
self->conn_skb = skb;
irlmp_next_lsap_state(self, LSAP_CONNECT_PEND);
irlmp_start_watchdog_timer(self, 1*HZ);
irlmp_do_lap_event(self->lap, LM_LAP_CONNECT_REQUEST, NULL);
break;
default:
pr_debug("%s(), Unknown event %s on LSAP %#02x\n",
__func__, irlmp_event[event], self->slsap_sel);
break;
}
return ret;
}
static int irlmp_state_connect(struct lsap_cb *self, IRLMP_EVENT event,
struct sk_buff *skb)
{
struct lsap_cb *lsap;
int ret = 0;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == LMP_LSAP_MAGIC, return -1;);
switch (event) {
case LM_CONNECT_RESPONSE:
lsap = hashbin_remove(irlmp->unconnected_lsaps, (long) self,
NULL);
IRDA_ASSERT(lsap == self, return -1;);
IRDA_ASSERT(self->lap != NULL, return -1;);
IRDA_ASSERT(self->lap->lsaps != NULL, return -1;);
hashbin_insert(self->lap->lsaps, (irda_queue_t *) self,
(long) self, NULL);
set_bit(0, &self->connected);
irlmp_send_lcf_pdu(self->lap, self->dlsap_sel,
self->slsap_sel, CONNECT_CNF, skb);
del_timer(&self->watchdog_timer);
irlmp_next_lsap_state(self, LSAP_DATA_TRANSFER_READY);
break;
case LM_WATCHDOG_TIMEOUT:
pr_debug("%s() WATCHDOG_TIMEOUT!\n", __func__);
self->lap = NULL;
self->dlsap_sel = LSAP_ANY;
irlmp_next_lsap_state(self, LSAP_DISCONNECTED);
break;
default:
pr_debug("%s(), Unknown event %s on LSAP %#02x\n",
__func__, irlmp_event[event], self->slsap_sel);
break;
}
return ret;
}
static int irlmp_state_connect_pend(struct lsap_cb *self, IRLMP_EVENT event,
struct sk_buff *skb)
{
struct sk_buff *tx_skb;
int ret = 0;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == LMP_LSAP_MAGIC, return -1;);
switch (event) {
case LM_CONNECT_REQUEST:
break;
case LM_CONNECT_RESPONSE:
pr_debug("%s(), LM_CONNECT_RESPONSE, no indication issued yet\n",
__func__);
break;
case LM_DISCONNECT_REQUEST:
pr_debug("%s(), LM_DISCONNECT_REQUEST, not yet bound to IrLAP connection\n",
__func__);
break;
case LM_LAP_CONNECT_CONFIRM:
pr_debug("%s(), LS_CONNECT_CONFIRM\n", __func__);
irlmp_next_lsap_state(self, LSAP_CONNECT);
tx_skb = self->conn_skb;
self->conn_skb = NULL;
irlmp_connect_indication(self, tx_skb);
dev_kfree_skb(tx_skb);
break;
case LM_WATCHDOG_TIMEOUT:
pr_debug("%s() WATCHDOG_TIMEOUT!\n", __func__);
self->lap = NULL;
self->dlsap_sel = LSAP_ANY;
if(self->conn_skb)
dev_kfree_skb(self->conn_skb);
self->conn_skb = NULL;
irlmp_next_lsap_state(self, LSAP_DISCONNECTED);
break;
default:
pr_debug("%s(), Unknown event %s on LSAP %#02x\n",
__func__, irlmp_event[event], self->slsap_sel);
break;
}
return ret;
}
static int irlmp_state_dtr(struct lsap_cb *self, IRLMP_EVENT event,
struct sk_buff *skb)
{
LM_REASON reason;
int ret = 0;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == LMP_LSAP_MAGIC, return -1;);
IRDA_ASSERT(self->lap != NULL, return -1;);
switch (event) {
case LM_DATA_REQUEST:
irlmp_send_data_pdu(self->lap, self->dlsap_sel,
self->slsap_sel, FALSE, skb);
break;
case LM_DATA_INDICATION:
irlmp_data_indication(self, skb);
break;
case LM_UDATA_REQUEST:
IRDA_ASSERT(skb != NULL, return -1;);
irlmp_send_data_pdu(self->lap, self->dlsap_sel,
self->slsap_sel, TRUE, skb);
break;
case LM_UDATA_INDICATION:
irlmp_udata_indication(self, skb);
break;
case LM_CONNECT_REQUEST:
pr_debug("%s(), LM_CONNECT_REQUEST, error, LSAP already connected\n",
__func__);
break;
case LM_CONNECT_RESPONSE:
pr_debug("%s(), LM_CONNECT_RESPONSE, error, LSAP already connected\n",
__func__);
break;
case LM_DISCONNECT_REQUEST:
irlmp_send_lcf_pdu(self->lap, self->dlsap_sel, self->slsap_sel,
DISCONNECT, skb);
irlmp_next_lsap_state(self, LSAP_DISCONNECTED);
if (self->lap) {
pr_debug("%s(), trying to close IrLAP\n",
__func__);
irlmp_do_lap_event(self->lap,
LM_LAP_DISCONNECT_REQUEST,
NULL);
}
break;
case LM_LAP_DISCONNECT_INDICATION:
irlmp_next_lsap_state(self, LSAP_DISCONNECTED);
reason = irlmp_convert_lap_reason(self->lap->reason);
irlmp_disconnect_indication(self, reason, NULL);
break;
case LM_DISCONNECT_INDICATION:
irlmp_next_lsap_state(self, LSAP_DISCONNECTED);
IRDA_ASSERT(self->lap != NULL, return -1;);
IRDA_ASSERT(self->lap->magic == LMP_LAP_MAGIC, return -1;);
IRDA_ASSERT(skb != NULL, return -1;);
IRDA_ASSERT(skb->len > 3, return -1;);
reason = skb->data[3];
pr_debug("%s(), trying to close IrLAP\n", __func__);
irlmp_do_lap_event(self->lap, LM_LAP_DISCONNECT_REQUEST, NULL);
irlmp_disconnect_indication(self, reason, skb);
break;
default:
pr_debug("%s(), Unknown event %s on LSAP %#02x\n",
__func__, irlmp_event[event], self->slsap_sel);
break;
}
return ret;
}
static int irlmp_state_setup(struct lsap_cb *self, IRLMP_EVENT event,
struct sk_buff *skb)
{
LM_REASON reason;
int ret = 0;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == LMP_LSAP_MAGIC, return -1;);
switch (event) {
case LM_CONNECT_CONFIRM:
irlmp_next_lsap_state(self, LSAP_DATA_TRANSFER_READY);
del_timer(&self->watchdog_timer);
irlmp_connect_confirm(self, skb);
break;
case LM_DISCONNECT_INDICATION:
irlmp_next_lsap_state(self, LSAP_DISCONNECTED);
IRDA_ASSERT(self->lap != NULL, return -1;);
IRDA_ASSERT(self->lap->magic == LMP_LAP_MAGIC, return -1;);
IRDA_ASSERT(skb != NULL, return -1;);
IRDA_ASSERT(skb->len > 3, return -1;);
reason = skb->data[3];
pr_debug("%s(), trying to close IrLAP\n", __func__);
irlmp_do_lap_event(self->lap, LM_LAP_DISCONNECT_REQUEST, NULL);
irlmp_disconnect_indication(self, reason, skb);
break;
case LM_LAP_DISCONNECT_INDICATION:
irlmp_next_lsap_state(self, LSAP_DISCONNECTED);
del_timer(&self->watchdog_timer);
IRDA_ASSERT(self->lap != NULL, return -1;);
IRDA_ASSERT(self->lap->magic == LMP_LAP_MAGIC, return -1;);
reason = irlmp_convert_lap_reason(self->lap->reason);
irlmp_disconnect_indication(self, reason, skb);
break;
case LM_WATCHDOG_TIMEOUT:
pr_debug("%s() WATCHDOG_TIMEOUT!\n", __func__);
IRDA_ASSERT(self->lap != NULL, return -1;);
irlmp_do_lap_event(self->lap, LM_LAP_DISCONNECT_REQUEST, NULL);
irlmp_next_lsap_state(self, LSAP_DISCONNECTED);
irlmp_disconnect_indication(self, LM_CONNECT_FAILURE, NULL);
break;
default:
pr_debug("%s(), Unknown event %s on LSAP %#02x\n",
__func__, irlmp_event[event], self->slsap_sel);
break;
}
return ret;
}
static int irlmp_state_setup_pend(struct lsap_cb *self, IRLMP_EVENT event,
struct sk_buff *skb)
{
struct sk_buff *tx_skb;
LM_REASON reason;
int ret = 0;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(irlmp != NULL, return -1;);
switch (event) {
case LM_LAP_CONNECT_CONFIRM:
IRDA_ASSERT(self->conn_skb != NULL, return -1;);
tx_skb = self->conn_skb;
self->conn_skb = NULL;
irlmp_send_lcf_pdu(self->lap, self->dlsap_sel,
self->slsap_sel, CONNECT_CMD, tx_skb);
dev_kfree_skb(tx_skb);
irlmp_next_lsap_state(self, LSAP_SETUP);
break;
case LM_WATCHDOG_TIMEOUT:
pr_debug("%s() : WATCHDOG_TIMEOUT !\n", __func__);
IRDA_ASSERT(self->lap != NULL, return -1;);
irlmp_do_lap_event(self->lap, LM_LAP_DISCONNECT_REQUEST, NULL);
irlmp_next_lsap_state(self, LSAP_DISCONNECTED);
irlmp_disconnect_indication(self, LM_CONNECT_FAILURE, NULL);
break;
case LM_LAP_DISCONNECT_INDICATION:
del_timer( &self->watchdog_timer);
irlmp_next_lsap_state(self, LSAP_DISCONNECTED);
reason = irlmp_convert_lap_reason(self->lap->reason);
irlmp_disconnect_indication(self, reason, NULL);
break;
default:
pr_debug("%s(), Unknown event %s on LSAP %#02x\n",
__func__, irlmp_event[event], self->slsap_sel);
break;
}
return ret;
}
