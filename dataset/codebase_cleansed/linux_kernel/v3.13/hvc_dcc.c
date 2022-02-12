static inline u32 __dcc_getstatus(void)
{
u32 __ret;
asm volatile("mrc p14, 0, %0, c0, c1, 0 @ read comms ctrl reg"
: "=r" (__ret) : : "cc");
return __ret;
}
static inline char __dcc_getchar(void)
{
char __c;
asm volatile("mrc p14, 0, %0, c0, c5, 0 @ read comms data reg"
: "=r" (__c));
isb();
return __c;
}
static inline void __dcc_putchar(char c)
{
asm volatile("mcr p14, 0, %0, c0, c5, 0 @ write a char"
:
: "r" (c));
isb();
}
static int hvc_dcc_put_chars(uint32_t vt, const char *buf, int count)
{
int i;
for (i = 0; i < count; i++) {
while (__dcc_getstatus() & DCC_STATUS_TX)
cpu_relax();
__dcc_putchar(buf[i]);
}
return count;
}
static int hvc_dcc_get_chars(uint32_t vt, char *buf, int count)
{
int i;
for (i = 0; i < count; ++i)
if (__dcc_getstatus() & DCC_STATUS_RX)
buf[i] = __dcc_getchar();
else
break;
return i;
}
static bool hvc_dcc_check(void)
{
unsigned long time = jiffies + (HZ / 10);
__dcc_putchar('\n');
while (time_is_after_jiffies(time)) {
if (!(__dcc_getstatus() & DCC_STATUS_TX))
return true;
}
return false;
}
static int __init hvc_dcc_console_init(void)
{
if (!hvc_dcc_check())
return -ENODEV;
hvc_instantiate(0, 0, &hvc_dcc_get_put_ops);
return 0;
}
static int __init hvc_dcc_init(void)
{
if (!hvc_dcc_check())
return -ENODEV;
hvc_alloc(0, 0, &hvc_dcc_get_put_ops, 128);
return 0;
}
