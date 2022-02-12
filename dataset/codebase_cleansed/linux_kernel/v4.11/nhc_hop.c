static void hop_nhid_setup(struct lowpan_nhc *nhc)\r\n{\r\nnhc->id[0] = LOWPAN_NHC_HOP_ID_0;\r\nnhc->idmask[0] = LOWPAN_NHC_HOP_MASK_0;\r\n}
