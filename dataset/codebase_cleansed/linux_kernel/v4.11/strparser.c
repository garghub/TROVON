static inline struct _strp_rx_msg *_strp_rx_msg(struct sk_buff *skb)
{
return (struct _strp_rx_msg *)((void *)skb->cb +
offsetof(struct qdisc_skb_cb, data));
}
static void strp_abort_rx_strp(struct strparser *strp, int err)
{
struct sock *csk = strp->sk;
del_timer(&strp->rx_msg_timer);
if (strp->rx_stopped)
return;
strp->rx_stopped = 1;
csk->sk_err = err;
csk->sk_error_report(csk);
}
static void strp_start_rx_timer(struct strparser *strp)
{
if (strp->sk->sk_rcvtimeo)
mod_timer(&strp->rx_msg_timer, strp->sk->sk_rcvtimeo);
}
static void strp_parser_err(struct strparser *strp, int err,
read_descriptor_t *desc)
{
desc->error = err;
kfree_skb(strp->rx_skb_head);
strp->rx_skb_head = NULL;
strp->cb.abort_parser(strp, err);
}
static inline int strp_peek_len(struct strparser *strp)
{
struct socket *sock = strp->sk->sk_socket;
return sock->ops->peek_len(sock);
}
static int strp_recv(read_descriptor_t *desc, struct sk_buff *orig_skb,
unsigned int orig_offset, size_t orig_len)
{
struct strparser *strp = (struct strparser *)desc->arg.data;
struct _strp_rx_msg *rxm;
struct sk_buff *head, *skb;
size_t eaten = 0, cand_len;
ssize_t extra;
int err;
bool cloned_orig = false;
if (strp->rx_paused)
return 0;
head = strp->rx_skb_head;
if (head) {
rxm = _strp_rx_msg(head);
if (unlikely(rxm->early_eaten)) {
eaten = orig_len <= rxm->early_eaten ?
orig_len : rxm->early_eaten;
rxm->early_eaten -= eaten;
return eaten;
}
if (unlikely(orig_offset)) {
orig_skb = skb_clone(orig_skb, GFP_ATOMIC);
if (!orig_skb) {
STRP_STATS_INCR(strp->stats.rx_mem_fail);
desc->error = -ENOMEM;
return 0;
}
if (!pskb_pull(orig_skb, orig_offset)) {
STRP_STATS_INCR(strp->stats.rx_mem_fail);
kfree_skb(orig_skb);
desc->error = -ENOMEM;
return 0;
}
cloned_orig = true;
orig_offset = 0;
}
if (!strp->rx_skb_nextp) {
err = skb_unclone(head, GFP_ATOMIC);
if (err) {
STRP_STATS_INCR(strp->stats.rx_mem_fail);
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
STRP_STATS_INCR(strp->stats.rx_mem_fail);
desc->error = -ENOMEM;
return 0;
}
skb->len = head->len;
skb->data_len = head->len;
skb->truesize = head->truesize;
*_strp_rx_msg(skb) = *_strp_rx_msg(head);
strp->rx_skb_nextp = &head->next;
skb_shinfo(skb)->frag_list = head;
strp->rx_skb_head = skb;
head = skb;
} else {
strp->rx_skb_nextp =
&skb_shinfo(head)->frag_list;
}
}
}
while (eaten < orig_len) {
skb = skb_clone(orig_skb, GFP_ATOMIC);
if (!skb) {
STRP_STATS_INCR(strp->stats.rx_mem_fail);
desc->error = -ENOMEM;
break;
}
cand_len = orig_len - eaten;
head = strp->rx_skb_head;
if (!head) {
head = skb;
strp->rx_skb_head = head;
strp->rx_skb_nextp = NULL;
rxm = _strp_rx_msg(head);
memset(rxm, 0, sizeof(*rxm));
rxm->strp.offset = orig_offset + eaten;
} else {
err = skb_unclone(skb, GFP_ATOMIC);
if (err) {
STRP_STATS_INCR(strp->stats.rx_mem_fail);
desc->error = err;
break;
}
rxm = _strp_rx_msg(head);
*strp->rx_skb_nextp = skb;
strp->rx_skb_nextp = &skb->next;
head->data_len += skb->len;
head->len += skb->len;
head->truesize += skb->truesize;
}
if (!rxm->strp.full_len) {
ssize_t len;
len = (*strp->cb.parse_msg)(strp, head);
if (!len) {
if (!rxm->accum_len) {
strp_start_rx_timer(strp);
}
rxm->accum_len += cand_len;
eaten += cand_len;
STRP_STATS_INCR(strp->stats.rx_need_more_hdr);
WARN_ON(eaten != orig_len);
break;
} else if (len < 0) {
if (len == -ESTRPIPE && rxm->accum_len) {
len = -ENODATA;
strp->rx_unrecov_intr = 1;
} else {
strp->rx_interrupted = 1;
}
strp_parser_err(strp, len, desc);
break;
} else if (len > strp->sk->sk_rcvbuf) {
STRP_STATS_INCR(strp->stats.rx_msg_too_big);
strp_parser_err(strp, -EMSGSIZE, desc);
break;
} else if (len <= (ssize_t)head->len -
skb->len - rxm->strp.offset) {
STRP_STATS_INCR(strp->stats.rx_bad_hdr_len);
strp_parser_err(strp, -EPROTO, desc);
break;
}
rxm->strp.full_len = len;
}
extra = (ssize_t)(rxm->accum_len + cand_len) -
rxm->strp.full_len;
if (extra < 0) {
if (rxm->strp.full_len - rxm->accum_len >
strp_peek_len(strp)) {
if (!rxm->accum_len) {
strp_start_rx_timer(strp);
}
strp->rx_need_bytes = rxm->strp.full_len -
rxm->accum_len;
rxm->accum_len += cand_len;
rxm->early_eaten = cand_len;
STRP_STATS_ADD(strp->stats.rx_bytes, cand_len);
desc->count = 0;
break;
}
rxm->accum_len += cand_len;
eaten += cand_len;
WARN_ON(eaten != orig_len);
break;
}
WARN_ON(extra > cand_len);
eaten += (cand_len - extra);
del_timer(&strp->rx_msg_timer);
strp->rx_skb_head = NULL;
STRP_STATS_INCR(strp->stats.rx_msgs);
strp->cb.rcv_msg(strp, head);
if (unlikely(strp->rx_paused)) {
break;
}
}
if (cloned_orig)
kfree_skb(orig_skb);
STRP_STATS_ADD(strp->stats.rx_bytes, eaten);
return eaten;
}
static int default_read_sock_done(struct strparser *strp, int err)
{
return err;
}
static int strp_read_sock(struct strparser *strp)
{
struct socket *sock = strp->sk->sk_socket;
read_descriptor_t desc;
desc.arg.data = strp;
desc.error = 0;
desc.count = 1;
sock->ops->read_sock(strp->sk, &desc, strp_recv);
desc.error = strp->cb.read_sock_done(strp, desc.error);
return desc.error;
}
void strp_data_ready(struct strparser *strp)
{
if (unlikely(strp->rx_stopped))
return;
if (sock_owned_by_user(strp->sk)) {
queue_work(strp_wq, &strp->rx_work);
return;
}
if (strp->rx_paused)
return;
if (strp->rx_need_bytes) {
if (strp_peek_len(strp) >= strp->rx_need_bytes)
strp->rx_need_bytes = 0;
else
return;
}
if (strp_read_sock(strp) == -ENOMEM)
queue_work(strp_wq, &strp->rx_work);
}
static void do_strp_rx_work(struct strparser *strp)
{
read_descriptor_t rd_desc;
struct sock *csk = strp->sk;
lock_sock(csk);
if (unlikely(strp->rx_stopped))
goto out;
if (strp->rx_paused)
goto out;
rd_desc.arg.data = strp;
if (strp_read_sock(strp) == -ENOMEM)
queue_work(strp_wq, &strp->rx_work);
out:
release_sock(csk);
}
static void strp_rx_work(struct work_struct *w)
{
do_strp_rx_work(container_of(w, struct strparser, rx_work));
}
static void strp_rx_msg_timeout(unsigned long arg)
{
struct strparser *strp = (struct strparser *)arg;
STRP_STATS_INCR(strp->stats.rx_msg_timeouts);
lock_sock(strp->sk);
strp->cb.abort_parser(strp, ETIMEDOUT);
release_sock(strp->sk);
}
int strp_init(struct strparser *strp, struct sock *csk,
struct strp_callbacks *cb)
{
struct socket *sock = csk->sk_socket;
if (!cb || !cb->rcv_msg || !cb->parse_msg)
return -EINVAL;
if (!sock->ops->read_sock || !sock->ops->peek_len)
return -EAFNOSUPPORT;
memset(strp, 0, sizeof(*strp));
strp->sk = csk;
setup_timer(&strp->rx_msg_timer, strp_rx_msg_timeout,
(unsigned long)strp);
INIT_WORK(&strp->rx_work, strp_rx_work);
strp->cb.rcv_msg = cb->rcv_msg;
strp->cb.parse_msg = cb->parse_msg;
strp->cb.read_sock_done = cb->read_sock_done ? : default_read_sock_done;
strp->cb.abort_parser = cb->abort_parser ? : strp_abort_rx_strp;
return 0;
}
void strp_unpause(struct strparser *strp)
{
strp->rx_paused = 0;
smp_mb();
queue_work(strp_wq, &strp->rx_work);
}
void strp_done(struct strparser *strp)
{
WARN_ON(!strp->rx_stopped);
del_timer_sync(&strp->rx_msg_timer);
cancel_work_sync(&strp->rx_work);
if (strp->rx_skb_head) {
kfree_skb(strp->rx_skb_head);
strp->rx_skb_head = NULL;
}
}
void strp_stop(struct strparser *strp)
{
strp->rx_stopped = 1;
}
void strp_check_rcv(struct strparser *strp)
{
queue_work(strp_wq, &strp->rx_work);
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
