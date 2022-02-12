static void clock_source_select(const char *dev_id, unsigned int clkval)
{
unsigned int clksel, offset;
clksel = __raw_readl(REG_CLKSEL);
if (strcmp(dev_id, "nuc900-ms") == 0)
offset = MSOFFSET;
else if (strcmp(dev_id, "nuc900-atapi") == 0)
offset = ATAOFFSET;
else if (strcmp(dev_id, "nuc900-lcd") == 0)
offset = LCDOFFSET;
else if (strcmp(dev_id, "nuc900-ac97") == 0)
offset = AUDOFFSET;
else
offset = CPUOFFSET;
clksel &= ~(0x03 << offset);
clksel |= (clkval << offset);
__raw_writel(clksel, REG_CLKSEL);
}
void nuc900_clock_source(struct device *dev, unsigned char *src)
{
unsigned int clkval;
const char *dev_id;
BUG_ON(!src);
clkval = 0;
mutex_lock(&clksel_sem);
if (dev)
dev_id = dev_name(dev);
else
dev_id = "cpufreq";
if (strcmp(src, "pll0") == 0)
clkval = PLL0;
else if (strcmp(src, "pll1") == 0)
clkval = PLL1;
else if (strcmp(src, "ext") == 0)
clkval = EXT;
else if (strcmp(src, "oth") == 0)
clkval = OTHER;
clock_source_select(dev_id, clkval);
mutex_unlock(&clksel_sem);
}
