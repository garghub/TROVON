static int __init config_pcmcia_cs(unsigned int cs,
u32 base, unsigned int size)
{
int ret;
ret = bcm63xx_set_cs_status(cs, 0);
if (!ret)
ret = bcm63xx_set_cs_base(cs, base, size);
if (!ret)
ret = bcm63xx_set_cs_status(cs, 1);
return ret;
}
int __init bcm63xx_pcmcia_register(void)
{
int ret, i;
if (!BCMCPU_IS_6348() && !BCMCPU_IS_6358())
return 0;
switch (bcm63xx_get_cpu_id()) {
case BCM6348_CPU_ID:
pd.ready_gpio = 22;
break;
case BCM6358_CPU_ID:
pd.ready_gpio = 18;
break;
default:
return -ENODEV;
}
pcmcia_resources[0].start = bcm63xx_regset_address(RSET_PCMCIA);
pcmcia_resources[0].end = pcmcia_resources[0].start +
RSET_PCMCIA_SIZE - 1;
pcmcia_resources[4].start = bcm63xx_get_irq_number(IRQ_PCMCIA);
for (i = 0; i < 3; i++) {
ret = config_pcmcia_cs(pcmcia_cs[i].cs,
pcmcia_cs[i].base,
pcmcia_cs[i].size);
if (ret)
goto out_err;
}
return platform_device_register(&bcm63xx_pcmcia_device);
out_err:
pr_err("unable to set pcmcia chip select\n");
return ret;
}
