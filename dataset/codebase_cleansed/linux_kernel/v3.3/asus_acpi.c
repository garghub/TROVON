static int write_acpi_int(acpi_handle handle, const char *method, int val,
struct acpi_buffer *output)
{
struct acpi_object_list params;
union acpi_object in_obj;
acpi_status status;
params.count = 1;
params.pointer = &in_obj;
in_obj.type = ACPI_TYPE_INTEGER;
in_obj.integer.value = val;
status = acpi_evaluate_object(handle, (char *)method, &params, output);
return (status == AE_OK);
}
static int read_acpi_int(acpi_handle handle, const char *method, int *val)
{
struct acpi_buffer output;
union acpi_object out_obj;
acpi_status status;
output.length = sizeof(out_obj);
output.pointer = &out_obj;
status = acpi_evaluate_object(handle, (char *)method, NULL, &output);
*val = out_obj.integer.value;
return (status == AE_OK) && (out_obj.type == ACPI_TYPE_INTEGER);
}
static int asus_info_proc_show(struct seq_file *m, void *v)
{
int temp;
seq_printf(m, ACPI_HOTK_NAME " " ASUS_ACPI_VERSION "\n");
seq_printf(m, "Model reference : %s\n", hotk->methods->name);
if (read_acpi_int(hotk->handle, "SFUN", &temp))
seq_printf(m, "SFUN value : 0x%04x\n", temp);
if (read_acpi_int(hotk->handle, "ASYM", &temp))
seq_printf(m, "ASYM value : 0x%04x\n", temp);
if (asus_info) {
seq_printf(m, "DSDT length : %d\n", asus_info->length);
seq_printf(m, "DSDT checksum : %d\n", asus_info->checksum);
seq_printf(m, "DSDT revision : %d\n", asus_info->revision);
seq_printf(m, "OEM id : %.*s\n", ACPI_OEM_ID_SIZE, asus_info->oem_id);
seq_printf(m, "OEM table id : %.*s\n", ACPI_OEM_TABLE_ID_SIZE, asus_info->oem_table_id);
seq_printf(m, "OEM revision : 0x%x\n", asus_info->oem_revision);
seq_printf(m, "ASL comp vendor id : %.*s\n", ACPI_NAME_SIZE, asus_info->asl_compiler_id);
seq_printf(m, "ASL comp revision : 0x%x\n", asus_info->asl_compiler_revision);
}
return 0;
}
static int asus_info_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, asus_info_proc_show, NULL);
}
static int read_led(const char *ledname, int ledmask)
{
if (ledname) {
int led_status;
if (read_acpi_int(NULL, ledname, &led_status))
return led_status;
else
pr_warn("Error reading LED status\n");
}
return (hotk->status & ledmask) ? 1 : 0;
}
static int parse_arg(const char __user *buf, unsigned long count, int *val)
{
char s[32];
if (!count)
return 0;
if (count > 31)
return -EINVAL;
if (copy_from_user(s, buf, count))
return -EFAULT;
s[count] = 0;
if (sscanf(s, "%i", val) != 1)
return -EINVAL;
return count;
}
static int
write_led(const char __user *buffer, unsigned long count,
char *ledname, int ledmask, int invert)
{
int rv, value;
int led_out = 0;
rv = parse_arg(buffer, count, &value);
if (rv > 0)
led_out = value ? 1 : 0;
hotk->status =
(led_out) ? (hotk->status | ledmask) : (hotk->status & ~ledmask);
if (invert)
led_out = !led_out;
if (!write_acpi_int(hotk->handle, ledname, led_out, NULL))
pr_warn("LED (%s) write failed\n", ledname);
return rv;
}
static int mled_proc_show(struct seq_file *m, void *v)
{
seq_printf(m, "%d\n", read_led(hotk->methods->mled_status, MLED_ON));
return 0;
}
static int mled_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, mled_proc_show, NULL);
}
static ssize_t mled_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *pos)
{
return write_led(buffer, count, hotk->methods->mt_mled, MLED_ON, 1);
}
static int ledd_proc_show(struct seq_file *m, void *v)
{
seq_printf(m, "0x%08x\n", hotk->ledd_status);
return 0;
}
static int ledd_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, ledd_proc_show, NULL);
}
static ssize_t ledd_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *pos)
{
int rv, value;
rv = parse_arg(buffer, count, &value);
if (rv > 0) {
if (!write_acpi_int
(hotk->handle, hotk->methods->mt_ledd, value, NULL))
pr_warn("LED display write failed\n");
else
hotk->ledd_status = (u32) value;
}
return rv;
}
static int wled_proc_show(struct seq_file *m, void *v)
{
seq_printf(m, "%d\n", read_led(hotk->methods->wled_status, WLED_ON));
return 0;
}
static int wled_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, wled_proc_show, NULL);
}
static ssize_t wled_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *pos)
{
return write_led(buffer, count, hotk->methods->mt_wled, WLED_ON, 0);
}
static int bluetooth_proc_show(struct seq_file *m, void *v)
{
seq_printf(m, "%d\n", read_led(hotk->methods->bt_status, BT_ON));
return 0;
}
static int bluetooth_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, bluetooth_proc_show, NULL);
}
static ssize_t bluetooth_proc_write(struct file *file,
const char __user *buffer, size_t count, loff_t *pos)
{
return write_led(buffer, count, hotk->methods->mt_bt_switch, BT_ON, 0);
}
static int tled_proc_show(struct seq_file *m, void *v)
{
seq_printf(m, "%d\n", read_led(hotk->methods->tled_status, TLED_ON));
return 0;
}
static int tled_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, tled_proc_show, NULL);
}
static ssize_t tled_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *pos)
{
return write_led(buffer, count, hotk->methods->mt_tled, TLED_ON, 0);
}
static int get_lcd_state(void)
{
int lcd = 0;
if (hotk->model == L3H) {
acpi_status status = 0;
struct acpi_object_list input;
union acpi_object mt_params[2];
struct acpi_buffer output;
union acpi_object out_obj;
input.count = 2;
input.pointer = mt_params;
mt_params[0].type = ACPI_TYPE_INTEGER;
mt_params[0].integer.value = 0x02;
mt_params[1].type = ACPI_TYPE_INTEGER;
mt_params[1].integer.value = 0x02;
output.length = sizeof(out_obj);
output.pointer = &out_obj;
status =
acpi_evaluate_object(NULL, hotk->methods->lcd_status,
&input, &output);
if (status != AE_OK)
return -1;
if (out_obj.type == ACPI_TYPE_INTEGER)
lcd = out_obj.integer.value >> 8;
} else if (hotk->model == F3Sa) {
unsigned long long tmp;
union acpi_object param;
struct acpi_object_list input;
acpi_status status;
param.type = ACPI_TYPE_INTEGER;
param.integer.value = 0x11;
input.count = 1;
input.pointer = &param;
status = acpi_evaluate_integer(NULL, hotk->methods->lcd_status,
&input, &tmp);
if (status != AE_OK)
return -1;
lcd = tmp;
} else {
if (!read_acpi_int(NULL, hotk->methods->lcd_status, &lcd))
pr_warn("Error reading LCD status\n");
if (hotk->model == L2D)
lcd = ~lcd;
}
return (lcd & 1);
}
static int set_lcd_state(int value)
{
int lcd = 0;
acpi_status status = 0;
lcd = value ? 1 : 0;
if (lcd != get_lcd_state()) {
if (hotk->model != L3H) {
status =
acpi_evaluate_object(NULL,
hotk->methods->mt_lcd_switch,
NULL, NULL);
} else {
if (!write_acpi_int
(hotk->handle, hotk->methods->mt_lcd_switch, 0x07,
NULL))
status = AE_ERROR;
}
if (ACPI_FAILURE(status))
pr_warn("Error switching LCD\n");
}
return 0;
}
static int lcd_proc_show(struct seq_file *m, void *v)
{
seq_printf(m, "%d\n", get_lcd_state());
return 0;
}
static int lcd_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, lcd_proc_show, NULL);
}
static ssize_t lcd_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *pos)
{
int rv, value;
rv = parse_arg(buffer, count, &value);
if (rv > 0)
set_lcd_state(value);
return rv;
}
static int read_brightness(struct backlight_device *bd)
{
int value;
if (hotk->methods->brightness_get) {
if (!read_acpi_int(hotk->handle, hotk->methods->brightness_get,
&value))
pr_warn("Error reading brightness\n");
} else if (hotk->methods->brightness_status) {
if (!read_acpi_int(NULL, hotk->methods->brightness_status,
&value))
pr_warn("Error reading brightness\n");
} else
value = hotk->brightness;
return value;
}
static int set_brightness(int value)
{
acpi_status status = 0;
int ret = 0;
if (hotk->methods->brightness_set) {
if (!write_acpi_int(hotk->handle, hotk->methods->brightness_set,
value, NULL)) {
pr_warn("Error changing brightness\n");
ret = -EIO;
}
goto out;
}
value -= read_brightness(NULL);
while (value != 0) {
status = acpi_evaluate_object(NULL, (value > 0) ?
hotk->methods->brightness_up :
hotk->methods->brightness_down,
NULL, NULL);
(value > 0) ? value-- : value++;
if (ACPI_FAILURE(status)) {
pr_warn("Error changing brightness\n");
ret = -EIO;
}
}
out:
return ret;
}
static int set_brightness_status(struct backlight_device *bd)
{
return set_brightness(bd->props.brightness);
}
static int brn_proc_show(struct seq_file *m, void *v)
{
seq_printf(m, "%d\n", read_brightness(NULL));
return 0;
}
static int brn_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, brn_proc_show, NULL);
}
static ssize_t brn_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *pos)
{
int rv, value;
rv = parse_arg(buffer, count, &value);
if (rv > 0) {
value = (0 < value) ? ((15 < value) ? 15 : value) : 0;
set_brightness(value);
}
return rv;
}
static void set_display(int value)
{
if (!write_acpi_int(hotk->handle, hotk->methods->display_set,
value, NULL))
pr_warn("Error setting display\n");
return;
}
static int disp_proc_show(struct seq_file *m, void *v)
{
int value = 0;
if (!read_acpi_int(hotk->handle, hotk->methods->display_get, &value))
pr_warn("Error reading display status\n");
value &= 0x07;
seq_printf(m, "%d\n", value);
return 0;
}
static int disp_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, disp_proc_show, NULL);
}
static ssize_t disp_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *pos)
{
int rv, value;
rv = parse_arg(buffer, count, &value);
if (rv > 0)
set_display(value);
return rv;
}
static int
asus_proc_add(char *name, const struct file_operations *proc_fops, umode_t mode,
struct acpi_device *device)
{
struct proc_dir_entry *proc;
proc = proc_create_data(name, mode, acpi_device_dir(device),
proc_fops, acpi_driver_data(device));
if (!proc) {
pr_warn(" Unable to create %s fs entry\n", name);
return -1;
}
proc->uid = asus_uid;
proc->gid = asus_gid;
return 0;
}
static int asus_hotk_add_fs(struct acpi_device *device)
{
struct proc_dir_entry *proc;
umode_t mode;
if ((asus_uid == 0) && (asus_gid == 0)) {
mode = S_IFREG | S_IRUGO | S_IWUSR | S_IWGRP;
} else {
mode = S_IFREG | S_IRUSR | S_IRGRP | S_IWUSR | S_IWGRP;
pr_warn(" asus_uid and asus_gid parameters are "
"deprecated, use chown and chmod instead!\n");
}
acpi_device_dir(device) = asus_proc_dir;
if (!acpi_device_dir(device))
return -ENODEV;
proc = proc_create(PROC_INFO, mode, acpi_device_dir(device),
&asus_info_proc_fops);
if (proc) {
proc->uid = asus_uid;
proc->gid = asus_gid;
} else {
pr_warn(" Unable to create " PROC_INFO " fs entry\n");
}
if (hotk->methods->mt_wled) {
asus_proc_add(PROC_WLED, &wled_proc_fops, mode, device);
}
if (hotk->methods->mt_ledd) {
asus_proc_add(PROC_LEDD, &ledd_proc_fops, mode, device);
}
if (hotk->methods->mt_mled) {
asus_proc_add(PROC_MLED, &mled_proc_fops, mode, device);
}
if (hotk->methods->mt_tled) {
asus_proc_add(PROC_TLED, &tled_proc_fops, mode, device);
}
if (hotk->methods->mt_bt_switch) {
asus_proc_add(PROC_BT, &bluetooth_proc_fops, mode, device);
}
if (hotk->methods->mt_lcd_switch && hotk->methods->lcd_status) {
asus_proc_add(PROC_LCD, &lcd_proc_fops, mode, device);
}
if ((hotk->methods->brightness_up && hotk->methods->brightness_down) ||
(hotk->methods->brightness_get && hotk->methods->brightness_set)) {
asus_proc_add(PROC_BRN, &brn_proc_fops, mode, device);
}
if (hotk->methods->display_set) {
asus_proc_add(PROC_DISP, &disp_proc_fops, mode, device);
}
return 0;
}
static int asus_hotk_remove_fs(struct acpi_device *device)
{
if (acpi_device_dir(device)) {
remove_proc_entry(PROC_INFO, acpi_device_dir(device));
if (hotk->methods->mt_wled)
remove_proc_entry(PROC_WLED, acpi_device_dir(device));
if (hotk->methods->mt_mled)
remove_proc_entry(PROC_MLED, acpi_device_dir(device));
if (hotk->methods->mt_tled)
remove_proc_entry(PROC_TLED, acpi_device_dir(device));
if (hotk->methods->mt_ledd)
remove_proc_entry(PROC_LEDD, acpi_device_dir(device));
if (hotk->methods->mt_bt_switch)
remove_proc_entry(PROC_BT, acpi_device_dir(device));
if (hotk->methods->mt_lcd_switch && hotk->methods->lcd_status)
remove_proc_entry(PROC_LCD, acpi_device_dir(device));
if ((hotk->methods->brightness_up
&& hotk->methods->brightness_down)
|| (hotk->methods->brightness_get
&& hotk->methods->brightness_set))
remove_proc_entry(PROC_BRN, acpi_device_dir(device));
if (hotk->methods->display_set)
remove_proc_entry(PROC_DISP, acpi_device_dir(device));
}
return 0;
}
static void asus_hotk_notify(struct acpi_device *device, u32 event)
{
if (!hotk)
return;
if (event > ACPI_MAX_SYS_NOTIFY)
return;
if ((event & ~((u32) BR_UP)) < 16)
hotk->brightness = (event & ~((u32) BR_UP));
else if ((event & ~((u32) BR_DOWN)) < 16)
hotk->brightness = (event & ~((u32) BR_DOWN));
acpi_bus_generate_proc_event(hotk->device, event,
hotk->event_count[event % 128]++);
return;
}
static int asus_model_match(char *model)
{
if (model == NULL)
return END_MODEL;
if (strncmp(model, "L3D", 3) == 0)
return L3D;
else if (strncmp(model, "L2E", 3) == 0 ||
strncmp(model, "L3H", 3) == 0 || strncmp(model, "L5D", 3) == 0)
return L3H;
else if (strncmp(model, "L3", 2) == 0 || strncmp(model, "L2B", 3) == 0)
return L3C;
else if (strncmp(model, "L8L", 3) == 0)
return L8L;
else if (strncmp(model, "L4R", 3) == 0)
return L4R;
else if (strncmp(model, "M6N", 3) == 0 || strncmp(model, "W3N", 3) == 0)
return M6N;
else if (strncmp(model, "M6R", 3) == 0 || strncmp(model, "A3G", 3) == 0)
return M6R;
else if (strncmp(model, "M2N", 3) == 0 ||
strncmp(model, "M3N", 3) == 0 ||
strncmp(model, "M5N", 3) == 0 ||
strncmp(model, "S1N", 3) == 0 ||
strncmp(model, "S5N", 3) == 0)
return xxN;
else if (strncmp(model, "M1", 2) == 0)
return M1A;
else if (strncmp(model, "M2", 2) == 0 || strncmp(model, "L4E", 3) == 0)
return M2E;
else if (strncmp(model, "L2", 2) == 0)
return L2D;
else if (strncmp(model, "L8", 2) == 0)
return S1x;
else if (strncmp(model, "D1", 2) == 0)
return D1x;
else if (strncmp(model, "A1", 2) == 0)
return A1x;
else if (strncmp(model, "A2", 2) == 0)
return A2x;
else if (strncmp(model, "J1", 2) == 0)
return S2x;
else if (strncmp(model, "L5", 2) == 0)
return L5x;
else if (strncmp(model, "A4G", 3) == 0)
return A4G;
else if (strncmp(model, "W1N", 3) == 0)
return W1N;
else if (strncmp(model, "W3V", 3) == 0)
return W3V;
else if (strncmp(model, "W5A", 3) == 0)
return W5A;
else if (strncmp(model, "R1F", 3) == 0)
return R1F;
else if (strncmp(model, "A4S", 3) == 0)
return A4S;
else if (strncmp(model, "F3Sa", 4) == 0)
return F3Sa;
else
return END_MODEL;
}
static int asus_hotk_get_info(void)
{
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
union acpi_object *model = NULL;
int bsts_result;
char *string = NULL;
acpi_status status;
status = acpi_get_table(ACPI_SIG_DSDT, 1, &asus_info);
if (ACPI_FAILURE(status))
pr_warn(" Couldn't get the DSDT table header\n");
if (!write_acpi_int(hotk->handle, "INIT", 0, &buffer)) {
pr_err(" Hotkey initialization failed\n");
return -ENODEV;
}
if (!read_acpi_int(hotk->handle, "BSTS", &bsts_result))
pr_warn(" Error calling BSTS\n");
else if (bsts_result)
pr_notice(" BSTS called, 0x%02x returned\n", bsts_result);
if (buffer.pointer) {
model = buffer.pointer;
switch (model->type) {
case ACPI_TYPE_STRING:
string = model->string.pointer;
break;
case ACPI_TYPE_BUFFER:
string = model->buffer.pointer;
break;
default:
kfree(model);
model = NULL;
break;
}
}
hotk->model = asus_model_match(string);
if (hotk->model == END_MODEL) {
if (asus_info &&
strncmp(asus_info->oem_table_id, "ODEM", 4) == 0) {
hotk->model = P30;
pr_notice(" Samsung P30 detected, supported\n");
hotk->methods = &model_conf[hotk->model];
kfree(model);
return 0;
} else {
hotk->model = M2E;
pr_notice(" unsupported model %s, trying default values\n",
string);
pr_notice(" send /proc/acpi/dsdt to the developers\n");
kfree(model);
return -ENODEV;
}
}
hotk->methods = &model_conf[hotk->model];
pr_notice(" %s model detected, supported\n", string);
if (strncmp(string, "L2B", 3) == 0)
hotk->methods->lcd_status = NULL;
else if (strncmp(string, "A3G", 3) == 0)
hotk->methods->lcd_status = "\\BLFG";
else if (strncmp(string, "S5N", 3) == 0 ||
strncmp(string, "M5N", 3) == 0 ||
strncmp(string, "W3N", 3) == 0)
hotk->methods->mt_mled = NULL;
else if (strncmp(string, "L5D", 3) == 0)
hotk->methods->mt_wled = NULL;
else if (strncmp(string, "M2N", 3) == 0 ||
strncmp(string, "W3V", 3) == 0 ||
strncmp(string, "S1N", 3) == 0)
hotk->methods->mt_wled = "WLED";
else if (asus_info) {
if (strncmp(asus_info->oem_table_id, "L1", 2) == 0)
hotk->methods->mled_status = NULL;
}
kfree(model);
return 0;
}
static int asus_hotk_check(void)
{
int result = 0;
result = acpi_bus_get_status(hotk->device);
if (result)
return result;
if (hotk->device->status.present) {
result = asus_hotk_get_info();
} else {
pr_err(" Hotkey device not present, aborting\n");
return -EINVAL;
}
return result;
}
static int asus_hotk_add(struct acpi_device *device)
{
acpi_status status = AE_OK;
int result;
pr_notice("Asus Laptop ACPI Extras version %s\n", ASUS_ACPI_VERSION);
hotk = kzalloc(sizeof(struct asus_hotk), GFP_KERNEL);
if (!hotk)
return -ENOMEM;
hotk->handle = device->handle;
strcpy(acpi_device_name(device), ACPI_HOTK_DEVICE_NAME);
strcpy(acpi_device_class(device), ACPI_HOTK_CLASS);
device->driver_data = hotk;
hotk->device = device;
result = asus_hotk_check();
if (result)
goto end;
result = asus_hotk_add_fs(device);
if (result)
goto end;
if ((!hotk->methods->brightness_get)
&& (!hotk->methods->brightness_status)
&& (hotk->methods->brightness_up && hotk->methods->brightness_down)) {
status =
acpi_evaluate_object(NULL, hotk->methods->brightness_down,
NULL, NULL);
if (ACPI_FAILURE(status))
pr_warn(" Error changing brightness\n");
else {
status =
acpi_evaluate_object(NULL,
hotk->methods->brightness_up,
NULL, NULL);
if (ACPI_FAILURE(status))
pr_warn(" Strange, error changing brightness\n");
}
}
asus_hotk_found = 1;
hotk->ledd_status = 0xFFF;
end:
if (result)
kfree(hotk);
return result;
}
static int asus_hotk_remove(struct acpi_device *device, int type)
{
asus_hotk_remove_fs(device);
kfree(hotk);
return 0;
}
static void asus_acpi_exit(void)
{
if (asus_backlight_device)
backlight_device_unregister(asus_backlight_device);
acpi_bus_unregister_driver(&asus_hotk_driver);
remove_proc_entry(PROC_ASUS, acpi_root_dir);
return;
}
static int __init asus_acpi_init(void)
{
struct backlight_properties props;
int result;
result = acpi_bus_register_driver(&asus_hotk_driver);
if (result < 0)
return result;
asus_proc_dir = proc_mkdir(PROC_ASUS, acpi_root_dir);
if (!asus_proc_dir) {
pr_err("Unable to create /proc entry\n");
acpi_bus_unregister_driver(&asus_hotk_driver);
return -ENODEV;
}
if (!asus_hotk_found) {
acpi_bus_unregister_driver(&asus_hotk_driver);
remove_proc_entry(PROC_ASUS, acpi_root_dir);
return -ENODEV;
}
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_PLATFORM;
props.max_brightness = 15;
asus_backlight_device = backlight_device_register("asus", NULL, NULL,
&asus_backlight_data,
&props);
if (IS_ERR(asus_backlight_device)) {
pr_err("Could not register asus backlight device\n");
asus_backlight_device = NULL;
asus_acpi_exit();
return -ENODEV;
}
return 0;
}
