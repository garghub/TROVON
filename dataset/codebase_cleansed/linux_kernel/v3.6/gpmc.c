static void gpmc_write_reg(int idx, u32 val)
{
__raw_writel(val, gpmc_base + idx);
}
static u32 gpmc_read_reg(int idx)
{
return __raw_readl(gpmc_base + idx);
}
static void gpmc_cs_write_byte(int cs, int idx, u8 val)
{
void __iomem *reg_addr;
reg_addr = gpmc_base + GPMC_CS0_OFFSET + (cs * GPMC_CS_SIZE) + idx;
__raw_writeb(val, reg_addr);
}
static u8 gpmc_cs_read_byte(int cs, int idx)
{
void __iomem *reg_addr;
reg_addr = gpmc_base + GPMC_CS0_OFFSET + (cs * GPMC_CS_SIZE) + idx;
return __raw_readb(reg_addr);
}
void gpmc_cs_write_reg(int cs, int idx, u32 val)
{
void __iomem *reg_addr;
reg_addr = gpmc_base + GPMC_CS0_OFFSET + (cs * GPMC_CS_SIZE) + idx;
__raw_writel(val, reg_addr);
}
u32 gpmc_cs_read_reg(int cs, int idx)
{
void __iomem *reg_addr;
reg_addr = gpmc_base + GPMC_CS0_OFFSET + (cs * GPMC_CS_SIZE) + idx;
return __raw_readl(reg_addr);
}
unsigned long gpmc_get_fclk_period(void)
{
unsigned long rate = clk_get_rate(gpmc_l3_clk);
if (rate == 0) {
printk(KERN_WARNING "gpmc_l3_clk not enabled\n");
return 0;
}
rate /= 1000;
rate = 1000000000 / rate;
return rate;
}
unsigned int gpmc_ns_to_ticks(unsigned int time_ns)
{
unsigned long tick_ps;
tick_ps = gpmc_get_fclk_period();
return (time_ns * 1000 + tick_ps - 1) / tick_ps;
}
unsigned int gpmc_ps_to_ticks(unsigned int time_ps)
{
unsigned long tick_ps;
tick_ps = gpmc_get_fclk_period();
return (time_ps + tick_ps - 1) / tick_ps;
}
unsigned int gpmc_ticks_to_ns(unsigned int ticks)
{
return ticks * gpmc_get_fclk_period() / 1000;
}
unsigned int gpmc_round_ns_to_ticks(unsigned int time_ns)
{
unsigned long ticks = gpmc_ns_to_ticks(time_ns);
return ticks * gpmc_get_fclk_period() / 1000;
}
int gpmc_cs_calc_divider(int cs, unsigned int sync_clk)
{
int div;
u32 l;
l = sync_clk + (gpmc_get_fclk_period() - 1);
div = l / gpmc_get_fclk_period();
if (div > 4)
return -1;
if (div <= 0)
div = 1;
return div;
}
int gpmc_cs_set_timings(int cs, const struct gpmc_timings *t)
{
int div;
u32 l;
div = gpmc_cs_calc_divider(cs, t->sync_clk);
if (div < 0)
return -1;
GPMC_SET_ONE(GPMC_CS_CONFIG2, 0, 3, cs_on);
GPMC_SET_ONE(GPMC_CS_CONFIG2, 8, 12, cs_rd_off);
GPMC_SET_ONE(GPMC_CS_CONFIG2, 16, 20, cs_wr_off);
GPMC_SET_ONE(GPMC_CS_CONFIG3, 0, 3, adv_on);
GPMC_SET_ONE(GPMC_CS_CONFIG3, 8, 12, adv_rd_off);
GPMC_SET_ONE(GPMC_CS_CONFIG3, 16, 20, adv_wr_off);
GPMC_SET_ONE(GPMC_CS_CONFIG4, 0, 3, oe_on);
GPMC_SET_ONE(GPMC_CS_CONFIG4, 8, 12, oe_off);
GPMC_SET_ONE(GPMC_CS_CONFIG4, 16, 19, we_on);
GPMC_SET_ONE(GPMC_CS_CONFIG4, 24, 28, we_off);
GPMC_SET_ONE(GPMC_CS_CONFIG5, 0, 4, rd_cycle);
GPMC_SET_ONE(GPMC_CS_CONFIG5, 8, 12, wr_cycle);
GPMC_SET_ONE(GPMC_CS_CONFIG5, 16, 20, access);
GPMC_SET_ONE(GPMC_CS_CONFIG5, 24, 27, page_burst_access);
if (cpu_is_omap34xx()) {
GPMC_SET_ONE(GPMC_CS_CONFIG6, 16, 19, wr_data_mux_bus);
GPMC_SET_ONE(GPMC_CS_CONFIG6, 24, 28, wr_access);
}
l = gpmc_cs_read_reg(cs, GPMC_CS_CONFIG1);
if (l & (GPMC_CONFIG1_READTYPE_SYNC | GPMC_CONFIG1_WRITETYPE_SYNC)) {
#ifdef DEBUG
printk(KERN_INFO "GPMC CS%d CLK period is %lu ns (div %d)\n",
cs, (div * gpmc_get_fclk_period()) / 1000, div);
#endif
l &= ~0x03;
l |= (div - 1);
gpmc_cs_write_reg(cs, GPMC_CS_CONFIG1, l);
}
return 0;
}
static void gpmc_cs_enable_mem(int cs, u32 base, u32 size)
{
u32 l;
u32 mask;
mask = (1 << GPMC_SECTION_SHIFT) - size;
l = gpmc_cs_read_reg(cs, GPMC_CS_CONFIG7);
l &= ~0x3f;
l = (base >> GPMC_CHUNK_SHIFT) & 0x3f;
l &= ~(0x0f << 8);
l |= ((mask >> GPMC_CHUNK_SHIFT) & 0x0f) << 8;
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
int gpmc_cs_set_reserved(int cs, int reserved)
{
if (cs > GPMC_CS_NUM)
return -ENODEV;
gpmc_cs_map &= ~(1 << cs);
gpmc_cs_map |= (reserved ? 1 : 0) << cs;
return 0;
}
int gpmc_cs_reserved(int cs)
{
if (cs > GPMC_CS_NUM)
return -ENODEV;
return gpmc_cs_map & (1 << cs);
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
struct resource *res = &gpmc_cs_mem[cs];
int r;
size = gpmc_mem_align(size);
spin_lock(&gpmc_mem_lock);
res->start = base;
res->end = base + size - 1;
r = request_resource(&gpmc_mem_root, res);
spin_unlock(&gpmc_mem_lock);
return r;
}
int gpmc_cs_request(int cs, unsigned long size, unsigned long *base)
{
struct resource *res = &gpmc_cs_mem[cs];
int r = -1;
if (cs > GPMC_CS_NUM)
return -ENODEV;
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
gpmc_cs_enable_mem(cs, res->start, resource_size(res));
*base = res->start;
gpmc_cs_set_reserved(cs, 1);
out:
spin_unlock(&gpmc_mem_lock);
return r;
}
void gpmc_cs_free(int cs)
{
spin_lock(&gpmc_mem_lock);
if (cs >= GPMC_CS_NUM || cs < 0 || !gpmc_cs_reserved(cs)) {
printk(KERN_ERR "Trying to free non-reserved GPMC CS%d\n", cs);
BUG();
spin_unlock(&gpmc_mem_lock);
return;
}
gpmc_cs_disable_mem(cs);
release_resource(&gpmc_cs_mem[cs]);
gpmc_cs_set_reserved(cs, 0);
spin_unlock(&gpmc_mem_lock);
}
int gpmc_read_status(int cmd)
{
int status = -EINVAL;
u32 regval = 0;
switch (cmd) {
case GPMC_GET_IRQ_STATUS:
status = gpmc_read_reg(GPMC_IRQSTATUS);
break;
case GPMC_PREFETCH_FIFO_CNT:
regval = gpmc_read_reg(GPMC_PREFETCH_STATUS);
status = GPMC_PREFETCH_STATUS_FIFO_CNT(regval);
break;
case GPMC_PREFETCH_COUNT:
regval = gpmc_read_reg(GPMC_PREFETCH_STATUS);
status = GPMC_PREFETCH_STATUS_COUNT(regval);
break;
case GPMC_STATUS_BUFFER:
regval = gpmc_read_reg(GPMC_STATUS);
status = regval & GPMC_STATUS_BUFF_EMPTY;
break;
default:
printk(KERN_ERR "gpmc_read_status: Not supported\n");
}
return status;
}
int gpmc_cs_configure(int cs, int cmd, int wval)
{
int err = 0;
u32 regval = 0;
switch (cmd) {
case GPMC_ENABLE_IRQ:
gpmc_write_reg(GPMC_IRQENABLE, wval);
break;
case GPMC_SET_IRQ_STATUS:
gpmc_write_reg(GPMC_IRQSTATUS, wval);
break;
case GPMC_CONFIG_WP:
regval = gpmc_read_reg(GPMC_CONFIG);
if (wval)
regval &= ~GPMC_CONFIG_WRITEPROTECT;
else
regval |= GPMC_CONFIG_WRITEPROTECT;
gpmc_write_reg(GPMC_CONFIG, regval);
break;
case GPMC_CONFIG_RDY_BSY:
regval = gpmc_cs_read_reg(cs, GPMC_CS_CONFIG1);
if (wval)
regval |= WR_RD_PIN_MONITORING;
else
regval &= ~WR_RD_PIN_MONITORING;
gpmc_cs_write_reg(cs, GPMC_CS_CONFIG1, regval);
break;
case GPMC_CONFIG_DEV_SIZE:
regval = gpmc_cs_read_reg(cs, GPMC_CS_CONFIG1);
regval &= ~GPMC_CONFIG1_DEVICESIZE(3);
regval |= GPMC_CONFIG1_DEVICESIZE(wval);
gpmc_cs_write_reg(cs, GPMC_CS_CONFIG1, regval);
break;
case GPMC_CONFIG_DEV_TYPE:
regval = gpmc_cs_read_reg(cs, GPMC_CS_CONFIG1);
regval |= GPMC_CONFIG1_DEVICETYPE(wval);
if (wval == GPMC_DEVICETYPE_NOR)
regval |= GPMC_CONFIG1_MUXADDDATA;
gpmc_cs_write_reg(cs, GPMC_CS_CONFIG1, regval);
break;
default:
printk(KERN_ERR "gpmc_configure_cs: Not supported\n");
err = -EINVAL;
}
return err;
}
int gpmc_nand_read(int cs, int cmd)
{
int rval = -EINVAL;
switch (cmd) {
case GPMC_NAND_DATA:
rval = gpmc_cs_read_byte(cs, GPMC_CS_NAND_DATA);
break;
default:
printk(KERN_ERR "gpmc_read_nand_ctrl: Not supported\n");
}
return rval;
}
int gpmc_nand_write(int cs, int cmd, int wval)
{
int err = 0;
switch (cmd) {
case GPMC_NAND_COMMAND:
gpmc_cs_write_byte(cs, GPMC_CS_NAND_COMMAND, wval);
break;
case GPMC_NAND_ADDRESS:
gpmc_cs_write_byte(cs, GPMC_CS_NAND_ADDRESS, wval);
break;
case GPMC_NAND_DATA:
gpmc_cs_write_byte(cs, GPMC_CS_NAND_DATA, wval);
default:
printk(KERN_ERR "gpmc_write_nand_ctrl: Not supported\n");
err = -EINVAL;
}
return err;
}
int gpmc_prefetch_enable(int cs, int fifo_th, int dma_mode,
unsigned int u32_count, int is_write)
{
if (fifo_th > PREFETCH_FIFOTHRESHOLD_MAX) {
pr_err("gpmc: fifo threshold is not supported\n");
return -1;
} else if (!(gpmc_read_reg(GPMC_PREFETCH_CONTROL))) {
gpmc_write_reg(GPMC_PREFETCH_CONFIG2, u32_count);
gpmc_write_reg(GPMC_PREFETCH_CONFIG1, ((cs << CS_NUM_SHIFT) |
PREFETCH_FIFOTHRESHOLD(fifo_th) |
ENABLE_PREFETCH |
(dma_mode << DMA_MPU_MODE) |
(0x1 & is_write)));
gpmc_write_reg(GPMC_PREFETCH_CONTROL, 0x1);
} else {
return -EBUSY;
}
return 0;
}
int gpmc_prefetch_reset(int cs)
{
u32 config1;
config1 = gpmc_read_reg(GPMC_PREFETCH_CONFIG1);
if (((config1 >> CS_NUM_SHIFT) & 0x7) != cs)
return -EINVAL;
gpmc_write_reg(GPMC_PREFETCH_CONTROL, 0x0);
gpmc_write_reg(GPMC_PREFETCH_CONFIG1, 0x0);
return 0;
}
static void __init gpmc_mem_init(void)
{
int cs;
unsigned long boot_rom_space = 0;
boot_rom_space = BOOT_ROM_SPACE;
if (machine_is_omap_apollon())
boot_rom_space = 0;
gpmc_mem_root.start = GPMC_MEM_START + boot_rom_space;
gpmc_mem_root.end = GPMC_MEM_END;
for (cs = 0; cs < GPMC_CS_NUM; cs++) {
u32 base, size;
if (!gpmc_cs_mem_enabled(cs))
continue;
gpmc_cs_get_memconf(cs, &base, &size);
if (gpmc_cs_insert_mem(cs, base, size) < 0)
BUG();
}
}
static int __init gpmc_init(void)
{
u32 l, irq;
int cs, ret = -EINVAL;
int gpmc_irq;
char *ck = NULL;
if (cpu_is_omap24xx()) {
ck = "core_l3_ck";
if (cpu_is_omap2420())
l = OMAP2420_GPMC_BASE;
else
l = OMAP34XX_GPMC_BASE;
gpmc_irq = INT_34XX_GPMC_IRQ;
} else if (cpu_is_omap34xx()) {
ck = "gpmc_fck";
l = OMAP34XX_GPMC_BASE;
gpmc_irq = INT_34XX_GPMC_IRQ;
} else if (cpu_is_omap44xx() || soc_is_omap54xx()) {
ck = "gpmc_ck";
l = OMAP44XX_GPMC_BASE;
gpmc_irq = OMAP44XX_IRQ_GPMC;
}
if (WARN_ON(!ck))
return ret;
gpmc_l3_clk = clk_get(NULL, ck);
if (IS_ERR(gpmc_l3_clk)) {
printk(KERN_ERR "Could not get GPMC clock %s\n", ck);
BUG();
}
gpmc_base = ioremap(l, SZ_4K);
if (!gpmc_base) {
clk_put(gpmc_l3_clk);
printk(KERN_ERR "Could not get GPMC register memory\n");
BUG();
}
clk_enable(gpmc_l3_clk);
l = gpmc_read_reg(GPMC_REVISION);
printk(KERN_INFO "GPMC revision %d.%d\n", (l >> 4) & 0x0f, l & 0x0f);
l = gpmc_read_reg(GPMC_SYSCONFIG);
l &= 0x03 << 3;
l |= (0x02 << 3) | (1 << 0);
gpmc_write_reg(GPMC_SYSCONFIG, l);
gpmc_mem_init();
irq = OMAP_GPMC_IRQ_BASE;
for (cs = 0; cs < GPMC_CS_NUM; cs++) {
irq_set_chip_and_handler(irq, &dummy_irq_chip,
handle_simple_irq);
set_irq_flags(irq, IRQF_VALID);
irq++;
}
ret = request_irq(gpmc_irq, gpmc_handle_irq, IRQF_SHARED, "gpmc", NULL);
if (ret)
pr_err("gpmc: irq-%d could not claim: err %d\n",
gpmc_irq, ret);
return ret;
}
static irqreturn_t gpmc_handle_irq(int irq, void *dev)
{
u8 cs;
cs = ((gpmc_read_reg(GPMC_PREFETCH_CONFIG1)) >> CS_NUM_SHIFT) & 0x7;
if (OMAP_GPMC_IRQ_BASE+cs <= OMAP_GPMC_IRQ_END)
generic_handle_irq(OMAP_GPMC_IRQ_BASE+cs);
return IRQ_HANDLED;
}
void omap3_gpmc_save_context(void)
{
int i;
gpmc_context.sysconfig = gpmc_read_reg(GPMC_SYSCONFIG);
gpmc_context.irqenable = gpmc_read_reg(GPMC_IRQENABLE);
gpmc_context.timeout_ctrl = gpmc_read_reg(GPMC_TIMEOUT_CONTROL);
gpmc_context.config = gpmc_read_reg(GPMC_CONFIG);
gpmc_context.prefetch_config1 = gpmc_read_reg(GPMC_PREFETCH_CONFIG1);
gpmc_context.prefetch_config2 = gpmc_read_reg(GPMC_PREFETCH_CONFIG2);
gpmc_context.prefetch_control = gpmc_read_reg(GPMC_PREFETCH_CONTROL);
for (i = 0; i < GPMC_CS_NUM; i++) {
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
gpmc_write_reg(GPMC_SYSCONFIG, gpmc_context.sysconfig);
gpmc_write_reg(GPMC_IRQENABLE, gpmc_context.irqenable);
gpmc_write_reg(GPMC_TIMEOUT_CONTROL, gpmc_context.timeout_ctrl);
gpmc_write_reg(GPMC_CONFIG, gpmc_context.config);
gpmc_write_reg(GPMC_PREFETCH_CONFIG1, gpmc_context.prefetch_config1);
gpmc_write_reg(GPMC_PREFETCH_CONFIG2, gpmc_context.prefetch_config2);
gpmc_write_reg(GPMC_PREFETCH_CONTROL, gpmc_context.prefetch_control);
for (i = 0; i < GPMC_CS_NUM; i++) {
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
int gpmc_enable_hwecc(int cs, int mode, int dev_width, int ecc_size)
{
unsigned int val;
if (gpmc_ecc_used != -EINVAL)
return -EINVAL;
gpmc_ecc_used = cs;
gpmc_write_reg(GPMC_ECC_CONTROL,
GPMC_ECC_CTRL_ECCCLEAR |
GPMC_ECC_CTRL_ECCREG1);
val = ((((ecc_size >> 1) - 1) << 22) | (0x0000000F));
gpmc_write_reg(GPMC_ECC_SIZE_CONFIG, val);
switch (mode) {
case GPMC_ECC_READ:
case GPMC_ECC_WRITE:
gpmc_write_reg(GPMC_ECC_CONTROL,
GPMC_ECC_CTRL_ECCCLEAR |
GPMC_ECC_CTRL_ECCREG1);
break;
case GPMC_ECC_READSYN:
gpmc_write_reg(GPMC_ECC_CONTROL,
GPMC_ECC_CTRL_ECCCLEAR |
GPMC_ECC_CTRL_ECCDISABLE);
break;
default:
printk(KERN_INFO "Error: Unrecognized Mode[%d]!\n", mode);
break;
}
val = (dev_width << 7) | (cs << 1) | (0x1);
gpmc_write_reg(GPMC_ECC_CONFIG, val);
return 0;
}
int gpmc_calculate_ecc(int cs, const u_char *dat, u_char *ecc_code)
{
unsigned int val = 0x0;
if (gpmc_ecc_used != cs)
return -EINVAL;
val = gpmc_read_reg(GPMC_ECC1_RESULT);
*ecc_code++ = val;
*ecc_code++ = val >> 16;
*ecc_code++ = ((val >> 8) & 0x0f) | ((val >> 20) & 0xf0);
gpmc_ecc_used = -EINVAL;
return 0;
}
int gpmc_init_hwecc_bch(int cs, int nsectors, int nerrors)
{
if (gpmc_ecc_used != -EINVAL)
return -EINVAL;
if (!cpu_is_omap34xx()) {
printk(KERN_ERR "BCH ecc is not supported on this CPU\n");
return -EINVAL;
}
if ((nerrors == 4) &&
(!cpu_is_omap3630() || (GET_OMAP_REVISION() == 0))) {
printk(KERN_ERR "BCH 4-bit mode is not supported on this CPU\n");
return -EINVAL;
}
if (nsectors > 8) {
printk(KERN_ERR "BCH cannot process %d sectors (max is 8)\n",
nsectors);
return -EINVAL;
}
return 0;
}
int gpmc_enable_hwecc_bch(int cs, int mode, int dev_width, int nsectors,
int nerrors)
{
unsigned int val;
if (gpmc_ecc_used != -EINVAL)
return -EINVAL;
gpmc_ecc_used = cs;
gpmc_write_reg(GPMC_ECC_CONTROL, 0x1);
gpmc_write_reg(GPMC_ECC_SIZE_CONFIG, (32 << 22) | (0 << 12));
val = ((1 << 16) |
(((nerrors == 8) ? 1 : 0) << 12) |
(0x06 << 8) |
(dev_width << 7) |
(((nsectors-1) & 0x7) << 4) |
(cs << 1) |
(0x1));
gpmc_write_reg(GPMC_ECC_CONFIG, val);
gpmc_write_reg(GPMC_ECC_CONTROL, 0x101);
return 0;
}
int gpmc_calculate_ecc_bch4(int cs, const u_char *dat, u_char *ecc)
{
int i;
unsigned long nsectors, reg, val1, val2;
if (gpmc_ecc_used != cs)
return -EINVAL;
nsectors = ((gpmc_read_reg(GPMC_ECC_CONFIG) >> 4) & 0x7) + 1;
for (i = 0; i < nsectors; i++) {
reg = GPMC_ECC_BCH_RESULT_0 + 16*i;
val1 = gpmc_read_reg(reg + 0);
val2 = gpmc_read_reg(reg + 4);
*ecc++ = 0x28 ^ ((val2 >> 12) & 0xFF);
*ecc++ = 0x13 ^ ((val2 >> 4) & 0xFF);
*ecc++ = 0xcc ^ (((val2 & 0xF) << 4)|((val1 >> 28) & 0xF));
*ecc++ = 0x39 ^ ((val1 >> 20) & 0xFF);
*ecc++ = 0x96 ^ ((val1 >> 12) & 0xFF);
*ecc++ = 0xac ^ ((val1 >> 4) & 0xFF);
*ecc++ = 0x7f ^ ((val1 & 0xF) << 4);
}
gpmc_ecc_used = -EINVAL;
return 0;
}
int gpmc_calculate_ecc_bch8(int cs, const u_char *dat, u_char *ecc)
{
int i;
unsigned long nsectors, reg, val1, val2, val3, val4;
if (gpmc_ecc_used != cs)
return -EINVAL;
nsectors = ((gpmc_read_reg(GPMC_ECC_CONFIG) >> 4) & 0x7) + 1;
for (i = 0; i < nsectors; i++) {
reg = GPMC_ECC_BCH_RESULT_0 + 16*i;
val1 = gpmc_read_reg(reg + 0);
val2 = gpmc_read_reg(reg + 4);
val3 = gpmc_read_reg(reg + 8);
val4 = gpmc_read_reg(reg + 12);
*ecc++ = 0xef ^ (val4 & 0xFF);
*ecc++ = 0x51 ^ ((val3 >> 24) & 0xFF);
*ecc++ = 0x2e ^ ((val3 >> 16) & 0xFF);
*ecc++ = 0x09 ^ ((val3 >> 8) & 0xFF);
*ecc++ = 0xed ^ (val3 & 0xFF);
*ecc++ = 0x93 ^ ((val2 >> 24) & 0xFF);
*ecc++ = 0x9a ^ ((val2 >> 16) & 0xFF);
*ecc++ = 0xc2 ^ ((val2 >> 8) & 0xFF);
*ecc++ = 0x97 ^ (val2 & 0xFF);
*ecc++ = 0x79 ^ ((val1 >> 24) & 0xFF);
*ecc++ = 0xe5 ^ ((val1 >> 16) & 0xFF);
*ecc++ = 0x24 ^ ((val1 >> 8) & 0xFF);
*ecc++ = 0xb5 ^ (val1 & 0xFF);
}
gpmc_ecc_used = -EINVAL;
return 0;
}
