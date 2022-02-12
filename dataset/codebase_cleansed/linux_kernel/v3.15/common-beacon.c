static u32 ath9k_mod_tsf64_tu(u64 tsf, u32 div_tu)
{
u32 tsf_mod, tsf_hi, tsf_lo, mod_hi, mod_lo;
tsf_mod = tsf & (BIT(10) - 1);
tsf_hi = tsf >> 32;
tsf_lo = ((u32) tsf) >> 10;
mod_hi = tsf_hi % div_tu;
mod_lo = ((mod_hi << 22) + tsf_lo) % div_tu;
return (mod_lo << 10) | tsf_mod;
}
static u32 ath9k_get_next_tbtt(struct ath_hw *ah, u64 tsf,
unsigned int interval)
{
unsigned int offset;
tsf += TU_TO_USEC(FUDGE + ah->config.sw_beacon_response_time);
offset = ath9k_mod_tsf64_tu(tsf, interval);
return (u32) tsf + TU_TO_USEC(interval) - offset;
}
int ath9k_cmn_beacon_config_sta(struct ath_hw *ah,
struct ath_beacon_config *conf,
struct ath9k_beacon_state *bs)
{
struct ath_common *common = ath9k_hw_common(ah);
int dtim_intval;
u64 tsf;
if (!test_bit(ATH_OP_PRIM_STA_VIF, &common->op_flags)) {
ath_dbg(common, BEACON,
"STA is not yet associated..skipping beacon config\n");
return -EPERM;
}
memset(bs, 0, sizeof(*bs));
conf->intval = conf->beacon_interval;
dtim_intval = conf->intval * conf->dtim_period;
tsf = ath9k_hw_gettsf64(ah);
conf->nexttbtt = ath9k_get_next_tbtt(ah, tsf, conf->intval);
bs->bs_intval = TU_TO_USEC(conf->intval);
bs->bs_dtimperiod = conf->dtim_period * bs->bs_intval;
bs->bs_nexttbtt = conf->nexttbtt;
bs->bs_nextdtim = conf->nexttbtt;
if (conf->dtim_period > 1)
bs->bs_nextdtim = ath9k_get_next_tbtt(ah, tsf, dtim_intval);
bs->bs_bmissthreshold = DIV_ROUND_UP(conf->bmiss_timeout, conf->intval);
if (bs->bs_bmissthreshold > 15)
bs->bs_bmissthreshold = 15;
else if (bs->bs_bmissthreshold <= 0)
bs->bs_bmissthreshold = 1;
bs->bs_sleepduration = TU_TO_USEC(roundup(IEEE80211_MS_TO_TU(100),
conf->intval));
if (bs->bs_sleepduration > bs->bs_dtimperiod)
bs->bs_sleepduration = bs->bs_dtimperiod;
bs->bs_tsfoor_threshold = ATH9K_TSFOOR_THRESHOLD;
ath_dbg(common, BEACON, "bmiss: %u sleep: %u\n",
bs->bs_bmissthreshold, bs->bs_sleepduration);
return 0;
}
void ath9k_cmn_beacon_config_adhoc(struct ath_hw *ah,
struct ath_beacon_config *conf)
{
struct ath_common *common = ath9k_hw_common(ah);
conf->intval = TU_TO_USEC(conf->beacon_interval);
if (conf->ibss_creator)
conf->nexttbtt = conf->intval;
else
conf->nexttbtt = ath9k_get_next_tbtt(ah, ath9k_hw_gettsf64(ah),
conf->beacon_interval);
if (conf->enable_beacon)
ah->imask |= ATH9K_INT_SWBA;
else
ah->imask &= ~ATH9K_INT_SWBA;
ath_dbg(common, BEACON,
"IBSS (%s) nexttbtt: %u intval: %u conf_intval: %u\n",
(conf->enable_beacon) ? "Enable" : "Disable",
conf->nexttbtt, conf->intval, conf->beacon_interval);
}
void ath9k_cmn_beacon_config_ap(struct ath_hw *ah,
struct ath_beacon_config *conf,
unsigned int bc_buf)
{
struct ath_common *common = ath9k_hw_common(ah);
conf->intval = TU_TO_USEC(conf->beacon_interval);
conf->intval /= bc_buf;
conf->nexttbtt = ath9k_get_next_tbtt(ah, ath9k_hw_gettsf64(ah),
conf->beacon_interval);
if (conf->enable_beacon)
ah->imask |= ATH9K_INT_SWBA;
else
ah->imask &= ~ATH9K_INT_SWBA;
ath_dbg(common, BEACON,
"AP (%s) nexttbtt: %u intval: %u conf_intval: %u\n",
(conf->enable_beacon) ? "Enable" : "Disable",
conf->nexttbtt, conf->intval, conf->beacon_interval);
}
