static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) && ! F_3 ( V_2 ) ;
}
static struct V_3 F_4 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
T_1 V_5 ;
V_5 = F_5 ( V_6 ) ;
V_4 . V_7 = ( V_5 & 0x7 ) + 1 ;
switch ( ( V_5 & 0xF0 ) >> 4 ) {
case 0x0 :
V_4 . V_8 = 8 ;
break;
case 0x1 :
V_4 . V_8 = 16 ;
break;
case 0x2 :
V_4 . V_8 = 20 ;
break;
case 0x3 :
V_4 . V_8 = 24 ;
break;
case 0x4 :
V_4 . V_8 = 32 ;
break;
default:
F_6 ( V_2 -> V_9 , L_1 ,
( int ) V_5 ) ;
V_4 . V_8 = 16 ;
}
if ( V_5 & 0x4000 )
V_4 . V_10 = 44100 ;
else
V_4 . V_10 = 48000 ;
V_4 . V_10 *= ( ( V_5 >> 11 ) & 0x7 ) + 1 ;
V_4 . V_10 /= ( ( V_5 >> 8 ) & 0x7 ) + 1 ;
V_5 = F_5 ( V_11 ) ;
V_4 . V_12 = V_5 & 0xff ;
V_4 . V_13 = ( V_5 >> 8 ) & 0xff ;
return V_4 ;
}
void F_7 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_8 ( V_15 , struct V_1 ,
V_16 ) ;
struct V_17 * V_9 = V_2 -> V_18 ;
struct V_3 V_19 = F_4 ( V_2 ) ;
struct V_20 * V_21 ;
bool V_22 = false ;
if ( V_2 -> V_23 . V_24 [ 0 ] . V_7 != V_19 . V_7 ||
V_2 -> V_23 . V_24 [ 0 ] . V_10 != V_19 . V_10 ||
V_2 -> V_23 . V_24 [ 0 ] . V_8 != V_19 . V_8 ||
V_2 -> V_23 . V_24 [ 0 ] . V_12 != V_19 . V_12 ||
V_2 -> V_23 . V_24 [ 0 ] . V_13 != V_19 . V_13 ) {
V_2 -> V_23 . V_24 [ 0 ] = V_19 ;
V_22 = true ;
}
F_9 (encoder, &dev->mode_config.encoder_list, head) {
if ( ! F_10 ( V_21 ) )
continue;
if ( V_22 || F_11 ( V_21 ) )
F_12 ( V_21 ) ;
}
}
void F_13 ( struct V_1 * V_2 ,
struct V_3 * V_24 ,
T_2 V_25 )
{
T_3 V_26 = F_5 ( V_27 ) ;
if ( ! V_24 )
return;
if ( V_25 ) {
V_26 |= V_28 ;
if ( V_25 & 1 )
V_26 |= V_29 ;
if ( V_25 & 2 )
V_26 |= V_30 ;
if ( V_25 & 4 )
V_26 |= V_31 ;
if ( V_25 & 8 )
V_26 |= V_32 ;
} else {
V_26 &= ~ ( V_28 |
V_29 |
V_30 |
V_31 |
V_32 ) ;
}
F_14 ( V_27 , V_26 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
if ( ! V_33 || ! F_1 ( V_2 ) )
return 0 ;
V_2 -> V_23 . V_34 = true ;
V_2 -> V_23 . V_35 = 1 ;
V_2 -> V_23 . V_24 [ 0 ] . V_7 = - 1 ;
V_2 -> V_23 . V_24 [ 0 ] . V_10 = - 1 ;
V_2 -> V_23 . V_24 [ 0 ] . V_8 = - 1 ;
V_2 -> V_23 . V_24 [ 0 ] . V_12 = 0 ;
V_2 -> V_23 . V_24 [ 0 ] . V_13 = 0 ;
V_2 -> V_23 . V_24 [ 0 ] . V_36 = 0 ;
F_13 ( V_2 , & V_2 -> V_23 . V_24 [ 0 ] , 0 ) ;
return 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_23 . V_34 )
return;
F_13 ( V_2 , & V_2 -> V_23 . V_24 [ 0 ] , 0 ) ;
V_2 -> V_23 . V_34 = false ;
}
struct V_3 * F_17 ( struct V_1 * V_2 )
{
return & V_2 -> V_23 . V_24 [ 0 ] ;
}
static void F_18 ( T_1 clock , int * V_37 , int * V_38 , int V_39 )
{
int V_40 , V_41 ;
unsigned long div , V_42 ;
V_40 = 128 * V_39 ;
V_41 = clock * 1000 ;
div = F_19 ( V_40 , V_41 ) ;
V_40 /= div ;
V_41 /= div ;
V_42 = ( ( 128 * V_39 / 1000 ) + ( V_40 - 1 ) ) / V_40 ;
V_40 *= V_42 ;
V_41 *= V_42 ;
if ( V_40 < ( 128 * V_39 / 1500 ) )
F_20 ( V_43 L_2 ) ;
if ( V_40 > ( 128 * V_39 / 300 ) )
F_20 ( V_43 L_3 ) ;
* V_38 = V_40 ;
* V_37 = V_41 ;
F_21 ( L_4 ,
* V_38 , * V_37 , V_39 ) ;
}
struct V_44 F_22 ( T_1 clock )
{
struct V_44 V_45 ;
T_2 V_46 ;
for ( V_46 = 0 ; V_46 < F_23 ( V_47 ) ; V_46 ++ ) {
if ( V_47 [ V_46 ] . clock == clock )
return V_47 [ V_46 ] ;
}
F_18 ( clock , & V_45 . V_48 , & V_45 . V_49 , 32000 ) ;
F_18 ( clock , & V_45 . V_50 , & V_45 . V_51 , 44100 ) ;
F_18 ( clock , & V_45 . V_52 , & V_45 . V_53 , 48000 ) ;
return V_45 ;
}
void F_24 ( struct V_20 * V_21 , T_1 clock )
{
struct V_17 * V_9 = V_21 -> V_9 ;
struct V_1 * V_2 = V_9 -> V_54 ;
struct V_44 V_55 = F_22 ( clock ) ;
struct V_56 * V_56 = F_25 ( V_21 ) ;
struct V_57 * V_58 = V_56 -> V_59 ;
T_1 V_60 = V_58 -> V_61 -> V_60 ;
F_26 ( V_62 + V_60 ,
F_27 ( V_55 . V_48 ) ,
~ V_63 ) ;
F_26 ( V_64 + V_60 ,
F_28 ( V_55 . V_49 ) ,
~ V_65 ) ;
F_26 ( V_66 + V_60 ,
F_29 ( V_55 . V_50 ) ,
~ V_67 ) ;
F_26 ( V_68 + V_60 ,
F_30 ( V_55 . V_51 ) ,
~ V_69 ) ;
F_26 ( V_70 + V_60 ,
F_31 ( V_55 . V_52 ) ,
~ V_71 ) ;
F_26 ( V_72 + V_60 ,
F_32 ( V_55 . V_53 ) ,
~ V_73 ) ;
}
void F_33 ( struct V_20 * V_21 , void * V_74 ,
T_4 V_75 )
{
struct V_17 * V_9 = V_21 -> V_9 ;
struct V_1 * V_2 = V_9 -> V_54 ;
struct V_56 * V_56 = F_25 ( V_21 ) ;
struct V_57 * V_58 = V_56 -> V_59 ;
T_1 V_60 = V_58 -> V_61 -> V_60 ;
T_5 * V_76 = V_74 + 3 ;
T_5 * V_77 = V_74 ;
F_14 ( V_78 + V_60 ,
V_76 [ 0x0 ] | ( V_76 [ 0x1 ] << 8 ) | ( V_76 [ 0x2 ] << 16 ) | ( V_76 [ 0x3 ] << 24 ) ) ;
F_14 ( V_79 + V_60 ,
V_76 [ 0x4 ] | ( V_76 [ 0x5 ] << 8 ) | ( V_76 [ 0x6 ] << 16 ) | ( V_76 [ 0x7 ] << 24 ) ) ;
F_14 ( V_80 + V_60 ,
V_76 [ 0x8 ] | ( V_76 [ 0x9 ] << 8 ) | ( V_76 [ 0xA ] << 16 ) | ( V_76 [ 0xB ] << 24 ) ) ;
F_14 ( V_81 + V_60 ,
V_76 [ 0xC ] | ( V_76 [ 0xD ] << 8 ) | ( V_77 [ 1 ] << 24 ) ) ;
}
static void F_34 ( struct V_20 * V_21 ,
const void * V_74 , T_4 V_75 )
{
struct V_17 * V_9 = V_21 -> V_9 ;
struct V_1 * V_2 = V_9 -> V_54 ;
struct V_56 * V_56 = F_25 ( V_21 ) ;
struct V_57 * V_58 = V_56 -> V_59 ;
T_1 V_60 = V_58 -> V_61 -> V_60 ;
const T_2 * V_76 = V_74 + 3 ;
F_14 ( V_82 + V_60 ,
V_76 [ 0x0 ] | ( V_76 [ 0x1 ] << 8 ) | ( V_76 [ 0x2 ] << 16 ) | ( V_76 [ 0x3 ] << 24 ) ) ;
F_14 ( V_83 + V_60 ,
V_76 [ 0x4 ] | ( V_76 [ 0x5 ] << 8 ) | ( V_76 [ 0x6 ] << 16 ) | ( V_76 [ 0x8 ] << 24 ) ) ;
}
static bool F_35 ( struct V_20 * V_21 )
{
struct V_17 * V_9 = V_21 -> V_9 ;
struct V_1 * V_2 = V_9 -> V_54 ;
struct V_56 * V_56 = F_25 ( V_21 ) ;
struct V_57 * V_58 = V_56 -> V_59 ;
T_1 V_60 = V_58 -> V_61 -> V_60 ;
return ( F_5 ( V_84 + V_60 ) & 0x10 ) != 0 ;
}
int F_11 ( struct V_20 * V_21 )
{
struct V_56 * V_56 = F_25 ( V_21 ) ;
struct V_57 * V_58 = V_56 -> V_59 ;
int V_4 , V_85 ;
if ( ! V_58 -> V_61 || ! V_58 -> V_61 -> V_34 )
return 0 ;
V_4 = F_35 ( V_21 ) ;
V_85 = V_58 -> V_61 -> V_86 != V_4 ;
V_58 -> V_61 -> V_86 = V_4 ;
return V_85 ;
}
void F_36 ( struct V_20 * V_21 )
{
struct V_17 * V_9 = V_21 -> V_9 ;
struct V_1 * V_2 = V_9 -> V_54 ;
struct V_56 * V_56 = F_25 ( V_21 ) ;
struct V_57 * V_58 = V_56 -> V_59 ;
T_1 V_60 = V_58 -> V_61 -> V_60 ;
bool V_87 = false ;
T_3 V_5 ;
if ( ! V_87 ||
F_35 ( V_21 ) )
V_5 = 0 ;
else
V_5 = V_88 ;
F_26 ( V_89 + V_60 ,
V_5 , ~ V_88 ) ;
}
void F_37 ( struct V_20 * V_21 , T_3 clock )
{
struct V_17 * V_9 = V_21 -> V_9 ;
struct V_1 * V_2 = V_9 -> V_54 ;
struct V_56 * V_56 = F_25 ( V_21 ) ;
struct V_57 * V_58 = V_56 -> V_59 ;
T_3 V_90 = 24000 ;
T_3 V_91 = clock / V_90 ;
T_3 V_92 ;
T_3 V_93 = clock ;
T_3 V_94 ;
T_3 V_95 ;
if ( ! V_58 || ! V_58 -> V_61 )
return;
if ( V_91 >= 8 ) {
V_92 = 192 * 1000 ;
V_94 = 3 ;
} else if ( V_91 >= 4 ) {
V_92 = 96 * 1000 ;
V_94 = 2 ;
} else if ( V_91 >= 2 ) {
V_92 = 48 * 1000 ;
V_94 = 1 ;
} else {
V_92 = 24 * 1000 ;
V_94 = 0 ;
}
if ( F_38 ( V_2 ) ) {
if ( V_58 -> V_96 == 0 ) {
V_95 = F_5 ( V_97 ) & ~ V_98 ;
V_95 |= F_39 ( V_94 ) ;
F_14 ( V_97 , V_95 ) ;
F_14 ( V_99 , V_92 ) ;
F_14 ( V_100 , V_93 ) ;
F_14 ( V_101 , 0 ) ;
} else {
V_95 = F_5 ( V_102 ) & ~ V_98 ;
V_95 |= F_39 ( V_94 ) ;
F_14 ( V_102 , V_95 ) ;
F_14 ( V_103 , V_92 ) ;
F_14 ( V_104 , V_93 ) ;
F_14 ( V_101 , 1 ) ;
}
} else {
if ( V_58 -> V_96 == 0 ) {
F_14 ( V_99 , V_90 * 100 ) ;
F_14 ( V_100 , clock * 100 ) ;
F_14 ( V_101 , 0 ) ;
} else {
F_14 ( V_103 , V_90 * 100 ) ;
F_14 ( V_104 , clock * 100 ) ;
F_14 ( V_101 , 1 ) ;
}
}
}
void F_40 ( struct V_20 * V_21 , struct V_105 * V_106 )
{
struct V_17 * V_9 = V_21 -> V_9 ;
struct V_1 * V_2 = V_9 -> V_54 ;
struct V_56 * V_56 = F_25 ( V_21 ) ;
struct V_57 * V_58 = V_56 -> V_59 ;
T_2 V_74 [ V_107 + V_108 ] ;
struct V_109 V_76 ;
T_1 V_60 ;
T_1 V_110 ;
T_6 V_111 ;
if ( ! V_58 || ! V_58 -> V_61 )
return;
if ( ! V_58 -> V_61 -> V_34 )
return;
V_60 = V_58 -> V_61 -> V_60 ;
V_58 -> V_61 -> V_24 = F_17 ( V_2 ) ;
F_13 ( V_2 , V_58 -> V_61 -> V_24 , 0xf ) ;
F_37 ( V_21 , V_106 -> clock ) ;
F_26 ( V_89 + V_60 ,
V_112 |
F_41 ( 1 ) |
F_42 ( 3 ) |
V_113 ,
~ ( V_112 |
V_114 |
V_115 |
V_113 ) ) ;
V_110 = F_43 ( V_2 ) ? V_116 :
V_117 ;
F_26 ( V_110 + V_60 ,
V_118 |
V_119 ,
~ ( V_118 |
V_119 ) ) ;
F_44 ( V_120 + V_60 ,
V_121 |
V_122 |
V_123 ) ;
F_44 ( V_124 + V_60 ,
V_125 |
V_126 |
V_127 |
V_128 ) ;
F_26 ( V_129 + V_60 ,
F_45 ( 2 ) |
F_46 ( 2 ) ,
~ ( V_130 |
V_131 ) ) ;
F_47 ( V_132 + V_60 ,
~ V_133 ) ;
V_111 = F_48 ( & V_76 , V_106 ) ;
if ( V_111 < 0 ) {
F_49 ( L_5 , V_111 ) ;
return;
}
V_111 = F_50 ( & V_76 , V_74 , sizeof( V_74 ) ) ;
if ( V_111 < 0 ) {
F_49 ( L_6 , V_111 ) ;
return;
}
F_33 ( V_21 , V_74 , sizeof( V_74 ) ) ;
F_47 ( V_134 + V_60 ,
~ ( V_135 |
V_136 |
V_137 |
V_138 |
V_139 |
V_140 |
V_141 ) ) ;
F_24 ( V_21 , V_106 -> clock ) ;
F_26 ( V_142 + V_60 ,
F_51 ( 1 ) ,
~ ( V_143 |
V_144 ) ) ;
F_26 ( V_145 + V_60 ,
F_52 ( 2 ) ,
~ V_146 ) ;
F_14 ( V_147 + V_60 , 0x00FFFFFF ) ;
F_14 ( V_148 + V_60 , 0x007FFFFF ) ;
F_14 ( V_149 + V_60 , 0x00000001 ) ;
F_14 ( V_150 + V_60 , 0x00000001 ) ;
F_13 ( V_2 , V_58 -> V_61 -> V_24 , 0xf ) ;
}
void F_12 ( struct V_20 * V_21 )
{
struct V_17 * V_9 = V_21 -> V_9 ;
struct V_1 * V_2 = V_9 -> V_54 ;
struct V_56 * V_56 = F_25 ( V_21 ) ;
struct V_57 * V_58 = V_56 -> V_59 ;
struct V_3 V_23 = F_4 ( V_2 ) ;
T_5 V_74 [ V_107 + V_151 ] ;
struct V_152 V_76 ;
T_1 V_60 ;
T_1 V_5 ;
T_6 V_111 ;
if ( ! V_58 -> V_61 || ! V_58 -> V_61 -> V_34 )
return;
V_60 = V_58 -> V_61 -> V_60 ;
F_21 ( L_7 ,
F_35 ( V_21 ) ? L_8 : L_9 ,
V_23 . V_7 , V_23 . V_10 , V_23 . V_8 ) ;
F_21 ( L_10 ,
( int ) V_23 . V_12 , ( int ) V_23 . V_13 ) ;
V_111 = F_53 ( & V_76 ) ;
if ( V_111 < 0 ) {
F_49 ( L_11 ) ;
return;
}
V_76 . V_7 = V_23 . V_7 ;
V_111 = F_54 ( & V_76 , V_74 , sizeof( V_74 ) ) ;
if ( V_111 < 0 ) {
F_49 ( L_12 ) ;
return;
}
V_5 = F_5 ( V_89 + V_60 ) ;
if ( V_5 & V_88 )
F_14 ( V_89 + V_60 ,
V_5 & ~ V_88 ) ;
F_44 ( V_153 + V_60 ,
V_154 ) ;
F_47 ( V_124 + V_60 ,
~ V_155 ) ;
F_34 ( V_21 , V_74 , sizeof( V_74 ) ) ;
F_44 ( V_124 + V_60 ,
V_156 |
V_128 ) ;
}
void F_55 ( struct V_20 * V_21 , bool V_157 )
{
struct V_17 * V_9 = V_21 -> V_9 ;
struct V_1 * V_2 = V_9 -> V_54 ;
struct V_56 * V_56 = F_25 ( V_21 ) ;
struct V_57 * V_58 = V_56 -> V_59 ;
T_3 V_158 = V_154 ;
if ( ! V_58 || ! V_58 -> V_61 )
return;
if ( V_157 && V_58 -> V_61 -> V_34 )
return;
if ( ! V_157 && ! V_58 -> V_61 -> V_34 )
return;
if ( ! V_157 && V_58 -> V_61 -> V_24 ) {
F_13 ( V_2 , V_58 -> V_61 -> V_24 , 0 ) ;
V_58 -> V_61 -> V_24 = NULL ;
}
if ( ! F_43 ( V_2 ) ) {
if ( V_157 )
V_158 |= V_159 ;
switch ( V_56 -> V_160 ) {
case V_161 :
if ( V_157 ) {
F_44 ( V_162 , V_163 ) ;
V_158 |= F_56 ( V_164 ) ;
} else {
F_47 ( V_162 , ~ V_163 ) ;
}
break;
case V_165 :
if ( V_157 ) {
F_44 ( V_166 , V_167 ) ;
V_158 |= F_56 ( V_168 ) ;
} else {
F_47 ( V_166 , ~ V_167 ) ;
}
break;
case V_169 :
if ( V_157 ) {
F_44 ( V_170 , V_171 ) ;
V_158 |= F_56 ( V_172 ) ;
} else {
F_47 ( V_170 , ~ V_171 ) ;
}
break;
case V_173 :
if ( V_157 )
V_158 |= F_56 ( V_174 ) ;
break;
default:
F_6 ( V_2 -> V_9 , L_13 ,
V_56 -> V_160 ) ;
break;
}
F_14 ( V_153 + V_58 -> V_61 -> V_60 , V_158 ) ;
}
if ( V_2 -> V_175 . V_176 ) {
if ( V_157 )
F_57 ( V_2 , V_58 -> V_61 -> V_36 ) ;
else
F_58 ( V_2 , V_58 -> V_61 -> V_36 ) ;
}
V_58 -> V_61 -> V_34 = V_157 ;
F_21 ( L_14 ,
V_157 ? L_15 : L_16 , V_58 -> V_61 -> V_60 , V_56 -> V_160 ) ;
}
