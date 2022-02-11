static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
const struct V_4 * V_5 = V_2 -> V_5 ;
return F_2 ( V_5 -> V_6 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_4 ( V_2 -> V_9 ) ;
V_2 -> V_10 = F_5 ( V_8 -> V_9 . V_11 , 0 ) ;
if ( V_2 -> V_10 == V_12 )
return - V_13 ;
V_2 -> V_14 . V_15 = F_6 ( V_8 -> V_9 . V_11 , 0 ) ;
if ( ! V_2 -> V_14 . V_15 )
return - V_13 ;
V_2 -> V_14 . V_16 = F_6 ( V_8 -> V_9 . V_11 , 1 ) ;
if ( ! V_2 -> V_14 . V_16 ) {
F_7 ( V_2 -> V_14 . V_15 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_8 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
F_3 ( V_2 ) ;
V_2 -> V_14 . V_18 = 0 ;
V_2 -> V_14 . V_19 = 0 ;
V_2 -> V_20 = V_21 ;
V_2 -> V_22 = V_23 ;
V_2 -> V_24 = V_25 ;
V_2 -> V_26 = V_27 | V_28 ;
V_2 -> V_29 = V_30 ;
return 0 ;
}
static int F_10 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
const struct V_4 * V_5 = V_2 -> V_5 ;
V_2 -> V_31 = F_11 ( ( V_5 -> V_32 + V_5 -> V_33 ) *
sizeof( V_34 ) , 8 ) ;
if ( F_12 ( V_2 -> V_31 ) )
return - V_35 ;
V_2 -> V_36 = ( void V_37 V_38 * )
F_13 ( V_2 -> V_31 ) ;
return 0 ;
}
static void F_14 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
if ( V_2 -> V_36 )
F_15 ( V_2 -> V_31 ) ;
}
static void F_16 ( struct V_17 * V_9 )
{
}
static void F_17 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_37 * V_15 = V_2 -> V_14 . V_15 ;
F_18 ( V_15 , V_39 , V_40 ) ;
}
static void F_19 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_3 V_37 * V_16 = V_2 -> V_14 . V_16 ;
F_20 ( V_16 , V_41 , 0 ) ;
F_20 ( V_16 , V_42 , 0 ) ;
F_20 ( V_16 , V_43 , 0 ) ;
F_20 ( V_16 , V_44 , 0 ) ;
}
static void F_21 ( struct V_17 * V_9 , const T_4 * V_45 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_3 V_37 * V_16 = V_2 -> V_14 . V_16 ;
T_5 V_46 , V_47 , V_48 ;
V_46 = ( ( T_5 ) V_45 [ 5 ] << 8 ) | V_45 [ 4 ] ;
V_47 = ( ( T_5 ) V_45 [ 3 ] << 8 ) | V_45 [ 2 ] ;
V_48 = ( ( T_5 ) V_45 [ 1 ] << 8 ) | V_45 [ 0 ] ;
F_20 ( V_16 , V_49 , V_46 ) ;
F_20 ( V_16 , V_50 , V_47 ) ;
F_20 ( V_16 , V_51 , V_48 ) ;
F_1 ( V_2 , V_52 ) ;
}
static void F_22 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_37 * V_15 = V_2 -> V_14 . V_15 ;
T_3 V_37 * V_16 = V_2 -> V_14 . V_16 ;
F_23 ( V_15 , V_39 , V_40 ) ;
if ( ( V_9 -> V_53 & V_54 ) != 0 ||
F_24 ( V_9 ) > V_55 ) {
F_20 ( V_16 , V_41 , 0xffff ) ;
F_20 ( V_16 , V_42 , 0xffff ) ;
F_20 ( V_16 , V_43 , 0xffff ) ;
F_20 ( V_16 , V_44 , 0xffff ) ;
}
}
static void F_25 ( struct V_17 * V_9 )
{
struct V_56 * V_57 ;
if ( ( V_9 -> V_53 & V_58 ) == 0 ) {
F_19 ( V_9 ) ;
F_26 (ha, dev)
F_21 ( V_9 , V_57 -> V_59 ) ;
F_22 ( V_9 ) ;
} else
F_17 ( V_9 ) ;
}
static void F_27 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_37 * V_15 = V_2 -> V_14 . V_15 ;
T_3 V_37 * V_16 = V_2 -> V_14 . V_16 ;
const struct V_4 * V_5 = V_2 -> V_5 ;
T_5 V_60 , V_61 , V_62 ;
const unsigned char * V_45 ;
int V_63 ;
F_28 ( V_15 , V_64 , V_65 | V_66 ) ;
for ( V_63 = 0 ; V_63 < sizeof( * V_16 ) ; V_63 ++ )
F_29 ( ( T_4 V_37 * ) V_16 + V_63 , 0 ) ;
F_20 ( V_16 , V_67 . V_68 , V_2 -> V_31 ) ;
F_20 ( V_16 , V_67 . V_69 ,
V_2 -> V_31 + sizeof( V_34 ) * V_5 -> V_33 ) ;
#ifndef F_30
F_31 ( V_16 , V_67 . V_70 , V_71 | V_72 ) ;
F_31 ( V_16 , V_67 . V_73 , V_71 | V_72 ) ;
#else
F_31 ( V_16 , V_67 . V_70 , V_71 ) ;
F_31 ( V_16 , V_67 . V_73 , V_71 ) ;
#endif
F_20 ( V_16 , V_67 . V_74 , 0x5f0 ) ;
F_32 ( V_16 , V_75 , 0xffffffff ) ;
F_32 ( V_16 , V_76 , 0xdebb20e3 ) ;
F_32 ( V_16 , V_77 , 0 ) ;
F_32 ( V_16 , V_78 , 0 ) ;
F_32 ( V_16 , V_79 , 0 ) ;
F_20 ( V_16 , V_80 , 0x8888 ) ;
F_20 ( V_16 , V_81 , 15 ) ;
F_20 ( V_16 , V_82 , 0x5ee ) ;
F_20 ( V_16 , V_83 , V_84 ) ;
F_20 ( V_16 , V_85 , 0x000005f0 ) ;
F_20 ( V_16 , V_86 , 0x000005f0 ) ;
F_20 ( V_16 , V_41 , 0 ) ;
F_20 ( V_16 , V_42 , 0 ) ;
F_20 ( V_16 , V_43 , 0 ) ;
F_20 ( V_16 , V_44 , 0 ) ;
F_20 ( V_16 , V_87 , 0 ) ;
F_20 ( V_16 , V_88 , 0 ) ;
F_20 ( V_16 , V_89 , 0 ) ;
F_20 ( V_16 , V_90 , 0 ) ;
V_45 = V_9 -> V_91 ;
V_60 = ( ( T_5 ) V_45 [ 5 ] << 8 ) | V_45 [ 4 ] ;
V_61 = ( ( T_5 ) V_45 [ 3 ] << 8 ) | V_45 [ 2 ] ;
V_62 = ( ( T_5 ) V_45 [ 1 ] << 8 ) | V_45 [ 0 ] ;
F_20 ( V_16 , V_92 , V_60 ) ;
F_20 ( V_16 , V_93 , V_61 ) ;
F_20 ( V_16 , V_94 , V_62 ) ;
F_20 ( V_16 , V_95 , 0 ) ;
F_20 ( V_16 , V_51 , 0 ) ;
F_20 ( V_16 , V_50 , 0 ) ;
F_20 ( V_16 , V_49 , 0 ) ;
F_33 ( V_9 ) ;
F_1 ( V_2 , V_96 ) ;
F_20 ( V_15 , V_97 , 0xffff ) ;
F_20 ( V_15 , V_98 , V_28 | V_99 | V_100 ) ;
F_32 ( V_15 , V_101 , 0 ) ;
F_32 ( V_15 , V_64 ,
V_102 | V_103 | V_104 |
V_105 ) ;
F_20 ( V_15 , V_106 , 0xd555 ) ;
F_20 ( V_15 , V_39 , V_107 | V_108 ) ;
if ( V_9 -> V_109 -> V_110 )
F_18 ( V_15 , V_39 , V_111 | V_112 ) ;
F_25 ( V_9 ) ;
F_34 ( V_15 , V_64 , V_65 | V_66 ) ;
}
static void F_35 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_37 * V_15 = V_2 -> V_14 . V_15 ;
int V_63 ;
for ( V_63 = 0 ; ( F_36 ( V_15 , V_98 ) == 0 ) && V_63 < V_113 ; V_63 ++ )
F_37 ( 1 ) ;
if ( V_63 == V_113 )
F_38 ( V_2 -> V_9 , L_1 ) ;
F_20 ( V_15 , V_98 , 0 ) ;
F_28 ( V_15 , V_64 , V_65 | V_66 ) ;
F_39 ( V_9 ) ;
}
static void F_40 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_37 * V_15 = V_2 -> V_14 . V_15 ;
F_20 ( V_15 , V_97 , V_21 ) ;
}
static void F_41 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_37 * V_15 = V_2 -> V_14 . V_15 ;
F_18 ( V_15 , V_98 , V_21 ) ;
}
static void F_42 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_37 * V_15 = V_2 -> V_14 . V_15 ;
F_23 ( V_15 , V_98 , V_21 ) ;
}
static void F_43 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_37 * V_15 = V_2 -> V_14 . V_15 ;
F_20 ( V_15 , V_97 , V_23 ) ;
}
static void F_44 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_37 * V_15 = V_2 -> V_14 . V_15 ;
F_18 ( V_15 , V_98 , V_23 ) ;
}
static void F_45 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_37 * V_15 = V_2 -> V_14 . V_15 ;
F_23 ( V_15 , V_98 , V_23 ) ;
}
static void F_46 ( struct V_17 * V_9 )
{
}
static void F_47 ( struct V_17 * V_9 )
{
}
static T_1 F_48 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_37 * V_15 = V_2 -> V_14 . V_15 ;
return ( T_1 ) F_36 ( V_15 , V_97 ) ;
}
static void F_49 ( struct V_17 * V_9 , T_1 V_114 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_37 * V_15 = V_2 -> V_14 . V_15 ;
F_20 ( V_15 , V_97 , V_114 & 0xffff ) ;
}
static void F_50 ( struct V_17 * V_9 , T_1 V_114 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
F_38 ( V_2 -> V_9 , L_2 , V_114 ) ;
}
static int F_51 ( struct V_17 * V_9 , void * V_115 , int * V_116 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
if ( * V_116 < sizeof( T_2 ) + sizeof( T_3 V_37 * ) )
return - V_13 ;
F_52 ( V_115 , V_2 -> V_14 . V_15 , sizeof( T_2 ) ) ;
V_115 = ( char * ) V_115 + sizeof( T_2 ) ;
F_52 ( V_115 , V_2 -> V_14 . V_16 , sizeof( T_3 V_37 * ) ) ;
return 0 ;
}
static int F_53 ( struct V_17 * V_9 )
{
return sizeof( T_2 ) + sizeof( T_3 V_37 * ) ;
}
static void F_54 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
F_1 ( V_2 , V_117 ) ;
}
