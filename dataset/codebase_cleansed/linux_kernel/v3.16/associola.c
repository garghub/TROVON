static struct sctp_association *sctp_association_init(struct sctp_association *asoc,
const struct sctp_endpoint *ep,
const struct sock *sk,
sctp_scope_t scope,
gfp_t gfp)
{
struct net *net = sock_net(sk);
struct sctp_sock *sp;
int i;
sctp_paramhdr_t *p;
int err;
sp = sctp_sk((struct sock *)sk);
asoc->ep = (struct sctp_endpoint *)ep;
asoc->base.sk = (struct sock *)sk;
sctp_endpoint_hold(asoc->ep);
sock_hold(asoc->base.sk);
asoc->base.type = SCTP_EP_TYPE_ASSOCIATION;
atomic_set(&asoc->base.refcnt, 1);
sctp_bind_addr_init(&asoc->base.bind_addr, ep->base.bind_addr.port);
asoc->state = SCTP_STATE_CLOSED;
asoc->cookie_life = ms_to_ktime(sp->assocparams.sasoc_cookie_life);
asoc->user_frag = sp->user_frag;
asoc->max_retrans = sp->assocparams.sasoc_asocmaxrxt;
asoc->pf_retrans = net->sctp.pf_retrans;
asoc->rto_initial = msecs_to_jiffies(sp->rtoinfo.srto_initial);
asoc->rto_max = msecs_to_jiffies(sp->rtoinfo.srto_max);
asoc->rto_min = msecs_to_jiffies(sp->rtoinfo.srto_min);
asoc->hbinterval = msecs_to_jiffies(sp->hbinterval);
asoc->pathmaxrxt = sp->pathmaxrxt;
asoc->pathmtu = sp->pathmtu;
asoc->sackdelay = msecs_to_jiffies(sp->sackdelay);
asoc->sackfreq = sp->sackfreq;
asoc->param_flags = sp->param_flags;
asoc->max_burst = sp->max_burst;
asoc->timeouts[SCTP_EVENT_TIMEOUT_T1_COOKIE] = asoc->rto_initial;
asoc->timeouts[SCTP_EVENT_TIMEOUT_T1_INIT] = asoc->rto_initial;
asoc->timeouts[SCTP_EVENT_TIMEOUT_T2_SHUTDOWN] = asoc->rto_initial;
asoc->timeouts[SCTP_EVENT_TIMEOUT_T5_SHUTDOWN_GUARD]
= 5 * asoc->rto_max;
asoc->timeouts[SCTP_EVENT_TIMEOUT_SACK] = asoc->sackdelay;
asoc->timeouts[SCTP_EVENT_TIMEOUT_AUTOCLOSE] = sp->autoclose * HZ;
for (i = SCTP_EVENT_TIMEOUT_NONE; i < SCTP_NUM_TIMEOUT_TYPES; ++i)
setup_timer(&asoc->timers[i], sctp_timer_events[i],
(unsigned long)asoc);
asoc->c.sinit_max_instreams = sp->initmsg.sinit_max_instreams;
asoc->c.sinit_num_ostreams = sp->initmsg.sinit_num_ostreams;
asoc->max_init_attempts = sp->initmsg.sinit_max_attempts;
asoc->max_init_timeo =
msecs_to_jiffies(sp->initmsg.sinit_max_init_timeo);
if ((sk->sk_rcvbuf/2) < SCTP_DEFAULT_MINWINDOW)
asoc->rwnd = SCTP_DEFAULT_MINWINDOW;
else
asoc->rwnd = sk->sk_rcvbuf/2;
asoc->a_rwnd = asoc->rwnd;
asoc->peer.rwnd = SCTP_DEFAULT_MAXWINDOW;
atomic_set(&asoc->rmem_alloc, 0);
init_waitqueue_head(&asoc->wait);
asoc->c.my_vtag = sctp_generate_tag(ep);
asoc->c.my_port = ep->base.bind_addr.port;
asoc->c.initial_tsn = sctp_generate_tsn(ep);
asoc->next_tsn = asoc->c.initial_tsn;
asoc->ctsn_ack_point = asoc->next_tsn - 1;
asoc->adv_peer_ack_point = asoc->ctsn_ack_point;
asoc->highest_sacked = asoc->ctsn_ack_point;
asoc->last_cwr_tsn = asoc->ctsn_ack_point;
asoc->addip_serial = asoc->c.initial_tsn;
INIT_LIST_HEAD(&asoc->addip_chunk_list);
INIT_LIST_HEAD(&asoc->asconf_ack_list);
INIT_LIST_HEAD(&asoc->peer.transport_addr_list);
asoc->peer.sack_needed = 1;
asoc->peer.sack_generation = 1;
if (net->sctp.addip_noauth)
asoc->peer.asconf_capable = 1;
sctp_inq_init(&asoc->base.inqueue);
sctp_inq_set_th_handler(&asoc->base.inqueue, sctp_assoc_bh_rcv);
sctp_outq_init(asoc, &asoc->outqueue);
if (!sctp_ulpq_init(&asoc->ulpq, asoc))
goto fail_init;
asoc->peer.ipv4_address = 1;
if (asoc->base.sk->sk_family == PF_INET6)
asoc->peer.ipv6_address = 1;
INIT_LIST_HEAD(&asoc->asocs);
asoc->default_stream = sp->default_stream;
asoc->default_ppid = sp->default_ppid;
asoc->default_flags = sp->default_flags;
asoc->default_context = sp->default_context;
asoc->default_timetolive = sp->default_timetolive;
asoc->default_rcv_context = sp->default_rcv_context;
INIT_LIST_HEAD(&asoc->endpoint_shared_keys);
err = sctp_auth_asoc_copy_shkeys(ep, asoc, gfp);
if (err)
goto fail_init;
asoc->active_key_id = ep->active_key_id;
if (ep->auth_hmacs_list)
memcpy(asoc->c.auth_hmacs, ep->auth_hmacs_list,
ntohs(ep->auth_hmacs_list->param_hdr.length));
if (ep->auth_chunk_list)
memcpy(asoc->c.auth_chunks, ep->auth_chunk_list,
ntohs(ep->auth_chunk_list->param_hdr.length));
p = (sctp_paramhdr_t *)asoc->c.auth_random;
p->type = SCTP_PARAM_RANDOM;
p->length = htons(sizeof(sctp_paramhdr_t) + SCTP_AUTH_RANDOM_LENGTH);
get_random_bytes(p+1, SCTP_AUTH_RANDOM_LENGTH);
return asoc;
fail_init:
sock_put(asoc->base.sk);
sctp_endpoint_put(asoc->ep);
return NULL;
}
struct sctp_association *sctp_association_new(const struct sctp_endpoint *ep,
const struct sock *sk,
sctp_scope_t scope,
gfp_t gfp)
{
struct sctp_association *asoc;
asoc = kzalloc(sizeof(*asoc), gfp);
if (!asoc)
goto fail;
if (!sctp_association_init(asoc, ep, sk, scope, gfp))
goto fail_init;
SCTP_DBG_OBJCNT_INC(assoc);
pr_debug("Created asoc %p\n", asoc);
return asoc;
fail_init:
kfree(asoc);
fail:
return NULL;
}
void sctp_association_free(struct sctp_association *asoc)
{
struct sock *sk = asoc->base.sk;
struct sctp_transport *transport;
struct list_head *pos, *temp;
int i;
if (!list_empty(&asoc->asocs)) {
list_del(&asoc->asocs);
if (sctp_style(sk, TCP) && sctp_sstate(sk, LISTENING))
sk->sk_ack_backlog--;
}
asoc->base.dead = true;
sctp_outq_free(&asoc->outqueue);
sctp_ulpq_free(&asoc->ulpq);
sctp_inq_free(&asoc->base.inqueue);
sctp_tsnmap_free(&asoc->peer.tsn_map);
sctp_ssnmap_free(asoc->ssnmap);
sctp_bind_addr_free(&asoc->base.bind_addr);
for (i = SCTP_EVENT_TIMEOUT_NONE; i < SCTP_NUM_TIMEOUT_TYPES; ++i) {
if (del_timer(&asoc->timers[i]))
sctp_association_put(asoc);
}
kfree(asoc->peer.cookie);
kfree(asoc->peer.peer_random);
kfree(asoc->peer.peer_chunks);
kfree(asoc->peer.peer_hmacs);
list_for_each_safe(pos, temp, &asoc->peer.transport_addr_list) {
transport = list_entry(pos, struct sctp_transport, transports);
list_del_rcu(pos);
sctp_transport_free(transport);
}
asoc->peer.transport_count = 0;
sctp_asconf_queue_teardown(asoc);
if (asoc->asconf_addr_del_pending != NULL)
kfree(asoc->asconf_addr_del_pending);
sctp_auth_destroy_keys(&asoc->endpoint_shared_keys);
sctp_auth_key_put(asoc->asoc_shared_key);
sctp_association_put(asoc);
}
static void sctp_association_destroy(struct sctp_association *asoc)
{
if (unlikely(!asoc->base.dead)) {
WARN(1, "Attempt to destroy undead association %p!\n", asoc);
return;
}
sctp_endpoint_put(asoc->ep);
sock_put(asoc->base.sk);
if (asoc->assoc_id != 0) {
spin_lock_bh(&sctp_assocs_id_lock);
idr_remove(&sctp_assocs_id, asoc->assoc_id);
spin_unlock_bh(&sctp_assocs_id_lock);
}
WARN_ON(atomic_read(&asoc->rmem_alloc));
kfree(asoc);
SCTP_DBG_OBJCNT_DEC(assoc);
}
void sctp_assoc_set_primary(struct sctp_association *asoc,
struct sctp_transport *transport)
{
int changeover = 0;
if (asoc->peer.primary_path != NULL &&
asoc->peer.primary_path != transport)
changeover = 1 ;
asoc->peer.primary_path = transport;
memcpy(&asoc->peer.primary_addr, &transport->ipaddr,
sizeof(union sctp_addr));
if ((transport->state == SCTP_ACTIVE) ||
(transport->state == SCTP_UNKNOWN))
asoc->peer.active_path = transport;
if (!asoc->outqueue.outstanding_bytes && !asoc->outqueue.out_qlen)
return;
if (transport->cacc.changeover_active)
transport->cacc.cycling_changeover = changeover;
transport->cacc.changeover_active = changeover;
transport->cacc.next_tsn_at_change = asoc->next_tsn;
}
void sctp_assoc_rm_peer(struct sctp_association *asoc,
struct sctp_transport *peer)
{
struct list_head *pos;
struct sctp_transport *transport;
pr_debug("%s: association:%p addr:%pISpc\n",
__func__, asoc, &peer->ipaddr.sa);
if (asoc->peer.retran_path == peer)
sctp_assoc_update_retran_path(asoc);
list_del_rcu(&peer->transports);
pos = asoc->peer.transport_addr_list.next;
transport = list_entry(pos, struct sctp_transport, transports);
if (asoc->peer.primary_path == peer)
sctp_assoc_set_primary(asoc, transport);
if (asoc->peer.active_path == peer)
asoc->peer.active_path = transport;
if (asoc->peer.retran_path == peer)
asoc->peer.retran_path = transport;
if (asoc->peer.last_data_from == peer)
asoc->peer.last_data_from = transport;
if (asoc->init_last_sent_to == peer)
asoc->init_last_sent_to = NULL;
if (asoc->shutdown_last_sent_to == peer)
asoc->shutdown_last_sent_to = NULL;
if (asoc->addip_last_asconf &&
asoc->addip_last_asconf->transport == peer)
asoc->addip_last_asconf->transport = NULL;
if (!list_empty(&peer->transmitted)) {
struct sctp_transport *active = asoc->peer.active_path;
struct sctp_chunk *ch;
list_for_each_entry(ch, &peer->transmitted,
transmitted_list) {
ch->transport = NULL;
ch->rtt_in_progress = 0;
}
list_splice_tail_init(&peer->transmitted,
&active->transmitted);
if (!timer_pending(&active->T3_rtx_timer))
if (!mod_timer(&active->T3_rtx_timer,
jiffies + active->rto))
sctp_transport_hold(active);
}
asoc->peer.transport_count--;
sctp_transport_free(peer);
}
struct sctp_transport *sctp_assoc_add_peer(struct sctp_association *asoc,
const union sctp_addr *addr,
const gfp_t gfp,
const int peer_state)
{
struct net *net = sock_net(asoc->base.sk);
struct sctp_transport *peer;
struct sctp_sock *sp;
unsigned short port;
sp = sctp_sk(asoc->base.sk);
port = ntohs(addr->v4.sin_port);
pr_debug("%s: association:%p addr:%pISpc state:%d\n", __func__,
asoc, &addr->sa, peer_state);
if (0 == asoc->peer.port)
asoc->peer.port = port;
peer = sctp_assoc_lookup_paddr(asoc, addr);
if (peer) {
if (peer->state == SCTP_UNKNOWN) {
peer->state = SCTP_ACTIVE;
}
return peer;
}
peer = sctp_transport_new(net, addr, gfp);
if (!peer)
return NULL;
sctp_transport_set_owner(peer, asoc);
peer->hbinterval = asoc->hbinterval;
peer->pathmaxrxt = asoc->pathmaxrxt;
peer->pf_retrans = asoc->pf_retrans;
peer->sackdelay = asoc->sackdelay;
peer->sackfreq = asoc->sackfreq;
peer->param_flags = asoc->param_flags;
sctp_transport_route(peer, NULL, sp);
if (peer->param_flags & SPP_PMTUD_DISABLE) {
if (asoc->pathmtu)
peer->pathmtu = asoc->pathmtu;
else
peer->pathmtu = SCTP_DEFAULT_MAXSEGMENT;
}
if (asoc->pathmtu)
asoc->pathmtu = min_t(int, peer->pathmtu, asoc->pathmtu);
else
asoc->pathmtu = peer->pathmtu;
pr_debug("%s: association:%p PMTU set to %d\n", __func__, asoc,
asoc->pathmtu);
peer->pmtu_pending = 0;
asoc->frag_point = sctp_frag_point(asoc, asoc->pathmtu);
sctp_packet_init(&peer->packet, peer, asoc->base.bind_addr.port,
asoc->peer.port);
peer->cwnd = min(4*asoc->pathmtu, max_t(__u32, 2*asoc->pathmtu, 4380));
peer->ssthresh = SCTP_DEFAULT_MAXWINDOW;
peer->partial_bytes_acked = 0;
peer->flight_size = 0;
peer->burst_limited = 0;
peer->rto = asoc->rto_initial;
sctp_max_rto(asoc, peer);
peer->state = peer_state;
list_add_tail_rcu(&peer->transports, &asoc->peer.transport_addr_list);
asoc->peer.transport_count++;
if (!asoc->peer.primary_path) {
sctp_assoc_set_primary(asoc, peer);
asoc->peer.retran_path = peer;
}
if (asoc->peer.active_path == asoc->peer.retran_path &&
peer->state != SCTP_UNCONFIRMED) {
asoc->peer.retran_path = peer;
}
return peer;
}
void sctp_assoc_del_peer(struct sctp_association *asoc,
const union sctp_addr *addr)
{
struct list_head *pos;
struct list_head *temp;
struct sctp_transport *transport;
list_for_each_safe(pos, temp, &asoc->peer.transport_addr_list) {
transport = list_entry(pos, struct sctp_transport, transports);
if (sctp_cmp_addr_exact(addr, &transport->ipaddr)) {
sctp_assoc_rm_peer(asoc, transport);
break;
}
}
}
struct sctp_transport *sctp_assoc_lookup_paddr(
const struct sctp_association *asoc,
const union sctp_addr *address)
{
struct sctp_transport *t;
list_for_each_entry(t, &asoc->peer.transport_addr_list,
transports) {
if (sctp_cmp_addr_exact(address, &t->ipaddr))
return t;
}
return NULL;
}
void sctp_assoc_del_nonprimary_peers(struct sctp_association *asoc,
struct sctp_transport *primary)
{
struct sctp_transport *temp;
struct sctp_transport *t;
list_for_each_entry_safe(t, temp, &asoc->peer.transport_addr_list,
transports) {
if (t != primary)
sctp_assoc_rm_peer(asoc, t);
}
}
void sctp_assoc_control_transport(struct sctp_association *asoc,
struct sctp_transport *transport,
sctp_transport_cmd_t command,
sctp_sn_error_t error)
{
struct sctp_ulpevent *event;
struct sockaddr_storage addr;
int spc_state = 0;
bool ulp_notify = true;
switch (command) {
case SCTP_TRANSPORT_UP:
if (SCTP_UNCONFIRMED == transport->state &&
SCTP_HEARTBEAT_SUCCESS == error)
spc_state = SCTP_ADDR_CONFIRMED;
else
spc_state = SCTP_ADDR_AVAILABLE;
if (transport->state == SCTP_PF) {
ulp_notify = false;
transport->cwnd = asoc->pathmtu;
}
transport->state = SCTP_ACTIVE;
break;
case SCTP_TRANSPORT_DOWN:
if (transport->state != SCTP_UNCONFIRMED)
transport->state = SCTP_INACTIVE;
else {
dst_release(transport->dst);
transport->dst = NULL;
}
spc_state = SCTP_ADDR_UNREACHABLE;
break;
case SCTP_TRANSPORT_PF:
transport->state = SCTP_PF;
ulp_notify = false;
break;
default:
return;
}
if (ulp_notify) {
memset(&addr, 0, sizeof(struct sockaddr_storage));
memcpy(&addr, &transport->ipaddr,
transport->af_specific->sockaddr_len);
event = sctp_ulpevent_make_peer_addr_change(asoc, &addr,
0, spc_state, error, GFP_ATOMIC);
if (event)
sctp_ulpq_tail_event(&asoc->ulpq, event);
}
sctp_select_active_and_retran_path(asoc);
}
void sctp_association_hold(struct sctp_association *asoc)
{
atomic_inc(&asoc->base.refcnt);
}
void sctp_association_put(struct sctp_association *asoc)
{
if (atomic_dec_and_test(&asoc->base.refcnt))
sctp_association_destroy(asoc);
}
__u32 sctp_association_get_next_tsn(struct sctp_association *asoc)
{
__u32 retval = asoc->next_tsn;
asoc->next_tsn++;
asoc->unack_data++;
return retval;
}
int sctp_cmp_addr_exact(const union sctp_addr *ss1,
const union sctp_addr *ss2)
{
struct sctp_af *af;
af = sctp_get_af_specific(ss1->sa.sa_family);
if (unlikely(!af))
return 0;
return af->cmp_addr(ss1, ss2);
}
struct sctp_chunk *sctp_get_ecne_prepend(struct sctp_association *asoc)
{
if (!asoc->need_ecne)
return NULL;
return sctp_make_ecne(asoc, asoc->last_ecne_tsn);
}
struct sctp_transport *sctp_assoc_lookup_tsn(struct sctp_association *asoc,
__u32 tsn)
{
struct sctp_transport *active;
struct sctp_transport *match;
struct sctp_transport *transport;
struct sctp_chunk *chunk;
__be32 key = htonl(tsn);
match = NULL;
active = asoc->peer.active_path;
list_for_each_entry(chunk, &active->transmitted,
transmitted_list) {
if (key == chunk->subh.data_hdr->tsn) {
match = active;
goto out;
}
}
list_for_each_entry(transport, &asoc->peer.transport_addr_list,
transports) {
if (transport == active)
continue;
list_for_each_entry(chunk, &transport->transmitted,
transmitted_list) {
if (key == chunk->subh.data_hdr->tsn) {
match = transport;
goto out;
}
}
}
out:
return match;
}
struct sctp_transport *sctp_assoc_is_match(struct sctp_association *asoc,
struct net *net,
const union sctp_addr *laddr,
const union sctp_addr *paddr)
{
struct sctp_transport *transport;
if ((htons(asoc->base.bind_addr.port) == laddr->v4.sin_port) &&
(htons(asoc->peer.port) == paddr->v4.sin_port) &&
net_eq(sock_net(asoc->base.sk), net)) {
transport = sctp_assoc_lookup_paddr(asoc, paddr);
if (!transport)
goto out;
if (sctp_bind_addr_match(&asoc->base.bind_addr, laddr,
sctp_sk(asoc->base.sk)))
goto out;
}
transport = NULL;
out:
return transport;
}
static void sctp_assoc_bh_rcv(struct work_struct *work)
{
struct sctp_association *asoc =
container_of(work, struct sctp_association,
base.inqueue.immediate);
struct net *net = sock_net(asoc->base.sk);
struct sctp_endpoint *ep;
struct sctp_chunk *chunk;
struct sctp_inq *inqueue;
int state;
sctp_subtype_t subtype;
int error = 0;
ep = asoc->ep;
inqueue = &asoc->base.inqueue;
sctp_association_hold(asoc);
while (NULL != (chunk = sctp_inq_pop(inqueue))) {
state = asoc->state;
subtype = SCTP_ST_CHUNK(chunk->chunk_hdr->type);
if (sctp_auth_recv_cid(subtype.chunk, asoc) && !chunk->auth)
continue;
if (sctp_chunk_is_data(chunk))
asoc->peer.last_data_from = chunk->transport;
else {
SCTP_INC_STATS(net, SCTP_MIB_INCTRLCHUNKS);
asoc->stats.ictrlchunks++;
if (chunk->chunk_hdr->type == SCTP_CID_SACK)
asoc->stats.isacks++;
}
if (chunk->transport)
chunk->transport->last_time_heard = ktime_get();
error = sctp_do_sm(net, SCTP_EVENT_T_CHUNK, subtype,
state, ep, asoc, chunk, GFP_ATOMIC);
if (asoc->base.dead)
break;
if (error && chunk)
chunk->pdiscard = 1;
}
sctp_association_put(asoc);
}
void sctp_assoc_migrate(struct sctp_association *assoc, struct sock *newsk)
{
struct sctp_sock *newsp = sctp_sk(newsk);
struct sock *oldsk = assoc->base.sk;
list_del_init(&assoc->asocs);
if (sctp_style(oldsk, TCP))
oldsk->sk_ack_backlog--;
sctp_endpoint_put(assoc->ep);
sock_put(assoc->base.sk);
assoc->ep = newsp->ep;
sctp_endpoint_hold(assoc->ep);
assoc->base.sk = newsk;
sock_hold(assoc->base.sk);
sctp_endpoint_add_asoc(newsp->ep, assoc);
}
void sctp_assoc_update(struct sctp_association *asoc,
struct sctp_association *new)
{
struct sctp_transport *trans;
struct list_head *pos, *temp;
asoc->c = new->c;
asoc->peer.rwnd = new->peer.rwnd;
asoc->peer.sack_needed = new->peer.sack_needed;
asoc->peer.auth_capable = new->peer.auth_capable;
asoc->peer.i = new->peer.i;
sctp_tsnmap_init(&asoc->peer.tsn_map, SCTP_TSN_MAP_INITIAL,
asoc->peer.i.initial_tsn, GFP_ATOMIC);
list_for_each_safe(pos, temp, &asoc->peer.transport_addr_list) {
trans = list_entry(pos, struct sctp_transport, transports);
if (!sctp_assoc_lookup_paddr(new, &trans->ipaddr)) {
sctp_assoc_rm_peer(asoc, trans);
continue;
}
if (asoc->state >= SCTP_STATE_ESTABLISHED)
sctp_transport_reset(trans);
}
if (asoc->state >= SCTP_STATE_ESTABLISHED) {
asoc->next_tsn = new->next_tsn;
asoc->ctsn_ack_point = new->ctsn_ack_point;
asoc->adv_peer_ack_point = new->adv_peer_ack_point;
sctp_ssnmap_clear(asoc->ssnmap);
sctp_ulpq_flush(&asoc->ulpq);
asoc->overall_error_count = 0;
} else {
list_for_each_entry(trans, &new->peer.transport_addr_list,
transports) {
if (!sctp_assoc_lookup_paddr(asoc, &trans->ipaddr))
sctp_assoc_add_peer(asoc, &trans->ipaddr,
GFP_ATOMIC, trans->state);
}
asoc->ctsn_ack_point = asoc->next_tsn - 1;
asoc->adv_peer_ack_point = asoc->ctsn_ack_point;
if (!asoc->ssnmap) {
asoc->ssnmap = new->ssnmap;
new->ssnmap = NULL;
}
if (!asoc->assoc_id) {
sctp_assoc_set_id(asoc, GFP_ATOMIC);
}
}
kfree(asoc->peer.peer_random);
asoc->peer.peer_random = new->peer.peer_random;
new->peer.peer_random = NULL;
kfree(asoc->peer.peer_chunks);
asoc->peer.peer_chunks = new->peer.peer_chunks;
new->peer.peer_chunks = NULL;
kfree(asoc->peer.peer_hmacs);
asoc->peer.peer_hmacs = new->peer.peer_hmacs;
new->peer.peer_hmacs = NULL;
sctp_auth_key_put(asoc->asoc_shared_key);
sctp_auth_asoc_init_active_key(asoc, GFP_ATOMIC);
}
static u8 sctp_trans_score(const struct sctp_transport *trans)
{
return sctp_trans_state_to_prio_map[trans->state];
}
static struct sctp_transport *sctp_trans_elect_tie(struct sctp_transport *trans1,
struct sctp_transport *trans2)
{
if (trans1->error_count > trans2->error_count) {
return trans2;
} else if (trans1->error_count == trans2->error_count &&
ktime_after(trans2->last_time_heard,
trans1->last_time_heard)) {
return trans2;
} else {
return trans1;
}
}
static struct sctp_transport *sctp_trans_elect_best(struct sctp_transport *curr,
struct sctp_transport *best)
{
u8 score_curr, score_best;
if (best == NULL)
return curr;
score_curr = sctp_trans_score(curr);
score_best = sctp_trans_score(best);
if (score_curr > score_best)
return curr;
else if (score_curr == score_best)
return sctp_trans_elect_tie(curr, best);
else
return best;
}
void sctp_assoc_update_retran_path(struct sctp_association *asoc)
{
struct sctp_transport *trans = asoc->peer.retran_path;
struct sctp_transport *trans_next = NULL;
if (asoc->peer.transport_count == 1)
return;
if (asoc->peer.active_path == asoc->peer.retran_path &&
asoc->peer.active_path->state == SCTP_ACTIVE)
return;
for (trans = list_next_entry(trans, transports); 1;
trans = list_next_entry(trans, transports)) {
if (&trans->transports == &asoc->peer.transport_addr_list)
continue;
if (trans->state == SCTP_UNCONFIRMED)
continue;
trans_next = sctp_trans_elect_best(trans, trans_next);
if (trans_next->state == SCTP_ACTIVE)
break;
if (trans == asoc->peer.retran_path)
break;
}
asoc->peer.retran_path = trans_next;
pr_debug("%s: association:%p updated new path to addr:%pISpc\n",
__func__, asoc, &asoc->peer.retran_path->ipaddr.sa);
}
static void sctp_select_active_and_retran_path(struct sctp_association *asoc)
{
struct sctp_transport *trans, *trans_pri = NULL, *trans_sec = NULL;
struct sctp_transport *trans_pf = NULL;
list_for_each_entry(trans, &asoc->peer.transport_addr_list,
transports) {
if (trans->state == SCTP_INACTIVE ||
trans->state == SCTP_UNCONFIRMED)
continue;
if (trans->state == SCTP_PF) {
trans_pf = sctp_trans_elect_best(trans, trans_pf);
continue;
}
if (trans_pri == NULL ||
ktime_after(trans->last_time_heard,
trans_pri->last_time_heard)) {
trans_sec = trans_pri;
trans_pri = trans;
} else if (trans_sec == NULL ||
ktime_after(trans->last_time_heard,
trans_sec->last_time_heard)) {
trans_sec = trans;
}
}
if ((asoc->peer.primary_path->state == SCTP_ACTIVE ||
asoc->peer.primary_path->state == SCTP_UNKNOWN) &&
asoc->peer.primary_path != trans_pri) {
trans_sec = trans_pri;
trans_pri = asoc->peer.primary_path;
}
if (trans_sec == NULL)
trans_sec = trans_pri;
if (trans_pri == NULL) {
trans_pri = sctp_trans_elect_best(asoc->peer.primary_path,
asoc->peer.retran_path);
trans_pri = sctp_trans_elect_best(trans_pri, trans_pf);
trans_sec = asoc->peer.primary_path;
}
asoc->peer.active_path = trans_pri;
asoc->peer.retran_path = trans_sec;
}
struct sctp_transport *
sctp_assoc_choose_alter_transport(struct sctp_association *asoc,
struct sctp_transport *last_sent_to)
{
if (last_sent_to == NULL) {
return asoc->peer.active_path;
} else {
if (last_sent_to == asoc->peer.retran_path)
sctp_assoc_update_retran_path(asoc);
return asoc->peer.retran_path;
}
}
void sctp_assoc_sync_pmtu(struct sock *sk, struct sctp_association *asoc)
{
struct sctp_transport *t;
__u32 pmtu = 0;
if (!asoc)
return;
list_for_each_entry(t, &asoc->peer.transport_addr_list,
transports) {
if (t->pmtu_pending && t->dst) {
sctp_transport_update_pmtu(sk, t, dst_mtu(t->dst));
t->pmtu_pending = 0;
}
if (!pmtu || (t->pathmtu < pmtu))
pmtu = t->pathmtu;
}
if (pmtu) {
asoc->pathmtu = pmtu;
asoc->frag_point = sctp_frag_point(asoc, pmtu);
}
pr_debug("%s: asoc:%p, pmtu:%d, frag_point:%d\n", __func__, asoc,
asoc->pathmtu, asoc->frag_point);
}
static inline bool sctp_peer_needs_update(struct sctp_association *asoc)
{
struct net *net = sock_net(asoc->base.sk);
switch (asoc->state) {
case SCTP_STATE_ESTABLISHED:
case SCTP_STATE_SHUTDOWN_PENDING:
case SCTP_STATE_SHUTDOWN_RECEIVED:
case SCTP_STATE_SHUTDOWN_SENT:
if ((asoc->rwnd > asoc->a_rwnd) &&
((asoc->rwnd - asoc->a_rwnd) >= max_t(__u32,
(asoc->base.sk->sk_rcvbuf >> net->sctp.rwnd_upd_shift),
asoc->pathmtu)))
return true;
break;
default:
break;
}
return false;
}
void sctp_assoc_rwnd_increase(struct sctp_association *asoc, unsigned int len)
{
struct sctp_chunk *sack;
struct timer_list *timer;
if (asoc->rwnd_over) {
if (asoc->rwnd_over >= len) {
asoc->rwnd_over -= len;
} else {
asoc->rwnd += (len - asoc->rwnd_over);
asoc->rwnd_over = 0;
}
} else {
asoc->rwnd += len;
}
if (asoc->rwnd_press && asoc->rwnd >= asoc->rwnd_press) {
int change = min(asoc->pathmtu, asoc->rwnd_press);
asoc->rwnd += change;
asoc->rwnd_press -= change;
}
pr_debug("%s: asoc:%p rwnd increased by %d to (%u, %u) - %u\n",
__func__, asoc, len, asoc->rwnd, asoc->rwnd_over,
asoc->a_rwnd);
if (sctp_peer_needs_update(asoc)) {
asoc->a_rwnd = asoc->rwnd;
pr_debug("%s: sending window update SACK- asoc:%p rwnd:%u "
"a_rwnd:%u\n", __func__, asoc, asoc->rwnd,
asoc->a_rwnd);
sack = sctp_make_sack(asoc);
if (!sack)
return;
asoc->peer.sack_needed = 0;
sctp_outq_tail(&asoc->outqueue, sack);
timer = &asoc->timers[SCTP_EVENT_TIMEOUT_SACK];
if (del_timer(timer))
sctp_association_put(asoc);
}
}
void sctp_assoc_rwnd_decrease(struct sctp_association *asoc, unsigned int len)
{
int rx_count;
int over = 0;
if (unlikely(!asoc->rwnd || asoc->rwnd_over))
pr_debug("%s: association:%p has asoc->rwnd:%u, "
"asoc->rwnd_over:%u!\n", __func__, asoc,
asoc->rwnd, asoc->rwnd_over);
if (asoc->ep->rcvbuf_policy)
rx_count = atomic_read(&asoc->rmem_alloc);
else
rx_count = atomic_read(&asoc->base.sk->sk_rmem_alloc);
if (rx_count >= asoc->base.sk->sk_rcvbuf)
over = 1;
if (asoc->rwnd >= len) {
asoc->rwnd -= len;
if (over) {
asoc->rwnd_press += asoc->rwnd;
asoc->rwnd = 0;
}
} else {
asoc->rwnd_over = len - asoc->rwnd;
asoc->rwnd = 0;
}
pr_debug("%s: asoc:%p rwnd decreased by %d to (%u, %u, %u)\n",
__func__, asoc, len, asoc->rwnd, asoc->rwnd_over,
asoc->rwnd_press);
}
int sctp_assoc_set_bind_addr_from_ep(struct sctp_association *asoc,
sctp_scope_t scope, gfp_t gfp)
{
int flags;
flags = (PF_INET6 == asoc->base.sk->sk_family) ? SCTP_ADDR6_ALLOWED : 0;
if (asoc->peer.ipv4_address)
flags |= SCTP_ADDR4_PEERSUPP;
if (asoc->peer.ipv6_address)
flags |= SCTP_ADDR6_PEERSUPP;
return sctp_bind_addr_copy(sock_net(asoc->base.sk),
&asoc->base.bind_addr,
&asoc->ep->base.bind_addr,
scope, gfp, flags);
}
int sctp_assoc_set_bind_addr_from_cookie(struct sctp_association *asoc,
struct sctp_cookie *cookie,
gfp_t gfp)
{
int var_size2 = ntohs(cookie->peer_init->chunk_hdr.length);
int var_size3 = cookie->raw_addr_list_len;
__u8 *raw = (__u8 *)cookie->peer_init + var_size2;
return sctp_raw_to_bind_addrs(&asoc->base.bind_addr, raw, var_size3,
asoc->ep->base.bind_addr.port, gfp);
}
int sctp_assoc_lookup_laddr(struct sctp_association *asoc,
const union sctp_addr *laddr)
{
int found = 0;
if ((asoc->base.bind_addr.port == ntohs(laddr->v4.sin_port)) &&
sctp_bind_addr_match(&asoc->base.bind_addr, laddr,
sctp_sk(asoc->base.sk)))
found = 1;
return found;
}
int sctp_assoc_set_id(struct sctp_association *asoc, gfp_t gfp)
{
bool preload = !!(gfp & __GFP_WAIT);
int ret;
if (asoc->assoc_id)
return 0;
if (preload)
idr_preload(gfp);
spin_lock_bh(&sctp_assocs_id_lock);
ret = idr_alloc_cyclic(&sctp_assocs_id, asoc, 1, 0, GFP_NOWAIT);
spin_unlock_bh(&sctp_assocs_id_lock);
if (preload)
idr_preload_end();
if (ret < 0)
return ret;
asoc->assoc_id = (sctp_assoc_t)ret;
return 0;
}
static void sctp_assoc_free_asconf_queue(struct sctp_association *asoc)
{
struct sctp_chunk *asconf;
struct sctp_chunk *tmp;
list_for_each_entry_safe(asconf, tmp, &asoc->addip_chunk_list, list) {
list_del_init(&asconf->list);
sctp_chunk_free(asconf);
}
}
static void sctp_assoc_free_asconf_acks(struct sctp_association *asoc)
{
struct sctp_chunk *ack;
struct sctp_chunk *tmp;
list_for_each_entry_safe(ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
list_del_init(&ack->transmitted_list);
sctp_chunk_free(ack);
}
}
void sctp_assoc_clean_asconf_ack_cache(const struct sctp_association *asoc)
{
struct sctp_chunk *ack;
struct sctp_chunk *tmp;
list_for_each_entry_safe(ack, tmp, &asoc->asconf_ack_list,
transmitted_list) {
if (ack->subh.addip_hdr->serial ==
htonl(asoc->peer.addip_serial))
break;
list_del_init(&ack->transmitted_list);
sctp_chunk_free(ack);
}
}
struct sctp_chunk *sctp_assoc_lookup_asconf_ack(
const struct sctp_association *asoc,
__be32 serial)
{
struct sctp_chunk *ack;
list_for_each_entry(ack, &asoc->asconf_ack_list, transmitted_list) {
if (ack->subh.addip_hdr->serial == serial) {
sctp_chunk_hold(ack);
return ack;
}
}
return NULL;
}
void sctp_asconf_queue_teardown(struct sctp_association *asoc)
{
sctp_assoc_free_asconf_acks(asoc);
sctp_assoc_free_asconf_queue(asoc);
if (asoc->addip_last_asconf)
sctp_chunk_free(asoc->addip_last_asconf);
}
