static bool
lnet_fault_nid_match(lnet_nid_t nid, lnet_nid_t msg_nid)
{
if (nid == msg_nid || nid == LNET_NID_ANY)
return true;
if (LNET_NIDNET(nid) != LNET_NIDNET(msg_nid))
return false;
return LNET_NIDADDR(nid) == LNET_NIDADDR(LNET_NID_ANY);
}
static bool
lnet_fault_attr_match(struct lnet_fault_attr *attr, lnet_nid_t src,
lnet_nid_t dst, unsigned int type, unsigned int portal)
{
if (!lnet_fault_nid_match(attr->fa_src, src) ||
!lnet_fault_nid_match(attr->fa_dst, dst))
return false;
if (!(attr->fa_msg_mask & (1 << type)))
return false;
if (attr->fa_ptl_mask &&
!(attr->fa_ptl_mask & (1ULL << portal)))
return false;
return true;
}
static int
lnet_fault_attr_validate(struct lnet_fault_attr *attr)
{
if (!attr->fa_msg_mask)
attr->fa_msg_mask = LNET_MSG_MASK;
if (!attr->fa_ptl_mask)
return 0;
attr->fa_msg_mask &= LNET_GET_BIT | LNET_PUT_BIT;
if (!attr->fa_msg_mask) {
CDEBUG(D_NET, "can't find valid message type bits %x\n",
attr->fa_msg_mask);
return -EINVAL;
}
return 0;
}
static void
lnet_fault_stat_inc(struct lnet_fault_stat *stat, unsigned int type)
{
switch (type) {
case LNET_MSG_PUT:
stat->fs_put++;
return;
case LNET_MSG_ACK:
stat->fs_ack++;
return;
case LNET_MSG_GET:
stat->fs_get++;
return;
case LNET_MSG_REPLY:
stat->fs_reply++;
return;
}
}
static int
lnet_drop_rule_add(struct lnet_fault_attr *attr)
{
struct lnet_drop_rule *rule;
if (attr->u.drop.da_rate & attr->u.drop.da_interval) {
CDEBUG(D_NET, "please provide either drop rate or drop interval, but not both at the same time %d/%d\n",
attr->u.drop.da_rate, attr->u.drop.da_interval);
return -EINVAL;
}
if (lnet_fault_attr_validate(attr))
return -EINVAL;
CFS_ALLOC_PTR(rule);
if (!rule)
return -ENOMEM;
spin_lock_init(&rule->dr_lock);
rule->dr_attr = *attr;
if (attr->u.drop.da_interval) {
rule->dr_time_base = cfs_time_shift(attr->u.drop.da_interval);
rule->dr_drop_time = cfs_time_shift(cfs_rand() %
attr->u.drop.da_interval);
} else {
rule->dr_drop_at = cfs_rand() % attr->u.drop.da_rate;
}
lnet_net_lock(LNET_LOCK_EX);
list_add(&rule->dr_link, &the_lnet.ln_drop_rules);
lnet_net_unlock(LNET_LOCK_EX);
CDEBUG(D_NET, "Added drop rule: src %s, dst %s, rate %d, interval %d\n",
libcfs_nid2str(attr->fa_src), libcfs_nid2str(attr->fa_src),
attr->u.drop.da_rate, attr->u.drop.da_interval);
return 0;
}
static int
lnet_drop_rule_del(lnet_nid_t src, lnet_nid_t dst)
{
struct lnet_drop_rule *rule;
struct lnet_drop_rule *tmp;
struct list_head zombies;
int n = 0;
INIT_LIST_HEAD(&zombies);
lnet_net_lock(LNET_LOCK_EX);
list_for_each_entry_safe(rule, tmp, &the_lnet.ln_drop_rules, dr_link) {
if (rule->dr_attr.fa_src != src && src)
continue;
if (rule->dr_attr.fa_dst != dst && dst)
continue;
list_move(&rule->dr_link, &zombies);
}
lnet_net_unlock(LNET_LOCK_EX);
list_for_each_entry_safe(rule, tmp, &zombies, dr_link) {
CDEBUG(D_NET, "Remove drop rule: src %s->dst: %s (1/%d, %d)\n",
libcfs_nid2str(rule->dr_attr.fa_src),
libcfs_nid2str(rule->dr_attr.fa_dst),
rule->dr_attr.u.drop.da_rate,
rule->dr_attr.u.drop.da_interval);
list_del(&rule->dr_link);
CFS_FREE_PTR(rule);
n++;
}
return n;
}
static int
lnet_drop_rule_list(int pos, struct lnet_fault_attr *attr,
struct lnet_fault_stat *stat)
{
struct lnet_drop_rule *rule;
int cpt;
int i = 0;
int rc = -ENOENT;
cpt = lnet_net_lock_current();
list_for_each_entry(rule, &the_lnet.ln_drop_rules, dr_link) {
if (i++ < pos)
continue;
spin_lock(&rule->dr_lock);
*attr = rule->dr_attr;
*stat = rule->dr_stat;
spin_unlock(&rule->dr_lock);
rc = 0;
break;
}
lnet_net_unlock(cpt);
return rc;
}
static void
lnet_drop_rule_reset(void)
{
struct lnet_drop_rule *rule;
int cpt;
cpt = lnet_net_lock_current();
list_for_each_entry(rule, &the_lnet.ln_drop_rules, dr_link) {
struct lnet_fault_attr *attr = &rule->dr_attr;
spin_lock(&rule->dr_lock);
memset(&rule->dr_stat, 0, sizeof(rule->dr_stat));
if (attr->u.drop.da_rate) {
rule->dr_drop_at = cfs_rand() % attr->u.drop.da_rate;
} else {
rule->dr_drop_time = cfs_time_shift(cfs_rand() %
attr->u.drop.da_interval);
rule->dr_time_base = cfs_time_shift(attr->u.drop.da_interval);
}
spin_unlock(&rule->dr_lock);
}
lnet_net_unlock(cpt);
}
static bool
drop_rule_match(struct lnet_drop_rule *rule, lnet_nid_t src,
lnet_nid_t dst, unsigned int type, unsigned int portal)
{
struct lnet_fault_attr *attr = &rule->dr_attr;
bool drop;
if (!lnet_fault_attr_match(attr, src, dst, type, portal))
return false;
spin_lock(&rule->dr_lock);
if (rule->dr_drop_time) {
unsigned long now = cfs_time_current();
rule->dr_stat.fs_count++;
drop = cfs_time_aftereq(now, rule->dr_drop_time);
if (drop) {
if (cfs_time_after(now, rule->dr_time_base))
rule->dr_time_base = now;
rule->dr_drop_time = rule->dr_time_base +
cfs_time_seconds(cfs_rand() %
attr->u.drop.da_interval);
rule->dr_time_base += cfs_time_seconds(attr->u.drop.da_interval);
CDEBUG(D_NET, "Drop Rule %s->%s: next drop : %lu\n",
libcfs_nid2str(attr->fa_src),
libcfs_nid2str(attr->fa_dst),
rule->dr_drop_time);
}
} else {
drop = rule->dr_stat.fs_count++ == rule->dr_drop_at;
if (!do_div(rule->dr_stat.fs_count, attr->u.drop.da_rate)) {
rule->dr_drop_at = rule->dr_stat.fs_count +
cfs_rand() % attr->u.drop.da_rate;
CDEBUG(D_NET, "Drop Rule %s->%s: next drop: %lu\n",
libcfs_nid2str(attr->fa_src),
libcfs_nid2str(attr->fa_dst), rule->dr_drop_at);
}
}
if (drop) {
lnet_fault_stat_inc(&rule->dr_stat, type);
rule->dr_stat.u.drop.ds_dropped++;
}
spin_unlock(&rule->dr_lock);
return drop;
}
bool
lnet_drop_rule_match(lnet_hdr_t *hdr)
{
struct lnet_drop_rule *rule;
lnet_nid_t src = le64_to_cpu(hdr->src_nid);
lnet_nid_t dst = le64_to_cpu(hdr->dest_nid);
unsigned int typ = le32_to_cpu(hdr->type);
unsigned int ptl = -1;
bool drop = false;
int cpt;
if (typ == LNET_MSG_PUT)
ptl = le32_to_cpu(hdr->msg.put.ptl_index);
else if (typ == LNET_MSG_GET)
ptl = le32_to_cpu(hdr->msg.get.ptl_index);
cpt = lnet_net_lock_current();
list_for_each_entry(rule, &the_lnet.ln_drop_rules, dr_link) {
drop = drop_rule_match(rule, src, dst, typ, ptl);
if (drop)
break;
}
lnet_net_unlock(cpt);
return drop;
}
static unsigned long
round_timeout(unsigned long timeout)
{
return cfs_time_seconds((unsigned int)
cfs_duration_sec(cfs_time_sub(timeout, 0)) + 1);
}
static void
delay_rule_decref(struct lnet_delay_rule *rule)
{
if (atomic_dec_and_test(&rule->dl_refcount)) {
LASSERT(list_empty(&rule->dl_sched_link));
LASSERT(list_empty(&rule->dl_msg_list));
LASSERT(list_empty(&rule->dl_link));
CFS_FREE_PTR(rule);
}
}
static bool
delay_rule_match(struct lnet_delay_rule *rule, lnet_nid_t src,
lnet_nid_t dst, unsigned int type, unsigned int portal,
struct lnet_msg *msg)
{
struct lnet_fault_attr *attr = &rule->dl_attr;
bool delay;
if (!lnet_fault_attr_match(attr, src, dst, type, portal))
return false;
spin_lock(&rule->dl_lock);
if (rule->dl_delay_time) {
unsigned long now = cfs_time_current();
rule->dl_stat.fs_count++;
delay = cfs_time_aftereq(now, rule->dl_delay_time);
if (delay) {
if (cfs_time_after(now, rule->dl_time_base))
rule->dl_time_base = now;
rule->dl_delay_time = rule->dl_time_base +
cfs_time_seconds(cfs_rand() %
attr->u.delay.la_interval);
rule->dl_time_base += cfs_time_seconds(attr->u.delay.la_interval);
CDEBUG(D_NET, "Delay Rule %s->%s: next delay : %lu\n",
libcfs_nid2str(attr->fa_src),
libcfs_nid2str(attr->fa_dst),
rule->dl_delay_time);
}
} else {
delay = rule->dl_stat.fs_count++ == rule->dl_delay_at;
if (!do_div(rule->dl_stat.fs_count, attr->u.delay.la_rate)) {
rule->dl_delay_at = rule->dl_stat.fs_count +
cfs_rand() % attr->u.delay.la_rate;
CDEBUG(D_NET, "Delay Rule %s->%s: next delay: %lu\n",
libcfs_nid2str(attr->fa_src),
libcfs_nid2str(attr->fa_dst), rule->dl_delay_at);
}
}
if (!delay) {
spin_unlock(&rule->dl_lock);
return false;
}
lnet_fault_stat_inc(&rule->dl_stat, type);
rule->dl_stat.u.delay.ls_delayed++;
list_add_tail(&msg->msg_list, &rule->dl_msg_list);
msg->msg_delay_send = round_timeout(
cfs_time_shift(attr->u.delay.la_latency));
if (rule->dl_msg_send == -1) {
rule->dl_msg_send = msg->msg_delay_send;
mod_timer(&rule->dl_timer, rule->dl_msg_send);
}
spin_unlock(&rule->dl_lock);
return true;
}
bool
lnet_delay_rule_match_locked(lnet_hdr_t *hdr, struct lnet_msg *msg)
{
struct lnet_delay_rule *rule;
lnet_nid_t src = le64_to_cpu(hdr->src_nid);
lnet_nid_t dst = le64_to_cpu(hdr->dest_nid);
unsigned int typ = le32_to_cpu(hdr->type);
unsigned int ptl = -1;
if (typ == LNET_MSG_PUT)
ptl = le32_to_cpu(hdr->msg.put.ptl_index);
else if (typ == LNET_MSG_GET)
ptl = le32_to_cpu(hdr->msg.get.ptl_index);
list_for_each_entry(rule, &the_lnet.ln_delay_rules, dl_link) {
if (delay_rule_match(rule, src, dst, typ, ptl, msg))
return true;
}
return false;
}
static void
delayed_msg_check(struct lnet_delay_rule *rule, bool all,
struct list_head *msg_list)
{
struct lnet_msg *msg;
struct lnet_msg *tmp;
unsigned long now = cfs_time_current();
if (!all && rule->dl_msg_send > now)
return;
spin_lock(&rule->dl_lock);
list_for_each_entry_safe(msg, tmp, &rule->dl_msg_list, msg_list) {
if (!all && msg->msg_delay_send > now)
break;
msg->msg_delay_send = 0;
list_move_tail(&msg->msg_list, msg_list);
}
if (list_empty(&rule->dl_msg_list)) {
del_timer(&rule->dl_timer);
rule->dl_msg_send = -1;
} else if (!list_empty(msg_list)) {
msg = list_entry(rule->dl_msg_list.next,
struct lnet_msg, msg_list);
rule->dl_msg_send = msg->msg_delay_send;
mod_timer(&rule->dl_timer, rule->dl_msg_send);
}
spin_unlock(&rule->dl_lock);
}
static void
delayed_msg_process(struct list_head *msg_list, bool drop)
{
struct lnet_msg *msg;
while (!list_empty(msg_list)) {
struct lnet_ni *ni;
int cpt;
int rc;
msg = list_entry(msg_list->next, struct lnet_msg, msg_list);
LASSERT(msg->msg_rxpeer);
ni = msg->msg_rxpeer->lp_ni;
cpt = msg->msg_rx_cpt;
list_del_init(&msg->msg_list);
if (drop) {
rc = -ECANCELED;
} else if (!msg->msg_routing) {
rc = lnet_parse_local(ni, msg);
if (!rc)
continue;
} else {
lnet_net_lock(cpt);
rc = lnet_parse_forward_locked(ni, msg);
lnet_net_unlock(cpt);
switch (rc) {
case LNET_CREDIT_OK:
lnet_ni_recv(ni, msg->msg_private, msg, 0,
0, msg->msg_len, msg->msg_len);
case LNET_CREDIT_WAIT:
continue;
default:
break;
}
}
lnet_drop_message(ni, cpt, msg->msg_private, msg->msg_len);
lnet_finalize(ni, msg, rc);
}
}
void
lnet_delay_rule_check(void)
{
struct lnet_delay_rule *rule;
struct list_head msgs;
INIT_LIST_HEAD(&msgs);
while (1) {
if (list_empty(&delay_dd.dd_sched_rules))
break;
spin_lock_bh(&delay_dd.dd_lock);
if (list_empty(&delay_dd.dd_sched_rules)) {
spin_unlock_bh(&delay_dd.dd_lock);
break;
}
rule = list_entry(delay_dd.dd_sched_rules.next,
struct lnet_delay_rule, dl_sched_link);
list_del_init(&rule->dl_sched_link);
spin_unlock_bh(&delay_dd.dd_lock);
delayed_msg_check(rule, false, &msgs);
delay_rule_decref(rule);
}
if (!list_empty(&msgs))
delayed_msg_process(&msgs, false);
}
static int
lnet_delay_rule_daemon(void *arg)
{
delay_dd.dd_running = 1;
wake_up(&delay_dd.dd_ctl_waitq);
while (delay_dd.dd_running) {
wait_event_interruptible(delay_dd.dd_waitq,
!delay_dd.dd_running ||
!list_empty(&delay_dd.dd_sched_rules));
lnet_delay_rule_check();
}
lnet_delay_rule_check();
delay_dd.dd_stopped = 1;
wake_up(&delay_dd.dd_ctl_waitq);
return 0;
}
static void
delay_timer_cb(unsigned long arg)
{
struct lnet_delay_rule *rule = (struct lnet_delay_rule *)arg;
spin_lock_bh(&delay_dd.dd_lock);
if (list_empty(&rule->dl_sched_link) && delay_dd.dd_running) {
atomic_inc(&rule->dl_refcount);
list_add_tail(&rule->dl_sched_link, &delay_dd.dd_sched_rules);
wake_up(&delay_dd.dd_waitq);
}
spin_unlock_bh(&delay_dd.dd_lock);
}
int
lnet_delay_rule_add(struct lnet_fault_attr *attr)
{
struct lnet_delay_rule *rule;
int rc = 0;
if (attr->u.delay.la_rate & attr->u.delay.la_interval) {
CDEBUG(D_NET, "please provide either delay rate or delay interval, but not both at the same time %d/%d\n",
attr->u.delay.la_rate, attr->u.delay.la_interval);
return -EINVAL;
}
if (!attr->u.delay.la_latency) {
CDEBUG(D_NET, "delay latency cannot be zero\n");
return -EINVAL;
}
if (lnet_fault_attr_validate(attr))
return -EINVAL;
CFS_ALLOC_PTR(rule);
if (!rule)
return -ENOMEM;
mutex_lock(&delay_dd.dd_mutex);
if (!delay_dd.dd_running) {
struct task_struct *task;
task = kthread_run(lnet_delay_rule_daemon, NULL, "lnet_dd");
if (IS_ERR(task)) {
rc = PTR_ERR(task);
goto failed;
}
wait_event(delay_dd.dd_ctl_waitq, delay_dd.dd_running);
}
setup_timer(&rule->dl_timer, delay_timer_cb, (unsigned long)rule);
spin_lock_init(&rule->dl_lock);
INIT_LIST_HEAD(&rule->dl_msg_list);
INIT_LIST_HEAD(&rule->dl_sched_link);
rule->dl_attr = *attr;
if (attr->u.delay.la_interval) {
rule->dl_time_base = cfs_time_shift(attr->u.delay.la_interval);
rule->dl_delay_time = cfs_time_shift(cfs_rand() %
attr->u.delay.la_interval);
} else {
rule->dl_delay_at = cfs_rand() % attr->u.delay.la_rate;
}
rule->dl_msg_send = -1;
lnet_net_lock(LNET_LOCK_EX);
atomic_set(&rule->dl_refcount, 1);
list_add(&rule->dl_link, &the_lnet.ln_delay_rules);
lnet_net_unlock(LNET_LOCK_EX);
CDEBUG(D_NET, "Added delay rule: src %s, dst %s, rate %d\n",
libcfs_nid2str(attr->fa_src), libcfs_nid2str(attr->fa_src),
attr->u.delay.la_rate);
mutex_unlock(&delay_dd.dd_mutex);
return 0;
failed:
mutex_unlock(&delay_dd.dd_mutex);
CFS_FREE_PTR(rule);
return rc;
}
int
lnet_delay_rule_del(lnet_nid_t src, lnet_nid_t dst, bool shutdown)
{
struct lnet_delay_rule *rule;
struct lnet_delay_rule *tmp;
struct list_head rule_list;
struct list_head msg_list;
int n = 0;
bool cleanup;
INIT_LIST_HEAD(&rule_list);
INIT_LIST_HEAD(&msg_list);
if (shutdown) {
src = 0;
dst = 0;
}
mutex_lock(&delay_dd.dd_mutex);
lnet_net_lock(LNET_LOCK_EX);
list_for_each_entry_safe(rule, tmp, &the_lnet.ln_delay_rules, dl_link) {
if (rule->dl_attr.fa_src != src && src)
continue;
if (rule->dl_attr.fa_dst != dst && dst)
continue;
CDEBUG(D_NET, "Remove delay rule: src %s->dst: %s (1/%d, %d)\n",
libcfs_nid2str(rule->dl_attr.fa_src),
libcfs_nid2str(rule->dl_attr.fa_dst),
rule->dl_attr.u.delay.la_rate,
rule->dl_attr.u.delay.la_interval);
list_move(&rule->dl_link, &rule_list);
}
cleanup = list_empty(&the_lnet.ln_delay_rules) &&
!list_empty(&rule_list);
lnet_net_unlock(LNET_LOCK_EX);
list_for_each_entry_safe(rule, tmp, &rule_list, dl_link) {
list_del_init(&rule->dl_link);
del_timer_sync(&rule->dl_timer);
delayed_msg_check(rule, true, &msg_list);
delay_rule_decref(rule);
n++;
}
if (cleanup) {
LASSERT(delay_dd.dd_running);
delay_dd.dd_running = 0;
wake_up(&delay_dd.dd_waitq);
while (!delay_dd.dd_stopped)
wait_event(delay_dd.dd_ctl_waitq, delay_dd.dd_stopped);
}
mutex_unlock(&delay_dd.dd_mutex);
if (!list_empty(&msg_list))
delayed_msg_process(&msg_list, shutdown);
return n;
}
int
lnet_delay_rule_list(int pos, struct lnet_fault_attr *attr,
struct lnet_fault_stat *stat)
{
struct lnet_delay_rule *rule;
int cpt;
int i = 0;
int rc = -ENOENT;
cpt = lnet_net_lock_current();
list_for_each_entry(rule, &the_lnet.ln_delay_rules, dl_link) {
if (i++ < pos)
continue;
spin_lock(&rule->dl_lock);
*attr = rule->dl_attr;
*stat = rule->dl_stat;
spin_unlock(&rule->dl_lock);
rc = 0;
break;
}
lnet_net_unlock(cpt);
return rc;
}
void
lnet_delay_rule_reset(void)
{
struct lnet_delay_rule *rule;
int cpt;
cpt = lnet_net_lock_current();
list_for_each_entry(rule, &the_lnet.ln_delay_rules, dl_link) {
struct lnet_fault_attr *attr = &rule->dl_attr;
spin_lock(&rule->dl_lock);
memset(&rule->dl_stat, 0, sizeof(rule->dl_stat));
if (attr->u.delay.la_rate) {
rule->dl_delay_at = cfs_rand() % attr->u.delay.la_rate;
} else {
rule->dl_delay_time = cfs_time_shift(cfs_rand() %
attr->u.delay.la_interval);
rule->dl_time_base = cfs_time_shift(attr->u.delay.la_interval);
}
spin_unlock(&rule->dl_lock);
}
lnet_net_unlock(cpt);
}
int
lnet_fault_ctl(int opc, struct libcfs_ioctl_data *data)
{
struct lnet_fault_attr *attr;
struct lnet_fault_stat *stat;
attr = (struct lnet_fault_attr *)data->ioc_inlbuf1;
switch (opc) {
default:
return -EINVAL;
case LNET_CTL_DROP_ADD:
if (!attr)
return -EINVAL;
return lnet_drop_rule_add(attr);
case LNET_CTL_DROP_DEL:
if (!attr)
return -EINVAL;
data->ioc_count = lnet_drop_rule_del(attr->fa_src,
attr->fa_dst);
return 0;
case LNET_CTL_DROP_RESET:
lnet_drop_rule_reset();
return 0;
case LNET_CTL_DROP_LIST:
stat = (struct lnet_fault_stat *)data->ioc_inlbuf2;
if (!attr || !stat)
return -EINVAL;
return lnet_drop_rule_list(data->ioc_count, attr, stat);
case LNET_CTL_DELAY_ADD:
if (!attr)
return -EINVAL;
return lnet_delay_rule_add(attr);
case LNET_CTL_DELAY_DEL:
if (!attr)
return -EINVAL;
data->ioc_count = lnet_delay_rule_del(attr->fa_src,
attr->fa_dst, false);
return 0;
case LNET_CTL_DELAY_RESET:
lnet_delay_rule_reset();
return 0;
case LNET_CTL_DELAY_LIST:
stat = (struct lnet_fault_stat *)data->ioc_inlbuf2;
if (!attr || !stat)
return -EINVAL;
return lnet_delay_rule_list(data->ioc_count, attr, stat);
}
}
int
lnet_fault_init(void)
{
CLASSERT(LNET_PUT_BIT == 1 << LNET_MSG_PUT);
CLASSERT(LNET_ACK_BIT == 1 << LNET_MSG_ACK);
CLASSERT(LNET_GET_BIT == 1 << LNET_MSG_GET);
CLASSERT(LNET_REPLY_BIT == 1 << LNET_MSG_REPLY);
mutex_init(&delay_dd.dd_mutex);
spin_lock_init(&delay_dd.dd_lock);
init_waitqueue_head(&delay_dd.dd_waitq);
init_waitqueue_head(&delay_dd.dd_ctl_waitq);
INIT_LIST_HEAD(&delay_dd.dd_sched_rules);
return 0;
}
void
lnet_fault_fini(void)
{
lnet_drop_rule_del(0, 0);
lnet_delay_rule_del(0, 0, true);
LASSERT(list_empty(&the_lnet.ln_drop_rules));
LASSERT(list_empty(&the_lnet.ln_delay_rules));
LASSERT(list_empty(&delay_dd.dd_sched_rules));
}
