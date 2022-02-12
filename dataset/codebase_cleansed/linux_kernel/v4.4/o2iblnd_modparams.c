int
kiblnd_tunables_init(void)
{
if (kiblnd_translate_mtu(*kiblnd_tunables.kib_ib_mtu) < 0) {
CERROR("Invalid ib_mtu %d, expected 256/512/1024/2048/4096\n",
*kiblnd_tunables.kib_ib_mtu);
return -EINVAL;
}
if (*kiblnd_tunables.kib_peertxcredits < IBLND_CREDITS_DEFAULT)
*kiblnd_tunables.kib_peertxcredits = IBLND_CREDITS_DEFAULT;
if (*kiblnd_tunables.kib_peertxcredits > IBLND_CREDITS_MAX)
*kiblnd_tunables.kib_peertxcredits = IBLND_CREDITS_MAX;
if (*kiblnd_tunables.kib_peertxcredits > *kiblnd_tunables.kib_credits)
*kiblnd_tunables.kib_peertxcredits = *kiblnd_tunables.kib_credits;
if (*kiblnd_tunables.kib_peercredits_hiw < *kiblnd_tunables.kib_peertxcredits / 2)
*kiblnd_tunables.kib_peercredits_hiw = *kiblnd_tunables.kib_peertxcredits / 2;
if (*kiblnd_tunables.kib_peercredits_hiw >= *kiblnd_tunables.kib_peertxcredits)
*kiblnd_tunables.kib_peercredits_hiw = *kiblnd_tunables.kib_peertxcredits - 1;
if (*kiblnd_tunables.kib_map_on_demand < 0 ||
*kiblnd_tunables.kib_map_on_demand > IBLND_MAX_RDMA_FRAGS)
*kiblnd_tunables.kib_map_on_demand = 0;
if (*kiblnd_tunables.kib_map_on_demand == 1)
*kiblnd_tunables.kib_map_on_demand = 2;
if (*kiblnd_tunables.kib_concurrent_sends == 0) {
if (*kiblnd_tunables.kib_map_on_demand > 0 &&
*kiblnd_tunables.kib_map_on_demand <= IBLND_MAX_RDMA_FRAGS / 8)
*kiblnd_tunables.kib_concurrent_sends = (*kiblnd_tunables.kib_peertxcredits) * 2;
else
*kiblnd_tunables.kib_concurrent_sends = (*kiblnd_tunables.kib_peertxcredits);
}
if (*kiblnd_tunables.kib_concurrent_sends > *kiblnd_tunables.kib_peertxcredits * 2)
*kiblnd_tunables.kib_concurrent_sends = *kiblnd_tunables.kib_peertxcredits * 2;
if (*kiblnd_tunables.kib_concurrent_sends < *kiblnd_tunables.kib_peertxcredits / 2)
*kiblnd_tunables.kib_concurrent_sends = *kiblnd_tunables.kib_peertxcredits / 2;
if (*kiblnd_tunables.kib_concurrent_sends < *kiblnd_tunables.kib_peertxcredits) {
CWARN("Concurrent sends %d is lower than message queue size: %d, performance may drop slightly.\n",
*kiblnd_tunables.kib_concurrent_sends, *kiblnd_tunables.kib_peertxcredits);
}
return 0;
}
