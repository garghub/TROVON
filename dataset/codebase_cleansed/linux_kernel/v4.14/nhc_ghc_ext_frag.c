static void frag_ghid_setup(struct lowpan_nhc *nhc)\r\n{\r\nnhc->id[0] = LOWPAN_GHC_EXT_FRAG_ID_0;\r\nnhc->idmask[0] = LOWPAN_GHC_EXT_FRAG_MASK_0;\r\n}
