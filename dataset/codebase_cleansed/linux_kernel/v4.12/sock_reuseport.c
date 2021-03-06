static struct sock_reuseport *__reuseport_alloc(unsigned int max_socks)
{
unsigned int size = sizeof(struct sock_reuseport) +
sizeof(struct sock *) * max_socks;
struct sock_reuseport *reuse = kzalloc(size, GFP_ATOMIC);
if (!reuse)
return NULL;
reuse->max_socks = max_socks;
RCU_INIT_POINTER(reuse->prog, NULL);
return reuse;
}
int reuseport_alloc(struct sock *sk)
{
struct sock_reuseport *reuse;
spin_lock_bh(&reuseport_lock);
WARN_ONCE(rcu_dereference_protected(sk->sk_reuseport_cb,
lockdep_is_held(&reuseport_lock)),
"multiple allocations for the same socket");
reuse = __reuseport_alloc(INIT_SOCKS);
if (!reuse) {
spin_unlock_bh(&reuseport_lock);
return -ENOMEM;
}
reuse->socks[0] = sk;
reuse->num_socks = 1;
rcu_assign_pointer(sk->sk_reuseport_cb, reuse);
spin_unlock_bh(&reuseport_lock);
return 0;
}
static struct sock_reuseport *reuseport_grow(struct sock_reuseport *reuse)
{
struct sock_reuseport *more_reuse;
u32 more_socks_size, i;
more_socks_size = reuse->max_socks * 2U;
if (more_socks_size > U16_MAX)
return NULL;
more_reuse = __reuseport_alloc(more_socks_size);
if (!more_reuse)
return NULL;
more_reuse->max_socks = more_socks_size;
more_reuse->num_socks = reuse->num_socks;
more_reuse->prog = reuse->prog;
memcpy(more_reuse->socks, reuse->socks,
reuse->num_socks * sizeof(struct sock *));
for (i = 0; i < reuse->num_socks; ++i)
rcu_assign_pointer(reuse->socks[i]->sk_reuseport_cb,
more_reuse);
kfree_rcu(reuse, rcu);
return more_reuse;
}
int reuseport_add_sock(struct sock *sk, struct sock *sk2)
{
struct sock_reuseport *reuse;
if (!rcu_access_pointer(sk2->sk_reuseport_cb)) {
int err = reuseport_alloc(sk2);
if (err)
return err;
}
spin_lock_bh(&reuseport_lock);
reuse = rcu_dereference_protected(sk2->sk_reuseport_cb,
lockdep_is_held(&reuseport_lock)),
WARN_ONCE(rcu_dereference_protected(sk->sk_reuseport_cb,
lockdep_is_held(&reuseport_lock)),
"socket already in reuseport group");
if (reuse->num_socks == reuse->max_socks) {
reuse = reuseport_grow(reuse);
if (!reuse) {
spin_unlock_bh(&reuseport_lock);
return -ENOMEM;
}
}
reuse->socks[reuse->num_socks] = sk;
smp_wmb();
reuse->num_socks++;
rcu_assign_pointer(sk->sk_reuseport_cb, reuse);
spin_unlock_bh(&reuseport_lock);
return 0;
}
static void reuseport_free_rcu(struct rcu_head *head)
{
struct sock_reuseport *reuse;
reuse = container_of(head, struct sock_reuseport, rcu);
if (reuse->prog)
bpf_prog_destroy(reuse->prog);
kfree(reuse);
}
void reuseport_detach_sock(struct sock *sk)
{
struct sock_reuseport *reuse;
int i;
spin_lock_bh(&reuseport_lock);
reuse = rcu_dereference_protected(sk->sk_reuseport_cb,
lockdep_is_held(&reuseport_lock));
rcu_assign_pointer(sk->sk_reuseport_cb, NULL);
for (i = 0; i < reuse->num_socks; i++) {
if (reuse->socks[i] == sk) {
reuse->socks[i] = reuse->socks[reuse->num_socks - 1];
reuse->num_socks--;
if (reuse->num_socks == 0)
call_rcu(&reuse->rcu, reuseport_free_rcu);
break;
}
}
spin_unlock_bh(&reuseport_lock);
}
static struct sock *run_bpf(struct sock_reuseport *reuse, u16 socks,
struct bpf_prog *prog, struct sk_buff *skb,
int hdr_len)
{
struct sk_buff *nskb = NULL;
u32 index;
if (skb_shared(skb)) {
nskb = skb_clone(skb, GFP_ATOMIC);
if (!nskb)
return NULL;
skb = nskb;
}
if (!pskb_pull(skb, hdr_len)) {
kfree_skb(nskb);
return NULL;
}
index = bpf_prog_run_save_cb(prog, skb);
__skb_push(skb, hdr_len);
consume_skb(nskb);
if (index >= socks)
return NULL;
return reuse->socks[index];
}
struct sock *reuseport_select_sock(struct sock *sk,
u32 hash,
struct sk_buff *skb,
int hdr_len)
{
struct sock_reuseport *reuse;
struct bpf_prog *prog;
struct sock *sk2 = NULL;
u16 socks;
rcu_read_lock();
reuse = rcu_dereference(sk->sk_reuseport_cb);
if (!reuse)
goto out;
prog = rcu_dereference(reuse->prog);
socks = READ_ONCE(reuse->num_socks);
if (likely(socks)) {
smp_rmb();
if (prog && skb)
sk2 = run_bpf(reuse, socks, prog, skb, hdr_len);
else
sk2 = reuse->socks[reciprocal_scale(hash, socks)];
}
out:
rcu_read_unlock();
return sk2;
}
struct bpf_prog *
reuseport_attach_prog(struct sock *sk, struct bpf_prog *prog)
{
struct sock_reuseport *reuse;
struct bpf_prog *old_prog;
spin_lock_bh(&reuseport_lock);
reuse = rcu_dereference_protected(sk->sk_reuseport_cb,
lockdep_is_held(&reuseport_lock));
old_prog = rcu_dereference_protected(reuse->prog,
lockdep_is_held(&reuseport_lock));
rcu_assign_pointer(reuse->prog, prog);
spin_unlock_bh(&reuseport_lock);
return old_prog;
}
