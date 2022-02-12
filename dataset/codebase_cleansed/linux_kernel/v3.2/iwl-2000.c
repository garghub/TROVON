static void iwl2000_set_ct_threshold(struct iwl_priv *priv)
{
hw_params(priv).ct_kill_threshold = CT_KILL_THRESHOLD;
hw_params(priv).ct_kill_exit_threshold = CT_KILL_EXIT_THRESHOLD;
}
static void iwl2000_nic_config(struct iwl_priv *priv)
{
iwl_rf_config(priv);
if (priv->cfg->iq_invert)
iwl_set_bit(bus(priv), CSR_GP_DRIVER_REG,
CSR_GP_DRIVER_REG_BIT_RADIO_IQ_INVER);
}
static int iwl2000_hw_set_hw_params(struct iwl_priv *priv)
{
if (iwlagn_mod_params.num_of_queues >= IWL_MIN_NUM_QUEUES &&
iwlagn_mod_params.num_of_queues <= IWLAGN_NUM_QUEUES)
priv->cfg->base_params->num_of_queues =
iwlagn_mod_params.num_of_queues;
hw_params(priv).max_txq_num = priv->cfg->base_params->num_of_queues;
priv->contexts[IWL_RXON_CTX_BSS].bcast_sta_id = IWLAGN_BROADCAST_ID;
hw_params(priv).max_data_size = IWL60_RTC_DATA_SIZE;
hw_params(priv).max_inst_size = IWL60_RTC_INST_SIZE;
hw_params(priv).ht40_channel = BIT(IEEE80211_BAND_2GHZ);
hw_params(priv).tx_chains_num = num_of_ant(priv->cfg->valid_tx_ant);
if (priv->cfg->rx_with_siso_diversity)
hw_params(priv).rx_chains_num = 1;
else
hw_params(priv).rx_chains_num =
num_of_ant(priv->cfg->valid_rx_ant);
hw_params(priv).valid_tx_ant = priv->cfg->valid_tx_ant;
hw_params(priv).valid_rx_ant = priv->cfg->valid_rx_ant;
iwl2000_set_ct_threshold(priv);
hw_params(priv).sens = &iwl2000_sensitivity;
hw_params(priv).calib_init_cfg =
BIT(IWL_CALIB_XTAL) |
BIT(IWL_CALIB_LO) |
BIT(IWL_CALIB_TX_IQ) |
BIT(IWL_CALIB_BASE_BAND);
if (priv->cfg->need_dc_calib)
hw_params(priv).calib_rt_cfg |= IWL_CALIB_CFG_DC_IDX;
if (priv->cfg->need_temp_offset_calib)
hw_params(priv).calib_init_cfg |= BIT(IWL_CALIB_TEMP_OFFSET);
return 0;
}
