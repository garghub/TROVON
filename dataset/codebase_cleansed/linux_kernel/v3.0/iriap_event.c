void iriap_next_client_state(struct iriap_cb *self, IRIAP_STATE state)
{
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
self->client_state = state;
}
void iriap_next_call_state(struct iriap_cb *self, IRIAP_STATE state)
{
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
self->call_state = state;
}
void iriap_next_server_state(struct iriap_cb *self, IRIAP_STATE state)
{
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
self->server_state = state;
}
void iriap_next_r_connect_state(struct iriap_cb *self, IRIAP_STATE state)
{
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
self->r_connect_state = state;
}
void iriap_do_client_event(struct iriap_cb *self, IRIAP_EVENT event,
struct sk_buff *skb)
{
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
(*iriap_state[ self->client_state]) (self, event, skb);
}
void iriap_do_call_event(struct iriap_cb *self, IRIAP_EVENT event,
struct sk_buff *skb)
{
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
(*iriap_state[ self->call_state]) (self, event, skb);
}
void iriap_do_server_event(struct iriap_cb *self, IRIAP_EVENT event,
struct sk_buff *skb)
{
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
(*iriap_state[ self->server_state]) (self, event, skb);
}
void iriap_do_r_connect_event(struct iriap_cb *self, IRIAP_EVENT event,
struct sk_buff *skb)
{
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
(*iriap_state[ self->r_connect_state]) (self, event, skb);
}
static void state_s_disconnect(struct iriap_cb *self, IRIAP_EVENT event,
struct sk_buff *skb)
{
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
switch (event) {
case IAP_CALL_REQUEST_GVBC:
iriap_next_client_state(self, S_CONNECTING);
IRDA_ASSERT(self->request_skb == NULL, return;);
skb_get(skb);
self->request_skb = skb;
iriap_connect_request(self);
break;
case IAP_LM_DISCONNECT_INDICATION:
break;
default:
IRDA_DEBUG(0, "%s(), Unknown event %d\n", __func__, event);
break;
}
}
static void state_s_connecting(struct iriap_cb *self, IRIAP_EVENT event,
struct sk_buff *skb)
{
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
switch (event) {
case IAP_LM_CONNECT_CONFIRM:
iriap_do_call_event(self, IAP_CALL_REQUEST, skb);
iriap_next_client_state(self, S_CALL);
break;
case IAP_LM_DISCONNECT_INDICATION:
iriap_next_call_state(self, S_MAKE_CALL);
iriap_next_client_state(self, S_DISCONNECT);
break;
default:
IRDA_DEBUG(0, "%s(), Unknown event %d\n", __func__, event);
break;
}
}
static void state_s_call(struct iriap_cb *self, IRIAP_EVENT event,
struct sk_buff *skb)
{
IRDA_ASSERT(self != NULL, return;);
switch (event) {
case IAP_LM_DISCONNECT_INDICATION:
iriap_next_call_state(self, S_MAKE_CALL);
iriap_next_client_state(self, S_DISCONNECT);
break;
default:
IRDA_DEBUG(0, "state_s_call: Unknown event %d\n", event);
break;
}
}
static void state_s_make_call(struct iriap_cb *self, IRIAP_EVENT event,
struct sk_buff *skb)
{
struct sk_buff *tx_skb;
IRDA_ASSERT(self != NULL, return;);
switch (event) {
case IAP_CALL_REQUEST:
tx_skb = self->request_skb;
self->request_skb = NULL;
irlmp_data_request(self->lsap, tx_skb);
iriap_next_call_state(self, S_OUTSTANDING);
break;
default:
IRDA_DEBUG(0, "%s(), Unknown event %d\n", __func__, event);
break;
}
}
static void state_s_calling(struct iriap_cb *self, IRIAP_EVENT event,
struct sk_buff *skb)
{
IRDA_DEBUG(0, "%s(), Not implemented\n", __func__);
}
static void state_s_outstanding(struct iriap_cb *self, IRIAP_EVENT event,
struct sk_buff *skb)
{
IRDA_ASSERT(self != NULL, return;);
switch (event) {
case IAP_RECV_F_LST:
iriap_next_call_state(self, S_WAIT_FOR_CALL);
break;
default:
IRDA_DEBUG(0, "%s(), Unknown event %d\n", __func__, event);
break;
}
}
static void state_s_replying(struct iriap_cb *self, IRIAP_EVENT event,
struct sk_buff *skb)
{
IRDA_DEBUG(0, "%s(), Not implemented\n", __func__);
}
static void state_s_wait_for_call(struct iriap_cb *self, IRIAP_EVENT event,
struct sk_buff *skb)
{
IRDA_DEBUG(0, "%s(), Not implemented\n", __func__);
}
static void state_s_wait_active(struct iriap_cb *self, IRIAP_EVENT event,
struct sk_buff *skb)
{
IRDA_DEBUG(0, "%s(), Not implemented\n", __func__);
}
static void state_r_disconnect(struct iriap_cb *self, IRIAP_EVENT event,
struct sk_buff *skb)
{
struct sk_buff *tx_skb;
switch (event) {
case IAP_LM_CONNECT_INDICATION:
tx_skb = alloc_skb(LMP_MAX_HEADER, GFP_ATOMIC);
if (tx_skb == NULL) {
IRDA_WARNING("%s: unable to malloc!\n", __func__);
return;
}
skb_reserve(tx_skb, LMP_MAX_HEADER);
irlmp_connect_response(self->lsap, tx_skb);
iriap_next_server_state(self, R_CALL);
iriap_next_r_connect_state(self, R_RECEIVING);
break;
default:
IRDA_DEBUG(0, "%s(), unknown event %d\n", __func__, event);
break;
}
}
static void state_r_call(struct iriap_cb *self, IRIAP_EVENT event,
struct sk_buff *skb)
{
IRDA_DEBUG(4, "%s()\n", __func__);
switch (event) {
case IAP_LM_DISCONNECT_INDICATION:
iriap_next_server_state(self, R_DISCONNECT);
iriap_next_r_connect_state(self, R_WAITING);
break;
default:
IRDA_DEBUG(0, "%s(), unknown event!\n", __func__);
break;
}
}
static void state_r_waiting(struct iriap_cb *self, IRIAP_EVENT event,
struct sk_buff *skb)
{
IRDA_DEBUG(0, "%s(), Not implemented\n", __func__);
}
static void state_r_wait_active(struct iriap_cb *self, IRIAP_EVENT event,
struct sk_buff *skb)
{
IRDA_DEBUG(0, "%s(), Not implemented\n", __func__);
}
static void state_r_receiving(struct iriap_cb *self, IRIAP_EVENT event,
struct sk_buff *skb)
{
IRDA_DEBUG(4, "%s()\n", __func__);
switch (event) {
case IAP_RECV_F_LST:
iriap_next_r_connect_state(self, R_EXECUTE);
iriap_call_indication(self, skb);
break;
default:
IRDA_DEBUG(0, "%s(), unknown event!\n", __func__);
break;
}
}
static void state_r_execute(struct iriap_cb *self, IRIAP_EVENT event,
struct sk_buff *skb)
{
IRDA_DEBUG(4, "%s()\n", __func__);
IRDA_ASSERT(skb != NULL, return;);
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
switch (event) {
case IAP_CALL_RESPONSE:
iriap_next_r_connect_state(self, R_RECEIVING);
skb_get(skb);
irlmp_data_request(self->lsap, skb);
break;
default:
IRDA_DEBUG(0, "%s(), unknown event!\n", __func__);
break;
}
}
static void state_r_returning(struct iriap_cb *self, IRIAP_EVENT event,
struct sk_buff *skb)
{
IRDA_DEBUG(0, "%s(), event=%d\n", __func__, event);
switch (event) {
case IAP_RECV_F_LST:
break;
default:
break;
}
}
