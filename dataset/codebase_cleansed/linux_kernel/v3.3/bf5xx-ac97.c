void bf5xx_pcm_to_ac97(struct ac97_frame *dst, const __u16 *src,
size_t count, unsigned int chan_mask)
{
while (count--) {
dst->ac97_tag = TAG_VALID;
if (chan_mask & SP_FL) {
dst->ac97_pcm_r = *src++;
dst->ac97_tag |= TAG_PCM_RIGHT;
}
if (chan_mask & SP_FR) {
dst->ac97_pcm_l = *src++;
dst->ac97_tag |= TAG_PCM_LEFT;
}
#if defined(CONFIG_SND_BF5XX_MULTICHAN_SUPPORT)
if (chan_mask & SP_SR) {
dst->ac97_sl = *src++;
dst->ac97_tag |= TAG_PCM_SL;
}
if (chan_mask & SP_SL) {
dst->ac97_sr = *src++;
dst->ac97_tag |= TAG_PCM_SR;
}
if (chan_mask & SP_LFE) {
dst->ac97_lfe = *src++;
dst->ac97_tag |= TAG_PCM_LFE;
}
if (chan_mask & SP_FC) {
dst->ac97_center = *src++;
dst->ac97_tag |= TAG_PCM_CENTER;
}
#endif
dst++;
}
}
void bf5xx_ac97_to_pcm(const struct ac97_frame *src, __u16 *dst,
size_t count)
{
while (count--) {
*(dst++) = src->ac97_pcm_l;
*(dst++) = src->ac97_pcm_r;
src++;
}
}
static unsigned int sport_tx_curr_frag(struct sport_device *sport)
{
return sport->tx_curr_frag = sport_curr_offset_tx(sport) /
sport->tx_fragsize;
}
static void enqueue_cmd(struct snd_ac97 *ac97, __u16 addr, __u16 data)
{
struct sport_device *sport = ac97_sport_handle;
int *cmd_count = sport->private_data;
int nextfrag = sport_tx_curr_frag(sport);
struct ac97_frame *nextwrite;
sport_incfrag(sport, &nextfrag, 1);
nextwrite = (struct ac97_frame *)(sport->tx_buf +
nextfrag * sport->tx_fragsize);
pr_debug("sport->tx_buf:%p, nextfrag:0x%x nextwrite:%p, cmd_count:%d\n",
sport->tx_buf, nextfrag, nextwrite, cmd_count[nextfrag]);
nextwrite[cmd_count[nextfrag]].ac97_tag |= TAG_CMD;
nextwrite[cmd_count[nextfrag]].ac97_addr = addr;
nextwrite[cmd_count[nextfrag]].ac97_data = data;
++cmd_count[nextfrag];
pr_debug("ac97_sport: Inserting %02x/%04x into fragment %d\n",
addr >> 8, data, nextfrag);
}
static unsigned short bf5xx_ac97_read(struct snd_ac97 *ac97,
unsigned short reg)
{
struct sport_device *sport_handle = ac97_sport_handle;
struct ac97_frame out_frame[2], in_frame[2];
pr_debug("%s enter 0x%x\n", __func__, reg);
if (sport_handle->tx_run || sport_handle->rx_run) {
pr_err("Could you send a mail to cliff.cai@analog.com "
"to report this?\n");
return -EFAULT;
}
memset(&out_frame, 0, 2 * sizeof(struct ac97_frame));
memset(&in_frame, 0, 2 * sizeof(struct ac97_frame));
out_frame[0].ac97_tag = TAG_VALID | TAG_CMD;
out_frame[0].ac97_addr = ((reg << 8) | 0x8000);
sport_send_and_recv(sport_handle, (unsigned char *)&out_frame,
(unsigned char *)&in_frame,
2 * sizeof(struct ac97_frame));
return in_frame[1].ac97_data;
}
void bf5xx_ac97_write(struct snd_ac97 *ac97, unsigned short reg,
unsigned short val)
{
struct sport_device *sport_handle = ac97_sport_handle;
pr_debug("%s enter 0x%x:0x%04x\n", __func__, reg, val);
if (sport_handle->tx_run) {
enqueue_cmd(ac97, (reg << 8), val);
enqueue_cmd(ac97, (reg << 8) | 0x8000, 0);
} else {
struct ac97_frame frame;
memset(&frame, 0, sizeof(struct ac97_frame));
frame.ac97_tag = TAG_VALID | TAG_CMD;
frame.ac97_addr = (reg << 8);
frame.ac97_data = val;
sport_send_and_recv(sport_handle, (unsigned char *)&frame, \
NULL, sizeof(struct ac97_frame));
}
}
static void bf5xx_ac97_warm_reset(struct snd_ac97 *ac97)
{
struct sport_device *sport_handle = ac97_sport_handle;
u16 gpio = P_IDENT(sport_handle->pin_req[3]);
pr_debug("%s enter\n", __func__);
peripheral_free_list(sport_handle->pin_req);
gpio_request(gpio, "bf5xx-ac97");
gpio_direction_output(gpio, 1);
udelay(2);
gpio_set_value(gpio, 0);
udelay(1);
gpio_free(gpio);
peripheral_request_list(sport_handle->pin_req, "soc-audio");
}
static void bf5xx_ac97_cold_reset(struct snd_ac97 *ac97)
{
#ifdef CONFIG_SND_BF5XX_HAVE_COLD_RESET
pr_debug("%s enter\n", __func__);
gpio_set_value(CONFIG_SND_BF5XX_RESET_GPIO_NUM, 0);
mdelay(1);
gpio_set_value(CONFIG_SND_BF5XX_RESET_GPIO_NUM, 1);
mdelay(1);
#else
pr_info("%s: Not implemented\n", __func__);
#endif
}
static int bf5xx_ac97_suspend(struct snd_soc_dai *dai)
{
struct sport_device *sport = snd_soc_dai_get_drvdata(dai);
pr_debug("%s : sport %d\n", __func__, dai->id);
if (!dai->active)
return 0;
if (dai->capture_active)
sport_rx_stop(sport);
if (dai->playback_active)
sport_tx_stop(sport);
return 0;
}
static int bf5xx_ac97_resume(struct snd_soc_dai *dai)
{
int ret;
struct sport_device *sport = snd_soc_dai_get_drvdata(dai);
pr_debug("%s : sport %d\n", __func__, dai->id);
if (!dai->active)
return 0;
#if defined(CONFIG_SND_BF5XX_MULTICHAN_SUPPORT)
ret = sport_set_multichannel(sport, 16, 0x3FF, 1);
#else
ret = sport_set_multichannel(sport, 16, 0x1F, 1);
#endif
if (ret) {
pr_err("SPORT is busy!\n");
return -EBUSY;
}
ret = sport_config_rx(sport, IRFS, 0xF, 0, (16*16-1));
if (ret) {
pr_err("SPORT is busy!\n");
return -EBUSY;
}
ret = sport_config_tx(sport, ITFS, 0xF, 0, (16*16-1));
if (ret) {
pr_err("SPORT is busy!\n");
return -EBUSY;
}
return 0;
}
static int __devinit asoc_bfin_ac97_probe(struct platform_device *pdev)
{
struct sport_device *sport_handle;
int ret;
#ifdef CONFIG_SND_BF5XX_HAVE_COLD_RESET
if (gpio_request(CONFIG_SND_BF5XX_RESET_GPIO_NUM, "SND_AD198x RESET")) {
pr_err("Failed to request GPIO_%d for reset\n",
CONFIG_SND_BF5XX_RESET_GPIO_NUM);
ret = -1;
goto gpio_err;
}
gpio_direction_output(CONFIG_SND_BF5XX_RESET_GPIO_NUM, 1);
#endif
sport_handle = sport_init(pdev, 2, sizeof(struct ac97_frame),
PAGE_SIZE);
if (!sport_handle) {
ret = -ENODEV;
goto sport_err;
}
#if defined(CONFIG_SND_BF5XX_MULTICHAN_SUPPORT)
ret = sport_set_multichannel(sport_handle, 16, 0x3FF, 1);
#else
ret = sport_set_multichannel(sport_handle, 16, 0x1F, 1);
#endif
if (ret) {
pr_err("SPORT is busy!\n");
ret = -EBUSY;
goto sport_config_err;
}
ret = sport_config_rx(sport_handle, IRFS, 0xF, 0, (16*16-1));
if (ret) {
pr_err("SPORT is busy!\n");
ret = -EBUSY;
goto sport_config_err;
}
ret = sport_config_tx(sport_handle, ITFS, 0xF, 0, (16*16-1));
if (ret) {
pr_err("SPORT is busy!\n");
ret = -EBUSY;
goto sport_config_err;
}
ret = snd_soc_register_dai(&pdev->dev, &bfin_ac97_dai);
if (ret) {
pr_err("Failed to register DAI: %d\n", ret);
goto sport_config_err;
}
ac97_sport_handle = sport_handle;
return 0;
sport_config_err:
sport_done(sport_handle);
sport_err:
#ifdef CONFIG_SND_BF5XX_HAVE_COLD_RESET
gpio_free(CONFIG_SND_BF5XX_RESET_GPIO_NUM);
gpio_err:
#endif
return ret;
}
static int __devexit asoc_bfin_ac97_remove(struct platform_device *pdev)
{
struct sport_device *sport_handle = platform_get_drvdata(pdev);
snd_soc_unregister_dai(&pdev->dev);
sport_done(sport_handle);
#ifdef CONFIG_SND_BF5XX_HAVE_COLD_RESET
gpio_free(CONFIG_SND_BF5XX_RESET_GPIO_NUM);
#endif
return 0;
}
