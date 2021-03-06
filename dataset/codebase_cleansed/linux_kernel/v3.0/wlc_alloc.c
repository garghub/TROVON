static void wlc_tunables_init(wlc_tunables_t *tunables, uint devid)
{
tunables->ntxd = NTXD;
tunables->nrxd = NRXD;
tunables->rxbufsz = RXBUFSZ;
tunables->nrxbufpost = NRXBUFPOST;
tunables->maxscb = MAXSCB;
tunables->ampdunummpdu = AMPDU_NUM_MPDU;
tunables->maxpktcb = MAXPKTCB;
tunables->maxucodebss = WLC_MAX_UCODE_BSS;
tunables->maxucodebss4 = WLC_MAX_UCODE_BSS4;
tunables->maxbss = MAXBSS;
tunables->datahiwat = WLC_DATAHIWAT;
tunables->ampdudatahiwat = WLC_AMPDUDATAHIWAT;
tunables->rxbnd = RXBND;
tunables->txsbnd = TXSBND;
}
static struct wlc_pub *wlc_pub_malloc(uint unit, uint *err, uint devid)
{
struct wlc_pub *pub;
pub = kzalloc(sizeof(struct wlc_pub), GFP_ATOMIC);
if (pub == NULL) {
*err = 1001;
goto fail;
}
pub->tunables = kzalloc(sizeof(wlc_tunables_t), GFP_ATOMIC);
if (pub->tunables == NULL) {
*err = 1028;
goto fail;
}
wlc_tunables_init(pub->tunables, devid);
pub->multicast = kzalloc(ETH_ALEN * MAXMULTILIST, GFP_ATOMIC);
if (pub->multicast == NULL) {
*err = 1003;
goto fail;
}
return pub;
fail:
wlc_pub_mfree(pub);
return NULL;
}
static void wlc_pub_mfree(struct wlc_pub *pub)
{
if (pub == NULL)
return;
kfree(pub->multicast);
kfree(pub->tunables);
kfree(pub);
}
static struct wlc_bsscfg *wlc_bsscfg_malloc(uint unit)
{
struct wlc_bsscfg *cfg;
cfg = kzalloc(sizeof(struct wlc_bsscfg), GFP_ATOMIC);
if (cfg == NULL)
goto fail;
cfg->current_bss = kzalloc(sizeof(wlc_bss_info_t), GFP_ATOMIC);
if (cfg->current_bss == NULL)
goto fail;
return cfg;
fail:
wlc_bsscfg_mfree(cfg);
return NULL;
}
static void wlc_bsscfg_mfree(struct wlc_bsscfg *cfg)
{
if (cfg == NULL)
return;
kfree(cfg->maclist);
kfree(cfg->current_bss);
kfree(cfg);
}
static void wlc_bsscfg_ID_assign(struct wlc_info *wlc,
struct wlc_bsscfg *bsscfg)
{
bsscfg->ID = wlc->next_bsscfg_ID;
wlc->next_bsscfg_ID++;
}
struct wlc_info *wlc_attach_malloc(uint unit, uint *err, uint devid)
{
struct wlc_info *wlc;
wlc = kzalloc(sizeof(struct wlc_info), GFP_ATOMIC);
if (wlc == NULL) {
*err = 1002;
goto fail;
}
wlc->hwrxoff = WL_HWRXOFF;
wlc->pub = wlc_pub_malloc(unit, err, devid);
if (wlc->pub == NULL) {
*err = 1003;
goto fail;
}
wlc->pub->wlc = wlc;
wlc->hw = kzalloc(sizeof(struct wlc_hw_info), GFP_ATOMIC);
if (wlc->hw == NULL) {
*err = 1005;
goto fail;
}
wlc->hw->wlc = wlc;
wlc->hw->bandstate[0] =
kzalloc(sizeof(struct wlc_hwband) * MAXBANDS, GFP_ATOMIC);
if (wlc->hw->bandstate[0] == NULL) {
*err = 1006;
goto fail;
} else {
int i;
for (i = 1; i < MAXBANDS; i++) {
wlc->hw->bandstate[i] = (struct wlc_hwband *)
((unsigned long)wlc->hw->bandstate[0] +
(sizeof(struct wlc_hwband) * i));
}
}
wlc->modulecb =
kzalloc(sizeof(struct modulecb) * WLC_MAXMODULES, GFP_ATOMIC);
if (wlc->modulecb == NULL) {
*err = 1009;
goto fail;
}
wlc->default_bss = kzalloc(sizeof(wlc_bss_info_t), GFP_ATOMIC);
if (wlc->default_bss == NULL) {
*err = 1010;
goto fail;
}
wlc->cfg = wlc_bsscfg_malloc(unit);
if (wlc->cfg == NULL) {
*err = 1011;
goto fail;
}
wlc_bsscfg_ID_assign(wlc, wlc->cfg);
wlc->pkt_callback = kzalloc(sizeof(struct pkt_cb) *
(wlc->pub->tunables->maxpktcb + 1),
GFP_ATOMIC);
if (wlc->pkt_callback == NULL) {
*err = 1013;
goto fail;
}
wlc->wsec_def_keys[0] =
kzalloc(sizeof(wsec_key_t) * WLC_DEFAULT_KEYS, GFP_ATOMIC);
if (wlc->wsec_def_keys[0] == NULL) {
*err = 1015;
goto fail;
} else {
int i;
for (i = 1; i < WLC_DEFAULT_KEYS; i++) {
wlc->wsec_def_keys[i] = (wsec_key_t *)
((unsigned long)wlc->wsec_def_keys[0] +
(sizeof(wsec_key_t) * i));
}
}
wlc->protection = kzalloc(sizeof(struct wlc_protection), GFP_ATOMIC);
if (wlc->protection == NULL) {
*err = 1016;
goto fail;
}
wlc->stf = kzalloc(sizeof(struct wlc_stf), GFP_ATOMIC);
if (wlc->stf == NULL) {
*err = 1017;
goto fail;
}
wlc->bandstate[0] =
kzalloc(sizeof(struct wlcband)*MAXBANDS, GFP_ATOMIC);
if (wlc->bandstate[0] == NULL) {
*err = 1025;
goto fail;
} else {
int i;
for (i = 1; i < MAXBANDS; i++) {
wlc->bandstate[i] =
(struct wlcband *) ((unsigned long)wlc->bandstate[0]
+ (sizeof(struct wlcband)*i));
}
}
wlc->corestate = kzalloc(sizeof(struct wlccore), GFP_ATOMIC);
if (wlc->corestate == NULL) {
*err = 1026;
goto fail;
}
wlc->corestate->macstat_snapshot =
kzalloc(sizeof(macstat_t), GFP_ATOMIC);
if (wlc->corestate->macstat_snapshot == NULL) {
*err = 1027;
goto fail;
}
return wlc;
fail:
wlc_detach_mfree(wlc);
return NULL;
}
void wlc_detach_mfree(struct wlc_info *wlc)
{
if (wlc == NULL)
return;
wlc_bsscfg_mfree(wlc->cfg);
wlc_pub_mfree(wlc->pub);
kfree(wlc->modulecb);
kfree(wlc->default_bss);
kfree(wlc->pkt_callback);
kfree(wlc->wsec_def_keys[0]);
kfree(wlc->protection);
kfree(wlc->stf);
kfree(wlc->bandstate[0]);
kfree(wlc->corestate->macstat_snapshot);
kfree(wlc->corestate);
kfree(wlc->hw->bandstate[0]);
kfree(wlc->hw);
kfree(wlc);
wlc = NULL;
}
