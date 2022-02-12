static void wlc_locale_add_channels(chanvec_t *target,
const chanvec_t *channels)
{
u8 i;
for (i = 0; i < sizeof(chanvec_t); i++) {
target->vec[i] |= channels->vec[i];
}
}
static void wlc_locale_get_channels(const locale_info_t *locale,
chanvec_t *channels)
{
u8 i;
memset(channels, 0, sizeof(chanvec_t));
for (i = 0; i < ARRAY_SIZE(g_table_locale_base); i++) {
if (locale->valid_channels & (1 << i)) {
wlc_locale_add_channels(channels,
g_table_locale_base[i]);
}
}
}
static const locale_info_t *wlc_get_locale_2g(u8 locale_idx)
{
if (locale_idx >= ARRAY_SIZE(g_locale_2g_table)) {
return NULL;
}
return g_locale_2g_table[locale_idx];
}
static const locale_info_t *wlc_get_locale_5g(u8 locale_idx)
{
if (locale_idx >= ARRAY_SIZE(g_locale_5g_table)) {
return NULL;
}
return g_locale_5g_table[locale_idx];
}
static const locale_mimo_info_t *wlc_get_mimo_2g(u8 locale_idx)
{
if (locale_idx >= ARRAY_SIZE(g_mimo_2g_table)) {
return NULL;
}
return g_mimo_2g_table[locale_idx];
}
static const locale_mimo_info_t *wlc_get_mimo_5g(u8 locale_idx)
{
if (locale_idx >= ARRAY_SIZE(g_mimo_5g_table)) {
return NULL;
}
return g_mimo_5g_table[locale_idx];
}
wlc_cm_info_t *wlc_channel_mgr_attach(struct wlc_info *wlc)
{
wlc_cm_info_t *wlc_cm;
char country_abbrev[WLC_CNTRY_BUF_SZ];
const country_info_t *country;
struct wlc_pub *pub = wlc->pub;
char *ccode;
BCMMSG(wlc->wiphy, "wl%d\n", wlc->pub->unit);
wlc_cm = kzalloc(sizeof(wlc_cm_info_t), GFP_ATOMIC);
if (wlc_cm == NULL) {
wiphy_err(wlc->wiphy, "wl%d: %s: out of memory", pub->unit,
__func__);
return NULL;
}
wlc_cm->pub = pub;
wlc_cm->wlc = wlc;
wlc->cmi = wlc_cm;
ccode = getvar(wlc->pub->vars, "ccode");
if (ccode) {
strncpy(wlc->pub->srom_ccode, ccode, WLC_CNTRY_BUF_SZ - 1);
}
memset(country_abbrev, 0, WLC_CNTRY_BUF_SZ);
strncpy(country_abbrev, "X2", sizeof(country_abbrev) - 1);
country = wlc_country_lookup(wlc, country_abbrev);
strncpy(wlc->country_default, country_abbrev, WLC_CNTRY_BUF_SZ - 1);
strncpy(wlc->autocountry_default, "X2", WLC_CNTRY_BUF_SZ - 1);
wlc_set_countrycode(wlc_cm, country_abbrev);
return wlc_cm;
}
void wlc_channel_mgr_detach(wlc_cm_info_t *wlc_cm)
{
kfree(wlc_cm);
}
u8 wlc_channel_locale_flags_in_band(wlc_cm_info_t *wlc_cm, uint bandunit)
{
return wlc_cm->bandstate[bandunit].locale_flags;
}
static int wlc_set_countrycode(wlc_cm_info_t *wlc_cm, const char *ccode)
{
char country_abbrev[WLC_CNTRY_BUF_SZ];
strncpy(country_abbrev, ccode, WLC_CNTRY_BUF_SZ);
return wlc_set_countrycode_rev(wlc_cm, country_abbrev, ccode, -1);
}
static int
wlc_set_countrycode_rev(wlc_cm_info_t *wlc_cm,
const char *country_abbrev,
const char *ccode, int regrev)
{
const country_info_t *country;
char mapped_ccode[WLC_CNTRY_BUF_SZ];
uint mapped_regrev;
if (regrev == -1) {
country =
wlc_countrycode_map(wlc_cm, ccode, mapped_ccode,
&mapped_regrev);
} else {
country = wlc_country_lookup_direct(ccode, regrev);
strncpy(mapped_ccode, ccode, WLC_CNTRY_BUF_SZ);
mapped_regrev = regrev;
}
if (country == NULL)
return -EINVAL;
wlc_set_country_common(wlc_cm, country_abbrev, mapped_ccode,
mapped_regrev, country);
return 0;
}
static void
wlc_set_country_common(wlc_cm_info_t *wlc_cm,
const char *country_abbrev,
const char *ccode, uint regrev,
const country_info_t *country)
{
const locale_mimo_info_t *li_mimo;
const locale_info_t *locale;
struct wlc_info *wlc = wlc_cm->wlc;
char prev_country_abbrev[WLC_CNTRY_BUF_SZ];
wlc_cm->country = country;
memset(&prev_country_abbrev, 0, WLC_CNTRY_BUF_SZ);
strncpy(prev_country_abbrev, wlc_cm->country_abbrev,
WLC_CNTRY_BUF_SZ - 1);
strncpy(wlc_cm->country_abbrev, country_abbrev, WLC_CNTRY_BUF_SZ - 1);
strncpy(wlc_cm->ccode, ccode, WLC_CNTRY_BUF_SZ - 1);
wlc_cm->regrev = regrev;
li_mimo = wlc_get_mimo_2g(country->locale_mimo_2G);
if (li_mimo && (li_mimo->flags & WLC_NO_MIMO)) {
wlc_set_nmode(wlc, OFF);
wlc->stf->no_cddstbc = true;
} else {
wlc->stf->no_cddstbc = false;
if (N_ENAB(wlc->pub) != wlc->protection->nmode_user)
wlc_set_nmode(wlc, wlc->protection->nmode_user);
}
wlc_stf_ss_update(wlc, wlc->bandstate[BAND_2G_INDEX]);
wlc_stf_ss_update(wlc, wlc->bandstate[BAND_5G_INDEX]);
locale = wlc_get_locale_2g(country->locale_2G);
if (locale && (locale->flags & WLC_NO_OFDM)) {
wlc_set_gmode(wlc, GMODE_LEGACY_B, false);
} else {
wlc_set_gmode(wlc, wlc->protection->gmode_user, false);
}
wlc_channels_init(wlc_cm, country);
return;
}
static const country_info_t *wlc_country_lookup(struct wlc_info *wlc,
const char *ccode)
{
const country_info_t *country;
char mapped_ccode[WLC_CNTRY_BUF_SZ];
uint mapped_regrev;
country =
wlc_countrycode_map(wlc->cmi, ccode, mapped_ccode, &mapped_regrev);
return country;
}
static const country_info_t *wlc_countrycode_map(wlc_cm_info_t *wlc_cm,
const char *ccode,
char *mapped_ccode,
uint *mapped_regrev)
{
struct wlc_info *wlc = wlc_cm->wlc;
const country_info_t *country;
uint srom_regrev = wlc_cm->srom_regrev;
const char *srom_ccode = wlc_cm->srom_ccode;
int mapped;
if (strlen(ccode) > (WLC_CNTRY_BUF_SZ - 1)) {
wiphy_err(wlc->wiphy, "wl%d: %s: ccode \"%s\" too long for "
"match\n", wlc->pub->unit, __func__, ccode);
return NULL;
}
strncpy(mapped_ccode, ccode, WLC_CNTRY_BUF_SZ);
*mapped_regrev = 0;
if (!strcmp(srom_ccode, ccode)) {
*mapped_regrev = srom_regrev;
mapped = 0;
wiphy_err(wlc->wiphy, "srom_code == ccode %s\n", __func__);
} else {
mapped =
wlc_country_aggregate_map(wlc_cm, ccode, mapped_ccode,
mapped_regrev);
}
country = wlc_country_lookup_direct(mapped_ccode, *mapped_regrev);
if (country == NULL && *mapped_regrev != 0) {
*mapped_regrev = 0;
country =
wlc_country_lookup_direct(mapped_ccode, *mapped_regrev);
}
return country;
}
static int
wlc_country_aggregate_map(wlc_cm_info_t *wlc_cm, const char *ccode,
char *mapped_ccode, uint *mapped_regrev)
{
return false;
}
static const country_info_t *wlc_country_lookup_direct(const char *ccode,
uint regrev)
{
uint size, i;
if (regrev > 0)
return NULL;
size = ARRAY_SIZE(cntry_locales);
for (i = 0; i < size; i++) {
if (strcmp(ccode, cntry_locales[i].abbrev) == 0) {
return &cntry_locales[i].country;
}
}
return NULL;
}
static int
wlc_channels_init(wlc_cm_info_t *wlc_cm, const country_info_t *country)
{
struct wlc_info *wlc = wlc_cm->wlc;
uint i, j;
struct wlcband *band;
const locale_info_t *li;
chanvec_t sup_chan;
const locale_mimo_info_t *li_mimo;
band = wlc->band;
for (i = 0; i < NBANDS(wlc);
i++, band = wlc->bandstate[OTHERBANDUNIT(wlc)]) {
li = BAND_5G(band->bandtype) ?
wlc_get_locale_5g(country->locale_5G) :
wlc_get_locale_2g(country->locale_2G);
wlc_cm->bandstate[band->bandunit].locale_flags = li->flags;
li_mimo = BAND_5G(band->bandtype) ?
wlc_get_mimo_5g(country->locale_mimo_5G) :
wlc_get_mimo_2g(country->locale_mimo_2G);
wlc_cm->bandstate[band->bandunit].locale_flags |=
li_mimo->flags;
wlc_cm->bandstate[band->bandunit].restricted_channels =
g_table_restricted_chan[li->restricted_channels];
wlc_cm->bandstate[band->bandunit].radar_channels =
g_table_radar_set[li->radar_channels];
wlc_phy_chanspec_band_validch(band->pi, band->bandtype,
&sup_chan);
wlc_locale_get_channels(li,
&wlc_cm->bandstate[band->bandunit].
valid_channels);
for (j = 0; j < sizeof(chanvec_t); j++)
wlc_cm->bandstate[band->bandunit].valid_channels.
vec[j] &= sup_chan.vec[j];
}
wlc_quiet_channels_reset(wlc_cm);
wlc_channels_commit(wlc_cm);
return 0;
}
static void wlc_channels_commit(wlc_cm_info_t *wlc_cm)
{
struct wlc_info *wlc = wlc_cm->wlc;
uint chan;
struct txpwr_limits txpwr;
for (chan = 0; chan < MAXCHANNEL; chan++) {
if (VALID_CHANNEL20_DB(wlc, chan)) {
break;
}
}
if (chan == MAXCHANNEL)
chan = INVCHANNEL;
if (chan == INVCHANNEL) {
mboolset(wlc->pub->radio_disabled, WL_RADIO_COUNTRY_DISABLE);
wiphy_err(wlc->wiphy, "wl%d: %s: no valid channel for \"%s\" "
"nbands %d bandlocked %d\n", wlc->pub->unit,
__func__, wlc_cm->country_abbrev, NBANDS(wlc),
wlc->bandlocked);
} else
if (mboolisset(wlc->pub->radio_disabled,
WL_RADIO_COUNTRY_DISABLE)) {
mboolclr(wlc->pub->radio_disabled, WL_RADIO_COUNTRY_DISABLE);
}
if (NBANDS(wlc) > 1 || BAND_2G(wlc->band->bandtype)) {
wlc_phy_chanspec_ch14_widefilter_set(wlc->band->pi,
wlc_japan(wlc) ? true :
false);
}
if (wlc->pub->up && chan != INVCHANNEL) {
wlc_channel_reg_limits(wlc_cm, wlc->chanspec, &txpwr);
wlc_channel_min_txpower_limits_with_local_constraint(wlc_cm,
&txpwr,
WLC_TXPWR_MAX);
wlc_phy_txpower_limit_set(wlc->band->pi, &txpwr, wlc->chanspec);
}
}
static void wlc_quiet_channels_reset(wlc_cm_info_t *wlc_cm)
{
struct wlc_info *wlc = wlc_cm->wlc;
uint i, j;
struct wlcband *band;
const chanvec_t *chanvec;
memset(&wlc_cm->quiet_channels, 0, sizeof(chanvec_t));
band = wlc->band;
for (i = 0; i < NBANDS(wlc);
i++, band = wlc->bandstate[OTHERBANDUNIT(wlc)]) {
chanvec = wlc_cm->bandstate[band->bandunit].restricted_channels;
for (j = 0; j < sizeof(chanvec_t); j++)
wlc_cm->quiet_channels.vec[j] |= chanvec->vec[j];
}
}
static bool wlc_quiet_chanspec(wlc_cm_info_t *wlc_cm, chanspec_t chspec)
{
return N_ENAB(wlc_cm->wlc->pub) && CHSPEC_IS40(chspec) ?
(isset
(wlc_cm->quiet_channels.vec,
LOWER_20_SB(CHSPEC_CHANNEL(chspec)))
|| isset(wlc_cm->quiet_channels.vec,
UPPER_20_SB(CHSPEC_CHANNEL(chspec)))) : isset(wlc_cm->
quiet_channels.
vec,
CHSPEC_CHANNEL
(chspec));
}
static bool wlc_valid_channel20_db(wlc_cm_info_t *wlc_cm, uint val)
{
struct wlc_info *wlc = wlc_cm->wlc;
return VALID_CHANNEL20(wlc, val) ||
(!wlc->bandlocked
&& VALID_CHANNEL20_IN_BAND(wlc, OTHERBANDUNIT(wlc), val));
}
static bool
wlc_valid_channel20_in_band(wlc_cm_info_t *wlc_cm, uint bandunit, uint val)
{
return ((val < MAXCHANNEL)
&& isset(wlc_cm->bandstate[bandunit].valid_channels.vec, val));
}
static bool wlc_valid_channel20(wlc_cm_info_t *wlc_cm, uint val)
{
struct wlc_info *wlc = wlc_cm->wlc;
return ((val < MAXCHANNEL) &&
isset(wlc_cm->bandstate[wlc->band->bandunit].valid_channels.vec,
val));
}
static void
wlc_channel_min_txpower_limits_with_local_constraint(wlc_cm_info_t *wlc_cm,
struct txpwr_limits *txpwr,
u8
local_constraint_qdbm)
{
int j;
for (j = 0; j < WL_TX_POWER_CCK_NUM; j++) {
txpwr->cck[j] = min(txpwr->cck[j], local_constraint_qdbm);
}
for (j = 0; j < WL_TX_POWER_OFDM_NUM; j++) {
txpwr->ofdm[j] = min(txpwr->ofdm[j], local_constraint_qdbm);
}
for (j = 0; j < WLC_NUM_RATES_OFDM; j++) {
txpwr->ofdm_cdd[j] =
min(txpwr->ofdm_cdd[j], local_constraint_qdbm);
}
for (j = 0; j < WLC_NUM_RATES_OFDM; j++) {
txpwr->ofdm_40_siso[j] =
min(txpwr->ofdm_40_siso[j], local_constraint_qdbm);
}
for (j = 0; j < WLC_NUM_RATES_OFDM; j++) {
txpwr->ofdm_40_cdd[j] =
min(txpwr->ofdm_40_cdd[j], local_constraint_qdbm);
}
for (j = 0; j < WLC_NUM_RATES_MCS_1_STREAM; j++) {
txpwr->mcs_20_siso[j] =
min(txpwr->mcs_20_siso[j], local_constraint_qdbm);
}
for (j = 0; j < WLC_NUM_RATES_MCS_1_STREAM; j++) {
txpwr->mcs_20_cdd[j] =
min(txpwr->mcs_20_cdd[j], local_constraint_qdbm);
}
for (j = 0; j < WLC_NUM_RATES_MCS_1_STREAM; j++) {
txpwr->mcs_20_stbc[j] =
min(txpwr->mcs_20_stbc[j], local_constraint_qdbm);
}
for (j = 0; j < WLC_NUM_RATES_MCS_2_STREAM; j++)
txpwr->mcs_20_mimo[j] =
min(txpwr->mcs_20_mimo[j], local_constraint_qdbm);
for (j = 0; j < WLC_NUM_RATES_MCS_1_STREAM; j++) {
txpwr->mcs_40_siso[j] =
min(txpwr->mcs_40_siso[j], local_constraint_qdbm);
}
for (j = 0; j < WLC_NUM_RATES_MCS_1_STREAM; j++) {
txpwr->mcs_40_cdd[j] =
min(txpwr->mcs_40_cdd[j], local_constraint_qdbm);
}
for (j = 0; j < WLC_NUM_RATES_MCS_1_STREAM; j++) {
txpwr->mcs_40_stbc[j] =
min(txpwr->mcs_40_stbc[j], local_constraint_qdbm);
}
for (j = 0; j < WLC_NUM_RATES_MCS_2_STREAM; j++)
txpwr->mcs_40_mimo[j] =
min(txpwr->mcs_40_mimo[j], local_constraint_qdbm);
txpwr->mcs32 = min(txpwr->mcs32, local_constraint_qdbm);
}
void
wlc_channel_set_chanspec(wlc_cm_info_t *wlc_cm, chanspec_t chanspec,
u8 local_constraint_qdbm)
{
struct wlc_info *wlc = wlc_cm->wlc;
struct txpwr_limits txpwr;
wlc_channel_reg_limits(wlc_cm, chanspec, &txpwr);
wlc_channel_min_txpower_limits_with_local_constraint(wlc_cm, &txpwr,
local_constraint_qdbm);
wlc_bmac_set_chanspec(wlc->hw, chanspec,
(wlc_quiet_chanspec(wlc_cm, chanspec) != 0),
&txpwr);
}
static void wlc_phy_txpower_limits_dump(txpwr_limits_t *txpwr)
{
int i;
char buf[80];
char fraction[4][4] = { " ", ".25", ".5 ", ".75" };
sprintf(buf, "CCK ");
for (i = 0; i < WLC_NUM_RATES_CCK; i++) {
sprintf(buf[strlen(buf)], " %2d%s",
txpwr->cck[i] / WLC_TXPWR_DB_FACTOR,
fraction[txpwr->cck[i] % WLC_TXPWR_DB_FACTOR]);
}
printk(KERN_DEBUG "%s\n", buf);
sprintf(buf, "20 MHz OFDM SISO ");
for (i = 0; i < WLC_NUM_RATES_OFDM; i++) {
sprintf(buf[strlen(buf)], " %2d%s",
txpwr->ofdm[i] / WLC_TXPWR_DB_FACTOR,
fraction[txpwr->ofdm[i] % WLC_TXPWR_DB_FACTOR]);
}
printk(KERN_DEBUG "%s\n", buf);
sprintf(buf, "20 MHz OFDM CDD ");
for (i = 0; i < WLC_NUM_RATES_OFDM; i++) {
sprintf(buf[strlen(buf)], " %2d%s",
txpwr->ofdm_cdd[i] / WLC_TXPWR_DB_FACTOR,
fraction[txpwr->ofdm_cdd[i] % WLC_TXPWR_DB_FACTOR]);
}
printk(KERN_DEBUG "%s\n", buf);
sprintf(buf, "40 MHz OFDM SISO ");
for (i = 0; i < WLC_NUM_RATES_OFDM; i++) {
sprintf(buf[strlen(buf)], " %2d%s",
txpwr->ofdm_40_siso[i] / WLC_TXPWR_DB_FACTOR,
fraction[txpwr->ofdm_40_siso[i] % WLC_TXPWR_DB_FACTOR]);
}
printk(KERN_DEBUG "%s\n", buf);
sprintf(buf, "40 MHz OFDM CDD ");
for (i = 0; i < WLC_NUM_RATES_OFDM; i++) {
sprintf(buf[strlen(buf)], " %2d%s",
txpwr->ofdm_40_cdd[i] / WLC_TXPWR_DB_FACTOR,
fraction[txpwr->ofdm_40_cdd[i] % WLC_TXPWR_DB_FACTOR]);
}
printk(KERN_DEBUG "%s\n", buf);
sprintf(buf, "20 MHz MCS0-7 SISO ");
for (i = 0; i < WLC_NUM_RATES_MCS_1_STREAM; i++) {
sprintf(buf[strlen(buf)], " %2d%s",
txpwr->mcs_20_siso[i] / WLC_TXPWR_DB_FACTOR,
fraction[txpwr->mcs_20_siso[i] % WLC_TXPWR_DB_FACTOR]);
}
printk(KERN_DEBUG "%s\n", buf);
sprintf(buf, "20 MHz MCS0-7 CDD ");
for (i = 0; i < WLC_NUM_RATES_MCS_1_STREAM; i++) {
sprintf(buf[strlen(buf)], " %2d%s",
txpwr->mcs_20_cdd[i] / WLC_TXPWR_DB_FACTOR,
fraction[txpwr->mcs_20_cdd[i] % WLC_TXPWR_DB_FACTOR]);
}
printk(KERN_DEBUG "%s\n", buf);
sprintf(buf, "20 MHz MCS0-7 STBC ");
for (i = 0; i < WLC_NUM_RATES_MCS_1_STREAM; i++) {
sprintf(buf[strlen(buf)], " %2d%s",
txpwr->mcs_20_stbc[i] / WLC_TXPWR_DB_FACTOR,
fraction[txpwr->mcs_20_stbc[i] % WLC_TXPWR_DB_FACTOR]);
}
printk(KERN_DEBUG "%s\n", buf);
sprintf(buf, "20 MHz MCS8-15 SDM ");
for (i = 0; i < WLC_NUM_RATES_MCS_2_STREAM; i++) {
sprintf(buf[strlen(buf)], " %2d%s",
txpwr->mcs_20_mimo[i] / WLC_TXPWR_DB_FACTOR,
fraction[txpwr->mcs_20_mimo[i] % WLC_TXPWR_DB_FACTOR]);
}
printk(KERN_DEBUG "%s\n", buf);
sprintf(buf, "40 MHz MCS0-7 SISO ");
for (i = 0; i < WLC_NUM_RATES_MCS_1_STREAM; i++) {
sprintf(buf[strlen(buf)], " %2d%s",
txpwr->mcs_40_siso[i] / WLC_TXPWR_DB_FACTOR,
fraction[txpwr->mcs_40_siso[i] % WLC_TXPWR_DB_FACTOR]);
}
printk(KERN_DEBUG "%s\n", buf);
sprintf(buf, "40 MHz MCS0-7 CDD ");
for (i = 0; i < WLC_NUM_RATES_MCS_1_STREAM; i++) {
sprintf(buf[strlen(buf)], " %2d%s",
txpwr->mcs_40_cdd[i] / WLC_TXPWR_DB_FACTOR,
fraction[txpwr->mcs_40_cdd[i] % WLC_TXPWR_DB_FACTOR]);
}
printk(KERN_DEBUG "%s\n", buf);
sprintf(buf, "40 MHz MCS0-7 STBC ");
for (i = 0; i < WLC_NUM_RATES_MCS_1_STREAM; i++) {
sprintf(buf[strlen(buf)], " %2d%s",
txpwr->mcs_40_stbc[i] / WLC_TXPWR_DB_FACTOR,
fraction[txpwr->mcs_40_stbc[i] % WLC_TXPWR_DB_FACTOR]);
}
printk(KERN_DEBUG "%s\n", buf);
sprintf(buf, "40 MHz MCS8-15 SDM ");
for (i = 0; i < WLC_NUM_RATES_MCS_2_STREAM; i++) {
sprintf(buf[strlen(buf)], " %2d%s",
txpwr->mcs_40_mimo[i] / WLC_TXPWR_DB_FACTOR,
fraction[txpwr->mcs_40_mimo[i] % WLC_TXPWR_DB_FACTOR]);
}
printk(KERN_DEBUG "%s\n", buf);
printk(KERN_DEBUG "MCS32 %2d%s\n",
txpwr->mcs32 / WLC_TXPWR_DB_FACTOR,
fraction[txpwr->mcs32 % WLC_TXPWR_DB_FACTOR]);
}
void
wlc_channel_reg_limits(wlc_cm_info_t *wlc_cm, chanspec_t chanspec,
txpwr_limits_t *txpwr)
{
struct wlc_info *wlc = wlc_cm->wlc;
uint i;
uint chan;
int maxpwr;
int delta;
const country_info_t *country;
struct wlcband *band;
const locale_info_t *li;
int conducted_max;
int conducted_ofdm_max;
const locale_mimo_info_t *li_mimo;
int maxpwr20, maxpwr40;
int maxpwr_idx;
uint j;
memset(txpwr, 0, sizeof(txpwr_limits_t));
if (!wlc_valid_chanspec_db(wlc_cm, chanspec)) {
country = wlc_country_lookup(wlc, wlc->autocountry_default);
if (country == NULL)
return;
} else {
country = wlc_cm->country;
}
chan = CHSPEC_CHANNEL(chanspec);
band = wlc->bandstate[CHSPEC_WLCBANDUNIT(chanspec)];
li = BAND_5G(band->bandtype) ?
wlc_get_locale_5g(country->locale_5G) :
wlc_get_locale_2g(country->locale_2G);
li_mimo = BAND_5G(band->bandtype) ?
wlc_get_mimo_5g(country->locale_mimo_5G) :
wlc_get_mimo_2g(country->locale_mimo_2G);
if (li->flags & WLC_EIRP) {
delta = band->antgain;
} else {
delta = 0;
if (band->antgain > QDB(6))
delta = band->antgain - QDB(6);
}
if (li == &locale_i) {
conducted_max = QDB(22);
conducted_ofdm_max = QDB(22);
}
if (BAND_2G(band->bandtype)) {
maxpwr = li->maxpwr[CHANNEL_POWER_IDX_2G_CCK(chan)];
maxpwr = maxpwr - delta;
maxpwr = max(maxpwr, 0);
maxpwr = min(maxpwr, conducted_max);
for (i = 0; i < WLC_NUM_RATES_CCK; i++)
txpwr->cck[i] = (u8) maxpwr;
}
if (BAND_2G(band->bandtype)) {
maxpwr = li->maxpwr[CHANNEL_POWER_IDX_2G_OFDM(chan)];
} else {
maxpwr = li->maxpwr[CHANNEL_POWER_IDX_5G(chan)];
}
maxpwr = maxpwr - delta;
maxpwr = max(maxpwr, 0);
maxpwr = min(maxpwr, conducted_ofdm_max);
if (BAND_2G(band->bandtype))
maxpwr = min_t(int, maxpwr, txpwr->cck[0]);
for (i = 0; i < WLC_NUM_RATES_OFDM; i++) {
txpwr->ofdm[i] = (u8) maxpwr;
}
for (i = 0; i < WLC_NUM_RATES_OFDM; i++) {
txpwr->ofdm_40_siso[i] = 0;
txpwr->ofdm_cdd[i] = (u8) maxpwr;
txpwr->ofdm_40_cdd[i] = 0;
}
if (li_mimo->flags & WLC_EIRP) {
delta = band->antgain;
} else {
delta = 0;
if (band->antgain > QDB(6))
delta = band->antgain - QDB(6);
}
if (BAND_2G(band->bandtype))
maxpwr_idx = (chan - 1);
else
maxpwr_idx = CHANNEL_POWER_IDX_5G(chan);
maxpwr20 = li_mimo->maxpwr20[maxpwr_idx];
maxpwr40 = li_mimo->maxpwr40[maxpwr_idx];
maxpwr20 = maxpwr20 - delta;
maxpwr20 = max(maxpwr20, 0);
maxpwr40 = maxpwr40 - delta;
maxpwr40 = max(maxpwr40, 0);
for (i = 0; i < WLC_NUM_RATES_MCS_1_STREAM; i++) {
txpwr->mcs_20_siso[i] = txpwr->ofdm[i];
txpwr->mcs_40_siso[i] = 0;
}
for (i = 0; i < WLC_NUM_RATES_MCS_1_STREAM; i++) {
txpwr->mcs_20_cdd[i] = (u8) maxpwr20;
txpwr->mcs_40_cdd[i] = (u8) maxpwr40;
}
if (li_mimo == &locale_bn) {
if (li_mimo == &locale_bn) {
maxpwr20 = QDB(16);
maxpwr40 = 0;
if (chan >= 3 && chan <= 11) {
maxpwr40 = QDB(16);
}
}
for (i = 0; i < WLC_NUM_RATES_MCS_1_STREAM; i++) {
txpwr->mcs_20_siso[i] = (u8) maxpwr20;
txpwr->mcs_40_siso[i] = (u8) maxpwr40;
}
}
for (i = 0; i < WLC_NUM_RATES_MCS_1_STREAM; i++) {
txpwr->mcs_20_stbc[i] = 0;
txpwr->mcs_40_stbc[i] = 0;
}
for (i = 0; i < WLC_NUM_RATES_MCS_2_STREAM; i++) {
txpwr->mcs_20_mimo[i] = (u8) maxpwr20;
txpwr->mcs_40_mimo[i] = (u8) maxpwr40;
}
txpwr->mcs32 = (u8) maxpwr40;
for (i = 0, j = 0; i < WLC_NUM_RATES_OFDM; i++, j++) {
if (txpwr->ofdm_40_cdd[i] == 0)
txpwr->ofdm_40_cdd[i] = txpwr->mcs_40_cdd[j];
if (i == 0) {
i = i + 1;
if (txpwr->ofdm_40_cdd[i] == 0)
txpwr->ofdm_40_cdd[i] = txpwr->mcs_40_cdd[j];
}
}
for (i = 0; i < WLC_NUM_RATES_MCS_1_STREAM; i++) {
if (txpwr->mcs_40_siso[i] == 0)
txpwr->mcs_40_siso[i] = txpwr->mcs_40_cdd[i];
}
for (i = 0, j = 0; i < WLC_NUM_RATES_OFDM; i++, j++) {
if (txpwr->ofdm_40_siso[i] == 0)
txpwr->ofdm_40_siso[i] = txpwr->mcs_40_siso[j];
if (i == 0) {
i = i + 1;
if (txpwr->ofdm_40_siso[i] == 0)
txpwr->ofdm_40_siso[i] = txpwr->mcs_40_siso[j];
}
}
for (i = 0; i < WLC_NUM_RATES_MCS_1_STREAM; i++) {
if (txpwr->mcs_20_stbc[i] == 0)
txpwr->mcs_20_stbc[i] = txpwr->mcs_20_cdd[i];
if (txpwr->mcs_40_stbc[i] == 0)
txpwr->mcs_40_stbc[i] = txpwr->mcs_40_cdd[i];
}
#ifdef POWER_DBG
wlc_phy_txpower_limits_dump(txpwr);
#endif
return;
}
static bool wlc_japan(struct wlc_info *wlc)
{
return wlc_japan_ccode(wlc->cmi->country_abbrev);
}
static bool wlc_japan_ccode(const char *ccode)
{
return (ccode[0] == 'J' &&
(ccode[1] == 'P' || (ccode[1] >= '1' && ccode[1] <= '9')));
}
static bool
wlc_valid_chanspec_ext(wlc_cm_info_t *wlc_cm, chanspec_t chspec, bool dualband)
{
struct wlc_info *wlc = wlc_cm->wlc;
u8 channel = CHSPEC_CHANNEL(chspec);
if (bcm_chspec_malformed(chspec)) {
wiphy_err(wlc->wiphy, "wl%d: malformed chanspec 0x%x\n",
wlc->pub->unit, chspec);
return false;
}
if (CHANNEL_BANDUNIT(wlc_cm->wlc, channel) !=
CHSPEC_WLCBANDUNIT(chspec))
return false;
if (CHSPEC_IS20(chspec)) {
if (dualband)
return VALID_CHANNEL20_DB(wlc_cm->wlc, channel);
else
return VALID_CHANNEL20(wlc_cm->wlc, channel);
}
#ifdef SUPPORT_40MHZ
if (WLCISNPHY(wlc->band) || WLCISSSLPNPHY(wlc->band)) {
u8 upper_sideband = 0, idx;
u8 num_ch20_entries =
sizeof(chan20_info) / sizeof(struct chan20_info);
if (!VALID_40CHANSPEC_IN_BAND(wlc, CHSPEC_WLCBANDUNIT(chspec)))
return false;
if (dualband) {
if (!VALID_CHANNEL20_DB(wlc, LOWER_20_SB(channel)) ||
!VALID_CHANNEL20_DB(wlc, UPPER_20_SB(channel)))
return false;
} else {
if (!VALID_CHANNEL20(wlc, LOWER_20_SB(channel)) ||
!VALID_CHANNEL20(wlc, UPPER_20_SB(channel)))
return false;
}
for (idx = 0; idx < num_ch20_entries; idx++) {
if (chan20_info[idx].sb == LOWER_20_SB(channel))
upper_sideband = chan20_info[idx].adj_sbs;
}
if ((upper_sideband & (CH_UPPER_SB | CH_EWA_VALID)) ==
(CH_UPPER_SB | CH_EWA_VALID))
return true;
return false;
}
#endif
return false;
}
bool wlc_valid_chanspec_db(wlc_cm_info_t *wlc_cm, chanspec_t chspec)
{
return wlc_valid_chanspec_ext(wlc_cm, chspec, true);
}
