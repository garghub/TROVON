void ar9003_hw_rtt_enable(struct ath_hw *ah)
{
REG_WRITE(ah, AR_PHY_RTT_CTRL, 1);
}
void ar9003_hw_rtt_disable(struct ath_hw *ah)
{
REG_WRITE(ah, AR_PHY_RTT_CTRL, 0);
}
void ar9003_hw_rtt_set_mask(struct ath_hw *ah, u32 rtt_mask)
{
REG_RMW_FIELD(ah, AR_PHY_RTT_CTRL,
AR_PHY_RTT_CTRL_RESTORE_MASK, rtt_mask);
}
bool ar9003_hw_rtt_force_restore(struct ath_hw *ah)
{
if (!ath9k_hw_wait(ah, AR_PHY_RTT_CTRL,
AR_PHY_RTT_CTRL_FORCE_RADIO_RESTORE,
0, RTT_RESTORE_TIMEOUT))
return false;
REG_RMW_FIELD(ah, AR_PHY_RTT_CTRL,
AR_PHY_RTT_CTRL_FORCE_RADIO_RESTORE, 1);
if (!ath9k_hw_wait(ah, AR_PHY_RTT_CTRL,
AR_PHY_RTT_CTRL_FORCE_RADIO_RESTORE,
0, RTT_RESTORE_TIMEOUT))
return false;
return true;
}
static void ar9003_hw_rtt_load_hist_entry(struct ath_hw *ah, u8 chain,
u32 index, u32 data28)
{
u32 val;
val = SM(data28, AR_PHY_RTT_SW_RTT_TABLE_DATA);
REG_WRITE(ah, AR_PHY_RTT_TABLE_SW_INTF_1_B(chain), val);
val = SM(0, AR_PHY_RTT_SW_RTT_TABLE_ACCESS) |
SM(1, AR_PHY_RTT_SW_RTT_TABLE_WRITE) |
SM(index, AR_PHY_RTT_SW_RTT_TABLE_ADDR);
REG_WRITE(ah, AR_PHY_RTT_TABLE_SW_INTF_B(chain), val);
udelay(1);
val |= SM(1, AR_PHY_RTT_SW_RTT_TABLE_ACCESS);
REG_WRITE(ah, AR_PHY_RTT_TABLE_SW_INTF_B(chain), val);
udelay(1);
if (!ath9k_hw_wait(ah, AR_PHY_RTT_TABLE_SW_INTF_B(chain),
AR_PHY_RTT_SW_RTT_TABLE_ACCESS, 0,
RTT_ACCESS_TIMEOUT))
return;
val &= ~SM(1, AR_PHY_RTT_SW_RTT_TABLE_WRITE);
REG_WRITE(ah, AR_PHY_RTT_TABLE_SW_INTF_B(chain), val);
udelay(1);
ath9k_hw_wait(ah, AR_PHY_RTT_TABLE_SW_INTF_B(chain),
AR_PHY_RTT_SW_RTT_TABLE_ACCESS, 0,
RTT_ACCESS_TIMEOUT);
}
void ar9003_hw_rtt_load_hist(struct ath_hw *ah)
{
int chain, i;
for (chain = 0; chain < AR9300_MAX_CHAINS; chain++) {
if (!(ah->rxchainmask & (1 << chain)))
continue;
for (i = 0; i < MAX_RTT_TABLE_ENTRY; i++) {
ar9003_hw_rtt_load_hist_entry(ah, chain, i,
ah->caldata->rtt_table[chain][i]);
ath_dbg(ath9k_hw_common(ah), CALIBRATE,
"Load RTT value at idx %d, chain %d: 0x%x\n",
i, chain, ah->caldata->rtt_table[chain][i]);
}
}
}
static int ar9003_hw_rtt_fill_hist_entry(struct ath_hw *ah, u8 chain, u32 index)
{
u32 val;
val = SM(0, AR_PHY_RTT_SW_RTT_TABLE_ACCESS) |
SM(0, AR_PHY_RTT_SW_RTT_TABLE_WRITE) |
SM(index, AR_PHY_RTT_SW_RTT_TABLE_ADDR);
REG_WRITE(ah, AR_PHY_RTT_TABLE_SW_INTF_B(chain), val);
udelay(1);
val |= SM(1, AR_PHY_RTT_SW_RTT_TABLE_ACCESS);
REG_WRITE(ah, AR_PHY_RTT_TABLE_SW_INTF_B(chain), val);
udelay(1);
if (!ath9k_hw_wait(ah, AR_PHY_RTT_TABLE_SW_INTF_B(chain),
AR_PHY_RTT_SW_RTT_TABLE_ACCESS, 0,
RTT_ACCESS_TIMEOUT))
return RTT_BAD_VALUE;
val = MS(REG_READ(ah, AR_PHY_RTT_TABLE_SW_INTF_1_B(chain)),
AR_PHY_RTT_SW_RTT_TABLE_DATA);
return val;
}
void ar9003_hw_rtt_fill_hist(struct ath_hw *ah)
{
int chain, i;
for (chain = 0; chain < AR9300_MAX_CHAINS; chain++) {
if (!(ah->rxchainmask & (1 << chain)))
continue;
for (i = 0; i < MAX_RTT_TABLE_ENTRY; i++) {
ah->caldata->rtt_table[chain][i] =
ar9003_hw_rtt_fill_hist_entry(ah, chain, i);
ath_dbg(ath9k_hw_common(ah), CALIBRATE,
"RTT value at idx %d, chain %d is: 0x%x\n",
i, chain, ah->caldata->rtt_table[chain][i]);
}
}
ah->caldata->rtt_done = true;
}
void ar9003_hw_rtt_clear_hist(struct ath_hw *ah)
{
int chain, i;
for (chain = 0; chain < AR9300_MAX_CHAINS; chain++) {
if (!(ah->rxchainmask & (1 << chain)))
continue;
for (i = 0; i < MAX_RTT_TABLE_ENTRY; i++)
ar9003_hw_rtt_load_hist_entry(ah, chain, i, 0);
}
if (ah->caldata)
ah->caldata->rtt_done = false;
}
bool ar9003_hw_rtt_restore(struct ath_hw *ah, struct ath9k_channel *chan)
{
bool restore;
if (!ah->caldata)
return false;
if (!ah->caldata->rtt_done)
return false;
ar9003_hw_rtt_enable(ah);
ar9003_hw_rtt_set_mask(ah, 0x10);
if (!ath9k_hw_rfbus_req(ah)) {
ath_err(ath9k_hw_common(ah), "Could not stop baseband\n");
restore = false;
goto fail;
}
ar9003_hw_rtt_load_hist(ah);
restore = ar9003_hw_rtt_force_restore(ah);
fail:
ath9k_hw_rfbus_done(ah);
ar9003_hw_rtt_disable(ah);
return restore;
}
