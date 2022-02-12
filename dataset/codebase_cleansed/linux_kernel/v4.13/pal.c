static void wusbhc_channel_changed(struct uwb_pal *pal, int channel)
{
struct wusbhc *wusbhc = container_of(pal, struct wusbhc, pal);
dev_dbg(wusbhc->dev, "%s: channel = %d\n", __func__, channel);
if (channel < 0)
wusbhc_stop(wusbhc);
else
wusbhc_start(wusbhc);
}
int wusbhc_pal_register(struct wusbhc *wusbhc)
{
uwb_pal_init(&wusbhc->pal);
wusbhc->pal.name = "wusbhc";
wusbhc->pal.device = wusbhc->usb_hcd.self.controller;
wusbhc->pal.rc = wusbhc->uwb_rc;
wusbhc->pal.channel_changed = wusbhc_channel_changed;
return uwb_pal_register(&wusbhc->pal);
}
void wusbhc_pal_unregister(struct wusbhc *wusbhc)
{
if (wusbhc->uwb_rc)
uwb_pal_unregister(&wusbhc->pal);
}
