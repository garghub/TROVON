static char *resolv_usage_page(unsigned page, struct seq_file *f) {
const struct hid_usage_entry *p;
char *buf = NULL;
if (!f) {
buf = kzalloc(sizeof(char) * HID_DEBUG_BUFSIZE, GFP_ATOMIC);
if (!buf)
return ERR_PTR(-ENOMEM);
}
for (p = hid_usage_table; p->description; p++)
if (p->page == page) {
if (!f) {
snprintf(buf, HID_DEBUG_BUFSIZE, "%s",
p->description);
return buf;
}
else {
seq_printf(f, "%s", p->description);
return NULL;
}
}
if (!f)
snprintf(buf, HID_DEBUG_BUFSIZE, "%04x", page);
else
seq_printf(f, "%04x", page);
return buf;
}
char *hid_resolv_usage(unsigned usage, struct seq_file *f) {
const struct hid_usage_entry *p;
char *buf = NULL;
int len = 0;
buf = resolv_usage_page(usage >> 16, f);
if (IS_ERR(buf)) {
pr_err("error allocating HID debug buffer\n");
return NULL;
}
if (!f) {
len = strlen(buf);
snprintf(buf+len, max(0, HID_DEBUG_BUFSIZE - len), ".");
len++;
}
else {
seq_printf(f, ".");
}
for (p = hid_usage_table; p->description; p++)
if (p->page == (usage >> 16)) {
for(++p; p->description && p->usage != 0; p++)
if (p->usage == (usage & 0xffff)) {
if (!f)
snprintf(buf + len,
max(0,HID_DEBUG_BUFSIZE - len - 1),
"%s", p->description);
else
seq_printf(f,
"%s",
p->description);
return buf;
}
break;
}
if (!f)
snprintf(buf + len, max(0, HID_DEBUG_BUFSIZE - len - 1),
"%04x", usage & 0xffff);
else
seq_printf(f, "%04x", usage & 0xffff);
return buf;
}
static void tab(int n, struct seq_file *f) {
seq_printf(f, "%*s", n, "");
}
void hid_dump_field(struct hid_field *field, int n, struct seq_file *f) {
int j;
if (field->physical) {
tab(n, f);
seq_printf(f, "Physical(");
hid_resolv_usage(field->physical, f); seq_printf(f, ")\n");
}
if (field->logical) {
tab(n, f);
seq_printf(f, "Logical(");
hid_resolv_usage(field->logical, f); seq_printf(f, ")\n");
}
tab(n, f); seq_printf(f, "Usage(%d)\n", field->maxusage);
for (j = 0; j < field->maxusage; j++) {
tab(n+2, f); hid_resolv_usage(field->usage[j].hid, f); seq_printf(f, "\n");
}
if (field->logical_minimum != field->logical_maximum) {
tab(n, f); seq_printf(f, "Logical Minimum(%d)\n", field->logical_minimum);
tab(n, f); seq_printf(f, "Logical Maximum(%d)\n", field->logical_maximum);
}
if (field->physical_minimum != field->physical_maximum) {
tab(n, f); seq_printf(f, "Physical Minimum(%d)\n", field->physical_minimum);
tab(n, f); seq_printf(f, "Physical Maximum(%d)\n", field->physical_maximum);
}
if (field->unit_exponent) {
tab(n, f); seq_printf(f, "Unit Exponent(%d)\n", field->unit_exponent);
}
if (field->unit) {
static const char *systems[5] = { "None", "SI Linear", "SI Rotation", "English Linear", "English Rotation" };
static const char *units[5][8] = {
{ "None", "None", "None", "None", "None", "None", "None", "None" },
{ "None", "Centimeter", "Gram", "Seconds", "Kelvin", "Ampere", "Candela", "None" },
{ "None", "Radians", "Gram", "Seconds", "Kelvin", "Ampere", "Candela", "None" },
{ "None", "Inch", "Slug", "Seconds", "Fahrenheit", "Ampere", "Candela", "None" },
{ "None", "Degrees", "Slug", "Seconds", "Fahrenheit", "Ampere", "Candela", "None" }
};
int i;
int sys;
__u32 data = field->unit;
sys = data & 0xf;
data >>= 4;
if(sys > 4) {
tab(n, f); seq_printf(f, "Unit(Invalid)\n");
}
else {
int earlier_unit = 0;
tab(n, f); seq_printf(f, "Unit(%s : ", systems[sys]);
for (i=1 ; i<sizeof(__u32)*2 ; i++) {
char nibble = data & 0xf;
data >>= 4;
if (nibble != 0) {
if(earlier_unit++ > 0)
seq_printf(f, "*");
seq_printf(f, "%s", units[sys][i]);
if(nibble != 1) {
int val = nibble & 0x7;
if(nibble & 0x08)
val = -((0x7 & ~val) +1);
seq_printf(f, "^%d", val);
}
}
}
seq_printf(f, ")\n");
}
}
tab(n, f); seq_printf(f, "Report Size(%u)\n", field->report_size);
tab(n, f); seq_printf(f, "Report Count(%u)\n", field->report_count);
tab(n, f); seq_printf(f, "Report Offset(%u)\n", field->report_offset);
tab(n, f); seq_printf(f, "Flags( ");
j = field->flags;
seq_printf(f, "%s", HID_MAIN_ITEM_CONSTANT & j ? "Constant " : "");
seq_printf(f, "%s", HID_MAIN_ITEM_VARIABLE & j ? "Variable " : "Array ");
seq_printf(f, "%s", HID_MAIN_ITEM_RELATIVE & j ? "Relative " : "Absolute ");
seq_printf(f, "%s", HID_MAIN_ITEM_WRAP & j ? "Wrap " : "");
seq_printf(f, "%s", HID_MAIN_ITEM_NONLINEAR & j ? "NonLinear " : "");
seq_printf(f, "%s", HID_MAIN_ITEM_NO_PREFERRED & j ? "NoPreferredState " : "");
seq_printf(f, "%s", HID_MAIN_ITEM_NULL_STATE & j ? "NullState " : "");
seq_printf(f, "%s", HID_MAIN_ITEM_VOLATILE & j ? "Volatile " : "");
seq_printf(f, "%s", HID_MAIN_ITEM_BUFFERED_BYTE & j ? "BufferedByte " : "");
seq_printf(f, ")\n");
}
void hid_dump_device(struct hid_device *device, struct seq_file *f)
{
struct hid_report_enum *report_enum;
struct hid_report *report;
struct list_head *list;
unsigned i,k;
static const char *table[] = {"INPUT", "OUTPUT", "FEATURE"};
for (i = 0; i < HID_REPORT_TYPES; i++) {
report_enum = device->report_enum + i;
list = report_enum->report_list.next;
while (list != &report_enum->report_list) {
report = (struct hid_report *) list;
tab(2, f);
seq_printf(f, "%s", table[i]);
if (report->id)
seq_printf(f, "(%d)", report->id);
seq_printf(f, "[%s]", table[report->type]);
seq_printf(f, "\n");
for (k = 0; k < report->maxfield; k++) {
tab(4, f);
seq_printf(f, "Field(%d)\n", k);
hid_dump_field(report->field[k], 6, f);
}
list = list->next;
}
}
}
void hid_debug_event(struct hid_device *hdev, char *buf)
{
int i;
struct hid_debug_list *list;
list_for_each_entry(list, &hdev->debug_list, node) {
for (i = 0; i < strlen(buf); i++)
list->hid_debug_buf[(list->tail + i) % HID_DEBUG_BUFSIZE] =
buf[i];
list->tail = (list->tail + i) % HID_DEBUG_BUFSIZE;
}
wake_up_interruptible(&hdev->debug_wait);
}
void hid_dump_input(struct hid_device *hdev, struct hid_usage *usage, __s32 value)
{
char *buf;
int len;
buf = hid_resolv_usage(usage->hid, NULL);
if (!buf)
return;
len = strlen(buf);
snprintf(buf + len, HID_DEBUG_BUFSIZE - len - 1, " = %d\n", value);
hid_debug_event(hdev, buf);
kfree(buf);
wake_up_interruptible(&hdev->debug_wait);
}
static void hid_resolv_event(__u8 type, __u16 code, struct seq_file *f)
{
seq_printf(f, "%s.%s", events[type] ? events[type] : "?",
names[type] ? (names[type][code] ? names[type][code] : "?") : "?");
}
static void hid_dump_input_mapping(struct hid_device *hid, struct seq_file *f)
{
int i, j, k;
struct hid_report *report;
struct hid_usage *usage;
for (k = HID_INPUT_REPORT; k <= HID_OUTPUT_REPORT; k++) {
list_for_each_entry(report, &hid->report_enum[k].report_list, list) {
for (i = 0; i < report->maxfield; i++) {
for ( j = 0; j < report->field[i]->maxusage; j++) {
usage = report->field[i]->usage + j;
hid_resolv_usage(usage->hid, f);
seq_printf(f, " ---> ");
hid_resolv_event(usage->type, usage->code, f);
seq_printf(f, "\n");
}
}
}
}
}
static int hid_debug_rdesc_show(struct seq_file *f, void *p)
{
struct hid_device *hdev = f->private;
int i;
for (i = 0; i < hdev->rsize; i++)
seq_printf(f, "%02x ", hdev->rdesc[i]);
seq_printf(f, "\n\n");
hid_dump_device(hdev, f);
seq_printf(f, "\n");
hid_dump_input_mapping(hdev, f);
return 0;
}
static int hid_debug_rdesc_open(struct inode *inode, struct file *file)
{
return single_open(file, hid_debug_rdesc_show, inode->i_private);
}
static int hid_debug_events_open(struct inode *inode, struct file *file)
{
int err = 0;
struct hid_debug_list *list;
if (!(list = kzalloc(sizeof(struct hid_debug_list), GFP_KERNEL))) {
err = -ENOMEM;
goto out;
}
if (!(list->hid_debug_buf = kzalloc(sizeof(char) * HID_DEBUG_BUFSIZE, GFP_KERNEL))) {
err = -ENOMEM;
kfree(list);
goto out;
}
list->hdev = (struct hid_device *) inode->i_private;
file->private_data = list;
mutex_init(&list->read_mutex);
list_add_tail(&list->node, &list->hdev->debug_list);
out:
return err;
}
static ssize_t hid_debug_events_read(struct file *file, char __user *buffer,
size_t count, loff_t *ppos)
{
struct hid_debug_list *list = file->private_data;
int ret = 0, len;
DECLARE_WAITQUEUE(wait, current);
mutex_lock(&list->read_mutex);
while (ret == 0) {
if (list->head == list->tail) {
add_wait_queue(&list->hdev->debug_wait, &wait);
set_current_state(TASK_INTERRUPTIBLE);
while (list->head == list->tail) {
if (file->f_flags & O_NONBLOCK) {
ret = -EAGAIN;
break;
}
if (signal_pending(current)) {
ret = -ERESTARTSYS;
break;
}
if (!list->hdev || !list->hdev->debug) {
ret = -EIO;
break;
}
mutex_unlock(&list->read_mutex);
schedule();
mutex_lock(&list->read_mutex);
set_current_state(TASK_INTERRUPTIBLE);
}
set_current_state(TASK_RUNNING);
remove_wait_queue(&list->hdev->debug_wait, &wait);
}
if (ret)
goto out;
copy_rest:
if (list->tail == list->head)
goto out;
if (list->tail > list->head) {
len = list->tail - list->head;
if (copy_to_user(buffer + ret, &list->hid_debug_buf[list->head], len)) {
ret = -EFAULT;
goto out;
}
ret += len;
list->head += len;
} else {
len = HID_DEBUG_BUFSIZE - list->head;
if (copy_to_user(buffer, &list->hid_debug_buf[list->head], len)) {
ret = -EFAULT;
goto out;
}
list->head = 0;
ret += len;
goto copy_rest;
}
}
out:
mutex_unlock(&list->read_mutex);
return ret;
}
static unsigned int hid_debug_events_poll(struct file *file, poll_table *wait)
{
struct hid_debug_list *list = file->private_data;
poll_wait(file, &list->hdev->debug_wait, wait);
if (list->head != list->tail)
return POLLIN | POLLRDNORM;
if (!list->hdev->debug)
return POLLERR | POLLHUP;
return 0;
}
static int hid_debug_events_release(struct inode *inode, struct file *file)
{
struct hid_debug_list *list = file->private_data;
list_del(&list->node);
kfree(list->hid_debug_buf);
kfree(list);
return 0;
}
void hid_debug_register(struct hid_device *hdev, const char *name)
{
hdev->debug_dir = debugfs_create_dir(name, hid_debug_root);
hdev->debug_rdesc = debugfs_create_file("rdesc", 0400,
hdev->debug_dir, hdev, &hid_debug_rdesc_fops);
hdev->debug_events = debugfs_create_file("events", 0400,
hdev->debug_dir, hdev, &hid_debug_events_fops);
hdev->debug = 1;
}
void hid_debug_unregister(struct hid_device *hdev)
{
hdev->debug = 0;
wake_up_interruptible(&hdev->debug_wait);
debugfs_remove(hdev->debug_rdesc);
debugfs_remove(hdev->debug_events);
debugfs_remove(hdev->debug_dir);
}
void hid_debug_init(void)
{
hid_debug_root = debugfs_create_dir("hid", NULL);
}
void hid_debug_exit(void)
{
debugfs_remove_recursive(hid_debug_root);
}
