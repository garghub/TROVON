static inline void high_nmcpy(unsigned char *dst, char *src)
{
memcpy(dst, src, 8);
}
static inline void low_nmcpy(unsigned char *dst, char *src)
{
memcpy(&dst[8], src, 8);
}
static int afiucv_pm_prepare(struct device *dev)
{
#ifdef CONFIG_PM_DEBUG
printk(KERN_WARNING "afiucv_pm_prepare\n");
#endif
return 0;
}
static void afiucv_pm_complete(struct device *dev)
{
#ifdef CONFIG_PM_DEBUG
printk(KERN_WARNING "afiucv_pm_complete\n");
#endif
}
static int afiucv_pm_freeze(struct device *dev)
{
struct iucv_sock *iucv;
struct sock *sk;
struct hlist_node *node;
int err = 0;
#ifdef CONFIG_PM_DEBUG
printk(KERN_WARNING "afiucv_pm_freeze\n");
#endif
read_lock(&iucv_sk_list.lock);
sk_for_each(sk, node, &iucv_sk_list.head) {
iucv = iucv_sk(sk);
skb_queue_purge(&iucv->send_skb_q);
skb_queue_purge(&iucv->backlog_skb_q);
switch (sk->sk_state) {
case IUCV_SEVERED:
case IUCV_DISCONN:
case IUCV_CLOSING:
case IUCV_CONNECTED:
if (iucv->path) {
err = iucv_path_sever(iucv->path, NULL);
iucv_path_free(iucv->path);
iucv->path = NULL;
}
break;
case IUCV_OPEN:
case IUCV_BOUND:
case IUCV_LISTEN:
case IUCV_CLOSED:
default:
break;
}
}
read_unlock(&iucv_sk_list.lock);
return err;
}
static int afiucv_pm_restore_thaw(struct device *dev)
{
struct sock *sk;
struct hlist_node *node;
#ifdef CONFIG_PM_DEBUG
printk(KERN_WARNING "afiucv_pm_restore_thaw\n");
#endif
read_lock(&iucv_sk_list.lock);
sk_for_each(sk, node, &iucv_sk_list.head) {
switch (sk->sk_state) {
case IUCV_CONNECTED:
sk->sk_err = EPIPE;
sk->sk_state = IUCV_DISCONN;
sk->sk_state_change(sk);
break;
case IUCV_DISCONN:
case IUCV_SEVERED:
case IUCV_CLOSING:
case IUCV_LISTEN:
case IUCV_BOUND:
case IUCV_OPEN:
default:
break;
}
}
read_unlock(&iucv_sk_list.lock);
return 0;
}
static inline size_t iucv_msg_length(struct iucv_message *msg)
{
size_t datalen;
if (msg->flags & IUCV_IPRMDATA) {
datalen = 0xff - msg->rmmsg[7];
return (datalen < 8) ? datalen : 8;
}
return msg->length;
}
static int iucv_sock_in_state(struct sock *sk, int state, int state2)
{
return (sk->sk_state == state || sk->sk_state == state2);
}
static inline int iucv_below_msglim(struct sock *sk)
{
struct iucv_sock *iucv = iucv_sk(sk);
if (sk->sk_state != IUCV_CONNECTED)
return 1;
return (skb_queue_len(&iucv->send_skb_q) < iucv->path->msglim);
}
static void iucv_sock_wake_msglim(struct sock *sk)
{
struct socket_wq *wq;
rcu_read_lock();
wq = rcu_dereference(sk->sk_wq);
if (wq_has_sleeper(wq))
wake_up_interruptible_all(&wq->wait);
sk_wake_async(sk, SOCK_WAKE_SPACE, POLL_OUT);
rcu_read_unlock();
}
static void iucv_sock_timeout(unsigned long arg)
{
struct sock *sk = (struct sock *)arg;
bh_lock_sock(sk);
sk->sk_err = ETIMEDOUT;
sk->sk_state_change(sk);
bh_unlock_sock(sk);
iucv_sock_kill(sk);
sock_put(sk);
}
static void iucv_sock_clear_timer(struct sock *sk)
{
sk_stop_timer(sk, &sk->sk_timer);
}
static struct sock *__iucv_get_sock_by_name(char *nm)
{
struct sock *sk;
struct hlist_node *node;
sk_for_each(sk, node, &iucv_sk_list.head)
if (!memcmp(&iucv_sk(sk)->src_name, nm, 8))
return sk;
return NULL;
}
static void iucv_sock_destruct(struct sock *sk)
{
skb_queue_purge(&sk->sk_receive_queue);
skb_queue_purge(&sk->sk_write_queue);
}
static void iucv_sock_cleanup_listen(struct sock *parent)
{
struct sock *sk;
while ((sk = iucv_accept_dequeue(parent, NULL))) {
iucv_sock_close(sk);
iucv_sock_kill(sk);
}
parent->sk_state = IUCV_CLOSED;
}
static void iucv_sock_kill(struct sock *sk)
{
if (!sock_flag(sk, SOCK_ZAPPED) || sk->sk_socket)
return;
iucv_sock_unlink(&iucv_sk_list, sk);
sock_set_flag(sk, SOCK_DEAD);
sock_put(sk);
}
static void iucv_sock_close(struct sock *sk)
{
unsigned char user_data[16];
struct iucv_sock *iucv = iucv_sk(sk);
unsigned long timeo;
iucv_sock_clear_timer(sk);
lock_sock(sk);
switch (sk->sk_state) {
case IUCV_LISTEN:
iucv_sock_cleanup_listen(sk);
break;
case IUCV_CONNECTED:
case IUCV_DISCONN:
sk->sk_state = IUCV_CLOSING;
sk->sk_state_change(sk);
if (!skb_queue_empty(&iucv->send_skb_q)) {
if (sock_flag(sk, SOCK_LINGER) && sk->sk_lingertime)
timeo = sk->sk_lingertime;
else
timeo = IUCV_DISCONN_TIMEOUT;
iucv_sock_wait(sk,
iucv_sock_in_state(sk, IUCV_CLOSED, 0),
timeo);
}
case IUCV_CLOSING:
sk->sk_state = IUCV_CLOSED;
sk->sk_state_change(sk);
if (iucv->path) {
low_nmcpy(user_data, iucv->src_name);
high_nmcpy(user_data, iucv->dst_name);
ASCEBC(user_data, sizeof(user_data));
iucv_path_sever(iucv->path, user_data);
iucv_path_free(iucv->path);
iucv->path = NULL;
}
sk->sk_err = ECONNRESET;
sk->sk_state_change(sk);
skb_queue_purge(&iucv->send_skb_q);
skb_queue_purge(&iucv->backlog_skb_q);
break;
default:
break;
}
sock_set_flag(sk, SOCK_ZAPPED);
release_sock(sk);
}
static void iucv_sock_init(struct sock *sk, struct sock *parent)
{
if (parent)
sk->sk_type = parent->sk_type;
}
static struct sock *iucv_sock_alloc(struct socket *sock, int proto, gfp_t prio)
{
struct sock *sk;
sk = sk_alloc(&init_net, PF_IUCV, prio, &iucv_proto);
if (!sk)
return NULL;
sock_init_data(sock, sk);
INIT_LIST_HEAD(&iucv_sk(sk)->accept_q);
spin_lock_init(&iucv_sk(sk)->accept_q_lock);
skb_queue_head_init(&iucv_sk(sk)->send_skb_q);
INIT_LIST_HEAD(&iucv_sk(sk)->message_q.list);
spin_lock_init(&iucv_sk(sk)->message_q.lock);
skb_queue_head_init(&iucv_sk(sk)->backlog_skb_q);
iucv_sk(sk)->send_tag = 0;
iucv_sk(sk)->flags = 0;
iucv_sk(sk)->msglimit = IUCV_QUEUELEN_DEFAULT;
iucv_sk(sk)->path = NULL;
memset(&iucv_sk(sk)->src_user_id , 0, 32);
sk->sk_destruct = iucv_sock_destruct;
sk->sk_sndtimeo = IUCV_CONN_TIMEOUT;
sk->sk_allocation = GFP_DMA;
sock_reset_flag(sk, SOCK_ZAPPED);
sk->sk_protocol = proto;
sk->sk_state = IUCV_OPEN;
setup_timer(&sk->sk_timer, iucv_sock_timeout, (unsigned long)sk);
iucv_sock_link(&iucv_sk_list, sk);
return sk;
}
static int iucv_sock_create(struct net *net, struct socket *sock, int protocol,
int kern)
{
struct sock *sk;
if (protocol && protocol != PF_IUCV)
return -EPROTONOSUPPORT;
sock->state = SS_UNCONNECTED;
switch (sock->type) {
case SOCK_STREAM:
sock->ops = &iucv_sock_ops;
break;
case SOCK_SEQPACKET:
sock->ops = &iucv_sock_ops;
break;
default:
return -ESOCKTNOSUPPORT;
}
sk = iucv_sock_alloc(sock, protocol, GFP_KERNEL);
if (!sk)
return -ENOMEM;
iucv_sock_init(sk, NULL);
return 0;
}
void iucv_sock_link(struct iucv_sock_list *l, struct sock *sk)
{
write_lock_bh(&l->lock);
sk_add_node(sk, &l->head);
write_unlock_bh(&l->lock);
}
void iucv_sock_unlink(struct iucv_sock_list *l, struct sock *sk)
{
write_lock_bh(&l->lock);
sk_del_node_init(sk);
write_unlock_bh(&l->lock);
}
void iucv_accept_enqueue(struct sock *parent, struct sock *sk)
{
unsigned long flags;
struct iucv_sock *par = iucv_sk(parent);
sock_hold(sk);
spin_lock_irqsave(&par->accept_q_lock, flags);
list_add_tail(&iucv_sk(sk)->accept_q, &par->accept_q);
spin_unlock_irqrestore(&par->accept_q_lock, flags);
iucv_sk(sk)->parent = parent;
sk_acceptq_added(parent);
}
void iucv_accept_unlink(struct sock *sk)
{
unsigned long flags;
struct iucv_sock *par = iucv_sk(iucv_sk(sk)->parent);
spin_lock_irqsave(&par->accept_q_lock, flags);
list_del_init(&iucv_sk(sk)->accept_q);
spin_unlock_irqrestore(&par->accept_q_lock, flags);
sk_acceptq_removed(iucv_sk(sk)->parent);
iucv_sk(sk)->parent = NULL;
sock_put(sk);
}
struct sock *iucv_accept_dequeue(struct sock *parent, struct socket *newsock)
{
struct iucv_sock *isk, *n;
struct sock *sk;
list_for_each_entry_safe(isk, n, &iucv_sk(parent)->accept_q, accept_q) {
sk = (struct sock *) isk;
lock_sock(sk);
if (sk->sk_state == IUCV_CLOSED) {
iucv_accept_unlink(sk);
release_sock(sk);
continue;
}
if (sk->sk_state == IUCV_CONNECTED ||
sk->sk_state == IUCV_SEVERED ||
sk->sk_state == IUCV_DISCONN ||
!newsock) {
iucv_accept_unlink(sk);
if (newsock)
sock_graft(sk, newsock);
if (sk->sk_state == IUCV_SEVERED)
sk->sk_state = IUCV_DISCONN;
release_sock(sk);
return sk;
}
release_sock(sk);
}
return NULL;
}
static int iucv_sock_bind(struct socket *sock, struct sockaddr *addr,
int addr_len)
{
struct sockaddr_iucv *sa = (struct sockaddr_iucv *) addr;
struct sock *sk = sock->sk;
struct iucv_sock *iucv;
int err;
if (!addr || addr->sa_family != AF_IUCV)
return -EINVAL;
lock_sock(sk);
if (sk->sk_state != IUCV_OPEN) {
err = -EBADFD;
goto done;
}
write_lock_bh(&iucv_sk_list.lock);
iucv = iucv_sk(sk);
if (__iucv_get_sock_by_name(sa->siucv_name)) {
err = -EADDRINUSE;
goto done_unlock;
}
if (iucv->path) {
err = 0;
goto done_unlock;
}
memcpy(iucv->src_name, sa->siucv_name, 8);
memcpy(iucv->src_user_id, iucv_userid, 8);
sk->sk_state = IUCV_BOUND;
err = 0;
done_unlock:
write_unlock_bh(&iucv_sk_list.lock);
done:
release_sock(sk);
return err;
}
static int iucv_sock_autobind(struct sock *sk)
{
struct iucv_sock *iucv = iucv_sk(sk);
char query_buffer[80];
char name[12];
int err = 0;
cpcmd("QUERY USERID", query_buffer, sizeof(query_buffer), &err);
if (unlikely(err))
return -EPROTO;
memcpy(iucv->src_user_id, query_buffer, 8);
write_lock_bh(&iucv_sk_list.lock);
sprintf(name, "%08x", atomic_inc_return(&iucv_sk_list.autobind_name));
while (__iucv_get_sock_by_name(name)) {
sprintf(name, "%08x",
atomic_inc_return(&iucv_sk_list.autobind_name));
}
write_unlock_bh(&iucv_sk_list.lock);
memcpy(&iucv->src_name, name, 8);
return err;
}
static int iucv_sock_connect(struct socket *sock, struct sockaddr *addr,
int alen, int flags)
{
struct sockaddr_iucv *sa = (struct sockaddr_iucv *) addr;
struct sock *sk = sock->sk;
struct iucv_sock *iucv;
unsigned char user_data[16];
int err;
if (addr->sa_family != AF_IUCV || alen < sizeof(struct sockaddr_iucv))
return -EINVAL;
if (sk->sk_state != IUCV_OPEN && sk->sk_state != IUCV_BOUND)
return -EBADFD;
if (sk->sk_type != SOCK_STREAM && sk->sk_type != SOCK_SEQPACKET)
return -EINVAL;
if (sk->sk_state == IUCV_OPEN) {
err = iucv_sock_autobind(sk);
if (unlikely(err))
return err;
}
lock_sock(sk);
memcpy(iucv_sk(sk)->dst_user_id, sa->siucv_user_id, 8);
memcpy(iucv_sk(sk)->dst_name, sa->siucv_name, 8);
high_nmcpy(user_data, sa->siucv_name);
low_nmcpy(user_data, iucv_sk(sk)->src_name);
ASCEBC(user_data, sizeof(user_data));
iucv = iucv_sk(sk);
iucv->path = iucv_path_alloc(iucv->msglimit,
IUCV_IPRMDATA, GFP_KERNEL);
if (!iucv->path) {
err = -ENOMEM;
goto done;
}
err = iucv_path_connect(iucv->path, &af_iucv_handler,
sa->siucv_user_id, NULL, user_data, sk);
if (err) {
iucv_path_free(iucv->path);
iucv->path = NULL;
switch (err) {
case 0x0b:
err = -ENETUNREACH;
break;
case 0x0d:
case 0x0e:
err = -EAGAIN;
break;
case 0x0f:
err = -EACCES;
break;
default:
err = -ECONNREFUSED;
break;
}
goto done;
}
if (sk->sk_state != IUCV_CONNECTED) {
err = iucv_sock_wait(sk, iucv_sock_in_state(sk, IUCV_CONNECTED,
IUCV_DISCONN),
sock_sndtimeo(sk, flags & O_NONBLOCK));
}
if (sk->sk_state == IUCV_DISCONN) {
err = -ECONNREFUSED;
}
if (err) {
iucv_path_sever(iucv->path, NULL);
iucv_path_free(iucv->path);
iucv->path = NULL;
}
done:
release_sock(sk);
return err;
}
static int iucv_sock_listen(struct socket *sock, int backlog)
{
struct sock *sk = sock->sk;
int err;
lock_sock(sk);
err = -EINVAL;
if (sk->sk_state != IUCV_BOUND)
goto done;
if (sock->type != SOCK_STREAM && sock->type != SOCK_SEQPACKET)
goto done;
sk->sk_max_ack_backlog = backlog;
sk->sk_ack_backlog = 0;
sk->sk_state = IUCV_LISTEN;
err = 0;
done:
release_sock(sk);
return err;
}
static int iucv_sock_accept(struct socket *sock, struct socket *newsock,
int flags)
{
DECLARE_WAITQUEUE(wait, current);
struct sock *sk = sock->sk, *nsk;
long timeo;
int err = 0;
lock_sock_nested(sk, SINGLE_DEPTH_NESTING);
if (sk->sk_state != IUCV_LISTEN) {
err = -EBADFD;
goto done;
}
timeo = sock_rcvtimeo(sk, flags & O_NONBLOCK);
add_wait_queue_exclusive(sk_sleep(sk), &wait);
while (!(nsk = iucv_accept_dequeue(sk, newsock))) {
set_current_state(TASK_INTERRUPTIBLE);
if (!timeo) {
err = -EAGAIN;
break;
}
release_sock(sk);
timeo = schedule_timeout(timeo);
lock_sock_nested(sk, SINGLE_DEPTH_NESTING);
if (sk->sk_state != IUCV_LISTEN) {
err = -EBADFD;
break;
}
if (signal_pending(current)) {
err = sock_intr_errno(timeo);
break;
}
}
set_current_state(TASK_RUNNING);
remove_wait_queue(sk_sleep(sk), &wait);
if (err)
goto done;
newsock->state = SS_CONNECTED;
done:
release_sock(sk);
return err;
}
static int iucv_sock_getname(struct socket *sock, struct sockaddr *addr,
int *len, int peer)
{
struct sockaddr_iucv *siucv = (struct sockaddr_iucv *) addr;
struct sock *sk = sock->sk;
addr->sa_family = AF_IUCV;
*len = sizeof(struct sockaddr_iucv);
if (peer) {
memcpy(siucv->siucv_user_id, iucv_sk(sk)->dst_user_id, 8);
memcpy(siucv->siucv_name, &iucv_sk(sk)->dst_name, 8);
} else {
memcpy(siucv->siucv_user_id, iucv_sk(sk)->src_user_id, 8);
memcpy(siucv->siucv_name, iucv_sk(sk)->src_name, 8);
}
memset(&siucv->siucv_port, 0, sizeof(siucv->siucv_port));
memset(&siucv->siucv_addr, 0, sizeof(siucv->siucv_addr));
memset(siucv->siucv_nodeid, 0, sizeof(siucv->siucv_nodeid));
return 0;
}
static int iucv_send_iprm(struct iucv_path *path, struct iucv_message *msg,
struct sk_buff *skb)
{
u8 prmdata[8];
memcpy(prmdata, (void *) skb->data, skb->len);
prmdata[7] = 0xff - (u8) skb->len;
return iucv_message_send(path, msg, IUCV_IPRMDATA, 0,
(void *) prmdata, 8);
}
static int iucv_sock_sendmsg(struct kiocb *iocb, struct socket *sock,
struct msghdr *msg, size_t len)
{
struct sock *sk = sock->sk;
struct iucv_sock *iucv = iucv_sk(sk);
struct sk_buff *skb;
struct iucv_message txmsg;
struct cmsghdr *cmsg;
int cmsg_done;
long timeo;
char user_id[9];
char appl_id[9];
int err;
int noblock = msg->msg_flags & MSG_DONTWAIT;
err = sock_error(sk);
if (err)
return err;
if (msg->msg_flags & MSG_OOB)
return -EOPNOTSUPP;
if (sk->sk_type == SOCK_SEQPACKET && !(msg->msg_flags & MSG_EOR))
return -EOPNOTSUPP;
lock_sock(sk);
if (sk->sk_shutdown & SEND_SHUTDOWN) {
err = -EPIPE;
goto out;
}
if (sk->sk_state != IUCV_CONNECTED) {
err = -ENOTCONN;
goto out;
}
cmsg_done = 0;
txmsg.class = 0;
for (cmsg = CMSG_FIRSTHDR(msg); cmsg;
cmsg = CMSG_NXTHDR(msg, cmsg)) {
if (!CMSG_OK(msg, cmsg)) {
err = -EINVAL;
goto out;
}
if (cmsg->cmsg_level != SOL_IUCV)
continue;
if (cmsg->cmsg_type & cmsg_done) {
err = -EINVAL;
goto out;
}
cmsg_done |= cmsg->cmsg_type;
switch (cmsg->cmsg_type) {
case SCM_IUCV_TRGCLS:
if (cmsg->cmsg_len != CMSG_LEN(TRGCLS_SIZE)) {
err = -EINVAL;
goto out;
}
memcpy(&txmsg.class,
(void *) CMSG_DATA(cmsg), TRGCLS_SIZE);
break;
default:
err = -EINVAL;
goto out;
break;
}
}
skb = sock_alloc_send_skb(sk, len, noblock, &err);
if (!skb)
goto out;
if (memcpy_fromiovec(skb_put(skb, len), msg->msg_iov, len)) {
err = -EFAULT;
goto fail;
}
timeo = sock_sndtimeo(sk, noblock);
err = iucv_sock_wait(sk, iucv_below_msglim(sk), timeo);
if (err)
goto fail;
if (sk->sk_state != IUCV_CONNECTED) {
err = -ECONNRESET;
goto fail;
}
txmsg.tag = iucv->send_tag++;
memcpy(CB_TAG(skb), &txmsg.tag, CB_TAG_LEN);
skb_queue_tail(&iucv->send_skb_q, skb);
if (((iucv->path->flags & IUCV_IPRMDATA) & iucv->flags)
&& skb->len <= 7) {
err = iucv_send_iprm(iucv->path, &txmsg, skb);
if (err == 0) {
skb_unlink(skb, &iucv->send_skb_q);
kfree_skb(skb);
}
if (err == 0x15) {
iucv_path_sever(iucv->path, NULL);
skb_unlink(skb, &iucv->send_skb_q);
err = -EPIPE;
goto fail;
}
} else
err = iucv_message_send(iucv->path, &txmsg, 0, 0,
(void *) skb->data, skb->len);
if (err) {
if (err == 3) {
user_id[8] = 0;
memcpy(user_id, iucv->dst_user_id, 8);
appl_id[8] = 0;
memcpy(appl_id, iucv->dst_name, 8);
pr_err("Application %s on z/VM guest %s"
" exceeds message limit\n",
appl_id, user_id);
err = -EAGAIN;
} else
err = -EPIPE;
skb_unlink(skb, &iucv->send_skb_q);
goto fail;
}
release_sock(sk);
return len;
fail:
kfree_skb(skb);
out:
release_sock(sk);
return err;
}
static int iucv_fragment_skb(struct sock *sk, struct sk_buff *skb, int len)
{
int dataleft, size, copied = 0;
struct sk_buff *nskb;
dataleft = len;
while (dataleft) {
if (dataleft >= sk->sk_rcvbuf / 4)
size = sk->sk_rcvbuf / 4;
else
size = dataleft;
nskb = alloc_skb(size, GFP_ATOMIC | GFP_DMA);
if (!nskb)
return -ENOMEM;
memcpy(CB_TRGCLS(nskb), CB_TRGCLS(skb), CB_TRGCLS_LEN);
memcpy(nskb->data, skb->data + copied, size);
copied += size;
dataleft -= size;
skb_reset_transport_header(nskb);
skb_reset_network_header(nskb);
nskb->len = size;
skb_queue_tail(&iucv_sk(sk)->backlog_skb_q, nskb);
}
return 0;
}
static void iucv_process_message(struct sock *sk, struct sk_buff *skb,
struct iucv_path *path,
struct iucv_message *msg)
{
int rc;
unsigned int len;
len = iucv_msg_length(msg);
memcpy(CB_TRGCLS(skb), &msg->class, CB_TRGCLS_LEN);
if ((msg->flags & IUCV_IPRMDATA) && len > 7) {
if (memcmp(msg->rmmsg, iprm_shutdown, 8) == 0) {
skb->data = NULL;
skb->len = 0;
}
} else {
rc = iucv_message_receive(path, msg, msg->flags & IUCV_IPRMDATA,
skb->data, len, NULL);
if (rc) {
kfree_skb(skb);
return;
}
if (sk->sk_type == SOCK_STREAM &&
skb->truesize >= sk->sk_rcvbuf / 4) {
rc = iucv_fragment_skb(sk, skb, len);
kfree_skb(skb);
skb = NULL;
if (rc) {
iucv_path_sever(path, NULL);
return;
}
skb = skb_dequeue(&iucv_sk(sk)->backlog_skb_q);
} else {
skb_reset_transport_header(skb);
skb_reset_network_header(skb);
skb->len = len;
}
}
if (sock_queue_rcv_skb(sk, skb))
skb_queue_head(&iucv_sk(sk)->backlog_skb_q, skb);
}
static void iucv_process_message_q(struct sock *sk)
{
struct iucv_sock *iucv = iucv_sk(sk);
struct sk_buff *skb;
struct sock_msg_q *p, *n;
list_for_each_entry_safe(p, n, &iucv->message_q.list, list) {
skb = alloc_skb(iucv_msg_length(&p->msg), GFP_ATOMIC | GFP_DMA);
if (!skb)
break;
iucv_process_message(sk, skb, p->path, &p->msg);
list_del(&p->list);
kfree(p);
if (!skb_queue_empty(&iucv->backlog_skb_q))
break;
}
}
static int iucv_sock_recvmsg(struct kiocb *iocb, struct socket *sock,
struct msghdr *msg, size_t len, int flags)
{
int noblock = flags & MSG_DONTWAIT;
struct sock *sk = sock->sk;
struct iucv_sock *iucv = iucv_sk(sk);
unsigned int copied, rlen;
struct sk_buff *skb, *rskb, *cskb;
int err = 0;
if ((sk->sk_state == IUCV_DISCONN || sk->sk_state == IUCV_SEVERED) &&
skb_queue_empty(&iucv->backlog_skb_q) &&
skb_queue_empty(&sk->sk_receive_queue) &&
list_empty(&iucv->message_q.list))
return 0;
if (flags & (MSG_OOB))
return -EOPNOTSUPP;
skb = skb_recv_datagram(sk, flags, noblock, &err);
if (!skb) {
if (sk->sk_shutdown & RCV_SHUTDOWN)
return 0;
return err;
}
rlen = skb->len;
copied = min_t(unsigned int, rlen, len);
cskb = skb;
if (memcpy_toiovec(msg->msg_iov, cskb->data, copied)) {
if (!(flags & MSG_PEEK))
skb_queue_head(&sk->sk_receive_queue, skb);
return -EFAULT;
}
if (sk->sk_type == SOCK_SEQPACKET) {
if (copied < rlen)
msg->msg_flags |= MSG_TRUNC;
msg->msg_flags |= MSG_EOR;
}
err = put_cmsg(msg, SOL_IUCV, SCM_IUCV_TRGCLS,
CB_TRGCLS_LEN, CB_TRGCLS(skb));
if (err) {
if (!(flags & MSG_PEEK))
skb_queue_head(&sk->sk_receive_queue, skb);
return err;
}
if (!(flags & MSG_PEEK)) {
if (sk->sk_type == SOCK_STREAM) {
skb_pull(skb, copied);
if (skb->len) {
skb_queue_head(&sk->sk_receive_queue, skb);
goto done;
}
}
kfree_skb(skb);
spin_lock_bh(&iucv->message_q.lock);
rskb = skb_dequeue(&iucv->backlog_skb_q);
while (rskb) {
if (sock_queue_rcv_skb(sk, rskb)) {
skb_queue_head(&iucv->backlog_skb_q,
rskb);
break;
} else {
rskb = skb_dequeue(&iucv->backlog_skb_q);
}
}
if (skb_queue_empty(&iucv->backlog_skb_q)) {
if (!list_empty(&iucv->message_q.list))
iucv_process_message_q(sk);
}
spin_unlock_bh(&iucv->message_q.lock);
}
done:
if (sk->sk_type == SOCK_SEQPACKET && (flags & MSG_TRUNC))
copied = rlen;
return copied;
}
static inline unsigned int iucv_accept_poll(struct sock *parent)
{
struct iucv_sock *isk, *n;
struct sock *sk;
list_for_each_entry_safe(isk, n, &iucv_sk(parent)->accept_q, accept_q) {
sk = (struct sock *) isk;
if (sk->sk_state == IUCV_CONNECTED)
return POLLIN | POLLRDNORM;
}
return 0;
}
unsigned int iucv_sock_poll(struct file *file, struct socket *sock,
poll_table *wait)
{
struct sock *sk = sock->sk;
unsigned int mask = 0;
sock_poll_wait(file, sk_sleep(sk), wait);
if (sk->sk_state == IUCV_LISTEN)
return iucv_accept_poll(sk);
if (sk->sk_err || !skb_queue_empty(&sk->sk_error_queue))
mask |= POLLERR;
if (sk->sk_shutdown & RCV_SHUTDOWN)
mask |= POLLRDHUP;
if (sk->sk_shutdown == SHUTDOWN_MASK)
mask |= POLLHUP;
if (!skb_queue_empty(&sk->sk_receive_queue) ||
(sk->sk_shutdown & RCV_SHUTDOWN))
mask |= POLLIN | POLLRDNORM;
if (sk->sk_state == IUCV_CLOSED)
mask |= POLLHUP;
if (sk->sk_state == IUCV_DISCONN || sk->sk_state == IUCV_SEVERED)
mask |= POLLIN;
if (sock_writeable(sk))
mask |= POLLOUT | POLLWRNORM | POLLWRBAND;
else
set_bit(SOCK_ASYNC_NOSPACE, &sk->sk_socket->flags);
return mask;
}
static int iucv_sock_shutdown(struct socket *sock, int how)
{
struct sock *sk = sock->sk;
struct iucv_sock *iucv = iucv_sk(sk);
struct iucv_message txmsg;
int err = 0;
how++;
if ((how & ~SHUTDOWN_MASK) || !how)
return -EINVAL;
lock_sock(sk);
switch (sk->sk_state) {
case IUCV_DISCONN:
case IUCV_CLOSING:
case IUCV_SEVERED:
case IUCV_CLOSED:
err = -ENOTCONN;
goto fail;
default:
sk->sk_shutdown |= how;
break;
}
if (how == SEND_SHUTDOWN || how == SHUTDOWN_MASK) {
txmsg.class = 0;
txmsg.tag = 0;
err = iucv_message_send(iucv->path, &txmsg, IUCV_IPRMDATA, 0,
(void *) iprm_shutdown, 8);
if (err) {
switch (err) {
case 1:
err = -ENOTCONN;
break;
case 2:
err = -ECONNRESET;
break;
default:
err = -ENOTCONN;
break;
}
}
}
if (how == RCV_SHUTDOWN || how == SHUTDOWN_MASK) {
err = iucv_path_quiesce(iucv_sk(sk)->path, NULL);
if (err)
err = -ENOTCONN;
skb_queue_purge(&sk->sk_receive_queue);
}
sk->sk_state_change(sk);
fail:
release_sock(sk);
return err;
}
static int iucv_sock_release(struct socket *sock)
{
struct sock *sk = sock->sk;
int err = 0;
if (!sk)
return 0;
iucv_sock_close(sk);
if (iucv_sk(sk)->path) {
iucv_path_sever(iucv_sk(sk)->path, NULL);
iucv_path_free(iucv_sk(sk)->path);
iucv_sk(sk)->path = NULL;
}
sock_orphan(sk);
iucv_sock_kill(sk);
return err;
}
static int iucv_sock_setsockopt(struct socket *sock, int level, int optname,
char __user *optval, unsigned int optlen)
{
struct sock *sk = sock->sk;
struct iucv_sock *iucv = iucv_sk(sk);
int val;
int rc;
if (level != SOL_IUCV)
return -ENOPROTOOPT;
if (optlen < sizeof(int))
return -EINVAL;
if (get_user(val, (int __user *) optval))
return -EFAULT;
rc = 0;
lock_sock(sk);
switch (optname) {
case SO_IPRMDATA_MSG:
if (val)
iucv->flags |= IUCV_IPRMDATA;
else
iucv->flags &= ~IUCV_IPRMDATA;
break;
case SO_MSGLIMIT:
switch (sk->sk_state) {
case IUCV_OPEN:
case IUCV_BOUND:
if (val < 1 || val > (u16)(~0))
rc = -EINVAL;
else
iucv->msglimit = val;
break;
default:
rc = -EINVAL;
break;
}
break;
default:
rc = -ENOPROTOOPT;
break;
}
release_sock(sk);
return rc;
}
static int iucv_sock_getsockopt(struct socket *sock, int level, int optname,
char __user *optval, int __user *optlen)
{
struct sock *sk = sock->sk;
struct iucv_sock *iucv = iucv_sk(sk);
int val, len;
if (level != SOL_IUCV)
return -ENOPROTOOPT;
if (get_user(len, optlen))
return -EFAULT;
if (len < 0)
return -EINVAL;
len = min_t(unsigned int, len, sizeof(int));
switch (optname) {
case SO_IPRMDATA_MSG:
val = (iucv->flags & IUCV_IPRMDATA) ? 1 : 0;
break;
case SO_MSGLIMIT:
lock_sock(sk);
val = (iucv->path != NULL) ? iucv->path->msglim
: iucv->msglimit;
release_sock(sk);
break;
default:
return -ENOPROTOOPT;
}
if (put_user(len, optlen))
return -EFAULT;
if (copy_to_user(optval, &val, len))
return -EFAULT;
return 0;
}
static int iucv_callback_connreq(struct iucv_path *path,
u8 ipvmid[8], u8 ipuser[16])
{
unsigned char user_data[16];
unsigned char nuser_data[16];
unsigned char src_name[8];
struct hlist_node *node;
struct sock *sk, *nsk;
struct iucv_sock *iucv, *niucv;
int err;
memcpy(src_name, ipuser, 8);
EBCASC(src_name, 8);
read_lock(&iucv_sk_list.lock);
iucv = NULL;
sk = NULL;
sk_for_each(sk, node, &iucv_sk_list.head)
if (sk->sk_state == IUCV_LISTEN &&
!memcmp(&iucv_sk(sk)->src_name, src_name, 8)) {
iucv = iucv_sk(sk);
break;
}
read_unlock(&iucv_sk_list.lock);
if (!iucv)
return -EINVAL;
bh_lock_sock(sk);
low_nmcpy(user_data, iucv->src_name);
high_nmcpy(user_data, iucv->dst_name);
ASCEBC(user_data, sizeof(user_data));
if (sk->sk_state != IUCV_LISTEN) {
err = iucv_path_sever(path, user_data);
iucv_path_free(path);
goto fail;
}
if (sk_acceptq_is_full(sk)) {
err = iucv_path_sever(path, user_data);
iucv_path_free(path);
goto fail;
}
nsk = iucv_sock_alloc(NULL, sk->sk_type, GFP_ATOMIC);
if (!nsk) {
err = iucv_path_sever(path, user_data);
iucv_path_free(path);
goto fail;
}
niucv = iucv_sk(nsk);
iucv_sock_init(nsk, sk);
memcpy(niucv->dst_name, ipuser + 8, 8);
EBCASC(niucv->dst_name, 8);
memcpy(niucv->dst_user_id, ipvmid, 8);
memcpy(niucv->src_name, iucv->src_name, 8);
memcpy(niucv->src_user_id, iucv->src_user_id, 8);
niucv->path = path;
high_nmcpy(nuser_data, ipuser + 8);
memcpy(nuser_data + 8, niucv->src_name, 8);
ASCEBC(nuser_data + 8, 8);
niucv->msglimit = iucv->msglimit;
path->msglim = iucv->msglimit;
err = iucv_path_accept(path, &af_iucv_handler, nuser_data, nsk);
if (err) {
err = iucv_path_sever(path, user_data);
iucv_path_free(path);
iucv_sock_kill(nsk);
goto fail;
}
iucv_accept_enqueue(sk, nsk);
nsk->sk_state = IUCV_CONNECTED;
sk->sk_data_ready(sk, 1);
err = 0;
fail:
bh_unlock_sock(sk);
return 0;
}
static void iucv_callback_connack(struct iucv_path *path, u8 ipuser[16])
{
struct sock *sk = path->private;
sk->sk_state = IUCV_CONNECTED;
sk->sk_state_change(sk);
}
static void iucv_callback_rx(struct iucv_path *path, struct iucv_message *msg)
{
struct sock *sk = path->private;
struct iucv_sock *iucv = iucv_sk(sk);
struct sk_buff *skb;
struct sock_msg_q *save_msg;
int len;
if (sk->sk_shutdown & RCV_SHUTDOWN) {
iucv_message_reject(path, msg);
return;
}
spin_lock(&iucv->message_q.lock);
if (!list_empty(&iucv->message_q.list) ||
!skb_queue_empty(&iucv->backlog_skb_q))
goto save_message;
len = atomic_read(&sk->sk_rmem_alloc);
len += iucv_msg_length(msg) + sizeof(struct sk_buff);
if (len > sk->sk_rcvbuf)
goto save_message;
skb = alloc_skb(iucv_msg_length(msg), GFP_ATOMIC | GFP_DMA);
if (!skb)
goto save_message;
iucv_process_message(sk, skb, path, msg);
goto out_unlock;
save_message:
save_msg = kzalloc(sizeof(struct sock_msg_q), GFP_ATOMIC | GFP_DMA);
if (!save_msg)
goto out_unlock;
save_msg->path = path;
save_msg->msg = *msg;
list_add_tail(&save_msg->list, &iucv->message_q.list);
out_unlock:
spin_unlock(&iucv->message_q.lock);
}
static void iucv_callback_txdone(struct iucv_path *path,
struct iucv_message *msg)
{
struct sock *sk = path->private;
struct sk_buff *this = NULL;
struct sk_buff_head *list = &iucv_sk(sk)->send_skb_q;
struct sk_buff *list_skb = list->next;
unsigned long flags;
if (!skb_queue_empty(list)) {
spin_lock_irqsave(&list->lock, flags);
while (list_skb != (struct sk_buff *)list) {
if (!memcmp(&msg->tag, CB_TAG(list_skb), CB_TAG_LEN)) {
this = list_skb;
break;
}
list_skb = list_skb->next;
}
if (this)
__skb_unlink(this, list);
spin_unlock_irqrestore(&list->lock, flags);
if (this) {
kfree_skb(this);
iucv_sock_wake_msglim(sk);
}
}
BUG_ON(!this);
if (sk->sk_state == IUCV_CLOSING) {
if (skb_queue_empty(&iucv_sk(sk)->send_skb_q)) {
sk->sk_state = IUCV_CLOSED;
sk->sk_state_change(sk);
}
}
}
static void iucv_callback_connrej(struct iucv_path *path, u8 ipuser[16])
{
struct sock *sk = path->private;
if (!list_empty(&iucv_sk(sk)->accept_q))
sk->sk_state = IUCV_SEVERED;
else
sk->sk_state = IUCV_DISCONN;
sk->sk_state_change(sk);
}
static void iucv_callback_shutdown(struct iucv_path *path, u8 ipuser[16])
{
struct sock *sk = path->private;
bh_lock_sock(sk);
if (sk->sk_state != IUCV_CLOSED) {
sk->sk_shutdown |= SEND_SHUTDOWN;
sk->sk_state_change(sk);
}
bh_unlock_sock(sk);
}
static int __init afiucv_init(void)
{
int err;
if (!MACHINE_IS_VM) {
pr_err("The af_iucv module cannot be loaded"
" without z/VM\n");
err = -EPROTONOSUPPORT;
goto out;
}
cpcmd("QUERY USERID", iucv_userid, sizeof(iucv_userid), &err);
if (unlikely(err)) {
WARN_ON(err);
err = -EPROTONOSUPPORT;
goto out;
}
err = iucv_register(&af_iucv_handler, 0);
if (err)
goto out;
err = proto_register(&iucv_proto, 0);
if (err)
goto out_iucv;
err = sock_register(&iucv_sock_family_ops);
if (err)
goto out_proto;
err = driver_register(&af_iucv_driver);
if (err)
goto out_sock;
af_iucv_dev = kzalloc(sizeof(struct device), GFP_KERNEL);
if (!af_iucv_dev) {
err = -ENOMEM;
goto out_driver;
}
dev_set_name(af_iucv_dev, "af_iucv");
af_iucv_dev->bus = &iucv_bus;
af_iucv_dev->parent = iucv_root;
af_iucv_dev->release = (void (*)(struct device *))kfree;
af_iucv_dev->driver = &af_iucv_driver;
err = device_register(af_iucv_dev);
if (err)
goto out_driver;
return 0;
out_driver:
driver_unregister(&af_iucv_driver);
out_sock:
sock_unregister(PF_IUCV);
out_proto:
proto_unregister(&iucv_proto);
out_iucv:
iucv_unregister(&af_iucv_handler, 0);
out:
return err;
}
static void __exit afiucv_exit(void)
{
device_unregister(af_iucv_dev);
driver_unregister(&af_iucv_driver);
sock_unregister(PF_IUCV);
proto_unregister(&iucv_proto);
iucv_unregister(&af_iucv_handler, 0);
}
