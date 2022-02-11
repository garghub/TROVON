static void F_1 ( T_1 clock , int * V_1 , int V_2 , int V_3 )
{
T_2 V_4 ;
T_3 V_5 ;
if ( * V_1 == 0 ) {
V_4 = ( T_2 ) clock * ( T_2 ) V_2 * 1000ULL ;
V_5 = 128 * V_3 ;
F_2 ( V_4 , V_5 ) ;
* V_1 = V_4 ;
}
F_3 ( L_1 ,
V_2 , * V_1 , V_3 ) ;
}
struct V_6 F_4 ( T_1 clock )
{
struct V_6 V_7 ;
T_4 V_8 ;
for ( V_8 = 0 ; V_9 [ V_8 ] . clock != clock &&
V_9 [ V_8 ] . clock != 0 ; V_8 ++ )
;
V_7 = V_9 [ V_8 ] ;
F_1 ( clock , & V_7 . V_10 , V_7 . V_11 , 32000 ) ;
F_1 ( clock , & V_7 . V_12 , V_7 . V_13 , 44100 ) ;
F_1 ( clock , & V_7 . V_14 , V_7 . V_15 , 48000 ) ;
return V_7 ;
}
static void F_5 ( struct V_16 * V_17 , T_1 clock )
{
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_21 = V_19 -> V_22 ;
struct V_6 V_23 = F_4 ( clock ) ;
struct V_24 * V_24 = F_6 ( V_17 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
T_1 V_28 = V_26 -> V_29 -> V_28 ;
F_7 ( V_30 + V_28 , F_8 ( V_23 . V_10 ) ) ;
F_7 ( V_31 + V_28 , V_23 . V_11 ) ;
F_7 ( V_32 + V_28 , F_9 ( V_23 . V_12 ) ) ;
F_7 ( V_33 + V_28 , V_23 . V_13 ) ;
F_7 ( V_34 + V_28 , F_10 ( V_23 . V_14 ) ) ;
F_7 ( V_35 + V_28 , V_23 . V_15 ) ;
}
static void F_11 ( struct V_16 * V_17 ,
void * V_36 , T_5 V_37 )
{
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_21 = V_19 -> V_22 ;
struct V_24 * V_24 = F_6 ( V_17 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
T_1 V_28 = V_26 -> V_29 -> V_28 ;
T_6 * V_38 = V_36 + 3 ;
T_6 * V_39 = V_36 ;
F_7 ( V_40 + V_28 ,
V_38 [ 0x0 ] | ( V_38 [ 0x1 ] << 8 ) | ( V_38 [ 0x2 ] << 16 ) | ( V_38 [ 0x3 ] << 24 ) ) ;
F_7 ( V_41 + V_28 ,
V_38 [ 0x4 ] | ( V_38 [ 0x5 ] << 8 ) | ( V_38 [ 0x6 ] << 16 ) | ( V_38 [ 0x7 ] << 24 ) ) ;
F_7 ( V_42 + V_28 ,
V_38 [ 0x8 ] | ( V_38 [ 0x9 ] << 8 ) | ( V_38 [ 0xA ] << 16 ) | ( V_38 [ 0xB ] << 24 ) ) ;
F_7 ( V_43 + V_28 ,
V_38 [ 0xC ] | ( V_38 [ 0xD ] << 8 ) | ( V_39 [ 1 ] << 24 ) ) ;
}
static void F_12 ( struct V_16 * V_17 ,
const void * V_36 , T_5 V_37 )
{
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_21 = V_19 -> V_22 ;
struct V_24 * V_24 = F_6 ( V_17 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
T_1 V_28 = V_26 -> V_29 -> V_28 ;
const T_4 * V_38 = V_36 + 3 ;
F_7 ( V_44 + V_28 ,
V_38 [ 0x0 ] | ( V_38 [ 0x1 ] << 8 ) | ( V_38 [ 0x2 ] << 16 ) | ( V_38 [ 0x3 ] << 24 ) ) ;
F_7 ( V_45 + V_28 ,
V_38 [ 0x4 ] | ( V_38 [ 0x5 ] << 8 ) | ( V_38 [ 0x6 ] << 16 ) | ( V_38 [ 0x8 ] << 24 ) ) ;
}
static bool F_13 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_21 = V_19 -> V_22 ;
struct V_24 * V_24 = F_6 ( V_17 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
T_1 V_28 = V_26 -> V_29 -> V_28 ;
return ( F_14 ( V_46 + V_28 ) & 0x10 ) != 0 ;
}
int F_15 ( struct V_16 * V_17 )
{
struct V_24 * V_24 = F_6 ( V_17 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
int V_47 , V_48 ;
if ( ! V_26 -> V_29 || ! V_26 -> V_29 -> V_49 )
return 0 ;
V_47 = F_13 ( V_17 ) ;
V_48 = V_26 -> V_29 -> V_50 != V_47 ;
V_26 -> V_29 -> V_50 = V_47 ;
return V_48 ;
}
static void F_16 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_21 = V_19 -> V_22 ;
struct V_24 * V_24 = F_6 ( V_17 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
T_1 V_28 = V_26 -> V_29 -> V_28 ;
bool V_51 = false ;
T_3 V_52 ;
if ( ! V_51 ||
F_13 ( V_17 ) )
V_52 = 0 ;
else
V_52 = V_53 ;
F_17 ( V_54 + V_28 ,
V_52 , ~ V_53 ) ;
}
void F_18 ( struct V_16 * V_17 , T_3 clock )
{
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_21 = V_19 -> V_22 ;
struct V_24 * V_24 = F_6 ( V_17 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
T_3 V_55 = 24000 ;
T_3 V_56 = clock / V_55 ;
T_3 V_57 ;
T_3 V_58 = clock ;
T_3 V_59 ;
T_3 V_60 ;
if ( ! V_26 || ! V_26 -> V_29 )
return;
if ( V_56 >= 8 ) {
V_57 = 192 * 1000 ;
V_59 = 3 ;
} else if ( V_56 >= 4 ) {
V_57 = 96 * 1000 ;
V_59 = 2 ;
} else if ( V_56 >= 2 ) {
V_57 = 48 * 1000 ;
V_59 = 1 ;
} else {
V_57 = 24 * 1000 ;
V_59 = 0 ;
}
if ( F_19 ( V_21 ) ) {
if ( V_26 -> V_61 == 0 ) {
V_60 = F_14 ( V_62 ) & ~ V_63 ;
V_60 |= F_20 ( V_59 ) ;
F_7 ( V_62 , V_60 ) ;
F_7 ( V_64 , V_57 ) ;
F_7 ( V_65 , V_58 ) ;
F_7 ( V_66 , 0 ) ;
} else {
V_60 = F_14 ( V_67 ) & ~ V_63 ;
V_60 |= F_20 ( V_59 ) ;
F_7 ( V_67 , V_60 ) ;
F_7 ( V_68 , V_57 ) ;
F_7 ( V_69 , V_58 ) ;
F_7 ( V_66 , 1 ) ;
}
} else if ( F_21 ( V_21 ) ) {
if ( V_26 -> V_61 == 0 ) {
F_7 ( V_64 , V_55 * 100 ) ;
F_7 ( V_65 , clock * 100 ) ;
F_7 ( V_66 , 0 ) ;
} else {
F_7 ( V_68 , V_55 * 100 ) ;
F_7 ( V_69 , clock * 100 ) ;
F_7 ( V_66 , 1 ) ;
}
} else {
F_7 ( V_70 , F_22 ( V_55 / 10 ) |
F_23 ( clock / 10 ) ) ;
}
}
static void F_24 ( struct V_16 * V_17 )
{
struct V_20 * V_21 = V_17 -> V_19 -> V_22 ;
struct V_71 * V_72 ;
struct V_73 * V_73 = NULL ;
T_3 V_74 ;
T_4 * V_75 ;
int V_76 ;
return;
F_25 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_72 -> V_17 == V_17 )
V_73 = F_26 ( V_72 ) ;
}
if ( ! V_73 ) {
F_27 ( L_2 ) ;
return;
}
V_76 = F_28 ( V_73 -> V_77 , & V_75 ) ;
if ( V_76 < 0 ) {
F_27 ( L_3 , V_76 ) ;
return;
}
V_74 = F_14 ( V_78 ) ;
V_74 &= ~ ( V_79 | V_80 ) ;
V_74 |= V_81 ;
if ( V_76 )
V_74 |= F_29 ( V_75 [ 0 ] ) ;
else
V_74 |= F_29 ( 5 ) ;
F_7 ( V_78 , V_74 ) ;
F_30 ( V_75 ) ;
}
static void F_31 ( struct V_16 * V_17 )
{
struct V_20 * V_21 = V_17 -> V_19 -> V_22 ;
struct V_71 * V_72 ;
struct V_73 * V_73 = NULL ;
struct V_82 * V_83 ;
int V_8 , V_76 ;
static const T_7 V_84 [] [ 2 ] = {
{ V_85 , V_86 } ,
{ V_87 , V_88 } ,
{ V_89 , V_90 } ,
{ V_91 , V_92 } ,
{ V_93 , V_94 } ,
{ V_95 , V_96 } ,
{ V_97 , V_98 } ,
{ V_99 , V_100 } ,
{ V_101 , V_102 } ,
{ V_103 , V_104 } ,
{ V_105 , V_106 } ,
{ V_107 , V_108 } ,
} ;
F_25 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_72 -> V_17 == V_17 )
V_73 = F_26 ( V_72 ) ;
}
if ( ! V_73 ) {
F_27 ( L_2 ) ;
return;
}
V_76 = F_32 ( V_73 -> V_77 , & V_83 ) ;
if ( V_76 < 0 ) {
F_27 ( L_4 , V_76 ) ;
return;
}
F_33 ( ! V_83 ) ;
for ( V_8 = 0 ; V_8 < F_34 ( V_84 ) ; V_8 ++ ) {
T_3 V_52 = 0 ;
int V_109 ;
for ( V_109 = 0 ; V_109 < V_76 ; V_109 ++ ) {
struct V_82 * V_110 = & V_83 [ V_109 ] ;
if ( V_110 -> V_111 == V_84 [ V_8 ] [ 1 ] ) {
V_52 = F_35 ( V_110 -> V_112 ) |
F_36 ( V_110 -> V_113 ) |
F_37 ( V_110 -> V_3 ) ;
if ( V_110 -> V_111 == V_86 )
V_52 |= F_38 ( V_110 -> V_3 ) ;
break;
}
}
F_7 ( V_84 [ V_8 ] [ 0 ] , V_52 ) ;
}
F_30 ( V_83 ) ;
}
void F_39 ( struct V_16 * V_17 , struct V_114 * V_115 )
{
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_21 = V_19 -> V_22 ;
struct V_24 * V_24 = F_6 ( V_17 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
T_4 V_36 [ V_116 + V_117 ] ;
struct V_118 V_38 ;
T_1 V_28 ;
T_8 V_119 ;
if ( ! V_26 || ! V_26 -> V_29 )
return;
if ( ! V_26 -> V_29 -> V_49 )
return;
V_28 = V_26 -> V_29 -> V_28 ;
F_18 ( V_17 , V_115 -> clock ) ;
F_7 ( V_120 + V_28 ,
V_121 ) ;
F_7 ( V_122 + V_28 , 0x1000 ) ;
if ( F_19 ( V_21 ) ) {
F_7 ( V_54 + V_28 ,
F_40 ( 1 ) |
F_41 ( 3 ) ) ;
F_7 ( V_123 + V_28 ,
V_124 |
V_125 ) ;
} else {
F_7 ( V_54 + V_28 ,
V_126 |
F_40 ( 1 ) |
F_41 ( 3 ) |
V_127 ) ;
}
if ( F_19 ( V_21 ) ) {
F_24 ( V_17 ) ;
F_31 ( V_17 ) ;
}
F_7 ( V_128 + V_28 ,
V_129 |
V_130 ) ;
F_7 ( V_120 + V_28 ,
V_121 |
V_131 |
V_132 ) ;
F_7 ( V_133 + V_28 ,
V_134 |
V_135 |
V_136 |
V_137 ) ;
F_7 ( V_138 + V_28 ,
F_42 ( 2 ) |
F_43 ( 2 ) ) ;
F_7 ( V_139 + V_28 , 0 ) ;
V_119 = F_44 ( & V_38 , V_115 ) ;
if ( V_119 < 0 ) {
F_27 ( L_5 , V_119 ) ;
return;
}
V_119 = F_45 ( & V_38 , V_36 , sizeof( V_36 ) ) ;
if ( V_119 < 0 ) {
F_27 ( L_6 , V_119 ) ;
return;
}
F_11 ( V_17 , V_36 , sizeof( V_36 ) ) ;
F_5 ( V_17 , V_115 -> clock ) ;
F_7 ( V_140 + V_28 , 0x00FFFFFF ) ;
F_7 ( V_141 + V_28 , 0x007FFFFF ) ;
F_7 ( V_142 + V_28 , 0x00000001 ) ;
F_7 ( V_143 + V_28 , 0x00000001 ) ;
F_16 ( V_17 ) ;
}
void F_46 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_21 = V_19 -> V_22 ;
struct V_24 * V_24 = F_6 ( V_17 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_144 V_145 = F_47 ( V_21 ) ;
T_6 V_36 [ V_116 + V_146 ] ;
struct V_147 V_38 ;
T_1 V_28 ;
T_1 V_148 ;
T_8 V_119 ;
if ( ! V_26 -> V_29 || ! V_26 -> V_29 -> V_49 )
return;
V_28 = V_26 -> V_29 -> V_28 ;
F_3 ( L_7 ,
F_13 ( V_17 ) ? L_8 : L_9 ,
V_145 . V_112 , V_145 . V_149 , V_145 . V_150 ) ;
F_3 ( L_10 ,
( int ) V_145 . V_151 , ( int ) V_145 . V_152 ) ;
V_148 = 0 ;
if ( V_145 . V_151 & V_153 )
V_148 |= 1 << 0 ;
if ( V_145 . V_151 & V_154 )
V_148 |= 1 << 1 ;
if ( V_145 . V_151 & V_155 )
V_148 |= 1 << 2 ;
if ( V_145 . V_151 & V_156 )
V_148 |= 1 << 3 ;
V_148 |= F_48 ( V_145 . V_152 ) ;
switch ( V_145 . V_149 ) {
case 32000 :
V_148 |= F_49 ( 0x3 ) ;
break;
case 44100 :
V_148 |= F_49 ( 0x0 ) ;
break;
case 48000 :
V_148 |= F_49 ( 0x2 ) ;
break;
case 88200 :
V_148 |= F_49 ( 0x8 ) ;
break;
case 96000 :
V_148 |= F_49 ( 0xa ) ;
break;
case 176400 :
V_148 |= F_49 ( 0xc ) ;
break;
case 192000 :
V_148 |= F_49 ( 0xe ) ;
break;
}
F_7 ( V_157 + V_28 , V_148 ) ;
V_148 = 0 ;
switch ( V_145 . V_150 ) {
case 16 :
V_148 |= F_50 ( 0x2 ) ;
break;
case 20 :
V_148 |= F_50 ( 0x3 ) ;
break;
case 24 :
V_148 |= F_50 ( 0xb ) ;
break;
}
if ( V_145 . V_151 & V_158 )
V_148 |= 0x5 << 16 ;
F_17 ( V_159 + V_28 , V_148 , ~ 0x5000f ) ;
V_119 = F_51 ( & V_38 ) ;
if ( V_119 < 0 ) {
F_27 ( L_11 ) ;
return;
}
V_38 . V_112 = V_145 . V_112 ;
V_119 = F_52 ( & V_38 , V_36 , sizeof( V_36 ) ) ;
if ( V_119 < 0 ) {
F_27 ( L_12 ) ;
return;
}
F_12 ( V_17 , V_36 , sizeof( V_36 ) ) ;
F_16 ( V_17 ) ;
}
void F_53 ( struct V_16 * V_17 , bool V_160 )
{
struct V_18 * V_19 = V_17 -> V_19 ;
struct V_20 * V_21 = V_19 -> V_22 ;
struct V_24 * V_24 = F_6 ( V_17 ) ;
struct V_25 * V_26 = V_24 -> V_27 ;
T_3 V_161 = V_162 ;
if ( ! V_26 || ! V_26 -> V_29 )
return;
if ( V_160 && V_26 -> V_29 -> V_49 )
return;
if ( ! V_160 && ! V_26 -> V_29 -> V_49 )
return;
if ( V_160 )
V_26 -> V_29 -> V_163 = F_54 ( V_21 ) ;
else
V_26 -> V_29 -> V_163 = NULL ;
if ( ! F_21 ( V_21 ) ) {
if ( V_160 )
V_161 |= V_164 ;
switch ( V_24 -> V_165 ) {
case V_166 :
if ( V_160 ) {
F_55 ( V_167 , V_168 ) ;
V_161 |= F_56 ( V_169 ) ;
} else {
F_57 ( V_167 , ~ V_168 ) ;
}
break;
case V_170 :
if ( V_160 ) {
F_55 ( V_171 , V_172 ) ;
V_161 |= F_56 ( V_173 ) ;
} else {
F_57 ( V_171 , ~ V_172 ) ;
}
break;
case V_174 :
if ( V_160 ) {
F_55 ( V_175 , V_176 ) ;
V_161 |= F_56 ( V_177 ) ;
} else {
F_57 ( V_175 , ~ V_176 ) ;
}
break;
case V_178 :
if ( V_160 )
V_161 |= F_56 ( V_179 ) ;
break;
default:
F_58 ( V_21 -> V_19 , L_13 ,
V_24 -> V_165 ) ;
break;
}
F_7 ( V_180 + V_26 -> V_29 -> V_28 , V_161 ) ;
}
if ( V_21 -> V_181 . V_182 ) {
if ( V_160 )
F_59 ( V_21 , V_26 -> V_29 -> V_183 ) ;
else
F_60 ( V_21 , V_26 -> V_29 -> V_183 ) ;
}
V_26 -> V_29 -> V_49 = V_160 ;
F_3 ( L_14 ,
V_160 ? L_15 : L_16 , V_26 -> V_29 -> V_28 , V_24 -> V_165 ) ;
}
