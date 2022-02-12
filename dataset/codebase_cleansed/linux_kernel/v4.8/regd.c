static bool dynamic_country_user_possible(struct ath_regulatory *reg)
{
if (IS_ENABLED(CONFIG_ATH_REG_DYNAMIC_USER_CERT_TESTING))
return true;
switch (reg->country_code) {
case CTRY_UNITED_STATES:
case CTRY_JAPAN1:
case CTRY_JAPAN2:
case CTRY_JAPAN3:
case CTRY_JAPAN4:
case CTRY_JAPAN5:
case CTRY_JAPAN6:
case CTRY_JAPAN7:
case CTRY_JAPAN8:
case CTRY_JAPAN9:
case CTRY_JAPAN10:
case CTRY_JAPAN11:
case CTRY_JAPAN12:
case CTRY_JAPAN13:
case CTRY_JAPAN14:
case CTRY_JAPAN15:
case CTRY_JAPAN16:
case CTRY_JAPAN17:
case CTRY_JAPAN18:
case CTRY_JAPAN19:
case CTRY_JAPAN20:
case CTRY_JAPAN21:
case CTRY_JAPAN22:
case CTRY_JAPAN23:
case CTRY_JAPAN24:
case CTRY_JAPAN25:
case CTRY_JAPAN26:
case CTRY_JAPAN27:
case CTRY_JAPAN28:
case CTRY_JAPAN29:
case CTRY_JAPAN30:
case CTRY_JAPAN31:
case CTRY_JAPAN32:
case CTRY_JAPAN33:
case CTRY_JAPAN34:
case CTRY_JAPAN35:
case CTRY_JAPAN36:
case CTRY_JAPAN37:
case CTRY_JAPAN38:
case CTRY_JAPAN39:
case CTRY_JAPAN40:
case CTRY_JAPAN41:
case CTRY_JAPAN42:
case CTRY_JAPAN43:
case CTRY_JAPAN44:
case CTRY_JAPAN45:
case CTRY_JAPAN46:
case CTRY_JAPAN47:
case CTRY_JAPAN48:
case CTRY_JAPAN49:
case CTRY_JAPAN50:
case CTRY_JAPAN51:
case CTRY_JAPAN52:
case CTRY_JAPAN53:
case CTRY_JAPAN54:
case CTRY_JAPAN55:
case CTRY_JAPAN56:
case CTRY_JAPAN57:
case CTRY_JAPAN58:
case CTRY_JAPAN59:
return false;
}
return true;
}
static bool ath_reg_dyn_country_user_allow(struct ath_regulatory *reg)
{
if (!IS_ENABLED(CONFIG_ATH_REG_DYNAMIC_USER_REG_HINTS))
return false;
if (!dynamic_country_user_possible(reg))
return false;
return true;
}
static inline bool is_wwr_sku(u16 regd)
{
return ((regd & COUNTRY_ERD_FLAG) != COUNTRY_ERD_FLAG) &&
(((regd & WORLD_SKU_MASK) == WORLD_SKU_PREFIX) ||
(regd == WORLD));
}
static u16 ath_regd_get_eepromRD(struct ath_regulatory *reg)
{
return reg->current_rd & ~WORLDWIDE_ROAMING_FLAG;
}
bool ath_is_world_regd(struct ath_regulatory *reg)
{
return is_wwr_sku(ath_regd_get_eepromRD(reg));
}
static const struct ieee80211_regdomain *ath_default_world_regdomain(void)
{
return &ath_world_regdom_64;
}
static const struct
ieee80211_regdomain *ath_world_regdomain(struct ath_regulatory *reg)
{
switch (reg->regpair->reg_domain) {
case 0x60:
case 0x61:
case 0x62:
return &ath_world_regdom_60_61_62;
case 0x63:
case 0x65:
return &ath_world_regdom_63_65;
case 0x64:
return &ath_world_regdom_64;
case 0x66:
case 0x69:
return &ath_world_regdom_66_69;
case 0x67:
case 0x68:
case 0x6A:
case 0x6C:
return &ath_world_regdom_67_68_6A_6C;
default:
WARN_ON(1);
return ath_default_world_regdomain();
}
}
bool ath_is_49ghz_allowed(u16 regdomain)
{
return regdomain == MKK9_MKKC;
}
static bool ath_is_radar_freq(u16 center_freq)
{
return (center_freq >= 5260 && center_freq <= 5700);
}
static void ath_force_clear_no_ir_chan(struct wiphy *wiphy,
struct ieee80211_channel *ch)
{
const struct ieee80211_reg_rule *reg_rule;
reg_rule = freq_reg_info(wiphy, MHZ_TO_KHZ(ch->center_freq));
if (IS_ERR(reg_rule))
return;
if (!(reg_rule->flags & NL80211_RRF_NO_IR))
if (ch->flags & IEEE80211_CHAN_NO_IR)
ch->flags &= ~IEEE80211_CHAN_NO_IR;
}
static void ath_force_clear_no_ir_freq(struct wiphy *wiphy, u16 center_freq)
{
struct ieee80211_channel *ch;
ch = ieee80211_get_channel(wiphy, center_freq);
if (!ch)
return;
ath_force_clear_no_ir_chan(wiphy, ch);
}
static void ath_force_no_ir_chan(struct ieee80211_channel *ch)
{
ch->flags |= IEEE80211_CHAN_NO_IR;
}
static void ath_force_no_ir_freq(struct wiphy *wiphy, u16 center_freq)
{
struct ieee80211_channel *ch;
ch = ieee80211_get_channel(wiphy, center_freq);
if (!ch)
return;
ath_force_no_ir_chan(ch);
}
static void
__ath_reg_apply_beaconing_flags(struct wiphy *wiphy,
struct ath_regulatory *reg,
enum nl80211_reg_initiator initiator,
struct ieee80211_channel *ch)
{
if (ath_is_radar_freq(ch->center_freq) ||
(ch->flags & IEEE80211_CHAN_RADAR))
return;
switch (initiator) {
case NL80211_REGDOM_SET_BY_COUNTRY_IE:
ath_force_clear_no_ir_chan(wiphy, ch);
break;
case NL80211_REGDOM_SET_BY_USER:
if (ath_reg_dyn_country_user_allow(reg))
ath_force_clear_no_ir_chan(wiphy, ch);
break;
default:
if (ch->beacon_found)
ch->flags &= ~IEEE80211_CHAN_NO_IR;
}
}
static void
ath_reg_apply_beaconing_flags(struct wiphy *wiphy,
struct ath_regulatory *reg,
enum nl80211_reg_initiator initiator)
{
enum nl80211_band band;
struct ieee80211_supported_band *sband;
struct ieee80211_channel *ch;
unsigned int i;
for (band = 0; band < NUM_NL80211_BANDS; band++) {
if (!wiphy->bands[band])
continue;
sband = wiphy->bands[band];
for (i = 0; i < sband->n_channels; i++) {
ch = &sband->channels[i];
__ath_reg_apply_beaconing_flags(wiphy, reg,
initiator, ch);
}
}
}
static void
ath_reg_apply_ir_flags(struct wiphy *wiphy,
struct ath_regulatory *reg,
enum nl80211_reg_initiator initiator)
{
struct ieee80211_supported_band *sband;
sband = wiphy->bands[NL80211_BAND_2GHZ];
if (!sband)
return;
switch(initiator) {
case NL80211_REGDOM_SET_BY_COUNTRY_IE:
ath_force_clear_no_ir_freq(wiphy, 2467);
ath_force_clear_no_ir_freq(wiphy, 2472);
break;
case NL80211_REGDOM_SET_BY_USER:
if (!ath_reg_dyn_country_user_allow(reg))
break;
ath_force_clear_no_ir_freq(wiphy, 2467);
ath_force_clear_no_ir_freq(wiphy, 2472);
break;
default:
ath_force_no_ir_freq(wiphy, 2467);
ath_force_no_ir_freq(wiphy, 2472);
}
}
static void ath_reg_apply_radar_flags(struct wiphy *wiphy)
{
struct ieee80211_supported_band *sband;
struct ieee80211_channel *ch;
unsigned int i;
if (!wiphy->bands[NL80211_BAND_5GHZ])
return;
sband = wiphy->bands[NL80211_BAND_5GHZ];
for (i = 0; i < sband->n_channels; i++) {
ch = &sband->channels[i];
if (!ath_is_radar_freq(ch->center_freq))
continue;
if (!(ch->flags & IEEE80211_CHAN_DISABLED))
ch->flags |= IEEE80211_CHAN_RADAR |
IEEE80211_CHAN_NO_IR;
}
}
static void ath_reg_apply_world_flags(struct wiphy *wiphy,
enum nl80211_reg_initiator initiator,
struct ath_regulatory *reg)
{
switch (reg->regpair->reg_domain) {
case 0x60:
case 0x63:
case 0x66:
case 0x67:
case 0x6C:
ath_reg_apply_beaconing_flags(wiphy, reg, initiator);
break;
case 0x68:
ath_reg_apply_beaconing_flags(wiphy, reg, initiator);
ath_reg_apply_ir_flags(wiphy, reg, initiator);
break;
default:
if (ath_reg_dyn_country_user_allow(reg))
ath_reg_apply_beaconing_flags(wiphy, reg, initiator);
}
}
static u16 ath_regd_find_country_by_name(char *alpha2)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(allCountries); i++) {
if (!memcmp(allCountries[i].isoName, alpha2, 2))
return allCountries[i].countryCode;
}
return -1;
}
static int __ath_reg_dyn_country(struct wiphy *wiphy,
struct ath_regulatory *reg,
struct regulatory_request *request)
{
u16 country_code;
if (request->initiator == NL80211_REGDOM_SET_BY_COUNTRY_IE &&
!ath_is_world_regd(reg))
return -EINVAL;
country_code = ath_regd_find_country_by_name(request->alpha2);
if (country_code == (u16) -1)
return -EINVAL;
reg->current_rd = COUNTRY_ERD_FLAG;
reg->current_rd |= country_code;
__ath_regd_init(reg);
ath_reg_apply_world_flags(wiphy, request->initiator, reg);
return 0;
}
static void ath_reg_dyn_country(struct wiphy *wiphy,
struct ath_regulatory *reg,
struct regulatory_request *request)
{
if (__ath_reg_dyn_country(wiphy, reg, request))
return;
printk(KERN_DEBUG "ath: regdomain 0x%0x "
"dynamically updated by %s\n",
reg->current_rd,
reg_initiator_name(request->initiator));
}
void ath_reg_notifier_apply(struct wiphy *wiphy,
struct regulatory_request *request,
struct ath_regulatory *reg)
{
struct ath_common *common = container_of(reg, struct ath_common,
regulatory);
ath_reg_apply_radar_flags(wiphy);
if (!request)
return;
reg->region = request->dfs_region;
switch (request->initiator) {
case NL80211_REGDOM_SET_BY_CORE:
if (!ath_is_world_regd(&common->reg_world_copy))
break;
memcpy(reg, &common->reg_world_copy,
sizeof(struct ath_regulatory));
break;
case NL80211_REGDOM_SET_BY_DRIVER:
break;
case NL80211_REGDOM_SET_BY_USER:
if (ath_reg_dyn_country_user_allow(reg))
ath_reg_dyn_country(wiphy, reg, request);
break;
case NL80211_REGDOM_SET_BY_COUNTRY_IE:
ath_reg_dyn_country(wiphy, reg, request);
break;
}
}
static bool ath_regd_is_eeprom_valid(struct ath_regulatory *reg)
{
u16 rd = ath_regd_get_eepromRD(reg);
int i;
if (rd & COUNTRY_ERD_FLAG) {
u16 cc = rd & ~COUNTRY_ERD_FLAG;
printk(KERN_DEBUG
"ath: EEPROM indicates we should expect "
"a country code\n");
for (i = 0; i < ARRAY_SIZE(allCountries); i++)
if (allCountries[i].countryCode == cc)
return true;
} else {
if (rd != CTRY_DEFAULT)
printk(KERN_DEBUG "ath: EEPROM indicates we "
"should expect a direct regpair map\n");
for (i = 0; i < ARRAY_SIZE(regDomainPairs); i++)
if (regDomainPairs[i].reg_domain == rd)
return true;
}
printk(KERN_DEBUG
"ath: invalid regulatory domain/country code 0x%x\n", rd);
return false;
}
static struct country_code_to_enum_rd*
ath_regd_find_country(u16 countryCode)
{
int i;
for (i = 0; i < ARRAY_SIZE(allCountries); i++) {
if (allCountries[i].countryCode == countryCode)
return &allCountries[i];
}
return NULL;
}
static struct country_code_to_enum_rd*
ath_regd_find_country_by_rd(int regdmn)
{
int i;
for (i = 0; i < ARRAY_SIZE(allCountries); i++) {
if (allCountries[i].regDmnEnum == regdmn)
return &allCountries[i];
}
return NULL;
}
static u16 ath_regd_get_default_country(u16 rd)
{
if (rd & COUNTRY_ERD_FLAG) {
struct country_code_to_enum_rd *country = NULL;
u16 cc = rd & ~COUNTRY_ERD_FLAG;
country = ath_regd_find_country(cc);
if (country != NULL)
return cc;
}
return CTRY_DEFAULT;
}
static struct reg_dmn_pair_mapping*
ath_get_regpair(int regdmn)
{
int i;
if (regdmn == NO_ENUMRD)
return NULL;
for (i = 0; i < ARRAY_SIZE(regDomainPairs); i++) {
if (regDomainPairs[i].reg_domain == regdmn)
return &regDomainPairs[i];
}
return NULL;
}
static int
ath_regd_init_wiphy(struct ath_regulatory *reg,
struct wiphy *wiphy,
void (*reg_notifier)(struct wiphy *wiphy,
struct regulatory_request *request))
{
const struct ieee80211_regdomain *regd;
wiphy->reg_notifier = reg_notifier;
wiphy->regulatory_flags |= REGULATORY_STRICT_REG |
REGULATORY_CUSTOM_REG;
if (ath_is_world_regd(reg)) {
regd = ath_world_regdomain(reg);
wiphy->regulatory_flags |= REGULATORY_COUNTRY_IE_FOLLOW_POWER;
} else {
regd = ath_default_world_regdomain();
}
wiphy_apply_custom_regulatory(wiphy, regd);
ath_reg_apply_radar_flags(wiphy);
ath_reg_apply_world_flags(wiphy, NL80211_REGDOM_SET_BY_DRIVER, reg);
return 0;
}
static void ath_regd_sanitize(struct ath_regulatory *reg)
{
if (reg->current_rd != COUNTRY_ERD_FLAG)
return;
printk(KERN_DEBUG "ath: EEPROM regdomain sanitized\n");
reg->current_rd = 0x64;
}
static int __ath_regd_init(struct ath_regulatory *reg)
{
struct country_code_to_enum_rd *country = NULL;
u16 regdmn;
if (!reg)
return -EINVAL;
ath_regd_sanitize(reg);
printk(KERN_DEBUG "ath: EEPROM regdomain: 0x%0x\n", reg->current_rd);
if (!ath_regd_is_eeprom_valid(reg)) {
pr_err("Invalid EEPROM contents\n");
return -EINVAL;
}
regdmn = ath_regd_get_eepromRD(reg);
reg->country_code = ath_regd_get_default_country(regdmn);
if (reg->country_code == CTRY_DEFAULT &&
regdmn == CTRY_DEFAULT) {
printk(KERN_DEBUG "ath: EEPROM indicates default "
"country code should be used\n");
reg->country_code = CTRY_UNITED_STATES;
}
if (reg->country_code == CTRY_DEFAULT) {
country = NULL;
} else {
printk(KERN_DEBUG "ath: doing EEPROM country->regdmn "
"map search\n");
country = ath_regd_find_country(reg->country_code);
if (country == NULL) {
printk(KERN_DEBUG
"ath: no valid country maps found for "
"country code: 0x%0x\n",
reg->country_code);
return -EINVAL;
} else {
regdmn = country->regDmnEnum;
printk(KERN_DEBUG "ath: country maps to "
"regdmn code: 0x%0x\n",
regdmn);
}
}
reg->regpair = ath_get_regpair(regdmn);
if (!reg->regpair) {
printk(KERN_DEBUG "ath: "
"No regulatory domain pair found, cannot continue\n");
return -EINVAL;
}
if (!country)
country = ath_regd_find_country_by_rd(regdmn);
if (country) {
reg->alpha2[0] = country->isoName[0];
reg->alpha2[1] = country->isoName[1];
} else {
reg->alpha2[0] = '0';
reg->alpha2[1] = '0';
}
printk(KERN_DEBUG "ath: Country alpha2 being used: %c%c\n",
reg->alpha2[0], reg->alpha2[1]);
printk(KERN_DEBUG "ath: Regpair used: 0x%0x\n",
reg->regpair->reg_domain);
return 0;
}
int
ath_regd_init(struct ath_regulatory *reg,
struct wiphy *wiphy,
void (*reg_notifier)(struct wiphy *wiphy,
struct regulatory_request *request))
{
struct ath_common *common = container_of(reg, struct ath_common,
regulatory);
int r;
r = __ath_regd_init(reg);
if (r)
return r;
if (ath_is_world_regd(reg))
memcpy(&common->reg_world_copy, reg,
sizeof(struct ath_regulatory));
ath_regd_init_wiphy(reg, wiphy, reg_notifier);
return 0;
}
u32 ath_regd_get_band_ctl(struct ath_regulatory *reg,
enum nl80211_band band)
{
if (!reg->regpair ||
(reg->country_code == CTRY_DEFAULT &&
is_wwr_sku(ath_regd_get_eepromRD(reg)))) {
return SD_NO_CTL;
}
if (ath_regd_get_eepromRD(reg) == CTRY_DEFAULT) {
switch (reg->region) {
case NL80211_DFS_FCC:
return CTL_FCC;
case NL80211_DFS_ETSI:
return CTL_ETSI;
case NL80211_DFS_JP:
return CTL_MKK;
default:
break;
}
}
switch (band) {
case NL80211_BAND_2GHZ:
return reg->regpair->reg_2ghz_ctl;
case NL80211_BAND_5GHZ:
return reg->regpair->reg_5ghz_ctl;
default:
return NO_CTL;
}
}
