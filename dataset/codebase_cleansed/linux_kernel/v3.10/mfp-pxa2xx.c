static int __mfp_config_gpio(unsigned gpio, unsigned long c)
{
unsigned long gafr, mask = GPIO_bit(gpio);
int bank = gpio_to_bank(gpio);
int uorl = !!(gpio & 0x10);
int shft = (gpio & 0xf) << 1;
int fn = MFP_AF(c);
int is_out = (c & MFP_DIR_OUT) ? 1 : 0;
if (fn > 3)
return -EINVAL;
gafr = (uorl == 0) ? GAFR_L(bank) : GAFR_U(bank);
gafr = (gafr & ~(0x3 << shft)) | (fn << shft);
if (uorl == 0)
GAFR_L(bank) = gafr;
else
GAFR_U(bank) = gafr;
if (is_out ^ gpio_desc[gpio].dir_inverted)
GPDR(gpio) |= mask;
else
GPDR(gpio) &= ~mask;
switch (c & MFP_LPM_STATE_MASK) {
case MFP_LPM_DRIVE_HIGH:
PGSR(bank) |= mask;
is_out = 1;
break;
case MFP_LPM_DRIVE_LOW:
PGSR(bank) &= ~mask;
is_out = 1;
break;
case MFP_LPM_INPUT:
case MFP_LPM_DEFAULT:
break;
default:
pr_warning("%s: GPIO%d: unsupported low power mode\n",
__func__, gpio);
break;
}
if (is_out ^ gpio_desc[gpio].dir_inverted)
gpdr_lpm[bank] |= mask;
else
gpdr_lpm[bank] &= ~mask;
if ((c & MFP_LPM_CAN_WAKEUP) && !gpio_desc[gpio].can_wakeup) {
pr_warning("%s: GPIO%d unable to wakeup\n",
__func__, gpio);
return -EINVAL;
}
if ((c & MFP_LPM_CAN_WAKEUP) && is_out) {
pr_warning("%s: output GPIO%d unable to wakeup\n",
__func__, gpio);
return -EINVAL;
}
return 0;
}
static inline int __mfp_validate(int mfp)
{
int gpio = mfp_to_gpio(mfp);
if ((mfp > MFP_PIN_GPIO127) || !gpio_desc[gpio].valid) {
pr_warning("%s: GPIO%d is invalid pin\n", __func__, gpio);
return -1;
}
return gpio;
}
void pxa2xx_mfp_config(unsigned long *mfp_cfgs, int num)
{
unsigned long flags;
unsigned long *c;
int i, gpio;
for (i = 0, c = mfp_cfgs; i < num; i++, c++) {
gpio = __mfp_validate(MFP_PIN(*c));
if (gpio < 0)
continue;
local_irq_save(flags);
gpio_desc[gpio].config = *c;
__mfp_config_gpio(gpio, *c);
local_irq_restore(flags);
}
}
void pxa2xx_mfp_set_lpm(int mfp, unsigned long lpm)
{
unsigned long flags, c;
int gpio;
gpio = __mfp_validate(mfp);
if (gpio < 0)
return;
local_irq_save(flags);
c = gpio_desc[gpio].config;
c = (c & ~MFP_LPM_STATE_MASK) | lpm;
__mfp_config_gpio(gpio, c);
local_irq_restore(flags);
}
int gpio_set_wake(unsigned int gpio, unsigned int on)
{
struct gpio_desc *d;
unsigned long c, mux_taken;
if (gpio > mfp_to_gpio(MFP_PIN_GPIO127))
return -EINVAL;
d = &gpio_desc[gpio];
c = d->config;
if (!d->valid)
return -EINVAL;
if (d->keypad_gpio && (MFP_AF(d->config) == 0) &&
(d->config & MFP_LPM_CAN_WAKEUP)) {
if (on)
PKWR |= d->mask;
else
PKWR &= ~d->mask;
return 0;
}
mux_taken = (PWER & d->mux_mask) & (~d->mask);
if (on && mux_taken)
return -EBUSY;
if (d->can_wakeup && (c & MFP_LPM_CAN_WAKEUP)) {
if (on) {
PWER = (PWER & ~d->mux_mask) | d->mask;
if (c & MFP_LPM_EDGE_RISE)
PRER |= d->mask;
else
PRER &= ~d->mask;
if (c & MFP_LPM_EDGE_FALL)
PFER |= d->mask;
else
PFER &= ~d->mask;
} else {
PWER &= ~d->mask;
PRER &= ~d->mask;
PFER &= ~d->mask;
}
}
return 0;
}
static void __init pxa25x_mfp_init(void)
{
int i;
#ifdef CONFIG_CPU_PXA26x
pxa_last_gpio = 89;
#else
pxa_last_gpio = 84;
#endif
for (i = 0; i <= pxa_last_gpio; i++)
gpio_desc[i].valid = 1;
for (i = 0; i <= 15; i++) {
gpio_desc[i].can_wakeup = 1;
gpio_desc[i].mask = GPIO_bit(i);
}
for (i = 86; i <= pxa_last_gpio; i++)
gpio_desc[i].dir_inverted = 1;
}
static inline void pxa25x_mfp_init(void) {}
int keypad_set_wake(unsigned int on)
{
unsigned int i, gpio, mask = 0;
struct gpio_desc *d;
for (i = 0; i < ARRAY_SIZE(pxa27x_pkwr_gpio); i++) {
gpio = pxa27x_pkwr_gpio[i];
d = &gpio_desc[gpio];
if (MFP_AF(d->config) == 0)
continue;
if (d->config & MFP_LPM_CAN_WAKEUP)
mask |= gpio_desc[gpio].mask;
}
if (on)
PKWR |= mask;
else
PKWR &= ~mask;
return 0;
}
static void __init pxa27x_mfp_init(void)
{
int i, gpio;
pxa_last_gpio = 120;
for (i = 0; i <= pxa_last_gpio; i++) {
if (i == 2 || i == 5 || i == 6 || i == 7 || i == 8)
continue;
gpio_desc[i].valid = 1;
}
for (i = 0; i < ARRAY_SIZE(pxa27x_pkwr_gpio); i++) {
gpio = pxa27x_pkwr_gpio[i];
gpio_desc[gpio].can_wakeup = 1;
gpio_desc[gpio].keypad_gpio = 1;
gpio_desc[gpio].mask = 1 << i;
}
for (i = 0; i <= 15; i++) {
if (GPIO_bit(i) & 0x1e4)
continue;
gpio_desc[i].can_wakeup = 1;
gpio_desc[i].mask = GPIO_bit(i);
}
gpio_desc[35].can_wakeup = 1;
gpio_desc[35].mask = PWER_WE35;
INIT_GPIO_DESC_MUXED(WEMUX3, 31);
INIT_GPIO_DESC_MUXED(WEMUX3, 113);
INIT_GPIO_DESC_MUXED(WEMUX2, 38);
INIT_GPIO_DESC_MUXED(WEMUX2, 53);
INIT_GPIO_DESC_MUXED(WEMUX2, 40);
INIT_GPIO_DESC_MUXED(WEMUX2, 36);
}
static inline void pxa27x_mfp_init(void) {}
static int pxa2xx_mfp_suspend(void)
{
int i;
for (i = 0; i < pxa_last_gpio; i++) {
if ((gpio_desc[i].config & MFP_LPM_KEEP_OUTPUT) &&
(GPDR(i) & GPIO_bit(i))) {
if (GPLR(i) & GPIO_bit(i))
PGSR(gpio_to_bank(i)) |= GPIO_bit(i);
else
PGSR(gpio_to_bank(i)) &= ~GPIO_bit(i);
}
}
for (i = 0; i <= gpio_to_bank(pxa_last_gpio); i++) {
saved_gafr[0][i] = GAFR_L(i);
saved_gafr[1][i] = GAFR_U(i);
saved_gpdr[i] = GPDR(i * 32);
saved_gplr[i] = GPLR(i * 32);
saved_pgsr[i] = PGSR(i);
GPSR(i * 32) = PGSR(i);
GPCR(i * 32) = ~PGSR(i);
}
for (i = 0; i < pxa_last_gpio; i++) {
if ((gpdr_lpm[gpio_to_bank(i)] & GPIO_bit(i)) ||
((gpio_desc[i].config & MFP_LPM_KEEP_OUTPUT) &&
(saved_gpdr[gpio_to_bank(i)] & GPIO_bit(i))))
GPDR(i) |= GPIO_bit(i);
else
GPDR(i) &= ~GPIO_bit(i);
}
return 0;
}
static void pxa2xx_mfp_resume(void)
{
int i;
for (i = 0; i <= gpio_to_bank(pxa_last_gpio); i++) {
GAFR_L(i) = saved_gafr[0][i];
GAFR_U(i) = saved_gafr[1][i];
GPSR(i * 32) = saved_gplr[i];
GPCR(i * 32) = ~saved_gplr[i];
GPDR(i * 32) = saved_gpdr[i];
PGSR(i) = saved_pgsr[i];
}
PSSR = PSSR_RDH | PSSR_PH;
}
static int __init pxa2xx_mfp_init(void)
{
int i;
if (!cpu_is_pxa2xx())
return 0;
if (cpu_is_pxa25x())
pxa25x_mfp_init();
if (cpu_is_pxa27x())
pxa27x_mfp_init();
PSSR = PSSR_RDH;
for (i = 0; i <= gpio_to_bank(pxa_last_gpio); i++)
gpdr_lpm[i] = GPDR(i * 32);
return 0;
}
