static void batadv_bitmap_shift_left(unsigned long *seq_bits, int32_t n)
{
if (n <= 0 || n >= BATADV_TQ_LOCAL_WINDOW_SIZE)
return;
bitmap_shift_left(seq_bits, seq_bits, n, BATADV_TQ_LOCAL_WINDOW_SIZE);
}
int batadv_bit_get_packet(void *priv, unsigned long *seq_bits,
int32_t seq_num_diff, int set_mark)
{
struct batadv_priv *bat_priv = priv;
if (seq_num_diff <= 0 && seq_num_diff > -BATADV_TQ_LOCAL_WINDOW_SIZE) {
if (set_mark)
batadv_set_bit(seq_bits, -seq_num_diff);
return 0;
}
if (seq_num_diff > 0 && seq_num_diff < BATADV_TQ_LOCAL_WINDOW_SIZE) {
batadv_bitmap_shift_left(seq_bits, seq_num_diff);
if (set_mark)
batadv_set_bit(seq_bits, 0);
return 1;
}
if (seq_num_diff >= BATADV_TQ_LOCAL_WINDOW_SIZE &&
seq_num_diff < BATADV_EXPECTED_SEQNO_RANGE) {
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"We missed a lot of packets (%i) !\n",
seq_num_diff - 1);
bitmap_zero(seq_bits, BATADV_TQ_LOCAL_WINDOW_SIZE);
if (set_mark)
batadv_set_bit(seq_bits, 0);
return 1;
}
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"Other host probably restarted!\n");
bitmap_zero(seq_bits, BATADV_TQ_LOCAL_WINDOW_SIZE);
if (set_mark)
batadv_set_bit(seq_bits, 0);
return 1;
}
