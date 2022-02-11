void
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 -> V_2 . V_9 . V_10 . V_11 -> V_7 ;
F_2 ( V_7 -> V_12 , V_3 ) ;
}
static int
F_3 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 -> V_2 . V_9 . V_10 . V_11 -> V_7 ;
T_1 V_15 = 0x80000000 | V_5 -> V_2 . V_16 << 24 ;
T_1 V_17 = V_14 -> V_17 ;
int V_18 ;
switch ( V_14 -> V_9 -> V_10 . V_19 ) {
case V_20 :
case V_21 : V_15 |= 0x00000000 ; break;
case V_22 : V_15 |= 0x00010000 ; break;
case V_23 : V_15 |= 0x00020000 ; break;
default:
F_4 ( 1 ) ;
return - V_24 ;
}
F_5 ( & V_5 -> V_8 -> V_2 . V_9 . V_10 . V_25 ) ;
V_18 = F_6 ( V_7 -> V_12 , V_14 , V_5 -> V_2 . V_16 , 4 ,
V_17 , V_15 ) ;
F_7 ( & V_5 -> V_8 -> V_2 . V_9 . V_10 . V_25 ) ;
return V_18 ;
}
void
F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_26 * V_8 = V_5 -> V_8 ;
struct V_27 * V_11 = V_8 -> V_2 . V_9 . V_10 . V_11 ;
struct V_28 * V_29 = V_11 -> V_7 -> V_30 ;
const struct V_31 * V_32 ;
unsigned long V_33 ;
T_1 V_34 = V_8 -> V_2 . V_35 - 1 ;
T_1 V_36 = V_5 -> V_30 ;
T_1 V_16 ;
F_9 ( & V_8 -> V_2 . V_37 , V_33 ) ;
F_10 ( V_11 , V_38 , 0 ) ;
V_16 = F_11 ( V_11 , V_39 ) & V_34 ;
if ( V_16 == V_5 -> V_2 . V_16 ) {
F_12 ( V_11 , V_40 , 0x00000001 , 0 ) ;
F_10 ( V_11 , V_41 , 0 ) ;
F_12 ( V_11 , V_42 , 0x00000001 , 0 ) ;
V_32 = V_8 -> V_30 ;
do {
T_1 V_43 = ( ( 1ULL << V_32 -> V_44 ) - 1 ) << V_32 -> V_45 ;
T_1 V_46 = ( ( 1ULL << V_32 -> V_44 ) - 1 ) << V_32 -> V_47 ;
T_1 V_48 = ( F_11 ( V_11 , V_32 -> V_49 ) & V_43 ) >> V_32 -> V_45 ;
T_1 V_50 = ( F_13 ( V_29 , V_32 -> V_51 + V_36 ) & ~ V_46 ) ;
F_14 ( V_29 , V_32 -> V_51 + V_36 , V_50 | ( V_48 << V_32 -> V_47 ) ) ;
} while ( ( ++ V_32 ) -> V_44 );
V_32 = V_8 -> V_30 ;
do {
F_10 ( V_11 , V_32 -> V_49 , 0x00000000 ) ;
} while ( ( ++ V_32 ) -> V_44 );
F_10 ( V_11 , V_52 , 0 ) ;
F_10 ( V_11 , V_53 , 0 ) ;
F_10 ( V_11 , V_39 , V_34 ) ;
F_10 ( V_11 , V_41 , 1 ) ;
F_10 ( V_11 , V_42 , 1 ) ;
}
F_12 ( V_11 , V_54 , 1 << V_5 -> V_2 . V_16 , 0 ) ;
F_10 ( V_11 , V_38 , 1 ) ;
F_15 ( & V_8 -> V_2 . V_37 , V_33 ) ;
}
void
F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_26 * V_8 = V_5 -> V_8 ;
struct V_27 * V_11 = V_8 -> V_2 . V_9 . V_10 . V_11 ;
T_1 V_34 = 1 << V_5 -> V_2 . V_16 ;
unsigned long V_33 ;
F_9 ( & V_8 -> V_2 . V_37 , V_33 ) ;
F_12 ( V_11 , V_54 , V_34 , V_34 ) ;
F_15 ( & V_8 -> V_2 . V_37 , V_33 ) ;
}
void *
F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_26 * V_8 = V_5 -> V_8 ;
struct V_6 * V_7 = V_8 -> V_2 . V_9 . V_10 . V_11 -> V_7 ;
const struct V_31 * V_32 = V_8 -> V_30 ;
F_18 ( V_7 -> V_30 ) ;
do {
F_14 ( V_7 -> V_30 , V_5 -> V_30 + V_32 -> V_51 , 0x00000000 ) ;
} while ( ( ++ V_32 ) -> V_44 );
F_19 ( V_7 -> V_30 ) ;
return V_5 ;
}
static int
F_20 ( struct V_55 * V_2 , const struct V_56 * V_57 ,
void * V_36 , T_1 V_58 , struct V_13 * * V_59 )
{
struct V_13 * V_60 = V_57 -> V_60 ;
union {
struct V_61 V_62 ;
} * args = V_36 ;
struct V_26 * V_8 = V_26 ( V_2 ) ;
struct V_4 * V_5 = NULL ;
struct V_27 * V_11 = V_8 -> V_2 . V_9 . V_10 . V_11 ;
struct V_6 * V_7 = V_11 -> V_7 ;
int V_63 ;
F_21 ( V_60 , L_1 , V_58 ) ;
if ( F_22 ( args -> V_62 , 0 , 0 , false ) ) {
F_21 ( V_60 , L_2
L_3 , args -> V_62 . V_64 ,
args -> V_62 . V_65 , args -> V_62 . V_66 ) ;
if ( ! args -> V_62 . V_65 )
return - V_24 ;
} else
return V_63 ;
if ( ! ( V_5 = F_23 ( sizeof( * V_5 ) , V_67 ) ) )
return - V_68 ;
* V_59 = & V_5 -> V_2 . V_14 ;
V_63 = F_24 ( & V_69 , & V_8 -> V_2 ,
0x1000 , 0x1000 , false , 0 , args -> V_62 . V_65 ,
( 1ULL << V_20 ) |
( 1ULL << V_22 ) |
( 1ULL << V_21 ) ,
0 , 0x800000 , 0x10000 , V_57 , & V_5 -> V_2 ) ;
V_5 -> V_8 = V_8 ;
if ( V_63 )
return V_63 ;
args -> V_62 . V_16 = V_5 -> V_2 . V_16 ;
V_5 -> V_30 = V_5 -> V_2 . V_16 * 32 ;
F_18 ( V_7 -> V_30 ) ;
F_14 ( V_7 -> V_30 , V_5 -> V_30 + 0x00 , args -> V_62 . V_66 ) ;
F_14 ( V_7 -> V_30 , V_5 -> V_30 + 0x04 , args -> V_62 . V_66 ) ;
F_14 ( V_7 -> V_30 , V_5 -> V_30 + 0x08 , V_5 -> V_2 . V_70 -> V_71 >> 4 ) ;
F_14 ( V_7 -> V_30 , V_5 -> V_30 + 0x10 ,
V_72 |
V_73 |
#ifdef F_25
V_74 |
#endif
V_75 ) ;
F_19 ( V_7 -> V_30 ) ;
return 0 ;
}
