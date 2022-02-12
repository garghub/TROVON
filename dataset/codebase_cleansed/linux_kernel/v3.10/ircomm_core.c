static int __init ircomm_init(void)
{
ircomm = hashbin_new(HB_LOCK);
if (ircomm == NULL) {
IRDA_ERROR("%s(), can't allocate hashbin!\n", __func__);
return -ENOMEM;
}
#ifdef CONFIG_PROC_FS
{ struct proc_dir_entry *ent;
ent = proc_create("ircomm", 0, proc_irda, &ircomm_proc_fops);
if (!ent) {
printk(KERN_ERR "ircomm_init: can't create /proc entry!\n");
return -ENODEV;
}
}
#endif
IRDA_MESSAGE("IrCOMM protocol (Dag Brattli)\n");
return 0;
}
static void __exit ircomm_cleanup(void)
{
IRDA_DEBUG(2, "%s()\n", __func__ );
hashbin_delete(ircomm, (FREE_FUNC) __ircomm_close);
#ifdef CONFIG_PROC_FS
remove_proc_entry("ircomm", proc_irda);
#endif
}
struct ircomm_cb *ircomm_open(notify_t *notify, __u8 service_type, int line)
{
struct ircomm_cb *self = NULL;
int ret;
IRDA_DEBUG(2, "%s(), service_type=0x%02x\n", __func__ ,
service_type);
IRDA_ASSERT(ircomm != NULL, return NULL;);
self = kzalloc(sizeof(struct ircomm_cb), GFP_KERNEL);
if (self == NULL)
return NULL;
self->notify = *notify;
self->magic = IRCOMM_MAGIC;
if (service_type & IRCOMM_3_WIRE_RAW) {
self->flow_status = FLOW_START;
ret = ircomm_open_lsap(self);
} else
ret = ircomm_open_tsap(self);
if (ret < 0) {
kfree(self);
return NULL;
}
self->service_type = service_type;
self->line = line;
hashbin_insert(ircomm, (irda_queue_t *) self, line, NULL);
ircomm_next_state(self, IRCOMM_IDLE);
return self;
}
static int __ircomm_close(struct ircomm_cb *self)
{
IRDA_DEBUG(2, "%s()\n", __func__ );
ircomm_do_event(self, IRCOMM_DISCONNECT_REQUEST, NULL, NULL);
if (self->tsap) {
irttp_close_tsap(self->tsap);
self->tsap = NULL;
}
if (self->lsap) {
irlmp_close_lsap(self->lsap);
self->lsap = NULL;
}
self->magic = 0;
kfree(self);
return 0;
}
int ircomm_close(struct ircomm_cb *self)
{
struct ircomm_cb *entry;
IRDA_ASSERT(self != NULL, return -EIO;);
IRDA_ASSERT(self->magic == IRCOMM_MAGIC, return -EIO;);
IRDA_DEBUG(0, "%s()\n", __func__ );
entry = hashbin_remove(ircomm, self->line, NULL);
IRDA_ASSERT(entry == self, return -1;);
return __ircomm_close(self);
}
int ircomm_connect_request(struct ircomm_cb *self, __u8 dlsap_sel,
__u32 saddr, __u32 daddr, struct sk_buff *skb,
__u8 service_type)
{
struct ircomm_info info;
int ret;
IRDA_DEBUG(2 , "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_MAGIC, return -1;);
self->service_type= service_type;
info.dlsap_sel = dlsap_sel;
info.saddr = saddr;
info.daddr = daddr;
ret = ircomm_do_event(self, IRCOMM_CONNECT_REQUEST, skb, &info);
return ret;
}
void ircomm_connect_indication(struct ircomm_cb *self, struct sk_buff *skb,
struct ircomm_info *info)
{
IRDA_DEBUG(2, "%s()\n", __func__ );
if (self->notify.connect_indication)
self->notify.connect_indication(self->notify.instance, self,
info->qos, info->max_data_size,
info->max_header_size, skb);
else {
IRDA_DEBUG(0, "%s(), missing handler\n", __func__ );
}
}
int ircomm_connect_response(struct ircomm_cb *self, struct sk_buff *userdata)
{
int ret;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_MAGIC, return -1;);
IRDA_DEBUG(4, "%s()\n", __func__ );
ret = ircomm_do_event(self, IRCOMM_CONNECT_RESPONSE, userdata, NULL);
return ret;
}
void ircomm_connect_confirm(struct ircomm_cb *self, struct sk_buff *skb,
struct ircomm_info *info)
{
IRDA_DEBUG(4, "%s()\n", __func__ );
if (self->notify.connect_confirm )
self->notify.connect_confirm(self->notify.instance,
self, info->qos,
info->max_data_size,
info->max_header_size, skb);
else {
IRDA_DEBUG(0, "%s(), missing handler\n", __func__ );
}
}
int ircomm_data_request(struct ircomm_cb *self, struct sk_buff *skb)
{
int ret;
IRDA_DEBUG(4, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return -EFAULT;);
IRDA_ASSERT(self->magic == IRCOMM_MAGIC, return -EFAULT;);
IRDA_ASSERT(skb != NULL, return -EFAULT;);
ret = ircomm_do_event(self, IRCOMM_DATA_REQUEST, skb, NULL);
return ret;
}
void ircomm_data_indication(struct ircomm_cb *self, struct sk_buff *skb)
{
IRDA_DEBUG(4, "%s()\n", __func__ );
IRDA_ASSERT(skb->len > 0, return;);
if (self->notify.data_indication)
self->notify.data_indication(self->notify.instance, self, skb);
else {
IRDA_DEBUG(0, "%s(), missing handler\n", __func__ );
}
}
void ircomm_process_data(struct ircomm_cb *self, struct sk_buff *skb)
{
int clen;
IRDA_ASSERT(skb->len > 0, return;);
clen = skb->data[0];
if (unlikely(skb->len < (clen + 1))) {
IRDA_DEBUG(2, "%s() throwing away illegal frame\n",
__func__ );
return;
}
if (clen > 0)
ircomm_control_indication(self, skb, clen);
skb_pull(skb, clen+1);
if (skb->len)
ircomm_data_indication(self, skb);
else {
IRDA_DEBUG(4, "%s(), data was control info only!\n",
__func__ );
}
}
int ircomm_control_request(struct ircomm_cb *self, struct sk_buff *skb)
{
int ret;
IRDA_DEBUG(2, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return -EFAULT;);
IRDA_ASSERT(self->magic == IRCOMM_MAGIC, return -EFAULT;);
IRDA_ASSERT(skb != NULL, return -EFAULT;);
ret = ircomm_do_event(self, IRCOMM_CONTROL_REQUEST, skb, NULL);
return ret;
}
static void ircomm_control_indication(struct ircomm_cb *self,
struct sk_buff *skb, int clen)
{
IRDA_DEBUG(2, "%s()\n", __func__ );
if (self->notify.udata_indication) {
struct sk_buff *ctrl_skb;
ctrl_skb = skb_clone(skb, GFP_ATOMIC);
if (!ctrl_skb)
return;
skb_trim(ctrl_skb, clen+1);
self->notify.udata_indication(self->notify.instance, self,
ctrl_skb);
dev_kfree_skb(ctrl_skb);
} else {
IRDA_DEBUG(0, "%s(), missing handler\n", __func__ );
}
}
int ircomm_disconnect_request(struct ircomm_cb *self, struct sk_buff *userdata)
{
struct ircomm_info info;
int ret;
IRDA_DEBUG(2, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_MAGIC, return -1;);
ret = ircomm_do_event(self, IRCOMM_DISCONNECT_REQUEST, userdata,
&info);
return ret;
}
void ircomm_disconnect_indication(struct ircomm_cb *self, struct sk_buff *skb,
struct ircomm_info *info)
{
IRDA_DEBUG(2, "%s()\n", __func__ );
IRDA_ASSERT(info != NULL, return;);
if (self->notify.disconnect_indication) {
self->notify.disconnect_indication(self->notify.instance, self,
info->reason, skb);
} else {
IRDA_DEBUG(0, "%s(), missing handler\n", __func__ );
}
}
void ircomm_flow_request(struct ircomm_cb *self, LOCAL_FLOW flow)
{
IRDA_DEBUG(2, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_MAGIC, return;);
if (self->service_type == IRCOMM_3_WIRE_RAW)
return;
irttp_flow_request(self->tsap, flow);
}
static void *ircomm_seq_start(struct seq_file *seq, loff_t *pos)
{
struct ircomm_cb *self;
loff_t off = 0;
spin_lock_irq(&ircomm->hb_spinlock);
for (self = (struct ircomm_cb *) hashbin_get_first(ircomm);
self != NULL;
self = (struct ircomm_cb *) hashbin_get_next(ircomm)) {
if (off++ == *pos)
break;
}
return self;
}
static void *ircomm_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
++*pos;
return (void *) hashbin_get_next(ircomm);
}
static void ircomm_seq_stop(struct seq_file *seq, void *v)
{
spin_unlock_irq(&ircomm->hb_spinlock);
}
static int ircomm_seq_show(struct seq_file *seq, void *v)
{
const struct ircomm_cb *self = v;
IRDA_ASSERT(self->magic == IRCOMM_MAGIC, return -EINVAL; );
if(self->line < 0x10)
seq_printf(seq, "ircomm%d", self->line);
else
seq_printf(seq, "irlpt%d", self->line - 0x10);
seq_printf(seq,
" state: %s, slsap_sel: %#02x, dlsap_sel: %#02x, mode:",
ircomm_state[ self->state],
self->slsap_sel, self->dlsap_sel);
if(self->service_type & IRCOMM_3_WIRE_RAW)
seq_printf(seq, " 3-wire-raw");
if(self->service_type & IRCOMM_3_WIRE)
seq_printf(seq, " 3-wire");
if(self->service_type & IRCOMM_9_WIRE)
seq_printf(seq, " 9-wire");
if(self->service_type & IRCOMM_CENTRONICS)
seq_printf(seq, " Centronics");
seq_putc(seq, '\n');
return 0;
}
static int ircomm_seq_open(struct inode *inode, struct file *file)
{
return seq_open(file, &ircomm_seq_ops);
}
