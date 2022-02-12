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
int n;
__u32 w;
__u64 t;
n = bucket->num_nodes >> 1;
while (!terminal(n)) {
int l;
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
static int is_out(const struct crush_map *map,
const __u32 *weight, int weight_max,
int item, int x)
{
if (item >= weight_max)
return 1;
if (weight[item] >= 0x10000)
return 0;
if (weight[item] == 0)
return 1;
if ((crush_hash32_2(CRUSH_HASH_RJENKINS1, x, item) & 0xffff)
< weight[item])
return 0;
return 1;
}
static int crush_choose_firstn(const struct crush_map *map,
struct crush_bucket *bucket,
const __u32 *weight, int weight_max,
int x, int numrep, int type,
int *out, int outpos,
unsigned int tries,
unsigned int recurse_tries,
unsigned int local_tries,
unsigned int local_fallback_tries,
int recurse_to_leaf,
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
r += ftotal;
if (in->size == 0) {
reject = 1;
goto reject;
}
if (local_fallback_tries > 0 &&
flocal >= (in->size>>1) &&
flocal > local_fallback_tries)
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
if (!collide && recurse_to_leaf) {
if (item < 0) {
if (crush_choose_firstn(map,
map->buckets[-1-item],
weight, weight_max,
x, outpos+1, 0,
out2, outpos,
recurse_tries, 0,
local_tries,
local_fallback_tries,
0,
NULL) <= outpos)
reject = 1;
} else {
out2[outpos] = item;
}
}
if (!reject) {
if (itemtype == 0)
reject = is_out(map, weight,
weight_max,
item, x);
else
reject = 0;
}
reject:
if (reject || collide) {
ftotal++;
flocal++;
if (collide && flocal <= local_tries)
retry_bucket = 1;
else if (local_fallback_tries > 0 &&
flocal <= in->size + local_fallback_tries)
retry_bucket = 1;
else if (ftotal <= tries)
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
static void crush_choose_indep(const struct crush_map *map,
struct crush_bucket *bucket,
const __u32 *weight, int weight_max,
int x, int left, int numrep, int type,
int *out, int outpos,
unsigned int tries,
unsigned int recurse_tries,
int recurse_to_leaf,
int *out2,
int parent_r)
{
struct crush_bucket *in = bucket;
int endpos = outpos + left;
int rep;
unsigned int ftotal;
int r;
int i;
int item = 0;
int itemtype;
int collide;
dprintk("CHOOSE%s INDEP bucket %d x %d outpos %d numrep %d\n", recurse_to_leaf ? "_LEAF" : "",
bucket->id, x, outpos, numrep);
for (rep = outpos; rep < endpos; rep++) {
out[rep] = CRUSH_ITEM_UNDEF;
if (out2)
out2[rep] = CRUSH_ITEM_UNDEF;
}
for (ftotal = 0; left > 0 && ftotal < tries; ftotal++) {
for (rep = outpos; rep < endpos; rep++) {
if (out[rep] != CRUSH_ITEM_UNDEF)
continue;
in = bucket;
for (;;) {
r = rep + parent_r;
if (in->alg == CRUSH_BUCKET_UNIFORM &&
in->size % numrep == 0)
r += (numrep+1) * ftotal;
else
r += numrep * ftotal;
if (in->size == 0) {
dprintk(" empty bucket\n");
break;
}
item = crush_bucket_choose(in, x, r);
if (item >= map->max_devices) {
dprintk(" bad item %d\n", item);
out[rep] = CRUSH_ITEM_NONE;
if (out2)
out2[rep] = CRUSH_ITEM_NONE;
left--;
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
out[rep] = CRUSH_ITEM_NONE;
if (out2)
out2[rep] =
CRUSH_ITEM_NONE;
left--;
break;
}
in = map->buckets[-1-item];
continue;
}
collide = 0;
for (i = outpos; i < endpos; i++) {
if (out[i] == item) {
collide = 1;
break;
}
}
if (collide)
break;
if (recurse_to_leaf) {
if (item < 0) {
crush_choose_indep(map,
map->buckets[-1-item],
weight, weight_max,
x, 1, numrep, 0,
out2, rep,
recurse_tries, 0,
0, NULL, r);
if (out2[rep] == CRUSH_ITEM_NONE) {
break;
}
} else {
out2[rep] = item;
}
}
if (itemtype == 0 &&
is_out(map, weight, weight_max, item, x))
break;
out[rep] = item;
left--;
break;
}
}
}
for (rep = outpos; rep < endpos; rep++) {
if (out[rep] == CRUSH_ITEM_UNDEF) {
out[rep] = CRUSH_ITEM_NONE;
}
if (out2 && out2[rep] == CRUSH_ITEM_UNDEF) {
out2[rep] = CRUSH_ITEM_NONE;
}
}
}
int crush_do_rule(const struct crush_map *map,
int ruleno, int x, int *result, int result_max,
const __u32 *weight, int weight_max,
int *scratch)
{
int result_len;
int *a = scratch;
int *b = scratch + result_max;
int *c = scratch + result_max*2;
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
int choose_tries = map->choose_total_tries;
int choose_local_tries = map->choose_local_tries;
int choose_local_fallback_tries = map->choose_local_fallback_tries;
int choose_leaf_tries = 0;
if ((__u32)ruleno >= map->max_rules) {
dprintk(" bad ruleno %d\n", ruleno);
return 0;
}
rule = map->rules[ruleno];
result_len = 0;
w = a;
o = b;
for (step = 0; step < rule->len; step++) {
int firstn = 0;
struct crush_rule_step *curstep = &rule->steps[step];
switch (curstep->op) {
case CRUSH_RULE_TAKE:
w[0] = curstep->arg1;
wsize = 1;
break;
case CRUSH_RULE_SET_CHOOSE_TRIES:
if (curstep->arg1 > 0)
choose_tries = curstep->arg1;
break;
case CRUSH_RULE_SET_CHOOSELEAF_TRIES:
if (curstep->arg1 > 0)
choose_leaf_tries = curstep->arg1;
break;
case CRUSH_RULE_SET_CHOOSE_LOCAL_TRIES:
if (curstep->arg1 > 0)
choose_local_tries = curstep->arg1;
break;
case CRUSH_RULE_SET_CHOOSE_LOCAL_FALLBACK_TRIES:
if (curstep->arg1 > 0)
choose_local_fallback_tries = curstep->arg1;
break;
case CRUSH_RULE_CHOOSELEAF_FIRSTN:
case CRUSH_RULE_CHOOSE_FIRSTN:
firstn = 1;
case CRUSH_RULE_CHOOSELEAF_INDEP:
case CRUSH_RULE_CHOOSE_INDEP:
if (wsize == 0)
break;
recurse_to_leaf =
curstep->op ==
CRUSH_RULE_CHOOSELEAF_FIRSTN ||
curstep->op ==
CRUSH_RULE_CHOOSELEAF_INDEP;
osize = 0;
for (i = 0; i < wsize; i++) {
numrep = curstep->arg1;
if (numrep <= 0) {
numrep += result_max;
if (numrep <= 0)
continue;
}
j = 0;
if (firstn) {
int recurse_tries;
if (choose_leaf_tries)
recurse_tries =
choose_leaf_tries;
else if (map->chooseleaf_descend_once)
recurse_tries = 1;
else
recurse_tries = choose_tries;
osize += crush_choose_firstn(
map,
map->buckets[-1-w[i]],
weight, weight_max,
x, numrep,
curstep->arg2,
o+osize, j,
choose_tries,
recurse_tries,
choose_local_tries,
choose_local_fallback_tries,
recurse_to_leaf,
c+osize);
} else {
crush_choose_indep(
map,
map->buckets[-1-w[i]],
weight, weight_max,
x, numrep, numrep,
curstep->arg2,
o+osize, j,
choose_tries,
choose_leaf_tries ?
choose_leaf_tries : 1,
recurse_to_leaf,
c+osize,
0);
osize += numrep;
}
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
