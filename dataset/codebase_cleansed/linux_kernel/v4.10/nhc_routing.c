static void routing_nhid_setup(struct lowpan_nhc *nhc)
{
nhc->id[0] = LOWPAN_NHC_ROUTING_ID_0;
nhc->idmask[0] = LOWPAN_NHC_ROUTING_MASK_0;
}
