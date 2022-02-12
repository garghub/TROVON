void sctp_inq_init(struct sctp_inq *queue)
{
INIT_LIST_HEAD(&queue->in_chunk_list);
queue->in_progress = NULL;
INIT_WORK(&queue->immediate, NULL);
}
void sctp_inq_free(struct sctp_inq *queue)
{
struct sctp_chunk *chunk, *tmp;
list_for_each_entry_safe(chunk, tmp, &queue->in_chunk_list, list) {
list_del_init(&chunk->list);
sctp_chunk_free(chunk);
}
if (queue->in_progress) {
sctp_chunk_free(queue->in_progress);
queue->in_progress = NULL;
}
}
void sctp_inq_push(struct sctp_inq *q, struct sctp_chunk *chunk)
{
if (chunk->rcvr->dead) {
sctp_chunk_free(chunk);
return;
}
list_add_tail(&chunk->list, &q->in_chunk_list);
if (chunk->asoc)
chunk->asoc->stats.ipackets++;
q->immediate.func(&q->immediate);
}
struct sctp_chunkhdr *sctp_inq_peek(struct sctp_inq *queue)
{
struct sctp_chunk *chunk;
sctp_chunkhdr_t *ch = NULL;
chunk = queue->in_progress;
if (chunk->singleton ||
chunk->end_of_packet ||
chunk->pdiscard)
return NULL;
ch = (sctp_chunkhdr_t *)chunk->chunk_end;
return ch;
}
struct sctp_chunk *sctp_inq_pop(struct sctp_inq *queue)
{
struct sctp_chunk *chunk;
sctp_chunkhdr_t *ch = NULL;
chunk = queue->in_progress;
if (chunk) {
if (chunk->singleton ||
chunk->end_of_packet ||
chunk->pdiscard) {
if (chunk->head_skb == chunk->skb) {
chunk->skb = skb_shinfo(chunk->skb)->frag_list;
goto new_skb;
}
if (chunk->skb->next) {
chunk->skb = chunk->skb->next;
goto new_skb;
}
if (chunk->head_skb)
chunk->skb = chunk->head_skb;
sctp_chunk_free(chunk);
chunk = queue->in_progress = NULL;
} else {
ch = (sctp_chunkhdr_t *) chunk->chunk_end;
skb_pull(chunk->skb, chunk->chunk_end - chunk->skb->data);
}
}
if (!chunk) {
struct list_head *entry;
next_chunk:
entry = sctp_list_dequeue(&queue->in_chunk_list);
if (!entry)
return NULL;
chunk = list_entry(entry, struct sctp_chunk, list);
if ((skb_shinfo(chunk->skb)->gso_type & SKB_GSO_SCTP) == SKB_GSO_SCTP) {
if (skb_shinfo(chunk->skb)->frag_list)
chunk->head_skb = chunk->skb;
if (chunk->head_skb && chunk->skb->data_len == chunk->skb->len)
chunk->skb = skb_shinfo(chunk->skb)->frag_list;
if (WARN_ON(!chunk->skb)) {
__SCTP_INC_STATS(dev_net(chunk->skb->dev), SCTP_MIB_IN_PKT_DISCARDS);
sctp_chunk_free(chunk);
goto next_chunk;
}
}
if (chunk->asoc)
sock_rps_save_rxhash(chunk->asoc->base.sk, chunk->skb);
queue->in_progress = chunk;
new_skb:
ch = (sctp_chunkhdr_t *) chunk->skb->data;
chunk->singleton = 1;
chunk->data_accepted = 0;
chunk->pdiscard = 0;
chunk->auth = 0;
chunk->has_asconf = 0;
chunk->end_of_packet = 0;
if (chunk->head_skb) {
struct sctp_input_cb
*cb = SCTP_INPUT_CB(chunk->skb),
*head_cb = SCTP_INPUT_CB(chunk->head_skb);
cb->chunk = head_cb->chunk;
cb->af = head_cb->af;
}
}
chunk->chunk_hdr = ch;
chunk->chunk_end = ((__u8 *)ch) + SCTP_PAD4(ntohs(ch->length));
skb_pull(chunk->skb, sizeof(sctp_chunkhdr_t));
chunk->subh.v = NULL;
if (chunk->chunk_end + sizeof(sctp_chunkhdr_t) <
skb_tail_pointer(chunk->skb)) {
chunk->singleton = 0;
} else if (chunk->chunk_end > skb_tail_pointer(chunk->skb)) {
chunk->pdiscard = 1;
chunk->chunk_end = skb_tail_pointer(chunk->skb);
} else {
chunk->end_of_packet = 1;
}
pr_debug("+++sctp_inq_pop+++ chunk:%p[%s], length:%d, skb->len:%d\n",
chunk, sctp_cname(SCTP_ST_CHUNK(chunk->chunk_hdr->type)),
ntohs(chunk->chunk_hdr->length), chunk->skb->len);
return chunk;
}
void sctp_inq_set_th_handler(struct sctp_inq *q, work_func_t callback)
{
INIT_WORK(&q->immediate, callback);
}
