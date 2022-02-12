static void udp_ghid_setup(struct lowpan_nhc *nhc)\r\n{\r\nnhc->id[0] = LOWPAN_GHC_UDP_ID_0;\r\nnhc->idmask[0] = LOWPAN_GHC_UDP_MASK_0;\r\n}
