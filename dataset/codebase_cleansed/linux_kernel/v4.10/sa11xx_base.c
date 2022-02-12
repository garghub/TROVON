static unsigned int
sa1100_pcmcia_default_mecr_timing(struct soc_pcmcia_socket *skt,
unsigned int cpu_speed,
unsigned int cmd_time)
{
return sa1100_pcmcia_mecr_bs(cmd_time, cpu_speed);
}
static int
sa1100_pcmcia_set_mecr(struct soc_pcmcia_socket *skt, unsigned int cpu_clock)
{
struct soc_pcmcia_timing timing;
u32 mecr, old_mecr;
unsigned long flags;
unsigned int bs_io, bs_mem, bs_attr;
soc_common_pcmcia_get_timing(skt, &timing);
bs_io = skt->ops->get_timing(skt, cpu_clock, timing.io);
bs_mem = skt->ops->get_timing(skt, cpu_clock, timing.mem);
bs_attr = skt->ops->get_timing(skt, cpu_clock, timing.attr);
local_irq_save(flags);
old_mecr = mecr = MECR;
MECR_FAST_SET(mecr, skt->nr, 0);
MECR_BSIO_SET(mecr, skt->nr, bs_io);
MECR_BSA_SET(mecr, skt->nr, bs_attr);
MECR_BSM_SET(mecr, skt->nr, bs_mem);
if (old_mecr != mecr)
MECR = mecr;
local_irq_restore(flags);
debug(skt, 2, "FAST %X BSM %X BSA %X BSIO %X\n",
MECR_FAST_GET(mecr, skt->nr),
MECR_BSM_GET(mecr, skt->nr), MECR_BSA_GET(mecr, skt->nr),
MECR_BSIO_GET(mecr, skt->nr));
return 0;
}
static int
sa1100_pcmcia_frequency_change(struct soc_pcmcia_socket *skt,
unsigned long val,
struct cpufreq_freqs *freqs)
{
switch (val) {
case CPUFREQ_PRECHANGE:
if (freqs->new > freqs->old)
sa1100_pcmcia_set_mecr(skt, freqs->new);
break;
case CPUFREQ_POSTCHANGE:
if (freqs->new < freqs->old)
sa1100_pcmcia_set_mecr(skt, freqs->new);
break;
}
return 0;
}
static int
sa1100_pcmcia_set_timing(struct soc_pcmcia_socket *skt)
{
unsigned long clk = clk_get_rate(skt->clk);
return sa1100_pcmcia_set_mecr(skt, clk / 1000);
}
static int
sa1100_pcmcia_show_timing(struct soc_pcmcia_socket *skt, char *buf)
{
struct soc_pcmcia_timing timing;
unsigned int clock = clk_get_rate(skt->clk) / 1000;
unsigned long mecr = MECR;
char *p = buf;
soc_common_pcmcia_get_timing(skt, &timing);
p+=sprintf(p, "I/O : %uns (%uns)\n", timing.io,
sa1100_pcmcia_cmd_time(clock, MECR_BSIO_GET(mecr, skt->nr)));
p+=sprintf(p, "attribute: %uns (%uns)\n", timing.attr,
sa1100_pcmcia_cmd_time(clock, MECR_BSA_GET(mecr, skt->nr)));
p+=sprintf(p, "common : %uns (%uns)\n", timing.mem,
sa1100_pcmcia_cmd_time(clock, MECR_BSM_GET(mecr, skt->nr)));
return p - buf;
}
int sa11xx_drv_pcmcia_add_one(struct soc_pcmcia_socket *skt)
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
void sa11xx_drv_pcmcia_ops(struct pcmcia_low_level *ops)
{
if (!ops->get_timing)
ops->get_timing = sa1100_pcmcia_default_mecr_timing;
ops->set_timing = sa1100_pcmcia_set_timing;
ops->show_timing = sa1100_pcmcia_show_timing;
#ifdef CONFIG_CPU_FREQ
ops->frequency_change = sa1100_pcmcia_frequency_change;
#endif
}
int sa11xx_drv_pcmcia_probe(struct device *dev, struct pcmcia_low_level *ops,
int first, int nr)
{
struct skt_dev_info *sinfo;
struct soc_pcmcia_socket *skt;
int i, ret = 0;
struct clk *clk;
clk = devm_clk_get(dev, NULL);
if (IS_ERR(clk))
return PTR_ERR(clk);
sa11xx_drv_pcmcia_ops(ops);
sinfo = devm_kzalloc(dev, SKT_DEV_INFO_SIZE(nr), GFP_KERNEL);
if (!sinfo)
return -ENOMEM;
sinfo->nskt = nr;
for (i = 0; i < nr; i++) {
skt = &sinfo->skt[i];
skt->nr = first + i;
skt->clk = clk;
soc_pcmcia_init_one(skt, ops, dev);
ret = sa11xx_drv_pcmcia_add_one(skt);
if (ret)
break;
}
if (ret) {
while (--i >= 0)
soc_pcmcia_remove_one(&sinfo->skt[i]);
} else {
dev_set_drvdata(dev, sinfo);
}
return ret;
}
