static void route_ghid_setup(struct lowpan_nhc *nhc)\r\n{\r\nnhc->id[0] = LOWPAN_GHC_EXT_ROUTE_ID_0;\r\nnhc->idmask[0] = LOWPAN_GHC_EXT_ROUTE_MASK_0;\r\n}
