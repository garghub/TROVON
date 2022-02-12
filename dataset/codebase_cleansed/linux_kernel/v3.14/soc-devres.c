static void devm_component_release(struct device *dev, void *res)
{
snd_soc_unregister_component(*(struct device **)res);
}
int devm_snd_soc_register_component(struct device *dev,
const struct snd_soc_component_driver *cmpnt_drv,
struct snd_soc_dai_driver *dai_drv, int num_dai)
{
struct device **ptr;
int ret;
ptr = devres_alloc(devm_component_release, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return -ENOMEM;
ret = snd_soc_register_component(dev, cmpnt_drv, dai_drv, num_dai);
if (ret == 0) {
*ptr = dev;
devres_add(dev, ptr);
} else {
devres_free(ptr);
}
return ret;
}
static void devm_card_release(struct device *dev, void *res)
{
snd_soc_unregister_card(*(struct snd_soc_card **)res);
}
int devm_snd_soc_register_card(struct device *dev, struct snd_soc_card *card)
{
struct snd_soc_card **ptr;
int ret;
ptr = devres_alloc(devm_card_release, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return -ENOMEM;
ret = snd_soc_register_card(card);
if (ret == 0) {
*ptr = card;
devres_add(dev, ptr);
} else {
devres_free(ptr);
}
return ret;
}
static void devm_dmaengine_pcm_release(struct device *dev, void *res)
{
snd_dmaengine_pcm_unregister(*(struct device **)res);
}
int devm_snd_dmaengine_pcm_register(struct device *dev,
const struct snd_dmaengine_pcm_config *config, unsigned int flags)
{
struct device **ptr;
int ret;
ptr = devres_alloc(devm_dmaengine_pcm_release, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return -ENOMEM;
ret = snd_dmaengine_pcm_register(dev, config, flags);
if (ret == 0) {
*ptr = dev;
devres_add(dev, ptr);
} else {
devres_free(ptr);
}
return ret;
}
