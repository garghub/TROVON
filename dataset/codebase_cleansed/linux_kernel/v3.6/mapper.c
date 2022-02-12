int crush_find_rule(const struct crush_map *map, int ruleset, int type, int size)
{
__u32 i;
for (i = 0; i < map->max_rules; i++) {
if (map->rules[i] &&
map->rules[i]->mask.ruleset == ruleset &&
map->rules[i]->mask.type == type &&
map->rules[i]->mask.min_size <= size &&
map->rules[i]->mask.max_size >= size)
return i;
}
return -1;
}
static int bucket_perm_choose(struct crush_bucket *bucket,
int x, int r)
{
unsigned int pr = r % bucket->size;
unsigned int i, s;
if (bucket->perm_x != (__u32)x || bucket->perm_n == 0) {
dprintk("bucket %d new x=%d\n", bucket->id, x);
bucket->perm_x = x;
if (pr == 0) {
s = crush_hash32_3(bucket->hash, x, bucket->id, 0) %
bucket->size;
bucket->perm[0] = s;
bucket->perm_n = 0xffff;
goto out;
}
for (i = 0; i < bucket->size; i++)
bucket->perm[i] = i;
bucket->perm_n = 0;
} else if (bucket->perm_n == 0xffff) {
for (i = 1; i < bucket->size; i++)
bucket->perm[i] = i;
bucket->perm[bucket->perm[0]] = 0;
bucket->perm_n = 1;
}
for (i = 0; i < bucket->perm_n; i++)
dprintk(" perm_choose have %d: %d\n", i, bucket->perm[i]);
while (bucket->perm_n <= pr) {
unsigned int p = bucket->perm_n;
if (p < bucket->size - 1) {
i = crush_hash32_3(bucket->hash, x, bucket->id, p) %
(bucket->size - p);
if (i) {
unsigned int t = bucket->perm[p + i];
bucket->perm[p + i] = bucket->perm[p];
bucket->perm[p] = t;
}
dprintk(" perm_choose swap %d with %d\n", p, p+i);
}
bucket->perm_n++;
}
for (i = 0; i < bucket->size; i++)
dprintk(" perm_choose %d: %d\n", i, bucket->perm[i]);
s = bucket->perm[pr];
out:
dprintk(" perm_choose %d sz=%d x=%d r=%d (%d) s=%d\n", bucket->id,
bucket->size, x, r, pr, s);
return bucket->items[s];
}
static int bucket_uniform_choose(struct crush_bucket_uniform *bucket,
int x, int r)
{
return bucket_perm_choose(&bucket->h, x, r);
}
static int bucket_list_choose(struct crush_bucket_list *bucket,
int x, int r)
{
int i;
for (i = bucket->h.size-1; i >= 0; i--) {
__u64 w = crush_hash32_4(bucket->h.hash,x, bucket->h.items[i],
r, bucket->h.id);
w &= 0xffff;
dprintk("list_choose i=%d x=%d r=%d item %d weight %x "
"sw %x rand %llx",
i, x, r, bucket->h.items[i], bucket->item_weights[i],
bucket->sum_weights[i], w);
w *= bucket->sum_weights[i];
w = w >> 16;
if (w < bucket->item_weights[i])
return bucket->h.items[i];
}
dprintk("bad list sums for bucket %d\n", bucket->h.id);
return bucket->h.items[0];
}
static int height(int n)
{
int h = 0;
while ((n & 1) == 0) {
h++;
n = n >> 1;
}
return h;
}
static int left(int x)
{
int h = height(x);
return x - (1 << (h-1));
}
static int right(int x)
{
int h = height(x);
return x + (1 << (h-1));
}
static int terminal(int x)
{
return x & 1;
}
static int bucket_tree_choose(struct crush_bucket_tree *bucket,
int x, int r)
{
int n, l;
__u32 w;
__u64 t;
n = bucket->num_nodes >> 1;
while (!terminal(n)) {
w = bucket->node_weights[n];
t = (__u64)crush_hash32_4(bucket->h.hash, x, n, r,
bucket->h.id) * (__u64)w;
t = t >> 32;
l = left(n);
if (t < bucket->node_weights[l])
n = l;
else
n = right(n);
}
return bucket->h.items[n >> 1];
}
static int bucket_straw_choose(struct crush_bucket_straw *bucket,
int x, int r)
{
__u32 i;
int high = 0;
__u64 high_draw = 0;
__u64 draw;
for (i = 0; i < bucket->h.size; i++) {
draw = crush_hash32_3(bucket->h.hash, x, bucket->h.items[i], r);
draw &= 0xffff;
draw *= bucket->straws[i];
if (i == 0 || draw > high_draw) {
high = i;
high_draw = draw;
}
}
return bucket->h.items[high];
}
static int crush_bucket_choose(struct crush_bucket *in, int x, int r)
{
dprintk(" crush_bucket_choose %d x=%d r=%d\n", in->id, x, r);
BUG_ON(in->size == 0);
switch (in->alg) {
case CRUSH_BUCKET_UNIFORM:
return bucket_uniform_choose((struct crush_bucket_uniform *)in,
x, r);
case CRUSH_BUCKET_LIST:
return bucket_list_choose((struct crush_bucket_list *)in,
x, r);
case CRUSH_BUCKET_TREE:
return bucket_tree_choose((struct crush_bucket_tree *)in,
x, r);
case CRUSH_BUCKET_STRAW:
return bucket_straw_choose((struct crush_bucket_straw *)in,
x, r);
default:
dprintk("unknown bucket %d alg %d\n", in->id, in->alg);
return in->items[0];
}
}
static int is_out(const struct crush_map *map, const __u32 *weight, int item, int x)
{
if (weight[item] >= 0x10000)
return 0;
if (weight[item] == 0)
return 1;
if ((crush_hash32_2(CRUSH_HASH_RJENKINS1, x, item) & 0xffff)
< weight[item])
return 0;
return 1;
}
static int crush_choose(const struct crush_map *map,
struct crush_bucket *bucket,
const __u32 *weight,
int x, int numrep, int type,
int *out, int outpos,
int firstn, int recurse_to_leaf,
int *out2)
{
int rep;
unsigned int ftotal, flocal;
int retry_descent, retry_bucket, skip_rep;
struct crush_bucket *in = bucket;
int r;
int i;
int item = 0;
int itemtype;
int collide, reject;
dprintk("CHOOSE%s bucket %d x %d outpos %d numrep %d\n", recurse_to_leaf ? "_LEAF" : "",
bucket->id, x, outpos, numrep);
for (rep = outpos; rep < numrep; rep++) {
ftotal = 0;
skip_rep = 0;
do {
retry_descent = 0;
in = bucket;
flocal = 0;
do {
collide = 0;
retry_bucket = 0;
r = rep;
if (in->alg == CRUSH_BUCKET_UNIFORM) {
if (firstn || (__u32)numrep >= in->size)
r += ftotal;
else if (in->size % numrep == 0)
r += (numrep+1) *
(flocal+ftotal);
else
r += numrep * (flocal+ftotal);
} else {
if (firstn)
r += ftotal;
else
r += numrep * (flocal+ftotal);
}
if (in->size == 0) {
reject = 1;
goto reject;
}
if (map->choose_local_fallback_tries > 0 &&
flocal >= (in->size>>1) &&
flocal > map->choose_local_fallback_tries)
item = bucket_perm_choose(in, x, r);
else
item = crush_bucket_choose(in, x, r);
if (item >= map->max_devices) {
dprintk(" bad item %d\n", item);
skip_rep = 1;
break;
}
if (item < 0)
itemtype = map->buckets[-1-item]->type;
else
itemtype = 0;
dprintk(" item %d type %d\n", item, itemtype);
if (itemtype != type) {
if (item >= 0 ||
(-1-item) >= map->max_buckets) {
dprintk(" bad item type %d\n", type);
skip_rep = 1;
break;
}
in = map->buckets[-1-item];
retry_bucket = 1;
continue;
}
for (i = 0; i < outpos; i++) {
if (out[i] == item) {
collide = 1;
break;
}
}
reject = 0;
if (recurse_to_leaf) {
if (item < 0) {
if (crush_choose(map,
map->buckets[-1-item],
weight,
x, outpos+1, 0,
out2, outpos,
firstn, 0,
NULL) <= outpos)
reject = 1;
} else {
out2[outpos] = item;
}
}
if (!reject) {
if (itemtype == 0)
reject = is_out(map, weight,
item, x);
else
reject = 0;
}
reject:
if (reject || collide) {
ftotal++;
flocal++;
if (collide && flocal <= map->choose_local_tries)
retry_bucket = 1;
else if (map->choose_local_fallback_tries > 0 &&
flocal <= in->size + map->choose_local_fallback_tries)
retry_bucket = 1;
else if (ftotal <= map->choose_total_tries)
retry_descent = 1;
else
skip_rep = 1;
dprintk(" reject %d collide %d "
"ftotal %u flocal %u\n",
reject, collide, ftotal,
flocal);
}
} while (retry_bucket);
} while (retry_descent);
if (skip_rep) {
dprintk("skip rep\n");
continue;
}
dprintk("CHOOSE got %d\n", item);
out[outpos] = item;
outpos++;
}
dprintk("CHOOSE returns %d\n", outpos);
return outpos;
}
int crush_do_rule(const struct crush_map *map,
int ruleno, int x, int *result, int result_max,
const __u32 *weight)
{
int result_len;
int a[CRUSH_MAX_SET];
int b[CRUSH_MAX_SET];
int c[CRUSH_MAX_SET];
int recurse_to_leaf;
int *w;
int wsize = 0;
int *o;
int osize;
int *tmp;
struct crush_rule *rule;
__u32 step;
int i, j;
int numrep;
int firstn;
if ((__u32)ruleno >= map->max_rules) {
dprintk(" bad ruleno %d\n", ruleno);
return 0;
}
rule = map->rules[ruleno];
result_len = 0;
w = a;
o = b;
for (step = 0; step < rule->len; step++) {
struct crush_rule_step *curstep = &rule->steps[step];
firstn = 0;
switch (curstep->op) {
case CRUSH_RULE_TAKE:
w[0] = curstep->arg1;
wsize = 1;
break;
case CRUSH_RULE_CHOOSE_LEAF_FIRSTN:
case CRUSH_RULE_CHOOSE_FIRSTN:
firstn = 1;
case CRUSH_RULE_CHOOSE_LEAF_INDEP:
case CRUSH_RULE_CHOOSE_INDEP:
if (wsize == 0)
break;
recurse_to_leaf =
curstep->op ==
CRUSH_RULE_CHOOSE_LEAF_FIRSTN ||
curstep->op ==
CRUSH_RULE_CHOOSE_LEAF_INDEP;
osize = 0;
for (i = 0; i < wsize; i++) {
numrep = curstep->arg1;
if (numrep <= 0) {
numrep += result_max;
if (numrep <= 0)
continue;
}
j = 0;
osize += crush_choose(map,
map->buckets[-1-w[i]],
weight,
x, numrep,
curstep->arg2,
o+osize, j,
firstn,
recurse_to_leaf, c+osize);
}
if (recurse_to_leaf)
memcpy(o, c, osize*sizeof(*o));
tmp = o;
o = w;
w = tmp;
wsize = osize;
break;
case CRUSH_RULE_EMIT:
for (i = 0; i < wsize && result_len < result_max; i++) {
result[result_len] = w[i];
result_len++;
}
wsize = 0;
break;
default:
dprintk(" unknown op %d at step %d\n",
curstep->op, step);
break;
}
}
return result_len;
}
