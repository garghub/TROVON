struct rds_sock *rds_find_bound(__be32 addr, __be16 port)
{
u64 key = ((u64)addr << 32) | port;
struct rds_sock *rs;
rs = rhashtable_lookup_fast(&bind_hash_table, &key, ht_parms);
if (rs && !sock_flag(rds_rs_to_sk(rs), SOCK_DEAD))
rds_sock_addref(rs);
else
rs = NULL;
rdsdebug("returning rs %p for %pI4:%u\n", rs, &addr,
ntohs(port));
return rs;
}
static int rds_add_bound(struct rds_sock *rs, __be32 addr, __be16 *port)
{
int ret = -EADDRINUSE;
u16 rover, last;
u64 key;
if (*port != 0) {
rover = be16_to_cpu(*port);
if (rover == RDS_FLAG_PROBE_PORT)
return -EINVAL;
last = rover;
} else {
rover = max_t(u16, prandom_u32(), 2);
last = rover - 1;
}
do {
if (rover == 0)
rover++;
if (rover == RDS_FLAG_PROBE_PORT)
continue;
key = ((u64)addr << 32) | cpu_to_be16(rover);
if (rhashtable_lookup_fast(&bind_hash_table, &key, ht_parms))
continue;
rs->rs_bound_key = key;
rs->rs_bound_addr = addr;
net_get_random_once(&rs->rs_hash_initval,
sizeof(rs->rs_hash_initval));
rs->rs_bound_port = cpu_to_be16(rover);
rs->rs_bound_node.next = NULL;
rds_sock_addref(rs);
if (!rhashtable_insert_fast(&bind_hash_table,
&rs->rs_bound_node, ht_parms)) {
*port = rs->rs_bound_port;
ret = 0;
rdsdebug("rs %p binding to %pI4:%d\n",
rs, &addr, (int)ntohs(*port));
break;
} else {
rds_sock_put(rs);
ret = -ENOMEM;
break;
}
} while (rover++ != last);
return ret;
}
void rds_remove_bound(struct rds_sock *rs)
{
if (!rs->rs_bound_addr)
return;
rdsdebug("rs %p unbinding from %pI4:%d\n",
rs, &rs->rs_bound_addr,
ntohs(rs->rs_bound_port));
rhashtable_remove_fast(&bind_hash_table, &rs->rs_bound_node, ht_parms);
rds_sock_put(rs);
rs->rs_bound_addr = 0;
}
int rds_bind(struct socket *sock, struct sockaddr *uaddr, int addr_len)
{
struct sock *sk = sock->sk;
struct sockaddr_in *sin = (struct sockaddr_in *)uaddr;
struct rds_sock *rs = rds_sk_to_rs(sk);
struct rds_transport *trans;
int ret = 0;
lock_sock(sk);
if (addr_len != sizeof(struct sockaddr_in) ||
sin->sin_family != AF_INET ||
rs->rs_bound_addr ||
sin->sin_addr.s_addr == htonl(INADDR_ANY)) {
ret = -EINVAL;
goto out;
}
ret = rds_add_bound(rs, sin->sin_addr.s_addr, &sin->sin_port);
if (ret)
goto out;
if (rs->rs_transport) {
trans = rs->rs_transport;
if (trans->laddr_check(sock_net(sock->sk),
sin->sin_addr.s_addr) != 0) {
ret = -ENOPROTOOPT;
rds_remove_bound(rs);
} else {
ret = 0;
}
goto out;
}
trans = rds_trans_get_preferred(sock_net(sock->sk),
sin->sin_addr.s_addr);
if (!trans) {
ret = -EADDRNOTAVAIL;
rds_remove_bound(rs);
pr_info_ratelimited("RDS: %s could not find a transport for %pI4, load rds_tcp or rds_rdma?\n",
__func__, &sin->sin_addr.s_addr);
goto out;
}
rs->rs_transport = trans;
ret = 0;
out:
release_sock(sk);
return ret;
}
void rds_bind_lock_destroy(void)
{
rhashtable_destroy(&bind_hash_table);
}
int rds_bind_lock_init(void)
{
return rhashtable_init(&bind_hash_table, &ht_parms);
}
