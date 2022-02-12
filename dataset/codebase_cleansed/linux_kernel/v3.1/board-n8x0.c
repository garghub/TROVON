static int tusb_set_power(int state)
{
int i, retval = 0;
if (state) {
gpio_set_value(TUSB6010_GPIO_ENABLE, 1);
msleep(1);
i = 100;
while (i && gpio_get_value(TUSB6010_GPIO_INT)) {
msleep(1);
i--;
}
if (!i) {
printk(KERN_ERR "tusb: powerup failed\n");
retval = -ENODEV;
}
} else {
gpio_set_value(TUSB6010_GPIO_ENABLE, 0);
msleep(10);
}
return retval;
}
static void __init n8x0_usb_init(void)
{
int ret = 0;
static char announce[] __initdata = KERN_INFO "TUSB 6010\n";
ret = gpio_request_one(TUSB6010_GPIO_ENABLE, GPIOF_OUT_INIT_LOW,
"TUSB6010 enable");
if (ret != 0) {
printk(KERN_ERR "Could not get TUSB power GPIO%i\n",
TUSB6010_GPIO_ENABLE);
return;
}
tusb_set_power(0);
ret = tusb6010_setup_interface(&tusb_data, TUSB6010_REFCLK_19, 2,
TUSB6010_ASYNC_CS, TUSB6010_SYNC_CS,
TUSB6010_GPIO_INT, TUSB6010_DMACHAN);
if (ret != 0)
goto err;
printk(announce);
return;
err:
gpio_free(TUSB6010_GPIO_ENABLE);
}
static void __init n8x0_usb_init(void) {}
static int n8x0_mmc_switch_slot(struct device *dev, int slot)
{
#ifdef CONFIG_MMC_DEBUG
dev_dbg(dev, "Choose slot %d\n", slot + 1);
#endif
gpio_set_value(N8X0_SLOT_SWITCH_GPIO, slot);
return 0;
}
static int n8x0_mmc_set_power_menelaus(struct device *dev, int slot,
int power_on, int vdd)
{
int mV;
#ifdef CONFIG_MMC_DEBUG
dev_dbg(dev, "Set slot %d power: %s (vdd %d)\n", slot + 1,
power_on ? "on" : "off", vdd);
#endif
if (slot == 0) {
if (!power_on)
return menelaus_set_vmmc(0);
switch (1 << vdd) {
case MMC_VDD_33_34:
case MMC_VDD_32_33:
case MMC_VDD_31_32:
mV = 3100;
break;
case MMC_VDD_30_31:
mV = 3000;
break;
case MMC_VDD_28_29:
mV = 2800;
break;
case MMC_VDD_165_195:
mV = 1850;
break;
default:
BUG();
}
return menelaus_set_vmmc(mV);
} else {
if (!power_on)
return menelaus_set_vdcdc(3, 0);
switch (1 << vdd) {
case MMC_VDD_33_34:
case MMC_VDD_32_33:
mV = 3300;
break;
case MMC_VDD_30_31:
case MMC_VDD_29_30:
mV = 3000;
break;
case MMC_VDD_28_29:
case MMC_VDD_27_28:
mV = 2800;
break;
case MMC_VDD_24_25:
case MMC_VDD_23_24:
mV = 2400;
break;
case MMC_VDD_22_23:
case MMC_VDD_21_22:
mV = 2200;
break;
case MMC_VDD_20_21:
mV = 2000;
break;
case MMC_VDD_165_195:
mV = 1800;
break;
default:
BUG();
}
return menelaus_set_vdcdc(3, mV);
}
return 0;
}
static void n810_set_power_emmc(struct device *dev,
int power_on)
{
dev_dbg(dev, "Set EMMC power %s\n", power_on ? "on" : "off");
if (power_on) {
gpio_set_value(N810_EMMC_VSD_GPIO, 1);
msleep(1);
gpio_set_value(N810_EMMC_VIO_GPIO, 1);
msleep(1);
} else {
gpio_set_value(N810_EMMC_VIO_GPIO, 0);
msleep(50);
gpio_set_value(N810_EMMC_VSD_GPIO, 0);
msleep(50);
}
}
static int n8x0_mmc_set_power(struct device *dev, int slot, int power_on,
int vdd)
{
if (machine_is_nokia_n800() || slot == 0)
return n8x0_mmc_set_power_menelaus(dev, slot, power_on, vdd);
n810_set_power_emmc(dev, power_on);
return 0;
}
static int n8x0_mmc_set_bus_mode(struct device *dev, int slot, int bus_mode)
{
int r;
dev_dbg(dev, "Set slot %d bus mode %s\n", slot + 1,
bus_mode == MMC_BUSMODE_OPENDRAIN ? "open-drain" : "push-pull");
BUG_ON(slot != 0 && slot != 1);
slot++;
switch (bus_mode) {
case MMC_BUSMODE_OPENDRAIN:
r = menelaus_set_mmc_opendrain(slot, 1);
break;
case MMC_BUSMODE_PUSHPULL:
r = menelaus_set_mmc_opendrain(slot, 0);
break;
default:
BUG();
}
if (r != 0 && printk_ratelimit())
dev_err(dev, "MMC: unable to set bus mode for slot %d\n",
slot);
return r;
}
static int n8x0_mmc_get_cover_state(struct device *dev, int slot)
{
slot++;
BUG_ON(slot != 1 && slot != 2);
if (slot == 1)
return slot1_cover_open;
else
return slot2_cover_open;
}
static void n8x0_mmc_callback(void *data, u8 card_mask)
{
int bit, *openp, index;
if (machine_is_nokia_n800()) {
bit = 1 << 1;
openp = &slot2_cover_open;
index = 1;
} else {
bit = 1;
openp = &slot1_cover_open;
index = 0;
}
if (card_mask & bit)
*openp = 1;
else
*openp = 0;
omap_mmc_notify_cover_event(mmc_device, index, *openp);
}
static int n8x0_mmc_late_init(struct device *dev)
{
int r, bit, *openp;
int vs2sel;
mmc_device = dev;
r = menelaus_set_slot_sel(1);
if (r < 0)
return r;
if (machine_is_nokia_n800())
vs2sel = 0;
else
vs2sel = 2;
r = menelaus_set_mmc_slot(2, 0, vs2sel, 1);
if (r < 0)
return r;
n8x0_mmc_set_power(dev, 0, MMC_POWER_ON, 16);
n8x0_mmc_set_power(dev, 1, MMC_POWER_ON, 16);
r = menelaus_set_mmc_slot(1, 1, 0, 1);
if (r < 0)
return r;
r = menelaus_set_mmc_slot(2, 1, vs2sel, 1);
if (r < 0)
return r;
r = menelaus_get_slot_pin_states();
if (r < 0)
return r;
if (machine_is_nokia_n800()) {
bit = 1 << 1;
openp = &slot2_cover_open;
} else {
bit = 1;
openp = &slot1_cover_open;
slot2_cover_open = 0;
}
if (r == 0xf || r == (0xf & ~bit))
r = ~r;
if (r & bit)
*openp = 1;
else
*openp = 0;
r = menelaus_register_mmc_callback(n8x0_mmc_callback, NULL);
return r;
}
static void n8x0_mmc_shutdown(struct device *dev)
{
int vs2sel;
if (machine_is_nokia_n800())
vs2sel = 0;
else
vs2sel = 2;
menelaus_set_mmc_slot(1, 0, 0, 0);
menelaus_set_mmc_slot(2, 0, vs2sel, 0);
}
static void n8x0_mmc_cleanup(struct device *dev)
{
menelaus_unregister_mmc_callback();
gpio_free(N8X0_SLOT_SWITCH_GPIO);
if (machine_is_nokia_n810()) {
gpio_free(N810_EMMC_VSD_GPIO);
gpio_free(N810_EMMC_VIO_GPIO);
}
}
static void __init n8x0_mmc_init(void)
{
int err;
if (machine_is_nokia_n810()) {
mmc1_data.slots[0].name = "external";
mmc1_data.slots[1].name = "internal";
mmc1_data.slots[1].ban_openended = 1;
}
err = gpio_request_one(N8X0_SLOT_SWITCH_GPIO, GPIOF_OUT_INIT_LOW,
"MMC slot switch");
if (err)
return;
if (machine_is_nokia_n810()) {
err = gpio_request_array(n810_emmc_gpios,
ARRAY_SIZE(n810_emmc_gpios));
if (err) {
gpio_free(N8X0_SLOT_SWITCH_GPIO);
return;
}
}
mmc_data[0] = &mmc1_data;
omap242x_init_mmc(mmc_data);
}
void __init n8x0_mmc_init(void)
{
}
static int n8x0_auto_sleep_regulators(void)
{
u32 val;
int ret;
val = EN_VPLL_SLEEP | EN_VMMC_SLEEP \
| EN_VAUX_SLEEP | EN_VIO_SLEEP \
| EN_VMEM_SLEEP | EN_DC3_SLEEP \
| EN_VC_SLEEP | EN_DC2_SLEEP;
ret = menelaus_set_regulator_sleep(1, val);
if (ret < 0) {
printk(KERN_ERR "Could not set regulators to sleep on "
"menelaus: %u\n", ret);
return ret;
}
return 0;
}
static int n8x0_auto_voltage_scale(void)
{
int ret;
ret = menelaus_set_vcore_hw(1400, 1050);
if (ret < 0) {
printk(KERN_ERR "Could not set VCORE voltage on "
"menelaus: %u\n", ret);
return ret;
}
return 0;
}
static int n8x0_menelaus_late_init(struct device *dev)
{
int ret;
ret = n8x0_auto_voltage_scale();
if (ret < 0)
return ret;
ret = n8x0_auto_sleep_regulators();
if (ret < 0)
return ret;
return 0;
}
static int n8x0_menelaus_late_init(struct device *dev)
{
return 0;
}
static void __init n8x0_map_io(void)
{
omap2_set_globals_242x();
omap242x_map_common_io();
}
static void __init n8x0_init_early(void)
{
omap2_init_common_infrastructure();
omap2_init_common_devices(NULL, NULL);
}
static inline void board_serial_init(void)
{
struct omap_board_data bdata;
bdata.flags = 0;
bdata.pads = NULL;
bdata.pads_cnt = 0;
bdata.id = 0;
omap_serial_init_port(&bdata);
bdata.id = 1;
omap_serial_init_port(&bdata);
bdata.id = 2;
bdata.pads = serial2_pads;
bdata.pads_cnt = ARRAY_SIZE(serial2_pads);
omap_serial_init_port(&bdata);
}
static inline void board_serial_init(void)
{
omap_serial_init();
}
static void __init n8x0_init_machine(void)
{
omap2420_mux_init(board_mux, OMAP_PACKAGE_ZAC);
spi_register_board_info(n800_spi_board_info,
ARRAY_SIZE(n800_spi_board_info));
omap_register_i2c_bus(1, 400, n8x0_i2c_board_info_1,
ARRAY_SIZE(n8x0_i2c_board_info_1));
omap_register_i2c_bus(2, 400, NULL, 0);
if (machine_is_nokia_n810())
i2c_register_board_info(2, n810_i2c_board_info_2,
ARRAY_SIZE(n810_i2c_board_info_2));
board_serial_init();
gpmc_onenand_init(board_onenand_data);
n8x0_mmc_init();
n8x0_usb_init();
}
