static void icmpv6_ghid_setup(struct lowpan_nhc *nhc)\r\n{\r\nnhc->id[0] = LOWPAN_GHC_ICMPV6_ID_0;\r\nnhc->idmask[0] = LOWPAN_GHC_ICMPV6_MASK_0;\r\n}
