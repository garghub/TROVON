void *get_tx_buffer(void)
{
return exported_g_tx_buf;
}
void *get_rx_buffer(void)
{
return exported_g_rx_buf;
}
void *get_fw_buffer(void)
{
return exported_g_fw_buf;
}
static int __init wilc_module_init(void)
{
printk("wilc_module_init\n");
MALLOC_WILC_BUFFER(g_tx_buf, LINUX_TX_SIZE)
MALLOC_WILC_BUFFER(g_rx_buf, LINUX_RX_SIZE)
MALLOC_WILC_BUFFER(g_fw_buf, WILC1000_FW_SIZE)
return 0;
}
static void __exit wilc_module_deinit(void)
{
printk("wilc_module_deinit\n");
FREE_WILC_BUFFER(g_tx_buf)
FREE_WILC_BUFFER(g_rx_buf)
FREE_WILC_BUFFER(g_fw_buf)
}
