static void ipv6_nhid_setup(struct lowpan_nhc *nhc)
{
nhc->id[0] = LOWPAN_NHC_IPV6_ID_0;
nhc->idmask[0] = LOWPAN_NHC_IPV6_MASK_0;
}
