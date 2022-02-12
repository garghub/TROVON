static void iwl2000_set_ct_threshold(struct iwl_priv *priv)
{
hw_params(priv).ct_kill_threshold = CT_KILL_THRESHOLD;
hw_params(priv).ct_kill_exit_threshold = CT_KILL_EXIT_THRESHOLD;
}
static void iwl2000_nic_config(struct iwl_priv *priv)
{
iwl_rf_config(priv);
if (cfg(priv)->iq_invert)
iwl_set_bit(trans(priv), CSR_GP_DRIVER_REG,
CSR_GP_DRIVER_REG_BIT_RADIO_IQ_INVER);
}
static void iwl2000_hw_set_hw_params(struct iwl_priv *priv)
{
hw_params(priv).ht40_channel = BIT(IEEE80211_BAND_2GHZ);
hw_params(priv).tx_chains_num =
num_of_ant(hw_params(priv).valid_tx_ant);
if (cfg(priv)->rx_with_siso_diversity)
hw_params(priv).rx_chains_num = 1;
else
hw_params(priv).rx_chains_num =
num_of_ant(hw_params(priv).valid_rx_ant);
iwl2000_set_ct_threshold(priv);
hw_params(priv).sens = &iwl2000_sensitivity;
}
