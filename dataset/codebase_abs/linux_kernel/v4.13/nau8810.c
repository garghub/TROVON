static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_5 :
case V_6 ... V_7 :
case V_8 ... V_9 :
case V_10 ... V_11 :
case V_12 ... V_13 :
case V_14 ... V_15 :
case V_16 ... V_17 :
case V_18 ... V_19 :
case V_20 :
case V_21 ... V_22 :
case V_23 :
case V_24 :
case V_25 ... V_26 :
case V_27 ... V_28 :
case V_29 ... V_30 :
case V_31 :
case V_32 ... V_33 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_5 :
case V_6 ... V_7 :
case V_8 ... V_9 :
case V_10 ... V_11 :
case V_12 ... V_13 :
case V_14 ... V_15 :
case V_16 ... V_17 :
case V_18 ... V_19 :
case V_20 :
case V_21 ... V_22 :
case V_23 :
case V_24 :
case V_25 ... V_26 :
case V_29 ... V_30 :
case V_31 :
case V_32 ... V_33 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_27 ... V_28 :
return true ;
default:
return false ;
}
}
static int F_4 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 = F_5 ( V_35 ) ;
struct V_40 * V_40 = F_6 ( V_39 ) ;
struct V_41 * V_42 = ( void * ) V_35 -> V_43 ;
int V_44 , V_3 , V_45 ;
T_1 * V_46 ;
V_46 = ( T_1 * ) V_37 -> V_47 . V_48 . V_49 ;
V_3 = V_10 ;
for ( V_44 = 0 ; V_44 < V_42 -> V_50 / sizeof( T_1 ) ; V_44 ++ ) {
F_7 ( V_40 -> V_51 , V_3 + V_44 , & V_45 ) ;
V_45 = F_8 ( V_45 ) ;
memcpy ( V_46 + V_44 , & V_45 , sizeof( V_45 ) ) ;
}
return 0 ;
}
static int F_9 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 = F_5 ( V_35 ) ;
struct V_40 * V_40 = F_6 ( V_39 ) ;
struct V_41 * V_42 = ( void * ) V_35 -> V_43 ;
void * V_49 ;
T_1 * V_46 , V_47 ;
int V_44 , V_3 , V_52 ;
V_49 = F_10 ( V_37 -> V_47 . V_48 . V_49 ,
V_42 -> V_50 , V_53 | V_54 ) ;
if ( ! V_49 )
return - V_55 ;
V_46 = ( T_1 * ) V_49 ;
V_3 = V_10 ;
for ( V_44 = 0 ; V_44 < V_42 -> V_50 / sizeof( T_1 ) ; V_44 ++ ) {
V_47 = F_11 ( * ( V_46 + V_44 ) ) ;
V_52 = F_12 ( V_40 -> V_51 , V_3 + V_44 , V_47 ) ;
if ( V_52 ) {
F_13 ( V_39 -> V_2 , L_1 ,
V_3 + V_44 , V_52 ) ;
F_14 ( V_49 ) ;
return V_52 ;
}
}
F_14 ( V_49 ) ;
return 0 ;
}
static int F_15 ( struct V_56 * V_57 ,
struct V_56 * V_58 )
{
struct V_38 * V_39 = F_16 ( V_57 -> V_59 ) ;
struct V_40 * V_40 = F_6 ( V_39 ) ;
unsigned int V_47 ;
F_7 ( V_40 -> V_51 , V_60 , & V_47 ) ;
return ( V_47 & V_61 ) ;
}
static int F_17 ( struct V_62 * V_63 ,
int V_64 , unsigned int V_65 , int V_66 )
{
struct V_38 * V_39 = V_63 -> V_39 ;
struct V_40 * V_40 = F_6 ( V_39 ) ;
V_40 -> V_64 = V_64 ;
V_40 -> V_67 = V_65 ;
F_18 ( V_40 -> V_2 , L_2 ,
V_65 , V_64 == V_68 ? L_3 : L_4 ) ;
return 0 ;
}
static int F_19 ( unsigned int V_69 ,
unsigned int V_70 , struct V_71 * V_72 )
{
T_2 V_73 , V_74 , V_75 ;
int V_44 , V_76 ;
if ( V_69 > V_77 || V_69 < V_78 )
return - V_79 ;
V_74 = 0 ;
V_76 = F_20 ( V_80 ) ;
for ( V_44 = 0 ; V_44 < F_20 ( V_80 ) ; V_44 ++ ) {
V_73 = 256 * V_70 * 4 * V_80 [ V_44 ] / 10 ;
if ( V_73 > V_81 && V_73 < V_82 &&
V_74 < V_73 ) {
V_74 = V_73 ;
V_76 = V_44 ;
}
}
if ( F_20 ( V_80 ) == V_76 )
return - V_79 ;
V_72 -> V_83 = V_76 ;
V_73 = V_74 ;
V_75 = F_21 ( V_73 << 28 , V_69 ) ;
V_72 -> V_84 = 0 ;
if ( ( ( V_75 >> 28 ) & 0xF ) < V_85 ) {
V_75 <<= 1 ;
V_72 -> V_84 = 1 ;
}
V_72 -> V_86 = ( V_75 >> 28 ) & 0xF ;
V_72 -> V_87 = ( ( V_75 & 0xFFFFFFF ) >> 4 ) ;
return 0 ;
}
static int F_22 ( struct V_62 * V_88 , int V_89 ,
int V_57 , unsigned int V_90 , unsigned int V_91 )
{
struct V_38 * V_39 = V_88 -> V_39 ;
struct V_40 * V_40 = F_6 ( V_39 ) ;
struct V_51 * V_92 = V_40 -> V_51 ;
struct V_71 * V_72 = & V_40 -> V_93 ;
int V_52 , V_70 ;
V_70 = V_91 / 256 ;
V_52 = F_19 ( V_90 , V_70 , V_72 ) ;
if ( V_52 < 0 ) {
F_13 ( V_40 -> V_2 , L_5 , V_90 ) ;
return V_52 ;
}
F_23 ( V_40 -> V_2 , L_6 ,
V_72 -> V_86 , V_72 -> V_87 , V_72 -> V_83 ,
V_72 -> V_84 ) ;
F_24 ( V_92 , V_94 ,
V_95 | V_96 ,
( V_72 -> V_84 ? V_95 : 0 ) |
V_72 -> V_86 ) ;
F_12 ( V_92 , V_97 ,
( V_72 -> V_87 >> V_98 ) &
V_99 ) ;
F_12 ( V_92 , V_100 ,
( V_72 -> V_87 >> V_101 ) &
V_102 ) ;
F_12 ( V_92 , V_103 ,
V_72 -> V_87 & V_104 ) ;
F_24 ( V_92 , V_60 , V_105 ,
V_72 -> V_83 << V_106 ) ;
F_24 ( V_92 , V_60 ,
V_61 , V_107 ) ;
return 0 ;
}
static int F_25 ( struct V_62 * V_88 ,
unsigned int V_108 )
{
struct V_38 * V_39 = V_88 -> V_39 ;
struct V_40 * V_40 = F_6 ( V_39 ) ;
T_1 V_109 = 0 , V_110 = 0 ;
switch ( V_108 & V_111 ) {
case V_112 :
V_110 |= V_113 ;
break;
case V_114 :
break;
default:
return - V_79 ;
}
switch ( V_108 & V_115 ) {
case V_116 :
V_109 |= V_117 ;
break;
case V_118 :
break;
case V_119 :
V_109 |= V_120 ;
break;
case V_121 :
V_109 |= V_122 ;
break;
default:
return - V_79 ;
}
switch ( V_108 & V_123 ) {
case V_124 :
break;
case V_125 :
V_109 |= V_126 | V_127 ;
break;
case V_128 :
V_109 |= V_126 ;
break;
case V_129 :
V_109 |= V_127 ;
break;
default:
return - V_79 ;
}
F_24 ( V_40 -> V_51 , V_130 ,
V_131 | V_127 |
V_126 , V_109 ) ;
F_24 ( V_40 -> V_51 , V_60 ,
V_132 , V_110 ) ;
return 0 ;
}
static int F_26 ( struct V_40 * V_40 , int V_133 )
{
int V_44 , V_134 , V_135 = V_133 * 256 , div = 0 ;
if ( ! V_40 -> V_67 ) {
F_13 ( V_40 -> V_2 , L_7 ) ;
return - V_79 ;
}
for ( V_44 = 1 ; V_44 < F_20 ( V_80 ) ; V_44 ++ ) {
V_134 = ( V_40 -> V_67 * 10 ) /
V_80 [ V_44 ] ;
if ( V_134 < V_135 )
break;
div = V_44 ;
}
F_18 ( V_40 -> V_2 ,
L_8 , div , V_133 ) ;
F_24 ( V_40 -> V_51 , V_60 ,
V_105 , ( div << V_106 ) ) ;
F_24 ( V_40 -> V_51 , V_60 ,
V_61 , V_136 ) ;
return 0 ;
}
static int F_27 ( struct V_137 * V_138 ,
struct V_139 * V_42 , struct V_62 * V_63 )
{
struct V_38 * V_39 = V_63 -> V_39 ;
struct V_40 * V_40 = F_6 ( V_39 ) ;
int V_140 = 0 , V_141 = 0 , V_52 = 0 ;
switch ( F_28 ( V_42 ) ) {
case 16 :
break;
case 20 :
V_140 |= V_142 ;
break;
case 24 :
V_140 |= V_143 ;
break;
case 32 :
V_140 |= V_144 ;
break;
}
switch ( F_29 ( V_42 ) ) {
case 8000 :
V_141 |= V_145 ;
break;
case 11025 :
V_141 |= V_146 ;
break;
case 16000 :
V_141 |= V_147 ;
break;
case 22050 :
V_141 |= V_148 ;
break;
case 32000 :
V_141 |= V_149 ;
break;
case 44100 :
case 48000 :
break;
}
F_24 ( V_40 -> V_51 , V_130 ,
V_150 , V_140 ) ;
F_24 ( V_40 -> V_51 , V_5 ,
V_151 , V_141 ) ;
if ( V_40 -> V_64 == V_152 ) {
V_52 = F_26 ( V_40 , F_29 ( V_42 ) ) ;
if ( V_52 < 0 )
F_13 ( V_40 -> V_2 , L_9 ) ;
}
return V_52 ;
}
static int F_30 ( struct V_38 * V_39 ,
enum V_153 V_154 )
{
struct V_40 * V_40 = F_6 ( V_39 ) ;
struct V_51 * V_92 = V_40 -> V_51 ;
switch ( V_154 ) {
case V_155 :
case V_156 :
F_24 ( V_92 , V_157 ,
V_158 , V_159 ) ;
break;
case V_160 :
F_24 ( V_92 , V_157 ,
V_161 | V_162 ,
V_161 | V_162 ) ;
if ( F_31 ( V_39 ) == V_163 ) {
F_32 ( V_92 ) ;
F_24 ( V_92 , V_157 ,
V_158 , V_164 ) ;
F_33 ( 100 ) ;
}
F_24 ( V_92 , V_157 ,
V_158 , V_165 ) ;
break;
case V_163 :
F_12 ( V_92 , V_157 , 0 ) ;
F_12 ( V_92 , V_166 , 0 ) ;
F_12 ( V_92 , V_167 , 0 ) ;
break;
}
return 0 ;
}
static int F_34 ( struct V_168 * V_169 ,
const struct V_170 * V_171 )
{
struct V_1 * V_2 = & V_169 -> V_2 ;
struct V_40 * V_40 = F_35 ( V_2 ) ;
if ( ! V_40 ) {
V_40 = F_36 ( V_2 , sizeof( * V_40 ) , V_53 ) ;
if ( ! V_40 )
return - V_55 ;
}
F_37 ( V_169 , V_40 ) ;
V_40 -> V_51 = F_38 ( V_169 , & V_172 ) ;
if ( F_39 ( V_40 -> V_51 ) )
return F_40 ( V_40 -> V_51 ) ;
V_40 -> V_2 = V_2 ;
F_12 ( V_40 -> V_51 , V_4 , 0x00 ) ;
return F_41 ( V_2 ,
& V_173 , & V_174 , 1 ) ;
}
static int F_42 ( struct V_168 * V_175 )
{
F_43 ( & V_175 -> V_2 ) ;
return 0 ;
}
