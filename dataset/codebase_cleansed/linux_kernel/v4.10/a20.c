static int empty_8042(void)
{
u8 status;
int loops = MAX_8042_LOOPS;
int ffs = MAX_8042_FF;
while (loops--) {
io_delay();
status = inb(0x64);
if (status == 0xff) {
if (!--ffs)
return -1;
}
if (status & 1) {
io_delay();
(void)inb(0x60);
} else if (!(status & 2)) {
return 0;
}
}
return -1;
}
static int a20_test(int loops)
{
int ok = 0;
int saved, ctr;
set_fs(0x0000);
set_gs(0xffff);
saved = ctr = rdfs32(A20_TEST_ADDR);
while (loops--) {
wrfs32(++ctr, A20_TEST_ADDR);
io_delay();
ok = rdgs32(A20_TEST_ADDR+0x10) ^ ctr;
if (ok)
break;
}
wrfs32(saved, A20_TEST_ADDR);
return ok;
}
static int a20_test_short(void)
{
return a20_test(A20_TEST_SHORT);
}
static int a20_test_long(void)
{
return a20_test(A20_TEST_LONG);
}
static void enable_a20_bios(void)
{
struct biosregs ireg;
initregs(&ireg);
ireg.ax = 0x2401;
intcall(0x15, &ireg, NULL);
}
static void enable_a20_kbc(void)
{
empty_8042();
outb(0xd1, 0x64);
empty_8042();
outb(0xdf, 0x60);
empty_8042();
outb(0xff, 0x64);
empty_8042();
}
static void enable_a20_fast(void)
{
u8 port_a;
port_a = inb(0x92);
port_a |= 0x02;
port_a &= ~0x01;
outb(port_a, 0x92);
}
int enable_a20(void)
{
int loops = A20_ENABLE_LOOPS;
int kbc_err;
while (loops--) {
if (a20_test_short())
return 0;
enable_a20_bios();
if (a20_test_short())
return 0;
kbc_err = empty_8042();
if (a20_test_short())
return 0;
if (!kbc_err) {
enable_a20_kbc();
if (a20_test_long())
return 0;
}
enable_a20_fast();
if (a20_test_long())
return 0;
}
return -1;
}
