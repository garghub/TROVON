u16 hists__col_len(struct hists *hists, enum hist_column col)
{
return hists->col_len[col];
}
void hists__set_col_len(struct hists *hists, enum hist_column col, u16 len)
{
hists->col_len[col] = len;
}
bool hists__new_col_len(struct hists *hists, enum hist_column col, u16 len)
{
if (len > hists__col_len(hists, col)) {
hists__set_col_len(hists, col, len);
return true;
}
return false;
}
void hists__reset_col_len(struct hists *hists)
{
enum hist_column col;
for (col = 0; col < HISTC_NR_COLS; ++col)
hists__set_col_len(hists, col, 0);
}
static void hists__set_unres_dso_col_len(struct hists *hists, int dso)
{
const unsigned int unresolved_col_width = BITS_PER_LONG / 4;
if (hists__col_len(hists, dso) < unresolved_col_width &&
!symbol_conf.col_width_list_str && !symbol_conf.field_sep &&
!symbol_conf.dso_list)
hists__set_col_len(hists, dso, unresolved_col_width);
}
void hists__calc_col_len(struct hists *hists, struct hist_entry *h)
{
const unsigned int unresolved_col_width = BITS_PER_LONG / 4;
u16 len;
if (h->ms.sym)
hists__new_col_len(hists, HISTC_SYMBOL, h->ms.sym->namelen + 4);
else
hists__set_unres_dso_col_len(hists, HISTC_DSO);
len = thread__comm_len(h->thread);
if (hists__new_col_len(hists, HISTC_COMM, len))
hists__set_col_len(hists, HISTC_THREAD, len + 6);
if (h->ms.map) {
len = dso__name_len(h->ms.map->dso);
hists__new_col_len(hists, HISTC_DSO, len);
}
if (h->parent)
hists__new_col_len(hists, HISTC_PARENT, h->parent->namelen);
if (h->branch_info) {
int symlen;
if (h->branch_info->from.sym) {
symlen = (int)h->branch_info->from.sym->namelen + 4;
hists__new_col_len(hists, HISTC_SYMBOL_FROM, symlen);
symlen = dso__name_len(h->branch_info->from.map->dso);
hists__new_col_len(hists, HISTC_DSO_FROM, symlen);
} else {
symlen = unresolved_col_width + 4 + 2;
hists__new_col_len(hists, HISTC_SYMBOL_FROM, symlen);
hists__set_unres_dso_col_len(hists, HISTC_DSO_FROM);
}
if (h->branch_info->to.sym) {
symlen = (int)h->branch_info->to.sym->namelen + 4;
hists__new_col_len(hists, HISTC_SYMBOL_TO, symlen);
symlen = dso__name_len(h->branch_info->to.map->dso);
hists__new_col_len(hists, HISTC_DSO_TO, symlen);
} else {
symlen = unresolved_col_width + 4 + 2;
hists__new_col_len(hists, HISTC_SYMBOL_TO, symlen);
hists__set_unres_dso_col_len(hists, HISTC_DSO_TO);
}
}
}
void hists__output_recalc_col_len(struct hists *hists, int max_rows)
{
struct rb_node *next = rb_first(&hists->entries);
struct hist_entry *n;
int row = 0;
hists__reset_col_len(hists);
while (next && row++ < max_rows) {
n = rb_entry(next, struct hist_entry, rb_node);
if (!n->filtered)
hists__calc_col_len(hists, n);
next = rb_next(&n->rb_node);
}
}
static void hist_entry__add_cpumode_period(struct hist_entry *he,
unsigned int cpumode, u64 period)
{
switch (cpumode) {
case PERF_RECORD_MISC_KERNEL:
he->stat.period_sys += period;
break;
case PERF_RECORD_MISC_USER:
he->stat.period_us += period;
break;
case PERF_RECORD_MISC_GUEST_KERNEL:
he->stat.period_guest_sys += period;
break;
case PERF_RECORD_MISC_GUEST_USER:
he->stat.period_guest_us += period;
break;
default:
break;
}
}
static void he_stat__add_period(struct he_stat *he_stat, u64 period)
{
he_stat->period += period;
he_stat->nr_events += 1;
}
static void he_stat__add_stat(struct he_stat *dest, struct he_stat *src)
{
dest->period += src->period;
dest->period_sys += src->period_sys;
dest->period_us += src->period_us;
dest->period_guest_sys += src->period_guest_sys;
dest->period_guest_us += src->period_guest_us;
dest->nr_events += src->nr_events;
}
static void hist_entry__decay(struct hist_entry *he)
{
he->stat.period = (he->stat.period * 7) / 8;
he->stat.nr_events = (he->stat.nr_events * 7) / 8;
}
static bool hists__decay_entry(struct hists *hists, struct hist_entry *he)
{
u64 prev_period = he->stat.period;
if (prev_period == 0)
return true;
hist_entry__decay(he);
if (!he->filtered)
hists->stats.total_period -= prev_period - he->stat.period;
return he->stat.period == 0;
}
static void __hists__decay_entries(struct hists *hists, bool zap_user,
bool zap_kernel, bool threaded)
{
struct rb_node *next = rb_first(&hists->entries);
struct hist_entry *n;
while (next) {
n = rb_entry(next, struct hist_entry, rb_node);
next = rb_next(&n->rb_node);
if (((zap_user && n->level == '.') ||
(zap_kernel && n->level != '.') ||
hists__decay_entry(hists, n)) &&
!n->used) {
rb_erase(&n->rb_node, &hists->entries);
if (sort__need_collapse || threaded)
rb_erase(&n->rb_node_in, &hists->entries_collapsed);
hist_entry__free(n);
--hists->nr_entries;
}
}
}
void hists__decay_entries(struct hists *hists, bool zap_user, bool zap_kernel)
{
return __hists__decay_entries(hists, zap_user, zap_kernel, false);
}
void hists__decay_entries_threaded(struct hists *hists,
bool zap_user, bool zap_kernel)
{
return __hists__decay_entries(hists, zap_user, zap_kernel, true);
}
static struct hist_entry *hist_entry__new(struct hist_entry *template)
{
size_t callchain_size = symbol_conf.use_callchain ? sizeof(struct callchain_root) : 0;
struct hist_entry *he = malloc(sizeof(*he) + callchain_size);
if (he != NULL) {
*he = *template;
if (he->ms.map)
he->ms.map->referenced = true;
if (he->branch_info) {
if (he->branch_info->from.map)
he->branch_info->from.map->referenced = true;
if (he->branch_info->to.map)
he->branch_info->to.map->referenced = true;
}
if (symbol_conf.use_callchain)
callchain_init(he->callchain);
INIT_LIST_HEAD(&he->pairs.node);
}
return he;
}
void hists__inc_nr_entries(struct hists *hists, struct hist_entry *h)
{
if (!h->filtered) {
hists__calc_col_len(hists, h);
++hists->nr_entries;
hists->stats.total_period += h->stat.period;
}
}
static u8 symbol__parent_filter(const struct symbol *parent)
{
if (symbol_conf.exclude_other && parent == NULL)
return 1 << HIST_FILTER__PARENT;
return 0;
}
static struct hist_entry *add_hist_entry(struct hists *hists,
struct hist_entry *entry,
struct addr_location *al,
u64 period)
{
struct rb_node **p;
struct rb_node *parent = NULL;
struct hist_entry *he;
int cmp;
pthread_mutex_lock(&hists->lock);
p = &hists->entries_in->rb_node;
while (*p != NULL) {
parent = *p;
he = rb_entry(parent, struct hist_entry, rb_node_in);
cmp = hist_entry__cmp(he, entry);
if (!cmp) {
he_stat__add_period(&he->stat, period);
if (he->ms.map != entry->ms.map) {
he->ms.map = entry->ms.map;
if (he->ms.map)
he->ms.map->referenced = true;
}
goto out;
}
if (cmp < 0)
p = &(*p)->rb_left;
else
p = &(*p)->rb_right;
}
he = hist_entry__new(entry);
if (!he)
goto out_unlock;
rb_link_node(&he->rb_node_in, parent, p);
rb_insert_color(&he->rb_node_in, hists->entries_in);
out:
hist_entry__add_cpumode_period(he, al->cpumode, period);
out_unlock:
pthread_mutex_unlock(&hists->lock);
return he;
}
struct hist_entry *__hists__add_branch_entry(struct hists *self,
struct addr_location *al,
struct symbol *sym_parent,
struct branch_info *bi,
u64 period)
{
struct hist_entry entry = {
.thread = al->thread,
.ms = {
.map = bi->to.map,
.sym = bi->to.sym,
},
.cpu = al->cpu,
.ip = bi->to.addr,
.level = al->level,
.stat = {
.period = period,
.nr_events = 1,
},
.parent = sym_parent,
.filtered = symbol__parent_filter(sym_parent),
.branch_info = bi,
.hists = self,
};
return add_hist_entry(self, &entry, al, period);
}
struct hist_entry *__hists__add_entry(struct hists *self,
struct addr_location *al,
struct symbol *sym_parent, u64 period)
{
struct hist_entry entry = {
.thread = al->thread,
.ms = {
.map = al->map,
.sym = al->sym,
},
.cpu = al->cpu,
.ip = al->addr,
.level = al->level,
.stat = {
.period = period,
.nr_events = 1,
},
.parent = sym_parent,
.filtered = symbol__parent_filter(sym_parent),
.hists = self,
};
return add_hist_entry(self, &entry, al, period);
}
int64_t
hist_entry__cmp(struct hist_entry *left, struct hist_entry *right)
{
struct sort_entry *se;
int64_t cmp = 0;
list_for_each_entry(se, &hist_entry__sort_list, list) {
cmp = se->se_cmp(left, right);
if (cmp)
break;
}
return cmp;
}
int64_t
hist_entry__collapse(struct hist_entry *left, struct hist_entry *right)
{
struct sort_entry *se;
int64_t cmp = 0;
list_for_each_entry(se, &hist_entry__sort_list, list) {
int64_t (*f)(struct hist_entry *, struct hist_entry *);
f = se->se_collapse ?: se->se_cmp;
cmp = f(left, right);
if (cmp)
break;
}
return cmp;
}
void hist_entry__free(struct hist_entry *he)
{
free(he->branch_info);
free(he);
}
static bool hists__collapse_insert_entry(struct hists *hists __maybe_unused,
struct rb_root *root,
struct hist_entry *he)
{
struct rb_node **p = &root->rb_node;
struct rb_node *parent = NULL;
struct hist_entry *iter;
int64_t cmp;
while (*p != NULL) {
parent = *p;
iter = rb_entry(parent, struct hist_entry, rb_node_in);
cmp = hist_entry__collapse(iter, he);
if (!cmp) {
he_stat__add_stat(&iter->stat, &he->stat);
if (symbol_conf.use_callchain) {
callchain_cursor_reset(&callchain_cursor);
callchain_merge(&callchain_cursor,
iter->callchain,
he->callchain);
}
hist_entry__free(he);
return false;
}
if (cmp < 0)
p = &(*p)->rb_left;
else
p = &(*p)->rb_right;
}
rb_link_node(&he->rb_node_in, parent, p);
rb_insert_color(&he->rb_node_in, root);
return true;
}
static struct rb_root *hists__get_rotate_entries_in(struct hists *hists)
{
struct rb_root *root;
pthread_mutex_lock(&hists->lock);
root = hists->entries_in;
if (++hists->entries_in > &hists->entries_in_array[1])
hists->entries_in = &hists->entries_in_array[0];
pthread_mutex_unlock(&hists->lock);
return root;
}
static void hists__apply_filters(struct hists *hists, struct hist_entry *he)
{
hists__filter_entry_by_dso(hists, he);
hists__filter_entry_by_thread(hists, he);
hists__filter_entry_by_symbol(hists, he);
}
static void __hists__collapse_resort(struct hists *hists, bool threaded)
{
struct rb_root *root;
struct rb_node *next;
struct hist_entry *n;
if (!sort__need_collapse && !threaded)
return;
root = hists__get_rotate_entries_in(hists);
next = rb_first(root);
while (next) {
n = rb_entry(next, struct hist_entry, rb_node_in);
next = rb_next(&n->rb_node_in);
rb_erase(&n->rb_node_in, root);
if (hists__collapse_insert_entry(hists, &hists->entries_collapsed, n)) {
hists__apply_filters(hists, n);
}
}
}
void hists__collapse_resort(struct hists *hists)
{
return __hists__collapse_resort(hists, false);
}
void hists__collapse_resort_threaded(struct hists *hists)
{
return __hists__collapse_resort(hists, true);
}
static int period_cmp(u64 period_a, u64 period_b)
{
if (period_a > period_b)
return 1;
if (period_a < period_b)
return -1;
return 0;
}
static int hist_entry__sort_on_period(struct hist_entry *a,
struct hist_entry *b)
{
int ret;
int i, nr_members;
struct perf_evsel *evsel;
struct hist_entry *pair;
u64 *periods_a, *periods_b;
ret = period_cmp(a->stat.period, b->stat.period);
if (ret || !symbol_conf.event_group)
return ret;
evsel = hists_to_evsel(a->hists);
nr_members = evsel->nr_members;
if (nr_members <= 1)
return ret;
periods_a = zalloc(sizeof(periods_a) * nr_members);
periods_b = zalloc(sizeof(periods_b) * nr_members);
if (!periods_a || !periods_b)
goto out;
list_for_each_entry(pair, &a->pairs.head, pairs.node) {
evsel = hists_to_evsel(pair->hists);
periods_a[perf_evsel__group_idx(evsel)] = pair->stat.period;
}
list_for_each_entry(pair, &b->pairs.head, pairs.node) {
evsel = hists_to_evsel(pair->hists);
periods_b[perf_evsel__group_idx(evsel)] = pair->stat.period;
}
for (i = 1; i < nr_members; i++) {
ret = period_cmp(periods_a[i], periods_b[i]);
if (ret)
break;
}
out:
free(periods_a);
free(periods_b);
return ret;
}
static void __hists__insert_output_entry(struct rb_root *entries,
struct hist_entry *he,
u64 min_callchain_hits)
{
struct rb_node **p = &entries->rb_node;
struct rb_node *parent = NULL;
struct hist_entry *iter;
if (symbol_conf.use_callchain)
callchain_param.sort(&he->sorted_chain, he->callchain,
min_callchain_hits, &callchain_param);
while (*p != NULL) {
parent = *p;
iter = rb_entry(parent, struct hist_entry, rb_node);
if (hist_entry__sort_on_period(he, iter) > 0)
p = &(*p)->rb_left;
else
p = &(*p)->rb_right;
}
rb_link_node(&he->rb_node, parent, p);
rb_insert_color(&he->rb_node, entries);
}
static void __hists__output_resort(struct hists *hists, bool threaded)
{
struct rb_root *root;
struct rb_node *next;
struct hist_entry *n;
u64 min_callchain_hits;
min_callchain_hits = hists->stats.total_period * (callchain_param.min_percent / 100);
if (sort__need_collapse || threaded)
root = &hists->entries_collapsed;
else
root = hists->entries_in;
next = rb_first(root);
hists->entries = RB_ROOT;
hists->nr_entries = 0;
hists->stats.total_period = 0;
hists__reset_col_len(hists);
while (next) {
n = rb_entry(next, struct hist_entry, rb_node_in);
next = rb_next(&n->rb_node_in);
__hists__insert_output_entry(&hists->entries, n, min_callchain_hits);
hists__inc_nr_entries(hists, n);
}
}
void hists__output_resort(struct hists *hists)
{
return __hists__output_resort(hists, false);
}
void hists__output_resort_threaded(struct hists *hists)
{
return __hists__output_resort(hists, true);
}
static void hists__remove_entry_filter(struct hists *hists, struct hist_entry *h,
enum hist_filter filter)
{
h->filtered &= ~(1 << filter);
if (h->filtered)
return;
++hists->nr_entries;
if (h->ms.unfolded)
hists->nr_entries += h->nr_rows;
h->row_offset = 0;
hists->stats.total_period += h->stat.period;
hists->stats.nr_events[PERF_RECORD_SAMPLE] += h->stat.nr_events;
hists__calc_col_len(hists, h);
}
static bool hists__filter_entry_by_dso(struct hists *hists,
struct hist_entry *he)
{
if (hists->dso_filter != NULL &&
(he->ms.map == NULL || he->ms.map->dso != hists->dso_filter)) {
he->filtered |= (1 << HIST_FILTER__DSO);
return true;
}
return false;
}
void hists__filter_by_dso(struct hists *hists)
{
struct rb_node *nd;
hists->nr_entries = hists->stats.total_period = 0;
hists->stats.nr_events[PERF_RECORD_SAMPLE] = 0;
hists__reset_col_len(hists);
for (nd = rb_first(&hists->entries); nd; nd = rb_next(nd)) {
struct hist_entry *h = rb_entry(nd, struct hist_entry, rb_node);
if (symbol_conf.exclude_other && !h->parent)
continue;
if (hists__filter_entry_by_dso(hists, h))
continue;
hists__remove_entry_filter(hists, h, HIST_FILTER__DSO);
}
}
static bool hists__filter_entry_by_thread(struct hists *hists,
struct hist_entry *he)
{
if (hists->thread_filter != NULL &&
he->thread != hists->thread_filter) {
he->filtered |= (1 << HIST_FILTER__THREAD);
return true;
}
return false;
}
void hists__filter_by_thread(struct hists *hists)
{
struct rb_node *nd;
hists->nr_entries = hists->stats.total_period = 0;
hists->stats.nr_events[PERF_RECORD_SAMPLE] = 0;
hists__reset_col_len(hists);
for (nd = rb_first(&hists->entries); nd; nd = rb_next(nd)) {
struct hist_entry *h = rb_entry(nd, struct hist_entry, rb_node);
if (hists__filter_entry_by_thread(hists, h))
continue;
hists__remove_entry_filter(hists, h, HIST_FILTER__THREAD);
}
}
static bool hists__filter_entry_by_symbol(struct hists *hists,
struct hist_entry *he)
{
if (hists->symbol_filter_str != NULL &&
(!he->ms.sym || strstr(he->ms.sym->name,
hists->symbol_filter_str) == NULL)) {
he->filtered |= (1 << HIST_FILTER__SYMBOL);
return true;
}
return false;
}
void hists__filter_by_symbol(struct hists *hists)
{
struct rb_node *nd;
hists->nr_entries = hists->stats.total_period = 0;
hists->stats.nr_events[PERF_RECORD_SAMPLE] = 0;
hists__reset_col_len(hists);
for (nd = rb_first(&hists->entries); nd; nd = rb_next(nd)) {
struct hist_entry *h = rb_entry(nd, struct hist_entry, rb_node);
if (hists__filter_entry_by_symbol(hists, h))
continue;
hists__remove_entry_filter(hists, h, HIST_FILTER__SYMBOL);
}
}
int hist_entry__inc_addr_samples(struct hist_entry *he, int evidx, u64 ip)
{
return symbol__inc_addr_samples(he->ms.sym, he->ms.map, evidx, ip);
}
int hist_entry__annotate(struct hist_entry *he, size_t privsize)
{
return symbol__annotate(he->ms.sym, he->ms.map, privsize);
}
void events_stats__inc(struct events_stats *stats, u32 type)
{
++stats->nr_events[0];
++stats->nr_events[type];
}
void hists__inc_nr_events(struct hists *hists, u32 type)
{
events_stats__inc(&hists->stats, type);
}
static struct hist_entry *hists__add_dummy_entry(struct hists *hists,
struct hist_entry *pair)
{
struct rb_root *root;
struct rb_node **p;
struct rb_node *parent = NULL;
struct hist_entry *he;
int cmp;
if (sort__need_collapse)
root = &hists->entries_collapsed;
else
root = hists->entries_in;
p = &root->rb_node;
while (*p != NULL) {
parent = *p;
he = rb_entry(parent, struct hist_entry, rb_node_in);
cmp = hist_entry__collapse(he, pair);
if (!cmp)
goto out;
if (cmp < 0)
p = &(*p)->rb_left;
else
p = &(*p)->rb_right;
}
he = hist_entry__new(pair);
if (he) {
memset(&he->stat, 0, sizeof(he->stat));
he->hists = hists;
rb_link_node(&he->rb_node_in, parent, p);
rb_insert_color(&he->rb_node_in, root);
hists__inc_nr_entries(hists, he);
}
out:
return he;
}
static struct hist_entry *hists__find_entry(struct hists *hists,
struct hist_entry *he)
{
struct rb_node *n;
if (sort__need_collapse)
n = hists->entries_collapsed.rb_node;
else
n = hists->entries_in->rb_node;
while (n) {
struct hist_entry *iter = rb_entry(n, struct hist_entry, rb_node_in);
int64_t cmp = hist_entry__collapse(iter, he);
if (cmp < 0)
n = n->rb_left;
else if (cmp > 0)
n = n->rb_right;
else
return iter;
}
return NULL;
}
void hists__match(struct hists *leader, struct hists *other)
{
struct rb_root *root;
struct rb_node *nd;
struct hist_entry *pos, *pair;
if (sort__need_collapse)
root = &leader->entries_collapsed;
else
root = leader->entries_in;
for (nd = rb_first(root); nd; nd = rb_next(nd)) {
pos = rb_entry(nd, struct hist_entry, rb_node_in);
pair = hists__find_entry(other, pos);
if (pair)
hist_entry__add_pair(pair, pos);
}
}
int hists__link(struct hists *leader, struct hists *other)
{
struct rb_root *root;
struct rb_node *nd;
struct hist_entry *pos, *pair;
if (sort__need_collapse)
root = &other->entries_collapsed;
else
root = other->entries_in;
for (nd = rb_first(root); nd; nd = rb_next(nd)) {
pos = rb_entry(nd, struct hist_entry, rb_node_in);
if (!hist_entry__has_pairs(pos)) {
pair = hists__add_dummy_entry(leader, pos);
if (pair == NULL)
return -1;
hist_entry__add_pair(pos, pair);
}
}
return 0;
}
