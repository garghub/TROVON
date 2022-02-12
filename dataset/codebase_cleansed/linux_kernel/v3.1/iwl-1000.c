static void iwl1000_set_ct_threshold(struct iwl_priv *priv)
{
priv->hw_params.ct_kill_threshold = CT_KILL_THRESHOLD_LEGACY;
priv->hw_params.ct_kill_exit_threshold = CT_KILL_EXIT_THRESHOLD;
}
static void iwl1000_nic_config(struct iwl_priv *priv)
{
iwl_set_bit(priv, CSR_HW_IF_CONFIG_REG,
CSR_HW_IF_CONFIG_REG_BIT_RADIO_SI |
CSR_HW_IF_CONFIG_REG_BIT_MAC_SI);
iwl_set_bits_mask_prph(priv, APMG_DIGITAL_SVR_REG,
APMG_SVR_DIGITAL_VOLTAGE_1_32,
~APMG_SVR_VOLTAGE_CONFIG_BIT_MSK);
}
static int iwl1000_hw_set_hw_params(struct iwl_priv *priv)
{
if (iwlagn_mod_params.num_of_queues >= IWL_MIN_NUM_QUEUES &&
iwlagn_mod_params.num_of_queues <= IWLAGN_NUM_QUEUES)
priv->cfg->base_params->num_of_queues =
iwlagn_mod_params.num_of_queues;
priv->hw_params.max_txq_num = priv->cfg->base_params->num_of_queues;
priv->hw_params.scd_bc_tbls_size =
priv->cfg->base_params->num_of_queues *
sizeof(struct iwlagn_scd_bc_tbl);
priv->hw_params.tfd_size = sizeof(struct iwl_tfd);
priv->hw_params.max_stations = IWLAGN_STATION_COUNT;
priv->contexts[IWL_RXON_CTX_BSS].bcast_sta_id = IWLAGN_BROADCAST_ID;
priv->hw_params.max_data_size = IWLAGN_RTC_DATA_SIZE;
priv->hw_params.max_inst_size = IWLAGN_RTC_INST_SIZE;
priv->hw_params.ht40_channel = BIT(IEEE80211_BAND_2GHZ) |
BIT(IEEE80211_BAND_5GHZ);
priv->hw_params.tx_chains_num = num_of_ant(priv->cfg->valid_tx_ant);
if (priv->cfg->rx_with_siso_diversity)
priv->hw_params.rx_chains_num = 1;
else
priv->hw_params.rx_chains_num =
num_of_ant(priv->cfg->valid_rx_ant);
priv->hw_params.valid_tx_ant = priv->cfg->valid_tx_ant;
priv->hw_params.valid_rx_ant = priv->cfg->valid_rx_ant;
iwl1000_set_ct_threshold(priv);
priv->hw_params.sens = &iwl1000_sensitivity;
priv->hw_params.calib_init_cfg =
BIT(IWL_CALIB_XTAL) |
BIT(IWL_CALIB_LO) |
BIT(IWL_CALIB_TX_IQ) |
BIT(IWL_CALIB_TX_IQ_PERD) |
BIT(IWL_CALIB_BASE_BAND);
if (priv->cfg->need_dc_calib)
priv->hw_params.calib_init_cfg |= BIT(IWL_CALIB_DC);
priv->hw_params.beacon_time_tsf_bits = IWLAGN_EXT_BEACON_TIME_POS;
return 0;
}
