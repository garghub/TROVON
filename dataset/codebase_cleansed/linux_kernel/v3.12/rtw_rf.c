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
u32 rtw_freq2ch(u32 freq)
{
u8 i;
u32 ch = 0;
for (i = 0; i < ch_freq_map_num; i++) {
if (freq == ch_freq_map[i].frequency) {
ch = ch_freq_map[i].channel;
break;
}
}
if (i == ch_freq_map_num)
ch = 1;
return ch;
}
