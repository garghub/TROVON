int __init tfrc_lib_init(void)
{
int rc = tfrc_li_init();
if (rc)
goto out;
rc = tfrc_tx_packet_history_init();
if (rc)
goto out_free_loss_intervals;
rc = tfrc_rx_packet_history_init();
if (rc)
goto out_free_tx_history;
return 0;
out_free_tx_history:
tfrc_tx_packet_history_exit();
out_free_loss_intervals:
tfrc_li_exit();
out:
return rc;
}
void tfrc_lib_exit(void)
{
tfrc_rx_packet_history_exit();
tfrc_tx_packet_history_exit();
tfrc_li_exit();
}
