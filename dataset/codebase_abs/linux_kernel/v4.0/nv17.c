static int
F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
union {
struct V_9 V_10 ;
} * args = V_6 ;
struct V_11 * V_12 = ( void * ) V_3 ;
struct V_13 * V_14 ;
int V_15 ;
F_2 ( V_2 , L_1 , V_7 ) ;
if ( F_3 ( args -> V_10 , 0 , 0 , false ) ) {
F_2 ( V_2 , L_2
L_3 , args -> V_10 . V_16 ,
args -> V_10 . V_17 , args -> V_10 . V_18 ) ;
} else
return V_15 ;
V_15 = F_4 ( V_2 , V_3 , V_5 , 0 , 0x800000 ,
0x10000 , args -> V_10 . V_17 ,
( 1ULL << V_19 ) |
( 1ULL << V_20 ) |
( 1ULL << V_21 ) |
( 1ULL << V_22 ) ,
& V_14 ) ;
* V_8 = F_5 ( V_14 ) ;
if ( V_15 )
return V_15 ;
args -> V_10 . V_23 = V_14 -> V_24 . V_23 ;
F_6 ( V_14 ) -> V_25 = V_26 ;
F_6 ( V_14 ) -> V_27 = V_28 ;
F_6 ( V_14 ) -> V_29 = V_30 ;
V_14 -> V_31 = V_14 -> V_24 . V_23 * 64 ;
F_7 ( V_12 -> V_31 , V_14 -> V_31 + 0x00 , args -> V_10 . V_18 ) ;
F_7 ( V_12 -> V_31 , V_14 -> V_31 + 0x04 , args -> V_10 . V_18 ) ;
F_7 ( V_12 -> V_31 , V_14 -> V_31 + 0x0c , V_14 -> V_24 . V_32 -> V_33 >> 4 ) ;
F_7 ( V_12 -> V_31 , V_14 -> V_31 + 0x14 ,
V_34 |
V_35 |
#ifdef F_8
V_36 |
#endif
V_37 ) ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_38 * V_39 = F_10 ( V_2 ) ;
struct V_11 * V_12 ;
int V_15 ;
V_15 = F_11 ( V_2 , V_3 , V_5 , 0 , 31 , & V_12 ) ;
* V_8 = F_5 ( V_12 ) ;
if ( V_15 )
return V_15 ;
F_12 ( V_39 -> V_40 , & V_12 -> V_40 ) ;
F_13 ( V_39 -> V_41 , & V_12 -> V_41 ) ;
F_13 ( V_39 -> V_31 , & V_12 -> V_31 ) ;
F_14 ( V_12 ) -> V_42 = 0x00000100 ;
F_14 ( V_12 ) -> V_43 = V_44 ;
F_15 ( V_12 ) -> V_45 = & V_46 ;
F_15 ( V_12 ) -> V_47 = V_48 ;
V_12 -> V_24 . V_49 = V_50 ;
V_12 -> V_24 . V_51 = V_52 ;
V_12 -> V_53 = V_54 ;
return 0 ;
}
static int
F_16 ( struct V_1 * V_55 )
{
struct V_11 * V_12 = ( void * ) V_55 ;
int V_15 ;
V_15 = F_17 ( & V_12 -> V_24 ) ;
if ( V_15 )
return V_15 ;
F_18 ( V_12 , V_56 , 0x000000ff ) ;
F_18 ( V_12 , V_57 , 0x0101ffff ) ;
F_18 ( V_12 , V_58 , ( 0x03 << 24 ) |
( ( V_12 -> V_40 -> V_59 - 9 ) << 16 ) |
( V_12 -> V_40 -> V_60 . V_33 >> 8 ) ) ;
F_18 ( V_12 , V_61 , V_12 -> V_41 -> V_33 >> 8 ) ;
F_18 ( V_12 , V_62 , V_12 -> V_31 -> V_33 >> 8 | 0x00010000 ) ;
F_18 ( V_12 , V_63 , V_12 -> V_24 . V_64 ) ;
F_18 ( V_12 , V_65 , 0xffffffff ) ;
F_18 ( V_12 , V_66 , 0xffffffff ) ;
F_18 ( V_12 , V_67 , 1 ) ;
F_18 ( V_12 , V_68 , 1 ) ;
F_18 ( V_12 , V_69 , 1 ) ;
return 0 ;
}
