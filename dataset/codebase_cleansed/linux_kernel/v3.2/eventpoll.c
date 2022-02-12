static inline void ep_set_ffd(struct epoll_filefd *ffd,
struct file *file, int fd)
{
ffd->file = file;
ffd->fd = fd;
}
static inline int ep_cmp_ffd(struct epoll_filefd *p1,
struct epoll_filefd *p2)
{
return (p1->file > p2->file ? +1:
(p1->file < p2->file ? -1 : p1->fd - p2->fd));
}
static inline int ep_is_linked(struct list_head *p)
{
return !list_empty(p);
}
static inline struct epitem *ep_item_from_wait(wait_queue_t *p)
{
return container_of(p, struct eppoll_entry, wait)->base;
}
static inline struct epitem *ep_item_from_epqueue(poll_table *p)
{
return container_of(p, struct ep_pqueue, pt)->epi;
}
static inline int ep_op_has_event(int op)
{
return op != EPOLL_CTL_DEL;
}
static void ep_nested_calls_init(struct nested_calls *ncalls)
{
INIT_LIST_HEAD(&ncalls->tasks_call_list);
spin_lock_init(&ncalls->lock);
}
static inline int ep_events_available(struct eventpoll *ep)
{
return !list_empty(&ep->rdllist) || ep->ovflist != EP_UNACTIVE_PTR;
}
static int ep_call_nested(struct nested_calls *ncalls, int max_nests,
int (*nproc)(void *, void *, int), void *priv,
void *cookie, void *ctx)
{
int error, call_nests = 0;
unsigned long flags;
struct list_head *lsthead = &ncalls->tasks_call_list;
struct nested_call_node *tncur;
struct nested_call_node tnode;
spin_lock_irqsave(&ncalls->lock, flags);
list_for_each_entry(tncur, lsthead, llink) {
if (tncur->ctx == ctx &&
(tncur->cookie == cookie || ++call_nests > max_nests)) {
error = -1;
goto out_unlock;
}
}
tnode.ctx = ctx;
tnode.cookie = cookie;
list_add(&tnode.llink, lsthead);
spin_unlock_irqrestore(&ncalls->lock, flags);
error = (*nproc)(priv, cookie, call_nests);
spin_lock_irqsave(&ncalls->lock, flags);
list_del(&tnode.llink);
out_unlock:
spin_unlock_irqrestore(&ncalls->lock, flags);
return error;
}
static inline void ep_wake_up_nested(wait_queue_head_t *wqueue,
unsigned long events, int subclass)
{
unsigned long flags;
spin_lock_irqsave_nested(&wqueue->lock, flags, subclass);
wake_up_locked_poll(wqueue, events);
spin_unlock_irqrestore(&wqueue->lock, flags);
}
static inline void ep_wake_up_nested(wait_queue_head_t *wqueue,
unsigned long events, int subclass)
{
wake_up_poll(wqueue, events);
}
static int ep_poll_wakeup_proc(void *priv, void *cookie, int call_nests)
{
ep_wake_up_nested((wait_queue_head_t *) cookie, POLLIN,
1 + call_nests);
return 0;
}
static void ep_poll_safewake(wait_queue_head_t *wq)
{
int this_cpu = get_cpu();
ep_call_nested(&poll_safewake_ncalls, EP_MAX_NESTS,
ep_poll_wakeup_proc, NULL, wq, (void *) (long) this_cpu);
put_cpu();
}
static void ep_unregister_pollwait(struct eventpoll *ep, struct epitem *epi)
{
struct list_head *lsthead = &epi->pwqlist;
struct eppoll_entry *pwq;
while (!list_empty(lsthead)) {
pwq = list_first_entry(lsthead, struct eppoll_entry, llink);
list_del(&pwq->llink);
remove_wait_queue(pwq->whead, &pwq->wait);
kmem_cache_free(pwq_cache, pwq);
}
}
static int ep_scan_ready_list(struct eventpoll *ep,
int (*sproc)(struct eventpoll *,
struct list_head *, void *),
void *priv,
int depth)
{
int error, pwake = 0;
unsigned long flags;
struct epitem *epi, *nepi;
LIST_HEAD(txlist);
mutex_lock_nested(&ep->mtx, depth);
spin_lock_irqsave(&ep->lock, flags);
list_splice_init(&ep->rdllist, &txlist);
ep->ovflist = NULL;
spin_unlock_irqrestore(&ep->lock, flags);
error = (*sproc)(ep, &txlist, priv);
spin_lock_irqsave(&ep->lock, flags);
for (nepi = ep->ovflist; (epi = nepi) != NULL;
nepi = epi->next, epi->next = EP_UNACTIVE_PTR) {
if (!ep_is_linked(&epi->rdllink))
list_add_tail(&epi->rdllink, &ep->rdllist);
}
ep->ovflist = EP_UNACTIVE_PTR;
list_splice(&txlist, &ep->rdllist);
if (!list_empty(&ep->rdllist)) {
if (waitqueue_active(&ep->wq))
wake_up_locked(&ep->wq);
if (waitqueue_active(&ep->poll_wait))
pwake++;
}
spin_unlock_irqrestore(&ep->lock, flags);
mutex_unlock(&ep->mtx);
if (pwake)
ep_poll_safewake(&ep->poll_wait);
return error;
}
static int ep_remove(struct eventpoll *ep, struct epitem *epi)
{
unsigned long flags;
struct file *file = epi->ffd.file;
ep_unregister_pollwait(ep, epi);
spin_lock(&file->f_lock);
if (ep_is_linked(&epi->fllink))
list_del_init(&epi->fllink);
spin_unlock(&file->f_lock);
rb_erase(&epi->rbn, &ep->rbr);
spin_lock_irqsave(&ep->lock, flags);
if (ep_is_linked(&epi->rdllink))
list_del_init(&epi->rdllink);
spin_unlock_irqrestore(&ep->lock, flags);
kmem_cache_free(epi_cache, epi);
atomic_long_dec(&ep->user->epoll_watches);
return 0;
}
static void ep_free(struct eventpoll *ep)
{
struct rb_node *rbp;
struct epitem *epi;
if (waitqueue_active(&ep->poll_wait))
ep_poll_safewake(&ep->poll_wait);
mutex_lock(&epmutex);
for (rbp = rb_first(&ep->rbr); rbp; rbp = rb_next(rbp)) {
epi = rb_entry(rbp, struct epitem, rbn);
ep_unregister_pollwait(ep, epi);
}
while ((rbp = rb_first(&ep->rbr)) != NULL) {
epi = rb_entry(rbp, struct epitem, rbn);
ep_remove(ep, epi);
}
mutex_unlock(&epmutex);
mutex_destroy(&ep->mtx);
free_uid(ep->user);
kfree(ep);
}
static int ep_eventpoll_release(struct inode *inode, struct file *file)
{
struct eventpoll *ep = file->private_data;
if (ep)
ep_free(ep);
return 0;
}
static int ep_read_events_proc(struct eventpoll *ep, struct list_head *head,
void *priv)
{
struct epitem *epi, *tmp;
list_for_each_entry_safe(epi, tmp, head, rdllink) {
if (epi->ffd.file->f_op->poll(epi->ffd.file, NULL) &
epi->event.events)
return POLLIN | POLLRDNORM;
else {
list_del_init(&epi->rdllink);
}
}
return 0;
}
static int ep_poll_readyevents_proc(void *priv, void *cookie, int call_nests)
{
return ep_scan_ready_list(priv, ep_read_events_proc, NULL, call_nests + 1);
}
static unsigned int ep_eventpoll_poll(struct file *file, poll_table *wait)
{
int pollflags;
struct eventpoll *ep = file->private_data;
poll_wait(file, &ep->poll_wait, wait);
pollflags = ep_call_nested(&poll_readywalk_ncalls, EP_MAX_NESTS,
ep_poll_readyevents_proc, ep, ep, current);
return pollflags != -1 ? pollflags : 0;
}
static inline int is_file_epoll(struct file *f)
{
return f->f_op == &eventpoll_fops;
}
void eventpoll_release_file(struct file *file)
{
struct list_head *lsthead = &file->f_ep_links;
struct eventpoll *ep;
struct epitem *epi;
mutex_lock(&epmutex);
while (!list_empty(lsthead)) {
epi = list_first_entry(lsthead, struct epitem, fllink);
ep = epi->ep;
list_del_init(&epi->fllink);
mutex_lock_nested(&ep->mtx, 0);
ep_remove(ep, epi);
mutex_unlock(&ep->mtx);
}
mutex_unlock(&epmutex);
}
static int ep_alloc(struct eventpoll **pep)
{
int error;
struct user_struct *user;
struct eventpoll *ep;
user = get_current_user();
error = -ENOMEM;
ep = kzalloc(sizeof(*ep), GFP_KERNEL);
if (unlikely(!ep))
goto free_uid;
spin_lock_init(&ep->lock);
mutex_init(&ep->mtx);
init_waitqueue_head(&ep->wq);
init_waitqueue_head(&ep->poll_wait);
INIT_LIST_HEAD(&ep->rdllist);
ep->rbr = RB_ROOT;
ep->ovflist = EP_UNACTIVE_PTR;
ep->user = user;
*pep = ep;
return 0;
free_uid:
free_uid(user);
return error;
}
static struct epitem *ep_find(struct eventpoll *ep, struct file *file, int fd)
{
int kcmp;
struct rb_node *rbp;
struct epitem *epi, *epir = NULL;
struct epoll_filefd ffd;
ep_set_ffd(&ffd, file, fd);
for (rbp = ep->rbr.rb_node; rbp; ) {
epi = rb_entry(rbp, struct epitem, rbn);
kcmp = ep_cmp_ffd(&ffd, &epi->ffd);
if (kcmp > 0)
rbp = rbp->rb_right;
else if (kcmp < 0)
rbp = rbp->rb_left;
else {
epir = epi;
break;
}
}
return epir;
}
static int ep_poll_callback(wait_queue_t *wait, unsigned mode, int sync, void *key)
{
int pwake = 0;
unsigned long flags;
struct epitem *epi = ep_item_from_wait(wait);
struct eventpoll *ep = epi->ep;
spin_lock_irqsave(&ep->lock, flags);
if (!(epi->event.events & ~EP_PRIVATE_BITS))
goto out_unlock;
if (key && !((unsigned long) key & epi->event.events))
goto out_unlock;
if (unlikely(ep->ovflist != EP_UNACTIVE_PTR)) {
if (epi->next == EP_UNACTIVE_PTR) {
epi->next = ep->ovflist;
ep->ovflist = epi;
}
goto out_unlock;
}
if (!ep_is_linked(&epi->rdllink))
list_add_tail(&epi->rdllink, &ep->rdllist);
if (waitqueue_active(&ep->wq))
wake_up_locked(&ep->wq);
if (waitqueue_active(&ep->poll_wait))
pwake++;
out_unlock:
spin_unlock_irqrestore(&ep->lock, flags);
if (pwake)
ep_poll_safewake(&ep->poll_wait);
return 1;
}
static void ep_ptable_queue_proc(struct file *file, wait_queue_head_t *whead,
poll_table *pt)
{
struct epitem *epi = ep_item_from_epqueue(pt);
struct eppoll_entry *pwq;
if (epi->nwait >= 0 && (pwq = kmem_cache_alloc(pwq_cache, GFP_KERNEL))) {
init_waitqueue_func_entry(&pwq->wait, ep_poll_callback);
pwq->whead = whead;
pwq->base = epi;
add_wait_queue(whead, &pwq->wait);
list_add_tail(&pwq->llink, &epi->pwqlist);
epi->nwait++;
} else {
epi->nwait = -1;
}
}
static void ep_rbtree_insert(struct eventpoll *ep, struct epitem *epi)
{
int kcmp;
struct rb_node **p = &ep->rbr.rb_node, *parent = NULL;
struct epitem *epic;
while (*p) {
parent = *p;
epic = rb_entry(parent, struct epitem, rbn);
kcmp = ep_cmp_ffd(&epi->ffd, &epic->ffd);
if (kcmp > 0)
p = &parent->rb_right;
else
p = &parent->rb_left;
}
rb_link_node(&epi->rbn, parent, p);
rb_insert_color(&epi->rbn, &ep->rbr);
}
static int ep_insert(struct eventpoll *ep, struct epoll_event *event,
struct file *tfile, int fd)
{
int error, revents, pwake = 0;
unsigned long flags;
long user_watches;
struct epitem *epi;
struct ep_pqueue epq;
user_watches = atomic_long_read(&ep->user->epoll_watches);
if (unlikely(user_watches >= max_user_watches))
return -ENOSPC;
if (!(epi = kmem_cache_alloc(epi_cache, GFP_KERNEL)))
return -ENOMEM;
INIT_LIST_HEAD(&epi->rdllink);
INIT_LIST_HEAD(&epi->fllink);
INIT_LIST_HEAD(&epi->pwqlist);
epi->ep = ep;
ep_set_ffd(&epi->ffd, tfile, fd);
epi->event = *event;
epi->nwait = 0;
epi->next = EP_UNACTIVE_PTR;
epq.epi = epi;
init_poll_funcptr(&epq.pt, ep_ptable_queue_proc);
revents = tfile->f_op->poll(tfile, &epq.pt);
error = -ENOMEM;
if (epi->nwait < 0)
goto error_unregister;
spin_lock(&tfile->f_lock);
list_add_tail(&epi->fllink, &tfile->f_ep_links);
spin_unlock(&tfile->f_lock);
ep_rbtree_insert(ep, epi);
spin_lock_irqsave(&ep->lock, flags);
if ((revents & event->events) && !ep_is_linked(&epi->rdllink)) {
list_add_tail(&epi->rdllink, &ep->rdllist);
if (waitqueue_active(&ep->wq))
wake_up_locked(&ep->wq);
if (waitqueue_active(&ep->poll_wait))
pwake++;
}
spin_unlock_irqrestore(&ep->lock, flags);
atomic_long_inc(&ep->user->epoll_watches);
if (pwake)
ep_poll_safewake(&ep->poll_wait);
return 0;
error_unregister:
ep_unregister_pollwait(ep, epi);
spin_lock_irqsave(&ep->lock, flags);
if (ep_is_linked(&epi->rdllink))
list_del_init(&epi->rdllink);
spin_unlock_irqrestore(&ep->lock, flags);
kmem_cache_free(epi_cache, epi);
return error;
}
static int ep_modify(struct eventpoll *ep, struct epitem *epi, struct epoll_event *event)
{
int pwake = 0;
unsigned int revents;
epi->event.events = event->events;
epi->event.data = event->data;
revents = epi->ffd.file->f_op->poll(epi->ffd.file, NULL);
if (revents & event->events) {
spin_lock_irq(&ep->lock);
if (!ep_is_linked(&epi->rdllink)) {
list_add_tail(&epi->rdllink, &ep->rdllist);
if (waitqueue_active(&ep->wq))
wake_up_locked(&ep->wq);
if (waitqueue_active(&ep->poll_wait))
pwake++;
}
spin_unlock_irq(&ep->lock);
}
if (pwake)
ep_poll_safewake(&ep->poll_wait);
return 0;
}
static int ep_send_events_proc(struct eventpoll *ep, struct list_head *head,
void *priv)
{
struct ep_send_events_data *esed = priv;
int eventcnt;
unsigned int revents;
struct epitem *epi;
struct epoll_event __user *uevent;
for (eventcnt = 0, uevent = esed->events;
!list_empty(head) && eventcnt < esed->maxevents;) {
epi = list_first_entry(head, struct epitem, rdllink);
list_del_init(&epi->rdllink);
revents = epi->ffd.file->f_op->poll(epi->ffd.file, NULL) &
epi->event.events;
if (revents) {
if (__put_user(revents, &uevent->events) ||
__put_user(epi->event.data, &uevent->data)) {
list_add(&epi->rdllink, head);
return eventcnt ? eventcnt : -EFAULT;
}
eventcnt++;
uevent++;
if (epi->event.events & EPOLLONESHOT)
epi->event.events &= EP_PRIVATE_BITS;
else if (!(epi->event.events & EPOLLET)) {
list_add_tail(&epi->rdllink, &ep->rdllist);
}
}
}
return eventcnt;
}
static int ep_send_events(struct eventpoll *ep,
struct epoll_event __user *events, int maxevents)
{
struct ep_send_events_data esed;
esed.maxevents = maxevents;
esed.events = events;
return ep_scan_ready_list(ep, ep_send_events_proc, &esed, 0);
}
static inline struct timespec ep_set_mstimeout(long ms)
{
struct timespec now, ts = {
.tv_sec = ms / MSEC_PER_SEC,
.tv_nsec = NSEC_PER_MSEC * (ms % MSEC_PER_SEC),
};
ktime_get_ts(&now);
return timespec_add_safe(now, ts);
}
static int ep_poll(struct eventpoll *ep, struct epoll_event __user *events,
int maxevents, long timeout)
{
int res = 0, eavail, timed_out = 0;
unsigned long flags;
long slack = 0;
wait_queue_t wait;
ktime_t expires, *to = NULL;
if (timeout > 0) {
struct timespec end_time = ep_set_mstimeout(timeout);
slack = select_estimate_accuracy(&end_time);
to = &expires;
*to = timespec_to_ktime(end_time);
} else if (timeout == 0) {
timed_out = 1;
spin_lock_irqsave(&ep->lock, flags);
goto check_events;
}
fetch_events:
spin_lock_irqsave(&ep->lock, flags);
if (!ep_events_available(ep)) {
init_waitqueue_entry(&wait, current);
__add_wait_queue_exclusive(&ep->wq, &wait);
for (;;) {
set_current_state(TASK_INTERRUPTIBLE);
if (ep_events_available(ep) || timed_out)
break;
if (signal_pending(current)) {
res = -EINTR;
break;
}
spin_unlock_irqrestore(&ep->lock, flags);
if (!schedule_hrtimeout_range(to, slack, HRTIMER_MODE_ABS))
timed_out = 1;
spin_lock_irqsave(&ep->lock, flags);
}
__remove_wait_queue(&ep->wq, &wait);
set_current_state(TASK_RUNNING);
}
check_events:
eavail = ep_events_available(ep);
spin_unlock_irqrestore(&ep->lock, flags);
if (!res && eavail &&
!(res = ep_send_events(ep, events, maxevents)) && !timed_out)
goto fetch_events;
return res;
}
static int ep_loop_check_proc(void *priv, void *cookie, int call_nests)
{
int error = 0;
struct file *file = priv;
struct eventpoll *ep = file->private_data;
struct rb_node *rbp;
struct epitem *epi;
mutex_lock_nested(&ep->mtx, call_nests + 1);
for (rbp = rb_first(&ep->rbr); rbp; rbp = rb_next(rbp)) {
epi = rb_entry(rbp, struct epitem, rbn);
if (unlikely(is_file_epoll(epi->ffd.file))) {
error = ep_call_nested(&poll_loop_ncalls, EP_MAX_NESTS,
ep_loop_check_proc, epi->ffd.file,
epi->ffd.file->private_data, current);
if (error != 0)
break;
}
}
mutex_unlock(&ep->mtx);
return error;
}
static int ep_loop_check(struct eventpoll *ep, struct file *file)
{
return ep_call_nested(&poll_loop_ncalls, EP_MAX_NESTS,
ep_loop_check_proc, file, ep, current);
}
static int __init eventpoll_init(void)
{
struct sysinfo si;
si_meminfo(&si);
max_user_watches = (((si.totalram - si.totalhigh) / 25) << PAGE_SHIFT) /
EP_ITEM_COST;
BUG_ON(max_user_watches < 0);
ep_nested_calls_init(&poll_loop_ncalls);
ep_nested_calls_init(&poll_safewake_ncalls);
ep_nested_calls_init(&poll_readywalk_ncalls);
epi_cache = kmem_cache_create("eventpoll_epi", sizeof(struct epitem),
0, SLAB_HWCACHE_ALIGN | SLAB_PANIC, NULL);
pwq_cache = kmem_cache_create("eventpoll_pwq",
sizeof(struct eppoll_entry), 0, SLAB_PANIC, NULL);
return 0;
}
