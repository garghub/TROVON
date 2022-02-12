gint
ieee80211_mhz_to_chan(guint freq) {
guint i;
for (i = 0; i < NUM_FREQ_CVT; i++) {
if (freq >= freq_cvt[i].fmin && freq <= freq_cvt[i].fmax) {
return ((freq - freq_cvt[i].fmin) / FREQ_STEP) + freq_cvt[i].cmin;
}
}
return -1;
}
guint
ieee80211_chan_to_mhz(gint chan, gboolean is_bg) {
guint i;
for (i = 0; i < NUM_FREQ_CVT; i++) {
if (is_bg == freq_cvt[i].is_bg &&
chan >= freq_cvt[i].cmin && chan <= MAX_CHANNEL(freq_cvt[i])) {
return ((chan - freq_cvt[i].cmin) * FREQ_STEP) + freq_cvt[i].fmin;
}
}
return 0;
}
gchar*
ieee80211_mhz_to_str(guint freq){
gint chan = ieee80211_mhz_to_chan(freq);
gboolean is_bg = FREQ_IS_BG(freq);
if (chan < 0) {
return g_strdup_printf("%u", freq);
} else {
return g_strdup_printf("%u [%s %u]", freq, is_bg ? "BG" : "A",
chan);
}
}
