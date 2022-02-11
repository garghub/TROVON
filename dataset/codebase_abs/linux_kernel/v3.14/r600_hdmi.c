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
static void F_7 ( struct V_18 * V_19 , T_1 clock )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_8 V_25 = F_5 ( clock ) ;
struct V_26 * V_26 = F_8 ( V_19 ) ;
struct V_27 * V_28 = V_26 -> V_29 ;
T_1 V_30 = V_28 -> V_31 -> V_30 ;
F_9 ( V_32 + V_30 , F_10 ( V_25 . V_12 ) ) ;
F_9 ( V_33 + V_30 , V_25 . V_13 ) ;
F_9 ( V_34 + V_30 , F_11 ( V_25 . V_14 ) ) ;
F_9 ( V_35 + V_30 , V_25 . V_15 ) ;
F_9 ( V_36 + V_30 , F_12 ( V_25 . V_16 ) ) ;
F_9 ( V_37 + V_30 , V_25 . V_17 ) ;
}
static void F_13 ( struct V_18 * V_19 ,
void * V_38 , T_3 V_39 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_26 * V_26 = F_8 ( V_19 ) ;
struct V_27 * V_28 = V_26 -> V_29 ;
T_1 V_30 = V_28 -> V_31 -> V_30 ;
T_4 * V_40 = V_38 + 3 ;
T_4 * V_41 = V_38 ;
F_9 ( V_42 + V_30 ,
V_40 [ 0x0 ] | ( V_40 [ 0x1 ] << 8 ) | ( V_40 [ 0x2 ] << 16 ) | ( V_40 [ 0x3 ] << 24 ) ) ;
F_9 ( V_43 + V_30 ,
V_40 [ 0x4 ] | ( V_40 [ 0x5 ] << 8 ) | ( V_40 [ 0x6 ] << 16 ) | ( V_40 [ 0x7 ] << 24 ) ) ;
F_9 ( V_44 + V_30 ,
V_40 [ 0x8 ] | ( V_40 [ 0x9 ] << 8 ) | ( V_40 [ 0xA ] << 16 ) | ( V_40 [ 0xB ] << 24 ) ) ;
F_9 ( V_45 + V_30 ,
V_40 [ 0xC ] | ( V_40 [ 0xD ] << 8 ) | ( V_41 [ 1 ] << 24 ) ) ;
}
static void F_14 ( struct V_18 * V_19 ,
const void * V_38 , T_3 V_39 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_26 * V_26 = F_8 ( V_19 ) ;
struct V_27 * V_28 = V_26 -> V_29 ;
T_1 V_30 = V_28 -> V_31 -> V_30 ;
const T_2 * V_40 = V_38 + 3 ;
F_9 ( V_46 + V_30 ,
V_40 [ 0x0 ] | ( V_40 [ 0x1 ] << 8 ) | ( V_40 [ 0x2 ] << 16 ) | ( V_40 [ 0x3 ] << 24 ) ) ;
F_9 ( V_47 + V_30 ,
V_40 [ 0x4 ] | ( V_40 [ 0x5 ] << 8 ) | ( V_40 [ 0x6 ] << 16 ) | ( V_40 [ 0x8 ] << 24 ) ) ;
}
static bool F_15 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_26 * V_26 = F_8 ( V_19 ) ;
struct V_27 * V_28 = V_26 -> V_29 ;
T_1 V_30 = V_28 -> V_31 -> V_30 ;
return ( F_16 ( V_48 + V_30 ) & 0x10 ) != 0 ;
}
int F_17 ( struct V_18 * V_19 )
{
struct V_26 * V_26 = F_8 ( V_19 ) ;
struct V_27 * V_28 = V_26 -> V_29 ;
int V_49 , V_50 ;
if ( ! V_28 -> V_31 || ! V_28 -> V_31 -> V_51 )
return 0 ;
V_49 = F_15 ( V_19 ) ;
V_50 = V_28 -> V_31 -> V_52 != V_49 ;
V_28 -> V_31 -> V_52 = V_49 ;
return V_50 ;
}
static void F_18 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_26 * V_26 = F_8 ( V_19 ) ;
struct V_27 * V_28 = V_26 -> V_29 ;
T_1 V_30 = V_28 -> V_31 -> V_30 ;
bool V_53 = false ;
T_5 V_54 ;
if ( ! V_53 ||
F_15 ( V_19 ) )
V_54 = 0 ;
else
V_54 = V_55 ;
F_19 ( V_56 + V_30 ,
V_54 , ~ V_55 ) ;
}
static void F_20 ( struct V_18 * V_19 , T_5 clock )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_26 * V_26 = F_8 ( V_19 ) ;
struct V_27 * V_28 = V_26 -> V_29 ;
T_5 V_57 = 24000 ;
T_5 V_58 = clock / V_57 ;
T_5 V_59 ;
T_5 V_60 = clock ;
T_5 V_61 ;
T_5 V_62 ;
if ( ! V_28 || ! V_28 -> V_31 )
return;
if ( V_58 >= 8 ) {
V_59 = 192 * 1000 ;
V_61 = 3 ;
} else if ( V_58 >= 4 ) {
V_59 = 96 * 1000 ;
V_61 = 2 ;
} else if ( V_58 >= 2 ) {
V_59 = 48 * 1000 ;
V_61 = 1 ;
} else {
V_59 = 24 * 1000 ;
V_61 = 0 ;
}
if ( F_21 ( V_23 ) ) {
if ( V_28 -> V_63 == 0 ) {
V_62 = F_16 ( V_64 ) & ~ V_65 ;
V_62 |= F_22 ( V_61 ) ;
F_9 ( V_64 , V_62 ) ;
F_9 ( V_66 , V_59 ) ;
F_9 ( V_67 , V_60 ) ;
F_9 ( V_68 , 0 ) ;
} else {
V_62 = F_16 ( V_69 ) & ~ V_65 ;
V_62 |= F_22 ( V_61 ) ;
F_9 ( V_69 , V_62 ) ;
F_9 ( V_70 , V_59 ) ;
F_9 ( V_71 , V_60 ) ;
F_9 ( V_68 , 1 ) ;
}
} else {
if ( V_28 -> V_63 == 0 ) {
F_9 ( V_66 , V_57 * 100 ) ;
F_9 ( V_67 , clock * 100 ) ;
F_9 ( V_68 , 0 ) ;
} else {
F_9 ( V_70 , V_57 * 100 ) ;
F_9 ( V_71 , clock * 100 ) ;
F_9 ( V_68 , 1 ) ;
}
}
}
static void F_23 ( struct V_18 * V_19 )
{
struct V_22 * V_23 = V_19 -> V_21 -> V_24 ;
struct V_72 * V_73 ;
struct V_74 * V_74 = NULL ;
T_5 V_75 ;
T_2 * V_76 ;
int V_77 ;
F_24 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_73 -> V_19 == V_19 ) {
V_74 = F_25 ( V_73 ) ;
break;
}
}
if ( ! V_74 ) {
F_26 ( L_4 ) ;
return;
}
V_77 = F_27 ( V_74 -> V_78 , & V_76 ) ;
if ( V_77 < 0 ) {
F_26 ( L_5 , V_77 ) ;
return;
}
V_75 = F_16 ( V_79 ) ;
V_75 &= ~ ( V_80 | V_81 ) ;
V_75 |= V_82 ;
if ( V_77 )
V_75 |= F_28 ( V_76 [ 0 ] ) ;
else
V_75 |= F_28 ( 5 ) ;
F_9 ( V_79 , V_75 ) ;
F_29 ( V_76 ) ;
}
static void F_30 ( struct V_18 * V_19 )
{
struct V_22 * V_23 = V_19 -> V_21 -> V_24 ;
struct V_72 * V_73 ;
struct V_74 * V_74 = NULL ;
struct V_83 * V_84 ;
int V_10 , V_77 ;
static const T_6 V_85 [] [ 2 ] = {
{ V_86 , V_87 } ,
{ V_88 , V_89 } ,
{ V_90 , V_91 } ,
{ V_92 , V_93 } ,
{ V_94 , V_95 } ,
{ V_96 , V_97 } ,
{ V_98 , V_99 } ,
{ V_100 , V_101 } ,
{ V_102 , V_103 } ,
{ V_104 , V_105 } ,
{ V_106 , V_107 } ,
{ V_108 , V_109 } ,
} ;
F_24 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_73 -> V_19 == V_19 ) {
V_74 = F_25 ( V_73 ) ;
break;
}
}
if ( ! V_74 ) {
F_26 ( L_4 ) ;
return;
}
V_77 = F_31 ( V_74 -> V_78 , & V_84 ) ;
if ( V_77 < 0 ) {
F_26 ( L_6 , V_77 ) ;
return;
}
F_32 ( ! V_84 ) ;
for ( V_10 = 0 ; V_10 < F_6 ( V_85 ) ; V_10 ++ ) {
T_5 V_54 = 0 ;
T_2 V_110 = 0 ;
int V_111 = - 1 ;
int V_112 ;
for ( V_112 = 0 ; V_112 < V_77 ; V_112 ++ ) {
struct V_83 * V_113 = & V_84 [ V_112 ] ;
if ( V_113 -> V_114 == V_85 [ V_10 ] [ 1 ] ) {
if ( V_113 -> V_115 > V_111 ) {
V_54 = F_33 ( V_113 -> V_115 ) |
F_34 ( V_113 -> V_116 ) |
F_35 ( V_113 -> V_3 ) ;
V_111 = V_113 -> V_115 ;
}
if ( V_113 -> V_114 == V_87 )
V_110 |= V_113 -> V_3 ;
else
break;
}
}
V_54 |= F_36 ( V_110 ) ;
F_9 ( V_85 [ V_10 ] [ 0 ] , V_54 ) ;
}
F_29 ( V_84 ) ;
}
void F_37 ( struct V_18 * V_19 , struct V_117 * V_118 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_26 * V_26 = F_8 ( V_19 ) ;
struct V_27 * V_28 = V_26 -> V_29 ;
T_2 V_38 [ V_119 + V_120 ] ;
struct V_121 V_40 ;
T_1 V_30 ;
T_7 V_122 ;
if ( ! V_28 || ! V_28 -> V_31 )
return;
if ( ! V_28 -> V_31 -> V_51 )
return;
V_30 = V_28 -> V_31 -> V_30 ;
V_28 -> V_31 -> V_123 = F_38 ( V_23 ) ;
F_39 ( V_23 , V_28 -> V_31 -> V_123 , false ) ;
F_20 ( V_19 , V_118 -> clock ) ;
F_9 ( V_124 + V_30 ,
V_125 ) ;
F_9 ( V_126 + V_30 , 0x1000 ) ;
if ( F_21 ( V_23 ) ) {
F_9 ( V_56 + V_30 ,
F_40 ( 1 ) |
F_41 ( 3 ) ) ;
F_9 ( V_127 + V_30 ,
V_128 |
V_129 ) ;
} else {
F_9 ( V_56 + V_30 ,
V_130 |
F_40 ( 1 ) |
F_41 ( 3 ) |
V_131 ) ;
}
if ( F_21 ( V_23 ) ) {
F_23 ( V_19 ) ;
F_30 ( V_19 ) ;
}
F_9 ( V_132 + V_30 ,
V_133 |
V_134 ) ;
F_9 ( V_124 + V_30 ,
V_125 |
V_135 |
V_136 ) ;
F_9 ( V_137 + V_30 ,
V_138 |
V_139 |
V_140 |
V_141 ) ;
F_9 ( V_142 + V_30 ,
F_42 ( 2 ) |
F_43 ( 2 ) ) ;
F_9 ( V_143 + V_30 , 0 ) ;
V_122 = F_44 ( & V_40 , V_118 ) ;
if ( V_122 < 0 ) {
F_26 ( L_7 , V_122 ) ;
return;
}
V_122 = F_45 ( & V_40 , V_38 , sizeof( V_38 ) ) ;
if ( V_122 < 0 ) {
F_26 ( L_8 , V_122 ) ;
return;
}
F_13 ( V_19 , V_38 , sizeof( V_38 ) ) ;
F_7 ( V_19 , V_118 -> clock ) ;
F_9 ( V_144 + V_30 , 0x00FFFFFF ) ;
F_9 ( V_145 + V_30 , 0x007FFFFF ) ;
F_9 ( V_146 + V_30 , 0x00000001 ) ;
F_9 ( V_147 + V_30 , 0x00000001 ) ;
F_18 ( V_19 ) ;
F_39 ( V_23 , V_28 -> V_31 -> V_123 , true ) ;
}
void F_46 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_26 * V_26 = F_8 ( V_19 ) ;
struct V_27 * V_28 = V_26 -> V_29 ;
struct V_148 V_149 = F_47 ( V_23 ) ;
T_4 V_38 [ V_119 + V_150 ] ;
struct V_151 V_40 ;
T_1 V_30 ;
T_1 V_152 ;
T_7 V_122 ;
if ( ! V_28 -> V_31 || ! V_28 -> V_31 -> V_51 )
return;
V_30 = V_28 -> V_31 -> V_30 ;
F_4 ( L_9 ,
F_15 ( V_19 ) ? L_10 : L_11 ,
V_149 . V_115 , V_149 . V_153 , V_149 . V_154 ) ;
F_4 ( L_12 ,
( int ) V_149 . V_155 , ( int ) V_149 . V_156 ) ;
V_152 = 0 ;
if ( V_149 . V_155 & V_157 )
V_152 |= 1 << 0 ;
if ( V_149 . V_155 & V_158 )
V_152 |= 1 << 1 ;
if ( V_149 . V_155 & V_159 )
V_152 |= 1 << 2 ;
if ( V_149 . V_155 & V_160 )
V_152 |= 1 << 3 ;
V_152 |= F_48 ( V_149 . V_156 ) ;
switch ( V_149 . V_153 ) {
case 32000 :
V_152 |= F_49 ( 0x3 ) ;
break;
case 44100 :
V_152 |= F_49 ( 0x0 ) ;
break;
case 48000 :
V_152 |= F_49 ( 0x2 ) ;
break;
case 88200 :
V_152 |= F_49 ( 0x8 ) ;
break;
case 96000 :
V_152 |= F_49 ( 0xa ) ;
break;
case 176400 :
V_152 |= F_49 ( 0xc ) ;
break;
case 192000 :
V_152 |= F_49 ( 0xe ) ;
break;
}
F_9 ( V_161 + V_30 , V_152 ) ;
V_152 = 0 ;
switch ( V_149 . V_154 ) {
case 16 :
V_152 |= F_50 ( 0x2 ) ;
break;
case 20 :
V_152 |= F_50 ( 0x3 ) ;
break;
case 24 :
V_152 |= F_50 ( 0xb ) ;
break;
}
if ( V_149 . V_155 & V_162 )
V_152 |= 0x5 << 16 ;
F_19 ( V_163 + V_30 , V_152 , ~ 0x5000f ) ;
V_122 = F_51 ( & V_40 ) ;
if ( V_122 < 0 ) {
F_26 ( L_13 ) ;
return;
}
V_40 . V_115 = V_149 . V_115 ;
V_122 = F_52 ( & V_40 , V_38 , sizeof( V_38 ) ) ;
if ( V_122 < 0 ) {
F_26 ( L_14 ) ;
return;
}
F_14 ( V_19 , V_38 , sizeof( V_38 ) ) ;
F_18 ( V_19 ) ;
}
void F_53 ( struct V_18 * V_19 , bool V_164 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_26 * V_26 = F_8 ( V_19 ) ;
struct V_27 * V_28 = V_26 -> V_29 ;
T_5 V_165 = V_166 ;
if ( ! V_28 || ! V_28 -> V_31 )
return;
if ( V_164 && V_28 -> V_31 -> V_51 )
return;
if ( ! V_164 && ! V_28 -> V_31 -> V_51 )
return;
if ( ! F_54 ( V_23 ) ) {
if ( V_164 )
V_165 |= V_167 ;
switch ( V_26 -> V_168 ) {
case V_169 :
if ( V_164 ) {
F_55 ( V_170 , V_171 ) ;
V_165 |= F_56 ( V_172 ) ;
} else {
F_57 ( V_170 , ~ V_171 ) ;
}
break;
case V_173 :
if ( V_164 ) {
F_55 ( V_174 , V_175 ) ;
V_165 |= F_56 ( V_176 ) ;
} else {
F_57 ( V_174 , ~ V_175 ) ;
}
break;
case V_177 :
if ( V_164 ) {
F_55 ( V_178 , V_179 ) ;
V_165 |= F_56 ( V_180 ) ;
} else {
F_57 ( V_178 , ~ V_179 ) ;
}
break;
case V_181 :
if ( V_164 )
V_165 |= F_56 ( V_182 ) ;
break;
default:
F_58 ( V_23 -> V_21 , L_15 ,
V_26 -> V_168 ) ;
break;
}
F_9 ( V_183 + V_28 -> V_31 -> V_30 , V_165 ) ;
}
if ( V_23 -> V_184 . V_185 ) {
if ( V_164 )
F_59 ( V_23 , V_28 -> V_31 -> V_186 ) ;
else
F_60 ( V_23 , V_28 -> V_31 -> V_186 ) ;
}
V_28 -> V_31 -> V_51 = V_164 ;
F_4 ( L_16 ,
V_164 ? L_17 : L_18 , V_28 -> V_31 -> V_30 , V_26 -> V_168 ) ;
}
