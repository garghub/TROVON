struct sctp_ulpq *sctp_ulpq_init(struct sctp_ulpq *ulpq,
struct sctp_association *asoc)
{
memset(ulpq, 0, sizeof(struct sctp_ulpq));
ulpq->asoc = asoc;
skb_queue_head_init(&ulpq->reasm);
skb_queue_head_init(&ulpq->lobby);
ulpq->pd_mode = 0;
return ulpq;
}
void sctp_ulpq_flush(struct sctp_ulpq *ulpq)
{
struct sk_buff *skb;
struct sctp_ulpevent *event;
while ((skb = __skb_dequeue(&ulpq->lobby)) != NULL) {
event = sctp_skb2event(skb);
sctp_ulpevent_free(event);
}
while ((skb = __skb_dequeue(&ulpq->reasm)) != NULL) {
event = sctp_skb2event(skb);
sctp_ulpevent_free(event);
}
}
void sctp_ulpq_free(struct sctp_ulpq *ulpq)
{
sctp_ulpq_flush(ulpq);
}
int sctp_ulpq_tail_data(struct sctp_ulpq *ulpq, struct sctp_chunk *chunk,
gfp_t gfp)
{
struct sk_buff_head temp;
struct sctp_ulpevent *event;
int event_eor = 0;
event = sctp_ulpevent_make_rcvmsg(chunk->asoc, chunk, gfp);
if (!event)
return -ENOMEM;
event = sctp_ulpq_reasm(ulpq, event);
if ((event) && (event->msg_flags & MSG_EOR)) {
skb_queue_head_init(&temp);
__skb_queue_tail(&temp, sctp_event2skb(event));
event = sctp_ulpq_order(ulpq, event);
}
if (event) {
event_eor = (event->msg_flags & MSG_EOR) ? 1 : 0;
sctp_ulpq_tail_event(ulpq, event);
}
return event_eor;
}
int sctp_clear_pd(struct sock *sk, struct sctp_association *asoc)
{
struct sctp_sock *sp = sctp_sk(sk);
if (atomic_dec_and_test(&sp->pd_mode)) {
if (!skb_queue_empty(&sp->pd_lobby)) {
skb_queue_splice_tail_init(&sp->pd_lobby,
&sk->sk_receive_queue);
return 1;
}
} else {
if (!skb_queue_empty(&sp->pd_lobby) && asoc) {
struct sk_buff *skb, *tmp;
struct sctp_ulpevent *event;
sctp_skb_for_each(skb, &sp->pd_lobby, tmp) {
event = sctp_skb2event(skb);
if (event->asoc == asoc) {
__skb_unlink(skb, &sp->pd_lobby);
__skb_queue_tail(&sk->sk_receive_queue,
skb);
}
}
}
}
return 0;
}
static void sctp_ulpq_set_pd(struct sctp_ulpq *ulpq)
{
struct sctp_sock *sp = sctp_sk(ulpq->asoc->base.sk);
atomic_inc(&sp->pd_mode);
ulpq->pd_mode = 1;
}
static int sctp_ulpq_clear_pd(struct sctp_ulpq *ulpq)
{
ulpq->pd_mode = 0;
sctp_ulpq_reasm_drain(ulpq);
return sctp_clear_pd(ulpq->asoc->base.sk, ulpq->asoc);
}
int sctp_ulpq_tail_event(struct sctp_ulpq *ulpq, struct sctp_ulpevent *event)
{
struct sock *sk = ulpq->asoc->base.sk;
struct sctp_sock *sp = sctp_sk(sk);
struct sk_buff_head *queue, *skb_list;
struct sk_buff *skb = sctp_event2skb(event);
int clear_pd = 0;
skb_list = (struct sk_buff_head *) skb->prev;
if (sk->sk_shutdown & RCV_SHUTDOWN &&
(sk->sk_shutdown & SEND_SHUTDOWN ||
!sctp_ulpevent_is_notification(event)))
goto out_free;
if (!sctp_ulpevent_is_notification(event)) {
sk_mark_napi_id(sk, skb);
sk_incoming_cpu_update(sk);
}
if (!sctp_ulpevent_is_enabled(event, &sp->subscribe))
goto out_free;
if (atomic_read(&sp->pd_mode) == 0) {
queue = &sk->sk_receive_queue;
} else {
if (ulpq->pd_mode) {
if ((event->msg_flags & MSG_NOTIFICATION) ||
(SCTP_DATA_NOT_FRAG ==
(event->msg_flags & SCTP_DATA_FRAG_MASK)))
queue = &sp->pd_lobby;
else {
clear_pd = event->msg_flags & MSG_EOR;
queue = &sk->sk_receive_queue;
}
} else {
if (sp->frag_interleave)
queue = &sk->sk_receive_queue;
else
queue = &sp->pd_lobby;
}
}
if (skb_list)
skb_queue_splice_tail_init(skb_list, queue);
else
__skb_queue_tail(queue, skb);
if (clear_pd)
sctp_ulpq_clear_pd(ulpq);
if (queue == &sk->sk_receive_queue && !sp->data_ready_signalled) {
if (!sock_owned_by_user(sk))
sp->data_ready_signalled = 1;
sk->sk_data_ready(sk);
}
return 1;
out_free:
if (skb_list)
sctp_queue_purge_ulpevents(skb_list);
else
sctp_ulpevent_free(event);
return 0;
}
static void sctp_ulpq_store_reasm(struct sctp_ulpq *ulpq,
struct sctp_ulpevent *event)
{
struct sk_buff *pos;
struct sctp_ulpevent *cevent;
__u32 tsn, ctsn;
tsn = event->tsn;
pos = skb_peek_tail(&ulpq->reasm);
if (!pos) {
__skb_queue_tail(&ulpq->reasm, sctp_event2skb(event));
return;
}
cevent = sctp_skb2event(pos);
ctsn = cevent->tsn;
if (TSN_lt(ctsn, tsn)) {
__skb_queue_tail(&ulpq->reasm, sctp_event2skb(event));
return;
}
skb_queue_walk(&ulpq->reasm, pos) {
cevent = sctp_skb2event(pos);
ctsn = cevent->tsn;
if (TSN_lt(tsn, ctsn))
break;
}
__skb_queue_before(&ulpq->reasm, pos, sctp_event2skb(event));
}
static struct sctp_ulpevent *sctp_make_reassembled_event(struct net *net,
struct sk_buff_head *queue, struct sk_buff *f_frag,
struct sk_buff *l_frag)
{
struct sk_buff *pos;
struct sk_buff *new = NULL;
struct sctp_ulpevent *event;
struct sk_buff *pnext, *last;
struct sk_buff *list = skb_shinfo(f_frag)->frag_list;
if (f_frag == l_frag)
pos = NULL;
else
pos = f_frag->next;
for (last = list; list; last = list, list = list->next)
;
if (last)
last->next = pos;
else {
if (skb_cloned(f_frag)) {
new = skb_copy(f_frag, GFP_ATOMIC);
if (!new)
return NULL;
sctp_skb_set_owner_r(new, f_frag->sk);
skb_shinfo(new)->frag_list = pos;
} else
skb_shinfo(f_frag)->frag_list = pos;
}
__skb_unlink(f_frag, queue);
if (new) {
kfree_skb(f_frag);
f_frag = new;
}
while (pos) {
pnext = pos->next;
f_frag->len += pos->len;
f_frag->data_len += pos->len;
__skb_unlink(pos, queue);
if (pos == l_frag)
break;
pos->next = pnext;
pos = pnext;
}
event = sctp_skb2event(f_frag);
SCTP_INC_STATS(net, SCTP_MIB_REASMUSRMSGS);
return event;
}
static struct sctp_ulpevent *sctp_ulpq_retrieve_reassembled(struct sctp_ulpq *ulpq)
{
struct sk_buff *pos;
struct sctp_ulpevent *cevent;
struct sk_buff *first_frag = NULL;
__u32 ctsn, next_tsn;
struct sctp_ulpevent *retval = NULL;
struct sk_buff *pd_first = NULL;
struct sk_buff *pd_last = NULL;
size_t pd_len = 0;
struct sctp_association *asoc;
u32 pd_point;
next_tsn = 0;
skb_queue_walk(&ulpq->reasm, pos) {
cevent = sctp_skb2event(pos);
ctsn = cevent->tsn;
switch (cevent->msg_flags & SCTP_DATA_FRAG_MASK) {
case SCTP_DATA_FIRST_FRAG:
if (pos == ulpq->reasm.next) {
pd_first = pos;
pd_last = pos;
pd_len = pos->len;
} else {
pd_first = NULL;
pd_last = NULL;
pd_len = 0;
}
first_frag = pos;
next_tsn = ctsn + 1;
break;
case SCTP_DATA_MIDDLE_FRAG:
if ((first_frag) && (ctsn == next_tsn)) {
next_tsn++;
if (pd_first) {
pd_last = pos;
pd_len += pos->len;
}
} else
first_frag = NULL;
break;
case SCTP_DATA_LAST_FRAG:
if (first_frag && (ctsn == next_tsn))
goto found;
else
first_frag = NULL;
break;
}
}
asoc = ulpq->asoc;
if (pd_first) {
if (!sctp_sk(asoc->base.sk)->frag_interleave &&
atomic_read(&sctp_sk(asoc->base.sk)->pd_mode))
goto done;
cevent = sctp_skb2event(pd_first);
pd_point = sctp_sk(asoc->base.sk)->pd_point;
if (pd_point && pd_point <= pd_len) {
retval = sctp_make_reassembled_event(sock_net(asoc->base.sk),
&ulpq->reasm,
pd_first,
pd_last);
if (retval)
sctp_ulpq_set_pd(ulpq);
}
}
done:
return retval;
found:
retval = sctp_make_reassembled_event(sock_net(ulpq->asoc->base.sk),
&ulpq->reasm, first_frag, pos);
if (retval)
retval->msg_flags |= MSG_EOR;
goto done;
}
static struct sctp_ulpevent *sctp_ulpq_retrieve_partial(struct sctp_ulpq *ulpq)
{
struct sk_buff *pos, *last_frag, *first_frag;
struct sctp_ulpevent *cevent;
__u32 ctsn, next_tsn;
int is_last;
struct sctp_ulpevent *retval;
if (skb_queue_empty(&ulpq->reasm))
return NULL;
last_frag = first_frag = NULL;
retval = NULL;
next_tsn = 0;
is_last = 0;
skb_queue_walk(&ulpq->reasm, pos) {
cevent = sctp_skb2event(pos);
ctsn = cevent->tsn;
switch (cevent->msg_flags & SCTP_DATA_FRAG_MASK) {
case SCTP_DATA_FIRST_FRAG:
if (!first_frag)
return NULL;
goto done;
case SCTP_DATA_MIDDLE_FRAG:
if (!first_frag) {
first_frag = pos;
next_tsn = ctsn + 1;
last_frag = pos;
} else if (next_tsn == ctsn) {
next_tsn++;
last_frag = pos;
} else
goto done;
break;
case SCTP_DATA_LAST_FRAG:
if (!first_frag)
first_frag = pos;
else if (ctsn != next_tsn)
goto done;
last_frag = pos;
is_last = 1;
goto done;
default:
return NULL;
}
}
done:
retval = sctp_make_reassembled_event(sock_net(ulpq->asoc->base.sk),
&ulpq->reasm, first_frag, last_frag);
if (retval && is_last)
retval->msg_flags |= MSG_EOR;
return retval;
}
static struct sctp_ulpevent *sctp_ulpq_reasm(struct sctp_ulpq *ulpq,
struct sctp_ulpevent *event)
{
struct sctp_ulpevent *retval = NULL;
if (SCTP_DATA_NOT_FRAG == (event->msg_flags & SCTP_DATA_FRAG_MASK)) {
event->msg_flags |= MSG_EOR;
return event;
}
sctp_ulpq_store_reasm(ulpq, event);
if (!ulpq->pd_mode)
retval = sctp_ulpq_retrieve_reassembled(ulpq);
else {
__u32 ctsn, ctsnap;
ctsn = event->tsn;
ctsnap = sctp_tsnmap_get_ctsn(&ulpq->asoc->peer.tsn_map);
if (TSN_lte(ctsn, ctsnap))
retval = sctp_ulpq_retrieve_partial(ulpq);
}
return retval;
}
static struct sctp_ulpevent *sctp_ulpq_retrieve_first(struct sctp_ulpq *ulpq)
{
struct sk_buff *pos, *last_frag, *first_frag;
struct sctp_ulpevent *cevent;
__u32 ctsn, next_tsn;
struct sctp_ulpevent *retval;
if (skb_queue_empty(&ulpq->reasm))
return NULL;
last_frag = first_frag = NULL;
retval = NULL;
next_tsn = 0;
skb_queue_walk(&ulpq->reasm, pos) {
cevent = sctp_skb2event(pos);
ctsn = cevent->tsn;
switch (cevent->msg_flags & SCTP_DATA_FRAG_MASK) {
case SCTP_DATA_FIRST_FRAG:
if (!first_frag) {
first_frag = pos;
next_tsn = ctsn + 1;
last_frag = pos;
} else
goto done;
break;
case SCTP_DATA_MIDDLE_FRAG:
if (!first_frag)
return NULL;
if (ctsn == next_tsn) {
next_tsn++;
last_frag = pos;
} else
goto done;
break;
case SCTP_DATA_LAST_FRAG:
if (!first_frag)
return NULL;
else
goto done;
break;
default:
return NULL;
}
}
done:
retval = sctp_make_reassembled_event(sock_net(ulpq->asoc->base.sk),
&ulpq->reasm, first_frag, last_frag);
return retval;
}
void sctp_ulpq_reasm_flushtsn(struct sctp_ulpq *ulpq, __u32 fwd_tsn)
{
struct sk_buff *pos, *tmp;
struct sctp_ulpevent *event;
__u32 tsn;
if (skb_queue_empty(&ulpq->reasm))
return;
skb_queue_walk_safe(&ulpq->reasm, pos, tmp) {
event = sctp_skb2event(pos);
tsn = event->tsn;
if (TSN_lte(tsn, fwd_tsn)) {
__skb_unlink(pos, &ulpq->reasm);
sctp_ulpevent_free(event);
} else
break;
}
}
static void sctp_ulpq_reasm_drain(struct sctp_ulpq *ulpq)
{
struct sctp_ulpevent *event = NULL;
struct sk_buff_head temp;
if (skb_queue_empty(&ulpq->reasm))
return;
while ((event = sctp_ulpq_retrieve_reassembled(ulpq)) != NULL) {
if ((event) && (event->msg_flags & MSG_EOR)) {
skb_queue_head_init(&temp);
__skb_queue_tail(&temp, sctp_event2skb(event));
event = sctp_ulpq_order(ulpq, event);
}
if (event)
sctp_ulpq_tail_event(ulpq, event);
}
}
static void sctp_ulpq_retrieve_ordered(struct sctp_ulpq *ulpq,
struct sctp_ulpevent *event)
{
struct sk_buff_head *event_list;
struct sk_buff *pos, *tmp;
struct sctp_ulpevent *cevent;
struct sctp_stream *stream;
__u16 sid, csid, cssn;
sid = event->stream;
stream = &ulpq->asoc->stream;
event_list = (struct sk_buff_head *) sctp_event2skb(event)->prev;
sctp_skb_for_each(pos, &ulpq->lobby, tmp) {
cevent = (struct sctp_ulpevent *) pos->cb;
csid = cevent->stream;
cssn = cevent->ssn;
if (csid > sid)
break;
if (csid < sid)
continue;
if (cssn != sctp_ssn_peek(stream, in, sid))
break;
sctp_ssn_next(stream, in, sid);
__skb_unlink(pos, &ulpq->lobby);
__skb_queue_tail(event_list, pos);
}
}
static void sctp_ulpq_store_ordered(struct sctp_ulpq *ulpq,
struct sctp_ulpevent *event)
{
struct sk_buff *pos;
struct sctp_ulpevent *cevent;
__u16 sid, csid;
__u16 ssn, cssn;
pos = skb_peek_tail(&ulpq->lobby);
if (!pos) {
__skb_queue_tail(&ulpq->lobby, sctp_event2skb(event));
return;
}
sid = event->stream;
ssn = event->ssn;
cevent = (struct sctp_ulpevent *) pos->cb;
csid = cevent->stream;
cssn = cevent->ssn;
if (sid > csid) {
__skb_queue_tail(&ulpq->lobby, sctp_event2skb(event));
return;
}
if ((sid == csid) && SSN_lt(cssn, ssn)) {
__skb_queue_tail(&ulpq->lobby, sctp_event2skb(event));
return;
}
skb_queue_walk(&ulpq->lobby, pos) {
cevent = (struct sctp_ulpevent *) pos->cb;
csid = cevent->stream;
cssn = cevent->ssn;
if (csid > sid)
break;
if (csid == sid && SSN_lt(ssn, cssn))
break;
}
__skb_queue_before(&ulpq->lobby, pos, sctp_event2skb(event));
}
static struct sctp_ulpevent *sctp_ulpq_order(struct sctp_ulpq *ulpq,
struct sctp_ulpevent *event)
{
__u16 sid, ssn;
struct sctp_stream *stream;
if (SCTP_DATA_UNORDERED & event->msg_flags)
return event;
sid = event->stream;
ssn = event->ssn;
stream = &ulpq->asoc->stream;
if (ssn != sctp_ssn_peek(stream, in, sid)) {
sctp_ulpq_store_ordered(ulpq, event);
return NULL;
}
sctp_ssn_next(stream, in, sid);
sctp_ulpq_retrieve_ordered(ulpq, event);
return event;
}
static void sctp_ulpq_reap_ordered(struct sctp_ulpq *ulpq, __u16 sid)
{
struct sk_buff *pos, *tmp;
struct sctp_ulpevent *cevent;
struct sctp_ulpevent *event;
struct sctp_stream *stream;
struct sk_buff_head temp;
struct sk_buff_head *lobby = &ulpq->lobby;
__u16 csid, cssn;
stream = &ulpq->asoc->stream;
skb_queue_head_init(&temp);
event = NULL;
sctp_skb_for_each(pos, lobby, tmp) {
cevent = (struct sctp_ulpevent *) pos->cb;
csid = cevent->stream;
cssn = cevent->ssn;
if (csid > sid)
break;
if (csid < sid)
continue;
if (!SSN_lt(cssn, sctp_ssn_peek(stream, in, csid)))
break;
__skb_unlink(pos, lobby);
if (!event)
event = sctp_skb2event(pos);
__skb_queue_tail(&temp, pos);
}
if (event == NULL && pos != (struct sk_buff *)lobby) {
cevent = (struct sctp_ulpevent *) pos->cb;
csid = cevent->stream;
cssn = cevent->ssn;
if (csid == sid && cssn == sctp_ssn_peek(stream, in, csid)) {
sctp_ssn_next(stream, in, csid);
__skb_unlink(pos, lobby);
__skb_queue_tail(&temp, pos);
event = sctp_skb2event(pos);
}
}
if (event) {
sctp_ulpq_retrieve_ordered(ulpq, event);
sctp_ulpq_tail_event(ulpq, event);
}
}
void sctp_ulpq_skip(struct sctp_ulpq *ulpq, __u16 sid, __u16 ssn)
{
struct sctp_stream *stream;
stream = &ulpq->asoc->stream;
if (SSN_lt(ssn, sctp_ssn_peek(stream, in, sid)))
return;
sctp_ssn_skip(stream, in, sid, ssn);
sctp_ulpq_reap_ordered(ulpq, sid);
}
static __u16 sctp_ulpq_renege_list(struct sctp_ulpq *ulpq,
struct sk_buff_head *list, __u16 needed)
{
__u16 freed = 0;
__u32 tsn, last_tsn;
struct sk_buff *skb, *flist, *last;
struct sctp_ulpevent *event;
struct sctp_tsnmap *tsnmap;
tsnmap = &ulpq->asoc->peer.tsn_map;
while ((skb = skb_peek_tail(list)) != NULL) {
event = sctp_skb2event(skb);
tsn = event->tsn;
if (TSN_lte(tsn, sctp_tsnmap_get_ctsn(tsnmap)))
break;
freed += skb_headlen(skb);
flist = skb_shinfo(skb)->frag_list;
for (last = flist; flist; flist = flist->next) {
last = flist;
freed += skb_headlen(last);
}
if (last)
last_tsn = sctp_skb2event(last)->tsn;
else
last_tsn = tsn;
__skb_unlink(skb, list);
sctp_ulpevent_free(event);
while (TSN_lte(tsn, last_tsn)) {
sctp_tsnmap_renege(tsnmap, tsn);
tsn++;
}
if (freed >= needed)
return freed;
}
return freed;
}
static __u16 sctp_ulpq_renege_order(struct sctp_ulpq *ulpq, __u16 needed)
{
return sctp_ulpq_renege_list(ulpq, &ulpq->lobby, needed);
}
static __u16 sctp_ulpq_renege_frags(struct sctp_ulpq *ulpq, __u16 needed)
{
return sctp_ulpq_renege_list(ulpq, &ulpq->reasm, needed);
}
void sctp_ulpq_partial_delivery(struct sctp_ulpq *ulpq,
gfp_t gfp)
{
struct sctp_ulpevent *event;
struct sctp_association *asoc;
struct sctp_sock *sp;
__u32 ctsn;
struct sk_buff *skb;
asoc = ulpq->asoc;
sp = sctp_sk(asoc->base.sk);
if (ulpq->pd_mode)
return;
skb = skb_peek(&asoc->ulpq.reasm);
if (skb != NULL) {
ctsn = sctp_skb2event(skb)->tsn;
if (!TSN_lte(ctsn, sctp_tsnmap_get_ctsn(&asoc->peer.tsn_map)))
return;
}
if (sp->frag_interleave || atomic_read(&sp->pd_mode) == 0) {
event = sctp_ulpq_retrieve_first(ulpq);
if (event) {
sctp_ulpq_tail_event(ulpq, event);
sctp_ulpq_set_pd(ulpq);
return;
}
}
}
void sctp_ulpq_renege(struct sctp_ulpq *ulpq, struct sctp_chunk *chunk,
gfp_t gfp)
{
struct sctp_association *asoc;
__u16 needed, freed;
asoc = ulpq->asoc;
if (chunk) {
needed = ntohs(chunk->chunk_hdr->length);
needed -= sizeof(struct sctp_data_chunk);
} else
needed = SCTP_DEFAULT_MAXWINDOW;
freed = 0;
if (skb_queue_empty(&asoc->base.sk->sk_receive_queue)) {
freed = sctp_ulpq_renege_order(ulpq, needed);
if (freed < needed) {
freed += sctp_ulpq_renege_frags(ulpq, needed - freed);
}
}
if (chunk && (freed >= needed)) {
int retval;
retval = sctp_ulpq_tail_data(ulpq, chunk, gfp);
if (retval <= 0)
sctp_ulpq_partial_delivery(ulpq, gfp);
else if (retval == 1)
sctp_ulpq_reasm_drain(ulpq);
}
sk_mem_reclaim(asoc->base.sk);
}
void sctp_ulpq_abort_pd(struct sctp_ulpq *ulpq, gfp_t gfp)
{
struct sctp_ulpevent *ev = NULL;
struct sock *sk;
struct sctp_sock *sp;
if (!ulpq->pd_mode)
return;
sk = ulpq->asoc->base.sk;
sp = sctp_sk(sk);
if (sctp_ulpevent_type_enabled(SCTP_PARTIAL_DELIVERY_EVENT,
&sctp_sk(sk)->subscribe))
ev = sctp_ulpevent_make_pdapi(ulpq->asoc,
SCTP_PARTIAL_DELIVERY_ABORTED,
gfp);
if (ev)
__skb_queue_tail(&sk->sk_receive_queue, sctp_event2skb(ev));
if ((sctp_ulpq_clear_pd(ulpq) || ev) && !sp->data_ready_signalled) {
sp->data_ready_signalled = 1;
sk->sk_data_ready(sk);
}
}
