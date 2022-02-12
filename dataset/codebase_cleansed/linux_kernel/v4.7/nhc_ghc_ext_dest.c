static void dest_ghid_setup(struct lowpan_nhc *nhc)\r\n{\r\nnhc->id[0] = LOWPAN_GHC_EXT_DEST_ID_0;\r\nnhc->idmask[0] = LOWPAN_GHC_EXT_DEST_MASK_0;\r\n}
