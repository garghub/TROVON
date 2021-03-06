static inline void iriap_start_watchdog_timer(struct iriap_cb *self,
int timeout)
{
irda_start_timer(&self->watchdog_timer, timeout, self,
iriap_watchdog_timer_expired);
}
int __init iriap_init(void)
{
struct ias_object *obj;
struct iriap_cb *server;
__u8 oct_seq[6];
__u16 hints;
iriap = hashbin_new(HB_LOCK);
if (!iriap)
return -ENOMEM;
irias_objects = hashbin_new(HB_LOCK);
if (!irias_objects) {
IRDA_WARNING("%s: Can't allocate irias_objects hashbin!\n",
__func__);
hashbin_delete(iriap, NULL);
return -ENOMEM;
}
lockdep_set_class_and_name(&irias_objects->hb_spinlock, &irias_objects_key,
"irias_objects");
hints = irlmp_service_to_hint(S_COMPUTER);
service_handle = irlmp_register_service(hints);
obj = irias_new_object("Device", IAS_DEVICE_ID);
irias_add_string_attrib(obj, "DeviceName", "Linux", IAS_KERNEL_ATTR);
oct_seq[0] = 0x01;
oct_seq[1] = 0x00;
oct_seq[2] = 0x00;
#ifdef CONFIG_IRDA_ULTRA
oct_seq[2] |= 0x04;
#endif
irias_add_octseq_attrib(obj, "IrLMPSupport", oct_seq, 3,
IAS_KERNEL_ATTR);
irias_insert_object(obj);
server = iriap_open(LSAP_IAS, IAS_SERVER, NULL, NULL);
if (!server) {
IRDA_DEBUG(0, "%s(), unable to open server\n", __func__);
return -1;
}
iriap_register_lsap(server, LSAP_IAS, IAS_SERVER);
return 0;
}
void iriap_cleanup(void)
{
irlmp_unregister_service(service_handle);
hashbin_delete(iriap, (FREE_FUNC) __iriap_close);
hashbin_delete(irias_objects, (FREE_FUNC) __irias_delete_object);
}
struct iriap_cb *iriap_open(__u8 slsap_sel, int mode, void *priv,
CONFIRM_CALLBACK callback)
{
struct iriap_cb *self;
IRDA_DEBUG(2, "%s()\n", __func__);
self = kzalloc(sizeof(*self), GFP_ATOMIC);
if (!self) {
IRDA_WARNING("%s: Unable to kmalloc!\n", __func__);
return NULL;
}
self->magic = IAS_MAGIC;
self->mode = mode;
if (mode == IAS_CLIENT)
iriap_register_lsap(self, slsap_sel, mode);
self->confirm = callback;
self->priv = priv;
self->max_header_size = LMP_MAX_HEADER;
init_timer(&self->watchdog_timer);
hashbin_insert(iriap, (irda_queue_t *) self, (long) self, NULL);
iriap_next_client_state(self, S_DISCONNECT);
iriap_next_call_state(self, S_MAKE_CALL);
iriap_next_server_state(self, R_DISCONNECT);
iriap_next_r_connect_state(self, R_WAITING);
return self;
}
static void __iriap_close(struct iriap_cb *self)
{
IRDA_DEBUG(4, "%s()\n", __func__);
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
del_timer(&self->watchdog_timer);
if (self->request_skb)
dev_kfree_skb(self->request_skb);
self->magic = 0;
kfree(self);
}
void iriap_close(struct iriap_cb *self)
{
struct iriap_cb *entry;
IRDA_DEBUG(2, "%s()\n", __func__);
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
if (self->lsap) {
irlmp_close_lsap(self->lsap);
self->lsap = NULL;
}
entry = (struct iriap_cb *) hashbin_remove(iriap, (long) self, NULL);
IRDA_ASSERT(entry == self, return;);
__iriap_close(self);
}
static int iriap_register_lsap(struct iriap_cb *self, __u8 slsap_sel, int mode)
{
notify_t notify;
IRDA_DEBUG(2, "%s()\n", __func__);
irda_notify_init(&notify);
notify.connect_confirm = iriap_connect_confirm;
notify.connect_indication = iriap_connect_indication;
notify.disconnect_indication = iriap_disconnect_indication;
notify.data_indication = iriap_data_indication;
notify.instance = self;
if (mode == IAS_CLIENT)
strcpy(notify.name, "IrIAS cli");
else
strcpy(notify.name, "IrIAS srv");
self->lsap = irlmp_open_lsap(slsap_sel, &notify, 0);
if (self->lsap == NULL) {
IRDA_ERROR("%s: Unable to allocated LSAP!\n", __func__);
return -1;
}
self->slsap_sel = self->lsap->slsap_sel;
return 0;
}
static void iriap_disconnect_indication(void *instance, void *sap,
LM_REASON reason,
struct sk_buff *skb)
{
struct iriap_cb *self;
IRDA_DEBUG(4, "%s(), reason=%s [%d]\n", __func__,
irlmp_reason_str(reason), reason);
self = instance;
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
IRDA_ASSERT(iriap != NULL, return;);
del_timer(&self->watchdog_timer);
if (skb)
dev_kfree_skb(skb);
if (self->mode == IAS_CLIENT) {
IRDA_DEBUG(4, "%s(), disconnect as client\n", __func__);
iriap_do_client_event(self, IAP_LM_DISCONNECT_INDICATION,
NULL);
if (self->confirm)
self->confirm(IAS_DISCONNECT, 0, NULL, self->priv);
} else {
IRDA_DEBUG(4, "%s(), disconnect as server\n", __func__);
iriap_do_server_event(self, IAP_LM_DISCONNECT_INDICATION,
NULL);
iriap_close(self);
}
}
static void iriap_disconnect_request(struct iriap_cb *self)
{
struct sk_buff *tx_skb;
IRDA_DEBUG(4, "%s()\n", __func__);
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
tx_skb = alloc_skb(LMP_MAX_HEADER, GFP_ATOMIC);
if (tx_skb == NULL) {
IRDA_DEBUG(0,
"%s(), Could not allocate an sk_buff of length %d\n",
__func__, LMP_MAX_HEADER);
return;
}
skb_reserve(tx_skb, LMP_MAX_HEADER);
irlmp_disconnect_request(self->lsap, tx_skb);
}
int iriap_getvaluebyclass_request(struct iriap_cb *self,
__u32 saddr, __u32 daddr,
char *name, char *attr)
{
struct sk_buff *tx_skb;
int name_len, attr_len, skb_len;
__u8 *frame;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return -1;);
if (!daddr)
return -1;
self->daddr = daddr;
self->saddr = saddr;
self->operation = GET_VALUE_BY_CLASS;
iriap_start_watchdog_timer(self, 10*HZ);
name_len = strlen(name);
attr_len = strlen(attr);
skb_len = self->max_header_size+2+name_len+1+attr_len+4;
tx_skb = alloc_skb(skb_len, GFP_ATOMIC);
if (!tx_skb)
return -ENOMEM;
skb_reserve(tx_skb, self->max_header_size);
skb_put(tx_skb, 3+name_len+attr_len);
frame = tx_skb->data;
frame[0] = IAP_LST | GET_VALUE_BY_CLASS;
frame[1] = name_len;
memcpy(frame+2, name, name_len);
frame[2+name_len] = attr_len;
memcpy(frame+3+name_len, attr, attr_len);
iriap_do_client_event(self, IAP_CALL_REQUEST_GVBC, tx_skb);
dev_kfree_skb(tx_skb);
return 0;
}
static void iriap_getvaluebyclass_confirm(struct iriap_cb *self,
struct sk_buff *skb)
{
struct ias_value *value;
int charset;
__u32 value_len;
__u32 tmp_cpu32;
__u16 obj_id;
__u16 len;
__u8 type;
__u8 *fp;
int n;
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
IRDA_ASSERT(skb != NULL, return;);
fp = skb->data;
n = 2;
len = get_unaligned_be16(fp + n);
n += 2;
IRDA_DEBUG(4, "%s(), len=%d\n", __func__, len);
obj_id = get_unaligned_be16(fp + n);
n += 2;
type = fp[n++];
IRDA_DEBUG(4, "%s(), Value type = %d\n", __func__, type);
switch (type) {
case IAS_INTEGER:
memcpy(&tmp_cpu32, fp+n, 4); n += 4;
be32_to_cpus(&tmp_cpu32);
value = irias_new_integer_value(tmp_cpu32);
IRDA_DEBUG(4, "%s(), lsap=%d\n", __func__, value->t.integer);
break;
case IAS_STRING:
charset = fp[n++];
switch (charset) {
case CS_ASCII:
break;
default:
IRDA_DEBUG(0, "%s(), charset [%d] %s, not supported\n",
__func__, charset,
charset < ARRAY_SIZE(ias_charset_types) ?
ias_charset_types[charset] :
"(unknown)");
iriap_disconnect_request(self);
return;
}
value_len = fp[n++];
IRDA_DEBUG(4, "%s(), strlen=%d\n", __func__, value_len);
if (n + value_len < skb->len)
fp[n + value_len] = 0x00;
IRDA_DEBUG(4, "Got string %s\n", fp+n);
value = irias_new_string_value(fp+n);
break;
case IAS_OCT_SEQ:
value_len = get_unaligned_be16(fp + n);
n += 2;
value = irias_new_octseq_value(fp+n, value_len);
break;
default:
value = irias_new_missing_value();
break;
}
iriap_disconnect_request(self);
if (self->confirm)
self->confirm(IAS_SUCCESS, obj_id, value, self->priv);
else {
IRDA_DEBUG(0, "%s(), missing handler!\n", __func__);
irias_delete_value(value);
}
}
static void iriap_getvaluebyclass_response(struct iriap_cb *self,
__u16 obj_id,
__u8 ret_code,
struct ias_value *value)
{
struct sk_buff *tx_skb;
int n;
__be32 tmp_be32;
__be16 tmp_be16;
__u8 *fp;
IRDA_DEBUG(4, "%s()\n", __func__);
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
IRDA_ASSERT(value != NULL, return;);
IRDA_ASSERT(value->len <= 1024, return;);
n = 0;
tx_skb = alloc_skb(value->len + self->max_header_size + 32,
GFP_ATOMIC);
if (!tx_skb)
return;
skb_reserve(tx_skb, self->max_header_size);
skb_put(tx_skb, 6);
fp = tx_skb->data;
fp[n++] = GET_VALUE_BY_CLASS | IAP_LST;
fp[n++] = ret_code;
tmp_be16 = htons(0x0001);
memcpy(fp+n, &tmp_be16, 2); n += 2;
tmp_be16 = cpu_to_be16(obj_id);
memcpy(fp+n, &tmp_be16, 2); n += 2;
switch (value->type) {
case IAS_STRING:
skb_put(tx_skb, 3 + value->len);
fp[n++] = value->type;
fp[n++] = 0;
fp[n++] = (__u8) value->len;
memcpy(fp+n, value->t.string, value->len); n+=value->len;
break;
case IAS_INTEGER:
skb_put(tx_skb, 5);
fp[n++] = value->type;
tmp_be32 = cpu_to_be32(value->t.integer);
memcpy(fp+n, &tmp_be32, 4); n += 4;
break;
case IAS_OCT_SEQ:
skb_put(tx_skb, 3 + value->len);
fp[n++] = value->type;
tmp_be16 = cpu_to_be16(value->len);
memcpy(fp+n, &tmp_be16, 2); n += 2;
memcpy(fp+n, value->t.oct_seq, value->len); n+=value->len;
break;
case IAS_MISSING:
IRDA_DEBUG( 3, "%s: sending IAS_MISSING\n", __func__);
skb_put(tx_skb, 1);
fp[n++] = value->type;
break;
default:
IRDA_DEBUG(0, "%s(), type not implemented!\n", __func__);
break;
}
iriap_do_r_connect_event(self, IAP_CALL_RESPONSE, tx_skb);
dev_kfree_skb(tx_skb);
}
static void iriap_getvaluebyclass_indication(struct iriap_cb *self,
struct sk_buff *skb)
{
struct ias_object *obj;
struct ias_attrib *attrib;
int name_len;
int attr_len;
char name[IAS_MAX_CLASSNAME + 1];
char attr[IAS_MAX_ATTRIBNAME + 1];
__u8 *fp;
int n;
IRDA_DEBUG(4, "%s()\n", __func__);
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
IRDA_ASSERT(skb != NULL, return;);
fp = skb->data;
n = 1;
name_len = fp[n++];
IRDA_ASSERT(name_len < IAS_MAX_CLASSNAME + 1, return;);
memcpy(name, fp+n, name_len); n+=name_len;
name[name_len] = '\0';
attr_len = fp[n++];
IRDA_ASSERT(attr_len < IAS_MAX_ATTRIBNAME + 1, return;);
memcpy(attr, fp+n, attr_len); n+=attr_len;
attr[attr_len] = '\0';
IRDA_DEBUG(4, "LM-IAS: Looking up %s: %s\n", name, attr);
obj = irias_find_object(name);
if (obj == NULL) {
IRDA_DEBUG(2, "LM-IAS: Object %s not found\n", name);
iriap_getvaluebyclass_response(self, 0x1235, IAS_CLASS_UNKNOWN,
&irias_missing);
return;
}
IRDA_DEBUG(4, "LM-IAS: found %s, id=%d\n", obj->name, obj->id);
attrib = irias_find_attrib(obj, attr);
if (attrib == NULL) {
IRDA_DEBUG(2, "LM-IAS: Attribute %s not found\n", attr);
iriap_getvaluebyclass_response(self, obj->id,
IAS_ATTRIB_UNKNOWN,
&irias_missing);
return;
}
iriap_getvaluebyclass_response(self, obj->id, IAS_SUCCESS,
attrib->value);
}
void iriap_send_ack(struct iriap_cb *self)
{
struct sk_buff *tx_skb;
__u8 *frame;
IRDA_DEBUG(2, "%s()\n", __func__);
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
tx_skb = alloc_skb(LMP_MAX_HEADER + 1, GFP_ATOMIC);
if (!tx_skb)
return;
skb_reserve(tx_skb, self->max_header_size);
skb_put(tx_skb, 1);
frame = tx_skb->data;
frame[0] = IAP_LST | IAP_ACK | self->operation;
irlmp_data_request(self->lsap, tx_skb);
}
void iriap_connect_request(struct iriap_cb *self)
{
int ret;
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
ret = irlmp_connect_request(self->lsap, LSAP_IAS,
self->saddr, self->daddr,
NULL, NULL);
if (ret < 0) {
IRDA_DEBUG(0, "%s(), connect failed!\n", __func__);
self->confirm(IAS_DISCONNECT, 0, NULL, self->priv);
}
}
static void iriap_connect_confirm(void *instance, void *sap,
struct qos_info *qos, __u32 max_seg_size,
__u8 max_header_size,
struct sk_buff *skb)
{
struct iriap_cb *self;
self = instance;
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
IRDA_ASSERT(skb != NULL, return;);
self->max_data_size = max_seg_size;
self->max_header_size = max_header_size;
del_timer(&self->watchdog_timer);
iriap_do_client_event(self, IAP_LM_CONNECT_CONFIRM, skb);
dev_kfree_skb(skb);
}
static void iriap_connect_indication(void *instance, void *sap,
struct qos_info *qos, __u32 max_seg_size,
__u8 max_header_size,
struct sk_buff *skb)
{
struct iriap_cb *self, *new;
IRDA_DEBUG(1, "%s()\n", __func__);
self = instance;
IRDA_ASSERT(skb != NULL, return;);
IRDA_ASSERT(self != NULL, goto out;);
IRDA_ASSERT(self->magic == IAS_MAGIC, goto out;);
new = iriap_open(LSAP_IAS, IAS_SERVER, NULL, NULL);
if (!new) {
IRDA_DEBUG(0, "%s(), open failed\n", __func__);
goto out;
}
new->lsap = irlmp_dup(self->lsap, new);
if (!new->lsap) {
IRDA_DEBUG(0, "%s(), dup failed!\n", __func__);
goto out;
}
new->max_data_size = max_seg_size;
new->max_header_size = max_header_size;
irlmp_listen(self->lsap);
iriap_do_server_event(new, IAP_LM_CONNECT_INDICATION, skb);
out:
dev_kfree_skb(skb);
}
static int iriap_data_indication(void *instance, void *sap,
struct sk_buff *skb)
{
struct iriap_cb *self;
__u8 *frame;
__u8 opcode;
IRDA_DEBUG(3, "%s()\n", __func__);
self = instance;
IRDA_ASSERT(skb != NULL, return 0;);
IRDA_ASSERT(self != NULL, goto out;);
IRDA_ASSERT(self->magic == IAS_MAGIC, goto out;);
frame = skb->data;
if (self->mode == IAS_SERVER) {
IRDA_DEBUG(4, "%s(), Calling server!\n", __func__);
iriap_do_r_connect_event(self, IAP_RECV_F_LST, skb);
goto out;
}
opcode = frame[0];
if (~opcode & IAP_LST) {
IRDA_WARNING("%s:, IrIAS multiframe commands or "
"results is not implemented yet!\n",
__func__);
goto out;
}
if (opcode & IAP_ACK) {
IRDA_DEBUG(0, "%s() Got ack frame!\n", __func__);
goto out;
}
opcode &= ~IAP_LST;
switch (opcode) {
case GET_INFO_BASE:
IRDA_DEBUG(0, "IrLMP GetInfoBaseDetails not implemented!\n");
break;
case GET_VALUE_BY_CLASS:
iriap_do_call_event(self, IAP_RECV_F_LST, NULL);
switch (frame[1]) {
case IAS_SUCCESS:
iriap_getvaluebyclass_confirm(self, skb);
break;
case IAS_CLASS_UNKNOWN:
IRDA_DEBUG(1, "%s(), No such class!\n", __func__);
iriap_disconnect_request(self);
if (self->confirm)
self->confirm(IAS_CLASS_UNKNOWN, 0, NULL,
self->priv);
break;
case IAS_ATTRIB_UNKNOWN:
IRDA_DEBUG(1, "%s(), No such attribute!\n", __func__);
iriap_disconnect_request(self);
if (self->confirm)
self->confirm(IAS_ATTRIB_UNKNOWN, 0, NULL,
self->priv);
break;
}
break;
default:
IRDA_DEBUG(0, "%s(), Unknown op-code: %02x\n", __func__,
opcode);
break;
}
out:
dev_kfree_skb(skb);
return 0;
}
void iriap_call_indication(struct iriap_cb *self, struct sk_buff *skb)
{
__u8 *fp;
__u8 opcode;
IRDA_DEBUG(4, "%s()\n", __func__);
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
IRDA_ASSERT(skb != NULL, return;);
fp = skb->data;
opcode = fp[0];
if (~opcode & 0x80) {
IRDA_WARNING("%s: IrIAS multiframe commands or results "
"is not implemented yet!\n", __func__);
return;
}
opcode &= 0x7f;
switch (opcode) {
case GET_INFO_BASE:
IRDA_WARNING("%s: GetInfoBaseDetails not implemented yet!\n",
__func__);
break;
case GET_VALUE_BY_CLASS:
iriap_getvaluebyclass_indication(self, skb);
break;
}
}
static void iriap_watchdog_timer_expired(void *data)
{
struct iriap_cb *self = (struct iriap_cb *) data;
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IAS_MAGIC, return;);
}
static inline struct ias_object *irias_seq_idx(loff_t pos)
{
struct ias_object *obj;
for (obj = (struct ias_object *) hashbin_get_first(irias_objects);
obj; obj = (struct ias_object *) hashbin_get_next(irias_objects)) {
if (pos-- == 0)
break;
}
return obj;
}
static void *irias_seq_start(struct seq_file *seq, loff_t *pos)
{
spin_lock_irq(&irias_objects->hb_spinlock);
return *pos ? irias_seq_idx(*pos - 1) : SEQ_START_TOKEN;
}
static void *irias_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
++*pos;
return (v == SEQ_START_TOKEN)
? (void *) hashbin_get_first(irias_objects)
: (void *) hashbin_get_next(irias_objects);
}
static void irias_seq_stop(struct seq_file *seq, void *v)
{
spin_unlock_irq(&irias_objects->hb_spinlock);
}
static int irias_seq_show(struct seq_file *seq, void *v)
{
if (v == SEQ_START_TOKEN)
seq_puts(seq, "LM-IAS Objects:\n");
else {
struct ias_object *obj = v;
struct ias_attrib *attrib;
IRDA_ASSERT(obj->magic == IAS_OBJECT_MAGIC, return -EINVAL;);
seq_printf(seq, "name: %s, id=%d\n",
obj->name, obj->id);
spin_lock(&obj->attribs->hb_spinlock);
for (attrib = (struct ias_attrib *) hashbin_get_first(obj->attribs);
attrib != NULL;
attrib = (struct ias_attrib *) hashbin_get_next(obj->attribs)) {
IRDA_ASSERT(attrib->magic == IAS_ATTRIB_MAGIC,
goto outloop; );
seq_printf(seq, " - Attribute name: \"%s\", ",
attrib->name);
seq_printf(seq, "value[%s]: ",
ias_value_types[attrib->value->type]);
switch (attrib->value->type) {
case IAS_INTEGER:
seq_printf(seq, "%d\n",
attrib->value->t.integer);
break;
case IAS_STRING:
seq_printf(seq, "\"%s\"\n",
attrib->value->t.string);
break;
case IAS_OCT_SEQ:
seq_printf(seq, "octet sequence (%d bytes)\n",
attrib->value->len);
break;
case IAS_MISSING:
seq_puts(seq, "missing\n");
break;
default:
seq_printf(seq, "type %d?\n",
attrib->value->type);
}
seq_putc(seq, '\n');
}
IRDA_ASSERT_LABEL(outloop:)
spin_unlock(&obj->attribs->hb_spinlock);
}
return 0;
}
static int irias_seq_open(struct inode *inode, struct file *file)
{
IRDA_ASSERT( irias_objects != NULL, return -EINVAL;);
return seq_open(file, &irias_seq_ops);
}
