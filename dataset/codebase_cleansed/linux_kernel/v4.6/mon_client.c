struct ceph_monmap *ceph_monmap_decode(void *p, void *end)
{
struct ceph_monmap *m = NULL;
int i, err = -EINVAL;
struct ceph_fsid fsid;
u32 epoch, num_mon;
u16 version;
u32 len;
ceph_decode_32_safe(&p, end, len, bad);
ceph_decode_need(&p, end, len, bad);
dout("monmap_decode %p %p len %d\n", p, end, (int)(end-p));
ceph_decode_16_safe(&p, end, version, bad);
ceph_decode_need(&p, end, sizeof(fsid) + 2*sizeof(u32), bad);
ceph_decode_copy(&p, &fsid, sizeof(fsid));
epoch = ceph_decode_32(&p);
num_mon = ceph_decode_32(&p);
ceph_decode_need(&p, end, num_mon*sizeof(m->mon_inst[0]), bad);
if (num_mon >= CEPH_MAX_MON)
goto bad;
m = kmalloc(sizeof(*m) + sizeof(m->mon_inst[0])*num_mon, GFP_NOFS);
if (m == NULL)
return ERR_PTR(-ENOMEM);
m->fsid = fsid;
m->epoch = epoch;
m->num_mon = num_mon;
ceph_decode_copy(&p, m->mon_inst, num_mon*sizeof(m->mon_inst[0]));
for (i = 0; i < num_mon; i++)
ceph_decode_addr(&m->mon_inst[i].addr);
dout("monmap_decode epoch %d, num_mon %d\n", m->epoch,
m->num_mon);
for (i = 0; i < m->num_mon; i++)
dout("monmap_decode mon%d is %s\n", i,
ceph_pr_addr(&m->mon_inst[i].addr.in_addr));
return m;
bad:
dout("monmap_decode failed with %d\n", err);
kfree(m);
return ERR_PTR(err);
}
int ceph_monmap_contains(struct ceph_monmap *m, struct ceph_entity_addr *addr)
{
int i;
for (i = 0; i < m->num_mon; i++)
if (memcmp(addr, &m->mon_inst[i].addr, sizeof(*addr)) == 0)
return 1;
return 0;
}
static void __send_prepared_auth_request(struct ceph_mon_client *monc, int len)
{
monc->pending_auth = 1;
monc->m_auth->front.iov_len = len;
monc->m_auth->hdr.front_len = cpu_to_le32(len);
ceph_msg_revoke(monc->m_auth);
ceph_msg_get(monc->m_auth);
ceph_con_send(&monc->con, monc->m_auth);
}
static void __close_session(struct ceph_mon_client *monc)
{
dout("__close_session closing mon%d\n", monc->cur_mon);
ceph_msg_revoke(monc->m_auth);
ceph_msg_revoke_incoming(monc->m_auth_reply);
ceph_msg_revoke(monc->m_subscribe);
ceph_msg_revoke_incoming(monc->m_subscribe_ack);
ceph_con_close(&monc->con);
monc->pending_auth = 0;
ceph_auth_reset(monc->auth);
}
static void pick_new_mon(struct ceph_mon_client *monc)
{
int old_mon = monc->cur_mon;
BUG_ON(monc->monmap->num_mon < 1);
if (monc->monmap->num_mon == 1) {
monc->cur_mon = 0;
} else {
int max = monc->monmap->num_mon;
int o = -1;
int n;
if (monc->cur_mon >= 0) {
if (monc->cur_mon < monc->monmap->num_mon)
o = monc->cur_mon;
if (o >= 0)
max--;
}
n = prandom_u32() % max;
if (o >= 0 && n >= o)
n++;
monc->cur_mon = n;
}
dout("%s mon%d -> mon%d out of %d mons\n", __func__, old_mon,
monc->cur_mon, monc->monmap->num_mon);
}
static void __open_session(struct ceph_mon_client *monc)
{
int ret;
pick_new_mon(monc);
monc->hunting = true;
if (monc->had_a_connection) {
monc->hunt_mult *= CEPH_MONC_HUNT_BACKOFF;
if (monc->hunt_mult > CEPH_MONC_HUNT_MAX_MULT)
monc->hunt_mult = CEPH_MONC_HUNT_MAX_MULT;
}
monc->sub_renew_after = jiffies;
monc->sub_renew_sent = 0;
dout("%s opening mon%d\n", __func__, monc->cur_mon);
ceph_con_open(&monc->con, CEPH_ENTITY_TYPE_MON, monc->cur_mon,
&monc->monmap->mon_inst[monc->cur_mon].addr);
ceph_con_keepalive(&monc->con);
ret = ceph_auth_build_hello(monc->auth,
monc->m_auth->front.iov_base,
monc->m_auth->front_alloc_len);
BUG_ON(ret <= 0);
__send_prepared_auth_request(monc, ret);
}
static void reopen_session(struct ceph_mon_client *monc)
{
if (!monc->hunting)
pr_info("mon%d %s session lost, hunting for new mon\n",
monc->cur_mon, ceph_pr_addr(&monc->con.peer_addr.in_addr));
__close_session(monc);
__open_session(monc);
}
static void __schedule_delayed(struct ceph_mon_client *monc)
{
unsigned long delay;
if (monc->hunting)
delay = CEPH_MONC_HUNT_INTERVAL * monc->hunt_mult;
else
delay = CEPH_MONC_PING_INTERVAL;
dout("__schedule_delayed after %lu\n", delay);
mod_delayed_work(system_wq, &monc->delayed_work,
round_jiffies_relative(delay));
}
static void __send_subscribe(struct ceph_mon_client *monc)
{
struct ceph_msg *msg = monc->m_subscribe;
void *p = msg->front.iov_base;
void *const end = p + msg->front_alloc_len;
int num = 0;
int i;
dout("%s sent %lu\n", __func__, monc->sub_renew_sent);
BUG_ON(monc->cur_mon < 0);
if (!monc->sub_renew_sent)
monc->sub_renew_sent = jiffies | 1;
msg->hdr.version = cpu_to_le16(2);
for (i = 0; i < ARRAY_SIZE(monc->subs); i++) {
if (monc->subs[i].want)
num++;
}
BUG_ON(num < 1);
ceph_encode_32(&p, num);
for (i = 0; i < ARRAY_SIZE(monc->subs); i++) {
const char *s = ceph_sub_str[i];
if (!monc->subs[i].want)
continue;
dout("%s %s start %llu flags 0x%x\n", __func__, s,
le64_to_cpu(monc->subs[i].item.start),
monc->subs[i].item.flags);
ceph_encode_string(&p, end, s, strlen(s));
memcpy(p, &monc->subs[i].item, sizeof(monc->subs[i].item));
p += sizeof(monc->subs[i].item);
}
BUG_ON(p != (end - 35 - (ARRAY_SIZE(monc->subs) - num) * 19));
msg->front.iov_len = p - msg->front.iov_base;
msg->hdr.front_len = cpu_to_le32(msg->front.iov_len);
ceph_msg_revoke(msg);
ceph_con_send(&monc->con, ceph_msg_get(msg));
}
static void handle_subscribe_ack(struct ceph_mon_client *monc,
struct ceph_msg *msg)
{
unsigned int seconds;
struct ceph_mon_subscribe_ack *h = msg->front.iov_base;
if (msg->front.iov_len < sizeof(*h))
goto bad;
seconds = le32_to_cpu(h->duration);
mutex_lock(&monc->mutex);
if (monc->sub_renew_sent) {
monc->sub_renew_after = monc->sub_renew_sent +
(seconds >> 1) * HZ - 1;
dout("%s sent %lu duration %d renew after %lu\n", __func__,
monc->sub_renew_sent, seconds, monc->sub_renew_after);
monc->sub_renew_sent = 0;
} else {
dout("%s sent %lu renew after %lu, ignoring\n", __func__,
monc->sub_renew_sent, monc->sub_renew_after);
}
mutex_unlock(&monc->mutex);
return;
bad:
pr_err("got corrupt subscribe-ack msg\n");
ceph_msg_dump(msg);
}
static bool __ceph_monc_want_map(struct ceph_mon_client *monc, int sub,
u32 epoch, bool continuous)
{
__le64 start = cpu_to_le64(epoch);
u8 flags = !continuous ? CEPH_SUBSCRIBE_ONETIME : 0;
dout("%s %s epoch %u continuous %d\n", __func__, ceph_sub_str[sub],
epoch, continuous);
if (monc->subs[sub].want &&
monc->subs[sub].item.start == start &&
monc->subs[sub].item.flags == flags)
return false;
monc->subs[sub].item.start = start;
monc->subs[sub].item.flags = flags;
monc->subs[sub].want = true;
return true;
}
bool ceph_monc_want_map(struct ceph_mon_client *monc, int sub, u32 epoch,
bool continuous)
{
bool need_request;
mutex_lock(&monc->mutex);
need_request = __ceph_monc_want_map(monc, sub, epoch, continuous);
mutex_unlock(&monc->mutex);
return need_request;
}
static void __ceph_monc_got_map(struct ceph_mon_client *monc, int sub,
u32 epoch)
{
dout("%s %s epoch %u\n", __func__, ceph_sub_str[sub], epoch);
if (monc->subs[sub].want) {
if (monc->subs[sub].item.flags & CEPH_SUBSCRIBE_ONETIME)
monc->subs[sub].want = false;
else
monc->subs[sub].item.start = cpu_to_le64(epoch + 1);
}
monc->subs[sub].have = epoch;
}
void ceph_monc_got_map(struct ceph_mon_client *monc, int sub, u32 epoch)
{
mutex_lock(&monc->mutex);
__ceph_monc_got_map(monc, sub, epoch);
mutex_unlock(&monc->mutex);
}
void ceph_monc_request_next_osdmap(struct ceph_mon_client *monc)
{
dout("%s have %u\n", __func__, monc->subs[CEPH_SUB_OSDMAP].have);
mutex_lock(&monc->mutex);
if (__ceph_monc_want_map(monc, CEPH_SUB_OSDMAP,
monc->subs[CEPH_SUB_OSDMAP].have + 1, false))
__send_subscribe(monc);
mutex_unlock(&monc->mutex);
}
int ceph_monc_wait_osdmap(struct ceph_mon_client *monc, u32 epoch,
unsigned long timeout)
{
unsigned long started = jiffies;
long ret;
mutex_lock(&monc->mutex);
while (monc->subs[CEPH_SUB_OSDMAP].have < epoch) {
mutex_unlock(&monc->mutex);
if (timeout && time_after_eq(jiffies, started + timeout))
return -ETIMEDOUT;
ret = wait_event_interruptible_timeout(monc->client->auth_wq,
monc->subs[CEPH_SUB_OSDMAP].have >= epoch,
ceph_timeout_jiffies(timeout));
if (ret < 0)
return ret;
mutex_lock(&monc->mutex);
}
mutex_unlock(&monc->mutex);
return 0;
}
int ceph_monc_open_session(struct ceph_mon_client *monc)
{
mutex_lock(&monc->mutex);
__ceph_monc_want_map(monc, CEPH_SUB_MONMAP, 0, true);
__ceph_monc_want_map(monc, CEPH_SUB_OSDMAP, 0, false);
__open_session(monc);
__schedule_delayed(monc);
mutex_unlock(&monc->mutex);
return 0;
}
static void ceph_monc_handle_map(struct ceph_mon_client *monc,
struct ceph_msg *msg)
{
struct ceph_client *client = monc->client;
struct ceph_monmap *monmap = NULL, *old = monc->monmap;
void *p, *end;
mutex_lock(&monc->mutex);
dout("handle_monmap\n");
p = msg->front.iov_base;
end = p + msg->front.iov_len;
monmap = ceph_monmap_decode(p, end);
if (IS_ERR(monmap)) {
pr_err("problem decoding monmap, %d\n",
(int)PTR_ERR(monmap));
goto out;
}
if (ceph_check_fsid(monc->client, &monmap->fsid) < 0) {
kfree(monmap);
goto out;
}
client->monc.monmap = monmap;
kfree(old);
__ceph_monc_got_map(monc, CEPH_SUB_MONMAP, monc->monmap->epoch);
client->have_fsid = true;
out:
mutex_unlock(&monc->mutex);
wake_up_all(&client->auth_wq);
}
static struct ceph_mon_generic_request *__lookup_generic_req(
struct ceph_mon_client *monc, u64 tid)
{
struct ceph_mon_generic_request *req;
struct rb_node *n = monc->generic_request_tree.rb_node;
while (n) {
req = rb_entry(n, struct ceph_mon_generic_request, node);
if (tid < req->tid)
n = n->rb_left;
else if (tid > req->tid)
n = n->rb_right;
else
return req;
}
return NULL;
}
static void __insert_generic_request(struct ceph_mon_client *monc,
struct ceph_mon_generic_request *new)
{
struct rb_node **p = &monc->generic_request_tree.rb_node;
struct rb_node *parent = NULL;
struct ceph_mon_generic_request *req = NULL;
while (*p) {
parent = *p;
req = rb_entry(parent, struct ceph_mon_generic_request, node);
if (new->tid < req->tid)
p = &(*p)->rb_left;
else if (new->tid > req->tid)
p = &(*p)->rb_right;
else
BUG();
}
rb_link_node(&new->node, parent, p);
rb_insert_color(&new->node, &monc->generic_request_tree);
}
static void release_generic_request(struct kref *kref)
{
struct ceph_mon_generic_request *req =
container_of(kref, struct ceph_mon_generic_request, kref);
if (req->reply)
ceph_msg_put(req->reply);
if (req->request)
ceph_msg_put(req->request);
kfree(req);
}
static void put_generic_request(struct ceph_mon_generic_request *req)
{
kref_put(&req->kref, release_generic_request);
}
static void get_generic_request(struct ceph_mon_generic_request *req)
{
kref_get(&req->kref);
}
static struct ceph_msg *get_generic_reply(struct ceph_connection *con,
struct ceph_msg_header *hdr,
int *skip)
{
struct ceph_mon_client *monc = con->private;
struct ceph_mon_generic_request *req;
u64 tid = le64_to_cpu(hdr->tid);
struct ceph_msg *m;
mutex_lock(&monc->mutex);
req = __lookup_generic_req(monc, tid);
if (!req) {
dout("get_generic_reply %lld dne\n", tid);
*skip = 1;
m = NULL;
} else {
dout("get_generic_reply %lld got %p\n", tid, req->reply);
*skip = 0;
m = ceph_msg_get(req->reply);
}
mutex_unlock(&monc->mutex);
return m;
}
static int __do_generic_request(struct ceph_mon_client *monc, u64 tid,
struct ceph_mon_generic_request *req)
{
int err;
req->tid = tid != 0 ? tid : ++monc->last_tid;
req->request->hdr.tid = cpu_to_le64(req->tid);
__insert_generic_request(monc, req);
monc->num_generic_requests++;
ceph_con_send(&monc->con, ceph_msg_get(req->request));
mutex_unlock(&monc->mutex);
err = wait_for_completion_interruptible(&req->completion);
mutex_lock(&monc->mutex);
rb_erase(&req->node, &monc->generic_request_tree);
monc->num_generic_requests--;
if (!err)
err = req->result;
return err;
}
static int do_generic_request(struct ceph_mon_client *monc,
struct ceph_mon_generic_request *req)
{
int err;
mutex_lock(&monc->mutex);
err = __do_generic_request(monc, 0, req);
mutex_unlock(&monc->mutex);
return err;
}
static void handle_statfs_reply(struct ceph_mon_client *monc,
struct ceph_msg *msg)
{
struct ceph_mon_generic_request *req;
struct ceph_mon_statfs_reply *reply = msg->front.iov_base;
u64 tid = le64_to_cpu(msg->hdr.tid);
if (msg->front.iov_len != sizeof(*reply))
goto bad;
dout("handle_statfs_reply %p tid %llu\n", msg, tid);
mutex_lock(&monc->mutex);
req = __lookup_generic_req(monc, tid);
if (req) {
*(struct ceph_statfs *)req->buf = reply->st;
req->result = 0;
get_generic_request(req);
}
mutex_unlock(&monc->mutex);
if (req) {
complete_all(&req->completion);
put_generic_request(req);
}
return;
bad:
pr_err("corrupt statfs reply, tid %llu\n", tid);
ceph_msg_dump(msg);
}
int ceph_monc_do_statfs(struct ceph_mon_client *monc, struct ceph_statfs *buf)
{
struct ceph_mon_generic_request *req;
struct ceph_mon_statfs *h;
int err;
req = kzalloc(sizeof(*req), GFP_NOFS);
if (!req)
return -ENOMEM;
kref_init(&req->kref);
req->buf = buf;
init_completion(&req->completion);
err = -ENOMEM;
req->request = ceph_msg_new(CEPH_MSG_STATFS, sizeof(*h), GFP_NOFS,
true);
if (!req->request)
goto out;
req->reply = ceph_msg_new(CEPH_MSG_STATFS_REPLY, 1024, GFP_NOFS,
true);
if (!req->reply)
goto out;
h = req->request->front.iov_base;
h->monhdr.have_version = 0;
h->monhdr.session_mon = cpu_to_le16(-1);
h->monhdr.session_mon_tid = 0;
h->fsid = monc->monmap->fsid;
err = do_generic_request(monc, req);
out:
put_generic_request(req);
return err;
}
static void handle_get_version_reply(struct ceph_mon_client *monc,
struct ceph_msg *msg)
{
struct ceph_mon_generic_request *req;
u64 tid = le64_to_cpu(msg->hdr.tid);
void *p = msg->front.iov_base;
void *end = p + msg->front_alloc_len;
u64 handle;
dout("%s %p tid %llu\n", __func__, msg, tid);
ceph_decode_need(&p, end, 2*sizeof(u64), bad);
handle = ceph_decode_64(&p);
if (tid != 0 && tid != handle)
goto bad;
mutex_lock(&monc->mutex);
req = __lookup_generic_req(monc, handle);
if (req) {
*(u64 *)req->buf = ceph_decode_64(&p);
req->result = 0;
get_generic_request(req);
}
mutex_unlock(&monc->mutex);
if (req) {
complete_all(&req->completion);
put_generic_request(req);
}
return;
bad:
pr_err("corrupt mon_get_version reply, tid %llu\n", tid);
ceph_msg_dump(msg);
}
int ceph_monc_do_get_version(struct ceph_mon_client *monc, const char *what,
u64 *newest)
{
struct ceph_mon_generic_request *req;
void *p, *end;
u64 tid;
int err;
req = kzalloc(sizeof(*req), GFP_NOFS);
if (!req)
return -ENOMEM;
kref_init(&req->kref);
req->buf = newest;
init_completion(&req->completion);
req->request = ceph_msg_new(CEPH_MSG_MON_GET_VERSION,
sizeof(u64) + sizeof(u32) + strlen(what),
GFP_NOFS, true);
if (!req->request) {
err = -ENOMEM;
goto out;
}
req->reply = ceph_msg_new(CEPH_MSG_MON_GET_VERSION_REPLY, 1024,
GFP_NOFS, true);
if (!req->reply) {
err = -ENOMEM;
goto out;
}
p = req->request->front.iov_base;
end = p + req->request->front_alloc_len;
mutex_lock(&monc->mutex);
tid = ++monc->last_tid;
ceph_encode_64(&p, tid);
ceph_encode_string(&p, end, what, strlen(what));
err = __do_generic_request(monc, tid, req);
mutex_unlock(&monc->mutex);
out:
put_generic_request(req);
return err;
}
static void __resend_generic_request(struct ceph_mon_client *monc)
{
struct ceph_mon_generic_request *req;
struct rb_node *p;
for (p = rb_first(&monc->generic_request_tree); p; p = rb_next(p)) {
req = rb_entry(p, struct ceph_mon_generic_request, node);
ceph_msg_revoke(req->request);
ceph_msg_revoke_incoming(req->reply);
ceph_con_send(&monc->con, ceph_msg_get(req->request));
}
}
static void delayed_work(struct work_struct *work)
{
struct ceph_mon_client *monc =
container_of(work, struct ceph_mon_client, delayed_work.work);
dout("monc delayed_work\n");
mutex_lock(&monc->mutex);
if (monc->hunting) {
dout("%s continuing hunt\n", __func__);
reopen_session(monc);
} else {
int is_auth = ceph_auth_is_authenticated(monc->auth);
if (ceph_con_keepalive_expired(&monc->con,
CEPH_MONC_PING_TIMEOUT)) {
dout("monc keepalive timeout\n");
is_auth = 0;
reopen_session(monc);
}
if (!monc->hunting) {
ceph_con_keepalive(&monc->con);
__validate_auth(monc);
}
if (is_auth) {
unsigned long now = jiffies;
dout("%s renew subs? now %lu renew after %lu\n",
__func__, now, monc->sub_renew_after);
if (time_after_eq(now, monc->sub_renew_after))
__send_subscribe(monc);
}
}
__schedule_delayed(monc);
mutex_unlock(&monc->mutex);
}
static int build_initial_monmap(struct ceph_mon_client *monc)
{
struct ceph_options *opt = monc->client->options;
struct ceph_entity_addr *mon_addr = opt->mon_addr;
int num_mon = opt->num_mon;
int i;
monc->monmap = kzalloc(sizeof(*monc->monmap) +
num_mon*sizeof(monc->monmap->mon_inst[0]),
GFP_KERNEL);
if (!monc->monmap)
return -ENOMEM;
for (i = 0; i < num_mon; i++) {
monc->monmap->mon_inst[i].addr = mon_addr[i];
monc->monmap->mon_inst[i].addr.nonce = 0;
monc->monmap->mon_inst[i].name.type =
CEPH_ENTITY_TYPE_MON;
monc->monmap->mon_inst[i].name.num = cpu_to_le64(i);
}
monc->monmap->num_mon = num_mon;
return 0;
}
int ceph_monc_init(struct ceph_mon_client *monc, struct ceph_client *cl)
{
int err = 0;
dout("init\n");
memset(monc, 0, sizeof(*monc));
monc->client = cl;
monc->monmap = NULL;
mutex_init(&monc->mutex);
err = build_initial_monmap(monc);
if (err)
goto out;
monc->auth = ceph_auth_init(cl->options->name,
cl->options->key);
if (IS_ERR(monc->auth)) {
err = PTR_ERR(monc->auth);
goto out_monmap;
}
monc->auth->want_keys =
CEPH_ENTITY_TYPE_AUTH | CEPH_ENTITY_TYPE_MON |
CEPH_ENTITY_TYPE_OSD | CEPH_ENTITY_TYPE_MDS;
err = -ENOMEM;
monc->m_subscribe_ack = ceph_msg_new(CEPH_MSG_MON_SUBSCRIBE_ACK,
sizeof(struct ceph_mon_subscribe_ack),
GFP_NOFS, true);
if (!monc->m_subscribe_ack)
goto out_auth;
monc->m_subscribe = ceph_msg_new(CEPH_MSG_MON_SUBSCRIBE, 96, GFP_NOFS,
true);
if (!monc->m_subscribe)
goto out_subscribe_ack;
monc->m_auth_reply = ceph_msg_new(CEPH_MSG_AUTH_REPLY, 4096, GFP_NOFS,
true);
if (!monc->m_auth_reply)
goto out_subscribe;
monc->m_auth = ceph_msg_new(CEPH_MSG_AUTH, 4096, GFP_NOFS, true);
monc->pending_auth = 0;
if (!monc->m_auth)
goto out_auth_reply;
ceph_con_init(&monc->con, monc, &mon_con_ops,
&monc->client->msgr);
monc->cur_mon = -1;
monc->had_a_connection = false;
monc->hunt_mult = 1;
INIT_DELAYED_WORK(&monc->delayed_work, delayed_work);
monc->generic_request_tree = RB_ROOT;
monc->num_generic_requests = 0;
monc->last_tid = 0;
return 0;
out_auth_reply:
ceph_msg_put(monc->m_auth_reply);
out_subscribe:
ceph_msg_put(monc->m_subscribe);
out_subscribe_ack:
ceph_msg_put(monc->m_subscribe_ack);
out_auth:
ceph_auth_destroy(monc->auth);
out_monmap:
kfree(monc->monmap);
out:
return err;
}
void ceph_monc_stop(struct ceph_mon_client *monc)
{
dout("stop\n");
cancel_delayed_work_sync(&monc->delayed_work);
mutex_lock(&monc->mutex);
__close_session(monc);
monc->cur_mon = -1;
mutex_unlock(&monc->mutex);
ceph_msgr_flush();
ceph_auth_destroy(monc->auth);
ceph_msg_put(monc->m_auth);
ceph_msg_put(monc->m_auth_reply);
ceph_msg_put(monc->m_subscribe);
ceph_msg_put(monc->m_subscribe_ack);
kfree(monc->monmap);
}
static void finish_hunting(struct ceph_mon_client *monc)
{
if (monc->hunting) {
dout("%s found mon%d\n", __func__, monc->cur_mon);
monc->hunting = false;
monc->had_a_connection = true;
monc->hunt_mult /= 2;
if (monc->hunt_mult < 1)
monc->hunt_mult = 1;
}
}
static void handle_auth_reply(struct ceph_mon_client *monc,
struct ceph_msg *msg)
{
int ret;
int was_auth = 0;
mutex_lock(&monc->mutex);
was_auth = ceph_auth_is_authenticated(monc->auth);
monc->pending_auth = 0;
ret = ceph_handle_auth_reply(monc->auth, msg->front.iov_base,
msg->front.iov_len,
monc->m_auth->front.iov_base,
monc->m_auth->front_alloc_len);
if (ret > 0) {
__send_prepared_auth_request(monc, ret);
goto out;
}
finish_hunting(monc);
if (ret < 0) {
monc->client->auth_err = ret;
} else if (!was_auth && ceph_auth_is_authenticated(monc->auth)) {
dout("authenticated, starting session\n");
monc->client->msgr.inst.name.type = CEPH_ENTITY_TYPE_CLIENT;
monc->client->msgr.inst.name.num =
cpu_to_le64(monc->auth->global_id);
__send_subscribe(monc);
__resend_generic_request(monc);
pr_info("mon%d %s session established\n", monc->cur_mon,
ceph_pr_addr(&monc->con.peer_addr.in_addr));
}
out:
mutex_unlock(&monc->mutex);
if (monc->client->auth_err < 0)
wake_up_all(&monc->client->auth_wq);
}
static int __validate_auth(struct ceph_mon_client *monc)
{
int ret;
if (monc->pending_auth)
return 0;
ret = ceph_build_auth(monc->auth, monc->m_auth->front.iov_base,
monc->m_auth->front_alloc_len);
if (ret <= 0)
return ret;
__send_prepared_auth_request(monc, ret);
return 0;
}
int ceph_monc_validate_auth(struct ceph_mon_client *monc)
{
int ret;
mutex_lock(&monc->mutex);
ret = __validate_auth(monc);
mutex_unlock(&monc->mutex);
return ret;
}
static void dispatch(struct ceph_connection *con, struct ceph_msg *msg)
{
struct ceph_mon_client *monc = con->private;
int type = le16_to_cpu(msg->hdr.type);
if (!monc)
return;
switch (type) {
case CEPH_MSG_AUTH_REPLY:
handle_auth_reply(monc, msg);
break;
case CEPH_MSG_MON_SUBSCRIBE_ACK:
handle_subscribe_ack(monc, msg);
break;
case CEPH_MSG_STATFS_REPLY:
handle_statfs_reply(monc, msg);
break;
case CEPH_MSG_MON_GET_VERSION_REPLY:
handle_get_version_reply(monc, msg);
break;
case CEPH_MSG_MON_MAP:
ceph_monc_handle_map(monc, msg);
break;
case CEPH_MSG_OSD_MAP:
ceph_osdc_handle_map(&monc->client->osdc, msg);
break;
default:
if (monc->client->extra_mon_dispatch &&
monc->client->extra_mon_dispatch(monc->client, msg) == 0)
break;
pr_err("received unknown message type %d %s\n", type,
ceph_msg_type_name(type));
}
ceph_msg_put(msg);
}
static struct ceph_msg *mon_alloc_msg(struct ceph_connection *con,
struct ceph_msg_header *hdr,
int *skip)
{
struct ceph_mon_client *monc = con->private;
int type = le16_to_cpu(hdr->type);
int front_len = le32_to_cpu(hdr->front_len);
struct ceph_msg *m = NULL;
*skip = 0;
switch (type) {
case CEPH_MSG_MON_SUBSCRIBE_ACK:
m = ceph_msg_get(monc->m_subscribe_ack);
break;
case CEPH_MSG_STATFS_REPLY:
return get_generic_reply(con, hdr, skip);
case CEPH_MSG_AUTH_REPLY:
m = ceph_msg_get(monc->m_auth_reply);
break;
case CEPH_MSG_MON_GET_VERSION_REPLY:
if (le64_to_cpu(hdr->tid) != 0)
return get_generic_reply(con, hdr, skip);
case CEPH_MSG_MON_MAP:
case CEPH_MSG_MDS_MAP:
case CEPH_MSG_OSD_MAP:
m = ceph_msg_new(type, front_len, GFP_NOFS, false);
if (!m)
return NULL;
break;
}
if (!m) {
pr_info("alloc_msg unknown type %d\n", type);
*skip = 1;
} else if (front_len > m->front_alloc_len) {
pr_warn("mon_alloc_msg front %d > prealloc %d (%u#%llu)\n",
front_len, m->front_alloc_len,
(unsigned int)con->peer_name.type,
le64_to_cpu(con->peer_name.num));
ceph_msg_put(m);
m = ceph_msg_new(type, front_len, GFP_NOFS, false);
}
return m;
}
static void mon_fault(struct ceph_connection *con)
{
struct ceph_mon_client *monc = con->private;
mutex_lock(&monc->mutex);
dout("%s mon%d\n", __func__, monc->cur_mon);
if (monc->cur_mon >= 0) {
if (!monc->hunting) {
dout("%s hunting for new mon\n", __func__);
reopen_session(monc);
__schedule_delayed(monc);
} else {
dout("%s already hunting\n", __func__);
}
}
mutex_unlock(&monc->mutex);
}
static struct ceph_connection *con_get(struct ceph_connection *con)
{
return con;
}
static void con_put(struct ceph_connection *con)
{
}
