static int iwl_pcie_gen2_apm_init(struct iwl_trans *trans)
{
int ret = 0;
IWL_DEBUG_INFO(trans, "Init card's basic functions\n");
iwl_set_bit(trans, CSR_GIO_CHICKEN_BITS,
CSR_GIO_CHICKEN_BITS_REG_BIT_L1A_NO_L0S_RX);
iwl_set_bit(trans, CSR_DBG_HPET_MEM_REG, CSR_DBG_HPET_MEM_REG_VAL);
iwl_set_bit(trans, CSR_HW_IF_CONFIG_REG,
CSR_HW_IF_CONFIG_REG_BIT_HAP_WAKE_L1A);
iwl_pcie_apm_config(trans);
iwl_set_bit(trans, CSR_GP_CNTRL, CSR_GP_CNTRL_REG_FLAG_INIT_DONE);
ret = iwl_poll_bit(trans, CSR_GP_CNTRL,
CSR_GP_CNTRL_REG_FLAG_MAC_CLOCK_READY,
CSR_GP_CNTRL_REG_FLAG_MAC_CLOCK_READY, 25000);
if (ret < 0) {
IWL_DEBUG_INFO(trans, "Failed to init the card\n");
return ret;
}
set_bit(STATUS_DEVICE_ENABLED, &trans->status);
return 0;
}
static void iwl_pcie_gen2_apm_stop(struct iwl_trans *trans, bool op_mode_leave)
{
IWL_DEBUG_INFO(trans, "Stop card, put in low power state\n");
if (op_mode_leave) {
if (!test_bit(STATUS_DEVICE_ENABLED, &trans->status))
iwl_pcie_gen2_apm_init(trans);
iwl_set_bit(trans, CSR_DBG_LINK_PWR_MGMT_REG,
CSR_RESET_LINK_PWR_MGMT_DISABLED);
iwl_set_bit(trans, CSR_HW_IF_CONFIG_REG,
CSR_HW_IF_CONFIG_REG_PREPARE |
CSR_HW_IF_CONFIG_REG_ENABLE_PME);
mdelay(1);
iwl_clear_bit(trans, CSR_DBG_LINK_PWR_MGMT_REG,
CSR_RESET_LINK_PWR_MGMT_DISABLED);
mdelay(5);
}
clear_bit(STATUS_DEVICE_ENABLED, &trans->status);
iwl_pcie_apm_stop_master(trans);
iwl_pcie_sw_reset(trans);
iwl_clear_bit(trans, CSR_GP_CNTRL, CSR_GP_CNTRL_REG_FLAG_INIT_DONE);
}
void _iwl_trans_pcie_gen2_stop_device(struct iwl_trans *trans, bool low_power)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
lockdep_assert_held(&trans_pcie->mutex);
if (trans_pcie->is_down)
return;
trans_pcie->is_down = true;
iwl_disable_interrupts(trans);
iwl_pcie_disable_ict(trans);
if (test_and_clear_bit(STATUS_DEVICE_ENABLED, &trans->status)) {
IWL_DEBUG_INFO(trans,
"DEVICE_ENABLED bit was set and is now cleared\n");
iwl_pcie_gen2_tx_stop(trans);
iwl_pcie_rx_stop(trans);
}
iwl_pcie_ctxt_info_free_paging(trans);
iwl_pcie_ctxt_info_free(trans);
iwl_clear_bit(trans, CSR_GP_CNTRL,
CSR_GP_CNTRL_REG_FLAG_MAC_ACCESS_REQ);
iwl_pcie_gen2_apm_stop(trans, false);
iwl_pcie_sw_reset(trans);
iwl_pcie_conf_msix_hw(trans_pcie);
iwl_disable_interrupts(trans);
clear_bit(STATUS_SYNC_HCMD_ACTIVE, &trans->status);
clear_bit(STATUS_INT_ENABLED, &trans->status);
clear_bit(STATUS_TPOWER_PMI, &trans->status);
iwl_enable_rfkill_int(trans);
iwl_pcie_prepare_card_hw(trans);
}
void iwl_trans_pcie_gen2_stop_device(struct iwl_trans *trans, bool low_power)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
bool was_in_rfkill;
mutex_lock(&trans_pcie->mutex);
trans_pcie->opmode_down = true;
was_in_rfkill = test_bit(STATUS_RFKILL_OPMODE, &trans->status);
_iwl_trans_pcie_gen2_stop_device(trans, low_power);
iwl_trans_pcie_handle_stop_rfkill(trans, was_in_rfkill);
mutex_unlock(&trans_pcie->mutex);
}
static int iwl_pcie_gen2_nic_init(struct iwl_trans *trans)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
spin_lock(&trans_pcie->irq_lock);
iwl_pcie_gen2_apm_init(trans);
spin_unlock(&trans_pcie->irq_lock);
iwl_op_mode_nic_config(trans->op_mode);
if (iwl_pcie_gen2_rx_init(trans))
return -ENOMEM;
if (iwl_pcie_gen2_tx_init(trans))
return -ENOMEM;
iwl_set_bit(trans, CSR_MAC_SHADOW_REG_CTRL, 0x800FFFFF);
IWL_DEBUG_INFO(trans, "Enabling shadow registers in device\n");
return 0;
}
void iwl_trans_pcie_gen2_fw_alive(struct iwl_trans *trans, u32 scd_addr)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
iwl_pcie_reset_ict(trans);
memset(trans_pcie->queue_stopped, 0, sizeof(trans_pcie->queue_stopped));
memset(trans_pcie->queue_used, 0, sizeof(trans_pcie->queue_used));
iwl_pcie_ctxt_info_free(trans);
}
int iwl_trans_pcie_gen2_start_fw(struct iwl_trans *trans,
const struct fw_img *fw, bool run_in_rfkill)
{
struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
bool hw_rfkill;
int ret;
if (iwl_pcie_prepare_card_hw(trans)) {
IWL_WARN(trans, "Exit HW not ready\n");
ret = -EIO;
goto out;
}
iwl_enable_rfkill_int(trans);
iwl_write32(trans, CSR_INT, 0xFFFFFFFF);
iwl_disable_interrupts(trans);
iwl_pcie_synchronize_irqs(trans);
mutex_lock(&trans_pcie->mutex);
hw_rfkill = iwl_trans_check_hw_rf_kill(trans);
if (hw_rfkill && !run_in_rfkill) {
ret = -ERFKILL;
goto out;
}
if (trans_pcie->is_down) {
IWL_WARN(trans,
"Can't start_fw since the HW hasn't been started\n");
ret = -EIO;
goto out;
}
iwl_write32(trans, CSR_UCODE_DRV_GP1_CLR, CSR_UCODE_SW_BIT_RFKILL);
iwl_write32(trans, CSR_UCODE_DRV_GP1_CLR,
CSR_UCODE_DRV_GP1_BIT_CMD_BLOCKED);
iwl_write32(trans, CSR_INT, 0xFFFFFFFF);
ret = iwl_pcie_gen2_nic_init(trans);
if (ret) {
IWL_ERR(trans, "Unable to init nic\n");
goto out;
}
ret = iwl_pcie_ctxt_info_init(trans, fw);
if (ret)
goto out;
hw_rfkill = iwl_trans_check_hw_rf_kill(trans);
if (hw_rfkill && !run_in_rfkill)
ret = -ERFKILL;
out:
mutex_unlock(&trans_pcie->mutex);
return ret;
}
