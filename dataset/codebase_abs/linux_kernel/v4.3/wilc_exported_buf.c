void * F_1 ( void )
{
return V_1 ;
}
void * F_2 ( void )
{
return V_2 ;
}
void * F_3 ( void )
{
return V_3 ;
}
static int T_1 F_4 ( void )
{
F_5 ( L_1 ) ;
F_6 (g_tx_buf, LINUX_TX_SIZE)
F_6 (g_rx_buf, LINUX_RX_SIZE)
F_6 (g_fw_buf, WILC1000_FW_SIZE)
return 0 ;
}
static void T_2 F_7 ( void )
{
F_5 ( L_2 ) ;
F_8 (g_tx_buf)
F_8 (g_rx_buf)
F_8 (g_fw_buf)
}
