static struct s3c2410_nand_mtd *s3c2410_nand_mtd_toours(struct mtd_info *mtd)
{
return container_of(mtd, struct s3c2410_nand_mtd, mtd);
}
static struct s3c2410_nand_info *s3c2410_nand_mtd_toinfo(struct mtd_info *mtd)
{
return s3c2410_nand_mtd_toours(mtd)->info;
}
static struct s3c2410_nand_info *to_nand_info(struct platform_device *dev)
{
return platform_get_drvdata(dev);
}
static struct s3c2410_platform_nand *to_nand_plat(struct platform_device *dev)
{
return dev->dev.platform_data;
}
static inline int allow_clk_suspend(struct s3c2410_nand_info *info)
{
return clock_stop;
}
static void s3c2410_nand_clk_set_state(struct s3c2410_nand_info *info,
enum s3c_nand_clk_state new_state)
{
if (!allow_clk_suspend(info) && new_state == CLOCK_SUSPEND)
return;
if (info->clk_state == CLOCK_ENABLE) {
if (new_state != CLOCK_ENABLE)
clk_disable(info->clk);
} else {
if (new_state == CLOCK_ENABLE)
clk_enable(info->clk);
}
info->clk_state = new_state;
}
static int s3c_nand_calc_rate(int wanted, unsigned long clk, int max)
{
int result;
result = DIV_ROUND_UP((wanted * clk), NS_IN_KHZ);
pr_debug("result %d from %ld, %d\n", result, clk, wanted);
if (result > max) {
printk("%d ns is too big for current clock rate %ld\n", wanted, clk);
return -1;
}
if (result < 1)
result = 1;
return result;
}
static int s3c2410_nand_setrate(struct s3c2410_nand_info *info)
{
struct s3c2410_platform_nand *plat = info->platform;
int tacls_max = (info->cpu_type == TYPE_S3C2412) ? 8 : 4;
int tacls, twrph0, twrph1;
unsigned long clkrate = clk_get_rate(info->clk);
unsigned long uninitialized_var(set), cfg, uninitialized_var(mask);
unsigned long flags;
info->clk_rate = clkrate;
clkrate /= 1000;
if (plat != NULL) {
tacls = s3c_nand_calc_rate(plat->tacls, clkrate, tacls_max);
twrph0 = s3c_nand_calc_rate(plat->twrph0, clkrate, 8);
twrph1 = s3c_nand_calc_rate(plat->twrph1, clkrate, 8);
} else {
tacls = tacls_max;
twrph0 = 8;
twrph1 = 8;
}
if (tacls < 0 || twrph0 < 0 || twrph1 < 0) {
dev_err(info->device, "cannot get suitable timings\n");
return -EINVAL;
}
dev_info(info->device, "Tacls=%d, %dns Twrph0=%d %dns, Twrph1=%d %dns\n",
tacls, to_ns(tacls, clkrate), twrph0, to_ns(twrph0, clkrate), twrph1, to_ns(twrph1, clkrate));
switch (info->cpu_type) {
case TYPE_S3C2410:
mask = (S3C2410_NFCONF_TACLS(3) |
S3C2410_NFCONF_TWRPH0(7) |
S3C2410_NFCONF_TWRPH1(7));
set = S3C2410_NFCONF_EN;
set |= S3C2410_NFCONF_TACLS(tacls - 1);
set |= S3C2410_NFCONF_TWRPH0(twrph0 - 1);
set |= S3C2410_NFCONF_TWRPH1(twrph1 - 1);
break;
case TYPE_S3C2440:
case TYPE_S3C2412:
mask = (S3C2440_NFCONF_TACLS(tacls_max - 1) |
S3C2440_NFCONF_TWRPH0(7) |
S3C2440_NFCONF_TWRPH1(7));
set = S3C2440_NFCONF_TACLS(tacls - 1);
set |= S3C2440_NFCONF_TWRPH0(twrph0 - 1);
set |= S3C2440_NFCONF_TWRPH1(twrph1 - 1);
break;
default:
BUG();
}
local_irq_save(flags);
cfg = readl(info->regs + S3C2410_NFCONF);
cfg &= ~mask;
cfg |= set;
writel(cfg, info->regs + S3C2410_NFCONF);
local_irq_restore(flags);
dev_dbg(info->device, "NF_CONF is 0x%lx\n", cfg);
return 0;
}
static int s3c2410_nand_inithw(struct s3c2410_nand_info *info)
{
int ret;
ret = s3c2410_nand_setrate(info);
if (ret < 0)
return ret;
switch (info->cpu_type) {
case TYPE_S3C2410:
default:
break;
case TYPE_S3C2440:
case TYPE_S3C2412:
writel(S3C2440_NFCONT_ENABLE, info->regs + S3C2440_NFCONT);
}
return 0;
}
static void s3c2410_nand_select_chip(struct mtd_info *mtd, int chip)
{
struct s3c2410_nand_info *info;
struct s3c2410_nand_mtd *nmtd;
struct nand_chip *this = mtd->priv;
unsigned long cur;
nmtd = this->priv;
info = nmtd->info;
if (chip != -1)
s3c2410_nand_clk_set_state(info, CLOCK_ENABLE);
cur = readl(info->sel_reg);
if (chip == -1) {
cur |= info->sel_bit;
} else {
if (nmtd->set != NULL && chip > nmtd->set->nr_chips) {
dev_err(info->device, "invalid chip %d\n", chip);
return;
}
if (info->platform != NULL) {
if (info->platform->select_chip != NULL)
(info->platform->select_chip) (nmtd->set, chip);
}
cur &= ~info->sel_bit;
}
writel(cur, info->sel_reg);
if (chip == -1)
s3c2410_nand_clk_set_state(info, CLOCK_SUSPEND);
}
static void s3c2410_nand_hwcontrol(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
struct s3c2410_nand_info *info = s3c2410_nand_mtd_toinfo(mtd);
if (cmd == NAND_CMD_NONE)
return;
if (ctrl & NAND_CLE)
writeb(cmd, info->regs + S3C2410_NFCMD);
else
writeb(cmd, info->regs + S3C2410_NFADDR);
}
static void s3c2440_nand_hwcontrol(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
struct s3c2410_nand_info *info = s3c2410_nand_mtd_toinfo(mtd);
if (cmd == NAND_CMD_NONE)
return;
if (ctrl & NAND_CLE)
writeb(cmd, info->regs + S3C2440_NFCMD);
else
writeb(cmd, info->regs + S3C2440_NFADDR);
}
static int s3c2410_nand_devready(struct mtd_info *mtd)
{
struct s3c2410_nand_info *info = s3c2410_nand_mtd_toinfo(mtd);
return readb(info->regs + S3C2410_NFSTAT) & S3C2410_NFSTAT_BUSY;
}
static int s3c2440_nand_devready(struct mtd_info *mtd)
{
struct s3c2410_nand_info *info = s3c2410_nand_mtd_toinfo(mtd);
return readb(info->regs + S3C2440_NFSTAT) & S3C2440_NFSTAT_READY;
}
static int s3c2412_nand_devready(struct mtd_info *mtd)
{
struct s3c2410_nand_info *info = s3c2410_nand_mtd_toinfo(mtd);
return readb(info->regs + S3C2412_NFSTAT) & S3C2412_NFSTAT_READY;
}
static int s3c2410_nand_correct_data(struct mtd_info *mtd, u_char *dat,
u_char *read_ecc, u_char *calc_ecc)
{
struct s3c2410_nand_info *info = s3c2410_nand_mtd_toinfo(mtd);
unsigned int diff0, diff1, diff2;
unsigned int bit, byte;
pr_debug("%s(%p,%p,%p,%p)\n", __func__, mtd, dat, read_ecc, calc_ecc);
diff0 = read_ecc[0] ^ calc_ecc[0];
diff1 = read_ecc[1] ^ calc_ecc[1];
diff2 = read_ecc[2] ^ calc_ecc[2];
pr_debug("%s: rd %02x%02x%02x calc %02x%02x%02x diff %02x%02x%02x\n",
__func__,
read_ecc[0], read_ecc[1], read_ecc[2],
calc_ecc[0], calc_ecc[1], calc_ecc[2],
diff0, diff1, diff2);
if (diff0 == 0 && diff1 == 0 && diff2 == 0)
return 0;
if (read_ecc[0] == 0xff && read_ecc[1] == 0xff && read_ecc[2] == 0xff
&& info->platform->ignore_unset_ecc)
return 0;
if (((diff0 ^ (diff0 >> 1)) & 0x55) == 0x55 &&
((diff1 ^ (diff1 >> 1)) & 0x55) == 0x55 &&
((diff2 ^ (diff2 >> 1)) & 0x55) == 0x55) {
bit = ((diff2 >> 3) & 1) |
((diff2 >> 4) & 2) |
((diff2 >> 5) & 4);
byte = ((diff2 << 7) & 0x100) |
((diff1 << 0) & 0x80) |
((diff1 << 1) & 0x40) |
((diff1 << 2) & 0x20) |
((diff1 << 3) & 0x10) |
((diff0 >> 4) & 0x08) |
((diff0 >> 3) & 0x04) |
((diff0 >> 2) & 0x02) |
((diff0 >> 1) & 0x01);
dev_dbg(info->device, "correcting error bit %d, byte %d\n",
bit, byte);
dat[byte] ^= (1 << bit);
return 1;
}
diff0 |= (diff1 << 8);
diff0 |= (diff2 << 16);
if ((diff0 & ~(1<<fls(diff0))) == 0)
return 1;
return -1;
}
static void s3c2410_nand_enable_hwecc(struct mtd_info *mtd, int mode)
{
struct s3c2410_nand_info *info = s3c2410_nand_mtd_toinfo(mtd);
unsigned long ctrl;
ctrl = readl(info->regs + S3C2410_NFCONF);
ctrl |= S3C2410_NFCONF_INITECC;
writel(ctrl, info->regs + S3C2410_NFCONF);
}
static void s3c2412_nand_enable_hwecc(struct mtd_info *mtd, int mode)
{
struct s3c2410_nand_info *info = s3c2410_nand_mtd_toinfo(mtd);
unsigned long ctrl;
ctrl = readl(info->regs + S3C2440_NFCONT);
writel(ctrl | S3C2412_NFCONT_INIT_MAIN_ECC, info->regs + S3C2440_NFCONT);
}
static void s3c2440_nand_enable_hwecc(struct mtd_info *mtd, int mode)
{
struct s3c2410_nand_info *info = s3c2410_nand_mtd_toinfo(mtd);
unsigned long ctrl;
ctrl = readl(info->regs + S3C2440_NFCONT);
writel(ctrl | S3C2440_NFCONT_INITECC, info->regs + S3C2440_NFCONT);
}
static int s3c2410_nand_calculate_ecc(struct mtd_info *mtd, const u_char *dat, u_char *ecc_code)
{
struct s3c2410_nand_info *info = s3c2410_nand_mtd_toinfo(mtd);
ecc_code[0] = readb(info->regs + S3C2410_NFECC + 0);
ecc_code[1] = readb(info->regs + S3C2410_NFECC + 1);
ecc_code[2] = readb(info->regs + S3C2410_NFECC + 2);
pr_debug("%s: returning ecc %02x%02x%02x\n", __func__,
ecc_code[0], ecc_code[1], ecc_code[2]);
return 0;
}
static int s3c2412_nand_calculate_ecc(struct mtd_info *mtd, const u_char *dat, u_char *ecc_code)
{
struct s3c2410_nand_info *info = s3c2410_nand_mtd_toinfo(mtd);
unsigned long ecc = readl(info->regs + S3C2412_NFMECC0);
ecc_code[0] = ecc;
ecc_code[1] = ecc >> 8;
ecc_code[2] = ecc >> 16;
pr_debug("calculate_ecc: returning ecc %02x,%02x,%02x\n", ecc_code[0], ecc_code[1], ecc_code[2]);
return 0;
}
static int s3c2440_nand_calculate_ecc(struct mtd_info *mtd, const u_char *dat, u_char *ecc_code)
{
struct s3c2410_nand_info *info = s3c2410_nand_mtd_toinfo(mtd);
unsigned long ecc = readl(info->regs + S3C2440_NFMECC0);
ecc_code[0] = ecc;
ecc_code[1] = ecc >> 8;
ecc_code[2] = ecc >> 16;
pr_debug("%s: returning ecc %06lx\n", __func__, ecc & 0xffffff);
return 0;
}
static void s3c2410_nand_read_buf(struct mtd_info *mtd, u_char *buf, int len)
{
struct nand_chip *this = mtd->priv;
readsb(this->IO_ADDR_R, buf, len);
}
static void s3c2440_nand_read_buf(struct mtd_info *mtd, u_char *buf, int len)
{
struct s3c2410_nand_info *info = s3c2410_nand_mtd_toinfo(mtd);
readsl(info->regs + S3C2440_NFDATA, buf, len >> 2);
if (len & 3) {
buf += len & ~3;
for (; len & 3; len--)
*buf++ = readb(info->regs + S3C2440_NFDATA);
}
}
static void s3c2410_nand_write_buf(struct mtd_info *mtd, const u_char *buf, int len)
{
struct nand_chip *this = mtd->priv;
writesb(this->IO_ADDR_W, buf, len);
}
static void s3c2440_nand_write_buf(struct mtd_info *mtd, const u_char *buf, int len)
{
struct s3c2410_nand_info *info = s3c2410_nand_mtd_toinfo(mtd);
writesl(info->regs + S3C2440_NFDATA, buf, len >> 2);
if (len & 3) {
buf += len & ~3;
for (; len & 3; len--, buf++)
writeb(*buf, info->regs + S3C2440_NFDATA);
}
}
static int s3c2410_nand_cpufreq_transition(struct notifier_block *nb,
unsigned long val, void *data)
{
struct s3c2410_nand_info *info;
unsigned long newclk;
info = container_of(nb, struct s3c2410_nand_info, freq_transition);
newclk = clk_get_rate(info->clk);
if ((val == CPUFREQ_POSTCHANGE && newclk < info->clk_rate) ||
(val == CPUFREQ_PRECHANGE && newclk > info->clk_rate)) {
s3c2410_nand_setrate(info);
}
return 0;
}
static inline int s3c2410_nand_cpufreq_register(struct s3c2410_nand_info *info)
{
info->freq_transition.notifier_call = s3c2410_nand_cpufreq_transition;
return cpufreq_register_notifier(&info->freq_transition,
CPUFREQ_TRANSITION_NOTIFIER);
}
static inline void s3c2410_nand_cpufreq_deregister(struct s3c2410_nand_info *info)
{
cpufreq_unregister_notifier(&info->freq_transition,
CPUFREQ_TRANSITION_NOTIFIER);
}
static inline int s3c2410_nand_cpufreq_register(struct s3c2410_nand_info *info)
{
return 0;
}
static inline void s3c2410_nand_cpufreq_deregister(struct s3c2410_nand_info *info)
{
}
static int s3c24xx_nand_remove(struct platform_device *pdev)
{
struct s3c2410_nand_info *info = to_nand_info(pdev);
platform_set_drvdata(pdev, NULL);
if (info == NULL)
return 0;
s3c2410_nand_cpufreq_deregister(info);
if (info->mtds != NULL) {
struct s3c2410_nand_mtd *ptr = info->mtds;
int mtdno;
for (mtdno = 0; mtdno < info->mtd_count; mtdno++, ptr++) {
pr_debug("releasing mtd %d (%p)\n", mtdno, ptr);
nand_release(&ptr->mtd);
}
kfree(info->mtds);
}
if (!IS_ERR(info->clk)) {
s3c2410_nand_clk_set_state(info, CLOCK_DISABLE);
clk_put(info->clk);
}
if (info->regs != NULL) {
iounmap(info->regs);
info->regs = NULL;
}
if (info->area != NULL) {
release_resource(info->area);
kfree(info->area);
info->area = NULL;
}
kfree(info);
return 0;
}
static int s3c2410_nand_add_partition(struct s3c2410_nand_info *info,
struct s3c2410_nand_mtd *mtd,
struct s3c2410_nand_set *set)
{
if (set)
mtd->mtd.name = set->name;
return mtd_device_parse_register(&mtd->mtd, NULL, NULL,
set->partitions, set->nr_partitions);
}
static void s3c2410_nand_init_chip(struct s3c2410_nand_info *info,
struct s3c2410_nand_mtd *nmtd,
struct s3c2410_nand_set *set)
{
struct nand_chip *chip = &nmtd->chip;
void __iomem *regs = info->regs;
chip->write_buf = s3c2410_nand_write_buf;
chip->read_buf = s3c2410_nand_read_buf;
chip->select_chip = s3c2410_nand_select_chip;
chip->chip_delay = 50;
chip->priv = nmtd;
chip->options = set->options;
chip->controller = &info->controller;
switch (info->cpu_type) {
case TYPE_S3C2410:
chip->IO_ADDR_W = regs + S3C2410_NFDATA;
info->sel_reg = regs + S3C2410_NFCONF;
info->sel_bit = S3C2410_NFCONF_nFCE;
chip->cmd_ctrl = s3c2410_nand_hwcontrol;
chip->dev_ready = s3c2410_nand_devready;
break;
case TYPE_S3C2440:
chip->IO_ADDR_W = regs + S3C2440_NFDATA;
info->sel_reg = regs + S3C2440_NFCONT;
info->sel_bit = S3C2440_NFCONT_nFCE;
chip->cmd_ctrl = s3c2440_nand_hwcontrol;
chip->dev_ready = s3c2440_nand_devready;
chip->read_buf = s3c2440_nand_read_buf;
chip->write_buf = s3c2440_nand_write_buf;
break;
case TYPE_S3C2412:
chip->IO_ADDR_W = regs + S3C2440_NFDATA;
info->sel_reg = regs + S3C2440_NFCONT;
info->sel_bit = S3C2412_NFCONT_nFCE0;
chip->cmd_ctrl = s3c2440_nand_hwcontrol;
chip->dev_ready = s3c2412_nand_devready;
if (readl(regs + S3C2410_NFCONF) & S3C2412_NFCONF_NANDBOOT)
dev_info(info->device, "System booted from NAND\n");
break;
}
chip->IO_ADDR_R = chip->IO_ADDR_W;
nmtd->info = info;
nmtd->mtd.priv = chip;
nmtd->mtd.owner = THIS_MODULE;
nmtd->set = set;
if (hardware_ecc) {
chip->ecc.calculate = s3c2410_nand_calculate_ecc;
chip->ecc.correct = s3c2410_nand_correct_data;
chip->ecc.mode = NAND_ECC_HW;
chip->ecc.strength = 1;
switch (info->cpu_type) {
case TYPE_S3C2410:
chip->ecc.hwctl = s3c2410_nand_enable_hwecc;
chip->ecc.calculate = s3c2410_nand_calculate_ecc;
break;
case TYPE_S3C2412:
chip->ecc.hwctl = s3c2412_nand_enable_hwecc;
chip->ecc.calculate = s3c2412_nand_calculate_ecc;
break;
case TYPE_S3C2440:
chip->ecc.hwctl = s3c2440_nand_enable_hwecc;
chip->ecc.calculate = s3c2440_nand_calculate_ecc;
break;
}
} else {
chip->ecc.mode = NAND_ECC_SOFT;
}
if (set->ecc_layout != NULL)
chip->ecc.layout = set->ecc_layout;
if (set->disable_ecc)
chip->ecc.mode = NAND_ECC_NONE;
switch (chip->ecc.mode) {
case NAND_ECC_NONE:
dev_info(info->device, "NAND ECC disabled\n");
break;
case NAND_ECC_SOFT:
dev_info(info->device, "NAND soft ECC\n");
break;
case NAND_ECC_HW:
dev_info(info->device, "NAND hardware ECC\n");
break;
default:
dev_info(info->device, "NAND ECC UNKNOWN\n");
break;
}
if (set->flash_bbt) {
chip->bbt_options |= NAND_BBT_USE_FLASH;
chip->options |= NAND_SKIP_BBTSCAN;
}
}
static void s3c2410_nand_update_chip(struct s3c2410_nand_info *info,
struct s3c2410_nand_mtd *nmtd)
{
struct nand_chip *chip = &nmtd->chip;
dev_dbg(info->device, "chip %p => page shift %d\n",
chip, chip->page_shift);
if (chip->ecc.mode != NAND_ECC_HW)
return;
if (chip->page_shift > 10) {
chip->ecc.size = 256;
chip->ecc.bytes = 3;
} else {
chip->ecc.size = 512;
chip->ecc.bytes = 3;
chip->ecc.layout = &nand_hw_eccoob;
}
}
static int s3c24xx_nand_probe(struct platform_device *pdev)
{
struct s3c2410_platform_nand *plat = to_nand_plat(pdev);
enum s3c_cpu_type cpu_type;
struct s3c2410_nand_info *info;
struct s3c2410_nand_mtd *nmtd;
struct s3c2410_nand_set *sets;
struct resource *res;
int err = 0;
int size;
int nr_sets;
int setno;
cpu_type = platform_get_device_id(pdev)->driver_data;
pr_debug("s3c2410_nand_probe(%p)\n", pdev);
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (info == NULL) {
dev_err(&pdev->dev, "no memory for flash info\n");
err = -ENOMEM;
goto exit_error;
}
platform_set_drvdata(pdev, info);
spin_lock_init(&info->controller.lock);
init_waitqueue_head(&info->controller.wq);
info->clk = clk_get(&pdev->dev, "nand");
if (IS_ERR(info->clk)) {
dev_err(&pdev->dev, "failed to get clock\n");
err = -ENOENT;
goto exit_error;
}
s3c2410_nand_clk_set_state(info, CLOCK_ENABLE);
res = pdev->resource;
size = resource_size(res);
info->area = request_mem_region(res->start, size, pdev->name);
if (info->area == NULL) {
dev_err(&pdev->dev, "cannot reserve register region\n");
err = -ENOENT;
goto exit_error;
}
info->device = &pdev->dev;
info->platform = plat;
info->regs = ioremap(res->start, size);
info->cpu_type = cpu_type;
if (info->regs == NULL) {
dev_err(&pdev->dev, "cannot reserve register region\n");
err = -EIO;
goto exit_error;
}
dev_dbg(&pdev->dev, "mapped registers at %p\n", info->regs);
err = s3c2410_nand_inithw(info);
if (err != 0)
goto exit_error;
sets = (plat != NULL) ? plat->sets : NULL;
nr_sets = (plat != NULL) ? plat->nr_sets : 1;
info->mtd_count = nr_sets;
size = nr_sets * sizeof(*info->mtds);
info->mtds = kzalloc(size, GFP_KERNEL);
if (info->mtds == NULL) {
dev_err(&pdev->dev, "failed to allocate mtd storage\n");
err = -ENOMEM;
goto exit_error;
}
nmtd = info->mtds;
for (setno = 0; setno < nr_sets; setno++, nmtd++) {
pr_debug("initialising set %d (%p, info %p)\n", setno, nmtd, info);
s3c2410_nand_init_chip(info, nmtd, sets);
nmtd->scan_res = nand_scan_ident(&nmtd->mtd,
(sets) ? sets->nr_chips : 1,
NULL);
if (nmtd->scan_res == 0) {
s3c2410_nand_update_chip(info, nmtd);
nand_scan_tail(&nmtd->mtd);
s3c2410_nand_add_partition(info, nmtd, sets);
}
if (sets != NULL)
sets++;
}
err = s3c2410_nand_cpufreq_register(info);
if (err < 0) {
dev_err(&pdev->dev, "failed to init cpufreq support\n");
goto exit_error;
}
if (allow_clk_suspend(info)) {
dev_info(&pdev->dev, "clock idle support enabled\n");
s3c2410_nand_clk_set_state(info, CLOCK_SUSPEND);
}
pr_debug("initialised ok\n");
return 0;
exit_error:
s3c24xx_nand_remove(pdev);
if (err == 0)
err = -EINVAL;
return err;
}
static int s3c24xx_nand_suspend(struct platform_device *dev, pm_message_t pm)
{
struct s3c2410_nand_info *info = platform_get_drvdata(dev);
if (info) {
info->save_sel = readl(info->sel_reg);
writel(info->save_sel | info->sel_bit, info->sel_reg);
s3c2410_nand_clk_set_state(info, CLOCK_DISABLE);
}
return 0;
}
static int s3c24xx_nand_resume(struct platform_device *dev)
{
struct s3c2410_nand_info *info = platform_get_drvdata(dev);
unsigned long sel;
if (info) {
s3c2410_nand_clk_set_state(info, CLOCK_ENABLE);
s3c2410_nand_inithw(info);
sel = readl(info->sel_reg);
sel &= ~info->sel_bit;
sel |= info->save_sel & info->sel_bit;
writel(sel, info->sel_reg);
s3c2410_nand_clk_set_state(info, CLOCK_SUSPEND);
}
return 0;
}
static int __init s3c2410_nand_init(void)
{
printk("S3C24XX NAND Driver, (c) 2004 Simtec Electronics\n");
return platform_driver_register(&s3c24xx_nand_driver);
}
static void __exit s3c2410_nand_exit(void)
{
platform_driver_unregister(&s3c24xx_nand_driver);
}
