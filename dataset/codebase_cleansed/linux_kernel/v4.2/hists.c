static bool hist_browser__has_filter(struct hist_browser *hb)
{
return hists__has_filter(hb->hists) || hb->min_pcnt || symbol_conf.has_filter;
}
static int hist_browser__get_folding(struct hist_browser *browser)
{
struct rb_node *nd;
struct hists *hists = browser->hists;
int unfolded_rows = 0;
for (nd = rb_first(&hists->entries);
(nd = hists__filter_entries(nd, browser->min_pcnt)) != NULL;
nd = rb_next(nd)) {
struct hist_entry *he =
rb_entry(nd, struct hist_entry, rb_node);
if (he->unfolded)
unfolded_rows += he->nr_rows;
}
return unfolded_rows;
}
static u32 hist_browser__nr_entries(struct hist_browser *hb)
{
u32 nr_entries;
if (hist_browser__has_filter(hb))
nr_entries = hb->nr_non_filtered_entries;
else
nr_entries = hb->hists->nr_entries;
hb->nr_callchain_rows = hist_browser__get_folding(hb);
return nr_entries + hb->nr_callchain_rows;
}
static void hist_browser__update_rows(struct hist_browser *hb)
{
struct ui_browser *browser = &hb->b;
u16 header_offset = hb->show_headers ? 1 : 0, index_row;
browser->rows = browser->height - header_offset;
index_row = browser->index - browser->top_idx;
if (index_row >= browser->rows)
browser->index -= index_row - browser->rows + 1;
}
static void hist_browser__refresh_dimensions(struct ui_browser *browser)
{
struct hist_browser *hb = container_of(browser, struct hist_browser, b);
browser->width = 3 + (hists__sort_list_width(hb->hists) + sizeof("[k]"));
ui_browser__refresh_dimensions(browser);
hist_browser__update_rows(hb);
}
static void hist_browser__gotorc(struct hist_browser *browser, int row, int column)
{
u16 header_offset = browser->show_headers ? 1 : 0;
ui_browser__gotorc(&browser->b, row + header_offset, column);
}
static void hist_browser__reset(struct hist_browser *browser)
{
browser->nr_callchain_rows = 0;
hist_browser__update_nr_entries(browser);
browser->b.nr_entries = hist_browser__nr_entries(browser);
hist_browser__refresh_dimensions(&browser->b);
ui_browser__reset_index(&browser->b);
}
static char tree__folded_sign(bool unfolded)
{
return unfolded ? '-' : '+';
}
static char hist_entry__folded(const struct hist_entry *he)
{
return he->has_children ? tree__folded_sign(he->unfolded) : ' ';
}
static char callchain_list__folded(const struct callchain_list *cl)
{
return cl->has_children ? tree__folded_sign(cl->unfolded) : ' ';
}
static void callchain_list__set_folding(struct callchain_list *cl, bool unfold)
{
cl->unfolded = unfold ? cl->has_children : false;
}
static int callchain_node__count_rows_rb_tree(struct callchain_node *node)
{
int n = 0;
struct rb_node *nd;
for (nd = rb_first(&node->rb_root); nd; nd = rb_next(nd)) {
struct callchain_node *child = rb_entry(nd, struct callchain_node, rb_node);
struct callchain_list *chain;
char folded_sign = ' ';
list_for_each_entry(chain, &child->val, list) {
++n;
folded_sign = callchain_list__folded(chain);
if (folded_sign == '+')
break;
}
if (folded_sign == '-')
n += callchain_node__count_rows_rb_tree(child);
}
return n;
}
static int callchain_node__count_rows(struct callchain_node *node)
{
struct callchain_list *chain;
bool unfolded = false;
int n = 0;
list_for_each_entry(chain, &node->val, list) {
++n;
unfolded = chain->unfolded;
}
if (unfolded)
n += callchain_node__count_rows_rb_tree(node);
return n;
}
static int callchain__count_rows(struct rb_root *chain)
{
struct rb_node *nd;
int n = 0;
for (nd = rb_first(chain); nd; nd = rb_next(nd)) {
struct callchain_node *node = rb_entry(nd, struct callchain_node, rb_node);
n += callchain_node__count_rows(node);
}
return n;
}
static bool hist_entry__toggle_fold(struct hist_entry *he)
{
if (!he)
return false;
if (!he->has_children)
return false;
he->unfolded = !he->unfolded;
return true;
}
static bool callchain_list__toggle_fold(struct callchain_list *cl)
{
if (!cl)
return false;
if (!cl->has_children)
return false;
cl->unfolded = !cl->unfolded;
return true;
}
static void callchain_node__init_have_children_rb_tree(struct callchain_node *node)
{
struct rb_node *nd = rb_first(&node->rb_root);
for (nd = rb_first(&node->rb_root); nd; nd = rb_next(nd)) {
struct callchain_node *child = rb_entry(nd, struct callchain_node, rb_node);
struct callchain_list *chain;
bool first = true;
list_for_each_entry(chain, &child->val, list) {
if (first) {
first = false;
chain->has_children = chain->list.next != &child->val ||
!RB_EMPTY_ROOT(&child->rb_root);
} else
chain->has_children = chain->list.next == &child->val &&
!RB_EMPTY_ROOT(&child->rb_root);
}
callchain_node__init_have_children_rb_tree(child);
}
}
static void callchain_node__init_have_children(struct callchain_node *node,
bool has_sibling)
{
struct callchain_list *chain;
chain = list_entry(node->val.next, struct callchain_list, list);
chain->has_children = has_sibling;
if (!list_empty(&node->val)) {
chain = list_entry(node->val.prev, struct callchain_list, list);
chain->has_children = !RB_EMPTY_ROOT(&node->rb_root);
}
callchain_node__init_have_children_rb_tree(node);
}
static void callchain__init_have_children(struct rb_root *root)
{
struct rb_node *nd = rb_first(root);
bool has_sibling = nd && rb_next(nd);
for (nd = rb_first(root); nd; nd = rb_next(nd)) {
struct callchain_node *node = rb_entry(nd, struct callchain_node, rb_node);
callchain_node__init_have_children(node, has_sibling);
}
}
static void hist_entry__init_have_children(struct hist_entry *he)
{
if (!he->init_have_children) {
he->has_children = !RB_EMPTY_ROOT(&he->sorted_chain);
callchain__init_have_children(&he->sorted_chain);
he->init_have_children = true;
}
}
static bool hist_browser__toggle_fold(struct hist_browser *browser)
{
struct hist_entry *he = browser->he_selection;
struct map_symbol *ms = browser->selection;
struct callchain_list *cl = container_of(ms, struct callchain_list, ms);
bool has_children;
if (ms == &he->ms)
has_children = hist_entry__toggle_fold(he);
else
has_children = callchain_list__toggle_fold(cl);
if (has_children) {
hist_entry__init_have_children(he);
browser->b.nr_entries -= he->nr_rows;
browser->nr_callchain_rows -= he->nr_rows;
if (he->unfolded)
he->nr_rows = callchain__count_rows(&he->sorted_chain);
else
he->nr_rows = 0;
browser->b.nr_entries += he->nr_rows;
browser->nr_callchain_rows += he->nr_rows;
return true;
}
return false;
}
static int callchain_node__set_folding_rb_tree(struct callchain_node *node, bool unfold)
{
int n = 0;
struct rb_node *nd;
for (nd = rb_first(&node->rb_root); nd; nd = rb_next(nd)) {
struct callchain_node *child = rb_entry(nd, struct callchain_node, rb_node);
struct callchain_list *chain;
bool has_children = false;
list_for_each_entry(chain, &child->val, list) {
++n;
callchain_list__set_folding(chain, unfold);
has_children = chain->has_children;
}
if (has_children)
n += callchain_node__set_folding_rb_tree(child, unfold);
}
return n;
}
static int callchain_node__set_folding(struct callchain_node *node, bool unfold)
{
struct callchain_list *chain;
bool has_children = false;
int n = 0;
list_for_each_entry(chain, &node->val, list) {
++n;
callchain_list__set_folding(chain, unfold);
has_children = chain->has_children;
}
if (has_children)
n += callchain_node__set_folding_rb_tree(node, unfold);
return n;
}
static int callchain__set_folding(struct rb_root *chain, bool unfold)
{
struct rb_node *nd;
int n = 0;
for (nd = rb_first(chain); nd; nd = rb_next(nd)) {
struct callchain_node *node = rb_entry(nd, struct callchain_node, rb_node);
n += callchain_node__set_folding(node, unfold);
}
return n;
}
static void hist_entry__set_folding(struct hist_entry *he, bool unfold)
{
hist_entry__init_have_children(he);
he->unfolded = unfold ? he->has_children : false;
if (he->has_children) {
int n = callchain__set_folding(&he->sorted_chain, unfold);
he->nr_rows = unfold ? n : 0;
} else
he->nr_rows = 0;
}
static void
__hist_browser__set_folding(struct hist_browser *browser, bool unfold)
{
struct rb_node *nd;
struct hists *hists = browser->hists;
for (nd = rb_first(&hists->entries);
(nd = hists__filter_entries(nd, browser->min_pcnt)) != NULL;
nd = rb_next(nd)) {
struct hist_entry *he = rb_entry(nd, struct hist_entry, rb_node);
hist_entry__set_folding(he, unfold);
browser->nr_callchain_rows += he->nr_rows;
}
}
static void hist_browser__set_folding(struct hist_browser *browser, bool unfold)
{
browser->nr_callchain_rows = 0;
__hist_browser__set_folding(browser, unfold);
browser->b.nr_entries = hist_browser__nr_entries(browser);
ui_browser__reset_index(&browser->b);
}
static void ui_browser__warn_lost_events(struct ui_browser *browser)
{
ui_browser__warning(browser, 4,
"Events are being lost, check IO/CPU overload!\n\n"
"You may want to run 'perf' using a RT scheduler policy:\n\n"
" perf top -r 80\n\n"
"Or reduce the sampling frequency.");
}
static int hist_browser__run(struct hist_browser *browser, const char *help)
{
int key;
char title[160];
struct hist_browser_timer *hbt = browser->hbt;
int delay_secs = hbt ? hbt->refresh : 0;
browser->b.entries = &browser->hists->entries;
browser->b.nr_entries = hist_browser__nr_entries(browser);
hists__browser_title(browser->hists, hbt, title, sizeof(title));
if (ui_browser__show(&browser->b, title, help) < 0)
return -1;
while (1) {
key = ui_browser__run(&browser->b, delay_secs);
switch (key) {
case K_TIMER: {
u64 nr_entries;
hbt->timer(hbt->arg);
if (hist_browser__has_filter(browser))
hist_browser__update_nr_entries(browser);
nr_entries = hist_browser__nr_entries(browser);
ui_browser__update_nr_entries(&browser->b, nr_entries);
if (browser->hists->stats.nr_lost_warned !=
browser->hists->stats.nr_events[PERF_RECORD_LOST]) {
browser->hists->stats.nr_lost_warned =
browser->hists->stats.nr_events[PERF_RECORD_LOST];
ui_browser__warn_lost_events(&browser->b);
}
hists__browser_title(browser->hists,
hbt, title, sizeof(title));
ui_browser__show_title(&browser->b, title);
continue;
}
case 'D': {
static int seq;
struct hist_entry *h = rb_entry(browser->b.top,
struct hist_entry, rb_node);
ui_helpline__pop();
ui_helpline__fpush("%d: nr_ent=(%d,%d), rows=%d, idx=%d, fve: idx=%d, row_off=%d, nrows=%d",
seq++, browser->b.nr_entries,
browser->hists->nr_entries,
browser->b.rows,
browser->b.index,
browser->b.top_idx,
h->row_offset, h->nr_rows);
}
break;
case 'C':
hist_browser__set_folding(browser, false);
break;
case 'E':
hist_browser__set_folding(browser, true);
break;
case 'H':
browser->show_headers = !browser->show_headers;
hist_browser__update_rows(browser);
break;
case K_ENTER:
if (hist_browser__toggle_fold(browser))
break;
default:
goto out;
}
}
out:
ui_browser__hide(&browser->b);
return key;
}
static void hist_browser__show_callchain_entry(struct hist_browser *browser,
struct callchain_list *chain,
const char *str, int offset,
unsigned short row,
struct callchain_print_arg *arg)
{
int color, width;
char folded_sign = callchain_list__folded(chain);
bool show_annotated = browser->show_dso && chain->ms.sym && symbol__annotation(chain->ms.sym)->src;
color = HE_COLORSET_NORMAL;
width = browser->b.width - (offset + 2);
if (ui_browser__is_current_entry(&browser->b, row)) {
browser->selection = &chain->ms;
color = HE_COLORSET_SELECTED;
arg->is_current_entry = true;
}
ui_browser__set_color(&browser->b, color);
hist_browser__gotorc(browser, row, 0);
slsmg_write_nstring(" ", offset);
slsmg_printf("%c", folded_sign);
ui_browser__write_graph(&browser->b, show_annotated ? SLSMG_RARROW_CHAR : ' ');
slsmg_write_nstring(str, width);
}
static void hist_browser__fprintf_callchain_entry(struct hist_browser *b __maybe_unused,
struct callchain_list *chain,
const char *str, int offset,
unsigned short row __maybe_unused,
struct callchain_print_arg *arg)
{
char folded_sign = callchain_list__folded(chain);
arg->printed += fprintf(arg->fp, "%*s%c %s\n", offset, " ",
folded_sign, str);
}
static bool hist_browser__check_output_full(struct hist_browser *browser,
unsigned short row)
{
return browser->b.rows == row;
}
static bool hist_browser__check_dump_full(struct hist_browser *browser __maybe_unused,
unsigned short row __maybe_unused)
{
return false;
}
static int hist_browser__show_callchain(struct hist_browser *browser,
struct rb_root *root, int level,
unsigned short row, u64 total,
print_callchain_entry_fn print,
struct callchain_print_arg *arg,
check_output_full_fn is_output_full)
{
struct rb_node *node;
int first_row = row, offset = level * LEVEL_OFFSET_STEP;
u64 new_total;
bool need_percent;
node = rb_first(root);
need_percent = node && rb_next(node);
while (node) {
struct callchain_node *child = rb_entry(node, struct callchain_node, rb_node);
struct rb_node *next = rb_next(node);
u64 cumul = callchain_cumul_hits(child);
struct callchain_list *chain;
char folded_sign = ' ';
int first = true;
int extra_offset = 0;
list_for_each_entry(chain, &child->val, list) {
char bf[1024], *alloc_str;
const char *str;
bool was_first = first;
if (first)
first = false;
else if (need_percent)
extra_offset = LEVEL_OFFSET_STEP;
folded_sign = callchain_list__folded(chain);
if (arg->row_offset != 0) {
arg->row_offset--;
goto do_next;
}
alloc_str = NULL;
str = callchain_list__sym_name(chain, bf, sizeof(bf),
browser->show_dso);
if (was_first && need_percent) {
double percent = cumul * 100.0 / total;
if (asprintf(&alloc_str, "%2.2f%% %s", percent, str) < 0)
str = "Not enough memory!";
else
str = alloc_str;
}
print(browser, chain, str, offset + extra_offset, row, arg);
free(alloc_str);
if (is_output_full(browser, ++row))
goto out;
do_next:
if (folded_sign == '+')
break;
}
if (folded_sign == '-') {
const int new_level = level + (extra_offset ? 2 : 1);
if (callchain_param.mode == CHAIN_GRAPH_REL)
new_total = child->children_hit;
else
new_total = total;
row += hist_browser__show_callchain(browser, &child->rb_root,
new_level, row, new_total,
print, arg, is_output_full);
}
if (is_output_full(browser, row))
break;
node = next;
}
out:
return row - first_row;
}
static int __hpp__slsmg_color_printf(struct perf_hpp *hpp, const char *fmt, ...)
{
struct hpp_arg *arg = hpp->ptr;
int ret, len;
va_list args;
double percent;
va_start(args, fmt);
len = va_arg(args, int);
percent = va_arg(args, double);
va_end(args);
ui_browser__set_percent_color(arg->b, percent, arg->current_entry);
ret = scnprintf(hpp->buf, hpp->size, fmt, len, percent);
slsmg_printf("%s", hpp->buf);
advance_hpp(hpp, ret);
return ret;
}
void hist_browser__init_hpp(void)
{
perf_hpp__format[PERF_HPP__OVERHEAD].color =
hist_browser__hpp_color_overhead;
perf_hpp__format[PERF_HPP__OVERHEAD_SYS].color =
hist_browser__hpp_color_overhead_sys;
perf_hpp__format[PERF_HPP__OVERHEAD_US].color =
hist_browser__hpp_color_overhead_us;
perf_hpp__format[PERF_HPP__OVERHEAD_GUEST_SYS].color =
hist_browser__hpp_color_overhead_guest_sys;
perf_hpp__format[PERF_HPP__OVERHEAD_GUEST_US].color =
hist_browser__hpp_color_overhead_guest_us;
perf_hpp__format[PERF_HPP__OVERHEAD_ACC].color =
hist_browser__hpp_color_overhead_acc;
}
static int hist_browser__show_entry(struct hist_browser *browser,
struct hist_entry *entry,
unsigned short row)
{
char s[256];
int printed = 0;
int width = browser->b.width;
char folded_sign = ' ';
bool current_entry = ui_browser__is_current_entry(&browser->b, row);
off_t row_offset = entry->row_offset;
bool first = true;
struct perf_hpp_fmt *fmt;
if (current_entry) {
browser->he_selection = entry;
browser->selection = &entry->ms;
}
if (symbol_conf.use_callchain) {
hist_entry__init_have_children(entry);
folded_sign = hist_entry__folded(entry);
}
if (row_offset == 0) {
struct hpp_arg arg = {
.b = &browser->b,
.folded_sign = folded_sign,
.current_entry = current_entry,
};
struct perf_hpp hpp = {
.buf = s,
.size = sizeof(s),
.ptr = &arg,
};
hist_browser__gotorc(browser, row, 0);
perf_hpp__for_each_format(fmt) {
if (perf_hpp__should_skip(fmt))
continue;
if (current_entry && browser->b.navkeypressed) {
ui_browser__set_color(&browser->b,
HE_COLORSET_SELECTED);
} else {
ui_browser__set_color(&browser->b,
HE_COLORSET_NORMAL);
}
if (first) {
if (symbol_conf.use_callchain) {
slsmg_printf("%c ", folded_sign);
width -= 2;
}
first = false;
} else {
slsmg_printf(" ");
width -= 2;
}
if (fmt->color) {
width -= fmt->color(fmt, &hpp, entry);
} else {
width -= fmt->entry(fmt, &hpp, entry);
slsmg_printf("%s", s);
}
}
if (!browser->b.navkeypressed)
width += 1;
slsmg_write_nstring("", width);
++row;
++printed;
} else
--row_offset;
if (folded_sign == '-' && row != browser->b.rows) {
u64 total = hists__total_period(entry->hists);
struct callchain_print_arg arg = {
.row_offset = row_offset,
.is_current_entry = current_entry,
};
if (callchain_param.mode == CHAIN_GRAPH_REL) {
if (symbol_conf.cumulate_callchain)
total = entry->stat_acc->period;
else
total = entry->stat.period;
}
printed += hist_browser__show_callchain(browser,
&entry->sorted_chain, 1, row, total,
hist_browser__show_callchain_entry, &arg,
hist_browser__check_output_full);
if (arg.is_current_entry)
browser->he_selection = entry;
}
return printed;
}
static int advance_hpp_check(struct perf_hpp *hpp, int inc)
{
advance_hpp(hpp, inc);
return hpp->size <= 0;
}
static int hists__scnprintf_headers(char *buf, size_t size, struct hists *hists)
{
struct perf_hpp dummy_hpp = {
.buf = buf,
.size = size,
};
struct perf_hpp_fmt *fmt;
size_t ret = 0;
if (symbol_conf.use_callchain) {
ret = scnprintf(buf, size, " ");
if (advance_hpp_check(&dummy_hpp, ret))
return ret;
}
perf_hpp__for_each_format(fmt) {
if (perf_hpp__should_skip(fmt))
continue;
ret = fmt->header(fmt, &dummy_hpp, hists_to_evsel(hists));
if (advance_hpp_check(&dummy_hpp, ret))
break;
ret = scnprintf(dummy_hpp.buf, dummy_hpp.size, " ");
if (advance_hpp_check(&dummy_hpp, ret))
break;
}
return ret;
}
static void hist_browser__show_headers(struct hist_browser *browser)
{
char headers[1024];
hists__scnprintf_headers(headers, sizeof(headers), browser->hists);
ui_browser__gotorc(&browser->b, 0, 0);
ui_browser__set_color(&browser->b, HE_COLORSET_ROOT);
slsmg_write_nstring(headers, browser->b.width + 1);
}
static void ui_browser__hists_init_top(struct ui_browser *browser)
{
if (browser->top == NULL) {
struct hist_browser *hb;
hb = container_of(browser, struct hist_browser, b);
browser->top = rb_first(&hb->hists->entries);
}
}
static unsigned int hist_browser__refresh(struct ui_browser *browser)
{
unsigned row = 0;
u16 header_offset = 0;
struct rb_node *nd;
struct hist_browser *hb = container_of(browser, struct hist_browser, b);
if (hb->show_headers) {
hist_browser__show_headers(hb);
header_offset = 1;
}
ui_browser__hists_init_top(browser);
for (nd = browser->top; nd; nd = rb_next(nd)) {
struct hist_entry *h = rb_entry(nd, struct hist_entry, rb_node);
float percent;
if (h->filtered)
continue;
percent = hist_entry__get_percent_limit(h);
if (percent < hb->min_pcnt)
continue;
row += hist_browser__show_entry(hb, h, row);
if (row == browser->rows)
break;
}
return row + header_offset;
}
static struct rb_node *hists__filter_entries(struct rb_node *nd,
float min_pcnt)
{
while (nd != NULL) {
struct hist_entry *h = rb_entry(nd, struct hist_entry, rb_node);
float percent = hist_entry__get_percent_limit(h);
if (!h->filtered && percent >= min_pcnt)
return nd;
nd = rb_next(nd);
}
return NULL;
}
static struct rb_node *hists__filter_prev_entries(struct rb_node *nd,
float min_pcnt)
{
while (nd != NULL) {
struct hist_entry *h = rb_entry(nd, struct hist_entry, rb_node);
float percent = hist_entry__get_percent_limit(h);
if (!h->filtered && percent >= min_pcnt)
return nd;
nd = rb_prev(nd);
}
return NULL;
}
static void ui_browser__hists_seek(struct ui_browser *browser,
off_t offset, int whence)
{
struct hist_entry *h;
struct rb_node *nd;
bool first = true;
struct hist_browser *hb;
hb = container_of(browser, struct hist_browser, b);
if (browser->nr_entries == 0)
return;
ui_browser__hists_init_top(browser);
switch (whence) {
case SEEK_SET:
nd = hists__filter_entries(rb_first(browser->entries),
hb->min_pcnt);
break;
case SEEK_CUR:
nd = browser->top;
goto do_offset;
case SEEK_END:
nd = hists__filter_prev_entries(rb_last(browser->entries),
hb->min_pcnt);
first = false;
break;
default:
return;
}
h = rb_entry(browser->top, struct hist_entry, rb_node);
h->row_offset = 0;
do_offset:
if (offset > 0) {
do {
h = rb_entry(nd, struct hist_entry, rb_node);
if (h->unfolded) {
u16 remaining = h->nr_rows - h->row_offset;
if (offset > remaining) {
offset -= remaining;
h->row_offset = 0;
} else {
h->row_offset += offset;
offset = 0;
browser->top = nd;
break;
}
}
nd = hists__filter_entries(rb_next(nd), hb->min_pcnt);
if (nd == NULL)
break;
--offset;
browser->top = nd;
} while (offset != 0);
} else if (offset < 0) {
while (1) {
h = rb_entry(nd, struct hist_entry, rb_node);
if (h->unfolded) {
if (first) {
if (-offset > h->row_offset) {
offset += h->row_offset;
h->row_offset = 0;
} else {
h->row_offset += offset;
offset = 0;
browser->top = nd;
break;
}
} else {
if (-offset > h->nr_rows) {
offset += h->nr_rows;
h->row_offset = 0;
} else {
h->row_offset = h->nr_rows + offset;
offset = 0;
browser->top = nd;
break;
}
}
}
nd = hists__filter_prev_entries(rb_prev(nd),
hb->min_pcnt);
if (nd == NULL)
break;
++offset;
browser->top = nd;
if (offset == 0) {
h = rb_entry(nd, struct hist_entry, rb_node);
if (h->unfolded)
h->row_offset = h->nr_rows;
break;
}
first = false;
}
} else {
browser->top = nd;
h = rb_entry(nd, struct hist_entry, rb_node);
h->row_offset = 0;
}
}
static int hist_browser__fprintf_callchain(struct hist_browser *browser,
struct hist_entry *he, FILE *fp)
{
u64 total = hists__total_period(he->hists);
struct callchain_print_arg arg = {
.fp = fp,
};
if (symbol_conf.cumulate_callchain)
total = he->stat_acc->period;
hist_browser__show_callchain(browser, &he->sorted_chain, 1, 0, total,
hist_browser__fprintf_callchain_entry, &arg,
hist_browser__check_dump_full);
return arg.printed;
}
static int hist_browser__fprintf_entry(struct hist_browser *browser,
struct hist_entry *he, FILE *fp)
{
char s[8192];
int printed = 0;
char folded_sign = ' ';
struct perf_hpp hpp = {
.buf = s,
.size = sizeof(s),
};
struct perf_hpp_fmt *fmt;
bool first = true;
int ret;
if (symbol_conf.use_callchain)
folded_sign = hist_entry__folded(he);
if (symbol_conf.use_callchain)
printed += fprintf(fp, "%c ", folded_sign);
perf_hpp__for_each_format(fmt) {
if (perf_hpp__should_skip(fmt))
continue;
if (!first) {
ret = scnprintf(hpp.buf, hpp.size, " ");
advance_hpp(&hpp, ret);
} else
first = false;
ret = fmt->entry(fmt, &hpp, he);
advance_hpp(&hpp, ret);
}
printed += fprintf(fp, "%s\n", rtrim(s));
if (folded_sign == '-')
printed += hist_browser__fprintf_callchain(browser, he, fp);
return printed;
}
static int hist_browser__fprintf(struct hist_browser *browser, FILE *fp)
{
struct rb_node *nd = hists__filter_entries(rb_first(browser->b.entries),
browser->min_pcnt);
int printed = 0;
while (nd) {
struct hist_entry *h = rb_entry(nd, struct hist_entry, rb_node);
printed += hist_browser__fprintf_entry(browser, h, fp);
nd = hists__filter_entries(rb_next(nd), browser->min_pcnt);
}
return printed;
}
static int hist_browser__dump(struct hist_browser *browser)
{
char filename[64];
FILE *fp;
while (1) {
scnprintf(filename, sizeof(filename), "perf.hist.%d", browser->print_seq);
if (access(filename, F_OK))
break;
if (++browser->print_seq == 8192) {
ui_helpline__fpush("Too many perf.hist.N files, nothing written!");
return -1;
}
}
fp = fopen(filename, "w");
if (fp == NULL) {
char bf[64];
const char *err = strerror_r(errno, bf, sizeof(bf));
ui_helpline__fpush("Couldn't write to %s: %s", filename, err);
return -1;
}
++browser->print_seq;
hist_browser__fprintf(browser, fp);
fclose(fp);
ui_helpline__fpush("%s written!", filename);
return 0;
}
static struct hist_browser *hist_browser__new(struct hists *hists,
struct hist_browser_timer *hbt,
struct perf_session_env *env)
{
struct hist_browser *browser = zalloc(sizeof(*browser));
if (browser) {
browser->hists = hists;
browser->b.refresh = hist_browser__refresh;
browser->b.refresh_dimensions = hist_browser__refresh_dimensions;
browser->b.seek = ui_browser__hists_seek;
browser->b.use_navkeypressed = true;
browser->show_headers = symbol_conf.show_hist_headers;
browser->hbt = hbt;
browser->env = env;
}
return browser;
}
static void hist_browser__delete(struct hist_browser *browser)
{
free(browser);
}
static struct hist_entry *hist_browser__selected_entry(struct hist_browser *browser)
{
return browser->he_selection;
}
static struct thread *hist_browser__selected_thread(struct hist_browser *browser)
{
return browser->he_selection->thread;
}
static inline bool is_report_browser(void *timer)
{
return timer == NULL;
}
static int hists__browser_title(struct hists *hists,
struct hist_browser_timer *hbt,
char *bf, size_t size)
{
char unit;
int printed;
const struct dso *dso = hists->dso_filter;
const struct thread *thread = hists->thread_filter;
unsigned long nr_samples = hists->stats.nr_events[PERF_RECORD_SAMPLE];
u64 nr_events = hists->stats.total_period;
struct perf_evsel *evsel = hists_to_evsel(hists);
const char *ev_name = perf_evsel__name(evsel);
char buf[512];
size_t buflen = sizeof(buf);
if (symbol_conf.filter_relative) {
nr_samples = hists->stats.nr_non_filtered_samples;
nr_events = hists->stats.total_non_filtered_period;
}
if (perf_evsel__is_group_event(evsel)) {
struct perf_evsel *pos;
perf_evsel__group_desc(evsel, buf, buflen);
ev_name = buf;
for_each_group_member(pos, evsel) {
struct hists *pos_hists = evsel__hists(pos);
if (symbol_conf.filter_relative) {
nr_samples += pos_hists->stats.nr_non_filtered_samples;
nr_events += pos_hists->stats.total_non_filtered_period;
} else {
nr_samples += pos_hists->stats.nr_events[PERF_RECORD_SAMPLE];
nr_events += pos_hists->stats.total_period;
}
}
}
nr_samples = convert_unit(nr_samples, &unit);
printed = scnprintf(bf, size,
"Samples: %lu%c of event '%s', Event count (approx.): %" PRIu64,
nr_samples, unit, ev_name, nr_events);
if (hists->uid_filter_str)
printed += snprintf(bf + printed, size - printed,
", UID: %s", hists->uid_filter_str);
if (thread)
printed += scnprintf(bf + printed, size - printed,
", Thread: %s(%d)",
(thread->comm_set ? thread__comm_str(thread) : ""),
thread->tid);
if (dso)
printed += scnprintf(bf + printed, size - printed,
", DSO: %s", dso->short_name);
if (!is_report_browser(hbt)) {
struct perf_top *top = hbt->arg;
if (top->zero)
printed += scnprintf(bf + printed, size - printed, " [z]");
}
return printed;
}
static inline void free_popup_options(char **options, int n)
{
int i;
for (i = 0; i < n; ++i)
zfree(&options[i]);
}
static int switch_data_file(void)
{
char *pwd, *options[32], *abs_path[32], *tmp;
DIR *pwd_dir;
int nr_options = 0, choice = -1, ret = -1;
struct dirent *dent;
pwd = getenv("PWD");
if (!pwd)
return ret;
pwd_dir = opendir(pwd);
if (!pwd_dir)
return ret;
memset(options, 0, sizeof(options));
memset(options, 0, sizeof(abs_path));
while ((dent = readdir(pwd_dir))) {
char path[PATH_MAX];
u64 magic;
char *name = dent->d_name;
FILE *file;
if (!(dent->d_type == DT_REG))
continue;
snprintf(path, sizeof(path), "%s/%s", pwd, name);
file = fopen(path, "r");
if (!file)
continue;
if (fread(&magic, 1, 8, file) < 8)
goto close_file_and_continue;
if (is_perf_magic(magic)) {
options[nr_options] = strdup(name);
if (!options[nr_options])
goto close_file_and_continue;
abs_path[nr_options] = strdup(path);
if (!abs_path[nr_options]) {
zfree(&options[nr_options]);
ui__warning("Can't search all data files due to memory shortage.\n");
fclose(file);
break;
}
nr_options++;
}
close_file_and_continue:
fclose(file);
if (nr_options >= 32) {
ui__warning("Too many perf data files in PWD!\n"
"Only the first 32 files will be listed.\n");
break;
}
}
closedir(pwd_dir);
if (nr_options) {
choice = ui__popup_menu(nr_options, options);
if (choice < nr_options && choice >= 0) {
tmp = strdup(abs_path[choice]);
if (tmp) {
if (is_input_name_malloced)
free((void *)input_name);
input_name = tmp;
is_input_name_malloced = true;
ret = 0;
} else
ui__warning("Data switch failed due to memory shortage!\n");
}
}
free_popup_options(options, nr_options);
free_popup_options(abs_path, nr_options);
return ret;
}
static int
do_annotate(struct hist_browser *browser, struct popup_action *act)
{
struct perf_evsel *evsel;
struct annotation *notes;
struct hist_entry *he;
int err;
if (!objdump_path && perf_session_env__lookup_objdump(browser->env))
return 0;
notes = symbol__annotation(act->ms.sym);
if (!notes->src)
return 0;
evsel = hists_to_evsel(browser->hists);
err = map_symbol__tui_annotate(&act->ms, evsel, browser->hbt);
he = hist_browser__selected_entry(browser);
if ((err == 'q' || err == CTRL('c')) && he->branch_info)
return 1;
ui_browser__update_nr_entries(&browser->b, browser->hists->nr_entries);
if (err)
ui_browser__handle_resize(&browser->b);
return 0;
}
static int
add_annotate_opt(struct hist_browser *browser __maybe_unused,
struct popup_action *act, char **optstr,
struct map *map, struct symbol *sym)
{
if (sym == NULL || map->dso->annotate_warned)
return 0;
if (asprintf(optstr, "Annotate %s", sym->name) < 0)
return 0;
act->ms.map = map;
act->ms.sym = sym;
act->fn = do_annotate;
return 1;
}
static int
do_zoom_thread(struct hist_browser *browser, struct popup_action *act)
{
struct thread *thread = act->thread;
if (browser->hists->thread_filter) {
pstack__remove(browser->pstack, &browser->hists->thread_filter);
perf_hpp__set_elide(HISTC_THREAD, false);
thread__zput(browser->hists->thread_filter);
ui_helpline__pop();
} else {
ui_helpline__fpush("To zoom out press <- or -> + \"Zoom out of %s(%d) thread\"",
thread->comm_set ? thread__comm_str(thread) : "",
thread->tid);
browser->hists->thread_filter = thread__get(thread);
perf_hpp__set_elide(HISTC_THREAD, false);
pstack__push(browser->pstack, &browser->hists->thread_filter);
}
hists__filter_by_thread(browser->hists);
hist_browser__reset(browser);
return 0;
}
static int
add_thread_opt(struct hist_browser *browser, struct popup_action *act,
char **optstr, struct thread *thread)
{
if (thread == NULL)
return 0;
if (asprintf(optstr, "Zoom %s %s(%d) thread",
browser->hists->thread_filter ? "out of" : "into",
thread->comm_set ? thread__comm_str(thread) : "",
thread->tid) < 0)
return 0;
act->thread = thread;
act->fn = do_zoom_thread;
return 1;
}
static int
do_zoom_dso(struct hist_browser *browser, struct popup_action *act)
{
struct dso *dso = act->dso;
if (browser->hists->dso_filter) {
pstack__remove(browser->pstack, &browser->hists->dso_filter);
perf_hpp__set_elide(HISTC_DSO, false);
browser->hists->dso_filter = NULL;
ui_helpline__pop();
} else {
if (dso == NULL)
return 0;
ui_helpline__fpush("To zoom out press <- or -> + \"Zoom out of %s DSO\"",
dso->kernel ? "the Kernel" : dso->short_name);
browser->hists->dso_filter = dso;
perf_hpp__set_elide(HISTC_DSO, true);
pstack__push(browser->pstack, &browser->hists->dso_filter);
}
hists__filter_by_dso(browser->hists);
hist_browser__reset(browser);
return 0;
}
static int
add_dso_opt(struct hist_browser *browser, struct popup_action *act,
char **optstr, struct dso *dso)
{
if (dso == NULL)
return 0;
if (asprintf(optstr, "Zoom %s %s DSO",
browser->hists->dso_filter ? "out of" : "into",
dso->kernel ? "the Kernel" : dso->short_name) < 0)
return 0;
act->dso = dso;
act->fn = do_zoom_dso;
return 1;
}
static int
do_browse_map(struct hist_browser *browser __maybe_unused,
struct popup_action *act)
{
map__browse(act->ms.map);
return 0;
}
static int
add_map_opt(struct hist_browser *browser __maybe_unused,
struct popup_action *act, char **optstr, struct map *map)
{
if (map == NULL)
return 0;
if (asprintf(optstr, "Browse map details") < 0)
return 0;
act->ms.map = map;
act->fn = do_browse_map;
return 1;
}
static int
do_run_script(struct hist_browser *browser __maybe_unused,
struct popup_action *act)
{
char script_opt[64];
memset(script_opt, 0, sizeof(script_opt));
if (act->thread) {
scnprintf(script_opt, sizeof(script_opt), " -c %s ",
thread__comm_str(act->thread));
} else if (act->ms.sym) {
scnprintf(script_opt, sizeof(script_opt), " -S %s ",
act->ms.sym->name);
}
script_browse(script_opt);
return 0;
}
static int
add_script_opt(struct hist_browser *browser __maybe_unused,
struct popup_action *act, char **optstr,
struct thread *thread, struct symbol *sym)
{
if (thread) {
if (asprintf(optstr, "Run scripts for samples of thread [%s]",
thread__comm_str(thread)) < 0)
return 0;
} else if (sym) {
if (asprintf(optstr, "Run scripts for samples of symbol [%s]",
sym->name) < 0)
return 0;
} else {
if (asprintf(optstr, "Run scripts for all samples") < 0)
return 0;
}
act->thread = thread;
act->ms.sym = sym;
act->fn = do_run_script;
return 1;
}
static int
do_switch_data(struct hist_browser *browser __maybe_unused,
struct popup_action *act __maybe_unused)
{
if (switch_data_file()) {
ui__warning("Won't switch the data files due to\n"
"no valid data file get selected!\n");
return 0;
}
return K_SWITCH_INPUT_DATA;
}
static int
add_switch_opt(struct hist_browser *browser,
struct popup_action *act, char **optstr)
{
if (!is_report_browser(browser->hbt))
return 0;
if (asprintf(optstr, "Switch to another data file in PWD") < 0)
return 0;
act->fn = do_switch_data;
return 1;
}
static int
do_exit_browser(struct hist_browser *browser __maybe_unused,
struct popup_action *act __maybe_unused)
{
return 0;
}
static int
add_exit_opt(struct hist_browser *browser __maybe_unused,
struct popup_action *act, char **optstr)
{
if (asprintf(optstr, "Exit") < 0)
return 0;
act->fn = do_exit_browser;
return 1;
}
static void hist_browser__update_nr_entries(struct hist_browser *hb)
{
u64 nr_entries = 0;
struct rb_node *nd = rb_first(&hb->hists->entries);
if (hb->min_pcnt == 0) {
hb->nr_non_filtered_entries = hb->hists->nr_non_filtered_entries;
return;
}
while ((nd = hists__filter_entries(nd, hb->min_pcnt)) != NULL) {
nr_entries++;
nd = rb_next(nd);
}
hb->nr_non_filtered_entries = nr_entries;
}
static int perf_evsel__hists_browse(struct perf_evsel *evsel, int nr_events,
const char *helpline,
bool left_exits,
struct hist_browser_timer *hbt,
float min_pcnt,
struct perf_session_env *env)
{
struct hists *hists = evsel__hists(evsel);
struct hist_browser *browser = hist_browser__new(hists, hbt, env);
struct branch_info *bi;
#define MAX_OPTIONS 16
char *options[MAX_OPTIONS];
struct popup_action actions[MAX_OPTIONS];
int nr_options = 0;
int key = -1;
char buf[64];
int delay_secs = hbt ? hbt->refresh : 0;
struct perf_hpp_fmt *fmt;
#define HIST_BROWSER_HELP_COMMON \
"h/?/F1 Show this window\n" \
"UP/DOWN/PGUP\n" \
"PGDN/SPACE Navigate\n" \
"q/ESC/CTRL+C Exit browser\n\n" \
"For multiple event sessions:\n\n" \
"TAB/UNTAB Switch events\n\n" \
"For symbolic views (--sort has sym):\n\n" \
"-> Zoom into DSO/Threads & Annotate current symbol\n" \
"<- Zoom out\n" \
"a Annotate current symbol\n" \
"C Collapse all callchains\n" \
"d Zoom into current DSO\n" \
"E Expand all callchains\n" \
"F Toggle percentage of filtered entries\n" \
"H Display column headers\n" \
const char report_help[] = HIST_BROWSER_HELP_COMMON
"i Show header information\n"
"P Print histograms to perf.hist.N\n"
"r Run available scripts\n"
"s Switch to another data file in PWD\n"
"t Zoom into current Thread\n"
"V Verbose (DSO names in callchains, etc)\n"
"/ Filter symbol by name";
const char top_help[] = HIST_BROWSER_HELP_COMMON
"P Print histograms to perf.hist.N\n"
"t Zoom into current Thread\n"
"V Verbose (DSO names in callchains, etc)\n"
"z Toggle zeroing of samples\n"
"f Enable/Disable events\n"
"/ Filter symbol by name";
if (browser == NULL)
return -1;
SLang_reset_tty();
SLang_init_tty(0, 0, 0);
if (min_pcnt) {
browser->min_pcnt = min_pcnt;
hist_browser__update_nr_entries(browser);
}
browser->pstack = pstack__new(2);
if (browser->pstack == NULL)
goto out;
ui_helpline__push(helpline);
memset(options, 0, sizeof(options));
memset(actions, 0, sizeof(actions));
perf_hpp__for_each_format(fmt)
perf_hpp__reset_width(fmt, hists);
if (symbol_conf.col_width_list_str)
perf_hpp__set_user_width(symbol_conf.col_width_list_str);
while (1) {
struct thread *thread = NULL;
struct dso *dso = NULL;
int choice = 0;
nr_options = 0;
key = hist_browser__run(browser, helpline);
if (browser->he_selection != NULL) {
thread = hist_browser__selected_thread(browser);
dso = browser->selection->map ? browser->selection->map->dso : NULL;
}
switch (key) {
case K_TAB:
case K_UNTAB:
if (nr_events == 1)
continue;
goto out_free_stack;
case 'a':
if (!sort__has_sym) {
ui_browser__warning(&browser->b, delay_secs * 2,
"Annotation is only available for symbolic views, "
"include \"sym*\" in --sort to use it.");
continue;
}
if (browser->selection == NULL ||
browser->selection->sym == NULL ||
browser->selection->map->dso->annotate_warned)
continue;
actions->ms.map = browser->selection->map;
actions->ms.sym = browser->selection->sym;
do_annotate(browser, actions);
continue;
case 'P':
hist_browser__dump(browser);
continue;
case 'd':
actions->dso = dso;
do_zoom_dso(browser, actions);
continue;
case 'V':
browser->show_dso = !browser->show_dso;
continue;
case 't':
actions->thread = thread;
do_zoom_thread(browser, actions);
continue;
case '/':
if (ui_browser__input_window("Symbol to show",
"Please enter the name of symbol you want to see",
buf, "ENTER: OK, ESC: Cancel",
delay_secs * 2) == K_ENTER) {
hists->symbol_filter_str = *buf ? buf : NULL;
hists__filter_by_symbol(hists);
hist_browser__reset(browser);
}
continue;
case 'r':
if (is_report_browser(hbt)) {
actions->thread = NULL;
actions->ms.sym = NULL;
do_run_script(browser, actions);
}
continue;
case 's':
if (is_report_browser(hbt)) {
key = do_switch_data(browser, actions);
if (key == K_SWITCH_INPUT_DATA)
goto out_free_stack;
}
continue;
case 'i':
if (env->arch)
tui__header_window(env);
continue;
case 'F':
symbol_conf.filter_relative ^= 1;
continue;
case 'z':
if (!is_report_browser(hbt)) {
struct perf_top *top = hbt->arg;
top->zero = !top->zero;
}
continue;
case K_F1:
case 'h':
case '?':
ui_browser__help_window(&browser->b,
is_report_browser(hbt) ? report_help : top_help);
continue;
case K_ENTER:
case K_RIGHT:
break;
case K_LEFT: {
const void *top;
if (pstack__empty(browser->pstack)) {
if (left_exits)
goto out_free_stack;
continue;
}
top = pstack__peek(browser->pstack);
if (top == &browser->hists->dso_filter) {
do_zoom_dso(browser, actions);
}
if (top == &browser->hists->thread_filter)
do_zoom_thread(browser, actions);
continue;
}
case K_ESC:
if (!left_exits &&
!ui_browser__dialog_yesno(&browser->b,
"Do you really want to exit?"))
continue;
case 'q':
case CTRL('c'):
goto out_free_stack;
case 'f':
if (!is_report_browser(hbt)) {
struct perf_top *top = hbt->arg;
perf_evlist__toggle_enable(top->evlist);
if (top->evlist->enabled) {
helpline = "Press 'f' to disable the events or 'h' to see other hotkeys";
hbt->refresh = delay_secs;
} else {
helpline = "Press 'f' again to re-enable the events";
hbt->refresh = 0;
}
continue;
}
default:
helpline = "Press '?' for help on key bindings";
continue;
}
if (!sort__has_sym)
goto add_exit_option;
if (browser->selection == NULL)
goto skip_annotation;
if (sort__mode == SORT_MODE__BRANCH) {
bi = browser->he_selection->branch_info;
if (bi == NULL)
goto skip_annotation;
nr_options += add_annotate_opt(browser,
&actions[nr_options],
&options[nr_options],
bi->from.map,
bi->from.sym);
if (bi->to.sym != bi->from.sym)
nr_options += add_annotate_opt(browser,
&actions[nr_options],
&options[nr_options],
bi->to.map,
bi->to.sym);
} else {
nr_options += add_annotate_opt(browser,
&actions[nr_options],
&options[nr_options],
browser->selection->map,
browser->selection->sym);
}
skip_annotation:
nr_options += add_thread_opt(browser, &actions[nr_options],
&options[nr_options], thread);
nr_options += add_dso_opt(browser, &actions[nr_options],
&options[nr_options], dso);
nr_options += add_map_opt(browser, &actions[nr_options],
&options[nr_options],
browser->selection->map);
if (browser->he_selection) {
nr_options += add_script_opt(browser,
&actions[nr_options],
&options[nr_options],
thread, NULL);
nr_options += add_script_opt(browser,
&actions[nr_options],
&options[nr_options],
NULL, browser->selection->sym);
}
nr_options += add_script_opt(browser, &actions[nr_options],
&options[nr_options], NULL, NULL);
nr_options += add_switch_opt(browser, &actions[nr_options],
&options[nr_options]);
add_exit_option:
nr_options += add_exit_opt(browser, &actions[nr_options],
&options[nr_options]);
do {
struct popup_action *act;
choice = ui__popup_menu(nr_options, options);
if (choice == -1 || choice >= nr_options)
break;
act = &actions[choice];
key = act->fn(browser, act);
} while (key == 1);
if (key == K_SWITCH_INPUT_DATA)
break;
}
out_free_stack:
pstack__delete(browser->pstack);
out:
hist_browser__delete(browser);
free_popup_options(options, MAX_OPTIONS);
return key;
}
static void perf_evsel_menu__write(struct ui_browser *browser,
void *entry, int row)
{
struct perf_evsel_menu *menu = container_of(browser,
struct perf_evsel_menu, b);
struct perf_evsel *evsel = list_entry(entry, struct perf_evsel, node);
struct hists *hists = evsel__hists(evsel);
bool current_entry = ui_browser__is_current_entry(browser, row);
unsigned long nr_events = hists->stats.nr_events[PERF_RECORD_SAMPLE];
const char *ev_name = perf_evsel__name(evsel);
char bf[256], unit;
const char *warn = " ";
size_t printed;
ui_browser__set_color(browser, current_entry ? HE_COLORSET_SELECTED :
HE_COLORSET_NORMAL);
if (perf_evsel__is_group_event(evsel)) {
struct perf_evsel *pos;
ev_name = perf_evsel__group_name(evsel);
for_each_group_member(pos, evsel) {
struct hists *pos_hists = evsel__hists(pos);
nr_events += pos_hists->stats.nr_events[PERF_RECORD_SAMPLE];
}
}
nr_events = convert_unit(nr_events, &unit);
printed = scnprintf(bf, sizeof(bf), "%lu%c%s%s", nr_events,
unit, unit == ' ' ? "" : " ", ev_name);
slsmg_printf("%s", bf);
nr_events = hists->stats.nr_events[PERF_RECORD_LOST];
if (nr_events != 0) {
menu->lost_events = true;
if (!current_entry)
ui_browser__set_color(browser, HE_COLORSET_TOP);
nr_events = convert_unit(nr_events, &unit);
printed += scnprintf(bf, sizeof(bf), ": %ld%c%schunks LOST!",
nr_events, unit, unit == ' ' ? "" : " ");
warn = bf;
}
slsmg_write_nstring(warn, browser->width - printed);
if (current_entry)
menu->selection = evsel;
}
static int perf_evsel_menu__run(struct perf_evsel_menu *menu,
int nr_events, const char *help,
struct hist_browser_timer *hbt)
{
struct perf_evlist *evlist = menu->b.priv;
struct perf_evsel *pos;
const char *title = "Available samples";
int delay_secs = hbt ? hbt->refresh : 0;
int key;
if (ui_browser__show(&menu->b, title,
"ESC: exit, ENTER|->: Browse histograms") < 0)
return -1;
while (1) {
key = ui_browser__run(&menu->b, delay_secs);
switch (key) {
case K_TIMER:
hbt->timer(hbt->arg);
if (!menu->lost_events_warned && menu->lost_events) {
ui_browser__warn_lost_events(&menu->b);
menu->lost_events_warned = true;
}
continue;
case K_RIGHT:
case K_ENTER:
if (!menu->selection)
continue;
pos = menu->selection;
browse_hists:
perf_evlist__set_selected(evlist, pos);
if (hbt)
hbt->timer(hbt->arg);
key = perf_evsel__hists_browse(pos, nr_events, help,
true, hbt,
menu->min_pcnt,
menu->env);
ui_browser__show_title(&menu->b, title);
switch (key) {
case K_TAB:
if (pos->node.next == &evlist->entries)
pos = perf_evlist__first(evlist);
else
pos = perf_evsel__next(pos);
goto browse_hists;
case K_UNTAB:
if (pos->node.prev == &evlist->entries)
pos = perf_evlist__last(evlist);
else
pos = perf_evsel__prev(pos);
goto browse_hists;
case K_ESC:
if (!ui_browser__dialog_yesno(&menu->b,
"Do you really want to exit?"))
continue;
case K_SWITCH_INPUT_DATA:
case 'q':
case CTRL('c'):
goto out;
default:
continue;
}
case K_LEFT:
continue;
case K_ESC:
if (!ui_browser__dialog_yesno(&menu->b,
"Do you really want to exit?"))
continue;
case 'q':
case CTRL('c'):
goto out;
default:
continue;
}
}
out:
ui_browser__hide(&menu->b);
return key;
}
static bool filter_group_entries(struct ui_browser *browser __maybe_unused,
void *entry)
{
struct perf_evsel *evsel = list_entry(entry, struct perf_evsel, node);
if (symbol_conf.event_group && !perf_evsel__is_group_leader(evsel))
return true;
return false;
}
static int __perf_evlist__tui_browse_hists(struct perf_evlist *evlist,
int nr_entries, const char *help,
struct hist_browser_timer *hbt,
float min_pcnt,
struct perf_session_env *env)
{
struct perf_evsel *pos;
struct perf_evsel_menu menu = {
.b = {
.entries = &evlist->entries,
.refresh = ui_browser__list_head_refresh,
.seek = ui_browser__list_head_seek,
.write = perf_evsel_menu__write,
.filter = filter_group_entries,
.nr_entries = nr_entries,
.priv = evlist,
},
.min_pcnt = min_pcnt,
.env = env,
};
ui_helpline__push("Press ESC to exit");
evlist__for_each(evlist, pos) {
const char *ev_name = perf_evsel__name(pos);
size_t line_len = strlen(ev_name) + 7;
if (menu.b.width < line_len)
menu.b.width = line_len;
}
return perf_evsel_menu__run(&menu, nr_entries, help, hbt);
}
int perf_evlist__tui_browse_hists(struct perf_evlist *evlist, const char *help,
struct hist_browser_timer *hbt,
float min_pcnt,
struct perf_session_env *env)
{
int nr_entries = evlist->nr_entries;
single_entry:
if (nr_entries == 1) {
struct perf_evsel *first = perf_evlist__first(evlist);
return perf_evsel__hists_browse(first, nr_entries, help,
false, hbt, min_pcnt,
env);
}
if (symbol_conf.event_group) {
struct perf_evsel *pos;
nr_entries = 0;
evlist__for_each(evlist, pos) {
if (perf_evsel__is_group_leader(pos))
nr_entries++;
}
if (nr_entries == 1)
goto single_entry;
}
return __perf_evlist__tui_browse_hists(evlist, nr_entries, help,
hbt, min_pcnt, env);
}
