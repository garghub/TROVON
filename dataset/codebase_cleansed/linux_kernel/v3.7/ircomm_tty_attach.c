int ircomm_tty_attach_cable(struct ircomm_tty_cb *self)
{
struct tty_struct *tty;
IRDA_DEBUG(0, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return -1;);
if (ircomm_is_connected(self->ircomm)) {
IRDA_DEBUG(0, "%s(), already connected!\n", __func__ );
return 0;
}
tty = tty_port_tty_get(&self->port);
if (tty) {
tty->hw_stopped = 1;
tty_kref_put(tty);
}
ircomm_tty_ias_register(self);
ircomm_tty_do_event(self, IRCOMM_TTY_ATTACH_CABLE, NULL, NULL);
return 0;
}
void ircomm_tty_detach_cable(struct ircomm_tty_cb *self)
{
IRDA_DEBUG(0, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return;);
del_timer(&self->watchdog_timer);
if (self->ckey) {
irlmp_unregister_client(self->ckey);
self->ckey = NULL;
}
if (self->skey) {
irlmp_unregister_service(self->skey);
self->skey = NULL;
}
if (self->iriap) {
iriap_close(self->iriap);
self->iriap = NULL;
}
if (self->obj) {
irias_delete_object(self->obj);
self->obj = NULL;
}
ircomm_tty_do_event(self, IRCOMM_TTY_DETACH_CABLE, NULL, NULL);
self->daddr = self->saddr = 0;
self->dlsap_sel = self->slsap_sel = 0;
memset(&self->settings, 0, sizeof(struct ircomm_params));
}
static void ircomm_tty_ias_register(struct ircomm_tty_cb *self)
{
__u8 oct_seq[6];
__u16 hints;
IRDA_DEBUG(0, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return;);
hints = irlmp_service_to_hint(S_COMM);
if (self->service_type & IRCOMM_3_WIRE_RAW)
hints |= irlmp_service_to_hint(S_PRINTER);
if (!self->skey)
self->skey = irlmp_register_service(hints);
if (!self->ckey)
self->ckey = irlmp_register_client(hints,
ircomm_tty_discovery_indication,
NULL, (void *) self);
if (self->obj)
return;
if (self->service_type & IRCOMM_3_WIRE_RAW) {
self->obj = irias_new_object("IrLPT", IAS_IRLPT_ID);
irias_add_integer_attrib(self->obj, "IrDA:IrLMP:LsapSel",
self->slsap_sel, IAS_KERNEL_ATTR);
} else {
self->obj = irias_new_object("IrDA:IrCOMM", IAS_IRCOMM_ID);
irias_add_integer_attrib(self->obj, "IrDA:TinyTP:LsapSel",
self->slsap_sel, IAS_KERNEL_ATTR);
irda_param_pack(oct_seq, "bbbbbb",
IRCOMM_SERVICE_TYPE, 1, self->service_type,
IRCOMM_PORT_TYPE, 1, IRCOMM_SERIAL);
irias_add_octseq_attrib(self->obj, "Parameters", oct_seq, 6,
IAS_KERNEL_ATTR);
}
irias_insert_object(self->obj);
}
static void ircomm_tty_ias_unregister(struct ircomm_tty_cb *self)
{
if (self->obj) {
irias_delete_object(self->obj);
self->obj = NULL;
}
#if 0
if (self->ckey) {
irlmp_unregister_client(self->ckey);
self->ckey = NULL;
}
#endif
}
int ircomm_tty_send_initial_parameters(struct ircomm_tty_cb *self)
{
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return -1;);
if (self->service_type & IRCOMM_3_WIRE_RAW)
return 0;
IRDA_DEBUG(2, "%s(), data-rate = %d\n", __func__ ,
self->settings.data_rate);
if (!self->settings.data_rate)
self->settings.data_rate = 9600;
IRDA_DEBUG(2, "%s(), data-format = %d\n", __func__ ,
self->settings.data_format);
if (!self->settings.data_format)
self->settings.data_format = IRCOMM_WSIZE_8;
IRDA_DEBUG(2, "%s(), flow-control = %d\n", __func__ ,
self->settings.flow_control);
self->settings.dte = IRCOMM_DTR | IRCOMM_RTS;
if (self->client)
ircomm_param_request(self, IRCOMM_SERVICE_TYPE, FALSE);
ircomm_param_request(self, IRCOMM_DATA_RATE, FALSE);
ircomm_param_request(self, IRCOMM_DATA_FORMAT, FALSE);
if (self->settings.service_type == IRCOMM_3_WIRE) {
ircomm_param_request(self, IRCOMM_FLOW_CONTROL, TRUE);
return 0;
}
ircomm_param_request(self, IRCOMM_FLOW_CONTROL, FALSE);
#if 0
ircomm_param_request(self, IRCOMM_XON_XOFF, FALSE);
ircomm_param_request(self, IRCOMM_ENQ_ACK, FALSE);
#endif
ircomm_param_request(self, IRCOMM_DTE, TRUE);
return 0;
}
static void ircomm_tty_discovery_indication(discinfo_t *discovery,
DISCOVERY_MODE mode,
void *priv)
{
struct ircomm_tty_cb *self;
struct ircomm_tty_info info;
IRDA_DEBUG(2, "%s()\n", __func__ );
if(mode == DISCOVERY_PASSIVE)
return;
info.daddr = discovery->daddr;
info.saddr = discovery->saddr;
self = priv;
ircomm_tty_do_event(self, IRCOMM_TTY_DISCOVERY_INDICATION,
NULL, &info);
}
void ircomm_tty_disconnect_indication(void *instance, void *sap,
LM_REASON reason,
struct sk_buff *skb)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) instance;
struct tty_struct *tty;
IRDA_DEBUG(2, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return;);
tty = tty_port_tty_get(&self->port);
if (!tty)
return;
self->flow = FLOW_STOP;
tty->hw_stopped = 1;
ircomm_tty_do_event(self, IRCOMM_TTY_DISCONNECT_INDICATION, NULL,
NULL);
tty_kref_put(tty);
}
static void ircomm_tty_getvalue_confirm(int result, __u16 obj_id,
struct ias_value *value,
void *priv)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) priv;
IRDA_DEBUG(2, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return;);
iriap_close(self->iriap);
self->iriap = NULL;
if (result != IAS_SUCCESS) {
IRDA_DEBUG(4, "%s(), got NULL value!\n", __func__ );
return;
}
switch (value->type) {
case IAS_OCT_SEQ:
IRDA_DEBUG(2, "%s(), got octet sequence\n", __func__ );
irda_param_extract_all(self, value->t.oct_seq, value->len,
&ircomm_param_info);
ircomm_tty_do_event(self, IRCOMM_TTY_GOT_PARAMETERS, NULL,
NULL);
break;
case IAS_INTEGER:
IRDA_DEBUG(2, "%s(), got lsapsel = %d\n", __func__ ,
value->t.integer);
if (value->t.integer == -1) {
IRDA_DEBUG(0, "%s(), invalid value!\n", __func__ );
} else
self->dlsap_sel = value->t.integer;
ircomm_tty_do_event(self, IRCOMM_TTY_GOT_LSAPSEL, NULL, NULL);
break;
case IAS_MISSING:
IRDA_DEBUG(0, "%s(), got IAS_MISSING\n", __func__ );
break;
default:
IRDA_DEBUG(0, "%s(), got unknown type!\n", __func__ );
break;
}
irias_delete_value(value);
}
void ircomm_tty_connect_confirm(void *instance, void *sap,
struct qos_info *qos,
__u32 max_data_size,
__u8 max_header_size,
struct sk_buff *skb)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) instance;
IRDA_DEBUG(2, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return;);
self->client = TRUE;
self->max_data_size = max_data_size;
self->max_header_size = max_header_size;
self->flow = FLOW_START;
ircomm_tty_do_event(self, IRCOMM_TTY_CONNECT_CONFIRM, NULL, NULL);
}
void ircomm_tty_connect_indication(void *instance, void *sap,
struct qos_info *qos,
__u32 max_data_size,
__u8 max_header_size,
struct sk_buff *skb)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) instance;
int clen;
IRDA_DEBUG(2, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return;);
self->client = FALSE;
self->max_data_size = max_data_size;
self->max_header_size = max_header_size;
self->flow = FLOW_START;
clen = skb->data[0];
if (clen)
irda_param_extract_all(self, skb->data+1,
IRDA_MIN(skb->len, clen),
&ircomm_param_info);
ircomm_tty_do_event(self, IRCOMM_TTY_CONNECT_INDICATION, NULL, NULL);
}
void ircomm_tty_link_established(struct ircomm_tty_cb *self)
{
struct tty_struct *tty;
IRDA_DEBUG(2, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return;);
tty = tty_port_tty_get(&self->port);
if (!tty)
return;
del_timer(&self->watchdog_timer);
if (tty_port_cts_enabled(&self->port) &&
((self->settings.dce & IRCOMM_CTS) == 0)) {
IRDA_DEBUG(0, "%s(), waiting for CTS ...\n", __func__ );
goto put;
} else {
IRDA_DEBUG(1, "%s(), starting hardware!\n", __func__ );
tty->hw_stopped = 0;
wake_up_interruptible(&self->port.open_wait);
}
schedule_work(&self->tqueue);
put:
tty_kref_put(tty);
}
static void ircomm_tty_start_watchdog_timer(struct ircomm_tty_cb *self,
int timeout)
{
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return;);
irda_start_timer(&self->watchdog_timer, timeout, (void *) self,
ircomm_tty_watchdog_timer_expired);
}
static void ircomm_tty_watchdog_timer_expired(void *data)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) data;
IRDA_DEBUG(2, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return;);
ircomm_tty_do_event(self, IRCOMM_TTY_WD_TIMER_EXPIRED, NULL, NULL);
}
int ircomm_tty_do_event(struct ircomm_tty_cb *self, IRCOMM_TTY_EVENT event,
struct sk_buff *skb, struct ircomm_tty_info *info)
{
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return -1;);
IRDA_DEBUG(2, "%s: state=%s, event=%s\n", __func__ ,
ircomm_tty_state[self->state], ircomm_tty_event[event]);
return (*state[self->state])(self, event, skb, info);
}
static inline void ircomm_tty_next_state(struct ircomm_tty_cb *self, IRCOMM_TTY_STATE state)
{
self->state = state;
}
static int ircomm_tty_state_idle(struct ircomm_tty_cb *self,
IRCOMM_TTY_EVENT event,
struct sk_buff *skb,
struct ircomm_tty_info *info)
{
int ret = 0;
IRDA_DEBUG(2, "%s: state=%s, event=%s\n", __func__ ,
ircomm_tty_state[self->state], ircomm_tty_event[event]);
switch (event) {
case IRCOMM_TTY_ATTACH_CABLE:
ircomm_tty_start_watchdog_timer(self, 3*HZ);
ircomm_tty_next_state(self, IRCOMM_TTY_SEARCH);
irlmp_discovery_request(DISCOVERY_DEFAULT_SLOTS);
break;
case IRCOMM_TTY_DISCOVERY_INDICATION:
self->daddr = info->daddr;
self->saddr = info->saddr;
if (self->iriap) {
IRDA_WARNING("%s(), busy with a previous query\n",
__func__);
return -EBUSY;
}
self->iriap = iriap_open(LSAP_ANY, IAS_CLIENT, self,
ircomm_tty_getvalue_confirm);
iriap_getvaluebyclass_request(self->iriap,
self->saddr, self->daddr,
"IrDA:IrCOMM", "Parameters");
ircomm_tty_start_watchdog_timer(self, 3*HZ);
ircomm_tty_next_state(self, IRCOMM_TTY_QUERY_PARAMETERS);
break;
case IRCOMM_TTY_CONNECT_INDICATION:
del_timer(&self->watchdog_timer);
ircomm_connect_response(self->ircomm, NULL);
ircomm_tty_next_state(self, IRCOMM_TTY_READY);
break;
case IRCOMM_TTY_WD_TIMER_EXPIRED:
break;
case IRCOMM_TTY_DETACH_CABLE:
ircomm_tty_next_state(self, IRCOMM_TTY_IDLE);
break;
default:
IRDA_DEBUG(2, "%s(), unknown event: %s\n", __func__ ,
ircomm_tty_event[event]);
ret = -EINVAL;
}
return ret;
}
static int ircomm_tty_state_search(struct ircomm_tty_cb *self,
IRCOMM_TTY_EVENT event,
struct sk_buff *skb,
struct ircomm_tty_info *info)
{
int ret = 0;
IRDA_DEBUG(2, "%s: state=%s, event=%s\n", __func__ ,
ircomm_tty_state[self->state], ircomm_tty_event[event]);
switch (event) {
case IRCOMM_TTY_DISCOVERY_INDICATION:
self->daddr = info->daddr;
self->saddr = info->saddr;
if (self->iriap) {
IRDA_WARNING("%s(), busy with a previous query\n",
__func__);
return -EBUSY;
}
self->iriap = iriap_open(LSAP_ANY, IAS_CLIENT, self,
ircomm_tty_getvalue_confirm);
if (self->service_type == IRCOMM_3_WIRE_RAW) {
iriap_getvaluebyclass_request(self->iriap, self->saddr,
self->daddr, "IrLPT",
"IrDA:IrLMP:LsapSel");
ircomm_tty_next_state(self, IRCOMM_TTY_QUERY_LSAP_SEL);
} else {
iriap_getvaluebyclass_request(self->iriap, self->saddr,
self->daddr,
"IrDA:IrCOMM",
"Parameters");
ircomm_tty_next_state(self, IRCOMM_TTY_QUERY_PARAMETERS);
}
ircomm_tty_start_watchdog_timer(self, 3*HZ);
break;
case IRCOMM_TTY_CONNECT_INDICATION:
del_timer(&self->watchdog_timer);
ircomm_tty_ias_unregister(self);
ircomm_connect_response(self->ircomm, NULL);
ircomm_tty_next_state(self, IRCOMM_TTY_READY);
break;
case IRCOMM_TTY_WD_TIMER_EXPIRED:
#if 1
#else
ircomm_tty_start_watchdog_timer(self, 3*HZ);
irlmp_discovery_request(DISCOVERY_DEFAULT_SLOTS);
#endif
break;
case IRCOMM_TTY_DETACH_CABLE:
ircomm_tty_next_state(self, IRCOMM_TTY_IDLE);
break;
default:
IRDA_DEBUG(2, "%s(), unknown event: %s\n", __func__ ,
ircomm_tty_event[event]);
ret = -EINVAL;
}
return ret;
}
static int ircomm_tty_state_query_parameters(struct ircomm_tty_cb *self,
IRCOMM_TTY_EVENT event,
struct sk_buff *skb,
struct ircomm_tty_info *info)
{
int ret = 0;
IRDA_DEBUG(2, "%s: state=%s, event=%s\n", __func__ ,
ircomm_tty_state[self->state], ircomm_tty_event[event]);
switch (event) {
case IRCOMM_TTY_GOT_PARAMETERS:
if (self->iriap) {
IRDA_WARNING("%s(), busy with a previous query\n",
__func__);
return -EBUSY;
}
self->iriap = iriap_open(LSAP_ANY, IAS_CLIENT, self,
ircomm_tty_getvalue_confirm);
iriap_getvaluebyclass_request(self->iriap, self->saddr,
self->daddr, "IrDA:IrCOMM",
"IrDA:TinyTP:LsapSel");
ircomm_tty_start_watchdog_timer(self, 3*HZ);
ircomm_tty_next_state(self, IRCOMM_TTY_QUERY_LSAP_SEL);
break;
case IRCOMM_TTY_WD_TIMER_EXPIRED:
ircomm_tty_next_state(self, IRCOMM_TTY_SEARCH);
ircomm_tty_start_watchdog_timer(self, 3*HZ);
break;
case IRCOMM_TTY_CONNECT_INDICATION:
del_timer(&self->watchdog_timer);
ircomm_tty_ias_unregister(self);
ircomm_connect_response(self->ircomm, NULL);
ircomm_tty_next_state(self, IRCOMM_TTY_READY);
break;
case IRCOMM_TTY_DETACH_CABLE:
ircomm_tty_next_state(self, IRCOMM_TTY_IDLE);
break;
default:
IRDA_DEBUG(2, "%s(), unknown event: %s\n", __func__ ,
ircomm_tty_event[event]);
ret = -EINVAL;
}
return ret;
}
static int ircomm_tty_state_query_lsap_sel(struct ircomm_tty_cb *self,
IRCOMM_TTY_EVENT event,
struct sk_buff *skb,
struct ircomm_tty_info *info)
{
int ret = 0;
IRDA_DEBUG(2, "%s: state=%s, event=%s\n", __func__ ,
ircomm_tty_state[self->state], ircomm_tty_event[event]);
switch (event) {
case IRCOMM_TTY_GOT_LSAPSEL:
ret = ircomm_connect_request(self->ircomm, self->dlsap_sel,
self->saddr, self->daddr,
NULL, self->service_type);
ircomm_tty_start_watchdog_timer(self, 3*HZ);
ircomm_tty_next_state(self, IRCOMM_TTY_SETUP);
break;
case IRCOMM_TTY_WD_TIMER_EXPIRED:
ircomm_tty_next_state(self, IRCOMM_TTY_SEARCH);
ircomm_tty_start_watchdog_timer(self, 3*HZ);
break;
case IRCOMM_TTY_CONNECT_INDICATION:
del_timer(&self->watchdog_timer);
ircomm_tty_ias_unregister(self);
ircomm_connect_response(self->ircomm, NULL);
ircomm_tty_next_state(self, IRCOMM_TTY_READY);
break;
case IRCOMM_TTY_DETACH_CABLE:
ircomm_tty_next_state(self, IRCOMM_TTY_IDLE);
break;
default:
IRDA_DEBUG(2, "%s(), unknown event: %s\n", __func__ ,
ircomm_tty_event[event]);
ret = -EINVAL;
}
return ret;
}
static int ircomm_tty_state_setup(struct ircomm_tty_cb *self,
IRCOMM_TTY_EVENT event,
struct sk_buff *skb,
struct ircomm_tty_info *info)
{
int ret = 0;
IRDA_DEBUG(2, "%s: state=%s, event=%s\n", __func__ ,
ircomm_tty_state[self->state], ircomm_tty_event[event]);
switch (event) {
case IRCOMM_TTY_CONNECT_CONFIRM:
del_timer(&self->watchdog_timer);
ircomm_tty_ias_unregister(self);
ircomm_tty_send_initial_parameters(self);
ircomm_tty_link_established(self);
ircomm_tty_next_state(self, IRCOMM_TTY_READY);
break;
case IRCOMM_TTY_CONNECT_INDICATION:
del_timer(&self->watchdog_timer);
ircomm_tty_ias_unregister(self);
ircomm_connect_response(self->ircomm, NULL);
ircomm_tty_next_state(self, IRCOMM_TTY_READY);
break;
case IRCOMM_TTY_WD_TIMER_EXPIRED:
ircomm_tty_next_state(self, IRCOMM_TTY_SEARCH);
ircomm_tty_start_watchdog_timer(self, 3*HZ);
break;
case IRCOMM_TTY_DETACH_CABLE:
ircomm_tty_next_state(self, IRCOMM_TTY_IDLE);
break;
default:
IRDA_DEBUG(2, "%s(), unknown event: %s\n", __func__ ,
ircomm_tty_event[event]);
ret = -EINVAL;
}
return ret;
}
static int ircomm_tty_state_ready(struct ircomm_tty_cb *self,
IRCOMM_TTY_EVENT event,
struct sk_buff *skb,
struct ircomm_tty_info *info)
{
int ret = 0;
switch (event) {
case IRCOMM_TTY_DATA_REQUEST:
ret = ircomm_data_request(self->ircomm, skb);
break;
case IRCOMM_TTY_DETACH_CABLE:
ircomm_disconnect_request(self->ircomm, NULL);
ircomm_tty_next_state(self, IRCOMM_TTY_IDLE);
break;
case IRCOMM_TTY_DISCONNECT_INDICATION:
ircomm_tty_ias_register(self);
ircomm_tty_next_state(self, IRCOMM_TTY_SEARCH);
ircomm_tty_start_watchdog_timer(self, 3*HZ);
if (self->port.flags & ASYNC_CHECK_CD) {
self->settings.dce = IRCOMM_DELTA_CD;
ircomm_tty_check_modem_status(self);
} else {
struct tty_struct *tty = tty_port_tty_get(&self->port);
IRDA_DEBUG(0, "%s(), hanging up!\n", __func__ );
if (tty) {
tty_hangup(tty);
tty_kref_put(tty);
}
}
break;
default:
IRDA_DEBUG(2, "%s(), unknown event: %s\n", __func__ ,
ircomm_tty_event[event]);
ret = -EINVAL;
}
return ret;
}
