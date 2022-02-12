static void routing_nhid_setup(struct lowpan_nhc *nhc)\r\n{\r\nnhc->id[0] = LOWPAN_NHC_ROUTING_ID_0;\r\nnhc->idmask[0] = LOWPAN_NHC_ROUTING_MASK_0;\r\n}
