int hda_display_power(bool enable)
{
if (!get_power || !put_power)
return -ENODEV;
pr_debug("HDA display power %s \n",
enable ? "Enable" : "Disable");
if (enable)
return get_power();
else
return put_power();
}
void haswell_set_bclk(struct azx *chip)
{
int cdclk_freq;
unsigned int bclk_m, bclk_n;
if (!get_cdclk)
return;
cdclk_freq = get_cdclk();
switch (cdclk_freq) {
case 337500:
bclk_m = 16;
bclk_n = 225;
break;
case 450000:
default:
bclk_m = 4;
bclk_n = 75;
break;
case 540000:
bclk_m = 4;
bclk_n = 90;
break;
case 675000:
bclk_m = 8;
bclk_n = 225;
break;
}
azx_writew(chip, EM4, bclk_m);
azx_writew(chip, EM5, bclk_n);
}
int hda_i915_init(void)
{
int err = 0;
get_power = symbol_request(i915_request_power_well);
if (!get_power) {
pr_warn("hda-i915: get_power symbol get fail\n");
return -ENODEV;
}
put_power = symbol_request(i915_release_power_well);
if (!put_power) {
symbol_put(i915_request_power_well);
get_power = NULL;
return -ENODEV;
}
get_cdclk = symbol_request(i915_get_cdclk_freq);
if (!get_cdclk)
pr_warn("hda-i915: get_cdclk symbol get fail\n");
pr_debug("HDA driver get symbol successfully from i915 module\n");
return err;
}
int hda_i915_exit(void)
{
if (get_power) {
symbol_put(i915_request_power_well);
get_power = NULL;
}
if (put_power) {
symbol_put(i915_release_power_well);
put_power = NULL;
}
if (get_cdclk) {
symbol_put(i915_get_cdclk_freq);
get_cdclk = NULL;
}
return 0;
}
