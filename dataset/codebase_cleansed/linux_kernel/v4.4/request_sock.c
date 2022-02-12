void reqsk_queue_alloc(struct request_sock_queue *queue)
{
spin_lock_init(&queue->rskq_lock);
spin_lock_init(&queue->fastopenq.lock);
queue->fastopenq.rskq_rst_head = NULL;
queue->fastopenq.rskq_rst_tail = NULL;
queue->fastopenq.qlen = 0;
queue->rskq_accept_head = NULL;
}
void reqsk_fastopen_remove(struct sock *sk, struct request_sock *req,
bool reset)
{
struct sock *lsk = req->rsk_listener;
struct fastopen_queue *fastopenq;
fastopenq = &inet_csk(lsk)->icsk_accept_queue.fastopenq;
tcp_sk(sk)->fastopen_rsk = NULL;
spin_lock_bh(&fastopenq->lock);
fastopenq->qlen--;
tcp_rsk(req)->tfo_listener = false;
if (req->sk)
goto out;
if (!reset || lsk->sk_state != TCP_LISTEN) {
spin_unlock_bh(&fastopenq->lock);
reqsk_put(req);
return;
}
req->rsk_timer.expires = jiffies + 60*HZ;
if (fastopenq->rskq_rst_head == NULL)
fastopenq->rskq_rst_head = req;
else
fastopenq->rskq_rst_tail->dl_next = req;
req->dl_next = NULL;
fastopenq->rskq_rst_tail = req;
fastopenq->qlen++;
out:
spin_unlock_bh(&fastopenq->lock);
}
