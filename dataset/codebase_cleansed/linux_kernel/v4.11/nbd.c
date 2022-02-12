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
if (bdev->bd_openers <= 1)
bd_set_size(bdev, 0);
set_capacity(nbd->disk, 0);
kobject_uevent(&nbd_to_dev(nbd)->kobj, KOBJ_CHANGE);
return 0;
}
static void nbd_size_update(struct nbd_device *nbd, struct block_device *bdev)
{
blk_queue_logical_block_size(nbd->disk->queue, nbd->blksize);
blk_queue_physical_block_size(nbd->disk->queue, nbd->blksize);
bd_set_size(bdev, nbd->bytesize);
set_capacity(nbd->disk, nbd->bytesize >> 9);
kobject_uevent(&nbd_to_dev(nbd)->kobj, KOBJ_CHANGE);
}
static void nbd_size_set(struct nbd_device *nbd, struct block_device *bdev,
loff_t blocksize, loff_t nr_blocks)
{
nbd->blksize = blocksize;
nbd->bytesize = blocksize * nr_blocks;
if (nbd_is_connected(nbd))
nbd_size_update(nbd, bdev);
}
static void nbd_end_request(struct nbd_cmd *cmd)
{
struct nbd_device *nbd = cmd->nbd;
struct request *req = blk_mq_rq_from_pdu(cmd);
int error = req->errors ? -EIO : 0;
dev_dbg(nbd_to_dev(nbd), "request %p: %s\n", cmd,
error ? "failed" : "done");
blk_mq_complete_request(req, error);
}
static void sock_shutdown(struct nbd_device *nbd)
{
int i;
if (nbd->num_connections == 0)
return;
if (test_and_set_bit(NBD_DISCONNECTED, &nbd->runtime_flags))
return;
for (i = 0; i < nbd->num_connections; i++) {
struct nbd_sock *nsock = nbd->socks[i];
mutex_lock(&nsock->tx_lock);
kernel_sock_shutdown(nsock->sock, SHUT_RDWR);
mutex_unlock(&nsock->tx_lock);
}
dev_warn(disk_to_dev(nbd->disk), "shutting down sockets\n");
}
static enum blk_eh_timer_return nbd_xmit_timeout(struct request *req,
bool reserved)
{
struct nbd_cmd *cmd = blk_mq_rq_to_pdu(req);
struct nbd_device *nbd = cmd->nbd;
dev_err(nbd_to_dev(nbd), "Connection timed out, shutting down connection\n");
set_bit(NBD_TIMEDOUT, &nbd->runtime_flags);
req->errors = -EIO;
mutex_lock(&nbd->config_lock);
sock_shutdown(nbd);
mutex_unlock(&nbd->config_lock);
return BLK_EH_HANDLED;
}
static int sock_xmit(struct nbd_device *nbd, int index, int send,
struct iov_iter *iter, int msg_flags, int *sent)
{
struct socket *sock = nbd->socks[index]->sock;
int result;
struct msghdr msg;
unsigned long pflags = current->flags;
if (unlikely(!sock)) {
dev_err_ratelimited(disk_to_dev(nbd->disk),
"Attempted %s on closed socket in sock_xmit\n",
(send ? "send" : "recv"));
return -EINVAL;
}
msg.msg_iter = *iter;
current->flags |= PF_MEMALLOC;
do {
sock->sk->sk_allocation = GFP_NOIO | __GFP_MEMALLOC;
msg.msg_name = NULL;
msg.msg_namelen = 0;
msg.msg_control = NULL;
msg.msg_controllen = 0;
msg.msg_flags = msg_flags | MSG_NOSIGNAL;
if (send)
result = sock_sendmsg(sock, &msg);
else
result = sock_recvmsg(sock, &msg, msg.msg_flags);
if (result <= 0) {
if (result == 0)
result = -EPIPE;
break;
}
if (sent)
*sent += result;
} while (msg_data_left(&msg));
tsk_restore_flags(current, pflags, PF_MEMALLOC);
return result;
}
static int nbd_send_cmd(struct nbd_device *nbd, struct nbd_cmd *cmd, int index)
{
struct request *req = blk_mq_rq_from_pdu(cmd);
struct nbd_sock *nsock = nbd->socks[index];
int result;
struct nbd_request request = {.magic = htonl(NBD_REQUEST_MAGIC)};
struct kvec iov = {.iov_base = &request, .iov_len = sizeof(request)};
struct iov_iter from;
unsigned long size = blk_rq_bytes(req);
struct bio *bio;
u32 type;
u32 tag = blk_mq_unique_tag(req);
int sent = nsock->sent, skip = 0;
iov_iter_kvec(&from, WRITE | ITER_KVEC, &iov, 1, sizeof(request));
switch (req_op(req)) {
case REQ_OP_DISCARD:
type = NBD_CMD_TRIM;
break;
case REQ_OP_FLUSH:
type = NBD_CMD_FLUSH;
break;
case REQ_OP_WRITE:
type = NBD_CMD_WRITE;
break;
case REQ_OP_READ:
type = NBD_CMD_READ;
break;
default:
return -EIO;
}
if (rq_data_dir(req) == WRITE &&
(nbd->flags & NBD_FLAG_READ_ONLY)) {
dev_err_ratelimited(disk_to_dev(nbd->disk),
"Write on read-only\n");
return -EIO;
}
if (sent) {
if (sent >= sizeof(request)) {
skip = sent - sizeof(request);
goto send_pages;
}
iov_iter_advance(&from, sent);
}
request.type = htonl(type);
if (type != NBD_CMD_FLUSH) {
request.from = cpu_to_be64((u64)blk_rq_pos(req) << 9);
request.len = htonl(size);
}
memcpy(request.handle, &tag, sizeof(tag));
dev_dbg(nbd_to_dev(nbd), "request %p: sending control (%s@%llu,%uB)\n",
cmd, nbdcmd_to_ascii(type),
(unsigned long long)blk_rq_pos(req) << 9, blk_rq_bytes(req));
result = sock_xmit(nbd, index, 1, &from,
(type == NBD_CMD_WRITE) ? MSG_MORE : 0, &sent);
if (result <= 0) {
if (result == -ERESTARTSYS) {
if (sent) {
nsock->pending = req;
nsock->sent = sent;
}
return BLK_MQ_RQ_QUEUE_BUSY;
}
dev_err_ratelimited(disk_to_dev(nbd->disk),
"Send control failed (result %d)\n", result);
return -EIO;
}
send_pages:
if (type != NBD_CMD_WRITE)
goto out;
bio = req->bio;
while (bio) {
struct bio *next = bio->bi_next;
struct bvec_iter iter;
struct bio_vec bvec;
bio_for_each_segment(bvec, bio, iter) {
bool is_last = !next && bio_iter_last(bvec, iter);
int flags = is_last ? 0 : MSG_MORE;
dev_dbg(nbd_to_dev(nbd), "request %p: sending %d bytes data\n",
cmd, bvec.bv_len);
iov_iter_bvec(&from, ITER_BVEC | WRITE,
&bvec, 1, bvec.bv_len);
if (skip) {
if (skip >= iov_iter_count(&from)) {
skip -= iov_iter_count(&from);
continue;
}
iov_iter_advance(&from, skip);
skip = 0;
}
result = sock_xmit(nbd, index, 1, &from, flags, &sent);
if (result <= 0) {
if (result == -ERESTARTSYS) {
nsock->pending = req;
nsock->sent = sent;
return BLK_MQ_RQ_QUEUE_BUSY;
}
dev_err(disk_to_dev(nbd->disk),
"Send data failed (result %d)\n",
result);
return -EIO;
}
if (is_last)
break;
}
bio = next;
}
out:
nsock->pending = NULL;
nsock->sent = 0;
return 0;
}
static struct nbd_cmd *nbd_read_stat(struct nbd_device *nbd, int index)
{
int result;
struct nbd_reply reply;
struct nbd_cmd *cmd;
struct request *req = NULL;
u16 hwq;
u32 tag;
struct kvec iov = {.iov_base = &reply, .iov_len = sizeof(reply)};
struct iov_iter to;
reply.magic = 0;
iov_iter_kvec(&to, READ | ITER_KVEC, &iov, 1, sizeof(reply));
result = sock_xmit(nbd, index, 0, &to, MSG_WAITALL, NULL);
if (result <= 0) {
if (!test_bit(NBD_DISCONNECTED, &nbd->runtime_flags) &&
!test_bit(NBD_DISCONNECT_REQUESTED, &nbd->runtime_flags))
dev_err(disk_to_dev(nbd->disk),
"Receive control failed (result %d)\n", result);
return ERR_PTR(result);
}
if (ntohl(reply.magic) != NBD_REPLY_MAGIC) {
dev_err(disk_to_dev(nbd->disk), "Wrong magic (0x%lx)\n",
(unsigned long)ntohl(reply.magic));
return ERR_PTR(-EPROTO);
}
memcpy(&tag, reply.handle, sizeof(u32));
hwq = blk_mq_unique_tag_to_hwq(tag);
if (hwq < nbd->tag_set.nr_hw_queues)
req = blk_mq_tag_to_rq(nbd->tag_set.tags[hwq],
blk_mq_unique_tag_to_tag(tag));
if (!req || !blk_mq_request_started(req)) {
dev_err(disk_to_dev(nbd->disk), "Unexpected reply (%d) %p\n",
tag, req);
return ERR_PTR(-ENOENT);
}
cmd = blk_mq_rq_to_pdu(req);
if (ntohl(reply.error)) {
dev_err(disk_to_dev(nbd->disk), "Other side returned error (%d)\n",
ntohl(reply.error));
req->errors = -EIO;
return cmd;
}
dev_dbg(nbd_to_dev(nbd), "request %p: got reply\n", cmd);
if (rq_data_dir(req) != WRITE) {
struct req_iterator iter;
struct bio_vec bvec;
rq_for_each_segment(bvec, req, iter) {
iov_iter_bvec(&to, ITER_BVEC | READ,
&bvec, 1, bvec.bv_len);
result = sock_xmit(nbd, index, 0, &to, MSG_WAITALL, NULL);
if (result <= 0) {
dev_err(disk_to_dev(nbd->disk), "Receive data failed (result %d)\n",
result);
req->errors = -EIO;
return cmd;
}
dev_dbg(nbd_to_dev(nbd), "request %p: got %d bytes data\n",
cmd, bvec.bv_len);
}
} else {
wait_for_completion(&cmd->send_complete);
}
return cmd;
}
static ssize_t pid_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct gendisk *disk = dev_to_disk(dev);
struct nbd_device *nbd = (struct nbd_device *)disk->private_data;
return sprintf(buf, "%d\n", task_pid_nr(nbd->task_recv));
}
static void recv_work(struct work_struct *work)
{
struct recv_thread_args *args = container_of(work,
struct recv_thread_args,
work);
struct nbd_device *nbd = args->nbd;
struct nbd_cmd *cmd;
int ret = 0;
BUG_ON(nbd->magic != NBD_MAGIC);
while (1) {
cmd = nbd_read_stat(nbd, args->index);
if (IS_ERR(cmd)) {
ret = PTR_ERR(cmd);
break;
}
nbd_end_request(cmd);
}
if (ret && !test_bit(NBD_DISCONNECT_REQUESTED, &nbd->runtime_flags))
sock_shutdown(nbd);
atomic_dec(&nbd->recv_threads);
wake_up(&nbd->recv_wq);
}
static void nbd_clear_req(struct request *req, void *data, bool reserved)
{
struct nbd_cmd *cmd;
if (!blk_mq_request_started(req))
return;
cmd = blk_mq_rq_to_pdu(req);
req->errors = -EIO;
nbd_end_request(cmd);
}
static void nbd_clear_que(struct nbd_device *nbd)
{
BUG_ON(nbd->magic != NBD_MAGIC);
blk_mq_tagset_busy_iter(&nbd->tag_set, nbd_clear_req, NULL);
dev_dbg(disk_to_dev(nbd->disk), "queue cleared\n");
}
static int nbd_handle_cmd(struct nbd_cmd *cmd, int index)
{
struct request *req = blk_mq_rq_from_pdu(cmd);
struct nbd_device *nbd = cmd->nbd;
struct nbd_sock *nsock;
int ret;
if (index >= nbd->num_connections) {
dev_err_ratelimited(disk_to_dev(nbd->disk),
"Attempted send on invalid socket\n");
return -EINVAL;
}
if (test_bit(NBD_DISCONNECTED, &nbd->runtime_flags)) {
dev_err_ratelimited(disk_to_dev(nbd->disk),
"Attempted send on closed socket\n");
return -EINVAL;
}
req->errors = 0;
nsock = nbd->socks[index];
mutex_lock(&nsock->tx_lock);
if (unlikely(!nsock->sock)) {
mutex_unlock(&nsock->tx_lock);
dev_err_ratelimited(disk_to_dev(nbd->disk),
"Attempted send on closed socket\n");
return -EINVAL;
}
if (unlikely(nsock->pending && nsock->pending != req)) {
blk_mq_requeue_request(req, true);
ret = 0;
goto out;
}
ret = nbd_send_cmd(nbd, cmd, index);
out:
mutex_unlock(&nsock->tx_lock);
return ret;
}
static int nbd_queue_rq(struct blk_mq_hw_ctx *hctx,
const struct blk_mq_queue_data *bd)
{
struct nbd_cmd *cmd = blk_mq_rq_to_pdu(bd->rq);
int ret;
init_completion(&cmd->send_complete);
blk_mq_start_request(bd->rq);
ret = nbd_handle_cmd(cmd, hctx->queue_num);
if (ret < 0)
ret = BLK_MQ_RQ_QUEUE_ERROR;
if (!ret)
ret = BLK_MQ_RQ_QUEUE_OK;
complete(&cmd->send_complete);
return ret;
}
static int nbd_add_socket(struct nbd_device *nbd, struct block_device *bdev,
unsigned long arg)
{
struct socket *sock;
struct nbd_sock **socks;
struct nbd_sock *nsock;
int err;
sock = sockfd_lookup(arg, &err);
if (!sock)
return err;
if (!nbd->task_setup)
nbd->task_setup = current;
if (nbd->task_setup != current) {
dev_err(disk_to_dev(nbd->disk),
"Device being setup by another task");
return -EINVAL;
}
socks = krealloc(nbd->socks, (nbd->num_connections + 1) *
sizeof(struct nbd_sock *), GFP_KERNEL);
if (!socks)
return -ENOMEM;
nsock = kzalloc(sizeof(struct nbd_sock), GFP_KERNEL);
if (!nsock)
return -ENOMEM;
nbd->socks = socks;
mutex_init(&nsock->tx_lock);
nsock->sock = sock;
nsock->pending = NULL;
nsock->sent = 0;
socks[nbd->num_connections++] = nsock;
if (max_part)
bdev->bd_invalidated = 1;
return 0;
}
static void nbd_reset(struct nbd_device *nbd)
{
nbd->runtime_flags = 0;
nbd->blksize = 1024;
nbd->bytesize = 0;
set_capacity(nbd->disk, 0);
nbd->flags = 0;
nbd->tag_set.timeout = 0;
queue_flag_clear_unlocked(QUEUE_FLAG_DISCARD, nbd->disk->queue);
}
static void nbd_bdev_reset(struct block_device *bdev)
{
if (bdev->bd_openers > 1)
return;
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
blk_queue_write_cache(nbd->disk->queue, true, false);
else
blk_queue_write_cache(nbd->disk->queue, false, false);
}
static void send_disconnects(struct nbd_device *nbd)
{
struct nbd_request request = {
.magic = htonl(NBD_REQUEST_MAGIC),
.type = htonl(NBD_CMD_DISC),
};
struct kvec iov = {.iov_base = &request, .iov_len = sizeof(request)};
struct iov_iter from;
int i, ret;
for (i = 0; i < nbd->num_connections; i++) {
iov_iter_kvec(&from, WRITE | ITER_KVEC, &iov, 1, sizeof(request));
ret = sock_xmit(nbd, i, 1, &from, 0, NULL);
if (ret <= 0)
dev_err(disk_to_dev(nbd->disk),
"Send disconnect failed %d\n", ret);
}
}
static int nbd_disconnect(struct nbd_device *nbd, struct block_device *bdev)
{
dev_info(disk_to_dev(nbd->disk), "NBD_DISCONNECT\n");
if (!nbd->socks)
return -EINVAL;
mutex_unlock(&nbd->config_lock);
fsync_bdev(bdev);
mutex_lock(&nbd->config_lock);
if (!nbd->socks)
return -EINVAL;
if (!test_and_set_bit(NBD_DISCONNECT_REQUESTED,
&nbd->runtime_flags))
send_disconnects(nbd);
return 0;
}
static int nbd_clear_sock(struct nbd_device *nbd, struct block_device *bdev)
{
sock_shutdown(nbd);
nbd_clear_que(nbd);
__invalidate_device(bdev, true);
nbd_bdev_reset(bdev);
if (!test_bit(NBD_RUNNING, &nbd->runtime_flags) &&
nbd->num_connections) {
int i;
for (i = 0; i < nbd->num_connections; i++) {
sockfd_put(nbd->socks[i]->sock);
kfree(nbd->socks[i]);
}
kfree(nbd->socks);
nbd->socks = NULL;
nbd->num_connections = 0;
}
nbd->task_setup = NULL;
return 0;
}
static int nbd_start_device(struct nbd_device *nbd, struct block_device *bdev)
{
struct recv_thread_args *args;
int num_connections = nbd->num_connections;
int error = 0, i;
if (nbd->task_recv)
return -EBUSY;
if (!nbd->socks)
return -EINVAL;
if (num_connections > 1 &&
!(nbd->flags & NBD_FLAG_CAN_MULTI_CONN)) {
dev_err(disk_to_dev(nbd->disk), "server does not support multiple connections per device.\n");
error = -EINVAL;
goto out_err;
}
set_bit(NBD_RUNNING, &nbd->runtime_flags);
blk_mq_update_nr_hw_queues(&nbd->tag_set, nbd->num_connections);
args = kcalloc(num_connections, sizeof(*args), GFP_KERNEL);
if (!args) {
error = -ENOMEM;
goto out_err;
}
nbd->task_recv = current;
mutex_unlock(&nbd->config_lock);
nbd_parse_flags(nbd, bdev);
error = device_create_file(disk_to_dev(nbd->disk), &pid_attr);
if (error) {
dev_err(disk_to_dev(nbd->disk), "device_create_file failed!\n");
goto out_recv;
}
nbd_size_update(nbd, bdev);
nbd_dev_dbg_init(nbd);
for (i = 0; i < num_connections; i++) {
sk_set_memalloc(nbd->socks[i]->sock->sk);
atomic_inc(&nbd->recv_threads);
INIT_WORK(&args[i].work, recv_work);
args[i].nbd = nbd;
args[i].index = i;
queue_work(recv_workqueue, &args[i].work);
}
wait_event_interruptible(nbd->recv_wq,
atomic_read(&nbd->recv_threads) == 0);
for (i = 0; i < num_connections; i++)
flush_work(&args[i].work);
nbd_dev_dbg_close(nbd);
nbd_size_clear(nbd, bdev);
device_remove_file(disk_to_dev(nbd->disk), &pid_attr);
out_recv:
mutex_lock(&nbd->config_lock);
nbd->task_recv = NULL;
out_err:
clear_bit(NBD_RUNNING, &nbd->runtime_flags);
nbd_clear_sock(nbd, bdev);
if (test_bit(NBD_DISCONNECT_REQUESTED, &nbd->runtime_flags))
error = 0;
if (test_bit(NBD_TIMEDOUT, &nbd->runtime_flags))
error = -ETIMEDOUT;
nbd_reset(nbd);
return error;
}
static int __nbd_ioctl(struct block_device *bdev, struct nbd_device *nbd,
unsigned int cmd, unsigned long arg)
{
switch (cmd) {
case NBD_DISCONNECT:
return nbd_disconnect(nbd, bdev);
case NBD_CLEAR_SOCK:
return nbd_clear_sock(nbd, bdev);
case NBD_SET_SOCK:
return nbd_add_socket(nbd, bdev, arg);
case NBD_SET_BLKSIZE:
nbd_size_set(nbd, bdev, arg,
div_s64(nbd->bytesize, arg));
return 0;
case NBD_SET_SIZE:
nbd_size_set(nbd, bdev, nbd->blksize,
div_s64(arg, nbd->blksize));
return 0;
case NBD_SET_SIZE_BLOCKS:
nbd_size_set(nbd, bdev, nbd->blksize, arg);
return 0;
case NBD_SET_TIMEOUT:
if (arg) {
nbd->tag_set.timeout = arg * HZ;
blk_queue_rq_timeout(nbd->disk->queue, arg * HZ);
}
return 0;
case NBD_SET_FLAGS:
nbd->flags = arg;
return 0;
case NBD_DO_IT:
return nbd_start_device(nbd, bdev);
case NBD_CLEAR_QUE:
return 0;
case NBD_PRINT_DEBUG:
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
mutex_lock(&nbd->config_lock);
error = __nbd_ioctl(bdev, nbd, cmd, arg);
mutex_unlock(&nbd->config_lock);
return error;
}
static int nbd_dbg_tasks_show(struct seq_file *s, void *unused)
{
struct nbd_device *nbd = s->private;
if (nbd->task_recv)
seq_printf(s, "recv: %d\n", task_pid_nr(nbd->task_recv));
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
debugfs_create_u32("timeout", 0444, dir, &nbd->tag_set.timeout);
debugfs_create_u64("blocksize", 0444, dir, &nbd->blksize);
debugfs_create_file("flags", 0444, dir, nbd, &nbd_dbg_flags_ops);
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
static int nbd_init_request(void *data, struct request *rq,
unsigned int hctx_idx, unsigned int request_idx,
unsigned int numa_node)
{
struct nbd_cmd *cmd = blk_mq_rq_to_pdu(rq);
cmd->nbd = data;
return 0;
}
static void nbd_dev_remove(struct nbd_device *nbd)
{
struct gendisk *disk = nbd->disk;
nbd->magic = 0;
if (disk) {
del_gendisk(disk);
blk_cleanup_queue(disk->queue);
blk_mq_free_tag_set(&nbd->tag_set);
put_disk(disk);
}
kfree(nbd);
}
static int nbd_dev_add(int index)
{
struct nbd_device *nbd;
struct gendisk *disk;
struct request_queue *q;
int err = -ENOMEM;
nbd = kzalloc(sizeof(struct nbd_device), GFP_KERNEL);
if (!nbd)
goto out;
disk = alloc_disk(1 << part_shift);
if (!disk)
goto out_free_nbd;
if (index >= 0) {
err = idr_alloc(&nbd_index_idr, nbd, index, index + 1,
GFP_KERNEL);
if (err == -ENOSPC)
err = -EEXIST;
} else {
err = idr_alloc(&nbd_index_idr, nbd, 0, 0, GFP_KERNEL);
if (err >= 0)
index = err;
}
if (err < 0)
goto out_free_disk;
nbd->disk = disk;
nbd->tag_set.ops = &nbd_mq_ops;
nbd->tag_set.nr_hw_queues = 1;
nbd->tag_set.queue_depth = 128;
nbd->tag_set.numa_node = NUMA_NO_NODE;
nbd->tag_set.cmd_size = sizeof(struct nbd_cmd);
nbd->tag_set.flags = BLK_MQ_F_SHOULD_MERGE |
BLK_MQ_F_SG_MERGE | BLK_MQ_F_BLOCKING;
nbd->tag_set.driver_data = nbd;
err = blk_mq_alloc_tag_set(&nbd->tag_set);
if (err)
goto out_free_idr;
q = blk_mq_init_queue(&nbd->tag_set);
if (IS_ERR(q)) {
err = PTR_ERR(q);
goto out_free_tags;
}
disk->queue = q;
queue_flag_set_unlocked(QUEUE_FLAG_NONROT, disk->queue);
queue_flag_clear_unlocked(QUEUE_FLAG_ADD_RANDOM, disk->queue);
disk->queue->limits.discard_granularity = 512;
blk_queue_max_discard_sectors(disk->queue, UINT_MAX);
disk->queue->limits.discard_zeroes_data = 0;
blk_queue_max_hw_sectors(disk->queue, 65536);
disk->queue->limits.max_sectors = 256;
nbd->magic = NBD_MAGIC;
mutex_init(&nbd->config_lock);
disk->major = NBD_MAJOR;
disk->first_minor = index << part_shift;
disk->fops = &nbd_fops;
disk->private_data = nbd;
sprintf(disk->disk_name, "nbd%d", index);
init_waitqueue_head(&nbd->recv_wq);
nbd_reset(nbd);
add_disk(disk);
return index;
out_free_tags:
blk_mq_free_tag_set(&nbd->tag_set);
out_free_idr:
idr_remove(&nbd_index_idr, index);
out_free_disk:
put_disk(disk);
out_free_nbd:
kfree(nbd);
out:
return err;
}
static int __init nbd_init(void)
{
int i;
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
recv_workqueue = alloc_workqueue("knbd-recv",
WQ_MEM_RECLAIM | WQ_HIGHPRI, 0);
if (!recv_workqueue)
return -ENOMEM;
if (register_blkdev(NBD_MAJOR, "nbd")) {
destroy_workqueue(recv_workqueue);
return -EIO;
}
nbd_dbg_init();
mutex_lock(&nbd_index_mutex);
for (i = 0; i < nbds_max; i++)
nbd_dev_add(i);
mutex_unlock(&nbd_index_mutex);
return 0;
}
static int nbd_exit_cb(int id, void *ptr, void *data)
{
struct nbd_device *nbd = ptr;
nbd_dev_remove(nbd);
return 0;
}
static void __exit nbd_cleanup(void)
{
nbd_dbg_close();
idr_for_each(&nbd_index_idr, &nbd_exit_cb, NULL);
idr_destroy(&nbd_index_idr);
destroy_workqueue(recv_workqueue);
unregister_blkdev(NBD_MAJOR, "nbd");
}
