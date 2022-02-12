static u8 caleb_reg_read(int reg)
{
u8 value;
value = *((volatile u8 *)(ENP2611_CALEB_VIRT_BASE + reg));
return value;
}
static void caleb_reg_write(int reg, u8 value)
{
u8 dummy;
*((volatile u8 *)(ENP2611_CALEB_VIRT_BASE + reg)) = value;
dummy = *((volatile u8 *)ENP2611_CALEB_VIRT_BASE);
__asm__ __volatile__("mov %0, %0" : "+r" (dummy));
}
void caleb_reset(void)
{
caleb_reg_write(CALEB_RESET, 0x02);
udelay(1);
caleb_reg_write(CALEB_INTREN0, 0xff);
caleb_reg_write(CALEB_INTREN1, 0x07);
caleb_reg_write(CALEB_PHY0RX, 0x11);
caleb_reg_write(CALEB_PHY1RX, 0x11);
caleb_reg_write(CALEB_PHY0TX, 0x11);
caleb_reg_write(CALEB_PHY1TX, 0x11);
caleb_reg_write(CALEB_BURST, 0);
}
void caleb_enable_rx(int port)
{
u8 temp;
temp = caleb_reg_read(CALEB_PORTEN);
temp |= 1 << port;
caleb_reg_write(CALEB_PORTEN, temp);
}
void caleb_disable_rx(int port)
{
u8 temp;
temp = caleb_reg_read(CALEB_PORTEN);
temp &= ~(1 << port);
caleb_reg_write(CALEB_PORTEN, temp);
}
void caleb_enable_tx(int port)
{
u8 temp;
temp = caleb_reg_read(CALEB_PORTEN);
temp |= 1 << (port + 4);
caleb_reg_write(CALEB_PORTEN, temp);
}
void caleb_disable_tx(int port)
{
u8 temp;
temp = caleb_reg_read(CALEB_PORTEN);
temp &= ~(1 << (port + 4));
caleb_reg_write(CALEB_PORTEN, temp);
}
