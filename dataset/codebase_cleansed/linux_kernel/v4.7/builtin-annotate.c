static int perf_evsel__add_sample(struct perf_evsel *evsel,
struct perf_sample *sample,
struct addr_location *al,
struct perf_annotate *ann)
{
struct hists *hists = evsel__hists(evsel);
struct hist_entry *he;
int ret;
if (ann->sym_hist_filter != NULL &&
(al->sym == NULL ||
strcmp(ann->sym_hist_filter, al->sym->name) != 0)) {
if (al->sym != NULL) {
rb_erase(&al->sym->rb_node,
&al->map->dso->symbols[al->map->type]);
symbol__delete(al->sym);
dso__reset_find_symbol_cache(al->map->dso);
}
return 0;
}
sample->period = 1;
sample->weight = 1;
he = __hists__add_entry(hists, al, NULL, NULL, NULL, sample, true);
if (he == NULL)
return -ENOMEM;
ret = hist_entry__inc_addr_samples(he, evsel->idx, al->addr);
hists__inc_nr_samples(hists, true);
return ret;
}
static int process_sample_event(struct perf_tool *tool,
union perf_event *event,
struct perf_sample *sample,
struct perf_evsel *evsel,
struct machine *machine)
{
struct perf_annotate *ann = container_of(tool, struct perf_annotate, tool);
struct addr_location al;
int ret = 0;
if (machine__resolve(machine, &al, sample) < 0) {
pr_warning("problem processing %d event, skipping it.\n",
event->header.type);
return -1;
}
if (ann->cpu_list && !test_bit(sample->cpu, ann->cpu_bitmap))
goto out_put;
if (!al.filtered && perf_evsel__add_sample(evsel, sample, &al, ann)) {
pr_warning("problem incrementing symbol count, "
"skipping event\n");
ret = -1;
}
out_put:
addr_location__put(&al);
return ret;
}
static int hist_entry__tty_annotate(struct hist_entry *he,
struct perf_evsel *evsel,
struct perf_annotate *ann)
{
return symbol__tty_annotate(he->ms.sym, he->ms.map, evsel,
ann->print_line, ann->full_paths, 0, 0);
}
static void hists__find_annotations(struct hists *hists,
struct perf_evsel *evsel,
struct perf_annotate *ann)
{
struct rb_node *nd = rb_first(&hists->entries), *next;
int key = K_RIGHT;
while (nd) {
struct hist_entry *he = rb_entry(nd, struct hist_entry, rb_node);
struct annotation *notes;
if (he->ms.sym == NULL || he->ms.map->dso->annotate_warned)
goto find_next;
notes = symbol__annotation(he->ms.sym);
if (notes->src == NULL) {
find_next:
if (key == K_LEFT)
nd = rb_prev(nd);
else
nd = rb_next(nd);
continue;
}
if (use_browser == 2) {
int ret;
int (*annotate)(struct hist_entry *he,
struct perf_evsel *evsel,
struct hist_browser_timer *hbt);
annotate = dlsym(perf_gtk_handle,
"hist_entry__gtk_annotate");
if (annotate == NULL) {
ui__error("GTK browser not found!\n");
return;
}
ret = annotate(he, evsel, NULL);
if (!ret || !ann->skip_missing)
return;
nd = rb_next(nd);
} else if (use_browser == 1) {
key = hist_entry__tui_annotate(he, evsel, NULL);
switch (key) {
case -1:
if (!ann->skip_missing)
return;
case K_RIGHT:
next = rb_next(nd);
break;
case K_LEFT:
next = rb_prev(nd);
break;
default:
return;
}
if (next != NULL)
nd = next;
} else {
hist_entry__tty_annotate(he, evsel, ann);
nd = rb_next(nd);
zfree(&notes->src->cycles_hist);
zfree(&notes->src);
}
}
}
static int __cmd_annotate(struct perf_annotate *ann)
{
int ret;
struct perf_session *session = ann->session;
struct perf_evsel *pos;
u64 total_nr_samples;
machines__set_symbol_filter(&session->machines, symbol__annotate_init);
if (ann->cpu_list) {
ret = perf_session__cpu_bitmap(session, ann->cpu_list,
ann->cpu_bitmap);
if (ret)
goto out;
}
if (!objdump_path) {
ret = perf_env__lookup_objdump(&session->header.env);
if (ret)
goto out;
}
ret = perf_session__process_events(session);
if (ret)
goto out;
if (dump_trace) {
perf_session__fprintf_nr_events(session, stdout);
perf_evlist__fprintf_nr_events(session->evlist, stdout);
goto out;
}
if (verbose > 3)
perf_session__fprintf(session, stdout);
if (verbose > 2)
perf_session__fprintf_dsos(session, stdout);
total_nr_samples = 0;
evlist__for_each(session->evlist, pos) {
struct hists *hists = evsel__hists(pos);
u32 nr_samples = hists->stats.nr_events[PERF_RECORD_SAMPLE];
if (nr_samples > 0) {
total_nr_samples += nr_samples;
hists__collapse_resort(hists, NULL);
perf_evsel__reset_sample_bit(pos, CALLCHAIN);
perf_evsel__output_resort(pos, NULL);
if (symbol_conf.event_group &&
!perf_evsel__is_group_leader(pos))
continue;
hists__find_annotations(hists, pos, ann);
}
}
if (total_nr_samples == 0) {
ui__error("The %s file has no samples!\n", session->file->path);
goto out;
}
if (use_browser == 2) {
void (*show_annotations)(void);
show_annotations = dlsym(perf_gtk_handle,
"perf_gtk__show_annotations");
if (show_annotations == NULL) {
ui__error("GTK browser not found!\n");
goto out;
}
show_annotations();
}
out:
return ret;
}
int cmd_annotate(int argc, const char **argv, const char *prefix __maybe_unused)
{
struct perf_annotate annotate = {
.tool = {
.sample = process_sample_event,
.mmap = perf_event__process_mmap,
.mmap2 = perf_event__process_mmap2,
.comm = perf_event__process_comm,
.exit = perf_event__process_exit,
.fork = perf_event__process_fork,
.ordered_events = true,
.ordering_requires_timestamps = true,
},
};
struct perf_data_file file = {
.mode = PERF_DATA_MODE_READ,
};
const struct option options[] = {
OPT_STRING('i', "input", &input_name, "file",
"input file name"),
OPT_STRING('d', "dsos", &symbol_conf.dso_list_str, "dso[,dso...]",
"only consider symbols in these dsos"),
OPT_STRING('s', "symbol", &annotate.sym_hist_filter, "symbol",
"symbol to annotate"),
OPT_BOOLEAN('f', "force", &file.force, "don't complain, do it"),
OPT_INCR('v', "verbose", &verbose,
"be more verbose (show symbol address, etc)"),
OPT_BOOLEAN('D', "dump-raw-trace", &dump_trace,
"dump raw trace in ASCII"),
OPT_BOOLEAN(0, "gtk", &annotate.use_gtk, "Use the GTK interface"),
OPT_BOOLEAN(0, "tui", &annotate.use_tui, "Use the TUI interface"),
OPT_BOOLEAN(0, "stdio", &annotate.use_stdio, "Use the stdio interface"),
OPT_STRING('k', "vmlinux", &symbol_conf.vmlinux_name,
"file", "vmlinux pathname"),
OPT_BOOLEAN('m', "modules", &symbol_conf.use_modules,
"load module symbols - WARNING: use only with -k and LIVE kernel"),
OPT_BOOLEAN('l', "print-line", &annotate.print_line,
"print matching source lines (may be slow)"),
OPT_BOOLEAN('P', "full-paths", &annotate.full_paths,
"Don't shorten the displayed pathnames"),
OPT_BOOLEAN(0, "skip-missing", &annotate.skip_missing,
"Skip symbols that cannot be annotated"),
OPT_STRING('C', "cpu", &annotate.cpu_list, "cpu", "list of cpus to profile"),
OPT_CALLBACK(0, "symfs", NULL, "directory",
"Look for files with symbols relative to this directory",
symbol__config_symfs),
OPT_BOOLEAN(0, "source", &symbol_conf.annotate_src,
"Interleave source code with assembly code (default)"),
OPT_BOOLEAN(0, "asm-raw", &symbol_conf.annotate_asm_raw,
"Display raw encoding of assembly instructions (default)"),
OPT_STRING('M', "disassembler-style", &disassembler_style, "disassembler style",
"Specify disassembler style (e.g. -M intel for intel syntax)"),
OPT_STRING(0, "objdump", &objdump_path, "path",
"objdump binary to use for disassembly and annotations"),
OPT_BOOLEAN(0, "group", &symbol_conf.event_group,
"Show event group information together"),
OPT_BOOLEAN(0, "show-total-period", &symbol_conf.show_total_period,
"Show a column with the sum of periods"),
OPT_END()
};
int ret = hists__init();
if (ret < 0)
return ret;
argc = parse_options(argc, argv, options, annotate_usage, 0);
if (argc) {
if (argc > 1)
usage_with_options(annotate_usage, options);
annotate.sym_hist_filter = argv[0];
}
file.path = input_name;
annotate.session = perf_session__new(&file, false, &annotate.tool);
if (annotate.session == NULL)
return -1;
symbol_conf.priv_size = sizeof(struct annotation);
symbol_conf.try_vmlinux_path = true;
ret = symbol__init(&annotate.session->header.env);
if (ret < 0)
goto out_delete;
if (setup_sorting(NULL) < 0)
usage_with_options(annotate_usage, options);
if (annotate.use_stdio)
use_browser = 0;
else if (annotate.use_tui)
use_browser = 1;
else if (annotate.use_gtk)
use_browser = 2;
setup_browser(true);
ret = __cmd_annotate(&annotate);
out_delete:
return ret;
}
