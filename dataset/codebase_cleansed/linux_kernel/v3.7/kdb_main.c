struct task_struct *kdb_curr_task(int cpu)
{
struct task_struct *p = curr_task(cpu);
#ifdef _TIF_MCA_INIT
if ((task_thread_info(p)->flags & _TIF_MCA_INIT) && KDB_TSK(cpu))
p = krp->p;
#endif
return p;
}
char *kdbgetenv(const char *match)
{
char **ep = __env;
int matchlen = strlen(match);
int i;
for (i = 0; i < __nenv; i++) {
char *e = *ep++;
if (!e)
continue;
if ((strncmp(match, e, matchlen) == 0)
&& ((e[matchlen] == '\0')
|| (e[matchlen] == '='))) {
char *cp = strchr(e, '=');
return cp ? ++cp : "";
}
}
return NULL;
}
static char *kdballocenv(size_t bytes)
{
#define KDB_ENVBUFSIZE 512
static char envbuffer[KDB_ENVBUFSIZE];
static int envbufsize;
char *ep = NULL;
if ((KDB_ENVBUFSIZE - envbufsize) >= bytes) {
ep = &envbuffer[envbufsize];
envbufsize += bytes;
}
return ep;
}
static int kdbgetulenv(const char *match, unsigned long *value)
{
char *ep;
ep = kdbgetenv(match);
if (!ep)
return KDB_NOTENV;
if (strlen(ep) == 0)
return KDB_NOENVVALUE;
*value = simple_strtoul(ep, NULL, 0);
return 0;
}
int kdbgetintenv(const char *match, int *value)
{
unsigned long val;
int diag;
diag = kdbgetulenv(match, &val);
if (!diag)
*value = (int) val;
return diag;
}
int kdbgetularg(const char *arg, unsigned long *value)
{
char *endp;
unsigned long val;
val = simple_strtoul(arg, &endp, 0);
if (endp == arg) {
val = simple_strtoul(arg, &endp, 16);
if (endp == arg)
return KDB_BADINT;
}
*value = val;
return 0;
}
int kdbgetu64arg(const char *arg, u64 *value)
{
char *endp;
u64 val;
val = simple_strtoull(arg, &endp, 0);
if (endp == arg) {
val = simple_strtoull(arg, &endp, 16);
if (endp == arg)
return KDB_BADINT;
}
*value = val;
return 0;
}
int kdb_set(int argc, const char **argv)
{
int i;
char *ep;
size_t varlen, vallen;
if (argc == 3) {
argv[2] = argv[3];
argc--;
}
if (argc != 2)
return KDB_ARGCOUNT;
if (strcmp(argv[1], "KDBDEBUG") == 0) {
unsigned int debugflags;
char *cp;
debugflags = simple_strtoul(argv[2], &cp, 0);
if (cp == argv[2] || debugflags & ~KDB_DEBUG_FLAG_MASK) {
kdb_printf("kdb: illegal debug flags '%s'\n",
argv[2]);
return 0;
}
kdb_flags = (kdb_flags &
~(KDB_DEBUG_FLAG_MASK << KDB_DEBUG_FLAG_SHIFT))
| (debugflags << KDB_DEBUG_FLAG_SHIFT);
return 0;
}
varlen = strlen(argv[1]);
vallen = strlen(argv[2]);
ep = kdballocenv(varlen + vallen + 2);
if (ep == (char *)0)
return KDB_ENVBUFFULL;
sprintf(ep, "%s=%s", argv[1], argv[2]);
ep[varlen+vallen+1] = '\0';
for (i = 0; i < __nenv; i++) {
if (__env[i]
&& ((strncmp(__env[i], argv[1], varlen) == 0)
&& ((__env[i][varlen] == '\0')
|| (__env[i][varlen] == '=')))) {
__env[i] = ep;
return 0;
}
}
for (i = 0; i < __nenv-1; i++) {
if (__env[i] == (char *)0) {
__env[i] = ep;
return 0;
}
}
return KDB_ENVFULL;
}
static int kdb_check_regs(void)
{
if (!kdb_current_regs) {
kdb_printf("No current kdb registers."
" You may need to select another task\n");
return KDB_BADREG;
}
return 0;
}
int kdbgetaddrarg(int argc, const char **argv, int *nextarg,
unsigned long *value, long *offset,
char **name)
{
unsigned long addr;
unsigned long off = 0;
int positive;
int diag;
int found = 0;
char *symname;
char symbol = '\0';
char *cp;
kdb_symtab_t symtab;
if (*nextarg > argc)
return KDB_ARGCOUNT;
symname = (char *)argv[*nextarg];
cp = strpbrk(symname, "+-");
if (cp != NULL) {
symbol = *cp;
*cp++ = '\0';
}
if (symname[0] == '$') {
diag = kdbgetulenv(&symname[1], &addr);
if (diag)
return diag;
} else if (symname[0] == '%') {
diag = kdb_check_regs();
if (diag)
return diag;
return KDB_NOTIMP;
} else {
found = kdbgetsymval(symname, &symtab);
if (found) {
addr = symtab.sym_start;
} else {
diag = kdbgetularg(argv[*nextarg], &addr);
if (diag)
return diag;
}
}
if (!found)
found = kdbnearsym(addr, &symtab);
(*nextarg)++;
if (name)
*name = symname;
if (value)
*value = addr;
if (offset && name && *name)
*offset = addr - symtab.sym_start;
if ((*nextarg > argc)
&& (symbol == '\0'))
return 0;
if (symbol == '\0') {
if ((argv[*nextarg][0] != '+')
&& (argv[*nextarg][0] != '-')) {
return 0;
} else {
positive = (argv[*nextarg][0] == '+');
(*nextarg)++;
}
} else
positive = (symbol == '+');
if ((*nextarg > argc)
&& (symbol == '\0')) {
return KDB_INVADDRFMT;
}
if (!symbol) {
cp = (char *)argv[*nextarg];
(*nextarg)++;
}
diag = kdbgetularg(cp, &off);
if (diag)
return diag;
if (!positive)
off = -off;
if (offset)
*offset += off;
if (value)
*value += off;
return 0;
}
static void kdb_cmderror(int diag)
{
int i;
if (diag >= 0) {
kdb_printf("no error detected (diagnostic is %d)\n", diag);
return;
}
for (i = 0; i < __nkdb_err; i++) {
if (kdbmsgs[i].km_diag == diag) {
kdb_printf("diag: %d: %s\n", diag, kdbmsgs[i].km_msg);
return;
}
}
kdb_printf("Unknown diag %d\n", -diag);
}
static int kdb_defcmd2(const char *cmdstr, const char *argv0)
{
struct defcmd_set *s = defcmd_set + defcmd_set_count - 1;
char **save_command = s->command;
if (strcmp(argv0, "endefcmd") == 0) {
defcmd_in_progress = 0;
if (!s->count)
s->usable = 0;
if (s->usable)
kdb_register(s->name, kdb_exec_defcmd,
s->usage, s->help, 0);
return 0;
}
if (!s->usable)
return KDB_NOTIMP;
s->command = kzalloc((s->count + 1) * sizeof(*(s->command)), GFP_KDB);
if (!s->command) {
kdb_printf("Could not allocate new kdb_defcmd table for %s\n",
cmdstr);
s->usable = 0;
return KDB_NOTIMP;
}
memcpy(s->command, save_command, s->count * sizeof(*(s->command)));
s->command[s->count++] = kdb_strdup(cmdstr, GFP_KDB);
kfree(save_command);
return 0;
}
static int kdb_defcmd(int argc, const char **argv)
{
struct defcmd_set *save_defcmd_set = defcmd_set, *s;
if (defcmd_in_progress) {
kdb_printf("kdb: nested defcmd detected, assuming missing "
"endefcmd\n");
kdb_defcmd2("endefcmd", "endefcmd");
}
if (argc == 0) {
int i;
for (s = defcmd_set; s < defcmd_set + defcmd_set_count; ++s) {
kdb_printf("defcmd %s \"%s\" \"%s\"\n", s->name,
s->usage, s->help);
for (i = 0; i < s->count; ++i)
kdb_printf("%s", s->command[i]);
kdb_printf("endefcmd\n");
}
return 0;
}
if (argc != 3)
return KDB_ARGCOUNT;
defcmd_set = kmalloc((defcmd_set_count + 1) * sizeof(*defcmd_set),
GFP_KDB);
if (!defcmd_set) {
kdb_printf("Could not allocate new defcmd_set entry for %s\n",
argv[1]);
defcmd_set = save_defcmd_set;
return KDB_NOTIMP;
}
memcpy(defcmd_set, save_defcmd_set,
defcmd_set_count * sizeof(*defcmd_set));
kfree(save_defcmd_set);
s = defcmd_set + defcmd_set_count;
memset(s, 0, sizeof(*s));
s->usable = 1;
s->name = kdb_strdup(argv[1], GFP_KDB);
s->usage = kdb_strdup(argv[2], GFP_KDB);
s->help = kdb_strdup(argv[3], GFP_KDB);
if (s->usage[0] == '"') {
strcpy(s->usage, s->usage+1);
s->usage[strlen(s->usage)-1] = '\0';
}
if (s->help[0] == '"') {
strcpy(s->help, s->help+1);
s->help[strlen(s->help)-1] = '\0';
}
++defcmd_set_count;
defcmd_in_progress = 1;
return 0;
}
static int kdb_exec_defcmd(int argc, const char **argv)
{
int i, ret;
struct defcmd_set *s;
if (argc != 0)
return KDB_ARGCOUNT;
for (s = defcmd_set, i = 0; i < defcmd_set_count; ++i, ++s) {
if (strcmp(s->name, argv[0]) == 0)
break;
}
if (i == defcmd_set_count) {
kdb_printf("kdb_exec_defcmd: could not find commands for %s\n",
argv[0]);
return KDB_NOTIMP;
}
for (i = 0; i < s->count; ++i) {
argv = NULL;
kdb_printf("[%s]kdb> %s\n", s->name, s->command[i]);
ret = kdb_parse(s->command[i]);
if (ret)
return ret;
}
return 0;
}
static void parse_grep(const char *str)
{
int len;
char *cp = (char *)str, *cp2;
if (*cp != '|')
return;
cp++;
while (isspace(*cp))
cp++;
if (strncmp(cp, "grep ", 5)) {
kdb_printf("invalid 'pipe', see grephelp\n");
return;
}
cp += 5;
while (isspace(*cp))
cp++;
cp2 = strchr(cp, '\n');
if (cp2)
*cp2 = '\0';
len = strlen(cp);
if (len == 0) {
kdb_printf("invalid 'pipe', see grephelp\n");
return;
}
if (*cp == '"') {
cp++;
cp2 = strchr(cp, '"');
if (!cp2) {
kdb_printf("invalid quoted string, see grephelp\n");
return;
}
*cp2 = '\0';
}
kdb_grep_leading = 0;
if (*cp == '^') {
kdb_grep_leading = 1;
cp++;
}
len = strlen(cp);
kdb_grep_trailing = 0;
if (*(cp+len-1) == '$') {
kdb_grep_trailing = 1;
*(cp+len-1) = '\0';
}
len = strlen(cp);
if (!len)
return;
if (len >= GREP_LEN) {
kdb_printf("search string too long\n");
return;
}
strcpy(kdb_grep_string, cp);
kdb_grepping_flag++;
return;
}
int kdb_parse(const char *cmdstr)
{
static char *argv[MAXARGC];
static int argc;
static char cbuf[CMD_BUFLEN+2];
char *cp;
char *cpp, quoted;
kdbtab_t *tp;
int i, escaped, ignore_errors = 0, check_grep;
cp = (char *)cmdstr;
kdb_grepping_flag = check_grep = 0;
if (KDB_FLAG(CMD_INTERRUPT)) {
KDB_FLAG_CLEAR(CMD_INTERRUPT);
KDB_STATE_SET(PAGER);
argc = 0;
}
if (*cp != '\n' && *cp != '\0') {
argc = 0;
cpp = cbuf;
while (*cp) {
while (isspace(*cp))
cp++;
if ((*cp == '\0') || (*cp == '\n') ||
(*cp == '#' && !defcmd_in_progress))
break;
if (*cp == '|') {
check_grep++;
break;
}
if (cpp >= cbuf + CMD_BUFLEN) {
kdb_printf("kdb_parse: command buffer "
"overflow, command ignored\n%s\n",
cmdstr);
return KDB_NOTFOUND;
}
if (argc >= MAXARGC - 1) {
kdb_printf("kdb_parse: too many arguments, "
"command ignored\n%s\n", cmdstr);
return KDB_NOTFOUND;
}
argv[argc++] = cpp;
escaped = 0;
quoted = '\0';
while (*cp && *cp != '\n' &&
(escaped || quoted || !isspace(*cp))) {
if (cpp >= cbuf + CMD_BUFLEN)
break;
if (escaped) {
escaped = 0;
*cpp++ = *cp++;
continue;
}
if (*cp == '\\') {
escaped = 1;
++cp;
continue;
}
if (*cp == quoted)
quoted = '\0';
else if (*cp == '\'' || *cp == '"')
quoted = *cp;
*cpp = *cp++;
if (*cpp == '=' && !quoted)
break;
++cpp;
}
*cpp++ = '\0';
}
}
if (!argc)
return 0;
if (check_grep)
parse_grep(cp);
if (defcmd_in_progress) {
int result = kdb_defcmd2(cmdstr, argv[0]);
if (!defcmd_in_progress) {
argc = 0;
*(argv[0]) = '\0';
}
return result;
}
if (argv[0][0] == '-' && argv[0][1] &&
(argv[0][1] < '0' || argv[0][1] > '9')) {
ignore_errors = 1;
++argv[0];
}
for_each_kdbcmd(tp, i) {
if (tp->cmd_name) {
if (tp->cmd_minlen
&& (strlen(argv[0]) <= tp->cmd_minlen)) {
if (strncmp(argv[0],
tp->cmd_name,
tp->cmd_minlen) == 0) {
break;
}
}
if (strcmp(argv[0], tp->cmd_name) == 0)
break;
}
}
if (i == kdb_max_commands) {
for_each_kdbcmd(tp, i) {
if (tp->cmd_name) {
if (strncmp(argv[0],
tp->cmd_name,
strlen(tp->cmd_name)) == 0) {
break;
}
}
}
}
if (i < kdb_max_commands) {
int result;
KDB_STATE_SET(CMD);
result = (*tp->cmd_func)(argc-1, (const char **)argv);
if (result && ignore_errors && result > KDB_CMD_GO)
result = 0;
KDB_STATE_CLEAR(CMD);
switch (tp->cmd_repeat) {
case KDB_REPEAT_NONE:
argc = 0;
if (argv[0])
*(argv[0]) = '\0';
break;
case KDB_REPEAT_NO_ARGS:
argc = 1;
if (argv[1])
*(argv[1]) = '\0';
break;
case KDB_REPEAT_WITH_ARGS:
break;
}
return result;
}
{
unsigned long value;
char *name = NULL;
long offset;
int nextarg = 0;
if (kdbgetaddrarg(0, (const char **)argv, &nextarg,
&value, &offset, &name)) {
return KDB_NOTFOUND;
}
kdb_printf("%s = ", argv[0]);
kdb_symbol_print(value, NULL, KDB_SP_DEFAULT);
kdb_printf("\n");
return 0;
}
}
static int handle_ctrl_cmd(char *cmd)
{
#define CTRL_P 16
#define CTRL_N 14
if (cmd_head == cmd_tail)
return 0;
switch (*cmd) {
case CTRL_P:
if (cmdptr != cmd_tail)
cmdptr = (cmdptr-1) % KDB_CMD_HISTORY_COUNT;
strncpy(cmd_cur, cmd_hist[cmdptr], CMD_BUFLEN);
return 1;
case CTRL_N:
if (cmdptr != cmd_head)
cmdptr = (cmdptr+1) % KDB_CMD_HISTORY_COUNT;
strncpy(cmd_cur, cmd_hist[cmdptr], CMD_BUFLEN);
return 1;
}
return 0;
}
static int kdb_reboot(int argc, const char **argv)
{
emergency_restart();
kdb_printf("Hmm, kdb_reboot did not reboot, spinning here\n");
while (1)
cpu_relax();
return 0;
}
static void kdb_dumpregs(struct pt_regs *regs)
{
int old_lvl = console_loglevel;
console_loglevel = 15;
kdb_trap_printk++;
show_regs(regs);
kdb_trap_printk--;
kdb_printf("\n");
console_loglevel = old_lvl;
}
void kdb_set_current_task(struct task_struct *p)
{
kdb_current_task = p;
if (kdb_task_has_cpu(p)) {
kdb_current_regs = KDB_TSKREGS(kdb_process_cpu(p));
return;
}
kdb_current_regs = NULL;
}
static int kdb_local(kdb_reason_t reason, int error, struct pt_regs *regs,
kdb_dbtrap_t db_result)
{
char *cmdbuf;
int diag;
struct task_struct *kdb_current =
kdb_curr_task(raw_smp_processor_id());
KDB_DEBUG_STATE("kdb_local 1", reason);
kdb_go_count = 0;
if (reason == KDB_REASON_DEBUG) {
} else {
kdb_printf("\nEntering kdb (current=0x%p, pid %d) ",
kdb_current, kdb_current ? kdb_current->pid : 0);
#if defined(CONFIG_SMP)
kdb_printf("on processor %d ", raw_smp_processor_id());
#endif
}
switch (reason) {
case KDB_REASON_DEBUG:
{
switch (db_result) {
case KDB_DB_BPT:
kdb_printf("\nEntering kdb (0x%p, pid %d) ",
kdb_current, kdb_current->pid);
#if defined(CONFIG_SMP)
kdb_printf("on processor %d ", raw_smp_processor_id());
#endif
kdb_printf("due to Debug @ " kdb_machreg_fmt "\n",
instruction_pointer(regs));
break;
case KDB_DB_SSB:
KDB_DEBUG_STATE("kdb_local 3", reason);
return KDB_CMD_SSB;
break;
case KDB_DB_SS:
break;
case KDB_DB_SSBPT:
KDB_DEBUG_STATE("kdb_local 4", reason);
return 1;
default:
kdb_printf("kdb: Bad result from kdba_db_trap: %d\n",
db_result);
break;
}
}
break;
case KDB_REASON_ENTER:
if (KDB_STATE(KEYBOARD))
kdb_printf("due to Keyboard Entry\n");
else
kdb_printf("due to KDB_ENTER()\n");
break;
case KDB_REASON_KEYBOARD:
KDB_STATE_SET(KEYBOARD);
kdb_printf("due to Keyboard Entry\n");
break;
case KDB_REASON_ENTER_SLAVE:
case KDB_REASON_SWITCH:
kdb_printf("due to cpu switch\n");
break;
case KDB_REASON_OOPS:
kdb_printf("Oops: %s\n", kdb_diemsg);
kdb_printf("due to oops @ " kdb_machreg_fmt "\n",
instruction_pointer(regs));
kdb_dumpregs(regs);
break;
case KDB_REASON_NMI:
kdb_printf("due to NonMaskable Interrupt @ "
kdb_machreg_fmt "\n",
instruction_pointer(regs));
kdb_dumpregs(regs);
break;
case KDB_REASON_SSTEP:
case KDB_REASON_BREAK:
kdb_printf("due to %s @ " kdb_machreg_fmt "\n",
reason == KDB_REASON_BREAK ?
"Breakpoint" : "SS trap", instruction_pointer(regs));
if (db_result != KDB_DB_BPT) {
kdb_printf("kdb: error return from kdba_bp_trap: %d\n",
db_result);
KDB_DEBUG_STATE("kdb_local 6", reason);
return 0;
}
break;
case KDB_REASON_RECURSE:
kdb_printf("due to Recursion @ " kdb_machreg_fmt "\n",
instruction_pointer(regs));
break;
default:
kdb_printf("kdb: unexpected reason code: %d\n", reason);
KDB_DEBUG_STATE("kdb_local 8", reason);
return 0;
}
while (1) {
kdb_nextline = 1;
KDB_STATE_CLEAR(SUPPRESS);
cmdbuf = cmd_cur;
*cmdbuf = '\0';
*(cmd_hist[cmd_head]) = '\0';
do_full_getstr:
#if defined(CONFIG_SMP)
snprintf(kdb_prompt_str, CMD_BUFLEN, kdbgetenv("PROMPT"),
raw_smp_processor_id());
#else
snprintf(kdb_prompt_str, CMD_BUFLEN, kdbgetenv("PROMPT"));
#endif
if (defcmd_in_progress)
strncat(kdb_prompt_str, "[defcmd]", CMD_BUFLEN);
cmdbuf = kdb_getstr(cmdbuf, CMD_BUFLEN, kdb_prompt_str);
if (*cmdbuf != '\n') {
if (*cmdbuf < 32) {
if (cmdptr == cmd_head) {
strncpy(cmd_hist[cmd_head], cmd_cur,
CMD_BUFLEN);
*(cmd_hist[cmd_head] +
strlen(cmd_hist[cmd_head])-1) = '\0';
}
if (!handle_ctrl_cmd(cmdbuf))
*(cmd_cur+strlen(cmd_cur)-1) = '\0';
cmdbuf = cmd_cur;
goto do_full_getstr;
} else {
strncpy(cmd_hist[cmd_head], cmd_cur,
CMD_BUFLEN);
}
cmd_head = (cmd_head+1) % KDB_CMD_HISTORY_COUNT;
if (cmd_head == cmd_tail)
cmd_tail = (cmd_tail+1) % KDB_CMD_HISTORY_COUNT;
}
cmdptr = cmd_head;
diag = kdb_parse(cmdbuf);
if (diag == KDB_NOTFOUND) {
kdb_printf("Unknown kdb command: '%s'\n", cmdbuf);
diag = 0;
}
if (diag == KDB_CMD_GO
|| diag == KDB_CMD_CPU
|| diag == KDB_CMD_SS
|| diag == KDB_CMD_SSB
|| diag == KDB_CMD_KGDB)
break;
if (diag)
kdb_cmderror(diag);
}
KDB_DEBUG_STATE("kdb_local 9", diag);
return diag;
}
void kdb_print_state(const char *text, int value)
{
kdb_printf("state: %s cpu %d value %d initial %d state %x\n",
text, raw_smp_processor_id(), value, kdb_initial_cpu,
kdb_state);
}
int kdb_main_loop(kdb_reason_t reason, kdb_reason_t reason2, int error,
kdb_dbtrap_t db_result, struct pt_regs *regs)
{
int result = 1;
while (1) {
KDB_DEBUG_STATE("kdb_main_loop 1", reason);
while (KDB_STATE(HOLD_CPU)) {
if (!KDB_STATE(KDB))
KDB_STATE_SET(KDB);
}
KDB_STATE_CLEAR(SUPPRESS);
KDB_DEBUG_STATE("kdb_main_loop 2", reason);
if (KDB_STATE(LEAVING))
break;
result = kdb_local(reason2, error, regs, db_result);
KDB_DEBUG_STATE("kdb_main_loop 3", result);
if (result == KDB_CMD_CPU)
break;
if (result == KDB_CMD_SS) {
KDB_STATE_SET(DOING_SS);
break;
}
if (result == KDB_CMD_SSB) {
KDB_STATE_SET(DOING_SS);
KDB_STATE_SET(DOING_SSB);
break;
}
if (result == KDB_CMD_KGDB) {
if (!KDB_STATE(DOING_KGDB))
kdb_printf("Entering please attach debugger "
"or use $D#44+ or $3#33\n");
break;
}
if (result && result != 1 && result != KDB_CMD_GO)
kdb_printf("\nUnexpected kdb_local return code %d\n",
result);
KDB_DEBUG_STATE("kdb_main_loop 4", reason);
break;
}
if (KDB_STATE(DOING_SS))
KDB_STATE_CLEAR(SSBPT);
kdb_kbd_cleanup_state();
return result;
}
static int kdb_mdr(unsigned long addr, unsigned int count)
{
unsigned char c;
while (count--) {
if (kdb_getarea(c, addr))
return 0;
kdb_printf("%02x", c);
addr++;
}
kdb_printf("\n");
return 0;
}
static void kdb_md_line(const char *fmtstr, unsigned long addr,
int symbolic, int nosect, int bytesperword,
int num, int repeat, int phys)
{
kdb_symtab_t symtab;
char cbuf[32];
char *c = cbuf;
int i;
unsigned long word;
memset(cbuf, '\0', sizeof(cbuf));
if (phys)
kdb_printf("phys " kdb_machreg_fmt0 " ", addr);
else
kdb_printf(kdb_machreg_fmt0 " ", addr);
for (i = 0; i < num && repeat--; i++) {
if (phys) {
if (kdb_getphysword(&word, addr, bytesperword))
break;
} else if (kdb_getword(&word, addr, bytesperword))
break;
kdb_printf(fmtstr, word);
if (symbolic)
kdbnearsym(word, &symtab);
else
memset(&symtab, 0, sizeof(symtab));
if (symtab.sym_name) {
kdb_symbol_print(word, &symtab, 0);
if (!nosect) {
kdb_printf("\n");
kdb_printf(" %s %s "
kdb_machreg_fmt " "
kdb_machreg_fmt " "
kdb_machreg_fmt, symtab.mod_name,
symtab.sec_name, symtab.sec_start,
symtab.sym_start, symtab.sym_end);
}
addr += bytesperword;
} else {
union {
u64 word;
unsigned char c[8];
} wc;
unsigned char *cp;
#ifdef __BIG_ENDIAN
cp = wc.c + 8 - bytesperword;
#else
cp = wc.c;
#endif
wc.word = word;
#define printable_char(c) \
({unsigned char __c = c; isascii(__c) && isprint(__c) ? __c : '.'; })
switch (bytesperword) {
case 8:
*c++ = printable_char(*cp++);
*c++ = printable_char(*cp++);
*c++ = printable_char(*cp++);
*c++ = printable_char(*cp++);
addr += 4;
case 4:
*c++ = printable_char(*cp++);
*c++ = printable_char(*cp++);
addr += 2;
case 2:
*c++ = printable_char(*cp++);
addr++;
case 1:
*c++ = printable_char(*cp++);
addr++;
break;
}
#undef printable_char
}
}
kdb_printf("%*s %s\n", (int)((num-i)*(2*bytesperword + 1)+1),
" ", cbuf);
}
static int kdb_md(int argc, const char **argv)
{
static unsigned long last_addr;
static int last_radix, last_bytesperword, last_repeat;
int radix = 16, mdcount = 8, bytesperword = KDB_WORD_SIZE, repeat;
int nosect = 0;
char fmtchar, fmtstr[64];
unsigned long addr;
unsigned long word;
long offset = 0;
int symbolic = 0;
int valid = 0;
int phys = 0;
kdbgetintenv("MDCOUNT", &mdcount);
kdbgetintenv("RADIX", &radix);
kdbgetintenv("BYTESPERWORD", &bytesperword);
repeat = mdcount * 16 / bytesperword;
if (strcmp(argv[0], "mdr") == 0) {
if (argc != 2)
return KDB_ARGCOUNT;
valid = 1;
} else if (isdigit(argv[0][2])) {
bytesperword = (int)(argv[0][2] - '0');
if (bytesperword == 0) {
bytesperword = last_bytesperword;
if (bytesperword == 0)
bytesperword = 4;
}
last_bytesperword = bytesperword;
repeat = mdcount * 16 / bytesperword;
if (!argv[0][3])
valid = 1;
else if (argv[0][3] == 'c' && argv[0][4]) {
char *p;
repeat = simple_strtoul(argv[0] + 4, &p, 10);
mdcount = ((repeat * bytesperword) + 15) / 16;
valid = !*p;
}
last_repeat = repeat;
} else if (strcmp(argv[0], "md") == 0)
valid = 1;
else if (strcmp(argv[0], "mds") == 0)
valid = 1;
else if (strcmp(argv[0], "mdp") == 0) {
phys = valid = 1;
}
if (!valid)
return KDB_NOTFOUND;
if (argc == 0) {
if (last_addr == 0)
return KDB_ARGCOUNT;
addr = last_addr;
radix = last_radix;
bytesperword = last_bytesperword;
repeat = last_repeat;
mdcount = ((repeat * bytesperword) + 15) / 16;
}
if (argc) {
unsigned long val;
int diag, nextarg = 1;
diag = kdbgetaddrarg(argc, argv, &nextarg, &addr,
&offset, NULL);
if (diag)
return diag;
if (argc > nextarg+2)
return KDB_ARGCOUNT;
if (argc >= nextarg) {
diag = kdbgetularg(argv[nextarg], &val);
if (!diag) {
mdcount = (int) val;
repeat = mdcount * 16 / bytesperword;
}
}
if (argc >= nextarg+1) {
diag = kdbgetularg(argv[nextarg+1], &val);
if (!diag)
radix = (int) val;
}
}
if (strcmp(argv[0], "mdr") == 0)
return kdb_mdr(addr, mdcount);
switch (radix) {
case 10:
fmtchar = 'd';
break;
case 16:
fmtchar = 'x';
break;
case 8:
fmtchar = 'o';
break;
default:
return KDB_BADRADIX;
}
last_radix = radix;
if (bytesperword > KDB_WORD_SIZE)
return KDB_BADWIDTH;
switch (bytesperword) {
case 8:
sprintf(fmtstr, "%%16.16l%c ", fmtchar);
break;
case 4:
sprintf(fmtstr, "%%8.8l%c ", fmtchar);
break;
case 2:
sprintf(fmtstr, "%%4.4l%c ", fmtchar);
break;
case 1:
sprintf(fmtstr, "%%2.2l%c ", fmtchar);
break;
default:
return KDB_BADWIDTH;
}
last_repeat = repeat;
last_bytesperword = bytesperword;
if (strcmp(argv[0], "mds") == 0) {
symbolic = 1;
bytesperword = KDB_WORD_SIZE;
repeat = mdcount;
kdbgetintenv("NOSECT", &nosect);
}
addr &= ~(bytesperword-1);
while (repeat > 0) {
unsigned long a;
int n, z, num = (symbolic ? 1 : (16 / bytesperword));
if (KDB_FLAG(CMD_INTERRUPT))
return 0;
for (a = addr, z = 0; z < repeat; a += bytesperword, ++z) {
if (phys) {
if (kdb_getphysword(&word, a, bytesperword)
|| word)
break;
} else if (kdb_getword(&word, a, bytesperword) || word)
break;
}
n = min(num, repeat);
kdb_md_line(fmtstr, addr, symbolic, nosect, bytesperword,
num, repeat, phys);
addr += bytesperword * n;
repeat -= n;
z = (z + num - 1) / num;
if (z > 2) {
int s = num * (z-2);
kdb_printf(kdb_machreg_fmt0 "-" kdb_machreg_fmt0
" zero suppressed\n",
addr, addr + bytesperword * s - 1);
addr += bytesperword * s;
repeat -= s;
}
}
last_addr = addr;
return 0;
}
static int kdb_mm(int argc, const char **argv)
{
int diag;
unsigned long addr;
long offset = 0;
unsigned long contents;
int nextarg;
int width;
if (argv[0][2] && !isdigit(argv[0][2]))
return KDB_NOTFOUND;
if (argc < 2)
return KDB_ARGCOUNT;
nextarg = 1;
diag = kdbgetaddrarg(argc, argv, &nextarg, &addr, &offset, NULL);
if (diag)
return diag;
if (nextarg > argc)
return KDB_ARGCOUNT;
diag = kdbgetaddrarg(argc, argv, &nextarg, &contents, NULL, NULL);
if (diag)
return diag;
if (nextarg != argc + 1)
return KDB_ARGCOUNT;
width = argv[0][2] ? (argv[0][2] - '0') : (KDB_WORD_SIZE);
diag = kdb_putword(addr, contents, width);
if (diag)
return diag;
kdb_printf(kdb_machreg_fmt " = " kdb_machreg_fmt "\n", addr, contents);
return 0;
}
static int kdb_go(int argc, const char **argv)
{
unsigned long addr;
int diag;
int nextarg;
long offset;
if (raw_smp_processor_id() != kdb_initial_cpu) {
kdb_printf("go must execute on the entry cpu, "
"please use \"cpu %d\" and then execute go\n",
kdb_initial_cpu);
return KDB_BADCPUNUM;
}
if (argc == 1) {
nextarg = 1;
diag = kdbgetaddrarg(argc, argv, &nextarg,
&addr, &offset, NULL);
if (diag)
return diag;
} else if (argc) {
return KDB_ARGCOUNT;
}
diag = KDB_CMD_GO;
if (KDB_FLAG(CATASTROPHIC)) {
kdb_printf("Catastrophic error detected\n");
kdb_printf("kdb_continue_catastrophic=%d, ",
kdb_continue_catastrophic);
if (kdb_continue_catastrophic == 0 && kdb_go_count++ == 0) {
kdb_printf("type go a second time if you really want "
"to continue\n");
return 0;
}
if (kdb_continue_catastrophic == 2) {
kdb_printf("forcing reboot\n");
kdb_reboot(0, NULL);
}
kdb_printf("attempting to continue\n");
}
return diag;
}
static int kdb_rd(int argc, const char **argv)
{
int len = kdb_check_regs();
#if DBG_MAX_REG_NUM > 0
int i;
char *rname;
int rsize;
u64 reg64;
u32 reg32;
u16 reg16;
u8 reg8;
if (len)
return len;
for (i = 0; i < DBG_MAX_REG_NUM; i++) {
rsize = dbg_reg_def[i].size * 2;
if (rsize > 16)
rsize = 2;
if (len + strlen(dbg_reg_def[i].name) + 4 + rsize > 80) {
len = 0;
kdb_printf("\n");
}
if (len)
len += kdb_printf(" ");
switch(dbg_reg_def[i].size * 8) {
case 8:
rname = dbg_get_reg(i, &reg8, kdb_current_regs);
if (!rname)
break;
len += kdb_printf("%s: %02x", rname, reg8);
break;
case 16:
rname = dbg_get_reg(i, &reg16, kdb_current_regs);
if (!rname)
break;
len += kdb_printf("%s: %04x", rname, reg16);
break;
case 32:
rname = dbg_get_reg(i, &reg32, kdb_current_regs);
if (!rname)
break;
len += kdb_printf("%s: %08x", rname, reg32);
break;
case 64:
rname = dbg_get_reg(i, &reg64, kdb_current_regs);
if (!rname)
break;
len += kdb_printf("%s: %016llx", rname, reg64);
break;
default:
len += kdb_printf("%s: ??", dbg_reg_def[i].name);
}
}
kdb_printf("\n");
#else
if (len)
return len;
kdb_dumpregs(kdb_current_regs);
#endif
return 0;
}
static int kdb_rm(int argc, const char **argv)
{
#if DBG_MAX_REG_NUM > 0
int diag;
const char *rname;
int i;
u64 reg64;
u32 reg32;
u16 reg16;
u8 reg8;
if (argc != 2)
return KDB_ARGCOUNT;
rname = argv[1];
if (*rname == '%')
rname++;
diag = kdbgetu64arg(argv[2], &reg64);
if (diag)
return diag;
diag = kdb_check_regs();
if (diag)
return diag;
diag = KDB_BADREG;
for (i = 0; i < DBG_MAX_REG_NUM; i++) {
if (strcmp(rname, dbg_reg_def[i].name) == 0) {
diag = 0;
break;
}
}
if (!diag) {
switch(dbg_reg_def[i].size * 8) {
case 8:
reg8 = reg64;
dbg_set_reg(i, &reg8, kdb_current_regs);
break;
case 16:
reg16 = reg64;
dbg_set_reg(i, &reg16, kdb_current_regs);
break;
case 32:
reg32 = reg64;
dbg_set_reg(i, &reg32, kdb_current_regs);
break;
case 64:
dbg_set_reg(i, &reg64, kdb_current_regs);
break;
}
}
return diag;
#else
kdb_printf("ERROR: Register set currently not implemented\n");
return 0;
#endif
}
static int kdb_sr(int argc, const char **argv)
{
if (argc != 1)
return KDB_ARGCOUNT;
kdb_trap_printk++;
__handle_sysrq(*argv[1], false);
kdb_trap_printk--;
return 0;
}
static int kdb_ef(int argc, const char **argv)
{
int diag;
unsigned long addr;
long offset;
int nextarg;
if (argc != 1)
return KDB_ARGCOUNT;
nextarg = 1;
diag = kdbgetaddrarg(argc, argv, &nextarg, &addr, &offset, NULL);
if (diag)
return diag;
show_regs((struct pt_regs *)addr);
return 0;
}
static int kdb_lsmod(int argc, const char **argv)
{
struct module *mod;
if (argc != 0)
return KDB_ARGCOUNT;
kdb_printf("Module Size modstruct Used by\n");
list_for_each_entry(mod, kdb_modules, list) {
kdb_printf("%-20s%8u 0x%p ", mod->name,
mod->core_size, (void *)mod);
#ifdef CONFIG_MODULE_UNLOAD
kdb_printf("%4ld ", module_refcount(mod));
#endif
if (mod->state == MODULE_STATE_GOING)
kdb_printf(" (Unloading)");
else if (mod->state == MODULE_STATE_COMING)
kdb_printf(" (Loading)");
else
kdb_printf(" (Live)");
kdb_printf(" 0x%p", mod->module_core);
#ifdef CONFIG_MODULE_UNLOAD
{
struct module_use *use;
kdb_printf(" [ ");
list_for_each_entry(use, &mod->source_list,
source_list)
kdb_printf("%s ", use->target->name);
kdb_printf("]\n");
}
#endif
}
return 0;
}
static int kdb_env(int argc, const char **argv)
{
int i;
for (i = 0; i < __nenv; i++) {
if (__env[i])
kdb_printf("%s\n", __env[i]);
}
if (KDB_DEBUG(MASK))
kdb_printf("KDBFLAGS=0x%x\n", kdb_flags);
return 0;
}
static int kdb_dmesg(int argc, const char **argv)
{
int diag;
int logging;
int lines = 0;
int adjust = 0;
int n = 0;
int skip = 0;
struct kmsg_dumper dumper = { .active = 1 };
size_t len;
char buf[201];
if (argc > 2)
return KDB_ARGCOUNT;
if (argc) {
char *cp;
lines = simple_strtol(argv[1], &cp, 0);
if (*cp)
lines = 0;
if (argc > 1) {
adjust = simple_strtoul(argv[2], &cp, 0);
if (*cp || adjust < 0)
adjust = 0;
}
}
diag = kdbgetintenv("LOGGING", &logging);
if (!diag && logging) {
const char *setargs[] = { "set", "LOGGING", "0" };
kdb_set(2, setargs);
}
kmsg_dump_rewind_nolock(&dumper);
while (kmsg_dump_get_line_nolock(&dumper, 1, NULL, 0, NULL))
n++;
if (lines < 0) {
if (adjust >= n)
kdb_printf("buffer only contains %d lines, nothing "
"printed\n", n);
else if (adjust - lines >= n)
kdb_printf("buffer only contains %d lines, last %d "
"lines printed\n", n, n - adjust);
skip = adjust;
lines = abs(lines);
} else if (lines > 0) {
skip = n - lines - adjust;
lines = abs(lines);
if (adjust >= n) {
kdb_printf("buffer only contains %d lines, "
"nothing printed\n", n);
skip = n;
} else if (skip < 0) {
lines += skip;
skip = 0;
kdb_printf("buffer only contains %d lines, first "
"%d lines printed\n", n, lines);
}
} else {
lines = n;
}
if (skip >= n || skip < 0)
return 0;
kmsg_dump_rewind_nolock(&dumper);
while (kmsg_dump_get_line_nolock(&dumper, 1, buf, sizeof(buf), &len)) {
if (skip) {
skip--;
continue;
}
if (!lines--)
break;
if (KDB_FLAG(CMD_INTERRUPT))
return 0;
kdb_printf("%.*s\n", (int)len - 1, buf);
}
return 0;
}
static int kdb_disable_nmi(int argc, const char *argv[])
{
if (atomic_read(&kdb_nmi_disabled))
return 0;
atomic_set(&kdb_nmi_disabled, 1);
arch_kgdb_ops.enable_nmi(0);
return 0;
}
static int kdb_param_enable_nmi(const char *val, const struct kernel_param *kp)
{
if (!atomic_add_unless(&kdb_nmi_disabled, -1, 0))
return -EINVAL;
arch_kgdb_ops.enable_nmi(1);
return 0;
}
static void kdb_cpu_status(void)
{
int i, start_cpu, first_print = 1;
char state, prev_state = '?';
kdb_printf("Currently on cpu %d\n", raw_smp_processor_id());
kdb_printf("Available cpus: ");
for (start_cpu = -1, i = 0; i < NR_CPUS; i++) {
if (!cpu_online(i)) {
state = 'F';
} else {
state = ' ';
if (kdb_task_state_char(KDB_TSK(i)) == 'I')
state = 'I';
}
if (state != prev_state) {
if (prev_state != '?') {
if (!first_print)
kdb_printf(", ");
first_print = 0;
kdb_printf("%d", start_cpu);
if (start_cpu < i-1)
kdb_printf("-%d", i-1);
if (prev_state != ' ')
kdb_printf("(%c)", prev_state);
}
prev_state = state;
start_cpu = i;
}
}
if (prev_state != 'F') {
if (!first_print)
kdb_printf(", ");
kdb_printf("%d", start_cpu);
if (start_cpu < i-1)
kdb_printf("-%d", i-1);
if (prev_state != ' ')
kdb_printf("(%c)", prev_state);
}
kdb_printf("\n");
}
static int kdb_cpu(int argc, const char **argv)
{
unsigned long cpunum;
int diag;
if (argc == 0) {
kdb_cpu_status();
return 0;
}
if (argc != 1)
return KDB_ARGCOUNT;
diag = kdbgetularg(argv[1], &cpunum);
if (diag)
return diag;
if ((cpunum > NR_CPUS) || !cpu_online(cpunum))
return KDB_BADCPUNUM;
dbg_switch_cpu = cpunum;
return KDB_CMD_CPU;
}
void kdb_ps_suppressed(void)
{
int idle = 0, daemon = 0;
unsigned long mask_I = kdb_task_state_string("I"),
mask_M = kdb_task_state_string("M");
unsigned long cpu;
const struct task_struct *p, *g;
for_each_online_cpu(cpu) {
p = kdb_curr_task(cpu);
if (kdb_task_state(p, mask_I))
++idle;
}
kdb_do_each_thread(g, p) {
if (kdb_task_state(p, mask_M))
++daemon;
} kdb_while_each_thread(g, p);
if (idle || daemon) {
if (idle)
kdb_printf("%d idle process%s (state I)%s\n",
idle, idle == 1 ? "" : "es",
daemon ? " and " : "");
if (daemon)
kdb_printf("%d sleeping system daemon (state M) "
"process%s", daemon,
daemon == 1 ? "" : "es");
kdb_printf(" suppressed,\nuse 'ps A' to see all.\n");
}
}
void kdb_ps1(const struct task_struct *p)
{
int cpu;
unsigned long tmp;
if (!p || probe_kernel_read(&tmp, (char *)p, sizeof(unsigned long)))
return;
cpu = kdb_process_cpu(p);
kdb_printf("0x%p %8d %8d %d %4d %c 0x%p %c%s\n",
(void *)p, p->pid, p->parent->pid,
kdb_task_has_cpu(p), kdb_process_cpu(p),
kdb_task_state_char(p),
(void *)(&p->thread),
p == kdb_curr_task(raw_smp_processor_id()) ? '*' : ' ',
p->comm);
if (kdb_task_has_cpu(p)) {
if (!KDB_TSK(cpu)) {
kdb_printf(" Error: no saved data for this cpu\n");
} else {
if (KDB_TSK(cpu) != p)
kdb_printf(" Error: does not match running "
"process table (0x%p)\n", KDB_TSK(cpu));
}
}
}
static int kdb_ps(int argc, const char **argv)
{
struct task_struct *g, *p;
unsigned long mask, cpu;
if (argc == 0)
kdb_ps_suppressed();
kdb_printf("%-*s Pid Parent [*] cpu State %-*s Command\n",
(int)(2*sizeof(void *))+2, "Task Addr",
(int)(2*sizeof(void *))+2, "Thread");
mask = kdb_task_state_string(argc ? argv[1] : NULL);
for_each_online_cpu(cpu) {
if (KDB_FLAG(CMD_INTERRUPT))
return 0;
p = kdb_curr_task(cpu);
if (kdb_task_state(p, mask))
kdb_ps1(p);
}
kdb_printf("\n");
kdb_do_each_thread(g, p) {
if (KDB_FLAG(CMD_INTERRUPT))
return 0;
if (kdb_task_state(p, mask))
kdb_ps1(p);
} kdb_while_each_thread(g, p);
return 0;
}
static int kdb_pid(int argc, const char **argv)
{
struct task_struct *p;
unsigned long val;
int diag;
if (argc > 1)
return KDB_ARGCOUNT;
if (argc) {
if (strcmp(argv[1], "R") == 0) {
p = KDB_TSK(kdb_initial_cpu);
} else {
diag = kdbgetularg(argv[1], &val);
if (diag)
return KDB_BADINT;
p = find_task_by_pid_ns((pid_t)val, &init_pid_ns);
if (!p) {
kdb_printf("No task with pid=%d\n", (pid_t)val);
return 0;
}
}
kdb_set_current_task(p);
}
kdb_printf("KDB current process is %s(pid=%d)\n",
kdb_current_task->comm,
kdb_current_task->pid);
return 0;
}
static int kdb_ll(int argc, const char **argv)
{
int diag = 0;
unsigned long addr;
long offset = 0;
unsigned long va;
unsigned long linkoffset;
int nextarg;
const char *command;
if (argc != 3)
return KDB_ARGCOUNT;
nextarg = 1;
diag = kdbgetaddrarg(argc, argv, &nextarg, &addr, &offset, NULL);
if (diag)
return diag;
diag = kdbgetularg(argv[2], &linkoffset);
if (diag)
return diag;
va = addr;
command = kdb_strdup(argv[3], GFP_KDB);
if (!command) {
kdb_printf("%s: cannot duplicate command\n", __func__);
return 0;
}
argv = NULL;
while (va) {
char buf[80];
if (KDB_FLAG(CMD_INTERRUPT))
goto out;
sprintf(buf, "%s " kdb_machreg_fmt "\n", command, va);
diag = kdb_parse(buf);
if (diag)
goto out;
addr = va + linkoffset;
if (kdb_getword(&va, addr, sizeof(va)))
goto out;
}
out:
kfree(command);
return diag;
}
static int kdb_kgdb(int argc, const char **argv)
{
return KDB_CMD_KGDB;
}
static int kdb_help(int argc, const char **argv)
{
kdbtab_t *kt;
int i;
kdb_printf("%-15.15s %-20.20s %s\n", "Command", "Usage", "Description");
kdb_printf("-----------------------------"
"-----------------------------\n");
for_each_kdbcmd(kt, i) {
if (kt->cmd_name)
kdb_printf("%-15.15s %-20.20s %s\n", kt->cmd_name,
kt->cmd_usage, kt->cmd_help);
if (KDB_FLAG(CMD_INTERRUPT))
return 0;
}
return 0;
}
static int kdb_kill(int argc, const char **argv)
{
long sig, pid;
char *endp;
struct task_struct *p;
struct siginfo info;
if (argc != 2)
return KDB_ARGCOUNT;
sig = simple_strtol(argv[1], &endp, 0);
if (*endp)
return KDB_BADINT;
if (sig >= 0) {
kdb_printf("Invalid signal parameter.<-signal>\n");
return 0;
}
sig = -sig;
pid = simple_strtol(argv[2], &endp, 0);
if (*endp)
return KDB_BADINT;
if (pid <= 0) {
kdb_printf("Process ID must be large than 0.\n");
return 0;
}
p = find_task_by_pid_ns(pid, &init_pid_ns);
if (!p) {
kdb_printf("The specified process isn't found.\n");
return 0;
}
p = p->group_leader;
info.si_signo = sig;
info.si_errno = 0;
info.si_code = SI_USER;
info.si_pid = pid;
info.si_uid = 0;
kdb_send_sig_info(p, &info);
return 0;
}
static void kdb_gmtime(struct timespec *tv, struct kdb_tm *tm)
{
static int mon_day[] = { 31, 29, 31, 30, 31, 30, 31,
31, 30, 31, 30, 31 };
memset(tm, 0, sizeof(*tm));
tm->tm_sec = tv->tv_sec % (24 * 60 * 60);
tm->tm_mday = tv->tv_sec / (24 * 60 * 60) +
(2 * 365 + 1);
tm->tm_min = tm->tm_sec / 60 % 60;
tm->tm_hour = tm->tm_sec / 60 / 60;
tm->tm_sec = tm->tm_sec % 60;
tm->tm_year = 68 + 4*(tm->tm_mday / (4*365+1));
tm->tm_mday %= (4*365+1);
mon_day[1] = 29;
while (tm->tm_mday >= mon_day[tm->tm_mon]) {
tm->tm_mday -= mon_day[tm->tm_mon];
if (++tm->tm_mon == 12) {
tm->tm_mon = 0;
++tm->tm_year;
mon_day[1] = 28;
}
}
++tm->tm_mday;
}
static void kdb_sysinfo(struct sysinfo *val)
{
struct timespec uptime;
do_posix_clock_monotonic_gettime(&uptime);
memset(val, 0, sizeof(*val));
val->uptime = uptime.tv_sec;
val->loads[0] = avenrun[0];
val->loads[1] = avenrun[1];
val->loads[2] = avenrun[2];
val->procs = nr_threads-1;
si_meminfo(val);
return;
}
static int kdb_summary(int argc, const char **argv)
{
struct timespec now;
struct kdb_tm tm;
struct sysinfo val;
if (argc)
return KDB_ARGCOUNT;
kdb_printf("sysname %s\n", init_uts_ns.name.sysname);
kdb_printf("release %s\n", init_uts_ns.name.release);
kdb_printf("version %s\n", init_uts_ns.name.version);
kdb_printf("machine %s\n", init_uts_ns.name.machine);
kdb_printf("nodename %s\n", init_uts_ns.name.nodename);
kdb_printf("domainname %s\n", init_uts_ns.name.domainname);
kdb_printf("ccversion %s\n", __stringify(CCVERSION));
now = __current_kernel_time();
kdb_gmtime(&now, &tm);
kdb_printf("date %04d-%02d-%02d %02d:%02d:%02d "
"tz_minuteswest %d\n",
1900+tm.tm_year, tm.tm_mon+1, tm.tm_mday,
tm.tm_hour, tm.tm_min, tm.tm_sec,
sys_tz.tz_minuteswest);
kdb_sysinfo(&val);
kdb_printf("uptime ");
if (val.uptime > (24*60*60)) {
int days = val.uptime / (24*60*60);
val.uptime %= (24*60*60);
kdb_printf("%d day%s ", days, days == 1 ? "" : "s");
}
kdb_printf("%02ld:%02ld\n", val.uptime/(60*60), (val.uptime/60)%60);
#define LOAD_INT(x) ((x) >> FSHIFT)
#define LOAD_FRAC(x) LOAD_INT(((x) & (FIXED_1-1)) * 100)
kdb_printf("load avg %ld.%02ld %ld.%02ld %ld.%02ld\n",
LOAD_INT(val.loads[0]), LOAD_FRAC(val.loads[0]),
LOAD_INT(val.loads[1]), LOAD_FRAC(val.loads[1]),
LOAD_INT(val.loads[2]), LOAD_FRAC(val.loads[2]));
#undef LOAD_INT
#undef LOAD_FRAC
#define K(x) ((x) << (PAGE_SHIFT - 10))
kdb_printf("\nMemTotal: %8lu kB\nMemFree: %8lu kB\n"
"Buffers: %8lu kB\n",
val.totalram, val.freeram, val.bufferram);
return 0;
}
static int kdb_per_cpu(int argc, const char **argv)
{
char fmtstr[64];
int cpu, diag, nextarg = 1;
unsigned long addr, symaddr, val, bytesperword = 0, whichcpu = ~0UL;
if (argc < 1 || argc > 3)
return KDB_ARGCOUNT;
diag = kdbgetaddrarg(argc, argv, &nextarg, &symaddr, NULL, NULL);
if (diag)
return diag;
if (argc >= 2) {
diag = kdbgetularg(argv[2], &bytesperword);
if (diag)
return diag;
}
if (!bytesperword)
bytesperword = KDB_WORD_SIZE;
else if (bytesperword > KDB_WORD_SIZE)
return KDB_BADWIDTH;
sprintf(fmtstr, "%%0%dlx ", (int)(2*bytesperword));
if (argc >= 3) {
diag = kdbgetularg(argv[3], &whichcpu);
if (diag)
return diag;
if (!cpu_online(whichcpu)) {
kdb_printf("cpu %ld is not online\n", whichcpu);
return KDB_BADCPUNUM;
}
}
#ifdef __per_cpu_offset
#define KDB_PCU(cpu) __per_cpu_offset(cpu)
#else
#ifdef CONFIG_SMP
#define KDB_PCU(cpu) __per_cpu_offset[cpu]
#else
#define KDB_PCU(cpu) 0
#endif
#endif
for_each_online_cpu(cpu) {
if (KDB_FLAG(CMD_INTERRUPT))
return 0;
if (whichcpu != ~0UL && whichcpu != cpu)
continue;
addr = symaddr + KDB_PCU(cpu);
diag = kdb_getword(&val, addr, bytesperword);
if (diag) {
kdb_printf("%5d " kdb_bfd_vma_fmt0 " - unable to "
"read, diag=%d\n", cpu, addr, diag);
continue;
}
kdb_printf("%5d ", cpu);
kdb_md_line(fmtstr, addr,
bytesperword == KDB_WORD_SIZE,
1, bytesperword, 1, 1, 0);
}
#undef KDB_PCU
return 0;
}
static int kdb_grep_help(int argc, const char **argv)
{
kdb_printf("Usage of cmd args | grep pattern:\n");
kdb_printf(" Any command's output may be filtered through an ");
kdb_printf("emulated 'pipe'.\n");
kdb_printf(" 'grep' is just a key word.\n");
kdb_printf(" The pattern may include a very limited set of "
"metacharacters:\n");
kdb_printf(" pattern or ^pattern or pattern$ or ^pattern$\n");
kdb_printf(" And if there are spaces in the pattern, you may "
"quote it:\n");
kdb_printf(" \"pat tern\" or \"^pat tern\" or \"pat tern$\""
" or \"^pat tern$\"\n");
return 0;
}
int kdb_register_repeat(char *cmd,
kdb_func_t func,
char *usage,
char *help,
short minlen,
kdb_repeat_t repeat)
{
int i;
kdbtab_t *kp;
for_each_kdbcmd(kp, i) {
if (kp->cmd_name && (strcmp(kp->cmd_name, cmd) == 0)) {
kdb_printf("Duplicate kdb command registered: "
"%s, func %p help %s\n", cmd, func, help);
return 1;
}
}
for_each_kdbcmd(kp, i) {
if (kp->cmd_name == NULL)
break;
}
if (i >= kdb_max_commands) {
kdbtab_t *new = kmalloc((kdb_max_commands - KDB_BASE_CMD_MAX +
kdb_command_extend) * sizeof(*new), GFP_KDB);
if (!new) {
kdb_printf("Could not allocate new kdb_command "
"table\n");
return 1;
}
if (kdb_commands) {
memcpy(new, kdb_commands,
(kdb_max_commands - KDB_BASE_CMD_MAX) * sizeof(*new));
kfree(kdb_commands);
}
memset(new + kdb_max_commands, 0,
kdb_command_extend * sizeof(*new));
kdb_commands = new;
kp = kdb_commands + kdb_max_commands - KDB_BASE_CMD_MAX;
kdb_max_commands += kdb_command_extend;
}
kp->cmd_name = cmd;
kp->cmd_func = func;
kp->cmd_usage = usage;
kp->cmd_help = help;
kp->cmd_flags = 0;
kp->cmd_minlen = minlen;
kp->cmd_repeat = repeat;
return 0;
}
int kdb_register(char *cmd,
kdb_func_t func,
char *usage,
char *help,
short minlen)
{
return kdb_register_repeat(cmd, func, usage, help, minlen,
KDB_REPEAT_NONE);
}
int kdb_unregister(char *cmd)
{
int i;
kdbtab_t *kp;
for_each_kdbcmd(kp, i) {
if (kp->cmd_name && (strcmp(kp->cmd_name, cmd) == 0)) {
kp->cmd_name = NULL;
return 0;
}
}
return 1;
}
static void __init kdb_inittab(void)
{
int i;
kdbtab_t *kp;
for_each_kdbcmd(kp, i)
kp->cmd_name = NULL;
kdb_register_repeat("md", kdb_md, "<vaddr>",
"Display Memory Contents, also mdWcN, e.g. md8c1", 1,
KDB_REPEAT_NO_ARGS);
kdb_register_repeat("mdr", kdb_md, "<vaddr> <bytes>",
"Display Raw Memory", 0, KDB_REPEAT_NO_ARGS);
kdb_register_repeat("mdp", kdb_md, "<paddr> <bytes>",
"Display Physical Memory", 0, KDB_REPEAT_NO_ARGS);
kdb_register_repeat("mds", kdb_md, "<vaddr>",
"Display Memory Symbolically", 0, KDB_REPEAT_NO_ARGS);
kdb_register_repeat("mm", kdb_mm, "<vaddr> <contents>",
"Modify Memory Contents", 0, KDB_REPEAT_NO_ARGS);
kdb_register_repeat("go", kdb_go, "[<vaddr>]",
"Continue Execution", 1, KDB_REPEAT_NONE);
kdb_register_repeat("rd", kdb_rd, "",
"Display Registers", 0, KDB_REPEAT_NONE);
kdb_register_repeat("rm", kdb_rm, "<reg> <contents>",
"Modify Registers", 0, KDB_REPEAT_NONE);
kdb_register_repeat("ef", kdb_ef, "<vaddr>",
"Display exception frame", 0, KDB_REPEAT_NONE);
kdb_register_repeat("bt", kdb_bt, "[<vaddr>]",
"Stack traceback", 1, KDB_REPEAT_NONE);
kdb_register_repeat("btp", kdb_bt, "<pid>",
"Display stack for process <pid>", 0, KDB_REPEAT_NONE);
kdb_register_repeat("bta", kdb_bt, "[DRSTCZEUIMA]",
"Display stack all processes", 0, KDB_REPEAT_NONE);
kdb_register_repeat("btc", kdb_bt, "",
"Backtrace current process on each cpu", 0, KDB_REPEAT_NONE);
kdb_register_repeat("btt", kdb_bt, "<vaddr>",
"Backtrace process given its struct task address", 0,
KDB_REPEAT_NONE);
kdb_register_repeat("ll", kdb_ll, "<first-element> <linkoffset> <cmd>",
"Execute cmd for each element in linked list", 0, KDB_REPEAT_NONE);
kdb_register_repeat("env", kdb_env, "",
"Show environment variables", 0, KDB_REPEAT_NONE);
kdb_register_repeat("set", kdb_set, "",
"Set environment variables", 0, KDB_REPEAT_NONE);
kdb_register_repeat("help", kdb_help, "",
"Display Help Message", 1, KDB_REPEAT_NONE);
kdb_register_repeat("?", kdb_help, "",
"Display Help Message", 0, KDB_REPEAT_NONE);
kdb_register_repeat("cpu", kdb_cpu, "<cpunum>",
"Switch to new cpu", 0, KDB_REPEAT_NONE);
kdb_register_repeat("kgdb", kdb_kgdb, "",
"Enter kgdb mode", 0, KDB_REPEAT_NONE);
kdb_register_repeat("ps", kdb_ps, "[<flags>|A]",
"Display active task list", 0, KDB_REPEAT_NONE);
kdb_register_repeat("pid", kdb_pid, "<pidnum>",
"Switch to another task", 0, KDB_REPEAT_NONE);
kdb_register_repeat("reboot", kdb_reboot, "",
"Reboot the machine immediately", 0, KDB_REPEAT_NONE);
#if defined(CONFIG_MODULES)
kdb_register_repeat("lsmod", kdb_lsmod, "",
"List loaded kernel modules", 0, KDB_REPEAT_NONE);
#endif
#if defined(CONFIG_MAGIC_SYSRQ)
kdb_register_repeat("sr", kdb_sr, "<key>",
"Magic SysRq key", 0, KDB_REPEAT_NONE);
#endif
#if defined(CONFIG_PRINTK)
kdb_register_repeat("dmesg", kdb_dmesg, "[lines]",
"Display syslog buffer", 0, KDB_REPEAT_NONE);
#endif
if (arch_kgdb_ops.enable_nmi) {
kdb_register_repeat("disable_nmi", kdb_disable_nmi, "",
"Disable NMI entry to KDB", 0, KDB_REPEAT_NONE);
}
kdb_register_repeat("defcmd", kdb_defcmd, "name \"usage\" \"help\"",
"Define a set of commands, down to endefcmd", 0, KDB_REPEAT_NONE);
kdb_register_repeat("kill", kdb_kill, "<-signal> <pid>",
"Send a signal to a process", 0, KDB_REPEAT_NONE);
kdb_register_repeat("summary", kdb_summary, "",
"Summarize the system", 4, KDB_REPEAT_NONE);
kdb_register_repeat("per_cpu", kdb_per_cpu, "<sym> [<bytes>] [<cpu>]",
"Display per_cpu variables", 3, KDB_REPEAT_NONE);
kdb_register_repeat("grephelp", kdb_grep_help, "",
"Display help on | grep", 0, KDB_REPEAT_NONE);
}
static void __init kdb_cmd_init(void)
{
int i, diag;
for (i = 0; kdb_cmds[i]; ++i) {
diag = kdb_parse(kdb_cmds[i]);
if (diag)
kdb_printf("kdb command %s failed, kdb diag %d\n",
kdb_cmds[i], diag);
}
if (defcmd_in_progress) {
kdb_printf("Incomplete 'defcmd' set, forcing endefcmd\n");
kdb_parse("endefcmd");
}
}
void __init kdb_init(int lvl)
{
static int kdb_init_lvl = KDB_NOT_INITIALIZED;
int i;
if (kdb_init_lvl == KDB_INIT_FULL || lvl <= kdb_init_lvl)
return;
for (i = kdb_init_lvl; i < lvl; i++) {
switch (i) {
case KDB_NOT_INITIALIZED:
kdb_inittab();
kdb_initbptab();
break;
case KDB_INIT_EARLY:
kdb_cmd_init();
break;
}
}
kdb_init_lvl = lvl;
}
