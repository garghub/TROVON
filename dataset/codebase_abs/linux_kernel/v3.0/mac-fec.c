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
V_9 -> V_13 = F_7 ( V_11 -> V_12 . V_14 , 0 , NULL ) ;
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
return 0 ;
}
static int F_11 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
const struct V_30 * V_31 = V_9 -> V_31 ;
V_9 -> V_32 = ( void V_33 T_1 * ) F_12 ( V_9 -> V_12 ,
( V_31 -> V_34 + V_31 -> V_35 ) *
sizeof( V_36 ) , & V_9 -> V_37 ,
V_38 ) ;
if ( V_9 -> V_32 == NULL )
return - V_39 ;
return 0 ;
}
static void F_13 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
const struct V_30 * V_31 = V_9 -> V_31 ;
if( V_9 -> V_32 )
F_14 ( V_9 -> V_12 , ( V_31 -> V_34 + V_31 -> V_35 )
* sizeof( V_36 ) ,
( void V_33 * ) V_9 -> V_32 ,
V_9 -> V_37 ) ;
}
static void F_15 ( struct V_19 * V_12 )
{
}
static void F_16 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_17 ( V_2 , V_40 , V_41 ) ;
}
static void F_18 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
V_9 -> V_1 . V_20 = 0 ;
V_9 -> V_1 . V_21 = 0 ;
}
static void F_19 ( struct V_19 * V_12 , const T_2 * V_42 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
int V_43 , V_44 , V_3 , V_45 ;
T_3 V_46 , V_47 ;
T_2 V_48 , V_49 ;
V_46 = 0xffffffff ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ ) {
V_48 = V_42 [ V_3 ] ;
for ( V_45 = 0 ; V_45 < 8 ; V_45 ++ ) {
V_49 = V_46 >> 31 ;
V_46 <<= 1 ;
if ( V_49 ^ ( V_48 & 0x1 ) )
V_46 ^= V_50 ;
V_48 >>= 1 ;
}
}
V_43 = ( V_46 & 0x3f ) >> 1 ;
V_44 = ( ( V_43 & 0x01 ) << 4 ) |
( ( V_43 & 0x02 ) << 2 ) |
( ( V_43 & 0x04 ) ) |
( ( V_43 & 0x08 ) >> 2 ) |
( ( V_43 & 0x10 ) >> 4 ) ;
V_47 = 1 << V_44 ;
if ( V_46 & 1 )
V_9 -> V_1 . V_20 |= V_47 ;
else
V_9 -> V_1 . V_21 |= V_47 ;
}
static void F_20 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
if ( ( V_12 -> V_51 & V_52 ) != 0 ||
F_21 ( V_12 ) > V_53 ) {
V_9 -> V_1 . V_20 = 0xffffffffU ;
V_9 -> V_1 . V_21 = 0xffffffffU ;
}
F_22 ( V_2 , V_40 , V_41 ) ;
F_2 ( V_2 , V_54 , V_9 -> V_1 . V_20 ) ;
F_2 ( V_2 , V_55 , V_9 -> V_1 . V_21 ) ;
}
static void F_23 ( struct V_19 * V_12 )
{
struct V_56 * V_57 ;
if ( ( V_12 -> V_51 & V_58 ) == 0 ) {
F_18 ( V_12 ) ;
F_24 (ha, dev)
F_19 ( V_12 , V_57 -> V_59 ) ;
F_20 ( V_12 ) ;
} else
F_16 ( V_12 ) ;
}
static void F_25 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
const struct V_30 * V_31 = V_9 -> V_31 ;
T_4 V_60 , V_61 ;
int V_62 ;
T_3 V_63 , V_64 ;
struct V_65 * V_66 = V_9 -> V_67 -> V_68 ;
struct V_69 * V_70 = V_66 -> V_71 ;
V_62 = F_1 ( V_9 -> V_1 . V_2 ) ;
if ( V_62 != 0 )
F_26 ( V_9 -> V_12 , L_1 ) ;
V_63 = ( ( T_3 ) V_12 -> V_72 [ 0 ] << 24 ) |
( ( T_3 ) V_12 -> V_72 [ 1 ] << 16 ) |
( ( T_3 ) V_12 -> V_72 [ 2 ] << 8 ) |
( T_3 ) V_12 -> V_72 [ 3 ] ;
V_64 = ( ( T_3 ) V_12 -> V_72 [ 4 ] << 24 ) |
( ( T_3 ) V_12 -> V_72 [ 5 ] << 16 ) ;
F_2 ( V_2 , V_73 , V_63 ) ;
F_2 ( V_2 , V_74 , V_64 ) ;
F_2 ( V_2 , V_54 , V_9 -> V_1 . V_20 ) ;
F_2 ( V_2 , V_55 , V_9 -> V_1 . V_21 ) ;
F_2 ( V_2 , V_75 , V_76 ) ;
#ifdef F_27
F_2 ( V_2 , V_40 , V_77 << 16 ) ;
#else
F_2 ( V_2 , V_78 , V_77 ) ;
#endif
V_60 = V_9 -> V_37 ;
V_61 = V_60 + sizeof( V_36 ) * V_31 -> V_35 ;
F_2 ( V_2 , V_79 , V_60 ) ;
F_2 ( V_2 , V_80 , V_61 ) ;
F_28 ( V_12 ) ;
#ifdef F_27
F_17 ( V_2 , V_81 , 0xC0000000 ) ;
#else
F_2 ( V_2 , V_82 , 0x78000000 ) ;
#endif
F_2 ( V_2 , V_83 , V_70 -> V_83 ) ;
F_2 ( V_2 , V_84 , 0xffc0 ) ;
#ifndef F_27
F_2 ( V_2 , V_85 , ( F_29 ( V_9 -> V_13 ) / 2 ) << 29 ) ;
F_2 ( V_2 , V_40 , V_86 ) ;
#else
F_17 ( V_2 , V_40 , V_86 ) ;
#endif
if ( V_9 -> V_67 -> V_87 ) {
F_22 ( V_2 , V_40 , V_88 ) ;
F_17 ( V_2 , V_89 , V_90 ) ;
} else {
F_17 ( V_2 , V_40 , V_88 ) ;
F_22 ( V_2 , V_89 , V_90 ) ;
}
F_2 ( V_2 , V_91 , V_92 | V_93 |
V_94 | V_95 ) ;
F_2 ( V_2 , V_4 , V_5 | V_96 ) ;
F_2 ( V_2 , V_97 , 0x01000000 ) ;
}
static void F_30 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
const struct V_30 * V_31 = V_9 -> V_31 ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
struct V_69 * V_98 = V_9 -> V_67 -> V_68 -> V_71 ;
int V_3 ;
if ( ( F_3 ( V_2 , V_4 ) & V_96 ) == 0 )
return;
F_2 ( V_2 , V_89 , 0x01 ) ;
for ( V_3 = 0 ; ( ( F_3 ( V_2 , V_84 ) & 0x10000000 ) == 0 ) &&
V_3 < V_7 ; V_3 ++ )
F_4 ( 1 ) ;
if ( V_3 == V_7 )
F_31 ( V_9 -> V_12 , L_2 ) ;
F_2 ( V_2 , V_91 , 0 ) ;
F_22 ( V_2 , V_4 , V_96 ) ;
F_32 ( V_12 ) ;
if ( V_31 -> V_99 ) {
F_17 ( V_2 , V_40 , V_86 ) ;
F_17 ( V_2 , V_4 , V_5 | V_96 ) ;
F_2 ( V_2 , V_84 , V_100 ) ;
F_2 ( V_2 , V_83 , V_98 -> V_83 ) ;
}
}
static void F_33 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_2 ( V_2 , V_84 , V_23 ) ;
}
static void F_34 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_17 ( V_2 , V_91 , V_23 ) ;
}
static void F_35 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_22 ( V_2 , V_91 , V_23 ) ;
}
static void F_36 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_2 ( V_2 , V_97 , 0x01000000 ) ;
}
static void F_37 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_2 ( V_2 , V_101 , 0x01000000 ) ;
}
static T_3 F_38 ( struct V_19 * V_12 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
return F_3 ( V_2 , V_84 ) & F_3 ( V_2 , V_91 ) ;
}
static void F_39 ( struct V_19 * V_12 , T_3 V_102 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
struct V_1 T_1 * V_2 = V_9 -> V_1 . V_2 ;
F_2 ( V_2 , V_84 , V_102 ) ;
}
static void F_40 ( struct V_19 * V_12 , T_3 V_102 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
F_31 ( V_9 -> V_12 , L_3 , V_102 ) ;
}
static int F_41 ( struct V_19 * V_12 , void * V_103 , int * V_104 )
{
struct V_8 * V_9 = F_10 ( V_12 ) ;
if ( * V_104 < sizeof( struct V_1 ) )
return - V_16 ;
F_42 ( V_103 , V_9 -> V_1 . V_2 , sizeof( struct V_1 ) ) ;
return 0 ;
}
static int F_43 ( struct V_19 * V_12 )
{
return sizeof( struct V_1 ) ;
}
static void F_44 ( struct V_19 * V_12 )
{
}
