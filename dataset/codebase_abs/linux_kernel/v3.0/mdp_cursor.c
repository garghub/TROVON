int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
struct V_8 * V_9 = & V_4 -> V_10 ;
int V_11 , V_12 ;
int V_13 ;
int V_14 = 0 ;
if ( ( V_9 -> V_15 > V_16 ) ||
( V_9 -> V_17 > V_18 ) ||
( V_9 -> V_19 != 32 ) )
return - V_20 ;
if ( V_4 -> V_21 & V_22 )
F_2 ( V_23 + 0x9004c , ( V_9 -> V_24 << 16 ) | V_9 -> V_25 ) ;
if ( V_4 -> V_21 & V_26 ) {
V_14 = F_3 ( V_6 -> V_27 , V_9 -> V_28 ,
V_9 -> V_15 * V_9 -> V_17 * 4 ) ;
if ( V_14 )
return V_14 ;
if ( V_9 -> V_29 == 0xffffffff )
V_12 = 0 ;
else
V_12 = 1 ;
V_13 = ( V_9 -> V_30 & 0xff000000 ) >> 24 ;
if ( V_13 )
V_11 = 0x2 ;
else
V_11 = 0x1 ;
F_2 ( V_23 + 0x90044 , ( V_9 -> V_17 << 16 ) | V_9 -> V_15 ) ;
F_2 ( V_23 + 0x90048 , V_6 -> V_31 ) ;
F_2 ( V_23 + 0x90060 ,
( V_12 << 3 ) | ( V_11 << 1 ) |
( F_4 ( V_23 + 0x90060 ) & 0x1 ) ) ;
#ifdef F_5
F_2 ( V_23 + 0x90064 , ( V_13 << 24 ) ) ;
F_2 ( V_23 + 0x90068 , ( 0xffffff & V_9 -> V_29 ) ) ;
F_2 ( V_23 + 0x9006C , ( 0xffffff & V_9 -> V_29 ) ) ;
#else
F_2 ( V_23 + 0x90064 ,
( V_13 << 24 ) | ( 0xffffff & V_9 -> V_29 ) ) ;
F_2 ( V_23 + 0x90068 , 0 ) ;
#endif
}
if ( ( V_4 -> V_32 ) && ( ! V_33 ) ) {
V_33 = 1 ;
F_2 ( V_23 + 0x90060 , F_4 ( V_23 + 0x90060 ) | 0x1 ) ;
} else if ( ( ! V_4 -> V_32 ) && ( V_33 ) ) {
V_33 = 0 ;
F_2 ( V_23 + 0x90060 ,
F_4 ( V_23 + 0x90060 ) & ( ~ 0x1 ) ) ;
}
return 0 ;
}
