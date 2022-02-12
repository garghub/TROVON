static void gpmc_write_reg(int idx, u32 val)
{
writel_relaxed(val, gpmc_base + idx);
}
static u32 gpmc_read_reg(int idx)
{
return readl_relaxed(gpmc_base + idx);
}
void gpmc_cs_write_reg(int cs, int idx, u32 val)
{
void __iomem *reg_addr;
reg_addr = gpmc_base + GPMC_CS0_OFFSET + (cs * GPMC_CS_SIZE) + idx;
writel_relaxed(val, reg_addr);
}
static u32 gpmc_cs_read_reg(int cs, int idx)
{
void __iomem *reg_addr;
reg_addr = gpmc_base + GPMC_CS0_OFFSET + (cs * GPMC_CS_SIZE) + idx;
return readl_relaxed(reg_addr);
}
static unsigned long gpmc_get_fclk_period(void)
{
unsigned long rate = clk_get_rate(gpmc_l3_clk);
rate /= 1000;
rate = 1000000000 / rate;
return rate;
}
static unsigned long gpmc_get_clk_period(int cs, enum gpmc_clk_domain cd)
{
unsigned long tick_ps = gpmc_get_fclk_period();
u32 l;
int div;
switch (cd) {
case GPMC_CD_CLK:
l = gpmc_cs_read_reg(cs, GPMC_CS_CONFIG1);
div = (l & 0x03) + 1;
tick_ps *= div;
break;
case GPMC_CD_FCLK:
default:
break;
}
return tick_ps;
}
static unsigned int gpmc_ns_to_clk_ticks(unsigned int time_ns, int cs,
enum gpmc_clk_domain cd)
{
unsigned long tick_ps;
tick_ps = gpmc_get_clk_period(cs, cd);
return (time_ns * 1000 + tick_ps - 1) / tick_ps;
}
static unsigned int gpmc_ns_to_ticks(unsigned int time_ns)
{
return gpmc_ns_to_clk_ticks(time_ns, 0, GPMC_CD_FCLK);
}
static unsigned int gpmc_ps_to_ticks(unsigned int time_ps)
{
unsigned long tick_ps;
tick_ps = gpmc_get_fclk_period();
return (time_ps + tick_ps - 1) / tick_ps;
}
unsigned int gpmc_clk_ticks_to_ns(unsigned ticks, int cs,
enum gpmc_clk_domain cd)
{
return ticks * gpmc_get_clk_period(cs, cd) / 1000;
}
unsigned int gpmc_ticks_to_ns(unsigned int ticks)
{
return gpmc_clk_ticks_to_ns(ticks, 0, GPMC_CD_FCLK);
}
static unsigned int gpmc_ticks_to_ps(unsigned int ticks)
{
return ticks * gpmc_get_fclk_period();
}
static unsigned int gpmc_round_ps_to_ticks(unsigned int time_ps)
{
unsigned long ticks = gpmc_ps_to_ticks(time_ps);
return ticks * gpmc_get_fclk_period();
}
static inline void gpmc_cs_modify_reg(int cs, int reg, u32 mask, bool value)
{
u32 l;
l = gpmc_cs_read_reg(cs, reg);
if (value)
l |= mask;
else
l &= ~mask;
gpmc_cs_write_reg(cs, reg, l);
}
static void gpmc_cs_bool_timings(int cs, const struct gpmc_bool_timings *p)
{
gpmc_cs_modify_reg(cs, GPMC_CS_CONFIG1,
GPMC_CONFIG1_TIME_PARA_GRAN,
p->time_para_granularity);
gpmc_cs_modify_reg(cs, GPMC_CS_CONFIG2,
GPMC_CONFIG2_CSEXTRADELAY, p->cs_extra_delay);
gpmc_cs_modify_reg(cs, GPMC_CS_CONFIG3,
GPMC_CONFIG3_ADVEXTRADELAY, p->adv_extra_delay);
gpmc_cs_modify_reg(cs, GPMC_CS_CONFIG4,
GPMC_CONFIG4_OEEXTRADELAY, p->oe_extra_delay);
gpmc_cs_modify_reg(cs, GPMC_CS_CONFIG4,
GPMC_CONFIG4_WEEXTRADELAY, p->we_extra_delay);
gpmc_cs_modify_reg(cs, GPMC_CS_CONFIG6,
GPMC_CONFIG6_CYCLE2CYCLESAMECSEN,
p->cycle2cyclesamecsen);
gpmc_cs_modify_reg(cs, GPMC_CS_CONFIG6,
GPMC_CONFIG6_CYCLE2CYCLEDIFFCSEN,
p->cycle2cyclediffcsen);
}
static int get_gpmc_timing_reg(
int cs, int reg, int st_bit, int end_bit, int max,
const char *name, const enum gpmc_clk_domain cd,
int shift,
bool raw, bool noval)
{
u32 l;
int nr_bits;
int mask;
bool invalid;
l = gpmc_cs_read_reg(cs, reg);
nr_bits = end_bit - st_bit + 1;
mask = (1 << nr_bits) - 1;
l = (l >> st_bit) & mask;
if (!max)
max = mask;
invalid = l > max;
if (shift)
l = (shift << l);
if (noval && (l == 0))
return 0;
if (!raw) {
unsigned int time_ns;
unsigned int time_ns_min = 0;
if (l)
time_ns_min = gpmc_clk_ticks_to_ns(l - 1, cs, cd) + 1;
time_ns = gpmc_clk_ticks_to_ns(l, cs, cd);
pr_info("gpmc,%s = <%u> /* %u ns - %u ns; %i ticks%s*/\n",
name, time_ns, time_ns_min, time_ns, l,
invalid ? "; invalid " : " ");
} else {
pr_info("gpmc,%s = <%u>%s\n", name, l,
invalid ? " /* invalid */" : "");
}
return l;
}
static void gpmc_show_regs(int cs, const char *desc)
{
pr_info("gpmc cs%i %s:\n", cs, desc);
GPMC_PRINT_CONFIG(cs, GPMC_CS_CONFIG1);
GPMC_PRINT_CONFIG(cs, GPMC_CS_CONFIG2);
GPMC_PRINT_CONFIG(cs, GPMC_CS_CONFIG3);
GPMC_PRINT_CONFIG(cs, GPMC_CS_CONFIG4);
GPMC_PRINT_CONFIG(cs, GPMC_CS_CONFIG5);
GPMC_PRINT_CONFIG(cs, GPMC_CS_CONFIG6);
}
static void gpmc_cs_show_timings(int cs, const char *desc)
{
gpmc_show_regs(cs, desc);
pr_info("gpmc cs%i access configuration:\n", cs);
GPMC_GET_RAW_BOOL(GPMC_CS_CONFIG1, 4, 4, "time-para-granularity");
GPMC_GET_RAW(GPMC_CS_CONFIG1, 8, 9, "mux-add-data");
GPMC_GET_RAW_MAX(GPMC_CS_CONFIG1, 12, 13,
GPMC_CONFIG1_DEVICESIZE_MAX, "device-width");
GPMC_GET_RAW(GPMC_CS_CONFIG1, 16, 17, "wait-pin");
GPMC_GET_RAW_BOOL(GPMC_CS_CONFIG1, 21, 21, "wait-on-write");
GPMC_GET_RAW_BOOL(GPMC_CS_CONFIG1, 22, 22, "wait-on-read");
GPMC_GET_RAW_SHIFT_MAX(GPMC_CS_CONFIG1, 23, 24, 4,
GPMC_CONFIG1_ATTACHEDDEVICEPAGELENGTH_MAX,
"burst-length");
GPMC_GET_RAW_BOOL(GPMC_CS_CONFIG1, 27, 27, "sync-write");
GPMC_GET_RAW_BOOL(GPMC_CS_CONFIG1, 28, 28, "burst-write");
GPMC_GET_RAW_BOOL(GPMC_CS_CONFIG1, 29, 29, "gpmc,sync-read");
GPMC_GET_RAW_BOOL(GPMC_CS_CONFIG1, 30, 30, "burst-read");
GPMC_GET_RAW_BOOL(GPMC_CS_CONFIG1, 31, 31, "burst-wrap");
GPMC_GET_RAW_BOOL(GPMC_CS_CONFIG2, 7, 7, "cs-extra-delay");
GPMC_GET_RAW_BOOL(GPMC_CS_CONFIG3, 7, 7, "adv-extra-delay");
GPMC_GET_RAW_BOOL(GPMC_CS_CONFIG4, 23, 23, "we-extra-delay");
GPMC_GET_RAW_BOOL(GPMC_CS_CONFIG4, 7, 7, "oe-extra-delay");
GPMC_GET_RAW_BOOL(GPMC_CS_CONFIG6, 7, 7, "cycle2cycle-samecsen");
GPMC_GET_RAW_BOOL(GPMC_CS_CONFIG6, 6, 6, "cycle2cycle-diffcsen");
pr_info("gpmc cs%i timings configuration:\n", cs);
GPMC_GET_TICKS(GPMC_CS_CONFIG2, 0, 3, "cs-on-ns");
GPMC_GET_TICKS(GPMC_CS_CONFIG2, 8, 12, "cs-rd-off-ns");
GPMC_GET_TICKS(GPMC_CS_CONFIG2, 16, 20, "cs-wr-off-ns");
GPMC_GET_TICKS(GPMC_CS_CONFIG3, 0, 3, "adv-on-ns");
GPMC_GET_TICKS(GPMC_CS_CONFIG3, 8, 12, "adv-rd-off-ns");
GPMC_GET_TICKS(GPMC_CS_CONFIG3, 16, 20, "adv-wr-off-ns");
if (gpmc_capability & GPMC_HAS_MUX_AAD) {
GPMC_GET_TICKS(GPMC_CS_CONFIG3, 4, 6, "adv-aad-mux-on-ns");
GPMC_GET_TICKS(GPMC_CS_CONFIG3, 24, 26,
"adv-aad-mux-rd-off-ns");
GPMC_GET_TICKS(GPMC_CS_CONFIG3, 28, 30,
"adv-aad-mux-wr-off-ns");
}
GPMC_GET_TICKS(GPMC_CS_CONFIG4, 0, 3, "oe-on-ns");
GPMC_GET_TICKS(GPMC_CS_CONFIG4, 8, 12, "oe-off-ns");
if (gpmc_capability & GPMC_HAS_MUX_AAD) {
GPMC_GET_TICKS(GPMC_CS_CONFIG4, 4, 6, "oe-aad-mux-on-ns");
GPMC_GET_TICKS(GPMC_CS_CONFIG4, 13, 15, "oe-aad-mux-off-ns");
}
GPMC_GET_TICKS(GPMC_CS_CONFIG4, 16, 19, "we-on-ns");
GPMC_GET_TICKS(GPMC_CS_CONFIG4, 24, 28, "we-off-ns");
GPMC_GET_TICKS(GPMC_CS_CONFIG5, 0, 4, "rd-cycle-ns");
GPMC_GET_TICKS(GPMC_CS_CONFIG5, 8, 12, "wr-cycle-ns");
GPMC_GET_TICKS(GPMC_CS_CONFIG5, 16, 20, "access-ns");
GPMC_GET_TICKS(GPMC_CS_CONFIG5, 24, 27, "page-burst-access-ns");
GPMC_GET_TICKS(GPMC_CS_CONFIG6, 0, 3, "bus-turnaround-ns");
GPMC_GET_TICKS(GPMC_CS_CONFIG6, 8, 11, "cycle2cycle-delay-ns");
GPMC_GET_TICKS_CD_MAX(GPMC_CS_CONFIG1, 18, 19,
GPMC_CONFIG1_WAITMONITORINGTIME_MAX,
"wait-monitoring-ns", GPMC_CD_CLK);
GPMC_GET_TICKS_CD_MAX(GPMC_CS_CONFIG1, 25, 26,
GPMC_CONFIG1_CLKACTIVATIONTIME_MAX,
"clk-activation-ns", GPMC_CD_FCLK);
GPMC_GET_TICKS(GPMC_CS_CONFIG6, 16, 19, "wr-data-mux-bus-ns");
GPMC_GET_TICKS(GPMC_CS_CONFIG6, 24, 28, "wr-access-ns");
}
static inline void gpmc_cs_show_timings(int cs, const char *desc)
{
}
static int set_gpmc_timing_reg(int cs, int reg, int st_bit, int end_bit, int max,
int time, enum gpmc_clk_domain cd, const char *name)
{
u32 l;
int ticks, mask, nr_bits;
if (time == 0)
ticks = 0;
else
ticks = gpmc_ns_to_clk_ticks(time, cs, cd);
nr_bits = end_bit - st_bit + 1;
mask = (1 << nr_bits) - 1;
if (!max)
max = mask;
if (ticks > max) {
pr_err("%s: GPMC CS%d: %s %d ns, %d ticks > %d ticks\n",
__func__, cs, name, time, ticks, max);
return -1;
}
l = gpmc_cs_read_reg(cs, reg);
#ifdef CONFIG_OMAP_GPMC_DEBUG
pr_info(
"GPMC CS%d: %-17s: %3d ticks, %3lu ns (was %3i ticks) %3d ns\n",
cs, name, ticks, gpmc_get_clk_period(cs, cd) * ticks / 1000,
(l >> st_bit) & mask, time);
#endif
l &= ~(mask << st_bit);
l |= ticks << st_bit;
gpmc_cs_write_reg(cs, reg, l);
return 0;
}
static int gpmc_calc_waitmonitoring_divider(unsigned int wait_monitoring)
{
int div = gpmc_ns_to_ticks(wait_monitoring);
div += GPMC_CONFIG1_WAITMONITORINGTIME_MAX - 1;
div /= GPMC_CONFIG1_WAITMONITORINGTIME_MAX;
if (div > 4)
return -1;
if (div <= 0)
div = 1;
return div;
}
int gpmc_calc_divider(unsigned int sync_clk)
{
int div = gpmc_ps_to_ticks(sync_clk);
if (div > 4)
return -1;
if (div <= 0)
div = 1;
return div;
}
int gpmc_cs_set_timings(int cs, const struct gpmc_timings *t,
const struct gpmc_settings *s)
{
int div;
u32 l;
div = gpmc_calc_divider(t->sync_clk);
if (div < 0)
return div;
if (!s->sync_read && !s->sync_write &&
(s->wait_on_read || s->wait_on_write)
) {
div = gpmc_calc_waitmonitoring_divider(t->wait_monitoring);
if (div < 0) {
pr_err("%s: waitmonitoringtime %3d ns too large for greatest gpmcfclkdivider.\n",
__func__,
t->wait_monitoring
);
return -1;
}
}
GPMC_SET_ONE(GPMC_CS_CONFIG2, 0, 3, cs_on);
GPMC_SET_ONE(GPMC_CS_CONFIG2, 8, 12, cs_rd_off);
GPMC_SET_ONE(GPMC_CS_CONFIG2, 16, 20, cs_wr_off);
GPMC_SET_ONE(GPMC_CS_CONFIG3, 0, 3, adv_on);
GPMC_SET_ONE(GPMC_CS_CONFIG3, 8, 12, adv_rd_off);
GPMC_SET_ONE(GPMC_CS_CONFIG3, 16, 20, adv_wr_off);
if (gpmc_capability & GPMC_HAS_MUX_AAD) {
GPMC_SET_ONE(GPMC_CS_CONFIG3, 4, 6, adv_aad_mux_on);
GPMC_SET_ONE(GPMC_CS_CONFIG3, 24, 26, adv_aad_mux_rd_off);
GPMC_SET_ONE(GPMC_CS_CONFIG3, 28, 30, adv_aad_mux_wr_off);
}
GPMC_SET_ONE(GPMC_CS_CONFIG4, 0, 3, oe_on);
GPMC_SET_ONE(GPMC_CS_CONFIG4, 8, 12, oe_off);
if (gpmc_capability & GPMC_HAS_MUX_AAD) {
GPMC_SET_ONE(GPMC_CS_CONFIG4, 4, 6, oe_aad_mux_on);
GPMC_SET_ONE(GPMC_CS_CONFIG4, 13, 15, oe_aad_mux_off);
}
GPMC_SET_ONE(GPMC_CS_CONFIG4, 16, 19, we_on);
GPMC_SET_ONE(GPMC_CS_CONFIG4, 24, 28, we_off);
GPMC_SET_ONE(GPMC_CS_CONFIG5, 0, 4, rd_cycle);
GPMC_SET_ONE(GPMC_CS_CONFIG5, 8, 12, wr_cycle);
GPMC_SET_ONE(GPMC_CS_CONFIG5, 16, 20, access);
GPMC_SET_ONE(GPMC_CS_CONFIG5, 24, 27, page_burst_access);
GPMC_SET_ONE(GPMC_CS_CONFIG6, 0, 3, bus_turnaround);
GPMC_SET_ONE(GPMC_CS_CONFIG6, 8, 11, cycle2cycle_delay);
if (gpmc_capability & GPMC_HAS_WR_DATA_MUX_BUS)
GPMC_SET_ONE(GPMC_CS_CONFIG6, 16, 19, wr_data_mux_bus);
if (gpmc_capability & GPMC_HAS_WR_ACCESS)
GPMC_SET_ONE(GPMC_CS_CONFIG6, 24, 28, wr_access);
l = gpmc_cs_read_reg(cs, GPMC_CS_CONFIG1);
l &= ~0x03;
l |= (div - 1);
gpmc_cs_write_reg(cs, GPMC_CS_CONFIG1, l);
GPMC_SET_ONE_CD_MAX(GPMC_CS_CONFIG1, 18, 19,
GPMC_CONFIG1_WAITMONITORINGTIME_MAX,
wait_monitoring, GPMC_CD_CLK);
GPMC_SET_ONE_CD_MAX(GPMC_CS_CONFIG1, 25, 26,
GPMC_CONFIG1_CLKACTIVATIONTIME_MAX,
clk_activation, GPMC_CD_FCLK);
#ifdef CONFIG_OMAP_GPMC_DEBUG
pr_info("GPMC CS%d CLK period is %lu ns (div %d)\n",
cs, (div * gpmc_get_fclk_period()) / 1000, div);
#endif
gpmc_cs_bool_timings(cs, &t->bool_timings);
gpmc_cs_show_timings(cs, "after gpmc_cs_set_timings");
return 0;
}
static int gpmc_cs_set_memconf(int cs, u32 base, u32 size)
{
u32 l;
u32 mask;
if (base & (size - 1))
return -EINVAL;
base >>= GPMC_CHUNK_SHIFT;
mask = (1 << GPMC_SECTION_SHIFT) - size;
mask >>= GPMC_CHUNK_SHIFT;
mask <<= GPMC_CONFIG7_MASKADDRESS_OFFSET;
l = gpmc_cs_read_reg(cs, GPMC_CS_CONFIG7);
l &= ~GPMC_CONFIG7_MASK;
l |= base & GPMC_CONFIG7_BASEADDRESS_MASK;
l |= mask & GPMC_CONFIG7_MASKADDRESS_MASK;
l |= GPMC_CONFIG7_CSVALID;
gpmc_cs_write_reg(cs, GPMC_CS_CONFIG7, l);
return 0;
}
static void gpmc_cs_enable_mem(int cs)
{
u32 l;
l = gpmc_cs_read_reg(cs, GPMC_CS_CONFIG7);
l |= GPMC_CONFIG7_CSVALID;
gpmc_cs_write_reg(cs, GPMC_CS_CONFIG7, l);
}
static void gpmc_cs_disable_mem(int cs)
{
u32 l;
l = gpmc_cs_read_reg(cs, GPMC_CS_CONFIG7);
l &= ~GPMC_CONFIG7_CSVALID;
gpmc_cs_write_reg(cs, GPMC_CS_CONFIG7, l);
}
static void gpmc_cs_get_memconf(int cs, u32 *base, u32 *size)
{
u32 l;
u32 mask;
l = gpmc_cs_read_reg(cs, GPMC_CS_CONFIG7);
*base = (l & 0x3f) << GPMC_CHUNK_SHIFT;
mask = (l >> 8) & 0x0f;
*size = (1 << GPMC_SECTION_SHIFT) - (mask << GPMC_CHUNK_SHIFT);
}
static int gpmc_cs_mem_enabled(int cs)
{
u32 l;
l = gpmc_cs_read_reg(cs, GPMC_CS_CONFIG7);
return l & GPMC_CONFIG7_CSVALID;
}
static void gpmc_cs_set_reserved(int cs, int reserved)
{
struct gpmc_cs_data *gpmc = &gpmc_cs[cs];
gpmc->flags |= GPMC_CS_RESERVED;
}
static bool gpmc_cs_reserved(int cs)
{
struct gpmc_cs_data *gpmc = &gpmc_cs[cs];
return gpmc->flags & GPMC_CS_RESERVED;
}
static void gpmc_cs_set_name(int cs, const char *name)
{
struct gpmc_cs_data *gpmc = &gpmc_cs[cs];
gpmc->name = name;
}
static const char *gpmc_cs_get_name(int cs)
{
struct gpmc_cs_data *gpmc = &gpmc_cs[cs];
return gpmc->name;
}
static unsigned long gpmc_mem_align(unsigned long size)
{
int order;
size = (size - 1) >> (GPMC_CHUNK_SHIFT - 1);
order = GPMC_CHUNK_SHIFT - 1;
do {
size >>= 1;
order++;
} while (size);
size = 1 << order;
return size;
}
static int gpmc_cs_insert_mem(int cs, unsigned long base, unsigned long size)
{
struct gpmc_cs_data *gpmc = &gpmc_cs[cs];
struct resource *res = &gpmc->mem;
int r;
size = gpmc_mem_align(size);
spin_lock(&gpmc_mem_lock);
res->start = base;
res->end = base + size - 1;
r = request_resource(&gpmc_mem_root, res);
spin_unlock(&gpmc_mem_lock);
return r;
}
static int gpmc_cs_delete_mem(int cs)
{
struct gpmc_cs_data *gpmc = &gpmc_cs[cs];
struct resource *res = &gpmc->mem;
int r;
spin_lock(&gpmc_mem_lock);
r = release_resource(res);
res->start = 0;
res->end = 0;
spin_unlock(&gpmc_mem_lock);
return r;
}
static int gpmc_cs_remap(int cs, u32 base)
{
int ret;
u32 old_base, size;
if (cs > gpmc_cs_num) {
pr_err("%s: requested chip-select is disabled\n", __func__);
return -ENODEV;
}
base &= ~(SZ_16M - 1);
gpmc_cs_get_memconf(cs, &old_base, &size);
if (base == old_base)
return 0;
ret = gpmc_cs_delete_mem(cs);
if (ret < 0)
return ret;
ret = gpmc_cs_insert_mem(cs, base, size);
if (ret < 0)
return ret;
ret = gpmc_cs_set_memconf(cs, base, size);
return ret;
}
int gpmc_cs_request(int cs, unsigned long size, unsigned long *base)
{
struct gpmc_cs_data *gpmc = &gpmc_cs[cs];
struct resource *res = &gpmc->mem;
int r = -1;
if (cs > gpmc_cs_num) {
pr_err("%s: requested chip-select is disabled\n", __func__);
return -ENODEV;
}
size = gpmc_mem_align(size);
if (size > (1 << GPMC_SECTION_SHIFT))
return -ENOMEM;
spin_lock(&gpmc_mem_lock);
if (gpmc_cs_reserved(cs)) {
r = -EBUSY;
goto out;
}
if (gpmc_cs_mem_enabled(cs))
r = adjust_resource(res, res->start & ~(size - 1), size);
if (r < 0)
r = allocate_resource(&gpmc_mem_root, res, size, 0, ~0,
size, NULL, NULL);
if (r < 0)
goto out;
gpmc_cs_disable_mem(cs);
r = gpmc_cs_set_memconf(cs, res->start, resource_size(res));
if (r < 0) {
release_resource(res);
goto out;
}
gpmc_cs_enable_mem(cs);
*base = res->start;
gpmc_cs_set_reserved(cs, 1);
out:
spin_unlock(&gpmc_mem_lock);
return r;
}
void gpmc_cs_free(int cs)
{
struct gpmc_cs_data *gpmc = &gpmc_cs[cs];
struct resource *res = &gpmc->mem;
spin_lock(&gpmc_mem_lock);
if (cs >= gpmc_cs_num || cs < 0 || !gpmc_cs_reserved(cs)) {
printk(KERN_ERR "Trying to free non-reserved GPMC CS%d\n", cs);
BUG();
spin_unlock(&gpmc_mem_lock);
return;
}
gpmc_cs_disable_mem(cs);
if (res->flags)
release_resource(res);
gpmc_cs_set_reserved(cs, 0);
spin_unlock(&gpmc_mem_lock);
}
int gpmc_configure(int cmd, int wval)
{
u32 regval;
switch (cmd) {
case GPMC_CONFIG_WP:
regval = gpmc_read_reg(GPMC_CONFIG);
if (wval)
regval &= ~GPMC_CONFIG_WRITEPROTECT;
else
regval |= GPMC_CONFIG_WRITEPROTECT;
gpmc_write_reg(GPMC_CONFIG, regval);
break;
default:
pr_err("%s: command not supported\n", __func__);
return -EINVAL;
}
return 0;
}
void gpmc_update_nand_reg(struct gpmc_nand_regs *reg, int cs)
{
int i;
reg->gpmc_status = NULL;
reg->gpmc_nand_command = gpmc_base + GPMC_CS0_OFFSET +
GPMC_CS_NAND_COMMAND + GPMC_CS_SIZE * cs;
reg->gpmc_nand_address = gpmc_base + GPMC_CS0_OFFSET +
GPMC_CS_NAND_ADDRESS + GPMC_CS_SIZE * cs;
reg->gpmc_nand_data = gpmc_base + GPMC_CS0_OFFSET +
GPMC_CS_NAND_DATA + GPMC_CS_SIZE * cs;
reg->gpmc_prefetch_config1 = gpmc_base + GPMC_PREFETCH_CONFIG1;
reg->gpmc_prefetch_config2 = gpmc_base + GPMC_PREFETCH_CONFIG2;
reg->gpmc_prefetch_control = gpmc_base + GPMC_PREFETCH_CONTROL;
reg->gpmc_prefetch_status = gpmc_base + GPMC_PREFETCH_STATUS;
reg->gpmc_ecc_config = gpmc_base + GPMC_ECC_CONFIG;
reg->gpmc_ecc_control = gpmc_base + GPMC_ECC_CONTROL;
reg->gpmc_ecc_size_config = gpmc_base + GPMC_ECC_SIZE_CONFIG;
reg->gpmc_ecc1_result = gpmc_base + GPMC_ECC1_RESULT;
for (i = 0; i < GPMC_BCH_NUM_REMAINDER; i++) {
reg->gpmc_bch_result0[i] = gpmc_base + GPMC_ECC_BCH_RESULT_0 +
GPMC_BCH_SIZE * i;
reg->gpmc_bch_result1[i] = gpmc_base + GPMC_ECC_BCH_RESULT_1 +
GPMC_BCH_SIZE * i;
reg->gpmc_bch_result2[i] = gpmc_base + GPMC_ECC_BCH_RESULT_2 +
GPMC_BCH_SIZE * i;
reg->gpmc_bch_result3[i] = gpmc_base + GPMC_ECC_BCH_RESULT_3 +
GPMC_BCH_SIZE * i;
reg->gpmc_bch_result4[i] = gpmc_base + GPMC_ECC_BCH_RESULT_4 +
i * GPMC_BCH_SIZE;
reg->gpmc_bch_result5[i] = gpmc_base + GPMC_ECC_BCH_RESULT_5 +
i * GPMC_BCH_SIZE;
reg->gpmc_bch_result6[i] = gpmc_base + GPMC_ECC_BCH_RESULT_6 +
i * GPMC_BCH_SIZE;
}
}
static bool gpmc_nand_writebuffer_empty(void)
{
if (gpmc_read_reg(GPMC_STATUS) & GPMC_STATUS_EMPTYWRITEBUFFERSTATUS)
return true;
return false;
}
struct gpmc_nand_ops *gpmc_omap_get_nand_ops(struct gpmc_nand_regs *reg, int cs)
{
if (cs >= gpmc_cs_num)
return NULL;
gpmc_update_nand_reg(reg, cs);
return &nand_ops;
}
int gpmc_get_client_irq(unsigned irq_config)
{
if (!gpmc_irq_domain) {
pr_warn("%s called before GPMC IRQ domain available\n",
__func__);
return 0;
}
if (irq_config >= GPMC_NR_NAND_IRQS)
return 0;
return irq_create_mapping(gpmc_irq_domain, irq_config);
}
static int gpmc_irq_endis(unsigned long hwirq, bool endis)
{
u32 regval;
if (hwirq >= GPMC_NR_NAND_IRQS)
hwirq += 8 - GPMC_NR_NAND_IRQS;
regval = gpmc_read_reg(GPMC_IRQENABLE);
if (endis)
regval |= BIT(hwirq);
else
regval &= ~BIT(hwirq);
gpmc_write_reg(GPMC_IRQENABLE, regval);
return 0;
}
static void gpmc_irq_disable(struct irq_data *p)
{
gpmc_irq_endis(p->hwirq, false);
}
static void gpmc_irq_enable(struct irq_data *p)
{
gpmc_irq_endis(p->hwirq, true);
}
static void gpmc_irq_mask(struct irq_data *d)
{
gpmc_irq_endis(d->hwirq, false);
}
static void gpmc_irq_unmask(struct irq_data *d)
{
gpmc_irq_endis(d->hwirq, true);
}
static void gpmc_irq_edge_config(unsigned long hwirq, bool rising_edge)
{
u32 regval;
if (hwirq < GPMC_NR_NAND_IRQS)
return;
hwirq += 8 - GPMC_NR_NAND_IRQS;
regval = gpmc_read_reg(GPMC_CONFIG);
if (rising_edge)
regval &= ~BIT(hwirq);
else
regval |= BIT(hwirq);
gpmc_write_reg(GPMC_CONFIG, regval);
}
static void gpmc_irq_ack(struct irq_data *d)
{
unsigned int hwirq = d->hwirq;
if (hwirq >= GPMC_NR_NAND_IRQS)
hwirq += 8 - GPMC_NR_NAND_IRQS;
gpmc_write_reg(GPMC_IRQSTATUS, BIT(hwirq));
}
static int gpmc_irq_set_type(struct irq_data *d, unsigned int trigger)
{
if (d->hwirq < GPMC_NR_NAND_IRQS)
return -EINVAL;
if (trigger == IRQ_TYPE_EDGE_FALLING)
gpmc_irq_edge_config(d->hwirq, false);
else if (trigger == IRQ_TYPE_EDGE_RISING)
gpmc_irq_edge_config(d->hwirq, true);
else
return -EINVAL;
return 0;
}
static int gpmc_irq_map(struct irq_domain *d, unsigned int virq,
irq_hw_number_t hw)
{
struct gpmc_device *gpmc = d->host_data;
irq_set_chip_data(virq, gpmc);
if (hw < GPMC_NR_NAND_IRQS) {
irq_modify_status(virq, IRQ_NOREQUEST, IRQ_NOAUTOEN);
irq_set_chip_and_handler(virq, &gpmc->irq_chip,
handle_simple_irq);
} else {
irq_set_chip_and_handler(virq, &gpmc->irq_chip,
handle_edge_irq);
}
return 0;
}
static irqreturn_t gpmc_handle_irq(int irq, void *data)
{
int hwirq, virq;
u32 regval, regvalx;
struct gpmc_device *gpmc = data;
regval = gpmc_read_reg(GPMC_IRQSTATUS);
regvalx = regval;
if (!regval)
return IRQ_NONE;
for (hwirq = 0; hwirq < gpmc->nirqs; hwirq++) {
if (hwirq == GPMC_NR_NAND_IRQS)
regvalx >>= 8 - GPMC_NR_NAND_IRQS;
if (regvalx & BIT(hwirq)) {
virq = irq_find_mapping(gpmc_irq_domain, hwirq);
if (!virq) {
dev_warn(gpmc->dev,
"spurious irq detected hwirq %d, virq %d\n",
hwirq, virq);
}
generic_handle_irq(virq);
}
}
gpmc_write_reg(GPMC_IRQSTATUS, regval);
return IRQ_HANDLED;
}
static int gpmc_setup_irq(struct gpmc_device *gpmc)
{
u32 regval;
int rc;
gpmc_write_reg(GPMC_IRQENABLE, 0);
regval = gpmc_read_reg(GPMC_IRQSTATUS);
gpmc_write_reg(GPMC_IRQSTATUS, regval);
gpmc->irq_chip.name = "gpmc";
gpmc->irq_chip.irq_enable = gpmc_irq_enable;
gpmc->irq_chip.irq_disable = gpmc_irq_disable;
gpmc->irq_chip.irq_ack = gpmc_irq_ack;
gpmc->irq_chip.irq_mask = gpmc_irq_mask;
gpmc->irq_chip.irq_unmask = gpmc_irq_unmask;
gpmc->irq_chip.irq_set_type = gpmc_irq_set_type;
gpmc_irq_domain = irq_domain_add_linear(gpmc->dev->of_node,
gpmc->nirqs,
&gpmc_irq_domain_ops,
gpmc);
if (!gpmc_irq_domain) {
dev_err(gpmc->dev, "IRQ domain add failed\n");
return -ENODEV;
}
rc = request_irq(gpmc->irq, gpmc_handle_irq, 0, "gpmc", gpmc);
if (rc) {
dev_err(gpmc->dev, "failed to request irq %d: %d\n",
gpmc->irq, rc);
irq_domain_remove(gpmc_irq_domain);
gpmc_irq_domain = NULL;
}
return rc;
}
static int gpmc_free_irq(struct gpmc_device *gpmc)
{
int hwirq;
free_irq(gpmc->irq, gpmc);
for (hwirq = 0; hwirq < gpmc->nirqs; hwirq++)
irq_dispose_mapping(irq_find_mapping(gpmc_irq_domain, hwirq));
irq_domain_remove(gpmc_irq_domain);
gpmc_irq_domain = NULL;
return 0;
}
static void gpmc_mem_exit(void)
{
int cs;
for (cs = 0; cs < gpmc_cs_num; cs++) {
if (!gpmc_cs_mem_enabled(cs))
continue;
gpmc_cs_delete_mem(cs);
}
}
static void gpmc_mem_init(void)
{
int cs;
gpmc_mem_root.start = GPMC_MEM_START;
gpmc_mem_root.end = GPMC_MEM_END;
for (cs = 0; cs < gpmc_cs_num; cs++) {
u32 base, size;
if (!gpmc_cs_mem_enabled(cs))
continue;
gpmc_cs_get_memconf(cs, &base, &size);
if (gpmc_cs_insert_mem(cs, base, size)) {
pr_warn("%s: disabling cs %d mapped at 0x%x-0x%x\n",
__func__, cs, base, base + size);
gpmc_cs_disable_mem(cs);
}
}
}
static u32 gpmc_round_ps_to_sync_clk(u32 time_ps, u32 sync_clk)
{
u32 temp;
int div;
div = gpmc_calc_divider(sync_clk);
temp = gpmc_ps_to_ticks(time_ps);
temp = (temp + div - 1) / div;
return gpmc_ticks_to_ps(temp * div);
}
static int gpmc_calc_sync_read_timings(struct gpmc_timings *gpmc_t,
struct gpmc_device_timings *dev_t,
bool mux)
{
u32 temp;
temp = dev_t->t_avdp_r;
if (mux) {
temp = max_t(u32, temp, gpmc_t->clk_activation + dev_t->t_avdh);
temp = max_t(u32, gpmc_t->adv_on + gpmc_ticks_to_ps(1), temp);
}
gpmc_t->adv_rd_off = gpmc_round_ps_to_ticks(temp);
temp = dev_t->t_oeasu;
if (mux) {
temp = max_t(u32, temp, gpmc_t->clk_activation + dev_t->t_ach);
temp = max_t(u32, temp, gpmc_t->adv_rd_off +
gpmc_ticks_to_ps(dev_t->cyc_aavdh_oe));
}
gpmc_t->oe_on = gpmc_round_ps_to_ticks(temp);
temp = max_t(u32, dev_t->t_iaa, dev_t->cyc_iaa * gpmc_t->sync_clk);
temp += gpmc_t->clk_activation;
if (dev_t->cyc_oe)
temp = max_t(u32, temp, gpmc_t->oe_on +
gpmc_ticks_to_ps(dev_t->cyc_oe));
gpmc_t->access = gpmc_round_ps_to_ticks(temp);
gpmc_t->oe_off = gpmc_t->access + gpmc_ticks_to_ps(1);
gpmc_t->cs_rd_off = gpmc_t->oe_off;
temp = max_t(u32, dev_t->t_cez_r, dev_t->t_oez);
temp = gpmc_round_ps_to_sync_clk(temp, gpmc_t->sync_clk) +
gpmc_t->access;
if (dev_t->t_ce_rdyz)
temp = max_t(u32, temp, gpmc_t->cs_rd_off + dev_t->t_ce_rdyz);
gpmc_t->rd_cycle = gpmc_round_ps_to_ticks(temp);
return 0;
}
static int gpmc_calc_sync_write_timings(struct gpmc_timings *gpmc_t,
struct gpmc_device_timings *dev_t,
bool mux)
{
u32 temp;
temp = dev_t->t_avdp_w;
if (mux) {
temp = max_t(u32, temp,
gpmc_t->clk_activation + dev_t->t_avdh);
temp = max_t(u32, gpmc_t->adv_on + gpmc_ticks_to_ps(1), temp);
}
gpmc_t->adv_wr_off = gpmc_round_ps_to_ticks(temp);
temp = max_t(u32, dev_t->t_weasu,
gpmc_t->clk_activation + dev_t->t_rdyo);
if (mux) {
temp = max_t(u32, temp,
gpmc_t->adv_wr_off + dev_t->t_aavdh);
temp = max_t(u32, temp, gpmc_t->adv_wr_off +
gpmc_ticks_to_ps(dev_t->cyc_aavdh_we));
}
gpmc_t->wr_data_mux_bus = gpmc_round_ps_to_ticks(temp);
if (gpmc_capability & GPMC_HAS_WR_DATA_MUX_BUS)
gpmc_t->we_on = gpmc_round_ps_to_ticks(dev_t->t_weasu);
else
gpmc_t->we_on = gpmc_t->wr_data_mux_bus;
gpmc_t->wr_access = gpmc_t->access;
temp = gpmc_t->we_on + dev_t->t_wpl;
temp = max_t(u32, temp,
gpmc_t->wr_access + gpmc_ticks_to_ps(1));
temp = max_t(u32, temp,
gpmc_t->we_on + gpmc_ticks_to_ps(dev_t->cyc_wpl));
gpmc_t->we_off = gpmc_round_ps_to_ticks(temp);
gpmc_t->cs_wr_off = gpmc_round_ps_to_ticks(gpmc_t->we_off +
dev_t->t_wph);
temp = gpmc_round_ps_to_sync_clk(dev_t->t_cez_w, gpmc_t->sync_clk);
temp += gpmc_t->wr_access;
if (dev_t->t_ce_rdyz)
temp = max_t(u32, temp,
gpmc_t->cs_wr_off + dev_t->t_ce_rdyz);
gpmc_t->wr_cycle = gpmc_round_ps_to_ticks(temp);
return 0;
}
static int gpmc_calc_async_read_timings(struct gpmc_timings *gpmc_t,
struct gpmc_device_timings *dev_t,
bool mux)
{
u32 temp;
temp = dev_t->t_avdp_r;
if (mux)
temp = max_t(u32, gpmc_t->adv_on + gpmc_ticks_to_ps(1), temp);
gpmc_t->adv_rd_off = gpmc_round_ps_to_ticks(temp);
temp = dev_t->t_oeasu;
if (mux)
temp = max_t(u32, temp,
gpmc_t->adv_rd_off + dev_t->t_aavdh);
gpmc_t->oe_on = gpmc_round_ps_to_ticks(temp);
temp = max_t(u32, dev_t->t_iaa,
gpmc_t->oe_on + dev_t->t_oe);
temp = max_t(u32, temp,
gpmc_t->cs_on + dev_t->t_ce);
temp = max_t(u32, temp,
gpmc_t->adv_on + dev_t->t_aa);
gpmc_t->access = gpmc_round_ps_to_ticks(temp);
gpmc_t->oe_off = gpmc_t->access + gpmc_ticks_to_ps(1);
gpmc_t->cs_rd_off = gpmc_t->oe_off;
temp = max_t(u32, dev_t->t_rd_cycle,
gpmc_t->cs_rd_off + dev_t->t_cez_r);
temp = max_t(u32, temp, gpmc_t->oe_off + dev_t->t_oez);
gpmc_t->rd_cycle = gpmc_round_ps_to_ticks(temp);
return 0;
}
static int gpmc_calc_async_write_timings(struct gpmc_timings *gpmc_t,
struct gpmc_device_timings *dev_t,
bool mux)
{
u32 temp;
temp = dev_t->t_avdp_w;
if (mux)
temp = max_t(u32, gpmc_t->adv_on + gpmc_ticks_to_ps(1), temp);
gpmc_t->adv_wr_off = gpmc_round_ps_to_ticks(temp);
temp = dev_t->t_weasu;
if (mux) {
temp = max_t(u32, temp, gpmc_t->adv_wr_off + dev_t->t_aavdh);
temp = max_t(u32, temp, gpmc_t->adv_wr_off +
gpmc_ticks_to_ps(dev_t->cyc_aavdh_we));
}
gpmc_t->wr_data_mux_bus = gpmc_round_ps_to_ticks(temp);
if (gpmc_capability & GPMC_HAS_WR_DATA_MUX_BUS)
gpmc_t->we_on = gpmc_round_ps_to_ticks(dev_t->t_weasu);
else
gpmc_t->we_on = gpmc_t->wr_data_mux_bus;
temp = gpmc_t->we_on + dev_t->t_wpl;
gpmc_t->we_off = gpmc_round_ps_to_ticks(temp);
gpmc_t->cs_wr_off = gpmc_round_ps_to_ticks(gpmc_t->we_off +
dev_t->t_wph);
temp = max_t(u32, dev_t->t_wr_cycle,
gpmc_t->cs_wr_off + dev_t->t_cez_w);
gpmc_t->wr_cycle = gpmc_round_ps_to_ticks(temp);
return 0;
}
static int gpmc_calc_sync_common_timings(struct gpmc_timings *gpmc_t,
struct gpmc_device_timings *dev_t)
{
u32 temp;
gpmc_t->sync_clk = gpmc_calc_divider(dev_t->clk) *
gpmc_get_fclk_period();
gpmc_t->page_burst_access = gpmc_round_ps_to_sync_clk(
dev_t->t_bacc,
gpmc_t->sync_clk);
temp = max_t(u32, dev_t->t_ces, dev_t->t_avds);
gpmc_t->clk_activation = gpmc_round_ps_to_ticks(temp);
if (gpmc_calc_divider(gpmc_t->sync_clk) != 1)
return 0;
if (dev_t->ce_xdelay)
gpmc_t->bool_timings.cs_extra_delay = true;
if (dev_t->avd_xdelay)
gpmc_t->bool_timings.adv_extra_delay = true;
if (dev_t->oe_xdelay)
gpmc_t->bool_timings.oe_extra_delay = true;
if (dev_t->we_xdelay)
gpmc_t->bool_timings.we_extra_delay = true;
return 0;
}
static int gpmc_calc_common_timings(struct gpmc_timings *gpmc_t,
struct gpmc_device_timings *dev_t,
bool sync)
{
u32 temp;
gpmc_t->cs_on = gpmc_round_ps_to_ticks(dev_t->t_ceasu);
temp = dev_t->t_avdasu;
if (dev_t->t_ce_avd)
temp = max_t(u32, temp,
gpmc_t->cs_on + dev_t->t_ce_avd);
gpmc_t->adv_on = gpmc_round_ps_to_ticks(temp);
if (sync)
gpmc_calc_sync_common_timings(gpmc_t, dev_t);
return 0;
}
static void gpmc_convert_ps_to_ns(struct gpmc_timings *t)
{
t->cs_on /= 1000;
t->cs_rd_off /= 1000;
t->cs_wr_off /= 1000;
t->adv_on /= 1000;
t->adv_rd_off /= 1000;
t->adv_wr_off /= 1000;
t->we_on /= 1000;
t->we_off /= 1000;
t->oe_on /= 1000;
t->oe_off /= 1000;
t->page_burst_access /= 1000;
t->access /= 1000;
t->rd_cycle /= 1000;
t->wr_cycle /= 1000;
t->bus_turnaround /= 1000;
t->cycle2cycle_delay /= 1000;
t->wait_monitoring /= 1000;
t->clk_activation /= 1000;
t->wr_access /= 1000;
t->wr_data_mux_bus /= 1000;
}
int gpmc_calc_timings(struct gpmc_timings *gpmc_t,
struct gpmc_settings *gpmc_s,
struct gpmc_device_timings *dev_t)
{
bool mux = false, sync = false;
if (gpmc_s) {
mux = gpmc_s->mux_add_data ? true : false;
sync = (gpmc_s->sync_read || gpmc_s->sync_write);
}
memset(gpmc_t, 0, sizeof(*gpmc_t));
gpmc_calc_common_timings(gpmc_t, dev_t, sync);
if (gpmc_s && gpmc_s->sync_read)
gpmc_calc_sync_read_timings(gpmc_t, dev_t, mux);
else
gpmc_calc_async_read_timings(gpmc_t, dev_t, mux);
if (gpmc_s && gpmc_s->sync_write)
gpmc_calc_sync_write_timings(gpmc_t, dev_t, mux);
else
gpmc_calc_async_write_timings(gpmc_t, dev_t, mux);
gpmc_convert_ps_to_ns(gpmc_t);
return 0;
}
int gpmc_cs_program_settings(int cs, struct gpmc_settings *p)
{
u32 config1;
if ((!p->device_width) || (p->device_width > GPMC_DEVWIDTH_16BIT)) {
pr_err("%s: invalid width %d!", __func__, p->device_width);
return -EINVAL;
}
if (p->device_nand && p->mux_add_data) {
pr_err("%s: invalid configuration!\n", __func__);
return -EINVAL;
}
if ((p->mux_add_data > GPMC_MUX_AD) ||
((p->mux_add_data == GPMC_MUX_AAD) &&
!(gpmc_capability & GPMC_HAS_MUX_AAD))) {
pr_err("%s: invalid multiplex configuration!\n", __func__);
return -EINVAL;
}
if (p->burst_read || p->burst_write) {
switch (p->burst_len) {
case GPMC_BURST_4:
case GPMC_BURST_8:
case GPMC_BURST_16:
break;
default:
pr_err("%s: invalid page/burst-length (%d)\n",
__func__, p->burst_len);
return -EINVAL;
}
}
if (p->wait_pin > gpmc_nr_waitpins) {
pr_err("%s: invalid wait-pin (%d)\n", __func__, p->wait_pin);
return -EINVAL;
}
config1 = GPMC_CONFIG1_DEVICESIZE((p->device_width - 1));
if (p->sync_read)
config1 |= GPMC_CONFIG1_READTYPE_SYNC;
if (p->sync_write)
config1 |= GPMC_CONFIG1_WRITETYPE_SYNC;
if (p->wait_on_read)
config1 |= GPMC_CONFIG1_WAIT_READ_MON;
if (p->wait_on_write)
config1 |= GPMC_CONFIG1_WAIT_WRITE_MON;
if (p->wait_on_read || p->wait_on_write)
config1 |= GPMC_CONFIG1_WAIT_PIN_SEL(p->wait_pin);
if (p->device_nand)
config1 |= GPMC_CONFIG1_DEVICETYPE(GPMC_DEVICETYPE_NAND);
if (p->mux_add_data)
config1 |= GPMC_CONFIG1_MUXTYPE(p->mux_add_data);
if (p->burst_read)
config1 |= GPMC_CONFIG1_READMULTIPLE_SUPP;
if (p->burst_write)
config1 |= GPMC_CONFIG1_WRITEMULTIPLE_SUPP;
if (p->burst_read || p->burst_write) {
config1 |= GPMC_CONFIG1_PAGE_LEN(p->burst_len >> 3);
config1 |= p->burst_wrap ? GPMC_CONFIG1_WRAPBURST_SUPP : 0;
}
gpmc_cs_write_reg(cs, GPMC_CS_CONFIG1, config1);
return 0;
}
void gpmc_read_settings_dt(struct device_node *np, struct gpmc_settings *p)
{
memset(p, 0, sizeof(struct gpmc_settings));
p->sync_read = of_property_read_bool(np, "gpmc,sync-read");
p->sync_write = of_property_read_bool(np, "gpmc,sync-write");
of_property_read_u32(np, "gpmc,device-width", &p->device_width);
of_property_read_u32(np, "gpmc,mux-add-data", &p->mux_add_data);
if (!of_property_read_u32(np, "gpmc,burst-length", &p->burst_len)) {
p->burst_wrap = of_property_read_bool(np, "gpmc,burst-wrap");
p->burst_read = of_property_read_bool(np, "gpmc,burst-read");
p->burst_write = of_property_read_bool(np, "gpmc,burst-write");
if (!p->burst_read && !p->burst_write)
pr_warn("%s: page/burst-length set but not used!\n",
__func__);
}
if (!of_property_read_u32(np, "gpmc,wait-pin", &p->wait_pin)) {
p->wait_on_read = of_property_read_bool(np,
"gpmc,wait-on-read");
p->wait_on_write = of_property_read_bool(np,
"gpmc,wait-on-write");
if (!p->wait_on_read && !p->wait_on_write)
pr_debug("%s: rd/wr wait monitoring not enabled!\n",
__func__);
}
}
static void __maybe_unused gpmc_read_timings_dt(struct device_node *np,
struct gpmc_timings *gpmc_t)
{
struct gpmc_bool_timings *p;
if (!np || !gpmc_t)
return;
memset(gpmc_t, 0, sizeof(*gpmc_t));
of_property_read_u32(np, "gpmc,sync-clk-ps", &gpmc_t->sync_clk);
of_property_read_u32(np, "gpmc,cs-on-ns", &gpmc_t->cs_on);
of_property_read_u32(np, "gpmc,cs-rd-off-ns", &gpmc_t->cs_rd_off);
of_property_read_u32(np, "gpmc,cs-wr-off-ns", &gpmc_t->cs_wr_off);
of_property_read_u32(np, "gpmc,adv-on-ns", &gpmc_t->adv_on);
of_property_read_u32(np, "gpmc,adv-rd-off-ns", &gpmc_t->adv_rd_off);
of_property_read_u32(np, "gpmc,adv-wr-off-ns", &gpmc_t->adv_wr_off);
of_property_read_u32(np, "gpmc,adv-aad-mux-on-ns",
&gpmc_t->adv_aad_mux_on);
of_property_read_u32(np, "gpmc,adv-aad-mux-rd-off-ns",
&gpmc_t->adv_aad_mux_rd_off);
of_property_read_u32(np, "gpmc,adv-aad-mux-wr-off-ns",
&gpmc_t->adv_aad_mux_wr_off);
of_property_read_u32(np, "gpmc,we-on-ns", &gpmc_t->we_on);
of_property_read_u32(np, "gpmc,we-off-ns", &gpmc_t->we_off);
of_property_read_u32(np, "gpmc,oe-on-ns", &gpmc_t->oe_on);
of_property_read_u32(np, "gpmc,oe-off-ns", &gpmc_t->oe_off);
of_property_read_u32(np, "gpmc,oe-aad-mux-on-ns",
&gpmc_t->oe_aad_mux_on);
of_property_read_u32(np, "gpmc,oe-aad-mux-off-ns",
&gpmc_t->oe_aad_mux_off);
of_property_read_u32(np, "gpmc,page-burst-access-ns",
&gpmc_t->page_burst_access);
of_property_read_u32(np, "gpmc,access-ns", &gpmc_t->access);
of_property_read_u32(np, "gpmc,rd-cycle-ns", &gpmc_t->rd_cycle);
of_property_read_u32(np, "gpmc,wr-cycle-ns", &gpmc_t->wr_cycle);
of_property_read_u32(np, "gpmc,bus-turnaround-ns",
&gpmc_t->bus_turnaround);
of_property_read_u32(np, "gpmc,cycle2cycle-delay-ns",
&gpmc_t->cycle2cycle_delay);
of_property_read_u32(np, "gpmc,wait-monitoring-ns",
&gpmc_t->wait_monitoring);
of_property_read_u32(np, "gpmc,clk-activation-ns",
&gpmc_t->clk_activation);
of_property_read_u32(np, "gpmc,wr-access-ns", &gpmc_t->wr_access);
of_property_read_u32(np, "gpmc,wr-data-mux-bus-ns",
&gpmc_t->wr_data_mux_bus);
p = &gpmc_t->bool_timings;
p->cycle2cyclediffcsen =
of_property_read_bool(np, "gpmc,cycle2cycle-diffcsen");
p->cycle2cyclesamecsen =
of_property_read_bool(np, "gpmc,cycle2cycle-samecsen");
p->we_extra_delay = of_property_read_bool(np, "gpmc,we-extra-delay");
p->oe_extra_delay = of_property_read_bool(np, "gpmc,oe-extra-delay");
p->adv_extra_delay = of_property_read_bool(np, "gpmc,adv-extra-delay");
p->cs_extra_delay = of_property_read_bool(np, "gpmc,cs-extra-delay");
p->time_para_granularity =
of_property_read_bool(np, "gpmc,time-para-granularity");
}
static int gpmc_probe_onenand_child(struct platform_device *pdev,
struct device_node *child)
{
u32 val;
struct omap_onenand_platform_data *gpmc_onenand_data;
if (of_property_read_u32(child, "reg", &val) < 0) {
dev_err(&pdev->dev, "%s has no 'reg' property\n",
child->full_name);
return -ENODEV;
}
gpmc_onenand_data = devm_kzalloc(&pdev->dev, sizeof(*gpmc_onenand_data),
GFP_KERNEL);
if (!gpmc_onenand_data)
return -ENOMEM;
gpmc_onenand_data->cs = val;
gpmc_onenand_data->of_node = child;
gpmc_onenand_data->dma_channel = -1;
if (!of_property_read_u32(child, "dma-channel", &val))
gpmc_onenand_data->dma_channel = val;
gpmc_onenand_init(gpmc_onenand_data);
return 0;
}
static int gpmc_probe_onenand_child(struct platform_device *pdev,
struct device_node *child)
{
return 0;
}
static int gpmc_probe_generic_child(struct platform_device *pdev,
struct device_node *child)
{
struct gpmc_settings gpmc_s;
struct gpmc_timings gpmc_t;
struct resource res;
unsigned long base;
const char *name;
int ret, cs;
u32 val;
struct gpio_desc *waitpin_desc = NULL;
struct gpmc_device *gpmc = platform_get_drvdata(pdev);
if (of_property_read_u32(child, "reg", &cs) < 0) {
dev_err(&pdev->dev, "%s has no 'reg' property\n",
child->full_name);
return -ENODEV;
}
if (of_address_to_resource(child, 0, &res) < 0) {
dev_err(&pdev->dev, "%s has malformed 'reg' property\n",
child->full_name);
return -ENODEV;
}
name = gpmc_cs_get_name(cs);
if (name && child->name && of_node_cmp(child->name, name) == 0)
goto no_timings;
ret = gpmc_cs_request(cs, resource_size(&res), &base);
if (ret < 0) {
dev_err(&pdev->dev, "cannot request GPMC CS %d\n", cs);
return ret;
}
gpmc_cs_set_name(cs, child->name);
gpmc_read_settings_dt(child, &gpmc_s);
gpmc_read_timings_dt(child, &gpmc_t);
if (!gpmc_t.cs_rd_off) {
WARN(1, "enable GPMC debug to configure .dts timings for CS%i\n",
cs);
gpmc_cs_show_timings(cs,
"please add GPMC bootloader timings to .dts");
goto no_timings;
}
gpmc_cs_disable_mem(cs);
ret = gpmc_cs_remap(cs, res.start);
if (ret < 0) {
dev_err(&pdev->dev, "cannot remap GPMC CS %d to %pa\n",
cs, &res.start);
if (res.start < GPMC_MEM_START) {
dev_info(&pdev->dev,
"GPMC CS %d start cannot be lesser than 0x%x\n",
cs, GPMC_MEM_START);
} else if (res.end > GPMC_MEM_END) {
dev_info(&pdev->dev,
"GPMC CS %d end cannot be greater than 0x%x\n",
cs, GPMC_MEM_END);
}
goto err;
}
if (of_node_cmp(child->name, "nand") == 0) {
if (!of_property_read_bool(child, "compatible")) {
dev_warn(&pdev->dev,
"Incompatible NAND node: missing compatible");
ret = -EINVAL;
goto err;
}
}
if (of_device_is_compatible(child, "ti,omap2-nand")) {
val = 8;
of_property_read_u32(child, "nand-bus-width", &val);
switch (val) {
case 8:
gpmc_s.device_width = GPMC_DEVWIDTH_8BIT;
break;
case 16:
gpmc_s.device_width = GPMC_DEVWIDTH_16BIT;
break;
default:
dev_err(&pdev->dev, "%s: invalid 'nand-bus-width'\n",
child->name);
ret = -EINVAL;
goto err;
}
gpmc_configure(GPMC_CONFIG_WP, 0);
gpmc_s.device_nand = true;
} else {
ret = of_property_read_u32(child, "bank-width",
&gpmc_s.device_width);
if (ret < 0)
goto err;
}
if (gpmc_s.wait_on_read || gpmc_s.wait_on_write) {
unsigned int wait_pin = gpmc_s.wait_pin;
waitpin_desc = gpiochip_request_own_desc(&gpmc->gpio_chip,
wait_pin, "WAITPIN");
if (IS_ERR(waitpin_desc)) {
dev_err(&pdev->dev, "invalid wait-pin: %d\n", wait_pin);
ret = PTR_ERR(waitpin_desc);
goto err;
}
}
gpmc_cs_show_timings(cs, "before gpmc_cs_program_settings");
ret = gpmc_cs_program_settings(cs, &gpmc_s);
if (ret < 0)
goto err_cs;
ret = gpmc_cs_set_timings(cs, &gpmc_t, &gpmc_s);
if (ret) {
dev_err(&pdev->dev, "failed to set gpmc timings for: %s\n",
child->name);
goto err_cs;
}
val = gpmc_read_reg(GPMC_CONFIG);
val &= ~GPMC_CONFIG_LIMITEDADDRESS;
gpmc_write_reg(GPMC_CONFIG, val);
gpmc_cs_enable_mem(cs);
no_timings:
if (!of_platform_device_create(child, NULL, &pdev->dev))
goto err_child_fail;
if (of_match_node(of_default_bus_match_table, child))
if (of_platform_populate(child, of_default_bus_match_table,
NULL, &pdev->dev))
goto err_child_fail;
return 0;
err_child_fail:
dev_err(&pdev->dev, "failed to create gpmc child %s\n", child->name);
ret = -ENODEV;
err_cs:
if (waitpin_desc)
gpiochip_free_own_desc(waitpin_desc);
err:
gpmc_cs_free(cs);
return ret;
}
static int gpmc_gpio_get_direction(struct gpio_chip *chip, unsigned int offset)
{
return 1;
}
static int gpmc_gpio_direction_input(struct gpio_chip *chip,
unsigned int offset)
{
return 0;
}
static int gpmc_gpio_direction_output(struct gpio_chip *chip,
unsigned int offset, int value)
{
return -EINVAL;
}
static void gpmc_gpio_set(struct gpio_chip *chip, unsigned int offset,
int value)
{
}
static int gpmc_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
u32 reg;
offset += 8;
reg = gpmc_read_reg(GPMC_STATUS) & BIT(offset);
return !!reg;
}
static int gpmc_gpio_init(struct gpmc_device *gpmc)
{
int ret;
gpmc->gpio_chip.parent = gpmc->dev;
gpmc->gpio_chip.owner = THIS_MODULE;
gpmc->gpio_chip.label = DEVICE_NAME;
gpmc->gpio_chip.ngpio = gpmc_nr_waitpins;
gpmc->gpio_chip.get_direction = gpmc_gpio_get_direction;
gpmc->gpio_chip.direction_input = gpmc_gpio_direction_input;
gpmc->gpio_chip.direction_output = gpmc_gpio_direction_output;
gpmc->gpio_chip.set = gpmc_gpio_set;
gpmc->gpio_chip.get = gpmc_gpio_get;
gpmc->gpio_chip.base = -1;
ret = gpiochip_add(&gpmc->gpio_chip);
if (ret < 0) {
dev_err(gpmc->dev, "could not register gpio chip: %d\n", ret);
return ret;
}
return 0;
}
static void gpmc_gpio_exit(struct gpmc_device *gpmc)
{
gpiochip_remove(&gpmc->gpio_chip);
}
static int gpmc_probe_dt(struct platform_device *pdev)
{
int ret;
const struct of_device_id *of_id =
of_match_device(gpmc_dt_ids, &pdev->dev);
if (!of_id)
return 0;
ret = of_property_read_u32(pdev->dev.of_node, "gpmc,num-cs",
&gpmc_cs_num);
if (ret < 0) {
pr_err("%s: number of chip-selects not defined\n", __func__);
return ret;
} else if (gpmc_cs_num < 1) {
pr_err("%s: all chip-selects are disabled\n", __func__);
return -EINVAL;
} else if (gpmc_cs_num > GPMC_CS_NUM) {
pr_err("%s: number of supported chip-selects cannot be > %d\n",
__func__, GPMC_CS_NUM);
return -EINVAL;
}
ret = of_property_read_u32(pdev->dev.of_node, "gpmc,num-waitpins",
&gpmc_nr_waitpins);
if (ret < 0) {
pr_err("%s: number of wait pins not found!\n", __func__);
return ret;
}
return 0;
}
static int gpmc_probe_dt_children(struct platform_device *pdev)
{
int ret;
struct device_node *child;
for_each_available_child_of_node(pdev->dev.of_node, child) {
if (!child->name)
continue;
if (of_node_cmp(child->name, "onenand") == 0)
ret = gpmc_probe_onenand_child(pdev, child);
else
ret = gpmc_probe_generic_child(pdev, child);
if (ret)
return ret;
}
return 0;
}
static int gpmc_probe_dt(struct platform_device *pdev)
{
return 0;
}
static int gpmc_probe_dt_children(struct platform_device *pdev)
{
return 0;
}
static int gpmc_probe(struct platform_device *pdev)
{
int rc;
u32 l;
struct resource *res;
struct gpmc_device *gpmc;
gpmc = devm_kzalloc(&pdev->dev, sizeof(*gpmc), GFP_KERNEL);
if (!gpmc)
return -ENOMEM;
gpmc->dev = &pdev->dev;
platform_set_drvdata(pdev, gpmc);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL)
return -ENOENT;
phys_base = res->start;
mem_size = resource_size(res);
gpmc_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(gpmc_base))
return PTR_ERR(gpmc_base);
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res) {
dev_err(&pdev->dev, "Failed to get resource: irq\n");
return -ENOENT;
}
gpmc->irq = res->start;
gpmc_l3_clk = devm_clk_get(&pdev->dev, "fck");
if (IS_ERR(gpmc_l3_clk)) {
dev_err(&pdev->dev, "Failed to get GPMC fck\n");
return PTR_ERR(gpmc_l3_clk);
}
if (!clk_get_rate(gpmc_l3_clk)) {
dev_err(&pdev->dev, "Invalid GPMC fck clock rate\n");
return -EINVAL;
}
if (pdev->dev.of_node) {
rc = gpmc_probe_dt(pdev);
if (rc)
return rc;
} else {
gpmc_cs_num = GPMC_CS_NUM;
gpmc_nr_waitpins = GPMC_NR_WAITPINS;
}
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
l = gpmc_read_reg(GPMC_REVISION);
if (GPMC_REVISION_MAJOR(l) > 0x4)
gpmc_capability = GPMC_HAS_WR_ACCESS | GPMC_HAS_WR_DATA_MUX_BUS;
if (GPMC_REVISION_MAJOR(l) > 0x5)
gpmc_capability |= GPMC_HAS_MUX_AAD;
dev_info(gpmc->dev, "GPMC revision %d.%d\n", GPMC_REVISION_MAJOR(l),
GPMC_REVISION_MINOR(l));
gpmc_mem_init();
rc = gpmc_gpio_init(gpmc);
if (rc)
goto gpio_init_failed;
gpmc->nirqs = GPMC_NR_NAND_IRQS + gpmc_nr_waitpins;
rc = gpmc_setup_irq(gpmc);
if (rc) {
dev_err(gpmc->dev, "gpmc_setup_irq failed\n");
goto setup_irq_failed;
}
rc = gpmc_probe_dt_children(pdev);
if (rc < 0) {
dev_err(gpmc->dev, "failed to probe DT children\n");
goto dt_children_failed;
}
return 0;
dt_children_failed:
gpmc_free_irq(gpmc);
setup_irq_failed:
gpmc_gpio_exit(gpmc);
gpio_init_failed:
gpmc_mem_exit();
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return rc;
}
static int gpmc_remove(struct platform_device *pdev)
{
struct gpmc_device *gpmc = platform_get_drvdata(pdev);
gpmc_free_irq(gpmc);
gpmc_gpio_exit(gpmc);
gpmc_mem_exit();
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int gpmc_suspend(struct device *dev)
{
omap3_gpmc_save_context();
pm_runtime_put_sync(dev);
return 0;
}
static int gpmc_resume(struct device *dev)
{
pm_runtime_get_sync(dev);
omap3_gpmc_restore_context();
return 0;
}
static __init int gpmc_init(void)
{
return platform_driver_register(&gpmc_driver);
}
static __exit void gpmc_exit(void)
{
platform_driver_unregister(&gpmc_driver);
}
void omap3_gpmc_save_context(void)
{
int i;
if (!gpmc_base)
return;
gpmc_context.sysconfig = gpmc_read_reg(GPMC_SYSCONFIG);
gpmc_context.irqenable = gpmc_read_reg(GPMC_IRQENABLE);
gpmc_context.timeout_ctrl = gpmc_read_reg(GPMC_TIMEOUT_CONTROL);
gpmc_context.config = gpmc_read_reg(GPMC_CONFIG);
gpmc_context.prefetch_config1 = gpmc_read_reg(GPMC_PREFETCH_CONFIG1);
gpmc_context.prefetch_config2 = gpmc_read_reg(GPMC_PREFETCH_CONFIG2);
gpmc_context.prefetch_control = gpmc_read_reg(GPMC_PREFETCH_CONTROL);
for (i = 0; i < gpmc_cs_num; i++) {
gpmc_context.cs_context[i].is_valid = gpmc_cs_mem_enabled(i);
if (gpmc_context.cs_context[i].is_valid) {
gpmc_context.cs_context[i].config1 =
gpmc_cs_read_reg(i, GPMC_CS_CONFIG1);
gpmc_context.cs_context[i].config2 =
gpmc_cs_read_reg(i, GPMC_CS_CONFIG2);
gpmc_context.cs_context[i].config3 =
gpmc_cs_read_reg(i, GPMC_CS_CONFIG3);
gpmc_context.cs_context[i].config4 =
gpmc_cs_read_reg(i, GPMC_CS_CONFIG4);
gpmc_context.cs_context[i].config5 =
gpmc_cs_read_reg(i, GPMC_CS_CONFIG5);
gpmc_context.cs_context[i].config6 =
gpmc_cs_read_reg(i, GPMC_CS_CONFIG6);
gpmc_context.cs_context[i].config7 =
gpmc_cs_read_reg(i, GPMC_CS_CONFIG7);
}
}
}
void omap3_gpmc_restore_context(void)
{
int i;
if (!gpmc_base)
return;
gpmc_write_reg(GPMC_SYSCONFIG, gpmc_context.sysconfig);
gpmc_write_reg(GPMC_IRQENABLE, gpmc_context.irqenable);
gpmc_write_reg(GPMC_TIMEOUT_CONTROL, gpmc_context.timeout_ctrl);
gpmc_write_reg(GPMC_CONFIG, gpmc_context.config);
gpmc_write_reg(GPMC_PREFETCH_CONFIG1, gpmc_context.prefetch_config1);
gpmc_write_reg(GPMC_PREFETCH_CONFIG2, gpmc_context.prefetch_config2);
gpmc_write_reg(GPMC_PREFETCH_CONTROL, gpmc_context.prefetch_control);
for (i = 0; i < gpmc_cs_num; i++) {
if (gpmc_context.cs_context[i].is_valid) {
gpmc_cs_write_reg(i, GPMC_CS_CONFIG1,
gpmc_context.cs_context[i].config1);
gpmc_cs_write_reg(i, GPMC_CS_CONFIG2,
gpmc_context.cs_context[i].config2);
gpmc_cs_write_reg(i, GPMC_CS_CONFIG3,
gpmc_context.cs_context[i].config3);
gpmc_cs_write_reg(i, GPMC_CS_CONFIG4,
gpmc_context.cs_context[i].config4);
gpmc_cs_write_reg(i, GPMC_CS_CONFIG5,
gpmc_context.cs_context[i].config5);
gpmc_cs_write_reg(i, GPMC_CS_CONFIG6,
gpmc_context.cs_context[i].config6);
gpmc_cs_write_reg(i, GPMC_CS_CONFIG7,
gpmc_context.cs_context[i].config7);
}
}
}
