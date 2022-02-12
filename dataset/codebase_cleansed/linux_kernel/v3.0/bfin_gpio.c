static void gpio_error(unsigned gpio)
{
printk(KERN_ERR "bfin-gpio: GPIO %d wasn't requested!\n", gpio);
}
static void set_label(unsigned short ident, const char *label)
{
if (label) {
strncpy(str_ident[ident].name, label,
RESOURCE_LABEL_SIZE);
str_ident[ident].name[RESOURCE_LABEL_SIZE - 1] = 0;
}
}
static char *get_label(unsigned short ident)
{
return (*str_ident[ident].name ? str_ident[ident].name : "UNKNOWN");
}
static int cmp_label(unsigned short ident, const char *label)
{
if (label == NULL) {
dump_stack();
printk(KERN_ERR "Please provide none-null label\n");
}
if (label)
return strcmp(str_ident[ident].name, label);
else
return -EINVAL;
}
inline int check_gpio(unsigned gpio)
{
#if defined(CONFIG_BF54x)
if (gpio == GPIO_PB15 || gpio == GPIO_PC14 || gpio == GPIO_PC15
|| gpio == GPIO_PH14 || gpio == GPIO_PH15
|| gpio == GPIO_PJ14 || gpio == GPIO_PJ15)
return -EINVAL;
#endif
if (gpio >= MAX_BLACKFIN_GPIOS)
return -EINVAL;
return 0;
}
static void port_setup(unsigned gpio, unsigned short usage)
{
#if defined(BF538_FAMILY)
if (gpio < MAX_BLACKFIN_GPIOS || gpio >= MAX_RESOURCES)
return;
gpio -= MAX_BLACKFIN_GPIOS;
if (usage == GPIO_USAGE)
*port_fer[gpio_bank(gpio)] |= gpio_bit(gpio);
else
*port_fer[gpio_bank(gpio)] &= ~gpio_bit(gpio);
SSYNC();
return;
#endif
if (check_gpio(gpio))
return;
#if defined(CONFIG_BF52x) || defined(BF537_FAMILY) || defined(CONFIG_BF51x)
if (usage == GPIO_USAGE)
*port_fer[gpio_bank(gpio)] &= ~gpio_bit(gpio);
else
*port_fer[gpio_bank(gpio)] |= gpio_bit(gpio);
SSYNC();
#elif defined(CONFIG_BF54x)
if (usage == GPIO_USAGE)
gpio_array[gpio_bank(gpio)]->port_fer &= ~gpio_bit(gpio);
else
gpio_array[gpio_bank(gpio)]->port_fer |= gpio_bit(gpio);
SSYNC();
#endif
}
static int portmux_group_check(unsigned short per)
{
u16 ident = P_IDENT(per);
u16 function = P_FUNCT2MUX(per);
s8 offset = port_mux[ident];
u16 m, pmux, pfunc;
if (offset < 0)
return 0;
pmux = bfin_read_PORT_MUX();
for (m = 0; m < ARRAY_SIZE(port_mux); ++m) {
if (m == ident)
continue;
if (port_mux[m] != offset)
continue;
if (!is_reserved(peri, m, 1))
continue;
if (offset == 1)
pfunc = (pmux >> offset) & 3;
else
pfunc = (pmux >> offset) & 1;
if (pfunc != function) {
pr_err("pin group conflict! request pin %d func %d conflict with pin %d func %d\n",
ident, function, m, pfunc);
return -EINVAL;
}
}
return 0;
}
static void portmux_setup(unsigned short per)
{
u16 ident = P_IDENT(per);
u16 function = P_FUNCT2MUX(per);
s8 offset = port_mux[ident];
u16 pmux;
if (offset == -1)
return;
pmux = bfin_read_PORT_MUX();
if (offset != 1)
pmux &= ~(1 << offset);
else
pmux &= ~(3 << 1);
pmux |= (function << offset);
bfin_write_PORT_MUX(pmux);
}
inline void portmux_setup(unsigned short per)
{
u16 ident = P_IDENT(per);
u16 function = P_FUNCT2MUX(per);
u32 pmux;
pmux = gpio_array[gpio_bank(ident)]->port_mux;
pmux &= ~(0x3 << (2 * gpio_sub_n(ident)));
pmux |= (function & 0x3) << (2 * gpio_sub_n(ident));
gpio_array[gpio_bank(ident)]->port_mux = pmux;
}
inline u16 get_portmux(unsigned short per)
{
u16 ident = P_IDENT(per);
u32 pmux = gpio_array[gpio_bank(ident)]->port_mux;
return (pmux >> (2 * gpio_sub_n(ident)) & 0x3);
}
static int portmux_group_check(unsigned short per)
{
return 0;
}
static int portmux_group_check(unsigned short per)
{
u16 ident = P_IDENT(per);
u16 function = P_FUNCT2MUX(per);
u8 offset = pmux_offset[gpio_bank(ident)][gpio_sub_n(ident)];
u16 pin, gpiopin, pfunc;
for (pin = 0; pin < GPIO_BANKSIZE; ++pin) {
if (offset != pmux_offset[gpio_bank(ident)][pin])
continue;
gpiopin = gpio_bank(ident) * GPIO_BANKSIZE + pin;
if (gpiopin == ident)
continue;
if (!is_reserved(peri, gpiopin, 1))
continue;
pfunc = *port_mux[gpio_bank(ident)];
pfunc = (pfunc >> offset) & 3;
if (pfunc != function) {
pr_err("pin group conflict! request pin %d func %d conflict with pin %d func %d\n",
ident, function, gpiopin, pfunc);
return -EINVAL;
}
}
return 0;
}
inline void portmux_setup(unsigned short per)
{
u16 ident = P_IDENT(per);
u16 function = P_FUNCT2MUX(per);
u8 offset = pmux_offset[gpio_bank(ident)][gpio_sub_n(ident)];
u16 pmux;
pmux = *port_mux[gpio_bank(ident)];
if (((pmux >> offset) & 3) == function)
return;
pmux &= ~(3 << offset);
pmux |= (function & 3) << offset;
*port_mux[gpio_bank(ident)] = pmux;
SSYNC();
}
static int portmux_group_check(unsigned short per)
{
return 0;
}
void set_gpio_toggle(unsigned gpio)
{
unsigned long flags;
if (ANOMALY_05000311 || ANOMALY_05000323)
flags = hard_local_irq_save();
gpio_array[gpio_bank(gpio)]->toggle = gpio_bit(gpio);
if (ANOMALY_05000311 || ANOMALY_05000323) {
AWA_DUMMY_READ(toggle);
hard_local_irq_restore(flags);
}
}
int gpio_pm_wakeup_ctrl(unsigned gpio, unsigned ctrl)
{
unsigned long flags;
if (check_gpio(gpio) < 0)
return -EINVAL;
flags = hard_local_irq_save();
if (ctrl)
reserve(wakeup, gpio);
else
unreserve(wakeup, gpio);
set_gpio_maskb(gpio, ctrl);
hard_local_irq_restore(flags);
return 0;
}
int bfin_pm_standby_ctrl(unsigned ctrl)
{
u16 bank, mask, i;
for (i = 0; i < MAX_BLACKFIN_GPIOS; i += GPIO_BANKSIZE) {
mask = map_entry(wakeup, i);
bank = gpio_bank(i);
if (mask)
bfin_internal_set_wake(sic_iwr_irqs[bank], ctrl);
}
return 0;
}
void bfin_gpio_pm_hibernate_suspend(void)
{
int i, bank;
for (i = 0; i < MAX_BLACKFIN_GPIOS; i += GPIO_BANKSIZE) {
bank = gpio_bank(i);
#if defined(CONFIG_BF52x) || defined(BF537_FAMILY) || defined(CONFIG_BF51x)
gpio_bank_saved[bank].fer = *port_fer[bank];
#if defined(CONFIG_BF52x) || defined(CONFIG_BF51x)
gpio_bank_saved[bank].mux = *port_mux[bank];
#else
if (bank == 0)
gpio_bank_saved[bank].mux = bfin_read_PORT_MUX();
#endif
#endif
gpio_bank_saved[bank].data = gpio_array[bank]->data;
gpio_bank_saved[bank].inen = gpio_array[bank]->inen;
gpio_bank_saved[bank].polar = gpio_array[bank]->polar;
gpio_bank_saved[bank].dir = gpio_array[bank]->dir;
gpio_bank_saved[bank].edge = gpio_array[bank]->edge;
gpio_bank_saved[bank].both = gpio_array[bank]->both;
gpio_bank_saved[bank].maska = gpio_array[bank]->maska;
}
AWA_DUMMY_READ(maska);
}
void bfin_gpio_pm_hibernate_restore(void)
{
int i, bank;
for (i = 0; i < MAX_BLACKFIN_GPIOS; i += GPIO_BANKSIZE) {
bank = gpio_bank(i);
#if defined(CONFIG_BF52x) || defined(BF537_FAMILY) || defined(CONFIG_BF51x)
#if defined(CONFIG_BF52x) || defined(CONFIG_BF51x)
*port_mux[bank] = gpio_bank_saved[bank].mux;
#else
if (bank == 0)
bfin_write_PORT_MUX(gpio_bank_saved[bank].mux);
#endif
*port_fer[bank] = gpio_bank_saved[bank].fer;
#endif
gpio_array[bank]->inen = gpio_bank_saved[bank].inen;
gpio_array[bank]->data_set = gpio_bank_saved[bank].data
& gpio_bank_saved[bank].dir;
gpio_array[bank]->dir = gpio_bank_saved[bank].dir;
gpio_array[bank]->polar = gpio_bank_saved[bank].polar;
gpio_array[bank]->edge = gpio_bank_saved[bank].edge;
gpio_array[bank]->both = gpio_bank_saved[bank].both;
gpio_array[bank]->maska = gpio_bank_saved[bank].maska;
}
AWA_DUMMY_READ(maska);
}
int bfin_pm_standby_ctrl(unsigned ctrl)
{
return 0;
}
void bfin_gpio_pm_hibernate_suspend(void)
{
int i, bank;
for (i = 0; i < MAX_BLACKFIN_GPIOS; i += GPIO_BANKSIZE) {
bank = gpio_bank(i);
gpio_bank_saved[bank].fer = gpio_array[bank]->port_fer;
gpio_bank_saved[bank].mux = gpio_array[bank]->port_mux;
gpio_bank_saved[bank].data = gpio_array[bank]->data;
gpio_bank_saved[bank].inen = gpio_array[bank]->inen;
gpio_bank_saved[bank].dir = gpio_array[bank]->dir_set;
}
}
void bfin_gpio_pm_hibernate_restore(void)
{
int i, bank;
for (i = 0; i < MAX_BLACKFIN_GPIOS; i += GPIO_BANKSIZE) {
bank = gpio_bank(i);
gpio_array[bank]->port_mux = gpio_bank_saved[bank].mux;
gpio_array[bank]->port_fer = gpio_bank_saved[bank].fer;
gpio_array[bank]->inen = gpio_bank_saved[bank].inen;
gpio_array[bank]->dir_set = gpio_bank_saved[bank].dir;
gpio_array[bank]->data_set = gpio_bank_saved[bank].data
| gpio_bank_saved[bank].dir;
}
}
unsigned short get_gpio_dir(unsigned gpio)
{
return (0x01 & (gpio_array[gpio_bank(gpio)]->dir_clear >> gpio_sub_n(gpio)));
}
int peripheral_request_list(const unsigned short per[], const char *label)
{
u16 cnt;
int ret;
for (cnt = 0; per[cnt] != 0; cnt++) {
ret = peripheral_request(per[cnt], label);
if (ret < 0) {
for ( ; cnt > 0; cnt--)
peripheral_free(per[cnt - 1]);
return ret;
}
}
return 0;
}
void peripheral_free(unsigned short per)
{
unsigned long flags;
unsigned short ident = P_IDENT(per);
if (per & P_DONTCARE)
return;
if (!(per & P_DEFINED))
return;
flags = hard_local_irq_save();
if (unlikely(!is_reserved(peri, ident, 0))) {
hard_local_irq_restore(flags);
return;
}
if (!(per & P_MAYSHARE))
port_setup(ident, GPIO_USAGE);
unreserve(peri, ident);
set_label(ident, "free");
hard_local_irq_restore(flags);
}
void peripheral_free_list(const unsigned short per[])
{
u16 cnt;
for (cnt = 0; per[cnt] != 0; cnt++)
peripheral_free(per[cnt]);
}
int bfin_gpio_request(unsigned gpio, const char *label)
{
unsigned long flags;
if (check_gpio(gpio) < 0)
return -EINVAL;
flags = hard_local_irq_save();
if (cmp_label(gpio, label) == 0) {
hard_local_irq_restore(flags);
return 0;
}
if (unlikely(is_reserved(gpio, gpio, 1))) {
if (system_state == SYSTEM_BOOTING)
dump_stack();
printk(KERN_ERR "bfin-gpio: GPIO %d is already reserved by %s !\n",
gpio, get_label(gpio));
hard_local_irq_restore(flags);
return -EBUSY;
}
if (unlikely(is_reserved(peri, gpio, 1))) {
if (system_state == SYSTEM_BOOTING)
dump_stack();
printk(KERN_ERR
"bfin-gpio: GPIO %d is already reserved as Peripheral by %s !\n",
gpio, get_label(gpio));
hard_local_irq_restore(flags);
return -EBUSY;
}
if (unlikely(is_reserved(gpio_irq, gpio, 1))) {
printk(KERN_NOTICE "bfin-gpio: GPIO %d is already reserved as gpio-irq!"
" (Documentation/blackfin/bfin-gpio-notes.txt)\n", gpio);
}
#ifndef CONFIG_BF54x
else {
set_gpio_polar(gpio, 0);
}
#endif
reserve(gpio, gpio);
set_label(gpio, label);
hard_local_irq_restore(flags);
port_setup(gpio, GPIO_USAGE);
return 0;
}
void bfin_gpio_free(unsigned gpio)
{
unsigned long flags;
if (check_gpio(gpio) < 0)
return;
might_sleep();
flags = hard_local_irq_save();
if (unlikely(!is_reserved(gpio, gpio, 0))) {
if (system_state == SYSTEM_BOOTING)
dump_stack();
gpio_error(gpio);
hard_local_irq_restore(flags);
return;
}
unreserve(gpio, gpio);
set_label(gpio, "free");
hard_local_irq_restore(flags);
}
int bfin_special_gpio_request(unsigned gpio, const char *label)
{
unsigned long flags;
flags = hard_local_irq_save();
if (cmp_label(gpio, label) == 0) {
hard_local_irq_restore(flags);
return 0;
}
if (unlikely(is_reserved(special_gpio, gpio, 1))) {
hard_local_irq_restore(flags);
printk(KERN_ERR "bfin-gpio: GPIO %d is already reserved by %s !\n",
gpio, get_label(gpio));
return -EBUSY;
}
if (unlikely(is_reserved(peri, gpio, 1))) {
hard_local_irq_restore(flags);
printk(KERN_ERR
"bfin-gpio: GPIO %d is already reserved as Peripheral by %s !\n",
gpio, get_label(gpio));
return -EBUSY;
}
reserve(special_gpio, gpio);
reserve(peri, gpio);
set_label(gpio, label);
hard_local_irq_restore(flags);
port_setup(gpio, GPIO_USAGE);
return 0;
}
void bfin_special_gpio_free(unsigned gpio)
{
unsigned long flags;
might_sleep();
flags = hard_local_irq_save();
if (unlikely(!is_reserved(special_gpio, gpio, 0))) {
gpio_error(gpio);
hard_local_irq_restore(flags);
return;
}
unreserve(special_gpio, gpio);
unreserve(peri, gpio);
set_label(gpio, "free");
hard_local_irq_restore(flags);
}
int bfin_gpio_irq_request(unsigned gpio, const char *label)
{
unsigned long flags;
if (check_gpio(gpio) < 0)
return -EINVAL;
flags = hard_local_irq_save();
if (unlikely(is_reserved(peri, gpio, 1))) {
if (system_state == SYSTEM_BOOTING)
dump_stack();
printk(KERN_ERR
"bfin-gpio: GPIO %d is already reserved as Peripheral by %s !\n",
gpio, get_label(gpio));
hard_local_irq_restore(flags);
return -EBUSY;
}
if (unlikely(is_reserved(gpio, gpio, 1)))
printk(KERN_NOTICE "bfin-gpio: GPIO %d is already reserved by %s! "
"(Documentation/blackfin/bfin-gpio-notes.txt)\n",
gpio, get_label(gpio));
reserve(gpio_irq, gpio);
set_label(gpio, label);
hard_local_irq_restore(flags);
port_setup(gpio, GPIO_USAGE);
return 0;
}
void bfin_gpio_irq_free(unsigned gpio)
{
unsigned long flags;
if (check_gpio(gpio) < 0)
return;
flags = hard_local_irq_save();
if (unlikely(!is_reserved(gpio_irq, gpio, 0))) {
if (system_state == SYSTEM_BOOTING)
dump_stack();
gpio_error(gpio);
hard_local_irq_restore(flags);
return;
}
unreserve(gpio_irq, gpio);
set_label(gpio, "free");
hard_local_irq_restore(flags);
}
static inline void __bfin_gpio_direction_input(unsigned gpio)
{
#ifdef CONFIG_BF54x
gpio_array[gpio_bank(gpio)]->dir_clear = gpio_bit(gpio);
#else
gpio_array[gpio_bank(gpio)]->dir &= ~gpio_bit(gpio);
#endif
gpio_array[gpio_bank(gpio)]->inen |= gpio_bit(gpio);
}
int bfin_gpio_direction_input(unsigned gpio)
{
unsigned long flags;
if (unlikely(!is_reserved(gpio, gpio, 0))) {
gpio_error(gpio);
return -EINVAL;
}
flags = hard_local_irq_save();
__bfin_gpio_direction_input(gpio);
AWA_DUMMY_READ(inen);
hard_local_irq_restore(flags);
return 0;
}
void bfin_gpio_irq_prepare(unsigned gpio)
{
#ifdef CONFIG_BF54x
unsigned long flags;
#endif
port_setup(gpio, GPIO_USAGE);
#ifdef CONFIG_BF54x
flags = hard_local_irq_save();
__bfin_gpio_direction_input(gpio);
hard_local_irq_restore(flags);
#endif
}
void bfin_gpio_set_value(unsigned gpio, int arg)
{
if (arg)
gpio_array[gpio_bank(gpio)]->data_set = gpio_bit(gpio);
else
gpio_array[gpio_bank(gpio)]->data_clear = gpio_bit(gpio);
}
int bfin_gpio_direction_output(unsigned gpio, int value)
{
unsigned long flags;
if (unlikely(!is_reserved(gpio, gpio, 0))) {
gpio_error(gpio);
return -EINVAL;
}
flags = hard_local_irq_save();
gpio_array[gpio_bank(gpio)]->inen &= ~gpio_bit(gpio);
gpio_set_value(gpio, value);
#ifdef CONFIG_BF54x
gpio_array[gpio_bank(gpio)]->dir_set = gpio_bit(gpio);
#else
gpio_array[gpio_bank(gpio)]->dir |= gpio_bit(gpio);
#endif
AWA_DUMMY_READ(dir);
hard_local_irq_restore(flags);
return 0;
}
int bfin_gpio_get_value(unsigned gpio)
{
#ifdef CONFIG_BF54x
return (1 & (gpio_array[gpio_bank(gpio)]->data >> gpio_sub_n(gpio)));
#else
unsigned long flags;
if (unlikely(get_gpio_edge(gpio))) {
int ret;
flags = hard_local_irq_save();
set_gpio_edge(gpio, 0);
ret = get_gpio_data(gpio);
set_gpio_edge(gpio, 1);
hard_local_irq_restore(flags);
return ret;
} else
return get_gpio_data(gpio);
#endif
}
void bfin_reset_boot_spi_cs(unsigned short pin)
{
unsigned short gpio = P_IDENT(pin);
port_setup(gpio, GPIO_USAGE);
gpio_array[gpio_bank(gpio)]->data_set = gpio_bit(gpio);
AWA_DUMMY_READ(data_set);
udelay(1);
}
static int gpio_proc_show(struct seq_file *m, void *v)
{
int c, irq, gpio;
for (c = 0; c < MAX_RESOURCES; c++) {
irq = is_reserved(gpio_irq, c, 1);
gpio = is_reserved(gpio, c, 1);
if (!check_gpio(c) && (gpio || irq))
seq_printf(m, "GPIO_%d: \t%s%s \t\tGPIO %s\n", c,
get_label(c), (gpio && irq) ? " *" : "",
get_gpio_dir(c) ? "OUTPUT" : "INPUT");
else if (is_reserved(peri, c, 1))
seq_printf(m, "GPIO_%d: \t%s \t\tPeripheral\n", c, get_label(c));
else
continue;
}
return 0;
}
static int gpio_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, gpio_proc_show, NULL);
}
static __init int gpio_register_proc(void)
{
struct proc_dir_entry *proc_gpio;
proc_gpio = proc_create("gpio", S_IRUGO, NULL, &gpio_proc_ops);
return proc_gpio != NULL;
}
static int bfin_gpiolib_direction_input(struct gpio_chip *chip, unsigned gpio)
{
return bfin_gpio_direction_input(gpio);
}
static int bfin_gpiolib_direction_output(struct gpio_chip *chip, unsigned gpio, int level)
{
return bfin_gpio_direction_output(gpio, level);
}
static int bfin_gpiolib_get_value(struct gpio_chip *chip, unsigned gpio)
{
return bfin_gpio_get_value(gpio);
}
static void bfin_gpiolib_set_value(struct gpio_chip *chip, unsigned gpio, int value)
{
return bfin_gpio_set_value(gpio, value);
}
static int bfin_gpiolib_gpio_request(struct gpio_chip *chip, unsigned gpio)
{
return bfin_gpio_request(gpio, chip->label);
}
static void bfin_gpiolib_gpio_free(struct gpio_chip *chip, unsigned gpio)
{
return bfin_gpio_free(gpio);
}
static int bfin_gpiolib_gpio_to_irq(struct gpio_chip *chip, unsigned gpio)
{
return gpio + GPIO_IRQ_BASE;
}
static int __init bfin_gpiolib_setup(void)
{
return gpiochip_add(&bfin_chip);
}
