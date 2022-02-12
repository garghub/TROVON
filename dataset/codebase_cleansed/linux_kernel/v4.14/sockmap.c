static inline struct smap_psock *smap_psock_sk(const struct sock *sk)
{
return rcu_dereference_sk_user_data(sk);
}
static inline void bpf_compute_data_end_sk_skb(struct sk_buff *skb)
{
TCP_SKB_CB(skb)->bpf.data_end = skb->data + skb_headlen(skb);
}
static int smap_verdict_func(struct smap_psock *psock, struct sk_buff *skb)
{
struct bpf_prog *prog = READ_ONCE(psock->bpf_verdict);
int rc;
if (unlikely(!prog))
return __SK_DROP;
skb_orphan(skb);
TCP_SKB_CB(skb)->bpf.map = NULL;
skb->sk = psock->sock;
bpf_compute_data_end_sk_skb(skb);
preempt_disable();
rc = (*prog->bpf_func)(skb, prog->insnsi);
preempt_enable();
skb->sk = NULL;
return rc == SK_PASS ?
(TCP_SKB_CB(skb)->bpf.map ? __SK_REDIRECT : __SK_PASS) :
__SK_DROP;
}
static void smap_do_verdict(struct smap_psock *psock, struct sk_buff *skb)
{
struct sock *sk;
int rc;
rc = smap_verdict_func(psock, skb);
switch (rc) {
case __SK_REDIRECT:
sk = do_sk_redirect_map(skb);
if (likely(sk)) {
struct smap_psock *peer = smap_psock_sk(sk);
if (likely(peer &&
test_bit(SMAP_TX_RUNNING, &peer->state) &&
!sock_flag(sk, SOCK_DEAD) &&
sock_writeable(sk))) {
skb_set_owner_w(skb, sk);
skb_queue_tail(&peer->rxqueue, skb);
schedule_work(&peer->tx_work);
break;
}
}
case __SK_DROP:
default:
kfree_skb(skb);
}
}
static void smap_report_sk_error(struct smap_psock *psock, int err)
{
struct sock *sk = psock->sock;
sk->sk_err = err;
sk->sk_error_report(sk);
}
static void smap_state_change(struct sock *sk)
{
struct smap_psock_map_entry *e, *tmp;
struct smap_psock *psock;
struct socket_wq *wq;
struct sock *osk;
rcu_read_lock();
switch (sk->sk_state) {
case TCP_SYN_SENT:
case TCP_SYN_RECV:
case TCP_ESTABLISHED:
break;
case TCP_CLOSE_WAIT:
case TCP_CLOSING:
case TCP_LAST_ACK:
case TCP_FIN_WAIT1:
case TCP_FIN_WAIT2:
case TCP_LISTEN:
break;
case TCP_CLOSE:
psock = smap_psock_sk(sk);
if (unlikely(!psock))
break;
write_lock_bh(&sk->sk_callback_lock);
list_for_each_entry_safe(e, tmp, &psock->maps, list) {
osk = cmpxchg(e->entry, sk, NULL);
if (osk == sk) {
list_del(&e->list);
smap_release_sock(psock, sk);
}
}
write_unlock_bh(&sk->sk_callback_lock);
break;
default:
psock = smap_psock_sk(sk);
if (unlikely(!psock))
break;
smap_report_sk_error(psock, EPIPE);
break;
}
wq = rcu_dereference(sk->sk_wq);
if (skwq_has_sleeper(wq))
wake_up_interruptible_all(&wq->wait);
rcu_read_unlock();
}
static void smap_read_sock_strparser(struct strparser *strp,
struct sk_buff *skb)
{
struct smap_psock *psock;
rcu_read_lock();
psock = container_of(strp, struct smap_psock, strp);
smap_do_verdict(psock, skb);
rcu_read_unlock();
}
static void smap_data_ready(struct sock *sk)
{
struct smap_psock *psock;
rcu_read_lock();
psock = smap_psock_sk(sk);
if (likely(psock)) {
write_lock_bh(&sk->sk_callback_lock);
strp_data_ready(&psock->strp);
write_unlock_bh(&sk->sk_callback_lock);
}
rcu_read_unlock();
}
static void smap_tx_work(struct work_struct *w)
{
struct smap_psock *psock;
struct sk_buff *skb;
int rem, off, n;
psock = container_of(w, struct smap_psock, tx_work);
lock_sock(psock->sock);
if (psock->save_skb) {
skb = psock->save_skb;
rem = psock->save_rem;
off = psock->save_off;
psock->save_skb = NULL;
goto start;
}
while ((skb = skb_dequeue(&psock->rxqueue))) {
rem = skb->len;
off = 0;
start:
do {
if (likely(psock->sock->sk_socket))
n = skb_send_sock_locked(psock->sock,
skb, off, rem);
else
n = -EINVAL;
if (n <= 0) {
if (n == -EAGAIN) {
psock->save_skb = skb;
psock->save_rem = rem;
psock->save_off = off;
goto out;
}
smap_report_sk_error(psock, n ? -n : EPIPE);
clear_bit(SMAP_TX_RUNNING, &psock->state);
kfree_skb(skb);
goto out;
}
rem -= n;
off += n;
} while (rem);
kfree_skb(skb);
}
out:
release_sock(psock->sock);
}
static void smap_write_space(struct sock *sk)
{
struct smap_psock *psock;
rcu_read_lock();
psock = smap_psock_sk(sk);
if (likely(psock && test_bit(SMAP_TX_RUNNING, &psock->state)))
schedule_work(&psock->tx_work);
rcu_read_unlock();
}
static void smap_stop_sock(struct smap_psock *psock, struct sock *sk)
{
if (!psock->strp_enabled)
return;
sk->sk_data_ready = psock->save_data_ready;
sk->sk_write_space = psock->save_write_space;
sk->sk_state_change = psock->save_state_change;
psock->save_data_ready = NULL;
psock->save_write_space = NULL;
psock->save_state_change = NULL;
strp_stop(&psock->strp);
psock->strp_enabled = false;
}
static void smap_destroy_psock(struct rcu_head *rcu)
{
struct smap_psock *psock = container_of(rcu,
struct smap_psock, rcu);
schedule_work(&psock->gc_work);
}
static void smap_release_sock(struct smap_psock *psock, struct sock *sock)
{
psock->refcnt--;
if (psock->refcnt)
return;
smap_stop_sock(psock, sock);
clear_bit(SMAP_TX_RUNNING, &psock->state);
rcu_assign_sk_user_data(sock, NULL);
call_rcu_sched(&psock->rcu, smap_destroy_psock);
}
static int smap_parse_func_strparser(struct strparser *strp,
struct sk_buff *skb)
{
struct smap_psock *psock;
struct bpf_prog *prog;
int rc;
rcu_read_lock();
psock = container_of(strp, struct smap_psock, strp);
prog = READ_ONCE(psock->bpf_parse);
if (unlikely(!prog)) {
rcu_read_unlock();
return skb->len;
}
skb->sk = psock->sock;
bpf_compute_data_end_sk_skb(skb);
rc = (*prog->bpf_func)(skb, prog->insnsi);
skb->sk = NULL;
rcu_read_unlock();
return rc;
}
static int smap_read_sock_done(struct strparser *strp, int err)
{
return err;
}
static int smap_init_sock(struct smap_psock *psock,
struct sock *sk)
{
static const struct strp_callbacks cb = {
.rcv_msg = smap_read_sock_strparser,
.parse_msg = smap_parse_func_strparser,
.read_sock_done = smap_read_sock_done,
};
return strp_init(&psock->strp, sk, &cb);
}
static void smap_init_progs(struct smap_psock *psock,
struct bpf_stab *stab,
struct bpf_prog *verdict,
struct bpf_prog *parse)
{
struct bpf_prog *orig_parse, *orig_verdict;
orig_parse = xchg(&psock->bpf_parse, parse);
orig_verdict = xchg(&psock->bpf_verdict, verdict);
if (orig_verdict)
bpf_prog_put(orig_verdict);
if (orig_parse)
bpf_prog_put(orig_parse);
}
static void smap_start_sock(struct smap_psock *psock, struct sock *sk)
{
if (sk->sk_data_ready == smap_data_ready)
return;
psock->save_data_ready = sk->sk_data_ready;
psock->save_write_space = sk->sk_write_space;
psock->save_state_change = sk->sk_state_change;
sk->sk_data_ready = smap_data_ready;
sk->sk_write_space = smap_write_space;
sk->sk_state_change = smap_state_change;
psock->strp_enabled = true;
}
static void sock_map_remove_complete(struct bpf_stab *stab)
{
bpf_map_area_free(stab->sock_map);
kfree(stab);
}
static void smap_gc_work(struct work_struct *w)
{
struct smap_psock_map_entry *e, *tmp;
struct smap_psock *psock;
psock = container_of(w, struct smap_psock, gc_work);
if (psock->strp_enabled)
strp_done(&psock->strp);
cancel_work_sync(&psock->tx_work);
__skb_queue_purge(&psock->rxqueue);
if (psock->bpf_parse)
bpf_prog_put(psock->bpf_parse);
if (psock->bpf_verdict)
bpf_prog_put(psock->bpf_verdict);
list_for_each_entry_safe(e, tmp, &psock->maps, list) {
list_del(&e->list);
kfree(e);
}
sock_put(psock->sock);
kfree(psock);
}
static struct smap_psock *smap_init_psock(struct sock *sock,
struct bpf_stab *stab)
{
struct smap_psock *psock;
psock = kzalloc_node(sizeof(struct smap_psock),
GFP_ATOMIC | __GFP_NOWARN,
stab->map.numa_node);
if (!psock)
return ERR_PTR(-ENOMEM);
psock->sock = sock;
skb_queue_head_init(&psock->rxqueue);
INIT_WORK(&psock->tx_work, smap_tx_work);
INIT_WORK(&psock->gc_work, smap_gc_work);
INIT_LIST_HEAD(&psock->maps);
psock->refcnt = 1;
rcu_assign_sk_user_data(sock, psock);
sock_hold(sock);
return psock;
}
static struct bpf_map *sock_map_alloc(union bpf_attr *attr)
{
struct bpf_stab *stab;
int err = -EINVAL;
u64 cost;
if (!capable(CAP_NET_ADMIN))
return ERR_PTR(-EPERM);
if (attr->max_entries == 0 || attr->key_size != 4 ||
attr->value_size != 4 || attr->map_flags & ~BPF_F_NUMA_NODE)
return ERR_PTR(-EINVAL);
if (attr->value_size > KMALLOC_MAX_SIZE)
return ERR_PTR(-E2BIG);
stab = kzalloc(sizeof(*stab), GFP_USER);
if (!stab)
return ERR_PTR(-ENOMEM);
stab->map.map_type = attr->map_type;
stab->map.key_size = attr->key_size;
stab->map.value_size = attr->value_size;
stab->map.max_entries = attr->max_entries;
stab->map.map_flags = attr->map_flags;
stab->map.numa_node = bpf_map_attr_numa_node(attr);
cost = (u64) stab->map.max_entries * sizeof(struct sock *);
if (cost >= U32_MAX - PAGE_SIZE)
goto free_stab;
stab->map.pages = round_up(cost, PAGE_SIZE) >> PAGE_SHIFT;
err = bpf_map_precharge_memlock(stab->map.pages);
if (err)
goto free_stab;
err = -ENOMEM;
stab->sock_map = bpf_map_area_alloc(stab->map.max_entries *
sizeof(struct sock *),
stab->map.numa_node);
if (!stab->sock_map)
goto free_stab;
return &stab->map;
free_stab:
kfree(stab);
return ERR_PTR(err);
}
static void smap_list_remove(struct smap_psock *psock, struct sock **entry)
{
struct smap_psock_map_entry *e, *tmp;
list_for_each_entry_safe(e, tmp, &psock->maps, list) {
if (e->entry == entry) {
list_del(&e->list);
break;
}
}
}
static void sock_map_free(struct bpf_map *map)
{
struct bpf_stab *stab = container_of(map, struct bpf_stab, map);
int i;
synchronize_rcu();
rcu_read_lock();
for (i = 0; i < stab->map.max_entries; i++) {
struct smap_psock *psock;
struct sock *sock;
sock = xchg(&stab->sock_map[i], NULL);
if (!sock)
continue;
write_lock_bh(&sock->sk_callback_lock);
psock = smap_psock_sk(sock);
smap_list_remove(psock, &stab->sock_map[i]);
smap_release_sock(psock, sock);
write_unlock_bh(&sock->sk_callback_lock);
}
rcu_read_unlock();
if (stab->bpf_verdict)
bpf_prog_put(stab->bpf_verdict);
if (stab->bpf_parse)
bpf_prog_put(stab->bpf_parse);
sock_map_remove_complete(stab);
}
static int sock_map_get_next_key(struct bpf_map *map, void *key, void *next_key)
{
struct bpf_stab *stab = container_of(map, struct bpf_stab, map);
u32 i = key ? *(u32 *)key : U32_MAX;
u32 *next = (u32 *)next_key;
if (i >= stab->map.max_entries) {
*next = 0;
return 0;
}
if (i == stab->map.max_entries - 1)
return -ENOENT;
*next = i + 1;
return 0;
}
struct sock *__sock_map_lookup_elem(struct bpf_map *map, u32 key)
{
struct bpf_stab *stab = container_of(map, struct bpf_stab, map);
if (key >= map->max_entries)
return NULL;
return READ_ONCE(stab->sock_map[key]);
}
static int sock_map_delete_elem(struct bpf_map *map, void *key)
{
struct bpf_stab *stab = container_of(map, struct bpf_stab, map);
struct smap_psock *psock;
int k = *(u32 *)key;
struct sock *sock;
if (k >= map->max_entries)
return -EINVAL;
sock = xchg(&stab->sock_map[k], NULL);
if (!sock)
return -EINVAL;
write_lock_bh(&sock->sk_callback_lock);
psock = smap_psock_sk(sock);
if (!psock)
goto out;
if (psock->bpf_parse)
smap_stop_sock(psock, sock);
smap_list_remove(psock, &stab->sock_map[k]);
smap_release_sock(psock, sock);
out:
write_unlock_bh(&sock->sk_callback_lock);
return 0;
}
static int sock_map_ctx_update_elem(struct bpf_sock_ops_kern *skops,
struct bpf_map *map,
void *key, u64 flags)
{
struct bpf_stab *stab = container_of(map, struct bpf_stab, map);
struct smap_psock_map_entry *e = NULL;
struct bpf_prog *verdict, *parse;
struct sock *osock, *sock;
struct smap_psock *psock;
u32 i = *(u32 *)key;
int err;
if (unlikely(flags > BPF_EXIST))
return -EINVAL;
if (unlikely(i >= stab->map.max_entries))
return -E2BIG;
sock = READ_ONCE(stab->sock_map[i]);
if (flags == BPF_EXIST && !sock)
return -ENOENT;
else if (flags == BPF_NOEXIST && sock)
return -EEXIST;
sock = skops->sk;
verdict = READ_ONCE(stab->bpf_verdict);
parse = READ_ONCE(stab->bpf_parse);
if (parse && verdict) {
verdict = bpf_prog_inc_not_zero(stab->bpf_verdict);
if (IS_ERR(verdict))
return PTR_ERR(verdict);
parse = bpf_prog_inc_not_zero(stab->bpf_parse);
if (IS_ERR(parse)) {
bpf_prog_put(verdict);
return PTR_ERR(parse);
}
}
write_lock_bh(&sock->sk_callback_lock);
psock = smap_psock_sk(sock);
if (psock) {
if (READ_ONCE(psock->bpf_parse) && parse) {
err = -EBUSY;
goto out_progs;
}
psock->refcnt++;
} else {
psock = smap_init_psock(sock, stab);
if (IS_ERR(psock)) {
err = PTR_ERR(psock);
goto out_progs;
}
set_bit(SMAP_TX_RUNNING, &psock->state);
}
e = kzalloc(sizeof(*e), GFP_ATOMIC | __GFP_NOWARN);
if (!e) {
err = -ENOMEM;
goto out_progs;
}
e->entry = &stab->sock_map[i];
if (parse && verdict && !psock->strp_enabled) {
err = smap_init_sock(psock, sock);
if (err)
goto out_free;
smap_init_progs(psock, stab, verdict, parse);
smap_start_sock(psock, sock);
}
list_add_tail(&e->list, &psock->maps);
write_unlock_bh(&sock->sk_callback_lock);
osock = xchg(&stab->sock_map[i], sock);
if (osock) {
struct smap_psock *opsock = smap_psock_sk(osock);
write_lock_bh(&osock->sk_callback_lock);
if (osock != sock && parse)
smap_stop_sock(opsock, osock);
smap_list_remove(opsock, &stab->sock_map[i]);
smap_release_sock(opsock, osock);
write_unlock_bh(&osock->sk_callback_lock);
}
return 0;
out_free:
smap_release_sock(psock, sock);
out_progs:
if (verdict)
bpf_prog_put(verdict);
if (parse)
bpf_prog_put(parse);
write_unlock_bh(&sock->sk_callback_lock);
kfree(e);
return err;
}
int sock_map_prog(struct bpf_map *map, struct bpf_prog *prog, u32 type)
{
struct bpf_stab *stab = container_of(map, struct bpf_stab, map);
struct bpf_prog *orig;
if (unlikely(map->map_type != BPF_MAP_TYPE_SOCKMAP))
return -EINVAL;
switch (type) {
case BPF_SK_SKB_STREAM_PARSER:
orig = xchg(&stab->bpf_parse, prog);
break;
case BPF_SK_SKB_STREAM_VERDICT:
orig = xchg(&stab->bpf_verdict, prog);
break;
default:
return -EOPNOTSUPP;
}
if (orig)
bpf_prog_put(orig);
return 0;
}
static void *sock_map_lookup(struct bpf_map *map, void *key)
{
return NULL;
}
static int sock_map_update_elem(struct bpf_map *map,
void *key, void *value, u64 flags)
{
struct bpf_sock_ops_kern skops;
u32 fd = *(u32 *)value;
struct socket *socket;
int err;
socket = sockfd_lookup(fd, &err);
if (!socket)
return err;
skops.sk = socket->sk;
if (!skops.sk) {
fput(socket->file);
return -EINVAL;
}
if (skops.sk->sk_type != SOCK_STREAM ||
skops.sk->sk_protocol != IPPROTO_TCP) {
fput(socket->file);
return -EOPNOTSUPP;
}
err = sock_map_ctx_update_elem(&skops, map, key, flags);
fput(socket->file);
return err;
}
