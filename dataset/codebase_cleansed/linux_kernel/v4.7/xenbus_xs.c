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
static void *read_reply(enum xsd_sockmsg_type *type, unsigned int *len)
{
struct xs_stored_msg *msg;
char *body;
spin_lock(&xs_state.reply_lock);
while (list_empty(&xs_state.reply_list)) {
spin_unlock(&xs_state.reply_lock);
if (xenbus_ok())
wait_event_timeout(xs_state.reply_waitq,
!list_empty(&xs_state.reply_list),
msecs_to_jiffies(500));
else {
return ERR_PTR(-EIO);
}
spin_lock(&xs_state.reply_lock);
}
msg = list_entry(xs_state.reply_list.next,
struct xs_stored_msg, list);
list_del(&msg->list);
spin_unlock(&xs_state.reply_lock);
*type = msg->hdr.type;
if (len)
*len = msg->hdr.len;
body = msg->u.reply.body;
kfree(msg);
return body;
}
static void transaction_start(void)
{
mutex_lock(&xs_state.transaction_mutex);
atomic_inc(&xs_state.transaction_count);
mutex_unlock(&xs_state.transaction_mutex);
}
static void transaction_end(void)
{
if (atomic_dec_and_test(&xs_state.transaction_count))
wake_up(&xs_state.transaction_wq);
}
static void transaction_suspend(void)
{
mutex_lock(&xs_state.transaction_mutex);
wait_event(xs_state.transaction_wq,
atomic_read(&xs_state.transaction_count) == 0);
}
static void transaction_resume(void)
{
mutex_unlock(&xs_state.transaction_mutex);
}
void *xenbus_dev_request_and_reply(struct xsd_sockmsg *msg)
{
void *ret;
enum xsd_sockmsg_type type = msg->type;
int err;
if (type == XS_TRANSACTION_START)
transaction_start();
mutex_lock(&xs_state.request_mutex);
err = xb_write(msg, sizeof(*msg) + msg->len);
if (err) {
msg->type = XS_ERROR;
ret = ERR_PTR(err);
} else
ret = read_reply(&msg->type, &msg->len);
mutex_unlock(&xs_state.request_mutex);
if ((msg->type == XS_TRANSACTION_END) ||
((type == XS_TRANSACTION_START) && (msg->type == XS_ERROR)))
transaction_end();
return ret;
}
static void *xs_talkv(struct xenbus_transaction t,
enum xsd_sockmsg_type type,
const struct kvec *iovec,
unsigned int num_vecs,
unsigned int *len)
{
struct xsd_sockmsg msg;
void *ret = NULL;
unsigned int i;
int err;
msg.tx_id = t.id;
msg.req_id = 0;
msg.type = type;
msg.len = 0;
for (i = 0; i < num_vecs; i++)
msg.len += iovec[i].iov_len;
mutex_lock(&xs_state.request_mutex);
err = xb_write(&msg, sizeof(msg));
if (err) {
mutex_unlock(&xs_state.request_mutex);
return ERR_PTR(err);
}
for (i = 0; i < num_vecs; i++) {
err = xb_write(iovec[i].iov_base, iovec[i].iov_len);
if (err) {
mutex_unlock(&xs_state.request_mutex);
return ERR_PTR(err);
}
}
ret = read_reply(&msg.type, len);
mutex_unlock(&xs_state.request_mutex);
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
transaction_start();
id_str = xs_single(XBT_NIL, XS_TRANSACTION_START, "", NULL);
if (IS_ERR(id_str)) {
transaction_end();
return PTR_ERR(id_str);
}
t->id = simple_strtoul(id_str, NULL, 0);
kfree(id_str);
return 0;
}
int xenbus_transaction_end(struct xenbus_transaction t, int abort)
{
char abortstr[2];
int err;
if (abort)
strcpy(abortstr, "F");
else
strcpy(abortstr, "T");
err = xs_error(xs_single(t, XS_TRANSACTION_END, abortstr, NULL));
transaction_end();
return err;
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
int err, supported = 0;
if (!xen_hvm_domain() || xen_initial_domain())
return;
if (xen_strict_xenbus_quirk())
return;
err = xenbus_scanf(XBT_NIL, "control",
"platform-feature-xs_reset_watches", "%d", &supported);
if (err != 1 || !supported)
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
down_read(&xs_state.watch_mutex);
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
up_read(&xs_state.watch_mutex);
return err;
}
void unregister_xenbus_watch(struct xenbus_watch *watch)
{
struct xs_stored_msg *msg, *tmp;
char token[sizeof(watch) * 2 + 1];
int err;
sprintf(token, "%lX", (long)watch);
down_read(&xs_state.watch_mutex);
spin_lock(&watches_lock);
BUG_ON(!find_watch(token));
list_del(&watch->list);
spin_unlock(&watches_lock);
err = xs_unwatch(watch->node, token);
if (err)
pr_warn("Failed to release watch %s: %i\n", watch->node, err);
up_read(&xs_state.watch_mutex);
if (current->pid != xenwatch_pid)
mutex_lock(&xenwatch_mutex);
spin_lock(&watch_events_lock);
list_for_each_entry_safe(msg, tmp, &watch_events, list) {
if (msg->u.watch.handle != watch)
continue;
list_del(&msg->list);
kfree(msg->u.watch.vec);
kfree(msg);
}
spin_unlock(&watch_events_lock);
if (current->pid != xenwatch_pid)
mutex_unlock(&xenwatch_mutex);
}
void xs_suspend(void)
{
transaction_suspend();
down_write(&xs_state.watch_mutex);
mutex_lock(&xs_state.request_mutex);
mutex_lock(&xs_state.response_mutex);
}
void xs_resume(void)
{
struct xenbus_watch *watch;
char token[sizeof(watch) * 2 + 1];
xb_init_comms();
mutex_unlock(&xs_state.response_mutex);
mutex_unlock(&xs_state.request_mutex);
transaction_resume();
list_for_each_entry(watch, &watches, list) {
sprintf(token, "%lX", (long)watch);
xs_watch(watch->node, token);
}
up_write(&xs_state.watch_mutex);
}
void xs_suspend_cancel(void)
{
mutex_unlock(&xs_state.response_mutex);
mutex_unlock(&xs_state.request_mutex);
up_write(&xs_state.watch_mutex);
mutex_unlock(&xs_state.transaction_mutex);
}
static int xenwatch_thread(void *unused)
{
struct list_head *ent;
struct xs_stored_msg *msg;
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
msg = list_entry(ent, struct xs_stored_msg, list);
msg->u.watch.handle->callback(
msg->u.watch.handle,
(const char **)msg->u.watch.vec,
msg->u.watch.vec_size);
kfree(msg->u.watch.vec);
kfree(msg);
}
mutex_unlock(&xenwatch_mutex);
}
return 0;
}
static int process_msg(void)
{
struct xs_stored_msg *msg;
char *body;
int err;
for (;;) {
err = xb_wait_for_data_to_read();
if (err)
return err;
mutex_lock(&xs_state.response_mutex);
if (xb_data_to_read())
break;
mutex_unlock(&xs_state.response_mutex);
}
msg = kmalloc(sizeof(*msg), GFP_NOIO | __GFP_HIGH);
if (msg == NULL) {
err = -ENOMEM;
goto out;
}
err = xb_read(&msg->hdr, sizeof(msg->hdr));
if (err) {
kfree(msg);
goto out;
}
if (msg->hdr.len > XENSTORE_PAYLOAD_MAX) {
kfree(msg);
err = -EINVAL;
goto out;
}
body = kmalloc(msg->hdr.len + 1, GFP_NOIO | __GFP_HIGH);
if (body == NULL) {
kfree(msg);
err = -ENOMEM;
goto out;
}
err = xb_read(body, msg->hdr.len);
if (err) {
kfree(body);
kfree(msg);
goto out;
}
body[msg->hdr.len] = '\0';
if (msg->hdr.type == XS_WATCH_EVENT) {
msg->u.watch.vec = split(body, msg->hdr.len,
&msg->u.watch.vec_size);
if (IS_ERR(msg->u.watch.vec)) {
err = PTR_ERR(msg->u.watch.vec);
kfree(msg);
goto out;
}
spin_lock(&watches_lock);
msg->u.watch.handle = find_watch(
msg->u.watch.vec[XS_WATCH_TOKEN]);
if (msg->u.watch.handle != NULL) {
spin_lock(&watch_events_lock);
list_add_tail(&msg->list, &watch_events);
wake_up(&watch_events_waitq);
spin_unlock(&watch_events_lock);
} else {
kfree(msg->u.watch.vec);
kfree(msg);
}
spin_unlock(&watches_lock);
} else {
msg->u.reply.body = body;
spin_lock(&xs_state.reply_lock);
list_add_tail(&msg->list, &xs_state.reply_list);
spin_unlock(&xs_state.reply_lock);
wake_up(&xs_state.reply_waitq);
}
out:
mutex_unlock(&xs_state.response_mutex);
return err;
}
static int xenbus_thread(void *unused)
{
int err;
for (;;) {
err = process_msg();
if (err)
pr_warn("error %d while reading message\n", err);
if (kthread_should_stop())
break;
}
return 0;
}
int xs_init(void)
{
int err;
struct task_struct *task;
INIT_LIST_HEAD(&xs_state.reply_list);
spin_lock_init(&xs_state.reply_lock);
init_waitqueue_head(&xs_state.reply_waitq);
mutex_init(&xs_state.request_mutex);
mutex_init(&xs_state.response_mutex);
mutex_init(&xs_state.transaction_mutex);
init_rwsem(&xs_state.watch_mutex);
atomic_set(&xs_state.transaction_count, 0);
init_waitqueue_head(&xs_state.transaction_wq);
err = xb_init_comms();
if (err)
return err;
task = kthread_run(xenwatch_thread, NULL, "xenwatch");
if (IS_ERR(task))
return PTR_ERR(task);
xenwatch_pid = task->pid;
task = kthread_run(xenbus_thread, NULL, "xenbus");
if (IS_ERR(task))
return PTR_ERR(task);
xs_reset_watches();
return 0;
}
