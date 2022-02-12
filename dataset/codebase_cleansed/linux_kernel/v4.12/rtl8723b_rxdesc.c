static void process_rssi(struct adapter *padapter, union recv_frame *prframe)
{
struct rx_pkt_attrib *pattrib = &prframe->u.hdr.attrib;
struct signal_stat *signal_stat = &padapter->recvpriv.signal_strength_data;
{
if (signal_stat->update_req) {
signal_stat->total_num = 0;
signal_stat->total_val = 0;
signal_stat->update_req = 0;
}
signal_stat->total_num++;
signal_stat->total_val += pattrib->phy_info.SignalStrength;
signal_stat->avg_val = signal_stat->total_val / signal_stat->total_num;
}
}
static void process_link_qual(struct adapter *padapter, union recv_frame *prframe)
{
struct rx_pkt_attrib *pattrib;
struct signal_stat *signal_stat;
if (prframe == NULL || padapter == NULL)
return;
pattrib = &prframe->u.hdr.attrib;
signal_stat = &padapter->recvpriv.signal_qual_data;
if (signal_stat->update_req) {
signal_stat->total_num = 0;
signal_stat->total_val = 0;
signal_stat->update_req = 0;
}
signal_stat->total_num++;
signal_stat->total_val += pattrib->phy_info.SignalQuality;
signal_stat->avg_val = signal_stat->total_val / signal_stat->total_num;
}
void rtl8723b_process_phy_info(struct adapter *padapter, void *prframe)
{
union recv_frame *precvframe = (union recv_frame *)prframe;
process_rssi(padapter, precvframe);
process_link_qual(padapter, precvframe);
#ifdef DBG_RX_SIGNAL_DISPLAY_RAW_DATA
rtw_store_phy_info(padapter, prframe);
#endif
}
