static void vhost_net_enable_zcopy(int vq)
{
vhost_net_zcopy_mask |= 0x1 << vq;
}
static void vhost_net_zerocopy_done_signal(struct kref *kref)
{
struct vhost_net_ubuf_ref *ubufs;
ubufs = container_of(kref, struct vhost_net_ubuf_ref, kref);
wake_up(&ubufs->wait);
}
static struct vhost_net_ubuf_ref *
vhost_net_ubuf_alloc(struct vhost_virtqueue *vq, bool zcopy)
{
struct vhost_net_ubuf_ref *ubufs;
if (!zcopy)
return NULL;
ubufs = kmalloc(sizeof(*ubufs), GFP_KERNEL);
if (!ubufs)
return ERR_PTR(-ENOMEM);
kref_init(&ubufs->kref);
init_waitqueue_head(&ubufs->wait);
ubufs->vq = vq;
return ubufs;
}
static void vhost_net_ubuf_put(struct vhost_net_ubuf_ref *ubufs)
{
kref_put(&ubufs->kref, vhost_net_zerocopy_done_signal);
}
static void vhost_net_ubuf_put_and_wait(struct vhost_net_ubuf_ref *ubufs)
{
kref_put(&ubufs->kref, vhost_net_zerocopy_done_signal);
wait_event(ubufs->wait, !atomic_read(&ubufs->kref.refcount));
}
static void vhost_net_ubuf_put_wait_and_free(struct vhost_net_ubuf_ref *ubufs)
{
vhost_net_ubuf_put_and_wait(ubufs);
kfree(ubufs);
}
static void vhost_net_clear_ubuf_info(struct vhost_net *n)
{
int i;
for (i = 0; i < VHOST_NET_VQ_MAX; ++i) {
kfree(n->vqs[i].ubuf_info);
n->vqs[i].ubuf_info = NULL;
}
}
static int vhost_net_set_ubuf_info(struct vhost_net *n)
{
bool zcopy;
int i;
for (i = 0; i < VHOST_NET_VQ_MAX; ++i) {
zcopy = vhost_net_zcopy_mask & (0x1 << i);
if (!zcopy)
continue;
n->vqs[i].ubuf_info = kmalloc(sizeof(*n->vqs[i].ubuf_info) *
UIO_MAXIOV, GFP_KERNEL);
if (!n->vqs[i].ubuf_info)
goto err;
}
return 0;
err:
vhost_net_clear_ubuf_info(n);
return -ENOMEM;
}
static void vhost_net_vq_reset(struct vhost_net *n)
{
int i;
vhost_net_clear_ubuf_info(n);
for (i = 0; i < VHOST_NET_VQ_MAX; i++) {
n->vqs[i].done_idx = 0;
n->vqs[i].upend_idx = 0;
n->vqs[i].ubufs = NULL;
n->vqs[i].vhost_hlen = 0;
n->vqs[i].sock_hlen = 0;
}
}
static void vhost_net_tx_packet(struct vhost_net *net)
{
++net->tx_packets;
if (net->tx_packets < 1024)
return;
net->tx_packets = 0;
net->tx_zcopy_err = 0;
}
static void vhost_net_tx_err(struct vhost_net *net)
{
++net->tx_zcopy_err;
}
static bool vhost_net_tx_select_zcopy(struct vhost_net *net)
{
return !net->tx_flush &&
net->tx_packets / 64 >= net->tx_zcopy_err;
}
static bool vhost_sock_zcopy(struct socket *sock)
{
return unlikely(experimental_zcopytx) &&
sock_flag(sock->sk, SOCK_ZEROCOPY);
}
static int move_iovec_hdr(struct iovec *from, struct iovec *to,
size_t len, int iov_count)
{
int seg = 0;
size_t size;
while (len && seg < iov_count) {
size = min(from->iov_len, len);
to->iov_base = from->iov_base;
to->iov_len = size;
from->iov_len -= size;
from->iov_base += size;
len -= size;
++from;
++to;
++seg;
}
return seg;
}
static void copy_iovec_hdr(const struct iovec *from, struct iovec *to,
size_t len, int iovcount)
{
int seg = 0;
size_t size;
while (len && seg < iovcount) {
size = min(from->iov_len, len);
to->iov_base = from->iov_base;
to->iov_len = size;
len -= size;
++from;
++to;
++seg;
}
}
static void vhost_zerocopy_signal_used(struct vhost_net *net,
struct vhost_virtqueue *vq)
{
struct vhost_net_virtqueue *nvq =
container_of(vq, struct vhost_net_virtqueue, vq);
int i, add;
int j = 0;
for (i = nvq->done_idx; i != nvq->upend_idx; i = (i + 1) % UIO_MAXIOV) {
if (vq->heads[i].len == VHOST_DMA_FAILED_LEN)
vhost_net_tx_err(net);
if (VHOST_DMA_IS_DONE(vq->heads[i].len)) {
vq->heads[i].len = VHOST_DMA_CLEAR_LEN;
++j;
} else
break;
}
while (j) {
add = min(UIO_MAXIOV - nvq->done_idx, j);
vhost_add_used_and_signal_n(vq->dev, vq,
&vq->heads[nvq->done_idx], add);
nvq->done_idx = (nvq->done_idx + add) % UIO_MAXIOV;
j -= add;
}
}
static void vhost_zerocopy_callback(struct ubuf_info *ubuf, bool success)
{
struct vhost_net_ubuf_ref *ubufs = ubuf->ctx;
struct vhost_virtqueue *vq = ubufs->vq;
int cnt = atomic_read(&ubufs->kref.refcount);
vq->heads[ubuf->desc].len = success ?
VHOST_DMA_DONE_LEN : VHOST_DMA_FAILED_LEN;
vhost_net_ubuf_put(ubufs);
if (cnt <= 2 || !(cnt % 16))
vhost_poll_queue(&vq->poll);
}
static void handle_tx(struct vhost_net *net)
{
struct vhost_net_virtqueue *nvq = &net->vqs[VHOST_NET_VQ_TX];
struct vhost_virtqueue *vq = &nvq->vq;
unsigned out, in, s;
int head;
struct msghdr msg = {
.msg_name = NULL,
.msg_namelen = 0,
.msg_control = NULL,
.msg_controllen = 0,
.msg_iov = vq->iov,
.msg_flags = MSG_DONTWAIT,
};
size_t len, total_len = 0;
int err;
size_t hdr_size;
struct socket *sock;
struct vhost_net_ubuf_ref *uninitialized_var(ubufs);
bool zcopy, zcopy_used;
mutex_lock(&vq->mutex);
sock = vq->private_data;
if (!sock)
goto out;
vhost_disable_notify(&net->dev, vq);
hdr_size = nvq->vhost_hlen;
zcopy = nvq->ubufs;
for (;;) {
if (zcopy)
vhost_zerocopy_signal_used(net, vq);
if (unlikely((nvq->upend_idx + vq->num - VHOST_MAX_PEND)
% UIO_MAXIOV == nvq->done_idx))
break;
head = vhost_get_vq_desc(&net->dev, vq, vq->iov,
ARRAY_SIZE(vq->iov),
&out, &in,
NULL, NULL);
if (unlikely(head < 0))
break;
if (head == vq->num) {
if (unlikely(vhost_enable_notify(&net->dev, vq))) {
vhost_disable_notify(&net->dev, vq);
continue;
}
break;
}
if (in) {
vq_err(vq, "Unexpected descriptor format for TX: "
"out %d, int %d\n", out, in);
break;
}
s = move_iovec_hdr(vq->iov, nvq->hdr, hdr_size, out);
msg.msg_iovlen = out;
len = iov_length(vq->iov, out);
if (!len) {
vq_err(vq, "Unexpected header len for TX: "
"%zd expected %zd\n",
iov_length(nvq->hdr, s), hdr_size);
break;
}
zcopy_used = zcopy && len >= VHOST_GOODCOPY_LEN
&& (nvq->upend_idx + 1) % UIO_MAXIOV !=
nvq->done_idx
&& vhost_net_tx_select_zcopy(net);
if (zcopy_used) {
struct ubuf_info *ubuf;
ubuf = nvq->ubuf_info + nvq->upend_idx;
vq->heads[nvq->upend_idx].id = head;
vq->heads[nvq->upend_idx].len = VHOST_DMA_IN_PROGRESS;
ubuf->callback = vhost_zerocopy_callback;
ubuf->ctx = nvq->ubufs;
ubuf->desc = nvq->upend_idx;
msg.msg_control = ubuf;
msg.msg_controllen = sizeof(ubuf);
ubufs = nvq->ubufs;
kref_get(&ubufs->kref);
nvq->upend_idx = (nvq->upend_idx + 1) % UIO_MAXIOV;
} else {
msg.msg_control = NULL;
ubufs = NULL;
}
err = sock->ops->sendmsg(NULL, sock, &msg, len);
if (unlikely(err < 0)) {
if (zcopy_used) {
vhost_net_ubuf_put(ubufs);
nvq->upend_idx = ((unsigned)nvq->upend_idx - 1)
% UIO_MAXIOV;
}
vhost_discard_vq_desc(vq, 1);
break;
}
if (err != len)
pr_debug("Truncated TX packet: "
" len %d != %zd\n", err, len);
if (!zcopy_used)
vhost_add_used_and_signal(&net->dev, vq, head, 0);
else
vhost_zerocopy_signal_used(net, vq);
total_len += len;
vhost_net_tx_packet(net);
if (unlikely(total_len >= VHOST_NET_WEIGHT)) {
vhost_poll_queue(&vq->poll);
break;
}
}
out:
mutex_unlock(&vq->mutex);
}
static int peek_head_len(struct sock *sk)
{
struct sk_buff *head;
int len = 0;
unsigned long flags;
spin_lock_irqsave(&sk->sk_receive_queue.lock, flags);
head = skb_peek(&sk->sk_receive_queue);
if (likely(head)) {
len = head->len;
if (vlan_tx_tag_present(head))
len += VLAN_HLEN;
}
spin_unlock_irqrestore(&sk->sk_receive_queue.lock, flags);
return len;
}
static int get_rx_bufs(struct vhost_virtqueue *vq,
struct vring_used_elem *heads,
int datalen,
unsigned *iovcount,
struct vhost_log *log,
unsigned *log_num,
unsigned int quota)
{
unsigned int out, in;
int seg = 0;
int headcount = 0;
unsigned d;
int r, nlogs = 0;
while (datalen > 0 && headcount < quota) {
if (unlikely(seg >= UIO_MAXIOV)) {
r = -ENOBUFS;
goto err;
}
d = vhost_get_vq_desc(vq->dev, vq, vq->iov + seg,
ARRAY_SIZE(vq->iov) - seg, &out,
&in, log, log_num);
if (d == vq->num) {
r = 0;
goto err;
}
if (unlikely(out || in <= 0)) {
vq_err(vq, "unexpected descriptor format for RX: "
"out %d, in %d\n", out, in);
r = -EINVAL;
goto err;
}
if (unlikely(log)) {
nlogs += *log_num;
log += *log_num;
}
heads[headcount].id = d;
heads[headcount].len = iov_length(vq->iov + seg, in);
datalen -= heads[headcount].len;
++headcount;
seg += in;
}
heads[headcount - 1].len += datalen;
*iovcount = seg;
if (unlikely(log))
*log_num = nlogs;
return headcount;
err:
vhost_discard_vq_desc(vq, headcount);
return r;
}
static void handle_rx(struct vhost_net *net)
{
struct vhost_net_virtqueue *nvq = &net->vqs[VHOST_NET_VQ_RX];
struct vhost_virtqueue *vq = &nvq->vq;
unsigned uninitialized_var(in), log;
struct vhost_log *vq_log;
struct msghdr msg = {
.msg_name = NULL,
.msg_namelen = 0,
.msg_control = NULL,
.msg_controllen = 0,
.msg_iov = vq->iov,
.msg_flags = MSG_DONTWAIT,
};
struct virtio_net_hdr_mrg_rxbuf hdr = {
.hdr.flags = 0,
.hdr.gso_type = VIRTIO_NET_HDR_GSO_NONE
};
size_t total_len = 0;
int err, mergeable;
s16 headcount;
size_t vhost_hlen, sock_hlen;
size_t vhost_len, sock_len;
struct socket *sock;
mutex_lock(&vq->mutex);
sock = vq->private_data;
if (!sock)
goto out;
vhost_disable_notify(&net->dev, vq);
vhost_hlen = nvq->vhost_hlen;
sock_hlen = nvq->sock_hlen;
vq_log = unlikely(vhost_has_feature(&net->dev, VHOST_F_LOG_ALL)) ?
vq->log : NULL;
mergeable = vhost_has_feature(&net->dev, VIRTIO_NET_F_MRG_RXBUF);
while ((sock_len = peek_head_len(sock->sk))) {
sock_len += sock_hlen;
vhost_len = sock_len + vhost_hlen;
headcount = get_rx_bufs(vq, vq->heads, vhost_len,
&in, vq_log, &log,
likely(mergeable) ? UIO_MAXIOV : 1);
if (unlikely(headcount < 0))
break;
if (!headcount) {
if (unlikely(vhost_enable_notify(&net->dev, vq))) {
vhost_disable_notify(&net->dev, vq);
continue;
}
break;
}
if (unlikely((vhost_hlen)))
move_iovec_hdr(vq->iov, nvq->hdr, vhost_hlen, in);
else
copy_iovec_hdr(vq->iov, nvq->hdr, sock_hlen, in);
msg.msg_iovlen = in;
err = sock->ops->recvmsg(NULL, sock, &msg,
sock_len, MSG_DONTWAIT | MSG_TRUNC);
if (unlikely(err != sock_len)) {
pr_debug("Discarded rx packet: "
" len %d, expected %zd\n", err, sock_len);
vhost_discard_vq_desc(vq, headcount);
continue;
}
if (unlikely(vhost_hlen) &&
memcpy_toiovecend(nvq->hdr, (unsigned char *)&hdr, 0,
vhost_hlen)) {
vq_err(vq, "Unable to write vnet_hdr at addr %p\n",
vq->iov->iov_base);
break;
}
if (likely(mergeable) &&
memcpy_toiovecend(nvq->hdr, (unsigned char *)&headcount,
offsetof(typeof(hdr), num_buffers),
sizeof hdr.num_buffers)) {
vq_err(vq, "Failed num_buffers write");
vhost_discard_vq_desc(vq, headcount);
break;
}
vhost_add_used_and_signal_n(&net->dev, vq, vq->heads,
headcount);
if (unlikely(vq_log))
vhost_log_write(vq, vq_log, log, vhost_len);
total_len += vhost_len;
if (unlikely(total_len >= VHOST_NET_WEIGHT)) {
vhost_poll_queue(&vq->poll);
break;
}
}
out:
mutex_unlock(&vq->mutex);
}
static void handle_tx_kick(struct vhost_work *work)
{
struct vhost_virtqueue *vq = container_of(work, struct vhost_virtqueue,
poll.work);
struct vhost_net *net = container_of(vq->dev, struct vhost_net, dev);
handle_tx(net);
}
static void handle_rx_kick(struct vhost_work *work)
{
struct vhost_virtqueue *vq = container_of(work, struct vhost_virtqueue,
poll.work);
struct vhost_net *net = container_of(vq->dev, struct vhost_net, dev);
handle_rx(net);
}
static void handle_tx_net(struct vhost_work *work)
{
struct vhost_net *net = container_of(work, struct vhost_net,
poll[VHOST_NET_VQ_TX].work);
handle_tx(net);
}
static void handle_rx_net(struct vhost_work *work)
{
struct vhost_net *net = container_of(work, struct vhost_net,
poll[VHOST_NET_VQ_RX].work);
handle_rx(net);
}
static int vhost_net_open(struct inode *inode, struct file *f)
{
struct vhost_net *n = kmalloc(sizeof *n, GFP_KERNEL);
struct vhost_dev *dev;
struct vhost_virtqueue **vqs;
int r, i;
if (!n)
return -ENOMEM;
vqs = kmalloc(VHOST_NET_VQ_MAX * sizeof(*vqs), GFP_KERNEL);
if (!vqs) {
kfree(n);
return -ENOMEM;
}
dev = &n->dev;
vqs[VHOST_NET_VQ_TX] = &n->vqs[VHOST_NET_VQ_TX].vq;
vqs[VHOST_NET_VQ_RX] = &n->vqs[VHOST_NET_VQ_RX].vq;
n->vqs[VHOST_NET_VQ_TX].vq.handle_kick = handle_tx_kick;
n->vqs[VHOST_NET_VQ_RX].vq.handle_kick = handle_rx_kick;
for (i = 0; i < VHOST_NET_VQ_MAX; i++) {
n->vqs[i].ubufs = NULL;
n->vqs[i].ubuf_info = NULL;
n->vqs[i].upend_idx = 0;
n->vqs[i].done_idx = 0;
n->vqs[i].vhost_hlen = 0;
n->vqs[i].sock_hlen = 0;
}
r = vhost_dev_init(dev, vqs, VHOST_NET_VQ_MAX);
if (r < 0) {
kfree(n);
kfree(vqs);
return r;
}
vhost_poll_init(n->poll + VHOST_NET_VQ_TX, handle_tx_net, POLLOUT, dev);
vhost_poll_init(n->poll + VHOST_NET_VQ_RX, handle_rx_net, POLLIN, dev);
f->private_data = n;
return 0;
}
static void vhost_net_disable_vq(struct vhost_net *n,
struct vhost_virtqueue *vq)
{
struct vhost_net_virtqueue *nvq =
container_of(vq, struct vhost_net_virtqueue, vq);
struct vhost_poll *poll = n->poll + (nvq - n->vqs);
if (!vq->private_data)
return;
vhost_poll_stop(poll);
}
static int vhost_net_enable_vq(struct vhost_net *n,
struct vhost_virtqueue *vq)
{
struct vhost_net_virtqueue *nvq =
container_of(vq, struct vhost_net_virtqueue, vq);
struct vhost_poll *poll = n->poll + (nvq - n->vqs);
struct socket *sock;
sock = vq->private_data;
if (!sock)
return 0;
return vhost_poll_start(poll, sock->file);
}
static struct socket *vhost_net_stop_vq(struct vhost_net *n,
struct vhost_virtqueue *vq)
{
struct socket *sock;
mutex_lock(&vq->mutex);
sock = vq->private_data;
vhost_net_disable_vq(n, vq);
vq->private_data = NULL;
mutex_unlock(&vq->mutex);
return sock;
}
static void vhost_net_stop(struct vhost_net *n, struct socket **tx_sock,
struct socket **rx_sock)
{
*tx_sock = vhost_net_stop_vq(n, &n->vqs[VHOST_NET_VQ_TX].vq);
*rx_sock = vhost_net_stop_vq(n, &n->vqs[VHOST_NET_VQ_RX].vq);
}
static void vhost_net_flush_vq(struct vhost_net *n, int index)
{
vhost_poll_flush(n->poll + index);
vhost_poll_flush(&n->vqs[index].vq.poll);
}
static void vhost_net_flush(struct vhost_net *n)
{
vhost_net_flush_vq(n, VHOST_NET_VQ_TX);
vhost_net_flush_vq(n, VHOST_NET_VQ_RX);
if (n->vqs[VHOST_NET_VQ_TX].ubufs) {
mutex_lock(&n->vqs[VHOST_NET_VQ_TX].vq.mutex);
n->tx_flush = true;
mutex_unlock(&n->vqs[VHOST_NET_VQ_TX].vq.mutex);
vhost_net_ubuf_put_and_wait(n->vqs[VHOST_NET_VQ_TX].ubufs);
mutex_lock(&n->vqs[VHOST_NET_VQ_TX].vq.mutex);
n->tx_flush = false;
kref_init(&n->vqs[VHOST_NET_VQ_TX].ubufs->kref);
mutex_unlock(&n->vqs[VHOST_NET_VQ_TX].vq.mutex);
}
}
static int vhost_net_release(struct inode *inode, struct file *f)
{
struct vhost_net *n = f->private_data;
struct socket *tx_sock;
struct socket *rx_sock;
vhost_net_stop(n, &tx_sock, &rx_sock);
vhost_net_flush(n);
vhost_dev_stop(&n->dev);
vhost_dev_cleanup(&n->dev, false);
vhost_net_vq_reset(n);
if (tx_sock)
fput(tx_sock->file);
if (rx_sock)
fput(rx_sock->file);
vhost_net_flush(n);
kfree(n->dev.vqs);
kfree(n);
return 0;
}
static struct socket *get_raw_socket(int fd)
{
struct {
struct sockaddr_ll sa;
char buf[MAX_ADDR_LEN];
} uaddr;
int uaddr_len = sizeof uaddr, r;
struct socket *sock = sockfd_lookup(fd, &r);
if (!sock)
return ERR_PTR(-ENOTSOCK);
if (sock->sk->sk_type != SOCK_RAW) {
r = -ESOCKTNOSUPPORT;
goto err;
}
r = sock->ops->getname(sock, (struct sockaddr *)&uaddr.sa,
&uaddr_len, 0);
if (r)
goto err;
if (uaddr.sa.sll_family != AF_PACKET) {
r = -EPFNOSUPPORT;
goto err;
}
return sock;
err:
fput(sock->file);
return ERR_PTR(r);
}
static struct socket *get_tap_socket(int fd)
{
struct file *file = fget(fd);
struct socket *sock;
if (!file)
return ERR_PTR(-EBADF);
sock = tun_get_socket(file);
if (!IS_ERR(sock))
return sock;
sock = macvtap_get_socket(file);
if (IS_ERR(sock))
fput(file);
return sock;
}
static struct socket *get_socket(int fd)
{
struct socket *sock;
if (fd == -1)
return NULL;
sock = get_raw_socket(fd);
if (!IS_ERR(sock))
return sock;
sock = get_tap_socket(fd);
if (!IS_ERR(sock))
return sock;
return ERR_PTR(-ENOTSOCK);
}
static long vhost_net_set_backend(struct vhost_net *n, unsigned index, int fd)
{
struct socket *sock, *oldsock;
struct vhost_virtqueue *vq;
struct vhost_net_virtqueue *nvq;
struct vhost_net_ubuf_ref *ubufs, *oldubufs = NULL;
int r;
mutex_lock(&n->dev.mutex);
r = vhost_dev_check_owner(&n->dev);
if (r)
goto err;
if (index >= VHOST_NET_VQ_MAX) {
r = -ENOBUFS;
goto err;
}
vq = &n->vqs[index].vq;
nvq = &n->vqs[index];
mutex_lock(&vq->mutex);
if (!vhost_vq_access_ok(vq)) {
r = -EFAULT;
goto err_vq;
}
sock = get_socket(fd);
if (IS_ERR(sock)) {
r = PTR_ERR(sock);
goto err_vq;
}
oldsock = vq->private_data;
if (sock != oldsock) {
ubufs = vhost_net_ubuf_alloc(vq,
sock && vhost_sock_zcopy(sock));
if (IS_ERR(ubufs)) {
r = PTR_ERR(ubufs);
goto err_ubufs;
}
vhost_net_disable_vq(n, vq);
vq->private_data = sock;
r = vhost_init_used(vq);
if (r)
goto err_used;
r = vhost_net_enable_vq(n, vq);
if (r)
goto err_used;
oldubufs = nvq->ubufs;
nvq->ubufs = ubufs;
n->tx_packets = 0;
n->tx_zcopy_err = 0;
n->tx_flush = false;
}
mutex_unlock(&vq->mutex);
if (oldubufs) {
vhost_net_ubuf_put_wait_and_free(oldubufs);
mutex_lock(&vq->mutex);
vhost_zerocopy_signal_used(n, vq);
mutex_unlock(&vq->mutex);
}
if (oldsock) {
vhost_net_flush_vq(n, index);
fput(oldsock->file);
}
mutex_unlock(&n->dev.mutex);
return 0;
err_used:
vq->private_data = oldsock;
vhost_net_enable_vq(n, vq);
if (ubufs)
vhost_net_ubuf_put_wait_and_free(ubufs);
err_ubufs:
fput(sock->file);
err_vq:
mutex_unlock(&vq->mutex);
err:
mutex_unlock(&n->dev.mutex);
return r;
}
static long vhost_net_reset_owner(struct vhost_net *n)
{
struct socket *tx_sock = NULL;
struct socket *rx_sock = NULL;
long err;
struct vhost_memory *memory;
mutex_lock(&n->dev.mutex);
err = vhost_dev_check_owner(&n->dev);
if (err)
goto done;
memory = vhost_dev_reset_owner_prepare();
if (!memory) {
err = -ENOMEM;
goto done;
}
vhost_net_stop(n, &tx_sock, &rx_sock);
vhost_net_flush(n);
vhost_dev_reset_owner(&n->dev, memory);
vhost_net_vq_reset(n);
done:
mutex_unlock(&n->dev.mutex);
if (tx_sock)
fput(tx_sock->file);
if (rx_sock)
fput(rx_sock->file);
return err;
}
static int vhost_net_set_features(struct vhost_net *n, u64 features)
{
size_t vhost_hlen, sock_hlen, hdr_len;
int i;
hdr_len = (features & (1 << VIRTIO_NET_F_MRG_RXBUF)) ?
sizeof(struct virtio_net_hdr_mrg_rxbuf) :
sizeof(struct virtio_net_hdr);
if (features & (1 << VHOST_NET_F_VIRTIO_NET_HDR)) {
vhost_hlen = hdr_len;
sock_hlen = 0;
} else {
vhost_hlen = 0;
sock_hlen = hdr_len;
}
mutex_lock(&n->dev.mutex);
if ((features & (1 << VHOST_F_LOG_ALL)) &&
!vhost_log_access_ok(&n->dev)) {
mutex_unlock(&n->dev.mutex);
return -EFAULT;
}
n->dev.acked_features = features;
smp_wmb();
for (i = 0; i < VHOST_NET_VQ_MAX; ++i) {
mutex_lock(&n->vqs[i].vq.mutex);
n->vqs[i].vhost_hlen = vhost_hlen;
n->vqs[i].sock_hlen = sock_hlen;
mutex_unlock(&n->vqs[i].vq.mutex);
}
vhost_net_flush(n);
mutex_unlock(&n->dev.mutex);
return 0;
}
static long vhost_net_set_owner(struct vhost_net *n)
{
int r;
mutex_lock(&n->dev.mutex);
if (vhost_dev_has_owner(&n->dev)) {
r = -EBUSY;
goto out;
}
r = vhost_net_set_ubuf_info(n);
if (r)
goto out;
r = vhost_dev_set_owner(&n->dev);
if (r)
vhost_net_clear_ubuf_info(n);
vhost_net_flush(n);
out:
mutex_unlock(&n->dev.mutex);
return r;
}
static long vhost_net_ioctl(struct file *f, unsigned int ioctl,
unsigned long arg)
{
struct vhost_net *n = f->private_data;
void __user *argp = (void __user *)arg;
u64 __user *featurep = argp;
struct vhost_vring_file backend;
u64 features;
int r;
switch (ioctl) {
case VHOST_NET_SET_BACKEND:
if (copy_from_user(&backend, argp, sizeof backend))
return -EFAULT;
return vhost_net_set_backend(n, backend.index, backend.fd);
case VHOST_GET_FEATURES:
features = VHOST_NET_FEATURES;
if (copy_to_user(featurep, &features, sizeof features))
return -EFAULT;
return 0;
case VHOST_SET_FEATURES:
if (copy_from_user(&features, featurep, sizeof features))
return -EFAULT;
if (features & ~VHOST_NET_FEATURES)
return -EOPNOTSUPP;
return vhost_net_set_features(n, features);
case VHOST_RESET_OWNER:
return vhost_net_reset_owner(n);
case VHOST_SET_OWNER:
return vhost_net_set_owner(n);
default:
mutex_lock(&n->dev.mutex);
r = vhost_dev_ioctl(&n->dev, ioctl, argp);
if (r == -ENOIOCTLCMD)
r = vhost_vring_ioctl(&n->dev, ioctl, argp);
else
vhost_net_flush(n);
mutex_unlock(&n->dev.mutex);
return r;
}
}
static long vhost_net_compat_ioctl(struct file *f, unsigned int ioctl,
unsigned long arg)
{
return vhost_net_ioctl(f, ioctl, (unsigned long)compat_ptr(arg));
}
static int vhost_net_init(void)
{
if (experimental_zcopytx)
vhost_net_enable_zcopy(VHOST_NET_VQ_TX);
return misc_register(&vhost_net_misc);
}
static void vhost_net_exit(void)
{
misc_deregister(&vhost_net_misc);
}
