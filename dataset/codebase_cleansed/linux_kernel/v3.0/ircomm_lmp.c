static int ircomm_lmp_connect_request(struct ircomm_cb *self,
struct sk_buff *userdata,
struct ircomm_info *info)
{
int ret = 0;
IRDA_DEBUG(0, "%s()\n", __func__ );
if(userdata)
skb_get(userdata);
ret = irlmp_connect_request(self->lsap, info->dlsap_sel,
info->saddr, info->daddr, NULL, userdata);
return ret;
}
static int ircomm_lmp_connect_response(struct ircomm_cb *self,
struct sk_buff *userdata)
{
struct sk_buff *tx_skb;
IRDA_DEBUG(0, "%s()\n", __func__ );
if (userdata == NULL) {
tx_skb = alloc_skb(LMP_MAX_HEADER, GFP_ATOMIC);
if (!tx_skb)
return -ENOMEM;
skb_reserve(tx_skb, LMP_MAX_HEADER);
} else {
IRDA_ASSERT(skb_headroom(userdata) >= LMP_MAX_HEADER,
return -1;);
skb_get(userdata);
tx_skb = userdata;
}
return irlmp_connect_response(self->lsap, tx_skb);
}
static int ircomm_lmp_disconnect_request(struct ircomm_cb *self,
struct sk_buff *userdata,
struct ircomm_info *info)
{
struct sk_buff *tx_skb;
int ret;
IRDA_DEBUG(0, "%s()\n", __func__ );
if (!userdata) {
tx_skb = alloc_skb(LMP_MAX_HEADER, GFP_ATOMIC);
if (!tx_skb)
return -ENOMEM;
skb_reserve(tx_skb, LMP_MAX_HEADER);
userdata = tx_skb;
} else {
skb_get(userdata);
}
ret = irlmp_disconnect_request(self->lsap, userdata);
return ret;
}
static void ircomm_lmp_flow_control(struct sk_buff *skb)
{
struct irda_skb_cb *cb;
struct ircomm_cb *self;
int line;
IRDA_ASSERT(skb != NULL, return;);
cb = (struct irda_skb_cb *) skb->cb;
IRDA_DEBUG(2, "%s()\n", __func__ );
line = cb->line;
self = (struct ircomm_cb *) hashbin_lock_find(ircomm, line, NULL);
if (!self) {
IRDA_DEBUG(2, "%s(), didn't find myself\n", __func__ );
return;
}
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_MAGIC, return;);
self->pkt_count--;
if ((self->pkt_count < 2) && (self->flow_status == FLOW_STOP)) {
IRDA_DEBUG(2, "%s(), asking TTY to start again!\n", __func__ );
self->flow_status = FLOW_START;
if (self->notify.flow_indication)
self->notify.flow_indication(self->notify.instance,
self, FLOW_START);
}
}
static int ircomm_lmp_data_request(struct ircomm_cb *self,
struct sk_buff *skb,
int not_used)
{
struct irda_skb_cb *cb;
int ret;
IRDA_ASSERT(skb != NULL, return -1;);
cb = (struct irda_skb_cb *) skb->cb;
cb->line = self->line;
IRDA_DEBUG(4, "%s(), sending frame\n", __func__ );
skb_get(skb);
skb_orphan(skb);
skb->destructor = ircomm_lmp_flow_control;
if ((self->pkt_count++ > 7) && (self->flow_status == FLOW_START)) {
IRDA_DEBUG(2, "%s(), asking TTY to slow down!\n", __func__ );
self->flow_status = FLOW_STOP;
if (self->notify.flow_indication)
self->notify.flow_indication(self->notify.instance,
self, FLOW_STOP);
}
ret = irlmp_data_request(self->lsap, skb);
if (ret) {
IRDA_ERROR("%s(), failed\n", __func__);
}
return ret;
}
static int ircomm_lmp_data_indication(void *instance, void *sap,
struct sk_buff *skb)
{
struct ircomm_cb *self = (struct ircomm_cb *) instance;
IRDA_DEBUG(4, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_MAGIC, return -1;);
IRDA_ASSERT(skb != NULL, return -1;);
ircomm_do_event(self, IRCOMM_LMP_DATA_INDICATION, skb, NULL);
dev_kfree_skb(skb);
return 0;
}
static void ircomm_lmp_connect_confirm(void *instance, void *sap,
struct qos_info *qos,
__u32 max_seg_size,
__u8 max_header_size,
struct sk_buff *skb)
{
struct ircomm_cb *self = (struct ircomm_cb *) instance;
struct ircomm_info info;
IRDA_DEBUG(0, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_MAGIC, return;);
IRDA_ASSERT(skb != NULL, return;);
IRDA_ASSERT(qos != NULL, return;);
info.max_data_size = max_seg_size;
info.max_header_size = max_header_size;
info.qos = qos;
ircomm_do_event(self, IRCOMM_LMP_CONNECT_CONFIRM, skb, &info);
dev_kfree_skb(skb);
}
static void ircomm_lmp_connect_indication(void *instance, void *sap,
struct qos_info *qos,
__u32 max_seg_size,
__u8 max_header_size,
struct sk_buff *skb)
{
struct ircomm_cb *self = (struct ircomm_cb *)instance;
struct ircomm_info info;
IRDA_DEBUG(0, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_MAGIC, return;);
IRDA_ASSERT(skb != NULL, return;);
IRDA_ASSERT(qos != NULL, return;);
info.max_data_size = max_seg_size;
info.max_header_size = max_header_size;
info.qos = qos;
ircomm_do_event(self, IRCOMM_LMP_CONNECT_INDICATION, skb, &info);
dev_kfree_skb(skb);
}
static void ircomm_lmp_disconnect_indication(void *instance, void *sap,
LM_REASON reason,
struct sk_buff *skb)
{
struct ircomm_cb *self = (struct ircomm_cb *) instance;
struct ircomm_info info;
IRDA_DEBUG(0, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_MAGIC, return;);
info.reason = reason;
ircomm_do_event(self, IRCOMM_LMP_DISCONNECT_INDICATION, skb, &info);
if(skb)
dev_kfree_skb(skb);
}
int ircomm_open_lsap(struct ircomm_cb *self)
{
notify_t notify;
IRDA_DEBUG(0, "%s()\n", __func__ );
irda_notify_init(&notify);
notify.data_indication = ircomm_lmp_data_indication;
notify.connect_confirm = ircomm_lmp_connect_confirm;
notify.connect_indication = ircomm_lmp_connect_indication;
notify.disconnect_indication = ircomm_lmp_disconnect_indication;
notify.instance = self;
strlcpy(notify.name, "IrCOMM", sizeof(notify.name));
self->lsap = irlmp_open_lsap(LSAP_ANY, &notify, 0);
if (!self->lsap) {
IRDA_DEBUG(0,"%sfailed to allocate tsap\n", __func__ );
return -1;
}
self->slsap_sel = self->lsap->slsap_sel;
self->issue.data_request = ircomm_lmp_data_request;
self->issue.connect_request = ircomm_lmp_connect_request;
self->issue.connect_response = ircomm_lmp_connect_response;
self->issue.disconnect_request = ircomm_lmp_disconnect_request;
return 0;
}
