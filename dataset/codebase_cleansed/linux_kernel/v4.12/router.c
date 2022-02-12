int
lnet_peer_buffer_credits(struct lnet_ni *ni)
{
if (ni->ni_peerrtrcredits > 0)
return ni->ni_peerrtrcredits;
if (peer_buffer_credits > 0)
return peer_buffer_credits;
return ni->ni_peertxcredits;
}
int
lnet_peers_start_down(void)
{
return check_routers_before_use;
}
void
lnet_notify_locked(struct lnet_peer *lp, int notifylnd, int alive,
unsigned long when)
{
if (time_before(when, lp->lp_timestamp)) {
CDEBUG(D_NET, "Out of date\n");
return;
}
lp->lp_timestamp = when;
lp->lp_ping_deadline = 0;
if (lp->lp_alive_count &&
(!lp->lp_alive) == (!alive)) {
CDEBUG(D_NET, "Old news\n");
return;
}
lp->lp_alive_count++;
lp->lp_alive = !(!alive);
lp->lp_notify = 1;
lp->lp_notifylnd |= notifylnd;
if (lp->lp_alive)
lp->lp_ping_feats = LNET_PING_FEAT_INVAL;
CDEBUG(D_NET, "set %s %d\n", libcfs_nid2str(lp->lp_nid), alive);
}
static void
lnet_ni_notify_locked(struct lnet_ni *ni, struct lnet_peer *lp)
{
int alive;
int notifylnd;
if (lp->lp_notifying || !ni)
return;
lp->lp_notifying = 1;
while (lp->lp_notify) {
alive = lp->lp_alive;
notifylnd = lp->lp_notifylnd;
lp->lp_notifylnd = 0;
lp->lp_notify = 0;
if (notifylnd && ni->ni_lnd->lnd_notify) {
lnet_net_unlock(lp->lp_cpt);
ni->ni_lnd->lnd_notify(ni, lp->lp_nid, alive);
lnet_net_lock(lp->lp_cpt);
}
}
lp->lp_notifying = 0;
}
static void
lnet_rtr_addref_locked(struct lnet_peer *lp)
{
LASSERT(lp->lp_refcount > 0);
LASSERT(lp->lp_rtr_refcount >= 0);
lp->lp_rtr_refcount++;
if (lp->lp_rtr_refcount == 1) {
struct list_head *pos;
list_for_each_prev(pos, &the_lnet.ln_routers) {
struct lnet_peer *rtr;
rtr = list_entry(pos, struct lnet_peer, lp_rtr_list);
if (rtr->lp_nid < lp->lp_nid)
break;
}
list_add(&lp->lp_rtr_list, pos);
lnet_peer_addref_locked(lp);
the_lnet.ln_routers_version++;
}
}
static void
lnet_rtr_decref_locked(struct lnet_peer *lp)
{
LASSERT(lp->lp_refcount > 0);
LASSERT(lp->lp_rtr_refcount > 0);
lp->lp_rtr_refcount--;
if (!lp->lp_rtr_refcount) {
LASSERT(list_empty(&lp->lp_routes));
if (lp->lp_rcd) {
list_add(&lp->lp_rcd->rcd_list,
&the_lnet.ln_rcd_deathrow);
lp->lp_rcd = NULL;
}
list_del(&lp->lp_rtr_list);
lnet_peer_decref_locked(lp);
the_lnet.ln_routers_version++;
}
}
struct lnet_remotenet *
lnet_find_net_locked(__u32 net)
{
struct lnet_remotenet *rnet;
struct list_head *tmp;
struct list_head *rn_list;
LASSERT(!the_lnet.ln_shutdown);
rn_list = lnet_net2rnethash(net);
list_for_each(tmp, rn_list) {
rnet = list_entry(tmp, struct lnet_remotenet, lrn_list);
if (rnet->lrn_net == net)
return rnet;
}
return NULL;
}
static void lnet_shuffle_seed(void)
{
static int seeded;
__u32 lnd_type, seed[2];
struct timespec64 ts;
struct lnet_ni *ni;
struct list_head *tmp;
if (seeded)
return;
cfs_get_random_bytes(seed, sizeof(seed));
list_for_each(tmp, &the_lnet.ln_nis) {
ni = list_entry(tmp, struct lnet_ni, ni_list);
lnd_type = LNET_NETTYP(LNET_NIDNET(ni->ni_nid));
if (lnd_type != LOLND)
seed[0] ^= (LNET_NIDADDR(ni->ni_nid) | lnd_type);
}
ktime_get_ts64(&ts);
cfs_srand(ts.tv_sec ^ seed[0], ts.tv_nsec ^ seed[1]);
seeded = 1;
}
static void
lnet_add_route_to_rnet(struct lnet_remotenet *rnet, struct lnet_route *route)
{
unsigned int len = 0;
unsigned int offset = 0;
struct list_head *e;
lnet_shuffle_seed();
list_for_each(e, &rnet->lrn_routes) {
len++;
}
offset = cfs_rand() % (len + 1);
list_for_each(e, &rnet->lrn_routes) {
if (!offset)
break;
offset--;
}
list_add(&route->lr_list, e);
list_add(&route->lr_gwlist, &route->lr_gateway->lp_routes);
the_lnet.ln_remote_nets_version++;
lnet_rtr_addref_locked(route->lr_gateway);
}
int
lnet_add_route(__u32 net, __u32 hops, lnet_nid_t gateway,
unsigned int priority)
{
struct list_head *e;
struct lnet_remotenet *rnet;
struct lnet_remotenet *rnet2;
struct lnet_route *route;
struct lnet_ni *ni;
int add_route;
int rc;
CDEBUG(D_NET, "Add route: net %s hops %d priority %u gw %s\n",
libcfs_net2str(net), hops, priority, libcfs_nid2str(gateway));
if (gateway == LNET_NID_ANY ||
LNET_NETTYP(LNET_NIDNET(gateway)) == LOLND ||
net == LNET_NIDNET(LNET_NID_ANY) ||
LNET_NETTYP(net) == LOLND ||
LNET_NIDNET(gateway) == net ||
(hops != LNET_UNDEFINED_HOPS && (hops < 1 || hops > 255)))
return -EINVAL;
if (lnet_islocalnet(net))
return -EEXIST;
LIBCFS_ALLOC(route, sizeof(*route));
LIBCFS_ALLOC(rnet, sizeof(*rnet));
if (!route || !rnet) {
CERROR("Out of memory creating route %s %d %s\n",
libcfs_net2str(net), hops, libcfs_nid2str(gateway));
if (route)
LIBCFS_FREE(route, sizeof(*route));
if (rnet)
LIBCFS_FREE(rnet, sizeof(*rnet));
return -ENOMEM;
}
INIT_LIST_HEAD(&rnet->lrn_routes);
rnet->lrn_net = net;
route->lr_hops = hops;
route->lr_net = net;
route->lr_priority = priority;
lnet_net_lock(LNET_LOCK_EX);
rc = lnet_nid2peer_locked(&route->lr_gateway, gateway, LNET_LOCK_EX);
if (rc) {
lnet_net_unlock(LNET_LOCK_EX);
LIBCFS_FREE(route, sizeof(*route));
LIBCFS_FREE(rnet, sizeof(*rnet));
if (rc == -EHOSTUNREACH)
return rc;
CERROR("Error %d creating route %s %d %s\n", rc,
libcfs_net2str(net), hops,
libcfs_nid2str(gateway));
return rc;
}
LASSERT(!the_lnet.ln_shutdown);
rnet2 = lnet_find_net_locked(net);
if (!rnet2) {
list_add_tail(&rnet->lrn_list, lnet_net2rnethash(net));
rnet2 = rnet;
}
add_route = 1;
list_for_each(e, &rnet2->lrn_routes) {
struct lnet_route *route2;
route2 = list_entry(e, struct lnet_route, lr_list);
if (route2->lr_gateway == route->lr_gateway) {
add_route = 0;
break;
}
LASSERT(route2->lr_gateway->lp_nid != gateway);
}
if (add_route) {
lnet_peer_addref_locked(route->lr_gateway);
lnet_add_route_to_rnet(rnet2, route);
ni = route->lr_gateway->lp_ni;
lnet_net_unlock(LNET_LOCK_EX);
if (ni->ni_lnd->lnd_notify)
ni->ni_lnd->lnd_notify(ni, gateway, 1);
lnet_net_lock(LNET_LOCK_EX);
}
lnet_peer_decref_locked(route->lr_gateway);
lnet_net_unlock(LNET_LOCK_EX);
rc = 0;
if (!add_route) {
rc = -EEXIST;
LIBCFS_FREE(route, sizeof(*route));
}
if (rnet != rnet2)
LIBCFS_FREE(rnet, sizeof(*rnet));
wake_up(&the_lnet.ln_rc_waitq);
return rc;
}
int
lnet_check_routes(void)
{
struct lnet_remotenet *rnet;
struct lnet_route *route;
struct lnet_route *route2;
struct list_head *e1;
struct list_head *e2;
int cpt;
struct list_head *rn_list;
int i;
cpt = lnet_net_lock_current();
for (i = 0; i < LNET_REMOTE_NETS_HASH_SIZE; i++) {
rn_list = &the_lnet.ln_remote_nets_hash[i];
list_for_each(e1, rn_list) {
rnet = list_entry(e1, struct lnet_remotenet, lrn_list);
route2 = NULL;
list_for_each(e2, &rnet->lrn_routes) {
lnet_nid_t nid1;
lnet_nid_t nid2;
int net;
route = list_entry(e2, struct lnet_route, lr_list);
if (!route2) {
route2 = route;
continue;
}
if (route->lr_gateway->lp_ni ==
route2->lr_gateway->lp_ni)
continue;
nid1 = route->lr_gateway->lp_nid;
nid2 = route2->lr_gateway->lp_nid;
net = rnet->lrn_net;
lnet_net_unlock(cpt);
CERROR("Routes to %s via %s and %s not supported\n",
libcfs_net2str(net),
libcfs_nid2str(nid1),
libcfs_nid2str(nid2));
return -EINVAL;
}
}
}
lnet_net_unlock(cpt);
return 0;
}
int
lnet_del_route(__u32 net, lnet_nid_t gw_nid)
{
struct lnet_peer *gateway;
struct lnet_remotenet *rnet;
struct lnet_route *route;
struct list_head *e1;
struct list_head *e2;
int rc = -ENOENT;
struct list_head *rn_list;
int idx = 0;
CDEBUG(D_NET, "Del route: net %s : gw %s\n",
libcfs_net2str(net), libcfs_nid2str(gw_nid));
lnet_net_lock(LNET_LOCK_EX);
if (net == LNET_NIDNET(LNET_NID_ANY))
rn_list = &the_lnet.ln_remote_nets_hash[0];
else
rn_list = lnet_net2rnethash(net);
again:
list_for_each(e1, rn_list) {
rnet = list_entry(e1, struct lnet_remotenet, lrn_list);
if (!(net == LNET_NIDNET(LNET_NID_ANY) ||
net == rnet->lrn_net))
continue;
list_for_each(e2, &rnet->lrn_routes) {
route = list_entry(e2, struct lnet_route, lr_list);
gateway = route->lr_gateway;
if (!(gw_nid == LNET_NID_ANY ||
gw_nid == gateway->lp_nid))
continue;
list_del(&route->lr_list);
list_del(&route->lr_gwlist);
the_lnet.ln_remote_nets_version++;
if (list_empty(&rnet->lrn_routes))
list_del(&rnet->lrn_list);
else
rnet = NULL;
lnet_rtr_decref_locked(gateway);
lnet_peer_decref_locked(gateway);
lnet_net_unlock(LNET_LOCK_EX);
LIBCFS_FREE(route, sizeof(*route));
if (rnet)
LIBCFS_FREE(rnet, sizeof(*rnet));
rc = 0;
lnet_net_lock(LNET_LOCK_EX);
goto again;
}
}
if (net == LNET_NIDNET(LNET_NID_ANY) &&
++idx < LNET_REMOTE_NETS_HASH_SIZE) {
rn_list = &the_lnet.ln_remote_nets_hash[idx];
goto again;
}
lnet_net_unlock(LNET_LOCK_EX);
return rc;
}
void
lnet_destroy_routes(void)
{
lnet_del_route(LNET_NIDNET(LNET_NID_ANY), LNET_NID_ANY);
}
int lnet_get_rtr_pool_cfg(int idx, struct lnet_ioctl_pool_cfg *pool_cfg)
{
int i, rc = -ENOENT, j;
if (!the_lnet.ln_rtrpools)
return rc;
for (i = 0; i < LNET_NRBPOOLS; i++) {
struct lnet_rtrbufpool *rbp;
lnet_net_lock(LNET_LOCK_EX);
cfs_percpt_for_each(rbp, j, the_lnet.ln_rtrpools) {
if (i++ != idx)
continue;
pool_cfg->pl_pools[i].pl_npages = rbp[i].rbp_npages;
pool_cfg->pl_pools[i].pl_nbuffers = rbp[i].rbp_nbuffers;
pool_cfg->pl_pools[i].pl_credits = rbp[i].rbp_credits;
pool_cfg->pl_pools[i].pl_mincredits = rbp[i].rbp_mincredits;
rc = 0;
break;
}
lnet_net_unlock(LNET_LOCK_EX);
}
lnet_net_lock(LNET_LOCK_EX);
pool_cfg->pl_routing = the_lnet.ln_routing;
lnet_net_unlock(LNET_LOCK_EX);
return rc;
}
int
lnet_get_route(int idx, __u32 *net, __u32 *hops,
lnet_nid_t *gateway, __u32 *alive, __u32 *priority)
{
struct list_head *e1;
struct list_head *e2;
struct lnet_remotenet *rnet;
struct lnet_route *route;
int cpt;
int i;
struct list_head *rn_list;
cpt = lnet_net_lock_current();
for (i = 0; i < LNET_REMOTE_NETS_HASH_SIZE; i++) {
rn_list = &the_lnet.ln_remote_nets_hash[i];
list_for_each(e1, rn_list) {
rnet = list_entry(e1, struct lnet_remotenet, lrn_list);
list_for_each(e2, &rnet->lrn_routes) {
route = list_entry(e2, struct lnet_route,
lr_list);
if (!idx--) {
*net = rnet->lrn_net;
*hops = route->lr_hops;
*priority = route->lr_priority;
*gateway = route->lr_gateway->lp_nid;
*alive = lnet_is_route_alive(route);
lnet_net_unlock(cpt);
return 0;
}
}
}
}
lnet_net_unlock(cpt);
return -ENOENT;
}
void
lnet_swap_pinginfo(struct lnet_ping_info *info)
{
int i;
struct lnet_ni_status *stat;
__swab32s(&info->pi_magic);
__swab32s(&info->pi_features);
__swab32s(&info->pi_pid);
__swab32s(&info->pi_nnis);
for (i = 0; i < info->pi_nnis && i < LNET_MAX_RTR_NIS; i++) {
stat = &info->pi_ni[i];
__swab64s(&stat->ns_nid);
__swab32s(&stat->ns_status);
}
}
static void
lnet_parse_rc_info(struct lnet_rc_data *rcd)
{
struct lnet_ping_info *info = rcd->rcd_pinginfo;
struct lnet_peer *gw = rcd->rcd_gateway;
struct lnet_route *rte;
if (!gw->lp_alive)
return;
if (info->pi_magic == __swab32(LNET_PROTO_PING_MAGIC))
lnet_swap_pinginfo(info);
if (info->pi_magic != LNET_PROTO_PING_MAGIC) {
CDEBUG(D_NET, "%s: Unexpected magic %08x\n",
libcfs_nid2str(gw->lp_nid), info->pi_magic);
gw->lp_ping_feats = LNET_PING_FEAT_INVAL;
return;
}
gw->lp_ping_feats = info->pi_features;
if (!(gw->lp_ping_feats & LNET_PING_FEAT_MASK)) {
CDEBUG(D_NET, "%s: Unexpected features 0x%x\n",
libcfs_nid2str(gw->lp_nid), gw->lp_ping_feats);
return;
}
if (!(gw->lp_ping_feats & LNET_PING_FEAT_NI_STATUS))
return;
list_for_each_entry(rte, &gw->lp_routes, lr_gwlist) {
int down = 0;
int up = 0;
int i;
if (gw->lp_ping_feats & LNET_PING_FEAT_RTE_DISABLED) {
rte->lr_downis = 1;
continue;
}
for (i = 0; i < info->pi_nnis && i < LNET_MAX_RTR_NIS; i++) {
struct lnet_ni_status *stat = &info->pi_ni[i];
lnet_nid_t nid = stat->ns_nid;
if (nid == LNET_NID_ANY) {
CDEBUG(D_NET, "%s: unexpected LNET_NID_ANY\n",
libcfs_nid2str(gw->lp_nid));
gw->lp_ping_feats = LNET_PING_FEAT_INVAL;
return;
}
if (LNET_NETTYP(LNET_NIDNET(nid)) == LOLND)
continue;
if (stat->ns_status == LNET_NI_STATUS_DOWN) {
down++;
continue;
}
if (stat->ns_status == LNET_NI_STATUS_UP) {
if (LNET_NIDNET(nid) == rte->lr_net) {
up = 1;
break;
}
continue;
}
CDEBUG(D_NET, "%s: Unexpected status 0x%x\n",
libcfs_nid2str(gw->lp_nid), stat->ns_status);
gw->lp_ping_feats = LNET_PING_FEAT_INVAL;
return;
}
if (up) {
rte->lr_downis = 0;
continue;
}
if (!down && rte->lr_hops == 1)
down = 1;
rte->lr_downis = down;
}
}
static void
lnet_router_checker_event(struct lnet_event *event)
{
struct lnet_rc_data *rcd = event->md.user_ptr;
struct lnet_peer *lp;
LASSERT(rcd);
if (event->unlinked) {
LNetInvalidateMDHandle(&rcd->rcd_mdh);
return;
}
LASSERT(event->type == LNET_EVENT_SEND ||
event->type == LNET_EVENT_REPLY);
lp = rcd->rcd_gateway;
LASSERT(lp);
lnet_net_lock(lp->lp_cpt);
if (!lnet_isrouter(lp) || lp->lp_rcd != rcd) {
goto out;
}
if (event->type == LNET_EVENT_SEND) {
lp->lp_ping_notsent = 0;
if (!event->status)
goto out;
}
lnet_notify_locked(lp, 1, !event->status, cfs_time_current());
if (avoid_asym_router_failure && !event->status)
lnet_parse_rc_info(rcd);
out:
lnet_net_unlock(lp->lp_cpt);
}
static void
lnet_wait_known_routerstate(void)
{
struct lnet_peer *rtr;
struct list_head *entry;
int all_known;
LASSERT(the_lnet.ln_rc_state == LNET_RC_STATE_RUNNING);
for (;;) {
int cpt = lnet_net_lock_current();
all_known = 1;
list_for_each(entry, &the_lnet.ln_routers) {
rtr = list_entry(entry, struct lnet_peer, lp_rtr_list);
if (!rtr->lp_alive_count) {
all_known = 0;
break;
}
}
lnet_net_unlock(cpt);
if (all_known)
return;
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(cfs_time_seconds(1));
}
}
void
lnet_router_ni_update_locked(struct lnet_peer *gw, __u32 net)
{
struct lnet_route *rte;
if ((gw->lp_ping_feats & LNET_PING_FEAT_NI_STATUS)) {
list_for_each_entry(rte, &gw->lp_routes, lr_gwlist) {
if (rte->lr_net == net) {
rte->lr_downis = 0;
break;
}
}
}
}
static void
lnet_update_ni_status_locked(void)
{
struct lnet_ni *ni;
time64_t now;
int timeout;
LASSERT(the_lnet.ln_routing);
timeout = router_ping_timeout +
max(live_router_check_interval, dead_router_check_interval);
now = ktime_get_real_seconds();
list_for_each_entry(ni, &the_lnet.ln_nis, ni_list) {
if (ni->ni_lnd->lnd_type == LOLND)
continue;
if (now < ni->ni_last_alive + timeout)
continue;
lnet_ni_lock(ni);
if (now < ni->ni_last_alive + timeout) {
lnet_ni_unlock(ni);
continue;
}
LASSERT(ni->ni_status);
if (ni->ni_status->ns_status != LNET_NI_STATUS_DOWN) {
CDEBUG(D_NET, "NI(%s:%d) status changed to down\n",
libcfs_nid2str(ni->ni_nid), timeout);
ni->ni_status->ns_status = LNET_NI_STATUS_DOWN;
}
lnet_ni_unlock(ni);
}
}
static void
lnet_destroy_rc_data(struct lnet_rc_data *rcd)
{
LASSERT(list_empty(&rcd->rcd_list));
LASSERT(LNetMDHandleIsInvalid(rcd->rcd_mdh));
if (rcd->rcd_gateway) {
int cpt = rcd->rcd_gateway->lp_cpt;
lnet_net_lock(cpt);
lnet_peer_decref_locked(rcd->rcd_gateway);
lnet_net_unlock(cpt);
}
if (rcd->rcd_pinginfo)
LIBCFS_FREE(rcd->rcd_pinginfo, LNET_PINGINFO_SIZE);
LIBCFS_FREE(rcd, sizeof(*rcd));
}
static struct lnet_rc_data *
lnet_create_rc_data_locked(struct lnet_peer *gateway)
{
struct lnet_rc_data *rcd = NULL;
struct lnet_ping_info *pi;
struct lnet_md md;
int rc;
int i;
lnet_net_unlock(gateway->lp_cpt);
LIBCFS_ALLOC(rcd, sizeof(*rcd));
if (!rcd)
goto out;
LNetInvalidateMDHandle(&rcd->rcd_mdh);
INIT_LIST_HEAD(&rcd->rcd_list);
LIBCFS_ALLOC(pi, LNET_PINGINFO_SIZE);
if (!pi)
goto out;
for (i = 0; i < LNET_MAX_RTR_NIS; i++) {
pi->pi_ni[i].ns_nid = LNET_NID_ANY;
pi->pi_ni[i].ns_status = LNET_NI_STATUS_INVALID;
}
rcd->rcd_pinginfo = pi;
md.start = pi;
md.user_ptr = rcd;
md.length = LNET_PINGINFO_SIZE;
md.threshold = LNET_MD_THRESH_INF;
md.options = LNET_MD_TRUNCATE;
md.eq_handle = the_lnet.ln_rc_eqh;
LASSERT(!LNetEQHandleIsInvalid(the_lnet.ln_rc_eqh));
rc = LNetMDBind(md, LNET_UNLINK, &rcd->rcd_mdh);
if (rc < 0) {
CERROR("Can't bind MD: %d\n", rc);
goto out;
}
LASSERT(!rc);
lnet_net_lock(gateway->lp_cpt);
if (!lnet_isrouter(gateway) || gateway->lp_rcd) {
lnet_net_unlock(gateway->lp_cpt);
goto out;
}
lnet_peer_addref_locked(gateway);
rcd->rcd_gateway = gateway;
gateway->lp_rcd = rcd;
gateway->lp_ping_notsent = 0;
return rcd;
out:
if (rcd) {
if (!LNetMDHandleIsInvalid(rcd->rcd_mdh)) {
rc = LNetMDUnlink(rcd->rcd_mdh);
LASSERT(!rc);
}
lnet_destroy_rc_data(rcd);
}
lnet_net_lock(gateway->lp_cpt);
return gateway->lp_rcd;
}
static int
lnet_router_check_interval(struct lnet_peer *rtr)
{
int secs;
secs = rtr->lp_alive ? live_router_check_interval :
dead_router_check_interval;
if (secs < 0)
secs = 0;
return secs;
}
static void
lnet_ping_router_locked(struct lnet_peer *rtr)
{
struct lnet_rc_data *rcd = NULL;
unsigned long now = cfs_time_current();
int secs;
lnet_peer_addref_locked(rtr);
if (rtr->lp_ping_deadline &&
cfs_time_after(now, rtr->lp_ping_deadline))
lnet_notify_locked(rtr, 1, 0, now);
lnet_ni_notify_locked(rtr->lp_ni, rtr);
if (!lnet_isrouter(rtr) ||
the_lnet.ln_rc_state != LNET_RC_STATE_RUNNING) {
lnet_peer_decref_locked(rtr);
return;
}
rcd = rtr->lp_rcd ?
rtr->lp_rcd : lnet_create_rc_data_locked(rtr);
if (!rcd)
return;
secs = lnet_router_check_interval(rtr);
CDEBUG(D_NET,
"rtr %s %d: deadline %lu ping_notsent %d alive %d alive_count %d lp_ping_timestamp %lu\n",
libcfs_nid2str(rtr->lp_nid), secs,
rtr->lp_ping_deadline, rtr->lp_ping_notsent,
rtr->lp_alive, rtr->lp_alive_count, rtr->lp_ping_timestamp);
if (secs && !rtr->lp_ping_notsent &&
cfs_time_after(now, cfs_time_add(rtr->lp_ping_timestamp,
cfs_time_seconds(secs)))) {
int rc;
struct lnet_process_id id;
struct lnet_handle_md mdh;
id.nid = rtr->lp_nid;
id.pid = LNET_PID_LUSTRE;
CDEBUG(D_NET, "Check: %s\n", libcfs_id2str(id));
rtr->lp_ping_notsent = 1;
rtr->lp_ping_timestamp = now;
mdh = rcd->rcd_mdh;
if (!rtr->lp_ping_deadline) {
rtr->lp_ping_deadline =
cfs_time_shift(router_ping_timeout);
}
lnet_net_unlock(rtr->lp_cpt);
rc = LNetGet(LNET_NID_ANY, mdh, id, LNET_RESERVED_PORTAL,
LNET_PROTO_PING_MATCHBITS, 0);
lnet_net_lock(rtr->lp_cpt);
if (rc)
rtr->lp_ping_notsent = 0;
}
lnet_peer_decref_locked(rtr);
}
int
lnet_router_checker_start(void)
{
struct task_struct *task;
int rc;
int eqsz = 0;
LASSERT(the_lnet.ln_rc_state == LNET_RC_STATE_SHUTDOWN);
if (check_routers_before_use &&
dead_router_check_interval <= 0) {
LCONSOLE_ERROR_MSG(0x10a, "'dead_router_check_interval' must be set if 'check_routers_before_use' is set\n");
return -EINVAL;
}
init_completion(&the_lnet.ln_rc_signal);
rc = LNetEQAlloc(0, lnet_router_checker_event, &the_lnet.ln_rc_eqh);
if (rc) {
CERROR("Can't allocate EQ(%d): %d\n", eqsz, rc);
return -ENOMEM;
}
the_lnet.ln_rc_state = LNET_RC_STATE_RUNNING;
task = kthread_run(lnet_router_checker, NULL, "router_checker");
if (IS_ERR(task)) {
rc = PTR_ERR(task);
CERROR("Can't start router checker thread: %d\n", rc);
wait_for_completion(&the_lnet.ln_rc_signal);
rc = LNetEQFree(the_lnet.ln_rc_eqh);
LASSERT(!rc);
the_lnet.ln_rc_state = LNET_RC_STATE_SHUTDOWN;
return -ENOMEM;
}
if (check_routers_before_use) {
lnet_wait_known_routerstate();
}
return 0;
}
void
lnet_router_checker_stop(void)
{
int rc;
if (the_lnet.ln_rc_state == LNET_RC_STATE_SHUTDOWN)
return;
LASSERT(the_lnet.ln_rc_state == LNET_RC_STATE_RUNNING);
the_lnet.ln_rc_state = LNET_RC_STATE_STOPPING;
wake_up(&the_lnet.ln_rc_waitq);
wait_for_completion(&the_lnet.ln_rc_signal);
LASSERT(the_lnet.ln_rc_state == LNET_RC_STATE_SHUTDOWN);
rc = LNetEQFree(the_lnet.ln_rc_eqh);
LASSERT(!rc);
}
static void
lnet_prune_rc_data(int wait_unlink)
{
struct lnet_rc_data *rcd;
struct lnet_rc_data *tmp;
struct lnet_peer *lp;
struct list_head head;
int i = 2;
if (likely(the_lnet.ln_rc_state == LNET_RC_STATE_RUNNING &&
list_empty(&the_lnet.ln_rcd_deathrow) &&
list_empty(&the_lnet.ln_rcd_zombie)))
return;
INIT_LIST_HEAD(&head);
lnet_net_lock(LNET_LOCK_EX);
if (the_lnet.ln_rc_state != LNET_RC_STATE_RUNNING) {
list_for_each_entry(lp, &the_lnet.ln_routers,
lp_rtr_list) {
if (!lp->lp_rcd)
continue;
LASSERT(list_empty(&lp->lp_rcd->rcd_list));
list_add(&lp->lp_rcd->rcd_list,
&the_lnet.ln_rcd_deathrow);
lp->lp_rcd = NULL;
}
}
list_splice_init(&the_lnet.ln_rcd_deathrow, &head);
if (!list_empty(&head)) {
lnet_net_unlock(LNET_LOCK_EX);
list_for_each_entry(rcd, &head, rcd_list)
LNetMDUnlink(rcd->rcd_mdh);
lnet_net_lock(LNET_LOCK_EX);
}
list_splice_init(&head, &the_lnet.ln_rcd_zombie);
while (!list_empty(&the_lnet.ln_rcd_zombie)) {
list_for_each_entry_safe(rcd, tmp, &the_lnet.ln_rcd_zombie,
rcd_list) {
if (LNetMDHandleIsInvalid(rcd->rcd_mdh))
list_move(&rcd->rcd_list, &head);
}
wait_unlink = wait_unlink &&
!list_empty(&the_lnet.ln_rcd_zombie);
lnet_net_unlock(LNET_LOCK_EX);
while (!list_empty(&head)) {
rcd = list_entry(head.next,
struct lnet_rc_data, rcd_list);
list_del_init(&rcd->rcd_list);
lnet_destroy_rc_data(rcd);
}
if (!wait_unlink)
return;
i++;
CDEBUG(((i & (-i)) == i) ? D_WARNING : D_NET,
"Waiting for rc buffers to unlink\n");
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(cfs_time_seconds(1) / 4);
lnet_net_lock(LNET_LOCK_EX);
}
lnet_net_unlock(LNET_LOCK_EX);
}
static inline bool
lnet_router_checker_active(void)
{
if (the_lnet.ln_rc_state != LNET_RC_STATE_RUNNING)
return true;
if (the_lnet.ln_routing)
return true;
return !list_empty(&the_lnet.ln_routers) &&
(live_router_check_interval > 0 ||
dead_router_check_interval > 0);
}
static int
lnet_router_checker(void *arg)
{
struct lnet_peer *rtr;
struct list_head *entry;
cfs_block_allsigs();
while (the_lnet.ln_rc_state == LNET_RC_STATE_RUNNING) {
__u64 version;
int cpt;
int cpt2;
cpt = lnet_net_lock_current();
rescan:
version = the_lnet.ln_routers_version;
list_for_each(entry, &the_lnet.ln_routers) {
rtr = list_entry(entry, struct lnet_peer, lp_rtr_list);
cpt2 = lnet_cpt_of_nid_locked(rtr->lp_nid);
if (cpt != cpt2) {
lnet_net_unlock(cpt);
cpt = cpt2;
lnet_net_lock(cpt);
if (version != the_lnet.ln_routers_version)
goto rescan;
}
lnet_ping_router_locked(rtr);
if (version != the_lnet.ln_routers_version) {
goto rescan;
}
}
if (the_lnet.ln_routing)
lnet_update_ni_status_locked();
lnet_net_unlock(cpt);
lnet_prune_rc_data(0);
if (!lnet_router_checker_active())
wait_event_interruptible(the_lnet.ln_rc_waitq,
lnet_router_checker_active());
else
wait_event_interruptible_timeout(the_lnet.ln_rc_waitq,
false,
cfs_time_seconds(1));
}
lnet_prune_rc_data(1);
the_lnet.ln_rc_state = LNET_RC_STATE_SHUTDOWN;
complete(&the_lnet.ln_rc_signal);
return 0;
}
void
lnet_destroy_rtrbuf(struct lnet_rtrbuf *rb, int npages)
{
int sz = offsetof(struct lnet_rtrbuf, rb_kiov[npages]);
while (--npages >= 0)
__free_page(rb->rb_kiov[npages].bv_page);
LIBCFS_FREE(rb, sz);
}
static struct lnet_rtrbuf *
lnet_new_rtrbuf(struct lnet_rtrbufpool *rbp, int cpt)
{
int npages = rbp->rbp_npages;
int sz = offsetof(struct lnet_rtrbuf, rb_kiov[npages]);
struct page *page;
struct lnet_rtrbuf *rb;
int i;
LIBCFS_CPT_ALLOC(rb, lnet_cpt_table(), cpt, sz);
if (!rb)
return NULL;
rb->rb_pool = rbp;
for (i = 0; i < npages; i++) {
page = alloc_pages_node(
cfs_cpt_spread_node(lnet_cpt_table(), cpt),
GFP_KERNEL | __GFP_ZERO, 0);
if (!page) {
while (--i >= 0)
__free_page(rb->rb_kiov[i].bv_page);
LIBCFS_FREE(rb, sz);
return NULL;
}
rb->rb_kiov[i].bv_len = PAGE_SIZE;
rb->rb_kiov[i].bv_offset = 0;
rb->rb_kiov[i].bv_page = page;
}
return rb;
}
static void
lnet_rtrpool_free_bufs(struct lnet_rtrbufpool *rbp, int cpt)
{
int npages = rbp->rbp_npages;
struct list_head tmp;
struct lnet_rtrbuf *rb;
struct lnet_rtrbuf *temp;
if (!rbp->rbp_nbuffers)
return;
INIT_LIST_HEAD(&tmp);
lnet_net_lock(cpt);
lnet_drop_routed_msgs_locked(&rbp->rbp_msgs, cpt);
list_splice_init(&rbp->rbp_bufs, &tmp);
rbp->rbp_req_nbuffers = 0;
rbp->rbp_nbuffers = 0;
rbp->rbp_credits = 0;
rbp->rbp_mincredits = 0;
lnet_net_unlock(cpt);
list_for_each_entry_safe(rb, temp, &tmp, rb_list) {
list_del(&rb->rb_list);
lnet_destroy_rtrbuf(rb, npages);
}
}
static int
lnet_rtrpool_adjust_bufs(struct lnet_rtrbufpool *rbp, int nbufs, int cpt)
{
struct list_head rb_list;
struct lnet_rtrbuf *rb;
int num_rb;
int num_buffers = 0;
int old_req_nbufs;
int npages = rbp->rbp_npages;
lnet_net_lock(cpt);
num_rb = nbufs - rbp->rbp_nbuffers;
if (nbufs <= rbp->rbp_req_nbuffers || num_rb <= 0) {
rbp->rbp_req_nbuffers = nbufs;
lnet_net_unlock(cpt);
return 0;
}
old_req_nbufs = rbp->rbp_req_nbuffers;
rbp->rbp_req_nbuffers = nbufs;
lnet_net_unlock(cpt);
INIT_LIST_HEAD(&rb_list);
while (num_rb-- > 0) {
rb = lnet_new_rtrbuf(rbp, cpt);
if (!rb) {
CERROR("Failed to allocate %d route bufs of %d pages\n",
nbufs, npages);
lnet_net_lock(cpt);
rbp->rbp_req_nbuffers = old_req_nbufs;
lnet_net_unlock(cpt);
goto failed;
}
list_add(&rb->rb_list, &rb_list);
num_buffers++;
}
lnet_net_lock(cpt);
list_splice_tail(&rb_list, &rbp->rbp_bufs);
rbp->rbp_nbuffers += num_buffers;
rbp->rbp_credits += num_buffers;
rbp->rbp_mincredits = rbp->rbp_credits;
while (!list_empty(&rbp->rbp_bufs) &&
!list_empty(&rbp->rbp_msgs))
lnet_schedule_blocked_locked(rbp);
lnet_net_unlock(cpt);
return 0;
failed:
while (!list_empty(&rb_list)) {
rb = list_entry(rb_list.next, struct lnet_rtrbuf, rb_list);
list_del(&rb->rb_list);
lnet_destroy_rtrbuf(rb, npages);
}
return -ENOMEM;
}
static void
lnet_rtrpool_init(struct lnet_rtrbufpool *rbp, int npages)
{
INIT_LIST_HEAD(&rbp->rbp_msgs);
INIT_LIST_HEAD(&rbp->rbp_bufs);
rbp->rbp_npages = npages;
rbp->rbp_credits = 0;
rbp->rbp_mincredits = 0;
}
void
lnet_rtrpools_free(int keep_pools)
{
struct lnet_rtrbufpool *rtrp;
int i;
if (!the_lnet.ln_rtrpools)
return;
cfs_percpt_for_each(rtrp, i, the_lnet.ln_rtrpools) {
lnet_rtrpool_free_bufs(&rtrp[LNET_TINY_BUF_IDX], i);
lnet_rtrpool_free_bufs(&rtrp[LNET_SMALL_BUF_IDX], i);
lnet_rtrpool_free_bufs(&rtrp[LNET_LARGE_BUF_IDX], i);
}
if (!keep_pools) {
cfs_percpt_free(the_lnet.ln_rtrpools);
the_lnet.ln_rtrpools = NULL;
}
}
static int
lnet_nrb_tiny_calculate(void)
{
int nrbs = LNET_NRB_TINY;
if (tiny_router_buffers < 0) {
LCONSOLE_ERROR_MSG(0x10c,
"tiny_router_buffers=%d invalid when routing enabled\n",
tiny_router_buffers);
return -EINVAL;
}
if (tiny_router_buffers > 0)
nrbs = tiny_router_buffers;
nrbs /= LNET_CPT_NUMBER;
return max(nrbs, LNET_NRB_TINY_MIN);
}
static int
lnet_nrb_small_calculate(void)
{
int nrbs = LNET_NRB_SMALL;
if (small_router_buffers < 0) {
LCONSOLE_ERROR_MSG(0x10c,
"small_router_buffers=%d invalid when routing enabled\n",
small_router_buffers);
return -EINVAL;
}
if (small_router_buffers > 0)
nrbs = small_router_buffers;
nrbs /= LNET_CPT_NUMBER;
return max(nrbs, LNET_NRB_SMALL_MIN);
}
static int
lnet_nrb_large_calculate(void)
{
int nrbs = LNET_NRB_LARGE;
if (large_router_buffers < 0) {
LCONSOLE_ERROR_MSG(0x10c,
"large_router_buffers=%d invalid when routing enabled\n",
large_router_buffers);
return -EINVAL;
}
if (large_router_buffers > 0)
nrbs = large_router_buffers;
nrbs /= LNET_CPT_NUMBER;
return max(nrbs, LNET_NRB_LARGE_MIN);
}
int
lnet_rtrpools_alloc(int im_a_router)
{
struct lnet_rtrbufpool *rtrp;
int nrb_tiny;
int nrb_small;
int nrb_large;
int rc;
int i;
if (!strcmp(forwarding, "")) {
if (!im_a_router)
return 0;
} else if (!strcmp(forwarding, "disabled")) {
return 0;
} else if (!strcmp(forwarding, "enabled")) {
} else {
LCONSOLE_ERROR_MSG(0x10b, "'forwarding' not set to either 'enabled' or 'disabled'\n");
return -EINVAL;
}
nrb_tiny = lnet_nrb_tiny_calculate();
if (nrb_tiny < 0)
return -EINVAL;
nrb_small = lnet_nrb_small_calculate();
if (nrb_small < 0)
return -EINVAL;
nrb_large = lnet_nrb_large_calculate();
if (nrb_large < 0)
return -EINVAL;
the_lnet.ln_rtrpools = cfs_percpt_alloc(lnet_cpt_table(),
LNET_NRBPOOLS *
sizeof(struct lnet_rtrbufpool));
if (!the_lnet.ln_rtrpools) {
LCONSOLE_ERROR_MSG(0x10c,
"Failed to initialize router buffe pool\n");
return -ENOMEM;
}
cfs_percpt_for_each(rtrp, i, the_lnet.ln_rtrpools) {
lnet_rtrpool_init(&rtrp[LNET_TINY_BUF_IDX], 0);
rc = lnet_rtrpool_adjust_bufs(&rtrp[LNET_TINY_BUF_IDX],
nrb_tiny, i);
if (rc)
goto failed;
lnet_rtrpool_init(&rtrp[LNET_SMALL_BUF_IDX],
LNET_NRB_SMALL_PAGES);
rc = lnet_rtrpool_adjust_bufs(&rtrp[LNET_SMALL_BUF_IDX],
nrb_small, i);
if (rc)
goto failed;
lnet_rtrpool_init(&rtrp[LNET_LARGE_BUF_IDX],
LNET_NRB_LARGE_PAGES);
rc = lnet_rtrpool_adjust_bufs(&rtrp[LNET_LARGE_BUF_IDX],
nrb_large, i);
if (rc)
goto failed;
}
lnet_net_lock(LNET_LOCK_EX);
the_lnet.ln_routing = 1;
lnet_net_unlock(LNET_LOCK_EX);
return 0;
failed:
lnet_rtrpools_free(0);
return rc;
}
static int
lnet_rtrpools_adjust_helper(int tiny, int small, int large)
{
int nrb = 0;
int rc = 0;
int i;
struct lnet_rtrbufpool *rtrp;
if (tiny >= 0) {
tiny_router_buffers = tiny;
nrb = lnet_nrb_tiny_calculate();
cfs_percpt_for_each(rtrp, i, the_lnet.ln_rtrpools) {
rc = lnet_rtrpool_adjust_bufs(&rtrp[LNET_TINY_BUF_IDX],
nrb, i);
if (rc)
return rc;
}
}
if (small >= 0) {
small_router_buffers = small;
nrb = lnet_nrb_small_calculate();
cfs_percpt_for_each(rtrp, i, the_lnet.ln_rtrpools) {
rc = lnet_rtrpool_adjust_bufs(&rtrp[LNET_SMALL_BUF_IDX],
nrb, i);
if (rc)
return rc;
}
}
if (large >= 0) {
large_router_buffers = large;
nrb = lnet_nrb_large_calculate();
cfs_percpt_for_each(rtrp, i, the_lnet.ln_rtrpools) {
rc = lnet_rtrpool_adjust_bufs(&rtrp[LNET_LARGE_BUF_IDX],
nrb, i);
if (rc)
return rc;
}
}
return 0;
}
int
lnet_rtrpools_adjust(int tiny, int small, int large)
{
if (!the_lnet.ln_routing)
return 0;
return lnet_rtrpools_adjust_helper(tiny, small, large);
}
int
lnet_rtrpools_enable(void)
{
int rc = 0;
if (the_lnet.ln_routing)
return 0;
if (!the_lnet.ln_rtrpools)
rc = lnet_rtrpools_alloc(1);
else
rc = lnet_rtrpools_adjust_helper(0, 0, 0);
if (rc)
return rc;
lnet_net_lock(LNET_LOCK_EX);
the_lnet.ln_routing = 1;
the_lnet.ln_ping_info->pi_features &= ~LNET_PING_FEAT_RTE_DISABLED;
lnet_net_unlock(LNET_LOCK_EX);
return rc;
}
void
lnet_rtrpools_disable(void)
{
if (!the_lnet.ln_routing)
return;
lnet_net_lock(LNET_LOCK_EX);
the_lnet.ln_routing = 0;
the_lnet.ln_ping_info->pi_features |= LNET_PING_FEAT_RTE_DISABLED;
tiny_router_buffers = 0;
small_router_buffers = 0;
large_router_buffers = 0;
lnet_net_unlock(LNET_LOCK_EX);
lnet_rtrpools_free(1);
}
int
lnet_notify(struct lnet_ni *ni, lnet_nid_t nid, int alive, unsigned long when)
{
struct lnet_peer *lp = NULL;
unsigned long now = cfs_time_current();
int cpt = lnet_cpt_of_nid(nid);
LASSERT(!in_interrupt());
CDEBUG(D_NET, "%s notifying %s: %s\n",
!ni ? "userspace" : libcfs_nid2str(ni->ni_nid),
libcfs_nid2str(nid),
alive ? "up" : "down");
if (ni &&
LNET_NIDNET(ni->ni_nid) != LNET_NIDNET(nid)) {
CWARN("Ignoring notification of %s %s by %s (different net)\n",
libcfs_nid2str(nid), alive ? "birth" : "death",
libcfs_nid2str(ni->ni_nid));
return -EINVAL;
}
if (cfs_time_after(when, now)) {
CWARN("Ignoring prediction from %s of %s %s %ld seconds in the future\n",
!ni ? "userspace" : libcfs_nid2str(ni->ni_nid),
libcfs_nid2str(nid), alive ? "up" : "down",
cfs_duration_sec(cfs_time_sub(when, now)));
return -EINVAL;
}
if (ni && !alive &&
!auto_down) {
CDEBUG(D_NET, "Auto-down disabled\n");
return 0;
}
lnet_net_lock(cpt);
if (the_lnet.ln_shutdown) {
lnet_net_unlock(cpt);
return -ESHUTDOWN;
}
lp = lnet_find_peer_locked(the_lnet.ln_peer_tables[cpt], nid);
if (!lp) {
lnet_net_unlock(cpt);
CDEBUG(D_NET, "%s not found\n", libcfs_nid2str(nid));
return 0;
}
if (ni && !alive && when < lp->lp_last_alive)
when = lp->lp_last_alive;
lnet_notify_locked(lp, !ni, alive, when);
if (ni)
lnet_ni_notify_locked(ni, lp);
lnet_peer_decref_locked(lp);
lnet_net_unlock(cpt);
return 0;
}
