int reqsk_queue_alloc(struct request_sock_queue *queue,
unsigned int nr_table_entries)
{
size_t lopt_size = sizeof(struct listen_sock);
struct listen_sock *lopt = NULL;
nr_table_entries = min_t(u32, nr_table_entries, sysctl_max_syn_backlog);
nr_table_entries = max_t(u32, nr_table_entries, 8);
nr_table_entries = roundup_pow_of_two(nr_table_entries + 1);
lopt_size += nr_table_entries * sizeof(struct request_sock *);
if (lopt_size <= (PAGE_SIZE << PAGE_ALLOC_COSTLY_ORDER))
lopt = kzalloc(lopt_size, GFP_KERNEL |
__GFP_NOWARN |
__GFP_NORETRY);
if (!lopt)
lopt = vzalloc(lopt_size);
if (!lopt)
return -ENOMEM;
get_random_bytes(&lopt->hash_rnd, sizeof(lopt->hash_rnd));
rwlock_init(&queue->syn_wait_lock);
queue->rskq_accept_head = NULL;
lopt->nr_table_entries = nr_table_entries;
lopt->max_qlen_log = ilog2(nr_table_entries);
write_lock_bh(&queue->syn_wait_lock);
queue->listen_opt = lopt;
write_unlock_bh(&queue->syn_wait_lock);
return 0;
}
void __reqsk_queue_destroy(struct request_sock_queue *queue)
{
kvfree(queue->listen_opt);
}
static inline struct listen_sock *reqsk_queue_yank_listen_sk(
struct request_sock_queue *queue)
{
struct listen_sock *lopt;
write_lock_bh(&queue->syn_wait_lock);
lopt = queue->listen_opt;
queue->listen_opt = NULL;
write_unlock_bh(&queue->syn_wait_lock);
return lopt;
}
void reqsk_queue_destroy(struct request_sock_queue *queue)
{
struct listen_sock *lopt = reqsk_queue_yank_listen_sk(queue);
if (lopt->qlen != 0) {
unsigned int i;
for (i = 0; i < lopt->nr_table_entries; i++) {
struct request_sock *req;
while ((req = lopt->syn_table[i]) != NULL) {
lopt->syn_table[i] = req->dl_next;
lopt->qlen--;
reqsk_free(req);
}
}
}
WARN_ON(lopt->qlen != 0);
kvfree(lopt);
}
void reqsk_fastopen_remove(struct sock *sk, struct request_sock *req,
bool reset)
{
struct sock *lsk = tcp_rsk(req)->listener;
struct fastopen_queue *fastopenq =
inet_csk(lsk)->icsk_accept_queue.fastopenq;
tcp_sk(sk)->fastopen_rsk = NULL;
spin_lock_bh(&fastopenq->lock);
fastopenq->qlen--;
tcp_rsk(req)->listener = NULL;
if (req->sk)
goto out;
if (!reset || lsk->sk_state != TCP_LISTEN) {
spin_unlock_bh(&fastopenq->lock);
sock_put(lsk);
reqsk_free(req);
return;
}
req->expires = jiffies + 60*HZ;
if (fastopenq->rskq_rst_head == NULL)
fastopenq->rskq_rst_head = req;
else
fastopenq->rskq_rst_tail->dl_next = req;
req->dl_next = NULL;
fastopenq->rskq_rst_tail = req;
fastopenq->qlen++;
out:
spin_unlock_bh(&fastopenq->lock);
sock_put(lsk);
}
