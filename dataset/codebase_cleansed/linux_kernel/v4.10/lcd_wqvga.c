static unsigned long read_reg(void *sohandle,
struct sh_mobile_lcdc_sys_bus_ops *so)
{
return so->read_data(sohandle);
}
static void write_reg(void *sohandle,
struct sh_mobile_lcdc_sys_bus_ops *so,
int i, unsigned long v)
{
if (i)
so->write_data(sohandle, v);
else
so->write_index(sohandle, v);
}
static void write_data(void *sohandle,
struct sh_mobile_lcdc_sys_bus_ops *so,
unsigned char const *data, int no_data)
{
int i;
for (i = 0; i < no_data; i++)
write_reg(sohandle, so, 1, data[i]);
}
static unsigned long read_device_code(void *sohandle,
struct sh_mobile_lcdc_sys_bus_ops *so)
{
unsigned long device_code;
write_reg(sohandle, so, 0, 0xb0);
write_reg(sohandle, so, 1, 0x00);
write_reg(sohandle, so, 0, 0xb1);
write_reg(sohandle, so, 1, 0x00);
write_reg(sohandle, so, 0, 0xbf);
mdelay(50);
read_reg(sohandle, so);
device_code = ((read_reg(sohandle, so) & 0xff) << 24);
device_code |= ((read_reg(sohandle, so) & 0xff) << 16);
device_code |= ((read_reg(sohandle, so) & 0xff) << 8);
device_code |= (read_reg(sohandle, so) & 0xff);
return device_code;
}
static void write_memory_start(void *sohandle,
struct sh_mobile_lcdc_sys_bus_ops *so)
{
write_reg(sohandle, so, 0, 0x2c);
}
static void clear_memory(void *sohandle,
struct sh_mobile_lcdc_sys_bus_ops *so)
{
int i;
write_memory_start(sohandle, so);
for (i = 0; i < (240 * 400); i++)
write_reg(sohandle, so, 1, 0x00);
}
static void display_on(void *sohandle,
struct sh_mobile_lcdc_sys_bus_ops *so)
{
write_reg(sohandle, so, 0, 0xb0);
write_reg(sohandle, so, 1, 0x00);
write_reg(sohandle, so, 0, 0xb1);
write_reg(sohandle, so, 1, 0x00);
write_reg(sohandle, so, 0, 0xb3);
write_data(sohandle, so, data_frame_if, ARRAY_SIZE(data_frame_if));
write_reg(sohandle, so, 0, 0xb4);
write_reg(sohandle, so, 1, 0x00);
write_reg(sohandle, so, 0, 0xc0);
write_data(sohandle, so, data_panel, ARRAY_SIZE(data_panel));
write_reg(sohandle, so, 0, 0xc1);
write_data(sohandle, so, data_timing, ARRAY_SIZE(data_timing));
write_reg(sohandle, so, 0, 0xc2);
write_data(sohandle, so, data_timing, ARRAY_SIZE(data_timing));
write_reg(sohandle, so, 0, 0xc3);
write_data(sohandle, so, data_timing, ARRAY_SIZE(data_timing));
write_reg(sohandle, so, 0, 0xc4);
write_data(sohandle, so, data_timing_src, ARRAY_SIZE(data_timing_src));
write_reg(sohandle, so, 0, 0xc8);
write_data(sohandle, so, data_gamma, ARRAY_SIZE(data_gamma));
write_reg(sohandle, so, 0, 0xc9);
write_data(sohandle, so, data_gamma, ARRAY_SIZE(data_gamma));
write_reg(sohandle, so, 0, 0xca);
write_data(sohandle, so, data_gamma, ARRAY_SIZE(data_gamma));
write_reg(sohandle, so, 0, 0xd0);
write_data(sohandle, so, data_power, ARRAY_SIZE(data_power));
write_reg(sohandle, so, 0, 0xd1);
write_reg(sohandle, so, 1, 0x00);
write_reg(sohandle, so, 1, 0x0f);
write_reg(sohandle, so, 1, 0x02);
write_reg(sohandle, so, 0, 0xd2);
write_reg(sohandle, so, 1, 0x63);
write_reg(sohandle, so, 1, 0x24);
write_reg(sohandle, so, 0, 0xd3);
write_reg(sohandle, so, 1, 0x63);
write_reg(sohandle, so, 1, 0x24);
write_reg(sohandle, so, 0, 0xd4);
write_reg(sohandle, so, 1, 0x63);
write_reg(sohandle, so, 1, 0x24);
write_reg(sohandle, so, 0, 0xd8);
write_reg(sohandle, so, 1, 0x77);
write_reg(sohandle, so, 1, 0x77);
write_reg(sohandle, so, 0, 0x35);
write_reg(sohandle, so, 1, 0x00);
write_reg(sohandle, so, 0, 0x44);
write_reg(sohandle, so, 1, 0x00);
write_reg(sohandle, so, 1, 0x00);
write_reg(sohandle, so, 0, 0x2a);
write_reg(sohandle, so, 1, 0x00);
write_reg(sohandle, so, 1, 0x00);
write_reg(sohandle, so, 1, 0x00);
write_reg(sohandle, so, 1, 0xef);
write_reg(sohandle, so, 0, 0x2b);
write_reg(sohandle, so, 1, 0x00);
write_reg(sohandle, so, 1, 0x00);
write_reg(sohandle, so, 1, 0x01);
write_reg(sohandle, so, 1, 0x8f);
write_reg(sohandle, so, 0, 0x11);
mdelay(120);
clear_memory(sohandle, so);
write_reg(sohandle, so, 0, 0x29);
mdelay(1);
write_memory_start(sohandle, so);
}
int kfr2r09_lcd_setup(void *sohandle, struct sh_mobile_lcdc_sys_bus_ops *so)
{
gpio_set_value(GPIO_PTF4, 0);
gpio_set_value(GPIO_PTE4, 0);
gpio_set_value(GPIO_PTF4, 1);
udelay(1100);
gpio_set_value(GPIO_PTE4, 1);
udelay(10);
gpio_set_value(GPIO_PTF4, 0);
mdelay(20);
if (read_device_code(sohandle, so) != 0x01221517)
return -ENODEV;
pr_info("KFR2R09 WQVGA LCD Module detected.\n");
display_on(sohandle, so);
return 0;
}
void kfr2r09_lcd_start(void *sohandle, struct sh_mobile_lcdc_sys_bus_ops *so)
{
write_memory_start(sohandle, so);
}
