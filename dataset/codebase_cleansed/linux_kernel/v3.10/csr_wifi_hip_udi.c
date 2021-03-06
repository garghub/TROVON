s32 unifi_print_status(card_t *card, struct seq_file *m)
{
sdio_config_data_t *cfg;
u16 i, n;
i = n = 0;
seq_printf(m, "Chip ID %u\n", card->chip_id);
seq_printf(m, "Chip Version %04X\n", card->chip_version);
seq_printf(m, "HIP v%u.%u\n",
(card->config_data.version >> 8) & 0xFF,
card->config_data.version & 0xFF);
seq_printf(m, "Build %u: %s\n", card->build_id, card->build_id_string);
cfg = &card->config_data;
seq_printf(m, "sdio ctrl offset %u\n", cfg->sdio_ctrl_offset);
seq_printf(m, "fromhost sigbuf handle %u\n", cfg->fromhost_sigbuf_handle);
seq_printf(m, "tohost_sigbuf_handle %u\n", cfg->tohost_sigbuf_handle);
seq_printf(m, "num_fromhost_sig_frags %u\n", cfg->num_fromhost_sig_frags);
seq_printf(m, "num_tohost_sig_frags %u\n", cfg->num_tohost_sig_frags);
seq_printf(m, "num_fromhost_data_slots %u\n", cfg->num_fromhost_data_slots);
seq_printf(m, "num_tohost_data_slots %u\n", cfg->num_tohost_data_slots);
seq_printf(m, "data_slot_size %u\n", cfg->data_slot_size);
seq_printf(m, "overlay_size %u\n", cfg->overlay_size);
seq_printf(m, "data_slot_round %u\n", cfg->data_slot_round);
seq_printf(m, "sig_frag_size %u\n", cfg->sig_frag_size);
seq_printf(m, "tohost_sig_pad %u\n", cfg->tohost_signal_padding);
seq_puts(m, "\nInternal state:\n");
seq_printf(m, "Last PHY PANIC: %04x:%04x\n",
card->last_phy_panic_code, card->last_phy_panic_arg);
seq_printf(m, "Last MAC PANIC: %04x:%04x\n",
card->last_mac_panic_code, card->last_mac_panic_arg);
seq_printf(m, "fhsr: %hu\n", (u16)card->from_host_signals_r);
seq_printf(m, "fhsw: %hu\n", (u16)card->from_host_signals_w);
seq_printf(m, "thsr: %hu\n", (u16)card->to_host_signals_r);
seq_printf(m, "thsw: %hu\n", (u16)card->to_host_signals_w);
seq_printf(m, "fh buffer contains: %d signals, %td bytes\n",
card->fh_buffer.count,
card->fh_buffer.ptr - card->fh_buffer.buf);
seq_puts(m, "paused: ");
for (i = 0; i < ARRAY_SIZE(card->tx_q_paused_flag); i++)
seq_printf(m, card->tx_q_paused_flag[i] ? "1" : "0");
seq_putc(m, '\n');
seq_printf(m, "fh command q: %u waiting, %u free of %u:\n",
CSR_WIFI_HIP_Q_SLOTS_USED(&card->fh_command_queue),
CSR_WIFI_HIP_Q_SLOTS_FREE(&card->fh_command_queue),
UNIFI_SOFT_COMMAND_Q_LENGTH);
for (i = 0; i < UNIFI_NO_OF_TX_QS; i++)
seq_printf(m, "fh traffic q[%u]: %u waiting, %u free of %u:\n",
i,
CSR_WIFI_HIP_Q_SLOTS_USED(&card->fh_traffic_queue[i]),
CSR_WIFI_HIP_Q_SLOTS_FREE(&card->fh_traffic_queue[i]),
UNIFI_SOFT_TRAFFIC_Q_LENGTH);
seq_printf(m, "fh data slots free: %u\n",
card->from_host_data ? CardGetFreeFromHostDataSlots(card) : 0);
seq_puts(m, "From host data slots:");
n = card->config_data.num_fromhost_data_slots;
for (i = 0; i < n && card->from_host_data; i++)
seq_printf(m, " %hu", (u16)card->from_host_data[i].bd.data_length);
seq_putc(m, '\n');
seq_puts(m, "To host data slots:");
n = card->config_data.num_tohost_data_slots;
for (i = 0; i < n && card->to_host_data; i++)
seq_printf(m, " %hu", (u16)card->to_host_data[i].data_length);
seq_putc(m, '\n');
unifi_print_unsafe_sdio_status(card, m);
seq_puts(m, "\nStats:\n");
seq_printf(m, "Total SDIO bytes: R=%u W=%u\n",
card->sdio_bytes_read, card->sdio_bytes_written);
seq_printf(m, "Interrupts generated on card: %u\n", card->unifi_interrupt_seq);
return 0;
}
