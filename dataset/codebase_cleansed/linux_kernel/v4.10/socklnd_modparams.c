int ksocknal_tunables_init(void)
{
ksocknal_tunables.ksnd_timeout = &sock_timeout;
ksocknal_tunables.ksnd_nscheds = &nscheds;
ksocknal_tunables.ksnd_nconnds = &nconnds;
ksocknal_tunables.ksnd_nconnds_max = &nconnds_max;
ksocknal_tunables.ksnd_min_reconnectms = &min_reconnectms;
ksocknal_tunables.ksnd_max_reconnectms = &max_reconnectms;
ksocknal_tunables.ksnd_eager_ack = &eager_ack;
ksocknal_tunables.ksnd_typed_conns = &typed_conns;
ksocknal_tunables.ksnd_min_bulk = &min_bulk;
ksocknal_tunables.ksnd_tx_buffer_size = &tx_buffer_size;
ksocknal_tunables.ksnd_rx_buffer_size = &rx_buffer_size;
ksocknal_tunables.ksnd_nagle = &nagle;
ksocknal_tunables.ksnd_round_robin = &round_robin;
ksocknal_tunables.ksnd_keepalive = &keepalive;
ksocknal_tunables.ksnd_keepalive_idle = &keepalive_idle;
ksocknal_tunables.ksnd_keepalive_count = &keepalive_count;
ksocknal_tunables.ksnd_keepalive_intvl = &keepalive_intvl;
ksocknal_tunables.ksnd_credits = &credits;
ksocknal_tunables.ksnd_peertxcredits = &peer_credits;
ksocknal_tunables.ksnd_peerrtrcredits = &peer_buffer_credits;
ksocknal_tunables.ksnd_peertimeout = &peer_timeout;
ksocknal_tunables.ksnd_enable_csum = &enable_csum;
ksocknal_tunables.ksnd_inject_csum_error = &inject_csum_error;
ksocknal_tunables.ksnd_nonblk_zcack = &nonblk_zcack;
ksocknal_tunables.ksnd_zc_min_payload = &zc_min_payload;
ksocknal_tunables.ksnd_zc_recv = &zc_recv;
ksocknal_tunables.ksnd_zc_recv_min_nfrags = &zc_recv_min_nfrags;
#if SOCKNAL_VERSION_DEBUG
ksocknal_tunables.ksnd_protocol = &protocol;
#endif
if (*ksocknal_tunables.ksnd_zc_min_payload < (2 << 10))
*ksocknal_tunables.ksnd_zc_min_payload = 2 << 10;
return 0;
}
