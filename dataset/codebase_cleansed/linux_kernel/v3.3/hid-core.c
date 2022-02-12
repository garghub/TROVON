struct hid_report *hid_register_report(struct hid_device *device, unsigned type, unsigned id)
{
struct hid_report_enum *report_enum = device->report_enum + type;
struct hid_report *report;
if (report_enum->report_id_hash[id])
return report_enum->report_id_hash[id];
report = kzalloc(sizeof(struct hid_report), GFP_KERNEL);
if (!report)
return NULL;
if (id != 0)
report_enum->numbered = 1;
report->id = id;
report->type = type;
report->size = 0;
report->device = device;
report_enum->report_id_hash[id] = report;
list_add_tail(&report->list, &report_enum->report_list);
return report;
}
static struct hid_field *hid_register_field(struct hid_report *report, unsigned usages, unsigned values)
{
struct hid_field *field;
if (report->maxfield == HID_MAX_FIELDS) {
hid_err(report->device, "too many fields in report\n");
return NULL;
}
field = kzalloc((sizeof(struct hid_field) +
usages * sizeof(struct hid_usage) +
values * sizeof(unsigned)), GFP_KERNEL);
if (!field)
return NULL;
field->index = report->maxfield++;
report->field[field->index] = field;
field->usage = (struct hid_usage *)(field + 1);
field->value = (s32 *)(field->usage + usages);
field->report = report;
return field;
}
static int open_collection(struct hid_parser *parser, unsigned type)
{
struct hid_collection *collection;
unsigned usage;
usage = parser->local.usage[0];
if (parser->collection_stack_ptr == HID_COLLECTION_STACK_SIZE) {
hid_err(parser->device, "collection stack overflow\n");
return -1;
}
if (parser->device->maxcollection == parser->device->collection_size) {
collection = kmalloc(sizeof(struct hid_collection) *
parser->device->collection_size * 2, GFP_KERNEL);
if (collection == NULL) {
hid_err(parser->device, "failed to reallocate collection array\n");
return -1;
}
memcpy(collection, parser->device->collection,
sizeof(struct hid_collection) *
parser->device->collection_size);
memset(collection + parser->device->collection_size, 0,
sizeof(struct hid_collection) *
parser->device->collection_size);
kfree(parser->device->collection);
parser->device->collection = collection;
parser->device->collection_size *= 2;
}
parser->collection_stack[parser->collection_stack_ptr++] =
parser->device->maxcollection;
collection = parser->device->collection +
parser->device->maxcollection++;
collection->type = type;
collection->usage = usage;
collection->level = parser->collection_stack_ptr - 1;
if (type == HID_COLLECTION_APPLICATION)
parser->device->maxapplication++;
return 0;
}
static int close_collection(struct hid_parser *parser)
{
if (!parser->collection_stack_ptr) {
hid_err(parser->device, "collection stack underflow\n");
return -1;
}
parser->collection_stack_ptr--;
return 0;
}
static unsigned hid_lookup_collection(struct hid_parser *parser, unsigned type)
{
struct hid_collection *collection = parser->device->collection;
int n;
for (n = parser->collection_stack_ptr - 1; n >= 0; n--) {
unsigned index = parser->collection_stack[n];
if (collection[index].type == type)
return collection[index].usage;
}
return 0;
}
static int hid_add_usage(struct hid_parser *parser, unsigned usage)
{
if (parser->local.usage_index >= HID_MAX_USAGES) {
hid_err(parser->device, "usage index exceeded\n");
return -1;
}
parser->local.usage[parser->local.usage_index] = usage;
parser->local.collection_index[parser->local.usage_index] =
parser->collection_stack_ptr ?
parser->collection_stack[parser->collection_stack_ptr - 1] : 0;
parser->local.usage_index++;
return 0;
}
static int hid_add_field(struct hid_parser *parser, unsigned report_type, unsigned flags)
{
struct hid_report *report;
struct hid_field *field;
int usages;
unsigned offset;
int i;
report = hid_register_report(parser->device, report_type, parser->global.report_id);
if (!report) {
hid_err(parser->device, "hid_register_report failed\n");
return -1;
}
if (parser->global.logical_maximum < parser->global.logical_minimum) {
hid_err(parser->device, "logical range invalid %d %d\n",
parser->global.logical_minimum, parser->global.logical_maximum);
return -1;
}
offset = report->size;
report->size += parser->global.report_size * parser->global.report_count;
if (!parser->local.usage_index)
return 0;
usages = max_t(int, parser->local.usage_index, parser->global.report_count);
field = hid_register_field(report, usages, parser->global.report_count);
if (!field)
return 0;
field->physical = hid_lookup_collection(parser, HID_COLLECTION_PHYSICAL);
field->logical = hid_lookup_collection(parser, HID_COLLECTION_LOGICAL);
field->application = hid_lookup_collection(parser, HID_COLLECTION_APPLICATION);
for (i = 0; i < usages; i++) {
int j = i;
if (i >= parser->local.usage_index)
j = parser->local.usage_index - 1;
field->usage[i].hid = parser->local.usage[j];
field->usage[i].collection_index =
parser->local.collection_index[j];
}
field->maxusage = usages;
field->flags = flags;
field->report_offset = offset;
field->report_type = report_type;
field->report_size = parser->global.report_size;
field->report_count = parser->global.report_count;
field->logical_minimum = parser->global.logical_minimum;
field->logical_maximum = parser->global.logical_maximum;
field->physical_minimum = parser->global.physical_minimum;
field->physical_maximum = parser->global.physical_maximum;
field->unit_exponent = parser->global.unit_exponent;
field->unit = parser->global.unit;
return 0;
}
static u32 item_udata(struct hid_item *item)
{
switch (item->size) {
case 1: return item->data.u8;
case 2: return item->data.u16;
case 4: return item->data.u32;
}
return 0;
}
static s32 item_sdata(struct hid_item *item)
{
switch (item->size) {
case 1: return item->data.s8;
case 2: return item->data.s16;
case 4: return item->data.s32;
}
return 0;
}
static int hid_parser_global(struct hid_parser *parser, struct hid_item *item)
{
switch (item->tag) {
case HID_GLOBAL_ITEM_TAG_PUSH:
if (parser->global_stack_ptr == HID_GLOBAL_STACK_SIZE) {
hid_err(parser->device, "global environment stack overflow\n");
return -1;
}
memcpy(parser->global_stack + parser->global_stack_ptr++,
&parser->global, sizeof(struct hid_global));
return 0;
case HID_GLOBAL_ITEM_TAG_POP:
if (!parser->global_stack_ptr) {
hid_err(parser->device, "global environment stack underflow\n");
return -1;
}
memcpy(&parser->global, parser->global_stack +
--parser->global_stack_ptr, sizeof(struct hid_global));
return 0;
case HID_GLOBAL_ITEM_TAG_USAGE_PAGE:
parser->global.usage_page = item_udata(item);
return 0;
case HID_GLOBAL_ITEM_TAG_LOGICAL_MINIMUM:
parser->global.logical_minimum = item_sdata(item);
return 0;
case HID_GLOBAL_ITEM_TAG_LOGICAL_MAXIMUM:
if (parser->global.logical_minimum < 0)
parser->global.logical_maximum = item_sdata(item);
else
parser->global.logical_maximum = item_udata(item);
return 0;
case HID_GLOBAL_ITEM_TAG_PHYSICAL_MINIMUM:
parser->global.physical_minimum = item_sdata(item);
return 0;
case HID_GLOBAL_ITEM_TAG_PHYSICAL_MAXIMUM:
if (parser->global.physical_minimum < 0)
parser->global.physical_maximum = item_sdata(item);
else
parser->global.physical_maximum = item_udata(item);
return 0;
case HID_GLOBAL_ITEM_TAG_UNIT_EXPONENT:
parser->global.unit_exponent = item_sdata(item);
return 0;
case HID_GLOBAL_ITEM_TAG_UNIT:
parser->global.unit = item_udata(item);
return 0;
case HID_GLOBAL_ITEM_TAG_REPORT_SIZE:
parser->global.report_size = item_udata(item);
if (parser->global.report_size > 96) {
hid_err(parser->device, "invalid report_size %d\n",
parser->global.report_size);
return -1;
}
return 0;
case HID_GLOBAL_ITEM_TAG_REPORT_COUNT:
parser->global.report_count = item_udata(item);
if (parser->global.report_count > HID_MAX_USAGES) {
hid_err(parser->device, "invalid report_count %d\n",
parser->global.report_count);
return -1;
}
return 0;
case HID_GLOBAL_ITEM_TAG_REPORT_ID:
parser->global.report_id = item_udata(item);
if (parser->global.report_id == 0) {
hid_err(parser->device, "report_id 0 is invalid\n");
return -1;
}
return 0;
default:
hid_err(parser->device, "unknown global tag 0x%x\n", item->tag);
return -1;
}
}
static int hid_parser_local(struct hid_parser *parser, struct hid_item *item)
{
__u32 data;
unsigned n;
data = item_udata(item);
switch (item->tag) {
case HID_LOCAL_ITEM_TAG_DELIMITER:
if (data) {
if (parser->local.delimiter_depth != 0) {
hid_err(parser->device, "nested delimiters\n");
return -1;
}
parser->local.delimiter_depth++;
parser->local.delimiter_branch++;
} else {
if (parser->local.delimiter_depth < 1) {
hid_err(parser->device, "bogus close delimiter\n");
return -1;
}
parser->local.delimiter_depth--;
}
return 1;
case HID_LOCAL_ITEM_TAG_USAGE:
if (parser->local.delimiter_branch > 1) {
dbg_hid("alternative usage ignored\n");
return 0;
}
if (item->size <= 2)
data = (parser->global.usage_page << 16) + data;
return hid_add_usage(parser, data);
case HID_LOCAL_ITEM_TAG_USAGE_MINIMUM:
if (parser->local.delimiter_branch > 1) {
dbg_hid("alternative usage ignored\n");
return 0;
}
if (item->size <= 2)
data = (parser->global.usage_page << 16) + data;
parser->local.usage_minimum = data;
return 0;
case HID_LOCAL_ITEM_TAG_USAGE_MAXIMUM:
if (parser->local.delimiter_branch > 1) {
dbg_hid("alternative usage ignored\n");
return 0;
}
if (item->size <= 2)
data = (parser->global.usage_page << 16) + data;
for (n = parser->local.usage_minimum; n <= data; n++)
if (hid_add_usage(parser, n)) {
dbg_hid("hid_add_usage failed\n");
return -1;
}
return 0;
default:
dbg_hid("unknown local item tag 0x%x\n", item->tag);
return 0;
}
return 0;
}
static int hid_parser_main(struct hid_parser *parser, struct hid_item *item)
{
__u32 data;
int ret;
data = item_udata(item);
switch (item->tag) {
case HID_MAIN_ITEM_TAG_BEGIN_COLLECTION:
ret = open_collection(parser, data & 0xff);
break;
case HID_MAIN_ITEM_TAG_END_COLLECTION:
ret = close_collection(parser);
break;
case HID_MAIN_ITEM_TAG_INPUT:
ret = hid_add_field(parser, HID_INPUT_REPORT, data);
break;
case HID_MAIN_ITEM_TAG_OUTPUT:
ret = hid_add_field(parser, HID_OUTPUT_REPORT, data);
break;
case HID_MAIN_ITEM_TAG_FEATURE:
ret = hid_add_field(parser, HID_FEATURE_REPORT, data);
break;
default:
hid_err(parser->device, "unknown main item tag 0x%x\n", item->tag);
ret = 0;
}
memset(&parser->local, 0, sizeof(parser->local));
return ret;
}
static int hid_parser_reserved(struct hid_parser *parser, struct hid_item *item)
{
dbg_hid("reserved item type, tag 0x%x\n", item->tag);
return 0;
}
static void hid_free_report(struct hid_report *report)
{
unsigned n;
for (n = 0; n < report->maxfield; n++)
kfree(report->field[n]);
kfree(report);
}
static void hid_device_release(struct device *dev)
{
struct hid_device *device = container_of(dev, struct hid_device, dev);
unsigned i, j;
for (i = 0; i < HID_REPORT_TYPES; i++) {
struct hid_report_enum *report_enum = device->report_enum + i;
for (j = 0; j < 256; j++) {
struct hid_report *report = report_enum->report_id_hash[j];
if (report)
hid_free_report(report);
}
}
kfree(device->rdesc);
kfree(device->collection);
kfree(device);
}
static u8 *fetch_item(__u8 *start, __u8 *end, struct hid_item *item)
{
u8 b;
if ((end - start) <= 0)
return NULL;
b = *start++;
item->type = (b >> 2) & 3;
item->tag = (b >> 4) & 15;
if (item->tag == HID_ITEM_TAG_LONG) {
item->format = HID_ITEM_FORMAT_LONG;
if ((end - start) < 2)
return NULL;
item->size = *start++;
item->tag = *start++;
if ((end - start) < item->size)
return NULL;
item->data.longdata = start;
start += item->size;
return start;
}
item->format = HID_ITEM_FORMAT_SHORT;
item->size = b & 3;
switch (item->size) {
case 0:
return start;
case 1:
if ((end - start) < 1)
return NULL;
item->data.u8 = *start++;
return start;
case 2:
if ((end - start) < 2)
return NULL;
item->data.u16 = get_unaligned_le16(start);
start = (__u8 *)((__le16 *)start + 1);
return start;
case 3:
item->size++;
if ((end - start) < 4)
return NULL;
item->data.u32 = get_unaligned_le32(start);
start = (__u8 *)((__le32 *)start + 1);
return start;
}
return NULL;
}
int hid_parse_report(struct hid_device *device, __u8 *start,
unsigned size)
{
struct hid_parser *parser;
struct hid_item item;
__u8 *end;
int ret;
static int (*dispatch_type[])(struct hid_parser *parser,
struct hid_item *item) = {
hid_parser_main,
hid_parser_global,
hid_parser_local,
hid_parser_reserved
}
static s32 snto32(__u32 value, unsigned n)
{
switch (n) {
case 8: return ((__s8)value);
case 16: return ((__s16)value);
case 32: return ((__s32)value);
}
return value & (1 << (n - 1)) ? value | (-1 << n) : value;
}
static u32 s32ton(__s32 value, unsigned n)
{
s32 a = value >> (n - 1);
if (a && a != -1)
return value < 0 ? 1 << (n - 1) : (1 << (n - 1)) - 1;
return value & ((1 << n) - 1);
}
static __u32 extract(const struct hid_device *hid, __u8 *report,
unsigned offset, unsigned n)
{
u64 x;
if (n > 32)
hid_warn(hid, "extract() called with n (%d) > 32! (%s)\n",
n, current->comm);
report += offset >> 3;
offset &= 7;
x = get_unaligned_le64(report);
x = (x >> offset) & ((1ULL << n) - 1);
return (u32) x;
}
static void implement(const struct hid_device *hid, __u8 *report,
unsigned offset, unsigned n, __u32 value)
{
u64 x;
u64 m = (1ULL << n) - 1;
if (n > 32)
hid_warn(hid, "%s() called with n (%d) > 32! (%s)\n",
__func__, n, current->comm);
if (value > m)
hid_warn(hid, "%s() called with too large value %d! (%s)\n",
__func__, value, current->comm);
WARN_ON(value > m);
value &= m;
report += offset >> 3;
offset &= 7;
x = get_unaligned_le64(report);
x &= ~(m << offset);
x |= ((u64)value) << offset;
put_unaligned_le64(x, report);
}
static int search(__s32 *array, __s32 value, unsigned n)
{
while (n--) {
if (*array++ == value)
return 0;
}
return -1;
}
static int hid_match_report(struct hid_device *hid, struct hid_report *report)
{
const struct hid_report_id *id = hid->driver->report_table;
if (!id)
return 1;
for (; id->report_type != HID_TERMINATOR; id++)
if (id->report_type == HID_ANY_ID ||
id->report_type == report->type)
return 1;
return 0;
}
static int hid_match_usage(struct hid_device *hid, struct hid_usage *usage)
{
const struct hid_usage_id *id = hid->driver->usage_table;
if (!id)
return 1;
for (; id->usage_type != HID_ANY_ID - 1; id++)
if ((id->usage_hid == HID_ANY_ID ||
id->usage_hid == usage->hid) &&
(id->usage_type == HID_ANY_ID ||
id->usage_type == usage->type) &&
(id->usage_code == HID_ANY_ID ||
id->usage_code == usage->code))
return 1;
return 0;
}
static void hid_process_event(struct hid_device *hid, struct hid_field *field,
struct hid_usage *usage, __s32 value, int interrupt)
{
struct hid_driver *hdrv = hid->driver;
int ret;
hid_dump_input(hid, usage, value);
if (hdrv && hdrv->event && hid_match_usage(hid, usage)) {
ret = hdrv->event(hid, field, usage, value);
if (ret != 0) {
if (ret < 0)
hid_err(hid, "%s's event failed with %d\n",
hdrv->name, ret);
return;
}
}
if (hid->claimed & HID_CLAIMED_INPUT)
hidinput_hid_event(hid, field, usage, value);
if (hid->claimed & HID_CLAIMED_HIDDEV && interrupt && hid->hiddev_hid_event)
hid->hiddev_hid_event(hid, field, usage, value);
}
static void hid_input_field(struct hid_device *hid, struct hid_field *field,
__u8 *data, int interrupt)
{
unsigned n;
unsigned count = field->report_count;
unsigned offset = field->report_offset;
unsigned size = field->report_size;
__s32 min = field->logical_minimum;
__s32 max = field->logical_maximum;
__s32 *value;
value = kmalloc(sizeof(__s32) * count, GFP_ATOMIC);
if (!value)
return;
for (n = 0; n < count; n++) {
value[n] = min < 0 ?
snto32(extract(hid, data, offset + n * size, size),
size) :
extract(hid, data, offset + n * size, size);
if (!(field->flags & HID_MAIN_ITEM_VARIABLE) &&
value[n] >= min && value[n] <= max &&
field->usage[value[n] - min].hid == HID_UP_KEYBOARD + 1)
goto exit;
}
for (n = 0; n < count; n++) {
if (HID_MAIN_ITEM_VARIABLE & field->flags) {
hid_process_event(hid, field, &field->usage[n], value[n], interrupt);
continue;
}
if (field->value[n] >= min && field->value[n] <= max
&& field->usage[field->value[n] - min].hid
&& search(value, field->value[n], count))
hid_process_event(hid, field, &field->usage[field->value[n] - min], 0, interrupt);
if (value[n] >= min && value[n] <= max
&& field->usage[value[n] - min].hid
&& search(field->value, value[n], count))
hid_process_event(hid, field, &field->usage[value[n] - min], 1, interrupt);
}
memcpy(field->value, value, count * sizeof(__s32));
exit:
kfree(value);
}
static void hid_output_field(const struct hid_device *hid,
struct hid_field *field, __u8 *data)
{
unsigned count = field->report_count;
unsigned offset = field->report_offset;
unsigned size = field->report_size;
unsigned n;
for (n = 0; n < count; n++) {
if (field->logical_minimum < 0)
implement(hid, data, offset + n * size, size,
s32ton(field->value[n], size));
else
implement(hid, data, offset + n * size, size,
field->value[n]);
}
}
void hid_output_report(struct hid_report *report, __u8 *data)
{
unsigned n;
if (report->id > 0)
*data++ = report->id;
memset(data, 0, ((report->size - 1) >> 3) + 1);
for (n = 0; n < report->maxfield; n++)
hid_output_field(report->device, report->field[n], data);
}
int hid_set_field(struct hid_field *field, unsigned offset, __s32 value)
{
unsigned size = field->report_size;
hid_dump_input(field->report->device, field->usage + offset, value);
if (offset >= field->report_count) {
hid_err(field->report->device, "offset (%d) exceeds report_count (%d)\n",
offset, field->report_count);
return -1;
}
if (field->logical_minimum < 0) {
if (value != snto32(s32ton(value, size), size)) {
hid_err(field->report->device, "value %d is out of range\n", value);
return -1;
}
}
field->value[offset] = value;
return 0;
}
static struct hid_report *hid_get_report(struct hid_report_enum *report_enum,
const u8 *data)
{
struct hid_report *report;
unsigned int n = 0;
if (report_enum->numbered)
n = *data;
report = report_enum->report_id_hash[n];
if (report == NULL)
dbg_hid("undefined report_id %u received\n", n);
return report;
}
void hid_report_raw_event(struct hid_device *hid, int type, u8 *data, int size,
int interrupt)
{
struct hid_report_enum *report_enum = hid->report_enum + type;
struct hid_report *report;
unsigned int a;
int rsize, csize = size;
u8 *cdata = data;
report = hid_get_report(report_enum, data);
if (!report)
return;
if (report_enum->numbered) {
cdata++;
csize--;
}
rsize = ((report->size - 1) >> 3) + 1;
if (rsize > HID_MAX_BUFFER_SIZE)
rsize = HID_MAX_BUFFER_SIZE;
if (csize < rsize) {
dbg_hid("report %d is too short, (%d < %d)\n", report->id,
csize, rsize);
memset(cdata + csize, 0, rsize - csize);
}
if ((hid->claimed & HID_CLAIMED_HIDDEV) && hid->hiddev_report_event)
hid->hiddev_report_event(hid, report);
if (hid->claimed & HID_CLAIMED_HIDRAW)
hidraw_report_event(hid, data, size);
for (a = 0; a < report->maxfield; a++)
hid_input_field(hid, report->field[a], cdata, interrupt);
if (hid->claimed & HID_CLAIMED_INPUT)
hidinput_report_event(hid, report);
}
int hid_input_report(struct hid_device *hid, int type, u8 *data, int size, int interrupt)
{
struct hid_report_enum *report_enum;
struct hid_driver *hdrv;
struct hid_report *report;
char *buf;
unsigned int i;
int ret = 0;
if (!hid)
return -ENODEV;
if (down_trylock(&hid->driver_lock))
return -EBUSY;
if (!hid->driver) {
ret = -ENODEV;
goto unlock;
}
report_enum = hid->report_enum + type;
hdrv = hid->driver;
if (!size) {
dbg_hid("empty report\n");
ret = -1;
goto unlock;
}
buf = kmalloc(sizeof(char) * HID_DEBUG_BUFSIZE, GFP_ATOMIC);
if (!buf)
goto nomem;
snprintf(buf, HID_DEBUG_BUFSIZE - 1,
"\nreport (size %u) (%snumbered) = ", size, report_enum->numbered ? "" : "un");
hid_debug_event(hid, buf);
for (i = 0; i < size; i++) {
snprintf(buf, HID_DEBUG_BUFSIZE - 1,
" %02x", data[i]);
hid_debug_event(hid, buf);
}
hid_debug_event(hid, "\n");
kfree(buf);
nomem:
report = hid_get_report(report_enum, data);
if (!report) {
ret = -1;
goto unlock;
}
if (hdrv && hdrv->raw_event && hid_match_report(hid, report)) {
ret = hdrv->raw_event(hid, report, data, size);
if (ret != 0) {
ret = ret < 0 ? ret : 0;
goto unlock;
}
}
hid_report_raw_event(hid, type, data, size, interrupt);
unlock:
up(&hid->driver_lock);
return ret;
}
static bool hid_match_one_id(struct hid_device *hdev,
const struct hid_device_id *id)
{
return id->bus == hdev->bus &&
(id->vendor == HID_ANY_ID || id->vendor == hdev->vendor) &&
(id->product == HID_ANY_ID || id->product == hdev->product);
}
const struct hid_device_id *hid_match_id(struct hid_device *hdev,
const struct hid_device_id *id)
{
for (; id->bus; id++)
if (hid_match_one_id(hdev, id))
return id;
return NULL;
}
static bool hid_hiddev(struct hid_device *hdev)
{
return !!hid_match_id(hdev, hid_hiddev_list);
}
static ssize_t
read_report_descriptor(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t off, size_t count)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
if (off >= hdev->rsize)
return 0;
if (off + count > hdev->rsize)
count = hdev->rsize - off;
memcpy(buf, hdev->rdesc + off, count);
return count;
}
int hid_connect(struct hid_device *hdev, unsigned int connect_mask)
{
static const char *types[] = { "Device", "Pointer", "Mouse", "Device",
"Joystick", "Gamepad", "Keyboard", "Keypad",
"Multi-Axis Controller"
};
const char *type, *bus;
char buf[64];
unsigned int i;
int len;
int ret;
if (hdev->quirks & HID_QUIRK_HIDDEV_FORCE)
connect_mask |= (HID_CONNECT_HIDDEV_FORCE | HID_CONNECT_HIDDEV);
if (hdev->quirks & HID_QUIRK_HIDINPUT_FORCE)
connect_mask |= HID_CONNECT_HIDINPUT_FORCE;
if (hdev->bus != BUS_USB)
connect_mask &= ~HID_CONNECT_HIDDEV;
if (hid_hiddev(hdev))
connect_mask |= HID_CONNECT_HIDDEV_FORCE;
if ((connect_mask & HID_CONNECT_HIDINPUT) && !hidinput_connect(hdev,
connect_mask & HID_CONNECT_HIDINPUT_FORCE))
hdev->claimed |= HID_CLAIMED_INPUT;
if (hdev->quirks & HID_QUIRK_MULTITOUCH) {
hdev->quirks &= ~HID_QUIRK_MULTITOUCH;
return -ENODEV;
}
if ((connect_mask & HID_CONNECT_HIDDEV) && hdev->hiddev_connect &&
!hdev->hiddev_connect(hdev,
connect_mask & HID_CONNECT_HIDDEV_FORCE))
hdev->claimed |= HID_CLAIMED_HIDDEV;
if ((connect_mask & HID_CONNECT_HIDRAW) && !hidraw_connect(hdev))
hdev->claimed |= HID_CLAIMED_HIDRAW;
if (!hdev->claimed) {
hid_err(hdev, "claimed by neither input, hiddev nor hidraw\n");
return -ENODEV;
}
if ((hdev->claimed & HID_CLAIMED_INPUT) &&
(connect_mask & HID_CONNECT_FF) && hdev->ff_init)
hdev->ff_init(hdev);
len = 0;
if (hdev->claimed & HID_CLAIMED_INPUT)
len += sprintf(buf + len, "input");
if (hdev->claimed & HID_CLAIMED_HIDDEV)
len += sprintf(buf + len, "%shiddev%d", len ? "," : "",
hdev->minor);
if (hdev->claimed & HID_CLAIMED_HIDRAW)
len += sprintf(buf + len, "%shidraw%d", len ? "," : "",
((struct hidraw *)hdev->hidraw)->minor);
type = "Device";
for (i = 0; i < hdev->maxcollection; i++) {
struct hid_collection *col = &hdev->collection[i];
if (col->type == HID_COLLECTION_APPLICATION &&
(col->usage & HID_USAGE_PAGE) == HID_UP_GENDESK &&
(col->usage & 0xffff) < ARRAY_SIZE(types)) {
type = types[col->usage & 0xffff];
break;
}
}
switch (hdev->bus) {
case BUS_USB:
bus = "USB";
break;
case BUS_BLUETOOTH:
bus = "BLUETOOTH";
break;
default:
bus = "<UNKNOWN>";
}
ret = device_create_bin_file(&hdev->dev, &dev_bin_attr_report_desc);
if (ret)
hid_warn(hdev,
"can't create sysfs report descriptor attribute err: %d\n", ret);
hid_info(hdev, "%s: %s HID v%x.%02x %s [%s] on %s\n",
buf, bus, hdev->version >> 8, hdev->version & 0xff,
type, hdev->name, hdev->phys);
return 0;
}
void hid_disconnect(struct hid_device *hdev)
{
device_remove_bin_file(&hdev->dev, &dev_bin_attr_report_desc);
if (hdev->claimed & HID_CLAIMED_INPUT)
hidinput_disconnect(hdev);
if (hdev->claimed & HID_CLAIMED_HIDDEV)
hdev->hiddev_disconnect(hdev);
if (hdev->claimed & HID_CLAIMED_HIDRAW)
hidraw_disconnect(hdev);
}
static ssize_t store_new_id(struct device_driver *drv, const char *buf,
size_t count)
{
struct hid_driver *hdrv = container_of(drv, struct hid_driver, driver);
struct hid_dynid *dynid;
__u32 bus, vendor, product;
unsigned long driver_data = 0;
int ret;
ret = sscanf(buf, "%x %x %x %lx",
&bus, &vendor, &product, &driver_data);
if (ret < 3)
return -EINVAL;
dynid = kzalloc(sizeof(*dynid), GFP_KERNEL);
if (!dynid)
return -ENOMEM;
dynid->id.bus = bus;
dynid->id.vendor = vendor;
dynid->id.product = product;
dynid->id.driver_data = driver_data;
spin_lock(&hdrv->dyn_lock);
list_add_tail(&dynid->list, &hdrv->dyn_list);
spin_unlock(&hdrv->dyn_lock);
ret = 0;
if (get_driver(&hdrv->driver)) {
ret = driver_attach(&hdrv->driver);
put_driver(&hdrv->driver);
}
return ret ? : count;
}
static void hid_free_dynids(struct hid_driver *hdrv)
{
struct hid_dynid *dynid, *n;
spin_lock(&hdrv->dyn_lock);
list_for_each_entry_safe(dynid, n, &hdrv->dyn_list, list) {
list_del(&dynid->list);
kfree(dynid);
}
spin_unlock(&hdrv->dyn_lock);
}
static const struct hid_device_id *hid_match_device(struct hid_device *hdev,
struct hid_driver *hdrv)
{
struct hid_dynid *dynid;
spin_lock(&hdrv->dyn_lock);
list_for_each_entry(dynid, &hdrv->dyn_list, list) {
if (hid_match_one_id(hdev, &dynid->id)) {
spin_unlock(&hdrv->dyn_lock);
return &dynid->id;
}
}
spin_unlock(&hdrv->dyn_lock);
return hid_match_id(hdev, hdrv->id_table);
}
static int hid_bus_match(struct device *dev, struct device_driver *drv)
{
struct hid_driver *hdrv = container_of(drv, struct hid_driver, driver);
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
if (!hid_match_device(hdev, hdrv))
return 0;
if (!strncmp(hdrv->name, "generic-", 8))
return !hid_match_id(hdev, hid_have_special_driver);
return 1;
}
static int hid_device_probe(struct device *dev)
{
struct hid_driver *hdrv = container_of(dev->driver,
struct hid_driver, driver);
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
const struct hid_device_id *id;
int ret = 0;
if (down_interruptible(&hdev->driver_lock))
return -EINTR;
if (!hdev->driver) {
id = hid_match_device(hdev, hdrv);
if (id == NULL) {
ret = -ENODEV;
goto unlock;
}
hdev->driver = hdrv;
if (hdrv->probe) {
ret = hdrv->probe(hdev, id);
} else {
ret = hid_parse(hdev);
if (!ret)
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
}
if (ret)
hdev->driver = NULL;
}
unlock:
up(&hdev->driver_lock);
return ret;
}
static int hid_device_remove(struct device *dev)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct hid_driver *hdrv;
if (down_interruptible(&hdev->driver_lock))
return -EINTR;
hdrv = hdev->driver;
if (hdrv) {
if (hdrv->remove)
hdrv->remove(hdev);
else
hid_hw_stop(hdev);
hdev->driver = NULL;
}
up(&hdev->driver_lock);
return 0;
}
static int hid_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
if (add_uevent_var(env, "HID_ID=%04X:%08X:%08X",
hdev->bus, hdev->vendor, hdev->product))
return -ENOMEM;
if (add_uevent_var(env, "HID_NAME=%s", hdev->name))
return -ENOMEM;
if (add_uevent_var(env, "HID_PHYS=%s", hdev->phys))
return -ENOMEM;
if (add_uevent_var(env, "HID_UNIQ=%s", hdev->uniq))
return -ENOMEM;
if (add_uevent_var(env, "MODALIAS=hid:b%04Xv%08Xp%08X",
hdev->bus, hdev->vendor, hdev->product))
return -ENOMEM;
return 0;
}
static bool hid_ignore(struct hid_device *hdev)
{
switch (hdev->vendor) {
case USB_VENDOR_ID_CODEMERCS:
if (hdev->product >= USB_DEVICE_ID_CODEMERCS_IOW_FIRST &&
hdev->product <= USB_DEVICE_ID_CODEMERCS_IOW_LAST)
return true;
break;
case USB_VENDOR_ID_LOGITECH:
if (hdev->product >= USB_DEVICE_ID_LOGITECH_HARMONY_FIRST &&
hdev->product <= USB_DEVICE_ID_LOGITECH_HARMONY_LAST)
return true;
break;
case USB_VENDOR_ID_SOUNDGRAPH:
if (hdev->product >= USB_DEVICE_ID_SOUNDGRAPH_IMON_FIRST &&
hdev->product <= USB_DEVICE_ID_SOUNDGRAPH_IMON_LAST)
return true;
break;
case USB_VENDOR_ID_HANWANG:
if (hdev->product >= USB_DEVICE_ID_HANWANG_TABLET_FIRST &&
hdev->product <= USB_DEVICE_ID_HANWANG_TABLET_LAST)
return true;
break;
case USB_VENDOR_ID_JESS:
if (hdev->product == USB_DEVICE_ID_JESS_YUREX &&
hdev->type == HID_TYPE_USBNONE)
return true;
break;
}
if (hdev->type == HID_TYPE_USBMOUSE &&
hid_match_id(hdev, hid_mouse_ignore_list))
return true;
return !!hid_match_id(hdev, hid_ignore_list);
}
int hid_add_device(struct hid_device *hdev)
{
static atomic_t id = ATOMIC_INIT(0);
int ret;
if (WARN_ON(hdev->status & HID_STAT_ADDED))
return -EBUSY;
if (!(hdev->quirks & HID_QUIRK_NO_IGNORE)
&& (hid_ignore(hdev) || (hdev->quirks & HID_QUIRK_IGNORE)))
return -ENODEV;
dev_set_name(&hdev->dev, "%04X:%04X:%04X.%04X", hdev->bus,
hdev->vendor, hdev->product, atomic_inc_return(&id));
hid_debug_register(hdev, dev_name(&hdev->dev));
ret = device_add(&hdev->dev);
if (!ret)
hdev->status |= HID_STAT_ADDED;
else
hid_debug_unregister(hdev);
return ret;
}
struct hid_device *hid_allocate_device(void)
{
struct hid_device *hdev;
unsigned int i;
int ret = -ENOMEM;
hdev = kzalloc(sizeof(*hdev), GFP_KERNEL);
if (hdev == NULL)
return ERR_PTR(ret);
device_initialize(&hdev->dev);
hdev->dev.release = hid_device_release;
hdev->dev.bus = &hid_bus_type;
hdev->collection = kcalloc(HID_DEFAULT_NUM_COLLECTIONS,
sizeof(struct hid_collection), GFP_KERNEL);
if (hdev->collection == NULL)
goto err;
hdev->collection_size = HID_DEFAULT_NUM_COLLECTIONS;
for (i = 0; i < HID_REPORT_TYPES; i++)
INIT_LIST_HEAD(&hdev->report_enum[i].report_list);
init_waitqueue_head(&hdev->debug_wait);
INIT_LIST_HEAD(&hdev->debug_list);
sema_init(&hdev->driver_lock, 1);
return hdev;
err:
put_device(&hdev->dev);
return ERR_PTR(ret);
}
static void hid_remove_device(struct hid_device *hdev)
{
if (hdev->status & HID_STAT_ADDED) {
device_del(&hdev->dev);
hid_debug_unregister(hdev);
hdev->status &= ~HID_STAT_ADDED;
}
}
void hid_destroy_device(struct hid_device *hdev)
{
hid_remove_device(hdev);
put_device(&hdev->dev);
}
int __hid_register_driver(struct hid_driver *hdrv, struct module *owner,
const char *mod_name)
{
int ret;
hdrv->driver.name = hdrv->name;
hdrv->driver.bus = &hid_bus_type;
hdrv->driver.owner = owner;
hdrv->driver.mod_name = mod_name;
INIT_LIST_HEAD(&hdrv->dyn_list);
spin_lock_init(&hdrv->dyn_lock);
ret = driver_register(&hdrv->driver);
if (ret)
return ret;
ret = driver_create_file(&hdrv->driver, &driver_attr_new_id);
if (ret)
driver_unregister(&hdrv->driver);
return ret;
}
void hid_unregister_driver(struct hid_driver *hdrv)
{
driver_remove_file(&hdrv->driver, &driver_attr_new_id);
driver_unregister(&hdrv->driver);
hid_free_dynids(hdrv);
}
int hid_check_keys_pressed(struct hid_device *hid)
{
struct hid_input *hidinput;
int i;
if (!(hid->claimed & HID_CLAIMED_INPUT))
return 0;
list_for_each_entry(hidinput, &hid->inputs, list) {
for (i = 0; i < BITS_TO_LONGS(KEY_MAX); i++)
if (hidinput->input->key[i])
return 1;
}
return 0;
}
static int __init hid_init(void)
{
int ret;
if (hid_debug)
pr_warn("hid_debug is now used solely for parser and driver debugging.\n"
"debugfs is now used for inspecting the device (report descriptor, reports)\n");
ret = bus_register(&hid_bus_type);
if (ret) {
pr_err("can't register hid bus\n");
goto err;
}
ret = hidraw_init();
if (ret)
goto err_bus;
hid_debug_init();
return 0;
err_bus:
bus_unregister(&hid_bus_type);
err:
return ret;
}
static void __exit hid_exit(void)
{
hid_debug_exit();
hidraw_exit();
bus_unregister(&hid_bus_type);
}
