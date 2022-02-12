int fbcon_platform_get_rotate(struct fb_info *info)
{
const struct dmi_system_id *match;
const struct fbcon_dmi_rotate_data *data;
const char *bios_date;
int i;
for (match = dmi_first_match(rotate_data);
match;
match = dmi_first_match(match + 1)) {
data = match->driver_data;
if (data->width != info->var.xres ||
data->height != info->var.yres)
continue;
if (!data->bios_dates)
return data->rotate;
bios_date = dmi_get_system_info(DMI_BIOS_DATE);
if (!bios_date)
continue;
for (i = 0; data->bios_dates[i]; i++) {
if (!strcmp(data->bios_dates[i], bios_date))
return data->rotate;
}
}
return FB_ROTATE_UR;
}
