gboolean check_fcs(tvbuff_t *p, guint8 len, guint8 offset, guint8 received_fcs){
guint8 FCS = 0xFF;
guint8 tmp = 0;
while (len--) {
tmp = FCS^tvb_get_guint8(p,offset);
offset++;
FCS=crctable[tmp];
}
FCS=crctable[FCS^received_fcs];
if (FCS==0xCF) {
return TRUE;
}
else {
return FALSE;
}
}
guint8 get_crc8_ieee8023_epon(tvbuff_t *p, guint8 len, guint8 offset) {
guint8 FCS = 0x00;
guint8 tmp = 0;
while (len--) {
tmp = FCS^tvb_get_guint8(p,offset);
offset++;
FCS=crctable[tmp];
}
return FCS;
}
