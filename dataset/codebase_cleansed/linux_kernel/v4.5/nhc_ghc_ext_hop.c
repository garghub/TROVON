static void hop_ghid_setup(struct lowpan_nhc *nhc)
{
nhc->id[0] = LOWPAN_GHC_EXT_HOP_ID_0;
nhc->idmask[0] = LOWPAN_GHC_EXT_HOP_MASK_0;
}
