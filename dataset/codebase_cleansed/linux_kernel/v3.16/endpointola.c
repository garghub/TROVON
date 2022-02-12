static struct sctp_endpoint *sctp_endpoint_init(struct sctp_endpoint *ep,
struct sock *sk,
gfp_t gfp)
{
struct net *net = sock_net(sk);
struct sctp_hmac_algo_param *auth_hmacs = NULL;
struct sctp_chunks_param *auth_chunks = NULL;
struct sctp_shared_key *null_key;
int err;
ep->digest = kzalloc(SCTP_SIGNATURE_SIZE, gfp);
if (!ep->digest)
return NULL;
ep->auth_enable = net->sctp.auth_enable;
if (ep->auth_enable) {
auth_hmacs = kzalloc(sizeof(sctp_hmac_algo_param_t) +
sizeof(__u16) * SCTP_AUTH_NUM_HMACS, gfp);
if (!auth_hmacs)
goto nomem;
auth_chunks = kzalloc(sizeof(sctp_chunks_param_t) +
SCTP_NUM_CHUNK_TYPES, gfp);
if (!auth_chunks)
goto nomem;
auth_hmacs->param_hdr.type = SCTP_PARAM_HMAC_ALGO;
auth_hmacs->param_hdr.length =
htons(sizeof(sctp_paramhdr_t) + 2);
auth_hmacs->hmac_ids[0] = htons(SCTP_AUTH_HMAC_ID_SHA1);
auth_chunks->param_hdr.type = SCTP_PARAM_CHUNKS;
auth_chunks->param_hdr.length = htons(sizeof(sctp_paramhdr_t));
if (net->sctp.addip_enable) {
auth_chunks->chunks[0] = SCTP_CID_ASCONF;
auth_chunks->chunks[1] = SCTP_CID_ASCONF_ACK;
auth_chunks->param_hdr.length =
htons(sizeof(sctp_paramhdr_t) + 2);
}
}
ep->base.type = SCTP_EP_TYPE_SOCKET;
atomic_set(&ep->base.refcnt, 1);
ep->base.dead = false;
sctp_inq_init(&ep->base.inqueue);
sctp_inq_set_th_handler(&ep->base.inqueue, sctp_endpoint_bh_rcv);
sctp_bind_addr_init(&ep->base.bind_addr, 0);
ep->base.sk = sk;
sock_hold(ep->base.sk);
INIT_LIST_HEAD(&ep->asocs);
ep->sndbuf_policy = net->sctp.sndbuf_policy;
sk->sk_data_ready = sctp_data_ready;
sk->sk_write_space = sctp_write_space;
sock_set_flag(sk, SOCK_USE_WRITE_QUEUE);
ep->rcvbuf_policy = net->sctp.rcvbuf_policy;
get_random_bytes(ep->secret_key, sizeof(ep->secret_key));
INIT_LIST_HEAD(&ep->endpoint_shared_keys);
null_key = sctp_auth_shkey_create(0, gfp);
if (!null_key)
goto nomem;
list_add(&null_key->key_list, &ep->endpoint_shared_keys);
err = sctp_auth_init_hmacs(ep, gfp);
if (err)
goto nomem_hmacs;
ep->auth_hmacs_list = auth_hmacs;
ep->auth_chunk_list = auth_chunks;
return ep;
nomem_hmacs:
sctp_auth_destroy_keys(&ep->endpoint_shared_keys);
nomem:
kfree(auth_hmacs);
kfree(auth_chunks);
kfree(ep->digest);
return NULL;
}
struct sctp_endpoint *sctp_endpoint_new(struct sock *sk, gfp_t gfp)
{
struct sctp_endpoint *ep;
ep = kzalloc(sizeof(*ep), gfp);
if (!ep)
goto fail;
if (!sctp_endpoint_init(ep, sk, gfp))
goto fail_init;
SCTP_DBG_OBJCNT_INC(ep);
return ep;
fail_init:
kfree(ep);
fail:
return NULL;
}
void sctp_endpoint_add_asoc(struct sctp_endpoint *ep,
struct sctp_association *asoc)
{
struct sock *sk = ep->base.sk;
if (asoc->temp)
return;
list_add_tail(&asoc->asocs, &ep->asocs);
if (sctp_style(sk, TCP) && sctp_sstate(sk, LISTENING))
sk->sk_ack_backlog++;
}
void sctp_endpoint_free(struct sctp_endpoint *ep)
{
ep->base.dead = true;
ep->base.sk->sk_state = SCTP_SS_CLOSED;
sctp_unhash_endpoint(ep);
sctp_endpoint_put(ep);
}
static void sctp_endpoint_destroy(struct sctp_endpoint *ep)
{
struct sock *sk;
if (unlikely(!ep->base.dead)) {
WARN(1, "Attempt to destroy undead endpoint %p!\n", ep);
return;
}
kfree(ep->digest);
sctp_auth_destroy_keys(&ep->endpoint_shared_keys);
kfree(ep->auth_hmacs_list);
kfree(ep->auth_chunk_list);
sctp_auth_destroy_hmacs(ep->auth_hmacs);
sctp_inq_free(&ep->base.inqueue);
sctp_bind_addr_free(&ep->base.bind_addr);
memset(ep->secret_key, 0, sizeof(ep->secret_key));
sk = ep->base.sk;
if (sk != NULL) {
if (sctp_sk(sk)->bind_hash)
sctp_put_port(sk);
sock_put(sk);
}
kfree(ep);
SCTP_DBG_OBJCNT_DEC(ep);
}
void sctp_endpoint_hold(struct sctp_endpoint *ep)
{
atomic_inc(&ep->base.refcnt);
}
void sctp_endpoint_put(struct sctp_endpoint *ep)
{
if (atomic_dec_and_test(&ep->base.refcnt))
sctp_endpoint_destroy(ep);
}
struct sctp_endpoint *sctp_endpoint_is_match(struct sctp_endpoint *ep,
struct net *net,
const union sctp_addr *laddr)
{
struct sctp_endpoint *retval = NULL;
if ((htons(ep->base.bind_addr.port) == laddr->v4.sin_port) &&
net_eq(sock_net(ep->base.sk), net)) {
if (sctp_bind_addr_match(&ep->base.bind_addr, laddr,
sctp_sk(ep->base.sk)))
retval = ep;
}
return retval;
}
static struct sctp_association *__sctp_endpoint_lookup_assoc(
const struct sctp_endpoint *ep,
const union sctp_addr *paddr,
struct sctp_transport **transport)
{
struct sctp_association *asoc = NULL;
struct sctp_association *tmp;
struct sctp_transport *t = NULL;
struct sctp_hashbucket *head;
struct sctp_ep_common *epb;
int hash;
int rport;
*transport = NULL;
if (!ep->base.bind_addr.port)
goto out;
rport = ntohs(paddr->v4.sin_port);
hash = sctp_assoc_hashfn(sock_net(ep->base.sk), ep->base.bind_addr.port,
rport);
head = &sctp_assoc_hashtable[hash];
read_lock(&head->lock);
sctp_for_each_hentry(epb, &head->chain) {
tmp = sctp_assoc(epb);
if (tmp->ep != ep || rport != tmp->peer.port)
continue;
t = sctp_assoc_lookup_paddr(tmp, paddr);
if (t) {
asoc = tmp;
*transport = t;
break;
}
}
read_unlock(&head->lock);
out:
return asoc;
}
struct sctp_association *sctp_endpoint_lookup_assoc(
const struct sctp_endpoint *ep,
const union sctp_addr *paddr,
struct sctp_transport **transport)
{
struct sctp_association *asoc;
local_bh_disable();
asoc = __sctp_endpoint_lookup_assoc(ep, paddr, transport);
local_bh_enable();
return asoc;
}
int sctp_endpoint_is_peeled_off(struct sctp_endpoint *ep,
const union sctp_addr *paddr)
{
struct sctp_sockaddr_entry *addr;
struct sctp_bind_addr *bp;
struct net *net = sock_net(ep->base.sk);
bp = &ep->base.bind_addr;
list_for_each_entry(addr, &bp->address_list, list) {
if (sctp_has_association(net, &addr->a, paddr))
return 1;
}
return 0;
}
static void sctp_endpoint_bh_rcv(struct work_struct *work)
{
struct sctp_endpoint *ep =
container_of(work, struct sctp_endpoint,
base.inqueue.immediate);
struct sctp_association *asoc;
struct sock *sk;
struct net *net;
struct sctp_transport *transport;
struct sctp_chunk *chunk;
struct sctp_inq *inqueue;
sctp_subtype_t subtype;
sctp_state_t state;
int error = 0;
int first_time = 1;
if (ep->base.dead)
return;
asoc = NULL;
inqueue = &ep->base.inqueue;
sk = ep->base.sk;
net = sock_net(sk);
while (NULL != (chunk = sctp_inq_pop(inqueue))) {
subtype = SCTP_ST_CHUNK(chunk->chunk_hdr->type);
if (first_time && (subtype.chunk == SCTP_CID_AUTH)) {
struct sctp_chunkhdr *next_hdr;
next_hdr = sctp_inq_peek(inqueue);
if (!next_hdr)
goto normal;
if (next_hdr->type == SCTP_CID_COOKIE_ECHO) {
chunk->auth_chunk = skb_clone(chunk->skb,
GFP_ATOMIC);
chunk->auth = 1;
continue;
}
}
normal:
if (NULL == chunk->asoc) {
asoc = sctp_endpoint_lookup_assoc(ep,
sctp_source(chunk),
&transport);
chunk->asoc = asoc;
chunk->transport = transport;
}
state = asoc ? asoc->state : SCTP_STATE_CLOSED;
if (sctp_auth_recv_cid(subtype.chunk, asoc) && !chunk->auth)
continue;
if (asoc && sctp_chunk_is_data(chunk))
asoc->peer.last_data_from = chunk->transport;
else {
SCTP_INC_STATS(sock_net(ep->base.sk), SCTP_MIB_INCTRLCHUNKS);
if (asoc)
asoc->stats.ictrlchunks++;
}
if (chunk->transport)
chunk->transport->last_time_heard = ktime_get();
error = sctp_do_sm(net, SCTP_EVENT_T_CHUNK, subtype, state,
ep, asoc, chunk, GFP_ATOMIC);
if (error && chunk)
chunk->pdiscard = 1;
if (!sctp_sk(sk)->ep)
break;
if (first_time)
first_time = 0;
}
}
