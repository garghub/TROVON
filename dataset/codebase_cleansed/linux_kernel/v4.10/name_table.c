static int hash(int x)
{
return x & (TIPC_NAMETBL_SIZE - 1);
}
static struct publication *publ_create(u32 type, u32 lower, u32 upper,
u32 scope, u32 node, u32 port_ref,
u32 key)
{
struct publication *publ = kzalloc(sizeof(*publ), GFP_ATOMIC);
if (publ == NULL) {
pr_warn("Publication creation failure, no memory\n");
return NULL;
}
publ->type = type;
publ->lower = lower;
publ->upper = upper;
publ->scope = scope;
publ->node = node;
publ->ref = port_ref;
publ->key = key;
INIT_LIST_HEAD(&publ->pport_list);
return publ;
}
static struct sub_seq *tipc_subseq_alloc(u32 cnt)
{
return kcalloc(cnt, sizeof(struct sub_seq), GFP_ATOMIC);
}
static struct name_seq *tipc_nameseq_create(u32 type, struct hlist_head *seq_head)
{
struct name_seq *nseq = kzalloc(sizeof(*nseq), GFP_ATOMIC);
struct sub_seq *sseq = tipc_subseq_alloc(1);
if (!nseq || !sseq) {
pr_warn("Name sequence creation failed, no memory\n");
kfree(nseq);
kfree(sseq);
return NULL;
}
spin_lock_init(&nseq->lock);
nseq->type = type;
nseq->sseqs = sseq;
nseq->alloc = 1;
INIT_HLIST_NODE(&nseq->ns_list);
INIT_LIST_HEAD(&nseq->subscriptions);
hlist_add_head_rcu(&nseq->ns_list, seq_head);
return nseq;
}
static struct sub_seq *nameseq_find_subseq(struct name_seq *nseq,
u32 instance)
{
struct sub_seq *sseqs = nseq->sseqs;
int low = 0;
int high = nseq->first_free - 1;
int mid;
while (low <= high) {
mid = (low + high) / 2;
if (instance < sseqs[mid].lower)
high = mid - 1;
else if (instance > sseqs[mid].upper)
low = mid + 1;
else
return &sseqs[mid];
}
return NULL;
}
static u32 nameseq_locate_subseq(struct name_seq *nseq, u32 instance)
{
struct sub_seq *sseqs = nseq->sseqs;
int low = 0;
int high = nseq->first_free - 1;
int mid;
while (low <= high) {
mid = (low + high) / 2;
if (instance < sseqs[mid].lower)
high = mid - 1;
else if (instance > sseqs[mid].upper)
low = mid + 1;
else
return mid;
}
return low;
}
static struct publication *tipc_nameseq_insert_publ(struct net *net,
struct name_seq *nseq,
u32 type, u32 lower,
u32 upper, u32 scope,
u32 node, u32 port, u32 key)
{
struct tipc_subscription *s;
struct tipc_subscription *st;
struct publication *publ;
struct sub_seq *sseq;
struct name_info *info;
int created_subseq = 0;
sseq = nameseq_find_subseq(nseq, lower);
if (sseq) {
if ((sseq->lower != lower) || (sseq->upper != upper)) {
return NULL;
}
info = sseq->info;
list_for_each_entry(publ, &info->zone_list, zone_list) {
if ((publ->ref == port) && (publ->key == key) &&
(!publ->node || (publ->node == node)))
return NULL;
}
} else {
u32 inspos;
struct sub_seq *freesseq;
inspos = nameseq_locate_subseq(nseq, lower);
if ((inspos < nseq->first_free) &&
(upper >= nseq->sseqs[inspos].lower)) {
return NULL;
}
if (nseq->first_free == nseq->alloc) {
struct sub_seq *sseqs = tipc_subseq_alloc(nseq->alloc * 2);
if (!sseqs) {
pr_warn("Cannot publish {%u,%u,%u}, no memory\n",
type, lower, upper);
return NULL;
}
memcpy(sseqs, nseq->sseqs,
nseq->alloc * sizeof(struct sub_seq));
kfree(nseq->sseqs);
nseq->sseqs = sseqs;
nseq->alloc *= 2;
}
info = kzalloc(sizeof(*info), GFP_ATOMIC);
if (!info) {
pr_warn("Cannot publish {%u,%u,%u}, no memory\n",
type, lower, upper);
return NULL;
}
INIT_LIST_HEAD(&info->node_list);
INIT_LIST_HEAD(&info->cluster_list);
INIT_LIST_HEAD(&info->zone_list);
sseq = &nseq->sseqs[inspos];
freesseq = &nseq->sseqs[nseq->first_free];
memmove(sseq + 1, sseq, (freesseq - sseq) * sizeof(*sseq));
memset(sseq, 0, sizeof(*sseq));
nseq->first_free++;
sseq->lower = lower;
sseq->upper = upper;
sseq->info = info;
created_subseq = 1;
}
publ = publ_create(type, lower, upper, scope, node, port, key);
if (!publ)
return NULL;
list_add(&publ->zone_list, &info->zone_list);
info->zone_list_size++;
if (in_own_cluster(net, node)) {
list_add(&publ->cluster_list, &info->cluster_list);
info->cluster_list_size++;
}
if (in_own_node(net, node)) {
list_add(&publ->node_list, &info->node_list);
info->node_list_size++;
}
list_for_each_entry_safe(s, st, &nseq->subscriptions, nameseq_list) {
tipc_subscrp_report_overlap(s, publ->lower, publ->upper,
TIPC_PUBLISHED, publ->ref,
publ->node, created_subseq);
}
return publ;
}
static struct publication *tipc_nameseq_remove_publ(struct net *net,
struct name_seq *nseq,
u32 inst, u32 node,
u32 ref, u32 key)
{
struct publication *publ;
struct sub_seq *sseq = nameseq_find_subseq(nseq, inst);
struct name_info *info;
struct sub_seq *free;
struct tipc_subscription *s, *st;
int removed_subseq = 0;
if (!sseq)
return NULL;
info = sseq->info;
list_for_each_entry(publ, &info->zone_list, zone_list) {
if ((publ->key == key) && (publ->ref == ref) &&
(!publ->node || (publ->node == node)))
goto found;
}
return NULL;
found:
list_del(&publ->zone_list);
info->zone_list_size--;
if (in_own_cluster(net, node)) {
list_del(&publ->cluster_list);
info->cluster_list_size--;
}
if (in_own_node(net, node)) {
list_del(&publ->node_list);
info->node_list_size--;
}
if (list_empty(&info->zone_list)) {
kfree(info);
free = &nseq->sseqs[nseq->first_free--];
memmove(sseq, sseq + 1, (free - (sseq + 1)) * sizeof(*sseq));
removed_subseq = 1;
}
list_for_each_entry_safe(s, st, &nseq->subscriptions, nameseq_list) {
tipc_subscrp_report_overlap(s, publ->lower, publ->upper,
TIPC_WITHDRAWN, publ->ref,
publ->node, removed_subseq);
}
return publ;
}
static void tipc_nameseq_subscribe(struct name_seq *nseq,
struct tipc_subscription *s)
{
struct sub_seq *sseq = nseq->sseqs;
struct tipc_name_seq ns;
tipc_subscrp_convert_seq(&s->evt.s.seq, s->swap, &ns);
list_add(&s->nameseq_list, &nseq->subscriptions);
if (!sseq)
return;
while (sseq != &nseq->sseqs[nseq->first_free]) {
if (tipc_subscrp_check_overlap(&ns, sseq->lower, sseq->upper)) {
struct publication *crs;
struct name_info *info = sseq->info;
int must_report = 1;
list_for_each_entry(crs, &info->zone_list, zone_list) {
tipc_subscrp_report_overlap(s, sseq->lower,
sseq->upper,
TIPC_PUBLISHED,
crs->ref, crs->node,
must_report);
must_report = 0;
}
}
sseq++;
}
}
static struct name_seq *nametbl_find_seq(struct net *net, u32 type)
{
struct tipc_net *tn = net_generic(net, tipc_net_id);
struct hlist_head *seq_head;
struct name_seq *ns;
seq_head = &tn->nametbl->seq_hlist[hash(type)];
hlist_for_each_entry_rcu(ns, seq_head, ns_list) {
if (ns->type == type)
return ns;
}
return NULL;
}
struct publication *tipc_nametbl_insert_publ(struct net *net, u32 type,
u32 lower, u32 upper, u32 scope,
u32 node, u32 port, u32 key)
{
struct tipc_net *tn = net_generic(net, tipc_net_id);
struct publication *publ;
struct name_seq *seq = nametbl_find_seq(net, type);
int index = hash(type);
if ((scope < TIPC_ZONE_SCOPE) || (scope > TIPC_NODE_SCOPE) ||
(lower > upper)) {
pr_debug("Failed to publish illegal {%u,%u,%u} with scope %u\n",
type, lower, upper, scope);
return NULL;
}
if (!seq)
seq = tipc_nameseq_create(type, &tn->nametbl->seq_hlist[index]);
if (!seq)
return NULL;
spin_lock_bh(&seq->lock);
publ = tipc_nameseq_insert_publ(net, seq, type, lower, upper,
scope, node, port, key);
spin_unlock_bh(&seq->lock);
return publ;
}
struct publication *tipc_nametbl_remove_publ(struct net *net, u32 type,
u32 lower, u32 node, u32 ref,
u32 key)
{
struct publication *publ;
struct name_seq *seq = nametbl_find_seq(net, type);
if (!seq)
return NULL;
spin_lock_bh(&seq->lock);
publ = tipc_nameseq_remove_publ(net, seq, lower, node, ref, key);
if (!seq->first_free && list_empty(&seq->subscriptions)) {
hlist_del_init_rcu(&seq->ns_list);
kfree(seq->sseqs);
spin_unlock_bh(&seq->lock);
kfree_rcu(seq, rcu);
return publ;
}
spin_unlock_bh(&seq->lock);
return publ;
}
u32 tipc_nametbl_translate(struct net *net, u32 type, u32 instance,
u32 *destnode)
{
struct tipc_net *tn = net_generic(net, tipc_net_id);
struct sub_seq *sseq;
struct name_info *info;
struct publication *publ;
struct name_seq *seq;
u32 ref = 0;
u32 node = 0;
if (!tipc_in_scope(*destnode, tn->own_addr))
return 0;
rcu_read_lock();
seq = nametbl_find_seq(net, type);
if (unlikely(!seq))
goto not_found;
spin_lock_bh(&seq->lock);
sseq = nameseq_find_subseq(seq, instance);
if (unlikely(!sseq))
goto no_match;
info = sseq->info;
if (likely(!*destnode)) {
if (!list_empty(&info->node_list)) {
publ = list_first_entry(&info->node_list,
struct publication,
node_list);
list_move_tail(&publ->node_list,
&info->node_list);
} else if (!list_empty(&info->cluster_list)) {
publ = list_first_entry(&info->cluster_list,
struct publication,
cluster_list);
list_move_tail(&publ->cluster_list,
&info->cluster_list);
} else {
publ = list_first_entry(&info->zone_list,
struct publication,
zone_list);
list_move_tail(&publ->zone_list,
&info->zone_list);
}
}
else if (*destnode == tn->own_addr) {
if (list_empty(&info->node_list))
goto no_match;
publ = list_first_entry(&info->node_list, struct publication,
node_list);
list_move_tail(&publ->node_list, &info->node_list);
} else if (in_own_cluster_exact(net, *destnode)) {
if (list_empty(&info->cluster_list))
goto no_match;
publ = list_first_entry(&info->cluster_list, struct publication,
cluster_list);
list_move_tail(&publ->cluster_list, &info->cluster_list);
} else {
publ = list_first_entry(&info->zone_list, struct publication,
zone_list);
list_move_tail(&publ->zone_list, &info->zone_list);
}
ref = publ->ref;
node = publ->node;
no_match:
spin_unlock_bh(&seq->lock);
not_found:
rcu_read_unlock();
*destnode = node;
return ref;
}
int tipc_nametbl_mc_translate(struct net *net, u32 type, u32 lower, u32 upper,
u32 limit, struct tipc_plist *dports)
{
struct name_seq *seq;
struct sub_seq *sseq;
struct sub_seq *sseq_stop;
struct name_info *info;
int res = 0;
rcu_read_lock();
seq = nametbl_find_seq(net, type);
if (!seq)
goto exit;
spin_lock_bh(&seq->lock);
sseq = seq->sseqs + nameseq_locate_subseq(seq, lower);
sseq_stop = seq->sseqs + seq->first_free;
for (; sseq != sseq_stop; sseq++) {
struct publication *publ;
if (sseq->lower > upper)
break;
info = sseq->info;
list_for_each_entry(publ, &info->node_list, node_list) {
if (publ->scope <= limit)
tipc_plist_push(dports, publ->ref);
}
if (info->cluster_list_size != info->node_list_size)
res = 1;
}
spin_unlock_bh(&seq->lock);
exit:
rcu_read_unlock();
return res;
}
struct publication *tipc_nametbl_publish(struct net *net, u32 type, u32 lower,
u32 upper, u32 scope, u32 port_ref,
u32 key)
{
struct publication *publ;
struct sk_buff *buf = NULL;
struct tipc_net *tn = net_generic(net, tipc_net_id);
spin_lock_bh(&tn->nametbl_lock);
if (tn->nametbl->local_publ_count >= TIPC_MAX_PUBLICATIONS) {
pr_warn("Publication failed, local publication limit reached (%u)\n",
TIPC_MAX_PUBLICATIONS);
spin_unlock_bh(&tn->nametbl_lock);
return NULL;
}
publ = tipc_nametbl_insert_publ(net, type, lower, upper, scope,
tn->own_addr, port_ref, key);
if (likely(publ)) {
tn->nametbl->local_publ_count++;
buf = tipc_named_publish(net, publ);
tipc_named_process_backlog(net);
}
spin_unlock_bh(&tn->nametbl_lock);
if (buf)
tipc_node_broadcast(net, buf);
return publ;
}
int tipc_nametbl_withdraw(struct net *net, u32 type, u32 lower, u32 ref,
u32 key)
{
struct publication *publ;
struct sk_buff *skb = NULL;
struct tipc_net *tn = net_generic(net, tipc_net_id);
spin_lock_bh(&tn->nametbl_lock);
publ = tipc_nametbl_remove_publ(net, type, lower, tn->own_addr,
ref, key);
if (likely(publ)) {
tn->nametbl->local_publ_count--;
skb = tipc_named_withdraw(net, publ);
tipc_named_process_backlog(net);
list_del_init(&publ->pport_list);
kfree_rcu(publ, rcu);
} else {
pr_err("Unable to remove local publication\n"
"(type=%u, lower=%u, ref=%u, key=%u)\n",
type, lower, ref, key);
}
spin_unlock_bh(&tn->nametbl_lock);
if (skb) {
tipc_node_broadcast(net, skb);
return 1;
}
return 0;
}
void tipc_nametbl_subscribe(struct tipc_subscription *s)
{
struct tipc_net *tn = net_generic(s->net, tipc_net_id);
u32 type = tipc_subscrp_convert_seq_type(s->evt.s.seq.type, s->swap);
int index = hash(type);
struct name_seq *seq;
struct tipc_name_seq ns;
spin_lock_bh(&tn->nametbl_lock);
seq = nametbl_find_seq(s->net, type);
if (!seq)
seq = tipc_nameseq_create(type, &tn->nametbl->seq_hlist[index]);
if (seq) {
spin_lock_bh(&seq->lock);
tipc_nameseq_subscribe(seq, s);
spin_unlock_bh(&seq->lock);
} else {
tipc_subscrp_convert_seq(&s->evt.s.seq, s->swap, &ns);
pr_warn("Failed to create subscription for {%u,%u,%u}\n",
ns.type, ns.lower, ns.upper);
}
spin_unlock_bh(&tn->nametbl_lock);
}
void tipc_nametbl_unsubscribe(struct tipc_subscription *s)
{
struct tipc_net *tn = net_generic(s->net, tipc_net_id);
struct name_seq *seq;
u32 type = tipc_subscrp_convert_seq_type(s->evt.s.seq.type, s->swap);
spin_lock_bh(&tn->nametbl_lock);
seq = nametbl_find_seq(s->net, type);
if (seq != NULL) {
spin_lock_bh(&seq->lock);
list_del_init(&s->nameseq_list);
if (!seq->first_free && list_empty(&seq->subscriptions)) {
hlist_del_init_rcu(&seq->ns_list);
kfree(seq->sseqs);
spin_unlock_bh(&seq->lock);
kfree_rcu(seq, rcu);
} else {
spin_unlock_bh(&seq->lock);
}
}
spin_unlock_bh(&tn->nametbl_lock);
}
int tipc_nametbl_init(struct net *net)
{
struct tipc_net *tn = net_generic(net, tipc_net_id);
struct name_table *tipc_nametbl;
int i;
tipc_nametbl = kzalloc(sizeof(*tipc_nametbl), GFP_ATOMIC);
if (!tipc_nametbl)
return -ENOMEM;
for (i = 0; i < TIPC_NAMETBL_SIZE; i++)
INIT_HLIST_HEAD(&tipc_nametbl->seq_hlist[i]);
INIT_LIST_HEAD(&tipc_nametbl->publ_list[TIPC_ZONE_SCOPE]);
INIT_LIST_HEAD(&tipc_nametbl->publ_list[TIPC_CLUSTER_SCOPE]);
INIT_LIST_HEAD(&tipc_nametbl->publ_list[TIPC_NODE_SCOPE]);
tn->nametbl = tipc_nametbl;
spin_lock_init(&tn->nametbl_lock);
return 0;
}
static void tipc_purge_publications(struct net *net, struct name_seq *seq)
{
struct publication *publ, *safe;
struct sub_seq *sseq;
struct name_info *info;
spin_lock_bh(&seq->lock);
sseq = seq->sseqs;
info = sseq->info;
list_for_each_entry_safe(publ, safe, &info->zone_list, zone_list) {
tipc_nameseq_remove_publ(net, seq, publ->lower, publ->node,
publ->ref, publ->key);
kfree_rcu(publ, rcu);
}
hlist_del_init_rcu(&seq->ns_list);
kfree(seq->sseqs);
spin_unlock_bh(&seq->lock);
kfree_rcu(seq, rcu);
}
void tipc_nametbl_stop(struct net *net)
{
u32 i;
struct name_seq *seq;
struct hlist_head *seq_head;
struct tipc_net *tn = net_generic(net, tipc_net_id);
struct name_table *tipc_nametbl = tn->nametbl;
spin_lock_bh(&tn->nametbl_lock);
for (i = 0; i < TIPC_NAMETBL_SIZE; i++) {
if (hlist_empty(&tipc_nametbl->seq_hlist[i]))
continue;
seq_head = &tipc_nametbl->seq_hlist[i];
hlist_for_each_entry_rcu(seq, seq_head, ns_list) {
tipc_purge_publications(net, seq);
}
}
spin_unlock_bh(&tn->nametbl_lock);
synchronize_net();
kfree(tipc_nametbl);
}
static int __tipc_nl_add_nametable_publ(struct tipc_nl_msg *msg,
struct name_seq *seq,
struct sub_seq *sseq, u32 *last_publ)
{
void *hdr;
struct nlattr *attrs;
struct nlattr *publ;
struct publication *p;
if (*last_publ) {
list_for_each_entry(p, &sseq->info->zone_list, zone_list)
if (p->key == *last_publ)
break;
if (p->key != *last_publ)
return -EPIPE;
} else {
p = list_first_entry(&sseq->info->zone_list, struct publication,
zone_list);
}
list_for_each_entry_from(p, &sseq->info->zone_list, zone_list) {
*last_publ = p->key;
hdr = genlmsg_put(msg->skb, msg->portid, msg->seq,
&tipc_genl_family, NLM_F_MULTI,
TIPC_NL_NAME_TABLE_GET);
if (!hdr)
return -EMSGSIZE;
attrs = nla_nest_start(msg->skb, TIPC_NLA_NAME_TABLE);
if (!attrs)
goto msg_full;
publ = nla_nest_start(msg->skb, TIPC_NLA_NAME_TABLE_PUBL);
if (!publ)
goto attr_msg_full;
if (nla_put_u32(msg->skb, TIPC_NLA_PUBL_TYPE, seq->type))
goto publ_msg_full;
if (nla_put_u32(msg->skb, TIPC_NLA_PUBL_LOWER, sseq->lower))
goto publ_msg_full;
if (nla_put_u32(msg->skb, TIPC_NLA_PUBL_UPPER, sseq->upper))
goto publ_msg_full;
if (nla_put_u32(msg->skb, TIPC_NLA_PUBL_SCOPE, p->scope))
goto publ_msg_full;
if (nla_put_u32(msg->skb, TIPC_NLA_PUBL_NODE, p->node))
goto publ_msg_full;
if (nla_put_u32(msg->skb, TIPC_NLA_PUBL_REF, p->ref))
goto publ_msg_full;
if (nla_put_u32(msg->skb, TIPC_NLA_PUBL_KEY, p->key))
goto publ_msg_full;
nla_nest_end(msg->skb, publ);
nla_nest_end(msg->skb, attrs);
genlmsg_end(msg->skb, hdr);
}
*last_publ = 0;
return 0;
publ_msg_full:
nla_nest_cancel(msg->skb, publ);
attr_msg_full:
nla_nest_cancel(msg->skb, attrs);
msg_full:
genlmsg_cancel(msg->skb, hdr);
return -EMSGSIZE;
}
static int __tipc_nl_subseq_list(struct tipc_nl_msg *msg, struct name_seq *seq,
u32 *last_lower, u32 *last_publ)
{
struct sub_seq *sseq;
struct sub_seq *sseq_start;
int err;
if (*last_lower) {
sseq_start = nameseq_find_subseq(seq, *last_lower);
if (!sseq_start)
return -EPIPE;
} else {
sseq_start = seq->sseqs;
}
for (sseq = sseq_start; sseq != &seq->sseqs[seq->first_free]; sseq++) {
err = __tipc_nl_add_nametable_publ(msg, seq, sseq, last_publ);
if (err) {
*last_lower = sseq->lower;
return err;
}
}
*last_lower = 0;
return 0;
}
static int tipc_nl_seq_list(struct net *net, struct tipc_nl_msg *msg,
u32 *last_type, u32 *last_lower, u32 *last_publ)
{
struct tipc_net *tn = net_generic(net, tipc_net_id);
struct hlist_head *seq_head;
struct name_seq *seq = NULL;
int err;
int i;
if (*last_type)
i = hash(*last_type);
else
i = 0;
for (; i < TIPC_NAMETBL_SIZE; i++) {
seq_head = &tn->nametbl->seq_hlist[i];
if (*last_type) {
seq = nametbl_find_seq(net, *last_type);
if (!seq)
return -EPIPE;
} else {
hlist_for_each_entry_rcu(seq, seq_head, ns_list)
break;
if (!seq)
continue;
}
hlist_for_each_entry_from_rcu(seq, ns_list) {
spin_lock_bh(&seq->lock);
err = __tipc_nl_subseq_list(msg, seq, last_lower,
last_publ);
if (err) {
*last_type = seq->type;
spin_unlock_bh(&seq->lock);
return err;
}
spin_unlock_bh(&seq->lock);
}
*last_type = 0;
}
return 0;
}
int tipc_nl_name_table_dump(struct sk_buff *skb, struct netlink_callback *cb)
{
int err;
int done = cb->args[3];
u32 last_type = cb->args[0];
u32 last_lower = cb->args[1];
u32 last_publ = cb->args[2];
struct net *net = sock_net(skb->sk);
struct tipc_nl_msg msg;
if (done)
return 0;
msg.skb = skb;
msg.portid = NETLINK_CB(cb->skb).portid;
msg.seq = cb->nlh->nlmsg_seq;
rcu_read_lock();
err = tipc_nl_seq_list(net, &msg, &last_type, &last_lower, &last_publ);
if (!err) {
done = 1;
} else if (err != -EMSGSIZE) {
cb->prev_seq = 1;
}
rcu_read_unlock();
cb->args[0] = last_type;
cb->args[1] = last_lower;
cb->args[2] = last_publ;
cb->args[3] = done;
return skb->len;
}
void tipc_plist_push(struct tipc_plist *pl, u32 port)
{
struct tipc_plist *nl;
if (likely(!pl->port)) {
pl->port = port;
return;
}
if (pl->port == port)
return;
list_for_each_entry(nl, &pl->list, list) {
if (nl->port == port)
return;
}
nl = kmalloc(sizeof(*nl), GFP_ATOMIC);
if (nl) {
nl->port = port;
list_add(&nl->list, &pl->list);
}
}
u32 tipc_plist_pop(struct tipc_plist *pl)
{
struct tipc_plist *nl;
u32 port = 0;
if (likely(list_empty(&pl->list))) {
port = pl->port;
pl->port = 0;
return port;
}
nl = list_first_entry(&pl->list, typeof(*nl), list);
port = nl->port;
list_del(&nl->list);
kfree(nl);
return port;
}
