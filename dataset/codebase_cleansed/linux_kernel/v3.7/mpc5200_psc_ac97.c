static unsigned short psc_ac97_read(struct snd_ac97 *ac97, unsigned short reg)
{
int status;
unsigned int val;
mutex_lock(&psc_dma->mutex);
status = spin_event_timeout(!(in_be16(&psc_dma->psc_regs->sr_csr.status) &
MPC52xx_PSC_SR_CMDSEND), 100, 0);
if (status == 0) {
pr_err("timeout on ac97 bus (rdy)\n");
mutex_unlock(&psc_dma->mutex);
return -ENODEV;
}
in_be32(&psc_dma->psc_regs->ac97_data);
out_be32(&psc_dma->psc_regs->ac97_cmd, (1<<31) | ((reg & 0x7f) << 24));
status = spin_event_timeout((in_be16(&psc_dma->psc_regs->sr_csr.status) &
MPC52xx_PSC_SR_DATA_VAL), 100, 0);
if (status == 0) {
pr_err("timeout on ac97 read (val) %x\n",
in_be16(&psc_dma->psc_regs->sr_csr.status));
mutex_unlock(&psc_dma->mutex);
return -ENODEV;
}
val = in_be32(&psc_dma->psc_regs->ac97_data);
if (((val >> 24) & 0x7f) != reg) {
pr_err("reg echo error on ac97 read\n");
mutex_unlock(&psc_dma->mutex);
return -ENODEV;
}
val = (val >> 8) & 0xffff;
mutex_unlock(&psc_dma->mutex);
return (unsigned short) val;
}
static void psc_ac97_write(struct snd_ac97 *ac97,
unsigned short reg, unsigned short val)
{
int status;
mutex_lock(&psc_dma->mutex);
status = spin_event_timeout(!(in_be16(&psc_dma->psc_regs->sr_csr.status) &
MPC52xx_PSC_SR_CMDSEND), 100, 0);
if (status == 0) {
pr_err("timeout on ac97 bus (write)\n");
goto out;
}
out_be32(&psc_dma->psc_regs->ac97_cmd,
((reg & 0x7f) << 24) | (val << 8));
out:
mutex_unlock(&psc_dma->mutex);
}
static void psc_ac97_warm_reset(struct snd_ac97 *ac97)
{
struct mpc52xx_psc __iomem *regs = psc_dma->psc_regs;
mutex_lock(&psc_dma->mutex);
out_be32(&regs->sicr, psc_dma->sicr | MPC52xx_PSC_SICR_AWR);
udelay(3);
out_be32(&regs->sicr, psc_dma->sicr);
mutex_unlock(&psc_dma->mutex);
}
static void psc_ac97_cold_reset(struct snd_ac97 *ac97)
{
struct mpc52xx_psc __iomem *regs = psc_dma->psc_regs;
mutex_lock(&psc_dma->mutex);
dev_dbg(psc_dma->dev, "cold reset\n");
mpc5200_psc_ac97_gpio_reset(psc_dma->id);
out_be32(&regs->sicr, psc_dma->sicr | MPC52xx_PSC_SICR_ACRB);
out_8(&regs->command, MPC52xx_PSC_TX_ENABLE | MPC52xx_PSC_RX_ENABLE);
mutex_unlock(&psc_dma->mutex);
msleep(1);
psc_ac97_warm_reset(ac97);
}
static int psc_ac97_hw_analog_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *cpu_dai)
{
struct psc_dma *psc_dma = snd_soc_dai_get_drvdata(cpu_dai);
struct psc_dma_stream *s = to_psc_dma_stream(substream, psc_dma);
dev_dbg(psc_dma->dev, "%s(substream=%p) p_size=%i p_bytes=%i"
" periods=%i buffer_size=%i buffer_bytes=%i channels=%i"
" rate=%i format=%i\n",
__func__, substream, params_period_size(params),
params_period_bytes(params), params_periods(params),
params_buffer_size(params), params_buffer_bytes(params),
params_channels(params), params_rate(params),
params_format(params));
s->ac97_slot_bits = (params_channels(params) == 1) ? 0x100 : 0x300;
if (substream->pstr->stream != SNDRV_PCM_STREAM_CAPTURE)
s->ac97_slot_bits <<= 16;
return 0;
}
static int psc_ac97_hw_digital_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *cpu_dai)
{
struct psc_dma *psc_dma = snd_soc_dai_get_drvdata(cpu_dai);
dev_dbg(psc_dma->dev, "%s(substream=%p)\n", __func__, substream);
if (params_channels(params) == 1)
out_be32(&psc_dma->psc_regs->ac97_slots, 0x01000000);
else
out_be32(&psc_dma->psc_regs->ac97_slots, 0x03000000);
return 0;
}
static int psc_ac97_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct psc_dma *psc_dma = snd_soc_dai_get_drvdata(dai);
struct psc_dma_stream *s = to_psc_dma_stream(substream, psc_dma);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
dev_dbg(psc_dma->dev, "AC97 START: stream=%i\n",
substream->pstr->stream);
psc_dma->slots |= s->ac97_slot_bits;
out_be32(&psc_dma->psc_regs->ac97_slots, psc_dma->slots);
break;
case SNDRV_PCM_TRIGGER_STOP:
dev_dbg(psc_dma->dev, "AC97 STOP: stream=%i\n",
substream->pstr->stream);
psc_dma->slots &= ~(s->ac97_slot_bits);
out_be32(&psc_dma->psc_regs->ac97_slots, psc_dma->slots);
break;
}
return 0;
}
static int psc_ac97_probe(struct snd_soc_dai *cpu_dai)
{
struct psc_dma *psc_dma = snd_soc_dai_get_drvdata(cpu_dai);
struct mpc52xx_psc __iomem *regs = psc_dma->psc_regs;
out_8(&regs->command, MPC52xx_PSC_TX_ENABLE | MPC52xx_PSC_RX_ENABLE);
return 0;
}
static int __devinit psc_ac97_of_probe(struct platform_device *op)
{
int rc;
struct snd_ac97 ac97;
struct mpc52xx_psc __iomem *regs;
rc = mpc5200_audio_dma_create(op);
if (rc != 0)
return rc;
rc = snd_soc_register_dais(&op->dev, psc_ac97_dai, ARRAY_SIZE(psc_ac97_dai));
if (rc != 0) {
dev_err(&op->dev, "Failed to register DAI\n");
return rc;
}
psc_dma = dev_get_drvdata(&op->dev);
regs = psc_dma->psc_regs;
ac97.private_data = psc_dma;
psc_dma->imr = 0;
out_be16(&psc_dma->psc_regs->isr_imr.imr, psc_dma->imr);
psc_dma->sicr = MPC52xx_PSC_SICR_SIM_AC97 | MPC52xx_PSC_SICR_ENAC97;
out_be32(&regs->sicr, psc_dma->sicr);
out_be32(&regs->ac97_slots, 0x00000000);
return 0;
}
static int __devexit psc_ac97_of_remove(struct platform_device *op)
{
mpc5200_audio_dma_destroy(op);
snd_soc_unregister_dais(&op->dev, ARRAY_SIZE(psc_ac97_dai));
return 0;
}
