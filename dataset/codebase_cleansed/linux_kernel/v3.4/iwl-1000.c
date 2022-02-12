static void iwl1000_set_ct_threshold(struct iwl_priv *priv)
{
hw_params(priv).ct_kill_threshold = CT_KILL_THRESHOLD_LEGACY;
hw_params(priv).ct_kill_exit_threshold = CT_KILL_EXIT_THRESHOLD;
}
static void iwl1000_nic_config(struct iwl_priv *priv)
{
iwl_set_bit(trans(priv), CSR_HW_IF_CONFIG_REG,
CSR_HW_IF_CONFIG_REG_BIT_RADIO_SI |
CSR_HW_IF_CONFIG_REG_BIT_MAC_SI);
iwl_set_bits_mask_prph(trans(priv), APMG_DIGITAL_SVR_REG,
APMG_SVR_DIGITAL_VOLTAGE_1_32,
~APMG_SVR_VOLTAGE_CONFIG_BIT_MSK);
}
static void iwl1000_hw_set_hw_params(struct iwl_priv *priv)
{
hw_params(priv).ht40_channel = BIT(IEEE80211_BAND_2GHZ);
hw_params(priv).tx_chains_num =
num_of_ant(hw_params(priv).valid_tx_ant);
if (cfg(priv)->rx_with_siso_diversity)
hw_params(priv).rx_chains_num = 1;
else
hw_params(priv).rx_chains_num =
num_of_ant(hw_params(priv).valid_rx_ant);
iwl1000_set_ct_threshold(priv);
hw_params(priv).sens = &iwl1000_sensitivity;
}
