static int gs_buf_alloc(struct gs_buf *gb, unsigned size)
{
gb->buf_buf = kmalloc(size, GFP_KERNEL);
if (gb->buf_buf == NULL)
return -ENOMEM;
gb->buf_size = size;
gb->buf_put = gb->buf_buf;
gb->buf_get = gb->buf_buf;
return 0;
}
static void gs_buf_free(struct gs_buf *gb)
{
kfree(gb->buf_buf);
gb->buf_buf = NULL;
}
static void gs_buf_clear(struct gs_buf *gb)
{
gb->buf_get = gb->buf_put;
}
static unsigned gs_buf_data_avail(struct gs_buf *gb)
{
return (gb->buf_size + gb->buf_put - gb->buf_get) % gb->buf_size;
}
static unsigned gs_buf_space_avail(struct gs_buf *gb)
{
return (gb->buf_size + gb->buf_get - gb->buf_put - 1) % gb->buf_size;
}
static unsigned
gs_buf_put(struct gs_buf *gb, const char *buf, unsigned count)
{
unsigned len;
len = gs_buf_space_avail(gb);
if (count > len)
count = len;
if (count == 0)
return 0;
len = gb->buf_buf + gb->buf_size - gb->buf_put;
if (count > len) {
memcpy(gb->buf_put, buf, len);
memcpy(gb->buf_buf, buf+len, count - len);
gb->buf_put = gb->buf_buf + count - len;
} else {
memcpy(gb->buf_put, buf, count);
if (count < len)
gb->buf_put += count;
else
gb->buf_put = gb->buf_buf;
}
return count;
}
static unsigned
gs_buf_get(struct gs_buf *gb, char *buf, unsigned count)
{
unsigned len;
len = gs_buf_data_avail(gb);
if (count > len)
count = len;
if (count == 0)
return 0;
len = gb->buf_buf + gb->buf_size - gb->buf_get;
if (count > len) {
memcpy(buf, gb->buf_get, len);
memcpy(buf+len, gb->buf_buf, count - len);
gb->buf_get = gb->buf_buf + count - len;
} else {
memcpy(buf, gb->buf_get, count);
if (count < len)
gb->buf_get += count;
else
gb->buf_get = gb->buf_buf;
}
return count;
}
struct usb_request *
gs_alloc_req(struct usb_ep *ep, unsigned len, gfp_t kmalloc_flags)
{
struct usb_request *req;
req = usb_ep_alloc_request(ep, kmalloc_flags);
if (req != NULL) {
req->length = len;
req->buf = kmalloc(len, kmalloc_flags);
if (req->buf == NULL) {
usb_ep_free_request(ep, req);
return NULL;
}
}
return req;
}
void gs_free_req(struct usb_ep *ep, struct usb_request *req)
{
kfree(req->buf);
usb_ep_free_request(ep, req);
}
static unsigned
gs_send_packet(struct gs_port *port, char *packet, unsigned size)
{
unsigned len;
len = gs_buf_data_avail(&port->port_write_buf);
if (len < size)
size = len;
if (size != 0)
size = gs_buf_get(&port->port_write_buf, packet, size);
return size;
}
static int gs_start_tx(struct gs_port *port)
{
struct list_head *pool = &port->write_pool;
struct usb_ep *in = port->port_usb->in;
int status = 0;
bool do_tty_wake = false;
while (!port->write_busy && !list_empty(pool)) {
struct usb_request *req;
int len;
if (port->write_started >= QUEUE_SIZE)
break;
req = list_entry(pool->next, struct usb_request, list);
len = gs_send_packet(port, req->buf, in->maxpacket);
if (len == 0) {
wake_up_interruptible(&port->drain_wait);
break;
}
do_tty_wake = true;
req->length = len;
list_del(&req->list);
req->zero = (gs_buf_data_avail(&port->port_write_buf) == 0);
pr_vdebug("ttyGS%d: tx len=%d, 0x%02x 0x%02x 0x%02x ...\n",
port->port_num, len, *((u8 *)req->buf),
*((u8 *)req->buf+1), *((u8 *)req->buf+2));
port->write_busy = true;
spin_unlock(&port->port_lock);
status = usb_ep_queue(in, req, GFP_ATOMIC);
spin_lock(&port->port_lock);
port->write_busy = false;
if (status) {
pr_debug("%s: %s %s err %d\n",
__func__, "queue", in->name, status);
list_add(&req->list, pool);
break;
}
port->write_started++;
if (!port->port_usb)
break;
}
if (do_tty_wake && port->port.tty)
tty_wakeup(port->port.tty);
return status;
}
static unsigned gs_start_rx(struct gs_port *port)
{
struct list_head *pool = &port->read_pool;
struct usb_ep *out = port->port_usb->out;
while (!list_empty(pool)) {
struct usb_request *req;
int status;
struct tty_struct *tty;
tty = port->port.tty;
if (!tty)
break;
if (port->read_started >= QUEUE_SIZE)
break;
req = list_entry(pool->next, struct usb_request, list);
list_del(&req->list);
req->length = out->maxpacket;
spin_unlock(&port->port_lock);
status = usb_ep_queue(out, req, GFP_ATOMIC);
spin_lock(&port->port_lock);
if (status) {
pr_debug("%s: %s %s err %d\n",
__func__, "queue", out->name, status);
list_add(&req->list, pool);
break;
}
port->read_started++;
if (!port->port_usb)
break;
}
return port->read_started;
}
static void gs_rx_push(unsigned long _port)
{
struct gs_port *port = (void *)_port;
struct tty_struct *tty;
struct list_head *queue = &port->read_queue;
bool disconnect = false;
bool do_push = false;
spin_lock_irq(&port->port_lock);
tty = port->port.tty;
while (!list_empty(queue)) {
struct usb_request *req;
req = list_first_entry(queue, struct usb_request, list);
if (tty && tty_throttled(tty))
break;
switch (req->status) {
case -ESHUTDOWN:
disconnect = true;
pr_vdebug("ttyGS%d: shutdown\n", port->port_num);
break;
default:
pr_warn("ttyGS%d: unexpected RX status %d\n",
port->port_num, req->status);
case 0:
break;
}
if (req->actual) {
char *packet = req->buf;
unsigned size = req->actual;
unsigned n;
int count;
n = port->n_read;
if (n) {
packet += n;
size -= n;
}
count = tty_insert_flip_string(&port->port, packet,
size);
if (count)
do_push = true;
if (count != size) {
port->n_read += count;
pr_vdebug("ttyGS%d: rx block %d/%d\n",
port->port_num, count, req->actual);
break;
}
port->n_read = 0;
}
list_move(&req->list, &port->read_pool);
port->read_started--;
}
if (do_push)
tty_flip_buffer_push(&port->port);
if (!list_empty(queue) && tty) {
if (!tty_throttled(tty)) {
if (do_push)
tasklet_schedule(&port->push);
else
pr_warn("ttyGS%d: RX not scheduled?\n",
port->port_num);
}
}
if (!disconnect && port->port_usb)
gs_start_rx(port);
spin_unlock_irq(&port->port_lock);
}
static void gs_read_complete(struct usb_ep *ep, struct usb_request *req)
{
struct gs_port *port = ep->driver_data;
spin_lock(&port->port_lock);
list_add_tail(&req->list, &port->read_queue);
tasklet_schedule(&port->push);
spin_unlock(&port->port_lock);
}
static void gs_write_complete(struct usb_ep *ep, struct usb_request *req)
{
struct gs_port *port = ep->driver_data;
spin_lock(&port->port_lock);
list_add(&req->list, &port->write_pool);
port->write_started--;
switch (req->status) {
default:
pr_warning("%s: unexpected %s status %d\n",
__func__, ep->name, req->status);
case 0:
gs_start_tx(port);
break;
case -ESHUTDOWN:
pr_vdebug("%s: %s shutdown\n", __func__, ep->name);
break;
}
spin_unlock(&port->port_lock);
}
static void gs_free_requests(struct usb_ep *ep, struct list_head *head,
int *allocated)
{
struct usb_request *req;
while (!list_empty(head)) {
req = list_entry(head->next, struct usb_request, list);
list_del(&req->list);
gs_free_req(ep, req);
if (allocated)
(*allocated)--;
}
}
static int gs_alloc_requests(struct usb_ep *ep, struct list_head *head,
void (*fn)(struct usb_ep *, struct usb_request *),
int *allocated)
{
int i;
struct usb_request *req;
int n = allocated ? QUEUE_SIZE - *allocated : QUEUE_SIZE;
for (i = 0; i < n; i++) {
req = gs_alloc_req(ep, ep->maxpacket, GFP_ATOMIC);
if (!req)
return list_empty(head) ? -ENOMEM : 0;
req->complete = fn;
list_add_tail(&req->list, head);
if (allocated)
(*allocated)++;
}
return 0;
}
static int gs_start_io(struct gs_port *port)
{
struct list_head *head = &port->read_pool;
struct usb_ep *ep = port->port_usb->out;
int status;
unsigned started;
status = gs_alloc_requests(ep, head, gs_read_complete,
&port->read_allocated);
if (status)
return status;
status = gs_alloc_requests(port->port_usb->in, &port->write_pool,
gs_write_complete, &port->write_allocated);
if (status) {
gs_free_requests(ep, head, &port->read_allocated);
return status;
}
port->n_read = 0;
started = gs_start_rx(port);
if (started) {
tty_wakeup(port->port.tty);
} else {
gs_free_requests(ep, head, &port->read_allocated);
gs_free_requests(port->port_usb->in, &port->write_pool,
&port->write_allocated);
status = -EIO;
}
return status;
}
static int gs_open(struct tty_struct *tty, struct file *file)
{
int port_num = tty->index;
struct gs_port *port;
int status;
do {
mutex_lock(&ports[port_num].lock);
port = ports[port_num].port;
if (!port)
status = -ENODEV;
else {
spin_lock_irq(&port->port_lock);
if (port->port.count) {
status = 0;
port->port.count++;
} else if (port->openclose) {
status = -EBUSY;
} else {
status = -EAGAIN;
port->openclose = true;
}
spin_unlock_irq(&port->port_lock);
}
mutex_unlock(&ports[port_num].lock);
switch (status) {
default:
return status;
case -EAGAIN:
break;
case -EBUSY:
msleep(1);
break;
}
} while (status != -EAGAIN);
spin_lock_irq(&port->port_lock);
if (port->port_write_buf.buf_buf == NULL) {
spin_unlock_irq(&port->port_lock);
status = gs_buf_alloc(&port->port_write_buf, WRITE_BUF_SIZE);
spin_lock_irq(&port->port_lock);
if (status) {
pr_debug("gs_open: ttyGS%d (%p,%p) no buffer\n",
port->port_num, tty, file);
port->openclose = false;
goto exit_unlock_port;
}
}
tty->driver_data = port;
port->port.tty = tty;
port->port.count = 1;
port->openclose = false;
if (port->port_usb) {
struct gserial *gser = port->port_usb;
pr_debug("gs_open: start ttyGS%d\n", port->port_num);
gs_start_io(port);
if (gser->connect)
gser->connect(gser);
}
pr_debug("gs_open: ttyGS%d (%p,%p)\n", port->port_num, tty, file);
status = 0;
exit_unlock_port:
spin_unlock_irq(&port->port_lock);
return status;
}
static int gs_writes_finished(struct gs_port *p)
{
int cond;
spin_lock_irq(&p->port_lock);
cond = (p->port_usb == NULL) || !gs_buf_data_avail(&p->port_write_buf);
spin_unlock_irq(&p->port_lock);
return cond;
}
static void gs_close(struct tty_struct *tty, struct file *file)
{
struct gs_port *port = tty->driver_data;
struct gserial *gser;
spin_lock_irq(&port->port_lock);
if (port->port.count != 1) {
if (port->port.count == 0)
WARN_ON(1);
else
--port->port.count;
goto exit;
}
pr_debug("gs_close: ttyGS%d (%p,%p) ...\n", port->port_num, tty, file);
port->openclose = true;
port->port.count = 0;
gser = port->port_usb;
if (gser && gser->disconnect)
gser->disconnect(gser);
if (gs_buf_data_avail(&port->port_write_buf) > 0 && gser) {
spin_unlock_irq(&port->port_lock);
wait_event_interruptible_timeout(port->drain_wait,
gs_writes_finished(port),
GS_CLOSE_TIMEOUT * HZ);
spin_lock_irq(&port->port_lock);
gser = port->port_usb;
}
if (gser == NULL)
gs_buf_free(&port->port_write_buf);
else
gs_buf_clear(&port->port_write_buf);
port->port.tty = NULL;
port->openclose = false;
pr_debug("gs_close: ttyGS%d (%p,%p) done!\n",
port->port_num, tty, file);
wake_up(&port->close_wait);
exit:
spin_unlock_irq(&port->port_lock);
}
static int gs_write(struct tty_struct *tty, const unsigned char *buf, int count)
{
struct gs_port *port = tty->driver_data;
unsigned long flags;
int status;
pr_vdebug("gs_write: ttyGS%d (%p) writing %d bytes\n",
port->port_num, tty, count);
spin_lock_irqsave(&port->port_lock, flags);
if (count)
count = gs_buf_put(&port->port_write_buf, buf, count);
if (port->port_usb)
status = gs_start_tx(port);
spin_unlock_irqrestore(&port->port_lock, flags);
return count;
}
static int gs_put_char(struct tty_struct *tty, unsigned char ch)
{
struct gs_port *port = tty->driver_data;
unsigned long flags;
int status;
pr_vdebug("gs_put_char: (%d,%p) char=0x%x, called from %ps\n",
port->port_num, tty, ch, __builtin_return_address(0));
spin_lock_irqsave(&port->port_lock, flags);
status = gs_buf_put(&port->port_write_buf, &ch, 1);
spin_unlock_irqrestore(&port->port_lock, flags);
return status;
}
static void gs_flush_chars(struct tty_struct *tty)
{
struct gs_port *port = tty->driver_data;
unsigned long flags;
pr_vdebug("gs_flush_chars: (%d,%p)\n", port->port_num, tty);
spin_lock_irqsave(&port->port_lock, flags);
if (port->port_usb)
gs_start_tx(port);
spin_unlock_irqrestore(&port->port_lock, flags);
}
static int gs_write_room(struct tty_struct *tty)
{
struct gs_port *port = tty->driver_data;
unsigned long flags;
int room = 0;
spin_lock_irqsave(&port->port_lock, flags);
if (port->port_usb)
room = gs_buf_space_avail(&port->port_write_buf);
spin_unlock_irqrestore(&port->port_lock, flags);
pr_vdebug("gs_write_room: (%d,%p) room=%d\n",
port->port_num, tty, room);
return room;
}
static int gs_chars_in_buffer(struct tty_struct *tty)
{
struct gs_port *port = tty->driver_data;
unsigned long flags;
int chars = 0;
spin_lock_irqsave(&port->port_lock, flags);
chars = gs_buf_data_avail(&port->port_write_buf);
spin_unlock_irqrestore(&port->port_lock, flags);
pr_vdebug("gs_chars_in_buffer: (%d,%p) chars=%d\n",
port->port_num, tty, chars);
return chars;
}
static void gs_unthrottle(struct tty_struct *tty)
{
struct gs_port *port = tty->driver_data;
unsigned long flags;
spin_lock_irqsave(&port->port_lock, flags);
if (port->port_usb) {
tasklet_schedule(&port->push);
pr_vdebug("ttyGS%d: unthrottle\n", port->port_num);
}
spin_unlock_irqrestore(&port->port_lock, flags);
}
static int gs_break_ctl(struct tty_struct *tty, int duration)
{
struct gs_port *port = tty->driver_data;
int status = 0;
struct gserial *gser;
pr_vdebug("gs_break_ctl: ttyGS%d, send break (%d) \n",
port->port_num, duration);
spin_lock_irq(&port->port_lock);
gser = port->port_usb;
if (gser && gser->send_break)
status = gser->send_break(gser, duration);
spin_unlock_irq(&port->port_lock);
return status;
}
static struct usb_request *gs_request_new(struct usb_ep *ep)
{
struct usb_request *req = usb_ep_alloc_request(ep, GFP_ATOMIC);
if (!req)
return NULL;
req->buf = kmalloc(ep->maxpacket, GFP_ATOMIC);
if (!req->buf) {
usb_ep_free_request(ep, req);
return NULL;
}
return req;
}
static void gs_request_free(struct usb_request *req, struct usb_ep *ep)
{
if (!req)
return;
kfree(req->buf);
usb_ep_free_request(ep, req);
}
static void gs_complete_out(struct usb_ep *ep, struct usb_request *req)
{
struct gscons_info *info = &gscons_info;
switch (req->status) {
default:
pr_warn("%s: unexpected %s status %d\n",
__func__, ep->name, req->status);
case 0:
spin_lock(&info->con_lock);
info->req_busy = 0;
spin_unlock(&info->con_lock);
wake_up_process(info->console_thread);
break;
case -ESHUTDOWN:
pr_vdebug("%s: %s shutdown\n", __func__, ep->name);
break;
}
}
static int gs_console_connect(int port_num)
{
struct gscons_info *info = &gscons_info;
struct gs_port *port;
struct usb_ep *ep;
if (port_num != gserial_cons.index) {
pr_err("%s: port num [%d] is not support console\n",
__func__, port_num);
return -ENXIO;
}
port = ports[port_num].port;
ep = port->port_usb->in;
if (!info->console_req) {
info->console_req = gs_request_new(ep);
if (!info->console_req)
return -ENOMEM;
info->console_req->complete = gs_complete_out;
}
info->port = port;
spin_lock(&info->con_lock);
info->req_busy = 0;
spin_unlock(&info->con_lock);
pr_vdebug("port[%d] console connect!\n", port_num);
return 0;
}
static void gs_console_disconnect(struct usb_ep *ep)
{
struct gscons_info *info = &gscons_info;
struct usb_request *req = info->console_req;
gs_request_free(req, ep);
info->console_req = NULL;
}
static int gs_console_thread(void *data)
{
struct gscons_info *info = &gscons_info;
struct gs_port *port;
struct usb_request *req;
struct usb_ep *ep;
int xfer, ret, count, size;
do {
port = info->port;
set_current_state(TASK_INTERRUPTIBLE);
if (!port || !port->port_usb
|| !port->port_usb->in || !info->console_req)
goto sched;
req = info->console_req;
ep = port->port_usb->in;
spin_lock_irq(&info->con_lock);
count = gs_buf_data_avail(&info->con_buf);
size = ep->maxpacket;
if (count > 0 && !info->req_busy) {
set_current_state(TASK_RUNNING);
if (count < size)
size = count;
xfer = gs_buf_get(&info->con_buf, req->buf, size);
req->length = xfer;
spin_unlock(&info->con_lock);
ret = usb_ep_queue(ep, req, GFP_ATOMIC);
spin_lock(&info->con_lock);
if (ret < 0)
info->req_busy = 0;
else
info->req_busy = 1;
spin_unlock_irq(&info->con_lock);
} else {
spin_unlock_irq(&info->con_lock);
sched:
if (kthread_should_stop()) {
set_current_state(TASK_RUNNING);
break;
}
schedule();
}
} while (1);
return 0;
}
static int gs_console_setup(struct console *co, char *options)
{
struct gscons_info *info = &gscons_info;
int status;
info->port = NULL;
info->console_req = NULL;
info->req_busy = 0;
spin_lock_init(&info->con_lock);
status = gs_buf_alloc(&info->con_buf, GS_CONSOLE_BUF_SIZE);
if (status) {
pr_err("%s: allocate console buffer failed\n", __func__);
return status;
}
info->console_thread = kthread_create(gs_console_thread,
co, "gs_console");
if (IS_ERR(info->console_thread)) {
pr_err("%s: cannot create console thread\n", __func__);
gs_buf_free(&info->con_buf);
return PTR_ERR(info->console_thread);
}
wake_up_process(info->console_thread);
return 0;
}
static void gs_console_write(struct console *co,
const char *buf, unsigned count)
{
struct gscons_info *info = &gscons_info;
unsigned long flags;
spin_lock_irqsave(&info->con_lock, flags);
gs_buf_put(&info->con_buf, buf, count);
spin_unlock_irqrestore(&info->con_lock, flags);
wake_up_process(info->console_thread);
}
static struct tty_driver *gs_console_device(struct console *co, int *index)
{
struct tty_driver **p = (struct tty_driver **)co->data;
if (!*p)
return NULL;
*index = co->index;
return *p;
}
static void gserial_console_init(void)
{
register_console(&gserial_cons);
}
static void gserial_console_exit(void)
{
struct gscons_info *info = &gscons_info;
unregister_console(&gserial_cons);
kthread_stop(info->console_thread);
gs_buf_free(&info->con_buf);
}
static int gs_console_connect(int port_num)
{
return 0;
}
static void gs_console_disconnect(struct usb_ep *ep)
{
}
static void gserial_console_init(void)
{
}
static void gserial_console_exit(void)
{
}
static int
gs_port_alloc(unsigned port_num, struct usb_cdc_line_coding *coding)
{
struct gs_port *port;
int ret = 0;
mutex_lock(&ports[port_num].lock);
if (ports[port_num].port) {
ret = -EBUSY;
goto out;
}
port = kzalloc(sizeof(struct gs_port), GFP_KERNEL);
if (port == NULL) {
ret = -ENOMEM;
goto out;
}
tty_port_init(&port->port);
spin_lock_init(&port->port_lock);
init_waitqueue_head(&port->drain_wait);
init_waitqueue_head(&port->close_wait);
tasklet_init(&port->push, gs_rx_push, (unsigned long) port);
INIT_LIST_HEAD(&port->read_pool);
INIT_LIST_HEAD(&port->read_queue);
INIT_LIST_HEAD(&port->write_pool);
port->port_num = port_num;
port->port_line_coding = *coding;
ports[port_num].port = port;
out:
mutex_unlock(&ports[port_num].lock);
return ret;
}
static int gs_closed(struct gs_port *port)
{
int cond;
spin_lock_irq(&port->port_lock);
cond = (port->port.count == 0) && !port->openclose;
spin_unlock_irq(&port->port_lock);
return cond;
}
static void gserial_free_port(struct gs_port *port)
{
tasklet_kill(&port->push);
wait_event(port->close_wait, gs_closed(port));
WARN_ON(port->port_usb != NULL);
tty_port_destroy(&port->port);
kfree(port);
}
void gserial_free_line(unsigned char port_num)
{
struct gs_port *port;
mutex_lock(&ports[port_num].lock);
if (WARN_ON(!ports[port_num].port)) {
mutex_unlock(&ports[port_num].lock);
return;
}
port = ports[port_num].port;
ports[port_num].port = NULL;
mutex_unlock(&ports[port_num].lock);
gserial_free_port(port);
tty_unregister_device(gs_tty_driver, port_num);
gserial_console_exit();
}
int gserial_alloc_line(unsigned char *line_num)
{
struct usb_cdc_line_coding coding;
struct device *tty_dev;
int ret;
int port_num;
coding.dwDTERate = cpu_to_le32(9600);
coding.bCharFormat = 8;
coding.bParityType = USB_CDC_NO_PARITY;
coding.bDataBits = USB_CDC_1_STOP_BITS;
for (port_num = 0; port_num < MAX_U_SERIAL_PORTS; port_num++) {
ret = gs_port_alloc(port_num, &coding);
if (ret == -EBUSY)
continue;
if (ret)
return ret;
break;
}
if (ret)
return ret;
tty_dev = tty_port_register_device(&ports[port_num].port->port,
gs_tty_driver, port_num, NULL);
if (IS_ERR(tty_dev)) {
struct gs_port *port;
pr_err("%s: failed to register tty for port %d, err %ld\n",
__func__, port_num, PTR_ERR(tty_dev));
ret = PTR_ERR(tty_dev);
port = ports[port_num].port;
ports[port_num].port = NULL;
gserial_free_port(port);
goto err;
}
*line_num = port_num;
gserial_console_init();
err:
return ret;
}
int gserial_connect(struct gserial *gser, u8 port_num)
{
struct gs_port *port;
unsigned long flags;
int status;
if (port_num >= MAX_U_SERIAL_PORTS)
return -ENXIO;
port = ports[port_num].port;
if (!port) {
pr_err("serial line %d not allocated.\n", port_num);
return -EINVAL;
}
if (port->port_usb) {
pr_err("serial line %d is in use.\n", port_num);
return -EBUSY;
}
status = usb_ep_enable(gser->in);
if (status < 0)
return status;
gser->in->driver_data = port;
status = usb_ep_enable(gser->out);
if (status < 0)
goto fail_out;
gser->out->driver_data = port;
spin_lock_irqsave(&port->port_lock, flags);
gser->ioport = port;
port->port_usb = gser;
gser->port_line_coding = port->port_line_coding;
if (port->port.count) {
pr_debug("gserial_connect: start ttyGS%d\n", port->port_num);
gs_start_io(port);
if (gser->connect)
gser->connect(gser);
} else {
if (gser->disconnect)
gser->disconnect(gser);
}
status = gs_console_connect(port_num);
spin_unlock_irqrestore(&port->port_lock, flags);
return status;
fail_out:
usb_ep_disable(gser->in);
return status;
}
void gserial_disconnect(struct gserial *gser)
{
struct gs_port *port = gser->ioport;
unsigned long flags;
if (!port)
return;
spin_lock_irqsave(&port->port_lock, flags);
port->port_line_coding = gser->port_line_coding;
port->port_usb = NULL;
gser->ioport = NULL;
if (port->port.count > 0 || port->openclose) {
wake_up_interruptible(&port->drain_wait);
if (port->port.tty)
tty_hangup(port->port.tty);
}
spin_unlock_irqrestore(&port->port_lock, flags);
usb_ep_disable(gser->out);
usb_ep_disable(gser->in);
spin_lock_irqsave(&port->port_lock, flags);
if (port->port.count == 0 && !port->openclose)
gs_buf_free(&port->port_write_buf);
gs_free_requests(gser->out, &port->read_pool, NULL);
gs_free_requests(gser->out, &port->read_queue, NULL);
gs_free_requests(gser->in, &port->write_pool, NULL);
port->read_allocated = port->read_started =
port->write_allocated = port->write_started = 0;
gs_console_disconnect(gser->in);
spin_unlock_irqrestore(&port->port_lock, flags);
}
static int userial_init(void)
{
unsigned i;
int status;
gs_tty_driver = alloc_tty_driver(MAX_U_SERIAL_PORTS);
if (!gs_tty_driver)
return -ENOMEM;
gs_tty_driver->driver_name = "g_serial";
gs_tty_driver->name = "ttyGS";
gs_tty_driver->type = TTY_DRIVER_TYPE_SERIAL;
gs_tty_driver->subtype = SERIAL_TYPE_NORMAL;
gs_tty_driver->flags = TTY_DRIVER_REAL_RAW | TTY_DRIVER_DYNAMIC_DEV;
gs_tty_driver->init_termios = tty_std_termios;
gs_tty_driver->init_termios.c_cflag =
B9600 | CS8 | CREAD | HUPCL | CLOCAL;
gs_tty_driver->init_termios.c_ispeed = 9600;
gs_tty_driver->init_termios.c_ospeed = 9600;
tty_set_operations(gs_tty_driver, &gs_tty_ops);
for (i = 0; i < MAX_U_SERIAL_PORTS; i++)
mutex_init(&ports[i].lock);
status = tty_register_driver(gs_tty_driver);
if (status) {
pr_err("%s: cannot register, err %d\n",
__func__, status);
goto fail;
}
pr_debug("%s: registered %d ttyGS* device%s\n", __func__,
MAX_U_SERIAL_PORTS,
(MAX_U_SERIAL_PORTS == 1) ? "" : "s");
return status;
fail:
put_tty_driver(gs_tty_driver);
gs_tty_driver = NULL;
return status;
}
static void userial_cleanup(void)
{
tty_unregister_driver(gs_tty_driver);
put_tty_driver(gs_tty_driver);
gs_tty_driver = NULL;
}
