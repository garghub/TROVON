static char *
lnet_get_routes(void)
{
return routes;
}
static char *
lnet_get_networks(void)
{
char *nets;
int rc;
if (*networks && *ip2nets) {
LCONSOLE_ERROR_MSG(0x101, "Please specify EITHER 'networks' or 'ip2nets' but not both at once\n");
return NULL;
}
if (*ip2nets) {
rc = lnet_parse_ip2nets(&nets, ip2nets);
return !rc ? nets : NULL;
}
if (*networks)
return networks;
return "tcp";
}
static void
lnet_init_locks(void)
{
spin_lock_init(&the_lnet.ln_eq_wait_lock);
init_waitqueue_head(&the_lnet.ln_eq_waitq);
init_waitqueue_head(&the_lnet.ln_rc_waitq);
mutex_init(&the_lnet.ln_lnd_mutex);
mutex_init(&the_lnet.ln_api_mutex);
}
static int
lnet_create_remote_nets_table(void)
{
int i;
struct list_head *hash;
LASSERT(!the_lnet.ln_remote_nets_hash);
LASSERT(the_lnet.ln_remote_nets_hbits > 0);
LIBCFS_ALLOC(hash, LNET_REMOTE_NETS_HASH_SIZE * sizeof(*hash));
if (!hash) {
CERROR("Failed to create remote nets hash table\n");
return -ENOMEM;
}
for (i = 0; i < LNET_REMOTE_NETS_HASH_SIZE; i++)
INIT_LIST_HEAD(&hash[i]);
the_lnet.ln_remote_nets_hash = hash;
return 0;
}
static void
lnet_destroy_remote_nets_table(void)
{
int i;
if (!the_lnet.ln_remote_nets_hash)
return;
for (i = 0; i < LNET_REMOTE_NETS_HASH_SIZE; i++)
LASSERT(list_empty(&the_lnet.ln_remote_nets_hash[i]));
LIBCFS_FREE(the_lnet.ln_remote_nets_hash,
LNET_REMOTE_NETS_HASH_SIZE *
sizeof(the_lnet.ln_remote_nets_hash[0]));
the_lnet.ln_remote_nets_hash = NULL;
}
static void
lnet_destroy_locks(void)
{
if (the_lnet.ln_res_lock) {
cfs_percpt_lock_free(the_lnet.ln_res_lock);
the_lnet.ln_res_lock = NULL;
}
if (the_lnet.ln_net_lock) {
cfs_percpt_lock_free(the_lnet.ln_net_lock);
the_lnet.ln_net_lock = NULL;
}
}
static int
lnet_create_locks(void)
{
lnet_init_locks();
the_lnet.ln_res_lock = cfs_percpt_lock_alloc(lnet_cpt_table());
if (!the_lnet.ln_res_lock)
goto failed;
the_lnet.ln_net_lock = cfs_percpt_lock_alloc(lnet_cpt_table());
if (!the_lnet.ln_net_lock)
goto failed;
return 0;
failed:
lnet_destroy_locks();
return -ENOMEM;
}
static void lnet_assert_wire_constants(void)
{
CLASSERT(LNET_PROTO_TCP_MAGIC == 0xeebc0ded);
CLASSERT(LNET_PROTO_TCP_VERSION_MAJOR == 1);
CLASSERT(LNET_PROTO_TCP_VERSION_MINOR == 0);
CLASSERT(LNET_MSG_ACK == 0);
CLASSERT(LNET_MSG_PUT == 1);
CLASSERT(LNET_MSG_GET == 2);
CLASSERT(LNET_MSG_REPLY == 3);
CLASSERT(LNET_MSG_HELLO == 4);
CLASSERT((int)sizeof(lnet_handle_wire_t) == 16);
CLASSERT((int)offsetof(lnet_handle_wire_t, wh_interface_cookie) == 0);
CLASSERT((int)sizeof(((lnet_handle_wire_t *)0)->wh_interface_cookie) == 8);
CLASSERT((int)offsetof(lnet_handle_wire_t, wh_object_cookie) == 8);
CLASSERT((int)sizeof(((lnet_handle_wire_t *)0)->wh_object_cookie) == 8);
CLASSERT((int)sizeof(lnet_magicversion_t) == 8);
CLASSERT((int)offsetof(lnet_magicversion_t, magic) == 0);
CLASSERT((int)sizeof(((lnet_magicversion_t *)0)->magic) == 4);
CLASSERT((int)offsetof(lnet_magicversion_t, version_major) == 4);
CLASSERT((int)sizeof(((lnet_magicversion_t *)0)->version_major) == 2);
CLASSERT((int)offsetof(lnet_magicversion_t, version_minor) == 6);
CLASSERT((int)sizeof(((lnet_magicversion_t *)0)->version_minor) == 2);
CLASSERT((int)sizeof(lnet_hdr_t) == 72);
CLASSERT((int)offsetof(lnet_hdr_t, dest_nid) == 0);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->dest_nid) == 8);
CLASSERT((int)offsetof(lnet_hdr_t, src_nid) == 8);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->src_nid) == 8);
CLASSERT((int)offsetof(lnet_hdr_t, dest_pid) == 16);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->dest_pid) == 4);
CLASSERT((int)offsetof(lnet_hdr_t, src_pid) == 20);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->src_pid) == 4);
CLASSERT((int)offsetof(lnet_hdr_t, type) == 24);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->type) == 4);
CLASSERT((int)offsetof(lnet_hdr_t, payload_length) == 28);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->payload_length) == 4);
CLASSERT((int)offsetof(lnet_hdr_t, msg) == 32);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->msg) == 40);
CLASSERT((int)offsetof(lnet_hdr_t, msg.ack.dst_wmd) == 32);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->msg.ack.dst_wmd) == 16);
CLASSERT((int)offsetof(lnet_hdr_t, msg.ack.match_bits) == 48);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->msg.ack.match_bits) == 8);
CLASSERT((int)offsetof(lnet_hdr_t, msg.ack.mlength) == 56);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->msg.ack.mlength) == 4);
CLASSERT((int)offsetof(lnet_hdr_t, msg.put.ack_wmd) == 32);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->msg.put.ack_wmd) == 16);
CLASSERT((int)offsetof(lnet_hdr_t, msg.put.match_bits) == 48);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->msg.put.match_bits) == 8);
CLASSERT((int)offsetof(lnet_hdr_t, msg.put.hdr_data) == 56);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->msg.put.hdr_data) == 8);
CLASSERT((int)offsetof(lnet_hdr_t, msg.put.ptl_index) == 64);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->msg.put.ptl_index) == 4);
CLASSERT((int)offsetof(lnet_hdr_t, msg.put.offset) == 68);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->msg.put.offset) == 4);
CLASSERT((int)offsetof(lnet_hdr_t, msg.get.return_wmd) == 32);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->msg.get.return_wmd) == 16);
CLASSERT((int)offsetof(lnet_hdr_t, msg.get.match_bits) == 48);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->msg.get.match_bits) == 8);
CLASSERT((int)offsetof(lnet_hdr_t, msg.get.ptl_index) == 56);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->msg.get.ptl_index) == 4);
CLASSERT((int)offsetof(lnet_hdr_t, msg.get.src_offset) == 60);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->msg.get.src_offset) == 4);
CLASSERT((int)offsetof(lnet_hdr_t, msg.get.sink_length) == 64);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->msg.get.sink_length) == 4);
CLASSERT((int)offsetof(lnet_hdr_t, msg.reply.dst_wmd) == 32);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->msg.reply.dst_wmd) == 16);
CLASSERT((int)offsetof(lnet_hdr_t, msg.hello.incarnation) == 32);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->msg.hello.incarnation) == 8);
CLASSERT((int)offsetof(lnet_hdr_t, msg.hello.type) == 40);
CLASSERT((int)sizeof(((lnet_hdr_t *)0)->msg.hello.type) == 4);
}
static lnd_t *
lnet_find_lnd_by_type(__u32 type)
{
lnd_t *lnd;
struct list_head *tmp;
list_for_each(tmp, &the_lnet.ln_lnds) {
lnd = list_entry(tmp, lnd_t, lnd_list);
if (lnd->lnd_type == type)
return lnd;
}
return NULL;
}
void
lnet_register_lnd(lnd_t *lnd)
{
mutex_lock(&the_lnet.ln_lnd_mutex);
LASSERT(libcfs_isknown_lnd(lnd->lnd_type));
LASSERT(!lnet_find_lnd_by_type(lnd->lnd_type));
list_add_tail(&lnd->lnd_list, &the_lnet.ln_lnds);
lnd->lnd_refcount = 0;
CDEBUG(D_NET, "%s LND registered\n", libcfs_lnd2str(lnd->lnd_type));
mutex_unlock(&the_lnet.ln_lnd_mutex);
}
void
lnet_unregister_lnd(lnd_t *lnd)
{
mutex_lock(&the_lnet.ln_lnd_mutex);
LASSERT(lnet_find_lnd_by_type(lnd->lnd_type) == lnd);
LASSERT(!lnd->lnd_refcount);
list_del(&lnd->lnd_list);
CDEBUG(D_NET, "%s LND unregistered\n", libcfs_lnd2str(lnd->lnd_type));
mutex_unlock(&the_lnet.ln_lnd_mutex);
}
void
lnet_counters_get(lnet_counters_t *counters)
{
lnet_counters_t *ctr;
int i;
memset(counters, 0, sizeof(*counters));
lnet_net_lock(LNET_LOCK_EX);
cfs_percpt_for_each(ctr, i, the_lnet.ln_counters) {
counters->msgs_max += ctr->msgs_max;
counters->msgs_alloc += ctr->msgs_alloc;
counters->errors += ctr->errors;
counters->send_count += ctr->send_count;
counters->recv_count += ctr->recv_count;
counters->route_count += ctr->route_count;
counters->drop_count += ctr->drop_count;
counters->send_length += ctr->send_length;
counters->recv_length += ctr->recv_length;
counters->route_length += ctr->route_length;
counters->drop_length += ctr->drop_length;
}
lnet_net_unlock(LNET_LOCK_EX);
}
void
lnet_counters_reset(void)
{
lnet_counters_t *counters;
int i;
lnet_net_lock(LNET_LOCK_EX);
cfs_percpt_for_each(counters, i, the_lnet.ln_counters)
memset(counters, 0, sizeof(lnet_counters_t));
lnet_net_unlock(LNET_LOCK_EX);
}
static char *
lnet_res_type2str(int type)
{
switch (type) {
default:
LBUG();
case LNET_COOKIE_TYPE_MD:
return "MD";
case LNET_COOKIE_TYPE_ME:
return "ME";
case LNET_COOKIE_TYPE_EQ:
return "EQ";
}
}
static void
lnet_res_container_cleanup(struct lnet_res_container *rec)
{
int count = 0;
if (!rec->rec_type)
return;
while (!list_empty(&rec->rec_active)) {
struct list_head *e = rec->rec_active.next;
list_del_init(e);
if (rec->rec_type == LNET_COOKIE_TYPE_EQ) {
lnet_eq_free(list_entry(e, lnet_eq_t, eq_list));
} else if (rec->rec_type == LNET_COOKIE_TYPE_MD) {
lnet_md_free(list_entry(e, lnet_libmd_t, md_list));
} else {
LBUG();
}
count++;
}
if (count > 0) {
CERROR("%d active elements on exit of %s container\n",
count, lnet_res_type2str(rec->rec_type));
}
if (rec->rec_lh_hash) {
LIBCFS_FREE(rec->rec_lh_hash,
LNET_LH_HASH_SIZE * sizeof(rec->rec_lh_hash[0]));
rec->rec_lh_hash = NULL;
}
rec->rec_type = 0;
}
static int
lnet_res_container_setup(struct lnet_res_container *rec, int cpt, int type)
{
int rc = 0;
int i;
LASSERT(!rec->rec_type);
rec->rec_type = type;
INIT_LIST_HEAD(&rec->rec_active);
rec->rec_lh_cookie = (cpt << LNET_COOKIE_TYPE_BITS) | type;
LIBCFS_CPT_ALLOC(rec->rec_lh_hash, lnet_cpt_table(), cpt,
LNET_LH_HASH_SIZE * sizeof(rec->rec_lh_hash[0]));
if (!rec->rec_lh_hash) {
rc = -ENOMEM;
goto out;
}
for (i = 0; i < LNET_LH_HASH_SIZE; i++)
INIT_LIST_HEAD(&rec->rec_lh_hash[i]);
return 0;
out:
CERROR("Failed to setup %s resource container\n",
lnet_res_type2str(type));
lnet_res_container_cleanup(rec);
return rc;
}
static void
lnet_res_containers_destroy(struct lnet_res_container **recs)
{
struct lnet_res_container *rec;
int i;
cfs_percpt_for_each(rec, i, recs)
lnet_res_container_cleanup(rec);
cfs_percpt_free(recs);
}
static struct lnet_res_container **
lnet_res_containers_create(int type)
{
struct lnet_res_container **recs;
struct lnet_res_container *rec;
int rc;
int i;
recs = cfs_percpt_alloc(lnet_cpt_table(), sizeof(*rec));
if (!recs) {
CERROR("Failed to allocate %s resource containers\n",
lnet_res_type2str(type));
return NULL;
}
cfs_percpt_for_each(rec, i, recs) {
rc = lnet_res_container_setup(rec, i, type);
if (rc) {
lnet_res_containers_destroy(recs);
return NULL;
}
}
return recs;
}
lnet_libhandle_t *
lnet_res_lh_lookup(struct lnet_res_container *rec, __u64 cookie)
{
struct list_head *head;
lnet_libhandle_t *lh;
unsigned int hash;
if ((cookie & LNET_COOKIE_MASK) != rec->rec_type)
return NULL;
hash = cookie >> (LNET_COOKIE_TYPE_BITS + LNET_CPT_BITS);
head = &rec->rec_lh_hash[hash & LNET_LH_HASH_MASK];
list_for_each_entry(lh, head, lh_hash_chain) {
if (lh->lh_cookie == cookie)
return lh;
}
return NULL;
}
void
lnet_res_lh_initialize(struct lnet_res_container *rec, lnet_libhandle_t *lh)
{
unsigned int ibits = LNET_COOKIE_TYPE_BITS + LNET_CPT_BITS;
unsigned int hash;
lh->lh_cookie = rec->rec_lh_cookie;
rec->rec_lh_cookie += 1 << ibits;
hash = (lh->lh_cookie >> ibits) & LNET_LH_HASH_MASK;
list_add(&lh->lh_hash_chain, &rec->rec_lh_hash[hash]);
}
static int
lnet_prepare(lnet_pid_t requested_pid)
{
struct lnet_res_container **recs;
int rc = 0;
if (requested_pid == LNET_PID_ANY) {
return -ENETDOWN;
}
LASSERT(!the_lnet.ln_refcount);
the_lnet.ln_routing = 0;
LASSERT(!(requested_pid & LNET_PID_USERFLAG));
the_lnet.ln_pid = requested_pid;
INIT_LIST_HEAD(&the_lnet.ln_test_peers);
INIT_LIST_HEAD(&the_lnet.ln_nis);
INIT_LIST_HEAD(&the_lnet.ln_nis_cpt);
INIT_LIST_HEAD(&the_lnet.ln_nis_zombie);
INIT_LIST_HEAD(&the_lnet.ln_routers);
INIT_LIST_HEAD(&the_lnet.ln_drop_rules);
INIT_LIST_HEAD(&the_lnet.ln_delay_rules);
rc = lnet_create_remote_nets_table();
if (rc)
goto failed;
the_lnet.ln_interface_cookie = ktime_get_ns();
the_lnet.ln_counters = cfs_percpt_alloc(lnet_cpt_table(),
sizeof(lnet_counters_t));
if (!the_lnet.ln_counters) {
CERROR("Failed to allocate counters for LNet\n");
rc = -ENOMEM;
goto failed;
}
rc = lnet_peer_tables_create();
if (rc)
goto failed;
rc = lnet_msg_containers_create();
if (rc)
goto failed;
rc = lnet_res_container_setup(&the_lnet.ln_eq_container, 0,
LNET_COOKIE_TYPE_EQ);
if (rc)
goto failed;
recs = lnet_res_containers_create(LNET_COOKIE_TYPE_ME);
if (!recs) {
rc = -ENOMEM;
goto failed;
}
the_lnet.ln_me_containers = recs;
recs = lnet_res_containers_create(LNET_COOKIE_TYPE_MD);
if (!recs) {
rc = -ENOMEM;
goto failed;
}
the_lnet.ln_md_containers = recs;
rc = lnet_portals_create();
if (rc) {
CERROR("Failed to create portals for LNet: %d\n", rc);
goto failed;
}
return 0;
failed:
lnet_unprepare();
return rc;
}
static int
lnet_unprepare(void)
{
lnet_fail_nid(LNET_NID_ANY, 0);
LASSERT(!the_lnet.ln_refcount);
LASSERT(list_empty(&the_lnet.ln_test_peers));
LASSERT(list_empty(&the_lnet.ln_nis));
LASSERT(list_empty(&the_lnet.ln_nis_cpt));
LASSERT(list_empty(&the_lnet.ln_nis_zombie));
lnet_portals_destroy();
if (the_lnet.ln_md_containers) {
lnet_res_containers_destroy(the_lnet.ln_md_containers);
the_lnet.ln_md_containers = NULL;
}
if (the_lnet.ln_me_containers) {
lnet_res_containers_destroy(the_lnet.ln_me_containers);
the_lnet.ln_me_containers = NULL;
}
lnet_res_container_cleanup(&the_lnet.ln_eq_container);
lnet_msg_containers_destroy();
lnet_peer_tables_destroy();
lnet_rtrpools_free(0);
if (the_lnet.ln_counters) {
cfs_percpt_free(the_lnet.ln_counters);
the_lnet.ln_counters = NULL;
}
lnet_destroy_remote_nets_table();
return 0;
}
lnet_ni_t *
lnet_net2ni_locked(__u32 net, int cpt)
{
struct list_head *tmp;
lnet_ni_t *ni;
LASSERT(cpt != LNET_LOCK_EX);
list_for_each(tmp, &the_lnet.ln_nis) {
ni = list_entry(tmp, lnet_ni_t, ni_list);
if (LNET_NIDNET(ni->ni_nid) == net) {
lnet_ni_addref_locked(ni, cpt);
return ni;
}
}
return NULL;
}
lnet_ni_t *
lnet_net2ni(__u32 net)
{
lnet_ni_t *ni;
lnet_net_lock(0);
ni = lnet_net2ni_locked(net, 0);
lnet_net_unlock(0);
return ni;
}
static unsigned int
lnet_nid_cpt_hash(lnet_nid_t nid, unsigned int number)
{
__u64 key = nid;
unsigned int val;
LASSERT(number >= 1 && number <= LNET_CPT_NUMBER);
if (number == 1)
return 0;
val = hash_long(key, LNET_CPT_BITS);
if (val < number)
return val;
return (unsigned int)(key + val + (val >> 1)) % number;
}
int
lnet_cpt_of_nid_locked(lnet_nid_t nid)
{
struct lnet_ni *ni;
if (LNET_CPT_NUMBER == 1)
return 0;
if (!list_empty(&the_lnet.ln_nis_cpt)) {
list_for_each_entry(ni, &the_lnet.ln_nis_cpt, ni_cptlist) {
if (LNET_NIDNET(ni->ni_nid) != LNET_NIDNET(nid))
continue;
LASSERT(ni->ni_cpts);
return ni->ni_cpts[lnet_nid_cpt_hash
(nid, ni->ni_ncpts)];
}
}
return lnet_nid_cpt_hash(nid, LNET_CPT_NUMBER);
}
int
lnet_cpt_of_nid(lnet_nid_t nid)
{
int cpt;
int cpt2;
if (LNET_CPT_NUMBER == 1)
return 0;
if (list_empty(&the_lnet.ln_nis_cpt))
return lnet_nid_cpt_hash(nid, LNET_CPT_NUMBER);
cpt = lnet_net_lock_current();
cpt2 = lnet_cpt_of_nid_locked(nid);
lnet_net_unlock(cpt);
return cpt2;
}
int
lnet_islocalnet(__u32 net)
{
struct lnet_ni *ni;
int cpt;
cpt = lnet_net_lock_current();
ni = lnet_net2ni_locked(net, cpt);
if (ni)
lnet_ni_decref_locked(ni, cpt);
lnet_net_unlock(cpt);
return !!ni;
}
lnet_ni_t *
lnet_nid2ni_locked(lnet_nid_t nid, int cpt)
{
struct lnet_ni *ni;
struct list_head *tmp;
LASSERT(cpt != LNET_LOCK_EX);
list_for_each(tmp, &the_lnet.ln_nis) {
ni = list_entry(tmp, lnet_ni_t, ni_list);
if (ni->ni_nid == nid) {
lnet_ni_addref_locked(ni, cpt);
return ni;
}
}
return NULL;
}
int
lnet_islocalnid(lnet_nid_t nid)
{
struct lnet_ni *ni;
int cpt;
cpt = lnet_net_lock_current();
ni = lnet_nid2ni_locked(nid, cpt);
if (ni)
lnet_ni_decref_locked(ni, cpt);
lnet_net_unlock(cpt);
return !!ni;
}
int
lnet_count_acceptor_nis(void)
{
int count = 0;
struct list_head *tmp;
struct lnet_ni *ni;
int cpt;
cpt = lnet_net_lock_current();
list_for_each(tmp, &the_lnet.ln_nis) {
ni = list_entry(tmp, lnet_ni_t, ni_list);
if (ni->ni_lnd->lnd_accept)
count++;
}
lnet_net_unlock(cpt);
return count;
}
static lnet_ping_info_t *
lnet_ping_info_create(int num_ni)
{
lnet_ping_info_t *ping_info;
unsigned int infosz;
infosz = offsetof(lnet_ping_info_t, pi_ni[num_ni]);
LIBCFS_ALLOC(ping_info, infosz);
if (!ping_info) {
CERROR("Can't allocate ping info[%d]\n", num_ni);
return NULL;
}
ping_info->pi_nnis = num_ni;
ping_info->pi_pid = the_lnet.ln_pid;
ping_info->pi_magic = LNET_PROTO_PING_MAGIC;
ping_info->pi_features = LNET_PING_FEAT_NI_STATUS;
return ping_info;
}
static inline int
lnet_get_ni_count(void)
{
struct lnet_ni *ni;
int count = 0;
lnet_net_lock(0);
list_for_each_entry(ni, &the_lnet.ln_nis, ni_list)
count++;
lnet_net_unlock(0);
return count;
}
static inline void
lnet_ping_info_free(lnet_ping_info_t *pinfo)
{
LIBCFS_FREE(pinfo,
offsetof(lnet_ping_info_t,
pi_ni[pinfo->pi_nnis]));
}
static void
lnet_ping_info_destroy(void)
{
struct lnet_ni *ni;
lnet_net_lock(LNET_LOCK_EX);
list_for_each_entry(ni, &the_lnet.ln_nis, ni_list) {
lnet_ni_lock(ni);
ni->ni_status = NULL;
lnet_ni_unlock(ni);
}
lnet_ping_info_free(the_lnet.ln_ping_info);
the_lnet.ln_ping_info = NULL;
lnet_net_unlock(LNET_LOCK_EX);
}
static void
lnet_ping_event_handler(lnet_event_t *event)
{
lnet_ping_info_t *pinfo = event->md.user_ptr;
if (event->unlinked)
pinfo->pi_features = LNET_PING_FEAT_INVAL;
}
static int
lnet_ping_info_setup(lnet_ping_info_t **ppinfo, lnet_handle_md_t *md_handle,
int ni_count, bool set_eq)
{
lnet_process_id_t id = {LNET_NID_ANY, LNET_PID_ANY};
lnet_handle_me_t me_handle;
lnet_md_t md = { NULL };
int rc, rc2;
if (set_eq) {
rc = LNetEQAlloc(0, lnet_ping_event_handler,
&the_lnet.ln_ping_target_eq);
if (rc) {
CERROR("Can't allocate ping EQ: %d\n", rc);
return rc;
}
}
*ppinfo = lnet_ping_info_create(ni_count);
if (!*ppinfo) {
rc = -ENOMEM;
goto failed_0;
}
rc = LNetMEAttach(LNET_RESERVED_PORTAL, id,
LNET_PROTO_PING_MATCHBITS, 0,
LNET_UNLINK, LNET_INS_AFTER,
&me_handle);
if (rc) {
CERROR("Can't create ping ME: %d\n", rc);
goto failed_1;
}
md.start = *ppinfo;
md.length = offsetof(lnet_ping_info_t,
pi_ni[(*ppinfo)->pi_nnis]);
md.threshold = LNET_MD_THRESH_INF;
md.max_size = 0;
md.options = LNET_MD_OP_GET | LNET_MD_TRUNCATE |
LNET_MD_MANAGE_REMOTE;
md.user_ptr = NULL;
md.eq_handle = the_lnet.ln_ping_target_eq;
md.user_ptr = *ppinfo;
rc = LNetMDAttach(me_handle, md, LNET_RETAIN, md_handle);
if (rc) {
CERROR("Can't attach ping MD: %d\n", rc);
goto failed_2;
}
return 0;
failed_2:
rc2 = LNetMEUnlink(me_handle);
LASSERT(!rc2);
failed_1:
lnet_ping_info_free(*ppinfo);
*ppinfo = NULL;
failed_0:
if (set_eq)
LNetEQFree(the_lnet.ln_ping_target_eq);
return rc;
}
static void
lnet_ping_md_unlink(lnet_ping_info_t *pinfo, lnet_handle_md_t *md_handle)
{
sigset_t blocked = cfs_block_allsigs();
LNetMDUnlink(*md_handle);
LNetInvalidateHandle(md_handle);
while (pinfo->pi_features != LNET_PING_FEAT_INVAL) {
CDEBUG(D_NET, "Still waiting for ping MD to unlink\n");
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(cfs_time_seconds(1));
}
cfs_restore_sigs(blocked);
}
static void
lnet_ping_info_install_locked(lnet_ping_info_t *ping_info)
{
lnet_ni_status_t *ns;
lnet_ni_t *ni;
int i = 0;
list_for_each_entry(ni, &the_lnet.ln_nis, ni_list) {
LASSERT(i < ping_info->pi_nnis);
ns = &ping_info->pi_ni[i];
ns->ns_nid = ni->ni_nid;
lnet_ni_lock(ni);
ns->ns_status = (ni->ni_status) ?
ni->ni_status->ns_status : LNET_NI_STATUS_UP;
ni->ni_status = ns;
lnet_ni_unlock(ni);
i++;
}
}
static void
lnet_ping_target_update(lnet_ping_info_t *pinfo, lnet_handle_md_t md_handle)
{
lnet_ping_info_t *old_pinfo = NULL;
lnet_handle_md_t old_md;
lnet_net_lock(LNET_LOCK_EX);
if (!the_lnet.ln_routing)
pinfo->pi_features |= LNET_PING_FEAT_RTE_DISABLED;
lnet_ping_info_install_locked(pinfo);
if (the_lnet.ln_ping_info) {
old_pinfo = the_lnet.ln_ping_info;
old_md = the_lnet.ln_ping_target_md;
}
the_lnet.ln_ping_target_md = md_handle;
the_lnet.ln_ping_info = pinfo;
lnet_net_unlock(LNET_LOCK_EX);
if (old_pinfo) {
lnet_ping_md_unlink(old_pinfo, &old_md);
lnet_ping_info_free(old_pinfo);
}
}
static void
lnet_ping_target_fini(void)
{
int rc;
lnet_ping_md_unlink(the_lnet.ln_ping_info,
&the_lnet.ln_ping_target_md);
rc = LNetEQFree(the_lnet.ln_ping_target_eq);
LASSERT(!rc);
lnet_ping_info_destroy();
}
static int
lnet_ni_tq_credits(lnet_ni_t *ni)
{
int credits;
LASSERT(ni->ni_ncpts >= 1);
if (ni->ni_ncpts == 1)
return ni->ni_maxtxcredits;
credits = ni->ni_maxtxcredits / ni->ni_ncpts;
credits = max(credits, 8 * ni->ni_peertxcredits);
credits = min(credits, ni->ni_maxtxcredits);
return credits;
}
static void
lnet_ni_unlink_locked(lnet_ni_t *ni)
{
if (!list_empty(&ni->ni_cptlist)) {
list_del_init(&ni->ni_cptlist);
lnet_ni_decref_locked(ni, 0);
}
LASSERT(!list_empty(&ni->ni_list));
list_move(&ni->ni_list, &the_lnet.ln_nis_zombie);
lnet_ni_decref_locked(ni, 0);
}
static void
lnet_clear_zombies_nis_locked(void)
{
int i;
int islo;
lnet_ni_t *ni;
lnet_ni_t *temp;
i = 2;
list_for_each_entry_safe(ni, temp, &the_lnet.ln_nis_zombie, ni_list) {
int *ref;
int j;
list_del_init(&ni->ni_list);
cfs_percpt_for_each(ref, j, ni->ni_refs) {
if (!*ref)
continue;
list_add(&ni->ni_list, &the_lnet.ln_nis_zombie);
break;
}
if (!list_empty(&ni->ni_list)) {
lnet_net_unlock(LNET_LOCK_EX);
++i;
if ((i & (-i)) == i) {
CDEBUG(D_WARNING, "Waiting for zombie LNI %s\n",
libcfs_nid2str(ni->ni_nid));
}
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(cfs_time_seconds(1));
lnet_net_lock(LNET_LOCK_EX);
continue;
}
ni->ni_lnd->lnd_refcount--;
lnet_net_unlock(LNET_LOCK_EX);
islo = ni->ni_lnd->lnd_type == LOLND;
LASSERT(!in_interrupt());
ni->ni_lnd->lnd_shutdown(ni);
if (!islo)
CDEBUG(D_LNI, "Removed LNI %s\n",
libcfs_nid2str(ni->ni_nid));
lnet_ni_free(ni);
i = 2;
lnet_net_lock(LNET_LOCK_EX);
}
}
static void
lnet_shutdown_lndnis(void)
{
lnet_ni_t *ni;
lnet_ni_t *temp;
int i;
LASSERT(!the_lnet.ln_shutdown);
LASSERT(!the_lnet.ln_refcount);
LASSERT(list_empty(&the_lnet.ln_nis_zombie));
lnet_net_lock(LNET_LOCK_EX);
the_lnet.ln_shutdown = 1;
list_for_each_entry_safe(ni, temp, &the_lnet.ln_nis, ni_list) {
lnet_ni_unlink_locked(ni);
}
if (the_lnet.ln_loni) {
lnet_ni_decref_locked(the_lnet.ln_loni, 0);
the_lnet.ln_loni = NULL;
}
lnet_net_unlock(LNET_LOCK_EX);
for (i = 0; i < the_lnet.ln_nportals; i++)
LNetClearLazyPortal(i);
lnet_peer_tables_cleanup(NULL);
lnet_net_lock(LNET_LOCK_EX);
lnet_clear_zombies_nis_locked();
the_lnet.ln_shutdown = 0;
lnet_net_unlock(LNET_LOCK_EX);
}
static void
lnet_shutdown_lndni(struct lnet_ni *ni)
{
int i;
lnet_net_lock(LNET_LOCK_EX);
lnet_ni_unlink_locked(ni);
lnet_net_unlock(LNET_LOCK_EX);
for (i = 0; i < the_lnet.ln_nportals; i++)
lnet_clear_lazy_portal(ni, i, "Shutting down NI");
lnet_peer_tables_cleanup(ni);
lnet_net_lock(LNET_LOCK_EX);
lnet_clear_zombies_nis_locked();
lnet_net_unlock(LNET_LOCK_EX);
}
static int
lnet_startup_lndni(struct lnet_ni *ni, struct lnet_ioctl_config_data *conf)
{
struct lnet_ioctl_config_lnd_tunables *lnd_tunables = NULL;
int rc = -EINVAL;
int lnd_type;
lnd_t *lnd;
struct lnet_tx_queue *tq;
int i;
lnd_type = LNET_NETTYP(LNET_NIDNET(ni->ni_nid));
LASSERT(libcfs_isknown_lnd(lnd_type));
if (lnd_type == CIBLND || lnd_type == OPENIBLND ||
lnd_type == IIBLND || lnd_type == VIBLND) {
CERROR("LND %s obsoleted\n", libcfs_lnd2str(lnd_type));
goto failed0;
}
lnet_net_lock(LNET_LOCK_EX);
rc = lnet_net_unique(LNET_NIDNET(ni->ni_nid), &the_lnet.ln_nis);
lnet_net_unlock(LNET_LOCK_EX);
if (!rc) {
if (lnd_type == LOLND) {
lnet_ni_free(ni);
return 0;
}
CERROR("Net %s is not unique\n",
libcfs_net2str(LNET_NIDNET(ni->ni_nid)));
rc = -EEXIST;
goto failed0;
}
mutex_lock(&the_lnet.ln_lnd_mutex);
lnd = lnet_find_lnd_by_type(lnd_type);
if (!lnd) {
mutex_unlock(&the_lnet.ln_lnd_mutex);
rc = request_module("%s", libcfs_lnd2modname(lnd_type));
mutex_lock(&the_lnet.ln_lnd_mutex);
lnd = lnet_find_lnd_by_type(lnd_type);
if (!lnd) {
mutex_unlock(&the_lnet.ln_lnd_mutex);
CERROR("Can't load LND %s, module %s, rc=%d\n",
libcfs_lnd2str(lnd_type),
libcfs_lnd2modname(lnd_type), rc);
rc = -EINVAL;
goto failed0;
}
}
lnet_net_lock(LNET_LOCK_EX);
lnd->lnd_refcount++;
lnet_net_unlock(LNET_LOCK_EX);
ni->ni_lnd = lnd;
if (conf && conf->cfg_hdr.ioc_len > sizeof(*conf))
lnd_tunables = (struct lnet_ioctl_config_lnd_tunables *)conf->cfg_bulk;
if (lnd_tunables) {
LIBCFS_ALLOC(ni->ni_lnd_tunables,
sizeof(*ni->ni_lnd_tunables));
if (!ni->ni_lnd_tunables) {
mutex_unlock(&the_lnet.ln_lnd_mutex);
rc = -ENOMEM;
goto failed0;
}
memcpy(ni->ni_lnd_tunables, lnd_tunables,
sizeof(*ni->ni_lnd_tunables));
}
if (conf) {
if (conf->cfg_config_u.cfg_net.net_peer_rtr_credits >= 0)
ni->ni_peerrtrcredits =
conf->cfg_config_u.cfg_net.net_peer_rtr_credits;
if (conf->cfg_config_u.cfg_net.net_peer_timeout >= 0)
ni->ni_peertimeout =
conf->cfg_config_u.cfg_net.net_peer_timeout;
if (conf->cfg_config_u.cfg_net.net_peer_tx_credits != -1)
ni->ni_peertxcredits =
conf->cfg_config_u.cfg_net.net_peer_tx_credits;
if (conf->cfg_config_u.cfg_net.net_max_tx_credits >= 0)
ni->ni_maxtxcredits =
conf->cfg_config_u.cfg_net.net_max_tx_credits;
}
rc = lnd->lnd_startup(ni);
mutex_unlock(&the_lnet.ln_lnd_mutex);
if (rc) {
LCONSOLE_ERROR_MSG(0x105, "Error %d starting up LNI %s\n",
rc, libcfs_lnd2str(lnd->lnd_type));
lnet_net_lock(LNET_LOCK_EX);
lnd->lnd_refcount--;
lnet_net_unlock(LNET_LOCK_EX);
goto failed0;
}
LASSERT(ni->ni_peertimeout <= 0 || lnd->lnd_query);
lnet_net_lock(LNET_LOCK_EX);
lnet_ni_addref_locked(ni, 0);
list_add_tail(&ni->ni_list, &the_lnet.ln_nis);
if (ni->ni_cpts) {
lnet_ni_addref_locked(ni, 0);
list_add_tail(&ni->ni_cptlist, &the_lnet.ln_nis_cpt);
}
lnet_net_unlock(LNET_LOCK_EX);
if (lnd->lnd_type == LOLND) {
lnet_ni_addref(ni);
LASSERT(!the_lnet.ln_loni);
the_lnet.ln_loni = ni;
return 0;
}
if (!ni->ni_peertxcredits || !ni->ni_maxtxcredits) {
LCONSOLE_ERROR_MSG(0x107, "LNI %s has no %scredits\n",
libcfs_lnd2str(lnd->lnd_type),
!ni->ni_peertxcredits ?
"" : "per-peer ");
lnet_shutdown_lndni(ni);
return -EINVAL;
}
cfs_percpt_for_each(tq, i, ni->ni_tx_queues) {
tq->tq_credits_min =
tq->tq_credits_max =
tq->tq_credits = lnet_ni_tq_credits(ni);
}
CDEBUG(D_LNI, "Added LNI %s [%d/%d/%d/%d]\n",
libcfs_nid2str(ni->ni_nid), ni->ni_peertxcredits,
lnet_ni_tq_credits(ni) * LNET_CPT_NUMBER,
ni->ni_peerrtrcredits, ni->ni_peertimeout);
return 0;
failed0:
lnet_ni_free(ni);
return rc;
}
static int
lnet_startup_lndnis(struct list_head *nilist)
{
struct lnet_ni *ni;
int rc;
int ni_count = 0;
while (!list_empty(nilist)) {
ni = list_entry(nilist->next, lnet_ni_t, ni_list);
list_del(&ni->ni_list);
rc = lnet_startup_lndni(ni, NULL);
if (rc < 0)
goto failed;
ni_count++;
}
return ni_count;
failed:
lnet_shutdown_lndnis();
return rc;
}
int lnet_lib_init(void)
{
int rc;
lnet_assert_wire_constants();
memset(&the_lnet, 0, sizeof(the_lnet));
the_lnet.ln_cpt_table = cfs_cpt_table;
the_lnet.ln_cpt_number = cfs_cpt_number(cfs_cpt_table);
LASSERT(the_lnet.ln_cpt_number > 0);
if (the_lnet.ln_cpt_number > LNET_CPT_MAX) {
CERROR("Can't have %d CPTs for LNet (max allowed is %d), please change setting of CPT-table and retry\n",
the_lnet.ln_cpt_number, LNET_CPT_MAX);
return -E2BIG;
}
while ((1 << the_lnet.ln_cpt_bits) < the_lnet.ln_cpt_number)
the_lnet.ln_cpt_bits++;
rc = lnet_create_locks();
if (rc) {
CERROR("Can't create LNet global locks: %d\n", rc);
return rc;
}
the_lnet.ln_refcount = 0;
LNetInvalidateHandle(&the_lnet.ln_rc_eqh);
INIT_LIST_HEAD(&the_lnet.ln_lnds);
INIT_LIST_HEAD(&the_lnet.ln_rcd_zombie);
INIT_LIST_HEAD(&the_lnet.ln_rcd_deathrow);
if (rnet_htable_size <= 0)
rnet_htable_size = LNET_REMOTE_NETS_HASH_DEFAULT;
else if (rnet_htable_size > LNET_REMOTE_NETS_HASH_MAX)
rnet_htable_size = LNET_REMOTE_NETS_HASH_MAX;
the_lnet.ln_remote_nets_hbits = max_t(int, 1,
order_base_2(rnet_htable_size) - 1);
lnet_register_lnd(&the_lolnd);
return 0;
}
void lnet_lib_exit(void)
{
LASSERT(!the_lnet.ln_refcount);
while (!list_empty(&the_lnet.ln_lnds))
lnet_unregister_lnd(list_entry(the_lnet.ln_lnds.next,
lnd_t, lnd_list));
lnet_destroy_locks();
}
int
LNetNIInit(lnet_pid_t requested_pid)
{
int im_a_router = 0;
int rc;
int ni_count;
lnet_ping_info_t *pinfo;
lnet_handle_md_t md_handle;
struct list_head net_head;
INIT_LIST_HEAD(&net_head);
mutex_lock(&the_lnet.ln_api_mutex);
CDEBUG(D_OTHER, "refs %d\n", the_lnet.ln_refcount);
if (the_lnet.ln_refcount > 0) {
rc = the_lnet.ln_refcount++;
mutex_unlock(&the_lnet.ln_api_mutex);
return rc;
}
rc = lnet_prepare(requested_pid);
if (rc) {
mutex_unlock(&the_lnet.ln_api_mutex);
return rc;
}
if (!lnet_ni_alloc(LNET_MKNET(LOLND, 0), NULL, &net_head)) {
rc = -ENOMEM;
goto err_empty_list;
}
if (!the_lnet.ln_nis_from_mod_params) {
rc = lnet_parse_networks(&net_head, lnet_get_networks());
if (rc < 0)
goto err_empty_list;
}
ni_count = lnet_startup_lndnis(&net_head);
if (ni_count < 0) {
rc = ni_count;
goto err_empty_list;
}
if (!the_lnet.ln_nis_from_mod_params) {
rc = lnet_parse_routes(lnet_get_routes(), &im_a_router);
if (rc)
goto err_shutdown_lndnis;
rc = lnet_check_routes();
if (rc)
goto err_destroy_routes;
rc = lnet_rtrpools_alloc(im_a_router);
if (rc)
goto err_destroy_routes;
}
rc = lnet_acceptor_start();
if (rc)
goto err_destroy_routes;
the_lnet.ln_refcount = 1;
rc = lnet_ping_info_setup(&pinfo, &md_handle, ni_count, true);
if (rc)
goto err_acceptor_stop;
lnet_ping_target_update(pinfo, md_handle);
rc = lnet_router_checker_start();
if (rc)
goto err_stop_ping;
lnet_fault_init();
lnet_router_debugfs_init();
mutex_unlock(&the_lnet.ln_api_mutex);
return 0;
err_stop_ping:
lnet_ping_target_fini();
err_acceptor_stop:
the_lnet.ln_refcount = 0;
lnet_acceptor_stop();
err_destroy_routes:
if (!the_lnet.ln_nis_from_mod_params)
lnet_destroy_routes();
err_shutdown_lndnis:
lnet_shutdown_lndnis();
err_empty_list:
lnet_unprepare();
LASSERT(rc < 0);
mutex_unlock(&the_lnet.ln_api_mutex);
while (!list_empty(&net_head)) {
struct lnet_ni *ni;
ni = list_entry(net_head.next, struct lnet_ni, ni_list);
list_del_init(&ni->ni_list);
lnet_ni_free(ni);
}
return rc;
}
int
LNetNIFini(void)
{
mutex_lock(&the_lnet.ln_api_mutex);
LASSERT(the_lnet.ln_refcount > 0);
if (the_lnet.ln_refcount != 1) {
the_lnet.ln_refcount--;
} else {
LASSERT(!the_lnet.ln_niinit_self);
lnet_fault_fini();
lnet_router_debugfs_fini();
lnet_router_checker_stop();
lnet_ping_target_fini();
the_lnet.ln_refcount = 0;
lnet_acceptor_stop();
lnet_destroy_routes();
lnet_shutdown_lndnis();
lnet_unprepare();
}
mutex_unlock(&the_lnet.ln_api_mutex);
return 0;
}
static void
lnet_fill_ni_info(struct lnet_ni *ni, struct lnet_ioctl_config_data *config)
{
struct lnet_ioctl_config_lnd_tunables *lnd_cfg = NULL;
struct lnet_ioctl_net_config *net_config;
size_t min_size, tunable_size = 0;
int i;
if (!ni || !config)
return;
net_config = (struct lnet_ioctl_net_config *)config->cfg_bulk;
if (!net_config)
return;
BUILD_BUG_ON(ARRAY_SIZE(ni->ni_interfaces) !=
ARRAY_SIZE(net_config->ni_interfaces));
for (i = 0; i < ARRAY_SIZE(ni->ni_interfaces); i++) {
if (!ni->ni_interfaces[i])
break;
strncpy(net_config->ni_interfaces[i],
ni->ni_interfaces[i],
sizeof(net_config->ni_interfaces[i]));
}
config->cfg_nid = ni->ni_nid;
config->cfg_config_u.cfg_net.net_peer_timeout = ni->ni_peertimeout;
config->cfg_config_u.cfg_net.net_max_tx_credits = ni->ni_maxtxcredits;
config->cfg_config_u.cfg_net.net_peer_tx_credits = ni->ni_peertxcredits;
config->cfg_config_u.cfg_net.net_peer_rtr_credits = ni->ni_peerrtrcredits;
net_config->ni_status = ni->ni_status->ns_status;
if (ni->ni_cpts) {
int num_cpts = min(ni->ni_ncpts, LNET_MAX_SHOW_NUM_CPT);
for (i = 0; i < num_cpts; i++)
net_config->ni_cpts[i] = ni->ni_cpts[i];
config->cfg_ncpts = num_cpts;
}
min_size = sizeof(*config) + sizeof(*net_config);
if (config->cfg_hdr.ioc_len > min_size)
tunable_size = config->cfg_hdr.ioc_len - min_size;
min_size = min(tunable_size, sizeof(*ni->ni_lnd_tunables));
lnd_cfg = (struct lnet_ioctl_config_lnd_tunables *)net_config->cfg_bulk;
if (ni->ni_lnd_tunables && lnd_cfg && min_size) {
memcpy(lnd_cfg, ni->ni_lnd_tunables, min_size);
config->cfg_config_u.cfg_net.net_interface_count = 1;
if (tunable_size > sizeof(*ni->ni_lnd_tunables)) {
min_size = tunable_size - sizeof(ni->ni_lnd_tunables);
config->cfg_hdr.ioc_len -= min_size;
}
}
}
static int
lnet_get_net_config(struct lnet_ioctl_config_data *config)
{
struct lnet_ni *ni;
struct list_head *tmp;
int idx = config->cfg_count;
int cpt, i = 0;
int rc = -ENOENT;
cpt = lnet_net_lock_current();
list_for_each(tmp, &the_lnet.ln_nis) {
if (i++ != idx)
continue;
ni = list_entry(tmp, lnet_ni_t, ni_list);
lnet_ni_lock(ni);
lnet_fill_ni_info(ni, config);
lnet_ni_unlock(ni);
rc = 0;
break;
}
lnet_net_unlock(cpt);
return rc;
}
int
lnet_dyn_add_ni(lnet_pid_t requested_pid, struct lnet_ioctl_config_data *conf)
{
char *nets = conf->cfg_config_u.cfg_net.net_intf;
lnet_ping_info_t *pinfo;
lnet_handle_md_t md_handle;
struct lnet_ni *ni;
struct list_head net_head;
lnet_remotenet_t *rnet;
int rc;
INIT_LIST_HEAD(&net_head);
rc = lnet_parse_networks(&net_head, nets);
if (rc <= 0)
return !rc ? -EINVAL : rc;
mutex_lock(&the_lnet.ln_api_mutex);
if (rc > 1) {
rc = -EINVAL;
goto failed0;
}
ni = list_entry(net_head.next, struct lnet_ni, ni_list);
lnet_net_lock(LNET_LOCK_EX);
rnet = lnet_find_net_locked(LNET_NIDNET(ni->ni_nid));
lnet_net_unlock(LNET_LOCK_EX);
if (rnet) {
CERROR("Adding net %s will invalidate routing configuration\n",
nets);
rc = -EUSERS;
goto failed0;
}
rc = lnet_ping_info_setup(&pinfo, &md_handle, 1 + lnet_get_ni_count(),
false);
if (rc)
goto failed0;
list_del_init(&ni->ni_list);
rc = lnet_startup_lndni(ni, conf);
if (rc)
goto failed1;
if (ni->ni_lnd->lnd_accept) {
rc = lnet_acceptor_start();
if (rc < 0) {
CERROR("Failed to start up acceptor thread\n");
lnet_shutdown_lndni(ni);
goto failed1;
}
}
lnet_ping_target_update(pinfo, md_handle);
mutex_unlock(&the_lnet.ln_api_mutex);
return 0;
failed1:
lnet_ping_md_unlink(pinfo, &md_handle);
lnet_ping_info_free(pinfo);
failed0:
mutex_unlock(&the_lnet.ln_api_mutex);
while (!list_empty(&net_head)) {
ni = list_entry(net_head.next, struct lnet_ni, ni_list);
list_del_init(&ni->ni_list);
lnet_ni_free(ni);
}
return rc;
}
int
lnet_dyn_del_ni(__u32 net)
{
lnet_ni_t *ni;
lnet_ping_info_t *pinfo;
lnet_handle_md_t md_handle;
int rc;
if (LNET_NETTYP(net) == LOLND)
return -EINVAL;
mutex_lock(&the_lnet.ln_api_mutex);
rc = lnet_ping_info_setup(&pinfo, &md_handle,
lnet_get_ni_count() - 1, false);
if (rc)
goto out;
ni = lnet_net2ni(net);
if (!ni) {
rc = -EINVAL;
goto failed;
}
lnet_ni_decref_locked(ni, 0);
lnet_shutdown_lndni(ni);
if (!lnet_count_acceptor_nis())
lnet_acceptor_stop();
lnet_ping_target_update(pinfo, md_handle);
goto out;
failed:
lnet_ping_md_unlink(pinfo, &md_handle);
lnet_ping_info_free(pinfo);
out:
mutex_unlock(&the_lnet.ln_api_mutex);
return rc;
}
int
LNetCtl(unsigned int cmd, void *arg)
{
struct libcfs_ioctl_data *data = arg;
struct lnet_ioctl_config_data *config;
lnet_process_id_t id = {0};
lnet_ni_t *ni;
int rc;
unsigned long secs_passed;
BUILD_BUG_ON(LIBCFS_IOC_DATA_MAX <
sizeof(struct lnet_ioctl_net_config) +
sizeof(struct lnet_ioctl_config_data));
switch (cmd) {
case IOC_LIBCFS_GET_NI:
rc = LNetGetId(data->ioc_count, &id);
data->ioc_nid = id.nid;
return rc;
case IOC_LIBCFS_FAIL_NID:
return lnet_fail_nid(data->ioc_nid, data->ioc_count);
case IOC_LIBCFS_ADD_ROUTE:
config = arg;
if (config->cfg_hdr.ioc_len < sizeof(*config))
return -EINVAL;
mutex_lock(&the_lnet.ln_api_mutex);
rc = lnet_add_route(config->cfg_net,
config->cfg_config_u.cfg_route.rtr_hop,
config->cfg_nid,
config->cfg_config_u.cfg_route.rtr_priority);
if (!rc) {
rc = lnet_check_routes();
if (rc)
lnet_del_route(config->cfg_net,
config->cfg_nid);
}
mutex_unlock(&the_lnet.ln_api_mutex);
return rc;
case IOC_LIBCFS_DEL_ROUTE:
config = arg;
if (config->cfg_hdr.ioc_len < sizeof(*config))
return -EINVAL;
mutex_lock(&the_lnet.ln_api_mutex);
rc = lnet_del_route(config->cfg_net, config->cfg_nid);
mutex_unlock(&the_lnet.ln_api_mutex);
return rc;
case IOC_LIBCFS_GET_ROUTE:
config = arg;
if (config->cfg_hdr.ioc_len < sizeof(*config))
return -EINVAL;
return lnet_get_route(config->cfg_count,
&config->cfg_net,
&config->cfg_config_u.cfg_route.rtr_hop,
&config->cfg_nid,
&config->cfg_config_u.cfg_route.rtr_flags,
&config->cfg_config_u.cfg_route.rtr_priority);
case IOC_LIBCFS_GET_NET: {
size_t total = sizeof(*config) +
sizeof(struct lnet_ioctl_net_config);
config = arg;
if (config->cfg_hdr.ioc_len < total)
return -EINVAL;
return lnet_get_net_config(config);
}
case IOC_LIBCFS_GET_LNET_STATS: {
struct lnet_ioctl_lnet_stats *lnet_stats = arg;
if (lnet_stats->st_hdr.ioc_len < sizeof(*lnet_stats))
return -EINVAL;
lnet_counters_get(&lnet_stats->st_cntrs);
return 0;
}
case IOC_LIBCFS_CONFIG_RTR:
config = arg;
if (config->cfg_hdr.ioc_len < sizeof(*config))
return -EINVAL;
mutex_lock(&the_lnet.ln_api_mutex);
if (config->cfg_config_u.cfg_buffers.buf_enable) {
rc = lnet_rtrpools_enable();
mutex_unlock(&the_lnet.ln_api_mutex);
return rc;
}
lnet_rtrpools_disable();
mutex_unlock(&the_lnet.ln_api_mutex);
return 0;
case IOC_LIBCFS_ADD_BUF:
config = arg;
if (config->cfg_hdr.ioc_len < sizeof(*config))
return -EINVAL;
mutex_lock(&the_lnet.ln_api_mutex);
rc = lnet_rtrpools_adjust(config->cfg_config_u.cfg_buffers.buf_tiny,
config->cfg_config_u.cfg_buffers.buf_small,
config->cfg_config_u.cfg_buffers.buf_large);
mutex_unlock(&the_lnet.ln_api_mutex);
return rc;
case IOC_LIBCFS_GET_BUF: {
struct lnet_ioctl_pool_cfg *pool_cfg;
size_t total = sizeof(*config) + sizeof(*pool_cfg);
config = arg;
if (config->cfg_hdr.ioc_len < total)
return -EINVAL;
pool_cfg = (struct lnet_ioctl_pool_cfg *)config->cfg_bulk;
return lnet_get_rtr_pool_cfg(config->cfg_count, pool_cfg);
}
case IOC_LIBCFS_GET_PEER_INFO: {
struct lnet_ioctl_peer *peer_info = arg;
if (peer_info->pr_hdr.ioc_len < sizeof(*peer_info))
return -EINVAL;
return lnet_get_peer_info(peer_info->pr_count,
&peer_info->pr_nid,
peer_info->pr_lnd_u.pr_peer_credits.cr_aliveness,
&peer_info->pr_lnd_u.pr_peer_credits.cr_ncpt,
&peer_info->pr_lnd_u.pr_peer_credits.cr_refcount,
&peer_info->pr_lnd_u.pr_peer_credits.cr_ni_peer_tx_credits,
&peer_info->pr_lnd_u.pr_peer_credits.cr_peer_tx_credits,
&peer_info->pr_lnd_u.pr_peer_credits.cr_peer_rtr_credits,
&peer_info->pr_lnd_u.pr_peer_credits.cr_peer_min_rtr_credits,
&peer_info->pr_lnd_u.pr_peer_credits.cr_peer_tx_qnob);
}
case IOC_LIBCFS_NOTIFY_ROUTER:
secs_passed = (ktime_get_real_seconds() - data->ioc_u64[0]);
secs_passed *= msecs_to_jiffies(MSEC_PER_SEC);
return lnet_notify(NULL, data->ioc_nid, data->ioc_flags,
jiffies - secs_passed);
case IOC_LIBCFS_LNET_DIST:
rc = LNetDist(data->ioc_nid, &data->ioc_nid, &data->ioc_u32[1]);
if (rc < 0 && rc != -EHOSTUNREACH)
return rc;
data->ioc_u32[0] = rc;
return 0;
case IOC_LIBCFS_TESTPROTOCOMPAT:
lnet_net_lock(LNET_LOCK_EX);
the_lnet.ln_testprotocompat = data->ioc_flags;
lnet_net_unlock(LNET_LOCK_EX);
return 0;
case IOC_LIBCFS_LNET_FAULT:
return lnet_fault_ctl(data->ioc_flags, data);
case IOC_LIBCFS_PING:
id.nid = data->ioc_nid;
id.pid = data->ioc_u32[0];
rc = lnet_ping(id, data->ioc_u32[1],
data->ioc_pbuf1,
data->ioc_plen1 / sizeof(lnet_process_id_t));
if (rc < 0)
return rc;
data->ioc_count = rc;
return 0;
default:
ni = lnet_net2ni(data->ioc_net);
if (!ni)
return -EINVAL;
if (!ni->ni_lnd->lnd_ctl)
rc = -EINVAL;
else
rc = ni->ni_lnd->lnd_ctl(ni, cmd, arg);
lnet_ni_decref(ni);
return rc;
}
}
void LNetDebugPeer(lnet_process_id_t id)
{
lnet_debug_peer(id.nid);
}
int
LNetGetId(unsigned int index, lnet_process_id_t *id)
{
struct lnet_ni *ni;
struct list_head *tmp;
int cpt;
int rc = -ENOENT;
LASSERT(the_lnet.ln_refcount > 0);
cpt = lnet_net_lock_current();
list_for_each(tmp, &the_lnet.ln_nis) {
if (index--)
continue;
ni = list_entry(tmp, lnet_ni_t, ni_list);
id->nid = ni->ni_nid;
id->pid = the_lnet.ln_pid;
rc = 0;
break;
}
lnet_net_unlock(cpt);
return rc;
}
void
LNetSnprintHandle(char *str, int len, lnet_handle_any_t h)
{
snprintf(str, len, "%#llx", h.cookie);
}
static int lnet_ping(lnet_process_id_t id, int timeout_ms,
lnet_process_id_t __user *ids, int n_ids)
{
lnet_handle_eq_t eqh;
lnet_handle_md_t mdh;
lnet_event_t event;
lnet_md_t md = { NULL };
int which;
int unlinked = 0;
int replied = 0;
const int a_long_time = 60000;
int infosz;
lnet_ping_info_t *info;
lnet_process_id_t tmpid;
int i;
int nob;
int rc;
int rc2;
sigset_t blocked;
infosz = offsetof(lnet_ping_info_t, pi_ni[n_ids]);
if (n_ids <= 0 ||
id.nid == LNET_NID_ANY ||
timeout_ms > 500000 ||
n_ids > 20)
return -EINVAL;
if (id.pid == LNET_PID_ANY)
id.pid = LNET_PID_LUSTRE;
LIBCFS_ALLOC(info, infosz);
if (!info)
return -ENOMEM;
rc = LNetEQAlloc(2, LNET_EQ_HANDLER_NONE, &eqh);
if (rc) {
CERROR("Can't allocate EQ: %d\n", rc);
goto out_0;
}
md.start = info;
md.length = infosz;
md.threshold = 2;
md.max_size = 0;
md.options = LNET_MD_TRUNCATE;
md.user_ptr = NULL;
md.eq_handle = eqh;
rc = LNetMDBind(md, LNET_UNLINK, &mdh);
if (rc) {
CERROR("Can't bind MD: %d\n", rc);
goto out_1;
}
rc = LNetGet(LNET_NID_ANY, mdh, id,
LNET_RESERVED_PORTAL,
LNET_PROTO_PING_MATCHBITS, 0);
if (rc) {
rc2 = LNetMDUnlink(mdh);
LASSERT(!rc2);
unlinked = 1;
timeout_ms = a_long_time;
}
do {
if (unlinked)
blocked = cfs_block_allsigs();
rc2 = LNetEQPoll(&eqh, 1, timeout_ms, &event, &which);
if (unlinked)
cfs_restore_sigs(blocked);
CDEBUG(D_NET, "poll %d(%d %d)%s\n", rc2,
(rc2 <= 0) ? -1 : event.type,
(rc2 <= 0) ? -1 : event.status,
(rc2 > 0 && event.unlinked) ? " unlinked" : "");
LASSERT(rc2 != -EOVERFLOW);
if (rc2 <= 0 || event.status) {
if (!replied && !rc)
rc = (rc2 < 0) ? rc2 :
!rc2 ? -ETIMEDOUT :
event.status;
if (!unlinked) {
LNetMDUnlink(mdh);
unlinked = 1;
timeout_ms = a_long_time;
} else if (!rc2) {
CWARN("ping %s: late network completion\n",
libcfs_id2str(id));
}
} else if (event.type == LNET_EVENT_REPLY) {
replied = 1;
rc = event.mlength;
}
} while (rc2 <= 0 || !event.unlinked);
if (!replied) {
if (rc >= 0)
CWARN("%s: Unexpected rc >= 0 but no reply!\n",
libcfs_id2str(id));
rc = -EIO;
goto out_1;
}
nob = rc;
LASSERT(nob >= 0 && nob <= infosz);
rc = -EPROTO;
if (nob < 8) {
CERROR("%s: ping info too short %d\n",
libcfs_id2str(id), nob);
goto out_1;
}
if (info->pi_magic == __swab32(LNET_PROTO_PING_MAGIC)) {
lnet_swap_pinginfo(info);
} else if (info->pi_magic != LNET_PROTO_PING_MAGIC) {
CERROR("%s: Unexpected magic %08x\n",
libcfs_id2str(id), info->pi_magic);
goto out_1;
}
if (!(info->pi_features & LNET_PING_FEAT_NI_STATUS)) {
CERROR("%s: ping w/o NI status: 0x%x\n",
libcfs_id2str(id), info->pi_features);
goto out_1;
}
if (nob < offsetof(lnet_ping_info_t, pi_ni[0])) {
CERROR("%s: Short reply %d(%d min)\n", libcfs_id2str(id),
nob, (int)offsetof(lnet_ping_info_t, pi_ni[0]));
goto out_1;
}
if (info->pi_nnis < n_ids)
n_ids = info->pi_nnis;
if (nob < offsetof(lnet_ping_info_t, pi_ni[n_ids])) {
CERROR("%s: Short reply %d(%d expected)\n", libcfs_id2str(id),
nob, (int)offsetof(lnet_ping_info_t, pi_ni[n_ids]));
goto out_1;
}
rc = -EFAULT;
memset(&tmpid, 0, sizeof(tmpid));
for (i = 0; i < n_ids; i++) {
tmpid.pid = info->pi_pid;
tmpid.nid = info->pi_ni[i].ns_nid;
if (copy_to_user(&ids[i], &tmpid, sizeof(tmpid)))
goto out_1;
}
rc = info->pi_nnis;
out_1:
rc2 = LNetEQFree(eqh);
if (rc2)
CERROR("rc2 %d\n", rc2);
LASSERT(!rc2);
out_0:
LIBCFS_FREE(info, infosz);
return rc;
}
