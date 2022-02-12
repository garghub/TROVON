static unsigned long osc_get_rate(struct clk *clk)
{
return at32_board_osc_rates[clk->index];
}
static unsigned long pll_get_rate(struct clk *clk, unsigned long control)
{
unsigned long div, mul, rate;
div = PM_BFEXT(PLLDIV, control) + 1;
mul = PM_BFEXT(PLLMUL, control) + 1;
rate = clk->parent->get_rate(clk->parent);
rate = (rate + div / 2) / div;
rate *= mul;
return rate;
}
static long pll_set_rate(struct clk *clk, unsigned long rate,
u32 *pll_ctrl)
{
unsigned long mul;
unsigned long mul_best_fit = 0;
unsigned long div;
unsigned long div_min;
unsigned long div_max;
unsigned long div_best_fit = 0;
unsigned long base;
unsigned long pll_in;
unsigned long actual = 0;
unsigned long rate_error;
unsigned long rate_error_prev = ~0UL;
u32 ctrl;
if (rate < 80000000UL || rate > 200000000UL)
return -EINVAL;
ctrl = PM_BF(PLLOPT, 4);
base = clk->parent->get_rate(clk->parent);
div_min = DIV_ROUND_UP(base, 32000000UL);
div_max = base / 6000000UL;
if (div_max < div_min)
return -EINVAL;
for (div = div_min; div <= div_max; div++) {
pll_in = (base + div / 2) / div;
mul = (rate + pll_in / 2) / pll_in;
if (mul == 0)
continue;
actual = pll_in * mul;
rate_error = abs(actual - rate);
if (rate_error < rate_error_prev) {
mul_best_fit = mul;
div_best_fit = div;
rate_error_prev = rate_error;
}
if (rate_error == 0)
break;
}
if (div_best_fit == 0)
return -EINVAL;
ctrl |= PM_BF(PLLMUL, mul_best_fit - 1);
ctrl |= PM_BF(PLLDIV, div_best_fit - 1);
ctrl |= PM_BF(PLLCOUNT, 16);
if (clk->parent == &osc1)
ctrl |= PM_BIT(PLLOSC);
*pll_ctrl = ctrl;
return actual;
}
static unsigned long pll0_get_rate(struct clk *clk)
{
u32 control;
control = pm_readl(PLL0);
return pll_get_rate(clk, control);
}
static void pll1_mode(struct clk *clk, int enabled)
{
unsigned long timeout;
u32 status;
u32 ctrl;
ctrl = pm_readl(PLL1);
if (enabled) {
if (!PM_BFEXT(PLLMUL, ctrl) && !PM_BFEXT(PLLDIV, ctrl)) {
pr_debug("clk %s: failed to enable, rate not set\n",
clk->name);
return;
}
ctrl |= PM_BIT(PLLEN);
pm_writel(PLL1, ctrl);
for (timeout = 10000; timeout; timeout--) {
status = pm_readl(ISR);
if (status & PM_BIT(LOCK1))
break;
udelay(10);
}
if (!(status & PM_BIT(LOCK1)))
printk(KERN_ERR "clk %s: timeout waiting for lock\n",
clk->name);
} else {
ctrl &= ~PM_BIT(PLLEN);
pm_writel(PLL1, ctrl);
}
}
static unsigned long pll1_get_rate(struct clk *clk)
{
u32 control;
control = pm_readl(PLL1);
return pll_get_rate(clk, control);
}
static long pll1_set_rate(struct clk *clk, unsigned long rate, int apply)
{
u32 ctrl = 0;
unsigned long actual_rate;
actual_rate = pll_set_rate(clk, rate, &ctrl);
if (apply) {
if (actual_rate != rate)
return -EINVAL;
if (clk->users > 0)
return -EBUSY;
pr_debug(KERN_INFO "clk %s: new rate %lu (actual rate %lu)\n",
clk->name, rate, actual_rate);
pm_writel(PLL1, ctrl);
}
return actual_rate;
}
static int pll1_set_parent(struct clk *clk, struct clk *parent)
{
u32 ctrl;
if (clk->users > 0)
return -EBUSY;
ctrl = pm_readl(PLL1);
WARN_ON(ctrl & PM_BIT(PLLEN));
if (parent == &osc0)
ctrl &= ~PM_BIT(PLLOSC);
else if (parent == &osc1)
ctrl |= PM_BIT(PLLOSC);
else
return -EINVAL;
pm_writel(PLL1, ctrl);
clk->parent = parent;
return 0;
}
static unsigned long bus_clk_get_rate(struct clk *clk, unsigned int shift)
{
return main_clock->get_rate(main_clock) >> shift;
}
static void cpu_clk_mode(struct clk *clk, int enabled)
{
unsigned long flags;
u32 mask;
spin_lock_irqsave(&pm_lock, flags);
mask = pm_readl(CPU_MASK);
if (enabled)
mask |= 1 << clk->index;
else
mask &= ~(1 << clk->index);
pm_writel(CPU_MASK, mask);
spin_unlock_irqrestore(&pm_lock, flags);
}
static unsigned long cpu_clk_get_rate(struct clk *clk)
{
unsigned long cksel, shift = 0;
cksel = pm_readl(CKSEL);
if (cksel & PM_BIT(CPUDIV))
shift = PM_BFEXT(CPUSEL, cksel) + 1;
return bus_clk_get_rate(clk, shift);
}
static long cpu_clk_set_rate(struct clk *clk, unsigned long rate, int apply)
{
u32 control;
unsigned long parent_rate, child_div, actual_rate, div;
parent_rate = clk->parent->get_rate(clk->parent);
control = pm_readl(CKSEL);
if (control & PM_BIT(HSBDIV))
child_div = 1 << (PM_BFEXT(HSBSEL, control) + 1);
else
child_div = 1;
if (rate > 3 * (parent_rate / 4) || child_div == 1) {
actual_rate = parent_rate;
control &= ~PM_BIT(CPUDIV);
} else {
unsigned int cpusel;
div = (parent_rate + rate / 2) / rate;
if (div > child_div)
div = child_div;
cpusel = (div > 1) ? (fls(div) - 2) : 0;
control = PM_BIT(CPUDIV) | PM_BFINS(CPUSEL, cpusel, control);
actual_rate = parent_rate / (1 << (cpusel + 1));
}
pr_debug("clk %s: new rate %lu (actual rate %lu)\n",
clk->name, rate, actual_rate);
if (apply)
pm_writel(CKSEL, control);
return actual_rate;
}
static void hsb_clk_mode(struct clk *clk, int enabled)
{
unsigned long flags;
u32 mask;
spin_lock_irqsave(&pm_lock, flags);
mask = pm_readl(HSB_MASK);
if (enabled)
mask |= 1 << clk->index;
else
mask &= ~(1 << clk->index);
pm_writel(HSB_MASK, mask);
spin_unlock_irqrestore(&pm_lock, flags);
}
static unsigned long hsb_clk_get_rate(struct clk *clk)
{
unsigned long cksel, shift = 0;
cksel = pm_readl(CKSEL);
if (cksel & PM_BIT(HSBDIV))
shift = PM_BFEXT(HSBSEL, cksel) + 1;
return bus_clk_get_rate(clk, shift);
}
void pba_clk_mode(struct clk *clk, int enabled)
{
unsigned long flags;
u32 mask;
spin_lock_irqsave(&pm_lock, flags);
mask = pm_readl(PBA_MASK);
if (enabled)
mask |= 1 << clk->index;
else
mask &= ~(1 << clk->index);
pm_writel(PBA_MASK, mask);
spin_unlock_irqrestore(&pm_lock, flags);
}
unsigned long pba_clk_get_rate(struct clk *clk)
{
unsigned long cksel, shift = 0;
cksel = pm_readl(CKSEL);
if (cksel & PM_BIT(PBADIV))
shift = PM_BFEXT(PBASEL, cksel) + 1;
return bus_clk_get_rate(clk, shift);
}
static void pbb_clk_mode(struct clk *clk, int enabled)
{
unsigned long flags;
u32 mask;
spin_lock_irqsave(&pm_lock, flags);
mask = pm_readl(PBB_MASK);
if (enabled)
mask |= 1 << clk->index;
else
mask &= ~(1 << clk->index);
pm_writel(PBB_MASK, mask);
spin_unlock_irqrestore(&pm_lock, flags);
}
static unsigned long pbb_clk_get_rate(struct clk *clk)
{
unsigned long cksel, shift = 0;
cksel = pm_readl(CKSEL);
if (cksel & PM_BIT(PBBDIV))
shift = PM_BFEXT(PBBSEL, cksel) + 1;
return bus_clk_get_rate(clk, shift);
}
static void genclk_mode(struct clk *clk, int enabled)
{
u32 control;
control = pm_readl(GCCTRL(clk->index));
if (enabled)
control |= PM_BIT(CEN);
else
control &= ~PM_BIT(CEN);
pm_writel(GCCTRL(clk->index), control);
}
static unsigned long genclk_get_rate(struct clk *clk)
{
u32 control;
unsigned long div = 1;
control = pm_readl(GCCTRL(clk->index));
if (control & PM_BIT(DIVEN))
div = 2 * (PM_BFEXT(DIV, control) + 1);
return clk->parent->get_rate(clk->parent) / div;
}
static long genclk_set_rate(struct clk *clk, unsigned long rate, int apply)
{
u32 control;
unsigned long parent_rate, actual_rate, div;
parent_rate = clk->parent->get_rate(clk->parent);
control = pm_readl(GCCTRL(clk->index));
if (rate > 3 * parent_rate / 4) {
actual_rate = parent_rate;
control &= ~PM_BIT(DIVEN);
} else {
div = (parent_rate + rate) / (2 * rate) - 1;
control = PM_BFINS(DIV, div, control) | PM_BIT(DIVEN);
actual_rate = parent_rate / (2 * (div + 1));
}
dev_dbg(clk->dev, "clk %s: new rate %lu (actual rate %lu)\n",
clk->name, rate, actual_rate);
if (apply)
pm_writel(GCCTRL(clk->index), control);
return actual_rate;
}
int genclk_set_parent(struct clk *clk, struct clk *parent)
{
u32 control;
dev_dbg(clk->dev, "clk %s: new parent %s (was %s)\n",
clk->name, parent->name, clk->parent->name);
control = pm_readl(GCCTRL(clk->index));
if (parent == &osc1 || parent == &pll1)
control |= PM_BIT(OSCSEL);
else if (parent == &osc0 || parent == &pll0)
control &= ~PM_BIT(OSCSEL);
else
return -EINVAL;
if (parent == &pll0 || parent == &pll1)
control |= PM_BIT(PLLSEL);
else
control &= ~PM_BIT(PLLSEL);
pm_writel(GCCTRL(clk->index), control);
clk->parent = parent;
return 0;
}
static void __init genclk_init_parent(struct clk *clk)
{
u32 control;
struct clk *parent;
BUG_ON(clk->index > 7);
control = pm_readl(GCCTRL(clk->index));
if (control & PM_BIT(OSCSEL))
parent = (control & PM_BIT(PLLSEL)) ? &pll1 : &osc1;
else
parent = (control & PM_BIT(PLLSEL)) ? &pll0 : &osc0;
clk->parent = parent;
}
static inline void set_ebi_sfr_bits(u32 mask)
{
hmatrix_sfr_set_bits(HMATRIX_SLAVE_EBI, mask);
}
static int __init system_device_init(void)
{
platform_device_register(&at32_pm0_device);
platform_device_register(&at32_intc0_device);
platform_device_register(&at32ap700x_rtc0_device);
platform_device_register(&at32_wdt0_device);
platform_device_register(&at32_eic0_device);
platform_device_register(&smc0_device);
platform_device_register(&pdc_device);
platform_device_register(&dw_dmac0_device);
platform_device_register(&at32_tcb0_device);
platform_device_register(&at32_tcb1_device);
platform_device_register(&pio0_device);
platform_device_register(&pio1_device);
platform_device_register(&pio2_device);
platform_device_register(&pio3_device);
platform_device_register(&pio4_device);
return 0;
}
struct platform_device *__init at32_add_device_psif(unsigned int id)
{
struct platform_device *pdev;
u32 pin_mask;
if (!(id == 0 || id == 1))
return NULL;
pdev = platform_device_alloc("atmel_psif", id);
if (!pdev)
return NULL;
switch (id) {
case 0:
pin_mask = (1 << 8) | (1 << 9);
if (platform_device_add_resources(pdev, atmel_psif0_resource,
ARRAY_SIZE(atmel_psif0_resource)))
goto err_add_resources;
atmel_psif0_pclk.dev = &pdev->dev;
select_peripheral(PIOA, pin_mask, PERIPH_A, 0);
break;
case 1:
pin_mask = (1 << 11) | (1 << 12);
if (platform_device_add_resources(pdev, atmel_psif1_resource,
ARRAY_SIZE(atmel_psif1_resource)))
goto err_add_resources;
atmel_psif1_pclk.dev = &pdev->dev;
select_peripheral(PIOB, pin_mask, PERIPH_A, 0);
break;
default:
return NULL;
}
platform_device_add(pdev);
return pdev;
err_add_resources:
platform_device_put(pdev);
return NULL;
}
static inline void configure_usart0_pins(int flags)
{
u32 pin_mask = (1 << 8) | (1 << 9);
if (flags & ATMEL_USART_RTS) pin_mask |= (1 << 6);
if (flags & ATMEL_USART_CTS) pin_mask |= (1 << 7);
if (flags & ATMEL_USART_CLK) pin_mask |= (1 << 10);
select_peripheral(PIOA, pin_mask, PERIPH_B, AT32_GPIOF_PULLUP);
}
static inline void configure_usart1_pins(int flags)
{
u32 pin_mask = (1 << 17) | (1 << 18);
if (flags & ATMEL_USART_RTS) pin_mask |= (1 << 19);
if (flags & ATMEL_USART_CTS) pin_mask |= (1 << 20);
if (flags & ATMEL_USART_CLK) pin_mask |= (1 << 16);
select_peripheral(PIOA, pin_mask, PERIPH_A, AT32_GPIOF_PULLUP);
}
static inline void configure_usart2_pins(int flags)
{
u32 pin_mask = (1 << 26) | (1 << 27);
if (flags & ATMEL_USART_RTS) pin_mask |= (1 << 30);
if (flags & ATMEL_USART_CTS) pin_mask |= (1 << 29);
if (flags & ATMEL_USART_CLK) pin_mask |= (1 << 28);
select_peripheral(PIOB, pin_mask, PERIPH_B, AT32_GPIOF_PULLUP);
}
static inline void configure_usart3_pins(int flags)
{
u32 pin_mask = (1 << 18) | (1 << 17);
if (flags & ATMEL_USART_RTS) pin_mask |= (1 << 16);
if (flags & ATMEL_USART_CTS) pin_mask |= (1 << 15);
if (flags & ATMEL_USART_CLK) pin_mask |= (1 << 19);
select_peripheral(PIOB, pin_mask, PERIPH_B, AT32_GPIOF_PULLUP);
}
void __init at32_map_usart(unsigned int hw_id, unsigned int line, int flags)
{
struct platform_device *pdev;
struct atmel_uart_data *pdata;
switch (hw_id) {
case 0:
pdev = &atmel_usart0_device;
configure_usart0_pins(flags);
break;
case 1:
pdev = &atmel_usart1_device;
configure_usart1_pins(flags);
break;
case 2:
pdev = &atmel_usart2_device;
configure_usart2_pins(flags);
break;
case 3:
pdev = &atmel_usart3_device;
configure_usart3_pins(flags);
break;
default:
return;
}
if (PXSEG(pdev->resource[0].start) == P4SEG) {
struct atmel_uart_data *data = pdev->dev.platform_data;
data->regs = (void __iomem *)pdev->resource[0].start;
}
pdev->id = line;
pdata = pdev->dev.platform_data;
pdata->num = line;
at32_usarts[line] = pdev;
}
struct platform_device *__init at32_add_device_usart(unsigned int id)
{
platform_device_register(at32_usarts[id]);
return at32_usarts[id];
}
void __init at32_setup_serial_console(unsigned int usart_id)
{
atmel_default_console_device = at32_usarts[usart_id];
}
struct platform_device *__init
at32_add_device_eth(unsigned int id, struct macb_platform_data *data)
{
struct platform_device *pdev;
u32 pin_mask;
switch (id) {
case 0:
pdev = &macb0_device;
pin_mask = (1 << 3);
pin_mask |= (1 << 4);
pin_mask |= (1 << 7);
pin_mask |= (1 << 8);
pin_mask |= (1 << 9);
pin_mask |= (1 << 10);
pin_mask |= (1 << 13);
pin_mask |= (1 << 15);
pin_mask |= (1 << 16);
pin_mask |= (1 << 17);
if (!data->is_rmii) {
pin_mask |= (1 << 0);
pin_mask |= (1 << 1);
pin_mask |= (1 << 2);
pin_mask |= (1 << 5);
pin_mask |= (1 << 6);
pin_mask |= (1 << 11);
pin_mask |= (1 << 12);
pin_mask |= (1 << 14);
#ifndef CONFIG_BOARD_MIMC200
pin_mask |= (1 << 18);
#endif
}
select_peripheral(PIOC, pin_mask, PERIPH_A, 0);
break;
case 1:
pdev = &macb1_device;
pin_mask = (1 << 13);
pin_mask |= (1 << 14);
pin_mask |= (1 << 11);
pin_mask |= (1 << 12);
pin_mask |= (1 << 10);
pin_mask |= (1 << 6);
pin_mask |= (1 << 5);
pin_mask |= (1 << 4);
pin_mask |= (1 << 3);
pin_mask |= (1 << 2);
#ifndef CONFIG_BOARD_MIMC200
if (!data->is_rmii)
pin_mask |= (1 << 15);
#endif
select_peripheral(PIOD, pin_mask, PERIPH_B, 0);
if (!data->is_rmii) {
pin_mask = (1 << 19);
pin_mask |= (1 << 23);
pin_mask |= (1 << 26);
pin_mask |= (1 << 27);
pin_mask |= (1 << 28);
pin_mask |= (1 << 29);
pin_mask |= (1 << 30);
pin_mask |= (1 << 24);
select_peripheral(PIOC, pin_mask, PERIPH_B, 0);
}
break;
default:
return NULL;
}
memcpy(pdev->dev.platform_data, data, sizeof(struct macb_platform_data));
platform_device_register(pdev);
return pdev;
}
void __init
at32_spi_setup_slaves(unsigned int bus_num, struct spi_board_info *b, unsigned int n)
{
static u8 __initdata spi_pins[][4] = {
{ GPIO_PIN_PA(3), GPIO_PIN_PA(4),
GPIO_PIN_PA(5), GPIO_PIN_PA(20) },
{ GPIO_PIN_PB(2), GPIO_PIN_PB(3),
GPIO_PIN_PB(4), GPIO_PIN_PA(27) },
};
unsigned int pin, mode;
if (bus_num > 1)
return;
for (; n; n--, b++) {
b->bus_num = bus_num;
if (b->chip_select >= 4)
continue;
pin = (unsigned)b->controller_data;
if (!pin) {
pin = spi_pins[bus_num][b->chip_select];
b->controller_data = (void *)pin;
}
mode = AT32_GPIOF_OUTPUT;
if (!(b->mode & SPI_CS_HIGH))
mode |= AT32_GPIOF_HIGH;
at32_select_gpio(pin, mode);
}
}
struct platform_device *__init
at32_add_device_spi(unsigned int id, struct spi_board_info *b, unsigned int n)
{
struct platform_device *pdev;
u32 pin_mask;
switch (id) {
case 0:
pdev = &atmel_spi0_device;
pin_mask = (1 << 1) | (1 << 2);
select_peripheral(PIOA, (1 << 0), PERIPH_A, AT32_GPIOF_PULLUP);
select_peripheral(PIOA, pin_mask, PERIPH_A, 0);
at32_spi_setup_slaves(0, b, n);
break;
case 1:
pdev = &atmel_spi1_device;
pin_mask = (1 << 1) | (1 << 5);
select_peripheral(PIOB, (1 << 0), PERIPH_B, AT32_GPIOF_PULLUP);
select_peripheral(PIOB, pin_mask, PERIPH_B, 0);
at32_spi_setup_slaves(1, b, n);
break;
default:
return NULL;
}
spi_register_board_info(b, n);
platform_device_register(pdev);
return pdev;
}
struct platform_device *__init at32_add_device_twi(unsigned int id,
struct i2c_board_info *b,
unsigned int n)
{
struct platform_device *pdev;
u32 pin_mask;
if (id != 0)
return NULL;
pdev = platform_device_alloc("atmel_twi", id);
if (!pdev)
return NULL;
if (platform_device_add_resources(pdev, atmel_twi0_resource,
ARRAY_SIZE(atmel_twi0_resource)))
goto err_add_resources;
pin_mask = (1 << 6) | (1 << 7);
select_peripheral(PIOA, pin_mask, PERIPH_A, 0);
atmel_twi0_pclk.dev = &pdev->dev;
if (b)
i2c_register_board_info(id, b, n);
platform_device_add(pdev);
return pdev;
err_add_resources:
platform_device_put(pdev);
return NULL;
}
struct platform_device *__init
at32_add_device_mci(unsigned int id, struct mci_platform_data *data)
{
struct platform_device *pdev;
struct mci_dma_data *slave;
u32 pioa_mask;
u32 piob_mask;
if (id != 0 || !data)
return NULL;
if (!data->slot[0].bus_width && !data->slot[1].bus_width)
return NULL;
pdev = platform_device_alloc("atmel_mci", id);
if (!pdev)
goto fail;
if (platform_device_add_resources(pdev, atmel_mci0_resource,
ARRAY_SIZE(atmel_mci0_resource)))
goto fail;
slave = kzalloc(sizeof(struct mci_dma_data), GFP_KERNEL);
if (!slave)
goto fail;
slave->sdata.dma_dev = &dw_dmac0_device.dev;
slave->sdata.reg_width = DW_DMA_SLAVE_WIDTH_32BIT;
slave->sdata.cfg_hi = (DWC_CFGH_SRC_PER(0)
| DWC_CFGH_DST_PER(1));
slave->sdata.cfg_lo &= ~(DWC_CFGL_HS_DST_POL
| DWC_CFGL_HS_SRC_POL);
data->dma_slave = slave;
if (platform_device_add_data(pdev, data,
sizeof(struct mci_platform_data)))
goto fail_free;
pioa_mask = 1 << 10;
switch (data->slot[0].bus_width) {
case 4:
pioa_mask |= 1 << 13;
pioa_mask |= 1 << 14;
pioa_mask |= 1 << 15;
case 1:
pioa_mask |= 1 << 11;
pioa_mask |= 1 << 12;
if (gpio_is_valid(data->slot[0].detect_pin))
at32_select_gpio(data->slot[0].detect_pin, 0);
if (gpio_is_valid(data->slot[0].wp_pin))
at32_select_gpio(data->slot[0].wp_pin, 0);
break;
case 0:
break;
default:
goto fail_free;
}
select_peripheral(PIOA, pioa_mask, PERIPH_A, 0);
piob_mask = 0;
switch (data->slot[1].bus_width) {
case 4:
piob_mask |= 1 << 8;
piob_mask |= 1 << 9;
piob_mask |= 1 << 10;
case 1:
piob_mask |= 1 << 6;
piob_mask |= 1 << 7;
select_peripheral(PIOB, piob_mask, PERIPH_B, 0);
if (gpio_is_valid(data->slot[1].detect_pin))
at32_select_gpio(data->slot[1].detect_pin, 0);
if (gpio_is_valid(data->slot[1].wp_pin))
at32_select_gpio(data->slot[1].wp_pin, 0);
break;
case 0:
break;
default:
if (!data->slot[0].bus_width)
goto fail_free;
data->slot[1].bus_width = 0;
break;
}
atmel_mci0_pclk.dev = &pdev->dev;
platform_device_add(pdev);
return pdev;
fail_free:
kfree(slave);
fail:
data->dma_slave = NULL;
platform_device_put(pdev);
return NULL;
}
struct platform_device *__init
at32_add_device_lcdc(unsigned int id, struct atmel_lcdfb_info *data,
unsigned long fbmem_start, unsigned long fbmem_len,
u64 pin_mask)
{
struct platform_device *pdev;
struct atmel_lcdfb_info *info;
struct fb_monspecs *monspecs;
struct fb_videomode *modedb;
unsigned int modedb_size;
u32 portc_mask, portd_mask, porte_mask;
monspecs = kmemdup(data->default_monspecs,
sizeof(struct fb_monspecs), GFP_KERNEL);
if (!monspecs)
return NULL;
modedb_size = sizeof(struct fb_videomode) * monspecs->modedb_len;
modedb = kmemdup(monspecs->modedb, modedb_size, GFP_KERNEL);
if (!modedb)
goto err_dup_modedb;
monspecs->modedb = modedb;
switch (id) {
case 0:
pdev = &atmel_lcdfb0_device;
if (pin_mask == 0ULL)
pin_mask = ATMEL_LCDC_PRI_24BIT | ATMEL_LCDC_PRI_CONTROL;
portc_mask = pin_mask & 0xfff80000;
select_peripheral(PIOC, portc_mask, PERIPH_A, 0);
portd_mask = pin_mask & 0x0003ffff;
select_peripheral(PIOD, portd_mask, PERIPH_A, 0);
porte_mask = (pin_mask >> 32) & 0x0007ffff;
select_peripheral(PIOE, porte_mask, PERIPH_B, 0);
clk_set_parent(&atmel_lcdfb0_pixclk, &pll0);
clk_set_rate(&atmel_lcdfb0_pixclk, clk_get_rate(&pll0));
break;
default:
goto err_invalid_id;
}
if (fbmem_len) {
pdev->resource[2].start = fbmem_start;
pdev->resource[2].end = fbmem_start + fbmem_len - 1;
pdev->resource[2].flags = IORESOURCE_MEM;
}
info = pdev->dev.platform_data;
memcpy(info, data, sizeof(struct atmel_lcdfb_info));
info->default_monspecs = monspecs;
platform_device_register(pdev);
return pdev;
err_invalid_id:
kfree(modedb);
err_dup_modedb:
kfree(monspecs);
return NULL;
}
struct platform_device *__init at32_add_device_pwm(u32 mask)
{
struct platform_device *pdev;
u32 pin_mask;
if (!mask)
return NULL;
pdev = platform_device_alloc("atmel_pwm", 0);
if (!pdev)
return NULL;
if (platform_device_add_resources(pdev, atmel_pwm0_resource,
ARRAY_SIZE(atmel_pwm0_resource)))
goto out_free_pdev;
if (platform_device_add_data(pdev, &mask, sizeof(mask)))
goto out_free_pdev;
pin_mask = 0;
if (mask & (1 << 0))
pin_mask |= (1 << 28);
if (mask & (1 << 1))
pin_mask |= (1 << 29);
if (pin_mask > 0)
select_peripheral(PIOA, pin_mask, PERIPH_A, 0);
pin_mask = 0;
if (mask & (1 << 2))
pin_mask |= (1 << 21);
if (mask & (1 << 3))
pin_mask |= (1 << 22);
if (pin_mask > 0)
select_peripheral(PIOA, pin_mask, PERIPH_B, 0);
atmel_pwm0_mck.dev = &pdev->dev;
platform_device_add(pdev);
return pdev;
out_free_pdev:
platform_device_put(pdev);
return NULL;
}
struct platform_device *__init
at32_add_device_ssc(unsigned int id, unsigned int flags)
{
struct platform_device *pdev;
u32 pin_mask = 0;
switch (id) {
case 0:
pdev = &ssc0_device;
if (flags & ATMEL_SSC_RF)
pin_mask |= (1 << 21);
if (flags & ATMEL_SSC_RK)
pin_mask |= (1 << 22);
if (flags & ATMEL_SSC_TK)
pin_mask |= (1 << 23);
if (flags & ATMEL_SSC_TF)
pin_mask |= (1 << 24);
if (flags & ATMEL_SSC_TD)
pin_mask |= (1 << 25);
if (flags & ATMEL_SSC_RD)
pin_mask |= (1 << 26);
if (pin_mask > 0)
select_peripheral(PIOA, pin_mask, PERIPH_A, 0);
break;
case 1:
pdev = &ssc1_device;
if (flags & ATMEL_SSC_RF)
pin_mask |= (1 << 0);
if (flags & ATMEL_SSC_RK)
pin_mask |= (1 << 1);
if (flags & ATMEL_SSC_TK)
pin_mask |= (1 << 2);
if (flags & ATMEL_SSC_TF)
pin_mask |= (1 << 3);
if (flags & ATMEL_SSC_TD)
pin_mask |= (1 << 4);
if (flags & ATMEL_SSC_RD)
pin_mask |= (1 << 5);
if (pin_mask > 0)
select_peripheral(PIOA, pin_mask, PERIPH_B, 0);
break;
case 2:
pdev = &ssc2_device;
if (flags & ATMEL_SSC_TD)
pin_mask |= (1 << 13);
if (flags & ATMEL_SSC_RD)
pin_mask |= (1 << 14);
if (flags & ATMEL_SSC_TK)
pin_mask |= (1 << 15);
if (flags & ATMEL_SSC_TF)
pin_mask |= (1 << 16);
if (flags & ATMEL_SSC_RF)
pin_mask |= (1 << 17);
if (flags & ATMEL_SSC_RK)
pin_mask |= (1 << 18);
if (pin_mask > 0)
select_peripheral(PIOB, pin_mask, PERIPH_A, 0);
break;
default:
return NULL;
}
platform_device_register(pdev);
return pdev;
}
struct platform_device *__init
at32_add_device_usba(unsigned int id, struct usba_platform_data *data)
{
struct {
struct usba_platform_data pdata;
struct usba_ep_data ep[7];
} usba_data;
struct platform_device *pdev;
if (id != 0)
return NULL;
pdev = platform_device_alloc("atmel_usba_udc", 0);
if (!pdev)
return NULL;
if (platform_device_add_resources(pdev, usba0_resource,
ARRAY_SIZE(usba0_resource)))
goto out_free_pdev;
if (data) {
usba_data.pdata.vbus_pin = data->vbus_pin;
usba_data.pdata.vbus_pin_inverted = data->vbus_pin_inverted;
} else {
usba_data.pdata.vbus_pin = -EINVAL;
usba_data.pdata.vbus_pin_inverted = -EINVAL;
}
data = &usba_data.pdata;
data->num_ep = ARRAY_SIZE(at32_usba_ep);
memcpy(data->ep, at32_usba_ep, sizeof(at32_usba_ep));
if (platform_device_add_data(pdev, data, sizeof(usba_data)))
goto out_free_pdev;
if (gpio_is_valid(data->vbus_pin))
at32_select_gpio(data->vbus_pin, 0);
usba0_pclk.dev = &pdev->dev;
usba0_hclk.dev = &pdev->dev;
platform_device_add(pdev);
return pdev;
out_free_pdev:
platform_device_put(pdev);
return NULL;
}
static int __init at32_init_ide_or_cf(struct platform_device *pdev,
unsigned int cs, unsigned int extint)
{
static unsigned int extint_pin_map[4] __initdata = {
(1 << 25),
(1 << 26),
(1 << 27),
(1 << 28),
};
static bool common_pins_initialized __initdata = false;
unsigned int extint_pin;
int ret;
u32 pin_mask;
if (extint >= ARRAY_SIZE(extint_pin_map))
return -EINVAL;
extint_pin = extint_pin_map[extint];
switch (cs) {
case 4:
ret = platform_device_add_resources(pdev,
at32_smc_cs4_resource,
ARRAY_SIZE(at32_smc_cs4_resource));
if (ret)
return ret;
select_peripheral(PIOE, (1 << 21), PERIPH_A, 0);
hmatrix_sfr_set_bits(HMATRIX_SLAVE_EBI, HMATRIX_EBI_CF0_ENABLE);
break;
case 5:
ret = platform_device_add_resources(pdev,
at32_smc_cs5_resource,
ARRAY_SIZE(at32_smc_cs5_resource));
if (ret)
return ret;
select_peripheral(PIOE, (1 << 22), PERIPH_A, 0);
hmatrix_sfr_set_bits(HMATRIX_SLAVE_EBI, HMATRIX_EBI_CF1_ENABLE);
break;
default:
return -EINVAL;
}
if (!common_pins_initialized) {
pin_mask = (1 << 19);
pin_mask |= (1 << 20);
pin_mask |= (1 << 23);
pin_mask |= (1 << 24);
select_peripheral(PIOE, pin_mask, PERIPH_A, 0);
common_pins_initialized = true;
}
select_peripheral(PIOB, extint_pin, PERIPH_A, AT32_GPIOF_DEGLITCH);
pdev->resource[1].start = EIM_IRQ_BASE + extint;
pdev->resource[1].end = pdev->resource[1].start;
return 0;
}
struct platform_device *__init
at32_add_device_ide(unsigned int id, unsigned int extint,
struct ide_platform_data *data)
{
struct platform_device *pdev;
pdev = platform_device_alloc("at32_ide", id);
if (!pdev)
goto fail;
if (platform_device_add_data(pdev, data,
sizeof(struct ide_platform_data)))
goto fail;
if (at32_init_ide_or_cf(pdev, data->cs, extint))
goto fail;
platform_device_add(pdev);
return pdev;
fail:
platform_device_put(pdev);
return NULL;
}
struct platform_device *__init
at32_add_device_cf(unsigned int id, unsigned int extint,
struct cf_platform_data *data)
{
struct platform_device *pdev;
pdev = platform_device_alloc("at32_cf", id);
if (!pdev)
goto fail;
if (platform_device_add_data(pdev, data,
sizeof(struct cf_platform_data)))
goto fail;
if (at32_init_ide_or_cf(pdev, data->cs, extint))
goto fail;
if (gpio_is_valid(data->detect_pin))
at32_select_gpio(data->detect_pin, AT32_GPIOF_DEGLITCH);
if (gpio_is_valid(data->reset_pin))
at32_select_gpio(data->reset_pin, 0);
if (gpio_is_valid(data->vcc_pin))
at32_select_gpio(data->vcc_pin, 0);
platform_device_add(pdev);
return pdev;
fail:
platform_device_put(pdev);
return NULL;
}
struct platform_device *__init
at32_add_device_nand(unsigned int id, struct atmel_nand_data *data)
{
struct platform_device *pdev;
if (id != 0 || !data)
return NULL;
pdev = platform_device_alloc("atmel_nand", id);
if (!pdev)
goto fail;
if (platform_device_add_resources(pdev, smc_cs3_resource,
ARRAY_SIZE(smc_cs3_resource)))
goto fail;
if (platform_device_add_data(pdev, data,
sizeof(struct atmel_nand_data)))
goto fail;
hmatrix_sfr_set_bits(HMATRIX_SLAVE_EBI, HMATRIX_EBI_NAND_ENABLE);
if (data->enable_pin)
at32_select_gpio(data->enable_pin,
AT32_GPIOF_OUTPUT | AT32_GPIOF_HIGH);
if (data->rdy_pin)
at32_select_gpio(data->rdy_pin, 0);
if (data->det_pin)
at32_select_gpio(data->det_pin, 0);
platform_device_add(pdev);
return pdev;
fail:
platform_device_put(pdev);
return NULL;
}
struct platform_device *__init
at32_add_device_ac97c(unsigned int id, struct ac97c_platform_data *data,
unsigned int flags)
{
struct platform_device *pdev;
struct dw_dma_slave *rx_dws;
struct dw_dma_slave *tx_dws;
struct ac97c_platform_data _data;
u32 pin_mask;
if (id != 0)
return NULL;
pdev = platform_device_alloc("atmel_ac97c", id);
if (!pdev)
return NULL;
if (platform_device_add_resources(pdev, atmel_ac97c0_resource,
ARRAY_SIZE(atmel_ac97c0_resource)))
goto out_free_resources;
if (!data) {
data = &_data;
memset(data, 0, sizeof(struct ac97c_platform_data));
data->reset_pin = -ENODEV;
}
rx_dws = &data->rx_dws;
tx_dws = &data->tx_dws;
if (flags & AC97C_CAPTURE) {
rx_dws->dma_dev = &dw_dmac0_device.dev;
rx_dws->reg_width = DW_DMA_SLAVE_WIDTH_16BIT;
rx_dws->cfg_hi = DWC_CFGH_SRC_PER(3);
rx_dws->cfg_lo &= ~(DWC_CFGL_HS_DST_POL | DWC_CFGL_HS_SRC_POL);
rx_dws->src_master = 0;
rx_dws->dst_master = 1;
rx_dws->src_msize = DW_DMA_MSIZE_1;
rx_dws->dst_msize = DW_DMA_MSIZE_1;
rx_dws->fc = DW_DMA_FC_D_P2M;
}
if (flags & AC97C_PLAYBACK) {
tx_dws->dma_dev = &dw_dmac0_device.dev;
tx_dws->reg_width = DW_DMA_SLAVE_WIDTH_16BIT;
tx_dws->cfg_hi = DWC_CFGH_DST_PER(4);
tx_dws->cfg_lo &= ~(DWC_CFGL_HS_DST_POL | DWC_CFGL_HS_SRC_POL);
tx_dws->src_master = 0;
tx_dws->dst_master = 1;
tx_dws->src_msize = DW_DMA_MSIZE_1;
tx_dws->dst_msize = DW_DMA_MSIZE_1;
tx_dws->fc = DW_DMA_FC_D_M2P;
}
if (platform_device_add_data(pdev, data,
sizeof(struct ac97c_platform_data)))
goto out_free_resources;
pin_mask = (1 << 20) | (1 << 21) | (1 << 22) | (1 << 23);
select_peripheral(PIOB, pin_mask, PERIPH_B, 0);
if (gpio_is_valid(data->reset_pin))
at32_select_gpio(data->reset_pin, AT32_GPIOF_OUTPUT
| AT32_GPIOF_HIGH);
atmel_ac97c0_pclk.dev = &pdev->dev;
platform_device_add(pdev);
return pdev;
out_free_resources:
platform_device_put(pdev);
return NULL;
}
struct platform_device *__init
at32_add_device_abdac(unsigned int id, struct atmel_abdac_pdata *data)
{
struct platform_device *pdev;
struct dw_dma_slave *dws;
u32 pin_mask;
if (id != 0 || !data)
return NULL;
pdev = platform_device_alloc("atmel_abdac", id);
if (!pdev)
return NULL;
if (platform_device_add_resources(pdev, abdac0_resource,
ARRAY_SIZE(abdac0_resource)))
goto out_free_resources;
dws = &data->dws;
dws->dma_dev = &dw_dmac0_device.dev;
dws->reg_width = DW_DMA_SLAVE_WIDTH_32BIT;
dws->cfg_hi = DWC_CFGH_DST_PER(2);
dws->cfg_lo &= ~(DWC_CFGL_HS_DST_POL | DWC_CFGL_HS_SRC_POL);
dws->src_master = 0;
dws->dst_master = 1;
dws->src_msize = DW_DMA_MSIZE_1;
dws->dst_msize = DW_DMA_MSIZE_1;
dws->fc = DW_DMA_FC_D_M2P;
if (platform_device_add_data(pdev, data,
sizeof(struct atmel_abdac_pdata)))
goto out_free_resources;
pin_mask = (1 << 20) | (1 << 22);
pin_mask |= (1 << 21) | (1 << 23);
select_peripheral(PIOB, pin_mask, PERIPH_A, 0);
abdac0_pclk.dev = &pdev->dev;
abdac0_sample_clk.dev = &pdev->dev;
platform_device_add(pdev);
return pdev;
out_free_resources:
platform_device_put(pdev);
return NULL;
}
void __init setup_platform(void)
{
u32 cpu_mask = 0, hsb_mask = 0, pba_mask = 0, pbb_mask = 0;
int i;
if (pm_readl(MCCTRL) & PM_BIT(PLLSEL)) {
main_clock = &pll0;
cpu_clk.parent = &pll0;
} else {
main_clock = &osc0;
cpu_clk.parent = &osc0;
}
if (pm_readl(PLL0) & PM_BIT(PLLOSC))
pll0.parent = &osc1;
if (pm_readl(PLL1) & PM_BIT(PLLOSC))
pll1.parent = &osc1;
genclk_init_parent(&gclk0);
genclk_init_parent(&gclk1);
genclk_init_parent(&gclk2);
genclk_init_parent(&gclk3);
genclk_init_parent(&gclk4);
#if defined(CONFIG_CPU_AT32AP7000) || defined(CONFIG_CPU_AT32AP7002)
genclk_init_parent(&atmel_lcdfb0_pixclk);
#endif
genclk_init_parent(&abdac0_sample_clk);
for (i = 0; i < ARRAY_SIZE(init_clocks); i++) {
struct clk *clk = init_clocks[i];
at32_clk_register(clk);
if (clk->users == 0)
continue;
if (clk->mode == &cpu_clk_mode)
cpu_mask |= 1 << clk->index;
else if (clk->mode == &hsb_clk_mode)
hsb_mask |= 1 << clk->index;
else if (clk->mode == &pba_clk_mode)
pba_mask |= 1 << clk->index;
else if (clk->mode == &pbb_clk_mode)
pbb_mask |= 1 << clk->index;
}
pm_writel(CPU_MASK, cpu_mask);
pm_writel(HSB_MASK, hsb_mask);
pm_writel(PBA_MASK, pba_mask);
pm_writel(PBB_MASK, pbb_mask);
at32_init_pio(&pio0_device);
at32_init_pio(&pio1_device);
at32_init_pio(&pio2_device);
at32_init_pio(&pio3_device);
at32_init_pio(&pio4_device);
}
static int __init sram_init(void)
{
struct gen_pool *pool;
pool = gen_pool_create(10, -1);
if (!pool)
goto fail;
if (gen_pool_add(pool, 0x24000000, 0x8000, -1))
goto err_pool_add;
sram_pool = pool;
return 0;
err_pool_add:
gen_pool_destroy(pool);
fail:
pr_err("Failed to create SRAM pool\n");
return -ENOMEM;
}
