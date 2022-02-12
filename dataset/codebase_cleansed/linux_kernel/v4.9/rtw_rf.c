u32 rtw_ch2freq(u32 channel)
{
u8 i;
u32 freq = 0;
for (i = 0; i < ch_freq_map_num; i++) {
if (channel == ch_freq_map[i].channel) {
freq = ch_freq_map[i].frequency;
break;
}
}
if (i == ch_freq_map_num)
freq = 2412;
return freq;
}
