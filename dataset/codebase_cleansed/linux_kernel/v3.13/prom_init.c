static inline int enter_prom(struct prom_args *args, unsigned long entry)
{
return ((int (*)(struct prom_args *))entry)(args);
}
static int __init call_prom(const char *service, int nargs, int nret, ...)
{
int i;
struct prom_args args;
va_list list;
args.service = cpu_to_be32(ADDR(service));
args.nargs = cpu_to_be32(nargs);
args.nret = cpu_to_be32(nret);
va_start(list, nret);
for (i = 0; i < nargs; i++)
args.args[i] = cpu_to_be32(va_arg(list, prom_arg_t));
va_end(list);
for (i = 0; i < nret; i++)
args.args[nargs+i] = 0;
if (enter_prom(&args, prom_entry) < 0)
return PROM_ERROR;
return (nret > 0) ? be32_to_cpu(args.args[nargs]) : 0;
}
static int __init call_prom_ret(const char *service, int nargs, int nret,
prom_arg_t *rets, ...)
{
int i;
struct prom_args args;
va_list list;
args.service = cpu_to_be32(ADDR(service));
args.nargs = cpu_to_be32(nargs);
args.nret = cpu_to_be32(nret);
va_start(list, rets);
for (i = 0; i < nargs; i++)
args.args[i] = cpu_to_be32(va_arg(list, prom_arg_t));
va_end(list);
for (i = 0; i < nret; i++)
args.args[nargs+i] = 0;
if (enter_prom(&args, prom_entry) < 0)
return PROM_ERROR;
if (rets != NULL)
for (i = 1; i < nret; ++i)
rets[i-1] = be32_to_cpu(args.args[nargs+i]);
return (nret > 0) ? be32_to_cpu(args.args[nargs]) : 0;
}
static void __init prom_print(const char *msg)
{
const char *p, *q;
if (prom.stdout == 0)
return;
for (p = msg; *p != 0; p = q) {
for (q = p; *q != 0 && *q != '\n'; ++q)
;
if (q > p)
call_prom("write", 3, 1, prom.stdout, p, q - p);
if (*q == 0)
break;
++q;
call_prom("write", 3, 1, prom.stdout, ADDR("\r\n"), 2);
}
}
static void __init prom_print_hex(unsigned long val)
{
int i, nibbles = sizeof(val)*2;
char buf[sizeof(val)*2+1];
for (i = nibbles-1; i >= 0; i--) {
buf[i] = (val & 0xf) + '0';
if (buf[i] > '9')
buf[i] += ('a'-'0'-10);
val >>= 4;
}
buf[nibbles] = '\0';
call_prom("write", 3, 1, prom.stdout, buf, nibbles);
}
static void __init prom_print_dec(unsigned long val)
{
int i, size;
char buf[UL_DIGITS+1];
for (i = UL_DIGITS-1; i >= 0; i--) {
buf[i] = (val % 10) + '0';
val = val/10;
if (val == 0)
break;
}
size = UL_DIGITS - i;
call_prom("write", 3, 1, prom.stdout, buf+i, size);
}
static void __init prom_printf(const char *format, ...)
{
const char *p, *q, *s;
va_list args;
unsigned long v;
long vs;
va_start(args, format);
for (p = format; *p != 0; p = q) {
for (q = p; *q != 0 && *q != '\n' && *q != '%'; ++q)
;
if (q > p)
call_prom("write", 3, 1, prom.stdout, p, q - p);
if (*q == 0)
break;
if (*q == '\n') {
++q;
call_prom("write", 3, 1, prom.stdout,
ADDR("\r\n"), 2);
continue;
}
++q;
if (*q == 0)
break;
switch (*q) {
case 's':
++q;
s = va_arg(args, const char *);
prom_print(s);
break;
case 'x':
++q;
v = va_arg(args, unsigned long);
prom_print_hex(v);
break;
case 'd':
++q;
vs = va_arg(args, int);
if (vs < 0) {
prom_print("-");
vs = -vs;
}
prom_print_dec(vs);
break;
case 'l':
++q;
if (*q == 0)
break;
else if (*q == 'x') {
++q;
v = va_arg(args, unsigned long);
prom_print_hex(v);
} else if (*q == 'u') {
++q;
v = va_arg(args, unsigned long);
prom_print_dec(v);
} else if (*q == 'd') {
++q;
vs = va_arg(args, long);
if (vs < 0) {
prom_print("-");
vs = -vs;
}
prom_print_dec(vs);
}
break;
}
}
}
static unsigned int __init prom_claim(unsigned long virt, unsigned long size,
unsigned long align)
{
if (align == 0 && (OF_WORKAROUNDS & OF_WA_CLAIM)) {
int ret;
prom_arg_t result;
ret = call_prom_ret("call-method", 5, 2, &result,
ADDR("claim"), prom.memory,
align, size, virt);
if (ret != 0 || result == -1)
return -1;
ret = call_prom_ret("call-method", 5, 2, &result,
ADDR("claim"), prom.mmumap,
align, size, virt);
if (ret != 0) {
call_prom("call-method", 4, 1, ADDR("release"),
prom.memory, size, virt);
return -1;
}
call_prom("call-method", 6, 1,
ADDR("map"), prom.mmumap, 0x12, size, virt, virt);
return virt;
}
return call_prom("claim", 3, 1, (prom_arg_t)virt, (prom_arg_t)size,
(prom_arg_t)align);
}
static int __init prom_next_node(phandle *nodep)
{
phandle node;
if ((node = *nodep) != 0
&& (*nodep = call_prom("child", 1, 1, node)) != 0)
return 1;
if ((*nodep = call_prom("peer", 1, 1, node)) != 0)
return 1;
for (;;) {
if ((node = call_prom("parent", 1, 1, node)) == 0)
return 0;
if ((*nodep = call_prom("peer", 1, 1, node)) != 0)
return 1;
}
}
static int inline prom_getprop(phandle node, const char *pname,
void *value, size_t valuelen)
{
return call_prom("getprop", 4, 1, node, ADDR(pname),
(u32)(unsigned long) value, (u32) valuelen);
}
static int inline prom_getproplen(phandle node, const char *pname)
{
return call_prom("getproplen", 2, 1, node, ADDR(pname));
}
static void add_string(char **str, const char *q)
{
char *p = *str;
while (*q)
*p++ = *q++;
*p++ = ' ';
*str = p;
}
static char *tohex(unsigned int x)
{
static char digits[] = "0123456789abcdef";
static char result[9];
int i;
result[8] = 0;
i = 8;
do {
--i;
result[i] = digits[x & 0xf];
x >>= 4;
} while (x != 0 && i > 0);
return &result[i];
}
static int __init prom_setprop(phandle node, const char *nodename,
const char *pname, void *value, size_t valuelen)
{
char cmd[256], *p;
if (!(OF_WORKAROUNDS & OF_WA_LONGTRAIL))
return call_prom("setprop", 4, 1, node, ADDR(pname),
(u32)(unsigned long) value, (u32) valuelen);
p = cmd;
add_string(&p, "dev");
add_string(&p, nodename);
add_string(&p, tohex((u32)(unsigned long) value));
add_string(&p, tohex(valuelen));
add_string(&p, tohex(ADDR(pname)));
add_string(&p, tohex(strlen(pname)));
add_string(&p, "property");
*p = 0;
return call_prom("interpret", 1, 1, (u32)(unsigned long) cmd);
}
static unsigned long prom_strtoul(const char *cp, const char **endp)
{
unsigned long result = 0, base = 10, value;
if (*cp == '0') {
base = 8;
cp++;
if (toupper(*cp) == 'X') {
cp++;
base = 16;
}
}
while (isxdigit(*cp) &&
(value = isdigit(*cp) ? *cp - '0' : toupper(*cp) - 'A' + 10) < base) {
result = result * base + value;
cp++;
}
if (endp)
*endp = cp;
return result;
}
static unsigned long prom_memparse(const char *ptr, const char **retptr)
{
unsigned long ret = prom_strtoul(ptr, retptr);
int shift = 0;
if ('G' == **retptr || 'g' == **retptr)
shift = 30;
if ('M' == **retptr || 'm' == **retptr)
shift = 20;
if ('K' == **retptr || 'k' == **retptr)
shift = 10;
if (shift) {
ret <<= shift;
(*retptr)++;
}
return ret;
}
static void __init early_cmdline_parse(void)
{
const char *opt;
char *p;
int l = 0;
prom_cmd_line[0] = 0;
p = prom_cmd_line;
if ((long)prom.chosen > 0)
l = prom_getprop(prom.chosen, "bootargs", p, COMMAND_LINE_SIZE-1);
#ifdef CONFIG_CMDLINE
if (l <= 0 || p[0] == '\0')
strlcpy(prom_cmd_line,
CONFIG_CMDLINE, sizeof(prom_cmd_line));
#endif
prom_printf("command line: %s\n", prom_cmd_line);
#ifdef CONFIG_PPC64
opt = strstr(prom_cmd_line, "iommu=");
if (opt) {
prom_printf("iommu opt is: %s\n", opt);
opt += 6;
while (*opt && *opt == ' ')
opt++;
if (!strncmp(opt, "off", 3))
prom_iommu_off = 1;
else if (!strncmp(opt, "force", 5))
prom_iommu_force_on = 1;
}
#endif
opt = strstr(prom_cmd_line, "mem=");
if (opt) {
opt += 4;
prom_memory_limit = prom_memparse(opt, (const char **)&opt);
#ifdef CONFIG_PPC64
prom_memory_limit = ALIGN(prom_memory_limit, 0x1000000);
#endif
}
}
static int __init prom_count_smt_threads(void)
{
phandle node;
char type[64];
unsigned int plen;
for (node = 0; prom_next_node(&node); ) {
type[0] = 0;
prom_getprop(node, "device_type", type, sizeof(type));
if (strcmp(type, "cpu"))
continue;
plen = prom_getproplen(node, "ibm,ppc-interrupt-server#s");
if (plen == PROM_ERROR)
break;
plen >>= 2;
prom_debug("Found %lu smt threads per core\n", (unsigned long)plen);
if (plen < 1 || plen > 64) {
prom_printf("Threads per core %lu out of bounds, assuming 1\n",
(unsigned long)plen);
return 1;
}
return plen;
}
prom_debug("No threads found, assuming 1 per core\n");
return 1;
}
static void __init prom_send_capabilities(void)
{
ihandle root;
prom_arg_t ret;
u32 cores;
unsigned char *ptcores;
root = call_prom("open", 1, 1, ADDR("/"));
if (root != 0) {
ptcores = &ibm_architecture_vec[IBM_ARCH_VEC_NRCORES_OFFSET];
cores = 0;
cores |= ptcores[0] << 24;
cores |= ptcores[1] << 16;
cores |= ptcores[2] << 8;
cores |= ptcores[3];
if (cores != NR_CPUS) {
prom_printf("WARNING ! "
"ibm_architecture_vec structure inconsistent: %lu!\n",
cores);
} else {
cores = DIV_ROUND_UP(NR_CPUS, prom_count_smt_threads());
prom_printf("Max number of cores passed to firmware: %lu (NR_CPUS = %lu)\n",
cores, NR_CPUS);
ptcores[0] = (cores >> 24) & 0xff;
ptcores[1] = (cores >> 16) & 0xff;
ptcores[2] = (cores >> 8) & 0xff;
ptcores[3] = cores & 0xff;
}
prom_printf("Calling ibm,client-architecture-support...");
if (call_prom_ret("call-method", 3, 2, &ret,
ADDR("ibm,client-architecture-support"),
root,
ADDR(ibm_architecture_vec)) == 0) {
if (ret)
prom_printf("\nWARNING: ibm,client-architecture"
"-support call FAILED!\n");
call_prom("close", 1, 0, root);
prom_printf(" done\n");
return;
}
call_prom("close", 1, 0, root);
prom_printf(" not implemented\n");
}
#ifdef __BIG_ENDIAN__
{
ihandle elfloader;
elfloader = call_prom("open", 1, 1,
ADDR("/packages/elf-loader"));
if (elfloader == 0) {
prom_printf("couldn't open /packages/elf-loader\n");
return;
}
call_prom("call-method", 3, 1, ADDR("process-elf-header"),
elfloader, ADDR(&fake_elf));
call_prom("close", 1, 0, elfloader);
}
#endif
}
static unsigned long __init alloc_up(unsigned long size, unsigned long align)
{
unsigned long base = alloc_bottom;
unsigned long addr = 0;
if (align)
base = _ALIGN_UP(base, align);
prom_debug("alloc_up(%x, %x)\n", size, align);
if (ram_top == 0)
prom_panic("alloc_up() called with mem not initialized\n");
if (align)
base = _ALIGN_UP(alloc_bottom, align);
else
base = alloc_bottom;
for(; (base + size) <= alloc_top;
base = _ALIGN_UP(base + 0x100000, align)) {
prom_debug(" trying: 0x%x\n\r", base);
addr = (unsigned long)prom_claim(base, size, 0);
if (addr != PROM_ERROR && addr != 0)
break;
addr = 0;
if (align == 0)
break;
}
if (addr == 0)
return 0;
alloc_bottom = addr + size;
prom_debug(" -> %x\n", addr);
prom_debug(" alloc_bottom : %x\n", alloc_bottom);
prom_debug(" alloc_top : %x\n", alloc_top);
prom_debug(" alloc_top_hi : %x\n", alloc_top_high);
prom_debug(" rmo_top : %x\n", rmo_top);
prom_debug(" ram_top : %x\n", ram_top);
return addr;
}
static unsigned long __init alloc_down(unsigned long size, unsigned long align,
int highmem)
{
unsigned long base, addr = 0;
prom_debug("alloc_down(%x, %x, %s)\n", size, align,
highmem ? "(high)" : "(low)");
if (ram_top == 0)
prom_panic("alloc_down() called with mem not initialized\n");
if (highmem) {
addr = _ALIGN_DOWN(alloc_top_high - size, align);
if (addr <= alloc_bottom)
return 0;
if (addr < rmo_top) {
if (alloc_top == rmo_top)
alloc_top = rmo_top = addr;
else
return 0;
}
alloc_top_high = addr;
goto bail;
}
base = _ALIGN_DOWN(alloc_top - size, align);
for (; base > alloc_bottom;
base = _ALIGN_DOWN(base - 0x100000, align)) {
prom_debug(" trying: 0x%x\n\r", base);
addr = (unsigned long)prom_claim(base, size, 0);
if (addr != PROM_ERROR && addr != 0)
break;
addr = 0;
}
if (addr == 0)
return 0;
alloc_top = addr;
bail:
prom_debug(" -> %x\n", addr);
prom_debug(" alloc_bottom : %x\n", alloc_bottom);
prom_debug(" alloc_top : %x\n", alloc_top);
prom_debug(" alloc_top_hi : %x\n", alloc_top_high);
prom_debug(" rmo_top : %x\n", rmo_top);
prom_debug(" ram_top : %x\n", ram_top);
return addr;
}
static unsigned long __init prom_next_cell(int s, cell_t **cellp)
{
cell_t *p = *cellp;
unsigned long r = 0;
while (s > sizeof(unsigned long) / 4) {
p++;
s--;
}
r = be32_to_cpu(*p++);
#ifdef CONFIG_PPC64
if (s > 1) {
r <<= 32;
r |= be32_to_cpu(*(p++));
}
#endif
*cellp = p;
return r;
}
static void __init reserve_mem(u64 base, u64 size)
{
u64 top = base + size;
unsigned long cnt = mem_reserve_cnt;
if (size == 0)
return;
base = _ALIGN_DOWN(base, PAGE_SIZE);
top = _ALIGN_UP(top, PAGE_SIZE);
size = top - base;
if (cnt >= (MEM_RESERVE_MAP_SIZE - 1))
prom_panic("Memory reserve map exhausted !\n");
mem_reserve_map[cnt].base = cpu_to_be64(base);
mem_reserve_map[cnt].size = cpu_to_be64(size);
mem_reserve_cnt = cnt + 1;
}
static void __init prom_init_mem(void)
{
phandle node;
char *path, type[64];
unsigned int plen;
cell_t *p, *endp;
__be32 val;
u32 rac, rsc;
val = cpu_to_be32(2);
prom_getprop(prom.root, "#address-cells", &val, sizeof(val));
rac = be32_to_cpu(val);
val = cpu_to_be32(1);
prom_getprop(prom.root, "#size-cells", &val, sizeof(rsc));
rsc = be32_to_cpu(val);
prom_debug("root_addr_cells: %x\n", rac);
prom_debug("root_size_cells: %x\n", rsc);
prom_debug("scanning memory:\n");
path = prom_scratch;
for (node = 0; prom_next_node(&node); ) {
type[0] = 0;
prom_getprop(node, "device_type", type, sizeof(type));
if (type[0] == 0) {
prom_getprop(node, "name", type, sizeof(type));
}
if (strcmp(type, "memory"))
continue;
plen = prom_getprop(node, "reg", regbuf, sizeof(regbuf));
if (plen > sizeof(regbuf)) {
prom_printf("memory node too large for buffer !\n");
plen = sizeof(regbuf);
}
p = regbuf;
endp = p + (plen / sizeof(cell_t));
#ifdef DEBUG_PROM
memset(path, 0, PROM_SCRATCH_SIZE);
call_prom("package-to-path", 3, 1, node, path, PROM_SCRATCH_SIZE-1);
prom_debug(" node %s :\n", path);
#endif
while ((endp - p) >= (rac + rsc)) {
unsigned long base, size;
base = prom_next_cell(rac, &p);
size = prom_next_cell(rsc, &p);
if (size == 0)
continue;
prom_debug(" %x %x\n", base, size);
if (base == 0 && (of_platform & PLATFORM_LPAR))
rmo_top = size;
if ((base + size) > ram_top)
ram_top = base + size;
}
}
alloc_bottom = PAGE_ALIGN((unsigned long)&_end + 0x4000);
alloc_top_high = ram_top;
if (prom_memory_limit) {
if (prom_memory_limit <= alloc_bottom) {
prom_printf("Ignoring mem=%x <= alloc_bottom.\n",
prom_memory_limit);
prom_memory_limit = 0;
} else if (prom_memory_limit >= ram_top) {
prom_printf("Ignoring mem=%x >= ram_top.\n",
prom_memory_limit);
prom_memory_limit = 0;
} else {
ram_top = prom_memory_limit;
rmo_top = min(rmo_top, prom_memory_limit);
}
}
if (!rmo_top)
rmo_top = ram_top;
rmo_top = min(0x30000000ul, rmo_top);
alloc_top = rmo_top;
alloc_top_high = ram_top;
if (prom_initrd_start &&
prom_initrd_start < rmo_top &&
prom_initrd_end > alloc_bottom)
alloc_bottom = PAGE_ALIGN(prom_initrd_end);
prom_printf("memory layout at init:\n");
prom_printf(" memory_limit : %x (16 MB aligned)\n", prom_memory_limit);
prom_printf(" alloc_bottom : %x\n", alloc_bottom);
prom_printf(" alloc_top : %x\n", alloc_top);
prom_printf(" alloc_top_hi : %x\n", alloc_top_high);
prom_printf(" rmo_top : %x\n", rmo_top);
prom_printf(" ram_top : %x\n", ram_top);
}
static void __init prom_close_stdin(void)
{
__be32 val;
ihandle stdin;
if (prom_getprop(prom.chosen, "stdin", &val, sizeof(val)) > 0) {
stdin = be32_to_cpu(val);
call_prom("close", 1, 0, stdin);
}
}
static void __init prom_query_opal(void)
{
long rc;
if (PHANDLE_VALID(call_prom("finddevice", 1, 1,
ADDR("/tnk-memory-map")))) {
prom_printf("TNK takeover detected, skipping OPAL check\n");
return;
}
prom_printf("Querying for OPAL presence... ");
rc = opal_query_takeover(&prom_opal_size,
&prom_opal_align);
prom_debug("(rc = %ld) ", rc);
if (rc != 0) {
prom_printf("not there.\n");
return;
}
of_platform = PLATFORM_OPAL;
prom_printf(" there !\n");
prom_debug(" opal_size = 0x%lx\n", prom_opal_size);
prom_debug(" opal_align = 0x%lx\n", prom_opal_align);
if (prom_opal_align < 0x10000)
prom_opal_align = 0x10000;
}
static int __init prom_rtas_call(int token, int nargs, int nret,
int *outputs, ...)
{
struct rtas_args rtas_args;
va_list list;
int i;
rtas_args.token = token;
rtas_args.nargs = nargs;
rtas_args.nret = nret;
rtas_args.rets = (rtas_arg_t *)&(rtas_args.args[nargs]);
va_start(list, outputs);
for (i = 0; i < nargs; ++i)
rtas_args.args[i] = va_arg(list, rtas_arg_t);
va_end(list);
for (i = 0; i < nret; ++i)
rtas_args.rets[i] = 0;
opal_enter_rtas(&rtas_args, prom_rtas_data,
prom_rtas_entry);
if (nret > 1 && outputs != NULL)
for (i = 0; i < nret-1; ++i)
outputs[i] = rtas_args.rets[i+1];
return (nret > 0)? rtas_args.rets[0]: 0;
}
static void __init prom_opal_hold_cpus(void)
{
int i, cnt, cpu, rc;
long j;
phandle node;
char type[64];
u32 servers[8];
void *entry = (unsigned long *)&opal_secondary_entry;
struct opal_secondary_data *data = &opal_secondary_data;
prom_debug("prom_opal_hold_cpus: start...\n");
prom_debug(" - entry = 0x%x\n", entry);
prom_debug(" - data = 0x%x\n", data);
data->ack = -1;
data->go = 0;
for (node = 0; prom_next_node(&node); ) {
type[0] = 0;
prom_getprop(node, "device_type", type, sizeof(type));
if (strcmp(type, "cpu") != 0)
continue;
if (prom_getprop(node, "status", type, sizeof(type)) > 0)
if (strcmp(type, "okay") != 0)
continue;
cnt = prom_getprop(node, "ibm,ppc-interrupt-server#s", servers,
sizeof(servers));
if (cnt == PROM_ERROR)
break;
cnt >>= 2;
for (i = 0; i < cnt; i++) {
cpu = servers[i];
prom_debug("CPU %d ... ", cpu);
if (cpu == prom.cpu) {
prom_debug("booted !\n");
continue;
}
prom_debug("starting ... ");
data->ack = -1;
rc = prom_rtas_call(prom_rtas_start_cpu, 3, 1,
NULL, cpu, entry, data);
prom_debug("rtas rc=%d ...", rc);
for (j = 0; j < 100000000 && data->ack == -1; j++) {
HMT_low();
mb();
}
HMT_medium();
if (data->ack != -1)
prom_debug("done, PIR=0x%x\n", data->ack);
else
prom_debug("timeout !\n");
}
}
prom_debug("prom_opal_hold_cpus: end...\n");
}
static void __init prom_opal_takeover(void)
{
struct opal_secondary_data *data = &opal_secondary_data;
struct opal_takeover_args *args = &data->args;
u64 align = prom_opal_align;
u64 top_addr, opal_addr;
args->k_image = (u64)_stext;
args->k_size = _end - _stext;
args->k_entry = 0;
args->k_entry2 = 0x60;
top_addr = _ALIGN_UP(args->k_size, align);
if (prom_initrd_start != 0) {
args->rd_image = prom_initrd_start;
args->rd_size = prom_initrd_end - args->rd_image;
args->rd_loc = top_addr;
top_addr = _ALIGN_UP(args->rd_loc + args->rd_size, align);
}
opal_addr = _ALIGN_DOWN(0x40000000 - prom_opal_size, align);
if (opal_addr < top_addr)
opal_addr = top_addr;
args->hal_addr = opal_addr;
strlcpy(boot_command_line, prom_cmd_line,
COMMAND_LINE_SIZE);
prom_debug(" k_image = 0x%lx\n", args->k_image);
prom_debug(" k_size = 0x%lx\n", args->k_size);
prom_debug(" k_entry = 0x%lx\n", args->k_entry);
prom_debug(" k_entry2 = 0x%lx\n", args->k_entry2);
prom_debug(" hal_addr = 0x%lx\n", args->hal_addr);
prom_debug(" rd_image = 0x%lx\n", args->rd_image);
prom_debug(" rd_size = 0x%lx\n", args->rd_size);
prom_debug(" rd_loc = 0x%lx\n", args->rd_loc);
prom_printf("Performing OPAL takeover,this can take a few minutes..\n");
prom_close_stdin();
mb();
data->go = 1;
for (;;)
opal_do_takeover(args);
}
static void __init prom_instantiate_opal(void)
{
phandle opal_node;
ihandle opal_inst;
u64 base, entry;
u64 size = 0, align = 0x10000;
__be64 val64;
u32 rets[2];
prom_debug("prom_instantiate_opal: start...\n");
opal_node = call_prom("finddevice", 1, 1, ADDR("/ibm,opal"));
prom_debug("opal_node: %x\n", opal_node);
if (!PHANDLE_VALID(opal_node))
return;
val64 = 0;
prom_getprop(opal_node, "opal-runtime-size", &val64, sizeof(val64));
size = be64_to_cpu(val64);
if (size == 0)
return;
val64 = 0;
prom_getprop(opal_node, "opal-runtime-alignment", &val64,sizeof(val64));
align = be64_to_cpu(val64);
base = alloc_down(size, align, 0);
if (base == 0) {
prom_printf("OPAL allocation failed !\n");
return;
}
opal_inst = call_prom("open", 1, 1, ADDR("/ibm,opal"));
if (!IHANDLE_VALID(opal_inst)) {
prom_printf("opening opal package failed (%x)\n", opal_inst);
return;
}
prom_printf("instantiating opal at 0x%x...", base);
if (call_prom_ret("call-method", 4, 3, rets,
ADDR("load-opal-runtime"),
opal_inst,
base >> 32, base & 0xffffffff) != 0
|| (rets[0] == 0 && rets[1] == 0)) {
prom_printf(" failed\n");
return;
}
entry = (((u64)rets[0]) << 32) | rets[1];
prom_printf(" done\n");
reserve_mem(base, size);
prom_debug("opal base = 0x%x\n", base);
prom_debug("opal align = 0x%x\n", align);
prom_debug("opal entry = 0x%x\n", entry);
prom_debug("opal size = 0x%x\n", (long)size);
prom_setprop(opal_node, "/ibm,opal", "opal-base-address",
&base, sizeof(base));
prom_setprop(opal_node, "/ibm,opal", "opal-entry-address",
&entry, sizeof(entry));
#ifdef CONFIG_PPC_EARLY_DEBUG_OPAL
prom_opal_base = base;
prom_opal_entry = entry;
#endif
prom_debug("prom_instantiate_opal: end...\n");
}
static void __init prom_instantiate_rtas(void)
{
phandle rtas_node;
ihandle rtas_inst;
u32 base, entry = 0;
__be32 val;
u32 size = 0;
prom_debug("prom_instantiate_rtas: start...\n");
rtas_node = call_prom("finddevice", 1, 1, ADDR("/rtas"));
prom_debug("rtas_node: %x\n", rtas_node);
if (!PHANDLE_VALID(rtas_node))
return;
val = 0;
prom_getprop(rtas_node, "rtas-size", &val, sizeof(size));
size = be32_to_cpu(val);
if (size == 0)
return;
base = alloc_down(size, PAGE_SIZE, 0);
if (base == 0)
prom_panic("Could not allocate memory for RTAS\n");
rtas_inst = call_prom("open", 1, 1, ADDR("/rtas"));
if (!IHANDLE_VALID(rtas_inst)) {
prom_printf("opening rtas package failed (%x)\n", rtas_inst);
return;
}
prom_printf("instantiating rtas at 0x%x...", base);
if (call_prom_ret("call-method", 3, 2, &entry,
ADDR("instantiate-rtas"),
rtas_inst, base) != 0
|| entry == 0) {
prom_printf(" failed\n");
return;
}
prom_printf(" done\n");
reserve_mem(base, size);
val = cpu_to_be32(base);
prom_setprop(rtas_node, "/rtas", "linux,rtas-base",
&val, sizeof(val));
val = cpu_to_be32(entry);
prom_setprop(rtas_node, "/rtas", "linux,rtas-entry",
&val, sizeof(val));
if (prom_getprop(rtas_node, "query-cpu-stopped-state",
&val, sizeof(val)) != PROM_ERROR)
rtas_has_query_cpu_stopped = true;
#if defined(CONFIG_PPC_POWERNV) && defined(__BIG_ENDIAN__)
prom_rtas_data = base;
prom_rtas_entry = entry;
prom_getprop(rtas_node, "start-cpu", &prom_rtas_start_cpu, 4);
#endif
prom_debug("rtas base = 0x%x\n", base);
prom_debug("rtas entry = 0x%x\n", entry);
prom_debug("rtas size = 0x%x\n", (long)size);
prom_debug("prom_instantiate_rtas: end...\n");
}
static void __init prom_instantiate_sml(void)
{
phandle ibmvtpm_node;
ihandle ibmvtpm_inst;
u32 entry = 0, size = 0;
u64 base;
prom_debug("prom_instantiate_sml: start...\n");
ibmvtpm_node = call_prom("finddevice", 1, 1, ADDR("/ibm,vtpm"));
prom_debug("ibmvtpm_node: %x\n", ibmvtpm_node);
if (!PHANDLE_VALID(ibmvtpm_node))
return;
ibmvtpm_inst = call_prom("open", 1, 1, ADDR("/ibm,vtpm"));
if (!IHANDLE_VALID(ibmvtpm_inst)) {
prom_printf("opening vtpm package failed (%x)\n", ibmvtpm_inst);
return;
}
if (call_prom_ret("call-method", 2, 2, &size,
ADDR("sml-get-handover-size"),
ibmvtpm_inst) != 0 || size == 0) {
prom_printf("SML get handover size failed\n");
return;
}
base = alloc_down(size, PAGE_SIZE, 0);
if (base == 0)
prom_panic("Could not allocate memory for sml\n");
prom_printf("instantiating sml at 0x%x...", base);
if (call_prom_ret("call-method", 4, 2, &entry,
ADDR("sml-handover"),
ibmvtpm_inst, size, base) != 0 || entry == 0) {
prom_printf("SML handover failed\n");
return;
}
prom_printf(" done\n");
reserve_mem(base, size);
prom_setprop(ibmvtpm_node, "/ibm,vtpm", "linux,sml-base",
&base, sizeof(base));
prom_setprop(ibmvtpm_node, "/ibm,vtpm", "linux,sml-size",
&size, sizeof(size));
prom_debug("sml base = 0x%x\n", base);
prom_debug("sml size = 0x%x\n", (long)size);
prom_debug("prom_instantiate_sml: end...\n");
}
static void __init prom_initialize_tce_table(void)
{
phandle node;
ihandle phb_node;
char compatible[64], type[64], model[64];
char *path = prom_scratch;
u64 base, align;
u32 minalign, minsize;
u64 tce_entry, *tce_entryp;
u64 local_alloc_top, local_alloc_bottom;
u64 i;
if (prom_iommu_off)
return;
prom_debug("starting prom_initialize_tce_table\n");
local_alloc_top = alloc_top_high;
local_alloc_bottom = local_alloc_top;
for (node = 0; prom_next_node(&node); ) {
compatible[0] = 0;
type[0] = 0;
model[0] = 0;
prom_getprop(node, "compatible",
compatible, sizeof(compatible));
prom_getprop(node, "device_type", type, sizeof(type));
prom_getprop(node, "model", model, sizeof(model));
if ((type[0] == 0) || (strstr(type, "pci") == NULL))
continue;
if (compatible[0] != 0) {
if ((strstr(compatible, "python") == NULL) &&
(strstr(compatible, "Speedwagon") == NULL) &&
(strstr(compatible, "Winnipeg") == NULL))
continue;
} else if (model[0] != 0) {
if ((strstr(model, "ython") == NULL) &&
(strstr(model, "peedwagon") == NULL) &&
(strstr(model, "innipeg") == NULL))
continue;
}
if (prom_getprop(node, "tce-table-minalign", &minalign,
sizeof(minalign)) == PROM_ERROR)
minalign = 0;
if (prom_getprop(node, "tce-table-minsize", &minsize,
sizeof(minsize)) == PROM_ERROR)
minsize = 4UL << 20;
if (pvr_version_is(PVR_POWER4) || pvr_version_is(PVR_POWER4p))
minsize = 8UL << 20;
else
minsize = 4UL << 20;
align = max(minalign, minsize);
base = alloc_down(minsize, align, 1);
if (base == 0)
prom_panic("ERROR, cannot find space for TCE table.\n");
if (base < local_alloc_bottom)
local_alloc_bottom = base;
memset(path, 0, PROM_SCRATCH_SIZE);
if (call_prom("package-to-path", 3, 1, node,
path, PROM_SCRATCH_SIZE-1) == PROM_ERROR) {
prom_printf("package-to-path failed\n");
}
prom_setprop(node, path, "linux,tce-base", &base, sizeof(base));
prom_setprop(node, path, "linux,tce-size", &minsize, sizeof(minsize));
prom_debug("TCE table: %s\n", path);
prom_debug("\tnode = 0x%x\n", node);
prom_debug("\tbase = 0x%x\n", base);
prom_debug("\tsize = 0x%x\n", minsize);
tce_entryp = (u64 *)base;
for (i = 0; i < (minsize >> 3) ;tce_entryp++, i++) {
tce_entry = (i << PAGE_SHIFT);
tce_entry |= 0x3;
*tce_entryp = tce_entry;
}
prom_printf("opening PHB %s", path);
phb_node = call_prom("open", 1, 1, path);
if (phb_node == 0)
prom_printf("... failed\n");
else
prom_printf("... done\n");
call_prom("call-method", 6, 0, ADDR("set-64-bit-addressing"),
phb_node, -1, minsize,
(u32) base, (u32) (base >> 32));
call_prom("close", 1, 0, phb_node);
}
reserve_mem(local_alloc_bottom, local_alloc_top - local_alloc_bottom);
prom_tce_alloc_start = local_alloc_bottom;
prom_tce_alloc_end = local_alloc_top;
prom_debug("ending prom_initialize_tce_table\n");
}
static void __init prom_hold_cpus(void)
{
unsigned long i;
phandle node;
char type[64];
unsigned long *spinloop
= (void *) LOW_ADDR(__secondary_hold_spinloop);
unsigned long *acknowledge
= (void *) LOW_ADDR(__secondary_hold_acknowledge);
unsigned long secondary_hold = LOW_ADDR(__secondary_hold);
if ((of_platform == PLATFORM_PSERIES ||
of_platform == PLATFORM_PSERIES_LPAR) &&
rtas_has_query_cpu_stopped) {
prom_printf("prom_hold_cpus: skipped\n");
return;
}
prom_debug("prom_hold_cpus: start...\n");
prom_debug(" 1) spinloop = 0x%x\n", (unsigned long)spinloop);
prom_debug(" 1) *spinloop = 0x%x\n", *spinloop);
prom_debug(" 1) acknowledge = 0x%x\n",
(unsigned long)acknowledge);
prom_debug(" 1) *acknowledge = 0x%x\n", *acknowledge);
prom_debug(" 1) secondary_hold = 0x%x\n", secondary_hold);
*spinloop = 0;
for (node = 0; prom_next_node(&node); ) {
unsigned int cpu_no;
__be32 reg;
type[0] = 0;
prom_getprop(node, "device_type", type, sizeof(type));
if (strcmp(type, "cpu") != 0)
continue;
if (prom_getprop(node, "status", type, sizeof(type)) > 0)
if (strcmp(type, "okay") != 0)
continue;
reg = cpu_to_be32(-1);
prom_getprop(node, "reg", &reg, sizeof(reg));
cpu_no = be32_to_cpu(reg);
prom_debug("cpu hw idx = %lu\n", cpu_no);
*acknowledge = (unsigned long)-1;
if (cpu_no != prom.cpu) {
prom_printf("starting cpu hw idx %lu... ", cpu_no);
call_prom("start-cpu", 3, 0, node,
secondary_hold, cpu_no);
for (i = 0; (i < 100000000) &&
(*acknowledge == ((unsigned long)-1)); i++ )
mb();
if (*acknowledge == cpu_no)
prom_printf("done\n");
else
prom_printf("failed: %x\n", *acknowledge);
}
#ifdef CONFIG_SMP
else
prom_printf("boot cpu hw idx %lu\n", cpu_no);
#endif
}
prom_debug("prom_hold_cpus: end...\n");
}
static void __init prom_init_client_services(unsigned long pp)
{
prom_entry = pp;
prom.chosen = call_prom("finddevice", 1, 1, ADDR("/chosen"));
if (!PHANDLE_VALID(prom.chosen))
prom_panic("cannot find chosen");
prom.root = call_prom("finddevice", 1, 1, ADDR("/"));
if (!PHANDLE_VALID(prom.root))
prom_panic("cannot find device tree root");
prom.mmumap = 0;
}
static void __init prom_find_mmu(void)
{
phandle oprom;
char version[64];
oprom = call_prom("finddevice", 1, 1, ADDR("/openprom"));
if (!PHANDLE_VALID(oprom))
return;
if (prom_getprop(oprom, "model", version, sizeof(version)) <= 0)
return;
version[sizeof(version) - 1] = 0;
if (strcmp(version, "Open Firmware, 1.0.5") == 0)
of_workarounds = OF_WA_CLAIM;
else if (strncmp(version, "FirmWorks,3.", 12) == 0) {
of_workarounds = OF_WA_CLAIM | OF_WA_LONGTRAIL;
call_prom("interpret", 1, 1, "dev /memory 0 to allow-reclaim");
} else
return;
prom.memory = call_prom("open", 1, 1, ADDR("/memory"));
prom_getprop(prom.chosen, "mmu", &prom.mmumap,
sizeof(prom.mmumap));
prom.mmumap = be32_to_cpu(prom.mmumap);
if (!IHANDLE_VALID(prom.memory) || !IHANDLE_VALID(prom.mmumap))
of_workarounds &= ~OF_WA_CLAIM;
}
static void __init prom_init_stdout(void)
{
char *path = of_stdout_device;
char type[16];
phandle stdout_node;
__be32 val;
if (prom_getprop(prom.chosen, "stdout", &val, sizeof(val)) <= 0)
prom_panic("cannot find stdout");
prom.stdout = be32_to_cpu(val);
memset(path, 0, 256);
call_prom("instance-to-path", 3, 1, prom.stdout, path, 255);
prom_printf("OF stdout device is: %s\n", of_stdout_device);
prom_setprop(prom.chosen, "/chosen", "linux,stdout-path",
path, strlen(path) + 1);
stdout_node = call_prom("instance-to-package", 1, 1, prom.stdout);
if (stdout_node != PROM_ERROR) {
val = cpu_to_be32(stdout_node);
prom_setprop(prom.chosen, "/chosen", "linux,stdout-package",
&val, sizeof(val));
memset(type, 0, sizeof(type));
prom_getprop(stdout_node, "device_type", type, sizeof(type));
if (strcmp(type, "display") == 0)
prom_setprop(stdout_node, path, "linux,boot-display", NULL, 0);
}
}
static int __init prom_find_machine_type(void)
{
char compat[256];
int len, i = 0;
#ifdef CONFIG_PPC64
phandle rtas;
int x;
#endif
len = prom_getprop(prom.root, "compatible",
compat, sizeof(compat)-1);
if (len > 0) {
compat[len] = 0;
while (i < len) {
char *p = &compat[i];
int sl = strlen(p);
if (sl == 0)
break;
if (strstr(p, "Power Macintosh") ||
strstr(p, "MacRISC"))
return PLATFORM_POWERMAC;
#ifdef CONFIG_PPC64
if (strstr(p, "IBM,CBEA") ||
strstr(p, "IBM,CPBW-1.0"))
return PLATFORM_GENERIC;
#endif
i += sl + 1;
}
}
#ifdef CONFIG_PPC64
if (PHANDLE_VALID(call_prom("finddevice", 1, 1, ADDR("/ibm,opal"))))
return PLATFORM_OPAL;
len = prom_getprop(prom.root, "device_type",
compat, sizeof(compat)-1);
if (len <= 0)
return PLATFORM_GENERIC;
if (strcmp(compat, "chrp"))
return PLATFORM_GENERIC;
rtas = call_prom("finddevice", 1, 1, ADDR("/rtas"));
if (!PHANDLE_VALID(rtas))
return PLATFORM_GENERIC;
x = prom_getproplen(rtas, "ibm,hypertas-functions");
if (x != PROM_ERROR) {
prom_debug("Hypertas detected, assuming LPAR !\n");
return PLATFORM_PSERIES_LPAR;
}
return PLATFORM_PSERIES;
#else
return PLATFORM_GENERIC;
#endif
}
static int __init prom_set_color(ihandle ih, int i, int r, int g, int b)
{
return call_prom("call-method", 6, 1, ADDR("color!"), ih, i, b, g, r);
}
static void __init prom_check_displays(void)
{
char type[16], *path;
phandle node;
ihandle ih;
int i;
static unsigned char default_colors[] = {
0x00, 0x00, 0x00,
0x00, 0x00, 0xaa,
0x00, 0xaa, 0x00,
0x00, 0xaa, 0xaa,
0xaa, 0x00, 0x00,
0xaa, 0x00, 0xaa,
0xaa, 0xaa, 0x00,
0xaa, 0xaa, 0xaa,
0x55, 0x55, 0x55,
0x55, 0x55, 0xff,
0x55, 0xff, 0x55,
0x55, 0xff, 0xff,
0xff, 0x55, 0x55,
0xff, 0x55, 0xff,
0xff, 0xff, 0x55,
0xff, 0xff, 0xff
};
const unsigned char *clut;
prom_debug("Looking for displays\n");
for (node = 0; prom_next_node(&node); ) {
memset(type, 0, sizeof(type));
prom_getprop(node, "device_type", type, sizeof(type));
if (strcmp(type, "display") != 0)
continue;
path = prom_scratch;
memset(path, 0, PROM_SCRATCH_SIZE);
if (call_prom("package-to-path", 3, 1, node, path,
PROM_SCRATCH_SIZE-10) == PROM_ERROR)
continue;
prom_printf("found display : %s, opening... ", path);
ih = call_prom("open", 1, 1, path);
if (ih == 0) {
prom_printf("failed\n");
continue;
}
prom_printf("done\n");
prom_setprop(node, path, "linux,opened", NULL, 0);
clut = default_colors;
for (i = 0; i < 16; i++, clut += 3)
if (prom_set_color(ih, i, clut[0], clut[1],
clut[2]) != 0)
break;
#ifdef CONFIG_LOGO_LINUX_CLUT224
clut = PTRRELOC(logo_linux_clut224.clut);
for (i = 0; i < logo_linux_clut224.clutsize; i++, clut += 3)
if (prom_set_color(ih, i + 32, clut[0], clut[1],
clut[2]) != 0)
break;
#endif
#ifdef CONFIG_PPC_EARLY_DEBUG_BOOTX
if (prom_getprop(node, "linux,boot-display", NULL, 0) !=
PROM_ERROR) {
u32 width, height, pitch, addr;
prom_printf("Setting btext !\n");
prom_getprop(node, "width", &width, 4);
prom_getprop(node, "height", &height, 4);
prom_getprop(node, "linebytes", &pitch, 4);
prom_getprop(node, "address", &addr, 4);
prom_printf("W=%d H=%d LB=%d addr=0x%x\n",
width, height, pitch, addr);
btext_setup_display(width, height, 8, pitch, addr);
}
#endif
}
}
static void __init *make_room(unsigned long *mem_start, unsigned long *mem_end,
unsigned long needed, unsigned long align)
{
void *ret;
*mem_start = _ALIGN(*mem_start, align);
while ((*mem_start + needed) > *mem_end) {
unsigned long room, chunk;
prom_debug("Chunk exhausted, claiming more at %x...\n",
alloc_bottom);
room = alloc_top - alloc_bottom;
if (room > DEVTREE_CHUNK_SIZE)
room = DEVTREE_CHUNK_SIZE;
if (room < PAGE_SIZE)
prom_panic("No memory for flatten_device_tree "
"(no room)\n");
chunk = alloc_up(room, 0);
if (chunk == 0)
prom_panic("No memory for flatten_device_tree "
"(claim failed)\n");
*mem_end = chunk + room;
}
ret = (void *)*mem_start;
*mem_start += needed;
return ret;
}
static unsigned long __init dt_find_string(char *str)
{
char *s, *os;
s = os = (char *)dt_string_start;
s += 4;
while (s < (char *)dt_string_end) {
if (strcmp(s, str) == 0)
return s - os;
s += strlen(s) + 1;
}
return 0;
}
static void __init scan_dt_build_strings(phandle node,
unsigned long *mem_start,
unsigned long *mem_end)
{
char *prev_name, *namep, *sstart;
unsigned long soff;
phandle child;
sstart = (char *)dt_string_start;
prev_name = "";
for (;;) {
namep = make_room(mem_start, mem_end, MAX_PROPERTY_NAME, 1);
if (call_prom("nextprop", 3, 1, node, prev_name, namep) != 1) {
*mem_start = (unsigned long)namep;
break;
}
if (strcmp(namep, "name") == 0) {
*mem_start = (unsigned long)namep;
prev_name = "name";
continue;
}
soff = dt_find_string(namep);
if (soff != 0) {
*mem_start = (unsigned long)namep;
namep = sstart + soff;
} else {
*mem_start = (unsigned long)namep + strlen(namep) + 1;
dt_string_end = *mem_start;
}
prev_name = namep;
}
child = call_prom("child", 1, 1, node);
while (child != 0) {
scan_dt_build_strings(child, mem_start, mem_end);
child = call_prom("peer", 1, 1, child);
}
}
static void __init scan_dt_build_struct(phandle node, unsigned long *mem_start,
unsigned long *mem_end)
{
phandle child;
char *namep, *prev_name, *sstart, *p, *ep, *lp, *path;
unsigned long soff;
unsigned char *valp;
static char pname[MAX_PROPERTY_NAME];
int l, room, has_phandle = 0;
dt_push_token(OF_DT_BEGIN_NODE, mem_start, mem_end);
namep = (char *)*mem_start;
room = *mem_end - *mem_start;
if (room > 255)
room = 255;
l = call_prom("package-to-path", 3, 1, node, namep, room);
if (l >= 0) {
if (l >= room) {
if (l >= *mem_end - *mem_start)
namep = make_room(mem_start, mem_end, l+1, 1);
call_prom("package-to-path", 3, 1, node, namep, l);
}
namep[l] = '\0';
for (lp = p = namep, ep = namep + l; p < ep; p++) {
if (*p == '/')
lp = namep;
else if (*p != 0)
*lp++ = *p;
}
*lp = 0;
*mem_start = _ALIGN((unsigned long)lp + 1, 4);
}
path = prom_scratch;
memset(path, 0, PROM_SCRATCH_SIZE);
call_prom("package-to-path", 3, 1, node, path, PROM_SCRATCH_SIZE-1);
prev_name = "";
sstart = (char *)dt_string_start;
for (;;) {
if (call_prom("nextprop", 3, 1, node, prev_name,
pname) != 1)
break;
if (strcmp(pname, "name") == 0) {
prev_name = "name";
continue;
}
soff = dt_find_string(pname);
if (soff == 0) {
prom_printf("WARNING: Can't find string index for"
" <%s>, node %s\n", pname, path);
break;
}
prev_name = sstart + soff;
l = call_prom("getproplen", 2, 1, node, pname);
if (l == PROM_ERROR)
continue;
dt_push_token(OF_DT_PROP, mem_start, mem_end);
dt_push_token(l, mem_start, mem_end);
dt_push_token(soff, mem_start, mem_end);
valp = make_room(mem_start, mem_end, l, 4);
call_prom("getprop", 4, 1, node, pname, valp, l);
*mem_start = _ALIGN(*mem_start, 4);
if (!strcmp(pname, "phandle"))
has_phandle = 1;
}
if (!has_phandle) {
soff = dt_find_string("linux,phandle");
if (soff == 0)
prom_printf("WARNING: Can't find string index for"
" <linux-phandle> node %s\n", path);
else {
dt_push_token(OF_DT_PROP, mem_start, mem_end);
dt_push_token(4, mem_start, mem_end);
dt_push_token(soff, mem_start, mem_end);
valp = make_room(mem_start, mem_end, 4, 4);
*(__be32 *)valp = cpu_to_be32(node);
}
}
child = call_prom("child", 1, 1, node);
while (child != 0) {
scan_dt_build_struct(child, mem_start, mem_end);
child = call_prom("peer", 1, 1, child);
}
dt_push_token(OF_DT_END_NODE, mem_start, mem_end);
}
static void __init flatten_device_tree(void)
{
phandle root;
unsigned long mem_start, mem_end, room;
struct boot_param_header *hdr;
char *namep;
u64 *rsvmap;
room = alloc_top - alloc_bottom - 0x4000;
if (room > DEVTREE_CHUNK_SIZE)
room = DEVTREE_CHUNK_SIZE;
prom_debug("starting device tree allocs at %x\n", alloc_bottom);
mem_start = (unsigned long)alloc_up(room, PAGE_SIZE);
if (mem_start == 0)
prom_panic("Can't allocate initial device-tree chunk\n");
mem_end = mem_start + room;
root = call_prom("peer", 1, 1, (phandle)0);
if (root == (phandle)0)
prom_panic ("couldn't get device tree root\n");
mem_start = _ALIGN(mem_start, 4);
hdr = make_room(&mem_start, &mem_end,
sizeof(struct boot_param_header), 4);
dt_header_start = (unsigned long)hdr;
rsvmap = make_room(&mem_start, &mem_end, sizeof(mem_reserve_map), 8);
mem_start = PAGE_ALIGN(mem_start);
dt_string_start = mem_start;
mem_start += 4;
namep = make_room(&mem_start, &mem_end, 16, 1);
strcpy(namep, "linux,phandle");
mem_start = (unsigned long)namep + strlen(namep) + 1;
prom_printf("Building dt strings...\n");
scan_dt_build_strings(root, &mem_start, &mem_end);
dt_string_end = mem_start;
mem_start = PAGE_ALIGN(mem_start);
dt_struct_start = mem_start;
prom_printf("Building dt structure...\n");
scan_dt_build_struct(root, &mem_start, &mem_end);
dt_push_token(OF_DT_END, &mem_start, &mem_end);
dt_struct_end = PAGE_ALIGN(mem_start);
hdr->boot_cpuid_phys = cpu_to_be32(prom.cpu);
hdr->magic = cpu_to_be32(OF_DT_HEADER);
hdr->totalsize = cpu_to_be32(dt_struct_end - dt_header_start);
hdr->off_dt_struct = cpu_to_be32(dt_struct_start - dt_header_start);
hdr->off_dt_strings = cpu_to_be32(dt_string_start - dt_header_start);
hdr->dt_strings_size = cpu_to_be32(dt_string_end - dt_string_start);
hdr->off_mem_rsvmap = cpu_to_be32(((unsigned long)rsvmap) - dt_header_start);
hdr->version = cpu_to_be32(OF_DT_VERSION);
hdr->last_comp_version = cpu_to_be32(0x10);
memcpy(rsvmap, mem_reserve_map, sizeof(mem_reserve_map));
#ifdef DEBUG_PROM
{
int i;
prom_printf("reserved memory map:\n");
for (i = 0; i < mem_reserve_cnt; i++)
prom_printf(" %x - %x\n",
be64_to_cpu(mem_reserve_map[i].base),
be64_to_cpu(mem_reserve_map[i].size));
}
#endif
mem_reserve_cnt = MEM_RESERVE_MAP_SIZE;
prom_printf("Device tree strings 0x%x -> 0x%x\n",
dt_string_start, dt_string_end);
prom_printf("Device tree struct 0x%x -> 0x%x\n",
dt_struct_start, dt_struct_end);
}
static void __init fixup_device_tree_maple(void)
{
phandle isa;
u32 rloc = 0x01002000;
u32 isa_ranges[6];
char *name;
name = "/ht@0/isa@4";
isa = call_prom("finddevice", 1, 1, ADDR(name));
if (!PHANDLE_VALID(isa)) {
name = "/ht@0/isa@6";
isa = call_prom("finddevice", 1, 1, ADDR(name));
rloc = 0x01003000;
}
if (!PHANDLE_VALID(isa))
return;
if (prom_getproplen(isa, "ranges") != 12)
return;
if (prom_getprop(isa, "ranges", isa_ranges, sizeof(isa_ranges))
== PROM_ERROR)
return;
if (isa_ranges[0] != 0x1 ||
isa_ranges[1] != 0xf4000000 ||
isa_ranges[2] != 0x00010000)
return;
prom_printf("Fixing up bogus ISA range on Maple/Apache...\n");
isa_ranges[0] = 0x1;
isa_ranges[1] = 0x0;
isa_ranges[2] = rloc;
isa_ranges[3] = 0x0;
isa_ranges[4] = 0x0;
isa_ranges[5] = 0x00010000;
prom_setprop(isa, name, "ranges",
isa_ranges, sizeof(isa_ranges));
}
static void __init fixup_device_tree_maple_memory_controller(void)
{
phandle mc;
u32 mc_reg[4];
char *name = "/hostbridge@f8000000";
u32 ac, sc;
mc = call_prom("finddevice", 1, 1, ADDR(name));
if (!PHANDLE_VALID(mc))
return;
if (prom_getproplen(mc, "reg") != 8)
return;
prom_getprop(prom.root, "#address-cells", &ac, sizeof(ac));
prom_getprop(prom.root, "#size-cells", &sc, sizeof(sc));
if ((ac != 2) || (sc != 2))
return;
if (prom_getprop(mc, "reg", mc_reg, sizeof(mc_reg)) == PROM_ERROR)
return;
if (mc_reg[0] != CPC925_MC_START || mc_reg[1] != CPC925_MC_LENGTH)
return;
prom_printf("Fixing up bogus hostbridge on Maple...\n");
mc_reg[0] = 0x0;
mc_reg[1] = CPC925_MC_START;
mc_reg[2] = 0x0;
mc_reg[3] = CPC925_MC_LENGTH;
prom_setprop(mc, name, "reg", mc_reg, sizeof(mc_reg));
}
static void __init fixup_device_tree_chrp(void)
{
phandle ph;
u32 prop[6];
u32 rloc = 0x01006000;
char *name;
int rc;
name = "/pci@80000000/isa@c";
ph = call_prom("finddevice", 1, 1, ADDR(name));
if (!PHANDLE_VALID(ph)) {
name = "/pci@ff500000/isa@6";
ph = call_prom("finddevice", 1, 1, ADDR(name));
rloc = 0x01003000;
}
if (PHANDLE_VALID(ph)) {
rc = prom_getproplen(ph, "ranges");
if (rc == 0 || rc == PROM_ERROR) {
prom_printf("Fixing up missing ISA range on Pegasos...\n");
prop[0] = 0x1;
prop[1] = 0x0;
prop[2] = rloc;
prop[3] = 0x0;
prop[4] = 0x0;
prop[5] = 0x00010000;
prom_setprop(ph, name, "ranges", prop, sizeof(prop));
}
}
name = "/pci@80000000/ide@C,1";
ph = call_prom("finddevice", 1, 1, ADDR(name));
if (PHANDLE_VALID(ph)) {
prom_printf("Fixing up IDE interrupt on Pegasos...\n");
prop[0] = 14;
prop[1] = 0x0;
prom_setprop(ph, name, "interrupts", prop, 2*sizeof(u32));
prom_printf("Fixing up IDE class-code on Pegasos...\n");
rc = prom_getprop(ph, "class-code", prop, sizeof(u32));
if (rc == sizeof(u32)) {
prop[0] &= ~0x5;
prom_setprop(ph, name, "class-code", prop, sizeof(u32));
}
}
}
static void __init fixup_device_tree_pmac(void)
{
phandle u3, i2c, mpic;
u32 u3_rev;
u32 interrupts[2];
u32 parent;
u3 = call_prom("finddevice", 1, 1, ADDR("/u3@0,f8000000"));
if (!PHANDLE_VALID(u3))
return;
i2c = call_prom("finddevice", 1, 1, ADDR("/u3@0,f8000000/i2c@f8001000"));
if (!PHANDLE_VALID(i2c))
return;
mpic = call_prom("finddevice", 1, 1, ADDR("/u3@0,f8000000/mpic@f8040000"));
if (!PHANDLE_VALID(mpic))
return;
if (prom_getprop(u3, "device-rev", &u3_rev, sizeof(u3_rev))
== PROM_ERROR)
return;
if (u3_rev < 0x35 || u3_rev > 0x39)
return;
if (prom_getproplen(i2c, "interrupts") > 0)
return;
prom_printf("fixing up bogus interrupts for u3 i2c...\n");
interrupts[0] = 0;
interrupts[1] = 1;
prom_setprop(i2c, "/u3@0,f8000000/i2c@f8001000", "interrupts",
&interrupts, sizeof(interrupts));
parent = (u32)mpic;
prom_setprop(i2c, "/u3@0,f8000000/i2c@f8001000", "interrupt-parent",
&parent, sizeof(parent));
}
static void __init fixup_device_tree_efika_add_phy(void)
{
u32 node;
char prop[64];
int rv;
node = call_prom("finddevice", 1, 1, ADDR("/builtin/ethernet"));
if (!PHANDLE_VALID(node))
return;
rv = prom_getprop(node, "phy-handle", prop, sizeof(prop));
if (!rv)
return;
node = call_prom("finddevice", 1, 1, ADDR("/builtin/mdio"));
if (!PHANDLE_VALID(node)) {
prom_printf("Adding Ethernet MDIO node\n");
call_prom("interpret", 1, 1,
" s\" /builtin\" find-device"
" new-device"
" 1 encode-int s\" #address-cells\" property"
" 0 encode-int s\" #size-cells\" property"
" s\" mdio\" device-name"
" s\" fsl,mpc5200b-mdio\" encode-string"
" s\" compatible\" property"
" 0xf0003000 0x400 reg"
" 0x2 encode-int"
" 0x5 encode-int encode+"
" 0x3 encode-int encode+"
" s\" interrupts\" property"
" finish-device");
};
node = call_prom("finddevice", 1, 1,
ADDR("/builtin/mdio/ethernet-phy"));
if (!PHANDLE_VALID(node)) {
prom_printf("Adding Ethernet PHY node\n");
call_prom("interpret", 1, 1,
" s\" /builtin/mdio\" find-device"
" new-device"
" s\" ethernet-phy\" device-name"
" 0x10 encode-int s\" reg\" property"
" my-self"
" ihandle>phandle"
" finish-device"
" s\" /builtin/ethernet\" find-device"
" encode-int"
" s\" phy-handle\" property"
" device-end");
}
}
static void __init fixup_device_tree_efika(void)
{
int sound_irq[3] = { 2, 2, 0 };
int bcomm_irq[3*16] = { 3,0,0, 3,1,0, 3,2,0, 3,3,0,
3,4,0, 3,5,0, 3,6,0, 3,7,0,
3,8,0, 3,9,0, 3,10,0, 3,11,0,
3,12,0, 3,13,0, 3,14,0, 3,15,0 };
u32 node;
char prop[64];
int rv, len;
node = call_prom("finddevice", 1, 1, ADDR("/"));
if (!PHANDLE_VALID(node))
return;
rv = prom_getprop(node, "model", prop, sizeof(prop));
if (rv == PROM_ERROR)
return;
if (strcmp(prop, "EFIKA5K2"))
return;
prom_printf("Applying EFIKA device tree fixups\n");
node = call_prom("finddevice", 1, 1, ADDR("/"));
rv = prom_getprop(node, "device_type", prop, sizeof(prop));
if (rv != PROM_ERROR && (strcmp(prop, "chrp") == 0))
prom_setprop(node, "/", "device_type", "efika", sizeof("efika"));
rv = prom_getprop(node, "CODEGEN,description", prop, sizeof(prop));
if (rv != PROM_ERROR && (strstr(prop, "CHRP")))
prom_setprop(node, "/", "CODEGEN,description",
"Efika 5200B PowerPC System",
sizeof("Efika 5200B PowerPC System"));
node = call_prom("finddevice", 1, 1, ADDR("/builtin/bestcomm"));
if (PHANDLE_VALID(node)) {
len = prom_getproplen(node, "interrupts");
if (len == 12) {
prom_printf("Fixing bestcomm interrupts property\n");
prom_setprop(node, "/builtin/bestcom", "interrupts",
bcomm_irq, sizeof(bcomm_irq));
}
}
node = call_prom("finddevice", 1, 1, ADDR("/builtin/sound"));
if (PHANDLE_VALID(node)) {
rv = prom_getprop(node, "interrupts", prop, sizeof(prop));
if (rv == PROM_ERROR) {
prom_printf("Adding sound interrupts property\n");
prom_setprop(node, "/builtin/sound", "interrupts",
sound_irq, sizeof(sound_irq));
}
}
fixup_device_tree_efika_add_phy();
}
static void __init fixup_device_tree(void)
{
fixup_device_tree_maple();
fixup_device_tree_maple_memory_controller();
fixup_device_tree_chrp();
fixup_device_tree_pmac();
fixup_device_tree_efika();
}
static void __init prom_find_boot_cpu(void)
{
__be32 rval;
ihandle prom_cpu;
phandle cpu_pkg;
rval = 0;
if (prom_getprop(prom.chosen, "cpu", &rval, sizeof(rval)) <= 0)
return;
prom_cpu = be32_to_cpu(rval);
cpu_pkg = call_prom("instance-to-package", 1, 1, prom_cpu);
prom_getprop(cpu_pkg, "reg", &rval, sizeof(rval));
prom.cpu = be32_to_cpu(rval);
prom_debug("Booting CPU hw index = %lu\n", prom.cpu);
}
static void __init prom_check_initrd(unsigned long r3, unsigned long r4)
{
#ifdef CONFIG_BLK_DEV_INITRD
if (r3 && r4 && r4 != 0xdeadbeef) {
__be64 val;
prom_initrd_start = is_kernel_addr(r3) ? __pa(r3) : r3;
prom_initrd_end = prom_initrd_start + r4;
val = cpu_to_be64(prom_initrd_start);
prom_setprop(prom.chosen, "/chosen", "linux,initrd-start",
&val, sizeof(val));
val = cpu_to_be64(prom_initrd_end);
prom_setprop(prom.chosen, "/chosen", "linux,initrd-end",
&val, sizeof(val));
reserve_mem(prom_initrd_start,
prom_initrd_end - prom_initrd_start);
prom_debug("initrd_start=0x%x\n", prom_initrd_start);
prom_debug("initrd_end=0x%x\n", prom_initrd_end);
}
#endif
}
static void reloc_toc(void)
{
}
static void unreloc_toc(void)
{
}
static void __reloc_toc(unsigned long offset, unsigned long nr_entries)
{
unsigned long i;
unsigned long *toc_entry;
asm volatile("addi %0,2,-0x8000" : "=b" (toc_entry));
for (i = 0; i < nr_entries; i++) {
*toc_entry = *toc_entry + offset;
toc_entry++;
}
}
static void reloc_toc(void)
{
unsigned long offset = reloc_offset();
unsigned long nr_entries =
(__prom_init_toc_end - __prom_init_toc_start) / sizeof(long);
__reloc_toc(offset, nr_entries);
mb();
}
static void unreloc_toc(void)
{
unsigned long offset = reloc_offset();
unsigned long nr_entries =
(__prom_init_toc_end - __prom_init_toc_start) / sizeof(long);
mb();
__reloc_toc(-offset, nr_entries);
}
unsigned long __init prom_init(unsigned long r3, unsigned long r4,
unsigned long pp,
unsigned long r6, unsigned long r7,
unsigned long kbase)
{
unsigned long hdr;
#ifdef CONFIG_PPC32
unsigned long offset = reloc_offset();
reloc_got2(offset);
#else
reloc_toc();
#endif
memset(&__bss_start, 0, __bss_stop - __bss_start);
prom_init_client_services(pp);
prom_find_mmu();
prom_init_stdout();
prom_printf("Preparing to boot %s", linux_banner);
of_platform = prom_find_machine_type();
prom_printf("Detected machine type: %x\n", of_platform);
#ifndef CONFIG_NONSTATIC_KERNEL
if (PHYSICAL_START > 0)
prom_panic("Error: You can't boot a kdump kernel from OF!\n");
#endif
prom_check_initrd(r3, r4);
#if defined(CONFIG_PPC_PSERIES) || defined(CONFIG_PPC_POWERNV)
if (of_platform == PLATFORM_PSERIES ||
of_platform == PLATFORM_PSERIES_LPAR)
prom_send_capabilities();
#endif
if (of_platform != PLATFORM_POWERMAC)
copy_and_flush(0, kbase, 0x100, 0);
early_cmdline_parse();
prom_init_mem();
prom_find_boot_cpu();
prom_check_displays();
#if defined(CONFIG_PPC64) && defined(__BIG_ENDIAN__)
if (of_platform == PLATFORM_PSERIES)
prom_initialize_tce_table();
#endif
if (of_platform != PLATFORM_POWERMAC &&
of_platform != PLATFORM_OPAL)
prom_instantiate_rtas();
#ifdef CONFIG_PPC_POWERNV
#ifdef __BIG_ENDIAN__
if (of_platform == PLATFORM_PSERIES_LPAR) {
prom_query_opal();
if (of_platform == PLATFORM_OPAL) {
prom_opal_hold_cpus();
prom_opal_takeover();
}
} else
#endif
if (of_platform == PLATFORM_OPAL)
prom_instantiate_opal();
#endif
#ifdef CONFIG_PPC64
prom_instantiate_sml();
#endif
if (of_platform != PLATFORM_POWERMAC &&
of_platform != PLATFORM_OPAL)
prom_hold_cpus();
if (prom_memory_limit) {
__be64 val = cpu_to_be64(prom_memory_limit);
prom_setprop(prom.chosen, "/chosen", "linux,memory-limit",
&val, sizeof(val));
}
#ifdef CONFIG_PPC64
if (prom_iommu_off)
prom_setprop(prom.chosen, "/chosen", "linux,iommu-off",
NULL, 0);
if (prom_iommu_force_on)
prom_setprop(prom.chosen, "/chosen", "linux,iommu-force-on",
NULL, 0);
if (prom_tce_alloc_start) {
prom_setprop(prom.chosen, "/chosen", "linux,tce-alloc-start",
&prom_tce_alloc_start,
sizeof(prom_tce_alloc_start));
prom_setprop(prom.chosen, "/chosen", "linux,tce-alloc-end",
&prom_tce_alloc_end,
sizeof(prom_tce_alloc_end));
}
#endif
fixup_device_tree();
prom_printf("copying OF device tree...\n");
flatten_device_tree();
if (of_platform != PLATFORM_POWERMAC &&
of_platform != PLATFORM_OPAL)
prom_close_stdin();
prom_printf("Calling quiesce...\n");
call_prom("quiesce", 0, 0);
hdr = dt_header_start;
if (of_platform != PLATFORM_OPAL) {
prom_printf("returning from prom_init\n");
prom_debug("->dt_header_start=0x%x\n", hdr);
}
#ifdef CONFIG_PPC32
reloc_got2(-offset);
#else
unreloc_toc();
#endif
#ifdef CONFIG_PPC_EARLY_DEBUG_OPAL
__start(hdr, kbase, 0, 0, 0,
prom_opal_base, prom_opal_entry);
#else
__start(hdr, kbase, 0, 0, 0, 0, 0);
#endif
return 0;
}
