static void sctp_ulpevent_init(struct sctp_ulpevent *event,
__u16 msg_flags,
unsigned int len)
{
memset(event, 0, sizeof(struct sctp_ulpevent));
event->msg_flags = msg_flags;
event->rmem_len = len;
}
static struct sctp_ulpevent *sctp_ulpevent_new(int size, __u16 msg_flags,
gfp_t gfp)
{
struct sctp_ulpevent *event;
struct sk_buff *skb;
skb = alloc_skb(size, gfp);
if (!skb)
goto fail;
event = sctp_skb2event(skb);
sctp_ulpevent_init(event, msg_flags, skb->truesize);
return event;
fail:
return NULL;
}
int sctp_ulpevent_is_notification(const struct sctp_ulpevent *event)
{
return MSG_NOTIFICATION == (event->msg_flags & MSG_NOTIFICATION);
}
static inline void sctp_ulpevent_set_owner(struct sctp_ulpevent *event,
const struct sctp_association *asoc)
{
struct sctp_chunk *chunk = event->chunk;
struct sk_buff *skb;
sctp_association_hold((struct sctp_association *)asoc);
skb = sctp_event2skb(event);
event->asoc = (struct sctp_association *)asoc;
atomic_add(event->rmem_len, &event->asoc->rmem_alloc);
sctp_skb_set_owner_r(skb, asoc->base.sk);
if (chunk && chunk->head_skb && !chunk->head_skb->sk)
chunk->head_skb->sk = asoc->base.sk;
}
static inline void sctp_ulpevent_release_owner(struct sctp_ulpevent *event)
{
struct sctp_association *asoc = event->asoc;
atomic_sub(event->rmem_len, &asoc->rmem_alloc);
sctp_association_put(asoc);
}
struct sctp_ulpevent *sctp_ulpevent_make_assoc_change(
const struct sctp_association *asoc,
__u16 flags, __u16 state, __u16 error, __u16 outbound,
__u16 inbound, struct sctp_chunk *chunk, gfp_t gfp)
{
struct sctp_ulpevent *event;
struct sctp_assoc_change *sac;
struct sk_buff *skb;
if (chunk) {
skb = skb_copy_expand(chunk->skb,
sizeof(struct sctp_assoc_change), 0, gfp);
if (!skb)
goto fail;
event = sctp_skb2event(skb);
sctp_ulpevent_init(event, MSG_NOTIFICATION, skb->truesize);
sac = skb_push(skb, sizeof(struct sctp_assoc_change));
skb_trim(skb, sizeof(struct sctp_assoc_change) +
ntohs(chunk->chunk_hdr->length) -
sizeof(struct sctp_chunkhdr));
} else {
event = sctp_ulpevent_new(sizeof(struct sctp_assoc_change),
MSG_NOTIFICATION, gfp);
if (!event)
goto fail;
skb = sctp_event2skb(event);
sac = skb_put(skb, sizeof(struct sctp_assoc_change));
}
sac->sac_type = SCTP_ASSOC_CHANGE;
sac->sac_state = state;
sac->sac_flags = 0;
sac->sac_length = skb->len;
sac->sac_error = error;
sac->sac_outbound_streams = outbound;
sac->sac_inbound_streams = inbound;
sctp_ulpevent_set_owner(event, asoc);
sac->sac_assoc_id = sctp_assoc2id(asoc);
return event;
fail:
return NULL;
}
struct sctp_ulpevent *sctp_ulpevent_make_peer_addr_change(
const struct sctp_association *asoc,
const struct sockaddr_storage *aaddr,
int flags, int state, int error, gfp_t gfp)
{
struct sctp_ulpevent *event;
struct sctp_paddr_change *spc;
struct sk_buff *skb;
event = sctp_ulpevent_new(sizeof(struct sctp_paddr_change),
MSG_NOTIFICATION, gfp);
if (!event)
goto fail;
skb = sctp_event2skb(event);
spc = skb_put(skb, sizeof(struct sctp_paddr_change));
spc->spc_type = SCTP_PEER_ADDR_CHANGE;
spc->spc_length = sizeof(struct sctp_paddr_change);
spc->spc_flags = 0;
spc->spc_state = state;
spc->spc_error = error;
sctp_ulpevent_set_owner(event, asoc);
spc->spc_assoc_id = sctp_assoc2id(asoc);
memcpy(&spc->spc_aaddr, aaddr, sizeof(struct sockaddr_storage));
sctp_get_pf_specific(asoc->base.sk->sk_family)->addr_to_user(
sctp_sk(asoc->base.sk),
(union sctp_addr *)&spc->spc_aaddr);
return event;
fail:
return NULL;
}
struct sctp_ulpevent *
sctp_ulpevent_make_remote_error(const struct sctp_association *asoc,
struct sctp_chunk *chunk, __u16 flags,
gfp_t gfp)
{
struct sctp_ulpevent *event;
struct sctp_remote_error *sre;
struct sk_buff *skb;
sctp_errhdr_t *ch;
__be16 cause;
int elen;
ch = (sctp_errhdr_t *)(chunk->skb->data);
cause = ch->cause;
elen = SCTP_PAD4(ntohs(ch->length)) - sizeof(sctp_errhdr_t);
skb_pull(chunk->skb, sizeof(sctp_errhdr_t));
skb = skb_copy_expand(chunk->skb, sizeof(*sre), 0, gfp);
skb_pull(chunk->skb, elen);
if (!skb)
goto fail;
event = sctp_skb2event(skb);
sctp_ulpevent_init(event, MSG_NOTIFICATION, skb->truesize);
sre = skb_push(skb, sizeof(*sre));
skb_trim(skb, sizeof(*sre) + elen);
memset(sre, 0, sizeof(*sre));
sre->sre_type = SCTP_REMOTE_ERROR;
sre->sre_flags = 0;
sre->sre_length = skb->len;
sre->sre_error = cause;
sctp_ulpevent_set_owner(event, asoc);
sre->sre_assoc_id = sctp_assoc2id(asoc);
return event;
fail:
return NULL;
}
struct sctp_ulpevent *sctp_ulpevent_make_send_failed(
const struct sctp_association *asoc, struct sctp_chunk *chunk,
__u16 flags, __u32 error, gfp_t gfp)
{
struct sctp_ulpevent *event;
struct sctp_send_failed *ssf;
struct sk_buff *skb;
int len = ntohs(chunk->chunk_hdr->length);
skb = skb_copy_expand(chunk->skb,
sizeof(struct sctp_send_failed),
0,
gfp);
if (!skb)
goto fail;
skb_pull(skb, sizeof(struct sctp_data_chunk));
len -= sizeof(struct sctp_data_chunk);
event = sctp_skb2event(skb);
sctp_ulpevent_init(event, MSG_NOTIFICATION, skb->truesize);
ssf = skb_push(skb, sizeof(struct sctp_send_failed));
ssf->ssf_type = SCTP_SEND_FAILED;
ssf->ssf_flags = flags;
ssf->ssf_length = sizeof(struct sctp_send_failed) + len;
skb_trim(skb, ssf->ssf_length);
ssf->ssf_error = error;
memcpy(&ssf->ssf_info, &chunk->sinfo, sizeof(struct sctp_sndrcvinfo));
ssf->ssf_info.sinfo_flags = chunk->chunk_hdr->flags;
sctp_ulpevent_set_owner(event, asoc);
ssf->ssf_assoc_id = sctp_assoc2id(asoc);
return event;
fail:
return NULL;
}
struct sctp_ulpevent *sctp_ulpevent_make_shutdown_event(
const struct sctp_association *asoc,
__u16 flags, gfp_t gfp)
{
struct sctp_ulpevent *event;
struct sctp_shutdown_event *sse;
struct sk_buff *skb;
event = sctp_ulpevent_new(sizeof(struct sctp_shutdown_event),
MSG_NOTIFICATION, gfp);
if (!event)
goto fail;
skb = sctp_event2skb(event);
sse = skb_put(skb, sizeof(struct sctp_shutdown_event));
sse->sse_type = SCTP_SHUTDOWN_EVENT;
sse->sse_flags = 0;
sse->sse_length = sizeof(struct sctp_shutdown_event);
sctp_ulpevent_set_owner(event, asoc);
sse->sse_assoc_id = sctp_assoc2id(asoc);
return event;
fail:
return NULL;
}
struct sctp_ulpevent *sctp_ulpevent_make_adaptation_indication(
const struct sctp_association *asoc, gfp_t gfp)
{
struct sctp_ulpevent *event;
struct sctp_adaptation_event *sai;
struct sk_buff *skb;
event = sctp_ulpevent_new(sizeof(struct sctp_adaptation_event),
MSG_NOTIFICATION, gfp);
if (!event)
goto fail;
skb = sctp_event2skb(event);
sai = skb_put(skb, sizeof(struct sctp_adaptation_event));
sai->sai_type = SCTP_ADAPTATION_INDICATION;
sai->sai_flags = 0;
sai->sai_length = sizeof(struct sctp_adaptation_event);
sai->sai_adaptation_ind = asoc->peer.adaptation_ind;
sctp_ulpevent_set_owner(event, asoc);
sai->sai_assoc_id = sctp_assoc2id(asoc);
return event;
fail:
return NULL;
}
struct sctp_ulpevent *sctp_ulpevent_make_rcvmsg(struct sctp_association *asoc,
struct sctp_chunk *chunk,
gfp_t gfp)
{
struct sctp_ulpevent *event = NULL;
struct sk_buff *skb;
size_t padding, len;
int rx_count;
if (asoc->ep->rcvbuf_policy)
rx_count = atomic_read(&asoc->rmem_alloc);
else
rx_count = atomic_read(&asoc->base.sk->sk_rmem_alloc);
if (rx_count >= asoc->base.sk->sk_rcvbuf) {
if ((asoc->base.sk->sk_userlocks & SOCK_RCVBUF_LOCK) ||
(!sk_rmem_schedule(asoc->base.sk, chunk->skb,
chunk->skb->truesize)))
goto fail;
}
skb = skb_clone(chunk->skb, gfp);
if (!skb)
goto fail;
if (sctp_tsnmap_mark(&asoc->peer.tsn_map,
ntohl(chunk->subh.data_hdr->tsn),
chunk->transport))
goto fail_mark;
len = ntohs(chunk->chunk_hdr->length);
padding = SCTP_PAD4(len) - len;
skb_trim(skb, chunk->chunk_end - padding - skb->data);
event = sctp_skb2event(skb);
sctp_ulpevent_init(event, 0, skb->len + sizeof(struct sk_buff));
sctp_chunk_hold(chunk);
event->chunk = chunk;
sctp_ulpevent_receive_data(event, asoc);
event->stream = ntohs(chunk->subh.data_hdr->stream);
event->ssn = ntohs(chunk->subh.data_hdr->ssn);
event->ppid = chunk->subh.data_hdr->ppid;
if (chunk->chunk_hdr->flags & SCTP_DATA_UNORDERED) {
event->flags |= SCTP_UNORDERED;
event->cumtsn = sctp_tsnmap_get_ctsn(&asoc->peer.tsn_map);
}
event->tsn = ntohl(chunk->subh.data_hdr->tsn);
event->msg_flags |= chunk->chunk_hdr->flags;
return event;
fail_mark:
sctp_chunk_put(chunk);
kfree_skb(skb);
fail:
return NULL;
}
struct sctp_ulpevent *sctp_ulpevent_make_pdapi(
const struct sctp_association *asoc, __u32 indication,
gfp_t gfp)
{
struct sctp_ulpevent *event;
struct sctp_pdapi_event *pd;
struct sk_buff *skb;
event = sctp_ulpevent_new(sizeof(struct sctp_pdapi_event),
MSG_NOTIFICATION, gfp);
if (!event)
goto fail;
skb = sctp_event2skb(event);
pd = skb_put(skb, sizeof(struct sctp_pdapi_event));
pd->pdapi_type = SCTP_PARTIAL_DELIVERY_EVENT;
pd->pdapi_flags = 0;
pd->pdapi_length = sizeof(struct sctp_pdapi_event);
pd->pdapi_indication = indication;
sctp_ulpevent_set_owner(event, asoc);
pd->pdapi_assoc_id = sctp_assoc2id(asoc);
return event;
fail:
return NULL;
}
struct sctp_ulpevent *sctp_ulpevent_make_authkey(
const struct sctp_association *asoc, __u16 key_id,
__u32 indication, gfp_t gfp)
{
struct sctp_ulpevent *event;
struct sctp_authkey_event *ak;
struct sk_buff *skb;
event = sctp_ulpevent_new(sizeof(struct sctp_authkey_event),
MSG_NOTIFICATION, gfp);
if (!event)
goto fail;
skb = sctp_event2skb(event);
ak = skb_put(skb, sizeof(struct sctp_authkey_event));
ak->auth_type = SCTP_AUTHENTICATION_EVENT;
ak->auth_flags = 0;
ak->auth_length = sizeof(struct sctp_authkey_event);
ak->auth_keynumber = key_id;
ak->auth_altkeynumber = 0;
ak->auth_indication = indication;
sctp_ulpevent_set_owner(event, asoc);
ak->auth_assoc_id = sctp_assoc2id(asoc);
return event;
fail:
return NULL;
}
struct sctp_ulpevent *sctp_ulpevent_make_sender_dry_event(
const struct sctp_association *asoc, gfp_t gfp)
{
struct sctp_ulpevent *event;
struct sctp_sender_dry_event *sdry;
struct sk_buff *skb;
event = sctp_ulpevent_new(sizeof(struct sctp_sender_dry_event),
MSG_NOTIFICATION, gfp);
if (!event)
return NULL;
skb = sctp_event2skb(event);
sdry = skb_put(skb, sizeof(struct sctp_sender_dry_event));
sdry->sender_dry_type = SCTP_SENDER_DRY_EVENT;
sdry->sender_dry_flags = 0;
sdry->sender_dry_length = sizeof(struct sctp_sender_dry_event);
sctp_ulpevent_set_owner(event, asoc);
sdry->sender_dry_assoc_id = sctp_assoc2id(asoc);
return event;
}
struct sctp_ulpevent *sctp_ulpevent_make_stream_reset_event(
const struct sctp_association *asoc, __u16 flags, __u16 stream_num,
__u16 *stream_list, gfp_t gfp)
{
struct sctp_stream_reset_event *sreset;
struct sctp_ulpevent *event;
struct sk_buff *skb;
int length, i;
length = sizeof(struct sctp_stream_reset_event) + 2 * stream_num;
event = sctp_ulpevent_new(length, MSG_NOTIFICATION, gfp);
if (!event)
return NULL;
skb = sctp_event2skb(event);
sreset = skb_put(skb, length);
sreset->strreset_type = SCTP_STREAM_RESET_EVENT;
sreset->strreset_flags = flags;
sreset->strreset_length = length;
sctp_ulpevent_set_owner(event, asoc);
sreset->strreset_assoc_id = sctp_assoc2id(asoc);
for (i = 0; i < stream_num; i++)
sreset->strreset_stream_list[i] = ntohs(stream_list[i]);
return event;
}
struct sctp_ulpevent *sctp_ulpevent_make_assoc_reset_event(
const struct sctp_association *asoc, __u16 flags, __u32 local_tsn,
__u32 remote_tsn, gfp_t gfp)
{
struct sctp_assoc_reset_event *areset;
struct sctp_ulpevent *event;
struct sk_buff *skb;
event = sctp_ulpevent_new(sizeof(struct sctp_assoc_reset_event),
MSG_NOTIFICATION, gfp);
if (!event)
return NULL;
skb = sctp_event2skb(event);
areset = skb_put(skb, sizeof(struct sctp_assoc_reset_event));
areset->assocreset_type = SCTP_ASSOC_RESET_EVENT;
areset->assocreset_flags = flags;
areset->assocreset_length = sizeof(struct sctp_assoc_reset_event);
sctp_ulpevent_set_owner(event, asoc);
areset->assocreset_assoc_id = sctp_assoc2id(asoc);
areset->assocreset_local_tsn = local_tsn;
areset->assocreset_remote_tsn = remote_tsn;
return event;
}
struct sctp_ulpevent *sctp_ulpevent_make_stream_change_event(
const struct sctp_association *asoc, __u16 flags,
__u32 strchange_instrms, __u32 strchange_outstrms, gfp_t gfp)
{
struct sctp_stream_change_event *schange;
struct sctp_ulpevent *event;
struct sk_buff *skb;
event = sctp_ulpevent_new(sizeof(struct sctp_stream_change_event),
MSG_NOTIFICATION, gfp);
if (!event)
return NULL;
skb = sctp_event2skb(event);
schange = skb_put(skb, sizeof(struct sctp_stream_change_event));
schange->strchange_type = SCTP_STREAM_CHANGE_EVENT;
schange->strchange_flags = flags;
schange->strchange_length = sizeof(struct sctp_stream_change_event);
sctp_ulpevent_set_owner(event, asoc);
schange->strchange_assoc_id = sctp_assoc2id(asoc);
schange->strchange_instrms = strchange_instrms;
schange->strchange_outstrms = strchange_outstrms;
return event;
}
__u16 sctp_ulpevent_get_notification_type(const struct sctp_ulpevent *event)
{
union sctp_notification *notification;
struct sk_buff *skb;
skb = sctp_event2skb(event);
notification = (union sctp_notification *) skb->data;
return notification->sn_header.sn_type;
}
void sctp_ulpevent_read_sndrcvinfo(const struct sctp_ulpevent *event,
struct msghdr *msghdr)
{
struct sctp_sndrcvinfo sinfo;
if (sctp_ulpevent_is_notification(event))
return;
memset(&sinfo, 0, sizeof(sinfo));
sinfo.sinfo_stream = event->stream;
sinfo.sinfo_ssn = event->ssn;
sinfo.sinfo_ppid = event->ppid;
sinfo.sinfo_flags = event->flags;
sinfo.sinfo_tsn = event->tsn;
sinfo.sinfo_cumtsn = event->cumtsn;
sinfo.sinfo_assoc_id = sctp_assoc2id(event->asoc);
sinfo.sinfo_context = event->asoc->default_rcv_context;
sinfo.sinfo_timetolive = 0;
put_cmsg(msghdr, IPPROTO_SCTP, SCTP_SNDRCV,
sizeof(sinfo), &sinfo);
}
void sctp_ulpevent_read_rcvinfo(const struct sctp_ulpevent *event,
struct msghdr *msghdr)
{
struct sctp_rcvinfo rinfo;
if (sctp_ulpevent_is_notification(event))
return;
memset(&rinfo, 0, sizeof(struct sctp_rcvinfo));
rinfo.rcv_sid = event->stream;
rinfo.rcv_ssn = event->ssn;
rinfo.rcv_ppid = event->ppid;
rinfo.rcv_flags = event->flags;
rinfo.rcv_tsn = event->tsn;
rinfo.rcv_cumtsn = event->cumtsn;
rinfo.rcv_assoc_id = sctp_assoc2id(event->asoc);
rinfo.rcv_context = event->asoc->default_rcv_context;
put_cmsg(msghdr, IPPROTO_SCTP, SCTP_RCVINFO,
sizeof(rinfo), &rinfo);
}
static void __sctp_ulpevent_read_nxtinfo(const struct sctp_ulpevent *event,
struct msghdr *msghdr,
const struct sk_buff *skb)
{
struct sctp_nxtinfo nxtinfo;
memset(&nxtinfo, 0, sizeof(nxtinfo));
nxtinfo.nxt_sid = event->stream;
nxtinfo.nxt_ppid = event->ppid;
nxtinfo.nxt_flags = event->flags;
if (sctp_ulpevent_is_notification(event))
nxtinfo.nxt_flags |= SCTP_NOTIFICATION;
nxtinfo.nxt_length = skb->len;
nxtinfo.nxt_assoc_id = sctp_assoc2id(event->asoc);
put_cmsg(msghdr, IPPROTO_SCTP, SCTP_NXTINFO,
sizeof(nxtinfo), &nxtinfo);
}
void sctp_ulpevent_read_nxtinfo(const struct sctp_ulpevent *event,
struct msghdr *msghdr,
struct sock *sk)
{
struct sk_buff *skb;
int err;
skb = sctp_skb_recv_datagram(sk, MSG_PEEK, 1, &err);
if (skb != NULL) {
__sctp_ulpevent_read_nxtinfo(sctp_skb2event(skb),
msghdr, skb);
kfree_skb(skb);
}
}
static void sctp_ulpevent_receive_data(struct sctp_ulpevent *event,
struct sctp_association *asoc)
{
struct sk_buff *skb, *frag;
skb = sctp_event2skb(event);
sctp_ulpevent_set_owner(event, asoc);
sctp_assoc_rwnd_decrease(asoc, skb_headlen(skb));
if (!skb->data_len)
return;
skb_walk_frags(skb, frag)
sctp_ulpevent_receive_data(sctp_skb2event(frag), asoc);
}
static void sctp_ulpevent_release_data(struct sctp_ulpevent *event)
{
struct sk_buff *skb, *frag;
unsigned int len;
skb = sctp_event2skb(event);
len = skb->len;
if (!skb->data_len)
goto done;
skb_walk_frags(skb, frag) {
sctp_ulpevent_release_frag_data(sctp_skb2event(frag));
}
done:
sctp_assoc_rwnd_increase(event->asoc, len);
sctp_chunk_put(event->chunk);
sctp_ulpevent_release_owner(event);
}
static void sctp_ulpevent_release_frag_data(struct sctp_ulpevent *event)
{
struct sk_buff *skb, *frag;
skb = sctp_event2skb(event);
if (!skb->data_len)
goto done;
skb_walk_frags(skb, frag) {
sctp_ulpevent_release_frag_data(sctp_skb2event(frag));
}
done:
sctp_chunk_put(event->chunk);
sctp_ulpevent_release_owner(event);
}
void sctp_ulpevent_free(struct sctp_ulpevent *event)
{
if (sctp_ulpevent_is_notification(event))
sctp_ulpevent_release_owner(event);
else
sctp_ulpevent_release_data(event);
kfree_skb(sctp_event2skb(event));
}
unsigned int sctp_queue_purge_ulpevents(struct sk_buff_head *list)
{
struct sk_buff *skb;
unsigned int data_unread = 0;
while ((skb = skb_dequeue(list)) != NULL) {
struct sctp_ulpevent *event = sctp_skb2event(skb);
if (!sctp_ulpevent_is_notification(event))
data_unread += skb->len;
sctp_ulpevent_free(event);
}
return data_unread;
}
