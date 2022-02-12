static int perf_evlist__add_sample(struct perf_evlist *evlist,
struct perf_sample *sample,
struct perf_evsel *evsel,
struct addr_location *al)
{
struct hist_entry *he;
int ret;
if (sym_hist_filter != NULL &&
(al->sym == NULL || strcmp(sym_hist_filter, al->sym->name) != 0)) {
if (al->sym != NULL) {
rb_erase(&al->sym->rb_node,
&al->map->dso->symbols[al->map->type]);
symbol__delete(al->sym);
}
return 0;
}
he = __hists__add_entry(&evsel->hists, al, NULL, 1);
if (he == NULL)
return -ENOMEM;
ret = 0;
if (he->ms.sym != NULL) {
struct annotation *notes = symbol__annotation(he->ms.sym);
if (notes->src == NULL &&
symbol__alloc_hist(he->ms.sym, evlist->nr_entries) < 0)
return -ENOMEM;
ret = hist_entry__inc_addr_samples(he, evsel->idx, al->addr);
}
evsel->hists.stats.total_period += sample->period;
hists__inc_nr_events(&evsel->hists, PERF_RECORD_SAMPLE);
return ret;
}
static int process_sample_event(union perf_event *event,
struct perf_sample *sample,
struct perf_evsel *evsel,
struct perf_session *session)
{
struct addr_location al;
if (perf_event__preprocess_sample(event, session, &al, sample,
symbol__annotate_init) < 0) {
pr_warning("problem processing %d event, skipping it.\n",
event->header.type);
return -1;
}
if (cpu_list && !test_bit(sample->cpu, cpu_bitmap))
return 0;
if (!al.filtered &&
perf_evlist__add_sample(session->evlist, sample, evsel, &al)) {
pr_warning("problem incrementing symbol count, "
"skipping event\n");
return -1;
}
return 0;
}
static int hist_entry__tty_annotate(struct hist_entry *he, int evidx)
{
return symbol__tty_annotate(he->ms.sym, he->ms.map, evidx,
print_line, full_paths, 0, 0);
}
static void hists__find_annotations(struct hists *self, int evidx)
{
struct rb_node *nd = rb_first(&self->entries), *next;
int key = KEY_RIGHT;
while (nd) {
struct hist_entry *he = rb_entry(nd, struct hist_entry, rb_node);
struct annotation *notes;
if (he->ms.sym == NULL || he->ms.map->dso->annotate_warned)
goto find_next;
notes = symbol__annotation(he->ms.sym);
if (notes->src == NULL) {
find_next:
if (key == KEY_LEFT)
nd = rb_prev(nd);
else
nd = rb_next(nd);
continue;
}
if (use_browser > 0) {
key = hist_entry__tui_annotate(he, evidx);
switch (key) {
case KEY_RIGHT:
next = rb_next(nd);
break;
case KEY_LEFT:
next = rb_prev(nd);
break;
default:
return;
}
if (next != NULL)
nd = next;
} else {
hist_entry__tty_annotate(he, evidx);
nd = rb_next(nd);
free(notes->src);
notes->src = NULL;
}
}
}
static int __cmd_annotate(void)
{
int ret;
struct perf_session *session;
struct perf_evsel *pos;
u64 total_nr_samples;
session = perf_session__new(input_name, O_RDONLY, force, false, &event_ops);
if (session == NULL)
return -ENOMEM;
if (cpu_list) {
ret = perf_session__cpu_bitmap(session, cpu_list, cpu_bitmap);
if (ret)
goto out_delete;
}
ret = perf_session__process_events(session, &event_ops);
if (ret)
goto out_delete;
if (dump_trace) {
perf_session__fprintf_nr_events(session, stdout);
goto out_delete;
}
if (verbose > 3)
perf_session__fprintf(session, stdout);
if (verbose > 2)
perf_session__fprintf_dsos(session, stdout);
total_nr_samples = 0;
list_for_each_entry(pos, &session->evlist->entries, node) {
struct hists *hists = &pos->hists;
u32 nr_samples = hists->stats.nr_events[PERF_RECORD_SAMPLE];
if (nr_samples > 0) {
total_nr_samples += nr_samples;
hists__collapse_resort(hists);
hists__output_resort(hists);
hists__find_annotations(hists, pos->idx);
}
}
if (total_nr_samples == 0) {
ui__warning("The %s file has no samples!\n", input_name);
goto out_delete;
}
out_delete:
return ret;
}
int cmd_annotate(int argc, const char **argv, const char *prefix __used)
{
argc = parse_options(argc, argv, options, annotate_usage, 0);
if (use_stdio)
use_browser = 0;
else if (use_tui)
use_browser = 1;
setup_browser(true);
symbol_conf.priv_size = sizeof(struct annotation);
symbol_conf.try_vmlinux_path = true;
if (symbol__init() < 0)
return -1;
setup_sorting(annotate_usage, options);
if (argc) {
if (argc > 1)
usage_with_options(annotate_usage, options);
sym_hist_filter = argv[0];
}
if (field_sep && *field_sep == '.') {
pr_err("'.' is the only non valid --field-separator argument\n");
return -1;
}
return __cmd_annotate();
}
