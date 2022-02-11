static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
const struct V_4 * V_5 = V_2 -> V_5 ;
return F_2 ( V_5 -> V_6 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_4 ( V_2 -> V_9 ) ;
V_2 -> V_10 = F_5 ( V_8 -> V_9 . V_11 , 0 ) ;
if ( ! V_2 -> V_10 )
return - V_12 ;
V_2 -> V_13 . V_14 = F_6 ( V_8 -> V_9 . V_11 , 0 ) ;
if ( ! V_2 -> V_13 . V_14 )
return - V_12 ;
V_2 -> V_13 . V_15 = F_6 ( V_8 -> V_9 . V_11 , 1 ) ;
if ( ! V_2 -> V_13 . V_15 ) {
F_7 ( V_2 -> V_13 . V_14 ) ;
return - V_12 ;
}
return 0 ;
}
static int F_8 ( struct V_16 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
F_3 ( V_2 ) ;
V_2 -> V_13 . V_17 = 0 ;
V_2 -> V_13 . V_18 = 0 ;
V_2 -> V_19 = V_20 ;
V_2 -> V_21 = V_22 | V_23 ;
V_2 -> V_24 = V_25 ;
return 0 ;
}
static int F_10 ( struct V_16 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
const struct V_4 * V_5 = V_2 -> V_5 ;
V_2 -> V_26 = F_11 ( ( V_5 -> V_27 + V_5 -> V_28 ) *
sizeof( V_29 ) , 8 ) ;
if ( F_12 ( V_2 -> V_26 ) )
return - V_30 ;
V_2 -> V_31 = ( void V_32 V_33 * )
F_13 ( V_2 -> V_26 ) ;
return 0 ;
}
static void F_14 ( struct V_16 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
if ( V_2 -> V_31 )
F_15 ( V_2 -> V_26 ) ;
}
static void F_16 ( struct V_16 * V_9 )
{
}
static void F_17 ( struct V_16 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_32 * V_14 = V_2 -> V_13 . V_14 ;
F_18 ( V_14 , V_34 , V_35 ) ;
}
static void F_19 ( struct V_16 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_3 V_32 * V_15 = V_2 -> V_13 . V_15 ;
F_20 ( V_15 , V_36 , 0 ) ;
F_20 ( V_15 , V_37 , 0 ) ;
F_20 ( V_15 , V_38 , 0 ) ;
F_20 ( V_15 , V_39 , 0 ) ;
}
static void F_21 ( struct V_16 * V_9 , const T_4 * V_40 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_3 V_32 * V_15 = V_2 -> V_13 . V_15 ;
T_5 V_41 , V_42 , V_43 ;
V_41 = ( ( T_5 ) V_40 [ 5 ] << 8 ) | V_40 [ 4 ] ;
V_42 = ( ( T_5 ) V_40 [ 3 ] << 8 ) | V_40 [ 2 ] ;
V_43 = ( ( T_5 ) V_40 [ 1 ] << 8 ) | V_40 [ 0 ] ;
F_20 ( V_15 , V_44 , V_41 ) ;
F_20 ( V_15 , V_45 , V_42 ) ;
F_20 ( V_15 , V_46 , V_43 ) ;
F_1 ( V_2 , V_47 ) ;
}
static void F_22 ( struct V_16 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_32 * V_14 = V_2 -> V_13 . V_14 ;
T_3 V_32 * V_15 = V_2 -> V_13 . V_15 ;
F_23 ( V_14 , V_34 , V_35 ) ;
if ( ( V_9 -> V_48 & V_49 ) != 0 ||
F_24 ( V_9 ) > V_50 ) {
F_20 ( V_15 , V_36 , 0xffff ) ;
F_20 ( V_15 , V_37 , 0xffff ) ;
F_20 ( V_15 , V_38 , 0xffff ) ;
F_20 ( V_15 , V_39 , 0xffff ) ;
}
}
static void F_25 ( struct V_16 * V_9 )
{
struct V_51 * V_52 ;
if ( ( V_9 -> V_48 & V_53 ) == 0 ) {
F_19 ( V_9 ) ;
F_26 (ha, dev)
F_21 ( V_9 , V_52 -> V_54 ) ;
F_22 ( V_9 ) ;
} else
F_17 ( V_9 ) ;
}
static void F_27 ( struct V_16 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_32 * V_14 = V_2 -> V_13 . V_14 ;
T_3 V_32 * V_15 = V_2 -> V_13 . V_15 ;
const struct V_4 * V_5 = V_2 -> V_5 ;
T_5 V_55 , V_56 , V_57 ;
const unsigned char * V_40 ;
int V_58 ;
F_28 ( V_14 , V_59 , V_60 | V_61 ) ;
for ( V_58 = 0 ; V_58 < sizeof( * V_15 ) ; V_58 ++ )
F_29 ( ( T_4 V_32 * ) V_15 + V_58 , 0 ) ;
F_20 ( V_15 , V_62 . V_63 , V_2 -> V_26 ) ;
F_20 ( V_15 , V_62 . V_64 ,
V_2 -> V_26 + sizeof( V_29 ) * V_5 -> V_28 ) ;
#ifndef F_30
F_31 ( V_15 , V_62 . V_65 , V_66 | V_67 ) ;
F_31 ( V_15 , V_62 . V_68 , V_66 | V_67 ) ;
#else
F_31 ( V_15 , V_62 . V_65 , V_66 ) ;
F_31 ( V_15 , V_62 . V_68 , V_66 ) ;
#endif
F_20 ( V_15 , V_62 . V_69 , 0x5f0 ) ;
F_32 ( V_15 , V_70 , 0xffffffff ) ;
F_32 ( V_15 , V_71 , 0xdebb20e3 ) ;
F_32 ( V_15 , V_72 , 0 ) ;
F_32 ( V_15 , V_73 , 0 ) ;
F_32 ( V_15 , V_74 , 0 ) ;
F_20 ( V_15 , V_75 , 0x8888 ) ;
F_20 ( V_15 , V_76 , 15 ) ;
F_20 ( V_15 , V_77 , 0x5ee ) ;
F_20 ( V_15 , V_78 , V_79 ) ;
F_20 ( V_15 , V_80 , 0x000005f0 ) ;
F_20 ( V_15 , V_81 , 0x000005f0 ) ;
F_20 ( V_15 , V_36 , 0 ) ;
F_20 ( V_15 , V_37 , 0 ) ;
F_20 ( V_15 , V_38 , 0 ) ;
F_20 ( V_15 , V_39 , 0 ) ;
F_20 ( V_15 , V_82 , 0 ) ;
F_20 ( V_15 , V_83 , 0 ) ;
F_20 ( V_15 , V_84 , 0 ) ;
F_20 ( V_15 , V_85 , 0 ) ;
V_40 = V_9 -> V_86 ;
V_55 = ( ( T_5 ) V_40 [ 5 ] << 8 ) | V_40 [ 4 ] ;
V_56 = ( ( T_5 ) V_40 [ 3 ] << 8 ) | V_40 [ 2 ] ;
V_57 = ( ( T_5 ) V_40 [ 1 ] << 8 ) | V_40 [ 0 ] ;
F_20 ( V_15 , V_87 , V_55 ) ;
F_20 ( V_15 , V_88 , V_56 ) ;
F_20 ( V_15 , V_89 , V_57 ) ;
F_20 ( V_15 , V_90 , 0 ) ;
F_20 ( V_15 , V_46 , 0 ) ;
F_20 ( V_15 , V_45 , 0 ) ;
F_20 ( V_15 , V_44 , 0 ) ;
F_33 ( V_9 ) ;
F_1 ( V_2 , V_91 ) ;
F_20 ( V_14 , V_92 , 0xffff ) ;
F_20 ( V_14 , V_93 , V_23 | V_94 | V_95 ) ;
F_32 ( V_14 , V_96 , 0 ) ;
F_32 ( V_14 , V_59 ,
V_97 | V_98 | V_99 |
V_100 ) ;
F_20 ( V_14 , V_101 , 0xd555 ) ;
F_20 ( V_14 , V_34 , V_102 | V_103 ) ;
if ( V_9 -> V_104 -> V_105 )
F_18 ( V_14 , V_34 , V_106 | V_107 ) ;
F_25 ( V_9 ) ;
F_34 ( V_14 , V_59 , V_60 | V_61 ) ;
}
static void F_35 ( struct V_16 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_32 * V_14 = V_2 -> V_13 . V_14 ;
int V_58 ;
for ( V_58 = 0 ; ( F_36 ( V_14 , V_93 ) == 0 ) && V_58 < V_108 ; V_58 ++ )
F_37 ( 1 ) ;
if ( V_58 == V_108 )
F_38 ( V_2 -> V_9 , L_1 ) ;
F_20 ( V_14 , V_93 , 0 ) ;
F_28 ( V_14 , V_59 , V_60 | V_61 ) ;
F_39 ( V_9 ) ;
}
static void F_40 ( struct V_16 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_32 * V_14 = V_2 -> V_13 . V_14 ;
F_20 ( V_14 , V_92 , V_20 ) ;
}
static void F_41 ( struct V_16 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_32 * V_14 = V_2 -> V_13 . V_14 ;
F_18 ( V_14 , V_93 , V_20 ) ;
}
static void F_42 ( struct V_16 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_32 * V_14 = V_2 -> V_13 . V_14 ;
F_23 ( V_14 , V_93 , V_20 ) ;
}
static void F_43 ( struct V_16 * V_9 )
{
}
static void F_44 ( struct V_16 * V_9 )
{
}
static T_1 F_45 ( struct V_16 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_32 * V_14 = V_2 -> V_13 . V_14 ;
return ( T_1 ) F_36 ( V_14 , V_92 ) ;
}
static void F_46 ( struct V_16 * V_9 , T_1 V_109 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_32 * V_14 = V_2 -> V_13 . V_14 ;
F_20 ( V_14 , V_92 , V_109 & 0xffff ) ;
}
static void F_47 ( struct V_16 * V_9 , T_1 V_109 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
F_38 ( V_2 -> V_9 , L_2 , V_109 ) ;
}
static int F_48 ( struct V_16 * V_9 , void * V_110 , int * V_111 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
if ( * V_111 < sizeof( T_2 ) + sizeof( T_3 V_32 * ) )
return - V_12 ;
F_49 ( V_110 , V_2 -> V_13 . V_14 , sizeof( T_2 ) ) ;
V_110 = ( char * ) V_110 + sizeof( T_2 ) ;
F_49 ( V_110 , V_2 -> V_13 . V_15 , sizeof( T_3 V_32 * ) ) ;
return 0 ;
}
static int F_50 ( struct V_16 * V_9 )
{
return sizeof( T_2 ) + sizeof( T_3 V_32 * ) ;
}
static void F_51 ( struct V_16 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
F_1 ( V_2 , V_112 ) ;
}
