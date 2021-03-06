static int irlan_provider_data_indication(void *instance, void *sap,
struct sk_buff *skb)
{
struct irlan_cb *self;
__u8 code;
IRDA_DEBUG(4, "%s()\n", __func__ );
self = instance;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRLAN_MAGIC, return -1;);
IRDA_ASSERT(skb != NULL, return -1;);
code = skb->data[0];
switch(code) {
case CMD_GET_PROVIDER_INFO:
IRDA_DEBUG(4, "Got GET_PROVIDER_INFO command!\n");
irlan_do_provider_event(self, IRLAN_GET_INFO_CMD, skb);
break;
case CMD_GET_MEDIA_CHAR:
IRDA_DEBUG(4, "Got GET_MEDIA_CHAR command!\n");
irlan_do_provider_event(self, IRLAN_GET_MEDIA_CMD, skb);
break;
case CMD_OPEN_DATA_CHANNEL:
IRDA_DEBUG(4, "Got OPEN_DATA_CHANNEL command!\n");
irlan_do_provider_event(self, IRLAN_OPEN_DATA_CMD, skb);
break;
case CMD_FILTER_OPERATION:
IRDA_DEBUG(4, "Got FILTER_OPERATION command!\n");
irlan_do_provider_event(self, IRLAN_FILTER_CONFIG_CMD, skb);
break;
case CMD_RECONNECT_DATA_CHAN:
IRDA_DEBUG(2, "%s(), Got RECONNECT_DATA_CHAN command\n", __func__ );
IRDA_DEBUG(2, "%s(), NOT IMPLEMENTED\n", __func__ );
break;
case CMD_CLOSE_DATA_CHAN:
IRDA_DEBUG(2, "Got CLOSE_DATA_CHAN command!\n");
IRDA_DEBUG(2, "%s(), NOT IMPLEMENTED\n", __func__ );
break;
default:
IRDA_DEBUG(2, "%s(), Unknown command!\n", __func__ );
break;
}
return 0;
}
static void irlan_provider_connect_indication(void *instance, void *sap,
struct qos_info *qos,
__u32 max_sdu_size,
__u8 max_header_size,
struct sk_buff *skb)
{
struct irlan_cb *self;
struct tsap_cb *tsap;
IRDA_DEBUG(0, "%s()\n", __func__ );
self = instance;
tsap = sap;
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRLAN_MAGIC, return;);
IRDA_ASSERT(tsap == self->provider.tsap_ctrl,return;);
IRDA_ASSERT(self->provider.state == IRLAN_IDLE, return;);
self->provider.max_sdu_size = max_sdu_size;
self->provider.max_header_size = max_header_size;
irlan_do_provider_event(self, IRLAN_CONNECT_INDICATION, NULL);
if ((self->provider.access_type == ACCESS_PEER) &&
(self->client.state == IRLAN_IDLE))
{
irlan_client_wakeup(self, self->saddr, self->daddr);
}
}
void irlan_provider_connect_response(struct irlan_cb *self,
struct tsap_cb *tsap)
{
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRLAN_MAGIC, return;);
irttp_connect_response(tsap, IRLAN_MTU, NULL);
}
static void irlan_provider_disconnect_indication(void *instance, void *sap,
LM_REASON reason,
struct sk_buff *userdata)
{
struct irlan_cb *self;
struct tsap_cb *tsap;
IRDA_DEBUG(4, "%s(), reason=%d\n", __func__ , reason);
self = instance;
tsap = sap;
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRLAN_MAGIC, return;);
IRDA_ASSERT(tsap != NULL, return;);
IRDA_ASSERT(tsap->magic == TTP_TSAP_MAGIC, return;);
IRDA_ASSERT(tsap == self->provider.tsap_ctrl, return;);
irlan_do_provider_event(self, IRLAN_LMP_DISCONNECT, NULL);
}
int irlan_parse_open_data_cmd(struct irlan_cb *self, struct sk_buff *skb)
{
int ret;
ret = irlan_provider_parse_command(self, CMD_OPEN_DATA_CHANNEL, skb);
irlan_open_data_tsap(self);
return ret;
}
int irlan_provider_parse_command(struct irlan_cb *self, int cmd,
struct sk_buff *skb)
{
__u8 *frame;
__u8 *ptr;
int count;
__u16 val_len;
int i;
char *name;
char *value;
int ret = RSP_SUCCESS;
IRDA_ASSERT(skb != NULL, return -RSP_PROTOCOL_ERROR;);
IRDA_DEBUG(4, "%s(), skb->len=%d\n", __func__ , (int)skb->len);
IRDA_ASSERT(self != NULL, return -RSP_PROTOCOL_ERROR;);
IRDA_ASSERT(self->magic == IRLAN_MAGIC, return -RSP_PROTOCOL_ERROR;);
if (!skb)
return -RSP_PROTOCOL_ERROR;
frame = skb->data;
name = kmalloc(255, GFP_ATOMIC);
if (!name)
return -RSP_INSUFFICIENT_RESOURCES;
value = kmalloc(1016, GFP_ATOMIC);
if (!value) {
kfree(name);
return -RSP_INSUFFICIENT_RESOURCES;
}
count = frame[1];
IRDA_DEBUG(4, "Got %d parameters\n", count);
ptr = frame+2;
for (i=0; i<count;i++) {
ret = irlan_extract_param(ptr, name, value, &val_len);
if (ret < 0) {
IRDA_DEBUG(2, "%s(), IrLAN, Error!\n", __func__ );
break;
}
ptr+=ret;
ret = RSP_SUCCESS;
irlan_check_command_param(self, name, value);
}
kfree(name);
kfree(value);
return ret;
}
void irlan_provider_send_reply(struct irlan_cb *self, int command,
int ret_code)
{
struct sk_buff *skb;
IRDA_DEBUG(4, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRLAN_MAGIC, return;);
skb = alloc_skb(IRLAN_MAX_HEADER + IRLAN_CMD_HEADER +
IRLAN_STRING_PARAMETER_LEN("FILTER_TYPE", "DIRECTED") +
IRLAN_STRING_PARAMETER_LEN("FILTER_TYPE", "BROADCAST") +
IRLAN_STRING_PARAMETER_LEN("FILTER_TYPE", "MULTICAST") +
IRLAN_STRING_PARAMETER_LEN("ACCESS_TYPE", "HOSTED"),
GFP_ATOMIC);
if (!skb)
return;
skb_reserve(skb, self->provider.max_header_size);
skb_put(skb, 2);
switch (command) {
case CMD_GET_PROVIDER_INFO:
skb->data[0] = 0x00;
skb->data[1] = 0x02;
switch (self->media) {
case MEDIA_802_3:
irlan_insert_string_param(skb, "MEDIA", "802.3");
break;
case MEDIA_802_5:
irlan_insert_string_param(skb, "MEDIA", "802.5");
break;
default:
IRDA_DEBUG(2, "%s(), unknown media type!\n", __func__ );
break;
}
irlan_insert_short_param(skb, "IRLAN_VER", 0x0101);
break;
case CMD_GET_MEDIA_CHAR:
skb->data[0] = 0x00;
skb->data[1] = 0x05;
irlan_insert_string_param(skb, "FILTER_TYPE", "DIRECTED");
irlan_insert_string_param(skb, "FILTER_TYPE", "BROADCAST");
irlan_insert_string_param(skb, "FILTER_TYPE", "MULTICAST");
switch (self->provider.access_type) {
case ACCESS_DIRECT:
irlan_insert_string_param(skb, "ACCESS_TYPE", "DIRECT");
break;
case ACCESS_PEER:
irlan_insert_string_param(skb, "ACCESS_TYPE", "PEER");
break;
case ACCESS_HOSTED:
irlan_insert_string_param(skb, "ACCESS_TYPE", "HOSTED");
break;
default:
IRDA_DEBUG(2, "%s(), Unknown access type\n", __func__ );
break;
}
irlan_insert_short_param(skb, "MAX_FRAME", 0x05ee);
break;
case CMD_OPEN_DATA_CHANNEL:
skb->data[0] = 0x00;
if (self->provider.send_arb_val) {
skb->data[1] = 0x03;
irlan_insert_short_param(skb, "CON_ARB",
self->provider.send_arb_val);
} else
skb->data[1] = 0x02;
irlan_insert_byte_param(skb, "DATA_CHAN", self->stsap_sel_data);
irlan_insert_string_param(skb, "RECONNECT_KEY", "LINUX RULES!");
break;
case CMD_FILTER_OPERATION:
irlan_filter_request(self, skb);
break;
default:
IRDA_DEBUG(2, "%s(), Unknown command!\n", __func__ );
break;
}
irttp_data_request(self->provider.tsap_ctrl, skb);
}
int irlan_provider_open_ctrl_tsap(struct irlan_cb *self)
{
struct tsap_cb *tsap;
notify_t notify;
IRDA_DEBUG(4, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRLAN_MAGIC, return -1;);
if (self->provider.tsap_ctrl)
return -1;
irda_notify_init(&notify);
notify.data_indication = irlan_provider_data_indication;
notify.connect_indication = irlan_provider_connect_indication;
notify.disconnect_indication = irlan_provider_disconnect_indication;
notify.instance = self;
strlcpy(notify.name, "IrLAN ctrl (p)", sizeof(notify.name));
tsap = irttp_open_tsap(LSAP_ANY, 1, &notify);
if (!tsap) {
IRDA_DEBUG(2, "%s(), Got no tsap!\n", __func__ );
return -1;
}
self->provider.tsap_ctrl = tsap;
irlan_ias_register(self, tsap->stsap_sel);
return 0;
}
