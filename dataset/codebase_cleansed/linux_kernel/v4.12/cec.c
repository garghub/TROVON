static void do_spring_cleaning(struct ce_array *ca)
{
int i;
for (i = 0; i < ca->n; i++) {
u8 decay = DECAY(ca->array[i]);
if (!decay)
continue;
decay--;
ca->array[i] &= ~(DECAY_MASK << COUNT_BITS);
ca->array[i] |= (decay << COUNT_BITS);
}
ca->decay_count = 0;
ca->decays_done++;
}
static void cec_mod_timer(struct timer_list *t, unsigned long interval)
{
unsigned long iv;
iv = interval * HZ + jiffies;
mod_timer(t, round_jiffies(iv));
}
static void cec_timer_fn(unsigned long data)
{
struct ce_array *ca = (struct ce_array *)data;
do_spring_cleaning(ca);
cec_mod_timer(&cec_timer, timer_interval);
}
static int __find_elem(struct ce_array *ca, u64 pfn, unsigned int *to)
{
u64 this_pfn;
int min = 0, max = ca->n;
while (min < max) {
int tmp = (max + min) >> 1;
this_pfn = PFN(ca->array[tmp]);
if (this_pfn < pfn)
min = tmp + 1;
else if (this_pfn > pfn)
max = tmp;
else {
min = tmp;
break;
}
}
if (to)
*to = min;
this_pfn = PFN(ca->array[min]);
if (this_pfn == pfn)
return min;
return -ENOKEY;
}
static int find_elem(struct ce_array *ca, u64 pfn, unsigned int *to)
{
WARN_ON(!to);
if (!ca->n) {
*to = 0;
return -ENOKEY;
}
return __find_elem(ca, pfn, to);
}
static void del_elem(struct ce_array *ca, int idx)
{
if (ca->n - (idx + 1))
memmove((void *)&ca->array[idx],
(void *)&ca->array[idx + 1],
(ca->n - (idx + 1)) * sizeof(u64));
ca->n--;
}
static u64 del_lru_elem_unlocked(struct ce_array *ca)
{
unsigned int min = FULL_COUNT_MASK;
int i, min_idx = 0;
for (i = 0; i < ca->n; i++) {
unsigned int this = FULL_COUNT(ca->array[i]);
if (min > this) {
min = this;
min_idx = i;
}
}
del_elem(ca, min_idx);
return PFN(ca->array[min_idx]);
}
static u64 __maybe_unused del_lru_elem(void)
{
struct ce_array *ca = &ce_arr;
u64 pfn;
if (!ca->n)
return 0;
mutex_lock(&ce_mutex);
pfn = del_lru_elem_unlocked(ca);
mutex_unlock(&ce_mutex);
return pfn;
}
int cec_add_elem(u64 pfn)
{
struct ce_array *ca = &ce_arr;
unsigned int to;
int count, ret = 0;
if (!ce_arr.array || ce_arr.disabled)
return -ENODEV;
ca->ces_entered++;
mutex_lock(&ce_mutex);
if (ca->n == MAX_ELEMS)
WARN_ON(!del_lru_elem_unlocked(ca));
ret = find_elem(ca, pfn, &to);
if (ret < 0) {
memmove((void *)&ca->array[to + 1],
(void *)&ca->array[to],
(ca->n - to) * sizeof(u64));
ca->array[to] = (pfn << PAGE_SHIFT) |
(DECAY_MASK << COUNT_BITS) | 1;
ca->n++;
ret = 0;
goto decay;
}
count = COUNT(ca->array[to]);
if (count < count_threshold) {
ca->array[to] |= (DECAY_MASK << COUNT_BITS);
ca->array[to]++;
ret = 0;
} else {
u64 pfn = ca->array[to] >> PAGE_SHIFT;
if (!pfn_valid(pfn)) {
pr_warn("CEC: Invalid pfn: 0x%llx\n", pfn);
} else {
pr_err("Soft-offlining pfn: 0x%llx\n", pfn);
memory_failure_queue(pfn, 0, MF_SOFT_OFFLINE);
ca->pfns_poisoned++;
}
del_elem(ca, to);
ret = 1;
goto unlock;
}
decay:
ca->decay_count++;
if (ca->decay_count >= CLEAN_ELEMS)
do_spring_cleaning(ca);
unlock:
mutex_unlock(&ce_mutex);
return ret;
}
static int u64_get(void *data, u64 *val)
{
*val = *(u64 *)data;
return 0;
}
static int pfn_set(void *data, u64 val)
{
*(u64 *)data = val;
return cec_add_elem(val);
}
static int decay_interval_set(void *data, u64 val)
{
*(u64 *)data = val;
if (val < CEC_TIMER_MIN_INTERVAL)
return -EINVAL;
if (val > CEC_TIMER_MAX_INTERVAL)
return -EINVAL;
timer_interval = val;
cec_mod_timer(&cec_timer, timer_interval);
return 0;
}
static int count_threshold_set(void *data, u64 val)
{
*(u64 *)data = val;
if (val > COUNT_MASK)
val = COUNT_MASK;
count_threshold = val;
return 0;
}
static int array_dump(struct seq_file *m, void *v)
{
struct ce_array *ca = &ce_arr;
u64 prev = 0;
int i;
mutex_lock(&ce_mutex);
seq_printf(m, "{ n: %d\n", ca->n);
for (i = 0; i < ca->n; i++) {
u64 this = PFN(ca->array[i]);
seq_printf(m, " %03d: [%016llx|%03llx]\n", i, this, FULL_COUNT(ca->array[i]));
WARN_ON(prev > this);
prev = this;
}
seq_printf(m, "}\n");
seq_printf(m, "Stats:\nCEs: %llu\nofflined pages: %llu\n",
ca->ces_entered, ca->pfns_poisoned);
seq_printf(m, "Flags: 0x%x\n", ca->flags);
seq_printf(m, "Timer interval: %lld seconds\n", timer_interval);
seq_printf(m, "Decays: %lld\n", ca->decays_done);
seq_printf(m, "Action threshold: %d\n", count_threshold);
mutex_unlock(&ce_mutex);
return 0;
}
static int array_open(struct inode *inode, struct file *filp)
{
return single_open(filp, array_dump, NULL);
}
static int __init create_debugfs_nodes(void)
{
struct dentry *d, *pfn, *decay, *count, *array;
d = debugfs_create_dir("cec", ras_debugfs_dir);
if (!d) {
pr_warn("Error creating cec debugfs node!\n");
return -1;
}
pfn = debugfs_create_file("pfn", S_IRUSR | S_IWUSR, d, &dfs_pfn, &pfn_ops);
if (!pfn) {
pr_warn("Error creating pfn debugfs node!\n");
goto err;
}
array = debugfs_create_file("array", S_IRUSR, d, NULL, &array_ops);
if (!array) {
pr_warn("Error creating array debugfs node!\n");
goto err;
}
decay = debugfs_create_file("decay_interval", S_IRUSR | S_IWUSR, d,
&timer_interval, &decay_interval_ops);
if (!decay) {
pr_warn("Error creating decay_interval debugfs node!\n");
goto err;
}
count = debugfs_create_file("count_threshold", S_IRUSR | S_IWUSR, d,
&count_threshold, &count_threshold_ops);
if (!decay) {
pr_warn("Error creating count_threshold debugfs node!\n");
goto err;
}
return 0;
err:
debugfs_remove_recursive(d);
return 1;
}
void __init cec_init(void)
{
if (ce_arr.disabled)
return;
ce_arr.array = (void *)get_zeroed_page(GFP_KERNEL);
if (!ce_arr.array) {
pr_err("Error allocating CE array page!\n");
return;
}
if (create_debugfs_nodes())
return;
setup_timer(&cec_timer, cec_timer_fn, (unsigned long)&ce_arr);
cec_mod_timer(&cec_timer, CEC_TIMER_DEFAULT_INTERVAL);
pr_info("Correctable Errors collector initialized.\n");
}
int __init parse_cec_param(char *str)
{
if (!str)
return 0;
if (*str == '=')
str++;
if (!strncmp(str, "cec_disable", 7))
ce_arr.disabled = 1;
else
return 0;
return 1;
}
