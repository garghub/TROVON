static inline u_int pxa2xx_mcxx_hold(u_int pcmcia_cycle_ns,
u_int mem_clk_10khz)
{
u_int code = pcmcia_cycle_ns * mem_clk_10khz;
return (code / 300000) + ((code % 300000) ? 1 : 0) - 1;
}
static inline u_int pxa2xx_mcxx_asst(u_int pcmcia_cycle_ns,
u_int mem_clk_10khz)
{
u_int code = pcmcia_cycle_ns * mem_clk_10khz;
return (code / 300000) + ((code % 300000) ? 1 : 0) + 1;
}
static inline u_int pxa2xx_mcxx_setup(u_int pcmcia_cycle_ns,
u_int mem_clk_10khz)
{
u_int code = pcmcia_cycle_ns * mem_clk_10khz;
return (code / 100000) + ((code % 100000) ? 1 : 0) - 1;
}
static inline u_int pxa2xx_pcmcia_cmd_time(u_int mem_clk_10khz,
u_int pcmcia_mcxx_asst)
{
return (300000 * (pcmcia_mcxx_asst + 1) / mem_clk_10khz);
}
static int pxa2xx_pcmcia_set_mcmem( int sock, int speed, int clock )
{
uint32_t val;
val = ((pxa2xx_mcxx_setup(speed, clock)
& MCXX_SETUP_MASK) << MCXX_SETUP_SHIFT)
| ((pxa2xx_mcxx_asst(speed, clock)
& MCXX_ASST_MASK) << MCXX_ASST_SHIFT)
| ((pxa2xx_mcxx_hold(speed, clock)
& MCXX_HOLD_MASK) << MCXX_HOLD_SHIFT);
__raw_writel(val, MCMEM(sock));
return 0;
}
static int pxa2xx_pcmcia_set_mcio( int sock, int speed, int clock )
{
uint32_t val;
val = ((pxa2xx_mcxx_setup(speed, clock)
& MCXX_SETUP_MASK) << MCXX_SETUP_SHIFT)
| ((pxa2xx_mcxx_asst(speed, clock)
& MCXX_ASST_MASK) << MCXX_ASST_SHIFT)
| ((pxa2xx_mcxx_hold(speed, clock)
& MCXX_HOLD_MASK) << MCXX_HOLD_SHIFT);
__raw_writel(val, MCIO(sock));
return 0;
}
static int pxa2xx_pcmcia_set_mcatt( int sock, int speed, int clock )
{
uint32_t val;
val = ((pxa2xx_mcxx_setup(speed, clock)
& MCXX_SETUP_MASK) << MCXX_SETUP_SHIFT)
| ((pxa2xx_mcxx_asst(speed, clock)
& MCXX_ASST_MASK) << MCXX_ASST_SHIFT)
| ((pxa2xx_mcxx_hold(speed, clock)
& MCXX_HOLD_MASK) << MCXX_HOLD_SHIFT);
__raw_writel(val, MCATT(sock));
return 0;
}
static int pxa2xx_pcmcia_set_mcxx(struct soc_pcmcia_socket *skt, unsigned int clk)
{
struct soc_pcmcia_timing timing;
int sock = skt->nr;
soc_common_pcmcia_get_timing(skt, &timing);
pxa2xx_pcmcia_set_mcmem(sock, timing.mem, clk);
pxa2xx_pcmcia_set_mcatt(sock, timing.attr, clk);
pxa2xx_pcmcia_set_mcio(sock, timing.io, clk);
return 0;
}
static int pxa2xx_pcmcia_set_timing(struct soc_pcmcia_socket *skt)
{
unsigned long clk = clk_get_rate(skt->clk);
return pxa2xx_pcmcia_set_mcxx(skt, clk / 10000);
}
static int
pxa2xx_pcmcia_frequency_change(struct soc_pcmcia_socket *skt,
unsigned long val,
struct cpufreq_freqs *freqs)
{
switch (val) {
case CPUFREQ_PRECHANGE:
if (freqs->new > freqs->old) {
debug(skt, 2, "new frequency %u.%uMHz > %u.%uMHz, "
"pre-updating\n",
freqs->new / 1000, (freqs->new / 100) % 10,
freqs->old / 1000, (freqs->old / 100) % 10);
pxa2xx_pcmcia_set_timing(skt);
}
break;
case CPUFREQ_POSTCHANGE:
if (freqs->new < freqs->old) {
debug(skt, 2, "new frequency %u.%uMHz < %u.%uMHz, "
"post-updating\n",
freqs->new / 1000, (freqs->new / 100) % 10,
freqs->old / 1000, (freqs->old / 100) % 10);
pxa2xx_pcmcia_set_timing(skt);
}
break;
}
return 0;
}
void pxa2xx_configure_sockets(struct device *dev, struct pcmcia_low_level *ops)
{
uint32_t mecr = MECR_CIT;
if ((ops->first + ops->nr) > 1 ||
machine_is_viper() || machine_is_arcom_zeus())
mecr |= MECR_NOS;
__raw_writel(mecr, MECR);
}
int pxa2xx_drv_pcmcia_add_one(struct soc_pcmcia_socket *skt)
{
skt->res_skt.start = _PCMCIA(skt->nr);
skt->res_skt.end = _PCMCIA(skt->nr) + PCMCIASp - 1;
skt->res_skt.name = skt_names[skt->nr];
skt->res_skt.flags = IORESOURCE_MEM;
skt->res_io.start = _PCMCIAIO(skt->nr);
skt->res_io.end = _PCMCIAIO(skt->nr) + PCMCIAIOSp - 1;
skt->res_io.name = "io";
skt->res_io.flags = IORESOURCE_MEM | IORESOURCE_BUSY;
skt->res_mem.start = _PCMCIAMem(skt->nr);
skt->res_mem.end = _PCMCIAMem(skt->nr) + PCMCIAMemSp - 1;
skt->res_mem.name = "memory";
skt->res_mem.flags = IORESOURCE_MEM;
skt->res_attr.start = _PCMCIAAttr(skt->nr);
skt->res_attr.end = _PCMCIAAttr(skt->nr) + PCMCIAAttrSp - 1;
skt->res_attr.name = "attribute";
skt->res_attr.flags = IORESOURCE_MEM;
return soc_pcmcia_add_one(skt);
}
void pxa2xx_drv_pcmcia_ops(struct pcmcia_low_level *ops)
{
ops->set_timing = pxa2xx_pcmcia_set_timing;
#ifdef CONFIG_CPU_FREQ
ops->frequency_change = pxa2xx_pcmcia_frequency_change;
#endif
}
static int pxa2xx_drv_pcmcia_probe(struct platform_device *dev)
{
int i, ret = 0;
struct pcmcia_low_level *ops;
struct skt_dev_info *sinfo;
struct soc_pcmcia_socket *skt;
struct clk *clk;
ops = (struct pcmcia_low_level *)dev->dev.platform_data;
if (!ops) {
ret = -ENODEV;
goto err0;
}
if (cpu_is_pxa320() && ops->nr > 1) {
dev_err(&dev->dev, "pxa320 supports only one pcmcia slot");
ret = -EINVAL;
goto err0;
}
clk = devm_clk_get(&dev->dev, NULL);
if (IS_ERR(clk))
return -ENODEV;
pxa2xx_drv_pcmcia_ops(ops);
sinfo = devm_kzalloc(&dev->dev, SKT_DEV_INFO_SIZE(ops->nr),
GFP_KERNEL);
if (!sinfo)
return -ENOMEM;
sinfo->nskt = ops->nr;
for (i = 0; i < ops->nr; i++) {
skt = &sinfo->skt[i];
skt->nr = ops->first + i;
skt->clk = clk;
soc_pcmcia_init_one(skt, ops, &dev->dev);
ret = pxa2xx_drv_pcmcia_add_one(skt);
if (ret)
goto err1;
}
pxa2xx_configure_sockets(&dev->dev, ops);
dev_set_drvdata(&dev->dev, sinfo);
return 0;
err1:
while (--i >= 0)
soc_pcmcia_remove_one(&sinfo->skt[i]);
err0:
return ret;
}
static int pxa2xx_drv_pcmcia_remove(struct platform_device *dev)
{
struct skt_dev_info *sinfo = platform_get_drvdata(dev);
int i;
for (i = 0; i < sinfo->nskt; i++)
soc_pcmcia_remove_one(&sinfo->skt[i]);
return 0;
}
static int pxa2xx_drv_pcmcia_resume(struct device *dev)
{
struct pcmcia_low_level *ops = (struct pcmcia_low_level *)dev->platform_data;
pxa2xx_configure_sockets(dev, ops);
return 0;
}
static int __init pxa2xx_pcmcia_init(void)
{
return platform_driver_register(&pxa2xx_pcmcia_driver);
}
static void __exit pxa2xx_pcmcia_exit(void)
{
platform_driver_unregister(&pxa2xx_pcmcia_driver);
}
