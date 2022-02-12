static int __init cmx2xx_pcmcia_init(void)
{
int ret = -ENODEV;
if (machine_is_armcore() && cpu_is_pxa25x())
ret = cmx255_pcmcia_init();
else if (machine_is_armcore() && cpu_is_pxa27x())
ret = cmx270_pcmcia_init();
return ret;
}
static void __exit cmx2xx_pcmcia_exit(void)
{
if (machine_is_armcore() && cpu_is_pxa25x())
cmx255_pcmcia_exit();
else if (machine_is_armcore() && cpu_is_pxa27x())
cmx270_pcmcia_exit();
}
