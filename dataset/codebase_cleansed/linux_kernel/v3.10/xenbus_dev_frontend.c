static ssize_t xenbus_file_read(struct file *filp,
char __user *ubuf,
size_t len, loff_t *ppos)
{
struct xenbus_file_priv *u = filp->private_data;
struct read_buffer *rb;
unsigned i;
int ret;
mutex_lock(&u->reply_mutex);
again:
while (list_empty(&u->read_buffers)) {
mutex_unlock(&u->reply_mutex);
if (filp->f_flags & O_NONBLOCK)
return -EAGAIN;
ret = wait_event_interruptible(u->read_waitq,
!list_empty(&u->read_buffers));
if (ret)
return ret;
mutex_lock(&u->reply_mutex);
}
rb = list_entry(u->read_buffers.next, struct read_buffer, list);
i = 0;
while (i < len) {
unsigned sz = min((unsigned)len - i, rb->len - rb->cons);
ret = copy_to_user(ubuf + i, &rb->msg[rb->cons], sz);
i += sz - ret;
rb->cons += sz - ret;
if (ret != 0) {
if (i == 0)
i = -EFAULT;
goto out;
}
if (rb->cons == rb->len) {
list_del(&rb->list);
kfree(rb);
if (list_empty(&u->read_buffers))
break;
rb = list_entry(u->read_buffers.next,
struct read_buffer, list);
}
}
if (i == 0)
goto again;
out:
mutex_unlock(&u->reply_mutex);
return i;
}
static int queue_reply(struct list_head *queue, const void *data, size_t len)
{
struct read_buffer *rb;
if (len == 0)
return 0;
rb = kmalloc(sizeof(*rb) + len, GFP_KERNEL);
if (rb == NULL)
return -ENOMEM;
rb->cons = 0;
rb->len = len;
memcpy(rb->msg, data, len);
list_add_tail(&rb->list, queue);
return 0;
}
static void queue_cleanup(struct list_head *list)
{
struct read_buffer *rb;
while (!list_empty(list)) {
rb = list_entry(list->next, struct read_buffer, list);
list_del(list->next);
kfree(rb);
}
}
static void free_watch_adapter(struct watch_adapter *watch)
{
kfree(watch->watch.node);
kfree(watch->token);
kfree(watch);
}
static struct watch_adapter *alloc_watch_adapter(const char *path,
const char *token)
{
struct watch_adapter *watch;
watch = kzalloc(sizeof(*watch), GFP_KERNEL);
if (watch == NULL)
goto out_fail;
watch->watch.node = kstrdup(path, GFP_KERNEL);
if (watch->watch.node == NULL)
goto out_free;
watch->token = kstrdup(token, GFP_KERNEL);
if (watch->token == NULL)
goto out_free;
return watch;
out_free:
free_watch_adapter(watch);
out_fail:
return NULL;
}
static void watch_fired(struct xenbus_watch *watch,
const char **vec,
unsigned int len)
{
struct watch_adapter *adap;
struct xsd_sockmsg hdr;
const char *path, *token;
int path_len, tok_len, body_len, data_len = 0;
int ret;
LIST_HEAD(staging_q);
adap = container_of(watch, struct watch_adapter, watch);
path = vec[XS_WATCH_PATH];
token = adap->token;
path_len = strlen(path) + 1;
tok_len = strlen(token) + 1;
if (len > 2)
data_len = vec[len] - vec[2] + 1;
body_len = path_len + tok_len + data_len;
hdr.type = XS_WATCH_EVENT;
hdr.len = body_len;
mutex_lock(&adap->dev_data->reply_mutex);
ret = queue_reply(&staging_q, &hdr, sizeof(hdr));
if (!ret)
ret = queue_reply(&staging_q, path, path_len);
if (!ret)
ret = queue_reply(&staging_q, token, tok_len);
if (!ret && len > 2)
ret = queue_reply(&staging_q, vec[2], data_len);
if (!ret) {
list_splice_tail(&staging_q, &adap->dev_data->read_buffers);
wake_up(&adap->dev_data->read_waitq);
} else
queue_cleanup(&staging_q);
mutex_unlock(&adap->dev_data->reply_mutex);
}
static int xenbus_write_transaction(unsigned msg_type,
struct xenbus_file_priv *u)
{
int rc;
void *reply;
struct xenbus_transaction_holder *trans = NULL;
LIST_HEAD(staging_q);
if (msg_type == XS_TRANSACTION_START) {
trans = kmalloc(sizeof(*trans), GFP_KERNEL);
if (!trans) {
rc = -ENOMEM;
goto out;
}
}
reply = xenbus_dev_request_and_reply(&u->u.msg);
if (IS_ERR(reply)) {
kfree(trans);
rc = PTR_ERR(reply);
goto out;
}
if (msg_type == XS_TRANSACTION_START) {
trans->handle.id = simple_strtoul(reply, NULL, 0);
list_add(&trans->list, &u->transactions);
} else if (msg_type == XS_TRANSACTION_END) {
list_for_each_entry(trans, &u->transactions, list)
if (trans->handle.id == u->u.msg.tx_id)
break;
BUG_ON(&trans->list == &u->transactions);
list_del(&trans->list);
kfree(trans);
}
mutex_lock(&u->reply_mutex);
rc = queue_reply(&staging_q, &u->u.msg, sizeof(u->u.msg));
if (!rc)
rc = queue_reply(&staging_q, reply, u->u.msg.len);
if (!rc) {
list_splice_tail(&staging_q, &u->read_buffers);
wake_up(&u->read_waitq);
} else {
queue_cleanup(&staging_q);
}
mutex_unlock(&u->reply_mutex);
kfree(reply);
out:
return rc;
}
static int xenbus_write_watch(unsigned msg_type, struct xenbus_file_priv *u)
{
struct watch_adapter *watch, *tmp_watch;
char *path, *token;
int err, rc;
LIST_HEAD(staging_q);
path = u->u.buffer + sizeof(u->u.msg);
token = memchr(path, 0, u->u.msg.len);
if (token == NULL) {
rc = -EILSEQ;
goto out;
}
token++;
if (memchr(token, 0, u->u.msg.len - (token - path)) == NULL) {
rc = -EILSEQ;
goto out;
}
if (msg_type == XS_WATCH) {
watch = alloc_watch_adapter(path, token);
if (watch == NULL) {
rc = -ENOMEM;
goto out;
}
watch->watch.callback = watch_fired;
watch->dev_data = u;
err = register_xenbus_watch(&watch->watch);
if (err) {
free_watch_adapter(watch);
rc = err;
goto out;
}
list_add(&watch->list, &u->watches);
} else {
list_for_each_entry_safe(watch, tmp_watch, &u->watches, list) {
if (!strcmp(watch->token, token) &&
!strcmp(watch->watch.node, path)) {
unregister_xenbus_watch(&watch->watch);
list_del(&watch->list);
free_watch_adapter(watch);
break;
}
}
}
{
struct {
struct xsd_sockmsg hdr;
char body[3];
} __packed reply = {
{
.type = msg_type,
.len = sizeof(reply.body)
},
"OK"
};
mutex_lock(&u->reply_mutex);
rc = queue_reply(&u->read_buffers, &reply, sizeof(reply));
wake_up(&u->read_waitq);
mutex_unlock(&u->reply_mutex);
}
out:
return rc;
}
static ssize_t xenbus_file_write(struct file *filp,
const char __user *ubuf,
size_t len, loff_t *ppos)
{
struct xenbus_file_priv *u = filp->private_data;
uint32_t msg_type;
int rc = len;
int ret;
LIST_HEAD(staging_q);
mutex_lock(&u->msgbuffer_mutex);
if (len == 0)
goto out;
if (len > sizeof(u->u.buffer) - u->len) {
u->len = 0;
rc = -EINVAL;
goto out;
}
ret = copy_from_user(u->u.buffer + u->len, ubuf, len);
if (ret != 0) {
rc = -EFAULT;
goto out;
}
len -= ret;
rc = len;
u->len += len;
if (u->len < sizeof(u->u.msg))
goto out;
if ((sizeof(u->u.msg) + u->u.msg.len) > sizeof(u->u.buffer)) {
rc = -E2BIG;
u->len = 0;
goto out;
}
if (u->len < (sizeof(u->u.msg) + u->u.msg.len))
goto out;
msg_type = u->u.msg.type;
switch (msg_type) {
case XS_WATCH:
case XS_UNWATCH:
ret = xenbus_write_watch(msg_type, u);
break;
default:
ret = xenbus_write_transaction(msg_type, u);
break;
}
if (ret != 0)
rc = ret;
u->len = 0;
out:
mutex_unlock(&u->msgbuffer_mutex);
return rc;
}
static int xenbus_file_open(struct inode *inode, struct file *filp)
{
struct xenbus_file_priv *u;
if (xen_store_evtchn == 0)
return -ENOENT;
nonseekable_open(inode, filp);
u = kzalloc(sizeof(*u), GFP_KERNEL);
if (u == NULL)
return -ENOMEM;
INIT_LIST_HEAD(&u->transactions);
INIT_LIST_HEAD(&u->watches);
INIT_LIST_HEAD(&u->read_buffers);
init_waitqueue_head(&u->read_waitq);
mutex_init(&u->reply_mutex);
mutex_init(&u->msgbuffer_mutex);
filp->private_data = u;
return 0;
}
static int xenbus_file_release(struct inode *inode, struct file *filp)
{
struct xenbus_file_priv *u = filp->private_data;
struct xenbus_transaction_holder *trans, *tmp;
struct watch_adapter *watch, *tmp_watch;
struct read_buffer *rb, *tmp_rb;
list_for_each_entry_safe(trans, tmp, &u->transactions, list) {
xenbus_transaction_end(trans->handle, 1);
list_del(&trans->list);
kfree(trans);
}
list_for_each_entry_safe(watch, tmp_watch, &u->watches, list) {
unregister_xenbus_watch(&watch->watch);
list_del(&watch->list);
free_watch_adapter(watch);
}
list_for_each_entry_safe(rb, tmp_rb, &u->read_buffers, list) {
list_del(&rb->list);
kfree(rb);
}
kfree(u);
return 0;
}
static unsigned int xenbus_file_poll(struct file *file, poll_table *wait)
{
struct xenbus_file_priv *u = file->private_data;
poll_wait(file, &u->read_waitq, wait);
if (!list_empty(&u->read_buffers))
return POLLIN | POLLRDNORM;
return 0;
}
static int __init xenbus_init(void)
{
int err;
if (!xen_domain())
return -ENODEV;
err = misc_register(&xenbus_dev);
if (err)
printk(KERN_ERR "Could not register xenbus frontend device\n");
return err;
}
static void __exit xenbus_exit(void)
{
misc_deregister(&xenbus_dev);
}
