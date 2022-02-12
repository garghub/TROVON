static void mobility_nhid_setup(struct lowpan_nhc *nhc)\r\n{\r\nnhc->id[0] = LOWPAN_NHC_MOBILITY_ID_0;\r\nnhc->idmask[0] = LOWPAN_NHC_MOBILITY_MASK_0;\r\n}
