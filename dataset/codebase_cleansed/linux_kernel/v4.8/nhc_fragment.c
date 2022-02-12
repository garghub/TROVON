static void fragment_nhid_setup(struct lowpan_nhc *nhc)\r\n{\r\nnhc->id[0] = LOWPAN_NHC_FRAGMENT_ID_0;\r\nnhc->idmask[0] = LOWPAN_NHC_FRAGMENT_MASK_0;\r\n}
