static void dw_kmsg_dump(struct kmsg_dumper *dumper,
enum kmsg_dump_reason reason)
{
static char line[1024];
size_t len;
mrst_early_console_init();
while (kmsg_dump_get_line(dumper, true, line, sizeof(line), &len))
early_mrst_console.write(&early_mrst_console, line, len);
}
static void max3110_write_config(void)
{
u16 config;
config = 0xc001;
dw_writel(pspi, dr, config);
}
static void max3110_write_data(char c)
{
u16 data;
data = 0x8000 | c;
dw_writel(pspi, dr, data);
}
void mrst_early_console_init(void)
{
u32 ctrlr0 = 0;
u32 spi0_cdiv;
u32 freq;
pclk_spi0 = (void *)set_fixmap_offset_nocache(FIX_EARLYCON_MEM_BASE,
MRST_CLK_SPI0_REG);
spi0_cdiv = ((*pclk_spi0) & 0xe00) >> 9;
freq = 100000000 / (spi0_cdiv + 1);
if (mrst_identify_cpu() == MRST_CPU_CHIP_PENWELL)
mrst_spi_paddr = MRST_REGBASE_SPI1;
pspi = (void *)set_fixmap_offset_nocache(FIX_EARLYCON_MEM_BASE,
mrst_spi_paddr);
dw_writel(pspi, ssienr, 0);
ctrlr0 = dw_readl(pspi, ctrl0);
ctrlr0 &= 0xfcc0;
ctrlr0 |= 0xf | (SPI_FRF_SPI << SPI_FRF_OFFSET)
| (SPI_TMOD_TO << SPI_TMOD_OFFSET);
dw_writel(pspi, ctrl0, ctrlr0);
dw_writel(pspi, baudr, freq/100000);
dw_writel(pspi, imr, 0x0);
dw_writel(pspi, ser, 0x2);
dw_writel(pspi, ssienr, 0x1);
max3110_write_config();
if (!dumper_registered) {
dw_dumper.dump = dw_kmsg_dump;
kmsg_dump_register(&dw_dumper);
dumper_registered = 1;
}
}
static void early_mrst_spi_putc(char c)
{
unsigned int timeout;
u32 sr;
timeout = MRST_SPI_TIMEOUT;
while (--timeout) {
sr = dw_readl(pspi, sr);
if (!(sr & SR_TF_NOT_FULL))
cpu_relax();
else
break;
}
if (!timeout)
pr_warning("MRST earlycon: timed out\n");
else
max3110_write_data(c);
}
static void early_mrst_spi_write(struct console *con, const char *str, unsigned n)
{
int i;
for (i = 0; i < n && *str; i++) {
if (*str == '\n')
early_mrst_spi_putc('\r');
early_mrst_spi_putc(*str);
str++;
}
}
void hsu_early_console_init(const char *s)
{
unsigned long paddr, port = 0;
u8 lcr;
if (*s && !kstrtoul(s, 10, &port))
port = clamp_val(port, 0, 2);
paddr = HSU_PORT_BASE + port * 0x80;
phsu = (void *)set_fixmap_offset_nocache(FIX_EARLYCON_MEM_BASE, paddr);
writeb(0x0, phsu + UART_FCR);
lcr = readb(phsu + UART_LCR);
writeb((0x80 | lcr), phsu + UART_LCR);
writeb(0x18, phsu + UART_DLL);
writeb(lcr, phsu + UART_LCR);
writel(0x3600, phsu + UART_MUL*4);
writeb(0x8, phsu + UART_MCR);
writeb(0x7, phsu + UART_FCR);
writeb(0x3, phsu + UART_LCR);
readb(phsu + UART_LSR);
readb(phsu + UART_RX);
readb(phsu + UART_IIR);
readb(phsu + UART_MSR);
writeb(0x7, phsu + UART_FCR);
}
static void early_hsu_putc(char ch)
{
unsigned int timeout = 10000;
u8 status;
while (--timeout) {
status = readb(phsu + UART_LSR);
if (status & BOTH_EMPTY)
break;
udelay(1);
}
if (timeout)
writeb(ch, phsu + UART_TX);
}
static void early_hsu_write(struct console *con, const char *str, unsigned n)
{
int i;
for (i = 0; i < n && *str; i++) {
if (*str == '\n')
early_hsu_putc('\r');
early_hsu_putc(*str);
str++;
}
}
