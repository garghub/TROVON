static void route_ghid_setup(struct lowpan_nhc *nhc)
{
nhc->id[0] = LOWPAN_GHC_EXT_ROUTE_ID_0;
nhc->idmask[0] = LOWPAN_GHC_EXT_ROUTE_MASK_0;
}
