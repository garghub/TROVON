static int fill_match_fields(struct adapter *adap,
struct ch_filter_specification *fs,
struct tc_cls_u32_offload *cls,
const struct cxgb4_match_field *entry,
bool next_header)
{
unsigned int i, j;
u32 val, mask;
int off, err;
bool found;
for (i = 0; i < cls->knode.sel->nkeys; i++) {
off = cls->knode.sel->keys[i].off;
val = cls->knode.sel->keys[i].val;
mask = cls->knode.sel->keys[i].mask;
if (next_header) {
if (!cls->knode.sel->keys[i].offmask)
continue;
} else {
if (cls->knode.sel->keys[i].offmask)
continue;
}
found = false;
for (j = 0; entry[j].val; j++) {
if (off == entry[j].off) {
found = true;
err = entry[j].val(fs, val, mask);
if (err)
return err;
break;
}
}
if (!found)
return -EINVAL;
}
return 0;
}
static int fill_action_fields(struct adapter *adap,
struct ch_filter_specification *fs,
struct tc_cls_u32_offload *cls)
{
unsigned int num_actions = 0;
const struct tc_action *a;
struct tcf_exts *exts;
LIST_HEAD(actions);
exts = cls->knode.exts;
if (tc_no_actions(exts))
return -EINVAL;
tcf_exts_to_list(exts, &actions);
list_for_each_entry(a, &actions, list) {
if (num_actions)
return -EINVAL;
if (is_tcf_gact_shot(a)) {
fs->action = FILTER_DROP;
num_actions++;
continue;
}
if (is_tcf_mirred_egress_redirect(a)) {
struct net_device *n_dev;
unsigned int i, index;
bool found = false;
index = tcf_mirred_ifindex(a);
for_each_port(adap, i) {
n_dev = adap->port[i];
if (index == n_dev->ifindex) {
fs->action = FILTER_SWITCH;
fs->eport = i;
found = true;
break;
}
}
if (!found)
return -EINVAL;
num_actions++;
continue;
}
return -EINVAL;
}
return 0;
}
int cxgb4_config_knode(struct net_device *dev, __be16 protocol,
struct tc_cls_u32_offload *cls)
{
const struct cxgb4_match_field *start, *link_start = NULL;
struct adapter *adapter = netdev2adap(dev);
struct ch_filter_specification fs;
struct cxgb4_tc_u32_table *t;
struct cxgb4_link *link;
unsigned int filter_id;
u32 uhtid, link_uhtid;
bool is_ipv6 = false;
int ret;
if (!can_tc_u32_offload(dev))
return -EOPNOTSUPP;
if (protocol != htons(ETH_P_IP) && protocol != htons(ETH_P_IPV6))
return -EOPNOTSUPP;
filter_id = cls->knode.handle & 0xFFFFF;
if (filter_id > adapter->tids.nftids) {
dev_err(adapter->pdev_dev,
"Location %d out of range for insertion. Max: %d\n",
filter_id, adapter->tids.nftids);
return -ERANGE;
}
t = adapter->tc_u32;
uhtid = TC_U32_USERHTID(cls->knode.handle);
link_uhtid = TC_U32_USERHTID(cls->knode.link_handle);
if (uhtid != 0x800 && uhtid >= t->size)
return -EINVAL;
if (link_uhtid >= t->size)
return -EINVAL;
memset(&fs, 0, sizeof(fs));
if (protocol == htons(ETH_P_IPV6)) {
start = cxgb4_ipv6_fields;
is_ipv6 = true;
} else {
start = cxgb4_ipv4_fields;
is_ipv6 = false;
}
if (uhtid != 0x800) {
if (!t->table[uhtid - 1].link_handle)
return -EINVAL;
link_start = t->table[uhtid - 1].match_field;
if (!link_start)
return -EINVAL;
}
if (link_uhtid) {
const struct cxgb4_next_header *next;
bool found = false;
unsigned int i, j;
u32 val, mask;
int off;
if (t->table[link_uhtid - 1].link_handle) {
dev_err(adapter->pdev_dev,
"Link handle exists for: 0x%x\n",
link_uhtid);
return -EINVAL;
}
next = is_ipv6 ? cxgb4_ipv6_jumps : cxgb4_ipv4_jumps;
for (i = 0; next[i].jump; i++) {
if (next[i].offoff != cls->knode.sel->offoff ||
next[i].shift != cls->knode.sel->offshift ||
next[i].mask != cls->knode.sel->offmask ||
next[i].offset != cls->knode.sel->off)
continue;
for (j = 0; j < cls->knode.sel->nkeys; j++) {
off = cls->knode.sel->keys[j].off;
val = cls->knode.sel->keys[j].val;
mask = cls->knode.sel->keys[j].mask;
if (next[i].match_off == off &&
next[i].match_val == val &&
next[i].match_mask == mask) {
found = true;
break;
}
}
if (!found)
continue;
ret = fill_match_fields(adapter, &fs, cls,
start, false);
if (ret)
goto out;
link = &t->table[link_uhtid - 1];
link->match_field = next[i].jump;
link->link_handle = cls->knode.handle;
memcpy(&link->fs, &fs, sizeof(fs));
break;
}
if (!found)
return -EINVAL;
return 0;
}
if (uhtid != 0x800 && t->table[uhtid - 1].link_handle) {
memcpy(&fs, &t->table[uhtid - 1].fs, sizeof(fs));
ret = fill_match_fields(adapter, &fs, cls,
link_start, true);
if (ret)
goto out;
}
ret = fill_match_fields(adapter, &fs, cls, start, false);
if (ret)
goto out;
ret = fill_action_fields(adapter, &fs, cls);
if (ret)
goto out;
fs.val.iport = netdev2pinfo(dev)->port_id;
fs.mask.iport = ~0;
fs.hitcnts = 1;
fs.type = is_ipv6 ? 1 : 0;
ret = cxgb4_set_filter(dev, filter_id, &fs);
if (ret)
goto out;
if (uhtid != 0x800 && t->table[uhtid - 1].link_handle)
set_bit(filter_id, t->table[uhtid - 1].tid_map);
out:
return ret;
}
int cxgb4_delete_knode(struct net_device *dev, __be16 protocol,
struct tc_cls_u32_offload *cls)
{
struct adapter *adapter = netdev2adap(dev);
unsigned int filter_id, max_tids, i, j;
struct cxgb4_link *link = NULL;
struct cxgb4_tc_u32_table *t;
u32 handle, uhtid;
int ret;
if (!can_tc_u32_offload(dev))
return -EOPNOTSUPP;
filter_id = cls->knode.handle & 0xFFFFF;
if (filter_id > adapter->tids.nftids) {
dev_err(adapter->pdev_dev,
"Location %d out of range for deletion. Max: %d\n",
filter_id, adapter->tids.nftids);
return -ERANGE;
}
t = adapter->tc_u32;
handle = cls->knode.handle;
uhtid = TC_U32_USERHTID(cls->knode.handle);
if (uhtid != 0x800 && uhtid >= t->size)
return -EINVAL;
if (uhtid != 0x800) {
link = &t->table[uhtid - 1];
if (!link->link_handle)
return -EINVAL;
if (!test_bit(filter_id, link->tid_map))
return -EINVAL;
}
ret = cxgb4_del_filter(dev, filter_id);
if (ret)
goto out;
if (link)
clear_bit(filter_id, link->tid_map);
max_tids = adapter->tids.nftids;
for (i = 0; i < t->size; i++) {
link = &t->table[i];
if (link->link_handle == handle) {
for (j = 0; j < max_tids; j++) {
if (!test_bit(j, link->tid_map))
continue;
ret = __cxgb4_del_filter(dev, j, NULL);
if (ret)
goto out;
clear_bit(j, link->tid_map);
}
link->match_field = NULL;
link->link_handle = 0;
memset(&link->fs, 0, sizeof(link->fs));
break;
}
}
out:
return ret;
}
void cxgb4_cleanup_tc_u32(struct adapter *adap)
{
struct cxgb4_tc_u32_table *t;
unsigned int i;
if (!adap->tc_u32)
return;
t = adap->tc_u32;
for (i = 0; i < t->size; i++) {
struct cxgb4_link *link = &t->table[i];
t4_free_mem(link->tid_map);
}
t4_free_mem(adap->tc_u32);
}
struct cxgb4_tc_u32_table *cxgb4_init_tc_u32(struct adapter *adap)
{
unsigned int max_tids = adap->tids.nftids;
struct cxgb4_tc_u32_table *t;
unsigned int i;
if (!max_tids)
return NULL;
t = t4_alloc_mem(sizeof(*t) +
(max_tids * sizeof(struct cxgb4_link)));
if (!t)
return NULL;
t->size = max_tids;
for (i = 0; i < t->size; i++) {
struct cxgb4_link *link = &t->table[i];
unsigned int bmap_size;
bmap_size = BITS_TO_LONGS(max_tids);
link->tid_map = t4_alloc_mem(sizeof(unsigned long) * bmap_size);
if (!link->tid_map)
goto out_no_mem;
bitmap_zero(link->tid_map, max_tids);
}
return t;
out_no_mem:
for (i = 0; i < t->size; i++) {
struct cxgb4_link *link = &t->table[i];
if (link->tid_map)
t4_free_mem(link->tid_map);
}
if (t)
t4_free_mem(t);
return NULL;
}
