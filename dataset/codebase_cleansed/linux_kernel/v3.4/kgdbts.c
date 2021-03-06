static int kgdbts_unreg_thread(void *ptr)
{
while (!final_ack)
msleep_interruptible(1500);
msleep_interruptible(1000);
if (configured)
kgdb_unregister_io_module(&kgdbts_io_ops);
configured = 0;
return 0;
}
static noinline void kgdbts_break_test(void)
{
v2printk("kgdbts: breakpoint complete\n");
}
static unsigned long lookup_addr(char *arg)
{
unsigned long addr = 0;
if (!strcmp(arg, "kgdbts_break_test"))
addr = (unsigned long)kgdbts_break_test;
else if (!strcmp(arg, "sys_open"))
addr = (unsigned long)do_sys_open;
else if (!strcmp(arg, "do_fork"))
addr = (unsigned long)do_fork;
else if (!strcmp(arg, "hw_break_val"))
addr = (unsigned long)&hw_break_val;
return addr;
}
static void break_helper(char *bp_type, char *arg, unsigned long vaddr)
{
unsigned long addr;
if (arg)
addr = lookup_addr(arg);
else
addr = vaddr;
sprintf(scratch_buf, "%s,%lx,%i", bp_type, addr,
BREAK_INSTR_SIZE);
fill_get_buf(scratch_buf);
}
static void sw_break(char *arg)
{
break_helper(force_hwbrks ? "Z1" : "Z0", arg, 0);
}
static void sw_rem_break(char *arg)
{
break_helper(force_hwbrks ? "z1" : "z0", arg, 0);
}
static void hw_break(char *arg)
{
break_helper("Z1", arg, 0);
}
static void hw_rem_break(char *arg)
{
break_helper("z1", arg, 0);
}
static void hw_write_break(char *arg)
{
break_helper("Z2", arg, 0);
}
static void hw_rem_write_break(char *arg)
{
break_helper("z2", arg, 0);
}
static void hw_access_break(char *arg)
{
break_helper("Z4", arg, 0);
}
static void hw_rem_access_break(char *arg)
{
break_helper("z4", arg, 0);
}
static void hw_break_val_access(void)
{
hw_break_val2 = hw_break_val;
}
static void hw_break_val_write(void)
{
hw_break_val++;
}
static int get_thread_id_continue(char *put_str, char *arg)
{
char *ptr = &put_str[11];
if (put_str[1] != 'T' || put_str[2] != '0')
return 1;
kgdb_hex2long(&ptr, &cont_thread_id);
return 0;
}
static int check_and_rewind_pc(char *put_str, char *arg)
{
unsigned long addr = lookup_addr(arg);
unsigned long ip;
int offset = 0;
kgdb_hex2mem(&put_str[1], (char *)kgdbts_gdb_regs,
NUMREGBYTES);
gdb_regs_to_pt_regs(kgdbts_gdb_regs, &kgdbts_regs);
ip = instruction_pointer(&kgdbts_regs);
v2printk("Stopped at IP: %lx\n", ip);
#ifdef GDB_ADJUSTS_BREAK_OFFSET
if (addr + BREAK_INSTR_SIZE == ip)
offset = -BREAK_INSTR_SIZE;
#endif
if (arch_needs_sstep_emulation && sstep_addr &&
ip + offset == sstep_addr &&
((!strcmp(arg, "sys_open") || !strcmp(arg, "do_fork")))) {
v2printk("Emul: rewind hit single step bp\n");
restart_from_top_after_write = 1;
} else if (strcmp(arg, "silent") && ip + offset != addr) {
eprintk("kgdbts: BP mismatch %lx expected %lx\n",
ip + offset, addr);
return 1;
}
ip += offset;
cont_addr = ip;
#ifdef GDB_ADJUSTS_BREAK_OFFSET
instruction_pointer_set(&kgdbts_regs, ip);
#endif
return 0;
}
static int check_single_step(char *put_str, char *arg)
{
unsigned long addr = lookup_addr(arg);
static int matched_id;
kgdb_hex2mem(&put_str[1], (char *)kgdbts_gdb_regs,
NUMREGBYTES);
gdb_regs_to_pt_regs(kgdbts_gdb_regs, &kgdbts_regs);
v2printk("Singlestep stopped at IP: %lx\n",
instruction_pointer(&kgdbts_regs));
if (sstep_thread_id != cont_thread_id) {
v2printk("ThrID does not match: %lx\n", cont_thread_id);
if (arch_needs_sstep_emulation) {
if (matched_id &&
instruction_pointer(&kgdbts_regs) != addr)
goto continue_test;
matched_id++;
ts.idx -= 2;
sstep_state = 0;
return 0;
}
cont_instead_of_sstep = 1;
ts.idx -= 4;
return 0;
}
continue_test:
matched_id = 0;
if (instruction_pointer(&kgdbts_regs) == addr) {
eprintk("kgdbts: SingleStep failed at %lx\n",
instruction_pointer(&kgdbts_regs));
return 1;
}
return 0;
}
static void write_regs(char *arg)
{
memset(scratch_buf, 0, sizeof(scratch_buf));
scratch_buf[0] = 'G';
pt_regs_to_gdb_regs(kgdbts_gdb_regs, &kgdbts_regs);
kgdb_mem2hex((char *)kgdbts_gdb_regs, &scratch_buf[1], NUMREGBYTES);
fill_get_buf(scratch_buf);
}
static void skip_back_repeat_test(char *arg)
{
int go_back = simple_strtol(arg, NULL, 10);
repeat_test--;
if (repeat_test <= 0)
ts.idx++;
else
ts.idx -= go_back;
fill_get_buf(ts.tst[ts.idx].get);
}
static int got_break(char *put_str, char *arg)
{
test_complete = 1;
if (!strncmp(put_str+1, arg, 2)) {
if (!strncmp(arg, "T0", 2))
test_complete = 2;
return 0;
}
return 1;
}
static void get_cont_catch(char *arg)
{
fill_get_buf("D");
}
static int put_cont_catch(char *put_str, char *arg)
{
v2printk("kgdbts: cleanup task: %lx\n", sstep_thread_id);
ts.idx--;
return 0;
}
static int emul_reset(char *put_str, char *arg)
{
if (strncmp(put_str, "$OK", 3))
return 1;
if (restart_from_top_after_write) {
restart_from_top_after_write = 0;
ts.idx = -1;
}
return 0;
}
static void emul_sstep_get(char *arg)
{
if (!arch_needs_sstep_emulation) {
if (cont_instead_of_sstep) {
cont_instead_of_sstep = 0;
fill_get_buf("c");
} else {
fill_get_buf(arg);
}
return;
}
switch (sstep_state) {
case 0:
v2printk("Emulate single step\n");
fill_get_buf("g");
break;
case 1:
break_helper("Z0", NULL, sstep_addr);
break;
case 2:
fill_get_buf("c");
break;
case 3:
break_helper("z0", NULL, sstep_addr);
break;
default:
eprintk("kgdbts: ERROR failed sstep get emulation\n");
}
sstep_state++;
}
static int emul_sstep_put(char *put_str, char *arg)
{
if (!arch_needs_sstep_emulation) {
char *ptr = &put_str[11];
if (put_str[1] != 'T' || put_str[2] != '0')
return 1;
kgdb_hex2long(&ptr, &sstep_thread_id);
return 0;
}
switch (sstep_state) {
case 1:
kgdb_hex2mem(&put_str[1], (char *)kgdbts_gdb_regs,
NUMREGBYTES);
gdb_regs_to_pt_regs(kgdbts_gdb_regs, &kgdbts_regs);
v2printk("Stopped at IP: %lx\n",
instruction_pointer(&kgdbts_regs));
sstep_addr = cont_addr + BREAK_INSTR_SIZE;
break;
case 2:
if (strncmp(put_str, "$OK", 3)) {
eprintk("kgdbts: failed sstep break set\n");
return 1;
}
break;
case 3:
if (strncmp(put_str, "$T0", 3)) {
eprintk("kgdbts: failed continue sstep\n");
return 1;
} else {
char *ptr = &put_str[11];
kgdb_hex2long(&ptr, &sstep_thread_id);
}
break;
case 4:
if (strncmp(put_str, "$OK", 3)) {
eprintk("kgdbts: failed sstep break unset\n");
return 1;
}
sstep_state = 0;
return 0;
default:
eprintk("kgdbts: ERROR failed sstep put emulation\n");
}
ts.idx--;
return 0;
}
static int final_ack_set(char *put_str, char *arg)
{
if (strncmp(put_str+1, arg, 2))
return 1;
final_ack = 1;
return 0;
}
static void fill_get_buf(char *buf)
{
unsigned char checksum = 0;
int count = 0;
char ch;
strcpy(get_buf, "$");
strcat(get_buf, buf);
while ((ch = buf[count])) {
checksum += ch;
count++;
}
strcat(get_buf, "#");
get_buf[count + 2] = hex_asc_hi(checksum);
get_buf[count + 3] = hex_asc_lo(checksum);
get_buf[count + 4] = '\0';
v2printk("get%i: %s\n", ts.idx, get_buf);
}
static int validate_simple_test(char *put_str)
{
char *chk_str;
if (ts.tst[ts.idx].put_handler)
return ts.tst[ts.idx].put_handler(put_str,
ts.tst[ts.idx].put);
chk_str = ts.tst[ts.idx].put;
if (*put_str == '$')
put_str++;
while (*chk_str != '\0' && *put_str != '\0') {
if (*put_str == '#' || *chk_str == '*')
return 0;
if (*put_str != *chk_str)
return 1;
chk_str++;
put_str++;
}
if (*chk_str == '\0' && (*put_str == '\0' || *put_str == '#'))
return 0;
return 1;
}
static int run_simple_test(int is_get_char, int chr)
{
int ret = 0;
if (is_get_char) {
if (send_ack) {
send_ack = 0;
return '+';
}
if (get_buf_cnt == 0) {
if (ts.tst[ts.idx].get_handler)
ts.tst[ts.idx].get_handler(ts.tst[ts.idx].get);
else
fill_get_buf(ts.tst[ts.idx].get);
}
if (get_buf[get_buf_cnt] == '\0') {
eprintk("kgdbts: ERROR GET: EOB on '%s' at %i\n",
ts.name, ts.idx);
get_buf_cnt = 0;
fill_get_buf("D");
}
ret = get_buf[get_buf_cnt];
get_buf_cnt++;
return ret;
}
if (ts.tst[ts.idx].get[0] == '\0' && ts.tst[ts.idx].put[0] == '\0' &&
!ts.tst[ts.idx].get_handler) {
eprintk("kgdbts: ERROR: beyond end of test on"
" '%s' line %i\n", ts.name, ts.idx);
return 0;
}
if (put_buf_cnt >= BUFMAX) {
eprintk("kgdbts: ERROR: put buffer overflow on"
" '%s' line %i\n", ts.name, ts.idx);
put_buf_cnt = 0;
return 0;
}
if (put_buf_cnt == 0 && chr != '$')
return 0;
put_buf[put_buf_cnt] = chr;
put_buf_cnt++;
if (put_buf_cnt > 3 && put_buf[put_buf_cnt - 3] == '#') {
if (put_buf_cnt >= BUFMAX) {
eprintk("kgdbts: ERROR: put buffer overflow on"
" '%s' line %i\n", ts.name, ts.idx);
put_buf_cnt = 0;
return 0;
}
put_buf[put_buf_cnt] = '\0';
v2printk("put%i: %s\n", ts.idx, put_buf);
if (ts.validate_put && ts.validate_put(put_buf)) {
eprintk("kgdbts: ERROR PUT: end of test "
"buffer on '%s' line %i expected %s got %s\n",
ts.name, ts.idx, ts.tst[ts.idx].put, put_buf);
}
ts.idx++;
put_buf_cnt = 0;
get_buf_cnt = 0;
send_ack = 1;
}
return 0;
}
static void init_simple_test(void)
{
memset(&ts, 0, sizeof(ts));
ts.run_test = run_simple_test;
ts.validate_put = validate_simple_test;
}
static void run_plant_and_detach_test(int is_early)
{
char before[BREAK_INSTR_SIZE];
char after[BREAK_INSTR_SIZE];
probe_kernel_read(before, (char *)kgdbts_break_test,
BREAK_INSTR_SIZE);
init_simple_test();
ts.tst = plant_and_detach_test;
ts.name = "plant_and_detach_test";
if (!is_early)
kgdb_breakpoint();
probe_kernel_read(after, (char *)kgdbts_break_test,
BREAK_INSTR_SIZE);
if (memcmp(before, after, BREAK_INSTR_SIZE)) {
printk(KERN_CRIT "kgdbts: ERROR kgdb corrupted memory\n");
panic("kgdb memory corruption");
}
if (!is_early)
kgdbts_break_test();
}
static void run_breakpoint_test(int is_hw_breakpoint)
{
test_complete = 0;
init_simple_test();
if (is_hw_breakpoint) {
ts.tst = hw_breakpoint_test;
ts.name = "hw_breakpoint_test";
} else {
ts.tst = sw_breakpoint_test;
ts.name = "sw_breakpoint_test";
}
kgdb_breakpoint();
kgdbts_break_test();
kgdb_breakpoint();
if (test_complete)
return;
eprintk("kgdbts: ERROR %s test failed\n", ts.name);
if (is_hw_breakpoint)
hwbreaks_ok = 0;
}
static void run_hw_break_test(int is_write_test)
{
test_complete = 0;
init_simple_test();
if (is_write_test) {
ts.tst = hw_write_break_test;
ts.name = "hw_write_break_test";
} else {
ts.tst = hw_access_break_test;
ts.name = "hw_access_break_test";
}
kgdb_breakpoint();
hw_break_val_access();
if (is_write_test) {
if (test_complete == 2) {
eprintk("kgdbts: ERROR %s broke on access\n",
ts.name);
hwbreaks_ok = 0;
}
hw_break_val_write();
}
kgdb_breakpoint();
if (test_complete == 1)
return;
eprintk("kgdbts: ERROR %s test failed\n", ts.name);
hwbreaks_ok = 0;
}
static void run_nmi_sleep_test(int nmi_sleep)
{
unsigned long flags;
init_simple_test();
ts.tst = nmi_sleep_test;
ts.name = "nmi_sleep_test";
kgdb_breakpoint();
local_irq_save(flags);
mdelay(nmi_sleep*1000);
touch_nmi_watchdog();
local_irq_restore(flags);
if (test_complete != 2)
eprintk("kgdbts: ERROR nmi_test did not hit nmi\n");
kgdb_breakpoint();
if (test_complete == 1)
return;
eprintk("kgdbts: ERROR %s test failed\n", ts.name);
}
static void run_bad_read_test(void)
{
init_simple_test();
ts.tst = bad_read_test;
ts.name = "bad_read_test";
kgdb_breakpoint();
}
static void run_do_fork_test(void)
{
init_simple_test();
ts.tst = do_fork_test;
ts.name = "do_fork_test";
kgdb_breakpoint();
}
static void run_sys_open_test(void)
{
init_simple_test();
ts.tst = sys_open_test;
ts.name = "sys_open_test";
kgdb_breakpoint();
}
static void run_singlestep_break_test(void)
{
init_simple_test();
ts.tst = singlestep_break_test;
ts.name = "singlestep_breakpoint_test";
kgdb_breakpoint();
kgdbts_break_test();
kgdbts_break_test();
}
static void kgdbts_run_tests(void)
{
char *ptr;
int fork_test = 0;
int do_sys_open_test = 0;
int sstep_test = 1000;
int nmi_sleep = 0;
int i;
ptr = strchr(config, 'F');
if (ptr)
fork_test = simple_strtol(ptr + 1, NULL, 10);
ptr = strchr(config, 'S');
if (ptr)
do_sys_open_test = simple_strtol(ptr + 1, NULL, 10);
ptr = strchr(config, 'N');
if (ptr)
nmi_sleep = simple_strtol(ptr+1, NULL, 10);
ptr = strchr(config, 'I');
if (ptr)
sstep_test = simple_strtol(ptr+1, NULL, 10);
if (arch_kgdb_ops.flags & KGDB_HW_BREAKPOINT) {
hwbreaks_ok = 1;
v1printk("kgdbts:RUN hw breakpoint test\n");
run_breakpoint_test(1);
v1printk("kgdbts:RUN hw write breakpoint test\n");
run_hw_break_test(1);
v1printk("kgdbts:RUN access write breakpoint test\n");
run_hw_break_test(0);
}
v1printk("kgdbts:RUN plant and detach test\n");
run_plant_and_detach_test(0);
v1printk("kgdbts:RUN sw breakpoint test\n");
run_breakpoint_test(0);
v1printk("kgdbts:RUN bad memory access test\n");
run_bad_read_test();
v1printk("kgdbts:RUN singlestep test %i iterations\n", sstep_test);
for (i = 0; i < sstep_test; i++) {
run_singlestep_break_test();
if (i % 100 == 0)
v1printk("kgdbts:RUN singlestep [%i/%i]\n",
i, sstep_test);
}
if (nmi_sleep) {
v1printk("kgdbts:RUN NMI sleep %i seconds test\n", nmi_sleep);
run_nmi_sleep_test(nmi_sleep);
}
if (fork_test) {
repeat_test = fork_test;
printk(KERN_INFO "kgdbts:RUN do_fork for %i breakpoints\n",
repeat_test);
kthread_run(kgdbts_unreg_thread, NULL, "kgdbts_unreg");
run_do_fork_test();
return;
}
if (do_sys_open_test) {
repeat_test = do_sys_open_test;
printk(KERN_INFO "kgdbts:RUN sys_open for %i breakpoints\n",
repeat_test);
kthread_run(kgdbts_unreg_thread, NULL, "kgdbts_unreg");
run_sys_open_test();
return;
}
kgdb_unregister_io_module(&kgdbts_io_ops);
configured = 0;
}
static int kgdbts_option_setup(char *opt)
{
if (strlen(opt) >= MAX_CONFIG_LEN) {
printk(KERN_ERR "kgdbts: config string too long\n");
return -ENOSPC;
}
strcpy(config, opt);
verbose = 0;
if (strstr(config, "V1"))
verbose = 1;
if (strstr(config, "V2"))
verbose = 2;
return 0;
}
static int configure_kgdbts(void)
{
int err = 0;
if (!strlen(config) || isspace(config[0]))
goto noconfig;
err = kgdbts_option_setup(config);
if (err)
goto noconfig;
final_ack = 0;
run_plant_and_detach_test(1);
err = kgdb_register_io_module(&kgdbts_io_ops);
if (err) {
configured = 0;
return err;
}
configured = 1;
kgdbts_run_tests();
return err;
noconfig:
config[0] = 0;
configured = 0;
return err;
}
static int __init init_kgdbts(void)
{
if (configured == 1)
return 0;
return configure_kgdbts();
}
static int kgdbts_get_char(void)
{
int val = 0;
if (ts.run_test)
val = ts.run_test(1, 0);
return val;
}
static void kgdbts_put_char(u8 chr)
{
if (ts.run_test)
ts.run_test(0, chr);
}
static int param_set_kgdbts_var(const char *kmessage, struct kernel_param *kp)
{
int len = strlen(kmessage);
if (len >= MAX_CONFIG_LEN) {
printk(KERN_ERR "kgdbts: config string too long\n");
return -ENOSPC;
}
if (configured < 0) {
strcpy(config, kmessage);
return 0;
}
if (configured == 1) {
printk(KERN_ERR "kgdbts: ERROR: Already configured and running.\n");
return -EBUSY;
}
strcpy(config, kmessage);
if (config[len - 1] == '\n')
config[len - 1] = '\0';
return configure_kgdbts();
}
static void kgdbts_pre_exp_handler(void)
{
if (!kgdb_connected)
try_module_get(THIS_MODULE);
}
static void kgdbts_post_exp_handler(void)
{
if (!kgdb_connected)
module_put(THIS_MODULE);
}
