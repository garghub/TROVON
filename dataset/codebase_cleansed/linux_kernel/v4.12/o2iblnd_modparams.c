int kiblnd_msg_queue_size(int version, struct lnet_ni *ni)
{
if (version == IBLND_MSG_VERSION_1)
return IBLND_MSG_QUEUE_SIZE_V1;
else if (ni)
return ni->ni_peertxcredits;
else
return peer_credits;
}
int kiblnd_tunables_setup(struct lnet_ni *ni)
{
struct lnet_ioctl_config_o2iblnd_tunables *tunables;
if (!ni->ni_lnd_tunables) {
LIBCFS_ALLOC(ni->ni_lnd_tunables,
sizeof(*ni->ni_lnd_tunables));
if (!ni->ni_lnd_tunables)
return -ENOMEM;
memcpy(&ni->ni_lnd_tunables->lt_tun_u.lt_o2ib,
&default_tunables, sizeof(*tunables));
}
tunables = &ni->ni_lnd_tunables->lt_tun_u.lt_o2ib;
tunables->lnd_version = 0;
if (kiblnd_translate_mtu(*kiblnd_tunables.kib_ib_mtu) < 0) {
CERROR("Invalid ib_mtu %d, expected 256/512/1024/2048/4096\n",
*kiblnd_tunables.kib_ib_mtu);
return -EINVAL;
}
if (!ni->ni_peertimeout)
ni->ni_peertimeout = peer_timeout;
if (!ni->ni_maxtxcredits)
ni->ni_maxtxcredits = credits;
if (!ni->ni_peertxcredits)
ni->ni_peertxcredits = peer_credits;
if (!ni->ni_peerrtrcredits)
ni->ni_peerrtrcredits = peer_buffer_credits;
if (ni->ni_peertxcredits < IBLND_CREDITS_DEFAULT)
ni->ni_peertxcredits = IBLND_CREDITS_DEFAULT;
if (ni->ni_peertxcredits > IBLND_CREDITS_MAX)
ni->ni_peertxcredits = IBLND_CREDITS_MAX;
if (ni->ni_peertxcredits > credits)
ni->ni_peertxcredits = credits;
if (!tunables->lnd_peercredits_hiw)
tunables->lnd_peercredits_hiw = peer_credits_hiw;
if (tunables->lnd_peercredits_hiw < ni->ni_peertxcredits / 2)
tunables->lnd_peercredits_hiw = ni->ni_peertxcredits / 2;
if (tunables->lnd_peercredits_hiw >= ni->ni_peertxcredits)
tunables->lnd_peercredits_hiw = ni->ni_peertxcredits - 1;
if (tunables->lnd_map_on_demand <= 0 ||
tunables->lnd_map_on_demand > IBLND_MAX_RDMA_FRAGS) {
CWARN("Invalid map_on_demand (%d), expects 1 - %d. Using default of %d\n",
tunables->lnd_map_on_demand,
IBLND_MAX_RDMA_FRAGS, IBLND_DEFAULT_MAP_ON_DEMAND);
tunables->lnd_map_on_demand = IBLND_DEFAULT_MAP_ON_DEMAND;
}
if (tunables->lnd_map_on_demand == 1) {
tunables->lnd_map_on_demand = 2;
}
if (!tunables->lnd_concurrent_sends) {
if (tunables->lnd_map_on_demand > 0 &&
tunables->lnd_map_on_demand <= IBLND_MAX_RDMA_FRAGS / 8) {
tunables->lnd_concurrent_sends =
ni->ni_peertxcredits * 2;
} else {
tunables->lnd_concurrent_sends = ni->ni_peertxcredits;
}
}
if (tunables->lnd_concurrent_sends > ni->ni_peertxcredits * 2)
tunables->lnd_concurrent_sends = ni->ni_peertxcredits * 2;
if (tunables->lnd_concurrent_sends < ni->ni_peertxcredits / 2)
tunables->lnd_concurrent_sends = ni->ni_peertxcredits / 2;
if (tunables->lnd_concurrent_sends < ni->ni_peertxcredits) {
CWARN("Concurrent sends %d is lower than message queue size: %d, performance may drop slightly.\n",
tunables->lnd_concurrent_sends, ni->ni_peertxcredits);
}
if (!tunables->lnd_fmr_pool_size)
tunables->lnd_fmr_pool_size = fmr_pool_size;
if (!tunables->lnd_fmr_flush_trigger)
tunables->lnd_fmr_flush_trigger = fmr_flush_trigger;
if (!tunables->lnd_fmr_cache)
tunables->lnd_fmr_cache = fmr_cache;
return 0;
}
void kiblnd_tunables_init(void)
{
default_tunables.lnd_version = 0;
default_tunables.lnd_peercredits_hiw = peer_credits_hiw,
default_tunables.lnd_map_on_demand = map_on_demand;
default_tunables.lnd_concurrent_sends = concurrent_sends;
default_tunables.lnd_fmr_pool_size = fmr_pool_size;
default_tunables.lnd_fmr_flush_trigger = fmr_flush_trigger;
default_tunables.lnd_fmr_cache = fmr_cache;
}
