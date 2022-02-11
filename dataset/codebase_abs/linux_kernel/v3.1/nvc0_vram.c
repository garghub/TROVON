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
struct V_15 * V_16 = V_13 -> V_17 . V_18 . V_16 ;
struct V_19 * V_20 ;
struct V_10 * V_21 ;
int V_22 ;
V_7 >>= 12 ;
V_8 >>= 12 ;
V_9 >>= 12 ;
V_21 = F_4 ( sizeof( * V_21 ) , V_23 ) ;
if ( ! V_21 )
return - V_24 ;
F_5 ( & V_21 -> V_25 ) ;
V_21 -> V_2 = V_13 -> V_2 ;
V_21 -> V_4 = ( type & 0xff ) ;
V_21 -> V_7 = V_7 ;
F_6 ( & V_16 -> V_26 ) ;
do {
V_22 = F_7 ( V_16 , 1 , V_7 , V_9 , V_8 , & V_20 ) ;
if ( V_22 ) {
F_8 ( & V_16 -> V_26 ) ;
F_9 ( V_2 , & V_21 ) ;
return V_22 ;
}
F_10 ( & V_20 -> V_27 , & V_21 -> V_25 ) ;
V_7 -= V_20 -> V_28 ;
} while ( V_7 );
F_8 ( & V_16 -> V_26 ) ;
V_20 = F_11 ( & V_21 -> V_25 , struct V_19 , V_27 ) ;
V_21 -> V_29 = ( T_3 ) V_20 -> V_29 << 12 ;
* V_11 = V_21 ;
return 0 ;
}
int
F_12 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_30 * V_18 = & V_13 -> V_17 . V_18 ;
const T_1 V_31 = ( 256 * 1024 ) >> 12 ;
const T_1 V_32 = ( 1024 * 1024 ) >> 12 ;
T_1 V_28 ;
V_13 -> V_33 = F_13 ( V_2 , 0x10f20c ) << 20 ;
V_13 -> V_33 *= F_13 ( V_2 , 0x121c74 ) ;
V_28 = ( V_13 -> V_33 >> 12 ) - V_31 - V_32 ;
return F_14 ( & V_18 -> V_16 , V_31 , V_28 , 1 ) ;
}
