u16 wlan_ieee2freq(int chan)
{
if (chan == 14) {
return 2484;
}
if (chan < 14) {
return (2407 + (chan*5));
}
if (chan < 27) {
return (2512 + ((chan-15)*20));
}
return (5000 + (chan*5));
}
u32 wlan_freq2ieee(u16 freq)
{
if (freq == 2484)
return 14;
if (freq < 2484)
return (freq - 2407) / 5;
if (freq < 5000)
return 15 + ((freq - 2512) / 20);
return (freq - 5000) / 5;
}
