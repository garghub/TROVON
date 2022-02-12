static inline void prom_putchar_wait(void __iomem *reg, u32 mask, u32 val)
{
u32 t;
do {
t = __raw_readl(reg);
if ((t & mask) == val)
break;
} while (1);
}
static void prom_putchar_ar71xx(unsigned char ch)
{
void __iomem *base = (void __iomem *)(KSEG1ADDR(AR71XX_UART_BASE));
prom_putchar_wait(base + UART_LSR * 4, BOTH_EMPTY, BOTH_EMPTY);
__raw_writel(ch, base + UART_TX * 4);
prom_putchar_wait(base + UART_LSR * 4, BOTH_EMPTY, BOTH_EMPTY);
}
static void prom_putchar_ar933x(unsigned char ch)
{
void __iomem *base = (void __iomem *)(KSEG1ADDR(AR933X_UART_BASE));
prom_putchar_wait(base + AR933X_UART_DATA_REG, AR933X_UART_DATA_TX_CSR,
AR933X_UART_DATA_TX_CSR);
__raw_writel(AR933X_UART_DATA_TX_CSR | ch, base + AR933X_UART_DATA_REG);
prom_putchar_wait(base + AR933X_UART_DATA_REG, AR933X_UART_DATA_TX_CSR,
AR933X_UART_DATA_TX_CSR);
}
static void prom_putchar_dummy(unsigned char ch)
{
}
static void prom_putchar_init(void)
{
void __iomem *base;
u32 id;
base = (void __iomem *)(KSEG1ADDR(AR71XX_RESET_BASE));
id = __raw_readl(base + AR71XX_RESET_REG_REV_ID);
id &= REV_ID_MAJOR_MASK;
switch (id) {
case REV_ID_MAJOR_AR71XX:
case REV_ID_MAJOR_AR7240:
case REV_ID_MAJOR_AR7241:
case REV_ID_MAJOR_AR7242:
case REV_ID_MAJOR_AR913X:
case REV_ID_MAJOR_AR9341:
case REV_ID_MAJOR_AR9342:
case REV_ID_MAJOR_AR9344:
case REV_ID_MAJOR_QCA9556:
case REV_ID_MAJOR_QCA9558:
_prom_putchar = prom_putchar_ar71xx;
break;
case REV_ID_MAJOR_AR9330:
case REV_ID_MAJOR_AR9331:
_prom_putchar = prom_putchar_ar933x;
break;
default:
_prom_putchar = prom_putchar_dummy;
break;
}
}
void prom_putchar(unsigned char ch)
{
if (!_prom_putchar)
prom_putchar_init();
_prom_putchar(ch);
}
