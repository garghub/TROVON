int ircomm_open_tsap(struct ircomm_cb *self)
{
notify_t notify;
IRDA_DEBUG(4, "%s()\n", __func__ );
irda_notify_init(&notify);
notify.data_indication = ircomm_ttp_data_indication;
notify.connect_confirm = ircomm_ttp_connect_confirm;
notify.connect_indication = ircomm_ttp_connect_indication;
notify.flow_indication = ircomm_ttp_flow_indication;
notify.disconnect_indication = ircomm_ttp_disconnect_indication;
notify.instance = self;
strlcpy(notify.name, "IrCOMM", sizeof(notify.name));
self->tsap = irttp_open_tsap(LSAP_ANY, DEFAULT_INITIAL_CREDIT,
&notify);
if (!self->tsap) {
IRDA_DEBUG(0, "%sfailed to allocate tsap\n", __func__ );
return -1;
}
self->slsap_sel = self->tsap->stsap_sel;
self->issue.data_request = ircomm_ttp_data_request;
self->issue.connect_request = ircomm_ttp_connect_request;
self->issue.connect_response = ircomm_ttp_connect_response;
self->issue.disconnect_request = ircomm_ttp_disconnect_request;
return 0;
}
static int ircomm_ttp_connect_request(struct ircomm_cb *self,
struct sk_buff *userdata,
struct ircomm_info *info)
{
int ret = 0;
IRDA_DEBUG(4, "%s()\n", __func__ );
if(userdata)
skb_get(userdata);
ret = irttp_connect_request(self->tsap, info->dlsap_sel,
info->saddr, info->daddr, NULL,
TTP_SAR_DISABLE, userdata);
return ret;
}
static int ircomm_ttp_connect_response(struct ircomm_cb *self,
struct sk_buff *userdata)
{
int ret;
IRDA_DEBUG(4, "%s()\n", __func__ );
if(userdata)
skb_get(userdata);
ret = irttp_connect_response(self->tsap, TTP_SAR_DISABLE, userdata);
return ret;
}
static int ircomm_ttp_data_request(struct ircomm_cb *self,
struct sk_buff *skb,
int clen)
{
int ret;
IRDA_ASSERT(skb != NULL, return -1;);
IRDA_DEBUG(2, "%s(), clen=%d\n", __func__ , clen);
IRDA_ASSERT(skb_headroom(skb) >= IRCOMM_HEADER_SIZE, return -1;);
skb_get(skb);
skb_push(skb, IRCOMM_HEADER_SIZE);
skb->data[0] = clen;
ret = irttp_data_request(self->tsap, skb);
if (ret) {
IRDA_ERROR("%s(), failed\n", __func__);
}
return ret;
}
static int ircomm_ttp_data_indication(void *instance, void *sap,
struct sk_buff *skb)
{
struct ircomm_cb *self = (struct ircomm_cb *) instance;
IRDA_DEBUG(4, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_MAGIC, return -1;);
IRDA_ASSERT(skb != NULL, return -1;);
ircomm_do_event(self, IRCOMM_TTP_DATA_INDICATION, skb, NULL);
dev_kfree_skb(skb);
return 0;
}
static void ircomm_ttp_connect_confirm(void *instance, void *sap,
struct qos_info *qos,
__u32 max_sdu_size,
__u8 max_header_size,
struct sk_buff *skb)
{
struct ircomm_cb *self = (struct ircomm_cb *) instance;
struct ircomm_info info;
IRDA_DEBUG(4, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_MAGIC, return;);
IRDA_ASSERT(skb != NULL, return;);
IRDA_ASSERT(qos != NULL, goto out;);
if (max_sdu_size != TTP_SAR_DISABLE) {
IRDA_ERROR("%s(), SAR not allowed for IrCOMM!\n",
__func__);
goto out;
}
info.max_data_size = irttp_get_max_seg_size(self->tsap)
- IRCOMM_HEADER_SIZE;
info.max_header_size = max_header_size + IRCOMM_HEADER_SIZE;
info.qos = qos;
ircomm_do_event(self, IRCOMM_TTP_CONNECT_CONFIRM, skb, &info);
out:
dev_kfree_skb(skb);
}
static void ircomm_ttp_connect_indication(void *instance, void *sap,
struct qos_info *qos,
__u32 max_sdu_size,
__u8 max_header_size,
struct sk_buff *skb)
{
struct ircomm_cb *self = (struct ircomm_cb *)instance;
struct ircomm_info info;
IRDA_DEBUG(4, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_MAGIC, return;);
IRDA_ASSERT(skb != NULL, return;);
IRDA_ASSERT(qos != NULL, goto out;);
if (max_sdu_size != TTP_SAR_DISABLE) {
IRDA_ERROR("%s(), SAR not allowed for IrCOMM!\n",
__func__);
goto out;
}
info.max_data_size = irttp_get_max_seg_size(self->tsap)
- IRCOMM_HEADER_SIZE;
info.max_header_size = max_header_size + IRCOMM_HEADER_SIZE;
info.qos = qos;
ircomm_do_event(self, IRCOMM_TTP_CONNECT_INDICATION, skb, &info);
out:
dev_kfree_skb(skb);
}
static int ircomm_ttp_disconnect_request(struct ircomm_cb *self,
struct sk_buff *userdata,
struct ircomm_info *info)
{
int ret;
if(userdata)
skb_get(userdata);
ret = irttp_disconnect_request(self->tsap, userdata, P_NORMAL);
return ret;
}
static void ircomm_ttp_disconnect_indication(void *instance, void *sap,
LM_REASON reason,
struct sk_buff *skb)
{
struct ircomm_cb *self = (struct ircomm_cb *) instance;
struct ircomm_info info;
IRDA_DEBUG(2, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_MAGIC, return;);
info.reason = reason;
ircomm_do_event(self, IRCOMM_TTP_DISCONNECT_INDICATION, skb, &info);
if(skb)
dev_kfree_skb(skb);
}
static void ircomm_ttp_flow_indication(void *instance, void *sap,
LOCAL_FLOW cmd)
{
struct ircomm_cb *self = (struct ircomm_cb *) instance;
IRDA_DEBUG(4, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_MAGIC, return;);
if (self->notify.flow_indication)
self->notify.flow_indication(self->notify.instance, self, cmd);
}
