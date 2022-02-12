static void udbg_uart_flush(void)
{
if (!udbg_uart_in)
return;
while ((udbg_uart_in(UART_LSR) & LSR_THRE) == 0)
cpu_relax();
}
static void udbg_uart_putc(char c)
{
if (!udbg_uart_out)
return;
if (c == '\n')
udbg_uart_putc('\r');
udbg_uart_flush();
udbg_uart_out(UART_THR, c);
}
static int udbg_uart_getc_poll(void)
{
if (!udbg_uart_in || !(udbg_uart_in(UART_LSR) & LSR_DR))
return udbg_uart_in(UART_RBR);
return -1;
}
static int udbg_uart_getc(void)
{
if (!udbg_uart_in)
return -1;
while (!(udbg_uart_in(UART_LSR) & LSR_DR))
cpu_relax();
return udbg_uart_in(UART_RBR);
}
static void udbg_use_uart(void)
{
udbg_putc = udbg_uart_putc;
udbg_flush = udbg_uart_flush;
udbg_getc = udbg_uart_getc;
udbg_getc_poll = udbg_uart_getc_poll;
}
void udbg_uart_setup(unsigned int speed, unsigned int clock)
{
unsigned int dll, base_bauds;
if (!udbg_uart_out)
return;
if (clock == 0)
clock = 1843200;
if (speed == 0)
speed = 9600;
base_bauds = clock / 16;
dll = base_bauds / speed;
udbg_uart_out(UART_LCR, 0x00);
udbg_uart_out(UART_IER, 0xff);
udbg_uart_out(UART_IER, 0x00);
udbg_uart_out(UART_LCR, LCR_DLAB);
udbg_uart_out(UART_DLL, dll & 0xff);
udbg_uart_out(UART_DLM, dll >> 8);
udbg_uart_out(UART_LCR, 0x3);
udbg_uart_out(UART_MCR, 0x3);
udbg_uart_out(UART_FCR, 0x7);
}
unsigned int udbg_probe_uart_speed(unsigned int clock)
{
unsigned int dll, dlm, divisor, prescaler, speed;
u8 old_lcr;
old_lcr = udbg_uart_in(UART_LCR);
udbg_uart_out(UART_LCR, old_lcr | LCR_DLAB);
dll = udbg_uart_in(UART_DLL);
dlm = udbg_uart_in(UART_DLM);
divisor = dlm << 8 | dll;
if (udbg_uart_in(UART_MCR) & 0x80)
prescaler = 4;
else
prescaler = 1;
udbg_uart_out(UART_LCR, old_lcr);
speed = (clock / prescaler) / (divisor * 16);
if (speed > (clock / 16))
speed = 9600;
return speed;
}
static u8 udbg_uart_in_pio(unsigned int reg)
{
return inb(udbg_uart.pio_base + (reg * udbg_uart_stride));
}
static void udbg_uart_out_pio(unsigned int reg, u8 data)
{
outb(data, udbg_uart.pio_base + (reg * udbg_uart_stride));
}
void udbg_uart_init_pio(unsigned long port, unsigned int stride)
{
if (!port)
return;
udbg_uart.pio_base = port;
udbg_uart_stride = stride;
udbg_uart_in = udbg_uart_in_pio;
udbg_uart_out = udbg_uart_out_pio;
udbg_use_uart();
}
static u8 udbg_uart_in_mmio(unsigned int reg)
{
return in_8(udbg_uart.mmio_base + (reg * udbg_uart_stride));
}
static void udbg_uart_out_mmio(unsigned int reg, u8 data)
{
out_8(udbg_uart.mmio_base + (reg * udbg_uart_stride), data);
}
void udbg_uart_init_mmio(void __iomem *addr, unsigned int stride)
{
if (!addr)
return;
udbg_uart.mmio_base = addr;
udbg_uart_stride = stride;
udbg_uart_in = udbg_uart_in_mmio;
udbg_uart_out = udbg_uart_out_mmio;
udbg_use_uart();
}
static u8 udbg_uart_in_maple(unsigned int reg)
{
return real_readb(UDBG_UART_MAPLE_ADDR + reg);
}
static void udbg_uart_out_maple(unsigned int reg, u8 val)
{
real_writeb(val, UDBG_UART_MAPLE_ADDR + reg);
}
void __init udbg_init_maple_realmode(void)
{
udbg_uart_in = udbg_uart_in_maple;
udbg_uart_out = udbg_uart_out_maple;
udbg_use_uart();
}
static u8 udbg_uart_in_pas(unsigned int reg)
{
return real_205_readb(UDBG_UART_PAS_ADDR + reg);
}
static void udbg_uart_out_pas(unsigned int reg, u8 val)
{
real_205_writeb(val, UDBG_UART_PAS_ADDR + reg);
}
void __init udbg_init_pas_realmode(void)
{
udbg_uart_in = udbg_uart_in_pas;
udbg_uart_out = udbg_uart_out_pas;
udbg_use_uart();
}
static u8 udbg_uart_in_44x_as1(unsigned int reg)
{
return as1_readb((void __iomem *)PPC44x_EARLY_DEBUG_VIRTADDR + reg);
}
static void udbg_uart_out_44x_as1(unsigned int reg, u8 val)
{
as1_writeb(val, (void __iomem *)PPC44x_EARLY_DEBUG_VIRTADDR + reg);
}
void __init udbg_init_44x_as1(void)
{
udbg_uart_in = udbg_uart_in_44x_as1;
udbg_uart_out = udbg_uart_out_44x_as1;
udbg_use_uart();
}
static u8 udbg_uart_in_40x(unsigned int reg)
{
return real_readb((void __iomem *)CONFIG_PPC_EARLY_DEBUG_40x_PHYSADDR
+ reg);
}
static void udbg_uart_out_40x(unsigned int reg, u8 val)
{
real_writeb(val, (void __iomem *)CONFIG_PPC_EARLY_DEBUG_40x_PHYSADDR
+ reg);
}
void __init udbg_init_40x_realmode(void)
{
udbg_uart_in = udbg_uart_in_40x;
udbg_uart_out = udbg_uart_out_40x;
udbg_use_uart();
}
