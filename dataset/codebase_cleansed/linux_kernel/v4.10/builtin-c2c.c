static void *c2c_he_zalloc(size_t size)
{
struct c2c_hist_entry *c2c_he;
c2c_he = zalloc(size + sizeof(*c2c_he));
if (!c2c_he)
return NULL;
c2c_he->cpuset = bitmap_alloc(c2c.cpus_cnt);
if (!c2c_he->cpuset)
return NULL;
c2c_he->node_stats = zalloc(c2c.nodes_cnt * sizeof(*c2c_he->node_stats));
if (!c2c_he->node_stats)
return NULL;
init_stats(&c2c_he->cstats.lcl_hitm);
init_stats(&c2c_he->cstats.rmt_hitm);
init_stats(&c2c_he->cstats.load);
return &c2c_he->he;
}
static void c2c_he_free(void *he)
{
struct c2c_hist_entry *c2c_he;
c2c_he = container_of(he, struct c2c_hist_entry, he);
if (c2c_he->hists) {
hists__delete_entries(&c2c_he->hists->hists);
free(c2c_he->hists);
}
free(c2c_he->cpuset);
free(c2c_he->node_stats);
free(c2c_he);
}
static struct c2c_hists*
he__get_c2c_hists(struct hist_entry *he,
const char *sort,
int nr_header_lines)
{
struct c2c_hist_entry *c2c_he;
struct c2c_hists *hists;
int ret;
c2c_he = container_of(he, struct c2c_hist_entry, he);
if (c2c_he->hists)
return c2c_he->hists;
hists = c2c_he->hists = zalloc(sizeof(*hists));
if (!hists)
return NULL;
ret = c2c_hists__init(hists, sort, nr_header_lines);
if (ret) {
free(hists);
return NULL;
}
return hists;
}
static void c2c_he__set_cpu(struct c2c_hist_entry *c2c_he,
struct perf_sample *sample)
{
if (WARN_ONCE(sample->cpu == (unsigned int) -1,
"WARNING: no sample cpu value"))
return;
set_bit(sample->cpu, c2c_he->cpuset);
}
static void compute_stats(struct c2c_hist_entry *c2c_he,
struct c2c_stats *stats,
u64 weight)
{
struct compute_stats *cstats = &c2c_he->cstats;
if (stats->rmt_hitm)
update_stats(&cstats->rmt_hitm, weight);
else if (stats->lcl_hitm)
update_stats(&cstats->lcl_hitm, weight);
else if (stats->load)
update_stats(&cstats->load, weight);
}
static int process_sample_event(struct perf_tool *tool __maybe_unused,
union perf_event *event,
struct perf_sample *sample,
struct perf_evsel *evsel,
struct machine *machine)
{
struct c2c_hists *c2c_hists = &c2c.hists;
struct c2c_hist_entry *c2c_he;
struct c2c_stats stats = { .nr_entries = 0, };
struct hist_entry *he;
struct addr_location al;
struct mem_info *mi, *mi_dup;
int ret;
if (machine__resolve(machine, &al, sample) < 0) {
pr_debug("problem processing %d event, skipping it.\n",
event->header.type);
return -1;
}
ret = sample__resolve_callchain(sample, &callchain_cursor, NULL,
evsel, &al, sysctl_perf_event_max_stack);
if (ret)
goto out;
mi = sample__resolve_mem(sample, &al);
if (mi == NULL)
return -ENOMEM;
mi_dup = memdup(mi, sizeof(*mi));
if (!mi_dup)
goto free_mi;
c2c_decode_stats(&stats, mi);
he = hists__add_entry_ops(&c2c_hists->hists, &c2c_entry_ops,
&al, NULL, NULL, mi,
sample, true);
if (he == NULL)
goto free_mi_dup;
c2c_he = container_of(he, struct c2c_hist_entry, he);
c2c_add_stats(&c2c_he->stats, &stats);
c2c_add_stats(&c2c_hists->stats, &stats);
c2c_he__set_cpu(c2c_he, sample);
hists__inc_nr_samples(&c2c_hists->hists, he->filtered);
ret = hist_entry__append_callchain(he, sample);
if (!ret) {
int cpu = sample->cpu == (unsigned int) -1 ? 0 : sample->cpu;
int node = c2c.cpu2node[cpu];
mi = mi_dup;
mi_dup = memdup(mi, sizeof(*mi));
if (!mi_dup)
goto free_mi;
c2c_hists = he__get_c2c_hists(he, c2c.cl_sort, 2);
if (!c2c_hists)
goto free_mi_dup;
he = hists__add_entry_ops(&c2c_hists->hists, &c2c_entry_ops,
&al, NULL, NULL, mi,
sample, true);
if (he == NULL)
goto free_mi_dup;
c2c_he = container_of(he, struct c2c_hist_entry, he);
c2c_add_stats(&c2c_he->stats, &stats);
c2c_add_stats(&c2c_hists->stats, &stats);
c2c_add_stats(&c2c_he->node_stats[node], &stats);
compute_stats(c2c_he, &stats, sample->weight);
c2c_he__set_cpu(c2c_he, sample);
hists__inc_nr_samples(&c2c_hists->hists, he->filtered);
ret = hist_entry__append_callchain(he, sample);
}
out:
addr_location__put(&al);
return ret;
free_mi_dup:
free(mi_dup);
free_mi:
free(mi);
ret = -ENOMEM;
goto out;
}
static int symbol_width(struct hists *hists, struct sort_entry *se)
{
int width = hists__col_len(hists, se->se_width_idx);
if (!c2c.symbol_full)
width = MIN(width, SYMBOL_WIDTH);
return width;
}
static int c2c_width(struct perf_hpp_fmt *fmt,
struct perf_hpp *hpp __maybe_unused,
struct hists *hists)
{
struct c2c_fmt *c2c_fmt;
struct c2c_dimension *dim;
c2c_fmt = container_of(fmt, struct c2c_fmt, fmt);
dim = c2c_fmt->dim;
if (dim == &dim_symbol || dim == &dim_srcline)
return symbol_width(hists, dim->se);
return dim->se ? hists__col_len(hists, dim->se->se_width_idx) :
c2c_fmt->dim->width;
}
static int c2c_header(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hists *hists, int line, int *span)
{
struct perf_hpp_list *hpp_list = hists->hpp_list;
struct c2c_fmt *c2c_fmt;
struct c2c_dimension *dim;
const char *text = NULL;
int width = c2c_width(fmt, hpp, hists);
c2c_fmt = container_of(fmt, struct c2c_fmt, fmt);
dim = c2c_fmt->dim;
if (dim->se) {
text = dim->header.line[line].text;
if (!text && (line == hpp_list->nr_header_lines - 1))
text = dim->se->se_header;
} else {
text = dim->header.line[line].text;
if (*span) {
(*span)--;
return 0;
} else {
*span = dim->header.line[line].span;
}
}
if (text == NULL)
text = "";
return scnprintf(hpp->buf, hpp->size, "%*s", width, text);
}
static int64_t
dcacheline_cmp(struct perf_hpp_fmt *fmt __maybe_unused,
struct hist_entry *left, struct hist_entry *right)
{
return sort__dcacheline_cmp(left, right);
}
static int dcacheline_entry(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
uint64_t addr = 0;
int width = c2c_width(fmt, hpp, he->hists);
char buf[20];
if (he->mem_info)
addr = cl_address(he->mem_info->daddr.addr);
return scnprintf(hpp->buf, hpp->size, "%*s", width, HEX_STR(buf, addr));
}
static int offset_entry(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
uint64_t addr = 0;
int width = c2c_width(fmt, hpp, he->hists);
char buf[20];
if (he->mem_info)
addr = cl_offset(he->mem_info->daddr.al_addr);
return scnprintf(hpp->buf, hpp->size, "%*s", width, HEX_STR(buf, addr));
}
static int64_t
offset_cmp(struct perf_hpp_fmt *fmt __maybe_unused,
struct hist_entry *left, struct hist_entry *right)
{
uint64_t l = 0, r = 0;
if (left->mem_info)
l = cl_offset(left->mem_info->daddr.addr);
if (right->mem_info)
r = cl_offset(right->mem_info->daddr.addr);
return (int64_t)(r - l);
}
static int
iaddr_entry(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
uint64_t addr = 0;
int width = c2c_width(fmt, hpp, he->hists);
char buf[20];
if (he->mem_info)
addr = he->mem_info->iaddr.addr;
return scnprintf(hpp->buf, hpp->size, "%*s", width, HEX_STR(buf, addr));
}
static int64_t
iaddr_cmp(struct perf_hpp_fmt *fmt __maybe_unused,
struct hist_entry *left, struct hist_entry *right)
{
return sort__iaddr_cmp(left, right);
}
static int
tot_hitm_entry(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
struct c2c_hist_entry *c2c_he;
int width = c2c_width(fmt, hpp, he->hists);
unsigned int tot_hitm;
c2c_he = container_of(he, struct c2c_hist_entry, he);
tot_hitm = c2c_he->stats.lcl_hitm + c2c_he->stats.rmt_hitm;
return scnprintf(hpp->buf, hpp->size, "%*u", width, tot_hitm);
}
static int64_t
tot_hitm_cmp(struct perf_hpp_fmt *fmt __maybe_unused,
struct hist_entry *left, struct hist_entry *right)
{
struct c2c_hist_entry *c2c_left;
struct c2c_hist_entry *c2c_right;
unsigned int tot_hitm_left;
unsigned int tot_hitm_right;
c2c_left = container_of(left, struct c2c_hist_entry, he);
c2c_right = container_of(right, struct c2c_hist_entry, he);
tot_hitm_left = c2c_left->stats.lcl_hitm + c2c_left->stats.rmt_hitm;
tot_hitm_right = c2c_right->stats.lcl_hitm + c2c_right->stats.rmt_hitm;
return tot_hitm_left - tot_hitm_right;
}
static uint64_t llc_miss(struct c2c_stats *stats)
{
uint64_t llcmiss;
llcmiss = stats->lcl_dram +
stats->rmt_dram +
stats->rmt_hitm +
stats->rmt_hit;
return llcmiss;
}
static int
ld_llcmiss_entry(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
struct c2c_hist_entry *c2c_he;
int width = c2c_width(fmt, hpp, he->hists);
c2c_he = container_of(he, struct c2c_hist_entry, he);
return scnprintf(hpp->buf, hpp->size, "%*lu", width,
llc_miss(&c2c_he->stats));
}
static int64_t
ld_llcmiss_cmp(struct perf_hpp_fmt *fmt __maybe_unused,
struct hist_entry *left, struct hist_entry *right)
{
struct c2c_hist_entry *c2c_left;
struct c2c_hist_entry *c2c_right;
c2c_left = container_of(left, struct c2c_hist_entry, he);
c2c_right = container_of(right, struct c2c_hist_entry, he);
return llc_miss(&c2c_left->stats) - llc_miss(&c2c_right->stats);
}
static uint64_t total_records(struct c2c_stats *stats)
{
uint64_t lclmiss, ldcnt, total;
lclmiss = stats->lcl_dram +
stats->rmt_dram +
stats->rmt_hitm +
stats->rmt_hit;
ldcnt = lclmiss +
stats->ld_fbhit +
stats->ld_l1hit +
stats->ld_l2hit +
stats->ld_llchit +
stats->lcl_hitm;
total = ldcnt +
stats->st_l1hit +
stats->st_l1miss;
return total;
}
static int
tot_recs_entry(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
struct c2c_hist_entry *c2c_he;
int width = c2c_width(fmt, hpp, he->hists);
uint64_t tot_recs;
c2c_he = container_of(he, struct c2c_hist_entry, he);
tot_recs = total_records(&c2c_he->stats);
return scnprintf(hpp->buf, hpp->size, "%*" PRIu64, width, tot_recs);
}
static int64_t
tot_recs_cmp(struct perf_hpp_fmt *fmt __maybe_unused,
struct hist_entry *left, struct hist_entry *right)
{
struct c2c_hist_entry *c2c_left;
struct c2c_hist_entry *c2c_right;
uint64_t tot_recs_left;
uint64_t tot_recs_right;
c2c_left = container_of(left, struct c2c_hist_entry, he);
c2c_right = container_of(right, struct c2c_hist_entry, he);
tot_recs_left = total_records(&c2c_left->stats);
tot_recs_right = total_records(&c2c_right->stats);
return tot_recs_left - tot_recs_right;
}
static uint64_t total_loads(struct c2c_stats *stats)
{
uint64_t lclmiss, ldcnt;
lclmiss = stats->lcl_dram +
stats->rmt_dram +
stats->rmt_hitm +
stats->rmt_hit;
ldcnt = lclmiss +
stats->ld_fbhit +
stats->ld_l1hit +
stats->ld_l2hit +
stats->ld_llchit +
stats->lcl_hitm;
return ldcnt;
}
static int
tot_loads_entry(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
struct c2c_hist_entry *c2c_he;
int width = c2c_width(fmt, hpp, he->hists);
uint64_t tot_recs;
c2c_he = container_of(he, struct c2c_hist_entry, he);
tot_recs = total_loads(&c2c_he->stats);
return scnprintf(hpp->buf, hpp->size, "%*" PRIu64, width, tot_recs);
}
static int64_t
tot_loads_cmp(struct perf_hpp_fmt *fmt __maybe_unused,
struct hist_entry *left, struct hist_entry *right)
{
struct c2c_hist_entry *c2c_left;
struct c2c_hist_entry *c2c_right;
uint64_t tot_recs_left;
uint64_t tot_recs_right;
c2c_left = container_of(left, struct c2c_hist_entry, he);
c2c_right = container_of(right, struct c2c_hist_entry, he);
tot_recs_left = total_loads(&c2c_left->stats);
tot_recs_right = total_loads(&c2c_right->stats);
return tot_recs_left - tot_recs_right;
}
static int
percent_color(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he, get_percent_cb get_percent)
{
struct c2c_hist_entry *c2c_he;
int width = c2c_width(fmt, hpp, he->hists);
double per;
c2c_he = container_of(he, struct c2c_hist_entry, he);
per = get_percent(c2c_he);
#ifdef HAVE_SLANG_SUPPORT
if (use_browser)
return __hpp__slsmg_color_printf(hpp, "%*.2f%%", width - 1, per);
#endif
return hpp_color_scnprintf(hpp, "%*.2f%%", width - 1, per);
}
static double percent_hitm(struct c2c_hist_entry *c2c_he)
{
struct c2c_hists *hists;
struct c2c_stats *stats;
struct c2c_stats *total;
int tot = 0, st = 0;
double p;
hists = container_of(c2c_he->he.hists, struct c2c_hists, hists);
stats = &c2c_he->stats;
total = &hists->stats;
switch (c2c.display) {
case DISPLAY_RMT:
st = stats->rmt_hitm;
tot = total->rmt_hitm;
break;
case DISPLAY_LCL:
st = stats->lcl_hitm;
tot = total->lcl_hitm;
break;
case DISPLAY_TOT:
st = stats->tot_hitm;
tot = total->tot_hitm;
default:
break;
}
p = tot ? (double) st / tot : 0;
return 100 * p;
}
static int
percent_hitm_entry(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
struct c2c_hist_entry *c2c_he;
int width = c2c_width(fmt, hpp, he->hists);
char buf[10];
double per;
c2c_he = container_of(he, struct c2c_hist_entry, he);
per = percent_hitm(c2c_he);
return scnprintf(hpp->buf, hpp->size, "%*s", width, PERC_STR(buf, per));
}
static int
percent_hitm_color(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
return percent_color(fmt, hpp, he, percent_hitm);
}
static int64_t
percent_hitm_cmp(struct perf_hpp_fmt *fmt __maybe_unused,
struct hist_entry *left, struct hist_entry *right)
{
struct c2c_hist_entry *c2c_left;
struct c2c_hist_entry *c2c_right;
double per_left;
double per_right;
c2c_left = container_of(left, struct c2c_hist_entry, he);
c2c_right = container_of(right, struct c2c_hist_entry, he);
per_left = percent_hitm(c2c_left);
per_right = percent_hitm(c2c_right);
return per_left - per_right;
}
static struct c2c_stats *he_stats(struct hist_entry *he)
{
struct c2c_hist_entry *c2c_he;
c2c_he = container_of(he, struct c2c_hist_entry, he);
return &c2c_he->stats;
}
static struct c2c_stats *total_stats(struct hist_entry *he)
{
struct c2c_hists *hists;
hists = container_of(he->hists, struct c2c_hists, hists);
return &hists->stats;
}
static double percent(int st, int tot)
{
return tot ? 100. * (double) st / (double) tot : 0;
}
static int
percent_rmt_hitm_entry(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
int width = c2c_width(fmt, hpp, he->hists);
double per = PERCENT(he, rmt_hitm);
char buf[10];
return scnprintf(hpp->buf, hpp->size, "%*s", width, PERC_STR(buf, per));
}
static int
percent_rmt_hitm_color(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
return percent_color(fmt, hpp, he, percent_rmt_hitm);
}
static int64_t
percent_rmt_hitm_cmp(struct perf_hpp_fmt *fmt __maybe_unused,
struct hist_entry *left, struct hist_entry *right)
{
double per_left;
double per_right;
per_left = PERCENT(left, lcl_hitm);
per_right = PERCENT(right, lcl_hitm);
return per_left - per_right;
}
static int
percent_lcl_hitm_entry(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
int width = c2c_width(fmt, hpp, he->hists);
double per = PERCENT(he, lcl_hitm);
char buf[10];
return scnprintf(hpp->buf, hpp->size, "%*s", width, PERC_STR(buf, per));
}
static int
percent_lcl_hitm_color(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
return percent_color(fmt, hpp, he, percent_lcl_hitm);
}
static int64_t
percent_lcl_hitm_cmp(struct perf_hpp_fmt *fmt __maybe_unused,
struct hist_entry *left, struct hist_entry *right)
{
double per_left;
double per_right;
per_left = PERCENT(left, lcl_hitm);
per_right = PERCENT(right, lcl_hitm);
return per_left - per_right;
}
static int
percent_stores_l1hit_entry(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
int width = c2c_width(fmt, hpp, he->hists);
double per = PERCENT(he, st_l1hit);
char buf[10];
return scnprintf(hpp->buf, hpp->size, "%*s", width, PERC_STR(buf, per));
}
static int
percent_stores_l1hit_color(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
return percent_color(fmt, hpp, he, percent_st_l1hit);
}
static int64_t
percent_stores_l1hit_cmp(struct perf_hpp_fmt *fmt __maybe_unused,
struct hist_entry *left, struct hist_entry *right)
{
double per_left;
double per_right;
per_left = PERCENT(left, st_l1hit);
per_right = PERCENT(right, st_l1hit);
return per_left - per_right;
}
static int
percent_stores_l1miss_entry(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
int width = c2c_width(fmt, hpp, he->hists);
double per = PERCENT(he, st_l1miss);
char buf[10];
return scnprintf(hpp->buf, hpp->size, "%*s", width, PERC_STR(buf, per));
}
static int
percent_stores_l1miss_color(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
return percent_color(fmt, hpp, he, percent_st_l1miss);
}
static int64_t
percent_stores_l1miss_cmp(struct perf_hpp_fmt *fmt __maybe_unused,
struct hist_entry *left, struct hist_entry *right)
{
double per_left;
double per_right;
per_left = PERCENT(left, st_l1miss);
per_right = PERCENT(right, st_l1miss);
return per_left - per_right;
}
static int
pid_entry(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
int width = c2c_width(fmt, hpp, he->hists);
return scnprintf(hpp->buf, hpp->size, "%*d", width, he->thread->pid_);
}
static int64_t
pid_cmp(struct perf_hpp_fmt *fmt __maybe_unused,
struct hist_entry *left, struct hist_entry *right)
{
return left->thread->pid_ - right->thread->pid_;
}
static int64_t
empty_cmp(struct perf_hpp_fmt *fmt __maybe_unused,
struct hist_entry *left __maybe_unused,
struct hist_entry *right __maybe_unused)
{
return 0;
}
static int
node_entry(struct perf_hpp_fmt *fmt __maybe_unused, struct perf_hpp *hpp,
struct hist_entry *he)
{
struct c2c_hist_entry *c2c_he;
bool first = true;
int node;
int ret = 0;
c2c_he = container_of(he, struct c2c_hist_entry, he);
for (node = 0; node < c2c.nodes_cnt; node++) {
DECLARE_BITMAP(set, c2c.cpus_cnt);
bitmap_zero(set, c2c.cpus_cnt);
bitmap_and(set, c2c_he->cpuset, c2c.nodes[node], c2c.cpus_cnt);
if (!bitmap_weight(set, c2c.cpus_cnt)) {
if (c2c.node_info == 1) {
ret = scnprintf(hpp->buf, hpp->size, "%21s", " ");
advance_hpp(hpp, ret);
}
continue;
}
if (!first) {
ret = scnprintf(hpp->buf, hpp->size, " ");
advance_hpp(hpp, ret);
}
switch (c2c.node_info) {
case 0:
ret = scnprintf(hpp->buf, hpp->size, "%2d", node);
advance_hpp(hpp, ret);
break;
case 1:
{
int num = bitmap_weight(c2c_he->cpuset, c2c.cpus_cnt);
struct c2c_stats *stats = &c2c_he->node_stats[node];
ret = scnprintf(hpp->buf, hpp->size, "%2d{%2d ", node, num);
advance_hpp(hpp, ret);
#define DISPLAY_HITM(__h) \
if (c2c_he->stats.__h> 0) { \
ret = scnprintf(hpp->buf, hpp->size, "%5.1f%% ", \
percent(stats->__h, c2c_he->stats.__h));\
} else { \
ret = scnprintf(hpp->buf, hpp->size, "%6s ", "n/a"); \
}
switch (c2c.display) {
case DISPLAY_RMT:
DISPLAY_HITM(rmt_hitm);
break;
case DISPLAY_LCL:
DISPLAY_HITM(lcl_hitm);
break;
case DISPLAY_TOT:
DISPLAY_HITM(tot_hitm);
default:
break;
}
#undef DISPLAY_HITM
advance_hpp(hpp, ret);
if (c2c_he->stats.store > 0) {
ret = scnprintf(hpp->buf, hpp->size, "%5.1f%%}",
percent(stats->store, c2c_he->stats.store));
} else {
ret = scnprintf(hpp->buf, hpp->size, "%6s}", "n/a");
}
advance_hpp(hpp, ret);
break;
}
case 2:
ret = scnprintf(hpp->buf, hpp->size, "%2d{", node);
advance_hpp(hpp, ret);
ret = bitmap_scnprintf(set, c2c.cpus_cnt, hpp->buf, hpp->size);
advance_hpp(hpp, ret);
ret = scnprintf(hpp->buf, hpp->size, "}");
advance_hpp(hpp, ret);
break;
default:
break;
}
first = false;
}
return 0;
}
static int
mean_entry(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he, double mean)
{
int width = c2c_width(fmt, hpp, he->hists);
char buf[10];
scnprintf(buf, 10, "%6.0f", mean);
return scnprintf(hpp->buf, hpp->size, "%*s", width, buf);
}
static int
cpucnt_entry(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
struct c2c_hist_entry *c2c_he;
int width = c2c_width(fmt, hpp, he->hists);
char buf[10];
c2c_he = container_of(he, struct c2c_hist_entry, he);
scnprintf(buf, 10, "%d", bitmap_weight(c2c_he->cpuset, c2c.cpus_cnt));
return scnprintf(hpp->buf, hpp->size, "%*s", width, buf);
}
static int
cl_idx_entry(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
struct c2c_hist_entry *c2c_he;
int width = c2c_width(fmt, hpp, he->hists);
char buf[10];
c2c_he = container_of(he, struct c2c_hist_entry, he);
scnprintf(buf, 10, "%u", c2c_he->cacheline_idx);
return scnprintf(hpp->buf, hpp->size, "%*s", width, buf);
}
static int
cl_idx_empty_entry(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
int width = c2c_width(fmt, hpp, he->hists);
return scnprintf(hpp->buf, hpp->size, "%*s", width, "");
}
static void fmt_free(struct perf_hpp_fmt *fmt)
{
struct c2c_fmt *c2c_fmt;
c2c_fmt = container_of(fmt, struct c2c_fmt, fmt);
free(c2c_fmt);
}
static bool fmt_equal(struct perf_hpp_fmt *a, struct perf_hpp_fmt *b)
{
struct c2c_fmt *c2c_a = container_of(a, struct c2c_fmt, fmt);
struct c2c_fmt *c2c_b = container_of(b, struct c2c_fmt, fmt);
return c2c_a->dim == c2c_b->dim;
}
static struct c2c_dimension *get_dimension(const char *name)
{
unsigned int i;
for (i = 0; dimensions[i]; i++) {
struct c2c_dimension *dim = dimensions[i];
if (!strcmp(dim->name, name))
return dim;
};
return NULL;
}
static int c2c_se_entry(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
struct c2c_fmt *c2c_fmt = container_of(fmt, struct c2c_fmt, fmt);
struct c2c_dimension *dim = c2c_fmt->dim;
size_t len = fmt->user_len;
if (!len) {
len = hists__col_len(he->hists, dim->se->se_width_idx);
if (dim == &dim_symbol || dim == &dim_srcline)
len = symbol_width(he->hists, dim->se);
}
return dim->se->se_snprintf(he, hpp->buf, hpp->size, len);
}
static int64_t c2c_se_cmp(struct perf_hpp_fmt *fmt,
struct hist_entry *a, struct hist_entry *b)
{
struct c2c_fmt *c2c_fmt = container_of(fmt, struct c2c_fmt, fmt);
struct c2c_dimension *dim = c2c_fmt->dim;
return dim->se->se_cmp(a, b);
}
static int64_t c2c_se_collapse(struct perf_hpp_fmt *fmt,
struct hist_entry *a, struct hist_entry *b)
{
struct c2c_fmt *c2c_fmt = container_of(fmt, struct c2c_fmt, fmt);
struct c2c_dimension *dim = c2c_fmt->dim;
int64_t (*collapse_fn)(struct hist_entry *, struct hist_entry *);
collapse_fn = dim->se->se_collapse ?: dim->se->se_cmp;
return collapse_fn(a, b);
}
static struct c2c_fmt *get_format(const char *name)
{
struct c2c_dimension *dim = get_dimension(name);
struct c2c_fmt *c2c_fmt;
struct perf_hpp_fmt *fmt;
if (!dim)
return NULL;
c2c_fmt = zalloc(sizeof(*c2c_fmt));
if (!c2c_fmt)
return NULL;
c2c_fmt->dim = dim;
fmt = &c2c_fmt->fmt;
INIT_LIST_HEAD(&fmt->list);
INIT_LIST_HEAD(&fmt->sort_list);
fmt->cmp = dim->se ? c2c_se_cmp : dim->cmp;
fmt->sort = dim->se ? c2c_se_cmp : dim->cmp;
fmt->color = dim->se ? NULL : dim->color;
fmt->entry = dim->se ? c2c_se_entry : dim->entry;
fmt->header = c2c_header;
fmt->width = c2c_width;
fmt->collapse = dim->se ? c2c_se_collapse : dim->cmp;
fmt->equal = fmt_equal;
fmt->free = fmt_free;
return c2c_fmt;
}
static int c2c_hists__init_output(struct perf_hpp_list *hpp_list, char *name)
{
struct c2c_fmt *c2c_fmt = get_format(name);
if (!c2c_fmt) {
reset_dimensions();
return output_field_add(hpp_list, name);
}
perf_hpp_list__column_register(hpp_list, &c2c_fmt->fmt);
return 0;
}
static int c2c_hists__init_sort(struct perf_hpp_list *hpp_list, char *name)
{
struct c2c_fmt *c2c_fmt = get_format(name);
struct c2c_dimension *dim;
if (!c2c_fmt) {
reset_dimensions();
return sort_dimension__add(hpp_list, name, NULL, 0);
}
dim = c2c_fmt->dim;
if (dim == &dim_dso)
hpp_list->dso = 1;
perf_hpp_list__register_sort_field(hpp_list, &c2c_fmt->fmt);
return 0;
}
static int hpp_list__parse(struct perf_hpp_list *hpp_list,
const char *output_,
const char *sort_)
{
char *output = output_ ? strdup(output_) : NULL;
char *sort = sort_ ? strdup(sort_) : NULL;
int ret;
PARSE_LIST(output, c2c_hists__init_output);
PARSE_LIST(sort, c2c_hists__init_sort);
perf_hpp__setup_output_field(hpp_list);
#if 0
perf_hpp__append_sort_keys(&hists->list);
#endif
free(output);
free(sort);
return ret;
}
static int c2c_hists__init(struct c2c_hists *hists,
const char *sort,
int nr_header_lines)
{
__hists__init(&hists->hists, &hists->list);
perf_hpp_list__init(&hists->list);
hists->list.nr_header_lines = nr_header_lines;
return hpp_list__parse(&hists->list, NULL, sort);
}
static int c2c_hists__reinit(struct c2c_hists *c2c_hists,
const char *output,
const char *sort)
{
perf_hpp__reset_output_field(&c2c_hists->list);
return hpp_list__parse(&c2c_hists->list, output, sort);
}
static bool he__display(struct hist_entry *he, struct c2c_stats *stats)
{
struct c2c_hist_entry *c2c_he;
double ld_dist;
if (c2c.show_all)
return true;
c2c_he = container_of(he, struct c2c_hist_entry, he);
#define FILTER_HITM(__h) \
if (stats->__h) { \
ld_dist = ((double)c2c_he->stats.__h / stats->__h); \
if (ld_dist < DISPLAY_LINE_LIMIT) \
he->filtered = HIST_FILTER__C2C; \
} else { \
he->filtered = HIST_FILTER__C2C; \
}
switch (c2c.display) {
case DISPLAY_LCL:
FILTER_HITM(lcl_hitm);
break;
case DISPLAY_RMT:
FILTER_HITM(rmt_hitm);
break;
case DISPLAY_TOT:
FILTER_HITM(tot_hitm);
default:
break;
};
#undef FILTER_HITM
return he->filtered == 0;
}
static inline int valid_hitm_or_store(struct hist_entry *he)
{
struct c2c_hist_entry *c2c_he;
bool has_hitm;
c2c_he = container_of(he, struct c2c_hist_entry, he);
has_hitm = c2c.display == DISPLAY_TOT ? c2c_he->stats.tot_hitm :
c2c.display == DISPLAY_LCL ? c2c_he->stats.lcl_hitm :
c2c_he->stats.rmt_hitm;
return has_hitm || c2c_he->stats.store;
}
static void calc_width(struct hist_entry *he)
{
struct c2c_hists *c2c_hists;
c2c_hists = container_of(he->hists, struct c2c_hists, hists);
hists__calc_col_len(&c2c_hists->hists, he);
}
static int filter_cb(struct hist_entry *he)
{
if (c2c.show_src && !he->srcline)
he->srcline = hist_entry__get_srcline(he);
calc_width(he);
if (!valid_hitm_or_store(he))
he->filtered = HIST_FILTER__C2C;
return 0;
}
static int resort_cl_cb(struct hist_entry *he)
{
struct c2c_hist_entry *c2c_he;
struct c2c_hists *c2c_hists;
bool display = he__display(he, &c2c.hitm_stats);
c2c_he = container_of(he, struct c2c_hist_entry, he);
c2c_hists = c2c_he->hists;
calc_width(he);
if (display && c2c_hists) {
static unsigned int idx;
c2c_he->cacheline_idx = idx++;
c2c_hists__reinit(c2c_hists, c2c.cl_output, c2c.cl_resort);
hists__collapse_resort(&c2c_hists->hists, NULL);
hists__output_resort_cb(&c2c_hists->hists, NULL, filter_cb);
}
return 0;
}
static void setup_nodes_header(void)
{
dim_node.header = header_node[c2c.node_info];
}
static int setup_nodes(struct perf_session *session)
{
struct numa_node *n;
unsigned long **nodes;
int node, cpu;
int *cpu2node;
if (c2c.node_info > 2)
c2c.node_info = 2;
c2c.nodes_cnt = session->header.env.nr_numa_nodes;
c2c.cpus_cnt = session->header.env.nr_cpus_online;
n = session->header.env.numa_nodes;
if (!n)
return -EINVAL;
nodes = zalloc(sizeof(unsigned long *) * c2c.nodes_cnt);
if (!nodes)
return -ENOMEM;
c2c.nodes = nodes;
cpu2node = zalloc(sizeof(int) * c2c.cpus_cnt);
if (!cpu2node)
return -ENOMEM;
for (cpu = 0; cpu < c2c.cpus_cnt; cpu++)
cpu2node[cpu] = -1;
c2c.cpu2node = cpu2node;
for (node = 0; node < c2c.nodes_cnt; node++) {
struct cpu_map *map = n[node].map;
unsigned long *set;
set = bitmap_alloc(c2c.cpus_cnt);
if (!set)
return -ENOMEM;
for (cpu = 0; cpu < map->nr; cpu++) {
set_bit(map->map[cpu], set);
if (WARN_ONCE(cpu2node[map->map[cpu]] != -1, "node/cpu topology bug"))
return -EINVAL;
cpu2node[map->map[cpu]] = node;
}
nodes[node] = set;
}
setup_nodes_header();
return 0;
}
static int resort_hitm_cb(struct hist_entry *he)
{
struct c2c_hist_entry *c2c_he;
c2c_he = container_of(he, struct c2c_hist_entry, he);
if (HAS_HITMS(c2c_he)) {
c2c.shared_clines++;
c2c_add_stats(&c2c.hitm_stats, &c2c_he->stats);
}
return 0;
}
static int hists__iterate_cb(struct hists *hists, hists__resort_cb_t cb)
{
struct rb_node *next = rb_first(&hists->entries);
int ret = 0;
while (next) {
struct hist_entry *he;
he = rb_entry(next, struct hist_entry, rb_node);
ret = cb(he);
if (ret)
break;
next = rb_next(&he->rb_node);
}
return ret;
}
static void print_c2c__display_stats(FILE *out)
{
int llc_misses;
struct c2c_stats *stats = &c2c.hists.stats;
llc_misses = stats->lcl_dram +
stats->rmt_dram +
stats->rmt_hit +
stats->rmt_hitm;
fprintf(out, "=================================================\n");
fprintf(out, " Trace Event Information \n");
fprintf(out, "=================================================\n");
fprintf(out, " Total records : %10d\n", stats->nr_entries);
fprintf(out, " Locked Load/Store Operations : %10d\n", stats->locks);
fprintf(out, " Load Operations : %10d\n", stats->load);
fprintf(out, " Loads - uncacheable : %10d\n", stats->ld_uncache);
fprintf(out, " Loads - IO : %10d\n", stats->ld_io);
fprintf(out, " Loads - Miss : %10d\n", stats->ld_miss);
fprintf(out, " Loads - no mapping : %10d\n", stats->ld_noadrs);
fprintf(out, " Load Fill Buffer Hit : %10d\n", stats->ld_fbhit);
fprintf(out, " Load L1D hit : %10d\n", stats->ld_l1hit);
fprintf(out, " Load L2D hit : %10d\n", stats->ld_l2hit);
fprintf(out, " Load LLC hit : %10d\n", stats->ld_llchit + stats->lcl_hitm);
fprintf(out, " Load Local HITM : %10d\n", stats->lcl_hitm);
fprintf(out, " Load Remote HITM : %10d\n", stats->rmt_hitm);
fprintf(out, " Load Remote HIT : %10d\n", stats->rmt_hit);
fprintf(out, " Load Local DRAM : %10d\n", stats->lcl_dram);
fprintf(out, " Load Remote DRAM : %10d\n", stats->rmt_dram);
fprintf(out, " Load MESI State Exclusive : %10d\n", stats->ld_excl);
fprintf(out, " Load MESI State Shared : %10d\n", stats->ld_shared);
fprintf(out, " Load LLC Misses : %10d\n", llc_misses);
fprintf(out, " LLC Misses to Local DRAM : %10.1f%%\n", ((double)stats->lcl_dram/(double)llc_misses) * 100.);
fprintf(out, " LLC Misses to Remote DRAM : %10.1f%%\n", ((double)stats->rmt_dram/(double)llc_misses) * 100.);
fprintf(out, " LLC Misses to Remote cache (HIT) : %10.1f%%\n", ((double)stats->rmt_hit /(double)llc_misses) * 100.);
fprintf(out, " LLC Misses to Remote cache (HITM) : %10.1f%%\n", ((double)stats->rmt_hitm/(double)llc_misses) * 100.);
fprintf(out, " Store Operations : %10d\n", stats->store);
fprintf(out, " Store - uncacheable : %10d\n", stats->st_uncache);
fprintf(out, " Store - no mapping : %10d\n", stats->st_noadrs);
fprintf(out, " Store L1D Hit : %10d\n", stats->st_l1hit);
fprintf(out, " Store L1D Miss : %10d\n", stats->st_l1miss);
fprintf(out, " No Page Map Rejects : %10d\n", stats->nomap);
fprintf(out, " Unable to parse data source : %10d\n", stats->noparse);
}
static void print_shared_cacheline_info(FILE *out)
{
struct c2c_stats *stats = &c2c.hitm_stats;
int hitm_cnt = stats->lcl_hitm + stats->rmt_hitm;
fprintf(out, "=================================================\n");
fprintf(out, " Global Shared Cache Line Event Information \n");
fprintf(out, "=================================================\n");
fprintf(out, " Total Shared Cache Lines : %10d\n", c2c.shared_clines);
fprintf(out, " Load HITs on shared lines : %10d\n", stats->load);
fprintf(out, " Fill Buffer Hits on shared lines : %10d\n", stats->ld_fbhit);
fprintf(out, " L1D hits on shared lines : %10d\n", stats->ld_l1hit);
fprintf(out, " L2D hits on shared lines : %10d\n", stats->ld_l2hit);
fprintf(out, " LLC hits on shared lines : %10d\n", stats->ld_llchit + stats->lcl_hitm);
fprintf(out, " Locked Access on shared lines : %10d\n", stats->locks);
fprintf(out, " Store HITs on shared lines : %10d\n", stats->store);
fprintf(out, " Store L1D hits on shared lines : %10d\n", stats->st_l1hit);
fprintf(out, " Total Merged records : %10d\n", hitm_cnt + stats->store);
}
static void print_cacheline(struct c2c_hists *c2c_hists,
struct hist_entry *he_cl,
struct perf_hpp_list *hpp_list,
FILE *out)
{
char bf[1000];
struct perf_hpp hpp = {
.buf = bf,
.size = 1000,
};
static bool once;
if (!once) {
hists__fprintf_headers(&c2c_hists->hists, out);
once = true;
} else {
fprintf(out, "\n");
}
fprintf(out, " -------------------------------------------------------------\n");
__hist_entry__snprintf(he_cl, &hpp, hpp_list);
fprintf(out, "%s\n", bf);
fprintf(out, " -------------------------------------------------------------\n");
hists__fprintf(&c2c_hists->hists, false, 0, 0, 0, out, true);
}
static void print_pareto(FILE *out)
{
struct perf_hpp_list hpp_list;
struct rb_node *nd;
int ret;
perf_hpp_list__init(&hpp_list);
ret = hpp_list__parse(&hpp_list,
"cl_num,"
"cl_rmt_hitm,"
"cl_lcl_hitm,"
"cl_stores_l1hit,"
"cl_stores_l1miss,"
"dcacheline",
NULL);
if (WARN_ONCE(ret, "failed to setup sort entries\n"))
return;
nd = rb_first(&c2c.hists.hists.entries);
for (; nd; nd = rb_next(nd)) {
struct hist_entry *he = rb_entry(nd, struct hist_entry, rb_node);
struct c2c_hist_entry *c2c_he;
if (he->filtered)
continue;
c2c_he = container_of(he, struct c2c_hist_entry, he);
print_cacheline(c2c_he->hists, he, &hpp_list, out);
}
}
static void print_c2c_info(FILE *out, struct perf_session *session)
{
struct perf_evlist *evlist = session->evlist;
struct perf_evsel *evsel;
bool first = true;
fprintf(out, "=================================================\n");
fprintf(out, " c2c details \n");
fprintf(out, "=================================================\n");
evlist__for_each_entry(evlist, evsel) {
fprintf(out, "%-36s: %s\n", first ? " Events" : "",
perf_evsel__name(evsel));
first = false;
}
fprintf(out, " Cachelines sort on : %s HITMs\n",
display_str[c2c.display]);
fprintf(out, " Cacheline data grouping : %s\n", c2c.cl_sort);
}
static void perf_c2c__hists_fprintf(FILE *out, struct perf_session *session)
{
setup_pager();
print_c2c__display_stats(out);
fprintf(out, "\n");
print_shared_cacheline_info(out);
fprintf(out, "\n");
print_c2c_info(out, session);
if (c2c.stats_only)
return;
fprintf(out, "\n");
fprintf(out, "=================================================\n");
fprintf(out, " Shared Data Cache Line Table \n");
fprintf(out, "=================================================\n");
fprintf(out, "#\n");
hists__fprintf(&c2c.hists.hists, true, 0, 0, 0, stdout, false);
fprintf(out, "\n");
fprintf(out, "=================================================\n");
fprintf(out, " Shared Cache Line Distribution Pareto \n");
fprintf(out, "=================================================\n");
fprintf(out, "#\n");
print_pareto(out);
}
static void c2c_browser__update_nr_entries(struct hist_browser *hb)
{
u64 nr_entries = 0;
struct rb_node *nd = rb_first(&hb->hists->entries);
while (nd) {
struct hist_entry *he = rb_entry(nd, struct hist_entry, rb_node);
if (!he->filtered)
nr_entries++;
nd = rb_next(nd);
}
hb->nr_non_filtered_entries = nr_entries;
}
static int
perf_c2c_cacheline_browser__title(struct hist_browser *browser,
char *bf, size_t size)
{
struct c2c_cacheline_browser *cl_browser;
struct hist_entry *he;
uint64_t addr = 0;
cl_browser = container_of(browser, struct c2c_cacheline_browser, hb);
he = cl_browser->he;
if (he->mem_info)
addr = cl_address(he->mem_info->daddr.addr);
scnprintf(bf, size, "Cacheline 0x%lx", addr);
return 0;
}
static struct c2c_cacheline_browser*
c2c_cacheline_browser__new(struct hists *hists, struct hist_entry *he)
{
struct c2c_cacheline_browser *browser;
browser = zalloc(sizeof(*browser));
if (browser) {
hist_browser__init(&browser->hb, hists);
browser->hb.c2c_filter = true;
browser->hb.title = perf_c2c_cacheline_browser__title;
browser->he = he;
}
return browser;
}
static int perf_c2c__browse_cacheline(struct hist_entry *he)
{
struct c2c_hist_entry *c2c_he;
struct c2c_hists *c2c_hists;
struct c2c_cacheline_browser *cl_browser;
struct hist_browser *browser;
int key = -1;
const char help[] =
" ENTER Togle callchains (if present) \n"
" n Togle Node details info \n"
" s Togle full lenght of symbol and source line columns \n"
" q Return back to cacheline list \n";
c2c.symbol_full = false;
c2c_he = container_of(he, struct c2c_hist_entry, he);
c2c_hists = c2c_he->hists;
cl_browser = c2c_cacheline_browser__new(&c2c_hists->hists, he);
if (cl_browser == NULL)
return -1;
browser = &cl_browser->hb;
SLang_reset_tty();
SLang_init_tty(0, 0, 0);
c2c_browser__update_nr_entries(browser);
while (1) {
key = hist_browser__run(browser, "? - help");
switch (key) {
case 's':
c2c.symbol_full = !c2c.symbol_full;
break;
case 'n':
c2c.node_info = (c2c.node_info + 1) % 3;
setup_nodes_header();
break;
case 'q':
goto out;
case '?':
ui_browser__help_window(&browser->b, help);
break;
default:
break;
}
}
out:
free(cl_browser);
return 0;
}
static int perf_c2c_browser__title(struct hist_browser *browser,
char *bf, size_t size)
{
scnprintf(bf, size,
"Shared Data Cache Line Table "
"(%lu entries, sorted on %s HITMs)",
browser->nr_non_filtered_entries,
display_str[c2c.display]);
return 0;
}
static struct hist_browser*
perf_c2c_browser__new(struct hists *hists)
{
struct hist_browser *browser = hist_browser__new(hists);
if (browser) {
browser->title = perf_c2c_browser__title;
browser->c2c_filter = true;
}
return browser;
}
static int perf_c2c__hists_browse(struct hists *hists)
{
struct hist_browser *browser;
int key = -1;
const char help[] =
" d Display cacheline details \n"
" ENTER Togle callchains (if present) \n"
" q Quit \n";
browser = perf_c2c_browser__new(hists);
if (browser == NULL)
return -1;
SLang_reset_tty();
SLang_init_tty(0, 0, 0);
c2c_browser__update_nr_entries(browser);
while (1) {
key = hist_browser__run(browser, "? - help");
switch (key) {
case 'q':
goto out;
case 'd':
perf_c2c__browse_cacheline(browser->he_selection);
break;
case '?':
ui_browser__help_window(&browser->b, help);
break;
default:
break;
}
}
out:
hist_browser__delete(browser);
return 0;
}
static void perf_c2c_display(struct perf_session *session)
{
if (c2c.use_stdio)
perf_c2c__hists_fprintf(stdout, session);
else
perf_c2c__hists_browse(&c2c.hists.hists);
}
static void perf_c2c_display(struct perf_session *session)
{
use_browser = 0;
perf_c2c__hists_fprintf(stdout, session);
}
static void ui_quirks(void)
{
if (!c2c.use_stdio) {
dim_offset.width = 5;
dim_offset.header = header_offset_tui;
}
dim_percent_hitm.header = percent_hitm_header[c2c.display];
}
static int
parse_callchain_opt(const struct option *opt, const char *arg, int unset)
{
struct callchain_param *callchain = opt->value;
callchain->enabled = !unset;
if (unset) {
symbol_conf.use_callchain = false;
callchain->mode = CHAIN_NONE;
return 0;
}
return parse_callchain_report_opt(arg);
}
static int setup_callchain(struct perf_evlist *evlist)
{
u64 sample_type = perf_evlist__combined_sample_type(evlist);
enum perf_call_graph_mode mode = CALLCHAIN_NONE;
if ((sample_type & PERF_SAMPLE_REGS_USER) &&
(sample_type & PERF_SAMPLE_STACK_USER))
mode = CALLCHAIN_DWARF;
else if (sample_type & PERF_SAMPLE_BRANCH_STACK)
mode = CALLCHAIN_LBR;
else if (sample_type & PERF_SAMPLE_CALLCHAIN)
mode = CALLCHAIN_FP;
if (!callchain_param.enabled &&
callchain_param.mode != CHAIN_NONE &&
mode != CALLCHAIN_NONE) {
symbol_conf.use_callchain = true;
if (callchain_register_param(&callchain_param) < 0) {
ui__error("Can't register callchain params.\n");
return -EINVAL;
}
}
callchain_param.record_mode = mode;
callchain_param.min_percent = 0;
return 0;
}
static int setup_display(const char *str)
{
const char *display = str ?: "tot";
if (!strcmp(display, "tot"))
c2c.display = DISPLAY_TOT;
else if (!strcmp(display, "rmt"))
c2c.display = DISPLAY_RMT;
else if (!strcmp(display, "lcl"))
c2c.display = DISPLAY_LCL;
else {
pr_err("failed: unknown display type: %s\n", str);
return -1;
}
return 0;
}
static int build_cl_output(char *cl_sort, bool no_source)
{
char *tok, *tmp, *buf = strdup(cl_sort);
bool add_pid = false;
bool add_tid = false;
bool add_iaddr = false;
bool add_sym = false;
bool add_dso = false;
bool add_src = false;
if (!buf)
return -ENOMEM;
for_each_token(tok, buf, ",", tmp) {
if (!strcmp(tok, "tid")) {
add_tid = true;
} else if (!strcmp(tok, "pid")) {
add_pid = true;
} else if (!strcmp(tok, "iaddr")) {
add_iaddr = true;
add_sym = true;
add_dso = true;
add_src = no_source ? false : true;
} else if (!strcmp(tok, "dso")) {
add_dso = true;
} else if (strcmp(tok, "offset")) {
pr_err("unrecognized sort token: %s\n", tok);
return -EINVAL;
}
}
if (asprintf(&c2c.cl_output,
"%s%s%s%s%s%s%s%s%s%s",
c2c.use_stdio ? "cl_num_empty," : "",
"percent_rmt_hitm,"
"percent_lcl_hitm,"
"percent_stores_l1hit,"
"percent_stores_l1miss,"
"offset,",
add_pid ? "pid," : "",
add_tid ? "tid," : "",
add_iaddr ? "iaddr," : "",
"mean_rmt,"
"mean_lcl,"
"mean_load,"
"cpucnt,",
add_sym ? "symbol," : "",
add_dso ? "dso," : "",
add_src ? "cl_srcline," : "",
"node") < 0)
return -ENOMEM;
c2c.show_src = add_src;
free(buf);
return 0;
}
static int setup_coalesce(const char *coalesce, bool no_source)
{
const char *c = coalesce ?: coalesce_default;
if (asprintf(&c2c.cl_sort, "offset,%s", c) < 0)
return -ENOMEM;
if (build_cl_output(c2c.cl_sort, no_source))
return -1;
if (asprintf(&c2c.cl_resort, "offset,%s",
c2c.display == DISPLAY_TOT ?
"tot_hitm" :
c2c.display == DISPLAY_RMT ?
"rmt_hitm,lcl_hitm" :
"lcl_hitm,rmt_hitm") < 0)
return -ENOMEM;
pr_debug("coalesce sort fields: %s\n", c2c.cl_sort);
pr_debug("coalesce resort fields: %s\n", c2c.cl_resort);
pr_debug("coalesce output fields: %s\n", c2c.cl_output);
return 0;
}
static int perf_c2c__report(int argc, const char **argv)
{
struct perf_session *session;
struct ui_progress prog;
struct perf_data_file file = {
.mode = PERF_DATA_MODE_READ,
};
char callchain_default_opt[] = CALLCHAIN_DEFAULT_OPT;
const char *display = NULL;
const char *coalesce = NULL;
bool no_source = false;
const struct option options[] = {
OPT_STRING('k', "vmlinux", &symbol_conf.vmlinux_name,
"file", "vmlinux pathname"),
OPT_STRING('i', "input", &input_name, "file",
"the input file to process"),
OPT_INCR('N', "node-info", &c2c.node_info,
"show extra node info in report (repeat for more info)"),
#ifdef HAVE_SLANG_SUPPORT
OPT_BOOLEAN(0, "stdio", &c2c.use_stdio, "Use the stdio interface"),
#endif
OPT_BOOLEAN(0, "stats", &c2c.stats_only,
"Use the stdio interface"),
OPT_BOOLEAN(0, "full-symbols", &c2c.symbol_full,
"Display full length of symbols"),
OPT_BOOLEAN(0, "no-source", &no_source,
"Do not display Source Line column"),
OPT_BOOLEAN(0, "show-all", &c2c.show_all,
"Show all captured HITM lines."),
OPT_CALLBACK_DEFAULT('g', "call-graph", &callchain_param,
"print_type,threshold[,print_limit],order,sort_key[,branch],value",
callchain_help, &parse_callchain_opt,
callchain_default_opt),
OPT_STRING('d', "display", &display, "Switch HITM output type", "lcl,rmt"),
OPT_STRING('c', "coalesce", &coalesce, "coalesce fields",
"coalesce fields: pid,tid,iaddr,dso"),
OPT_BOOLEAN('f', "force", &symbol_conf.force, "don't complain, do it"),
OPT_PARENT(c2c_options),
OPT_END()
};
int err = 0;
argc = parse_options(argc, argv, options, report_c2c_usage,
PARSE_OPT_STOP_AT_NON_OPTION);
if (argc)
usage_with_options(report_c2c_usage, options);
if (c2c.stats_only)
c2c.use_stdio = true;
if (!input_name || !strlen(input_name))
input_name = "perf.data";
file.path = input_name;
file.force = symbol_conf.force;
err = setup_display(display);
if (err)
goto out;
err = setup_coalesce(coalesce, no_source);
if (err) {
pr_debug("Failed to initialize hists\n");
goto out;
}
err = c2c_hists__init(&c2c.hists, "dcacheline", 2);
if (err) {
pr_debug("Failed to initialize hists\n");
goto out;
}
session = perf_session__new(&file, 0, &c2c.tool);
if (session == NULL) {
pr_debug("No memory for session\n");
goto out;
}
err = setup_nodes(session);
if (err) {
pr_err("Failed setup nodes\n");
goto out;
}
err = setup_callchain(session->evlist);
if (err)
goto out_session;
if (symbol__init(&session->header.env) < 0)
goto out_session;
if (perf_data_file__is_pipe(session->file)) {
pr_debug("No pipe support at the moment.\n");
goto out_session;
}
if (c2c.use_stdio)
use_browser = 0;
else
use_browser = 1;
setup_browser(false);
err = perf_session__process_events(session);
if (err) {
pr_err("failed to process sample\n");
goto out_session;
}
c2c_hists__reinit(&c2c.hists,
"cl_idx,"
"dcacheline,"
"tot_recs,"
"percent_hitm,"
"tot_hitm,lcl_hitm,rmt_hitm,"
"stores,stores_l1hit,stores_l1miss,"
"dram_lcl,dram_rmt,"
"ld_llcmiss,"
"tot_loads,"
"ld_fbhit,ld_l1hit,ld_l2hit,"
"ld_lclhit,ld_rmthit",
c2c.display == DISPLAY_TOT ? "tot_hitm" :
c2c.display == DISPLAY_LCL ? "lcl_hitm" : "rmt_hitm"
);
ui_progress__init(&prog, c2c.hists.hists.nr_entries, "Sorting...");
hists__collapse_resort(&c2c.hists.hists, NULL);
hists__output_resort_cb(&c2c.hists.hists, &prog, resort_hitm_cb);
hists__iterate_cb(&c2c.hists.hists, resort_cl_cb);
ui_progress__finish();
ui_quirks();
perf_c2c_display(session);
out_session:
perf_session__delete(session);
out:
return err;
}
static int parse_record_events(const struct option *opt,
const char *str, int unset __maybe_unused)
{
bool *event_set = (bool *) opt->value;
*event_set = true;
return perf_mem_events__parse(str);
}
static int perf_c2c__record(int argc, const char **argv)
{
int rec_argc, i = 0, j;
const char **rec_argv;
int ret;
bool all_user = false, all_kernel = false;
bool event_set = false;
struct option options[] = {
OPT_CALLBACK('e', "event", &event_set, "event",
"event selector. Use 'perf mem record -e list' to list available events",
parse_record_events),
OPT_BOOLEAN('u', "all-user", &all_user, "collect only user level data"),
OPT_BOOLEAN('k', "all-kernel", &all_kernel, "collect only kernel level data"),
OPT_UINTEGER('l', "ldlat", &perf_mem_events__loads_ldlat, "setup mem-loads latency"),
OPT_PARENT(c2c_options),
OPT_END()
};
if (perf_mem_events__init()) {
pr_err("failed: memory events not supported\n");
return -1;
}
argc = parse_options(argc, argv, options, record_mem_usage,
PARSE_OPT_KEEP_UNKNOWN);
rec_argc = argc + 10;
rec_argv = calloc(rec_argc + 1, sizeof(char *));
if (!rec_argv)
return -1;
rec_argv[i++] = "record";
if (!event_set) {
perf_mem_events[PERF_MEM_EVENTS__LOAD].record = true;
perf_mem_events[PERF_MEM_EVENTS__STORE].record = true;
}
if (perf_mem_events[PERF_MEM_EVENTS__LOAD].record)
rec_argv[i++] = "-W";
rec_argv[i++] = "-d";
rec_argv[i++] = "--sample-cpu";
for (j = 0; j < PERF_MEM_EVENTS__MAX; j++) {
if (!perf_mem_events[j].record)
continue;
if (!perf_mem_events[j].supported) {
pr_err("failed: event '%s' not supported\n",
perf_mem_events[j].name);
return -1;
}
rec_argv[i++] = "-e";
rec_argv[i++] = perf_mem_events__name(j);
};
if (all_user)
rec_argv[i++] = "--all-user";
if (all_kernel)
rec_argv[i++] = "--all-kernel";
for (j = 0; j < argc; j++, i++)
rec_argv[i] = argv[j];
if (verbose > 0) {
pr_debug("calling: ");
j = 0;
while (rec_argv[j]) {
pr_debug("%s ", rec_argv[j]);
j++;
}
pr_debug("\n");
}
ret = cmd_record(i, rec_argv, NULL);
free(rec_argv);
return ret;
}
int cmd_c2c(int argc, const char **argv, const char *prefix __maybe_unused)
{
argc = parse_options(argc, argv, c2c_options, c2c_usage,
PARSE_OPT_STOP_AT_NON_OPTION);
if (!argc)
usage_with_options(c2c_usage, c2c_options);
if (!strncmp(argv[0], "rec", 3)) {
return perf_c2c__record(argc, argv);
} else if (!strncmp(argv[0], "rep", 3)) {
return perf_c2c__report(argc, argv);
} else {
usage_with_options(c2c_usage, c2c_options);
}
return 0;
}
