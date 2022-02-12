static void viper_icr_set_bit(unsigned int bit)
{
icr |= bit;
VIPER_ICR = icr;
}
static void viper_icr_clear_bit(unsigned int bit)
{
icr &= ~bit;
VIPER_ICR = icr;
}
static void viper_cf_reset(int state)
{
if (state)
viper_icr_set_bit(VIPER_ICR_CF_RST);
else
viper_icr_clear_bit(VIPER_ICR_CF_RST);
}
static u8 viper_hw_version(void)
{
u8 v1, v2;
unsigned long flags;
local_irq_save(flags);
VIPER_VERSION = 0;
v1 = VIPER_VERSION;
VIPER_VERSION = 0xff;
v2 = VIPER_VERSION;
v1 = (v1 != v2 || v1 == 0xff) ? 0 : v1;
local_irq_restore(flags);
return v1;
}
static int viper_cpu_suspend(void)
{
viper_icr_set_bit(VIPER_ICR_R_DIS);
return 0;
}
static void viper_cpu_resume(void)
{
viper_icr_clear_bit(VIPER_ICR_R_DIS);
}
static void viper_set_core_cpu_voltage(unsigned long khz, int force)
{
int i = 0;
unsigned int divisor = 0;
const char *v;
if (khz < 200000) {
v = "1.0"; divisor = 0xfff;
} else if (khz < 300000) {
v = "1.1"; divisor = 0xde5;
} else {
v = "1.3"; divisor = 0x325;
}
pr_debug("viper: setting CPU core voltage to %sV at %d.%03dMHz\n",
v, (int)khz / 1000, (int)khz % 1000);
#define STEP 0x100
do {
int step;
if (force)
step = divisor;
else if (current_voltage_divisor < divisor - STEP)
step = current_voltage_divisor + STEP;
else if (current_voltage_divisor > divisor + STEP)
step = current_voltage_divisor - STEP;
else
step = divisor;
force = 0;
gpio_set_value(VIPER_PSU_CLK_GPIO, 0);
gpio_set_value(VIPER_PSU_nCS_LD_GPIO, 0);
for (i = 1 << 11 ; i > 0 ; i >>= 1) {
udelay(1);
gpio_set_value(VIPER_PSU_DATA_GPIO, step & i);
udelay(1);
gpio_set_value(VIPER_PSU_CLK_GPIO, 1);
udelay(1);
gpio_set_value(VIPER_PSU_CLK_GPIO, 0);
}
udelay(1);
gpio_set_value(VIPER_PSU_nCS_LD_GPIO, 1);
udelay(1);
gpio_set_value(VIPER_PSU_nCS_LD_GPIO, 0);
current_voltage_divisor = step;
} while (current_voltage_divisor != divisor);
}
static inline int viper_irq_to_bitmask(unsigned int irq)
{
return viper_isa_irq_map[irq - PXA_ISA_IRQ(0)];
}
static inline int viper_bit_to_irq(int bit)
{
return viper_isa_irqs[bit] + PXA_ISA_IRQ(0);
}
static void viper_ack_irq(struct irq_data *d)
{
int viper_irq = viper_irq_to_bitmask(d->irq);
if (viper_irq & 0xff)
VIPER_LO_IRQ_STATUS = viper_irq;
else
VIPER_HI_IRQ_STATUS = (viper_irq >> 8);
}
static void viper_mask_irq(struct irq_data *d)
{
viper_irq_enabled_mask &= ~(viper_irq_to_bitmask(d->irq));
}
static void viper_unmask_irq(struct irq_data *d)
{
viper_irq_enabled_mask |= viper_irq_to_bitmask(d->irq);
}
static inline unsigned long viper_irq_pending(void)
{
return (VIPER_HI_IRQ_STATUS << 8 | VIPER_LO_IRQ_STATUS) &
viper_irq_enabled_mask;
}
static void viper_irq_handler(struct irq_desc *desc)
{
unsigned int irq;
unsigned long pending;
pending = viper_irq_pending();
do {
desc->irq_data.chip->irq_ack(&desc->irq_data);
if (likely(pending)) {
irq = viper_bit_to_irq(__ffs(pending));
generic_handle_irq(irq);
}
pending = viper_irq_pending();
} while (pending);
}
static void __init viper_init_irq(void)
{
int level;
int isa_irq;
pxa25x_init_irq();
for (level = 0; level < ARRAY_SIZE(viper_isa_irqs); level++) {
isa_irq = viper_bit_to_irq(level);
irq_set_chip_and_handler(isa_irq, &viper_irq_chip,
handle_edge_irq);
irq_clear_status_flags(isa_irq, IRQ_NOREQUEST | IRQ_NOPROBE);
}
irq_set_chained_handler(gpio_to_irq(VIPER_CPLD_GPIO),
viper_irq_handler);
irq_set_irq_type(gpio_to_irq(VIPER_CPLD_GPIO), IRQ_TYPE_EDGE_BOTH);
}
static int viper_backlight_init(struct device *dev)
{
int ret;
ret = gpio_request(VIPER_BCKLIGHT_EN_GPIO, "Backlight");
if (ret)
goto err_request_bckl;
ret = gpio_request(VIPER_LCD_EN_GPIO, "LCD");
if (ret)
goto err_request_lcd;
ret = gpio_direction_output(VIPER_BCKLIGHT_EN_GPIO, 0);
if (ret)
goto err_dir;
ret = gpio_direction_output(VIPER_LCD_EN_GPIO, 0);
if (ret)
goto err_dir;
return 0;
err_dir:
gpio_free(VIPER_LCD_EN_GPIO);
err_request_lcd:
gpio_free(VIPER_BCKLIGHT_EN_GPIO);
err_request_bckl:
dev_err(dev, "Failed to setup LCD GPIOs\n");
return ret;
}
static int viper_backlight_notify(struct device *dev, int brightness)
{
gpio_set_value(VIPER_LCD_EN_GPIO, !!brightness);
gpio_set_value(VIPER_BCKLIGHT_EN_GPIO, !!brightness);
return brightness;
}
static void viper_backlight_exit(struct device *dev)
{
gpio_free(VIPER_LCD_EN_GPIO);
gpio_free(VIPER_BCKLIGHT_EN_GPIO);
}
static void isp116x_delay(struct device *dev, int delay)
{
ndelay(delay);
}
static int __init viper_tpm_setup(char *str)
{
return kstrtoul(str, 10, &viper_tpm) >= 0;
}
static void __init viper_tpm_init(void)
{
struct platform_device *tpm_device;
struct i2c_gpio_platform_data i2c_tpm_data = {
.sda_pin = VIPER_TPM_I2C_SDA_GPIO,
.scl_pin = VIPER_TPM_I2C_SCL_GPIO,
.udelay = 10,
.timeout = HZ,
};
char *errstr;
if (!viper_tpm)
return;
tpm_device = platform_device_alloc("i2c-gpio", 2);
if (tpm_device) {
if (!platform_device_add_data(tpm_device,
&i2c_tpm_data,
sizeof(i2c_tpm_data))) {
if (platform_device_add(tpm_device)) {
errstr = "register TPM i2c bus";
goto error_free_tpm;
}
} else {
errstr = "allocate TPM i2c bus data";
goto error_free_tpm;
}
} else {
errstr = "allocate TPM i2c device";
goto error_tpm;
}
return;
error_free_tpm:
kfree(tpm_device);
error_tpm:
pr_err("viper: Couldn't %s, giving up\n", errstr);
}
static void __init viper_init_vcore_gpios(void)
{
if (gpio_request(VIPER_PSU_DATA_GPIO, "PSU data"))
goto err_request_data;
if (gpio_request(VIPER_PSU_CLK_GPIO, "PSU clock"))
goto err_request_clk;
if (gpio_request(VIPER_PSU_nCS_LD_GPIO, "PSU cs"))
goto err_request_cs;
if (gpio_direction_output(VIPER_PSU_DATA_GPIO, 0) ||
gpio_direction_output(VIPER_PSU_CLK_GPIO, 0) ||
gpio_direction_output(VIPER_PSU_nCS_LD_GPIO, 0))
goto err_dir;
viper_set_core_cpu_voltage(get_clk_frequency_khz(0), 1);
return;
err_dir:
gpio_free(VIPER_PSU_nCS_LD_GPIO);
err_request_cs:
gpio_free(VIPER_PSU_CLK_GPIO);
err_request_clk:
gpio_free(VIPER_PSU_DATA_GPIO);
err_request_data:
pr_err("viper: Failed to setup vcore control GPIOs\n");
}
static void __init viper_init_serial_gpio(void)
{
if (gpio_request(VIPER_UART_SHDN_GPIO, "UARTs shutdown"))
goto err_request;
if (gpio_direction_output(VIPER_UART_SHDN_GPIO, 0))
goto err_dir;
return;
err_dir:
gpio_free(VIPER_UART_SHDN_GPIO);
err_request:
pr_err("viper: Failed to setup UART shutdown GPIO\n");
}
static int viper_cpufreq_notifier(struct notifier_block *nb,
unsigned long val, void *data)
{
struct cpufreq_freqs *freq = data;
switch (val) {
case CPUFREQ_PRECHANGE:
if (freq->old < freq->new) {
viper_set_core_cpu_voltage(freq->new, 0);
}
break;
case CPUFREQ_POSTCHANGE:
if (freq->old > freq->new) {
viper_set_core_cpu_voltage(freq->new, 0);
}
break;
default:
break;
}
return 0;
}
static void __init viper_init_cpufreq(void)
{
if (cpufreq_register_notifier(&viper_cpufreq_notifier_block,
CPUFREQ_TRANSITION_NOTIFIER))
pr_err("viper: Failed to setup cpufreq notifier\n");
}
static inline void viper_init_cpufreq(void) {}
static void viper_power_off(void)
{
pr_notice("Shutting off UPS\n");
gpio_set_value(VIPER_UPS_GPIO, 1);
while (1);
}
static void __init viper_init(void)
{
u8 version;
pm_power_off = viper_power_off;
pxa2xx_mfp_config(ARRAY_AND_SIZE(viper_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
viper_init_serial_gpio();
pxa_set_fb_info(NULL, &fb_info);
version = viper_hw_version();
if (version == 0)
smc91x_device.num_resources--;
pxa_set_i2c_info(NULL);
platform_add_devices(viper_devs, ARRAY_SIZE(viper_devs));
viper_init_vcore_gpios();
viper_init_cpufreq();
register_syscore_ops(&viper_cpu_syscore_ops);
if (version) {
pr_info("viper: hardware v%di%d detected. "
"CPLD revision %d.\n",
VIPER_BOARD_VERSION(version),
VIPER_BOARD_ISSUE(version),
VIPER_CPLD_REVISION(version));
system_rev = (VIPER_BOARD_VERSION(version) << 8) |
(VIPER_BOARD_ISSUE(version) << 4) |
VIPER_CPLD_REVISION(version);
} else {
pr_info("viper: No version register.\n");
}
i2c_register_board_info(1, ARRAY_AND_SIZE(viper_i2c_devices));
viper_tpm_init();
pxa_set_ac97_info(NULL);
}
static void __init viper_map_io(void)
{
pxa25x_map_io();
iotable_init(viper_io_desc, ARRAY_SIZE(viper_io_desc));
PCFR |= PCFR_OPDE;
}
