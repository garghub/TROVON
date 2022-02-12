int wusbhc_mmcie_create(struct wusbhc *wusbhc)
{
u8 mmcies = wusbhc->mmcies_max;
wusbhc->mmcie = kcalloc(mmcies, sizeof(wusbhc->mmcie[0]), GFP_KERNEL);
if (wusbhc->mmcie == NULL)
return -ENOMEM;
mutex_init(&wusbhc->mmcie_mutex);
return 0;
}
void wusbhc_mmcie_destroy(struct wusbhc *wusbhc)
{
kfree(wusbhc->mmcie);
}
int wusbhc_mmcie_set(struct wusbhc *wusbhc, u8 interval, u8 repeat_cnt,
struct wuie_hdr *wuie)
{
int result = -ENOBUFS;
unsigned handle, itr;
mutex_lock(&wusbhc->mmcie_mutex);
switch (wuie->bIEIdentifier) {
case WUIE_ID_HOST_INFO:
handle = wusbhc->mmcies_max - 1;
break;
case WUIE_ID_ISOCH_DISCARD:
dev_err(wusbhc->dev, "Special ordering case for WUIE ID 0x%x "
"unimplemented\n", wuie->bIEIdentifier);
result = -ENOSYS;
goto error_unlock;
default:
handle = ~0;
for (itr = 0; itr < wusbhc->mmcies_max - 1; itr++) {
if (wusbhc->mmcie[itr] == wuie) {
handle = itr;
break;
}
if (wusbhc->mmcie[itr] == NULL)
handle = itr;
}
if (handle == ~0)
goto error_unlock;
}
result = (wusbhc->mmcie_add)(wusbhc, interval, repeat_cnt, handle,
wuie);
if (result >= 0)
wusbhc->mmcie[handle] = wuie;
error_unlock:
mutex_unlock(&wusbhc->mmcie_mutex);
return result;
}
void wusbhc_mmcie_rm(struct wusbhc *wusbhc, struct wuie_hdr *wuie)
{
int result;
unsigned handle, itr;
mutex_lock(&wusbhc->mmcie_mutex);
for (itr = 0; itr < wusbhc->mmcies_max; itr++) {
if (wusbhc->mmcie[itr] == wuie) {
handle = itr;
goto found;
}
}
mutex_unlock(&wusbhc->mmcie_mutex);
return;
found:
result = (wusbhc->mmcie_rm)(wusbhc, handle);
if (result == 0)
wusbhc->mmcie[itr] = NULL;
mutex_unlock(&wusbhc->mmcie_mutex);
}
static int wusbhc_mmc_start(struct wusbhc *wusbhc)
{
int ret;
mutex_lock(&wusbhc->mutex);
ret = wusbhc->start(wusbhc);
if (ret >= 0)
wusbhc->active = 1;
mutex_unlock(&wusbhc->mutex);
return ret;
}
static void wusbhc_mmc_stop(struct wusbhc *wusbhc)
{
mutex_lock(&wusbhc->mutex);
wusbhc->active = 0;
wusbhc->stop(wusbhc, WUSB_CHANNEL_STOP_DELAY_MS);
mutex_unlock(&wusbhc->mutex);
}
int wusbhc_start(struct wusbhc *wusbhc)
{
int result;
struct device *dev = wusbhc->dev;
WARN_ON(wusbhc->wuie_host_info != NULL);
BUG_ON(wusbhc->uwb_rc == NULL);
result = wusbhc_rsv_establish(wusbhc);
if (result < 0) {
dev_err(dev, "cannot establish cluster reservation: %d\n",
result);
goto error_rsv_establish;
}
result = wusbhc_devconnect_start(wusbhc);
if (result < 0) {
dev_err(dev, "error enabling device connections: %d\n",
result);
goto error_devconnect_start;
}
result = wusbhc_sec_start(wusbhc);
if (result < 0) {
dev_err(dev, "error starting security in the HC: %d\n",
result);
goto error_sec_start;
}
result = wusbhc->set_num_dnts(wusbhc, wusbhc->dnts_interval,
wusbhc->dnts_num_slots);
if (result < 0) {
dev_err(dev, "Cannot set DNTS parameters: %d\n", result);
goto error_set_num_dnts;
}
result = wusbhc_mmc_start(wusbhc);
if (result < 0) {
dev_err(dev, "error starting wusbch: %d\n", result);
goto error_wusbhc_start;
}
return 0;
error_wusbhc_start:
wusbhc_sec_stop(wusbhc);
error_set_num_dnts:
error_sec_start:
wusbhc_devconnect_stop(wusbhc);
error_devconnect_start:
wusbhc_rsv_terminate(wusbhc);
error_rsv_establish:
return result;
}
void wusbhc_stop(struct wusbhc *wusbhc)
{
wusbhc_mmc_stop(wusbhc);
wusbhc_sec_stop(wusbhc);
wusbhc_devconnect_stop(wusbhc);
wusbhc_rsv_terminate(wusbhc);
}
int wusbhc_chid_set(struct wusbhc *wusbhc, const struct wusb_ckhdid *chid)
{
int result = 0;
if (memcmp(chid, &wusb_ckhdid_zero, sizeof(*chid)) == 0)
chid = NULL;
mutex_lock(&wusbhc->mutex);
if (chid) {
if (wusbhc->active) {
mutex_unlock(&wusbhc->mutex);
return -EBUSY;
}
wusbhc->chid = *chid;
}
if ((chid) && (wusbhc->uwb_rc == NULL)) {
wusbhc->uwb_rc = uwb_rc_get_by_grandpa(wusbhc->dev->parent);
if (wusbhc->uwb_rc == NULL) {
result = -ENODEV;
dev_err(wusbhc->dev,
"Cannot get associated UWB Host Controller\n");
goto error_rc_get;
}
result = wusbhc_pal_register(wusbhc);
if (result < 0) {
dev_err(wusbhc->dev, "Cannot register as a UWB PAL\n");
goto error_pal_register;
}
}
mutex_unlock(&wusbhc->mutex);
if (chid)
result = uwb_radio_start(&wusbhc->pal);
else if (wusbhc->uwb_rc)
uwb_radio_stop(&wusbhc->pal);
return result;
error_pal_register:
uwb_rc_put(wusbhc->uwb_rc);
wusbhc->uwb_rc = NULL;
error_rc_get:
mutex_unlock(&wusbhc->mutex);
return result;
}
