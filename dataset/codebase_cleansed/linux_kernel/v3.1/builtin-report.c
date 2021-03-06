static int perf_session__add_hist_entry(struct perf_session *session,
struct addr_location *al,
struct perf_sample *sample,
struct perf_evsel *evsel)
{
struct symbol *parent = NULL;
int err = 0;
struct hist_entry *he;
if ((sort__has_parent || symbol_conf.use_callchain) && sample->callchain) {
err = perf_session__resolve_callchain(session, al->thread,
sample->callchain, &parent);
if (err)
return err;
}
he = __hists__add_entry(&evsel->hists, al, parent, sample->period);
if (he == NULL)
return -ENOMEM;
if (symbol_conf.use_callchain) {
err = callchain_append(he->callchain, &session->callchain_cursor,
sample->period);
if (err)
return err;
}
if (al->sym != NULL && use_browser > 0) {
struct annotation *notes = symbol__annotation(he->ms.sym);
assert(evsel != NULL);
err = -ENOMEM;
if (notes->src == NULL &&
symbol__alloc_hist(he->ms.sym, session->evlist->nr_entries) < 0)
goto out;
err = hist_entry__inc_addr_samples(he, evsel->idx, al->addr);
}
evsel->hists.stats.total_period += sample->period;
hists__inc_nr_events(&evsel->hists, PERF_RECORD_SAMPLE);
out:
return err;
}
static int process_sample_event(union perf_event *event,
struct perf_sample *sample,
struct perf_evsel *evsel,
struct perf_session *session)
{
struct addr_location al;
if (perf_event__preprocess_sample(event, session, &al, sample,
annotate_init) < 0) {
fprintf(stderr, "problem processing %d event, skipping it.\n",
event->header.type);
return -1;
}
if (al.filtered || (hide_unresolved && al.sym == NULL))
return 0;
if (cpu_list && !test_bit(sample->cpu, cpu_bitmap))
return 0;
if (al.map != NULL)
al.map->dso->hit = 1;
if (perf_session__add_hist_entry(session, &al, sample, evsel)) {
pr_debug("problem incrementing symbol period, skipping event\n");
return -1;
}
return 0;
}
static int process_read_event(union perf_event *event,
struct perf_sample *sample __used,
struct perf_session *session)
{
struct perf_evsel *evsel = perf_evlist__id2evsel(session->evlist,
event->read.id);
if (show_threads) {
const char *name = evsel ? event_name(evsel) : "unknown";
perf_read_values_add_value(&show_threads_values,
event->read.pid, event->read.tid,
event->read.id,
name,
event->read.value);
}
dump_printf(": %d %d %s %" PRIu64 "\n", event->read.pid, event->read.tid,
evsel ? event_name(evsel) : "FAIL",
event->read.value);
return 0;
}
static int perf_session__setup_sample_type(struct perf_session *self)
{
if (!(self->sample_type & PERF_SAMPLE_CALLCHAIN)) {
if (sort__has_parent) {
ui__warning("Selected --sort parent, but no "
"callchain data. Did you call "
"'perf record' without -g?\n");
return -EINVAL;
}
if (symbol_conf.use_callchain) {
ui__warning("Selected -g but no callchain data. Did "
"you call 'perf record' without -g?\n");
return -1;
}
} else if (!dont_use_callchains && callchain_param.mode != CHAIN_NONE &&
!symbol_conf.use_callchain) {
symbol_conf.use_callchain = true;
if (callchain_register_param(&callchain_param) < 0) {
ui__warning("Can't register callchain "
"params.\n");
return -EINVAL;
}
}
return 0;
}
static void sig_handler(int sig __used)
{
session_done = 1;
}
static size_t hists__fprintf_nr_sample_events(struct hists *self,
const char *evname, FILE *fp)
{
size_t ret;
char unit;
unsigned long nr_events = self->stats.nr_events[PERF_RECORD_SAMPLE];
nr_events = convert_unit(nr_events, &unit);
ret = fprintf(fp, "# Events: %lu%c", nr_events, unit);
if (evname != NULL)
ret += fprintf(fp, " %s", evname);
return ret + fprintf(fp, "\n#\n");
}
static int perf_evlist__tty_browse_hists(struct perf_evlist *evlist,
const char *help)
{
struct perf_evsel *pos;
list_for_each_entry(pos, &evlist->entries, node) {
struct hists *hists = &pos->hists;
const char *evname = NULL;
if (rb_first(&hists->entries) != rb_last(&hists->entries))
evname = event_name(pos);
hists__fprintf_nr_sample_events(hists, evname, stdout);
hists__fprintf(hists, NULL, false, stdout);
fprintf(stdout, "\n\n");
}
if (sort_order == default_sort_order &&
parent_pattern == default_parent_pattern) {
fprintf(stdout, "#\n# (%s)\n#\n", help);
if (show_threads) {
bool style = !strcmp(pretty_printing_style, "raw");
perf_read_values_display(stdout, &show_threads_values,
style);
perf_read_values_destroy(&show_threads_values);
}
}
return 0;
}
static int __cmd_report(void)
{
int ret = -EINVAL;
u64 nr_samples;
struct perf_session *session;
struct perf_evsel *pos;
struct map *kernel_map;
struct kmap *kernel_kmap;
const char *help = "For a higher level overview, try: perf report --sort comm,dso";
signal(SIGINT, sig_handler);
session = perf_session__new(input_name, O_RDONLY, force, false, &event_ops);
if (session == NULL)
return -ENOMEM;
if (cpu_list) {
ret = perf_session__cpu_bitmap(session, cpu_list, cpu_bitmap);
if (ret)
goto out_delete;
}
if (show_threads)
perf_read_values_init(&show_threads_values);
ret = perf_session__setup_sample_type(session);
if (ret)
goto out_delete;
ret = perf_session__process_events(session, &event_ops);
if (ret)
goto out_delete;
kernel_map = session->host_machine.vmlinux_maps[MAP__FUNCTION];
kernel_kmap = map__kmap(kernel_map);
if (kernel_map == NULL ||
(kernel_map->dso->hit &&
(kernel_kmap->ref_reloc_sym == NULL ||
kernel_kmap->ref_reloc_sym->addr == 0))) {
const struct dso *kdso = kernel_map->dso;
ui__warning(
"Kernel address maps (/proc/{kallsyms,modules}) were restricted.\n\n"
"Check /proc/sys/kernel/kptr_restrict before running 'perf record'.\n\n%s\n\n"
"Samples in kernel modules can't be resolved as well.\n\n",
RB_EMPTY_ROOT(&kdso->symbols[MAP__FUNCTION]) ?
"As no suitable kallsyms nor vmlinux was found, kernel samples\n"
"can't be resolved." :
"If some relocation was applied (e.g. kexec) symbols may be misresolved.");
}
if (dump_trace) {
perf_session__fprintf_nr_events(session, stdout);
goto out_delete;
}
if (verbose > 3)
perf_session__fprintf(session, stdout);
if (verbose > 2)
perf_session__fprintf_dsos(session, stdout);
nr_samples = 0;
list_for_each_entry(pos, &session->evlist->entries, node) {
struct hists *hists = &pos->hists;
hists__collapse_resort(hists);
hists__output_resort(hists);
nr_samples += hists->stats.nr_events[PERF_RECORD_SAMPLE];
}
if (nr_samples == 0) {
ui__warning("The %s file has no samples!\n", input_name);
goto out_delete;
}
if (use_browser > 0)
perf_evlist__tui_browse_hists(session->evlist, help);
else
perf_evlist__tty_browse_hists(session->evlist, help);
out_delete:
return ret;
}
static int
parse_callchain_opt(const struct option *opt __used, const char *arg,
int unset)
{
char *tok, *tok2;
char *endptr;
if (unset) {
dont_use_callchains = true;
return 0;
}
symbol_conf.use_callchain = true;
if (!arg)
return 0;
tok = strtok((char *)arg, ",");
if (!tok)
return -1;
if (!strncmp(tok, "graph", strlen(arg)))
callchain_param.mode = CHAIN_GRAPH_ABS;
else if (!strncmp(tok, "flat", strlen(arg)))
callchain_param.mode = CHAIN_FLAT;
else if (!strncmp(tok, "fractal", strlen(arg)))
callchain_param.mode = CHAIN_GRAPH_REL;
else if (!strncmp(tok, "none", strlen(arg))) {
callchain_param.mode = CHAIN_NONE;
symbol_conf.use_callchain = false;
return 0;
}
else
return -1;
tok = strtok(NULL, ",");
if (!tok)
goto setup;
callchain_param.min_percent = strtod(tok, &endptr);
if (tok == endptr)
return -1;
tok2 = strtok(NULL, ",");
if (!tok2)
goto setup;
if (tok2[0] != 'c') {
callchain_param.print_limit = strtod(tok2, &endptr);
tok2 = strtok(NULL, ",");
if (!tok2)
goto setup;
}
if (!strcmp(tok2, "caller"))
callchain_param.order = ORDER_CALLER;
else if (!strcmp(tok2, "callee"))
callchain_param.order = ORDER_CALLEE;
else
return -1;
setup:
if (callchain_register_param(&callchain_param) < 0) {
fprintf(stderr, "Can't register callchain params\n");
return -1;
}
return 0;
}
int cmd_report(int argc, const char **argv, const char *prefix __used)
{
argc = parse_options(argc, argv, options, report_usage, 0);
if (use_stdio)
use_browser = 0;
else if (use_tui)
use_browser = 1;
if (inverted_callchain)
callchain_param.order = ORDER_CALLER;
if (strcmp(input_name, "-") != 0)
setup_browser(true);
else
use_browser = 0;
if (use_browser > 0) {
symbol_conf.priv_size = sizeof(struct annotation);
annotate_init = symbol__annotate_init;
if (verbose) {
symbol_conf.priv_size += sizeof(u32);
symbol_conf.sort_by_name = true;
}
}
if (symbol__init() < 0)
return -1;
setup_sorting(report_usage, options);
if (parent_pattern != default_parent_pattern) {
if (sort_dimension__add("parent") < 0)
return -1;
if (!strstr(sort_order, "parent"))
sort_parent.elide = 1;
} else
symbol_conf.exclude_other = false;
if (argc)
usage_with_options(report_usage, options);
sort_entry__setup_elide(&sort_dso, symbol_conf.dso_list, "dso", stdout);
sort_entry__setup_elide(&sort_comm, symbol_conf.comm_list, "comm", stdout);
sort_entry__setup_elide(&sort_sym, symbol_conf.sym_list, "symbol", stdout);
return __cmd_report();
}
