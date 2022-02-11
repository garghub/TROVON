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
if ( V_9 -> V_13 == V_15 )
return - V_16 ;
V_9 -> V_1 . V_2 = F_8 ( V_11 -> V_12 . V_14 , 0 ) ;
if ( ! V_9 -> V_17 . V_18 )
return - V_16 ;
return 0 ;
}
static int F_9 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
if ( F_5 ( V_9 ) != 0 )
return - V_16 ;
V_9 -> V_1 . V_20 = 0 ;
V_9 -> V_1 . V_21 = 0 ;
V_9 -> V_22 = V_23 ;
V_9 -> V_24 = V_25 ;
V_9 -> V_26 = V_27 ;
V_9 -> V_28 = V_29 ;
V_9 -> V_30 = V_31 ;
return 0 ;
}
static int F_11 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
const struct V_32 * V_33 = V_9 -> V_33 ;
V_9 -> V_34 = ( void V_35 T_1 * ) F_12 ( V_9 -> V_12 ,
( V_33 -> V_36 + V_33 -> V_37 ) *
sizeof( V_38 ) , & V_9 -> V_39 ,
V_40 ) ;
if ( V_9 -> V_34 == NULL )
return - V_41 ;
return 0 ;
}
static void F_13 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
const struct V_32 * V_33 = V_9 -> V_33 ;
if( V_9 -> V_34 )
F_14 ( V_9 -> V_12 , ( V_33 -> V_36 + V_33 -> V_37 )
* sizeof( V_38 ) ,
( void V_35 * ) V_9 -> V_34 ,
V_9 -> V_39 ) ;
}
static void F_15 ( struct V_19 * V_12 )
{
}
static void F_16 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_17 ( V_2 , V_42 , V_43 ) ;
}
static void F_18 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
V_9 -> V_1 . V_20 = 0 ;
V_9 -> V_1 . V_21 = 0 ;
}
static void F_19 ( struct V_19 * V_12 , const T_2 * V_44 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
int V_45 , V_46 , V_3 , V_47 ;
T_3 V_48 , V_49 ;
T_2 V_50 , V_51 ;
V_48 = 0xffffffff ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ ) {
V_50 = V_44 [ V_3 ] ;
for ( V_47 = 0 ; V_47 < 8 ; V_47 ++ ) {
V_51 = V_48 >> 31 ;
V_48 <<= 1 ;
if ( V_51 ^ ( V_50 & 0x1 ) )
V_48 ^= V_52 ;
V_50 >>= 1 ;
}
}
V_45 = ( V_48 & 0x3f ) >> 1 ;
V_46 = ( ( V_45 & 0x01 ) << 4 ) |
( ( V_45 & 0x02 ) << 2 ) |
( ( V_45 & 0x04 ) ) |
( ( V_45 & 0x08 ) >> 2 ) |
( ( V_45 & 0x10 ) >> 4 ) ;
V_49 = 1 << V_46 ;
if ( V_48 & 1 )
V_9 -> V_1 . V_20 |= V_49 ;
else
V_9 -> V_1 . V_21 |= V_49 ;
}
static void F_20 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
if ( ( V_12 -> V_53 & V_54 ) != 0 ||
F_21 ( V_12 ) > V_55 ) {
V_9 -> V_1 . V_20 = 0xffffffffU ;
V_9 -> V_1 . V_21 = 0xffffffffU ;
}
F_22 ( V_2 , V_42 , V_43 ) ;
F_2 ( V_2 , V_56 , V_9 -> V_1 . V_20 ) ;
F_2 ( V_2 , V_57 , V_9 -> V_1 . V_21 ) ;
}
static void F_23 ( struct V_19 * V_12 )
{
struct V_58 * V_59 ;
if ( ( V_12 -> V_53 & V_60 ) == 0 ) {
F_18 ( V_12 ) ;
F_24 (ha, dev)
F_19 ( V_12 , V_59 -> V_61 ) ;
F_20 ( V_12 ) ;
} else
F_16 ( V_12 ) ;
}
static void F_25 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
const struct V_32 * V_33 = V_9 -> V_33 ;
T_4 V_62 , V_63 ;
int V_64 ;
T_3 V_65 , V_66 ;
struct V_67 * V_68 = V_9 -> V_69 -> V_70 ;
struct V_71 * V_72 = V_68 -> V_73 ;
V_64 = F_1 ( V_9 -> V_1 . V_2 ) ;
if ( V_64 != 0 )
F_26 ( V_9 -> V_12 , L_1 ) ;
V_65 = ( ( T_3 ) V_12 -> V_74 [ 0 ] << 24 ) |
( ( T_3 ) V_12 -> V_74 [ 1 ] << 16 ) |
( ( T_3 ) V_12 -> V_74 [ 2 ] << 8 ) |
( T_3 ) V_12 -> V_74 [ 3 ] ;
V_66 = ( ( T_3 ) V_12 -> V_74 [ 4 ] << 24 ) |
( ( T_3 ) V_12 -> V_74 [ 5 ] << 16 ) ;
F_2 ( V_2 , V_75 , V_65 ) ;
F_2 ( V_2 , V_76 , V_66 ) ;
F_2 ( V_2 , V_56 , V_9 -> V_1 . V_20 ) ;
F_2 ( V_2 , V_57 , V_9 -> V_1 . V_21 ) ;
F_2 ( V_2 , V_77 , V_78 ) ;
#ifdef F_27
F_2 ( V_2 , V_42 , V_79 << 16 ) ;
#else
F_2 ( V_2 , V_80 , V_79 ) ;
#endif
V_62 = V_9 -> V_39 ;
V_63 = V_62 + sizeof( V_38 ) * V_33 -> V_37 ;
F_2 ( V_2 , V_81 , V_62 ) ;
F_2 ( V_2 , V_82 , V_63 ) ;
F_28 ( V_12 ) ;
#ifdef F_27
F_17 ( V_2 , V_83 , 0xC0000000 ) ;
#else
F_2 ( V_2 , V_84 , 0x78000000 ) ;
#endif
F_2 ( V_2 , V_85 , V_72 -> V_85 ) ;
F_2 ( V_2 , V_86 , 0xffc0 ) ;
#ifndef F_27
F_2 ( V_2 , V_87 , ( F_29 ( V_9 -> V_13 ) / 2 ) << 29 ) ;
F_2 ( V_2 , V_42 , V_88 ) ;
#else
F_17 ( V_2 , V_42 , V_33 -> V_89 ?
V_90 : V_88 ) ;
#endif
if ( V_9 -> V_69 -> V_91 ) {
F_22 ( V_2 , V_42 , V_92 ) ;
F_17 ( V_2 , V_93 , V_94 ) ;
} else {
F_17 ( V_2 , V_42 , V_92 ) ;
F_22 ( V_2 , V_93 , V_94 ) ;
}
F_23 ( V_12 ) ;
F_2 ( V_2 , V_95 , V_96 | V_97 |
V_98 | V_99 ) ;
F_2 ( V_2 , V_4 , V_5 | V_100 ) ;
F_2 ( V_2 , V_101 , 0x01000000 ) ;
}
static void F_30 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
const struct V_32 * V_33 = V_9 -> V_33 ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
struct V_71 * V_102 = V_9 -> V_69 -> V_70 -> V_73 ;
int V_3 ;
if ( ( F_3 ( V_2 , V_4 ) & V_100 ) == 0 )
return;
F_2 ( V_2 , V_93 , 0x01 ) ;
for ( V_3 = 0 ; ( ( F_3 ( V_2 , V_86 ) & 0x10000000 ) == 0 ) &&
V_3 < V_7 ; V_3 ++ )
F_4 ( 1 ) ;
if ( V_3 == V_7 )
F_31 ( V_9 -> V_12 , L_2 ) ;
F_2 ( V_2 , V_95 , 0 ) ;
F_22 ( V_2 , V_4 , V_100 ) ;
F_32 ( V_12 ) ;
if ( V_33 -> V_103 ) {
F_17 ( V_2 , V_42 , V_33 -> V_89 ?
V_90 :
V_88 ) ;
F_17 ( V_2 , V_4 , V_5 | V_100 ) ;
F_2 ( V_2 , V_86 , V_104 ) ;
F_2 ( V_2 , V_85 , V_102 -> V_85 ) ;
}
}
static void F_33 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_2 ( V_2 , V_86 , V_23 ) ;
}
static void F_34 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_17 ( V_2 , V_95 , V_23 ) ;
}
static void F_35 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_22 ( V_2 , V_95 , V_23 ) ;
}
static void F_36 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_2 ( V_2 , V_86 , V_25 ) ;
}
static void F_37 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_17 ( V_2 , V_95 , V_25 ) ;
}
static void F_38 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_22 ( V_2 , V_95 , V_25 ) ;
}
static void F_39 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_2 ( V_2 , V_101 , 0x01000000 ) ;
}
static void F_40 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_2 ( V_2 , V_105 , 0x01000000 ) ;
}
static T_3 F_41 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
return F_3 ( V_2 , V_86 ) & F_3 ( V_2 , V_95 ) ;
}
static void F_42 ( struct V_19 * V_12 , T_3 V_106 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_2 ( V_2 , V_86 , V_106 ) ;
}
static void F_43 ( struct V_19 * V_12 , T_3 V_106 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
F_31 ( V_9 -> V_12 , L_3 , V_106 ) ;
}
static int F_44 ( struct V_19 * V_12 , void * V_107 , int * V_108 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
if ( * V_108 < sizeof( struct V_1 ) )
return - V_16 ;
F_45 ( V_107 , V_9 -> V_1 . V_2 , sizeof( struct V_1 ) ) ;
return 0 ;
}
static int F_46 ( struct V_19 * V_12 )
{
return sizeof( struct V_1 ) ;
}
static void F_47 ( struct V_19 * V_12 )
{
}
