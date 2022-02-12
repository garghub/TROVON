static void sctp_datamsg_init(struct sctp_datamsg *msg)
{
atomic_set(&msg->refcnt, 1);
msg->send_failed = 0;
msg->send_error = 0;
msg->can_abandon = 0;
msg->can_delay = 1;
msg->expires_at = 0;
INIT_LIST_HEAD(&msg->chunks);
}
static struct sctp_datamsg *sctp_datamsg_new(gfp_t gfp)
{
struct sctp_datamsg *msg;
msg = kmalloc(sizeof(struct sctp_datamsg), gfp);
if (msg) {
sctp_datamsg_init(msg);
SCTP_DBG_OBJCNT_INC(datamsg);
}
return msg;
}
static void sctp_datamsg_destroy(struct sctp_datamsg *msg)
{
struct list_head *pos, *temp;
struct sctp_chunk *chunk;
struct sctp_sock *sp;
struct sctp_ulpevent *ev;
struct sctp_association *asoc = NULL;
int error = 0, notify;
notify = msg->send_failed ? -1 : 0;
list_for_each_safe(pos, temp, &msg->chunks) {
list_del_init(pos);
chunk = list_entry(pos, struct sctp_chunk, frag_list);
if (notify < 0) {
asoc = chunk->asoc;
if (msg->send_error)
error = msg->send_error;
else
error = asoc->outqueue.error;
sp = sctp_sk(asoc->base.sk);
notify = sctp_ulpevent_type_enabled(SCTP_SEND_FAILED,
&sp->subscribe);
}
if (notify > 0) {
int sent;
if (chunk->has_tsn)
sent = SCTP_DATA_SENT;
else
sent = SCTP_DATA_UNSENT;
ev = sctp_ulpevent_make_send_failed(asoc, chunk, sent,
error, GFP_ATOMIC);
if (ev)
sctp_ulpq_tail_event(&asoc->ulpq, ev);
}
sctp_chunk_put(chunk);
}
SCTP_DBG_OBJCNT_DEC(datamsg);
kfree(msg);
}
static void sctp_datamsg_hold(struct sctp_datamsg *msg)
{
atomic_inc(&msg->refcnt);
}
void sctp_datamsg_put(struct sctp_datamsg *msg)
{
if (atomic_dec_and_test(&msg->refcnt))
sctp_datamsg_destroy(msg);
}
static void sctp_datamsg_assign(struct sctp_datamsg *msg, struct sctp_chunk *chunk)
{
sctp_datamsg_hold(msg);
chunk->msg = msg;
}
struct sctp_datamsg *sctp_datamsg_from_user(struct sctp_association *asoc,
struct sctp_sndrcvinfo *sinfo,
struct iov_iter *from)
{
int max, whole, i, offset, over, err;
int len, first_len;
int max_data;
struct sctp_chunk *chunk;
struct sctp_datamsg *msg;
struct list_head *pos, *temp;
size_t msg_len = iov_iter_count(from);
__u8 frag;
msg = sctp_datamsg_new(GFP_KERNEL);
if (!msg)
return ERR_PTR(-ENOMEM);
if (sinfo->sinfo_timetolive) {
msg->expires_at = jiffies +
msecs_to_jiffies(sinfo->sinfo_timetolive);
msg->can_abandon = 1;
pr_debug("%s: msg:%p expires_at:%ld jiffies:%ld\n", __func__,
msg, msg->expires_at, jiffies);
}
max_data = (asoc->pathmtu -
sctp_sk(asoc->base.sk)->pf->af->net_header_len -
sizeof(struct sctphdr) - sizeof(struct sctp_data_chunk)) & ~3;
max = asoc->frag_point;
if (sctp_auth_send_cid(SCTP_CID_DATA, asoc)) {
struct sctp_hmac *hmac_desc = sctp_auth_asoc_get_hmac(asoc);
if (hmac_desc)
max_data -= WORD_ROUND(sizeof(sctp_auth_chunk_t) +
hmac_desc->hmac_len);
}
if (max > max_data)
max = max_data;
whole = 0;
first_len = max;
if (timer_pending(&asoc->timers[SCTP_EVENT_TIMEOUT_SACK]) &&
asoc->outqueue.out_qlen == 0 &&
list_empty(&asoc->outqueue.retransmit) &&
msg_len > max)
max_data -= WORD_ROUND(sizeof(sctp_sack_chunk_t));
if (asoc->state < SCTP_STATE_COOKIE_ECHOED)
max_data -= SCTP_ARBITRARY_COOKIE_ECHO_LEN;
if (first_len > max_data)
first_len = max_data;
if (msg_len >= first_len) {
msg_len -= first_len;
whole = 1;
msg->can_delay = 0;
}
whole += msg_len / max;
over = msg_len % max;
offset = 0;
if ((whole > 1) || (whole && over))
SCTP_INC_STATS(sock_net(asoc->base.sk), SCTP_MIB_FRAGUSRMSGS);
for (i = 0, len = first_len; i < whole; i++) {
frag = SCTP_DATA_MIDDLE_FRAG;
if (0 == i)
frag |= SCTP_DATA_FIRST_FRAG;
if ((i == (whole - 1)) && !over) {
frag |= SCTP_DATA_LAST_FRAG;
if ((sinfo->sinfo_flags & SCTP_EOF) ||
(sinfo->sinfo_flags & SCTP_SACK_IMMEDIATELY))
frag |= SCTP_DATA_SACK_IMM;
}
chunk = sctp_make_datafrag_empty(asoc, sinfo, len, frag,
0, GFP_KERNEL);
if (!chunk) {
err = -ENOMEM;
goto errout;
}
err = sctp_user_addto_chunk(chunk, len, from);
if (err < 0)
goto errout_chunk_free;
__skb_pull(chunk->skb, (__u8 *)chunk->chunk_hdr
- (__u8 *)chunk->skb->data);
sctp_datamsg_assign(msg, chunk);
list_add_tail(&chunk->frag_list, &msg->chunks);
if (0 == i)
len = max;
}
if (over) {
if (!whole)
frag = SCTP_DATA_NOT_FRAG;
else
frag = SCTP_DATA_LAST_FRAG;
if ((sinfo->sinfo_flags & SCTP_EOF) ||
(sinfo->sinfo_flags & SCTP_SACK_IMMEDIATELY))
frag |= SCTP_DATA_SACK_IMM;
chunk = sctp_make_datafrag_empty(asoc, sinfo, over, frag,
0, GFP_KERNEL);
if (!chunk) {
err = -ENOMEM;
goto errout;
}
err = sctp_user_addto_chunk(chunk, over, from);
__skb_pull(chunk->skb, (__u8 *)chunk->chunk_hdr
- (__u8 *)chunk->skb->data);
if (err < 0)
goto errout_chunk_free;
sctp_datamsg_assign(msg, chunk);
list_add_tail(&chunk->frag_list, &msg->chunks);
}
return msg;
errout_chunk_free:
sctp_chunk_free(chunk);
errout:
list_for_each_safe(pos, temp, &msg->chunks) {
list_del_init(pos);
chunk = list_entry(pos, struct sctp_chunk, frag_list);
sctp_chunk_free(chunk);
}
sctp_datamsg_put(msg);
return ERR_PTR(err);
}
int sctp_chunk_abandoned(struct sctp_chunk *chunk)
{
struct sctp_datamsg *msg = chunk->msg;
if (!msg->can_abandon)
return 0;
if (time_after(jiffies, msg->expires_at))
return 1;
return 0;
}
void sctp_chunk_fail(struct sctp_chunk *chunk, int error)
{
chunk->msg->send_failed = 1;
chunk->msg->send_error = error;
}
