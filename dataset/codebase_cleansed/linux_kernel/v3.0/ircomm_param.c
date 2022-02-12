int ircomm_param_request(struct ircomm_tty_cb *self, __u8 pi, int flush)
{
struct tty_struct *tty;
unsigned long flags;
struct sk_buff *skb;
int count;
IRDA_DEBUG(2, "%s()\n", __func__ );
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return -1;);
tty = self->tty;
if (!tty)
return 0;
if (self->service_type == IRCOMM_3_WIRE_RAW)
return 0;
spin_lock_irqsave(&self->spinlock, flags);
skb = self->ctrl_skb;
if (!skb) {
skb = alloc_skb(256, GFP_ATOMIC);
if (!skb) {
spin_unlock_irqrestore(&self->spinlock, flags);
return -ENOMEM;
}
skb_reserve(skb, self->max_header_size);
self->ctrl_skb = skb;
}
count = irda_param_insert(self, pi, skb_tail_pointer(skb),
skb_tailroom(skb), &ircomm_param_info);
if (count < 0) {
IRDA_WARNING("%s(), no room for parameter!\n", __func__);
spin_unlock_irqrestore(&self->spinlock, flags);
return -1;
}
skb_put(skb, count);
spin_unlock_irqrestore(&self->spinlock, flags);
IRDA_DEBUG(2, "%s(), skb->len=%d\n", __func__ , skb->len);
if (flush) {
schedule_work(&self->tqueue);
}
return count;
}
static int ircomm_param_service_type(void *instance, irda_param_t *param,
int get)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) instance;
__u8 service_type = (__u8) param->pv.i;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return -1;);
if (get) {
param->pv.i = self->settings.service_type;
return 0;
}
service_type &= self->service_type;
if (!service_type) {
IRDA_DEBUG(2,
"%s(), No common service type to use!\n", __func__ );
return -1;
}
IRDA_DEBUG(0, "%s(), services in common=%02x\n", __func__ ,
service_type);
if (service_type & IRCOMM_CENTRONICS)
self->settings.service_type = IRCOMM_CENTRONICS;
else if (service_type & IRCOMM_9_WIRE)
self->settings.service_type = IRCOMM_9_WIRE;
else if (service_type & IRCOMM_3_WIRE)
self->settings.service_type = IRCOMM_3_WIRE;
else if (service_type & IRCOMM_3_WIRE_RAW)
self->settings.service_type = IRCOMM_3_WIRE_RAW;
IRDA_DEBUG(0, "%s(), resulting service type=0x%02x\n", __func__ ,
self->settings.service_type);
if ((self->max_header_size != IRCOMM_TTY_HDR_UNINITIALISED) &&
(!self->client) &&
(self->settings.service_type != IRCOMM_3_WIRE_RAW))
{
ircomm_tty_send_initial_parameters(self);
ircomm_tty_link_established(self);
}
return 0;
}
static int ircomm_param_port_type(void *instance, irda_param_t *param, int get)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) instance;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return -1;);
if (get)
param->pv.i = IRCOMM_SERIAL;
else {
self->settings.port_type = (__u8) param->pv.i;
IRDA_DEBUG(0, "%s(), port type=%d\n", __func__ ,
self->settings.port_type);
}
return 0;
}
static int ircomm_param_port_name(void *instance, irda_param_t *param, int get)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) instance;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return -1;);
if (get) {
IRDA_DEBUG(0, "%s(), not imp!\n", __func__ );
} else {
IRDA_DEBUG(0, "%s(), port-name=%s\n", __func__ , param->pv.c);
strncpy(self->settings.port_name, param->pv.c, 32);
}
return 0;
}
static int ircomm_param_data_rate(void *instance, irda_param_t *param, int get)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) instance;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return -1;);
if (get)
param->pv.i = self->settings.data_rate;
else
self->settings.data_rate = param->pv.i;
IRDA_DEBUG(2, "%s(), data rate = %d\n", __func__ , param->pv.i);
return 0;
}
static int ircomm_param_data_format(void *instance, irda_param_t *param,
int get)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) instance;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return -1;);
if (get)
param->pv.i = self->settings.data_format;
else
self->settings.data_format = (__u8) param->pv.i;
return 0;
}
static int ircomm_param_flow_control(void *instance, irda_param_t *param,
int get)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) instance;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return -1;);
if (get)
param->pv.i = self->settings.flow_control;
else
self->settings.flow_control = (__u8) param->pv.i;
IRDA_DEBUG(1, "%s(), flow control = 0x%02x\n", __func__ , (__u8) param->pv.i);
return 0;
}
static int ircomm_param_xon_xoff(void *instance, irda_param_t *param, int get)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) instance;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return -1;);
if (get) {
param->pv.i = self->settings.xonxoff[0];
param->pv.i |= self->settings.xonxoff[1] << 8;
} else {
self->settings.xonxoff[0] = (__u16) param->pv.i & 0xff;
self->settings.xonxoff[1] = (__u16) param->pv.i >> 8;
}
IRDA_DEBUG(0, "%s(), XON/XOFF = 0x%02x,0x%02x\n", __func__ ,
param->pv.i & 0xff, param->pv.i >> 8);
return 0;
}
static int ircomm_param_enq_ack(void *instance, irda_param_t *param, int get)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) instance;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return -1;);
if (get) {
param->pv.i = self->settings.enqack[0];
param->pv.i |= self->settings.enqack[1] << 8;
} else {
self->settings.enqack[0] = (__u16) param->pv.i & 0xff;
self->settings.enqack[1] = (__u16) param->pv.i >> 8;
}
IRDA_DEBUG(0, "%s(), ENQ/ACK = 0x%02x,0x%02x\n", __func__ ,
param->pv.i & 0xff, param->pv.i >> 8);
return 0;
}
static int ircomm_param_line_status(void *instance, irda_param_t *param,
int get)
{
IRDA_DEBUG(2, "%s(), not impl.\n", __func__ );
return 0;
}
static int ircomm_param_dte(void *instance, irda_param_t *param, int get)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) instance;
__u8 dte;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return -1;);
if (get)
param->pv.i = self->settings.dte;
else {
dte = (__u8) param->pv.i;
self->settings.dce = 0;
if (dte & IRCOMM_DELTA_DTR)
self->settings.dce |= (IRCOMM_DELTA_DSR|
IRCOMM_DELTA_RI |
IRCOMM_DELTA_CD);
if (dte & IRCOMM_DTR)
self->settings.dce |= (IRCOMM_DSR|
IRCOMM_RI |
IRCOMM_CD);
if (dte & IRCOMM_DELTA_RTS)
self->settings.dce |= IRCOMM_DELTA_CTS;
if (dte & IRCOMM_RTS)
self->settings.dce |= IRCOMM_CTS;
ircomm_tty_check_modem_status(self);
self->settings.null_modem = TRUE;
}
return 0;
}
static int ircomm_param_dce(void *instance, irda_param_t *param, int get)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) instance;
__u8 dce;
IRDA_DEBUG(1, "%s(), dce = 0x%02x\n", __func__ , (__u8) param->pv.i);
dce = (__u8) param->pv.i;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return -1;);
self->settings.dce = dce;
if (dce & 0x0f) {
if (dce & IRCOMM_DELTA_CTS) {
IRDA_DEBUG(2, "%s(), CTS\n", __func__ );
}
}
ircomm_tty_check_modem_status(self);
return 0;
}
static int ircomm_param_poll(void *instance, irda_param_t *param, int get)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) instance;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return -1;);
if (!get) {
ircomm_param_request(self, IRCOMM_DTE, TRUE);
}
return 0;
}
