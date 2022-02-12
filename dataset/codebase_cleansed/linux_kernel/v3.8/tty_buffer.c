void tty_buffer_free_all(struct tty_port *port)
{
struct tty_bufhead *buf = &port->buf;
struct tty_buffer *thead;
while ((thead = buf->head) != NULL) {
buf->head = thead->next;
kfree(thead);
}
while ((thead = buf->free) != NULL) {
buf->free = thead->next;
kfree(thead);
}
buf->tail = NULL;
buf->memory_used = 0;
}
static struct tty_buffer *tty_buffer_alloc(struct tty_port *port, size_t size)
{
struct tty_buffer *p;
if (port->buf.memory_used + size > 65536)
return NULL;
p = kmalloc(sizeof(struct tty_buffer) + 2 * size, GFP_ATOMIC);
if (p == NULL)
return NULL;
p->used = 0;
p->size = size;
p->next = NULL;
p->commit = 0;
p->read = 0;
p->char_buf_ptr = (char *)(p->data);
p->flag_buf_ptr = (unsigned char *)p->char_buf_ptr + size;
port->buf.memory_used += size;
return p;
}
static void tty_buffer_free(struct tty_port *port, struct tty_buffer *b)
{
struct tty_bufhead *buf = &port->buf;
buf->memory_used -= b->size;
WARN_ON(buf->memory_used < 0);
if (b->size >= 512)
kfree(b);
else {
b->next = buf->free;
buf->free = b;
}
}
static void __tty_buffer_flush(struct tty_port *port)
{
struct tty_bufhead *buf = &port->buf;
struct tty_buffer *thead;
while ((thead = buf->head) != NULL) {
buf->head = thead->next;
tty_buffer_free(port, thead);
}
buf->tail = NULL;
}
void tty_buffer_flush(struct tty_struct *tty)
{
struct tty_port *port = tty->port;
struct tty_bufhead *buf = &port->buf;
unsigned long flags;
spin_lock_irqsave(&buf->lock, flags);
if (test_bit(TTYP_FLUSHING, &port->iflags)) {
set_bit(TTYP_FLUSHPENDING, &port->iflags);
spin_unlock_irqrestore(&buf->lock, flags);
wait_event(tty->read_wait,
test_bit(TTYP_FLUSHPENDING, &port->iflags) == 0);
return;
} else
__tty_buffer_flush(port);
spin_unlock_irqrestore(&buf->lock, flags);
}
static struct tty_buffer *tty_buffer_find(struct tty_port *port, size_t size)
{
struct tty_buffer **tbh = &port->buf.free;
while ((*tbh) != NULL) {
struct tty_buffer *t = *tbh;
if (t->size >= size) {
*tbh = t->next;
t->next = NULL;
t->used = 0;
t->commit = 0;
t->read = 0;
port->buf.memory_used += t->size;
return t;
}
tbh = &((*tbh)->next);
}
size = (size + 0xFF) & ~0xFF;
return tty_buffer_alloc(port, size);
}
static int __tty_buffer_request_room(struct tty_port *port, size_t size)
{
struct tty_bufhead *buf = &port->buf;
struct tty_buffer *b, *n;
int left;
b = buf->tail;
if (b != NULL)
left = b->size - b->used;
else
left = 0;
if (left < size) {
if ((n = tty_buffer_find(port, size)) != NULL) {
if (b != NULL) {
b->next = n;
b->commit = b->used;
} else
buf->head = n;
buf->tail = n;
} else
size = left;
}
return size;
}
int tty_buffer_request_room(struct tty_struct *tty, size_t size)
{
struct tty_port *port = tty->port;
unsigned long flags;
int length;
spin_lock_irqsave(&port->buf.lock, flags);
length = __tty_buffer_request_room(port, size);
spin_unlock_irqrestore(&port->buf.lock, flags);
return length;
}
int tty_insert_flip_string_fixed_flag(struct tty_struct *tty,
const unsigned char *chars, char flag, size_t size)
{
struct tty_bufhead *buf = &tty->port->buf;
int copied = 0;
do {
int goal = min_t(size_t, size - copied, TTY_BUFFER_PAGE);
int space;
unsigned long flags;
struct tty_buffer *tb;
spin_lock_irqsave(&buf->lock, flags);
space = __tty_buffer_request_room(tty->port, goal);
tb = buf->tail;
if (unlikely(space == 0)) {
spin_unlock_irqrestore(&buf->lock, flags);
break;
}
memcpy(tb->char_buf_ptr + tb->used, chars, space);
memset(tb->flag_buf_ptr + tb->used, flag, space);
tb->used += space;
spin_unlock_irqrestore(&buf->lock, flags);
copied += space;
chars += space;
} while (unlikely(size > copied));
return copied;
}
int tty_insert_flip_string_flags(struct tty_struct *tty,
const unsigned char *chars, const char *flags, size_t size)
{
struct tty_bufhead *buf = &tty->port->buf;
int copied = 0;
do {
int goal = min_t(size_t, size - copied, TTY_BUFFER_PAGE);
int space;
unsigned long __flags;
struct tty_buffer *tb;
spin_lock_irqsave(&buf->lock, __flags);
space = __tty_buffer_request_room(tty->port, goal);
tb = buf->tail;
if (unlikely(space == 0)) {
spin_unlock_irqrestore(&buf->lock, __flags);
break;
}
memcpy(tb->char_buf_ptr + tb->used, chars, space);
memcpy(tb->flag_buf_ptr + tb->used, flags, space);
tb->used += space;
spin_unlock_irqrestore(&buf->lock, __flags);
copied += space;
chars += space;
flags += space;
} while (unlikely(size > copied));
return copied;
}
void tty_schedule_flip(struct tty_struct *tty)
{
struct tty_bufhead *buf = &tty->port->buf;
unsigned long flags;
WARN_ON(tty->low_latency);
spin_lock_irqsave(&buf->lock, flags);
if (buf->tail != NULL)
buf->tail->commit = buf->tail->used;
spin_unlock_irqrestore(&buf->lock, flags);
schedule_work(&buf->work);
}
int tty_prepare_flip_string(struct tty_struct *tty, unsigned char **chars,
size_t size)
{
struct tty_bufhead *buf = &tty->port->buf;
int space;
unsigned long flags;
struct tty_buffer *tb;
spin_lock_irqsave(&buf->lock, flags);
space = __tty_buffer_request_room(tty->port, size);
tb = buf->tail;
if (likely(space)) {
*chars = tb->char_buf_ptr + tb->used;
memset(tb->flag_buf_ptr + tb->used, TTY_NORMAL, space);
tb->used += space;
}
spin_unlock_irqrestore(&buf->lock, flags);
return space;
}
int tty_prepare_flip_string_flags(struct tty_struct *tty,
unsigned char **chars, char **flags, size_t size)
{
struct tty_bufhead *buf = &tty->port->buf;
int space;
unsigned long __flags;
struct tty_buffer *tb;
spin_lock_irqsave(&buf->lock, __flags);
space = __tty_buffer_request_room(tty->port, size);
tb = buf->tail;
if (likely(space)) {
*chars = tb->char_buf_ptr + tb->used;
*flags = tb->flag_buf_ptr + tb->used;
tb->used += space;
}
spin_unlock_irqrestore(&buf->lock, __flags);
return space;
}
static void flush_to_ldisc(struct work_struct *work)
{
struct tty_port *port = container_of(work, struct tty_port, buf.work);
struct tty_bufhead *buf = &port->buf;
struct tty_struct *tty;
unsigned long flags;
struct tty_ldisc *disc;
tty = port->itty;
if (WARN_RATELIMIT(tty == NULL, "tty is NULL\n"))
return;
disc = tty_ldisc_ref(tty);
if (disc == NULL)
return;
spin_lock_irqsave(&buf->lock, flags);
if (!test_and_set_bit(TTYP_FLUSHING, &port->iflags)) {
struct tty_buffer *head;
while ((head = buf->head) != NULL) {
int count;
char *char_buf;
unsigned char *flag_buf;
count = head->commit - head->read;
if (!count) {
if (head->next == NULL)
break;
buf->head = head->next;
tty_buffer_free(port, head);
continue;
}
if (test_bit(TTYP_FLUSHPENDING, &port->iflags))
break;
if (!tty->receive_room)
break;
if (count > tty->receive_room)
count = tty->receive_room;
char_buf = head->char_buf_ptr + head->read;
flag_buf = head->flag_buf_ptr + head->read;
head->read += count;
spin_unlock_irqrestore(&buf->lock, flags);
disc->ops->receive_buf(tty, char_buf,
flag_buf, count);
spin_lock_irqsave(&buf->lock, flags);
}
clear_bit(TTYP_FLUSHING, &port->iflags);
}
if (test_bit(TTYP_FLUSHPENDING, &port->iflags)) {
__tty_buffer_flush(port);
clear_bit(TTYP_FLUSHPENDING, &port->iflags);
wake_up(&tty->read_wait);
}
spin_unlock_irqrestore(&buf->lock, flags);
tty_ldisc_deref(disc);
}
void tty_flush_to_ldisc(struct tty_struct *tty)
{
if (!tty->low_latency)
flush_work(&tty->port->buf.work);
}
void tty_flip_buffer_push(struct tty_struct *tty)
{
struct tty_bufhead *buf = &tty->port->buf;
unsigned long flags;
spin_lock_irqsave(&buf->lock, flags);
if (buf->tail != NULL)
buf->tail->commit = buf->tail->used;
spin_unlock_irqrestore(&buf->lock, flags);
if (tty->low_latency)
flush_to_ldisc(&buf->work);
else
schedule_work(&buf->work);
}
void tty_buffer_init(struct tty_port *port)
{
struct tty_bufhead *buf = &port->buf;
spin_lock_init(&buf->lock);
buf->head = NULL;
buf->tail = NULL;
buf->free = NULL;
buf->memory_used = 0;
INIT_WORK(&buf->work, flush_to_ldisc);
}
