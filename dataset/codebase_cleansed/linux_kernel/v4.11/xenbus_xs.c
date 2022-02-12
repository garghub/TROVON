static void xs_suspend_enter(void)
{
spin_lock(&xs_state_lock);
xs_suspend_active++;
spin_unlock(&xs_state_lock);
wait_event(xs_state_exit_wq, xs_state_users == 0);
}
static void xs_suspend_exit(void)
{
spin_lock(&xs_state_lock);
xs_suspend_active--;
spin_unlock(&xs_state_lock);
wake_up_all(&xs_state_enter_wq);
}
static uint32_t xs_request_enter(struct xb_req_data *req)
{
uint32_t rq_id;
req->type = req->msg.type;
spin_lock(&xs_state_lock);
while (!xs_state_users && xs_suspend_active) {
spin_unlock(&xs_state_lock);
wait_event(xs_state_enter_wq, xs_suspend_active == 0);
spin_lock(&xs_state_lock);
}
if (req->type == XS_TRANSACTION_START)
xs_state_users++;
xs_state_users++;
rq_id = xs_request_id++;
spin_unlock(&xs_state_lock);
return rq_id;
}
void xs_request_exit(struct xb_req_data *req)
{
spin_lock(&xs_state_lock);
xs_state_users--;
if ((req->type == XS_TRANSACTION_START && req->msg.type == XS_ERROR) ||
req->type == XS_TRANSACTION_END)
xs_state_users--;
spin_unlock(&xs_state_lock);
if (xs_suspend_active && !xs_state_users)
wake_up(&xs_state_exit_wq);
}
static int get_error(const char *errorstring)
{
unsigned int i;
for (i = 0; strcmp(errorstring, xsd_errors[i].errstring) != 0; i++) {
if (i == ARRAY_SIZE(xsd_errors) - 1) {
pr_warn("xen store gave: unknown error %s\n",
errorstring);
return EINVAL;
}
}
return xsd_errors[i].errnum;
}
static bool xenbus_ok(void)
{
switch (xen_store_domain_type) {
case XS_LOCAL:
switch (system_state) {
case SYSTEM_POWER_OFF:
case SYSTEM_RESTART:
case SYSTEM_HALT:
return false;
default:
break;
}
return true;
case XS_PV:
case XS_HVM:
return true;
default:
break;
}
return false;
}
static bool test_reply(struct xb_req_data *req)
{
if (req->state == xb_req_state_got_reply || !xenbus_ok())
return true;
barrier();
return false;
}
static void *read_reply(struct xb_req_data *req)
{
while (req->state != xb_req_state_got_reply) {
wait_event(req->wq, test_reply(req));
if (!xenbus_ok())
return ERR_PTR(-EIO);
if (req->err)
return ERR_PTR(req->err);
}
return req->body;
}
static void xs_send(struct xb_req_data *req, struct xsd_sockmsg *msg)
{
bool notify;
req->msg = *msg;
req->err = 0;
req->state = xb_req_state_queued;
init_waitqueue_head(&req->wq);
req->msg.req_id = xs_request_enter(req);
mutex_lock(&xb_write_mutex);
list_add_tail(&req->list, &xb_write_list);
notify = list_is_singular(&xb_write_list);
mutex_unlock(&xb_write_mutex);
if (notify)
wake_up(&xb_waitq);
}
static void *xs_wait_for_reply(struct xb_req_data *req, struct xsd_sockmsg *msg)
{
void *ret;
ret = read_reply(req);
xs_request_exit(req);
msg->type = req->msg.type;
msg->len = req->msg.len;
mutex_lock(&xb_write_mutex);
if (req->state == xb_req_state_queued ||
req->state == xb_req_state_wait_reply)
req->state = xb_req_state_aborted;
else
kfree(req);
mutex_unlock(&xb_write_mutex);
return ret;
}
static void xs_wake_up(struct xb_req_data *req)
{
wake_up(&req->wq);
}
int xenbus_dev_request_and_reply(struct xsd_sockmsg *msg, void *par)
{
struct xb_req_data *req;
struct kvec *vec;
req = kmalloc(sizeof(*req) + sizeof(*vec), GFP_KERNEL);
if (!req)
return -ENOMEM;
vec = (struct kvec *)(req + 1);
vec->iov_len = msg->len;
vec->iov_base = msg + 1;
req->vec = vec;
req->num_vecs = 1;
req->cb = xenbus_dev_queue_reply;
req->par = par;
xs_send(req, msg);
return 0;
}
static void *xs_talkv(struct xenbus_transaction t,
enum xsd_sockmsg_type type,
const struct kvec *iovec,
unsigned int num_vecs,
unsigned int *len)
{
struct xb_req_data *req;
struct xsd_sockmsg msg;
void *ret = NULL;
unsigned int i;
int err;
req = kmalloc(sizeof(*req), GFP_NOIO | __GFP_HIGH);
if (!req)
return ERR_PTR(-ENOMEM);
req->vec = iovec;
req->num_vecs = num_vecs;
req->cb = xs_wake_up;
msg.tx_id = t.id;
msg.type = type;
msg.len = 0;
for (i = 0; i < num_vecs; i++)
msg.len += iovec[i].iov_len;
xs_send(req, &msg);
ret = xs_wait_for_reply(req, &msg);
if (len)
*len = msg.len;
if (IS_ERR(ret))
return ret;
if (msg.type == XS_ERROR) {
err = get_error(ret);
kfree(ret);
return ERR_PTR(-err);
}
if (msg.type != type) {
pr_warn_ratelimited("unexpected type [%d], expected [%d]\n",
msg.type, type);
kfree(ret);
return ERR_PTR(-EINVAL);
}
return ret;
}
static void *xs_single(struct xenbus_transaction t,
enum xsd_sockmsg_type type,
const char *string,
unsigned int *len)
{
struct kvec iovec;
iovec.iov_base = (void *)string;
iovec.iov_len = strlen(string) + 1;
return xs_talkv(t, type, &iovec, 1, len);
}
static int xs_error(char *reply)
{
if (IS_ERR(reply))
return PTR_ERR(reply);
kfree(reply);
return 0;
}
static unsigned int count_strings(const char *strings, unsigned int len)
{
unsigned int num;
const char *p;
for (p = strings, num = 0; p < strings + len; p += strlen(p) + 1)
num++;
return num;
}
static char *join(const char *dir, const char *name)
{
char *buffer;
if (strlen(name) == 0)
buffer = kasprintf(GFP_NOIO | __GFP_HIGH, "%s", dir);
else
buffer = kasprintf(GFP_NOIO | __GFP_HIGH, "%s/%s", dir, name);
return (!buffer) ? ERR_PTR(-ENOMEM) : buffer;
}
static char **split(char *strings, unsigned int len, unsigned int *num)
{
char *p, **ret;
*num = count_strings(strings, len);
ret = kmalloc(*num * sizeof(char *) + len, GFP_NOIO | __GFP_HIGH);
if (!ret) {
kfree(strings);
return ERR_PTR(-ENOMEM);
}
memcpy(&ret[*num], strings, len);
kfree(strings);
strings = (char *)&ret[*num];
for (p = strings, *num = 0; p < strings + len; p += strlen(p) + 1)
ret[(*num)++] = p;
return ret;
}
char **xenbus_directory(struct xenbus_transaction t,
const char *dir, const char *node, unsigned int *num)
{
char *strings, *path;
unsigned int len;
path = join(dir, node);
if (IS_ERR(path))
return (char **)path;
strings = xs_single(t, XS_DIRECTORY, path, &len);
kfree(path);
if (IS_ERR(strings))
return (char **)strings;
return split(strings, len, num);
}
int xenbus_exists(struct xenbus_transaction t,
const char *dir, const char *node)
{
char **d;
int dir_n;
d = xenbus_directory(t, dir, node, &dir_n);
if (IS_ERR(d))
return 0;
kfree(d);
return 1;
}
void *xenbus_read(struct xenbus_transaction t,
const char *dir, const char *node, unsigned int *len)
{
char *path;
void *ret;
path = join(dir, node);
if (IS_ERR(path))
return (void *)path;
ret = xs_single(t, XS_READ, path, len);
kfree(path);
return ret;
}
int xenbus_write(struct xenbus_transaction t,
const char *dir, const char *node, const char *string)
{
const char *path;
struct kvec iovec[2];
int ret;
path = join(dir, node);
if (IS_ERR(path))
return PTR_ERR(path);
iovec[0].iov_base = (void *)path;
iovec[0].iov_len = strlen(path) + 1;
iovec[1].iov_base = (void *)string;
iovec[1].iov_len = strlen(string);
ret = xs_error(xs_talkv(t, XS_WRITE, iovec, ARRAY_SIZE(iovec), NULL));
kfree(path);
return ret;
}
int xenbus_mkdir(struct xenbus_transaction t,
const char *dir, const char *node)
{
char *path;
int ret;
path = join(dir, node);
if (IS_ERR(path))
return PTR_ERR(path);
ret = xs_error(xs_single(t, XS_MKDIR, path, NULL));
kfree(path);
return ret;
}
int xenbus_rm(struct xenbus_transaction t, const char *dir, const char *node)
{
char *path;
int ret;
path = join(dir, node);
if (IS_ERR(path))
return PTR_ERR(path);
ret = xs_error(xs_single(t, XS_RM, path, NULL));
kfree(path);
return ret;
}
int xenbus_transaction_start(struct xenbus_transaction *t)
{
char *id_str;
id_str = xs_single(XBT_NIL, XS_TRANSACTION_START, "", NULL);
if (IS_ERR(id_str))
return PTR_ERR(id_str);
t->id = simple_strtoul(id_str, NULL, 0);
kfree(id_str);
return 0;
}
int xenbus_transaction_end(struct xenbus_transaction t, int abort)
{
char abortstr[2];
if (abort)
strcpy(abortstr, "F");
else
strcpy(abortstr, "T");
return xs_error(xs_single(t, XS_TRANSACTION_END, abortstr, NULL));
}
int xenbus_scanf(struct xenbus_transaction t,
const char *dir, const char *node, const char *fmt, ...)
{
va_list ap;
int ret;
char *val;
val = xenbus_read(t, dir, node, NULL);
if (IS_ERR(val))
return PTR_ERR(val);
va_start(ap, fmt);
ret = vsscanf(val, fmt, ap);
va_end(ap);
kfree(val);
if (ret == 0)
return -ERANGE;
return ret;
}
unsigned int xenbus_read_unsigned(const char *dir, const char *node,
unsigned int default_val)
{
unsigned int val;
int ret;
ret = xenbus_scanf(XBT_NIL, dir, node, "%u", &val);
if (ret <= 0)
val = default_val;
return val;
}
int xenbus_printf(struct xenbus_transaction t,
const char *dir, const char *node, const char *fmt, ...)
{
va_list ap;
int ret;
char *buf;
va_start(ap, fmt);
buf = kvasprintf(GFP_NOIO | __GFP_HIGH, fmt, ap);
va_end(ap);
if (!buf)
return -ENOMEM;
ret = xenbus_write(t, dir, node, buf);
kfree(buf);
return ret;
}
int xenbus_gather(struct xenbus_transaction t, const char *dir, ...)
{
va_list ap;
const char *name;
int ret = 0;
va_start(ap, dir);
while (ret == 0 && (name = va_arg(ap, char *)) != NULL) {
const char *fmt = va_arg(ap, char *);
void *result = va_arg(ap, void *);
char *p;
p = xenbus_read(t, dir, name, NULL);
if (IS_ERR(p)) {
ret = PTR_ERR(p);
break;
}
if (fmt) {
if (sscanf(p, fmt, result) == 0)
ret = -EINVAL;
kfree(p);
} else
*(char **)result = p;
}
va_end(ap);
return ret;
}
static int xs_watch(const char *path, const char *token)
{
struct kvec iov[2];
iov[0].iov_base = (void *)path;
iov[0].iov_len = strlen(path) + 1;
iov[1].iov_base = (void *)token;
iov[1].iov_len = strlen(token) + 1;
return xs_error(xs_talkv(XBT_NIL, XS_WATCH, iov,
ARRAY_SIZE(iov), NULL));
}
static int xs_unwatch(const char *path, const char *token)
{
struct kvec iov[2];
iov[0].iov_base = (char *)path;
iov[0].iov_len = strlen(path) + 1;
iov[1].iov_base = (char *)token;
iov[1].iov_len = strlen(token) + 1;
return xs_error(xs_talkv(XBT_NIL, XS_UNWATCH, iov,
ARRAY_SIZE(iov), NULL));
}
static struct xenbus_watch *find_watch(const char *token)
{
struct xenbus_watch *i, *cmp;
cmp = (void *)simple_strtoul(token, NULL, 16);
list_for_each_entry(i, &watches, list)
if (i == cmp)
return i;
return NULL;
}
int xs_watch_msg(struct xs_watch_event *event)
{
if (count_strings(event->body, event->len) != 2) {
kfree(event);
return -EINVAL;
}
event->path = (const char *)event->body;
event->token = (const char *)strchr(event->body, '\0') + 1;
spin_lock(&watches_lock);
event->handle = find_watch(event->token);
if (event->handle != NULL) {
spin_lock(&watch_events_lock);
list_add_tail(&event->list, &watch_events);
wake_up(&watch_events_waitq);
spin_unlock(&watch_events_lock);
} else
kfree(event);
spin_unlock(&watches_lock);
return 0;
}
static bool xen_strict_xenbus_quirk(void)
{
#ifdef CONFIG_X86
uint32_t eax, ebx, ecx, edx, base;
base = xen_cpuid_base();
cpuid(base + 1, &eax, &ebx, &ecx, &edx);
if ((eax >> 16) < 4)
return true;
#endif
return false;
}
static void xs_reset_watches(void)
{
int err;
if (!xen_hvm_domain() || xen_initial_domain())
return;
if (xen_strict_xenbus_quirk())
return;
if (!xenbus_read_unsigned("control",
"platform-feature-xs_reset_watches", 0))
return;
err = xs_error(xs_single(XBT_NIL, XS_RESET_WATCHES, "", NULL));
if (err && err != -EEXIST)
pr_warn("xs_reset_watches failed: %d\n", err);
}
int register_xenbus_watch(struct xenbus_watch *watch)
{
char token[sizeof(watch) * 2 + 1];
int err;
sprintf(token, "%lX", (long)watch);
down_read(&xs_watch_rwsem);
spin_lock(&watches_lock);
BUG_ON(find_watch(token));
list_add(&watch->list, &watches);
spin_unlock(&watches_lock);
err = xs_watch(watch->node, token);
if (err) {
spin_lock(&watches_lock);
list_del(&watch->list);
spin_unlock(&watches_lock);
}
up_read(&xs_watch_rwsem);
return err;
}
void unregister_xenbus_watch(struct xenbus_watch *watch)
{
struct xs_watch_event *event, *tmp;
char token[sizeof(watch) * 2 + 1];
int err;
sprintf(token, "%lX", (long)watch);
down_read(&xs_watch_rwsem);
spin_lock(&watches_lock);
BUG_ON(!find_watch(token));
list_del(&watch->list);
spin_unlock(&watches_lock);
err = xs_unwatch(watch->node, token);
if (err)
pr_warn("Failed to release watch %s: %i\n", watch->node, err);
up_read(&xs_watch_rwsem);
if (current->pid != xenwatch_pid)
mutex_lock(&xenwatch_mutex);
spin_lock(&watch_events_lock);
list_for_each_entry_safe(event, tmp, &watch_events, list) {
if (event->handle != watch)
continue;
list_del(&event->list);
kfree(event);
}
spin_unlock(&watch_events_lock);
if (current->pid != xenwatch_pid)
mutex_unlock(&xenwatch_mutex);
}
void xs_suspend(void)
{
xs_suspend_enter();
down_write(&xs_watch_rwsem);
mutex_lock(&xs_response_mutex);
}
void xs_resume(void)
{
struct xenbus_watch *watch;
char token[sizeof(watch) * 2 + 1];
xb_init_comms();
mutex_unlock(&xs_response_mutex);
xs_suspend_exit();
list_for_each_entry(watch, &watches, list) {
sprintf(token, "%lX", (long)watch);
xs_watch(watch->node, token);
}
up_write(&xs_watch_rwsem);
}
void xs_suspend_cancel(void)
{
mutex_unlock(&xs_response_mutex);
up_write(&xs_watch_rwsem);
xs_suspend_exit();
}
static int xenwatch_thread(void *unused)
{
struct list_head *ent;
struct xs_watch_event *event;
for (;;) {
wait_event_interruptible(watch_events_waitq,
!list_empty(&watch_events));
if (kthread_should_stop())
break;
mutex_lock(&xenwatch_mutex);
spin_lock(&watch_events_lock);
ent = watch_events.next;
if (ent != &watch_events)
list_del(ent);
spin_unlock(&watch_events_lock);
if (ent != &watch_events) {
event = list_entry(ent, struct xs_watch_event, list);
event->handle->callback(event->handle, event->path,
event->token);
kfree(event);
}
mutex_unlock(&xenwatch_mutex);
}
return 0;
}
static int xs_reboot_notify(struct notifier_block *nb,
unsigned long code, void *unused)
{
struct xb_req_data *req;
mutex_lock(&xb_write_mutex);
list_for_each_entry(req, &xs_reply_list, list)
wake_up(&req->wq);
list_for_each_entry(req, &xb_write_list, list)
wake_up(&req->wq);
mutex_unlock(&xb_write_mutex);
return NOTIFY_DONE;
}
int xs_init(void)
{
int err;
struct task_struct *task;
register_reboot_notifier(&xs_reboot_nb);
err = xb_init_comms();
if (err)
return err;
task = kthread_run(xenwatch_thread, NULL, "xenwatch");
if (IS_ERR(task))
return PTR_ERR(task);
xenwatch_pid = task->pid;
xs_reset_watches();
return 0;
}
