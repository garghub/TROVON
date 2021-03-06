static int __init
x86_get_mtrr_mem_range(struct range *range, int nr_range,
unsigned long extra_remove_base,
unsigned long extra_remove_size)
{
unsigned long base, size;
mtrr_type type;
int i;
for (i = 0; i < num_var_ranges; i++) {
type = range_state[i].type;
if (type != MTRR_TYPE_WRBACK)
continue;
base = range_state[i].base_pfn;
size = range_state[i].size_pfn;
nr_range = add_range_with_merge(range, RANGE_NUM, nr_range,
base, base + size);
}
if (debug_print) {
printk(KERN_DEBUG "After WB checking\n");
for (i = 0; i < nr_range; i++)
printk(KERN_DEBUG "MTRR MAP PFN: %016llx - %016llx\n",
range[i].start, range[i].end);
}
for (i = 0; i < num_var_ranges; i++) {
type = range_state[i].type;
if (type != MTRR_TYPE_UNCACHABLE &&
type != MTRR_TYPE_WRPROT)
continue;
size = range_state[i].size_pfn;
if (!size)
continue;
base = range_state[i].base_pfn;
if (base < (1<<(20-PAGE_SHIFT)) && mtrr_state.have_fixed &&
(mtrr_state.enabled & 1)) {
printk(BIOS_BUG_MSG, i);
if (base + size <= (1<<(20-PAGE_SHIFT)))
continue;
size -= (1<<(20-PAGE_SHIFT)) - base;
base = 1<<(20-PAGE_SHIFT);
}
subtract_range(range, RANGE_NUM, base, base + size);
}
if (extra_remove_size)
subtract_range(range, RANGE_NUM, extra_remove_base,
extra_remove_base + extra_remove_size);
if (debug_print) {
printk(KERN_DEBUG "After UC checking\n");
for (i = 0; i < RANGE_NUM; i++) {
if (!range[i].end)
continue;
printk(KERN_DEBUG "MTRR MAP PFN: %016llx - %016llx\n",
range[i].start, range[i].end);
}
}
nr_range = clean_sort_range(range, RANGE_NUM);
if (debug_print) {
printk(KERN_DEBUG "After sorting\n");
for (i = 0; i < nr_range; i++)
printk(KERN_DEBUG "MTRR MAP PFN: %016llx - %016llx\n",
range[i].start, range[i].end);
}
return nr_range;
}
static unsigned long __init sum_ranges(struct range *range, int nr_range)
{
unsigned long sum = 0;
int i;
for (i = 0; i < nr_range; i++)
sum += range[i].end - range[i].start;
return sum;
}
static int __init disable_mtrr_cleanup_setup(char *str)
{
enable_mtrr_cleanup = 0;
return 0;
}
static int __init enable_mtrr_cleanup_setup(char *str)
{
enable_mtrr_cleanup = 1;
return 0;
}
static int __init mtrr_cleanup_debug_setup(char *str)
{
debug_print = 1;
return 0;
}
static void __init
set_var_mtrr(unsigned int reg, unsigned long basek, unsigned long sizek,
unsigned char type, unsigned int address_bits)
{
u32 base_lo, base_hi, mask_lo, mask_hi;
u64 base, mask;
if (!sizek) {
fill_mtrr_var_range(reg, 0, 0, 0, 0);
return;
}
mask = (1ULL << address_bits) - 1;
mask &= ~((((u64)sizek) << 10) - 1);
base = ((u64)basek) << 10;
base |= type;
mask |= 0x800;
base_lo = base & ((1ULL<<32) - 1);
base_hi = base >> 32;
mask_lo = mask & ((1ULL<<32) - 1);
mask_hi = mask >> 32;
fill_mtrr_var_range(reg, base_lo, base_hi, mask_lo, mask_hi);
}
static void __init
save_var_mtrr(unsigned int reg, unsigned long basek, unsigned long sizek,
unsigned char type)
{
range_state[reg].base_pfn = basek >> (PAGE_SHIFT - 10);
range_state[reg].size_pfn = sizek >> (PAGE_SHIFT - 10);
range_state[reg].type = type;
}
static void __init set_var_mtrr_all(unsigned int address_bits)
{
unsigned long basek, sizek;
unsigned char type;
unsigned int reg;
for (reg = 0; reg < num_var_ranges; reg++) {
basek = range_state[reg].base_pfn << (PAGE_SHIFT - 10);
sizek = range_state[reg].size_pfn << (PAGE_SHIFT - 10);
type = range_state[reg].type;
set_var_mtrr(reg, basek, sizek, type, address_bits);
}
}
static unsigned long to_size_factor(unsigned long sizek, char *factorp)
{
unsigned long base = sizek;
char factor;
if (base & ((1<<10) - 1)) {
factor = 'K';
} else if (base & ((1<<20) - 1)) {
factor = 'M';
base >>= 10;
} else {
factor = 'G';
base >>= 20;
}
*factorp = factor;
return base;
}
static unsigned int __init
range_to_mtrr(unsigned int reg, unsigned long range_startk,
unsigned long range_sizek, unsigned char type)
{
if (!range_sizek || (reg >= num_var_ranges))
return reg;
while (range_sizek) {
unsigned long max_align, align;
unsigned long sizek;
if (range_startk)
max_align = __ffs(range_startk);
else
max_align = BITS_PER_LONG - 1;
align = __fls(range_sizek);
if (align > max_align)
align = max_align;
sizek = 1UL << align;
if (debug_print) {
char start_factor = 'K', size_factor = 'K';
unsigned long start_base, size_base;
start_base = to_size_factor(range_startk, &start_factor);
size_base = to_size_factor(sizek, &size_factor);
Dprintk("Setting variable MTRR %d, "
"base: %ld%cB, range: %ld%cB, type %s\n",
reg, start_base, start_factor,
size_base, size_factor,
(type == MTRR_TYPE_UNCACHABLE) ? "UC" :
((type == MTRR_TYPE_WRBACK) ? "WB" : "Other")
);
}
save_var_mtrr(reg++, range_startk, sizek, type);
range_startk += sizek;
range_sizek -= sizek;
if (reg >= num_var_ranges)
break;
}
return reg;
}
static unsigned __init
range_to_mtrr_with_hole(struct var_mtrr_state *state, unsigned long basek,
unsigned long sizek)
{
unsigned long hole_basek, hole_sizek;
unsigned long second_basek, second_sizek;
unsigned long range0_basek, range0_sizek;
unsigned long range_basek, range_sizek;
unsigned long chunk_sizek;
unsigned long gran_sizek;
hole_basek = 0;
hole_sizek = 0;
second_basek = 0;
second_sizek = 0;
chunk_sizek = state->chunk_sizek;
gran_sizek = state->gran_sizek;
range_basek = ALIGN(state->range_startk, gran_sizek);
if ((range_basek > basek) && basek)
return second_sizek;
state->range_sizek -= (range_basek - state->range_startk);
range_sizek = ALIGN(state->range_sizek, gran_sizek);
while (range_sizek > state->range_sizek) {
range_sizek -= gran_sizek;
if (!range_sizek)
return 0;
}
state->range_sizek = range_sizek;
range0_basek = state->range_startk;
range0_sizek = ALIGN(state->range_sizek, chunk_sizek);
if (range0_sizek == state->range_sizek) {
Dprintk("rangeX: %016lx - %016lx\n",
range0_basek<<10,
(range0_basek + state->range_sizek)<<10);
state->reg = range_to_mtrr(state->reg, range0_basek,
state->range_sizek, MTRR_TYPE_WRBACK);
return 0;
}
if (sizek) {
while (range0_basek + range0_sizek > (basek + sizek)) {
if (range0_sizek >= chunk_sizek)
range0_sizek -= chunk_sizek;
else
range0_sizek = 0;
if (!range0_sizek)
break;
}
}
second_try:
range_basek = range0_basek + range0_sizek;
if (range_basek > basek && range_basek <= (basek + sizek))
second_sizek = range_basek - basek;
if (range0_sizek > state->range_sizek) {
hole_sizek = range0_sizek - state->range_sizek - second_sizek;
if (hole_sizek >= (range0_sizek >> 1) &&
range0_sizek >= chunk_sizek) {
range0_sizek -= chunk_sizek;
second_sizek = 0;
hole_sizek = 0;
goto second_try;
}
}
if (range0_sizek) {
Dprintk("range0: %016lx - %016lx\n",
range0_basek<<10,
(range0_basek + range0_sizek)<<10);
state->reg = range_to_mtrr(state->reg, range0_basek,
range0_sizek, MTRR_TYPE_WRBACK);
}
if (range0_sizek < state->range_sizek) {
range_sizek = state->range_sizek - range0_sizek;
Dprintk("range: %016lx - %016lx\n",
range_basek<<10,
(range_basek + range_sizek)<<10);
state->reg = range_to_mtrr(state->reg, range_basek,
range_sizek, MTRR_TYPE_WRBACK);
}
if (hole_sizek) {
hole_basek = range_basek - hole_sizek - second_sizek;
Dprintk("hole: %016lx - %016lx\n",
hole_basek<<10,
(hole_basek + hole_sizek)<<10);
state->reg = range_to_mtrr(state->reg, hole_basek,
hole_sizek, MTRR_TYPE_UNCACHABLE);
}
return second_sizek;
}
static void __init
set_var_mtrr_range(struct var_mtrr_state *state, unsigned long base_pfn,
unsigned long size_pfn)
{
unsigned long basek, sizek;
unsigned long second_sizek = 0;
if (state->reg >= num_var_ranges)
return;
basek = base_pfn << (PAGE_SHIFT - 10);
sizek = size_pfn << (PAGE_SHIFT - 10);
if ((basek <= 1024) ||
(state->range_startk + state->range_sizek == basek)) {
unsigned long endk = basek + sizek;
state->range_sizek = endk - state->range_startk;
return;
}
if (state->range_sizek != 0)
second_sizek = range_to_mtrr_with_hole(state, basek, sizek);
state->range_startk = basek + second_sizek;
state->range_sizek = sizek - second_sizek;
}
static int __init parse_mtrr_chunk_size_opt(char *p)
{
if (!p)
return -EINVAL;
mtrr_chunk_size = memparse(p, &p);
return 0;
}
static int __init parse_mtrr_gran_size_opt(char *p)
{
if (!p)
return -EINVAL;
mtrr_gran_size = memparse(p, &p);
return 0;
}
static int __init parse_mtrr_spare_reg(char *arg)
{
if (arg)
nr_mtrr_spare_reg = simple_strtoul(arg, NULL, 0);
return 0;
}
static int __init
x86_setup_var_mtrrs(struct range *range, int nr_range,
u64 chunk_size, u64 gran_size)
{
struct var_mtrr_state var_state;
int num_reg;
int i;
var_state.range_startk = 0;
var_state.range_sizek = 0;
var_state.reg = 0;
var_state.chunk_sizek = chunk_size >> 10;
var_state.gran_sizek = gran_size >> 10;
memset(range_state, 0, sizeof(range_state));
for (i = 0; i < nr_range; i++) {
set_var_mtrr_range(&var_state, range[i].start,
range[i].end - range[i].start);
}
if (var_state.range_sizek != 0)
range_to_mtrr_with_hole(&var_state, 0, 0);
num_reg = var_state.reg;
while (var_state.reg < num_var_ranges) {
save_var_mtrr(var_state.reg, 0, 0, 0);
var_state.reg++;
}
return num_reg;
}
static void __init print_out_mtrr_range_state(void)
{
char start_factor = 'K', size_factor = 'K';
unsigned long start_base, size_base;
mtrr_type type;
int i;
for (i = 0; i < num_var_ranges; i++) {
size_base = range_state[i].size_pfn << (PAGE_SHIFT - 10);
if (!size_base)
continue;
size_base = to_size_factor(size_base, &size_factor),
start_base = range_state[i].base_pfn << (PAGE_SHIFT - 10);
start_base = to_size_factor(start_base, &start_factor),
type = range_state[i].type;
printk(KERN_DEBUG "reg %d, base: %ld%cB, range: %ld%cB, type %s\n",
i, start_base, start_factor,
size_base, size_factor,
(type == MTRR_TYPE_UNCACHABLE) ? "UC" :
((type == MTRR_TYPE_WRPROT) ? "WP" :
((type == MTRR_TYPE_WRBACK) ? "WB" : "Other"))
);
}
}
static int __init mtrr_need_cleanup(void)
{
int i;
mtrr_type type;
unsigned long size;
int num[MTRR_NUM_TYPES + 1];
memset(num, 0, sizeof(num));
for (i = 0; i < num_var_ranges; i++) {
type = range_state[i].type;
size = range_state[i].size_pfn;
if (type >= MTRR_NUM_TYPES)
continue;
if (!size)
type = MTRR_NUM_TYPES;
num[type]++;
}
if (!num[MTRR_TYPE_UNCACHABLE])
return 0;
if (num[MTRR_TYPE_WRBACK] + num[MTRR_TYPE_UNCACHABLE] !=
num_var_ranges - num[MTRR_NUM_TYPES])
return 0;
return 1;
}
static void __init
mtrr_calc_range_state(u64 chunk_size, u64 gran_size,
unsigned long x_remove_base,
unsigned long x_remove_size, int i)
{
static struct range range_new[RANGE_NUM];
unsigned long range_sums_new;
static int nr_range_new;
int num_reg;
num_reg = x86_setup_var_mtrrs(range, nr_range, chunk_size, gran_size);
memset(range_new, 0, sizeof(range_new));
nr_range_new = x86_get_mtrr_mem_range(range_new, 0,
x_remove_base, x_remove_size);
range_sums_new = sum_ranges(range_new, nr_range_new);
result[i].chunk_sizek = chunk_size >> 10;
result[i].gran_sizek = gran_size >> 10;
result[i].num_reg = num_reg;
if (range_sums < range_sums_new) {
result[i].lose_cover_sizek = (range_sums_new - range_sums) << PSHIFT;
result[i].bad = 1;
} else {
result[i].lose_cover_sizek = (range_sums - range_sums_new) << PSHIFT;
}
if (!result[i].bad && !result[i].lose_cover_sizek) {
if (nr_range_new != nr_range || memcmp(range, range_new, sizeof(range)))
result[i].bad = 1;
}
if (!result[i].bad && (range_sums - range_sums_new < min_loss_pfn[num_reg]))
min_loss_pfn[num_reg] = range_sums - range_sums_new;
}
static void __init mtrr_print_out_one_result(int i)
{
unsigned long gran_base, chunk_base, lose_base;
char gran_factor, chunk_factor, lose_factor;
gran_base = to_size_factor(result[i].gran_sizek, &gran_factor);
chunk_base = to_size_factor(result[i].chunk_sizek, &chunk_factor);
lose_base = to_size_factor(result[i].lose_cover_sizek, &lose_factor);
pr_info("%sgran_size: %ld%c \tchunk_size: %ld%c \t",
result[i].bad ? "*BAD*" : " ",
gran_base, gran_factor, chunk_base, chunk_factor);
pr_cont("num_reg: %d \tlose cover RAM: %s%ld%c\n",
result[i].num_reg, result[i].bad ? "-" : "",
lose_base, lose_factor);
}
static int __init mtrr_search_optimal_index(void)
{
int num_reg_good;
int index_good;
int i;
if (nr_mtrr_spare_reg >= num_var_ranges)
nr_mtrr_spare_reg = num_var_ranges - 1;
num_reg_good = -1;
for (i = num_var_ranges - nr_mtrr_spare_reg; i > 0; i--) {
if (!min_loss_pfn[i])
num_reg_good = i;
}
index_good = -1;
if (num_reg_good != -1) {
for (i = 0; i < NUM_RESULT; i++) {
if (!result[i].bad &&
result[i].num_reg == num_reg_good &&
!result[i].lose_cover_sizek) {
index_good = i;
break;
}
}
}
return index_good;
}
int __init mtrr_cleanup(unsigned address_bits)
{
unsigned long x_remove_base, x_remove_size;
unsigned long base, size, def, dummy;
u64 chunk_size, gran_size;
mtrr_type type;
int index_good;
int i;
if (!is_cpu(INTEL) || enable_mtrr_cleanup < 1)
return 0;
rdmsr(MSR_MTRRdefType, def, dummy);
def &= 0xff;
if (def != MTRR_TYPE_UNCACHABLE)
return 0;
memset(range_state, 0, sizeof(range_state));
for (i = 0; i < num_var_ranges; i++) {
mtrr_if->get(i, &base, &size, &type);
range_state[i].base_pfn = base;
range_state[i].size_pfn = size;
range_state[i].type = type;
}
if (!mtrr_need_cleanup())
return 0;
printk(KERN_DEBUG "original variable MTRRs\n");
print_out_mtrr_range_state();
memset(range, 0, sizeof(range));
x_remove_size = 0;
x_remove_base = 1 << (32 - PAGE_SHIFT);
if (mtrr_tom2)
x_remove_size = (mtrr_tom2 >> PAGE_SHIFT) - x_remove_base;
nr_range = x86_get_mtrr_mem_range(range, 0, x_remove_base, x_remove_size);
nr_range = add_range_with_merge(range, RANGE_NUM, nr_range, 0,
1ULL<<(20 - PAGE_SHIFT));
sort_range(range, nr_range);
range_sums = sum_ranges(range, nr_range);
printk(KERN_INFO "total RAM covered: %ldM\n",
range_sums >> (20 - PAGE_SHIFT));
if (mtrr_chunk_size && mtrr_gran_size) {
i = 0;
mtrr_calc_range_state(mtrr_chunk_size, mtrr_gran_size,
x_remove_base, x_remove_size, i);
mtrr_print_out_one_result(i);
if (!result[i].bad) {
set_var_mtrr_all(address_bits);
printk(KERN_DEBUG "New variable MTRRs\n");
print_out_mtrr_range_state();
return 1;
}
printk(KERN_INFO "invalid mtrr_gran_size or mtrr_chunk_size, "
"will find optimal one\n");
}
i = 0;
memset(min_loss_pfn, 0xff, sizeof(min_loss_pfn));
memset(result, 0, sizeof(result));
for (gran_size = (1ULL<<16); gran_size < (1ULL<<32); gran_size <<= 1) {
for (chunk_size = gran_size; chunk_size < (1ULL<<32);
chunk_size <<= 1) {
if (i >= NUM_RESULT)
continue;
mtrr_calc_range_state(chunk_size, gran_size,
x_remove_base, x_remove_size, i);
if (debug_print) {
mtrr_print_out_one_result(i);
printk(KERN_INFO "\n");
}
i++;
}
}
index_good = mtrr_search_optimal_index();
if (index_good != -1) {
printk(KERN_INFO "Found optimal setting for mtrr clean up\n");
i = index_good;
mtrr_print_out_one_result(i);
chunk_size = result[i].chunk_sizek;
chunk_size <<= 10;
gran_size = result[i].gran_sizek;
gran_size <<= 10;
x86_setup_var_mtrrs(range, nr_range, chunk_size, gran_size);
set_var_mtrr_all(address_bits);
printk(KERN_DEBUG "New variable MTRRs\n");
print_out_mtrr_range_state();
return 1;
} else {
for (i = 0; i < NUM_RESULT; i++)
mtrr_print_out_one_result(i);
}
printk(KERN_INFO "mtrr_cleanup: can not find optimal value\n");
printk(KERN_INFO "please specify mtrr_gran_size/mtrr_chunk_size\n");
return 0;
}
int __init mtrr_cleanup(unsigned address_bits)
{
return 0;
}
static int __init disable_mtrr_trim_setup(char *str)
{
disable_mtrr_trim = 1;
return 0;
}
int __init amd_special_default_mtrr(void)
{
u32 l, h;
if (boot_cpu_data.x86_vendor != X86_VENDOR_AMD)
return 0;
if (boot_cpu_data.x86 < 0xf)
return 0;
if (rdmsr_safe(MSR_K8_SYSCFG, &l, &h) < 0)
return 0;
if ((l & (Tom2Enabled | Tom2ForceMemTypeWB)) ==
(Tom2Enabled | Tom2ForceMemTypeWB))
return 1;
return 0;
}
static u64 __init
real_trim_memory(unsigned long start_pfn, unsigned long limit_pfn)
{
u64 trim_start, trim_size;
trim_start = start_pfn;
trim_start <<= PAGE_SHIFT;
trim_size = limit_pfn;
trim_size <<= PAGE_SHIFT;
trim_size -= trim_start;
return e820_update_range(trim_start, trim_size, E820_RAM, E820_RESERVED);
}
int __init mtrr_trim_uncached_memory(unsigned long end_pfn)
{
unsigned long i, base, size, highest_pfn = 0, def, dummy;
mtrr_type type;
u64 total_trim_size;
int num[MTRR_NUM_TYPES + 1];
if (!is_cpu(INTEL) || disable_mtrr_trim)
return 0;
rdmsr(MSR_MTRRdefType, def, dummy);
def &= 0xff;
if (def != MTRR_TYPE_UNCACHABLE)
return 0;
memset(range_state, 0, sizeof(range_state));
for (i = 0; i < num_var_ranges; i++) {
mtrr_if->get(i, &base, &size, &type);
range_state[i].base_pfn = base;
range_state[i].size_pfn = size;
range_state[i].type = type;
}
for (i = 0; i < num_var_ranges; i++) {
type = range_state[i].type;
if (type != MTRR_TYPE_WRBACK)
continue;
base = range_state[i].base_pfn;
size = range_state[i].size_pfn;
if (highest_pfn < base + size)
highest_pfn = base + size;
}
if (!highest_pfn) {
printk(KERN_INFO "CPU MTRRs all blank - virtualized system.\n");
return 0;
}
memset(num, 0, sizeof(num));
for (i = 0; i < num_var_ranges; i++) {
type = range_state[i].type;
if (type >= MTRR_NUM_TYPES)
continue;
size = range_state[i].size_pfn;
if (!size)
type = MTRR_NUM_TYPES;
num[type]++;
}
if (!num[MTRR_TYPE_WRBACK])
return 0;
if (num[MTRR_TYPE_WRBACK] + num[MTRR_TYPE_UNCACHABLE] !=
num_var_ranges - num[MTRR_NUM_TYPES])
return 0;
memset(range, 0, sizeof(range));
nr_range = 0;
if (mtrr_tom2) {
range[nr_range].start = (1ULL<<(32 - PAGE_SHIFT));
range[nr_range].end = mtrr_tom2 >> PAGE_SHIFT;
if (highest_pfn < range[nr_range].end)
highest_pfn = range[nr_range].end;
nr_range++;
}
nr_range = x86_get_mtrr_mem_range(range, nr_range, 0, 0);
total_trim_size = 0;
if (range[0].start)
total_trim_size += real_trim_memory(0, range[0].start);
for (i = 0; i < nr_range - 1; i++) {
if (range[i].end < range[i+1].start)
total_trim_size += real_trim_memory(range[i].end,
range[i+1].start);
}
i = nr_range - 1;
if (range[i].end < end_pfn)
total_trim_size += real_trim_memory(range[i].end,
end_pfn);
if (total_trim_size) {
pr_warning("WARNING: BIOS bug: CPU MTRRs don't cover all of memory, losing %lluMB of RAM.\n", total_trim_size >> 20);
if (!changed_by_mtrr_cleanup)
WARN_ON(1);
pr_info("update e820 for mtrr\n");
update_e820();
return 1;
}
return 0;
}
