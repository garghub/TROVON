const char *gcov_info_filename(struct gcov_info *info)
{
return info->filename;
}
unsigned int gcov_info_version(struct gcov_info *info)
{
return info->version;
}
struct gcov_info *gcov_info_next(struct gcov_info *info)
{
if (!info)
return gcov_info_head;
return info->next;
}
void gcov_info_link(struct gcov_info *info)
{
info->next = gcov_info_head;
gcov_info_head = info;
}
void gcov_info_unlink(struct gcov_info *prev, struct gcov_info *info)
{
if (prev)
prev->next = info->next;
else
gcov_info_head = info->next;
}
static int counter_active(struct gcov_info *info, unsigned int type)
{
return (1 << type) & info->ctr_mask;
}
static unsigned int num_counter_active(struct gcov_info *info)
{
unsigned int i;
unsigned int result = 0;
for (i = 0; i < GCOV_COUNTERS; i++) {
if (counter_active(info, i))
result++;
}
return result;
}
void gcov_info_reset(struct gcov_info *info)
{
unsigned int active = num_counter_active(info);
unsigned int i;
for (i = 0; i < active; i++) {
memset(info->counts[i].values, 0,
info->counts[i].num * sizeof(gcov_type));
}
}
int gcov_info_is_compatible(struct gcov_info *info1, struct gcov_info *info2)
{
return (info1->stamp == info2->stamp);
}
void gcov_info_add(struct gcov_info *dest, struct gcov_info *source)
{
unsigned int i;
unsigned int j;
for (i = 0; i < num_counter_active(dest); i++) {
for (j = 0; j < dest->counts[i].num; j++) {
dest->counts[i].values[j] +=
source->counts[i].values[j];
}
}
}
static size_t get_fn_size(struct gcov_info *info)
{
size_t size;
size = sizeof(struct gcov_fn_info) + num_counter_active(info) *
sizeof(unsigned int);
if (__alignof__(struct gcov_fn_info) > sizeof(unsigned int))
size = ALIGN(size, __alignof__(struct gcov_fn_info));
return size;
}
static struct gcov_fn_info *get_fn_info(struct gcov_info *info, unsigned int fn)
{
return (struct gcov_fn_info *)
((char *) info->functions + fn * get_fn_size(info));
}
struct gcov_info *gcov_info_dup(struct gcov_info *info)
{
struct gcov_info *dup;
unsigned int i;
unsigned int active;
active = num_counter_active(info);
dup = kzalloc(sizeof(struct gcov_info) +
sizeof(struct gcov_ctr_info) * active, GFP_KERNEL);
if (!dup)
return NULL;
dup->version = info->version;
dup->stamp = info->stamp;
dup->n_functions = info->n_functions;
dup->ctr_mask = info->ctr_mask;
dup->filename = kstrdup(info->filename, GFP_KERNEL);
if (!dup->filename)
goto err_free;
dup->functions = kmemdup(info->functions, info->n_functions *
get_fn_size(info), GFP_KERNEL);
if (!dup->functions)
goto err_free;
for (i = 0; i < active ; i++) {
struct gcov_ctr_info *ctr = &info->counts[i];
size_t size = ctr->num * sizeof(gcov_type);
dup->counts[i].num = ctr->num;
dup->counts[i].merge = ctr->merge;
dup->counts[i].values = vmalloc(size);
if (!dup->counts[i].values)
goto err_free;
memcpy(dup->counts[i].values, ctr->values, size);
}
return dup;
err_free:
gcov_info_free(dup);
return NULL;
}
void gcov_info_free(struct gcov_info *info)
{
unsigned int active = num_counter_active(info);
unsigned int i;
for (i = 0; i < active ; i++)
vfree(info->counts[i].values);
kfree(info->functions);
kfree(info->filename);
kfree(info);
}
static struct gcov_fn_info *get_func(struct gcov_iterator *iter)
{
return get_fn_info(iter->info, iter->function);
}
static struct type_info *get_type(struct gcov_iterator *iter)
{
return &iter->type_info[iter->type];
}
struct gcov_iterator *gcov_iter_new(struct gcov_info *info)
{
struct gcov_iterator *iter;
iter = kzalloc(sizeof(struct gcov_iterator) +
num_counter_active(info) * sizeof(struct type_info),
GFP_KERNEL);
if (iter)
iter->info = info;
return iter;
}
void gcov_iter_free(struct gcov_iterator *iter)
{
kfree(iter);
}
struct gcov_info *gcov_iter_get_info(struct gcov_iterator *iter)
{
return iter->info;
}
void gcov_iter_start(struct gcov_iterator *iter)
{
int i;
iter->record = 0;
iter->function = 0;
iter->type = 0;
iter->count = 0;
iter->num_types = 0;
for (i = 0; i < GCOV_COUNTERS; i++) {
if (counter_active(iter->info, i)) {
iter->type_info[iter->num_types].ctr_type = i;
iter->type_info[iter->num_types++].offset = 0;
}
}
}
int gcov_iter_next(struct gcov_iterator *iter)
{
switch (iter->record) {
case RECORD_FILE_MAGIC:
case RECORD_GCOV_VERSION:
case RECORD_FUNCTION_TAG:
case RECORD_FUNCTON_TAG_LEN:
case RECORD_FUNCTION_IDENT:
case RECORD_COUNT_TAG:
iter->record++;
break;
case RECORD_COUNT:
iter->count++;
case RECORD_COUNT_LEN:
if (iter->count < get_func(iter)->n_ctrs[iter->type]) {
iter->record = 9;
break;
}
get_type(iter)->offset += iter->count;
iter->count = 0;
iter->type++;
case RECORD_FUNCTION_CHECK:
if (iter->type < iter->num_types) {
iter->record = 7;
break;
}
iter->type = 0;
iter->function++;
case RECORD_TIME_STAMP:
if (iter->function < iter->info->n_functions)
iter->record = 3;
else
iter->record = -1;
break;
}
if (iter->record == -1)
return -EINVAL;
else
return 0;
}
static int seq_write_gcov_u32(struct seq_file *seq, u32 v)
{
return seq_write(seq, &v, sizeof(v));
}
static int seq_write_gcov_u64(struct seq_file *seq, u64 v)
{
u32 data[2];
data[0] = (v & 0xffffffffUL);
data[1] = (v >> 32);
return seq_write(seq, data, sizeof(data));
}
int gcov_iter_write(struct gcov_iterator *iter, struct seq_file *seq)
{
int rc = -EINVAL;
switch (iter->record) {
case RECORD_FILE_MAGIC:
rc = seq_write_gcov_u32(seq, GCOV_DATA_MAGIC);
break;
case RECORD_GCOV_VERSION:
rc = seq_write_gcov_u32(seq, iter->info->version);
break;
case RECORD_TIME_STAMP:
rc = seq_write_gcov_u32(seq, iter->info->stamp);
break;
case RECORD_FUNCTION_TAG:
rc = seq_write_gcov_u32(seq, GCOV_TAG_FUNCTION);
break;
case RECORD_FUNCTON_TAG_LEN:
rc = seq_write_gcov_u32(seq, 2);
break;
case RECORD_FUNCTION_IDENT:
rc = seq_write_gcov_u32(seq, get_func(iter)->ident);
break;
case RECORD_FUNCTION_CHECK:
rc = seq_write_gcov_u32(seq, get_func(iter)->checksum);
break;
case RECORD_COUNT_TAG:
rc = seq_write_gcov_u32(seq,
GCOV_TAG_FOR_COUNTER(get_type(iter)->ctr_type));
break;
case RECORD_COUNT_LEN:
rc = seq_write_gcov_u32(seq,
get_func(iter)->n_ctrs[iter->type] * 2);
break;
case RECORD_COUNT:
rc = seq_write_gcov_u64(seq,
iter->info->counts[iter->type].
values[iter->count + get_type(iter)->offset]);
break;
}
return rc;
}
