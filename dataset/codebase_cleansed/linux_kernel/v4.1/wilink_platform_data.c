int __init wl1251_set_platform_data(const struct wl1251_platform_data *data)
{
if (wl1251_platform_data)
return -EBUSY;
if (!data)
return -EINVAL;
wl1251_platform_data = kmemdup(data, sizeof(*data), GFP_KERNEL);
if (!wl1251_platform_data)
return -ENOMEM;
return 0;
}
struct wl1251_platform_data *wl1251_get_platform_data(void)
{
if (!wl1251_platform_data)
return ERR_PTR(-ENODEV);
return wl1251_platform_data;
}
