void * F_1 ( void * V_1 ,
const void * V_2 ,
unsigned int V_3 )
{
static T_1 V_4 , V_5 ;
F_2 ( F_3 ( V_6 L_1 , V_3 ) ) ;
#if 0
*R_GEN_CONFIG = genconfig_shadow =
(genconfig_shadow & ~0x3c0000) |
IO_STATE(R_GEN_CONFIG, dma6, intdma7) |
IO_STATE(R_GEN_CONFIG, dma7, intdma6);
#endif
V_4 . V_7 = V_5 . V_7 = V_3 ;
V_4 . V_8 = V_9 | V_10 ;
V_5 . V_8 = V_9 ;
V_4 . V_11 = V_2 ;
V_5 . V_11 = V_1 ;
* V_12 = & V_4 ;
* V_13 = & V_5 ;
* V_14 = F_4 ( V_14 , V_15 , V_16 ) ;
* V_17 = F_4 ( V_17 , V_15 , V_16 ) ;
while ( * V_17 == 1 )
;
F_2 ( F_3 ( V_6 L_2 ) ) ;
}
