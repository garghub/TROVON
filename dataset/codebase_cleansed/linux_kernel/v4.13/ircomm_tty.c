static void ircomm_port_raise_dtr_rts(struct tty_port *port, int raise)
{
struct ircomm_tty_cb *self = container_of(port, struct ircomm_tty_cb,
port);
if (raise)
self->settings.dte |= IRCOMM_RTS | IRCOMM_DTR;
else
self->settings.dte &= ~(IRCOMM_RTS | IRCOMM_DTR);
ircomm_param_request(self, IRCOMM_DTE, TRUE);
}
static int ircomm_port_carrier_raised(struct tty_port *port)
{
struct ircomm_tty_cb *self = container_of(port, struct ircomm_tty_cb,
port);
return self->settings.dce & IRCOMM_CD;
}
static int __init ircomm_tty_init(void)
{
driver = alloc_tty_driver(IRCOMM_TTY_PORTS);
if (!driver)
return -ENOMEM;
ircomm_tty = hashbin_new(HB_LOCK);
if (ircomm_tty == NULL) {
net_err_ratelimited("%s(), can't allocate hashbin!\n",
__func__);
put_tty_driver(driver);
return -ENOMEM;
}
driver->driver_name = "ircomm";
driver->name = "ircomm";
driver->major = IRCOMM_TTY_MAJOR;
driver->minor_start = IRCOMM_TTY_MINOR;
driver->type = TTY_DRIVER_TYPE_SERIAL;
driver->subtype = SERIAL_TYPE_NORMAL;
driver->init_termios = tty_std_termios;
driver->init_termios.c_cflag = B9600 | CS8 | CREAD | HUPCL | CLOCAL;
driver->flags = TTY_DRIVER_REAL_RAW;
tty_set_operations(driver, &ops);
if (tty_register_driver(driver)) {
net_err_ratelimited("%s(): Couldn't register serial driver\n",
__func__);
put_tty_driver(driver);
return -1;
}
return 0;
}
static void __exit __ircomm_tty_cleanup(struct ircomm_tty_cb *self)
{
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return;);
ircomm_tty_shutdown(self);
self->magic = 0;
tty_port_destroy(&self->port);
kfree(self);
}
static void __exit ircomm_tty_cleanup(void)
{
int ret;
ret = tty_unregister_driver(driver);
if (ret) {
net_err_ratelimited("%s(), failed to unregister driver\n",
__func__);
return;
}
hashbin_delete(ircomm_tty, (FREE_FUNC) __ircomm_tty_cleanup);
put_tty_driver(driver);
}
static int ircomm_tty_startup(struct ircomm_tty_cb *self)
{
notify_t notify;
int ret = -ENODEV;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return -1;);
if (tty_port_initialized(&self->port)) {
pr_debug("%s(), already open so break out!\n", __func__);
return 0;
}
tty_port_set_initialized(&self->port, 1);
irda_notify_init(&notify);
notify.data_indication = ircomm_tty_data_indication;
notify.udata_indication = ircomm_tty_control_indication;
notify.flow_indication = ircomm_tty_flow_indication;
notify.disconnect_indication = ircomm_tty_disconnect_indication;
notify.connect_confirm = ircomm_tty_connect_confirm;
notify.connect_indication = ircomm_tty_connect_indication;
strlcpy(notify.name, "ircomm_tty", sizeof(notify.name));
notify.instance = self;
if (!self->ircomm) {
self->ircomm = ircomm_open(&notify, self->service_type,
self->line);
}
if (!self->ircomm)
goto err;
self->slsap_sel = self->ircomm->slsap_sel;
ret = ircomm_tty_attach_cable(self);
if (ret < 0) {
net_err_ratelimited("%s(), error attaching cable!\n", __func__);
goto err;
}
return 0;
err:
tty_port_set_initialized(&self->port, 0);
return ret;
}
static int ircomm_tty_block_til_ready(struct ircomm_tty_cb *self,
struct tty_struct *tty, struct file *filp)
{
struct tty_port *port = &self->port;
DECLARE_WAITQUEUE(wait, current);
int retval;
int do_clocal = 0;
unsigned long flags;
if (tty_io_error(tty)) {
tty_port_set_active(port, 1);
return 0;
}
if (filp->f_flags & O_NONBLOCK) {
if (C_BAUD(tty))
tty_port_raise_dtr_rts(port);
tty_port_set_active(port, 1);
pr_debug("%s(), O_NONBLOCK requested!\n", __func__);
return 0;
}
if (C_CLOCAL(tty)) {
pr_debug("%s(), doing CLOCAL!\n", __func__);
do_clocal = 1;
}
retval = 0;
add_wait_queue(&port->open_wait, &wait);
pr_debug("%s(%d):block_til_ready before block on %s open_count=%d\n",
__FILE__, __LINE__, tty->driver->name, port->count);
spin_lock_irqsave(&port->lock, flags);
port->count--;
port->blocked_open++;
spin_unlock_irqrestore(&port->lock, flags);
while (1) {
if (C_BAUD(tty) && tty_port_initialized(port))
tty_port_raise_dtr_rts(port);
set_current_state(TASK_INTERRUPTIBLE);
if (tty_hung_up_p(filp) || !tty_port_initialized(port)) {
retval = (port->flags & ASYNC_HUP_NOTIFY) ?
-EAGAIN : -ERESTARTSYS;
break;
}
if ((do_clocal || tty_port_carrier_raised(port)) &&
self->state == IRCOMM_TTY_READY)
{
break;
}
if (signal_pending(current)) {
retval = -ERESTARTSYS;
break;
}
pr_debug("%s(%d):block_til_ready blocking on %s open_count=%d\n",
__FILE__, __LINE__, tty->driver->name, port->count);
schedule();
}
__set_current_state(TASK_RUNNING);
remove_wait_queue(&port->open_wait, &wait);
spin_lock_irqsave(&port->lock, flags);
if (!tty_hung_up_p(filp))
port->count++;
port->blocked_open--;
spin_unlock_irqrestore(&port->lock, flags);
pr_debug("%s(%d):block_til_ready after blocking on %s open_count=%d\n",
__FILE__, __LINE__, tty->driver->name, port->count);
if (!retval)
tty_port_set_active(port, 1);
return retval;
}
static int ircomm_tty_install(struct tty_driver *driver, struct tty_struct *tty)
{
struct ircomm_tty_cb *self;
unsigned int line = tty->index;
self = hashbin_lock_find(ircomm_tty, line, NULL);
if (!self) {
self = kzalloc(sizeof(struct ircomm_tty_cb), GFP_KERNEL);
if (self == NULL)
return -ENOMEM;
tty_port_init(&self->port);
self->port.ops = &ircomm_port_ops;
self->magic = IRCOMM_TTY_MAGIC;
self->flow = FLOW_STOP;
self->line = line;
INIT_WORK(&self->tqueue, ircomm_tty_do_softint);
self->max_header_size = IRCOMM_TTY_HDR_UNINITIALISED;
self->max_data_size = IRCOMM_TTY_DATA_UNINITIALISED;
init_timer(&self->watchdog_timer);
spin_lock_init(&self->spinlock);
tty->termios.c_iflag = 0;
tty->termios.c_oflag = 0;
hashbin_insert(ircomm_tty, (irda_queue_t *) self, line, NULL);
}
tty->driver_data = self;
return tty_port_install(&self->port, driver, tty);
}
static int ircomm_tty_open(struct tty_struct *tty, struct file *filp)
{
struct ircomm_tty_cb *self = tty->driver_data;
unsigned long flags;
int ret;
spin_lock_irqsave(&self->port.lock, flags);
self->port.count++;
spin_unlock_irqrestore(&self->port.lock, flags);
tty_port_tty_set(&self->port, tty);
pr_debug("%s(), %s%d, count = %d\n", __func__ , tty->driver->name,
self->line, self->port.count);
self->port.low_latency = (self->port.flags & ASYNC_LOW_LATENCY) ? 1 : 0;
if (self->line < 0x10) {
self->service_type = IRCOMM_3_WIRE | IRCOMM_9_WIRE;
self->settings.service_type = IRCOMM_9_WIRE;
self->settings.dce = IRCOMM_CTS | IRCOMM_CD | IRCOMM_DSR | IRCOMM_RI;
pr_debug("%s(), IrCOMM device\n", __func__);
} else {
pr_debug("%s(), IrLPT device\n", __func__);
self->service_type = IRCOMM_3_WIRE_RAW;
self->settings.service_type = IRCOMM_3_WIRE_RAW;
}
ret = ircomm_tty_startup(self);
if (ret)
return ret;
ret = ircomm_tty_block_til_ready(self, tty, filp);
if (ret) {
pr_debug("%s(), returning after block_til_ready with %d\n",
__func__, ret);
return ret;
}
return 0;
}
static void ircomm_tty_close(struct tty_struct *tty, struct file *filp)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) tty->driver_data;
struct tty_port *port = &self->port;
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return;);
if (tty_port_close_start(port, tty, filp) == 0)
return;
ircomm_tty_shutdown(self);
tty_driver_flush_buffer(tty);
tty_port_close_end(port, tty);
tty_port_tty_set(port, NULL);
}
static void ircomm_tty_flush_buffer(struct tty_struct *tty)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) tty->driver_data;
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return;);
schedule_work(&self->tqueue);
}
static void ircomm_tty_do_softint(struct work_struct *work)
{
struct ircomm_tty_cb *self =
container_of(work, struct ircomm_tty_cb, tqueue);
struct tty_struct *tty;
unsigned long flags;
struct sk_buff *skb, *ctrl_skb;
if (!self || self->magic != IRCOMM_TTY_MAGIC)
return;
tty = tty_port_tty_get(&self->port);
if (!tty)
return;
spin_lock_irqsave(&self->spinlock, flags);
ctrl_skb = self->ctrl_skb;
self->ctrl_skb = NULL;
spin_unlock_irqrestore(&self->spinlock, flags);
if(ctrl_skb) {
if(self->flow == FLOW_START)
ircomm_control_request(self->ircomm, ctrl_skb);
dev_kfree_skb(ctrl_skb);
}
if (tty->hw_stopped)
goto put;
spin_lock_irqsave(&self->spinlock, flags);
skb = self->tx_skb;
self->tx_skb = NULL;
spin_unlock_irqrestore(&self->spinlock, flags);
if (skb) {
ircomm_tty_do_event(self, IRCOMM_TTY_DATA_REQUEST, skb, NULL);
dev_kfree_skb(skb);
}
tty_wakeup(tty);
put:
tty_kref_put(tty);
}
static int ircomm_tty_write(struct tty_struct *tty,
const unsigned char *buf, int count)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) tty->driver_data;
unsigned long flags;
struct sk_buff *skb;
int tailroom = 0;
int len = 0;
int size;
pr_debug("%s(), count=%d, hw_stopped=%d\n", __func__ , count,
tty->hw_stopped);
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return -1;);
if (self->max_header_size == IRCOMM_TTY_HDR_UNINITIALISED) {
pr_debug("%s() : not initialised\n", __func__);
#ifdef IRCOMM_NO_TX_BEFORE_INIT
return 0;
#endif
}
if (count < 1)
return 0;
spin_lock_irqsave(&self->spinlock, flags);
skb = self->tx_skb;
while (count) {
size = count;
if (size > self->max_data_size)
size = self->max_data_size;
if (skb) {
if ((tailroom = (self->tx_data_size - skb->len)) > 0) {
if (size > tailroom)
size = tailroom;
} else {
break;
}
} else {
skb = alloc_skb(self->max_data_size+
self->max_header_size,
GFP_ATOMIC);
if (!skb) {
spin_unlock_irqrestore(&self->spinlock, flags);
return -ENOBUFS;
}
skb_reserve(skb, self->max_header_size);
self->tx_skb = skb;
self->tx_data_size = self->max_data_size;
}
skb_put_data(skb, buf + len, size);
count -= size;
len += size;
}
spin_unlock_irqrestore(&self->spinlock, flags);
schedule_work(&self->tqueue);
return len;
}
static int ircomm_tty_write_room(struct tty_struct *tty)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) tty->driver_data;
unsigned long flags;
int ret;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return -1;);
#ifdef IRCOMM_NO_TX_BEFORE_INIT
if (self->max_header_size == IRCOMM_TTY_HDR_UNINITIALISED)
return 0;
#endif
if (tty->hw_stopped)
ret = 0;
else {
spin_lock_irqsave(&self->spinlock, flags);
if (self->tx_skb)
ret = self->tx_data_size - self->tx_skb->len;
else
ret = self->max_data_size;
spin_unlock_irqrestore(&self->spinlock, flags);
}
pr_debug("%s(), ret=%d\n", __func__ , ret);
return ret;
}
static void ircomm_tty_wait_until_sent(struct tty_struct *tty, int timeout)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) tty->driver_data;
unsigned long orig_jiffies, poll_time;
unsigned long flags;
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return;);
orig_jiffies = jiffies;
poll_time = msecs_to_jiffies(200);
if (timeout)
poll_time = min_t(unsigned long, timeout, poll_time);
spin_lock_irqsave(&self->spinlock, flags);
while (self->tx_skb && self->tx_skb->len) {
spin_unlock_irqrestore(&self->spinlock, flags);
schedule_timeout_interruptible(poll_time);
spin_lock_irqsave(&self->spinlock, flags);
if (signal_pending(current))
break;
if (timeout && time_after(jiffies, orig_jiffies + timeout))
break;
}
spin_unlock_irqrestore(&self->spinlock, flags);
__set_current_state(TASK_RUNNING);
}
static void ircomm_tty_throttle(struct tty_struct *tty)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) tty->driver_data;
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return;);
if (I_IXOFF(tty))
ircomm_tty_send_xchar(tty, STOP_CHAR(tty));
if (C_CRTSCTS(tty)) {
self->settings.dte &= ~IRCOMM_RTS;
self->settings.dte |= IRCOMM_DELTA_RTS;
ircomm_param_request(self, IRCOMM_DTE, TRUE);
}
ircomm_flow_request(self->ircomm, FLOW_STOP);
}
static void ircomm_tty_unthrottle(struct tty_struct *tty)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) tty->driver_data;
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return;);
if (I_IXOFF(tty))
ircomm_tty_send_xchar(tty, START_CHAR(tty));
if (C_CRTSCTS(tty)) {
self->settings.dte |= (IRCOMM_RTS|IRCOMM_DELTA_RTS);
ircomm_param_request(self, IRCOMM_DTE, TRUE);
pr_debug("%s(), FLOW_START\n", __func__);
}
ircomm_flow_request(self->ircomm, FLOW_START);
}
static int ircomm_tty_chars_in_buffer(struct tty_struct *tty)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) tty->driver_data;
unsigned long flags;
int len = 0;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return -1;);
spin_lock_irqsave(&self->spinlock, flags);
if (self->tx_skb)
len = self->tx_skb->len;
spin_unlock_irqrestore(&self->spinlock, flags);
return len;
}
static void ircomm_tty_shutdown(struct ircomm_tty_cb *self)
{
unsigned long flags;
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return;);
if (!tty_port_initialized(&self->port))
return;
tty_port_set_initialized(&self->port, 0);
ircomm_tty_detach_cable(self);
spin_lock_irqsave(&self->spinlock, flags);
del_timer(&self->watchdog_timer);
if (self->ctrl_skb) {
dev_kfree_skb(self->ctrl_skb);
self->ctrl_skb = NULL;
}
if (self->tx_skb) {
dev_kfree_skb(self->tx_skb);
self->tx_skb = NULL;
}
if (self->ircomm) {
ircomm_close(self->ircomm);
self->ircomm = NULL;
}
spin_unlock_irqrestore(&self->spinlock, flags);
}
static void ircomm_tty_hangup(struct tty_struct *tty)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) tty->driver_data;
struct tty_port *port = &self->port;
unsigned long flags;
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return;);
ircomm_tty_shutdown(self);
spin_lock_irqsave(&port->lock, flags);
if (port->tty) {
set_bit(TTY_IO_ERROR, &port->tty->flags);
tty_kref_put(port->tty);
}
port->tty = NULL;
port->count = 0;
spin_unlock_irqrestore(&port->lock, flags);
tty_port_set_active(port, 0);
wake_up_interruptible(&port->open_wait);
}
static void ircomm_tty_send_xchar(struct tty_struct *tty, char ch)
{
pr_debug("%s(), not impl\n", __func__);
}
void ircomm_tty_start(struct tty_struct *tty)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) tty->driver_data;
ircomm_flow_request(self->ircomm, FLOW_START);
}
static void ircomm_tty_stop(struct tty_struct *tty)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) tty->driver_data;
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return;);
ircomm_flow_request(self->ircomm, FLOW_STOP);
}
void ircomm_tty_check_modem_status(struct ircomm_tty_cb *self)
{
struct tty_struct *tty;
int status;
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return;);
tty = tty_port_tty_get(&self->port);
status = self->settings.dce;
if (status & IRCOMM_DCE_DELTA_ANY) {
}
if (tty_port_check_carrier(&self->port) && (status & IRCOMM_DELTA_CD)) {
pr_debug("%s(), ircomm%d CD now %s...\n", __func__ , self->line,
(status & IRCOMM_CD) ? "on" : "off");
if (status & IRCOMM_CD) {
wake_up_interruptible(&self->port.open_wait);
} else {
pr_debug("%s(), Doing serial hangup..\n", __func__);
if (tty)
tty_hangup(tty);
goto put;
}
}
if (tty && tty_port_cts_enabled(&self->port)) {
if (tty->hw_stopped) {
if (status & IRCOMM_CTS) {
pr_debug("%s(), CTS tx start...\n", __func__);
tty->hw_stopped = 0;
wake_up_interruptible(&self->port.open_wait);
schedule_work(&self->tqueue);
goto put;
}
} else {
if (!(status & IRCOMM_CTS)) {
pr_debug("%s(), CTS tx stop...\n", __func__);
tty->hw_stopped = 1;
}
}
}
put:
tty_kref_put(tty);
}
static int ircomm_tty_data_indication(void *instance, void *sap,
struct sk_buff *skb)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) instance;
struct tty_struct *tty;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return -1;);
IRDA_ASSERT(skb != NULL, return -1;);
tty = tty_port_tty_get(&self->port);
if (!tty) {
pr_debug("%s(), no tty!\n", __func__);
return 0;
}
if (tty->hw_stopped && (self->flow == FLOW_START)) {
pr_debug("%s(), polling for line settings!\n", __func__);
ircomm_param_request(self, IRCOMM_POLL, TRUE);
ircomm_tty_send_initial_parameters(self);
ircomm_tty_link_established(self);
}
tty_kref_put(tty);
tty_insert_flip_string(&self->port, skb->data, skb->len);
tty_flip_buffer_push(&self->port);
return 0;
}
static int ircomm_tty_control_indication(void *instance, void *sap,
struct sk_buff *skb)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) instance;
int clen;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return -1;);
IRDA_ASSERT(skb != NULL, return -1;);
clen = skb->data[0];
irda_param_extract_all(self, skb->data+1, IRDA_MIN(skb->len-1, clen),
&ircomm_param_info);
return 0;
}
static void ircomm_tty_flow_indication(void *instance, void *sap,
LOCAL_FLOW cmd)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) instance;
struct tty_struct *tty;
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return;);
tty = tty_port_tty_get(&self->port);
switch (cmd) {
case FLOW_START:
pr_debug("%s(), hw start!\n", __func__);
if (tty)
tty->hw_stopped = 0;
schedule_work(&self->tqueue);
break;
default:
case FLOW_STOP:
pr_debug("%s(), hw stopped!\n", __func__);
if (tty)
tty->hw_stopped = 1;
break;
}
tty_kref_put(tty);
self->flow = cmd;
}
static void ircomm_tty_line_info(struct ircomm_tty_cb *self, struct seq_file *m)
{
struct tty_struct *tty;
char sep;
seq_printf(m, "State: %s\n", ircomm_tty_state[self->state]);
seq_puts(m, "Service type: ");
if (self->service_type & IRCOMM_9_WIRE)
seq_puts(m, "9_WIRE");
else if (self->service_type & IRCOMM_3_WIRE)
seq_puts(m, "3_WIRE");
else if (self->service_type & IRCOMM_3_WIRE_RAW)
seq_puts(m, "3_WIRE_RAW");
else
seq_puts(m, "No common service type!\n");
seq_putc(m, '\n');
seq_printf(m, "Port name: %s\n", self->settings.port_name);
seq_printf(m, "DTE status:");
sep = ' ';
if (self->settings.dte & IRCOMM_RTS) {
seq_printf(m, "%cRTS", sep);
sep = '|';
}
if (self->settings.dte & IRCOMM_DTR) {
seq_printf(m, "%cDTR", sep);
sep = '|';
}
seq_putc(m, '\n');
seq_puts(m, "DCE status:");
sep = ' ';
if (self->settings.dce & IRCOMM_CTS) {
seq_printf(m, "%cCTS", sep);
sep = '|';
}
if (self->settings.dce & IRCOMM_DSR) {
seq_printf(m, "%cDSR", sep);
sep = '|';
}
if (self->settings.dce & IRCOMM_CD) {
seq_printf(m, "%cCD", sep);
sep = '|';
}
if (self->settings.dce & IRCOMM_RI) {
seq_printf(m, "%cRI", sep);
sep = '|';
}
seq_putc(m, '\n');
seq_puts(m, "Configuration: ");
if (!self->settings.null_modem)
seq_puts(m, "DTE <-> DCE\n");
else
seq_puts(m, "DTE <-> DTE (null modem emulation)\n");
seq_printf(m, "Data rate: %d\n", self->settings.data_rate);
seq_puts(m, "Flow control:");
sep = ' ';
if (self->settings.flow_control & IRCOMM_XON_XOFF_IN) {
seq_printf(m, "%cXON_XOFF_IN", sep);
sep = '|';
}
if (self->settings.flow_control & IRCOMM_XON_XOFF_OUT) {
seq_printf(m, "%cXON_XOFF_OUT", sep);
sep = '|';
}
if (self->settings.flow_control & IRCOMM_RTS_CTS_IN) {
seq_printf(m, "%cRTS_CTS_IN", sep);
sep = '|';
}
if (self->settings.flow_control & IRCOMM_RTS_CTS_OUT) {
seq_printf(m, "%cRTS_CTS_OUT", sep);
sep = '|';
}
if (self->settings.flow_control & IRCOMM_DSR_DTR_IN) {
seq_printf(m, "%cDSR_DTR_IN", sep);
sep = '|';
}
if (self->settings.flow_control & IRCOMM_DSR_DTR_OUT) {
seq_printf(m, "%cDSR_DTR_OUT", sep);
sep = '|';
}
if (self->settings.flow_control & IRCOMM_ENQ_ACK_IN) {
seq_printf(m, "%cENQ_ACK_IN", sep);
sep = '|';
}
if (self->settings.flow_control & IRCOMM_ENQ_ACK_OUT) {
seq_printf(m, "%cENQ_ACK_OUT", sep);
sep = '|';
}
seq_putc(m, '\n');
seq_puts(m, "Flags:");
sep = ' ';
if (tty_port_cts_enabled(&self->port)) {
seq_printf(m, "%cASYNC_CTS_FLOW", sep);
sep = '|';
}
if (tty_port_check_carrier(&self->port)) {
seq_printf(m, "%cASYNC_CHECK_CD", sep);
sep = '|';
}
if (tty_port_initialized(&self->port)) {
seq_printf(m, "%cASYNC_INITIALIZED", sep);
sep = '|';
}
if (self->port.flags & ASYNC_LOW_LATENCY) {
seq_printf(m, "%cASYNC_LOW_LATENCY", sep);
sep = '|';
}
if (tty_port_active(&self->port)) {
seq_printf(m, "%cASYNC_NORMAL_ACTIVE", sep);
sep = '|';
}
seq_putc(m, '\n');
seq_printf(m, "Role: %s\n", self->client ? "client" : "server");
seq_printf(m, "Open count: %d\n", self->port.count);
seq_printf(m, "Max data size: %d\n", self->max_data_size);
seq_printf(m, "Max header size: %d\n", self->max_header_size);
tty = tty_port_tty_get(&self->port);
if (tty) {
seq_printf(m, "Hardware: %s\n",
tty->hw_stopped ? "Stopped" : "Running");
tty_kref_put(tty);
}
}
static int ircomm_tty_proc_show(struct seq_file *m, void *v)
{
struct ircomm_tty_cb *self;
unsigned long flags;
spin_lock_irqsave(&ircomm_tty->hb_spinlock, flags);
self = (struct ircomm_tty_cb *) hashbin_get_first(ircomm_tty);
while (self != NULL) {
if (self->magic != IRCOMM_TTY_MAGIC)
break;
ircomm_tty_line_info(self, m);
self = (struct ircomm_tty_cb *) hashbin_get_next(ircomm_tty);
}
spin_unlock_irqrestore(&ircomm_tty->hb_spinlock, flags);
return 0;
}
static int ircomm_tty_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, ircomm_tty_proc_show, NULL);
}
