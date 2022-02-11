static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
const struct V_4 * V_5 = V_2 -> V_5 ;
return F_2 ( V_5 -> V_6 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_4 ( V_2 -> V_9 ) ;
V_2 -> V_10 = F_5 ( V_8 -> V_9 . V_11 , 0 , NULL ) ;
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
V_2 -> V_24 = V_25 | V_26 ;
V_2 -> V_27 = V_28 ;
return 0 ;
}
static int F_10 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
const struct V_4 * V_5 = V_2 -> V_5 ;
V_2 -> V_29 = F_11 ( ( V_5 -> V_30 + V_5 -> V_31 ) *
sizeof( V_32 ) , 8 ) ;
if ( F_12 ( V_2 -> V_29 ) )
return - V_33 ;
V_2 -> V_34 = ( void V_35 V_36 * )
F_13 ( V_2 -> V_29 ) ;
return 0 ;
}
static void F_14 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
if ( V_2 -> V_34 )
F_15 ( V_2 -> V_29 ) ;
}
static void F_16 ( struct V_17 * V_9 )
{
}
static void F_17 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_35 * V_15 = V_2 -> V_14 . V_15 ;
F_18 ( V_15 , V_37 , V_38 ) ;
}
static void F_19 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_3 V_35 * V_16 = V_2 -> V_14 . V_16 ;
F_20 ( V_16 , V_39 , 0 ) ;
F_20 ( V_16 , V_40 , 0 ) ;
F_20 ( V_16 , V_41 , 0 ) ;
F_20 ( V_16 , V_42 , 0 ) ;
}
static void F_21 ( struct V_17 * V_9 , const T_4 * V_43 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_3 V_35 * V_16 = V_2 -> V_14 . V_16 ;
T_5 V_44 , V_45 , V_46 ;
V_44 = ( ( T_5 ) V_43 [ 5 ] << 8 ) | V_43 [ 4 ] ;
V_45 = ( ( T_5 ) V_43 [ 3 ] << 8 ) | V_43 [ 2 ] ;
V_46 = ( ( T_5 ) V_43 [ 1 ] << 8 ) | V_43 [ 0 ] ;
F_20 ( V_16 , V_47 , V_44 ) ;
F_20 ( V_16 , V_48 , V_45 ) ;
F_20 ( V_16 , V_49 , V_46 ) ;
F_1 ( V_2 , V_50 ) ;
}
static void F_22 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_35 * V_15 = V_2 -> V_14 . V_15 ;
T_3 V_35 * V_16 = V_2 -> V_14 . V_16 ;
F_23 ( V_15 , V_37 , V_38 ) ;
if ( ( V_9 -> V_51 & V_52 ) != 0 ||
F_24 ( V_9 ) > V_53 ) {
F_20 ( V_16 , V_39 , 0xffff ) ;
F_20 ( V_16 , V_40 , 0xffff ) ;
F_20 ( V_16 , V_41 , 0xffff ) ;
F_20 ( V_16 , V_42 , 0xffff ) ;
}
}
static void F_25 ( struct V_17 * V_9 )
{
struct V_54 * V_55 ;
if ( ( V_9 -> V_51 & V_56 ) == 0 ) {
F_19 ( V_9 ) ;
F_26 (ha, dev)
F_21 ( V_9 , V_55 -> V_57 ) ;
F_22 ( V_9 ) ;
} else
F_17 ( V_9 ) ;
}
static void F_27 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_35 * V_15 = V_2 -> V_14 . V_15 ;
T_3 V_35 * V_16 = V_2 -> V_14 . V_16 ;
const struct V_4 * V_5 = V_2 -> V_5 ;
T_5 V_58 , V_59 , V_60 ;
const unsigned char * V_43 ;
int V_61 ;
F_28 ( V_15 , V_62 , V_63 | V_64 ) ;
for ( V_61 = 0 ; V_61 < sizeof( * V_16 ) ; V_61 ++ )
F_29 ( ( T_4 V_35 * ) V_16 + V_61 , 0 ) ;
F_20 ( V_16 , V_65 . V_66 , V_2 -> V_29 ) ;
F_20 ( V_16 , V_65 . V_67 ,
V_2 -> V_29 + sizeof( V_32 ) * V_5 -> V_31 ) ;
#ifndef F_30
F_31 ( V_16 , V_65 . V_68 , V_69 | V_70 ) ;
F_31 ( V_16 , V_65 . V_71 , V_69 | V_70 ) ;
#else
F_31 ( V_16 , V_65 . V_68 , V_69 ) ;
F_31 ( V_16 , V_65 . V_71 , V_69 ) ;
#endif
F_20 ( V_16 , V_65 . V_72 , 0x5f0 ) ;
F_32 ( V_16 , V_73 , 0xffffffff ) ;
F_32 ( V_16 , V_74 , 0xdebb20e3 ) ;
F_32 ( V_16 , V_75 , 0 ) ;
F_32 ( V_16 , V_76 , 0 ) ;
F_32 ( V_16 , V_77 , 0 ) ;
F_20 ( V_16 , V_78 , 0x8888 ) ;
F_20 ( V_16 , V_79 , 15 ) ;
F_20 ( V_16 , V_80 , 0x5ee ) ;
F_20 ( V_16 , V_81 , V_82 ) ;
F_20 ( V_16 , V_83 , 0x000005f0 ) ;
F_20 ( V_16 , V_84 , 0x000005f0 ) ;
F_20 ( V_16 , V_39 , 0 ) ;
F_20 ( V_16 , V_40 , 0 ) ;
F_20 ( V_16 , V_41 , 0 ) ;
F_20 ( V_16 , V_42 , 0 ) ;
F_20 ( V_16 , V_85 , 0 ) ;
F_20 ( V_16 , V_86 , 0 ) ;
F_20 ( V_16 , V_87 , 0 ) ;
F_20 ( V_16 , V_88 , 0 ) ;
V_43 = V_9 -> V_89 ;
V_58 = ( ( T_5 ) V_43 [ 5 ] << 8 ) | V_43 [ 4 ] ;
V_59 = ( ( T_5 ) V_43 [ 3 ] << 8 ) | V_43 [ 2 ] ;
V_60 = ( ( T_5 ) V_43 [ 1 ] << 8 ) | V_43 [ 0 ] ;
F_20 ( V_16 , V_90 , V_58 ) ;
F_20 ( V_16 , V_91 , V_59 ) ;
F_20 ( V_16 , V_92 , V_60 ) ;
F_20 ( V_16 , V_93 , 0 ) ;
F_20 ( V_16 , V_49 , 0 ) ;
F_20 ( V_16 , V_48 , 0 ) ;
F_20 ( V_16 , V_47 , 0 ) ;
F_33 ( V_9 ) ;
F_1 ( V_2 , V_94 ) ;
F_20 ( V_15 , V_95 , 0xffff ) ;
F_20 ( V_15 , V_96 , V_26 | V_97 | V_98 ) ;
F_32 ( V_15 , V_99 , 0 ) ;
F_32 ( V_15 , V_62 ,
V_100 | V_101 | V_102 |
V_103 ) ;
F_20 ( V_15 , V_104 , 0xd555 ) ;
F_20 ( V_15 , V_37 , V_105 | V_106 ) ;
if ( V_2 -> V_107 -> V_108 )
F_18 ( V_15 , V_37 , V_109 | V_110 ) ;
F_34 ( V_15 , V_62 , V_63 | V_64 ) ;
}
static void F_35 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_35 * V_15 = V_2 -> V_14 . V_15 ;
int V_61 ;
for ( V_61 = 0 ; ( F_36 ( V_15 , V_96 ) == 0 ) && V_61 < V_111 ; V_61 ++ )
F_37 ( 1 ) ;
if ( V_61 == V_111 )
F_38 ( V_2 -> V_9 , L_1 ) ;
F_20 ( V_15 , V_96 , 0 ) ;
F_28 ( V_15 , V_62 , V_63 | V_64 ) ;
F_39 ( V_9 ) ;
}
static void F_40 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_35 * V_15 = V_2 -> V_14 . V_15 ;
F_20 ( V_15 , V_95 , V_21 ) ;
}
static void F_41 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_35 * V_15 = V_2 -> V_14 . V_15 ;
F_18 ( V_15 , V_96 , V_21 ) ;
}
static void F_42 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_35 * V_15 = V_2 -> V_14 . V_15 ;
F_23 ( V_15 , V_96 , V_21 ) ;
}
static void F_43 ( struct V_17 * V_9 )
{
}
static void F_44 ( struct V_17 * V_9 )
{
}
static T_1 F_45 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_35 * V_15 = V_2 -> V_14 . V_15 ;
return ( T_1 ) F_36 ( V_15 , V_95 ) ;
}
static void F_46 ( struct V_17 * V_9 , T_1 V_112 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_2 V_35 * V_15 = V_2 -> V_14 . V_15 ;
F_20 ( V_15 , V_95 , V_112 & 0xffff ) ;
}
static void F_47 ( struct V_17 * V_9 , T_1 V_112 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
F_38 ( V_2 -> V_9 , L_2 , V_112 ) ;
}
static int F_48 ( struct V_17 * V_9 , void * V_113 , int * V_114 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
if ( * V_114 < sizeof( T_2 ) + sizeof( T_3 V_35 * ) )
return - V_13 ;
F_49 ( V_113 , V_2 -> V_14 . V_15 , sizeof( T_2 ) ) ;
V_113 = ( char * ) V_113 + sizeof( T_2 ) ;
F_49 ( V_113 , V_2 -> V_14 . V_16 , sizeof( T_3 V_35 * ) ) ;
return 0 ;
}
static int F_50 ( struct V_17 * V_9 )
{
return sizeof( T_2 ) + sizeof( T_3 V_35 * ) ;
}
static void F_51 ( struct V_17 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
F_1 ( V_2 , V_115 ) ;
}
