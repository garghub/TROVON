static void __init mpc512x_restart_init(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "fsl,mpc5121-reset");
if (!np)
return;
reset_module_base = of_iomap(np, 0);
of_node_put(np);
}
void mpc512x_restart(char *cmd)
{
if (reset_module_base) {
out_be32(&reset_module_base->rpr, 0x52535445);
out_be32(&reset_module_base->rcr, 0x2);
} else {
pr_err("Restart module not mapped.\n");
}
for (;;)
;
}
void mpc512x_set_pixel_clock(unsigned int pixclock)
{
unsigned long bestval, bestfreq, speed, busfreq;
unsigned long minpixclock, maxpixclock, pixval;
struct mpc512x_ccm __iomem *ccm;
struct device_node *np;
u32 temp;
long err;
int i;
np = of_find_compatible_node(NULL, NULL, "fsl,mpc5121-clock");
if (!np) {
pr_err("Can't find clock control module.\n");
return;
}
ccm = of_iomap(np, 0);
of_node_put(np);
if (!ccm) {
pr_err("Can't map clock control module reg.\n");
return;
}
np = of_find_node_by_type(NULL, "cpu");
if (np) {
const unsigned int *prop =
of_get_property(np, "bus-frequency", NULL);
of_node_put(np);
if (prop) {
busfreq = *prop;
} else {
pr_err("Can't get bus-frequency property\n");
return;
}
} else {
pr_err("Can't find 'cpu' node.\n");
return;
}
pr_debug("DIU: Bus Frequency = %lu\n", busfreq);
speed = busfreq * 4;
pr_debug("DIU pixclock in ps - %d\n", pixclock);
temp = (1000000000 / pixclock) * 1000;
pixclock = temp;
pr_debug("DIU pixclock freq - %u\n", pixclock);
temp = temp / 20;
pr_debug("deviation = %d\n", temp);
minpixclock = pixclock - temp;
maxpixclock = pixclock + temp;
pr_debug("DIU minpixclock - %lu\n", minpixclock);
pr_debug("DIU maxpixclock - %lu\n", maxpixclock);
pixval = speed/pixclock;
pr_debug("DIU pixval = %lu\n", pixval);
err = LONG_MAX;
bestval = pixval;
pr_debug("DIU bestval = %lu\n", bestval);
bestfreq = 0;
for (i = -1; i <= 1; i++) {
temp = speed / (pixval+i);
pr_debug("DIU test pixval i=%d, pixval=%lu, temp freq. = %u\n",
i, pixval, temp);
if ((temp < minpixclock) || (temp > maxpixclock))
pr_debug("DIU exceeds monitor range (%lu to %lu)\n",
minpixclock, maxpixclock);
else if (abs(temp - pixclock) < err) {
pr_debug("Entered the else if block %d\n", i);
err = abs(temp - pixclock);
bestval = pixval + i;
bestfreq = temp;
}
}
pr_debug("DIU chose = %lx\n", bestval);
pr_debug("DIU error = %ld\n NomPixClk ", err);
pr_debug("DIU: Best Freq = %lx\n", bestfreq);
temp = in_be32(&ccm->scfr1);
pr_debug("DIU: Current value of SCFR1: 0x%08x\n", temp);
temp &= ~DIU_DIV_MASK;
temp |= (bestval & DIU_DIV_MASK);
out_be32(&ccm->scfr1, temp);
pr_debug("DIU: Modified value of SCFR1: 0x%08x\n", temp);
iounmap(ccm);
}
enum fsl_diu_monitor_port
mpc512x_valid_monitor_port(enum fsl_diu_monitor_port port)
{
return FSL_DIU_PORT_DVI;
}
static inline void mpc512x_free_bootmem(struct page *page)
{
BUG_ON(PageTail(page));
BUG_ON(atomic_read(&page->_count) > 1);
free_reserved_page(page);
}
void mpc512x_release_bootmem(void)
{
unsigned long addr = diu_shared_fb.fb_phys & PAGE_MASK;
unsigned long size = diu_shared_fb.fb_len;
unsigned long start, end;
if (diu_shared_fb.in_use) {
start = PFN_UP(addr);
end = PFN_DOWN(addr + size);
for (; start < end; start++)
mpc512x_free_bootmem(pfn_to_page(start));
diu_shared_fb.in_use = false;
}
diu_ops.release_bootmem = NULL;
}
void __init mpc512x_init_diu(void)
{
struct device_node *np;
struct diu __iomem *diu_reg;
phys_addr_t desc;
void __iomem *vaddr;
unsigned long mode, pix_fmt, res, bpp;
unsigned long dst;
np = of_find_compatible_node(NULL, NULL, "fsl,mpc5121-diu");
if (!np) {
pr_err("No DIU node\n");
return;
}
diu_reg = of_iomap(np, 0);
of_node_put(np);
if (!diu_reg) {
pr_err("Can't map DIU\n");
return;
}
mode = in_be32(&diu_reg->diu_mode);
if (mode == MFB_MODE0) {
pr_info("%s: DIU OFF\n", __func__);
goto out;
}
desc = in_be32(&diu_reg->desc[0]);
vaddr = ioremap(desc, sizeof(struct diu_ad));
if (!vaddr) {
pr_err("Can't map DIU area desc.\n");
goto out;
}
memcpy(&diu_shared_fb.ad0, vaddr, sizeof(struct diu_ad));
dst = (unsigned long)&diu_shared_fb.ad0;
flush_dcache_range(dst, dst + sizeof(struct diu_ad) - 1);
res = in_be32(&diu_reg->disp_size);
pix_fmt = in_le32(vaddr);
bpp = ((pix_fmt >> 16) & 0x3) + 1;
diu_shared_fb.fb_phys = in_le32(vaddr + 4);
diu_shared_fb.fb_len = ((res & 0xfff0000) >> 16) * (res & 0xfff) * bpp;
diu_shared_fb.in_use = true;
iounmap(vaddr);
desc = in_be32(&diu_reg->gamma);
vaddr = ioremap(desc, sizeof(diu_shared_fb.gamma));
if (!vaddr) {
pr_err("Can't map DIU area desc.\n");
diu_shared_fb.in_use = false;
goto out;
}
memcpy(&diu_shared_fb.gamma, vaddr, sizeof(diu_shared_fb.gamma));
dst = (unsigned long)&diu_shared_fb.gamma;
flush_dcache_range(dst, dst + sizeof(diu_shared_fb.gamma) - 1);
iounmap(vaddr);
out_be32(&diu_reg->gamma, virt_to_phys(&diu_shared_fb.gamma));
out_be32(&diu_reg->desc[1], 0);
out_be32(&diu_reg->desc[2], 0);
out_be32(&diu_reg->desc[0], virt_to_phys(&diu_shared_fb.ad0));
out:
iounmap(diu_reg);
}
void __init mpc512x_setup_diu(void)
{
int ret;
if (diu_shared_fb.in_use) {
ret = reserve_bootmem(diu_shared_fb.fb_phys,
diu_shared_fb.fb_len,
BOOTMEM_EXCLUSIVE);
if (ret) {
pr_err("%s: reserve bootmem failed\n", __func__);
diu_shared_fb.in_use = false;
}
}
diu_ops.set_pixel_clock = mpc512x_set_pixel_clock;
diu_ops.valid_monitor_port = mpc512x_valid_monitor_port;
diu_ops.release_bootmem = mpc512x_release_bootmem;
}
void __init mpc512x_init_IRQ(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "fsl,mpc5121-ipic");
if (!np)
return;
ipic_init(np, 0);
of_node_put(np);
ipic_set_default_priority();
}
void __init mpc512x_declare_of_platform_devices(void)
{
if (of_platform_bus_probe(NULL, of_bus_ids, NULL))
printk(KERN_ERR __FILE__ ": "
"Error while probing of_platform bus\n");
}
const char *mpc512x_select_psc_compat(void)
{
if (of_machine_is_compatible("fsl,mpc5121"))
return "fsl,mpc5121-psc";
if (of_machine_is_compatible("fsl,mpc5125"))
return "fsl,mpc5125-psc";
return NULL;
}
static unsigned int __init get_fifo_size(struct device_node *np,
char *prop_name)
{
const unsigned int *fp;
fp = of_get_property(np, prop_name, NULL);
if (fp)
return *fp;
pr_warning("no %s property in %s node, defaulting to %d\n",
prop_name, np->full_name, DEFAULT_FIFO_SIZE);
return DEFAULT_FIFO_SIZE;
}
void __init mpc512x_psc_fifo_init(void)
{
struct device_node *np;
void __iomem *psc;
unsigned int tx_fifo_size;
unsigned int rx_fifo_size;
const char *psc_compat;
int fifobase = 0;
psc_compat = mpc512x_select_psc_compat();
if (!psc_compat) {
pr_err("%s: no compatible devices found\n", __func__);
return;
}
for_each_compatible_node(np, NULL, psc_compat) {
tx_fifo_size = get_fifo_size(np, "fsl,tx-fifo-size");
rx_fifo_size = get_fifo_size(np, "fsl,rx-fifo-size");
tx_fifo_size /= 4;
rx_fifo_size /= 4;
if (!tx_fifo_size)
tx_fifo_size = 1;
if (!rx_fifo_size)
rx_fifo_size = 1;
psc = of_iomap(np, 0);
if (!psc) {
pr_err("%s: Can't map %s device\n",
__func__, np->full_name);
continue;
}
if ((fifobase + tx_fifo_size + rx_fifo_size) > 0x1000) {
pr_err("%s: no fifo space available for %s\n",
__func__, np->full_name);
iounmap(psc);
continue;
}
out_be32(&FIFOC(psc)->txsz, (fifobase << 16) | tx_fifo_size);
fifobase += tx_fifo_size;
out_be32(&FIFOC(psc)->rxsz, (fifobase << 16) | rx_fifo_size);
fifobase += rx_fifo_size;
out_be32(&FIFOC(psc)->txcmd, 0x80);
out_be32(&FIFOC(psc)->txcmd, 0x01);
out_be32(&FIFOC(psc)->rxcmd, 0x80);
out_be32(&FIFOC(psc)->rxcmd, 0x01);
iounmap(psc);
}
}
void __init mpc512x_init(void)
{
mpc5121_clk_init();
mpc512x_declare_of_platform_devices();
mpc512x_restart_init();
mpc512x_psc_fifo_init();
}
int mpc512x_cs_config(unsigned int cs, u32 val)
{
static struct mpc512x_lpc __iomem *lpc;
struct device_node *np;
if (cs > 7)
return -EINVAL;
if (!lpc) {
np = of_find_compatible_node(NULL, NULL, "fsl,mpc5121-lpc");
lpc = of_iomap(np, 0);
of_node_put(np);
if (!lpc)
return -ENOMEM;
}
out_be32(&lpc->cs_cfg[cs], val);
return 0;
}
