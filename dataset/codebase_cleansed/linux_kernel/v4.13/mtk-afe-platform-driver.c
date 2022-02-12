static snd_pcm_uframes_t mtk_afe_pcm_pointer
(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
struct mtk_base_afe_memif *memif = &afe->memif[rtd->cpu_dai->id];
const struct mtk_base_memif_data *memif_data = memif->data;
struct regmap *regmap = afe->regmap;
struct device *dev = afe->dev;
int reg_ofs_base = memif_data->reg_ofs_base;
int reg_ofs_cur = memif_data->reg_ofs_cur;
unsigned int hw_ptr = 0, hw_base = 0;
int ret, pcm_ptr_bytes;
ret = regmap_read(regmap, reg_ofs_cur, &hw_ptr);
if (ret || hw_ptr == 0) {
dev_err(dev, "%s hw_ptr err\n", __func__);
pcm_ptr_bytes = 0;
goto POINTER_RETURN_FRAMES;
}
ret = regmap_read(regmap, reg_ofs_base, &hw_base);
if (ret || hw_base == 0) {
dev_err(dev, "%s hw_ptr err\n", __func__);
pcm_ptr_bytes = 0;
goto POINTER_RETURN_FRAMES;
}
pcm_ptr_bytes = hw_ptr - hw_base;
POINTER_RETURN_FRAMES:
return bytes_to_frames(substream->runtime, pcm_ptr_bytes);
}
static int mtk_afe_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
size_t size;
struct snd_card *card = rtd->card->snd_card;
struct snd_pcm *pcm = rtd->pcm;
struct mtk_base_afe *afe = snd_soc_platform_get_drvdata(rtd->platform);
size = afe->mtk_afe_hardware->buffer_bytes_max;
return snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
card->dev, size, size);
}
static void mtk_afe_pcm_free(struct snd_pcm *pcm)
{
snd_pcm_lib_preallocate_free_for_all(pcm);
}
