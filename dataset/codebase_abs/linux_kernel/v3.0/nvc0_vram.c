bool
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 = ( V_3 & V_5 ) >> 8 ;
return F_2 ( ( V_6 [ V_4 ] == 1 ) ) ;
}
int
F_3 ( struct V_1 * V_2 , T_3 V_7 , T_1 V_8 , T_1 V_9 ,
T_1 type , struct V_10 * * V_11 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_15 * V_16 = & V_13 -> V_17 . V_16 ;
struct V_18 * V_19 = & V_16 -> V_19 [ V_20 ] ;
struct V_21 * V_22 = V_19 -> V_23 ;
struct V_24 * V_25 ;
struct V_10 * V_26 ;
int V_27 ;
V_7 >>= 12 ;
V_8 >>= 12 ;
V_9 >>= 12 ;
V_26 = F_4 ( sizeof( * V_26 ) , V_28 ) ;
if ( ! V_26 )
return - V_29 ;
F_5 ( & V_26 -> V_30 ) ;
V_26 -> V_2 = V_13 -> V_2 ;
V_26 -> V_4 = ( type & 0xff ) ;
V_26 -> V_7 = V_7 ;
F_6 ( & V_22 -> V_31 ) ;
do {
V_27 = F_7 ( V_22 , 1 , V_7 , V_9 , V_8 , & V_25 ) ;
if ( V_27 ) {
F_8 ( & V_22 -> V_31 ) ;
F_9 ( V_2 , & V_26 ) ;
return V_27 ;
}
F_10 ( & V_25 -> V_32 , & V_26 -> V_30 ) ;
V_7 -= V_25 -> V_33 ;
} while ( V_7 );
F_8 ( & V_22 -> V_31 ) ;
V_25 = F_11 ( & V_26 -> V_30 , struct V_24 , V_32 ) ;
V_26 -> V_34 = ( T_3 ) V_25 -> V_34 << 12 ;
* V_11 = V_26 ;
return 0 ;
}
int
F_12 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
V_13 -> V_35 = F_13 ( V_2 , 0x10f20c ) << 20 ;
V_13 -> V_35 *= F_13 ( V_2 , 0x121c74 ) ;
V_13 -> V_36 = 4096 ;
return 0 ;
}
