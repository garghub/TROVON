static void ath9k_wow_map_triggers(struct ath_softc *sc,
struct cfg80211_wowlan *wowlan,
u32 *wow_triggers)
{
if (wowlan->disconnect)
*wow_triggers |= AH_WOW_LINK_CHANGE |
AH_WOW_BEACON_MISS;
if (wowlan->magic_pkt)
*wow_triggers |= AH_WOW_MAGIC_PATTERN_EN;
if (wowlan->n_patterns)
*wow_triggers |= AH_WOW_USER_PATTERN_EN;
sc->wow_enabled = *wow_triggers;
}
static void ath9k_wow_add_disassoc_deauth_pattern(struct ath_softc *sc)
{
struct ath_hw *ah = sc->sc_ah;
struct ath_common *common = ath9k_hw_common(ah);
int pattern_count = 0;
int i, byte_cnt;
u8 dis_deauth_pattern[MAX_PATTERN_SIZE];
u8 dis_deauth_mask[MAX_PATTERN_SIZE];
memset(dis_deauth_pattern, 0, MAX_PATTERN_SIZE);
memset(dis_deauth_mask, 0, MAX_PATTERN_SIZE);
byte_cnt = 0;
for (i = 0; i < MAX_PATTERN_MASK_SIZE; i++)
dis_deauth_mask[i] = 0xff;
dis_deauth_pattern[byte_cnt] = 0xa0;
byte_cnt++;
byte_cnt += 3;
byte_cnt += 6;
memcpy((dis_deauth_pattern + byte_cnt), common->curbssid, ETH_ALEN);
byte_cnt += 6;
memcpy((dis_deauth_pattern + byte_cnt), common->curbssid, ETH_ALEN);
dis_deauth_mask[0] = 0xfe;
dis_deauth_mask[1] = 0x03;
dis_deauth_mask[2] = 0xc0;
ath_dbg(common, WOW, "Adding disassoc/deauth patterns for WoW\n");
ath9k_hw_wow_apply_pattern(ah, dis_deauth_pattern, dis_deauth_mask,
pattern_count, byte_cnt);
pattern_count++;
dis_deauth_pattern[0] = 0xC0;
ath9k_hw_wow_apply_pattern(ah, dis_deauth_pattern, dis_deauth_mask,
pattern_count, byte_cnt);
}
static void ath9k_wow_add_pattern(struct ath_softc *sc,
struct cfg80211_wowlan *wowlan)
{
struct ath_hw *ah = sc->sc_ah;
struct ath9k_wow_pattern *wow_pattern = NULL;
struct cfg80211_pkt_pattern *patterns = wowlan->patterns;
int mask_len;
s8 i = 0;
if (!wowlan->n_patterns)
return;
for (i = 0; i < wowlan->n_patterns; i++) {
wow_pattern = kzalloc(sizeof(*wow_pattern), GFP_KERNEL);
if (!wow_pattern)
return;
mask_len = DIV_ROUND_UP(wowlan->patterns[i].pattern_len, 8);
memset(wow_pattern->pattern_bytes, 0, MAX_PATTERN_SIZE);
memset(wow_pattern->mask_bytes, 0, MAX_PATTERN_SIZE);
memcpy(wow_pattern->pattern_bytes, patterns[i].pattern,
patterns[i].pattern_len);
memcpy(wow_pattern->mask_bytes, patterns[i].mask, mask_len);
wow_pattern->pattern_len = patterns[i].pattern_len;
ath9k_hw_wow_apply_pattern(ah, wow_pattern->pattern_bytes,
wow_pattern->mask_bytes,
i + 2,
wow_pattern->pattern_len);
kfree(wow_pattern);
}
}
int ath9k_suspend(struct ieee80211_hw *hw,
struct cfg80211_wowlan *wowlan)
{
struct ath_softc *sc = hw->priv;
struct ath_hw *ah = sc->sc_ah;
struct ath_common *common = ath9k_hw_common(ah);
u32 wow_triggers_enabled = 0;
int ret = 0;
mutex_lock(&sc->mutex);
ath_cancel_work(sc);
ath_stop_ani(sc);
if (test_bit(SC_OP_INVALID, &sc->sc_flags)) {
ath_dbg(common, ANY, "Device not present\n");
ret = -EINVAL;
goto fail_wow;
}
if (WARN_ON(!wowlan)) {
ath_dbg(common, WOW, "None of the WoW triggers enabled\n");
ret = -EINVAL;
goto fail_wow;
}
if (!device_can_wakeup(sc->dev)) {
ath_dbg(common, WOW, "device_can_wakeup failed, WoW is not enabled\n");
ret = 1;
goto fail_wow;
}
if (!test_bit(SC_OP_PRIM_STA_VIF, &sc->sc_flags)) {
ath_dbg(common, WOW, "None of the STA vifs are associated\n");
ret = 1;
goto fail_wow;
}
if (sc->nvifs > 1) {
ath_dbg(common, WOW, "WoW for multivif is not yet supported\n");
ret = 1;
goto fail_wow;
}
ath9k_wow_map_triggers(sc, wowlan, &wow_triggers_enabled);
ath_dbg(common, WOW, "WoW triggers enabled 0x%x\n",
wow_triggers_enabled);
ath9k_ps_wakeup(sc);
ath9k_stop_btcoex(sc);
ath9k_wow_add_disassoc_deauth_pattern(sc);
if (wow_triggers_enabled & AH_WOW_USER_PATTERN_EN)
ath9k_wow_add_pattern(sc, wowlan);
spin_lock_bh(&sc->sc_pcu_lock);
sc->wow_intr_before_sleep = ah->imask;
ah->imask &= ~ATH9K_INT_GLOBAL;
ath9k_hw_disable_interrupts(ah);
ah->imask = ATH9K_INT_BMISS | ATH9K_INT_GLOBAL;
ath9k_hw_set_interrupts(ah);
ath9k_hw_enable_interrupts(ah);
spin_unlock_bh(&sc->sc_pcu_lock);
synchronize_irq(sc->irq);
tasklet_kill(&sc->intr_tq);
ath9k_hw_wow_enable(ah, wow_triggers_enabled);
ath9k_ps_restore(sc);
ath_dbg(common, ANY, "WoW enabled in ath9k\n");
atomic_inc(&sc->wow_sleep_proc_intr);
fail_wow:
mutex_unlock(&sc->mutex);
return ret;
}
int ath9k_resume(struct ieee80211_hw *hw)
{
struct ath_softc *sc = hw->priv;
struct ath_hw *ah = sc->sc_ah;
struct ath_common *common = ath9k_hw_common(ah);
u32 wow_status;
mutex_lock(&sc->mutex);
ath9k_ps_wakeup(sc);
spin_lock_bh(&sc->sc_pcu_lock);
ath9k_hw_disable_interrupts(ah);
ah->imask = sc->wow_intr_before_sleep;
ath9k_hw_set_interrupts(ah);
ath9k_hw_enable_interrupts(ah);
spin_unlock_bh(&sc->sc_pcu_lock);
wow_status = ath9k_hw_wow_wakeup(ah);
if (atomic_read(&sc->wow_got_bmiss_intr) == 0) {
wow_status |= AH_WOW_BEACON_MISS;
atomic_dec(&sc->wow_got_bmiss_intr);
ath_dbg(common, ANY, "Beacon miss interrupt picked up during WoW sleep\n");
}
atomic_dec(&sc->wow_sleep_proc_intr);
if (wow_status) {
ath_dbg(common, ANY, "Waking up due to WoW triggers %s with WoW status = %x\n",
ath9k_hw_wow_event_to_string(wow_status), wow_status);
}
ath_restart_work(sc);
ath9k_start_btcoex(sc);
ath9k_ps_restore(sc);
mutex_unlock(&sc->mutex);
return 0;
}
void ath9k_set_wakeup(struct ieee80211_hw *hw, bool enabled)
{
struct ath_softc *sc = hw->priv;
mutex_lock(&sc->mutex);
device_init_wakeup(sc->dev, 1);
device_set_wakeup_enable(sc->dev, enabled);
mutex_unlock(&sc->mutex);
}
void ath9k_init_wow(struct ieee80211_hw *hw)
{
struct ath_softc *sc = hw->priv;
if ((sc->sc_ah->caps.hw_caps & ATH9K_HW_WOW_DEVICE_CAPABLE) &&
(sc->driver_data & ATH9K_PCI_WOW) &&
device_can_wakeup(sc->dev))
hw->wiphy->wowlan = &ath9k_wowlan_support;
atomic_set(&sc->wow_sleep_proc_intr, -1);
atomic_set(&sc->wow_got_bmiss_intr, -1);
}
