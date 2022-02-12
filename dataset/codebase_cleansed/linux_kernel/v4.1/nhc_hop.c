static void hop_nhid_setup(struct lowpan_nhc *nhc)
{
nhc->id[0] = LOWPAN_NHC_HOP_ID_0;
nhc->idmask[0] = LOWPAN_NHC_HOP_MASK_0;
}
