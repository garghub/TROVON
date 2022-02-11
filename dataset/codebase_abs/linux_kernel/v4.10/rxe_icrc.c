T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_5 = 0 ;
struct V_6 * V_7 = NULL ;
struct V_8 * V_9 = NULL ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
int V_14 ;
int V_15 ;
int V_16 = sizeof( struct V_10 ) +
( V_4 -> V_17 == F_2 ( V_18 ) ?
sizeof( struct V_6 ) : sizeof( struct V_8 ) ) ;
T_2 V_19 [ sizeof( struct V_10 ) +
sizeof( struct V_8 ) +
V_20 ] ;
V_14 = 0xdebb20e3 ;
if ( V_4 -> V_17 == F_2 ( V_18 ) ) {
memcpy ( V_19 , F_3 ( V_4 ) , V_16 ) ;
V_7 = (struct V_6 * ) V_19 ;
V_11 = (struct V_10 * ) ( V_7 + 1 ) ;
V_7 -> V_21 = 0xff ;
V_7 -> V_22 = V_23 ;
V_7 -> V_24 = 0xff ;
} else {
memcpy ( V_19 , F_4 ( V_4 ) , V_16 ) ;
V_9 = (struct V_8 * ) V_19 ;
V_11 = (struct V_10 * ) ( V_9 + 1 ) ;
memset ( V_9 -> V_25 , 0xff , sizeof( V_9 -> V_25 ) ) ;
V_9 -> V_26 = 0xf ;
V_9 -> V_27 = 0xff ;
}
V_11 -> V_22 = V_23 ;
V_5 += V_16 ;
memcpy ( & V_19 [ V_5 ] , V_2 -> V_28 , V_20 ) ;
V_13 = (struct V_12 * ) & V_19 [ V_5 ] ;
V_13 -> V_29 |= F_5 ( ~ V_30 ) ;
V_15 = V_16 + V_20 ;
V_14 = F_6 ( V_14 , V_19 , V_15 ) ;
V_14 = F_6 ( V_14 , V_2 -> V_28 + V_20 ,
V_31 [ V_2 -> V_32 ] . V_15 - V_20 ) ;
return V_14 ;
}
