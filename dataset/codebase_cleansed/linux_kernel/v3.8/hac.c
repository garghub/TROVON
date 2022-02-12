static int hac_get_codec_data(struct hac_priv *hac, unsigned short r,
unsigned short *v)
{
unsigned int to1, to2, i;
unsigned short adr;
for (i = AC97_READ_RETRY; i; i--) {
*v = 0;
for (to1 = TMO_E4;
to1 && !(HACREG(HACRSR) & RSR_STARY);
--to1)
udelay(1);
for (to2 = TMO_E4;
to2 && !(HACREG(HACRSR) & RSR_STDRY);
--to2)
udelay(1);
if (!to1 && !to2)
return 0;
adr = ((HACREG(HACCSAR) & CSAR_MASK) >> CSAR_SHIFT);
*v = ((HACREG(HACCSDR) & CSDR_MASK) >> CSDR_SHIFT);
HACREG(HACRSR) &= ~(RSR_STDRY | RSR_STARY);
if (r == adr)
break;
udelay(21);
}
HACREG(HACRSR) &= ~(RSR_STDRY | RSR_STARY);
return i;
}
static unsigned short hac_read_codec_aux(struct hac_priv *hac,
unsigned short reg)
{
unsigned short val;
unsigned int i, to;
for (i = AC97_READ_RETRY; i; i--) {
local_irq_disable();
HACREG(HACTSR) &= ~(TSR_CMDAMT);
HACREG(HACCSAR) = (reg << CSAR_SHIFT) | CSAR_RD;
local_irq_enable();
for (to = TMO_E3;
to && !(HACREG(HACTSR) & TSR_CMDAMT);
--to)
udelay(1);
HACREG(HACTSR) &= ~TSR_CMDAMT;
val = 0;
if (hac_get_codec_data(hac, reg, &val) != 0)
break;
}
return i ? val : ~0;
}
static void hac_ac97_write(struct snd_ac97 *ac97, unsigned short reg,
unsigned short val)
{
int unit_id = 0 ;
struct hac_priv *hac = &hac_cpu_data[unit_id];
unsigned int i, to;
for (i = AC97_WRITE_RETRY; i; i--) {
local_irq_disable();
HACREG(HACTSR) &= ~(TSR_CMDDMT | TSR_CMDAMT);
HACREG(HACCSDR) = (val << CSDR_SHIFT);
HACREG(HACCSAR) = (reg << CSAR_SHIFT) & (~CSAR_RD);
local_irq_enable();
for (to = TMO_E1;
to && !(HACREG(HACTSR) & (TSR_CMDAMT|TSR_CMDDMT));
--to)
udelay(1);
HACREG(HACTSR) &= ~(TSR_CMDAMT | TSR_CMDDMT);
if (to)
break;
}
}
static unsigned short hac_ac97_read(struct snd_ac97 *ac97,
unsigned short reg)
{
int unit_id = 0 ;
struct hac_priv *hac = &hac_cpu_data[unit_id];
return hac_read_codec_aux(hac, reg);
}
static void hac_ac97_warmrst(struct snd_ac97 *ac97)
{
int unit_id = 0 ;
struct hac_priv *hac = &hac_cpu_data[unit_id];
unsigned int tmo;
HACREG(HACCR) = CR_WMRT | CR_ST | CR_B9;
msleep(10);
HACREG(HACCR) = CR_ST | CR_B9;
for (tmo = 1000; (tmo > 0) && !(HACREG(HACCR) & CR_CR); tmo--)
udelay(1);
if (!tmo)
printk(KERN_INFO "hac: reset: AC97 link down!\n");
HACREG(HACACR) |= ACR_TX12ATOM;
}
static void hac_ac97_coldrst(struct snd_ac97 *ac97)
{
int unit_id = 0 ;
struct hac_priv *hac;
hac = &hac_cpu_data[unit_id];
HACREG(HACCR) = 0;
HACREG(HACCR) = CR_CDRT | CR_ST | CR_B9;
msleep(10);
hac_ac97_warmrst(ac97);
}
static int hac_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct hac_priv *hac = &hac_cpu_data[dai->id];
int d = substream->stream == SNDRV_PCM_STREAM_PLAYBACK ? 0 : 1;
switch (params->msbits) {
case 16:
HACREG(HACACR) |= d ? ACR_DMARX16 : ACR_DMATX16;
HACREG(HACACR) &= d ? ~ACR_DMARX20 : ~ACR_DMATX20;
break;
case 20:
HACREG(HACACR) &= d ? ~ACR_DMARX16 : ~ACR_DMATX16;
HACREG(HACACR) |= d ? ACR_DMARX20 : ACR_DMATX20;
break;
default:
pr_debug("hac: invalid depth %d bit\n", params->msbits);
return -EINVAL;
break;
}
return 0;
}
static int hac_soc_platform_probe(struct platform_device *pdev)
{
return snd_soc_register_dais(&pdev->dev, sh4_hac_dai,
ARRAY_SIZE(sh4_hac_dai));
}
static int hac_soc_platform_remove(struct platform_device *pdev)
{
snd_soc_unregister_dais(&pdev->dev, ARRAY_SIZE(sh4_hac_dai));
return 0;
}
