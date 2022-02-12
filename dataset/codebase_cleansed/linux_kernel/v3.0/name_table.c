static int hash(int x)
{
return x & (tipc_nametbl_size - 1);
}
static struct publication *publ_create(u32 type, u32 lower, u32 upper,
u32 scope, u32 node, u32 port_ref,
u32 key)
{
struct publication *publ = kzalloc(sizeof(*publ), GFP_ATOMIC);
if (publ == NULL) {
warn("Publication creation failure, no memory\n");
return NULL;
}
publ->type = type;
publ->lower = lower;
publ->upper = upper;
publ->scope = scope;
publ->node = node;
publ->ref = port_ref;
publ->key = key;
INIT_LIST_HEAD(&publ->local_list);
INIT_LIST_HEAD(&publ->pport_list);
INIT_LIST_HEAD(&publ->subscr.nodesub_list);
return publ;
}
static struct sub_seq *tipc_subseq_alloc(u32 cnt)
{
struct sub_seq *sseq = kcalloc(cnt, sizeof(struct sub_seq), GFP_ATOMIC);
return sseq;
}
static struct name_seq *tipc_nameseq_create(u32 type, struct hlist_head *seq_head)
{
struct name_seq *nseq = kzalloc(sizeof(*nseq), GFP_ATOMIC);
struct sub_seq *sseq = tipc_subseq_alloc(1);
if (!nseq || !sseq) {
warn("Name sequence creation failed, no memory\n");
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
hlist_add_head(&nseq->ns_list, seq_head);
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
static struct publication *tipc_nameseq_insert_publ(struct name_seq *nseq,
u32 type, u32 lower, u32 upper,
u32 scope, u32 node, u32 port, u32 key)
{
struct subscription *s;
struct subscription *st;
struct publication *publ;
struct sub_seq *sseq;
int created_subseq = 0;
sseq = nameseq_find_subseq(nseq, lower);
if (sseq) {
if ((sseq->lower != lower) || (sseq->upper != upper)) {
warn("Cannot publish {%u,%u,%u}, overlap error\n",
type, lower, upper);
return NULL;
}
} else {
u32 inspos;
struct sub_seq *freesseq;
inspos = nameseq_locate_subseq(nseq, lower);
if ((inspos < nseq->first_free) &&
(upper >= nseq->sseqs[inspos].lower)) {
warn("Cannot publish {%u,%u,%u}, overlap error\n",
type, lower, upper);
return NULL;
}
if (nseq->first_free == nseq->alloc) {
struct sub_seq *sseqs = tipc_subseq_alloc(nseq->alloc * 2);
if (!sseqs) {
warn("Cannot publish {%u,%u,%u}, no memory\n",
type, lower, upper);
return NULL;
}
memcpy(sseqs, nseq->sseqs,
nseq->alloc * sizeof(struct sub_seq));
kfree(nseq->sseqs);
nseq->sseqs = sseqs;
nseq->alloc *= 2;
}
sseq = &nseq->sseqs[inspos];
freesseq = &nseq->sseqs[nseq->first_free];
memmove(sseq + 1, sseq, (freesseq - sseq) * sizeof(*sseq));
memset(sseq, 0, sizeof(*sseq));
nseq->first_free++;
sseq->lower = lower;
sseq->upper = upper;
created_subseq = 1;
}
publ = publ_create(type, lower, upper, scope, node, port, key);
if (!publ)
return NULL;
sseq->zone_list_size++;
if (!sseq->zone_list)
sseq->zone_list = publ->zone_list_next = publ;
else {
publ->zone_list_next = sseq->zone_list->zone_list_next;
sseq->zone_list->zone_list_next = publ;
}
if (in_own_cluster(node)) {
sseq->cluster_list_size++;
if (!sseq->cluster_list)
sseq->cluster_list = publ->cluster_list_next = publ;
else {
publ->cluster_list_next =
sseq->cluster_list->cluster_list_next;
sseq->cluster_list->cluster_list_next = publ;
}
}
if (node == tipc_own_addr) {
sseq->node_list_size++;
if (!sseq->node_list)
sseq->node_list = publ->node_list_next = publ;
else {
publ->node_list_next = sseq->node_list->node_list_next;
sseq->node_list->node_list_next = publ;
}
}
list_for_each_entry_safe(s, st, &nseq->subscriptions, nameseq_list) {
tipc_subscr_report_overlap(s,
publ->lower,
publ->upper,
TIPC_PUBLISHED,
publ->ref,
publ->node,
created_subseq);
}
return publ;
}
static struct publication *tipc_nameseq_remove_publ(struct name_seq *nseq, u32 inst,
u32 node, u32 ref, u32 key)
{
struct publication *publ;
struct publication *curr;
struct publication *prev;
struct sub_seq *sseq = nameseq_find_subseq(nseq, inst);
struct sub_seq *free;
struct subscription *s, *st;
int removed_subseq = 0;
if (!sseq)
return NULL;
prev = sseq->zone_list;
publ = sseq->zone_list->zone_list_next;
while ((publ->key != key) || (publ->ref != ref) ||
(publ->node && (publ->node != node))) {
prev = publ;
publ = publ->zone_list_next;
if (prev == sseq->zone_list) {
return NULL;
}
}
if (publ != sseq->zone_list)
prev->zone_list_next = publ->zone_list_next;
else if (publ->zone_list_next != publ) {
prev->zone_list_next = publ->zone_list_next;
sseq->zone_list = publ->zone_list_next;
} else {
sseq->zone_list = NULL;
}
sseq->zone_list_size--;
if (in_own_cluster(node)) {
prev = sseq->cluster_list;
curr = sseq->cluster_list->cluster_list_next;
while (curr != publ) {
prev = curr;
curr = curr->cluster_list_next;
if (prev == sseq->cluster_list) {
err("Unable to de-list cluster publication\n"
"{%u%u}, node=0x%x, ref=%u, key=%u)\n",
publ->type, publ->lower, publ->node,
publ->ref, publ->key);
goto end_cluster;
}
}
if (publ != sseq->cluster_list)
prev->cluster_list_next = publ->cluster_list_next;
else if (publ->cluster_list_next != publ) {
prev->cluster_list_next = publ->cluster_list_next;
sseq->cluster_list = publ->cluster_list_next;
} else {
sseq->cluster_list = NULL;
}
sseq->cluster_list_size--;
}
end_cluster:
if (node == tipc_own_addr) {
prev = sseq->node_list;
curr = sseq->node_list->node_list_next;
while (curr != publ) {
prev = curr;
curr = curr->node_list_next;
if (prev == sseq->node_list) {
err("Unable to de-list node publication\n"
"{%u%u}, node=0x%x, ref=%u, key=%u)\n",
publ->type, publ->lower, publ->node,
publ->ref, publ->key);
goto end_node;
}
}
if (publ != sseq->node_list)
prev->node_list_next = publ->node_list_next;
else if (publ->node_list_next != publ) {
prev->node_list_next = publ->node_list_next;
sseq->node_list = publ->node_list_next;
} else {
sseq->node_list = NULL;
}
sseq->node_list_size--;
}
end_node:
if (!sseq->zone_list) {
free = &nseq->sseqs[nseq->first_free--];
memmove(sseq, sseq + 1, (free - (sseq + 1)) * sizeof(*sseq));
removed_subseq = 1;
}
list_for_each_entry_safe(s, st, &nseq->subscriptions, nameseq_list) {
tipc_subscr_report_overlap(s,
publ->lower,
publ->upper,
TIPC_WITHDRAWN,
publ->ref,
publ->node,
removed_subseq);
}
return publ;
}
static void tipc_nameseq_subscribe(struct name_seq *nseq, struct subscription *s)
{
struct sub_seq *sseq = nseq->sseqs;
list_add(&s->nameseq_list, &nseq->subscriptions);
if (!sseq)
return;
while (sseq != &nseq->sseqs[nseq->first_free]) {
struct publication *zl = sseq->zone_list;
if (zl && tipc_subscr_overlap(s, sseq->lower, sseq->upper)) {
struct publication *crs = zl;
int must_report = 1;
do {
tipc_subscr_report_overlap(s,
sseq->lower,
sseq->upper,
TIPC_PUBLISHED,
crs->ref,
crs->node,
must_report);
must_report = 0;
crs = crs->zone_list_next;
} while (crs != zl);
}
sseq++;
}
}
static struct name_seq *nametbl_find_seq(u32 type)
{
struct hlist_head *seq_head;
struct hlist_node *seq_node;
struct name_seq *ns;
seq_head = &table.types[hash(type)];
hlist_for_each_entry(ns, seq_node, seq_head, ns_list) {
if (ns->type == type)
return ns;
}
return NULL;
}
struct publication *tipc_nametbl_insert_publ(u32 type, u32 lower, u32 upper,
u32 scope, u32 node, u32 port, u32 key)
{
struct name_seq *seq = nametbl_find_seq(type);
if (lower > upper) {
warn("Failed to publish illegal {%u,%u,%u}\n",
type, lower, upper);
return NULL;
}
if (!seq)
seq = tipc_nameseq_create(type, &table.types[hash(type)]);
if (!seq)
return NULL;
return tipc_nameseq_insert_publ(seq, type, lower, upper,
scope, node, port, key);
}
struct publication *tipc_nametbl_remove_publ(u32 type, u32 lower,
u32 node, u32 ref, u32 key)
{
struct publication *publ;
struct name_seq *seq = nametbl_find_seq(type);
if (!seq)
return NULL;
publ = tipc_nameseq_remove_publ(seq, lower, node, ref, key);
if (!seq->first_free && list_empty(&seq->subscriptions)) {
hlist_del_init(&seq->ns_list);
kfree(seq->sseqs);
kfree(seq);
}
return publ;
}
u32 tipc_nametbl_translate(u32 type, u32 instance, u32 *destnode)
{
struct sub_seq *sseq;
struct publication *publ = NULL;
struct name_seq *seq;
u32 ref;
if (!tipc_in_scope(*destnode, tipc_own_addr))
return 0;
read_lock_bh(&tipc_nametbl_lock);
seq = nametbl_find_seq(type);
if (unlikely(!seq))
goto not_found;
sseq = nameseq_find_subseq(seq, instance);
if (unlikely(!sseq))
goto not_found;
spin_lock_bh(&seq->lock);
if (likely(!*destnode)) {
publ = sseq->node_list;
if (publ) {
sseq->node_list = publ->node_list_next;
found:
ref = publ->ref;
*destnode = publ->node;
spin_unlock_bh(&seq->lock);
read_unlock_bh(&tipc_nametbl_lock);
return ref;
}
publ = sseq->cluster_list;
if (publ) {
sseq->cluster_list = publ->cluster_list_next;
goto found;
}
publ = sseq->zone_list;
if (publ) {
sseq->zone_list = publ->zone_list_next;
goto found;
}
}
else if (*destnode == tipc_own_addr) {
publ = sseq->node_list;
if (publ) {
sseq->node_list = publ->node_list_next;
goto found;
}
} else if (in_own_cluster(*destnode)) {
publ = sseq->cluster_list;
if (publ) {
sseq->cluster_list = publ->cluster_list_next;
goto found;
}
} else {
publ = sseq->zone_list;
if (publ) {
sseq->zone_list = publ->zone_list_next;
goto found;
}
}
spin_unlock_bh(&seq->lock);
not_found:
read_unlock_bh(&tipc_nametbl_lock);
return 0;
}
int tipc_nametbl_mc_translate(u32 type, u32 lower, u32 upper, u32 limit,
struct port_list *dports)
{
struct name_seq *seq;
struct sub_seq *sseq;
struct sub_seq *sseq_stop;
int res = 0;
read_lock_bh(&tipc_nametbl_lock);
seq = nametbl_find_seq(type);
if (!seq)
goto exit;
spin_lock_bh(&seq->lock);
sseq = seq->sseqs + nameseq_locate_subseq(seq, lower);
sseq_stop = seq->sseqs + seq->first_free;
for (; sseq != sseq_stop; sseq++) {
struct publication *publ;
if (sseq->lower > upper)
break;
publ = sseq->node_list;
if (publ) {
do {
if (publ->scope <= limit)
tipc_port_list_add(dports, publ->ref);
publ = publ->node_list_next;
} while (publ != sseq->node_list);
}
if (sseq->cluster_list_size != sseq->node_list_size)
res = 1;
}
spin_unlock_bh(&seq->lock);
exit:
read_unlock_bh(&tipc_nametbl_lock);
return res;
}
int tipc_nametbl_publish_rsv(u32 ref, unsigned int scope,
struct tipc_name_seq const *seq)
{
int res;
atomic_inc(&rsv_publ_ok);
res = tipc_publish(ref, scope, seq);
atomic_dec(&rsv_publ_ok);
return res;
}
struct publication *tipc_nametbl_publish(u32 type, u32 lower, u32 upper,
u32 scope, u32 port_ref, u32 key)
{
struct publication *publ;
if (table.local_publ_count >= tipc_max_publications) {
warn("Publication failed, local publication limit reached (%u)\n",
tipc_max_publications);
return NULL;
}
if ((type < TIPC_RESERVED_TYPES) && !atomic_read(&rsv_publ_ok)) {
warn("Publication failed, reserved name {%u,%u,%u}\n",
type, lower, upper);
return NULL;
}
write_lock_bh(&tipc_nametbl_lock);
table.local_publ_count++;
publ = tipc_nametbl_insert_publ(type, lower, upper, scope,
tipc_own_addr, port_ref, key);
if (publ && (scope != TIPC_NODE_SCOPE))
tipc_named_publish(publ);
write_unlock_bh(&tipc_nametbl_lock);
return publ;
}
int tipc_nametbl_withdraw(u32 type, u32 lower, u32 ref, u32 key)
{
struct publication *publ;
write_lock_bh(&tipc_nametbl_lock);
publ = tipc_nametbl_remove_publ(type, lower, tipc_own_addr, ref, key);
if (likely(publ)) {
table.local_publ_count--;
if (publ->scope != TIPC_NODE_SCOPE)
tipc_named_withdraw(publ);
write_unlock_bh(&tipc_nametbl_lock);
list_del_init(&publ->pport_list);
kfree(publ);
return 1;
}
write_unlock_bh(&tipc_nametbl_lock);
err("Unable to remove local publication\n"
"(type=%u, lower=%u, ref=%u, key=%u)\n",
type, lower, ref, key);
return 0;
}
void tipc_nametbl_subscribe(struct subscription *s)
{
u32 type = s->seq.type;
struct name_seq *seq;
write_lock_bh(&tipc_nametbl_lock);
seq = nametbl_find_seq(type);
if (!seq)
seq = tipc_nameseq_create(type, &table.types[hash(type)]);
if (seq) {
spin_lock_bh(&seq->lock);
tipc_nameseq_subscribe(seq, s);
spin_unlock_bh(&seq->lock);
} else {
warn("Failed to create subscription for {%u,%u,%u}\n",
s->seq.type, s->seq.lower, s->seq.upper);
}
write_unlock_bh(&tipc_nametbl_lock);
}
void tipc_nametbl_unsubscribe(struct subscription *s)
{
struct name_seq *seq;
write_lock_bh(&tipc_nametbl_lock);
seq = nametbl_find_seq(s->seq.type);
if (seq != NULL) {
spin_lock_bh(&seq->lock);
list_del_init(&s->nameseq_list);
spin_unlock_bh(&seq->lock);
if ((seq->first_free == 0) && list_empty(&seq->subscriptions)) {
hlist_del_init(&seq->ns_list);
kfree(seq->sseqs);
kfree(seq);
}
}
write_unlock_bh(&tipc_nametbl_lock);
}
static void subseq_list(struct sub_seq *sseq, struct print_buf *buf, u32 depth,
u32 index)
{
char portIdStr[27];
const char *scope_str[] = {"", " zone", " cluster", " node"};
struct publication *publ = sseq->zone_list;
tipc_printf(buf, "%-10u %-10u ", sseq->lower, sseq->upper);
if (depth == 2 || !publ) {
tipc_printf(buf, "\n");
return;
}
do {
sprintf(portIdStr, "<%u.%u.%u:%u>",
tipc_zone(publ->node), tipc_cluster(publ->node),
tipc_node(publ->node), publ->ref);
tipc_printf(buf, "%-26s ", portIdStr);
if (depth > 3) {
tipc_printf(buf, "%-10u %s", publ->key,
scope_str[publ->scope]);
}
publ = publ->zone_list_next;
if (publ == sseq->zone_list)
break;
tipc_printf(buf, "\n%33s", " ");
} while (1);
tipc_printf(buf, "\n");
}
static void nameseq_list(struct name_seq *seq, struct print_buf *buf, u32 depth,
u32 type, u32 lowbound, u32 upbound, u32 index)
{
struct sub_seq *sseq;
char typearea[11];
if (seq->first_free == 0)
return;
sprintf(typearea, "%-10u", seq->type);
if (depth == 1) {
tipc_printf(buf, "%s\n", typearea);
return;
}
for (sseq = seq->sseqs; sseq != &seq->sseqs[seq->first_free]; sseq++) {
if ((lowbound <= sseq->upper) && (upbound >= sseq->lower)) {
tipc_printf(buf, "%s ", typearea);
spin_lock_bh(&seq->lock);
subseq_list(sseq, buf, depth, index);
spin_unlock_bh(&seq->lock);
sprintf(typearea, "%10s", " ");
}
}
}
static void nametbl_header(struct print_buf *buf, u32 depth)
{
const char *header[] = {
"Type ",
"Lower Upper ",
"Port Identity ",
"Publication Scope"
};
int i;
if (depth > 4)
depth = 4;
for (i = 0; i < depth; i++)
tipc_printf(buf, header[i]);
tipc_printf(buf, "\n");
}
static void nametbl_list(struct print_buf *buf, u32 depth_info,
u32 type, u32 lowbound, u32 upbound)
{
struct hlist_head *seq_head;
struct hlist_node *seq_node;
struct name_seq *seq;
int all_types;
u32 depth;
u32 i;
all_types = (depth_info & TIPC_NTQ_ALLTYPES);
depth = (depth_info & ~TIPC_NTQ_ALLTYPES);
if (depth == 0)
return;
if (all_types) {
nametbl_header(buf, depth);
lowbound = 0;
upbound = ~0;
for (i = 0; i < tipc_nametbl_size; i++) {
seq_head = &table.types[i];
hlist_for_each_entry(seq, seq_node, seq_head, ns_list) {
nameseq_list(seq, buf, depth, seq->type,
lowbound, upbound, i);
}
}
} else {
if (upbound < lowbound) {
tipc_printf(buf, "invalid name sequence specified\n");
return;
}
nametbl_header(buf, depth);
i = hash(type);
seq_head = &table.types[i];
hlist_for_each_entry(seq, seq_node, seq_head, ns_list) {
if (seq->type == type) {
nameseq_list(seq, buf, depth, type,
lowbound, upbound, i);
break;
}
}
}
}
struct sk_buff *tipc_nametbl_get(const void *req_tlv_area, int req_tlv_space)
{
struct sk_buff *buf;
struct tipc_name_table_query *argv;
struct tlv_desc *rep_tlv;
struct print_buf b;
int str_len;
if (!TLV_CHECK(req_tlv_area, req_tlv_space, TIPC_TLV_NAME_TBL_QUERY))
return tipc_cfg_reply_error_string(TIPC_CFG_TLV_ERROR);
buf = tipc_cfg_reply_alloc(TLV_SPACE(MAX_NAME_TBL_QUERY));
if (!buf)
return NULL;
rep_tlv = (struct tlv_desc *)buf->data;
tipc_printbuf_init(&b, TLV_DATA(rep_tlv), MAX_NAME_TBL_QUERY);
argv = (struct tipc_name_table_query *)TLV_DATA(req_tlv_area);
read_lock_bh(&tipc_nametbl_lock);
nametbl_list(&b, ntohl(argv->depth), ntohl(argv->type),
ntohl(argv->lowbound), ntohl(argv->upbound));
read_unlock_bh(&tipc_nametbl_lock);
str_len = tipc_printbuf_validate(&b);
skb_put(buf, TLV_SPACE(str_len));
TLV_SET(rep_tlv, TIPC_TLV_ULTRA_STRING, NULL, str_len);
return buf;
}
int tipc_nametbl_init(void)
{
table.types = kcalloc(tipc_nametbl_size, sizeof(struct hlist_head),
GFP_ATOMIC);
if (!table.types)
return -ENOMEM;
table.local_publ_count = 0;
return 0;
}
void tipc_nametbl_stop(void)
{
u32 i;
if (!table.types)
return;
write_lock_bh(&tipc_nametbl_lock);
for (i = 0; i < tipc_nametbl_size; i++) {
if (!hlist_empty(&table.types[i]))
err("tipc_nametbl_stop(): hash chain %u is non-null\n", i);
}
kfree(table.types);
table.types = NULL;
write_unlock_bh(&tipc_nametbl_lock);
}
