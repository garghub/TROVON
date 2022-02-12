void hda_display_power(bool enable)
{
if (!get_power || !put_power)
return;
pr_debug("HDA display power %s \n",
enable ? "Enable" : "Disable");
if (enable)
get_power();
else
put_power();
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
return 0;
}
