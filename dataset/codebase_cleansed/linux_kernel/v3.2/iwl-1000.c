static void iwl1000_set_ct_threshold(struct iwl_priv *priv)
{
hw_params(priv).ct_kill_threshold = CT_KILL_THRESHOLD_LEGACY;
hw_params(priv).ct_kill_exit_threshold = CT_KILL_EXIT_THRESHOLD;
}
static void iwl1000_nic_config(struct iwl_priv *priv)
{
iwl_set_bit(bus(priv), CSR_HW_IF_CONFIG_REG,
CSR_HW_IF_CONFIG_REG_BIT_RADIO_SI |
CSR_HW_IF_CONFIG_REG_BIT_MAC_SI);
iwl_set_bits_mask_prph(bus(priv), APMG_DIGITAL_SVR_REG,
APMG_SVR_DIGITAL_VOLTAGE_1_32,
~APMG_SVR_VOLTAGE_CONFIG_BIT_MSK);
}
static int iwl1000_hw_set_hw_params(struct iwl_priv *priv)
{
if (iwlagn_mod_params.num_of_queues >= IWL_MIN_NUM_QUEUES &&
iwlagn_mod_params.num_of_queues <= IWLAGN_NUM_QUEUES)
priv->cfg->base_params->num_of_queues =
iwlagn_mod_params.num_of_queues;
hw_params(priv).max_txq_num = priv->cfg->base_params->num_of_queues;
priv->contexts[IWL_RXON_CTX_BSS].bcast_sta_id = IWLAGN_BROADCAST_ID;
hw_params(priv).max_data_size = IWLAGN_RTC_DATA_SIZE;
hw_params(priv).max_inst_size = IWLAGN_RTC_INST_SIZE;
hw_params(priv).ht40_channel = BIT(IEEE80211_BAND_2GHZ);
hw_params(priv).tx_chains_num = num_of_ant(priv->cfg->valid_tx_ant);
if (priv->cfg->rx_with_siso_diversity)
hw_params(priv).rx_chains_num = 1;
else
hw_params(priv).rx_chains_num =
num_of_ant(priv->cfg->valid_rx_ant);
hw_params(priv).valid_tx_ant = priv->cfg->valid_tx_ant;
hw_params(priv).valid_rx_ant = priv->cfg->valid_rx_ant;
iwl1000_set_ct_threshold(priv);
hw_params(priv).sens = &iwl1000_sensitivity;
hw_params(priv).calib_init_cfg =
BIT(IWL_CALIB_XTAL) |
BIT(IWL_CALIB_LO) |
BIT(IWL_CALIB_TX_IQ) |
BIT(IWL_CALIB_TX_IQ_PERD) |
BIT(IWL_CALIB_BASE_BAND);
if (priv->cfg->need_dc_calib)
hw_params(priv).calib_init_cfg |= BIT(IWL_CALIB_DC);
return 0;
}
