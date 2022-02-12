int snd_soc_component_read(struct snd_soc_component *component,
unsigned int reg, unsigned int *val)
{
int ret;
if (component->regmap)
ret = regmap_read(component->regmap, reg, val);
else if (component->read)
ret = component->read(component, reg, val);
else
ret = -EIO;
return ret;
}
int snd_soc_component_write(struct snd_soc_component *component,
unsigned int reg, unsigned int val)
{
if (component->regmap)
return regmap_write(component->regmap, reg, val);
else if (component->write)
return component->write(component, reg, val);
else
return -EIO;
}
static int snd_soc_component_update_bits_legacy(
struct snd_soc_component *component, unsigned int reg,
unsigned int mask, unsigned int val, bool *change)
{
unsigned int old, new;
int ret;
if (!component->read || !component->write)
return -EIO;
mutex_lock(&component->io_mutex);
ret = component->read(component, reg, &old);
if (ret < 0)
goto out_unlock;
new = (old & ~mask) | (val & mask);
*change = old != new;
if (*change)
ret = component->write(component, reg, new);
out_unlock:
mutex_unlock(&component->io_mutex);
return ret;
}
int snd_soc_component_update_bits(struct snd_soc_component *component,
unsigned int reg, unsigned int mask, unsigned int val)
{
bool change;
int ret;
if (component->regmap)
ret = regmap_update_bits_check(component->regmap, reg, mask,
val, &change);
else
ret = snd_soc_component_update_bits_legacy(component, reg,
mask, val, &change);
if (ret < 0)
return ret;
return change;
}
int snd_soc_component_update_bits_async(struct snd_soc_component *component,
unsigned int reg, unsigned int mask, unsigned int val)
{
bool change;
int ret;
if (component->regmap)
ret = regmap_update_bits_check_async(component->regmap, reg,
mask, val, &change);
else
ret = snd_soc_component_update_bits_legacy(component, reg,
mask, val, &change);
if (ret < 0)
return ret;
return change;
}
void snd_soc_component_async_complete(struct snd_soc_component *component)
{
if (component->regmap)
regmap_async_complete(component->regmap);
}
int snd_soc_component_test_bits(struct snd_soc_component *component,
unsigned int reg, unsigned int mask, unsigned int value)
{
unsigned int old, new;
int ret;
ret = snd_soc_component_read(component, reg, &old);
if (ret < 0)
return ret;
new = (old & ~mask) | value;
return old != new;
}
unsigned int snd_soc_read(struct snd_soc_codec *codec, unsigned int reg)
{
unsigned int val;
int ret;
ret = snd_soc_component_read(&codec->component, reg, &val);
if (ret < 0)
return -1;
return val;
}
int snd_soc_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int val)
{
return snd_soc_component_write(&codec->component, reg, val);
}
int snd_soc_update_bits(struct snd_soc_codec *codec, unsigned int reg,
unsigned int mask, unsigned int value)
{
return snd_soc_component_update_bits(&codec->component, reg, mask,
value);
}
int snd_soc_test_bits(struct snd_soc_codec *codec, unsigned int reg,
unsigned int mask, unsigned int value)
{
return snd_soc_component_test_bits(&codec->component, reg, mask, value);
}
int snd_soc_platform_read(struct snd_soc_platform *platform,
unsigned int reg)
{
unsigned int val;
int ret;
ret = snd_soc_component_read(&platform->component, reg, &val);
if (ret < 0)
return -1;
return val;
}
int snd_soc_platform_write(struct snd_soc_platform *platform,
unsigned int reg, unsigned int val)
{
return snd_soc_component_write(&platform->component, reg, val);
}
int snd_soc_component_init_io(struct snd_soc_component *component,
struct regmap *regmap)
{
int ret;
if (!regmap)
return -EINVAL;
ret = regmap_get_val_bytes(regmap);
if (ret > 0)
component->val_bytes = ret;
component->regmap = regmap;
return 0;
}
