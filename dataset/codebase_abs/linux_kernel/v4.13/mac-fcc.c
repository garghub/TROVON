static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
const struct V_4 * V_5 = V_2 -> V_5 ;
return F_2 ( V_5 -> V_6 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_4 ( V_2 -> V_9 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_10 = - V_11 ;
V_2 -> V_12 = F_5 ( V_8 -> V_9 . V_13 , 0 ) ;
if ( ! V_2 -> V_12 )
goto V_14;
V_2 -> V_15 . V_16 = F_6 ( V_8 -> V_9 . V_13 , 0 ) ;
if ( ! V_2 -> V_15 . V_16 )
goto V_14;
V_2 -> V_15 . V_17 = F_6 ( V_8 -> V_9 . V_13 , 1 ) ;
if ( ! V_2 -> V_15 . V_17 )
goto V_18;
V_2 -> V_15 . V_19 = F_6 ( V_8 -> V_9 . V_13 , 2 ) ;
if ( ! V_2 -> V_15 . V_19 )
goto V_20;
V_2 -> V_15 . V_21 = ( void V_22 * ) V_23 ;
V_5 -> V_24 = F_7 ( 128 , 32 ) ;
if ( F_8 ( V_5 -> V_24 ) ) {
V_10 = V_5 -> V_24 ;
goto V_25;
}
return 0 ;
V_25:
F_9 ( V_2 -> V_15 . V_19 ) ;
V_20:
F_9 ( V_2 -> V_15 . V_17 ) ;
V_18:
F_9 ( V_2 -> V_15 . V_16 ) ;
V_14:
return V_10 ;
}
static int F_10 ( struct V_26 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
if ( F_3 ( V_2 ) != 0 )
return - V_11 ;
V_2 -> V_27 = V_28 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_31 = V_32 ;
return 0 ;
}
static int F_12 ( struct V_26 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
const struct V_4 * V_5 = V_2 -> V_5 ;
V_2 -> V_33 = ( void V_22 V_34 * ) F_13 ( V_2 -> V_9 ,
( V_5 -> V_35 + V_5 -> V_36 ) *
sizeof( V_37 ) , & V_2 -> V_38 ,
V_39 ) ;
if ( V_2 -> V_33 == NULL )
return - V_40 ;
return 0 ;
}
static void F_14 ( struct V_26 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
const struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_2 -> V_33 )
F_15 ( V_2 -> V_9 ,
( V_5 -> V_35 + V_5 -> V_36 ) * sizeof( V_37 ) ,
( void V_34 * ) V_2 -> V_33 , V_2 -> V_38 ) ;
}
static void F_16 ( struct V_26 * V_9 )
{
}
static void F_17 ( struct V_26 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_22 * V_16 = V_2 -> V_15 . V_16 ;
F_18 ( V_16 , V_41 , V_42 ) ;
}
static void F_19 ( struct V_26 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_3 V_22 * V_17 = V_2 -> V_15 . V_17 ;
F_20 ( V_17 , V_43 , 0 ) ;
F_20 ( V_17 , V_44 , 0 ) ;
}
static void F_21 ( struct V_26 * V_9 , const T_4 * V_45 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_3 V_22 * V_17 = V_2 -> V_15 . V_17 ;
T_5 V_46 , V_47 , V_48 ;
V_46 = ( ( T_5 ) V_45 [ 5 ] << 8 ) | V_45 [ 4 ] ;
V_47 = ( ( T_5 ) V_45 [ 3 ] << 8 ) | V_45 [ 2 ] ;
V_48 = ( ( T_5 ) V_45 [ 1 ] << 8 ) | V_45 [ 0 ] ;
F_22 ( V_17 , V_49 , V_46 ) ;
F_22 ( V_17 , V_50 , V_47 ) ;
F_22 ( V_17 , V_51 , V_48 ) ;
F_1 ( V_2 , V_52 ) ;
}
static void F_23 ( struct V_26 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_22 * V_16 = V_2 -> V_15 . V_16 ;
T_3 V_22 * V_17 = V_2 -> V_15 . V_17 ;
F_24 ( V_16 , V_41 , V_42 ) ;
if ( ( V_9 -> V_53 & V_54 ) != 0 ||
F_25 ( V_9 ) > V_55 ) {
F_20 ( V_17 , V_43 , 0xffffffff ) ;
F_20 ( V_17 , V_44 , 0xffffffff ) ;
}
V_2 -> V_15 . V_56 = F_26 ( V_17 , V_43 ) ;
V_2 -> V_15 . V_57 = F_26 ( V_17 , V_44 ) ;
}
static void F_27 ( struct V_26 * V_9 )
{
struct V_58 * V_59 ;
if ( ( V_9 -> V_53 & V_60 ) == 0 ) {
F_19 ( V_9 ) ;
F_28 (ha, dev)
F_21 ( V_9 , V_59 -> V_61 ) ;
F_23 ( V_9 ) ;
} else
F_17 ( V_9 ) ;
}
static void F_29 ( struct V_26 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
const struct V_4 * V_5 = V_2 -> V_5 ;
T_2 V_22 * V_16 = V_2 -> V_15 . V_16 ;
T_6 V_22 * V_19 = V_2 -> V_15 . V_19 ;
T_3 V_22 * V_17 = V_2 -> V_15 . V_17 ;
T_7 V_62 , V_63 ;
T_5 V_64 , V_65 , V_66 ;
const unsigned char * V_45 ;
int V_67 ;
F_24 ( V_16 , V_68 , V_69 | V_70 ) ;
for ( V_67 = 0 ; V_67 < sizeof( * V_17 ) ; V_67 ++ )
F_30 ( ( T_4 V_22 * ) V_17 + V_67 , 0 ) ;
V_62 = V_2 -> V_38 ;
V_63 = V_62 + sizeof( V_37 ) * V_5 -> V_36 ;
F_20 ( V_17 , V_71 . V_72 , V_62 ) ;
F_20 ( V_17 , V_71 . V_73 , V_63 ) ;
F_22 ( V_17 , V_71 . V_74 , V_75 ) ;
F_20 ( V_17 , V_71 . V_76 , ( V_77 | V_78 ) << 24 ) ;
F_20 ( V_17 , V_71 . V_79 , ( V_77 | V_78 ) << 24 ) ;
F_22 ( V_17 , V_71 . V_80 , V_5 -> V_24 ) ;
F_22 ( V_17 , V_71 . V_81 , V_5 -> V_24 + 32 ) ;
F_22 ( V_17 , V_82 , V_5 -> V_24 + 64 ) ;
F_31 ( V_2 -> V_15 . V_21 + V_5 -> V_24 + 64 , 0x88 , 32 ) ;
F_20 ( V_17 , V_71 . V_83 , 0 ) ;
F_20 ( V_17 , V_71 . V_84 , 0 ) ;
F_20 ( V_17 , V_71 . V_85 , 0 ) ;
F_20 ( V_17 , V_71 . V_86 , 0 ) ;
F_22 ( V_17 , V_71 . V_87 , 0 ) ;
F_20 ( V_17 , V_71 . V_88 , 0 ) ;
F_20 ( V_17 , V_89 , 0 ) ;
F_20 ( V_17 , V_90 , 0xdebb20e3 ) ;
F_20 ( V_17 , V_91 , 0xffffffff ) ;
F_20 ( V_17 , V_92 , 0 ) ;
F_20 ( V_17 , V_93 , 0 ) ;
F_20 ( V_17 , V_94 , 0 ) ;
F_22 ( V_17 , V_95 , 15 ) ;
F_22 ( V_17 , V_96 , 0 ) ;
F_20 ( V_17 , V_43 , V_2 -> V_15 . V_56 ) ;
F_20 ( V_17 , V_44 , V_2 -> V_15 . V_56 ) ;
F_20 ( V_17 , V_97 , 0 ) ;
F_20 ( V_17 , V_98 , 0 ) ;
F_22 ( V_17 , V_99 , 0 ) ;
F_22 ( V_17 , V_100 , 0 ) ;
F_20 ( V_17 , V_101 , 0 ) ;
F_22 ( V_17 , V_102 , V_103 ) ;
F_22 ( V_17 , V_104 , V_105 ) ;
V_45 = V_9 -> V_106 ;
V_64 = ( ( T_5 ) V_45 [ 5 ] << 8 ) | V_45 [ 4 ] ;
V_65 = ( ( T_5 ) V_45 [ 3 ] << 8 ) | V_45 [ 2 ] ;
V_66 = ( ( T_5 ) V_45 [ 1 ] << 8 ) | V_45 [ 0 ] ;
F_22 ( V_17 , V_107 , V_64 ) ;
F_22 ( V_17 , V_108 , V_65 ) ;
F_22 ( V_17 , V_109 , V_66 ) ;
F_22 ( V_17 , V_49 , 0 ) ;
F_22 ( V_17 , V_50 , 0 ) ;
F_22 ( V_17 , V_51 , 0 ) ;
F_22 ( V_17 , V_110 , 1520 ) ;
F_22 ( V_17 , V_111 , 1520 ) ;
F_20 ( V_17 , V_112 , 0 ) ;
F_20 ( V_17 , V_113 , 0 ) ;
F_20 ( V_17 , V_114 , 0 ) ;
F_20 ( V_17 , V_115 , 0 ) ;
F_20 ( V_17 , V_116 , 0 ) ;
F_20 ( V_17 , V_117 , 0 ) ;
F_20 ( V_17 , V_118 , 0 ) ;
F_20 ( V_17 , V_119 , 0 ) ;
F_20 ( V_17 , V_120 , 0 ) ;
F_20 ( V_17 , V_121 , 0 ) ;
F_20 ( V_17 , V_122 , 0 ) ;
F_20 ( V_17 , V_123 , 0 ) ;
F_20 ( V_17 , V_124 , 0 ) ;
F_20 ( V_17 , V_125 , 0 ) ;
F_22 ( V_17 , V_126 , 0 ) ;
F_22 ( V_17 , V_127 , 0 ) ;
F_22 ( V_17 , V_128 , 0 ) ;
F_32 ( V_9 ) ;
if ( V_5 -> V_129 ) {
if ( V_9 -> V_130 -> V_131 == 100 )
F_33 ( V_19 , V_132 , 0x20 ) ;
else
F_34 ( V_19 , V_132 , 0x20 ) ;
}
F_1 ( V_2 , V_133 ) ;
F_22 ( V_16 , V_134 , 0xffff ) ;
F_22 ( V_16 , V_135 , V_136 | V_137 | V_138 ) ;
F_20 ( V_16 , V_68 , V_139 | V_140 ) ;
F_22 ( V_16 , V_141 , 0xd555 ) ;
F_20 ( V_16 , V_41 , V_142 ) ;
if ( V_5 -> V_129 )
F_18 ( V_16 , V_41 , V_143 ) ;
if ( V_9 -> V_130 -> V_144 )
F_18 ( V_16 , V_41 , V_145 | V_146 ) ;
else
F_24 ( V_16 , V_41 , V_145 | V_146 ) ;
F_27 ( V_9 ) ;
F_18 ( V_16 , V_68 , V_69 | V_70 ) ;
}
static void F_35 ( struct V_26 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_22 * V_16 = V_2 -> V_15 . V_16 ;
F_24 ( V_16 , V_68 , V_69 | V_70 ) ;
F_22 ( V_16 , V_134 , 0xffff ) ;
F_22 ( V_16 , V_135 , 0 ) ;
F_36 ( V_9 ) ;
}
static void F_37 ( struct V_26 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_22 * V_16 = V_2 -> V_15 . V_16 ;
F_22 ( V_16 , V_134 , V_28 ) ;
}
static void F_38 ( struct V_26 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_22 * V_16 = V_2 -> V_15 . V_16 ;
F_39 ( V_16 , V_135 , V_28 ) ;
}
static void F_40 ( struct V_26 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_22 * V_16 = V_2 -> V_15 . V_16 ;
F_41 ( V_16 , V_135 , V_28 ) ;
}
static void F_42 ( struct V_26 * V_9 )
{
}
static void F_43 ( struct V_26 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_22 * V_16 = V_2 -> V_15 . V_16 ;
F_39 ( V_16 , V_147 , 0x8000 ) ;
}
static T_1 F_44 ( struct V_26 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_22 * V_16 = V_2 -> V_15 . V_16 ;
return ( T_1 ) F_45 ( V_16 , V_134 ) ;
}
static void F_46 ( struct V_26 * V_9 , T_1 V_148 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_22 * V_16 = V_2 -> V_15 . V_16 ;
F_22 ( V_16 , V_134 , V_148 & 0xffff ) ;
}
static void F_47 ( struct V_26 * V_9 , T_1 V_148 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
F_48 ( V_2 -> V_9 , L_1 , V_148 ) ;
}
static int F_49 ( struct V_26 * V_9 , void * V_149 , int * V_150 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
if ( * V_150 < sizeof( T_2 ) + sizeof( T_3 ) + 1 )
return - V_11 ;
F_50 ( V_149 , V_2 -> V_15 . V_16 , sizeof( T_2 ) ) ;
V_149 = ( char * ) V_149 + sizeof( T_2 ) ;
F_50 ( V_149 , V_2 -> V_15 . V_17 , sizeof( T_3 ) ) ;
V_149 = ( char * ) V_149 + sizeof( T_3 ) ;
F_50 ( V_149 , V_2 -> V_15 . V_19 , 1 ) ;
return 0 ;
}
static int F_51 ( struct V_26 * V_9 )
{
return sizeof( T_2 ) + sizeof( T_3 ) + 1 ;
}
static void F_52 ( struct V_26 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_22 * V_16 = V_2 -> V_15 . V_16 ;
const struct V_4 * V_5 = V_2 -> V_5 ;
T_3 V_22 * V_17 = V_2 -> V_15 . V_17 ;
V_37 V_22 * V_151 ;
V_37 V_22 * V_152 ;
V_37 V_22 * V_153 ;
V_37 V_22 * V_154 ;
V_154 = V_2 -> V_155 + ( V_5 -> V_35 - 1 ) ;
V_152 = V_151 = ( V_37 V_22 * )
( ( F_26 ( V_17 , V_71 . V_84 ) - V_2 -> V_38 ) +
V_2 -> V_33 ) ;
V_153 = ( V_152 == V_2 -> V_155 ) ? V_154 : V_152 - 1 ;
while ( ( F_53 ( V_153 ) & V_156 ) != 0 ) {
V_152 = V_153 ;
V_153 = ( V_153 == V_2 -> V_155 ) ? V_154 : V_153 - 1 ;
if ( V_152 == V_151 )
break;
}
F_20 ( V_17 , V_71 . V_84 ,
( V_157 ) ( ( ( void * ) V_152 - V_2 -> V_33 ) +
V_2 -> V_38 ) ) ;
V_2 -> V_158 = V_152 ;
F_24 ( V_16 , V_68 , V_70 ) ;
F_54 ( 10 ) ;
F_18 ( V_16 , V_68 , V_70 ) ;
F_1 ( V_2 , V_159 ) ;
}
