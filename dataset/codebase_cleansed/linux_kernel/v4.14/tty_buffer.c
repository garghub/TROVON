void tty_buffer_lock_exclusive(struct tty_port *port)
{
struct tty_bufhead *buf = &port->buf;
atomic_inc(&buf->priority);
mutex_lock(&buf->lock);
}
void tty_buffer_unlock_exclusive(struct tty_port *port)
{
struct tty_bufhead *buf = &port->buf;
int restart;
restart = buf->head->commit != buf->head->read;
atomic_dec(&buf->priority);
mutex_unlock(&buf->lock);
if (restart)
queue_work(system_unbound_wq, &buf->work);
}
int tty_buffer_space_avail(struct tty_port *port)
{
int space = port->buf.mem_limit - atomic_read(&port->buf.mem_used);
return max(space, 0);
}
static void tty_buffer_reset(struct tty_buffer *p, size_t size)
{
p->used = 0;
p->size = size;
p->next = NULL;
p->commit = 0;
p->read = 0;
p->flags = 0;
}
void tty_buffer_free_all(struct tty_port *port)
{
struct tty_bufhead *buf = &port->buf;
struct tty_buffer *p, *next;
struct llist_node *llist;
while ((p = buf->head) != NULL) {
buf->head = p->next;
if (p->size > 0)
kfree(p);
}
llist = llist_del_all(&buf->free);
llist_for_each_entry_safe(p, next, llist, free)
kfree(p);
tty_buffer_reset(&buf->sentinel, 0);
buf->head = &buf->sentinel;
buf->tail = &buf->sentinel;
atomic_set(&buf->mem_used, 0);
}
static struct tty_buffer *tty_buffer_alloc(struct tty_port *port, size_t size)
{
struct llist_node *free;
struct tty_buffer *p;
size = __ALIGN_MASK(size, TTYB_ALIGN_MASK);
if (size <= MIN_TTYB_SIZE) {
free = llist_del_first(&port->buf.free);
if (free) {
p = llist_entry(free, struct tty_buffer, free);
goto found;
}
}
if (atomic_read(&port->buf.mem_used) > port->buf.mem_limit)
return NULL;
p = kmalloc(sizeof(struct tty_buffer) + 2 * size, GFP_ATOMIC);
if (p == NULL)
return NULL;
found:
tty_buffer_reset(p, size);
atomic_add(size, &port->buf.mem_used);
return p;
}
static void tty_buffer_free(struct tty_port *port, struct tty_buffer *b)
{
struct tty_bufhead *buf = &port->buf;
WARN_ON(atomic_sub_return(b->size, &buf->mem_used) < 0);
if (b->size > MIN_TTYB_SIZE)
kfree(b);
else if (b->size > 0)
llist_add(&b->free, &buf->free);
}
void tty_buffer_flush(struct tty_struct *tty, struct tty_ldisc *ld)
{
struct tty_port *port = tty->port;
struct tty_bufhead *buf = &port->buf;
struct tty_buffer *next;
atomic_inc(&buf->priority);
mutex_lock(&buf->lock);
while ((next = smp_load_acquire(&buf->head->next)) != NULL) {
tty_buffer_free(port, buf->head);
buf->head = next;
}
buf->head->read = buf->head->commit;
if (ld && ld->ops->flush_buffer)
ld->ops->flush_buffer(tty);
atomic_dec(&buf->priority);
mutex_unlock(&buf->lock);
}
static int __tty_buffer_request_room(struct tty_port *port, size_t size,
int flags)
{
struct tty_bufhead *buf = &port->buf;
struct tty_buffer *b, *n;
int left, change;
b = buf->tail;
if (b->flags & TTYB_NORMAL)
left = 2 * b->size - b->used;
else
left = b->size - b->used;
change = (b->flags & TTYB_NORMAL) && (~flags & TTYB_NORMAL);
if (change || left < size) {
n = tty_buffer_alloc(port, size);
if (n != NULL) {
n->flags = flags;
buf->tail = n;
smp_store_release(&b->commit, b->used);
smp_store_release(&b->next, n);
} else if (change)
size = 0;
else
size = left;
}
return size;
}
int tty_buffer_request_room(struct tty_port *port, size_t size)
{
return __tty_buffer_request_room(port, size, 0);
}
int tty_insert_flip_string_fixed_flag(struct tty_port *port,
const unsigned char *chars, char flag, size_t size)
{
int copied = 0;
do {
int goal = min_t(size_t, size - copied, TTY_BUFFER_PAGE);
int flags = (flag == TTY_NORMAL) ? TTYB_NORMAL : 0;
int space = __tty_buffer_request_room(port, goal, flags);
struct tty_buffer *tb = port->buf.tail;
if (unlikely(space == 0))
break;
memcpy(char_buf_ptr(tb, tb->used), chars, space);
if (~tb->flags & TTYB_NORMAL)
memset(flag_buf_ptr(tb, tb->used), flag, space);
tb->used += space;
copied += space;
chars += space;
} while (unlikely(size > copied));
return copied;
}
int tty_insert_flip_string_flags(struct tty_port *port,
const unsigned char *chars, const char *flags, size_t size)
{
int copied = 0;
do {
int goal = min_t(size_t, size - copied, TTY_BUFFER_PAGE);
int space = tty_buffer_request_room(port, goal);
struct tty_buffer *tb = port->buf.tail;
if (unlikely(space == 0))
break;
memcpy(char_buf_ptr(tb, tb->used), chars, space);
memcpy(flag_buf_ptr(tb, tb->used), flags, space);
tb->used += space;
copied += space;
chars += space;
flags += space;
} while (unlikely(size > copied));
return copied;
}
int __tty_insert_flip_char(struct tty_port *port, unsigned char ch, char flag)
{
struct tty_buffer *tb;
int flags = (flag == TTY_NORMAL) ? TTYB_NORMAL : 0;
if (!__tty_buffer_request_room(port, 1, flags))
return 0;
tb = port->buf.tail;
if (~tb->flags & TTYB_NORMAL)
*flag_buf_ptr(tb, tb->used) = flag;
*char_buf_ptr(tb, tb->used++) = ch;
return 1;
}
void tty_schedule_flip(struct tty_port *port)
{
struct tty_bufhead *buf = &port->buf;
smp_store_release(&buf->tail->commit, buf->tail->used);
queue_work(system_unbound_wq, &buf->work);
}
int tty_prepare_flip_string(struct tty_port *port, unsigned char **chars,
size_t size)
{
int space = __tty_buffer_request_room(port, size, TTYB_NORMAL);
if (likely(space)) {
struct tty_buffer *tb = port->buf.tail;
*chars = char_buf_ptr(tb, tb->used);
if (~tb->flags & TTYB_NORMAL)
memset(flag_buf_ptr(tb, tb->used), TTY_NORMAL, space);
tb->used += space;
}
return space;
}
int tty_ldisc_receive_buf(struct tty_ldisc *ld, const unsigned char *p,
char *f, int count)
{
if (ld->ops->receive_buf2)
count = ld->ops->receive_buf2(ld->tty, p, f, count);
else {
count = min_t(int, count, ld->tty->receive_room);
if (count && ld->ops->receive_buf)
ld->ops->receive_buf(ld->tty, p, f, count);
}
return count;
}
static int
receive_buf(struct tty_port *port, struct tty_buffer *head, int count)
{
unsigned char *p = char_buf_ptr(head, head->read);
char *f = NULL;
if (~head->flags & TTYB_NORMAL)
f = flag_buf_ptr(head, head->read);
return port->client_ops->receive_buf(port, p, f, count);
}
static void flush_to_ldisc(struct work_struct *work)
{
struct tty_port *port = container_of(work, struct tty_port, buf.work);
struct tty_bufhead *buf = &port->buf;
mutex_lock(&buf->lock);
while (1) {
struct tty_buffer *head = buf->head;
struct tty_buffer *next;
int count;
if (atomic_read(&buf->priority))
break;
next = smp_load_acquire(&head->next);
count = smp_load_acquire(&head->commit) - head->read;
if (!count) {
if (next == NULL)
break;
buf->head = next;
tty_buffer_free(port, head);
continue;
}
count = receive_buf(port, head, count);
if (!count)
break;
head->read += count;
}
mutex_unlock(&buf->lock);
}
void tty_flip_buffer_push(struct tty_port *port)
{
tty_schedule_flip(port);
}
void tty_buffer_init(struct tty_port *port)
{
struct tty_bufhead *buf = &port->buf;
mutex_init(&buf->lock);
tty_buffer_reset(&buf->sentinel, 0);
buf->head = &buf->sentinel;
buf->tail = &buf->sentinel;
init_llist_head(&buf->free);
atomic_set(&buf->mem_used, 0);
atomic_set(&buf->priority, 0);
INIT_WORK(&buf->work, flush_to_ldisc);
buf->mem_limit = TTYB_DEFAULT_MEM_LIMIT;
}
int tty_buffer_set_limit(struct tty_port *port, int limit)
{
if (limit < MIN_TTYB_SIZE)
return -EINVAL;
port->buf.mem_limit = limit;
return 0;
}
void tty_buffer_set_lock_subclass(struct tty_port *port)
{
lockdep_set_subclass(&port->buf.lock, TTY_LOCK_SLAVE);
}
bool tty_buffer_restart_work(struct tty_port *port)
{
return queue_work(system_unbound_wq, &port->buf.work);
}
bool tty_buffer_cancel_work(struct tty_port *port)
{
return cancel_work_sync(&port->buf.work);
}
void tty_buffer_flush_work(struct tty_port *port)
{
flush_work(&port->buf.work);
}
