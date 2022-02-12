static u32 vhost_transport_get_local_cid(void)
{
return VHOST_VSOCK_DEFAULT_HOST_CID;
}
static struct vhost_vsock *__vhost_vsock_get(u32 guest_cid)
{
struct vhost_vsock *vsock;
list_for_each_entry(vsock, &vhost_vsock_list, list) {
u32 other_cid = vsock->guest_cid;
if (other_cid == 0)
continue;
if (other_cid == guest_cid) {
return vsock;
}
}
return NULL;
}
static struct vhost_vsock *vhost_vsock_get(u32 guest_cid)
{
struct vhost_vsock *vsock;
spin_lock_bh(&vhost_vsock_lock);
vsock = __vhost_vsock_get(guest_cid);
spin_unlock_bh(&vhost_vsock_lock);
return vsock;
}
static void
vhost_transport_do_send_pkt(struct vhost_vsock *vsock,
struct vhost_virtqueue *vq)
{
struct vhost_virtqueue *tx_vq = &vsock->vqs[VSOCK_VQ_TX];
bool added = false;
bool restart_tx = false;
mutex_lock(&vq->mutex);
if (!vq->private_data)
goto out;
vhost_disable_notify(&vsock->dev, vq);
for (;;) {
struct virtio_vsock_pkt *pkt;
struct iov_iter iov_iter;
unsigned out, in;
size_t nbytes;
size_t len;
int head;
spin_lock_bh(&vsock->send_pkt_list_lock);
if (list_empty(&vsock->send_pkt_list)) {
spin_unlock_bh(&vsock->send_pkt_list_lock);
vhost_enable_notify(&vsock->dev, vq);
break;
}
pkt = list_first_entry(&vsock->send_pkt_list,
struct virtio_vsock_pkt, list);
list_del_init(&pkt->list);
spin_unlock_bh(&vsock->send_pkt_list_lock);
head = vhost_get_vq_desc(vq, vq->iov, ARRAY_SIZE(vq->iov),
&out, &in, NULL, NULL);
if (head < 0) {
spin_lock_bh(&vsock->send_pkt_list_lock);
list_add(&pkt->list, &vsock->send_pkt_list);
spin_unlock_bh(&vsock->send_pkt_list_lock);
break;
}
if (head == vq->num) {
spin_lock_bh(&vsock->send_pkt_list_lock);
list_add(&pkt->list, &vsock->send_pkt_list);
spin_unlock_bh(&vsock->send_pkt_list_lock);
if (unlikely(vhost_enable_notify(&vsock->dev, vq))) {
vhost_disable_notify(&vsock->dev, vq);
continue;
}
break;
}
if (out) {
virtio_transport_free_pkt(pkt);
vq_err(vq, "Expected 0 output buffers, got %u\n", out);
break;
}
len = iov_length(&vq->iov[out], in);
iov_iter_init(&iov_iter, READ, &vq->iov[out], in, len);
nbytes = copy_to_iter(&pkt->hdr, sizeof(pkt->hdr), &iov_iter);
if (nbytes != sizeof(pkt->hdr)) {
virtio_transport_free_pkt(pkt);
vq_err(vq, "Faulted on copying pkt hdr\n");
break;
}
nbytes = copy_to_iter(pkt->buf, pkt->len, &iov_iter);
if (nbytes != pkt->len) {
virtio_transport_free_pkt(pkt);
vq_err(vq, "Faulted on copying pkt buf\n");
break;
}
vhost_add_used(vq, head, sizeof(pkt->hdr) + pkt->len);
added = true;
if (pkt->reply) {
int val;
val = atomic_dec_return(&vsock->queued_replies);
if (val + 1 == tx_vq->num)
restart_tx = true;
}
virtio_transport_free_pkt(pkt);
}
if (added)
vhost_signal(&vsock->dev, vq);
out:
mutex_unlock(&vq->mutex);
if (restart_tx)
vhost_poll_queue(&tx_vq->poll);
}
static void vhost_transport_send_pkt_work(struct vhost_work *work)
{
struct vhost_virtqueue *vq;
struct vhost_vsock *vsock;
vsock = container_of(work, struct vhost_vsock, send_pkt_work);
vq = &vsock->vqs[VSOCK_VQ_RX];
vhost_transport_do_send_pkt(vsock, vq);
}
static int
vhost_transport_send_pkt(struct virtio_vsock_pkt *pkt)
{
struct vhost_vsock *vsock;
int len = pkt->len;
vsock = vhost_vsock_get(le64_to_cpu(pkt->hdr.dst_cid));
if (!vsock) {
virtio_transport_free_pkt(pkt);
return -ENODEV;
}
if (pkt->reply)
atomic_inc(&vsock->queued_replies);
spin_lock_bh(&vsock->send_pkt_list_lock);
list_add_tail(&pkt->list, &vsock->send_pkt_list);
spin_unlock_bh(&vsock->send_pkt_list_lock);
vhost_work_queue(&vsock->dev, &vsock->send_pkt_work);
return len;
}
static struct virtio_vsock_pkt *
vhost_vsock_alloc_pkt(struct vhost_virtqueue *vq,
unsigned int out, unsigned int in)
{
struct virtio_vsock_pkt *pkt;
struct iov_iter iov_iter;
size_t nbytes;
size_t len;
if (in != 0) {
vq_err(vq, "Expected 0 input buffers, got %u\n", in);
return NULL;
}
pkt = kzalloc(sizeof(*pkt), GFP_KERNEL);
if (!pkt)
return NULL;
len = iov_length(vq->iov, out);
iov_iter_init(&iov_iter, WRITE, vq->iov, out, len);
nbytes = copy_from_iter(&pkt->hdr, sizeof(pkt->hdr), &iov_iter);
if (nbytes != sizeof(pkt->hdr)) {
vq_err(vq, "Expected %zu bytes for pkt->hdr, got %zu bytes\n",
sizeof(pkt->hdr), nbytes);
kfree(pkt);
return NULL;
}
if (le16_to_cpu(pkt->hdr.type) == VIRTIO_VSOCK_TYPE_STREAM)
pkt->len = le32_to_cpu(pkt->hdr.len);
if (!pkt->len)
return pkt;
if (pkt->len > VIRTIO_VSOCK_MAX_PKT_BUF_SIZE) {
kfree(pkt);
return NULL;
}
pkt->buf = kmalloc(pkt->len, GFP_KERNEL);
if (!pkt->buf) {
kfree(pkt);
return NULL;
}
nbytes = copy_from_iter(pkt->buf, pkt->len, &iov_iter);
if (nbytes != pkt->len) {
vq_err(vq, "Expected %u byte payload, got %zu bytes\n",
pkt->len, nbytes);
virtio_transport_free_pkt(pkt);
return NULL;
}
return pkt;
}
static bool vhost_vsock_more_replies(struct vhost_vsock *vsock)
{
struct vhost_virtqueue *vq = &vsock->vqs[VSOCK_VQ_TX];
int val;
smp_rmb();
val = atomic_read(&vsock->queued_replies);
return val < vq->num;
}
static void vhost_vsock_handle_tx_kick(struct vhost_work *work)
{
struct vhost_virtqueue *vq = container_of(work, struct vhost_virtqueue,
poll.work);
struct vhost_vsock *vsock = container_of(vq->dev, struct vhost_vsock,
dev);
struct virtio_vsock_pkt *pkt;
int head;
unsigned int out, in;
bool added = false;
mutex_lock(&vq->mutex);
if (!vq->private_data)
goto out;
vhost_disable_notify(&vsock->dev, vq);
for (;;) {
u32 len;
if (!vhost_vsock_more_replies(vsock)) {
goto no_more_replies;
}
head = vhost_get_vq_desc(vq, vq->iov, ARRAY_SIZE(vq->iov),
&out, &in, NULL, NULL);
if (head < 0)
break;
if (head == vq->num) {
if (unlikely(vhost_enable_notify(&vsock->dev, vq))) {
vhost_disable_notify(&vsock->dev, vq);
continue;
}
break;
}
pkt = vhost_vsock_alloc_pkt(vq, out, in);
if (!pkt) {
vq_err(vq, "Faulted on pkt\n");
continue;
}
len = pkt->len;
if (le64_to_cpu(pkt->hdr.src_cid) == vsock->guest_cid)
virtio_transport_recv_pkt(pkt);
else
virtio_transport_free_pkt(pkt);
vhost_add_used(vq, head, sizeof(pkt->hdr) + len);
added = true;
}
no_more_replies:
if (added)
vhost_signal(&vsock->dev, vq);
out:
mutex_unlock(&vq->mutex);
}
static void vhost_vsock_handle_rx_kick(struct vhost_work *work)
{
struct vhost_virtqueue *vq = container_of(work, struct vhost_virtqueue,
poll.work);
struct vhost_vsock *vsock = container_of(vq->dev, struct vhost_vsock,
dev);
vhost_transport_do_send_pkt(vsock, vq);
}
static int vhost_vsock_start(struct vhost_vsock *vsock)
{
struct vhost_virtqueue *vq;
size_t i;
int ret;
mutex_lock(&vsock->dev.mutex);
ret = vhost_dev_check_owner(&vsock->dev);
if (ret)
goto err;
for (i = 0; i < ARRAY_SIZE(vsock->vqs); i++) {
vq = &vsock->vqs[i];
mutex_lock(&vq->mutex);
if (!vhost_vq_access_ok(vq)) {
ret = -EFAULT;
goto err_vq;
}
if (!vq->private_data) {
vq->private_data = vsock;
ret = vhost_vq_init_access(vq);
if (ret)
goto err_vq;
}
mutex_unlock(&vq->mutex);
}
mutex_unlock(&vsock->dev.mutex);
return 0;
err_vq:
vq->private_data = NULL;
mutex_unlock(&vq->mutex);
for (i = 0; i < ARRAY_SIZE(vsock->vqs); i++) {
vq = &vsock->vqs[i];
mutex_lock(&vq->mutex);
vq->private_data = NULL;
mutex_unlock(&vq->mutex);
}
err:
mutex_unlock(&vsock->dev.mutex);
return ret;
}
static int vhost_vsock_stop(struct vhost_vsock *vsock)
{
size_t i;
int ret;
mutex_lock(&vsock->dev.mutex);
ret = vhost_dev_check_owner(&vsock->dev);
if (ret)
goto err;
for (i = 0; i < ARRAY_SIZE(vsock->vqs); i++) {
struct vhost_virtqueue *vq = &vsock->vqs[i];
mutex_lock(&vq->mutex);
vq->private_data = NULL;
mutex_unlock(&vq->mutex);
}
err:
mutex_unlock(&vsock->dev.mutex);
return ret;
}
static void vhost_vsock_free(struct vhost_vsock *vsock)
{
kvfree(vsock);
}
static int vhost_vsock_dev_open(struct inode *inode, struct file *file)
{
struct vhost_virtqueue **vqs;
struct vhost_vsock *vsock;
int ret;
vsock = kzalloc(sizeof(*vsock), GFP_KERNEL | __GFP_NOWARN | __GFP_REPEAT);
if (!vsock) {
vsock = vmalloc(sizeof(*vsock));
if (!vsock)
return -ENOMEM;
}
vqs = kmalloc_array(ARRAY_SIZE(vsock->vqs), sizeof(*vqs), GFP_KERNEL);
if (!vqs) {
ret = -ENOMEM;
goto out;
}
atomic_set(&vsock->queued_replies, 0);
vqs[VSOCK_VQ_TX] = &vsock->vqs[VSOCK_VQ_TX];
vqs[VSOCK_VQ_RX] = &vsock->vqs[VSOCK_VQ_RX];
vsock->vqs[VSOCK_VQ_TX].handle_kick = vhost_vsock_handle_tx_kick;
vsock->vqs[VSOCK_VQ_RX].handle_kick = vhost_vsock_handle_rx_kick;
vhost_dev_init(&vsock->dev, vqs, ARRAY_SIZE(vsock->vqs));
file->private_data = vsock;
spin_lock_init(&vsock->send_pkt_list_lock);
INIT_LIST_HEAD(&vsock->send_pkt_list);
vhost_work_init(&vsock->send_pkt_work, vhost_transport_send_pkt_work);
spin_lock_bh(&vhost_vsock_lock);
list_add_tail(&vsock->list, &vhost_vsock_list);
spin_unlock_bh(&vhost_vsock_lock);
return 0;
out:
vhost_vsock_free(vsock);
return ret;
}
static void vhost_vsock_flush(struct vhost_vsock *vsock)
{
int i;
for (i = 0; i < ARRAY_SIZE(vsock->vqs); i++)
if (vsock->vqs[i].handle_kick)
vhost_poll_flush(&vsock->vqs[i].poll);
vhost_work_flush(&vsock->dev, &vsock->send_pkt_work);
}
static void vhost_vsock_reset_orphans(struct sock *sk)
{
struct vsock_sock *vsk = vsock_sk(sk);
if (!vhost_vsock_get(vsk->remote_addr.svm_cid)) {
sock_set_flag(sk, SOCK_DONE);
vsk->peer_shutdown = SHUTDOWN_MASK;
sk->sk_state = SS_UNCONNECTED;
sk->sk_err = ECONNRESET;
sk->sk_error_report(sk);
}
}
static int vhost_vsock_dev_release(struct inode *inode, struct file *file)
{
struct vhost_vsock *vsock = file->private_data;
spin_lock_bh(&vhost_vsock_lock);
list_del(&vsock->list);
spin_unlock_bh(&vhost_vsock_lock);
vsock_for_each_connected_socket(vhost_vsock_reset_orphans);
vhost_vsock_stop(vsock);
vhost_vsock_flush(vsock);
vhost_dev_stop(&vsock->dev);
spin_lock_bh(&vsock->send_pkt_list_lock);
while (!list_empty(&vsock->send_pkt_list)) {
struct virtio_vsock_pkt *pkt;
pkt = list_first_entry(&vsock->send_pkt_list,
struct virtio_vsock_pkt, list);
list_del_init(&pkt->list);
virtio_transport_free_pkt(pkt);
}
spin_unlock_bh(&vsock->send_pkt_list_lock);
vhost_dev_cleanup(&vsock->dev, false);
kfree(vsock->dev.vqs);
vhost_vsock_free(vsock);
return 0;
}
static int vhost_vsock_set_cid(struct vhost_vsock *vsock, u64 guest_cid)
{
struct vhost_vsock *other;
if (guest_cid <= VMADDR_CID_HOST ||
guest_cid == U32_MAX)
return -EINVAL;
if (guest_cid > U32_MAX)
return -EINVAL;
spin_lock_bh(&vhost_vsock_lock);
other = __vhost_vsock_get(guest_cid);
if (other && other != vsock) {
spin_unlock_bh(&vhost_vsock_lock);
return -EADDRINUSE;
}
vsock->guest_cid = guest_cid;
spin_unlock_bh(&vhost_vsock_lock);
return 0;
}
static int vhost_vsock_set_features(struct vhost_vsock *vsock, u64 features)
{
struct vhost_virtqueue *vq;
int i;
if (features & ~VHOST_VSOCK_FEATURES)
return -EOPNOTSUPP;
mutex_lock(&vsock->dev.mutex);
if ((features & (1 << VHOST_F_LOG_ALL)) &&
!vhost_log_access_ok(&vsock->dev)) {
mutex_unlock(&vsock->dev.mutex);
return -EFAULT;
}
for (i = 0; i < ARRAY_SIZE(vsock->vqs); i++) {
vq = &vsock->vqs[i];
mutex_lock(&vq->mutex);
vq->acked_features = features;
mutex_unlock(&vq->mutex);
}
mutex_unlock(&vsock->dev.mutex);
return 0;
}
static long vhost_vsock_dev_ioctl(struct file *f, unsigned int ioctl,
unsigned long arg)
{
struct vhost_vsock *vsock = f->private_data;
void __user *argp = (void __user *)arg;
u64 guest_cid;
u64 features;
int start;
int r;
switch (ioctl) {
case VHOST_VSOCK_SET_GUEST_CID:
if (copy_from_user(&guest_cid, argp, sizeof(guest_cid)))
return -EFAULT;
return vhost_vsock_set_cid(vsock, guest_cid);
case VHOST_VSOCK_SET_RUNNING:
if (copy_from_user(&start, argp, sizeof(start)))
return -EFAULT;
if (start)
return vhost_vsock_start(vsock);
else
return vhost_vsock_stop(vsock);
case VHOST_GET_FEATURES:
features = VHOST_VSOCK_FEATURES;
if (copy_to_user(argp, &features, sizeof(features)))
return -EFAULT;
return 0;
case VHOST_SET_FEATURES:
if (copy_from_user(&features, argp, sizeof(features)))
return -EFAULT;
return vhost_vsock_set_features(vsock, features);
default:
mutex_lock(&vsock->dev.mutex);
r = vhost_dev_ioctl(&vsock->dev, ioctl, argp);
if (r == -ENOIOCTLCMD)
r = vhost_vring_ioctl(&vsock->dev, ioctl, argp);
else
vhost_vsock_flush(vsock);
mutex_unlock(&vsock->dev.mutex);
return r;
}
}
static int __init vhost_vsock_init(void)
{
int ret;
ret = vsock_core_init(&vhost_transport.transport);
if (ret < 0)
return ret;
return misc_register(&vhost_vsock_misc);
}
static void __exit vhost_vsock_exit(void)
{
misc_deregister(&vhost_vsock_misc);
vsock_core_exit();
}
