static int cs_etm_parse_snapshot_options(struct auxtrace_record *itr,
struct record_opts *opts,
const char *str)
{
struct cs_etm_recording *ptr =
container_of(itr, struct cs_etm_recording, itr);
unsigned long long snapshot_size = 0;
char *endptr;
if (str) {
snapshot_size = strtoull(str, &endptr, 0);
if (*endptr || snapshot_size > SIZE_MAX)
return -1;
}
opts->auxtrace_snapshot_mode = true;
opts->auxtrace_snapshot_size = snapshot_size;
ptr->snapshot_size = snapshot_size;
return 0;
}
static int cs_etm_recording_options(struct auxtrace_record *itr,
struct perf_evlist *evlist,
struct record_opts *opts)
{
struct cs_etm_recording *ptr =
container_of(itr, struct cs_etm_recording, itr);
struct perf_pmu *cs_etm_pmu = ptr->cs_etm_pmu;
struct perf_evsel *evsel, *cs_etm_evsel = NULL;
const struct cpu_map *cpus = evlist->cpus;
bool privileged = (geteuid() == 0 || perf_event_paranoid() < 0);
ptr->evlist = evlist;
ptr->snapshot_mode = opts->auxtrace_snapshot_mode;
evlist__for_each_entry(evlist, evsel) {
if (evsel->attr.type == cs_etm_pmu->type) {
if (cs_etm_evsel) {
pr_err("There may be only one %s event\n",
CORESIGHT_ETM_PMU_NAME);
return -EINVAL;
}
evsel->attr.freq = 0;
evsel->attr.sample_period = 1;
cs_etm_evsel = evsel;
opts->full_auxtrace = true;
}
}
if (!cs_etm_evsel)
return 0;
if (opts->use_clockid) {
pr_err("Cannot use clockid (-k option) with %s\n",
CORESIGHT_ETM_PMU_NAME);
return -EINVAL;
}
if (opts->auxtrace_snapshot_mode) {
if (!opts->auxtrace_snapshot_size &&
!opts->auxtrace_mmap_pages) {
if (privileged) {
opts->auxtrace_mmap_pages = MiB(4) / page_size;
} else {
opts->auxtrace_mmap_pages =
KiB(128) / page_size;
if (opts->mmap_pages == UINT_MAX)
opts->mmap_pages = KiB(256) / page_size;
}
} else if (!opts->auxtrace_mmap_pages && !privileged &&
opts->mmap_pages == UINT_MAX) {
opts->mmap_pages = KiB(256) / page_size;
}
if (!opts->auxtrace_snapshot_size) {
opts->auxtrace_snapshot_size =
opts->auxtrace_mmap_pages * (size_t)page_size;
}
if (!opts->auxtrace_mmap_pages) {
size_t sz = opts->auxtrace_snapshot_size;
sz = round_up(sz, page_size) / page_size;
opts->auxtrace_mmap_pages = roundup_pow_of_two(sz);
}
if (opts->auxtrace_snapshot_size >
opts->auxtrace_mmap_pages * (size_t)page_size) {
pr_err("Snapshot size %zu must not be greater than AUX area tracing mmap size %zu\n",
opts->auxtrace_snapshot_size,
opts->auxtrace_mmap_pages * (size_t)page_size);
return -EINVAL;
}
if (!opts->auxtrace_snapshot_size ||
!opts->auxtrace_mmap_pages) {
pr_err("Failed to calculate default snapshot size and/or AUX area tracing mmap pages\n");
return -EINVAL;
}
}
if (opts->full_auxtrace && !opts->auxtrace_mmap_pages) {
if (privileged) {
opts->auxtrace_mmap_pages = MiB(4) / page_size;
} else {
opts->auxtrace_mmap_pages = KiB(128) / page_size;
if (opts->mmap_pages == UINT_MAX)
opts->mmap_pages = KiB(256) / page_size;
}
}
if (opts->auxtrace_mmap_pages) {
unsigned int max_page = (KiB(128) / page_size);
size_t sz = opts->auxtrace_mmap_pages * (size_t)page_size;
if (!privileged &&
opts->auxtrace_mmap_pages > max_page) {
opts->auxtrace_mmap_pages = max_page;
pr_err("auxtrace too big, truncating to %d\n",
max_page);
}
if (!is_power_of_2(sz)) {
pr_err("Invalid mmap size for %s: must be a power of 2\n",
CORESIGHT_ETM_PMU_NAME);
return -EINVAL;
}
}
if (opts->auxtrace_snapshot_mode)
pr_debug2("%s snapshot size: %zu\n", CORESIGHT_ETM_PMU_NAME,
opts->auxtrace_snapshot_size);
perf_evlist__to_front(evlist, cs_etm_evsel);
if (!cpu_map__empty(cpus))
perf_evsel__set_sample_bit(cs_etm_evsel, CPU);
if (opts->full_auxtrace) {
struct perf_evsel *tracking_evsel;
int err;
err = parse_events(evlist, "dummy:u", NULL);
if (err)
return err;
tracking_evsel = perf_evlist__last(evlist);
perf_evlist__set_tracking_event(evlist, tracking_evsel);
tracking_evsel->attr.freq = 0;
tracking_evsel->attr.sample_period = 1;
if (!cpu_map__empty(cpus))
perf_evsel__set_sample_bit(tracking_evsel, TIME);
}
return 0;
}
static u64 cs_etm_get_config(struct auxtrace_record *itr)
{
u64 config = 0;
struct cs_etm_recording *ptr =
container_of(itr, struct cs_etm_recording, itr);
struct perf_pmu *cs_etm_pmu = ptr->cs_etm_pmu;
struct perf_evlist *evlist = ptr->evlist;
struct perf_evsel *evsel;
evlist__for_each_entry(evlist, evsel) {
if (evsel->attr.type == cs_etm_pmu->type) {
config = evsel->attr.config;
break;
}
}
return config;
}
static size_t
cs_etm_info_priv_size(struct auxtrace_record *itr __maybe_unused,
struct perf_evlist *evlist __maybe_unused)
{
int i;
int etmv3 = 0, etmv4 = 0;
const struct cpu_map *cpus = evlist->cpus;
if (!cpu_map__empty(cpus)) {
for (i = 0; i < cpu_map__nr(cpus); i++) {
if (cs_etm_is_etmv4(itr, cpus->map[i]))
etmv4++;
else
etmv3++;
}
} else {
for (i = 0; i < cpu__max_cpu(); i++) {
if (cs_etm_is_etmv4(itr, i))
etmv4++;
else
etmv3++;
}
}
return (CS_ETM_HEADER_SIZE +
(etmv4 * CS_ETMV4_PRIV_SIZE) +
(etmv3 * CS_ETMV3_PRIV_SIZE));
}
static bool cs_etm_is_etmv4(struct auxtrace_record *itr, int cpu)
{
bool ret = false;
char path[PATH_MAX];
int scan;
unsigned int val;
struct cs_etm_recording *ptr =
container_of(itr, struct cs_etm_recording, itr);
struct perf_pmu *cs_etm_pmu = ptr->cs_etm_pmu;
snprintf(path, PATH_MAX, "cpu%d/%s",
cpu, metadata_etmv4_ro[CS_ETMV4_TRCIDR0]);
scan = perf_pmu__scan_file(cs_etm_pmu, path, "%x", &val);
if (scan == 1)
ret = true;
return ret;
}
static int cs_etm_get_ro(struct perf_pmu *pmu, int cpu, const char *path)
{
char pmu_path[PATH_MAX];
int scan;
unsigned int val = 0;
snprintf(pmu_path, PATH_MAX, "cpu%d/%s", cpu, path);
scan = perf_pmu__scan_file(pmu, pmu_path, "%x", &val);
if (scan != 1)
pr_err("%s: error reading: %s\n", __func__, pmu_path);
return val;
}
static void cs_etm_get_metadata(int cpu, u32 *offset,
struct auxtrace_record *itr,
struct auxtrace_info_event *info)
{
u32 increment;
u64 magic;
struct cs_etm_recording *ptr =
container_of(itr, struct cs_etm_recording, itr);
struct perf_pmu *cs_etm_pmu = ptr->cs_etm_pmu;
if (cs_etm_is_etmv4(itr, cpu)) {
magic = __perf_cs_etmv4_magic;
info->priv[*offset + CS_ETMV4_TRCCONFIGR] =
cs_etm_get_config(itr);
info->priv[*offset + CS_ETMV4_TRCTRACEIDR] =
coresight_get_trace_id(cpu);
info->priv[*offset + CS_ETMV4_TRCIDR0] =
cs_etm_get_ro(cs_etm_pmu, cpu,
metadata_etmv4_ro[CS_ETMV4_TRCIDR0]);
info->priv[*offset + CS_ETMV4_TRCIDR1] =
cs_etm_get_ro(cs_etm_pmu, cpu,
metadata_etmv4_ro[CS_ETMV4_TRCIDR1]);
info->priv[*offset + CS_ETMV4_TRCIDR2] =
cs_etm_get_ro(cs_etm_pmu, cpu,
metadata_etmv4_ro[CS_ETMV4_TRCIDR2]);
info->priv[*offset + CS_ETMV4_TRCIDR8] =
cs_etm_get_ro(cs_etm_pmu, cpu,
metadata_etmv4_ro[CS_ETMV4_TRCIDR8]);
info->priv[*offset + CS_ETMV4_TRCAUTHSTATUS] =
cs_etm_get_ro(cs_etm_pmu, cpu,
metadata_etmv4_ro
[CS_ETMV4_TRCAUTHSTATUS]);
increment = CS_ETMV4_PRIV_MAX;
} else {
magic = __perf_cs_etmv3_magic;
info->priv[*offset + CS_ETM_ETMCR] = cs_etm_get_config(itr);
info->priv[*offset + CS_ETM_ETMTRACEIDR] =
coresight_get_trace_id(cpu);
info->priv[*offset + CS_ETM_ETMCCER] =
cs_etm_get_ro(cs_etm_pmu, cpu,
metadata_etmv3_ro[CS_ETM_ETMCCER]);
info->priv[*offset + CS_ETM_ETMIDR] =
cs_etm_get_ro(cs_etm_pmu, cpu,
metadata_etmv3_ro[CS_ETM_ETMIDR]);
increment = CS_ETM_PRIV_MAX;
}
info->priv[*offset + CS_ETM_MAGIC] = magic;
info->priv[*offset + CS_ETM_CPU] = cpu;
*offset += increment;
}
static int cs_etm_info_fill(struct auxtrace_record *itr,
struct perf_session *session,
struct auxtrace_info_event *info,
size_t priv_size)
{
int i;
u32 offset;
u64 nr_cpu, type;
const struct cpu_map *cpus = session->evlist->cpus;
struct cs_etm_recording *ptr =
container_of(itr, struct cs_etm_recording, itr);
struct perf_pmu *cs_etm_pmu = ptr->cs_etm_pmu;
if (priv_size != cs_etm_info_priv_size(itr, session->evlist))
return -EINVAL;
if (!session->evlist->nr_mmaps)
return -EINVAL;
nr_cpu = cpu_map__empty(cpus) ? cpu__max_cpu() : cpu_map__nr(cpus);
type = cs_etm_pmu->type;
info->type = PERF_AUXTRACE_CS_ETM;
info->priv[CS_HEADER_VERSION_0] = 0;
info->priv[CS_PMU_TYPE_CPUS] = type << 32;
info->priv[CS_PMU_TYPE_CPUS] |= nr_cpu;
info->priv[CS_ETM_SNAPSHOT] = ptr->snapshot_mode;
offset = CS_ETM_SNAPSHOT + 1;
if (!cpu_map__empty(cpus)) {
for (i = 0; i < cpu_map__nr(cpus) && offset < priv_size; i++)
cs_etm_get_metadata(cpus->map[i], &offset, itr, info);
} else {
for (i = 0; i < cpu__max_cpu(); i++)
cs_etm_get_metadata(i, &offset, itr, info);
}
return 0;
}
static int cs_etm_find_snapshot(struct auxtrace_record *itr __maybe_unused,
int idx, struct auxtrace_mmap *mm,
unsigned char *data __maybe_unused,
u64 *head, u64 *old)
{
pr_debug3("%s: mmap index %d old head %zu new head %zu size %zu\n",
__func__, idx, (size_t)*old, (size_t)*head, mm->len);
*old = *head;
*head += mm->len;
return 0;
}
static int cs_etm_snapshot_start(struct auxtrace_record *itr)
{
struct cs_etm_recording *ptr =
container_of(itr, struct cs_etm_recording, itr);
struct perf_evsel *evsel;
evlist__for_each_entry(ptr->evlist, evsel) {
if (evsel->attr.type == ptr->cs_etm_pmu->type)
return perf_evsel__disable(evsel);
}
return -EINVAL;
}
static int cs_etm_snapshot_finish(struct auxtrace_record *itr)
{
struct cs_etm_recording *ptr =
container_of(itr, struct cs_etm_recording, itr);
struct perf_evsel *evsel;
evlist__for_each_entry(ptr->evlist, evsel) {
if (evsel->attr.type == ptr->cs_etm_pmu->type)
return perf_evsel__enable(evsel);
}
return -EINVAL;
}
static u64 cs_etm_reference(struct auxtrace_record *itr __maybe_unused)
{
return (((u64) rand() << 0) & 0x00000000FFFFFFFFull) |
(((u64) rand() << 32) & 0xFFFFFFFF00000000ull);
}
static void cs_etm_recording_free(struct auxtrace_record *itr)
{
struct cs_etm_recording *ptr =
container_of(itr, struct cs_etm_recording, itr);
free(ptr);
}
static int cs_etm_read_finish(struct auxtrace_record *itr, int idx)
{
struct cs_etm_recording *ptr =
container_of(itr, struct cs_etm_recording, itr);
struct perf_evsel *evsel;
evlist__for_each_entry(ptr->evlist, evsel) {
if (evsel->attr.type == ptr->cs_etm_pmu->type)
return perf_evlist__enable_event_idx(ptr->evlist,
evsel, idx);
}
return -EINVAL;
}
struct auxtrace_record *cs_etm_record_init(int *err)
{
struct perf_pmu *cs_etm_pmu;
struct cs_etm_recording *ptr;
cs_etm_pmu = perf_pmu__find(CORESIGHT_ETM_PMU_NAME);
if (!cs_etm_pmu) {
*err = -EINVAL;
goto out;
}
ptr = zalloc(sizeof(struct cs_etm_recording));
if (!ptr) {
*err = -ENOMEM;
goto out;
}
ptr->cs_etm_pmu = cs_etm_pmu;
ptr->itr.parse_snapshot_options = cs_etm_parse_snapshot_options;
ptr->itr.recording_options = cs_etm_recording_options;
ptr->itr.info_priv_size = cs_etm_info_priv_size;
ptr->itr.info_fill = cs_etm_info_fill;
ptr->itr.find_snapshot = cs_etm_find_snapshot;
ptr->itr.snapshot_start = cs_etm_snapshot_start;
ptr->itr.snapshot_finish = cs_etm_snapshot_finish;
ptr->itr.reference = cs_etm_reference;
ptr->itr.free = cs_etm_recording_free;
ptr->itr.read_finish = cs_etm_read_finish;
*err = 0;
return &ptr->itr;
out:
return NULL;
}
static FILE *cs_device__open_file(const char *name)
{
struct stat st;
char path[PATH_MAX];
const char *sysfs;
sysfs = sysfs__mountpoint();
if (!sysfs)
return NULL;
snprintf(path, PATH_MAX,
"%s" CS_BUS_DEVICE_PATH "%s", sysfs, name);
if (stat(path, &st) < 0)
return NULL;
return fopen(path, "w");
}
int cs_etm_set_drv_config(struct perf_evsel_config_term *term)
{
int ret;
char enable_sink[ENABLE_SINK_MAX];
snprintf(enable_sink, ENABLE_SINK_MAX, "%s/%s",
term->val.drv_cfg, "enable_sink");
ret = cs_device__print_file(enable_sink, "%d", 1);
if (ret < 0)
return ret;
return 0;
}
