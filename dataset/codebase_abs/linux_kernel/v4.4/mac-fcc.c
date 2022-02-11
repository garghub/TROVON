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
if ( V_2 -> V_12 == V_14 )
goto V_15;
V_2 -> V_16 . V_17 = F_6 ( V_8 -> V_9 . V_13 , 0 ) ;
if ( ! V_2 -> V_16 . V_17 )
goto V_15;
V_2 -> V_16 . V_18 = F_6 ( V_8 -> V_9 . V_13 , 1 ) ;
if ( ! V_2 -> V_16 . V_18 )
goto V_19;
V_2 -> V_16 . V_20 = F_6 ( V_8 -> V_9 . V_13 , 2 ) ;
if ( ! V_2 -> V_16 . V_20 )
goto V_21;
V_2 -> V_16 . V_22 = ( void V_23 * ) V_24 ;
V_5 -> V_25 = F_7 ( 128 , 32 ) ;
if ( F_8 ( V_5 -> V_25 ) ) {
V_10 = V_5 -> V_25 ;
goto V_26;
}
return 0 ;
V_26:
F_9 ( V_2 -> V_16 . V_20 ) ;
V_21:
F_9 ( V_2 -> V_16 . V_18 ) ;
V_19:
F_9 ( V_2 -> V_16 . V_17 ) ;
V_15:
return V_10 ;
}
static int F_10 ( struct V_27 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
if ( F_3 ( V_2 ) != 0 )
return - V_11 ;
V_2 -> V_28 = V_29 ;
V_2 -> V_30 = V_31 ;
V_2 -> V_32 = V_33 ;
V_2 -> V_34 = V_35 ;
V_2 -> V_36 = V_37 ;
return 0 ;
}
static int F_12 ( struct V_27 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
const struct V_4 * V_5 = V_2 -> V_5 ;
V_2 -> V_38 = ( void V_23 V_39 * ) F_13 ( V_2 -> V_9 ,
( V_5 -> V_40 + V_5 -> V_41 ) *
sizeof( V_42 ) , & V_2 -> V_43 ,
V_44 ) ;
if ( V_2 -> V_38 == NULL )
return - V_45 ;
return 0 ;
}
static void F_14 ( struct V_27 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
const struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_2 -> V_38 )
F_15 ( V_2 -> V_9 ,
( V_5 -> V_40 + V_5 -> V_41 ) * sizeof( V_42 ) ,
( void V_39 * ) V_2 -> V_38 , V_2 -> V_43 ) ;
}
static void F_16 ( struct V_27 * V_9 )
{
}
static void F_17 ( struct V_27 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_23 * V_17 = V_2 -> V_16 . V_17 ;
F_18 ( V_17 , V_46 , V_47 ) ;
}
static void F_19 ( struct V_27 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_3 V_23 * V_18 = V_2 -> V_16 . V_18 ;
F_20 ( V_18 , V_48 , 0 ) ;
F_20 ( V_18 , V_49 , 0 ) ;
}
static void F_21 ( struct V_27 * V_9 , const T_4 * V_50 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_3 V_23 * V_18 = V_2 -> V_16 . V_18 ;
T_5 V_51 , V_52 , V_53 ;
V_51 = ( ( T_5 ) V_50 [ 5 ] << 8 ) | V_50 [ 4 ] ;
V_52 = ( ( T_5 ) V_50 [ 3 ] << 8 ) | V_50 [ 2 ] ;
V_53 = ( ( T_5 ) V_50 [ 1 ] << 8 ) | V_50 [ 0 ] ;
F_22 ( V_18 , V_54 , V_51 ) ;
F_22 ( V_18 , V_55 , V_52 ) ;
F_22 ( V_18 , V_56 , V_53 ) ;
F_1 ( V_2 , V_57 ) ;
}
static void F_23 ( struct V_27 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_23 * V_17 = V_2 -> V_16 . V_17 ;
T_3 V_23 * V_18 = V_2 -> V_16 . V_18 ;
F_24 ( V_17 , V_46 , V_47 ) ;
if ( ( V_9 -> V_58 & V_59 ) != 0 ||
F_25 ( V_9 ) > V_60 ) {
F_20 ( V_18 , V_48 , 0xffffffff ) ;
F_20 ( V_18 , V_49 , 0xffffffff ) ;
}
V_2 -> V_16 . V_61 = F_26 ( V_18 , V_48 ) ;
V_2 -> V_16 . V_62 = F_26 ( V_18 , V_49 ) ;
}
static void F_27 ( struct V_27 * V_9 )
{
struct V_63 * V_64 ;
if ( ( V_9 -> V_58 & V_65 ) == 0 ) {
F_19 ( V_9 ) ;
F_28 (ha, dev)
F_21 ( V_9 , V_64 -> V_66 ) ;
F_23 ( V_9 ) ;
} else
F_17 ( V_9 ) ;
}
static void F_29 ( struct V_27 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
const struct V_4 * V_5 = V_2 -> V_5 ;
T_2 V_23 * V_17 = V_2 -> V_16 . V_17 ;
T_6 V_23 * V_20 = V_2 -> V_16 . V_20 ;
T_3 V_23 * V_18 = V_2 -> V_16 . V_18 ;
T_7 V_67 , V_68 ;
T_5 V_69 , V_70 , V_71 ;
const unsigned char * V_50 ;
int V_72 ;
F_24 ( V_17 , V_73 , V_74 | V_75 ) ;
for ( V_72 = 0 ; V_72 < sizeof( * V_18 ) ; V_72 ++ )
F_30 ( ( T_4 V_23 * ) V_18 + V_72 , 0 ) ;
V_67 = V_2 -> V_43 ;
V_68 = V_67 + sizeof( V_42 ) * V_5 -> V_41 ;
F_20 ( V_18 , V_76 . V_77 , V_67 ) ;
F_20 ( V_18 , V_76 . V_78 , V_68 ) ;
F_22 ( V_18 , V_76 . V_79 , V_80 ) ;
F_20 ( V_18 , V_76 . V_81 , ( V_82 | V_83 ) << 24 ) ;
F_20 ( V_18 , V_76 . V_84 , ( V_82 | V_83 ) << 24 ) ;
F_22 ( V_18 , V_76 . V_85 , V_5 -> V_25 ) ;
F_22 ( V_18 , V_76 . V_86 , V_5 -> V_25 + 32 ) ;
F_22 ( V_18 , V_87 , V_5 -> V_25 + 64 ) ;
F_31 ( V_2 -> V_16 . V_22 + V_5 -> V_25 + 64 , 0x88 , 32 ) ;
F_20 ( V_18 , V_76 . V_88 , 0 ) ;
F_20 ( V_18 , V_76 . V_89 , 0 ) ;
F_20 ( V_18 , V_76 . V_90 , 0 ) ;
F_20 ( V_18 , V_76 . V_91 , 0 ) ;
F_22 ( V_18 , V_76 . V_92 , 0 ) ;
F_20 ( V_18 , V_76 . V_93 , 0 ) ;
F_20 ( V_18 , V_94 , 0 ) ;
F_20 ( V_18 , V_95 , 0xdebb20e3 ) ;
F_20 ( V_18 , V_96 , 0xffffffff ) ;
F_20 ( V_18 , V_97 , 0 ) ;
F_20 ( V_18 , V_98 , 0 ) ;
F_20 ( V_18 , V_99 , 0 ) ;
F_22 ( V_18 , V_100 , 15 ) ;
F_22 ( V_18 , V_101 , 0 ) ;
F_20 ( V_18 , V_48 , V_2 -> V_16 . V_61 ) ;
F_20 ( V_18 , V_49 , V_2 -> V_16 . V_61 ) ;
F_20 ( V_18 , V_102 , 0 ) ;
F_20 ( V_18 , V_103 , 0 ) ;
F_22 ( V_18 , V_104 , 0 ) ;
F_22 ( V_18 , V_105 , 0 ) ;
F_20 ( V_18 , V_106 , 0 ) ;
F_22 ( V_18 , V_107 , V_108 ) ;
F_22 ( V_18 , V_109 , V_110 ) ;
V_50 = V_9 -> V_111 ;
V_69 = ( ( T_5 ) V_50 [ 5 ] << 8 ) | V_50 [ 4 ] ;
V_70 = ( ( T_5 ) V_50 [ 3 ] << 8 ) | V_50 [ 2 ] ;
V_71 = ( ( T_5 ) V_50 [ 1 ] << 8 ) | V_50 [ 0 ] ;
F_22 ( V_18 , V_112 , V_69 ) ;
F_22 ( V_18 , V_113 , V_70 ) ;
F_22 ( V_18 , V_114 , V_71 ) ;
F_22 ( V_18 , V_54 , 0 ) ;
F_22 ( V_18 , V_55 , 0 ) ;
F_22 ( V_18 , V_56 , 0 ) ;
F_22 ( V_18 , V_115 , 1520 ) ;
F_22 ( V_18 , V_116 , 1520 ) ;
F_20 ( V_18 , V_117 , 0 ) ;
F_20 ( V_18 , V_118 , 0 ) ;
F_20 ( V_18 , V_119 , 0 ) ;
F_20 ( V_18 , V_120 , 0 ) ;
F_20 ( V_18 , V_121 , 0 ) ;
F_20 ( V_18 , V_122 , 0 ) ;
F_20 ( V_18 , V_123 , 0 ) ;
F_20 ( V_18 , V_124 , 0 ) ;
F_20 ( V_18 , V_125 , 0 ) ;
F_20 ( V_18 , V_126 , 0 ) ;
F_20 ( V_18 , V_127 , 0 ) ;
F_20 ( V_18 , V_128 , 0 ) ;
F_20 ( V_18 , V_129 , 0 ) ;
F_20 ( V_18 , V_130 , 0 ) ;
F_22 ( V_18 , V_131 , 0 ) ;
F_22 ( V_18 , V_132 , 0 ) ;
F_22 ( V_18 , V_133 , 0 ) ;
F_32 ( V_9 ) ;
if ( V_5 -> V_134 ) {
if ( V_2 -> V_135 -> V_136 == 100 )
F_33 ( V_20 , V_137 , 0x20 ) ;
else
F_34 ( V_20 , V_137 , 0x20 ) ;
}
F_1 ( V_2 , V_138 ) ;
F_22 ( V_17 , V_139 , 0xffff ) ;
F_22 ( V_17 , V_140 , V_141 | V_142 | V_143 ) ;
F_20 ( V_17 , V_73 , V_144 | V_145 ) ;
F_22 ( V_17 , V_146 , 0xd555 ) ;
F_20 ( V_17 , V_46 , V_147 ) ;
if ( V_5 -> V_134 )
F_18 ( V_17 , V_46 , V_148 ) ;
if ( V_2 -> V_135 -> V_149 )
F_18 ( V_17 , V_46 , V_150 | V_151 ) ;
else
F_24 ( V_17 , V_46 , V_150 | V_151 ) ;
F_27 ( V_9 ) ;
F_18 ( V_17 , V_73 , V_74 | V_75 ) ;
}
static void F_35 ( struct V_27 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_23 * V_17 = V_2 -> V_16 . V_17 ;
F_24 ( V_17 , V_73 , V_74 | V_75 ) ;
F_22 ( V_17 , V_139 , 0xffff ) ;
F_22 ( V_17 , V_140 , 0 ) ;
F_36 ( V_9 ) ;
}
static void F_37 ( struct V_27 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_23 * V_17 = V_2 -> V_16 . V_17 ;
F_22 ( V_17 , V_139 , V_29 ) ;
}
static void F_38 ( struct V_27 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_23 * V_17 = V_2 -> V_16 . V_17 ;
F_39 ( V_17 , V_140 , V_29 ) ;
}
static void F_40 ( struct V_27 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_23 * V_17 = V_2 -> V_16 . V_17 ;
F_41 ( V_17 , V_140 , V_29 ) ;
}
static void F_42 ( struct V_27 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_23 * V_17 = V_2 -> V_16 . V_17 ;
F_22 ( V_17 , V_139 , V_31 ) ;
}
static void F_43 ( struct V_27 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_23 * V_17 = V_2 -> V_16 . V_17 ;
F_39 ( V_17 , V_140 , V_31 ) ;
}
static void F_44 ( struct V_27 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_23 * V_17 = V_2 -> V_16 . V_17 ;
F_41 ( V_17 , V_140 , V_31 ) ;
}
static void F_45 ( struct V_27 * V_9 )
{
}
static void F_46 ( struct V_27 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_23 * V_17 = V_2 -> V_16 . V_17 ;
F_39 ( V_17 , V_152 , 0x8000 ) ;
}
static T_1 F_47 ( struct V_27 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_23 * V_17 = V_2 -> V_16 . V_17 ;
return ( T_1 ) F_48 ( V_17 , V_139 ) ;
}
static void F_49 ( struct V_27 * V_9 , T_1 V_153 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_23 * V_17 = V_2 -> V_16 . V_17 ;
F_22 ( V_17 , V_139 , V_153 & 0xffff ) ;
}
static void F_50 ( struct V_27 * V_9 , T_1 V_153 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
F_51 ( V_2 -> V_9 , L_1 , V_153 ) ;
}
static int F_52 ( struct V_27 * V_9 , void * V_154 , int * V_155 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
if ( * V_155 < sizeof( T_2 ) + sizeof( T_3 ) + 1 )
return - V_11 ;
F_53 ( V_154 , V_2 -> V_16 . V_17 , sizeof( T_2 ) ) ;
V_154 = ( char * ) V_154 + sizeof( T_2 ) ;
F_53 ( V_154 , V_2 -> V_16 . V_18 , sizeof( T_3 ) ) ;
V_154 = ( char * ) V_154 + sizeof( T_3 ) ;
F_53 ( V_154 , V_2 -> V_16 . V_20 , 1 ) ;
return 0 ;
}
static int F_54 ( struct V_27 * V_9 )
{
return sizeof( T_2 ) + sizeof( T_3 ) + 1 ;
}
static void F_55 ( struct V_27 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_9 ) ;
T_2 V_23 * V_17 = V_2 -> V_16 . V_17 ;
const struct V_4 * V_5 = V_2 -> V_5 ;
T_3 V_23 * V_18 = V_2 -> V_16 . V_18 ;
V_42 V_23 * V_156 ;
V_42 V_23 * V_157 ;
V_42 V_23 * V_158 ;
V_42 V_23 * V_159 ;
V_159 = V_2 -> V_160 + ( ( V_5 -> V_40 - 1 ) * sizeof( V_42 ) ) ;
V_157 = V_156 = ( V_42 V_23 * )
( ( F_26 ( V_18 , V_76 . V_89 ) - V_2 -> V_43 ) +
V_2 -> V_38 ) ;
V_158 = ( V_157 == V_2 -> V_160 ) ? V_159 : V_157 - 1 ;
while ( ( F_56 ( V_158 ) & V_161 ) != 0 ) {
V_157 = V_158 ;
V_158 = ( V_158 == V_2 -> V_160 ) ? V_159 : V_158 - 1 ;
if ( V_157 == V_156 )
break;
}
F_20 ( V_18 , V_76 . V_89 ,
( V_162 ) ( ( ( void * ) V_157 - V_2 -> V_38 ) +
V_2 -> V_43 ) ) ;
V_2 -> V_163 = V_157 ;
F_24 ( V_17 , V_73 , V_75 ) ;
F_57 ( 10 ) ;
F_18 ( V_17 , V_73 , V_75 ) ;
F_1 ( V_2 , V_164 ) ;
}
