int build_id__mark_dso_hit(struct perf_tool *tool __maybe_unused,
union perf_event *event,
struct perf_sample *sample,
struct perf_evsel *evsel __maybe_unused,
struct machine *machine)
{
struct addr_location al;
u8 cpumode = event->header.misc & PERF_RECORD_MISC_CPUMODE_MASK;
struct thread *thread = machine__findnew_thread(machine, sample->pid,
sample->tid);
if (thread == NULL) {
pr_err("problem processing %d event, skipping it.\n",
event->header.type);
return -1;
}
thread__find_addr_map(thread, machine, cpumode, MAP__FUNCTION,
sample->ip, &al);
if (al.map != NULL)
al.map->dso->hit = 1;
return 0;
}
static int perf_event__exit_del_thread(struct perf_tool *tool __maybe_unused,
union perf_event *event,
struct perf_sample *sample
__maybe_unused,
struct machine *machine)
{
struct thread *thread = machine__findnew_thread(machine,
event->fork.pid,
event->fork.tid);
dump_printf("(%d:%d):(%d:%d)\n", event->fork.pid, event->fork.tid,
event->fork.ppid, event->fork.ptid);
if (thread) {
rb_erase(&thread->rb_node, &machine->threads);
machine->last_match = NULL;
thread__delete(thread);
}
return 0;
}
int build_id__sprintf(const u8 *build_id, int len, char *bf)
{
char *bid = bf;
const u8 *raw = build_id;
int i;
for (i = 0; i < len; ++i) {
sprintf(bid, "%02x", *raw);
++raw;
bid += 2;
}
return raw - build_id;
}
char *dso__build_id_filename(const struct dso *dso, char *bf, size_t size)
{
char build_id_hex[BUILD_ID_SIZE * 2 + 1];
if (!dso->has_build_id)
return NULL;
build_id__sprintf(dso->build_id, sizeof(dso->build_id), build_id_hex);
if (bf == NULL) {
if (asprintf(&bf, "%s/.build-id/%.2s/%s", buildid_dir,
build_id_hex, build_id_hex + 2) < 0)
return NULL;
} else
snprintf(bf, size, "%s/.build-id/%.2s/%s", buildid_dir,
build_id_hex, build_id_hex + 2);
return bf;
}
