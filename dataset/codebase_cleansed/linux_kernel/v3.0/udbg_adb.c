static inline void udbg_adb_poll(void)
{
#ifdef CONFIG_ADB_PMU
if (input_type == input_adb_pmu)
pmu_poll_adb();
#endif
#ifdef CONFIG_ADB_CUDA
if (input_type == input_adb_cuda)
cuda_poll();
#endif
}
static int udbg_adb_local_getc(void)
{
int k, t, on;
xmon_wants_key = 1;
for (;;) {
xmon_adb_keycode = -1;
t = 0;
on = 0;
k = -1;
do {
if (--t < 0) {
on = 1 - on;
btext_drawchar(on? 0xdb: 0x20);
btext_drawchar('\b');
t = 200000;
}
udbg_adb_poll();
if (udbg_adb_old_getc_poll)
k = udbg_adb_old_getc_poll();
} while (k == -1 && xmon_adb_keycode == -1);
if (on)
btext_drawstring(" \b");
if (k != -1)
return k;
k = xmon_adb_keycode;
if ((k & 0x7f) == 0x38 || (k & 0x7f) == 0x7b) {
xmon_adb_shiftstate = (k & 0x80) == 0;
continue;
}
if (k >= 0x80)
continue;
k = (xmon_adb_shiftstate? xmon_shift_keytab: xmon_keytab)[k];
if (k != 0)
break;
}
xmon_wants_key = 0;
return k;
}
static int udbg_adb_getc(void)
{
#ifdef CONFIG_BOOTX_TEXT
if (udbg_adb_use_btext && input_type != input_adb_none)
return udbg_adb_local_getc();
#endif
if (udbg_adb_old_getc)
return udbg_adb_old_getc();
return -1;
}
static int udbg_adb_getc_poll(void)
{
udbg_adb_poll();
if (udbg_adb_old_getc_poll)
return udbg_adb_old_getc_poll();
return -1;
}
static void udbg_adb_putc(char c)
{
#ifdef CONFIG_BOOTX_TEXT
if (udbg_adb_use_btext)
btext_drawchar(c);
#endif
if (udbg_adb_old_putc)
return udbg_adb_old_putc(c);
}
void __init udbg_adb_init_early(void)
{
#ifdef CONFIG_BOOTX_TEXT
if (btext_find_display(1) == 0) {
udbg_adb_use_btext = 1;
udbg_putc = udbg_adb_putc;
}
#endif
}
int __init udbg_adb_init(int force_btext)
{
struct device_node *np;
udbg_adb_old_putc = udbg_putc;
udbg_adb_old_getc = udbg_getc;
udbg_adb_old_getc_poll = udbg_getc_poll;
if (udbg_adb_old_putc == udbg_adb_putc)
udbg_adb_old_putc = NULL;
#ifdef CONFIG_BOOTX_TEXT
if (udbg_adb_old_putc == btext_drawchar)
udbg_adb_old_putc = NULL;
#endif
udbg_putc = udbg_adb_putc;
udbg_getc = udbg_adb_getc;
udbg_getc_poll = udbg_adb_getc_poll;
#ifdef CONFIG_BOOTX_TEXT
if (btext_find_display(force_btext) == 0)
udbg_adb_use_btext = 1;
#endif
for (np = NULL; (np = of_find_node_by_name(np, "keyboard")) != NULL;) {
struct device_node *parent = of_get_parent(np);
int found = (parent && strcmp(parent->type, "adb") == 0);
of_node_put(parent);
if (found)
break;
}
if (np == NULL)
return -ENODEV;
of_node_put(np);
#ifdef CONFIG_ADB_PMU
if (find_via_pmu())
input_type = input_adb_pmu;
#endif
#ifdef CONFIG_ADB_CUDA
if (find_via_cuda())
input_type = input_adb_cuda;
#endif
if (input_type == input_adb_none)
return -ENODEV;
return 0;
}
