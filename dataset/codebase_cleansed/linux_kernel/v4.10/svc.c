static int
param_set_pool_mode(const char *val, struct kernel_param *kp)
{
int *ip = (int *)kp->arg;
struct svc_pool_map *m = &svc_pool_map;
int err;
mutex_lock(&svc_pool_map_mutex);
err = -EBUSY;
if (m->count)
goto out;
err = 0;
if (!strncmp(val, "auto", 4))
*ip = SVC_POOL_AUTO;
else if (!strncmp(val, "global", 6))
*ip = SVC_POOL_GLOBAL;
else if (!strncmp(val, "percpu", 6))
*ip = SVC_POOL_PERCPU;
else if (!strncmp(val, "pernode", 7))
*ip = SVC_POOL_PERNODE;
else
err = -EINVAL;
out:
mutex_unlock(&svc_pool_map_mutex);
return err;
}
static int
param_get_pool_mode(char *buf, struct kernel_param *kp)
{
int *ip = (int *)kp->arg;
switch (*ip)
{
case SVC_POOL_AUTO:
return strlcpy(buf, "auto", 20);
case SVC_POOL_GLOBAL:
return strlcpy(buf, "global", 20);
case SVC_POOL_PERCPU:
return strlcpy(buf, "percpu", 20);
case SVC_POOL_PERNODE:
return strlcpy(buf, "pernode", 20);
default:
return sprintf(buf, "%d", *ip);
}
}
static int
svc_pool_map_choose_mode(void)
{
unsigned int node;
if (nr_online_nodes > 1) {
return SVC_POOL_PERNODE;
}
node = first_online_node;
if (nr_cpus_node(node) > 2) {
return SVC_POOL_PERCPU;
}
return SVC_POOL_GLOBAL;
}
static int
svc_pool_map_alloc_arrays(struct svc_pool_map *m, unsigned int maxpools)
{
m->to_pool = kcalloc(maxpools, sizeof(unsigned int), GFP_KERNEL);
if (!m->to_pool)
goto fail;
m->pool_to = kcalloc(maxpools, sizeof(unsigned int), GFP_KERNEL);
if (!m->pool_to)
goto fail_free;
return 0;
fail_free:
kfree(m->to_pool);
m->to_pool = NULL;
fail:
return -ENOMEM;
}
static int
svc_pool_map_init_percpu(struct svc_pool_map *m)
{
unsigned int maxpools = nr_cpu_ids;
unsigned int pidx = 0;
unsigned int cpu;
int err;
err = svc_pool_map_alloc_arrays(m, maxpools);
if (err)
return err;
for_each_online_cpu(cpu) {
BUG_ON(pidx >= maxpools);
m->to_pool[cpu] = pidx;
m->pool_to[pidx] = cpu;
pidx++;
}
return pidx;
}
static int
svc_pool_map_init_pernode(struct svc_pool_map *m)
{
unsigned int maxpools = nr_node_ids;
unsigned int pidx = 0;
unsigned int node;
int err;
err = svc_pool_map_alloc_arrays(m, maxpools);
if (err)
return err;
for_each_node_with_cpus(node) {
BUG_ON(pidx > maxpools);
m->to_pool[node] = pidx;
m->pool_to[pidx] = node;
pidx++;
}
return pidx;
}
unsigned int
svc_pool_map_get(void)
{
struct svc_pool_map *m = &svc_pool_map;
int npools = -1;
mutex_lock(&svc_pool_map_mutex);
if (m->count++) {
mutex_unlock(&svc_pool_map_mutex);
return m->npools;
}
if (m->mode == SVC_POOL_AUTO)
m->mode = svc_pool_map_choose_mode();
switch (m->mode) {
case SVC_POOL_PERCPU:
npools = svc_pool_map_init_percpu(m);
break;
case SVC_POOL_PERNODE:
npools = svc_pool_map_init_pernode(m);
break;
}
if (npools < 0) {
npools = 1;
m->mode = SVC_POOL_GLOBAL;
}
m->npools = npools;
mutex_unlock(&svc_pool_map_mutex);
return m->npools;
}
void
svc_pool_map_put(void)
{
struct svc_pool_map *m = &svc_pool_map;
mutex_lock(&svc_pool_map_mutex);
if (!--m->count) {
kfree(m->to_pool);
m->to_pool = NULL;
kfree(m->pool_to);
m->pool_to = NULL;
m->npools = 0;
}
mutex_unlock(&svc_pool_map_mutex);
}
static int svc_pool_map_get_node(unsigned int pidx)
{
const struct svc_pool_map *m = &svc_pool_map;
if (m->count) {
if (m->mode == SVC_POOL_PERCPU)
return cpu_to_node(m->pool_to[pidx]);
if (m->mode == SVC_POOL_PERNODE)
return m->pool_to[pidx];
}
return NUMA_NO_NODE;
}
static inline void
svc_pool_map_set_cpumask(struct task_struct *task, unsigned int pidx)
{
struct svc_pool_map *m = &svc_pool_map;
unsigned int node = m->pool_to[pidx];
WARN_ON_ONCE(m->count == 0);
if (m->count == 0)
return;
switch (m->mode) {
case SVC_POOL_PERCPU:
{
set_cpus_allowed_ptr(task, cpumask_of(node));
break;
}
case SVC_POOL_PERNODE:
{
set_cpus_allowed_ptr(task, cpumask_of_node(node));
break;
}
}
}
struct svc_pool *
svc_pool_for_cpu(struct svc_serv *serv, int cpu)
{
struct svc_pool_map *m = &svc_pool_map;
unsigned int pidx = 0;
if (svc_serv_is_pooled(serv)) {
switch (m->mode) {
case SVC_POOL_PERCPU:
pidx = m->to_pool[cpu];
break;
case SVC_POOL_PERNODE:
pidx = m->to_pool[cpu_to_node(cpu)];
break;
}
}
return &serv->sv_pools[pidx % serv->sv_nrpools];
}
int svc_rpcb_setup(struct svc_serv *serv, struct net *net)
{
int err;
err = rpcb_create_local(net);
if (err)
return err;
svc_unregister(serv, net);
return 0;
}
void svc_rpcb_cleanup(struct svc_serv *serv, struct net *net)
{
svc_unregister(serv, net);
rpcb_put_local(net);
}
static int svc_uses_rpcbind(struct svc_serv *serv)
{
struct svc_program *progp;
unsigned int i;
for (progp = serv->sv_program; progp; progp = progp->pg_next) {
for (i = 0; i < progp->pg_nvers; i++) {
if (progp->pg_vers[i] == NULL)
continue;
if (progp->pg_vers[i]->vs_hidden == 0)
return 1;
}
}
return 0;
}
int svc_bind(struct svc_serv *serv, struct net *net)
{
if (!svc_uses_rpcbind(serv))
return 0;
return svc_rpcb_setup(serv, net);
}
static void
__svc_init_bc(struct svc_serv *serv)
{
INIT_LIST_HEAD(&serv->sv_cb_list);
spin_lock_init(&serv->sv_cb_lock);
init_waitqueue_head(&serv->sv_cb_waitq);
}
static void
__svc_init_bc(struct svc_serv *serv)
{
}
static struct svc_serv *
__svc_create(struct svc_program *prog, unsigned int bufsize, int npools,
struct svc_serv_ops *ops)
{
struct svc_serv *serv;
unsigned int vers;
unsigned int xdrsize;
unsigned int i;
if (!(serv = kzalloc(sizeof(*serv), GFP_KERNEL)))
return NULL;
serv->sv_name = prog->pg_name;
serv->sv_program = prog;
serv->sv_nrthreads = 1;
serv->sv_stats = prog->pg_stats;
if (bufsize > RPCSVC_MAXPAYLOAD)
bufsize = RPCSVC_MAXPAYLOAD;
serv->sv_max_payload = bufsize? bufsize : 4096;
serv->sv_max_mesg = roundup(serv->sv_max_payload + PAGE_SIZE, PAGE_SIZE);
serv->sv_ops = ops;
xdrsize = 0;
while (prog) {
prog->pg_lovers = prog->pg_nvers-1;
for (vers=0; vers<prog->pg_nvers ; vers++)
if (prog->pg_vers[vers]) {
prog->pg_hivers = vers;
if (prog->pg_lovers > vers)
prog->pg_lovers = vers;
if (prog->pg_vers[vers]->vs_xdrsize > xdrsize)
xdrsize = prog->pg_vers[vers]->vs_xdrsize;
}
prog = prog->pg_next;
}
serv->sv_xdrsize = xdrsize;
INIT_LIST_HEAD(&serv->sv_tempsocks);
INIT_LIST_HEAD(&serv->sv_permsocks);
init_timer(&serv->sv_temptimer);
spin_lock_init(&serv->sv_lock);
__svc_init_bc(serv);
serv->sv_nrpools = npools;
serv->sv_pools =
kcalloc(serv->sv_nrpools, sizeof(struct svc_pool),
GFP_KERNEL);
if (!serv->sv_pools) {
kfree(serv);
return NULL;
}
for (i = 0; i < serv->sv_nrpools; i++) {
struct svc_pool *pool = &serv->sv_pools[i];
dprintk("svc: initialising pool %u for %s\n",
i, serv->sv_name);
pool->sp_id = i;
INIT_LIST_HEAD(&pool->sp_sockets);
INIT_LIST_HEAD(&pool->sp_all_threads);
spin_lock_init(&pool->sp_lock);
}
return serv;
}
struct svc_serv *
svc_create(struct svc_program *prog, unsigned int bufsize,
struct svc_serv_ops *ops)
{
return __svc_create(prog, bufsize, 1, ops);
}
struct svc_serv *
svc_create_pooled(struct svc_program *prog, unsigned int bufsize,
struct svc_serv_ops *ops)
{
struct svc_serv *serv;
unsigned int npools = svc_pool_map_get();
serv = __svc_create(prog, bufsize, npools, ops);
if (!serv)
goto out_err;
return serv;
out_err:
svc_pool_map_put();
return NULL;
}
void svc_shutdown_net(struct svc_serv *serv, struct net *net)
{
svc_close_net(serv, net);
if (serv->sv_ops->svo_shutdown)
serv->sv_ops->svo_shutdown(serv, net);
}
void
svc_destroy(struct svc_serv *serv)
{
dprintk("svc: svc_destroy(%s, %d)\n",
serv->sv_program->pg_name,
serv->sv_nrthreads);
if (serv->sv_nrthreads) {
if (--(serv->sv_nrthreads) != 0) {
svc_sock_update_bufs(serv);
return;
}
} else
printk("svc_destroy: no threads for serv=%p!\n", serv);
del_timer_sync(&serv->sv_temptimer);
BUG_ON(!list_empty(&serv->sv_permsocks));
BUG_ON(!list_empty(&serv->sv_tempsocks));
cache_clean_deferred(serv);
if (svc_serv_is_pooled(serv))
svc_pool_map_put();
kfree(serv->sv_pools);
kfree(serv);
}
static int
svc_init_buffer(struct svc_rqst *rqstp, unsigned int size, int node)
{
unsigned int pages, arghi;
if (svc_is_backchannel(rqstp))
return 1;
pages = size / PAGE_SIZE + 1;
arghi = 0;
WARN_ON_ONCE(pages > RPCSVC_MAXPAGES);
if (pages > RPCSVC_MAXPAGES)
pages = RPCSVC_MAXPAGES;
while (pages) {
struct page *p = alloc_pages_node(node, GFP_KERNEL, 0);
if (!p)
break;
rqstp->rq_pages[arghi++] = p;
pages--;
}
return pages == 0;
}
static void
svc_release_buffer(struct svc_rqst *rqstp)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(rqstp->rq_pages); i++)
if (rqstp->rq_pages[i])
put_page(rqstp->rq_pages[i]);
}
struct svc_rqst *
svc_rqst_alloc(struct svc_serv *serv, struct svc_pool *pool, int node)
{
struct svc_rqst *rqstp;
rqstp = kzalloc_node(sizeof(*rqstp), GFP_KERNEL, node);
if (!rqstp)
return rqstp;
__set_bit(RQ_BUSY, &rqstp->rq_flags);
spin_lock_init(&rqstp->rq_lock);
rqstp->rq_server = serv;
rqstp->rq_pool = pool;
rqstp->rq_argp = kmalloc_node(serv->sv_xdrsize, GFP_KERNEL, node);
if (!rqstp->rq_argp)
goto out_enomem;
rqstp->rq_resp = kmalloc_node(serv->sv_xdrsize, GFP_KERNEL, node);
if (!rqstp->rq_resp)
goto out_enomem;
if (!svc_init_buffer(rqstp, serv->sv_max_mesg, node))
goto out_enomem;
return rqstp;
out_enomem:
svc_rqst_free(rqstp);
return NULL;
}
struct svc_rqst *
svc_prepare_thread(struct svc_serv *serv, struct svc_pool *pool, int node)
{
struct svc_rqst *rqstp;
rqstp = svc_rqst_alloc(serv, pool, node);
if (!rqstp)
return ERR_PTR(-ENOMEM);
serv->sv_nrthreads++;
spin_lock_bh(&pool->sp_lock);
pool->sp_nrthreads++;
list_add_rcu(&rqstp->rq_all, &pool->sp_all_threads);
spin_unlock_bh(&pool->sp_lock);
return rqstp;
}
static inline struct svc_pool *
choose_pool(struct svc_serv *serv, struct svc_pool *pool, unsigned int *state)
{
if (pool != NULL)
return pool;
return &serv->sv_pools[(*state)++ % serv->sv_nrpools];
}
static inline struct task_struct *
choose_victim(struct svc_serv *serv, struct svc_pool *pool, unsigned int *state)
{
unsigned int i;
struct task_struct *task = NULL;
if (pool != NULL) {
spin_lock_bh(&pool->sp_lock);
} else {
for (i = 0; i < serv->sv_nrpools; i++) {
pool = &serv->sv_pools[--(*state) % serv->sv_nrpools];
spin_lock_bh(&pool->sp_lock);
if (!list_empty(&pool->sp_all_threads))
goto found_pool;
spin_unlock_bh(&pool->sp_lock);
}
return NULL;
}
found_pool:
if (!list_empty(&pool->sp_all_threads)) {
struct svc_rqst *rqstp;
rqstp = list_entry(pool->sp_all_threads.next, struct svc_rqst, rq_all);
set_bit(RQ_VICTIM, &rqstp->rq_flags);
list_del_rcu(&rqstp->rq_all);
task = rqstp->rq_task;
}
spin_unlock_bh(&pool->sp_lock);
return task;
}
int
svc_set_num_threads(struct svc_serv *serv, struct svc_pool *pool, int nrservs)
{
struct svc_rqst *rqstp;
struct task_struct *task;
struct svc_pool *chosen_pool;
int error = 0;
unsigned int state = serv->sv_nrthreads-1;
int node;
if (pool == NULL) {
nrservs -= (serv->sv_nrthreads-1);
} else {
spin_lock_bh(&pool->sp_lock);
nrservs -= pool->sp_nrthreads;
spin_unlock_bh(&pool->sp_lock);
}
while (nrservs > 0) {
nrservs--;
chosen_pool = choose_pool(serv, pool, &state);
node = svc_pool_map_get_node(chosen_pool->sp_id);
rqstp = svc_prepare_thread(serv, chosen_pool, node);
if (IS_ERR(rqstp)) {
error = PTR_ERR(rqstp);
break;
}
__module_get(serv->sv_ops->svo_module);
task = kthread_create_on_node(serv->sv_ops->svo_function, rqstp,
node, "%s", serv->sv_name);
if (IS_ERR(task)) {
error = PTR_ERR(task);
module_put(serv->sv_ops->svo_module);
svc_exit_thread(rqstp);
break;
}
rqstp->rq_task = task;
if (serv->sv_nrpools > 1)
svc_pool_map_set_cpumask(task, chosen_pool->sp_id);
svc_sock_update_bufs(serv);
wake_up_process(task);
}
while (nrservs < 0 &&
(task = choose_victim(serv, pool, &state)) != NULL) {
send_sig(SIGINT, task, 1);
nrservs++;
}
return error;
}
void
svc_rqst_free(struct svc_rqst *rqstp)
{
svc_release_buffer(rqstp);
kfree(rqstp->rq_resp);
kfree(rqstp->rq_argp);
kfree(rqstp->rq_auth_data);
kfree_rcu(rqstp, rq_rcu_head);
}
void
svc_exit_thread(struct svc_rqst *rqstp)
{
struct svc_serv *serv = rqstp->rq_server;
struct svc_pool *pool = rqstp->rq_pool;
spin_lock_bh(&pool->sp_lock);
pool->sp_nrthreads--;
if (!test_and_set_bit(RQ_VICTIM, &rqstp->rq_flags))
list_del_rcu(&rqstp->rq_all);
spin_unlock_bh(&pool->sp_lock);
svc_rqst_free(rqstp);
if (serv)
svc_destroy(serv);
}
static int __svc_rpcb_register4(struct net *net, const u32 program,
const u32 version,
const unsigned short protocol,
const unsigned short port)
{
const struct sockaddr_in sin = {
.sin_family = AF_INET,
.sin_addr.s_addr = htonl(INADDR_ANY),
.sin_port = htons(port),
};
const char *netid;
int error;
switch (protocol) {
case IPPROTO_UDP:
netid = RPCBIND_NETID_UDP;
break;
case IPPROTO_TCP:
netid = RPCBIND_NETID_TCP;
break;
default:
return -ENOPROTOOPT;
}
error = rpcb_v4_register(net, program, version,
(const struct sockaddr *)&sin, netid);
if (error == -EPROTONOSUPPORT)
error = rpcb_register(net, program, version, protocol, port);
return error;
}
static int __svc_rpcb_register6(struct net *net, const u32 program,
const u32 version,
const unsigned short protocol,
const unsigned short port)
{
const struct sockaddr_in6 sin6 = {
.sin6_family = AF_INET6,
.sin6_addr = IN6ADDR_ANY_INIT,
.sin6_port = htons(port),
};
const char *netid;
int error;
switch (protocol) {
case IPPROTO_UDP:
netid = RPCBIND_NETID_UDP6;
break;
case IPPROTO_TCP:
netid = RPCBIND_NETID_TCP6;
break;
default:
return -ENOPROTOOPT;
}
error = rpcb_v4_register(net, program, version,
(const struct sockaddr *)&sin6, netid);
if (error == -EPROTONOSUPPORT)
error = -EAFNOSUPPORT;
return error;
}
static int __svc_register(struct net *net, const char *progname,
const u32 program, const u32 version,
const int family,
const unsigned short protocol,
const unsigned short port)
{
int error = -EAFNOSUPPORT;
switch (family) {
case PF_INET:
error = __svc_rpcb_register4(net, program, version,
protocol, port);
break;
#if IS_ENABLED(CONFIG_IPV6)
case PF_INET6:
error = __svc_rpcb_register6(net, program, version,
protocol, port);
#endif
}
return error;
}
int svc_register(const struct svc_serv *serv, struct net *net,
const int family, const unsigned short proto,
const unsigned short port)
{
struct svc_program *progp;
struct svc_version *vers;
unsigned int i;
int error = 0;
WARN_ON_ONCE(proto == 0 && port == 0);
if (proto == 0 && port == 0)
return -EINVAL;
for (progp = serv->sv_program; progp; progp = progp->pg_next) {
for (i = 0; i < progp->pg_nvers; i++) {
vers = progp->pg_vers[i];
if (vers == NULL)
continue;
dprintk("svc: svc_register(%sv%d, %s, %u, %u)%s\n",
progp->pg_name,
i,
proto == IPPROTO_UDP? "udp" : "tcp",
port,
family,
vers->vs_hidden ?
" (but not telling portmap)" : "");
if (vers->vs_hidden)
continue;
error = __svc_register(net, progp->pg_name, progp->pg_prog,
i, family, proto, port);
if (vers->vs_rpcb_optnl) {
error = 0;
continue;
}
if (error < 0) {
printk(KERN_WARNING "svc: failed to register "
"%sv%u RPC service (errno %d).\n",
progp->pg_name, i, -error);
break;
}
}
}
return error;
}
static void __svc_unregister(struct net *net, const u32 program, const u32 version,
const char *progname)
{
int error;
error = rpcb_v4_register(net, program, version, NULL, "");
if (error == -EPROTONOSUPPORT)
error = rpcb_register(net, program, version, 0, 0);
dprintk("svc: %s(%sv%u), error %d\n",
__func__, progname, version, error);
}
static void svc_unregister(const struct svc_serv *serv, struct net *net)
{
struct svc_program *progp;
unsigned long flags;
unsigned int i;
clear_thread_flag(TIF_SIGPENDING);
for (progp = serv->sv_program; progp; progp = progp->pg_next) {
for (i = 0; i < progp->pg_nvers; i++) {
if (progp->pg_vers[i] == NULL)
continue;
if (progp->pg_vers[i]->vs_hidden)
continue;
dprintk("svc: attempting to unregister %sv%u\n",
progp->pg_name, i);
__svc_unregister(net, progp->pg_prog, i, progp->pg_name);
}
}
spin_lock_irqsave(&current->sighand->siglock, flags);
recalc_sigpending();
spin_unlock_irqrestore(&current->sighand->siglock, flags);
}
int
bc_svc_process(struct svc_serv *serv, struct rpc_rqst *req,
struct svc_rqst *rqstp)
{
struct kvec *argv = &rqstp->rq_arg.head[0];
struct kvec *resv = &rqstp->rq_res.head[0];
struct rpc_task *task;
int proc_error;
int error;
dprintk("svc: %s(%p)\n", __func__, req);
rqstp->rq_xprt = serv->sv_bc_xprt;
rqstp->rq_xid = req->rq_xid;
rqstp->rq_prot = req->rq_xprt->prot;
rqstp->rq_server = serv;
rqstp->rq_addrlen = sizeof(req->rq_xprt->addr);
memcpy(&rqstp->rq_addr, &req->rq_xprt->addr, rqstp->rq_addrlen);
memcpy(&rqstp->rq_arg, &req->rq_rcv_buf, sizeof(rqstp->rq_arg));
memcpy(&rqstp->rq_res, &req->rq_snd_buf, sizeof(rqstp->rq_res));
rqstp->rq_arg.len = req->rq_private_buf.len;
if (rqstp->rq_arg.len <= rqstp->rq_arg.head[0].iov_len) {
rqstp->rq_arg.head[0].iov_len = rqstp->rq_arg.len;
rqstp->rq_arg.page_len = 0;
} else if (rqstp->rq_arg.len <= rqstp->rq_arg.head[0].iov_len +
rqstp->rq_arg.page_len)
rqstp->rq_arg.page_len = rqstp->rq_arg.len -
rqstp->rq_arg.head[0].iov_len;
else
rqstp->rq_arg.len = rqstp->rq_arg.head[0].iov_len +
rqstp->rq_arg.page_len;
resv->iov_len = 0;
svc_getu32(argv);
svc_getnl(argv);
proc_error = svc_process_common(rqstp, argv, resv);
atomic_inc(&req->rq_xprt->bc_free_slots);
if (!proc_error) {
xprt_free_bc_request(req);
return 0;
}
memcpy(&req->rq_snd_buf, &rqstp->rq_res, sizeof(req->rq_snd_buf));
task = rpc_run_bc_task(req);
if (IS_ERR(task)) {
error = PTR_ERR(task);
goto out;
}
WARN_ON_ONCE(atomic_read(&task->tk_count) != 1);
error = task->tk_status;
rpc_put_task(task);
out:
dprintk("svc: %s(), error=%d\n", __func__, error);
return error;
}
u32 svc_max_payload(const struct svc_rqst *rqstp)
{
u32 max = rqstp->rq_xprt->xpt_class->xcl_max_payload;
if (rqstp->rq_server->sv_max_payload < max)
max = rqstp->rq_server->sv_max_payload;
return max;
}
