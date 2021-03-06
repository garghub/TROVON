static void cpm_mask_irq(struct irq_data *d)
{
unsigned int cpm_vec = (unsigned int)irqd_to_hwirq(d);
clrbits32(&cpic_reg->cpic_cimr, (1 << cpm_vec));
}
static void cpm_unmask_irq(struct irq_data *d)
{
unsigned int cpm_vec = (unsigned int)irqd_to_hwirq(d);
setbits32(&cpic_reg->cpic_cimr, (1 << cpm_vec));
}
static void cpm_end_irq(struct irq_data *d)
{
unsigned int cpm_vec = (unsigned int)irqd_to_hwirq(d);
out_be32(&cpic_reg->cpic_cisr, (1 << cpm_vec));
}
int cpm_get_irq(void)
{
int cpm_vec;
out_be16(&cpic_reg->cpic_civr, 1);
cpm_vec = in_be16(&cpic_reg->cpic_civr);
cpm_vec >>= 11;
return irq_linear_revmap(cpm_pic_host, cpm_vec);
}
static int cpm_pic_host_map(struct irq_host *h, unsigned int virq,
irq_hw_number_t hw)
{
pr_debug("cpm_pic_host_map(%d, 0x%lx)\n", virq, hw);
irq_set_status_flags(virq, IRQ_LEVEL);
irq_set_chip_and_handler(virq, &cpm_pic, handle_fasteoi_irq);
return 0;
}
static irqreturn_t cpm_error_interrupt(int irq, void *dev)
{
return IRQ_HANDLED;
}
unsigned int cpm_pic_init(void)
{
struct device_node *np = NULL;
struct resource res;
unsigned int sirq = NO_IRQ, hwirq, eirq;
int ret;
pr_debug("cpm_pic_init\n");
np = of_find_compatible_node(NULL, NULL, "fsl,cpm1-pic");
if (np == NULL)
np = of_find_compatible_node(NULL, "cpm-pic", "CPM");
if (np == NULL) {
printk(KERN_ERR "CPM PIC init: can not find cpm-pic node\n");
return sirq;
}
ret = of_address_to_resource(np, 0, &res);
if (ret)
goto end;
cpic_reg = ioremap(res.start, res.end - res.start + 1);
if (cpic_reg == NULL)
goto end;
sirq = irq_of_parse_and_map(np, 0);
if (sirq == NO_IRQ)
goto end;
hwirq = (unsigned int)virq_to_hw(sirq);
out_be32(&cpic_reg->cpic_cicr,
(CICR_SCD_SCC4 | CICR_SCC_SCC3 | CICR_SCB_SCC2 | CICR_SCA_SCC1) |
((hwirq/2) << 13) | CICR_HP_MASK);
out_be32(&cpic_reg->cpic_cimr, 0);
cpm_pic_host = irq_alloc_host(np, IRQ_HOST_MAP_LINEAR,
64, &cpm_pic_host_ops, 64);
if (cpm_pic_host == NULL) {
printk(KERN_ERR "CPM2 PIC: failed to allocate irq host!\n");
sirq = NO_IRQ;
goto end;
}
np = of_find_compatible_node(NULL, NULL, "fsl,cpm1");
if (np == NULL)
np = of_find_node_by_type(NULL, "cpm");
if (np == NULL) {
printk(KERN_ERR "CPM PIC init: can not find cpm node\n");
goto end;
}
eirq = irq_of_parse_and_map(np, 0);
if (eirq == NO_IRQ)
goto end;
if (setup_irq(eirq, &cpm_error_irqaction))
printk(KERN_ERR "Could not allocate CPM error IRQ!");
setbits32(&cpic_reg->cpic_cicr, CICR_IEN);
end:
of_node_put(np);
return sirq;
}
void __init cpm_reset(void)
{
sysconf8xx_t __iomem *siu_conf;
mpc8xx_immr = ioremap(get_immrbase(), 0x4000);
if (!mpc8xx_immr) {
printk(KERN_CRIT "Could not map IMMR\n");
return;
}
cpmp = &mpc8xx_immr->im_cpm;
#ifndef CONFIG_PPC_EARLY_DEBUG_CPM
out_be16(&cpmp->cp_cpcr, CPM_CR_RST | CPM_CR_FLG);
while (in_be16(&cpmp->cp_cpcr) & CPM_CR_FLG);
#endif
#ifdef CONFIG_UCODE_PATCH
cpm_load_patch(cpmp);
#endif
siu_conf = immr_map(im_siu_conf);
out_be32(&siu_conf->sc_sdcr, 1);
immr_unmap(siu_conf);
cpm_muram_init();
}
int cpm_command(u32 command, u8 opcode)
{
int i, ret;
unsigned long flags;
if (command & 0xffffff0f)
return -EINVAL;
spin_lock_irqsave(&cmd_lock, flags);
ret = 0;
out_be16(&cpmp->cp_cpcr, command | CPM_CR_FLG | (opcode << 8));
for (i = 0; i < MAX_CR_CMD_LOOPS; i++)
if ((in_be16(&cpmp->cp_cpcr) & CPM_CR_FLG) == 0)
goto out;
printk(KERN_ERR "%s(): Not able to issue CPM command\n", __func__);
ret = -EIO;
out:
spin_unlock_irqrestore(&cmd_lock, flags);
return ret;
}
void
cpm_setbrg(uint brg, uint rate)
{
u32 __iomem *bp;
bp = &cpmp->cp_brgc1;
bp += brg;
if (((BRG_UART_CLK / rate) - 1) < 4096)
out_be32(bp, (((BRG_UART_CLK / rate) - 1) << 1) | CPM_BRG_EN);
else
out_be32(bp, (((BRG_UART_CLK_DIV16 / rate) - 1) << 1) |
CPM_BRG_EN | CPM_BRG_DIV16);
}
static void cpm1_set_pin32(int port, int pin, int flags)
{
struct cpm_ioport32e __iomem *iop;
pin = 1 << (31 - pin);
if (port == CPM_PORTB)
iop = (struct cpm_ioport32e __iomem *)
&mpc8xx_immr->im_cpm.cp_pbdir;
else
iop = (struct cpm_ioport32e __iomem *)
&mpc8xx_immr->im_cpm.cp_pedir;
if (flags & CPM_PIN_OUTPUT)
setbits32(&iop->dir, pin);
else
clrbits32(&iop->dir, pin);
if (!(flags & CPM_PIN_GPIO))
setbits32(&iop->par, pin);
else
clrbits32(&iop->par, pin);
if (port == CPM_PORTB) {
if (flags & CPM_PIN_OPENDRAIN)
setbits16(&mpc8xx_immr->im_cpm.cp_pbodr, pin);
else
clrbits16(&mpc8xx_immr->im_cpm.cp_pbodr, pin);
}
if (port == CPM_PORTE) {
if (flags & CPM_PIN_SECONDARY)
setbits32(&iop->sor, pin);
else
clrbits32(&iop->sor, pin);
if (flags & CPM_PIN_OPENDRAIN)
setbits32(&mpc8xx_immr->im_cpm.cp_peodr, pin);
else
clrbits32(&mpc8xx_immr->im_cpm.cp_peodr, pin);
}
}
static void cpm1_set_pin16(int port, int pin, int flags)
{
struct cpm_ioport16 __iomem *iop =
(struct cpm_ioport16 __iomem *)&mpc8xx_immr->im_ioport;
pin = 1 << (15 - pin);
if (port != 0)
iop += port - 1;
if (flags & CPM_PIN_OUTPUT)
setbits16(&iop->dir, pin);
else
clrbits16(&iop->dir, pin);
if (!(flags & CPM_PIN_GPIO))
setbits16(&iop->par, pin);
else
clrbits16(&iop->par, pin);
if (port == CPM_PORTA) {
if (flags & CPM_PIN_OPENDRAIN)
setbits16(&iop->odr_sor, pin);
else
clrbits16(&iop->odr_sor, pin);
}
if (port == CPM_PORTC) {
if (flags & CPM_PIN_SECONDARY)
setbits16(&iop->odr_sor, pin);
else
clrbits16(&iop->odr_sor, pin);
}
}
void cpm1_set_pin(enum cpm_port port, int pin, int flags)
{
if (port == CPM_PORTB || port == CPM_PORTE)
cpm1_set_pin32(port, pin, flags);
else
cpm1_set_pin16(port, pin, flags);
}
int cpm1_clk_setup(enum cpm_clk_target target, int clock, int mode)
{
int shift;
int i, bits = 0;
u32 __iomem *reg;
u32 mask = 7;
u8 clk_map[][3] = {
{CPM_CLK_SCC1, CPM_BRG1, 0},
{CPM_CLK_SCC1, CPM_BRG2, 1},
{CPM_CLK_SCC1, CPM_BRG3, 2},
{CPM_CLK_SCC1, CPM_BRG4, 3},
{CPM_CLK_SCC1, CPM_CLK1, 4},
{CPM_CLK_SCC1, CPM_CLK2, 5},
{CPM_CLK_SCC1, CPM_CLK3, 6},
{CPM_CLK_SCC1, CPM_CLK4, 7},
{CPM_CLK_SCC2, CPM_BRG1, 0},
{CPM_CLK_SCC2, CPM_BRG2, 1},
{CPM_CLK_SCC2, CPM_BRG3, 2},
{CPM_CLK_SCC2, CPM_BRG4, 3},
{CPM_CLK_SCC2, CPM_CLK1, 4},
{CPM_CLK_SCC2, CPM_CLK2, 5},
{CPM_CLK_SCC2, CPM_CLK3, 6},
{CPM_CLK_SCC2, CPM_CLK4, 7},
{CPM_CLK_SCC3, CPM_BRG1, 0},
{CPM_CLK_SCC3, CPM_BRG2, 1},
{CPM_CLK_SCC3, CPM_BRG3, 2},
{CPM_CLK_SCC3, CPM_BRG4, 3},
{CPM_CLK_SCC3, CPM_CLK5, 4},
{CPM_CLK_SCC3, CPM_CLK6, 5},
{CPM_CLK_SCC3, CPM_CLK7, 6},
{CPM_CLK_SCC3, CPM_CLK8, 7},
{CPM_CLK_SCC4, CPM_BRG1, 0},
{CPM_CLK_SCC4, CPM_BRG2, 1},
{CPM_CLK_SCC4, CPM_BRG3, 2},
{CPM_CLK_SCC4, CPM_BRG4, 3},
{CPM_CLK_SCC4, CPM_CLK5, 4},
{CPM_CLK_SCC4, CPM_CLK6, 5},
{CPM_CLK_SCC4, CPM_CLK7, 6},
{CPM_CLK_SCC4, CPM_CLK8, 7},
{CPM_CLK_SMC1, CPM_BRG1, 0},
{CPM_CLK_SMC1, CPM_BRG2, 1},
{CPM_CLK_SMC1, CPM_BRG3, 2},
{CPM_CLK_SMC1, CPM_BRG4, 3},
{CPM_CLK_SMC1, CPM_CLK1, 4},
{CPM_CLK_SMC1, CPM_CLK2, 5},
{CPM_CLK_SMC1, CPM_CLK3, 6},
{CPM_CLK_SMC1, CPM_CLK4, 7},
{CPM_CLK_SMC2, CPM_BRG1, 0},
{CPM_CLK_SMC2, CPM_BRG2, 1},
{CPM_CLK_SMC2, CPM_BRG3, 2},
{CPM_CLK_SMC2, CPM_BRG4, 3},
{CPM_CLK_SMC2, CPM_CLK5, 4},
{CPM_CLK_SMC2, CPM_CLK6, 5},
{CPM_CLK_SMC2, CPM_CLK7, 6},
{CPM_CLK_SMC2, CPM_CLK8, 7},
};
switch (target) {
case CPM_CLK_SCC1:
reg = &mpc8xx_immr->im_cpm.cp_sicr;
shift = 0;
break;
case CPM_CLK_SCC2:
reg = &mpc8xx_immr->im_cpm.cp_sicr;
shift = 8;
break;
case CPM_CLK_SCC3:
reg = &mpc8xx_immr->im_cpm.cp_sicr;
shift = 16;
break;
case CPM_CLK_SCC4:
reg = &mpc8xx_immr->im_cpm.cp_sicr;
shift = 24;
break;
case CPM_CLK_SMC1:
reg = &mpc8xx_immr->im_cpm.cp_simode;
shift = 12;
break;
case CPM_CLK_SMC2:
reg = &mpc8xx_immr->im_cpm.cp_simode;
shift = 28;
break;
default:
printk(KERN_ERR "cpm1_clock_setup: invalid clock target\n");
return -EINVAL;
}
for (i = 0; i < ARRAY_SIZE(clk_map); i++) {
if (clk_map[i][0] == target && clk_map[i][1] == clock) {
bits = clk_map[i][2];
break;
}
}
if (i == ARRAY_SIZE(clk_map)) {
printk(KERN_ERR "cpm1_clock_setup: invalid clock combination\n");
return -EINVAL;
}
bits <<= shift;
mask <<= shift;
if (reg == &mpc8xx_immr->im_cpm.cp_sicr) {
if (mode == CPM_CLK_RTX) {
bits |= bits << 3;
mask |= mask << 3;
} else if (mode == CPM_CLK_RX) {
bits <<= 3;
mask <<= 3;
}
}
out_be32(reg, (in_be32(reg) & ~mask) | bits);
return 0;
}
static inline struct cpm1_gpio16_chip *
to_cpm1_gpio16_chip(struct of_mm_gpio_chip *mm_gc)
{
return container_of(mm_gc, struct cpm1_gpio16_chip, mm_gc);
}
static void cpm1_gpio16_save_regs(struct of_mm_gpio_chip *mm_gc)
{
struct cpm1_gpio16_chip *cpm1_gc = to_cpm1_gpio16_chip(mm_gc);
struct cpm_ioport16 __iomem *iop = mm_gc->regs;
cpm1_gc->cpdata = in_be16(&iop->dat);
}
static int cpm1_gpio16_get(struct gpio_chip *gc, unsigned int gpio)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct cpm_ioport16 __iomem *iop = mm_gc->regs;
u16 pin_mask;
pin_mask = 1 << (15 - gpio);
return !!(in_be16(&iop->dat) & pin_mask);
}
static void __cpm1_gpio16_set(struct of_mm_gpio_chip *mm_gc, u16 pin_mask,
int value)
{
struct cpm1_gpio16_chip *cpm1_gc = to_cpm1_gpio16_chip(mm_gc);
struct cpm_ioport16 __iomem *iop = mm_gc->regs;
if (value)
cpm1_gc->cpdata |= pin_mask;
else
cpm1_gc->cpdata &= ~pin_mask;
out_be16(&iop->dat, cpm1_gc->cpdata);
}
static void cpm1_gpio16_set(struct gpio_chip *gc, unsigned int gpio, int value)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct cpm1_gpio16_chip *cpm1_gc = to_cpm1_gpio16_chip(mm_gc);
unsigned long flags;
u16 pin_mask = 1 << (15 - gpio);
spin_lock_irqsave(&cpm1_gc->lock, flags);
__cpm1_gpio16_set(mm_gc, pin_mask, value);
spin_unlock_irqrestore(&cpm1_gc->lock, flags);
}
static int cpm1_gpio16_dir_out(struct gpio_chip *gc, unsigned int gpio, int val)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct cpm1_gpio16_chip *cpm1_gc = to_cpm1_gpio16_chip(mm_gc);
struct cpm_ioport16 __iomem *iop = mm_gc->regs;
unsigned long flags;
u16 pin_mask = 1 << (15 - gpio);
spin_lock_irqsave(&cpm1_gc->lock, flags);
setbits16(&iop->dir, pin_mask);
__cpm1_gpio16_set(mm_gc, pin_mask, val);
spin_unlock_irqrestore(&cpm1_gc->lock, flags);
return 0;
}
static int cpm1_gpio16_dir_in(struct gpio_chip *gc, unsigned int gpio)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct cpm1_gpio16_chip *cpm1_gc = to_cpm1_gpio16_chip(mm_gc);
struct cpm_ioport16 __iomem *iop = mm_gc->regs;
unsigned long flags;
u16 pin_mask = 1 << (15 - gpio);
spin_lock_irqsave(&cpm1_gc->lock, flags);
clrbits16(&iop->dir, pin_mask);
spin_unlock_irqrestore(&cpm1_gc->lock, flags);
return 0;
}
int cpm1_gpiochip_add16(struct device_node *np)
{
struct cpm1_gpio16_chip *cpm1_gc;
struct of_mm_gpio_chip *mm_gc;
struct gpio_chip *gc;
cpm1_gc = kzalloc(sizeof(*cpm1_gc), GFP_KERNEL);
if (!cpm1_gc)
return -ENOMEM;
spin_lock_init(&cpm1_gc->lock);
mm_gc = &cpm1_gc->mm_gc;
gc = &mm_gc->gc;
mm_gc->save_regs = cpm1_gpio16_save_regs;
gc->ngpio = 16;
gc->direction_input = cpm1_gpio16_dir_in;
gc->direction_output = cpm1_gpio16_dir_out;
gc->get = cpm1_gpio16_get;
gc->set = cpm1_gpio16_set;
return of_mm_gpiochip_add(np, mm_gc);
}
static inline struct cpm1_gpio32_chip *
to_cpm1_gpio32_chip(struct of_mm_gpio_chip *mm_gc)
{
return container_of(mm_gc, struct cpm1_gpio32_chip, mm_gc);
}
static void cpm1_gpio32_save_regs(struct of_mm_gpio_chip *mm_gc)
{
struct cpm1_gpio32_chip *cpm1_gc = to_cpm1_gpio32_chip(mm_gc);
struct cpm_ioport32b __iomem *iop = mm_gc->regs;
cpm1_gc->cpdata = in_be32(&iop->dat);
}
static int cpm1_gpio32_get(struct gpio_chip *gc, unsigned int gpio)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct cpm_ioport32b __iomem *iop = mm_gc->regs;
u32 pin_mask;
pin_mask = 1 << (31 - gpio);
return !!(in_be32(&iop->dat) & pin_mask);
}
static void __cpm1_gpio32_set(struct of_mm_gpio_chip *mm_gc, u32 pin_mask,
int value)
{
struct cpm1_gpio32_chip *cpm1_gc = to_cpm1_gpio32_chip(mm_gc);
struct cpm_ioport32b __iomem *iop = mm_gc->regs;
if (value)
cpm1_gc->cpdata |= pin_mask;
else
cpm1_gc->cpdata &= ~pin_mask;
out_be32(&iop->dat, cpm1_gc->cpdata);
}
static void cpm1_gpio32_set(struct gpio_chip *gc, unsigned int gpio, int value)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct cpm1_gpio32_chip *cpm1_gc = to_cpm1_gpio32_chip(mm_gc);
unsigned long flags;
u32 pin_mask = 1 << (31 - gpio);
spin_lock_irqsave(&cpm1_gc->lock, flags);
__cpm1_gpio32_set(mm_gc, pin_mask, value);
spin_unlock_irqrestore(&cpm1_gc->lock, flags);
}
static int cpm1_gpio32_dir_out(struct gpio_chip *gc, unsigned int gpio, int val)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct cpm1_gpio32_chip *cpm1_gc = to_cpm1_gpio32_chip(mm_gc);
struct cpm_ioport32b __iomem *iop = mm_gc->regs;
unsigned long flags;
u32 pin_mask = 1 << (31 - gpio);
spin_lock_irqsave(&cpm1_gc->lock, flags);
setbits32(&iop->dir, pin_mask);
__cpm1_gpio32_set(mm_gc, pin_mask, val);
spin_unlock_irqrestore(&cpm1_gc->lock, flags);
return 0;
}
static int cpm1_gpio32_dir_in(struct gpio_chip *gc, unsigned int gpio)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct cpm1_gpio32_chip *cpm1_gc = to_cpm1_gpio32_chip(mm_gc);
struct cpm_ioport32b __iomem *iop = mm_gc->regs;
unsigned long flags;
u32 pin_mask = 1 << (31 - gpio);
spin_lock_irqsave(&cpm1_gc->lock, flags);
clrbits32(&iop->dir, pin_mask);
spin_unlock_irqrestore(&cpm1_gc->lock, flags);
return 0;
}
int cpm1_gpiochip_add32(struct device_node *np)
{
struct cpm1_gpio32_chip *cpm1_gc;
struct of_mm_gpio_chip *mm_gc;
struct gpio_chip *gc;
cpm1_gc = kzalloc(sizeof(*cpm1_gc), GFP_KERNEL);
if (!cpm1_gc)
return -ENOMEM;
spin_lock_init(&cpm1_gc->lock);
mm_gc = &cpm1_gc->mm_gc;
gc = &mm_gc->gc;
mm_gc->save_regs = cpm1_gpio32_save_regs;
gc->ngpio = 32;
gc->direction_input = cpm1_gpio32_dir_in;
gc->direction_output = cpm1_gpio32_dir_out;
gc->get = cpm1_gpio32_get;
gc->set = cpm1_gpio32_set;
return of_mm_gpiochip_add(np, mm_gc);
}
static int cpm_init_par_io(void)
{
struct device_node *np;
for_each_compatible_node(np, NULL, "fsl,cpm1-pario-bank-a")
cpm1_gpiochip_add16(np);
for_each_compatible_node(np, NULL, "fsl,cpm1-pario-bank-b")
cpm1_gpiochip_add32(np);
for_each_compatible_node(np, NULL, "fsl,cpm1-pario-bank-c")
cpm1_gpiochip_add16(np);
for_each_compatible_node(np, NULL, "fsl,cpm1-pario-bank-d")
cpm1_gpiochip_add16(np);
for_each_compatible_node(np, NULL, "fsl,cpm1-pario-bank-e")
cpm2_gpiochip_add32(np);
return 0;
}
