static int
F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_9 * V_10 = ( void * ) V_3 ;
struct V_11 * V_12 ;
struct V_13 * args = V_6 ;
int V_14 ;
if ( V_7 < sizeof( * args ) )
return - V_15 ;
V_14 = F_2 ( V_2 , V_3 , V_5 , 0 , 0x800000 ,
0x10000 , args -> V_16 ,
( 1 << V_17 ) |
( 1 << V_18 ) |
( 1 << V_19 ) |
( 1 << V_20 ) ,
& V_12 ) ;
* V_8 = F_3 ( V_12 ) ;
if ( V_14 )
return V_14 ;
F_4 ( V_12 ) -> V_21 = V_22 ;
F_4 ( V_12 ) -> V_23 = V_24 ;
F_4 ( V_12 ) -> V_25 = V_26 ;
V_12 -> V_27 = V_12 -> V_28 . V_29 * 64 ;
F_5 ( V_10 -> V_27 , V_12 -> V_27 + 0x00 , args -> V_30 ) ;
F_5 ( V_10 -> V_27 , V_12 -> V_27 + 0x04 , args -> V_30 ) ;
F_5 ( V_10 -> V_27 , V_12 -> V_27 + 0x0c , V_12 -> V_28 . V_31 -> V_32 >> 4 ) ;
F_5 ( V_10 -> V_27 , V_12 -> V_27 + 0x14 ,
V_33 |
V_34 |
#ifdef F_6
V_35 |
#endif
V_36 ) ;
return 0 ;
}
static int
F_7 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_37 * V_38 = F_8 ( V_2 ) ;
struct V_9 * V_10 ;
int V_14 ;
V_14 = F_9 ( V_2 , V_3 , V_5 , 0 , 31 , & V_10 ) ;
* V_8 = F_3 ( V_10 ) ;
if ( V_14 )
return V_14 ;
F_10 ( V_38 -> V_39 , & V_10 -> V_39 ) ;
F_11 ( V_38 -> V_40 , & V_10 -> V_40 ) ;
F_11 ( V_38 -> V_27 , & V_10 -> V_27 ) ;
F_12 ( V_10 ) -> V_41 = 0x00000100 ;
F_12 ( V_10 ) -> V_42 = V_43 ;
F_13 ( V_10 ) -> V_44 = & V_45 ;
F_13 ( V_10 ) -> V_46 = V_47 ;
V_10 -> V_28 . V_48 = V_49 ;
V_10 -> V_28 . V_50 = V_51 ;
V_10 -> V_52 = V_53 ;
return 0 ;
}
static int
F_14 ( struct V_1 * V_54 )
{
struct V_9 * V_10 = ( void * ) V_54 ;
int V_14 ;
V_14 = F_15 ( & V_10 -> V_28 ) ;
if ( V_14 )
return V_14 ;
F_16 ( V_10 , V_55 , 0x000000ff ) ;
F_16 ( V_10 , V_56 , 0x0101ffff ) ;
F_16 ( V_10 , V_57 , ( 0x03 << 24 ) |
( ( V_10 -> V_39 -> V_58 - 9 ) << 16 ) |
( V_10 -> V_39 -> V_28 . V_32 >> 8 ) ) ;
F_16 ( V_10 , V_59 , V_10 -> V_40 -> V_32 >> 8 ) ;
F_16 ( V_10 , V_60 , V_10 -> V_27 -> V_32 >> 8 | 0x00010000 ) ;
F_16 ( V_10 , V_61 , V_10 -> V_28 . V_62 ) ;
F_16 ( V_10 , V_63 , 0xffffffff ) ;
F_16 ( V_10 , V_64 , 0xffffffff ) ;
F_16 ( V_10 , V_65 , 1 ) ;
F_16 ( V_10 , V_66 , 1 ) ;
F_16 ( V_10 , V_67 , 1 ) ;
return 0 ;
}
