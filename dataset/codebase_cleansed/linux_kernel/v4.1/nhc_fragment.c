static void fragment_nhid_setup(struct lowpan_nhc *nhc)
{
nhc->id[0] = LOWPAN_NHC_FRAGMENT_ID_0;
nhc->idmask[0] = LOWPAN_NHC_FRAGMENT_MASK_0;
}
