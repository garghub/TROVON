static void reset_lcd_module(void)
{
gpio_set_value(GPIO_PTH2, 0);
mdelay(2);
gpio_set_value(GPIO_PTH2, 1);
mdelay(1);
}
static unsigned long adjust_reg18(unsigned short data)
{
unsigned long tmp1, tmp2;
tmp1 = (data<<1 | 0x00000001) & 0x000001FF;
tmp2 = (data<<2 | 0x00000200) & 0x0003FE00;
return tmp1 | tmp2;
}
static void write_reg(void *sys_ops_handle,
struct sh_mobile_lcdc_sys_bus_ops *sys_ops,
unsigned short reg, unsigned short data)
{
sys_ops->write_index(sys_ops_handle, adjust_reg18(reg << 8 | data));
}
static void write_reg16(void *sys_ops_handle,
struct sh_mobile_lcdc_sys_bus_ops *sys_ops,
unsigned short reg, unsigned short data)
{
sys_ops->write_index(sys_ops_handle, adjust_reg18(reg));
sys_ops->write_data(sys_ops_handle, adjust_reg18(data));
}
static unsigned long read_reg16(void *sys_ops_handle,
struct sh_mobile_lcdc_sys_bus_ops *sys_ops,
unsigned short reg)
{
unsigned long data;
sys_ops->write_index(sys_ops_handle, adjust_reg18(reg));
data = sys_ops->read_data(sys_ops_handle);
return ((data >> 1) & 0xff) | ((data >> 2) & 0xff00);
}
static void migor_lcd_qvga_seq(void *sys_ops_handle,
struct sh_mobile_lcdc_sys_bus_ops *sys_ops,
unsigned short const *data, int no_data)
{
int i;
for (i = 0; i < no_data; i += 2)
write_reg16(sys_ops_handle, sys_ops, data[i], data[i + 1]);
}
int migor_lcd_qvga_setup(void *sohandle, struct sh_mobile_lcdc_sys_bus_ops *so)
{
unsigned long xres = 320;
unsigned long yres = 240;
int k;
reset_lcd_module();
migor_lcd_qvga_seq(sohandle, so, sync_data, ARRAY_SIZE(sync_data));
if (read_reg16(sohandle, so, 0) != 0x1505)
return -ENODEV;
pr_info("Migo-R QVGA LCD Module detected.\n");
migor_lcd_qvga_seq(sohandle, so, sync_data, ARRAY_SIZE(sync_data));
write_reg16(sohandle, so, 0x00A4, 0x0001);
mdelay(10);
migor_lcd_qvga_seq(sohandle, so, magic0_data, ARRAY_SIZE(magic0_data));
mdelay(100);
migor_lcd_qvga_seq(sohandle, so, magic1_data, ARRAY_SIZE(magic1_data));
write_reg16(sohandle, so, 0x0050, 0xef - (yres - 1));
write_reg16(sohandle, so, 0x0051, 0x00ef);
write_reg16(sohandle, so, 0x0052, 0x0000);
write_reg16(sohandle, so, 0x0053, xres - 1);
migor_lcd_qvga_seq(sohandle, so, magic2_data, ARRAY_SIZE(magic2_data));
mdelay(10);
migor_lcd_qvga_seq(sohandle, so, magic3_data, ARRAY_SIZE(magic3_data));
mdelay(40);
write_reg16(sohandle, so, 0x0020, 0x0000);
write_reg16(sohandle, so, 0x0021, 0x0000);
for (k = 0; k < (xres * 256); k++)
write_reg16(sohandle, so, 0x0022, 0x0000);
write_reg16(sohandle, so, 0x0020, 0x0000);
write_reg16(sohandle, so, 0x0021, 0x0000);
write_reg16(sohandle, so, 0x0007, 0x0173);
mdelay(40);
write_reg(sohandle, so, 0x00, 0x22);
mdelay(100);
return 0;
}
