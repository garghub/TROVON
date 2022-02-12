static void dest_nhid_setup(struct lowpan_nhc *nhc)
{
nhc->id[0] = LOWPAN_NHC_DEST_ID_0;
nhc->idmask[0] = LOWPAN_NHC_DEST_MASK_0;
}
