static void ath9k_hw_update_mibstats(struct ath_hw *ah,
struct ath9k_mib_stats *stats)
{
stats->ackrcv_bad += REG_READ(ah, AR_ACK_FAIL);
stats->rts_bad += REG_READ(ah, AR_RTS_FAIL);
stats->fcs_bad += REG_READ(ah, AR_FCS_FAIL);
stats->rts_good += REG_READ(ah, AR_RTS_OK);
stats->beacons += REG_READ(ah, AR_BEACON_CNT);
}
static void ath9k_ani_restart(struct ath_hw *ah)
{
struct ar5416AniState *aniState;
if (!DO_ANI(ah))
return;
aniState = &ah->curchan->ani;
aniState->listenTime = 0;
ENABLE_REGWRITE_BUFFER(ah);
REG_WRITE(ah, AR_PHY_ERR_1, 0);
REG_WRITE(ah, AR_PHY_ERR_2, 0);
REG_WRITE(ah, AR_PHY_ERR_MASK_1, AR_PHY_ERR_OFDM_TIMING);
REG_WRITE(ah, AR_PHY_ERR_MASK_2, AR_PHY_ERR_CCK_TIMING);
REGWRITE_BUFFER_FLUSH(ah);
ath9k_hw_update_mibstats(ah, &ah->ah_mibStats);
aniState->ofdmPhyErrCount = 0;
aniState->cckPhyErrCount = 0;
}
static void ath9k_hw_set_ofdm_nil(struct ath_hw *ah, u8 immunityLevel,
bool scan)
{
struct ar5416AniState *aniState = &ah->curchan->ani;
struct ath_common *common = ath9k_hw_common(ah);
const struct ani_ofdm_level_entry *entry_ofdm;
const struct ani_cck_level_entry *entry_cck;
bool weak_sig;
ath_dbg(common, ANI, "**** ofdmlevel %d=>%d, rssi=%d[lo=%d hi=%d]\n",
aniState->ofdmNoiseImmunityLevel,
immunityLevel, BEACON_RSSI(ah),
aniState->rssiThrLow, aniState->rssiThrHigh);
if (!scan)
aniState->ofdmNoiseImmunityLevel = immunityLevel;
entry_ofdm = &ofdm_level_table[aniState->ofdmNoiseImmunityLevel];
entry_cck = &cck_level_table[aniState->cckNoiseImmunityLevel];
if (aniState->spurImmunityLevel != entry_ofdm->spur_immunity_level)
ath9k_hw_ani_control(ah,
ATH9K_ANI_SPUR_IMMUNITY_LEVEL,
entry_ofdm->spur_immunity_level);
if (aniState->firstepLevel != entry_ofdm->fir_step_level &&
entry_ofdm->fir_step_level >= entry_cck->fir_step_level)
ath9k_hw_ani_control(ah,
ATH9K_ANI_FIRSTEP_LEVEL,
entry_ofdm->fir_step_level);
weak_sig = entry_ofdm->ofdm_weak_signal_on;
if (ah->opmode == NL80211_IFTYPE_STATION &&
BEACON_RSSI(ah) <= aniState->rssiThrHigh)
weak_sig = true;
if (aniState->ofdmWeakSigDetect != weak_sig)
ath9k_hw_ani_control(ah,
ATH9K_ANI_OFDM_WEAK_SIGNAL_DETECTION,
entry_ofdm->ofdm_weak_signal_on);
if (aniState->ofdmNoiseImmunityLevel >= ATH9K_ANI_OFDM_DEF_LEVEL) {
ah->config.ofdm_trig_high = ATH9K_ANI_OFDM_TRIG_HIGH;
ah->config.ofdm_trig_low = ATH9K_ANI_OFDM_TRIG_LOW_ABOVE_INI;
} else {
ah->config.ofdm_trig_high = ATH9K_ANI_OFDM_TRIG_HIGH_BELOW_INI;
ah->config.ofdm_trig_low = ATH9K_ANI_OFDM_TRIG_LOW;
}
}
static void ath9k_hw_ani_ofdm_err_trigger(struct ath_hw *ah)
{
struct ar5416AniState *aniState;
if (!DO_ANI(ah))
return;
aniState = &ah->curchan->ani;
if (aniState->ofdmNoiseImmunityLevel < ATH9K_ANI_OFDM_MAX_LEVEL)
ath9k_hw_set_ofdm_nil(ah, aniState->ofdmNoiseImmunityLevel + 1, false);
}
static void ath9k_hw_set_cck_nil(struct ath_hw *ah, u_int8_t immunityLevel,
bool scan)
{
struct ar5416AniState *aniState = &ah->curchan->ani;
struct ath_common *common = ath9k_hw_common(ah);
const struct ani_ofdm_level_entry *entry_ofdm;
const struct ani_cck_level_entry *entry_cck;
ath_dbg(common, ANI, "**** ccklevel %d=>%d, rssi=%d[lo=%d hi=%d]\n",
aniState->cckNoiseImmunityLevel, immunityLevel,
BEACON_RSSI(ah), aniState->rssiThrLow,
aniState->rssiThrHigh);
if (ah->opmode == NL80211_IFTYPE_STATION &&
BEACON_RSSI(ah) <= aniState->rssiThrLow &&
immunityLevel > ATH9K_ANI_CCK_MAX_LEVEL_LOW_RSSI)
immunityLevel = ATH9K_ANI_CCK_MAX_LEVEL_LOW_RSSI;
if (!scan)
aniState->cckNoiseImmunityLevel = immunityLevel;
entry_ofdm = &ofdm_level_table[aniState->ofdmNoiseImmunityLevel];
entry_cck = &cck_level_table[aniState->cckNoiseImmunityLevel];
if (aniState->firstepLevel != entry_cck->fir_step_level &&
entry_cck->fir_step_level >= entry_ofdm->fir_step_level)
ath9k_hw_ani_control(ah,
ATH9K_ANI_FIRSTEP_LEVEL,
entry_cck->fir_step_level);
if (!AR_SREV_9300_20_OR_LATER(ah) || AR_SREV_9485(ah))
return;
if (aniState->mrcCCK != entry_cck->mrc_cck_on)
ath9k_hw_ani_control(ah,
ATH9K_ANI_MRC_CCK,
entry_cck->mrc_cck_on);
}
static void ath9k_hw_ani_cck_err_trigger(struct ath_hw *ah)
{
struct ar5416AniState *aniState;
if (!DO_ANI(ah))
return;
aniState = &ah->curchan->ani;
if (aniState->cckNoiseImmunityLevel < ATH9K_ANI_CCK_MAX_LEVEL)
ath9k_hw_set_cck_nil(ah, aniState->cckNoiseImmunityLevel + 1,
false);
}
static void ath9k_hw_ani_lower_immunity(struct ath_hw *ah)
{
struct ar5416AniState *aniState;
aniState = &ah->curchan->ani;
if (aniState->ofdmNoiseImmunityLevel > 0 &&
(aniState->ofdmsTurn || aniState->cckNoiseImmunityLevel == 0)) {
ath9k_hw_set_ofdm_nil(ah, aniState->ofdmNoiseImmunityLevel - 1,
false);
return;
}
if (aniState->cckNoiseImmunityLevel > 0)
ath9k_hw_set_cck_nil(ah, aniState->cckNoiseImmunityLevel - 1,
false);
}
void ath9k_ani_reset(struct ath_hw *ah, bool is_scanning)
{
struct ar5416AniState *aniState = &ah->curchan->ani;
struct ath9k_channel *chan = ah->curchan;
struct ath_common *common = ath9k_hw_common(ah);
int ofdm_nil, cck_nil;
if (!DO_ANI(ah))
return;
BUG_ON(aniState == NULL);
ah->stats.ast_ani_reset++;
if (ah->opmode == NL80211_IFTYPE_AP) {
if (IS_CHAN_2GHZ(chan)) {
ah->ani_function = (ATH9K_ANI_SPUR_IMMUNITY_LEVEL |
ATH9K_ANI_FIRSTEP_LEVEL);
if (AR_SREV_9300_20_OR_LATER(ah))
ah->ani_function |= ATH9K_ANI_MRC_CCK;
} else
ah->ani_function = 0;
}
ah->ani_function |= ATH9K_ANI_MODE;
ofdm_nil = max_t(int, ATH9K_ANI_OFDM_DEF_LEVEL,
aniState->ofdmNoiseImmunityLevel);
cck_nil = max_t(int, ATH9K_ANI_CCK_DEF_LEVEL,
aniState->cckNoiseImmunityLevel);
if (is_scanning ||
(ah->opmode != NL80211_IFTYPE_STATION &&
ah->opmode != NL80211_IFTYPE_ADHOC)) {
if (aniState->ofdmNoiseImmunityLevel !=
ATH9K_ANI_OFDM_DEF_LEVEL ||
aniState->cckNoiseImmunityLevel !=
ATH9K_ANI_CCK_DEF_LEVEL) {
ath_dbg(common, ANI,
"Restore defaults: opmode %u chan %d Mhz/0x%x is_scanning=%d ofdm:%d cck:%d\n",
ah->opmode,
chan->channel,
chan->channelFlags,
is_scanning,
aniState->ofdmNoiseImmunityLevel,
aniState->cckNoiseImmunityLevel);
ofdm_nil = ATH9K_ANI_OFDM_DEF_LEVEL;
cck_nil = ATH9K_ANI_CCK_DEF_LEVEL;
}
} else {
ath_dbg(common, ANI,
"Restore history: opmode %u chan %d Mhz/0x%x is_scanning=%d ofdm:%d cck:%d\n",
ah->opmode,
chan->channel,
chan->channelFlags,
is_scanning,
aniState->ofdmNoiseImmunityLevel,
aniState->cckNoiseImmunityLevel);
}
ath9k_hw_set_ofdm_nil(ah, ofdm_nil, is_scanning);
ath9k_hw_set_cck_nil(ah, cck_nil, is_scanning);
ath9k_ani_restart(ah);
ENABLE_REGWRITE_BUFFER(ah);
REG_WRITE(ah, AR_PHY_ERR_MASK_1, AR_PHY_ERR_OFDM_TIMING);
REG_WRITE(ah, AR_PHY_ERR_MASK_2, AR_PHY_ERR_CCK_TIMING);
REGWRITE_BUFFER_FLUSH(ah);
}
static bool ath9k_hw_ani_read_counters(struct ath_hw *ah)
{
struct ath_common *common = ath9k_hw_common(ah);
struct ar5416AniState *aniState = &ah->curchan->ani;
u32 phyCnt1, phyCnt2;
int32_t listenTime;
ath_hw_cycle_counters_update(common);
listenTime = ath_hw_get_listen_time(common);
if (listenTime <= 0) {
ah->stats.ast_ani_lneg_or_lzero++;
ath9k_ani_restart(ah);
return false;
}
aniState->listenTime += listenTime;
ath9k_hw_update_mibstats(ah, &ah->ah_mibStats);
phyCnt1 = REG_READ(ah, AR_PHY_ERR_1);
phyCnt2 = REG_READ(ah, AR_PHY_ERR_2);
ah->stats.ast_ani_ofdmerrs += phyCnt1 - aniState->ofdmPhyErrCount;
aniState->ofdmPhyErrCount = phyCnt1;
ah->stats.ast_ani_cckerrs += phyCnt2 - aniState->cckPhyErrCount;
aniState->cckPhyErrCount = phyCnt2;
return true;
}
void ath9k_hw_ani_monitor(struct ath_hw *ah, struct ath9k_channel *chan)
{
struct ar5416AniState *aniState;
struct ath_common *common = ath9k_hw_common(ah);
u32 ofdmPhyErrRate, cckPhyErrRate;
if (!DO_ANI(ah))
return;
aniState = &ah->curchan->ani;
if (WARN_ON(!aniState))
return;
if (!ath9k_hw_ani_read_counters(ah))
return;
ofdmPhyErrRate = aniState->ofdmPhyErrCount * 1000 /
aniState->listenTime;
cckPhyErrRate = aniState->cckPhyErrCount * 1000 /
aniState->listenTime;
ath_dbg(common, ANI,
"listenTime=%d OFDM:%d errs=%d/s CCK:%d errs=%d/s ofdm_turn=%d\n",
aniState->listenTime,
aniState->ofdmNoiseImmunityLevel,
ofdmPhyErrRate, aniState->cckNoiseImmunityLevel,
cckPhyErrRate, aniState->ofdmsTurn);
if (aniState->listenTime > ah->aniperiod) {
if (cckPhyErrRate < ah->config.cck_trig_low &&
ofdmPhyErrRate < ah->config.ofdm_trig_low) {
ath9k_hw_ani_lower_immunity(ah);
aniState->ofdmsTurn = !aniState->ofdmsTurn;
} else if (ofdmPhyErrRate > ah->config.ofdm_trig_high) {
ath9k_hw_ani_ofdm_err_trigger(ah);
aniState->ofdmsTurn = false;
} else if (cckPhyErrRate > ah->config.cck_trig_high) {
ath9k_hw_ani_cck_err_trigger(ah);
aniState->ofdmsTurn = true;
}
ath9k_ani_restart(ah);
}
}
void ath9k_enable_mib_counters(struct ath_hw *ah)
{
struct ath_common *common = ath9k_hw_common(ah);
ath_dbg(common, ANI, "Enable MIB counters\n");
ath9k_hw_update_mibstats(ah, &ah->ah_mibStats);
ENABLE_REGWRITE_BUFFER(ah);
REG_WRITE(ah, AR_FILT_OFDM, 0);
REG_WRITE(ah, AR_FILT_CCK, 0);
REG_WRITE(ah, AR_MIBC,
~(AR_MIBC_COW | AR_MIBC_FMC | AR_MIBC_CMC | AR_MIBC_MCS)
& 0x0f);
REG_WRITE(ah, AR_PHY_ERR_MASK_1, AR_PHY_ERR_OFDM_TIMING);
REG_WRITE(ah, AR_PHY_ERR_MASK_2, AR_PHY_ERR_CCK_TIMING);
REGWRITE_BUFFER_FLUSH(ah);
}
void ath9k_hw_disable_mib_counters(struct ath_hw *ah)
{
struct ath_common *common = ath9k_hw_common(ah);
ath_dbg(common, ANI, "Disable MIB counters\n");
REG_WRITE(ah, AR_MIBC, AR_MIBC_FMC);
ath9k_hw_update_mibstats(ah, &ah->ah_mibStats);
REG_WRITE(ah, AR_MIBC, AR_MIBC_CMC);
REG_WRITE(ah, AR_FILT_OFDM, 0);
REG_WRITE(ah, AR_FILT_CCK, 0);
}
void ath9k_hw_ani_setup(struct ath_hw *ah)
{
int i;
static const int totalSizeDesired[] = { -55, -55, -55, -55, -62 };
static const int coarseHigh[] = { -14, -14, -14, -14, -12 };
static const int coarseLow[] = { -64, -64, -64, -64, -70 };
static const int firpwr[] = { -78, -78, -78, -78, -80 };
for (i = 0; i < 5; i++) {
ah->totalSizeDesired[i] = totalSizeDesired[i];
ah->coarse_high[i] = coarseHigh[i];
ah->coarse_low[i] = coarseLow[i];
ah->firpwr[i] = firpwr[i];
}
}
void ath9k_hw_ani_init(struct ath_hw *ah)
{
struct ath_common *common = ath9k_hw_common(ah);
int i;
ath_dbg(common, ANI, "Initialize ANI\n");
ah->config.ofdm_trig_high = ATH9K_ANI_OFDM_TRIG_HIGH;
ah->config.ofdm_trig_low = ATH9K_ANI_OFDM_TRIG_LOW;
ah->config.cck_trig_high = ATH9K_ANI_CCK_TRIG_HIGH;
ah->config.cck_trig_low = ATH9K_ANI_CCK_TRIG_LOW;
for (i = 0; i < ARRAY_SIZE(ah->channels); i++) {
struct ath9k_channel *chan = &ah->channels[i];
struct ar5416AniState *ani = &chan->ani;
ani->spurImmunityLevel = ATH9K_ANI_SPUR_IMMUNE_LVL;
ani->firstepLevel = ATH9K_ANI_FIRSTEP_LVL;
ani->mrcCCK = AR_SREV_9300_20_OR_LATER(ah) ? true : false;
ani->ofdmsTurn = true;
ani->rssiThrHigh = ATH9K_ANI_RSSI_THR_HIGH;
ani->rssiThrLow = ATH9K_ANI_RSSI_THR_LOW;
ani->ofdmWeakSigDetect = ATH9K_ANI_USE_OFDM_WEAK_SIG;
ani->cckNoiseImmunityLevel = ATH9K_ANI_CCK_DEF_LEVEL;
ani->ofdmNoiseImmunityLevel = ATH9K_ANI_OFDM_DEF_LEVEL;
}
ah->aniperiod = ATH9K_ANI_PERIOD;
ah->config.ani_poll_interval = ATH9K_ANI_POLLINTERVAL;
if (ah->config.enable_ani)
ah->proc_phyerr |= HAL_PROCESS_ANI;
ath9k_ani_restart(ah);
ath9k_enable_mib_counters(ah);
}
