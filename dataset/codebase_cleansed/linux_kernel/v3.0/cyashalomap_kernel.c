static void cy_as_hal_print_omap_regs(char *name_prefix,
u8 name_base, u32 virt_base, u16 count)
{
u32 reg_val, reg_addr;
u16 i;
cy_as_hal_print_message(KERN_INFO "\n");
for (i = 0; i < count; i++) {
reg_addr = virt_base + (i*4);
reg_val = __raw_readl(reg_addr);
cy_as_hal_print_message(KERN_INFO "%s_%d[%8.8x]=%8.8x\n",
name_prefix, name_base+i,
reg_addr, reg_val);
}
}
static u16 omap_cfg_reg_L(u32 pad_func_index)
{
static u8 sanity_check = 1;
u32 reg_vma;
u16 cur_val, wr_val, rdback_val;
cy_as_hal_print_message(KERN_INFO" OMAP pins user_pad cfg ");
if (sanity_check) {
if ((omap_mux_pin_cfg[END_OF_TABLE].name[0] == 'E') &&
(omap_mux_pin_cfg[END_OF_TABLE].name[1] == 'N') &&
(omap_mux_pin_cfg[END_OF_TABLE].name[2] == 'D')) {
cy_as_hal_print_message(KERN_INFO
"table is good.\n");
} else {
cy_as_hal_print_message(KERN_WARNING
"table is bad, fix it");
}
sanity_check = 0;
}
reg_vma = (u32)iomux_vma + omap_mux_pin_cfg[pad_func_index].offset;
wr_val = omap_mux_pin_cfg[pad_func_index].mux_val;
cur_val = IORD16(reg_vma);
IOWR16(reg_vma, wr_val);
rdback_val = IORD16(reg_vma);
return wr_val;
}
void cy_as_hal_gpmc_enable_16bit_bus(bool dbus16_enabled)
{
uint32_t tmp32;
tmp32 = gpmc_cs_read_reg(AST_GPMC_CS,
GPMC_CS_CONFIG7) & ~GPMC_CONFIG7_CSVALID;
gpmc_cs_write_reg(AST_GPMC_CS, GPMC_CS_CONFIG7, tmp32);
if (dbus16_enabled) {
DBGPRN("enabling 16 bit bus\n");
gpmc_cs_write_reg(AST_GPMC_CS, GPMC_CS_CONFIG1,
(GPMC_CONFIG1_DEVICETYPE(2) |
GPMC_CONFIG1_WAIT_PIN_SEL(2) |
GPMC_CONFIG1_DEVICESIZE_16)
);
} else {
DBGPRN(KERN_INFO "enabling 8 bit bus\n");
gpmc_cs_write_reg(AST_GPMC_CS, GPMC_CS_CONFIG1,
(GPMC_CONFIG1_DEVICETYPE(2) |
GPMC_CONFIG1_WAIT_PIN_SEL(2))
);
}
gpmc_cs_write_reg(AST_GPMC_CS, GPMC_CS_CONFIG7,
(tmp32 | GPMC_CONFIG7_CSVALID));
pnand_16bit = dbus16_enabled;
}
static int cy_as_hal_gpmc_init(void)
{
u32 tmp32;
int err;
struct gpmc_timings timings;
gpmc_base = (u32)ioremap_nocache(OMAP34XX_GPMC_BASE, BLKSZ_4K);
DBGPRN(KERN_INFO "kernel has gpmc_base=%x , val@ the base=%x",
gpmc_base, __raw_readl(gpmc_base)
);
ncmd_reg_vma = GPMC_VMA(AST_GPMC_NAND_CMD);
naddr_reg_vma = GPMC_VMA(AST_GPMC_NAND_ADDR);
ndata_reg_vma = GPMC_VMA(AST_GPMC_NAND_DATA);
if (gpmc_cs_request(AST_GPMC_CS, SZ_16M, (void *)&csa_phy) < 0) {
cy_as_hal_print_message(KERN_ERR "error failed to request"
"ncs4 for ASTORIA\n");
return -1;
} else {
DBGPRN(KERN_INFO "got phy_addr:%x for "
"GPMC CS%d GPMC_CFGREG7[CS4]\n",
csa_phy, AST_GPMC_CS);
}
if (!request_mem_region(csa_phy, BLKSZ_4K, "AST_OMAP_HAL")) {
err = -EBUSY;
cy_as_hal_print_message(KERN_ERR "error MEM region "
"request for phy_addr:%x failed\n",
csa_phy);
goto out_free_cs;
}
gpmc_data_vma = (u32)ioremap_nocache(csa_phy, BLKSZ_4K);
if (!gpmc_data_vma) {
err = -ENOMEM;
cy_as_hal_print_message(KERN_ERR "error- ioremap()"
"for phy_addr:%x failed", csa_phy);
goto out_release_mem_region;
}
cy_as_hal_print_message(KERN_INFO "ioremap(%x) returned vma=%x\n",
csa_phy, gpmc_data_vma);
gpmc_cs_write_reg(AST_GPMC_CS, GPMC_CS_CONFIG1,
(GPMC_CONFIG1_DEVICETYPE(2) |
GPMC_CONFIG1_WAIT_PIN_SEL(2)));
memset(&timings, 0, sizeof(timings));
timings.cs_on = WB_GPMC_CS_t_o_n;
timings.cs_wr_off = WB_GPMC_BUSCYC_t;
timings.cs_rd_off = WB_GPMC_BUSCYC_t;
timings.adv_on = WB_GPMC_ADV_t_o_n;
timings.adv_rd_off = WB_GPMC_BUSCYC_t;
timings.adv_wr_off = WB_GPMC_BUSCYC_t;
timings.oe_on = WB_GPMC_OE_t_o_n;
timings.oe_off = WB_GPMC_OE_t_o_f_f;
timings.access = WB_GPMC_RD_t_a_c_c;
timings.rd_cycle = WB_GPMC_BUSCYC_t;
timings.we_on = WB_GPMC_WE_t_o_n;
timings.we_off = WB_GPMC_WE_t_o_f_f;
timings.wr_access = WB_GPMC_WR_t_a_c_c;
timings.wr_cycle = WB_GPMC_BUSCYC_t;
timings.page_burst_access = WB_GPMC_BUSCYC_t;
timings.wr_data_mux_bus = WB_GPMC_BUSCYC_t;
gpmc_cs_set_timings(AST_GPMC_CS, &timings);
cy_as_hal_print_omap_regs("GPMC_CONFIG", 1,
GPMC_VMA(GPMC_CFG_REG(1, AST_GPMC_CS)), 7);
tmp32 = gpmc_cs_read_reg(AST_GPMC_CS, GPMC_CS_CONFIG7) &
~GPMC_CONFIG7_CSVALID;
gpmc_cs_write_reg(AST_GPMC_CS, GPMC_CS_CONFIG7, tmp32);
gpmc_cs_write_reg(AST_GPMC_CS, GPMC_CS_CONFIG7,
(AS_CS_MASK | AS_CS_BADDR));
gpmc_cs_write_reg(AST_GPMC_CS, GPMC_CS_CONFIG1,
(GPMC_CONFIG1_DEVICETYPE(2) |
GPMC_CONFIG1_WAIT_PIN_SEL(2)));
gpmc_cs_write_reg(AST_GPMC_CS, GPMC_CS_CONFIG7,
(tmp32 | GPMC_CONFIG7_CSVALID));
tmp32 = IORD32(GPMC_VMA(GPMC_CONFIG_REG));
tmp32 = tmp32 | NAND_FORCE_POSTED_WRITE_B | 0x40;
IOWR32(GPMC_VMA(GPMC_CONFIG_REG), tmp32);
tmp32 = IORD32(GPMC_VMA(GPMC_CONFIG_REG));
cy_as_hal_print_message("GPMC_CONFIG_REG=0x%x\n", tmp32);
return 0;
out_release_mem_region:
release_mem_region(csa_phy, BLKSZ_4K);
out_free_cs:
gpmc_cs_free(AST_GPMC_CS);
return err;
}
static irqreturn_t cy_astoria_int_handler(int irq,
void *dev_id, struct pt_regs *regs)
{
cy_as_omap_dev_kernel *dev_p;
uint16_t read_val = 0;
uint16_t mask_val = 0;
uint16_t drq_loop_cnt = 0;
uint8_t irq_pin;
const uint16_t sentinel = (CY_AS_MEM_P0_INTR_REG_MCUINT |
CY_AS_MEM_P0_INTR_REG_MBINT |
CY_AS_MEM_P0_INTR_REG_PMINT |
CY_AS_MEM_P0_INTR_REG_PLLLOCKINT);
irq_pin = __gpio_get_value(AST_INT);
intr_sequence_num++;
dev_p = dev_id;
read_val = cy_as_hal_read_register((cy_as_hal_device_tag)dev_p,
CY_AS_MEM_P0_INTR_REG);
mask_val = cy_as_hal_read_register((cy_as_hal_device_tag)dev_p,
CY_AS_MEM_P0_INT_MASK_REG);
DBGPRN("<1>HAL__intr__enter:_seq:%d, P0_INTR_REG:%x\n",
intr_sequence_num, read_val);
cy_as_hal_write_register((cy_as_hal_device_tag)dev_p,
CY_AS_MEM_P0_INT_MASK_REG, 0x0000);
if (read_val & CY_AS_MEM_P0_INTR_REG_DRQINT) {
do {
drq_loop_cnt++;
cy_handle_d_r_q_interrupt(dev_p);
if (drq_loop_cnt >= MAX_DRQ_LOOPS_IN_ISR)
break;
} while (cy_as_hal_read_register((cy_as_hal_device_tag)dev_p,
CY_AS_MEM_P0_INTR_REG) &
CY_AS_MEM_P0_INTR_REG_DRQINT);
}
if (read_val & sentinel)
cy_as_intr_service_interrupt((cy_as_hal_device_tag)dev_p);
DBGPRN("<1>_hal:_intr__exit seq:%d, mask=%4.4x,"
"int_pin:%d DRQ_jobs:%d\n",
intr_sequence_num,
mask_val,
irq_pin,
drq_loop_cnt);
cy_as_hal_write_register((cy_as_hal_device_tag)dev_p,
CY_AS_MEM_P0_INT_MASK_REG, mask_val);
return IRQ_HANDLED;
}
static int cy_as_hal_configure_interrupts(void *dev_p)
{
int result;
int irq_pin = AST_INT;
irq_set_irq_type(OMAP_GPIO_IRQ(irq_pin), IRQ_TYPE_LEVEL_LOW);
result = request_irq(OMAP_GPIO_IRQ(irq_pin),
(irq_handler_t)cy_astoria_int_handler,
IRQF_SHARED, "AST_INT#", dev_p);
if (result == 0) {
cy_as_hal_print_message(KERN_INFO"AST_INT omap_pin:"
"%d assigned IRQ #%d IRQEN1=%d\n",
irq_pin,
OMAP_GPIO_IRQ(irq_pin),
OMAP_GPIO_BIT(AST_INT, GPIO_IRQENABLE1)
);
} else {
cy_as_hal_print_message("cyasomaphal: interrupt "
"failed to register\n");
gpio_free(irq_pin);
cy_as_hal_print_message(KERN_WARNING
"ASTORIA: can't get assigned IRQ"
"%i for INT#\n", OMAP_GPIO_IRQ(irq_pin));
}
return result;
}
static void cy_as_hal_init_user_pads(user_pad_cfg_t *pad_cfg_tab)
{
u32 in_level = 0;
u16 tmp16, mux_val;
while (pad_cfg_tab->name != NULL) {
if (gpio_request(pad_cfg_tab->pin_num, NULL) == 0) {
pad_cfg_tab->valid = 1;
mux_val = omap_cfg_reg_L(pad_cfg_tab->mux_func);
__gpio_set_value(pad_cfg_tab->pin_num,
pad_cfg_tab->drv);
if (pad_cfg_tab->dir)
gpio_direction_input(pad_cfg_tab->pin_num);
else
gpio_direction_output(pad_cfg_tab->pin_num,
pad_cfg_tab->drv);
in_level = __gpio_get_value(pad_cfg_tab->pin_num);
cy_as_hal_print_message(KERN_INFO "configured %s to "
"OMAP pad_%d, DIR=%d "
"DOUT=%d, DIN=%d\n",
pad_cfg_tab->name,
pad_cfg_tab->pin_num,
pad_cfg_tab->dir,
pad_cfg_tab->drv,
in_level
);
} else {
cy_as_hal_print_message(KERN_INFO "couldn't cfg pin %d"
"for signal %s, its already taken\n",
pad_cfg_tab->pin_num,
pad_cfg_tab->name);
}
tmp16 = *(u16 *)PADCFG_VMA
(omap_mux_pin_cfg[pad_cfg_tab->mux_func].offset);
cy_as_hal_print_message(KERN_INFO "GPIO_%d(PAD_CFG=%x,OE=%d"
"DOUT=%d, DIN=%d IRQEN=%d)\n\n",
pad_cfg_tab->pin_num, tmp16,
OMAP_GPIO_BIT(pad_cfg_tab->pin_num, GPIO_OE),
OMAP_GPIO_BIT(pad_cfg_tab->pin_num, GPIO_DATA_OUT),
OMAP_GPIO_BIT(pad_cfg_tab->pin_num, GPIO_DATA_IN),
OMAP_GPIO_BIT(pad_cfg_tab->pin_num, GPIO_IRQENABLE1)
);
pad_cfg_tab++;
}
cy_as_hal_print_message(KERN_INFO"pads configured\n");
}
static void cy_as_hal_release_user_pads(user_pad_cfg_t *pad_cfg_tab)
{
while (pad_cfg_tab->name != NULL) {
if (pad_cfg_tab->valid) {
gpio_free(pad_cfg_tab->pin_num);
pad_cfg_tab->valid = 0;
cy_as_hal_print_message(KERN_INFO "GPIO_%d "
"released from %s\n",
pad_cfg_tab->pin_num,
pad_cfg_tab->name);
} else {
cy_as_hal_print_message(KERN_INFO "no release "
"for %s, GPIO_%d, wasn't acquired\n",
pad_cfg_tab->name,
pad_cfg_tab->pin_num);
}
pad_cfg_tab++;
}
}
void cy_as_hal_config_c_s_mux(void)
{
omap_cfg_reg_L(T8_OMAP3430_GPMC_n_c_s4);
}
uint32_t cy_as_hal_processor_hw_init(void)
{
int i, err;
cy_as_hal_print_message(KERN_INFO "init OMAP3430 hw...\n");
iomux_vma = (u32)ioremap_nocache(
(u32)CTLPADCONF_BASE_ADDR, CTLPADCONF_SIZE);
cy_as_hal_print_message(KERN_INFO "PADCONF_VMA=%x val=%x\n",
iomux_vma, IORD32(iomux_vma));
for (i = 0; i < 6; i++) {
gpio_vma_tab[i].virt_addr = (u32)ioremap_nocache(
gpio_vma_tab[i].phy_addr,
gpio_vma_tab[i].size);
cy_as_hal_print_message(KERN_INFO "%s virt_addr=%x\n",
gpio_vma_tab[i].name,
(u32)gpio_vma_tab[i].virt_addr);
}
gpio_free(AST_RESET);
gpio_free(AST_CS);
cy_as_hal_init_user_pads(user_pad_cfg);
err = cy_as_hal_gpmc_init();
if (err < 0)
cy_as_hal_print_message(KERN_INFO"gpmc init failed:%d", err);
cy_as_hal_config_c_s_mux();
return gpmc_data_vma;
}
void cy_as_hal_omap_hardware_deinit(cy_as_omap_dev_kernel *dev_p)
{
if (gpmc_data_vma != 0)
iounmap((void *)gpmc_data_vma);
if (csa_phy != 0)
release_mem_region(csa_phy, BLKSZ_4K);
gpmc_cs_free(AST_GPMC_CS);
free_irq(OMAP_GPIO_IRQ(AST_INT), dev_p);
cy_as_hal_release_user_pads(user_pad_cfg);
}
int stop_o_m_a_p_kernel(const char *pgm, cy_as_hal_device_tag tag)
{
cy_as_omap_dev_kernel *dev_p = (cy_as_omap_dev_kernel *)tag;
if (0 == dev_p)
return 1;
cy_as_hal_print_message("<1>_stopping OMAP34xx HAL layer object\n");
if (dev_p->m_sig != CY_AS_OMAP_KERNEL_HAL_SIG) {
cy_as_hal_print_message("<1>%s: %s: bad HAL tag\n",
pgm, __func__);
return 1;
}
cy_as_hal_write_register((cy_as_hal_device_tag)dev_p,
CY_AS_MEM_P0_INT_MASK_REG, 0x0000);
#if 0
if (dev_p->thread_flag == 0) {
dev_p->thread_flag = 1;
wait_for_completion(&dev_p->thread_complete);
cy_as_hal_print_message("cyasomaphal:"
"done cleaning thread\n");
cy_as_hal_destroy_sleep_channel(&dev_p->thread_sc);
}
#endif
cy_as_hal_omap_hardware_deinit(dev_p);
if (m_omap_list_p == dev_p)
m_omap_list_p = dev_p->m_next_p;
cy_as_hal_free(dev_p);
cy_as_hal_print_message(KERN_INFO"OMAP_kernel_hal stopped\n");
return 0;
}
int omap_start_intr(cy_as_hal_device_tag tag)
{
cy_as_omap_dev_kernel *dev_p = (cy_as_omap_dev_kernel *)tag;
int ret = 0;
const uint16_t mask = CY_AS_MEM_P0_INTR_REG_DRQINT |
CY_AS_MEM_P0_INTR_REG_MBINT;
ret = cy_as_hal_configure_interrupts(dev_p);
cy_as_hal_write_register((cy_as_hal_device_tag)dev_p,
CY_AS_MEM_P0_INT_MASK_REG, mask);
return 1;
}
static inline void nand_cmd_n_addr(u8 cmdb1, u16 col_addr, u32 row_addr)
{
u32 tmpa32 = ((row_addr << 16) | col_addr);
u8 RA2 = (u8)(row_addr >> 16);
if (!pnand_16bit) {
IOWR8(ncmd_reg_vma, cmdb1);
IOWR32(naddr_reg_vma, tmpa32);
IOWR8(naddr_reg_vma, RA2);
} else {
uint8_t CA0, CA1, RA0, RA1;
CA0 = tmpa32 & 0x000000ff;
CA1 = (tmpa32 >> 8) & 0x000000ff;
RA0 = (tmpa32 >> 16) & 0x000000ff;
RA1 = (tmpa32 >> 24) & 0x000000ff;
IOWR8(ncmd_reg_vma, cmdb1);
IOWR8(naddr_reg_vma, CA0);
IOWR8(naddr_reg_vma, CA1);
IOWR8(naddr_reg_vma, RA0);
IOWR8(naddr_reg_vma, RA1);
IOWR8(naddr_reg_vma, RA2);
}
}
inline int wait_rn_b_high(void)
{
u32 w_spins = 0;
return w_spins;
}
static void p_nand_lbd_read(u16 col_addr, u32 row_addr, u16 count, void *buff)
{
uint16_t w32cnt;
uint32_t *ptr32;
uint8_t *ptr8;
uint8_t bytes_in_fifo;
#ifdef PFE_READ_DEBUG
uint32_t loop_limit;
uint16_t bytes_read = 0;
#endif
uint32_t tmp32;
uint32_t pfe_status;
IOWR32(GPMC_VMA(GPMC_PREFETCH_CONTROL), 0x0);
IOWR32(GPMC_VMA(GPMC_PREFETCH_CONFIG1), GPMC_PREFETCH_CONFIG1_VAL);
IOWR32(GPMC_VMA(GPMC_PREFETCH_CONFIG2), count);
#ifdef PFE_READ_DEBUG
tmp32 = IORD32(GPMC_VMA(GPMC_PREFETCH_CONFIG1));
if (tmp32 != GPMC_PREFETCH_CONFIG1_VAL) {
printk(KERN_INFO "<1> prefetch is CONFIG1 read val:%8.8x, != VAL written:%8.8x\n",
tmp32, GPMC_PREFETCH_CONFIG1_VAL);
tmp32 = IORD32(GPMC_VMA(GPMC_PREFETCH_STATUS));
printk(KERN_INFO "<1> GPMC_PREFETCH_STATUS : %8.8x\n", tmp32);
}
tmp32 = IORD32(GPMC_VMA(GPMC_PREFETCH_CONFIG2));
if (tmp32 != (count))
printk(KERN_INFO "<1> GPMC_PREFETCH_CONFIG2 read val:%d, "
"!= VAL written:%d\n", tmp32, count);
#endif
nand_cmd_n_addr(RDPAGE_B1, col_addr, row_addr);
IOWR8(ncmd_reg_vma, RDPAGE_B2);
IOWR32(GPMC_VMA(GPMC_PREFETCH_CONTROL), 0x1);
ptr32 = buff;
while (1) {
do {
pfe_status = IORD32(GPMC_VMA(GPMC_PREFETCH_STATUS));
bytes_in_fifo = (pfe_status >> 24) & 0x7f;
} while (bytes_in_fifo == 0);
w32cnt = bytes_in_fifo >> 2;
#if 0
printk(KERN_ERR "<1> got PF_STATUS:%8.8x FIFO_PTR:%d, COUNTVAL:%d, w32cnt:%d\n",
pfe_status, bytes_in_fifo,
(pfe_status & 0x3fff), w32cnt);
#endif
while (w32cnt--)
*ptr32++ = IORD32(gpmc_data_vma);
if ((pfe_status & 0x3fff) == 0) {
bytes_in_fifo = (IORD32(
GPMC_VMA(GPMC_PREFETCH_STATUS)) >> 24) & 0x7f;
ptr8 = ptr32;
switch (bytes_in_fifo) {
case 0:
break;
case 1:
*ptr8 = IORD8(gpmc_data_vma);
break;
case 2:
*(uint16_t *)ptr8 = IORD16(gpmc_data_vma);
break;
case 3:
*(uint16_t *)ptr8 = IORD16(gpmc_data_vma);
ptr8 += 2;
*ptr8 = IORD8(gpmc_data_vma);
break;
case 4:
*ptr32 = IORD32(gpmc_data_vma);
break;
default:
printk(KERN_ERR"<1>_error: PFE FIFO bytes leftover is not read:%d\n",
bytes_in_fifo);
break;
}
break;
}
}
}
static void p_nand_lbd_read(u16 col_addr, u32 row_addr, u16 count, void *buff)
{
uint8_t rd_cnt;
uint32_t *ptr32;
uint8_t *ptr8;
uint16_t reminder;
uint32_t pfe_status;
nand_cmd_n_addr(RDPAGE_B1, col_addr, row_addr);
IOWR8(ncmd_reg_vma, RDPAGE_B2);
IOWR32(GPMC_VMA(GPMC_PREFETCH_CONFIG1), GPMC_PREFETCH_CONFIG1_VAL);
IOWR32(GPMC_VMA(GPMC_PREFETCH_CONFIG2), count);
IOWR32(GPMC_VMA(GPMC_PREFETCH_CONTROL), 0x1);
ptr32 = buff;
do {
pfe_status = IORD32(GPMC_VMA(GPMC_PREFETCH_STATUS));
rd_cnt = pfe_status >> (24+2);
while (rd_cnt--)
*ptr32++ = IORD32(gpmc_data_vma);
} while (pfe_status & 0x3fff);
ptr8 = ptr32;
rd_cnt = (IORD32(GPMC_VMA(GPMC_PREFETCH_STATUS)) >> 24) & 0x7f;
while (rd_cnt--)
*ptr8++ = IORD8(gpmc_data_vma);
}
static void p_nand_lbd_read(u16 col_addr, u32 row_addr, u16 count, void *buff)
{
uint16_t w32cnt;
uint32_t *ptr32;
uint16_t *ptr16;
uint16_t remainder;
DBGPRN("<1> %s(): NO_PFE\n", __func__);
ptr32 = buff;
w32cnt = count >> 2;
remainder = count & 03;
nand_cmd_n_addr(RDPAGE_B1, col_addr, row_addr);
IOWR8(ncmd_reg_vma, RDPAGE_B2);
while (w32cnt--)
*ptr32++ = IORD32(ndata_reg_vma);
ptr16 = (uint16_t *)ptr32;
switch (remainder) {
case 1:
case 2:
*ptr16 = IORD16(ndata_reg_vma);
break;
case 3:
*ptr16++ = IORD16(ndata_reg_vma);
*ptr16 = IORD16(ndata_reg_vma);
break;
default:
break;
}
}
static void p_nand_lbd_write(u16 col_addr, u32 row_addr, u16 count, void *buff)
{
uint16_t w32cnt;
uint16_t remainder;
uint8_t *ptr8;
uint16_t *ptr16;
uint32_t *ptr32;
remainder = count & 03;
w32cnt = count >> 2;
ptr32 = buff;
ptr8 = buff;
nand_cmd_n_addr(PGMPAGE_B1, col_addr, row_addr);
while (w32cnt--)
IOWR32(ndata_reg_vma, *ptr32++);
ptr16 = (uint16_t *)ptr32;
switch (remainder) {
case 1:
case 2:
IOWR16(ndata_reg_vma, *ptr16);
break;
case 3:
IOWR16(ndata_reg_vma, *ptr16++);
IOWR16(ndata_reg_vma, *ptr16);
break;
default:
break;
}
IOWR8(ncmd_reg_vma, PGMPAGE_B2);
}
static inline void ast_p_nand_casdi_write(u8 reg_addr8, u16 data)
{
unsigned long flags;
u16 addr16;
static atomic_t rdreg_usage_cnt = { 0 };
local_irq_save(flags);
if (atomic_read(&rdreg_usage_cnt) != 0) {
cy_as_hal_print_message(KERN_ERR "cy_as_omap_hal:"
"* cy_as_hal_write_register usage:%d\n",
atomic_read(&rdreg_usage_cnt));
}
atomic_inc(&rdreg_usage_cnt);
if (pnand_16bit) {
IOWR8(ncmd_reg_vma, 0x85);
IOWR8(naddr_reg_vma, reg_addr8);
IOWR8(naddr_reg_vma, 0x0c);
IOWR16(ndata_reg_vma, data);
} else {
addr16 = 0x0c00 | reg_addr8;
IOWR8(ncmd_reg_vma, 0x85);
IOWR16(naddr_reg_vma, addr16);
IOWR16(ndata_reg_vma, data);
}
atomic_dec(&rdreg_usage_cnt);
local_irq_restore(flags);
}
static inline u16 ast_p_nand_casdo_read(u8 reg_addr8)
{
u16 data;
u16 addr16;
unsigned long flags;
static atomic_t wrreg_usage_cnt = { 0 };
local_irq_save(flags);
if (atomic_read(&wrreg_usage_cnt) != 0) {
cy_as_hal_print_message(KERN_ERR"cy_as_omap_hal: "
"cy_as_hal_write_register usage:%d\n",
atomic_read(&wrreg_usage_cnt));
}
atomic_inc(&wrreg_usage_cnt);
if (pnand_16bit) {
IOWR8(ncmd_reg_vma, 0x05);
IOWR8(naddr_reg_vma, reg_addr8);
IOWR8(naddr_reg_vma, 0x0c);
IOWR8(ncmd_reg_vma, 0x00E0);
udelay(1);
data = IORD16(ndata_reg_vma);
} else {
addr16 = 0x0c00 | reg_addr8;
IOWR8(ncmd_reg_vma, 0x05);
IOWR16(naddr_reg_vma, addr16);
IOWR8(ncmd_reg_vma, 0xE0);
udelay(1);
data = IORD16(ndata_reg_vma);
}
atomic_dec(&wrreg_usage_cnt);
local_irq_restore(flags);
return data;
}
void cy_as_hal_write_register(
cy_as_hal_device_tag tag,
uint16_t addr, uint16_t data)
{
ast_p_nand_casdi_write((u8)addr, data);
}
uint16_t cy_as_hal_read_register(cy_as_hal_device_tag tag, uint16_t addr)
{
uint16_t data = 0;
data = ast_p_nand_casdo_read((u8)addr);
return data;
}
static inline bool prep_for_next_xfer(cy_as_hal_device_tag tag, uint8_t ep)
{
if (!end_points[ep].sg_list_enabled) {
if (end_points[ep].req_xfer_cnt >= end_points[ep].req_length) {
DBGPRN("<1> %s():RQ sz:%d non-_sg EP:%d completed\n",
__func__, end_points[ep].req_length, ep);
return false;
}
if ((end_points[ep].req_length - end_points[ep].req_xfer_cnt)
>= HAL_DMA_PKT_SZ) {
end_points[ep].dma_xfer_sz = HAL_DMA_PKT_SZ;
} else {
end_points[ep].dma_xfer_sz = end_points[ep].req_length -
end_points[ep].req_xfer_cnt;
}
return true;
}
if (end_points[ep].seg_xfer_cnt == end_points[ep].sg_p->length) {
if (sg_is_last(end_points[ep].sg_p)) {
DBGPRN("<1> %s: EP:%d completed,"
"%d bytes xfered\n",
__func__,
ep,
end_points[ep].req_xfer_cnt
);
return false;
} else {
end_points[ep].seg_xfer_cnt = 0;
end_points[ep].sg_p = sg_next(end_points[ep].sg_p);
end_points[ep].data_p = sg_virt(end_points[ep].sg_p);
DBGPRN("<1> %s new SG:_va:%p\n\n",
__func__, end_points[ep].data_p);
}
}
end_points[ep].dma_xfer_sz = HAL_DMA_PKT_SZ;
return true;
}
static void cy_service_e_p_dma_read_request(
cy_as_omap_dev_kernel *dev_p, uint8_t ep)
{
cy_as_hal_device_tag tag = (cy_as_hal_device_tag)dev_p;
uint16_t v, size;
void *dptr;
uint16_t col_addr = 0x0000;
uint32_t row_addr = CYAS_DEV_CALC_EP_ADDR(ep);
uint16_t ep_dma_reg = CY_AS_MEM_P0_EP2_DMA_REG + ep - 2;
v = cy_as_hal_read_register(tag, ep_dma_reg);
size = v & CY_AS_MEM_P0_E_pn_DMA_REG_COUNT_MASK;
dptr = end_points[ep].data_p;
DBGPRN("<1>HAL:_svc_dma_read on EP_%d sz:%d, intr_seq:%d, dptr:%p\n",
ep,
size,
intr_sequence_num,
dptr
);
cy_as_hal_assert(size != 0);
if (size) {
p_nand_lbd_read(col_addr, row_addr, size, dptr);
}
cy_as_hal_write_register(tag, ep_dma_reg, 0);
end_points[ep].seg_xfer_cnt += size;
end_points[ep].req_xfer_cnt += size;
end_points[ep].data_p += size;
if (prep_for_next_xfer(tag, ep)) {
v = end_points[ep].dma_xfer_sz |
CY_AS_MEM_P0_E_pn_DMA_REG_DMAVAL;
cy_as_hal_write_register(tag, ep_dma_reg, v);
} else {
end_points[ep].pending = cy_false;
end_points[ep].type = cy_as_hal_none;
end_points[ep].buffer_valid = cy_false;
if (callback) {
DBGPRN("<1>trigg rd_dma completion cb: xfer_sz:%d\n",
end_points[ep].req_xfer_cnt);
callback(tag, ep,
end_points[ep].req_xfer_cnt,
CY_AS_ERROR_SUCCESS);
}
}
}
static void cy_service_e_p_dma_write_request(
cy_as_omap_dev_kernel *dev_p, uint8_t ep)
{
uint16_t addr;
uint16_t v = 0;
uint32_t size;
uint16_t col_addr = 0x0000;
uint32_t row_addr = CYAS_DEV_CALC_EP_ADDR(ep);
void *dptr;
cy_as_hal_device_tag tag = (cy_as_hal_device_tag)dev_p;
size = end_points[ep].dma_xfer_sz;
dptr = end_points[ep].data_p;
if (size)
p_nand_lbd_write(col_addr, row_addr, size, dptr);
end_points[ep].seg_xfer_cnt += size;
end_points[ep].req_xfer_cnt += size;
end_points[ep].data_p += size;
addr = CY_AS_MEM_P0_EP2_DMA_REG + ep - 2;
cy_as_hal_write_register(tag, addr, size);
if (prep_for_next_xfer(tag, ep)) {
v = end_points[ep].dma_xfer_sz |
CY_AS_MEM_P0_E_pn_DMA_REG_DMAVAL;
cy_as_hal_write_register(tag, addr, v);
} else {
end_points[ep].pending = cy_false;
end_points[ep].type = cy_as_hal_none;
end_points[ep].buffer_valid = cy_false;
if (callback) {
callback(tag, ep,
end_points[ep].req_xfer_cnt,
CY_AS_ERROR_SUCCESS);
}
}
}
static void cy_handle_d_r_q_interrupt(cy_as_omap_dev_kernel *dev_p)
{
uint16_t v;
static uint8_t service_ep = 2;
v = cy_as_hal_read_register((cy_as_hal_device_tag)dev_p,
CY_AS_MEM_P0_DRQ);
if (v == 0) {
#ifndef WESTBRIDGE_NDEBUG
cy_as_hal_print_message("stray DRQ interrupt detected\n");
#endif
return;
}
while ((v & (1 << service_ep)) == 0) {
if (service_ep == 15)
service_ep = 2;
else
service_ep++;
}
if (end_points[service_ep].type == cy_as_hal_write) {
cy_service_e_p_dma_write_request(dev_p, service_ep);
} else if (end_points[service_ep].type == cy_as_hal_read) {
cy_service_e_p_dma_read_request(dev_p, service_ep);
}
#ifndef WESTBRIDGE_NDEBUG
else
cy_as_hal_print_message("cyashalomap:interrupt,"
" w/o pending DMA job,"
"-check DRQ_MASK logic\n");
#endif
if (end_points[service_ep].type == cy_as_hal_none) {
if (service_ep == 15)
service_ep = 2;
else
service_ep++;
}
}
void cy_as_hal_dma_cancel_request(cy_as_hal_device_tag tag, uint8_t ep)
{
DBGPRN("cy_as_hal_dma_cancel_request on ep:%d", ep);
if (end_points[ep].pending)
cy_as_hal_write_register(tag,
CY_AS_MEM_P0_EP2_DMA_REG + ep - 2, 0);
end_points[ep].buffer_valid = cy_false;
end_points[ep].type = cy_as_hal_none;
}
void cy_as_hal_set_ep_dma_mode(uint8_t ep, bool sg_xfer_enabled)
{
end_points[ep].sg_list_enabled = sg_xfer_enabled;
DBGPRN("<1> EP:%d sg_list assisted DMA mode set to = %d\n",
ep, end_points[ep].sg_list_enabled);
}
void cy_as_hal_dma_setup_write(cy_as_hal_device_tag tag,
uint8_t ep, void *buf,
uint32_t size, uint16_t maxsize)
{
uint32_t addr = 0;
uint16_t v = 0;
cy_as_hal_assert(ep != 0 && ep != 1);
cy_as_hal_assert(end_points[ep].buffer_valid == cy_false);
end_points[ep].buffer_valid = cy_true;
end_points[ep].type = cy_as_hal_write;
end_points[ep].pending = cy_true;
end_points[ep].req_length = size;
if (size >= maxsize) {
end_points[ep].dma_xfer_sz = maxsize;
} else {
end_points[ep].dma_xfer_sz = size;
}
if (end_points[ep].sg_list_enabled) {
end_points[ep].sg_p = buf;
end_points[ep].data_p = sg_virt(end_points[ep].sg_p);
end_points[ep].seg_xfer_cnt = 0;
end_points[ep].req_xfer_cnt = 0;
#ifdef DBGPRN_DMA_SETUP_WR
DBGPRN("cyasomaphal:%s: EP:%d, buf:%p, buf_va:%p,"
"req_sz:%d, maxsz:%d\n",
__func__,
ep,
buf,
end_points[ep].data_p,
size,
maxsize);
#endif
} else {
#ifdef DBGPRN_DMA_SETUP_WR
DBGPRN("<1>%s non storage or sz < 512:"
"EP:%d, sz:%d\n", __func__, ep, size);
#endif
end_points[ep].sg_p = NULL;
end_points[ep].data_p = buf;
end_points[ep].req_xfer_cnt = 0;
}
v = (end_points[ep].dma_xfer_sz & CY_AS_MEM_P0_E_pn_DMA_REG_COUNT_MASK)
| CY_AS_MEM_P0_E_pn_DMA_REG_DMAVAL;
addr = CY_AS_MEM_P0_EP2_DMA_REG + ep - 2;
cy_as_hal_write_register(tag, addr, v);
}
void cy_as_hal_dma_setup_read(cy_as_hal_device_tag tag,
uint8_t ep, void *buf,
uint32_t size, uint16_t maxsize)
{
uint32_t addr;
uint16_t v;
cy_as_hal_assert(ep != 0 && ep != 1);
cy_as_hal_assert(end_points[ep].buffer_valid == cy_false);
end_points[ep].buffer_valid = cy_true;
end_points[ep].type = cy_as_hal_read;
end_points[ep].pending = cy_true;
end_points[ep].req_xfer_cnt = 0;
end_points[ep].req_length = size;
if (size >= maxsize) {
end_points[ep].dma_xfer_sz = maxsize;
} else {
end_points[ep].dma_xfer_sz = size;
}
addr = CY_AS_MEM_P0_EP2_DMA_REG + ep - 2;
if (end_points[ep].sg_list_enabled) {
end_points[ep].seg_xfer_cnt = 0;
end_points[ep].sg_p = buf;
end_points[ep].data_p = sg_virt(end_points[ep].sg_p);
#ifdef DBGPRN_DMA_SETUP_RD
DBGPRN("cyasomaphal:DMA_setup_read sg_list EP:%d, "
"buf:%p, buf_va:%p, req_sz:%d, maxsz:%d\n",
ep,
buf,
end_points[ep].data_p,
size,
maxsize);
#endif
v = (end_points[ep].dma_xfer_sz &
CY_AS_MEM_P0_E_pn_DMA_REG_COUNT_MASK) |
CY_AS_MEM_P0_E_pn_DMA_REG_DMAVAL;
cy_as_hal_write_register(tag, addr, v);
} else {
#ifdef DBGPRN_DMA_SETUP_RD
DBGPRN("%s:non-sg_list EP:%d,"
"RQ_sz:%d, maxsz:%d\n",
__func__, ep, size, maxsize);
#endif
end_points[ep].sg_p = NULL;
end_points[ep].data_p = buf;
if (is_storage_e_p(ep)) {
v = (end_points[ep].dma_xfer_sz &
CY_AS_MEM_P0_E_pn_DMA_REG_COUNT_MASK) |
CY_AS_MEM_P0_E_pn_DMA_REG_DMAVAL;
cy_as_hal_write_register(tag, addr, v);
}
}
}
void cy_as_hal_dma_register_callback(cy_as_hal_device_tag tag,
cy_as_hal_dma_complete_callback cb)
{
DBGPRN("<1>\n%s: WB API has registered a dma_complete callback:%x\n",
__func__, (uint32_t)cb);
callback = cb;
}
uint32_t cy_as_hal_dma_max_request_size(cy_as_hal_device_tag tag,
cy_as_end_point_number_t ep)
{
if ((ep == CYASSTORAGE_READ_EP_NUM) ||
(ep == CYASSTORAGE_WRITE_EP_NUM)) {
return CYASSTORAGE_MAX_XFER_SIZE;
} else {
return CY_AS_DMA_MAX_SIZE_HW_SIZE;
}
}
cy_bool cy_as_hal_set_wakeup_pin(cy_as_hal_device_tag tag, cy_bool state)
{
return cy_false;
}
void cy_as_hal_pll_lock_loss_handler(cy_as_hal_device_tag tag)
{
cy_as_hal_print_message("error: astoria PLL lock is lost\n");
cy_as_hal_print_message("please check the input voltage levels");
cy_as_hal_print_message("and clock, and restart the system\n");
}
void *cy_as_hal_alloc(uint32_t cnt)
{
return kmalloc(cnt, GFP_ATOMIC);
}
void cy_as_hal_free(void *mem_p)
{
kfree(mem_p);
}
void *cy_as_hal_c_b_alloc(uint32_t cnt)
{
return kmalloc(cnt, GFP_ATOMIC);
}
void cy_as_hal_mem_set(void *ptr, uint8_t value, uint32_t cnt)
{
memset(ptr, value, cnt);
}
cy_bool cy_as_hal_create_sleep_channel(cy_as_hal_sleep_channel *channel)
{
init_waitqueue_head(&channel->wq);
return cy_true;
}
cy_bool cy_as_hal_destroy_sleep_channel(cy_as_hal_sleep_channel *channel)
{
return cy_true;
}
cy_bool cy_as_hal_sleep_on(cy_as_hal_sleep_channel *channel, uint32_t ms)
{
wait_event_interruptible_timeout(channel->wq, 0, ((ms * HZ)/1000));
return cy_true;
}
cy_bool cy_as_hal_wake(cy_as_hal_sleep_channel *channel)
{
wake_up_interruptible_all(&channel->wq);
return cy_true;
}
uint32_t cy_as_hal_disable_interrupts()
{
if (0 == intr__enable)
;
intr__enable++;
return 0;
}
void cy_as_hal_enable_interrupts(uint32_t val)
{
intr__enable--;
if (0 == intr__enable)
;
}
void cy_as_hal_sleep150(void)
{
uint32_t i, j;
j = 0;
for (i = 0; i < 1000; i++)
j += (~i);
}
void cy_as_hal_sleep(uint32_t ms)
{
cy_as_hal_sleep_channel channel;
cy_as_hal_create_sleep_channel(&channel);
cy_as_hal_sleep_on(&channel, ms);
cy_as_hal_destroy_sleep_channel(&channel);
}
cy_bool cy_as_hal_is_polling()
{
return cy_false;
}
void cy_as_hal_c_b_free(void *ptr)
{
cy_as_hal_free(ptr);
}
void cy_as_hal_init_dev_registers(cy_as_hal_device_tag tag,
cy_bool is_standby_wakeup)
{
(void) tag;
(void) is_standby_wakeup;
}
void cy_as_hal_read_regs_before_standby(cy_as_hal_device_tag tag)
{
(void) tag;
}
cy_bool cy_as_hal_sync_device_clocks(cy_as_hal_device_tag tag)
{
return true;
}
int start_o_m_a_p_kernel(const char *pgm,
cy_as_hal_device_tag *tag, cy_bool debug)
{
cy_as_omap_dev_kernel *dev_p;
int i;
u16 data16[4];
u8 pncfg_reg;
(void)debug;
DBGPRN(KERN_INFO"starting OMAP34xx HAL...\n");
for (i = 0; i < sizeof(end_points)/sizeof(end_points[0]); i++) {
end_points[i].data_p = 0;
end_points[i].pending = cy_false;
end_points[i].size = 0;
end_points[i].type = cy_as_hal_none;
end_points[i].sg_list_enabled = cy_false;
}
dev_p = (cy_as_omap_dev_kernel *)cy_as_hal_alloc(
sizeof(cy_as_omap_dev_kernel));
if (dev_p == 0) {
cy_as_hal_print_message("out of memory allocating OMAP"
"device structure\n");
return 0;
}
dev_p->m_sig = CY_AS_OMAP_KERNEL_HAL_SIG;
dev_p->m_addr_base = (void *)cy_as_hal_processor_hw_init();
__gpio_set_value(AST_WAKEUP, 1);
DBGPRN(KERN_INFO"-_-_pulse -> westbridge RST pin\n");
__gpio_set_value(AST_RESET, 0);
mdelay(1);
__gpio_set_value(AST_RESET, 1);
mdelay(50);
pncfg_reg = ast_p_nand_casdo_read(CY_AS_MEM_PNAND_CFG);
#ifdef PNAND_16BIT_MODE
ast_p_nand_casdi_write(CY_AS_MEM_PNAND_CFG, 0x0001);
cy_as_hal_gpmc_enable_16bit_bus(cy_true);
#else
ast_p_nand_casdi_write(CY_AS_MEM_PNAND_CFG, 0x0000);
#endif
data16[0] = ast_p_nand_casdo_read(CY_AS_MEM_CM_WB_CFG_ID);
data16[1] = ast_p_nand_casdo_read(CY_AS_MEM_PNAND_CFG);
if (data16[0] != 0xA200) {
printk(KERN_ERR "ERROR: astoria device is not found, CY_AS_MEM_CM_WB_CFG_ID ");
printk(KERN_ERR "read returned:%4.4X: CY_AS_MEM_PNAND_CFG:%4.4x !\n",
data16[0], data16[0]);
goto bus_acc_error;
}
cy_as_hal_print_message(KERN_INFO" register access CASDO test:"
"\n CY_AS_MEM_CM_WB_CFG_ID:%4.4x\n"
"PNAND_CFG after RST:%4.4x\n "
"CY_AS_MEM_PNAND_CFG"
"after cfg_wr:%4.4x\n\n",
data16[0], pncfg_reg, data16[1]);
dev_p->thread_flag = 1;
spin_lock_init(&int_lock);
dev_p->m_next_p = m_omap_list_p;
m_omap_list_p = dev_p;
*tag = dev_p;
cy_as_hal_configure_interrupts((void *)dev_p);
cy_as_hal_print_message(KERN_INFO"OMAP3430__hal started tag:%p"
", kernel HZ:%d\n", dev_p, HZ);
cy_as_hal_set_ep_dma_mode(4, true);
cy_as_hal_set_ep_dma_mode(8, true);
return 1;
bus_acc_error:
cy_as_hal_omap_hardware_deinit(dev_p);
cy_as_hal_free(dev_p);
return 0;
}
void my_o_m_a_p_kernel_hal_dummy_function(void)
{
}
