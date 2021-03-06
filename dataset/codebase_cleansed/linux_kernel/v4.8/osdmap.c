char *ceph_osdmap_state_str(char *str, int len, int state)
{
if (!len)
return str;
if ((state & CEPH_OSD_EXISTS) && (state & CEPH_OSD_UP))
snprintf(str, len, "exists, up");
else if (state & CEPH_OSD_EXISTS)
snprintf(str, len, "exists");
else if (state & CEPH_OSD_UP)
snprintf(str, len, "up");
else
snprintf(str, len, "doesn't exist");
return str;
}
static int calc_bits_of(unsigned int t)
{
int b = 0;
while (t) {
t = t >> 1;
b++;
}
return b;
}
static void calc_pg_masks(struct ceph_pg_pool_info *pi)
{
pi->pg_num_mask = (1 << calc_bits_of(pi->pg_num-1)) - 1;
pi->pgp_num_mask = (1 << calc_bits_of(pi->pgp_num-1)) - 1;
}
static int crush_decode_uniform_bucket(void **p, void *end,
struct crush_bucket_uniform *b)
{
dout("crush_decode_uniform_bucket %p to %p\n", *p, end);
ceph_decode_need(p, end, (1+b->h.size) * sizeof(u32), bad);
b->item_weight = ceph_decode_32(p);
return 0;
bad:
return -EINVAL;
}
static int crush_decode_list_bucket(void **p, void *end,
struct crush_bucket_list *b)
{
int j;
dout("crush_decode_list_bucket %p to %p\n", *p, end);
b->item_weights = kcalloc(b->h.size, sizeof(u32), GFP_NOFS);
if (b->item_weights == NULL)
return -ENOMEM;
b->sum_weights = kcalloc(b->h.size, sizeof(u32), GFP_NOFS);
if (b->sum_weights == NULL)
return -ENOMEM;
ceph_decode_need(p, end, 2 * b->h.size * sizeof(u32), bad);
for (j = 0; j < b->h.size; j++) {
b->item_weights[j] = ceph_decode_32(p);
b->sum_weights[j] = ceph_decode_32(p);
}
return 0;
bad:
return -EINVAL;
}
static int crush_decode_tree_bucket(void **p, void *end,
struct crush_bucket_tree *b)
{
int j;
dout("crush_decode_tree_bucket %p to %p\n", *p, end);
ceph_decode_8_safe(p, end, b->num_nodes, bad);
b->node_weights = kcalloc(b->num_nodes, sizeof(u32), GFP_NOFS);
if (b->node_weights == NULL)
return -ENOMEM;
ceph_decode_need(p, end, b->num_nodes * sizeof(u32), bad);
for (j = 0; j < b->num_nodes; j++)
b->node_weights[j] = ceph_decode_32(p);
return 0;
bad:
return -EINVAL;
}
static int crush_decode_straw_bucket(void **p, void *end,
struct crush_bucket_straw *b)
{
int j;
dout("crush_decode_straw_bucket %p to %p\n", *p, end);
b->item_weights = kcalloc(b->h.size, sizeof(u32), GFP_NOFS);
if (b->item_weights == NULL)
return -ENOMEM;
b->straws = kcalloc(b->h.size, sizeof(u32), GFP_NOFS);
if (b->straws == NULL)
return -ENOMEM;
ceph_decode_need(p, end, 2 * b->h.size * sizeof(u32), bad);
for (j = 0; j < b->h.size; j++) {
b->item_weights[j] = ceph_decode_32(p);
b->straws[j] = ceph_decode_32(p);
}
return 0;
bad:
return -EINVAL;
}
static int crush_decode_straw2_bucket(void **p, void *end,
struct crush_bucket_straw2 *b)
{
int j;
dout("crush_decode_straw2_bucket %p to %p\n", *p, end);
b->item_weights = kcalloc(b->h.size, sizeof(u32), GFP_NOFS);
if (b->item_weights == NULL)
return -ENOMEM;
ceph_decode_need(p, end, b->h.size * sizeof(u32), bad);
for (j = 0; j < b->h.size; j++)
b->item_weights[j] = ceph_decode_32(p);
return 0;
bad:
return -EINVAL;
}
static int skip_name_map(void **p, void *end)
{
int len;
ceph_decode_32_safe(p, end, len ,bad);
while (len--) {
int strlen;
*p += sizeof(u32);
ceph_decode_32_safe(p, end, strlen, bad);
*p += strlen;
}
return 0;
bad:
return -EINVAL;
}
static struct crush_map *crush_decode(void *pbyval, void *end)
{
struct crush_map *c;
int err = -EINVAL;
int i, j;
void **p = &pbyval;
void *start = pbyval;
u32 magic;
u32 num_name_maps;
dout("crush_decode %p to %p len %d\n", *p, end, (int)(end - *p));
c = kzalloc(sizeof(*c), GFP_NOFS);
if (c == NULL)
return ERR_PTR(-ENOMEM);
c->choose_local_tries = 2;
c->choose_local_fallback_tries = 5;
c->choose_total_tries = 19;
c->chooseleaf_descend_once = 0;
ceph_decode_need(p, end, 4*sizeof(u32), bad);
magic = ceph_decode_32(p);
if (magic != CRUSH_MAGIC) {
pr_err("crush_decode magic %x != current %x\n",
(unsigned int)magic, (unsigned int)CRUSH_MAGIC);
goto bad;
}
c->max_buckets = ceph_decode_32(p);
c->max_rules = ceph_decode_32(p);
c->max_devices = ceph_decode_32(p);
c->buckets = kcalloc(c->max_buckets, sizeof(*c->buckets), GFP_NOFS);
if (c->buckets == NULL)
goto badmem;
c->rules = kcalloc(c->max_rules, sizeof(*c->rules), GFP_NOFS);
if (c->rules == NULL)
goto badmem;
for (i = 0; i < c->max_buckets; i++) {
int size = 0;
u32 alg;
struct crush_bucket *b;
ceph_decode_32_safe(p, end, alg, bad);
if (alg == 0) {
c->buckets[i] = NULL;
continue;
}
dout("crush_decode bucket %d off %x %p to %p\n",
i, (int)(*p-start), *p, end);
switch (alg) {
case CRUSH_BUCKET_UNIFORM:
size = sizeof(struct crush_bucket_uniform);
break;
case CRUSH_BUCKET_LIST:
size = sizeof(struct crush_bucket_list);
break;
case CRUSH_BUCKET_TREE:
size = sizeof(struct crush_bucket_tree);
break;
case CRUSH_BUCKET_STRAW:
size = sizeof(struct crush_bucket_straw);
break;
case CRUSH_BUCKET_STRAW2:
size = sizeof(struct crush_bucket_straw2);
break;
default:
err = -EINVAL;
goto bad;
}
BUG_ON(size == 0);
b = c->buckets[i] = kzalloc(size, GFP_NOFS);
if (b == NULL)
goto badmem;
ceph_decode_need(p, end, 4*sizeof(u32), bad);
b->id = ceph_decode_32(p);
b->type = ceph_decode_16(p);
b->alg = ceph_decode_8(p);
b->hash = ceph_decode_8(p);
b->weight = ceph_decode_32(p);
b->size = ceph_decode_32(p);
dout("crush_decode bucket size %d off %x %p to %p\n",
b->size, (int)(*p-start), *p, end);
b->items = kcalloc(b->size, sizeof(__s32), GFP_NOFS);
if (b->items == NULL)
goto badmem;
b->perm = kcalloc(b->size, sizeof(u32), GFP_NOFS);
if (b->perm == NULL)
goto badmem;
b->perm_n = 0;
ceph_decode_need(p, end, b->size*sizeof(u32), bad);
for (j = 0; j < b->size; j++)
b->items[j] = ceph_decode_32(p);
switch (b->alg) {
case CRUSH_BUCKET_UNIFORM:
err = crush_decode_uniform_bucket(p, end,
(struct crush_bucket_uniform *)b);
if (err < 0)
goto bad;
break;
case CRUSH_BUCKET_LIST:
err = crush_decode_list_bucket(p, end,
(struct crush_bucket_list *)b);
if (err < 0)
goto bad;
break;
case CRUSH_BUCKET_TREE:
err = crush_decode_tree_bucket(p, end,
(struct crush_bucket_tree *)b);
if (err < 0)
goto bad;
break;
case CRUSH_BUCKET_STRAW:
err = crush_decode_straw_bucket(p, end,
(struct crush_bucket_straw *)b);
if (err < 0)
goto bad;
break;
case CRUSH_BUCKET_STRAW2:
err = crush_decode_straw2_bucket(p, end,
(struct crush_bucket_straw2 *)b);
if (err < 0)
goto bad;
break;
}
}
dout("rule vec is %p\n", c->rules);
for (i = 0; i < c->max_rules; i++) {
u32 yes;
struct crush_rule *r;
ceph_decode_32_safe(p, end, yes, bad);
if (!yes) {
dout("crush_decode NO rule %d off %x %p to %p\n",
i, (int)(*p-start), *p, end);
c->rules[i] = NULL;
continue;
}
dout("crush_decode rule %d off %x %p to %p\n",
i, (int)(*p-start), *p, end);
ceph_decode_32_safe(p, end, yes, bad);
#if BITS_PER_LONG == 32
err = -EINVAL;
if (yes > (ULONG_MAX - sizeof(*r))
/ sizeof(struct crush_rule_step))
goto bad;
#endif
r = c->rules[i] = kmalloc(sizeof(*r) +
yes*sizeof(struct crush_rule_step),
GFP_NOFS);
if (r == NULL)
goto badmem;
dout(" rule %d is at %p\n", i, r);
r->len = yes;
ceph_decode_copy_safe(p, end, &r->mask, 4, bad);
ceph_decode_need(p, end, r->len*3*sizeof(u32), bad);
for (j = 0; j < r->len; j++) {
r->steps[j].op = ceph_decode_32(p);
r->steps[j].arg1 = ceph_decode_32(p);
r->steps[j].arg2 = ceph_decode_32(p);
}
}
for (num_name_maps = 0; num_name_maps < 3; num_name_maps++) {
err = skip_name_map(p, end);
if (err < 0)
goto done;
}
ceph_decode_need(p, end, 3*sizeof(u32), done);
c->choose_local_tries = ceph_decode_32(p);
c->choose_local_fallback_tries = ceph_decode_32(p);
c->choose_total_tries = ceph_decode_32(p);
dout("crush decode tunable choose_local_tries = %d\n",
c->choose_local_tries);
dout("crush decode tunable choose_local_fallback_tries = %d\n",
c->choose_local_fallback_tries);
dout("crush decode tunable choose_total_tries = %d\n",
c->choose_total_tries);
ceph_decode_need(p, end, sizeof(u32), done);
c->chooseleaf_descend_once = ceph_decode_32(p);
dout("crush decode tunable chooseleaf_descend_once = %d\n",
c->chooseleaf_descend_once);
ceph_decode_need(p, end, sizeof(u8), done);
c->chooseleaf_vary_r = ceph_decode_8(p);
dout("crush decode tunable chooseleaf_vary_r = %d\n",
c->chooseleaf_vary_r);
ceph_decode_need(p, end, sizeof(u8) + sizeof(u32), done);
*p += sizeof(u8) + sizeof(u32);
ceph_decode_need(p, end, sizeof(u8), done);
c->chooseleaf_stable = ceph_decode_8(p);
dout("crush decode tunable chooseleaf_stable = %d\n",
c->chooseleaf_stable);
done:
dout("crush_decode success\n");
return c;
badmem:
err = -ENOMEM;
bad:
dout("crush_decode fail %d\n", err);
crush_destroy(c);
return ERR_PTR(err);
}
int ceph_pg_compare(const struct ceph_pg *lhs, const struct ceph_pg *rhs)
{
if (lhs->pool < rhs->pool)
return -1;
if (lhs->pool > rhs->pool)
return 1;
if (lhs->seed < rhs->seed)
return -1;
if (lhs->seed > rhs->seed)
return 1;
return 0;
}
static int __insert_pg_mapping(struct ceph_pg_mapping *new,
struct rb_root *root)
{
struct rb_node **p = &root->rb_node;
struct rb_node *parent = NULL;
struct ceph_pg_mapping *pg = NULL;
int c;
dout("__insert_pg_mapping %llx %p\n", *(u64 *)&new->pgid, new);
while (*p) {
parent = *p;
pg = rb_entry(parent, struct ceph_pg_mapping, node);
c = ceph_pg_compare(&new->pgid, &pg->pgid);
if (c < 0)
p = &(*p)->rb_left;
else if (c > 0)
p = &(*p)->rb_right;
else
return -EEXIST;
}
rb_link_node(&new->node, parent, p);
rb_insert_color(&new->node, root);
return 0;
}
static struct ceph_pg_mapping *__lookup_pg_mapping(struct rb_root *root,
struct ceph_pg pgid)
{
struct rb_node *n = root->rb_node;
struct ceph_pg_mapping *pg;
int c;
while (n) {
pg = rb_entry(n, struct ceph_pg_mapping, node);
c = ceph_pg_compare(&pgid, &pg->pgid);
if (c < 0) {
n = n->rb_left;
} else if (c > 0) {
n = n->rb_right;
} else {
dout("__lookup_pg_mapping %lld.%x got %p\n",
pgid.pool, pgid.seed, pg);
return pg;
}
}
return NULL;
}
static int __remove_pg_mapping(struct rb_root *root, struct ceph_pg pgid)
{
struct ceph_pg_mapping *pg = __lookup_pg_mapping(root, pgid);
if (pg) {
dout("__remove_pg_mapping %lld.%x %p\n", pgid.pool, pgid.seed,
pg);
rb_erase(&pg->node, root);
kfree(pg);
return 0;
}
dout("__remove_pg_mapping %lld.%x dne\n", pgid.pool, pgid.seed);
return -ENOENT;
}
static int __insert_pg_pool(struct rb_root *root, struct ceph_pg_pool_info *new)
{
struct rb_node **p = &root->rb_node;
struct rb_node *parent = NULL;
struct ceph_pg_pool_info *pi = NULL;
while (*p) {
parent = *p;
pi = rb_entry(parent, struct ceph_pg_pool_info, node);
if (new->id < pi->id)
p = &(*p)->rb_left;
else if (new->id > pi->id)
p = &(*p)->rb_right;
else
return -EEXIST;
}
rb_link_node(&new->node, parent, p);
rb_insert_color(&new->node, root);
return 0;
}
static struct ceph_pg_pool_info *__lookup_pg_pool(struct rb_root *root, u64 id)
{
struct ceph_pg_pool_info *pi;
struct rb_node *n = root->rb_node;
while (n) {
pi = rb_entry(n, struct ceph_pg_pool_info, node);
if (id < pi->id)
n = n->rb_left;
else if (id > pi->id)
n = n->rb_right;
else
return pi;
}
return NULL;
}
struct ceph_pg_pool_info *ceph_pg_pool_by_id(struct ceph_osdmap *map, u64 id)
{
return __lookup_pg_pool(&map->pg_pools, id);
}
const char *ceph_pg_pool_name_by_id(struct ceph_osdmap *map, u64 id)
{
struct ceph_pg_pool_info *pi;
if (id == CEPH_NOPOOL)
return NULL;
if (WARN_ON_ONCE(id > (u64) INT_MAX))
return NULL;
pi = __lookup_pg_pool(&map->pg_pools, (int) id);
return pi ? pi->name : NULL;
}
int ceph_pg_poolid_by_name(struct ceph_osdmap *map, const char *name)
{
struct rb_node *rbp;
for (rbp = rb_first(&map->pg_pools); rbp; rbp = rb_next(rbp)) {
struct ceph_pg_pool_info *pi =
rb_entry(rbp, struct ceph_pg_pool_info, node);
if (pi->name && strcmp(pi->name, name) == 0)
return pi->id;
}
return -ENOENT;
}
static void __remove_pg_pool(struct rb_root *root, struct ceph_pg_pool_info *pi)
{
rb_erase(&pi->node, root);
kfree(pi->name);
kfree(pi);
}
static int decode_pool(void **p, void *end, struct ceph_pg_pool_info *pi)
{
u8 ev, cv;
unsigned len, num;
void *pool_end;
ceph_decode_need(p, end, 2 + 4, bad);
ev = ceph_decode_8(p);
cv = ceph_decode_8(p);
if (ev < 5) {
pr_warn("got v %d < 5 cv %d of ceph_pg_pool\n", ev, cv);
return -EINVAL;
}
if (cv > 9) {
pr_warn("got v %d cv %d > 9 of ceph_pg_pool\n", ev, cv);
return -EINVAL;
}
len = ceph_decode_32(p);
ceph_decode_need(p, end, len, bad);
pool_end = *p + len;
pi->type = ceph_decode_8(p);
pi->size = ceph_decode_8(p);
pi->crush_ruleset = ceph_decode_8(p);
pi->object_hash = ceph_decode_8(p);
pi->pg_num = ceph_decode_32(p);
pi->pgp_num = ceph_decode_32(p);
*p += 4 + 4;
*p += 4;
*p += 8 + 4;
num = ceph_decode_32(p);
while (num--) {
*p += 8;
*p += 1 + 1;
len = ceph_decode_32(p);
*p += len;
}
num = ceph_decode_32(p);
*p += num * (8 + 8);
*p += 8;
pi->flags = ceph_decode_64(p);
*p += 4;
if (ev >= 7)
pi->min_size = ceph_decode_8(p);
else
pi->min_size = pi->size - pi->size / 2;
if (ev >= 8)
*p += 8 + 8;
if (ev >= 9) {
num = ceph_decode_32(p);
*p += num * 8;
*p += 8;
*p += 1;
pi->read_tier = ceph_decode_64(p);
pi->write_tier = ceph_decode_64(p);
} else {
pi->read_tier = -1;
pi->write_tier = -1;
}
if (ev >= 10) {
num = ceph_decode_32(p);
while (num--) {
len = ceph_decode_32(p);
*p += len;
len = ceph_decode_32(p);
*p += len;
}
}
if (ev >= 11) {
*p += 1 + 1;
len = ceph_decode_32(p);
*p += len;
*p += 4;
*p += 4;
}
if (ev >= 12)
*p += 4;
if (ev >= 13) {
*p += 8;
*p += 8;
*p += 4;
*p += 4;
*p += 4;
*p += 4;
}
if (ev >= 14) {
len = ceph_decode_32(p);
*p += len;
}
if (ev >= 15)
pi->last_force_request_resend = ceph_decode_32(p);
else
pi->last_force_request_resend = 0;
*p = pool_end;
calc_pg_masks(pi);
return 0;
bad:
return -EINVAL;
}
static int decode_pool_names(void **p, void *end, struct ceph_osdmap *map)
{
struct ceph_pg_pool_info *pi;
u32 num, len;
u64 pool;
ceph_decode_32_safe(p, end, num, bad);
dout(" %d pool names\n", num);
while (num--) {
ceph_decode_64_safe(p, end, pool, bad);
ceph_decode_32_safe(p, end, len, bad);
dout(" pool %llu len %d\n", pool, len);
ceph_decode_need(p, end, len, bad);
pi = __lookup_pg_pool(&map->pg_pools, pool);
if (pi) {
char *name = kstrndup(*p, len, GFP_NOFS);
if (!name)
return -ENOMEM;
kfree(pi->name);
pi->name = name;
dout(" name is %s\n", pi->name);
}
*p += len;
}
return 0;
bad:
return -EINVAL;
}
struct ceph_osdmap *ceph_osdmap_alloc(void)
{
struct ceph_osdmap *map;
map = kzalloc(sizeof(*map), GFP_NOIO);
if (!map)
return NULL;
map->pg_pools = RB_ROOT;
map->pool_max = -1;
map->pg_temp = RB_ROOT;
map->primary_temp = RB_ROOT;
mutex_init(&map->crush_scratch_mutex);
return map;
}
void ceph_osdmap_destroy(struct ceph_osdmap *map)
{
dout("osdmap_destroy %p\n", map);
if (map->crush)
crush_destroy(map->crush);
while (!RB_EMPTY_ROOT(&map->pg_temp)) {
struct ceph_pg_mapping *pg =
rb_entry(rb_first(&map->pg_temp),
struct ceph_pg_mapping, node);
rb_erase(&pg->node, &map->pg_temp);
kfree(pg);
}
while (!RB_EMPTY_ROOT(&map->primary_temp)) {
struct ceph_pg_mapping *pg =
rb_entry(rb_first(&map->primary_temp),
struct ceph_pg_mapping, node);
rb_erase(&pg->node, &map->primary_temp);
kfree(pg);
}
while (!RB_EMPTY_ROOT(&map->pg_pools)) {
struct ceph_pg_pool_info *pi =
rb_entry(rb_first(&map->pg_pools),
struct ceph_pg_pool_info, node);
__remove_pg_pool(&map->pg_pools, pi);
}
kfree(map->osd_state);
kfree(map->osd_weight);
kfree(map->osd_addr);
kfree(map->osd_primary_affinity);
kfree(map);
}
static int osdmap_set_max_osd(struct ceph_osdmap *map, int max)
{
u8 *state;
u32 *weight;
struct ceph_entity_addr *addr;
int i;
state = krealloc(map->osd_state, max*sizeof(*state), GFP_NOFS);
if (!state)
return -ENOMEM;
map->osd_state = state;
weight = krealloc(map->osd_weight, max*sizeof(*weight), GFP_NOFS);
if (!weight)
return -ENOMEM;
map->osd_weight = weight;
addr = krealloc(map->osd_addr, max*sizeof(*addr), GFP_NOFS);
if (!addr)
return -ENOMEM;
map->osd_addr = addr;
for (i = map->max_osd; i < max; i++) {
map->osd_state[i] = 0;
map->osd_weight[i] = CEPH_OSD_OUT;
memset(map->osd_addr + i, 0, sizeof(*map->osd_addr));
}
if (map->osd_primary_affinity) {
u32 *affinity;
affinity = krealloc(map->osd_primary_affinity,
max*sizeof(*affinity), GFP_NOFS);
if (!affinity)
return -ENOMEM;
map->osd_primary_affinity = affinity;
for (i = map->max_osd; i < max; i++)
map->osd_primary_affinity[i] =
CEPH_OSD_DEFAULT_PRIMARY_AFFINITY;
}
map->max_osd = max;
return 0;
}
static int get_osdmap_client_data_v(void **p, void *end,
const char *prefix, u8 *v)
{
u8 struct_v;
ceph_decode_8_safe(p, end, struct_v, e_inval);
if (struct_v >= 7) {
u8 struct_compat;
ceph_decode_8_safe(p, end, struct_compat, e_inval);
if (struct_compat > OSDMAP_WRAPPER_COMPAT_VER) {
pr_warn("got v %d cv %d > %d of %s ceph_osdmap\n",
struct_v, struct_compat,
OSDMAP_WRAPPER_COMPAT_VER, prefix);
return -EINVAL;
}
*p += 4;
ceph_decode_8_safe(p, end, struct_v, e_inval);
ceph_decode_8_safe(p, end, struct_compat, e_inval);
if (struct_compat > OSDMAP_CLIENT_DATA_COMPAT_VER) {
pr_warn("got v %d cv %d > %d of %s ceph_osdmap client data\n",
struct_v, struct_compat,
OSDMAP_CLIENT_DATA_COMPAT_VER, prefix);
return -EINVAL;
}
*p += 4;
} else {
u16 version;
*p -= 1;
ceph_decode_16_safe(p, end, version, e_inval);
if (version < 6) {
pr_warn("got v %d < 6 of %s ceph_osdmap\n",
version, prefix);
return -EINVAL;
}
struct_v = 0;
}
*v = struct_v;
return 0;
e_inval:
return -EINVAL;
}
static int __decode_pools(void **p, void *end, struct ceph_osdmap *map,
bool incremental)
{
u32 n;
ceph_decode_32_safe(p, end, n, e_inval);
while (n--) {
struct ceph_pg_pool_info *pi;
u64 pool;
int ret;
ceph_decode_64_safe(p, end, pool, e_inval);
pi = __lookup_pg_pool(&map->pg_pools, pool);
if (!incremental || !pi) {
pi = kzalloc(sizeof(*pi), GFP_NOFS);
if (!pi)
return -ENOMEM;
pi->id = pool;
ret = __insert_pg_pool(&map->pg_pools, pi);
if (ret) {
kfree(pi);
return ret;
}
}
ret = decode_pool(p, end, pi);
if (ret)
return ret;
}
return 0;
e_inval:
return -EINVAL;
}
static int decode_pools(void **p, void *end, struct ceph_osdmap *map)
{
return __decode_pools(p, end, map, false);
}
static int decode_new_pools(void **p, void *end, struct ceph_osdmap *map)
{
return __decode_pools(p, end, map, true);
}
static int __decode_pg_temp(void **p, void *end, struct ceph_osdmap *map,
bool incremental)
{
u32 n;
ceph_decode_32_safe(p, end, n, e_inval);
while (n--) {
struct ceph_pg pgid;
u32 len, i;
int ret;
ret = ceph_decode_pgid(p, end, &pgid);
if (ret)
return ret;
ceph_decode_32_safe(p, end, len, e_inval);
ret = __remove_pg_mapping(&map->pg_temp, pgid);
BUG_ON(!incremental && ret != -ENOENT);
if (!incremental || len > 0) {
struct ceph_pg_mapping *pg;
ceph_decode_need(p, end, len*sizeof(u32), e_inval);
if (len > (UINT_MAX - sizeof(*pg)) / sizeof(u32))
return -EINVAL;
pg = kzalloc(sizeof(*pg) + len*sizeof(u32), GFP_NOFS);
if (!pg)
return -ENOMEM;
pg->pgid = pgid;
pg->pg_temp.len = len;
for (i = 0; i < len; i++)
pg->pg_temp.osds[i] = ceph_decode_32(p);
ret = __insert_pg_mapping(pg, &map->pg_temp);
if (ret) {
kfree(pg);
return ret;
}
}
}
return 0;
e_inval:
return -EINVAL;
}
static int decode_pg_temp(void **p, void *end, struct ceph_osdmap *map)
{
return __decode_pg_temp(p, end, map, false);
}
static int decode_new_pg_temp(void **p, void *end, struct ceph_osdmap *map)
{
return __decode_pg_temp(p, end, map, true);
}
static int __decode_primary_temp(void **p, void *end, struct ceph_osdmap *map,
bool incremental)
{
u32 n;
ceph_decode_32_safe(p, end, n, e_inval);
while (n--) {
struct ceph_pg pgid;
u32 osd;
int ret;
ret = ceph_decode_pgid(p, end, &pgid);
if (ret)
return ret;
ceph_decode_32_safe(p, end, osd, e_inval);
ret = __remove_pg_mapping(&map->primary_temp, pgid);
BUG_ON(!incremental && ret != -ENOENT);
if (!incremental || osd != (u32)-1) {
struct ceph_pg_mapping *pg;
pg = kzalloc(sizeof(*pg), GFP_NOFS);
if (!pg)
return -ENOMEM;
pg->pgid = pgid;
pg->primary_temp.osd = osd;
ret = __insert_pg_mapping(pg, &map->primary_temp);
if (ret) {
kfree(pg);
return ret;
}
}
}
return 0;
e_inval:
return -EINVAL;
}
static int decode_primary_temp(void **p, void *end, struct ceph_osdmap *map)
{
return __decode_primary_temp(p, end, map, false);
}
static int decode_new_primary_temp(void **p, void *end,
struct ceph_osdmap *map)
{
return __decode_primary_temp(p, end, map, true);
}
u32 ceph_get_primary_affinity(struct ceph_osdmap *map, int osd)
{
BUG_ON(osd >= map->max_osd);
if (!map->osd_primary_affinity)
return CEPH_OSD_DEFAULT_PRIMARY_AFFINITY;
return map->osd_primary_affinity[osd];
}
static int set_primary_affinity(struct ceph_osdmap *map, int osd, u32 aff)
{
BUG_ON(osd >= map->max_osd);
if (!map->osd_primary_affinity) {
int i;
map->osd_primary_affinity = kmalloc(map->max_osd*sizeof(u32),
GFP_NOFS);
if (!map->osd_primary_affinity)
return -ENOMEM;
for (i = 0; i < map->max_osd; i++)
map->osd_primary_affinity[i] =
CEPH_OSD_DEFAULT_PRIMARY_AFFINITY;
}
map->osd_primary_affinity[osd] = aff;
return 0;
}
static int decode_primary_affinity(void **p, void *end,
struct ceph_osdmap *map)
{
u32 len, i;
ceph_decode_32_safe(p, end, len, e_inval);
if (len == 0) {
kfree(map->osd_primary_affinity);
map->osd_primary_affinity = NULL;
return 0;
}
if (len != map->max_osd)
goto e_inval;
ceph_decode_need(p, end, map->max_osd*sizeof(u32), e_inval);
for (i = 0; i < map->max_osd; i++) {
int ret;
ret = set_primary_affinity(map, i, ceph_decode_32(p));
if (ret)
return ret;
}
return 0;
e_inval:
return -EINVAL;
}
static int decode_new_primary_affinity(void **p, void *end,
struct ceph_osdmap *map)
{
u32 n;
ceph_decode_32_safe(p, end, n, e_inval);
while (n--) {
u32 osd, aff;
int ret;
ceph_decode_32_safe(p, end, osd, e_inval);
ceph_decode_32_safe(p, end, aff, e_inval);
ret = set_primary_affinity(map, osd, aff);
if (ret)
return ret;
pr_info("osd%d primary-affinity 0x%x\n", osd, aff);
}
return 0;
e_inval:
return -EINVAL;
}
static int osdmap_decode(void **p, void *end, struct ceph_osdmap *map)
{
u8 struct_v;
u32 epoch = 0;
void *start = *p;
u32 max;
u32 len, i;
int err;
dout("%s %p to %p len %d\n", __func__, *p, end, (int)(end - *p));
err = get_osdmap_client_data_v(p, end, "full", &struct_v);
if (err)
goto bad;
ceph_decode_need(p, end, sizeof(map->fsid) + sizeof(u32) +
sizeof(map->created) + sizeof(map->modified), e_inval);
ceph_decode_copy(p, &map->fsid, sizeof(map->fsid));
epoch = map->epoch = ceph_decode_32(p);
ceph_decode_copy(p, &map->created, sizeof(map->created));
ceph_decode_copy(p, &map->modified, sizeof(map->modified));
err = decode_pools(p, end, map);
if (err)
goto bad;
err = decode_pool_names(p, end, map);
if (err)
goto bad;
ceph_decode_32_safe(p, end, map->pool_max, e_inval);
ceph_decode_32_safe(p, end, map->flags, e_inval);
ceph_decode_32_safe(p, end, max, e_inval);
err = osdmap_set_max_osd(map, max);
if (err)
goto bad;
ceph_decode_need(p, end, 3*sizeof(u32) +
map->max_osd*(1 + sizeof(*map->osd_weight) +
sizeof(*map->osd_addr)), e_inval);
if (ceph_decode_32(p) != map->max_osd)
goto e_inval;
ceph_decode_copy(p, map->osd_state, map->max_osd);
if (ceph_decode_32(p) != map->max_osd)
goto e_inval;
for (i = 0; i < map->max_osd; i++)
map->osd_weight[i] = ceph_decode_32(p);
if (ceph_decode_32(p) != map->max_osd)
goto e_inval;
ceph_decode_copy(p, map->osd_addr, map->max_osd*sizeof(*map->osd_addr));
for (i = 0; i < map->max_osd; i++)
ceph_decode_addr(&map->osd_addr[i]);
err = decode_pg_temp(p, end, map);
if (err)
goto bad;
if (struct_v >= 1) {
err = decode_primary_temp(p, end, map);
if (err)
goto bad;
}
if (struct_v >= 2) {
err = decode_primary_affinity(p, end, map);
if (err)
goto bad;
} else {
kfree(map->osd_primary_affinity);
map->osd_primary_affinity = NULL;
}
ceph_decode_32_safe(p, end, len, e_inval);
map->crush = crush_decode(*p, min(*p + len, end));
if (IS_ERR(map->crush)) {
err = PTR_ERR(map->crush);
map->crush = NULL;
goto bad;
}
*p += len;
*p = end;
dout("full osdmap epoch %d max_osd %d\n", map->epoch, map->max_osd);
return 0;
e_inval:
err = -EINVAL;
bad:
pr_err("corrupt full osdmap (%d) epoch %d off %d (%p of %p-%p)\n",
err, epoch, (int)(*p - start), *p, start, end);
print_hex_dump(KERN_DEBUG, "osdmap: ",
DUMP_PREFIX_OFFSET, 16, 1,
start, end - start, true);
return err;
}
struct ceph_osdmap *ceph_osdmap_decode(void **p, void *end)
{
struct ceph_osdmap *map;
int ret;
map = ceph_osdmap_alloc();
if (!map)
return ERR_PTR(-ENOMEM);
ret = osdmap_decode(p, end, map);
if (ret) {
ceph_osdmap_destroy(map);
return ERR_PTR(ret);
}
return map;
}
static int decode_new_up_state_weight(void **p, void *end,
struct ceph_osdmap *map)
{
void *new_up_client;
void *new_state;
void *new_weight_end;
u32 len;
new_up_client = *p;
ceph_decode_32_safe(p, end, len, e_inval);
len *= sizeof(u32) + sizeof(struct ceph_entity_addr);
ceph_decode_need(p, end, len, e_inval);
*p += len;
new_state = *p;
ceph_decode_32_safe(p, end, len, e_inval);
len *= sizeof(u32) + sizeof(u8);
ceph_decode_need(p, end, len, e_inval);
*p += len;
ceph_decode_32_safe(p, end, len, e_inval);
while (len--) {
s32 osd;
u32 w;
ceph_decode_need(p, end, 2*sizeof(u32), e_inval);
osd = ceph_decode_32(p);
w = ceph_decode_32(p);
BUG_ON(osd >= map->max_osd);
pr_info("osd%d weight 0x%x %s\n", osd, w,
w == CEPH_OSD_IN ? "(in)" :
(w == CEPH_OSD_OUT ? "(out)" : ""));
map->osd_weight[osd] = w;
if (w) {
map->osd_state[osd] |= CEPH_OSD_EXISTS;
map->osd_state[osd] &= ~(CEPH_OSD_AUTOOUT |
CEPH_OSD_NEW);
}
}
new_weight_end = *p;
*p = new_state;
len = ceph_decode_32(p);
while (len--) {
s32 osd;
u8 xorstate;
int ret;
osd = ceph_decode_32(p);
xorstate = ceph_decode_8(p);
if (xorstate == 0)
xorstate = CEPH_OSD_UP;
BUG_ON(osd >= map->max_osd);
if ((map->osd_state[osd] & CEPH_OSD_UP) &&
(xorstate & CEPH_OSD_UP))
pr_info("osd%d down\n", osd);
if ((map->osd_state[osd] & CEPH_OSD_EXISTS) &&
(xorstate & CEPH_OSD_EXISTS)) {
pr_info("osd%d does not exist\n", osd);
map->osd_weight[osd] = CEPH_OSD_IN;
ret = set_primary_affinity(map, osd,
CEPH_OSD_DEFAULT_PRIMARY_AFFINITY);
if (ret)
return ret;
memset(map->osd_addr + osd, 0, sizeof(*map->osd_addr));
map->osd_state[osd] = 0;
} else {
map->osd_state[osd] ^= xorstate;
}
}
*p = new_up_client;
len = ceph_decode_32(p);
while (len--) {
s32 osd;
struct ceph_entity_addr addr;
osd = ceph_decode_32(p);
ceph_decode_copy(p, &addr, sizeof(addr));
ceph_decode_addr(&addr);
BUG_ON(osd >= map->max_osd);
pr_info("osd%d up\n", osd);
map->osd_state[osd] |= CEPH_OSD_EXISTS | CEPH_OSD_UP;
map->osd_addr[osd] = addr;
}
*p = new_weight_end;
return 0;
e_inval:
return -EINVAL;
}
struct ceph_osdmap *osdmap_apply_incremental(void **p, void *end,
struct ceph_osdmap *map)
{
struct crush_map *newcrush = NULL;
struct ceph_fsid fsid;
u32 epoch = 0;
struct ceph_timespec modified;
s32 len;
u64 pool;
__s64 new_pool_max;
__s32 new_flags, max;
void *start = *p;
int err;
u8 struct_v;
dout("%s %p to %p len %d\n", __func__, *p, end, (int)(end - *p));
err = get_osdmap_client_data_v(p, end, "inc", &struct_v);
if (err)
goto bad;
ceph_decode_need(p, end, sizeof(fsid) + sizeof(u32) + sizeof(modified) +
sizeof(u64) + sizeof(u32), e_inval);
ceph_decode_copy(p, &fsid, sizeof(fsid));
epoch = ceph_decode_32(p);
BUG_ON(epoch != map->epoch+1);
ceph_decode_copy(p, &modified, sizeof(modified));
new_pool_max = ceph_decode_64(p);
new_flags = ceph_decode_32(p);
ceph_decode_32_safe(p, end, len, e_inval);
if (len > 0) {
dout("apply_incremental full map len %d, %p to %p\n",
len, *p, end);
return ceph_osdmap_decode(p, min(*p+len, end));
}
ceph_decode_32_safe(p, end, len, e_inval);
if (len > 0) {
newcrush = crush_decode(*p, min(*p+len, end));
if (IS_ERR(newcrush)) {
err = PTR_ERR(newcrush);
newcrush = NULL;
goto bad;
}
*p += len;
}
if (new_flags >= 0)
map->flags = new_flags;
if (new_pool_max >= 0)
map->pool_max = new_pool_max;
ceph_decode_32_safe(p, end, max, e_inval);
if (max >= 0) {
err = osdmap_set_max_osd(map, max);
if (err)
goto bad;
}
map->epoch++;
map->modified = modified;
if (newcrush) {
if (map->crush)
crush_destroy(map->crush);
map->crush = newcrush;
newcrush = NULL;
}
err = decode_new_pools(p, end, map);
if (err)
goto bad;
err = decode_pool_names(p, end, map);
if (err)
goto bad;
ceph_decode_32_safe(p, end, len, e_inval);
while (len--) {
struct ceph_pg_pool_info *pi;
ceph_decode_64_safe(p, end, pool, e_inval);
pi = __lookup_pg_pool(&map->pg_pools, pool);
if (pi)
__remove_pg_pool(&map->pg_pools, pi);
}
err = decode_new_up_state_weight(p, end, map);
if (err)
goto bad;
err = decode_new_pg_temp(p, end, map);
if (err)
goto bad;
if (struct_v >= 1) {
err = decode_new_primary_temp(p, end, map);
if (err)
goto bad;
}
if (struct_v >= 2) {
err = decode_new_primary_affinity(p, end, map);
if (err)
goto bad;
}
*p = end;
dout("inc osdmap epoch %d max_osd %d\n", map->epoch, map->max_osd);
return map;
e_inval:
err = -EINVAL;
bad:
pr_err("corrupt inc osdmap (%d) epoch %d off %d (%p of %p-%p)\n",
err, epoch, (int)(*p - start), *p, start, end);
print_hex_dump(KERN_DEBUG, "osdmap: ",
DUMP_PREFIX_OFFSET, 16, 1,
start, end - start, true);
if (newcrush)
crush_destroy(newcrush);
return ERR_PTR(err);
}
void ceph_oloc_copy(struct ceph_object_locator *dest,
const struct ceph_object_locator *src)
{
WARN_ON(!ceph_oloc_empty(dest));
WARN_ON(dest->pool_ns);
dest->pool = src->pool;
if (src->pool_ns)
dest->pool_ns = ceph_get_string(src->pool_ns);
}
void ceph_oloc_destroy(struct ceph_object_locator *oloc)
{
ceph_put_string(oloc->pool_ns);
}
void ceph_oid_copy(struct ceph_object_id *dest,
const struct ceph_object_id *src)
{
WARN_ON(!ceph_oid_empty(dest));
if (src->name != src->inline_name) {
dest->name = kmalloc(src->name_len + 1,
GFP_NOIO | __GFP_NOFAIL);
}
memcpy(dest->name, src->name, src->name_len + 1);
dest->name_len = src->name_len;
}
void ceph_oid_destroy(struct ceph_object_id *oid)
{
if (oid->name != oid->inline_name)
kfree(oid->name);
}
static bool __osds_equal(const struct ceph_osds *lhs,
const struct ceph_osds *rhs)
{
if (lhs->size == rhs->size &&
!memcmp(lhs->osds, rhs->osds, rhs->size * sizeof(rhs->osds[0])))
return true;
return false;
}
static bool osds_equal(const struct ceph_osds *lhs,
const struct ceph_osds *rhs)
{
if (__osds_equal(lhs, rhs) &&
lhs->primary == rhs->primary)
return true;
return false;
}
static bool osds_valid(const struct ceph_osds *set)
{
if (set->size > 0 && set->primary >= 0)
return true;
if (!set->size && set->primary == -1)
return true;
if (set->size > 0 && set->primary == -1) {
int i;
for (i = 0; i < set->size; i++) {
if (set->osds[i] != CRUSH_ITEM_NONE)
break;
}
if (i == set->size)
return true;
}
return false;
}
void ceph_osds_copy(struct ceph_osds *dest, const struct ceph_osds *src)
{
memcpy(dest->osds, src->osds, src->size * sizeof(src->osds[0]));
dest->size = src->size;
dest->primary = src->primary;
}
static bool is_split(const struct ceph_pg *pgid,
u32 old_pg_num,
u32 new_pg_num)
{
int old_bits = calc_bits_of(old_pg_num);
int old_mask = (1 << old_bits) - 1;
int n;
WARN_ON(pgid->seed >= old_pg_num);
if (new_pg_num <= old_pg_num)
return false;
for (n = 1; ; n++) {
int next_bit = n << (old_bits - 1);
u32 s = next_bit | pgid->seed;
if (s < old_pg_num || s == pgid->seed)
continue;
if (s >= new_pg_num)
break;
s = ceph_stable_mod(s, old_pg_num, old_mask);
if (s == pgid->seed)
return true;
}
return false;
}
bool ceph_is_new_interval(const struct ceph_osds *old_acting,
const struct ceph_osds *new_acting,
const struct ceph_osds *old_up,
const struct ceph_osds *new_up,
int old_size,
int new_size,
int old_min_size,
int new_min_size,
u32 old_pg_num,
u32 new_pg_num,
bool old_sort_bitwise,
bool new_sort_bitwise,
const struct ceph_pg *pgid)
{
return !osds_equal(old_acting, new_acting) ||
!osds_equal(old_up, new_up) ||
old_size != new_size ||
old_min_size != new_min_size ||
is_split(pgid, old_pg_num, new_pg_num) ||
old_sort_bitwise != new_sort_bitwise;
}
static int calc_pg_rank(int osd, const struct ceph_osds *acting)
{
int i;
for (i = 0; i < acting->size; i++) {
if (acting->osds[i] == osd)
return i;
}
return -1;
}
static bool primary_changed(const struct ceph_osds *old_acting,
const struct ceph_osds *new_acting)
{
if (!old_acting->size && !new_acting->size)
return false;
if (!old_acting->size ^ !new_acting->size)
return true;
if (old_acting->primary != new_acting->primary)
return true;
if (calc_pg_rank(old_acting->primary, old_acting) !=
calc_pg_rank(new_acting->primary, new_acting))
return true;
return false;
}
bool ceph_osds_changed(const struct ceph_osds *old_acting,
const struct ceph_osds *new_acting,
bool any_change)
{
if (primary_changed(old_acting, new_acting))
return true;
if (any_change && !__osds_equal(old_acting, new_acting))
return true;
return false;
}
int ceph_calc_file_object_mapping(struct ceph_file_layout *layout,
u64 off, u64 len,
u64 *ono,
u64 *oxoff, u64 *oxlen)
{
u32 osize = layout->object_size;
u32 su = layout->stripe_unit;
u32 sc = layout->stripe_count;
u32 bl, stripeno, stripepos, objsetno;
u32 su_per_object;
u64 t, su_offset;
dout("mapping %llu~%llu osize %u fl_su %u\n", off, len,
osize, su);
if (su == 0 || sc == 0)
goto invalid;
su_per_object = osize / su;
if (su_per_object == 0)
goto invalid;
dout("osize %u / su %u = su_per_object %u\n", osize, su,
su_per_object);
if ((su & ~PAGE_MASK) != 0)
goto invalid;
t = off;
do_div(t, su);
bl = t;
dout("off %llu / su %u = bl %u\n", off, su, bl);
stripeno = bl / sc;
stripepos = bl % sc;
objsetno = stripeno / su_per_object;
*ono = objsetno * sc + stripepos;
dout("objset %u * sc %u = ono %u\n", objsetno, sc, (unsigned int)*ono);
t = off;
su_offset = do_div(t, su);
*oxoff = su_offset + (stripeno % su_per_object) * su;
*oxlen = min_t(u64, len, su - su_offset);
dout(" obj extent %llu~%llu\n", *oxoff, *oxlen);
return 0;
invalid:
dout(" invalid layout\n");
*ono = 0;
*oxoff = 0;
*oxlen = 0;
return -EINVAL;
}
int ceph_object_locator_to_pg(struct ceph_osdmap *osdmap,
struct ceph_object_id *oid,
struct ceph_object_locator *oloc,
struct ceph_pg *raw_pgid)
{
struct ceph_pg_pool_info *pi;
pi = ceph_pg_pool_by_id(osdmap, oloc->pool);
if (!pi)
return -ENOENT;
if (!oloc->pool_ns) {
raw_pgid->pool = oloc->pool;
raw_pgid->seed = ceph_str_hash(pi->object_hash, oid->name,
oid->name_len);
dout("%s %s -> raw_pgid %llu.%x\n", __func__, oid->name,
raw_pgid->pool, raw_pgid->seed);
} else {
char stack_buf[256];
char *buf = stack_buf;
int nsl = oloc->pool_ns->len;
size_t total = nsl + 1 + oid->name_len;
if (total > sizeof(stack_buf)) {
buf = kmalloc(total, GFP_NOIO);
if (!buf)
return -ENOMEM;
}
memcpy(buf, oloc->pool_ns->str, nsl);
buf[nsl] = '\037';
memcpy(buf + nsl + 1, oid->name, oid->name_len);
raw_pgid->pool = oloc->pool;
raw_pgid->seed = ceph_str_hash(pi->object_hash, buf, total);
if (buf != stack_buf)
kfree(buf);
dout("%s %s ns %.*s -> raw_pgid %llu.%x\n", __func__,
oid->name, nsl, oloc->pool_ns->str,
raw_pgid->pool, raw_pgid->seed);
}
return 0;
}
static void raw_pg_to_pg(struct ceph_pg_pool_info *pi,
const struct ceph_pg *raw_pgid,
struct ceph_pg *pgid)
{
pgid->pool = raw_pgid->pool;
pgid->seed = ceph_stable_mod(raw_pgid->seed, pi->pg_num,
pi->pg_num_mask);
}
static u32 raw_pg_to_pps(struct ceph_pg_pool_info *pi,
const struct ceph_pg *raw_pgid)
{
if (pi->flags & CEPH_POOL_FLAG_HASHPSPOOL) {
return crush_hash32_2(CRUSH_HASH_RJENKINS1,
ceph_stable_mod(raw_pgid->seed,
pi->pgp_num,
pi->pgp_num_mask),
raw_pgid->pool);
} else {
return ceph_stable_mod(raw_pgid->seed, pi->pgp_num,
pi->pgp_num_mask) +
(unsigned)raw_pgid->pool;
}
}
static int do_crush(struct ceph_osdmap *map, int ruleno, int x,
int *result, int result_max,
const __u32 *weight, int weight_max)
{
int r;
BUG_ON(result_max > CEPH_PG_MAX_SIZE);
mutex_lock(&map->crush_scratch_mutex);
r = crush_do_rule(map->crush, ruleno, x, result, result_max,
weight, weight_max, map->crush_scratch_ary);
mutex_unlock(&map->crush_scratch_mutex);
return r;
}
static void pg_to_raw_osds(struct ceph_osdmap *osdmap,
struct ceph_pg_pool_info *pi,
const struct ceph_pg *raw_pgid,
struct ceph_osds *raw,
u32 *ppps)
{
u32 pps = raw_pg_to_pps(pi, raw_pgid);
int ruleno;
int len;
ceph_osds_init(raw);
if (ppps)
*ppps = pps;
ruleno = crush_find_rule(osdmap->crush, pi->crush_ruleset, pi->type,
pi->size);
if (ruleno < 0) {
pr_err("no crush rule: pool %lld ruleset %d type %d size %d\n",
pi->id, pi->crush_ruleset, pi->type, pi->size);
return;
}
len = do_crush(osdmap, ruleno, pps, raw->osds,
min_t(int, pi->size, ARRAY_SIZE(raw->osds)),
osdmap->osd_weight, osdmap->max_osd);
if (len < 0) {
pr_err("error %d from crush rule %d: pool %lld ruleset %d type %d size %d\n",
len, ruleno, pi->id, pi->crush_ruleset, pi->type,
pi->size);
return;
}
raw->size = len;
}
static void raw_to_up_osds(struct ceph_osdmap *osdmap,
struct ceph_pg_pool_info *pi,
struct ceph_osds *set)
{
int i;
BUG_ON(set->primary != -1);
if (ceph_can_shift_osds(pi)) {
int removed = 0;
for (i = 0; i < set->size; i++) {
if (ceph_osd_is_down(osdmap, set->osds[i])) {
removed++;
continue;
}
if (removed)
set->osds[i - removed] = set->osds[i];
}
set->size -= removed;
if (set->size > 0)
set->primary = set->osds[0];
} else {
for (i = set->size - 1; i >= 0; i--) {
if (ceph_osd_is_down(osdmap, set->osds[i]))
set->osds[i] = CRUSH_ITEM_NONE;
else
set->primary = set->osds[i];
}
}
}
static void apply_primary_affinity(struct ceph_osdmap *osdmap,
struct ceph_pg_pool_info *pi,
u32 pps,
struct ceph_osds *up)
{
int i;
int pos = -1;
if (!osdmap->osd_primary_affinity)
return;
for (i = 0; i < up->size; i++) {
int osd = up->osds[i];
if (osd != CRUSH_ITEM_NONE &&
osdmap->osd_primary_affinity[osd] !=
CEPH_OSD_DEFAULT_PRIMARY_AFFINITY) {
break;
}
}
if (i == up->size)
return;
for (i = 0; i < up->size; i++) {
int osd = up->osds[i];
u32 aff;
if (osd == CRUSH_ITEM_NONE)
continue;
aff = osdmap->osd_primary_affinity[osd];
if (aff < CEPH_OSD_MAX_PRIMARY_AFFINITY &&
(crush_hash32_2(CRUSH_HASH_RJENKINS1,
pps, osd) >> 16) >= aff) {
if (pos < 0)
pos = i;
} else {
pos = i;
break;
}
}
if (pos < 0)
return;
up->primary = up->osds[pos];
if (ceph_can_shift_osds(pi) && pos > 0) {
for (i = pos; i > 0; i--)
up->osds[i] = up->osds[i - 1];
up->osds[0] = up->primary;
}
}
static void get_temp_osds(struct ceph_osdmap *osdmap,
struct ceph_pg_pool_info *pi,
const struct ceph_pg *raw_pgid,
struct ceph_osds *temp)
{
struct ceph_pg pgid;
struct ceph_pg_mapping *pg;
int i;
raw_pg_to_pg(pi, raw_pgid, &pgid);
ceph_osds_init(temp);
pg = __lookup_pg_mapping(&osdmap->pg_temp, pgid);
if (pg) {
for (i = 0; i < pg->pg_temp.len; i++) {
if (ceph_osd_is_down(osdmap, pg->pg_temp.osds[i])) {
if (ceph_can_shift_osds(pi))
continue;
temp->osds[temp->size++] = CRUSH_ITEM_NONE;
} else {
temp->osds[temp->size++] = pg->pg_temp.osds[i];
}
}
for (i = 0; i < temp->size; i++) {
if (temp->osds[i] != CRUSH_ITEM_NONE) {
temp->primary = temp->osds[i];
break;
}
}
}
pg = __lookup_pg_mapping(&osdmap->primary_temp, pgid);
if (pg)
temp->primary = pg->primary_temp.osd;
}
void ceph_pg_to_up_acting_osds(struct ceph_osdmap *osdmap,
const struct ceph_pg *raw_pgid,
struct ceph_osds *up,
struct ceph_osds *acting)
{
struct ceph_pg_pool_info *pi;
u32 pps;
pi = ceph_pg_pool_by_id(osdmap, raw_pgid->pool);
if (!pi) {
ceph_osds_init(up);
ceph_osds_init(acting);
goto out;
}
pg_to_raw_osds(osdmap, pi, raw_pgid, up, &pps);
raw_to_up_osds(osdmap, pi, up);
apply_primary_affinity(osdmap, pi, pps, up);
get_temp_osds(osdmap, pi, raw_pgid, acting);
if (!acting->size) {
memcpy(acting->osds, up->osds, up->size * sizeof(up->osds[0]));
acting->size = up->size;
if (acting->primary == -1)
acting->primary = up->primary;
}
out:
WARN_ON(!osds_valid(up) || !osds_valid(acting));
}
int ceph_pg_to_acting_primary(struct ceph_osdmap *osdmap,
const struct ceph_pg *raw_pgid)
{
struct ceph_osds up, acting;
ceph_pg_to_up_acting_osds(osdmap, raw_pgid, &up, &acting);
return acting.primary;
}
