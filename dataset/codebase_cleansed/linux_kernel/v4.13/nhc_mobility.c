static void mobility_nhid_setup(struct lowpan_nhc *nhc)
{
nhc->id[0] = LOWPAN_NHC_MOBILITY_ID_0;
nhc->idmask[0] = LOWPAN_NHC_MOBILITY_MASK_0;
}
