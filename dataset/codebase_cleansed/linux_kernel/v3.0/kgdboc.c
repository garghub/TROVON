static int kgdboc_reset_connect(struct input_handler *handler,
struct input_dev *dev,
const struct input_device_id *id)
{
input_reset_device(dev);
return -ENODEV;
}
static void kgdboc_reset_disconnect(struct input_handle *handle)
{
BUG();
}
static void kgdboc_restore_input_helper(struct work_struct *dummy)
{
mutex_lock(&kgdboc_reset_mutex);
if (input_register_handler(&kgdboc_reset_handler) == 0)
input_unregister_handler(&kgdboc_reset_handler);
mutex_unlock(&kgdboc_reset_mutex);
}
static void kgdboc_restore_input(void)
{
if (likely(system_state == SYSTEM_RUNNING))
schedule_work(&kgdboc_restore_input_work);
}
static int kgdboc_register_kbd(char **cptr)
{
if (strncmp(*cptr, "kbd", 3) == 0) {
if (kdb_poll_idx < KDB_POLL_FUNC_MAX) {
kdb_poll_funcs[kdb_poll_idx] = kdb_get_kbd_char;
kdb_poll_idx++;
if (cptr[0][3] == ',')
*cptr += 4;
else
return 1;
}
}
return 0;
}
static void kgdboc_unregister_kbd(void)
{
int i;
for (i = 0; i < kdb_poll_idx; i++) {
if (kdb_poll_funcs[i] == kdb_get_kbd_char) {
kdb_poll_idx--;
kdb_poll_funcs[i] = kdb_poll_funcs[kdb_poll_idx];
kdb_poll_funcs[kdb_poll_idx] = NULL;
i--;
}
}
flush_work_sync(&kgdboc_restore_input_work);
}
static int kgdboc_option_setup(char *opt)
{
if (strlen(opt) >= MAX_CONFIG_LEN) {
printk(KERN_ERR "kgdboc: config string too long\n");
return -ENOSPC;
}
strcpy(config, opt);
return 0;
}
static void cleanup_kgdboc(void)
{
kgdboc_unregister_kbd();
if (configured == 1)
kgdb_unregister_io_module(&kgdboc_io_ops);
}
static int configure_kgdboc(void)
{
struct tty_driver *p;
int tty_line = 0;
int err;
char *cptr = config;
struct console *cons;
err = kgdboc_option_setup(config);
if (err || !strlen(config) || isspace(config[0]))
goto noconfig;
err = -ENODEV;
kgdboc_io_ops.is_console = 0;
kgdb_tty_driver = NULL;
kgdboc_use_kms = 0;
if (strncmp(cptr, "kms,", 4) == 0) {
cptr += 4;
kgdboc_use_kms = 1;
}
if (kgdboc_register_kbd(&cptr))
goto do_register;
p = tty_find_polling_driver(cptr, &tty_line);
if (!p)
goto noconfig;
cons = console_drivers;
while (cons) {
int idx;
if (cons->device && cons->device(cons, &idx) == p &&
idx == tty_line) {
kgdboc_io_ops.is_console = 1;
break;
}
cons = cons->next;
}
kgdb_tty_driver = p;
kgdb_tty_line = tty_line;
do_register:
err = kgdb_register_io_module(&kgdboc_io_ops);
if (err)
goto noconfig;
configured = 1;
return 0;
noconfig:
config[0] = 0;
configured = 0;
cleanup_kgdboc();
return err;
}
static int __init init_kgdboc(void)
{
if (configured == 1)
return 0;
return configure_kgdboc();
}
static int kgdboc_get_char(void)
{
if (!kgdb_tty_driver)
return -1;
return kgdb_tty_driver->ops->poll_get_char(kgdb_tty_driver,
kgdb_tty_line);
}
static void kgdboc_put_char(u8 chr)
{
if (!kgdb_tty_driver)
return;
kgdb_tty_driver->ops->poll_put_char(kgdb_tty_driver,
kgdb_tty_line, chr);
}
static int param_set_kgdboc_var(const char *kmessage, struct kernel_param *kp)
{
int len = strlen(kmessage);
if (len >= MAX_CONFIG_LEN) {
printk(KERN_ERR "kgdboc: config string too long\n");
return -ENOSPC;
}
if (configured < 0) {
strcpy(config, kmessage);
return 0;
}
if (kgdb_connected) {
printk(KERN_ERR
"kgdboc: Cannot reconfigure while KGDB is connected.\n");
return -EBUSY;
}
strcpy(config, kmessage);
if (config[len - 1] == '\n')
config[len - 1] = '\0';
if (configured == 1)
cleanup_kgdboc();
return configure_kgdboc();
}
static void kgdboc_pre_exp_handler(void)
{
if (!dbg_restore_graphics && kgdboc_use_kms) {
dbg_restore_graphics = 1;
con_debug_enter(vc_cons[fg_console].d);
}
if (!kgdb_connected)
try_module_get(THIS_MODULE);
}
static void kgdboc_post_exp_handler(void)
{
if (!kgdb_connected)
module_put(THIS_MODULE);
if (kgdboc_use_kms && dbg_restore_graphics) {
dbg_restore_graphics = 0;
con_debug_leave();
}
kgdboc_restore_input();
}
static int __init kgdboc_early_init(char *opt)
{
char save_ch;
kgdboc_option_setup(opt);
save_ch = config[0];
init_kgdboc();
config[0] = save_ch;
return 0;
}
