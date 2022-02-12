static void icmpv6_ghid_setup(struct lowpan_nhc *nhc)
{
nhc->id[0] = LOWPAN_GHC_ICMPV6_ID_0;
nhc->idmask[0] = LOWPAN_GHC_ICMPV6_MASK_0;
}
