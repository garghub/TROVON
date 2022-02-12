static inline struct device *nbd_to_dev(struct nbd_device *nbd)
{
return disk_to_dev(nbd->disk);
}
static bool nbd_is_connected(struct nbd_device *nbd)
{
return !!nbd->task_recv;
}
static const char *nbdcmd_to_ascii(int cmd)
{
switch (cmd) {
case NBD_CMD_READ: return "read";
case NBD_CMD_WRITE: return "write";
case NBD_CMD_DISC: return "disconnect";
case NBD_CMD_FLUSH: return "flush";
case NBD_CMD_TRIM: return "trim/discard";
}
return "invalid";
}
static int nbd_size_clear(struct nbd_device *nbd, struct block_device *bdev)
{
bdev->bd_inode->i_size = 0;
set_capacity(nbd->disk, 0);
kobject_uevent(&nbd_to_dev(nbd)->kobj, KOBJ_CHANGE);
return 0;
}
static void nbd_size_update(struct nbd_device *nbd, struct block_device *bdev)
{
if (!nbd_is_connected(nbd))
return;
bdev->bd_inode->i_size = nbd->bytesize;
set_capacity(nbd->disk, nbd->bytesize >> 9);
kobject_uevent(&nbd_to_dev(nbd)->kobj, KOBJ_CHANGE);
}
static int nbd_size_set(struct nbd_device *nbd, struct block_device *bdev,
int blocksize, int nr_blocks)
{
int ret;
ret = set_blocksize(bdev, blocksize);
if (ret)
return ret;
nbd->blksize = blocksize;
nbd->bytesize = (loff_t)blocksize * (loff_t)nr_blocks;
nbd_size_update(nbd, bdev);
return 0;
}
static void nbd_end_request(struct nbd_device *nbd, struct request *req)
{
int error = req->errors ? -EIO : 0;
struct request_queue *q = req->q;
unsigned long flags;
dev_dbg(nbd_to_dev(nbd), "request %p: %s\n", req,
error ? "failed" : "done");
spin_lock_irqsave(q->queue_lock, flags);
__blk_end_request_all(req, error);
spin_unlock_irqrestore(q->queue_lock, flags);
}
static void sock_shutdown(struct nbd_device *nbd)
{
spin_lock_irq(&nbd->sock_lock);
if (!nbd->sock) {
spin_unlock_irq(&nbd->sock_lock);
return;
}
dev_warn(disk_to_dev(nbd->disk), "shutting down socket\n");
kernel_sock_shutdown(nbd->sock, SHUT_RDWR);
sockfd_put(nbd->sock);
nbd->sock = NULL;
spin_unlock_irq(&nbd->sock_lock);
del_timer(&nbd->timeout_timer);
}
static void nbd_xmit_timeout(unsigned long arg)
{
struct nbd_device *nbd = (struct nbd_device *)arg;
unsigned long flags;
if (list_empty(&nbd->queue_head))
return;
spin_lock_irqsave(&nbd->sock_lock, flags);
nbd->timedout = true;
if (nbd->sock)
kernel_sock_shutdown(nbd->sock, SHUT_RDWR);
spin_unlock_irqrestore(&nbd->sock_lock, flags);
dev_err(nbd_to_dev(nbd), "Connection timed out, shutting down connection\n");
}
static int sock_xmit(struct nbd_device *nbd, int send, void *buf, int size,
int msg_flags)
{
struct socket *sock = nbd->sock;
int result;
struct msghdr msg;
struct kvec iov;
unsigned long pflags = current->flags;
if (unlikely(!sock)) {
dev_err(disk_to_dev(nbd->disk),
"Attempted %s on closed socket in sock_xmit\n",
(send ? "send" : "recv"));
return -EINVAL;
}
current->flags |= PF_MEMALLOC;
do {
sock->sk->sk_allocation = GFP_NOIO | __GFP_MEMALLOC;
iov.iov_base = buf;
iov.iov_len = size;
msg.msg_name = NULL;
msg.msg_namelen = 0;
msg.msg_control = NULL;
msg.msg_controllen = 0;
msg.msg_flags = msg_flags | MSG_NOSIGNAL;
if (send)
result = kernel_sendmsg(sock, &msg, &iov, 1, size);
else
result = kernel_recvmsg(sock, &msg, &iov, 1, size,
msg.msg_flags);
if (result <= 0) {
if (result == 0)
result = -EPIPE;
break;
}
size -= result;
buf += result;
} while (size > 0);
tsk_restore_flags(current, pflags, PF_MEMALLOC);
if (!send && nbd->xmit_timeout)
mod_timer(&nbd->timeout_timer, jiffies + nbd->xmit_timeout);
return result;
}
static inline int sock_send_bvec(struct nbd_device *nbd, struct bio_vec *bvec,
int flags)
{
int result;
void *kaddr = kmap(bvec->bv_page);
result = sock_xmit(nbd, 1, kaddr + bvec->bv_offset,
bvec->bv_len, flags);
kunmap(bvec->bv_page);
return result;
}
static int nbd_send_req(struct nbd_device *nbd, struct request *req)
{
int result, flags;
struct nbd_request request;
unsigned long size = blk_rq_bytes(req);
u32 type;
if (req->cmd_type == REQ_TYPE_DRV_PRIV)
type = NBD_CMD_DISC;
else if (req->cmd_flags & REQ_DISCARD)
type = NBD_CMD_TRIM;
else if (req->cmd_flags & REQ_FLUSH)
type = NBD_CMD_FLUSH;
else if (rq_data_dir(req) == WRITE)
type = NBD_CMD_WRITE;
else
type = NBD_CMD_READ;
memset(&request, 0, sizeof(request));
request.magic = htonl(NBD_REQUEST_MAGIC);
request.type = htonl(type);
if (type != NBD_CMD_FLUSH && type != NBD_CMD_DISC) {
request.from = cpu_to_be64((u64)blk_rq_pos(req) << 9);
request.len = htonl(size);
}
memcpy(request.handle, &req, sizeof(req));
dev_dbg(nbd_to_dev(nbd), "request %p: sending control (%s@%llu,%uB)\n",
req, nbdcmd_to_ascii(type),
(unsigned long long)blk_rq_pos(req) << 9, blk_rq_bytes(req));
result = sock_xmit(nbd, 1, &request, sizeof(request),
(type == NBD_CMD_WRITE) ? MSG_MORE : 0);
if (result <= 0) {
dev_err(disk_to_dev(nbd->disk),
"Send control failed (result %d)\n", result);
return -EIO;
}
if (type == NBD_CMD_WRITE) {
struct req_iterator iter;
struct bio_vec bvec;
rq_for_each_segment(bvec, req, iter) {
flags = 0;
if (!rq_iter_last(bvec, iter))
flags = MSG_MORE;
dev_dbg(nbd_to_dev(nbd), "request %p: sending %d bytes data\n",
req, bvec.bv_len);
result = sock_send_bvec(nbd, &bvec, flags);
if (result <= 0) {
dev_err(disk_to_dev(nbd->disk),
"Send data failed (result %d)\n",
result);
return -EIO;
}
}
}
return 0;
}
static struct request *nbd_find_request(struct nbd_device *nbd,
struct request *xreq)
{
struct request *req, *tmp;
int err;
err = wait_event_interruptible(nbd->active_wq, nbd->active_req != xreq);
if (unlikely(err))
return ERR_PTR(err);
spin_lock(&nbd->queue_lock);
list_for_each_entry_safe(req, tmp, &nbd->queue_head, queuelist) {
if (req != xreq)
continue;
list_del_init(&req->queuelist);
spin_unlock(&nbd->queue_lock);
return req;
}
spin_unlock(&nbd->queue_lock);
return ERR_PTR(-ENOENT);
}
static inline int sock_recv_bvec(struct nbd_device *nbd, struct bio_vec *bvec)
{
int result;
void *kaddr = kmap(bvec->bv_page);
result = sock_xmit(nbd, 0, kaddr + bvec->bv_offset, bvec->bv_len,
MSG_WAITALL);
kunmap(bvec->bv_page);
return result;
}
static struct request *nbd_read_stat(struct nbd_device *nbd)
{
int result;
struct nbd_reply reply;
struct request *req;
reply.magic = 0;
result = sock_xmit(nbd, 0, &reply, sizeof(reply), MSG_WAITALL);
if (result <= 0) {
dev_err(disk_to_dev(nbd->disk),
"Receive control failed (result %d)\n", result);
return ERR_PTR(result);
}
if (ntohl(reply.magic) != NBD_REPLY_MAGIC) {
dev_err(disk_to_dev(nbd->disk), "Wrong magic (0x%lx)\n",
(unsigned long)ntohl(reply.magic));
return ERR_PTR(-EPROTO);
}
req = nbd_find_request(nbd, *(struct request **)reply.handle);
if (IS_ERR(req)) {
result = PTR_ERR(req);
if (result != -ENOENT)
return ERR_PTR(result);
dev_err(disk_to_dev(nbd->disk), "Unexpected reply (%p)\n",
reply.handle);
return ERR_PTR(-EBADR);
}
if (ntohl(reply.error)) {
dev_err(disk_to_dev(nbd->disk), "Other side returned error (%d)\n",
ntohl(reply.error));
req->errors++;
return req;
}
dev_dbg(nbd_to_dev(nbd), "request %p: got reply\n", req);
if (rq_data_dir(req) != WRITE) {
struct req_iterator iter;
struct bio_vec bvec;
rq_for_each_segment(bvec, req, iter) {
result = sock_recv_bvec(nbd, &bvec);
if (result <= 0) {
dev_err(disk_to_dev(nbd->disk), "Receive data failed (result %d)\n",
result);
req->errors++;
return req;
}
dev_dbg(nbd_to_dev(nbd), "request %p: got %d bytes data\n",
req, bvec.bv_len);
}
}
return req;
}
static ssize_t pid_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct gendisk *disk = dev_to_disk(dev);
struct nbd_device *nbd = (struct nbd_device *)disk->private_data;
return sprintf(buf, "%d\n", task_pid_nr(nbd->task_recv));
}
static int nbd_thread_recv(struct nbd_device *nbd, struct block_device *bdev)
{
struct request *req;
int ret;
BUG_ON(nbd->magic != NBD_MAGIC);
sk_set_memalloc(nbd->sock->sk);
nbd->task_recv = current;
ret = device_create_file(disk_to_dev(nbd->disk), &pid_attr);
if (ret) {
dev_err(disk_to_dev(nbd->disk), "device_create_file failed!\n");
nbd->task_recv = NULL;
return ret;
}
nbd_size_update(nbd, bdev);
while (1) {
req = nbd_read_stat(nbd);
if (IS_ERR(req)) {
ret = PTR_ERR(req);
break;
}
nbd_end_request(nbd, req);
}
nbd_size_clear(nbd, bdev);
device_remove_file(disk_to_dev(nbd->disk), &pid_attr);
nbd->task_recv = NULL;
return ret;
}
static void nbd_clear_que(struct nbd_device *nbd)
{
struct request *req;
BUG_ON(nbd->magic != NBD_MAGIC);
BUG_ON(nbd->sock);
BUG_ON(nbd->active_req);
while (!list_empty(&nbd->queue_head)) {
req = list_entry(nbd->queue_head.next, struct request,
queuelist);
list_del_init(&req->queuelist);
req->errors++;
nbd_end_request(nbd, req);
}
while (!list_empty(&nbd->waiting_queue)) {
req = list_entry(nbd->waiting_queue.next, struct request,
queuelist);
list_del_init(&req->queuelist);
req->errors++;
nbd_end_request(nbd, req);
}
dev_dbg(disk_to_dev(nbd->disk), "queue cleared\n");
}
static void nbd_handle_req(struct nbd_device *nbd, struct request *req)
{
if (req->cmd_type != REQ_TYPE_FS)
goto error_out;
if (rq_data_dir(req) == WRITE &&
(nbd->flags & NBD_FLAG_READ_ONLY)) {
dev_err(disk_to_dev(nbd->disk),
"Write on read-only\n");
goto error_out;
}
req->errors = 0;
mutex_lock(&nbd->tx_lock);
if (unlikely(!nbd->sock)) {
mutex_unlock(&nbd->tx_lock);
dev_err(disk_to_dev(nbd->disk),
"Attempted send on closed socket\n");
goto error_out;
}
nbd->active_req = req;
if (nbd->xmit_timeout && list_empty_careful(&nbd->queue_head))
mod_timer(&nbd->timeout_timer, jiffies + nbd->xmit_timeout);
if (nbd_send_req(nbd, req) != 0) {
dev_err(disk_to_dev(nbd->disk), "Request send failed\n");
req->errors++;
nbd_end_request(nbd, req);
} else {
spin_lock(&nbd->queue_lock);
list_add_tail(&req->queuelist, &nbd->queue_head);
spin_unlock(&nbd->queue_lock);
}
nbd->active_req = NULL;
mutex_unlock(&nbd->tx_lock);
wake_up_all(&nbd->active_wq);
return;
error_out:
req->errors++;
nbd_end_request(nbd, req);
}
static int nbd_thread_send(void *data)
{
struct nbd_device *nbd = data;
struct request *req;
nbd->task_send = current;
set_user_nice(current, MIN_NICE);
while (!kthread_should_stop() || !list_empty(&nbd->waiting_queue)) {
wait_event_interruptible(nbd->waiting_wq,
kthread_should_stop() ||
!list_empty(&nbd->waiting_queue));
if (list_empty(&nbd->waiting_queue))
continue;
spin_lock_irq(&nbd->queue_lock);
req = list_entry(nbd->waiting_queue.next, struct request,
queuelist);
list_del_init(&req->queuelist);
spin_unlock_irq(&nbd->queue_lock);
nbd_handle_req(nbd, req);
}
nbd->task_send = NULL;
return 0;
}
static void nbd_request_handler(struct request_queue *q)
__releases(q->queue_lock) __acquires(q->queue_lock)
{
struct request *req;
while ((req = blk_fetch_request(q)) != NULL) {
struct nbd_device *nbd;
spin_unlock_irq(q->queue_lock);
nbd = req->rq_disk->private_data;
BUG_ON(nbd->magic != NBD_MAGIC);
dev_dbg(nbd_to_dev(nbd), "request %p: dequeued (flags=%x)\n",
req, req->cmd_type);
if (unlikely(!nbd->sock)) {
dev_err_ratelimited(disk_to_dev(nbd->disk),
"Attempted send on closed socket\n");
req->errors++;
nbd_end_request(nbd, req);
spin_lock_irq(q->queue_lock);
continue;
}
spin_lock_irq(&nbd->queue_lock);
list_add_tail(&req->queuelist, &nbd->waiting_queue);
spin_unlock_irq(&nbd->queue_lock);
wake_up(&nbd->waiting_wq);
spin_lock_irq(q->queue_lock);
}
}
static int nbd_set_socket(struct nbd_device *nbd, struct socket *sock)
{
int ret = 0;
spin_lock_irq(&nbd->sock_lock);
if (nbd->sock) {
ret = -EBUSY;
goto out;
}
nbd->sock = sock;
out:
spin_unlock_irq(&nbd->sock_lock);
return ret;
}
static void nbd_reset(struct nbd_device *nbd)
{
nbd->disconnect = false;
nbd->timedout = false;
nbd->blksize = 1024;
nbd->bytesize = 0;
set_capacity(nbd->disk, 0);
nbd->flags = 0;
nbd->xmit_timeout = 0;
queue_flag_clear_unlocked(QUEUE_FLAG_DISCARD, nbd->disk->queue);
del_timer_sync(&nbd->timeout_timer);
}
static void nbd_bdev_reset(struct block_device *bdev)
{
set_device_ro(bdev, false);
bdev->bd_inode->i_size = 0;
if (max_part > 0) {
blkdev_reread_part(bdev);
bdev->bd_invalidated = 1;
}
}
static void nbd_parse_flags(struct nbd_device *nbd, struct block_device *bdev)
{
if (nbd->flags & NBD_FLAG_READ_ONLY)
set_device_ro(bdev, true);
if (nbd->flags & NBD_FLAG_SEND_TRIM)
queue_flag_set_unlocked(QUEUE_FLAG_DISCARD, nbd->disk->queue);
if (nbd->flags & NBD_FLAG_SEND_FLUSH)
blk_queue_flush(nbd->disk->queue, REQ_FLUSH);
else
blk_queue_flush(nbd->disk->queue, 0);
}
static int __nbd_ioctl(struct block_device *bdev, struct nbd_device *nbd,
unsigned int cmd, unsigned long arg)
{
switch (cmd) {
case NBD_DISCONNECT: {
struct request sreq;
dev_info(disk_to_dev(nbd->disk), "NBD_DISCONNECT\n");
if (!nbd->sock)
return -EINVAL;
mutex_unlock(&nbd->tx_lock);
fsync_bdev(bdev);
mutex_lock(&nbd->tx_lock);
blk_rq_init(NULL, &sreq);
sreq.cmd_type = REQ_TYPE_DRV_PRIV;
if (!nbd->sock)
return -EINVAL;
nbd->disconnect = true;
nbd_send_req(nbd, &sreq);
return 0;
}
case NBD_CLEAR_SOCK:
sock_shutdown(nbd);
nbd_clear_que(nbd);
BUG_ON(!list_empty(&nbd->queue_head));
BUG_ON(!list_empty(&nbd->waiting_queue));
kill_bdev(bdev);
return 0;
case NBD_SET_SOCK: {
int err;
struct socket *sock = sockfd_lookup(arg, &err);
if (!sock)
return err;
err = nbd_set_socket(nbd, sock);
if (!err && max_part)
bdev->bd_invalidated = 1;
return err;
}
case NBD_SET_BLKSIZE: {
loff_t bsize = div_s64(nbd->bytesize, arg);
return nbd_size_set(nbd, bdev, arg, bsize);
}
case NBD_SET_SIZE:
return nbd_size_set(nbd, bdev, nbd->blksize,
arg / nbd->blksize);
case NBD_SET_SIZE_BLOCKS:
return nbd_size_set(nbd, bdev, nbd->blksize, arg);
case NBD_SET_TIMEOUT:
nbd->xmit_timeout = arg * HZ;
if (arg)
mod_timer(&nbd->timeout_timer,
jiffies + nbd->xmit_timeout);
else
del_timer_sync(&nbd->timeout_timer);
return 0;
case NBD_SET_FLAGS:
nbd->flags = arg;
return 0;
case NBD_DO_IT: {
struct task_struct *thread;
int error;
if (nbd->task_recv)
return -EBUSY;
if (!nbd->sock)
return -EINVAL;
mutex_unlock(&nbd->tx_lock);
nbd_parse_flags(nbd, bdev);
thread = kthread_run(nbd_thread_send, nbd, "%s",
nbd_name(nbd));
if (IS_ERR(thread)) {
mutex_lock(&nbd->tx_lock);
return PTR_ERR(thread);
}
nbd_dev_dbg_init(nbd);
error = nbd_thread_recv(nbd, bdev);
nbd_dev_dbg_close(nbd);
kthread_stop(thread);
mutex_lock(&nbd->tx_lock);
sock_shutdown(nbd);
nbd_clear_que(nbd);
kill_bdev(bdev);
nbd_bdev_reset(bdev);
if (nbd->disconnect)
error = 0;
if (nbd->timedout)
error = -ETIMEDOUT;
nbd_reset(nbd);
return error;
}
case NBD_CLEAR_QUE:
return 0;
case NBD_PRINT_DEBUG:
dev_info(disk_to_dev(nbd->disk),
"next = %p, prev = %p, head = %p\n",
nbd->queue_head.next, nbd->queue_head.prev,
&nbd->queue_head);
return 0;
}
return -ENOTTY;
}
static int nbd_ioctl(struct block_device *bdev, fmode_t mode,
unsigned int cmd, unsigned long arg)
{
struct nbd_device *nbd = bdev->bd_disk->private_data;
int error;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
BUG_ON(nbd->magic != NBD_MAGIC);
mutex_lock(&nbd->tx_lock);
error = __nbd_ioctl(bdev, nbd, cmd, arg);
mutex_unlock(&nbd->tx_lock);
return error;
}
static int nbd_dbg_tasks_show(struct seq_file *s, void *unused)
{
struct nbd_device *nbd = s->private;
if (nbd->task_recv)
seq_printf(s, "recv: %d\n", task_pid_nr(nbd->task_recv));
if (nbd->task_send)
seq_printf(s, "send: %d\n", task_pid_nr(nbd->task_send));
return 0;
}
static int nbd_dbg_tasks_open(struct inode *inode, struct file *file)
{
return single_open(file, nbd_dbg_tasks_show, inode->i_private);
}
static int nbd_dbg_flags_show(struct seq_file *s, void *unused)
{
struct nbd_device *nbd = s->private;
u32 flags = nbd->flags;
seq_printf(s, "Hex: 0x%08x\n\n", flags);
seq_puts(s, "Known flags:\n");
if (flags & NBD_FLAG_HAS_FLAGS)
seq_puts(s, "NBD_FLAG_HAS_FLAGS\n");
if (flags & NBD_FLAG_READ_ONLY)
seq_puts(s, "NBD_FLAG_READ_ONLY\n");
if (flags & NBD_FLAG_SEND_FLUSH)
seq_puts(s, "NBD_FLAG_SEND_FLUSH\n");
if (flags & NBD_FLAG_SEND_TRIM)
seq_puts(s, "NBD_FLAG_SEND_TRIM\n");
return 0;
}
static int nbd_dbg_flags_open(struct inode *inode, struct file *file)
{
return single_open(file, nbd_dbg_flags_show, inode->i_private);
}
static int nbd_dev_dbg_init(struct nbd_device *nbd)
{
struct dentry *dir;
if (!nbd_dbg_dir)
return -EIO;
dir = debugfs_create_dir(nbd_name(nbd), nbd_dbg_dir);
if (!dir) {
dev_err(nbd_to_dev(nbd), "Failed to create debugfs dir for '%s'\n",
nbd_name(nbd));
return -EIO;
}
nbd->dbg_dir = dir;
debugfs_create_file("tasks", 0444, dir, nbd, &nbd_dbg_tasks_ops);
debugfs_create_u64("size_bytes", 0444, dir, &nbd->bytesize);
debugfs_create_u32("timeout", 0444, dir, &nbd->xmit_timeout);
debugfs_create_u32("blocksize", 0444, dir, &nbd->blksize);
debugfs_create_file("flags", 0444, dir, &nbd, &nbd_dbg_flags_ops);
return 0;
}
static void nbd_dev_dbg_close(struct nbd_device *nbd)
{
debugfs_remove_recursive(nbd->dbg_dir);
}
static int nbd_dbg_init(void)
{
struct dentry *dbg_dir;
dbg_dir = debugfs_create_dir("nbd", NULL);
if (!dbg_dir)
return -EIO;
nbd_dbg_dir = dbg_dir;
return 0;
}
static void nbd_dbg_close(void)
{
debugfs_remove_recursive(nbd_dbg_dir);
}
static int nbd_dev_dbg_init(struct nbd_device *nbd)
{
return 0;
}
static void nbd_dev_dbg_close(struct nbd_device *nbd)
{
}
static int nbd_dbg_init(void)
{
return 0;
}
static void nbd_dbg_close(void)
{
}
static int __init nbd_init(void)
{
int err = -ENOMEM;
int i;
int part_shift;
BUILD_BUG_ON(sizeof(struct nbd_request) != 28);
if (max_part < 0) {
printk(KERN_ERR "nbd: max_part must be >= 0\n");
return -EINVAL;
}
part_shift = 0;
if (max_part > 0) {
part_shift = fls(max_part);
max_part = (1UL << part_shift) - 1;
}
if ((1UL << part_shift) > DISK_MAX_PARTS)
return -EINVAL;
if (nbds_max > 1UL << (MINORBITS - part_shift))
return -EINVAL;
nbd_dev = kcalloc(nbds_max, sizeof(*nbd_dev), GFP_KERNEL);
if (!nbd_dev)
return -ENOMEM;
for (i = 0; i < nbds_max; i++) {
struct gendisk *disk = alloc_disk(1 << part_shift);
if (!disk)
goto out;
nbd_dev[i].disk = disk;
disk->queue = blk_init_queue(nbd_request_handler, &nbd_lock);
if (!disk->queue) {
put_disk(disk);
goto out;
}
queue_flag_set_unlocked(QUEUE_FLAG_NONROT, disk->queue);
queue_flag_clear_unlocked(QUEUE_FLAG_ADD_RANDOM, disk->queue);
disk->queue->limits.discard_granularity = 512;
blk_queue_max_discard_sectors(disk->queue, UINT_MAX);
disk->queue->limits.discard_zeroes_data = 0;
blk_queue_max_hw_sectors(disk->queue, 65536);
disk->queue->limits.max_sectors = 256;
}
if (register_blkdev(NBD_MAJOR, "nbd")) {
err = -EIO;
goto out;
}
printk(KERN_INFO "nbd: registered device at major %d\n", NBD_MAJOR);
nbd_dbg_init();
for (i = 0; i < nbds_max; i++) {
struct gendisk *disk = nbd_dev[i].disk;
nbd_dev[i].magic = NBD_MAGIC;
INIT_LIST_HEAD(&nbd_dev[i].waiting_queue);
spin_lock_init(&nbd_dev[i].queue_lock);
spin_lock_init(&nbd_dev[i].sock_lock);
INIT_LIST_HEAD(&nbd_dev[i].queue_head);
mutex_init(&nbd_dev[i].tx_lock);
init_timer(&nbd_dev[i].timeout_timer);
nbd_dev[i].timeout_timer.function = nbd_xmit_timeout;
nbd_dev[i].timeout_timer.data = (unsigned long)&nbd_dev[i];
init_waitqueue_head(&nbd_dev[i].active_wq);
init_waitqueue_head(&nbd_dev[i].waiting_wq);
disk->major = NBD_MAJOR;
disk->first_minor = i << part_shift;
disk->fops = &nbd_fops;
disk->private_data = &nbd_dev[i];
sprintf(disk->disk_name, "nbd%d", i);
nbd_reset(&nbd_dev[i]);
add_disk(disk);
}
return 0;
out:
while (i--) {
blk_cleanup_queue(nbd_dev[i].disk->queue);
put_disk(nbd_dev[i].disk);
}
kfree(nbd_dev);
return err;
}
static void __exit nbd_cleanup(void)
{
int i;
nbd_dbg_close();
for (i = 0; i < nbds_max; i++) {
struct gendisk *disk = nbd_dev[i].disk;
nbd_dev[i].magic = 0;
if (disk) {
del_gendisk(disk);
blk_cleanup_queue(disk->queue);
put_disk(disk);
}
}
unregister_blkdev(NBD_MAJOR, "nbd");
kfree(nbd_dev);
printk(KERN_INFO "nbd: unregistered device at major %d\n", NBD_MAJOR);
}
