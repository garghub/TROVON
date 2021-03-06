static int value_set(struct bt_ctf_field_type *type,
struct bt_ctf_event *event,
const char *name, u64 val)
{
struct bt_ctf_field *field;
bool sign = bt_ctf_field_type_integer_get_signed(type);
int ret;
field = bt_ctf_field_create(type);
if (!field) {
pr_err("failed to create a field %s\n", name);
return -1;
}
if (sign) {
ret = bt_ctf_field_signed_integer_set_value(field, val);
if (ret) {
pr_err("failed to set field value %s\n", name);
goto err;
}
} else {
ret = bt_ctf_field_unsigned_integer_set_value(field, val);
if (ret) {
pr_err("failed to set field value %s\n", name);
goto err;
}
}
ret = bt_ctf_event_set_payload(event, name, field);
if (ret) {
pr_err("failed to set payload %s\n", name);
goto err;
}
pr2(" SET [%s = %" PRIu64 "]\n", name, val);
err:
bt_ctf_field_put(field);
return ret;
}
static struct bt_ctf_field_type*
get_tracepoint_field_type(struct ctf_writer *cw, struct format_field *field)
{
unsigned long flags = field->flags;
if (flags & FIELD_IS_STRING)
return cw->data.string;
if (!(flags & FIELD_IS_SIGNED)) {
if (flags & FIELD_IS_LONG || flags & FIELD_IS_POINTER)
return cw->data.u64_hex;
}
if (flags & FIELD_IS_SIGNED) {
if (field->size == 8)
return cw->data.s64;
else
return cw->data.s32;
}
if (field->size == 8)
return cw->data.u64;
else
return cw->data.u32;
}
static unsigned long long adjust_signedness(unsigned long long value_int, int size)
{
unsigned long long value_mask;
switch (size) {
case 1:
value_mask = 0x7fULL;
break;
case 2:
value_mask = 0x7fffULL;
break;
case 4:
value_mask = 0x7fffffffULL;
break;
case 8:
default:
return value_int;
}
if ((value_int & (~0ULL - value_mask)) == 0)
return value_int;
return (value_int & value_mask) | ~value_mask;
}
static int add_tracepoint_field_value(struct ctf_writer *cw,
struct bt_ctf_event_class *event_class,
struct bt_ctf_event *event,
struct perf_sample *sample,
struct format_field *fmtf)
{
struct bt_ctf_field_type *type;
struct bt_ctf_field *array_field;
struct bt_ctf_field *field;
const char *name = fmtf->name;
void *data = sample->raw_data;
unsigned long flags = fmtf->flags;
unsigned int n_items;
unsigned int i;
unsigned int offset;
unsigned int len;
int ret;
name = fmtf->alias;
offset = fmtf->offset;
len = fmtf->size;
if (flags & FIELD_IS_STRING)
flags &= ~FIELD_IS_ARRAY;
if (flags & FIELD_IS_DYNAMIC) {
unsigned long long tmp_val;
tmp_val = pevent_read_number(fmtf->event->pevent,
data + offset, len);
offset = tmp_val;
len = offset >> 16;
offset &= 0xffff;
}
if (flags & FIELD_IS_ARRAY) {
type = bt_ctf_event_class_get_field_by_name(
event_class, name);
array_field = bt_ctf_field_create(type);
bt_ctf_field_type_put(type);
if (!array_field) {
pr_err("Failed to create array type %s\n", name);
return -1;
}
len = fmtf->size / fmtf->arraylen;
n_items = fmtf->arraylen;
} else {
n_items = 1;
array_field = NULL;
}
type = get_tracepoint_field_type(cw, fmtf);
for (i = 0; i < n_items; i++) {
if (flags & FIELD_IS_ARRAY)
field = bt_ctf_field_array_get_field(array_field, i);
else
field = bt_ctf_field_create(type);
if (!field) {
pr_err("failed to create a field %s\n", name);
return -1;
}
if (flags & FIELD_IS_STRING)
ret = bt_ctf_field_string_set_value(field,
data + offset + i * len);
else {
unsigned long long value_int;
value_int = pevent_read_number(
fmtf->event->pevent,
data + offset + i * len, len);
if (!(flags & FIELD_IS_SIGNED))
ret = bt_ctf_field_unsigned_integer_set_value(
field, value_int);
else
ret = bt_ctf_field_signed_integer_set_value(
field, adjust_signedness(value_int, len));
}
if (ret) {
pr_err("failed to set file value %s\n", name);
goto err_put_field;
}
if (!(flags & FIELD_IS_ARRAY)) {
ret = bt_ctf_event_set_payload(event, name, field);
if (ret) {
pr_err("failed to set payload %s\n", name);
goto err_put_field;
}
}
bt_ctf_field_put(field);
}
if (flags & FIELD_IS_ARRAY) {
ret = bt_ctf_event_set_payload(event, name, array_field);
if (ret) {
pr_err("Failed add payload array %s\n", name);
return -1;
}
bt_ctf_field_put(array_field);
}
return 0;
err_put_field:
bt_ctf_field_put(field);
return -1;
}
static int add_tracepoint_fields_values(struct ctf_writer *cw,
struct bt_ctf_event_class *event_class,
struct bt_ctf_event *event,
struct format_field *fields,
struct perf_sample *sample)
{
struct format_field *field;
int ret;
for (field = fields; field; field = field->next) {
ret = add_tracepoint_field_value(cw, event_class, event, sample,
field);
if (ret)
return -1;
}
return 0;
}
static int add_tracepoint_values(struct ctf_writer *cw,
struct bt_ctf_event_class *event_class,
struct bt_ctf_event *event,
struct perf_evsel *evsel,
struct perf_sample *sample)
{
struct format_field *common_fields = evsel->tp_format->format.common_fields;
struct format_field *fields = evsel->tp_format->format.fields;
int ret;
ret = add_tracepoint_fields_values(cw, event_class, event,
common_fields, sample);
if (!ret)
ret = add_tracepoint_fields_values(cw, event_class, event,
fields, sample);
return ret;
}
static int add_generic_values(struct ctf_writer *cw,
struct bt_ctf_event *event,
struct perf_evsel *evsel,
struct perf_sample *sample)
{
u64 type = evsel->attr.sample_type;
int ret;
if (type & PERF_SAMPLE_IP) {
ret = value_set_u64_hex(cw, event, "perf_ip", sample->ip);
if (ret)
return -1;
}
if (type & PERF_SAMPLE_TID) {
ret = value_set_s32(cw, event, "perf_tid", sample->tid);
if (ret)
return -1;
ret = value_set_s32(cw, event, "perf_pid", sample->pid);
if (ret)
return -1;
}
if ((type & PERF_SAMPLE_ID) ||
(type & PERF_SAMPLE_IDENTIFIER)) {
ret = value_set_u64(cw, event, "perf_id", sample->id);
if (ret)
return -1;
}
if (type & PERF_SAMPLE_STREAM_ID) {
ret = value_set_u64(cw, event, "perf_stream_id", sample->stream_id);
if (ret)
return -1;
}
if (type & PERF_SAMPLE_PERIOD) {
ret = value_set_u64(cw, event, "perf_period", sample->period);
if (ret)
return -1;
}
if (type & PERF_SAMPLE_WEIGHT) {
ret = value_set_u64(cw, event, "perf_weight", sample->weight);
if (ret)
return -1;
}
if (type & PERF_SAMPLE_DATA_SRC) {
ret = value_set_u64(cw, event, "perf_data_src",
sample->data_src);
if (ret)
return -1;
}
if (type & PERF_SAMPLE_TRANSACTION) {
ret = value_set_u64(cw, event, "perf_transaction",
sample->transaction);
if (ret)
return -1;
}
return 0;
}
static int ctf_stream__flush(struct ctf_stream *cs)
{
int err = 0;
if (cs) {
err = bt_ctf_stream_flush(cs->stream);
if (err)
pr_err("CTF stream %d flush failed\n", cs->cpu);
pr("Flush stream for cpu %d (%u samples)\n",
cs->cpu, cs->count);
cs->count = 0;
}
return err;
}
static struct ctf_stream *ctf_stream__create(struct ctf_writer *cw, int cpu)
{
struct ctf_stream *cs;
struct bt_ctf_field *pkt_ctx = NULL;
struct bt_ctf_field *cpu_field = NULL;
struct bt_ctf_stream *stream = NULL;
int ret;
cs = zalloc(sizeof(*cs));
if (!cs) {
pr_err("Failed to allocate ctf stream\n");
return NULL;
}
stream = bt_ctf_writer_create_stream(cw->writer, cw->stream_class);
if (!stream) {
pr_err("Failed to create CTF stream\n");
goto out;
}
pkt_ctx = bt_ctf_stream_get_packet_context(stream);
if (!pkt_ctx) {
pr_err("Failed to obtain packet context\n");
goto out;
}
cpu_field = bt_ctf_field_structure_get_field(pkt_ctx, "cpu_id");
bt_ctf_field_put(pkt_ctx);
if (!cpu_field) {
pr_err("Failed to obtain cpu field\n");
goto out;
}
ret = bt_ctf_field_unsigned_integer_set_value(cpu_field, (u32) cpu);
if (ret) {
pr_err("Failed to update CPU number\n");
goto out;
}
bt_ctf_field_put(cpu_field);
cs->cpu = cpu;
cs->stream = stream;
return cs;
out:
if (cpu_field)
bt_ctf_field_put(cpu_field);
if (stream)
bt_ctf_stream_put(stream);
free(cs);
return NULL;
}
static void ctf_stream__delete(struct ctf_stream *cs)
{
if (cs) {
bt_ctf_stream_put(cs->stream);
free(cs);
}
}
static struct ctf_stream *ctf_stream(struct ctf_writer *cw, int cpu)
{
struct ctf_stream *cs = cw->stream[cpu];
if (!cs) {
cs = ctf_stream__create(cw, cpu);
cw->stream[cpu] = cs;
}
return cs;
}
static int get_sample_cpu(struct ctf_writer *cw, struct perf_sample *sample,
struct perf_evsel *evsel)
{
int cpu = 0;
if (evsel->attr.sample_type & PERF_SAMPLE_CPU)
cpu = sample->cpu;
if (cpu > cw->stream_cnt) {
pr_err("Event was recorded for CPU %d, limit is at %d.\n",
cpu, cw->stream_cnt);
cpu = 0;
}
return cpu;
}
static bool is_flush_needed(struct ctf_stream *cs)
{
return cs->count >= STREAM_FLUSH_COUNT;
}
static int process_sample_event(struct perf_tool *tool,
union perf_event *_event __maybe_unused,
struct perf_sample *sample,
struct perf_evsel *evsel,
struct machine *machine __maybe_unused)
{
struct convert *c = container_of(tool, struct convert, tool);
struct evsel_priv *priv = evsel->priv;
struct ctf_writer *cw = &c->writer;
struct ctf_stream *cs;
struct bt_ctf_event_class *event_class;
struct bt_ctf_event *event;
int ret;
if (WARN_ONCE(!priv, "Failed to setup all events.\n"))
return 0;
event_class = priv->event_class;
c->events_count++;
c->events_size += _event->header.size;
pr_time2(sample->time, "sample %" PRIu64 "\n", c->events_count);
event = bt_ctf_event_create(event_class);
if (!event) {
pr_err("Failed to create an CTF event\n");
return -1;
}
bt_ctf_clock_set_time(cw->clock, sample->time);
ret = add_generic_values(cw, event, evsel, sample);
if (ret)
return -1;
if (evsel->attr.type == PERF_TYPE_TRACEPOINT) {
ret = add_tracepoint_values(cw, event_class, event,
evsel, sample);
if (ret)
return -1;
}
cs = ctf_stream(cw, get_sample_cpu(cw, sample, evsel));
if (cs) {
if (is_flush_needed(cs))
ctf_stream__flush(cs);
cs->count++;
bt_ctf_stream_append_event(cs->stream, event);
}
bt_ctf_event_put(event);
return cs ? 0 : -1;
}
static char *change_name(char *name, char *orig_name, int dup)
{
char *new_name = NULL;
size_t len;
if (!name)
name = orig_name;
if (dup >= 10)
goto out;
if (dup < 0)
len = strlen(name) + sizeof("_");
else
len = strlen(orig_name) + sizeof("_dupl_X");
new_name = malloc(len);
if (!new_name)
goto out;
if (dup < 0)
snprintf(new_name, len, "_%s", name);
else
snprintf(new_name, len, "%s_dupl_%d", orig_name, dup);
out:
if (name != orig_name)
free(name);
return new_name;
}
static int event_class_add_field(struct bt_ctf_event_class *event_class,
struct bt_ctf_field_type *type,
struct format_field *field)
{
struct bt_ctf_field_type *t = NULL;
char *name;
int dup = 1;
int ret;
if (field->alias != field->name)
return bt_ctf_event_class_add_field(event_class, type,
(char *)field->alias);
name = field->name;
if (bt_ctf_validate_identifier(name))
name = change_name(name, field->name, -1);
if (!name) {
pr_err("Failed to fix invalid identifier.");
return -1;
}
while ((t = bt_ctf_event_class_get_field_by_name(event_class, name))) {
bt_ctf_field_type_put(t);
name = change_name(name, field->name, dup++);
if (!name) {
pr_err("Failed to create dup name for '%s'\n", field->name);
return -1;
}
}
ret = bt_ctf_event_class_add_field(event_class, type, name);
if (!ret)
field->alias = name;
return ret;
}
static int add_tracepoint_fields_types(struct ctf_writer *cw,
struct format_field *fields,
struct bt_ctf_event_class *event_class)
{
struct format_field *field;
int ret;
for (field = fields; field; field = field->next) {
struct bt_ctf_field_type *type;
unsigned long flags = field->flags;
pr2(" field '%s'\n", field->name);
type = get_tracepoint_field_type(cw, field);
if (!type)
return -1;
if (flags & FIELD_IS_STRING)
flags &= ~FIELD_IS_ARRAY;
if (flags & FIELD_IS_ARRAY)
type = bt_ctf_field_type_array_create(type, field->arraylen);
ret = event_class_add_field(event_class, type, field);
if (flags & FIELD_IS_ARRAY)
bt_ctf_field_type_put(type);
if (ret) {
pr_err("Failed to add field '%s': %d\n",
field->name, ret);
return -1;
}
}
return 0;
}
static int add_tracepoint_types(struct ctf_writer *cw,
struct perf_evsel *evsel,
struct bt_ctf_event_class *class)
{
struct format_field *common_fields = evsel->tp_format->format.common_fields;
struct format_field *fields = evsel->tp_format->format.fields;
int ret;
ret = add_tracepoint_fields_types(cw, common_fields, class);
if (!ret)
ret = add_tracepoint_fields_types(cw, fields, class);
return ret;
}
static int add_generic_types(struct ctf_writer *cw, struct perf_evsel *evsel,
struct bt_ctf_event_class *event_class)
{
u64 type = evsel->attr.sample_type;
#define ADD_FIELD(cl, t, n) \
do { \
pr2(" field '%s'\n", n); \
if (bt_ctf_event_class_add_field(cl, t, n)) { \
pr_err("Failed to add field '%s';\n", n); \
return -1; \
} \
} while (0)
if (type & PERF_SAMPLE_IP)
ADD_FIELD(event_class, cw->data.u64_hex, "perf_ip");
if (type & PERF_SAMPLE_TID) {
ADD_FIELD(event_class, cw->data.s32, "perf_tid");
ADD_FIELD(event_class, cw->data.s32, "perf_pid");
}
if ((type & PERF_SAMPLE_ID) ||
(type & PERF_SAMPLE_IDENTIFIER))
ADD_FIELD(event_class, cw->data.u64, "perf_id");
if (type & PERF_SAMPLE_STREAM_ID)
ADD_FIELD(event_class, cw->data.u64, "perf_stream_id");
if (type & PERF_SAMPLE_PERIOD)
ADD_FIELD(event_class, cw->data.u64, "perf_period");
if (type & PERF_SAMPLE_WEIGHT)
ADD_FIELD(event_class, cw->data.u64, "perf_weight");
if (type & PERF_SAMPLE_DATA_SRC)
ADD_FIELD(event_class, cw->data.u64, "perf_data_src");
if (type & PERF_SAMPLE_TRANSACTION)
ADD_FIELD(event_class, cw->data.u64, "perf_transaction");
#undef ADD_FIELD
return 0;
}
static int add_event(struct ctf_writer *cw, struct perf_evsel *evsel)
{
struct bt_ctf_event_class *event_class;
struct evsel_priv *priv;
const char *name = perf_evsel__name(evsel);
int ret;
pr("Adding event '%s' (type %d)\n", name, evsel->attr.type);
event_class = bt_ctf_event_class_create(name);
if (!event_class)
return -1;
ret = add_generic_types(cw, evsel, event_class);
if (ret)
goto err;
if (evsel->attr.type == PERF_TYPE_TRACEPOINT) {
ret = add_tracepoint_types(cw, evsel, event_class);
if (ret)
goto err;
}
ret = bt_ctf_stream_class_add_event_class(cw->stream_class, event_class);
if (ret) {
pr("Failed to add event class into stream.\n");
goto err;
}
priv = malloc(sizeof(*priv));
if (!priv)
goto err;
priv->event_class = event_class;
evsel->priv = priv;
return 0;
err:
bt_ctf_event_class_put(event_class);
pr_err("Failed to add event '%s'.\n", name);
return -1;
}
static int setup_events(struct ctf_writer *cw, struct perf_session *session)
{
struct perf_evlist *evlist = session->evlist;
struct perf_evsel *evsel;
int ret;
evlist__for_each(evlist, evsel) {
ret = add_event(cw, evsel);
if (ret)
return ret;
}
return 0;
}
static int setup_streams(struct ctf_writer *cw, struct perf_session *session)
{
struct ctf_stream **stream;
struct perf_header *ph = &session->header;
int ncpus;
ncpus = ph->env.nr_cpus_avail ?: MAX_CPUS;
stream = zalloc(sizeof(*stream) * ncpus);
if (!stream) {
pr_err("Failed to allocate streams.\n");
return -ENOMEM;
}
cw->stream = stream;
cw->stream_cnt = ncpus;
return 0;
}
static void free_streams(struct ctf_writer *cw)
{
int cpu;
for (cpu = 0; cpu < cw->stream_cnt; cpu++)
ctf_stream__delete(cw->stream[cpu]);
free(cw->stream);
}
static int ctf_writer__setup_env(struct ctf_writer *cw,
struct perf_session *session)
{
struct perf_header *header = &session->header;
struct bt_ctf_writer *writer = cw->writer;
#define ADD(__n, __v) \
do { \
if (bt_ctf_writer_add_environment_field(writer, __n, __v)) \
return -1; \
} while (0)
ADD("host", header->env.hostname);
ADD("sysname", "Linux");
ADD("release", header->env.os_release);
ADD("version", header->env.version);
ADD("machine", header->env.arch);
ADD("domain", "kernel");
ADD("tracer_name", "perf");
#undef ADD
return 0;
}
static int ctf_writer__setup_clock(struct ctf_writer *cw)
{
struct bt_ctf_clock *clock = cw->clock;
bt_ctf_clock_set_description(clock, "perf clock");
#define SET(__n, __v) \
do { \
if (bt_ctf_clock_set_##__n(clock, __v)) \
return -1; \
} while (0)
SET(frequency, 1000000000);
SET(offset_s, 0);
SET(offset, 0);
SET(precision, 10);
SET(is_absolute, 0);
#undef SET
return 0;
}
static struct bt_ctf_field_type *create_int_type(int size, bool sign, bool hex)
{
struct bt_ctf_field_type *type;
type = bt_ctf_field_type_integer_create(size);
if (!type)
return NULL;
if (sign &&
bt_ctf_field_type_integer_set_signed(type, 1))
goto err;
if (hex &&
bt_ctf_field_type_integer_set_base(type, BT_CTF_INTEGER_BASE_HEXADECIMAL))
goto err;
pr2("Created type: INTEGER %d-bit %ssigned %s\n",
size, sign ? "un" : "", hex ? "hex" : "");
return type;
err:
bt_ctf_field_type_put(type);
return NULL;
}
static void ctf_writer__cleanup_data(struct ctf_writer *cw)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(cw->data.array); i++)
bt_ctf_field_type_put(cw->data.array[i]);
}
static int ctf_writer__init_data(struct ctf_writer *cw)
{
#define CREATE_INT_TYPE(type, size, sign, hex) \
do { \
(type) = create_int_type(size, sign, hex); \
if (!(type)) \
goto err; \
} while (0)
CREATE_INT_TYPE(cw->data.s64, 64, true, false);
CREATE_INT_TYPE(cw->data.u64, 64, false, false);
CREATE_INT_TYPE(cw->data.s32, 32, true, false);
CREATE_INT_TYPE(cw->data.u32, 32, false, false);
CREATE_INT_TYPE(cw->data.u32_hex, 32, false, true);
CREATE_INT_TYPE(cw->data.u64_hex, 64, false, true);
cw->data.string = bt_ctf_field_type_string_create();
if (cw->data.string)
return 0;
err:
ctf_writer__cleanup_data(cw);
pr_err("Failed to create data types.\n");
return -1;
}
static void ctf_writer__cleanup(struct ctf_writer *cw)
{
ctf_writer__cleanup_data(cw);
bt_ctf_clock_put(cw->clock);
free_streams(cw);
bt_ctf_stream_class_put(cw->stream_class);
bt_ctf_writer_put(cw->writer);
memset(cw, 0, sizeof(*cw));
}
static int ctf_writer__init(struct ctf_writer *cw, const char *path)
{
struct bt_ctf_writer *writer;
struct bt_ctf_stream_class *stream_class;
struct bt_ctf_clock *clock;
struct bt_ctf_field_type *pkt_ctx_type;
int ret;
writer = bt_ctf_writer_create(path);
if (!writer)
goto err;
cw->writer = writer;
clock = bt_ctf_clock_create("perf_clock");
if (!clock) {
pr("Failed to create CTF clock.\n");
goto err_cleanup;
}
cw->clock = clock;
if (ctf_writer__setup_clock(cw)) {
pr("Failed to setup CTF clock.\n");
goto err_cleanup;
}
stream_class = bt_ctf_stream_class_create("perf_stream");
if (!stream_class) {
pr("Failed to create CTF stream class.\n");
goto err_cleanup;
}
cw->stream_class = stream_class;
if (bt_ctf_stream_class_set_clock(stream_class, clock)) {
pr("Failed to assign CTF clock to stream class.\n");
goto err_cleanup;
}
if (ctf_writer__init_data(cw))
goto err_cleanup;
pkt_ctx_type = bt_ctf_stream_class_get_packet_context_type(stream_class);
if (!pkt_ctx_type)
goto err_cleanup;
ret = bt_ctf_field_type_structure_add_field(pkt_ctx_type, cw->data.u32, "cpu_id");
bt_ctf_field_type_put(pkt_ctx_type);
if (ret)
goto err_cleanup;
if (bt_ctf_writer_add_clock(writer, clock)) {
pr("Failed to assign CTF clock to writer.\n");
goto err_cleanup;
}
return 0;
err_cleanup:
ctf_writer__cleanup(cw);
err:
pr_err("Failed to setup CTF writer.\n");
return -1;
}
static int ctf_writer__flush_streams(struct ctf_writer *cw)
{
int cpu, ret = 0;
for (cpu = 0; cpu < cw->stream_cnt && !ret; cpu++)
ret = ctf_stream__flush(cw->stream[cpu]);
return ret;
}
static int convert__config(const char *var, const char *value, void *cb)
{
struct convert *c = cb;
if (!strcmp(var, "convert.queue-size")) {
c->queue_size = perf_config_u64(var, value);
return 0;
}
return perf_default_config(var, value, cb);
}
int bt_convert__perf2ctf(const char *input, const char *path, bool force)
{
struct perf_session *session;
struct perf_data_file file = {
.path = input,
.mode = PERF_DATA_MODE_READ,
.force = force,
};
struct convert c = {
.tool = {
.sample = process_sample_event,
.mmap = perf_event__process_mmap,
.mmap2 = perf_event__process_mmap2,
.comm = perf_event__process_comm,
.exit = perf_event__process_exit,
.fork = perf_event__process_fork,
.lost = perf_event__process_lost,
.tracing_data = perf_event__process_tracing_data,
.build_id = perf_event__process_build_id,
.ordered_events = true,
.ordering_requires_timestamps = true,
},
};
struct ctf_writer *cw = &c.writer;
int err = -1;
perf_config(convert__config, &c);
if (ctf_writer__init(cw, path))
return -1;
session = perf_session__new(&file, 0, &c.tool);
if (!session)
goto free_writer;
if (c.queue_size) {
ordered_events__set_alloc_size(&session->ordered_events,
c.queue_size);
}
if (ctf_writer__setup_env(cw, session))
goto free_session;
if (setup_events(cw, session))
goto free_session;
if (setup_streams(cw, session))
goto free_session;
err = perf_session__process_events(session);
if (!err)
err = ctf_writer__flush_streams(cw);
else
pr_err("Error during conversion.\n");
fprintf(stderr,
"[ perf data convert: Converted '%s' into CTF data '%s' ]\n",
file.path, path);
fprintf(stderr,
"[ perf data convert: Converted and wrote %.3f MB (%" PRIu64 " samples) ]\n",
(double) c.events_size / 1024.0 / 1024.0,
c.events_count);
perf_session__delete(session);
ctf_writer__cleanup(cw);
return err;
free_session:
perf_session__delete(session);
free_writer:
ctf_writer__cleanup(cw);
pr_err("Error during conversion setup.\n");
return err;
}
