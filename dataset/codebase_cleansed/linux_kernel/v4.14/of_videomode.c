int of_get_videomode(struct device_node *np, struct videomode *vm,
int index)
{
struct display_timings *disp;
int ret;
disp = of_get_display_timings(np);
if (!disp) {
pr_err("%pOF: no timings specified\n", np);
return -EINVAL;
}
if (index == OF_USE_NATIVE_MODE)
index = disp->native_mode;
ret = videomode_from_timings(disp, vm, index);
display_timings_release(disp);
return ret;
}
