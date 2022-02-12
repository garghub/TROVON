static int adda_reg_read(void *context, unsigned int reg, unsigned int *val)
{
void __iomem *base = (void __iomem *)context;
u32 tmp;
writel(readl(base) | ADDA_PR_RESET, base);
writel(readl(base) & ~ADDA_PR_WRITE, base);
tmp = readl(base);
tmp &= ~(ADDA_PR_ADDR_MASK << ADDA_PR_ADDR_SHIFT);
tmp |= (reg & ADDA_PR_ADDR_MASK) << ADDA_PR_ADDR_SHIFT;
writel(tmp, base);
*val = readl(base) & ADDA_PR_DATA_OUT_MASK;
return 0;
}
static int adda_reg_write(void *context, unsigned int reg, unsigned int val)
{
void __iomem *base = (void __iomem *)context;
u32 tmp;
writel(readl(base) | ADDA_PR_RESET, base);
tmp = readl(base);
tmp &= ~(ADDA_PR_ADDR_MASK << ADDA_PR_ADDR_SHIFT);
tmp |= (reg & ADDA_PR_ADDR_MASK) << ADDA_PR_ADDR_SHIFT;
writel(tmp, base);
tmp = readl(base);
tmp &= ~(ADDA_PR_DATA_IN_MASK << ADDA_PR_DATA_IN_SHIFT);
tmp |= (val & ADDA_PR_DATA_IN_MASK) << ADDA_PR_DATA_IN_SHIFT;
writel(tmp, base);
writel(readl(base) | ADDA_PR_WRITE, base);
writel(readl(base) & ~ADDA_PR_WRITE, base);
return 0;
}
static int sun8i_headphone_amp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);
if (SND_SOC_DAPM_EVENT_ON(event)) {
snd_soc_component_update_bits(component, SUN8I_ADDA_PAEN_HP_CTRL,
BIT(SUN8I_ADDA_PAEN_HP_CTRL_HPPAEN),
BIT(SUN8I_ADDA_PAEN_HP_CTRL_HPPAEN));
msleep(700);
} else if (SND_SOC_DAPM_EVENT_OFF(event)) {
snd_soc_component_update_bits(component, SUN8I_ADDA_PAEN_HP_CTRL,
BIT(SUN8I_ADDA_PAEN_HP_CTRL_HPPAEN),
0x0);
}
return 0;
}
static int sun8i_codec_add_headphone(struct snd_soc_component *cmpnt)
{
struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(cmpnt);
struct device *dev = cmpnt->dev;
int ret;
ret = snd_soc_add_component_controls(cmpnt,
sun8i_codec_headphone_controls,
ARRAY_SIZE(sun8i_codec_headphone_controls));
if (ret) {
dev_err(dev, "Failed to add Headphone controls: %d\n", ret);
return ret;
}
ret = snd_soc_dapm_new_controls(dapm, sun8i_codec_headphone_widgets,
ARRAY_SIZE(sun8i_codec_headphone_widgets));
if (ret) {
dev_err(dev, "Failed to add Headphone DAPM widgets: %d\n", ret);
return ret;
}
ret = snd_soc_dapm_add_routes(dapm, sun8i_codec_headphone_routes,
ARRAY_SIZE(sun8i_codec_headphone_routes));
if (ret) {
dev_err(dev, "Failed to add Headphone DAPM routes: %d\n", ret);
return ret;
}
return 0;
}
static int sun8i_codec_add_hmic(struct snd_soc_component *cmpnt)
{
struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(cmpnt);
struct device *dev = cmpnt->dev;
int ret;
ret = snd_soc_dapm_new_controls(dapm, sun8i_codec_hmic_widgets,
ARRAY_SIZE(sun8i_codec_hmic_widgets));
if (ret)
dev_err(dev, "Failed to add Mic3 DAPM widgets: %d\n", ret);
return ret;
}
static int sun8i_codec_add_linein(struct snd_soc_component *cmpnt)
{
struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(cmpnt);
struct device *dev = cmpnt->dev;
int ret;
ret = snd_soc_add_component_controls(cmpnt,
sun8i_codec_linein_controls,
ARRAY_SIZE(sun8i_codec_linein_controls));
if (ret) {
dev_err(dev, "Failed to add Line In controls: %d\n", ret);
return ret;
}
ret = snd_soc_dapm_new_controls(dapm, sun8i_codec_linein_widgets,
ARRAY_SIZE(sun8i_codec_linein_widgets));
if (ret) {
dev_err(dev, "Failed to add Line In DAPM widgets: %d\n", ret);
return ret;
}
ret = snd_soc_dapm_add_routes(dapm, sun8i_codec_linein_routes,
ARRAY_SIZE(sun8i_codec_linein_routes));
if (ret) {
dev_err(dev, "Failed to add Line In DAPM routes: %d\n", ret);
return ret;
}
return 0;
}
static int sun8i_codec_add_lineout(struct snd_soc_component *cmpnt)
{
struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(cmpnt);
struct device *dev = cmpnt->dev;
int ret;
ret = snd_soc_add_component_controls(cmpnt,
sun8i_codec_lineout_controls,
ARRAY_SIZE(sun8i_codec_lineout_controls));
if (ret) {
dev_err(dev, "Failed to add Line Out controls: %d\n", ret);
return ret;
}
ret = snd_soc_dapm_new_controls(dapm, sun8i_codec_lineout_widgets,
ARRAY_SIZE(sun8i_codec_lineout_widgets));
if (ret) {
dev_err(dev, "Failed to add Line Out DAPM widgets: %d\n", ret);
return ret;
}
ret = snd_soc_dapm_add_routes(dapm, sun8i_codec_lineout_routes,
ARRAY_SIZE(sun8i_codec_lineout_routes));
if (ret) {
dev_err(dev, "Failed to add Line Out DAPM routes: %d\n", ret);
return ret;
}
return 0;
}
static int sun8i_codec_add_mic2(struct snd_soc_component *cmpnt)
{
struct snd_soc_dapm_context *dapm = snd_soc_component_get_dapm(cmpnt);
struct device *dev = cmpnt->dev;
int ret;
ret = snd_soc_add_component_controls(cmpnt,
sun8i_codec_mic2_controls,
ARRAY_SIZE(sun8i_codec_mic2_controls));
if (ret) {
dev_err(dev, "Failed to add MIC2 controls: %d\n", ret);
return ret;
}
ret = snd_soc_dapm_new_controls(dapm, sun8i_codec_mic2_widgets,
ARRAY_SIZE(sun8i_codec_mic2_widgets));
if (ret) {
dev_err(dev, "Failed to add MIC2 DAPM widgets: %d\n", ret);
return ret;
}
ret = snd_soc_dapm_add_routes(dapm, sun8i_codec_mic2_routes,
ARRAY_SIZE(sun8i_codec_mic2_routes));
if (ret) {
dev_err(dev, "Failed to add MIC2 DAPM routes: %d\n", ret);
return ret;
}
return 0;
}
static int sun8i_codec_analog_cmpnt_probe(struct snd_soc_component *cmpnt)
{
struct device *dev = cmpnt->dev;
const struct sun8i_codec_analog_quirks *quirks;
int ret;
quirks = of_device_get_match_data(dev);
if (quirks->has_headphone) {
ret = sun8i_codec_add_headphone(cmpnt);
if (ret)
return ret;
}
if (quirks->has_hmic) {
ret = sun8i_codec_add_hmic(cmpnt);
if (ret)
return ret;
}
if (quirks->has_linein) {
ret = sun8i_codec_add_linein(cmpnt);
if (ret)
return ret;
}
if (quirks->has_lineout) {
ret = sun8i_codec_add_lineout(cmpnt);
if (ret)
return ret;
}
if (quirks->has_mic2) {
ret = sun8i_codec_add_mic2(cmpnt);
if (ret)
return ret;
}
return 0;
}
static int sun8i_codec_analog_probe(struct platform_device *pdev)
{
struct resource *res;
struct regmap *regmap;
void __iomem *base;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base)) {
dev_err(&pdev->dev, "Failed to map the registers\n");
return PTR_ERR(base);
}
regmap = devm_regmap_init(&pdev->dev, NULL, base, &adda_pr_regmap_cfg);
if (IS_ERR(regmap)) {
dev_err(&pdev->dev, "Failed to create regmap\n");
return PTR_ERR(regmap);
}
return devm_snd_soc_register_component(&pdev->dev,
&sun8i_codec_analog_cmpnt_drv,
NULL, 0);
}
