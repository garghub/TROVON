void qnap_tsx09_power_off(void)
{
const unsigned divisor = ((orion5x_tclk + (8 * 19200)) / (16 * 19200));
pr_info("%s: triggering power-off...\n", __func__);
writel(0x83, UART1_REG(LCR));
writel(divisor & 0xff, UART1_REG(DLL));
writel((divisor >> 8) & 0xff, UART1_REG(DLM));
writel(0x03, UART1_REG(LCR));
writel(0x00, UART1_REG(IER));
writel(0x00, UART1_REG(FCR));
writel(0x00, UART1_REG(MCR));
writel('A', UART1_REG(TX));
}
static int __init qnap_tsx09_check_mac_addr(const char *addr_str)
{
u_int8_t addr[6];
if (!mac_pton(addr_str, addr))
return -1;
printk(KERN_INFO "tsx09: found ethernet mac address %pM\n", addr);
memcpy(qnap_tsx09_eth_data.mac_addr, addr, 6);
return 0;
}
void __init qnap_tsx09_find_mac_addr(u32 mem_base, u32 size)
{
unsigned long addr;
for (addr = mem_base; addr < (mem_base + size); addr += 1024) {
void __iomem *nor_page;
int ret = 0;
nor_page = ioremap(addr, 1024);
if (nor_page != NULL) {
ret = qnap_tsx09_check_mac_addr((__force const char *)nor_page);
iounmap(nor_page);
}
if (ret == 0)
break;
}
}
