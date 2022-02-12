static void udp_ghid_setup(struct lowpan_nhc *nhc)
{
nhc->id[0] = LOWPAN_GHC_UDP_ID_0;
nhc->idmask[0] = LOWPAN_GHC_UDP_MASK_0;
}
