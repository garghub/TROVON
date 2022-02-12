static uint32_t axi_clkgen_lookup_filter(unsigned int m)
{
switch (m) {
case 0:
return 0x01001990;
case 1:
return 0x01001190;
case 2:
return 0x01009890;
case 3:
return 0x01001890;
case 4:
return 0x01008890;
case 5 ... 8:
return 0x01009090;
case 9 ... 11:
return 0x01000890;
case 12:
return 0x08009090;
case 13 ... 22:
return 0x01001090;
case 23 ... 36:
return 0x01008090;
case 37 ... 46:
return 0x08001090;
default:
return 0x08008090;
}
}
static uint32_t axi_clkgen_lookup_lock(unsigned int m)
{
if (m < ARRAY_SIZE(axi_clkgen_lock_table))
return axi_clkgen_lock_table[m];
return 0x1f1f00fa;
}
static void axi_clkgen_calc_params(unsigned long fin, unsigned long fout,
unsigned int *best_d, unsigned int *best_m, unsigned int *best_dout)
{
unsigned long d, d_min, d_max, _d_min, _d_max;
unsigned long m, m_min, m_max;
unsigned long f, dout, best_f, fvco;
fin /= 1000;
fout /= 1000;
best_f = ULONG_MAX;
*best_d = 0;
*best_m = 0;
*best_dout = 0;
d_min = max_t(unsigned long, DIV_ROUND_UP(fin, fpfd_max), 1);
d_max = min_t(unsigned long, fin / fpfd_min, 80);
m_min = max_t(unsigned long, DIV_ROUND_UP(fvco_min, fin) * d_min, 1);
m_max = min_t(unsigned long, fvco_max * d_max / fin, 64);
for (m = m_min; m <= m_max; m++) {
_d_min = max(d_min, DIV_ROUND_UP(fin * m, fvco_max));
_d_max = min(d_max, fin * m / fvco_min);
for (d = _d_min; d <= _d_max; d++) {
fvco = fin * m / d;
dout = DIV_ROUND_CLOSEST(fvco, fout);
dout = clamp_t(unsigned long, dout, 1, 128);
f = fvco / dout;
if (abs(f - fout) < abs(best_f - fout)) {
best_f = f;
*best_d = d;
*best_m = m;
*best_dout = dout;
if (best_f == fout)
return;
}
}
}
}
static void axi_clkgen_calc_clk_params(unsigned int divider, unsigned int *low,
unsigned int *high, unsigned int *edge, unsigned int *nocount)
{
if (divider == 1)
*nocount = 1;
else
*nocount = 0;
*high = divider / 2;
*edge = divider % 2;
*low = divider - *high;
}
static void axi_clkgen_write(struct axi_clkgen *axi_clkgen,
unsigned int reg, unsigned int val)
{
writel(val, axi_clkgen->base + reg);
}
static void axi_clkgen_read(struct axi_clkgen *axi_clkgen,
unsigned int reg, unsigned int *val)
{
*val = readl(axi_clkgen->base + reg);
}
static int axi_clkgen_wait_non_busy(struct axi_clkgen *axi_clkgen)
{
unsigned int timeout = 10000;
unsigned int val;
do {
axi_clkgen_read(axi_clkgen, AXI_CLKGEN_V2_REG_DRP_STATUS, &val);
} while ((val & AXI_CLKGEN_V2_DRP_STATUS_BUSY) && --timeout);
if (val & AXI_CLKGEN_V2_DRP_STATUS_BUSY)
return -EIO;
return val & 0xffff;
}
static int axi_clkgen_mmcm_read(struct axi_clkgen *axi_clkgen,
unsigned int reg, unsigned int *val)
{
unsigned int reg_val;
int ret;
ret = axi_clkgen_wait_non_busy(axi_clkgen);
if (ret < 0)
return ret;
reg_val = AXI_CLKGEN_V2_DRP_CNTRL_SEL | AXI_CLKGEN_V2_DRP_CNTRL_READ;
reg_val |= (reg << 16);
axi_clkgen_write(axi_clkgen, AXI_CLKGEN_V2_REG_DRP_CNTRL, reg_val);
ret = axi_clkgen_wait_non_busy(axi_clkgen);
if (ret < 0)
return ret;
*val = ret;
return 0;
}
static int axi_clkgen_mmcm_write(struct axi_clkgen *axi_clkgen,
unsigned int reg, unsigned int val, unsigned int mask)
{
unsigned int reg_val = 0;
int ret;
ret = axi_clkgen_wait_non_busy(axi_clkgen);
if (ret < 0)
return ret;
if (mask != 0xffff) {
axi_clkgen_mmcm_read(axi_clkgen, reg, &reg_val);
reg_val &= ~mask;
}
reg_val |= AXI_CLKGEN_V2_DRP_CNTRL_SEL | (reg << 16) | (val & mask);
axi_clkgen_write(axi_clkgen, AXI_CLKGEN_V2_REG_DRP_CNTRL, reg_val);
return 0;
}
static void axi_clkgen_mmcm_enable(struct axi_clkgen *axi_clkgen,
bool enable)
{
unsigned int val = AXI_CLKGEN_V2_RESET_ENABLE;
if (enable)
val |= AXI_CLKGEN_V2_RESET_MMCM_ENABLE;
axi_clkgen_write(axi_clkgen, AXI_CLKGEN_V2_REG_RESET, val);
}
static struct axi_clkgen *clk_hw_to_axi_clkgen(struct clk_hw *clk_hw)
{
return container_of(clk_hw, struct axi_clkgen, clk_hw);
}
static int axi_clkgen_set_rate(struct clk_hw *clk_hw,
unsigned long rate, unsigned long parent_rate)
{
struct axi_clkgen *axi_clkgen = clk_hw_to_axi_clkgen(clk_hw);
unsigned int d, m, dout;
unsigned int nocount;
unsigned int high;
unsigned int edge;
unsigned int low;
uint32_t filter;
uint32_t lock;
if (parent_rate == 0 || rate == 0)
return -EINVAL;
axi_clkgen_calc_params(parent_rate, rate, &d, &m, &dout);
if (d == 0 || dout == 0 || m == 0)
return -EINVAL;
filter = axi_clkgen_lookup_filter(m - 1);
lock = axi_clkgen_lookup_lock(m - 1);
axi_clkgen_calc_clk_params(dout, &low, &high, &edge, &nocount);
axi_clkgen_mmcm_write(axi_clkgen, MMCM_REG_CLKOUT0_1,
(high << 6) | low, 0xefff);
axi_clkgen_mmcm_write(axi_clkgen, MMCM_REG_CLKOUT0_2,
(edge << 7) | (nocount << 6), 0x03ff);
axi_clkgen_calc_clk_params(d, &low, &high, &edge, &nocount);
axi_clkgen_mmcm_write(axi_clkgen, MMCM_REG_CLK_DIV,
(edge << 13) | (nocount << 12) | (high << 6) | low, 0x3fff);
axi_clkgen_calc_clk_params(m, &low, &high, &edge, &nocount);
axi_clkgen_mmcm_write(axi_clkgen, MMCM_REG_CLK_FB1,
(high << 6) | low, 0xefff);
axi_clkgen_mmcm_write(axi_clkgen, MMCM_REG_CLK_FB2,
(edge << 7) | (nocount << 6), 0x03ff);
axi_clkgen_mmcm_write(axi_clkgen, MMCM_REG_LOCK1, lock & 0x3ff, 0x3ff);
axi_clkgen_mmcm_write(axi_clkgen, MMCM_REG_LOCK2,
(((lock >> 16) & 0x1f) << 10) | 0x1, 0x7fff);
axi_clkgen_mmcm_write(axi_clkgen, MMCM_REG_LOCK3,
(((lock >> 24) & 0x1f) << 10) | 0x3e9, 0x7fff);
axi_clkgen_mmcm_write(axi_clkgen, MMCM_REG_FILTER1, filter >> 16, 0x9900);
axi_clkgen_mmcm_write(axi_clkgen, MMCM_REG_FILTER2, filter, 0x9900);
return 0;
}
static long axi_clkgen_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
unsigned int d, m, dout;
axi_clkgen_calc_params(*parent_rate, rate, &d, &m, &dout);
if (d == 0 || dout == 0 || m == 0)
return -EINVAL;
return *parent_rate / d * m / dout;
}
static unsigned long axi_clkgen_recalc_rate(struct clk_hw *clk_hw,
unsigned long parent_rate)
{
struct axi_clkgen *axi_clkgen = clk_hw_to_axi_clkgen(clk_hw);
unsigned int d, m, dout;
unsigned int reg;
unsigned long long tmp;
axi_clkgen_mmcm_read(axi_clkgen, MMCM_REG_CLKOUT0_1, &reg);
dout = (reg & 0x3f) + ((reg >> 6) & 0x3f);
axi_clkgen_mmcm_read(axi_clkgen, MMCM_REG_CLK_DIV, &reg);
d = (reg & 0x3f) + ((reg >> 6) & 0x3f);
axi_clkgen_mmcm_read(axi_clkgen, MMCM_REG_CLK_FB1, &reg);
m = (reg & 0x3f) + ((reg >> 6) & 0x3f);
if (d == 0 || dout == 0)
return 0;
tmp = (unsigned long long)(parent_rate / d) * m;
do_div(tmp, dout);
return min_t(unsigned long long, tmp, ULONG_MAX);
}
static int axi_clkgen_enable(struct clk_hw *clk_hw)
{
struct axi_clkgen *axi_clkgen = clk_hw_to_axi_clkgen(clk_hw);
axi_clkgen_mmcm_enable(axi_clkgen, true);
return 0;
}
static void axi_clkgen_disable(struct clk_hw *clk_hw)
{
struct axi_clkgen *axi_clkgen = clk_hw_to_axi_clkgen(clk_hw);
axi_clkgen_mmcm_enable(axi_clkgen, false);
}
static int axi_clkgen_set_parent(struct clk_hw *clk_hw, u8 index)
{
struct axi_clkgen *axi_clkgen = clk_hw_to_axi_clkgen(clk_hw);
axi_clkgen_write(axi_clkgen, AXI_CLKGEN_V2_REG_CLKSEL, index);
return 0;
}
static u8 axi_clkgen_get_parent(struct clk_hw *clk_hw)
{
struct axi_clkgen *axi_clkgen = clk_hw_to_axi_clkgen(clk_hw);
unsigned int parent;
axi_clkgen_read(axi_clkgen, AXI_CLKGEN_V2_REG_CLKSEL, &parent);
return parent;
}
static int axi_clkgen_probe(struct platform_device *pdev)
{
const struct of_device_id *id;
struct axi_clkgen *axi_clkgen;
struct clk_init_data init;
const char *parent_names[2];
const char *clk_name;
struct resource *mem;
struct clk *clk;
unsigned int i;
if (!pdev->dev.of_node)
return -ENODEV;
id = of_match_node(axi_clkgen_ids, pdev->dev.of_node);
if (!id)
return -ENODEV;
axi_clkgen = devm_kzalloc(&pdev->dev, sizeof(*axi_clkgen), GFP_KERNEL);
if (!axi_clkgen)
return -ENOMEM;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
axi_clkgen->base = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(axi_clkgen->base))
return PTR_ERR(axi_clkgen->base);
init.num_parents = of_clk_get_parent_count(pdev->dev.of_node);
if (init.num_parents < 1 || init.num_parents > 2)
return -EINVAL;
for (i = 0; i < init.num_parents; i++) {
parent_names[i] = of_clk_get_parent_name(pdev->dev.of_node, i);
if (!parent_names[i])
return -EINVAL;
}
clk_name = pdev->dev.of_node->name;
of_property_read_string(pdev->dev.of_node, "clock-output-names",
&clk_name);
init.name = clk_name;
init.ops = &axi_clkgen_ops;
init.flags = CLK_SET_RATE_GATE | CLK_SET_PARENT_GATE;
init.parent_names = parent_names;
axi_clkgen_mmcm_enable(axi_clkgen, false);
axi_clkgen->clk_hw.init = &init;
clk = devm_clk_register(&pdev->dev, &axi_clkgen->clk_hw);
if (IS_ERR(clk))
return PTR_ERR(clk);
return of_clk_add_provider(pdev->dev.of_node, of_clk_src_simple_get,
clk);
}
static int axi_clkgen_remove(struct platform_device *pdev)
{
of_clk_del_provider(pdev->dev.of_node);
return 0;
}
