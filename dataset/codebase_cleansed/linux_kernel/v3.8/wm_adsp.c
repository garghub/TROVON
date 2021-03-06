static struct wm_adsp_region const *wm_adsp_find_region(struct wm_adsp *dsp,
int type)
{
int i;
for (i = 0; i < dsp->num_mems; i++)
if (dsp->mem[i].type == type)
return &dsp->mem[i];
return NULL;
}
static int wm_adsp_load(struct wm_adsp *dsp)
{
const struct firmware *firmware;
struct regmap *regmap = dsp->regmap;
unsigned int pos = 0;
const struct wmfw_header *header;
const struct wmfw_adsp1_sizes *adsp1_sizes;
const struct wmfw_adsp2_sizes *adsp2_sizes;
const struct wmfw_footer *footer;
const struct wmfw_region *region;
const struct wm_adsp_region *mem;
const char *region_name;
char *file, *text;
void *buf;
unsigned int reg;
int regions = 0;
int ret, offset, type, sizes;
file = kzalloc(PAGE_SIZE, GFP_KERNEL);
if (file == NULL)
return -ENOMEM;
snprintf(file, PAGE_SIZE, "%s-dsp%d.wmfw", dsp->part, dsp->num);
file[PAGE_SIZE - 1] = '\0';
ret = request_firmware(&firmware, file, dsp->dev);
if (ret != 0) {
adsp_err(dsp, "Failed to request '%s'\n", file);
goto out;
}
ret = -EINVAL;
pos = sizeof(*header) + sizeof(*adsp1_sizes) + sizeof(*footer);
if (pos >= firmware->size) {
adsp_err(dsp, "%s: file too short, %zu bytes\n",
file, firmware->size);
goto out_fw;
}
header = (void*)&firmware->data[0];
if (memcmp(&header->magic[0], "WMFW", 4) != 0) {
adsp_err(dsp, "%s: invalid magic\n", file);
goto out_fw;
}
if (header->ver != 0) {
adsp_err(dsp, "%s: unknown file format %d\n",
file, header->ver);
goto out_fw;
}
if (header->core != dsp->type) {
adsp_err(dsp, "%s: invalid core %d != %d\n",
file, header->core, dsp->type);
goto out_fw;
}
switch (dsp->type) {
case WMFW_ADSP1:
pos = sizeof(*header) + sizeof(*adsp1_sizes) + sizeof(*footer);
adsp1_sizes = (void *)&(header[1]);
footer = (void *)&(adsp1_sizes[1]);
sizes = sizeof(*adsp1_sizes);
adsp_dbg(dsp, "%s: %d DM, %d PM, %d ZM\n",
file, le32_to_cpu(adsp1_sizes->dm),
le32_to_cpu(adsp1_sizes->pm),
le32_to_cpu(adsp1_sizes->zm));
break;
case WMFW_ADSP2:
pos = sizeof(*header) + sizeof(*adsp2_sizes) + sizeof(*footer);
adsp2_sizes = (void *)&(header[1]);
footer = (void *)&(adsp2_sizes[1]);
sizes = sizeof(*adsp2_sizes);
adsp_dbg(dsp, "%s: %d XM, %d YM %d PM, %d ZM\n",
file, le32_to_cpu(adsp2_sizes->xm),
le32_to_cpu(adsp2_sizes->ym),
le32_to_cpu(adsp2_sizes->pm),
le32_to_cpu(adsp2_sizes->zm));
break;
default:
BUG_ON(NULL == "Unknown DSP type");
goto out_fw;
}
if (le32_to_cpu(header->len) != sizeof(*header) +
sizes + sizeof(*footer)) {
adsp_err(dsp, "%s: unexpected header length %d\n",
file, le32_to_cpu(header->len));
goto out_fw;
}
adsp_dbg(dsp, "%s: timestamp %llu\n", file,
le64_to_cpu(footer->timestamp));
while (pos < firmware->size &&
pos - firmware->size > sizeof(*region)) {
region = (void *)&(firmware->data[pos]);
region_name = "Unknown";
reg = 0;
text = NULL;
offset = le32_to_cpu(region->offset) & 0xffffff;
type = be32_to_cpu(region->type) & 0xff;
mem = wm_adsp_find_region(dsp, type);
switch (type) {
case WMFW_NAME_TEXT:
region_name = "Firmware name";
text = kzalloc(le32_to_cpu(region->len) + 1,
GFP_KERNEL);
break;
case WMFW_INFO_TEXT:
region_name = "Information";
text = kzalloc(le32_to_cpu(region->len) + 1,
GFP_KERNEL);
break;
case WMFW_ABSOLUTE:
region_name = "Absolute";
reg = offset;
break;
case WMFW_ADSP1_PM:
BUG_ON(!mem);
region_name = "PM";
reg = mem->base + (offset * 3);
break;
case WMFW_ADSP1_DM:
BUG_ON(!mem);
region_name = "DM";
reg = mem->base + (offset * 2);
break;
case WMFW_ADSP2_XM:
BUG_ON(!mem);
region_name = "XM";
reg = mem->base + (offset * 2);
break;
case WMFW_ADSP2_YM:
BUG_ON(!mem);
region_name = "YM";
reg = mem->base + (offset * 2);
break;
case WMFW_ADSP1_ZM:
BUG_ON(!mem);
region_name = "ZM";
reg = mem->base + (offset * 2);
break;
default:
adsp_warn(dsp,
"%s.%d: Unknown region type %x at %d(%x)\n",
file, regions, type, pos, pos);
break;
}
adsp_dbg(dsp, "%s.%d: %d bytes at %d in %s\n", file,
regions, le32_to_cpu(region->len), offset,
region_name);
if (text) {
memcpy(text, region->data, le32_to_cpu(region->len));
adsp_info(dsp, "%s: %s\n", file, text);
kfree(text);
}
if (reg) {
buf = kmemdup(region->data, le32_to_cpu(region->len),
GFP_KERNEL | GFP_DMA);
if (!buf) {
adsp_err(dsp, "Out of memory\n");
return -ENOMEM;
}
ret = regmap_raw_write(regmap, reg, buf,
le32_to_cpu(region->len));
kfree(buf);
if (ret != 0) {
adsp_err(dsp,
"%s.%d: Failed to write %d bytes at %d in %s: %d\n",
file, regions,
le32_to_cpu(region->len), offset,
region_name, ret);
goto out_fw;
}
}
pos += le32_to_cpu(region->len) + sizeof(*region);
regions++;
}
if (pos > firmware->size)
adsp_warn(dsp, "%s.%d: %zu bytes at end of file\n",
file, regions, pos - firmware->size);
out_fw:
release_firmware(firmware);
out:
kfree(file);
return ret;
}
static int wm_adsp_load_coeff(struct wm_adsp *dsp)
{
struct regmap *regmap = dsp->regmap;
struct wmfw_coeff_hdr *hdr;
struct wmfw_coeff_item *blk;
const struct firmware *firmware;
const char *region_name;
int ret, pos, blocks, type, offset, reg;
char *file;
void *buf;
file = kzalloc(PAGE_SIZE, GFP_KERNEL);
if (file == NULL)
return -ENOMEM;
snprintf(file, PAGE_SIZE, "%s-dsp%d.bin", dsp->part, dsp->num);
file[PAGE_SIZE - 1] = '\0';
ret = request_firmware(&firmware, file, dsp->dev);
if (ret != 0) {
adsp_warn(dsp, "Failed to request '%s'\n", file);
ret = 0;
goto out;
}
ret = -EINVAL;
if (sizeof(*hdr) >= firmware->size) {
adsp_err(dsp, "%s: file too short, %zu bytes\n",
file, firmware->size);
goto out_fw;
}
hdr = (void*)&firmware->data[0];
if (memcmp(hdr->magic, "WMDR", 4) != 0) {
adsp_err(dsp, "%s: invalid magic\n", file);
goto out_fw;
}
adsp_dbg(dsp, "%s: v%d.%d.%d\n", file,
(le32_to_cpu(hdr->ver) >> 16) & 0xff,
(le32_to_cpu(hdr->ver) >> 8) & 0xff,
le32_to_cpu(hdr->ver) & 0xff);
pos = le32_to_cpu(hdr->len);
blocks = 0;
while (pos < firmware->size &&
pos - firmware->size > sizeof(*blk)) {
blk = (void*)(&firmware->data[pos]);
type = be32_to_cpu(blk->type) & 0xff;
offset = le32_to_cpu(blk->offset) & 0xffffff;
adsp_dbg(dsp, "%s.%d: %x v%d.%d.%d\n",
file, blocks, le32_to_cpu(blk->id),
(le32_to_cpu(blk->ver) >> 16) & 0xff,
(le32_to_cpu(blk->ver) >> 8) & 0xff,
le32_to_cpu(blk->ver) & 0xff);
adsp_dbg(dsp, "%s.%d: %d bytes at 0x%x in %x\n",
file, blocks, le32_to_cpu(blk->len), offset, type);
reg = 0;
region_name = "Unknown";
switch (type) {
case WMFW_NAME_TEXT:
case WMFW_INFO_TEXT:
break;
case WMFW_ABSOLUTE:
region_name = "register";
reg = offset;
break;
default:
adsp_err(dsp, "Unknown region type %x\n", type);
break;
}
if (reg) {
buf = kmemdup(blk->data, le32_to_cpu(blk->len),
GFP_KERNEL | GFP_DMA);
if (!buf) {
adsp_err(dsp, "Out of memory\n");
return -ENOMEM;
}
ret = regmap_raw_write(regmap, reg, blk->data,
le32_to_cpu(blk->len));
if (ret != 0) {
adsp_err(dsp,
"%s.%d: Failed to write to %x in %s\n",
file, blocks, reg, region_name);
}
kfree(buf);
}
pos += le32_to_cpu(blk->len) + sizeof(*blk);
blocks++;
}
if (pos > firmware->size)
adsp_warn(dsp, "%s.%d: %zu bytes at end of file\n",
file, blocks, pos - firmware->size);
out_fw:
release_firmware(firmware);
out:
kfree(file);
return 0;
}
int wm_adsp1_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol,
int event)
{
struct snd_soc_codec *codec = w->codec;
struct wm_adsp *dsps = snd_soc_codec_get_drvdata(codec);
struct wm_adsp *dsp = &dsps[w->shift];
int ret;
switch (event) {
case SND_SOC_DAPM_POST_PMU:
regmap_update_bits(dsp->regmap, dsp->base + ADSP1_CONTROL_30,
ADSP1_SYS_ENA, ADSP1_SYS_ENA);
ret = wm_adsp_load(dsp);
if (ret != 0)
goto err;
ret = wm_adsp_load_coeff(dsp);
if (ret != 0)
goto err;
regmap_update_bits(dsp->regmap, dsp->base + ADSP1_CONTROL_30,
ADSP1_CORE_ENA | ADSP1_START,
ADSP1_CORE_ENA | ADSP1_START);
break;
case SND_SOC_DAPM_PRE_PMD:
regmap_update_bits(dsp->regmap, dsp->base + ADSP1_CONTROL_30,
ADSP1_CORE_ENA | ADSP1_START, 0);
regmap_update_bits(dsp->regmap, dsp->base + ADSP1_CONTROL_19,
ADSP1_WDMA_BUFFER_LENGTH_MASK, 0);
regmap_update_bits(dsp->regmap, dsp->base + ADSP1_CONTROL_30,
ADSP1_SYS_ENA, 0);
break;
default:
break;
}
return 0;
err:
regmap_update_bits(dsp->regmap, dsp->base + ADSP1_CONTROL_30,
ADSP1_SYS_ENA, 0);
return ret;
}
static int wm_adsp2_ena(struct wm_adsp *dsp)
{
unsigned int val;
int ret, count;
ret = regmap_update_bits(dsp->regmap, dsp->base + ADSP2_CONTROL,
ADSP2_SYS_ENA, ADSP2_SYS_ENA);
if (ret != 0)
return ret;
count = 0;
do {
ret = regmap_read(dsp->regmap, dsp->base + ADSP2_STATUS1,
&val);
if (ret != 0)
return ret;
} while (!(val & ADSP2_RAM_RDY) && ++count < 10);
if (!(val & ADSP2_RAM_RDY)) {
adsp_err(dsp, "Failed to start DSP RAM\n");
return -EBUSY;
}
adsp_dbg(dsp, "RAM ready after %d polls\n", count);
adsp_info(dsp, "RAM ready after %d polls\n", count);
return 0;
}
int wm_adsp2_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct wm_adsp *dsps = snd_soc_codec_get_drvdata(codec);
struct wm_adsp *dsp = &dsps[w->shift];
unsigned int val;
int ret;
switch (event) {
case SND_SOC_DAPM_POST_PMU:
ret = regmap_read(dsp->regmap, ARIZONA_SYSTEM_CLOCK_1, &val);
if (ret != 0) {
adsp_err(dsp, "Failed to read SYSCLK state: %d\n",
ret);
return ret;
}
val = (val & ARIZONA_SYSCLK_FREQ_MASK)
>> ARIZONA_SYSCLK_FREQ_SHIFT;
ret = regmap_update_bits(dsp->regmap,
dsp->base + ADSP2_CLOCKING,
ADSP2_CLK_SEL_MASK, val);
if (ret != 0) {
adsp_err(dsp, "Failed to set clock rate: %d\n",
ret);
return ret;
}
if (dsp->dvfs) {
ret = regmap_read(dsp->regmap,
dsp->base + ADSP2_CLOCKING, &val);
if (ret != 0) {
dev_err(dsp->dev,
"Failed to read clocking: %d\n", ret);
return ret;
}
if ((val & ADSP2_CLK_SEL_MASK) >= 3) {
ret = regulator_enable(dsp->dvfs);
if (ret != 0) {
dev_err(dsp->dev,
"Failed to enable supply: %d\n",
ret);
return ret;
}
ret = regulator_set_voltage(dsp->dvfs,
1800000,
1800000);
if (ret != 0) {
dev_err(dsp->dev,
"Failed to raise supply: %d\n",
ret);
return ret;
}
}
}
ret = wm_adsp2_ena(dsp);
if (ret != 0)
return ret;
ret = wm_adsp_load(dsp);
if (ret != 0)
goto err;
ret = wm_adsp_load_coeff(dsp);
if (ret != 0)
goto err;
ret = regmap_update_bits(dsp->regmap,
dsp->base + ADSP2_CONTROL,
ADSP2_CORE_ENA | ADSP2_START,
ADSP2_CORE_ENA | ADSP2_START);
if (ret != 0)
goto err;
break;
case SND_SOC_DAPM_PRE_PMD:
regmap_update_bits(dsp->regmap, dsp->base + ADSP2_CONTROL,
ADSP2_SYS_ENA | ADSP2_CORE_ENA |
ADSP2_START, 0);
if (dsp->dvfs) {
ret = regulator_set_voltage(dsp->dvfs, 1200000,
1800000);
if (ret != 0)
dev_warn(dsp->dev,
"Failed to lower supply: %d\n",
ret);
ret = regulator_disable(dsp->dvfs);
if (ret != 0)
dev_err(dsp->dev,
"Failed to enable supply: %d\n",
ret);
}
break;
default:
break;
}
return 0;
err:
regmap_update_bits(dsp->regmap, dsp->base + ADSP2_CONTROL,
ADSP2_SYS_ENA | ADSP2_CORE_ENA | ADSP2_START, 0);
return ret;
}
int wm_adsp2_init(struct wm_adsp *adsp, bool dvfs)
{
int ret;
ret = regmap_update_bits(adsp->regmap, adsp->base + ADSP2_CONTROL,
ADSP2_MEM_ENA, 0);
if (ret != 0) {
adsp_err(adsp, "Failed to clear memory retention: %d\n", ret);
return ret;
}
if (dvfs) {
adsp->dvfs = devm_regulator_get(adsp->dev, "DCVDD");
if (IS_ERR(adsp->dvfs)) {
ret = PTR_ERR(adsp->dvfs);
dev_err(adsp->dev, "Failed to get DCVDD: %d\n", ret);
return ret;
}
ret = regulator_enable(adsp->dvfs);
if (ret != 0) {
dev_err(adsp->dev, "Failed to enable DCVDD: %d\n",
ret);
return ret;
}
ret = regulator_set_voltage(adsp->dvfs, 1200000, 1800000);
if (ret != 0) {
dev_err(adsp->dev, "Failed to initialise DVFS: %d\n",
ret);
return ret;
}
ret = regulator_disable(adsp->dvfs);
if (ret != 0) {
dev_err(adsp->dev, "Failed to disable DCVDD: %d\n",
ret);
return ret;
}
}
return 0;
}
