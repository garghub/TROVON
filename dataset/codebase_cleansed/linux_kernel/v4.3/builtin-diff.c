static int setup_compute_opt_wdiff(char *opt)
{
char *w1_str = opt;
char *w2_str;
int ret = -EINVAL;
if (!opt)
goto out;
w2_str = strchr(opt, ',');
if (!w2_str)
goto out;
*w2_str++ = 0x0;
if (!*w2_str)
goto out;
compute_wdiff_w1 = strtol(w1_str, NULL, 10);
compute_wdiff_w2 = strtol(w2_str, NULL, 10);
if (!compute_wdiff_w1 || !compute_wdiff_w2)
goto out;
pr_debug("compute wdiff w1(%" PRId64 ") w2(%" PRId64 ")\n",
compute_wdiff_w1, compute_wdiff_w2);
ret = 0;
out:
if (ret)
pr_err("Failed: wrong weight data, use 'wdiff:w1,w2'\n");
return ret;
}
static int setup_compute_opt(char *opt)
{
if (compute == COMPUTE_WEIGHTED_DIFF)
return setup_compute_opt_wdiff(opt);
if (opt) {
pr_err("Failed: extra option specified '%s'", opt);
return -EINVAL;
}
return 0;
}
static int setup_compute(const struct option *opt, const char *str,
int unset __maybe_unused)
{
int *cp = (int *) opt->value;
char *cstr = (char *) str;
char buf[50];
unsigned i;
char *option;
if (!str) {
*cp = COMPUTE_DELTA;
return 0;
}
option = strchr(str, ':');
if (option) {
unsigned len = option++ - str;
if (len >= sizeof(buf))
return -EINVAL;
strncpy(buf, str, len);
buf[len] = 0x0;
cstr = buf;
}
for (i = 0; i < COMPUTE_MAX; i++)
if (!strcmp(cstr, compute_names[i])) {
*cp = i;
return setup_compute_opt(option);
}
pr_err("Failed: '%s' is not computation method "
"(use 'delta','ratio' or 'wdiff')\n", str);
return -EINVAL;
}
static double period_percent(struct hist_entry *he, u64 period)
{
u64 total = hists__total_period(he->hists);
return (period * 100.0) / total;
}
static double compute_delta(struct hist_entry *he, struct hist_entry *pair)
{
double old_percent = period_percent(he, he->stat.period);
double new_percent = period_percent(pair, pair->stat.period);
pair->diff.period_ratio_delta = new_percent - old_percent;
pair->diff.computed = true;
return pair->diff.period_ratio_delta;
}
static double compute_ratio(struct hist_entry *he, struct hist_entry *pair)
{
double old_period = he->stat.period ?: 1;
double new_period = pair->stat.period;
pair->diff.computed = true;
pair->diff.period_ratio = new_period / old_period;
return pair->diff.period_ratio;
}
static s64 compute_wdiff(struct hist_entry *he, struct hist_entry *pair)
{
u64 old_period = he->stat.period;
u64 new_period = pair->stat.period;
pair->diff.computed = true;
pair->diff.wdiff = new_period * compute_wdiff_w2 -
old_period * compute_wdiff_w1;
return pair->diff.wdiff;
}
static int formula_delta(struct hist_entry *he, struct hist_entry *pair,
char *buf, size_t size)
{
u64 he_total = he->hists->stats.total_period;
u64 pair_total = pair->hists->stats.total_period;
if (symbol_conf.filter_relative) {
he_total = he->hists->stats.total_non_filtered_period;
pair_total = pair->hists->stats.total_non_filtered_period;
}
return scnprintf(buf, size,
"(%" PRIu64 " * 100 / %" PRIu64 ") - "
"(%" PRIu64 " * 100 / %" PRIu64 ")",
pair->stat.period, pair_total,
he->stat.period, he_total);
}
static int formula_ratio(struct hist_entry *he, struct hist_entry *pair,
char *buf, size_t size)
{
double old_period = he->stat.period;
double new_period = pair->stat.period;
return scnprintf(buf, size, "%.0F / %.0F", new_period, old_period);
}
static int formula_wdiff(struct hist_entry *he, struct hist_entry *pair,
char *buf, size_t size)
{
u64 old_period = he->stat.period;
u64 new_period = pair->stat.period;
return scnprintf(buf, size,
"(%" PRIu64 " * " "%" PRId64 ") - (%" PRIu64 " * " "%" PRId64 ")",
new_period, compute_wdiff_w2, old_period, compute_wdiff_w1);
}
static int formula_fprintf(struct hist_entry *he, struct hist_entry *pair,
char *buf, size_t size)
{
switch (compute) {
case COMPUTE_DELTA:
return formula_delta(he, pair, buf, size);
case COMPUTE_RATIO:
return formula_ratio(he, pair, buf, size);
case COMPUTE_WEIGHTED_DIFF:
return formula_wdiff(he, pair, buf, size);
default:
BUG_ON(1);
}
return -1;
}
static int hists__add_entry(struct hists *hists,
struct addr_location *al, u64 period,
u64 weight, u64 transaction)
{
if (__hists__add_entry(hists, al, NULL, NULL, NULL, period, weight,
transaction, true) != NULL)
return 0;
return -ENOMEM;
}
static int diff__process_sample_event(struct perf_tool *tool __maybe_unused,
union perf_event *event,
struct perf_sample *sample,
struct perf_evsel *evsel,
struct machine *machine)
{
struct addr_location al;
struct hists *hists = evsel__hists(evsel);
int ret = -1;
if (perf_event__preprocess_sample(event, machine, &al, sample) < 0) {
pr_warning("problem processing %d event, skipping it.\n",
event->header.type);
return -1;
}
if (hists__add_entry(hists, &al, sample->period,
sample->weight, sample->transaction)) {
pr_warning("problem incrementing symbol period, skipping event\n");
goto out_put;
}
hists->stats.total_period += sample->period;
if (!al.filtered)
hists->stats.total_non_filtered_period += sample->period;
ret = 0;
out_put:
addr_location__put(&al);
return ret;
}
static struct perf_evsel *evsel_match(struct perf_evsel *evsel,
struct perf_evlist *evlist)
{
struct perf_evsel *e;
evlist__for_each(evlist, e) {
if (perf_evsel__match2(evsel, e))
return e;
}
return NULL;
}
static void perf_evlist__collapse_resort(struct perf_evlist *evlist)
{
struct perf_evsel *evsel;
evlist__for_each(evlist, evsel) {
struct hists *hists = evsel__hists(evsel);
hists__collapse_resort(hists, NULL);
}
}
static struct data__file *fmt_to_data_file(struct perf_hpp_fmt *fmt)
{
struct diff_hpp_fmt *dfmt = container_of(fmt, struct diff_hpp_fmt, fmt);
void *ptr = dfmt - dfmt->idx;
struct data__file *d = container_of(ptr, struct data__file, fmt);
return d;
}
static struct hist_entry*
get_pair_data(struct hist_entry *he, struct data__file *d)
{
if (hist_entry__has_pairs(he)) {
struct hist_entry *pair;
list_for_each_entry(pair, &he->pairs.head, pairs.node)
if (pair->hists == d->hists)
return pair;
}
return NULL;
}
static struct hist_entry*
get_pair_fmt(struct hist_entry *he, struct diff_hpp_fmt *dfmt)
{
struct data__file *d = fmt_to_data_file(&dfmt->fmt);
return get_pair_data(he, d);
}
static void hists__baseline_only(struct hists *hists)
{
struct rb_root *root;
struct rb_node *next;
if (sort__need_collapse)
root = &hists->entries_collapsed;
else
root = hists->entries_in;
next = rb_first(root);
while (next != NULL) {
struct hist_entry *he = rb_entry(next, struct hist_entry, rb_node_in);
next = rb_next(&he->rb_node_in);
if (!hist_entry__next_pair(he)) {
rb_erase(&he->rb_node_in, root);
hist_entry__delete(he);
}
}
}
static void hists__precompute(struct hists *hists)
{
struct rb_root *root;
struct rb_node *next;
if (sort__need_collapse)
root = &hists->entries_collapsed;
else
root = hists->entries_in;
next = rb_first(root);
while (next != NULL) {
struct hist_entry *he, *pair;
struct data__file *d;
int i;
he = rb_entry(next, struct hist_entry, rb_node_in);
next = rb_next(&he->rb_node_in);
data__for_each_file_new(i, d) {
pair = get_pair_data(he, d);
if (!pair)
continue;
switch (compute) {
case COMPUTE_DELTA:
compute_delta(he, pair);
break;
case COMPUTE_RATIO:
compute_ratio(he, pair);
break;
case COMPUTE_WEIGHTED_DIFF:
compute_wdiff(he, pair);
break;
default:
BUG_ON(1);
}
}
}
}
static int64_t cmp_doubles(double l, double r)
{
if (l > r)
return -1;
else if (l < r)
return 1;
else
return 0;
}
static int64_t
__hist_entry__cmp_compute(struct hist_entry *left, struct hist_entry *right,
int c)
{
switch (c) {
case COMPUTE_DELTA:
{
double l = left->diff.period_ratio_delta;
double r = right->diff.period_ratio_delta;
return cmp_doubles(l, r);
}
case COMPUTE_RATIO:
{
double l = left->diff.period_ratio;
double r = right->diff.period_ratio;
return cmp_doubles(l, r);
}
case COMPUTE_WEIGHTED_DIFF:
{
s64 l = left->diff.wdiff;
s64 r = right->diff.wdiff;
return r - l;
}
default:
BUG_ON(1);
}
return 0;
}
static int64_t
hist_entry__cmp_compute(struct hist_entry *left, struct hist_entry *right,
int c, int sort_idx)
{
bool pairs_left = hist_entry__has_pairs(left);
bool pairs_right = hist_entry__has_pairs(right);
struct hist_entry *p_right, *p_left;
if (!pairs_left && !pairs_right)
return 0;
if (!pairs_left || !pairs_right)
return pairs_left ? -1 : 1;
p_left = get_pair_data(left, &data__files[sort_idx]);
p_right = get_pair_data(right, &data__files[sort_idx]);
if (!p_left && !p_right)
return 0;
if (!p_left || !p_right)
return p_left ? -1 : 1;
return __hist_entry__cmp_compute(p_left, p_right, c);
}
static int64_t
hist_entry__cmp_compute_idx(struct hist_entry *left, struct hist_entry *right,
int c, int sort_idx)
{
struct hist_entry *p_right, *p_left;
p_left = get_pair_data(left, &data__files[sort_idx]);
p_right = get_pair_data(right, &data__files[sort_idx]);
if (!p_left && !p_right)
return 0;
if (!p_left || !p_right)
return p_left ? -1 : 1;
if (c != COMPUTE_DELTA) {
if (left->dummy && right->dummy)
return 0;
if (left->dummy || right->dummy)
return left->dummy ? 1 : -1;
}
return __hist_entry__cmp_compute(p_left, p_right, c);
}
static int64_t
hist_entry__cmp_nop(struct perf_hpp_fmt *fmt __maybe_unused,
struct hist_entry *left __maybe_unused,
struct hist_entry *right __maybe_unused)
{
return 0;
}
static int64_t
hist_entry__cmp_baseline(struct perf_hpp_fmt *fmt __maybe_unused,
struct hist_entry *left, struct hist_entry *right)
{
if (left->stat.period == right->stat.period)
return 0;
return left->stat.period > right->stat.period ? 1 : -1;
}
static int64_t
hist_entry__cmp_delta(struct perf_hpp_fmt *fmt,
struct hist_entry *left, struct hist_entry *right)
{
struct data__file *d = fmt_to_data_file(fmt);
return hist_entry__cmp_compute(right, left, COMPUTE_DELTA, d->idx);
}
static int64_t
hist_entry__cmp_ratio(struct perf_hpp_fmt *fmt,
struct hist_entry *left, struct hist_entry *right)
{
struct data__file *d = fmt_to_data_file(fmt);
return hist_entry__cmp_compute(right, left, COMPUTE_RATIO, d->idx);
}
static int64_t
hist_entry__cmp_wdiff(struct perf_hpp_fmt *fmt,
struct hist_entry *left, struct hist_entry *right)
{
struct data__file *d = fmt_to_data_file(fmt);
return hist_entry__cmp_compute(right, left, COMPUTE_WEIGHTED_DIFF, d->idx);
}
static int64_t
hist_entry__cmp_delta_idx(struct perf_hpp_fmt *fmt __maybe_unused,
struct hist_entry *left, struct hist_entry *right)
{
return hist_entry__cmp_compute_idx(right, left, COMPUTE_DELTA,
sort_compute);
}
static int64_t
hist_entry__cmp_ratio_idx(struct perf_hpp_fmt *fmt __maybe_unused,
struct hist_entry *left, struct hist_entry *right)
{
return hist_entry__cmp_compute_idx(right, left, COMPUTE_RATIO,
sort_compute);
}
static int64_t
hist_entry__cmp_wdiff_idx(struct perf_hpp_fmt *fmt __maybe_unused,
struct hist_entry *left, struct hist_entry *right)
{
return hist_entry__cmp_compute_idx(right, left, COMPUTE_WEIGHTED_DIFF,
sort_compute);
}
static void hists__process(struct hists *hists)
{
if (show_baseline_only)
hists__baseline_only(hists);
hists__precompute(hists);
hists__output_resort(hists, NULL);
hists__fprintf(hists, true, 0, 0, 0, stdout);
}
static void data__fprintf(void)
{
struct data__file *d;
int i;
fprintf(stdout, "# Data files:\n");
data__for_each_file(i, d)
fprintf(stdout, "# [%d] %s %s\n",
d->idx, d->file.path,
!d->idx ? "(Baseline)" : "");
fprintf(stdout, "#\n");
}
static void data_process(void)
{
struct perf_evlist *evlist_base = data__files[0].session->evlist;
struct perf_evsel *evsel_base;
bool first = true;
evlist__for_each(evlist_base, evsel_base) {
struct hists *hists_base = evsel__hists(evsel_base);
struct data__file *d;
int i;
data__for_each_file_new(i, d) {
struct perf_evlist *evlist = d->session->evlist;
struct perf_evsel *evsel;
struct hists *hists;
evsel = evsel_match(evsel_base, evlist);
if (!evsel)
continue;
hists = evsel__hists(evsel);
d->hists = hists;
hists__match(hists_base, hists);
if (!show_baseline_only)
hists__link(hists_base, hists);
}
fprintf(stdout, "%s# Event '%s'\n#\n", first ? "" : "\n",
perf_evsel__name(evsel_base));
first = false;
if (verbose || data__files_cnt > 2)
data__fprintf();
perf_evsel__reset_sample_bit(evsel_base, CALLCHAIN);
hists__process(hists_base);
}
}
static void data__free(struct data__file *d)
{
int col;
for (col = 0; col < PERF_HPP_DIFF__MAX_INDEX; col++) {
struct diff_hpp_fmt *fmt = &d->fmt[col];
zfree(&fmt->header);
}
}
static int __cmd_diff(void)
{
struct data__file *d;
int ret = -EINVAL, i;
data__for_each_file(i, d) {
d->session = perf_session__new(&d->file, false, &tool);
if (!d->session) {
pr_err("Failed to open %s\n", d->file.path);
ret = -1;
goto out_delete;
}
ret = perf_session__process_events(d->session);
if (ret) {
pr_err("Failed to process %s\n", d->file.path);
goto out_delete;
}
perf_evlist__collapse_resort(d->session->evlist);
}
data_process();
out_delete:
data__for_each_file(i, d) {
if (d->session)
perf_session__delete(d->session);
data__free(d);
}
free(data__files);
return ret;
}
static double baseline_percent(struct hist_entry *he)
{
u64 total = hists__total_period(he->hists);
return 100.0 * he->stat.period / total;
}
static int hpp__color_baseline(struct perf_hpp_fmt *fmt,
struct perf_hpp *hpp, struct hist_entry *he)
{
struct diff_hpp_fmt *dfmt =
container_of(fmt, struct diff_hpp_fmt, fmt);
double percent = baseline_percent(he);
char pfmt[20] = " ";
if (!he->dummy) {
scnprintf(pfmt, 20, "%%%d.2f%%%%", dfmt->header_width - 1);
return percent_color_snprintf(hpp->buf, hpp->size,
pfmt, percent);
} else
return scnprintf(hpp->buf, hpp->size, "%*s",
dfmt->header_width, pfmt);
}
static int hpp__entry_baseline(struct hist_entry *he, char *buf, size_t size)
{
double percent = baseline_percent(he);
const char *fmt = symbol_conf.field_sep ? "%.2f" : "%6.2f%%";
int ret = 0;
if (!he->dummy)
ret = scnprintf(buf, size, fmt, percent);
return ret;
}
static int __hpp__color_compare(struct perf_hpp_fmt *fmt,
struct perf_hpp *hpp, struct hist_entry *he,
int comparison_method)
{
struct diff_hpp_fmt *dfmt =
container_of(fmt, struct diff_hpp_fmt, fmt);
struct hist_entry *pair = get_pair_fmt(he, dfmt);
double diff;
s64 wdiff;
char pfmt[20] = " ";
if (!pair)
goto no_print;
switch (comparison_method) {
case COMPUTE_DELTA:
if (pair->diff.computed)
diff = pair->diff.period_ratio_delta;
else
diff = compute_delta(he, pair);
scnprintf(pfmt, 20, "%%%+d.2f%%%%", dfmt->header_width - 1);
return percent_color_snprintf(hpp->buf, hpp->size,
pfmt, diff);
case COMPUTE_RATIO:
if (he->dummy)
goto dummy_print;
if (pair->diff.computed)
diff = pair->diff.period_ratio;
else
diff = compute_ratio(he, pair);
scnprintf(pfmt, 20, "%%%d.6f", dfmt->header_width);
return value_color_snprintf(hpp->buf, hpp->size,
pfmt, diff);
case COMPUTE_WEIGHTED_DIFF:
if (he->dummy)
goto dummy_print;
if (pair->diff.computed)
wdiff = pair->diff.wdiff;
else
wdiff = compute_wdiff(he, pair);
scnprintf(pfmt, 20, "%%14ld", dfmt->header_width);
return color_snprintf(hpp->buf, hpp->size,
get_percent_color(wdiff),
pfmt, wdiff);
default:
BUG_ON(1);
}
dummy_print:
return scnprintf(hpp->buf, hpp->size, "%*s",
dfmt->header_width, "N/A");
no_print:
return scnprintf(hpp->buf, hpp->size, "%*s",
dfmt->header_width, pfmt);
}
static int hpp__color_delta(struct perf_hpp_fmt *fmt,
struct perf_hpp *hpp, struct hist_entry *he)
{
return __hpp__color_compare(fmt, hpp, he, COMPUTE_DELTA);
}
static int hpp__color_ratio(struct perf_hpp_fmt *fmt,
struct perf_hpp *hpp, struct hist_entry *he)
{
return __hpp__color_compare(fmt, hpp, he, COMPUTE_RATIO);
}
static int hpp__color_wdiff(struct perf_hpp_fmt *fmt,
struct perf_hpp *hpp, struct hist_entry *he)
{
return __hpp__color_compare(fmt, hpp, he, COMPUTE_WEIGHTED_DIFF);
}
static void
hpp__entry_unpair(struct hist_entry *he, int idx, char *buf, size_t size)
{
switch (idx) {
case PERF_HPP_DIFF__PERIOD_BASELINE:
scnprintf(buf, size, "%" PRIu64, he->stat.period);
break;
default:
break;
}
}
static void
hpp__entry_pair(struct hist_entry *he, struct hist_entry *pair,
int idx, char *buf, size_t size)
{
double diff;
double ratio;
s64 wdiff;
switch (idx) {
case PERF_HPP_DIFF__DELTA:
if (pair->diff.computed)
diff = pair->diff.period_ratio_delta;
else
diff = compute_delta(he, pair);
scnprintf(buf, size, "%+4.2F%%", diff);
break;
case PERF_HPP_DIFF__RATIO:
if (he->dummy) {
scnprintf(buf, size, "N/A");
break;
}
if (pair->diff.computed)
ratio = pair->diff.period_ratio;
else
ratio = compute_ratio(he, pair);
if (ratio > 0.0)
scnprintf(buf, size, "%14.6F", ratio);
break;
case PERF_HPP_DIFF__WEIGHTED_DIFF:
if (he->dummy) {
scnprintf(buf, size, "N/A");
break;
}
if (pair->diff.computed)
wdiff = pair->diff.wdiff;
else
wdiff = compute_wdiff(he, pair);
if (wdiff != 0)
scnprintf(buf, size, "%14ld", wdiff);
break;
case PERF_HPP_DIFF__FORMULA:
formula_fprintf(he, pair, buf, size);
break;
case PERF_HPP_DIFF__PERIOD:
scnprintf(buf, size, "%" PRIu64, pair->stat.period);
break;
default:
BUG_ON(1);
};
}
static void
__hpp__entry_global(struct hist_entry *he, struct diff_hpp_fmt *dfmt,
char *buf, size_t size)
{
struct hist_entry *pair = get_pair_fmt(he, dfmt);
int idx = dfmt->idx;
if (idx == PERF_HPP_DIFF__BASELINE)
hpp__entry_baseline(he, buf, size);
else {
if (pair)
hpp__entry_pair(he, pair, idx, buf, size);
else
hpp__entry_unpair(he, idx, buf, size);
}
}
static int hpp__entry_global(struct perf_hpp_fmt *_fmt, struct perf_hpp *hpp,
struct hist_entry *he)
{
struct diff_hpp_fmt *dfmt =
container_of(_fmt, struct diff_hpp_fmt, fmt);
char buf[MAX_COL_WIDTH] = " ";
__hpp__entry_global(he, dfmt, buf, MAX_COL_WIDTH);
if (symbol_conf.field_sep)
return scnprintf(hpp->buf, hpp->size, "%s", buf);
else
return scnprintf(hpp->buf, hpp->size, "%*s",
dfmt->header_width, buf);
}
static int hpp__header(struct perf_hpp_fmt *fmt, struct perf_hpp *hpp,
struct perf_evsel *evsel __maybe_unused)
{
struct diff_hpp_fmt *dfmt =
container_of(fmt, struct diff_hpp_fmt, fmt);
BUG_ON(!dfmt->header);
return scnprintf(hpp->buf, hpp->size, dfmt->header);
}
static int hpp__width(struct perf_hpp_fmt *fmt,
struct perf_hpp *hpp __maybe_unused,
struct perf_evsel *evsel __maybe_unused)
{
struct diff_hpp_fmt *dfmt =
container_of(fmt, struct diff_hpp_fmt, fmt);
BUG_ON(dfmt->header_width <= 0);
return dfmt->header_width;
}
static void init_header(struct data__file *d, struct diff_hpp_fmt *dfmt)
{
#define MAX_HEADER_NAME 100
char buf_indent[MAX_HEADER_NAME];
char buf[MAX_HEADER_NAME];
const char *header = NULL;
int width = 0;
BUG_ON(dfmt->idx >= PERF_HPP_DIFF__MAX_INDEX);
header = columns[dfmt->idx].name;
width = columns[dfmt->idx].width;
BUG_ON(!header);
if (data__files_cnt > 2)
scnprintf(buf, MAX_HEADER_NAME, "%s/%d", header, d->idx);
#define NAME (data__files_cnt > 2 ? buf : header)
dfmt->header_width = width;
width = (int) strlen(NAME);
if (dfmt->header_width < width)
dfmt->header_width = width;
scnprintf(buf_indent, MAX_HEADER_NAME, "%*s",
dfmt->header_width, NAME);
dfmt->header = strdup(buf_indent);
#undef MAX_HEADER_NAME
#undef NAME
}
static void data__hpp_register(struct data__file *d, int idx)
{
struct diff_hpp_fmt *dfmt = &d->fmt[idx];
struct perf_hpp_fmt *fmt = &dfmt->fmt;
dfmt->idx = idx;
fmt->header = hpp__header;
fmt->width = hpp__width;
fmt->entry = hpp__entry_global;
fmt->cmp = hist_entry__cmp_nop;
fmt->collapse = hist_entry__cmp_nop;
switch (idx) {
case PERF_HPP_DIFF__BASELINE:
fmt->color = hpp__color_baseline;
fmt->sort = hist_entry__cmp_baseline;
break;
case PERF_HPP_DIFF__DELTA:
fmt->color = hpp__color_delta;
fmt->sort = hist_entry__cmp_delta;
break;
case PERF_HPP_DIFF__RATIO:
fmt->color = hpp__color_ratio;
fmt->sort = hist_entry__cmp_ratio;
break;
case PERF_HPP_DIFF__WEIGHTED_DIFF:
fmt->color = hpp__color_wdiff;
fmt->sort = hist_entry__cmp_wdiff;
break;
default:
fmt->sort = hist_entry__cmp_nop;
break;
}
init_header(d, dfmt);
perf_hpp__column_register(fmt);
perf_hpp__register_sort_field(fmt);
}
static int ui_init(void)
{
struct data__file *d;
struct perf_hpp_fmt *fmt;
int i;
data__for_each_file(i, d) {
data__hpp_register(d, i ? compute_2_hpp[compute] :
PERF_HPP_DIFF__BASELINE);
if (show_formula && i)
data__hpp_register(d, PERF_HPP_DIFF__FORMULA);
if (show_period)
data__hpp_register(d, i ? PERF_HPP_DIFF__PERIOD :
PERF_HPP_DIFF__PERIOD_BASELINE);
}
if (!sort_compute)
return 0;
fmt = zalloc(sizeof(*fmt));
if (fmt == NULL) {
pr_err("Memory allocation failed\n");
return -1;
}
fmt->cmp = hist_entry__cmp_nop;
fmt->collapse = hist_entry__cmp_nop;
switch (compute) {
case COMPUTE_DELTA:
fmt->sort = hist_entry__cmp_delta_idx;
break;
case COMPUTE_RATIO:
fmt->sort = hist_entry__cmp_ratio_idx;
break;
case COMPUTE_WEIGHTED_DIFF:
fmt->sort = hist_entry__cmp_wdiff_idx;
break;
default:
BUG_ON(1);
}
list_add(&fmt->sort_list, &perf_hpp__sort_list);
return 0;
}
static int data_init(int argc, const char **argv)
{
struct data__file *d;
static const char *defaults[] = {
"perf.data.old",
"perf.data",
};
bool use_default = true;
int i;
data__files_cnt = 2;
if (argc) {
if (argc == 1)
defaults[1] = argv[0];
else {
data__files_cnt = argc;
use_default = false;
}
} else if (perf_guest) {
defaults[0] = "perf.data.host";
defaults[1] = "perf.data.guest";
}
if (sort_compute >= (unsigned int) data__files_cnt) {
pr_err("Order option out of limit.\n");
return -EINVAL;
}
data__files = zalloc(sizeof(*data__files) * data__files_cnt);
if (!data__files)
return -ENOMEM;
data__for_each_file(i, d) {
struct perf_data_file *file = &d->file;
file->path = use_default ? defaults[i] : argv[i];
file->mode = PERF_DATA_MODE_READ,
file->force = force,
d->idx = i;
}
return 0;
}
int cmd_diff(int argc, const char **argv, const char *prefix __maybe_unused)
{
int ret = hists__init();
if (ret < 0)
return ret;
perf_config(perf_default_config, NULL);
argc = parse_options(argc, argv, options, diff_usage, 0);
if (symbol__init(NULL) < 0)
return -1;
if (data_init(argc, argv) < 0)
return -1;
if (ui_init() < 0)
return -1;
sort__mode = SORT_MODE__DIFF;
if (setup_sorting() < 0)
usage_with_options(diff_usage, options);
setup_pager();
sort__setup_elide(NULL);
return __cmd_diff();
}
