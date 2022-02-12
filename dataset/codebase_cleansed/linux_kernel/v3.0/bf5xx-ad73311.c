static int snd_ad73311_startup(void)
{
pr_debug("%s enter\n", __func__);
gpio_set_value(GPIO_SE, 1);
return 0;
}
static int snd_ad73311_configure(void)
{
unsigned short ctrl_regs[6];
unsigned short status = 0;
int count = 0;
ctrl_regs[0] = AD_CONTROL | AD_WRITE | CTRL_REG_B | REGB_MCDIV(0) | \
REGB_SCDIV(0) | REGB_DIRATE(0);
ctrl_regs[1] = AD_CONTROL | AD_WRITE | CTRL_REG_C | REGC_PUDEV | \
REGC_PUADC | REGC_PUDAC | REGC_PUREF | REGC_REFUSE ;
ctrl_regs[2] = AD_CONTROL | AD_WRITE | CTRL_REG_D | REGD_OGS(2) | \
REGD_IGS(2);
ctrl_regs[3] = AD_CONTROL | AD_WRITE | CTRL_REG_E | REGE_DA(0x1f);
ctrl_regs[4] = AD_CONTROL | AD_WRITE | CTRL_REG_F | REGF_SEEN ;
ctrl_regs[5] = AD_CONTROL | AD_WRITE | CTRL_REG_A | REGA_MODE_DATA;
local_irq_disable();
snd_ad73311_startup();
udelay(1);
bfin_write_SPORT_TCR1(TFSR);
bfin_write_SPORT_TCR2(0xF);
SSYNC();
for (count = 0; count < 6; count++)
bfin_write_SPORT_TX16(ctrl_regs[count]);
SSYNC();
bfin_write_SPORT_TCR1(bfin_read_SPORT_TCR1() | TSPEN);
SSYNC();
while (!(status & TUVF) && ++count < 10000) {
udelay(1);
status = bfin_read_SPORT_STAT();
SSYNC();
}
bfin_write_SPORT_TCR1(bfin_read_SPORT_TCR1() & ~TSPEN);
SSYNC();
local_irq_enable();
if (count >= 10000) {
printk(KERN_ERR "ad73311: failed to configure codec\n");
return -1;
}
return 0;
}
static int bf5xx_probe(struct platform_device *pdev)
{
int err;
if (gpio_request(GPIO_SE, "AD73311_SE")) {
printk(KERN_ERR "%s: Failed ro request GPIO_%d\n", __func__, GPIO_SE);
return -EBUSY;
}
gpio_direction_output(GPIO_SE, 0);
err = snd_ad73311_configure();
if (err < 0)
return -EFAULT;
return 0;
}
static int bf5xx_ad73311_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
int ret = 0;
pr_debug("%s rate %d format %x\n", __func__, params_rate(params),
params_format(params));
ret = snd_soc_dai_set_fmt(cpu_dai, SND_SOC_DAIFMT_DSP_A |
SND_SOC_DAIFMT_NB_NF | SND_SOC_DAIFMT_CBM_CFM);
if (ret < 0)
return ret;
return 0;
}
static int __init bf5xx_ad73311_init(void)
{
int ret;
pr_debug("%s enter\n", __func__);
bf5xx_ad73311_snd_device = platform_device_alloc("soc-audio", -1);
if (!bf5xx_ad73311_snd_device)
return -ENOMEM;
platform_set_drvdata(bf5xx_ad73311_snd_device, &bf5xx_ad73311);
ret = platform_device_add(bf5xx_ad73311_snd_device);
if (ret)
platform_device_put(bf5xx_ad73311_snd_device);
return ret;
}
static void __exit bf5xx_ad73311_exit(void)
{
pr_debug("%s enter\n", __func__);
platform_device_unregister(bf5xx_ad73311_snd_device);
}
