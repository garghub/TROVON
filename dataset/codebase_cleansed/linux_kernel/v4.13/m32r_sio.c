static int puts(const char *s)
{
char c;
while ((c = *s++))
m32r_putc(c);
return 0;
}
static void m32r_putc(char c)
{
while ((*BOOT_SIO0STS & 0x3) != 0x3)
cpu_relax();
if (c == '\n') {
*BOOT_SIO0TXB = '\r';
while ((*BOOT_SIO0STS & 0x3) != 0x3)
cpu_relax();
}
*BOOT_SIO0TXB = c;
}
static void m32r_putc(char c)
{
while ((*SIO0STS & 0x1) == 0)
cpu_relax();
if (c == '\n') {
*SIO0TXB = '\r';
while ((*SIO0STS & 0x1) == 0)
cpu_relax();
}
*SIO0TXB = c;
}
