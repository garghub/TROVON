s8 odm_CCKRSSI_8723B(u8 LNA_idx, u8 VGA_idx)
{
s8 rx_pwr_all = 0x00;
switch (LNA_idx) {
case 6:
rx_pwr_all = -34 - (2 * VGA_idx);
break;
case 4:
rx_pwr_all = -14 - (2 * VGA_idx);
break;
case 1:
rx_pwr_all = 6 - (2 * VGA_idx);
break;
case 0:
rx_pwr_all = 16 - (2 * VGA_idx);
break;
default:
break;
}
return rx_pwr_all;
}
