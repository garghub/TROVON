static void F_1 ( T_1 clock , int * V_1 , int * V_2 , int V_3 )
{
int V_4 , V_5 ;
unsigned long div , V_6 ;
V_4 = 128 * V_3 ;
V_5 = clock * 1000 ;
div = F_2 ( V_4 , V_5 ) ;
V_4 /= div ;
V_5 /= div ;
V_6 = ( ( 128 * V_3 / 1000 ) + ( V_4 - 1 ) ) / V_4 ;
V_4 *= V_6 ;
V_5 *= V_6 ;
if ( V_4 < ( 128 * V_3 / 1500 ) )
F_3 ( V_7 L_1 ) ;
if ( V_4 > ( 128 * V_3 / 300 ) )
F_3 ( V_7 L_2 ) ;
* V_2 = V_4 ;
* V_1 = V_5 ;
F_4 ( L_3 ,
* V_2 , * V_1 , V_3 ) ;
}
struct V_8 F_5 ( T_1 clock )
{
struct V_8 V_9 ;
T_2 V_10 ;
for ( V_10 = 0 ; V_10 < F_6 ( V_11 ) ; V_10 ++ ) {
if ( V_11 [ V_10 ] . clock == clock )
return V_11 [ V_10 ] ;
}
F_1 ( clock , & V_9 . V_12 , & V_9 . V_13 , 32000 ) ;
F_1 ( clock , & V_9 . V_14 , & V_9 . V_15 , 44100 ) ;
F_1 ( clock , & V_9 . V_16 , & V_9 . V_17 , 48000 ) ;
return V_9 ;
}
void F_7 ( struct V_18 * V_19 , T_1 clock )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_8 V_25 = F_5 ( clock ) ;
struct V_26 * V_26 = F_8 ( V_19 ) ;
struct V_27 * V_28 = V_26 -> V_29 ;
T_1 V_30 = V_28 -> V_31 -> V_30 ;
F_9 ( V_32 + V_30 ,
F_10 ( V_25 . V_12 ) ,
~ V_33 ) ;
F_9 ( V_34 + V_30 ,
F_11 ( V_25 . V_13 ) ,
~ V_35 ) ;
F_9 ( V_36 + V_30 ,
F_12 ( V_25 . V_14 ) ,
~ V_37 ) ;
F_9 ( V_38 + V_30 ,
F_13 ( V_25 . V_15 ) ,
~ V_39 ) ;
F_9 ( V_40 + V_30 ,
F_14 ( V_25 . V_16 ) ,
~ V_41 ) ;
F_9 ( V_42 + V_30 ,
F_15 ( V_25 . V_17 ) ,
~ V_43 ) ;
}
void F_16 ( struct V_18 * V_19 , void * V_44 ,
T_3 V_45 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_26 * V_26 = F_8 ( V_19 ) ;
struct V_27 * V_28 = V_26 -> V_29 ;
T_1 V_30 = V_28 -> V_31 -> V_30 ;
T_4 * V_46 = V_44 + 3 ;
T_4 * V_47 = V_44 ;
F_17 ( V_48 + V_30 ,
V_46 [ 0x0 ] | ( V_46 [ 0x1 ] << 8 ) | ( V_46 [ 0x2 ] << 16 ) | ( V_46 [ 0x3 ] << 24 ) ) ;
F_17 ( V_49 + V_30 ,
V_46 [ 0x4 ] | ( V_46 [ 0x5 ] << 8 ) | ( V_46 [ 0x6 ] << 16 ) | ( V_46 [ 0x7 ] << 24 ) ) ;
F_17 ( V_50 + V_30 ,
V_46 [ 0x8 ] | ( V_46 [ 0x9 ] << 8 ) | ( V_46 [ 0xA ] << 16 ) | ( V_46 [ 0xB ] << 24 ) ) ;
F_17 ( V_51 + V_30 ,
V_46 [ 0xC ] | ( V_46 [ 0xD ] << 8 ) | ( V_47 [ 1 ] << 24 ) ) ;
}
static void F_18 ( struct V_18 * V_19 ,
const void * V_44 , T_3 V_45 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_26 * V_26 = F_8 ( V_19 ) ;
struct V_27 * V_28 = V_26 -> V_29 ;
T_1 V_30 = V_28 -> V_31 -> V_30 ;
const T_2 * V_46 = V_44 + 3 ;
F_17 ( V_52 + V_30 ,
V_46 [ 0x0 ] | ( V_46 [ 0x1 ] << 8 ) | ( V_46 [ 0x2 ] << 16 ) | ( V_46 [ 0x3 ] << 24 ) ) ;
F_17 ( V_53 + V_30 ,
V_46 [ 0x4 ] | ( V_46 [ 0x5 ] << 8 ) | ( V_46 [ 0x6 ] << 16 ) | ( V_46 [ 0x8 ] << 24 ) ) ;
}
static bool F_19 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_26 * V_26 = F_8 ( V_19 ) ;
struct V_27 * V_28 = V_26 -> V_29 ;
T_1 V_30 = V_28 -> V_31 -> V_30 ;
return ( F_20 ( V_54 + V_30 ) & 0x10 ) != 0 ;
}
int F_21 ( struct V_18 * V_19 )
{
struct V_26 * V_26 = F_8 ( V_19 ) ;
struct V_27 * V_28 = V_26 -> V_29 ;
int V_55 , V_56 ;
if ( ! V_28 -> V_31 || ! V_28 -> V_31 -> V_57 )
return 0 ;
V_55 = F_19 ( V_19 ) ;
V_56 = V_28 -> V_31 -> V_58 != V_55 ;
V_28 -> V_31 -> V_58 = V_55 ;
return V_56 ;
}
void F_22 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_26 * V_26 = F_8 ( V_19 ) ;
struct V_27 * V_28 = V_26 -> V_29 ;
T_1 V_30 = V_28 -> V_31 -> V_30 ;
bool V_59 = false ;
T_5 V_60 ;
if ( ! V_59 ||
F_19 ( V_19 ) )
V_60 = 0 ;
else
V_60 = V_61 ;
F_9 ( V_62 + V_30 ,
V_60 , ~ V_61 ) ;
}
void F_23 ( struct V_18 * V_19 , T_5 clock )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_26 * V_26 = F_8 ( V_19 ) ;
struct V_27 * V_28 = V_26 -> V_29 ;
T_5 V_63 = 24000 ;
T_5 V_64 = clock / V_63 ;
T_5 V_65 ;
T_5 V_66 = clock ;
T_5 V_67 ;
T_5 V_68 ;
if ( ! V_28 || ! V_28 -> V_31 )
return;
if ( V_64 >= 8 ) {
V_65 = 192 * 1000 ;
V_67 = 3 ;
} else if ( V_64 >= 4 ) {
V_65 = 96 * 1000 ;
V_67 = 2 ;
} else if ( V_64 >= 2 ) {
V_65 = 48 * 1000 ;
V_67 = 1 ;
} else {
V_65 = 24 * 1000 ;
V_67 = 0 ;
}
if ( F_24 ( V_23 ) ) {
if ( V_28 -> V_69 == 0 ) {
V_68 = F_20 ( V_70 ) & ~ V_71 ;
V_68 |= F_25 ( V_67 ) ;
F_17 ( V_70 , V_68 ) ;
F_17 ( V_72 , V_65 ) ;
F_17 ( V_73 , V_66 ) ;
F_17 ( V_74 , 0 ) ;
} else {
V_68 = F_20 ( V_75 ) & ~ V_71 ;
V_68 |= F_25 ( V_67 ) ;
F_17 ( V_75 , V_68 ) ;
F_17 ( V_76 , V_65 ) ;
F_17 ( V_77 , V_66 ) ;
F_17 ( V_74 , 1 ) ;
}
} else {
if ( V_28 -> V_69 == 0 ) {
F_17 ( V_72 , V_63 * 100 ) ;
F_17 ( V_73 , clock * 100 ) ;
F_17 ( V_74 , 0 ) ;
} else {
F_17 ( V_76 , V_63 * 100 ) ;
F_17 ( V_77 , clock * 100 ) ;
F_17 ( V_74 , 1 ) ;
}
}
}
void F_26 ( struct V_18 * V_19 , struct V_78 * V_79 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_26 * V_26 = F_8 ( V_19 ) ;
struct V_27 * V_28 = V_26 -> V_29 ;
T_2 V_44 [ V_80 + V_81 ] ;
struct V_82 V_46 ;
T_1 V_30 ;
T_1 V_83 ;
T_6 V_84 ;
if ( ! V_28 || ! V_28 -> V_31 )
return;
if ( ! V_28 -> V_31 -> V_57 )
return;
V_30 = V_28 -> V_31 -> V_30 ;
V_28 -> V_31 -> V_85 = F_27 ( V_23 ) ;
F_28 ( V_23 , V_28 -> V_31 -> V_85 , false ) ;
F_23 ( V_19 , V_79 -> clock ) ;
F_9 ( V_62 + V_30 ,
V_86 |
F_29 ( 1 ) |
F_30 ( 3 ) |
V_87 ,
~ ( V_86 |
V_88 |
V_89 |
V_87 ) ) ;
V_83 = F_31 ( V_23 ) ? V_90 :
V_91 ;
F_9 ( V_83 + V_30 ,
V_92 |
V_93 ,
~ ( V_92 |
V_93 ) ) ;
F_32 ( V_94 + V_30 ,
V_95 |
V_96 |
V_97 ) ;
F_32 ( V_98 + V_30 ,
V_99 |
V_100 |
V_101 |
V_102 ) ;
F_9 ( V_103 + V_30 ,
F_33 ( 2 ) |
F_34 ( 2 ) ,
~ ( V_104 |
V_105 ) ) ;
F_35 ( V_106 + V_30 ,
~ V_107 ) ;
V_84 = F_36 ( & V_46 , V_79 ) ;
if ( V_84 < 0 ) {
F_37 ( L_4 , V_84 ) ;
return;
}
V_84 = F_38 ( & V_46 , V_44 , sizeof( V_44 ) ) ;
if ( V_84 < 0 ) {
F_37 ( L_5 , V_84 ) ;
return;
}
F_16 ( V_19 , V_44 , sizeof( V_44 ) ) ;
F_35 ( V_108 + V_30 ,
~ ( V_109 |
V_110 |
V_111 |
V_112 |
V_113 |
V_114 |
V_115 ) ) ;
F_7 ( V_19 , V_79 -> clock ) ;
F_9 ( V_116 + V_30 ,
F_39 ( 1 ) ,
~ ( V_117 |
V_118 ) ) ;
F_9 ( V_119 + V_30 ,
F_40 ( 2 ) ,
~ V_120 ) ;
F_17 ( V_121 + V_30 , 0x00FFFFFF ) ;
F_17 ( V_122 + V_30 , 0x007FFFFF ) ;
F_17 ( V_123 + V_30 , 0x00000001 ) ;
F_17 ( V_124 + V_30 , 0x00000001 ) ;
F_28 ( V_23 , V_28 -> V_31 -> V_85 , true ) ;
}
void F_41 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_26 * V_26 = F_8 ( V_19 ) ;
struct V_27 * V_28 = V_26 -> V_29 ;
struct V_125 V_126 = F_42 ( V_23 ) ;
T_4 V_44 [ V_80 + V_127 ] ;
struct V_128 V_46 ;
T_1 V_30 ;
T_1 V_60 ;
T_6 V_84 ;
if ( ! V_28 -> V_31 || ! V_28 -> V_31 -> V_57 )
return;
V_30 = V_28 -> V_31 -> V_30 ;
F_4 ( L_6 ,
F_19 ( V_19 ) ? L_7 : L_8 ,
V_126 . V_129 , V_126 . V_130 , V_126 . V_131 ) ;
F_4 ( L_9 ,
( int ) V_126 . V_132 , ( int ) V_126 . V_133 ) ;
V_84 = F_43 ( & V_46 ) ;
if ( V_84 < 0 ) {
F_37 ( L_10 ) ;
return;
}
V_46 . V_129 = V_126 . V_129 ;
V_84 = F_44 ( & V_46 , V_44 , sizeof( V_44 ) ) ;
if ( V_84 < 0 ) {
F_37 ( L_11 ) ;
return;
}
V_60 = F_20 ( V_62 + V_30 ) ;
if ( V_60 & V_61 )
F_17 ( V_62 + V_30 ,
V_60 & ~ V_61 ) ;
F_32 ( V_134 + V_30 ,
V_135 ) ;
F_35 ( V_98 + V_30 ,
~ V_136 ) ;
F_18 ( V_19 , V_44 , sizeof( V_44 ) ) ;
F_32 ( V_98 + V_30 ,
V_137 |
V_102 ) ;
}
void F_45 ( struct V_18 * V_19 , bool V_138 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_26 * V_26 = F_8 ( V_19 ) ;
struct V_27 * V_28 = V_26 -> V_29 ;
T_5 V_139 = V_135 ;
if ( ! V_28 || ! V_28 -> V_31 )
return;
if ( V_138 && V_28 -> V_31 -> V_57 )
return;
if ( ! V_138 && ! V_28 -> V_31 -> V_57 )
return;
if ( ! F_31 ( V_23 ) ) {
if ( V_138 )
V_139 |= V_140 ;
switch ( V_26 -> V_141 ) {
case V_142 :
if ( V_138 ) {
F_32 ( V_143 , V_144 ) ;
V_139 |= F_46 ( V_145 ) ;
} else {
F_35 ( V_143 , ~ V_144 ) ;
}
break;
case V_146 :
if ( V_138 ) {
F_32 ( V_147 , V_148 ) ;
V_139 |= F_46 ( V_149 ) ;
} else {
F_35 ( V_147 , ~ V_148 ) ;
}
break;
case V_150 :
if ( V_138 ) {
F_32 ( V_151 , V_152 ) ;
V_139 |= F_46 ( V_153 ) ;
} else {
F_35 ( V_151 , ~ V_152 ) ;
}
break;
case V_154 :
if ( V_138 )
V_139 |= F_46 ( V_155 ) ;
break;
default:
F_47 ( V_23 -> V_21 , L_12 ,
V_26 -> V_141 ) ;
break;
}
F_17 ( V_134 + V_28 -> V_31 -> V_30 , V_139 ) ;
}
if ( V_23 -> V_156 . V_157 ) {
if ( V_138 )
F_48 ( V_23 , V_28 -> V_31 -> V_158 ) ;
else
F_49 ( V_23 , V_28 -> V_31 -> V_158 ) ;
}
V_28 -> V_31 -> V_57 = V_138 ;
F_4 ( L_13 ,
V_138 ? L_14 : L_15 , V_28 -> V_31 -> V_30 , V_26 -> V_141 ) ;
}
