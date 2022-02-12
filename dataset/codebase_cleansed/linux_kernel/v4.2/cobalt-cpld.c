static u16 cpld_read(struct cobalt *cobalt, u32 offset)
{
return cobalt_bus_read32(cobalt->bar1, ADRS(offset));
}
static void cpld_write(struct cobalt *cobalt, u32 offset, u16 val)
{
return cobalt_bus_write32(cobalt->bar1, ADRS(offset), val);
}
static void cpld_info_ver3(struct cobalt *cobalt)
{
u32 rd;
u32 tmp;
cobalt_info("CPLD System control register (read/write)\n");
cobalt_info("\t\tSystem control: 0x%04x (0x0f00)\n",
cpld_read(cobalt, 0));
cobalt_info("CPLD Clock control register (read/write)\n");
cobalt_info("\t\tClock control: 0x%04x (0x0000)\n",
cpld_read(cobalt, 0x04));
cobalt_info("CPLD HSMA Clk Osc register (read/write) - Must set wr trigger to load default values\n");
cobalt_info("\t\tRegister #7:\t0x%04x (0x0022)\n",
cpld_read(cobalt, 0x08));
cobalt_info("\t\tRegister #8:\t0x%04x (0x0047)\n",
cpld_read(cobalt, 0x0c));
cobalt_info("\t\tRegister #9:\t0x%04x (0x00fa)\n",
cpld_read(cobalt, 0x10));
cobalt_info("\t\tRegister #10:\t0x%04x (0x0061)\n",
cpld_read(cobalt, 0x14));
cobalt_info("\t\tRegister #11:\t0x%04x (0x001e)\n",
cpld_read(cobalt, 0x18));
cobalt_info("\t\tRegister #12:\t0x%04x (0x0045)\n",
cpld_read(cobalt, 0x1c));
cobalt_info("\t\tRegister #135:\t0x%04x\n",
cpld_read(cobalt, 0x20));
cobalt_info("\t\tRegister #137:\t0x%04x\n",
cpld_read(cobalt, 0x24));
cobalt_info("CPLD System status register (read only)\n");
cobalt_info("\t\tSystem status: 0x%04x\n",
cpld_read(cobalt, 0x28));
cobalt_info("CPLD MAXII info register (read only)\n");
cobalt_info("\t\tBoard serial number: 0x%04x\n",
cpld_read(cobalt, 0x2c));
cobalt_info("\t\tMAXII program revision: 0x%04x\n",
cpld_read(cobalt, 0x30));
cobalt_info("CPLD temp and voltage ADT7411 registers (read only)\n");
cobalt_info("\t\tBoard temperature: %u Celcius\n",
cpld_read(cobalt, 0x34) / 4);
cobalt_info("\t\tFPGA temperature: %u Celcius\n",
cpld_read(cobalt, 0x38) / 4);
rd = cpld_read(cobalt, 0x3c);
tmp = (rd * 33 * 1000) / (483 * 10);
cobalt_info("\t\tVDD 3V3: %u,%03uV\n", tmp / 1000, tmp % 1000);
rd = cpld_read(cobalt, 0x40);
tmp = (rd * 74 * 2197) / (27 * 1000);
cobalt_info("\t\tADC ch3 5V: %u,%03uV\n", tmp / 1000, tmp % 1000);
rd = cpld_read(cobalt, 0x44);
tmp = (rd * 74 * 2197) / (47 * 1000);
cobalt_info("\t\tADC ch4 3V: %u,%03uV\n", tmp / 1000, tmp % 1000);
rd = cpld_read(cobalt, 0x48);
tmp = (rd * 57 * 2197) / (47 * 1000);
cobalt_info("\t\tADC ch5 2V5: %u,%03uV\n", tmp / 1000, tmp % 1000);
rd = cpld_read(cobalt, 0x4c);
tmp = (rd * 2197) / 1000;
cobalt_info("\t\tADC ch6 1V8: %u,%03uV\n", tmp / 1000, tmp % 1000);
rd = cpld_read(cobalt, 0x50);
tmp = (rd * 2197) / 1000;
cobalt_info("\t\tADC ch7 1V5: %u,%03uV\n", tmp / 1000, tmp % 1000);
rd = cpld_read(cobalt, 0x54);
tmp = (rd * 2197) / 1000;
cobalt_info("\t\tADC ch8 0V9: %u,%03uV\n", tmp / 1000, tmp % 1000);
}
void cobalt_cpld_status(struct cobalt *cobalt)
{
u32 rev = cpld_read(cobalt, 0x30);
switch (rev) {
case 3:
case 4:
case 5:
cpld_info_ver3(cobalt);
break;
default:
cobalt_info("CPLD revision %u is not supported!\n", rev);
break;
}
}
bool cobalt_cpld_set_freq(struct cobalt *cobalt, unsigned f_out)
{
const unsigned f_xtal = 39170000;
u64 dco;
u64 rfreq;
unsigned delta = 0xffffffff;
unsigned i_best = 0;
unsigned i;
u8 n1, hsdiv;
u8 regs[6];
int found = 0;
u16 clock_ctrl;
int retries = 3;
for (i = 0; i < ARRAY_SIZE(multipliers); i++) {
unsigned mult = multipliers[i].mult;
u32 d;
dco = (u64)f_out * mult;
if (dco < DCO_MIN || dco > DCO_MAX)
continue;
div_u64_rem((dco << 28) + f_xtal / 2, f_xtal, &d);
if (d < delta) {
found = 1;
i_best = i;
delta = d;
}
}
if (!found)
return false;
dco = (u64)f_out * multipliers[i_best].mult;
n1 = multipliers[i_best].n1 - 1;
hsdiv = multipliers[i_best].hsdiv - 4;
rfreq = div_u64(dco << 28, f_xtal);
clock_ctrl = cpld_read(cobalt, SI570_CLOCK_CTRL);
clock_ctrl |= S01755_REG_CLOCK_CTRL_BITMAP_CLKHSMA_FPGA_CTRL;
clock_ctrl |= S01755_REG_CLOCK_CTRL_BITMAP_CLKHSMA_EN;
regs[0] = (hsdiv << 5) | (n1 >> 2);
regs[1] = ((n1 & 0x3) << 6) | (rfreq >> 32);
regs[2] = (rfreq >> 24) & 0xff;
regs[3] = (rfreq >> 16) & 0xff;
regs[4] = (rfreq >> 8) & 0xff;
regs[5] = rfreq & 0xff;
cobalt_dbg(1, "%u: %02x %02x %02x %02x %02x %02x\n", f_out,
regs[0], regs[1], regs[2], regs[3], regs[4], regs[5]);
while (retries--) {
u8 read_regs[6];
cpld_write(cobalt, SI570_CLOCK_CTRL,
S01755_REG_CLOCK_CTRL_BITMAP_CLKHSMA_EN |
S01755_REG_CLOCK_CTRL_BITMAP_CLKHSMA_FPGA_CTRL);
usleep_range(10000, 15000);
cpld_write(cobalt, SI570_REG7, regs[0]);
cpld_write(cobalt, SI570_REG8, regs[1]);
cpld_write(cobalt, SI570_REG9, regs[2]);
cpld_write(cobalt, SI570_REG10, regs[3]);
cpld_write(cobalt, SI570_REG11, regs[4]);
cpld_write(cobalt, SI570_REG12, regs[5]);
cpld_write(cobalt, SI570_CLOCK_CTRL,
S01755_REG_CLOCK_CTRL_BITMAP_CLKHSMA_EN |
S01755_REG_CLOCK_CTRL_BITMAP_CLKHSMA_WR_TRIGGER);
usleep_range(10000, 15000);
cpld_write(cobalt, SI570_CLOCK_CTRL,
S01755_REG_CLOCK_CTRL_BITMAP_CLKHSMA_EN |
S01755_REG_CLOCK_CTRL_BITMAP_CLKHSMA_FPGA_CTRL);
usleep_range(10000, 15000);
read_regs[0] = cpld_read(cobalt, SI570_REG7);
read_regs[1] = cpld_read(cobalt, SI570_REG8);
read_regs[2] = cpld_read(cobalt, SI570_REG9);
read_regs[3] = cpld_read(cobalt, SI570_REG10);
read_regs[4] = cpld_read(cobalt, SI570_REG11);
read_regs[5] = cpld_read(cobalt, SI570_REG12);
cpld_write(cobalt, SI570_CLOCK_CTRL,
S01755_REG_CLOCK_CTRL_BITMAP_CLKHSMA_EN |
S01755_REG_CLOCK_CTRL_BITMAP_CLKHSMA_FPGA_CTRL |
S01755_REG_CLOCK_CTRL_BITMAP_CLKHSMA_RST_TRIGGER);
usleep_range(10000, 15000);
cpld_write(cobalt, SI570_CLOCK_CTRL,
S01755_REG_CLOCK_CTRL_BITMAP_CLKHSMA_EN);
usleep_range(10000, 15000);
if (!memcmp(read_regs, regs, sizeof(read_regs)))
break;
cobalt_dbg(1, "retry: %02x %02x %02x %02x %02x %02x\n",
read_regs[0], read_regs[1], read_regs[2],
read_regs[3], read_regs[4], read_regs[5]);
}
if (2 - retries)
cobalt_info("Needed %d retries\n", 2 - retries);
return true;
}
