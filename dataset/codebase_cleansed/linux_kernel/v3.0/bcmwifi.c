bool bcm_chspec_malformed(chanspec_t chanspec)
{
if (!CHSPEC_IS5G(chanspec) && !CHSPEC_IS2G(chanspec))
return true;
if (!CHSPEC_IS40(chanspec) && !CHSPEC_IS20(chanspec))
return true;
if (CHSPEC_IS20(chanspec)) {
if (!CHSPEC_SB_NONE(chanspec))
return true;
} else {
if (!CHSPEC_SB_UPPER(chanspec) && !CHSPEC_SB_LOWER(chanspec))
return true;
}
return false;
}
u8 bcm_chspec_ctlchan(chanspec_t chspec)
{
u8 ctl_chan;
if (CHSPEC_CTL_SB(chspec) == WL_CHANSPEC_CTL_SB_NONE) {
return CHSPEC_CHANNEL(chspec);
} else {
if (CHSPEC_CTL_SB(chspec) == WL_CHANSPEC_CTL_SB_UPPER) {
ctl_chan = UPPER_20_SB(CHSPEC_CHANNEL(chspec));
} else {
ctl_chan = LOWER_20_SB(CHSPEC_CHANNEL(chspec));
}
}
return ctl_chan;
}
int bcm_mhz2channel(uint freq, uint start_factor)
{
int ch = -1;
uint base;
int offset;
if (start_factor == 0) {
if (freq >= 2400 && freq <= 2500)
start_factor = WF_CHAN_FACTOR_2_4_G;
else if (freq >= 5000 && freq <= 6000)
start_factor = WF_CHAN_FACTOR_5_G;
}
if (freq == 2484 && start_factor == WF_CHAN_FACTOR_2_4_G)
return 14;
base = start_factor / 2;
if ((freq < base) || (freq > base + 1000))
return -1;
offset = freq - base;
ch = offset / 5;
if (offset != (ch * 5))
return -1;
if (start_factor == WF_CHAN_FACTOR_2_4_G && (ch < 1 || ch > 13))
return -1;
return ch;
}
