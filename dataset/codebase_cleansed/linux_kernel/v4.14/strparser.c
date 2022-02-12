static inline struct _strp_msg *_strp_msg(struct sk_buff *skb)
{
return (struct _strp_msg *)((void *)skb->cb +
offsetof(struct qdisc_skb_cb, data));
}
static void strp_abort_strp(struct strparser *strp, int err)
{
cancel_delayed_work(&strp->msg_timer_work);
if (strp->stopped)
return;
strp->stopped = 1;
if (strp->sk) {
struct sock *sk = strp->sk;
sk->sk_err = err;
sk->sk_error_report(sk);
}
}
static void strp_start_timer(struct strparser *strp, long timeo)
{
if (timeo)
mod_delayed_work(strp_wq, &strp->msg_timer_work, timeo);
}
static void strp_parser_err(struct strparser *strp, int err,
read_descriptor_t *desc)
{
desc->error = err;
kfree_skb(strp->skb_head);
strp->skb_head = NULL;
strp->cb.abort_parser(strp, err);
}
static inline int strp_peek_len(struct strparser *strp)
{
if (strp->sk) {
struct socket *sock = strp->sk->sk_socket;
return sock->ops->peek_len(sock);
}
return INT_MAX;
}
static int __strp_recv(read_descriptor_t *desc, struct sk_buff *orig_skb,
unsigned int orig_offset, size_t orig_len,
size_t max_msg_size, long timeo)
{
struct strparser *strp = (struct strparser *)desc->arg.data;
struct _strp_msg *stm;
struct sk_buff *head, *skb;
size_t eaten = 0, cand_len;
ssize_t extra;
int err;
bool cloned_orig = false;
if (strp->paused)
return 0;
head = strp->skb_head;
if (head) {
stm = _strp_msg(head);
if (unlikely(stm->early_eaten)) {
eaten = orig_len <= stm->early_eaten ?
orig_len : stm->early_eaten;
stm->early_eaten -= eaten;
return eaten;
}
if (unlikely(orig_offset)) {
orig_skb = skb_clone(orig_skb, GFP_ATOMIC);
if (!orig_skb) {
STRP_STATS_INCR(strp->stats.mem_fail);
desc->error = -ENOMEM;
return 0;
}
if (!pskb_pull(orig_skb, orig_offset)) {
STRP_STATS_INCR(strp->stats.mem_fail);
kfree_skb(orig_skb);
desc->error = -ENOMEM;
return 0;
}
cloned_orig = true;
orig_offset = 0;
}
if (!strp->skb_nextp) {
err = skb_unclone(head, GFP_ATOMIC);
if (err) {
STRP_STATS_INCR(strp->stats.mem_fail);
desc->error = err;
return 0;
}
if (unlikely(skb_shinfo(head)->frag_list)) {
if (WARN_ON(head->next)) {
desc->error = -EINVAL;
return 0;
}
skb = alloc_skb(0, GFP_ATOMIC);
if (!skb) {
STRP_STATS_INCR(strp->stats.mem_fail);
desc->error = -ENOMEM;
return 0;
}
skb->len = head->len;
skb->data_len = head->len;
skb->truesize = head->truesize;
*_strp_msg(skb) = *_strp_msg(head);
strp->skb_nextp = &head->next;
skb_shinfo(skb)->frag_list = head;
strp->skb_head = skb;
head = skb;
} else {
strp->skb_nextp =
&skb_shinfo(head)->frag_list;
}
}
}
while (eaten < orig_len) {
skb = skb_clone(orig_skb, GFP_ATOMIC);
if (!skb) {
STRP_STATS_INCR(strp->stats.mem_fail);
desc->error = -ENOMEM;
break;
}
cand_len = orig_len - eaten;
head = strp->skb_head;
if (!head) {
head = skb;
strp->skb_head = head;
strp->skb_nextp = NULL;
stm = _strp_msg(head);
memset(stm, 0, sizeof(*stm));
stm->strp.offset = orig_offset + eaten;
} else {
err = skb_unclone(skb, GFP_ATOMIC);
if (err) {
STRP_STATS_INCR(strp->stats.mem_fail);
desc->error = err;
break;
}
stm = _strp_msg(head);
*strp->skb_nextp = skb;
strp->skb_nextp = &skb->next;
head->data_len += skb->len;
head->len += skb->len;
head->truesize += skb->truesize;
}
if (!stm->strp.full_len) {
ssize_t len;
len = (*strp->cb.parse_msg)(strp, head);
if (!len) {
if (!stm->accum_len) {
strp_start_timer(strp, timeo);
}
stm->accum_len += cand_len;
eaten += cand_len;
STRP_STATS_INCR(strp->stats.need_more_hdr);
WARN_ON(eaten != orig_len);
break;
} else if (len < 0) {
if (len == -ESTRPIPE && stm->accum_len) {
len = -ENODATA;
strp->unrecov_intr = 1;
} else {
strp->interrupted = 1;
}
strp_parser_err(strp, len, desc);
break;
} else if (len > max_msg_size) {
STRP_STATS_INCR(strp->stats.msg_too_big);
strp_parser_err(strp, -EMSGSIZE, desc);
break;
} else if (len <= (ssize_t)head->len -
skb->len - stm->strp.offset) {
STRP_STATS_INCR(strp->stats.bad_hdr_len);
strp_parser_err(strp, -EPROTO, desc);
break;
}
stm->strp.full_len = len;
}
extra = (ssize_t)(stm->accum_len + cand_len) -
stm->strp.full_len;
if (extra < 0) {
if (stm->strp.full_len - stm->accum_len >
strp_peek_len(strp)) {
if (!stm->accum_len) {
strp_start_timer(strp, timeo);
}
strp->need_bytes = stm->strp.full_len -
stm->accum_len;
stm->accum_len += cand_len;
stm->early_eaten = cand_len;
STRP_STATS_ADD(strp->stats.bytes, cand_len);
desc->count = 0;
break;
}
stm->accum_len += cand_len;
eaten += cand_len;
WARN_ON(eaten != orig_len);
break;
}
WARN_ON(extra > cand_len);
eaten += (cand_len - extra);
cancel_delayed_work(&strp->msg_timer_work);
strp->skb_head = NULL;
STRP_STATS_INCR(strp->stats.msgs);
strp->cb.rcv_msg(strp, head);
if (unlikely(strp->paused)) {
break;
}
}
if (cloned_orig)
kfree_skb(orig_skb);
STRP_STATS_ADD(strp->stats.bytes, eaten);
return eaten;
}
int strp_process(struct strparser *strp, struct sk_buff *orig_skb,
unsigned int orig_offset, size_t orig_len,
size_t max_msg_size, long timeo)
{
read_descriptor_t desc;
desc.arg.data = strp;
return __strp_recv(&desc, orig_skb, orig_offset, orig_len,
max_msg_size, timeo);
}
static int strp_recv(read_descriptor_t *desc, struct sk_buff *orig_skb,
unsigned int orig_offset, size_t orig_len)
{
struct strparser *strp = (struct strparser *)desc->arg.data;
return __strp_recv(desc, orig_skb, orig_offset, orig_len,
strp->sk->sk_rcvbuf, strp->sk->sk_rcvtimeo);
}
static int default_read_sock_done(struct strparser *strp, int err)
{
return err;
}
static int strp_read_sock(struct strparser *strp)
{
struct socket *sock = strp->sk->sk_socket;
read_descriptor_t desc;
if (unlikely(!sock || !sock->ops || !sock->ops->read_sock))
return -EBUSY;
desc.arg.data = strp;
desc.error = 0;
desc.count = 1;
sock->ops->read_sock(strp->sk, &desc, strp_recv);
desc.error = strp->cb.read_sock_done(strp, desc.error);
return desc.error;
}
void strp_data_ready(struct strparser *strp)
{
if (unlikely(strp->stopped))
return;
if (sock_owned_by_user(strp->sk)) {
queue_work(strp_wq, &strp->work);
return;
}
if (strp->paused)
return;
if (strp->need_bytes) {
if (strp_peek_len(strp) >= strp->need_bytes)
strp->need_bytes = 0;
else
return;
}
if (strp_read_sock(strp) == -ENOMEM)
queue_work(strp_wq, &strp->work);
}
static void do_strp_work(struct strparser *strp)
{
read_descriptor_t rd_desc;
strp->cb.lock(strp);
if (unlikely(strp->stopped))
goto out;
if (strp->paused)
goto out;
rd_desc.arg.data = strp;
if (strp_read_sock(strp) == -ENOMEM)
queue_work(strp_wq, &strp->work);
out:
strp->cb.unlock(strp);
}
static void strp_work(struct work_struct *w)
{
do_strp_work(container_of(w, struct strparser, work));
}
static void strp_msg_timeout(struct work_struct *w)
{
struct strparser *strp = container_of(w, struct strparser,
msg_timer_work.work);
STRP_STATS_INCR(strp->stats.msg_timeouts);
strp->cb.lock(strp);
strp->cb.abort_parser(strp, ETIMEDOUT);
strp->cb.unlock(strp);
}
static void strp_sock_lock(struct strparser *strp)
{
lock_sock(strp->sk);
}
static void strp_sock_unlock(struct strparser *strp)
{
release_sock(strp->sk);
}
int strp_init(struct strparser *strp, struct sock *sk,
const struct strp_callbacks *cb)
{
if (!cb || !cb->rcv_msg || !cb->parse_msg)
return -EINVAL;
if (!sk) {
if (!cb->lock || !cb->unlock)
return -EINVAL;
}
memset(strp, 0, sizeof(*strp));
strp->sk = sk;
strp->cb.lock = cb->lock ? : strp_sock_lock;
strp->cb.unlock = cb->unlock ? : strp_sock_unlock;
strp->cb.rcv_msg = cb->rcv_msg;
strp->cb.parse_msg = cb->parse_msg;
strp->cb.read_sock_done = cb->read_sock_done ? : default_read_sock_done;
strp->cb.abort_parser = cb->abort_parser ? : strp_abort_strp;
INIT_DELAYED_WORK(&strp->msg_timer_work, strp_msg_timeout);
INIT_WORK(&strp->work, strp_work);
return 0;
}
void strp_unpause(struct strparser *strp)
{
strp->paused = 0;
smp_mb();
queue_work(strp_wq, &strp->work);
}
void strp_done(struct strparser *strp)
{
WARN_ON(!strp->stopped);
cancel_delayed_work_sync(&strp->msg_timer_work);
cancel_work_sync(&strp->work);
if (strp->skb_head) {
kfree_skb(strp->skb_head);
strp->skb_head = NULL;
}
}
void strp_stop(struct strparser *strp)
{
strp->stopped = 1;
}
void strp_check_rcv(struct strparser *strp)
{
queue_work(strp_wq, &strp->work);
}
static int __init strp_mod_init(void)
{
strp_wq = create_singlethread_workqueue("kstrp");
return 0;
}
static void __exit strp_mod_exit(void)
{
destroy_workqueue(strp_wq);
}
