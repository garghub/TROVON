static int F_1 ( struct V_1 T_1 * V_2 )
{
int V_3 ;
F_2 ( V_2 , V_4 , V_5 | V_6 ) ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
if ( ( F_3 ( V_2 , V_4 ) & V_6 ) == 0 )
return 0 ;
F_4 ( 1 ) ;
}
return - 1 ;
}
static int F_5 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_6 ( V_9 -> V_12 ) ;
V_9 -> V_13 = F_7 ( V_11 -> V_12 . V_14 , 0 ) ;
if ( ! V_9 -> V_13 )
return - V_15 ;
V_9 -> V_1 . V_2 = F_8 ( V_11 -> V_12 . V_14 , 0 ) ;
if ( ! V_9 -> V_16 . V_17 )
return - V_15 ;
return 0 ;
}
static int F_9 ( struct V_18 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
if ( F_5 ( V_9 ) != 0 )
return - V_15 ;
V_9 -> V_1 . V_19 = 0 ;
V_9 -> V_1 . V_20 = 0 ;
V_9 -> V_21 = V_22 ;
V_9 -> V_23 = V_24 ;
V_9 -> V_25 = V_26 ;
return 0 ;
}
static int F_11 ( struct V_18 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
const struct V_27 * V_28 = V_9 -> V_28 ;
V_9 -> V_29 = ( void V_30 T_1 * ) F_12 ( V_9 -> V_12 ,
( V_28 -> V_31 + V_28 -> V_32 ) *
sizeof( V_33 ) , & V_9 -> V_34 ,
V_35 ) ;
if ( V_9 -> V_29 == NULL )
return - V_36 ;
return 0 ;
}
static void F_13 ( struct V_18 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
const struct V_27 * V_28 = V_9 -> V_28 ;
if( V_9 -> V_29 )
F_14 ( V_9 -> V_12 , ( V_28 -> V_31 + V_28 -> V_32 )
* sizeof( V_33 ) ,
( void V_30 * ) V_9 -> V_29 ,
V_9 -> V_34 ) ;
}
static void F_15 ( struct V_18 * V_12 )
{
}
static void F_16 ( struct V_18 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_17 ( V_2 , V_37 , V_38 ) ;
}
static void F_18 ( struct V_18 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
V_9 -> V_1 . V_19 = 0 ;
V_9 -> V_1 . V_20 = 0 ;
}
static void F_19 ( struct V_18 * V_12 , const T_2 * V_39 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
int V_40 , V_41 , V_3 , V_42 ;
T_3 V_43 , V_44 ;
T_2 V_45 , V_46 ;
V_43 = 0xffffffff ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ ) {
V_45 = V_39 [ V_3 ] ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
V_46 = V_43 >> 31 ;
V_43 <<= 1 ;
if ( V_46 ^ ( V_45 & 0x1 ) )
V_43 ^= V_47 ;
V_45 >>= 1 ;
}
}
V_40 = ( V_43 & 0x3f ) >> 1 ;
V_41 = ( ( V_40 & 0x01 ) << 4 ) |
( ( V_40 & 0x02 ) << 2 ) |
( ( V_40 & 0x04 ) ) |
( ( V_40 & 0x08 ) >> 2 ) |
( ( V_40 & 0x10 ) >> 4 ) ;
V_44 = 1 << V_41 ;
if ( V_43 & 1 )
V_9 -> V_1 . V_19 |= V_44 ;
else
V_9 -> V_1 . V_20 |= V_44 ;
}
static void F_20 ( struct V_18 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
if ( ( V_12 -> V_48 & V_49 ) != 0 ||
F_21 ( V_12 ) > V_50 ) {
V_9 -> V_1 . V_19 = 0xffffffffU ;
V_9 -> V_1 . V_20 = 0xffffffffU ;
}
F_22 ( V_2 , V_37 , V_38 ) ;
F_2 ( V_2 , V_51 , V_9 -> V_1 . V_19 ) ;
F_2 ( V_2 , V_52 , V_9 -> V_1 . V_20 ) ;
}
static void F_23 ( struct V_18 * V_12 )
{
struct V_53 * V_54 ;
if ( ( V_12 -> V_48 & V_55 ) == 0 ) {
F_18 ( V_12 ) ;
F_24 (ha, dev)
F_19 ( V_12 , V_54 -> V_56 ) ;
F_20 ( V_12 ) ;
} else
F_16 ( V_12 ) ;
}
static void F_25 ( struct V_18 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
const struct V_27 * V_28 = V_9 -> V_28 ;
T_4 V_57 , V_58 ;
int V_59 ;
T_3 V_60 , V_61 ;
struct V_62 * V_63 = V_12 -> V_64 -> V_65 . V_66 ;
struct V_67 * V_68 = V_63 -> V_69 ;
V_59 = F_1 ( V_9 -> V_1 . V_2 ) ;
if ( V_59 != 0 )
F_26 ( V_9 -> V_12 , L_1 ) ;
V_60 = ( ( T_3 ) V_12 -> V_70 [ 0 ] << 24 ) |
( ( T_3 ) V_12 -> V_70 [ 1 ] << 16 ) |
( ( T_3 ) V_12 -> V_70 [ 2 ] << 8 ) |
( T_3 ) V_12 -> V_70 [ 3 ] ;
V_61 = ( ( T_3 ) V_12 -> V_70 [ 4 ] << 24 ) |
( ( T_3 ) V_12 -> V_70 [ 5 ] << 16 ) ;
F_2 ( V_2 , V_71 , V_60 ) ;
F_2 ( V_2 , V_72 , V_61 ) ;
F_2 ( V_2 , V_51 , V_9 -> V_1 . V_19 ) ;
F_2 ( V_2 , V_52 , V_9 -> V_1 . V_20 ) ;
F_2 ( V_2 , V_73 , V_74 ) ;
#ifdef F_27
F_2 ( V_2 , V_37 , V_75 << 16 ) ;
#else
F_2 ( V_2 , V_76 , V_75 ) ;
#endif
V_57 = V_9 -> V_34 ;
V_58 = V_57 + sizeof( V_33 ) * V_28 -> V_32 ;
F_2 ( V_2 , V_77 , V_57 ) ;
F_2 ( V_2 , V_78 , V_58 ) ;
F_28 ( V_12 ) ;
#ifdef F_27
F_17 ( V_2 , V_79 , 0xC0000000 ) ;
#else
F_2 ( V_2 , V_80 , 0x78000000 ) ;
#endif
F_2 ( V_2 , V_81 , V_68 -> V_81 ) ;
F_2 ( V_2 , V_82 , 0xffc0 ) ;
#ifndef F_27
F_2 ( V_2 , V_83 , ( F_29 ( V_9 -> V_13 ) / 2 ) << 29 ) ;
F_2 ( V_2 , V_37 , V_84 ) ;
#else
F_17 ( V_2 , V_37 , V_28 -> V_85 ?
V_86 : V_84 ) ;
#endif
if ( V_12 -> V_64 -> V_87 ) {
F_22 ( V_2 , V_37 , V_88 ) ;
F_17 ( V_2 , V_89 , V_90 ) ;
} else {
F_17 ( V_2 , V_37 , V_88 ) ;
F_22 ( V_2 , V_89 , V_90 ) ;
}
F_23 ( V_12 ) ;
F_2 ( V_2 , V_91 , V_92 | V_93 |
V_94 | V_95 ) ;
F_2 ( V_2 , V_4 , V_5 | V_96 ) ;
F_2 ( V_2 , V_97 , 0x01000000 ) ;
}
static void F_30 ( struct V_18 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
const struct V_27 * V_28 = V_9 -> V_28 ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
struct V_67 * V_98 = V_12 -> V_64 -> V_65 . V_66 -> V_69 ;
int V_3 ;
if ( ( F_3 ( V_2 , V_4 ) & V_96 ) == 0 )
return;
F_2 ( V_2 , V_89 , 0x01 ) ;
for ( V_3 = 0 ; ( ( F_3 ( V_2 , V_82 ) & 0x10000000 ) == 0 ) &&
V_3 < V_7 ; V_3 ++ )
F_4 ( 1 ) ;
if ( V_3 == V_7 )
F_31 ( V_9 -> V_12 , L_2 ) ;
F_2 ( V_2 , V_91 , 0 ) ;
F_22 ( V_2 , V_4 , V_96 ) ;
F_32 ( V_12 ) ;
if ( V_28 -> V_99 ) {
F_17 ( V_2 , V_37 , V_28 -> V_85 ?
V_86 :
V_84 ) ;
F_17 ( V_2 , V_4 , V_5 | V_96 ) ;
F_2 ( V_2 , V_82 , V_100 ) ;
F_2 ( V_2 , V_81 , V_98 -> V_81 ) ;
}
}
static void F_33 ( struct V_18 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_2 ( V_2 , V_82 , V_22 ) ;
}
static void F_34 ( struct V_18 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_17 ( V_2 , V_91 , V_22 ) ;
}
static void F_35 ( struct V_18 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_22 ( V_2 , V_91 , V_22 ) ;
}
static void F_36 ( struct V_18 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_2 ( V_2 , V_97 , 0x01000000 ) ;
}
static void F_37 ( struct V_18 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_2 ( V_2 , V_101 , 0x01000000 ) ;
}
static T_3 F_38 ( struct V_18 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
return F_3 ( V_2 , V_82 ) & F_3 ( V_2 , V_91 ) ;
}
static void F_39 ( struct V_18 * V_12 , T_3 V_102 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_2 ( V_2 , V_82 , V_102 ) ;
}
static void F_40 ( struct V_18 * V_12 , T_3 V_102 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
F_31 ( V_9 -> V_12 , L_3 , V_102 ) ;
}
static int F_41 ( struct V_18 * V_12 , void * V_103 , int * V_104 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
if ( * V_104 < sizeof( struct V_1 ) )
return - V_15 ;
F_42 ( V_103 , V_9 -> V_1 . V_2 , sizeof( struct V_1 ) ) ;
return 0 ;
}
static int F_43 ( struct V_18 * V_12 )
{
return sizeof( struct V_1 ) ;
}
static void F_44 ( struct V_18 * V_12 )
{
}
